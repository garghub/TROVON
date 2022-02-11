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
F_18 ( & V_30 -> V_40 . V_41 , V_42 ) ;
}
while ( ! F_16 ( & V_14 -> V_43 ) ) {
V_30 = F_19 ( V_14 ) ;
if ( V_28 )
F_20 ( V_14 , V_30 ) ;
else
F_18 ( & V_30 -> V_40 . V_41 , V_42 ) ;
}
F_14 ( & V_14 -> V_23 , V_11 ) ;
F_21 ( V_14 ) ;
if ( ! V_31 )
return 0 ;
return F_22 ( & V_14 -> V_44 , V_45 , 0 ) ;
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
F_27 ( V_14 -> V_46 ,
! F_28 ( V_35 , & V_14 -> V_32 ) ,
( 2 * V_47 / 10 ) ) ;
return F_15 ( V_14 , V_28 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
F_8 ( V_14 , & V_14 -> V_20 ) ;
F_30 ( V_14 , & V_14 -> V_21 ) ;
F_12 ( V_14 , V_14 -> V_24 -> V_25 ) ;
F_31 ( V_48 , & V_14 -> V_32 ) ;
}
static T_2 F_32 ( int V_49 , void * V_50 )
{
struct V_13 * V_14 = V_50 ;
struct V_29 * V_51 ;
unsigned long V_11 ;
T_1 V_52 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_52 = F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
if ( F_35 ( V_35 , & V_14 -> V_32 ) ) {
F_36 ( & V_14 -> V_46 ) ;
goto V_53;
}
if ( V_52 & V_54 ) {
F_31 ( V_34 , & V_14 -> V_32 ) ;
V_14 -> V_55 . V_56 ++ ;
}
if ( V_52 & V_57 ) {
F_37 ( V_14 ) ;
F_31 ( V_36 , & V_14 -> V_32 ) ;
F_36 ( & V_14 -> V_46 ) ;
}
if ( F_38 ( & V_14 -> V_58 ) != V_59 )
goto V_53;
if ( ( V_52 & V_60 ) &&
F_28 ( V_34 , & V_14 -> V_32 ) &&
! F_16 ( & V_14 -> V_39 ) ) {
V_51 = F_17 ( V_14 ) ;
F_39 ( V_14 , V_51 ) ;
F_40 ( V_14 , V_51 ) ;
}
if ( ( V_52 & V_61 ) &&
F_28 ( V_34 , & V_14 -> V_32 ) &&
! F_16 ( & V_14 -> V_43 ) ) {
V_51 = F_19 ( V_14 ) ;
F_41 ( & V_51 -> V_40 . V_62 ) ;
V_51 -> V_40 . V_63 = V_14 -> V_64 ++ ;
F_42 ( V_14 , V_51 -> V_5 ) ;
F_18 ( & V_51 -> V_40 . V_41 , V_65 ) ;
}
if ( F_28 ( V_48 , & V_14 -> V_32 ) )
F_29 ( V_14 ) ;
if ( F_16 ( & V_14 -> V_39 ) ) {
F_26 ( V_14 ) ;
F_31 ( V_36 , & V_14 -> V_32 ) ;
}
V_53:
F_25 ( V_34 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return V_66 ;
}
static int F_43 ( struct V_67 * V_68 , unsigned int V_69 )
{
struct V_13 * V_14 = V_68 -> V_70 ;
unsigned long V_11 ;
int V_71 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_14 -> V_72 = 0 ;
V_14 -> V_64 = 0 ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
V_71 = F_3 ( V_14 , false ) ;
if ( V_71 ) {
F_15 ( V_14 , false ) ;
return V_71 ;
}
F_25 ( V_38 , & V_14 -> V_32 ) ;
if ( ! F_16 ( & V_14 -> V_43 ) &&
! F_44 ( V_36 , & V_14 -> V_32 ) ) {
F_45 ( V_14 ) ;
if ( ! F_44 ( V_33 , & V_14 -> V_32 ) )
F_22 ( & V_14 -> V_44 , V_45 , 1 ) ;
}
if ( V_26 > 0 )
F_13 ( V_14 , V_27 ) ;
return 0 ;
}
static void F_46 ( struct V_67 * V_68 )
{
struct V_13 * V_14 = V_68 -> V_70 ;
if ( ! F_24 ( V_14 ) )
return;
F_23 ( V_14 , false ) ;
}
static int F_47 ( struct V_67 * V_73 , const void * V_74 ,
unsigned int * V_75 , unsigned int * V_76 ,
unsigned int V_77 [] , void * V_78 [] )
{
const struct V_79 * V_80 = V_74 ;
const struct V_81 * V_82 = NULL ;
struct V_13 * V_14 = V_73 -> V_70 ;
struct V_83 * V_84 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_84 -> V_6 ;
unsigned long V_85 ;
int V_8 ;
if ( V_80 ) {
V_82 = & V_80 -> V_6 . V_86 ;
V_6 = F_1 ( & V_82 -> V_2 , NULL , 0 , - 1 ) ;
V_85 = V_82 -> V_87 * V_82 -> V_88 ;
} else {
V_85 = V_84 -> V_89 * V_84 -> V_90 ;
}
if ( V_6 == NULL )
return - V_22 ;
* V_76 = V_6 -> V_91 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_91 ; V_8 ++ ) {
unsigned int V_92 = ( V_85 * V_6 -> V_93 [ V_8 ] ) / 8 ;
if ( V_82 )
V_77 [ V_8 ] = F_48 ( V_92 , V_82 -> V_94 [ V_8 ] . V_95 ) ;
else
V_77 [ V_8 ] = V_92 ;
V_78 [ V_8 ] = V_14 -> V_96 ;
}
return 0 ;
}
static int F_49 ( struct V_97 * V_40 )
{
struct V_67 * V_73 = V_40 -> V_67 ;
struct V_13 * V_14 = V_73 -> V_70 ;
int V_8 ;
if ( V_14 -> V_21 . V_6 == NULL )
return - V_22 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_21 . V_6 -> V_91 ; V_8 ++ ) {
unsigned long V_92 = V_14 -> V_98 [ V_8 ] ;
if ( F_50 ( V_40 , V_8 ) < V_92 ) {
F_51 ( & V_14 -> V_44 . V_99 ,
L_1 ,
F_50 ( V_40 , V_8 ) , V_92 ) ;
return - V_22 ;
}
F_52 ( V_40 , V_8 , V_92 ) ;
}
return 0 ;
}
static void F_53 ( struct V_97 * V_40 )
{
struct V_100 * V_51 = F_54 ( V_40 ) ;
struct V_29 * V_30
= F_55 ( V_51 , struct V_29 , V_40 ) ;
struct V_13 * V_14 = F_56 ( V_40 -> V_67 ) ;
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_30 -> V_101 = F_57 ( V_40 , 0 ) ;
V_30 -> V_5 = V_14 -> V_72 ++ ;
if ( V_14 -> V_72 >= V_14 -> V_102 )
V_14 -> V_72 = 0 ;
if ( ! F_28 ( V_37 , & V_14 -> V_32 ) &&
! F_28 ( V_36 , & V_14 -> V_32 ) &&
F_16 ( & V_14 -> V_43 ) ) {
F_39 ( V_14 , V_30 ) ;
F_40 ( V_14 , V_30 ) ;
} else {
F_20 ( V_14 , V_30 ) ;
}
if ( F_58 ( & V_14 -> V_103 ) &&
! F_16 ( & V_14 -> V_39 ) &&
! F_44 ( V_36 , & V_14 -> V_32 ) ) {
F_45 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_44 ( V_33 , & V_14 -> V_32 ) )
F_22 ( & V_14 -> V_44 , V_45 , 1 ) ;
return;
}
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
memset ( & V_14 -> V_55 , 0 , sizeof( V_14 -> V_55 ) ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
static int F_60 ( struct V_104 * V_104 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_105 * V_106 = & V_14 -> V_44 . V_99 . V_107 ;
int V_71 ;
F_62 ( & V_14 -> V_108 ) ;
if ( F_38 ( & V_14 -> V_58 ) != V_59 ) {
V_71 = - V_109 ;
goto V_110;
}
F_25 ( V_111 , & V_14 -> V_32 ) ;
V_71 = F_63 ( & V_14 -> V_112 -> V_113 ) ;
if ( V_71 < 0 )
goto V_110;
V_71 = F_64 ( V_104 ) ;
if ( V_71 < 0 )
goto V_114;
if ( ! F_65 ( V_104 ) ||
F_38 ( & V_14 -> V_58 ) != V_59 )
goto V_110;
F_62 ( & V_106 -> V_115 -> V_116 ) ;
V_71 = F_22 ( & V_14 -> V_44 , V_117 , V_106 , true ) ;
if ( V_71 == 0 )
V_106 -> V_118 ++ ;
F_66 ( & V_106 -> V_115 -> V_116 ) ;
if ( ! V_71 ) {
F_59 ( V_14 ) ;
goto V_110;
}
F_67 ( V_104 ) ;
V_114:
F_68 ( & V_14 -> V_112 -> V_113 ) ;
F_31 ( V_111 , & V_14 -> V_32 ) ;
V_110:
F_66 ( & V_14 -> V_108 ) ;
return V_71 ;
}
static int F_69 ( struct V_104 * V_104 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_105 * V_107 = & V_14 -> V_44 . V_99 . V_107 ;
F_62 ( & V_14 -> V_108 ) ;
if ( F_65 ( V_104 ) &&
F_38 ( & V_14 -> V_58 ) == V_59 ) {
if ( V_14 -> V_31 ) {
F_70 ( V_107 ) ;
V_14 -> V_31 = false ;
}
F_23 ( V_14 , false ) ;
F_22 ( & V_14 -> V_44 , V_119 ) ;
F_31 ( V_111 , & V_14 -> V_32 ) ;
F_62 ( & V_107 -> V_115 -> V_116 ) ;
V_107 -> V_118 -- ;
F_66 ( & V_107 -> V_115 -> V_116 ) ;
}
F_71 ( V_104 , NULL ) ;
F_72 ( & V_14 -> V_112 -> V_113 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
F_66 ( & V_14 -> V_108 ) ;
return 0 ;
}
static const struct V_1 * F_73 ( struct V_13 * V_14 ,
struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_124 * V_125 = V_14 -> V_125 ;
struct V_126 * V_127 = & V_123 -> V_123 ;
const struct V_1 * V_6 = NULL ;
if ( V_123 -> V_128 == V_129 ) {
F_74 ( & V_127 -> V_87 , 8 , V_125 -> V_130 ,
F_75 ( V_125 -> V_131 ) - 1 ,
& V_127 -> V_88 , 0 , V_125 -> V_132 , 0 , 0 ) ;
V_6 = F_1 ( NULL , & V_127 -> V_133 , 0 , 0 ) ;
if ( F_76 ( ! V_6 ) )
return NULL ;
V_127 -> V_134 = V_6 -> V_134 ;
V_127 -> V_133 = V_6 -> V_3 ;
} else {
struct V_83 * V_135 = & V_14 -> V_20 ;
struct V_126 * V_136 ;
struct V_137 * V_138 ;
if ( V_123 -> V_139 == V_140 ) {
V_136 = F_77 ( & V_14 -> V_141 , V_121 ,
V_129 ) ;
V_127 -> V_133 = V_136 -> V_133 ;
V_127 -> V_134 = V_136 -> V_134 ;
V_138 = F_78 ( & V_14 -> V_141 , V_121 ,
V_129 ) ;
} else {
V_127 -> V_133 = V_135 -> V_6 -> V_3 ;
V_127 -> V_134 = V_135 -> V_6 -> V_134 ;
V_138 = & V_135 -> V_138 ;
}
V_127 -> V_87 = V_138 -> V_87 ;
V_127 -> V_88 = V_138 -> V_88 ;
}
V_127 -> V_142 = V_143 ;
F_79 ( 1 , V_26 , & V_14 -> V_141 , L_2 ,
V_127 -> V_133 , V_127 -> V_134 , V_127 -> V_87 , V_127 -> V_88 ) ;
return V_6 ;
}
static void F_80 ( struct V_13 * V_14 , struct V_137 * V_144 )
{
struct V_83 * V_84 = & V_14 -> V_20 ;
F_74 ( & V_144 -> V_87 , 0 , V_84 -> V_89 , 0 ,
& V_144 -> V_88 , 0 , V_84 -> V_90 , 0 , 0 ) ;
V_144 -> V_145 = F_81 ( T_1 , V_144 -> V_145 , 0 , V_84 -> V_89 - V_144 -> V_87 ) ;
V_144 -> V_145 = F_82 ( V_144 -> V_145 , V_14 -> V_125 -> V_146 ) ;
V_144 -> V_147 = F_81 ( T_1 , V_144 -> V_147 , 0 , V_84 -> V_90 - V_144 -> V_88 ) ;
F_79 ( 1 , V_26 , & V_14 -> V_141 , L_3 ,
V_144 -> V_145 , V_144 -> V_147 , V_144 -> V_87 , V_144 -> V_88 ,
V_84 -> V_89 , V_84 -> V_90 ) ;
}
static void F_83 ( struct V_13 * V_14 , struct V_137 * V_144 )
{
struct V_83 * V_84 = & V_14 -> V_21 ;
struct V_137 * V_148 = & V_14 -> V_20 . V_138 ;
V_144 -> V_87 = V_148 -> V_87 ;
V_144 -> V_88 = V_148 -> V_88 ;
V_144 -> V_145 = F_81 ( T_1 , V_144 -> V_145 , 0 , V_84 -> V_89 - V_144 -> V_87 ) ;
V_144 -> V_145 = F_82 ( V_144 -> V_145 , V_14 -> V_125 -> V_149 ) ;
V_144 -> V_147 = F_81 ( T_1 , V_144 -> V_147 , 0 , V_14 -> V_21 . V_90 - V_144 -> V_88 ) ;
F_79 ( 1 , V_26 , & V_14 -> V_141 , L_4 ,
V_144 -> V_145 , V_144 -> V_147 , V_144 -> V_87 , V_144 -> V_88 ,
V_84 -> V_89 , V_84 -> V_90 ) ;
}
static int F_84 ( struct V_104 * V_104 , void * V_50 ,
struct V_150 * V_151 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
F_85 ( V_151 -> V_152 , V_153 , sizeof( V_151 -> V_152 ) ) ;
F_85 ( V_151 -> V_154 , V_153 , sizeof( V_151 -> V_154 ) ) ;
snprintf ( V_151 -> V_155 , sizeof( V_151 -> V_155 ) , L_5 ,
F_86 ( & V_14 -> V_112 -> V_113 ) ) ;
V_151 -> V_156 = V_157 ;
V_151 -> V_158 = V_151 -> V_156 | V_159 ;
return 0 ;
}
static int F_87 ( struct V_104 * V_104 , void * V_50 ,
struct V_160 * V_161 )
{
const struct V_1 * V_6 ;
if ( V_161 -> V_5 >= F_2 ( V_10 ) )
return - V_22 ;
V_6 = & V_10 [ V_161 -> V_5 ] ;
F_85 ( V_161 -> V_162 , V_6 -> V_163 , sizeof( V_161 -> V_162 ) ) ;
V_161 -> V_2 = V_6 -> V_12 ;
return 0 ;
}
static int F_88 ( struct V_104 * V_104 , void * V_164 ,
struct V_79 * V_161 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_81 * V_82 = & V_161 -> V_6 . V_86 ;
struct V_165 * V_94 = & V_82 -> V_94 [ 0 ] ;
struct V_83 * V_84 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_84 -> V_6 ;
V_94 -> V_166 = ( V_84 -> V_89 * V_6 -> V_93 [ 0 ] ) / 8 ;
V_94 -> V_95 = V_94 -> V_166 * V_84 -> V_90 ;
V_82 -> V_76 = V_6 -> V_91 ;
V_82 -> V_2 = V_6 -> V_12 ;
V_82 -> V_87 = V_84 -> V_89 ;
V_82 -> V_88 = V_84 -> V_90 ;
V_82 -> V_142 = V_143 ;
V_82 -> V_134 = V_6 -> V_134 ;
return 0 ;
}
static int F_89 ( struct V_13 * V_14 ,
struct V_81 * V_82 ,
const struct V_1 * * V_167 )
{
T_1 V_168 = V_82 -> V_94 [ 0 ] . V_166 ;
struct V_124 * V_125 = V_14 -> V_125 ;
const struct V_1 * V_169 = V_14 -> V_20 . V_6 ;
const struct V_1 * V_6 ;
if ( F_76 ( V_169 == NULL ) )
return - V_22 ;
if ( V_169 -> V_11 & V_170 )
V_6 = F_1 ( & V_82 -> V_2 , NULL ,
V_169 -> V_11 , 0 ) ;
else
V_6 = V_169 ;
if ( F_76 ( V_6 == NULL ) )
return - V_22 ;
if ( V_167 )
* V_167 = V_6 ;
F_74 ( & V_82 -> V_87 , 8 , V_125 -> V_130 ,
F_75 ( V_125 -> V_131 ) - 1 ,
& V_82 -> V_88 , 0 , V_125 -> V_132 , 0 , 0 ) ;
if ( ( V_168 == 0 || ( ( V_168 * 8 ) / V_6 -> V_93 [ 0 ] ) < V_82 -> V_87 ) )
V_82 -> V_94 [ 0 ] . V_166 = ( V_82 -> V_87 *
V_6 -> V_93 [ 0 ] ) / 8 ;
if ( V_82 -> V_94 [ 0 ] . V_95 == 0 )
V_82 -> V_94 [ 0 ] . V_95 = ( V_82 -> V_87 * V_82 -> V_88 *
V_6 -> V_93 [ 0 ] ) / 8 ;
V_82 -> V_76 = V_6 -> V_91 ;
V_82 -> V_2 = V_6 -> V_12 ;
V_82 -> V_134 = V_6 -> V_134 ;
V_82 -> V_142 = V_143 ;
return 0 ;
}
static int F_90 ( struct V_104 * V_104 , void * V_164 ,
struct V_79 * V_161 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
return F_89 ( V_14 , & V_161 -> V_6 . V_86 , NULL ) ;
}
static int F_91 ( struct V_104 * V_104 , void * V_50 ,
struct V_79 * V_161 )
{
struct V_81 * V_82 = & V_161 -> V_6 . V_86 ;
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_83 * V_84 = & V_14 -> V_21 ;
const struct V_1 * V_6 = NULL ;
int V_71 ;
if ( F_92 ( & V_14 -> V_103 ) )
return - V_109 ;
V_71 = F_89 ( V_14 , & V_161 -> V_6 . V_86 , & V_6 ) ;
if ( V_71 < 0 )
return V_71 ;
V_84 -> V_6 = V_6 ;
V_14 -> V_98 [ 0 ] = F_48 ( ( V_82 -> V_87 * V_82 -> V_88 * V_6 -> V_93 [ 0 ] ) / 8 ,
V_82 -> V_94 [ 0 ] . V_95 ) ;
V_84 -> V_89 = V_82 -> V_87 ;
V_84 -> V_90 = V_82 -> V_88 ;
return 0 ;
}
static int F_93 ( struct V_13 * V_14 )
{
struct V_171 * V_172 = & V_14 -> V_141 ;
struct V_122 V_136 , V_173 ;
struct V_174 * V_128 ;
int V_71 ;
while ( 1 ) {
V_128 = & V_172 -> V_107 . V_175 [ 0 ] ;
if ( ! ( V_128 -> V_11 & V_176 ) )
break;
if ( V_172 == & V_14 -> V_141 ) {
struct V_83 * V_177 = & V_14 -> V_21 ;
V_136 . V_123 . V_87 = V_177 -> V_89 ;
V_136 . V_123 . V_88 = V_177 -> V_90 ;
V_136 . V_123 . V_133 = V_14 -> V_20 . V_6 -> V_3 ;
} else {
V_136 . V_128 = V_128 -> V_5 ;
V_136 . V_139 = V_178 ;
V_71 = F_94 ( V_172 , V_128 , V_179 , NULL ,
& V_136 ) ;
if ( V_71 < 0 && V_71 != - V_180 )
return - V_181 ;
}
V_128 = F_95 ( V_128 ) ;
if ( V_128 == NULL ||
F_96 ( V_128 -> V_107 ) != V_182 )
break;
V_172 = F_97 ( V_128 -> V_107 ) ;
V_173 . V_128 = V_128 -> V_5 ;
V_173 . V_139 = V_178 ;
V_71 = F_94 ( V_172 , V_128 , V_179 , NULL , & V_173 ) ;
if ( V_71 < 0 && V_71 != - V_180 )
return - V_181 ;
if ( V_173 . V_123 . V_87 != V_136 . V_123 . V_87 ||
V_173 . V_123 . V_88 != V_136 . V_123 . V_88 ||
V_173 . V_123 . V_133 != V_136 . V_123 . V_133 )
return - V_181 ;
}
return 0 ;
}
static int F_98 ( struct V_104 * V_104 , void * V_50 ,
enum V_183 type )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_105 * V_107 = & V_14 -> V_44 . V_99 . V_107 ;
int V_71 ;
if ( F_24 ( V_14 ) )
return - V_109 ;
V_71 = F_99 ( V_107 , & V_14 -> V_44 . V_184 -> V_185 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_93 ( V_14 ) ;
if ( V_71 < 0 )
goto V_186;
V_14 -> V_18 = F_100 ( & V_14 -> V_141 . V_107 ) ;
V_71 = F_101 ( V_104 , V_50 , type ) ;
if ( ! V_71 ) {
V_14 -> V_31 = true ;
return V_71 ;
}
V_186:
F_70 ( V_107 ) ;
return 0 ;
}
static int F_102 ( struct V_104 * V_104 , void * V_50 ,
enum V_183 type )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
int V_71 ;
V_71 = F_103 ( V_104 , V_50 , type ) ;
if ( V_71 < 0 )
return V_71 ;
F_70 ( & V_14 -> V_44 . V_99 . V_107 ) ;
V_14 -> V_31 = false ;
return 0 ;
}
static int F_104 ( struct V_104 * V_104 , void * V_50 ,
struct V_187 * V_188 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
int V_71 ;
V_188 -> V_69 = F_105 ( T_1 , V_189 , V_188 -> V_69 ) ;
V_71 = F_106 ( V_104 , V_50 , V_188 ) ;
if ( ! V_71 )
V_14 -> V_102 = V_188 -> V_69 ;
return V_71 ;
}
static int F_107 ( struct V_137 * V_190 , struct V_137 * V_191 )
{
if ( V_190 -> V_145 < V_191 -> V_145 || V_190 -> V_147 < V_191 -> V_147 )
return 0 ;
if ( V_190 -> V_145 + V_190 -> V_87 > V_191 -> V_145 + V_191 -> V_87 )
return 0 ;
if ( V_190 -> V_147 + V_190 -> V_88 > V_191 -> V_147 + V_191 -> V_88 )
return 0 ;
return 1 ;
}
static int F_108 ( struct V_104 * V_104 , void * V_164 ,
struct V_192 * V_193 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_83 * V_161 = & V_14 -> V_21 ;
if ( V_193 -> type != V_194 )
return - V_22 ;
switch ( V_193 -> V_195 ) {
case V_196 :
case V_197 :
V_193 -> V_144 . V_145 = 0 ;
V_193 -> V_144 . V_147 = 0 ;
V_193 -> V_144 . V_87 = V_161 -> V_89 ;
V_193 -> V_144 . V_88 = V_161 -> V_90 ;
return 0 ;
case V_198 :
V_193 -> V_144 = V_161 -> V_138 ;
return 0 ;
}
return - V_22 ;
}
static int F_109 ( struct V_104 * V_104 , void * V_164 ,
struct V_192 * V_193 )
{
struct V_13 * V_14 = F_61 ( V_104 ) ;
struct V_83 * V_161 = & V_14 -> V_21 ;
struct V_137 V_138 = V_193 -> V_144 ;
unsigned long V_11 ;
if ( V_193 -> type != V_194 ||
V_193 -> V_195 != V_198 )
return - V_22 ;
F_83 ( V_14 , & V_138 ) ;
if ( ( V_193 -> V_11 & V_199 ) &&
! F_107 ( & V_138 , & V_193 -> V_144 ) )
return - V_200 ;
if ( ( V_193 -> V_11 & V_201 ) &&
! F_107 ( & V_193 -> V_144 , & V_138 ) )
return - V_200 ;
V_193 -> V_144 = V_138 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_161 -> V_138 = V_138 ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
static int F_110 ( struct V_105 * V_107 ,
const struct V_174 * V_202 ,
const struct V_174 * V_203 , T_1 V_11 )
{
struct V_171 * V_172 = F_97 ( V_107 ) ;
struct V_13 * V_14 = F_111 ( V_172 ) ;
unsigned int V_204 = F_96 ( V_203 -> V_107 ) ;
int V_71 = 0 ;
if ( F_76 ( V_14 == NULL ) )
return 0 ;
F_79 ( 1 , V_26 , V_172 , L_6 ,
V_27 , V_203 -> V_107 -> V_163 , V_202 -> V_107 -> V_163 ,
V_11 , V_14 -> V_205 ) ;
switch ( V_202 -> V_5 ) {
case V_129 :
if ( V_204 != V_182 ) {
V_71 = - V_22 ;
break;
}
if ( V_11 & V_206 ) {
if ( V_14 -> V_205 == 0 )
V_14 -> V_205 = V_172 -> V_207 ;
else
V_71 = - V_109 ;
} else {
V_14 -> V_205 = 0 ;
V_14 -> V_18 = NULL ;
}
break;
case V_208 :
if ( ! ( V_11 & V_206 ) )
F_112 ( & V_14 -> V_58 , V_209 ) ;
else if ( V_204 == V_210 )
F_112 ( & V_14 -> V_58 , V_59 ) ;
else
V_71 = - V_22 ;
break;
case V_211 :
if ( ! ( V_11 & V_206 ) )
F_112 ( & V_14 -> V_58 , V_209 ) ;
else if ( V_204 == V_182 )
F_112 ( & V_14 -> V_58 , V_212 ) ;
else
V_71 = - V_22 ;
break;
default:
F_51 ( V_172 , L_7 ) ;
V_71 = - V_22 ;
}
F_113 () ;
return V_71 ;
}
static int F_114 ( struct V_171 * V_172 ,
struct V_120 * V_121 ,
struct V_213 * V_133 )
{
const struct V_1 * V_6 ;
V_6 = F_1 ( NULL , NULL , 0 , V_133 -> V_5 ) ;
if ( ! V_6 )
return - V_22 ;
V_133 -> V_133 = V_6 -> V_3 ;
return 0 ;
}
static struct V_126 * F_115 (
struct V_171 * V_172 ,
struct V_120 * V_121 , unsigned int V_128 )
{
if ( V_128 != V_129 )
V_128 = V_208 ;
return F_77 ( V_172 , V_121 , V_128 ) ;
}
static int F_116 ( struct V_171 * V_172 ,
struct V_120 * V_121 ,
struct V_122 * V_6 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
struct V_126 * V_127 = & V_6 -> V_123 ;
struct V_83 * V_161 = & V_14 -> V_20 ;
if ( V_6 -> V_139 == V_140 ) {
V_127 = F_115 ( V_172 , V_121 , V_6 -> V_128 ) ;
V_6 -> V_123 = * V_127 ;
return 0 ;
}
F_62 ( & V_14 -> V_108 ) ;
V_127 -> V_134 = V_161 -> V_6 -> V_134 ;
V_127 -> V_133 = V_161 -> V_6 -> V_3 ;
if ( V_6 -> V_128 == V_129 ) {
V_127 -> V_87 = V_161 -> V_89 ;
V_127 -> V_88 = V_161 -> V_90 ;
} else {
V_127 -> V_87 = V_161 -> V_138 . V_87 ;
V_127 -> V_88 = V_161 -> V_138 . V_88 ;
}
F_66 ( & V_14 -> V_108 ) ;
return 0 ;
}
static int F_117 ( struct V_171 * V_172 ,
struct V_120 * V_121 ,
struct V_122 * V_6 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
struct V_126 * V_127 = & V_6 -> V_123 ;
struct V_83 * V_135 = & V_14 -> V_20 ;
struct V_83 * V_214 = & V_14 -> V_21 ;
const struct V_1 * V_167 ;
F_79 ( 1 , V_26 , V_172 , L_8 ,
V_6 -> V_128 , V_127 -> V_133 , V_127 -> V_87 , V_127 -> V_88 ) ;
F_62 ( & V_14 -> V_108 ) ;
if ( ( F_38 ( & V_14 -> V_58 ) == V_212 &&
V_172 -> V_107 . V_215 > 0 ) ||
( F_38 ( & V_14 -> V_58 ) == V_59 &&
F_92 ( & V_14 -> V_103 ) ) ) {
F_66 ( & V_14 -> V_108 ) ;
return - V_109 ;
}
V_167 = F_73 ( V_14 , V_121 , V_6 ) ;
if ( V_6 -> V_139 == V_140 ) {
struct V_126 * V_173 ;
V_127 = F_115 ( V_172 , V_121 , V_6 -> V_128 ) ;
* V_127 = V_6 -> V_123 ;
if ( V_6 -> V_128 == V_129 ) {
unsigned int V_128 = V_208 ;
V_173 = F_115 ( V_172 , V_121 , V_128 ) ;
* V_173 = * V_127 ;
}
F_66 ( & V_14 -> V_108 ) ;
return 0 ;
}
if ( V_6 -> V_128 == V_129 ) {
V_135 -> V_89 = V_127 -> V_87 ;
V_135 -> V_90 = V_127 -> V_88 ;
V_135 -> V_6 = V_167 ;
V_135 -> V_138 . V_87 = V_127 -> V_87 ;
V_135 -> V_138 . V_88 = V_127 -> V_88 ;
V_135 -> V_138 . V_145 = 0 ;
V_135 -> V_138 . V_147 = 0 ;
V_214 -> V_138 = V_135 -> V_138 ;
V_214 -> V_89 = V_127 -> V_87 ;
V_214 -> V_90 = V_127 -> V_88 ;
}
F_66 ( & V_14 -> V_108 ) ;
return 0 ;
}
static int F_118 ( struct V_171 * V_172 ,
struct V_120 * V_121 ,
struct V_216 * V_193 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
struct V_83 * V_161 = & V_14 -> V_20 ;
if ( ( V_193 -> V_195 != V_217 &&
V_193 -> V_195 != V_218 ) ||
V_193 -> V_128 != V_129 )
return - V_22 ;
if ( V_193 -> V_139 == V_140 ) {
V_193 -> V_144 = * F_78 ( V_172 , V_121 , V_193 -> V_128 ) ;
return 0 ;
}
F_62 ( & V_14 -> V_108 ) ;
if ( V_193 -> V_195 == V_217 ) {
V_193 -> V_144 = V_161 -> V_138 ;
} else {
V_193 -> V_144 . V_145 = 0 ;
V_193 -> V_144 . V_147 = 0 ;
V_193 -> V_144 . V_87 = V_161 -> V_89 ;
V_193 -> V_144 . V_88 = V_161 -> V_90 ;
}
F_66 ( & V_14 -> V_108 ) ;
F_79 ( 1 , V_26 , V_172 , L_9 ,
V_27 , V_161 -> V_138 . V_145 , V_161 -> V_138 . V_147 , V_161 -> V_138 . V_87 ,
V_161 -> V_138 . V_88 , V_161 -> V_89 , V_161 -> V_90 ) ;
return 0 ;
}
static int F_119 ( struct V_171 * V_172 ,
struct V_120 * V_121 ,
struct V_216 * V_193 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
struct V_83 * V_161 = & V_14 -> V_20 ;
int V_71 = 0 ;
if ( V_193 -> V_195 != V_217 || V_193 -> V_128 != V_129 )
return - V_22 ;
F_62 ( & V_14 -> V_108 ) ;
F_80 ( V_14 , & V_193 -> V_144 ) ;
if ( V_193 -> V_139 == V_140 ) {
* F_78 ( V_172 , V_121 , V_193 -> V_128 ) = V_193 -> V_144 ;
} else {
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_161 -> V_138 = V_193 -> V_144 ;
V_14 -> V_21 . V_138 = V_193 -> V_144 ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
F_66 ( & V_14 -> V_108 ) ;
F_79 ( 1 , V_26 , V_172 , L_9 ,
V_27 , V_161 -> V_138 . V_145 , V_161 -> V_138 . V_147 , V_161 -> V_138 . V_87 ,
V_161 -> V_138 . V_88 , V_161 -> V_89 , V_161 -> V_90 ) ;
return V_71 ;
}
static int F_120 ( struct V_171 * V_172 , int V_219 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
unsigned long V_11 ;
int V_71 ;
V_14 -> V_18 = F_100 ( & V_172 -> V_107 ) ;
if ( F_38 ( & V_14 -> V_58 ) != V_212 )
return - V_180 ;
F_62 ( & V_14 -> V_108 ) ;
if ( V_219 ) {
F_21 ( V_14 ) ;
V_71 = F_3 ( V_14 , true ) ;
if ( ! V_71 ) {
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_45 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
} else {
F_25 ( V_35 , & V_14 -> V_32 ) ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
F_26 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
V_71 = F_27 ( V_14 -> V_46 ,
! F_28 ( V_35 , & V_14 -> V_32 ) ,
F_121 ( 200 ) ) ;
if ( V_71 == 0 )
F_51 ( V_172 , L_10 ) ;
F_31 ( V_34 , & V_14 -> V_32 ) ;
}
F_66 ( & V_14 -> V_108 ) ;
return V_71 ;
}
static int F_122 ( struct V_171 * V_172 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
F_13 ( V_14 , V_27 ) ;
return 0 ;
}
static int F_123 ( struct V_171 * V_172 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
struct V_67 * V_68 = & V_14 -> V_103 ;
struct V_220 * V_221 = & V_14 -> V_44 . V_99 ;
int V_71 ;
memset ( V_221 , 0 , sizeof( * V_221 ) ) ;
F_112 ( & V_14 -> V_58 , V_59 ) ;
snprintf ( V_221 -> V_163 , sizeof( V_221 -> V_163 ) , L_11 ,
V_14 -> V_5 ) ;
V_221 -> V_222 = & V_223 ;
V_221 -> V_224 = & V_225 ;
V_221 -> V_226 = V_172 -> V_226 ;
V_221 -> V_227 = - 1 ;
V_221 -> V_228 = V_229 ;
V_221 -> V_230 = V_68 ;
V_14 -> V_102 = 0 ;
F_124 ( & V_14 -> V_39 ) ;
F_124 ( & V_14 -> V_43 ) ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> type = V_194 ;
V_68 -> V_231 = V_232 | V_233 ;
V_68 -> V_234 = & V_235 ;
V_68 -> V_236 = & V_237 ;
V_68 -> V_238 = sizeof( struct V_29 ) ;
V_68 -> V_70 = V_14 ;
V_68 -> V_239 = V_240 ;
V_68 -> V_108 = & V_14 -> V_108 ;
V_71 = F_125 ( V_68 ) ;
if ( V_71 < 0 )
return V_71 ;
V_14 -> V_241 . V_11 = V_176 ;
V_71 = F_126 ( & V_221 -> V_107 , 1 , & V_14 -> V_241 , 0 ) ;
if ( V_71 < 0 )
return V_71 ;
F_127 ( V_221 , V_14 ) ;
V_14 -> V_44 . V_184 = F_4 ( V_172 ) ;
V_71 = F_128 ( V_221 , V_242 , - 1 ) ;
if ( V_71 < 0 ) {
F_129 ( & V_221 -> V_107 ) ;
V_14 -> V_44 . V_184 = NULL ;
return V_71 ;
}
F_130 ( V_172 -> V_226 , L_12 ,
V_221 -> V_163 , F_131 ( V_221 ) ) ;
return 0 ;
}
static void F_132 ( struct V_171 * V_172 )
{
struct V_13 * V_14 = F_111 ( V_172 ) ;
if ( V_14 == NULL )
return;
F_62 ( & V_14 -> V_108 ) ;
if ( F_133 ( & V_14 -> V_44 . V_99 ) ) {
F_134 ( & V_14 -> V_44 . V_99 ) ;
F_129 ( & V_14 -> V_44 . V_99 . V_107 ) ;
V_14 -> V_44 . V_184 = NULL ;
}
F_66 ( & V_14 -> V_108 ) ;
}
static int F_135 ( struct V_243 * V_244 )
{
struct V_13 * V_14 = F_55 ( V_244 -> V_245 , struct V_13 ,
V_246 ) ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
return 0 ;
}
static void F_136 ( struct V_13 * V_14 )
{
struct V_83 * V_135 = & V_14 -> V_20 ;
struct V_83 * V_214 = & V_14 -> V_21 ;
V_135 -> V_6 = & V_10 [ 0 ] ;
V_135 -> V_89 = V_247 ;
V_135 -> V_90 = V_248 ;
V_135 -> V_138 . V_87 = V_247 ;
V_135 -> V_138 . V_88 = V_248 ;
V_135 -> V_138 . V_145 = 0 ;
V_135 -> V_138 . V_147 = 0 ;
* V_214 = * V_135 ;
}
static int F_137 ( struct V_13 * V_14 )
{
struct V_249 * V_245 = & V_14 -> V_246 ;
struct V_171 * V_172 = & V_14 -> V_141 ;
int V_71 ;
F_138 ( V_172 , & V_250 ) ;
V_172 -> V_11 |= V_251 ;
snprintf ( V_172 -> V_163 , sizeof( V_172 -> V_163 ) , L_13 , V_14 -> V_5 ) ;
V_14 -> V_252 [ V_129 ] . V_11 = V_176 ;
V_14 -> V_252 [ V_208 ] . V_11 = V_253 ;
V_14 -> V_252 [ V_211 ] . V_11 = V_253 ;
V_71 = F_126 ( & V_172 -> V_107 , V_254 ,
V_14 -> V_252 , 0 ) ;
if ( V_71 )
return V_71 ;
F_139 ( V_245 , 1 ) ;
V_14 -> V_24 = F_140 ( V_245 , & V_255 ,
NULL ) ;
if ( V_245 -> error ) {
F_129 ( & V_172 -> V_107 ) ;
return V_245 -> error ;
}
V_172 -> V_246 = V_245 ;
V_172 -> V_256 = & V_257 ;
V_172 -> V_107 . V_234 = & V_258 ;
V_172 -> V_259 = V_260 ;
F_141 ( V_172 , V_14 ) ;
return 0 ;
}
static void F_142 ( struct V_13 * V_14 )
{
struct V_171 * V_172 = & V_14 -> V_141 ;
F_143 ( V_172 ) ;
F_129 ( & V_172 -> V_107 ) ;
F_144 ( & V_14 -> V_246 ) ;
F_141 ( V_172 , NULL ) ;
}
static void F_145 ( struct V_13 * V_14 )
{
if ( F_146 ( V_14 -> clock ) )
return;
F_147 ( V_14 -> clock ) ;
F_148 ( V_14 -> clock ) ;
V_14 -> clock = F_149 ( - V_22 ) ;
}
static int F_150 ( struct V_13 * V_14 )
{
int V_71 ;
V_14 -> clock = F_151 ( & V_14 -> V_112 -> V_113 , V_261 ) ;
if ( F_146 ( V_14 -> clock ) )
return F_152 ( V_14 -> clock ) ;
V_71 = F_153 ( V_14 -> clock ) ;
if ( V_71 < 0 ) {
F_148 ( V_14 -> clock ) ;
V_14 -> clock = F_149 ( - V_22 ) ;
}
return V_71 ;
}
static int F_154 ( struct V_262 * V_112 )
{
struct V_124 * V_263 = NULL ;
struct V_264 * V_113 = & V_112 -> V_113 ;
const struct V_265 * V_266 ;
struct V_13 * V_14 ;
struct V_267 * V_268 ;
int V_71 ;
if ( ! V_113 -> V_269 )
return - V_270 ;
V_14 = F_155 ( V_113 , sizeof( * V_14 ) , V_271 ) ;
if ( ! V_14 )
return - V_272 ;
V_266 = F_156 ( V_273 , V_113 -> V_269 ) ;
if ( V_266 )
V_263 = (struct V_124 * ) V_266 -> V_274 ;
V_14 -> V_5 = F_157 ( V_113 -> V_269 , L_14 ) ;
if ( ! V_263 || V_14 -> V_5 >= V_263 -> V_275 ||
V_14 -> V_5 < 0 ) {
F_158 ( V_113 , L_15 ,
V_113 -> V_269 -> V_276 ) ;
return - V_22 ;
}
V_14 -> V_125 = V_263 ;
V_14 -> V_112 = V_112 ;
F_159 ( & V_14 -> V_46 ) ;
F_160 ( & V_14 -> V_23 ) ;
F_161 ( & V_14 -> V_108 ) ;
V_268 = F_162 ( V_112 , V_277 , 0 ) ;
V_14 -> V_278 = F_163 ( V_113 , V_268 ) ;
if ( F_146 ( V_14 -> V_278 ) )
return F_152 ( V_14 -> V_278 ) ;
V_268 = F_162 ( V_112 , V_279 , 0 ) ;
if ( V_268 == NULL ) {
F_158 ( V_113 , L_16 ) ;
return - V_19 ;
}
V_71 = F_150 ( V_14 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_164 ( V_113 , V_268 -> V_280 , F_32 ,
0 , F_86 ( V_113 ) , V_14 ) ;
if ( V_71 ) {
F_158 ( V_113 , L_17 , V_71 ) ;
goto V_281;
}
V_71 = F_137 ( V_14 ) ;
if ( V_71 )
goto V_281;
F_165 ( V_112 , V_14 ) ;
F_166 ( V_113 ) ;
if ( ! F_167 ( V_113 ) ) {
V_71 = F_168 ( V_14 -> clock ) ;
if ( V_71 < 0 )
goto V_282;
}
V_14 -> V_96 = F_169 ( V_113 ) ;
if ( F_146 ( V_14 -> V_96 ) ) {
V_71 = F_152 ( V_14 -> V_96 ) ;
goto V_283;
}
F_136 ( V_14 ) ;
F_170 ( V_113 , L_18 ,
V_14 -> V_5 ) ;
return 0 ;
V_283:
if ( ! F_167 ( V_113 ) )
F_171 ( V_14 -> clock ) ;
V_282:
F_142 ( V_14 ) ;
V_281:
F_145 ( V_14 ) ;
return V_71 ;
}
static int F_172 ( struct V_264 * V_113 )
{
struct V_13 * V_14 = F_173 ( V_113 ) ;
F_168 ( V_14 -> clock ) ;
return 0 ;
}
static int F_174 ( struct V_264 * V_113 )
{
struct V_13 * V_14 = F_173 ( V_113 ) ;
F_171 ( V_14 -> clock ) ;
return 0 ;
}
static int F_175 ( struct V_264 * V_113 )
{
struct V_13 * V_14 = F_173 ( V_113 ) ;
struct V_29 * V_30 ;
unsigned long V_11 ;
int V_8 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_284 , & V_14 -> V_32 ) ||
! F_28 ( V_111 , & V_14 -> V_32 ) ) {
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
F_21 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_37 , & V_14 -> V_32 ) )
return 0 ;
F_124 ( & V_14 -> V_43 ) ;
F_22 ( & V_14 -> V_44 , V_117 ,
& V_14 -> V_44 . V_99 . V_107 , false ) ;
F_3 ( V_14 , F_38 ( & V_14 -> V_58 ) == V_212 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_102 ; V_8 ++ ) {
if ( F_16 ( & V_14 -> V_39 ) )
break;
V_30 = F_17 ( V_14 ) ;
F_53 ( & V_30 -> V_40 . V_41 ) ;
}
return 0 ;
}
static int F_176 ( struct V_264 * V_113 )
{
struct V_13 * V_14 = F_173 ( V_113 ) ;
bool V_28 = F_28 ( V_111 , & V_14 -> V_32 ) ;
int V_71 ;
if ( F_44 ( V_284 , & V_14 -> V_32 ) )
return 0 ;
V_71 = F_23 ( V_14 , V_28 ) ;
if ( V_71 < 0 || ! F_24 ( V_14 ) )
return V_71 ;
return F_22 ( & V_14 -> V_44 , V_119 ) ;
}
static int F_177 ( struct V_262 * V_112 )
{
struct V_13 * V_14 = F_178 ( V_112 ) ;
struct V_264 * V_113 = & V_112 -> V_113 ;
F_179 ( V_113 ) ;
F_180 ( V_113 ) ;
F_142 ( V_14 ) ;
F_181 ( V_14 -> V_96 ) ;
F_145 ( V_14 ) ;
F_182 ( V_113 , L_19 ) ;
return 0 ;
}
