static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
#ifndef F_3
const T_3 * V_3 ;
#endif
#ifndef F_4
const T_4 * V_4 ;
#endif
if( ! F_5 ( V_1 , V_5 ) ||
! F_6 ( V_1 , V_6 ) ||
#ifndef F_2
! F_7 ( V_1 , & V_7 ) ||
#endif
#ifndef F_3
! F_8 ( V_1 , & V_8 ) ||
#endif
#ifndef F_4
! F_9 ( V_1 , & V_9 ) ||
#endif
! F_10 ( V_1 , & V_10 ) ||
! F_11 ( V_1 , V_11 ) ||
! F_12 ( V_1 , V_12 ) ||
! F_13 ( V_1 , V_13 ) ||
! F_14 ( V_1 , V_14 ) ||
! F_15 ( V_1 , V_15 ) )
return 0 ;
#ifndef F_2
V_2 = F_16 () ;
V_7 . V_16 = V_2 -> V_16 ;
V_7 . V_17 = V_2 -> V_17 ;
V_7 . V_18 = V_2 -> V_18 ;
V_7 . V_19 = V_2 -> V_19 ;
#endif
#ifndef F_3
V_3 = F_17 () ;
V_8 . V_20 = V_3 -> V_20 ;
V_8 . V_21 = V_3 -> V_21 ;
V_8 . V_22 = V_3 -> V_22 ;
#endif
#ifndef F_4
V_4 = F_18 () ;
V_9 . V_23 = V_4 -> V_23 ;
V_9 . V_24 = V_4 -> V_24 ;
#endif
F_19 () ;
return 1 ;
}
static T_1 * F_20 ( void )
{
T_1 * V_25 = F_21 () ;
if( ! V_25 )
return NULL ;
if( ! F_1 ( V_25 ) )
{
F_22 ( V_25 ) ;
return NULL ;
}
return V_25 ;
}
static
#endif
void F_23 ( void )
{
T_1 * V_26 = F_20 () ;
if( ! V_26 ) return;
F_24 ( V_26 ) ;
F_22 ( V_26 ) ;
F_25 () ;
}
static int V_11 ( T_1 * V_1 )
{
F_26 () ;
return 1 ;
}
static int F_27 ( T_5 * V_27 )
{
unsigned int V_28 = 0 ;
V_28 = F_28 ( 0 , V_27 ) ;
if( V_28 != 0 )
return 0 ;
return 1 ;
}
static void F_29 ( T_5 V_29 )
{
F_30 ( V_29 ) ;
}
static int V_12 ( T_1 * V_1 )
{
void (* F_31)();
void (* F_32)();
void (* F_33)();
void (* F_34)();
void (* F_35)();
if( V_30 != NULL )
{
F_36 ( V_31 , V_32 ) ;
goto V_33;
}
V_30 = F_37 ( NULL , V_34 , NULL ,
0 ) ;
if( V_30 == NULL )
{
F_36 ( V_31 , V_35 ) ;
goto V_33;
}
if( ! ( F_31 = F_38 (
V_30 , V_36 ) ) ||
! ( F_32 = F_38 (
V_30 , V_37 ) ) ||
! ( F_33 = F_38 (
V_30 , V_38 ) ) ||
! ( F_34 = F_38 (
V_30 , V_39 ) ) ||
! ( F_35 = F_38 (
V_30 , V_40 ) ) )
{
F_36 ( V_31 , V_35 ) ;
goto V_33;
}
F_28 = ( unsigned int ( V_41 * ) () ) F_31 ;
F_30 = ( unsigned int ( V_41 * ) () ) F_32 ;
V_42 = ( unsigned int ( V_41 * ) () ) F_33 ;
V_43 = ( unsigned int ( V_41 * ) () ) F_34 ;
V_44 = ( unsigned int ( V_41 * ) () ) F_35 ;
if( ! F_27 ( & V_29 ) )
{
F_36 ( V_31 , V_45 ) ;
goto V_33;
}
return 1 ;
V_33:
if( V_30 )
F_39 ( V_30 ) ;
F_28 = NULL ;
F_30 = NULL ;
V_42 = NULL ;
V_43 = NULL ;
return 0 ;
}
static int V_13 ( T_1 * V_1 )
{
if( V_30 == NULL )
{
F_36 ( V_46 , V_47 ) ;
return 0 ;
}
F_29 ( V_29 ) ;
if( ! F_39 ( V_30 ) )
{
F_36 ( V_46 , V_35 ) ;
return 0 ;
}
V_30 = NULL ;
return 1 ;
}
static int V_14 ( T_1 * V_1 , int V_48 , long V_49 , void * V_50 , void (* F_40)() )
{
int V_51 = ( ( V_30 == NULL ) ? 0 : 1 ) ;
switch( V_48 )
{
case V_52 :
if( V_50 == NULL )
{
F_36 ( V_53 , V_54 ) ;
return 0 ;
}
if( V_51 )
{
F_36 ( V_53 , V_32 ) ;
return 0 ;
}
V_34 = ( const char * ) V_50 ;
return 1 ;
default:
break;
}
F_36 ( V_53 , V_55 ) ;
return 0 ;
}
static int F_41 ( T_6 * V_56 , const T_6 * V_57 , const T_6 * V_50 ,
const T_6 * V_58 , T_7 * V_59 )
{
T_6 * V_60 = NULL ;
T_6 * V_61 = NULL ;
T_6 * V_62 = NULL ;
int V_63 ;
int V_64 , V_65 , V_66 ;
T_8 * V_67 = NULL ;
unsigned int V_68 ;
V_63 = 0 ;
if( ! V_30 )
{
F_36 ( V_69 , V_47 ) ;
goto V_33;
}
F_42 ( V_59 ) ;
V_60 = F_43 ( V_59 ) ;
V_61 = F_43 ( V_59 ) ;
V_62 = F_43 ( V_59 ) ;
if( ! V_60 || ! V_61 || ! V_62 )
{
F_36 ( V_69 , V_70 ) ;
goto V_33;
}
if( ! F_44 ( V_60 , V_58 -> V_71 ) || ! F_44 ( V_61 , V_58 -> V_71 ) ||
! F_44 ( V_62 , sizeof( * V_67 ) / V_72 ) )
{
F_36 ( V_69 , V_73 ) ;
goto V_33;
}
V_67 = ( T_8 * ) V_62 -> V_74 ;
if ( V_67 == NULL )
{
goto V_33;
}
memset ( V_67 , 0 , sizeof( T_8 ) ) ;
V_67 -> V_75 = F_45 ( V_76 ) ;
V_67 -> V_77 = F_45 ( sizeof( T_8 ) ) ;
V_67 -> V_78 = ( char * ) V_67 -> V_79 - ( char * ) V_67 ;
V_65 = F_46 ( V_58 ) ;
if ( V_65 > 256 ) {
F_36 ( V_69 , V_80 ) ;
goto V_33;
}
V_67 -> V_81 = V_67 -> V_82 = V_65 ;
if ( V_65 < F_46 ( V_50 ) ) {
F_36 ( V_69 , V_83 ) ;
goto V_33;
}
F_47 ( V_50 , & V_67 -> V_79 [ V_67 -> V_81 -
F_46 ( V_50 ) ] ) ;
F_47 ( V_58 , & V_67 -> V_79 [ V_67 -> V_81 ] ) ;
V_67 -> V_84 = F_45 ( V_67 -> V_82 * 8 ) ;
V_67 -> V_85 = F_45 ( V_67 -> V_78 +
V_67 -> V_81 ) ;
V_67 -> V_78 = F_45 ( ( char * ) V_67 -> V_79 -
( char * ) V_67 ) ;
V_66 = V_65 ;
V_67 -> V_81 = V_67 -> V_82 = F_45 ( V_66 ) ;
memset ( V_60 -> V_74 , 0 , V_65 ) ;
F_47 ( V_57 , ( unsigned char * ) V_60 -> V_74 + V_65 -
F_46 ( V_57 ) ) ;
V_64 = V_65 ;
if( ( V_68 = V_42 ( V_29 , V_64 , ( unsigned char * ) V_60 -> V_74 ,
V_67 , & V_65 , ( unsigned char * ) V_61 -> V_74 ) )
!= 0 )
{
printf ( L_1 , V_68 ) ;
F_36 ( V_69 , V_86 ) ;
goto V_33;
}
F_48 ( ( unsigned char * ) V_61 -> V_74 , V_65 , V_56 ) ;
V_63 = 1 ;
V_33:
F_49 ( V_59 ) ;
return V_63 ;
}
static int F_50 ( T_6 * V_87 , const T_6 * V_88 , T_9 * V_89 )
{
T_7 * V_59 ;
int V_63 = 0 ;
if( ( V_59 = F_51 () ) == NULL )
goto V_33;
if( ! V_89 -> V_50 || ! V_89 -> V_90 || ! V_89 -> V_91 || ! V_89 -> V_92 || ! V_89 -> V_93 )
{
if( ! V_89 -> V_74 || ! V_89 -> V_94 )
{
F_36 ( V_95 ,
V_96 ) ;
goto V_33;
}
V_63 = F_41 ( V_87 , V_88 , V_89 -> V_74 , V_89 -> V_94 , V_59 ) ;
}
else
{
V_63 = F_52 ( V_87 , V_88 , V_89 -> V_50 , V_89 -> V_90 , V_89 -> V_91 ,
V_89 -> V_92 , V_89 -> V_93 , V_59 ) ;
}
V_33:
if( V_59 )
F_53 ( V_59 ) ;
return V_63 ;
}
static int F_52 ( T_6 * V_56 , const T_6 * V_57 , const T_6 * V_50 ,
const T_6 * V_90 , const T_6 * V_91 ,
const T_6 * V_92 , const T_6 * V_93 , T_7 * V_59 )
{
T_6 * V_60 = NULL ;
T_6 * V_61 = NULL ;
T_6 * V_62 = NULL ;
int V_63 = 0 ;
char * V_97 = NULL ;
T_10 * V_98 = NULL ;
int V_64 , V_65 ;
int V_68 ;
unsigned int V_99 , V_100 , V_101 ;
unsigned int V_102 ;
unsigned int V_103 = F_46 ( V_50 ) ;
unsigned int V_104 = F_46 ( V_90 ) ;
unsigned int V_105 = F_46 ( V_91 ) ;
unsigned int V_106 = F_46 ( V_92 ) ;
unsigned int V_107 = F_46 ( V_93 ) ;
F_42 ( V_59 ) ;
V_60 = F_43 ( V_59 ) ;
V_61 = F_43 ( V_59 ) ;
V_62 = F_43 ( V_59 ) ;
if( ! V_60 || ! V_61 || ! V_62 )
{
F_36 ( V_108 , V_70 ) ;
goto V_33;
}
if( ! F_44 ( V_60 , V_50 -> V_71 + V_90 -> V_71 ) ||
! F_44 ( V_61 , V_50 -> V_71 + V_90 -> V_71 ) ||
! F_44 ( V_62 , sizeof( * V_98 ) / V_72 ) )
{
F_36 ( V_108 , V_73 ) ;
goto V_33;
}
V_98 = ( T_10 * ) V_62 -> V_74 ;
V_102 = V_103 + V_104 + V_105 + V_106 + V_107 ;
if ( V_102 > sizeof( V_98 -> V_79 ) ) {
F_36 ( V_108 , V_109 ) ;
goto V_33;
}
if ( ( V_104 + V_106 ) > 256 ) {
F_36 ( V_108 , V_109 ) ;
goto V_33;
}
if ( V_103 + V_105 > 256 ) {
F_36 ( V_108 , V_109 ) ;
goto V_33;
}
memset ( V_98 , 0 , sizeof( T_10 ) ) ;
V_98 -> V_75 = F_45 ( V_110 ) ;
V_98 -> V_77 = F_45 ( sizeof( T_10 ) ) ;
V_98 -> V_84 =
F_45 ( F_46 ( V_90 ) * 2 * 8 ) ;
V_98 -> V_111 = F_45 ( F_46 ( V_50 ) + 8 ) ;
V_98 -> V_112 = F_45 ( F_46 ( V_90 ) ) ;
V_98 -> V_113 = F_45 ( F_46 ( V_91 ) + 8 ) ;
V_98 -> V_114 = F_45 ( F_46 ( V_92 ) ) ;
V_98 -> V_115 = F_45 ( F_46 ( V_93 ) + 8 ) ;
V_99 = ( char * ) V_98 -> V_79
- ( char * ) V_98 ;
V_101 = F_46 ( V_90 ) ;
V_100 = V_101 + 8 ;
if ( ( V_103 > V_100 ) || ( V_105 > V_100 ) ||
( V_107 > V_100 ) || ( V_104 > V_101 ) ||
( V_106 > V_101 ) ) {
F_36 ( V_108 , V_109 ) ;
goto V_33;
}
V_98 -> V_116 = F_45 ( V_99 ) ;
V_99 += V_100 ;
V_98 -> V_117 = F_45 ( V_99 ) ;
V_99 += V_101 ;
V_98 -> V_118 = F_45 ( V_99 ) ;
V_99 += V_100 ;
V_98 -> V_119 = F_45 ( V_99 ) ;
V_99 += V_101 ;
V_98 -> V_120 = F_45 ( V_99 ) ;
V_97 = ( char * ) V_98 -> V_79 ;
if ( V_100 < V_103 ) {
F_36 ( V_108 , V_121 ) ;
goto V_33;
}
V_97 += V_100 - F_46 ( V_91 ) ;
F_47 ( V_91 , V_97 ) ;
V_97 += F_46 ( V_91 ) ;
F_47 ( V_92 , V_97 ) ;
V_97 += V_101 ;
V_97 += V_100 - F_46 ( V_50 ) ;
F_47 ( V_50 , V_97 ) ;
V_97 += F_46 ( V_50 ) ;
F_47 ( V_90 , V_97 ) ;
V_97 += V_101 ;
V_97 += V_100 - F_46 ( V_93 ) ;
F_47 ( V_93 , V_97 ) ;
V_65 = F_45 ( V_98 -> V_112 ) * 2 ;
if ( V_65 > 256 ) {
F_36 ( V_108 , V_122 ) ;
goto V_33;
}
if ( V_65 < F_46 ( V_57 ) ) {
F_36 ( V_108 , V_121 ) ;
goto V_33;
}
F_47 ( V_57 , ( unsigned char * ) V_60 -> V_74 + V_65 -
F_46 ( V_57 ) ) ;
V_64 = V_65 ;
memset ( V_61 -> V_74 , 0 , V_65 ) ;
if ( ( V_68 = V_44 ( V_29 , V_64 , ( unsigned char * ) V_60 -> V_74 ,
V_98 , & V_65 , ( unsigned char * ) V_61 -> V_74 ) ) != 0 )
{
printf ( L_1 , V_68 ) ;
F_36 ( V_108 , V_86 ) ;
goto V_33;
}
F_48 ( ( unsigned char * ) V_61 -> V_74 , V_65 , V_56 ) ;
V_63 = 1 ;
V_33:
F_49 ( V_59 ) ;
return V_63 ;
}
static int F_54 ( T_11 * V_123 , T_6 * V_124 , T_6 * V_125 ,
T_6 * F_31 , T_6 * V_126 , T_6 * F_32 , T_6 * V_58 ,
T_7 * V_59 , T_12 * V_127 )
{
T_6 V_128 ;
int V_63 = 0 ;
F_55 ( & V_128 ) ;
if ( ! F_41 ( V_124 , V_125 , F_31 , V_58 , V_59 ) ) goto V_129;
if ( ! F_41 ( & V_128 , V_126 , F_32 , V_58 , V_59 ) ) goto V_129;
if ( ! F_56 ( V_124 , V_124 , & V_128 , V_58 , V_59 ) ) goto V_129;
V_63 = 1 ;
V_129:
F_57 ( & V_128 ) ;
return V_63 ;
}
static int F_58 ( T_11 * V_123 , T_6 * V_56 , T_6 * V_57 ,
const T_6 * V_50 , const T_6 * V_58 , T_7 * V_59 ,
T_12 * V_130 )
{
return F_41 ( V_56 , V_57 , V_50 , V_58 , V_59 ) ;
}
static int F_59 ( T_6 * V_56 , const T_6 * V_57 , const T_6 * V_50 ,
const T_6 * V_58 , T_7 * V_59 , T_12 * V_130 )
{
return F_41 ( V_56 , V_57 , V_50 , V_58 , V_59 ) ;
}
static int F_60 ( T_13 const * V_131 , T_6 * V_56 ,
const T_6 * V_57 , const T_6 * V_50 ,
const T_6 * V_58 , T_7 * V_59 , T_12 * V_130 )
{
return F_41 ( V_56 , V_57 , V_50 , V_58 , V_59 ) ;
}
static int F_61 ( unsigned char * V_132 , int V_133 )
{
int V_63 = 0 ;
unsigned int V_25 ;
if( V_29 == 0 )
{
F_36 ( V_134 , V_135 ) ;
goto V_33;
}
V_25 = V_43 ( V_29 , V_133 , V_132 ) ;
if ( V_25 < 0 )
{
F_36 ( V_134 , V_86 ) ;
goto V_33;
}
V_63 = 1 ;
V_33:
return V_63 ;
}
static int F_62 ( void )
{
return 1 ;
}
static int F_63 ( T_1 * V_1 , const char * V_136 )
{
if( V_136 && ( strcmp ( V_136 , V_5 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
