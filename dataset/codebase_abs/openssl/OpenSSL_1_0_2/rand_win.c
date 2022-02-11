int F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 = 0 ;
T_3 V_3 ;
int V_4 = 0 ;
# if F_2 ( V_5 )
# if F_2 ( V_6 ) && V_6 >= 300
{
T_4 V_7 [ 64 ] ;
if ( F_3 ( & V_2 , NULL , NULL , V_8 ,
V_9 ) ) {
if ( F_4 ( V_2 , sizeof( V_7 ) , V_7 ) )
F_5 ( V_7 , sizeof( V_7 ) , sizeof( V_7 ) ) ;
F_6 ( V_2 , 0 ) ;
}
}
# endif
# else
{
T_5 V_10 = F_7 ( F_8 ( L_1 ) ) ;
T_5 V_11 = F_7 ( F_8 ( L_2 ) ) ;
T_5 V_12 = NULL ;
T_5 V_13 = F_7 ( F_8 ( L_3 ) ) ;
T_6 V_14 = NULL ;
T_7 V_15 = NULL ;
T_8 V_16 = NULL ;
T_9 V_17 = NULL ;
T_10 V_18 = NULL ;
T_4 V_7 [ 64 ] ;
if ( V_13 ) {
V_17 =
( T_9 ) F_9 ( V_13 , L_4 ) ;
V_18 = ( T_10 ) F_9 ( V_13 , L_5 ) ;
}
if ( V_17 && V_18 ) {
T_11 V_19 ;
if ( V_17 ( NULL , L_6 , 0 , 0 , & V_19 ) == 0 ) {
F_5 ( V_19 , sizeof( V_20 ) , 45 ) ;
V_18 ( V_19 ) ;
}
if ( V_17 ( NULL , L_7 , 0 , 0 , & V_19 ) == 0 ) {
F_5 ( V_19 , sizeof( V_21 ) , 17 ) ;
V_18 ( V_19 ) ;
}
}
if ( V_13 )
F_10 ( V_13 ) ;
if ( V_10 ) {
V_14 = ( T_6 ) F_9 ( V_10 ,
L_8 ) ;
V_15 = ( T_7 ) F_9 ( V_10 , L_9 ) ;
V_16 = ( T_8 ) F_9 ( V_10 ,
L_10 ) ;
}
if ( V_14 && V_15 && V_16 ) {
if ( V_14 ( & V_2 , NULL , NULL , V_8 ,
V_9 ) ) {
if ( V_15 ( V_2 , sizeof( V_7 ) , V_7 ) != 0 ) {
F_5 ( V_7 , sizeof( V_7 ) , 0 ) ;
V_4 = 1 ;
# if 0
printf("randomness from PROV_RSA_FULL\n");
# endif
}
V_16 ( V_2 , 0 ) ;
}
if ( V_14 ( & V_2 , 0 , V_22 , V_23 , 0 ) ) {
if ( V_15 ( V_2 , sizeof( V_7 ) , V_7 ) != 0 ) {
F_5 ( V_7 , sizeof( V_7 ) , sizeof( V_7 ) ) ;
V_4 = 1 ;
# if 0
printf("randomness from PROV_INTEL_SEC\n");
# endif
}
V_16 ( V_2 , 0 ) ;
}
}
if ( V_10 )
F_10 ( V_10 ) ;
if ( ( ! F_11 () ||
! F_12 () ) &&
( V_12 = F_7 ( F_8 ( L_11 ) ) ) ) {
T_12 V_24 ;
T_13 V_25 ;
T_14 V_26 ;
V_25 =
( T_13 ) F_9 ( V_12 ,
L_12 ) ;
V_24 = ( T_12 ) F_9 ( V_12 , L_13 ) ;
V_26 = ( T_14 ) F_9 ( V_12 , L_14 ) ;
if ( V_25 ) {
T_15 V_27 = V_25 () ;
F_5 ( & V_27 , sizeof( V_27 ) , 0 ) ;
}
if ( V_24 ) {
if ( F_11 () && ! F_13 ( 5 ) )
V_24 = 0 ;
}
if ( V_24 ) {
T_16 V_28 ;
V_28 . V_29 = sizeof( T_16 ) ;
if ( V_24 ( & V_28 ) )
F_5 ( & V_28 , V_28 . V_29 , 2 ) ;
}
if ( V_26 ) {
V_3 = V_26 ( V_30 ) ;
F_5 ( & V_3 , sizeof( V_3 ) , 1 ) ;
}
F_10 ( V_12 ) ;
}
if ( V_11 ) {
T_17 V_31 ;
T_18 V_32 ;
T_19 V_33 ;
T_20 V_34 ;
T_21 V_35 ;
T_22 V_36 , V_37 ;
T_23 V_38 , V_39 ;
T_24 V_40 , V_41 ;
T_25 V_42 , V_43 ;
T_26 V_44 ;
T_27 V_45 ;
T_28 V_46 ;
T_29 V_47 ;
T_30 V_1 ;
T_3 V_48 = 0 ;
V_31 = ( T_17 )
F_9 ( V_11 , L_15 ) ;
V_32 = ( T_18 )
F_9 ( V_11 , L_16 ) ;
V_34 = ( T_20 ) F_9 ( V_11 , L_17 ) ;
V_35 = ( T_21 ) F_9 ( V_11 , L_18 ) ;
V_36 =
( T_22 ) F_9 ( V_11 , L_19 ) ;
V_37 =
( T_22 ) F_9 ( V_11 , L_20 ) ;
V_38 =
( T_23 ) F_9 ( V_11 , L_21 ) ;
V_39 =
( T_23 ) F_9 ( V_11 , L_22 ) ;
V_40 = ( T_24 ) F_9 ( V_11 , L_23 ) ;
V_41 = ( T_24 ) F_9 ( V_11 , L_24 ) ;
V_42 = ( T_25 ) F_9 ( V_11 , L_25 ) ;
V_43 = ( T_25 ) F_9 ( V_11 , L_26 ) ;
if ( V_31 && V_34 && V_35 && V_36 &&
V_37 && V_38 && V_39 &&
V_40 && V_41 && V_42 &&
V_43 && ( V_33 = V_31 ( V_49 , 0 ) )
!= V_50 ) {
F_14 ( & V_44 , sizeof( T_26 ) ) ;
V_44 . V_51 = sizeof( T_26 ) ;
if ( V_4 )
V_48 = F_15 () ;
# ifdef F_16
if ( V_36 ( V_33 , & V_44 ) ) {
int V_52 = 42 ;
do {
F_5 ( & V_44 , V_44 . V_51 , 3 ) ;
F_17 {
F_14 ( & V_45 , sizeof( T_27 ) ) ;
V_45 . V_51 = sizeof( T_27 ) ;
if ( V_34 ( & V_45 ,
V_44 . V_53 ,
V_44 . V_54 ) ) {
int V_55 = 80 ;
do
F_5 ( & V_45 , V_45 . V_51 , 5 ) ;
while ( V_35 ( & V_45 )
&& ( ! V_4
|| ( F_15 () - V_48 ) <
V_56 )
&& -- V_55 > 0 );
}
}
F_18 (EXCEPTION_EXECUTE_HANDLER) {
V_52 -- ;
}
} while ( V_37 ( V_33 , & V_44 )
&& ( ! V_4
|| ( F_15 () - V_48 ) < V_56 )
&& V_52 > 0 );
}
# else
if ( V_36 ( V_33 , & V_44 ) ) {
do {
F_5 ( & V_44 , V_44 . V_51 , 3 ) ;
V_45 . V_51 = sizeof( T_27 ) ;
if ( V_34 ( & V_45 ,
V_44 . V_53 ,
V_44 . V_54 ) ) {
int V_55 = 80 ;
do
F_5 ( & V_45 , V_45 . V_51 , 5 ) ;
while ( V_35 ( & V_45 )
&& -- V_55 > 0 );
}
} while ( V_37 ( V_33 , & V_44 )
&& ( ! V_4
|| ( F_15 () - V_48 ) < V_56 ) );
}
# endif
V_46 . V_51 = sizeof( T_28 ) ;
if ( V_4 )
V_48 = F_15 () ;
if ( V_38 ( V_33 , & V_46 ) )
do
F_5 ( & V_46 , V_46 . V_51 , 9 ) ;
while ( V_39 ( V_33 , & V_46 )
&& ( ! V_4
|| ( F_15 () - V_48 ) < V_56 ) );
V_47 . V_51 = sizeof( T_29 ) ;
if ( V_4 )
V_48 = F_15 () ;
if ( V_40 ( V_33 , & V_47 ) )
do
F_5 ( & V_47 , V_47 . V_51 , 6 ) ;
while ( V_41 ( V_33 , & V_47 )
&& ( ! V_4
|| ( F_15 () - V_48 ) < V_56 ) );
V_1 . V_51 = sizeof( T_30 ) ;
if ( V_4 )
V_48 = F_15 () ;
if ( V_42 ( V_33 , & V_1 ) )
do
F_5 ( & V_1 , V_1 . V_51 , 9 ) ;
while ( V_43 ( V_33 , & V_1 )
&& ( ! V_4
|| ( F_15 () - V_48 ) < V_56 ) );
if ( V_32 )
V_32 ( V_33 ) ;
else
F_19 ( V_33 ) ;
}
F_10 ( V_11 ) ;
}
}
# endif
F_20 () ;
F_21 ( & V_1 ) ;
F_5 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_3 = F_22 () ;
F_5 ( & V_3 , sizeof( V_3 ) , 1 ) ;
# if 0
printf("Exiting RAND_poll\n");
# endif
return ( 1 ) ;
}
int F_23 ( T_31 V_57 , T_32 V_58 , T_33 V_59 )
{
double V_60 = 0 ;
switch ( V_57 ) {
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
V_68 = F_24 ( V_59 ) ;
V_69 = F_25 ( V_59 ) ;
V_70 = V_64 - V_68 ;
V_71 = V_65 - V_69 ;
if ( V_70 != 0 && V_71 != 0 && V_70 - V_66 != 0 && V_71 - V_67 != 0 )
V_60 = .2 ;
V_64 = V_68 , V_65 = V_69 ;
V_66 = V_70 , V_67 = V_71 ;
}
break;
}
F_20 () ;
F_5 ( & V_57 , sizeof( V_57 ) , V_60 ) ;
F_5 ( & V_58 , sizeof( V_58 ) , 0 ) ;
F_5 ( & V_59 , sizeof( V_59 ) , 0 ) ;
return ( F_26 () ) ;
}
void F_27 ( void )
{
F_1 () ;
F_28 () ;
}
static void F_20 ( void )
{
T_3 V_3 ;
T_34 V_72 ;
static int V_73 = 1 ;
# if F_2 ( F_16 ) && F_2 ( V_74 )
static int V_75 = 1 ;
T_3 V_76 ;
if ( V_75 ) {
F_17 {
__asm {
_emit 0x0f _emit 0x31 mov cyclecount, eax}
F_5 ( & V_76 , sizeof( V_76 ) , 1 ) ;
}
F_18 (EXCEPTION_EXECUTE_HANDLER) {
V_75 = 0 ;
}
}
# else
# define V_75 0
# endif
if ( V_73 ) {
if ( F_29 ( & V_72 ) == 0 )
V_73 = 0 ;
else
F_5 ( & V_72 , sizeof( V_72 ) , 0 ) ;
}
if ( ! V_75 && ! V_73 ) {
V_3 = F_15 () ;
F_5 ( & V_3 , sizeof( V_3 ) , 0 ) ;
}
}
static void F_28 ( void )
{
# if ! F_2 ( V_5 ) && ! F_2 ( V_77 )
T_35 V_78 ;
T_36 V_79 ;
T_37 V_80 ;
unsigned int V_81 ;
char * V_82 ;
int V_3 ;
int V_27 ;
int V_69 ;
int V_83 = 16 ;
T_38 V_84 ;
if ( F_11 () && F_12 () > 0 )
return;
V_78 = F_30 ( NULL ) ;
V_3 = F_31 ( V_78 , V_85 ) ;
V_27 = F_31 ( V_78 , V_86 ) ;
V_79 = F_32 ( V_78 , V_3 , V_83 ) ;
F_33 ( V_79 , sizeof( T_37 ) , ( V_87 ) & V_80 ) ;
V_81 = ( unsigned int ) V_80 . V_88 * V_80 . V_89 * V_80 . V_90 ;
V_84 . V_91 = sizeof( T_38 ) ;
V_84 . V_92 = V_80 . V_93 ;
V_84 . V_94 = V_80 . V_89 ;
V_84 . V_95 = V_80 . V_90 ;
V_84 . V_96 = V_80 . V_97 ;
V_84 . V_98 = V_99 ;
V_84 . V_100 = 0 ;
V_84 . V_101 = 0 ;
V_84 . V_102 = 0 ;
V_84 . V_103 = 0 ;
V_84 . V_104 = 0 ;
V_82 = F_34 ( V_81 ) ;
if ( V_82 ) {
for ( V_69 = 0 ; V_69 < V_27 - V_83 ; V_69 += V_83 ) {
unsigned char V_105 [ V_106 ] ;
F_35 ( V_78 , V_79 , V_69 , V_83 ,
V_82 , ( V_107 * ) & V_84 , V_108 ) ;
F_36 ( V_82 , V_81 , V_105 ) ;
F_5 ( V_105 , V_106 , 0 ) ;
}
F_37 ( V_82 ) ;
}
F_38 ( V_79 ) ;
F_39 ( NULL , V_78 ) ;
# endif
}
