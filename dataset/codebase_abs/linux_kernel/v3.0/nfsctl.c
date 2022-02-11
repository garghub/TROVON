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
#ifdef F_8
static int V_14 ;
if ( V_1 -> V_15 -> V_16 . V_17 [ 0 ] == '.' && ! V_14 ) {
F_9 ( V_18
L_1
L_2 ,
V_19 -> V_20 , V_1 -> V_15 -> V_16 . V_17 ) ;
V_14 = 1 ;
}
#endif
if ( ! V_1 -> V_21 ) {
T_1 V_11 = F_1 ( V_1 , V_2 , 0 , V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return F_10 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_11 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_12 ( V_1 , & V_23 ) ;
}
static int F_13 ( struct V_24 * V_25 , void * V_26 )
{
F_14 ( V_25 , L_3 , V_27 , V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_16 ( V_1 , F_13 , NULL ) ;
}
static int F_17 ( struct V_24 * V_25 , void * V_26 )
{
F_14 ( V_25 , V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return F_16 ( V_1 , F_17 , NULL ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_30 * V_10 ;
int V_31 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_30 * ) V_2 ;
V_31 = F_20 ( V_10 -> V_32 , V_10 -> V_33 ) ;
if ( V_31 < 0 )
return V_31 ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_34 * V_10 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_34 * ) V_2 ;
return F_22 ( V_10 ) ;
}
static T_1 F_23 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_34 * V_10 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_34 * ) V_2 ;
return F_24 ( V_10 ) ;
}
static T_1 F_25 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_35 * V_10 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_35 * ) V_2 ;
return F_26 ( V_10 ) ;
}
static T_1 F_27 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_35 * V_10 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_35 * ) V_2 ;
return F_28 ( V_10 ) ;
}
static T_1 F_29 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_36 * V_10 ;
struct V_37 * sin ;
struct V_38 * V_39 ;
int V_31 = 0 ;
struct V_40 * V_41 ;
struct V_42 V_43 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_36 * ) V_2 ;
V_31 = - V_44 ;
if ( V_10 -> V_45 . V_46 != V_47 )
goto V_48;
sin = (struct V_37 * ) & V_10 -> V_45 ;
if ( V_10 -> V_49 > V_50 )
V_10 -> V_49 = V_50 ;
V_41 = (struct V_40 * ) V_2 ;
F_30 () ;
F_31 ( sin -> V_51 . V_52 , & V_43 ) ;
V_39 = F_32 ( & V_53 , & V_43 ) ;
if ( ! V_39 )
V_31 = - V_54 ;
else {
V_31 = F_33 ( V_39 , V_10 -> V_55 , V_41 , V_10 -> V_49 ) ;
F_34 ( V_39 ) ;
}
F_35 () ;
if ( V_31 == 0 )
V_31 = V_41 -> V_56 + F_36 ( struct V_40 , V_57 ) ;
V_48:
return V_31 ;
}
static T_1 F_37 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_58 * V_10 ;
struct V_37 * sin ;
struct V_38 * V_39 ;
int V_31 = 0 ;
struct V_40 V_59 ;
char * V_41 ;
struct V_42 V_43 ;
if ( V_3 < sizeof( * V_10 ) )
return - V_13 ;
V_10 = (struct V_58 * ) V_2 ;
V_31 = - V_44 ;
if ( V_10 -> V_45 . V_46 != V_47 )
goto V_48;
V_31 = - V_13 ;
if ( V_10 -> V_60 < 2 || V_10 -> V_60 > V_61 )
goto V_48;
V_41 = V_2 ;
sin = (struct V_37 * ) & V_10 -> V_45 ;
F_30 () ;
F_31 ( sin -> V_51 . V_52 , & V_43 ) ;
V_39 = F_32 ( & V_53 , & V_43 ) ;
if ( ! V_39 )
V_31 = - V_54 ;
else {
V_31 = F_33 ( V_39 , V_10 -> V_55 , & V_59 , V_62 ) ;
F_34 ( V_39 ) ;
}
F_35 () ;
if ( V_31 == 0 ) {
memset ( V_41 , 0 , V_62 ) ;
memcpy ( V_41 , & V_59 . V_57 , V_59 . V_56 ) ;
V_31 = V_62 ;
}
V_48:
return V_31 ;
}
static T_1 F_38 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_63 V_64 ;
struct V_65 * V_66 = (struct V_65 * ) & V_64 ;
T_3 V_67 = sizeof( V_64 ) ;
char * V_68 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_68 = V_2 ;
if ( F_39 ( & V_2 , V_68 , V_3 ) < 0 )
return - V_13 ;
if ( F_40 ( V_68 , V_3 , V_66 , V_67 ) == 0 )
return - V_13 ;
return F_41 ( V_66 ) ;
}
static T_1 F_42 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
struct V_69 V_69 ;
char * V_68 ;
int error ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_68 = V_2 ;
if ( F_39 ( & V_2 , V_68 , V_3 ) < 0 )
return - V_13 ;
error = F_43 ( V_68 , 0 , & V_69 ) ;
if ( error )
return error ;
error = F_44 ( V_69 . V_70 -> V_71 ) ;
F_45 ( & V_69 ) ;
return error ;
}
static T_1 F_46 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_72 , * V_69 ;
int V_73 ( V_74 ) ;
char * V_75 = V_2 ;
int V_76 ;
struct V_38 * V_77 ;
struct V_40 V_59 ;
if ( V_3 == 0 )
return - V_13 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_72 = V_75 ;
V_76 = F_39 ( & V_75 , V_72 , V_3 ) ;
if ( V_76 <= 0 )
return - V_13 ;
V_69 = V_72 + V_76 + 1 ;
V_76 = F_39 ( & V_75 , V_69 , V_3 ) ;
if ( V_76 <= 0 )
return - V_13 ;
V_76 = F_47 ( & V_75 , & V_74 ) ;
if ( V_76 )
return V_76 ;
if ( V_74 < V_62 )
return - V_13 ;
if ( V_74 > V_50 )
V_74 = V_50 ;
if ( F_39 ( & V_75 , V_75 , V_3 ) > 0 )
return - V_13 ;
V_77 = F_48 ( V_72 ) ;
if ( ! V_77 )
return - V_78 ;
V_76 = F_33 ( V_77 , V_69 , & V_59 , V_74 ) ;
F_34 ( V_77 ) ;
if ( V_76 )
return V_76 ;
V_75 = V_2 ;
V_76 = V_79 ;
F_49 ( & V_75 , & V_76 , ( char * ) & V_59 . V_57 , V_59 . V_56 ) ;
V_75 [ - 1 ] = '\n' ;
return V_75 - V_2 ;
}
static T_1 F_50 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_75 = V_2 ;
int V_11 ;
if ( V_3 > 0 ) {
int V_80 ;
V_11 = F_47 ( & V_75 , & V_80 ) ;
if ( V_11 )
return V_11 ;
if ( V_80 < 0 )
return - V_13 ;
V_11 = F_20 ( V_81 , V_80 ) ;
if ( V_11 < 0 )
return V_11 ;
} else
V_11 = F_51 () ;
return F_52 ( V_2 , V_79 , L_4 , V_11 ) ;
}
static T_1 F_53 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_75 = V_2 ;
int V_82 ;
int V_11 ;
int V_76 ;
int V_83 ;
int * V_84 ;
F_54 ( & V_85 ) ;
V_83 = F_55 () ;
if ( V_83 == 0 ) {
F_56 ( & V_85 ) ;
strcpy ( V_2 , L_5 ) ;
return strlen ( V_2 ) ;
}
V_84 = F_57 ( V_83 , sizeof( int ) , V_86 ) ;
V_11 = - V_78 ;
if ( V_84 == NULL )
goto V_87;
if ( V_3 > 0 ) {
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ ) {
V_11 = F_47 ( & V_75 , & V_84 [ V_82 ] ) ;
if ( V_11 == - V_88 )
break;
if ( V_11 )
goto V_87;
V_11 = - V_13 ;
if ( V_84 [ V_82 ] < 0 )
goto V_87;
}
V_11 = F_58 ( V_82 , V_84 ) ;
if ( V_11 )
goto V_87;
}
V_11 = F_59 ( V_83 , V_84 ) ;
if ( V_11 )
goto V_87;
V_75 = V_2 ;
V_3 = V_79 ;
for ( V_82 = 0 ; V_82 < V_83 && V_3 > 0 ; V_82 ++ ) {
snprintf ( V_75 , V_3 , L_6 , V_84 [ V_82 ] , ( V_82 == V_83 - 1 ? '\n' : ' ' ) ) ;
V_76 = strlen ( V_75 ) ;
V_3 -= V_76 ;
V_75 += V_76 ;
}
V_11 = V_75 - V_2 ;
V_87:
F_60 ( V_84 ) ;
F_56 ( & V_85 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_75 = V_2 ;
char * V_89 , * V_90 , V_91 ;
int V_76 , V_92 , V_93 ;
unsigned V_94 ;
T_1 V_95 = 0 ;
char * V_96 ;
if ( V_3 > 0 ) {
if ( V_97 )
return - V_98 ;
if ( V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_89 = V_75 ;
V_76 = F_39 ( & V_75 , V_89 , V_3 ) ;
if ( V_76 <= 0 ) return - V_13 ;
do {
V_91 = * V_89 ;
if ( V_91 == '+' || V_91 == '-' )
V_92 = F_62 ( ( V_89 + 1 ) , & V_90 , 0 ) ;
else
V_92 = F_62 ( V_89 , & V_90 , 0 ) ;
if ( * V_90 == '.' ) {
if ( V_92 < 4 )
return - V_13 ;
V_94 = F_63 ( V_90 + 1 , NULL , 0 ) ;
if ( V_94 == 0 )
return - V_13 ;
if ( F_64 ( V_94 , V_91 == '-' ?
V_99 : V_100 ) < 0 )
return - V_13 ;
goto V_101;
}
switch( V_92 ) {
case 2 :
case 3 :
case 4 :
F_65 ( V_92 , V_91 == '-' ? V_99 : V_100 ) ;
break;
default:
return - V_13 ;
}
V_101:
V_89 += V_76 + 1 ;
} while ( ( V_76 = F_39 ( & V_75 , V_89 , V_3 ) ) > 0 );
F_66 () ;
}
V_76 = 0 ;
V_96 = L_7 ;
V_93 = V_79 ;
for ( V_92 = 2 ; V_92 <= 4 ; V_92 ++ )
if ( F_65 ( V_92 , V_102 ) ) {
V_76 = snprintf ( V_2 , V_93 , L_8 , V_96 ,
F_65 ( V_92 , V_103 ) ? '+' : '-' ,
V_92 ) ;
V_96 = L_9 ;
if ( V_76 > V_93 )
break;
V_93 -= V_76 ;
V_2 += V_76 ;
V_95 += V_76 ;
}
if ( F_65 ( 4 , V_102 ) )
for ( V_94 = 1 ; V_94 <= V_104 ;
V_94 ++ ) {
V_76 = snprintf ( V_2 , V_93 , L_10 ,
( F_65 ( 4 , V_103 ) &&
F_64 ( V_94 , V_103 ) ) ?
'+' : '-' ,
V_94 ) ;
if ( V_76 > V_93 )
break;
V_93 -= V_76 ;
V_2 += V_76 ;
V_95 += V_76 ;
}
V_76 = snprintf ( V_2 , V_93 , L_11 ) ;
if ( V_76 > V_93 )
return - V_13 ;
return V_95 + V_76 ;
}
static T_1 F_67 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_54 ( & V_85 ) ;
V_11 = F_61 ( V_1 , V_2 , V_3 ) ;
F_56 ( & V_85 ) ;
return V_11 ;
}
static T_1 F_68 ( char * V_2 )
{
if ( V_97 == NULL )
return 0 ;
return F_69 ( V_97 , V_2 , V_79 ) ;
}
static T_1 F_70 ( char * V_2 )
{
char * V_75 = V_2 ;
int V_105 , V_31 ;
V_31 = F_47 ( & V_75 , & V_105 ) ;
if ( V_31 != 0 || V_105 < 0 )
return - V_13 ;
V_31 = F_71 () ;
if ( V_31 != 0 )
return V_31 ;
V_31 = F_72 ( V_97 , V_105 , V_2 , V_79 ) ;
if ( V_31 < 0 ) {
F_73 ( V_97 ) ;
return V_31 ;
}
V_97 -> V_106 -- ;
return V_31 ;
}
static T_1 F_74 ( char * V_2 )
{
char * V_107 ;
int V_76 = 0 ;
V_107 = F_75 ( V_2 + 1 , V_86 ) ;
if ( V_107 == NULL )
return - V_78 ;
if ( V_97 != NULL )
V_76 = F_76 ( V_97 , V_2 ,
V_79 , V_107 ) ;
F_60 ( V_107 ) ;
return V_76 ;
}
static T_1 F_77 ( char * V_2 )
{
char V_108 [ 16 ] ;
struct V_109 * V_110 ;
int V_111 , V_31 ;
if ( sscanf ( V_2 , L_12 , V_108 , & V_111 ) != 2 )
return - V_13 ;
if ( V_111 < 1 || V_111 > V_112 )
return - V_13 ;
V_31 = F_71 () ;
if ( V_31 != 0 )
return V_31 ;
V_31 = F_78 ( V_97 , V_108 , & V_53 ,
V_113 , V_111 , V_114 ) ;
if ( V_31 < 0 )
goto V_115;
V_31 = F_78 ( V_97 , V_108 , & V_53 ,
V_116 , V_111 , V_114 ) ;
if ( V_31 < 0 && V_31 != - V_117 )
goto V_118;
V_97 -> V_106 -- ;
return 0 ;
V_118:
V_110 = F_79 ( V_97 , V_108 , V_113 , V_111 ) ;
if ( V_110 != NULL ) {
F_80 ( V_110 ) ;
F_81 ( V_110 ) ;
}
V_115:
F_73 ( V_97 ) ;
return V_31 ;
}
static T_1 F_82 ( char * V_2 )
{
struct V_109 * V_110 ;
char V_108 [ 16 ] ;
int V_111 ;
if ( sscanf ( & V_2 [ 1 ] , L_12 , V_108 , & V_111 ) != 2 )
return - V_13 ;
if ( V_111 < 1 || V_111 > V_112 || V_97 == NULL )
return - V_13 ;
V_110 = F_79 ( V_97 , V_108 , V_119 , V_111 ) ;
if ( V_110 == NULL )
return - V_120 ;
F_80 ( V_110 ) ;
F_81 ( V_110 ) ;
return 0 ;
}
static T_1 F_83 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
if ( V_3 == 0 )
return F_68 ( V_2 ) ;
if ( isdigit ( V_2 [ 0 ] ) )
return F_70 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isdigit ( V_2 [ 1 ] ) )
return F_74 ( V_2 ) ;
if ( isalpha ( V_2 [ 0 ] ) )
return F_77 ( V_2 ) ;
if ( V_2 [ 0 ] == '-' && isalpha ( V_2 [ 1 ] ) )
return F_82 ( V_2 ) ;
return - V_13 ;
}
static T_1 F_84 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_54 ( & V_85 ) ;
V_11 = F_83 ( V_1 , V_2 , V_3 ) ;
F_56 ( & V_85 ) ;
return V_11 ;
}
static T_1 F_85 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_75 = V_2 ;
if ( V_3 > 0 ) {
int V_121 ;
int V_11 = F_47 ( & V_75 , & V_121 ) ;
if ( V_11 )
return V_11 ;
if ( V_121 < 1024 )
V_121 = 1024 ;
if ( V_121 > V_122 )
V_121 = V_122 ;
V_121 &= ~ ( 1024 - 1 ) ;
F_54 ( & V_85 ) ;
if ( V_97 ) {
F_56 ( & V_85 ) ;
return - V_98 ;
}
V_123 = V_121 ;
F_56 ( & V_85 ) ;
}
return F_52 ( V_2 , V_79 , L_4 ,
V_123 ) ;
}
static T_1 F_86 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
char * V_75 = V_2 ;
int V_11 , V_82 ;
if ( V_3 > 0 ) {
if ( V_97 )
return - V_98 ;
V_11 = F_47 ( & V_75 , & V_82 ) ;
if ( V_11 )
return V_11 ;
if ( V_82 < 10 || V_82 > 3600 )
return - V_13 ;
* time = V_82 ;
}
return F_52 ( V_2 , V_79 , L_13 , * time ) ;
}
static T_1 F_87 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 , T_6 * time )
{
T_1 V_11 ;
F_54 ( & V_85 ) ;
V_11 = F_86 ( V_1 , V_2 , V_3 , time ) ;
F_56 ( & V_85 ) ;
return V_11 ;
}
static T_1 F_88 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_87 ( V_1 , V_2 , V_3 , & V_124 ) ;
}
static T_1 F_89 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
return F_87 ( V_1 , V_2 , V_3 , & V_125 ) ;
}
static T_1 F_90 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
char * V_75 = V_2 ;
char * V_126 ;
int V_76 , V_127 ;
if ( V_3 > 0 ) {
if ( V_97 )
return - V_98 ;
if ( V_3 > V_128 || V_2 [ V_3 - 1 ] != '\n' )
return - V_13 ;
V_2 [ V_3 - 1 ] = 0 ;
V_126 = V_75 ;
V_76 = F_39 ( & V_75 , V_126 , V_3 ) ;
if ( V_76 <= 0 )
return - V_13 ;
V_127 = F_91 ( V_126 ) ;
if ( V_127 )
return V_127 ;
}
return F_52 ( V_2 , V_79 , L_14 ,
F_92 () ) ;
}
static T_1 F_93 ( struct V_1 * V_1 , char * V_2 , T_3 V_3 )
{
T_1 V_11 ;
F_54 ( & V_85 ) ;
V_11 = F_90 ( V_1 , V_2 , V_3 ) ;
F_56 ( & V_85 ) ;
return V_11 ;
}
static int F_94 ( struct V_129 * V_130 , void * V_10 , int V_131 )
{
static struct V_132 V_133 [] = {
#ifdef F_8
[ V_134 ] = { L_15 , & V_135 , V_136 } ,
[ V_137 ] = { L_16 , & V_135 , V_136 } ,
[ V_138 ] = { L_17 , & V_135 , V_136 } ,
[ V_139 ] = { L_18 , & V_135 , V_136 } ,
[ V_140 ] = { L_19 , & V_135 , V_136 } ,
[ V_141 ] = { L_20 , & V_135 , V_136 | V_142 } ,
[ V_143 ] = { L_21 , & V_135 , V_136 | V_142 } ,
#endif
[ V_144 ] = { L_22 , & V_145 , V_146 } ,
[ V_147 ] = { L_23 ,
& V_148 , V_146 } ,
[ V_149 ] = { L_24 ,
& V_135 , V_136 | V_142 } ,
[ V_150 ] = { L_25 ,
& V_135 , V_136 | V_142 } ,
[ V_151 ] = { L_26 , & V_135 , V_136 | V_142 } ,
[ V_152 ] = { L_27 , & V_135 , V_136 | V_142 } ,
[ V_153 ] = { L_28 , & V_135 , V_136 | V_142 } ,
[ V_154 ] = { L_29 , & V_155 , V_146 } ,
[ V_156 ] = { L_30 , & V_135 , V_136 | V_142 } ,
[ V_157 ] = { L_31 , & V_135 , V_136 | V_146 } ,
[ V_158 ] = { L_32 , & V_135 , V_136 | V_146 } ,
#if F_95 ( V_159 ) || F_95 ( V_160 )
[ V_161 ] = { L_33 , & V_162 , V_146 } ,
#endif
#ifdef F_96
[ V_163 ] = { L_34 , & V_135 , V_136 | V_142 } ,
[ V_164 ] = { L_35 , & V_135 , V_136 | V_142 } ,
[ V_165 ] = { L_36 , & V_135 , V_136 | V_142 } ,
#endif
{ L_7 }
} ;
return F_97 ( V_130 , 0x6e667364 , V_133 ) ;
}
static struct V_7 * F_98 ( struct V_166 * V_167 ,
int V_168 , const char * V_169 , void * V_10 )
{
return F_99 ( V_167 , V_168 , V_10 , F_94 ) ;
}
static int F_100 ( void )
{
struct V_170 * V_171 ;
V_171 = F_101 ( L_37 , NULL ) ;
if ( ! V_171 )
return - V_78 ;
V_171 = F_102 ( L_22 , 0 , V_171 , & V_145 ) ;
if ( ! V_171 )
return - V_78 ;
return 0 ;
}
static int F_100 ( void )
{
return 0 ;
}
static int T_7 F_103 ( void )
{
int V_172 ;
F_9 ( V_18 L_38 ) ;
V_172 = F_104 () ;
if ( V_172 )
return V_172 ;
F_105 () ;
V_172 = F_106 () ;
if ( V_172 )
goto V_173;
V_172 = F_107 () ;
if ( V_172 )
goto V_174;
F_108 () ;
V_172 = F_109 () ;
if ( V_172 )
goto V_175;
V_172 = F_100 () ;
if ( V_172 )
goto V_176;
V_172 = F_110 ( & V_177 ) ;
if ( V_172 )
goto V_178;
return 0 ;
V_178:
F_111 ( L_39 , NULL ) ;
F_111 ( L_37 , NULL ) ;
V_176:
F_112 () ;
V_175:
F_113 () ;
F_114 () ;
V_174:
F_115 () ;
V_173:
F_116 () ;
F_117 () ;
return V_172 ;
}
static void T_8 F_118 ( void )
{
F_114 () ;
F_115 () ;
F_111 ( L_39 , NULL ) ;
F_111 ( L_37 , NULL ) ;
F_116 () ;
F_113 () ;
F_112 () ;
F_117 () ;
F_119 ( & V_177 ) ;
}
