int F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 = 0 ;
T_3 V_3 [ 64 ] ;
T_4 V_4 ;
T_5 V_5 ;
T_6 V_6 , V_7 , V_8 , V_9 ;
T_7 V_10 = 0 ;
T_8 V_11 = 0 ;
T_9 V_12 = 0 ;
#if 1
T_10 V_13 = 0 ;
T_11 V_14 = 0 ;
#endif
T_12 V_15 ;
V_15 . V_16 = sizeof( T_12 ) ;
F_2 ( & V_15 ) ;
#if F_3 ( V_17 ) && V_18 != V_19
if ( F_4 ( & V_2 , 0 , 0 , V_20 , V_21 ) )
{
if ( F_5 ( V_2 , sizeof( V_3 ) , V_3 ) )
F_6 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
F_7 ( V_2 , 0 ) ;
}
#endif
V_6 = F_8 ( F_9 ( L_1 ) ) ;
V_7 = F_8 ( F_9 ( L_2 ) ) ;
V_8 = F_8 ( F_9 ( L_3 ) ) ;
V_9 = F_8 ( F_9 ( L_4 ) ) ;
#ifndef V_17
#if 1
if ( V_9 )
{
V_13 = ( T_10 ) F_10 ( V_9 , F_9 ( L_5 ) ) ;
V_14 = ( T_11 ) F_10 ( V_9 , F_9 ( L_6 ) ) ;
}
if ( V_13 && V_14 )
{
T_13 V_22 ;
if ( V_13 ( NULL , L_7 , 0 , 0 , & V_22 ) == 0 )
{
F_6 ( V_22 , sizeof( V_23 ) , 45 ) ;
V_14 ( V_22 ) ;
}
if ( V_13 ( NULL , L_8 , 0 , 0 , & V_22 ) == 0 )
{
F_6 ( V_22 , sizeof( V_24 ) , 17 ) ;
V_14 ( V_22 ) ;
}
}
if ( V_9 )
F_11 ( V_9 ) ;
#endif
#endif
#ifndef V_17
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
#endif
if ( V_6 )
{
V_10 = ( T_7 ) F_10 ( V_6 ,
F_9 ( L_9 ) ) ;
V_11 = ( T_8 ) F_10 ( V_6 ,
F_9 ( L_10 ) ) ;
V_12 = ( T_9 ) F_10 ( V_6 ,
F_9 ( L_11 ) ) ;
}
if ( V_10 && V_11 && V_12 )
{
if ( V_10 ( & V_2 , 0 , 0 , V_20 ,
V_21 ) )
{
if ( V_11 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_6 ( V_3 , sizeof( V_3 ) , 0 ) ;
#if 0
printf("randomness from PROV_RSA_FULL\n");
#endif
}
V_12 ( V_2 , 0 ) ;
}
if ( V_10 ( & V_2 , 0 , V_25 , V_26 , 0 ) )
{
if ( V_11 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_6 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
#if 0
printf("randomness from PROV_INTEL_SEC\n");
#endif
}
V_12 ( V_2 , 0 ) ;
}
}
if ( V_6 )
F_11 ( V_6 ) ;
F_12 () ;
F_13 ( & V_1 ) ;
F_6 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_4 = F_14 () ;
F_6 ( & V_4 , sizeof( V_4 ) , 1 ) ;
if ( V_8 )
{
T_14 V_27 ;
T_15 V_28 ;
T_16 V_29 ;
V_28 = ( T_15 ) F_10 ( V_8 , F_9 ( L_12 ) ) ;
V_27 = ( T_14 ) F_10 ( V_8 , F_9 ( L_13 ) ) ;
V_29 = ( T_16 ) F_10 ( V_8 , F_9 ( L_14 ) ) ;
if ( V_28 )
{
V_5 = V_28 () ;
F_6 ( & V_5 , sizeof( V_5 ) , 0 ) ;
}
if ( V_27 )
{
if ( V_15 . V_30 == V_31 &&
V_15 . V_32 < 5 )
V_27 = 0 ;
}
if ( V_27 )
{
T_17 V_33 ;
V_33 . V_34 = sizeof( T_17 ) ;
if ( V_27 ( & V_33 ) )
F_6 ( & V_33 , V_33 . V_34 , 2 ) ;
}
if ( V_29 )
{
V_4 = V_29 ( V_35 ) ;
F_6 ( & V_4 , sizeof( V_4 ) , 1 ) ;
}
F_11 ( V_8 ) ;
}
if ( V_7 )
{
T_18 V_36 ;
T_19 V_37 ;
T_20 V_38 ;
T_21 V_39 ;
T_22 V_40 , V_41 ;
T_23 V_42 , V_43 ;
T_24 V_44 , V_45 ;
T_25 V_46 , V_47 ;
T_26 V_48 ;
T_27 V_49 ;
T_28 V_50 ;
T_29 V_51 ;
T_30 V_1 ;
V_36 = ( T_18 )
F_10 ( V_7 , F_9 ( L_15 ) ) ;
V_38 = ( T_20 ) F_10 ( V_7 , F_9 ( L_16 ) ) ;
V_39 = ( T_21 ) F_10 ( V_7 , F_9 ( L_17 ) ) ;
V_40 = ( T_22 ) F_10 ( V_7 , F_9 ( L_18 ) ) ;
V_41 = ( T_22 ) F_10 ( V_7 , F_9 ( L_19 ) ) ;
V_42 = ( T_23 ) F_10 ( V_7 , F_9 ( L_20 ) ) ;
V_43 = ( T_23 ) F_10 ( V_7 , F_9 ( L_21 ) ) ;
V_44 = ( T_24 ) F_10 ( V_7 , F_9 ( L_22 ) ) ;
V_45 = ( T_24 ) F_10 ( V_7 , F_9 ( L_23 ) ) ;
V_46 = ( T_25 ) F_10 ( V_7 , F_9 ( L_24 ) ) ;
V_47 = ( T_25 ) F_10 ( V_7 , F_9 ( L_25 ) ) ;
if ( V_36 && V_38 && V_39 && V_40 &&
V_41 && V_42 && V_43 &&
V_44 && V_45 && V_46 &&
V_47 && ( V_37 = V_36 ( V_52 , 0 ) )
!= NULL )
{
V_48 . V_53 = sizeof( T_26 ) ;
if ( V_40 ( V_37 , & V_48 ) )
do
{
F_6 ( & V_48 , V_48 . V_53 , 3 ) ;
V_49 . V_53 = sizeof( T_27 ) ;
if ( V_38 ( & V_49 ,
V_48 . V_54 ,
V_48 . V_55 ) )
{
int V_56 = 80 ;
do
F_6 ( & V_49 ,
V_49 . V_53 , 5 ) ;
while ( V_39 ( & V_49 )
&& -- V_56 > 0 );
}
} while ( V_41 ( V_37 ,
& V_48 ) );
V_50 . V_53 = sizeof( T_28 ) ;
if ( V_42 ( V_37 , & V_50 ) )
do
F_6 ( & V_50 , V_50 . V_53 , 9 ) ;
while ( V_43 ( V_37 , & V_50 ) );
V_51 . V_53 = sizeof( T_29 ) ;
if ( V_44 ( V_37 , & V_51 ) )
do
F_6 ( & V_51 , V_51 . V_53 , 6 ) ;
while ( V_45 ( V_37 , & V_51 ) );
V_1 . V_53 = sizeof( T_30 ) ;
if ( V_46 ( V_37 , & V_1 ) )
do
F_6 ( & V_1 , V_1 . V_53 , 9 ) ;
while ( V_47 ( V_37 , & V_1 ) );
F_15 ( V_37 ) ;
}
F_11 ( V_7 ) ;
}
#if 0
printf("Exiting RAND_poll\n");
#endif
return ( 1 ) ;
}
int F_16 ( T_31 V_57 , T_32 V_58 , T_33 V_59 )
{
double V_60 = 0 ;
switch ( V_57 )
{
case V_61 :
{
static T_32 V_62 ;
if ( V_62 != V_58 )
V_60 = 0.05 ;
V_62 = V_58 ;
}
break;
case V_63 :
{
static int V_64 , V_65 , V_66 , V_67 ;
int V_68 , V_69 , V_70 , V_71 ;
V_68 = F_17 ( V_59 ) ;
V_69 = F_18 ( V_59 ) ;
V_70 = V_64 - V_68 ;
V_71 = V_65 - V_69 ;
if ( V_70 != 0 && V_71 != 0 && V_70 - V_66 != 0 && V_71 - V_67 != 0 )
V_60 = .2 ;
V_64 = V_68 , V_65 = V_69 ;
V_66 = V_70 , V_67 = V_71 ;
}
break;
}
F_12 () ;
F_6 ( & V_57 , sizeof( V_57 ) , V_60 ) ;
F_6 ( & V_58 , sizeof( V_58 ) , 0 ) ;
F_6 ( & V_59 , sizeof( V_59 ) , 0 ) ;
return ( F_19 () ) ;
}
void F_20 ( void )
{
F_1 () ;
F_21 () ;
}
static void F_12 ( void )
{
T_4 V_4 ;
T_34 V_72 ;
static int V_73 = 1 ;
#if F_3 ( V_74 ) && ! F_3 ( V_17 )
static int V_75 = 1 ;
T_4 V_76 ;
if ( V_75 ) {
F_22 {
__asm {
_emit 0x0f
_emit 0x31
mov cyclecount, eax
}
F_6 ( & V_76 , sizeof( V_76 ) , 1 ) ;
} F_23 (EXCEPTION_EXECUTE_HANDLER) {
V_75 = 0 ;
}
}
#else
# define V_75 0
#endif
if ( V_73 ) {
if ( F_24 ( & V_72 ) == 0 )
V_73 = 0 ;
else
F_6 ( & V_72 , sizeof( V_72 ) , 0 ) ;
}
if ( ! V_75 && ! V_73 ) {
V_4 = F_25 () ;
F_6 ( & V_4 , sizeof( V_4 ) , 0 ) ;
}
}
static void F_21 ( void )
{
#ifndef V_17
T_35 V_77 ;
T_35 V_78 ;
T_36 V_79 ;
T_36 V_80 ;
T_37 V_81 ;
unsigned int V_82 ;
char * V_83 ;
int V_4 ;
int V_5 ;
int V_69 ;
int V_84 = 16 ;
V_77 = F_26 ( F_9 ( L_26 ) , NULL , NULL , NULL ) ;
V_78 = F_27 ( V_77 ) ;
V_4 = F_28 ( V_77 , V_85 ) ;
V_5 = F_28 ( V_77 , V_86 ) ;
V_79 = F_29 ( V_77 , V_4 , V_84 ) ;
V_80 = F_30 ( V_78 , V_79 ) ;
F_31 ( V_79 , sizeof( T_37 ) , ( V_87 ) & V_81 ) ;
V_82 = ( unsigned int ) V_81 . V_88 * V_81 . V_89 * V_81 . V_90 ;
V_83 = F_32 ( V_82 ) ;
if ( V_83 ) {
for ( V_69 = 0 ; V_69 < V_5 - V_84 ; V_69 += V_84 )
{
unsigned char V_91 [ V_92 ] ;
F_33 ( V_78 , 0 , 0 , V_4 , V_84 , V_77 , 0 , V_69 , V_93 ) ;
F_34 ( V_79 , V_82 , V_83 ) ;
F_35 ( V_83 , V_82 , V_91 ) ;
F_6 ( V_91 , V_92 , 0 ) ;
}
F_36 ( V_83 ) ;
}
V_79 = F_30 ( V_78 , V_80 ) ;
F_37 ( V_79 ) ;
F_38 ( V_78 ) ;
F_38 ( V_77 ) ;
#endif
}
