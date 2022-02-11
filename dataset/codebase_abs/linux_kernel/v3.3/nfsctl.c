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
return F_10 ( V_1 , & V_16 ) ;
}
static int F_11 ( struct V_17 * V_18 , void * V_19 )
{
F_12 ( V_18 , L_1 , V_20 , V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
return F_14 ( V_1 , F_11 , NULL ) ;
}
static int F_15 ( struct V_17 * V_18 , void * V_19 )
{
F_12 ( V_18 , V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
return F_14 ( V_1 , F_15 , NULL ) ;
}
static T_1 F_17 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_23 V_24 ;
struct V_25 * V_26 = (struct V_25 * ) & V_24 ;
T_3 V_27 = sizeof( V_24 ) ;
char * V_28 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_28 = V_2 ;
if ( F_18 ( & V_2 , V_28 , V_3 ) < 0 )
return - V_13 ;
if ( F_19 ( V_28 , V_3 , V_26 , V_27 ) == 0 )
return - V_13 ;
return F_20 ( V_26 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_29 V_29 ;
char * V_28 ;
int error ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_28 = V_2 ;
if ( F_18 ( & V_2 , V_28 , V_3 ) < 0 )
return - V_13 ;
error = F_22 ( V_28 , 0 , & V_29 ) ;
if ( error )
return error ;
error = F_23 ( V_29 . V_7 -> V_30 ) ;
F_24 ( & V_29 ) ;
return error ;
}
static T_1 F_25 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_31 , * V_29 ;
int V_32 ( V_33 ) ;
char * V_34 = V_2 ;
int V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_31 = V_34 ;
V_35 = F_18 ( & V_34 , V_31 , V_3 ) ;
if ( V_35 <= 0 )
return - V_13 ;
V_29 = V_31 + V_35 + 1 ;
V_35 = F_18 ( & V_34 , V_29 , V_3 ) ;
if ( V_35 <= 0 )
return - V_13 ;
V_35 = F_26 ( & V_34 , & V_33 ) ;
if ( V_35 )
return V_35 ;
if ( V_33 < V_40 )
return - V_13 ;
if ( V_33 > V_41 )
V_33 = V_41 ;
if ( F_18 ( & V_34 , V_34 , V_3 ) > 0 )
return - V_13 ;
V_37 = F_27 ( V_31 ) ;
if ( ! V_37 )
return - V_42 ;
V_35 = F_28 ( V_37 , V_29 , & V_39 , V_33 ) ;
F_29 ( V_37 ) ;
if ( V_35 )
return V_35 ;
V_34 = V_2 ;
V_35 = V_43 ;
F_30 ( & V_34 , & V_35 , ( char * ) & V_39 . V_44 , V_39 . V_45 ) ;
V_34 [ - 1 ] = '\n' ;
return V_34 - V_2 ;
}
static T_1 F_31 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_34 = V_2 ;
int V_11 ;
if ( V_3 > 0 ) {
int V_46 ;
V_11 = F_26 ( & V_34 , & V_46 ) ;
if ( V_11 )
return V_11 ;
if ( V_46 < 0 )
return - V_13 ;
V_11 = F_32 ( V_47 , V_46 ) ;
if ( V_11 < 0 )
return V_11 ;
} else
V_11 = F_33 () ;
return F_34 ( V_2 , V_43 , L_2 , V_11 ) ;
}
static T_1 F_35 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_34 = V_2 ;
int V_48 ;
int V_11 ;
int V_35 ;
int V_49 ;
int * V_50 ;
F_36 ( & V_51 ) ;
V_49 = F_37 () ;
if ( V_49 == 0 ) {
F_38 ( & V_51 ) ;
strcpy ( V_2 , L_3 ) ;
return strlen ( V_2 ) ;
}
V_50 = F_39 ( V_49 , sizeof( int ) , V_52 ) ;
V_11 = - V_42 ;
if ( V_50 == NULL )
goto V_53;
if ( V_3 > 0 ) {
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_11 = F_26 ( & V_34 , & V_50 [ V_48 ] ) ;
if ( V_11 == - V_54 )
break;
if ( V_11 )
goto V_53;
V_11 = - V_13 ;
if ( V_50 [ V_48 ] < 0 )
goto V_53;
}
V_11 = F_40 ( V_48 , V_50 ) ;
if ( V_11 )
goto V_53;
}
V_11 = F_41 ( V_49 , V_50 ) ;
if ( V_11 )
goto V_53;
V_34 = V_2 ;
V_3 = V_43 ;
for ( V_48 = 0 ; V_48 < V_49 && V_3 > 0 ; V_48 ++ ) {
snprintf ( V_34 , V_3 , L_4 , V_50 [ V_48 ] , ( V_48 == V_49 - 1 ? '\n' : ' ' ) ) ;
V_35 = strlen ( V_34 ) ;
V_3 -= V_35 ;
V_34 += V_35 ;
}
V_11 = V_34 - V_2 ;
V_53:
F_42 ( V_50 ) ;
F_38 ( & V_51 ) ;
return V_11 ;
}
static T_1 F_43 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_34 = V_2 ;
char * V_55 , * V_56 , V_57 ;
int V_35 , V_58 , V_59 ;
unsigned V_60 ;
T_1 V_61 = 0 ;
char * V_62 ;
if ( V_3 > 0 ) {
if ( V_63 )
return - V_64 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_55 = V_34 ;
V_35 = F_18 ( & V_34 , V_55 , V_3 ) ;
if ( V_35 <= 0 ) return - V_13 ;
do {
V_57 = * V_55 ;
if ( V_57 == '+' || V_57 == '-' )
V_58 = F_44 ( ( V_55 + 1 ) , & V_56 , 0 ) ;
else
V_58 = F_44 ( V_55 , & V_56 , 0 ) ;
if ( * V_56 == '.' ) {
if ( V_58 < 4 )
return - V_13 ;
V_60 = F_45 ( V_56 + 1 , NULL , 0 ) ;
if ( V_60 == 0 )
return - V_13 ;
if ( F_46 ( V_60 , V_57 == '-' ?
V_65 : V_66 ) < 0 )
return - V_13 ;
goto V_67;
}
switch( V_58 ) {
case 2 :
case 3 :
case 4 :
F_47 ( V_58 , V_57 == '-' ? V_65 : V_66 ) ;
break;
default:
return - V_13 ;
}
V_67:
V_55 += V_35 + 1 ;
} while ( ( V_35 = F_18 ( & V_34 , V_55 , V_3 ) ) > 0 );
F_48 () ;
}
V_35 = 0 ;
V_62 = L_5 ;
V_59 = V_43 ;
for ( V_58 = 2 ; V_58 <= 4 ; V_58 ++ )
if ( F_47 ( V_58 , V_68 ) ) {
V_35 = snprintf ( V_2 , V_59 , L_6 , V_62 ,
F_47 ( V_58 , V_69 ) ? '+' : '-' ,
V_58 ) ;
V_62 = L_7 ;
if ( V_35 > V_59 )
break;
V_59 -= V_35 ;
V_2 += V_35 ;
V_61 += V_35 ;
}
if ( F_47 ( 4 , V_68 ) )
for ( V_60 = 1 ; V_60 <= V_70 ;
V_60 ++ ) {
V_35 = snprintf ( V_2 , V_59 , L_8 ,
( F_47 ( 4 , V_69 ) &&
F_46 ( V_60 , V_69 ) ) ?
'+' : '-' ,
V_60 ) ;
if ( V_35 > V_59 )
break;
V_59 -= V_35 ;
V_2 += V_35 ;
V_61 += V_35 ;
}
V_35 = snprintf ( V_2 , V_59 , L_9 ) ;
if ( V_35 > V_59 )
return - V_13 ;
return V_61 + V_35 ;
}
static T_1 F_49 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_36 ( & V_51 ) ;
V_11 = F_43 ( V_1 , V_2 , V_3 ) ;
F_38 ( & V_51 ) ;
return V_11 ;
}
static T_1 F_50 ( char * V_2 )
{
if ( V_63 == NULL )
return 0 ;
return F_51 ( V_63 , V_2 , V_43 ) ;
}
static T_1 F_52 ( char * V_2 )
{
char * V_34 = V_2 ;
int V_71 , V_72 ;
V_72 = F_26 ( & V_34 , & V_71 ) ;
if ( V_72 != 0 || V_71 < 0 )
return - V_13 ;
V_72 = F_53 () ;
if ( V_72 != 0 )
return V_72 ;
V_72 = F_54 ( V_63 , V_71 , V_2 , V_43 ) ;
if ( V_72 < 0 ) {
F_55 ( V_63 ) ;
return V_72 ;
}
V_63 -> V_73 -- ;
return V_72 ;
}
static T_1 F_56 ( char * V_2 )
{
char * V_74 ;
int V_35 = 0 ;
V_74 = F_57 ( V_2 + 1 , V_52 ) ;
if ( V_74 == NULL )
return - V_42 ;
if ( V_63 != NULL )
V_35 = F_58 ( V_63 , V_2 ,
V_43 , V_74 ) ;
F_42 ( V_74 ) ;
return V_35 ;
}
static T_1 F_59 ( char * V_2 )
{
char V_75 [ 16 ] ;
struct V_76 * V_77 ;
int V_78 , V_72 ;
if ( sscanf ( V_2 , L_10 , V_75 , & V_78 ) != 2 )
return - V_13 ;
if ( V_78 < 1 || V_78 > V_79 )
return - V_13 ;
V_72 = F_53 () ;
if ( V_72 != 0 )
return V_72 ;
V_72 = F_60 ( V_63 , V_75 , & V_80 ,
V_81 , V_78 , V_82 ) ;
if ( V_72 < 0 )
goto V_83;
V_72 = F_60 ( V_63 , V_75 , & V_80 ,
V_84 , V_78 , V_82 ) ;
if ( V_72 < 0 && V_72 != - V_85 )
goto V_86;
V_63 -> V_73 -- ;
return 0 ;
V_86:
V_77 = F_61 ( V_63 , V_75 , V_81 , V_78 ) ;
if ( V_77 != NULL ) {
F_62 ( V_77 ) ;
F_63 ( V_77 ) ;
}
V_83:
F_55 ( V_63 ) ;
return V_72 ;
}
static T_1 F_64 ( char * V_2 )
{
struct V_76 * V_77 ;
char V_75 [ 16 ] ;
int V_78 ;
if ( sscanf ( & V_2 [ 1 ] , L_10 , V_75 , & V_78 ) != 2 )
return - V_13 ;
if ( V_78 < 1 || V_78 > V_79 || V_63 == NULL )
return - V_13 ;
V_77 = F_61 ( V_63 , V_75 , V_87 , V_78 ) ;
if ( V_77 == NULL )
return - V_88 ;
F_62 ( V_77 ) ;
F_63 ( V_77 ) ;
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
if ( V_3 == 0 )
return F_50 ( V_2 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_52 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isdigit ( V_2 [ 1 ] ) )
return F_56 ( V_2 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_59 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isalpha ( V_2 [ 1 ] ) )
return F_64 ( V_2 ) ;
return - V_13 ;
}
static T_1 F_66 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_36 ( & V_51 ) ;
V_11 = F_65 ( V_1 , V_2 , V_3 ) ;
F_38 ( & V_51 ) ;
return V_11 ;
}
static T_1 F_67 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_34 = V_2 ;
if ( V_3 > 0 ) {
int V_89 ;
int V_11 = F_26 ( & V_34 , & V_89 ) ;
if ( V_11 )
return V_11 ;
if ( V_89 < 1024 )
V_89 = 1024 ;
if ( V_89 > V_90 )
V_89 = V_90 ;
V_89 &= ~ ( 1024 - 1 ) ;
F_36 ( & V_51 ) ;
if ( V_63 ) {
F_38 ( & V_51 ) ;
return - V_64 ;
}
V_91 = V_89 ;
F_38 ( & V_51 ) ;
}
return F_34 ( V_2 , V_43 , L_2 ,
V_91 ) ;
}
static T_1 F_68 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
char * V_34 = V_2 ;
int V_11 , V_48 ;
if ( V_3 > 0 ) {
if ( V_63 )
return - V_64 ;
V_11 = F_26 ( & V_34 , & V_48 ) ;
if ( V_11 )
return V_11 ;
if ( V_48 < 10 || V_48 > 3600 )
return - V_13 ;
* time = V_48 ;
}
return F_34 ( V_2 , V_43 , L_11 , * time ) ;
}
static T_1 F_69 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
T_1 V_11 ;
F_36 ( & V_51 ) ;
V_11 = F_68 ( V_1 , V_2 , V_3 , time ) ;
F_38 ( & V_51 ) ;
return V_11 ;
}
static T_1 F_70 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_69 ( V_1 , V_2 , V_3 , & V_92 ) ;
}
static T_1 F_71 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_69 ( V_1 , V_2 , V_3 , & V_93 ) ;
}
static T_1 F_72 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_34 = V_2 ;
char * V_94 ;
int V_35 , V_95 ;
if ( V_3 > 0 ) {
if ( V_63 )
return - V_64 ;
if ( V_3 > V_96 || V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_94 = V_34 ;
V_35 = F_18 ( & V_34 , V_94 , V_3 ) ;
if ( V_35 <= 0 )
return - V_13 ;
V_95 = F_73 ( V_94 ) ;
if ( V_95 )
return V_95 ;
}
return F_34 ( V_2 , V_43 , L_12 ,
F_74 () ) ;
}
static T_1 F_75 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_36 ( & V_51 ) ;
V_11 = F_72 ( V_1 , V_2 , V_3 ) ;
F_38 ( & V_51 ) ;
return V_11 ;
}
static int F_76 ( struct V_97 * V_98 , void * V_10 , int V_99 )
{
static struct V_100 V_101 [] = {
[ V_102 ] = { L_13 , & V_103 , V_104 } ,
[ V_105 ] = { L_14 ,
& V_106 , V_104 } ,
[ V_107 ] = { L_15 ,
& V_108 , V_109 | V_110 } ,
[ V_111 ] = { L_16 ,
& V_108 , V_109 | V_110 } ,
[ V_112 ] = { L_17 , & V_108 , V_109 | V_110 } ,
[ V_113 ] = { L_18 , & V_108 , V_109 | V_110 } ,
[ V_114 ] = { L_19 , & V_108 , V_109 | V_110 } ,
[ V_115 ] = { L_20 , & V_116 , V_104 } ,
[ V_117 ] = { L_21 , & V_108 , V_109 | V_110 } ,
[ V_118 ] = { L_22 , & V_108 , V_109 | V_104 } ,
[ V_119 ] = { L_23 , & V_108 , V_109 | V_104 } ,
#if F_77 ( V_120 ) || F_77 ( V_121 )
[ V_122 ] = { L_24 , & V_123 , V_104 } ,
#endif
#ifdef F_78
[ V_124 ] = { L_25 , & V_108 , V_109 | V_110 } ,
[ V_125 ] = { L_26 , & V_108 , V_109 | V_110 } ,
[ V_126 ] = { L_27 , & V_108 , V_109 | V_110 } ,
#endif
{ L_5 }
} ;
return F_79 ( V_98 , 0x6e667364 , V_101 ) ;
}
static struct V_7 * F_80 ( struct V_127 * V_128 ,
int V_129 , const char * V_130 , void * V_10 )
{
return F_81 ( V_128 , V_129 , V_10 , F_76 ) ;
}
static int F_82 ( void )
{
struct V_131 * V_132 ;
V_132 = F_83 ( L_28 , NULL ) ;
if ( ! V_132 )
return - V_42 ;
V_132 = F_84 ( L_13 , 0 , V_132 , & V_103 ) ;
if ( ! V_132 )
return - V_42 ;
return 0 ;
}
static int F_82 ( void )
{
return 0 ;
}
static int T_7 F_85 ( void )
{
int V_133 ;
F_86 ( V_134 L_29 ) ;
V_133 = F_87 () ;
if ( V_133 )
return V_133 ;
F_88 () ;
V_133 = F_89 () ;
if ( V_133 )
goto V_135;
F_90 () ;
V_133 = F_91 () ;
if ( V_133 )
goto V_136;
V_133 = F_92 () ;
if ( V_133 )
goto V_137;
F_93 () ;
V_133 = F_94 () ;
if ( V_133 )
goto V_138;
V_133 = F_82 () ;
if ( V_133 )
goto V_139;
V_133 = F_95 ( & V_140 ) ;
if ( V_133 )
goto V_141;
return 0 ;
V_141:
F_96 ( L_30 , NULL ) ;
F_96 ( L_28 , NULL ) ;
V_139:
F_97 () ;
V_138:
F_98 () ;
F_99 () ;
V_137:
F_100 () ;
V_136:
F_101 () ;
F_102 () ;
V_135:
F_103 () ;
return V_133 ;
}
static void T_8 F_104 ( void )
{
F_99 () ;
F_100 () ;
F_96 ( L_30 , NULL ) ;
F_96 ( L_28 , NULL ) ;
F_101 () ;
F_98 () ;
F_97 () ;
F_103 () ;
F_102 () ;
F_105 ( & V_140 ) ;
}
