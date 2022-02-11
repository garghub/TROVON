int F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 = 0 ;
T_3 V_3 ;
int V_4 = 0 ;
T_4 V_5 ;
V_5 . V_6 = sizeof( T_4 ) ;
F_2 ( & V_5 ) ;
#if F_3 ( V_7 )
# if F_3 ( V_8 ) && V_8 >= 300
{
T_5 V_9 [ 64 ] ;
if ( F_4 ( & V_2 , NULL , NULL , V_10 ,
V_11 ) )
{
if ( F_5 ( V_2 , sizeof( V_9 ) , V_9 ) )
F_6 ( V_9 , sizeof( V_9 ) , sizeof( V_9 ) ) ;
F_7 ( V_2 , 0 ) ;
}
}
# endif
#else
{
T_6 V_12 = F_8 ( F_9 ( L_1 ) ) ;
T_6 V_13 = F_8 ( F_9 ( L_2 ) ) ;
T_6 V_14 = NULL ;
T_6 V_15 = F_8 ( F_9 ( L_3 ) ) ;
T_7 V_16 = NULL ;
T_8 V_17 = NULL ;
T_9 V_18 = NULL ;
T_10 V_19 = NULL ;
T_11 V_20 = NULL ;
T_5 V_9 [ 64 ] ;
if ( V_15 )
{
V_19 = ( T_10 ) F_10 ( V_15 , L_4 ) ;
V_20 = ( T_11 ) F_10 ( V_15 , L_5 ) ;
}
if ( V_19 && V_20 )
{
T_12 V_21 ;
if ( V_19 ( NULL , L_6 , 0 , 0 , & V_21 ) == 0 )
{
F_6 ( V_21 , sizeof( V_22 ) , 45 ) ;
V_20 ( V_21 ) ;
}
if ( V_19 ( NULL , L_7 , 0 , 0 , & V_21 ) == 0 )
{
F_6 ( V_21 , sizeof( V_23 ) , 17 ) ;
V_20 ( V_21 ) ;
}
}
if ( V_15 )
F_11 ( V_15 ) ;
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
if ( V_12 )
{
V_16 = ( T_7 ) F_10 ( V_12 ,
L_8 ) ;
V_17 = ( T_8 ) F_10 ( V_12 ,
L_9 ) ;
V_18 = ( T_9 ) F_10 ( V_12 ,
L_10 ) ;
}
if ( V_16 && V_17 && V_18 )
{
if ( V_16 ( & V_2 , NULL , NULL , V_10 ,
V_11 ) )
{
if ( V_17 ( V_2 , sizeof( V_9 ) , V_9 ) != 0 )
{
F_6 ( V_9 , sizeof( V_9 ) , 0 ) ;
V_4 = 1 ;
#if 0
printf("randomness from PROV_RSA_FULL\n");
#endif
}
V_18 ( V_2 , 0 ) ;
}
if ( V_16 ( & V_2 , 0 , V_24 , V_25 , 0 ) )
{
if ( V_17 ( V_2 , sizeof( V_9 ) , V_9 ) != 0 )
{
F_6 ( V_9 , sizeof( V_9 ) , sizeof( V_9 ) ) ;
V_4 = 1 ;
#if 0
printf("randomness from PROV_INTEL_SEC\n");
#endif
}
V_18 ( V_2 , 0 ) ;
}
}
if ( V_12 )
F_11 ( V_12 ) ;
if ( ( V_5 . V_26 != V_27 ||
! F_12 () ) &&
( V_14 = F_8 ( F_9 ( L_11 ) ) ) )
{
T_13 V_28 ;
T_14 V_29 ;
T_15 V_30 ;
V_29 = ( T_14 ) F_10 ( V_14 , L_12 ) ;
V_28 = ( T_13 ) F_10 ( V_14 , L_13 ) ;
V_30 = ( T_15 ) F_10 ( V_14 , L_14 ) ;
if ( V_29 )
{
T_16 V_31 = V_29 () ;
F_6 ( & V_31 , sizeof( V_31 ) , 0 ) ;
}
if ( V_28 )
{
if ( V_5 . V_26 == V_27 &&
V_5 . V_32 < 5 )
V_28 = 0 ;
}
if ( V_28 )
{
T_17 V_33 ;
V_33 . V_34 = sizeof( T_17 ) ;
if ( V_28 ( & V_33 ) )
F_6 ( & V_33 , V_33 . V_34 , 2 ) ;
}
if ( V_30 )
{
V_3 = V_30 ( V_35 ) ;
F_6 ( & V_3 , sizeof( V_3 ) , 1 ) ;
}
F_11 ( V_14 ) ;
}
if ( V_13 )
{
T_18 V_36 ;
T_19 V_37 ;
T_20 V_38 ;
T_21 V_39 ;
T_22 V_40 ;
T_23 V_41 , V_42 ;
T_24 V_43 , V_44 ;
T_25 V_45 , V_46 ;
T_26 V_47 , V_48 ;
T_27 V_49 ;
T_28 V_50 ;
T_29 V_51 ;
T_30 V_52 ;
T_31 V_1 ;
T_3 V_53 = 0 ;
V_36 = ( T_18 )
F_10 ( V_13 , L_15 ) ;
V_37 = ( T_19 )
F_10 ( V_13 , L_16 ) ;
V_39 = ( T_21 ) F_10 ( V_13 , L_17 ) ;
V_40 = ( T_22 ) F_10 ( V_13 , L_18 ) ;
V_41 = ( T_23 ) F_10 ( V_13 , L_19 ) ;
V_42 = ( T_23 ) F_10 ( V_13 , L_20 ) ;
V_43 = ( T_24 ) F_10 ( V_13 , L_21 ) ;
V_44 = ( T_24 ) F_10 ( V_13 , L_22 ) ;
V_45 = ( T_25 ) F_10 ( V_13 , L_23 ) ;
V_46 = ( T_25 ) F_10 ( V_13 , L_24 ) ;
V_47 = ( T_26 ) F_10 ( V_13 , L_25 ) ;
V_48 = ( T_26 ) F_10 ( V_13 , L_26 ) ;
if ( V_36 && V_39 && V_40 && V_41 &&
V_42 && V_43 && V_44 &&
V_45 && V_46 && V_47 &&
V_48 && ( V_38 = V_36 ( V_54 , 0 ) )
!= V_55 )
{
F_13 ( & V_49 , sizeof( T_27 ) ) ;
V_49 . V_56 = sizeof( T_27 ) ;
if ( V_4 ) V_53 = F_14 () ;
#ifdef F_15
if ( V_41 ( V_38 , & V_49 ) )
{
int V_57 = 42 ;
do
{
F_6 ( & V_49 , V_49 . V_56 , 3 ) ;
F_16
{
F_13 ( & V_50 , sizeof( T_28 ) ) ;
V_50 . V_56 = sizeof( T_28 ) ;
if ( V_39 ( & V_50 ,
V_49 . V_58 ,
V_49 . V_59 ) )
{
int V_60 = 80 ;
do
F_6 ( & V_50 ,
V_50 . V_56 , 5 ) ;
while ( V_40 ( & V_50 )
&& ( ! V_4 || ( F_14 () - V_53 ) < V_61 )
&& -- V_60 > 0 );
}
}
F_17 (EXCEPTION_EXECUTE_HANDLER)
{
V_57 -- ;
}
} while ( V_42 ( V_38 , & V_49 )
&& ( ! V_4 || ( F_14 () - V_53 ) < V_61 )
&& V_57 > 0 );
}
#else
if ( V_41 ( V_38 , & V_49 ) )
{
do
{
F_6 ( & V_49 , V_49 . V_56 , 3 ) ;
V_50 . V_56 = sizeof( T_28 ) ;
if ( V_39 ( & V_50 ,
V_49 . V_58 ,
V_49 . V_59 ) )
{
int V_60 = 80 ;
do
F_6 ( & V_50 ,
V_50 . V_56 , 5 ) ;
while ( V_40 ( & V_50 )
&& -- V_60 > 0 );
}
} while ( V_42 ( V_38 , & V_49 )
&& ( ! V_4 || ( F_14 () - V_53 ) < V_61 ) );
}
#endif
V_51 . V_56 = sizeof( T_29 ) ;
if ( V_4 ) V_53 = F_14 () ;
if ( V_43 ( V_38 , & V_51 ) )
do
F_6 ( & V_51 , V_51 . V_56 , 9 ) ;
while ( V_44 ( V_38 , & V_51 ) && ( ! V_4 || ( F_14 () - V_53 ) < V_61 ) );
V_52 . V_56 = sizeof( T_30 ) ;
if ( V_4 ) V_53 = F_14 () ;
if ( V_45 ( V_38 , & V_52 ) )
do
F_6 ( & V_52 , V_52 . V_56 , 6 ) ;
while ( V_46 ( V_38 , & V_52 ) && ( ! V_4 || ( F_14 () - V_53 ) < V_61 ) );
V_1 . V_56 = sizeof( T_31 ) ;
if ( V_4 ) V_53 = F_14 () ;
if ( V_47 ( V_38 , & V_1 ) )
do
F_6 ( & V_1 , V_1 . V_56 , 9 ) ;
while ( V_48 ( V_38 , & V_1 )
&& ( ! V_4 || ( F_14 () - V_53 ) < V_61 ) );
if ( V_37 )
V_37 ( V_38 ) ;
else
F_18 ( V_38 ) ;
}
F_11 ( V_13 ) ;
}
}
#endif
F_19 () ;
F_20 ( & V_1 ) ;
F_6 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_3 = F_21 () ;
F_6 ( & V_3 , sizeof( V_3 ) , 1 ) ;
#if 0
printf("Exiting RAND_poll\n");
#endif
return ( 1 ) ;
}
int F_22 ( T_32 V_62 , T_33 V_63 , T_34 V_64 )
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
V_73 = F_23 ( V_64 ) ;
V_74 = F_24 ( V_64 ) ;
V_75 = V_69 - V_73 ;
V_76 = V_70 - V_74 ;
if ( V_75 != 0 && V_76 != 0 && V_75 - V_71 != 0 && V_76 - V_72 != 0 )
V_65 = .2 ;
V_69 = V_73 , V_70 = V_74 ;
V_71 = V_75 , V_72 = V_76 ;
}
break;
}
F_19 () ;
F_6 ( & V_62 , sizeof( V_62 ) , V_65 ) ;
F_6 ( & V_63 , sizeof( V_63 ) , 0 ) ;
F_6 ( & V_64 , sizeof( V_64 ) , 0 ) ;
return ( F_25 () ) ;
}
void F_26 ( void )
{
F_1 () ;
F_27 () ;
}
static void F_19 ( void )
{
T_3 V_3 ;
T_35 V_77 ;
static int V_78 = 1 ;
#if F_3 ( F_15 ) && F_3 ( V_79 )
static int V_80 = 1 ;
T_3 V_81 ;
if ( V_80 ) {
F_16 {
__asm {
_emit 0x0f
_emit 0x31
mov cyclecount, eax
}
F_6 ( & V_81 , sizeof( V_81 ) , 1 ) ;
} F_17 (EXCEPTION_EXECUTE_HANDLER) {
V_80 = 0 ;
}
}
#else
# define V_80 0
#endif
if ( V_78 ) {
if ( F_28 ( & V_77 ) == 0 )
V_78 = 0 ;
else
F_6 ( & V_77 , sizeof( V_77 ) , 0 ) ;
}
if ( ! V_80 && ! V_78 ) {
V_3 = F_14 () ;
F_6 ( & V_3 , sizeof( V_3 ) , 0 ) ;
}
}
static void F_27 ( void )
{
#if ! F_3 ( V_7 ) && ! F_3 ( V_82 )
T_36 V_83 ;
T_36 V_84 ;
T_37 V_85 ;
T_37 V_86 ;
T_38 V_87 ;
unsigned int V_88 ;
char * V_89 ;
int V_3 ;
int V_31 ;
int V_74 ;
int V_90 = 16 ;
if ( F_29 () < 0x80000000 && F_12 () > 0 )
return;
V_83 = F_30 ( F_9 ( L_27 ) , NULL , NULL , NULL ) ;
V_84 = F_31 ( V_83 ) ;
V_3 = F_32 ( V_83 , V_91 ) ;
V_31 = F_32 ( V_83 , V_92 ) ;
V_85 = F_33 ( V_83 , V_3 , V_90 ) ;
V_86 = F_34 ( V_84 , V_85 ) ;
F_35 ( V_85 , sizeof( T_38 ) , ( V_93 ) & V_87 ) ;
V_88 = ( unsigned int ) V_87 . V_94 * V_87 . V_95 * V_87 . V_96 ;
V_89 = F_36 ( V_88 ) ;
if ( V_89 ) {
for ( V_74 = 0 ; V_74 < V_31 - V_90 ; V_74 += V_90 )
{
unsigned char V_97 [ V_98 ] ;
F_37 ( V_84 , 0 , 0 , V_3 , V_90 , V_83 , 0 , V_74 , V_99 ) ;
F_38 ( V_85 , V_88 , V_89 ) ;
F_39 ( V_89 , V_88 , V_97 ) ;
F_6 ( V_97 , V_98 , 0 ) ;
}
F_40 ( V_89 ) ;
}
V_85 = F_34 ( V_84 , V_86 ) ;
F_41 ( V_85 ) ;
F_42 ( V_84 ) ;
F_42 ( V_83 ) ;
#endif
}
