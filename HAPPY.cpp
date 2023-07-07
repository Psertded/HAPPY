
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <windows.h>
#include <dshow.h>
#include <mmsystem.h>
#include <sstream>


using namespace std;

void setr()
{
    srand(time(NULL) + clock() + rand());
}

int main()
{
    HWND win = GetForegroundWindow();
    HWND hwnd = win;
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style = style & ~WS_CAPTION & ~WS_SIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    int screenX = GetSystemMetrics(SM_CXSCREEN);
    int screenY = GetSystemMetrics(SM_CYSCREEN);
    SetWindowPos(hwnd, NULL, 0, 0, screenX, screenY, SWP_NOZORDER);
    SetWindowLong(win, GWL_STYLE, style);
    RECT rect;
    string text[17] =
    {
        "       2Dr                                 uu                                                                                                         ",
        "      .BB                                  BBD                                                                                                        ",
        "      BBR.:iii:::iiririri7:                 BB7               ::           .:.           :.           .:...:..         :...:..       :::           :r ",
        "     5BBBBBBBQBBBBBBBBBBBBB   BBBBBBBQBBBBBBBBBBBBBBBBBBBBQ   BBu          BBB          BBBB          QBBBBBBBBBP      QBBBBBBBBBL   :BBM         BBB ",
        "    5BB       sBB             .:...  QZi .  7br         ..    BBr          BBM         rBBBBi         bBB     iBBB:    BBY    .YBBQ   .BBJ       BBB  ",
        "   QBQ        sBB                   rQB     BB : BQr          BBE          DEA        :QB.BBd         PBQ       gBB    BBr       BBb   iBQ      RBB   ",
        "  BBB         jBB                  iBB     BBBBBBBBBQBBB      BBi          QQZ        QBg  BBQ        qBQ       :BB    BBv       MBB    JBB    KBB    ",
        "   i          JBB                 rBB     BQq.::i7L7iQBQ      BB:          DBE       :BB    BBi       PQB       RBB    BBr       BB2     bBB  7BB     ",
        "              vBB                jBB7    BBP  ZZ     BQi      BBBBBBBBBBBBBBBZ       BB7    JBQ       KBR     :BBB     BBr     vBBB       BBg.BB      ",
        "iBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BQBB7  :BBBB  7BBg  BBZ       BBP7jjUjUuuLrBBd      DQg      BBZ      PBBBBBBBBQ5      BBBBQBBBQBr         BBBB.      ",
        " Y77r7r7r7r7i:PBB:i7r7r7r7rv7 rBBSdB7 QBB.:BB   S: QBB        BB.          gBD     .BBQBBBBBQBBB:     KBBr7Lr:         BQdrv7r.             BBv       ",
        "              7BB             BBi PBv rQ   rBB:   BBB         BBr          QBE     BBRqgQRQRMSBBB     PBR              BBi                  BBi       ",
        "              jBB              .  MBv       .BBqiBB5          BBr          BBD    PBB          BBZ    qBB              BBv                  BBi       ",
        "              UBB                 QBY         BBBBJ           BQ7          BBg   :BBi          iBBi   DBB              BBJ                  BBv       ",
        "              uBB                 QBL      .KBBBDBBBu.        BBv          BBQ   BBB            BBB   DBB              BBU                  BBL       ",
        "              2BB                 QBL   :bBBBQ:   uBBBBQUr.                                                                                           ",
        "              SBB                 BBJ :BBBP:         :PBBB:                                                                                           ",
    };
    int x, b, c = 180, d = 37;
    string cmd;
    POINT m;
    system("mode 180,37");
    GetWindowRect(win, &rect);
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        cout << "Failed to load sound";
        system("pause");
    }
    IGraphBuilder* pGBuilder;
    IMediaControl* pMControl;
    IMediaPosition* pMPos;
    IMediaEvent* pEvent;
    CoInitialize(NULL);
    CoCreateInstance(CLSID_FilterGraph, NULL,
        CLSCTX_INPROC, IID_IGraphBuilder, (void**)&pGBuilder);
    pGBuilder->QueryInterface(IID_IMediaControl, (void**)&pMControl);
    pGBuilder->QueryInterface(IID_IMediaPosition, (void**)&pMPos);
    pGBuilder->RenderFile(L"backgroundmusic.mp3", NULL);
    pMPos->put_CurrentPosition(0);
    pMControl->Run();
    ios::sync_with_stdio(false);
    for (int i = 0; true; i=rand()%256)
    {
        b = rand() % 8;

        GetCursorPos(&m);
        switch (b)
        {
        case 0:

            setr();
            SetCursorPos(m.x + rand() % 15, m.y + rand() % 15);
            c++; d++;
            rect.left += 10;
            rect.top += 10;
            MoveWindow(win, rect.left, rect.top, rect.right, rect.bottom, TRUE);
            break;
        case 1:
            setr();
            SetCursorPos(m.x - rand() % 15, m.y - rand() % 15);
            c--; d--;
            rect.left -= 10;
            rect.top -= 10;
            MoveWindow(win, rect.left, rect.top, rect.right, rect.bottom, TRUE);
            break;
        case 2:
            setr();
            SetCursorPos(m.x + rand() % 15, m.y - rand() % 15);
            c++, d--;
            rect.left += 10;
            rect.top -= 10;
            MoveWindow(win, rect.left, rect.top, rect.right, rect.bottom, TRUE);
            break;
        case 3:
            setr();
            SetCursorPos(m.x - rand() % 15, m.y + rand() % 15);
            rect.left -= 10;
            rect.top += 10;
            MoveWindow(win, rect.left, rect.top, rect.right, rect.bottom, TRUE);
            c--, d++;
            break;
        }
        cmd.clear();
        cmd = "mode ";
        cmd.append(to_string(c));
        cmd.push_back(',');
        cmd.append(to_string(d));
        system(cmd.c_str());
        system("cls");
        x = rand() % 5;
        if (i > 257)
        {
            i = 0;
        }
        srand(rand());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << string(x, '\n');
        for (int s = 0; s < 17; s++)
        {
            cout << string(b, ' ') << text[s] << endl;
        }
        cout << string(rand() % 10, '\n');
        if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000) ? 1 : 0)
        {
            exit(0);
        }
        if ((GetAsyncKeyState((unsigned short)'R') & 0x8000) ? 1 : 0)
        {
            style = GetWindowLong(hwnd, GWL_STYLE);
            style = style & ~WS_CAPTION & ~WS_SIZEBOX;
            SetWindowLong(hwnd, GWL_STYLE, style);
            int screenX = GetSystemMetrics(SM_CXSCREEN);
            int screenY = GetSystemMetrics(SM_CYSCREEN);
            SetWindowPos(hwnd, NULL, 0, 0, screenX, screenY, SWP_NOZORDER);
            SetWindowLong(win, GWL_STYLE, style);
            GetWindowRect(win, &rect);
        }
        if ((GetAsyncKeyState((unsigned short)'P') & 0x8000) ? 1 : 0)
        {
            MoveWindow
            (
                win, GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN),
                GetSystemMetrics(SM_CXFULLSCREEN) + GetSystemMetrics(SM_CXFULLSCREEN),
                GetSystemMetrics(SM_CYFULLSCREEN) + GetSystemMetrics(SM_CYFULLSCREEN),
                TRUE
            );
            style = GetWindowLong(hwnd, GWL_STYLE);
            style = style & ~WS_CAPTION & ~WS_SIZEBOX;
            SetWindowLong(hwnd, GWL_STYLE, style);
            int screenX = GetSystemMetrics(SM_CXSCREEN);
            int screenY = GetSystemMetrics(SM_CYSCREEN);
            SetWindowPos(hwnd, NULL, 0, 0, screenX, screenY, SWP_NOZORDER);
            SetWindowLong(win, GWL_STYLE, style);
            GetWindowRect(win, &rect);
            cmd.clear();
            cmd = "mode ";
            cmd.append(to_string(c));
            cmd.push_back(',');
            cmd.append(to_string(d));
            system(cmd.c_str());
            GetWindowRect(win, &rect);
        }
    }
}
