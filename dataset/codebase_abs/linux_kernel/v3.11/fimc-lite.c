static const struct V_1 * F_1 ( const T_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 , int V_5 )
{
const struct V_1 * V_6 , * V_7 = NULL ;
unsigned int V_8 ;
int V_9 = 0 ;
if ( V_5 >= ( int ) F_2 ( V_10 ) )
return NULL ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; ++ V_8 ) {
V_6 = & V_10 [ V_8 ] ;
if ( V_4 && ! ( V_6 -> V_11 & V_4 ) )
continue;
if ( V_2 && V_6 -> V_12 == * V_2 )
return V_6 ;
if ( V_3 && V_6 -> V_3 == * V_3 )
return V_6 ;
if ( V_5 == V_9 )
V_7 = V_6 ;
V_9 ++ ;
}
return V_7 ;
}
static int F_3 ( struct V_13 * V_14 , bool V_15 )
{
struct V_16 * V_17 ;
unsigned long V_11 ;
if ( V_14 -> V_18 == NULL )
return - V_19 ;
if ( V_14 -> V_20 . V_6 == NULL || V_14 -> V_21 . V_6 == NULL )
return - V_22 ;
V_17 = F_4 ( V_14 -> V_18 ) ;
if ( ! V_17 )
return - V_22 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_6 ( V_14 , V_17 ) ;
F_7 ( V_14 , & V_14 -> V_20 ) ;
F_8 ( V_14 , & V_14 -> V_20 ) ;
F_9 ( V_14 , 0 ) ;
F_10 ( V_14 , & V_14 -> V_21 , ! V_15 ) ;
F_11 ( V_14 ) ;
F_12 ( V_14 , V_14 -> V_24 -> V_25 ) ;
if ( V_26 > 0 )
F_13 ( V_14 , V_27 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , bool V_28 )
{
struct V_29 * V_30 ;
unsigned long V_11 ;
bool V_31 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_31 = V_14 -> V_32 & ( 1 << V_33 ) ;
V_14 -> V_32 &= ~ ( 1 << V_34 | 1 << V_35 |
1 << V_36 | 1 << V_33 ) ;
if ( V_28 )
V_14 -> V_32 |= ( 1 << V_37 ) ;
else
V_14 -> V_32 &= ~ ( 1 << V_38 |
1 << V_37 ) ;
while ( ! V_28 && ! F_16 ( & V_14 -> V_39 ) ) {
V_30 = F_17 ( V_14 ) ;
F_18 ( & V_30 -> V_40 , V_41 ) ;
}
while ( ! F_16 ( & V_14 -> V_42 ) ) {
V_30 = F_19 ( V_14 ) ;
if ( V_28 )
F_20 ( V_14 , V_30 ) ;
else
F_18 ( & V_30 -> V_40 , V_41 ) ;
}
F_14 ( & V_14 -> V_23 , V_11 ) ;
F_21 ( V_14 ) ;
if ( ! V_31 )
return 0 ;
return F_22 ( & V_14 -> V_43 , V_44 , 0 ) ;
}
static int F_23 ( struct V_13 * V_14 , bool V_28 )
{
unsigned long V_11 ;
if ( ! F_24 ( V_14 ) )
return 0 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_25 ( V_35 , & V_14 -> V_32 ) ;
F_26 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
F_27 ( V_14 -> V_45 ,
! F_28 ( V_35 , & V_14 -> V_32 ) ,
( 2 * V_46 / 10 ) ) ;
return F_15 ( V_14 , V_28 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
F_8 ( V_14 , & V_14 -> V_20 ) ;
F_30 ( V_14 , & V_14 -> V_21 ) ;
F_12 ( V_14 , V_14 -> V_24 -> V_25 ) ;
F_31 ( V_47 , & V_14 -> V_32 ) ;
}
static T_2 F_32 ( int V_48 , void * V_49 )
{
struct V_13 * V_14 = V_49 ;
struct V_29 * V_50 ;
unsigned long V_11 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
T_1 V_55 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_55 = F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
if ( F_35 ( V_35 , & V_14 -> V_32 ) ) {
F_36 ( & V_14 -> V_45 ) ;
goto V_56;
}
if ( V_55 & V_57 ) {
F_31 ( V_34 , & V_14 -> V_32 ) ;
V_14 -> V_58 . V_59 ++ ;
}
if ( V_55 & V_60 ) {
F_37 ( V_14 ) ;
F_31 ( V_36 , & V_14 -> V_32 ) ;
F_36 ( & V_14 -> V_45 ) ;
}
if ( F_38 ( & V_14 -> V_61 ) != V_62 )
goto V_56;
if ( ( V_55 & V_63 ) &&
F_28 ( V_34 , & V_14 -> V_32 ) &&
! F_16 ( & V_14 -> V_39 ) ) {
V_50 = F_17 ( V_14 ) ;
F_39 ( V_14 , V_50 ) ;
F_40 ( V_14 , V_50 ) ;
}
if ( ( V_55 & V_64 ) &&
F_28 ( V_34 , & V_14 -> V_32 ) &&
! F_16 ( & V_14 -> V_42 ) ) {
V_50 = F_19 ( V_14 ) ;
F_41 ( & V_54 ) ;
V_52 = & V_50 -> V_40 . V_65 . V_66 ;
V_52 -> V_67 = V_54 . V_67 ;
V_52 -> V_68 = V_54 . V_69 / V_70 ;
V_50 -> V_40 . V_65 . V_71 = V_14 -> V_72 ++ ;
F_42 ( V_14 , V_50 -> V_5 ) ;
F_18 ( & V_50 -> V_40 , V_73 ) ;
}
if ( F_28 ( V_47 , & V_14 -> V_32 ) )
F_29 ( V_14 ) ;
if ( F_16 ( & V_14 -> V_39 ) ) {
F_26 ( V_14 ) ;
F_31 ( V_36 , & V_14 -> V_32 ) ;
}
V_56:
F_25 ( V_34 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return V_74 ;
}
static int F_43 ( struct V_75 * V_76 , unsigned int V_77 )
{
struct V_13 * V_14 = V_76 -> V_78 ;
unsigned long V_11 ;
int V_79 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_14 -> V_80 = 0 ;
V_14 -> V_72 = 0 ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
V_79 = F_3 ( V_14 , false ) ;
if ( V_79 ) {
F_15 ( V_14 , false ) ;
return V_79 ;
}
F_25 ( V_38 , & V_14 -> V_32 ) ;
if ( ! F_16 ( & V_14 -> V_42 ) &&
! F_44 ( V_36 , & V_14 -> V_32 ) ) {
F_45 ( V_14 ) ;
if ( ! F_44 ( V_33 , & V_14 -> V_32 ) )
F_22 ( & V_14 -> V_43 , V_44 , 1 ) ;
}
if ( V_26 > 0 )
F_13 ( V_14 , V_27 ) ;
return 0 ;
}
static int F_46 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = V_76 -> V_78 ;
if ( ! F_24 ( V_14 ) )
return - V_22 ;
return F_23 ( V_14 , false ) ;
}
static int F_47 ( struct V_75 * V_81 , const struct V_82 * V_83 ,
unsigned int * V_84 , unsigned int * V_85 ,
unsigned int V_86 [] , void * V_87 [] )
{
const struct V_88 * V_89 = NULL ;
struct V_13 * V_14 = V_81 -> V_78 ;
struct V_90 * V_91 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_91 -> V_6 ;
unsigned long V_92 ;
int V_8 ;
if ( V_83 ) {
V_89 = & V_83 -> V_6 . V_93 ;
V_6 = F_1 ( & V_89 -> V_2 , NULL , 0 , - 1 ) ;
V_92 = V_89 -> V_94 * V_89 -> V_95 ;
} else {
V_92 = V_91 -> V_96 * V_91 -> V_97 ;
}
if ( V_6 == NULL )
return - V_22 ;
* V_85 = V_6 -> V_98 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_98 ; V_8 ++ ) {
unsigned int V_99 = ( V_92 * V_6 -> V_100 [ V_8 ] ) / 8 ;
if ( V_89 )
V_86 [ V_8 ] = F_48 ( V_99 , V_89 -> V_101 [ V_8 ] . V_102 ) ;
else
V_86 [ V_8 ] = V_99 ;
V_87 [ V_8 ] = V_14 -> V_103 ;
}
return 0 ;
}
static int F_49 ( struct V_104 * V_40 )
{
struct V_75 * V_81 = V_40 -> V_75 ;
struct V_13 * V_14 = V_81 -> V_78 ;
int V_8 ;
if ( V_14 -> V_21 . V_6 == NULL )
return - V_22 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_21 . V_6 -> V_98 ; V_8 ++ ) {
unsigned long V_99 = V_14 -> V_105 [ V_8 ] ;
if ( F_50 ( V_40 , V_8 ) < V_99 ) {
F_51 ( & V_14 -> V_43 . V_106 ,
L_1 ,
F_50 ( V_40 , V_8 ) , V_99 ) ;
return - V_22 ;
}
F_52 ( V_40 , V_8 , V_99 ) ;
}
return 0 ;
}
static void F_53 ( struct V_104 * V_40 )
{
struct V_29 * V_30
= F_54 ( V_40 , struct V_29 , V_40 ) ;
struct V_13 * V_14 = F_55 ( V_40 -> V_75 ) ;
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_30 -> V_107 = F_56 ( V_40 , 0 ) ;
V_30 -> V_5 = V_14 -> V_80 ++ ;
if ( V_14 -> V_80 >= V_14 -> V_108 )
V_14 -> V_80 = 0 ;
if ( ! F_28 ( V_37 , & V_14 -> V_32 ) &&
! F_28 ( V_36 , & V_14 -> V_32 ) &&
F_16 ( & V_14 -> V_42 ) ) {
F_39 ( V_14 , V_30 ) ;
F_40 ( V_14 , V_30 ) ;
} else {
F_20 ( V_14 , V_30 ) ;
}
if ( F_57 ( & V_14 -> V_109 ) &&
! F_16 ( & V_14 -> V_39 ) &&
! F_44 ( V_36 , & V_14 -> V_32 ) ) {
F_45 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_44 ( V_33 , & V_14 -> V_32 ) )
F_22 ( & V_14 -> V_43 , V_44 , 1 ) ;
return;
}
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
static void F_58 ( struct V_13 * V_14 )
{
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
memset ( & V_14 -> V_58 , 0 , sizeof( V_14 -> V_58 ) ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
static int F_59 ( struct V_110 * V_110 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_111 * V_112 = & V_14 -> V_43 . V_106 . V_113 ;
int V_79 ;
F_61 ( & V_14 -> V_114 ) ;
if ( F_38 ( & V_14 -> V_61 ) != V_62 ) {
V_79 = - V_115 ;
goto V_116;
}
F_25 ( V_117 , & V_14 -> V_32 ) ;
V_79 = F_62 ( & V_14 -> V_118 -> V_119 ) ;
if ( V_79 < 0 )
goto V_116;
V_79 = F_63 ( V_110 ) ;
if ( V_79 < 0 )
goto V_120;
if ( ! F_64 ( V_110 ) ||
F_38 ( & V_14 -> V_61 ) != V_62 )
goto V_116;
F_61 ( & V_112 -> V_121 -> V_122 ) ;
V_79 = F_22 ( & V_14 -> V_43 , V_123 , V_112 , true ) ;
if ( V_79 == 0 )
V_112 -> V_124 ++ ;
F_65 ( & V_112 -> V_121 -> V_122 ) ;
if ( ! V_79 ) {
F_58 ( V_14 ) ;
goto V_116;
}
F_66 ( V_110 ) ;
V_120:
F_67 ( & V_14 -> V_118 -> V_119 ) ;
F_31 ( V_117 , & V_14 -> V_32 ) ;
V_116:
F_65 ( & V_14 -> V_114 ) ;
return V_79 ;
}
static int F_68 ( struct V_110 * V_110 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_111 * V_113 = & V_14 -> V_43 . V_106 . V_113 ;
F_61 ( & V_14 -> V_114 ) ;
if ( F_64 ( V_110 ) &&
F_38 ( & V_14 -> V_61 ) == V_62 ) {
if ( V_14 -> V_31 ) {
F_69 ( V_113 ) ;
V_14 -> V_31 = false ;
}
F_23 ( V_14 , false ) ;
F_22 ( & V_14 -> V_43 , V_125 ) ;
F_31 ( V_117 , & V_14 -> V_32 ) ;
F_61 ( & V_113 -> V_121 -> V_122 ) ;
V_113 -> V_124 -- ;
F_65 ( & V_113 -> V_121 -> V_122 ) ;
}
F_70 ( V_110 ) ;
F_71 ( & V_14 -> V_118 -> V_119 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
F_65 ( & V_14 -> V_114 ) ;
return 0 ;
}
static const struct V_1 * F_72 ( struct V_13 * V_14 ,
struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_130 * V_131 = V_14 -> V_131 ;
struct V_132 * V_133 = & V_129 -> V_129 ;
const struct V_1 * V_6 = NULL ;
if ( V_129 -> V_134 == V_135 ) {
F_73 ( & V_133 -> V_94 , 8 , V_131 -> V_136 ,
F_74 ( V_131 -> V_137 ) - 1 ,
& V_133 -> V_95 , 0 , V_131 -> V_138 , 0 , 0 ) ;
V_6 = F_1 ( NULL , & V_133 -> V_139 , 0 , 0 ) ;
if ( F_75 ( ! V_6 ) )
return NULL ;
V_133 -> V_140 = V_6 -> V_140 ;
V_133 -> V_139 = V_6 -> V_3 ;
} else {
struct V_90 * V_141 = & V_14 -> V_20 ;
struct V_132 * V_142 ;
struct V_143 * V_144 ;
if ( V_129 -> V_145 == V_146 ) {
V_142 = F_76 ( V_127 ,
V_135 ) ;
V_133 -> V_139 = V_142 -> V_139 ;
V_133 -> V_140 = V_142 -> V_140 ;
V_144 = F_77 ( V_127 ,
V_135 ) ;
} else {
V_133 -> V_139 = V_141 -> V_6 -> V_3 ;
V_133 -> V_140 = V_141 -> V_6 -> V_140 ;
V_144 = & V_141 -> V_144 ;
}
V_133 -> V_94 = V_144 -> V_94 ;
V_133 -> V_95 = V_144 -> V_95 ;
}
V_133 -> V_147 = V_148 ;
F_78 ( 1 , V_26 , & V_14 -> V_149 , L_2 ,
V_133 -> V_139 , V_133 -> V_140 , V_133 -> V_94 , V_133 -> V_95 ) ;
return V_6 ;
}
static void F_79 ( struct V_13 * V_14 , struct V_143 * V_150 )
{
struct V_90 * V_91 = & V_14 -> V_20 ;
F_73 ( & V_150 -> V_94 , 0 , V_91 -> V_96 , 0 ,
& V_150 -> V_95 , 0 , V_91 -> V_97 , 0 , 0 ) ;
V_150 -> V_151 = F_80 ( T_1 , V_150 -> V_151 , 0 , V_91 -> V_96 - V_150 -> V_94 ) ;
V_150 -> V_151 = F_81 ( V_150 -> V_151 , V_14 -> V_131 -> V_152 ) ;
V_150 -> V_153 = F_80 ( T_1 , V_150 -> V_153 , 0 , V_91 -> V_97 - V_150 -> V_95 ) ;
F_78 ( 1 , V_26 , & V_14 -> V_149 , L_3 ,
V_150 -> V_151 , V_150 -> V_153 , V_150 -> V_94 , V_150 -> V_95 ,
V_91 -> V_96 , V_91 -> V_97 ) ;
}
static void F_82 ( struct V_13 * V_14 , struct V_143 * V_150 )
{
struct V_90 * V_91 = & V_14 -> V_21 ;
struct V_143 * V_154 = & V_14 -> V_20 . V_144 ;
V_150 -> V_94 = V_154 -> V_94 ;
V_150 -> V_95 = V_154 -> V_95 ;
V_150 -> V_151 = F_80 ( T_1 , V_150 -> V_151 , 0 , V_91 -> V_96 - V_150 -> V_94 ) ;
V_150 -> V_151 = F_81 ( V_150 -> V_151 , V_14 -> V_131 -> V_155 ) ;
V_150 -> V_153 = F_80 ( T_1 , V_150 -> V_153 , 0 , V_14 -> V_21 . V_97 - V_150 -> V_95 ) ;
F_78 ( 1 , V_26 , & V_14 -> V_149 , L_4 ,
V_150 -> V_151 , V_150 -> V_153 , V_150 -> V_94 , V_150 -> V_95 ,
V_91 -> V_96 , V_91 -> V_97 ) ;
}
static int F_83 ( struct V_110 * V_110 , void * V_49 ,
struct V_156 * V_157 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
F_84 ( V_157 -> V_158 , V_159 , sizeof( V_157 -> V_158 ) ) ;
F_84 ( V_157 -> V_160 , V_159 , sizeof( V_157 -> V_160 ) ) ;
snprintf ( V_157 -> V_161 , sizeof( V_157 -> V_161 ) , L_5 ,
F_85 ( & V_14 -> V_118 -> V_119 ) ) ;
V_157 -> V_162 = V_163 ;
V_157 -> V_164 = V_157 -> V_162 | V_165 ;
return 0 ;
}
static int F_86 ( struct V_110 * V_110 , void * V_49 ,
struct V_166 * V_167 )
{
const struct V_1 * V_6 ;
if ( V_167 -> V_5 >= F_2 ( V_10 ) )
return - V_22 ;
V_6 = & V_10 [ V_167 -> V_5 ] ;
F_84 ( V_167 -> V_168 , V_6 -> V_169 , sizeof( V_167 -> V_168 ) ) ;
V_167 -> V_2 = V_6 -> V_12 ;
return 0 ;
}
static int F_87 ( struct V_110 * V_110 , void * V_127 ,
struct V_82 * V_167 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_88 * V_89 = & V_167 -> V_6 . V_93 ;
struct V_170 * V_101 = & V_89 -> V_101 [ 0 ] ;
struct V_90 * V_91 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_91 -> V_6 ;
V_101 -> V_171 = ( V_91 -> V_96 * V_6 -> V_100 [ 0 ] ) / 8 ;
V_101 -> V_102 = V_101 -> V_171 * V_91 -> V_97 ;
V_89 -> V_85 = V_6 -> V_98 ;
V_89 -> V_2 = V_6 -> V_12 ;
V_89 -> V_94 = V_91 -> V_96 ;
V_89 -> V_95 = V_91 -> V_97 ;
V_89 -> V_147 = V_148 ;
V_89 -> V_140 = V_6 -> V_140 ;
return 0 ;
}
static int F_88 ( struct V_13 * V_14 ,
struct V_88 * V_89 ,
const struct V_1 * * V_172 )
{
T_1 V_173 = V_89 -> V_101 [ 0 ] . V_171 ;
struct V_130 * V_131 = V_14 -> V_131 ;
const struct V_1 * V_174 = V_14 -> V_20 . V_6 ;
const struct V_1 * V_6 ;
if ( F_75 ( V_174 == NULL ) )
return - V_22 ;
if ( V_174 -> V_11 & V_175 )
V_6 = F_1 ( & V_89 -> V_2 , NULL ,
V_174 -> V_11 , 0 ) ;
else
V_6 = V_174 ;
if ( F_75 ( V_6 == NULL ) )
return - V_22 ;
if ( V_172 )
* V_172 = V_6 ;
F_73 ( & V_89 -> V_94 , 8 , V_131 -> V_136 ,
F_74 ( V_131 -> V_137 ) - 1 ,
& V_89 -> V_95 , 0 , V_131 -> V_138 , 0 , 0 ) ;
if ( ( V_173 == 0 || ( ( V_173 * 8 ) / V_6 -> V_100 [ 0 ] ) < V_89 -> V_94 ) )
V_89 -> V_101 [ 0 ] . V_171 = ( V_89 -> V_94 *
V_6 -> V_100 [ 0 ] ) / 8 ;
if ( V_89 -> V_101 [ 0 ] . V_102 == 0 )
V_89 -> V_101 [ 0 ] . V_102 = ( V_89 -> V_94 * V_89 -> V_95 *
V_6 -> V_100 [ 0 ] ) / 8 ;
V_89 -> V_85 = V_6 -> V_98 ;
V_89 -> V_2 = V_6 -> V_12 ;
V_89 -> V_140 = V_6 -> V_140 ;
V_89 -> V_147 = V_148 ;
return 0 ;
}
static int F_89 ( struct V_110 * V_110 , void * V_127 ,
struct V_82 * V_167 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
return F_88 ( V_14 , & V_167 -> V_6 . V_93 , NULL ) ;
}
static int F_90 ( struct V_110 * V_110 , void * V_49 ,
struct V_82 * V_167 )
{
struct V_88 * V_89 = & V_167 -> V_6 . V_93 ;
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_90 * V_91 = & V_14 -> V_21 ;
const struct V_1 * V_6 = NULL ;
int V_79 ;
if ( F_91 ( & V_14 -> V_109 ) )
return - V_115 ;
V_79 = F_88 ( V_14 , & V_167 -> V_6 . V_93 , & V_6 ) ;
if ( V_79 < 0 )
return V_79 ;
V_91 -> V_6 = V_6 ;
V_14 -> V_105 [ 0 ] = F_48 ( ( V_89 -> V_94 * V_89 -> V_95 * V_6 -> V_100 [ 0 ] ) / 8 ,
V_89 -> V_101 [ 0 ] . V_102 ) ;
V_91 -> V_96 = V_89 -> V_94 ;
V_91 -> V_97 = V_89 -> V_95 ;
return 0 ;
}
static int F_92 ( struct V_13 * V_14 )
{
struct V_176 * V_177 = & V_14 -> V_149 ;
struct V_128 V_142 , V_178 ;
struct V_179 * V_134 ;
int V_79 ;
while ( 1 ) {
V_134 = & V_177 -> V_113 . V_180 [ 0 ] ;
if ( ! ( V_134 -> V_11 & V_181 ) )
break;
if ( V_177 == & V_14 -> V_149 ) {
struct V_90 * V_182 = & V_14 -> V_21 ;
V_142 . V_129 . V_94 = V_182 -> V_96 ;
V_142 . V_129 . V_95 = V_182 -> V_97 ;
V_142 . V_129 . V_139 = V_14 -> V_20 . V_6 -> V_3 ;
} else {
V_142 . V_134 = V_134 -> V_5 ;
V_142 . V_145 = V_183 ;
V_79 = F_93 ( V_177 , V_134 , V_184 , NULL ,
& V_142 ) ;
if ( V_79 < 0 && V_79 != - V_185 )
return - V_186 ;
}
V_134 = F_94 ( V_134 ) ;
if ( V_134 == NULL ||
F_95 ( V_134 -> V_113 ) != V_187 )
break;
V_177 = F_96 ( V_134 -> V_113 ) ;
V_178 . V_134 = V_134 -> V_5 ;
V_178 . V_145 = V_183 ;
V_79 = F_93 ( V_177 , V_134 , V_184 , NULL , & V_178 ) ;
if ( V_79 < 0 && V_79 != - V_185 )
return - V_186 ;
if ( V_178 . V_129 . V_94 != V_142 . V_129 . V_94 ||
V_178 . V_129 . V_95 != V_142 . V_129 . V_95 ||
V_178 . V_129 . V_139 != V_142 . V_129 . V_139 )
return - V_186 ;
}
return 0 ;
}
static int F_97 ( struct V_110 * V_110 , void * V_49 ,
enum V_188 type )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_111 * V_113 = & V_14 -> V_43 . V_106 . V_113 ;
int V_79 ;
if ( F_24 ( V_14 ) )
return - V_115 ;
V_79 = F_98 ( V_113 , & V_14 -> V_43 . V_189 -> V_190 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_92 ( V_14 ) ;
if ( V_79 < 0 )
goto V_191;
V_14 -> V_18 = F_99 ( & V_14 -> V_149 . V_113 ) ;
V_79 = F_100 ( V_110 , V_49 , type ) ;
if ( ! V_79 ) {
V_14 -> V_31 = true ;
return V_79 ;
}
V_191:
F_69 ( V_113 ) ;
return 0 ;
}
static int F_101 ( struct V_110 * V_110 , void * V_49 ,
enum V_188 type )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
int V_79 ;
V_79 = F_102 ( V_110 , V_49 , type ) ;
if ( V_79 < 0 )
return V_79 ;
F_69 ( & V_14 -> V_43 . V_106 . V_113 ) ;
V_14 -> V_31 = false ;
return 0 ;
}
static int F_103 ( struct V_110 * V_110 , void * V_49 ,
struct V_192 * V_193 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
int V_79 ;
V_193 -> V_77 = F_104 ( T_1 , V_194 , V_193 -> V_77 ) ;
V_79 = F_105 ( V_110 , V_49 , V_193 ) ;
if ( ! V_79 )
V_14 -> V_108 = V_193 -> V_77 ;
return V_79 ;
}
static int F_106 ( struct V_143 * V_195 , struct V_143 * V_196 )
{
if ( V_195 -> V_151 < V_196 -> V_151 || V_195 -> V_153 < V_196 -> V_153 )
return 0 ;
if ( V_195 -> V_151 + V_195 -> V_94 > V_196 -> V_151 + V_196 -> V_94 )
return 0 ;
if ( V_195 -> V_153 + V_195 -> V_95 > V_196 -> V_153 + V_196 -> V_95 )
return 0 ;
return 1 ;
}
static int F_107 ( struct V_110 * V_110 , void * V_127 ,
struct V_197 * V_198 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_90 * V_167 = & V_14 -> V_21 ;
if ( V_198 -> type != V_199 )
return - V_22 ;
switch ( V_198 -> V_200 ) {
case V_201 :
case V_202 :
V_198 -> V_150 . V_151 = 0 ;
V_198 -> V_150 . V_153 = 0 ;
V_198 -> V_150 . V_94 = V_167 -> V_96 ;
V_198 -> V_150 . V_95 = V_167 -> V_97 ;
return 0 ;
case V_203 :
V_198 -> V_150 = V_167 -> V_144 ;
return 0 ;
}
return - V_22 ;
}
static int F_108 ( struct V_110 * V_110 , void * V_127 ,
struct V_197 * V_198 )
{
struct V_13 * V_14 = F_60 ( V_110 ) ;
struct V_90 * V_167 = & V_14 -> V_21 ;
struct V_143 V_144 = V_198 -> V_150 ;
unsigned long V_11 ;
if ( V_198 -> type != V_199 ||
V_198 -> V_200 != V_203 )
return - V_22 ;
F_82 ( V_14 , & V_144 ) ;
if ( ( V_198 -> V_11 & V_204 ) &&
! F_106 ( & V_144 , & V_198 -> V_150 ) )
return - V_205 ;
if ( ( V_198 -> V_11 & V_206 ) &&
! F_106 ( & V_198 -> V_150 , & V_144 ) )
return - V_205 ;
V_198 -> V_150 = V_144 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_167 -> V_144 = V_144 ;
F_25 ( V_47 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
static int F_109 ( struct V_111 * V_113 ,
const struct V_179 * V_207 ,
const struct V_179 * V_208 , T_1 V_11 )
{
struct V_176 * V_177 = F_96 ( V_113 ) ;
struct V_13 * V_14 = F_110 ( V_177 ) ;
unsigned int V_209 = F_95 ( V_208 -> V_113 ) ;
int V_79 = 0 ;
if ( F_75 ( V_14 == NULL ) )
return 0 ;
F_78 ( 1 , V_26 , V_177 , L_6 ,
V_27 , V_208 -> V_113 -> V_169 , V_207 -> V_113 -> V_169 ,
V_11 , V_14 -> V_210 ) ;
switch ( V_207 -> V_5 ) {
case V_135 :
if ( V_209 != V_187 ) {
V_79 = - V_22 ;
break;
}
if ( V_11 & V_211 ) {
if ( V_14 -> V_210 == 0 )
V_14 -> V_210 = V_177 -> V_212 ;
else
V_79 = - V_115 ;
} else {
V_14 -> V_210 = 0 ;
V_14 -> V_18 = NULL ;
}
break;
case V_213 :
if ( ! ( V_11 & V_211 ) )
F_111 ( & V_14 -> V_61 , V_214 ) ;
else if ( V_209 == V_215 )
F_111 ( & V_14 -> V_61 , V_62 ) ;
else
V_79 = - V_22 ;
break;
case V_216 :
if ( ! ( V_11 & V_211 ) )
F_111 ( & V_14 -> V_61 , V_214 ) ;
else if ( V_209 == V_187 )
F_111 ( & V_14 -> V_61 , V_217 ) ;
else
V_79 = - V_22 ;
break;
default:
F_51 ( V_177 , L_7 ) ;
V_79 = - V_22 ;
}
F_112 () ;
return V_79 ;
}
static int F_113 ( struct V_176 * V_177 ,
struct V_126 * V_127 ,
struct V_218 * V_139 )
{
const struct V_1 * V_6 ;
V_6 = F_1 ( NULL , NULL , 0 , V_139 -> V_5 ) ;
if ( ! V_6 )
return - V_22 ;
V_139 -> V_139 = V_6 -> V_3 ;
return 0 ;
}
static struct V_132 * F_114 (
struct V_126 * V_127 , unsigned int V_134 )
{
if ( V_134 != V_135 )
V_134 = V_213 ;
return F_76 ( V_127 , V_134 ) ;
}
static int F_115 ( struct V_176 * V_177 ,
struct V_126 * V_127 ,
struct V_128 * V_6 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
struct V_132 * V_133 = & V_6 -> V_129 ;
struct V_90 * V_167 = & V_14 -> V_20 ;
if ( V_6 -> V_145 == V_146 ) {
V_133 = F_114 ( V_127 , V_6 -> V_134 ) ;
V_6 -> V_129 = * V_133 ;
return 0 ;
}
F_61 ( & V_14 -> V_114 ) ;
V_133 -> V_140 = V_167 -> V_6 -> V_140 ;
V_133 -> V_139 = V_167 -> V_6 -> V_3 ;
if ( V_6 -> V_134 == V_135 ) {
V_133 -> V_94 = V_167 -> V_96 ;
V_133 -> V_95 = V_167 -> V_97 ;
} else {
V_133 -> V_94 = V_167 -> V_144 . V_94 ;
V_133 -> V_95 = V_167 -> V_144 . V_95 ;
}
F_65 ( & V_14 -> V_114 ) ;
return 0 ;
}
static int F_116 ( struct V_176 * V_177 ,
struct V_126 * V_127 ,
struct V_128 * V_6 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
struct V_132 * V_133 = & V_6 -> V_129 ;
struct V_90 * V_141 = & V_14 -> V_20 ;
struct V_90 * V_219 = & V_14 -> V_21 ;
const struct V_1 * V_172 ;
F_78 ( 1 , V_26 , V_177 , L_8 ,
V_6 -> V_134 , V_133 -> V_139 , V_133 -> V_94 , V_133 -> V_95 ) ;
F_61 ( & V_14 -> V_114 ) ;
if ( ( F_38 ( & V_14 -> V_61 ) == V_217 &&
V_177 -> V_113 . V_220 > 0 ) ||
( F_38 ( & V_14 -> V_61 ) == V_62 &&
F_91 ( & V_14 -> V_109 ) ) ) {
F_65 ( & V_14 -> V_114 ) ;
return - V_115 ;
}
V_172 = F_72 ( V_14 , V_127 , V_6 ) ;
if ( V_6 -> V_145 == V_146 ) {
struct V_132 * V_178 ;
V_133 = F_114 ( V_127 , V_6 -> V_134 ) ;
* V_133 = V_6 -> V_129 ;
if ( V_6 -> V_134 == V_135 ) {
unsigned int V_134 = V_213 ;
V_178 = F_114 ( V_127 , V_134 ) ;
* V_178 = * V_133 ;
}
F_65 ( & V_14 -> V_114 ) ;
return 0 ;
}
if ( V_6 -> V_134 == V_135 ) {
V_141 -> V_96 = V_133 -> V_94 ;
V_141 -> V_97 = V_133 -> V_95 ;
V_141 -> V_6 = V_172 ;
V_141 -> V_144 . V_94 = V_133 -> V_94 ;
V_141 -> V_144 . V_95 = V_133 -> V_95 ;
V_141 -> V_144 . V_151 = 0 ;
V_141 -> V_144 . V_153 = 0 ;
V_219 -> V_144 = V_141 -> V_144 ;
V_219 -> V_96 = V_133 -> V_94 ;
V_219 -> V_97 = V_133 -> V_95 ;
}
F_65 ( & V_14 -> V_114 ) ;
return 0 ;
}
static int F_117 ( struct V_176 * V_177 ,
struct V_126 * V_127 ,
struct V_221 * V_198 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
struct V_90 * V_167 = & V_14 -> V_20 ;
if ( ( V_198 -> V_200 != V_222 &&
V_198 -> V_200 != V_223 ) ||
V_198 -> V_134 != V_135 )
return - V_22 ;
if ( V_198 -> V_145 == V_146 ) {
V_198 -> V_150 = * F_77 ( V_127 , V_198 -> V_134 ) ;
return 0 ;
}
F_61 ( & V_14 -> V_114 ) ;
if ( V_198 -> V_200 == V_222 ) {
V_198 -> V_150 = V_167 -> V_144 ;
} else {
V_198 -> V_150 . V_151 = 0 ;
V_198 -> V_150 . V_153 = 0 ;
V_198 -> V_150 . V_94 = V_167 -> V_96 ;
V_198 -> V_150 . V_95 = V_167 -> V_97 ;
}
F_65 ( & V_14 -> V_114 ) ;
F_78 ( 1 , V_26 , V_177 , L_9 ,
V_27 , V_167 -> V_144 . V_151 , V_167 -> V_144 . V_153 , V_167 -> V_144 . V_94 ,
V_167 -> V_144 . V_95 , V_167 -> V_96 , V_167 -> V_97 ) ;
return 0 ;
}
static int F_118 ( struct V_176 * V_177 ,
struct V_126 * V_127 ,
struct V_221 * V_198 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
struct V_90 * V_167 = & V_14 -> V_20 ;
int V_79 = 0 ;
if ( V_198 -> V_200 != V_222 || V_198 -> V_134 != V_135 )
return - V_22 ;
F_61 ( & V_14 -> V_114 ) ;
F_79 ( V_14 , & V_198 -> V_150 ) ;
if ( V_198 -> V_145 == V_146 ) {
* F_77 ( V_127 , V_198 -> V_134 ) = V_198 -> V_150 ;
} else {
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_167 -> V_144 = V_198 -> V_150 ;
V_14 -> V_21 . V_144 = V_198 -> V_150 ;
F_25 ( V_47 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
F_65 ( & V_14 -> V_114 ) ;
F_78 ( 1 , V_26 , V_177 , L_9 ,
V_27 , V_167 -> V_144 . V_151 , V_167 -> V_144 . V_153 , V_167 -> V_144 . V_94 ,
V_167 -> V_144 . V_95 , V_167 -> V_96 , V_167 -> V_97 ) ;
return V_79 ;
}
static int F_119 ( struct V_176 * V_177 , int V_224 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
unsigned long V_11 ;
int V_79 ;
V_14 -> V_18 = F_99 ( & V_177 -> V_113 ) ;
if ( F_38 ( & V_14 -> V_61 ) != V_217 )
return - V_185 ;
F_61 ( & V_14 -> V_114 ) ;
if ( V_224 ) {
F_21 ( V_14 ) ;
V_79 = F_3 ( V_14 , true ) ;
if ( ! V_79 ) {
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_45 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
} else {
F_25 ( V_35 , & V_14 -> V_32 ) ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_26 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
V_79 = F_27 ( V_14 -> V_45 ,
! F_28 ( V_35 , & V_14 -> V_32 ) ,
F_120 ( 200 ) ) ;
if ( V_79 == 0 )
F_51 ( V_177 , L_10 ) ;
F_31 ( V_34 , & V_14 -> V_32 ) ;
}
F_65 ( & V_14 -> V_114 ) ;
return V_79 ;
}
static int F_121 ( struct V_176 * V_177 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
F_13 ( V_14 , V_27 ) ;
return 0 ;
}
static int F_122 ( struct V_176 * V_177 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
struct V_75 * V_76 = & V_14 -> V_109 ;
struct V_225 * V_226 = & V_14 -> V_43 . V_106 ;
int V_79 ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
F_111 ( & V_14 -> V_61 , V_62 ) ;
snprintf ( V_226 -> V_169 , sizeof( V_226 -> V_169 ) , L_11 ,
V_14 -> V_5 ) ;
V_226 -> V_227 = & V_228 ;
V_226 -> V_229 = & V_230 ;
V_226 -> V_231 = V_177 -> V_231 ;
V_226 -> V_232 = - 1 ;
V_226 -> V_233 = V_234 ;
V_226 -> V_235 = V_76 ;
V_14 -> V_108 = 0 ;
F_123 ( & V_14 -> V_39 ) ;
F_123 ( & V_14 -> V_42 ) ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> type = V_199 ;
V_76 -> V_236 = V_237 | V_238 ;
V_76 -> V_239 = & V_240 ;
V_76 -> V_241 = & V_242 ;
V_76 -> V_243 = sizeof( struct V_29 ) ;
V_76 -> V_78 = V_14 ;
V_76 -> V_244 = V_245 ;
V_76 -> V_114 = & V_14 -> V_114 ;
V_79 = F_124 ( V_76 ) ;
if ( V_79 < 0 )
return V_79 ;
V_14 -> V_246 . V_11 = V_181 ;
V_79 = F_125 ( & V_226 -> V_113 , 1 , & V_14 -> V_246 , 0 ) ;
if ( V_79 < 0 )
return V_79 ;
F_126 ( V_226 , V_14 ) ;
V_14 -> V_43 . V_189 = F_4 ( V_177 ) ;
V_79 = F_127 ( V_226 , V_247 , - 1 ) ;
if ( V_79 < 0 ) {
F_128 ( & V_226 -> V_113 ) ;
V_14 -> V_43 . V_189 = NULL ;
return V_79 ;
}
F_129 ( V_177 -> V_231 , L_12 ,
V_226 -> V_169 , F_130 ( V_226 ) ) ;
return 0 ;
}
static void F_131 ( struct V_176 * V_177 )
{
struct V_13 * V_14 = F_110 ( V_177 ) ;
if ( V_14 == NULL )
return;
F_61 ( & V_14 -> V_114 ) ;
if ( F_132 ( & V_14 -> V_43 . V_106 ) ) {
F_133 ( & V_14 -> V_43 . V_106 ) ;
F_128 ( & V_14 -> V_43 . V_106 . V_113 ) ;
V_14 -> V_43 . V_189 = NULL ;
}
F_65 ( & V_14 -> V_114 ) ;
}
static int F_134 ( struct V_248 * V_249 )
{
struct V_13 * V_14 = F_54 ( V_249 -> V_250 , struct V_13 ,
V_251 ) ;
F_25 ( V_47 , & V_14 -> V_32 ) ;
return 0 ;
}
static void F_135 ( struct V_13 * V_14 )
{
struct V_90 * V_141 = & V_14 -> V_20 ;
struct V_90 * V_219 = & V_14 -> V_21 ;
V_141 -> V_6 = & V_10 [ 0 ] ;
V_141 -> V_96 = V_252 ;
V_141 -> V_97 = V_253 ;
V_141 -> V_144 . V_94 = V_252 ;
V_141 -> V_144 . V_95 = V_253 ;
V_141 -> V_144 . V_151 = 0 ;
V_141 -> V_144 . V_153 = 0 ;
* V_219 = * V_141 ;
}
static int F_136 ( struct V_13 * V_14 )
{
struct V_254 * V_250 = & V_14 -> V_251 ;
struct V_176 * V_177 = & V_14 -> V_149 ;
int V_79 ;
F_137 ( V_177 , & V_255 ) ;
V_177 -> V_11 |= V_256 ;
snprintf ( V_177 -> V_169 , sizeof( V_177 -> V_169 ) , L_13 , V_14 -> V_5 ) ;
V_14 -> V_257 [ V_135 ] . V_11 = V_181 ;
V_14 -> V_257 [ V_213 ] . V_11 = V_258 ;
V_14 -> V_257 [ V_216 ] . V_11 = V_258 ;
V_79 = F_125 ( & V_177 -> V_113 , V_259 ,
V_14 -> V_257 , 0 ) ;
if ( V_79 )
return V_79 ;
F_138 ( V_250 , 1 ) ;
V_14 -> V_24 = F_139 ( V_250 , & V_260 ,
NULL ) ;
if ( V_250 -> error ) {
F_128 ( & V_177 -> V_113 ) ;
return V_250 -> error ;
}
V_177 -> V_251 = V_250 ;
V_177 -> V_261 = & V_262 ;
V_177 -> V_113 . V_239 = & V_263 ;
V_177 -> V_264 = V_265 ;
F_140 ( V_177 , V_14 ) ;
return 0 ;
}
static void F_141 ( struct V_13 * V_14 )
{
struct V_176 * V_177 = & V_14 -> V_149 ;
F_142 ( V_177 ) ;
F_128 ( & V_177 -> V_113 ) ;
F_143 ( & V_14 -> V_251 ) ;
F_140 ( V_177 , NULL ) ;
}
static void F_144 ( struct V_13 * V_14 )
{
if ( F_145 ( V_14 -> clock ) )
return;
F_146 ( V_14 -> clock ) ;
F_147 ( V_14 -> clock ) ;
V_14 -> clock = F_148 ( - V_22 ) ;
}
static int F_149 ( struct V_13 * V_14 )
{
int V_79 ;
V_14 -> clock = F_150 ( & V_14 -> V_118 -> V_119 , V_266 ) ;
if ( F_145 ( V_14 -> clock ) )
return F_151 ( V_14 -> clock ) ;
V_79 = F_152 ( V_14 -> clock ) ;
if ( V_79 < 0 ) {
F_147 ( V_14 -> clock ) ;
V_14 -> clock = F_148 ( - V_22 ) ;
}
return V_79 ;
}
static int F_153 ( struct V_267 * V_118 )
{
struct V_130 * V_268 = NULL ;
struct V_269 * V_119 = & V_118 -> V_119 ;
const struct V_270 * V_271 ;
struct V_13 * V_14 ;
struct V_272 * V_273 ;
int V_79 ;
V_14 = F_154 ( V_119 , sizeof( * V_14 ) , V_274 ) ;
if ( ! V_14 )
return - V_275 ;
if ( V_119 -> V_276 ) {
V_271 = F_155 ( V_277 , V_119 -> V_276 ) ;
if ( V_271 )
V_268 = (struct V_130 * ) V_271 -> V_278 ;
V_14 -> V_5 = F_156 ( V_119 -> V_276 , L_14 ) ;
}
if ( ! V_268 || V_14 -> V_5 >= V_268 -> V_279 ||
V_14 -> V_5 < 0 ) {
F_157 ( V_119 , L_15 ,
V_119 -> V_276 -> V_280 ) ;
return - V_22 ;
}
V_14 -> V_131 = V_268 ;
V_14 -> V_118 = V_118 ;
F_158 ( & V_14 -> V_45 ) ;
F_159 ( & V_14 -> V_23 ) ;
F_160 ( & V_14 -> V_114 ) ;
V_273 = F_161 ( V_118 , V_281 , 0 ) ;
V_14 -> V_282 = F_162 ( V_119 , V_273 ) ;
if ( F_145 ( V_14 -> V_282 ) )
return F_151 ( V_14 -> V_282 ) ;
V_273 = F_161 ( V_118 , V_283 , 0 ) ;
if ( V_273 == NULL ) {
F_157 ( V_119 , L_16 ) ;
return - V_19 ;
}
V_79 = F_149 ( V_14 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_163 ( V_119 , V_273 -> V_284 , F_32 ,
0 , F_85 ( V_119 ) , V_14 ) ;
if ( V_79 ) {
F_157 ( V_119 , L_17 , V_79 ) ;
goto V_285;
}
V_79 = F_136 ( V_14 ) ;
if ( V_79 )
goto V_285;
F_164 ( V_118 , V_14 ) ;
F_165 ( V_119 ) ;
V_79 = F_62 ( V_119 ) ;
if ( V_79 < 0 )
goto V_286;
V_14 -> V_103 = F_166 ( V_119 ) ;
if ( F_145 ( V_14 -> V_103 ) ) {
V_79 = F_151 ( V_14 -> V_103 ) ;
goto V_120;
}
F_71 ( V_119 ) ;
F_135 ( V_14 ) ;
F_167 ( V_119 , L_18 ,
V_14 -> V_5 ) ;
return 0 ;
V_120:
F_71 ( V_119 ) ;
V_286:
F_141 ( V_14 ) ;
V_285:
F_144 ( V_14 ) ;
return V_79 ;
}
static int F_168 ( struct V_269 * V_119 )
{
struct V_13 * V_14 = F_169 ( V_119 ) ;
F_170 ( V_14 -> clock ) ;
return 0 ;
}
static int F_171 ( struct V_269 * V_119 )
{
struct V_13 * V_14 = F_169 ( V_119 ) ;
F_172 ( V_14 -> clock ) ;
return 0 ;
}
static int F_173 ( struct V_269 * V_119 )
{
struct V_13 * V_14 = F_169 ( V_119 ) ;
struct V_29 * V_30 ;
unsigned long V_11 ;
int V_8 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_287 , & V_14 -> V_32 ) ||
! F_28 ( V_117 , & V_14 -> V_32 ) ) {
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
F_21 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_37 , & V_14 -> V_32 ) )
return 0 ;
F_123 ( & V_14 -> V_42 ) ;
F_22 ( & V_14 -> V_43 , V_123 ,
& V_14 -> V_43 . V_106 . V_113 , false ) ;
F_3 ( V_14 , F_38 ( & V_14 -> V_61 ) == V_217 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_108 ; V_8 ++ ) {
if ( F_16 ( & V_14 -> V_39 ) )
break;
V_30 = F_17 ( V_14 ) ;
F_53 ( & V_30 -> V_40 ) ;
}
return 0 ;
}
static int F_174 ( struct V_269 * V_119 )
{
struct V_13 * V_14 = F_169 ( V_119 ) ;
bool V_28 = F_28 ( V_117 , & V_14 -> V_32 ) ;
int V_79 ;
if ( F_44 ( V_287 , & V_14 -> V_32 ) )
return 0 ;
V_79 = F_23 ( V_14 , V_28 ) ;
if ( V_79 < 0 || ! F_24 ( V_14 ) )
return V_79 ;
return F_22 ( & V_14 -> V_43 , V_125 ) ;
}
static int F_175 ( struct V_267 * V_118 )
{
struct V_13 * V_14 = F_176 ( V_118 ) ;
struct V_269 * V_119 = & V_118 -> V_119 ;
F_177 ( V_119 ) ;
F_178 ( V_119 ) ;
F_141 ( V_14 ) ;
F_179 ( V_14 -> V_103 ) ;
F_144 ( V_14 ) ;
F_180 ( V_119 , L_19 ) ;
return 0 ;
}
