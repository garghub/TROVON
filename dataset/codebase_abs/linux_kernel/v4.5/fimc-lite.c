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
V_51 -> V_40 . V_41 . V_62 = F_41 () ;
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
static int F_47 ( struct V_67 * V_73 ,
unsigned int * V_74 , unsigned int * V_75 ,
unsigned int V_76 [] , void * V_77 [] )
{
struct V_13 * V_14 = V_73 -> V_70 ;
struct V_78 * V_79 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_79 -> V_6 ;
unsigned long V_80 = V_79 -> V_81 * V_79 -> V_82 ;
int V_8 ;
if ( V_6 == NULL )
return - V_22 ;
if ( * V_75 ) {
if ( * V_75 != V_6 -> V_83 )
return - V_22 ;
for ( V_8 = 0 ; V_8 < * V_75 ; V_8 ++ ) {
if ( V_76 [ V_8 ] < ( V_80 * V_6 -> V_84 [ V_8 ] ) / 8 )
return - V_22 ;
V_77 [ V_8 ] = V_14 -> V_85 ;
}
return 0 ;
}
* V_75 = V_6 -> V_83 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_83 ; V_8 ++ ) {
V_76 [ V_8 ] = ( V_80 * V_6 -> V_84 [ V_8 ] ) / 8 ;
V_77 [ V_8 ] = V_14 -> V_85 ;
}
return 0 ;
}
static int F_48 ( struct V_86 * V_40 )
{
struct V_67 * V_73 = V_40 -> V_67 ;
struct V_13 * V_14 = V_73 -> V_70 ;
int V_8 ;
if ( V_14 -> V_21 . V_6 == NULL )
return - V_22 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_21 . V_6 -> V_83 ; V_8 ++ ) {
unsigned long V_87 = V_14 -> V_88 [ V_8 ] ;
if ( F_49 ( V_40 , V_8 ) < V_87 ) {
F_50 ( & V_14 -> V_44 . V_89 ,
L_1 ,
F_49 ( V_40 , V_8 ) , V_87 ) ;
return - V_22 ;
}
F_51 ( V_40 , V_8 , V_87 ) ;
}
return 0 ;
}
static void F_52 ( struct V_86 * V_40 )
{
struct V_90 * V_51 = F_53 ( V_40 ) ;
struct V_29 * V_30
= F_54 ( V_51 , struct V_29 , V_40 ) ;
struct V_13 * V_14 = F_55 ( V_40 -> V_67 ) ;
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_30 -> V_91 = F_56 ( V_40 , 0 ) ;
V_30 -> V_5 = V_14 -> V_72 ++ ;
if ( V_14 -> V_72 >= V_14 -> V_92 )
V_14 -> V_72 = 0 ;
if ( ! F_28 ( V_37 , & V_14 -> V_32 ) &&
! F_28 ( V_36 , & V_14 -> V_32 ) &&
F_16 ( & V_14 -> V_43 ) ) {
F_39 ( V_14 , V_30 ) ;
F_40 ( V_14 , V_30 ) ;
} else {
F_20 ( V_14 , V_30 ) ;
}
if ( F_57 ( & V_14 -> V_93 ) &&
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
static void F_58 ( struct V_13 * V_14 )
{
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
memset ( & V_14 -> V_55 , 0 , sizeof( V_14 -> V_55 ) ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
static int F_59 ( struct V_94 * V_94 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_95 * V_96 = & V_14 -> V_44 . V_89 . V_97 ;
int V_71 ;
F_61 ( & V_14 -> V_98 ) ;
if ( F_38 ( & V_14 -> V_58 ) != V_59 ) {
V_71 = - V_99 ;
goto V_100;
}
F_25 ( V_101 , & V_14 -> V_32 ) ;
V_71 = F_62 ( & V_14 -> V_102 -> V_103 ) ;
if ( V_71 < 0 )
goto V_100;
V_71 = F_63 ( V_94 ) ;
if ( V_71 < 0 )
goto V_104;
if ( ! F_64 ( V_94 ) ||
F_38 ( & V_14 -> V_58 ) != V_59 )
goto V_100;
F_61 ( & V_96 -> V_105 . V_106 -> V_107 ) ;
V_71 = F_22 ( & V_14 -> V_44 , V_108 , V_96 , true ) ;
if ( V_71 == 0 )
V_96 -> V_109 ++ ;
F_65 ( & V_96 -> V_105 . V_106 -> V_107 ) ;
if ( ! V_71 ) {
F_58 ( V_14 ) ;
goto V_100;
}
F_66 ( V_94 ) ;
V_104:
F_67 ( & V_14 -> V_102 -> V_103 ) ;
F_31 ( V_101 , & V_14 -> V_32 ) ;
V_100:
F_65 ( & V_14 -> V_98 ) ;
return V_71 ;
}
static int F_68 ( struct V_94 * V_94 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_95 * V_97 = & V_14 -> V_44 . V_89 . V_97 ;
F_61 ( & V_14 -> V_98 ) ;
if ( F_64 ( V_94 ) &&
F_38 ( & V_14 -> V_58 ) == V_59 ) {
if ( V_14 -> V_31 ) {
F_69 ( V_97 ) ;
V_14 -> V_31 = false ;
}
F_23 ( V_14 , false ) ;
F_22 ( & V_14 -> V_44 , V_110 ) ;
F_31 ( V_101 , & V_14 -> V_32 ) ;
F_61 ( & V_97 -> V_105 . V_106 -> V_107 ) ;
V_97 -> V_109 -- ;
F_65 ( & V_97 -> V_105 . V_106 -> V_107 ) ;
}
F_70 ( V_94 , NULL ) ;
F_71 ( & V_14 -> V_102 -> V_103 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
F_65 ( & V_14 -> V_98 ) ;
return 0 ;
}
static const struct V_1 * F_72 ( struct V_13 * V_14 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_115 * V_116 = V_14 -> V_116 ;
struct V_117 * V_118 = & V_114 -> V_114 ;
const struct V_1 * V_6 = NULL ;
if ( V_114 -> V_119 == V_120 ) {
F_73 ( & V_118 -> V_121 , 8 , V_116 -> V_122 ,
F_74 ( V_116 -> V_123 ) - 1 ,
& V_118 -> V_124 , 0 , V_116 -> V_125 , 0 , 0 ) ;
V_6 = F_1 ( NULL , & V_118 -> V_126 , 0 , 0 ) ;
if ( F_75 ( ! V_6 ) )
return NULL ;
V_118 -> V_127 = V_6 -> V_127 ;
V_118 -> V_126 = V_6 -> V_3 ;
} else {
struct V_78 * V_128 = & V_14 -> V_20 ;
struct V_117 * V_129 ;
struct V_130 * V_131 ;
if ( V_114 -> V_132 == V_133 ) {
V_129 = F_76 ( & V_14 -> V_134 , V_112 ,
V_120 ) ;
V_118 -> V_126 = V_129 -> V_126 ;
V_118 -> V_127 = V_129 -> V_127 ;
V_131 = F_77 ( & V_14 -> V_134 , V_112 ,
V_120 ) ;
} else {
V_118 -> V_126 = V_128 -> V_6 -> V_3 ;
V_118 -> V_127 = V_128 -> V_6 -> V_127 ;
V_131 = & V_128 -> V_131 ;
}
V_118 -> V_121 = V_131 -> V_121 ;
V_118 -> V_124 = V_131 -> V_124 ;
}
V_118 -> V_135 = V_136 ;
F_78 ( 1 , V_26 , & V_14 -> V_134 , L_2 ,
V_118 -> V_126 , V_118 -> V_127 , V_118 -> V_121 , V_118 -> V_124 ) ;
return V_6 ;
}
static void F_79 ( struct V_13 * V_14 , struct V_130 * V_137 )
{
struct V_78 * V_79 = & V_14 -> V_20 ;
F_73 ( & V_137 -> V_121 , 0 , V_79 -> V_81 , 0 ,
& V_137 -> V_124 , 0 , V_79 -> V_82 , 0 , 0 ) ;
V_137 -> V_138 = F_80 ( T_1 , V_137 -> V_138 , 0 , V_79 -> V_81 - V_137 -> V_121 ) ;
V_137 -> V_138 = F_81 ( V_137 -> V_138 , V_14 -> V_116 -> V_139 ) ;
V_137 -> V_140 = F_80 ( T_1 , V_137 -> V_140 , 0 , V_79 -> V_82 - V_137 -> V_124 ) ;
F_78 ( 1 , V_26 , & V_14 -> V_134 , L_3 ,
V_137 -> V_138 , V_137 -> V_140 , V_137 -> V_121 , V_137 -> V_124 ,
V_79 -> V_81 , V_79 -> V_82 ) ;
}
static void F_82 ( struct V_13 * V_14 , struct V_130 * V_137 )
{
struct V_78 * V_79 = & V_14 -> V_21 ;
struct V_130 * V_141 = & V_14 -> V_20 . V_131 ;
V_137 -> V_121 = V_141 -> V_121 ;
V_137 -> V_124 = V_141 -> V_124 ;
V_137 -> V_138 = F_80 ( T_1 , V_137 -> V_138 , 0 , V_79 -> V_81 - V_137 -> V_121 ) ;
V_137 -> V_138 = F_81 ( V_137 -> V_138 , V_14 -> V_116 -> V_142 ) ;
V_137 -> V_140 = F_80 ( T_1 , V_137 -> V_140 , 0 , V_14 -> V_21 . V_82 - V_137 -> V_124 ) ;
F_78 ( 1 , V_26 , & V_14 -> V_134 , L_4 ,
V_137 -> V_138 , V_137 -> V_140 , V_137 -> V_121 , V_137 -> V_124 ,
V_79 -> V_81 , V_79 -> V_82 ) ;
}
static int F_83 ( struct V_94 * V_94 , void * V_50 ,
struct V_143 * V_144 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
F_84 ( V_144 -> V_145 , V_146 , sizeof( V_144 -> V_145 ) ) ;
F_84 ( V_144 -> V_147 , V_146 , sizeof( V_144 -> V_147 ) ) ;
snprintf ( V_144 -> V_148 , sizeof( V_144 -> V_148 ) , L_5 ,
F_85 ( & V_14 -> V_102 -> V_103 ) ) ;
V_144 -> V_149 = V_150 ;
V_144 -> V_151 = V_144 -> V_149 | V_152 ;
return 0 ;
}
static int F_86 ( struct V_94 * V_94 , void * V_50 ,
struct V_153 * V_154 )
{
const struct V_1 * V_6 ;
if ( V_154 -> V_5 >= F_2 ( V_10 ) )
return - V_22 ;
V_6 = & V_10 [ V_154 -> V_5 ] ;
F_84 ( V_154 -> V_155 , V_6 -> V_156 , sizeof( V_154 -> V_155 ) ) ;
V_154 -> V_2 = V_6 -> V_12 ;
return 0 ;
}
static int F_87 ( struct V_94 * V_94 , void * V_157 ,
struct V_158 * V_154 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_159 * V_160 = & V_154 -> V_6 . V_161 ;
struct V_162 * V_163 = & V_160 -> V_163 [ 0 ] ;
struct V_78 * V_79 = & V_14 -> V_21 ;
const struct V_1 * V_6 = V_79 -> V_6 ;
V_163 -> V_164 = ( V_79 -> V_81 * V_6 -> V_84 [ 0 ] ) / 8 ;
V_163 -> V_165 = V_163 -> V_164 * V_79 -> V_82 ;
V_160 -> V_75 = V_6 -> V_83 ;
V_160 -> V_2 = V_6 -> V_12 ;
V_160 -> V_121 = V_79 -> V_81 ;
V_160 -> V_124 = V_79 -> V_82 ;
V_160 -> V_135 = V_136 ;
V_160 -> V_127 = V_6 -> V_127 ;
return 0 ;
}
static int F_88 ( struct V_13 * V_14 ,
struct V_159 * V_160 ,
const struct V_1 * * V_166 )
{
T_1 V_167 = V_160 -> V_163 [ 0 ] . V_164 ;
struct V_115 * V_116 = V_14 -> V_116 ;
const struct V_1 * V_168 = V_14 -> V_20 . V_6 ;
const struct V_1 * V_6 ;
if ( F_75 ( V_168 == NULL ) )
return - V_22 ;
if ( V_168 -> V_11 & V_169 )
V_6 = F_1 ( & V_160 -> V_2 , NULL ,
V_168 -> V_11 , 0 ) ;
else
V_6 = V_168 ;
if ( F_75 ( V_6 == NULL ) )
return - V_22 ;
if ( V_166 )
* V_166 = V_6 ;
F_73 ( & V_160 -> V_121 , 8 , V_116 -> V_122 ,
F_74 ( V_116 -> V_123 ) - 1 ,
& V_160 -> V_124 , 0 , V_116 -> V_125 , 0 , 0 ) ;
if ( ( V_167 == 0 || ( ( V_167 * 8 ) / V_6 -> V_84 [ 0 ] ) < V_160 -> V_121 ) )
V_160 -> V_163 [ 0 ] . V_164 = ( V_160 -> V_121 *
V_6 -> V_84 [ 0 ] ) / 8 ;
if ( V_160 -> V_163 [ 0 ] . V_165 == 0 )
V_160 -> V_163 [ 0 ] . V_165 = ( V_160 -> V_121 * V_160 -> V_124 *
V_6 -> V_84 [ 0 ] ) / 8 ;
V_160 -> V_75 = V_6 -> V_83 ;
V_160 -> V_2 = V_6 -> V_12 ;
V_160 -> V_127 = V_6 -> V_127 ;
V_160 -> V_135 = V_136 ;
return 0 ;
}
static int F_89 ( struct V_94 * V_94 , void * V_157 ,
struct V_158 * V_154 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
return F_88 ( V_14 , & V_154 -> V_6 . V_161 , NULL ) ;
}
static int F_90 ( struct V_94 * V_94 , void * V_50 ,
struct V_158 * V_154 )
{
struct V_159 * V_160 = & V_154 -> V_6 . V_161 ;
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_78 * V_79 = & V_14 -> V_21 ;
const struct V_1 * V_6 = NULL ;
int V_71 ;
if ( F_91 ( & V_14 -> V_93 ) )
return - V_99 ;
V_71 = F_88 ( V_14 , & V_154 -> V_6 . V_161 , & V_6 ) ;
if ( V_71 < 0 )
return V_71 ;
V_79 -> V_6 = V_6 ;
V_14 -> V_88 [ 0 ] = F_92 ( ( V_160 -> V_121 * V_160 -> V_124 * V_6 -> V_84 [ 0 ] ) / 8 ,
V_160 -> V_163 [ 0 ] . V_165 ) ;
V_79 -> V_81 = V_160 -> V_121 ;
V_79 -> V_82 = V_160 -> V_124 ;
return 0 ;
}
static int F_93 ( struct V_13 * V_14 )
{
struct V_170 * V_171 = & V_14 -> V_134 ;
struct V_113 V_129 , V_172 ;
struct V_173 * V_119 ;
int V_71 ;
while ( 1 ) {
V_119 = & V_171 -> V_97 . V_174 [ 0 ] ;
if ( ! ( V_119 -> V_11 & V_175 ) )
break;
if ( V_171 == & V_14 -> V_134 ) {
struct V_78 * V_176 = & V_14 -> V_21 ;
V_129 . V_114 . V_121 = V_176 -> V_81 ;
V_129 . V_114 . V_124 = V_176 -> V_82 ;
V_129 . V_114 . V_126 = V_14 -> V_20 . V_6 -> V_3 ;
} else {
V_129 . V_119 = V_119 -> V_5 ;
V_129 . V_132 = V_177 ;
V_71 = F_94 ( V_171 , V_119 , V_178 , NULL ,
& V_129 ) ;
if ( V_71 < 0 && V_71 != - V_179 )
return - V_180 ;
}
V_119 = F_95 ( V_119 ) ;
if ( ! V_119 || ! F_96 ( V_119 -> V_97 ) )
break;
V_171 = F_97 ( V_119 -> V_97 ) ;
V_172 . V_119 = V_119 -> V_5 ;
V_172 . V_132 = V_177 ;
V_71 = F_94 ( V_171 , V_119 , V_178 , NULL , & V_172 ) ;
if ( V_71 < 0 && V_71 != - V_179 )
return - V_180 ;
if ( V_172 . V_114 . V_121 != V_129 . V_114 . V_121 ||
V_172 . V_114 . V_124 != V_129 . V_114 . V_124 ||
V_172 . V_114 . V_126 != V_129 . V_114 . V_126 )
return - V_180 ;
}
return 0 ;
}
static int F_98 ( struct V_94 * V_94 , void * V_50 ,
enum V_181 type )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_95 * V_97 = & V_14 -> V_44 . V_89 . V_97 ;
int V_71 ;
if ( F_24 ( V_14 ) )
return - V_99 ;
V_71 = F_99 ( V_97 , & V_14 -> V_44 . V_182 -> V_183 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_93 ( V_14 ) ;
if ( V_71 < 0 )
goto V_184;
V_14 -> V_18 = F_100 ( & V_14 -> V_134 . V_97 ) ;
V_71 = F_101 ( V_94 , V_50 , type ) ;
if ( ! V_71 ) {
V_14 -> V_31 = true ;
return V_71 ;
}
V_184:
F_69 ( V_97 ) ;
return 0 ;
}
static int F_102 ( struct V_94 * V_94 , void * V_50 ,
enum V_181 type )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
int V_71 ;
V_71 = F_103 ( V_94 , V_50 , type ) ;
if ( V_71 < 0 )
return V_71 ;
F_69 ( & V_14 -> V_44 . V_89 . V_97 ) ;
V_14 -> V_31 = false ;
return 0 ;
}
static int F_104 ( struct V_94 * V_94 , void * V_50 ,
struct V_185 * V_186 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
int V_71 ;
V_186 -> V_69 = F_105 ( T_1 , V_187 , V_186 -> V_69 ) ;
V_71 = F_106 ( V_94 , V_50 , V_186 ) ;
if ( ! V_71 )
V_14 -> V_92 = V_186 -> V_69 ;
return V_71 ;
}
static int F_107 ( struct V_130 * V_188 , struct V_130 * V_189 )
{
if ( V_188 -> V_138 < V_189 -> V_138 || V_188 -> V_140 < V_189 -> V_140 )
return 0 ;
if ( V_188 -> V_138 + V_188 -> V_121 > V_189 -> V_138 + V_189 -> V_121 )
return 0 ;
if ( V_188 -> V_140 + V_188 -> V_124 > V_189 -> V_140 + V_189 -> V_124 )
return 0 ;
return 1 ;
}
static int F_108 ( struct V_94 * V_94 , void * V_157 ,
struct V_190 * V_191 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_78 * V_154 = & V_14 -> V_21 ;
if ( V_191 -> type != V_192 )
return - V_22 ;
switch ( V_191 -> V_193 ) {
case V_194 :
case V_195 :
V_191 -> V_137 . V_138 = 0 ;
V_191 -> V_137 . V_140 = 0 ;
V_191 -> V_137 . V_121 = V_154 -> V_81 ;
V_191 -> V_137 . V_124 = V_154 -> V_82 ;
return 0 ;
case V_196 :
V_191 -> V_137 = V_154 -> V_131 ;
return 0 ;
}
return - V_22 ;
}
static int F_109 ( struct V_94 * V_94 , void * V_157 ,
struct V_190 * V_191 )
{
struct V_13 * V_14 = F_60 ( V_94 ) ;
struct V_78 * V_154 = & V_14 -> V_21 ;
struct V_130 V_131 = V_191 -> V_137 ;
unsigned long V_11 ;
if ( V_191 -> type != V_192 ||
V_191 -> V_193 != V_196 )
return - V_22 ;
F_82 ( V_14 , & V_131 ) ;
if ( ( V_191 -> V_11 & V_197 ) &&
! F_107 ( & V_131 , & V_191 -> V_137 ) )
return - V_198 ;
if ( ( V_191 -> V_11 & V_199 ) &&
! F_107 ( & V_191 -> V_137 , & V_131 ) )
return - V_198 ;
V_191 -> V_137 = V_131 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_154 -> V_131 = V_131 ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
static int F_110 ( struct V_95 * V_97 ,
const struct V_173 * V_200 ,
const struct V_173 * V_201 , T_1 V_11 )
{
struct V_170 * V_171 = F_97 ( V_97 ) ;
struct V_13 * V_14 = F_111 ( V_171 ) ;
int V_71 = 0 ;
if ( F_75 ( V_14 == NULL ) )
return 0 ;
F_78 ( 1 , V_26 , V_171 , L_6 ,
V_27 , V_201 -> V_97 -> V_156 , V_200 -> V_97 -> V_156 ,
V_11 , V_14 -> V_202 ) ;
switch ( V_200 -> V_5 ) {
case V_120 :
if ( ! F_96 ( V_201 -> V_97 ) ) {
V_71 = - V_22 ;
break;
}
if ( V_11 & V_203 ) {
if ( V_14 -> V_202 == 0 )
V_14 -> V_202 = V_171 -> V_204 ;
else
V_71 = - V_99 ;
} else {
V_14 -> V_202 = 0 ;
V_14 -> V_18 = NULL ;
}
break;
case V_205 :
if ( ! ( V_11 & V_203 ) )
F_112 ( & V_14 -> V_58 , V_206 ) ;
else if ( F_113 ( V_201 -> V_97 ) )
F_112 ( & V_14 -> V_58 , V_59 ) ;
else
V_71 = - V_22 ;
break;
case V_207 :
if ( ! ( V_11 & V_203 ) )
F_112 ( & V_14 -> V_58 , V_206 ) ;
else if ( F_96 ( V_201 -> V_97 ) )
F_112 ( & V_14 -> V_58 , V_208 ) ;
else
V_71 = - V_22 ;
break;
default:
F_50 ( V_171 , L_7 ) ;
V_71 = - V_22 ;
}
F_114 () ;
return V_71 ;
}
static int F_115 ( struct V_170 * V_171 ,
struct V_111 * V_112 ,
struct V_209 * V_126 )
{
const struct V_1 * V_6 ;
V_6 = F_1 ( NULL , NULL , 0 , V_126 -> V_5 ) ;
if ( ! V_6 )
return - V_22 ;
V_126 -> V_126 = V_6 -> V_3 ;
return 0 ;
}
static struct V_117 * F_116 (
struct V_170 * V_171 ,
struct V_111 * V_112 , unsigned int V_119 )
{
if ( V_119 != V_120 )
V_119 = V_205 ;
return F_76 ( V_171 , V_112 , V_119 ) ;
}
static int F_117 ( struct V_170 * V_171 ,
struct V_111 * V_112 ,
struct V_113 * V_6 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
struct V_117 * V_118 = & V_6 -> V_114 ;
struct V_78 * V_154 = & V_14 -> V_20 ;
if ( V_6 -> V_132 == V_133 ) {
V_118 = F_116 ( V_171 , V_112 , V_6 -> V_119 ) ;
V_6 -> V_114 = * V_118 ;
return 0 ;
}
F_61 ( & V_14 -> V_98 ) ;
V_118 -> V_127 = V_154 -> V_6 -> V_127 ;
V_118 -> V_126 = V_154 -> V_6 -> V_3 ;
if ( V_6 -> V_119 == V_120 ) {
V_118 -> V_121 = V_154 -> V_81 ;
V_118 -> V_124 = V_154 -> V_82 ;
} else {
V_118 -> V_121 = V_154 -> V_131 . V_121 ;
V_118 -> V_124 = V_154 -> V_131 . V_124 ;
}
F_65 ( & V_14 -> V_98 ) ;
return 0 ;
}
static int F_118 ( struct V_170 * V_171 ,
struct V_111 * V_112 ,
struct V_113 * V_6 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
struct V_117 * V_118 = & V_6 -> V_114 ;
struct V_78 * V_128 = & V_14 -> V_20 ;
struct V_78 * V_210 = & V_14 -> V_21 ;
const struct V_1 * V_166 ;
F_78 ( 1 , V_26 , V_171 , L_8 ,
V_6 -> V_119 , V_118 -> V_126 , V_118 -> V_121 , V_118 -> V_124 ) ;
F_61 ( & V_14 -> V_98 ) ;
if ( ( F_38 ( & V_14 -> V_58 ) == V_208 &&
V_171 -> V_97 . V_211 > 0 ) ||
( F_38 ( & V_14 -> V_58 ) == V_59 &&
F_91 ( & V_14 -> V_93 ) ) ) {
F_65 ( & V_14 -> V_98 ) ;
return - V_99 ;
}
V_166 = F_72 ( V_14 , V_112 , V_6 ) ;
if ( V_6 -> V_132 == V_133 ) {
struct V_117 * V_172 ;
V_118 = F_116 ( V_171 , V_112 , V_6 -> V_119 ) ;
* V_118 = V_6 -> V_114 ;
if ( V_6 -> V_119 == V_120 ) {
unsigned int V_119 = V_205 ;
V_172 = F_116 ( V_171 , V_112 , V_119 ) ;
* V_172 = * V_118 ;
}
F_65 ( & V_14 -> V_98 ) ;
return 0 ;
}
if ( V_6 -> V_119 == V_120 ) {
V_128 -> V_81 = V_118 -> V_121 ;
V_128 -> V_82 = V_118 -> V_124 ;
V_128 -> V_6 = V_166 ;
V_128 -> V_131 . V_121 = V_118 -> V_121 ;
V_128 -> V_131 . V_124 = V_118 -> V_124 ;
V_128 -> V_131 . V_138 = 0 ;
V_128 -> V_131 . V_140 = 0 ;
V_210 -> V_131 = V_128 -> V_131 ;
V_210 -> V_81 = V_118 -> V_121 ;
V_210 -> V_82 = V_118 -> V_124 ;
}
F_65 ( & V_14 -> V_98 ) ;
return 0 ;
}
static int F_119 ( struct V_170 * V_171 ,
struct V_111 * V_112 ,
struct V_212 * V_191 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
struct V_78 * V_154 = & V_14 -> V_20 ;
if ( ( V_191 -> V_193 != V_213 &&
V_191 -> V_193 != V_214 ) ||
V_191 -> V_119 != V_120 )
return - V_22 ;
if ( V_191 -> V_132 == V_133 ) {
V_191 -> V_137 = * F_77 ( V_171 , V_112 , V_191 -> V_119 ) ;
return 0 ;
}
F_61 ( & V_14 -> V_98 ) ;
if ( V_191 -> V_193 == V_213 ) {
V_191 -> V_137 = V_154 -> V_131 ;
} else {
V_191 -> V_137 . V_138 = 0 ;
V_191 -> V_137 . V_140 = 0 ;
V_191 -> V_137 . V_121 = V_154 -> V_81 ;
V_191 -> V_137 . V_124 = V_154 -> V_82 ;
}
F_65 ( & V_14 -> V_98 ) ;
F_78 ( 1 , V_26 , V_171 , L_9 ,
V_27 , V_154 -> V_131 . V_138 , V_154 -> V_131 . V_140 , V_154 -> V_131 . V_121 ,
V_154 -> V_131 . V_124 , V_154 -> V_81 , V_154 -> V_82 ) ;
return 0 ;
}
static int F_120 ( struct V_170 * V_171 ,
struct V_111 * V_112 ,
struct V_212 * V_191 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
struct V_78 * V_154 = & V_14 -> V_20 ;
int V_71 = 0 ;
if ( V_191 -> V_193 != V_213 || V_191 -> V_119 != V_120 )
return - V_22 ;
F_61 ( & V_14 -> V_98 ) ;
F_79 ( V_14 , & V_191 -> V_137 ) ;
if ( V_191 -> V_132 == V_133 ) {
* F_77 ( V_171 , V_112 , V_191 -> V_119 ) = V_191 -> V_137 ;
} else {
unsigned long V_11 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
V_154 -> V_131 = V_191 -> V_137 ;
V_14 -> V_21 . V_131 = V_191 -> V_137 ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
}
F_65 ( & V_14 -> V_98 ) ;
F_78 ( 1 , V_26 , V_171 , L_9 ,
V_27 , V_154 -> V_131 . V_138 , V_154 -> V_131 . V_140 , V_154 -> V_131 . V_121 ,
V_154 -> V_131 . V_124 , V_154 -> V_81 , V_154 -> V_82 ) ;
return V_71 ;
}
static int F_121 ( struct V_170 * V_171 , int V_215 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
unsigned long V_11 ;
int V_71 ;
V_14 -> V_18 = F_100 ( & V_171 -> V_97 ) ;
if ( F_38 ( & V_14 -> V_58 ) != V_208 )
return - V_179 ;
F_61 ( & V_14 -> V_98 ) ;
if ( V_215 ) {
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
F_122 ( 200 ) ) ;
if ( V_71 == 0 )
F_50 ( V_171 , L_10 ) ;
F_31 ( V_34 , & V_14 -> V_32 ) ;
}
F_65 ( & V_14 -> V_98 ) ;
return V_71 ;
}
static int F_123 ( struct V_170 * V_171 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
F_13 ( V_14 , V_27 ) ;
return 0 ;
}
static int F_124 ( struct V_170 * V_171 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
struct V_67 * V_68 = & V_14 -> V_93 ;
struct V_216 * V_217 = & V_14 -> V_44 . V_89 ;
int V_71 ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
F_112 ( & V_14 -> V_58 , V_59 ) ;
snprintf ( V_217 -> V_156 , sizeof( V_217 -> V_156 ) , L_11 ,
V_14 -> V_5 ) ;
V_217 -> V_218 = & V_219 ;
V_217 -> V_220 = & V_221 ;
V_217 -> V_222 = V_171 -> V_222 ;
V_217 -> V_223 = - 1 ;
V_217 -> V_224 = V_225 ;
V_217 -> V_226 = V_68 ;
V_14 -> V_92 = 0 ;
F_125 ( & V_14 -> V_39 ) ;
F_125 ( & V_14 -> V_43 ) ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> type = V_192 ;
V_68 -> V_227 = V_228 | V_229 ;
V_68 -> V_230 = & V_231 ;
V_68 -> V_232 = & V_233 ;
V_68 -> V_234 = sizeof( struct V_29 ) ;
V_68 -> V_70 = V_14 ;
V_68 -> V_235 = V_236 ;
V_68 -> V_98 = & V_14 -> V_98 ;
V_71 = F_126 ( V_68 ) ;
if ( V_71 < 0 )
return V_71 ;
V_14 -> V_237 . V_11 = V_175 ;
V_71 = F_127 ( & V_217 -> V_97 , 1 , & V_14 -> V_237 ) ;
if ( V_71 < 0 )
return V_71 ;
F_128 ( V_217 , V_14 ) ;
V_14 -> V_44 . V_182 = F_4 ( V_171 ) ;
V_71 = F_129 ( V_217 , V_238 , - 1 ) ;
if ( V_71 < 0 ) {
F_130 ( & V_217 -> V_97 ) ;
V_14 -> V_44 . V_182 = NULL ;
return V_71 ;
}
F_131 ( V_171 -> V_222 , L_12 ,
V_217 -> V_156 , F_132 ( V_217 ) ) ;
return 0 ;
}
static void F_133 ( struct V_170 * V_171 )
{
struct V_13 * V_14 = F_111 ( V_171 ) ;
if ( V_14 == NULL )
return;
F_61 ( & V_14 -> V_98 ) ;
if ( F_134 ( & V_14 -> V_44 . V_89 ) ) {
F_135 ( & V_14 -> V_44 . V_89 ) ;
F_130 ( & V_14 -> V_44 . V_89 . V_97 ) ;
V_14 -> V_44 . V_182 = NULL ;
}
F_65 ( & V_14 -> V_98 ) ;
}
static int F_136 ( struct V_239 * V_240 )
{
struct V_13 * V_14 = F_54 ( V_240 -> V_241 , struct V_13 ,
V_242 ) ;
F_25 ( V_48 , & V_14 -> V_32 ) ;
return 0 ;
}
static void F_137 ( struct V_13 * V_14 )
{
struct V_78 * V_128 = & V_14 -> V_20 ;
struct V_78 * V_210 = & V_14 -> V_21 ;
V_128 -> V_6 = & V_10 [ 0 ] ;
V_128 -> V_81 = V_243 ;
V_128 -> V_82 = V_244 ;
V_128 -> V_131 . V_121 = V_243 ;
V_128 -> V_131 . V_124 = V_244 ;
V_128 -> V_131 . V_138 = 0 ;
V_128 -> V_131 . V_140 = 0 ;
* V_210 = * V_128 ;
}
static int F_138 ( struct V_13 * V_14 )
{
struct V_245 * V_241 = & V_14 -> V_242 ;
struct V_170 * V_171 = & V_14 -> V_134 ;
int V_71 ;
F_139 ( V_171 , & V_246 ) ;
V_171 -> V_11 |= V_247 ;
snprintf ( V_171 -> V_156 , sizeof( V_171 -> V_156 ) , L_13 , V_14 -> V_5 ) ;
V_14 -> V_248 [ V_120 ] . V_11 = V_175 ;
V_14 -> V_248 [ V_205 ] . V_11 = V_249 ;
V_14 -> V_248 [ V_207 ] . V_11 = V_249 ;
V_71 = F_127 ( & V_171 -> V_97 , V_250 ,
V_14 -> V_248 ) ;
if ( V_71 )
return V_71 ;
F_140 ( V_241 , 1 ) ;
V_14 -> V_24 = F_141 ( V_241 , & V_251 ,
NULL ) ;
if ( V_241 -> error ) {
F_130 ( & V_171 -> V_97 ) ;
return V_241 -> error ;
}
V_171 -> V_242 = V_241 ;
V_171 -> V_252 = & V_253 ;
V_171 -> V_97 . V_230 = & V_254 ;
V_171 -> V_255 = V_256 ;
F_142 ( V_171 , V_14 ) ;
return 0 ;
}
static void F_143 ( struct V_13 * V_14 )
{
struct V_170 * V_171 = & V_14 -> V_134 ;
F_144 ( V_171 ) ;
F_130 ( & V_171 -> V_97 ) ;
F_145 ( & V_14 -> V_242 ) ;
F_142 ( V_171 , NULL ) ;
}
static void F_146 ( struct V_13 * V_14 )
{
if ( F_147 ( V_14 -> clock ) )
return;
F_148 ( V_14 -> clock ) ;
F_149 ( V_14 -> clock ) ;
V_14 -> clock = F_150 ( - V_22 ) ;
}
static int F_151 ( struct V_13 * V_14 )
{
int V_71 ;
V_14 -> clock = F_152 ( & V_14 -> V_102 -> V_103 , V_257 ) ;
if ( F_147 ( V_14 -> clock ) )
return F_153 ( V_14 -> clock ) ;
V_71 = F_154 ( V_14 -> clock ) ;
if ( V_71 < 0 ) {
F_149 ( V_14 -> clock ) ;
V_14 -> clock = F_150 ( - V_22 ) ;
}
return V_71 ;
}
static int F_155 ( struct V_258 * V_102 )
{
struct V_115 * V_259 = NULL ;
struct V_260 * V_103 = & V_102 -> V_103 ;
const struct V_261 * V_262 ;
struct V_13 * V_14 ;
struct V_263 * V_264 ;
int V_71 ;
if ( ! V_103 -> V_265 )
return - V_266 ;
V_14 = F_156 ( V_103 , sizeof( * V_14 ) , V_267 ) ;
if ( ! V_14 )
return - V_268 ;
V_262 = F_157 ( V_269 , V_103 -> V_265 ) ;
if ( V_262 )
V_259 = (struct V_115 * ) V_262 -> V_270 ;
V_14 -> V_5 = F_158 ( V_103 -> V_265 , L_14 ) ;
if ( ! V_259 || V_14 -> V_5 >= V_259 -> V_271 ||
V_14 -> V_5 < 0 ) {
F_159 ( V_103 , L_15 ,
V_103 -> V_265 -> V_272 ) ;
return - V_22 ;
}
V_14 -> V_116 = V_259 ;
V_14 -> V_102 = V_102 ;
F_160 ( & V_14 -> V_46 ) ;
F_161 ( & V_14 -> V_23 ) ;
F_162 ( & V_14 -> V_98 ) ;
V_264 = F_163 ( V_102 , V_273 , 0 ) ;
V_14 -> V_274 = F_164 ( V_103 , V_264 ) ;
if ( F_147 ( V_14 -> V_274 ) )
return F_153 ( V_14 -> V_274 ) ;
V_264 = F_163 ( V_102 , V_275 , 0 ) ;
if ( V_264 == NULL ) {
F_159 ( V_103 , L_16 ) ;
return - V_19 ;
}
V_71 = F_151 ( V_14 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_165 ( V_103 , V_264 -> V_276 , F_32 ,
0 , F_85 ( V_103 ) , V_14 ) ;
if ( V_71 ) {
F_159 ( V_103 , L_17 , V_71 ) ;
goto V_277;
}
V_71 = F_138 ( V_14 ) ;
if ( V_71 )
goto V_277;
F_166 ( V_102 , V_14 ) ;
F_167 ( V_103 ) ;
if ( ! F_168 ( V_103 ) ) {
V_71 = F_169 ( V_14 -> clock ) ;
if ( V_71 < 0 )
goto V_278;
}
V_14 -> V_85 = F_170 ( V_103 ) ;
if ( F_147 ( V_14 -> V_85 ) ) {
V_71 = F_153 ( V_14 -> V_85 ) ;
goto V_279;
}
F_137 ( V_14 ) ;
F_171 ( V_103 , L_18 ,
V_14 -> V_5 ) ;
return 0 ;
V_279:
if ( ! F_168 ( V_103 ) )
F_172 ( V_14 -> clock ) ;
V_278:
F_143 ( V_14 ) ;
V_277:
F_146 ( V_14 ) ;
return V_71 ;
}
static int F_173 ( struct V_260 * V_103 )
{
struct V_13 * V_14 = F_174 ( V_103 ) ;
F_169 ( V_14 -> clock ) ;
return 0 ;
}
static int F_175 ( struct V_260 * V_103 )
{
struct V_13 * V_14 = F_174 ( V_103 ) ;
F_172 ( V_14 -> clock ) ;
return 0 ;
}
static int F_176 ( struct V_260 * V_103 )
{
struct V_13 * V_14 = F_174 ( V_103 ) ;
struct V_29 * V_30 ;
unsigned long V_11 ;
int V_8 ;
F_5 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_280 , & V_14 -> V_32 ) ||
! F_28 ( V_101 , & V_14 -> V_32 ) ) {
F_14 ( & V_14 -> V_23 , V_11 ) ;
return 0 ;
}
F_21 ( V_14 ) ;
F_14 ( & V_14 -> V_23 , V_11 ) ;
if ( ! F_35 ( V_37 , & V_14 -> V_32 ) )
return 0 ;
F_125 ( & V_14 -> V_43 ) ;
F_22 ( & V_14 -> V_44 , V_108 ,
& V_14 -> V_44 . V_89 . V_97 , false ) ;
F_3 ( V_14 , F_38 ( & V_14 -> V_58 ) == V_208 ) ;
F_31 ( V_37 , & V_14 -> V_32 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_92 ; V_8 ++ ) {
if ( F_16 ( & V_14 -> V_39 ) )
break;
V_30 = F_17 ( V_14 ) ;
F_52 ( & V_30 -> V_40 . V_41 ) ;
}
return 0 ;
}
static int F_177 ( struct V_260 * V_103 )
{
struct V_13 * V_14 = F_174 ( V_103 ) ;
bool V_28 = F_28 ( V_101 , & V_14 -> V_32 ) ;
int V_71 ;
if ( F_44 ( V_280 , & V_14 -> V_32 ) )
return 0 ;
V_71 = F_23 ( V_14 , V_28 ) ;
if ( V_71 < 0 || ! F_24 ( V_14 ) )
return V_71 ;
return F_22 ( & V_14 -> V_44 , V_110 ) ;
}
static int F_178 ( struct V_258 * V_102 )
{
struct V_13 * V_14 = F_179 ( V_102 ) ;
struct V_260 * V_103 = & V_102 -> V_103 ;
F_180 ( V_103 ) ;
F_181 ( V_103 ) ;
F_143 ( V_14 ) ;
F_182 ( V_14 -> V_85 ) ;
F_146 ( V_14 ) ;
F_183 ( V_103 , L_19 ) ;
return 0 ;
}
