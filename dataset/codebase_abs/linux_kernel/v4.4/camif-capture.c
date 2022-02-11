static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 , & V_2 -> V_3 ) ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_7 . V_8 = V_5 -> V_9 . V_10 * V_5 -> V_11 + V_5 -> V_9 . V_12 ;
V_5 -> V_7 . line = V_5 -> V_11 - ( V_5 -> V_9 . V_12 + V_5 -> V_9 . V_13 ) ;
F_9 ( L_1 ,
V_5 -> V_7 . V_8 , V_5 -> V_7 . line ) ;
}
static int F_10 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
const struct V_16 * V_17 = V_15 -> V_17 ;
if ( V_15 -> V_18 . V_19 == NULL || V_2 -> V_20 == NULL )
return - V_21 ;
if ( V_17 -> V_22 == V_23 )
F_11 ( V_2 ) ;
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
F_14 ( V_15 ) ;
F_15 ( V_15 , V_15 -> V_24 ) ;
if ( V_17 -> V_25 )
F_16 ( V_15 , V_15 -> V_26 ,
V_15 -> V_27 , V_15 -> V_28 ) ;
if ( V_17 -> V_22 == V_29 )
F_17 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_30 &= ~ V_31 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
if ( V_2 -> V_20 == NULL )
return - V_21 ;
F_8 ( V_2 ) ;
if ( V_32 == V_23 )
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_30 &= ~ V_31 ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 , int V_33 )
{
struct V_34 * V_18 = & V_15 -> V_18 ;
int V_35 = 0 ;
if ( V_15 -> V_18 . V_36 == ! V_33 )
V_35 = F_20 ( V_18 -> V_19 , V_37 , V_38 , V_33 ) ;
if ( ! V_35 )
V_18 -> V_36 += V_33 ? 1 : - 1 ;
F_9 ( L_2 ,
V_33 , V_18 -> V_36 , V_35 ) ;
return V_35 ;
}
static int F_21 ( struct V_14 * V_15 , int V_33 )
{
struct V_34 * V_18 = & V_15 -> V_18 ;
int V_35 = 0 ;
if ( V_15 -> V_18 . V_39 == ! V_33 )
V_35 = F_20 ( V_18 -> V_19 , V_40 , V_41 , V_33 ) ;
if ( ! V_35 )
V_18 -> V_39 += V_33 ? 1 : - 1 ;
F_9 ( L_3 ,
V_33 , V_18 -> V_39 , V_35 ) ;
return V_35 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
bool V_45 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_45 = V_2 -> V_30 & V_47 ;
V_2 -> V_30 &= ~ ( V_48 | V_49 | V_50 |
V_51 | V_52 |
V_47 | V_53 ) ;
while ( ! F_24 ( & V_2 -> V_54 ) ) {
V_43 = F_25 ( V_2 ) ;
F_26 ( & V_43 -> V_55 . V_56 , V_57 ) ;
}
while ( ! F_24 ( & V_2 -> V_58 ) ) {
V_43 = F_27 ( V_2 ) ;
F_26 ( & V_43 -> V_55 . V_56 , V_57 ) ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
if ( ! V_45 )
return 0 ;
return F_21 ( V_15 , 0 ) ;
}
static bool F_29 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
bool V_59 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_59 = ( V_2 -> V_30 & V_49 ) || ( V_2 -> V_30 & V_48 ) ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return V_59 ;
}
static bool F_30 ( struct V_14 * V_15 )
{
unsigned long V_44 ;
bool V_60 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_60 = V_15 -> V_39 > 0 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return V_60 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
int V_59 ;
if ( ! F_29 ( V_2 ) )
return 0 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_30 &= ~ ( V_50 | V_53 ) ;
V_2 -> V_30 |= V_51 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
V_59 = F_32 ( V_2 -> V_61 ,
! ( V_2 -> V_30 & V_51 ) ,
F_33 ( V_62 ) ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
if ( V_59 == 0 && ! ( V_2 -> V_30 & V_50 ) ) {
V_2 -> V_30 &= ~ ( V_50 | V_51 |
V_53 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 , false ) ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
return F_22 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_63 * V_55 ,
struct V_64 * V_65 )
{
struct V_4 * V_66 = & V_2 -> V_6 ;
T_1 V_67 ;
if ( V_55 == NULL || V_66 == NULL )
return - V_21 ;
V_67 = V_66 -> V_9 . V_13 * V_66 -> V_9 . V_68 ;
F_9 ( L_4 ,
V_2 -> V_20 -> V_69 , V_67 ) ;
V_65 -> V_70 = F_37 ( V_55 , 0 ) ;
switch ( V_2 -> V_20 -> V_69 ) {
case 1 :
V_65 -> V_71 = 0 ;
V_65 -> V_72 = 0 ;
break;
case 2 :
V_65 -> V_71 = ( T_1 ) ( V_65 -> V_70 + V_67 ) ;
V_65 -> V_72 = 0 ;
break;
case 3 :
V_65 -> V_71 = ( T_1 ) ( V_65 -> V_70 + V_67 ) ;
if ( V_2 -> V_20 -> V_73 == V_74 )
V_65 -> V_72 = ( T_1 ) ( V_65 -> V_71 + ( V_67 >> 1 ) ) ;
else
V_65 -> V_72 = ( T_1 ) ( V_65 -> V_71 + ( V_67 >> 2 ) ) ;
if ( V_2 -> V_20 -> V_73 == V_75 )
F_38 ( V_65 -> V_71 , V_65 -> V_72 ) ;
break;
default:
return - V_21 ;
}
F_9 ( L_5 ,
& V_65 -> V_70 , & V_65 -> V_71 , & V_65 -> V_72 ) ;
return 0 ;
}
T_2 F_39 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
unsigned int V_60 ;
F_40 ( & V_15 -> V_46 ) ;
if ( V_32 == V_29 )
F_41 ( V_2 ) ;
V_60 = F_42 ( V_2 ) ;
if ( V_32 == V_23 && ( V_60 & V_78 ) ) {
F_11 ( V_2 ) ;
goto V_79;
}
if ( V_2 -> V_30 & V_51 ) {
if ( V_2 -> V_30 & V_50 ) {
V_2 -> V_30 &= ~ ( V_50 | V_51 |
V_53 ) ;
F_43 ( & V_2 -> V_61 ) ;
goto V_79;
} else if ( V_2 -> V_30 & V_53 ) {
F_34 ( V_2 ) ;
F_35 ( V_2 , false ) ;
F_44 ( V_2 , false ) ;
V_2 -> V_30 |= V_50 ;
} else {
F_44 ( V_2 , true ) ;
V_2 -> V_30 |= V_53 ;
}
}
if ( ! F_24 ( & V_2 -> V_54 ) && ( V_2 -> V_30 & V_49 ) &&
! F_24 ( & V_2 -> V_58 ) ) {
unsigned int V_80 ;
struct V_42 * V_81 ;
V_80 = ( F_45 ( V_60 ) + 2 ) & 1 ;
V_81 = F_46 ( V_2 , V_80 ) ;
if ( ! F_2 ( V_81 == NULL ) ) {
F_47 ( & V_81 -> V_55 . V_82 ) ;
V_81 -> V_55 . V_83 = V_2 -> V_84 ++ ;
F_26 ( & V_81 -> V_55 . V_56 , V_85 ) ;
V_81 = F_25 ( V_2 ) ;
V_81 -> V_80 = V_80 ;
F_48 ( V_2 , & V_81 -> V_65 , V_80 ) ;
F_48 ( V_2 , & V_81 -> V_65 , V_80 + 2 ) ;
F_49 ( V_2 , V_81 ) ;
}
} else if ( ! ( V_2 -> V_30 & V_51 ) &&
( V_2 -> V_30 & V_48 ) ) {
V_2 -> V_30 |= V_49 ;
}
if ( V_2 -> V_30 & V_31 ) {
F_8 ( V_2 ) ;
F_14 ( V_15 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_15 ( V_15 , V_15 -> V_24 ) ;
if ( V_15 -> V_17 -> V_25 )
F_16 ( V_15 , V_15 -> V_26 ,
V_15 -> V_27 , V_15 -> V_28 ) ;
V_2 -> V_30 &= ~ V_31 ;
}
V_79:
F_50 ( & V_15 -> V_46 ) ;
return V_86 ;
}
static int F_51 ( struct V_87 * V_88 , unsigned int V_89 )
{
struct V_1 * V_2 = F_52 ( V_88 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
int V_59 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
if ( V_15 -> V_39 == 0 ) {
F_53 ( V_15 ) ;
V_59 = F_10 ( V_15 , V_2 ) ;
} else {
V_59 = F_18 ( V_15 , V_2 ) ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
if ( V_59 < 0 ) {
F_22 ( V_2 ) ;
return V_59 ;
}
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_84 = 0 ;
V_2 -> V_30 |= V_48 ;
if ( ! F_24 ( & V_2 -> V_54 ) &&
( ! ( V_2 -> V_30 & V_52 ) ||
! ( V_2 -> V_30 & V_47 ) ) ) {
F_35 ( V_2 , V_2 -> V_3 . V_90 ) ;
F_54 ( V_2 ) ;
V_2 -> V_30 |= V_52 ;
if ( ! ( V_2 -> V_30 & V_47 ) ) {
V_2 -> V_30 |= V_47 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
V_59 = F_21 ( V_15 , 1 ) ;
if ( V_59 )
F_55 ( & V_2 -> V_91 , L_6 ) ;
if ( V_92 )
F_56 ( V_15 , V_93 ) ;
return V_59 ;
}
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
static void F_57 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_52 ( V_88 ) ;
F_31 ( V_2 ) ;
}
static int F_58 ( struct V_87 * V_88 , const void * V_94 ,
unsigned int * V_95 , unsigned int * V_96 ,
unsigned int V_97 [] , void * V_98 [] )
{
const struct V_99 * V_100 = V_94 ;
const struct V_101 * V_102 = NULL ;
struct V_1 * V_2 = F_52 ( V_88 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_66 = & V_2 -> V_6 ;
const struct V_103 * V_104 ;
unsigned int V_105 ;
if ( V_100 ) {
V_102 = & V_100 -> V_104 . V_102 ;
V_104 = F_59 ( V_2 , & V_102 -> V_106 , - 1 ) ;
if ( V_104 == NULL )
return - V_21 ;
V_105 = ( V_102 -> V_13 * V_102 -> V_68 * V_104 -> V_107 ) / 8 ;
} else {
V_104 = V_2 -> V_20 ;
if ( V_104 == NULL )
return - V_21 ;
V_105 = ( V_66 -> V_11 * V_66 -> V_108 * V_104 -> V_107 ) / 8 ;
}
* V_96 = 1 ;
if ( V_102 )
V_97 [ 0 ] = F_60 ( V_105 , V_102 -> V_109 ) ;
else
V_97 [ 0 ] = V_105 ;
V_98 [ 0 ] = V_15 -> V_110 ;
F_9 ( L_7 , V_97 [ 0 ] ) ;
return 0 ;
}
static int F_61 ( struct V_63 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_87 ) ;
if ( V_2 -> V_20 == NULL )
return - V_21 ;
if ( F_62 ( V_55 , 0 ) < V_2 -> V_111 ) {
F_55 ( & V_2 -> V_91 , L_8 ,
F_62 ( V_55 , 0 ) , V_2 -> V_111 ) ;
return - V_21 ;
}
F_63 ( V_55 , 0 , V_2 -> V_111 ) ;
return 0 ;
}
static void F_64 ( struct V_63 * V_55 )
{
struct V_112 * V_81 = F_65 ( V_55 ) ;
struct V_42 * V_43 = F_66 ( V_81 , struct V_42 , V_55 ) ;
struct V_1 * V_2 = F_52 ( V_55 -> V_87 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
F_2 ( F_36 ( V_2 , & V_43 -> V_55 . V_56 , & V_43 -> V_65 ) ) ;
if ( ! ( V_2 -> V_30 & V_52 ) && V_2 -> V_113 < 2 ) {
V_43 -> V_80 = V_2 -> V_114 ;
F_48 ( V_2 , & V_43 -> V_65 , V_43 -> V_80 ) ;
F_48 ( V_2 , & V_43 -> V_65 , V_43 -> V_80 + 2 ) ;
F_49 ( V_2 , V_43 ) ;
V_2 -> V_114 = ! V_2 -> V_114 ;
} else {
F_67 ( V_2 , V_43 ) ;
}
if ( F_68 ( & V_2 -> V_115 ) && ! F_24 ( & V_2 -> V_54 )
&& ! ( V_2 -> V_30 & V_52 ) ) {
V_2 -> V_30 |= V_52 ;
F_35 ( V_2 , V_2 -> V_3 . V_90 ) ;
F_54 ( V_2 ) ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
if ( ! ( V_2 -> V_30 & V_47 ) ) {
if ( F_21 ( V_15 , 1 ) == 0 )
V_2 -> V_30 |= V_47 ;
else
F_55 ( & V_2 -> V_91 , L_6 ) ;
if ( V_92 )
F_56 ( V_15 , V_93 ) ;
}
return;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
}
static int F_69 ( struct V_116 * V_116 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_9 , V_2 -> V_117 ,
V_2 -> V_30 , V_2 -> V_118 , F_71 ( V_119 ) ) ;
if ( F_72 ( & V_15 -> V_120 ) )
return - V_121 ;
V_59 = F_73 ( V_116 ) ;
if ( V_59 < 0 )
goto V_79;
V_59 = F_74 ( V_15 -> V_122 ) ;
if ( V_59 < 0 )
goto V_123;
V_59 = F_19 ( V_15 , 1 ) ;
if ( ! V_59 )
goto V_79;
F_75 ( V_15 -> V_122 ) ;
V_123:
F_76 ( V_116 ) ;
V_79:
F_77 ( & V_15 -> V_120 ) ;
return V_59 ;
}
static int F_78 ( struct V_116 * V_116 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_10 , V_2 -> V_117 ,
V_2 -> V_30 , V_2 -> V_118 , F_71 ( V_119 ) ) ;
F_79 ( & V_15 -> V_120 ) ;
if ( V_2 -> V_118 == V_116 -> V_124 ) {
F_31 ( V_2 ) ;
F_80 ( & V_2 -> V_115 ) ;
V_2 -> V_118 = NULL ;
}
F_19 ( V_15 , 0 ) ;
F_75 ( V_15 -> V_122 ) ;
V_59 = F_76 ( V_116 ) ;
F_77 ( & V_15 -> V_120 ) ;
return V_59 ;
}
static unsigned int F_81 ( struct V_116 * V_116 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_79 ( & V_15 -> V_120 ) ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_116 -> V_124 )
V_59 = - V_127 ;
else
V_59 = F_82 ( & V_2 -> V_115 , V_116 , V_126 ) ;
F_77 ( & V_15 -> V_120 ) ;
return V_59 ;
}
static int F_83 ( struct V_116 * V_116 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
int V_59 ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_116 -> V_124 )
V_59 = - V_127 ;
else
V_59 = F_84 ( & V_2 -> V_115 , V_129 ) ;
return V_59 ;
}
static int F_85 ( struct V_116 * V_116 , void * V_77 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
F_86 ( V_131 -> V_132 , V_133 , sizeof( V_131 -> V_132 ) ) ;
F_86 ( V_131 -> V_134 , V_133 , sizeof( V_131 -> V_134 ) ) ;
snprintf ( V_131 -> V_135 , sizeof( V_131 -> V_135 ) , L_11 ,
F_87 ( V_2 -> V_15 -> V_122 ) , V_2 -> V_117 ) ;
V_131 -> V_136 = V_137 | V_138 ;
V_131 -> V_139 = V_131 -> V_136 | V_140 ;
return 0 ;
}
static int F_88 ( struct V_116 * V_116 , void * V_77 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_143 * V_18 = V_2 -> V_15 -> V_18 . V_19 ;
if ( V_142 -> V_80 || V_18 == NULL )
return - V_21 ;
V_142 -> type = V_144 ;
F_86 ( V_142 -> V_145 , V_18 -> V_145 , sizeof( V_142 -> V_145 ) ) ;
return 0 ;
}
static int F_89 ( struct V_116 * V_116 , void * V_77 ,
unsigned int V_146 )
{
return V_146 == 0 ? 0 : - V_21 ;
}
static int F_90 ( struct V_116 * V_116 , void * V_77 ,
unsigned int * V_146 )
{
* V_146 = 0 ;
return 0 ;
}
static int F_91 ( struct V_116 * V_116 , void * V_77 ,
struct V_147 * V_5 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
const struct V_103 * V_104 ;
V_104 = F_59 ( V_2 , NULL , V_5 -> V_80 ) ;
if ( ! V_104 )
return - V_21 ;
F_86 ( V_5 -> V_148 , V_104 -> V_145 , sizeof( V_5 -> V_148 ) ) ;
V_5 -> V_106 = V_104 -> V_149 ;
F_9 ( L_12 , V_5 -> V_80 , V_5 -> V_148 ) ;
return 0 ;
}
static int F_92 ( struct V_116 * V_116 , void * V_77 ,
struct V_99 * V_5 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_101 * V_102 = & V_5 -> V_104 . V_102 ;
struct V_4 * V_66 = & V_2 -> V_6 ;
const struct V_103 * V_104 = V_2 -> V_20 ;
V_102 -> V_150 = V_66 -> V_11 * V_104 -> V_151 ;
V_102 -> V_109 = V_2 -> V_111 ;
V_102 -> V_106 = V_104 -> V_149 ;
V_102 -> V_13 = V_66 -> V_11 ;
V_102 -> V_68 = V_66 -> V_108 ;
V_102 -> V_152 = V_153 ;
V_102 -> V_154 = V_155 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
const struct V_103 * * V_156 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_157 * V_158 = & V_15 -> V_159 ;
unsigned int V_160 , V_161 , V_162 , V_163 ;
const struct V_164 * V_165 ;
const struct V_103 * V_104 ;
V_104 = F_59 ( V_2 , & V_102 -> V_106 , 0 ) ;
if ( F_2 ( V_104 == NULL ) )
return - V_21 ;
if ( V_156 )
* V_156 = V_104 ;
V_165 = & V_15 -> V_17 -> V_164 [ V_2 -> V_117 ] ;
F_9 ( L_13 ,
V_102 -> V_13 , V_102 -> V_68 , V_158 -> V_13 , V_158 -> V_68 ,
V_102 -> V_150 ) ;
V_162 = F_94 ( V_166 , 1 << ( F_95 ( V_158 -> V_13 ) - 3 ) ) ;
V_163 = F_94 ( V_166 , 1 << ( F_95 ( V_158 -> V_68 ) - 1 ) ) ;
V_160 = F_96 ( T_1 , V_165 -> V_167 , V_158 -> V_13 / V_162 ) ;
V_160 = F_97 ( V_160 , V_165 -> V_168 ) ;
V_161 = F_96 ( T_1 , 8 , V_158 -> V_68 / V_163 ) ;
V_161 = F_97 ( V_161 , 8 ) ;
F_98 ( & V_102 -> V_13 , V_160 , V_165 -> V_169 ,
F_95 ( V_165 -> V_168 ) - 1 ,
& V_102 -> V_68 , V_161 , V_165 -> V_170 , 0 , 0 ) ;
V_102 -> V_150 = V_102 -> V_13 * V_104 -> V_151 ;
V_102 -> V_109 = ( V_102 -> V_13 * V_102 -> V_68 * V_104 -> V_107 ) / 8 ;
V_102 -> V_106 = V_104 -> V_149 ;
V_102 -> V_154 = V_155 ;
V_102 -> V_152 = V_153 ;
F_9 ( L_14 ,
V_102 -> V_13 , V_102 -> V_68 , V_160 , V_161 , V_162 , V_163 ) ;
return 0 ;
}
static int F_99 ( struct V_116 * V_116 , void * V_77 ,
struct V_99 * V_5 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
return F_93 ( V_2 , & V_5 -> V_104 . V_102 , NULL ) ;
}
static int F_100 ( struct V_116 * V_116 , void * V_77 ,
struct V_99 * V_5 )
{
struct V_101 * V_102 = & V_5 -> V_104 . V_102 ;
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_4 * V_6 = & V_2 -> V_6 ;
const struct V_103 * V_104 = NULL ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_117 ) ;
if ( F_101 ( & V_2 -> V_115 ) )
return - V_127 ;
V_59 = F_93 ( V_2 , & V_5 -> V_104 . V_102 , & V_104 ) ;
if ( V_59 < 0 )
return V_59 ;
V_2 -> V_20 = V_104 ;
V_2 -> V_111 = V_102 -> V_109 ;
V_6 -> V_11 = V_102 -> V_13 ;
V_6 -> V_108 = V_102 -> V_68 ;
V_6 -> V_9 . V_13 = V_102 -> V_13 ;
V_6 -> V_9 . V_68 = V_102 -> V_68 ;
V_6 -> V_9 . V_12 = 0 ;
V_6 -> V_9 . V_10 = 0 ;
if ( V_2 -> V_118 == NULL )
V_2 -> V_118 = V_77 ;
F_9 ( L_16 ,
V_6 -> V_11 , V_6 -> V_108 , V_2 -> V_111 , V_104 -> V_145 ,
V_102 -> V_13 * V_102 -> V_68 * V_104 -> V_107 , V_104 -> V_107 ,
V_102 -> V_109 , V_102 -> V_150 ) ;
return 0 ;
}
static int F_102 ( struct V_14 * V_15 )
{
struct V_171 V_172 ;
struct V_173 * V_174 ;
int V_59 ;
V_174 = F_103 ( & V_15 -> V_175 [ 0 ] ) ;
if ( ! V_174 || F_104 ( V_174 -> V_176 ) != V_177 )
return - V_178 ;
V_172 . V_174 = V_174 -> V_80 ;
V_172 . V_179 = V_180 ;
V_59 = F_20 ( V_15 -> V_18 . V_19 , V_174 , V_181 , NULL , & V_172 ) ;
if ( V_59 < 0 && V_59 != - V_182 )
return - V_178 ;
if ( V_172 . V_183 . V_13 != V_15 -> V_184 . V_13 ||
V_172 . V_183 . V_68 != V_15 -> V_184 . V_68 ||
V_172 . V_183 . V_185 != V_15 -> V_184 . V_185 )
return - V_178 ;
return 0 ;
}
static int F_105 ( struct V_116 * V_116 , void * V_77 ,
enum V_186 type )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_187 * V_18 = & V_15 -> V_18 . V_19 -> V_176 ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_117 ) ;
if ( type != V_188 )
return - V_21 ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
if ( F_29 ( V_2 ) )
return 0 ;
V_59 = F_106 ( V_18 , V_15 -> V_189 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_102 ( V_15 ) ;
if ( V_59 < 0 ) {
F_107 ( V_18 ) ;
return V_59 ;
}
return F_108 ( & V_2 -> V_115 , type ) ;
}
static int F_109 ( struct V_116 * V_116 , void * V_77 ,
enum V_186 type )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_117 ) ;
if ( type != V_188 )
return - V_21 ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
V_59 = F_110 ( & V_2 -> V_115 , type ) ;
if ( V_59 == 0 )
F_107 ( & V_15 -> V_18 . V_19 -> V_176 ) ;
return V_59 ;
}
static int F_111 ( struct V_116 * V_116 , void * V_77 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
int V_59 ;
F_9 ( L_17 ,
V_2 -> V_117 , V_191 -> V_89 , V_2 -> V_118 , V_77 ) ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
if ( V_191 -> V_89 )
V_191 -> V_89 = F_96 ( T_1 , V_192 , V_191 -> V_89 ) ;
else
V_2 -> V_118 = NULL ;
V_59 = F_112 ( & V_2 -> V_115 , V_191 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_191 -> V_89 && V_191 -> V_89 < V_192 ) {
V_191 -> V_89 = 0 ;
F_112 ( & V_2 -> V_115 , V_191 ) ;
V_59 = - V_193 ;
}
V_2 -> V_194 = V_191 -> V_89 ;
if ( V_2 -> V_118 == NULL && V_191 -> V_89 > 0 )
V_2 -> V_118 = V_77 ;
return V_59 ;
}
static int F_113 ( struct V_116 * V_116 , void * V_77 ,
struct V_195 * V_43 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
return F_114 ( & V_2 -> V_115 , V_43 ) ;
}
static int F_115 ( struct V_116 * V_116 , void * V_77 ,
struct V_195 * V_43 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
F_9 ( L_15 , V_2 -> V_117 ) ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
return F_116 ( & V_2 -> V_115 , V_43 ) ;
}
static int F_117 ( struct V_116 * V_116 , void * V_77 ,
struct V_195 * V_43 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
F_9 ( L_18 , V_2 -> V_117 , V_2 -> V_84 ) ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
return F_118 ( & V_2 -> V_115 , V_43 , V_116 -> V_196 & V_197 ) ;
}
static int F_119 ( struct V_116 * V_116 , void * V_77 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
int V_59 ;
if ( V_2 -> V_118 && V_2 -> V_118 != V_77 )
return - V_127 ;
V_199 -> V_89 = F_96 ( T_1 , 1 , V_199 -> V_89 ) ;
V_59 = F_120 ( & V_2 -> V_115 , V_199 ) ;
if ( ! V_59 && V_2 -> V_118 == NULL )
V_2 -> V_118 = V_77 ;
return V_59 ;
}
static int F_121 ( struct V_116 * V_116 , void * V_77 ,
struct V_195 * V_200 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
return F_122 ( & V_2 -> V_115 , V_200 ) ;
}
static int F_123 ( struct V_116 * V_116 , void * V_77 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
if ( V_202 -> type != V_188 )
return - V_21 ;
switch ( V_202 -> V_203 ) {
case V_204 :
case V_205 :
V_202 -> V_206 . V_12 = 0 ;
V_202 -> V_206 . V_10 = 0 ;
V_202 -> V_206 . V_13 = V_2 -> V_6 . V_11 ;
V_202 -> V_206 . V_68 = V_2 -> V_6 . V_108 ;
return 0 ;
case V_207 :
V_202 -> V_206 = V_2 -> V_6 . V_9 ;
return 0 ;
}
return - V_21 ;
}
static void F_124 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_157 * V_206 )
{
if ( V_15 -> V_17 -> V_22 == V_23 ) {
* V_206 = V_2 -> V_6 . V_9 ;
return;
}
}
static int F_125 ( struct V_116 * V_116 , void * V_77 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 = F_70 ( V_116 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_157 V_9 = V_202 -> V_206 ;
unsigned long V_44 ;
if ( V_202 -> type != V_188 ||
V_202 -> V_203 != V_207 )
return - V_21 ;
F_124 ( V_15 , V_2 , & V_9 ) ;
V_202 -> V_206 = V_9 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_6 . V_9 = V_9 ;
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
F_9 ( L_19 ,
V_202 -> type , V_202 -> V_203 , V_202 -> V_44 ,
V_202 -> V_206 . V_12 , V_202 -> V_206 . V_10 , V_202 -> V_206 . V_13 , V_202 -> V_206 . V_68 ) ;
return 0 ;
}
static int F_126 ( struct V_208 * V_209 )
{
struct V_1 * V_2 = V_209 -> V_77 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_9 ( L_20 , V_2 -> V_117 ,
V_209 -> V_145 , V_209 -> V_210 ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_209 -> V_117 ) {
case V_211 :
V_2 -> V_212 = V_209 -> V_210 ;
break;
case V_213 :
V_2 -> V_214 = V_209 -> V_210 ;
break;
}
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_127 ( struct V_14 * V_15 , int V_215 )
{
struct V_1 * V_2 = & V_15 -> V_2 [ V_215 ] ;
struct V_87 * V_216 = & V_2 -> V_115 ;
struct V_217 * V_218 = & V_2 -> V_91 ;
struct V_208 * V_209 ;
int V_59 ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
snprintf ( V_218 -> V_145 , sizeof( V_218 -> V_145 ) , L_21 ,
V_2 -> V_117 == 0 ? L_22 : L_23 ) ;
V_218 -> V_219 = & V_220 ;
V_218 -> V_221 = & V_222 ;
V_218 -> V_223 = & V_15 -> V_223 ;
V_218 -> V_224 = - 1 ;
V_218 -> V_225 = V_226 ;
V_218 -> V_120 = & V_15 -> V_120 ;
V_2 -> V_194 = 0 ;
F_128 ( & V_2 -> V_54 ) ;
F_128 ( & V_2 -> V_58 ) ;
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
V_216 -> type = V_188 ;
V_216 -> V_227 = V_228 | V_229 ;
V_216 -> V_230 = & V_231 ;
V_216 -> V_232 = & V_233 ;
V_216 -> V_234 = sizeof( struct V_42 ) ;
V_216 -> V_235 = V_2 ;
V_216 -> V_236 = V_237 ;
V_216 -> V_120 = & V_2 -> V_15 -> V_120 ;
V_59 = F_129 ( V_216 ) ;
if ( V_59 )
goto V_238;
V_2 -> V_174 . V_44 = V_239 ;
V_59 = F_130 ( & V_218 -> V_176 , 1 , & V_2 -> V_174 , 0 ) ;
if ( V_59 )
goto V_238;
F_131 ( V_218 , V_2 ) ;
F_132 ( & V_2 -> V_240 , 1 ) ;
V_209 = F_133 ( & V_2 -> V_240 , & V_241 ,
V_211 , 0 , 1 , 1 , 0 ) ;
if ( V_209 )
V_209 -> V_77 = V_2 ;
V_209 = F_133 ( & V_2 -> V_240 , & V_241 ,
V_213 , 0 , 1 , 1 , 0 ) ;
if ( V_209 )
V_209 -> V_77 = V_2 ;
V_59 = V_2 -> V_240 . error ;
if ( V_59 < 0 )
goto V_242;
V_218 -> V_240 = & V_2 -> V_240 ;
V_59 = F_134 ( V_218 , V_243 , - 1 ) ;
if ( V_59 )
goto V_244;
F_135 ( & V_15 -> V_223 , L_24 ,
V_218 -> V_145 , F_136 ( V_218 ) ) ;
return 0 ;
V_244:
F_137 ( & V_2 -> V_240 ) ;
V_242:
F_138 ( & V_218 -> V_176 ) ;
V_238:
F_139 ( V_218 ) ;
return V_59 ;
}
void F_140 ( struct V_14 * V_15 , int V_215 )
{
struct V_217 * V_218 = & V_15 -> V_2 [ V_215 ] . V_91 ;
if ( F_141 ( V_218 ) ) {
F_142 ( V_218 ) ;
F_138 ( & V_218 -> V_176 ) ;
F_137 ( V_218 -> V_240 ) ;
}
}
static int F_143 ( struct V_143 * V_19 ,
struct V_245 * V_246 ,
struct V_247 * V_185 )
{
if ( V_185 -> V_80 >= F_144 ( V_248 ) )
return - V_21 ;
V_185 -> V_185 = V_248 [ V_185 -> V_80 ] ;
return 0 ;
}
static int F_145 ( struct V_143 * V_19 ,
struct V_245 * V_246 ,
struct V_171 * V_104 )
{
struct V_14 * V_15 = F_146 ( V_19 ) ;
struct V_249 * V_250 = & V_104 -> V_183 ;
if ( V_104 -> V_179 == V_251 ) {
V_250 = F_147 ( V_19 , V_246 , V_104 -> V_174 ) ;
V_104 -> V_183 = * V_250 ;
return 0 ;
}
F_79 ( & V_15 -> V_120 ) ;
switch ( V_104 -> V_174 ) {
case V_252 :
* V_250 = V_15 -> V_184 ;
break;
case V_253 ... V_254 :
V_250 -> V_13 = V_15 -> V_159 . V_13 ;
V_250 -> V_68 = V_15 -> V_159 . V_68 ;
V_250 -> V_185 = V_15 -> V_184 . V_185 ;
break;
}
F_77 ( & V_15 -> V_120 ) ;
V_250 -> V_152 = V_153 ;
V_250 -> V_154 = V_155 ;
return 0 ;
}
static void F_148 ( struct V_14 * V_15 ,
struct V_249 * V_250 , int V_174 )
{
const struct V_16 * V_17 = V_15 -> V_17 ;
const struct V_164 * V_165 ;
int V_146 = F_144 ( V_248 ) ;
V_165 = & V_17 -> V_164 [ V_255 ] ;
while ( V_146 -- >= 0 )
if ( V_248 [ V_146 ] == V_250 -> V_185 )
break;
V_250 -> V_185 = V_248 [ V_146 ] ;
if ( V_174 == V_252 ) {
F_98 ( & V_250 -> V_13 , 8 , V_256 ,
F_95 ( V_165 -> V_168 ) - 1 ,
& V_250 -> V_68 , 8 , V_257 , 0 ,
0 ) ;
} else {
struct V_157 * V_158 = & V_15 -> V_159 ;
F_98 ( & V_250 -> V_13 , 8 , V_158 -> V_13 ,
F_95 ( V_165 -> V_168 ) - 1 ,
& V_250 -> V_68 , 8 , V_158 -> V_68 ,
0 , 0 ) ;
}
F_149 ( 1 , V_92 , & V_15 -> V_258 , L_25 , V_250 -> V_13 , V_250 -> V_68 ) ;
}
static int F_150 ( struct V_143 * V_19 ,
struct V_245 * V_246 ,
struct V_171 * V_104 )
{
struct V_14 * V_15 = F_146 ( V_19 ) ;
struct V_249 * V_250 = & V_104 -> V_183 ;
struct V_157 * V_158 = & V_15 -> V_159 ;
int V_146 ;
F_149 ( 1 , V_92 , V_19 , L_26 ,
V_104 -> V_174 , V_250 -> V_185 , V_250 -> V_13 , V_250 -> V_68 ) ;
V_250 -> V_152 = V_153 ;
V_250 -> V_154 = V_155 ;
F_79 ( & V_15 -> V_120 ) ;
if ( F_101 ( & V_15 -> V_2 [ V_255 ] . V_115 ) ||
F_101 ( & V_15 -> V_2 [ V_259 ] . V_115 ) ) {
F_77 ( & V_15 -> V_120 ) ;
return - V_127 ;
}
F_148 ( V_15 , V_250 , V_104 -> V_174 ) ;
if ( V_104 -> V_179 == V_251 ) {
V_250 = F_147 ( V_19 , V_246 , V_104 -> V_174 ) ;
* V_250 = V_104 -> V_183 ;
F_77 ( & V_15 -> V_120 ) ;
return 0 ;
}
switch ( V_104 -> V_174 ) {
case V_252 :
V_15 -> V_184 = * V_250 ;
V_158 -> V_13 = V_250 -> V_13 ;
V_158 -> V_68 = V_250 -> V_68 ;
V_158 -> V_12 = 0 ;
V_158 -> V_10 = 0 ;
for ( V_146 = 0 ; V_146 < V_260 ; V_146 ++ ) {
struct V_4 * V_66 = & V_15 -> V_2 [ V_146 ] . V_6 ;
V_66 -> V_9 = * V_158 ;
V_66 -> V_11 = V_250 -> V_13 ;
V_66 -> V_108 = V_250 -> V_68 ;
}
break;
case V_253 ... V_254 :
V_250 -> V_185 = V_15 -> V_184 . V_185 ;
V_250 -> V_13 = V_158 -> V_13 ;
V_250 -> V_68 = V_158 -> V_68 ;
break;
}
F_77 ( & V_15 -> V_120 ) ;
return 0 ;
}
static int F_151 ( struct V_143 * V_19 ,
struct V_245 * V_246 ,
struct V_261 * V_202 )
{
struct V_14 * V_15 = F_146 ( V_19 ) ;
struct V_157 * V_158 = & V_15 -> V_159 ;
struct V_249 * V_250 = & V_15 -> V_184 ;
if ( ( V_202 -> V_203 != V_262 &&
V_202 -> V_203 != V_263 ) ||
V_202 -> V_174 != V_252 )
return - V_21 ;
if ( V_202 -> V_179 == V_251 ) {
V_202 -> V_206 = * F_152 ( V_19 , V_246 , V_202 -> V_174 ) ;
return 0 ;
}
F_79 ( & V_15 -> V_120 ) ;
if ( V_202 -> V_203 == V_262 ) {
V_202 -> V_206 = * V_158 ;
} else {
V_202 -> V_206 . V_13 = V_250 -> V_13 ;
V_202 -> V_206 . V_68 = V_250 -> V_68 ;
V_202 -> V_206 . V_12 = 0 ;
V_202 -> V_206 . V_10 = 0 ;
}
F_77 ( & V_15 -> V_120 ) ;
F_149 ( 1 , V_92 , V_19 , L_27 ,
V_93 , V_158 -> V_12 , V_158 -> V_10 , V_158 -> V_13 ,
V_158 -> V_68 , V_250 -> V_13 , V_250 -> V_68 ) ;
return 0 ;
}
static void F_153 ( struct V_14 * V_15 , struct V_157 * V_206 )
{
struct V_249 * V_250 = & V_15 -> V_184 ;
const struct V_264 * V_165 = & V_15 -> V_17 -> V_265 ;
unsigned int V_12 = 2 * V_206 -> V_12 ;
unsigned int V_10 = 2 * V_206 -> V_10 ;
F_98 ( & V_206 -> V_13 , 0 , V_250 -> V_13 ,
F_95 ( V_165 -> V_266 ) - 1 ,
& V_206 -> V_68 , 0 , V_250 -> V_68 , 1 , 0 ) ;
F_98 ( & V_12 , 0 , V_250 -> V_13 - V_206 -> V_13 ,
F_95 ( V_165 -> V_266 ) ,
& V_10 , 0 , V_250 -> V_68 - V_206 -> V_68 , 2 , 0 ) ;
V_206 -> V_12 = V_12 / 2 ;
V_206 -> V_10 = V_10 / 2 ;
V_206 -> V_13 = V_250 -> V_13 - V_12 ;
V_206 -> V_68 = V_250 -> V_68 - V_10 ;
if ( V_15 -> V_17 -> V_22 == V_23 &&
F_30 ( V_15 ) ) {
unsigned int V_146 ;
for ( V_146 = 0 ; V_146 < V_260 ; V_146 ++ ) {
struct V_157 * V_267 = & V_15 -> V_2 [ V_146 ] . V_6 . V_9 ;
if ( ( V_267 -> V_13 > V_206 -> V_13 ) == ( V_267 -> V_68 > V_206 -> V_68 ) )
continue;
* V_206 = V_15 -> V_159 ;
F_9 ( L_28 ) ;
break;
}
}
F_149 ( 1 , V_92 , & V_15 -> V_223 , L_29 ,
V_206 -> V_12 , V_206 -> V_10 , V_206 -> V_13 , V_206 -> V_68 , V_250 -> V_13 , V_250 -> V_68 ) ;
}
static int F_154 ( struct V_143 * V_19 ,
struct V_245 * V_246 ,
struct V_261 * V_202 )
{
struct V_14 * V_15 = F_146 ( V_19 ) ;
struct V_157 * V_158 = & V_15 -> V_159 ;
struct V_268 V_3 ;
if ( V_202 -> V_203 != V_262 || V_202 -> V_174 != V_252 )
return - V_21 ;
F_79 ( & V_15 -> V_120 ) ;
F_153 ( V_15 , & V_202 -> V_206 ) ;
if ( V_202 -> V_179 == V_251 ) {
* F_152 ( V_19 , V_246 , V_202 -> V_174 ) = V_202 -> V_206 ;
} else {
unsigned long V_44 ;
unsigned int V_146 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
* V_158 = V_202 -> V_206 ;
for ( V_146 = 0 ; V_146 < V_260 ; V_146 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_146 ] ;
V_3 = V_2 -> V_3 ;
if ( F_3 ( V_2 , & V_3 ) )
continue;
V_2 -> V_3 = V_3 ;
V_2 -> V_30 |= V_31 ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
}
F_77 ( & V_15 -> V_120 ) ;
F_149 ( 1 , V_92 , V_19 , L_30 ,
V_93 , V_158 -> V_12 , V_158 -> V_10 , V_158 -> V_13 , V_158 -> V_68 ,
V_15 -> V_184 . V_13 , V_15 -> V_184 . V_68 ) ;
return 0 ;
}
static int F_155 ( struct V_208 * V_209 )
{
struct V_14 * V_15 = F_66 ( V_209 -> V_269 , struct V_14 ,
V_240 ) ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_209 -> V_117 ) {
case V_270 :
V_15 -> V_26 = V_15 -> V_271 -> V_210 ;
switch ( V_209 -> V_210 ) {
case V_272 :
V_15 -> V_27 = 115 ;
V_15 -> V_28 = 145 ;
break;
case V_273 :
V_15 -> V_27 = V_15 -> V_274 -> V_210 >> 8 ;
V_15 -> V_28 = V_15 -> V_274 -> V_210 & 0xff ;
break;
default:
V_15 -> V_27 = 128 ;
V_15 -> V_28 = 128 ;
}
break;
case V_275 :
V_15 -> V_24 = V_15 -> V_276 -> V_210 ;
break;
default:
F_2 ( 1 ) ;
}
V_15 -> V_2 [ V_255 ] . V_30 |= V_31 ;
V_15 -> V_2 [ V_259 ] . V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_156 ( struct V_14 * V_15 )
{
struct V_277 * V_269 = & V_15 -> V_240 ;
struct V_143 * V_19 = & V_15 -> V_258 ;
int V_59 ;
F_157 ( V_19 , & V_278 ) ;
V_19 -> V_44 |= V_279 ;
F_86 ( V_19 -> V_145 , L_31 , sizeof( V_19 -> V_145 ) ) ;
V_15 -> V_175 [ V_252 ] . V_44 = V_239 ;
V_15 -> V_175 [ V_253 ] . V_44 = V_280 ;
V_15 -> V_175 [ V_254 ] . V_44 = V_280 ;
V_59 = F_130 ( & V_19 -> V_176 , V_281 ,
V_15 -> V_175 , 0 ) ;
if ( V_59 )
return V_59 ;
F_132 ( V_269 , 3 ) ;
V_15 -> V_276 = F_158 ( V_269 ,
& V_282 , V_275 ,
F_144 ( V_283 ) - 1 , 0 , 0 ,
V_283 ) ;
if ( V_15 -> V_17 -> V_25 ) {
V_15 -> V_271 = F_159 ( V_269 ,
& V_282 ,
V_270 , V_273 ,
~ 0x981f , V_284 ) ;
V_15 -> V_274 = F_133 ( V_269 ,
& V_282 ,
V_285 , 0 , 0xffff , 1 , 0 ) ;
}
if ( V_269 -> error ) {
F_137 ( V_269 ) ;
F_138 ( & V_19 -> V_176 ) ;
return V_269 -> error ;
}
if ( V_15 -> V_17 -> V_25 )
F_160 ( 2 , & V_15 -> V_271 ,
V_273 , false ) ;
V_19 -> V_240 = V_269 ;
F_161 ( V_19 , V_15 ) ;
return 0 ;
}
void F_162 ( struct V_14 * V_15 )
{
struct V_143 * V_19 = & V_15 -> V_258 ;
if ( F_146 ( V_19 ) == NULL )
return;
F_163 ( V_19 ) ;
F_138 ( & V_19 -> V_176 ) ;
F_137 ( & V_15 -> V_240 ) ;
F_161 ( V_19 , NULL ) ;
}
int F_164 ( struct V_14 * V_15 )
{
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_260 ; V_146 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_146 ] ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_117 = V_146 ;
V_2 -> V_286 = V_15 -> V_17 -> V_287 ;
if ( V_32 == V_23 )
V_2 -> V_288 = V_146 ? V_289 :
V_290 ;
else
V_2 -> V_288 = V_291 ;
V_2 -> V_20 = F_59 ( V_2 , NULL , 0 ) ;
F_165 ( V_2 -> V_20 == NULL ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_11 = V_292 ;
V_5 -> V_108 = V_293 ;
V_5 -> V_9 . V_13 = V_292 ;
V_5 -> V_9 . V_68 = V_293 ;
V_2 -> V_3 . V_90 = 1 ;
V_2 -> V_111 = ( V_5 -> V_11 * V_5 -> V_108 *
V_2 -> V_20 -> V_107 ) / 8 ;
}
memset ( & V_15 -> V_184 , 0 , sizeof( V_15 -> V_184 ) ) ;
V_15 -> V_184 . V_13 = V_292 ;
V_15 -> V_184 . V_68 = V_293 ;
V_15 -> V_184 . V_185 = V_248 [ 0 ] ;
memset ( & V_15 -> V_159 , 0 , sizeof( V_15 -> V_159 ) ) ;
V_15 -> V_159 . V_13 = V_292 ;
V_15 -> V_159 . V_68 = V_293 ;
return 0 ;
}
