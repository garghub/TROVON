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
struct V_54 * V_54 = & V_21 ;
if ( V_3 > 0 ) {
int V_55 ;
V_11 = F_27 ( & V_42 , & V_55 ) ;
if ( V_11 )
return V_11 ;
if ( V_55 < 0 )
return - V_13 ;
V_11 = F_33 ( V_55 , V_54 ) ;
if ( V_11 < 0 )
return V_11 ;
} else
V_11 = F_34 ( V_54 ) ;
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
struct V_54 * V_54 = & V_21 ;
F_37 ( & V_59 ) ;
V_57 = F_38 ( V_54 ) ;
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
V_11 = F_41 ( V_56 , V_58 , V_54 ) ;
if ( V_11 )
goto V_61;
}
V_11 = F_42 ( V_57 , V_58 , V_54 ) ;
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
struct V_54 * V_54 = & V_21 ;
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
if ( V_3 > 0 ) {
if ( V_20 -> V_71 )
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
static T_1 F_51 ( char * V_2 , struct V_54 * V_54 )
{
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
if ( V_20 -> V_71 == NULL )
return 0 ;
return F_52 ( V_20 -> V_71 , V_2 , V_51 ) ;
}
static T_1 F_53 ( char * V_2 , struct V_54 * V_54 )
{
char * V_42 = V_2 ;
int V_79 , V_16 ;
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
V_16 = F_27 ( & V_42 , & V_79 ) ;
if ( V_16 != 0 || V_79 < 0 )
return - V_13 ;
V_16 = F_54 ( V_54 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_55 ( V_20 -> V_71 , V_79 , V_2 , V_51 ) ;
if ( V_16 < 0 ) {
F_56 ( V_54 ) ;
return V_16 ;
}
V_20 -> V_71 -> V_80 -- ;
return V_16 ;
}
static T_1 F_57 ( char * V_2 , struct V_54 * V_54 )
{
char V_81 [ 16 ] ;
struct V_82 * V_83 ;
int V_84 , V_16 ;
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
if ( sscanf ( V_2 , L_10 , V_81 , & V_84 ) != 2 )
return - V_13 ;
if ( V_84 < 1 || V_84 > V_85 )
return - V_13 ;
V_16 = F_54 ( V_54 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_58 ( V_20 -> V_71 , V_81 , V_54 ,
V_86 , V_84 , V_87 ) ;
if ( V_16 < 0 )
goto V_88;
V_16 = F_58 ( V_20 -> V_71 , V_81 , V_54 ,
V_89 , V_84 , V_87 ) ;
if ( V_16 < 0 && V_16 != - V_90 )
goto V_91;
V_20 -> V_71 -> V_80 -- ;
return 0 ;
V_91:
V_83 = F_59 ( V_20 -> V_71 , V_81 , V_54 , V_86 , V_84 ) ;
if ( V_83 != NULL ) {
F_60 ( V_83 ) ;
F_61 ( V_83 ) ;
}
V_88:
F_56 ( V_54 ) ;
return V_16 ;
}
static T_1 F_62 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_54 * V_54 )
{
if ( V_3 == 0 )
return F_51 ( V_2 , V_54 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_53 ( V_2 , V_54 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_57 ( V_2 , V_54 ) ;
return - V_13 ;
}
static T_1 F_63 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
struct V_54 * V_54 = & V_21 ;
F_37 ( & V_59 ) ;
V_11 = F_62 ( V_1 , V_2 , V_3 , V_54 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_64 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 = V_2 ;
struct V_54 * V_54 = & V_21 ;
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
if ( V_3 > 0 ) {
int V_92 ;
int V_11 = F_27 ( & V_42 , & V_92 ) ;
if ( V_11 )
return V_11 ;
if ( V_92 < 1024 )
V_92 = 1024 ;
if ( V_92 > V_93 )
V_92 = V_93 ;
V_92 &= ~ ( 1024 - 1 ) ;
F_37 ( & V_59 ) ;
if ( V_20 -> V_71 ) {
F_39 ( & V_59 ) ;
return - V_72 ;
}
V_94 = V_92 ;
F_39 ( & V_59 ) ;
}
return F_35 ( V_2 , V_51 , L_2 ,
V_94 ) ;
}
static T_1 F_65 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_19 * V_20 )
{
char * V_42 = V_2 ;
int V_11 , V_56 ;
if ( V_3 > 0 ) {
if ( V_20 -> V_71 )
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
static T_1 F_66 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_19 * V_20 )
{
T_1 V_11 ;
F_37 ( & V_59 ) ;
V_11 = F_65 ( V_1 , V_2 , V_3 , time , V_20 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static T_1 F_67 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_19 * V_20 = F_10 ( & V_21 , V_22 ) ;
return F_66 ( V_1 , V_2 , V_3 , & V_20 -> V_95 , V_20 ) ;
}
static T_1 F_68 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_19 * V_20 = F_10 ( & V_21 , V_22 ) ;
return F_66 ( V_1 , V_2 , V_3 , & V_20 -> V_96 , V_20 ) ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_19 * V_20 )
{
char * V_42 = V_2 ;
char * V_97 ;
int V_43 , V_98 ;
if ( V_3 > 0 ) {
if ( V_20 -> V_71 )
return - V_72 ;
if ( V_3 > V_99 || V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_97 = V_42 ;
V_43 = F_19 ( & V_42 , V_97 , V_3 ) ;
if ( V_43 <= 0 )
return - V_13 ;
V_98 = F_70 ( V_97 ) ;
if ( V_98 )
return V_98 ;
}
return F_35 ( V_2 , V_51 , L_12 ,
F_71 () ) ;
}
static T_1 F_72 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
struct V_19 * V_20 = F_10 ( & V_21 , V_22 ) ;
F_37 ( & V_59 ) ;
V_11 = F_69 ( V_1 , V_2 , V_3 , V_20 ) ;
F_39 ( & V_59 ) ;
return V_11 ;
}
static int F_73 ( struct V_100 * V_101 , void * V_10 , int V_102 )
{
static struct V_103 V_104 [] = {
[ V_105 ] = { L_13 , & V_106 , V_107 } ,
[ V_108 ] = { L_14 ,
& V_109 , V_107 } ,
[ V_110 ] = { L_15 ,
& V_111 , V_112 | V_113 } ,
[ V_114 ] = { L_16 ,
& V_111 , V_112 | V_113 } ,
[ V_115 ] = { L_17 , & V_111 , V_112 | V_113 } ,
[ V_116 ] = { L_18 , & V_111 , V_112 | V_113 } ,
[ V_117 ] = { L_19 , & V_111 , V_112 | V_113 } ,
[ V_118 ] = { L_20 , & V_119 , V_107 } ,
[ V_120 ] = { L_21 , & V_111 , V_112 | V_113 } ,
[ V_121 ] = { L_22 , & V_111 , V_112 | V_107 } ,
[ V_122 ] = { L_23 , & V_111 , V_112 | V_107 } ,
#if F_74 ( V_123 ) || F_74 ( V_124 )
[ V_125 ] = { L_24 , & V_126 , V_107 } ,
#endif
#ifdef F_75
[ V_127 ] = { L_25 , & V_111 , V_112 | V_113 } ,
[ V_128 ] = { L_26 , & V_111 , V_112 | V_113 } ,
[ V_129 ] = { L_27 , & V_111 , V_112 | V_113 } ,
#endif
{ L_5 }
} ;
return F_76 ( V_101 , 0x6e667364 , V_104 ) ;
}
static struct V_7 * F_77 ( struct V_130 * V_131 ,
int V_132 , const char * V_133 , void * V_10 )
{
return F_78 ( V_131 , V_132 , V_10 , F_73 ) ;
}
static int F_79 ( void )
{
struct V_134 * V_135 ;
V_135 = F_80 ( L_28 , NULL ) ;
if ( ! V_135 )
return - V_50 ;
V_135 = F_81 ( L_13 , 0 , V_135 , & V_106 ) ;
if ( ! V_135 )
return - V_50 ;
return 0 ;
}
static int F_79 ( void )
{
return 0 ;
}
static T_7 int F_82 ( struct V_54 * V_54 )
{
int V_136 ;
struct V_19 * V_20 = F_10 ( V_54 , V_22 ) ;
V_136 = F_83 ( V_54 ) ;
if ( V_136 )
goto V_137;
V_136 = F_84 ( V_54 ) ;
if ( V_136 )
goto V_138;
V_20 -> V_95 = 90 ;
V_20 -> V_96 = 90 ;
return 0 ;
V_138:
F_85 ( V_54 ) ;
V_137:
return V_136 ;
}
static T_8 void F_86 ( struct V_54 * V_54 )
{
F_87 ( V_54 ) ;
F_85 ( V_54 ) ;
}
static int T_9 F_88 ( void )
{
int V_136 ;
F_89 ( V_139 L_29 ) ;
V_136 = F_90 () ;
if ( V_136 )
return V_136 ;
V_136 = F_91 ( & V_140 ) ;
if ( V_136 < 0 )
goto V_141;
V_136 = F_92 () ;
if ( V_136 )
goto V_142;
F_93 () ;
V_136 = F_94 () ;
if ( V_136 )
goto V_143;
F_95 () ;
V_136 = F_96 () ;
if ( V_136 )
goto V_144;
F_97 () ;
V_136 = F_79 () ;
if ( V_136 )
goto V_145;
V_136 = F_98 ( & V_146 ) ;
if ( V_136 )
goto V_147;
return 0 ;
V_147:
F_99 ( L_30 , NULL ) ;
F_99 ( L_28 , NULL ) ;
V_145:
F_100 () ;
F_101 () ;
V_144:
F_102 () ;
F_103 () ;
V_143:
F_104 () ;
V_142:
F_105 ( & V_140 ) ;
V_141:
F_106 () ;
return V_136 ;
}
static void T_10 F_107 ( void )
{
F_101 () ;
F_99 ( L_30 , NULL ) ;
F_99 ( L_28 , NULL ) ;
F_102 () ;
F_100 () ;
F_104 () ;
F_103 () ;
F_108 ( & V_146 ) ;
F_105 ( & V_140 ) ;
F_106 () ;
}
