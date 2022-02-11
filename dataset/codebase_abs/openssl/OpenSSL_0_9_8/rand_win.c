int F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 = 0 ;
T_3 V_3 [ 64 ] ;
T_4 V_4 ;
T_5 V_5 ;
int V_6 = 0 ;
T_6 V_7 , V_8 , V_9 , V_10 ;
T_7 V_11 = 0 ;
T_8 V_12 = 0 ;
T_9 V_13 = 0 ;
#if 1
T_10 V_14 = 0 ;
T_11 V_15 = 0 ;
#endif
T_12 V_16 ;
V_16 . V_17 = sizeof( T_12 ) ;
F_2 ( & V_16 ) ;
#if F_3 ( V_18 ) && V_19 != V_20
#ifndef F_4
#define F_4 CryptAcquireContextW
#endif
if ( F_4 ( & V_2 , 0 , 0 , V_21 , V_22 ) )
{
if ( F_5 ( V_2 , sizeof( V_3 ) , V_3 ) )
F_6 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
F_7 ( V_2 , 0 ) ;
}
#endif
#ifndef V_18
V_7 = F_8 ( F_9 ( L_1 ) ) ;
V_8 = F_8 ( F_9 ( L_2 ) ) ;
V_9 = F_8 ( F_9 ( L_3 ) ) ;
V_10 = F_8 ( F_9 ( L_4 ) ) ;
#if 1
if ( V_10 )
{
V_14 = ( T_10 ) F_10 ( V_10 , L_5 ) ;
V_15 = ( T_11 ) F_10 ( V_10 , L_6 ) ;
}
if ( V_14 && V_15 )
{
T_13 V_23 ;
if ( V_14 ( NULL , L_7 , 0 , 0 , & V_23 ) == 0 )
{
F_6 ( V_23 , sizeof( V_24 ) , 45 ) ;
V_15 ( V_23 ) ;
}
if ( V_14 ( NULL , L_8 , 0 , 0 , & V_23 ) == 0 )
{
F_6 ( V_23 , sizeof( V_25 ) , 17 ) ;
V_15 ( V_23 ) ;
}
}
if ( V_10 )
F_11 ( V_10 ) ;
#endif
#if 0
if ( osverinfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
osverinfo.dwMajorVersion < 5)
{
LONG rc=ERROR_MORE_DATA;
char * buf=NULL;
DWORD bufsz=0;
DWORD length;
while (rc == ERROR_MORE_DATA)
{
buf = realloc(buf,bufsz+8192);
if (!buf)
break;
bufsz += 8192;
length = bufsz;
rc = RegQueryValueEx(HKEY_PERFORMANCE_DATA, TEXT("Global"),
NULL, NULL, buf, &length);
}
if (rc == ERROR_SUCCESS)
{
RAND_add(&length, sizeof(length), 0);
RAND_add(buf, length, length / 4.0);
RegCloseKey(HKEY_PERFORMANCE_DATA);
}
if (buf)
free(buf);
}
#endif
if ( V_7 )
{
V_11 = ( T_7 ) F_10 ( V_7 ,
L_9 ) ;
V_12 = ( T_8 ) F_10 ( V_7 ,
L_10 ) ;
V_13 = ( T_9 ) F_10 ( V_7 ,
L_11 ) ;
}
if ( V_11 && V_12 && V_13 )
{
if ( V_11 ( & V_2 , 0 , 0 , V_21 ,
V_22 ) )
{
if ( V_12 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_6 ( V_3 , sizeof( V_3 ) , 0 ) ;
V_6 = 1 ;
#if 0
printf("randomness from PROV_RSA_FULL\n");
#endif
}
V_13 ( V_2 , 0 ) ;
}
if ( V_11 ( & V_2 , 0 , V_26 , V_27 , 0 ) )
{
if ( V_12 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_6 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
V_6 = 1 ;
#if 0
printf("randomness from PROV_INTEL_SEC\n");
#endif
}
V_13 ( V_2 , 0 ) ;
}
}
if ( V_7 )
F_11 ( V_7 ) ;
if ( V_9 )
{
T_14 V_28 ;
T_15 V_29 ;
T_16 V_30 ;
V_29 = ( T_15 ) F_10 ( V_9 , L_12 ) ;
V_28 = ( T_14 ) F_10 ( V_9 , L_13 ) ;
V_30 = ( T_16 ) F_10 ( V_9 , L_14 ) ;
if ( V_29 )
{
V_5 = V_29 () ;
F_6 ( & V_5 , sizeof( V_5 ) , 0 ) ;
}
if ( V_28 )
{
if ( V_16 . V_31 == V_32 &&
V_16 . V_33 < 5 )
V_28 = 0 ;
}
if ( V_28 )
{
T_17 V_34 ;
V_34 . V_35 = sizeof( T_17 ) ;
if ( V_28 ( & V_34 ) )
F_6 ( & V_34 , V_34 . V_35 , 2 ) ;
}
if ( V_30 )
{
V_4 = V_30 ( V_36 ) ;
F_6 ( & V_4 , sizeof( V_4 ) , 1 ) ;
}
F_11 ( V_9 ) ;
}
if ( V_8 )
{
T_18 V_37 ;
T_19 V_38 ;
T_20 V_39 ;
T_21 V_40 ;
T_22 V_41 ;
T_23 V_42 , V_43 ;
T_24 V_44 , V_45 ;
T_25 V_46 , V_47 ;
T_26 V_48 , V_49 ;
T_27 V_50 ;
T_28 V_51 ;
T_29 V_52 ;
T_30 V_53 ;
T_31 V_1 ;
T_4 V_54 = 0 ;
V_37 = ( T_18 )
F_10 ( V_8 , L_15 ) ;
V_38 = ( T_19 )
F_10 ( V_8 , L_16 ) ;
V_40 = ( T_21 ) F_10 ( V_8 , L_17 ) ;
V_41 = ( T_22 ) F_10 ( V_8 , L_18 ) ;
V_42 = ( T_23 ) F_10 ( V_8 , L_19 ) ;
V_43 = ( T_23 ) F_10 ( V_8 , L_20 ) ;
V_44 = ( T_24 ) F_10 ( V_8 , L_21 ) ;
V_45 = ( T_24 ) F_10 ( V_8 , L_22 ) ;
V_46 = ( T_25 ) F_10 ( V_8 , L_23 ) ;
V_47 = ( T_25 ) F_10 ( V_8 , L_24 ) ;
V_48 = ( T_26 ) F_10 ( V_8 , L_25 ) ;
V_49 = ( T_26 ) F_10 ( V_8 , L_26 ) ;
if ( V_37 && V_40 && V_41 && V_42 &&
V_43 && V_44 && V_45 &&
V_46 && V_47 && V_48 &&
V_49 && ( V_39 = V_37 ( V_55 , 0 ) )
!= V_56 )
{
V_50 . V_57 = sizeof( T_27 ) ;
if ( V_6 ) V_54 = F_12 () + V_58 ;
if ( V_42 ( V_39 , & V_50 ) )
do
{
F_6 ( & V_50 , V_50 . V_57 , 3 ) ;
V_51 . V_57 = sizeof( T_28 ) ;
if ( V_40 ( & V_51 ,
V_50 . V_59 ,
V_50 . V_60 ) )
{
int V_61 = 80 ;
do
F_6 ( & V_51 ,
V_51 . V_57 , 5 ) ;
while ( V_41 ( & V_51 )
&& -- V_61 > 0 );
}
} while ( V_43 ( V_39 ,
& V_50 ) && F_12 () < V_54 );
V_52 . V_57 = sizeof( T_29 ) ;
if ( V_6 ) V_54 = F_12 () + V_58 ;
if ( V_44 ( V_39 , & V_52 ) )
do
F_6 ( & V_52 , V_52 . V_57 , 9 ) ;
while ( V_45 ( V_39 , & V_52 ) && F_12 () < V_54 );
V_53 . V_57 = sizeof( T_30 ) ;
if ( V_6 ) V_54 = F_12 () + V_58 ;
if ( V_46 ( V_39 , & V_53 ) )
do
F_6 ( & V_53 , V_53 . V_57 , 6 ) ;
while ( V_47 ( V_39 , & V_53 ) && F_12 () < V_54 );
V_1 . V_57 = sizeof( T_31 ) ;
if ( V_6 ) V_54 = F_12 () + V_58 ;
if ( V_48 ( V_39 , & V_1 ) )
do
F_6 ( & V_1 , V_1 . V_57 , 9 ) ;
while ( V_49 ( V_39 , & V_1 )
&& ( F_12 () < V_54 ) );
if ( V_38 )
V_38 ( V_39 ) ;
else
F_13 ( V_39 ) ;
}
F_11 ( V_8 ) ;
}
#endif
F_14 () ;
F_15 ( & V_1 ) ;
F_6 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_4 = F_16 () ;
F_6 ( & V_4 , sizeof( V_4 ) , 1 ) ;
#if 0
printf("Exiting RAND_poll\n");
#endif
return ( 1 ) ;
}
int F_17 ( T_32 V_62 , T_33 V_63 , T_34 V_64 )
{
double V_65 = 0 ;
switch ( V_62 )
{
case V_66 :
{
static T_33 V_67 ;
if ( V_67 != V_63 )
V_65 = 0.05 ;
V_67 = V_63 ;
}
break;
case V_68 :
{
static int V_69 , V_70 , V_71 , V_72 ;
int V_73 , V_74 , V_75 , V_76 ;
V_73 = F_18 ( V_64 ) ;
V_74 = F_19 ( V_64 ) ;
V_75 = V_69 - V_73 ;
V_76 = V_70 - V_74 ;
if ( V_75 != 0 && V_76 != 0 && V_75 - V_71 != 0 && V_76 - V_72 != 0 )
V_65 = .2 ;
V_69 = V_73 , V_70 = V_74 ;
V_71 = V_75 , V_72 = V_76 ;
}
break;
}
F_14 () ;
F_6 ( & V_62 , sizeof( V_62 ) , V_65 ) ;
F_6 ( & V_63 , sizeof( V_63 ) , 0 ) ;
F_6 ( & V_64 , sizeof( V_64 ) , 0 ) ;
return ( F_20 () ) ;
}
void F_21 ( void )
{
F_1 () ;
if ( F_22 () >= 0x80000000 || ! F_23 () )
F_24 () ;
}
static void F_14 ( void )
{
T_4 V_4 ;
T_35 V_77 ;
static int V_78 = 1 ;
#if F_3 ( V_79 ) && F_3 ( V_80 )
static int V_81 = 1 ;
T_4 V_82 ;
if ( V_81 ) {
F_25 {
__asm {
_emit 0x0f
_emit 0x31
mov cyclecount, eax
}
F_6 ( & V_82 , sizeof( V_82 ) , 1 ) ;
} F_26 (EXCEPTION_EXECUTE_HANDLER) {
V_81 = 0 ;
}
}
#else
# define V_81 0
#endif
if ( V_78 ) {
if ( F_27 ( & V_77 ) == 0 )
V_78 = 0 ;
else
F_6 ( & V_77 , sizeof( V_77 ) , 0 ) ;
}
if ( ! V_81 && ! V_78 ) {
V_4 = F_12 () ;
F_6 ( & V_4 , sizeof( V_4 ) , 0 ) ;
}
}
static void F_24 ( void )
{
#if ! F_3 ( V_18 ) && ! F_3 ( V_83 )
T_36 V_84 ;
T_36 V_85 ;
T_37 V_86 ;
T_37 V_87 ;
T_38 V_88 ;
unsigned int V_89 ;
char * V_90 ;
int V_4 ;
int V_5 ;
int V_74 ;
int V_91 = 16 ;
V_84 = F_28 ( F_9 ( L_27 ) , NULL , NULL , NULL ) ;
V_85 = F_29 ( V_84 ) ;
V_4 = F_30 ( V_84 , V_92 ) ;
V_5 = F_30 ( V_84 , V_93 ) ;
V_86 = F_31 ( V_84 , V_4 , V_91 ) ;
V_87 = F_32 ( V_85 , V_86 ) ;
F_33 ( V_86 , sizeof( T_38 ) , ( V_94 ) & V_88 ) ;
V_89 = ( unsigned int ) V_88 . V_95 * V_88 . V_96 * V_88 . V_97 ;
V_90 = F_34 ( V_89 ) ;
if ( V_90 ) {
for ( V_74 = 0 ; V_74 < V_5 - V_91 ; V_74 += V_91 )
{
unsigned char V_98 [ V_99 ] ;
F_35 ( V_85 , 0 , 0 , V_4 , V_91 , V_84 , 0 , V_74 , V_100 ) ;
F_36 ( V_86 , V_89 , V_90 ) ;
F_37 ( V_90 , V_89 , V_98 ) ;
F_6 ( V_98 , V_99 , 0 ) ;
}
F_38 ( V_90 ) ;
}
V_86 = F_32 ( V_85 , V_87 ) ;
F_39 ( V_86 ) ;
F_40 ( V_85 ) ;
F_40 ( V_84 ) ;
#endif
}
