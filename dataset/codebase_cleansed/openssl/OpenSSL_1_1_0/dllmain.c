BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
switch (fdwReason) {
case DLL_PROCESS_ATTACH:
OPENSSL_cpuid_setup();
# if defined(_WIN32_WINNT)
{
IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *) hinstDLL;
IMAGE_NT_HEADERS *nt_headers;
if (dos_header->e_magic == IMAGE_DOS_SIGNATURE) {
nt_headers = (IMAGE_NT_HEADERS *) ((char *)dos_header
+ dos_header->e_lfanew);
if (nt_headers->Signature == IMAGE_NT_SIGNATURE &&
hinstDLL !=
(HINSTANCE) (nt_headers->OptionalHeader.ImageBase))
OPENSSL_NONPIC_relocated = 1;
}
}
# endif
break;
case DLL_THREAD_ATTACH:
break;
case DLL_THREAD_DETACH:
OPENSSL_thread_stop();
break;
case DLL_PROCESS_DETACH:
break;
}
return (TRUE);
}
