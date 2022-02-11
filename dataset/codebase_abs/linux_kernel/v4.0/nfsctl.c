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
static inline struct V_12 * F_21 ( struct V_1 * V_1 )
{
return F_2 ( V_1 ) -> V_26 -> V_27 ;
}
static T_1 F_22 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_33 V_34 ;
struct V_35 * V_36 = (struct V_35 * ) & V_34 ;
T_3 V_37 = sizeof( V_34 ) ;
char * V_38 ;
struct V_12 * V_12 = F_21 ( V_1 ) ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_38 = V_2 ;
if ( F_23 ( & V_2 , V_38 , V_3 ) < 0 )
return - V_10 ;
if ( F_24 ( V_12 , V_38 , V_3 , V_36 , V_37 ) == 0 )
return - V_10 ;
return F_25 ( V_36 ) ;
}
static T_1 F_26 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_39 V_39 ;
char * V_38 ;
int error ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_38 = V_2 ;
if ( F_23 ( & V_2 , V_38 , V_3 ) < 0 )
return - V_10 ;
error = F_27 ( V_38 , 0 , & V_39 ) ;
if ( error )
return error ;
error = F_28 ( V_39 . V_40 -> V_41 ) ;
F_29 ( & V_39 ) ;
return error ;
}
static T_1 F_30 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_42 , * V_39 ;
int V_43 ( V_44 ) ;
char * V_45 = V_2 ;
int V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
if ( V_3 == 0 )
return - V_10 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_42 = V_45 ;
V_46 = F_23 ( & V_45 , V_42 , V_3 ) ;
if ( V_46 <= 0 )
return - V_10 ;
V_39 = V_42 + V_46 + 1 ;
V_46 = F_23 ( & V_45 , V_39 , V_3 ) ;
if ( V_46 <= 0 )
return - V_10 ;
V_46 = F_31 ( & V_45 , & V_44 ) ;
if ( V_46 )
return V_46 ;
if ( V_44 < V_51 )
return - V_10 ;
V_44 = F_32 ( V_44 , V_52 ) ;
if ( F_23 ( & V_45 , V_45 , V_3 ) > 0 )
return - V_10 ;
V_48 = F_33 ( V_42 ) ;
if ( ! V_48 )
return - V_53 ;
V_46 = F_34 ( F_21 ( V_1 ) , V_48 , V_39 , & V_50 , V_44 ) ;
F_35 ( V_48 ) ;
if ( V_46 )
return V_46 ;
V_45 = V_2 ;
V_46 = V_54 ;
F_36 ( & V_45 , & V_46 , ( char * ) & V_50 . V_55 , V_50 . V_56 ) ;
V_45 [ - 1 ] = '\n' ;
return V_45 - V_2 ;
}
static T_1 F_37 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_45 = V_2 ;
int V_8 ;
struct V_12 * V_12 = F_21 ( V_1 ) ;
if ( V_3 > 0 ) {
int V_57 ;
V_8 = F_31 ( & V_45 , & V_57 ) ;
if ( V_8 )
return V_8 ;
if ( V_57 < 0 )
return - V_10 ;
V_8 = F_38 ( V_57 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
V_8 = F_39 ( V_12 ) ;
return F_40 ( V_2 , V_54 , L_2 , V_8 ) ;
}
static T_1 F_41 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_45 = V_2 ;
int V_58 ;
int V_8 ;
int V_46 ;
int V_59 ;
int * V_60 ;
struct V_12 * V_12 = F_21 ( V_1 ) ;
F_42 ( & V_61 ) ;
V_59 = F_43 ( V_12 ) ;
if ( V_59 == 0 ) {
F_44 ( & V_61 ) ;
strcpy ( V_2 , L_3 ) ;
return strlen ( V_2 ) ;
}
V_60 = F_45 ( V_59 , sizeof( int ) , V_62 ) ;
V_8 = - V_53 ;
if ( V_60 == NULL )
goto V_63;
if ( V_3 > 0 ) {
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_8 = F_31 ( & V_45 , & V_60 [ V_58 ] ) ;
if ( V_8 == - V_64 )
break;
if ( V_8 )
goto V_63;
V_8 = - V_10 ;
if ( V_60 [ V_58 ] < 0 )
goto V_63;
}
V_8 = F_46 ( V_58 , V_60 , V_12 ) ;
if ( V_8 )
goto V_63;
}
V_8 = F_47 ( V_59 , V_60 , V_12 ) ;
if ( V_8 )
goto V_63;
V_45 = V_2 ;
V_3 = V_54 ;
for ( V_58 = 0 ; V_58 < V_59 && V_3 > 0 ; V_58 ++ ) {
snprintf ( V_45 , V_3 , L_4 , V_60 [ V_58 ] , ( V_58 == V_59 - 1 ? '\n' : ' ' ) ) ;
V_46 = strlen ( V_45 ) ;
V_3 -= V_46 ;
V_45 += V_46 ;
}
V_8 = V_45 - V_2 ;
V_63:
F_48 ( V_60 ) ;
F_44 ( & V_61 ) ;
return V_8 ;
}
static T_1 F_49 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_45 = V_2 ;
char * V_65 , * V_66 , V_67 ;
int V_46 , V_68 , V_69 ;
unsigned V_70 ;
T_1 V_71 = 0 ;
char * V_72 ;
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
if ( V_3 > 0 ) {
if ( V_17 -> V_73 )
return - V_74 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_65 = V_45 ;
V_46 = F_23 ( & V_45 , V_65 , V_3 ) ;
if ( V_46 <= 0 ) return - V_10 ;
do {
V_67 = * V_65 ;
if ( V_67 == '+' || V_67 == '-' )
V_68 = F_50 ( ( V_65 + 1 ) , & V_66 , 0 ) ;
else
V_68 = F_50 ( V_65 , & V_66 , 0 ) ;
if ( * V_66 == '.' ) {
if ( V_68 != 4 )
return - V_10 ;
V_70 = F_51 ( V_66 + 1 , NULL , 0 ) ;
if ( V_70 == 0 )
return - V_10 ;
if ( F_52 ( V_70 , V_67 == '-' ?
V_75 : V_76 ) < 0 )
return - V_10 ;
goto V_77;
}
switch( V_68 ) {
case 2 :
case 3 :
case 4 :
F_53 ( V_68 , V_67 == '-' ? V_75 : V_76 ) ;
break;
default:
return - V_10 ;
}
V_77:
V_65 += V_46 + 1 ;
} while ( ( V_46 = F_23 ( & V_45 , V_65 , V_3 ) ) > 0 );
F_54 () ;
}
V_46 = 0 ;
V_72 = L_5 ;
V_69 = V_54 ;
for ( V_68 = 2 ; V_68 <= 4 ; V_68 ++ )
if ( F_53 ( V_68 , V_78 ) ) {
V_46 = snprintf ( V_2 , V_69 , L_6 , V_72 ,
F_53 ( V_68 , V_79 ) ? '+' : '-' ,
V_68 ) ;
V_72 = L_7 ;
if ( V_46 >= V_69 )
break;
V_69 -= V_46 ;
V_2 += V_46 ;
V_71 += V_46 ;
}
if ( F_53 ( 4 , V_78 ) )
for ( V_70 = 1 ; V_70 <= V_80 ;
V_70 ++ ) {
V_46 = snprintf ( V_2 , V_69 , L_8 ,
( F_53 ( 4 , V_79 ) &&
F_52 ( V_70 , V_79 ) ) ?
'+' : '-' ,
V_70 ) ;
if ( V_46 >= V_69 )
break;
V_69 -= V_46 ;
V_2 += V_46 ;
V_71 += V_46 ;
}
V_46 = snprintf ( V_2 , V_69 , L_9 ) ;
if ( V_46 >= V_69 )
return - V_10 ;
return V_71 + V_46 ;
}
static T_1 F_55 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
F_42 ( & V_61 ) ;
V_8 = F_49 ( V_1 , V_2 , V_3 ) ;
F_44 ( & V_61 ) ;
return V_8 ;
}
static T_1 F_56 ( char * V_2 , struct V_12 * V_12 )
{
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_17 -> V_73 == NULL )
return 0 ;
return F_57 ( V_17 -> V_73 , V_2 , V_54 ) ;
}
static T_1 F_58 ( char * V_2 , struct V_12 * V_12 )
{
char * V_45 = V_2 ;
int V_81 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_13 = F_31 ( & V_45 , & V_81 ) ;
if ( V_13 != 0 || V_81 < 0 )
return - V_10 ;
if ( F_59 ( V_12 , V_81 ) ) {
F_60 ( V_82 L_10 , V_83 ) ;
return - V_10 ;
}
V_13 = F_61 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_62 ( V_17 -> V_73 , V_81 , V_2 , V_54 ) ;
if ( V_13 < 0 ) {
F_63 ( V_12 ) ;
return V_13 ;
}
V_17 -> V_73 -> V_84 -- ;
return V_13 ;
}
static T_1 F_64 ( char * V_2 , struct V_12 * V_12 )
{
char V_85 [ 16 ] ;
struct V_86 * V_87 ;
int V_88 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( sscanf ( V_2 , L_11 , V_85 , & V_88 ) != 2 )
return - V_10 ;
if ( V_88 < 1 || V_88 > V_89 )
return - V_10 ;
V_13 = F_61 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_65 ( V_17 -> V_73 , V_85 , V_12 ,
V_90 , V_88 , V_91 ) ;
if ( V_13 < 0 )
goto V_92;
V_13 = F_65 ( V_17 -> V_73 , V_85 , V_12 ,
V_93 , V_88 , V_91 ) ;
if ( V_13 < 0 && V_13 != - V_94 )
goto V_95;
V_17 -> V_73 -> V_84 -- ;
return 0 ;
V_95:
V_87 = F_66 ( V_17 -> V_73 , V_85 , V_12 , V_90 , V_88 ) ;
if ( V_87 != NULL ) {
F_67 ( V_87 ) ;
F_68 ( V_87 ) ;
}
V_92:
F_63 ( V_12 ) ;
return V_13 ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_12 * V_12 )
{
if ( V_3 == 0 )
return F_56 ( V_2 , V_12 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_58 ( V_2 , V_12 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_64 ( V_2 , V_12 ) ;
return - V_10 ;
}
static T_1 F_70 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
F_42 ( & V_61 ) ;
V_8 = F_69 ( V_1 , V_2 , V_3 , F_21 ( V_1 ) ) ;
F_44 ( & V_61 ) ;
return V_8 ;
}
static T_1 F_71 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_45 = V_2 ;
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
if ( V_3 > 0 ) {
int V_96 ;
int V_8 = F_31 ( & V_45 , & V_96 ) ;
if ( V_8 )
return V_8 ;
V_96 = F_72 ( int , V_96 , 1024 ) ;
V_96 = F_73 ( int , V_96 , V_97 ) ;
V_96 &= ~ ( 1024 - 1 ) ;
F_42 ( & V_61 ) ;
if ( V_17 -> V_73 ) {
F_44 ( & V_61 ) ;
return - V_74 ;
}
V_98 = V_96 ;
F_44 ( & V_61 ) ;
}
return F_40 ( V_2 , V_54 , L_2 ,
V_98 ) ;
}
static T_1 F_74 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_45 = V_2 ;
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
unsigned int V_99 = V_17 -> V_100 ;
if ( V_3 > 0 ) {
int V_8 = F_75 ( & V_45 , & V_99 ) ;
if ( V_8 )
return V_8 ;
V_17 -> V_100 = V_99 ;
}
return F_40 ( V_2 , V_54 , L_12 , V_99 ) ;
}
static T_1 F_76 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_16 * V_17 )
{
char * V_45 = V_2 ;
int V_8 , V_58 ;
if ( V_3 > 0 ) {
if ( V_17 -> V_73 )
return - V_74 ;
V_8 = F_31 ( & V_45 , & V_58 ) ;
if ( V_8 )
return V_8 ;
if ( V_58 < 10 || V_58 > 3600 )
return - V_10 ;
* time = V_58 ;
}
return F_40 ( V_2 , V_54 , L_13 , * time ) ;
}
static T_1 F_77 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_16 * V_17 )
{
T_1 V_8 ;
F_42 ( & V_61 ) ;
V_8 = F_76 ( V_1 , V_2 , V_3 , time , V_17 ) ;
F_44 ( & V_61 ) ;
return V_8 ;
}
static T_1 F_78 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
return F_77 ( V_1 , V_2 , V_3 , & V_17 -> V_101 , V_17 ) ;
}
static T_1 F_79 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
return F_77 ( V_1 , V_2 , V_3 , & V_17 -> V_102 , V_17 ) ;
}
static T_1 F_80 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_16 * V_17 )
{
char * V_45 = V_2 ;
char * V_103 ;
int V_46 , V_104 ;
if ( V_3 > 0 ) {
if ( V_17 -> V_73 )
return - V_74 ;
if ( V_3 > V_105 || V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_103 = V_45 ;
V_46 = F_23 ( & V_45 , V_103 , V_3 ) ;
if ( V_46 <= 0 )
return - V_10 ;
V_104 = F_81 ( V_103 ) ;
if ( V_104 )
return V_104 ;
}
return F_40 ( V_2 , V_54 , L_14 ,
F_82 () ) ;
}
static T_1 F_83 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
F_42 ( & V_61 ) ;
V_8 = F_80 ( V_1 , V_2 , V_3 , V_17 ) ;
F_44 ( & V_61 ) ;
return V_8 ;
}
static T_1 F_84 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_16 * V_17 = F_11 ( F_21 ( V_1 ) , V_18 ) ;
if ( V_3 > 0 ) {
switch( V_2 [ 0 ] ) {
case 'Y' :
case 'y' :
case '1' :
F_85 ( V_17 ) ;
break;
default:
return - V_10 ;
}
}
return F_40 ( V_2 , V_54 , L_15 ,
V_17 -> V_106 ? 'Y' : 'N' ) ;
}
static int F_86 ( struct V_107 * V_108 , void * V_7 , int V_109 )
{
static struct V_110 V_111 [] = {
[ V_112 ] = { L_16 , & V_113 , V_114 } ,
[ V_115 ] = { L_17 ,
& V_116 , V_114 } ,
[ V_117 ] = { L_18 ,
& V_118 , V_119 | V_120 } ,
[ V_121 ] = { L_19 ,
& V_118 , V_119 | V_120 } ,
[ V_122 ] = { L_20 , & V_118 , V_119 | V_120 } ,
[ V_123 ] = { L_21 , & V_118 , V_119 | V_120 } ,
[ V_124 ] = { L_22 , & V_118 , V_119 | V_120 } ,
[ V_125 ] = { L_23 , & V_126 , V_114 } ,
[ V_127 ] = { L_24 , & V_128 , V_114 } ,
[ V_129 ] = { L_25 , & V_118 , V_119 | V_120 } ,
[ V_130 ] = { L_26 , & V_118 , V_119 | V_114 } ,
[ V_131 ] = { L_27 , & V_118 , V_119 | V_114 } ,
[ V_132 ] = { L_28 , & V_118 , V_119 | V_114 } ,
#if F_87 ( V_133 ) || F_87 ( V_134 )
[ V_135 ] = { L_29 , & V_136 , V_114 } ,
#endif
#ifdef F_88
[ V_137 ] = { L_30 , & V_118 , V_119 | V_120 } ,
[ V_138 ] = { L_31 , & V_118 , V_119 | V_120 } ,
[ V_139 ] = { L_32 , & V_118 , V_119 | V_120 } ,
[ V_140 ] = { L_33 , & V_118 , V_119 | V_114 } ,
#endif
{ L_5 }
} ;
struct V_12 * V_12 = V_7 ;
int V_141 ;
V_141 = F_89 ( V_108 , 0x6e667364 , V_111 ) ;
if ( V_141 )
return V_141 ;
V_108 -> V_27 = F_90 ( V_12 ) ;
return 0 ;
}
static struct V_40 * F_91 ( struct V_142 * V_143 ,
int V_144 , const char * V_145 , void * V_7 )
{
return F_92 ( V_143 , V_144 , V_23 -> V_24 -> V_25 , F_86 ) ;
}
static void F_93 ( struct V_107 * V_108 )
{
struct V_12 * V_12 = V_108 -> V_27 ;
F_94 ( V_108 ) ;
F_95 ( V_12 ) ;
}
static int F_96 ( void )
{
struct V_146 * V_147 ;
V_147 = F_97 ( L_34 , NULL ) ;
if ( ! V_147 )
return - V_53 ;
V_147 = F_98 ( L_16 , 0 , V_147 ,
& V_148 ) ;
if ( ! V_147 ) {
F_99 ( L_34 , NULL ) ;
return - V_53 ;
}
return 0 ;
}
static int F_96 ( void )
{
return 0 ;
}
static T_7 int F_100 ( struct V_12 * V_12 )
{
int V_149 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_149 = F_101 ( V_12 ) ;
if ( V_149 )
goto V_150;
V_149 = F_102 ( V_12 ) ;
if ( V_149 )
goto V_151;
V_17 -> V_101 = 90 ;
V_17 -> V_102 = 90 ;
return 0 ;
V_151:
F_103 ( V_12 ) ;
V_150:
return V_149 ;
}
static T_8 void F_104 ( struct V_12 * V_12 )
{
F_105 ( V_12 ) ;
F_103 ( V_12 ) ;
}
static int T_9 F_106 ( void )
{
int V_149 ;
F_60 ( V_152 L_35 ) ;
V_149 = F_107 () ;
if ( V_149 )
return V_149 ;
V_149 = F_108 ( & V_153 ) ;
if ( V_149 < 0 )
goto V_154;
V_149 = F_109 () ;
if ( V_149 )
goto V_155;
V_149 = F_110 () ;
if ( V_149 )
goto V_156;
V_149 = F_111 () ;
if ( V_149 )
goto V_157;
F_112 () ;
V_149 = F_113 () ;
if ( V_149 )
goto V_158;
F_114 () ;
V_149 = F_96 () ;
if ( V_149 )
goto V_159;
V_149 = F_115 ( & V_160 ) ;
if ( V_149 )
goto V_161;
return 0 ;
V_161:
F_99 ( L_36 , NULL ) ;
F_99 ( L_34 , NULL ) ;
V_159:
F_116 () ;
F_117 () ;
V_158:
F_118 () ;
F_119 () ;
V_157:
F_120 () ;
V_156:
F_121 () ;
V_155:
F_122 ( & V_153 ) ;
V_154:
F_123 () ;
return V_149 ;
}
static void T_10 F_124 ( void )
{
F_117 () ;
F_99 ( L_36 , NULL ) ;
F_99 ( L_34 , NULL ) ;
F_118 () ;
F_116 () ;
F_121 () ;
F_120 () ;
F_119 () ;
F_125 ( & V_160 ) ;
F_122 ( & V_153 ) ;
F_123 () ;
}
