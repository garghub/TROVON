static const struct V_1 * F_1 ( const T_1 * V_2 ,
const T_1 * V_3 , int V_4 )
{
const struct V_1 * V_5 , * V_6 = NULL ;
unsigned int V_7 ;
int V_8 = 0 ;
if ( V_4 >= ( int ) F_2 ( V_9 ) )
return NULL ;
for ( V_7 = 0 ; V_7 < F_2 ( V_9 ) ; ++ V_7 ) {
V_5 = & V_9 [ V_7 ] ;
if ( V_2 && V_5 -> V_10 == * V_2 )
return V_5 ;
if ( V_3 && V_5 -> V_3 == * V_3 )
return V_5 ;
if ( V_4 == V_8 )
V_6 = V_5 ;
V_8 ++ ;
}
return V_6 ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
if ( V_14 -> V_18 [ V_19 ] == NULL )
return - V_20 ;
if ( V_12 -> V_5 == NULL )
return - V_21 ;
V_16 = F_4 ( V_14 -> V_18 [ V_19 ] ) ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
F_6 ( V_12 , & V_16 -> V_23 ) ;
F_7 ( V_12 , & V_12 -> V_24 ) ;
F_8 ( V_12 , & V_12 -> V_24 ) ;
F_9 ( V_12 , & V_12 -> V_25 , true ) ;
F_10 ( V_12 ) ;
F_11 ( V_12 , V_12 -> V_26 -> V_27 ) ;
if ( V_28 > 0 )
F_12 ( V_12 , V_29 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , bool V_30 )
{
struct V_31 * V_32 ;
unsigned long V_17 ;
bool V_33 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_33 = V_12 -> V_34 & ( 1 << V_35 ) ;
V_12 -> V_34 &= ~ ( 1 << V_36 | 1 << V_37 |
1 << V_38 | 1 << V_35 ) ;
if ( V_30 )
V_12 -> V_34 |= ( 1 << V_39 ) ;
else
V_12 -> V_34 &= ~ ( 1 << V_40 |
1 << V_39 ) ;
while ( ! V_30 && ! F_15 ( & V_12 -> V_41 ) ) {
V_32 = F_16 ( V_12 ) ;
F_17 ( & V_32 -> V_42 , V_43 ) ;
}
while ( ! F_15 ( & V_12 -> V_44 ) ) {
V_32 = F_18 ( V_12 ) ;
if ( V_30 )
F_19 ( V_12 , V_32 ) ;
else
F_17 ( & V_32 -> V_42 , V_43 ) ;
}
F_13 ( & V_12 -> V_22 , V_17 ) ;
F_20 ( V_12 ) ;
if ( ! V_33 )
return 0 ;
return F_21 ( V_12 , V_45 , & V_12 -> V_14 , 0 ) ;
}
static int F_22 ( struct V_11 * V_12 , bool V_30 )
{
unsigned long V_17 ;
if ( ! F_23 ( V_12 ) )
return 0 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
F_24 ( V_37 , & V_12 -> V_34 ) ;
F_25 ( V_12 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
F_26 ( V_12 -> V_46 ,
! F_27 ( V_37 , & V_12 -> V_34 ) ,
( 2 * V_47 / 10 ) ) ;
return F_14 ( V_12 , V_30 ) ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_8 ( V_12 , & V_12 -> V_24 ) ;
F_29 ( V_12 , & V_12 -> V_25 ) ;
F_11 ( V_12 , V_12 -> V_26 -> V_27 ) ;
F_30 ( V_48 , & V_12 -> V_34 ) ;
}
static T_2 F_31 ( int V_49 , void * V_50 )
{
struct V_11 * V_12 = V_50 ;
struct V_31 * V_51 ;
unsigned long V_17 ;
struct V_52 * V_53 ;
struct V_54 V_55 ;
T_1 V_56 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_56 = F_32 ( V_12 ) ;
F_33 ( V_12 ) ;
if ( F_34 ( V_37 , & V_12 -> V_34 ) ) {
F_35 ( & V_12 -> V_46 ) ;
goto V_57;
}
if ( V_56 & V_58 ) {
F_30 ( V_36 , & V_12 -> V_34 ) ;
V_12 -> V_59 . V_60 ++ ;
}
if ( V_56 & V_61 ) {
F_36 ( V_12 ) ;
F_30 ( V_38 , & V_12 -> V_34 ) ;
F_35 ( & V_12 -> V_46 ) ;
}
if ( V_12 -> V_62 != V_63 )
goto V_57;
if ( ( V_56 & V_64 ) &&
F_27 ( V_36 , & V_12 -> V_34 ) &&
! F_15 ( & V_12 -> V_44 ) &&
! F_15 ( & V_12 -> V_41 ) ) {
V_51 = F_18 ( V_12 ) ;
F_37 ( & V_55 ) ;
V_53 = & V_51 -> V_42 . V_65 . V_66 ;
V_53 -> V_67 = V_55 . V_67 ;
V_53 -> V_68 = V_55 . V_69 / V_70 ;
V_51 -> V_42 . V_65 . V_71 = V_12 -> V_72 ++ ;
F_17 ( & V_51 -> V_42 , V_73 ) ;
V_51 = F_16 ( V_12 ) ;
F_38 ( V_12 , V_51 -> V_74 ) ;
F_39 ( V_12 , V_51 ) ;
}
if ( F_27 ( V_48 , & V_12 -> V_34 ) )
F_28 ( V_12 ) ;
if ( F_15 ( & V_12 -> V_41 ) ) {
F_25 ( V_12 ) ;
F_30 ( V_38 , & V_12 -> V_34 ) ;
}
V_57:
F_24 ( V_36 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
return V_75 ;
}
static int F_40 ( struct V_76 * V_77 , unsigned int V_78 )
{
struct V_11 * V_12 = V_77 -> V_79 ;
int V_80 ;
V_12 -> V_72 = 0 ;
V_80 = F_3 ( V_12 ) ;
if ( V_80 ) {
F_14 ( V_12 , false ) ;
return V_80 ;
}
F_24 ( V_40 , & V_12 -> V_34 ) ;
if ( ! F_15 ( & V_12 -> V_44 ) &&
! F_41 ( V_38 , & V_12 -> V_34 ) ) {
F_42 ( V_12 ) ;
if ( ! F_41 ( V_35 , & V_12 -> V_34 ) )
F_21 ( V_12 , V_45 ,
& V_12 -> V_14 , 1 ) ;
}
if ( V_28 > 0 )
F_12 ( V_12 , V_29 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = V_77 -> V_79 ;
if ( ! F_23 ( V_12 ) )
return - V_21 ;
return F_22 ( V_12 , false ) ;
}
static int F_44 ( struct V_76 * V_81 , const struct V_82 * V_83 ,
unsigned int * V_84 , unsigned int * V_85 ,
unsigned int V_86 [] , void * V_87 [] )
{
const struct V_88 * V_89 = NULL ;
struct V_11 * V_12 = V_81 -> V_79 ;
struct V_90 * V_91 = & V_12 -> V_25 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
unsigned long V_92 ;
int V_7 ;
if ( V_83 ) {
V_89 = & V_83 -> V_5 . V_93 ;
V_5 = F_1 ( & V_89 -> V_2 , NULL , - 1 ) ;
V_92 = V_89 -> V_94 * V_89 -> V_95 ;
} else {
V_92 = V_91 -> V_96 * V_91 -> V_97 ;
}
if ( V_5 == NULL )
return - V_21 ;
* V_85 = V_5 -> V_98 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_98 ; V_7 ++ ) {
unsigned int V_99 = ( V_92 * V_5 -> V_100 [ V_7 ] ) / 8 ;
if ( V_89 )
V_86 [ V_7 ] = F_45 ( V_99 , V_89 -> V_101 [ V_7 ] . V_102 ) ;
else
V_86 [ V_7 ] = V_99 ;
V_87 [ V_7 ] = V_12 -> V_103 ;
}
return 0 ;
}
static int F_46 ( struct V_104 * V_42 )
{
struct V_76 * V_81 = V_42 -> V_76 ;
struct V_11 * V_12 = V_81 -> V_79 ;
int V_7 ;
if ( V_12 -> V_5 == NULL )
return - V_21 ;
for ( V_7 = 0 ; V_7 < V_12 -> V_5 -> V_98 ; V_7 ++ ) {
unsigned long V_99 = V_12 -> V_105 [ V_7 ] ;
if ( F_47 ( V_42 , V_7 ) < V_99 ) {
F_48 ( & V_12 -> V_106 ,
L_1 ,
F_47 ( V_42 , V_7 ) , V_99 ) ;
return - V_21 ;
}
F_49 ( V_42 , V_7 , V_99 ) ;
}
return 0 ;
}
static void F_50 ( struct V_104 * V_42 )
{
struct V_31 * V_32
= F_51 ( V_42 , struct V_31 , V_42 ) ;
struct V_11 * V_12 = F_52 ( V_42 -> V_76 ) ;
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_32 -> V_74 = F_53 ( V_42 , 0 ) ;
if ( ! F_27 ( V_39 , & V_12 -> V_34 ) &&
! F_27 ( V_38 , & V_12 -> V_34 ) &&
F_15 ( & V_12 -> V_44 ) ) {
F_38 ( V_12 , V_32 -> V_74 ) ;
F_39 ( V_12 , V_32 ) ;
} else {
F_19 ( V_12 , V_32 ) ;
}
if ( F_54 ( & V_12 -> V_107 ) &&
! F_15 ( & V_12 -> V_41 ) &&
! F_41 ( V_38 , & V_12 -> V_34 ) ) {
F_42 ( V_12 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_41 ( V_35 , & V_12 -> V_34 ) )
F_21 ( V_12 , V_45 ,
& V_12 -> V_14 , 1 ) ;
return;
}
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
static void F_55 ( struct V_76 * V_81 )
{
struct V_11 * V_12 = F_52 ( V_81 ) ;
F_56 ( & V_12 -> V_108 ) ;
}
static void F_57 ( struct V_76 * V_81 )
{
struct V_11 * V_12 = F_52 ( V_81 ) ;
F_58 ( & V_12 -> V_108 ) ;
}
static void F_59 ( struct V_11 * V_12 )
{
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
memset ( & V_12 -> V_59 , 0 , sizeof( V_12 -> V_59 ) ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
static int F_60 ( struct V_109 * V_109 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
int V_80 ;
if ( F_62 ( & V_12 -> V_108 ) )
return - V_110 ;
F_24 ( V_111 , & V_12 -> V_34 ) ;
V_80 = F_63 ( & V_12 -> V_112 -> V_113 ) ;
if ( V_80 < 0 )
goto V_57;
V_80 = F_64 ( V_109 ) ;
if ( V_80 < 0 )
goto V_57;
if ( ++ V_12 -> V_114 == 1 && V_12 -> V_62 == V_63 ) {
V_80 = F_21 ( V_12 , V_115 , & V_12 -> V_14 ,
& V_12 -> V_106 . V_116 , true ) ;
if ( V_80 < 0 ) {
F_65 ( & V_12 -> V_112 -> V_113 ) ;
V_12 -> V_114 -- ;
F_66 ( V_109 ) ;
F_30 ( V_111 , & V_12 -> V_34 ) ;
}
F_59 ( V_12 ) ;
}
V_57:
F_58 ( & V_12 -> V_108 ) ;
return V_80 ;
}
static int F_67 ( struct V_109 * V_109 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
int V_80 ;
F_56 ( & V_12 -> V_108 ) ;
if ( -- V_12 -> V_114 == 0 && V_12 -> V_62 == V_63 ) {
F_30 ( V_111 , & V_12 -> V_34 ) ;
F_22 ( V_12 , false ) ;
F_21 ( V_12 , V_117 , & V_12 -> V_14 ) ;
F_30 ( V_39 , & V_12 -> V_34 ) ;
}
F_68 ( & V_12 -> V_112 -> V_113 ) ;
if ( V_12 -> V_114 == 0 )
F_69 ( & V_12 -> V_107 ) ;
V_80 = F_66 ( V_109 ) ;
F_58 ( & V_12 -> V_108 ) ;
return V_80 ;
}
static unsigned int F_70 ( struct V_109 * V_109 ,
struct V_118 * V_119 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
int V_80 ;
if ( F_62 ( & V_12 -> V_108 ) )
return V_120 ;
V_80 = F_71 ( & V_12 -> V_107 , V_109 , V_119 ) ;
F_58 ( & V_12 -> V_108 ) ;
return V_80 ;
}
static int F_72 ( struct V_109 * V_109 , struct V_121 * V_122 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
int V_80 ;
if ( F_62 ( & V_12 -> V_108 ) )
return - V_110 ;
V_80 = F_73 ( & V_12 -> V_107 , V_122 ) ;
F_58 ( & V_12 -> V_108 ) ;
return V_80 ;
}
static const struct V_1 * F_74 ( struct V_11 * V_12 ,
T_1 * V_94 , T_1 * V_95 ,
T_1 * V_123 , T_1 * V_10 , int V_124 )
{
struct V_125 * V_126 = V_12 -> V_126 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( V_10 , V_123 , 0 ) ;
if ( F_75 ( ! V_5 ) )
return NULL ;
if ( V_123 )
* V_123 = V_5 -> V_3 ;
if ( V_10 )
* V_10 = V_5 -> V_10 ;
if ( V_124 == V_127 ) {
F_76 ( V_94 , 8 , V_126 -> V_128 ,
F_77 ( V_126 -> V_129 ) - 1 ,
V_95 , 0 , V_126 -> V_130 , 0 , 0 ) ;
} else {
F_76 ( V_94 , 8 , V_12 -> V_24 . V_131 . V_94 ,
F_77 ( V_126 -> V_129 ) - 1 ,
V_95 , 0 , V_12 -> V_24 . V_131 . V_95 ,
0 , 0 ) ;
}
F_78 ( 1 , V_28 , & V_12 -> V_132 , L_2 ,
V_123 ? * V_123 : 0 , * V_94 , * V_95 ) ;
return V_5 ;
}
static void F_79 ( struct V_11 * V_12 , struct V_133 * V_134 )
{
struct V_90 * V_91 = & V_12 -> V_24 ;
F_76 ( & V_134 -> V_94 , 0 , V_91 -> V_96 , 0 ,
& V_134 -> V_95 , 0 , V_91 -> V_97 , 0 , 0 ) ;
V_134 -> V_135 = F_80 ( T_1 , V_134 -> V_135 , 0 , V_91 -> V_96 - V_134 -> V_94 ) ;
V_134 -> V_135 = F_81 ( V_134 -> V_135 , V_12 -> V_126 -> V_136 ) ;
V_134 -> V_137 = F_80 ( T_1 , V_134 -> V_137 , 0 , V_91 -> V_97 - V_134 -> V_95 ) ;
F_78 ( 1 , V_28 , & V_12 -> V_132 , L_3 ,
V_134 -> V_135 , V_134 -> V_137 , V_134 -> V_94 , V_134 -> V_95 ,
V_91 -> V_96 , V_91 -> V_97 ) ;
}
static void F_82 ( struct V_11 * V_12 , struct V_133 * V_134 )
{
struct V_90 * V_91 = & V_12 -> V_25 ;
struct V_133 * V_138 = & V_12 -> V_24 . V_131 ;
V_134 -> V_94 = V_138 -> V_94 ;
V_134 -> V_95 = V_138 -> V_95 ;
V_134 -> V_135 = F_80 ( T_1 , V_134 -> V_135 , 0 , V_91 -> V_96 - V_134 -> V_94 ) ;
V_134 -> V_135 = F_81 ( V_134 -> V_135 , V_12 -> V_126 -> V_139 ) ;
V_134 -> V_137 = F_80 ( T_1 , V_134 -> V_137 , 0 , V_12 -> V_25 . V_97 - V_134 -> V_95 ) ;
F_78 ( 1 , V_28 , & V_12 -> V_132 , L_4 ,
V_134 -> V_135 , V_134 -> V_137 , V_134 -> V_94 , V_134 -> V_95 ,
V_91 -> V_96 , V_91 -> V_97 ) ;
}
static int F_83 ( struct V_109 * V_109 , void * V_50 ,
struct V_140 * V_141 )
{
F_84 ( V_141 -> V_142 , V_143 , sizeof( V_141 -> V_142 ) ) ;
V_141 -> V_144 [ 0 ] = 0 ;
V_141 -> V_145 [ 0 ] = 0 ;
V_141 -> V_146 = V_147 ;
return 0 ;
}
static int F_85 ( struct V_109 * V_109 , void * V_50 ,
struct V_148 * V_149 )
{
const struct V_1 * V_5 ;
if ( V_149 -> V_4 >= F_2 ( V_9 ) )
return - V_21 ;
V_5 = & V_9 [ V_149 -> V_4 ] ;
F_84 ( V_149 -> V_150 , V_5 -> V_151 , sizeof( V_149 -> V_150 ) ) ;
V_149 -> V_2 = V_5 -> V_10 ;
return 0 ;
}
static int F_86 ( struct V_109 * V_109 , void * V_152 ,
struct V_82 * V_149 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_88 * V_89 = & V_149 -> V_5 . V_93 ;
struct V_153 * V_101 = & V_89 -> V_101 [ 0 ] ;
struct V_90 * V_91 = & V_12 -> V_25 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
V_101 -> V_154 = ( V_91 -> V_96 * V_5 -> V_100 [ 0 ] ) / 8 ;
V_101 -> V_102 = V_101 -> V_154 * V_91 -> V_97 ;
V_89 -> V_85 = V_5 -> V_98 ;
V_89 -> V_2 = V_5 -> V_10 ;
V_89 -> V_94 = V_91 -> V_96 ;
V_89 -> V_95 = V_91 -> V_97 ;
V_89 -> V_155 = V_156 ;
V_89 -> V_157 = V_158 ;
return 0 ;
}
static int F_87 ( struct V_11 * V_12 ,
struct V_88 * V_89 ,
const struct V_1 * * V_159 )
{
struct V_125 * V_126 = V_12 -> V_126 ;
T_1 V_160 = V_89 -> V_101 [ 0 ] . V_154 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( & V_89 -> V_2 , NULL , 0 ) ;
if ( F_75 ( V_5 == NULL ) )
return - V_21 ;
if ( V_159 )
* V_159 = V_5 ;
F_76 ( & V_89 -> V_94 , 8 , V_126 -> V_128 ,
F_77 ( V_126 -> V_129 ) - 1 ,
& V_89 -> V_95 , 0 , V_126 -> V_130 , 0 , 0 ) ;
if ( ( V_160 == 0 || ( ( V_160 * 8 ) / V_5 -> V_100 [ 0 ] ) < V_89 -> V_94 ) )
V_89 -> V_101 [ 0 ] . V_154 = ( V_89 -> V_94 *
V_5 -> V_100 [ 0 ] ) / 8 ;
if ( V_89 -> V_101 [ 0 ] . V_102 == 0 )
V_89 -> V_101 [ 0 ] . V_102 = ( V_89 -> V_94 * V_89 -> V_95 *
V_5 -> V_100 [ 0 ] ) / 8 ;
V_89 -> V_85 = V_5 -> V_98 ;
V_89 -> V_2 = V_5 -> V_10 ;
V_89 -> V_157 = V_158 ;
V_89 -> V_155 = V_156 ;
return 0 ;
}
static int F_88 ( struct V_109 * V_109 , void * V_152 ,
struct V_82 * V_149 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_87 ( V_12 , & V_149 -> V_5 . V_93 , NULL ) ;
}
static int F_89 ( struct V_109 * V_109 , void * V_50 ,
struct V_82 * V_149 )
{
struct V_88 * V_89 = & V_149 -> V_5 . V_93 ;
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_90 * V_91 = & V_12 -> V_25 ;
const struct V_1 * V_5 = NULL ;
int V_80 ;
if ( F_90 ( & V_12 -> V_107 ) )
return - V_161 ;
V_80 = F_87 ( V_12 , & V_149 -> V_5 . V_93 , & V_5 ) ;
if ( V_80 < 0 )
return V_80 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_105 [ 0 ] = F_45 ( ( V_89 -> V_94 * V_89 -> V_95 * V_5 -> V_100 [ 0 ] ) / 8 ,
V_89 -> V_101 [ 0 ] . V_102 ) ;
V_91 -> V_96 = V_89 -> V_94 ;
V_91 -> V_97 = V_89 -> V_95 ;
return 0 ;
}
static int F_91 ( struct V_11 * V_12 )
{
struct V_162 * V_163 = & V_12 -> V_132 ;
struct V_164 V_165 , V_166 ;
struct V_167 * V_124 ;
int V_80 ;
while ( 1 ) {
V_124 = & V_163 -> V_116 . V_168 [ 0 ] ;
if ( ! ( V_124 -> V_17 & V_169 ) )
break;
if ( V_163 == & V_12 -> V_132 ) {
struct V_90 * V_170 = & V_12 -> V_25 ;
V_165 . V_171 . V_94 = V_170 -> V_96 ;
V_165 . V_171 . V_95 = V_170 -> V_97 ;
V_165 . V_171 . V_123 = V_12 -> V_5 -> V_3 ;
} else {
V_165 . V_124 = V_124 -> V_4 ;
V_165 . V_172 = V_173 ;
V_80 = F_92 ( V_163 , V_124 , V_174 , NULL ,
& V_165 ) ;
if ( V_80 < 0 && V_80 != - V_175 )
return - V_176 ;
}
V_124 = F_93 ( V_124 ) ;
if ( V_124 == NULL ||
F_94 ( V_124 -> V_116 ) != V_177 )
break;
V_163 = F_95 ( V_124 -> V_116 ) ;
V_166 . V_124 = V_124 -> V_4 ;
V_166 . V_172 = V_173 ;
V_80 = F_92 ( V_163 , V_124 , V_174 , NULL , & V_166 ) ;
if ( V_80 < 0 && V_80 != - V_175 )
return - V_176 ;
if ( V_166 . V_171 . V_94 != V_165 . V_171 . V_94 ||
V_166 . V_171 . V_95 != V_165 . V_171 . V_95 ||
V_166 . V_171 . V_123 != V_165 . V_171 . V_123 )
return - V_176 ;
}
return 0 ;
}
static int F_96 ( struct V_109 * V_109 , void * V_50 ,
enum V_178 type )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_162 * V_16 = V_12 -> V_14 . V_18 [ V_19 ] ;
struct V_13 * V_179 = & V_12 -> V_14 ;
int V_80 ;
if ( F_23 ( V_12 ) )
return - V_161 ;
V_80 = F_97 ( & V_16 -> V_116 , V_179 -> V_180 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_91 ( V_12 ) ;
if ( V_80 ) {
F_98 ( & V_16 -> V_116 ) ;
return V_80 ;
}
return F_99 ( & V_12 -> V_107 , type ) ;
}
static int F_100 ( struct V_109 * V_109 , void * V_50 ,
enum V_178 type )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_162 * V_163 = V_12 -> V_14 . V_18 [ V_19 ] ;
int V_80 ;
V_80 = F_101 ( & V_12 -> V_107 , type ) ;
if ( V_80 == 0 )
F_98 ( & V_163 -> V_116 ) ;
return V_80 ;
}
static int F_102 ( struct V_109 * V_109 , void * V_50 ,
struct V_181 * V_182 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
int V_80 ;
V_182 -> V_78 = F_103 ( T_1 , V_183 , V_182 -> V_78 ) ;
V_80 = F_104 ( & V_12 -> V_107 , V_182 ) ;
if ( ! V_80 )
V_12 -> V_184 = V_182 -> V_78 ;
return V_80 ;
}
static int F_105 ( struct V_109 * V_109 , void * V_50 ,
struct V_185 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_106 ( & V_12 -> V_107 , V_32 ) ;
}
static int F_107 ( struct V_109 * V_109 , void * V_50 ,
struct V_185 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_108 ( & V_12 -> V_107 , V_32 ) ;
}
static int F_109 ( struct V_109 * V_109 , void * V_50 ,
struct V_185 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_110 ( & V_12 -> V_107 , V_32 , V_109 -> V_186 & V_187 ) ;
}
static int F_111 ( struct V_109 * V_109 , void * V_50 ,
struct V_188 * V_189 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_112 ( & V_12 -> V_107 , V_189 ) ;
}
static int F_113 ( struct V_109 * V_109 , void * V_50 ,
struct V_185 * V_190 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
return F_114 ( & V_12 -> V_107 , V_190 ) ;
}
static int F_115 ( struct V_133 * V_191 , struct V_133 * V_190 )
{
if ( V_191 -> V_135 < V_190 -> V_135 || V_191 -> V_137 < V_190 -> V_137 )
return 0 ;
if ( V_191 -> V_135 + V_191 -> V_94 > V_190 -> V_135 + V_190 -> V_94 )
return 0 ;
if ( V_191 -> V_137 + V_191 -> V_95 > V_190 -> V_137 + V_190 -> V_95 )
return 0 ;
return 1 ;
}
static int F_116 ( struct V_109 * V_109 , void * V_152 ,
struct V_192 * V_193 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_90 * V_149 = & V_12 -> V_25 ;
if ( V_193 -> type != V_194 )
return - V_21 ;
switch ( V_193 -> V_195 ) {
case V_196 :
case V_197 :
V_193 -> V_134 . V_135 = 0 ;
V_193 -> V_134 . V_137 = 0 ;
V_193 -> V_134 . V_94 = V_149 -> V_96 ;
V_193 -> V_134 . V_95 = V_149 -> V_97 ;
return 0 ;
case V_198 :
V_193 -> V_134 = V_149 -> V_131 ;
return 0 ;
}
return - V_21 ;
}
static int F_117 ( struct V_109 * V_109 , void * V_152 ,
struct V_192 * V_193 )
{
struct V_11 * V_12 = F_61 ( V_109 ) ;
struct V_90 * V_149 = & V_12 -> V_25 ;
struct V_133 V_131 = V_193 -> V_134 ;
unsigned long V_17 ;
if ( V_193 -> type != V_194 ||
V_193 -> V_195 != V_198 )
return - V_21 ;
F_82 ( V_12 , & V_131 ) ;
if ( ( V_193 -> V_17 & V_199 ) &&
! F_115 ( & V_131 , & V_193 -> V_134 ) )
return - V_200 ;
if ( ( V_193 -> V_17 & V_201 ) &&
! F_115 ( & V_193 -> V_134 , & V_131 ) )
return - V_200 ;
V_193 -> V_134 = V_131 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_149 -> V_131 = V_131 ;
F_24 ( V_48 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
return 0 ;
}
static int F_118 ( struct V_202 * V_116 ,
const struct V_167 * V_203 ,
const struct V_167 * V_204 , T_1 V_17 )
{
struct V_162 * V_163 = F_95 ( V_116 ) ;
struct V_11 * V_12 = F_119 ( V_163 ) ;
unsigned int V_205 = F_94 ( V_204 -> V_116 ) ;
if ( F_75 ( V_12 == NULL ) )
return 0 ;
F_78 ( 1 , V_28 , V_163 , L_5 ,
V_29 , V_203 -> V_116 -> V_151 , V_204 -> V_116 -> V_151 ,
V_17 , V_12 -> V_206 ) ;
switch ( V_203 -> V_4 ) {
case V_207 :
if ( V_205 != V_177 )
return - V_21 ;
if ( V_17 & V_208 ) {
if ( V_12 -> V_206 != 0 )
return - V_161 ;
V_12 -> V_206 = V_163 -> V_209 ;
return 0 ;
}
V_12 -> V_206 = 0 ;
break;
case V_210 :
if ( ! ( V_17 & V_208 ) ) {
V_12 -> V_62 = V_211 ;
return 0 ;
}
if ( V_205 == V_177 )
V_12 -> V_62 = V_212 ;
else
V_12 -> V_62 = V_63 ;
break;
default:
F_48 ( V_163 , L_6 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_120 ( struct V_162 * V_163 ,
struct V_213 * V_152 ,
struct V_214 * V_123 )
{
const struct V_1 * V_5 ;
V_5 = F_1 ( NULL , NULL , V_123 -> V_4 ) ;
if ( ! V_5 )
return - V_21 ;
V_123 -> V_123 = V_5 -> V_3 ;
return 0 ;
}
static int F_121 ( struct V_162 * V_163 ,
struct V_213 * V_152 ,
struct V_164 * V_5 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
struct V_215 * V_216 = & V_5 -> V_171 ;
struct V_90 * V_149 = & V_12 -> V_25 ;
if ( V_5 -> V_172 == V_217 ) {
V_216 = F_122 ( V_152 , V_5 -> V_124 ) ;
V_5 -> V_171 = * V_216 ;
return 0 ;
}
V_216 -> V_157 = V_158 ;
F_56 ( & V_12 -> V_108 ) ;
V_216 -> V_123 = V_12 -> V_5 -> V_3 ;
if ( V_5 -> V_124 == V_127 ) {
V_216 -> V_94 = V_149 -> V_96 ;
V_216 -> V_95 = V_149 -> V_97 ;
} else {
V_216 -> V_94 = V_149 -> V_131 . V_94 ;
V_216 -> V_95 = V_149 -> V_131 . V_95 ;
}
F_58 ( & V_12 -> V_108 ) ;
return 0 ;
}
static int F_123 ( struct V_162 * V_163 ,
struct V_213 * V_152 ,
struct V_164 * V_5 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
struct V_215 * V_216 = & V_5 -> V_171 ;
struct V_90 * V_218 = & V_12 -> V_24 ;
struct V_90 * V_219 = & V_12 -> V_25 ;
const struct V_1 * V_159 ;
F_78 ( 1 , V_28 , V_163 , L_7 ,
V_5 -> V_124 , V_216 -> V_123 , V_216 -> V_94 , V_216 -> V_95 ) ;
V_216 -> V_157 = V_158 ;
F_56 ( & V_12 -> V_108 ) ;
if ( ( V_12 -> V_62 == V_212 && V_163 -> V_116 . V_220 > 0 ) ||
( V_12 -> V_62 == V_63 && F_90 ( & V_12 -> V_107 ) ) ) {
F_58 ( & V_12 -> V_108 ) ;
return - V_161 ;
}
V_159 = F_74 ( V_12 , & V_216 -> V_94 , & V_216 -> V_95 ,
& V_216 -> V_123 , NULL , V_5 -> V_124 ) ;
if ( V_5 -> V_172 == V_217 ) {
V_216 = F_122 ( V_152 , V_5 -> V_124 ) ;
* V_216 = V_5 -> V_171 ;
F_58 ( & V_12 -> V_108 ) ;
return 0 ;
}
if ( V_5 -> V_124 == V_127 ) {
V_218 -> V_96 = V_216 -> V_94 ;
V_218 -> V_97 = V_216 -> V_95 ;
V_12 -> V_5 = V_159 ;
V_218 -> V_131 . V_94 = V_216 -> V_94 ;
V_218 -> V_131 . V_95 = V_216 -> V_95 ;
V_218 -> V_131 . V_135 = 0 ;
V_218 -> V_131 . V_137 = 0 ;
V_219 -> V_131 = V_218 -> V_131 ;
V_219 -> V_96 = V_216 -> V_94 ;
V_219 -> V_97 = V_216 -> V_95 ;
} else {
V_216 -> V_123 = V_12 -> V_5 -> V_3 ;
V_216 -> V_94 = V_218 -> V_131 . V_94 ;
V_216 -> V_95 = V_218 -> V_131 . V_95 ;
}
F_58 ( & V_12 -> V_108 ) ;
return 0 ;
}
static int F_124 ( struct V_162 * V_163 ,
struct V_213 * V_152 ,
struct V_221 * V_193 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
struct V_90 * V_149 = & V_12 -> V_24 ;
if ( ( V_193 -> V_195 != V_222 &&
V_193 -> V_195 != V_223 ) ||
V_193 -> V_124 != V_127 )
return - V_21 ;
if ( V_193 -> V_172 == V_217 ) {
V_193 -> V_134 = * F_125 ( V_152 , V_193 -> V_124 ) ;
return 0 ;
}
F_56 ( & V_12 -> V_108 ) ;
if ( V_193 -> V_195 == V_222 ) {
V_193 -> V_134 = V_149 -> V_131 ;
} else {
V_193 -> V_134 . V_135 = 0 ;
V_193 -> V_134 . V_137 = 0 ;
V_193 -> V_134 . V_94 = V_149 -> V_96 ;
V_193 -> V_134 . V_95 = V_149 -> V_97 ;
}
F_58 ( & V_12 -> V_108 ) ;
F_78 ( 1 , V_28 , V_163 , L_8 ,
V_29 , V_149 -> V_131 . V_135 , V_149 -> V_131 . V_137 , V_149 -> V_131 . V_94 ,
V_149 -> V_131 . V_95 , V_149 -> V_96 , V_149 -> V_97 ) ;
return 0 ;
}
static int F_126 ( struct V_162 * V_163 ,
struct V_213 * V_152 ,
struct V_221 * V_193 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
struct V_90 * V_149 = & V_12 -> V_24 ;
int V_80 = 0 ;
if ( V_193 -> V_195 != V_222 || V_193 -> V_124 != V_127 )
return - V_21 ;
F_56 ( & V_12 -> V_108 ) ;
F_79 ( V_12 , & V_193 -> V_134 ) ;
if ( V_193 -> V_172 == V_217 ) {
* F_125 ( V_152 , V_193 -> V_124 ) = V_193 -> V_134 ;
} else {
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_149 -> V_131 = V_193 -> V_134 ;
V_12 -> V_25 . V_131 = V_193 -> V_134 ;
F_24 ( V_48 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
F_58 ( & V_12 -> V_108 ) ;
F_78 ( 1 , V_28 , V_163 , L_8 ,
V_29 , V_149 -> V_131 . V_135 , V_149 -> V_131 . V_137 , V_149 -> V_131 . V_94 ,
V_149 -> V_131 . V_95 , V_149 -> V_96 , V_149 -> V_97 ) ;
return V_80 ;
}
static int F_127 ( struct V_162 * V_163 , int V_224 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
if ( V_12 -> V_62 == V_63 )
return - V_175 ;
return 0 ;
}
static int F_128 ( struct V_162 * V_163 , int V_224 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
if ( V_12 -> V_62 == V_63 )
return - V_175 ;
return 0 ;
}
static int F_129 ( struct V_162 * V_163 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
F_12 ( V_12 , V_29 ) ;
return 0 ;
}
static int F_130 ( struct V_162 * V_163 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
struct V_76 * V_77 = & V_12 -> V_107 ;
struct V_225 * V_106 = & V_12 -> V_106 ;
int V_80 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_12 -> V_5 = & V_9 [ 0 ] ;
V_12 -> V_62 = V_63 ;
snprintf ( V_106 -> V_151 , sizeof( V_106 -> V_151 ) , L_9 ,
V_12 -> V_4 ) ;
V_106 -> V_226 = & V_227 ;
V_106 -> V_228 = & V_229 ;
V_106 -> V_230 = V_163 -> V_230 ;
V_106 -> V_231 = - 1 ;
V_106 -> V_232 = V_233 ;
V_106 -> V_108 = & V_12 -> V_108 ;
V_12 -> V_114 = 0 ;
V_12 -> V_184 = 0 ;
F_131 ( & V_12 -> V_41 ) ;
F_131 ( & V_12 -> V_44 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> type = V_194 ;
V_77 -> V_234 = V_235 | V_236 ;
V_77 -> V_237 = & V_238 ;
V_77 -> V_239 = & V_240 ;
V_77 -> V_241 = sizeof( struct V_31 ) ;
V_77 -> V_79 = V_12 ;
V_80 = F_132 ( V_77 ) ;
if ( V_80 < 0 )
return V_80 ;
V_12 -> V_242 . V_17 = V_169 ;
V_80 = F_133 ( & V_106 -> V_116 , 1 , & V_12 -> V_242 , 0 ) ;
if ( V_80 < 0 )
return V_80 ;
F_134 ( V_106 , V_12 ) ;
V_12 -> V_243 = F_4 ( V_163 ) ;
V_80 = F_135 ( V_106 , V_244 , - 1 ) ;
if ( V_80 < 0 ) {
F_136 ( & V_106 -> V_116 ) ;
V_12 -> V_243 = NULL ;
return V_80 ;
}
F_137 ( V_163 -> V_230 , L_10 ,
V_106 -> V_151 , F_138 ( V_106 ) ) ;
return 0 ;
}
static void F_139 ( struct V_162 * V_163 )
{
struct V_11 * V_12 = F_119 ( V_163 ) ;
if ( V_12 == NULL )
return;
if ( F_140 ( & V_12 -> V_106 ) ) {
F_141 ( & V_12 -> V_106 ) ;
F_136 ( & V_12 -> V_106 . V_116 ) ;
V_12 -> V_243 = NULL ;
}
}
static int F_142 ( struct V_245 * V_246 )
{
struct V_11 * V_12 = F_51 ( V_246 -> V_247 , struct V_11 ,
V_248 ) ;
F_24 ( V_48 , & V_12 -> V_34 ) ;
return 0 ;
}
static int F_143 ( struct V_11 * V_12 )
{
struct V_249 * V_247 = & V_12 -> V_248 ;
struct V_162 * V_163 = & V_12 -> V_132 ;
int V_80 ;
F_144 ( V_163 , & V_250 ) ;
V_163 -> V_17 = V_251 ;
snprintf ( V_163 -> V_151 , sizeof( V_163 -> V_151 ) , L_11 , V_12 -> V_4 ) ;
V_12 -> V_252 [ V_207 ] . V_17 = V_169 ;
V_12 -> V_252 [ V_210 ] . V_17 = V_253 ;
V_80 = F_133 ( & V_163 -> V_116 , V_254 ,
V_12 -> V_252 , 0 ) ;
if ( V_80 )
return V_80 ;
F_145 ( V_247 , 1 ) ;
V_12 -> V_26 = F_146 ( V_247 , & V_255 ,
NULL ) ;
if ( V_247 -> error ) {
F_136 ( & V_163 -> V_116 ) ;
return V_247 -> error ;
}
V_163 -> V_248 = V_247 ;
V_163 -> V_256 = & V_257 ;
V_163 -> V_116 . V_237 = & V_258 ;
F_147 ( V_163 , V_12 ) ;
return 0 ;
}
static void F_148 ( struct V_11 * V_12 )
{
struct V_162 * V_163 = & V_12 -> V_132 ;
F_149 ( V_163 ) ;
F_136 ( & V_163 -> V_116 ) ;
F_150 ( & V_12 -> V_248 ) ;
F_147 ( V_163 , NULL ) ;
}
static void F_151 ( struct V_11 * V_12 )
{
if ( F_152 ( V_12 -> clock ) )
return;
F_153 ( V_12 -> clock ) ;
F_154 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
static int F_155 ( struct V_11 * V_12 )
{
int V_80 ;
V_12 -> clock = F_156 ( & V_12 -> V_112 -> V_113 , V_259 ) ;
if ( F_157 ( V_12 -> clock ) )
return F_158 ( V_12 -> clock ) ;
V_80 = F_159 ( V_12 -> clock ) ;
if ( V_80 < 0 ) {
F_154 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
return V_80 ;
}
static int F_160 ( struct V_260 * V_112 )
{
struct V_261 * V_262 = F_161 ( V_112 ) ;
struct V_11 * V_12 ;
struct V_263 * V_264 ;
int V_80 ;
V_12 = F_162 ( & V_112 -> V_113 , sizeof( * V_12 ) , V_265 ) ;
if ( ! V_12 )
return - V_266 ;
V_12 -> V_4 = V_112 -> V_8 ;
V_12 -> V_126 = V_262 -> V_126 [ V_12 -> V_4 ] ;
V_12 -> V_112 = V_112 ;
F_163 ( & V_12 -> V_46 ) ;
F_164 ( & V_12 -> V_22 ) ;
F_165 ( & V_12 -> V_108 ) ;
V_264 = F_166 ( V_112 , V_267 , 0 ) ;
V_12 -> V_268 = F_167 ( & V_112 -> V_113 , V_264 ) ;
if ( V_12 -> V_268 == NULL ) {
F_168 ( & V_112 -> V_113 , L_12 ) ;
return - V_269 ;
}
V_264 = F_166 ( V_112 , V_270 , 0 ) ;
if ( V_264 == NULL ) {
F_168 ( & V_112 -> V_113 , L_13 ) ;
return - V_20 ;
}
V_80 = F_155 ( V_12 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_169 ( & V_112 -> V_113 , V_264 -> V_271 , F_31 ,
0 , F_170 ( & V_112 -> V_113 ) , V_12 ) ;
if ( V_80 ) {
F_168 ( & V_112 -> V_113 , L_14 , V_80 ) ;
goto V_272;
}
V_80 = F_143 ( V_12 ) ;
if ( V_80 )
goto V_272;
F_171 ( V_112 , V_12 ) ;
F_172 ( & V_112 -> V_113 ) ;
V_80 = F_63 ( & V_112 -> V_113 ) ;
if ( V_80 < 0 )
goto V_273;
V_12 -> V_103 = F_173 ( & V_112 -> V_113 ) ;
if ( F_157 ( V_12 -> V_103 ) ) {
V_80 = F_158 ( V_12 -> V_103 ) ;
goto V_274;
}
F_68 ( & V_112 -> V_113 ) ;
F_174 ( & V_112 -> V_113 , L_15 ,
V_12 -> V_4 ) ;
return 0 ;
V_274:
F_68 ( & V_112 -> V_113 ) ;
V_273:
F_148 ( V_12 ) ;
V_272:
F_151 ( V_12 ) ;
return V_80 ;
}
static int F_175 ( struct V_275 * V_113 )
{
struct V_11 * V_12 = F_176 ( V_113 ) ;
F_177 ( V_12 -> clock ) ;
return 0 ;
}
static int F_178 ( struct V_275 * V_113 )
{
struct V_11 * V_12 = F_176 ( V_113 ) ;
F_179 ( V_12 -> clock ) ;
return 0 ;
}
static int F_180 ( struct V_275 * V_113 )
{
struct V_11 * V_12 = F_176 ( V_113 ) ;
struct V_31 * V_32 ;
unsigned long V_17 ;
int V_7 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_34 ( V_276 , & V_12 -> V_34 ) ||
! F_27 ( V_111 , & V_12 -> V_34 ) ) {
F_13 ( & V_12 -> V_22 , V_17 ) ;
return 0 ;
}
F_20 ( V_12 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_34 ( V_39 , & V_12 -> V_34 ) )
return 0 ;
F_131 ( & V_12 -> V_44 ) ;
F_21 ( V_12 , V_115 , & V_12 -> V_14 ,
& V_12 -> V_106 . V_116 , false ) ;
F_3 ( V_12 ) ;
F_30 ( V_39 , & V_12 -> V_34 ) ;
for ( V_7 = 0 ; V_7 < V_12 -> V_184 ; V_7 ++ ) {
if ( F_15 ( & V_12 -> V_41 ) )
break;
V_32 = F_16 ( V_12 ) ;
F_50 ( & V_32 -> V_42 ) ;
}
return 0 ;
}
static int F_181 ( struct V_275 * V_113 )
{
struct V_11 * V_12 = F_176 ( V_113 ) ;
bool V_30 = F_27 ( V_111 , & V_12 -> V_34 ) ;
int V_80 ;
if ( F_41 ( V_276 , & V_12 -> V_34 ) )
return 0 ;
V_80 = F_22 ( V_12 , V_30 ) ;
if ( V_80 < 0 || ! F_23 ( V_12 ) )
return V_80 ;
return F_21 ( V_12 , V_117 , & V_12 -> V_14 ) ;
}
static int F_182 ( struct V_260 * V_112 )
{
struct V_11 * V_12 = F_183 ( V_112 ) ;
struct V_275 * V_113 = & V_112 -> V_113 ;
F_184 ( V_113 ) ;
F_185 ( V_113 ) ;
F_148 ( V_12 ) ;
F_186 ( V_12 -> V_103 ) ;
F_151 ( V_12 ) ;
F_187 ( V_113 , L_16 ) ;
return 0 ;
}
