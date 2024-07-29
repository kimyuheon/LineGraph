#ifndef _LOT_GDC_H_
#define _LOT_GDC_H_


#include <gdiplus.h>
using namespace Gdiplus;

#define RGB24(r, g, b) (0XFF000000 | (r << 16) | (g << 8) | b) // 0xFFRRGGBB
#define RGB32(a, r, g, b) ((a << 24) | (r << 16) | (g << 8) | b) // 0xAARRGGBB

class LOT_GDC
{
protected:
	Brush* mp_brush;
	Brush* mp_font_brush;	// ���� �귯�� ����
	Pen* mp_pen;
	Gdiplus::Font* mp_font;
	Bitmap* mp_bitmap;
	Graphics* mp_graphic;

	int m_cx, m_cy;
	int m_last_pos_x, m_last_pos_y;
	Color m_temp_color;

	static ULONG_PTR m_token;
	static int m_object_count;
public:
	LOT_GDC();
	LOT_GDC(int a_cx, int a_cy);
	virtual ~LOT_GDC();

	void Init();
	void CreateGDC(int a_cx, int a_cy);

	// �簢���� �׸��� �Լ���
	void Rectangle(int a_sx, int a_sy, int a_ex, int a_ey);  // ä���� �׵θ� ���� �׸�
	void FillSolidRect(int a_sx, int a_sy, int a_ex, int a_ey, ARGB a_color);  // ä��⸸ ��
	void FillSolidRect(int a_sx, int a_sy, int a_ex, int a_ey);  // ä��⸸ ��
	void DrawRect(int a_sx, int a_sy, int a_ex, int a_ey, ARGB a_color);  // �׵θ��� �׸�
	void DrawRect(int a_sx, int a_sy, int a_ex, int a_ey); // �׵θ��� �׸�

	// Ÿ���� �׸��� �Լ���
	void Ellipse(int a_sx, int a_sy, int a_ex, int a_ey);  // ä���� �׵θ� ���� �׸�
	void FillSolidEllipse(int a_sx, int a_sy, int a_ex, int a_ey, ARGB a_color); // ä��⸸ ��
	void FillSolidEllipse(int a_sx, int a_sy, int a_ex, int a_ey); // ä��⸸ ��
	void DrawEllipse(int a_sx, int a_sy, int a_ex, int a_ey, ARGB a_color); // �׵θ��� �׸�
	void DrawEllipse(int a_sx, int a_sy, int a_ex, int a_ey); // �׵θ��� �׸�

	// ���� �׸��� �Լ���
	void DrawLine(int a_sx, int a_sy, int a_ex, int a_ey, ARGB a_color);  // ����, ���� ����ؼ� ���׸���
	void DrawLine(int a_sx, int a_sy, int a_ex, int a_ey);  // ����, ���� ����ؼ� ���׸���
	void MoveTo(int a_x, int a_y);  // ���� ���� ��ġ�� ����
	void LineTo(int a_x, int a_y);  // MoveTo �Ǵ� ������ LineTo�� ����� ������ ���� ����

	void SetDCBrushColor(ARGB a_color);  // ä��� ������ ����
	void SetDCPenColor(ARGB a_color);  // �� ������ ����
	void SetDCPenColor(DashStyle a_style, REAL a_width, ARGB a_color);  // �� ��Ÿ��, ���� �׸��� �� ���� ����
	void SetTextColor(ARGB a_color);  // �۲��� ������ ����
	Gdiplus::Font* SelectObject(Gdiplus::Font* ap_font);  // ��Ʈ ��ü�� �ٽ� �����Ѵ�.

	void Draw(Image* ap_image, int a_x, int a_y);  // ���޵� �̹��� ��ü�� ���
	void Draw(HDC ah_dc, int a_x = 0, int a_y = 0);  // ���޵� DC�� ���� �̹����� ���

	// ���ڿ��� ������ ��ġ�� ����ϴ� �Լ���
	void TextOut(int a_x, int a_y, ARGB a_color, const wchar_t* ap_str, int a_str_len);
	void TextOut(int a_x, int a_y, const wchar_t* ap_str, int a_str_len);

	// ���� ��ȣ ����� ���� �ܺο��� ����� �� �ְ� ���ִ� �Լ���
	Image* GetImage() { return mp_bitmap; }
	Graphics* GetGraphics() { return mp_graphic; }

	// GetImage �Լ��� GetGraphics �Լ��� ���ϰ� ����ϵ��� ������ �����ε� ���
	operator Image* () { return mp_bitmap; }
	operator Graphics* () { return mp_graphic; }
};

#endif
