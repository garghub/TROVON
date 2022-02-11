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
V_81 -> V_55 . V_56 . V_82 = F_47 () ;
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
static int F_58 ( struct V_87 * V_88 ,
unsigned int * V_94 , unsigned int * V_95 ,
unsigned int V_96 [] , void * V_97 [] )
{
struct V_1 * V_2 = F_52 ( V_88 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_66 = & V_2 -> V_6 ;
const struct V_98 * V_99 = V_2 -> V_20 ;
unsigned int V_100 ;
if ( V_99 == NULL )
return - V_21 ;
V_100 = ( V_66 -> V_11 * V_66 -> V_101 * V_99 -> V_102 ) / 8 ;
V_97 [ 0 ] = V_15 -> V_103 ;
if ( * V_95 )
return V_96 [ 0 ] < V_100 ? - V_21 : 0 ;
* V_95 = 1 ;
V_96 [ 0 ] = V_100 ;
F_9 ( L_7 , V_96 [ 0 ] ) ;
return 0 ;
}
static int F_59 ( struct V_63 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_87 ) ;
if ( V_2 -> V_20 == NULL )
return - V_21 ;
if ( F_60 ( V_55 , 0 ) < V_2 -> V_104 ) {
F_55 ( & V_2 -> V_91 , L_8 ,
F_60 ( V_55 , 0 ) , V_2 -> V_104 ) ;
return - V_21 ;
}
F_61 ( V_55 , 0 , V_2 -> V_104 ) ;
return 0 ;
}
static void F_62 ( struct V_63 * V_55 )
{
struct V_105 * V_81 = F_63 ( V_55 ) ;
struct V_42 * V_43 = F_64 ( V_81 , struct V_42 , V_55 ) ;
struct V_1 * V_2 = F_52 ( V_55 -> V_87 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
F_2 ( F_36 ( V_2 , & V_43 -> V_55 . V_56 , & V_43 -> V_65 ) ) ;
if ( ! ( V_2 -> V_30 & V_52 ) && V_2 -> V_106 < 2 ) {
V_43 -> V_80 = V_2 -> V_107 ;
F_48 ( V_2 , & V_43 -> V_65 , V_43 -> V_80 ) ;
F_48 ( V_2 , & V_43 -> V_65 , V_43 -> V_80 + 2 ) ;
F_49 ( V_2 , V_43 ) ;
V_2 -> V_107 = ! V_2 -> V_107 ;
} else {
F_65 ( V_2 , V_43 ) ;
}
if ( F_66 ( & V_2 -> V_108 ) && ! F_24 ( & V_2 -> V_54 )
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
static int F_67 ( struct V_109 * V_109 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_9 , V_2 -> V_110 ,
V_2 -> V_30 , V_2 -> V_111 , F_69 ( V_112 ) ) ;
if ( F_70 ( & V_15 -> V_113 ) )
return - V_114 ;
V_59 = F_71 ( V_109 ) ;
if ( V_59 < 0 )
goto V_79;
V_59 = F_72 ( V_15 -> V_115 ) ;
if ( V_59 < 0 )
goto V_116;
V_59 = F_19 ( V_15 , 1 ) ;
if ( ! V_59 )
goto V_79;
F_73 ( V_15 -> V_115 ) ;
V_116:
F_74 ( V_109 ) ;
V_79:
F_75 ( & V_15 -> V_113 ) ;
return V_59 ;
}
static int F_76 ( struct V_109 * V_109 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_10 , V_2 -> V_110 ,
V_2 -> V_30 , V_2 -> V_111 , F_69 ( V_112 ) ) ;
F_77 ( & V_15 -> V_113 ) ;
if ( V_2 -> V_111 == V_109 -> V_117 ) {
F_31 ( V_2 ) ;
F_78 ( & V_2 -> V_108 ) ;
V_2 -> V_111 = NULL ;
}
F_19 ( V_15 , 0 ) ;
F_73 ( V_15 -> V_115 ) ;
V_59 = F_74 ( V_109 ) ;
F_75 ( & V_15 -> V_113 ) ;
return V_59 ;
}
static unsigned int F_79 ( struct V_109 * V_109 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_77 ( & V_15 -> V_113 ) ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_109 -> V_117 )
V_59 = - V_120 ;
else
V_59 = F_80 ( & V_2 -> V_108 , V_109 , V_119 ) ;
F_75 ( & V_15 -> V_113 ) ;
return V_59 ;
}
static int F_81 ( struct V_109 * V_109 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
int V_59 ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_109 -> V_117 )
V_59 = - V_120 ;
else
V_59 = F_82 ( & V_2 -> V_108 , V_122 ) ;
return V_59 ;
}
static int F_83 ( struct V_109 * V_109 , void * V_77 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
F_84 ( V_124 -> V_125 , V_126 , sizeof( V_124 -> V_125 ) ) ;
F_84 ( V_124 -> V_127 , V_126 , sizeof( V_124 -> V_127 ) ) ;
snprintf ( V_124 -> V_128 , sizeof( V_124 -> V_128 ) , L_11 ,
F_85 ( V_2 -> V_15 -> V_115 ) , V_2 -> V_110 ) ;
V_124 -> V_129 = V_130 | V_131 ;
V_124 -> V_132 = V_124 -> V_129 | V_133 ;
return 0 ;
}
static int F_86 ( struct V_109 * V_109 , void * V_77 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_136 * V_18 = V_2 -> V_15 -> V_18 . V_19 ;
if ( V_135 -> V_80 || V_18 == NULL )
return - V_21 ;
V_135 -> type = V_137 ;
F_84 ( V_135 -> V_138 , V_18 -> V_138 , sizeof( V_135 -> V_138 ) ) ;
return 0 ;
}
static int F_87 ( struct V_109 * V_109 , void * V_77 ,
unsigned int V_139 )
{
return V_139 == 0 ? 0 : - V_21 ;
}
static int F_88 ( struct V_109 * V_109 , void * V_77 ,
unsigned int * V_139 )
{
* V_139 = 0 ;
return 0 ;
}
static int F_89 ( struct V_109 * V_109 , void * V_77 ,
struct V_140 * V_5 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
const struct V_98 * V_99 ;
V_99 = F_90 ( V_2 , NULL , V_5 -> V_80 ) ;
if ( ! V_99 )
return - V_21 ;
F_84 ( V_5 -> V_141 , V_99 -> V_138 , sizeof( V_5 -> V_141 ) ) ;
V_5 -> V_142 = V_99 -> V_143 ;
F_9 ( L_12 , V_5 -> V_80 , V_5 -> V_141 ) ;
return 0 ;
}
static int F_91 ( struct V_109 * V_109 , void * V_77 ,
struct V_144 * V_5 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_145 * V_146 = & V_5 -> V_99 . V_146 ;
struct V_4 * V_66 = & V_2 -> V_6 ;
const struct V_98 * V_99 = V_2 -> V_20 ;
V_146 -> V_147 = V_66 -> V_11 * V_99 -> V_148 ;
V_146 -> V_149 = V_2 -> V_104 ;
V_146 -> V_142 = V_99 -> V_143 ;
V_146 -> V_13 = V_66 -> V_11 ;
V_146 -> V_68 = V_66 -> V_101 ;
V_146 -> V_150 = V_151 ;
V_146 -> V_152 = V_153 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
const struct V_98 * * V_154 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_155 * V_156 = & V_15 -> V_157 ;
unsigned int V_158 , V_159 , V_160 , V_161 ;
const struct V_162 * V_163 ;
const struct V_98 * V_99 ;
V_99 = F_90 ( V_2 , & V_146 -> V_142 , 0 ) ;
if ( F_2 ( V_99 == NULL ) )
return - V_21 ;
if ( V_154 )
* V_154 = V_99 ;
V_163 = & V_15 -> V_17 -> V_162 [ V_2 -> V_110 ] ;
F_9 ( L_13 ,
V_146 -> V_13 , V_146 -> V_68 , V_156 -> V_13 , V_156 -> V_68 ,
V_146 -> V_147 ) ;
V_160 = F_93 ( V_164 , 1 << ( F_94 ( V_156 -> V_13 ) - 3 ) ) ;
V_161 = F_93 ( V_164 , 1 << ( F_94 ( V_156 -> V_68 ) - 1 ) ) ;
V_158 = F_95 ( T_1 , V_163 -> V_165 , V_156 -> V_13 / V_160 ) ;
V_158 = F_96 ( V_158 , V_163 -> V_166 ) ;
V_159 = F_95 ( T_1 , 8 , V_156 -> V_68 / V_161 ) ;
V_159 = F_96 ( V_159 , 8 ) ;
F_97 ( & V_146 -> V_13 , V_158 , V_163 -> V_167 ,
F_94 ( V_163 -> V_166 ) - 1 ,
& V_146 -> V_68 , V_159 , V_163 -> V_168 , 0 , 0 ) ;
V_146 -> V_147 = V_146 -> V_13 * V_99 -> V_148 ;
V_146 -> V_149 = ( V_146 -> V_13 * V_146 -> V_68 * V_99 -> V_102 ) / 8 ;
V_146 -> V_142 = V_99 -> V_143 ;
V_146 -> V_152 = V_153 ;
V_146 -> V_150 = V_151 ;
F_9 ( L_14 ,
V_146 -> V_13 , V_146 -> V_68 , V_158 , V_159 , V_160 , V_161 ) ;
return 0 ;
}
static int F_98 ( struct V_109 * V_109 , void * V_77 ,
struct V_144 * V_5 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
return F_92 ( V_2 , & V_5 -> V_99 . V_146 , NULL ) ;
}
static int F_99 ( struct V_109 * V_109 , void * V_77 ,
struct V_144 * V_5 )
{
struct V_145 * V_146 = & V_5 -> V_99 . V_146 ;
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_4 * V_6 = & V_2 -> V_6 ;
const struct V_98 * V_99 = NULL ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_110 ) ;
if ( F_100 ( & V_2 -> V_108 ) )
return - V_120 ;
V_59 = F_92 ( V_2 , & V_5 -> V_99 . V_146 , & V_99 ) ;
if ( V_59 < 0 )
return V_59 ;
V_2 -> V_20 = V_99 ;
V_2 -> V_104 = V_146 -> V_149 ;
V_6 -> V_11 = V_146 -> V_13 ;
V_6 -> V_101 = V_146 -> V_68 ;
V_6 -> V_9 . V_13 = V_146 -> V_13 ;
V_6 -> V_9 . V_68 = V_146 -> V_68 ;
V_6 -> V_9 . V_12 = 0 ;
V_6 -> V_9 . V_10 = 0 ;
if ( V_2 -> V_111 == NULL )
V_2 -> V_111 = V_77 ;
F_9 ( L_16 ,
V_6 -> V_11 , V_6 -> V_101 , V_2 -> V_104 , V_99 -> V_138 ,
V_146 -> V_13 * V_146 -> V_68 * V_99 -> V_102 , V_99 -> V_102 ,
V_146 -> V_149 , V_146 -> V_147 ) ;
return 0 ;
}
static int F_101 ( struct V_14 * V_15 )
{
struct V_169 V_170 ;
struct V_171 * V_172 ;
int V_59 ;
V_172 = F_102 ( & V_15 -> V_173 [ 0 ] ) ;
if ( ! V_172 || ! F_103 ( V_172 -> V_174 ) )
return - V_175 ;
V_170 . V_172 = V_172 -> V_80 ;
V_170 . V_176 = V_177 ;
V_59 = F_20 ( V_15 -> V_18 . V_19 , V_172 , V_178 , NULL , & V_170 ) ;
if ( V_59 < 0 && V_59 != - V_179 )
return - V_175 ;
if ( V_170 . V_180 . V_13 != V_15 -> V_181 . V_13 ||
V_170 . V_180 . V_68 != V_15 -> V_181 . V_68 ||
V_170 . V_180 . V_182 != V_15 -> V_181 . V_182 )
return - V_175 ;
return 0 ;
}
static int F_104 ( struct V_109 * V_109 , void * V_77 ,
enum V_183 type )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_184 * V_18 = & V_15 -> V_18 . V_19 -> V_174 ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_110 ) ;
if ( type != V_185 )
return - V_21 ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
if ( F_29 ( V_2 ) )
return 0 ;
V_59 = F_105 ( V_18 , V_15 -> V_186 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_101 ( V_15 ) ;
if ( V_59 < 0 ) {
F_106 ( V_18 ) ;
return V_59 ;
}
return F_107 ( & V_2 -> V_108 , type ) ;
}
static int F_108 ( struct V_109 * V_109 , void * V_77 ,
enum V_183 type )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_59 ;
F_9 ( L_15 , V_2 -> V_110 ) ;
if ( type != V_185 )
return - V_21 ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
V_59 = F_109 ( & V_2 -> V_108 , type ) ;
if ( V_59 == 0 )
F_106 ( & V_15 -> V_18 . V_19 -> V_174 ) ;
return V_59 ;
}
static int F_110 ( struct V_109 * V_109 , void * V_77 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
int V_59 ;
F_9 ( L_17 ,
V_2 -> V_110 , V_188 -> V_89 , V_2 -> V_111 , V_77 ) ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
if ( V_188 -> V_89 )
V_188 -> V_89 = F_95 ( T_1 , V_189 , V_188 -> V_89 ) ;
else
V_2 -> V_111 = NULL ;
V_59 = F_111 ( & V_2 -> V_108 , V_188 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_188 -> V_89 && V_188 -> V_89 < V_189 ) {
V_188 -> V_89 = 0 ;
F_111 ( & V_2 -> V_108 , V_188 ) ;
V_59 = - V_190 ;
}
V_2 -> V_191 = V_188 -> V_89 ;
if ( V_2 -> V_111 == NULL && V_188 -> V_89 > 0 )
V_2 -> V_111 = V_77 ;
return V_59 ;
}
static int F_112 ( struct V_109 * V_109 , void * V_77 ,
struct V_192 * V_43 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
return F_113 ( & V_2 -> V_108 , V_43 ) ;
}
static int F_114 ( struct V_109 * V_109 , void * V_77 ,
struct V_192 * V_43 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
F_9 ( L_15 , V_2 -> V_110 ) ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
return F_115 ( & V_2 -> V_108 , V_43 ) ;
}
static int F_116 ( struct V_109 * V_109 , void * V_77 ,
struct V_192 * V_43 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
F_9 ( L_18 , V_2 -> V_110 , V_2 -> V_84 ) ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
return F_117 ( & V_2 -> V_108 , V_43 , V_109 -> V_193 & V_194 ) ;
}
static int F_118 ( struct V_109 * V_109 , void * V_77 ,
struct V_195 * V_196 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
int V_59 ;
if ( V_2 -> V_111 && V_2 -> V_111 != V_77 )
return - V_120 ;
V_196 -> V_89 = F_95 ( T_1 , 1 , V_196 -> V_89 ) ;
V_59 = F_119 ( & V_2 -> V_108 , V_196 ) ;
if ( ! V_59 && V_2 -> V_111 == NULL )
V_2 -> V_111 = V_77 ;
return V_59 ;
}
static int F_120 ( struct V_109 * V_109 , void * V_77 ,
struct V_192 * V_197 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
return F_121 ( & V_2 -> V_108 , V_197 ) ;
}
static int F_122 ( struct V_109 * V_109 , void * V_77 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
if ( V_199 -> type != V_185 )
return - V_21 ;
switch ( V_199 -> V_200 ) {
case V_201 :
case V_202 :
V_199 -> V_203 . V_12 = 0 ;
V_199 -> V_203 . V_10 = 0 ;
V_199 -> V_203 . V_13 = V_2 -> V_6 . V_11 ;
V_199 -> V_203 . V_68 = V_2 -> V_6 . V_101 ;
return 0 ;
case V_204 :
V_199 -> V_203 = V_2 -> V_6 . V_9 ;
return 0 ;
}
return - V_21 ;
}
static void F_123 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_155 * V_203 )
{
if ( V_15 -> V_17 -> V_22 == V_23 ) {
* V_203 = V_2 -> V_6 . V_9 ;
return;
}
}
static int F_124 ( struct V_109 * V_109 , void * V_77 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = F_68 ( V_109 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_155 V_9 = V_199 -> V_203 ;
unsigned long V_44 ;
if ( V_199 -> type != V_185 ||
V_199 -> V_200 != V_204 )
return - V_21 ;
F_123 ( V_15 , V_2 , & V_9 ) ;
V_199 -> V_203 = V_9 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_6 . V_9 = V_9 ;
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
F_9 ( L_19 ,
V_199 -> type , V_199 -> V_200 , V_199 -> V_44 ,
V_199 -> V_203 . V_12 , V_199 -> V_203 . V_10 , V_199 -> V_203 . V_13 , V_199 -> V_203 . V_68 ) ;
return 0 ;
}
static int F_125 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = V_206 -> V_77 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_9 ( L_20 , V_2 -> V_110 ,
V_206 -> V_138 , V_206 -> V_207 ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_206 -> V_110 ) {
case V_208 :
V_2 -> V_209 = V_206 -> V_207 ;
break;
case V_210 :
V_2 -> V_211 = V_206 -> V_207 ;
break;
}
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_126 ( struct V_14 * V_15 , int V_212 )
{
struct V_1 * V_2 = & V_15 -> V_2 [ V_212 ] ;
struct V_87 * V_213 = & V_2 -> V_108 ;
struct V_214 * V_215 = & V_2 -> V_91 ;
struct V_205 * V_206 ;
int V_59 ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
snprintf ( V_215 -> V_138 , sizeof( V_215 -> V_138 ) , L_21 ,
V_2 -> V_110 == 0 ? L_22 : L_23 ) ;
V_215 -> V_216 = & V_217 ;
V_215 -> V_218 = & V_219 ;
V_215 -> V_220 = & V_15 -> V_220 ;
V_215 -> V_221 = - 1 ;
V_215 -> V_222 = V_223 ;
V_215 -> V_113 = & V_15 -> V_113 ;
V_2 -> V_191 = 0 ;
F_127 ( & V_2 -> V_54 ) ;
F_127 ( & V_2 -> V_58 ) ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> type = V_185 ;
V_213 -> V_224 = V_225 | V_226 ;
V_213 -> V_227 = & V_228 ;
V_213 -> V_229 = & V_230 ;
V_213 -> V_231 = sizeof( struct V_42 ) ;
V_213 -> V_232 = V_2 ;
V_213 -> V_233 = V_234 ;
V_213 -> V_113 = & V_2 -> V_15 -> V_113 ;
V_59 = F_128 ( V_213 ) ;
if ( V_59 )
goto V_235;
V_2 -> V_172 . V_44 = V_236 ;
V_59 = F_129 ( & V_215 -> V_174 , 1 , & V_2 -> V_172 ) ;
if ( V_59 )
goto V_235;
F_130 ( V_215 , V_2 ) ;
F_131 ( & V_2 -> V_237 , 1 ) ;
V_206 = F_132 ( & V_2 -> V_237 , & V_238 ,
V_208 , 0 , 1 , 1 , 0 ) ;
if ( V_206 )
V_206 -> V_77 = V_2 ;
V_206 = F_132 ( & V_2 -> V_237 , & V_238 ,
V_210 , 0 , 1 , 1 , 0 ) ;
if ( V_206 )
V_206 -> V_77 = V_2 ;
V_59 = V_2 -> V_237 . error ;
if ( V_59 < 0 )
goto V_239;
V_215 -> V_237 = & V_2 -> V_237 ;
V_59 = F_133 ( V_215 , V_240 , - 1 ) ;
if ( V_59 )
goto V_241;
F_134 ( & V_15 -> V_220 , L_24 ,
V_215 -> V_138 , F_135 ( V_215 ) ) ;
return 0 ;
V_241:
F_136 ( & V_2 -> V_237 ) ;
V_239:
F_137 ( & V_215 -> V_174 ) ;
V_235:
F_138 ( V_215 ) ;
return V_59 ;
}
void F_139 ( struct V_14 * V_15 , int V_212 )
{
struct V_214 * V_215 = & V_15 -> V_2 [ V_212 ] . V_91 ;
if ( F_140 ( V_215 ) ) {
F_141 ( V_215 ) ;
F_137 ( & V_215 -> V_174 ) ;
F_136 ( V_215 -> V_237 ) ;
}
}
static int F_142 ( struct V_136 * V_19 ,
struct V_242 * V_243 ,
struct V_244 * V_182 )
{
if ( V_182 -> V_80 >= F_143 ( V_245 ) )
return - V_21 ;
V_182 -> V_182 = V_245 [ V_182 -> V_80 ] ;
return 0 ;
}
static int F_144 ( struct V_136 * V_19 ,
struct V_242 * V_243 ,
struct V_169 * V_99 )
{
struct V_14 * V_15 = F_145 ( V_19 ) ;
struct V_246 * V_247 = & V_99 -> V_180 ;
if ( V_99 -> V_176 == V_248 ) {
V_247 = F_146 ( V_19 , V_243 , V_99 -> V_172 ) ;
V_99 -> V_180 = * V_247 ;
return 0 ;
}
F_77 ( & V_15 -> V_113 ) ;
switch ( V_99 -> V_172 ) {
case V_249 :
* V_247 = V_15 -> V_181 ;
break;
case V_250 ... V_251 :
V_247 -> V_13 = V_15 -> V_157 . V_13 ;
V_247 -> V_68 = V_15 -> V_157 . V_68 ;
V_247 -> V_182 = V_15 -> V_181 . V_182 ;
break;
}
F_75 ( & V_15 -> V_113 ) ;
V_247 -> V_150 = V_151 ;
V_247 -> V_152 = V_153 ;
return 0 ;
}
static void F_147 ( struct V_14 * V_15 ,
struct V_246 * V_247 , int V_172 )
{
const struct V_16 * V_17 = V_15 -> V_17 ;
const struct V_162 * V_163 ;
int V_139 = F_143 ( V_245 ) ;
V_163 = & V_17 -> V_162 [ V_252 ] ;
while ( V_139 -- >= 0 )
if ( V_245 [ V_139 ] == V_247 -> V_182 )
break;
V_247 -> V_182 = V_245 [ V_139 ] ;
if ( V_172 == V_249 ) {
F_97 ( & V_247 -> V_13 , 8 , V_253 ,
F_94 ( V_163 -> V_166 ) - 1 ,
& V_247 -> V_68 , 8 , V_254 , 0 ,
0 ) ;
} else {
struct V_155 * V_156 = & V_15 -> V_157 ;
F_97 ( & V_247 -> V_13 , 8 , V_156 -> V_13 ,
F_94 ( V_163 -> V_166 ) - 1 ,
& V_247 -> V_68 , 8 , V_156 -> V_68 ,
0 , 0 ) ;
}
F_148 ( 1 , V_92 , & V_15 -> V_255 , L_25 , V_247 -> V_13 , V_247 -> V_68 ) ;
}
static int F_149 ( struct V_136 * V_19 ,
struct V_242 * V_243 ,
struct V_169 * V_99 )
{
struct V_14 * V_15 = F_145 ( V_19 ) ;
struct V_246 * V_247 = & V_99 -> V_180 ;
struct V_155 * V_156 = & V_15 -> V_157 ;
int V_139 ;
F_148 ( 1 , V_92 , V_19 , L_26 ,
V_99 -> V_172 , V_247 -> V_182 , V_247 -> V_13 , V_247 -> V_68 ) ;
V_247 -> V_150 = V_151 ;
V_247 -> V_152 = V_153 ;
F_77 ( & V_15 -> V_113 ) ;
if ( F_100 ( & V_15 -> V_2 [ V_252 ] . V_108 ) ||
F_100 ( & V_15 -> V_2 [ V_256 ] . V_108 ) ) {
F_75 ( & V_15 -> V_113 ) ;
return - V_120 ;
}
F_147 ( V_15 , V_247 , V_99 -> V_172 ) ;
if ( V_99 -> V_176 == V_248 ) {
V_247 = F_146 ( V_19 , V_243 , V_99 -> V_172 ) ;
* V_247 = V_99 -> V_180 ;
F_75 ( & V_15 -> V_113 ) ;
return 0 ;
}
switch ( V_99 -> V_172 ) {
case V_249 :
V_15 -> V_181 = * V_247 ;
V_156 -> V_13 = V_247 -> V_13 ;
V_156 -> V_68 = V_247 -> V_68 ;
V_156 -> V_12 = 0 ;
V_156 -> V_10 = 0 ;
for ( V_139 = 0 ; V_139 < V_257 ; V_139 ++ ) {
struct V_4 * V_66 = & V_15 -> V_2 [ V_139 ] . V_6 ;
V_66 -> V_9 = * V_156 ;
V_66 -> V_11 = V_247 -> V_13 ;
V_66 -> V_101 = V_247 -> V_68 ;
}
break;
case V_250 ... V_251 :
V_247 -> V_182 = V_15 -> V_181 . V_182 ;
V_247 -> V_13 = V_156 -> V_13 ;
V_247 -> V_68 = V_156 -> V_68 ;
break;
}
F_75 ( & V_15 -> V_113 ) ;
return 0 ;
}
static int F_150 ( struct V_136 * V_19 ,
struct V_242 * V_243 ,
struct V_258 * V_199 )
{
struct V_14 * V_15 = F_145 ( V_19 ) ;
struct V_155 * V_156 = & V_15 -> V_157 ;
struct V_246 * V_247 = & V_15 -> V_181 ;
if ( ( V_199 -> V_200 != V_259 &&
V_199 -> V_200 != V_260 ) ||
V_199 -> V_172 != V_249 )
return - V_21 ;
if ( V_199 -> V_176 == V_248 ) {
V_199 -> V_203 = * F_151 ( V_19 , V_243 , V_199 -> V_172 ) ;
return 0 ;
}
F_77 ( & V_15 -> V_113 ) ;
if ( V_199 -> V_200 == V_259 ) {
V_199 -> V_203 = * V_156 ;
} else {
V_199 -> V_203 . V_13 = V_247 -> V_13 ;
V_199 -> V_203 . V_68 = V_247 -> V_68 ;
V_199 -> V_203 . V_12 = 0 ;
V_199 -> V_203 . V_10 = 0 ;
}
F_75 ( & V_15 -> V_113 ) ;
F_148 ( 1 , V_92 , V_19 , L_27 ,
V_93 , V_156 -> V_12 , V_156 -> V_10 , V_156 -> V_13 ,
V_156 -> V_68 , V_247 -> V_13 , V_247 -> V_68 ) ;
return 0 ;
}
static void F_152 ( struct V_14 * V_15 , struct V_155 * V_203 )
{
struct V_246 * V_247 = & V_15 -> V_181 ;
const struct V_261 * V_163 = & V_15 -> V_17 -> V_262 ;
unsigned int V_12 = 2 * V_203 -> V_12 ;
unsigned int V_10 = 2 * V_203 -> V_10 ;
F_97 ( & V_203 -> V_13 , 0 , V_247 -> V_13 ,
F_94 ( V_163 -> V_263 ) - 1 ,
& V_203 -> V_68 , 0 , V_247 -> V_68 , 1 , 0 ) ;
F_97 ( & V_12 , 0 , V_247 -> V_13 - V_203 -> V_13 ,
F_94 ( V_163 -> V_263 ) ,
& V_10 , 0 , V_247 -> V_68 - V_203 -> V_68 , 2 , 0 ) ;
V_203 -> V_12 = V_12 / 2 ;
V_203 -> V_10 = V_10 / 2 ;
V_203 -> V_13 = V_247 -> V_13 - V_12 ;
V_203 -> V_68 = V_247 -> V_68 - V_10 ;
if ( V_15 -> V_17 -> V_22 == V_23 &&
F_30 ( V_15 ) ) {
unsigned int V_139 ;
for ( V_139 = 0 ; V_139 < V_257 ; V_139 ++ ) {
struct V_155 * V_264 = & V_15 -> V_2 [ V_139 ] . V_6 . V_9 ;
if ( ( V_264 -> V_13 > V_203 -> V_13 ) == ( V_264 -> V_68 > V_203 -> V_68 ) )
continue;
* V_203 = V_15 -> V_157 ;
F_9 ( L_28 ) ;
break;
}
}
F_148 ( 1 , V_92 , & V_15 -> V_220 , L_29 ,
V_203 -> V_12 , V_203 -> V_10 , V_203 -> V_13 , V_203 -> V_68 , V_247 -> V_13 , V_247 -> V_68 ) ;
}
static int F_153 ( struct V_136 * V_19 ,
struct V_242 * V_243 ,
struct V_258 * V_199 )
{
struct V_14 * V_15 = F_145 ( V_19 ) ;
struct V_155 * V_156 = & V_15 -> V_157 ;
struct V_265 V_3 ;
if ( V_199 -> V_200 != V_259 || V_199 -> V_172 != V_249 )
return - V_21 ;
F_77 ( & V_15 -> V_113 ) ;
F_152 ( V_15 , & V_199 -> V_203 ) ;
if ( V_199 -> V_176 == V_248 ) {
* F_151 ( V_19 , V_243 , V_199 -> V_172 ) = V_199 -> V_203 ;
} else {
unsigned long V_44 ;
unsigned int V_139 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
* V_156 = V_199 -> V_203 ;
for ( V_139 = 0 ; V_139 < V_257 ; V_139 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_139 ] ;
V_3 = V_2 -> V_3 ;
if ( F_3 ( V_2 , & V_3 ) )
continue;
V_2 -> V_3 = V_3 ;
V_2 -> V_30 |= V_31 ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
}
F_75 ( & V_15 -> V_113 ) ;
F_148 ( 1 , V_92 , V_19 , L_30 ,
V_93 , V_156 -> V_12 , V_156 -> V_10 , V_156 -> V_13 , V_156 -> V_68 ,
V_15 -> V_181 . V_13 , V_15 -> V_181 . V_68 ) ;
return 0 ;
}
static int F_154 ( struct V_205 * V_206 )
{
struct V_14 * V_15 = F_64 ( V_206 -> V_266 , struct V_14 ,
V_237 ) ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_206 -> V_110 ) {
case V_267 :
V_15 -> V_26 = V_15 -> V_268 -> V_207 ;
switch ( V_206 -> V_207 ) {
case V_269 :
V_15 -> V_27 = 115 ;
V_15 -> V_28 = 145 ;
break;
case V_270 :
V_15 -> V_27 = V_15 -> V_271 -> V_207 >> 8 ;
V_15 -> V_28 = V_15 -> V_271 -> V_207 & 0xff ;
break;
default:
V_15 -> V_27 = 128 ;
V_15 -> V_28 = 128 ;
}
break;
case V_272 :
V_15 -> V_24 = V_15 -> V_273 -> V_207 ;
break;
default:
F_2 ( 1 ) ;
}
V_15 -> V_2 [ V_252 ] . V_30 |= V_31 ;
V_15 -> V_2 [ V_256 ] . V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_155 ( struct V_14 * V_15 )
{
struct V_274 * V_266 = & V_15 -> V_237 ;
struct V_136 * V_19 = & V_15 -> V_255 ;
int V_59 ;
F_156 ( V_19 , & V_275 ) ;
V_19 -> V_44 |= V_276 ;
F_84 ( V_19 -> V_138 , L_31 , sizeof( V_19 -> V_138 ) ) ;
V_15 -> V_173 [ V_249 ] . V_44 = V_236 ;
V_15 -> V_173 [ V_250 ] . V_44 = V_277 ;
V_15 -> V_173 [ V_251 ] . V_44 = V_277 ;
V_59 = F_129 ( & V_19 -> V_174 , V_278 ,
V_15 -> V_173 ) ;
if ( V_59 )
return V_59 ;
F_131 ( V_266 , 3 ) ;
V_15 -> V_273 = F_157 ( V_266 ,
& V_279 , V_272 ,
F_143 ( V_280 ) - 1 , 0 , 0 ,
V_280 ) ;
if ( V_15 -> V_17 -> V_25 ) {
V_15 -> V_268 = F_158 ( V_266 ,
& V_279 ,
V_267 , V_270 ,
~ 0x981f , V_281 ) ;
V_15 -> V_271 = F_132 ( V_266 ,
& V_279 ,
V_282 , 0 , 0xffff , 1 , 0 ) ;
}
if ( V_266 -> error ) {
F_136 ( V_266 ) ;
F_137 ( & V_19 -> V_174 ) ;
return V_266 -> error ;
}
if ( V_15 -> V_17 -> V_25 )
F_159 ( 2 , & V_15 -> V_268 ,
V_270 , false ) ;
V_19 -> V_237 = V_266 ;
F_160 ( V_19 , V_15 ) ;
return 0 ;
}
void F_161 ( struct V_14 * V_15 )
{
struct V_136 * V_19 = & V_15 -> V_255 ;
if ( F_145 ( V_19 ) == NULL )
return;
F_162 ( V_19 ) ;
F_137 ( & V_19 -> V_174 ) ;
F_136 ( & V_15 -> V_237 ) ;
F_160 ( V_19 , NULL ) ;
}
int F_163 ( struct V_14 * V_15 )
{
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_257 ; V_139 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_139 ] ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_110 = V_139 ;
V_2 -> V_283 = V_15 -> V_17 -> V_284 ;
if ( V_32 == V_23 )
V_2 -> V_285 = V_139 ? V_286 :
V_287 ;
else
V_2 -> V_285 = V_288 ;
V_2 -> V_20 = F_90 ( V_2 , NULL , 0 ) ;
F_164 ( V_2 -> V_20 == NULL ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_11 = V_289 ;
V_5 -> V_101 = V_290 ;
V_5 -> V_9 . V_13 = V_289 ;
V_5 -> V_9 . V_68 = V_290 ;
V_2 -> V_3 . V_90 = 1 ;
V_2 -> V_104 = ( V_5 -> V_11 * V_5 -> V_101 *
V_2 -> V_20 -> V_102 ) / 8 ;
}
memset ( & V_15 -> V_181 , 0 , sizeof( V_15 -> V_181 ) ) ;
V_15 -> V_181 . V_13 = V_289 ;
V_15 -> V_181 . V_68 = V_290 ;
V_15 -> V_181 . V_182 = V_245 [ 0 ] ;
memset ( & V_15 -> V_157 , 0 , sizeof( V_15 -> V_157 ) ) ;
V_15 -> V_157 . V_13 = V_289 ;
V_15 -> V_157 . V_68 = V_290 ;
return 0 ;
}
