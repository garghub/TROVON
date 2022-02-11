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
F_23 ( V_68 , V_77 , false ) ;
* V_66 = V_68 -> V_66 ;
}
static int F_24 ( struct V_30 * V_31 , struct V_36 * V_37 )
{
struct V_67 * V_68 = F_25 ( V_31 ) ;
return F_26 ( & V_68 -> V_78 . V_79 , V_37 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_51 * V_52 = & V_3 -> V_52 [ V_81 -> V_82 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_81 -> V_83 . V_84 = NULL ;
V_81 -> V_83 . V_85 = 0 ;
V_81 -> V_83 . V_16 = V_81 -> V_86 << V_87 ;
V_81 -> V_83 . V_88 = 0 ;
V_81 -> V_83 . V_89 = false ;
if ( ! ( V_52 -> V_50 & V_54 ) )
return - V_47 ;
switch ( V_81 -> V_82 ) {
case V_53 :
return 0 ;
case V_59 :
V_81 -> V_83 . V_89 = true ;
V_81 -> V_83 . V_88 = V_6 -> V_90 ;
V_81 -> V_83 . V_85 = V_81 -> V_91 << V_87 ;
break;
case V_60 :
V_81 -> V_83 . V_89 = true ;
V_81 -> V_83 . V_88 = V_6 -> V_92 ;
V_81 -> V_83 . V_85 = V_81 -> V_91 << V_87 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
}
static int F_29 ( struct V_93 * V_94 ,
struct V_80 * V_95 )
{
struct V_96 * V_97 = ( void * ) V_94 ;
V_97 -> V_85 = ( unsigned long ) ( V_95 -> V_91 << V_87 ) ;
if ( ! V_94 -> V_86 ) {
F_30 ( 1 , L_8 ,
V_94 -> V_86 , V_95 , V_94 ) ;
}
return - 1 ;
}
static int F_31 ( struct V_93 * V_94 )
{
return - 1 ;
}
static void F_32 ( struct V_93 * V_94 )
{
struct V_96 * V_97 = ( void * ) V_94 ;
F_33 ( & V_97 -> V_94 ) ;
F_34 ( V_97 ) ;
}
static int F_35 ( struct V_93 * V_94 )
{
int V_11 ;
if ( V_94 -> V_98 != V_99 )
return 0 ;
V_11 = F_36 ( V_94 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_37 ( struct V_93 * V_94 )
{
F_38 ( V_94 ) ;
}
static struct V_93 * F_39 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_100 ,
struct V_101 * V_102 )
{
struct V_1 * V_6 ;
struct V_96 * V_97 ;
V_6 = F_1 ( V_3 ) ;
V_97 = F_40 ( sizeof( struct V_96 ) , V_103 ) ;
if ( V_97 == NULL )
return NULL ;
V_97 -> V_94 . V_94 . V_61 = & V_104 ;
V_97 -> V_6 = V_6 ;
if ( F_41 ( & V_97 -> V_94 , V_3 , V_16 , V_100 ,
V_102 ) ) {
F_34 ( V_97 ) ;
return NULL ;
}
return & V_97 -> V_94 . V_94 ;
}
static void F_42 ( struct V_30 * V_31 ,
struct V_80 * V_105 )
{
struct V_80 * V_106 = & V_31 -> V_81 ;
F_43 ( V_106 -> V_107 != NULL ) ;
* V_106 = * V_105 ;
V_105 -> V_107 = NULL ;
}
static int F_44 ( struct V_30 * V_31 ,
bool V_108 , bool V_109 ,
bool V_110 ,
struct V_80 * V_105 )
{
struct V_80 * V_106 = & V_31 -> V_81 ;
if ( V_106 -> V_82 == V_53 && V_31 -> V_94 == NULL ) {
F_42 ( V_31 , V_105 ) ;
return 0 ;
}
return F_45 ( V_31 , V_108 , V_110 , V_105 ) ;
}
static int F_46 ( void * V_111 ,
bool V_112 , bool V_109 )
{
struct V_113 * V_114 = (struct V_113 * ) V_111 ;
int V_115 = 0 , V_116 = 0 ;
struct V_67 * V_31 = F_2 ( V_114 , struct V_67 , V_117 ) ;
if ( V_114 -> V_118 == 0 )
return 0 ;
V_119:
if ( V_116 == 0 ) {
if ( V_31 -> type == V_120 )
F_47 ( V_114 -> V_6 , V_31 ) ;
} else if ( V_116 >= 1 ) {
F_48 ( V_114 -> V_6 ) ;
}
V_116 ++ ;
for ( V_115 = 0 ; V_115 < 10 ; V_115 ++ ) {
bool V_121 ;
V_121 = F_49 ( V_114 -> V_6 , true ) ;
if ( V_121 == false )
break;
if ( V_114 -> V_118 == 0 )
return 0 ;
}
if ( V_114 -> V_118 ) {
bool V_122 = false ;
void * * V_123 ;
struct V_124 V_125 ;
int V_126 ;
F_50 (slot, &qfence->tree, &iter, 0 ) {
struct V_127 * V_19 ;
V_126 = V_125 . V_128 ;
V_19 = F_51 ( V_114 -> V_6 , V_126 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> type == V_129 )
V_122 = true ;
}
F_49 ( V_114 -> V_6 , true ) ;
if ( V_122 || V_116 < 4 ) {
if ( V_116 > 2 )
F_52 ( 500 , 1000 ) ;
if ( V_122 && V_116 > 300 ) {
F_30 ( 1 , L_9 , V_116 , V_31 -> V_130 , V_31 -> V_131 , V_31 -> V_132 , ( unsigned long ) V_31 -> V_78 . V_16 , V_114 -> V_118 ) ;
return - V_133 ;
}
goto V_119;
}
}
return 0 ;
}
static int F_53 ( void * V_111 )
{
return 0 ;
}
static void F_54 ( void * * V_111 )
{
}
static void * F_55 ( void * V_111 )
{
return V_111 ;
}
static bool F_56 ( void * V_111 )
{
struct V_113 * V_114 = (struct V_113 * ) V_111 ;
return ( V_114 -> V_118 == 0 ) ;
}
static void F_57 ( struct V_30 * V_31 ,
struct V_80 * V_105 )
{
struct V_67 * V_68 ;
struct V_1 * V_6 ;
if ( ! F_22 ( V_31 ) )
return;
V_68 = F_2 ( V_31 , struct V_67 , V_76 ) ;
V_6 = V_68 -> V_78 . V_45 -> V_46 ;
if ( V_31 -> V_81 . V_82 == V_60 && V_68 -> V_130 )
F_58 ( V_6 , V_68 , V_105 ? true : false ) ;
}
int F_59 ( struct V_1 * V_6 )
{
int V_11 ;
int V_134 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_60 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_135 , V_41 , 0 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_134 = V_6 -> V_136 -> V_137 / V_138 ;
V_11 = F_61 ( & V_6 -> V_5 . V_3 , V_59 ,
V_134 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_61 ( & V_6 -> V_5 . V_3 , V_60 ,
V_6 -> V_139 / V_138 ) ;
if ( V_11 ) {
F_9 ( L_12 ) ;
return V_11 ;
}
F_62 ( L_13 ,
( unsigned ) V_6 -> V_140 / ( 1024 * 1024 ) ) ;
F_62 ( L_14 ,
( ( unsigned ) V_134 * V_138 ) / ( 1024 * 1024 ) ) ;
if ( F_14 ( V_6 -> V_5 . V_3 . V_141 == NULL ) )
V_6 -> V_5 . V_3 . V_141 = V_6 -> V_142 -> V_141 ;
V_11 = F_63 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_64 ( struct V_1 * V_6 )
{
F_65 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_65 ( & V_6 -> V_5 . V_3 , V_60 ) ;
F_66 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_62 ( L_16 ) ;
}
static int F_67 ( struct V_143 * V_144 , void * V_145 )
{
struct V_146 * V_147 = (struct V_146 * ) V_144 -> V_148 ;
struct V_149 * V_150 = (struct V_149 * ) V_147 -> V_151 -> V_145 ;
struct V_152 * V_45 = V_147 -> V_44 -> V_45 ;
struct V_1 * V_153 = V_45 -> V_46 ;
int V_121 ;
struct V_23 * V_154 = V_153 -> V_5 . V_3 . V_154 ;
F_68 ( & V_154 -> V_155 ) ;
V_121 = F_69 ( V_144 , V_150 ) ;
F_70 ( & V_154 -> V_155 ) ;
return V_121 ;
}
static int F_63 ( struct V_1 * V_6 )
{
#if F_71 ( V_156 )
static struct V_157 V_158 [ V_159 ] ;
static char V_160 [ V_159 ] [ 32 ] ;
unsigned V_161 ;
for ( V_161 = 0 ; V_161 < V_159 ; V_161 ++ ) {
if ( V_161 == 0 )
sprintf ( V_160 [ V_161 ] , L_17 ) ;
else
sprintf ( V_160 [ V_161 ] , L_18 ) ;
V_158 [ V_161 ] . V_162 = V_160 [ V_161 ] ;
V_158 [ V_161 ] . V_163 = & F_67 ;
V_158 [ V_161 ] . V_164 = 0 ;
if ( V_161 == 0 )
V_158 [ V_161 ] . V_145 = V_6 -> V_5 . V_3 . V_52 [ V_59 ] . V_165 ;
else
V_158 [ V_161 ] . V_145 = V_6 -> V_5 . V_3 . V_52 [ V_60 ] . V_165 ;
}
return F_72 ( V_6 , V_158 , V_161 ) ;
#else
return 0 ;
#endif
}
