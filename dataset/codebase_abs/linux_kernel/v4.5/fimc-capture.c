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
V_54 -> V_35 . V_36 . V_56 = F_41 () ;
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
static int F_59 ( struct V_71 * V_83 ,
unsigned int * V_84 , unsigned int * V_85 ,
unsigned int V_86 [] , void * V_87 [] )
{
struct V_7 * V_8 = V_83 -> V_74 ;
struct V_52 * V_88 = & V_8 -> V_17 ;
struct V_89 * V_12 = V_88 -> V_12 ;
unsigned long V_90 = V_88 -> V_91 * V_88 -> V_92 ;
int V_79 ;
if ( V_12 == NULL )
return - V_13 ;
if ( * V_85 ) {
if ( * V_85 != V_12 -> V_93 )
return - V_13 ;
for ( V_79 = 0 ; V_79 < * V_85 ; V_79 ++ ) {
if ( V_86 [ V_79 ] < ( V_90 * V_12 -> V_94 [ V_79 ] ) / 8 )
return - V_13 ;
V_87 [ V_79 ] = V_8 -> V_1 -> V_95 ;
}
return 0 ;
}
* V_85 = V_12 -> V_93 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_93 ; V_79 ++ ) {
unsigned int V_65 = ( V_90 * V_12 -> V_94 [ V_79 ] ) / 8 ;
if ( F_60 ( V_12 -> V_96 ) )
V_86 [ V_79 ] = V_88 -> V_66 [ V_79 ] ;
else
V_86 [ V_79 ] = F_61 ( V_97 , V_65 , V_88 -> V_66 [ V_79 ] ) ;
V_87 [ V_79 ] = V_8 -> V_1 -> V_95 ;
}
return 0 ;
}
static int F_62 ( struct V_98 * V_35 )
{
struct V_71 * V_83 = V_35 -> V_71 ;
struct V_7 * V_8 = V_83 -> V_74 ;
int V_79 ;
if ( V_8 -> V_17 . V_12 == NULL )
return - V_13 ;
for ( V_79 = 0 ; V_79 < V_8 -> V_17 . V_12 -> V_93 ; V_79 ++ ) {
unsigned long V_65 = V_8 -> V_17 . V_66 [ V_79 ] ;
if ( F_63 ( V_35 , V_79 ) < V_65 ) {
F_64 ( & V_8 -> V_1 -> V_5 . V_40 . V_81 ,
L_3 ,
F_63 ( V_35 , V_79 ) , V_65 ) ;
return - V_13 ;
}
F_65 ( V_35 , V_79 , V_65 ) ;
}
return 0 ;
}
static void F_58 ( struct V_98 * V_35 )
{
struct V_99 * V_100 = F_66 ( V_35 ) ;
struct V_25 * V_26
= F_67 ( V_100 , struct V_25 , V_35 ) ;
struct V_7 * V_8 = F_68 ( V_35 -> V_71 ) ;
struct V_1 * V_2 = V_8 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_5 -> V_40 ;
unsigned long V_10 ;
int V_75 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_69 ( V_8 , & V_26 -> V_35 . V_36 , & V_8 -> V_17 , & V_26 -> V_60 ) ;
if ( ! F_35 ( V_32 , & V_2 -> V_21 ) &&
! F_35 ( V_31 , & V_2 -> V_21 ) &&
V_5 -> V_70 < V_62 ) {
int V_101 = ( V_5 -> V_76 == 1 ) ? - 1 :
V_5 -> V_39 ;
F_42 ( V_2 , & V_26 -> V_60 , V_101 ) ;
V_26 -> V_61 = V_5 -> V_39 ;
F_43 ( V_5 , V_26 ) ;
if ( ++ V_5 -> V_39 >= V_62 )
V_5 -> V_39 = 0 ;
} else {
F_27 ( V_5 , V_26 ) ;
}
V_75 = V_5 -> V_76 > 1 ? 2 : 1 ;
if ( F_70 ( & V_5 -> V_102 ) &&
V_5 -> V_70 >= V_75 &&
! F_51 ( V_31 , & V_2 -> V_21 ) ) {
int V_9 ;
F_52 ( V_8 ) ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
if ( F_51 ( V_28 , & V_2 -> V_21 ) )
return;
V_9 = F_29 ( V_40 , V_41 , 1 ) ;
if ( V_9 < 0 )
F_64 ( & V_40 -> V_81 , L_4 , V_9 ) ;
return;
}
F_21 ( & V_2 -> V_16 , V_10 ) ;
}
static int F_71 ( struct V_103 * V_103 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_104 -> V_40 ;
int V_9 = - V_105 ;
F_44 ( L_5 , F_73 ( V_106 ) , V_2 -> V_21 ) ;
F_74 ( & V_2 -> V_107 ) ;
if ( F_75 ( V_2 ) )
goto V_108;
F_32 ( V_109 , & V_2 -> V_21 ) ;
V_9 = F_76 ( & V_2 -> V_110 -> V_111 ) ;
if ( V_9 < 0 )
goto V_108;
V_9 = F_77 ( V_103 ) ;
if ( V_9 ) {
F_78 ( & V_2 -> V_110 -> V_111 ) ;
goto V_108;
}
if ( F_79 ( V_103 ) ) {
F_80 ( V_40 ) ;
V_9 = F_29 ( V_40 , V_80 , & V_40 -> V_81 . V_82 , true ) ;
if ( V_9 == 0 && V_104 -> V_112 && V_104 -> V_113 ) {
F_81 ( V_104 -> V_8 ) ;
V_9 = F_82 ( V_104 -> V_8 ) ;
if ( V_9 == 0 )
V_104 -> V_113 = false ;
}
if ( V_9 == 0 )
V_40 -> V_81 . V_82 . V_114 ++ ;
F_83 ( V_40 ) ;
if ( V_9 == 0 )
V_9 = F_84 ( V_2 ) ;
if ( V_9 < 0 ) {
F_20 ( V_109 , & V_2 -> V_21 ) ;
F_78 ( & V_2 -> V_110 -> V_111 ) ;
F_85 ( V_103 ) ;
}
}
V_108:
F_86 ( & V_2 -> V_107 ) ;
return V_9 ;
}
static int F_87 ( struct V_103 * V_103 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_23 * V_104 = & V_2 -> V_5 ;
bool V_77 = F_79 ( V_103 ) ;
int V_9 ;
F_44 ( L_5 , F_73 ( V_106 ) , V_2 -> V_21 ) ;
F_74 ( & V_2 -> V_107 ) ;
if ( V_77 && V_104 -> V_27 ) {
F_88 ( & V_104 -> V_40 . V_81 . V_82 ) ;
V_104 -> V_27 = false ;
}
V_9 = F_89 ( V_103 , NULL ) ;
if ( V_77 ) {
F_20 ( V_109 , & V_2 -> V_21 ) ;
F_29 ( & V_104 -> V_40 , V_77 ) ;
F_20 ( V_32 , & V_2 -> V_21 ) ;
F_80 ( & V_104 -> V_40 ) ;
V_104 -> V_40 . V_81 . V_82 . V_114 -- ;
F_83 ( & V_104 -> V_40 ) ;
}
F_78 ( & V_2 -> V_110 -> V_111 ) ;
F_86 ( & V_2 -> V_107 ) ;
return V_9 ;
}
static struct V_89 * F_90 ( struct V_7 * V_8 ,
V_97 * V_115 , V_97 * V_116 ,
V_97 * V_117 , V_97 * V_118 , int V_119 )
{
bool V_120 = V_8 -> V_120 == 90 || V_8 -> V_120 == 270 ;
struct V_1 * V_2 = V_8 -> V_1 ;
const struct V_121 * V_122 = V_2 -> V_123 ;
const struct V_124 * V_125 = V_122 -> V_126 ;
struct V_52 * V_127 = & V_8 -> V_17 ;
V_97 V_94 , V_128 , V_129 , V_130 , V_131 = 3 ;
V_97 V_132 = V_133 ;
struct V_89 * V_134 ;
if ( V_117 && V_8 -> V_11 . V_12 && V_119 == V_135 &&
F_60 ( V_8 -> V_11 . V_12 -> V_96 ) )
* V_117 = V_8 -> V_11 . V_12 -> V_136 ;
if ( V_118 && * V_118 != V_137 && V_119 == V_135 )
V_132 |= V_138 ;
if ( V_119 == V_139 )
V_132 = V_140 ;
V_134 = F_91 ( V_118 , V_117 , V_132 , 0 ) ;
if ( F_92 ( ! V_134 ) )
return NULL ;
if ( V_117 )
* V_117 = V_134 -> V_136 ;
if ( V_118 )
* V_118 = V_134 -> V_118 ;
if ( V_119 != V_135 ) {
V_129 = F_60 ( V_134 -> V_96 ) ?
V_125 -> V_141 : V_125 -> V_142 ;
F_93 ( V_115 , F_61 ( V_97 , * V_115 , 32 ) , V_129 , 4 ,
V_116 , F_61 ( V_97 , * V_116 , 32 ) ,
V_143 ,
F_60 ( V_134 -> V_96 ) ?
3 : 1 ,
0 ) ;
return V_134 ;
}
if ( F_60 ( V_134 -> V_96 ) ) {
* V_115 = V_8 -> V_11 . V_91 ;
* V_116 = V_8 -> V_11 . V_92 ;
return V_134 ;
}
V_129 = V_120 ? V_125 -> V_144 : V_125 -> V_145 ;
if ( V_8 -> V_21 & V_146 ) {
V_128 = V_127 -> V_147 + V_127 -> V_115 ;
V_130 = V_127 -> V_148 + V_127 -> V_116 ;
} else {
V_128 = V_122 -> V_149 ;
V_130 = V_122 -> V_149 ;
}
if ( V_122 -> V_150 == 1 && ! V_120 )
V_131 = F_94 ( V_134 -> V_96 ) ? 0 : 1 ;
V_94 = F_95 ( V_134 ) ;
F_93 ( V_115 , V_128 , V_129 ,
F_46 ( V_122 -> V_149 ) - 1 ,
V_116 , V_130 , V_143 ,
V_131 ,
64 / ( F_96 ( V_94 , 8 ) ) ) ;
F_44 ( L_6 ,
V_119 , V_117 ? * V_117 : 0 , * V_115 , * V_116 ,
V_127 -> V_91 , V_127 -> V_92 ) ;
return V_134 ;
}
static void F_97 ( struct V_7 * V_8 ,
struct V_151 * V_152 ,
int V_153 )
{
bool V_154 = V_8 -> V_120 == 90 || V_8 -> V_120 == 270 ;
struct V_1 * V_2 = V_8 -> V_1 ;
const struct V_121 * V_122 = V_2 -> V_123 ;
const struct V_124 * V_125 = V_122 -> V_126 ;
struct V_52 * V_155 = & V_8 -> V_11 ;
V_97 V_129 , V_156 , V_128 = 0 , V_130 = 0 , V_157 ;
V_97 V_158 = 0 , V_131 = 4 ;
V_97 V_159 , V_160 ;
if ( F_60 ( V_8 -> V_17 . V_12 -> V_96 ) ) {
V_152 -> V_115 = V_155 -> V_91 ;
V_152 -> V_116 = V_155 -> V_92 ;
V_152 -> V_161 = V_152 -> V_162 = 0 ;
return;
}
if ( V_153 == V_163 ) {
if ( V_8 -> V_120 != 90 && V_8 -> V_120 != 270 )
V_131 = 1 ;
V_159 = F_98 ( V_164 , 1 << ( F_46 ( V_155 -> V_115 ) - 3 ) ) ;
V_160 = F_98 ( V_165 , 1 << ( F_46 ( V_155 -> V_116 ) - 1 ) ) ;
V_157 = V_122 -> V_149 ;
} else {
V_97 V_94 = F_95 ( V_155 -> V_12 ) ;
V_158 = 64 / F_96 ( V_94 , 8 ) ;
V_157 = V_122 -> V_166 ;
V_128 = V_130 = V_157 ;
V_159 = V_160 = 1 ;
}
V_129 = F_99 ( V_97 ,
V_154 ? V_125 -> V_144 : V_125 -> V_145 ,
V_154 ? V_155 -> V_92 : V_155 -> V_91 ) ;
V_156 = F_99 ( V_97 , V_143 , V_155 -> V_92 ) ;
if ( V_153 == V_163 ) {
V_128 = F_99 ( V_97 , V_129 , V_155 -> V_91 / V_159 ) ;
V_130 = F_99 ( V_97 , V_156 , V_155 -> V_92 / V_160 ) ;
if ( V_154 ) {
F_100 ( V_159 , V_160 ) ;
F_100 ( V_128 , V_130 ) ;
}
}
F_93 ( & V_152 -> V_115 , V_128 , V_129 , F_46 ( V_157 ) - 1 ,
& V_152 -> V_116 , V_130 , V_156 , V_131 ,
V_158 ) ;
V_152 -> V_161 = F_101 ( V_97 , V_152 -> V_161 , 0 , V_155 -> V_91 - V_152 -> V_115 ) ;
V_152 -> V_162 = F_101 ( V_97 , V_152 -> V_162 , 0 , V_155 -> V_92 - V_152 -> V_116 ) ;
V_152 -> V_161 = F_102 ( V_152 -> V_161 , V_122 -> V_167 ) ;
F_44 ( L_7 ,
V_153 , V_152 -> V_161 , V_152 -> V_162 , V_152 -> V_115 , V_152 -> V_116 ,
V_155 -> V_91 , V_155 -> V_92 ) ;
}
static int F_103 ( struct V_103 * V_103 , void * V_168 ,
struct V_169 * V_24 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
F_104 ( & V_2 -> V_110 -> V_111 , V_24 , V_170 |
V_171 ) ;
return 0 ;
}
static int F_105 ( struct V_103 * V_103 , void * V_168 ,
struct V_172 * V_53 )
{
struct V_89 * V_12 ;
V_12 = F_91 ( NULL , NULL , V_133 | V_138 ,
V_53 -> V_61 ) ;
if ( ! V_12 )
return - V_13 ;
strncpy ( V_53 -> V_173 , V_12 -> V_174 , sizeof( V_53 -> V_173 ) - 1 ) ;
V_53 -> V_175 = V_12 -> V_118 ;
if ( V_12 -> V_118 == V_176 )
V_53 -> V_10 |= V_177 ;
return 0 ;
}
static struct V_178 * F_106 ( struct V_178 * V_179 )
{
struct V_180 * V_119 = & V_179 -> V_181 [ 0 ] ;
while ( ! ( V_119 -> V_10 & V_182 ) ) {
V_119 = F_107 ( V_119 ) ;
if ( ! V_119 )
break;
V_179 = V_119 -> V_82 ;
V_119 = & V_179 -> V_181 [ 0 ] ;
}
return V_179 ;
}
static int F_108 ( struct V_7 * V_8 ,
struct V_183 * V_184 ,
struct V_89 * * V_185 ,
bool V_186 )
{
struct V_1 * V_2 = V_8 -> V_1 ;
struct V_45 * V_46 = F_38 ( V_2 -> V_5 . V_40 . V_47 ) ;
struct V_48 * V_187 = V_46 -> V_50 [ V_188 ] ;
struct V_189 V_190 ;
struct V_183 * V_191 = & V_190 . V_192 ;
struct V_178 * V_179 ;
struct V_89 * V_134 ;
struct V_180 * V_119 ;
int V_9 , V_79 = 1 ;
V_97 V_193 ;
if ( F_92 ( ! V_187 || ! V_184 ) )
return - V_13 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_192 = * V_184 ;
V_190 . V_194 = V_186 ? V_195 : V_196 ;
V_179 = F_106 ( & V_187 -> V_82 ) ;
while ( 1 ) {
V_134 = F_91 ( NULL , V_191 -> V_117 != 0 ? & V_191 -> V_117 : NULL ,
V_133 , V_79 ++ ) ;
if ( V_134 == NULL ) {
return - V_13 ;
}
V_191 -> V_117 = V_184 -> V_117 = V_134 -> V_136 ;
while ( V_179 != & V_2 -> V_5 . V_197 . V_82 ) {
V_187 = F_109 ( V_179 ) ;
V_190 . V_119 = 0 ;
V_9 = F_49 ( V_187 , V_119 , V_198 , NULL , & V_190 ) ;
if ( V_9 )
return V_9 ;
if ( V_179 -> V_181 [ 0 ] . V_10 & V_199 ) {
V_190 . V_119 = V_179 -> V_200 - 1 ;
V_191 -> V_117 = V_184 -> V_117 ;
V_9 = F_49 ( V_187 , V_119 , V_198 , NULL ,
& V_190 ) ;
if ( V_9 )
return V_9 ;
}
V_119 = F_107 ( & V_179 -> V_181 [ V_190 . V_119 ] ) ;
if ( ! V_119 )
return - V_13 ;
V_179 = V_119 -> V_82 ;
}
if ( V_191 -> V_117 != V_184 -> V_117 )
continue;
V_193 = V_134 -> V_118 ;
V_184 -> V_115 = V_191 -> V_115 ;
V_184 -> V_116 = V_191 -> V_116 ;
V_134 = F_90 ( V_8 , & V_184 -> V_115 , & V_184 -> V_116 ,
NULL , & V_193 , V_201 ) ;
V_134 = F_90 ( V_8 , & V_184 -> V_115 , & V_184 -> V_116 ,
NULL , & V_193 , V_135 ) ;
if ( V_134 && V_134 -> V_136 )
V_191 -> V_117 = V_134 -> V_136 ;
if ( V_191 -> V_115 != V_184 -> V_115 || V_191 -> V_116 != V_184 -> V_116 )
continue;
V_184 -> V_117 = V_191 -> V_117 ;
break;
}
if ( V_185 && V_134 )
* V_185 = V_134 ;
* V_184 = * V_191 ;
return 0 ;
}
static int F_110 ( struct V_48 * V_202 ,
struct V_203 * V_204 ,
unsigned int V_85 , bool V_205 )
{
struct V_206 V_207 ;
int V_79 , V_9 ;
int V_119 ;
for ( V_79 = 0 ; V_79 < V_85 ; V_79 ++ )
V_207 . V_208 [ V_79 ] . V_209 = V_204 [ V_79 ] . V_210 ;
V_119 = V_202 -> V_82 . V_200 - 1 ;
if ( V_205 )
V_9 = F_49 ( V_202 , V_119 , V_211 , V_119 , & V_207 ) ;
else
V_9 = F_49 ( V_202 , V_119 , V_212 , V_119 , & V_207 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_85 != V_207 . V_213 )
return - V_13 ;
for ( V_79 = 0 ; V_79 < V_85 ; V_79 ++ )
V_204 [ V_79 ] . V_210 = V_207 . V_208 [ V_79 ] . V_209 ;
if ( V_207 . V_208 [ 0 ] . V_209 > V_214 ) {
F_64 ( V_202 -> V_215 , L_8 ,
V_207 . V_208 [ 0 ] . V_209 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_111 ( struct V_103 * V_103 , void * V_216 ,
struct V_217 * V_53 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
F_112 ( & V_2 -> V_5 . V_8 -> V_17 , V_53 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_217 * V_53 , bool V_205 ,
struct V_89 * * V_218 ,
struct V_89 * * V_219 )
{
struct V_220 * V_221 = & V_53 -> V_12 . V_222 ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_78 * V_40 = & V_104 -> V_40 ;
struct V_7 * V_8 = V_104 -> V_8 ;
unsigned int V_115 = 0 , V_116 = 0 ;
int V_9 = 0 ;
if ( F_114 ( V_221 -> V_175 ) ) {
F_90 ( V_8 , & V_221 -> V_115 , & V_221 -> V_116 ,
NULL , & V_221 -> V_175 ,
V_201 ) ;
if ( V_205 ) {
V_115 = V_221 -> V_115 ;
V_116 = V_221 -> V_116 ;
} else {
V_8 -> V_11 . V_91 = V_221 -> V_115 ;
V_8 -> V_11 . V_92 = V_221 -> V_116 ;
}
}
* V_219 = F_90 ( V_8 , & V_221 -> V_115 , & V_221 -> V_116 ,
NULL , & V_221 -> V_175 ,
V_135 ) ;
if ( * V_219 == NULL )
return - V_13 ;
if ( V_205 && F_114 ( V_221 -> V_175 ) ) {
V_221 -> V_115 = V_115 ;
V_221 -> V_116 = V_116 ;
}
if ( ! V_104 -> V_112 ) {
struct V_183 V_223 ;
struct V_183 * V_191 ;
V_191 = V_205 ? & V_223 : & V_2 -> V_5 . V_224 ;
V_191 -> V_117 = ( * V_219 ) -> V_136 ;
V_191 -> V_115 = V_221 -> V_115 ;
V_191 -> V_116 = V_221 -> V_116 ;
F_80 ( V_40 ) ;
V_9 = F_108 ( V_8 , V_191 , V_218 , V_205 ) ;
F_83 ( V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
V_221 -> V_115 = V_191 -> V_115 ;
V_221 -> V_116 = V_191 -> V_116 ;
}
F_115 ( * V_219 , V_221 -> V_115 , V_221 -> V_116 , V_221 ) ;
if ( ( * V_219 ) -> V_10 & V_225 ) {
struct V_48 * V_202 ;
F_80 ( V_40 ) ;
V_202 = F_116 ( V_40 -> V_47 , V_188 ) ;
if ( V_202 )
F_110 ( V_202 , V_221 -> V_204 ,
( * V_219 ) -> V_93 , V_205 ) ;
else
V_9 = - V_226 ;
F_83 ( V_40 ) ;
}
return V_9 ;
}
static int F_117 ( struct V_103 * V_103 , void * V_216 ,
struct V_217 * V_53 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_89 * V_219 = NULL , * V_218 = NULL ;
return F_113 ( V_2 , V_53 , true , & V_218 , & V_219 ) ;
}
static void F_118 ( struct V_7 * V_8 ,
enum V_227 V_96 )
{
bool V_228 = F_60 ( V_96 ) ;
V_8 -> V_229 . V_230 = ! V_228 ;
F_119 ( V_8 , ! V_228 ) ;
if ( V_228 )
F_32 ( V_231 , & V_8 -> V_1 -> V_21 ) ;
else
F_20 ( V_231 , & V_8 -> V_1 -> V_21 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_217 * V_53 )
{
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_7 * V_8 = V_104 -> V_8 ;
struct V_220 * V_221 = & V_53 -> V_12 . V_222 ;
struct V_52 * V_232 = & V_8 -> V_17 ;
struct V_89 * V_218 = NULL ;
int V_9 , V_79 ;
if ( F_121 ( & V_2 -> V_5 . V_102 ) )
return - V_105 ;
V_9 = F_113 ( V_2 , V_53 , false , & V_218 , & V_232 -> V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
F_122 ( V_8 ) ;
for ( V_79 = 0 ; V_79 < V_232 -> V_12 -> V_93 ; V_79 ++ ) {
V_232 -> V_233 [ V_79 ] = V_221 -> V_204 [ V_79 ] . V_233 ;
V_232 -> V_66 [ V_79 ] = V_221 -> V_204 [ V_79 ] . V_210 ;
}
F_123 ( V_232 , V_221 -> V_115 , V_221 -> V_116 ) ;
if ( ! ( V_8 -> V_21 & V_146 ) )
F_124 ( V_232 , 0 , 0 , V_221 -> V_115 , V_221 -> V_116 ) ;
F_118 ( V_8 , V_232 -> V_12 -> V_96 ) ;
if ( ! V_104 -> V_112 ) {
V_8 -> V_11 . V_12 = V_218 ;
F_123 ( & V_8 -> V_11 , V_221 -> V_115 , V_221 -> V_116 ) ;
F_124 ( & V_8 -> V_11 , 0 , 0 , V_221 -> V_115 , V_221 -> V_116 ) ;
}
return V_9 ;
}
static int F_125 ( struct V_103 * V_103 , void * V_168 ,
struct V_217 * V_53 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
return F_120 ( V_2 , V_53 ) ;
}
static int F_126 ( struct V_103 * V_103 , void * V_168 ,
struct V_234 * V_79 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_78 * V_40 = & V_2 -> V_5 . V_40 ;
struct V_48 * V_187 ;
if ( V_79 -> V_61 != 0 )
return - V_13 ;
V_79 -> type = V_235 ;
F_80 ( V_40 ) ;
V_187 = F_116 ( V_40 -> V_47 , V_188 ) ;
F_83 ( V_40 ) ;
if ( V_187 )
F_127 ( V_79 -> V_174 , V_187 -> V_174 , sizeof( V_79 -> V_174 ) ) ;
return 0 ;
}
static int F_128 ( struct V_103 * V_103 , void * V_168 , unsigned int V_79 )
{
return V_79 == 0 ? V_79 : - V_13 ;
}
static int F_129 ( struct V_103 * V_103 , void * V_168 , unsigned int * V_79 )
{
* V_79 = 0 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_189 V_236 , V_237 ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_48 * V_187 = & V_104 -> V_197 ;
struct V_45 * V_46 = F_38 ( V_104 -> V_40 . V_47 ) ;
struct V_180 * V_238 , * V_239 ;
int V_79 , V_9 ;
while ( 1 ) {
V_239 = NULL ;
for ( V_79 = 0 ; V_79 < V_187 -> V_82 . V_200 ; V_79 ++ ) {
struct V_180 * V_46 = & V_187 -> V_82 . V_181 [ V_79 ] ;
if ( V_46 -> V_10 & V_199 ) {
V_238 = V_46 ;
V_239 = F_107 ( V_238 ) ;
if ( V_239 )
break;
}
}
if ( ! V_239 || ! F_131 ( V_239 -> V_82 ) )
break;
if ( V_187 == & V_104 -> V_197 ) {
struct V_52 * V_232 = & V_104 -> V_8 -> V_11 ;
V_236 . V_192 . V_115 = V_232 -> V_91 ;
V_236 . V_192 . V_116 = V_232 -> V_92 ;
V_236 . V_192 . V_117 = V_232 -> V_12 ? V_232 -> V_12 -> V_136 : 0 ;
} else {
V_236 . V_119 = V_238 -> V_61 ;
V_236 . V_194 = V_195 ;
V_9 = F_49 ( V_187 , V_119 , V_240 , NULL , & V_236 ) ;
if ( V_9 < 0 && V_9 != - V_241 )
return - V_226 ;
}
V_187 = F_109 ( V_239 -> V_82 ) ;
V_237 . V_119 = V_239 -> V_61 ;
V_237 . V_194 = V_195 ;
V_9 = F_49 ( V_187 , V_119 , V_240 , NULL , & V_237 ) ;
if ( V_9 < 0 && V_9 != - V_241 )
return - V_226 ;
if ( V_237 . V_192 . V_115 != V_236 . V_192 . V_115 ||
V_237 . V_192 . V_116 != V_236 . V_192 . V_116 ||
V_237 . V_192 . V_117 != V_236 . V_192 . V_117 )
return - V_226 ;
if ( V_187 == V_46 -> V_50 [ V_188 ] &&
F_132 ( V_237 . V_192 . V_117 ) ) {
struct V_203 V_204 [ V_242 ] ;
struct V_52 * V_88 = & V_104 -> V_8 -> V_17 ;
unsigned int V_79 ;
V_9 = F_110 ( V_187 , V_204 ,
V_88 -> V_12 -> V_93 ,
false ) ;
if ( V_9 < 0 )
return - V_226 ;
for ( V_79 = 0 ; V_79 < V_88 -> V_12 -> V_93 ; V_79 ++ )
if ( V_88 -> V_66 [ V_79 ] < V_204 [ V_79 ] . V_210 )
return - V_226 ;
}
}
return 0 ;
}
static int F_133 ( struct V_103 * V_103 , void * V_168 ,
enum V_243 type )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_178 * V_82 = & V_104 -> V_40 . V_81 . V_82 ;
struct V_3 * V_4 = NULL ;
struct V_48 * V_187 ;
int V_9 ;
if ( F_31 ( V_2 ) )
return - V_105 ;
V_9 = F_134 ( V_82 , & V_104 -> V_40 . V_47 -> V_244 ) ;
if ( V_9 < 0 )
return V_9 ;
V_187 = F_116 ( V_104 -> V_40 . V_47 , V_188 ) ;
if ( V_187 )
V_4 = F_135 ( V_187 ) ;
if ( V_4 == NULL ) {
V_9 = - V_226 ;
goto V_245;
}
V_104 -> V_6 = * V_4 ;
if ( V_104 -> V_246 == V_247 )
V_104 -> V_6 . V_14 = V_15 ;
if ( V_104 -> V_112 ) {
V_9 = F_130 ( V_2 ) ;
if ( V_9 < 0 )
goto V_245;
}
V_9 = F_136 ( V_103 , V_168 , type ) ;
if ( ! V_9 ) {
V_104 -> V_27 = true ;
return V_9 ;
}
V_245:
F_88 ( V_82 ) ;
return V_9 ;
}
static int F_137 ( struct V_103 * V_103 , void * V_168 ,
enum V_243 type )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_23 * V_104 = & V_2 -> V_5 ;
int V_9 ;
V_9 = F_138 ( V_103 , V_168 , type ) ;
if ( V_9 < 0 )
return V_9 ;
F_88 ( & V_104 -> V_40 . V_81 . V_82 ) ;
V_104 -> V_27 = false ;
return 0 ;
}
static int F_139 ( struct V_103 * V_103 , void * V_168 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
int V_9 ;
V_9 = F_140 ( V_103 , V_168 , V_249 ) ;
if ( ! V_9 )
V_2 -> V_5 . V_76 = V_249 -> V_73 ;
return V_9 ;
}
static int F_141 ( struct V_103 * V_103 , void * V_216 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
if ( V_251 -> type != V_252 )
return - V_13 ;
switch ( V_251 -> V_153 ) {
case V_253 :
case V_254 :
V_53 = & V_8 -> V_17 ;
case V_255 :
case V_256 :
V_251 -> V_152 . V_161 = 0 ;
V_251 -> V_152 . V_162 = 0 ;
V_251 -> V_152 . V_115 = V_53 -> V_257 ;
V_251 -> V_152 . V_116 = V_53 -> V_258 ;
return 0 ;
case V_163 :
V_53 = & V_8 -> V_17 ;
case V_259 :
V_251 -> V_152 . V_161 = V_53 -> V_147 ;
V_251 -> V_152 . V_162 = V_53 -> V_148 ;
V_251 -> V_152 . V_115 = V_53 -> V_115 ;
V_251 -> V_152 . V_116 = V_53 -> V_116 ;
return 0 ;
}
return - V_13 ;
}
static int F_142 ( struct V_151 * V_260 , struct V_151 * V_261 )
{
if ( V_260 -> V_161 < V_261 -> V_161 || V_260 -> V_162 < V_261 -> V_162 )
return 0 ;
if ( V_260 -> V_161 + V_260 -> V_115 > V_261 -> V_161 + V_261 -> V_115 )
return 0 ;
if ( V_260 -> V_162 + V_260 -> V_116 > V_261 -> V_162 + V_261 -> V_116 )
return 0 ;
return 1 ;
}
static int F_143 ( struct V_103 * V_103 , void * V_216 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_72 ( V_103 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_151 V_262 = V_251 -> V_152 ;
struct V_52 * V_53 ;
unsigned long V_10 ;
if ( V_251 -> type != V_252 )
return - V_13 ;
if ( V_251 -> V_153 == V_163 )
V_53 = & V_8 -> V_17 ;
else if ( V_251 -> V_153 == V_259 )
V_53 = & V_8 -> V_11 ;
else
return - V_13 ;
F_97 ( V_8 , & V_262 , V_251 -> V_153 ) ;
if ( V_251 -> V_10 & V_263 &&
! F_142 ( & V_262 , & V_251 -> V_152 ) )
return - V_264 ;
if ( V_251 -> V_10 & V_265 &&
! F_142 ( & V_251 -> V_152 , & V_262 ) )
return - V_264 ;
V_251 -> V_152 = V_262 ;
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_124 ( V_53 , V_251 -> V_152 . V_161 , V_251 -> V_152 . V_162 , V_251 -> V_152 . V_115 ,
V_251 -> V_152 . V_116 ) ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
F_32 ( V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
static int F_144 ( struct V_178 * V_82 ,
const struct V_180 * V_266 ,
const struct V_180 * V_267 , V_97 V_10 )
{
struct V_48 * V_187 = F_109 ( V_82 ) ;
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_48 * V_202 ;
if ( ! F_131 ( V_267 -> V_82 ) )
return - V_13 ;
if ( F_92 ( V_2 == NULL ) )
return 0 ;
F_44 ( L_9 ,
V_266 -> V_82 -> V_174 , V_267 -> V_82 -> V_174 , V_10 ,
V_2 -> V_5 . V_246 ) ;
if ( ! ( V_10 & V_268 ) ) {
V_2 -> V_5 . V_246 = 0 ;
return 0 ;
}
if ( V_104 -> V_246 != 0 )
return - V_105 ;
V_104 -> V_246 = V_187 -> V_269 ;
if ( V_104 -> V_112 || V_104 -> V_113 )
return 0 ;
V_202 = F_146 ( & V_104 -> V_197 . V_82 ) ;
if ( V_202 == NULL )
return 0 ;
return F_147 ( & V_104 -> V_8 -> V_270 . V_271 ,
V_202 -> V_272 , NULL ) ;
}
void F_148 ( struct V_48 * V_187 , unsigned int V_273 ,
void * V_274 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 ;
struct V_275 * V_276 ;
struct V_1 * V_2 ;
unsigned long V_10 ;
if ( V_187 == NULL )
return;
V_4 = F_135 ( V_187 ) ;
V_276 = F_149 ( & V_187 -> V_82 ) ;
F_3 ( & V_276 -> V_16 , V_10 ) ;
V_2 = V_4 ? F_150 ( V_4 ) -> V_277 : NULL ;
if ( V_2 && V_274 && V_273 == V_278 &&
F_35 ( V_33 , & V_2 -> V_21 ) ) {
unsigned long V_279 ;
F_3 ( & V_2 -> V_16 , V_279 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_38 ) ) {
V_26 = F_151 ( V_2 -> V_5 . V_38 . V_280 ,
struct V_25 , V_281 ) ;
F_65 ( & V_26 -> V_35 . V_36 , 0 ,
* ( ( V_97 * ) V_274 ) ) ;
}
F_37 ( V_2 , 1 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_16 , V_279 ) ;
}
F_21 ( & V_276 -> V_16 , V_10 ) ;
}
static int F_152 ( struct V_48 * V_187 ,
struct V_282 * V_283 ,
struct V_284 * V_117 )
{
struct V_89 * V_12 ;
V_12 = F_91 ( NULL , NULL , V_133 , V_117 -> V_61 ) ;
if ( ! V_12 )
return - V_13 ;
V_117 -> V_117 = V_12 -> V_136 ;
return 0 ;
}
static int F_153 ( struct V_48 * V_187 ,
struct V_282 * V_283 ,
struct V_189 * V_12 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_232 = & V_8 -> V_11 ;
struct V_183 * V_191 ;
if ( V_12 -> V_194 == V_196 ) {
V_191 = F_154 ( V_187 , V_283 , V_12 -> V_119 ) ;
V_12 -> V_192 = * V_191 ;
return 0 ;
}
V_191 = & V_12 -> V_192 ;
F_74 ( & V_2 -> V_107 ) ;
switch ( V_12 -> V_119 ) {
case V_135 :
if ( ! F_92 ( V_232 -> V_12 == NULL ) )
V_191 -> V_117 = V_232 -> V_12 -> V_136 ;
V_191 -> V_115 = V_232 -> V_115 ;
V_191 -> V_116 = V_232 -> V_116 ;
break;
case V_139 :
* V_191 = V_2 -> V_5 . V_285 ;
break;
case V_201 :
default:
* V_191 = V_2 -> V_5 . V_224 ;
break;
}
F_86 ( & V_2 -> V_107 ) ;
V_191 -> V_286 = V_287 ;
return 0 ;
}
static int F_155 ( struct V_48 * V_187 ,
struct V_282 * V_283 ,
struct V_189 * V_12 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_183 * V_191 = & V_12 -> V_192 ;
struct V_23 * V_104 = & V_2 -> V_5 ;
struct V_7 * V_8 = V_104 -> V_8 ;
struct V_52 * V_232 ;
struct V_89 * V_134 ;
F_44 ( L_10 ,
V_12 -> V_119 , V_191 -> V_117 , V_191 -> V_115 , V_191 -> V_116 ) ;
if ( V_12 -> V_119 == V_135 && F_121 ( & V_104 -> V_102 ) )
return - V_105 ;
F_74 ( & V_2 -> V_107 ) ;
V_134 = F_90 ( V_8 , & V_191 -> V_115 , & V_191 -> V_116 ,
& V_191 -> V_117 , NULL , V_12 -> V_119 ) ;
F_86 ( & V_2 -> V_107 ) ;
V_191 -> V_286 = V_287 ;
if ( V_12 -> V_194 == V_196 ) {
V_191 = F_154 ( V_187 , V_283 , V_12 -> V_119 ) ;
* V_191 = V_12 -> V_192 ;
return 0 ;
}
if ( F_92 ( V_134 == NULL ) )
return - V_13 ;
F_122 ( V_8 ) ;
F_118 ( V_8 , V_134 -> V_96 ) ;
if ( V_12 -> V_119 == V_135 ) {
V_232 = & V_8 -> V_17 ;
V_191 -> V_115 = V_8 -> V_11 . V_115 ;
V_191 -> V_116 = V_8 -> V_11 . V_116 ;
} else {
V_232 = & V_8 -> V_11 ;
}
F_74 ( & V_2 -> V_107 ) ;
F_123 ( V_232 , V_191 -> V_115 , V_191 -> V_116 ) ;
if ( V_12 -> V_119 == V_139 )
V_104 -> V_285 = * V_191 ;
else if ( V_12 -> V_119 == V_201 )
V_104 -> V_224 = * V_191 ;
V_232 -> V_12 = V_134 ;
if ( ! ( V_12 -> V_119 == V_135 && ( V_8 -> V_21 & V_146 ) ) )
F_124 ( V_232 , 0 , 0 , V_191 -> V_115 , V_191 -> V_116 ) ;
if ( V_12 -> V_119 != V_135 )
V_8 -> V_21 &= ~ V_146 ;
F_86 ( & V_2 -> V_107 ) ;
return 0 ;
}
static int F_156 ( struct V_48 * V_187 ,
struct V_282 * V_283 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
struct V_151 * V_152 = & V_289 -> V_152 ;
struct V_151 * V_290 ;
if ( V_289 -> V_119 == V_135 )
return - V_13 ;
F_74 ( & V_2 -> V_107 ) ;
switch ( V_289 -> V_153 ) {
case V_254 :
V_53 = & V_8 -> V_17 ;
case V_255 :
V_152 -> V_115 = V_53 -> V_257 ;
V_152 -> V_116 = V_53 -> V_258 ;
V_152 -> V_161 = 0 ;
V_152 -> V_162 = 0 ;
F_86 ( & V_2 -> V_107 ) ;
return 0 ;
case V_259 :
V_290 = F_157 ( V_187 , V_283 , V_289 -> V_119 ) ;
break;
case V_163 :
V_290 = F_158 ( V_187 , V_283 , V_289 -> V_119 ) ;
V_53 = & V_8 -> V_17 ;
break;
default:
F_86 ( & V_2 -> V_107 ) ;
return - V_13 ;
}
if ( V_289 -> V_194 == V_196 ) {
V_289 -> V_152 = * V_290 ;
} else {
V_152 -> V_161 = V_53 -> V_147 ;
V_152 -> V_162 = V_53 -> V_148 ;
V_152 -> V_115 = V_53 -> V_115 ;
V_152 -> V_116 = V_53 -> V_116 ;
}
F_44 ( L_11 ,
V_289 -> V_119 , V_152 -> V_161 , V_152 -> V_162 , V_152 -> V_115 , V_152 -> V_116 ,
V_53 -> V_91 , V_53 -> V_92 ) ;
F_86 ( & V_2 -> V_107 ) ;
return 0 ;
}
static int F_159 ( struct V_48 * V_187 ,
struct V_282 * V_283 ,
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_7 * V_8 = V_2 -> V_5 . V_8 ;
struct V_52 * V_53 = & V_8 -> V_11 ;
struct V_151 * V_152 = & V_289 -> V_152 ;
struct V_151 * V_290 ;
unsigned long V_10 ;
if ( V_289 -> V_119 == V_135 )
return - V_13 ;
F_74 ( & V_2 -> V_107 ) ;
F_97 ( V_8 , V_152 , V_259 ) ;
switch ( V_289 -> V_153 ) {
case V_259 :
V_290 = F_157 ( V_187 , V_283 , V_289 -> V_119 ) ;
break;
case V_163 :
V_290 = F_158 ( V_187 , V_283 , V_289 -> V_119 ) ;
V_53 = & V_8 -> V_17 ;
break;
default:
F_86 ( & V_2 -> V_107 ) ;
return - V_13 ;
}
if ( V_289 -> V_194 == V_196 ) {
* V_290 = V_289 -> V_152 ;
} else {
F_3 ( & V_2 -> V_16 , V_10 ) ;
F_124 ( V_53 , V_152 -> V_161 , V_152 -> V_162 , V_152 -> V_115 , V_152 -> V_116 ) ;
F_32 ( V_20 , & V_2 -> V_21 ) ;
if ( V_289 -> V_153 == V_163 )
V_8 -> V_21 |= V_146 ;
F_21 ( & V_2 -> V_16 , V_10 ) ;
}
F_44 ( L_12 , V_289 -> V_153 , V_152 -> V_161 , V_152 -> V_162 ,
V_152 -> V_115 , V_152 -> V_116 ) ;
F_86 ( & V_2 -> V_107 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_217 V_12 = {
. type = V_252 ,
. V_12 . V_222 = {
. V_115 = V_291 ,
. V_116 = V_292 ,
. V_175 = V_293 ,
. V_294 = V_295 ,
. V_286 = V_287 ,
} ,
} ;
return F_120 ( V_2 , & V_12 ) ;
}
static int F_160 ( struct V_1 * V_2 ,
struct V_296 * V_215 )
{
struct V_297 * V_298 = & V_2 -> V_5 . V_40 . V_81 ;
struct V_71 * V_72 = & V_2 -> V_5 . V_102 ;
struct V_7 * V_8 ;
struct V_23 * V_5 ;
struct V_89 * V_12 ;
int V_9 = - V_299 ;
V_8 = F_161 ( sizeof( * V_8 ) , V_300 ) ;
if ( ! V_8 )
return - V_299 ;
V_8 -> V_1 = V_2 ;
V_8 -> V_301 = V_302 ;
V_8 -> V_303 = V_304 ;
V_8 -> V_21 = V_305 ;
V_8 -> V_11 . V_12 = F_91 ( NULL , NULL , V_133 , 0 ) ;
V_8 -> V_17 . V_12 = V_8 -> V_11 . V_12 ;
memset ( V_298 , 0 , sizeof( * V_298 ) ) ;
snprintf ( V_298 -> V_174 , sizeof( V_298 -> V_174 ) , L_13 , V_2 -> V_306 ) ;
V_298 -> V_307 = & V_308 ;
V_298 -> V_309 = & V_310 ;
V_298 -> V_215 = V_215 ;
V_298 -> V_311 = - 1 ;
V_298 -> V_312 = V_313 ;
V_298 -> V_314 = V_72 ;
V_298 -> V_107 = & V_2 -> V_107 ;
F_162 ( V_298 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_70 = 0 ;
V_5 -> V_76 = 0 ;
V_5 -> V_8 = V_8 ;
F_57 ( & V_5 -> V_34 ) ;
F_57 ( & V_5 -> V_38 ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> type = V_252 ;
V_72 -> V_315 = V_316 | V_317 | V_318 ;
V_72 -> V_74 = V_8 ;
V_72 -> V_319 = & V_320 ;
V_72 -> V_321 = & V_322 ;
V_72 -> V_323 = sizeof( struct V_25 ) ;
V_72 -> V_324 = V_325 ;
V_72 -> V_107 = & V_2 -> V_107 ;
V_9 = F_163 ( V_72 ) ;
if ( V_9 )
goto V_326;
V_12 = F_91 ( NULL , NULL , V_133 , 0 ) ;
V_5 -> V_224 . V_115 = V_291 ;
V_5 -> V_224 . V_116 = V_292 ;
V_5 -> V_224 . V_117 = V_12 -> V_136 ;
V_8 -> V_11 . V_115 = V_291 ;
V_8 -> V_11 . V_116 = V_292 ;
V_8 -> V_11 . V_12 = V_12 ;
V_12 = F_91 ( NULL , NULL , V_140 , 0 ) ;
V_5 -> V_285 = V_5 -> V_224 ;
V_5 -> V_285 . V_117 = V_12 -> V_136 ;
V_5 -> V_327 . V_10 = V_199 ;
V_9 = F_164 ( & V_298 -> V_82 , 1 , & V_5 -> V_327 ) ;
if ( V_9 )
goto V_326;
V_9 = F_82 ( V_8 ) ;
if ( V_9 )
goto V_328;
V_9 = F_165 ( V_298 , V_329 , - 1 ) ;
if ( V_9 )
goto V_330;
F_166 ( V_215 , L_14 ,
V_298 -> V_174 , F_167 ( V_298 ) ) ;
V_298 -> V_272 = & V_8 -> V_270 . V_271 ;
return 0 ;
V_330:
F_81 ( V_8 ) ;
V_328:
F_168 ( & V_298 -> V_82 ) ;
V_326:
F_169 ( V_8 ) ;
return V_9 ;
}
static int F_170 ( struct V_48 * V_187 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
int V_9 ;
if ( V_2 == NULL )
return - V_331 ;
V_9 = F_171 ( V_2 , V_187 -> V_215 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_5 . V_40 . V_47 = F_135 ( V_187 ) ;
V_9 = F_160 ( V_2 , V_187 -> V_215 ) ;
if ( V_9 ) {
F_172 ( V_2 ) ;
V_2 -> V_5 . V_40 . V_47 = NULL ;
}
return V_9 ;
}
static void F_173 ( struct V_48 * V_187 )
{
struct V_1 * V_2 = F_145 ( V_187 ) ;
struct V_297 * V_81 ;
if ( V_2 == NULL )
return;
F_74 ( & V_2 -> V_107 ) ;
F_172 ( V_2 ) ;
V_81 = & V_2 -> V_5 . V_40 . V_81 ;
if ( F_174 ( V_81 ) ) {
F_175 ( V_81 ) ;
F_168 ( & V_81 -> V_82 ) ;
F_81 ( V_2 -> V_5 . V_8 ) ;
V_2 -> V_5 . V_40 . V_47 = NULL ;
}
F_169 ( V_2 -> V_5 . V_8 ) ;
V_2 -> V_5 . V_8 = NULL ;
F_86 ( & V_2 -> V_107 ) ;
}
int F_176 ( struct V_1 * V_2 )
{
struct V_48 * V_187 = & V_2 -> V_5 . V_197 ;
int V_9 ;
F_177 ( V_187 , & V_332 ) ;
V_187 -> V_10 |= V_333 ;
snprintf ( V_187 -> V_174 , sizeof( V_187 -> V_174 ) , L_15 , V_2 -> V_306 ) ;
V_2 -> V_5 . V_334 [ V_201 ] . V_10 = V_199 ;
V_2 -> V_5 . V_334 [ V_139 ] . V_10 = V_199 ;
V_2 -> V_5 . V_334 [ V_135 ] . V_10 = V_182 ;
V_9 = F_164 ( & V_187 -> V_82 , V_335 ,
V_2 -> V_5 . V_334 ) ;
if ( V_9 )
return V_9 ;
V_187 -> V_82 . V_319 = & V_336 ;
V_187 -> V_337 = & V_338 ;
F_178 ( V_187 , V_2 ) ;
return 0 ;
}
void F_179 ( struct V_1 * V_2 )
{
struct V_48 * V_187 = & V_2 -> V_5 . V_197 ;
F_180 ( V_187 ) ;
F_168 ( & V_187 -> V_82 ) ;
F_178 ( V_187 , NULL ) ;
}
