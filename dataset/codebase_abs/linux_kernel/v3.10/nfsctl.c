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
if ( V_45 > V_53 )
V_45 = V_53 ;
if ( F_22 ( & V_46 , V_46 , V_3 ) > 0 )
return - V_10 ;
V_49 = F_31 ( V_43 ) ;
if ( ! V_49 )
return - V_54 ;
V_47 = F_32 ( V_12 , V_49 , V_41 , & V_51 , V_45 ) ;
F_33 ( V_49 ) ;
if ( V_47 )
return V_47 ;
V_46 = V_2 ;
V_47 = V_55 ;
F_34 ( & V_46 , & V_47 , ( char * ) & V_51 . V_56 , V_51 . V_57 ) ;
V_46 [ - 1 ] = '\n' ;
return V_46 - V_2 ;
}
static T_1 F_35 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
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
V_8 = F_36 ( V_58 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
V_8 = F_37 ( V_12 ) ;
return F_38 ( V_2 , V_55 , L_2 , V_8 ) ;
}
static T_1 F_39 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
int V_59 ;
int V_8 ;
int V_47 ;
int V_60 ;
int * V_61 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
F_40 ( & V_62 ) ;
V_60 = F_41 ( V_12 ) ;
if ( V_60 == 0 ) {
F_42 ( & V_62 ) ;
strcpy ( V_2 , L_3 ) ;
return strlen ( V_2 ) ;
}
V_61 = F_43 ( V_60 , sizeof( int ) , V_63 ) ;
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
V_8 = F_44 ( V_59 , V_61 , V_12 ) ;
if ( V_8 )
goto V_64;
}
V_8 = F_45 ( V_60 , V_61 , V_12 ) ;
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
F_46 ( V_61 ) ;
F_42 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_47 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
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
V_69 = F_48 ( ( V_66 + 1 ) , & V_67 , 0 ) ;
else
V_69 = F_48 ( V_66 , & V_67 , 0 ) ;
if ( * V_67 == '.' ) {
if ( V_69 != 4 )
return - V_10 ;
V_71 = F_49 ( V_67 + 1 , NULL , 0 ) ;
if ( V_71 == 0 )
return - V_10 ;
if ( F_50 ( V_71 , V_68 == '-' ?
V_76 : V_77 ) < 0 )
return - V_10 ;
goto V_78;
}
switch( V_69 ) {
case 2 :
case 3 :
case 4 :
F_51 ( V_69 , V_68 == '-' ? V_76 : V_77 ) ;
break;
default:
return - V_10 ;
}
V_78:
V_66 += V_47 + 1 ;
} while ( ( V_47 = F_22 ( & V_46 , V_66 , V_3 ) ) > 0 );
F_52 () ;
}
V_47 = 0 ;
V_73 = L_5 ;
V_70 = V_55 ;
for ( V_69 = 2 ; V_69 <= 4 ; V_69 ++ )
if ( F_51 ( V_69 , V_79 ) ) {
V_47 = snprintf ( V_2 , V_70 , L_6 , V_73 ,
F_51 ( V_69 , V_80 ) ? '+' : '-' ,
V_69 ) ;
V_73 = L_7 ;
if ( V_47 > V_70 )
break;
V_70 -= V_47 ;
V_2 += V_47 ;
V_72 += V_47 ;
}
if ( F_51 ( 4 , V_79 ) )
for ( V_71 = 1 ; V_71 <= V_81 ;
V_71 ++ ) {
V_47 = snprintf ( V_2 , V_70 , L_8 ,
( F_51 ( 4 , V_80 ) &&
F_50 ( V_71 , V_80 ) ) ?
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
static T_1 F_53 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
F_40 ( & V_62 ) ;
V_8 = F_47 ( V_1 , V_2 , V_3 ) ;
F_42 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_54 ( char * V_2 , struct V_12 * V_12 )
{
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_17 -> V_74 == NULL )
return 0 ;
return F_55 ( V_17 -> V_74 , V_2 , V_55 ) ;
}
static T_1 F_56 ( char * V_2 , struct V_12 * V_12 )
{
char * V_46 = V_2 ;
int V_82 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_13 = F_30 ( & V_46 , & V_82 ) ;
if ( V_13 != 0 || V_82 < 0 )
return - V_10 ;
V_13 = F_57 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_58 ( V_17 -> V_74 , V_82 , V_2 , V_55 ) ;
if ( V_13 < 0 ) {
F_59 ( V_12 ) ;
return V_13 ;
}
V_17 -> V_74 -> V_83 -- ;
return V_13 ;
}
static T_1 F_60 ( char * V_2 , struct V_12 * V_12 )
{
char V_84 [ 16 ] ;
struct V_85 * V_86 ;
int V_87 , V_13 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( sscanf ( V_2 , L_10 , V_84 , & V_87 ) != 2 )
return - V_10 ;
if ( V_87 < 1 || V_87 > V_88 )
return - V_10 ;
V_13 = F_57 ( V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_61 ( V_17 -> V_74 , V_84 , V_12 ,
V_89 , V_87 , V_90 ) ;
if ( V_13 < 0 )
goto V_91;
V_13 = F_61 ( V_17 -> V_74 , V_84 , V_12 ,
V_92 , V_87 , V_90 ) ;
if ( V_13 < 0 && V_13 != - V_93 )
goto V_94;
V_17 -> V_74 -> V_83 -- ;
return 0 ;
V_94:
V_86 = F_62 ( V_17 -> V_74 , V_84 , V_12 , V_89 , V_87 ) ;
if ( V_86 != NULL ) {
F_63 ( V_86 ) ;
F_64 ( V_86 ) ;
}
V_91:
F_59 ( V_12 ) ;
return V_13 ;
}
static T_1 F_65 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_12 * V_12 )
{
if ( V_3 == 0 )
return F_54 ( V_2 , V_12 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_56 ( V_2 , V_12 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_60 ( V_2 , V_12 ) ;
return - V_10 ;
}
static T_1 F_66 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
F_40 ( & V_62 ) ;
V_8 = F_65 ( V_1 , V_2 , V_3 , V_12 ) ;
F_42 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_67 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_46 = V_2 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
if ( V_3 > 0 ) {
int V_95 ;
int V_8 = F_30 ( & V_46 , & V_95 ) ;
if ( V_8 )
return V_8 ;
if ( V_95 < 1024 )
V_95 = 1024 ;
if ( V_95 > V_96 )
V_95 = V_96 ;
V_95 &= ~ ( 1024 - 1 ) ;
F_40 ( & V_62 ) ;
if ( V_17 -> V_74 ) {
F_42 ( & V_62 ) ;
return - V_75 ;
}
V_97 = V_95 ;
F_42 ( & V_62 ) ;
}
return F_38 ( V_2 , V_55 , L_2 ,
V_97 ) ;
}
static T_1 F_68 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
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
return F_38 ( V_2 , V_55 , L_11 , * time ) ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
T_6 * time , struct V_16 * V_17 )
{
T_1 V_8 ;
F_40 ( & V_62 ) ;
V_8 = F_68 ( V_1 , V_2 , V_3 , time , V_17 ) ;
F_42 ( & V_62 ) ;
return V_8 ;
}
static T_1 F_70 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
return F_69 ( V_1 , V_2 , V_3 , & V_17 -> V_98 , V_17 ) ;
}
static T_1 F_71 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
return F_69 ( V_1 , V_2 , V_3 , & V_17 -> V_99 , V_17 ) ;
}
static T_1 F_72 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 ,
struct V_16 * V_17 )
{
char * V_46 = V_2 ;
char * V_100 ;
int V_47 , V_101 ;
if ( V_3 > 0 ) {
if ( V_17 -> V_74 )
return - V_75 ;
if ( V_3 > V_102 || V_2 [ V_3 - 1 ] != '\n' )
return - V_10 ;
V_2 [ V_3 - 1 ] = 0 ;
V_100 = V_46 ;
V_47 = F_22 ( & V_46 , V_100 , V_3 ) ;
if ( V_47 <= 0 )
return - V_10 ;
V_101 = F_73 ( V_100 ) ;
if ( V_101 )
return V_101 ;
}
return F_38 ( V_2 , V_55 , L_12 ,
F_74 () ) ;
}
static T_1 F_75 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_8 ;
struct V_12 * V_12 = V_1 -> V_39 -> V_40 -> V_27 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
F_40 ( & V_62 ) ;
V_8 = F_72 ( V_1 , V_2 , V_3 , V_17 ) ;
F_42 ( & V_62 ) ;
return V_8 ;
}
static int F_76 ( struct V_103 * V_104 , void * V_7 , int V_105 )
{
static struct V_106 V_107 [] = {
[ V_108 ] = { L_13 , & V_109 , V_110 } ,
[ V_111 ] = { L_14 ,
& V_112 , V_110 } ,
[ V_113 ] = { L_15 ,
& V_114 , V_115 | V_116 } ,
[ V_117 ] = { L_16 ,
& V_114 , V_115 | V_116 } ,
[ V_118 ] = { L_17 , & V_114 , V_115 | V_116 } ,
[ V_119 ] = { L_18 , & V_114 , V_115 | V_116 } ,
[ V_120 ] = { L_19 , & V_114 , V_115 | V_116 } ,
[ V_121 ] = { L_20 , & V_122 , V_110 } ,
[ V_123 ] = { L_21 , & V_124 , V_110 } ,
[ V_125 ] = { L_22 , & V_114 , V_115 | V_116 } ,
[ V_126 ] = { L_23 , & V_114 , V_115 | V_110 } ,
[ V_127 ] = { L_24 , & V_114 , V_115 | V_110 } ,
#if F_77 ( V_128 ) || F_77 ( V_129 )
[ V_130 ] = { L_25 , & V_131 , V_110 } ,
#endif
#ifdef F_78
[ V_132 ] = { L_26 , & V_114 , V_115 | V_116 } ,
[ V_133 ] = { L_27 , & V_114 , V_115 | V_116 } ,
[ V_134 ] = { L_28 , & V_114 , V_115 | V_116 } ,
#endif
{ L_5 }
} ;
struct V_12 * V_12 = V_7 ;
int V_135 ;
V_135 = F_79 ( V_104 , 0x6e667364 , V_107 ) ;
if ( V_135 )
return V_135 ;
V_104 -> V_27 = F_80 ( V_12 ) ;
return 0 ;
}
static struct V_42 * F_81 ( struct V_136 * V_137 ,
int V_138 , const char * V_139 , void * V_7 )
{
return F_82 ( V_137 , V_138 , V_23 -> V_24 -> V_25 , F_76 ) ;
}
static void F_83 ( struct V_103 * V_104 )
{
struct V_12 * V_12 = V_104 -> V_27 ;
F_84 ( V_104 ) ;
F_85 ( V_12 ) ;
}
static int F_86 ( void )
{
struct V_140 * V_141 ;
V_141 = F_87 ( L_29 , NULL ) ;
if ( ! V_141 )
return - V_54 ;
V_141 = F_88 ( L_13 , 0 , V_141 ,
& V_142 ) ;
if ( ! V_141 ) {
F_89 ( L_29 , NULL ) ;
return - V_54 ;
}
return 0 ;
}
static int F_86 ( void )
{
return 0 ;
}
static T_7 int F_90 ( struct V_12 * V_12 )
{
int V_143 ;
struct V_16 * V_17 = F_11 ( V_12 , V_18 ) ;
V_143 = F_91 ( V_12 ) ;
if ( V_143 )
goto V_144;
V_143 = F_92 ( V_12 ) ;
if ( V_143 )
goto V_145;
V_17 -> V_98 = 90 ;
V_17 -> V_99 = 90 ;
return 0 ;
V_145:
F_93 ( V_12 ) ;
V_144:
return V_143 ;
}
static T_8 void F_94 ( struct V_12 * V_12 )
{
F_95 ( V_12 ) ;
F_93 ( V_12 ) ;
}
static int T_9 F_96 ( void )
{
int V_143 ;
F_97 ( V_146 L_30 ) ;
V_143 = F_98 () ;
if ( V_143 )
return V_143 ;
V_143 = F_99 ( & V_147 ) ;
if ( V_143 < 0 )
goto V_148;
V_143 = F_100 () ;
if ( V_143 )
goto V_149;
F_101 () ;
V_143 = F_102 () ;
if ( V_143 )
goto V_150;
F_103 () ;
V_143 = F_104 () ;
if ( V_143 )
goto V_151;
F_105 () ;
V_143 = F_86 () ;
if ( V_143 )
goto V_152;
V_143 = F_106 ( & V_153 ) ;
if ( V_143 )
goto V_154;
return 0 ;
V_154:
F_89 ( L_31 , NULL ) ;
F_89 ( L_29 , NULL ) ;
V_152:
F_107 () ;
F_108 () ;
V_151:
F_109 () ;
F_110 () ;
V_150:
F_111 () ;
V_149:
F_112 ( & V_147 ) ;
V_148:
F_113 () ;
return V_143 ;
}
static void T_10 F_114 ( void )
{
F_108 () ;
F_89 ( L_31 , NULL ) ;
F_89 ( L_29 , NULL ) ;
F_109 () ;
F_107 () ;
F_111 () ;
F_110 () ;
F_115 ( & V_153 ) ;
F_112 ( & V_147 ) ;
F_113 () ;
}
