static char * F_1 ( char * V_1 )
{
char * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ )
* V_2 = tolower ( * V_2 ) ;
return V_1 ;
}
static void T_1 * F_2 ( const char * V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
V_5 = F_3 ( NULL , NULL , V_3 ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_4 ( V_5 , 0 ) ;
F_5 ( V_5 ) ;
return V_6 ;
}
static int F_6 ( struct V_7 * V_8 , int V_9 , bool V_10 ,
T_2 args [] )
{
unsigned long V_11 = F_7 ( V_12 ) ;
void T_1 * V_13 = V_8 -> V_13 ;
unsigned int V_14 ;
int V_15 ;
T_2 V_16 ;
V_15 = F_8 ( & V_8 -> V_17 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 , V_16 = 1 ; V_16 != 0 && V_14 < V_18 ; V_14 ++ )
V_16 = F_9 ( V_13 + V_19 ) ;
if ( V_14 == V_18 ) {
V_15 = - V_20 ;
goto V_21;
}
F_10 ( V_22 , V_13 + V_23 ) ;
if ( args && V_10 ) {
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ )
F_10 ( args [ V_14 ] , V_13 + F_11 ( V_14 ) ) ;
}
F_12 ( & V_8 -> V_25 ) ;
F_10 ( V_9 , V_13 + V_19 ) ;
F_10 ( V_26 , V_8 -> V_27 + V_28 ) ;
V_11 = F_13 ( & V_8 -> V_25 , V_11 ) ;
V_16 = F_9 ( V_13 + V_23 ) ;
if ( V_11 == 0 || V_16 == 0 || V_16 > V_29 ) {
F_14 ( V_8 -> V_30 , L_1 ,
V_9 ) ;
F_14 ( V_8 -> V_30 , L_2 ,
F_15 ( V_11 ) , V_16 ) ;
V_15 = - V_31 ;
goto V_21;
}
if ( args && ! V_10 ) {
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ )
args [ V_14 ] = F_9 ( V_13 + F_11 ( V_14 ) ) ;
}
F_10 ( V_22 , V_13 + V_23 ) ;
switch ( V_16 ) {
case V_32 :
V_15 = - V_33 ;
break;
case V_34 :
V_15 = - V_35 ;
break;
case V_36 :
V_15 = - V_37 ;
break;
case V_38 :
V_15 = - V_39 ;
break;
case V_40 :
V_15 = - V_41 ;
break;
}
V_21:
F_16 ( & V_8 -> V_17 ) ;
return V_15 ;
}
static T_3 F_17 ( int V_42 , void * V_43 )
{
struct V_7 * V_8 = V_43 ;
F_18 ( & V_8 -> V_25 ) ;
return V_44 ;
}
static char * F_19 ( unsigned int V_45 )
{
switch ( V_45 ) {
case V_46 :
return L_3 ;
case V_47 :
return L_4 ;
case V_48 :
return L_5 ;
case V_49 :
return L_6 ;
}
return NULL ;
}
static void F_20 ( T_2 V_50 , unsigned int * V_51 , unsigned int * V_52 ,
unsigned int * V_53 )
{
* V_51 = ( V_50 >> V_54 ) & V_55 ;
* V_52 = ( V_50 >> V_56 ) & V_57 ;
* V_53 = ( V_50 >> V_58 ) & V_59 ;
}
static void F_21 ( T_2 V_60 , unsigned int * V_61 ,
unsigned int * V_62 , unsigned int * V_63 ,
unsigned int * V_64 )
{
* V_64 = ( V_60 >> V_65 ) & V_66 ;
* V_63 = ( V_60 >> V_67 ) & V_68 ;
* V_62 = ( V_60 >> V_69 ) & V_70 ;
* V_61 = ( V_60 >> V_71 ) & V_72 ;
}
static int F_22 ( struct V_7 * V_8 , struct V_73 * V_73 )
{
T_2 args [ V_24 ] ;
int V_15 ;
V_15 = F_6 ( V_8 , V_74 , false , args ) ;
if ( V_15 || ! V_73 )
return V_15 ;
V_73 -> V_45 = args [ 0 ] ;
V_73 -> V_50 = args [ 1 ] ;
V_73 -> V_60 = args [ 2 ] ;
V_73 -> V_75 = args [ 3 ] ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , struct V_73 * V_73 )
{
T_2 args [ V_24 ] ;
args [ 0 ] = V_73 -> V_45 ;
args [ 1 ] = V_73 -> V_50 ;
args [ 2 ] = V_73 -> V_60 ;
args [ 3 ] = V_73 -> V_75 ;
return F_6 ( V_8 , V_76 , true , args ) ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int * V_77 )
{
T_2 args [ V_24 ] ;
int V_15 ;
V_15 = F_6 ( V_8 , V_78 , false , args ) ;
if ( V_15 )
return V_15 ;
* V_77 = args [ 0 ] ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , unsigned int V_77 )
{
T_2 args [ V_24 ] ;
args [ 0 ] = V_77 ;
return F_6 ( V_8 , V_79 , true , args ) ;
}
static unsigned long F_26 ( void T_1 * V_13 )
{
return F_9 ( V_13 + V_80 ) ;
}
static unsigned long F_27 ( void T_1 * V_13 )
{
return F_9 ( V_13 + V_81 ) * 1000 ;
}
static struct V_82 *
F_28 ( struct V_83 * V_30 , struct V_7 * V_8 )
{
struct V_82 * V_84 ;
unsigned int V_77 ;
int V_14 , V_15 ;
V_15 = F_24 ( V_8 , & V_77 ) ;
if ( V_15 )
return F_29 ( V_15 ) ;
V_84 = F_30 ( V_30 , ( V_85 + 1 ) * sizeof( * V_84 ) ,
V_86 ) ;
if ( ! V_84 )
return F_29 ( - V_87 ) ;
for ( V_14 = V_88 ; V_14 <= V_85 ; V_14 ++ ) {
V_15 = F_25 ( V_8 , V_14 ) ;
if ( V_15 )
return F_29 ( V_15 ) ;
V_84 [ V_14 ] . V_89 = F_27 ( V_8 -> V_13 ) ;
V_84 [ V_14 ] . V_90 = V_14 ;
}
V_84 [ V_14 ] . V_89 = V_91 ;
V_15 = F_25 ( V_8 , V_77 ) ;
if ( V_15 )
return F_29 ( V_15 ) ;
return V_84 ;
}
static int F_31 ( struct V_92 * V_1 , void * V_43 )
{
struct V_93 * V_94 = V_1 -> V_95 ;
void T_1 * V_13 ;
T_2 V_16 , V_96 ;
if ( ! V_94 ) {
F_32 ( V_1 , L_7 ) ;
return 0 ;
}
V_13 = V_94 -> V_8 -> V_13 ;
V_96 = V_94 -> V_97 -> V_96 ;
V_16 = F_9 ( V_13 + V_96 ) ;
switch ( V_94 -> V_97 -> V_98 ) {
case V_99 :
F_33 ( V_1 , L_8 , V_16 ) ;
break;
case V_100 :
F_33 ( V_1 , L_9 , F_34 ( V_16 ) , F_35 ( V_16 ) ) ;
break;
case V_101 :
F_33 ( V_1 , L_10 , ( V_16 >> 24 & 0xff ) ,
( V_16 >> 16 & 0xff ) , ( V_16 >> 8 & 0xff ) ,
V_16 & 0xff ) ;
break;
}
F_33 ( V_1 , L_11 , V_16 ) ;
return 0 ;
}
static T_4 F_36 ( struct V_102 * V_102 , const char T_5 * V_103 ,
T_6 V_104 , T_7 * V_105 )
{
struct V_92 * V_1 = V_102 -> V_7 ;
struct V_93 * V_94 = V_1 -> V_95 ;
struct V_7 * V_8 = V_94 -> V_8 ;
void T_1 * V_13 , * V_27 ;
bool V_106 = false ;
unsigned long V_16 , V_96 ;
char V_107 [ 128 ] ;
int V_15 ;
char * V_108 = V_107 ;
if ( V_104 >= sizeof( V_107 ) )
return - V_109 ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
V_15 = F_37 ( V_107 , V_103 , V_104 ) ;
if ( V_15 )
return V_15 ;
V_13 = V_8 -> V_13 ;
V_27 = V_8 -> V_27 ;
V_96 = V_94 -> V_97 -> V_96 ;
if ( V_108 [ 0 ] == 'c' && V_96 == V_19 ) {
V_106 = true ;
V_108 ++ ;
}
if ( F_38 ( V_108 , 0 , & V_16 ) != 0 )
return - V_33 ;
if ( V_16 == V_79 ) {
struct V_110 * V_111 ;
unsigned int V_77 ;
V_111 = F_39 ( F_40 () ) ;
V_77 = F_9 ( V_13 + F_11 ( 0 ) ) ;
if ( V_106 ) {
V_15 = F_41 ( V_111 , V_77 ) ;
return V_15 ? V_15 : V_104 ;
}
V_111 -> V_112 = V_111 -> V_113 [ V_77 ] . V_89 ;
}
if ( V_106 ) {
V_15 = F_6 ( V_8 , V_16 , false , NULL ) ;
} else {
V_15 = F_8 ( & V_8 -> V_17 ) ;
if ( V_15 )
return V_15 ;
F_10 ( V_16 , V_13 + V_96 ) ;
if ( V_96 == V_19 )
F_10 ( V_26 ,
V_27 + V_28 ) ;
F_16 ( & V_8 -> V_17 ) ;
}
return V_15 ? V_15 : V_104 ;
}
static struct V_114 * F_42 ( const char * V_3 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_43 ( V_115 ) ; V_14 ++ )
if ( strcasecmp ( V_115 [ V_14 ] . V_3 , V_3 ) == 0 )
return & V_115 [ V_14 ] ;
return NULL ;
}
static int F_44 ( struct V_116 * V_116 , struct V_102 * V_102 )
{
struct V_93 * V_43 ;
T_8 V_117 ;
int V_15 ;
V_117 = V_102 -> V_118 ;
if ( ( V_117 & V_119 ) && ! ( V_116 -> V_120 & V_121 ) )
return - V_122 ;
V_43 = F_45 ( sizeof( * V_43 ) , V_86 ) ;
if ( ! V_43 )
return - V_87 ;
V_43 -> V_97 = F_42 ( V_102 -> V_123 . V_124 -> V_125 ) ;
V_43 -> V_8 = V_116 -> V_126 ;
V_15 = F_46 ( V_102 , F_31 , V_43 ) ;
if ( V_15 )
F_47 ( V_43 ) ;
V_102 -> V_118 = V_117 ;
return V_15 ;
}
static int F_48 ( struct V_116 * V_116 , struct V_102 * V_102 )
{
struct V_92 * V_127 = V_102 -> V_7 ;
struct V_93 * V_43 = V_127 -> V_95 ;
F_47 ( V_43 ) ;
return F_49 ( V_116 , V_102 ) ;
}
static void F_50 ( struct V_128 * V_129 )
{
struct V_7 * V_8 = F_51 ( V_129 ) ;
struct V_124 * V_130 ;
int V_14 ;
if ( ! V_8 )
return;
V_130 = F_52 ( V_131 , NULL ) ;
if ( F_53 ( V_130 ) )
return;
V_8 -> V_132 = V_130 ;
for ( V_14 = 0 ; V_14 < F_43 ( V_115 ) ; V_14 ++ ) {
char * V_97 = F_1 ( V_115 [ V_14 ] . V_3 ) ;
T_8 V_45 = V_115 [ V_14 ] . V_45 ;
if ( ! F_54 ( V_97 , V_133 | V_134 | V_45 ,
V_130 , V_8 , & V_135 ) ) {
V_8 -> V_132 = NULL ;
F_55 ( V_130 ) ;
break;
}
}
}
static void F_56 ( struct V_128 * V_129 )
{
struct V_7 * V_8 = F_51 ( V_129 ) ;
if ( V_8 && V_8 -> V_132 ) {
F_55 ( V_8 -> V_132 ) ;
V_8 -> V_132 = NULL ;
}
}
static void F_50 ( struct V_128 * V_129 ) {}
static void F_56 ( struct V_128 * V_129 ) {}
static bool F_57 ( struct V_7 * V_8 )
{
T_2 V_136 ;
int V_137 ;
V_137 = F_22 ( V_8 , NULL ) ;
V_136 = F_9 ( V_8 -> V_13 + V_138 ) ;
return ( V_136 == V_139 ) && ( V_137 != - V_35 ) &&
( V_137 != - V_33 ) ;
}
static unsigned int F_58 ( unsigned int V_140 )
{
struct V_110 * V_111 = F_39 ( V_140 ) ;
struct V_7 * V_8 = V_111 -> V_90 ;
return F_27 ( V_8 -> V_13 ) ;
}
static int F_41 ( struct V_110 * V_111 ,
unsigned int V_141 )
{
return F_25 ( V_111 -> V_90 ,
V_111 -> V_113 [ V_141 ] . V_90 ) ;
}
static int F_59 ( struct V_110 * V_111 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
int V_15 ;
V_15 = F_22 ( V_8 , & V_8 -> V_73 ) ;
if ( V_15 )
return V_15 ;
return F_24 ( V_8 , & V_8 -> V_73 . V_75 ) ;
}
static int F_60 ( struct V_110 * V_111 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
int V_15 ;
V_15 = F_23 ( V_8 , & V_8 -> V_73 ) ;
if ( V_15 == - V_39 ) {
struct V_128 * V_129 = F_61 () ;
struct V_83 * V_30 = & V_129 -> V_30 ;
F_62 ( V_30 , L_12 ) ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_63 ( struct V_128 * V_129 )
{
struct V_7 * V_8 ;
struct V_83 * V_30 ;
int V_142 , V_15 ;
V_30 = & V_129 -> V_30 ;
V_8 = F_30 ( V_30 , sizeof( * V_8 ) , V_86 ) ;
if ( ! V_8 )
return - V_87 ;
V_8 -> V_30 = V_30 ;
F_64 ( & V_8 -> V_17 , 1 ) ;
F_65 ( & V_8 -> V_25 ) ;
F_66 ( V_129 , V_8 ) ;
V_8 -> V_13 = F_2 ( V_143 ) ;
if ( ! V_8 -> V_13 ) {
F_14 ( V_30 , L_13 ,
V_143 ) ;
return - V_37 ;
}
V_8 -> V_27 = F_2 ( V_144 ) ;
if ( ! V_8 -> V_27 ) {
F_14 ( V_30 , L_13 ,
V_144 ) ;
V_15 = - V_37 ;
goto V_145;
}
V_142 = F_67 ( V_129 , V_146 ) ;
if ( V_142 < 0 ) {
F_14 ( V_30 , L_14 ,
V_146 , V_142 ) ;
V_15 = V_142 ;
goto V_147;
}
V_15 = F_68 ( V_30 , V_142 , F_17 , V_148 ,
V_146 , V_8 ) ;
if ( V_15 ) {
F_14 ( V_30 , L_15 ,
V_146 , V_142 , V_15 ) ;
goto V_147;
}
if ( F_57 ( V_8 ) )
return 0 ;
F_14 ( V_30 , L_16 ) ;
V_15 = - V_149 ;
V_147:
F_69 ( V_8 -> V_27 ) ;
V_145:
F_69 ( V_8 -> V_13 ) ;
return V_15 ;
}
static int F_70 ( struct V_110 * V_111 )
{
struct V_82 * V_113 ;
struct V_128 * V_129 ;
struct V_7 * V_8 ;
struct V_83 * V_30 ;
int V_15 ;
V_129 = F_61 () ;
V_8 = F_51 ( V_129 ) ;
V_111 -> V_90 = V_8 ;
V_30 = & V_129 -> V_30 ;
V_113 = F_28 ( V_30 , V_8 ) ;
if ( F_71 ( V_113 ) ) {
V_15 = F_72 ( V_113 ) ;
F_14 ( V_30 , L_17 , V_15 ) ;
return V_15 ;
}
V_15 = F_73 ( V_111 , V_113 ) ;
if ( V_15 ) {
F_14 ( V_30 , L_18 , V_15 ) ;
return V_15 ;
}
F_74 ( V_111 -> V_150 ) ;
V_15 = F_6 ( V_8 , V_151 , false , NULL ) ;
if ( ! V_15 ) {
unsigned int V_77 ;
V_15 = F_24 ( V_8 , & V_77 ) ;
if ( ! V_15 ) {
V_111 -> V_112 = V_113 [ V_77 ] . V_89 ;
F_75 ( V_30 , L_19 ) ;
return 0 ;
}
}
F_14 ( V_30 , L_20 , V_15 ) ;
return V_15 ;
}
static T_4 F_76 ( struct V_110 * V_111 , char * V_103 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
unsigned int V_77 ;
if ( F_24 ( V_8 , & V_77 ) )
return sprintf ( V_103 , L_21 ) ;
return sprintf ( V_103 , L_8 , V_77 ) ;
}
static T_4 F_77 ( struct V_110 * V_111 , char * V_103 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
struct V_73 V_73 ;
if ( F_22 ( V_8 , & V_73 ) )
return sprintf ( V_103 , L_21 ) ;
return sprintf ( V_103 , L_22 , F_19 ( V_73 . V_45 ) ,
V_73 . V_45 ) ;
}
static T_4 F_78 ( struct V_110 * V_111 , char * V_103 )
{
unsigned int V_51 , V_61 , V_62 , V_63 , V_64 ;
struct V_7 * V_8 = V_111 -> V_90 ;
unsigned int V_53 , V_52 ;
struct V_73 V_73 ;
if ( F_22 ( V_8 , & V_73 ) )
return sprintf ( V_103 , L_21 ) ;
F_20 ( V_73 . V_50 , & V_51 , & V_52 , & V_53 ) ;
F_21 ( V_73 . V_60 , & V_61 , & V_62 , & V_63 , & V_64 ) ;
return sprintf ( V_103 , L_23 ,
V_73 . V_50 , V_73 . V_60 , V_53 , V_52 , V_51 , V_61 , V_62 ,
V_63 , V_64 , V_73 . V_45 , V_73 . V_75 ) ;
}
static T_4 F_79 ( struct V_110 * V_111 , char * V_103 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
return sprintf ( V_103 , L_24 , F_26 ( V_8 -> V_13 ) ) ;
}
static T_4 F_80 ( struct V_110 * V_111 , char * V_103 )
{
struct V_7 * V_8 = V_111 -> V_90 ;
return sprintf ( V_103 , L_24 , F_27 ( V_8 -> V_13 ) ) ;
}
static int F_81 ( struct V_128 * V_129 )
{
int V_15 ;
V_15 = F_63 ( V_129 ) ;
if ( V_15 )
return V_15 ;
V_152 . V_90 = V_129 ;
V_15 = F_82 ( & V_152 ) ;
if ( ! V_15 )
F_50 ( V_129 ) ;
return V_15 ;
}
static int F_83 ( struct V_128 * V_129 )
{
struct V_7 * V_8 ;
int V_15 ;
V_15 = F_84 ( & V_152 ) ;
if ( V_15 )
return V_15 ;
F_56 ( V_129 ) ;
V_8 = F_51 ( V_129 ) ;
F_69 ( V_8 -> V_13 ) ;
F_69 ( V_8 -> V_27 ) ;
return 0 ;
}
