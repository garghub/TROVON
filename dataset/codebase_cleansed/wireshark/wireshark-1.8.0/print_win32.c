void print_mswin(char *file_name)
{
HDC hDC;
DOCINFO di;
HWND hWndParent = HWND_DESKTOP;
hDC = get_printer_dc();
if( !hDC)
{
return;
}
if( SetAbortProc( hDC, abort_proc ) == SP_ERROR )
{
MessageBox( NULL, "Error setting up AbortProc",
"Error", MB_APPLMODAL | MB_OK);
return;
}
init_doc_struct( &di, "MyDoc");
StartDoc( hDC, &di );
StartPage( hDC );
print_file(file_name, hDC );
EndPage( hDC );
EndDoc( hDC );
DeleteDC( hDC );
}
static HDC get_printer_dc(void)
{
PRINTDLG pdlg;
memset( &pdlg, 0, sizeof( PRINTDLG ) );
pdlg.lStructSize = sizeof( PRINTDLG );
pdlg.Flags =
PD_RETURNDC |
PD_NOPAGENUMS |
PD_NOSELECTION |
PD_USEDEVMODECOPIESANDCOLLATE;
PrintDlg( &pdlg );
return pdlg.hDC;
}
static BOOL CALLBACK abort_proc( HDC hDC, int Error )
{
MSG msg;
while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
{
TranslateMessage( &msg );
DispatchMessage( &msg );
}
return TRUE;
}
static void init_doc_struct( DOCINFO* di, char* docname)
{
memset( di, 0, sizeof( DOCINFO ) );
di->cbSize = sizeof( DOCINFO );
di->lpszDocName = docname;
}
static void print_file( char *file_name, HDC hdc) {
#define max_buf_size 1024
#define max_lines 66
#define y_offset 5
#define x_offset 5
FILE* fh1;
size_t results;
int cnt=0, y_pos = y_offset, y_cnt = 0;
char buf[ max_buf_size];
char ch;
TEXTMETRIC tm;
GetTextMetrics(hdc, &tm);
SetMapMode (hdc, MM_TEXT);
fh1 = ws_fopen( file_name, "r" );
if( !fh1 ) {
MessageBox( NULL, "Open failed on input file",
"Error", MB_APPLMODAL | MB_OK);
return;
}
while ((results = fread( &ch, 1, 1, fh1 )) != 0) {
if ( ch == 0x0c){
buf[cnt] = 0;
TextOut(hdc, x_offset,y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
EndPage( hdc );
StartPage( hdc );
y_pos = y_offset;
y_cnt = 0;
continue;
}
if ( ch == 0x0a){
buf[ cnt] = 0;
TextOut(hdc, x_offset,y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
if ( ++y_cnt == max_lines){
EndPage( hdc );
StartPage( hdc );
y_pos = y_offset;
y_cnt = 0;
}
continue;
}
if ( cnt == ( max_buf_size - 1)) {
buf[ cnt] = 0;
TextOut(hdc, x_offset, y_pos, buf, (int) strlen(buf));
y_pos += tm.tmHeight;
cnt = 0;
if ( ++y_cnt == max_lines){
EndPage( hdc );
StartPage( hdc );
y_pos = y_offset;
y_cnt = 0;
}
continue;
}
buf[ cnt++] = ch;
}
if ( cnt > 0) {
buf[ cnt] = 0;
TextOut(hdc, 0,y_pos, buf, (int) strlen(buf));
}
fclose(fh1);
}
