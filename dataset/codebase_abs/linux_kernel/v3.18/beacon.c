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
T_1 V_43 = 0 ;
V_40 = & V_10 -> V_44 [ V_2 -> V_45 . V_46 -> V_47 ] ;
V_43 = V_40 -> V_48 [ V_33 ] . V_49 ;
if ( V_30 -> V_50 . V_51 )
V_43 |= V_40 -> V_48 [ V_33 ] . V_52 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_53 = V_35 -> V_54 + V_55 ;
V_38 . type = V_56 ;
V_38 . V_57 = V_58 ;
V_38 . V_59 = V_60 ;
V_38 . V_61 = V_62 ;
V_38 . V_63 = V_64 | V_65 ;
V_38 . V_66 [ 0 ] = V_32 -> V_67 ;
V_38 . V_68 [ 0 ] = F_9 ( V_35 -> V_54 , 4 ) ;
V_38 . V_69 = true ;
V_38 . V_70 = true ;
V_38 . V_71 = V_2 -> V_3 . V_16 ;
V_38 . V_72 [ 0 ] . V_73 = 1 ;
V_38 . V_72 [ 0 ] . V_74 = V_43 ;
V_38 . V_72 [ 0 ] . V_75 = F_10 ( V_2 , V_41 , V_43 ) ;
F_11 ( V_7 , V_32 -> V_76 , & V_38 ) ;
}
static struct V_31 * F_12 ( struct V_77 * V_78 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = V_78 -> V_79 ;
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_31 * V_32 ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
struct V_34 * V_35 ;
struct V_14 * V_83 = V_2 -> V_3 . V_83 ;
struct V_84 * V_38 ;
struct V_85 * V_86 ;
int V_87 ;
if ( V_81 -> V_88 == NULL )
return NULL ;
V_32 = V_81 -> V_88 ;
V_35 = V_32 -> V_36 ;
if ( V_35 ) {
F_13 ( V_2 -> V_89 , V_32 -> V_67 ,
V_35 -> V_54 , V_90 ) ;
F_14 ( V_35 ) ;
V_32 -> V_67 = 0 ;
V_32 -> V_36 = NULL ;
}
V_35 = F_15 ( V_78 , V_30 ) ;
if ( V_35 == NULL )
return NULL ;
V_32 -> V_36 = V_35 ;
V_86 = (struct V_85 * ) V_35 -> V_91 ;
V_86 -> V_92 . V_3 . V_93 = V_81 -> V_94 ;
V_38 = F_16 ( V_35 ) ;
F_17 ( V_10 , V_35 ) ;
if ( V_30 -> V_95 )
F_18 ( V_2 , V_81 , V_35 ) ;
V_32 -> V_67 = F_19 ( V_2 -> V_89 , V_35 -> V_91 ,
V_35 -> V_54 , V_90 ) ;
if ( F_20 ( F_21 ( V_2 -> V_89 , V_32 -> V_67 ) ) ) {
F_14 ( V_35 ) ;
V_32 -> V_36 = NULL ;
V_32 -> V_67 = 0 ;
F_6 ( V_10 , L_2 ) ;
return NULL ;
}
V_35 = F_22 ( V_78 , V_30 ) ;
F_23 ( & V_83 -> V_96 ) ;
V_87 = V_83 -> V_97 ;
F_24 ( & V_83 -> V_96 ) ;
if ( V_35 && V_87 ) {
if ( V_2 -> V_98 -> V_99 > 1 ) {
F_25 ( V_10 , V_100 ,
L_3 ) ;
F_26 ( V_2 , V_83 ) ;
}
}
F_8 ( V_2 , V_30 , V_32 , V_38 -> V_101 . V_72 [ 0 ] . V_102 ) ;
if ( V_35 )
F_27 ( V_78 , V_30 , V_35 ) ;
return V_32 ;
}
void F_28 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
int V_103 ;
V_81 -> V_88 = F_29 ( & V_2 -> V_3 . V_104 , struct V_31 , V_105 ) ;
F_30 ( & V_81 -> V_88 -> V_105 ) ;
for ( V_103 = 0 ; V_103 < V_106 ; V_103 ++ ) {
if ( V_2 -> V_3 . V_107 [ V_103 ] == NULL ) {
V_81 -> V_108 = V_103 ;
break;
}
}
V_2 -> V_3 . V_107 [ V_81 -> V_108 ] = V_30 ;
V_2 -> V_109 ++ ;
F_25 ( V_10 , V_110 , L_4 ,
V_81 -> V_108 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
struct V_31 * V_32 = V_81 -> V_88 ;
F_25 ( V_10 , V_110 , L_5 ,
V_81 -> V_108 ) ;
F_32 ( & V_2 -> V_111 ) ;
if ( V_32 && V_32 -> V_36 ) {
struct V_34 * V_35 = V_32 -> V_36 ;
F_13 ( V_2 -> V_89 , V_32 -> V_67 ,
V_35 -> V_54 , V_90 ) ;
F_14 ( V_35 ) ;
V_32 -> V_36 = NULL ;
V_32 -> V_67 = 0 ;
}
V_81 -> V_88 = NULL ;
V_2 -> V_3 . V_107 [ V_81 -> V_108 ] = NULL ;
V_2 -> V_109 -- ;
F_33 ( & V_32 -> V_105 , & V_2 -> V_3 . V_104 ) ;
F_34 ( & V_2 -> V_111 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_2 -> V_98 -> V_3 ;
T_2 V_114 ;
T_3 V_115 ;
T_4 V_116 ;
int V_103 ;
if ( V_2 -> V_8 -> V_17 != V_18 &&
V_2 -> V_8 -> V_17 != V_19 ) {
F_25 ( V_10 , V_100 , L_6 ,
F_36 ( V_2 -> V_8 ) ) ;
return 0 ;
}
V_114 = V_113 -> V_117 ? : V_118 ;
V_116 = F_36 ( V_2 -> V_8 ) ;
V_116 += F_37 ( V_2 -> V_8 -> V_119 . V_120 ) ;
V_115 = F_38 ( ( V_116 * V_106 ) >> 32 , V_116 * V_106 ) ;
V_103 = ( V_115 % ( V_114 * V_106 ) ) / V_114 ;
F_25 ( V_10 , V_100 , L_7 ,
V_103 , V_116 , V_115 / V_106 ) ;
return V_103 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
struct V_112 * V_113 = & V_81 -> V_121 -> V_3 ;
T_3 V_122 ;
if ( V_81 -> V_108 == 0 )
return;
V_122 = V_113 -> V_117 * V_81 -> V_108 ;
V_122 = F_37 ( V_122 ) / V_106 ;
V_81 -> V_94 = F_40 ( V_122 ) ;
F_25 ( V_10 , V_110 , L_8 ,
( unsigned long long ) V_122 , V_81 -> V_108 ) ;
}
bool F_41 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
if ( ! V_30 || ! V_30 -> V_123 )
return false ;
if ( ! F_42 ( V_30 ) )
return false ;
F_43 ( V_30 ) ;
return true ;
}
static void F_44 ( void * V_91 , T_1 * V_124 , struct V_29 * V_30 )
{
struct V_1 * V_2 = V_91 ;
F_41 ( V_2 , V_30 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 -> V_78 ,
V_125 ,
F_44 , V_2 ) ;
}
void F_47 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_31 * V_32 = NULL ;
struct V_29 * V_30 ;
bool V_126 = ! ! ( V_7 -> V_127 . V_128 & V_129 ) ;
int V_103 ;
if ( F_48 ( V_130 , & V_10 -> V_131 ) ) {
F_25 ( V_10 , V_132 ,
L_9 ) ;
return;
}
if ( F_49 ( V_7 , V_2 -> V_3 . V_16 ) != 0 ) {
V_2 -> V_3 . V_133 ++ ;
F_50 ( V_7 ) ;
if ( ! F_51 ( V_2 ) )
return;
if ( V_2 -> V_3 . V_133 < V_134 * V_2 -> V_109 ) {
F_25 ( V_10 , V_135 ,
L_10 ,
V_2 -> V_3 . V_133 ) ;
F_52 ( V_7 , V_2 -> V_3 . V_16 ) ;
if ( V_2 -> V_3 . V_133 > 3 )
F_53 ( V_7 ) ;
} else if ( V_2 -> V_3 . V_133 >= V_134 ) {
F_25 ( V_10 , V_135 , L_11 ) ;
V_2 -> V_3 . V_133 = 0 ;
F_54 ( V_2 , V_136 ) ;
}
return;
}
V_103 = F_35 ( V_2 ) ;
V_30 = V_2 -> V_3 . V_107 [ V_103 ] ;
if ( ! V_126 ) {
if ( F_55 () ) {
F_56 ( V_2 ,
V_137 ) ;
}
if ( F_41 ( V_2 , V_30 ) )
return;
}
if ( ! V_30 || ! V_30 -> V_50 . V_138 )
return;
if ( F_55 () ) {
F_57 ( V_2 , V_30 , V_139 ) ;
}
V_32 = F_12 ( V_2 -> V_78 , V_30 ) ;
if ( V_2 -> V_3 . V_133 != 0 ) {
F_25 ( V_10 , V_135 , L_12 ,
V_2 -> V_3 . V_133 ) ;
V_2 -> V_3 . V_133 = 0 ;
}
if ( V_2 -> V_3 . V_140 == V_141 ) {
V_2 -> V_3 . V_140 = V_142 ;
V_2 -> V_3 . V_143 = V_103 ;
} else if ( V_2 -> V_3 . V_140 == V_142 &&
V_2 -> V_3 . V_143 == V_103 ) {
V_7 -> V_27 = V_2 -> V_3 . V_27 ;
F_58 ( V_7 ) ;
V_2 -> V_3 . V_140 = V_144 ;
}
if ( V_32 ) {
F_1 ( V_2 ) ;
F_25 ( V_10 , V_100 ,
L_13 , V_103 ) ;
F_59 ( V_7 , V_2 -> V_3 . V_16 , V_32 -> V_145 ) ;
if ( ! V_126 )
F_60 ( V_7 , V_2 -> V_3 . V_16 ) ;
}
}
static void F_61 ( struct V_1 * V_2 , T_3 V_146 ,
T_3 V_114 , bool V_147 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_62 ( V_7 ) ;
if ( V_147 )
F_63 ( V_7 ) ;
F_2 ( V_2 ) ;
F_64 ( V_7 , V_146 , V_114 ) ;
V_2 -> V_3 . V_133 = 0 ;
F_65 ( V_7 ) ;
F_66 ( V_7 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_112 * V_148 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_68 ( V_7 , V_148 , V_106 ) ;
F_61 ( V_2 , V_148 -> V_146 , V_148 -> V_114 , false ) ;
}
static void F_69 ( struct V_6 * V_7 ,
struct V_112 * V_148 )
{
struct V_149 V_150 ;
if ( F_70 ( V_7 , V_148 , & V_150 ) == - V_151 )
return;
F_62 ( V_7 ) ;
F_71 ( V_7 , & V_150 ) ;
V_7 -> V_152 |= V_153 ;
F_65 ( V_7 ) ;
F_66 ( V_7 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_112 * V_148 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_1 ( V_2 ) ;
F_73 ( V_7 , V_148 ) ;
F_61 ( V_2 , V_148 -> V_146 , V_148 -> V_114 , V_148 -> V_154 ) ;
if ( ! V_148 -> V_154 && V_148 -> V_138 )
F_74 ( V_155 , & V_10 -> V_131 ) ;
}
static bool F_75 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
if ( F_55 () ) {
if ( V_2 -> V_98 != V_81 -> V_121 )
return true ;
}
if ( V_2 -> V_8 -> V_17 == V_18 ) {
if ( ( V_30 -> type != V_18 ) ||
( V_2 -> V_109 > 1 ) ) {
F_25 ( V_10 , V_110 ,
L_14 ) ;
return false ;
}
}
if ( V_2 -> V_8 -> V_17 == V_156 ) {
if ( ( V_30 -> type == V_156 ) &&
F_48 ( V_155 , & V_10 -> V_131 ) &&
V_30 != V_2 -> V_98 -> V_157 ) {
F_25 ( V_10 , V_110 ,
L_15 ) ;
return false ;
}
}
return true ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_158 * V_159 ,
struct V_160 * V_50 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_159 -> V_3 ;
F_25 ( V_10 , V_100 ,
L_16 , V_50 -> V_161 ) ;
V_113 -> V_117 = V_50 -> V_162 ;
V_113 -> V_163 = V_50 -> V_163 ;
V_113 -> V_164 = 1 ;
V_113 -> V_154 = V_50 -> V_154 ;
if ( V_113 -> V_117 == 0 )
V_113 -> V_117 = 100 ;
V_113 -> V_165 =
V_166 * V_113 -> V_117 ;
if ( V_113 -> V_163 == 0 )
V_113 -> V_163 = 1 ;
}
void F_77 ( struct V_1 * V_2 , struct V_29 * V_30 ,
T_3 V_167 )
{
struct V_160 * V_50 = & V_30 -> V_50 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_80 * V_81 = ( void * ) V_30 -> V_82 ;
struct V_158 * V_159 = V_81 -> V_121 ;
struct V_112 * V_113 ;
unsigned long V_63 ;
bool V_168 = false ;
if ( ! V_159 )
return;
V_113 = & V_81 -> V_121 -> V_3 ;
if ( V_30 -> type == V_18 )
F_39 ( V_2 , V_30 ) ;
if ( ! F_75 ( V_2 , V_30 ) )
return;
if ( V_30 -> type == V_156 ) {
F_76 ( V_2 , V_159 , V_50 ) ;
if ( V_159 != V_2 -> V_98 )
return;
F_78 ( V_2 ) ;
F_74 ( V_155 , & V_10 -> V_131 ) ;
return;
}
if ( V_167 & V_169 ) {
if ( ! V_50 -> V_138 &&
( V_2 -> V_109 <= 1 ) ) {
V_113 -> V_138 = false ;
} else if ( V_50 -> V_138 ) {
V_113 -> V_138 = true ;
F_76 ( V_2 , V_159 , V_50 ) ;
}
}
if ( V_159 != V_2 -> V_98 )
return;
if ( V_113 -> V_117 ) {
if ( ( V_167 & V_170 ) && ! V_50 -> V_154 &&
V_50 -> V_138 ) {
F_79 ( & V_2 -> V_171 , V_63 ) ;
V_2 -> V_172 |= V_173 | V_174 ;
F_80 ( & V_2 -> V_171 , V_63 ) ;
V_168 = true ;
} else {
F_78 ( V_2 ) ;
}
if ( V_113 -> V_138 && ! V_168 )
F_74 ( V_155 , & V_10 -> V_131 ) ;
else
F_81 ( V_155 , & V_10 -> V_131 ) ;
}
}
void F_78 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_112 * V_113 = & V_2 -> V_98 -> V_3 ;
switch ( V_2 -> V_8 -> V_17 ) {
case V_18 :
case V_19 :
F_67 ( V_2 , V_113 ) ;
break;
case V_175 :
F_72 ( V_2 , V_113 ) ;
break;
case V_156 :
F_69 ( V_2 -> V_8 , V_113 ) ;
break;
default:
F_25 ( V_10 , V_110 , L_17 ) ;
return;
}
}
