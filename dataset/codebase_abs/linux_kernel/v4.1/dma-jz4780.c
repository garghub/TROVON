static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static inline struct V_5 * F_3 (
struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static inline struct V_8 * F_4 (
struct V_1 * V_9 )
{
return F_2 ( V_9 -> V_4 . V_3 . V_10 , struct V_8 ,
V_11 ) ;
}
static inline T_1 F_5 ( struct V_8 * V_12 ,
unsigned int V_13 )
{
return F_6 ( V_12 -> V_14 + V_13 ) ;
}
static inline void F_7 ( struct V_8 * V_12 ,
unsigned int V_13 , T_1 V_15 )
{
F_8 ( V_15 , V_12 -> V_14 + V_13 ) ;
}
static struct V_5 * F_9 (
struct V_1 * V_9 , unsigned int V_16 ,
enum V_17 type )
{
struct V_5 * V_18 ;
if ( V_16 > V_19 )
return NULL ;
V_18 = F_10 ( sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_18 = F_11 ( V_9 -> V_21 , V_20 ,
& V_18 -> V_22 ) ;
if ( ! V_18 -> V_18 ) {
F_12 ( V_18 ) ;
return NULL ;
}
V_18 -> V_16 = V_16 ;
V_18 -> type = type ;
return V_18 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_5 * V_18 = F_3 ( V_7 ) ;
struct V_1 * V_9 = F_1 ( V_7 -> V_23 . V_3 ) ;
F_14 ( V_9 -> V_21 , V_18 -> V_18 , V_18 -> V_22 ) ;
F_12 ( V_18 ) ;
}
static T_1 F_15 ( unsigned long V_15 , int * V_24 )
{
* V_24 = F_16 ( V_15 ) - 1 ;
switch ( * V_24 ) {
case 0 :
return V_25 ;
case 1 :
return V_26 ;
case 2 :
return V_27 ;
case 4 :
return V_28 ;
case 5 :
return V_29 ;
case 6 :
return V_30 ;
case 7 :
return V_31 ;
default:
return - V_32 ;
}
}
static T_1 F_17 ( struct V_1 * V_9 ,
struct V_33 * V_18 , T_2 V_34 , T_3 V_35 ,
enum V_36 V_37 )
{
struct V_38 * V_39 = & V_9 -> V_39 ;
T_1 V_40 , V_41 , V_42 ;
int V_24 ;
if ( V_37 == V_43 ) {
V_18 -> V_44 = V_45 ;
V_18 -> V_46 = V_34 ;
V_18 -> V_47 = V_39 -> V_48 ;
V_18 -> V_49 = V_9 -> V_50 ;
V_40 = V_39 -> V_51 ;
V_41 = V_39 -> V_52 ;
} else {
V_18 -> V_44 = V_53 ;
V_18 -> V_46 = V_39 -> V_54 ;
V_18 -> V_47 = V_34 ;
V_18 -> V_49 = V_9 -> V_50 ;
V_40 = V_39 -> V_55 ;
V_41 = V_39 -> V_56 ;
}
V_42 = F_15 ( V_34 | V_35 | ( V_40 * V_41 ) , & V_24 ) ;
V_9 -> V_57 = V_24 ;
switch ( V_40 ) {
case V_58 :
case V_59 :
break;
case V_60 :
V_40 = V_61 ;
break;
default:
return - V_32 ;
}
V_18 -> V_44 |= V_42 << V_62 ;
V_18 -> V_44 |= V_40 << V_63 ;
V_18 -> V_44 |= V_40 << V_64 ;
V_18 -> V_65 = V_35 >> V_24 ;
}
static struct V_66 * F_18 (
struct V_2 * V_3 , struct V_67 * V_68 , unsigned int V_69 ,
enum V_36 V_37 , unsigned long V_70 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
unsigned int V_71 ;
int V_72 ;
V_18 = F_9 ( V_9 , V_69 , V_73 ) ;
if ( ! V_18 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
V_72 = F_17 ( V_9 , & V_18 -> V_18 [ V_71 ] ,
F_19 ( & V_68 [ V_71 ] ) ,
F_20 ( & V_68 [ V_71 ] ) ,
V_37 ) ;
if ( V_72 < 0 )
return F_21 ( V_72 ) ;
V_18 -> V_18 [ V_71 ] . V_44 |= V_74 ;
if ( V_71 != ( V_69 - 1 ) ) {
V_18 -> V_18 [ V_71 ] . V_44 |= V_75 ;
V_18 -> V_18 [ V_71 ] . V_65 |=
( ( ( V_71 + 1 ) * sizeof( * V_18 -> V_18 ) ) >> 4 ) << 24 ;
}
}
return F_22 ( & V_9 -> V_4 , & V_18 -> V_7 , V_70 ) ;
}
static struct V_66 * F_23 (
struct V_2 * V_3 , T_2 V_76 , T_3 V_77 ,
T_3 V_78 , enum V_36 V_37 ,
unsigned long V_70 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
unsigned int V_79 , V_71 ;
int V_72 ;
if ( V_77 % V_78 )
return NULL ;
V_79 = V_77 / V_78 ;
V_18 = F_9 ( V_9 , V_79 , V_80 ) ;
if ( ! V_18 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_79 ; V_71 ++ ) {
V_72 = F_17 ( V_9 , & V_18 -> V_18 [ V_71 ] , V_76 ,
V_78 , V_37 ) ;
if ( V_72 < 0 )
return F_21 ( V_72 ) ;
V_76 += V_78 ;
V_18 -> V_18 [ V_71 ] . V_44 |= V_74 | V_75 ;
if ( V_71 != ( V_79 - 1 ) ) {
V_18 -> V_18 [ V_71 ] . V_65 |=
( ( ( V_71 + 1 ) * sizeof( * V_18 -> V_18 ) ) >> 4 ) << 24 ;
}
}
return F_22 ( & V_9 -> V_4 , & V_18 -> V_7 , V_70 ) ;
}
struct V_66 * F_24 (
struct V_2 * V_3 , T_2 V_81 , T_2 V_82 ,
T_3 V_35 , unsigned long V_70 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
T_1 V_42 ;
int V_24 ;
V_18 = F_9 ( V_9 , 1 , V_83 ) ;
if ( ! V_18 )
return NULL ;
V_42 = F_15 ( V_81 | V_82 | V_35 , & V_24 ) ;
if ( V_42 < 0 )
return F_21 ( V_42 ) ;
V_18 -> V_18 [ 0 ] . V_46 = V_82 ;
V_18 -> V_18 [ 0 ] . V_47 = V_81 ;
V_18 -> V_18 [ 0 ] . V_49 = V_84 ;
V_18 -> V_18 [ 0 ] . V_44 = V_74 | V_45 | V_53 |
V_42 << V_62 |
V_61 << V_63 |
V_61 << V_64 ;
V_18 -> V_18 [ 0 ] . V_65 = V_35 >> V_24 ;
return F_22 ( & V_9 -> V_4 , & V_18 -> V_7 , V_70 ) ;
}
static void F_25 ( struct V_1 * V_9 )
{
struct V_8 * V_12 = F_4 ( V_9 ) ;
struct V_6 * V_7 ;
unsigned int V_71 ;
T_2 V_22 ;
if ( ! V_9 -> V_18 ) {
V_7 = F_26 ( & V_9 -> V_4 ) ;
if ( ! V_7 )
return;
F_27 ( & V_7 -> V_85 ) ;
V_9 -> V_18 = F_3 ( V_7 ) ;
V_9 -> V_86 = 0 ;
if ( V_9 -> V_18 -> type == V_80 && V_7 -> V_23 . V_87 ) {
for ( V_71 = 0 ; V_71 < V_9 -> V_18 -> V_16 ; V_71 ++ )
V_9 -> V_18 -> V_18 [ V_71 ] . V_44 &= ~ V_75 ;
}
} else {
V_9 -> V_86 =
( V_9 -> V_86 + 1 ) % V_9 -> V_18 -> V_16 ;
}
F_7 ( V_12 , F_28 ( V_9 -> V_88 ) , V_89 ) ;
V_22 = V_9 -> V_18 -> V_22 +
( V_9 -> V_86 * sizeof( * V_9 -> V_18 -> V_18 ) ) ;
F_7 ( V_12 , F_29 ( V_9 -> V_88 ) , V_22 ) ;
F_7 ( V_12 , V_90 , F_30 ( V_9 -> V_88 ) ) ;
F_7 ( V_12 , F_28 ( V_9 -> V_88 ) ,
V_89 | V_91 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_70 ;
F_32 ( & V_9 -> V_4 . V_92 , V_70 ) ;
if ( F_33 ( & V_9 -> V_4 ) && ! V_9 -> V_18 )
F_25 ( V_9 ) ;
F_34 ( & V_9 -> V_4 . V_92 , V_70 ) ;
}
static int F_35 ( struct V_1 * V_9 )
{
struct V_8 * V_12 = F_4 ( V_9 ) ;
unsigned long V_70 ;
F_36 ( V_93 ) ;
F_32 ( & V_9 -> V_4 . V_92 , V_70 ) ;
F_7 ( V_12 , F_28 ( V_9 -> V_88 ) , 0 ) ;
if ( V_9 -> V_18 ) {
F_13 ( & V_9 -> V_18 -> V_7 ) ;
V_9 -> V_18 = NULL ;
}
F_37 ( & V_9 -> V_4 , & V_93 ) ;
F_34 ( & V_9 -> V_4 . V_92 , V_70 ) ;
F_38 ( & V_9 -> V_4 , & V_93 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_9 ,
const struct V_38 * V_39 )
{
if ( ( V_39 -> V_55 == V_94 )
|| ( V_39 -> V_51 == V_94 ) )
return - V_32 ;
memcpy ( & V_9 -> V_39 , V_39 , sizeof( V_9 -> V_39 ) ) ;
return 0 ;
}
static T_3 F_40 ( struct V_1 * V_9 ,
struct V_5 * V_18 , unsigned int V_95 )
{
struct V_8 * V_12 = F_4 ( V_9 ) ;
unsigned int V_96 , V_16 ;
unsigned int V_71 ;
V_96 = 0 ;
for ( V_71 = V_95 ; V_71 < V_18 -> V_16 ; V_71 ++ )
V_96 += V_18 -> V_18 [ V_71 ] . V_65 << V_9 -> V_57 ;
if ( V_95 != 0 ) {
V_16 = F_5 ( V_12 ,
F_41 ( V_9 -> V_88 ) ) ;
V_96 += V_16 << V_9 -> V_57 ;
}
return V_96 ;
}
static enum V_97 F_42 ( struct V_2 * V_3 ,
T_4 V_98 , struct V_99 * V_100 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
enum V_97 V_101 ;
unsigned long V_70 ;
V_101 = F_43 ( V_3 , V_98 , V_100 ) ;
if ( ( V_101 == V_102 ) || ( V_100 == NULL ) )
return V_101 ;
F_32 ( & V_9 -> V_4 . V_92 , V_70 ) ;
V_7 = F_44 ( & V_9 -> V_4 , V_98 ) ;
if ( V_7 ) {
V_100 -> V_96 = F_40 ( V_9 ,
F_3 ( V_7 ) , 0 ) ;
} else if ( V_98 == V_9 -> V_18 -> V_7 . V_23 . V_98 ) {
V_100 -> V_96 = F_40 ( V_9 , V_9 -> V_18 ,
( V_9 -> V_86 + 1 ) % V_9 -> V_18 -> V_16 ) ;
} else
V_100 -> V_96 = 0 ;
if ( V_7 && V_9 -> V_18 && V_7 == & V_9 -> V_18 -> V_7
&& V_9 -> V_18 -> V_101 & ( V_103 | V_104 ) )
V_101 = V_105 ;
F_34 ( & V_9 -> V_4 . V_92 , V_70 ) ;
return V_101 ;
}
static void F_45 ( struct V_8 * V_12 ,
struct V_1 * V_9 )
{
T_1 V_106 ;
F_46 ( & V_9 -> V_4 . V_92 ) ;
V_106 = F_5 ( V_12 , F_28 ( V_9 -> V_88 ) ) ;
F_7 ( V_12 , F_28 ( V_9 -> V_88 ) , 0 ) ;
if ( V_106 & V_103 ) {
F_47 ( & V_9 -> V_4 . V_3 . V_107 -> V_10 ,
L_1 , V_106 ) ;
}
if ( V_106 & V_104 ) {
F_47 ( & V_9 -> V_4 . V_3 . V_107 -> V_10 ,
L_2 , V_106 ) ;
}
if ( V_9 -> V_18 ) {
V_9 -> V_18 -> V_101 = V_106 ;
if ( ( V_106 & ( V_103 | V_104 ) ) == 0 ) {
if ( V_9 -> V_18 -> type == V_80 ) {
F_48 ( & V_9 -> V_18 -> V_7 ) ;
} else {
F_49 ( & V_9 -> V_18 -> V_7 ) ;
V_9 -> V_18 = NULL ;
}
F_25 ( V_9 ) ;
}
} else {
F_50 ( & V_9 -> V_4 . V_3 . V_107 -> V_10 ,
L_3 ) ;
}
F_51 ( & V_9 -> V_4 . V_92 ) ;
}
static T_5 F_52 ( int V_108 , void * V_109 )
{
struct V_8 * V_12 = V_109 ;
T_1 V_110 , V_111 ;
int V_71 ;
V_110 = F_5 ( V_12 , V_112 ) ;
for ( V_71 = 0 ; V_71 < V_113 ; V_71 ++ ) {
if ( ! ( V_110 & ( 1 << V_71 ) ) )
continue;
F_45 ( V_12 , & V_12 -> V_3 [ V_71 ] ) ;
}
V_111 = F_5 ( V_12 , V_114 ) ;
V_111 &= ~ ( V_115 | V_116 ) ;
F_7 ( V_12 , V_114 , V_111 ) ;
F_7 ( V_12 , V_112 , 0 ) ;
return V_117 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_21 = F_54 ( F_55 ( & V_3 -> V_107 -> V_10 ) ,
V_3 -> V_10 -> V_107 ,
V_118 ,
V_119 , 0 ) ;
if ( ! V_9 -> V_21 ) {
F_50 ( & V_3 -> V_107 -> V_10 ,
L_4 ) ;
return - V_120 ;
}
return 0 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_57 ( & V_9 -> V_4 ) ;
F_58 ( V_9 -> V_21 ) ;
V_9 -> V_21 = NULL ;
}
static bool F_59 ( struct V_2 * V_3 , void * V_121 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_8 * V_12 = F_4 ( V_9 ) ;
struct V_122 * V_109 = V_121 ;
if ( V_109 -> V_123 > - 1 ) {
if ( V_109 -> V_123 != V_9 -> V_88 )
return false ;
} else if ( V_12 -> V_124 & F_30 ( V_9 -> V_88 ) ) {
return false ;
}
V_9 -> V_50 = V_109 -> V_50 ;
return true ;
}
static struct V_2 * F_60 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
struct V_8 * V_12 = V_128 -> V_129 ;
T_6 V_130 = V_12 -> V_11 . V_131 ;
struct V_122 V_109 ;
if ( V_126 -> V_132 != 2 )
return NULL ;
V_109 . V_50 = V_126 -> args [ 0 ] ;
V_109 . V_123 = V_126 -> args [ 1 ] ;
if ( V_109 . V_123 > - 1 ) {
if ( V_109 . V_123 >= V_113 ) {
F_50 ( V_12 -> V_11 . V_107 ,
L_5 ,
V_109 . V_123 ) ;
return NULL ;
}
if ( ! ( V_12 -> V_124 & F_30 ( V_109 . V_123 ) ) ) {
F_50 ( V_12 -> V_11 . V_107 ,
L_6 ,
V_109 . V_123 ) ;
return NULL ;
}
}
return F_61 ( V_130 , F_59 , & V_109 ) ;
}
static int F_62 ( struct V_133 * V_134 )
{
struct V_10 * V_107 = & V_134 -> V_107 ;
struct V_8 * V_12 ;
struct V_1 * V_9 ;
struct V_11 * V_135 ;
struct V_136 * V_137 ;
int V_71 , V_138 ;
V_12 = F_63 ( V_107 , sizeof( * V_12 ) , V_139 ) ;
if ( ! V_12 )
return - V_120 ;
F_64 ( V_134 , V_12 ) ;
V_137 = F_65 ( V_134 , V_140 , 0 ) ;
if ( ! V_137 ) {
F_50 ( V_107 , L_7 ) ;
return - V_32 ;
}
V_12 -> V_14 = F_66 ( V_107 , V_137 ) ;
if ( F_67 ( V_12 -> V_14 ) )
return F_68 ( V_12 -> V_14 ) ;
V_12 -> V_108 = F_69 ( V_134 , 0 ) ;
if ( V_12 -> V_108 < 0 ) {
F_50 ( V_107 , L_8 , V_138 ) ;
return V_12 -> V_108 ;
}
V_138 = F_70 ( V_107 , V_12 -> V_108 , F_52 , 0 ,
F_55 ( V_107 ) , V_12 ) ;
if ( V_138 ) {
F_50 ( V_107 , L_9 , V_12 -> V_108 ) ;
return - V_32 ;
}
V_12 -> V_141 = F_71 ( V_107 , NULL ) ;
if ( F_67 ( V_12 -> V_141 ) ) {
F_50 ( V_107 , L_10 ) ;
return F_68 ( V_12 -> V_141 ) ;
}
F_72 ( V_12 -> V_141 ) ;
F_73 ( V_107 -> V_142 , L_11 ,
0 , & V_12 -> V_124 ) ;
V_135 = & V_12 -> V_11 ;
F_74 ( V_83 , V_135 -> V_131 ) ;
F_74 ( V_73 , V_135 -> V_131 ) ;
F_74 ( V_80 , V_135 -> V_131 ) ;
V_135 -> V_107 = V_107 ;
V_135 -> V_143 = 2 ;
V_135 -> V_144 = F_53 ;
V_135 -> V_145 = F_56 ;
V_135 -> V_146 = F_18 ;
V_135 -> V_147 = F_23 ;
V_135 -> V_148 = F_24 ;
V_135 -> V_149 = F_39 ;
V_135 -> V_150 = F_35 ;
V_135 -> V_151 = F_42 ;
V_135 -> V_152 = F_31 ;
V_135 -> V_153 = V_154 ;
V_135 -> V_155 = V_154 ;
V_135 -> V_156 = F_30 ( V_157 ) | F_30 ( V_43 ) ;
V_135 -> V_158 = V_159 ;
F_7 ( V_12 , V_114 ,
V_160 | V_161 ) ;
F_7 ( V_12 , V_162 , 0 ) ;
F_75 ( & V_135 -> V_163 ) ;
for ( V_71 = 0 ; V_71 < V_113 ; V_71 ++ ) {
V_9 = & V_12 -> V_3 [ V_71 ] ;
V_9 -> V_88 = V_71 ;
F_76 ( & V_9 -> V_4 , V_135 ) ;
V_9 -> V_4 . V_164 = F_13 ;
}
V_138 = F_77 ( V_135 ) ;
if ( V_138 ) {
F_50 ( V_107 , L_12 ) ;
goto V_165;
}
V_138 = F_78 ( V_107 -> V_142 , F_60 ,
V_12 ) ;
if ( V_138 ) {
F_50 ( V_107 , L_13 ) ;
goto V_166;
}
F_79 ( V_107 , L_14 ) ;
return 0 ;
V_166:
F_80 ( V_135 ) ;
V_165:
F_81 ( V_12 -> V_141 ) ;
return V_138 ;
}
static int F_82 ( struct V_133 * V_134 )
{
struct V_8 * V_12 = F_83 ( V_134 ) ;
F_84 ( V_134 -> V_107 . V_142 ) ;
F_85 ( & V_134 -> V_107 , V_12 -> V_108 , V_12 ) ;
F_80 ( & V_12 -> V_11 ) ;
return 0 ;
}
static int T_7 F_86 ( void )
{
return F_87 ( & V_167 ) ;
}
static void T_8 F_88 ( void )
{
F_89 ( & V_167 ) ;
}
