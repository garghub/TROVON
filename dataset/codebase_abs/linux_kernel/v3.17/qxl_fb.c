static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
V_1 -> V_3 = V_3 ;
if ( V_5 ) {
V_1 -> V_8 = V_5 -> V_9 . V_8 ;
if ( V_1 -> V_8 == V_10 ||
V_1 -> V_8 == V_11 )
memcpy ( & V_1 -> V_12 ,
V_5 -> V_12 ,
sizeof( V_1 -> V_12 ) ) ;
} else {
if ( V_7 -> V_13 == 1 )
V_1 -> V_8 = V_14 ;
else
V_1 -> V_8 = V_11 ;
}
if ( V_7 ) {
memcpy ( & V_1 -> V_6 , V_7 ,
sizeof( V_1 -> V_6 ) ) ;
}
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_1 V_1 ;
struct V_6 * V_7 = & V_1 . V_6 ;
T_1 V_18 , V_19 , y1 , V_20 ;
int V_21 = V_16 -> V_22 . V_23 . V_24 [ 0 ] ;
V_18 = V_16 -> V_25 . V_18 ;
V_19 = V_16 -> V_25 . V_19 ;
y1 = V_16 -> V_25 . y1 ;
V_20 = V_16 -> V_25 . V_20 ;
F_3 ( V_3 , L_1 , V_18 , V_19 , y1 , V_20 ) ;
V_7 -> V_26 = V_18 ;
V_7 -> V_27 = y1 ;
V_7 -> V_28 = V_19 - V_18 ;
V_7 -> V_29 = V_20 - y1 ;
V_7 -> V_30 = 0xffffffff ;
V_7 -> V_31 = 0 ;
V_7 -> V_13 = 32 ;
V_7 -> V_32 . V_33 = 0 ;
V_7 -> V_32 . V_34 = 0 ;
V_7 -> V_32 . V_35 = NULL ;
V_7 -> V_32 . V_36 = NULL ;
V_7 -> V_32 . V_37 = NULL ;
V_7 -> V_32 . V_38 = NULL ;
V_7 -> V_39 = V_16 -> V_40 + ( V_18 * 4 ) + ( V_21 * y1 ) ;
F_1 ( & V_1 , V_3 , V_5 , NULL ) ;
F_4 ( & V_1 , V_21 ) ;
V_16 -> V_25 . V_18 = 0 ;
V_16 -> V_25 . V_19 = 0 ;
V_16 -> V_25 . y1 = 0 ;
V_16 -> V_25 . V_20 = 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
struct V_41 * V_42 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned long V_33 , V_43 , V_44 , V_45 ;
struct V_46 * V_46 ;
int y1 , V_20 ;
V_44 = V_47 ;
V_45 = 0 ;
F_6 (page, pagelist, lru) {
V_33 = V_46 -> V_48 << V_49 ;
V_43 = V_33 + V_50 - 1 ;
V_44 = V_44 ( V_44 , V_33 ) ;
V_45 = V_45 ( V_45 , V_43 ) ;
}
if ( V_44 < V_45 ) {
y1 = V_44 / V_5 -> V_9 . V_51 ;
V_20 = ( V_45 / V_5 -> V_9 . V_51 ) + 1 ;
V_16 -> V_25 . V_18 = 0 ;
V_16 -> V_25 . y1 = y1 ;
V_16 -> V_25 . V_19 = V_5 -> V_52 . V_53 ;
V_16 -> V_25 . V_20 = V_20 ;
}
F_2 ( V_5 ) ;
}
static void F_7 ( struct V_15 * V_16 ,
const struct V_54 * V_55 )
{
struct V_56 * V_57 ;
unsigned long V_58 ;
V_57 = F_8 ( sizeof( struct V_56 ) , V_59 | V_60 ) ;
if ( ! V_57 )
return;
V_57 -> V_57 . V_61 = * V_55 ;
V_57 -> V_62 = NULL ;
V_57 -> V_63 = V_64 ;
F_9 ( & V_16 -> V_65 , V_58 ) ;
F_10 ( & V_57 -> V_66 , & V_16 -> V_67 ) ;
F_11 ( & V_16 -> V_65 , V_58 ) ;
}
static void F_12 ( struct V_15 * V_16 ,
const struct V_68 * V_69 )
{
struct V_56 * V_57 ;
unsigned long V_58 ;
V_57 = F_8 ( sizeof( struct V_56 ) , V_59 | V_60 ) ;
if ( ! V_57 )
return;
V_57 -> V_57 . V_70 = * V_69 ;
V_57 -> V_62 = NULL ;
V_57 -> V_63 = V_71 ;
F_9 ( & V_16 -> V_65 , V_58 ) ;
F_10 ( & V_57 -> V_66 , & V_16 -> V_67 ) ;
F_11 ( & V_16 -> V_65 , V_58 ) ;
}
static void F_13 ( struct V_15 * V_16 ,
const struct V_6 * V_6 )
{
struct V_56 * V_57 ;
unsigned long V_58 ;
T_2 V_72 = V_6 -> V_28 * V_6 -> V_29 * ( V_6 -> V_13 >= 8 ? V_6 -> V_13 / 8 : 1 ) ;
V_57 = F_8 ( sizeof( struct V_56 ) + V_72 , V_59 | V_60 ) ;
if ( ! V_57 )
return;
V_57 -> V_57 . V_73 = * V_6 ;
V_57 -> V_62 = ( void * ) ( V_57 + 1 ) ;
V_57 -> V_63 = V_74 ;
memcpy ( V_57 -> V_62 , V_6 -> V_39 , V_72 ) ;
V_57 -> V_57 . V_73 . V_39 = V_57 -> V_62 ;
F_9 ( & V_16 -> V_65 , V_58 ) ;
F_10 ( & V_57 -> V_66 , & V_16 -> V_67 ) ;
F_11 ( & V_16 -> V_65 , V_58 ) ;
}
static void F_14 ( struct V_4 * V_5 ,
const struct V_54 * V_55 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_75 V_76 ;
T_2 V_77 ;
int V_78 = V_55 -> V_26 ;
int V_79 = V_55 -> V_27 ;
int V_28 = V_55 -> V_28 ;
int V_29 = V_55 -> V_29 ;
T_3 V_80 ;
struct V_81 V_82 ;
if ( V_5 -> V_9 . V_8 == V_10 ||
V_5 -> V_9 . V_8 == V_11 )
V_77 = ( ( T_1 * ) ( V_5 -> V_12 ) ) [ V_55 -> V_77 ] ;
else
V_77 = V_55 -> V_77 ;
V_76 . V_83 = V_78 ;
V_76 . V_84 = V_78 + V_28 ;
V_76 . V_85 = V_79 ;
V_76 . V_86 = V_79 + V_29 ;
switch ( V_55 -> V_80 ) {
case V_87 :
V_80 = V_88 ;
break;
case V_89 :
V_80 = V_90 ;
break;
default:
F_15 ( L_2
L_3 ) ;
V_80 = V_90 ;
}
V_82 . V_3 = V_3 ;
V_82 . V_76 = V_76 ;
V_82 . V_77 = V_77 ;
V_82 . V_80 = V_80 ;
V_81 ( & V_82 ) ;
}
static void F_16 ( struct V_4 * V_5 ,
const struct V_54 * V_55 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
if ( ! F_17 () ) {
F_7 ( V_16 , V_55 ) ;
F_18 ( & V_3 -> V_91 ) ;
return;
}
F_19 ( & V_3 -> V_91 ) ;
F_14 ( V_5 , V_55 ) ;
}
static void F_20 ( struct V_4 * V_5 ,
const struct V_68 * V_92 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_21 ( V_16 -> V_3 ,
V_92 -> V_28 , V_92 -> V_29 ,
V_92 -> V_93 , V_92 -> V_94 ,
V_92 -> V_26 , V_92 -> V_27 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
const struct V_68 * V_92 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
if ( ! F_17 () ) {
F_12 ( V_16 , V_92 ) ;
F_18 ( & V_3 -> V_91 ) ;
return;
}
F_19 ( & V_3 -> V_91 ) ;
F_20 ( V_5 , V_92 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0 ) ;
}
static void F_24 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_1 V_1 ;
F_1 ( & V_1 , V_16 -> V_3 , V_5 , V_7 ) ;
F_23 ( & V_1 ) ;
}
static void F_25 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
if ( ! F_17 () ) {
F_13 ( V_16 , V_7 ) ;
F_18 ( & V_3 -> V_91 ) ;
return;
}
F_19 ( & V_3 -> V_91 ) ;
F_24 ( V_5 , V_7 ) ;
}
static void F_26 ( struct V_95 * V_96 )
{
struct V_2 * V_3 = F_27 ( V_96 , struct V_2 , V_91 ) ;
unsigned long V_58 ;
struct V_56 * V_97 , * V_98 ;
struct V_15 * V_16 = V_3 -> V_99 . V_16 ;
F_9 ( & V_16 -> V_65 , V_58 ) ;
F_28 (entry, tmp, &qfbdev->delayed_ops, head) {
F_11 ( & V_16 -> V_65 , V_58 ) ;
switch ( V_97 -> V_63 ) {
case V_64 :
F_14 ( V_16 -> V_100 . V_101 , & V_97 -> V_57 . V_61 ) ;
break;
case V_71 :
F_20 ( V_16 -> V_100 . V_101 , & V_97 -> V_57 . V_70 ) ;
break;
case V_74 :
F_24 ( V_16 -> V_100 . V_101 , & V_97 -> V_57 . V_73 ) ;
break;
}
F_9 ( & V_16 -> V_65 , V_58 ) ;
F_29 ( & V_97 -> V_66 ) ;
F_30 ( V_97 ) ;
}
F_11 ( & V_16 -> V_65 , V_58 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
F_32 ( & V_3 -> V_91 , F_26 ) ;
return 0 ;
}
static void F_33 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = F_34 ( V_103 ) ;
int V_106 ;
V_106 = F_35 ( V_105 , false ) ;
if ( F_36 ( V_106 == 0 ) ) {
F_37 ( V_105 ) ;
F_38 ( V_105 ) ;
F_39 ( V_105 ) ;
}
F_40 ( V_103 ) ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_107 * V_108 ,
T_2 * V_109 )
{
int V_110 ;
struct V_102 * V_103 = V_3 -> V_111 -> V_112 ;
F_42 ( ! V_103 ) ;
V_110 = F_43 ( V_108 , V_103 , V_109 ) ;
if ( V_110 )
return V_110 ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 ,
struct V_113 * V_114 ,
struct V_102 * * V_115 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_102 * V_103 = NULL ;
struct V_104 * V_105 = NULL ;
int V_106 ;
int V_116 , V_72 ;
int V_29 = V_114 -> V_29 ;
int V_117 ;
int V_13 ;
F_45 ( V_114 -> V_118 , & V_117 , & V_13 ) ;
V_72 = V_114 -> V_24 [ 0 ] * V_29 ;
V_116 = F_46 ( V_72 , V_50 ) ;
V_106 = F_47 ( V_3 , V_116 , 0 ,
V_119 ,
false ,
false ,
NULL ,
& V_103 ) ;
if ( V_106 ) {
F_15 ( L_4 ,
V_116 ) ;
return - V_120 ;
}
V_105 = F_34 ( V_103 ) ;
V_105 -> V_121 . V_28 = V_114 -> V_28 ;
V_105 -> V_121 . V_29 = V_114 -> V_29 ;
V_105 -> V_121 . V_21 = V_114 -> V_24 [ 0 ] ;
V_105 -> V_121 . V_122 = V_123 ;
V_106 = F_35 ( V_105 , false ) ;
if ( F_48 ( V_106 != 0 ) )
goto V_124;
V_106 = F_49 ( V_105 , V_119 , NULL ) ;
if ( V_106 ) {
F_39 ( V_105 ) ;
goto V_124;
}
V_106 = F_50 ( V_105 , NULL ) ;
F_39 ( V_105 ) ;
if ( V_106 )
goto V_124;
* V_115 = V_103 ;
return 0 ;
V_124:
F_33 ( V_103 ) ;
* V_115 = NULL ;
return V_106 ;
}
static int F_51 ( struct V_15 * V_16 ,
struct V_125 * V_126 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_4 * V_5 ;
struct V_127 * V_128 = NULL ;
struct V_113 V_114 ;
struct V_102 * V_103 = NULL ;
struct V_104 * V_105 = NULL ;
struct V_129 * V_129 = & V_3 -> V_130 -> V_131 ;
int V_106 ;
int V_72 ;
int V_117 = V_126 -> V_132 ;
int V_13 = V_126 -> V_133 ;
void * V_40 ;
V_114 . V_28 = V_126 -> V_134 ;
V_114 . V_29 = V_126 -> V_135 ;
V_114 . V_24 [ 0 ] = F_46 ( V_114 . V_28 * ( ( V_117 + 1 ) / 8 ) , 64 ) ;
V_114 . V_118 = F_52 ( V_117 , V_13 ) ;
V_106 = F_44 ( V_16 , & V_114 , & V_103 ) ;
V_105 = F_34 ( V_103 ) ;
F_53 ( V_3 , L_5 , V_136 , V_114 . V_28 ,
V_114 . V_29 , V_114 . V_24 [ 0 ] ) ;
V_40 = F_54 ( V_114 . V_24 [ 0 ] * V_114 . V_29 ) ;
F_42 ( ! V_40 ) ;
F_53 ( V_3 ,
L_6 ,
F_55 ( V_105 ) ,
F_56 ( V_105 ) ,
V_105 -> V_137 ,
V_40 ) ;
V_72 = V_114 . V_24 [ 0 ] * V_114 . V_29 ;
V_5 = F_57 ( 0 , V_129 ) ;
if ( V_5 == NULL ) {
V_106 = - V_120 ;
goto V_124;
}
V_5 -> V_17 = V_16 ;
F_58 ( V_3 -> V_138 , & V_16 -> V_22 , & V_114 , V_103 ) ;
V_128 = & V_16 -> V_22 . V_23 ;
V_16 -> V_100 . V_128 = V_128 ;
V_16 -> V_100 . V_101 = V_5 ;
V_16 -> V_40 = V_40 ;
strcpy ( V_5 -> V_9 . V_139 , L_7 ) ;
F_59 ( V_5 , V_128 -> V_24 [ 0 ] , V_128 -> V_13 ) ;
V_5 -> V_58 = V_140 | V_141 | V_142 ;
V_5 -> V_143 = & V_144 ;
V_5 -> V_9 . V_145 = V_3 -> V_146 ;
V_5 -> V_9 . V_147 = V_103 -> V_72 ;
V_5 -> V_148 = V_16 -> V_40 ;
V_5 -> V_149 = V_103 -> V_72 ;
F_60 ( V_5 , & V_16 -> V_100 , V_126 -> V_150 ,
V_126 -> V_151 ) ;
V_5 -> V_152 = F_61 ( 1 ) ;
if ( ! V_5 -> V_152 ) {
V_106 = - V_120 ;
goto V_124;
}
V_5 -> V_152 -> V_153 [ 0 ] . V_23 = V_3 -> V_138 -> V_154 . V_155 ;
V_5 -> V_152 -> V_153 [ 0 ] . V_72 = V_3 -> V_156 ;
V_5 -> V_9 . V_157 = 0 ;
V_5 -> V_9 . V_158 = 0 ;
if ( V_5 -> V_148 == NULL ) {
V_106 = - V_159 ;
goto V_124;
}
V_106 = F_62 ( & V_5 -> V_32 , 256 , 0 ) ;
if ( V_106 ) {
V_106 = - V_120 ;
goto V_124;
}
V_5 -> V_160 = & V_161 ;
F_63 ( V_5 ) ;
V_3 -> V_162 = V_5 ;
V_3 -> V_111 = & V_16 -> V_22 ;
F_64 ( L_8 , V_5 -> V_9 . V_145 , ( unsigned long ) V_5 -> V_149 ) ;
F_64 ( L_9 , V_128 -> V_13 , V_128 -> V_24 [ 0 ] , V_128 -> V_28 , V_128 -> V_29 ) ;
return 0 ;
V_124:
if ( V_105 ) {
V_106 = F_35 ( V_105 , false ) ;
if ( F_36 ( V_106 == 0 ) ) {
F_37 ( V_105 ) ;
F_38 ( V_105 ) ;
F_39 ( V_105 ) ;
}
}
if ( V_128 && V_106 ) {
F_65 ( V_103 ) ;
F_66 ( V_128 ) ;
F_30 ( V_128 ) ;
}
F_65 ( V_103 ) ;
return V_106 ;
}
static int F_67 (
struct V_163 * V_100 ,
struct V_125 * V_126 )
{
struct V_15 * V_16 = (struct V_15 * ) V_100 ;
int V_164 = 0 ;
int V_106 ;
if ( ! V_100 -> V_128 ) {
V_106 = F_51 ( V_16 , V_126 ) ;
if ( V_106 )
return V_106 ;
V_164 = 1 ;
}
return V_164 ;
}
static int F_68 ( struct V_165 * V_131 , struct V_15 * V_16 )
{
struct V_4 * V_5 ;
struct V_166 * V_22 = & V_16 -> V_22 ;
if ( V_16 -> V_100 . V_101 ) {
V_5 = V_16 -> V_100 . V_101 ;
F_69 ( V_5 ) ;
F_70 ( V_5 ) ;
}
if ( V_22 -> V_112 ) {
F_33 ( V_22 -> V_112 ) ;
V_22 -> V_112 = NULL ;
}
F_71 ( & V_16 -> V_100 ) ;
F_72 ( V_16 -> V_40 ) ;
F_66 ( & V_22 -> V_23 ) ;
return 0 ;
}
int F_73 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
int V_167 = 32 ;
int V_106 ;
V_16 = F_74 ( sizeof( struct V_15 ) , V_168 ) ;
if ( ! V_16 )
return - V_120 ;
V_16 -> V_3 = V_3 ;
V_3 -> V_99 . V_16 = V_16 ;
F_75 ( & V_16 -> V_65 ) ;
F_76 ( & V_16 -> V_67 ) ;
F_77 ( V_3 -> V_138 , & V_16 -> V_100 ,
& V_169 ) ;
V_106 = F_78 ( V_3 -> V_138 , & V_16 -> V_100 ,
V_170 ,
V_171 ) ;
if ( V_106 ) {
F_30 ( V_16 ) ;
return V_106 ;
}
F_79 ( & V_16 -> V_100 ) ;
F_80 ( & V_16 -> V_100 , V_167 ) ;
return 0 ;
}
void F_81 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_99 . V_16 )
return;
F_68 ( V_3 -> V_138 , V_3 -> V_99 . V_16 ) ;
F_30 ( V_3 -> V_99 . V_16 ) ;
V_3 -> V_99 . V_16 = NULL ;
}
void F_82 ( struct V_2 * V_3 , int V_172 )
{
F_83 ( V_3 -> V_99 . V_16 -> V_100 . V_101 , V_172 ) ;
}
bool F_84 ( struct V_2 * V_3 , struct V_104 * V_173 )
{
if ( V_173 == F_34 ( V_3 -> V_99 . V_16 -> V_22 . V_112 ) )
return true ;
return false ;
}
