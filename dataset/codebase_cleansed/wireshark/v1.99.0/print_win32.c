void print_mswin(const char *file_name)
{
HDC hDC;
DOCINFO di;
short int width, height;
hDC = get_printer_dc(&width, &height);
if (!hDC) {
return;
}
if (SetAbortProc(hDC, abort_proc) == SP_ERROR) {
MessageBox(NULL, "Error setting up AbortProc",
"Error", MB_APPLMODAL | MB_OK);
return;
}
init_doc_struct(&di, "MyDoc");
StartDoc(hDC, &di);
StartPage(hDC);
print_file(file_name, hDC, width, height);
EndPage(hDC);
EndDoc(hDC);
DeleteDC(hDC);
}
static HDC get_printer_dc(short *width, short *height)
{
PRINTDLG pdlg;
PDEVMODE returnedDevmode;
memset(&pdlg, 0, sizeof(PRINTDLG));
pdlg.lStructSize = sizeof(PRINTDLG);
pdlg.Flags =
PD_RETURNDC |
PD_NOPAGENUMS |
PD_NOSELECTION |
PD_USEDEVMODECOPIESANDCOLLATE;
if (PrintDlg(&pdlg)) {
returnedDevmode = (PDEVMODE)GlobalLock(pdlg.hDevMode);
if (returnedDevmode == NULL) {
if (pdlg.hDevMode)
GlobalFree(pdlg.hDevMode);
if (pdlg.hDevNames)
GlobalFree(pdlg.hDevNames);
return NULL;
}
if (returnedDevmode->dmOrientation == DMORIENT_LANDSCAPE) {
*width = returnedDevmode->dmPaperLength;
*height = returnedDevmode->dmPaperWidth;
}
else {
*width = returnedDevmode->dmPaperWidth;
*height = returnedDevmode->dmPaperLength;
}
GlobalUnlock(pdlg.hDevMode);
if (pdlg.hDevMode)
GlobalFree(pdlg.hDevMode);
if (pdlg.hDevNames)
GlobalFree(pdlg.hDevNames);
}
return pdlg.hDC;
}
static BOOL CALLBACK abort_proc(HDC hDC, int Error)
{
MSG msg;
while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return TRUE;
}
static void init_doc_struct(DOCINFO* di, char* docname)
{
memset(di, 0, sizeof(DOCINFO));
di->cbSize = sizeof(DOCINFO);
di->lpszDocName = docname;
}
static void print_file(const char *file_name, HDC hdc, int width, int height)
{
#define MAX_BUF_SIZE 1024
#define X_OFFSET 5
#define Y_OFFSET 5
FILE* fh1;
size_t results;
int cnt=0, y_pos = Y_OFFSET, y_cnt = 0;
char buf[MAX_BUF_SIZE];
char ch;
TEXTMETRIC tm;
int max_chars_per_line, max_lines_per_page;
SetMapMode(hdc, MM_LOMETRIC);
GetTextMetrics(hdc, &tm);
max_chars_per_line = MIN(width / (tm.tmMaxCharWidth + 1), MAX_BUF_SIZE);
max_lines_per_page = height / (tm.tmHeight + 1);
SetMapMode(hdc, MM_TEXT);
GetTextMetrics(hdc, &tm);
fh1 = ws_fopen(file_name, "r");
if (!fh1) {
MessageBox(NULL, "Open failed on input file",
"Error", MB_APPLMODAL | MB_OK);
return;
}
while ((results = fread(&ch, 1, 1, fh1)) != 0) {
if (ch == 0x0c) {
buf[cnt] = 0;
TextOut(hdc, X_OFFSET,y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
EndPage(hdc);
StartPage(hdc);
y_pos = Y_OFFSET;
y_cnt = 0;
continue;
}
if (ch == 0x0a) {
buf[cnt] = 0;
TextOut(hdc, X_OFFSET,y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
if (++y_cnt == max_lines_per_page) {
EndPage(hdc);
StartPage(hdc);
y_pos = Y_OFFSET;
y_cnt = 0;
}
continue;
}
if (cnt == (max_chars_per_line - 1)) {
buf[cnt] = 0;
TextOut(hdc, X_OFFSET, y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
if (++y_cnt == max_lines_per_page) {
EndPage(hdc);
StartPage(hdc);
y_pos = Y_OFFSET;
y_cnt = 0;
}
}
buf[cnt++] = ch;
}
if (cnt > 0) {
buf[cnt] = 0;
TextOut(hdc, 0,y_pos, buf, (int) strlen(buf));
}
fclose(fh1);
}
