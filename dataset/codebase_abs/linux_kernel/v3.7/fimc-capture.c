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
int V_12 ;
if ( F_76 ( V_5 -> V_4 == NULL ) )
return - V_15 ;
if ( V_5 -> V_4 -> V_120 . V_121 )
return 0 ;
V_12 = F_77 ( V_5 -> V_4 ) ;
if ( V_12 || V_5 -> V_122 || ! V_5 -> V_4 -> V_120 . V_121 )
return V_12 ;
return F_78 ( & V_5 -> V_4 -> V_120 . V_123 ,
V_2 -> V_8 . V_13 [ V_14 ] -> V_124 , NULL ) ;
}
static int F_79 ( struct V_125 * V_125 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 = - V_126 ;
F_43 ( L_4 , F_81 ( V_127 ) , V_2 -> V_25 ) ;
if ( F_82 ( & V_2 -> V_119 ) )
return - V_128 ;
if ( F_83 ( V_2 ) )
goto V_129;
F_32 ( V_130 , & V_2 -> V_25 ) ;
V_12 = F_84 ( & V_2 -> V_131 -> V_132 ) ;
if ( V_12 < 0 )
goto V_129;
V_12 = F_85 ( V_125 ) ;
if ( V_12 ) {
F_86 ( & V_2 -> V_131 -> V_132 ) ;
goto V_129;
}
if ( ++ V_2 -> V_5 . V_133 == 1 ) {
V_12 = F_29 ( V_2 , V_86 , & V_2 -> V_8 ,
& V_2 -> V_5 . V_87 . V_88 , true ) ;
if ( ! V_12 && ! V_2 -> V_5 . V_122 )
V_12 = F_87 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_75 ( V_2 ) ;
if ( V_12 < 0 ) {
F_20 ( V_130 , & V_2 -> V_25 ) ;
F_88 ( & V_2 -> V_131 -> V_132 ) ;
V_2 -> V_5 . V_133 -- ;
F_89 ( V_125 ) ;
}
}
V_129:
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static int F_90 ( struct V_125 * V_125 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
F_43 ( L_4 , F_81 ( V_127 ) , V_2 -> V_25 ) ;
F_72 ( & V_2 -> V_119 ) ;
if ( -- V_2 -> V_5 . V_133 == 0 ) {
F_20 ( V_130 , & V_2 -> V_25 ) ;
F_30 ( V_2 , false ) ;
F_29 ( V_2 , V_84 , & V_2 -> V_8 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
}
F_86 ( & V_2 -> V_131 -> V_132 ) ;
if ( V_2 -> V_5 . V_133 == 0 ) {
F_91 ( & V_2 -> V_5 . V_118 ) ;
F_92 ( V_2 -> V_5 . V_4 ) ;
}
V_12 = F_89 ( V_125 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static unsigned int F_93 ( struct V_125 * V_125 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
if ( F_82 ( & V_2 -> V_119 ) )
return V_136 ;
V_12 = F_94 ( & V_2 -> V_5 . V_118 , V_125 , V_135 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static int F_95 ( struct V_125 * V_125 , struct V_137 * V_138 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 ;
if ( F_82 ( & V_2 -> V_119 ) )
return - V_128 ;
V_12 = F_96 ( & V_2 -> V_5 . V_118 , V_138 ) ;
F_74 ( & V_2 -> V_119 ) ;
return V_12 ;
}
static struct V_99 * F_97 ( struct V_3 * V_4 ,
V_114 * V_105 , V_114 * V_106 ,
V_114 * V_139 , V_114 * V_140 , int V_141 )
{
bool V_142 = V_4 -> V_142 == 90 || V_4 -> V_142 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_143 * V_144 = V_2 -> V_22 ;
struct V_145 * V_146 = V_144 -> V_147 ;
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
F_98 ( V_105 , F_62 ( V_114 , * V_105 , 32 ) , V_150 , 4 ,
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
V_152 = F_99 ( V_154 -> V_113 ) ? 0 : 1 ;
V_110 = F_100 ( V_154 ) ;
F_98 ( V_105 , V_149 , V_150 ,
F_45 ( V_144 -> V_167 ) - 1 ,
V_106 , V_151 , V_161 ,
V_152 ,
64 / ( F_101 ( V_110 , 8 ) ) ) ;
F_43 ( L_5 ,
V_141 , V_139 ? * V_139 : 0 , * V_105 , * V_106 ,
V_148 -> V_107 , V_148 -> V_108 ) ;
return V_154 ;
}
static void F_102 ( struct V_3 * V_4 ,
struct V_169 * V_170 ,
int V_171 )
{
bool V_172 = V_4 -> V_142 == 90 || V_4 -> V_142 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_143 * V_144 = V_2 -> V_22 ;
struct V_145 * V_146 = V_144 -> V_147 ;
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
V_177 = F_103 ( V_182 , 1 << ( F_45 ( V_173 -> V_105 ) - 3 ) ) ;
V_178 = F_103 ( V_183 , 1 << ( F_45 ( V_173 -> V_106 ) - 1 ) ) ;
V_175 = V_144 -> V_167 ;
} else {
V_114 V_110 = F_100 ( V_173 -> V_17 ) ;
V_176 = 64 / F_101 ( V_110 , 8 ) ;
V_175 = V_144 -> V_184 ;
V_149 = V_151 = V_175 ;
V_177 = V_178 = 1 ;
}
V_150 = F_104 ( V_114 ,
V_172 ? V_146 -> V_162 : V_146 -> V_163 ,
V_172 ? V_173 -> V_108 : V_173 -> V_107 ) ;
V_174 = F_104 ( V_114 , V_161 , V_173 -> V_108 ) ;
if ( V_171 == V_181 ) {
V_149 = F_104 ( V_114 , V_150 , V_173 -> V_107 / V_177 ) ;
V_151 = F_104 ( V_114 , V_174 , V_173 -> V_108 / V_178 ) ;
if ( V_172 ) {
F_105 ( V_177 , V_178 ) ;
F_105 ( V_149 , V_151 ) ;
}
}
F_98 ( & V_170 -> V_105 , V_149 , V_150 , F_45 ( V_175 ) - 1 ,
& V_170 -> V_106 , V_151 , V_174 , V_152 ,
V_176 ) ;
V_170 -> V_179 = F_106 ( V_114 , V_170 -> V_179 , 0 , V_173 -> V_107 - V_170 -> V_105 ) ;
V_170 -> V_180 = F_106 ( V_114 , V_170 -> V_180 , 0 , V_173 -> V_108 - V_170 -> V_106 ) ;
V_170 -> V_179 = F_107 ( V_170 -> V_179 , V_144 -> V_185 ) ;
F_43 ( L_6 ,
V_171 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ,
V_173 -> V_107 , V_173 -> V_108 ) ;
}
static int F_108 ( struct V_125 * V_125 , void * V_186 ,
struct V_187 * V_28 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
strncpy ( V_28 -> V_188 , V_2 -> V_131 -> V_189 , sizeof( V_28 -> V_188 ) - 1 ) ;
strncpy ( V_28 -> V_190 , V_2 -> V_131 -> V_189 , sizeof( V_28 -> V_190 ) - 1 ) ;
V_28 -> V_191 [ 0 ] = 0 ;
V_28 -> V_192 = V_193 | V_194 ;
return 0 ;
}
static int F_109 ( struct V_125 * V_125 , void * V_186 ,
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
static int F_110 ( struct V_3 * V_4 ,
struct V_199 * V_200 ,
struct V_99 * * V_201 ,
bool V_202 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_47 * V_203 = V_2 -> V_8 . V_13 [ V_14 ] ;
struct V_47 * V_48 = V_2 -> V_8 . V_13 [ V_49 ] ;
struct V_204 V_205 ;
struct V_199 * V_206 = & V_205 . V_207 ;
struct V_99 * V_154 = NULL ;
int V_12 , V_85 = 0 ;
if ( F_76 ( ! V_203 || ! V_200 ) )
return - V_18 ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_207 = * V_200 ;
V_205 . V_208 = V_202 ? V_209 : V_210 ;
while ( 1 ) {
V_154 = F_59 ( NULL , V_206 -> V_139 != 0 ? & V_206 -> V_139 : NULL ,
V_103 , V_85 ++ ) ;
if ( V_154 == NULL ) {
return - V_18 ;
}
V_206 -> V_139 = V_200 -> V_139 = V_154 -> V_156 ;
V_12 = F_48 ( V_203 , V_141 , V_211 , NULL , & V_205 ) ;
if ( V_12 )
return V_12 ;
if ( V_206 -> V_139 != V_200 -> V_139 ) {
V_206 -> V_139 = 0 ;
continue;
}
if ( V_206 -> V_105 != V_200 -> V_105 || V_206 -> V_106 != V_200 -> V_106 ) {
V_114 V_212 = V_154 -> V_140 ;
V_200 -> V_105 = V_206 -> V_105 ;
V_200 -> V_106 = V_206 -> V_106 ;
V_154 = F_97 ( V_4 ,
& V_200 -> V_105 , & V_200 -> V_106 ,
NULL , & V_212 , V_155 ) ;
if ( V_154 && V_154 -> V_156 )
V_206 -> V_139 = V_154 -> V_156 ;
if ( V_206 -> V_105 != V_200 -> V_105 ||
V_206 -> V_106 != V_200 -> V_106 )
continue;
V_200 -> V_139 = V_206 -> V_139 ;
}
if ( V_48 )
V_12 = F_48 ( V_48 , V_141 , V_211 , NULL , & V_205 ) ;
if ( V_206 -> V_139 == V_200 -> V_139 &&
V_206 -> V_105 == V_200 -> V_105 && V_206 -> V_106 == V_200 -> V_106 )
break;
}
if ( V_201 && V_154 )
* V_201 = V_154 ;
* V_200 = * V_206 ;
F_43 ( L_7 , V_206 -> V_139 , V_206 -> V_105 , V_206 -> V_106 , V_154 ) ;
return 0 ;
}
static int F_111 ( struct V_47 * V_10 ,
struct V_213 * V_111 ,
unsigned int V_93 , bool V_214 )
{
struct V_215 V_216 ;
int V_85 , V_12 ;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ )
V_216 . V_217 [ V_85 ] . V_218 = V_111 [ V_85 ] . V_112 ;
if ( V_214 )
V_12 = F_48 ( V_10 , V_141 , V_219 , 0 , & V_216 ) ;
else
V_12 = F_48 ( V_10 , V_141 , V_220 , 0 , & V_216 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_93 != V_216 . V_221 )
return - V_18 ;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ )
V_111 [ V_85 ] . V_112 = V_216 . V_217 [ V_85 ] . V_218 ;
if ( V_216 . V_217 [ 0 ] . V_218 > V_222 ) {
F_65 ( V_10 -> V_223 , L_8 ,
V_216 . V_217 [ 0 ] . V_218 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_112 ( struct V_125 * V_125 , void * V_224 ,
struct V_90 * V_51 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
return F_113 ( & V_4 -> V_20 , V_51 ) ;
}
static int F_114 ( struct V_125 * V_125 , void * V_224 ,
struct V_90 * V_51 )
{
struct V_96 * V_225 = & V_51 -> V_17 . V_101 ;
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_199 V_206 ;
struct V_99 * V_154 = NULL ;
if ( F_115 ( V_225 -> V_102 ) ) {
F_97 ( V_4 , & V_225 -> V_105 , & V_225 -> V_106 ,
NULL , & V_225 -> V_102 ,
V_158 ) ;
V_4 -> V_16 . V_107 = V_225 -> V_105 ;
V_4 -> V_16 . V_108 = V_225 -> V_106 ;
}
V_154 = F_97 ( V_4 , & V_225 -> V_105 , & V_225 -> V_106 ,
NULL , & V_225 -> V_102 ,
V_155 ) ;
if ( ! V_154 )
return - V_18 ;
if ( ! V_2 -> V_5 . V_122 ) {
V_206 . V_105 = V_225 -> V_105 ;
V_206 . V_106 = V_225 -> V_106 ;
V_206 . V_139 = V_154 -> V_156 ;
F_116 ( V_2 ) ;
F_110 ( V_4 , & V_206 , & V_154 , false ) ;
F_117 ( V_2 ) ;
V_225 -> V_105 = V_206 . V_105 ;
V_225 -> V_106 = V_206 . V_106 ;
if ( V_154 )
V_225 -> V_102 = V_154 -> V_140 ;
}
F_118 ( V_154 , V_225 -> V_105 , V_225 -> V_106 , V_225 ) ;
if ( V_154 -> V_11 & V_226 )
F_111 ( V_2 -> V_8 . V_13 [ V_14 ] ,
V_225 -> V_111 , V_154 -> V_109 , true ) ;
return 0 ;
}
static void F_119 ( struct V_3 * V_4 ,
enum V_227 V_113 )
{
bool V_228 = F_61 ( V_113 ) ;
V_4 -> V_229 . V_230 = ! V_228 ;
F_120 ( V_4 , ! V_228 ) ;
if ( V_228 )
F_32 ( V_231 , & V_4 -> V_1 -> V_25 ) ;
else
F_20 ( V_231 , & V_4 -> V_1 -> V_25 ) ;
}
static int F_121 ( struct V_1 * V_2 , struct V_90 * V_51 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_96 * V_225 = & V_51 -> V_17 . V_101 ;
struct V_199 * V_206 = & V_2 -> V_5 . V_206 ;
struct V_50 * V_232 = & V_4 -> V_20 ;
struct V_99 * V_233 = NULL ;
int V_12 , V_85 ;
if ( F_122 ( & V_2 -> V_5 . V_118 ) )
return - V_126 ;
if ( F_115 ( V_225 -> V_102 ) ) {
F_97 ( V_4 , & V_225 -> V_105 , & V_225 -> V_106 ,
NULL , & V_225 -> V_102 ,
V_158 ) ;
V_4 -> V_16 . V_107 = V_225 -> V_105 ;
V_4 -> V_16 . V_108 = V_225 -> V_106 ;
}
V_232 -> V_17 = F_97 ( V_4 , & V_225 -> V_105 , & V_225 -> V_106 ,
NULL , & V_225 -> V_102 ,
V_155 ) ;
if ( ! V_232 -> V_17 )
return - V_18 ;
F_123 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_122 ) {
V_206 -> V_139 = V_232 -> V_17 -> V_156 ;
V_206 -> V_105 = V_225 -> V_105 ;
V_206 -> V_106 = V_225 -> V_106 ;
F_116 ( V_2 ) ;
V_12 = F_110 ( V_4 , V_206 , & V_233 , true ) ;
F_117 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_225 -> V_105 = V_206 -> V_105 ;
V_225 -> V_106 = V_206 -> V_106 ;
}
F_118 ( V_232 -> V_17 , V_225 -> V_105 , V_225 -> V_106 , V_225 ) ;
if ( V_232 -> V_17 -> V_11 & V_226 ) {
V_12 = F_111 ( V_2 -> V_8 . V_13 [ V_14 ] ,
V_225 -> V_111 , V_232 -> V_17 -> V_109 ,
true ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_85 = 0 ; V_85 < V_232 -> V_17 -> V_109 ; V_85 ++ )
V_232 -> V_73 [ V_85 ] = V_225 -> V_111 [ V_85 ] . V_112 ;
F_124 ( V_232 , V_225 -> V_105 , V_225 -> V_106 ) ;
if ( ! ( V_4 -> V_25 & V_164 ) )
F_125 ( V_232 , 0 , 0 , V_225 -> V_105 , V_225 -> V_106 ) ;
F_119 ( V_4 , V_232 -> V_17 -> V_113 ) ;
if ( ! V_2 -> V_5 . V_122 ) {
V_4 -> V_16 . V_17 = V_233 ;
F_124 ( & V_4 -> V_16 , V_225 -> V_105 , V_225 -> V_106 ) ;
F_125 ( & V_4 -> V_16 , 0 , 0 , V_225 -> V_105 , V_225 -> V_106 ) ;
}
return V_12 ;
}
static int F_126 ( struct V_125 * V_125 , void * V_186 ,
struct V_90 * V_51 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_121 ( V_2 , V_51 ) ;
}
static int F_127 ( struct V_125 * V_125 , void * V_186 ,
struct V_234 * V_85 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_47 * V_203 = V_2 -> V_8 . V_13 [ V_14 ] ;
if ( V_85 -> V_68 != 0 )
return - V_18 ;
V_85 -> type = V_235 ;
if ( V_203 )
F_128 ( V_85 -> V_189 , V_203 -> V_189 , sizeof( V_85 -> V_189 ) ) ;
return 0 ;
}
static int F_129 ( struct V_125 * V_125 , void * V_186 , unsigned int V_85 )
{
return V_85 == 0 ? V_85 : - V_18 ;
}
static int F_130 ( struct V_125 * V_125 , void * V_186 , unsigned int * V_85 )
{
* V_85 = 0 ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_204 V_236 , V_237 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_47 * V_203 ;
struct V_238 * V_141 ;
int V_12 ;
V_141 = F_132 ( & V_5 -> V_239 ) ;
if ( V_141 == NULL )
return - V_240 ;
V_203 = F_133 ( V_141 -> V_88 ) ;
while ( 1 ) {
V_141 = & V_203 -> V_88 . V_241 [ 0 ] ;
if ( ! ( V_141 -> V_11 & V_242 ) )
break;
if ( V_203 == & V_2 -> V_5 . V_243 ) {
struct V_50 * V_232 = & V_5 -> V_4 -> V_16 ;
V_236 . V_207 . V_105 = V_232 -> V_107 ;
V_236 . V_207 . V_106 = V_232 -> V_108 ;
V_236 . V_207 . V_139 = V_232 -> V_17 ? V_232 -> V_17 -> V_156 : 0 ;
} else {
V_236 . V_141 = V_141 -> V_68 ;
V_236 . V_208 = V_209 ;
V_12 = F_48 ( V_203 , V_141 , V_244 , NULL , & V_236 ) ;
if ( V_12 < 0 && V_12 != - V_245 )
return - V_240 ;
}
V_141 = F_132 ( V_141 ) ;
if ( V_141 == NULL ||
F_134 ( V_141 -> V_88 ) != V_246 )
break;
V_203 = F_133 ( V_141 -> V_88 ) ;
V_237 . V_141 = V_141 -> V_68 ;
V_237 . V_208 = V_209 ;
V_12 = F_48 ( V_203 , V_141 , V_244 , NULL , & V_237 ) ;
if ( V_12 < 0 && V_12 != - V_245 )
return - V_240 ;
if ( V_237 . V_207 . V_105 != V_236 . V_207 . V_105 ||
V_237 . V_207 . V_106 != V_236 . V_207 . V_106 ||
V_237 . V_207 . V_139 != V_236 . V_207 . V_139 )
return - V_240 ;
if ( V_203 == V_2 -> V_8 . V_13 [ V_14 ] &&
F_135 ( V_237 . V_207 . V_139 ) ) {
struct V_213 V_111 [ V_247 ] ;
struct V_50 * V_98 = & V_5 -> V_4 -> V_20 ;
unsigned int V_85 ;
V_12 = F_111 ( V_203 , V_111 ,
V_98 -> V_17 -> V_109 ,
false ) ;
if ( V_12 < 0 )
return - V_240 ;
for ( V_85 = 0 ; V_85 < V_98 -> V_17 -> V_109 ; V_85 ++ )
if ( V_98 -> V_73 [ V_85 ] < V_111 [ V_85 ] . V_112 )
return - V_240 ;
}
}
return 0 ;
}
static int F_136 ( struct V_125 * V_125 , void * V_186 ,
enum V_248 type )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_47 * V_203 = V_7 -> V_13 [ V_14 ] ;
int V_12 ;
if ( F_31 ( V_2 ) )
return - V_126 ;
V_12 = F_137 ( & V_203 -> V_88 , V_7 -> V_249 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_5 . V_122 ) {
V_12 = F_131 ( V_2 ) ;
if ( V_12 < 0 ) {
F_138 ( & V_203 -> V_88 ) ;
return V_12 ;
}
}
return F_139 ( & V_2 -> V_5 . V_118 , type ) ;
}
static int F_140 ( struct V_125 * V_125 , void * V_186 ,
enum V_248 type )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_47 * V_203 = V_2 -> V_8 . V_13 [ V_14 ] ;
int V_12 ;
V_12 = F_141 ( & V_2 -> V_5 . V_118 , type ) ;
if ( V_12 == 0 )
F_138 ( & V_203 -> V_88 ) ;
return V_12 ;
}
static int F_142 ( struct V_125 * V_125 , void * V_186 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
int V_12 = F_143 ( & V_2 -> V_5 . V_118 , V_251 ) ;
if ( ! V_12 )
V_2 -> V_5 . V_83 = V_251 -> V_80 ;
return V_12 ;
}
static int F_144 ( struct V_125 * V_125 , void * V_186 ,
struct V_252 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_145 ( & V_2 -> V_5 . V_118 , V_30 ) ;
}
static int F_146 ( struct V_125 * V_125 , void * V_186 ,
struct V_252 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_147 ( & V_2 -> V_5 . V_118 , V_30 ) ;
}
static int F_148 ( struct V_125 * V_125 , void * V_186 ,
struct V_252 * V_30 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_149 ( & V_2 -> V_5 . V_118 , V_30 , V_125 -> V_253 & V_254 ) ;
}
static int F_150 ( struct V_125 * V_125 , void * V_186 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_151 ( & V_2 -> V_5 . V_118 , V_256 ) ;
}
static int F_152 ( struct V_125 * V_125 , void * V_186 ,
struct V_252 * V_257 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
return F_153 ( & V_2 -> V_5 . V_118 , V_257 ) ;
}
static int F_154 ( struct V_125 * V_125 , void * V_224 ,
struct V_258 * V_259 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
if ( V_259 -> type != V_260 )
return - V_18 ;
switch ( V_259 -> V_171 ) {
case V_261 :
case V_262 :
V_51 = & V_4 -> V_20 ;
case V_263 :
case V_264 :
V_259 -> V_170 . V_179 = 0 ;
V_259 -> V_170 . V_180 = 0 ;
V_259 -> V_170 . V_105 = V_51 -> V_265 ;
V_259 -> V_170 . V_106 = V_51 -> V_266 ;
return 0 ;
case V_181 :
V_51 = & V_4 -> V_20 ;
case V_267 :
V_259 -> V_170 . V_179 = V_51 -> V_165 ;
V_259 -> V_170 . V_180 = V_51 -> V_166 ;
V_259 -> V_170 . V_105 = V_51 -> V_105 ;
V_259 -> V_170 . V_106 = V_51 -> V_106 ;
return 0 ;
}
return - V_18 ;
}
static int F_155 ( struct V_169 * V_268 , struct V_169 * V_257 )
{
if ( V_268 -> V_179 < V_257 -> V_179 || V_268 -> V_180 < V_257 -> V_180 )
return 0 ;
if ( V_268 -> V_179 + V_268 -> V_105 > V_257 -> V_179 + V_257 -> V_105 )
return 0 ;
if ( V_268 -> V_180 + V_268 -> V_106 > V_257 -> V_180 + V_257 -> V_106 )
return 0 ;
return 1 ;
}
static int F_156 ( struct V_125 * V_125 , void * V_224 ,
struct V_258 * V_259 )
{
struct V_1 * V_2 = F_80 ( V_125 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_169 V_269 = V_259 -> V_170 ;
struct V_50 * V_51 ;
unsigned long V_11 ;
if ( V_259 -> type != V_260 )
return - V_18 ;
if ( V_259 -> V_171 == V_181 )
V_51 = & V_4 -> V_20 ;
else if ( V_259 -> V_171 == V_267 )
V_51 = & V_4 -> V_16 ;
else
return - V_18 ;
F_102 ( V_4 , & V_269 , V_259 -> V_171 ) ;
if ( V_259 -> V_11 & V_270 &&
! F_155 ( & V_269 , & V_259 -> V_170 ) )
return - V_271 ;
if ( V_259 -> V_11 & V_272 &&
! F_155 ( & V_259 -> V_170 , & V_269 ) )
return - V_271 ;
V_259 -> V_170 = V_269 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_125 ( V_51 , V_259 -> V_170 . V_179 , V_259 -> V_170 . V_180 , V_259 -> V_170 . V_105 ,
V_259 -> V_170 . V_106 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
return 0 ;
}
static int F_157 ( struct V_273 * V_88 ,
const struct V_238 * V_274 ,
const struct V_238 * V_275 , V_114 V_11 )
{
struct V_47 * V_203 = F_133 ( V_88 ) ;
struct V_1 * V_2 = F_158 ( V_203 ) ;
if ( F_134 ( V_275 -> V_88 ) != V_246 )
return - V_18 ;
if ( F_76 ( V_2 == NULL ) )
return 0 ;
F_43 ( L_9 ,
V_274 -> V_88 -> V_189 , V_275 -> V_88 -> V_189 , V_11 ,
V_2 -> V_5 . V_276 ) ;
if ( V_11 & V_277 ) {
if ( V_2 -> V_5 . V_276 != 0 )
return - V_126 ;
V_2 -> V_5 . V_276 = V_203 -> V_278 ;
return 0 ;
}
V_2 -> V_5 . V_276 = 0 ;
return 0 ;
}
void F_159 ( struct V_47 * V_203 , unsigned int V_279 ,
void * V_280 )
{
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_281 * V_282 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
if ( V_203 == NULL )
return;
V_10 = F_2 ( V_203 ) ;
V_282 = F_160 ( & V_203 -> V_88 ) ;
F_3 ( & V_282 -> V_19 , V_11 ) ;
V_2 = V_10 ? V_10 -> V_283 : NULL ;
if ( V_2 && V_280 && V_279 == V_284 &&
F_35 ( V_37 , & V_2 -> V_25 ) ) {
unsigned long V_285 ;
F_3 ( & V_2 -> V_19 , V_285 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_41 ) ) {
V_30 = F_161 ( V_2 -> V_5 . V_41 . V_286 ,
struct V_29 , V_287 ) ;
F_66 ( & V_30 -> V_39 , 0 , * ( ( V_114 * ) V_280 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_19 , V_285 ) ;
}
F_21 ( & V_282 -> V_19 , V_11 ) ;
}
static int F_162 ( struct V_47 * V_203 ,
struct V_288 * V_224 ,
struct V_289 * V_139 )
{
struct V_99 * V_17 ;
V_17 = F_59 ( NULL , NULL , V_103 , V_139 -> V_68 ) ;
if ( ! V_17 )
return - V_18 ;
V_139 -> V_139 = V_17 -> V_156 ;
return 0 ;
}
static int F_163 ( struct V_47 * V_203 ,
struct V_288 * V_224 ,
struct V_204 * V_17 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_199 * V_206 ;
struct V_50 * V_232 ;
if ( V_17 -> V_208 == V_210 ) {
V_206 = F_164 ( V_224 , V_17 -> V_141 ) ;
V_17 -> V_207 = * V_206 ;
return 0 ;
}
V_206 = & V_17 -> V_207 ;
V_206 -> V_290 = V_291 ;
V_232 = V_17 -> V_141 == V_158 ? & V_4 -> V_16 : & V_4 -> V_20 ;
F_72 ( & V_2 -> V_119 ) ;
if ( ! F_76 ( V_4 -> V_16 . V_17 == NULL ) )
V_206 -> V_139 = V_4 -> V_16 . V_17 -> V_156 ;
V_206 -> V_105 = V_232 -> V_107 ;
V_206 -> V_106 = V_232 -> V_108 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_165 ( struct V_47 * V_203 ,
struct V_288 * V_224 ,
struct V_204 * V_17 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
struct V_199 * V_206 = & V_17 -> V_207 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_232 ;
struct V_99 * V_154 ;
F_43 ( L_10 ,
V_17 -> V_141 , V_206 -> V_139 , V_206 -> V_105 , V_206 -> V_106 ) ;
if ( V_17 -> V_141 == V_155 &&
F_122 ( & V_2 -> V_5 . V_118 ) )
return - V_126 ;
F_72 ( & V_2 -> V_119 ) ;
V_154 = F_97 ( V_4 , & V_206 -> V_105 , & V_206 -> V_106 ,
& V_206 -> V_139 , NULL , V_17 -> V_141 ) ;
F_74 ( & V_2 -> V_119 ) ;
V_206 -> V_290 = V_291 ;
if ( V_17 -> V_208 == V_210 ) {
V_206 = F_164 ( V_224 , V_17 -> V_141 ) ;
* V_206 = V_17 -> V_207 ;
return 0 ;
}
F_123 ( V_4 ) ;
F_119 ( V_4 , V_154 -> V_113 ) ;
V_232 = V_17 -> V_141 == V_158 ?
& V_4 -> V_16 : & V_4 -> V_20 ;
F_72 ( & V_2 -> V_119 ) ;
F_124 ( V_232 , V_206 -> V_105 , V_206 -> V_106 ) ;
V_2 -> V_5 . V_206 = * V_206 ;
V_232 -> V_17 = V_154 ;
if ( ! ( V_17 -> V_141 == V_155 && ( V_4 -> V_25 & V_164 ) ) )
F_125 ( V_232 , 0 , 0 , V_206 -> V_105 , V_206 -> V_106 ) ;
if ( V_17 -> V_141 == V_158 )
V_4 -> V_25 &= ~ V_164 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_166 ( struct V_47 * V_203 ,
struct V_288 * V_224 ,
struct V_292 * V_293 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
struct V_169 * V_170 = & V_293 -> V_170 ;
struct V_169 * V_294 ;
if ( V_293 -> V_141 != V_158 )
return - V_18 ;
F_72 ( & V_2 -> V_119 ) ;
switch ( V_293 -> V_171 ) {
case V_262 :
V_51 = & V_4 -> V_20 ;
case V_263 :
V_170 -> V_105 = V_51 -> V_265 ;
V_170 -> V_106 = V_51 -> V_266 ;
V_170 -> V_179 = 0 ;
V_170 -> V_180 = 0 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
case V_267 :
V_294 = F_167 ( V_224 , V_293 -> V_141 ) ;
break;
case V_181 :
V_294 = F_168 ( V_224 , V_293 -> V_141 ) ;
V_51 = & V_4 -> V_20 ;
break;
default:
F_74 ( & V_2 -> V_119 ) ;
return - V_18 ;
}
if ( V_293 -> V_208 == V_210 ) {
V_293 -> V_170 = * V_294 ;
} else {
V_170 -> V_179 = V_51 -> V_165 ;
V_170 -> V_180 = V_51 -> V_166 ;
V_170 -> V_105 = V_51 -> V_105 ;
V_170 -> V_106 = V_51 -> V_106 ;
}
F_43 ( L_11 ,
V_293 -> V_141 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ,
V_51 -> V_107 , V_51 -> V_108 ) ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_169 ( struct V_47 * V_203 ,
struct V_288 * V_224 ,
struct V_292 * V_293 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_51 = & V_4 -> V_16 ;
struct V_169 * V_170 = & V_293 -> V_170 ;
struct V_169 * V_294 ;
unsigned long V_11 ;
if ( V_293 -> V_141 != V_158 )
return - V_18 ;
F_72 ( & V_2 -> V_119 ) ;
F_102 ( V_4 , V_170 , V_267 ) ;
switch ( V_293 -> V_171 ) {
case V_262 :
V_51 = & V_4 -> V_20 ;
case V_263 :
V_170 -> V_105 = V_51 -> V_265 ;
V_170 -> V_106 = V_51 -> V_266 ;
V_170 -> V_179 = 0 ;
V_170 -> V_180 = 0 ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
case V_267 :
V_294 = F_167 ( V_224 , V_293 -> V_141 ) ;
break;
case V_181 :
V_294 = F_168 ( V_224 , V_293 -> V_141 ) ;
V_51 = & V_4 -> V_20 ;
break;
default:
F_74 ( & V_2 -> V_119 ) ;
return - V_18 ;
}
if ( V_293 -> V_208 == V_210 ) {
* V_294 = V_293 -> V_170 ;
} else {
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_125 ( V_51 , V_170 -> V_179 , V_170 -> V_180 , V_170 -> V_105 , V_170 -> V_106 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( V_293 -> V_171 == V_181 )
V_4 -> V_25 |= V_164 ;
}
F_43 ( L_12 , V_293 -> V_171 , V_170 -> V_179 , V_170 -> V_180 ,
V_170 -> V_105 , V_170 -> V_106 ) ;
F_74 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_90 V_17 = {
. type = V_260 ,
. V_17 . V_101 = {
. V_105 = 640 ,
. V_106 = 480 ,
. V_102 = V_295 ,
. V_296 = V_297 ,
. V_290 = V_291 ,
} ,
} ;
return F_121 ( V_2 , & V_17 ) ;
}
static int F_170 ( struct V_1 * V_2 ,
struct V_298 * V_223 )
{
struct V_299 * V_87 = & V_2 -> V_5 . V_87 ;
struct V_27 * V_5 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_12 = - V_300 ;
V_4 = F_171 ( sizeof( * V_4 ) , V_301 ) ;
if ( ! V_4 )
return - V_300 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_302 = V_303 ;
V_4 -> V_304 = V_305 ;
V_4 -> V_25 = V_306 ;
V_4 -> V_16 . V_17 = F_59 ( NULL , NULL , V_103 , 0 ) ;
V_4 -> V_20 . V_17 = V_4 -> V_16 . V_17 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
snprintf ( V_87 -> V_189 , sizeof( V_87 -> V_189 ) , L_13 , V_2 -> V_307 ) ;
V_87 -> V_308 = & V_309 ;
V_87 -> V_310 = & V_311 ;
V_87 -> V_223 = V_223 ;
V_87 -> V_312 = - 1 ;
V_87 -> V_313 = V_314 ;
V_87 -> V_119 = & V_2 -> V_119 ;
F_172 ( V_87 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_77 = 0 ;
V_5 -> V_83 = 0 ;
V_5 -> V_133 = 0 ;
F_56 ( & V_5 -> V_38 ) ;
F_56 ( & V_5 -> V_41 ) ;
V_5 -> V_4 = V_4 ;
V_79 = & V_2 -> V_5 . V_118 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_260 ;
V_79 -> V_315 = V_316 | V_317 ;
V_79 -> V_81 = V_2 -> V_5 . V_4 ;
V_79 -> V_318 = & V_319 ;
V_79 -> V_320 = & V_321 ;
V_79 -> V_322 = sizeof( struct V_29 ) ;
V_12 = F_173 ( V_79 ) ;
if ( V_12 )
goto V_323;
V_5 -> V_239 . V_11 = V_242 ;
V_12 = F_174 ( & V_87 -> V_88 , 1 , & V_5 -> V_239 , 0 ) ;
if ( V_12 )
goto V_323;
V_12 = F_175 ( V_87 , V_324 , - 1 ) ;
if ( V_12 )
goto V_325;
F_176 ( V_223 , L_14 ,
V_87 -> V_189 , F_177 ( V_87 ) ) ;
V_87 -> V_124 = & V_4 -> V_120 . V_123 ;
return 0 ;
V_325:
F_178 ( & V_87 -> V_88 ) ;
V_323:
F_179 ( V_4 ) ;
return V_12 ;
}
static int F_180 ( struct V_47 * V_203 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
int V_12 ;
if ( V_2 == NULL )
return - V_15 ;
V_12 = F_181 ( V_2 , V_203 -> V_223 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_326 = F_2 ( V_203 ) ;
V_12 = F_170 ( V_2 , V_203 -> V_223 ) ;
if ( V_12 ) {
F_182 ( V_2 ) ;
V_2 -> V_326 = NULL ;
}
return V_12 ;
}
static void F_183 ( struct V_47 * V_203 )
{
struct V_1 * V_2 = F_158 ( V_203 ) ;
if ( V_2 == NULL )
return;
F_182 ( V_2 ) ;
if ( F_184 ( & V_2 -> V_5 . V_87 ) ) {
F_185 ( & V_2 -> V_5 . V_87 ) ;
F_178 ( & V_2 -> V_5 . V_87 . V_88 ) ;
V_2 -> V_326 = NULL ;
}
F_179 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
int F_186 ( struct V_1 * V_2 )
{
struct V_47 * V_203 = & V_2 -> V_5 . V_243 ;
int V_12 ;
F_187 ( V_203 , & V_327 ) ;
V_203 -> V_11 = V_328 ;
snprintf ( V_203 -> V_189 , sizeof( V_203 -> V_189 ) , L_15 , V_2 -> V_131 -> V_307 ) ;
V_2 -> V_5 . V_329 [ V_158 ] . V_11 = V_242 ;
V_2 -> V_5 . V_329 [ V_155 ] . V_11 = V_330 ;
V_12 = F_174 ( & V_203 -> V_88 , V_331 ,
V_2 -> V_5 . V_329 , 0 ) ;
if ( V_12 )
return V_12 ;
V_203 -> V_88 . V_318 = & V_332 ;
V_203 -> V_333 = & V_334 ;
F_188 ( V_203 , V_2 ) ;
return 0 ;
}
void F_189 ( struct V_1 * V_2 )
{
struct V_47 * V_203 = & V_2 -> V_5 . V_243 ;
F_190 ( V_203 ) ;
F_178 ( & V_203 -> V_88 ) ;
F_188 ( V_203 , NULL ) ;
}
