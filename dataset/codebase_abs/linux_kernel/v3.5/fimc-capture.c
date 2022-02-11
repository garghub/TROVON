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
F_6 ( V_2 , V_10 -> V_21 ) ;
F_7 ( V_2 , V_10 -> V_21 ) ;
F_8 ( V_2 , V_10 -> V_21 ) ;
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
return F_29 ( & V_2 -> V_8 , 0 ) ;
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
F_34 ( V_2 -> V_43 ,
! F_35 ( V_34 , & V_2 -> V_25 ) ,
( 2 * V_44 / 10 ) ) ;
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
void F_37 ( struct V_1 * V_2 , int V_45 )
{
struct V_27 * V_28 = & V_2 -> V_5 ;
struct V_29 * V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
if ( F_38 ( V_34 , & V_2 -> V_25 ) ) {
F_39 ( & V_2 -> V_43 ) ;
goto V_51;
}
if ( ! F_23 ( & V_28 -> V_41 ) &&
F_35 ( V_33 , & V_2 -> V_25 ) && V_45 ) {
F_40 ( & V_50 ) ;
V_46 = F_26 ( V_28 ) ;
V_48 = & V_46 -> V_39 . V_52 . V_53 ;
V_48 -> V_54 = V_50 . V_54 ;
V_48 -> V_55 = V_50 . V_56 / V_57 ;
V_46 -> V_39 . V_52 . V_58 = V_28 -> V_59 ++ ;
F_25 ( & V_46 -> V_39 , V_60 ) ;
}
if ( ! F_23 ( & V_28 -> V_38 ) ) {
V_46 = F_24 ( V_28 ) ;
F_41 ( V_2 , & V_46 -> V_61 , V_28 -> V_42 ) ;
V_46 -> V_62 = V_28 -> V_42 ;
F_42 ( V_28 , V_46 ) ;
F_43 ( L_1 ,
F_44 ( V_2 ) , V_46 -> V_62 ) ;
if ( ++ V_28 -> V_42 >= V_63 )
V_28 -> V_42 = 0 ;
}
if ( V_28 -> V_64 == 0 ) {
if ( V_45 )
F_20 ( V_33 , & V_2 -> V_25 ) ;
if ( ++ V_28 -> V_42 >= V_63 )
V_28 -> V_42 = 0 ;
} else {
F_32 ( V_33 , & V_2 -> V_25 ) ;
}
if ( F_35 ( V_24 , & V_2 -> V_25 ) )
F_36 ( V_28 -> V_4 ) ;
V_51:
if ( V_28 -> V_64 == 1 ) {
F_33 ( V_2 ) ;
F_20 ( V_35 , & V_2 -> V_25 ) ;
}
F_43 ( L_2 ,
F_44 ( V_2 ) , V_28 -> V_64 ) ;
}
static int F_45 ( struct V_65 * V_66 , unsigned int V_67 )
{
struct V_3 * V_4 = V_66 -> V_68 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
int V_69 ;
int V_12 ;
V_5 -> V_59 = 0 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_22 ( V_2 , false ) ;
return V_12 ;
}
F_32 ( V_37 , & V_2 -> V_25 ) ;
V_69 = V_2 -> V_5 . V_70 > 1 ? 2 : 1 ;
if ( V_5 -> V_64 >= V_69 &&
! F_46 ( V_35 , & V_2 -> V_25 ) ) {
F_47 ( V_4 ) ;
if ( ! F_46 ( V_32 , & V_2 -> V_25 ) )
F_29 ( & V_2 -> V_8 , 1 ) ;
}
return 0 ;
}
static int F_48 ( struct V_65 * V_66 )
{
struct V_3 * V_4 = V_66 -> V_68 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_31 ( V_2 ) )
return - V_18 ;
return F_30 ( V_2 , false ) ;
}
int F_49 ( struct V_1 * V_2 )
{
bool V_26 = F_50 ( V_2 ) ;
int V_12 = F_30 ( V_2 , V_26 ) ;
if ( V_12 )
return V_12 ;
return F_51 ( & V_2 -> V_8 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_29 * V_30 ;
int V_71 ;
if ( ! F_38 ( V_36 , & V_2 -> V_25 ) )
return 0 ;
F_53 ( & V_2 -> V_5 . V_41 ) ;
V_5 -> V_42 = 0 ;
F_54 ( & V_2 -> V_8 , & V_5 -> V_72 -> V_73 ,
false ) ;
F_1 ( V_2 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
for ( V_71 = 0 ; V_71 < V_5 -> V_70 ; V_71 ++ ) {
if ( F_23 ( & V_5 -> V_38 ) )
break;
V_30 = F_24 ( V_5 ) ;
F_55 ( & V_30 -> V_39 ) ;
}
return 0 ;
}
static int F_56 ( struct V_65 * V_74 , const struct V_75 * V_76 ,
unsigned int * V_77 , unsigned int * V_78 ,
unsigned int V_79 [] , void * V_80 [] )
{
const struct V_81 * V_82 = NULL ;
struct V_3 * V_4 = V_74 -> V_68 ;
struct V_83 * V_84 = & V_4 -> V_20 ;
struct V_85 * V_17 = V_84 -> V_17 ;
unsigned long V_86 ;
int V_71 ;
if ( V_76 ) {
V_82 = & V_76 -> V_17 . V_87 ;
V_17 = F_57 ( & V_82 -> V_88 , NULL ,
V_89 | V_90 , - 1 ) ;
V_86 = V_82 -> V_91 * V_82 -> V_92 ;
} else {
V_86 = V_84 -> V_93 * V_84 -> V_94 ;
}
if ( V_17 == NULL )
return - V_18 ;
* V_78 = V_17 -> V_95 ;
for ( V_71 = 0 ; V_71 < V_17 -> V_95 ; V_71 ++ ) {
unsigned int V_96 = ( V_86 * V_17 -> V_97 [ V_71 ] ) / 8 ;
if ( V_82 )
V_79 [ V_71 ] = F_58 ( V_96 , V_82 -> V_98 [ V_71 ] . V_99 ) ;
else
V_79 [ V_71 ] = F_59 ( V_100 , V_96 , V_84 -> V_101 [ V_71 ] ) ;
V_80 [ V_71 ] = V_4 -> V_1 -> V_102 ;
}
return 0 ;
}
static int F_60 ( struct V_103 * V_39 )
{
struct V_65 * V_74 = V_39 -> V_65 ;
struct V_3 * V_4 = V_74 -> V_68 ;
int V_71 ;
if ( V_4 -> V_20 . V_17 == NULL )
return - V_18 ;
for ( V_71 = 0 ; V_71 < V_4 -> V_20 . V_17 -> V_95 ; V_71 ++ ) {
unsigned long V_96 = V_4 -> V_20 . V_101 [ V_71 ] ;
if ( F_61 ( V_39 , V_71 ) < V_96 ) {
F_62 ( V_4 -> V_1 -> V_5 . V_72 ,
L_3 ,
F_61 ( V_39 , V_71 ) , V_96 ) ;
return - V_18 ;
}
F_63 ( V_39 , V_71 , V_96 ) ;
}
return 0 ;
}
static void F_55 ( struct V_103 * V_39 )
{
struct V_29 * V_30
= F_64 ( V_39 , struct V_29 , V_39 ) ;
struct V_3 * V_4 = F_65 ( V_39 -> V_65 ) ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
unsigned long V_11 ;
int V_69 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_66 ( V_4 , & V_30 -> V_39 , & V_4 -> V_20 , & V_30 -> V_61 ) ;
if ( ! F_35 ( V_36 , & V_2 -> V_25 ) &&
! F_35 ( V_35 , & V_2 -> V_25 ) &&
V_5 -> V_64 < V_63 ) {
int V_104 = ( V_5 -> V_70 == 1 ) ? - 1 :
V_5 -> V_42 ;
F_41 ( V_2 , & V_30 -> V_61 , V_104 ) ;
V_30 -> V_62 = V_5 -> V_42 ;
F_42 ( V_5 , V_30 ) ;
if ( ++ V_5 -> V_42 >= V_63 )
V_5 -> V_42 = 0 ;
} else {
F_27 ( V_5 , V_30 ) ;
}
V_69 = V_5 -> V_70 > 1 ? 2 : 1 ;
if ( F_67 ( & V_5 -> V_105 ) &&
V_5 -> V_64 >= V_69 &&
! F_46 ( V_35 , & V_2 -> V_25 ) ) {
F_47 ( V_4 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( ! F_46 ( V_32 , & V_2 -> V_25 ) )
F_29 ( & V_2 -> V_8 , 1 ) ;
return;
}
F_21 ( & V_2 -> V_19 , V_11 ) ;
}
static void F_68 ( struct V_65 * V_74 )
{
struct V_3 * V_4 = F_65 ( V_74 ) ;
F_69 ( & V_4 -> V_1 -> V_106 ) ;
}
static void F_70 ( struct V_65 * V_74 )
{
struct V_3 * V_4 = F_65 ( V_74 ) ;
F_71 ( & V_4 -> V_1 -> V_106 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_27 * V_5 = & V_2 -> V_5 ;
int V_12 ;
if ( F_73 ( V_5 -> V_4 == NULL ) )
return - V_15 ;
if ( V_5 -> V_4 -> V_107 . V_108 )
return 0 ;
V_12 = F_74 ( V_5 -> V_4 ) ;
if ( V_12 || V_5 -> V_109 || ! V_5 -> V_4 -> V_107 . V_108 )
return V_12 ;
return F_75 ( & V_5 -> V_4 -> V_107 . V_110 ,
V_2 -> V_8 . V_13 [ V_14 ] -> V_111 ) ;
}
static int F_76 ( struct V_112 * V_112 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 ;
F_43 ( L_4 , F_78 ( V_113 ) , V_2 -> V_25 ) ;
if ( F_79 ( V_2 ) )
return - V_114 ;
F_32 ( V_115 , & V_2 -> V_25 ) ;
V_12 = F_80 ( & V_2 -> V_116 -> V_117 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_81 ( V_112 ) ;
if ( V_12 )
return V_12 ;
if ( ++ V_2 -> V_5 . V_118 != 1 )
return 0 ;
V_12 = F_54 ( & V_2 -> V_8 ,
& V_2 -> V_5 . V_72 -> V_73 , true ) ;
if ( V_12 < 0 ) {
F_20 ( V_115 , & V_2 -> V_25 ) ;
F_82 ( & V_2 -> V_116 -> V_117 ) ;
V_2 -> V_5 . V_118 -- ;
F_83 ( V_112 ) ;
return V_12 ;
}
V_12 = F_72 ( V_2 ) ;
if ( ! V_12 && ! V_2 -> V_5 . V_109 )
V_12 = F_84 ( V_2 ) ;
return V_12 ;
}
static int F_85 ( struct V_112 * V_112 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
F_43 ( L_4 , F_78 ( V_113 ) , V_2 -> V_25 ) ;
if ( -- V_2 -> V_5 . V_118 == 0 ) {
F_20 ( V_115 , & V_2 -> V_25 ) ;
F_30 ( V_2 , false ) ;
F_51 ( & V_2 -> V_8 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
}
F_86 ( & V_2 -> V_116 -> V_117 ) ;
if ( V_2 -> V_5 . V_118 == 0 ) {
F_87 ( & V_2 -> V_5 . V_105 ) ;
F_88 ( V_2 -> V_5 . V_4 ) ;
}
return F_83 ( V_112 ) ;
}
static unsigned int F_89 ( struct V_112 * V_112 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_90 ( & V_2 -> V_5 . V_105 , V_112 , V_120 ) ;
}
static int F_91 ( struct V_112 * V_112 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_92 ( & V_2 -> V_5 . V_105 , V_122 ) ;
}
static struct V_85 * F_93 ( struct V_3 * V_4 ,
V_100 * V_91 , V_100 * V_92 ,
V_100 * V_123 , V_100 * V_124 , int V_125 )
{
bool V_126 = V_4 -> V_126 == 90 || V_4 -> V_126 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_127 * V_128 = V_2 -> V_22 ;
struct V_129 * V_130 = V_128 -> V_131 ;
struct V_83 * V_132 = & V_4 -> V_20 ;
V_100 V_97 , V_133 , V_134 , V_135 , V_136 = 3 ;
V_100 V_137 = V_89 ;
struct V_85 * V_138 ;
if ( V_123 && V_4 -> V_16 . V_17 && V_125 == V_139 &&
F_94 ( V_4 -> V_16 . V_17 -> V_140 ) )
* V_123 = V_141 ;
if ( V_124 && * V_124 != V_142 && V_125 != V_143 )
V_137 |= V_90 ;
V_138 = F_57 ( V_124 , V_123 , V_137 , 0 ) ;
if ( F_73 ( ! V_138 ) )
return NULL ;
if ( V_123 )
* V_123 = V_138 -> V_144 ;
if ( V_124 )
* V_124 = V_138 -> V_124 ;
if ( V_125 == V_143 ) {
V_134 = F_94 ( V_138 -> V_140 ) ?
V_130 -> V_145 : V_130 -> V_146 ;
F_95 ( V_91 , F_59 ( V_100 , * V_91 , 32 ) , V_134 , 4 ,
V_92 , F_59 ( V_100 , * V_92 , 32 ) ,
V_147 ,
F_94 ( V_138 -> V_140 ) ? 3 : 1 ,
0 ) ;
return V_138 ;
}
if ( F_94 ( V_138 -> V_140 ) ) {
* V_91 = V_4 -> V_16 . V_93 ;
* V_92 = V_4 -> V_16 . V_94 ;
return V_138 ;
}
V_134 = V_126 ? V_130 -> V_148 : V_130 -> V_149 ;
if ( V_4 -> V_25 & V_150 ) {
V_133 = V_132 -> V_151 + V_132 -> V_91 ;
V_135 = V_132 -> V_152 + V_132 -> V_92 ;
} else {
V_133 = V_128 -> V_153 ;
V_135 = V_128 -> V_153 ;
}
if ( V_128 -> V_154 == 1 && ! V_126 )
V_136 = F_96 ( V_138 -> V_140 ) ? 0 : 1 ;
V_97 = F_97 ( V_138 ) ;
F_95 ( V_91 , V_133 , V_134 ,
F_98 ( V_128 -> V_153 ) - 1 ,
V_92 , V_135 , V_147 ,
V_136 ,
64 / ( F_99 ( V_97 , 8 ) ) ) ;
F_43 ( L_5 ,
V_125 , V_123 ? * V_123 : 0 , * V_91 , * V_92 ,
V_132 -> V_93 , V_132 -> V_94 ) ;
return V_138 ;
}
static void F_100 ( struct V_3 * V_4 ,
struct V_155 * V_156 ,
int V_157 )
{
bool V_158 = V_4 -> V_126 == 90 || V_4 -> V_126 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_127 * V_128 = V_2 -> V_22 ;
struct V_129 * V_130 = V_128 -> V_131 ;
struct V_83 * V_159 = & V_4 -> V_16 ;
V_100 V_134 , V_160 , V_133 = 0 , V_135 = 0 , V_161 ;
V_100 V_162 = 0 , V_136 = 4 ;
V_100 V_163 , V_164 ;
if ( F_94 ( V_4 -> V_20 . V_17 -> V_140 ) ) {
V_156 -> V_91 = V_159 -> V_93 ;
V_156 -> V_92 = V_159 -> V_94 ;
V_156 -> V_165 = V_156 -> V_166 = 0 ;
return;
}
if ( V_157 == V_167 ) {
if ( V_4 -> V_126 != 90 && V_4 -> V_126 != 270 )
V_136 = 1 ;
V_163 = F_101 ( V_168 , 1 << ( F_98 ( V_159 -> V_91 ) - 3 ) ) ;
V_164 = F_101 ( V_169 , 1 << ( F_98 ( V_159 -> V_92 ) - 1 ) ) ;
V_161 = V_128 -> V_153 ;
} else {
V_100 V_97 = F_97 ( V_159 -> V_17 ) ;
V_162 = 64 / F_99 ( V_97 , 8 ) ;
V_161 = V_128 -> V_170 ;
V_133 = V_135 = V_161 ;
V_163 = V_164 = 1 ;
}
V_134 = F_102 ( V_100 ,
V_158 ? V_130 -> V_148 : V_130 -> V_149 ,
V_158 ? V_159 -> V_94 : V_159 -> V_93 ) ;
V_160 = F_102 ( V_100 , V_147 , V_159 -> V_94 ) ;
if ( V_157 == V_167 ) {
V_133 = F_102 ( V_100 , V_134 , V_159 -> V_93 / V_163 ) ;
V_135 = F_102 ( V_100 , V_160 , V_159 -> V_94 / V_164 ) ;
if ( V_158 ) {
F_103 ( V_163 , V_164 ) ;
F_103 ( V_133 , V_135 ) ;
}
}
F_95 ( & V_156 -> V_91 , V_133 , V_134 , F_98 ( V_161 ) - 1 ,
& V_156 -> V_92 , V_135 , V_160 , V_136 ,
V_162 ) ;
V_156 -> V_165 = F_104 ( V_100 , V_156 -> V_165 , 0 , V_159 -> V_93 - V_156 -> V_91 ) ;
V_156 -> V_166 = F_104 ( V_100 , V_156 -> V_166 , 0 , V_159 -> V_94 - V_156 -> V_92 ) ;
V_156 -> V_165 = F_105 ( V_156 -> V_165 , V_128 -> V_171 ) ;
F_43 ( L_6 ,
V_157 , V_156 -> V_165 , V_156 -> V_166 , V_156 -> V_91 , V_156 -> V_92 ,
V_159 -> V_93 , V_159 -> V_94 ) ;
}
static int F_106 ( struct V_112 * V_112 , void * V_172 ,
struct V_173 * V_28 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
strncpy ( V_28 -> V_174 , V_2 -> V_116 -> V_175 , sizeof( V_28 -> V_174 ) - 1 ) ;
strncpy ( V_28 -> V_176 , V_2 -> V_116 -> V_175 , sizeof( V_28 -> V_176 ) - 1 ) ;
V_28 -> V_177 [ 0 ] = 0 ;
V_28 -> V_178 = V_179 | V_180 ;
return 0 ;
}
static int F_107 ( struct V_112 * V_112 , void * V_172 ,
struct V_181 * V_182 )
{
struct V_85 * V_17 ;
V_17 = F_57 ( NULL , NULL , V_89 | V_90 ,
V_182 -> V_62 ) ;
if ( ! V_17 )
return - V_18 ;
strncpy ( V_182 -> V_183 , V_17 -> V_175 , sizeof( V_182 -> V_183 ) - 1 ) ;
V_182 -> V_88 = V_17 -> V_124 ;
if ( V_17 -> V_124 == V_141 )
V_182 -> V_11 |= V_184 ;
return 0 ;
}
static int F_108 ( struct V_3 * V_4 ,
struct V_185 * V_186 ,
struct V_85 * * V_187 ,
bool V_188 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_189 * V_190 = V_2 -> V_8 . V_13 [ V_14 ] ;
struct V_189 * V_191 = V_2 -> V_8 . V_13 [ V_192 ] ;
struct V_193 V_194 ;
struct V_185 * V_195 = & V_194 . V_196 ;
struct V_85 * V_138 = NULL ;
int V_12 , V_71 = 0 ;
if ( F_73 ( ! V_190 || ! V_186 ) )
return - V_18 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_196 = * V_186 ;
V_194 . V_197 = V_188 ? V_198 : V_199 ;
while ( 1 ) {
V_138 = F_57 ( NULL , V_195 -> V_123 != 0 ? & V_195 -> V_123 : NULL ,
V_89 , V_71 ++ ) ;
if ( V_138 == NULL ) {
return - V_18 ;
}
V_195 -> V_123 = V_186 -> V_123 = V_138 -> V_144 ;
V_12 = F_109 ( V_190 , V_125 , V_200 , NULL , & V_194 ) ;
if ( V_12 )
return V_12 ;
if ( V_195 -> V_123 != V_186 -> V_123 ) {
V_195 -> V_123 = 0 ;
continue;
}
if ( V_195 -> V_91 != V_186 -> V_91 || V_195 -> V_92 != V_186 -> V_92 ) {
V_100 V_201 = V_138 -> V_124 ;
V_186 -> V_91 = V_195 -> V_91 ;
V_186 -> V_92 = V_195 -> V_92 ;
V_138 = F_93 ( V_4 ,
& V_186 -> V_91 , & V_186 -> V_92 ,
NULL , & V_201 , V_139 ) ;
if ( V_138 && V_138 -> V_144 )
V_195 -> V_123 = V_138 -> V_144 ;
if ( V_195 -> V_91 != V_186 -> V_91 ||
V_195 -> V_92 != V_186 -> V_92 )
continue;
V_186 -> V_123 = V_195 -> V_123 ;
}
if ( V_191 )
V_12 = F_109 ( V_191 , V_125 , V_200 , NULL , & V_194 ) ;
if ( V_195 -> V_123 == V_186 -> V_123 &&
V_195 -> V_91 == V_186 -> V_91 && V_195 -> V_92 == V_186 -> V_92 )
break;
}
if ( V_187 && V_138 )
* V_187 = V_138 ;
* V_186 = * V_195 ;
F_43 ( L_7 , V_195 -> V_123 , V_195 -> V_91 , V_195 -> V_92 , V_138 ) ;
return 0 ;
}
static int F_110 ( struct V_112 * V_112 , void * V_202 ,
struct V_75 * V_182 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
return F_111 ( & V_4 -> V_20 , V_182 ) ;
}
static int F_112 ( struct V_112 * V_112 , void * V_202 ,
struct V_75 * V_182 )
{
struct V_81 * V_203 = & V_182 -> V_17 . V_87 ;
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_185 V_195 ;
struct V_85 * V_138 = NULL ;
if ( V_203 -> V_88 == V_142 ) {
F_93 ( V_4 , & V_203 -> V_91 , & V_203 -> V_92 ,
NULL , & V_203 -> V_88 ,
V_143 ) ;
V_4 -> V_16 . V_93 = V_203 -> V_91 ;
V_4 -> V_16 . V_94 = V_203 -> V_92 ;
}
V_138 = F_93 ( V_4 , & V_203 -> V_91 , & V_203 -> V_92 ,
NULL , & V_203 -> V_88 ,
V_139 ) ;
if ( ! V_138 )
return - V_18 ;
if ( ! V_2 -> V_5 . V_109 ) {
V_195 . V_91 = V_203 -> V_91 ;
V_195 . V_92 = V_203 -> V_92 ;
V_195 . V_123 = V_138 -> V_144 ;
F_113 ( V_2 ) ;
F_108 ( V_4 , & V_195 , & V_138 , false ) ;
F_114 ( V_2 ) ;
V_203 -> V_91 = V_195 . V_91 ;
V_203 -> V_92 = V_195 . V_92 ;
if ( V_138 )
V_203 -> V_88 = V_138 -> V_124 ;
}
F_115 ( V_138 , V_203 -> V_91 , V_203 -> V_92 , V_203 ) ;
return 0 ;
}
static void F_116 ( struct V_3 * V_4 , bool V_204 )
{
V_4 -> V_205 . V_206 = ! V_204 ;
F_117 ( V_4 , ! V_204 ) ;
if ( V_204 )
F_32 ( V_207 , & V_4 -> V_1 -> V_25 ) ;
else
F_20 ( V_207 , & V_4 -> V_1 -> V_25 ) ;
}
static int F_118 ( struct V_1 * V_2 , struct V_75 * V_182 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_81 * V_203 = & V_182 -> V_17 . V_87 ;
struct V_185 * V_195 = & V_2 -> V_5 . V_195 ;
struct V_83 * V_208 = & V_4 -> V_20 ;
struct V_85 * V_209 = NULL ;
int V_12 , V_71 ;
if ( F_119 ( & V_2 -> V_5 . V_105 ) )
return - V_114 ;
if ( V_203 -> V_88 == V_142 ) {
F_93 ( V_4 , & V_203 -> V_91 , & V_203 -> V_92 ,
NULL , & V_203 -> V_88 ,
V_143 ) ;
V_4 -> V_16 . V_93 = V_203 -> V_91 ;
V_4 -> V_16 . V_94 = V_203 -> V_92 ;
}
V_208 -> V_17 = F_93 ( V_4 , & V_203 -> V_91 , & V_203 -> V_92 ,
NULL , & V_203 -> V_88 ,
V_139 ) ;
if ( ! V_208 -> V_17 )
return - V_18 ;
F_120 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_109 ) {
V_195 -> V_123 = V_208 -> V_17 -> V_144 ;
V_195 -> V_91 = V_203 -> V_91 ;
V_195 -> V_92 = V_203 -> V_92 ;
F_113 ( V_2 ) ;
V_12 = F_108 ( V_4 , V_195 , & V_209 , true ) ;
F_114 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_203 -> V_91 = V_195 -> V_91 ;
V_203 -> V_92 = V_195 -> V_92 ;
}
F_115 ( V_208 -> V_17 , V_203 -> V_91 , V_203 -> V_92 , V_203 ) ;
for ( V_71 = 0 ; V_71 < V_208 -> V_17 -> V_210 ; V_71 ++ )
V_208 -> V_101 [ V_71 ] = V_203 -> V_98 [ V_71 ] . V_99 ;
F_121 ( V_208 , V_203 -> V_91 , V_203 -> V_92 ) ;
if ( ! ( V_4 -> V_25 & V_150 ) )
F_122 ( V_208 , 0 , 0 , V_203 -> V_91 , V_203 -> V_92 ) ;
F_116 ( V_4 , F_94 ( V_208 -> V_17 -> V_140 ) ) ;
if ( ! V_2 -> V_5 . V_109 ) {
V_4 -> V_16 . V_17 = V_209 ;
F_121 ( & V_4 -> V_16 , V_203 -> V_91 , V_203 -> V_92 ) ;
F_122 ( & V_4 -> V_16 , 0 , 0 , V_203 -> V_91 , V_203 -> V_92 ) ;
}
return V_12 ;
}
static int F_123 ( struct V_112 * V_112 , void * V_172 ,
struct V_75 * V_182 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_118 ( V_2 , V_182 ) ;
}
static int F_124 ( struct V_112 * V_112 , void * V_172 ,
struct V_211 * V_71 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_189 * V_190 = V_2 -> V_8 . V_13 [ V_14 ] ;
if ( V_71 -> V_62 != 0 )
return - V_18 ;
V_71 -> type = V_212 ;
if ( V_190 )
F_125 ( V_71 -> V_175 , V_190 -> V_175 , sizeof( V_71 -> V_175 ) ) ;
return 0 ;
}
static int F_126 ( struct V_112 * V_112 , void * V_172 , unsigned int V_71 )
{
return V_71 == 0 ? V_71 : - V_18 ;
}
static int F_127 ( struct V_112 * V_112 , void * V_172 , unsigned int * V_71 )
{
* V_71 = 0 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_193 V_213 , V_214 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_189 * V_190 ;
struct V_215 * V_125 ;
int V_12 ;
V_125 = F_129 ( & V_5 -> V_216 ) ;
if ( V_125 == NULL )
return - V_217 ;
V_190 = F_130 ( V_125 -> V_73 ) ;
while ( 1 ) {
V_125 = & V_190 -> V_73 . V_218 [ 0 ] ;
if ( ! ( V_125 -> V_11 & V_219 ) )
break;
if ( V_190 == & V_2 -> V_5 . V_220 ) {
struct V_83 * V_208 = & V_5 -> V_4 -> V_16 ;
V_213 . V_196 . V_91 = V_208 -> V_93 ;
V_213 . V_196 . V_92 = V_208 -> V_94 ;
V_213 . V_196 . V_123 = V_208 -> V_17 ? V_208 -> V_17 -> V_144 : 0 ;
} else {
V_213 . V_125 = V_125 -> V_62 ;
V_213 . V_197 = V_198 ;
V_12 = F_109 ( V_190 , V_125 , V_221 , NULL , & V_213 ) ;
if ( V_12 < 0 && V_12 != - V_222 )
return - V_217 ;
}
V_125 = F_129 ( V_125 ) ;
if ( V_125 == NULL ||
F_131 ( V_125 -> V_73 ) != V_223 )
break;
V_190 = F_130 ( V_125 -> V_73 ) ;
V_214 . V_125 = V_125 -> V_62 ;
V_214 . V_197 = V_198 ;
V_12 = F_109 ( V_190 , V_125 , V_221 , NULL , & V_214 ) ;
if ( V_12 < 0 && V_12 != - V_222 )
return - V_217 ;
if ( V_214 . V_196 . V_91 != V_213 . V_196 . V_91 ||
V_214 . V_196 . V_92 != V_213 . V_196 . V_92 ||
V_214 . V_196 . V_123 != V_213 . V_196 . V_123 )
return - V_217 ;
}
return 0 ;
}
static int F_132 ( struct V_112 * V_112 , void * V_172 ,
enum V_224 type )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_189 * V_190 = V_7 -> V_13 [ V_14 ] ;
int V_12 ;
if ( F_31 ( V_2 ) )
return - V_114 ;
V_12 = F_133 ( & V_190 -> V_73 , V_7 -> V_225 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_5 . V_109 ) {
V_12 = F_128 ( V_2 ) ;
if ( V_12 < 0 ) {
F_134 ( & V_190 -> V_73 ) ;
return V_12 ;
}
}
return F_135 ( & V_2 -> V_5 . V_105 , type ) ;
}
static int F_136 ( struct V_112 * V_112 , void * V_172 ,
enum V_224 type )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_189 * V_190 = V_2 -> V_8 . V_13 [ V_14 ] ;
int V_12 ;
V_12 = F_137 ( & V_2 -> V_5 . V_105 , type ) ;
if ( V_12 == 0 )
F_134 ( & V_190 -> V_73 ) ;
return V_12 ;
}
static int F_138 ( struct V_112 * V_112 , void * V_172 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 = F_139 ( & V_2 -> V_5 . V_105 , V_227 ) ;
if ( ! V_12 )
V_2 -> V_5 . V_70 = V_227 -> V_67 ;
return V_12 ;
}
static int F_140 ( struct V_112 * V_112 , void * V_172 ,
struct V_228 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_141 ( & V_2 -> V_5 . V_105 , V_30 ) ;
}
static int F_142 ( struct V_112 * V_112 , void * V_172 ,
struct V_228 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_143 ( & V_2 -> V_5 . V_105 , V_30 ) ;
}
static int F_144 ( struct V_112 * V_112 , void * V_172 ,
struct V_228 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_145 ( & V_2 -> V_5 . V_105 , V_30 , V_112 -> V_229 & V_230 ) ;
}
static int F_146 ( struct V_112 * V_112 , void * V_172 ,
struct V_231 * V_232 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_147 ( & V_2 -> V_5 . V_105 , V_232 ) ;
}
static int F_148 ( struct V_112 * V_112 , void * V_172 ,
struct V_228 * V_233 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_149 ( & V_2 -> V_5 . V_105 , V_233 ) ;
}
static int F_150 ( struct V_112 * V_112 , void * V_202 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_182 = & V_4 -> V_16 ;
if ( V_235 -> type != V_236 )
return - V_18 ;
switch ( V_235 -> V_157 ) {
case V_237 :
case V_238 :
V_182 = & V_4 -> V_20 ;
case V_239 :
case V_240 :
V_235 -> V_156 . V_165 = 0 ;
V_235 -> V_156 . V_166 = 0 ;
V_235 -> V_156 . V_91 = V_182 -> V_241 ;
V_235 -> V_156 . V_92 = V_182 -> V_242 ;
return 0 ;
case V_167 :
V_182 = & V_4 -> V_20 ;
case V_243 :
V_235 -> V_156 . V_165 = V_182 -> V_151 ;
V_235 -> V_156 . V_166 = V_182 -> V_152 ;
V_235 -> V_156 . V_91 = V_182 -> V_91 ;
V_235 -> V_156 . V_92 = V_182 -> V_92 ;
return 0 ;
}
return - V_18 ;
}
int F_151 ( struct V_155 * V_244 , struct V_155 * V_233 )
{
if ( V_244 -> V_165 < V_233 -> V_165 || V_244 -> V_166 < V_233 -> V_166 )
return 0 ;
if ( V_244 -> V_165 + V_244 -> V_91 > V_233 -> V_165 + V_233 -> V_91 )
return 0 ;
if ( V_244 -> V_166 + V_244 -> V_92 > V_233 -> V_166 + V_233 -> V_92 )
return 0 ;
return 1 ;
}
static int F_152 ( struct V_112 * V_112 , void * V_202 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_155 V_245 = V_235 -> V_156 ;
struct V_83 * V_182 ;
unsigned long V_11 ;
if ( V_235 -> type != V_236 )
return - V_18 ;
if ( V_235 -> V_157 == V_167 )
V_182 = & V_4 -> V_20 ;
else if ( V_235 -> V_157 == V_243 )
V_182 = & V_4 -> V_16 ;
else
return - V_18 ;
F_100 ( V_4 , & V_245 , V_235 -> V_157 ) ;
if ( V_235 -> V_11 & V_246 &&
! F_151 ( & V_245 , & V_235 -> V_156 ) )
return - V_247 ;
if ( V_235 -> V_11 & V_248 &&
! F_151 ( & V_235 -> V_156 , & V_245 ) )
return - V_247 ;
V_235 -> V_156 = V_245 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_122 ( V_182 , V_235 -> V_156 . V_165 , V_235 -> V_156 . V_166 , V_235 -> V_156 . V_91 ,
V_235 -> V_156 . V_92 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
return 0 ;
}
static int F_153 ( struct V_249 * V_73 ,
const struct V_215 * V_250 ,
const struct V_215 * V_251 , V_100 V_11 )
{
struct V_189 * V_190 = F_130 ( V_73 ) ;
struct V_1 * V_2 = F_154 ( V_190 ) ;
if ( F_131 ( V_251 -> V_73 ) != V_223 )
return - V_18 ;
if ( F_73 ( V_2 == NULL ) )
return 0 ;
F_43 ( L_8 ,
V_250 -> V_73 -> V_175 , V_251 -> V_73 -> V_175 , V_11 ,
V_2 -> V_5 . V_252 ) ;
if ( V_11 & V_253 ) {
if ( V_2 -> V_5 . V_252 != 0 )
return - V_114 ;
V_2 -> V_5 . V_252 = V_190 -> V_254 ;
return 0 ;
}
V_2 -> V_5 . V_252 = 0 ;
return 0 ;
}
void F_155 ( struct V_189 * V_190 , unsigned int V_255 ,
void * V_256 )
{
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_257 * V_258 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
if ( V_190 == NULL )
return;
V_10 = F_2 ( V_190 ) ;
V_258 = F_156 ( & V_190 -> V_73 ) ;
F_3 ( & V_258 -> V_19 , V_11 ) ;
V_2 = V_10 ? V_10 -> V_259 : NULL ;
if ( V_2 && V_256 && V_255 == V_260 &&
F_35 ( V_37 , & V_2 -> V_25 ) ) {
unsigned long V_261 ;
F_3 ( & V_2 -> V_19 , V_261 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_41 ) ) {
V_30 = F_157 ( V_2 -> V_5 . V_41 . V_262 ,
struct V_29 , V_263 ) ;
F_63 ( & V_30 -> V_39 , 0 , * ( ( V_100 * ) V_256 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_19 , V_261 ) ;
}
F_21 ( & V_258 -> V_19 , V_11 ) ;
}
static int F_158 ( struct V_189 * V_190 ,
struct V_264 * V_202 ,
struct V_265 * V_123 )
{
struct V_85 * V_17 ;
V_17 = F_57 ( NULL , NULL , V_89 , V_123 -> V_62 ) ;
if ( ! V_17 )
return - V_18 ;
V_123 -> V_123 = V_17 -> V_144 ;
return 0 ;
}
static int F_159 ( struct V_189 * V_190 ,
struct V_264 * V_202 ,
struct V_193 * V_17 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_185 * V_195 ;
struct V_83 * V_208 ;
if ( V_17 -> V_197 == V_199 ) {
V_195 = F_160 ( V_202 , V_17 -> V_125 ) ;
V_17 -> V_196 = * V_195 ;
return 0 ;
}
V_195 = & V_17 -> V_196 ;
V_195 -> V_266 = V_267 ;
V_208 = V_17 -> V_125 == V_143 ? & V_4 -> V_16 : & V_4 -> V_20 ;
F_69 ( & V_2 -> V_106 ) ;
if ( ! F_73 ( V_4 -> V_16 . V_17 == NULL ) )
V_195 -> V_123 = V_4 -> V_16 . V_17 -> V_144 ;
V_195 -> V_91 = V_208 -> V_93 ;
V_195 -> V_92 = V_208 -> V_94 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_161 ( struct V_189 * V_190 ,
struct V_264 * V_202 ,
struct V_193 * V_17 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
struct V_185 * V_195 = & V_17 -> V_196 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_208 ;
struct V_85 * V_138 ;
F_43 ( L_9 ,
V_17 -> V_125 , V_195 -> V_123 , V_195 -> V_91 , V_195 -> V_92 ) ;
if ( V_17 -> V_125 == V_139 &&
F_119 ( & V_2 -> V_5 . V_105 ) )
return - V_114 ;
F_69 ( & V_2 -> V_106 ) ;
V_138 = F_93 ( V_4 , & V_195 -> V_91 , & V_195 -> V_92 ,
& V_195 -> V_123 , NULL , V_17 -> V_125 ) ;
F_71 ( & V_2 -> V_106 ) ;
V_195 -> V_266 = V_267 ;
if ( V_17 -> V_197 == V_199 ) {
V_195 = F_160 ( V_202 , V_17 -> V_125 ) ;
* V_195 = V_17 -> V_196 ;
return 0 ;
}
F_120 ( V_4 ) ;
F_116 ( V_4 , F_94 ( V_138 -> V_140 ) ) ;
V_208 = V_17 -> V_125 == V_143 ?
& V_4 -> V_16 : & V_4 -> V_20 ;
F_69 ( & V_2 -> V_106 ) ;
F_121 ( V_208 , V_195 -> V_91 , V_195 -> V_92 ) ;
V_2 -> V_5 . V_195 = * V_195 ;
V_208 -> V_17 = V_138 ;
if ( ! ( V_17 -> V_125 == V_139 && ( V_4 -> V_25 & V_150 ) ) )
F_122 ( V_208 , 0 , 0 , V_195 -> V_91 , V_195 -> V_92 ) ;
if ( V_17 -> V_125 == V_143 )
V_4 -> V_25 &= ~ V_150 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_162 ( struct V_189 * V_190 ,
struct V_264 * V_202 ,
struct V_268 * V_269 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_182 = & V_4 -> V_16 ;
struct V_155 * V_156 = & V_269 -> V_156 ;
struct V_155 * V_270 ;
if ( V_269 -> V_125 != V_143 )
return - V_18 ;
F_69 ( & V_2 -> V_106 ) ;
switch ( V_269 -> V_157 ) {
case V_271 :
V_182 = & V_4 -> V_20 ;
case V_272 :
V_156 -> V_91 = V_182 -> V_241 ;
V_156 -> V_92 = V_182 -> V_242 ;
V_156 -> V_165 = 0 ;
V_156 -> V_166 = 0 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
case V_273 :
V_270 = F_163 ( V_202 , V_269 -> V_125 ) ;
break;
case V_274 :
V_270 = F_164 ( V_202 , V_269 -> V_125 ) ;
V_182 = & V_4 -> V_20 ;
break;
default:
F_71 ( & V_2 -> V_106 ) ;
return - V_18 ;
}
if ( V_269 -> V_197 == V_199 ) {
V_269 -> V_156 = * V_270 ;
} else {
V_156 -> V_165 = V_182 -> V_151 ;
V_156 -> V_166 = V_182 -> V_152 ;
V_156 -> V_91 = V_182 -> V_91 ;
V_156 -> V_92 = V_182 -> V_92 ;
}
F_43 ( L_10 ,
V_269 -> V_125 , V_156 -> V_165 , V_156 -> V_166 , V_156 -> V_91 , V_156 -> V_92 ,
V_182 -> V_93 , V_182 -> V_94 ) ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_165 ( struct V_189 * V_190 ,
struct V_264 * V_202 ,
struct V_268 * V_269 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_182 = & V_4 -> V_16 ;
struct V_155 * V_156 = & V_269 -> V_156 ;
struct V_155 * V_270 ;
unsigned long V_11 ;
if ( V_269 -> V_125 != V_143 )
return - V_18 ;
F_69 ( & V_2 -> V_106 ) ;
F_100 ( V_4 , V_156 , V_243 ) ;
switch ( V_269 -> V_157 ) {
case V_271 :
V_182 = & V_4 -> V_20 ;
case V_272 :
V_156 -> V_91 = V_182 -> V_241 ;
V_156 -> V_92 = V_182 -> V_242 ;
V_156 -> V_165 = 0 ;
V_156 -> V_166 = 0 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
case V_273 :
V_270 = F_163 ( V_202 , V_269 -> V_125 ) ;
break;
case V_274 :
V_270 = F_164 ( V_202 , V_269 -> V_125 ) ;
V_182 = & V_4 -> V_20 ;
break;
default:
F_71 ( & V_2 -> V_106 ) ;
return - V_18 ;
}
if ( V_269 -> V_197 == V_199 ) {
* V_270 = V_269 -> V_156 ;
} else {
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_122 ( V_182 , V_156 -> V_165 , V_156 -> V_166 , V_156 -> V_91 , V_156 -> V_92 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( V_269 -> V_157 == V_274 )
V_4 -> V_25 |= V_150 ;
}
F_43 ( L_11 , V_269 -> V_157 , V_156 -> V_165 , V_156 -> V_166 ,
V_156 -> V_91 , V_156 -> V_92 ) ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_75 V_17 = {
. type = V_236 ,
. V_17 . V_87 = {
. V_91 = 640 ,
. V_92 = 480 ,
. V_88 = V_275 ,
. V_276 = V_277 ,
. V_266 = V_267 ,
} ,
} ;
return F_118 ( V_2 , & V_17 ) ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
struct V_280 * V_72 ;
struct V_27 * V_5 ;
struct V_3 * V_4 ;
struct V_65 * V_66 ;
int V_12 = - V_281 ;
V_4 = F_167 ( sizeof *V_4 , V_282 ) ;
if ( ! V_4 )
return - V_281 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_283 = V_284 ;
V_4 -> V_285 = V_286 ;
V_4 -> V_25 = V_287 ;
V_4 -> V_16 . V_17 = F_57 ( NULL , NULL , V_89 , 0 ) ;
V_4 -> V_20 . V_17 = V_4 -> V_16 . V_17 ;
V_72 = F_168 () ;
if ( ! V_72 ) {
F_62 ( V_279 , L_12 ) ;
goto V_288;
}
snprintf ( V_72 -> V_175 , sizeof( V_72 -> V_175 ) , L_13 , V_2 -> V_289 ) ;
V_72 -> V_290 = & V_291 ;
V_72 -> V_292 = & V_293 ;
V_72 -> V_279 = V_279 ;
V_72 -> V_294 = - 1 ;
V_72 -> V_295 = V_296 ;
V_72 -> V_106 = & V_2 -> V_106 ;
F_32 ( V_297 , & V_72 -> V_11 ) ;
F_169 ( V_72 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_72 = V_72 ;
V_5 -> V_64 = 0 ;
V_5 -> V_70 = 0 ;
V_5 -> V_118 = 0 ;
F_53 ( & V_5 -> V_38 ) ;
F_53 ( & V_5 -> V_41 ) ;
V_5 -> V_4 = V_4 ;
V_66 = & V_2 -> V_5 . V_105 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_236 ;
V_66 -> V_298 = V_299 | V_300 ;
V_66 -> V_68 = V_2 -> V_5 . V_4 ;
V_66 -> V_301 = & V_302 ;
V_66 -> V_303 = & V_304 ;
V_66 -> V_305 = sizeof( struct V_29 ) ;
F_170 ( V_66 ) ;
V_5 -> V_216 . V_11 = V_219 ;
V_12 = F_171 ( & V_72 -> V_73 , 1 , & V_5 -> V_216 , 0 ) ;
if ( V_12 )
goto V_306;
V_12 = F_172 ( V_72 , V_307 , - 1 ) ;
if ( V_12 )
goto V_308;
F_173 ( V_279 , L_14 ,
V_72 -> V_175 , F_174 ( V_72 ) ) ;
V_72 -> V_111 = & V_4 -> V_107 . V_110 ;
return 0 ;
V_308:
F_175 ( & V_72 -> V_73 ) ;
V_306:
V_296 ( V_72 ) ;
V_288:
F_176 ( V_4 ) ;
return V_12 ;
}
static int F_177 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
int V_12 ;
V_12 = F_178 ( V_2 , V_190 -> V_279 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_166 ( V_2 , V_190 -> V_279 ) ;
if ( V_12 )
F_179 ( V_2 ) ;
return V_12 ;
}
static void F_180 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_154 ( V_190 ) ;
if ( V_2 == NULL )
return;
F_179 ( V_2 ) ;
if ( V_2 -> V_5 . V_72 ) {
F_175 ( & V_2 -> V_5 . V_72 -> V_73 ) ;
F_181 ( V_2 -> V_5 . V_72 ) ;
V_2 -> V_5 . V_72 = NULL ;
}
F_176 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
int F_182 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_5 . V_220 ;
int V_12 ;
F_183 ( V_190 , & V_309 ) ;
V_190 -> V_11 = V_310 ;
snprintf ( V_190 -> V_175 , sizeof( V_190 -> V_175 ) , L_15 , V_2 -> V_116 -> V_289 ) ;
V_2 -> V_5 . V_311 [ V_143 ] . V_11 = V_219 ;
V_2 -> V_5 . V_311 [ V_139 ] . V_11 = V_312 ;
V_12 = F_171 ( & V_190 -> V_73 , V_313 ,
V_2 -> V_5 . V_311 , 0 ) ;
if ( V_12 )
return V_12 ;
V_190 -> V_73 . V_301 = & V_314 ;
V_190 -> V_315 = & V_316 ;
F_184 ( V_190 , V_2 ) ;
return 0 ;
}
void F_185 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_5 . V_220 ;
F_186 ( V_190 ) ;
F_175 ( & V_190 -> V_73 ) ;
F_184 ( V_190 , NULL ) ;
}
