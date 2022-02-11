static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 = F_2 ( V_1 ) -> V_6 ;
char * V_7 ;
T_1 V_8 ;
if ( V_5 >= F_3 ( V_9 ) || ! V_9 [ V_5 ] )
return - V_10 ;
V_7 = F_4 ( V_1 , V_2 , V_3 ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
V_8 = V_9 [ V_5 ] ( V_1 , V_7 , V_3 ) ;
if ( V_8 >= 0 ) {
F_7 ( V_1 , V_8 ) ;
V_8 = V_3 ;
}
return V_8 ;
}
static T_1 F_8 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
if ( ! V_1 -> V_11 ) {
T_1 V_8 = F_1 ( V_1 , V_2 , 0 , V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return F_9 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_10 ( struct V_12 * V_12 , struct V_1 * V_1 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_13 = F_12 ( V_1 , & V_19 ) ;
if ( V_13 )
return V_13 ;
V_15 = V_1 -> V_11 ;
V_15 -> V_20 = V_17 -> V_21 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_10 ( V_23 -> V_24 -> V_25 , V_1 ) ;
}
static int F_14 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_10 ( V_22 -> V_26 -> V_27 , V_1 ) ;
}
static int F_15 ( struct V_14 * V_28 , void * V_29 )
{
F_16 ( V_28 , L_1 , V_30 , V_31 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_18 ( V_1 , F_15 , NULL ) ;
}
static int F_19 ( struct V_14 * V_28 , void * V_29 )
{
F_16 ( V_28 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_18 ( V_1 , F_19 , NULL ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_33 V_34 ;
struct V_35 * V_36 = (struct V_35 * ) & V_34 ;
T_3 V_37 = sizeof( V_34 ) ;
char * V_38 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_38 = V_2 ;
if ( F_22 ( & V_2 , V_38 , V_3 ) < 0 )
return - V_10 ;
if ( F_23 ( V_12 , V_38 , V_3 , V_36 , V_37 ) == 0 )
return - V_10 ;
return F_24 ( V_36 ) ;
}
static T_1 F_25 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_41 V_41 ;
char * V_38 ;
int error ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_38 = V_2 ;
if ( F_22 ( & V_2 , V_38 , V_3 ) < 0 )
return - V_10 ;
error = F_26 ( V_38 , 0 , & V_41 ) ;
if ( error )
return error ;
error = F_27 ( V_41 . V_42 -> V_40 ) ;
F_28 ( & V_41 ) ;
return error ;
}
static T_1 F_29 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_43 , * V_41 ;
int V_44 ( V_45 ) ;
char * V_46 = V_2 ;
int V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_43 = V_46 ;
V_47 = F_22 ( & V_46 , V_43 , V_3 ) ;
if ( V_47 <= 0 )
return - V_10 ;
V_41 = V_43 + V_47 + 1 ;
V_47 = F_22 ( & V_46 , V_41 , V_3 ) ;
if ( V_47 <= 0 )
return - V_10 ;
V_47 = F_30 ( & V_46 , & V_45 ) ;
if ( V_47 )
return V_47 ;
if ( V_45 < V_52 )
return - V_10 ;
V_45 = F_31 ( V_45 , V_53 ) ;
if ( F_22 ( & V_46 , V_46 , V_3 ) > 0 )
return - V_10 ;
V_49 = F_32 ( V_43 ) ;
if ( ! V_49 )
return - V_54 ;
V_47 = F_33 ( V_12 , V_49 , V_41 , & V_51 , V_45 ) ;
F_34 ( V_49 ) ;
if ( V_47 )
return V_47 ;
V_46 = V_2 ;
V_47 = V_55 ;
F_35 ( & V_46 , & V_47 , ( char * ) & V_51 . V_56 , V_51 . V_57 ) ;
V_46 [ - 1 ] = '\n' ;
return V_46 - V_2 ;
}
static T_1 F_36 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
int V_8 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
if ( V_3 > 0 ) {
int V_58 ;
V_8 = F_30 ( & V_46 , & V_58 ) ;
if ( V_8 )
return V_8 ;
if ( V_58 < 0 )
return - V_10 ;
V_8 = F_37 ( V_58 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
V_8 = F_38 ( V_12 ) ;
return F_39 ( V_2 , V_55 , L_2 , V_8 ) ;
}
static T_1 F_40 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
int V_59 ;
int V_8 ;
int V_47 ;
int V_60 ;
int * V_61 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
F_41 ( & V_62 ) ;
V_60 = F_42 ( V_12 ) ;
if ( V_60 == 0 ) {
F_43 ( & V_62 ) ;
strcpy ( V_2 , L_3 ) ;
return strlen ( V_2 ) ;
}
V_61 = F_44 ( V_60 , sizeof( int ) , V_63 ) ;
V_8 = - V_54 ;
if ( V_61 == NULL )
goto V_64;
if ( V_3 > 0 ) {
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_8 = F_30 ( & V_46 , & V_61 [ V_59 ] ) ;
if ( V_8 == - V_65 )
break;
if ( V_8 )
goto V_64;
V_8 = - V_10 ;
if ( V_61 [ V_59 ] < 0 )
goto V_64;
}
V_8 = F_45 ( V_59 , V_61 , V_12 ) ;
if ( V_8 )
goto V_64;
}
V_8 = F_46 ( V_60 , V_61 , V_12 ) ;
if ( V_8 )
goto V_64;
V_46 = V_2 ;
V_3 = V_55 ;
for ( V_59 = 0 ; V_59 < V_60 && V_3 > 0 ; V_59 ++ ) {
snprintf ( V_46 , V_3 , L_4 , V_61 [ V_59 ] , ( V_59 == V_60 - 1 ? '\n' : ' ' ) ) ;
V_47 = strlen ( V_46 ) ;
V_3 -= V_47 ;
V_46 += V_47 ;
}
V_8 = V_46 - V_2 ;
V_64:
F_47 ( V_61 ) ;
F_43 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_48 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
char * V_66 , * V_67 , V_68 ;
int V_47 , V_69 , V_70 ;
unsigned V_71 ;
T_1 V_72 = 0 ;
char * V_73 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_3 > 0 ) {
if ( V_17 -> V_74 )
return - V_75 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_66 = V_46 ;
V_47 = F_22 ( & V_46 , V_66 , V_3 ) ;
if ( V_47 <= 0 ) return - V_10 ;
do {
V_68 = * V_66 ;
if ( V_68 == '+' || V_68 == '-' )
V_69 = F_49 ( ( V_66 + 1 ) , & V_67 , 0 ) ;
else
V_69 = F_49 ( V_66 , & V_67 , 0 ) ;
if ( * V_67 == '.' ) {
if ( V_69 != 4 )
return - V_10 ;
V_71 = F_50 ( V_67 + 1 , NULL , 0 ) ;
if ( V_71 == 0 )
return - V_10 ;
if ( F_51 ( V_71 , V_68 == '-' ?
V_76 : V_77 ) < 0 )
return - V_10 ;
goto V_78;
}
switch( V_69 ) {
case 2 :
case 3 :
case 4 :
F_52 ( V_69 , V_68 == '-' ? V_76 : V_77 ) ;
break;
default:
return - V_10 ;
}
V_78:
V_66 += V_47 + 1 ;
} while ( ( V_47 = F_22 ( & V_46 , V_66 , V_3 ) ) > 0 );
F_53 () ;
}
V_47 = 0 ;
V_73 = L_5 ;
V_70 = V_55 ;
for ( V_69 = 2 ; V_69 <= 4 ; V_69 ++ )
if ( F_52 ( V_69 , V_79 ) ) {
V_47 = snprintf ( V_2 , V_70 , L_6 , V_73 ,
F_52 ( V_69 , V_80 ) ? '+' : '-' ,
V_69 ) ;
V_73 = L_7 ;
if ( V_47 > V_70 )
break;
V_70 -= V_47 ;
V_2 += V_47 ;
V_72 += V_47 ;
}
if ( F_52 ( 4 , V_79 ) )
for ( V_71 = 1 ; V_71 <= V_81 ;
V_71 ++ ) {
V_47 = snprintf ( V_2 , V_70 , L_8 ,
( F_52 ( 4 , V_80 ) &&
F_51 ( V_71 , V_80 ) ) ?
'+' : '-' ,
V_71 ) ;
if ( V_47 > V_70 )
break;
V_70 -= V_47 ;
V_2 += V_47 ;
V_72 += V_47 ;
}
V_47 = snprintf ( V_2 , V_70 , L_9 ) ;
if ( V_47 > V_70 )
return - V_10 ;
return V_72 + V_47 ;
}
static T_1 F_54 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
F_41 ( & V_62 ) ;
V_8 = F_48 ( V_1 , V_2 , V_3 ) ;
F_43 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_55 ( char * V_2 , struct V_12 * V_12 )
{
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_17 -> V_74 == NULL )
return 0 ;
return F_56 ( V_17 -> V_74 , V_2 , V_55 ) ;
}
static T_1 F_57 ( char * V_2 , struct V_12 * V_12 )
{
char * V_46 = V_2 ;
int V_82 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_13 = F_30 ( & V_46 , & V_82 ) ;
if ( V_13 != 0 || V_82 < 0 )
return - V_10 ;
if ( F_58 ( V_12 , V_82 ) ) {
F_59 ( V_83 L_10 , V_84 ) ;
return - V_10 ;
}
V_13 = F_60 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_61 ( V_17 -> V_74 , V_82 , V_2 , V_55 ) ;
if ( V_13 < 0 ) {
F_62 ( V_12 ) ;
return V_13 ;
}
V_17 -> V_74 -> V_85 -- ;
return V_13 ;
}
static T_1 F_63 ( char * V_2 , struct V_12 * V_12 )
{
char V_86 [ 16 ] ;
struct V_87 * V_88 ;
int V_89 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( sscanf ( V_2 , L_11 , V_86 , & V_89 ) != 2 )
return - V_10 ;
if ( V_89 < 1 || V_89 > V_90 )
return - V_10 ;
V_13 = F_60 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_64 ( V_17 -> V_74 , V_86 , V_12 ,
V_91 , V_89 , V_92 ) ;
if ( V_13 < 0 )
goto V_93;
V_13 = F_64 ( V_17 -> V_74 , V_86 , V_12 ,
V_94 , V_89 , V_92 ) ;
if ( V_13 < 0 && V_13 != - V_95 )
goto V_96;
V_17 -> V_74 -> V_85 -- ;
return 0 ;
V_96:
V_88 = F_65 ( V_17 -> V_74 , V_86 , V_12 , V_91 , V_89 ) ;
if ( V_88 != NULL ) {
F_66 ( V_88 ) ;
F_67 ( V_88 ) ;
}
V_93:
F_62 ( V_12 ) ;
return V_13 ;
}
static T_1 F_68 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_12 * V_12 )
{
if ( V_3 == 0 )
return F_55 ( V_2 , V_12 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_57 ( V_2 , V_12 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_63 ( V_2 , V_12 ) ;
return - V_10 ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
F_41 ( & V_62 ) ;
V_8 = F_68 ( V_1 , V_2 , V_3 , V_12 ) ;
F_43 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_70 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_3 > 0 ) {
int V_97 ;
int V_8 = F_30 ( & V_46 , & V_97 ) ;
if ( V_8 )
return V_8 ;
V_97 = F_71 ( int , V_97 , 1024 ) ;
V_97 = F_72 ( int , V_97 , V_98 ) ;
V_97 &= ~ ( 1024 - 1 ) ;
F_41 ( & V_62 ) ;
if ( V_17 -> V_74 ) {
F_43 ( & V_62 ) ;
return - V_75 ;
}
V_99 = V_97 ;
F_43 ( & V_62 ) ;
}
return F_39 ( V_2 , V_55 , L_2 ,
V_99 ) ;
}
static T_1 F_73 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
unsigned int V_100 = V_17 -> V_101 ;
if ( V_3 > 0 ) {
int V_8 = F_74 ( & V_46 , & V_100 ) ;
if ( V_8 )
return V_8 ;
V_17 -> V_101 = V_100 ;
}
return F_39 ( V_2 , V_55 , L_12 , V_100 ) ;
}
static T_1 F_75 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_16 * V_17 )
{
char * V_46 = V_2 ;
int V_8 , V_59 ;
if ( V_3 > 0 ) {
if ( V_17 -> V_74 )
return - V_75 ;
V_8 = F_30 ( & V_46 , & V_59 ) ;
if ( V_8 )
return V_8 ;
if ( V_59 < 10 || V_59 > 3600 )
return - V_10 ;
* time = V_59 ;
}
return F_39 ( V_2 , V_55 , L_13 , * time ) ;
}
static T_1 F_76 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_16 * V_17 )
{
T_1 V_8 ;
F_41 ( & V_62 ) ;
V_8 = F_75 ( V_1 , V_2 , V_3 , time , V_17 ) ;
F_43 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_77 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
return F_76 ( V_1 , V_2 , V_3 , & V_17 -> V_102 , V_17 ) ;
}
static T_1 F_78 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
return F_76 ( V_1 , V_2 , V_3 , & V_17 -> V_103 , V_17 ) ;
}
static T_1 F_79 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_16 * V_17 )
{
char * V_46 = V_2 ;
char * V_104 ;
int V_47 , V_105 ;
if ( V_3 > 0 ) {
if ( V_17 -> V_74 )
return - V_75 ;
if ( V_3 > V_106 || V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_104 = V_46 ;
V_47 = F_22 ( & V_46 , V_104 , V_3 ) ;
if ( V_47 <= 0 )
return - V_10 ;
V_105 = F_80 ( V_104 ) ;
if ( V_105 )
return V_105 ;
}
return F_39 ( V_2 , V_55 , L_14 ,
F_81 () ) ;
}
static T_1 F_82 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
F_41 ( & V_62 ) ;
V_8 = F_79 ( V_1 , V_2 , V_3 , V_17 ) ;
F_43 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_83 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_3 > 0 ) {
switch( V_2 [ 0 ] ) {
case 'Y' :
case 'y' :
case '1' :
F_84 ( V_17 ) ;
break;
default:
return - V_10 ;
}
}
return F_39 ( V_2 , V_55 , L_15 ,
V_17 -> V_107 ? 'Y' : 'N' ) ;
}
static int F_85 ( struct V_108 * V_109 , void * V_7 , int V_110 )
{
static struct V_111 V_112 [] = {
[ V_113 ] = { L_16 , & V_114 , V_115 } ,
[ V_116 ] = { L_17 ,
& V_117 , V_115 } ,
[ V_118 ] = { L_18 ,
& V_119 , V_120 | V_121 } ,
[ V_122 ] = { L_19 ,
& V_119 , V_120 | V_121 } ,
[ V_123 ] = { L_20 , & V_119 , V_120 | V_121 } ,
[ V_124 ] = { L_21 , & V_119 , V_120 | V_121 } ,
[ V_125 ] = { L_22 , & V_119 , V_120 | V_121 } ,
[ V_126 ] = { L_23 , & V_127 , V_115 } ,
[ V_128 ] = { L_24 , & V_129 , V_115 } ,
[ V_130 ] = { L_25 , & V_119 , V_120 | V_121 } ,
[ V_131 ] = { L_26 , & V_119 , V_120 | V_115 } ,
[ V_132 ] = { L_27 , & V_119 , V_120 | V_115 } ,
[ V_133 ] = { L_28 , & V_119 , V_120 | V_115 } ,
#if F_86 ( V_134 ) || F_86 ( V_135 )
[ V_136 ] = { L_29 , & V_137 , V_115 } ,
#endif
#ifdef F_87
[ V_138 ] = { L_30 , & V_119 , V_120 | V_121 } ,
[ V_139 ] = { L_31 , & V_119 , V_120 | V_121 } ,
[ V_140 ] = { L_32 , & V_119 , V_120 | V_121 } ,
[ V_141 ] = { L_33 , & V_119 , V_120 | V_115 } ,
#endif
{ L_5 }
} ;
struct V_12 * V_12 = V_7 ;
int V_142 ;
V_142 = F_88 ( V_109 , 0x6e667364 , V_112 ) ;
if ( V_142 )
return V_142 ;
V_109 -> V_27 = F_89 ( V_12 ) ;
return 0 ;
}
static struct V_42 * F_90 ( struct V_143 * V_144 ,
int V_145 , const char * V_146 , void * V_7 )
{
return F_91 ( V_144 , V_145 , V_23 -> V_24 -> V_25 , F_85 ) ;
}
static void F_92 ( struct V_108 * V_109 )
{
struct V_12 * V_12 = V_109 -> V_27 ;
F_93 ( V_109 ) ;
F_94 ( V_12 ) ;
}
static int F_95 ( void )
{
struct V_147 * V_148 ;
V_148 = F_96 ( L_34 , NULL ) ;
if ( ! V_148 )
return - V_54 ;
V_148 = F_97 ( L_16 , 0 , V_148 ,
& V_149 ) ;
if ( ! V_148 ) {
F_98 ( L_34 , NULL ) ;
return - V_54 ;
}
return 0 ;
}
static int F_95 ( void )
{
return 0 ;
}
static T_7 int F_99 ( struct V_12 * V_12 )
{
int V_150 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_150 = F_100 ( V_12 ) ;
if ( V_150 )
goto V_151;
V_150 = F_101 ( V_12 ) ;
if ( V_150 )
goto V_152;
V_17 -> V_102 = 90 ;
V_17 -> V_103 = 90 ;
return 0 ;
V_152:
F_102 ( V_12 ) ;
V_151:
return V_150 ;
}
static T_8 void F_103 ( struct V_12 * V_12 )
{
F_104 ( V_12 ) ;
F_102 ( V_12 ) ;
}
static int T_9 F_105 ( void )
{
int V_150 ;
F_59 ( V_153 L_35 ) ;
V_150 = F_106 () ;
if ( V_150 )
return V_150 ;
V_150 = F_107 ( & V_154 ) ;
if ( V_150 < 0 )
goto V_155;
V_150 = F_108 () ;
if ( V_150 )
goto V_156;
V_150 = F_109 () ;
if ( V_150 )
goto V_157;
F_110 () ;
V_150 = F_111 () ;
if ( V_150 )
goto V_158;
F_112 () ;
V_150 = F_95 () ;
if ( V_150 )
goto V_159;
V_150 = F_113 ( & V_160 ) ;
if ( V_150 )
goto V_161;
return 0 ;
V_161:
F_98 ( L_36 , NULL ) ;
F_98 ( L_34 , NULL ) ;
V_159:
F_114 () ;
F_115 () ;
V_158:
F_116 () ;
F_117 () ;
V_157:
F_118 () ;
V_156:
F_119 ( & V_154 ) ;
V_155:
F_120 () ;
return V_150 ;
}
static void T_10 F_121 ( void )
{
F_115 () ;
F_98 ( L_36 , NULL ) ;
F_98 ( L_34 , NULL ) ;
F_116 () ;
F_114 () ;
F_118 () ;
F_117 () ;
F_122 ( & V_160 ) ;
F_119 ( & V_154 ) ;
F_120 () ;
}
