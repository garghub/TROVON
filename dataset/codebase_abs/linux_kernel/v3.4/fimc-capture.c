static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 = 0 ;
if ( V_2 -> V_10 . V_7 == NULL || V_4 == NULL )
return - V_11 ;
if ( V_4 -> V_12 . V_13 == NULL )
return - V_14 ;
V_7 = F_2 ( V_2 -> V_10 . V_7 ) ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_4 ( V_4 , & V_4 -> V_16 ) ;
F_5 ( V_4 ) ;
F_6 ( V_2 , V_7 -> V_17 ) ;
F_7 ( V_2 , V_7 -> V_17 ) ;
F_8 ( V_2 , V_7 -> V_17 ) ;
F_9 ( V_2 , & V_4 -> V_12 ) ;
V_9 = F_10 ( V_4 ) ;
if ( ! V_9 ) {
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 , false ) ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
if ( V_2 -> V_18 -> V_19 )
F_19 ( V_4 ) ;
F_20 ( V_20 , & V_2 -> V_21 ) ;
}
F_21 ( & V_2 -> V_15 , V_8 ) ;
return V_9 ;
}
static int F_22 ( struct V_1 * V_2 , bool V_22 )
{
struct V_23 * V_24 = & V_2 -> V_5 ;
struct V_25 * V_26 ;
unsigned long V_8 ;
bool V_27 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
V_27 = V_2 -> V_21 & ( 1 << V_28 ) ;
V_2 -> V_21 &= ~ ( 1 << V_29 | 1 << V_30 |
1 << V_31 | 1 << V_28 ) ;
if ( ! V_22 )
V_2 -> V_21 &= ~ ( 1 << V_32 | 1 << V_33 ) ;
while ( ! V_22 && ! F_23 ( & V_24 -> V_34 ) ) {
V_26 = F_24 ( V_24 ) ;
F_25 ( & V_26 -> V_35 , V_36 ) ;
}
while ( ! F_23 ( & V_24 -> V_37 ) ) {
V_26 = F_26 ( V_24 ) ;
if ( V_22 )
F_27 ( V_24 , V_26 ) ;
else
F_25 ( & V_26 -> V_35 , V_36 ) ;
}
F_28 ( V_33 , & V_2 -> V_21 ) ;
F_29 ( V_2 ) ;
V_24 -> V_38 = 0 ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
if ( V_27 )
return F_30 ( V_2 , 0 ) ;
else
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , bool V_22 )
{
unsigned long V_8 ;
if ( ! F_32 ( V_2 ) )
return 0 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_28 ( V_30 , & V_2 -> V_21 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
F_34 ( V_2 -> V_39 ,
! F_35 ( V_30 , & V_2 -> V_21 ) ,
( 2 * V_40 / 10 ) ) ;
return F_22 ( V_2 , V_22 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
int V_9 ;
if ( ! F_35 ( V_20 , & V_2 -> V_21 ) )
return 0 ;
F_37 ( & V_4 -> V_15 ) ;
F_9 ( V_2 , & V_4 -> V_12 ) ;
V_9 = F_10 ( V_4 ) ;
if ( V_9 == 0 ) {
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_4 ( V_4 , & V_4 -> V_16 ) ;
F_18 ( V_4 ) ;
if ( V_2 -> V_18 -> V_19 )
F_19 ( V_4 ) ;
F_20 ( V_20 , & V_2 -> V_21 ) ;
}
F_38 ( & V_4 -> V_15 ) ;
return V_9 ;
}
static int F_39 ( struct V_41 * V_42 , unsigned int V_43 )
{
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
int V_45 ;
int V_9 ;
V_5 -> V_46 = 0 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
goto error;
F_28 ( V_32 , & V_2 -> V_21 ) ;
V_45 = V_2 -> V_5 . V_47 > 1 ? 2 : 1 ;
if ( V_5 -> V_48 >= V_45 &&
! F_40 ( V_31 , & V_2 -> V_21 ) ) {
F_41 ( V_4 ) ;
if ( ! F_40 ( V_28 , & V_2 -> V_21 ) )
F_30 ( V_2 , 1 ) ;
}
return 0 ;
error:
F_22 ( V_2 , false ) ;
return V_9 ;
}
static int F_42 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_32 ( V_2 ) )
return - V_14 ;
return F_31 ( V_2 , false ) ;
}
int F_43 ( struct V_1 * V_2 )
{
bool V_22 = F_44 ( V_2 ) ;
int V_9 = F_31 ( V_2 , V_22 ) ;
if ( V_9 )
return V_9 ;
return F_45 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_25 * V_26 ;
int V_49 ;
if ( ! F_47 ( V_33 , & V_2 -> V_21 ) )
return 0 ;
F_48 ( & V_2 -> V_5 . V_37 ) ;
V_5 -> V_38 = 0 ;
F_49 ( V_2 , & V_2 -> V_5 . V_50 -> V_51 ,
false ) ;
F_1 ( V_2 ) ;
F_20 ( V_33 , & V_2 -> V_21 ) ;
for ( V_49 = 0 ; V_49 < V_5 -> V_47 ; V_49 ++ ) {
if ( F_23 ( & V_5 -> V_34 ) )
break;
V_26 = F_24 ( V_5 ) ;
F_50 ( & V_26 -> V_35 ) ;
}
return 0 ;
}
static int F_51 ( struct V_41 * V_52 , const struct V_53 * V_54 ,
unsigned int * V_55 , unsigned int * V_56 ,
unsigned int V_57 [] , void * V_58 [] )
{
const struct V_59 * V_60 = NULL ;
struct V_3 * V_4 = V_52 -> V_44 ;
struct V_61 * V_62 = & V_4 -> V_16 ;
struct V_63 * V_13 = V_62 -> V_13 ;
unsigned long V_64 ;
int V_49 ;
if ( V_54 ) {
V_60 = & V_54 -> V_13 . V_65 ;
V_13 = F_52 ( & V_60 -> V_66 , NULL ,
V_67 | V_68 , - 1 ) ;
V_64 = V_60 -> V_69 * V_60 -> V_70 ;
} else {
V_64 = V_62 -> V_71 * V_62 -> V_72 ;
}
if ( V_13 == NULL )
return - V_14 ;
* V_56 = V_13 -> V_73 ;
for ( V_49 = 0 ; V_49 < V_13 -> V_73 ; V_49 ++ ) {
unsigned int V_74 = ( V_64 * V_13 -> V_75 [ V_49 ] ) / 8 ;
if ( V_60 )
V_57 [ V_49 ] = F_53 ( V_74 , V_60 -> V_76 [ V_49 ] . V_77 ) ;
else
V_57 [ V_49 ] = V_74 ;
V_58 [ V_49 ] = V_4 -> V_1 -> V_78 ;
}
return 0 ;
}
static int F_54 ( struct V_79 * V_35 )
{
struct V_41 * V_52 = V_35 -> V_41 ;
struct V_3 * V_4 = V_52 -> V_44 ;
int V_49 ;
if ( V_4 -> V_16 . V_13 == NULL )
return - V_14 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_16 . V_13 -> V_73 ; V_49 ++ ) {
unsigned long V_74 = V_4 -> V_16 . V_80 [ V_49 ] ;
if ( F_55 ( V_35 , V_49 ) < V_74 ) {
F_56 ( V_4 -> V_1 -> V_5 . V_50 ,
L_1 ,
F_55 ( V_35 , V_49 ) , V_74 ) ;
return - V_14 ;
}
F_57 ( V_35 , V_49 , V_74 ) ;
}
return 0 ;
}
static void F_50 ( struct V_79 * V_35 )
{
struct V_25 * V_26
= F_58 ( V_35 , struct V_25 , V_35 ) ;
struct V_3 * V_4 = F_59 ( V_35 -> V_41 ) ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
unsigned long V_8 ;
int V_45 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_60 ( V_4 , & V_26 -> V_35 , & V_4 -> V_16 , & V_26 -> V_81 ) ;
if ( ! F_35 ( V_33 , & V_2 -> V_21 ) &&
! F_35 ( V_31 , & V_2 -> V_21 ) &&
V_5 -> V_48 < V_82 ) {
int V_83 = ( V_5 -> V_47 == 1 ) ? - 1 :
V_5 -> V_38 ;
F_61 ( V_2 , & V_26 -> V_81 , V_83 ) ;
V_26 -> V_84 = V_5 -> V_38 ;
F_62 ( V_5 , V_26 ) ;
if ( ++ V_5 -> V_38 >= V_82 )
V_5 -> V_38 = 0 ;
} else {
F_27 ( V_5 , V_26 ) ;
}
V_45 = V_5 -> V_47 > 1 ? 2 : 1 ;
if ( F_63 ( & V_5 -> V_85 ) &&
V_5 -> V_48 >= V_45 &&
! F_40 ( V_31 , & V_2 -> V_21 ) ) {
F_41 ( V_4 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
if ( ! F_40 ( V_28 , & V_2 -> V_21 ) )
F_30 ( V_2 , 1 ) ;
return;
}
F_21 ( & V_2 -> V_15 , V_8 ) ;
}
static void F_64 ( struct V_41 * V_52 )
{
struct V_3 * V_4 = F_59 ( V_52 ) ;
F_65 ( & V_4 -> V_1 -> V_86 ) ;
}
static void F_66 ( struct V_41 * V_52 )
{
struct V_3 * V_4 = F_59 ( V_52 ) ;
F_67 ( & V_4 -> V_1 -> V_86 ) ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = & V_2 -> V_5 ;
int V_9 ;
if ( F_69 ( V_5 -> V_4 == NULL ) )
return - V_11 ;
if ( V_5 -> V_4 -> V_87 )
return 0 ;
V_9 = F_70 ( V_5 -> V_4 ) ;
if ( V_9 || V_5 -> V_88 )
return V_9 ;
return F_71 ( & V_5 -> V_4 -> V_89 ,
V_2 -> V_10 . V_7 -> V_89 ) ;
}
static int F_72 ( struct V_90 * V_90 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
int V_9 = F_74 ( V_90 ) ;
if ( V_9 )
return V_9 ;
F_75 ( L_2 , F_76 ( V_91 ) , V_2 -> V_21 ) ;
if ( F_77 ( V_2 ) )
return - V_92 ;
F_28 ( V_93 , & V_2 -> V_21 ) ;
F_78 ( & V_2 -> V_94 -> V_95 ) ;
if ( ++ V_2 -> V_5 . V_96 == 1 ) {
V_9 = F_49 ( V_2 ,
& V_2 -> V_5 . V_50 -> V_51 , true ) ;
if ( V_9 < 0 ) {
F_79 ( & V_2 -> V_94 -> V_95 ,
L_3 ) ;
F_80 ( & V_2 -> V_94 -> V_95 ) ;
V_2 -> V_5 . V_96 -- ;
F_81 ( V_90 ) ;
F_20 ( V_93 , & V_2 -> V_21 ) ;
return V_9 ;
}
V_9 = F_68 ( V_2 ) ;
if ( ! V_9 && ! V_2 -> V_5 . V_88 )
V_9 = F_82 ( V_2 ) ;
}
return V_9 ;
}
static int F_83 ( struct V_90 * V_90 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
F_75 ( L_2 , F_76 ( V_91 ) , V_2 -> V_21 ) ;
if ( -- V_2 -> V_5 . V_96 == 0 ) {
F_20 ( V_93 , & V_2 -> V_21 ) ;
F_31 ( V_2 , false ) ;
F_45 ( V_2 ) ;
F_20 ( V_33 , & V_2 -> V_21 ) ;
}
F_84 ( & V_2 -> V_94 -> V_95 ) ;
if ( V_2 -> V_5 . V_96 == 0 ) {
F_85 ( & V_2 -> V_5 . V_85 ) ;
F_86 ( V_2 -> V_5 . V_4 ) ;
}
return F_81 ( V_90 ) ;
}
static unsigned int F_87 ( struct V_90 * V_90 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_88 ( & V_2 -> V_5 . V_85 , V_90 , V_98 ) ;
}
static int F_89 ( struct V_90 * V_90 , struct V_99 * V_100 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_90 ( & V_2 -> V_5 . V_85 , V_100 ) ;
}
static struct V_63 * F_91 ( struct V_3 * V_4 ,
T_1 * V_69 , T_1 * V_70 ,
T_1 * V_101 , T_1 * V_102 , int V_103 )
{
bool V_104 = V_4 -> V_104 == 90 || V_4 -> V_104 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_105 * V_106 = V_2 -> V_18 ;
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_61 * V_110 = & V_4 -> V_16 ;
T_1 V_75 , V_111 , V_112 , V_113 , V_114 = 3 ;
T_1 V_115 = V_67 ;
struct V_63 * V_116 ;
if ( V_101 && V_4 -> V_12 . V_13 && V_103 == V_117 &&
F_92 ( V_4 -> V_12 . V_13 -> V_118 ) )
* V_101 = V_119 ;
if ( V_102 && * V_102 != V_120 && V_103 != V_121 )
V_115 |= V_68 ;
V_116 = F_52 ( V_102 , V_101 , V_115 , 0 ) ;
if ( F_69 ( ! V_116 ) )
return NULL ;
if ( V_101 )
* V_101 = V_116 -> V_122 ;
if ( V_102 )
* V_102 = V_116 -> V_102 ;
if ( V_103 == V_121 ) {
V_112 = F_92 ( V_116 -> V_118 ) ?
V_108 -> V_123 : V_108 -> V_124 ;
F_93 ( V_69 , F_94 ( T_1 , * V_69 , 32 ) , V_112 , 4 ,
V_70 , F_94 ( T_1 , * V_70 , 32 ) ,
V_125 ,
F_92 ( V_116 -> V_118 ) ? 3 : 1 ,
0 ) ;
return V_116 ;
}
if ( F_92 ( V_116 -> V_118 ) ) {
* V_69 = V_4 -> V_12 . V_71 ;
* V_70 = V_4 -> V_12 . V_72 ;
return V_116 ;
}
V_112 = V_104 ? V_108 -> V_126 : V_108 -> V_127 ;
V_111 = V_4 -> V_21 & V_128 ? V_110 -> V_69 : V_106 -> V_129 ;
V_113 = V_4 -> V_21 & V_128 ? V_110 -> V_70 : V_106 -> V_129 ;
if ( V_106 -> V_130 == 1 && ! V_104 )
V_114 = F_95 ( V_116 -> V_118 ) ? 0 : 1 ;
V_75 = F_96 ( V_116 ) ;
F_93 ( V_69 , V_111 , V_112 ,
F_97 ( V_106 -> V_129 ) - 1 ,
V_70 , V_113 , V_125 ,
V_114 ,
64 / ( F_98 ( V_75 , 8 ) ) ) ;
F_75 ( L_4 ,
V_103 , V_101 ? * V_101 : 0 , * V_69 , * V_70 ,
V_110 -> V_71 , V_110 -> V_72 ) ;
return V_116 ;
}
static void F_99 ( struct V_3 * V_4 , struct V_131 * V_132 ,
int V_103 )
{
bool V_133 = V_4 -> V_104 == 90 || V_4 -> V_104 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_105 * V_106 = V_2 -> V_18 ;
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_61 * V_134 = & V_4 -> V_12 ;
T_1 V_112 , V_135 , V_111 = 0 , V_113 = 0 , V_136 ;
T_1 V_137 = 0 , V_114 = 4 ;
T_1 V_138 , V_139 ;
if ( F_92 ( V_4 -> V_16 . V_13 -> V_118 ) ) {
V_132 -> V_69 = V_134 -> V_71 ;
V_132 -> V_70 = V_134 -> V_72 ;
V_132 -> V_140 = V_132 -> V_141 = 0 ;
return;
}
if ( V_103 == V_117 ) {
if ( V_4 -> V_104 != 90 && V_4 -> V_104 != 270 )
V_114 = 1 ;
V_138 = F_100 ( V_142 , 1 << ( F_97 ( V_134 -> V_69 ) - 3 ) ) ;
V_139 = F_100 ( V_143 , 1 << ( F_97 ( V_134 -> V_70 ) - 1 ) ) ;
V_136 = V_106 -> V_129 ;
} else {
T_1 V_75 = F_96 ( V_134 -> V_13 ) ;
V_137 = 64 / F_98 ( V_75 , 8 ) ;
V_136 = V_106 -> V_144 ;
V_111 = V_113 = V_136 ;
V_138 = V_139 = 1 ;
}
V_112 = F_101 ( T_1 ,
V_133 ? V_108 -> V_126 : V_108 -> V_127 ,
V_133 ? V_134 -> V_72 : V_134 -> V_71 ) ;
V_135 = F_101 ( T_1 , V_125 , V_134 -> V_72 ) ;
if ( V_103 == V_117 ) {
V_111 = F_101 ( T_1 , V_112 , V_134 -> V_71 / V_138 ) ;
V_113 = F_101 ( T_1 , V_135 , V_134 -> V_72 / V_139 ) ;
if ( V_133 ) {
F_102 ( V_138 , V_139 ) ;
F_102 ( V_111 , V_113 ) ;
}
}
F_93 ( & V_132 -> V_69 , V_111 , V_112 , F_97 ( V_136 ) - 1 ,
& V_132 -> V_70 , V_113 , V_135 , V_114 ,
V_137 ) ;
V_132 -> V_140 = F_103 ( T_1 , V_132 -> V_140 , 0 , V_134 -> V_71 - V_132 -> V_69 ) ;
V_132 -> V_141 = F_103 ( T_1 , V_132 -> V_141 , 0 , V_134 -> V_72 - V_132 -> V_70 ) ;
V_132 -> V_140 = F_104 ( V_132 -> V_140 , V_106 -> V_145 ) ;
F_75 ( L_5 ,
V_103 , V_132 -> V_140 , V_132 -> V_141 , V_132 -> V_69 , V_132 -> V_70 ,
V_134 -> V_71 , V_134 -> V_72 ) ;
}
static int F_105 ( struct V_90 * V_90 , void * V_146 ,
struct V_147 * V_24 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
strncpy ( V_24 -> V_148 , V_2 -> V_94 -> V_149 , sizeof( V_24 -> V_148 ) - 1 ) ;
strncpy ( V_24 -> V_150 , V_2 -> V_94 -> V_149 , sizeof( V_24 -> V_150 ) - 1 ) ;
V_24 -> V_151 [ 0 ] = 0 ;
V_24 -> V_152 = V_153 | V_154 ;
return 0 ;
}
static int F_106 ( struct V_90 * V_90 , void * V_146 ,
struct V_155 * V_156 )
{
struct V_63 * V_13 ;
V_13 = F_52 ( NULL , NULL , V_67 | V_68 ,
V_156 -> V_84 ) ;
if ( ! V_13 )
return - V_14 ;
strncpy ( V_156 -> V_157 , V_13 -> V_149 , sizeof( V_156 -> V_157 ) - 1 ) ;
V_156 -> V_66 = V_13 -> V_102 ;
if ( V_13 -> V_102 == V_119 )
V_156 -> V_8 |= V_158 ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 ,
struct V_159 * V_160 ,
struct V_63 * * V_161 ,
bool V_162 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_163 * V_164 = V_2 -> V_10 . V_7 ;
struct V_163 * V_165 = V_2 -> V_10 . V_165 ;
struct V_166 V_167 ;
struct V_159 * V_168 = & V_167 . V_169 ;
struct V_63 * V_116 = NULL ;
int V_9 , V_49 = 0 ;
if ( F_69 ( ! V_164 || ! V_160 ) )
return - V_14 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_169 = * V_160 ;
V_167 . V_170 = V_162 ? V_171 : V_172 ;
while ( 1 ) {
V_116 = F_52 ( NULL , V_168 -> V_101 != 0 ? & V_168 -> V_101 : NULL ,
V_67 , V_49 ++ ) ;
if ( V_116 == NULL ) {
return - V_14 ;
}
V_168 -> V_101 = V_160 -> V_101 = V_116 -> V_122 ;
V_9 = F_108 ( V_164 , V_103 , V_173 , NULL , & V_167 ) ;
if ( V_9 )
return V_9 ;
if ( V_168 -> V_101 != V_160 -> V_101 ) {
V_168 -> V_101 = 0 ;
continue;
}
if ( V_168 -> V_69 != V_160 -> V_69 || V_168 -> V_70 != V_160 -> V_70 ) {
T_1 V_174 = V_116 -> V_102 ;
V_160 -> V_69 = V_168 -> V_69 ;
V_160 -> V_70 = V_168 -> V_70 ;
V_116 = F_91 ( V_4 ,
& V_160 -> V_69 , & V_160 -> V_70 ,
NULL , & V_174 , V_117 ) ;
if ( V_116 && V_116 -> V_122 )
V_168 -> V_101 = V_116 -> V_122 ;
if ( V_168 -> V_69 != V_160 -> V_69 ||
V_168 -> V_70 != V_160 -> V_70 )
continue;
V_160 -> V_101 = V_168 -> V_101 ;
}
if ( V_165 )
V_9 = F_108 ( V_165 , V_103 , V_173 , NULL , & V_167 ) ;
if ( V_168 -> V_101 == V_160 -> V_101 &&
V_168 -> V_69 == V_160 -> V_69 && V_168 -> V_70 == V_160 -> V_70 )
break;
}
if ( V_161 && V_116 )
* V_161 = V_116 ;
* V_160 = * V_168 ;
F_75 ( L_6 , V_168 -> V_101 , V_168 -> V_69 , V_168 -> V_70 , V_116 ) ;
return 0 ;
}
static int F_109 ( struct V_90 * V_90 , void * V_175 ,
struct V_53 * V_156 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( V_156 -> type != V_176 )
return - V_14 ;
return F_110 ( & V_4 -> V_16 , V_156 ) ;
}
static int F_111 ( struct V_90 * V_90 , void * V_175 ,
struct V_53 * V_156 )
{
struct V_59 * V_177 = & V_156 -> V_13 . V_65 ;
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_159 V_168 ;
struct V_63 * V_116 = NULL ;
if ( V_156 -> type != V_176 )
return - V_14 ;
if ( V_177 -> V_66 == V_120 ) {
F_91 ( V_4 , & V_177 -> V_69 , & V_177 -> V_70 ,
NULL , & V_177 -> V_66 ,
V_121 ) ;
V_4 -> V_12 . V_71 = V_177 -> V_69 ;
V_4 -> V_12 . V_72 = V_177 -> V_70 ;
}
V_116 = F_91 ( V_4 , & V_177 -> V_69 , & V_177 -> V_70 ,
NULL , & V_177 -> V_66 ,
V_117 ) ;
if ( ! V_116 )
return - V_14 ;
if ( ! V_2 -> V_5 . V_88 ) {
V_168 . V_69 = V_177 -> V_69 ;
V_168 . V_70 = V_177 -> V_70 ;
V_168 . V_101 = V_116 -> V_122 ;
F_112 ( V_2 ) ;
F_107 ( V_4 , & V_168 , & V_116 , false ) ;
F_113 ( V_2 ) ;
V_177 -> V_69 = V_168 . V_69 ;
V_177 -> V_70 = V_168 . V_70 ;
if ( V_116 )
V_177 -> V_66 = V_116 -> V_102 ;
}
F_114 ( V_116 , V_177 -> V_69 , V_177 -> V_70 , V_177 ) ;
return 0 ;
}
static void F_115 ( struct V_3 * V_4 , bool V_178 )
{
V_4 -> V_179 . V_180 = ! V_178 ;
F_116 ( V_4 , ! V_178 ) ;
if ( V_178 )
F_28 ( V_181 , & V_4 -> V_1 -> V_21 ) ;
else
F_20 ( V_181 , & V_4 -> V_1 -> V_21 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_53 * V_156 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_59 * V_177 = & V_156 -> V_13 . V_65 ;
struct V_159 * V_168 = & V_2 -> V_5 . V_168 ;
struct V_61 * V_182 = & V_4 -> V_16 ;
struct V_63 * V_183 = NULL ;
int V_9 , V_49 ;
if ( V_156 -> type != V_176 )
return - V_14 ;
if ( F_118 ( & V_2 -> V_5 . V_85 ) )
return - V_92 ;
if ( V_177 -> V_66 == V_120 ) {
F_91 ( V_4 , & V_177 -> V_69 , & V_177 -> V_70 ,
NULL , & V_177 -> V_66 ,
V_121 ) ;
V_4 -> V_12 . V_71 = V_177 -> V_69 ;
V_4 -> V_12 . V_72 = V_177 -> V_70 ;
}
V_182 -> V_13 = F_91 ( V_4 , & V_177 -> V_69 , & V_177 -> V_70 ,
NULL , & V_177 -> V_66 ,
V_117 ) ;
if ( ! V_182 -> V_13 )
return - V_14 ;
F_119 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_88 ) {
V_168 -> V_101 = V_182 -> V_13 -> V_122 ;
V_168 -> V_69 = V_177 -> V_69 ;
V_168 -> V_70 = V_177 -> V_70 ;
F_112 ( V_2 ) ;
V_9 = F_107 ( V_4 , V_168 , & V_183 , true ) ;
F_113 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_177 -> V_69 = V_168 -> V_69 ;
V_177 -> V_70 = V_168 -> V_70 ;
}
F_114 ( V_182 -> V_13 , V_177 -> V_69 , V_177 -> V_70 , V_177 ) ;
for ( V_49 = 0 ; V_49 < V_182 -> V_13 -> V_184 ; V_49 ++ )
V_182 -> V_80 [ V_49 ] =
( V_177 -> V_69 * V_177 -> V_70 * V_182 -> V_13 -> V_75 [ V_49 ] ) / 8 ;
F_120 ( V_182 , V_177 -> V_69 , V_177 -> V_70 ) ;
if ( ! ( V_4 -> V_21 & V_128 ) )
F_121 ( V_182 , 0 , 0 , V_177 -> V_69 , V_177 -> V_70 ) ;
F_115 ( V_4 , F_92 ( V_182 -> V_13 -> V_118 ) ) ;
if ( ! V_2 -> V_5 . V_88 ) {
V_4 -> V_12 . V_13 = V_183 ;
F_120 ( & V_4 -> V_12 , V_177 -> V_69 , V_177 -> V_70 ) ;
F_121 ( & V_4 -> V_12 , 0 , 0 , V_177 -> V_69 , V_177 -> V_70 ) ;
}
return V_9 ;
}
static int F_122 ( struct V_90 * V_90 , void * V_146 ,
struct V_53 * V_156 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_117 ( V_2 , V_156 ) ;
}
static int F_123 ( struct V_90 * V_90 , void * V_146 ,
struct V_185 * V_49 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_163 * V_164 = V_2 -> V_10 . V_7 ;
if ( V_49 -> V_84 != 0 )
return - V_14 ;
V_49 -> type = V_186 ;
if ( V_164 )
F_124 ( V_49 -> V_149 , V_164 -> V_149 , sizeof( V_49 -> V_149 ) ) ;
return 0 ;
}
static int F_125 ( struct V_90 * V_90 , void * V_146 , unsigned int V_49 )
{
return V_49 == 0 ? V_49 : - V_14 ;
}
static int F_126 ( struct V_90 * V_90 , void * V_146 , unsigned int * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_166 V_187 , V_188 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_163 * V_164 ;
struct V_189 * V_103 ;
int V_9 ;
V_103 = F_128 ( & V_5 -> V_190 ) ;
if ( V_103 == NULL )
return - V_191 ;
V_164 = F_129 ( V_103 -> V_51 ) ;
while ( 1 ) {
V_103 = & V_164 -> V_51 . V_192 [ 0 ] ;
if ( ! ( V_103 -> V_8 & V_193 ) )
break;
if ( V_164 == V_2 -> V_5 . V_194 ) {
struct V_61 * V_182 = & V_5 -> V_4 -> V_12 ;
V_187 . V_169 . V_69 = V_182 -> V_71 ;
V_187 . V_169 . V_70 = V_182 -> V_72 ;
V_187 . V_169 . V_101 = V_182 -> V_13 ? V_182 -> V_13 -> V_122 : 0 ;
} else {
V_187 . V_103 = V_103 -> V_84 ;
V_187 . V_170 = V_171 ;
V_9 = F_108 ( V_164 , V_103 , V_195 , NULL , & V_187 ) ;
if ( V_9 < 0 && V_9 != - V_196 )
return - V_191 ;
}
V_103 = F_128 ( V_103 ) ;
if ( V_103 == NULL ||
F_130 ( V_103 -> V_51 ) != V_197 )
break;
V_164 = F_129 ( V_103 -> V_51 ) ;
V_188 . V_103 = V_103 -> V_84 ;
V_188 . V_170 = V_171 ;
V_9 = F_108 ( V_164 , V_103 , V_195 , NULL , & V_188 ) ;
if ( V_9 < 0 && V_9 != - V_196 )
return - V_191 ;
if ( V_188 . V_169 . V_69 != V_187 . V_169 . V_69 ||
V_188 . V_169 . V_70 != V_187 . V_169 . V_70 ||
V_188 . V_169 . V_101 != V_187 . V_169 . V_101 )
return - V_191 ;
}
return 0 ;
}
static int F_131 ( struct V_90 * V_90 , void * V_146 ,
enum V_198 type )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_199 * V_200 = & V_2 -> V_10 ;
int V_9 ;
if ( F_32 ( V_2 ) )
return - V_92 ;
F_132 ( & V_200 -> V_7 -> V_51 , V_200 -> V_201 ) ;
if ( V_2 -> V_5 . V_88 ) {
V_9 = F_127 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
return F_133 ( & V_2 -> V_5 . V_85 , type ) ;
}
static int F_134 ( struct V_90 * V_90 , void * V_146 ,
enum V_198 type )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_163 * V_164 = V_2 -> V_10 . V_7 ;
int V_9 ;
V_9 = F_135 ( & V_2 -> V_5 . V_85 , type ) ;
if ( V_9 == 0 )
F_136 ( & V_164 -> V_51 ) ;
return V_9 ;
}
static int F_137 ( struct V_90 * V_90 , void * V_146 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
int V_9 = F_138 ( & V_2 -> V_5 . V_85 , V_203 ) ;
if ( ! V_9 )
V_2 -> V_5 . V_47 = V_203 -> V_43 ;
return V_9 ;
}
static int F_139 ( struct V_90 * V_90 , void * V_146 ,
struct V_204 * V_26 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_140 ( & V_2 -> V_5 . V_85 , V_26 ) ;
}
static int F_141 ( struct V_90 * V_90 , void * V_146 ,
struct V_204 * V_26 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_142 ( & V_2 -> V_5 . V_85 , V_26 ) ;
}
static int F_143 ( struct V_90 * V_90 , void * V_146 ,
struct V_204 * V_26 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_144 ( & V_2 -> V_5 . V_85 , V_26 , V_90 -> V_205 & V_206 ) ;
}
static int F_145 ( struct V_90 * V_90 , void * V_146 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_146 ( & V_2 -> V_5 . V_85 , V_208 ) ;
}
static int F_147 ( struct V_90 * V_90 , void * V_146 ,
struct V_204 * V_209 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
return F_148 ( & V_2 -> V_5 . V_85 , V_209 ) ;
}
static int F_149 ( struct V_90 * V_90 , void * V_175 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_61 * V_156 = & V_4 -> V_12 ;
if ( V_211 -> type != V_176 )
return - V_14 ;
switch ( V_211 -> V_212 ) {
case V_213 :
case V_214 :
V_156 = & V_4 -> V_16 ;
case V_215 :
case V_216 :
V_211 -> V_132 . V_140 = 0 ;
V_211 -> V_132 . V_141 = 0 ;
V_211 -> V_132 . V_69 = V_156 -> V_217 ;
V_211 -> V_132 . V_70 = V_156 -> V_218 ;
return 0 ;
case V_219 :
V_156 = & V_4 -> V_16 ;
case V_220 :
V_211 -> V_132 . V_140 = V_156 -> V_221 ;
V_211 -> V_132 . V_141 = V_156 -> V_222 ;
V_211 -> V_132 . V_69 = V_156 -> V_69 ;
V_211 -> V_132 . V_70 = V_156 -> V_70 ;
return 0 ;
}
return - V_14 ;
}
int F_150 ( struct V_131 * V_223 , struct V_131 * V_209 )
{
if ( V_223 -> V_140 < V_209 -> V_140 || V_223 -> V_141 < V_209 -> V_141 )
return 0 ;
if ( V_223 -> V_140 + V_223 -> V_69 > V_209 -> V_140 + V_209 -> V_69 )
return 0 ;
if ( V_223 -> V_141 + V_223 -> V_70 > V_209 -> V_141 + V_209 -> V_70 )
return 0 ;
return 1 ;
}
static int F_151 ( struct V_90 * V_90 , void * V_175 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_131 V_224 = V_211 -> V_132 ;
struct V_61 * V_156 ;
unsigned long V_8 ;
unsigned int V_103 ;
if ( V_211 -> type != V_176 )
return - V_14 ;
switch ( V_211 -> V_212 ) {
case V_213 :
case V_214 :
case V_219 :
V_156 = & V_4 -> V_16 ;
V_103 = V_117 ;
break;
case V_215 :
case V_216 :
case V_220 :
V_156 = & V_4 -> V_12 ;
V_103 = V_121 ;
break;
default:
return - V_14 ;
}
F_99 ( V_4 , & V_224 , V_103 ) ;
if ( V_211 -> V_8 & V_225 &&
! F_150 ( & V_224 , & V_211 -> V_132 ) )
return - V_226 ;
if ( V_211 -> V_8 & V_227 &&
! F_150 ( & V_211 -> V_132 , & V_224 ) )
return - V_226 ;
V_211 -> V_132 = V_224 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_121 ( V_156 , V_211 -> V_132 . V_140 , V_211 -> V_132 . V_141 , V_211 -> V_132 . V_69 ,
V_211 -> V_132 . V_70 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
F_28 ( V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
static int F_152 ( struct V_228 * V_51 ,
const struct V_189 * V_229 ,
const struct V_189 * V_230 , T_1 V_8 )
{
struct V_163 * V_164 = F_129 ( V_51 ) ;
struct V_1 * V_2 = F_153 ( V_164 ) ;
if ( F_130 ( V_230 -> V_51 ) != V_197 )
return - V_14 ;
if ( F_69 ( V_2 == NULL ) )
return 0 ;
F_75 ( L_7 ,
V_229 -> V_51 -> V_149 , V_230 -> V_51 -> V_149 , V_8 ,
V_2 -> V_5 . V_231 ) ;
if ( V_8 & V_232 ) {
if ( V_2 -> V_5 . V_231 != 0 )
return - V_92 ;
V_2 -> V_5 . V_231 = V_164 -> V_233 ;
return 0 ;
}
V_2 -> V_5 . V_231 = 0 ;
return 0 ;
}
void F_154 ( struct V_163 * V_164 , unsigned int V_234 ,
void * V_235 )
{
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_236 * V_237 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( V_164 == NULL )
return;
V_7 = F_2 ( V_164 ) ;
V_237 = F_155 ( & V_164 -> V_51 ) ;
F_3 ( & V_237 -> V_15 , V_8 ) ;
V_2 = V_7 ? V_7 -> V_238 : NULL ;
if ( V_2 && V_235 && V_234 == V_239 &&
F_35 ( V_32 , & V_2 -> V_21 ) ) {
unsigned long V_240 ;
F_3 ( & V_2 -> V_15 , V_240 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_37 ) ) {
V_26 = F_156 ( V_2 -> V_5 . V_37 . V_241 ,
struct V_25 , V_242 ) ;
F_57 ( & V_26 -> V_35 , 0 , * ( ( T_1 * ) V_235 ) ) ;
}
F_157 ( V_2 , true ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_15 , V_240 ) ;
}
F_21 ( & V_237 -> V_15 , V_8 ) ;
}
static int F_158 ( struct V_163 * V_164 ,
struct V_243 * V_175 ,
struct V_244 * V_101 )
{
struct V_63 * V_13 ;
V_13 = F_52 ( NULL , NULL , V_67 , V_101 -> V_84 ) ;
if ( ! V_13 )
return - V_14 ;
V_101 -> V_101 = V_13 -> V_122 ;
return 0 ;
}
static int F_159 ( struct V_163 * V_164 ,
struct V_243 * V_175 ,
struct V_166 * V_13 )
{
struct V_1 * V_2 = F_153 ( V_164 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_159 * V_168 ;
struct V_61 * V_182 ;
if ( V_13 -> V_170 == V_172 ) {
V_168 = F_160 ( V_175 , V_13 -> V_103 ) ;
V_13 -> V_169 = * V_168 ;
return 0 ;
}
V_168 = & V_13 -> V_169 ;
V_168 -> V_245 = V_246 ;
V_182 = V_13 -> V_103 == V_121 ? & V_4 -> V_12 : & V_4 -> V_16 ;
F_65 ( & V_2 -> V_86 ) ;
if ( ! F_69 ( V_4 -> V_12 . V_13 == NULL ) )
V_168 -> V_101 = V_4 -> V_12 . V_13 -> V_122 ;
V_168 -> V_69 = V_182 -> V_71 ;
V_168 -> V_70 = V_182 -> V_72 ;
F_67 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_161 ( struct V_163 * V_164 ,
struct V_243 * V_175 ,
struct V_166 * V_13 )
{
struct V_1 * V_2 = F_153 ( V_164 ) ;
struct V_159 * V_168 = & V_13 -> V_169 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_61 * V_182 ;
struct V_63 * V_116 ;
F_75 ( L_8 ,
V_13 -> V_103 , V_168 -> V_101 , V_168 -> V_69 , V_168 -> V_70 ) ;
if ( V_13 -> V_103 == V_117 &&
F_118 ( & V_2 -> V_5 . V_85 ) )
return - V_92 ;
F_65 ( & V_2 -> V_86 ) ;
V_116 = F_91 ( V_4 , & V_168 -> V_69 , & V_168 -> V_70 ,
& V_168 -> V_101 , NULL , V_13 -> V_103 ) ;
F_67 ( & V_2 -> V_86 ) ;
V_168 -> V_245 = V_246 ;
if ( V_13 -> V_170 == V_172 ) {
V_168 = F_160 ( V_175 , V_13 -> V_103 ) ;
* V_168 = V_13 -> V_169 ;
return 0 ;
}
F_119 ( V_4 ) ;
F_115 ( V_4 , F_92 ( V_116 -> V_118 ) ) ;
V_182 = V_13 -> V_103 == V_121 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_65 ( & V_2 -> V_86 ) ;
F_120 ( V_182 , V_168 -> V_69 , V_168 -> V_70 ) ;
V_2 -> V_5 . V_168 = * V_168 ;
V_182 -> V_13 = V_116 ;
if ( ! ( V_13 -> V_103 == V_117 && ( V_4 -> V_21 & V_128 ) ) )
F_121 ( V_182 , 0 , 0 , V_168 -> V_69 , V_168 -> V_70 ) ;
if ( V_13 -> V_103 == V_121 )
V_4 -> V_21 &= ~ V_128 ;
F_67 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_162 ( struct V_163 * V_164 ,
struct V_243 * V_175 ,
struct V_247 * V_248 )
{
struct V_1 * V_2 = F_153 ( V_164 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_131 * V_132 = & V_248 -> V_224 ;
struct V_61 * V_182 ;
if ( V_248 -> V_170 == V_172 ) {
V_248 -> V_224 = * F_163 ( V_175 , V_248 -> V_103 ) ;
return 0 ;
}
V_182 = V_248 -> V_103 == V_121 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_65 ( & V_2 -> V_86 ) ;
V_132 -> V_140 = V_182 -> V_221 ;
V_132 -> V_141 = V_182 -> V_222 ;
V_132 -> V_69 = V_182 -> V_69 ;
V_132 -> V_70 = V_182 -> V_70 ;
F_67 ( & V_2 -> V_86 ) ;
F_75 ( L_9 ,
V_182 , V_248 -> V_103 , V_132 -> V_140 , V_132 -> V_141 , V_132 -> V_69 , V_132 -> V_70 ,
V_182 -> V_71 , V_182 -> V_72 ) ;
return 0 ;
}
static int F_164 ( struct V_163 * V_164 ,
struct V_243 * V_175 ,
struct V_247 * V_248 )
{
struct V_1 * V_2 = F_153 ( V_164 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_131 * V_132 = & V_248 -> V_224 ;
struct V_61 * V_182 ;
unsigned long V_8 ;
F_75 ( L_10 , V_132 -> V_140 , V_132 -> V_141 , V_132 -> V_69 , V_132 -> V_70 ) ;
V_182 = V_248 -> V_103 == V_117 ?
& V_4 -> V_16 : & V_4 -> V_12 ;
F_65 ( & V_2 -> V_86 ) ;
F_99 ( V_4 , V_132 , V_248 -> V_103 ) ;
if ( V_248 -> V_170 == V_172 ) {
F_67 ( & V_2 -> V_86 ) ;
* F_163 ( V_175 , V_248 -> V_103 ) = * V_132 ;
return 0 ;
}
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_121 ( V_182 , V_132 -> V_140 , V_132 -> V_141 , V_132 -> V_69 , V_132 -> V_70 ) ;
if ( V_248 -> V_103 == V_117 )
V_4 -> V_21 |= V_128 ;
F_28 ( V_20 , & V_2 -> V_21 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
F_75 ( L_11 , V_248 -> V_103 , V_132 -> V_140 , V_132 -> V_141 ,
V_132 -> V_69 , V_132 -> V_70 ) ;
F_67 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
struct V_163 * V_164 ;
int V_9 ;
V_164 = F_166 ( sizeof( * V_164 ) , V_251 ) ;
if ( ! V_164 )
return - V_252 ;
F_167 ( V_164 , & V_253 ) ;
V_164 -> V_8 = V_254 ;
snprintf ( V_164 -> V_149 , sizeof( V_164 -> V_149 ) , L_12 , V_2 -> V_94 -> V_255 ) ;
V_2 -> V_5 . V_256 [ V_121 ] . V_8 = V_193 ;
V_2 -> V_5 . V_256 [ V_117 ] . V_8 = V_257 ;
V_9 = F_168 ( & V_164 -> V_51 , V_258 ,
V_2 -> V_5 . V_256 , 0 ) ;
if ( V_9 )
goto V_259;
V_9 = F_169 ( V_250 , V_164 ) ;
if ( V_9 )
goto V_260;
V_2 -> V_5 . V_194 = V_164 ;
F_170 ( V_164 , V_2 ) ;
V_164 -> V_51 . V_261 = & V_262 ;
return 0 ;
V_260:
F_171 ( & V_164 -> V_51 ) ;
V_259:
F_172 ( V_164 ) ;
return V_9 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_163 * V_164 = V_2 -> V_5 . V_194 ;
if ( ! V_164 )
return;
F_171 ( & V_164 -> V_51 ) ;
F_174 ( V_164 ) ;
F_172 ( V_164 ) ;
V_2 -> V_5 . V_194 = NULL ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_53 V_13 = {
. type = V_176 ,
. V_13 . V_65 = {
. V_69 = 640 ,
. V_70 = 480 ,
. V_66 = V_263 ,
. V_264 = V_265 ,
. V_245 = V_246 ,
} ,
} ;
return F_117 ( V_2 , & V_13 ) ;
}
int F_175 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
struct V_266 * V_50 ;
struct V_23 * V_5 ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
int V_9 = - V_252 ;
V_4 = F_166 ( sizeof *V_4 , V_251 ) ;
if ( ! V_4 )
return - V_252 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_267 = V_268 ;
V_4 -> V_269 = V_270 ;
V_4 -> V_21 = V_271 ;
V_4 -> V_12 . V_13 = F_52 ( NULL , NULL , V_67 , 0 ) ;
V_4 -> V_16 . V_13 = F_52 ( NULL , NULL , V_67 , 0 ) ;
V_50 = F_176 () ;
if ( ! V_50 ) {
F_56 ( V_250 , L_13 ) ;
goto V_272;
}
snprintf ( V_50 -> V_149 , sizeof( V_50 -> V_149 ) , L_14 ,
F_177 ( & V_2 -> V_94 -> V_95 ) ) ;
V_50 -> V_273 = & V_274 ;
V_50 -> V_275 = & V_276 ;
V_50 -> V_250 = V_250 ;
V_50 -> V_277 = - 1 ;
V_50 -> V_278 = V_279 ;
V_50 -> V_86 = & V_2 -> V_86 ;
F_178 ( V_50 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_48 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_96 = 0 ;
F_48 ( & V_5 -> V_34 ) ;
F_48 ( & V_5 -> V_37 ) ;
F_179 ( & V_4 -> V_15 ) ;
V_5 -> V_4 = V_4 ;
V_42 = & V_2 -> V_5 . V_85 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> type = V_176 ;
V_42 -> V_280 = V_281 | V_282 ;
V_42 -> V_44 = V_2 -> V_5 . V_4 ;
V_42 -> V_261 = & V_283 ;
V_42 -> V_284 = & V_285 ;
V_42 -> V_286 = sizeof( struct V_25 ) ;
F_180 ( V_42 ) ;
V_2 -> V_5 . V_190 . V_8 = V_193 ;
V_9 = F_168 ( & V_50 -> V_51 , 1 , & V_2 -> V_5 . V_190 , 0 ) ;
if ( V_9 )
goto V_287;
V_9 = F_165 ( V_2 , V_250 ) ;
if ( V_9 )
goto V_288;
V_50 -> V_89 = & V_4 -> V_89 ;
return 0 ;
V_288:
F_171 ( & V_50 -> V_51 ) ;
V_287:
V_279 ( V_50 ) ;
V_272:
F_172 ( V_4 ) ;
return V_9 ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_266 * V_50 = V_2 -> V_5 . V_50 ;
if ( V_50 ) {
F_171 ( & V_50 -> V_51 ) ;
F_182 ( V_50 ) ;
}
F_173 ( V_2 ) ;
F_172 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
