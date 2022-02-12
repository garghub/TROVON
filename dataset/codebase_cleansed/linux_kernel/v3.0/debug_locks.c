int debug_locks_off(void)
{
if (__debug_locks_off()) {
if (!debug_locks_silent) {
console_verbose();
return 1;
}
}
return 0;
}
