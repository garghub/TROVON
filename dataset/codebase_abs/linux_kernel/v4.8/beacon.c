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
if ( V_7 -> V_27 == 20 )
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
static void F_8 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_30 * V_31 , int V_32 )
{
struct V_33 * V_34 = V_31 -> V_35 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
T_1 V_40 = V_7 -> V_41 ;
T_1 V_42 , V_43 = 0 ;
V_39 = & V_10 -> V_44 [ V_2 -> V_45 . V_46 -> V_47 ] ;
V_43 = V_39 -> V_48 [ V_32 ] . V_49 ;
if ( V_29 -> V_50 . V_51 )
V_43 |= V_39 -> V_48 [ V_32 ] . V_52 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_53 = V_34 -> V_54 + V_55 ;
V_37 . type = V_56 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ )
V_37 . V_57 [ V_42 ] = V_58 ;
V_37 . V_59 = V_60 ;
V_37 . V_61 = V_62 ;
V_37 . V_63 = V_64 | V_65 ;
V_37 . V_66 [ 0 ] = V_31 -> V_67 ;
V_37 . V_68 [ 0 ] = F_9 ( V_34 -> V_54 , 4 ) ;
V_37 . V_69 = true ;
V_37 . V_70 = true ;
V_37 . V_71 = V_2 -> V_3 . V_16 ;
V_37 . V_72 [ 0 ] . V_73 = 1 ;
V_37 . V_72 [ 0 ] . V_74 = V_43 ;
V_37 . V_72 [ 0 ] . V_75 = F_10 ( V_2 , V_40 , V_43 ) ;
F_11 ( V_7 , V_31 -> V_76 , & V_37 ) ;
}
static struct V_30 * F_12 ( struct V_77 * V_78 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = V_78 -> V_79 ;
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_30 * V_31 ;
struct V_80 * V_81 = ( void * ) V_29 -> V_82 ;
struct V_33 * V_34 ;
struct V_14 * V_83 = V_2 -> V_3 . V_83 ;
struct V_84 * V_37 ;
struct V_85 * V_86 ;
int V_87 ;
if ( V_81 -> V_88 == NULL )
return NULL ;
V_31 = V_81 -> V_88 ;
V_34 = V_31 -> V_35 ;
if ( V_34 ) {
F_13 ( V_2 -> V_89 , V_31 -> V_67 ,
V_34 -> V_54 , V_90 ) ;
F_14 ( V_34 ) ;
V_31 -> V_67 = 0 ;
V_31 -> V_35 = NULL ;
}
V_34 = F_15 ( V_78 , V_29 ) ;
if ( V_34 == NULL )
return NULL ;
V_31 -> V_35 = V_34 ;
V_86 = (struct V_85 * ) V_34 -> V_91 ;
V_86 -> V_92 . V_3 . V_93 = V_81 -> V_94 ;
V_37 = F_16 ( V_34 ) ;
F_17 ( V_10 , V_34 ) ;
if ( F_18 () )
F_19 ( V_2 , V_81 , V_34 ) ;
V_31 -> V_67 = F_20 ( V_2 -> V_89 , V_34 -> V_91 ,
V_34 -> V_54 , V_90 ) ;
if ( F_21 ( F_22 ( V_2 -> V_89 , V_31 -> V_67 ) ) ) {
F_14 ( V_34 ) ;
V_31 -> V_35 = NULL ;
V_31 -> V_67 = 0 ;
F_6 ( V_10 , L_2 ) ;
return NULL ;
}
V_34 = F_23 ( V_78 , V_29 ) ;
F_24 ( & V_83 -> V_95 ) ;
V_87 = V_83 -> V_96 ;
F_25 ( & V_83 -> V_95 ) ;
if ( V_34 && V_87 ) {
if ( V_2 -> V_97 -> V_98 > 1 ) {
F_26 ( V_10 , V_99 ,
L_3 ) ;
F_27 ( V_2 , V_83 ) ;
}
}
F_8 ( V_2 , V_29 , V_31 , V_37 -> V_100 . V_72 [ 0 ] . V_101 ) ;
if ( V_34 )
F_28 ( V_78 , V_29 , V_34 ) ;
return V_31 ;
}
void F_29 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_29 -> V_82 ;
int V_102 ;
V_81 -> V_88 = F_30 ( & V_2 -> V_3 . V_103 , struct V_30 , V_104 ) ;
F_31 ( & V_81 -> V_88 -> V_104 ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
if ( V_2 -> V_3 . V_106 [ V_102 ] == NULL ) {
V_81 -> V_107 = V_102 ;
break;
}
}
V_2 -> V_3 . V_106 [ V_81 -> V_107 ] = V_29 ;
F_26 ( V_10 , V_108 , L_4 ,
V_81 -> V_107 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_80 * V_81 = ( void * ) V_29 -> V_82 ;
struct V_30 * V_31 = V_81 -> V_88 ;
F_26 ( V_10 , V_108 , L_5 ,
V_81 -> V_107 ) ;
F_33 ( & V_2 -> V_109 ) ;
if ( V_31 && V_31 -> V_35 ) {
struct V_33 * V_34 = V_31 -> V_35 ;
F_13 ( V_2 -> V_89 , V_31 -> V_67 ,
V_34 -> V_54 , V_90 ) ;
F_14 ( V_34 ) ;
V_31 -> V_35 = NULL ;
V_31 -> V_67 = 0 ;
}
V_81 -> V_88 = NULL ;
V_2 -> V_3 . V_106 [ V_81 -> V_107 ] = NULL ;
F_34 ( & V_31 -> V_104 , & V_2 -> V_3 . V_103 ) ;
F_35 ( & V_2 -> V_109 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_28 * V_29 ;
struct V_80 * V_81 ;
T_2 V_110 ;
T_3 V_111 ;
int V_112 = V_105 ;
int V_102 ;
F_33 ( & V_2 -> V_109 ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
if ( V_2 -> V_3 . V_106 [ V_102 ] ) {
V_112 = V_102 ;
break;
}
}
if ( V_112 == 0 )
goto V_113;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
if ( V_102 + V_112 < V_105 ) {
V_29 = V_2 -> V_3 . V_106 [ V_102 + V_112 ] ;
V_2 -> V_3 . V_106 [ V_102 ] = V_29 ;
if ( V_29 ) {
V_81 = ( void * ) V_29 -> V_82 ;
V_81 -> V_107 = V_102 ;
}
} else {
V_2 -> V_3 . V_106 [ V_102 ] = NULL ;
}
}
V_29 = V_2 -> V_3 . V_106 [ 0 ] ;
if ( F_37 ( ! V_29 ) )
goto V_113;
V_81 = ( void * ) V_29 -> V_82 ;
V_110 = F_38 ( V_81 -> V_94 ) ;
F_26 ( V_10 , V_108 ,
L_6 ,
( signed long long ) V_110 ) ;
V_81 -> V_114 -> V_115 += V_110 ;
if ( V_2 -> V_97 == V_81 -> V_114 ) {
V_111 = F_39 ( & V_81 -> V_114 -> V_116 , NULL ) ;
F_40 ( V_2 -> V_8 , V_81 -> V_114 -> V_115 + V_111 ) ;
}
V_113:
F_35 ( & V_2 -> V_109 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_117 * V_118 = & V_2 -> V_97 -> V_3 ;
T_4 V_119 ;
T_3 V_120 ;
T_5 V_121 ;
int V_102 ;
if ( V_2 -> V_8 -> V_17 != V_18 &&
V_2 -> V_8 -> V_17 != V_19 ) {
F_26 ( V_10 , V_99 , L_7 ,
F_42 ( V_2 -> V_8 ) ) ;
return 0 ;
}
V_119 = V_118 -> V_122 ? : V_123 ;
V_121 = F_42 ( V_2 -> V_8 ) ;
V_121 += F_43 ( V_2 -> V_8 -> V_124 . V_125 ) ;
V_120 = F_44 ( ( V_121 * V_105 ) >> 32 , V_121 * V_105 ) ;
V_102 = ( V_120 % ( V_119 * V_105 ) ) / V_119 ;
F_26 ( V_10 , V_99 , L_8 ,
V_102 , V_121 , V_120 / V_105 ) ;
return V_102 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
T_2 V_110 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
struct V_80 * V_81 ;
if ( ! V_2 -> V_3 . V_106 [ V_102 ] )
continue;
V_81 = ( void * ) V_2 -> V_3 . V_106 [ V_102 ] -> V_82 ;
V_110 = V_118 -> V_122 * V_81 -> V_107 ;
V_110 = - F_43 ( V_110 ) / V_105 ;
V_81 -> V_94 = F_46 ( V_110 ) ;
F_26 ( V_10 , V_108 , L_9 ,
( signed long long ) V_110 , V_81 -> V_107 ) ;
}
}
bool F_47 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_126 )
return false ;
if ( ! F_48 ( V_29 ) )
return false ;
F_49 ( V_29 ) ;
return true ;
}
static void F_50 ( void * V_91 , T_1 * V_127 , struct V_28 * V_29 )
{
struct V_1 * V_2 = V_91 ;
F_47 ( V_2 , V_29 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_78 ,
V_128 ,
F_50 , V_2 ) ;
}
void F_53 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_30 * V_31 = NULL ;
struct V_28 * V_29 ;
bool V_129 = ! ! ( V_7 -> V_130 . V_131 & V_132 ) ;
int V_102 ;
if ( F_54 ( V_133 , & V_10 -> V_134 ) ) {
F_26 ( V_10 , V_135 ,
L_10 ) ;
return;
}
if ( F_55 ( V_7 , V_2 -> V_3 . V_16 ) != 0 ) {
V_2 -> V_3 . V_136 ++ ;
F_56 ( V_7 ) ;
if ( ! F_57 ( V_2 ) )
return;
if ( V_2 -> V_3 . V_136 < V_137 * V_2 -> V_138 ) {
F_26 ( V_10 , V_139 ,
L_11 ,
V_2 -> V_3 . V_136 ) ;
F_58 ( V_7 , V_2 -> V_3 . V_16 ) ;
if ( V_2 -> V_3 . V_136 > 3 )
F_59 ( V_7 ) ;
} else if ( V_2 -> V_3 . V_136 >= V_137 ) {
F_26 ( V_10 , V_139 , L_12 ) ;
V_2 -> V_3 . V_136 = 0 ;
F_60 ( V_2 , V_140 ) ;
}
return;
}
V_102 = F_41 ( V_2 ) ;
V_29 = V_2 -> V_3 . V_106 [ V_102 ] ;
if ( ! V_129 ) {
if ( F_18 () ) {
F_61 ( V_2 ,
V_141 ) ;
}
if ( F_47 ( V_2 , V_29 ) )
return;
}
if ( ! V_29 || ! V_29 -> V_50 . V_142 )
return;
if ( F_18 () ) {
F_62 ( V_2 , V_29 , V_143 ) ;
}
V_31 = F_12 ( V_2 -> V_78 , V_29 ) ;
if ( V_2 -> V_3 . V_136 != 0 ) {
F_26 ( V_10 , V_139 , L_13 ,
V_2 -> V_3 . V_136 ) ;
V_2 -> V_3 . V_136 = 0 ;
}
if ( V_2 -> V_3 . V_144 == V_145 ) {
V_2 -> V_3 . V_144 = V_146 ;
V_2 -> V_3 . V_147 = V_102 ;
} else if ( V_2 -> V_3 . V_144 == V_146 &&
V_2 -> V_3 . V_147 == V_102 ) {
V_7 -> V_27 = V_2 -> V_3 . V_27 ;
F_63 ( V_7 ) ;
V_2 -> V_3 . V_144 = V_148 ;
}
if ( V_31 ) {
F_1 ( V_2 ) ;
F_26 ( V_10 , V_99 ,
L_14 , V_102 ) ;
F_64 ( V_7 , V_2 -> V_3 . V_16 , V_31 -> V_149 ) ;
if ( ! V_129 )
F_65 ( V_7 , V_2 -> V_3 . V_16 ) ;
}
}
static void F_66 ( struct V_1 * V_2 , T_3 V_150 ,
T_3 V_119 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_67 ( V_7 ) ;
F_2 ( V_2 ) ;
F_68 ( V_7 , V_150 , V_119 ) ;
V_7 -> V_151 |= V_152 ;
V_2 -> V_3 . V_136 = 0 ;
F_69 ( V_7 ) ;
F_70 ( V_7 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_67 ( V_2 -> V_8 ) ;
V_2 -> V_8 -> V_151 &= ~ ( V_152 | V_153 ) ;
V_2 -> V_3 . V_136 = 0 ;
F_69 ( V_2 -> V_8 ) ;
F_70 ( V_2 -> V_8 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_117 * V_154 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_73 ( V_7 , V_154 , V_105 ) ;
F_66 ( V_2 , V_154 -> V_150 , V_154 -> V_119 ) ;
}
static void F_74 ( struct V_6 * V_7 ,
struct V_117 * V_154 )
{
struct V_155 V_156 ;
if ( F_75 ( V_7 , V_154 , & V_156 ) == - V_157 )
return;
F_67 ( V_7 ) ;
F_76 ( V_7 , & V_156 ) ;
V_7 -> V_151 |= V_153 ;
F_69 ( V_7 ) ;
F_70 ( V_7 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_117 * V_154 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_1 ( V_2 ) ;
F_78 ( V_7 , V_154 ) ;
F_66 ( V_2 , V_154 -> V_150 , V_154 -> V_119 ) ;
if ( ! V_154 -> V_158 && V_154 -> V_142 )
F_79 ( V_159 , & V_10 -> V_134 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
struct V_162 * V_50 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_117 * V_118 = & V_161 -> V_3 ;
F_26 ( V_10 , V_99 ,
L_15 , V_50 -> V_163 ) ;
V_118 -> V_122 = V_50 -> V_164 ;
V_118 -> V_165 = V_50 -> V_165 ;
V_118 -> V_166 = 1 ;
V_118 -> V_158 = V_50 -> V_158 ;
if ( V_118 -> V_122 == 0 )
V_118 -> V_122 = 100 ;
V_118 -> V_167 =
V_168 * V_118 -> V_122 ;
if ( V_118 -> V_165 == 0 )
V_118 -> V_165 = 1 ;
F_45 ( V_2 , V_118 ) ;
}
void F_81 ( struct V_1 * V_2 , struct V_28 * V_169 ,
bool V_170 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_80 * V_81 ;
struct V_160 * V_161 ;
struct V_117 * V_118 ;
unsigned long V_63 ;
bool V_171 ;
bool V_172 = false ;
if ( ! V_170 ) {
F_82 ( V_159 , & V_10 -> V_134 ) ;
F_71 ( V_2 ) ;
return;
}
if ( F_37 ( ! V_169 ) )
return;
V_81 = ( void * ) V_169 -> V_82 ;
V_161 = V_81 -> V_114 ;
V_118 = & V_161 -> V_3 ;
V_171 = V_118 -> V_142 ;
V_118 -> V_142 = V_170 ;
if ( V_2 -> V_8 -> V_17 == V_173 ) {
F_80 ( V_2 , V_161 , & V_169 -> V_50 ) ;
F_83 ( V_2 ) ;
F_79 ( V_159 , & V_10 -> V_134 ) ;
return;
}
F_80 ( V_2 , V_161 , & V_169 -> V_50 ) ;
if ( V_118 -> V_122 ) {
if ( V_2 -> V_8 -> V_17 == V_174 &&
! V_171 && V_170 && ! V_169 -> V_50 . V_158 ) {
F_84 ( & V_2 -> V_175 , V_63 ) ;
V_2 -> V_176 |= V_177 | V_178 ;
F_85 ( & V_2 -> V_175 , V_63 ) ;
V_172 = true ;
}
if ( V_170 && ! V_172 ) {
F_79 ( V_159 , & V_10 -> V_134 ) ;
F_83 ( V_2 ) ;
} else {
F_82 ( V_159 , & V_10 -> V_134 ) ;
F_71 ( V_2 ) ;
}
} else {
F_82 ( V_159 , & V_10 -> V_134 ) ;
F_71 ( V_2 ) ;
}
}
void F_83 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_117 * V_118 = & V_2 -> V_97 -> V_3 ;
switch ( V_2 -> V_8 -> V_17 ) {
case V_18 :
case V_19 :
F_72 ( V_2 , V_118 ) ;
break;
case V_174 :
F_77 ( V_2 , V_118 ) ;
break;
case V_173 :
F_74 ( V_2 -> V_8 , V_118 ) ;
break;
default:
F_26 ( V_10 , V_108 , L_16 ) ;
return;
}
}
