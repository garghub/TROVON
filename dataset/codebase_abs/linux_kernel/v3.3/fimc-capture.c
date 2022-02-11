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
static unsigned int F_51 ( struct V_52 * V_53 , unsigned int V_54 )
{
if ( ! V_53 || V_54 >= V_53 -> V_13 -> V_55 )
return 0 ;
return V_53 -> V_56 * V_53 -> V_57 * V_53 -> V_13 -> V_58 [ V_54 ] / 8 ;
}
static int F_52 ( struct V_41 * V_59 , const struct V_60 * V_61 ,
unsigned int * V_62 , unsigned int * V_63 ,
unsigned int V_64 [] , void * V_65 [] )
{
struct V_3 * V_4 = V_59 -> V_44 ;
struct V_66 * V_13 = V_4 -> V_16 . V_13 ;
int V_49 ;
if ( ! V_13 )
return - V_14 ;
* V_63 = V_13 -> V_55 ;
for ( V_49 = 0 ; V_49 < V_13 -> V_55 ; V_49 ++ ) {
V_64 [ V_49 ] = F_51 ( & V_4 -> V_16 , V_49 ) ;
V_65 [ V_49 ] = V_4 -> V_1 -> V_67 ;
}
return 0 ;
}
static int F_53 ( struct V_68 * V_35 )
{
struct V_41 * V_59 = V_35 -> V_41 ;
struct V_3 * V_4 = V_59 -> V_44 ;
int V_49 ;
if ( V_4 -> V_16 . V_13 == NULL )
return - V_14 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_16 . V_13 -> V_55 ; V_49 ++ ) {
unsigned long V_69 = V_4 -> V_16 . V_70 [ V_49 ] ;
if ( F_54 ( V_35 , V_49 ) < V_69 ) {
F_55 ( V_4 -> V_1 -> V_5 . V_50 ,
L_1 ,
F_54 ( V_35 , V_49 ) , V_69 ) ;
return - V_14 ;
}
F_56 ( V_35 , V_49 , V_69 ) ;
}
return 0 ;
}
static void F_50 ( struct V_68 * V_35 )
{
struct V_25 * V_26
= F_57 ( V_35 , struct V_25 , V_35 ) ;
struct V_3 * V_4 = F_58 ( V_35 -> V_41 ) ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
unsigned long V_8 ;
int V_45 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_59 ( V_4 , & V_26 -> V_35 , & V_4 -> V_16 , & V_26 -> V_71 ) ;
if ( ! F_35 ( V_33 , & V_2 -> V_21 ) &&
! F_35 ( V_31 , & V_2 -> V_21 ) &&
V_5 -> V_48 < V_72 ) {
int V_73 = ( V_5 -> V_47 == 1 ) ? - 1 :
V_5 -> V_38 ;
F_60 ( V_2 , & V_26 -> V_71 , V_73 ) ;
V_26 -> V_74 = V_5 -> V_38 ;
F_61 ( V_5 , V_26 ) ;
if ( ++ V_5 -> V_38 >= V_72 )
V_5 -> V_38 = 0 ;
} else {
F_27 ( V_5 , V_26 ) ;
}
V_45 = V_5 -> V_47 > 1 ? 2 : 1 ;
if ( F_62 ( & V_5 -> V_75 ) &&
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
static void F_63 ( struct V_41 * V_59 )
{
struct V_3 * V_4 = F_58 ( V_59 ) ;
F_64 ( & V_4 -> V_1 -> V_76 ) ;
}
static void F_65 ( struct V_41 * V_59 )
{
struct V_3 * V_4 = F_58 ( V_59 ) ;
F_66 ( & V_4 -> V_1 -> V_76 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
struct V_23 * V_5 = & V_2 -> V_5 ;
int V_9 ;
if ( F_68 ( V_5 -> V_4 == NULL ) )
return - V_11 ;
if ( V_5 -> V_4 -> V_77 )
return 0 ;
V_9 = F_69 ( V_5 -> V_4 ) ;
if ( V_9 || V_5 -> V_78 )
return V_9 ;
return F_70 ( & V_5 -> V_4 -> V_79 ,
V_2 -> V_10 . V_7 -> V_79 ) ;
}
static int F_71 ( struct V_80 * V_80 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
int V_9 = F_73 ( V_80 ) ;
if ( V_9 )
return V_9 ;
F_74 ( L_2 , F_75 ( V_81 ) , V_2 -> V_21 ) ;
if ( F_76 ( V_2 ) )
return - V_82 ;
F_28 ( V_83 , & V_2 -> V_21 ) ;
F_77 ( & V_2 -> V_84 -> V_85 ) ;
if ( ++ V_2 -> V_5 . V_86 == 1 ) {
V_9 = F_49 ( V_2 ,
& V_2 -> V_5 . V_50 -> V_51 , true ) ;
if ( V_9 < 0 ) {
F_78 ( & V_2 -> V_84 -> V_85 ,
L_3 ) ;
F_79 ( & V_2 -> V_84 -> V_85 ) ;
V_2 -> V_5 . V_86 -- ;
F_80 ( V_80 ) ;
F_20 ( V_83 , & V_2 -> V_21 ) ;
return V_9 ;
}
V_9 = F_67 ( V_2 ) ;
if ( ! V_9 && ! V_2 -> V_5 . V_78 )
V_9 = F_81 ( V_2 ) ;
}
return V_9 ;
}
static int F_82 ( struct V_80 * V_80 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
F_74 ( L_2 , F_75 ( V_81 ) , V_2 -> V_21 ) ;
if ( -- V_2 -> V_5 . V_86 == 0 ) {
F_20 ( V_83 , & V_2 -> V_21 ) ;
F_31 ( V_2 , false ) ;
F_45 ( V_2 ) ;
F_20 ( V_33 , & V_2 -> V_21 ) ;
}
F_83 ( & V_2 -> V_84 -> V_85 ) ;
if ( V_2 -> V_5 . V_86 == 0 ) {
F_84 ( & V_2 -> V_5 . V_75 ) ;
F_85 ( V_2 -> V_5 . V_4 ) ;
}
return F_80 ( V_80 ) ;
}
static unsigned int F_86 ( struct V_80 * V_80 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_87 ( & V_2 -> V_5 . V_75 , V_80 , V_88 ) ;
}
static int F_88 ( struct V_80 * V_80 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_89 ( & V_2 -> V_5 . V_75 , V_90 ) ;
}
static struct V_66 * F_90 ( struct V_3 * V_4 ,
T_1 * V_91 , T_1 * V_92 ,
T_1 * V_93 , T_1 * V_94 , int V_95 )
{
bool V_96 = V_4 -> V_96 == 90 || V_4 -> V_96 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_97 * V_98 = V_2 -> V_18 ;
struct V_99 * V_100 = V_98 -> V_101 ;
struct V_52 * V_102 = & V_4 -> V_16 ;
T_1 V_58 , V_103 , V_104 , V_105 , V_106 = 3 ;
T_1 V_107 = V_108 ;
struct V_66 * V_109 ;
if ( V_93 && V_4 -> V_12 . V_13 && V_95 == V_110 &&
F_91 ( V_4 -> V_12 . V_13 -> V_111 ) )
* V_93 = V_112 ;
if ( V_94 && * V_94 != V_113 && V_95 != V_114 )
V_107 |= V_115 ;
V_109 = F_92 ( V_94 , V_93 , V_107 , 0 ) ;
if ( F_68 ( ! V_109 ) )
return NULL ;
if ( V_93 )
* V_93 = V_109 -> V_116 ;
if ( V_94 )
* V_94 = V_109 -> V_94 ;
if ( V_95 == V_114 ) {
V_104 = F_91 ( V_109 -> V_111 ) ?
V_100 -> V_117 : V_100 -> V_118 ;
F_93 ( V_91 , F_94 ( T_1 , * V_91 , 32 ) , V_104 , 4 ,
V_92 , F_94 ( T_1 , * V_92 , 32 ) ,
V_119 ,
F_91 ( V_109 -> V_111 ) ? 3 : 1 ,
0 ) ;
return V_109 ;
}
if ( F_91 ( V_109 -> V_111 ) ) {
* V_91 = V_4 -> V_12 . V_56 ;
* V_92 = V_4 -> V_12 . V_57 ;
return V_109 ;
}
V_104 = V_96 ? V_100 -> V_120 : V_100 -> V_121 ;
V_103 = V_4 -> V_21 & V_122 ? V_102 -> V_91 : V_98 -> V_123 ;
V_105 = V_4 -> V_21 & V_122 ? V_102 -> V_92 : V_98 -> V_123 ;
if ( V_98 -> V_124 == 1 && ! V_96 )
V_106 = F_95 ( V_109 -> V_111 ) ? 0 : 1 ;
V_58 = F_96 ( V_109 ) ;
F_93 ( V_91 , V_103 , V_104 ,
F_97 ( V_98 -> V_123 ) - 1 ,
V_92 , V_105 , V_119 ,
V_106 ,
64 / ( F_98 ( V_58 , 8 ) ) ) ;
F_74 ( L_4 ,
V_95 , V_93 ? * V_93 : 0 , * V_91 , * V_92 ,
V_102 -> V_56 , V_102 -> V_57 ) ;
return V_109 ;
}
static void F_99 ( struct V_3 * V_4 , struct V_125 * V_126 ,
int V_95 )
{
bool V_127 = V_4 -> V_96 == 90 || V_4 -> V_96 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_97 * V_98 = V_2 -> V_18 ;
struct V_99 * V_100 = V_98 -> V_101 ;
struct V_52 * V_128 = & V_4 -> V_12 ;
T_1 V_104 , V_129 , V_103 = 0 , V_105 = 0 , V_130 ;
T_1 V_131 = 0 , V_106 = 4 ;
T_1 V_132 , V_133 ;
if ( F_91 ( V_4 -> V_16 . V_13 -> V_111 ) ) {
V_126 -> V_91 = V_128 -> V_56 ;
V_126 -> V_92 = V_128 -> V_57 ;
V_126 -> V_134 = V_126 -> V_135 = 0 ;
return;
}
if ( V_95 == V_110 ) {
if ( V_4 -> V_96 != 90 && V_4 -> V_96 != 270 )
V_106 = 1 ;
V_132 = F_100 ( V_136 , 1 << ( F_97 ( V_128 -> V_91 ) - 3 ) ) ;
V_133 = F_100 ( V_137 , 1 << ( F_97 ( V_128 -> V_92 ) - 1 ) ) ;
V_130 = V_98 -> V_123 ;
} else {
T_1 V_58 = F_96 ( V_128 -> V_13 ) ;
V_131 = 64 / F_98 ( V_58 , 8 ) ;
V_130 = V_98 -> V_138 ;
V_103 = V_105 = V_130 ;
V_132 = V_133 = 1 ;
}
V_104 = F_101 ( T_1 ,
V_127 ? V_100 -> V_120 : V_100 -> V_121 ,
V_127 ? V_128 -> V_57 : V_128 -> V_56 ) ;
V_129 = F_101 ( T_1 , V_119 , V_128 -> V_57 ) ;
if ( V_95 == V_110 ) {
V_103 = F_101 ( T_1 , V_104 , V_128 -> V_56 / V_132 ) ;
V_105 = F_101 ( T_1 , V_129 , V_128 -> V_57 / V_133 ) ;
if ( V_127 ) {
F_102 ( V_132 , V_133 ) ;
F_102 ( V_103 , V_105 ) ;
}
}
F_93 ( & V_126 -> V_91 , V_103 , V_104 , F_97 ( V_130 ) - 1 ,
& V_126 -> V_92 , V_105 , V_129 , V_106 ,
V_131 ) ;
V_126 -> V_134 = F_103 ( T_1 , V_126 -> V_134 , 0 , V_128 -> V_56 - V_126 -> V_91 ) ;
V_126 -> V_135 = F_103 ( T_1 , V_126 -> V_135 , 0 , V_128 -> V_57 - V_126 -> V_92 ) ;
V_126 -> V_134 = F_104 ( V_126 -> V_134 , V_98 -> V_139 ) ;
F_74 ( L_5 ,
V_95 , V_126 -> V_134 , V_126 -> V_135 , V_126 -> V_91 , V_126 -> V_92 ,
V_128 -> V_56 , V_128 -> V_57 ) ;
}
static int F_105 ( struct V_80 * V_80 , void * V_140 ,
struct V_141 * V_24 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
strncpy ( V_24 -> V_142 , V_2 -> V_84 -> V_143 , sizeof( V_24 -> V_142 ) - 1 ) ;
strncpy ( V_24 -> V_144 , V_2 -> V_84 -> V_143 , sizeof( V_24 -> V_144 ) - 1 ) ;
V_24 -> V_145 [ 0 ] = 0 ;
V_24 -> V_146 = V_147 | V_148 ;
return 0 ;
}
static int F_106 ( struct V_80 * V_80 , void * V_140 ,
struct V_149 * V_150 )
{
struct V_66 * V_13 ;
V_13 = F_92 ( NULL , NULL , V_108 | V_115 ,
V_150 -> V_74 ) ;
if ( ! V_13 )
return - V_14 ;
strncpy ( V_150 -> V_151 , V_13 -> V_143 , sizeof( V_150 -> V_151 ) - 1 ) ;
V_150 -> V_152 = V_13 -> V_94 ;
if ( V_13 -> V_94 == V_112 )
V_150 -> V_8 |= V_153 ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 ,
struct V_154 * V_155 ,
struct V_66 * * V_156 ,
bool V_157 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_158 * V_159 = V_2 -> V_10 . V_7 ;
struct V_158 * V_160 = V_2 -> V_10 . V_160 ;
struct V_161 V_162 ;
struct V_154 * V_163 = & V_162 . V_164 ;
struct V_66 * V_109 = NULL ;
int V_9 , V_49 = 0 ;
if ( F_68 ( ! V_159 || ! V_155 ) )
return - V_14 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_164 = * V_155 ;
V_162 . V_165 = V_157 ? V_166 : V_167 ;
while ( 1 ) {
V_109 = F_92 ( NULL , V_163 -> V_93 != 0 ? & V_163 -> V_93 : NULL ,
V_108 , V_49 ++ ) ;
if ( V_109 == NULL ) {
return - V_14 ;
}
V_163 -> V_93 = V_155 -> V_93 = V_109 -> V_116 ;
V_9 = F_108 ( V_159 , V_95 , V_168 , NULL , & V_162 ) ;
if ( V_9 )
return V_9 ;
if ( V_163 -> V_93 != V_155 -> V_93 ) {
V_163 -> V_93 = 0 ;
continue;
}
if ( V_163 -> V_91 != V_155 -> V_91 || V_163 -> V_92 != V_155 -> V_92 ) {
T_1 V_169 = V_109 -> V_94 ;
V_155 -> V_91 = V_163 -> V_91 ;
V_155 -> V_92 = V_163 -> V_92 ;
V_109 = F_90 ( V_4 ,
& V_155 -> V_91 , & V_155 -> V_92 ,
NULL , & V_169 , V_110 ) ;
if ( V_109 && V_109 -> V_116 )
V_163 -> V_93 = V_109 -> V_116 ;
if ( V_163 -> V_91 != V_155 -> V_91 ||
V_163 -> V_92 != V_155 -> V_92 )
continue;
V_155 -> V_93 = V_163 -> V_93 ;
}
if ( V_160 )
V_9 = F_108 ( V_160 , V_95 , V_168 , NULL , & V_162 ) ;
if ( V_163 -> V_93 == V_155 -> V_93 &&
V_163 -> V_91 == V_155 -> V_91 && V_163 -> V_92 == V_155 -> V_92 )
break;
}
if ( V_156 && V_109 )
* V_156 = V_109 ;
* V_155 = * V_163 ;
F_74 ( L_6 , V_163 -> V_93 , V_163 -> V_91 , V_163 -> V_92 , V_109 ) ;
return 0 ;
}
static int F_109 ( struct V_80 * V_80 , void * V_170 ,
struct V_60 * V_150 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( V_150 -> type != V_171 )
return - V_14 ;
return F_110 ( & V_4 -> V_16 , V_150 ) ;
}
static int F_111 ( struct V_80 * V_80 , void * V_170 ,
struct V_60 * V_150 )
{
struct V_172 * V_173 = & V_150 -> V_13 . V_174 ;
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_154 V_163 ;
struct V_66 * V_109 = NULL ;
if ( V_150 -> type != V_171 )
return - V_14 ;
if ( V_173 -> V_152 == V_113 ) {
F_90 ( V_4 , & V_173 -> V_91 , & V_173 -> V_92 ,
NULL , & V_173 -> V_152 ,
V_114 ) ;
V_4 -> V_12 . V_56 = V_173 -> V_91 ;
V_4 -> V_12 . V_57 = V_173 -> V_92 ;
}
V_109 = F_90 ( V_4 , & V_173 -> V_91 , & V_173 -> V_92 ,
NULL , & V_173 -> V_152 ,
V_110 ) ;
if ( ! V_109 )
return - V_14 ;
if ( ! V_2 -> V_5 . V_78 ) {
V_163 . V_91 = V_173 -> V_91 ;
V_163 . V_92 = V_173 -> V_92 ;
V_163 . V_93 = V_109 -> V_116 ;
F_112 ( V_2 ) ;
F_107 ( V_4 , & V_163 , & V_109 , false ) ;
F_113 ( V_2 ) ;
V_173 -> V_91 = V_163 . V_91 ;
V_173 -> V_92 = V_163 . V_92 ;
if ( V_109 )
V_173 -> V_152 = V_109 -> V_94 ;
}
F_114 ( V_109 , V_173 -> V_91 , V_173 -> V_92 , V_173 ) ;
return 0 ;
}
static void F_115 ( struct V_3 * V_4 , bool V_175 )
{
V_4 -> V_176 . V_177 = ! V_175 ;
F_116 ( V_4 , ! V_175 ) ;
if ( V_175 )
F_28 ( V_178 , & V_4 -> V_1 -> V_21 ) ;
else
F_20 ( V_178 , & V_4 -> V_1 -> V_21 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_60 * V_150 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_172 * V_173 = & V_150 -> V_13 . V_174 ;
struct V_154 * V_163 = & V_2 -> V_5 . V_163 ;
struct V_52 * V_179 = & V_4 -> V_16 ;
struct V_66 * V_180 = NULL ;
int V_9 , V_49 ;
if ( V_150 -> type != V_171 )
return - V_14 ;
if ( F_118 ( & V_2 -> V_5 . V_75 ) )
return - V_82 ;
if ( V_173 -> V_152 == V_113 ) {
F_90 ( V_4 , & V_173 -> V_91 , & V_173 -> V_92 ,
NULL , & V_173 -> V_152 ,
V_114 ) ;
V_4 -> V_12 . V_56 = V_173 -> V_91 ;
V_4 -> V_12 . V_57 = V_173 -> V_92 ;
}
V_179 -> V_13 = F_90 ( V_4 , & V_173 -> V_91 , & V_173 -> V_92 ,
NULL , & V_173 -> V_152 ,
V_110 ) ;
if ( ! V_179 -> V_13 )
return - V_14 ;
F_119 ( V_4 ) ;
if ( ! V_2 -> V_5 . V_78 ) {
V_163 -> V_93 = V_179 -> V_13 -> V_116 ;
V_163 -> V_91 = V_173 -> V_91 ;
V_163 -> V_92 = V_173 -> V_92 ;
F_112 ( V_2 ) ;
V_9 = F_107 ( V_4 , V_163 , & V_180 , true ) ;
F_113 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_173 -> V_91 = V_163 -> V_91 ;
V_173 -> V_92 = V_163 -> V_92 ;
}
F_114 ( V_179 -> V_13 , V_173 -> V_91 , V_173 -> V_92 , V_173 ) ;
for ( V_49 = 0 ; V_49 < V_179 -> V_13 -> V_181 ; V_49 ++ )
V_179 -> V_70 [ V_49 ] =
( V_173 -> V_91 * V_173 -> V_92 * V_179 -> V_13 -> V_58 [ V_49 ] ) / 8 ;
F_120 ( V_179 , V_173 -> V_91 , V_173 -> V_92 ) ;
if ( ! ( V_4 -> V_21 & V_122 ) )
F_121 ( V_179 , 0 , 0 , V_173 -> V_91 , V_173 -> V_92 ) ;
F_115 ( V_4 , F_91 ( V_179 -> V_13 -> V_111 ) ) ;
if ( ! V_2 -> V_5 . V_78 ) {
V_4 -> V_12 . V_13 = V_180 ;
F_120 ( & V_4 -> V_12 , V_173 -> V_91 , V_173 -> V_92 ) ;
F_121 ( & V_4 -> V_12 , 0 , 0 , V_173 -> V_91 , V_173 -> V_92 ) ;
}
return V_9 ;
}
static int F_122 ( struct V_80 * V_80 , void * V_140 ,
struct V_60 * V_150 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_117 ( V_2 , V_150 ) ;
}
static int F_123 ( struct V_80 * V_80 , void * V_140 ,
struct V_182 * V_49 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_158 * V_159 = V_2 -> V_10 . V_7 ;
if ( V_49 -> V_74 != 0 )
return - V_14 ;
V_49 -> type = V_183 ;
if ( V_159 )
F_124 ( V_49 -> V_143 , V_159 -> V_143 , sizeof( V_49 -> V_143 ) ) ;
return 0 ;
}
static int F_125 ( struct V_80 * V_80 , void * V_140 , unsigned int V_49 )
{
return V_49 == 0 ? V_49 : - V_14 ;
}
static int F_126 ( struct V_80 * V_80 , void * V_140 , unsigned int * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_161 V_184 , V_185 ;
struct V_23 * V_5 = & V_2 -> V_5 ;
struct V_158 * V_159 ;
struct V_186 * V_95 ;
int V_9 ;
V_95 = F_128 ( & V_5 -> V_187 ) ;
if ( V_95 == NULL )
return - V_188 ;
V_159 = F_129 ( V_95 -> V_51 ) ;
while ( 1 ) {
V_95 = & V_159 -> V_51 . V_189 [ 0 ] ;
if ( ! ( V_95 -> V_8 & V_190 ) )
break;
if ( V_159 == V_2 -> V_5 . V_191 ) {
struct V_52 * V_179 = & V_5 -> V_4 -> V_12 ;
V_184 . V_164 . V_91 = V_179 -> V_56 ;
V_184 . V_164 . V_92 = V_179 -> V_57 ;
V_184 . V_164 . V_93 = V_179 -> V_13 ? V_179 -> V_13 -> V_116 : 0 ;
} else {
V_184 . V_95 = V_95 -> V_74 ;
V_184 . V_165 = V_166 ;
V_9 = F_108 ( V_159 , V_95 , V_192 , NULL , & V_184 ) ;
if ( V_9 < 0 && V_9 != - V_193 )
return - V_188 ;
}
V_95 = F_128 ( V_95 ) ;
if ( V_95 == NULL ||
F_130 ( V_95 -> V_51 ) != V_194 )
break;
V_159 = F_129 ( V_95 -> V_51 ) ;
V_185 . V_95 = V_95 -> V_74 ;
V_185 . V_165 = V_166 ;
V_9 = F_108 ( V_159 , V_95 , V_192 , NULL , & V_185 ) ;
if ( V_9 < 0 && V_9 != - V_193 )
return - V_188 ;
if ( V_185 . V_164 . V_91 != V_184 . V_164 . V_91 ||
V_185 . V_164 . V_92 != V_184 . V_164 . V_92 ||
V_185 . V_164 . V_93 != V_184 . V_164 . V_93 )
return - V_188 ;
}
return 0 ;
}
static int F_131 ( struct V_80 * V_80 , void * V_140 ,
enum V_195 type )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_196 * V_197 = & V_2 -> V_10 ;
int V_9 ;
if ( F_32 ( V_2 ) )
return - V_82 ;
F_132 ( & V_197 -> V_7 -> V_51 , V_197 -> V_198 ) ;
if ( V_2 -> V_5 . V_78 ) {
V_9 = F_127 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
return F_133 ( & V_2 -> V_5 . V_75 , type ) ;
}
static int F_134 ( struct V_80 * V_80 , void * V_140 ,
enum V_195 type )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_158 * V_159 = V_2 -> V_10 . V_7 ;
int V_9 ;
V_9 = F_135 ( & V_2 -> V_5 . V_75 , type ) ;
if ( V_9 == 0 )
F_136 ( & V_159 -> V_51 ) ;
return V_9 ;
}
static int F_137 ( struct V_80 * V_80 , void * V_140 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
int V_9 = F_138 ( & V_2 -> V_5 . V_75 , V_200 ) ;
if ( ! V_9 )
V_2 -> V_5 . V_47 = V_200 -> V_43 ;
return V_9 ;
}
static int F_139 ( struct V_80 * V_80 , void * V_140 ,
struct V_201 * V_26 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_140 ( & V_2 -> V_5 . V_75 , V_26 ) ;
}
static int F_141 ( struct V_80 * V_80 , void * V_140 ,
struct V_201 * V_26 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_142 ( & V_2 -> V_5 . V_75 , V_26 ) ;
}
static int F_143 ( struct V_80 * V_80 , void * V_140 ,
struct V_201 * V_26 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
return F_144 ( & V_2 -> V_5 . V_75 , V_26 , V_80 -> V_202 & V_203 ) ;
}
static int F_145 ( struct V_80 * V_80 , void * V_170 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_52 * V_150 = & V_2 -> V_5 . V_4 -> V_12 ;
if ( V_205 -> type != V_171 )
return - V_14 ;
V_205 -> V_206 . V_134 = 0 ;
V_205 -> V_206 . V_135 = 0 ;
V_205 -> V_206 . V_91 = V_150 -> V_207 ;
V_205 -> V_206 . V_92 = V_150 -> V_208 ;
V_205 -> V_209 = V_205 -> V_206 ;
return 0 ;
}
static int F_146 ( struct V_80 * V_80 , void * V_170 , struct V_210 * V_205 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_52 * V_150 = & V_2 -> V_5 . V_4 -> V_12 ;
V_205 -> V_211 . V_134 = V_150 -> V_212 ;
V_205 -> V_211 . V_135 = V_150 -> V_213 ;
V_205 -> V_211 . V_91 = V_150 -> V_91 ;
V_205 -> V_211 . V_92 = V_150 -> V_92 ;
return 0 ;
}
static int F_147 ( struct V_80 * V_80 , void * V_170 , struct V_210 * V_205 )
{
struct V_1 * V_2 = F_72 ( V_80 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_52 * V_179 ;
unsigned long V_8 ;
F_99 ( V_4 , & V_205 -> V_211 , V_114 ) ;
V_179 = & V_4 -> V_12 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_121 ( V_179 , V_205 -> V_211 . V_134 , V_205 -> V_211 . V_135 , V_205 -> V_211 . V_91 , V_205 -> V_211 . V_92 ) ;
F_28 ( V_20 , & V_2 -> V_21 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
return 0 ;
}
static int F_148 ( struct V_214 * V_51 ,
const struct V_186 * V_215 ,
const struct V_186 * V_216 , T_1 V_8 )
{
struct V_158 * V_159 = F_129 ( V_51 ) ;
struct V_1 * V_2 = F_149 ( V_159 ) ;
if ( F_130 ( V_216 -> V_51 ) != V_194 )
return - V_14 ;
if ( F_68 ( V_2 == NULL ) )
return 0 ;
F_74 ( L_7 ,
V_215 -> V_51 -> V_143 , V_216 -> V_51 -> V_143 , V_8 ,
V_2 -> V_5 . V_217 ) ;
if ( V_8 & V_218 ) {
if ( V_2 -> V_5 . V_217 != 0 )
return - V_82 ;
V_2 -> V_5 . V_217 = V_159 -> V_219 ;
return 0 ;
}
V_2 -> V_5 . V_217 = 0 ;
return 0 ;
}
void F_150 ( struct V_158 * V_159 , unsigned int V_220 ,
void * V_221 )
{
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_222 * V_223 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( V_159 == NULL )
return;
V_7 = F_2 ( V_159 ) ;
V_223 = F_151 ( & V_159 -> V_51 ) ;
F_3 ( & V_223 -> V_15 , V_8 ) ;
V_2 = V_7 ? V_7 -> V_224 : NULL ;
if ( V_2 && V_221 && V_220 == V_225 &&
F_35 ( V_32 , & V_2 -> V_21 ) ) {
unsigned long V_226 ;
F_3 ( & V_2 -> V_15 , V_226 ) ;
if ( ! F_23 ( & V_2 -> V_5 . V_37 ) ) {
V_26 = F_152 ( V_2 -> V_5 . V_37 . V_227 ,
struct V_25 , V_228 ) ;
F_56 ( & V_26 -> V_35 , 0 , * ( ( T_1 * ) V_221 ) ) ;
}
F_153 ( V_2 , true ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_15 , V_226 ) ;
}
F_21 ( & V_223 -> V_15 , V_8 ) ;
}
static int F_154 ( struct V_158 * V_159 ,
struct V_229 * V_170 ,
struct V_230 * V_93 )
{
struct V_66 * V_13 ;
V_13 = F_92 ( NULL , NULL , V_108 , V_93 -> V_74 ) ;
if ( ! V_13 )
return - V_14 ;
V_93 -> V_93 = V_13 -> V_116 ;
return 0 ;
}
static int F_155 ( struct V_158 * V_159 ,
struct V_229 * V_170 ,
struct V_161 * V_13 )
{
struct V_1 * V_2 = F_149 ( V_159 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_154 * V_163 ;
struct V_52 * V_179 ;
if ( V_13 -> V_165 == V_167 ) {
V_163 = F_156 ( V_170 , V_13 -> V_95 ) ;
V_13 -> V_164 = * V_163 ;
return 0 ;
}
V_163 = & V_13 -> V_164 ;
V_163 -> V_231 = V_232 ;
V_179 = V_13 -> V_95 == V_114 ? & V_4 -> V_12 : & V_4 -> V_16 ;
F_64 ( & V_2 -> V_76 ) ;
if ( ! F_68 ( V_4 -> V_12 . V_13 == NULL ) )
V_163 -> V_93 = V_4 -> V_12 . V_13 -> V_116 ;
V_163 -> V_91 = V_179 -> V_56 ;
V_163 -> V_92 = V_179 -> V_57 ;
F_66 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_157 ( struct V_158 * V_159 ,
struct V_229 * V_170 ,
struct V_161 * V_13 )
{
struct V_1 * V_2 = F_149 ( V_159 ) ;
struct V_154 * V_163 = & V_13 -> V_164 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_52 * V_179 ;
struct V_66 * V_109 ;
F_74 ( L_8 ,
V_13 -> V_95 , V_163 -> V_93 , V_163 -> V_91 , V_163 -> V_92 ) ;
if ( V_13 -> V_95 == V_110 &&
F_118 ( & V_2 -> V_5 . V_75 ) )
return - V_82 ;
F_64 ( & V_2 -> V_76 ) ;
V_109 = F_90 ( V_4 , & V_163 -> V_91 , & V_163 -> V_92 ,
& V_163 -> V_93 , NULL , V_13 -> V_95 ) ;
F_66 ( & V_2 -> V_76 ) ;
V_163 -> V_231 = V_232 ;
if ( V_13 -> V_165 == V_167 ) {
V_163 = F_156 ( V_170 , V_13 -> V_95 ) ;
* V_163 = V_13 -> V_164 ;
return 0 ;
}
F_119 ( V_4 ) ;
F_115 ( V_4 , F_91 ( V_109 -> V_111 ) ) ;
V_179 = V_13 -> V_95 == V_114 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_64 ( & V_2 -> V_76 ) ;
F_120 ( V_179 , V_163 -> V_91 , V_163 -> V_92 ) ;
V_2 -> V_5 . V_163 = * V_163 ;
V_179 -> V_13 = V_109 ;
if ( ! ( V_13 -> V_95 == V_110 && ( V_4 -> V_21 & V_122 ) ) )
F_121 ( V_179 , 0 , 0 , V_163 -> V_91 , V_163 -> V_92 ) ;
if ( V_13 -> V_95 == V_114 )
V_4 -> V_21 &= ~ V_122 ;
F_66 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_158 ( struct V_158 * V_159 ,
struct V_229 * V_170 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = F_149 ( V_159 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_125 * V_126 = & V_234 -> V_235 ;
struct V_52 * V_179 ;
if ( V_234 -> V_165 == V_167 ) {
V_234 -> V_235 = * F_159 ( V_170 , V_234 -> V_95 ) ;
return 0 ;
}
V_179 = V_234 -> V_95 == V_114 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_64 ( & V_2 -> V_76 ) ;
V_126 -> V_134 = V_179 -> V_212 ;
V_126 -> V_135 = V_179 -> V_213 ;
V_126 -> V_91 = V_179 -> V_91 ;
V_126 -> V_92 = V_179 -> V_92 ;
F_66 ( & V_2 -> V_76 ) ;
F_74 ( L_9 ,
V_179 , V_234 -> V_95 , V_126 -> V_134 , V_126 -> V_135 , V_126 -> V_91 , V_126 -> V_92 ,
V_179 -> V_56 , V_179 -> V_57 ) ;
return 0 ;
}
static int F_160 ( struct V_158 * V_159 ,
struct V_229 * V_170 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = F_149 ( V_159 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_125 * V_126 = & V_234 -> V_235 ;
struct V_52 * V_179 ;
unsigned long V_8 ;
F_74 ( L_10 , V_126 -> V_134 , V_126 -> V_135 , V_126 -> V_91 , V_126 -> V_92 ) ;
V_179 = V_234 -> V_95 == V_110 ?
& V_4 -> V_16 : & V_4 -> V_12 ;
F_64 ( & V_2 -> V_76 ) ;
F_99 ( V_4 , V_126 , V_234 -> V_95 ) ;
if ( V_234 -> V_165 == V_167 ) {
F_64 ( & V_2 -> V_76 ) ;
* F_159 ( V_170 , V_234 -> V_95 ) = * V_126 ;
return 0 ;
}
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_121 ( V_179 , V_126 -> V_134 , V_126 -> V_135 , V_126 -> V_91 , V_126 -> V_92 ) ;
if ( V_234 -> V_95 == V_110 )
V_4 -> V_21 |= V_122 ;
F_28 ( V_20 , & V_2 -> V_21 ) ;
F_21 ( & V_2 -> V_15 , V_8 ) ;
F_74 ( L_11 , V_234 -> V_95 , V_126 -> V_134 , V_126 -> V_135 ,
V_126 -> V_91 , V_126 -> V_92 ) ;
F_66 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_236 * V_237 )
{
struct V_158 * V_159 ;
int V_9 ;
V_159 = F_162 ( sizeof( * V_159 ) , V_238 ) ;
if ( ! V_159 )
return - V_239 ;
F_163 ( V_159 , & V_240 ) ;
V_159 -> V_8 = V_241 ;
snprintf ( V_159 -> V_143 , sizeof( V_159 -> V_143 ) , L_12 , V_2 -> V_84 -> V_242 ) ;
V_2 -> V_5 . V_243 [ V_114 ] . V_8 = V_190 ;
V_2 -> V_5 . V_243 [ V_110 ] . V_8 = V_244 ;
V_9 = F_164 ( & V_159 -> V_51 , V_245 ,
V_2 -> V_5 . V_243 , 0 ) ;
if ( V_9 )
goto V_246;
V_9 = F_165 ( V_237 , V_159 ) ;
if ( V_9 )
goto V_247;
V_2 -> V_5 . V_191 = V_159 ;
F_166 ( V_159 , V_2 ) ;
V_159 -> V_51 . V_248 = & V_249 ;
return 0 ;
V_247:
F_167 ( & V_159 -> V_51 ) ;
V_246:
F_168 ( V_159 ) ;
return V_9 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_158 * V_159 = V_2 -> V_5 . V_191 ;
if ( ! V_159 )
return;
F_167 ( & V_159 -> V_51 ) ;
F_170 ( V_159 ) ;
F_168 ( V_159 ) ;
V_2 -> V_5 . V_191 = NULL ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_60 V_13 = {
. type = V_171 ,
. V_13 . V_174 = {
. V_91 = 640 ,
. V_92 = 480 ,
. V_152 = V_250 ,
. V_251 = V_252 ,
. V_231 = V_232 ,
} ,
} ;
return F_117 ( V_2 , & V_13 ) ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_236 * V_237 )
{
struct V_253 * V_50 ;
struct V_23 * V_5 ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
int V_9 = - V_239 ;
V_4 = F_162 ( sizeof *V_4 , V_238 ) ;
if ( ! V_4 )
return - V_239 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_254 = V_255 ;
V_4 -> V_256 = V_257 ;
V_4 -> V_21 = V_258 ;
V_4 -> V_12 . V_13 = F_92 ( NULL , NULL , V_108 , 0 ) ;
V_4 -> V_16 . V_13 = F_92 ( NULL , NULL , V_108 , 0 ) ;
V_50 = F_172 () ;
if ( ! V_50 ) {
F_55 ( V_237 , L_13 ) ;
goto V_259;
}
snprintf ( V_50 -> V_143 , sizeof( V_50 -> V_143 ) , L_14 ,
F_173 ( & V_2 -> V_84 -> V_85 ) ) ;
V_50 -> V_260 = & V_261 ;
V_50 -> V_262 = & V_263 ;
V_50 -> V_237 = V_237 ;
V_50 -> V_264 = - 1 ;
V_50 -> V_265 = V_266 ;
V_50 -> V_76 = & V_2 -> V_76 ;
F_174 ( V_50 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_48 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_86 = 0 ;
F_48 ( & V_5 -> V_34 ) ;
F_48 ( & V_5 -> V_37 ) ;
F_175 ( & V_4 -> V_15 ) ;
V_5 -> V_4 = V_4 ;
V_42 = & V_2 -> V_5 . V_75 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> type = V_171 ;
V_42 -> V_267 = V_268 | V_269 ;
V_42 -> V_44 = V_2 -> V_5 . V_4 ;
V_42 -> V_248 = & V_270 ;
V_42 -> V_271 = & V_272 ;
V_42 -> V_273 = sizeof( struct V_25 ) ;
F_176 ( V_42 ) ;
V_2 -> V_5 . V_187 . V_8 = V_190 ;
V_9 = F_164 ( & V_50 -> V_51 , 1 , & V_2 -> V_5 . V_187 , 0 ) ;
if ( V_9 )
goto V_274;
V_9 = F_161 ( V_2 , V_237 ) ;
if ( V_9 )
goto V_275;
V_50 -> V_79 = & V_4 -> V_79 ;
return 0 ;
V_275:
F_167 ( & V_50 -> V_51 ) ;
V_274:
V_266 ( V_50 ) ;
V_259:
F_168 ( V_4 ) ;
return V_9 ;
}
void F_177 ( struct V_1 * V_2 )
{
struct V_253 * V_50 = V_2 -> V_5 . V_50 ;
if ( V_50 ) {
F_167 ( & V_50 -> V_51 ) ;
F_178 ( V_50 ) ;
}
F_169 ( V_2 ) ;
F_168 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
