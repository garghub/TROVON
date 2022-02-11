static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 = V_1 -> V_6 . V_7 -> V_8 -> V_9 ;
char * V_10 ;
T_1 V_11 ;
if ( V_5 >= F_2 ( V_12 ) || ! V_12 [ V_5 ] )
return - V_13 ;
V_10 = F_3 ( V_1 , V_2 , V_3 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_11 = V_12 [ V_5 ] ( V_1 , V_10 , V_3 ) ;
if ( V_11 >= 0 ) {
F_6 ( V_1 , V_11 ) ;
V_11 = V_3 ;
}
return V_11 ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
if ( ! V_1 -> V_14 ) {
T_1 V_11 = F_1 ( V_1 , V_2 , 0 , V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_9 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = F_10 ( & V_21 , V_22 ) ;
V_16 = F_11 ( V_1 , & V_23 ) ;
if ( V_16 )
return V_16 ;
V_18 = V_1 -> V_14 ;
V_18 -> V_24 = V_20 -> V_25 ;
return 0 ;
}
static int F_12 ( struct V_17 * V_26 , void * V_27 )
{
F_13 ( V_26 , L_1 , V_28 , V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
return F_15 ( V_1 , F_12 , NULL ) ;
}
static int F_16 ( struct V_17 * V_26 , void * V_27 )
{
F_13 ( V_26 , V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
return F_15 ( V_1 , F_16 , NULL ) ;
}
static T_1 F_18 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_31 V_32 ;
struct V_33 * V_34 = (struct V_33 * ) & V_32 ;
T_3 V_35 = sizeof( V_32 ) ;
char * V_36 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_36 = V_2 ;
if ( F_19 ( & V_2 , V_36 , V_3 ) < 0 )
return - V_13 ;
if ( F_20 ( & V_21 , V_36 , V_3 , V_34 , V_35 ) == 0 )
return - V_13 ;
return F_21 ( V_34 ) ;
}
static T_1 F_22 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_37 V_37 ;
char * V_36 ;
int error ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_36 = V_2 ;
if ( F_19 ( & V_2 , V_36 , V_3 ) < 0 )
return - V_13 ;
error = F_23 ( V_36 , 0 , & V_37 ) ;
if ( error )
return error ;
error = F_24 ( V_37 . V_7 -> V_38 ) ;
F_25 ( & V_37 ) ;
return error ;
}
static T_1 F_26 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_39 , * V_37 ;
int V_40 ( V_41 ) ;
char * V_42 = V_2 ;
int V_43 ;
struct V_44 * V_45 ;
struct V_46 V_47 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_39 = V_42 ;
V_43 = F_19 ( & V_42 , V_39 , V_3 ) ;
if ( V_43 <= 0 )
return - V_13 ;
V_37 = V_39 + V_43 + 1 ;
V_43 = F_19 ( & V_42 , V_37 , V_3 ) ;
if ( V_43 <= 0 )
return - V_13 ;
V_43 = F_27 ( & V_42 , & V_41 ) ;
if ( V_43 )
return V_43 ;
if ( V_41 < V_48 )
return - V_13 ;
if ( V_41 > V_49 )
V_41 = V_49 ;
if ( F_19 ( & V_42 , V_42 , V_3 ) > 0 )
return - V_13 ;
V_45 = F_28 ( V_39 ) ;
if ( ! V_45 )
return - V_50 ;
V_43 = F_29 ( & V_21 , V_45 , V_37 , & V_47 , V_41 ) ;
F_30 ( V_45 ) ;
if ( V_43 )
return V_43 ;
V_42 = V_2 ;
V_43 = V_51 ;
F_31 ( & V_42 , & V_43 , ( char * ) & V_47 . V_52 , V_47 . V_53 ) ;
V_42 [ - 1 ] = '\n' ;
return V_42 - V_2 ;
}
static T_1 F_32 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
int V_11 ;
if ( V_3 > 0 ) {
int V_54 ;
V_11 = F_27 ( & V_42 , & V_54 ) ;
if ( V_11 )
return V_11 ;
if ( V_54 < 0 )
return - V_13 ;
V_11 = F_33 ( V_55 , V_54 ) ;
if ( V_11 < 0 )
return V_11 ;
} else
V_11 = F_34 () ;
return F_35 ( V_2 , V_51 , L_2 , V_11 ) ;
}
static T_1 F_36 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
int V_56 ;
int V_11 ;
int V_43 ;
int V_57 ;
int * V_58 ;
F_37 ( & V_59 ) ;
V_57 = F_38 () ;
if ( V_57 == 0 ) {
F_39 ( & V_59 ) ;
strcpy ( V_2 , L_3 ) ;
return strlen ( V_2 ) ;
}
V_58 = F_40 ( V_57 , sizeof( int ) , V_60 ) ;
V_11 = - V_50 ;
if ( V_58 == NULL )
goto V_61;
if ( V_3 > 0 ) {
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_11 = F_27 ( & V_42 , & V_58 [ V_56 ] ) ;
if ( V_11 == - V_62 )
break;
if ( V_11 )
goto V_61;
V_11 = - V_13 ;
if ( V_58 [ V_56 ] < 0 )
goto V_61;
}
V_11 = F_41 ( V_56 , V_58 ) ;
if ( V_11 )
goto V_61;
}
V_11 = F_42 ( V_57 , V_58 ) ;
if ( V_11 )
goto V_61;
V_42 = V_2 ;
V_3 = V_51 ;
for ( V_56 = 0 ; V_56 < V_57 && V_3 > 0 ; V_56 ++ ) {
snprintf ( V_42 , V_3 , L_4 , V_58 [ V_56 ] , ( V_56 == V_57 - 1 ? '\n' : ' ' ) ) ;
V_43 = strlen ( V_42 ) ;
V_3 -= V_43 ;
V_42 += V_43 ;
}
V_11 = V_42 - V_2 ;
V_61:
F_43 ( V_58 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_44 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
char * V_63 , * V_64 , V_65 ;
int V_43 , V_66 , V_67 ;
unsigned V_68 ;
T_1 V_69 = 0 ;
char * V_70 ;
if ( V_3 > 0 ) {
if ( V_71 )
return - V_72 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_63 = V_42 ;
V_43 = F_19 ( & V_42 , V_63 , V_3 ) ;
if ( V_43 <= 0 ) return - V_13 ;
do {
V_65 = * V_63 ;
if ( V_65 == '+' || V_65 == '-' )
V_66 = F_45 ( ( V_63 + 1 ) , & V_64 , 0 ) ;
else
V_66 = F_45 ( V_63 , & V_64 , 0 ) ;
if ( * V_64 == '.' ) {
if ( V_66 < 4 )
return - V_13 ;
V_68 = F_46 ( V_64 + 1 , NULL , 0 ) ;
if ( V_68 == 0 )
return - V_13 ;
if ( F_47 ( V_68 , V_65 == '-' ?
V_73 : V_74 ) < 0 )
return - V_13 ;
goto V_75;
}
switch( V_66 ) {
case 2 :
case 3 :
case 4 :
F_48 ( V_66 , V_65 == '-' ? V_73 : V_74 ) ;
break;
default:
return - V_13 ;
}
V_75:
V_63 += V_43 + 1 ;
} while ( ( V_43 = F_19 ( & V_42 , V_63 , V_3 ) ) > 0 );
F_49 () ;
}
V_43 = 0 ;
V_70 = L_5 ;
V_67 = V_51 ;
for ( V_66 = 2 ; V_66 <= 4 ; V_66 ++ )
if ( F_48 ( V_66 , V_76 ) ) {
V_43 = snprintf ( V_2 , V_67 , L_6 , V_70 ,
F_48 ( V_66 , V_77 ) ? '+' : '-' ,
V_66 ) ;
V_70 = L_7 ;
if ( V_43 > V_67 )
break;
V_67 -= V_43 ;
V_2 += V_43 ;
V_69 += V_43 ;
}
if ( F_48 ( 4 , V_76 ) )
for ( V_68 = 1 ; V_68 <= V_78 ;
V_68 ++ ) {
V_43 = snprintf ( V_2 , V_67 , L_8 ,
( F_48 ( 4 , V_77 ) &&
F_47 ( V_68 , V_77 ) ) ?
'+' : '-' ,
V_68 ) ;
if ( V_43 > V_67 )
break;
V_67 -= V_43 ;
V_2 += V_43 ;
V_69 += V_43 ;
}
V_43 = snprintf ( V_2 , V_67 , L_9 ) ;
if ( V_43 > V_67 )
return - V_13 ;
return V_69 + V_43 ;
}
static T_1 F_50 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_37 ( & V_59 ) ;
V_11 = F_44 ( V_1 , V_2 , V_3 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_51 ( char * V_2 )
{
if ( V_71 == NULL )
return 0 ;
return F_52 ( V_71 , V_2 , V_51 ) ;
}
static T_1 F_53 ( char * V_2 )
{
char * V_42 = V_2 ;
int V_79 , V_16 ;
struct V_80 * V_80 = & V_21 ;
V_16 = F_27 ( & V_42 , & V_79 ) ;
if ( V_16 != 0 || V_79 < 0 )
return - V_13 ;
V_16 = F_54 () ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_55 ( V_71 , V_79 , V_2 , V_51 ) ;
if ( V_16 < 0 ) {
F_56 ( V_80 ) ;
return V_16 ;
}
V_71 -> V_81 -- ;
return V_16 ;
}
static T_1 F_57 ( char * V_2 )
{
char * V_82 ;
int V_43 = 0 ;
V_82 = F_58 ( V_2 + 1 , V_60 ) ;
if ( V_82 == NULL )
return - V_50 ;
if ( V_71 != NULL )
V_43 = F_59 ( V_71 , V_2 ,
V_51 , V_82 ) ;
F_43 ( V_82 ) ;
return V_43 ;
}
static T_1 F_60 ( char * V_2 )
{
char V_83 [ 16 ] ;
struct V_84 * V_85 ;
int V_86 , V_16 ;
struct V_80 * V_80 = & V_21 ;
if ( sscanf ( V_2 , L_10 , V_83 , & V_86 ) != 2 )
return - V_13 ;
if ( V_86 < 1 || V_86 > V_87 )
return - V_13 ;
V_16 = F_54 () ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_61 ( V_71 , V_83 , V_80 ,
V_88 , V_86 , V_89 ) ;
if ( V_16 < 0 )
goto V_90;
V_16 = F_61 ( V_71 , V_83 , V_80 ,
V_91 , V_86 , V_89 ) ;
if ( V_16 < 0 && V_16 != - V_92 )
goto V_93;
V_71 -> V_81 -- ;
return 0 ;
V_93:
V_85 = F_62 ( V_71 , V_83 , V_80 , V_88 , V_86 ) ;
if ( V_85 != NULL ) {
F_63 ( V_85 ) ;
F_64 ( V_85 ) ;
}
V_90:
F_56 ( V_80 ) ;
return V_16 ;
}
static T_1 F_65 ( char * V_2 )
{
struct V_84 * V_85 ;
char V_83 [ 16 ] ;
int V_86 ;
if ( sscanf ( & V_2 [ 1 ] , L_10 , V_83 , & V_86 ) != 2 )
return - V_13 ;
if ( V_86 < 1 || V_86 > V_87 || V_71 == NULL )
return - V_13 ;
V_85 = F_62 ( V_71 , V_83 , & V_21 , V_94 , V_86 ) ;
if ( V_85 == NULL )
return - V_95 ;
F_63 ( V_85 ) ;
F_64 ( V_85 ) ;
return 0 ;
}
static T_1 F_66 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
if ( V_3 == 0 )
return F_51 ( V_2 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_53 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isdigit ( V_2 [ 1 ] ) )
return F_57 ( V_2 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_60 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isalpha ( V_2 [ 1 ] ) )
return F_65 ( V_2 ) ;
return - V_13 ;
}
static T_1 F_67 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_37 ( & V_59 ) ;
V_11 = F_66 ( V_1 , V_2 , V_3 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_68 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
if ( V_3 > 0 ) {
int V_96 ;
int V_11 = F_27 ( & V_42 , & V_96 ) ;
if ( V_11 )
return V_11 ;
if ( V_96 < 1024 )
V_96 = 1024 ;
if ( V_96 > V_97 )
V_96 = V_97 ;
V_96 &= ~ ( 1024 - 1 ) ;
F_37 ( & V_59 ) ;
if ( V_71 ) {
F_39 ( & V_59 ) ;
return - V_72 ;
}
V_98 = V_96 ;
F_39 ( & V_59 ) ;
}
return F_35 ( V_2 , V_51 , L_2 ,
V_98 ) ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
char * V_42 = V_2 ;
int V_11 , V_56 ;
if ( V_3 > 0 ) {
if ( V_71 )
return - V_72 ;
V_11 = F_27 ( & V_42 , & V_56 ) ;
if ( V_11 )
return V_11 ;
if ( V_56 < 10 || V_56 > 3600 )
return - V_13 ;
* time = V_56 ;
}
return F_35 ( V_2 , V_51 , L_11 , * time ) ;
}
static T_1 F_70 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
T_1 V_11 ;
F_37 ( & V_59 ) ;
V_11 = F_69 ( V_1 , V_2 , V_3 , time ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_71 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_70 ( V_1 , V_2 , V_3 , & V_99 ) ;
}
static T_1 F_72 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_70 ( V_1 , V_2 , V_3 , & V_100 ) ;
}
static T_1 F_73 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
char * V_101 ;
int V_43 , V_102 ;
if ( V_3 > 0 ) {
if ( V_71 )
return - V_72 ;
if ( V_3 > V_103 || V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_101 = V_42 ;
V_43 = F_19 ( & V_42 , V_101 , V_3 ) ;
if ( V_43 <= 0 )
return - V_13 ;
V_102 = F_74 ( V_101 ) ;
if ( V_102 )
return V_102 ;
}
return F_35 ( V_2 , V_51 , L_12 ,
F_75 () ) ;
}
static T_1 F_76 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_37 ( & V_59 ) ;
V_11 = F_73 ( V_1 , V_2 , V_3 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static int F_77 ( struct V_104 * V_105 , void * V_10 , int V_106 )
{
static struct V_107 V_108 [] = {
[ V_109 ] = { L_13 , & V_110 , V_111 } ,
[ V_112 ] = { L_14 ,
& V_113 , V_111 } ,
[ V_114 ] = { L_15 ,
& V_115 , V_116 | V_117 } ,
[ V_118 ] = { L_16 ,
& V_115 , V_116 | V_117 } ,
[ V_119 ] = { L_17 , & V_115 , V_116 | V_117 } ,
[ V_120 ] = { L_18 , & V_115 , V_116 | V_117 } ,
[ V_121 ] = { L_19 , & V_115 , V_116 | V_117 } ,
[ V_122 ] = { L_20 , & V_123 , V_111 } ,
[ V_124 ] = { L_21 , & V_115 , V_116 | V_117 } ,
[ V_125 ] = { L_22 , & V_115 , V_116 | V_111 } ,
[ V_126 ] = { L_23 , & V_115 , V_116 | V_111 } ,
#if F_78 ( V_127 ) || F_78 ( V_128 )
[ V_129 ] = { L_24 , & V_130 , V_111 } ,
#endif
#ifdef F_79
[ V_131 ] = { L_25 , & V_115 , V_116 | V_117 } ,
[ V_132 ] = { L_26 , & V_115 , V_116 | V_117 } ,
[ V_133 ] = { L_27 , & V_115 , V_116 | V_117 } ,
#endif
{ L_5 }
} ;
return F_80 ( V_105 , 0x6e667364 , V_108 ) ;
}
static struct V_7 * F_81 ( struct V_134 * V_135 ,
int V_136 , const char * V_137 , void * V_10 )
{
return F_82 ( V_135 , V_136 , V_10 , F_77 ) ;
}
static int F_83 ( void )
{
struct V_138 * V_139 ;
V_139 = F_84 ( L_28 , NULL ) ;
if ( ! V_139 )
return - V_50 ;
V_139 = F_85 ( L_13 , 0 , V_139 , & V_110 ) ;
if ( ! V_139 )
return - V_50 ;
return 0 ;
}
static int F_83 ( void )
{
return 0 ;
}
static T_7 int F_86 ( struct V_80 * V_80 )
{
int V_140 ;
V_140 = F_87 ( V_80 ) ;
if ( V_140 )
goto V_141;
V_140 = F_88 ( V_80 ) ;
if ( V_140 )
goto V_142;
return 0 ;
V_142:
F_89 ( V_80 ) ;
V_141:
return V_140 ;
}
static T_8 void F_90 ( struct V_80 * V_80 )
{
F_91 ( V_80 ) ;
F_89 ( V_80 ) ;
}
static int T_9 F_92 ( void )
{
int V_140 ;
F_93 ( V_143 L_29 ) ;
V_140 = F_94 () ;
if ( V_140 )
return V_140 ;
V_140 = F_95 ( & V_144 ) ;
if ( V_140 < 0 )
goto V_145;
V_140 = F_96 () ;
if ( V_140 )
goto V_146;
F_97 () ;
V_140 = F_98 () ;
if ( V_140 )
goto V_147;
F_99 () ;
V_140 = F_100 () ;
if ( V_140 )
goto V_148;
F_101 () ;
V_140 = F_83 () ;
if ( V_140 )
goto V_149;
V_140 = F_102 ( & V_150 ) ;
if ( V_140 )
goto V_151;
return 0 ;
V_151:
F_103 ( L_30 , NULL ) ;
F_103 ( L_28 , NULL ) ;
V_149:
F_104 () ;
F_105 () ;
V_148:
F_106 () ;
F_107 () ;
V_147:
F_108 () ;
V_146:
F_109 ( & V_144 ) ;
V_145:
F_110 () ;
return V_140 ;
}
static void T_10 F_111 ( void )
{
F_105 () ;
F_103 ( L_30 , NULL ) ;
F_103 ( L_28 , NULL ) ;
F_106 () ;
F_104 () ;
F_108 () ;
F_107 () ;
F_112 ( & V_150 ) ;
F_109 ( & V_144 ) ;
F_110 () ;
}
