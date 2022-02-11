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
F_19 ( V_18 , & V_2 -> V_19 ) ;
}
F_20 ( & V_2 -> V_15 , V_8 ) ;
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 , bool V_20 )
{
struct V_21 * V_22 = & V_2 -> V_5 ;
struct V_23 * V_24 ;
unsigned long V_8 ;
bool V_25 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
V_25 = V_2 -> V_19 & ( 1 << V_26 ) ;
V_2 -> V_19 &= ~ ( 1 << V_27 | 1 << V_28 |
1 << V_29 | 1 << V_26 ) ;
if ( ! V_20 )
V_2 -> V_19 &= ~ ( 1 << V_30 | 1 << V_31 ) ;
while ( ! V_20 && ! F_22 ( & V_22 -> V_32 ) ) {
V_24 = F_23 ( V_22 ) ;
F_24 ( & V_24 -> V_33 , V_34 ) ;
}
while ( ! F_22 ( & V_22 -> V_35 ) ) {
V_24 = F_25 ( V_22 ) ;
if ( V_20 )
F_26 ( V_22 , V_24 ) ;
else
F_24 ( & V_24 -> V_33 , V_34 ) ;
}
F_27 ( V_31 , & V_2 -> V_19 ) ;
F_28 ( V_2 ) ;
V_22 -> V_36 = 0 ;
F_20 ( & V_2 -> V_15 , V_8 ) ;
if ( V_25 )
return F_29 ( V_2 , 0 ) ;
else
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , bool V_20 )
{
unsigned long V_8 ;
if ( ! F_31 ( V_2 ) )
return 0 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_27 ( V_28 , & V_2 -> V_19 ) ;
F_32 ( V_2 ) ;
F_20 ( & V_2 -> V_15 , V_8 ) ;
F_33 ( V_2 -> V_37 ,
! F_34 ( V_28 , & V_2 -> V_19 ) ,
( 2 * V_38 / 10 ) ) ;
return F_21 ( V_2 , V_20 ) ;
}
int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
int V_9 ;
if ( ! F_34 ( V_18 , & V_2 -> V_19 ) )
return 0 ;
F_36 ( & V_4 -> V_15 ) ;
F_9 ( V_2 , & V_4 -> V_12 ) ;
V_9 = F_10 ( V_4 ) ;
if ( V_9 == 0 ) {
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_4 ( V_4 , & V_4 -> V_16 ) ;
F_18 ( V_4 ) ;
F_19 ( V_18 , & V_2 -> V_19 ) ;
}
F_37 ( & V_4 -> V_15 ) ;
return V_9 ;
}
static int F_38 ( struct V_39 * V_40 , unsigned int V_41 )
{
struct V_3 * V_4 = V_40 -> V_42 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_21 * V_5 = & V_2 -> V_5 ;
int V_43 ;
int V_9 ;
V_5 -> V_44 = 0 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
goto error;
F_27 ( V_30 , & V_2 -> V_19 ) ;
V_43 = V_2 -> V_5 . V_45 > 1 ? 2 : 1 ;
if ( V_5 -> V_46 >= V_43 &&
! F_39 ( V_29 , & V_2 -> V_19 ) ) {
F_40 ( V_4 ) ;
if ( ! F_39 ( V_26 , & V_2 -> V_19 ) )
F_29 ( V_2 , 1 ) ;
}
return 0 ;
error:
F_21 ( V_2 , false ) ;
return V_9 ;
}
static int F_41 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_42 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_31 ( V_2 ) )
return - V_14 ;
return F_30 ( V_2 , false ) ;
}
int F_42 ( struct V_1 * V_2 )
{
bool V_20 = F_43 ( V_2 ) ;
int V_9 = F_30 ( V_2 , V_20 ) ;
if ( V_9 )
return V_9 ;
return F_44 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_21 * V_5 = & V_2 -> V_5 ;
struct V_23 * V_24 ;
int V_47 ;
if ( ! F_46 ( V_31 , & V_2 -> V_19 ) )
return 0 ;
F_47 ( & V_2 -> V_5 . V_35 ) ;
V_5 -> V_36 = 0 ;
F_48 ( V_2 , & V_2 -> V_5 . V_48 -> V_49 ,
false ) ;
F_1 ( V_2 ) ;
F_19 ( V_31 , & V_2 -> V_19 ) ;
for ( V_47 = 0 ; V_47 < V_5 -> V_45 ; V_47 ++ ) {
if ( F_22 ( & V_5 -> V_32 ) )
break;
V_24 = F_23 ( V_5 ) ;
F_49 ( & V_24 -> V_33 ) ;
}
return 0 ;
}
static unsigned int F_50 ( struct V_50 * V_51 , unsigned int V_52 )
{
if ( ! V_51 || V_52 >= V_51 -> V_13 -> V_53 )
return 0 ;
return V_51 -> V_54 * V_51 -> V_55 * V_51 -> V_13 -> V_56 [ V_52 ] / 8 ;
}
static int F_51 ( struct V_39 * V_57 , const struct V_58 * V_59 ,
unsigned int * V_60 , unsigned int * V_61 ,
unsigned int V_62 [] , void * V_63 [] )
{
struct V_3 * V_4 = V_57 -> V_42 ;
struct V_64 * V_13 = V_4 -> V_16 . V_13 ;
int V_47 ;
if ( ! V_13 )
return - V_14 ;
* V_61 = V_13 -> V_53 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_53 ; V_47 ++ ) {
V_62 [ V_47 ] = F_50 ( & V_4 -> V_16 , V_47 ) ;
V_63 [ V_47 ] = V_4 -> V_1 -> V_65 ;
}
return 0 ;
}
static int F_52 ( struct V_66 * V_33 )
{
struct V_39 * V_57 = V_33 -> V_39 ;
struct V_3 * V_4 = V_57 -> V_42 ;
int V_47 ;
if ( V_4 -> V_16 . V_13 == NULL )
return - V_14 ;
for ( V_47 = 0 ; V_47 < V_4 -> V_16 . V_13 -> V_53 ; V_47 ++ ) {
unsigned long V_67 = V_4 -> V_16 . V_68 [ V_47 ] ;
if ( F_53 ( V_33 , V_47 ) < V_67 ) {
F_54 ( V_4 -> V_1 -> V_5 . V_48 ,
L_1 ,
F_53 ( V_33 , V_47 ) , V_67 ) ;
return - V_14 ;
}
F_55 ( V_33 , V_47 , V_67 ) ;
}
return 0 ;
}
static void F_49 ( struct V_66 * V_33 )
{
struct V_23 * V_24
= F_56 ( V_33 , struct V_23 , V_33 ) ;
struct V_3 * V_4 = F_57 ( V_33 -> V_39 ) ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_21 * V_5 = & V_2 -> V_5 ;
unsigned long V_8 ;
int V_43 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_58 ( V_4 , & V_24 -> V_33 , & V_4 -> V_16 , & V_24 -> V_69 ) ;
if ( ! F_34 ( V_31 , & V_2 -> V_19 ) &&
! F_34 ( V_29 , & V_2 -> V_19 ) &&
V_5 -> V_46 < V_70 ) {
int V_71 = ( V_5 -> V_45 == 1 ) ? - 1 :
V_5 -> V_36 ;
F_59 ( V_2 , & V_24 -> V_69 , V_71 ) ;
V_24 -> V_72 = V_5 -> V_36 ;
F_60 ( V_5 , V_24 ) ;
if ( ++ V_5 -> V_36 >= V_70 )
V_5 -> V_36 = 0 ;
} else {
F_26 ( V_5 , V_24 ) ;
}
V_43 = V_5 -> V_45 > 1 ? 2 : 1 ;
if ( F_61 ( & V_5 -> V_73 ) &&
V_5 -> V_46 >= V_43 &&
! F_39 ( V_29 , & V_2 -> V_19 ) ) {
F_40 ( V_4 ) ;
F_20 ( & V_2 -> V_15 , V_8 ) ;
if ( ! F_39 ( V_26 , & V_2 -> V_19 ) )
F_29 ( V_2 , 1 ) ;
return;
}
F_20 ( & V_2 -> V_15 , V_8 ) ;
}
static void F_62 ( struct V_39 * V_57 )
{
struct V_3 * V_4 = F_57 ( V_57 ) ;
F_63 ( & V_4 -> V_1 -> V_74 ) ;
}
static void F_64 ( struct V_39 * V_57 )
{
struct V_3 * V_4 = F_57 ( V_57 ) ;
F_65 ( & V_4 -> V_1 -> V_74 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_21 * V_5 = & V_2 -> V_5 ;
int V_9 ;
if ( F_67 ( V_5 -> V_4 == NULL ) )
return - V_11 ;
if ( V_5 -> V_4 -> V_75 )
return 0 ;
V_9 = F_68 ( V_5 -> V_4 ) ;
if ( V_9 || V_5 -> V_76 )
return V_9 ;
return F_69 ( & V_5 -> V_4 -> V_77 ,
V_2 -> V_10 . V_7 -> V_77 ) ;
}
static int F_70 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
int V_9 = F_72 ( V_78 ) ;
if ( V_9 )
return V_9 ;
F_73 ( L_2 , F_74 ( V_79 ) , V_2 -> V_19 ) ;
if ( F_75 ( V_2 ) )
return - V_80 ;
F_27 ( V_81 , & V_2 -> V_19 ) ;
F_76 ( & V_2 -> V_82 -> V_83 ) ;
if ( ++ V_2 -> V_5 . V_84 == 1 ) {
V_9 = F_48 ( V_2 ,
& V_2 -> V_5 . V_48 -> V_49 , true ) ;
if ( V_9 < 0 ) {
F_77 ( & V_2 -> V_82 -> V_83 ,
L_3 ) ;
F_78 ( & V_2 -> V_82 -> V_83 ) ;
V_2 -> V_5 . V_84 -- ;
F_79 ( V_78 ) ;
F_19 ( V_81 , & V_2 -> V_19 ) ;
return V_9 ;
}
V_9 = F_66 ( V_2 ) ;
if ( ! V_9 && ! V_2 -> V_5 . V_76 )
V_9 = F_80 ( V_2 ) ;
}
return V_9 ;
}
static int F_81 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
F_73 ( L_2 , F_74 ( V_79 ) , V_2 -> V_19 ) ;
if ( -- V_2 -> V_5 . V_84 == 0 ) {
F_19 ( V_81 , & V_2 -> V_19 ) ;
F_30 ( V_2 , false ) ;
F_44 ( V_2 ) ;
F_19 ( V_31 , & V_2 -> V_19 ) ;
}
F_82 ( & V_2 -> V_82 -> V_83 ) ;
if ( V_2 -> V_5 . V_84 == 0 ) {
F_83 ( & V_2 -> V_5 . V_73 ) ;
F_84 ( V_2 -> V_5 . V_4 ) ;
}
return F_79 ( V_78 ) ;
}
static unsigned int F_85 ( struct V_78 * V_78 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_86 ( & V_2 -> V_5 . V_73 , V_78 , V_86 ) ;
}
static int F_87 ( struct V_78 * V_78 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_88 ( & V_2 -> V_5 . V_73 , V_88 ) ;
}
static struct V_64 * F_89 ( struct V_3 * V_4 ,
T_1 * V_89 , T_1 * V_90 ,
T_1 * V_91 , T_1 * V_92 , int V_93 )
{
bool V_94 = V_4 -> V_94 == 90 || V_4 -> V_94 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_98 * V_99 = V_96 -> V_100 ;
struct V_50 * V_101 = & V_4 -> V_16 ;
T_1 V_56 , V_102 , V_103 , V_104 , V_105 = 3 ;
T_1 V_106 = V_107 ;
struct V_64 * V_108 ;
if ( V_91 && V_4 -> V_12 . V_13 && V_93 == V_109 &&
F_90 ( V_4 -> V_12 . V_13 -> V_110 ) )
* V_91 = V_111 ;
if ( V_92 && * V_92 != V_112 && V_93 != V_113 )
V_106 |= V_114 ;
V_108 = F_91 ( V_92 , V_91 , V_106 , 0 ) ;
if ( F_67 ( ! V_108 ) )
return NULL ;
if ( V_91 )
* V_91 = V_108 -> V_115 ;
if ( V_92 )
* V_92 = V_108 -> V_92 ;
if ( V_93 == V_113 ) {
V_103 = F_90 ( V_108 -> V_110 ) ?
V_99 -> V_116 : V_99 -> V_117 ;
F_92 ( V_89 , F_93 ( T_1 , * V_89 , 32 ) , V_103 , 4 ,
V_90 , F_93 ( T_1 , * V_90 , 32 ) ,
V_118 ,
F_90 ( V_108 -> V_110 ) ? 3 : 1 ,
0 ) ;
return V_108 ;
}
if ( F_90 ( V_108 -> V_110 ) ) {
* V_89 = V_4 -> V_12 . V_54 ;
* V_90 = V_4 -> V_12 . V_55 ;
return V_108 ;
}
V_103 = V_94 ? V_99 -> V_119 : V_99 -> V_120 ;
V_102 = V_4 -> V_19 & V_121 ? V_101 -> V_89 : V_96 -> V_122 ;
V_104 = V_4 -> V_19 & V_121 ? V_101 -> V_90 : V_96 -> V_122 ;
if ( V_96 -> V_123 == 1 && ! V_94 )
V_105 = F_94 ( V_108 -> V_110 ) ? 0 : 1 ;
V_56 = F_95 ( V_108 ) ;
F_92 ( V_89 , V_102 , V_103 ,
F_96 ( V_96 -> V_122 ) - 1 ,
V_90 , V_104 , V_118 ,
V_105 ,
64 / ( F_97 ( V_56 , 8 ) ) ) ;
F_73 ( L_4 ,
V_93 , V_91 ? * V_91 : 0 , * V_89 , * V_90 ,
V_101 -> V_54 , V_101 -> V_55 ) ;
return V_108 ;
}
static void F_98 ( struct V_3 * V_4 , struct V_124 * V_125 ,
int V_93 )
{
bool V_126 = V_4 -> V_94 == 90 || V_4 -> V_94 == 270 ;
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_98 * V_99 = V_96 -> V_100 ;
struct V_50 * V_127 = & V_4 -> V_12 ;
T_1 V_103 , V_128 , V_102 = 0 , V_104 = 0 , V_129 ;
T_1 V_130 = 0 , V_105 = 4 ;
T_1 V_131 , V_132 ;
if ( F_90 ( V_4 -> V_16 . V_13 -> V_110 ) ) {
V_125 -> V_89 = V_127 -> V_54 ;
V_125 -> V_90 = V_127 -> V_55 ;
V_125 -> V_133 = V_125 -> V_134 = 0 ;
return;
}
if ( V_93 == V_109 ) {
if ( V_4 -> V_94 != 90 && V_4 -> V_94 != 270 )
V_105 = 1 ;
V_131 = F_99 ( V_135 , 1 << ( F_96 ( V_127 -> V_89 ) - 3 ) ) ;
V_132 = F_99 ( V_136 , 1 << ( F_96 ( V_127 -> V_90 ) - 1 ) ) ;
V_129 = V_96 -> V_122 ;
} else {
T_1 V_56 = F_95 ( V_127 -> V_13 ) ;
V_130 = 64 / F_97 ( V_56 , 8 ) ;
V_129 = V_96 -> V_137 ;
V_102 = V_104 = V_129 ;
V_131 = V_132 = 1 ;
}
V_103 = F_100 ( T_1 ,
V_126 ? V_99 -> V_119 : V_99 -> V_120 ,
V_126 ? V_127 -> V_55 : V_127 -> V_54 ) ;
V_128 = F_100 ( T_1 , V_118 , V_127 -> V_55 ) ;
if ( V_93 == V_109 ) {
V_102 = F_100 ( T_1 , V_103 , V_127 -> V_54 / V_131 ) ;
V_104 = F_100 ( T_1 , V_128 , V_127 -> V_55 / V_132 ) ;
if ( V_126 ) {
F_101 ( V_131 , V_132 ) ;
F_101 ( V_102 , V_104 ) ;
}
}
F_92 ( & V_125 -> V_89 , V_102 , V_103 , F_96 ( V_129 ) - 1 ,
& V_125 -> V_90 , V_104 , V_128 , V_105 ,
V_130 ) ;
V_125 -> V_133 = F_102 ( T_1 , V_125 -> V_133 , 0 , V_127 -> V_54 - V_125 -> V_89 ) ;
V_125 -> V_134 = F_102 ( T_1 , V_125 -> V_134 , 0 , V_127 -> V_55 - V_125 -> V_90 ) ;
V_125 -> V_133 = F_103 ( V_125 -> V_133 , V_96 -> V_138 ) ;
F_73 ( L_5 ,
V_93 , V_125 -> V_133 , V_125 -> V_134 , V_125 -> V_89 , V_125 -> V_90 ,
V_127 -> V_54 , V_127 -> V_55 ) ;
}
static int F_104 ( struct V_78 * V_78 , void * V_139 ,
struct V_140 * V_22 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
strncpy ( V_22 -> V_141 , V_2 -> V_82 -> V_142 , sizeof( V_22 -> V_141 ) - 1 ) ;
strncpy ( V_22 -> V_143 , V_2 -> V_82 -> V_142 , sizeof( V_22 -> V_143 ) - 1 ) ;
V_22 -> V_144 [ 0 ] = 0 ;
V_22 -> V_145 = V_146 | V_147 ;
return 0 ;
}
static int F_105 ( struct V_78 * V_78 , void * V_139 ,
struct V_148 * V_149 )
{
struct V_64 * V_13 ;
V_13 = F_91 ( NULL , NULL , V_107 | V_114 ,
V_149 -> V_72 ) ;
if ( ! V_13 )
return - V_14 ;
strncpy ( V_149 -> V_150 , V_13 -> V_142 , sizeof( V_149 -> V_150 ) - 1 ) ;
V_149 -> V_151 = V_13 -> V_92 ;
if ( V_13 -> V_92 == V_111 )
V_149 -> V_8 |= V_152 ;
return 0 ;
}
static int F_106 ( struct V_3 * V_4 ,
struct V_153 * V_154 ,
struct V_64 * * V_155 ,
bool V_156 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
struct V_157 * V_158 = V_2 -> V_10 . V_7 ;
struct V_157 * V_159 = V_2 -> V_10 . V_159 ;
struct V_160 V_161 ;
struct V_153 * V_162 = & V_161 . V_163 ;
struct V_64 * V_108 = NULL ;
int V_9 , V_47 = 0 ;
if ( F_67 ( ! V_158 || ! V_154 ) )
return - V_14 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_163 = * V_154 ;
V_161 . V_164 = V_156 ? V_165 : V_166 ;
while ( 1 ) {
V_108 = F_91 ( NULL , V_162 -> V_91 != 0 ? & V_162 -> V_91 : NULL ,
V_107 , V_47 ++ ) ;
if ( V_108 == NULL ) {
return - V_14 ;
}
V_162 -> V_91 = V_154 -> V_91 = V_108 -> V_115 ;
V_9 = F_107 ( V_158 , V_93 , V_167 , NULL , & V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_162 -> V_91 != V_154 -> V_91 ) {
V_162 -> V_91 = 0 ;
continue;
}
if ( V_162 -> V_89 != V_154 -> V_89 || V_162 -> V_89 != V_154 -> V_89 ) {
T_1 V_168 = V_108 -> V_92 ;
V_154 -> V_89 = V_162 -> V_89 ;
V_154 -> V_90 = V_162 -> V_90 ;
V_108 = F_89 ( V_4 ,
& V_154 -> V_89 , & V_154 -> V_90 ,
NULL , & V_168 , V_109 ) ;
if ( V_108 && V_108 -> V_115 )
V_162 -> V_91 = V_108 -> V_115 ;
if ( V_162 -> V_89 != V_154 -> V_89 || V_162 -> V_89 != V_154 -> V_89 )
continue;
V_154 -> V_91 = V_162 -> V_91 ;
}
if ( V_159 )
V_9 = F_107 ( V_159 , V_93 , V_167 , NULL , & V_161 ) ;
if ( V_162 -> V_91 == V_154 -> V_91 &&
V_162 -> V_89 == V_154 -> V_89 && V_162 -> V_89 == V_154 -> V_89 )
break;
}
if ( V_155 && V_108 )
* V_155 = V_108 ;
* V_154 = * V_162 ;
F_73 ( L_6 , V_162 -> V_91 , V_162 -> V_89 , V_162 -> V_90 , V_108 ) ;
return 0 ;
}
static int F_108 ( struct V_78 * V_78 , void * V_169 ,
struct V_58 * V_149 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( V_149 -> type != V_170 )
return - V_14 ;
return F_109 ( & V_4 -> V_16 , V_149 ) ;
}
static int F_110 ( struct V_78 * V_78 , void * V_169 ,
struct V_58 * V_149 )
{
struct V_171 * V_172 = & V_149 -> V_13 . V_173 ;
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_153 V_162 ;
struct V_64 * V_108 = NULL ;
if ( V_149 -> type != V_170 )
return - V_14 ;
if ( V_172 -> V_151 == V_112 ) {
F_89 ( V_4 , & V_172 -> V_89 , & V_172 -> V_90 ,
NULL , & V_172 -> V_151 ,
V_113 ) ;
V_4 -> V_12 . V_54 = V_172 -> V_89 ;
V_4 -> V_12 . V_55 = V_172 -> V_90 ;
}
V_108 = F_89 ( V_4 , & V_172 -> V_89 , & V_172 -> V_90 ,
NULL , & V_172 -> V_151 ,
V_109 ) ;
if ( ! V_108 )
return - V_14 ;
if ( ! V_2 -> V_5 . V_76 ) {
V_162 . V_89 = V_172 -> V_89 ;
V_162 . V_90 = V_172 -> V_90 ;
V_162 . V_91 = V_108 -> V_115 ;
F_111 ( V_2 ) ;
F_106 ( V_4 , & V_162 , & V_108 , false ) ;
F_112 ( V_2 ) ;
V_172 -> V_89 = V_162 . V_89 ;
V_172 -> V_90 = V_162 . V_90 ;
if ( V_108 )
V_172 -> V_151 = V_108 -> V_92 ;
}
F_113 ( V_108 , V_172 -> V_89 , V_172 -> V_90 , V_172 ) ;
return 0 ;
}
static void F_114 ( struct V_3 * V_4 , bool V_174 )
{
V_4 -> V_175 . V_176 = ! V_174 ;
F_115 ( V_4 , ! V_174 ) ;
if ( V_174 )
F_27 ( V_177 , & V_4 -> V_1 -> V_19 ) ;
else
F_19 ( V_177 , & V_4 -> V_1 -> V_19 ) ;
}
static int F_116 ( struct V_1 * V_2 , struct V_58 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_171 * V_172 = & V_149 -> V_13 . V_173 ;
struct V_153 * V_162 = & V_2 -> V_5 . V_162 ;
struct V_50 * V_178 = & V_4 -> V_16 ;
struct V_64 * V_179 = NULL ;
int V_9 , V_47 ;
if ( V_149 -> type != V_170 )
return - V_14 ;
if ( F_117 ( & V_2 -> V_5 . V_73 ) )
return - V_80 ;
if ( V_172 -> V_151 == V_112 ) {
F_89 ( V_4 , & V_172 -> V_89 , & V_172 -> V_90 ,
NULL , & V_172 -> V_151 ,
V_113 ) ;
V_4 -> V_12 . V_54 = V_172 -> V_89 ;
V_4 -> V_12 . V_55 = V_172 -> V_90 ;
}
V_178 -> V_13 = F_89 ( V_4 , & V_172 -> V_89 , & V_172 -> V_90 ,
NULL , & V_172 -> V_151 ,
V_109 ) ;
if ( ! V_178 -> V_13 )
return - V_14 ;
if ( ! V_2 -> V_5 . V_76 ) {
V_162 -> V_91 = V_178 -> V_13 -> V_115 ;
V_162 -> V_89 = V_172 -> V_89 ;
V_162 -> V_90 = V_172 -> V_90 ;
F_111 ( V_2 ) ;
V_9 = F_106 ( V_4 , V_162 , & V_179 , true ) ;
F_112 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_172 -> V_89 = V_162 -> V_89 ;
V_172 -> V_90 = V_162 -> V_90 ;
}
F_113 ( V_178 -> V_13 , V_172 -> V_89 , V_172 -> V_90 , V_172 ) ;
for ( V_47 = 0 ; V_47 < V_178 -> V_13 -> V_180 ; V_47 ++ )
V_178 -> V_68 [ V_47 ] =
( V_172 -> V_89 * V_172 -> V_90 * V_178 -> V_13 -> V_56 [ V_47 ] ) / 8 ;
F_118 ( V_178 , V_172 -> V_89 , V_172 -> V_90 ) ;
if ( ! ( V_4 -> V_19 & V_121 ) )
F_119 ( V_178 , 0 , 0 , V_172 -> V_89 , V_172 -> V_90 ) ;
F_114 ( V_4 , F_90 ( V_178 -> V_13 -> V_110 ) ) ;
if ( ! V_2 -> V_5 . V_76 ) {
V_4 -> V_12 . V_13 = V_179 ;
F_118 ( & V_4 -> V_12 , V_172 -> V_89 , V_172 -> V_90 ) ;
F_119 ( & V_4 -> V_12 , 0 , 0 , V_172 -> V_89 , V_172 -> V_90 ) ;
}
return V_9 ;
}
static int F_120 ( struct V_78 * V_78 , void * V_139 ,
struct V_58 * V_149 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_116 ( V_2 , V_149 ) ;
}
static int F_121 ( struct V_78 * V_78 , void * V_139 ,
struct V_181 * V_47 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_157 * V_158 = V_2 -> V_10 . V_7 ;
if ( V_47 -> V_72 != 0 )
return - V_14 ;
V_47 -> type = V_182 ;
if ( V_158 )
F_122 ( V_47 -> V_142 , V_158 -> V_142 , sizeof( V_47 -> V_142 ) ) ;
return 0 ;
}
static int F_123 ( struct V_78 * V_78 , void * V_139 , unsigned int V_47 )
{
return V_47 == 0 ? V_47 : - V_14 ;
}
static int F_124 ( struct V_78 * V_78 , void * V_139 , unsigned int * V_47 )
{
* V_47 = 0 ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_160 V_183 , V_184 ;
struct V_21 * V_5 = & V_2 -> V_5 ;
struct V_157 * V_158 ;
struct V_185 * V_93 ;
int V_9 ;
V_93 = F_126 ( & V_5 -> V_186 ) ;
if ( V_93 == NULL )
return - V_187 ;
V_158 = F_127 ( V_93 -> V_49 ) ;
while ( 1 ) {
V_93 = & V_158 -> V_49 . V_188 [ 0 ] ;
if ( ! ( V_93 -> V_8 & V_189 ) )
break;
if ( V_158 == V_2 -> V_5 . V_190 ) {
struct V_50 * V_178 = & V_5 -> V_4 -> V_12 ;
V_183 . V_163 . V_89 = V_178 -> V_54 ;
V_183 . V_163 . V_90 = V_178 -> V_55 ;
V_183 . V_163 . V_91 = V_178 -> V_13 ? V_178 -> V_13 -> V_115 : 0 ;
} else {
V_183 . V_93 = V_93 -> V_72 ;
V_183 . V_164 = V_165 ;
V_9 = F_107 ( V_158 , V_93 , V_191 , NULL , & V_183 ) ;
if ( V_9 < 0 && V_9 != - V_192 )
return - V_187 ;
}
V_93 = F_126 ( V_93 ) ;
if ( V_93 == NULL ||
F_128 ( V_93 -> V_49 ) != V_193 )
break;
V_158 = F_127 ( V_93 -> V_49 ) ;
V_184 . V_93 = V_93 -> V_72 ;
V_184 . V_164 = V_165 ;
V_9 = F_107 ( V_158 , V_93 , V_191 , NULL , & V_184 ) ;
if ( V_9 < 0 && V_9 != - V_192 )
return - V_187 ;
if ( V_184 . V_163 . V_89 != V_183 . V_163 . V_89 ||
V_184 . V_163 . V_90 != V_183 . V_163 . V_90 ||
V_184 . V_163 . V_91 != V_183 . V_163 . V_91 )
return - V_187 ;
}
return 0 ;
}
static int F_129 ( struct V_78 * V_78 , void * V_139 ,
enum V_194 type )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_195 * V_196 = & V_2 -> V_10 ;
int V_9 ;
if ( F_31 ( V_2 ) )
return - V_80 ;
F_130 ( & V_196 -> V_7 -> V_49 , V_196 -> V_197 ) ;
if ( V_2 -> V_5 . V_76 ) {
V_9 = F_125 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
return F_131 ( & V_2 -> V_5 . V_73 , type ) ;
}
static int F_132 ( struct V_78 * V_78 , void * V_139 ,
enum V_194 type )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_157 * V_158 = V_2 -> V_10 . V_7 ;
int V_9 ;
V_9 = F_133 ( & V_2 -> V_5 . V_73 , type ) ;
if ( V_9 == 0 )
F_134 ( & V_158 -> V_49 ) ;
return V_9 ;
}
static int F_135 ( struct V_78 * V_78 , void * V_139 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
int V_9 = F_136 ( & V_2 -> V_5 . V_73 , V_199 ) ;
if ( ! V_9 )
V_2 -> V_5 . V_45 = V_199 -> V_41 ;
return V_9 ;
}
static int F_137 ( struct V_78 * V_78 , void * V_139 ,
struct V_200 * V_24 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_138 ( & V_2 -> V_5 . V_73 , V_24 ) ;
}
static int F_139 ( struct V_78 * V_78 , void * V_139 ,
struct V_200 * V_24 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_140 ( & V_2 -> V_5 . V_73 , V_24 ) ;
}
static int F_141 ( struct V_78 * V_78 , void * V_139 ,
struct V_200 * V_24 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
return F_142 ( & V_2 -> V_5 . V_73 , V_24 , V_78 -> V_201 & V_202 ) ;
}
static int F_143 ( struct V_78 * V_78 , void * V_169 ,
struct V_203 * V_204 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_50 * V_149 = & V_2 -> V_5 . V_4 -> V_12 ;
if ( V_204 -> type != V_170 )
return - V_14 ;
V_204 -> V_205 . V_133 = 0 ;
V_204 -> V_205 . V_134 = 0 ;
V_204 -> V_205 . V_89 = V_149 -> V_206 ;
V_204 -> V_205 . V_90 = V_149 -> V_207 ;
V_204 -> V_208 = V_204 -> V_205 ;
return 0 ;
}
static int F_144 ( struct V_78 * V_78 , void * V_169 , struct V_209 * V_204 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_50 * V_149 = & V_2 -> V_5 . V_4 -> V_12 ;
V_204 -> V_210 . V_133 = V_149 -> V_211 ;
V_204 -> V_210 . V_134 = V_149 -> V_212 ;
V_204 -> V_210 . V_89 = V_149 -> V_89 ;
V_204 -> V_210 . V_90 = V_149 -> V_90 ;
return 0 ;
}
static int F_145 ( struct V_78 * V_78 , void * V_169 , struct V_209 * V_204 )
{
struct V_1 * V_2 = F_71 ( V_78 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_178 ;
unsigned long V_8 ;
F_98 ( V_4 , & V_204 -> V_210 , V_113 ) ;
V_178 = & V_4 -> V_12 ;
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_119 ( V_178 , V_204 -> V_210 . V_133 , V_204 -> V_210 . V_134 , V_204 -> V_210 . V_89 , V_204 -> V_210 . V_90 ) ;
F_27 ( V_18 , & V_2 -> V_19 ) ;
F_20 ( & V_2 -> V_15 , V_8 ) ;
return 0 ;
}
static int F_146 ( struct V_213 * V_49 ,
const struct V_185 * V_214 ,
const struct V_185 * V_215 , T_1 V_8 )
{
struct V_157 * V_158 = F_127 ( V_49 ) ;
struct V_1 * V_2 = F_147 ( V_158 ) ;
if ( F_128 ( V_215 -> V_49 ) != V_193 )
return - V_14 ;
if ( F_67 ( V_2 == NULL ) )
return 0 ;
F_73 ( L_7 ,
V_214 -> V_49 -> V_142 , V_215 -> V_49 -> V_142 , V_8 ,
V_2 -> V_5 . V_216 ) ;
if ( V_8 & V_217 ) {
if ( V_2 -> V_5 . V_216 != 0 )
return - V_80 ;
V_2 -> V_5 . V_216 = V_158 -> V_218 ;
return 0 ;
}
V_2 -> V_5 . V_216 = 0 ;
return 0 ;
}
void F_148 ( struct V_157 * V_158 , unsigned int V_219 ,
void * V_220 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_221 * V_222 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( V_158 == NULL )
return;
V_7 = F_2 ( V_158 ) ;
V_222 = F_149 ( & V_158 -> V_49 ) ;
F_3 ( & V_222 -> V_15 , V_8 ) ;
V_2 = V_7 ? V_7 -> V_223 : NULL ;
if ( V_2 && V_220 && V_219 == V_224 &&
F_34 ( V_30 , & V_2 -> V_19 ) ) {
unsigned long V_225 ;
F_3 ( & V_2 -> V_15 , V_225 ) ;
if ( ! F_22 ( & V_2 -> V_5 . V_35 ) ) {
V_24 = F_150 ( V_2 -> V_5 . V_35 . V_226 ,
struct V_23 , V_227 ) ;
F_55 ( & V_24 -> V_33 , 0 , * ( ( T_1 * ) V_220 ) ) ;
}
F_151 ( V_2 , true ) ;
F_32 ( V_2 ) ;
F_20 ( & V_2 -> V_15 , V_225 ) ;
}
F_20 ( & V_222 -> V_15 , V_8 ) ;
}
static int F_152 ( struct V_157 * V_158 ,
struct V_228 * V_169 ,
struct V_229 * V_91 )
{
struct V_64 * V_13 ;
V_13 = F_91 ( NULL , NULL , V_107 , V_91 -> V_72 ) ;
if ( ! V_13 )
return - V_14 ;
V_91 -> V_91 = V_13 -> V_115 ;
return 0 ;
}
static int F_153 ( struct V_157 * V_158 ,
struct V_228 * V_169 ,
struct V_160 * V_13 )
{
struct V_1 * V_2 = F_147 ( V_158 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_153 * V_162 ;
struct V_50 * V_178 ;
if ( V_13 -> V_164 == V_166 ) {
V_162 = F_154 ( V_169 , V_13 -> V_93 ) ;
V_13 -> V_163 = * V_162 ;
return 0 ;
}
V_162 = & V_13 -> V_163 ;
V_162 -> V_230 = V_231 ;
V_178 = V_13 -> V_93 == V_113 ? & V_4 -> V_12 : & V_4 -> V_16 ;
F_63 ( & V_2 -> V_74 ) ;
if ( ! F_67 ( V_4 -> V_12 . V_13 == NULL ) )
V_162 -> V_91 = V_4 -> V_12 . V_13 -> V_115 ;
V_162 -> V_89 = V_178 -> V_54 ;
V_162 -> V_90 = V_178 -> V_55 ;
F_65 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_155 ( struct V_157 * V_158 ,
struct V_228 * V_169 ,
struct V_160 * V_13 )
{
struct V_1 * V_2 = F_147 ( V_158 ) ;
struct V_153 * V_162 = & V_13 -> V_163 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_50 * V_178 ;
struct V_64 * V_108 ;
F_73 ( L_8 ,
V_13 -> V_93 , V_162 -> V_91 , V_162 -> V_89 , V_162 -> V_90 ) ;
if ( V_13 -> V_93 == V_109 &&
F_117 ( & V_2 -> V_5 . V_73 ) )
return - V_80 ;
F_63 ( & V_2 -> V_74 ) ;
V_108 = F_89 ( V_4 , & V_162 -> V_89 , & V_162 -> V_90 ,
& V_162 -> V_91 , NULL , V_13 -> V_93 ) ;
F_65 ( & V_2 -> V_74 ) ;
V_162 -> V_230 = V_231 ;
if ( V_13 -> V_164 == V_166 ) {
V_162 = F_154 ( V_169 , V_13 -> V_93 ) ;
* V_162 = V_13 -> V_163 ;
return 0 ;
}
F_114 ( V_4 , F_90 ( V_108 -> V_110 ) ) ;
V_178 = V_13 -> V_93 == V_113 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_63 ( & V_2 -> V_74 ) ;
F_118 ( V_178 , V_162 -> V_89 , V_162 -> V_90 ) ;
V_2 -> V_5 . V_162 = * V_162 ;
V_178 -> V_13 = V_108 ;
if ( ! ( V_13 -> V_93 == V_109 && ( V_4 -> V_19 & V_121 ) ) )
F_119 ( V_178 , 0 , 0 , V_162 -> V_89 , V_162 -> V_90 ) ;
if ( V_13 -> V_93 == V_113 )
V_4 -> V_19 &= ~ V_121 ;
F_65 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_156 ( struct V_157 * V_158 ,
struct V_228 * V_169 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = F_147 ( V_158 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_124 * V_125 = & V_233 -> V_234 ;
struct V_50 * V_178 ;
if ( V_233 -> V_164 == V_166 ) {
V_233 -> V_234 = * F_157 ( V_169 , V_233 -> V_93 ) ;
return 0 ;
}
V_178 = V_233 -> V_93 == V_113 ?
& V_4 -> V_12 : & V_4 -> V_16 ;
F_63 ( & V_2 -> V_74 ) ;
V_125 -> V_133 = V_178 -> V_211 ;
V_125 -> V_134 = V_178 -> V_212 ;
V_125 -> V_89 = V_178 -> V_89 ;
V_125 -> V_90 = V_178 -> V_90 ;
F_65 ( & V_2 -> V_74 ) ;
F_73 ( L_9 ,
V_178 , V_233 -> V_93 , V_125 -> V_133 , V_125 -> V_134 , V_125 -> V_89 , V_125 -> V_90 ,
V_178 -> V_54 , V_178 -> V_55 ) ;
return 0 ;
}
static int F_158 ( struct V_157 * V_158 ,
struct V_228 * V_169 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = F_147 ( V_158 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_124 * V_125 = & V_233 -> V_234 ;
struct V_50 * V_178 ;
unsigned long V_8 ;
F_73 ( L_10 , V_125 -> V_133 , V_125 -> V_134 , V_125 -> V_89 , V_125 -> V_90 ) ;
V_178 = V_233 -> V_93 == V_109 ?
& V_4 -> V_16 : & V_4 -> V_12 ;
F_63 ( & V_2 -> V_74 ) ;
F_98 ( V_4 , V_125 , V_233 -> V_93 ) ;
if ( V_233 -> V_164 == V_166 ) {
F_63 ( & V_2 -> V_74 ) ;
* F_157 ( V_169 , V_233 -> V_93 ) = * V_125 ;
return 0 ;
}
F_3 ( & V_2 -> V_15 , V_8 ) ;
F_119 ( V_178 , V_125 -> V_133 , V_125 -> V_134 , V_125 -> V_89 , V_125 -> V_90 ) ;
if ( V_233 -> V_93 == V_109 )
V_4 -> V_19 |= V_121 ;
F_27 ( V_18 , & V_2 -> V_19 ) ;
F_20 ( & V_2 -> V_15 , V_8 ) ;
F_73 ( L_11 , V_233 -> V_93 , V_125 -> V_133 , V_125 -> V_134 ,
V_125 -> V_89 , V_125 -> V_90 ) ;
F_65 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 ,
struct V_235 * V_236 )
{
struct V_157 * V_158 ;
int V_9 ;
V_158 = F_160 ( sizeof( * V_158 ) , V_237 ) ;
if ( ! V_158 )
return - V_238 ;
F_161 ( V_158 , & V_239 ) ;
V_158 -> V_8 = V_240 ;
snprintf ( V_158 -> V_142 , sizeof( V_158 -> V_142 ) , L_12 , V_2 -> V_82 -> V_241 ) ;
V_2 -> V_5 . V_242 [ V_113 ] . V_8 = V_189 ;
V_2 -> V_5 . V_242 [ V_109 ] . V_8 = V_243 ;
V_9 = F_162 ( & V_158 -> V_49 , V_244 ,
V_2 -> V_5 . V_242 , 0 ) ;
if ( V_9 )
goto V_245;
V_9 = F_163 ( V_236 , V_158 ) ;
if ( V_9 )
goto V_246;
V_2 -> V_5 . V_190 = V_158 ;
F_164 ( V_158 , V_2 ) ;
V_158 -> V_49 . V_247 = & V_248 ;
return 0 ;
V_246:
F_165 ( & V_158 -> V_49 ) ;
V_245:
F_166 ( V_158 ) ;
return V_9 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = V_2 -> V_5 . V_190 ;
if ( ! V_158 )
return;
F_165 ( & V_158 -> V_49 ) ;
F_168 ( V_158 ) ;
F_166 ( V_158 ) ;
V_2 -> V_5 . V_190 = NULL ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_58 V_13 = {
. type = V_170 ,
. V_13 . V_173 = {
. V_89 = 640 ,
. V_90 = 480 ,
. V_151 = V_249 ,
. V_250 = V_251 ,
. V_230 = V_231 ,
} ,
} ;
return F_116 ( V_2 , & V_13 ) ;
}
int F_169 ( struct V_1 * V_2 ,
struct V_235 * V_236 )
{
struct V_252 * V_48 ;
struct V_21 * V_5 ;
struct V_3 * V_4 ;
struct V_39 * V_40 ;
int V_9 = - V_238 ;
V_4 = F_160 ( sizeof *V_4 , V_237 ) ;
if ( ! V_4 )
return - V_238 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_253 = V_254 ;
V_4 -> V_255 = V_256 ;
V_4 -> V_19 = V_257 ;
V_4 -> V_12 . V_13 = F_91 ( NULL , NULL , V_107 , 0 ) ;
V_4 -> V_16 . V_13 = F_91 ( NULL , NULL , V_107 , 0 ) ;
V_48 = F_170 () ;
if ( ! V_48 ) {
F_54 ( V_236 , L_13 ) ;
goto V_258;
}
snprintf ( V_48 -> V_142 , sizeof( V_48 -> V_142 ) , L_14 ,
F_171 ( & V_2 -> V_82 -> V_83 ) ) ;
V_48 -> V_259 = & V_260 ;
V_48 -> V_261 = & V_262 ;
V_48 -> V_236 = V_236 ;
V_48 -> V_263 = - 1 ;
V_48 -> V_264 = V_265 ;
V_48 -> V_74 = & V_2 -> V_74 ;
F_172 ( V_48 , V_2 ) ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_48 = V_48 ;
V_5 -> V_46 = 0 ;
V_5 -> V_45 = 0 ;
V_5 -> V_84 = 0 ;
F_47 ( & V_5 -> V_32 ) ;
F_47 ( & V_5 -> V_35 ) ;
F_173 ( & V_4 -> V_15 ) ;
V_5 -> V_4 = V_4 ;
V_40 = & V_2 -> V_5 . V_73 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> type = V_170 ;
V_40 -> V_266 = V_267 | V_268 ;
V_40 -> V_42 = V_2 -> V_5 . V_4 ;
V_40 -> V_247 = & V_269 ;
V_40 -> V_270 = & V_271 ;
V_40 -> V_272 = sizeof( struct V_23 ) ;
F_174 ( V_40 ) ;
V_2 -> V_5 . V_186 . V_8 = V_189 ;
V_9 = F_162 ( & V_48 -> V_49 , 1 , & V_2 -> V_5 . V_186 , 0 ) ;
if ( V_9 )
goto V_273;
V_9 = F_159 ( V_2 , V_236 ) ;
if ( V_9 )
goto V_274;
V_48 -> V_77 = & V_4 -> V_77 ;
return 0 ;
V_274:
F_165 ( & V_48 -> V_49 ) ;
V_273:
V_265 ( V_48 ) ;
V_258:
F_166 ( V_4 ) ;
return V_9 ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_252 * V_48 = V_2 -> V_5 . V_48 ;
if ( V_48 ) {
F_165 ( & V_48 -> V_49 ) ;
F_176 ( V_48 ) ;
}
F_167 ( V_2 ) ;
F_166 ( V_2 -> V_5 . V_4 ) ;
V_2 -> V_5 . V_4 = NULL ;
}
