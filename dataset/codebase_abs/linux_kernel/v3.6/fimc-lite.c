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
F_6 ( V_12 , V_16 -> V_23 ) ;
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
return F_21 ( & V_12 -> V_14 , 0 ) ;
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
F_26 ( V_12 -> V_45 ,
! F_27 ( V_37 , & V_12 -> V_34 ) ,
( 2 * V_46 / 10 ) ) ;
return F_14 ( V_12 , V_30 ) ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_8 ( V_12 , & V_12 -> V_24 ) ;
F_29 ( V_12 , & V_12 -> V_25 ) ;
F_11 ( V_12 , V_12 -> V_26 -> V_27 ) ;
F_30 ( V_47 , & V_12 -> V_34 ) ;
}
static T_2 F_31 ( int V_48 , void * V_49 )
{
struct V_11 * V_12 = V_49 ;
struct V_31 * V_50 ;
unsigned long V_17 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
T_1 V_55 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_55 = F_32 ( V_12 ) ;
F_33 ( V_12 ) ;
if ( F_34 ( V_37 , & V_12 -> V_34 ) ) {
F_35 ( & V_12 -> V_45 ) ;
goto V_56;
}
if ( V_55 & V_57 ) {
F_30 ( V_36 , & V_12 -> V_34 ) ;
V_12 -> V_58 . V_59 ++ ;
}
if ( V_55 & V_60 ) {
F_36 ( V_12 ) ;
F_30 ( V_38 , & V_12 -> V_34 ) ;
F_35 ( & V_12 -> V_45 ) ;
}
if ( V_12 -> V_61 != V_62 )
goto V_56;
if ( ( V_55 & V_63 ) &&
F_27 ( V_36 , & V_12 -> V_34 ) &&
! F_15 ( & V_12 -> V_44 ) &&
! F_15 ( & V_12 -> V_41 ) ) {
V_50 = F_18 ( V_12 ) ;
F_37 ( & V_54 ) ;
V_52 = & V_50 -> V_42 . V_64 . V_65 ;
V_52 -> V_66 = V_54 . V_66 ;
V_52 -> V_67 = V_54 . V_68 / V_69 ;
V_50 -> V_42 . V_64 . V_70 = V_12 -> V_71 ++ ;
F_17 ( & V_50 -> V_42 , V_72 ) ;
V_50 = F_16 ( V_12 ) ;
F_38 ( V_12 , V_50 -> V_73 ) ;
F_39 ( V_12 , V_50 ) ;
}
if ( F_27 ( V_47 , & V_12 -> V_34 ) )
F_28 ( V_12 ) ;
if ( F_15 ( & V_12 -> V_41 ) ) {
F_25 ( V_12 ) ;
F_30 ( V_38 , & V_12 -> V_34 ) ;
}
V_56:
F_24 ( V_36 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
return V_74 ;
}
static int F_40 ( struct V_75 * V_76 , unsigned int V_77 )
{
struct V_11 * V_12 = V_76 -> V_78 ;
int V_79 ;
V_12 -> V_71 = 0 ;
V_79 = F_3 ( V_12 ) ;
if ( V_79 ) {
F_14 ( V_12 , false ) ;
return V_79 ;
}
F_24 ( V_40 , & V_12 -> V_34 ) ;
if ( ! F_15 ( & V_12 -> V_44 ) &&
! F_41 ( V_38 , & V_12 -> V_34 ) ) {
F_42 ( V_12 ) ;
if ( ! F_41 ( V_35 , & V_12 -> V_34 ) )
F_21 ( & V_12 -> V_14 , 1 ) ;
}
if ( V_28 > 0 )
F_12 ( V_12 , V_29 ) ;
return 0 ;
}
static int F_43 ( struct V_75 * V_76 )
{
struct V_11 * V_12 = V_76 -> V_78 ;
if ( ! F_23 ( V_12 ) )
return - V_21 ;
return F_22 ( V_12 , false ) ;
}
static int F_44 ( struct V_75 * V_80 , const struct V_81 * V_82 ,
unsigned int * V_83 , unsigned int * V_84 ,
unsigned int V_85 [] , void * V_86 [] )
{
const struct V_87 * V_88 = NULL ;
struct V_11 * V_12 = V_80 -> V_78 ;
struct V_89 * V_90 = & V_12 -> V_25 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
unsigned long V_91 ;
int V_7 ;
if ( V_82 ) {
V_88 = & V_82 -> V_5 . V_92 ;
V_5 = F_1 ( & V_88 -> V_2 , NULL , - 1 ) ;
V_91 = V_88 -> V_93 * V_88 -> V_94 ;
} else {
V_91 = V_90 -> V_95 * V_90 -> V_96 ;
}
if ( V_5 == NULL )
return - V_21 ;
* V_84 = V_5 -> V_97 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_97 ; V_7 ++ ) {
unsigned int V_98 = ( V_91 * V_5 -> V_99 [ V_7 ] ) / 8 ;
if ( V_88 )
V_85 [ V_7 ] = F_45 ( V_98 , V_88 -> V_100 [ V_7 ] . V_101 ) ;
else
V_85 [ V_7 ] = V_98 ;
V_86 [ V_7 ] = V_12 -> V_102 ;
}
return 0 ;
}
static int F_46 ( struct V_103 * V_42 )
{
struct V_75 * V_80 = V_42 -> V_75 ;
struct V_11 * V_12 = V_80 -> V_78 ;
int V_7 ;
if ( V_12 -> V_5 == NULL )
return - V_21 ;
for ( V_7 = 0 ; V_7 < V_12 -> V_5 -> V_97 ; V_7 ++ ) {
unsigned long V_98 = V_12 -> V_104 [ V_7 ] ;
if ( F_47 ( V_42 , V_7 ) < V_98 ) {
F_48 ( V_12 -> V_105 ,
L_1 ,
F_47 ( V_42 , V_7 ) , V_98 ) ;
return - V_21 ;
}
F_49 ( V_42 , V_7 , V_98 ) ;
}
return 0 ;
}
static void F_50 ( struct V_103 * V_42 )
{
struct V_31 * V_32
= F_51 ( V_42 , struct V_31 , V_42 ) ;
struct V_11 * V_12 = F_52 ( V_42 -> V_75 ) ;
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_32 -> V_73 = F_53 ( V_42 , 0 ) ;
if ( ! F_27 ( V_39 , & V_12 -> V_34 ) &&
! F_27 ( V_38 , & V_12 -> V_34 ) &&
F_15 ( & V_12 -> V_44 ) ) {
F_38 ( V_12 , V_32 -> V_73 ) ;
F_39 ( V_12 , V_32 ) ;
} else {
F_19 ( V_12 , V_32 ) ;
}
if ( F_54 ( & V_12 -> V_106 ) &&
! F_15 ( & V_12 -> V_41 ) &&
! F_41 ( V_38 , & V_12 -> V_34 ) ) {
F_42 ( V_12 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_41 ( V_35 , & V_12 -> V_34 ) )
F_21 ( & V_12 -> V_14 , 1 ) ;
return;
}
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
static void F_55 ( struct V_75 * V_80 )
{
struct V_11 * V_12 = F_52 ( V_80 ) ;
F_56 ( & V_12 -> V_107 ) ;
}
static void F_57 ( struct V_75 * V_80 )
{
struct V_11 * V_12 = F_52 ( V_80 ) ;
F_58 ( & V_12 -> V_107 ) ;
}
static void F_59 ( struct V_11 * V_12 )
{
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
memset ( & V_12 -> V_58 , 0 , sizeof( V_12 -> V_58 ) ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
static int F_60 ( struct V_108 * V_108 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
int V_79 ;
if ( F_62 ( & V_12 -> V_107 ) )
return - V_109 ;
F_24 ( V_110 , & V_12 -> V_34 ) ;
V_79 = F_63 ( & V_12 -> V_111 -> V_112 ) ;
if ( V_79 < 0 )
goto V_56;
V_79 = F_64 ( V_108 ) ;
if ( V_79 < 0 )
goto V_56;
if ( ++ V_12 -> V_113 == 1 && V_12 -> V_61 == V_62 ) {
V_79 = F_65 ( & V_12 -> V_14 ,
& V_12 -> V_105 -> V_114 , true ) ;
if ( V_79 < 0 ) {
F_66 ( & V_12 -> V_111 -> V_112 ) ;
V_12 -> V_113 -- ;
F_67 ( V_108 ) ;
F_30 ( V_110 , & V_12 -> V_34 ) ;
}
F_59 ( V_12 ) ;
}
V_56:
F_58 ( & V_12 -> V_107 ) ;
return V_79 ;
}
static int F_68 ( struct V_108 * V_108 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
int V_79 ;
if ( F_62 ( & V_12 -> V_107 ) )
return - V_109 ;
if ( -- V_12 -> V_113 == 0 && V_12 -> V_61 == V_62 ) {
F_30 ( V_110 , & V_12 -> V_34 ) ;
F_22 ( V_12 , false ) ;
F_69 ( & V_12 -> V_14 ) ;
F_30 ( V_39 , & V_12 -> V_34 ) ;
}
F_70 ( & V_12 -> V_111 -> V_112 ) ;
if ( V_12 -> V_113 == 0 )
F_71 ( & V_12 -> V_106 ) ;
V_79 = F_67 ( V_108 ) ;
F_58 ( & V_12 -> V_107 ) ;
return V_79 ;
}
static unsigned int F_72 ( struct V_108 * V_108 ,
struct V_115 * V_116 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
int V_79 ;
if ( F_62 ( & V_12 -> V_107 ) )
return V_117 ;
V_79 = F_73 ( & V_12 -> V_106 , V_108 , V_116 ) ;
F_58 ( & V_12 -> V_107 ) ;
return V_79 ;
}
static int F_74 ( struct V_108 * V_108 , struct V_118 * V_119 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
int V_79 ;
if ( F_62 ( & V_12 -> V_107 ) )
return - V_109 ;
V_79 = F_75 ( & V_12 -> V_106 , V_119 ) ;
F_58 ( & V_12 -> V_107 ) ;
return V_79 ;
}
static const struct V_1 * F_76 ( struct V_11 * V_12 ,
T_1 * V_93 , T_1 * V_94 ,
T_1 * V_120 , T_1 * V_10 , int V_121 )
{
struct V_122 * V_123 = V_12 -> V_123 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( V_10 , V_120 , 0 ) ;
if ( F_77 ( ! V_5 ) )
return NULL ;
if ( V_120 )
* V_120 = V_5 -> V_3 ;
if ( V_10 )
* V_10 = V_5 -> V_10 ;
if ( V_121 == V_124 ) {
F_78 ( V_93 , 8 , V_123 -> V_125 ,
F_79 ( V_123 -> V_126 ) - 1 ,
V_94 , 0 , V_123 -> V_127 , 0 , 0 ) ;
} else {
F_78 ( V_93 , 8 , V_12 -> V_24 . V_128 . V_93 ,
F_79 ( V_123 -> V_126 ) - 1 ,
V_94 , 0 , V_12 -> V_24 . V_128 . V_94 ,
0 , 0 ) ;
}
F_80 ( 1 , V_28 , & V_12 -> V_129 , L_2 ,
V_120 ? * V_120 : 0 , * V_93 , * V_94 ) ;
return V_5 ;
}
static void F_81 ( struct V_11 * V_12 , struct V_130 * V_131 )
{
struct V_89 * V_90 = & V_12 -> V_24 ;
F_78 ( & V_131 -> V_93 , 0 , V_90 -> V_95 , 0 ,
& V_131 -> V_94 , 0 , V_90 -> V_96 , 0 , 0 ) ;
V_131 -> V_132 = F_82 ( T_1 , V_131 -> V_132 , 0 , V_90 -> V_95 - V_131 -> V_93 ) ;
V_131 -> V_132 = F_83 ( V_131 -> V_132 , V_12 -> V_123 -> V_133 ) ;
V_131 -> V_134 = F_82 ( T_1 , V_131 -> V_134 , 0 , V_90 -> V_96 - V_131 -> V_94 ) ;
F_80 ( 1 , V_28 , & V_12 -> V_129 , L_3 ,
V_131 -> V_132 , V_131 -> V_134 , V_131 -> V_93 , V_131 -> V_94 ,
V_90 -> V_95 , V_90 -> V_96 ) ;
}
static void F_84 ( struct V_11 * V_12 , struct V_130 * V_131 )
{
struct V_89 * V_90 = & V_12 -> V_25 ;
struct V_130 * V_135 = & V_12 -> V_24 . V_128 ;
V_131 -> V_93 = V_135 -> V_93 ;
V_131 -> V_94 = V_135 -> V_94 ;
V_131 -> V_132 = F_82 ( T_1 , V_131 -> V_132 , 0 , V_90 -> V_95 - V_131 -> V_93 ) ;
V_131 -> V_132 = F_83 ( V_131 -> V_132 , V_12 -> V_123 -> V_136 ) ;
V_131 -> V_134 = F_82 ( T_1 , V_131 -> V_134 , 0 , V_12 -> V_25 . V_96 - V_131 -> V_94 ) ;
F_80 ( 1 , V_28 , & V_12 -> V_129 , L_4 ,
V_131 -> V_132 , V_131 -> V_134 , V_131 -> V_93 , V_131 -> V_94 ,
V_90 -> V_95 , V_90 -> V_96 ) ;
}
static int F_85 ( struct V_108 * V_108 , void * V_49 ,
struct V_137 * V_138 )
{
F_86 ( V_138 -> V_139 , V_140 , sizeof( V_138 -> V_139 ) ) ;
V_138 -> V_141 [ 0 ] = 0 ;
V_138 -> V_142 [ 0 ] = 0 ;
V_138 -> V_143 = V_144 ;
return 0 ;
}
static int F_87 ( struct V_108 * V_108 , void * V_49 ,
struct V_145 * V_146 )
{
const struct V_1 * V_5 ;
if ( V_146 -> V_4 >= F_2 ( V_9 ) )
return - V_21 ;
V_5 = & V_9 [ V_146 -> V_4 ] ;
F_86 ( V_146 -> V_147 , V_5 -> V_148 , sizeof( V_146 -> V_147 ) ) ;
V_146 -> V_2 = V_5 -> V_10 ;
return 0 ;
}
static int F_88 ( struct V_108 * V_108 , void * V_149 ,
struct V_81 * V_146 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_87 * V_88 = & V_146 -> V_5 . V_92 ;
struct V_150 * V_100 = & V_88 -> V_100 [ 0 ] ;
struct V_89 * V_90 = & V_12 -> V_25 ;
const struct V_1 * V_5 = V_12 -> V_5 ;
V_100 -> V_151 = ( V_90 -> V_95 * V_5 -> V_99 [ 0 ] ) / 8 ;
V_100 -> V_101 = V_100 -> V_151 * V_90 -> V_96 ;
V_88 -> V_84 = V_5 -> V_97 ;
V_88 -> V_2 = V_5 -> V_10 ;
V_88 -> V_93 = V_90 -> V_95 ;
V_88 -> V_94 = V_90 -> V_96 ;
V_88 -> V_152 = V_153 ;
V_88 -> V_154 = V_155 ;
return 0 ;
}
static int F_89 ( struct V_11 * V_12 ,
struct V_87 * V_88 ,
const struct V_1 * * V_156 )
{
struct V_122 * V_123 = V_12 -> V_123 ;
T_1 V_157 = V_88 -> V_100 [ 0 ] . V_151 ;
const struct V_1 * V_5 ;
V_5 = F_1 ( & V_88 -> V_2 , NULL , 0 ) ;
if ( F_77 ( V_5 == NULL ) )
return - V_21 ;
if ( V_156 )
* V_156 = V_5 ;
F_78 ( & V_88 -> V_93 , 8 , V_123 -> V_125 ,
F_79 ( V_123 -> V_126 ) - 1 ,
& V_88 -> V_94 , 0 , V_123 -> V_127 , 0 , 0 ) ;
if ( ( V_157 == 0 || ( ( V_157 * 8 ) / V_5 -> V_99 [ 0 ] ) < V_88 -> V_93 ) )
V_88 -> V_100 [ 0 ] . V_151 = ( V_88 -> V_93 *
V_5 -> V_99 [ 0 ] ) / 8 ;
if ( V_88 -> V_100 [ 0 ] . V_101 == 0 )
V_88 -> V_100 [ 0 ] . V_101 = ( V_88 -> V_93 * V_88 -> V_94 *
V_5 -> V_99 [ 0 ] ) / 8 ;
V_88 -> V_84 = V_5 -> V_97 ;
V_88 -> V_2 = V_5 -> V_10 ;
V_88 -> V_154 = V_155 ;
V_88 -> V_152 = V_153 ;
return 0 ;
}
static int F_90 ( struct V_108 * V_108 , void * V_149 ,
struct V_81 * V_146 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_89 ( V_12 , & V_146 -> V_5 . V_92 , NULL ) ;
}
static int F_91 ( struct V_108 * V_108 , void * V_49 ,
struct V_81 * V_146 )
{
struct V_87 * V_88 = & V_146 -> V_5 . V_92 ;
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_89 * V_90 = & V_12 -> V_25 ;
const struct V_1 * V_5 = NULL ;
int V_79 ;
if ( F_92 ( & V_12 -> V_106 ) )
return - V_158 ;
V_79 = F_89 ( V_12 , & V_146 -> V_5 . V_92 , & V_5 ) ;
if ( V_79 < 0 )
return V_79 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_104 [ 0 ] = F_45 ( ( V_88 -> V_93 * V_88 -> V_94 * V_5 -> V_99 [ 0 ] ) / 8 ,
V_88 -> V_100 [ 0 ] . V_101 ) ;
V_90 -> V_95 = V_88 -> V_93 ;
V_90 -> V_96 = V_88 -> V_94 ;
return 0 ;
}
static int F_93 ( struct V_11 * V_12 )
{
struct V_159 * V_160 = & V_12 -> V_129 ;
struct V_161 V_162 , V_163 ;
struct V_164 * V_121 ;
int V_79 ;
while ( 1 ) {
V_121 = & V_160 -> V_114 . V_165 [ 0 ] ;
if ( ! ( V_121 -> V_17 & V_166 ) )
break;
if ( V_160 == & V_12 -> V_129 ) {
struct V_89 * V_167 = & V_12 -> V_25 ;
V_162 . V_168 . V_93 = V_167 -> V_95 ;
V_162 . V_168 . V_94 = V_167 -> V_96 ;
V_162 . V_168 . V_120 = V_12 -> V_5 -> V_3 ;
} else {
V_162 . V_121 = V_121 -> V_4 ;
V_162 . V_169 = V_170 ;
V_79 = F_94 ( V_160 , V_121 , V_171 , NULL ,
& V_162 ) ;
if ( V_79 < 0 && V_79 != - V_172 )
return - V_173 ;
}
V_121 = F_95 ( V_121 ) ;
if ( V_121 == NULL ||
F_96 ( V_121 -> V_114 ) != V_174 )
break;
V_160 = F_97 ( V_121 -> V_114 ) ;
V_163 . V_121 = V_121 -> V_4 ;
V_163 . V_169 = V_170 ;
V_79 = F_94 ( V_160 , V_121 , V_171 , NULL , & V_163 ) ;
if ( V_79 < 0 && V_79 != - V_172 )
return - V_173 ;
if ( V_163 . V_168 . V_93 != V_162 . V_168 . V_93 ||
V_163 . V_168 . V_94 != V_162 . V_168 . V_94 ||
V_163 . V_168 . V_120 != V_162 . V_168 . V_120 )
return - V_173 ;
}
return 0 ;
}
static int F_98 ( struct V_108 * V_108 , void * V_49 ,
enum V_175 type )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_159 * V_16 = V_12 -> V_14 . V_18 [ V_19 ] ;
struct V_13 * V_176 = & V_12 -> V_14 ;
int V_79 ;
if ( F_23 ( V_12 ) )
return - V_158 ;
V_79 = F_99 ( & V_16 -> V_114 , V_176 -> V_177 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_93 ( V_12 ) ;
if ( V_79 ) {
F_100 ( & V_16 -> V_114 ) ;
return V_79 ;
}
return F_101 ( & V_12 -> V_106 , type ) ;
}
static int F_102 ( struct V_108 * V_108 , void * V_49 ,
enum V_175 type )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_159 * V_160 = V_12 -> V_14 . V_18 [ V_19 ] ;
int V_79 ;
V_79 = F_103 ( & V_12 -> V_106 , type ) ;
if ( V_79 == 0 )
F_100 ( & V_160 -> V_114 ) ;
return V_79 ;
}
static int F_104 ( struct V_108 * V_108 , void * V_49 ,
struct V_178 * V_179 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
int V_79 ;
V_179 -> V_77 = F_105 ( T_1 , V_180 , V_179 -> V_77 ) ;
V_79 = F_106 ( & V_12 -> V_106 , V_179 ) ;
if ( ! V_79 < 0 )
V_12 -> V_181 = V_179 -> V_77 ;
return V_79 ;
}
static int F_107 ( struct V_108 * V_108 , void * V_49 ,
struct V_182 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_108 ( & V_12 -> V_106 , V_32 ) ;
}
static int F_109 ( struct V_108 * V_108 , void * V_49 ,
struct V_182 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_110 ( & V_12 -> V_106 , V_32 ) ;
}
static int F_111 ( struct V_108 * V_108 , void * V_49 ,
struct V_182 * V_32 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_112 ( & V_12 -> V_106 , V_32 , V_108 -> V_183 & V_184 ) ;
}
static int F_113 ( struct V_108 * V_108 , void * V_49 ,
struct V_185 * V_186 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_114 ( & V_12 -> V_106 , V_186 ) ;
}
static int F_115 ( struct V_108 * V_108 , void * V_49 ,
struct V_182 * V_187 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
return F_116 ( & V_12 -> V_106 , V_187 ) ;
}
static int F_117 ( struct V_130 * V_188 , struct V_130 * V_187 )
{
if ( V_188 -> V_132 < V_187 -> V_132 || V_188 -> V_134 < V_187 -> V_134 )
return 0 ;
if ( V_188 -> V_132 + V_188 -> V_93 > V_187 -> V_132 + V_187 -> V_93 )
return 0 ;
if ( V_188 -> V_134 + V_188 -> V_94 > V_187 -> V_134 + V_187 -> V_94 )
return 0 ;
return 1 ;
}
static int F_118 ( struct V_108 * V_108 , void * V_149 ,
struct V_189 * V_190 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_89 * V_146 = & V_12 -> V_25 ;
if ( V_190 -> type != V_191 )
return - V_21 ;
switch ( V_190 -> V_192 ) {
case V_193 :
case V_194 :
V_190 -> V_131 . V_132 = 0 ;
V_190 -> V_131 . V_134 = 0 ;
V_190 -> V_131 . V_93 = V_146 -> V_95 ;
V_190 -> V_131 . V_94 = V_146 -> V_96 ;
return 0 ;
case V_195 :
V_190 -> V_131 = V_146 -> V_128 ;
return 0 ;
}
return - V_21 ;
}
static int F_119 ( struct V_108 * V_108 , void * V_149 ,
struct V_189 * V_190 )
{
struct V_11 * V_12 = F_61 ( V_108 ) ;
struct V_89 * V_146 = & V_12 -> V_25 ;
struct V_130 V_128 = V_190 -> V_131 ;
unsigned long V_17 ;
if ( V_190 -> type != V_191 ||
V_190 -> V_192 != V_195 )
return - V_21 ;
F_84 ( V_12 , & V_128 ) ;
if ( ( V_190 -> V_17 & V_196 ) &&
! F_117 ( & V_128 , & V_190 -> V_131 ) )
return - V_197 ;
if ( ( V_190 -> V_17 & V_198 ) &&
! F_117 ( & V_190 -> V_131 , & V_128 ) )
return - V_197 ;
V_190 -> V_131 = V_128 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_146 -> V_128 = V_128 ;
F_24 ( V_47 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
return 0 ;
}
static int F_120 ( struct V_199 * V_114 ,
const struct V_164 * V_200 ,
const struct V_164 * V_201 , T_1 V_17 )
{
struct V_159 * V_160 = F_97 ( V_114 ) ;
struct V_11 * V_12 = F_121 ( V_160 ) ;
unsigned int V_202 = F_96 ( V_201 -> V_114 ) ;
if ( F_77 ( V_12 == NULL ) )
return 0 ;
F_80 ( 1 , V_28 , V_160 , L_5 ,
V_29 , V_200 -> V_114 -> V_148 , V_201 -> V_114 -> V_148 ,
V_17 , V_12 -> V_203 ) ;
switch ( V_200 -> V_4 ) {
case V_204 :
if ( V_202 != V_174 )
return - V_21 ;
if ( V_17 & V_205 ) {
if ( V_12 -> V_203 != 0 )
return - V_158 ;
V_12 -> V_203 = V_160 -> V_206 ;
return 0 ;
}
V_12 -> V_203 = 0 ;
break;
case V_207 :
if ( ! ( V_17 & V_205 ) ) {
V_12 -> V_61 = V_208 ;
return 0 ;
}
if ( V_202 == V_174 )
V_12 -> V_61 = V_209 ;
else
V_12 -> V_61 = V_62 ;
break;
default:
F_48 ( V_160 , L_6 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_122 ( struct V_159 * V_160 ,
struct V_210 * V_149 ,
struct V_211 * V_120 )
{
const struct V_1 * V_5 ;
V_5 = F_1 ( NULL , NULL , V_120 -> V_4 ) ;
if ( ! V_5 )
return - V_21 ;
V_120 -> V_120 = V_5 -> V_3 ;
return 0 ;
}
static int F_123 ( struct V_159 * V_160 ,
struct V_210 * V_149 ,
struct V_161 * V_5 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
struct V_212 * V_213 = & V_5 -> V_168 ;
struct V_89 * V_146 = & V_12 -> V_25 ;
if ( V_5 -> V_169 == V_214 ) {
V_213 = F_124 ( V_149 , V_5 -> V_121 ) ;
V_5 -> V_168 = * V_213 ;
return 0 ;
}
V_213 -> V_154 = V_155 ;
F_56 ( & V_12 -> V_107 ) ;
V_213 -> V_120 = V_12 -> V_5 -> V_3 ;
if ( V_5 -> V_121 == V_124 ) {
V_213 -> V_93 = V_146 -> V_95 ;
V_213 -> V_94 = V_146 -> V_96 ;
} else {
V_213 -> V_93 = V_146 -> V_128 . V_93 ;
V_213 -> V_94 = V_146 -> V_128 . V_94 ;
}
F_58 ( & V_12 -> V_107 ) ;
return 0 ;
}
static int F_125 ( struct V_159 * V_160 ,
struct V_210 * V_149 ,
struct V_161 * V_5 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
struct V_212 * V_213 = & V_5 -> V_168 ;
struct V_89 * V_215 = & V_12 -> V_24 ;
const struct V_1 * V_156 ;
F_80 ( 1 , V_28 , V_160 , L_7 ,
V_5 -> V_121 , V_213 -> V_120 , V_213 -> V_93 , V_213 -> V_94 ) ;
V_213 -> V_154 = V_155 ;
F_56 ( & V_12 -> V_107 ) ;
if ( ( V_12 -> V_61 == V_209 && V_160 -> V_114 . V_216 > 0 ) ||
( V_12 -> V_61 == V_62 && F_92 ( & V_12 -> V_106 ) ) ) {
F_58 ( & V_12 -> V_107 ) ;
return - V_158 ;
}
V_156 = F_76 ( V_12 , & V_213 -> V_93 , & V_213 -> V_94 ,
& V_213 -> V_120 , NULL , V_5 -> V_121 ) ;
if ( V_5 -> V_169 == V_214 ) {
V_213 = F_124 ( V_149 , V_5 -> V_121 ) ;
* V_213 = V_5 -> V_168 ;
F_58 ( & V_12 -> V_107 ) ;
return 0 ;
}
if ( V_5 -> V_121 == V_124 ) {
V_215 -> V_95 = V_213 -> V_93 ;
V_215 -> V_96 = V_213 -> V_94 ;
V_12 -> V_5 = V_156 ;
V_215 -> V_128 . V_93 = V_213 -> V_93 ;
V_215 -> V_128 . V_94 = V_213 -> V_94 ;
V_215 -> V_128 . V_132 = 0 ;
V_215 -> V_128 . V_134 = 0 ;
V_12 -> V_25 . V_128 = V_215 -> V_128 ;
} else {
V_213 -> V_120 = V_12 -> V_5 -> V_3 ;
V_213 -> V_93 = V_215 -> V_128 . V_93 ;
V_213 -> V_94 = V_215 -> V_128 . V_94 ;
}
F_58 ( & V_12 -> V_107 ) ;
return 0 ;
}
static int F_126 ( struct V_159 * V_160 ,
struct V_210 * V_149 ,
struct V_217 * V_190 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
struct V_89 * V_146 = & V_12 -> V_24 ;
if ( ( V_190 -> V_192 != V_218 &&
V_190 -> V_192 != V_219 ) ||
V_190 -> V_121 != V_124 )
return - V_21 ;
if ( V_190 -> V_169 == V_214 ) {
V_190 -> V_131 = * F_127 ( V_149 , V_190 -> V_121 ) ;
return 0 ;
}
F_56 ( & V_12 -> V_107 ) ;
if ( V_190 -> V_192 == V_218 ) {
V_190 -> V_131 = V_146 -> V_128 ;
} else {
V_190 -> V_131 . V_132 = 0 ;
V_190 -> V_131 . V_134 = 0 ;
V_190 -> V_131 . V_93 = V_146 -> V_95 ;
V_190 -> V_131 . V_94 = V_146 -> V_96 ;
}
F_58 ( & V_12 -> V_107 ) ;
F_80 ( 1 , V_28 , V_160 , L_8 ,
V_29 , V_146 -> V_128 . V_132 , V_146 -> V_128 . V_134 , V_146 -> V_128 . V_93 ,
V_146 -> V_128 . V_94 , V_146 -> V_95 , V_146 -> V_96 ) ;
return 0 ;
}
static int F_128 ( struct V_159 * V_160 ,
struct V_210 * V_149 ,
struct V_217 * V_190 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
struct V_89 * V_146 = & V_12 -> V_24 ;
int V_79 = 0 ;
if ( V_190 -> V_192 != V_218 || V_190 -> V_121 != V_124 )
return - V_21 ;
F_56 ( & V_12 -> V_107 ) ;
F_81 ( V_12 , & V_190 -> V_131 ) ;
if ( V_190 -> V_169 == V_214 ) {
* F_127 ( V_149 , V_190 -> V_121 ) = V_190 -> V_131 ;
} else {
unsigned long V_17 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
V_146 -> V_128 = V_190 -> V_131 ;
V_12 -> V_25 . V_128 = V_190 -> V_131 ;
F_24 ( V_47 , & V_12 -> V_34 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
}
F_58 ( & V_12 -> V_107 ) ;
F_80 ( 1 , V_28 , V_160 , L_8 ,
V_29 , V_146 -> V_128 . V_132 , V_146 -> V_128 . V_134 , V_146 -> V_128 . V_93 ,
V_146 -> V_128 . V_94 , V_146 -> V_95 , V_146 -> V_96 ) ;
return V_79 ;
}
static int F_129 ( struct V_159 * V_160 , int V_220 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
if ( V_12 -> V_61 == V_62 )
return - V_172 ;
return 0 ;
}
static int F_130 ( struct V_159 * V_160 , int V_220 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
if ( V_12 -> V_61 == V_62 )
return - V_172 ;
return 0 ;
}
static int F_131 ( struct V_159 * V_160 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
F_12 ( V_12 , V_29 ) ;
return 0 ;
}
static int F_132 ( struct V_159 * V_160 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
struct V_75 * V_76 = & V_12 -> V_106 ;
struct V_221 * V_105 ;
int V_79 ;
V_12 -> V_5 = & V_9 [ 0 ] ;
V_12 -> V_61 = V_62 ;
V_105 = F_133 () ;
if ( ! V_105 ) {
F_48 ( V_160 -> V_222 , L_9 ) ;
return - V_223 ;
}
snprintf ( V_105 -> V_148 , sizeof( V_105 -> V_148 ) , L_10 ,
V_12 -> V_4 ) ;
V_105 -> V_224 = & V_225 ;
V_105 -> V_226 = & V_227 ;
V_105 -> V_222 = V_160 -> V_222 ;
V_105 -> V_228 = - 1 ;
V_105 -> V_229 = V_230 ;
V_105 -> V_107 = & V_12 -> V_107 ;
V_12 -> V_105 = V_105 ;
V_12 -> V_113 = 0 ;
V_12 -> V_181 = 0 ;
F_134 ( & V_12 -> V_41 ) ;
F_134 ( & V_12 -> V_44 ) ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> type = V_191 ;
V_76 -> V_231 = V_232 | V_233 ;
V_76 -> V_234 = & V_235 ;
V_76 -> V_236 = & V_237 ;
V_76 -> V_238 = sizeof( struct V_31 ) ;
V_76 -> V_78 = V_12 ;
F_135 ( V_76 ) ;
V_12 -> V_239 . V_17 = V_166 ;
V_79 = F_136 ( & V_105 -> V_114 , 1 , & V_12 -> V_239 , 0 ) ;
if ( V_79 )
goto V_240;
F_137 ( V_105 , V_12 ) ;
V_79 = F_138 ( V_105 , V_241 , - 1 ) ;
if ( V_79 )
goto V_242;
F_139 ( V_160 -> V_222 , L_11 ,
V_105 -> V_148 , F_140 ( V_105 ) ) ;
return 0 ;
V_242:
F_141 ( & V_105 -> V_114 ) ;
V_240:
V_230 ( V_105 ) ;
return V_79 ;
}
static void F_142 ( struct V_159 * V_160 )
{
struct V_11 * V_12 = F_121 ( V_160 ) ;
if ( V_12 == NULL )
return;
if ( V_12 -> V_105 ) {
F_143 ( V_12 -> V_105 ) ;
F_141 ( & V_12 -> V_105 -> V_114 ) ;
V_12 -> V_105 = NULL ;
}
}
static int F_144 ( struct V_243 * V_244 )
{
struct V_11 * V_12 = F_51 ( V_244 -> V_245 , struct V_11 ,
V_246 ) ;
F_24 ( V_47 , & V_12 -> V_34 ) ;
return 0 ;
}
static int F_145 ( struct V_11 * V_12 )
{
struct V_247 * V_245 = & V_12 -> V_246 ;
struct V_159 * V_160 = & V_12 -> V_129 ;
int V_79 ;
F_146 ( V_160 , & V_248 ) ;
V_160 -> V_17 = V_249 ;
snprintf ( V_160 -> V_148 , sizeof( V_160 -> V_148 ) , L_12 , V_12 -> V_4 ) ;
V_12 -> V_250 [ V_204 ] . V_17 = V_166 ;
V_12 -> V_250 [ V_207 ] . V_17 = V_251 ;
V_79 = F_136 ( & V_160 -> V_114 , V_252 ,
V_12 -> V_250 , 0 ) ;
if ( V_79 )
return V_79 ;
F_147 ( V_245 , 1 ) ;
V_12 -> V_26 = F_148 ( V_245 , & V_253 ,
NULL ) ;
if ( V_245 -> error ) {
F_141 ( & V_160 -> V_114 ) ;
return V_245 -> error ;
}
V_160 -> V_246 = V_245 ;
V_160 -> V_254 = & V_255 ;
V_160 -> V_114 . V_234 = & V_256 ;
F_149 ( V_160 , V_12 ) ;
return 0 ;
}
static void F_150 ( struct V_11 * V_12 )
{
struct V_159 * V_160 = & V_12 -> V_129 ;
F_151 ( V_160 ) ;
F_141 ( & V_160 -> V_114 ) ;
F_152 ( & V_12 -> V_246 ) ;
F_149 ( V_160 , NULL ) ;
}
static void F_153 ( struct V_11 * V_12 )
{
if ( F_154 ( V_12 -> clock ) )
return;
F_155 ( V_12 -> clock ) ;
F_156 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
static int F_157 ( struct V_11 * V_12 )
{
int V_79 ;
V_12 -> clock = F_158 ( & V_12 -> V_111 -> V_112 , V_257 ) ;
if ( F_159 ( V_12 -> clock ) )
return F_160 ( V_12 -> clock ) ;
V_79 = F_161 ( V_12 -> clock ) ;
if ( V_79 < 0 ) {
F_156 ( V_12 -> clock ) ;
V_12 -> clock = NULL ;
}
return V_79 ;
}
static int T_3 F_162 ( struct V_258 * V_111 )
{
struct V_259 * V_260 = F_163 ( V_111 ) ;
struct V_11 * V_12 ;
struct V_261 * V_262 ;
int V_79 ;
V_12 = F_164 ( & V_111 -> V_112 , sizeof( * V_12 ) , V_263 ) ;
if ( ! V_12 )
return - V_223 ;
V_12 -> V_4 = V_111 -> V_8 ;
V_12 -> V_123 = V_260 -> V_123 [ V_12 -> V_4 ] ;
V_12 -> V_111 = V_111 ;
F_165 ( & V_12 -> V_45 ) ;
F_166 ( & V_12 -> V_22 ) ;
F_167 ( & V_12 -> V_107 ) ;
V_262 = F_168 ( V_111 , V_264 , 0 ) ;
V_12 -> V_265 = F_169 ( & V_111 -> V_112 , V_262 ) ;
if ( V_12 -> V_265 == NULL ) {
F_170 ( & V_111 -> V_112 , L_13 ) ;
return - V_266 ;
}
V_262 = F_168 ( V_111 , V_267 , 0 ) ;
if ( V_262 == NULL ) {
F_170 ( & V_111 -> V_112 , L_14 ) ;
return - V_20 ;
}
V_79 = F_157 ( V_12 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_171 ( & V_111 -> V_112 , V_262 -> V_268 , F_31 ,
0 , F_172 ( & V_111 -> V_112 ) , V_12 ) ;
if ( V_79 ) {
F_170 ( & V_111 -> V_112 , L_15 , V_79 ) ;
goto V_269;
}
V_79 = F_145 ( V_12 ) ;
if ( V_79 )
goto V_269;
F_173 ( V_111 , V_12 ) ;
F_174 ( & V_111 -> V_112 ) ;
V_79 = F_63 ( & V_111 -> V_112 ) ;
if ( V_79 < 0 )
goto V_270;
V_12 -> V_102 = F_175 ( & V_111 -> V_112 ) ;
if ( F_159 ( V_12 -> V_102 ) ) {
V_79 = F_160 ( V_12 -> V_102 ) ;
goto V_271;
}
F_70 ( & V_111 -> V_112 ) ;
F_176 ( & V_111 -> V_112 , L_16 ,
V_12 -> V_4 ) ;
return 0 ;
V_271:
F_70 ( & V_111 -> V_112 ) ;
V_270:
F_150 ( V_12 ) ;
V_269:
F_153 ( V_12 ) ;
return V_79 ;
}
static int F_177 ( struct V_272 * V_112 )
{
struct V_11 * V_12 = F_178 ( V_112 ) ;
F_179 ( V_12 -> clock ) ;
return 0 ;
}
static int F_180 ( struct V_272 * V_112 )
{
struct V_11 * V_12 = F_178 ( V_112 ) ;
F_181 ( V_12 -> clock ) ;
return 0 ;
}
static int F_182 ( struct V_272 * V_112 )
{
struct V_11 * V_12 = F_178 ( V_112 ) ;
struct V_31 * V_32 ;
unsigned long V_17 ;
int V_7 ;
F_5 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_34 ( V_273 , & V_12 -> V_34 ) ||
! F_27 ( V_110 , & V_12 -> V_34 ) ) {
F_13 ( & V_12 -> V_22 , V_17 ) ;
return 0 ;
}
F_20 ( V_12 ) ;
F_13 ( & V_12 -> V_22 , V_17 ) ;
if ( ! F_34 ( V_39 , & V_12 -> V_34 ) )
return 0 ;
F_134 ( & V_12 -> V_44 ) ;
F_65 ( & V_12 -> V_14 , & V_12 -> V_105 -> V_114 , false ) ;
F_3 ( V_12 ) ;
F_30 ( V_39 , & V_12 -> V_34 ) ;
for ( V_7 = 0 ; V_7 < V_12 -> V_181 ; V_7 ++ ) {
if ( F_15 ( & V_12 -> V_41 ) )
break;
V_32 = F_16 ( V_12 ) ;
F_50 ( & V_32 -> V_42 ) ;
}
return 0 ;
}
static int F_183 ( struct V_272 * V_112 )
{
struct V_11 * V_12 = F_178 ( V_112 ) ;
bool V_30 = F_27 ( V_110 , & V_12 -> V_34 ) ;
int V_79 ;
if ( F_41 ( V_273 , & V_12 -> V_34 ) )
return 0 ;
V_79 = F_22 ( V_12 , V_30 ) ;
if ( V_79 < 0 || ! F_23 ( V_12 ) )
return V_79 ;
return F_69 ( & V_12 -> V_14 ) ;
}
static int T_4 F_184 ( struct V_258 * V_111 )
{
struct V_11 * V_12 = F_185 ( V_111 ) ;
struct V_272 * V_112 = & V_111 -> V_112 ;
F_186 ( V_112 ) ;
F_187 ( V_112 ) ;
F_150 ( V_12 ) ;
F_188 ( V_12 -> V_102 ) ;
F_153 ( V_12 ) ;
F_189 ( V_112 , L_17 ) ;
return 0 ;
}
