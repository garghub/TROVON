int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 ) && F_3 ( V_2 ) )
return 1 ;
if ( F_4 ( V_2 ) >= 9 )
return 1 ;
if ( V_3 == 0 )
return 0 ;
if ( F_2 ( V_2 ) &&
F_5 ( V_2 ) &&
V_4 . V_5 >= 0 )
return 1 ;
return 0 ;
}
static void
F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_7 -> V_9 [ V_9 -> V_12 ] ;
T_1 V_13 ;
F_7 ( V_14 > ( 1 << V_15 ) ) ;
V_13 = V_7 -> V_16 ;
V_13 |= F_8 ( V_11 -> V_17 ) + V_18 * V_19 ;
V_13 |= ( T_1 ) V_7 -> V_20 << V_21 ;
V_11 -> V_22 = V_13 ;
}
T_2 F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
return V_7 -> V_9 [ V_9 -> V_12 ] . V_22 ;
}
static inline void
F_10 ( struct V_23 * V_24 ,
unsigned long V_25 )
{
if ( ! F_11 ( V_26 ) )
return;
F_12 ( & V_24 -> V_9 -> V_27 ,
V_25 , V_24 ) ;
}
static void
F_13 ( struct V_28 * V_29 , T_3 * V_30 )
{
F_14 ( V_29 , V_30 , 3 ) ;
F_14 ( V_29 , V_30 , 2 ) ;
F_14 ( V_29 , V_30 , 1 ) ;
F_14 ( V_29 , V_30 , 0 ) ;
}
static T_1 F_15 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = & V_24 -> V_7 -> V_9 [ V_24 -> V_9 -> V_12 ] ;
struct V_28 * V_29 =
V_24 -> V_7 -> V_29 ? : V_24 -> V_4 -> V_31 . V_32 ;
T_3 * V_30 = V_11 -> V_33 ;
V_30 [ V_34 + 1 ] = F_16 ( V_24 -> V_35 , V_24 -> V_36 ) ;
if ( V_29 && ! F_17 ( & V_29 -> V_37 ) )
F_13 ( V_29 , V_30 ) ;
return V_11 -> V_22 ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
struct V_38 * V_39 = V_9 -> V_38 ;
T_3 T_4 * V_40 =
V_2 -> V_41 + F_19 ( F_20 ( V_9 ) ) ;
T_1 V_13 [ 2 ] ;
F_21 ( V_39 [ 0 ] . V_42 > 1 ) ;
if ( ! V_39 [ 0 ] . V_42 )
F_10 ( V_39 [ 0 ] . V_43 ,
V_44 ) ;
V_13 [ 0 ] = F_15 ( V_39 [ 0 ] . V_43 ) ;
F_22 ( V_39 [ 0 ] . V_45 = F_23 ( V_13 [ 0 ] ) ) ;
V_39 [ 0 ] . V_42 ++ ;
if ( V_39 [ 1 ] . V_43 ) {
F_21 ( V_39 [ 1 ] . V_42 ) ;
F_10 ( V_39 [ 1 ] . V_43 ,
V_44 ) ;
V_13 [ 1 ] = F_15 ( V_39 [ 1 ] . V_43 ) ;
F_22 ( V_39 [ 1 ] . V_45 = F_23 ( V_13 [ 1 ] ) ) ;
V_39 [ 1 ] . V_42 = 1 ;
} else {
V_13 [ 1 ] = 0 ;
}
F_21 ( V_13 [ 0 ] == V_13 [ 1 ] ) ;
F_24 ( F_23 ( V_13 [ 1 ] ) , V_40 ) ;
F_24 ( F_25 ( V_13 [ 1 ] ) , V_40 ) ;
F_24 ( F_23 ( V_13 [ 0 ] ) , V_40 ) ;
F_24 ( F_25 ( V_13 [ 0 ] ) , V_40 ) ;
}
static bool F_26 ( const struct V_6 * V_7 )
{
return ( F_11 ( V_26 ) &&
F_27 ( V_7 ) ) ;
}
static bool F_28 ( const struct V_6 * V_46 ,
const struct V_6 * V_47 )
{
if ( V_46 != V_47 )
return false ;
if ( F_26 ( V_46 ) )
return false ;
return true ;
}
static void F_29 ( struct V_8 * V_9 )
{
struct V_23 * V_48 ;
struct V_38 * V_39 = V_9 -> V_38 ;
struct V_49 * V_50 ;
bool V_51 = false ;
V_48 = V_39 -> V_43 ;
if ( V_48 )
V_48 -> V_36 = V_48 -> V_52 ;
F_21 ( V_39 [ 1 ] . V_43 ) ;
F_30 ( & V_9 -> V_53 -> V_54 ) ;
V_50 = V_9 -> V_55 ;
while ( V_50 ) {
struct V_23 * V_56 =
F_31 ( V_50 , F_32 ( * V_56 ) , V_57 . V_58 ) ;
if ( V_48 && ! F_28 ( V_56 -> V_7 , V_48 -> V_7 ) ) {
if ( V_39 != V_9 -> V_38 )
break;
if ( F_26 ( V_48 -> V_7 ) ||
F_26 ( V_56 -> V_7 ) )
break;
F_21 ( V_48 -> V_7 == V_56 -> V_7 ) ;
F_33 ( & V_39 -> V_43 , V_48 ) ;
V_39 ++ ;
}
V_50 = F_34 ( V_50 ) ;
F_35 ( & V_56 -> V_57 . V_58 , & V_9 -> V_59 ) ;
F_36 ( & V_56 -> V_57 . V_58 ) ;
V_56 -> V_57 . V_60 = V_61 ;
F_37 ( V_56 ) ;
F_38 ( V_56 , V_39 - V_9 -> V_38 ) ;
V_48 = V_56 ;
V_51 = true ;
}
if ( V_51 ) {
F_33 ( & V_39 -> V_43 , V_48 ) ;
V_9 -> V_55 = V_50 ;
}
F_39 ( & V_9 -> V_53 -> V_54 ) ;
if ( V_51 )
F_18 ( V_9 ) ;
}
static bool F_40 ( struct V_8 * V_9 )
{
return ! V_9 -> V_38 [ 0 ] . V_43 ;
}
static bool F_41 ( const struct V_8 * V_9 )
{
const struct V_38 * V_39 = V_9 -> V_38 ;
return V_39 [ 0 ] . V_42 + V_39 [ 1 ] . V_42 < 2 ;
}
static void F_42 ( unsigned long V_62 )
{
struct V_8 * V_9 = (struct V_8 * ) V_62 ;
struct V_38 * V_39 = V_9 -> V_38 ;
struct V_1 * V_2 = V_9 -> V_4 ;
F_43 ( V_2 , V_9 -> V_63 ) ;
while ( F_44 ( V_64 , & V_9 -> V_65 ) ) {
T_3 T_4 * V_66 =
V_2 -> V_41 + F_19 ( F_45 ( V_9 ) ) ;
T_3 T_4 * V_67 =
V_2 -> V_41 + F_19 ( F_46 ( V_9 , 0 ) ) ;
unsigned int V_68 , V_36 ;
F_47 ( V_64 , & V_9 -> V_65 ) ;
V_68 = F_48 ( V_66 ) ;
V_36 = F_49 ( V_68 ) ;
V_68 = F_50 ( V_68 ) ;
while ( V_68 != V_36 ) {
unsigned int V_25 ;
if ( ++ V_68 == V_69 )
V_68 = 0 ;
V_25 = F_48 ( V_67 + 2 * V_68 ) ;
if ( ! ( V_25 & V_70 ) )
continue;
F_51 ( F_48 ( V_67 + 2 * V_68 + 1 ) !=
V_39 [ 0 ] . V_45 ) ;
F_21 ( V_39 [ 0 ] . V_42 == 0 ) ;
if ( -- V_39 [ 0 ] . V_42 == 0 ) {
F_21 ( V_25 & V_71 ) ;
F_21 ( ! F_52 ( V_39 [ 0 ] . V_43 ) ) ;
F_10 ( V_39 [ 0 ] . V_43 ,
V_72 ) ;
F_53 ( V_39 [ 0 ] . V_43 ) ;
F_54 ( V_39 [ 0 ] . V_43 ) ;
V_39 [ 0 ] = V_39 [ 1 ] ;
memset ( & V_39 [ 1 ] , 0 , sizeof( V_39 [ 1 ] ) ) ;
}
F_21 ( V_39 [ 0 ] . V_42 == 0 &&
! ( V_25 & V_73 ) ) ;
}
F_24 ( F_55 ( V_74 , V_68 << 8 ) ,
V_66 ) ;
}
if ( F_41 ( V_9 ) )
F_29 ( V_9 ) ;
F_56 ( V_2 , V_9 -> V_63 ) ;
}
static bool F_57 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_49 * * V_79 , * V_50 ;
bool V_80 = true ;
V_50 = NULL ;
V_79 = & V_78 -> V_49 ;
while ( * V_79 ) {
struct V_75 * V_81 ;
V_50 = * V_79 ;
V_81 = F_31 ( V_50 , F_32 ( * V_81 ) , V_58 ) ;
if ( V_76 -> V_60 > V_81 -> V_60 ) {
V_79 = & V_50 -> V_82 ;
} else {
V_79 = & V_50 -> V_83 ;
V_80 = false ;
}
}
F_58 ( & V_76 -> V_58 , V_50 , V_79 ) ;
F_59 ( & V_76 -> V_58 , V_78 ) ;
return V_80 ;
}
static void F_60 ( struct V_23 * V_43 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
unsigned long V_84 ;
F_61 ( & V_9 -> V_53 -> V_54 , V_84 ) ;
if ( F_57 ( & V_43 -> V_57 , & V_9 -> V_59 ) ) {
V_9 -> V_55 = & V_43 -> V_57 . V_58 ;
if ( F_41 ( V_9 ) )
F_62 ( & V_9 -> V_85 ) ;
}
F_63 ( & V_9 -> V_53 -> V_54 , V_84 ) ;
}
static struct V_8 *
F_64 ( struct V_75 * V_76 , struct V_8 * V_86 )
{
struct V_8 * V_9 =
F_65 ( V_76 , struct V_23 , V_57 ) -> V_9 ;
F_21 ( ! V_86 ) ;
if ( V_9 != V_86 ) {
F_66 ( & V_86 -> V_53 -> V_54 ) ;
F_67 ( & V_9 -> V_53 -> V_54 ) ;
}
return V_9 ;
}
static void F_68 ( struct V_23 * V_43 , int V_87 )
{
struct V_8 * V_9 ;
struct V_88 * V_89 , * V_79 ;
struct V_88 V_90 ;
F_69 ( V_91 ) ;
if ( V_87 <= F_70 ( V_43 -> V_57 . V_60 ) )
return;
F_71 ( & V_43 -> V_4 -> V_92 . V_93 ) ;
V_90 . V_94 = & V_43 -> V_57 ;
F_72 ( & V_90 . V_95 , & V_91 ) ;
F_73 (dep, p, &dfs, dfs_link) {
struct V_75 * V_76 = V_89 -> V_94 ;
F_74 (p, &pt->signalers_list, signal_link) {
F_21 ( V_79 -> V_94 -> V_60 < V_76 -> V_60 ) ;
if ( V_87 > F_70 ( V_79 -> V_94 -> V_60 ) )
F_75 ( & V_79 -> V_95 , & V_91 ) ;
}
F_76 ( V_89 , V_79 , V_95 ) ;
}
V_9 = V_43 -> V_9 ;
F_30 ( & V_9 -> V_53 -> V_54 ) ;
F_77 (dep, p, &dfs, dfs_link) {
struct V_75 * V_76 = V_89 -> V_94 ;
F_78 ( & V_89 -> V_95 ) ;
V_9 = F_64 ( V_76 , V_9 ) ;
if ( V_87 <= V_76 -> V_60 )
continue;
V_76 -> V_60 = V_87 ;
if ( ! F_79 ( & V_76 -> V_58 ) ) {
F_35 ( & V_76 -> V_58 , & V_9 -> V_59 ) ;
if ( F_57 ( V_76 , & V_9 -> V_59 ) )
V_9 -> V_55 = & V_76 -> V_58 ;
}
}
F_39 ( & V_9 -> V_53 -> V_54 ) ;
}
static int F_80 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_9 [ V_9 -> V_12 ] ;
unsigned int V_84 ;
void * V_96 ;
int V_97 ;
F_71 ( & V_7 -> V_4 -> V_92 . V_93 ) ;
if ( V_11 -> V_98 ++ )
return 0 ;
F_21 ( ! V_11 -> V_98 ) ;
if ( ! V_11 -> V_17 ) {
V_97 = F_81 ( V_7 , V_9 ) ;
if ( V_97 )
goto V_99;
}
F_21 ( ! V_11 -> V_17 ) ;
V_84 = V_100 | V_101 ;
if ( V_7 -> V_102 )
V_84 |= V_103 | V_7 -> V_102 ;
V_97 = F_82 ( V_11 -> V_17 , 0 , V_104 , V_84 ) ;
if ( V_97 )
goto V_99;
V_96 = F_83 ( V_11 -> V_17 -> V_105 , V_106 ) ;
if ( F_84 ( V_96 ) ) {
V_97 = F_85 ( V_96 ) ;
goto V_107;
}
V_97 = F_86 ( V_11 -> V_35 , V_7 -> V_102 ) ;
if ( V_97 )
goto V_108;
F_6 ( V_7 , V_9 ) ;
V_11 -> V_33 = V_96 + V_109 * V_19 ;
V_11 -> V_33 [ V_110 + 1 ] =
F_8 ( V_11 -> V_35 -> V_111 ) ;
V_11 -> V_17 -> V_105 -> V_31 . V_112 = true ;
F_87 ( V_7 ) ;
return 0 ;
V_108:
F_88 ( V_11 -> V_17 -> V_105 ) ;
V_107:
F_89 ( V_11 -> V_17 ) ;
V_99:
V_11 -> V_98 = 0 ;
return V_97 ;
}
static void F_90 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_9 [ V_9 -> V_12 ] ;
F_71 ( & V_7 -> V_4 -> V_92 . V_93 ) ;
F_21 ( V_11 -> V_98 == 0 ) ;
if ( -- V_11 -> V_98 )
return;
F_91 ( V_11 -> V_35 ) ;
F_88 ( V_11 -> V_17 -> V_105 ) ;
F_92 ( V_11 -> V_17 ) ;
F_93 ( V_7 ) ;
}
static int F_94 ( struct V_23 * V_43 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
struct V_10 * V_11 = & V_43 -> V_7 -> V_9 [ V_9 -> V_12 ] ;
T_3 * V_113 ;
int V_97 ;
F_21 ( ! V_11 -> V_98 ) ;
V_43 -> V_114 += V_115 ;
F_21 ( ! V_11 -> V_35 ) ;
V_43 -> V_35 = V_11 -> V_35 ;
if ( V_4 . V_116 ) {
V_97 = F_95 ( V_43 ) ;
if ( V_97 )
goto V_99;
}
V_113 = F_96 ( V_43 , 0 ) ;
if ( F_84 ( V_113 ) ) {
V_97 = F_85 ( V_113 ) ;
goto V_117;
}
if ( ! V_11 -> V_118 ) {
V_97 = V_9 -> V_119 ( V_43 ) ;
if ( V_97 )
goto V_117;
V_11 -> V_118 = true ;
}
V_43 -> V_114 -= V_115 ;
return 0 ;
V_117:
if ( V_4 . V_116 )
F_97 ( V_43 ) ;
V_99:
return V_97 ;
}
static T_3 *
F_98 ( struct V_8 * V_9 , T_3 * V_120 )
{
* V_120 ++ = V_121 | V_122 ;
* V_120 ++ = F_19 ( V_123 ) ;
* V_120 ++ = F_8 ( V_9 -> V_124 ) + 256 ;
* V_120 ++ = 0 ;
* V_120 ++ = F_99 ( 1 ) ;
* V_120 ++ = F_19 ( V_123 ) ;
* V_120 ++ = 0x40400000 | V_125 ;
V_120 = F_100 ( V_120 ,
V_126 |
V_127 ,
0 ) ;
* V_120 ++ = V_128 | V_122 ;
* V_120 ++ = F_19 ( V_123 ) ;
* V_120 ++ = F_8 ( V_9 -> V_124 ) + 256 ;
* V_120 ++ = 0 ;
return V_120 ;
}
static T_3 * F_101 ( struct V_8 * V_9 , T_3 * V_120 )
{
* V_120 ++ = V_129 | V_130 ;
if ( F_102 ( V_9 -> V_4 ) )
V_120 = F_98 ( V_9 , V_120 ) ;
V_120 = F_100 ( V_120 ,
V_131 |
V_132 |
V_126 |
V_133 ,
F_8 ( V_9 -> V_124 ) +
2 * V_134 ) ;
while ( ( unsigned long ) V_120 % V_134 )
* V_120 ++ = V_135 ;
return V_120 ;
}
static T_3 * F_103 ( struct V_8 * V_9 , T_3 * V_120 )
{
* V_120 ++ = V_129 | V_136 ;
* V_120 ++ = V_137 ;
return V_120 ;
}
static T_3 * F_104 ( struct V_8 * V_9 , T_3 * V_120 )
{
V_120 = F_98 ( V_9 , V_120 ) ;
* V_120 ++ = F_99 ( 1 ) ;
* V_120 ++ = F_19 ( V_138 ) ;
* V_120 ++ = F_105 (
V_139 ) ;
* V_120 ++ = V_135 ;
if ( F_106 ( V_9 -> V_4 , 0 , V_140 ) ) {
V_120 = F_100 ( V_120 ,
V_131 |
V_132 |
V_126 |
V_133 ,
F_8 ( V_9 -> V_124 )
+ 2 * V_134 ) ;
}
if ( F_107 ( V_9 -> V_4 ) ) {
* V_120 ++ = V_141 ;
* V_120 ++ = V_142 ;
* V_120 ++ = 0x00777000 ;
* V_120 ++ = 0 ;
* V_120 ++ = 0 ;
* V_120 ++ = 0 ;
}
while ( ( unsigned long ) V_120 % V_134 )
* V_120 ++ = V_135 ;
return V_120 ;
}
static T_3 * F_108 ( struct V_8 * V_9 , T_3 * V_120 )
{
* V_120 ++ = V_137 ;
return V_120 ;
}
static int F_109 ( struct V_8 * V_9 )
{
struct V_143 * V_105 ;
struct V_144 * V_111 ;
int V_99 ;
V_105 = F_110 ( V_9 -> V_4 , V_145 ) ;
if ( F_84 ( V_105 ) )
return F_85 ( V_105 ) ;
V_111 = F_111 ( V_105 , & V_9 -> V_4 -> V_146 . V_37 , NULL ) ;
if ( F_84 ( V_111 ) ) {
V_99 = F_85 ( V_111 ) ;
goto V_99;
}
V_99 = F_82 ( V_111 , 0 , V_19 , V_100 | V_101 ) ;
if ( V_99 )
goto V_99;
V_9 -> V_147 . V_111 = V_111 ;
return 0 ;
V_99:
F_112 ( V_105 ) ;
return V_99 ;
}
static void F_113 ( struct V_8 * V_9 )
{
F_114 ( & V_9 -> V_147 . V_111 ) ;
}
static int F_115 ( struct V_8 * V_9 )
{
struct V_148 * V_147 = & V_9 -> V_147 ;
struct V_149 * V_150 [ 2 ] = { & V_147 -> V_151 ,
& V_147 -> V_152 } ;
T_5 V_153 [ 2 ] ;
struct V_154 * V_154 ;
void * V_120 , * V_155 ;
unsigned int V_156 ;
int V_97 ;
if ( F_116 ( V_9 -> V_12 != V_157 || ! V_9 -> V_124 ) )
return - V_158 ;
switch ( F_4 ( V_9 -> V_4 ) ) {
case 9 :
V_153 [ 0 ] = F_104 ;
V_153 [ 1 ] = F_108 ;
break;
case 8 :
V_153 [ 0 ] = F_101 ;
V_153 [ 1 ] = F_103 ;
break;
default:
F_117 ( F_4 ( V_9 -> V_4 ) ) ;
return 0 ;
}
V_97 = F_109 ( V_9 ) ;
if ( V_97 ) {
F_118 ( L_1 , V_97 ) ;
return V_97 ;
}
V_154 = F_119 ( V_147 -> V_111 -> V_105 , 0 ) ;
V_120 = V_155 = F_120 ( V_154 ) ;
for ( V_156 = 0 ; V_156 < F_121 ( V_153 ) ; V_156 ++ ) {
V_150 [ V_156 ] -> V_159 = V_155 - V_120 ;
if ( F_116 ( ! F_122 ( V_150 [ V_156 ] -> V_159 , V_134 ) ) ) {
V_97 = - V_158 ;
break;
}
V_155 = V_153 [ V_156 ] ( V_9 , V_155 ) ;
V_150 [ V_156 ] -> V_160 = V_155 - ( V_120 + V_150 [ V_156 ] -> V_159 ) ;
}
F_123 ( V_155 - V_120 > V_145 ) ;
F_124 ( V_120 ) ;
if ( V_97 )
F_113 ( V_9 ) ;
return V_97 ;
}
static T_3 F_125 ( struct V_38 * V_39 )
{
return V_39 -> V_43 ? V_39 -> V_43 -> V_161 : 0 ;
}
static int F_126 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
int V_97 ;
V_97 = F_127 ( V_9 ) ;
if ( V_97 )
return V_97 ;
F_128 ( V_9 ) ;
F_129 ( V_9 ) ;
F_130 ( F_131 ( V_9 -> V_162 ) , 0xffffffff ) ;
F_130 ( F_132 ( V_9 ) ,
F_133 ( V_163 ) ) ;
F_130 ( F_134 ( V_9 -> V_162 ) ,
V_9 -> V_164 . V_165 ) ;
F_135 ( F_134 ( V_9 -> V_162 ) ) ;
F_118 ( L_2 , V_9 -> V_166 ) ;
F_136 ( V_64 , & V_9 -> V_65 ) ;
if ( ! V_4 . V_116 && ! F_40 ( V_9 ) ) {
F_118 ( L_3 ,
V_9 -> V_166 ,
F_125 ( & V_9 -> V_38 [ 0 ] ) ,
F_125 ( & V_9 -> V_38 [ 1 ] ) ) ;
V_9 -> V_38 [ 0 ] . V_42 = 0 ;
V_9 -> V_38 [ 1 ] . V_42 = 0 ;
F_18 ( V_9 ) ;
}
return 0 ;
}
static int F_137 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
int V_97 ;
V_97 = F_126 ( V_9 ) ;
if ( V_97 )
return V_97 ;
F_130 ( V_167 , F_133 ( V_168 ) ) ;
F_130 ( V_169 , F_133 ( V_170 ) ) ;
return F_138 ( V_9 ) ;
}
static int F_139 ( struct V_8 * V_9 )
{
int V_97 ;
V_97 = F_126 ( V_9 ) ;
if ( V_97 )
return V_97 ;
return F_138 ( V_9 ) ;
}
static void F_140 ( struct V_8 * V_9 ,
struct V_23 * V_43 )
{
struct V_38 * V_39 = V_9 -> V_38 ;
struct V_10 * V_11 ;
if ( ! V_43 || V_43 -> V_171 . error != - V_172 )
return;
V_11 = & V_43 -> V_7 -> V_9 [ V_9 -> V_12 ] ;
F_141 ( V_11 -> V_33 ,
V_43 -> V_7 , V_9 , V_11 -> V_35 ) ;
V_11 -> V_33 [ V_110 + 1 ] =
F_8 ( V_11 -> V_35 -> V_111 ) ;
V_11 -> V_33 [ V_173 + 1 ] = V_43 -> V_174 ;
V_43 -> V_35 -> V_68 = V_43 -> V_174 ;
F_142 ( V_43 -> V_35 ) ;
if ( V_43 -> V_7 != V_39 [ 0 ] . V_43 -> V_7 ) {
F_54 ( V_39 [ 0 ] . V_43 ) ;
V_39 [ 0 ] = V_39 [ 1 ] ;
memset ( & V_39 [ 1 ] , 0 , sizeof( V_39 [ 1 ] ) ) ;
}
F_21 ( V_43 -> V_7 != V_39 [ 0 ] . V_43 -> V_7 ) ;
V_43 -> V_36 =
F_143 ( V_43 -> V_35 ,
V_43 -> V_52 - V_175 * sizeof( T_3 ) ) ;
F_144 ( V_43 -> V_35 , V_43 -> V_36 ) ;
}
static int F_145 ( struct V_23 * V_176 )
{
struct V_28 * V_29 = V_176 -> V_7 -> V_29 ;
struct V_8 * V_9 = V_176 -> V_9 ;
const int V_177 = V_178 * 2 ;
T_3 * V_113 ;
int V_156 ;
V_113 = F_96 ( V_176 , V_177 * 2 + 2 ) ;
if ( F_84 ( V_113 ) )
return F_85 ( V_113 ) ;
* V_113 ++ = F_99 ( V_177 ) ;
for ( V_156 = V_178 - 1 ; V_156 >= 0 ; V_156 -- ) {
const T_6 V_179 = F_146 ( V_29 , V_156 ) ;
* V_113 ++ = F_19 ( F_147 ( V_9 , V_156 ) ) ;
* V_113 ++ = F_23 ( V_179 ) ;
* V_113 ++ = F_19 ( F_148 ( V_9 , V_156 ) ) ;
* V_113 ++ = F_25 ( V_179 ) ;
}
* V_113 ++ = V_135 ;
F_149 ( V_176 , V_113 ) ;
return 0 ;
}
static int F_150 ( struct V_23 * V_176 ,
T_1 V_159 , T_3 V_180 ,
const unsigned int V_84 )
{
T_3 * V_113 ;
int V_97 ;
if ( V_176 -> V_7 -> V_29 &&
( F_151 ( V_176 -> V_9 ) & V_176 -> V_7 -> V_29 -> V_181 ) &&
! F_17 ( & V_176 -> V_7 -> V_29 -> V_37 ) &&
! F_3 ( V_176 -> V_4 ) ) {
V_97 = F_145 ( V_176 ) ;
if ( V_97 )
return V_97 ;
V_176 -> V_7 -> V_29 -> V_181 &= ~ F_151 ( V_176 -> V_9 ) ;
}
V_113 = F_96 ( V_176 , 4 ) ;
if ( F_84 ( V_113 ) )
return F_85 ( V_113 ) ;
* V_113 ++ = V_182 |
( V_84 & V_183 ? 0 : F_152 ( 8 ) ) |
( V_84 & V_184 ? V_185 : 0 ) ;
* V_113 ++ = F_25 ( V_159 ) ;
* V_113 ++ = F_23 ( V_159 ) ;
* V_113 ++ = V_135 ;
F_149 ( V_176 , V_113 ) ;
return 0 ;
}
static void F_153 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
F_154 ( V_9 ,
~ ( V_9 -> V_186 | V_9 -> V_187 ) ) ;
F_155 ( F_156 ( V_9 -> V_162 ) ) ;
}
static void F_157 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
F_154 ( V_9 , ~ V_9 -> V_187 ) ;
}
static int F_158 ( struct V_23 * V_43 , T_3 V_188 )
{
T_3 V_189 , * V_113 ;
V_113 = F_96 ( V_43 , 4 ) ;
if ( F_84 ( V_113 ) )
return F_85 ( V_113 ) ;
V_189 = V_190 + 1 ;
V_189 |= V_191 | V_192 ;
if ( V_188 & V_193 ) {
V_189 |= V_194 ;
if ( V_43 -> V_9 -> V_12 == V_195 )
V_189 |= V_196 ;
}
* V_113 ++ = V_189 ;
* V_113 ++ = V_197 | V_198 ;
* V_113 ++ = 0 ;
* V_113 ++ = 0 ;
F_149 ( V_43 , V_113 ) ;
return 0 ;
}
static int F_159 ( struct V_23 * V_43 ,
T_3 V_188 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
T_3 V_199 =
F_8 ( V_9 -> V_124 ) + 2 * V_134 ;
bool V_200 = false , V_201 = false ;
T_3 * V_113 , V_84 = 0 ;
int V_180 ;
V_84 |= V_126 ;
if ( V_188 & V_202 ) {
V_84 |= V_203 ;
V_84 |= V_204 ;
V_84 |= V_127 ;
V_84 |= V_205 ;
}
if ( V_188 & V_193 ) {
V_84 |= V_206 ;
V_84 |= V_207 ;
V_84 |= V_208 ;
V_84 |= V_209 ;
V_84 |= V_210 ;
V_84 |= V_211 ;
V_84 |= V_133 ;
V_84 |= V_132 ;
if ( F_160 ( V_43 -> V_4 ) )
V_200 = true ;
if ( F_106 ( V_43 -> V_4 , 0 , V_212 ) )
V_201 = true ;
}
V_180 = 6 ;
if ( V_200 )
V_180 += 6 ;
if ( V_201 )
V_180 += 12 ;
V_113 = F_96 ( V_43 , V_180 ) ;
if ( F_84 ( V_113 ) )
return F_85 ( V_113 ) ;
if ( V_200 )
V_113 = F_100 ( V_113 , 0 , 0 ) ;
if ( V_201 )
V_113 = F_100 ( V_113 , V_127 ,
0 ) ;
V_113 = F_100 ( V_113 , V_84 , V_199 ) ;
if ( V_201 )
V_113 = F_100 ( V_113 , V_126 , 0 ) ;
F_149 ( V_43 , V_113 ) ;
return 0 ;
}
static void F_161 ( struct V_23 * V_43 , T_3 * V_113 )
{
* V_113 ++ = V_135 ;
* V_113 ++ = V_135 ;
V_43 -> V_52 = F_162 ( V_43 , V_113 ) ;
}
static void F_163 ( struct V_23 * V_43 , T_3 * V_113 )
{
F_7 ( V_213 & ( 1 << 5 ) ) ;
* V_113 ++ = ( V_190 + 1 ) | V_192 ;
* V_113 ++ = F_164 ( V_43 -> V_9 ) | V_198 ;
* V_113 ++ = 0 ;
* V_113 ++ = V_43 -> V_161 ;
* V_113 ++ = V_214 ;
* V_113 ++ = V_135 ;
V_43 -> V_36 = F_162 ( V_43 , V_113 ) ;
F_144 ( V_43 -> V_35 , V_43 -> V_36 ) ;
F_161 ( V_43 , V_113 ) ;
}
static void F_165 ( struct V_23 * V_43 ,
T_3 * V_113 )
{
F_7 ( V_215 & 1 ) ;
* V_113 ++ = F_166 ( 6 ) ;
* V_113 ++ = V_132 | V_126 |
V_133 ;
* V_113 ++ = F_164 ( V_43 -> V_9 ) ;
* V_113 ++ = 0 ;
* V_113 ++ = V_43 -> V_161 ;
* V_113 ++ = 0 ;
* V_113 ++ = V_214 ;
* V_113 ++ = V_135 ;
V_43 -> V_36 = F_162 ( V_43 , V_113 ) ;
F_144 ( V_43 -> V_35 , V_43 -> V_36 ) ;
F_161 ( V_43 , V_113 ) ;
}
static int F_167 ( struct V_23 * V_176 )
{
int V_97 ;
V_97 = F_168 ( V_176 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_169 ( V_176 ) ;
if ( V_97 )
F_170 ( L_4 ) ;
return F_171 ( V_176 ) ;
}
void F_172 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
if ( F_116 ( F_44 ( V_216 , & V_9 -> V_85 . V_17 ) ) )
F_173 ( & V_9 -> V_85 ) ;
V_2 = V_9 -> V_4 ;
if ( V_9 -> V_217 ) {
F_116 ( ( F_174 ( V_9 ) & V_218 ) == 0 ) ;
}
if ( V_9 -> V_219 )
V_9 -> V_219 ( V_9 ) ;
if ( V_9 -> V_164 . V_111 ) {
F_88 ( V_9 -> V_164 . V_111 -> V_105 ) ;
V_9 -> V_164 . V_111 = NULL ;
}
F_175 ( V_9 ) ;
F_113 ( V_9 ) ;
V_9 -> V_4 = NULL ;
V_2 -> V_9 [ V_9 -> V_12 ] = NULL ;
F_176 ( V_9 ) ;
}
static void F_177 ( struct V_8 * V_9 )
{
V_9 -> V_220 = F_60 ;
V_9 -> V_221 = F_68 ;
V_9 -> V_85 . V_222 = F_42 ;
}
static void
F_178 ( struct V_8 * V_9 )
{
V_9 -> V_223 = F_126 ;
V_9 -> V_224 = F_140 ;
V_9 -> V_225 = F_80 ;
V_9 -> V_226 = F_90 ;
V_9 -> V_227 = F_94 ;
V_9 -> V_228 = F_158 ;
V_9 -> V_229 = F_163 ;
V_9 -> V_230 = V_231 ;
V_9 -> V_232 = F_177 ;
V_9 -> V_233 = F_153 ;
V_9 -> V_234 = F_157 ;
V_9 -> V_235 = F_150 ;
}
static inline void
F_179 ( struct V_8 * V_9 )
{
unsigned V_236 = V_9 -> V_237 ;
V_9 -> V_186 = V_238 << V_236 ;
V_9 -> V_187 = V_239 << V_236 ;
}
static int
F_180 ( struct V_8 * V_9 , struct V_144 * V_111 )
{
const int V_240 = V_18 * V_19 ;
void * V_241 ;
V_241 = F_83 ( V_111 -> V_105 , V_106 ) ;
if ( F_84 ( V_241 ) )
return F_85 ( V_241 ) ;
V_9 -> V_164 . V_242 = V_241 + V_240 ;
V_9 -> V_164 . V_165 = F_8 ( V_111 ) + V_240 ;
V_9 -> V_164 . V_111 = V_111 ;
return 0 ;
}
static void
F_181 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
enum V_243 V_63 ;
F_182 ( V_9 ) ;
V_9 -> V_217 = NULL ;
V_63 = F_183 ( V_2 ,
F_20 ( V_9 ) ,
V_244 ) ;
V_63 |= F_183 ( V_2 ,
F_45 ( V_9 ) ,
V_245 | V_244 ) ;
V_63 |= F_183 ( V_2 ,
F_184 ( V_9 ) ,
V_245 ) ;
V_9 -> V_63 = V_63 ;
F_185 ( & V_9 -> V_85 ,
F_42 , ( unsigned long ) V_9 ) ;
F_178 ( V_9 ) ;
F_179 ( V_9 ) ;
}
static int
F_186 ( struct V_8 * V_9 )
{
struct V_6 * V_246 = V_9 -> V_4 -> V_247 ;
int V_97 ;
V_97 = F_187 ( V_9 ) ;
if ( V_97 )
goto error;
V_97 = F_180 ( V_9 , V_246 -> V_9 [ V_9 -> V_12 ] . V_17 ) ;
if ( V_97 ) {
F_170 ( L_5 , V_9 -> V_166 , V_97 ) ;
goto error;
}
return 0 ;
error:
F_172 ( V_9 ) ;
return V_97 ;
}
int F_188 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
int V_97 ;
F_181 ( V_9 ) ;
if ( F_189 ( V_2 ) )
V_9 -> V_187 |= V_248 ;
if ( F_4 ( V_2 ) >= 9 )
V_9 -> V_223 = F_139 ;
else
V_9 -> V_223 = F_137 ;
V_9 -> V_119 = F_167 ;
V_9 -> V_228 = F_159 ;
V_9 -> V_229 = F_165 ;
V_9 -> V_230 = V_249 ;
V_97 = F_190 ( V_9 , V_19 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_115 ( V_9 ) ;
if ( V_97 ) {
F_170 ( L_6 ,
V_97 ) ;
}
return F_186 ( V_9 ) ;
}
int F_191 ( struct V_8 * V_9 )
{
F_181 ( V_9 ) ;
return F_186 ( V_9 ) ;
}
static T_3
F_192 ( struct V_1 * V_2 )
{
T_3 V_250 = 0 ;
if ( F_4 ( V_2 ) < 9 )
return 0 ;
if ( F_193 ( V_2 ) -> V_251 . V_252 ) {
V_250 |= V_253 ;
V_250 |= F_194 ( F_193 ( V_2 ) -> V_251 . V_254 ) <<
V_255 ;
V_250 |= V_256 ;
}
if ( F_193 ( V_2 ) -> V_251 . V_257 ) {
V_250 |= V_258 ;
V_250 |= F_194 ( F_193 ( V_2 ) -> V_251 . V_259 ) <<
V_260 ;
V_250 |= V_256 ;
}
if ( F_193 ( V_2 ) -> V_251 . V_261 ) {
V_250 |= F_193 ( V_2 ) -> V_251 . V_262 <<
V_263 ;
V_250 |= F_193 ( V_2 ) -> V_251 . V_262 <<
V_264 ;
V_250 |= V_256 ;
}
return V_250 ;
}
static T_3 F_195 ( struct V_8 * V_9 )
{
T_3 V_265 ;
switch ( F_4 ( V_9 -> V_4 ) ) {
default:
F_117 ( F_4 ( V_9 -> V_4 ) ) ;
case 9 :
V_265 =
V_266 ;
break;
case 8 :
V_265 =
V_267 ;
break;
}
return V_265 ;
}
static void F_141 ( T_3 * V_41 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_268 * V_35 )
{
struct V_1 * V_2 = V_9 -> V_4 ;
struct V_28 * V_29 = V_7 -> V_29 ? : V_2 -> V_31 . V_32 ;
T_3 V_37 = V_9 -> V_162 ;
bool V_269 = V_9 -> V_12 == V_157 ;
V_41 [ V_270 ] = F_99 ( V_269 ? 14 : 11 ) |
V_271 ;
F_196 ( V_41 , V_272 , F_197 ( V_9 ) ,
F_133 ( V_273 |
V_274 |
( F_198 ( V_2 ) ?
V_275 : 0 ) ) ) ;
F_196 ( V_41 , V_173 , F_199 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_34 , F_200 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_110 , F_201 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_276 , F_202 ( V_37 ) ,
F_203 ( V_35 -> V_160 ) | V_277 ) ;
F_196 ( V_41 , V_278 , F_204 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_279 , F_205 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_280 , F_206 ( V_37 ) , V_281 ) ;
F_196 ( V_41 , V_282 , F_207 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_283 , F_208 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_284 , F_209 ( V_37 ) , 0 ) ;
if ( V_269 ) {
F_196 ( V_41 , V_285 , F_210 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_286 , F_211 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_287 ,
F_212 ( V_37 ) , 0 ) ;
if ( V_9 -> V_147 . V_111 ) {
struct V_148 * V_147 = & V_9 -> V_147 ;
T_3 V_165 = F_8 ( V_147 -> V_111 ) ;
V_41 [ V_286 + 1 ] =
( V_165 + V_147 -> V_151 . V_159 ) |
( V_147 -> V_151 . V_160 / V_134 ) ;
V_41 [ V_287 + 1 ] =
F_195 ( V_9 ) << 6 ;
V_41 [ V_285 + 1 ] =
( V_165 + V_147 -> V_152 . V_159 ) | 0x01 ;
}
}
V_41 [ V_288 ] = F_99 ( 9 ) | V_271 ;
F_196 ( V_41 , V_289 , F_213 ( V_37 ) , 0 ) ;
F_196 ( V_41 , V_290 , F_147 ( V_9 , 3 ) , 0 ) ;
F_196 ( V_41 , V_291 , F_148 ( V_9 , 3 ) , 0 ) ;
F_196 ( V_41 , V_292 , F_147 ( V_9 , 2 ) , 0 ) ;
F_196 ( V_41 , V_293 , F_148 ( V_9 , 2 ) , 0 ) ;
F_196 ( V_41 , V_294 , F_147 ( V_9 , 1 ) , 0 ) ;
F_196 ( V_41 , V_295 , F_148 ( V_9 , 1 ) , 0 ) ;
F_196 ( V_41 , V_296 , F_147 ( V_9 , 0 ) , 0 ) ;
F_196 ( V_41 , V_297 , F_148 ( V_9 , 0 ) , 0 ) ;
if ( V_29 && F_17 ( & V_29 -> V_37 ) ) {
F_214 ( V_29 , V_41 ) ;
}
if ( V_269 ) {
V_41 [ V_298 ] = F_99 ( 1 ) ;
F_196 ( V_41 , V_299 , V_300 ,
F_192 ( V_2 ) ) ;
}
}
static int
F_215 ( struct V_6 * V_7 ,
struct V_143 * V_301 ,
struct V_8 * V_9 ,
struct V_268 * V_35 )
{
void * V_96 ;
int V_97 ;
V_97 = F_216 ( V_301 , true ) ;
if ( V_97 ) {
F_118 ( L_7 ) ;
return V_97 ;
}
V_96 = F_83 ( V_301 , V_106 ) ;
if ( F_84 ( V_96 ) ) {
V_97 = F_85 ( V_96 ) ;
F_118 ( L_8 , V_97 ) ;
return V_97 ;
}
V_301 -> V_31 . V_112 = true ;
F_141 ( V_96 + V_109 * V_19 ,
V_7 , V_9 , V_35 ) ;
F_88 ( V_301 ) ;
return 0 ;
}
T_7 F_217 ( struct V_8 * V_9 )
{
int V_97 = 0 ;
F_116 ( F_4 ( V_9 -> V_4 ) < 8 ) ;
switch ( V_9 -> V_12 ) {
case V_157 :
if ( F_4 ( V_9 -> V_4 ) >= 9 )
V_97 = V_302 ;
else
V_97 = V_303 ;
break;
case V_195 :
case V_304 :
case V_305 :
case V_306 :
V_97 = V_307 ;
break;
}
return V_97 ;
}
static int F_81 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_143 * V_301 ;
struct V_10 * V_11 = & V_7 -> V_9 [ V_9 -> V_12 ] ;
struct V_144 * V_111 ;
T_7 V_308 ;
struct V_268 * V_35 ;
int V_97 ;
F_116 ( V_11 -> V_17 ) ;
V_308 = F_218 ( F_217 ( V_9 ) ,
V_309 ) ;
V_308 += V_19 * V_18 ;
V_301 = F_110 ( V_7 -> V_4 , V_308 ) ;
if ( F_84 ( V_301 ) ) {
F_118 ( L_9 ) ;
return F_85 ( V_301 ) ;
}
V_111 = F_111 ( V_301 , & V_7 -> V_4 -> V_146 . V_37 , NULL ) ;
if ( F_84 ( V_111 ) ) {
V_97 = F_85 ( V_111 ) ;
goto V_310;
}
V_35 = F_219 ( V_9 , V_7 -> V_311 ) ;
if ( F_84 ( V_35 ) ) {
V_97 = F_85 ( V_35 ) ;
goto V_310;
}
V_97 = F_215 ( V_7 , V_301 , V_9 , V_35 ) ;
if ( V_97 ) {
F_118 ( L_10 , V_97 ) ;
goto V_312;
}
V_11 -> V_35 = V_35 ;
V_11 -> V_17 = V_111 ;
V_11 -> V_118 |= V_9 -> V_119 == NULL ;
return 0 ;
V_312:
F_220 ( V_35 ) ;
V_310:
F_112 ( V_301 ) ;
return V_97 ;
}
void F_221 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
enum V_313 V_12 ;
F_74 (ctx, &dev_priv->context_list, link) {
F_222 (engine, dev_priv, id) {
struct V_10 * V_11 = & V_7 -> V_9 [ V_9 -> V_12 ] ;
T_3 * V_314 ;
if ( ! V_11 -> V_17 )
continue;
V_314 = F_83 ( V_11 -> V_17 -> V_105 ,
V_106 ) ;
if ( F_116 ( F_84 ( V_314 ) ) )
continue;
V_314 += V_109 * V_19 / sizeof( * V_314 ) ;
V_314 [ V_173 + 1 ] = 0 ;
V_314 [ V_34 + 1 ] = 0 ;
V_11 -> V_17 -> V_105 -> V_31 . V_112 = true ;
F_88 ( V_11 -> V_17 -> V_105 ) ;
F_223 ( V_11 -> V_35 , 0 ) ;
}
}
}
