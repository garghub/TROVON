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
static int F_3 ( struct V_11 * V_12 , bool V_13 )
{
struct V_14 * V_15 = & V_12 -> V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
unsigned long V_20 ;
V_17 = V_13 ? V_12 -> V_17 : V_15 -> V_21 [ V_22 ] ;
if ( V_17 == NULL )
return - V_23 ;
if ( V_12 -> V_5 == NULL )
return - V_24 ;
V_19 = F_4 ( V_17 ) ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
F_6 ( V_12 , & V_19 -> V_26 ) ;
F_7 ( V_12 , & V_12 -> V_27 ) ;
F_8 ( V_12 , & V_12 -> V_27 ) ;
F_9 ( V_12 , & V_12 -> V_28 , ! V_13 ) ;
F_10 ( V_12 ) ;
F_11 ( V_12 , V_12 -> V_29 -> V_30 ) ;
if ( V_31 > 0 )
F_12 ( V_12 , V_32 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , bool V_33 )
{
struct V_34 * V_35 ;
unsigned long V_20 ;
bool V_36 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
V_36 = V_12 -> V_37 & ( 1 << V_38 ) ;
V_12 -> V_37 &= ~ ( 1 << V_39 | 1 << V_40 |
1 << V_41 | 1 << V_38 ) ;
if ( V_33 )
V_12 -> V_37 |= ( 1 << V_42 ) ;
else
V_12 -> V_37 &= ~ ( 1 << V_43 |
1 << V_42 ) ;
while ( ! V_33 && ! F_15 ( & V_12 -> V_44 ) ) {
V_35 = F_16 ( V_12 ) ;
F_17 ( & V_35 -> V_45 , V_46 ) ;
}
while ( ! F_15 ( & V_12 -> V_47 ) ) {
V_35 = F_18 ( V_12 ) ;
if ( V_33 )
F_19 ( V_12 , V_35 ) ;
else
F_17 ( & V_35 -> V_45 , V_46 ) ;
}
F_13 ( & V_12 -> V_25 , V_20 ) ;
F_20 ( V_12 ) ;
if ( ! V_36 )
return 0 ;
return F_21 ( V_12 , V_48 , & V_12 -> V_15 , 0 ) ;
}
static int F_22 ( struct V_11 * V_12 , bool V_33 )
{
unsigned long V_20 ;
if ( ! F_23 ( V_12 ) )
return 0 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
F_24 ( V_40 , & V_12 -> V_37 ) ;
F_25 ( V_12 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
F_26 ( V_12 -> V_49 ,
! F_27 ( V_40 , & V_12 -> V_37 ) ,
( 2 * V_50 / 10 ) ) ;
return F_14 ( V_12 , V_33 ) ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_8 ( V_12 , & V_12 -> V_27 ) ;
F_29 ( V_12 , & V_12 -> V_28 ) ;
F_11 ( V_12 , V_12 -> V_29 -> V_30 ) ;
F_30 ( V_51 , & V_12 -> V_37 ) ;
}
static T_2 F_31 ( int V_52 , void * V_53 )
{
struct V_11 * V_12 = V_53 ;
struct V_34 * V_54 ;
unsigned long V_20 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
T_1 V_59 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
V_59 = F_32 ( V_12 ) ;
F_33 ( V_12 ) ;
if ( F_34 ( V_40 , & V_12 -> V_37 ) ) {
F_35 ( & V_12 -> V_49 ) ;
goto V_60;
}
if ( V_59 & V_61 ) {
F_30 ( V_39 , & V_12 -> V_37 ) ;
V_12 -> V_62 . V_63 ++ ;
}
if ( V_59 & V_64 ) {
F_36 ( V_12 ) ;
F_30 ( V_41 , & V_12 -> V_37 ) ;
F_35 ( & V_12 -> V_49 ) ;
}
if ( F_37 ( & V_12 -> V_65 ) != V_66 )
goto V_60;
if ( ( V_59 & V_67 ) &&
F_27 ( V_39 , & V_12 -> V_37 ) &&
! F_15 ( & V_12 -> V_47 ) &&
! F_15 ( & V_12 -> V_44 ) ) {
V_54 = F_18 ( V_12 ) ;
F_38 ( & V_58 ) ;
V_56 = & V_54 -> V_45 . V_68 . V_69 ;
V_56 -> V_70 = V_58 . V_70 ;
V_56 -> V_71 = V_58 . V_72 / V_73 ;
V_54 -> V_45 . V_68 . V_74 = V_12 -> V_75 ++ ;
F_17 ( & V_54 -> V_45 , V_76 ) ;
V_54 = F_16 ( V_12 ) ;
F_39 ( V_12 , V_54 -> V_77 ) ;
F_40 ( V_12 , V_54 ) ;
}
if ( F_27 ( V_51 , & V_12 -> V_37 ) )
F_28 ( V_12 ) ;
if ( F_15 ( & V_12 -> V_44 ) ) {
F_25 ( V_12 ) ;
F_30 ( V_41 , & V_12 -> V_37 ) ;
}
V_60:
F_24 ( V_39 , & V_12 -> V_37 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
return V_78 ;
}
static int F_41 ( struct V_79 * V_80 , unsigned int V_81 )
{
struct V_11 * V_12 = V_80 -> V_82 ;
int V_83 ;
V_12 -> V_75 = 0 ;
V_83 = F_3 ( V_12 , false ) ;
if ( V_83 ) {
F_14 ( V_12 , false ) ;
return V_83 ;
}
F_24 ( V_43 , & V_12 -> V_37 ) ;
if ( ! F_15 ( & V_12 -> V_47 ) &&
! F_42 ( V_41 , & V_12 -> V_37 ) ) {
F_43 ( V_12 ) ;
if ( ! F_42 ( V_38 , & V_12 -> V_37 ) )
F_21 ( V_12 , V_48 ,
& V_12 -> V_15 , 1 ) ;
}
if ( V_31 > 0 )
F_12 ( V_12 , V_32 ) ;
return 0 ;
}
static int F_44 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_82 ;
if ( ! F_23 ( V_12 ) )
return - V_24 ;
return F_22 ( V_12 , false ) ;
}
static int F_45 ( struct V_79 * V_84 , const struct V_85 * V_86 ,
unsigned int * V_87 , unsigned int * V_88 ,
unsigned int V_89 [] , void * V_90 [] )
{
const struct V_91 * V_92 = NULL ;
struct V_11 * V_12 = V_84 -> V_82 ;
struct V_93 * V_94 = & V_12 -> V_28 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
unsigned long V_95 ;
int V_7 ;
if ( V_86 ) {
V_92 = & V_86 -> V_5 . V_96 ;
V_5 = F_1 ( & V_92 -> V_2 , NULL , - 1 ) ;
V_95 = V_92 -> V_97 * V_92 -> V_98 ;
} else {
V_95 = V_94 -> V_99 * V_94 -> V_100 ;
}
if ( V_5 == NULL )
return - V_24 ;
* V_88 = V_5 -> V_101 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_101 ; V_7 ++ ) {
unsigned int V_102 = ( V_95 * V_5 -> V_103 [ V_7 ] ) / 8 ;
if ( V_92 )
V_89 [ V_7 ] = F_46 ( V_102 , V_92 -> V_104 [ V_7 ] . V_105 ) ;
else
V_89 [ V_7 ] = V_102 ;
V_90 [ V_7 ] = V_12 -> V_106 ;
}
return 0 ;
}
static int F_47 ( struct V_107 * V_45 )
{
struct V_79 * V_84 = V_45 -> V_79 ;
struct V_11 * V_12 = V_84 -> V_82 ;
int V_7 ;
if ( V_12 -> V_5 == NULL )
return - V_24 ;
for ( V_7 = 0 ; V_7 < V_12 -> V_5 -> V_101 ; V_7 ++ ) {
unsigned long V_102 = V_12 -> V_108 [ V_7 ] ;
if ( F_48 ( V_45 , V_7 ) < V_102 ) {
F_49 ( & V_12 -> V_109 ,
L_1 ,
F_48 ( V_45 , V_7 ) , V_102 ) ;
return - V_24 ;
}
F_50 ( V_45 , V_7 , V_102 ) ;
}
return 0 ;
}
static void F_51 ( struct V_107 * V_45 )
{
struct V_34 * V_35
= F_52 ( V_45 , struct V_34 , V_45 ) ;
struct V_11 * V_12 = F_53 ( V_45 -> V_79 ) ;
unsigned long V_20 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
V_35 -> V_77 = F_54 ( V_45 , 0 ) ;
if ( ! F_27 ( V_42 , & V_12 -> V_37 ) &&
! F_27 ( V_41 , & V_12 -> V_37 ) &&
F_15 ( & V_12 -> V_47 ) ) {
F_39 ( V_12 , V_35 -> V_77 ) ;
F_40 ( V_12 , V_35 ) ;
} else {
F_19 ( V_12 , V_35 ) ;
}
if ( F_55 ( & V_12 -> V_110 ) &&
! F_15 ( & V_12 -> V_44 ) &&
! F_42 ( V_41 , & V_12 -> V_37 ) ) {
F_43 ( V_12 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
if ( ! F_42 ( V_38 , & V_12 -> V_37 ) )
F_21 ( V_12 , V_48 ,
& V_12 -> V_15 , 1 ) ;
return;
}
F_13 ( & V_12 -> V_25 , V_20 ) ;
}
static void F_56 ( struct V_79 * V_84 )
{
struct V_11 * V_12 = F_53 ( V_84 ) ;
F_57 ( & V_12 -> V_111 ) ;
}
static void F_58 ( struct V_79 * V_84 )
{
struct V_11 * V_12 = F_53 ( V_84 ) ;
F_59 ( & V_12 -> V_111 ) ;
}
static void F_60 ( struct V_11 * V_12 )
{
unsigned long V_20 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
memset ( & V_12 -> V_62 , 0 , sizeof( V_12 -> V_62 ) ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
}
static int F_61 ( struct V_112 * V_112 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_113 * V_114 = & V_12 -> V_109 . V_115 ;
int V_83 ;
F_57 ( & V_114 -> V_116 -> V_117 ) ;
F_57 ( & V_12 -> V_111 ) ;
if ( F_37 ( & V_12 -> V_65 ) != V_66 ) {
V_83 = - V_118 ;
goto V_60;
}
F_24 ( V_119 , & V_12 -> V_37 ) ;
V_83 = F_63 ( & V_12 -> V_120 -> V_121 ) ;
if ( V_83 < 0 )
goto V_60;
V_83 = F_64 ( V_112 ) ;
if ( V_83 < 0 )
goto V_60;
if ( ++ V_12 -> V_122 == 1 &&
F_37 ( & V_12 -> V_65 ) == V_66 ) {
V_83 = F_21 ( V_12 , V_123 , & V_12 -> V_15 ,
& V_12 -> V_109 . V_115 , true ) ;
if ( V_83 < 0 ) {
F_65 ( & V_12 -> V_120 -> V_121 ) ;
V_12 -> V_122 -- ;
F_66 ( V_112 ) ;
F_30 ( V_119 , & V_12 -> V_37 ) ;
}
F_60 ( V_12 ) ;
}
V_60:
F_59 ( & V_12 -> V_111 ) ;
F_59 ( & V_114 -> V_116 -> V_117 ) ;
return V_83 ;
}
static int F_67 ( struct V_112 * V_112 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
int V_83 ;
F_57 ( & V_12 -> V_111 ) ;
if ( -- V_12 -> V_122 == 0 &&
F_37 ( & V_12 -> V_65 ) == V_66 ) {
F_30 ( V_119 , & V_12 -> V_37 ) ;
F_22 ( V_12 , false ) ;
F_21 ( V_12 , V_124 , & V_12 -> V_15 ) ;
F_30 ( V_42 , & V_12 -> V_37 ) ;
}
F_68 ( & V_12 -> V_120 -> V_121 ) ;
if ( V_12 -> V_122 == 0 )
F_69 ( & V_12 -> V_110 ) ;
V_83 = F_66 ( V_112 ) ;
F_59 ( & V_12 -> V_111 ) ;
return V_83 ;
}
static unsigned int F_70 ( struct V_112 * V_112 ,
struct V_125 * V_126 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
int V_83 ;
if ( F_71 ( & V_12 -> V_111 ) )
return V_127 ;
V_83 = F_72 ( & V_12 -> V_110 , V_112 , V_126 ) ;
F_59 ( & V_12 -> V_111 ) ;
return V_83 ;
}
static int F_73 ( struct V_112 * V_112 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
int V_83 ;
if ( F_71 ( & V_12 -> V_111 ) )
return - V_130 ;
V_83 = F_74 ( & V_12 -> V_110 , V_129 ) ;
F_59 ( & V_12 -> V_111 ) ;
return V_83 ;
}
static const struct V_1 * F_75 ( struct V_11 * V_12 ,
T_1 * V_97 , T_1 * V_98 ,
T_1 * V_131 , T_1 * V_10 , int V_132 )
{
struct V_133 * V_134 = V_12 -> V_134 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( V_10 , V_131 , 0 ) ;
if ( F_76 ( ! V_5 ) )
return NULL ;
if ( V_131 )
* V_131 = V_5 -> V_3 ;
if ( V_10 )
* V_10 = V_5 -> V_10 ;
if ( V_132 == V_135 ) {
F_77 ( V_97 , 8 , V_134 -> V_136 ,
F_78 ( V_134 -> V_137 ) - 1 ,
V_98 , 0 , V_134 -> V_138 , 0 , 0 ) ;
} else {
F_77 ( V_97 , 8 , V_12 -> V_27 . V_139 . V_97 ,
F_78 ( V_134 -> V_137 ) - 1 ,
V_98 , 0 , V_12 -> V_27 . V_139 . V_98 ,
0 , 0 ) ;
}
F_79 ( 1 , V_31 , & V_12 -> V_140 , L_2 ,
V_131 ? * V_131 : 0 , * V_97 , * V_98 ) ;
return V_5 ;
}
static void F_80 ( struct V_11 * V_12 , struct V_141 * V_142 )
{
struct V_93 * V_94 = & V_12 -> V_27 ;
F_77 ( & V_142 -> V_97 , 0 , V_94 -> V_99 , 0 ,
& V_142 -> V_98 , 0 , V_94 -> V_100 , 0 , 0 ) ;
V_142 -> V_143 = F_81 ( T_1 , V_142 -> V_143 , 0 , V_94 -> V_99 - V_142 -> V_97 ) ;
V_142 -> V_143 = F_82 ( V_142 -> V_143 , V_12 -> V_134 -> V_144 ) ;
V_142 -> V_145 = F_81 ( T_1 , V_142 -> V_145 , 0 , V_94 -> V_100 - V_142 -> V_98 ) ;
F_79 ( 1 , V_31 , & V_12 -> V_140 , L_3 ,
V_142 -> V_143 , V_142 -> V_145 , V_142 -> V_97 , V_142 -> V_98 ,
V_94 -> V_99 , V_94 -> V_100 ) ;
}
static void F_83 ( struct V_11 * V_12 , struct V_141 * V_142 )
{
struct V_93 * V_94 = & V_12 -> V_28 ;
struct V_141 * V_146 = & V_12 -> V_27 . V_139 ;
V_142 -> V_97 = V_146 -> V_97 ;
V_142 -> V_98 = V_146 -> V_98 ;
V_142 -> V_143 = F_81 ( T_1 , V_142 -> V_143 , 0 , V_94 -> V_99 - V_142 -> V_97 ) ;
V_142 -> V_143 = F_82 ( V_142 -> V_143 , V_12 -> V_134 -> V_147 ) ;
V_142 -> V_145 = F_81 ( T_1 , V_142 -> V_145 , 0 , V_12 -> V_28 . V_100 - V_142 -> V_98 ) ;
F_79 ( 1 , V_31 , & V_12 -> V_140 , L_4 ,
V_142 -> V_143 , V_142 -> V_145 , V_142 -> V_97 , V_142 -> V_98 ,
V_94 -> V_99 , V_94 -> V_100 ) ;
}
static int F_84 ( struct V_112 * V_112 , void * V_53 ,
struct V_148 * V_149 )
{
F_85 ( V_149 -> V_150 , V_151 , sizeof( V_149 -> V_150 ) ) ;
V_149 -> V_152 [ 0 ] = 0 ;
V_149 -> V_153 [ 0 ] = 0 ;
V_149 -> V_154 = V_155 ;
return 0 ;
}
static int F_86 ( struct V_112 * V_112 , void * V_53 ,
struct V_156 * V_157 )
{
const struct V_1 * V_5 ;
if ( V_157 -> V_4 >= F_2 ( V_9 ) )
return - V_24 ;
V_5 = & V_9 [ V_157 -> V_4 ] ;
F_85 ( V_157 -> V_158 , V_5 -> V_159 , sizeof( V_157 -> V_158 ) ) ;
V_157 -> V_2 = V_5 -> V_10 ;
return 0 ;
}
static int F_87 ( struct V_112 * V_112 , void * V_160 ,
struct V_85 * V_157 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_91 * V_92 = & V_157 -> V_5 . V_96 ;
struct V_161 * V_104 = & V_92 -> V_104 [ 0 ] ;
struct V_93 * V_94 = & V_12 -> V_28 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
V_104 -> V_162 = ( V_94 -> V_99 * V_5 -> V_103 [ 0 ] ) / 8 ;
V_104 -> V_105 = V_104 -> V_162 * V_94 -> V_100 ;
V_92 -> V_88 = V_5 -> V_101 ;
V_92 -> V_2 = V_5 -> V_10 ;
V_92 -> V_97 = V_94 -> V_99 ;
V_92 -> V_98 = V_94 -> V_100 ;
V_92 -> V_163 = V_164 ;
V_92 -> V_165 = V_166 ;
return 0 ;
}
static int F_88 ( struct V_11 * V_12 ,
struct V_91 * V_92 ,
const struct V_1 * * V_167 )
{
struct V_133 * V_134 = V_12 -> V_134 ;
T_1 V_168 = V_92 -> V_104 [ 0 ] . V_162 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( & V_92 -> V_2 , NULL , 0 ) ;
if ( F_76 ( V_5 == NULL ) )
return - V_24 ;
if ( V_167 )
* V_167 = V_5 ;
F_77 ( & V_92 -> V_97 , 8 , V_134 -> V_136 ,
F_78 ( V_134 -> V_137 ) - 1 ,
& V_92 -> V_98 , 0 , V_134 -> V_138 , 0 , 0 ) ;
if ( ( V_168 == 0 || ( ( V_168 * 8 ) / V_5 -> V_103 [ 0 ] ) < V_92 -> V_97 ) )
V_92 -> V_104 [ 0 ] . V_162 = ( V_92 -> V_97 *
V_5 -> V_103 [ 0 ] ) / 8 ;
if ( V_92 -> V_104 [ 0 ] . V_105 == 0 )
V_92 -> V_104 [ 0 ] . V_105 = ( V_92 -> V_97 * V_92 -> V_98 *
V_5 -> V_103 [ 0 ] ) / 8 ;
V_92 -> V_88 = V_5 -> V_101 ;
V_92 -> V_2 = V_5 -> V_10 ;
V_92 -> V_165 = V_166 ;
V_92 -> V_163 = V_164 ;
return 0 ;
}
static int F_89 ( struct V_112 * V_112 , void * V_160 ,
struct V_85 * V_157 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_88 ( V_12 , & V_157 -> V_5 . V_96 , NULL ) ;
}
static int F_90 ( struct V_112 * V_112 , void * V_53 ,
struct V_85 * V_157 )
{
struct V_91 * V_92 = & V_157 -> V_5 . V_96 ;
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_93 * V_94 = & V_12 -> V_28 ;
const struct V_1 * V_5 = NULL ;
int V_83 ;
if ( F_91 ( & V_12 -> V_110 ) )
return - V_118 ;
V_83 = F_88 ( V_12 , & V_157 -> V_5 . V_96 , & V_5 ) ;
if ( V_83 < 0 )
return V_83 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_108 [ 0 ] = F_46 ( ( V_92 -> V_97 * V_92 -> V_98 * V_5 -> V_103 [ 0 ] ) / 8 ,
V_92 -> V_104 [ 0 ] . V_105 ) ;
V_94 -> V_99 = V_92 -> V_97 ;
V_94 -> V_100 = V_92 -> V_98 ;
return 0 ;
}
static int F_92 ( struct V_11 * V_12 )
{
struct V_16 * V_169 = & V_12 -> V_140 ;
struct V_170 V_171 , V_172 ;
struct V_173 * V_132 ;
int V_83 ;
while ( 1 ) {
V_132 = & V_169 -> V_115 . V_174 [ 0 ] ;
if ( ! ( V_132 -> V_20 & V_175 ) )
break;
if ( V_169 == & V_12 -> V_140 ) {
struct V_93 * V_176 = & V_12 -> V_28 ;
V_171 . V_177 . V_97 = V_176 -> V_99 ;
V_171 . V_177 . V_98 = V_176 -> V_100 ;
V_171 . V_177 . V_131 = V_12 -> V_5 -> V_3 ;
} else {
V_171 . V_132 = V_132 -> V_4 ;
V_171 . V_178 = V_179 ;
V_83 = F_93 ( V_169 , V_132 , V_180 , NULL ,
& V_171 ) ;
if ( V_83 < 0 && V_83 != - V_181 )
return - V_182 ;
}
V_132 = F_94 ( V_132 ) ;
if ( V_132 == NULL ||
F_95 ( V_132 -> V_115 ) != V_183 )
break;
V_169 = F_96 ( V_132 -> V_115 ) ;
V_172 . V_132 = V_132 -> V_4 ;
V_172 . V_178 = V_179 ;
V_83 = F_93 ( V_169 , V_132 , V_180 , NULL , & V_172 ) ;
if ( V_83 < 0 && V_83 != - V_181 )
return - V_182 ;
if ( V_172 . V_177 . V_97 != V_171 . V_177 . V_97 ||
V_172 . V_177 . V_98 != V_171 . V_177 . V_98 ||
V_172 . V_177 . V_131 != V_171 . V_177 . V_131 )
return - V_182 ;
}
return 0 ;
}
static int F_97 ( struct V_112 * V_112 , void * V_53 ,
enum V_184 type )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_16 * V_17 = V_12 -> V_15 . V_21 [ V_22 ] ;
struct V_14 * V_185 = & V_12 -> V_15 ;
int V_83 ;
if ( F_23 ( V_12 ) )
return - V_118 ;
V_83 = F_98 ( & V_17 -> V_115 , V_185 -> V_186 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_92 ( V_12 ) ;
if ( V_83 ) {
F_99 ( & V_17 -> V_115 ) ;
return V_83 ;
}
return F_100 ( & V_12 -> V_110 , type ) ;
}
static int F_101 ( struct V_112 * V_112 , void * V_53 ,
enum V_184 type )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_16 * V_169 = V_12 -> V_15 . V_21 [ V_22 ] ;
int V_83 ;
V_83 = F_102 ( & V_12 -> V_110 , type ) ;
if ( V_83 == 0 )
F_99 ( & V_169 -> V_115 ) ;
return V_83 ;
}
static int F_103 ( struct V_112 * V_112 , void * V_53 ,
struct V_187 * V_188 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
int V_83 ;
V_188 -> V_81 = F_104 ( T_1 , V_189 , V_188 -> V_81 ) ;
V_83 = F_105 ( & V_12 -> V_110 , V_188 ) ;
if ( ! V_83 )
V_12 -> V_190 = V_188 -> V_81 ;
return V_83 ;
}
static int F_106 ( struct V_112 * V_112 , void * V_53 ,
struct V_191 * V_35 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_107 ( & V_12 -> V_110 , V_35 ) ;
}
static int F_108 ( struct V_112 * V_112 , void * V_53 ,
struct V_191 * V_35 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_109 ( & V_12 -> V_110 , V_35 ) ;
}
static int F_110 ( struct V_112 * V_112 , void * V_53 ,
struct V_191 * V_35 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_111 ( & V_12 -> V_110 , V_35 , V_112 -> V_192 & V_193 ) ;
}
static int F_112 ( struct V_112 * V_112 , void * V_53 ,
struct V_194 * V_195 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_113 ( & V_12 -> V_110 , V_195 ) ;
}
static int F_114 ( struct V_112 * V_112 , void * V_53 ,
struct V_191 * V_196 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
return F_115 ( & V_12 -> V_110 , V_196 ) ;
}
static int F_116 ( struct V_141 * V_197 , struct V_141 * V_196 )
{
if ( V_197 -> V_143 < V_196 -> V_143 || V_197 -> V_145 < V_196 -> V_145 )
return 0 ;
if ( V_197 -> V_143 + V_197 -> V_97 > V_196 -> V_143 + V_196 -> V_97 )
return 0 ;
if ( V_197 -> V_145 + V_197 -> V_98 > V_196 -> V_145 + V_196 -> V_98 )
return 0 ;
return 1 ;
}
static int F_117 ( struct V_112 * V_112 , void * V_160 ,
struct V_198 * V_199 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_93 * V_157 = & V_12 -> V_28 ;
if ( V_199 -> type != V_200 )
return - V_24 ;
switch ( V_199 -> V_201 ) {
case V_202 :
case V_203 :
V_199 -> V_142 . V_143 = 0 ;
V_199 -> V_142 . V_145 = 0 ;
V_199 -> V_142 . V_97 = V_157 -> V_99 ;
V_199 -> V_142 . V_98 = V_157 -> V_100 ;
return 0 ;
case V_204 :
V_199 -> V_142 = V_157 -> V_139 ;
return 0 ;
}
return - V_24 ;
}
static int F_118 ( struct V_112 * V_112 , void * V_160 ,
struct V_198 * V_199 )
{
struct V_11 * V_12 = F_62 ( V_112 ) ;
struct V_93 * V_157 = & V_12 -> V_28 ;
struct V_141 V_139 = V_199 -> V_142 ;
unsigned long V_20 ;
if ( V_199 -> type != V_200 ||
V_199 -> V_201 != V_204 )
return - V_24 ;
F_83 ( V_12 , & V_139 ) ;
if ( ( V_199 -> V_20 & V_205 ) &&
! F_116 ( & V_139 , & V_199 -> V_142 ) )
return - V_206 ;
if ( ( V_199 -> V_20 & V_207 ) &&
! F_116 ( & V_199 -> V_142 , & V_139 ) )
return - V_206 ;
V_199 -> V_142 = V_139 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
V_157 -> V_139 = V_139 ;
F_24 ( V_51 , & V_12 -> V_37 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
return 0 ;
}
static struct V_16 * F_119 ( struct V_113 * V_114 )
{
struct V_173 * V_132 = & V_114 -> V_174 [ 0 ] ;
struct V_16 * V_169 ;
while ( V_132 -> V_20 & V_175 ) {
V_132 = F_94 ( V_132 ) ;
if ( V_132 == NULL ||
F_95 ( V_132 -> V_115 ) != V_183 )
break;
V_169 = F_96 ( V_132 -> V_115 ) ;
if ( V_169 -> V_208 == V_209 )
return V_169 ;
V_132 = & V_169 -> V_115 . V_174 [ 0 ] ;
}
return NULL ;
}
static int F_120 ( struct V_113 * V_115 ,
const struct V_173 * V_210 ,
const struct V_173 * V_211 , T_1 V_20 )
{
struct V_16 * V_169 = F_96 ( V_115 ) ;
struct V_11 * V_12 = F_121 ( V_169 ) ;
unsigned int V_212 = F_95 ( V_211 -> V_115 ) ;
int V_83 = 0 ;
if ( F_76 ( V_12 == NULL ) )
return 0 ;
F_79 ( 1 , V_31 , V_169 , L_5 ,
V_32 , V_211 -> V_115 -> V_159 , V_210 -> V_115 -> V_159 ,
V_20 , V_12 -> V_213 ) ;
F_57 ( & V_12 -> V_111 ) ;
switch ( V_210 -> V_4 ) {
case V_135 :
if ( V_212 != V_183 ) {
V_83 = - V_24 ;
break;
}
if ( V_20 & V_214 ) {
if ( V_12 -> V_213 == 0 )
V_12 -> V_213 = V_169 -> V_208 ;
else
V_83 = - V_118 ;
} else {
V_12 -> V_213 = 0 ;
V_12 -> V_17 = NULL ;
}
break;
case V_215 :
if ( ! ( V_20 & V_214 ) )
F_122 ( & V_12 -> V_65 , V_216 ) ;
else if ( V_212 == V_217 )
F_122 ( & V_12 -> V_65 , V_66 ) ;
else
V_83 = - V_24 ;
break;
case V_218 :
if ( ! ( V_20 & V_214 ) )
F_122 ( & V_12 -> V_65 , V_216 ) ;
else if ( V_212 == V_183 )
F_122 ( & V_12 -> V_65 , V_219 ) ;
else
V_83 = - V_24 ;
break;
default:
F_49 ( V_169 , L_6 ) ;
V_83 = - V_24 ;
}
F_123 () ;
F_59 ( & V_12 -> V_111 ) ;
return V_83 ;
}
static int F_124 ( struct V_16 * V_169 ,
struct V_220 * V_160 ,
struct V_221 * V_131 )
{
const struct V_1 * V_5 ;
V_5 = F_1 ( NULL , NULL , V_131 -> V_4 ) ;
if ( ! V_5 )
return - V_24 ;
V_131 -> V_131 = V_5 -> V_3 ;
return 0 ;
}
static int F_125 ( struct V_16 * V_169 ,
struct V_220 * V_160 ,
struct V_170 * V_5 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
struct V_222 * V_223 = & V_5 -> V_177 ;
struct V_93 * V_157 = & V_12 -> V_28 ;
if ( V_5 -> V_178 == V_224 ) {
V_223 = F_126 ( V_160 , V_5 -> V_132 ) ;
V_5 -> V_177 = * V_223 ;
return 0 ;
}
V_223 -> V_165 = V_166 ;
F_57 ( & V_12 -> V_111 ) ;
V_223 -> V_131 = V_12 -> V_5 -> V_3 ;
if ( V_5 -> V_132 == V_135 ) {
V_223 -> V_97 = V_157 -> V_99 ;
V_223 -> V_98 = V_157 -> V_100 ;
} else {
V_223 -> V_97 = V_157 -> V_139 . V_97 ;
V_223 -> V_98 = V_157 -> V_139 . V_98 ;
}
F_59 ( & V_12 -> V_111 ) ;
return 0 ;
}
static int F_127 ( struct V_16 * V_169 ,
struct V_220 * V_160 ,
struct V_170 * V_5 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
struct V_222 * V_223 = & V_5 -> V_177 ;
struct V_93 * V_225 = & V_12 -> V_27 ;
struct V_93 * V_226 = & V_12 -> V_28 ;
const struct V_1 * V_167 ;
F_79 ( 1 , V_31 , V_169 , L_7 ,
V_5 -> V_132 , V_223 -> V_131 , V_223 -> V_97 , V_223 -> V_98 ) ;
V_223 -> V_165 = V_166 ;
F_57 ( & V_12 -> V_111 ) ;
if ( ( F_37 ( & V_12 -> V_65 ) == V_219 &&
V_169 -> V_115 . V_227 > 0 ) ||
( F_37 ( & V_12 -> V_65 ) == V_66 &&
F_91 ( & V_12 -> V_110 ) ) ) {
F_59 ( & V_12 -> V_111 ) ;
return - V_118 ;
}
V_167 = F_75 ( V_12 , & V_223 -> V_97 , & V_223 -> V_98 ,
& V_223 -> V_131 , NULL , V_5 -> V_132 ) ;
if ( V_5 -> V_178 == V_224 ) {
V_223 = F_126 ( V_160 , V_5 -> V_132 ) ;
* V_223 = V_5 -> V_177 ;
F_59 ( & V_12 -> V_111 ) ;
return 0 ;
}
if ( V_5 -> V_132 == V_135 ) {
V_225 -> V_99 = V_223 -> V_97 ;
V_225 -> V_100 = V_223 -> V_98 ;
V_12 -> V_5 = V_167 ;
V_225 -> V_139 . V_97 = V_223 -> V_97 ;
V_225 -> V_139 . V_98 = V_223 -> V_98 ;
V_225 -> V_139 . V_143 = 0 ;
V_225 -> V_139 . V_145 = 0 ;
V_226 -> V_139 = V_225 -> V_139 ;
V_226 -> V_99 = V_223 -> V_97 ;
V_226 -> V_100 = V_223 -> V_98 ;
} else {
V_223 -> V_131 = V_12 -> V_5 -> V_3 ;
V_223 -> V_97 = V_225 -> V_139 . V_97 ;
V_223 -> V_98 = V_225 -> V_139 . V_98 ;
}
F_59 ( & V_12 -> V_111 ) ;
return 0 ;
}
static int F_128 ( struct V_16 * V_169 ,
struct V_220 * V_160 ,
struct V_228 * V_199 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
struct V_93 * V_157 = & V_12 -> V_27 ;
if ( ( V_199 -> V_201 != V_229 &&
V_199 -> V_201 != V_230 ) ||
V_199 -> V_132 != V_135 )
return - V_24 ;
if ( V_199 -> V_178 == V_224 ) {
V_199 -> V_142 = * F_129 ( V_160 , V_199 -> V_132 ) ;
return 0 ;
}
F_57 ( & V_12 -> V_111 ) ;
if ( V_199 -> V_201 == V_229 ) {
V_199 -> V_142 = V_157 -> V_139 ;
} else {
V_199 -> V_142 . V_143 = 0 ;
V_199 -> V_142 . V_145 = 0 ;
V_199 -> V_142 . V_97 = V_157 -> V_99 ;
V_199 -> V_142 . V_98 = V_157 -> V_100 ;
}
F_59 ( & V_12 -> V_111 ) ;
F_79 ( 1 , V_31 , V_169 , L_8 ,
V_32 , V_157 -> V_139 . V_143 , V_157 -> V_139 . V_145 , V_157 -> V_139 . V_97 ,
V_157 -> V_139 . V_98 , V_157 -> V_99 , V_157 -> V_100 ) ;
return 0 ;
}
static int F_130 ( struct V_16 * V_169 ,
struct V_220 * V_160 ,
struct V_228 * V_199 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
struct V_93 * V_157 = & V_12 -> V_27 ;
int V_83 = 0 ;
if ( V_199 -> V_201 != V_229 || V_199 -> V_132 != V_135 )
return - V_24 ;
F_57 ( & V_12 -> V_111 ) ;
F_80 ( V_12 , & V_199 -> V_142 ) ;
if ( V_199 -> V_178 == V_224 ) {
* F_129 ( V_160 , V_199 -> V_132 ) = V_199 -> V_142 ;
} else {
unsigned long V_20 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
V_157 -> V_139 = V_199 -> V_142 ;
V_12 -> V_28 . V_139 = V_199 -> V_142 ;
F_24 ( V_51 , & V_12 -> V_37 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
}
F_59 ( & V_12 -> V_111 ) ;
F_79 ( 1 , V_31 , V_169 , L_8 ,
V_32 , V_157 -> V_139 . V_143 , V_157 -> V_139 . V_145 , V_157 -> V_139 . V_97 ,
V_157 -> V_139 . V_98 , V_157 -> V_99 , V_157 -> V_100 ) ;
return V_83 ;
}
static int F_131 ( struct V_16 * V_169 , int V_231 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
unsigned long V_20 ;
int V_83 ;
V_12 -> V_17 = F_119 ( & V_169 -> V_115 ) ;
if ( F_37 ( & V_12 -> V_65 ) != V_219 )
return - V_181 ;
F_57 ( & V_12 -> V_111 ) ;
if ( V_231 ) {
F_20 ( V_12 ) ;
V_83 = F_3 ( V_12 , true ) ;
if ( ! V_83 ) {
F_5 ( & V_12 -> V_25 , V_20 ) ;
F_43 ( V_12 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
}
} else {
F_24 ( V_40 , & V_12 -> V_37 ) ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
F_25 ( V_12 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
V_83 = F_26 ( V_12 -> V_49 ,
! F_27 ( V_40 , & V_12 -> V_37 ) ,
F_132 ( 200 ) ) ;
if ( V_83 == 0 )
F_49 ( V_169 , L_9 ) ;
F_30 ( V_39 , & V_12 -> V_37 ) ;
}
F_59 ( & V_12 -> V_111 ) ;
return V_83 ;
}
static int F_133 ( struct V_16 * V_169 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
F_12 ( V_12 , V_32 ) ;
return 0 ;
}
static int F_134 ( struct V_16 * V_169 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
struct V_79 * V_80 = & V_12 -> V_110 ;
struct V_232 * V_109 = & V_12 -> V_109 ;
int V_83 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_12 -> V_5 = & V_9 [ 0 ] ;
F_122 ( & V_12 -> V_65 , V_66 ) ;
snprintf ( V_109 -> V_159 , sizeof( V_109 -> V_159 ) , L_10 ,
V_12 -> V_4 ) ;
V_109 -> V_233 = & V_234 ;
V_109 -> V_235 = & V_236 ;
V_109 -> V_237 = V_169 -> V_237 ;
V_109 -> V_238 = - 1 ;
V_109 -> V_239 = V_240 ;
V_109 -> V_111 = & V_12 -> V_111 ;
V_12 -> V_122 = 0 ;
V_12 -> V_190 = 0 ;
F_135 ( & V_12 -> V_44 ) ;
F_135 ( & V_12 -> V_47 ) ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
V_80 -> type = V_200 ;
V_80 -> V_241 = V_242 | V_243 ;
V_80 -> V_244 = & V_245 ;
V_80 -> V_246 = & V_247 ;
V_80 -> V_248 = sizeof( struct V_34 ) ;
V_80 -> V_82 = V_12 ;
V_83 = F_136 ( V_80 ) ;
if ( V_83 < 0 )
return V_83 ;
V_12 -> V_249 . V_20 = V_175 ;
V_83 = F_137 ( & V_109 -> V_115 , 1 , & V_12 -> V_249 , 0 ) ;
if ( V_83 < 0 )
return V_83 ;
F_138 ( V_109 , V_12 ) ;
V_12 -> V_250 = F_4 ( V_169 ) ;
V_83 = F_139 ( V_109 , V_251 , - 1 ) ;
if ( V_83 < 0 ) {
F_140 ( & V_109 -> V_115 ) ;
V_12 -> V_250 = NULL ;
return V_83 ;
}
F_141 ( V_169 -> V_237 , L_11 ,
V_109 -> V_159 , F_142 ( V_109 ) ) ;
return 0 ;
}
static void F_143 ( struct V_16 * V_169 )
{
struct V_11 * V_12 = F_121 ( V_169 ) ;
if ( V_12 == NULL )
return;
if ( F_144 ( & V_12 -> V_109 ) ) {
F_145 ( & V_12 -> V_109 ) ;
F_140 ( & V_12 -> V_109 . V_115 ) ;
V_12 -> V_250 = NULL ;
}
}
static int F_146 ( struct V_252 * V_253 )
{
struct V_11 * V_12 = F_52 ( V_253 -> V_254 , struct V_11 ,
V_255 ) ;
F_24 ( V_51 , & V_12 -> V_37 ) ;
return 0 ;
}
static int F_147 ( struct V_11 * V_12 )
{
struct V_256 * V_254 = & V_12 -> V_255 ;
struct V_16 * V_169 = & V_12 -> V_140 ;
int V_83 ;
F_148 ( V_169 , & V_257 ) ;
V_169 -> V_20 = V_258 ;
snprintf ( V_169 -> V_159 , sizeof( V_169 -> V_159 ) , L_12 , V_12 -> V_4 ) ;
V_12 -> V_259 [ V_135 ] . V_20 = V_175 ;
V_12 -> V_259 [ V_215 ] . V_20 = V_260 ;
V_12 -> V_259 [ V_218 ] . V_20 = V_260 ;
V_83 = F_137 ( & V_169 -> V_115 , V_261 ,
V_12 -> V_259 , 0 ) ;
if ( V_83 )
return V_83 ;
F_149 ( V_254 , 1 ) ;
V_12 -> V_29 = F_150 ( V_254 , & V_262 ,
NULL ) ;
if ( V_254 -> error ) {
F_140 ( & V_169 -> V_115 ) ;
return V_254 -> error ;
}
V_169 -> V_255 = V_254 ;
V_169 -> V_263 = & V_264 ;
V_169 -> V_115 . V_244 = & V_265 ;
F_151 ( V_169 , V_12 ) ;
return 0 ;
}
static void F_152 ( struct V_11 * V_12 )
{
struct V_16 * V_169 = & V_12 -> V_140 ;
F_153 ( V_169 ) ;
F_140 ( & V_169 -> V_115 ) ;
F_154 ( & V_12 -> V_255 ) ;
F_151 ( V_169 , NULL ) ;
}
static void F_155 ( struct V_11 * V_12 )
{
if ( F_156 ( V_12 -> clock ) )
return;
F_157 ( V_12 -> clock ) ;
F_158 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
static int F_159 ( struct V_11 * V_12 )
{
int V_83 ;
V_12 -> clock = F_160 ( & V_12 -> V_120 -> V_121 , V_266 ) ;
if ( F_161 ( V_12 -> clock ) )
return F_162 ( V_12 -> clock ) ;
V_83 = F_163 ( V_12 -> clock ) ;
if ( V_83 < 0 ) {
F_158 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
return V_83 ;
}
static int F_164 ( struct V_267 * V_120 )
{
struct V_268 * V_269 = F_165 ( V_120 ) ;
struct V_11 * V_12 ;
struct V_270 * V_271 ;
int V_83 ;
V_12 = F_166 ( & V_120 -> V_121 , sizeof( * V_12 ) , V_272 ) ;
if ( ! V_12 )
return - V_273 ;
V_12 -> V_4 = V_120 -> V_8 ;
V_12 -> V_134 = V_269 -> V_134 [ V_12 -> V_4 ] ;
V_12 -> V_120 = V_120 ;
F_167 ( & V_12 -> V_49 ) ;
F_168 ( & V_12 -> V_25 ) ;
F_169 ( & V_12 -> V_111 ) ;
V_271 = F_170 ( V_120 , V_274 , 0 ) ;
V_12 -> V_275 = F_171 ( & V_120 -> V_121 , V_271 ) ;
if ( F_161 ( V_12 -> V_275 ) )
return F_162 ( V_12 -> V_275 ) ;
V_271 = F_170 ( V_120 , V_276 , 0 ) ;
if ( V_271 == NULL ) {
F_172 ( & V_120 -> V_121 , L_13 ) ;
return - V_23 ;
}
V_83 = F_159 ( V_12 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_173 ( & V_120 -> V_121 , V_271 -> V_277 , F_31 ,
0 , F_174 ( & V_120 -> V_121 ) , V_12 ) ;
if ( V_83 ) {
F_172 ( & V_120 -> V_121 , L_14 , V_83 ) ;
goto V_278;
}
V_83 = F_147 ( V_12 ) ;
if ( V_83 )
goto V_278;
F_175 ( V_120 , V_12 ) ;
F_176 ( & V_120 -> V_121 ) ;
V_83 = F_63 ( & V_120 -> V_121 ) ;
if ( V_83 < 0 )
goto V_279;
V_12 -> V_106 = F_177 ( & V_120 -> V_121 ) ;
if ( F_161 ( V_12 -> V_106 ) ) {
V_83 = F_162 ( V_12 -> V_106 ) ;
goto V_280;
}
F_68 ( & V_120 -> V_121 ) ;
F_178 ( & V_120 -> V_121 , L_15 ,
V_12 -> V_4 ) ;
return 0 ;
V_280:
F_68 ( & V_120 -> V_121 ) ;
V_279:
F_152 ( V_12 ) ;
V_278:
F_155 ( V_12 ) ;
return V_83 ;
}
static int F_179 ( struct V_281 * V_121 )
{
struct V_11 * V_12 = F_180 ( V_121 ) ;
F_181 ( V_12 -> clock ) ;
return 0 ;
}
static int F_182 ( struct V_281 * V_121 )
{
struct V_11 * V_12 = F_180 ( V_121 ) ;
F_183 ( V_12 -> clock ) ;
return 0 ;
}
static int F_184 ( struct V_281 * V_121 )
{
struct V_11 * V_12 = F_180 ( V_121 ) ;
struct V_34 * V_35 ;
unsigned long V_20 ;
int V_7 ;
F_5 ( & V_12 -> V_25 , V_20 ) ;
if ( ! F_34 ( V_282 , & V_12 -> V_37 ) ||
! F_27 ( V_119 , & V_12 -> V_37 ) ) {
F_13 ( & V_12 -> V_25 , V_20 ) ;
return 0 ;
}
F_20 ( V_12 ) ;
F_13 ( & V_12 -> V_25 , V_20 ) ;
if ( ! F_34 ( V_42 , & V_12 -> V_37 ) )
return 0 ;
F_135 ( & V_12 -> V_47 ) ;
F_21 ( V_12 , V_123 , & V_12 -> V_15 ,
& V_12 -> V_109 . V_115 , false ) ;
F_3 ( V_12 , F_37 ( & V_12 -> V_65 ) == V_219 ) ;
F_30 ( V_42 , & V_12 -> V_37 ) ;
for ( V_7 = 0 ; V_7 < V_12 -> V_190 ; V_7 ++ ) {
if ( F_15 ( & V_12 -> V_44 ) )
break;
V_35 = F_16 ( V_12 ) ;
F_51 ( & V_35 -> V_45 ) ;
}
return 0 ;
}
static int F_185 ( struct V_281 * V_121 )
{
struct V_11 * V_12 = F_180 ( V_121 ) ;
bool V_33 = F_27 ( V_119 , & V_12 -> V_37 ) ;
int V_83 ;
if ( F_42 ( V_282 , & V_12 -> V_37 ) )
return 0 ;
V_83 = F_22 ( V_12 , V_33 ) ;
if ( V_83 < 0 || ! F_23 ( V_12 ) )
return V_83 ;
return F_21 ( V_12 , V_124 , & V_12 -> V_15 ) ;
}
static int F_186 ( struct V_267 * V_120 )
{
struct V_11 * V_12 = F_187 ( V_120 ) ;
struct V_281 * V_121 = & V_120 -> V_121 ;
F_188 ( V_121 ) ;
F_189 ( V_121 ) ;
F_152 ( V_12 ) ;
F_190 ( V_12 -> V_106 ) ;
F_155 ( V_12 ) ;
F_191 ( V_121 , L_16 ) ;
return 0 ;
}
