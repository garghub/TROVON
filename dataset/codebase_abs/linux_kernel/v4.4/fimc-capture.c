static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
int V_9 ;
unsigned long V_10 ;
if ( V_8 == NULL || V_8 -> V_11 . V_12 == NULL )
return - V_13 ;
if ( V_4 -> V_14 == V_15 ) {
V_9 = F_2 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
}
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_4 ( V_8 , & V_8 -> V_17 ) ;
F_5 ( V_8 ) ;
F_6 ( V_2 , V_4 ) ;
F_7 ( V_2 , V_4 ) ;
F_8 ( V_2 , V_4 ) ;
F_9 ( V_2 , & V_8 -> V_11 ) ;
V_9 = F_10 ( V_8 ) ;
if ( ! V_9 ) {
F_11 ( V_8 ) ;
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
F_18 ( V_8 ) ;
if ( V_2 -> V_18 -> V_19 )
F_19 ( V_8 ) ;
F_20 ( V_20 , & V_2 -> V_21 ) ;
}
F_21 ( & V_2 -> V_16 , V_10 ) ;
return V_9 ;
}
static int F_22 ( struct V_1 * V_2 , bool V_22 )
{
struct V_23 * V_24 = & V_2 -> V_5 ;
struct V_25 * V_26 ;
unsigned long V_10 ;
bool V_27 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
V_27 = V_2 -> V_21 & ( 1 << V_28 ) ;
V_2 -> V_21 &= ~ ( 1 << V_29 | 1 << V_30 |
1 << V_31 | 1 << V_28 ) ;
if ( V_22 )
V_2 -> V_21 |= ( 1 << V_32 ) ;
else
V_2 -> V_21 &= ~ ( 1 << V_33 | 1 << V_32 ) ;
while ( ! V_22 && ! F_23 ( & V_24 -> V_34 ) ) {
V_26 = F_24 ( V_24 ) ;
F_25 ( & V_26 -> V_35 . V_36 , V_37 ) ;
}
while ( ! F_23 ( & V_24 -> V_38 ) ) {
V_26 = F_26 ( V_24 ) ;
if ( V_22 )
F_27 ( V_24 , V_26 ) ;
else
F_25 ( & V_26 -> V_35 . V_36 , V_37 ) ;
}
F_28 ( V_2 ) ;
V_24 -> V_39 = 0 ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
if ( V_27 )
return F_29 ( & V_24 -> V_40 , V_41 , 0 ) ;
else
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , bool V_22 )
{
unsigned long V_10 ;
if ( ! F_31 ( V_2 ) )
return 0 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_32 ( V_30 , & V_2 -> V_21 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
F_34 ( V_2 -> V_42 ,
! F_35 ( V_30 , & V_2 -> V_21 ) ,
( 2 * V_43 / 10 ) ) ;
return F_22 ( V_2 , V_22 ) ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_1 ;
int V_9 ;
F_9 ( V_2 , & V_8 -> V_11 ) ;
V_9 = F_10 ( V_8 ) ;
if ( V_9 )
return V_9 ;
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_4 ( V_8 , & V_8 -> V_17 ) ;
F_18 ( V_8 ) ;
if ( V_2 -> V_18 -> V_19 )
F_19 ( V_8 ) ;
F_20 ( V_20 , & V_2 -> V_21 ) ;
return V_9 ;
}
void F_37 ( struct V_1 * V_2 , int V_44 )
{
struct V_23 * V_24 = & V_2 -> V_5 ;
struct V_45 * V_46 = F_38 ( V_24 -> V_40 . V_47 ) ;
struct V_48 * V_49 = V_46 -> V_50 [ V_51 ] ;
struct V_52 * V_53 = & V_24 -> V_8 -> V_17 ;
struct V_25 * V_54 ;
if ( F_39 ( V_30 , & V_2 -> V_21 ) ) {
F_40 ( & V_2 -> V_42 ) ;
goto V_55;
}
if ( ! F_23 ( & V_24 -> V_38 ) &&
F_35 ( V_29 , & V_2 -> V_21 ) && V_44 ) {
V_54 = F_26 ( V_24 ) ;
F_41 ( & V_54 -> V_35 . V_56 ) ;
V_54 -> V_35 . V_57 = V_24 -> V_58 ++ ;
F_25 ( & V_54 -> V_35 . V_36 , V_59 ) ;
}
if ( ! F_23 ( & V_24 -> V_34 ) ) {
V_54 = F_24 ( V_24 ) ;
F_42 ( V_2 , & V_54 -> V_60 , V_24 -> V_39 ) ;
V_54 -> V_61 = V_24 -> V_39 ;
F_43 ( V_24 , V_54 ) ;
F_44 ( L_1 ,
F_45 ( V_2 ) , V_54 -> V_61 ) ;
if ( ++ V_24 -> V_39 >= V_62 )
V_24 -> V_39 = 0 ;
}
if ( V_53 -> V_12 -> V_63 && ! F_23 ( & V_24 -> V_38 ) ) {
unsigned int V_64 = F_46 ( V_53 -> V_12 -> V_63 ) - 1 ;
unsigned int V_65 = V_53 -> V_66 [ V_64 ] ;
T_1 V_61 = F_45 ( V_2 ) ;
void * V_67 ;
F_47 (v_buf, &cap->active_buf_q, list) {
if ( V_54 -> V_61 != V_61 )
continue;
V_67 = F_48 ( & V_54 -> V_35 . V_36 , V_64 ) ;
F_49 ( V_49 , V_68 , V_69 ,
V_67 , & V_65 ) ;
break;
}
}
if ( V_24 -> V_70 == 0 ) {
if ( V_44 )
F_20 ( V_29 , & V_2 -> V_21 ) ;
if ( ++ V_24 -> V_39 >= V_62 )
V_24 -> V_39 = 0 ;
} else {
F_32 ( V_29 , & V_2 -> V_21 ) ;
}
if ( F_35 ( V_20 , & V_2 -> V_21 ) )
F_36 ( V_24 -> V_8 ) ;
V_55:
if ( V_24 -> V_70 == 1 ) {
F_33 ( V_2 ) ;
F_20 ( V_31 , & V_2 -> V_21 ) ;
}
F_44 ( L_2 ,
F_45 ( V_2 ) , V_24 -> V_70 ) ;
}
static int F_50 ( struct V_71 * V_72 , unsigned int V_73 )
{
struct V_7 * V_8 = V_72 -> V_74 ;
struct V_1 * V_2 = V_8 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
int V_75 ;
int V_9 ;
V_5 -> V_58 = 0 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 ) {
F_22 ( V_2 , false ) ;
return V_9 ;
}
F_32 ( V_33 , & V_2 -> V_21 ) ;
V_75 = V_2 -> V_5 . V_76 > 1 ? 2 : 1 ;
if ( V_5 -> V_70 >= V_75 &&
! F_51 ( V_31 , & V_2 -> V_21 ) ) {
F_52 ( V_8 ) ;
if ( ! F_51 ( V_28 , & V_2 -> V_21 ) )
return F_29 ( & V_5 -> V_40 , V_41 , 1 ) ;
}
return 0 ;
}
static void F_53 ( struct V_71 * V_72 )
{
struct V_7 * V_8 = V_72 -> V_74 ;
struct V_1 * V_2 = V_8 -> V_1 ;
if ( ! F_31 ( V_2 ) )
return;
F_30 ( V_2 , false ) ;
}
int F_54 ( struct V_1 * V_2 )
{
bool V_22 = F_55 ( V_2 ) ;
int V_9 = F_30 ( V_2 , V_22 ) ;
if ( V_9 )
return V_9 ;
return F_29 ( & V_2 -> V_5 . V_40 , V_77 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_5 -> V_40 ;
struct V_25 * V_26 ;
int V_79 ;
if ( ! F_39 ( V_32 , & V_2 -> V_21 ) )
return 0 ;
F_57 ( & V_2 -> V_5 . V_38 ) ;
V_5 -> V_39 = 0 ;
F_29 ( V_40 , V_80 , & V_40 -> V_81 . V_82 , false ) ;
F_1 ( V_2 ) ;
F_20 ( V_32 , & V_2 -> V_21 ) ;
for ( V_79 = 0 ; V_79 < V_5 -> V_76 ; V_79 ++ ) {
if ( F_23 ( & V_5 -> V_34 ) )
break;
V_26 = F_24 ( V_5 ) ;
F_58 ( & V_26 -> V_35 . V_36 ) ;
}
return 0 ;
}
static int F_59 ( struct V_71 * V_83 , const void * V_84 ,
unsigned int * V_85 , unsigned int * V_86 ,
unsigned int V_87 [] , void * V_88 [] )
{
const struct V_89 * V_90 = V_84 ;
const struct V_91 * V_92 = NULL ;
struct V_7 * V_8 = V_83 -> V_74 ;
struct V_52 * V_93 = & V_8 -> V_17 ;
struct V_94 * V_12 = V_93 -> V_12 ;
unsigned long V_95 ;
int V_79 ;
if ( V_90 ) {
V_92 = & V_90 -> V_12 . V_96 ;
V_12 = F_60 ( & V_92 -> V_97 , NULL ,
V_98 | V_99 , - 1 ) ;
V_95 = V_92 -> V_100 * V_92 -> V_101 ;
} else {
V_95 = V_93 -> V_102 * V_93 -> V_103 ;
}
if ( V_12 == NULL )
return - V_13 ;
* V_86 = V_12 -> V_104 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_104 ; V_79 ++ ) {
unsigned int V_65 = ( V_95 * V_12 -> V_105 [ V_79 ] ) / 8 ;
if ( V_92 )
V_87 [ V_79 ] = F_61 ( V_65 , V_92 -> V_106 [ V_79 ] . V_107 ) ;
else if ( F_62 ( V_12 -> V_108 ) )
V_87 [ V_79 ] = V_93 -> V_66 [ V_79 ] ;
else
V_87 [ V_79 ] = F_63 ( V_109 , V_65 , V_93 -> V_66 [ V_79 ] ) ;
V_88 [ V_79 ] = V_8 -> V_1 -> V_110 ;
}
return 0 ;
}
static int F_64 ( struct V_111 * V_35 )
{
struct V_71 * V_83 = V_35 -> V_71 ;
struct V_7 * V_8 = V_83 -> V_74 ;
int V_79 ;
if ( V_8 -> V_17 . V_12 == NULL )
return - V_13 ;
for ( V_79 = 0 ; V_79 < V_8 -> V_17 . V_12 -> V_104 ; V_79 ++ ) {
unsigned long V_65 = V_8 -> V_17 . V_66 [ V_79 ] ;
if ( F_65 ( V_35 , V_79 ) < V_65 ) {
F_66 ( & V_8 -> V_1 -> V_5 . V_40 . V_81 ,
L_3 ,
F_65 ( V_35 , V_79 ) , V_65 ) ;
return - V_13 ;
}
F_67 ( V_35 , V_79 , V_65 ) ;
}
return 0 ;
}
static void F_58 ( struct V_111 * V_35 )
{
struct V_112 * V_113 = F_68 ( V_35 ) ;
struct V_25 * V_26
= F_69 ( V_113 , struct V_25 , V_35 ) ;
struct V_7 * V_8 = F_70 ( V_35 -> V_71 ) ;
struct V_1 * V_2 = V_8 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_5 -> V_40 ;
unsigned long V_10 ;
int V_75 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_71 ( V_8 , & V_26 -> V_35 . V_36 , & V_8 -> V_17 , & V_26 -> V_60 ) ;
if ( ! F_35 ( V_32 , & V_2 -> V_21 ) &&
! F_35 ( V_31 , & V_2 -> V_21 ) &&
V_5 -> V_70 < V_62 ) {
int V_114 = ( V_5 -> V_76 == 1 ) ? - 1 :
V_5 -> V_39 ;
F_42 ( V_2 , & V_26 -> V_60 , V_114 ) ;
V_26 -> V_61 = V_5 -> V_39 ;
F_43 ( V_5 , V_26 ) ;
if ( ++ V_5 -> V_39 >= V_62 )
V_5 -> V_39 = 0 ;
} else {
F_27 ( V_5 , V_26 ) ;
}
V_75 = V_5 -> V_76 > 1 ? 2 : 1 ;
if ( F_72 ( & V_5 -> V_115 ) &&
V_5 -> V_70 >= V_75 &&
! F_51 ( V_31 , & V_2 -> V_21 ) ) {
int V_9 ;
F_52 ( V_8 ) ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
if ( F_51 ( V_28 , & V_2 -> V_21 ) )
return;
V_9 = F_29 ( V_40 , V_41 , 1 ) ;
if ( V_9 < 0 )
F_66 ( & V_40 -> V_81 , L_4 , V_9 ) ;
return;
}
F_21 ( & V_2 -> V_16 , V_10 ) ;
}
static int F_73 ( struct V_116 * V_116 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_117 -> V_40 ;
int V_9 = - V_118 ;
F_44 ( L_5 , F_75 ( V_119 ) , V_2 -> V_21 ) ;
F_76 ( & V_2 -> V_120 ) ;
if ( F_77 ( V_2 ) )
goto V_121;
F_32 ( V_122 , & V_2 -> V_21 ) ;
V_9 = F_78 ( & V_2 -> V_123 -> V_124 ) ;
if ( V_9 < 0 )
goto V_121;
V_9 = F_79 ( V_116 ) ;
if ( V_9 ) {
F_80 ( & V_2 -> V_123 -> V_124 ) ;
goto V_121;
}
if ( F_81 ( V_116 ) ) {
F_82 ( V_40 ) ;
V_9 = F_29 ( V_40 , V_80 , & V_40 -> V_81 . V_82 , true ) ;
if ( V_9 == 0 && V_117 -> V_125 && V_117 -> V_126 ) {
F_83 ( V_117 -> V_8 ) ;
V_9 = F_84 ( V_117 -> V_8 ) ;
if ( V_9 == 0 )
V_117 -> V_126 = false ;
}
if ( V_9 == 0 )
V_40 -> V_81 . V_82 . V_127 ++ ;
F_85 ( V_40 ) ;
if ( V_9 == 0 )
V_9 = F_86 ( V_2 ) ;
if ( V_9 < 0 ) {
F_20 ( V_122 , & V_2 -> V_21 ) ;
F_80 ( & V_2 -> V_123 -> V_124 ) ;
F_87 ( V_116 ) ;
}
}
V_121:
F_88 ( & V_2 -> V_120 ) ;
return V_9 ;
}
static int F_89 ( struct V_116 * V_116 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_23 * V_117 = & V_2 -> V_5 ;
bool V_77 = F_81 ( V_116 ) ;
int V_9 ;
F_44 ( L_5 , F_75 ( V_119 ) , V_2 -> V_21 ) ;
F_76 ( & V_2 -> V_120 ) ;
if ( V_77 && V_117 -> V_27 ) {
F_90 ( & V_117 -> V_40 . V_81 . V_82 ) ;
V_117 -> V_27 = false ;
}
V_9 = F_91 ( V_116 , NULL ) ;
if ( V_77 ) {
F_20 ( V_122 , & V_2 -> V_21 ) ;
F_29 ( & V_117 -> V_40 , V_77 ) ;
F_20 ( V_32 , & V_2 -> V_21 ) ;
F_82 ( & V_117 -> V_40 ) ;
V_117 -> V_40 . V_81 . V_82 . V_127 -- ;
F_85 ( & V_117 -> V_40 ) ;
}
F_80 ( & V_2 -> V_123 -> V_124 ) ;
F_88 ( & V_2 -> V_120 ) ;
return V_9 ;
}
static struct V_94 * F_92 ( struct V_7 * V_8 ,
V_109 * V_100 , V_109 * V_101 ,
V_109 * V_128 , V_109 * V_129 , int V_130 )
{
bool V_131 = V_8 -> V_131 == 90 || V_8 -> V_131 == 270 ;
struct V_1 * V_2 = V_8 -> V_1 ;
const struct V_132 * V_133 = V_2 -> V_134 ;
const struct V_135 * V_136 = V_133 -> V_137 ;
struct V_52 * V_138 = & V_8 -> V_17 ;
V_109 V_105 , V_139 , V_140 , V_141 , V_142 = 3 ;
V_109 V_143 = V_98 ;
struct V_94 * V_144 ;
if ( V_128 && V_8 -> V_11 . V_12 && V_130 == V_145 &&
F_62 ( V_8 -> V_11 . V_12 -> V_108 ) )
* V_128 = V_8 -> V_11 . V_12 -> V_146 ;
if ( V_129 && * V_129 != V_147 && V_130 == V_145 )
V_143 |= V_99 ;
if ( V_130 == V_148 )
V_143 = V_149 ;
V_144 = F_60 ( V_129 , V_128 , V_143 , 0 ) ;
if ( F_93 ( ! V_144 ) )
return NULL ;
if ( V_128 )
* V_128 = V_144 -> V_146 ;
if ( V_129 )
* V_129 = V_144 -> V_129 ;
if ( V_130 != V_145 ) {
V_140 = F_62 ( V_144 -> V_108 ) ?
V_136 -> V_150 : V_136 -> V_151 ;
F_94 ( V_100 , F_63 ( V_109 , * V_100 , 32 ) , V_140 , 4 ,
V_101 , F_63 ( V_109 , * V_101 , 32 ) ,
V_152 ,
F_62 ( V_144 -> V_108 ) ?
3 : 1 ,
0 ) ;
return V_144 ;
}
if ( F_62 ( V_144 -> V_108 ) ) {
* V_100 = V_8 -> V_11 . V_102 ;
* V_101 = V_8 -> V_11 . V_103 ;
return V_144 ;
}
V_140 = V_131 ? V_136 -> V_153 : V_136 -> V_154 ;
if ( V_8 -> V_21 & V_155 ) {
V_139 = V_138 -> V_156 + V_138 -> V_100 ;
V_141 = V_138 -> V_157 + V_138 -> V_101 ;
} else {
V_139 = V_133 -> V_158 ;
V_141 = V_133 -> V_158 ;
}
if ( V_133 -> V_159 == 1 && ! V_131 )
V_142 = F_95 ( V_144 -> V_108 ) ? 0 : 1 ;
V_105 = F_96 ( V_144 ) ;
F_94 ( V_100 , V_139 , V_140 ,
F_46 ( V_133 -> V_158 ) - 1 ,
V_101 , V_141 , V_152 ,
V_142 ,
64 / ( F_97 ( V_105 , 8 ) ) ) ;
F_44 ( L_6 ,
V_130 , V_128 ? * V_128 : 0 , * V_100 , * V_101 ,
V_138 -> V_102 , V_138 -> V_103 ) ;
return V_144 ;
}
static void F_98 ( struct V_7 * V_8 ,
struct V_160 * V_161 ,
int V_162 )
{
bool V_163 = V_8 -> V_131 == 90 || V_8 -> V_131 == 270 ;
struct V_1 * V_2 = V_8 -> V_1 ;
const struct V_132 * V_133 = V_2 -> V_134 ;
const struct V_135 * V_136 = V_133 -> V_137 ;
struct V_52 * V_164 = & V_8 -> V_11 ;
V_109 V_140 , V_165 , V_139 = 0 , V_141 = 0 , V_166 ;
V_109 V_167 = 0 , V_142 = 4 ;
V_109 V_168 , V_169 ;
if ( F_62 ( V_8 -> V_17 . V_12 -> V_108 ) ) {
V_161 -> V_100 = V_164 -> V_102 ;
V_161 -> V_101 = V_164 -> V_103 ;
V_161 -> V_170 = V_161 -> V_171 = 0 ;
return;
}
if ( V_162 == V_172 ) {
if ( V_8 -> V_131 != 90 && V_8 -> V_131 != 270 )
V_142 = 1 ;
V_168 = F_99 ( V_173 , 1 << ( F_46 ( V_164 -> V_100 ) - 3 ) ) ;
V_169 = F_99 ( V_174 , 1 << ( F_46 ( V_164 -> V_101 ) - 1 ) ) ;
V_166 = V_133 -> V_158 ;
} else {
V_109 V_105 = F_96 ( V_164 -> V_12 ) ;
V_167 = 64 / F_97 ( V_105 , 8 ) ;
V_166 = V_133 -> V_175 ;
V_139 = V_141 = V_166 ;
V_168 = V_169 = 1 ;
}
V_140 = F_100 ( V_109 ,
V_163 ? V_136 -> V_153 : V_136 -> V_154 ,
V_163 ? V_164 -> V_103 : V_164 -> V_102 ) ;
V_165 = F_100 ( V_109 , V_152 , V_164 -> V_103 ) ;
if ( V_162 == V_172 ) {
V_139 = F_100 ( V_109 , V_140 , V_164 -> V_102 / V_168 ) ;
V_141 = F_100 ( V_109 , V_165 , V_164 -> V_103 / V_169 ) ;
if ( V_163 ) {
F_101 ( V_168 , V_169 ) ;
F_101 ( V_139 , V_141 ) ;
}
}
F_94 ( & V_161 -> V_100 , V_139 , V_140 , F_46 ( V_166 ) - 1 ,
& V_161 -> V_101 , V_141 , V_165 , V_142 ,
V_167 ) ;
V_161 -> V_170 = F_102 ( V_109 , V_161 -> V_170 , 0 , V_164 -> V_102 - V_161 -> V_100 ) ;
V_161 -> V_171 = F_102 ( V_109 , V_161 -> V_171 , 0 , V_164 -> V_103 - V_161 -> V_101 ) ;
V_161 -> V_170 = F_103 ( V_161 -> V_170 , V_133 -> V_176 ) ;
F_44 ( L_7 ,
V_162 , V_161 -> V_170 , V_161 -> V_171 , V_161 -> V_100 , V_161 -> V_101 ,
V_164 -> V_102 , V_164 -> V_103 ) ;
}
static int F_104 ( struct V_116 * V_116 , void * V_177 ,
struct V_178 * V_24 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
F_105 ( & V_2 -> V_123 -> V_124 , V_24 , V_179 |
V_180 ) ;
return 0 ;
}
static int F_106 ( struct V_116 * V_116 , void * V_177 ,
struct V_181 * V_53 )
{
struct V_94 * V_12 ;
V_12 = F_60 ( NULL , NULL , V_98 | V_99 ,
V_53 -> V_61 ) ;
if ( ! V_12 )
return - V_13 ;
strncpy ( V_53 -> V_182 , V_12 -> V_183 , sizeof( V_53 -> V_182 ) - 1 ) ;
V_53 -> V_97 = V_12 -> V_129 ;
if ( V_12 -> V_129 == V_184 )
V_53 -> V_10 |= V_185 ;
return 0 ;
}
static struct V_186 * F_107 ( struct V_186 * V_187 )
{
struct V_188 * V_130 = & V_187 -> V_189 [ 0 ] ;
while ( ! ( V_130 -> V_10 & V_190 ) ) {
V_130 = F_108 ( V_130 ) ;
if ( ! V_130 )
break;
V_187 = V_130 -> V_82 ;
V_130 = & V_187 -> V_189 [ 0 ] ;
}
return V_187 ;
}
static int F_109 ( struct V_7 * V_8 ,
struct V_191 * V_192 ,
struct V_94 * * V_193 ,
bool V_194 )
{
struct V_1 * V_2 = V_8 -> V_1 ;
struct V_45 * V_46 = F_38 ( V_2 -> V_5 . V_40 . V_47 ) ;
struct V_48 * V_195 = V_46 -> V_50 [ V_196 ] ;
struct V_197 V_198 ;
struct V_191 * V_199 = & V_198 . V_200 ;
struct V_186 * V_187 ;
struct V_94 * V_144 ;
struct V_188 * V_130 ;
int V_9 , V_79 = 1 ;
V_109 V_201 ;
if ( F_93 ( ! V_195 || ! V_192 ) )
return - V_13 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_200 = * V_192 ;
V_198 . V_202 = V_194 ? V_203 : V_204 ;
V_187 = F_107 ( & V_195 -> V_82 ) ;
while ( 1 ) {
V_144 = F_60 ( NULL , V_199 -> V_128 != 0 ? & V_199 -> V_128 : NULL ,
V_98 , V_79 ++ ) ;
if ( V_144 == NULL ) {
return - V_13 ;
}
V_199 -> V_128 = V_192 -> V_128 = V_144 -> V_146 ;
while ( V_187 != & V_2 -> V_5 . V_205 . V_82 ) {
V_195 = F_110 ( V_187 ) ;
V_198 . V_130 = 0 ;
V_9 = F_49 ( V_195 , V_130 , V_206 , NULL , & V_198 ) ;
if ( V_9 )
return V_9 ;
if ( V_187 -> V_189 [ 0 ] . V_10 & V_207 ) {
V_198 . V_130 = V_187 -> V_208 - 1 ;
V_199 -> V_128 = V_192 -> V_128 ;
V_9 = F_49 ( V_195 , V_130 , V_206 , NULL ,
& V_198 ) ;
if ( V_9 )
return V_9 ;
}
V_130 = F_108 ( & V_187 -> V_189 [ V_198 . V_130 ] ) ;
if ( ! V_130 )
return - V_13 ;
V_187 = V_130 -> V_82 ;
}
if ( V_199 -> V_128 != V_192 -> V_128 )
continue;
V_201 = V_144 -> V_129 ;
V_192 -> V_100 = V_199 -> V_100 ;
V_192 -> V_101 = V_199 -> V_101 ;
V_144 = F_92 ( V_8 , & V_192 -> V_100 , & V_192 -> V_101 ,
NULL , & V_201 , V_209 ) ;
V_144 = F_92 ( V_8 , & V_192 -> V_100 , & V_192 -> V_101 ,
NULL , & V_201 , V_145 ) ;
if ( V_144 && V_144 -> V_146 )
V_199 -> V_128 = V_144 -> V_146 ;
if ( V_199 -> V_100 != V_192 -> V_100 || V_199 -> V_101 != V_192 -> V_101 )
continue;
V_192 -> V_128 = V_199 -> V_128 ;
break;
}
if ( V_193 && V_144 )
* V_193 = V_144 ;
* V_192 = * V_199 ;
return 0 ;
}
static int F_111 ( struct V_48 * V_210 ,
struct V_211 * V_106 ,
unsigned int V_86 , bool V_212 )
{
struct V_213 V_214 ;
int V_79 , V_9 ;
int V_130 ;
for ( V_79 = 0 ; V_79 < V_86 ; V_79 ++ )
V_214 . V_215 [ V_79 ] . V_216 = V_106 [ V_79 ] . V_107 ;
V_130 = V_210 -> V_82 . V_208 - 1 ;
if ( V_212 )
V_9 = F_49 ( V_210 , V_130 , V_217 , V_130 , & V_214 ) ;
else
V_9 = F_49 ( V_210 , V_130 , V_218 , V_130 , & V_214 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_86 != V_214 . V_219 )
return - V_13 ;
for ( V_79 = 0 ; V_79 < V_86 ; V_79 ++ )
V_106 [ V_79 ] . V_107 = V_214 . V_215 [ V_79 ] . V_216 ;
if ( V_214 . V_215 [ 0 ] . V_216 > V_220 ) {
F_66 ( V_210 -> V_221 , L_8 ,
V_214 . V_215 [ 0 ] . V_216 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_112 ( struct V_116 * V_116 , void * V_222 ,
struct V_89 * V_53 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
F_113 ( & V_2 -> V_5 . V_8 -> V_17 , V_53 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_89 * V_53 , bool V_212 ,
struct V_94 * * V_223 ,
struct V_94 * * V_224 )
{
struct V_91 * V_225 = & V_53 -> V_12 . V_96 ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_117 -> V_40 ;
struct V_7 * V_8 = V_117 -> V_8 ;
unsigned int V_100 = 0 , V_101 = 0 ;
int V_9 = 0 ;
if ( F_115 ( V_225 -> V_97 ) ) {
F_92 ( V_8 , & V_225 -> V_100 , & V_225 -> V_101 ,
NULL , & V_225 -> V_97 ,
V_209 ) ;
if ( V_212 ) {
V_100 = V_225 -> V_100 ;
V_101 = V_225 -> V_101 ;
} else {
V_8 -> V_11 . V_102 = V_225 -> V_100 ;
V_8 -> V_11 . V_103 = V_225 -> V_101 ;
}
}
* V_224 = F_92 ( V_8 , & V_225 -> V_100 , & V_225 -> V_101 ,
NULL , & V_225 -> V_97 ,
V_145 ) ;
if ( * V_224 == NULL )
return - V_13 ;
if ( V_212 && F_115 ( V_225 -> V_97 ) ) {
V_225 -> V_100 = V_100 ;
V_225 -> V_101 = V_101 ;
}
if ( ! V_117 -> V_125 ) {
struct V_191 V_226 ;
struct V_191 * V_199 ;
V_199 = V_212 ? & V_226 : & V_2 -> V_5 . V_227 ;
V_199 -> V_128 = ( * V_224 ) -> V_146 ;
V_199 -> V_100 = V_225 -> V_100 ;
V_199 -> V_101 = V_225 -> V_101 ;
F_82 ( V_40 ) ;
V_9 = F_109 ( V_8 , V_199 , V_223 , V_212 ) ;
F_85 ( V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
V_225 -> V_100 = V_199 -> V_100 ;
V_225 -> V_101 = V_199 -> V_101 ;
}
F_116 ( * V_224 , V_225 -> V_100 , V_225 -> V_101 , V_225 ) ;
if ( ( * V_224 ) -> V_10 & V_228 ) {
struct V_48 * V_210 ;
F_82 ( V_40 ) ;
V_210 = F_117 ( V_40 -> V_47 , V_196 ) ;
if ( V_210 )
F_111 ( V_210 , V_225 -> V_106 ,
( * V_224 ) -> V_104 , V_212 ) ;
else
V_9 = - V_229 ;
F_85 ( V_40 ) ;
}
return V_9 ;
}
static int F_118 ( struct V_116 * V_116 , void * V_222 ,
struct V_89 * V_53 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_94 * V_224 = NULL , * V_223 = NULL ;
return F_114 ( V_2 , V_53 , true , & V_223 , & V_224 ) ;
}
static void F_119 ( struct V_7 * V_8 ,
enum V_230 V_108 )
{
bool V_231 = F_62 ( V_108 ) ;
V_8 -> V_232 . V_233 = ! V_231 ;
F_120 ( V_8 , ! V_231 ) ;
if ( V_231 )
F_32 ( V_234 , & V_8 -> V_1 -> V_21 ) ;
else
F_20 ( V_234 , & V_8 -> V_1 -> V_21 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_89 * V_53 )
{
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_7 * V_8 = V_117 -> V_8 ;
struct V_91 * V_225 = & V_53 -> V_12 . V_96 ;
struct V_52 * V_235 = & V_8 -> V_17 ;
struct V_94 * V_223 = NULL ;
int V_9 , V_79 ;
if ( F_122 ( & V_2 -> V_5 . V_115 ) )
return - V_118 ;
V_9 = F_114 ( V_2 , V_53 , false , & V_223 , & V_235 -> V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
F_123 ( V_8 ) ;
for ( V_79 = 0 ; V_79 < V_235 -> V_12 -> V_104 ; V_79 ++ ) {
V_235 -> V_236 [ V_79 ] = V_225 -> V_106 [ V_79 ] . V_236 ;
V_235 -> V_66 [ V_79 ] = V_225 -> V_106 [ V_79 ] . V_107 ;
}
F_124 ( V_235 , V_225 -> V_100 , V_225 -> V_101 ) ;
if ( ! ( V_8 -> V_21 & V_155 ) )
F_125 ( V_235 , 0 , 0 , V_225 -> V_100 , V_225 -> V_101 ) ;
F_119 ( V_8 , V_235 -> V_12 -> V_108 ) ;
if ( ! V_117 -> V_125 ) {
V_8 -> V_11 . V_12 = V_223 ;
F_124 ( & V_8 -> V_11 , V_225 -> V_100 , V_225 -> V_101 ) ;
F_125 ( & V_8 -> V_11 , 0 , 0 , V_225 -> V_100 , V_225 -> V_101 ) ;
}
return V_9 ;
}
static int F_126 ( struct V_116 * V_116 , void * V_177 ,
struct V_89 * V_53 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
return F_121 ( V_2 , V_53 ) ;
}
static int F_127 ( struct V_116 * V_116 , void * V_177 ,
struct V_237 * V_79 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_78 * V_40 = & V_2 -> V_5 . V_40 ;
struct V_48 * V_195 ;
if ( V_79 -> V_61 != 0 )
return - V_13 ;
V_79 -> type = V_238 ;
F_82 ( V_40 ) ;
V_195 = F_117 ( V_40 -> V_47 , V_196 ) ;
F_85 ( V_40 ) ;
if ( V_195 )
F_128 ( V_79 -> V_183 , V_195 -> V_183 , sizeof( V_79 -> V_183 ) ) ;
return 0 ;
}
static int F_129 ( struct V_116 * V_116 , void * V_177 , unsigned int V_79 )
{
return V_79 == 0 ? V_79 : - V_13 ;
}
static int F_130 ( struct V_116 * V_116 , void * V_177 , unsigned int * V_79 )
{
* V_79 = 0 ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_197 V_239 , V_240 ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_48 * V_195 = & V_117 -> V_205 ;
struct V_45 * V_46 = F_38 ( V_117 -> V_40 . V_47 ) ;
struct V_188 * V_241 , * V_242 ;
int V_79 , V_9 ;
while ( 1 ) {
V_242 = NULL ;
for ( V_79 = 0 ; V_79 < V_195 -> V_82 . V_208 ; V_79 ++ ) {
struct V_188 * V_46 = & V_195 -> V_82 . V_189 [ V_79 ] ;
if ( V_46 -> V_10 & V_207 ) {
V_241 = V_46 ;
V_242 = F_108 ( V_241 ) ;
if ( V_242 )
break;
}
}
if ( V_242 == NULL ||
F_132 ( V_242 -> V_82 ) != V_243 )
break;
if ( V_195 == & V_117 -> V_205 ) {
struct V_52 * V_235 = & V_117 -> V_8 -> V_11 ;
V_239 . V_200 . V_100 = V_235 -> V_102 ;
V_239 . V_200 . V_101 = V_235 -> V_103 ;
V_239 . V_200 . V_128 = V_235 -> V_12 ? V_235 -> V_12 -> V_146 : 0 ;
} else {
V_239 . V_130 = V_241 -> V_61 ;
V_239 . V_202 = V_203 ;
V_9 = F_49 ( V_195 , V_130 , V_244 , NULL , & V_239 ) ;
if ( V_9 < 0 && V_9 != - V_245 )
return - V_229 ;
}
V_195 = F_110 ( V_242 -> V_82 ) ;
V_240 . V_130 = V_242 -> V_61 ;
V_240 . V_202 = V_203 ;
V_9 = F_49 ( V_195 , V_130 , V_244 , NULL , & V_240 ) ;
if ( V_9 < 0 && V_9 != - V_245 )
return - V_229 ;
if ( V_240 . V_200 . V_100 != V_239 . V_200 . V_100 ||
V_240 . V_200 . V_101 != V_239 . V_200 . V_101 ||
V_240 . V_200 . V_128 != V_239 . V_200 . V_128 )
return - V_229 ;
if ( V_195 == V_46 -> V_50 [ V_196 ] &&
F_133 ( V_240 . V_200 . V_128 ) ) {
struct V_211 V_106 [ V_246 ] ;
struct V_52 * V_93 = & V_117 -> V_8 -> V_17 ;
unsigned int V_79 ;
V_9 = F_111 ( V_195 , V_106 ,
V_93 -> V_12 -> V_104 ,
false ) ;
if ( V_9 < 0 )
return - V_229 ;
for ( V_79 = 0 ; V_79 < V_93 -> V_12 -> V_104 ; V_79 ++ )
if ( V_93 -> V_66 [ V_79 ] < V_106 [ V_79 ] . V_107 )
return - V_229 ;
}
}
return 0 ;
}
static int F_134 ( struct V_116 * V_116 , void * V_177 ,
enum V_247 type )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_186 * V_82 = & V_117 -> V_40 . V_81 . V_82 ;
struct V_3 * V_4 = NULL ;
struct V_48 * V_195 ;
int V_9 ;
if ( F_31 ( V_2 ) )
return - V_118 ;
V_9 = F_135 ( V_82 , & V_117 -> V_40 . V_47 -> V_248 ) ;
if ( V_9 < 0 )
return V_9 ;
V_195 = F_117 ( V_117 -> V_40 . V_47 , V_196 ) ;
if ( V_195 )
V_4 = F_136 ( V_195 ) ;
if ( V_4 == NULL ) {
V_9 = - V_229 ;
goto V_249;
}
V_117 -> V_6 = * V_4 ;
if ( V_117 -> V_250 == V_251 )
V_117 -> V_6 . V_14 = V_15 ;
if ( V_117 -> V_125 ) {
V_9 = F_131 ( V_2 ) ;
if ( V_9 < 0 )
goto V_249;
}
V_9 = F_137 ( V_116 , V_177 , type ) ;
if ( ! V_9 ) {
V_117 -> V_27 = true ;
return V_9 ;
}
V_249:
F_90 ( V_82 ) ;
return V_9 ;
}
static int F_138 ( struct V_116 * V_116 , void * V_177 ,
enum V_247 type )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_23 * V_117 = & V_2 -> V_5 ;
int V_9 ;
V_9 = F_139 ( V_116 , V_177 , type ) ;
if ( V_9 < 0 )
return V_9 ;
F_90 ( & V_117 -> V_40 . V_81 . V_82 ) ;
V_117 -> V_27 = false ;
return 0 ;
}
static int F_140 ( struct V_116 * V_116 , void * V_177 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
int V_9 ;
V_9 = F_141 ( V_116 , V_177 , V_253 ) ;
if ( ! V_9 )
V_2 -> V_5 . V_76 = V_253 -> V_73 ;
return V_9 ;
}
static int F_142 ( struct V_116 * V_116 , void * V_222 ,
struct V_254 * V_255 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
if ( V_255 -> type != V_256 )
return - V_13 ;
switch ( V_255 -> V_162 ) {
case V_257 :
case V_258 :
V_53 = & V_8 -> V_17 ;
case V_259 :
case V_260 :
V_255 -> V_161 . V_170 = 0 ;
V_255 -> V_161 . V_171 = 0 ;
V_255 -> V_161 . V_100 = V_53 -> V_261 ;
V_255 -> V_161 . V_101 = V_53 -> V_262 ;
return 0 ;
case V_172 :
V_53 = & V_8 -> V_17 ;
case V_263 :
V_255 -> V_161 . V_170 = V_53 -> V_156 ;
V_255 -> V_161 . V_171 = V_53 -> V_157 ;
V_255 -> V_161 . V_100 = V_53 -> V_100 ;
V_255 -> V_161 . V_101 = V_53 -> V_101 ;
return 0 ;
}
return - V_13 ;
}
static int F_143 ( struct V_160 * V_264 , struct V_160 * V_265 )
{
if ( V_264 -> V_170 < V_265 -> V_170 || V_264 -> V_171 < V_265 -> V_171 )
return 0 ;
if ( V_264 -> V_170 + V_264 -> V_100 > V_265 -> V_170 + V_265 -> V_100 )
return 0 ;
if ( V_264 -> V_171 + V_264 -> V_101 > V_265 -> V_171 + V_265 -> V_101 )
return 0 ;
return 1 ;
}
static int F_144 ( struct V_116 * V_116 , void * V_222 ,
struct V_254 * V_255 )
{
struct V_1 * V_2 = F_74 ( V_116 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_160 V_266 = V_255 -> V_161 ;
struct V_52 * V_53 ;
unsigned long V_10 ;
if ( V_255 -> type != V_256 )
return - V_13 ;
if ( V_255 -> V_162 == V_172 )
V_53 = & V_8 -> V_17 ;
else if ( V_255 -> V_162 == V_263 )
V_53 = & V_8 -> V_11 ;
else
return - V_13 ;
F_98 ( V_8 , & V_266 , V_255 -> V_162 ) ;
if ( V_255 -> V_10 & V_267 &&
! F_143 ( & V_266 , & V_255 -> V_161 ) )
return - V_268 ;
if ( V_255 -> V_10 & V_269 &&
! F_143 ( & V_255 -> V_161 , & V_266 ) )
return - V_268 ;
V_255 -> V_161 = V_266 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_125 ( V_53 , V_255 -> V_161 . V_170 , V_255 -> V_161 . V_171 , V_255 -> V_161 . V_100 ,
V_255 -> V_161 . V_101 ) ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
F_32 ( V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
static int F_145 ( struct V_186 * V_82 ,
const struct V_188 * V_270 ,
const struct V_188 * V_271 , V_109 V_10 )
{
struct V_48 * V_195 = F_110 ( V_82 ) ;
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_48 * V_210 ;
if ( F_132 ( V_271 -> V_82 ) != V_243 )
return - V_13 ;
if ( F_93 ( V_2 == NULL ) )
return 0 ;
F_44 ( L_9 ,
V_270 -> V_82 -> V_183 , V_271 -> V_82 -> V_183 , V_10 ,
V_2 -> V_5 . V_250 ) ;
if ( ! ( V_10 & V_272 ) ) {
V_2 -> V_5 . V_250 = 0 ;
return 0 ;
}
if ( V_117 -> V_250 != 0 )
return - V_118 ;
V_117 -> V_250 = V_195 -> V_273 ;
if ( V_117 -> V_125 || V_117 -> V_126 )
return 0 ;
V_210 = F_147 ( & V_117 -> V_205 . V_82 ) ;
if ( V_210 == NULL )
return 0 ;
return F_148 ( & V_117 -> V_8 -> V_274 . V_275 ,
V_210 -> V_276 , NULL ) ;
}
void F_149 ( struct V_48 * V_195 , unsigned int V_277 ,
void * V_278 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 ;
struct V_279 * V_280 ;
struct V_1 * V_2 ;
unsigned long V_10 ;
if ( V_195 == NULL )
return;
V_4 = F_136 ( V_195 ) ;
V_280 = F_150 ( & V_195 -> V_82 ) ;
F_3 ( & V_280 -> V_16 , V_10 ) ;
V_2 = V_4 ? F_151 ( V_4 ) -> V_281 : NULL ;
if ( V_2 && V_278 && V_277 == V_282 &&
F_35 ( V_33 , & V_2 -> V_21 ) ) {
unsigned long V_283 ;
F_3 ( & V_2 -> V_16 , V_283 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_38 ) ) {
V_26 = F_152 ( V_2 -> V_5 . V_38 . V_284 ,
struct V_25 , V_285 ) ;
F_67 ( & V_26 -> V_35 . V_36 , 0 ,
* ( ( V_109 * ) V_278 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_16 , V_283 ) ;
}
F_21 ( & V_280 -> V_16 , V_10 ) ;
}
static int F_153 ( struct V_48 * V_195 ,
struct V_286 * V_287 ,
struct V_288 * V_128 )
{
struct V_94 * V_12 ;
V_12 = F_60 ( NULL , NULL , V_98 , V_128 -> V_61 ) ;
if ( ! V_12 )
return - V_13 ;
V_128 -> V_128 = V_12 -> V_146 ;
return 0 ;
}
static int F_154 ( struct V_48 * V_195 ,
struct V_286 * V_287 ,
struct V_197 * V_12 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_235 = & V_8 -> V_11 ;
struct V_191 * V_199 ;
if ( V_12 -> V_202 == V_204 ) {
V_199 = F_155 ( V_195 , V_287 , V_12 -> V_130 ) ;
V_12 -> V_200 = * V_199 ;
return 0 ;
}
V_199 = & V_12 -> V_200 ;
F_76 ( & V_2 -> V_120 ) ;
switch ( V_12 -> V_130 ) {
case V_145 :
if ( ! F_93 ( V_235 -> V_12 == NULL ) )
V_199 -> V_128 = V_235 -> V_12 -> V_146 ;
V_199 -> V_100 = V_235 -> V_100 ;
V_199 -> V_101 = V_235 -> V_101 ;
break;
case V_148 :
* V_199 = V_2 -> V_5 . V_289 ;
break;
case V_209 :
default:
* V_199 = V_2 -> V_5 . V_227 ;
break;
}
F_88 ( & V_2 -> V_120 ) ;
V_199 -> V_290 = V_291 ;
return 0 ;
}
static int F_156 ( struct V_48 * V_195 ,
struct V_286 * V_287 ,
struct V_197 * V_12 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_191 * V_199 = & V_12 -> V_200 ;
struct V_23 * V_117 = & V_2 -> V_5 ;
struct V_7 * V_8 = V_117 -> V_8 ;
struct V_52 * V_235 ;
struct V_94 * V_144 ;
F_44 ( L_10 ,
V_12 -> V_130 , V_199 -> V_128 , V_199 -> V_100 , V_199 -> V_101 ) ;
if ( V_12 -> V_130 == V_145 && F_122 ( & V_117 -> V_115 ) )
return - V_118 ;
F_76 ( & V_2 -> V_120 ) ;
V_144 = F_92 ( V_8 , & V_199 -> V_100 , & V_199 -> V_101 ,
& V_199 -> V_128 , NULL , V_12 -> V_130 ) ;
F_88 ( & V_2 -> V_120 ) ;
V_199 -> V_290 = V_291 ;
if ( V_12 -> V_202 == V_204 ) {
V_199 = F_155 ( V_195 , V_287 , V_12 -> V_130 ) ;
* V_199 = V_12 -> V_200 ;
return 0 ;
}
if ( F_93 ( V_144 == NULL ) )
return - V_13 ;
F_123 ( V_8 ) ;
F_119 ( V_8 , V_144 -> V_108 ) ;
if ( V_12 -> V_130 == V_145 ) {
V_235 = & V_8 -> V_17 ;
V_199 -> V_100 = V_8 -> V_11 . V_100 ;
V_199 -> V_101 = V_8 -> V_11 . V_101 ;
} else {
V_235 = & V_8 -> V_11 ;
}
F_76 ( & V_2 -> V_120 ) ;
F_124 ( V_235 , V_199 -> V_100 , V_199 -> V_101 ) ;
if ( V_12 -> V_130 == V_148 )
V_117 -> V_289 = * V_199 ;
else if ( V_12 -> V_130 == V_209 )
V_117 -> V_227 = * V_199 ;
V_235 -> V_12 = V_144 ;
if ( ! ( V_12 -> V_130 == V_145 && ( V_8 -> V_21 & V_155 ) ) )
F_125 ( V_235 , 0 , 0 , V_199 -> V_100 , V_199 -> V_101 ) ;
if ( V_12 -> V_130 != V_145 )
V_8 -> V_21 &= ~ V_155 ;
F_88 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_157 ( struct V_48 * V_195 ,
struct V_286 * V_287 ,
struct V_292 * V_293 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
struct V_160 * V_161 = & V_293 -> V_161 ;
struct V_160 * V_294 ;
if ( V_293 -> V_130 == V_145 )
return - V_13 ;
F_76 ( & V_2 -> V_120 ) ;
switch ( V_293 -> V_162 ) {
case V_258 :
V_53 = & V_8 -> V_17 ;
case V_259 :
V_161 -> V_100 = V_53 -> V_261 ;
V_161 -> V_101 = V_53 -> V_262 ;
V_161 -> V_170 = 0 ;
V_161 -> V_171 = 0 ;
F_88 ( & V_2 -> V_120 ) ;
return 0 ;
case V_263 :
V_294 = F_158 ( V_195 , V_287 , V_293 -> V_130 ) ;
break;
case V_172 :
V_294 = F_159 ( V_195 , V_287 , V_293 -> V_130 ) ;
V_53 = & V_8 -> V_17 ;
break;
default:
F_88 ( & V_2 -> V_120 ) ;
return - V_13 ;
}
if ( V_293 -> V_202 == V_204 ) {
V_293 -> V_161 = * V_294 ;
} else {
V_161 -> V_170 = V_53 -> V_156 ;
V_161 -> V_171 = V_53 -> V_157 ;
V_161 -> V_100 = V_53 -> V_100 ;
V_161 -> V_101 = V_53 -> V_101 ;
}
F_44 ( L_11 ,
V_293 -> V_130 , V_161 -> V_170 , V_161 -> V_171 , V_161 -> V_100 , V_161 -> V_101 ,
V_53 -> V_102 , V_53 -> V_103 ) ;
F_88 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_160 ( struct V_48 * V_195 ,
struct V_286 * V_287 ,
struct V_292 * V_293 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
struct V_160 * V_161 = & V_293 -> V_161 ;
struct V_160 * V_294 ;
unsigned long V_10 ;
if ( V_293 -> V_130 == V_145 )
return - V_13 ;
F_76 ( & V_2 -> V_120 ) ;
F_98 ( V_8 , V_161 , V_263 ) ;
switch ( V_293 -> V_162 ) {
case V_263 :
V_294 = F_158 ( V_195 , V_287 , V_293 -> V_130 ) ;
break;
case V_172 :
V_294 = F_159 ( V_195 , V_287 , V_293 -> V_130 ) ;
V_53 = & V_8 -> V_17 ;
break;
default:
F_88 ( & V_2 -> V_120 ) ;
return - V_13 ;
}
if ( V_293 -> V_202 == V_204 ) {
* V_294 = V_293 -> V_161 ;
} else {
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_125 ( V_53 , V_161 -> V_170 , V_161 -> V_171 , V_161 -> V_100 , V_161 -> V_101 ) ;
F_32 ( V_20 , & V_2 -> V_21 ) ;
if ( V_293 -> V_162 == V_172 )
V_8 -> V_21 |= V_155 ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
}
F_44 ( L_12 , V_293 -> V_162 , V_161 -> V_170 , V_161 -> V_171 ,
V_161 -> V_100 , V_161 -> V_101 ) ;
F_88 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_89 V_12 = {
. type = V_256 ,
. V_12 . V_96 = {
. V_100 = V_295 ,
. V_101 = V_296 ,
. V_97 = V_297 ,
. V_298 = V_299 ,
. V_290 = V_291 ,
} ,
} ;
return F_121 ( V_2 , & V_12 ) ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_300 * V_221 )
{
struct V_301 * V_302 = & V_2 -> V_5 . V_40 . V_81 ;
struct V_71 * V_72 = & V_2 -> V_5 . V_115 ;
struct V_7 * V_8 ;
struct V_23 * V_5 ;
struct V_94 * V_12 ;
int V_9 = - V_303 ;
V_8 = F_162 ( sizeof( * V_8 ) , V_304 ) ;
if ( ! V_8 )
return - V_303 ;
V_8 -> V_1 = V_2 ;
V_8 -> V_305 = V_306 ;
V_8 -> V_307 = V_308 ;
V_8 -> V_21 = V_309 ;
V_8 -> V_11 . V_12 = F_60 ( NULL , NULL , V_98 , 0 ) ;
V_8 -> V_17 . V_12 = V_8 -> V_11 . V_12 ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
snprintf ( V_302 -> V_183 , sizeof( V_302 -> V_183 ) , L_13 , V_2 -> V_310 ) ;
V_302 -> V_311 = & V_312 ;
V_302 -> V_313 = & V_314 ;
V_302 -> V_221 = V_221 ;
V_302 -> V_315 = - 1 ;
V_302 -> V_316 = V_317 ;
V_302 -> V_318 = V_72 ;
V_302 -> V_120 = & V_2 -> V_120 ;
F_163 ( V_302 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_70 = 0 ;
V_5 -> V_76 = 0 ;
V_5 -> V_8 = V_8 ;
F_57 ( & V_5 -> V_34 ) ;
F_57 ( & V_5 -> V_38 ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> type = V_256 ;
V_72 -> V_319 = V_320 | V_321 | V_322 ;
V_72 -> V_74 = V_8 ;
V_72 -> V_323 = & V_324 ;
V_72 -> V_325 = & V_326 ;
V_72 -> V_327 = sizeof( struct V_25 ) ;
V_72 -> V_328 = V_329 ;
V_72 -> V_120 = & V_2 -> V_120 ;
V_9 = F_164 ( V_72 ) ;
if ( V_9 )
goto V_330;
V_12 = F_60 ( NULL , NULL , V_98 , 0 ) ;
V_5 -> V_227 . V_100 = V_295 ;
V_5 -> V_227 . V_101 = V_296 ;
V_5 -> V_227 . V_128 = V_12 -> V_146 ;
V_8 -> V_11 . V_100 = V_295 ;
V_8 -> V_11 . V_101 = V_296 ;
V_8 -> V_11 . V_12 = V_12 ;
V_12 = F_60 ( NULL , NULL , V_149 , 0 ) ;
V_5 -> V_289 = V_5 -> V_227 ;
V_5 -> V_289 . V_128 = V_12 -> V_146 ;
V_5 -> V_331 . V_10 = V_207 ;
V_9 = F_165 ( & V_302 -> V_82 , 1 , & V_5 -> V_331 , 0 ) ;
if ( V_9 )
goto V_330;
V_9 = F_84 ( V_8 ) ;
if ( V_9 )
goto V_332;
V_9 = F_166 ( V_302 , V_333 , - 1 ) ;
if ( V_9 )
goto V_334;
F_167 ( V_221 , L_14 ,
V_302 -> V_183 , F_168 ( V_302 ) ) ;
V_302 -> V_276 = & V_8 -> V_274 . V_275 ;
return 0 ;
V_334:
F_83 ( V_8 ) ;
V_332:
F_169 ( & V_302 -> V_82 ) ;
V_330:
F_170 ( V_8 ) ;
return V_9 ;
}
static int F_171 ( struct V_48 * V_195 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
int V_9 ;
if ( V_2 == NULL )
return - V_335 ;
V_9 = F_172 ( V_2 , V_195 -> V_221 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_5 . V_40 . V_47 = F_136 ( V_195 ) ;
V_9 = F_161 ( V_2 , V_195 -> V_221 ) ;
if ( V_9 ) {
F_173 ( V_2 ) ;
V_2 -> V_5 . V_40 . V_47 = NULL ;
}
return V_9 ;
}
static void F_174 ( struct V_48 * V_195 )
{
struct V_1 * V_2 = F_146 ( V_195 ) ;
struct V_301 * V_81 ;
if ( V_2 == NULL )
return;
F_76 ( & V_2 -> V_120 ) ;
F_173 ( V_2 ) ;
V_81 = & V_2 -> V_5 . V_40 . V_81 ;
if ( F_175 ( V_81 ) ) {
F_176 ( V_81 ) ;
F_169 ( & V_81 -> V_82 ) ;
F_83 ( V_2 -> V_5 . V_8 ) ;
V_2 -> V_5 . V_40 . V_47 = NULL ;
}
F_170 ( V_2 -> V_5 . V_8 ) ;
V_2 -> V_5 . V_8 = NULL ;
F_88 ( & V_2 -> V_120 ) ;
}
int F_177 ( struct V_1 * V_2 )
{
struct V_48 * V_195 = & V_2 -> V_5 . V_205 ;
int V_9 ;
F_178 ( V_195 , & V_336 ) ;
V_195 -> V_10 |= V_337 ;
snprintf ( V_195 -> V_183 , sizeof( V_195 -> V_183 ) , L_15 , V_2 -> V_310 ) ;
V_2 -> V_5 . V_338 [ V_209 ] . V_10 = V_207 ;
V_2 -> V_5 . V_338 [ V_148 ] . V_10 = V_207 ;
V_2 -> V_5 . V_338 [ V_145 ] . V_10 = V_190 ;
V_9 = F_165 ( & V_195 -> V_82 , V_339 ,
V_2 -> V_5 . V_338 , 0 ) ;
if ( V_9 )
return V_9 ;
V_195 -> V_82 . V_323 = & V_340 ;
V_195 -> V_341 = & V_342 ;
F_179 ( V_195 , V_2 ) ;
return 0 ;
}
void F_180 ( struct V_1 * V_2 )
{
struct V_48 * V_195 = & V_2 -> V_5 . V_205 ;
F_181 ( V_195 ) ;
F_169 ( & V_195 -> V_82 ) ;
F_179 ( V_195 , NULL ) ;
}
