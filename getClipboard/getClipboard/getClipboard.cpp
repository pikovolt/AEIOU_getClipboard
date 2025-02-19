#include <iostream>
#include <windows.h>

int main()
{
    HANDLE hData;
    char* pszText;

    // クリップボードを開く
    if (!OpenClipboard(NULL)) {
        std::cout << "クリップボードを開けませんでした。\n";
        return 1;
    }

    // クリップボードからデータを取得
    hData = GetClipboardData(CF_TEXT);
    if (hData == NULL) {
        CloseClipboard();
        std::cout << "クリップボードからデータを取得できませんでした。\n";
        return 1;
    }

    // データにロックをかける
    pszText = static_cast<char*>(GlobalLock(hData));

    // テキストを表示
    std::cout << pszText << std::endl;

    // ロックを解除
    GlobalUnlock(hData);

    // クリップボードを閉じる
    CloseClipboard();

    return 0;
}
