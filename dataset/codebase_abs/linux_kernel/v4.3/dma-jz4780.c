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
static T_1 F_15 ( unsigned long V_15 , T_1 * V_24 )
{
int V_25 = F_16 ( V_15 ) - 1 ;
if ( V_25 == 3 )
V_25 = 2 ;
else if ( V_25 > 7 )
V_25 = 7 ;
* V_24 = V_25 ;
switch ( V_25 ) {
case 0 :
return V_26 ;
case 1 :
return V_27 ;
case 2 :
return V_28 ;
case 4 :
return V_29 ;
case 5 :
return V_30 ;
case 6 :
return V_31 ;
default:
return V_32 ;
}
}
static int F_17 ( struct V_1 * V_9 ,
struct V_33 * V_18 , T_2 V_34 , T_3 V_35 ,
enum V_36 V_37 )
{
struct V_38 * V_39 = & V_9 -> V_39 ;
T_1 V_40 , V_41 , V_42 ;
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
V_42 = F_15 ( V_34 | V_35 | ( V_40 * V_41 ) ,
& V_9 -> V_57 ) ;
switch ( V_40 ) {
case V_58 :
case V_59 :
break;
case V_60 :
V_40 = V_61 ;
break;
default:
return - V_62 ;
}
V_18 -> V_44 |= V_42 << V_63 ;
V_18 -> V_44 |= V_40 << V_64 ;
V_18 -> V_44 |= V_40 << V_65 ;
V_18 -> V_66 = V_35 >> V_9 -> V_57 ;
return 0 ;
}
static struct V_67 * F_18 (
struct V_2 * V_3 , struct V_68 * V_69 , unsigned int V_70 ,
enum V_36 V_37 , unsigned long V_71 ,
void * V_72 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
unsigned int V_73 ;
int V_74 ;
V_18 = F_9 ( V_9 , V_70 , V_75 ) ;
if ( ! V_18 )
return NULL ;
for ( V_73 = 0 ; V_73 < V_70 ; V_73 ++ ) {
V_74 = F_17 ( V_9 , & V_18 -> V_18 [ V_73 ] ,
F_19 ( & V_69 [ V_73 ] ) ,
F_20 ( & V_69 [ V_73 ] ) ,
V_37 ) ;
if ( V_74 < 0 )
return NULL ;
V_18 -> V_18 [ V_73 ] . V_44 |= V_76 ;
if ( V_73 != ( V_70 - 1 ) ) {
V_18 -> V_18 [ V_73 ] . V_44 |= V_77 ;
V_18 -> V_18 [ V_73 ] . V_66 |=
( ( ( V_73 + 1 ) * sizeof( * V_18 -> V_18 ) ) >> 4 ) << 24 ;
}
}
return F_21 ( & V_9 -> V_4 , & V_18 -> V_7 , V_71 ) ;
}
static struct V_67 * F_22 (
struct V_2 * V_3 , T_2 V_78 , T_3 V_79 ,
T_3 V_80 , enum V_36 V_37 ,
unsigned long V_71 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
unsigned int V_81 , V_73 ;
int V_74 ;
if ( V_79 % V_80 )
return NULL ;
V_81 = V_79 / V_80 ;
V_18 = F_9 ( V_9 , V_81 , V_82 ) ;
if ( ! V_18 )
return NULL ;
for ( V_73 = 0 ; V_73 < V_81 ; V_73 ++ ) {
V_74 = F_17 ( V_9 , & V_18 -> V_18 [ V_73 ] , V_78 ,
V_80 , V_37 ) ;
if ( V_74 < 0 )
return NULL ;
V_78 += V_80 ;
V_18 -> V_18 [ V_73 ] . V_44 |= V_76 | V_77 ;
if ( V_73 != ( V_81 - 1 ) ) {
V_18 -> V_18 [ V_73 ] . V_66 |=
( ( ( V_73 + 1 ) * sizeof( * V_18 -> V_18 ) ) >> 4 ) << 24 ;
}
}
return F_21 ( & V_9 -> V_4 , & V_18 -> V_7 , V_71 ) ;
}
struct V_67 * F_23 (
struct V_2 * V_3 , T_2 V_83 , T_2 V_84 ,
T_3 V_35 , unsigned long V_71 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
T_1 V_42 ;
V_18 = F_9 ( V_9 , 1 , V_85 ) ;
if ( ! V_18 )
return NULL ;
V_42 = F_15 ( V_83 | V_84 | V_35 ,
& V_9 -> V_57 ) ;
V_18 -> V_18 [ 0 ] . V_46 = V_84 ;
V_18 -> V_18 [ 0 ] . V_47 = V_83 ;
V_18 -> V_18 [ 0 ] . V_49 = V_86 ;
V_18 -> V_18 [ 0 ] . V_44 = V_76 | V_45 | V_53 |
V_42 << V_63 |
V_61 << V_64 |
V_61 << V_65 ;
V_18 -> V_18 [ 0 ] . V_66 = V_35 >> V_9 -> V_57 ;
return F_21 ( & V_9 -> V_4 , & V_18 -> V_7 , V_71 ) ;
}
static void F_24 ( struct V_1 * V_9 )
{
struct V_8 * V_12 = F_4 ( V_9 ) ;
struct V_6 * V_7 ;
unsigned int V_73 ;
T_2 V_22 ;
if ( ! V_9 -> V_18 ) {
V_7 = F_25 ( & V_9 -> V_4 ) ;
if ( ! V_7 )
return;
F_26 ( & V_7 -> V_87 ) ;
V_9 -> V_18 = F_3 ( V_7 ) ;
V_9 -> V_88 = 0 ;
if ( V_9 -> V_18 -> type == V_82 && V_7 -> V_23 . V_89 ) {
for ( V_73 = 0 ; V_73 < V_9 -> V_18 -> V_16 ; V_73 ++ )
V_9 -> V_18 -> V_18 [ V_73 ] . V_44 &= ~ V_77 ;
}
} else {
V_9 -> V_88 =
( V_9 -> V_88 + 1 ) % V_9 -> V_18 -> V_16 ;
}
F_7 ( V_12 , F_27 ( V_9 -> V_90 ) , V_91 ) ;
V_22 = V_9 -> V_18 -> V_22 +
( V_9 -> V_88 * sizeof( * V_9 -> V_18 -> V_18 ) ) ;
F_7 ( V_12 , F_28 ( V_9 -> V_90 ) , V_22 ) ;
F_7 ( V_12 , V_92 , F_29 ( V_9 -> V_90 ) ) ;
F_7 ( V_12 , F_27 ( V_9 -> V_90 ) ,
V_91 | V_93 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_71 ;
F_31 ( & V_9 -> V_4 . V_94 , V_71 ) ;
if ( F_32 ( & V_9 -> V_4 ) && ! V_9 -> V_18 )
F_24 ( V_9 ) ;
F_33 ( & V_9 -> V_4 . V_94 , V_71 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_8 * V_12 = F_4 ( V_9 ) ;
unsigned long V_71 ;
F_35 ( V_95 ) ;
F_31 ( & V_9 -> V_4 . V_94 , V_71 ) ;
F_7 ( V_12 , F_27 ( V_9 -> V_90 ) , 0 ) ;
if ( V_9 -> V_18 ) {
F_13 ( & V_9 -> V_18 -> V_7 ) ;
V_9 -> V_18 = NULL ;
}
F_36 ( & V_9 -> V_4 , & V_95 ) ;
F_33 ( & V_9 -> V_4 . V_94 , V_71 ) ;
F_37 ( & V_9 -> V_4 , & V_95 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ( V_39 -> V_55 == V_96 )
|| ( V_39 -> V_51 == V_96 ) )
return - V_62 ;
memcpy ( & V_9 -> V_39 , V_39 , sizeof( V_9 -> V_39 ) ) ;
return 0 ;
}
static T_3 F_39 ( struct V_1 * V_9 ,
struct V_5 * V_18 , unsigned int V_97 )
{
struct V_8 * V_12 = F_4 ( V_9 ) ;
unsigned int V_98 , V_16 ;
unsigned int V_73 ;
V_98 = 0 ;
for ( V_73 = V_97 ; V_73 < V_18 -> V_16 ; V_73 ++ )
V_98 += V_18 -> V_18 [ V_73 ] . V_66 << V_9 -> V_57 ;
if ( V_97 != 0 ) {
V_16 = F_5 ( V_12 ,
F_40 ( V_9 -> V_90 ) ) ;
V_98 += V_16 << V_9 -> V_57 ;
}
return V_98 ;
}
static enum V_99 F_41 ( struct V_2 * V_3 ,
T_4 V_100 , struct V_101 * V_102 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
enum V_99 V_103 ;
unsigned long V_71 ;
V_103 = F_42 ( V_3 , V_100 , V_102 ) ;
if ( ( V_103 == V_104 ) || ( V_102 == NULL ) )
return V_103 ;
F_31 ( & V_9 -> V_4 . V_94 , V_71 ) ;
V_7 = F_43 ( & V_9 -> V_4 , V_100 ) ;
if ( V_7 ) {
V_102 -> V_98 = F_39 ( V_9 ,
F_3 ( V_7 ) , 0 ) ;
} else if ( V_100 == V_9 -> V_18 -> V_7 . V_23 . V_100 ) {
V_102 -> V_98 = F_39 ( V_9 , V_9 -> V_18 ,
( V_9 -> V_88 + 1 ) % V_9 -> V_18 -> V_16 ) ;
} else
V_102 -> V_98 = 0 ;
if ( V_7 && V_9 -> V_18 && V_7 == & V_9 -> V_18 -> V_7
&& V_9 -> V_18 -> V_103 & ( V_105 | V_106 ) )
V_103 = V_107 ;
F_33 ( & V_9 -> V_4 . V_94 , V_71 ) ;
return V_103 ;
}
static void F_44 ( struct V_8 * V_12 ,
struct V_1 * V_9 )
{
T_1 V_108 ;
F_45 ( & V_9 -> V_4 . V_94 ) ;
V_108 = F_5 ( V_12 , F_27 ( V_9 -> V_90 ) ) ;
F_7 ( V_12 , F_27 ( V_9 -> V_90 ) , 0 ) ;
if ( V_108 & V_105 ) {
F_46 ( & V_9 -> V_4 . V_3 . V_109 -> V_10 ,
L_1 , V_108 ) ;
}
if ( V_108 & V_106 ) {
F_46 ( & V_9 -> V_4 . V_3 . V_109 -> V_10 ,
L_2 , V_108 ) ;
}
if ( V_9 -> V_18 ) {
V_9 -> V_18 -> V_103 = V_108 ;
if ( ( V_108 & ( V_105 | V_106 ) ) == 0 ) {
if ( V_9 -> V_18 -> type == V_82 ) {
F_47 ( & V_9 -> V_18 -> V_7 ) ;
} else {
F_48 ( & V_9 -> V_18 -> V_7 ) ;
V_9 -> V_18 = NULL ;
}
F_24 ( V_9 ) ;
}
} else {
F_49 ( & V_9 -> V_4 . V_3 . V_109 -> V_10 ,
L_3 ) ;
}
F_50 ( & V_9 -> V_4 . V_94 ) ;
}
static T_5 F_51 ( int V_110 , void * V_111 )
{
struct V_8 * V_12 = V_111 ;
T_1 V_112 , V_113 ;
int V_73 ;
V_112 = F_5 ( V_12 , V_114 ) ;
for ( V_73 = 0 ; V_73 < V_115 ; V_73 ++ ) {
if ( ! ( V_112 & ( 1 << V_73 ) ) )
continue;
F_44 ( V_12 , & V_12 -> V_3 [ V_73 ] ) ;
}
V_113 = F_5 ( V_12 , V_116 ) ;
V_113 &= ~ ( V_117 | V_118 ) ;
F_7 ( V_12 , V_116 , V_113 ) ;
F_7 ( V_12 , V_114 , 0 ) ;
return V_119 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_21 = F_53 ( F_54 ( & V_3 -> V_109 -> V_10 ) ,
V_3 -> V_10 -> V_109 ,
V_120 ,
V_121 , 0 ) ;
if ( ! V_9 -> V_21 ) {
F_49 ( & V_3 -> V_109 -> V_10 ,
L_4 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_56 ( & V_9 -> V_4 ) ;
F_57 ( V_9 -> V_21 ) ;
V_9 -> V_21 = NULL ;
}
static bool F_58 ( struct V_2 * V_3 , void * V_123 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_8 * V_12 = F_4 ( V_9 ) ;
struct V_124 * V_111 = V_123 ;
if ( V_12 -> V_11 . V_109 -> V_125 != V_111 -> V_125 )
return false ;
if ( V_111 -> V_126 > - 1 ) {
if ( V_111 -> V_126 != V_9 -> V_90 )
return false ;
} else if ( V_12 -> V_127 & F_29 ( V_9 -> V_90 ) ) {
return false ;
}
V_9 -> V_50 = V_111 -> V_50 ;
return true ;
}
static struct V_2 * F_59 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_8 * V_12 = V_131 -> V_132 ;
T_6 V_133 = V_12 -> V_11 . V_134 ;
struct V_124 V_111 ;
if ( V_129 -> V_135 != 2 )
return NULL ;
V_111 . V_125 = V_131 -> V_125 ;
V_111 . V_50 = V_129 -> args [ 0 ] ;
V_111 . V_126 = V_129 -> args [ 1 ] ;
if ( V_111 . V_126 > - 1 ) {
if ( V_111 . V_126 >= V_115 ) {
F_49 ( V_12 -> V_11 . V_109 ,
L_5 ,
V_111 . V_126 ) ;
return NULL ;
}
if ( ! ( V_12 -> V_127 & F_29 ( V_111 . V_126 ) ) ) {
F_49 ( V_12 -> V_11 . V_109 ,
L_6 ,
V_111 . V_126 ) ;
return NULL ;
}
V_12 -> V_3 [ V_111 . V_126 ] . V_50 = V_111 . V_50 ;
return F_60 (
& V_12 -> V_3 [ V_111 . V_126 ] . V_4 . V_3 ) ;
} else {
return F_61 ( V_133 , F_58 , & V_111 ) ;
}
}
static int F_62 ( struct V_136 * V_137 )
{
struct V_10 * V_109 = & V_137 -> V_109 ;
struct V_8 * V_12 ;
struct V_1 * V_9 ;
struct V_11 * V_138 ;
struct V_139 * V_140 ;
int V_73 , V_141 ;
V_12 = F_63 ( V_109 , sizeof( * V_12 ) , V_142 ) ;
if ( ! V_12 )
return - V_122 ;
F_64 ( V_137 , V_12 ) ;
V_140 = F_65 ( V_137 , V_143 , 0 ) ;
if ( ! V_140 ) {
F_49 ( V_109 , L_7 ) ;
return - V_62 ;
}
V_12 -> V_14 = F_66 ( V_109 , V_140 ) ;
if ( F_67 ( V_12 -> V_14 ) )
return F_68 ( V_12 -> V_14 ) ;
V_141 = F_69 ( V_137 , 0 ) ;
if ( V_141 < 0 ) {
F_49 ( V_109 , L_8 , V_141 ) ;
return V_141 ;
}
V_12 -> V_110 = V_141 ;
V_141 = F_70 ( V_12 -> V_110 , F_51 , 0 , F_54 ( V_109 ) ,
V_12 ) ;
if ( V_141 ) {
F_49 ( V_109 , L_9 , V_12 -> V_110 ) ;
return V_141 ;
}
V_12 -> V_144 = F_71 ( V_109 , NULL ) ;
if ( F_67 ( V_12 -> V_144 ) ) {
F_49 ( V_109 , L_10 ) ;
V_141 = F_68 ( V_12 -> V_144 ) ;
goto V_145;
}
F_72 ( V_12 -> V_144 ) ;
F_73 ( V_109 -> V_125 , L_11 ,
0 , & V_12 -> V_127 ) ;
V_138 = & V_12 -> V_11 ;
F_74 ( V_85 , V_138 -> V_134 ) ;
F_74 ( V_75 , V_138 -> V_134 ) ;
F_74 ( V_82 , V_138 -> V_134 ) ;
V_138 -> V_109 = V_109 ;
V_138 -> V_146 = V_147 ;
V_138 -> V_148 = F_52 ;
V_138 -> V_149 = F_55 ;
V_138 -> V_150 = F_18 ;
V_138 -> V_151 = F_22 ;
V_138 -> V_152 = F_23 ;
V_138 -> V_153 = F_38 ;
V_138 -> V_154 = F_34 ;
V_138 -> V_155 = F_41 ;
V_138 -> V_156 = F_30 ;
V_138 -> V_157 = V_158 ;
V_138 -> V_159 = V_158 ;
V_138 -> V_160 = F_29 ( V_161 ) | F_29 ( V_43 ) ;
V_138 -> V_162 = V_163 ;
F_7 ( V_12 , V_116 ,
V_164 | V_165 ) ;
F_7 ( V_12 , V_166 , 0 ) ;
F_75 ( & V_138 -> V_167 ) ;
for ( V_73 = 0 ; V_73 < V_115 ; V_73 ++ ) {
V_9 = & V_12 -> V_3 [ V_73 ] ;
V_9 -> V_90 = V_73 ;
F_76 ( & V_9 -> V_4 , V_138 ) ;
V_9 -> V_4 . V_168 = F_13 ;
}
V_141 = F_77 ( V_138 ) ;
if ( V_141 ) {
F_49 ( V_109 , L_12 ) ;
goto V_169;
}
V_141 = F_78 ( V_109 -> V_125 , F_59 ,
V_12 ) ;
if ( V_141 ) {
F_49 ( V_109 , L_13 ) ;
goto V_170;
}
F_79 ( V_109 , L_14 ) ;
return 0 ;
V_170:
F_80 ( V_138 ) ;
V_169:
F_81 ( V_12 -> V_144 ) ;
V_145:
F_82 ( V_12 -> V_110 , V_12 ) ;
return V_141 ;
}
static int F_83 ( struct V_136 * V_137 )
{
struct V_8 * V_12 = F_84 ( V_137 ) ;
int V_73 ;
F_85 ( V_137 -> V_109 . V_125 ) ;
F_82 ( V_12 -> V_110 , V_12 ) ;
for ( V_73 = 0 ; V_73 < V_115 ; V_73 ++ )
F_86 ( & V_12 -> V_3 [ V_73 ] . V_4 . V_171 ) ;
F_80 ( & V_12 -> V_11 ) ;
return 0 ;
}
static int T_7 F_87 ( void )
{
return F_88 ( & V_172 ) ;
}
static void T_8 F_89 ( void )
{
F_90 ( & V_172 ) ;
}
