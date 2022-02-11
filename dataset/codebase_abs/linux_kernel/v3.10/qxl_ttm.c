static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static int F_12 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_1 * V_6 ;
int V_11 ;
V_31 = (struct V_30 * ) V_27 -> V_32 ;
if ( V_31 == NULL )
return V_33 ;
V_6 = F_1 ( V_31 -> V_3 ) ;
V_11 = V_34 -> V_35 ( V_27 , V_29 ) ;
return V_11 ;
}
int F_13 ( struct V_36 * V_37 , struct V_26 * V_27 )
{
struct V_38 * V_39 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_14 ( V_27 -> V_40 < V_41 ) ) {
F_15 ( L_4 ,
V_42 , V_27 -> V_40 ) ;
return F_16 ( V_37 , V_27 ) ;
}
V_39 = V_37 -> V_43 ;
V_6 = V_39 -> V_44 -> V_45 -> V_46 ;
if ( V_6 == NULL ) {
F_9 (
L_5 ) ;
return - V_47 ;
}
F_17 ( V_6 , L_6 ,
V_42 , V_37 -> V_43 , V_27 -> V_40 ) ;
V_11 = F_18 ( V_37 , V_27 , & V_6 -> V_5 . V_3 ) ;
if ( F_14 ( V_11 != 0 ) )
return V_11 ;
if ( F_14 ( V_34 == NULL ) ) {
V_34 = V_27 -> V_48 ;
V_49 = * V_34 ;
V_49 . V_35 = & F_12 ;
}
V_27 -> V_48 = & V_49 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_1 V_50 )
{
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , T_1 type ,
struct V_51 * V_52 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_53 :
V_52 -> V_50 = V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
break;
case V_59 :
case V_60 :
V_52 -> V_61 = & V_62 ;
V_52 -> V_63 = 0 ;
V_52 -> V_50 = V_64 |
V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
break;
default:
F_9 ( L_7 , ( unsigned ) type ) ;
return - V_47 ;
}
return 0 ;
}
static void F_21 ( struct V_30 * V_31 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 ;
static T_2 V_69 = V_56 | V_70 ;
if ( ! F_22 ( V_31 ) ) {
V_66 -> V_71 = 0 ;
V_66 -> V_72 = 0 ;
V_66 -> V_66 = & V_69 ;
V_66 -> V_73 = & V_69 ;
V_66 -> V_74 = 1 ;
V_66 -> V_75 = 1 ;
return;
}
V_68 = F_2 ( V_31 , struct V_67 , V_76 ) ;
F_23 ( V_68 , V_77 ) ;
* V_66 = V_68 -> V_66 ;
}
static int F_24 ( struct V_30 * V_31 , struct V_36 * V_37 )
{
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_51 * V_52 = & V_3 -> V_52 [ V_79 -> V_80 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_79 -> V_81 . V_82 = NULL ;
V_79 -> V_81 . V_83 = 0 ;
V_79 -> V_81 . V_16 = V_79 -> V_84 << V_85 ;
V_79 -> V_81 . V_86 = 0 ;
V_79 -> V_81 . V_87 = false ;
if ( ! ( V_52 -> V_50 & V_54 ) )
return - V_47 ;
switch ( V_79 -> V_80 ) {
case V_53 :
return 0 ;
case V_59 :
V_79 -> V_81 . V_87 = true ;
V_79 -> V_81 . V_86 = V_6 -> V_88 ;
V_79 -> V_81 . V_83 = V_79 -> V_89 << V_85 ;
break;
case V_60 :
V_79 -> V_81 . V_87 = true ;
V_79 -> V_81 . V_86 = V_6 -> V_90 ;
V_79 -> V_81 . V_83 = V_79 -> V_89 << V_85 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
}
static int F_27 ( struct V_91 * V_92 ,
struct V_78 * V_93 )
{
struct V_94 * V_95 = ( void * ) V_92 ;
V_95 -> V_83 = ( unsigned long ) ( V_93 -> V_89 << V_85 ) ;
if ( ! V_92 -> V_84 ) {
F_28 ( 1 , L_8 ,
V_92 -> V_84 , V_93 , V_92 ) ;
}
return - 1 ;
}
static int F_29 ( struct V_91 * V_92 )
{
return - 1 ;
}
static void F_30 ( struct V_91 * V_92 )
{
struct V_94 * V_95 = ( void * ) V_92 ;
F_31 ( & V_95 -> V_92 ) ;
F_32 ( V_95 ) ;
}
static int F_33 ( struct V_91 * V_92 )
{
int V_11 ;
if ( V_92 -> V_96 != V_97 )
return 0 ;
V_11 = F_34 ( V_92 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_35 ( struct V_91 * V_92 )
{
F_36 ( V_92 ) ;
}
static struct V_91 * F_37 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_98 ,
struct V_99 * V_100 )
{
struct V_1 * V_6 ;
struct V_94 * V_95 ;
V_6 = F_1 ( V_3 ) ;
V_95 = F_38 ( sizeof( struct V_94 ) , V_101 ) ;
if ( V_95 == NULL )
return NULL ;
V_95 -> V_92 . V_92 . V_61 = & V_102 ;
V_95 -> V_6 = V_6 ;
if ( F_39 ( & V_95 -> V_92 , V_3 , V_16 , V_98 ,
V_100 ) ) {
F_32 ( V_95 ) ;
return NULL ;
}
return & V_95 -> V_92 . V_92 ;
}
static void F_40 ( struct V_30 * V_31 ,
struct V_78 * V_103 )
{
struct V_78 * V_104 = & V_31 -> V_79 ;
F_41 ( V_104 -> V_105 != NULL ) ;
* V_104 = * V_103 ;
V_103 -> V_105 = NULL ;
}
static int F_42 ( struct V_30 * V_31 ,
bool V_106 , bool V_107 ,
bool V_108 ,
struct V_78 * V_103 )
{
struct V_78 * V_104 = & V_31 -> V_79 ;
if ( V_104 -> V_80 == V_53 && V_31 -> V_92 == NULL ) {
F_40 ( V_31 , V_103 ) ;
return 0 ;
}
return F_43 ( V_31 , V_106 , V_108 , V_103 ) ;
}
static int F_44 ( void * V_109 ,
bool V_110 , bool V_107 )
{
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
int V_113 = 0 , V_114 = 0 ;
struct V_67 * V_31 = F_2 ( V_112 , struct V_67 , V_115 ) ;
if ( V_112 -> V_116 == 0 )
return 0 ;
V_117:
if ( V_114 == 0 ) {
if ( V_31 -> type == V_118 )
F_45 ( V_112 -> V_6 , V_31 ) ;
} else if ( V_114 >= 1 ) {
F_46 ( V_112 -> V_6 ) ;
}
V_114 ++ ;
for ( V_113 = 0 ; V_113 < 10 ; V_113 ++ ) {
bool V_119 ;
V_119 = F_47 ( V_112 -> V_6 , true ) ;
if ( V_119 == false )
break;
if ( V_112 -> V_116 == 0 )
return 0 ;
}
if ( V_112 -> V_116 ) {
bool V_120 = false ;
void * * V_121 ;
struct V_122 V_123 ;
int V_124 ;
F_48 (slot, &qfence->tree, &iter, 0 ) {
struct V_125 * V_19 ;
V_124 = V_123 . V_126 ;
V_19 = F_49 ( V_112 -> V_6 , V_124 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> type == V_127 )
V_120 = true ;
}
F_47 ( V_112 -> V_6 , true ) ;
if ( V_120 || V_114 < 4 ) {
if ( V_114 > 2 )
F_50 ( 500 , 1000 ) ;
if ( V_120 && V_114 > 300 ) {
F_28 ( 1 , L_9 , V_114 , V_31 -> V_128 , V_31 -> V_129 , V_31 -> V_130 , ( unsigned long ) V_31 -> V_131 . V_16 , V_112 -> V_116 ) ;
return - V_132 ;
}
goto V_117;
}
}
return 0 ;
}
static int F_51 ( void * V_109 )
{
return 0 ;
}
static void F_52 ( void * * V_109 )
{
}
static void * F_53 ( void * V_109 )
{
return V_109 ;
}
static bool F_54 ( void * V_109 )
{
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
return ( V_112 -> V_116 == 0 ) ;
}
static void F_55 ( struct V_30 * V_31 ,
struct V_78 * V_103 )
{
struct V_67 * V_68 ;
struct V_1 * V_6 ;
if ( ! F_22 ( V_31 ) )
return;
V_68 = F_2 ( V_31 , struct V_67 , V_76 ) ;
V_6 = V_68 -> V_131 . V_45 -> V_46 ;
if ( V_31 -> V_79 . V_80 == V_60 && V_68 -> V_128 )
F_56 ( V_6 , V_68 , V_103 ? true : false ) ;
}
int F_57 ( struct V_1 * V_6 )
{
int V_11 ;
int V_133 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_58 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_134 , V_41 , 0 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_133 = V_6 -> V_135 -> V_136 / V_137 ;
V_11 = F_59 ( & V_6 -> V_5 . V_3 , V_59 ,
V_133 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_59 ( & V_6 -> V_5 . V_3 , V_60 ,
V_6 -> V_138 / V_137 ) ;
if ( V_11 ) {
F_9 ( L_12 ) ;
return V_11 ;
}
F_60 ( L_13 ,
( unsigned ) V_6 -> V_139 / ( 1024 * 1024 ) ) ;
F_60 ( L_14 ,
( ( unsigned ) V_133 * V_137 ) / ( 1024 * 1024 ) ) ;
if ( F_14 ( V_6 -> V_5 . V_3 . V_140 == NULL ) )
V_6 -> V_5 . V_3 . V_140 = V_6 -> V_141 -> V_140 ;
V_11 = F_61 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_6 )
{
F_63 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_63 ( & V_6 -> V_5 . V_3 , V_60 ) ;
F_64 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_60 ( L_16 ) ;
}
static int F_65 ( struct V_142 * V_143 , void * V_144 )
{
struct V_145 * V_146 = (struct V_145 * ) V_143 -> V_147 ;
struct V_148 * V_149 = (struct V_148 * ) V_146 -> V_150 -> V_144 ;
struct V_151 * V_45 = V_146 -> V_44 -> V_45 ;
struct V_1 * V_152 = V_45 -> V_46 ;
int V_119 ;
struct V_23 * V_153 = V_152 -> V_5 . V_3 . V_153 ;
F_66 ( & V_153 -> V_154 ) ;
V_119 = F_67 ( V_143 , V_149 ) ;
F_68 ( & V_153 -> V_154 ) ;
return V_119 ;
}
static int F_61 ( struct V_1 * V_6 )
{
#if F_69 ( V_155 )
static struct V_156 V_157 [ V_158 ] ;
static char V_159 [ V_158 ] [ 32 ] ;
unsigned V_160 ;
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
if ( V_160 == 0 )
sprintf ( V_159 [ V_160 ] , L_17 ) ;
else
sprintf ( V_159 [ V_160 ] , L_18 ) ;
V_157 [ V_160 ] . V_161 = V_159 [ V_160 ] ;
V_157 [ V_160 ] . V_162 = & F_65 ;
V_157 [ V_160 ] . V_163 = 0 ;
if ( V_160 == 0 )
V_157 [ V_160 ] . V_144 = V_6 -> V_5 . V_3 . V_52 [ V_59 ] . V_164 ;
else
V_157 [ V_160 ] . V_144 = V_6 -> V_5 . V_3 . V_52 [ V_60 ] . V_164 ;
}
return F_70 ( V_6 , V_157 , V_160 ) ;
#else
return 0 ;
#endif
}
