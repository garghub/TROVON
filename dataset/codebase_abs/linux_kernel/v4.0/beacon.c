static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = false ;
V_2 -> V_3 . V_5 = false ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 V_12 , V_13 ;
struct V_14 * V_15 ;
F_4 ( V_7 , V_2 -> V_3 . V_16 , & V_12 ) ;
if ( V_2 -> V_8 -> V_17 == V_18 ||
V_2 -> V_8 -> V_17 == V_19 ) {
V_12 . V_20 = 1 ;
V_12 . V_21 = 0 ;
V_12 . V_22 = 0 ;
} else {
V_15 = V_2 -> V_23 . V_24 [ V_25 ] ;
F_4 ( V_7 , V_15 -> V_26 , & V_13 ) ;
V_12 . V_20 = V_13 . V_20 ;
if ( V_7 -> V_27 == V_28 )
V_12 . V_21 = 2 * V_13 . V_21 ;
else
V_12 . V_21 = 4 * V_13 . V_21 ;
V_12 . V_22 = V_13 . V_22 ;
}
if ( ! F_5 ( V_7 , V_2 -> V_3 . V_16 , & V_12 ) ) {
F_6 ( V_10 , L_1 ) ;
} else {
F_7 ( V_7 , V_2 -> V_3 . V_16 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 , int V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_37 V_38 ;
struct V_39 * V_40 ;
T_1 V_41 = V_7 -> V_42 ;
T_1 V_43 , V_44 = 0 ;
V_40 = & V_10 -> V_45 [ V_2 -> V_46 . V_47 -> V_48 ] ;
V_44 = V_40 -> V_49 [ V_33 ] . V_50 ;
if ( V_30 -> V_51 . V_52 )
V_44 |= V_40 -> V_49 [ V_33 ] . V_53 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_54 = V_35 -> V_55 + V_56 ;
V_38 . type = V_57 ;
for ( V_43 = 0 ; V_43 < 4 ; V_43 ++ )
V_38 . V_58 [ V_43 ] = V_59 ;
V_38 . V_60 = V_61 ;
V_38 . V_62 = V_63 ;
V_38 . V_64 = V_65 | V_66 ;
V_38 . V_67 [ 0 ] = V_32 -> V_68 ;
V_38 . V_69 [ 0 ] = F_9 ( V_35 -> V_55 , 4 ) ;
V_38 . V_70 = true ;
V_38 . V_71 = true ;
V_38 . V_72 = V_2 -> V_3 . V_16 ;
V_38 . V_73 [ 0 ] . V_74 = 1 ;
V_38 . V_73 [ 0 ] . V_75 = V_44 ;
V_38 . V_73 [ 0 ] . V_76 = F_10 ( V_2 , V_41 , V_44 ) ;
F_11 ( V_7 , V_32 -> V_77 , & V_38 ) ;
}
static struct V_31 * F_12 ( struct V_78 * V_79 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = V_79 -> V_80 ;
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_31 * V_32 ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
struct V_34 * V_35 ;
struct V_14 * V_84 = V_2 -> V_3 . V_84 ;
struct V_85 * V_38 ;
struct V_86 * V_87 ;
int V_88 ;
if ( V_82 -> V_89 == NULL )
return NULL ;
V_32 = V_82 -> V_89 ;
V_35 = V_32 -> V_36 ;
if ( V_35 ) {
F_13 ( V_2 -> V_90 , V_32 -> V_68 ,
V_35 -> V_55 , V_91 ) ;
F_14 ( V_35 ) ;
V_32 -> V_68 = 0 ;
V_32 -> V_36 = NULL ;
}
V_35 = F_15 ( V_79 , V_30 ) ;
if ( V_35 == NULL )
return NULL ;
V_32 -> V_36 = V_35 ;
V_87 = (struct V_86 * ) V_35 -> V_92 ;
V_87 -> V_93 . V_3 . V_94 = V_82 -> V_95 ;
V_38 = F_16 ( V_35 ) ;
F_17 ( V_10 , V_35 ) ;
if ( V_30 -> V_96 )
F_18 ( V_2 , V_82 , V_35 ) ;
V_32 -> V_68 = F_19 ( V_2 -> V_90 , V_35 -> V_92 ,
V_35 -> V_55 , V_91 ) ;
if ( F_20 ( F_21 ( V_2 -> V_90 , V_32 -> V_68 ) ) ) {
F_14 ( V_35 ) ;
V_32 -> V_36 = NULL ;
V_32 -> V_68 = 0 ;
F_6 ( V_10 , L_2 ) ;
return NULL ;
}
V_35 = F_22 ( V_79 , V_30 ) ;
F_23 ( & V_84 -> V_97 ) ;
V_88 = V_84 -> V_98 ;
F_24 ( & V_84 -> V_97 ) ;
if ( V_35 && V_88 ) {
if ( V_2 -> V_99 -> V_100 > 1 ) {
F_25 ( V_10 , V_101 ,
L_3 ) ;
F_26 ( V_2 , V_84 ) ;
}
}
F_8 ( V_2 , V_30 , V_32 , V_38 -> V_102 . V_73 [ 0 ] . V_103 ) ;
if ( V_35 )
F_27 ( V_79 , V_30 , V_35 ) ;
return V_32 ;
}
void F_28 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
int V_104 ;
V_82 -> V_89 = F_29 ( & V_2 -> V_3 . V_105 , struct V_31 , V_106 ) ;
F_30 ( & V_82 -> V_89 -> V_106 ) ;
for ( V_104 = 0 ; V_104 < V_107 ; V_104 ++ ) {
if ( V_2 -> V_3 . V_108 [ V_104 ] == NULL ) {
V_82 -> V_109 = V_104 ;
break;
}
}
V_2 -> V_3 . V_108 [ V_82 -> V_109 ] = V_30 ;
V_2 -> V_110 ++ ;
F_25 ( V_10 , V_111 , L_4 ,
V_82 -> V_109 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
struct V_31 * V_32 = V_82 -> V_89 ;
struct V_112 * V_113 = & V_2 -> V_99 -> V_3 ;
F_25 ( V_10 , V_111 , L_5 ,
V_82 -> V_109 ) ;
F_32 ( & V_2 -> V_114 ) ;
V_113 -> V_115 &= ~ F_33 ( V_82 -> V_109 ) ;
if ( V_32 && V_32 -> V_36 ) {
struct V_34 * V_35 = V_32 -> V_36 ;
F_13 ( V_2 -> V_90 , V_32 -> V_68 ,
V_35 -> V_55 , V_91 ) ;
F_14 ( V_35 ) ;
V_32 -> V_36 = NULL ;
V_32 -> V_68 = 0 ;
}
V_82 -> V_89 = NULL ;
V_2 -> V_3 . V_108 [ V_82 -> V_109 ] = NULL ;
V_2 -> V_110 -- ;
F_34 ( & V_32 -> V_106 , & V_2 -> V_3 . V_105 ) ;
F_35 ( & V_2 -> V_114 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_2 -> V_99 -> V_3 ;
T_2 V_116 ;
T_3 V_117 ;
T_4 V_118 ;
int V_104 ;
if ( V_2 -> V_8 -> V_17 != V_18 &&
V_2 -> V_8 -> V_17 != V_19 ) {
F_25 ( V_10 , V_101 , L_6 ,
F_37 ( V_2 -> V_8 ) ) ;
return 0 ;
}
V_116 = V_113 -> V_119 ? : V_120 ;
V_118 = F_37 ( V_2 -> V_8 ) ;
V_118 += F_38 ( V_2 -> V_8 -> V_121 . V_122 ) ;
V_117 = F_39 ( ( V_118 * V_107 ) >> 32 , V_118 * V_107 ) ;
V_104 = ( V_117 % ( V_116 * V_107 ) ) / V_116 ;
F_25 ( V_10 , V_101 , L_7 ,
V_104 , V_118 , V_117 / V_107 ) ;
return V_104 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
struct V_112 * V_113 = & V_82 -> V_123 -> V_3 ;
T_3 V_124 ;
if ( V_82 -> V_109 == 0 )
return;
V_124 = V_113 -> V_119 * V_82 -> V_109 ;
V_124 = F_38 ( V_124 ) / V_107 ;
V_82 -> V_95 = F_41 ( V_124 ) ;
F_25 ( V_10 , V_111 , L_8 ,
( unsigned long long ) V_124 , V_82 -> V_109 ) ;
}
bool F_42 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
if ( ! V_30 || ! V_30 -> V_125 )
return false ;
if ( ! F_43 ( V_30 ) )
return false ;
F_44 ( V_30 ) ;
return true ;
}
static void F_45 ( void * V_92 , T_1 * V_126 , struct V_29 * V_30 )
{
struct V_1 * V_2 = V_92 ;
F_42 ( V_2 , V_30 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_79 ,
V_127 ,
F_45 , V_2 ) ;
}
void F_48 ( unsigned long V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_92 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_31 * V_32 = NULL ;
struct V_29 * V_30 ;
bool V_128 = ! ! ( V_7 -> V_129 . V_130 & V_131 ) ;
int V_104 ;
if ( F_49 ( V_132 , & V_10 -> V_133 ) ) {
F_25 ( V_10 , V_134 ,
L_9 ) ;
return;
}
if ( F_50 ( V_7 , V_2 -> V_3 . V_16 ) != 0 ) {
V_2 -> V_3 . V_135 ++ ;
F_51 ( V_7 ) ;
if ( ! F_52 ( V_2 ) )
return;
if ( V_2 -> V_3 . V_135 < V_136 * V_2 -> V_110 ) {
F_25 ( V_10 , V_137 ,
L_10 ,
V_2 -> V_3 . V_135 ) ;
F_53 ( V_7 , V_2 -> V_3 . V_16 ) ;
if ( V_2 -> V_3 . V_135 > 3 )
F_54 ( V_7 ) ;
} else if ( V_2 -> V_3 . V_135 >= V_136 ) {
F_25 ( V_10 , V_137 , L_11 ) ;
V_2 -> V_3 . V_135 = 0 ;
F_55 ( V_2 , V_138 ) ;
}
return;
}
V_104 = F_36 ( V_2 ) ;
V_30 = V_2 -> V_3 . V_108 [ V_104 ] ;
if ( ! V_128 ) {
if ( F_56 () ) {
F_57 ( V_2 ,
V_139 ) ;
}
if ( F_42 ( V_2 , V_30 ) )
return;
}
if ( ! V_30 || ! V_30 -> V_51 . V_115 )
return;
if ( F_56 () ) {
F_58 ( V_2 , V_30 , V_140 ) ;
}
V_32 = F_12 ( V_2 -> V_79 , V_30 ) ;
if ( V_2 -> V_3 . V_135 != 0 ) {
F_25 ( V_10 , V_137 , L_12 ,
V_2 -> V_3 . V_135 ) ;
V_2 -> V_3 . V_135 = 0 ;
}
if ( V_2 -> V_3 . V_141 == V_142 ) {
V_2 -> V_3 . V_141 = V_143 ;
V_2 -> V_3 . V_144 = V_104 ;
} else if ( V_2 -> V_3 . V_141 == V_143 &&
V_2 -> V_3 . V_144 == V_104 ) {
V_7 -> V_27 = V_2 -> V_3 . V_27 ;
F_59 ( V_7 ) ;
V_2 -> V_3 . V_141 = V_145 ;
}
if ( V_32 ) {
F_1 ( V_2 ) ;
F_25 ( V_10 , V_101 ,
L_13 , V_104 ) ;
F_60 ( V_7 , V_2 -> V_3 . V_16 , V_32 -> V_146 ) ;
if ( ! V_128 )
F_61 ( V_7 , V_2 -> V_3 . V_16 ) ;
}
}
static void F_62 ( struct V_1 * V_2 , T_3 V_147 ,
T_3 V_116 , bool V_148 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_63 ( V_7 ) ;
if ( V_148 )
F_64 ( V_7 ) ;
F_2 ( V_2 ) ;
F_65 ( V_7 , V_147 , V_116 ) ;
V_2 -> V_3 . V_135 = 0 ;
F_66 ( V_7 ) ;
F_67 ( V_7 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_112 * V_149 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_69 ( V_7 , V_149 , V_107 ) ;
F_62 ( V_2 , V_149 -> V_147 , V_149 -> V_116 , false ) ;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_112 * V_149 )
{
struct V_150 V_151 ;
if ( F_71 ( V_7 , V_149 , & V_151 ) == - V_152 )
return;
F_63 ( V_7 ) ;
F_72 ( V_7 , & V_151 ) ;
V_7 -> V_153 |= V_154 ;
F_66 ( V_7 ) ;
F_67 ( V_7 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_112 * V_149 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_1 ( V_2 ) ;
F_74 ( V_7 , V_149 ) ;
F_62 ( V_2 , V_149 -> V_147 , V_149 -> V_116 , V_149 -> V_155 ) ;
if ( ! V_149 -> V_155 && V_149 -> V_115 )
F_75 ( V_156 , & V_10 -> V_133 ) ;
}
static bool F_76 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
if ( F_56 () ) {
if ( V_2 -> V_99 != V_82 -> V_123 )
return true ;
}
if ( V_2 -> V_8 -> V_17 == V_18 ) {
if ( V_30 -> type != V_18 ) {
F_25 ( V_10 , V_111 ,
L_14 ) ;
return false ;
}
}
if ( V_2 -> V_8 -> V_17 == V_157 ) {
if ( ( V_30 -> type == V_157 ) &&
F_49 ( V_156 , & V_10 -> V_133 ) &&
V_30 != V_2 -> V_99 -> V_158 ) {
F_25 ( V_10 , V_111 ,
L_15 ) ;
return false ;
}
}
return true ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_159 * V_160 ,
struct V_161 * V_51 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_160 -> V_3 ;
F_25 ( V_10 , V_101 ,
L_16 , V_51 -> V_162 ) ;
V_113 -> V_119 = V_51 -> V_163 ;
V_113 -> V_164 = V_51 -> V_164 ;
V_113 -> V_165 = 1 ;
V_113 -> V_155 = V_51 -> V_155 ;
if ( V_113 -> V_119 == 0 )
V_113 -> V_119 = 100 ;
V_113 -> V_166 =
V_167 * V_113 -> V_119 ;
if ( V_113 -> V_164 == 0 )
V_113 -> V_164 = 1 ;
}
void F_78 ( struct V_1 * V_2 , struct V_29 * V_30 ,
T_3 V_168 )
{
struct V_161 * V_51 = & V_30 -> V_51 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_81 * V_82 = ( void * ) V_30 -> V_83 ;
struct V_159 * V_160 = V_82 -> V_123 ;
struct V_112 * V_113 ;
unsigned long V_64 ;
bool V_169 = false ;
if ( ! V_160 )
return;
V_113 = & V_82 -> V_123 -> V_3 ;
if ( V_30 -> type == V_18 )
F_40 ( V_2 , V_30 ) ;
if ( ! F_76 ( V_2 , V_30 ) )
return;
if ( V_30 -> type == V_157 ) {
F_77 ( V_2 , V_160 , V_51 ) ;
if ( V_160 != V_2 -> V_99 )
return;
F_79 ( V_2 ) ;
F_75 ( V_156 , & V_10 -> V_133 ) ;
return;
}
if ( V_168 & V_170 ) {
bool V_171 = V_113 -> V_115 ;
if ( ! V_51 -> V_115 ) {
V_113 -> V_115 &= ~ F_33 ( V_82 -> V_109 ) ;
} else {
V_113 -> V_115 |= F_33 ( V_82 -> V_109 ) ;
if ( ! V_171 )
F_77 ( V_2 , V_160 , V_51 ) ;
}
}
if ( V_160 != V_2 -> V_99 )
return;
if ( V_113 -> V_119 ) {
if ( ( V_168 & V_172 ) && ! V_51 -> V_155 &&
V_51 -> V_115 ) {
F_80 ( & V_2 -> V_173 , V_64 ) ;
V_2 -> V_174 |= V_175 | V_176 ;
F_81 ( & V_2 -> V_173 , V_64 ) ;
V_169 = true ;
} else {
F_79 ( V_2 ) ;
}
if ( V_113 -> V_115 && ! V_169 )
F_75 ( V_156 , & V_10 -> V_133 ) ;
else
F_82 ( V_156 , & V_10 -> V_133 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_2 -> V_99 -> V_3 ;
switch ( V_2 -> V_8 -> V_17 ) {
case V_18 :
case V_19 :
F_68 ( V_2 , V_113 ) ;
break;
case V_177 :
F_73 ( V_2 , V_113 ) ;
break;
case V_157 :
F_70 ( V_2 -> V_8 , V_113 ) ;
break;
default:
F_25 ( V_10 , V_111 , L_17 ) ;
return;
}
}
