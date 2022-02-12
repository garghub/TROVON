PCHAR __init
ArcGetEnvironmentVariable(CHAR *name)
{
return (CHAR *) ARC_CALL1(get_evar, name);
}
LONG __init
ArcSetEnvironmentVariable(PCHAR name, PCHAR value)
{
return ARC_CALL2(set_evar, name, value);
}
