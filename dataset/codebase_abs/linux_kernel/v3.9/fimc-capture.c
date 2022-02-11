static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
int V_12 = 0 ;
if ( V_7 -> V_13 [ V_14 ] == NULL || V_4 == NULL )
return - V_15 ;
if ( V_4 -> V_16 . V_17 == NULL )
return - V_18 ;
V_10 = F_2 ( V_7 -> V_13 [ V_14 ] ) ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_4 ( V_4 , & V_4 -> V_20 ) ;
F_5 ( V_4 ) ;
F_6 ( V_2 , & V_10 -> V_21 ) ;
F_7 ( V_2 , & V_10 -> V_21 ) ;
F_8 ( V_2 , & V_10 -> V_21 ) ;
F_9 ( V_2 , & V_4 -> V_16 ) ;
V_12 = F_10 ( V_4 ) ;
if ( ! V_12 ) {
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
if ( V_2 -> V_22 -> V_23 )
F_19 ( V_4 ) ;
F_20 ( V_24 , & V_2 -> V_25 ) ;
}
F_21 ( & V_2 -> V_19 , V_11 ) ;
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 , bool V_26 )
{
struct V_27 * V_28 = & V_2 -> V_5 ;
struct V_29 * V_30 ;
unsigned long V_11 ;
bool V_31 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
V_31 = V_2 -> V_25 & ( 1 << V_32 ) ;
V_2 -> V_25 &= ~ ( 1 << V_33 | 1 << V_34 |
1 << V_35 | 1 << V_32 ) ;
if ( V_26 )
V_2 -> V_25 |= ( 1 << V_36 ) ;
else
V_2 -> V_25 &= ~ ( 1 << V_37 | 1 << V_36 ) ;
while ( ! V_26 && ! F_23 ( & V_28 -> V_38 ) ) {
V_30 = F_24 ( V_28 ) ;
F_25 ( & V_30 -> V_39 , V_40 ) ;
}
while ( ! F_23 ( & V_28 -> V_41 ) ) {
V_30 = F_26 ( V_28 ) ;
if ( V_26 )
F_27 ( V_28 , V_30 ) ;
else
F_25 ( & V_30 -> V_39 , V_40 ) ;
}
F_28 ( V_2 ) ;
V_28 -> V_42 = 0 ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( V_31 )
return F_29 ( V_2 , V_43 ,
& V_2 -> V_8 , 0 ) ;
else
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , bool V_26 )
{
unsigned long V_11 ;
if ( ! F_31 ( V_2 ) )
return 0 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_32 ( V_34 , & V_2 -> V_25 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
F_34 ( V_2 -> V_44 ,
! F_35 ( V_34 , & V_2 -> V_25 ) ,
( 2 * V_45 / 10 ) ) ;
return F_22 ( V_2 , V_26 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
int V_12 ;
F_9 ( V_2 , & V_4 -> V_16 ) ;
V_12 = F_10 ( V_4 ) ;
if ( V_12 )
return V_12 ;
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
F_4 ( V_4 , & V_4 -> V_20 ) ;
F_18 ( V_4 ) ;
if ( V_2 -> V_22 -> V_23 )
F_19 ( V_4 ) ;
F_20 ( V_24 , & V_2 -> V_25 ) ;
return V_12 ;
}
void F_37 ( struct V_1 * V_2 , int V_46 )
{
struct V_47 * V_48 = V_2 -> V_8 . V_13 [ V_49 ] ;
struct V_27 * V_28 = & V_2 -> V_5 ;
struct V_50 * V_51 = & V_28 -> V_4 -> V_20 ;
struct V_29 * V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
if ( F_38 ( V_34 , & V_2 -> V_25 ) ) {
F_39 ( & V_2 -> V_44 ) ;
goto V_57;
}
if ( ! F_23 ( & V_28 -> V_41 ) &&
F_35 ( V_33 , & V_2 -> V_25 ) && V_46 ) {
F_40 ( & V_56 ) ;
V_52 = F_26 ( V_28 ) ;
V_54 = & V_52 -> V_39 . V_58 . V_59 ;
V_54 -> V_60 = V_56 . V_60 ;
V_54 -> V_61 = V_56 . V_62 / V_63 ;
V_52 -> V_39 . V_58 . V_64 = V_28 -> V_65 ++ ;
F_25 ( & V_52 -> V_39 , V_66 ) ;
}
if ( ! F_23 ( & V_28 -> V_38 ) ) {
V_52 = F_24 ( V_28 ) ;
F_41 ( V_2 , & V_52 -> V_67 , V_28 -> V_42 ) ;
V_52 -> V_68 = V_28 -> V_42 ;
F_42 ( V_28 , V_52 ) ;
F_43 ( L_1 ,
F_44 ( V_2 ) , V_52 -> V_68 ) ;
if ( ++ V_28 -> V_42 >= V_69 )
V_28 -> V_42 = 0 ;
}
if ( V_51 -> V_17 -> V_70 && ! F_23 ( & V_28 -> V_41 ) ) {
unsigned int V_71 = F_45 ( V_51 -> V_17 -> V_70 ) - 1 ;
unsigned int V_72 = V_51 -> V_73 [ V_71 ] ;
T_1 V_68 = F_44 ( V_2 ) ;
void * V_74 ;
F_46 (v_buf, &cap->active_buf_q, list) {
if ( V_52 -> V_68 != V_68 )
continue;
V_74 = F_47 ( & V_52 -> V_39 , V_71 ) ;
F_48 ( V_48 , V_75 , V_76 ,
V_74 , & V_72 ) ;
break;
}
}
if ( V_28 -> V_77 == 0 ) {
if ( V_46 )
F_20 ( V_33 , & V_2 -> V_25 ) ;
if ( ++ V_28 -> V_42 >= V_69 )
V_28 -> V_42 = 0 ;
} else {
F_32 ( V_33 , & V_2 -> V_25 ) ;
}
if ( F_35 ( V_24 , & V_2 -> V_25 ) )
F_36 ( V_28 -> V_4 ) ;
V_57:
if ( V_28 -> V_77 == 1 ) {
F_33 ( V_2 ) ;
F_20 ( V_35 , & V_2 -> V_25 ) ;
}
F_43 ( L_2 ,
F_44 ( V_2 ) , V_28 -> V_77 ) ;
}
static int F_49 ( struct V_78 * V_79 , unsigned int V_80 )
{
struct V_3 * V_4 = V_79 -> V_81 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
int V_82 ;
int V_12 ;
V_5 -> V_65 = 0 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_22 ( V_2 , false ) ;
return V_12 ;
}
F_32 ( V_37 , & V_2 -> V_25 ) ;
V_82 = V_2 -> V_5 . V_83 > 1 ? 2 : 1 ;
if ( V_5 -> V_77 >= V_82 &&
! F_50 ( V_35 , & V_2 -> V_25 ) ) {
F_51 ( V_4 ) ;
if ( ! F_50 ( V_32 , & V_2 -> V_25 ) )
F_29 ( V_2 , V_43 ,
& V_2 -> V_8 , 1 ) ;
}
return 0 ;
}
static int F_52 ( struct V_78 * V_79 )
{
struct V_3 * V_4 = V_79 -> V_81 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_31 ( V_2 ) )
return - V_18 ;
return F_30 ( V_2 , false ) ;
}
int F_53 ( struct V_1 * V_2 )
{
bool V_26 = F_54 ( V_2 ) ;
int V_12 = F_30 ( V_2 , V_26 ) ;
if ( V_12 )
return V_12 ;
return F_29 ( V_2 , V_84 , & V_2 -> V_8 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_29 * V_30 ;
int V_85 ;
if ( ! F_38 ( V_36 , & V_2 -> V_25 ) )
return 0 ;
F_56 ( & V_2 -> V_5 . V_41 ) ;
V_5 -> V_42 = 0 ;
F_29 ( V_2 , V_86 , & V_2 -> V_8 ,
& V_5 -> V_87 . V_88 , false ) ;
F_1 ( V_2 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
for ( V_85 = 0 ; V_85 < V_5 -> V_83 ; V_85 ++ ) {
if ( F_23 ( & V_5 -> V_38 ) )
break;
V_30 = F_24 ( V_5 ) ;
F_57 ( & V_30 -> V_39 ) ;
}
return 0 ;
}
static int F_58 ( struct V_78 * V_89 , const struct V_90 * V_91 ,
unsigned int * V_92 , unsigned int * V_93 ,
unsigned int V_94 [] , void * V_95 [] )
{
const struct V_96 * V_97 = NULL ;
struct V_3 * V_4 = V_89 -> V_81 ;
struct V_50 * V_98 = & V_4 -> V_20 ;
struct V_99 * V_17 = V_98 -> V_17 ;
unsigned long V_100 ;
int V_85 ;
if ( V_91 ) {
V_97 = & V_91 -> V_17 . V_101 ;
V_17 = F_59 ( & V_97 -> V_102 , NULL ,
V_103 | V_104 , - 1 ) ;
V_100 = V_97 -> V_105 * V_97 -> V_106 ;
} else {
V_100 = V_98 -> V_107 * V_98 -> V_108 ;
}
if ( V_17 == NULL )
return - V_18 ;
* V_93 = V_17 -> V_109 ;
for ( V_85 = 0 ; V_85 < V_17 -> V_109 ; V_85 ++ ) {
unsigned int V_72 = ( V_100 * V_17 -> V_110 [ V_85 ] ) / 8 ;
if ( V_97 )
V_94 [ V_85 ] = F_60 ( V_72 , V_97 -> V_111 [ V_85 ] . V_112 ) ;
else if ( F_61 ( V_17 -> V_113 ) )
V_94 [ V_85 ] = V_98 -> V_73 [ V_85 ] ;
else
V_94 [ V_85 ] = F_62 ( V_114 , V_72 , V_98 -> V_73 [ V_85 ] ) ;
V_95 [ V_85 ] = V_4 -> V_1 -> V_115 ;
}
return 0 ;
}
static int F_63 ( struct V_116 * V_39 )
{
struct V_78 * V_89 = V_39 -> V_78 ;
struct V_3 * V_4 = V_89 -> V_81 ;
int V_85 ;
if ( V_4 -> V_20 . V_17 == NULL )
return - V_18 ;
for ( V_85 = 0 ; V_85 < V_4 -> V_20 . V_17 -> V_109 ; V_85 ++ ) {
unsigned long V_72 = V_4 -> V_20 . V_73 [ V_85 ] ;
if ( F_64 ( V_39 , V_85 ) < V_72 ) {
F_65 ( & V_4 -> V_1 -> V_5 . V_87 ,
L_3 ,
F_64 ( V_39 , V_85 ) , V_72 ) ;
return - V_18 ;
}
F_66 ( V_39 , V_85 , V_72 ) ;
}
return 0 ;
}
static void F_57 ( struct V_116 * V_39 )
{
struct V_29 * V_30
= F_67 ( V_39 , struct V_29 , V_39 ) ;
struct V_3 * V_4 = F_68 ( V_39 -> V_78 ) ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
unsigned long V_11 ;
int V_82 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_69 ( V_4 , & V_30 -> V_39 , & V_4 -> V_20 , & V_30 -> V_67 ) ;
if ( ! F_35 ( V_36 , & V_2 -> V_25 ) &&
! F_35 ( V_35 , & V_2 -> V_25 ) &&
V_5 -> V_77 < V_69 ) {
int V_117 = ( V_5 -> V_83 == 1 ) ? - 1 :
V_5 -> V_42 ;
F_41 ( V_2 , & V_30 -> V_67 , V_117 ) ;
V_30 -> V_68 = V_5 -> V_42 ;
F_42 ( V_5 , V_30 ) ;
if ( ++ V_5 -> V_42 >= V_69 )
V_5 -> V_42 = 0 ;
} else {
F_27 ( V_5 , V_30 ) ;
}
V_82 = V_5 -> V_83 > 1 ? 2 : 1 ;
if ( F_70 ( & V_5 -> V_118 ) &&
V_5 -> V_77 >= V_82 &&
! F_50 ( V_35 , & V_2 -> V_25 ) ) {
F_51 ( V_4 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( ! F_50 ( V_32 , & V_2 -> V_25 ) )
F_29 ( V_2 , V_43 ,
& V_2 -> V_8 , 1 ) ;
return;
}
F_21 ( & V_2 -> V_19 , V_11 ) ;
}
static void F_71 ( struct V_78 * V_89 )
{
struct V_3 * V_4 = F_68 ( V_89 ) ;
F_72 ( & V_4 -> V_1 -> V_119 ) ;
}
static void F_73 ( struct V_78 * V_89 )
{
struct V_3 * V_4 = F_68 ( V_89 ) ;
F_74 ( & V_4 -> V_1 -> V_119 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_47 * V_10 = V_2 -> V_8 . V_13 [ V_14 ] ;
int V_12 ;
if ( F_76 ( V_5 -> V_4 == NULL ) )
return - V_15 ;
if ( V_5 -> V_4 -> V_120 . V_121 )
return 0 ;
V_12 = F_77 ( V_5 -> V_4 ) ;
if ( V_12 || V_5 -> V_122 || ! V_10 ||
! V_5 -> V_4 -> V_120 . V_121 )
return V_12 ;
return F_78 ( & V_5 -> V_4 -> V_120 . V_123 ,
V_10 -> V_124 , NULL ) ;
}
static int F_79 ( struct V_125 * V_125 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 = - V_126 ;
F_43 ( L_4 , F_81 ( V_127 ) , V_2 -> V_25 ) ;
F_82 ( V_2 ) ;
F_72 ( & V_2 -> V_119 ) ;
if ( F_83 ( V_2 ) )
goto V_128;
F_32 ( V_129 , & V_2 -> V_25 ) ;
V_12 = F_84 ( & V_2 -> V_130 -> V_131 ) ;
if ( V_12 < 0 )
goto V_128;
V_12 = F_85 ( V_125 ) ;
if ( V_12 ) {
F_86 ( & V_2 -> V_130 -> V_131 ) ;
goto V_128;
}
if ( ++ V_2 -> V_5 . V_132 == 1 ) {
V_12 = F_29 ( V_2 , V_86 , & V_2 -> V_8 ,
& V_2 -> V_5 . V_87 . V_88 , true ) ;
if ( ! V_12 && ! V_2 -> V_5 . V_122 )
V_12 = F_87 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_75 ( V_2 ) ;
if ( V_12 < 0 ) {
F_20 ( V_129 , & V_2 -> V_25 ) ;
F_88 ( & V_2 -> V_130 -> V_131 ) ;
V_2 -> V_5 . V_132 -- ;
F_89 ( V_125 ) ;
}
}
V_128:
F_74 ( & V_2 -> V_119 ) ;
F_90 ( V_2 ) ;
return V_12 ;
}
static int F_91 ( struct V_125 * V_125 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
F_43 ( L_4 , F_81 ( V_127 ) , V_2 -> V_25 ) ;
F_72 ( & V_2 -> V_119 ) ;
if ( -- V_2 -> V_5 . V_132 == 0 ) {
F_20 ( V_129 , & V_2 -> V_25 ) ;
F_30 ( V_2 , false ) ;
F_29 ( V_2 , V_84 , & V_2 -> V_8 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
}
F_86 ( & V_2 -> V_130 -> V_131 ) ;
if ( V_2 -> V_5 . V_132 == 0 ) {
F_92 ( & V_2 -> V_5 . V_118 ) ;
F_93 ( V_2 -> V_5 . V_4 ) ;
}
V_12 = F_89 ( V_125 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static unsigned int F_94 ( struct V_125 * V_125 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
if ( F_95 ( & V_2 -> V_119 ) )
return V_135 ;
V_12 = F_96 ( & V_2 -> V_5 . V_118 , V_125 , V_134 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static int F_97 ( struct V_125 * V_125 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
if ( F_95 ( & V_2 -> V_119 ) )
return - V_138 ;
V_12 = F_98 ( & V_2 -> V_5 . V_118 , V_137 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static struct V_99 * F_99 ( struct V_3 * V_4 ,
V_114 * V_105 , V_114 * V_106 ,
V_114 * V_139 , V_114 * V_140 , int V_141 )
{
bool V_142 = V_4 -> V_142 == 90 || V_4 -> V_142 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
const struct V_143 * V_144 = V_2 -> V_22 ;
const struct V_145 * V_146 = V_144 -> V_147 ;
struct V_50 * V_148 = & V_4 -> V_20 ;
V_114 V_110 , V_149 , V_150 , V_151 , V_152 = 3 ;
V_114 V_153 = V_103 ;
struct V_99 * V_154 ;
if ( V_139 && V_4 -> V_16 . V_17 && V_141 == V_155 &&
F_61 ( V_4 -> V_16 . V_17 -> V_113 ) )
* V_139 = V_4 -> V_16 . V_17 -> V_156 ;
if ( V_140 && * V_140 != V_157 && V_141 != V_158 )
V_153 |= V_104 ;
V_154 = F_59 ( V_140 , V_139 , V_153 , 0 ) ;
if ( F_76 ( ! V_154 ) )
return NULL ;
if ( V_139 )
* V_139 = V_154 -> V_156 ;
if ( V_140 )
* V_140 = V_154 -> V_140 ;
if ( V_141 == V_158 ) {
V_150 = F_61 ( V_154 -> V_113 ) ?
V_146 -> V_159 : V_146 -> V_160 ;
F_100 ( V_105 , F_62 ( V_114 , * V_105 , 32 ) , V_150 , 4 ,
V_106 , F_62 ( V_114 , * V_106 , 32 ) ,
V_161 ,
F_61 ( V_154 -> V_113 ) ?
3 : 1 ,
0 ) ;
return V_154 ;
}
if ( F_61 ( V_154 -> V_113 ) ) {
* V_105 = V_4 -> V_16 . V_107 ;
* V_106 = V_4 -> V_16 . V_108 ;
return V_154 ;
}
V_150 = V_142 ? V_146 -> V_162 : V_146 -> V_163 ;
if ( V_4 -> V_25 & V_164 ) {
V_149 = V_148 -> V_165 + V_148 -> V_105 ;
V_151 = V_148 -> V_166 + V_148 -> V_106 ;
} else {
V_149 = V_144 -> V_167 ;
V_151 = V_144 -> V_167 ;
}
if ( V_144 -> V_168 == 1 && ! V_142 )
V_152 = F_101 ( V_154 -> V_113 ) ? 0 : 1 ;
V_110 = F_102 ( V_154 ) ;
F_100 ( V_105 , V_149 , V_150 ,
F_45 ( V_144 -> V_167 ) - 1 ,
V_106 , V_151 , V_161 ,
V_152 ,
64 / ( F_103 ( V_110 , 8 ) ) ) ;
F_43 ( L_5 ,
V_141 , V_139 ? * V_139 : 0 , * V_105 , * V_106 ,
V_148 -> V_107 , V_148 -> V_108 ) ;
return V_154 ;
}
static void F_104 ( struct V_3 * V_4 ,
struct V_169 * V_170 ,
int V_171 )
{
bool V_172 = V_4 -> V_142 == 90 || V_4 -> V_142 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
const struct V_143 * V_144 = V_2 -> V_22 ;
const struct V_145 * V_146 = V_144 -> V_147 ;
struct V_50 * V_173 = & V_4 -> V_16 ;
V_114 V_150 , V_174 , V_149 = 0 , V_151 = 0 , V_175 ;
V_114 V_176 = 0 , V_152 = 4 ;
V_114 V_177 , V_178 ;
if ( F_61 ( V_4 -> V_20 . V_17 -> V_113 ) ) {
V_170 -> V_105 = V_173 -> V_107 ;
V_170 -> V_106 = V_173 -> V_108 ;
V_170 -> V_179 = V_170 -> V_180 = 0 ;
return;
}
if ( V_171 == V_181 ) {
if ( V_4 -> V_142 != 90 && V_4 -> V_142 != 270 )
V_152 = 1 ;
V_177 = F_105 ( V_182 , 1 << ( F_45 ( V_173 -> V_105 ) - 3 ) ) ;
V_178 = F_105 ( V_183 , 1 << ( F_45 ( V_173 -> V_106 ) - 1 ) ) ;
V_175 = V_144 -> V_167 ;
} else {
V_114 V_110 = F_102 ( V_173 -> V_17 ) ;
V_176 = 64 / F_103 ( V_110 , 8 ) ;
V_175 = V_144 -> V_184 ;
V_149 = V_151 = V_175 ;
V_177 = V_178 = 1 ;
}
V_150 = F_106 ( V_114 ,
V_172 ? V_146 -> V_162 : V_146 -> V_163 ,
V_172 ? V_173 -> V_108 : V_173 -> V_107 ) ;
V_174 = F_106 ( V_114 , V_161 , V_173 -> V_108 ) ;
if ( V_171 == V_181 ) {
V_149 = F_106 ( V_114 , V_150 , V_173 -> V_107 / V_177 ) ;
V_151 = F_106 ( V_114 , V_174 , V_173 -> V_108 / V_178 ) ;
if ( V_172 ) {
F_107 ( V_177 , V_178 ) ;
F_107 ( V_149 , V_151 ) ;
}
}
F_100 ( & V_170 -> V_105 , V_149 , V_150 , F_45 ( V_175 ) - 1 ,
& V_170 -> V_106 , V_151 , V_174 , V_152 ,
V_176 ) ;
V_170 -> V_179 = F_108 ( V_114 , V_170 -> V_179 , 0 , V_173 -> V_107 - V_170 -> V_105 ) ;
V_170 -> V_180 = F_108 ( V_114 , V_170 -> V_180 , 0 , V_173 -> V_108 - V_170 -> V_106 ) ;
V_170 -> V_179 = F_109 ( V_170 -> V_179 , V_144 -> V_185 ) ;
F_43 ( L_6 ,
V_171 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ,
V_173 -> V_107 , V_173 -> V_108 ) ;
}
static int F_110 ( struct V_125 * V_125 , void * V_186 ,
struct V_187 * V_28 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
strncpy ( V_28 -> V_188 , V_2 -> V_130 -> V_189 , sizeof( V_28 -> V_188 ) - 1 ) ;
strncpy ( V_28 -> V_190 , V_2 -> V_130 -> V_189 , sizeof( V_28 -> V_190 ) - 1 ) ;
V_28 -> V_191 [ 0 ] = 0 ;
V_28 -> V_192 = V_193 | V_194 ;
return 0 ;
}
static int F_111 ( struct V_125 * V_125 , void * V_186 ,
struct V_195 * V_51 )
{
struct V_99 * V_17 ;
V_17 = F_59 ( NULL , NULL , V_103 | V_104 ,
V_51 -> V_68 ) ;
if ( ! V_17 )
return - V_18 ;
strncpy ( V_51 -> V_196 , V_17 -> V_189 , sizeof( V_51 -> V_196 ) - 1 ) ;
V_51 -> V_102 = V_17 -> V_140 ;
if ( V_17 -> V_140 == V_197 )
V_51 -> V_11 |= V_198 ;
return 0 ;
}
static struct V_199 * F_112 ( struct V_199 * V_200 )
{
struct V_201 * V_141 = & V_200 -> V_202 [ 0 ] ;
while ( ! ( V_141 -> V_11 & V_203 ) ) {
V_141 = F_113 ( V_141 ) ;
if ( ! V_141 )
break;
V_200 = V_141 -> V_88 ;
V_141 = & V_200 -> V_202 [ 0 ] ;
}
return V_200 ;
}
static int F_114 ( struct V_3 * V_4 ,
struct V_204 * V_205 ,
struct V_99 * * V_206 ,
bool V_207 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_47 * V_208 = V_2 -> V_8 . V_13 [ V_14 ] ;
struct V_209 V_210 ;
struct V_204 * V_211 = & V_210 . V_212 ;
struct V_199 * V_200 ;
struct V_99 * V_154 ;
struct V_201 * V_141 ;
int V_12 , V_85 = 1 ;
V_114 V_213 ;
if ( F_76 ( ! V_208 || ! V_205 ) )
return - V_18 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_210 . V_212 = * V_205 ;
V_210 . V_214 = V_207 ? V_215 : V_216 ;
V_200 = F_112 ( & V_208 -> V_88 ) ;
while ( 1 ) {
V_154 = F_59 ( NULL , V_211 -> V_139 != 0 ? & V_211 -> V_139 : NULL ,
V_103 , V_85 ++ ) ;
if ( V_154 == NULL ) {
return - V_18 ;
}
V_211 -> V_139 = V_205 -> V_139 = V_154 -> V_156 ;
while ( V_200 != & V_2 -> V_5 . V_217 . V_88 ) {
V_208 = F_115 ( V_200 ) ;
V_210 . V_141 = 0 ;
V_12 = F_48 ( V_208 , V_141 , V_218 , NULL , & V_210 ) ;
if ( V_12 )
return V_12 ;
if ( V_200 -> V_202 [ 0 ] . V_11 & V_219 ) {
V_210 . V_141 = V_200 -> V_220 - 1 ;
V_211 -> V_139 = V_205 -> V_139 ;
V_12 = F_48 ( V_208 , V_141 , V_218 , NULL ,
& V_210 ) ;
if ( V_12 )
return V_12 ;
}
V_141 = F_113 ( & V_200 -> V_202 [ V_210 . V_141 ] ) ;
if ( ! V_141 )
return - V_18 ;
V_200 = V_141 -> V_88 ;
}
if ( V_211 -> V_139 != V_205 -> V_139 )
continue;
V_213 = V_154 -> V_140 ;
V_205 -> V_105 = V_211 -> V_105 ;
V_205 -> V_106 = V_211 -> V_106 ;
V_154 = F_99 ( V_4 , & V_205 -> V_105 , & V_205 -> V_106 ,
NULL , & V_213 , V_158 ) ;
V_154 = F_99 ( V_4 , & V_205 -> V_105 , & V_205 -> V_106 ,
NULL , & V_213 , V_155 ) ;
if ( V_154 && V_154 -> V_156 )
V_211 -> V_139 = V_154 -> V_156 ;
if ( V_211 -> V_105 != V_205 -> V_105 || V_211 -> V_106 != V_205 -> V_106 )
continue;
V_205 -> V_139 = V_211 -> V_139 ;
break;
}
if ( V_206 && V_154 )
* V_206 = V_154 ;
* V_205 = * V_211 ;
return 0 ;
}
static int F_116 ( struct V_47 * V_10 ,
struct V_221 * V_111 ,
unsigned int V_93 , bool V_222 )
{
struct V_223 V_224 ;
int V_85 , V_12 ;
int V_141 ;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ )
V_224 . V_225 [ V_85 ] . V_226 = V_111 [ V_85 ] . V_112 ;
V_141 = V_10 -> V_88 . V_220 - 1 ;
if ( V_222 )
V_12 = F_48 ( V_10 , V_141 , V_227 , V_141 , & V_224 ) ;
else
V_12 = F_48 ( V_10 , V_141 , V_228 , V_141 , & V_224 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_93 != V_224 . V_229 )
return - V_18 ;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ )
V_111 [ V_85 ] . V_112 = V_224 . V_225 [ V_85 ] . V_226 ;
if ( V_224 . V_225 [ 0 ] . V_226 > V_230 ) {
F_65 ( V_10 -> V_231 , L_7 ,
V_224 . V_225 [ 0 ] . V_226 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_117 ( struct V_125 * V_125 , void * V_232 ,
struct V_90 * V_51 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
F_118 ( & V_2 -> V_5 . V_4 -> V_20 , V_51 ) ;
return 0 ;
}
static int F_119 ( struct V_125 * V_125 , void * V_232 ,
struct V_90 * V_51 )
{
struct V_96 * V_233 = & V_51 -> V_17 . V_101 ;
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_204 V_211 ;
struct V_99 * V_154 = NULL ;
int V_12 = 0 ;
F_82 ( V_2 ) ;
F_72 ( & V_2 -> V_119 ) ;
if ( F_120 ( V_233 -> V_102 ) ) {
F_99 ( V_4 , & V_233 -> V_105 , & V_233 -> V_106 ,
NULL , & V_233 -> V_102 ,
V_158 ) ;
V_4 -> V_16 . V_107 = V_233 -> V_105 ;
V_4 -> V_16 . V_108 = V_233 -> V_106 ;
}
V_154 = F_99 ( V_4 , & V_233 -> V_105 , & V_233 -> V_106 ,
NULL , & V_233 -> V_102 ,
V_155 ) ;
if ( ! V_154 ) {
V_12 = - V_18 ;
goto V_128;
}
if ( ! V_2 -> V_5 . V_122 ) {
V_211 . V_105 = V_233 -> V_105 ;
V_211 . V_106 = V_233 -> V_106 ;
V_211 . V_139 = V_154 -> V_156 ;
F_114 ( V_4 , & V_211 , & V_154 , false ) ;
V_233 -> V_105 = V_211 . V_105 ;
V_233 -> V_106 = V_211 . V_106 ;
if ( V_154 )
V_233 -> V_102 = V_154 -> V_140 ;
}
F_121 ( V_154 , V_233 -> V_105 , V_233 -> V_106 , V_233 ) ;
if ( V_154 -> V_11 & V_234 )
F_116 ( V_2 -> V_8 . V_13 [ V_14 ] ,
V_233 -> V_111 , V_154 -> V_109 , true ) ;
V_128:
F_74 ( & V_2 -> V_119 ) ;
F_90 ( V_2 ) ;
return V_12 ;
}
static void F_122 ( struct V_3 * V_4 ,
enum V_235 V_113 )
{
bool V_236 = F_61 ( V_113 ) ;
V_4 -> V_237 . V_238 = ! V_236 ;
F_123 ( V_4 , ! V_236 ) ;
if ( V_236 )
F_32 ( V_239 , & V_4 -> V_1 -> V_25 ) ;
else
F_20 ( V_239 , & V_4 -> V_1 -> V_25 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_90 * V_51 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_96 * V_233 = & V_51 -> V_17 . V_101 ;
struct V_204 * V_211 = & V_2 -> V_5 . V_211 ;
struct V_50 * V_240 = & V_4 -> V_20 ;
struct V_99 * V_241 = NULL ;
int V_12 , V_85 ;
if ( F_125 ( & V_2 -> V_5 . V_118 ) )
return - V_126 ;
if ( F_120 ( V_233 -> V_102 ) ) {
F_99 ( V_4 , & V_233 -> V_105 , & V_233 -> V_106 ,
NULL , & V_233 -> V_102 ,
V_158 ) ;
V_4 -> V_16 . V_107 = V_233 -> V_105 ;
V_4 -> V_16 . V_108 = V_233 -> V_106 ;
}
V_240 -> V_17 = F_99 ( V_4 , & V_233 -> V_105 , & V_233 -> V_106 ,
NULL , & V_233 -> V_102 ,
V_155 ) ;
if ( ! V_240 -> V_17 )
return - V_18 ;
F_126 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_122 ) {
V_211 -> V_139 = V_240 -> V_17 -> V_156 ;
V_211 -> V_105 = V_233 -> V_105 ;
V_211 -> V_106 = V_233 -> V_106 ;
V_12 = F_114 ( V_4 , V_211 , & V_241 , true ) ;
if ( V_12 )
return V_12 ;
V_233 -> V_105 = V_211 -> V_105 ;
V_233 -> V_106 = V_211 -> V_106 ;
}
F_121 ( V_240 -> V_17 , V_233 -> V_105 , V_233 -> V_106 , V_233 ) ;
if ( V_240 -> V_17 -> V_11 & V_234 ) {
V_12 = F_116 ( V_2 -> V_8 . V_13 [ V_14 ] ,
V_233 -> V_111 , V_240 -> V_17 -> V_109 ,
true ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_85 = 0 ; V_85 < V_240 -> V_17 -> V_109 ; V_85 ++ ) {
V_240 -> V_242 [ V_85 ] = V_233 -> V_111 [ V_85 ] . V_242 ;
V_240 -> V_73 [ V_85 ] = V_233 -> V_111 [ V_85 ] . V_112 ;
}
F_127 ( V_240 , V_233 -> V_105 , V_233 -> V_106 ) ;
if ( ! ( V_4 -> V_25 & V_164 ) )
F_128 ( V_240 , 0 , 0 , V_233 -> V_105 , V_233 -> V_106 ) ;
F_122 ( V_4 , V_240 -> V_17 -> V_113 ) ;
if ( ! V_2 -> V_5 . V_122 ) {
V_4 -> V_16 . V_17 = V_241 ;
F_127 ( & V_4 -> V_16 , V_233 -> V_105 , V_233 -> V_106 ) ;
F_128 ( & V_4 -> V_16 , 0 , 0 , V_233 -> V_105 , V_233 -> V_106 ) ;
}
return V_12 ;
}
static int F_129 ( struct V_125 * V_125 , void * V_186 ,
struct V_90 * V_51 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
F_82 ( V_2 ) ;
F_72 ( & V_2 -> V_119 ) ;
V_12 = F_124 ( V_2 , V_51 ) ;
F_74 ( & V_2 -> V_119 ) ;
F_90 ( V_2 ) ;
return V_12 ;
}
static int F_130 ( struct V_125 * V_125 , void * V_186 ,
struct V_243 * V_85 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_47 * V_208 = V_2 -> V_8 . V_13 [ V_14 ] ;
if ( V_85 -> V_68 != 0 )
return - V_18 ;
V_85 -> type = V_244 ;
if ( V_208 )
F_131 ( V_85 -> V_189 , V_208 -> V_189 , sizeof( V_85 -> V_189 ) ) ;
return 0 ;
}
static int F_132 ( struct V_125 * V_125 , void * V_186 , unsigned int V_85 )
{
return V_85 == 0 ? V_85 : - V_18 ;
}
static int F_133 ( struct V_125 * V_125 , void * V_186 , unsigned int * V_85 )
{
* V_85 = 0 ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_209 V_245 , V_246 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_47 * V_208 ;
struct V_201 * V_141 ;
int V_12 ;
V_141 = F_113 ( & V_5 -> V_247 ) ;
if ( V_141 == NULL )
return - V_248 ;
V_208 = F_115 ( V_141 -> V_88 ) ;
while ( 1 ) {
V_141 = & V_208 -> V_88 . V_202 [ 0 ] ;
if ( ! ( V_141 -> V_11 & V_219 ) )
break;
if ( V_208 == & V_2 -> V_5 . V_217 ) {
struct V_50 * V_240 = & V_5 -> V_4 -> V_16 ;
V_245 . V_212 . V_105 = V_240 -> V_107 ;
V_245 . V_212 . V_106 = V_240 -> V_108 ;
V_245 . V_212 . V_139 = V_240 -> V_17 ? V_240 -> V_17 -> V_156 : 0 ;
} else {
V_245 . V_141 = V_141 -> V_68 ;
V_245 . V_214 = V_215 ;
V_12 = F_48 ( V_208 , V_141 , V_249 , NULL , & V_245 ) ;
if ( V_12 < 0 && V_12 != - V_250 )
return - V_248 ;
}
V_141 = F_113 ( V_141 ) ;
if ( V_141 == NULL ||
F_135 ( V_141 -> V_88 ) != V_251 )
break;
V_208 = F_115 ( V_141 -> V_88 ) ;
V_246 . V_141 = V_141 -> V_68 ;
V_246 . V_214 = V_215 ;
V_12 = F_48 ( V_208 , V_141 , V_249 , NULL , & V_246 ) ;
if ( V_12 < 0 && V_12 != - V_250 )
return - V_248 ;
if ( V_246 . V_212 . V_105 != V_245 . V_212 . V_105 ||
V_246 . V_212 . V_106 != V_245 . V_212 . V_106 ||
V_246 . V_212 . V_139 != V_245 . V_212 . V_139 )
return - V_248 ;
if ( V_208 == V_2 -> V_8 . V_13 [ V_14 ] &&
F_136 ( V_246 . V_212 . V_139 ) ) {
struct V_221 V_111 [ V_252 ] ;
struct V_50 * V_98 = & V_5 -> V_4 -> V_20 ;
unsigned int V_85 ;
V_12 = F_116 ( V_208 , V_111 ,
V_98 -> V_17 -> V_109 ,
false ) ;
if ( V_12 < 0 )
return - V_248 ;
for ( V_85 = 0 ; V_85 < V_98 -> V_17 -> V_109 ; V_85 ++ )
if ( V_98 -> V_73 [ V_85 ] < V_111 [ V_85 ] . V_112 )
return - V_248 ;
}
}
return 0 ;
}
static int F_137 ( struct V_125 * V_125 , void * V_186 ,
enum V_253 type )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_47 * V_208 = V_7 -> V_13 [ V_14 ] ;
int V_12 ;
if ( F_31 ( V_2 ) )
return - V_126 ;
V_12 = F_138 ( & V_208 -> V_88 , V_7 -> V_254 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_5 . V_122 ) {
V_12 = F_134 ( V_2 ) ;
if ( V_12 < 0 ) {
F_139 ( & V_208 -> V_88 ) ;
return V_12 ;
}
}
return F_140 ( & V_2 -> V_5 . V_118 , type ) ;
}
static int F_141 ( struct V_125 * V_125 , void * V_186 ,
enum V_253 type )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_47 * V_208 = V_2 -> V_8 . V_13 [ V_14 ] ;
int V_12 ;
V_12 = F_142 ( & V_2 -> V_5 . V_118 , type ) ;
if ( V_12 == 0 )
F_139 ( & V_208 -> V_88 ) ;
return V_12 ;
}
static int F_143 ( struct V_125 * V_125 , void * V_186 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 = F_144 ( & V_2 -> V_5 . V_118 , V_256 ) ;
if ( ! V_12 )
V_2 -> V_5 . V_83 = V_256 -> V_80 ;
return V_12 ;
}
static int F_145 ( struct V_125 * V_125 , void * V_186 ,
struct V_257 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_146 ( & V_2 -> V_5 . V_118 , V_30 ) ;
}
static int F_147 ( struct V_125 * V_125 , void * V_186 ,
struct V_257 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_148 ( & V_2 -> V_5 . V_118 , V_30 ) ;
}
static int F_149 ( struct V_125 * V_125 , void * V_186 ,
struct V_258 * V_259 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_150 ( & V_2 -> V_5 . V_118 , V_259 ) ;
}
static int F_151 ( struct V_125 * V_125 , void * V_186 ,
struct V_257 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_152 ( & V_2 -> V_5 . V_118 , V_30 , V_125 -> V_260 & V_261 ) ;
}
static int F_153 ( struct V_125 * V_125 , void * V_186 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_154 ( & V_2 -> V_5 . V_118 , V_263 ) ;
}
static int F_155 ( struct V_125 * V_125 , void * V_186 ,
struct V_257 * V_264 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_156 ( & V_2 -> V_5 . V_118 , V_264 ) ;
}
static int F_157 ( struct V_125 * V_125 , void * V_232 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
if ( V_266 -> type != V_267 )
return - V_18 ;
switch ( V_266 -> V_171 ) {
case V_268 :
case V_269 :
V_51 = & V_4 -> V_20 ;
case V_270 :
case V_271 :
V_266 -> V_170 . V_179 = 0 ;
V_266 -> V_170 . V_180 = 0 ;
V_266 -> V_170 . V_105 = V_51 -> V_272 ;
V_266 -> V_170 . V_106 = V_51 -> V_273 ;
return 0 ;
case V_181 :
V_51 = & V_4 -> V_20 ;
case V_274 :
V_266 -> V_170 . V_179 = V_51 -> V_165 ;
V_266 -> V_170 . V_180 = V_51 -> V_166 ;
V_266 -> V_170 . V_105 = V_51 -> V_105 ;
V_266 -> V_170 . V_106 = V_51 -> V_106 ;
return 0 ;
}
return - V_18 ;
}
static int F_158 ( struct V_169 * V_275 , struct V_169 * V_264 )
{
if ( V_275 -> V_179 < V_264 -> V_179 || V_275 -> V_180 < V_264 -> V_180 )
return 0 ;
if ( V_275 -> V_179 + V_275 -> V_105 > V_264 -> V_179 + V_264 -> V_105 )
return 0 ;
if ( V_275 -> V_180 + V_275 -> V_106 > V_264 -> V_180 + V_264 -> V_106 )
return 0 ;
return 1 ;
}
static int F_159 ( struct V_125 * V_125 , void * V_232 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_169 V_276 = V_266 -> V_170 ;
struct V_50 * V_51 ;
unsigned long V_11 ;
if ( V_266 -> type != V_267 )
return - V_18 ;
if ( V_266 -> V_171 == V_181 )
V_51 = & V_4 -> V_20 ;
else if ( V_266 -> V_171 == V_274 )
V_51 = & V_4 -> V_16 ;
else
return - V_18 ;
F_104 ( V_4 , & V_276 , V_266 -> V_171 ) ;
if ( V_266 -> V_11 & V_277 &&
! F_158 ( & V_276 , & V_266 -> V_170 ) )
return - V_278 ;
if ( V_266 -> V_11 & V_279 &&
! F_158 ( & V_266 -> V_170 , & V_276 ) )
return - V_278 ;
V_266 -> V_170 = V_276 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_128 ( V_51 , V_266 -> V_170 . V_179 , V_266 -> V_170 . V_180 , V_266 -> V_170 . V_105 ,
V_266 -> V_170 . V_106 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
return 0 ;
}
static int F_160 ( struct V_199 * V_88 ,
const struct V_201 * V_280 ,
const struct V_201 * V_281 , V_114 V_11 )
{
struct V_47 * V_208 = F_115 ( V_88 ) ;
struct V_1 * V_2 = F_161 ( V_208 ) ;
if ( F_135 ( V_281 -> V_88 ) != V_251 )
return - V_18 ;
if ( F_76 ( V_2 == NULL ) )
return 0 ;
F_43 ( L_8 ,
V_280 -> V_88 -> V_189 , V_281 -> V_88 -> V_189 , V_11 ,
V_2 -> V_5 . V_282 ) ;
if ( V_11 & V_283 ) {
if ( V_2 -> V_5 . V_282 != 0 )
return - V_126 ;
V_2 -> V_5 . V_282 = V_208 -> V_284 ;
return 0 ;
}
V_2 -> V_5 . V_282 = 0 ;
return 0 ;
}
void F_162 ( struct V_47 * V_208 , unsigned int V_285 ,
void * V_286 )
{
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_287 * V_288 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
if ( V_208 == NULL )
return;
V_10 = F_2 ( V_208 ) ;
V_288 = F_163 ( & V_208 -> V_88 ) ;
F_3 ( & V_288 -> V_19 , V_11 ) ;
V_2 = V_10 ? V_10 -> V_289 : NULL ;
if ( V_2 && V_286 && V_285 == V_290 &&
F_35 ( V_37 , & V_2 -> V_25 ) ) {
unsigned long V_291 ;
F_3 ( & V_2 -> V_19 , V_291 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_41 ) ) {
V_30 = F_164 ( V_2 -> V_5 . V_41 . V_292 ,
struct V_29 , V_293 ) ;
F_66 ( & V_30 -> V_39 , 0 , * ( ( V_114 * ) V_286 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_19 , V_291 ) ;
}
F_21 ( & V_288 -> V_19 , V_11 ) ;
}
static int F_165 ( struct V_47 * V_208 ,
struct V_294 * V_232 ,
struct V_295 * V_139 )
{
struct V_99 * V_17 ;
V_17 = F_59 ( NULL , NULL , V_103 , V_139 -> V_68 ) ;
if ( ! V_17 )
return - V_18 ;
V_139 -> V_139 = V_17 -> V_156 ;
return 0 ;
}
static int F_166 ( struct V_47 * V_208 ,
struct V_294 * V_232 ,
struct V_209 * V_17 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_204 * V_211 ;
struct V_50 * V_240 ;
if ( V_17 -> V_214 == V_216 ) {
V_211 = F_167 ( V_232 , V_17 -> V_141 ) ;
V_17 -> V_212 = * V_211 ;
return 0 ;
}
V_211 = & V_17 -> V_212 ;
V_211 -> V_296 = V_297 ;
V_240 = V_17 -> V_141 == V_158 ? & V_4 -> V_16 : & V_4 -> V_20 ;
F_72 ( & V_2 -> V_119 ) ;
if ( ! F_76 ( V_4 -> V_16 . V_17 == NULL ) )
V_211 -> V_139 = V_4 -> V_16 . V_17 -> V_156 ;
V_211 -> V_105 = V_240 -> V_107 ;
V_211 -> V_106 = V_240 -> V_108 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_168 ( struct V_47 * V_208 ,
struct V_294 * V_232 ,
struct V_209 * V_17 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
struct V_204 * V_211 = & V_17 -> V_212 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_240 ;
struct V_99 * V_154 ;
F_43 ( L_9 ,
V_17 -> V_141 , V_211 -> V_139 , V_211 -> V_105 , V_211 -> V_106 ) ;
if ( V_17 -> V_141 == V_155 &&
F_125 ( & V_2 -> V_5 . V_118 ) )
return - V_126 ;
F_72 ( & V_2 -> V_119 ) ;
V_154 = F_99 ( V_4 , & V_211 -> V_105 , & V_211 -> V_106 ,
& V_211 -> V_139 , NULL , V_17 -> V_141 ) ;
F_74 ( & V_2 -> V_119 ) ;
V_211 -> V_296 = V_297 ;
if ( V_17 -> V_214 == V_216 ) {
V_211 = F_167 ( V_232 , V_17 -> V_141 ) ;
* V_211 = V_17 -> V_212 ;
return 0 ;
}
if ( F_76 ( V_154 == NULL ) )
return - V_18 ;
F_126 ( V_4 ) ;
F_122 ( V_4 , V_154 -> V_113 ) ;
V_240 = V_17 -> V_141 == V_158 ?
& V_4 -> V_16 : & V_4 -> V_20 ;
F_72 ( & V_2 -> V_119 ) ;
F_127 ( V_240 , V_211 -> V_105 , V_211 -> V_106 ) ;
V_2 -> V_5 . V_211 = * V_211 ;
V_240 -> V_17 = V_154 ;
if ( ! ( V_17 -> V_141 == V_155 && ( V_4 -> V_25 & V_164 ) ) )
F_128 ( V_240 , 0 , 0 , V_211 -> V_105 , V_211 -> V_106 ) ;
if ( V_17 -> V_141 == V_158 )
V_4 -> V_25 &= ~ V_164 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_169 ( struct V_47 * V_208 ,
struct V_294 * V_232 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
struct V_169 * V_170 = & V_299 -> V_170 ;
struct V_169 * V_300 ;
if ( V_299 -> V_141 != V_158 )
return - V_18 ;
F_72 ( & V_2 -> V_119 ) ;
switch ( V_299 -> V_171 ) {
case V_269 :
V_51 = & V_4 -> V_20 ;
case V_270 :
V_170 -> V_105 = V_51 -> V_272 ;
V_170 -> V_106 = V_51 -> V_273 ;
V_170 -> V_179 = 0 ;
V_170 -> V_180 = 0 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
case V_274 :
V_300 = F_170 ( V_232 , V_299 -> V_141 ) ;
break;
case V_181 :
V_300 = F_171 ( V_232 , V_299 -> V_141 ) ;
V_51 = & V_4 -> V_20 ;
break;
default:
F_74 ( & V_2 -> V_119 ) ;
return - V_18 ;
}
if ( V_299 -> V_214 == V_216 ) {
V_299 -> V_170 = * V_300 ;
} else {
V_170 -> V_179 = V_51 -> V_165 ;
V_170 -> V_180 = V_51 -> V_166 ;
V_170 -> V_105 = V_51 -> V_105 ;
V_170 -> V_106 = V_51 -> V_106 ;
}
F_43 ( L_10 ,
V_299 -> V_141 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ,
V_51 -> V_107 , V_51 -> V_108 ) ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_172 ( struct V_47 * V_208 ,
struct V_294 * V_232 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
struct V_169 * V_170 = & V_299 -> V_170 ;
struct V_169 * V_300 ;
unsigned long V_11 ;
if ( V_299 -> V_141 != V_158 )
return - V_18 ;
F_72 ( & V_2 -> V_119 ) ;
F_104 ( V_4 , V_170 , V_274 ) ;
switch ( V_299 -> V_171 ) {
case V_274 :
V_300 = F_170 ( V_232 , V_299 -> V_141 ) ;
break;
case V_181 :
V_300 = F_171 ( V_232 , V_299 -> V_141 ) ;
V_51 = & V_4 -> V_20 ;
break;
default:
F_74 ( & V_2 -> V_119 ) ;
return - V_18 ;
}
if ( V_299 -> V_214 == V_216 ) {
* V_300 = V_299 -> V_170 ;
} else {
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_128 ( V_51 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
if ( V_299 -> V_171 == V_181 )
V_4 -> V_25 |= V_164 ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
}
F_43 ( L_11 , V_299 -> V_171 , V_170 -> V_179 , V_170 -> V_180 ,
V_170 -> V_105 , V_170 -> V_106 ) ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_90 V_17 = {
. type = V_267 ,
. V_17 . V_101 = {
. V_105 = 640 ,
. V_106 = 480 ,
. V_102 = V_301 ,
. V_302 = V_303 ,
. V_296 = V_297 ,
} ,
} ;
return F_124 ( V_2 , & V_17 ) ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_304 * V_231 )
{
struct V_305 * V_87 = & V_2 -> V_5 . V_87 ;
struct V_27 * V_5 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_12 = - V_306 ;
V_4 = F_174 ( sizeof( * V_4 ) , V_307 ) ;
if ( ! V_4 )
return - V_306 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_308 = V_309 ;
V_4 -> V_310 = V_311 ;
V_4 -> V_25 = V_312 ;
V_4 -> V_16 . V_17 = F_59 ( NULL , NULL , V_103 , 0 ) ;
V_4 -> V_20 . V_17 = V_4 -> V_16 . V_17 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
snprintf ( V_87 -> V_189 , sizeof( V_87 -> V_189 ) , L_12 , V_2 -> V_313 ) ;
V_87 -> V_314 = & V_315 ;
V_87 -> V_316 = & V_317 ;
V_87 -> V_231 = V_231 ;
V_87 -> V_318 = - 1 ;
V_87 -> V_319 = V_320 ;
V_87 -> V_119 = & V_2 -> V_119 ;
F_175 ( V_87 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_77 = 0 ;
V_5 -> V_83 = 0 ;
V_5 -> V_132 = 0 ;
F_56 ( & V_5 -> V_38 ) ;
F_56 ( & V_5 -> V_41 ) ;
V_5 -> V_4 = V_4 ;
V_79 = & V_2 -> V_5 . V_118 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_267 ;
V_79 -> V_321 = V_322 | V_323 | V_324 ;
V_79 -> V_81 = V_2 -> V_5 . V_4 ;
V_79 -> V_325 = & V_326 ;
V_79 -> V_327 = & V_328 ;
V_79 -> V_329 = sizeof( struct V_29 ) ;
V_12 = F_176 ( V_79 ) ;
if ( V_12 )
goto V_330;
V_5 -> V_247 . V_11 = V_219 ;
V_12 = F_177 ( & V_87 -> V_88 , 1 , & V_5 -> V_247 , 0 ) ;
if ( V_12 )
goto V_330;
F_178 ( V_87 , V_331 ) ;
F_178 ( V_87 , V_332 ) ;
V_12 = F_179 ( V_87 , V_333 , - 1 ) ;
if ( V_12 )
goto V_334;
F_180 ( V_231 , L_13 ,
V_87 -> V_189 , F_181 ( V_87 ) ) ;
V_87 -> V_124 = & V_4 -> V_120 . V_123 ;
return 0 ;
V_334:
F_182 ( & V_87 -> V_88 ) ;
V_330:
F_183 ( V_4 ) ;
return V_12 ;
}
static int F_184 ( struct V_47 * V_208 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
int V_12 ;
if ( V_2 == NULL )
return - V_15 ;
V_12 = F_185 ( V_2 , V_208 -> V_231 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_335 = F_2 ( V_208 ) ;
V_12 = F_173 ( V_2 , V_208 -> V_231 ) ;
if ( V_12 ) {
F_186 ( V_2 ) ;
V_2 -> V_335 = NULL ;
}
return V_12 ;
}
static void F_187 ( struct V_47 * V_208 )
{
struct V_1 * V_2 = F_161 ( V_208 ) ;
if ( V_2 == NULL )
return;
F_186 ( V_2 ) ;
if ( F_188 ( & V_2 -> V_5 . V_87 ) ) {
F_189 ( & V_2 -> V_5 . V_87 ) ;
F_182 ( & V_2 -> V_5 . V_87 . V_88 ) ;
V_2 -> V_335 = NULL ;
}
F_183 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
int F_190 ( struct V_1 * V_2 )
{
struct V_47 * V_208 = & V_2 -> V_5 . V_217 ;
int V_12 ;
F_191 ( V_208 , & V_336 ) ;
V_208 -> V_11 = V_337 ;
snprintf ( V_208 -> V_189 , sizeof( V_208 -> V_189 ) , L_14 , V_2 -> V_130 -> V_313 ) ;
V_2 -> V_5 . V_338 [ V_158 ] . V_11 = V_219 ;
V_2 -> V_5 . V_338 [ V_155 ] . V_11 = V_203 ;
V_12 = F_177 ( & V_208 -> V_88 , V_339 ,
V_2 -> V_5 . V_338 , 0 ) ;
if ( V_12 )
return V_12 ;
V_208 -> V_88 . V_325 = & V_340 ;
V_208 -> V_341 = & V_342 ;
F_192 ( V_208 , V_2 ) ;
return 0 ;
}
void F_193 ( struct V_1 * V_2 )
{
struct V_47 * V_208 = & V_2 -> V_5 . V_217 ;
F_194 ( V_208 ) ;
F_182 ( & V_208 -> V_88 ) ;
F_192 ( V_208 , NULL ) ;
}
