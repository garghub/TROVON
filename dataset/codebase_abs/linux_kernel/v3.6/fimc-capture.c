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
int V_12 = - V_113 ;
F_43 ( L_4 , F_78 ( V_114 ) , V_2 -> V_25 ) ;
if ( F_79 ( & V_2 -> V_106 ) )
return - V_115 ;
if ( F_80 ( V_2 ) )
goto V_116;
F_32 ( V_117 , & V_2 -> V_25 ) ;
V_12 = F_81 ( & V_2 -> V_118 -> V_119 ) ;
if ( V_12 < 0 )
goto V_116;
V_12 = F_82 ( V_112 ) ;
if ( V_12 ) {
F_83 ( & V_2 -> V_118 -> V_119 ) ;
goto V_116;
}
if ( ++ V_2 -> V_5 . V_120 == 1 ) {
V_12 = F_54 ( & V_2 -> V_8 ,
& V_2 -> V_5 . V_72 -> V_73 , true ) ;
if ( ! V_12 && ! V_2 -> V_5 . V_109 )
V_12 = F_84 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_72 ( V_2 ) ;
if ( V_12 < 0 ) {
F_20 ( V_117 , & V_2 -> V_25 ) ;
F_85 ( & V_2 -> V_118 -> V_119 ) ;
V_2 -> V_5 . V_120 -- ;
F_86 ( V_112 ) ;
}
}
V_116:
F_71 ( & V_2 -> V_106 ) ;
return V_12 ;
}
static int F_87 ( struct V_112 * V_112 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 ;
F_43 ( L_4 , F_78 ( V_114 ) , V_2 -> V_25 ) ;
if ( F_79 ( & V_2 -> V_106 ) )
return - V_115 ;
if ( -- V_2 -> V_5 . V_120 == 0 ) {
F_20 ( V_117 , & V_2 -> V_25 ) ;
F_30 ( V_2 , false ) ;
F_51 ( & V_2 -> V_8 ) ;
F_20 ( V_36 , & V_2 -> V_25 ) ;
}
F_83 ( & V_2 -> V_118 -> V_119 ) ;
if ( V_2 -> V_5 . V_120 == 0 ) {
F_88 ( & V_2 -> V_5 . V_105 ) ;
F_89 ( V_2 -> V_5 . V_4 ) ;
}
V_12 = F_86 ( V_112 ) ;
F_71 ( & V_2 -> V_106 ) ;
return V_12 ;
}
static unsigned int F_90 ( struct V_112 * V_112 ,
struct V_121 * V_122 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 ;
if ( F_79 ( & V_2 -> V_106 ) )
return V_123 ;
V_12 = F_91 ( & V_2 -> V_5 . V_105 , V_112 , V_122 ) ;
F_71 ( & V_2 -> V_106 ) ;
return V_12 ;
}
static int F_92 ( struct V_112 * V_112 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 ;
if ( F_79 ( & V_2 -> V_106 ) )
return - V_115 ;
V_12 = F_93 ( & V_2 -> V_5 . V_105 , V_125 ) ;
F_71 ( & V_2 -> V_106 ) ;
return V_12 ;
}
static struct V_85 * F_94 ( struct V_3 * V_4 ,
V_100 * V_91 , V_100 * V_92 ,
V_100 * V_126 , V_100 * V_127 , int V_128 )
{
bool V_129 = V_4 -> V_129 == 90 || V_4 -> V_129 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_130 * V_131 = V_2 -> V_22 ;
struct V_132 * V_133 = V_131 -> V_134 ;
struct V_83 * V_135 = & V_4 -> V_20 ;
V_100 V_97 , V_136 , V_137 , V_138 , V_139 = 3 ;
V_100 V_140 = V_89 ;
struct V_85 * V_141 ;
if ( V_126 && V_4 -> V_16 . V_17 && V_128 == V_142 &&
F_95 ( V_4 -> V_16 . V_17 -> V_143 ) )
* V_126 = V_144 ;
if ( V_127 && * V_127 != V_145 && V_128 != V_146 )
V_140 |= V_90 ;
V_141 = F_57 ( V_127 , V_126 , V_140 , 0 ) ;
if ( F_73 ( ! V_141 ) )
return NULL ;
if ( V_126 )
* V_126 = V_141 -> V_147 ;
if ( V_127 )
* V_127 = V_141 -> V_127 ;
if ( V_128 == V_146 ) {
V_137 = F_95 ( V_141 -> V_143 ) ?
V_133 -> V_148 : V_133 -> V_149 ;
F_96 ( V_91 , F_59 ( V_100 , * V_91 , 32 ) , V_137 , 4 ,
V_92 , F_59 ( V_100 , * V_92 , 32 ) ,
V_150 ,
F_95 ( V_141 -> V_143 ) ? 3 : 1 ,
0 ) ;
return V_141 ;
}
if ( F_95 ( V_141 -> V_143 ) ) {
* V_91 = V_4 -> V_16 . V_93 ;
* V_92 = V_4 -> V_16 . V_94 ;
return V_141 ;
}
V_137 = V_129 ? V_133 -> V_151 : V_133 -> V_152 ;
if ( V_4 -> V_25 & V_153 ) {
V_136 = V_135 -> V_154 + V_135 -> V_91 ;
V_138 = V_135 -> V_155 + V_135 -> V_92 ;
} else {
V_136 = V_131 -> V_156 ;
V_138 = V_131 -> V_156 ;
}
if ( V_131 -> V_157 == 1 && ! V_129 )
V_139 = F_97 ( V_141 -> V_143 ) ? 0 : 1 ;
V_97 = F_98 ( V_141 ) ;
F_96 ( V_91 , V_136 , V_137 ,
F_99 ( V_131 -> V_156 ) - 1 ,
V_92 , V_138 , V_150 ,
V_139 ,
64 / ( F_100 ( V_97 , 8 ) ) ) ;
F_43 ( L_5 ,
V_128 , V_126 ? * V_126 : 0 , * V_91 , * V_92 ,
V_135 -> V_93 , V_135 -> V_94 ) ;
return V_141 ;
}
static void F_101 ( struct V_3 * V_4 ,
struct V_158 * V_159 ,
int V_160 )
{
bool V_161 = V_4 -> V_129 == 90 || V_4 -> V_129 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_130 * V_131 = V_2 -> V_22 ;
struct V_132 * V_133 = V_131 -> V_134 ;
struct V_83 * V_162 = & V_4 -> V_16 ;
V_100 V_137 , V_163 , V_136 = 0 , V_138 = 0 , V_164 ;
V_100 V_165 = 0 , V_139 = 4 ;
V_100 V_166 , V_167 ;
if ( F_95 ( V_4 -> V_20 . V_17 -> V_143 ) ) {
V_159 -> V_91 = V_162 -> V_93 ;
V_159 -> V_92 = V_162 -> V_94 ;
V_159 -> V_168 = V_159 -> V_169 = 0 ;
return;
}
if ( V_160 == V_170 ) {
if ( V_4 -> V_129 != 90 && V_4 -> V_129 != 270 )
V_139 = 1 ;
V_166 = F_102 ( V_171 , 1 << ( F_99 ( V_162 -> V_91 ) - 3 ) ) ;
V_167 = F_102 ( V_172 , 1 << ( F_99 ( V_162 -> V_92 ) - 1 ) ) ;
V_164 = V_131 -> V_156 ;
} else {
V_100 V_97 = F_98 ( V_162 -> V_17 ) ;
V_165 = 64 / F_100 ( V_97 , 8 ) ;
V_164 = V_131 -> V_173 ;
V_136 = V_138 = V_164 ;
V_166 = V_167 = 1 ;
}
V_137 = F_103 ( V_100 ,
V_161 ? V_133 -> V_151 : V_133 -> V_152 ,
V_161 ? V_162 -> V_94 : V_162 -> V_93 ) ;
V_163 = F_103 ( V_100 , V_150 , V_162 -> V_94 ) ;
if ( V_160 == V_170 ) {
V_136 = F_103 ( V_100 , V_137 , V_162 -> V_93 / V_166 ) ;
V_138 = F_103 ( V_100 , V_163 , V_162 -> V_94 / V_167 ) ;
if ( V_161 ) {
F_104 ( V_166 , V_167 ) ;
F_104 ( V_136 , V_138 ) ;
}
}
F_96 ( & V_159 -> V_91 , V_136 , V_137 , F_99 ( V_164 ) - 1 ,
& V_159 -> V_92 , V_138 , V_163 , V_139 ,
V_165 ) ;
V_159 -> V_168 = F_105 ( V_100 , V_159 -> V_168 , 0 , V_162 -> V_93 - V_159 -> V_91 ) ;
V_159 -> V_169 = F_105 ( V_100 , V_159 -> V_169 , 0 , V_162 -> V_94 - V_159 -> V_92 ) ;
V_159 -> V_168 = F_106 ( V_159 -> V_168 , V_131 -> V_174 ) ;
F_43 ( L_6 ,
V_160 , V_159 -> V_168 , V_159 -> V_169 , V_159 -> V_91 , V_159 -> V_92 ,
V_162 -> V_93 , V_162 -> V_94 ) ;
}
static int F_107 ( struct V_112 * V_112 , void * V_175 ,
struct V_176 * V_28 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
strncpy ( V_28 -> V_177 , V_2 -> V_118 -> V_178 , sizeof( V_28 -> V_177 ) - 1 ) ;
strncpy ( V_28 -> V_179 , V_2 -> V_118 -> V_178 , sizeof( V_28 -> V_179 ) - 1 ) ;
V_28 -> V_180 [ 0 ] = 0 ;
V_28 -> V_181 = V_182 | V_183 ;
return 0 ;
}
static int F_108 ( struct V_112 * V_112 , void * V_175 ,
struct V_184 * V_185 )
{
struct V_85 * V_17 ;
V_17 = F_57 ( NULL , NULL , V_89 | V_90 ,
V_185 -> V_62 ) ;
if ( ! V_17 )
return - V_18 ;
strncpy ( V_185 -> V_186 , V_17 -> V_178 , sizeof( V_185 -> V_186 ) - 1 ) ;
V_185 -> V_88 = V_17 -> V_127 ;
if ( V_17 -> V_127 == V_144 )
V_185 -> V_11 |= V_187 ;
return 0 ;
}
static int F_109 ( struct V_3 * V_4 ,
struct V_188 * V_189 ,
struct V_85 * * V_190 ,
bool V_191 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_192 * V_193 = V_2 -> V_8 . V_13 [ V_14 ] ;
struct V_192 * V_194 = V_2 -> V_8 . V_13 [ V_195 ] ;
struct V_196 V_197 ;
struct V_188 * V_198 = & V_197 . V_199 ;
struct V_85 * V_141 = NULL ;
int V_12 , V_71 = 0 ;
if ( F_73 ( ! V_193 || ! V_189 ) )
return - V_18 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_199 = * V_189 ;
V_197 . V_200 = V_191 ? V_201 : V_202 ;
while ( 1 ) {
V_141 = F_57 ( NULL , V_198 -> V_126 != 0 ? & V_198 -> V_126 : NULL ,
V_89 , V_71 ++ ) ;
if ( V_141 == NULL ) {
return - V_18 ;
}
V_198 -> V_126 = V_189 -> V_126 = V_141 -> V_147 ;
V_12 = F_110 ( V_193 , V_128 , V_203 , NULL , & V_197 ) ;
if ( V_12 )
return V_12 ;
if ( V_198 -> V_126 != V_189 -> V_126 ) {
V_198 -> V_126 = 0 ;
continue;
}
if ( V_198 -> V_91 != V_189 -> V_91 || V_198 -> V_92 != V_189 -> V_92 ) {
V_100 V_204 = V_141 -> V_127 ;
V_189 -> V_91 = V_198 -> V_91 ;
V_189 -> V_92 = V_198 -> V_92 ;
V_141 = F_94 ( V_4 ,
& V_189 -> V_91 , & V_189 -> V_92 ,
NULL , & V_204 , V_142 ) ;
if ( V_141 && V_141 -> V_147 )
V_198 -> V_126 = V_141 -> V_147 ;
if ( V_198 -> V_91 != V_189 -> V_91 ||
V_198 -> V_92 != V_189 -> V_92 )
continue;
V_189 -> V_126 = V_198 -> V_126 ;
}
if ( V_194 )
V_12 = F_110 ( V_194 , V_128 , V_203 , NULL , & V_197 ) ;
if ( V_198 -> V_126 == V_189 -> V_126 &&
V_198 -> V_91 == V_189 -> V_91 && V_198 -> V_92 == V_189 -> V_92 )
break;
}
if ( V_190 && V_141 )
* V_190 = V_141 ;
* V_189 = * V_198 ;
F_43 ( L_7 , V_198 -> V_126 , V_198 -> V_91 , V_198 -> V_92 , V_141 ) ;
return 0 ;
}
static int F_111 ( struct V_112 * V_112 , void * V_205 ,
struct V_75 * V_185 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
return F_112 ( & V_4 -> V_20 , V_185 ) ;
}
static int F_113 ( struct V_112 * V_112 , void * V_205 ,
struct V_75 * V_185 )
{
struct V_81 * V_206 = & V_185 -> V_17 . V_87 ;
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_188 V_198 ;
struct V_85 * V_141 = NULL ;
if ( V_206 -> V_88 == V_145 ) {
F_94 ( V_4 , & V_206 -> V_91 , & V_206 -> V_92 ,
NULL , & V_206 -> V_88 ,
V_146 ) ;
V_4 -> V_16 . V_93 = V_206 -> V_91 ;
V_4 -> V_16 . V_94 = V_206 -> V_92 ;
}
V_141 = F_94 ( V_4 , & V_206 -> V_91 , & V_206 -> V_92 ,
NULL , & V_206 -> V_88 ,
V_142 ) ;
if ( ! V_141 )
return - V_18 ;
if ( ! V_2 -> V_5 . V_109 ) {
V_198 . V_91 = V_206 -> V_91 ;
V_198 . V_92 = V_206 -> V_92 ;
V_198 . V_126 = V_141 -> V_147 ;
F_114 ( V_2 ) ;
F_109 ( V_4 , & V_198 , & V_141 , false ) ;
F_115 ( V_2 ) ;
V_206 -> V_91 = V_198 . V_91 ;
V_206 -> V_92 = V_198 . V_92 ;
if ( V_141 )
V_206 -> V_88 = V_141 -> V_127 ;
}
F_116 ( V_141 , V_206 -> V_91 , V_206 -> V_92 , V_206 ) ;
return 0 ;
}
static void F_117 ( struct V_3 * V_4 , bool V_207 )
{
V_4 -> V_208 . V_209 = ! V_207 ;
F_118 ( V_4 , ! V_207 ) ;
if ( V_207 )
F_32 ( V_210 , & V_4 -> V_1 -> V_25 ) ;
else
F_20 ( V_210 , & V_4 -> V_1 -> V_25 ) ;
}
static int F_119 ( struct V_1 * V_2 , struct V_75 * V_185 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_81 * V_206 = & V_185 -> V_17 . V_87 ;
struct V_188 * V_198 = & V_2 -> V_5 . V_198 ;
struct V_83 * V_211 = & V_4 -> V_20 ;
struct V_85 * V_212 = NULL ;
int V_12 , V_71 ;
if ( F_120 ( & V_2 -> V_5 . V_105 ) )
return - V_113 ;
if ( V_206 -> V_88 == V_145 ) {
F_94 ( V_4 , & V_206 -> V_91 , & V_206 -> V_92 ,
NULL , & V_206 -> V_88 ,
V_146 ) ;
V_4 -> V_16 . V_93 = V_206 -> V_91 ;
V_4 -> V_16 . V_94 = V_206 -> V_92 ;
}
V_211 -> V_17 = F_94 ( V_4 , & V_206 -> V_91 , & V_206 -> V_92 ,
NULL , & V_206 -> V_88 ,
V_142 ) ;
if ( ! V_211 -> V_17 )
return - V_18 ;
F_121 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_109 ) {
V_198 -> V_126 = V_211 -> V_17 -> V_147 ;
V_198 -> V_91 = V_206 -> V_91 ;
V_198 -> V_92 = V_206 -> V_92 ;
F_114 ( V_2 ) ;
V_12 = F_109 ( V_4 , V_198 , & V_212 , true ) ;
F_115 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_206 -> V_91 = V_198 -> V_91 ;
V_206 -> V_92 = V_198 -> V_92 ;
}
F_116 ( V_211 -> V_17 , V_206 -> V_91 , V_206 -> V_92 , V_206 ) ;
for ( V_71 = 0 ; V_71 < V_211 -> V_17 -> V_213 ; V_71 ++ )
V_211 -> V_101 [ V_71 ] = V_206 -> V_98 [ V_71 ] . V_99 ;
F_122 ( V_211 , V_206 -> V_91 , V_206 -> V_92 ) ;
if ( ! ( V_4 -> V_25 & V_153 ) )
F_123 ( V_211 , 0 , 0 , V_206 -> V_91 , V_206 -> V_92 ) ;
F_117 ( V_4 , F_95 ( V_211 -> V_17 -> V_143 ) ) ;
if ( ! V_2 -> V_5 . V_109 ) {
V_4 -> V_16 . V_17 = V_212 ;
F_122 ( & V_4 -> V_16 , V_206 -> V_91 , V_206 -> V_92 ) ;
F_123 ( & V_4 -> V_16 , 0 , 0 , V_206 -> V_91 , V_206 -> V_92 ) ;
}
return V_12 ;
}
static int F_124 ( struct V_112 * V_112 , void * V_175 ,
struct V_75 * V_185 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_119 ( V_2 , V_185 ) ;
}
static int F_125 ( struct V_112 * V_112 , void * V_175 ,
struct V_214 * V_71 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_192 * V_193 = V_2 -> V_8 . V_13 [ V_14 ] ;
if ( V_71 -> V_62 != 0 )
return - V_18 ;
V_71 -> type = V_215 ;
if ( V_193 )
F_126 ( V_71 -> V_178 , V_193 -> V_178 , sizeof( V_71 -> V_178 ) ) ;
return 0 ;
}
static int F_127 ( struct V_112 * V_112 , void * V_175 , unsigned int V_71 )
{
return V_71 == 0 ? V_71 : - V_18 ;
}
static int F_128 ( struct V_112 * V_112 , void * V_175 , unsigned int * V_71 )
{
* V_71 = 0 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_196 V_216 , V_217 ;
struct V_27 * V_5 = & V_2 -> V_5 ;
struct V_192 * V_193 ;
struct V_218 * V_128 ;
int V_12 ;
V_128 = F_130 ( & V_5 -> V_219 ) ;
if ( V_128 == NULL )
return - V_220 ;
V_193 = F_131 ( V_128 -> V_73 ) ;
while ( 1 ) {
V_128 = & V_193 -> V_73 . V_221 [ 0 ] ;
if ( ! ( V_128 -> V_11 & V_222 ) )
break;
if ( V_193 == & V_2 -> V_5 . V_223 ) {
struct V_83 * V_211 = & V_5 -> V_4 -> V_16 ;
V_216 . V_199 . V_91 = V_211 -> V_93 ;
V_216 . V_199 . V_92 = V_211 -> V_94 ;
V_216 . V_199 . V_126 = V_211 -> V_17 ? V_211 -> V_17 -> V_147 : 0 ;
} else {
V_216 . V_128 = V_128 -> V_62 ;
V_216 . V_200 = V_201 ;
V_12 = F_110 ( V_193 , V_128 , V_224 , NULL , & V_216 ) ;
if ( V_12 < 0 && V_12 != - V_225 )
return - V_220 ;
}
V_128 = F_130 ( V_128 ) ;
if ( V_128 == NULL ||
F_132 ( V_128 -> V_73 ) != V_226 )
break;
V_193 = F_131 ( V_128 -> V_73 ) ;
V_217 . V_128 = V_128 -> V_62 ;
V_217 . V_200 = V_201 ;
V_12 = F_110 ( V_193 , V_128 , V_224 , NULL , & V_217 ) ;
if ( V_12 < 0 && V_12 != - V_225 )
return - V_220 ;
if ( V_217 . V_199 . V_91 != V_216 . V_199 . V_91 ||
V_217 . V_199 . V_92 != V_216 . V_199 . V_92 ||
V_217 . V_199 . V_126 != V_216 . V_199 . V_126 )
return - V_220 ;
}
return 0 ;
}
static int F_133 ( struct V_112 * V_112 , void * V_175 ,
enum V_227 type )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_192 * V_193 = V_7 -> V_13 [ V_14 ] ;
int V_12 ;
if ( F_31 ( V_2 ) )
return - V_113 ;
V_12 = F_134 ( & V_193 -> V_73 , V_7 -> V_228 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_5 . V_109 ) {
V_12 = F_129 ( V_2 ) ;
if ( V_12 < 0 ) {
F_135 ( & V_193 -> V_73 ) ;
return V_12 ;
}
}
return F_136 ( & V_2 -> V_5 . V_105 , type ) ;
}
static int F_137 ( struct V_112 * V_112 , void * V_175 ,
enum V_227 type )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_192 * V_193 = V_2 -> V_8 . V_13 [ V_14 ] ;
int V_12 ;
V_12 = F_138 ( & V_2 -> V_5 . V_105 , type ) ;
if ( V_12 == 0 )
F_135 ( & V_193 -> V_73 ) ;
return V_12 ;
}
static int F_139 ( struct V_112 * V_112 , void * V_175 ,
struct V_229 * V_230 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
int V_12 = F_140 ( & V_2 -> V_5 . V_105 , V_230 ) ;
if ( ! V_12 )
V_2 -> V_5 . V_70 = V_230 -> V_67 ;
return V_12 ;
}
static int F_141 ( struct V_112 * V_112 , void * V_175 ,
struct V_231 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_142 ( & V_2 -> V_5 . V_105 , V_30 ) ;
}
static int F_143 ( struct V_112 * V_112 , void * V_175 ,
struct V_231 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_144 ( & V_2 -> V_5 . V_105 , V_30 ) ;
}
static int F_145 ( struct V_112 * V_112 , void * V_175 ,
struct V_231 * V_30 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_146 ( & V_2 -> V_5 . V_105 , V_30 , V_112 -> V_232 & V_233 ) ;
}
static int F_147 ( struct V_112 * V_112 , void * V_175 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_148 ( & V_2 -> V_5 . V_105 , V_235 ) ;
}
static int F_149 ( struct V_112 * V_112 , void * V_175 ,
struct V_231 * V_236 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
return F_150 ( & V_2 -> V_5 . V_105 , V_236 ) ;
}
static int F_151 ( struct V_112 * V_112 , void * V_205 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_185 = & V_4 -> V_16 ;
if ( V_238 -> type != V_239 )
return - V_18 ;
switch ( V_238 -> V_160 ) {
case V_240 :
case V_241 :
V_185 = & V_4 -> V_20 ;
case V_242 :
case V_243 :
V_238 -> V_159 . V_168 = 0 ;
V_238 -> V_159 . V_169 = 0 ;
V_238 -> V_159 . V_91 = V_185 -> V_244 ;
V_238 -> V_159 . V_92 = V_185 -> V_245 ;
return 0 ;
case V_170 :
V_185 = & V_4 -> V_20 ;
case V_246 :
V_238 -> V_159 . V_168 = V_185 -> V_154 ;
V_238 -> V_159 . V_169 = V_185 -> V_155 ;
V_238 -> V_159 . V_91 = V_185 -> V_91 ;
V_238 -> V_159 . V_92 = V_185 -> V_92 ;
return 0 ;
}
return - V_18 ;
}
static int F_152 ( struct V_158 * V_247 , struct V_158 * V_236 )
{
if ( V_247 -> V_168 < V_236 -> V_168 || V_247 -> V_169 < V_236 -> V_169 )
return 0 ;
if ( V_247 -> V_168 + V_247 -> V_91 > V_236 -> V_168 + V_236 -> V_91 )
return 0 ;
if ( V_247 -> V_169 + V_247 -> V_92 > V_236 -> V_169 + V_236 -> V_92 )
return 0 ;
return 1 ;
}
static int F_153 ( struct V_112 * V_112 , void * V_205 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_112 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_158 V_248 = V_238 -> V_159 ;
struct V_83 * V_185 ;
unsigned long V_11 ;
if ( V_238 -> type != V_239 )
return - V_18 ;
if ( V_238 -> V_160 == V_170 )
V_185 = & V_4 -> V_20 ;
else if ( V_238 -> V_160 == V_246 )
V_185 = & V_4 -> V_16 ;
else
return - V_18 ;
F_101 ( V_4 , & V_248 , V_238 -> V_160 ) ;
if ( V_238 -> V_11 & V_249 &&
! F_152 ( & V_248 , & V_238 -> V_159 ) )
return - V_250 ;
if ( V_238 -> V_11 & V_251 &&
! F_152 ( & V_238 -> V_159 , & V_248 ) )
return - V_250 ;
V_238 -> V_159 = V_248 ;
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_123 ( V_185 , V_238 -> V_159 . V_168 , V_238 -> V_159 . V_169 , V_238 -> V_159 . V_91 ,
V_238 -> V_159 . V_92 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
return 0 ;
}
static int F_154 ( struct V_252 * V_73 ,
const struct V_218 * V_253 ,
const struct V_218 * V_254 , V_100 V_11 )
{
struct V_192 * V_193 = F_131 ( V_73 ) ;
struct V_1 * V_2 = F_155 ( V_193 ) ;
if ( F_132 ( V_254 -> V_73 ) != V_226 )
return - V_18 ;
if ( F_73 ( V_2 == NULL ) )
return 0 ;
F_43 ( L_8 ,
V_253 -> V_73 -> V_178 , V_254 -> V_73 -> V_178 , V_11 ,
V_2 -> V_5 . V_255 ) ;
if ( V_11 & V_256 ) {
if ( V_2 -> V_5 . V_255 != 0 )
return - V_113 ;
V_2 -> V_5 . V_255 = V_193 -> V_257 ;
return 0 ;
}
V_2 -> V_5 . V_255 = 0 ;
return 0 ;
}
void F_156 ( struct V_192 * V_193 , unsigned int V_258 ,
void * V_259 )
{
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_260 * V_261 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
if ( V_193 == NULL )
return;
V_10 = F_2 ( V_193 ) ;
V_261 = F_157 ( & V_193 -> V_73 ) ;
F_3 ( & V_261 -> V_19 , V_11 ) ;
V_2 = V_10 ? V_10 -> V_262 : NULL ;
if ( V_2 && V_259 && V_258 == V_263 &&
F_35 ( V_37 , & V_2 -> V_25 ) ) {
unsigned long V_264 ;
F_3 ( & V_2 -> V_19 , V_264 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_41 ) ) {
V_30 = F_158 ( V_2 -> V_5 . V_41 . V_265 ,
struct V_29 , V_266 ) ;
F_63 ( & V_30 -> V_39 , 0 , * ( ( V_100 * ) V_259 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_19 , V_264 ) ;
}
F_21 ( & V_261 -> V_19 , V_11 ) ;
}
static int F_159 ( struct V_192 * V_193 ,
struct V_267 * V_205 ,
struct V_268 * V_126 )
{
struct V_85 * V_17 ;
V_17 = F_57 ( NULL , NULL , V_89 , V_126 -> V_62 ) ;
if ( ! V_17 )
return - V_18 ;
V_126 -> V_126 = V_17 -> V_147 ;
return 0 ;
}
static int F_160 ( struct V_192 * V_193 ,
struct V_267 * V_205 ,
struct V_196 * V_17 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_188 * V_198 ;
struct V_83 * V_211 ;
if ( V_17 -> V_200 == V_202 ) {
V_198 = F_161 ( V_205 , V_17 -> V_128 ) ;
V_17 -> V_199 = * V_198 ;
return 0 ;
}
V_198 = & V_17 -> V_199 ;
V_198 -> V_269 = V_270 ;
V_211 = V_17 -> V_128 == V_146 ? & V_4 -> V_16 : & V_4 -> V_20 ;
F_69 ( & V_2 -> V_106 ) ;
if ( ! F_73 ( V_4 -> V_16 . V_17 == NULL ) )
V_198 -> V_126 = V_4 -> V_16 . V_17 -> V_147 ;
V_198 -> V_91 = V_211 -> V_93 ;
V_198 -> V_92 = V_211 -> V_94 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_162 ( struct V_192 * V_193 ,
struct V_267 * V_205 ,
struct V_196 * V_17 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
struct V_188 * V_198 = & V_17 -> V_199 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_211 ;
struct V_85 * V_141 ;
F_43 ( L_9 ,
V_17 -> V_128 , V_198 -> V_126 , V_198 -> V_91 , V_198 -> V_92 ) ;
if ( V_17 -> V_128 == V_142 &&
F_120 ( & V_2 -> V_5 . V_105 ) )
return - V_113 ;
F_69 ( & V_2 -> V_106 ) ;
V_141 = F_94 ( V_4 , & V_198 -> V_91 , & V_198 -> V_92 ,
& V_198 -> V_126 , NULL , V_17 -> V_128 ) ;
F_71 ( & V_2 -> V_106 ) ;
V_198 -> V_269 = V_270 ;
if ( V_17 -> V_200 == V_202 ) {
V_198 = F_161 ( V_205 , V_17 -> V_128 ) ;
* V_198 = V_17 -> V_199 ;
return 0 ;
}
F_121 ( V_4 ) ;
F_117 ( V_4 , F_95 ( V_141 -> V_143 ) ) ;
V_211 = V_17 -> V_128 == V_146 ?
& V_4 -> V_16 : & V_4 -> V_20 ;
F_69 ( & V_2 -> V_106 ) ;
F_122 ( V_211 , V_198 -> V_91 , V_198 -> V_92 ) ;
V_2 -> V_5 . V_198 = * V_198 ;
V_211 -> V_17 = V_141 ;
if ( ! ( V_17 -> V_128 == V_142 && ( V_4 -> V_25 & V_153 ) ) )
F_123 ( V_211 , 0 , 0 , V_198 -> V_91 , V_198 -> V_92 ) ;
if ( V_17 -> V_128 == V_146 )
V_4 -> V_25 &= ~ V_153 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_163 ( struct V_192 * V_193 ,
struct V_267 * V_205 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_185 = & V_4 -> V_16 ;
struct V_158 * V_159 = & V_272 -> V_159 ;
struct V_158 * V_273 ;
if ( V_272 -> V_128 != V_146 )
return - V_18 ;
F_69 ( & V_2 -> V_106 ) ;
switch ( V_272 -> V_160 ) {
case V_241 :
V_185 = & V_4 -> V_20 ;
case V_242 :
V_159 -> V_91 = V_185 -> V_244 ;
V_159 -> V_92 = V_185 -> V_245 ;
V_159 -> V_168 = 0 ;
V_159 -> V_169 = 0 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
case V_246 :
V_273 = F_164 ( V_205 , V_272 -> V_128 ) ;
break;
case V_170 :
V_273 = F_165 ( V_205 , V_272 -> V_128 ) ;
V_185 = & V_4 -> V_20 ;
break;
default:
F_71 ( & V_2 -> V_106 ) ;
return - V_18 ;
}
if ( V_272 -> V_200 == V_202 ) {
V_272 -> V_159 = * V_273 ;
} else {
V_159 -> V_168 = V_185 -> V_154 ;
V_159 -> V_169 = V_185 -> V_155 ;
V_159 -> V_91 = V_185 -> V_91 ;
V_159 -> V_92 = V_185 -> V_92 ;
}
F_43 ( L_10 ,
V_272 -> V_128 , V_159 -> V_168 , V_159 -> V_169 , V_159 -> V_91 , V_159 -> V_92 ,
V_185 -> V_93 , V_185 -> V_94 ) ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_166 ( struct V_192 * V_193 ,
struct V_267 * V_205 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_83 * V_185 = & V_4 -> V_16 ;
struct V_158 * V_159 = & V_272 -> V_159 ;
struct V_158 * V_273 ;
unsigned long V_11 ;
if ( V_272 -> V_128 != V_146 )
return - V_18 ;
F_69 ( & V_2 -> V_106 ) ;
F_101 ( V_4 , V_159 , V_246 ) ;
switch ( V_272 -> V_160 ) {
case V_241 :
V_185 = & V_4 -> V_20 ;
case V_242 :
V_159 -> V_91 = V_185 -> V_244 ;
V_159 -> V_92 = V_185 -> V_245 ;
V_159 -> V_168 = 0 ;
V_159 -> V_169 = 0 ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
case V_246 :
V_273 = F_164 ( V_205 , V_272 -> V_128 ) ;
break;
case V_170 :
V_273 = F_165 ( V_205 , V_272 -> V_128 ) ;
V_185 = & V_4 -> V_20 ;
break;
default:
F_71 ( & V_2 -> V_106 ) ;
return - V_18 ;
}
if ( V_272 -> V_200 == V_202 ) {
* V_273 = V_272 -> V_159 ;
} else {
F_3 ( & V_2 -> V_19 , V_11 ) ;
F_123 ( V_185 , V_159 -> V_168 , V_159 -> V_169 , V_159 -> V_91 , V_159 -> V_92 ) ;
F_32 ( V_24 , & V_2 -> V_25 ) ;
F_21 ( & V_2 -> V_19 , V_11 ) ;
if ( V_272 -> V_160 == V_170 )
V_4 -> V_25 |= V_153 ;
}
F_43 ( L_11 , V_272 -> V_160 , V_159 -> V_168 , V_159 -> V_169 ,
V_159 -> V_91 , V_159 -> V_92 ) ;
F_71 ( & V_2 -> V_106 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_75 V_17 = {
. type = V_239 ,
. V_17 . V_87 = {
. V_91 = 640 ,
. V_92 = 480 ,
. V_88 = V_274 ,
. V_275 = V_276 ,
. V_269 = V_270 ,
} ,
} ;
return F_119 ( V_2 , & V_17 ) ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
struct V_279 * V_72 ;
struct V_27 * V_5 ;
struct V_3 * V_4 ;
struct V_65 * V_66 ;
int V_12 = - V_280 ;
V_4 = F_168 ( sizeof *V_4 , V_281 ) ;
if ( ! V_4 )
return - V_280 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_282 = V_283 ;
V_4 -> V_284 = V_285 ;
V_4 -> V_25 = V_286 ;
V_4 -> V_16 . V_17 = F_57 ( NULL , NULL , V_89 , 0 ) ;
V_4 -> V_20 . V_17 = V_4 -> V_16 . V_17 ;
V_72 = F_169 () ;
if ( ! V_72 ) {
F_62 ( V_278 , L_12 ) ;
goto V_287;
}
snprintf ( V_72 -> V_178 , sizeof( V_72 -> V_178 ) , L_13 , V_2 -> V_288 ) ;
V_72 -> V_289 = & V_290 ;
V_72 -> V_291 = & V_292 ;
V_72 -> V_278 = V_278 ;
V_72 -> V_293 = - 1 ;
V_72 -> V_294 = V_295 ;
V_72 -> V_106 = & V_2 -> V_106 ;
F_170 ( V_72 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_72 = V_72 ;
V_5 -> V_64 = 0 ;
V_5 -> V_70 = 0 ;
V_5 -> V_120 = 0 ;
F_53 ( & V_5 -> V_38 ) ;
F_53 ( & V_5 -> V_41 ) ;
V_5 -> V_4 = V_4 ;
V_66 = & V_2 -> V_5 . V_105 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_239 ;
V_66 -> V_296 = V_297 | V_298 ;
V_66 -> V_68 = V_2 -> V_5 . V_4 ;
V_66 -> V_299 = & V_300 ;
V_66 -> V_301 = & V_302 ;
V_66 -> V_303 = sizeof( struct V_29 ) ;
F_171 ( V_66 ) ;
V_5 -> V_219 . V_11 = V_222 ;
V_12 = F_172 ( & V_72 -> V_73 , 1 , & V_5 -> V_219 , 0 ) ;
if ( V_12 )
goto V_304;
V_12 = F_173 ( V_72 , V_305 , - 1 ) ;
if ( V_12 )
goto V_306;
F_174 ( V_278 , L_14 ,
V_72 -> V_178 , F_175 ( V_72 ) ) ;
V_72 -> V_111 = & V_4 -> V_107 . V_110 ;
return 0 ;
V_306:
F_176 ( & V_72 -> V_73 ) ;
V_304:
V_295 ( V_72 ) ;
V_287:
F_177 ( V_4 ) ;
return V_12 ;
}
static int F_178 ( struct V_192 * V_193 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
int V_12 ;
V_12 = F_179 ( V_2 , V_193 -> V_278 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_167 ( V_2 , V_193 -> V_278 ) ;
if ( V_12 )
F_180 ( V_2 ) ;
return V_12 ;
}
static void F_181 ( struct V_192 * V_193 )
{
struct V_1 * V_2 = F_155 ( V_193 ) ;
if ( V_2 == NULL )
return;
F_180 ( V_2 ) ;
if ( V_2 -> V_5 . V_72 ) {
F_176 ( & V_2 -> V_5 . V_72 -> V_73 ) ;
F_182 ( V_2 -> V_5 . V_72 ) ;
V_2 -> V_5 . V_72 = NULL ;
}
F_177 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
int F_183 ( struct V_1 * V_2 )
{
struct V_192 * V_193 = & V_2 -> V_5 . V_223 ;
int V_12 ;
F_184 ( V_193 , & V_307 ) ;
V_193 -> V_11 = V_308 ;
snprintf ( V_193 -> V_178 , sizeof( V_193 -> V_178 ) , L_15 , V_2 -> V_118 -> V_288 ) ;
V_2 -> V_5 . V_309 [ V_146 ] . V_11 = V_222 ;
V_2 -> V_5 . V_309 [ V_142 ] . V_11 = V_310 ;
V_12 = F_172 ( & V_193 -> V_73 , V_311 ,
V_2 -> V_5 . V_309 , 0 ) ;
if ( V_12 )
return V_12 ;
V_193 -> V_73 . V_299 = & V_312 ;
V_193 -> V_313 = & V_314 ;
F_185 ( V_193 , V_2 ) ;
return 0 ;
}
void F_186 ( struct V_1 * V_2 )
{
struct V_192 * V_193 = & V_2 -> V_5 . V_223 ;
F_187 ( V_193 ) ;
F_176 ( & V_193 -> V_73 ) ;
F_185 ( V_193 , NULL ) ;
}
