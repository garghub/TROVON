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
if ( ! V_33 == V_15 -> V_18 . V_36 )
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
if ( ! V_33 == V_15 -> V_18 . V_39 )
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
F_26 ( & V_43 -> V_55 , V_56 ) ;
}
while ( ! F_24 ( & V_2 -> V_57 ) ) {
V_43 = F_27 ( V_2 ) ;
F_26 ( & V_43 -> V_55 , V_56 ) ;
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
bool V_58 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_58 = ( V_2 -> V_30 & V_49 ) || ( V_2 -> V_30 & V_48 ) ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return V_58 ;
}
static bool F_30 ( struct V_14 * V_15 )
{
unsigned long V_44 ;
bool V_59 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_59 = V_15 -> V_39 > 0 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return V_59 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
int V_58 ;
if ( ! F_29 ( V_2 ) )
return 0 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_30 &= ~ ( V_50 | V_53 ) ;
V_2 -> V_30 |= V_51 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
V_58 = F_32 ( V_2 -> V_60 ,
! ( V_2 -> V_30 & V_51 ) ,
F_33 ( V_61 ) ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
if ( V_58 == 0 && ! ( V_2 -> V_30 & V_50 ) ) {
V_2 -> V_30 &= ~ ( V_50 | V_51 |
V_53 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 , false ) ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
return F_22 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_62 * V_55 ,
struct V_63 * V_64 )
{
struct V_4 * V_65 = & V_2 -> V_6 ;
T_1 V_66 ;
if ( V_55 == NULL || V_65 == NULL )
return - V_21 ;
V_66 = V_65 -> V_9 . V_13 * V_65 -> V_9 . V_67 ;
F_9 ( L_4 ,
V_2 -> V_20 -> V_68 , V_66 ) ;
V_64 -> V_69 = F_37 ( V_55 , 0 ) ;
switch ( V_2 -> V_20 -> V_68 ) {
case 1 :
V_64 -> V_70 = 0 ;
V_64 -> V_71 = 0 ;
break;
case 2 :
V_64 -> V_70 = ( T_1 ) ( V_64 -> V_69 + V_66 ) ;
V_64 -> V_71 = 0 ;
break;
case 3 :
V_64 -> V_70 = ( T_1 ) ( V_64 -> V_69 + V_66 ) ;
if ( V_2 -> V_20 -> V_72 == V_73 )
V_64 -> V_71 = ( T_1 ) ( V_64 -> V_70 + ( V_66 >> 1 ) ) ;
else
V_64 -> V_71 = ( T_1 ) ( V_64 -> V_70 + ( V_66 >> 2 ) ) ;
if ( V_2 -> V_20 -> V_72 == V_74 )
F_38 ( V_64 -> V_70 , V_64 -> V_71 ) ;
break;
default:
return - V_21 ;
}
F_9 ( L_5 ,
V_64 -> V_69 , V_64 -> V_70 , V_64 -> V_71 ) ;
return 0 ;
}
T_2 F_39 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
unsigned int V_59 ;
F_40 ( & V_15 -> V_46 ) ;
if ( V_32 == V_29 )
F_41 ( V_2 ) ;
V_59 = F_42 ( V_2 ) ;
if ( V_32 == V_23 && ( V_59 & V_77 ) ) {
F_11 ( V_2 ) ;
goto V_78;
}
if ( V_2 -> V_30 & V_51 ) {
if ( V_2 -> V_30 & V_50 ) {
V_2 -> V_30 &= ~ ( V_50 | V_51 |
V_53 ) ;
F_43 ( & V_2 -> V_60 ) ;
goto V_78;
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
! F_24 ( & V_2 -> V_57 ) ) {
unsigned int V_79 ;
struct V_42 * V_80 ;
struct V_81 * V_82 ;
struct V_83 V_84 ;
V_79 = ( F_45 ( V_59 ) + 2 ) & 1 ;
F_46 ( & V_84 ) ;
V_80 = F_47 ( V_2 , V_79 ) ;
if ( ! F_2 ( V_80 == NULL ) ) {
V_82 = & V_80 -> V_55 . V_85 . V_86 ;
V_82 -> V_87 = V_84 . V_87 ;
V_82 -> V_88 = V_84 . V_89 / V_90 ;
V_80 -> V_55 . V_85 . V_91 = V_2 -> V_92 ++ ;
F_26 ( & V_80 -> V_55 , V_93 ) ;
V_80 = F_25 ( V_2 ) ;
V_80 -> V_79 = V_79 ;
F_48 ( V_2 , & V_80 -> V_64 , V_79 ) ;
F_48 ( V_2 , & V_80 -> V_64 , V_79 + 2 ) ;
F_49 ( V_2 , V_80 ) ;
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
V_78:
F_50 ( & V_15 -> V_46 ) ;
return V_94 ;
}
static int F_51 ( struct V_95 * V_96 , unsigned int V_97 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
int V_58 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
if ( V_15 -> V_39 == 0 ) {
F_53 ( V_15 ) ;
V_58 = F_10 ( V_15 , V_2 ) ;
} else {
V_58 = F_18 ( V_15 , V_2 ) ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
if ( V_58 < 0 ) {
F_22 ( V_2 ) ;
return V_58 ;
}
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_92 = 0 ;
V_2 -> V_30 |= V_48 ;
if ( ! F_24 ( & V_2 -> V_54 ) &&
( ! ( V_2 -> V_30 & V_52 ) ||
! ( V_2 -> V_30 & V_47 ) ) ) {
F_35 ( V_2 , V_2 -> V_3 . V_98 ) ;
F_54 ( V_2 ) ;
V_2 -> V_30 |= V_52 ;
if ( ! ( V_2 -> V_30 & V_47 ) ) {
V_2 -> V_30 |= V_47 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
V_58 = F_21 ( V_15 , 1 ) ;
if ( V_58 )
F_55 ( & V_2 -> V_99 , L_6 ) ;
if ( V_100 )
F_56 ( V_15 , V_101 ) ;
return V_58 ;
}
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
static void F_57 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
F_31 ( V_2 ) ;
}
static int F_58 ( struct V_95 * V_96 , const struct V_102 * V_103 ,
unsigned int * V_104 , unsigned int * V_105 ,
unsigned int V_106 [] , void * V_107 [] )
{
const struct V_108 * V_109 = NULL ;
struct V_1 * V_2 = F_52 ( V_96 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_65 = & V_2 -> V_6 ;
const struct V_110 * V_111 = V_2 -> V_20 ;
unsigned int V_112 ;
if ( V_103 ) {
V_109 = & V_103 -> V_111 . V_109 ;
V_111 = F_59 ( V_2 , & V_109 -> V_113 , - 1 ) ;
V_112 = ( V_109 -> V_13 * V_109 -> V_67 * V_111 -> V_114 ) / 8 ;
} else {
V_112 = ( V_65 -> V_11 * V_65 -> V_115 * V_111 -> V_114 ) / 8 ;
}
if ( V_111 == NULL )
return - V_21 ;
* V_105 = 1 ;
if ( V_109 )
V_106 [ 0 ] = F_60 ( V_112 , V_109 -> V_116 ) ;
else
V_106 [ 0 ] = V_112 ;
V_107 [ 0 ] = V_15 -> V_117 ;
F_9 ( L_7 , V_106 [ 0 ] ) ;
return 0 ;
}
static int F_61 ( struct V_62 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_95 ) ;
if ( V_2 -> V_20 == NULL )
return - V_21 ;
if ( F_62 ( V_55 , 0 ) < V_2 -> V_118 ) {
F_55 ( & V_2 -> V_99 , L_8 ,
F_62 ( V_55 , 0 ) , V_2 -> V_118 ) ;
return - V_21 ;
}
F_63 ( V_55 , 0 , V_2 -> V_118 ) ;
return 0 ;
}
static void F_64 ( struct V_62 * V_55 )
{
struct V_42 * V_43 = F_65 ( V_55 , struct V_42 , V_55 ) ;
struct V_1 * V_2 = F_52 ( V_55 -> V_95 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
F_2 ( F_36 ( V_2 , & V_43 -> V_55 , & V_43 -> V_64 ) ) ;
if ( ! ( V_2 -> V_30 & V_52 ) && V_2 -> V_119 < 2 ) {
V_43 -> V_79 = V_2 -> V_120 ;
F_48 ( V_2 , & V_43 -> V_64 , V_43 -> V_79 ) ;
F_48 ( V_2 , & V_43 -> V_64 , V_43 -> V_79 + 2 ) ;
F_49 ( V_2 , V_43 ) ;
V_2 -> V_120 = ! V_2 -> V_120 ;
} else {
F_66 ( V_2 , V_43 ) ;
}
if ( F_67 ( & V_2 -> V_121 ) && ! F_24 ( & V_2 -> V_54 )
&& ! ( V_2 -> V_30 & V_52 ) ) {
V_2 -> V_30 |= V_52 ;
F_35 ( V_2 , V_2 -> V_3 . V_98 ) ;
F_54 ( V_2 ) ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
if ( ! ( V_2 -> V_30 & V_47 ) ) {
if ( F_21 ( V_15 , 1 ) == 0 )
V_2 -> V_30 |= V_47 ;
else
F_55 ( & V_2 -> V_99 , L_6 ) ;
if ( V_100 )
F_56 ( V_15 , V_101 ) ;
}
return;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
}
static void F_68 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
F_69 ( & V_2 -> V_15 -> V_122 ) ;
}
static void F_70 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
F_71 ( & V_2 -> V_15 -> V_122 ) ;
}
static int F_72 ( struct V_123 * V_123 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_58 ;
F_9 ( L_9 , V_2 -> V_124 ,
V_2 -> V_30 , V_2 -> V_125 , F_74 ( V_126 ) ) ;
if ( F_75 ( & V_15 -> V_122 ) )
return - V_127 ;
V_58 = F_76 ( V_123 ) ;
if ( V_58 < 0 )
goto V_78;
V_58 = F_77 ( V_15 -> V_128 ) ;
if ( V_58 < 0 )
goto V_129;
V_58 = F_19 ( V_15 , 1 ) ;
if ( ! V_58 )
goto V_78;
F_78 ( V_15 -> V_128 ) ;
V_129:
F_79 ( V_123 ) ;
V_78:
F_71 ( & V_15 -> V_122 ) ;
return V_58 ;
}
static int F_80 ( struct V_123 * V_123 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_58 ;
F_9 ( L_10 , V_2 -> V_124 ,
V_2 -> V_30 , V_2 -> V_125 , F_74 ( V_126 ) ) ;
F_69 ( & V_15 -> V_122 ) ;
if ( V_2 -> V_125 == V_123 -> V_130 ) {
F_31 ( V_2 ) ;
F_81 ( & V_2 -> V_121 ) ;
V_2 -> V_125 = NULL ;
}
F_19 ( V_15 , 0 ) ;
F_78 ( V_15 -> V_128 ) ;
V_58 = F_79 ( V_123 ) ;
F_71 ( & V_15 -> V_122 ) ;
return V_58 ;
}
static unsigned int F_82 ( struct V_123 * V_123 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_58 ;
F_69 ( & V_15 -> V_122 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_123 -> V_130 )
V_58 = - V_133 ;
else
V_58 = F_83 ( & V_2 -> V_121 , V_123 , V_132 ) ;
F_71 ( & V_15 -> V_122 ) ;
return V_58 ;
}
static int F_84 ( struct V_123 * V_123 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
int V_58 ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_123 -> V_130 )
V_58 = - V_133 ;
else
V_58 = F_85 ( & V_2 -> V_121 , V_135 ) ;
return V_58 ;
}
static int F_86 ( struct V_123 * V_123 , void * V_76 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
F_87 ( V_137 -> V_138 , V_139 , sizeof( V_137 -> V_138 ) ) ;
F_87 ( V_137 -> V_140 , V_139 , sizeof( V_137 -> V_140 ) ) ;
snprintf ( V_137 -> V_141 , sizeof( V_137 -> V_141 ) , L_11 ,
F_88 ( V_2 -> V_15 -> V_128 ) , V_2 -> V_124 ) ;
V_137 -> V_142 = V_143 | V_144 ;
V_137 -> V_145 = V_137 -> V_142 | V_146 ;
return 0 ;
}
static int F_89 ( struct V_123 * V_123 , void * V_76 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_149 * V_18 = V_2 -> V_15 -> V_18 . V_19 ;
if ( V_148 -> V_79 || V_18 == NULL )
return - V_21 ;
V_148 -> type = V_150 ;
F_87 ( V_148 -> V_151 , V_18 -> V_151 , sizeof( V_148 -> V_151 ) ) ;
return 0 ;
}
static int F_90 ( struct V_123 * V_123 , void * V_76 ,
unsigned int V_152 )
{
return V_152 == 0 ? 0 : - V_21 ;
}
static int F_91 ( struct V_123 * V_123 , void * V_76 ,
unsigned int * V_152 )
{
* V_152 = 0 ;
return 0 ;
}
static int F_92 ( struct V_123 * V_123 , void * V_76 ,
struct V_153 * V_5 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
const struct V_110 * V_111 ;
V_111 = F_59 ( V_2 , NULL , V_5 -> V_79 ) ;
if ( ! V_111 )
return - V_21 ;
F_87 ( V_5 -> V_154 , V_111 -> V_151 , sizeof( V_5 -> V_154 ) ) ;
V_5 -> V_113 = V_111 -> V_155 ;
F_9 ( L_12 , V_5 -> V_79 , V_5 -> V_154 ) ;
return 0 ;
}
static int F_93 ( struct V_123 * V_123 , void * V_76 ,
struct V_102 * V_5 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_108 * V_109 = & V_5 -> V_111 . V_109 ;
struct V_4 * V_65 = & V_2 -> V_6 ;
const struct V_110 * V_111 = V_2 -> V_20 ;
V_109 -> V_156 = V_65 -> V_11 * V_111 -> V_157 ;
V_109 -> V_116 = V_2 -> V_118 ;
V_109 -> V_113 = V_111 -> V_155 ;
V_109 -> V_13 = V_65 -> V_11 ;
V_109 -> V_67 = V_65 -> V_115 ;
V_109 -> V_158 = V_159 ;
V_109 -> V_160 = V_161 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
const struct V_110 * * V_162 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_163 * V_164 = & V_15 -> V_165 ;
unsigned int V_166 , V_167 , V_168 , V_169 ;
const struct V_170 * V_171 ;
const struct V_110 * V_111 ;
V_111 = F_59 ( V_2 , & V_109 -> V_113 , 0 ) ;
if ( F_2 ( V_111 == NULL ) )
return - V_21 ;
if ( V_162 )
* V_162 = V_111 ;
V_171 = & V_15 -> V_17 -> V_170 [ V_2 -> V_124 ] ;
F_9 ( L_13 ,
V_109 -> V_13 , V_109 -> V_67 , V_164 -> V_13 , V_164 -> V_67 ,
V_109 -> V_156 ) ;
V_168 = F_95 ( V_172 , 1 << ( F_96 ( V_164 -> V_13 ) - 3 ) ) ;
V_169 = F_95 ( V_172 , 1 << ( F_96 ( V_164 -> V_67 ) - 1 ) ) ;
V_166 = F_97 ( T_1 , V_171 -> V_173 , V_164 -> V_13 / V_168 ) ;
V_166 = F_98 ( V_166 , V_171 -> V_174 ) ;
V_167 = F_97 ( T_1 , 8 , V_164 -> V_67 / V_169 ) ;
V_167 = F_98 ( V_167 , 8 ) ;
F_99 ( & V_109 -> V_13 , V_166 , V_171 -> V_175 ,
F_96 ( V_171 -> V_174 ) - 1 ,
& V_109 -> V_67 , V_167 , V_171 -> V_176 , 0 , 0 ) ;
V_109 -> V_156 = V_109 -> V_13 * V_111 -> V_157 ;
V_109 -> V_116 = ( V_109 -> V_13 * V_109 -> V_67 * V_111 -> V_114 ) / 8 ;
V_109 -> V_113 = V_111 -> V_155 ;
V_109 -> V_160 = V_161 ;
V_109 -> V_158 = V_159 ;
F_9 ( L_14 ,
V_109 -> V_13 , V_109 -> V_67 , V_166 , V_167 , V_168 , V_169 ) ;
return 0 ;
}
static int F_100 ( struct V_123 * V_123 , void * V_76 ,
struct V_102 * V_5 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
return F_94 ( V_2 , & V_5 -> V_111 . V_109 , NULL ) ;
}
static int F_101 ( struct V_123 * V_123 , void * V_76 ,
struct V_102 * V_5 )
{
struct V_108 * V_109 = & V_5 -> V_111 . V_109 ;
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_4 * V_6 = & V_2 -> V_6 ;
const struct V_110 * V_111 = NULL ;
int V_58 ;
F_9 ( L_15 , V_2 -> V_124 ) ;
if ( F_102 ( & V_2 -> V_121 ) )
return - V_133 ;
V_58 = F_94 ( V_2 , & V_5 -> V_111 . V_109 , & V_111 ) ;
if ( V_58 < 0 )
return V_58 ;
V_2 -> V_20 = V_111 ;
V_2 -> V_118 = V_109 -> V_116 ;
V_6 -> V_11 = V_109 -> V_13 ;
V_6 -> V_115 = V_109 -> V_67 ;
V_6 -> V_9 . V_13 = V_109 -> V_13 ;
V_6 -> V_9 . V_67 = V_109 -> V_67 ;
V_6 -> V_9 . V_12 = 0 ;
V_6 -> V_9 . V_10 = 0 ;
if ( V_2 -> V_125 == NULL )
V_2 -> V_125 = V_76 ;
F_9 ( L_16 ,
V_6 -> V_11 , V_6 -> V_115 , V_2 -> V_118 , V_111 -> V_151 ,
V_109 -> V_13 * V_109 -> V_67 * V_111 -> V_114 , V_111 -> V_114 ,
V_109 -> V_116 , V_109 -> V_156 ) ;
return 0 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_177 V_178 ;
struct V_179 * V_180 ;
int V_58 ;
V_180 = F_104 ( & V_15 -> V_181 [ 0 ] ) ;
if ( ! V_180 || F_105 ( V_180 -> V_182 ) != V_183 )
return - V_184 ;
V_178 . V_180 = V_180 -> V_79 ;
V_178 . V_185 = V_186 ;
V_58 = F_20 ( V_15 -> V_18 . V_19 , V_180 , V_187 , NULL , & V_178 ) ;
if ( V_58 < 0 && V_58 != - V_188 )
return - V_184 ;
if ( V_178 . V_189 . V_13 != V_15 -> V_190 . V_13 ||
V_178 . V_189 . V_67 != V_15 -> V_190 . V_67 ||
V_178 . V_189 . V_191 != V_15 -> V_190 . V_191 )
return - V_184 ;
return 0 ;
}
static int F_106 ( struct V_123 * V_123 , void * V_76 ,
enum V_192 type )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_193 * V_18 = & V_15 -> V_18 . V_19 -> V_182 ;
int V_58 ;
F_9 ( L_15 , V_2 -> V_124 ) ;
if ( type != V_194 )
return - V_21 ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
if ( F_29 ( V_2 ) )
return 0 ;
V_58 = F_107 ( V_18 , V_15 -> V_195 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_103 ( V_15 ) ;
if ( V_58 < 0 ) {
F_108 ( V_18 ) ;
return V_58 ;
}
return F_109 ( & V_2 -> V_121 , type ) ;
}
static int F_110 ( struct V_123 * V_123 , void * V_76 ,
enum V_192 type )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_58 ;
F_9 ( L_15 , V_2 -> V_124 ) ;
if ( type != V_194 )
return - V_21 ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
V_58 = F_111 ( & V_2 -> V_121 , type ) ;
if ( V_58 == 0 )
F_108 ( & V_15 -> V_18 . V_19 -> V_182 ) ;
return V_58 ;
}
static int F_112 ( struct V_123 * V_123 , void * V_76 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
int V_58 ;
F_9 ( L_17 ,
V_2 -> V_124 , V_197 -> V_97 , V_2 -> V_125 , V_76 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
if ( V_197 -> V_97 )
V_197 -> V_97 = F_97 ( T_1 , V_198 , V_197 -> V_97 ) ;
else
V_2 -> V_125 = NULL ;
V_58 = F_113 ( & V_2 -> V_121 , V_197 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_197 -> V_97 && V_197 -> V_97 < V_198 ) {
V_197 -> V_97 = 0 ;
F_113 ( & V_2 -> V_121 , V_197 ) ;
V_58 = - V_199 ;
}
V_2 -> V_200 = V_197 -> V_97 ;
if ( V_2 -> V_125 == NULL && V_197 -> V_97 > 0 )
V_2 -> V_125 = V_76 ;
return V_58 ;
}
static int F_114 ( struct V_123 * V_123 , void * V_76 ,
struct V_201 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
return F_115 ( & V_2 -> V_121 , V_43 ) ;
}
static int F_116 ( struct V_123 * V_123 , void * V_76 ,
struct V_201 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
F_9 ( L_15 , V_2 -> V_124 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
return F_117 ( & V_2 -> V_121 , V_43 ) ;
}
static int F_118 ( struct V_123 * V_123 , void * V_76 ,
struct V_201 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
F_9 ( L_18 , V_2 -> V_124 , V_2 -> V_92 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
return F_119 ( & V_2 -> V_121 , V_43 , V_123 -> V_202 & V_203 ) ;
}
static int F_120 ( struct V_123 * V_123 , void * V_76 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
int V_58 ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
V_205 -> V_97 = F_97 ( T_1 , 1 , V_205 -> V_97 ) ;
V_58 = F_121 ( & V_2 -> V_121 , V_205 ) ;
if ( ! V_58 && V_2 -> V_125 == NULL )
V_2 -> V_125 = V_76 ;
return V_58 ;
}
static int F_122 ( struct V_123 * V_123 , void * V_76 ,
struct V_201 * V_206 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
return F_123 ( & V_2 -> V_121 , V_206 ) ;
}
static int F_124 ( struct V_123 * V_123 , void * V_76 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
if ( V_208 -> type != V_194 )
return - V_21 ;
switch ( V_208 -> V_209 ) {
case V_210 :
case V_211 :
V_208 -> V_212 . V_12 = 0 ;
V_208 -> V_212 . V_10 = 0 ;
V_208 -> V_212 . V_13 = V_2 -> V_6 . V_11 ;
V_208 -> V_212 . V_67 = V_2 -> V_6 . V_115 ;
return 0 ;
case V_213 :
V_208 -> V_212 = V_2 -> V_6 . V_9 ;
return 0 ;
}
return - V_21 ;
}
static void F_125 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_163 * V_212 )
{
if ( V_15 -> V_17 -> V_22 == V_23 ) {
* V_212 = V_2 -> V_6 . V_9 ;
return;
}
}
static int F_126 ( struct V_123 * V_123 , void * V_76 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_163 V_9 = V_208 -> V_212 ;
unsigned long V_44 ;
if ( V_208 -> type != V_194 ||
V_208 -> V_209 != V_213 )
return - V_21 ;
F_125 ( V_15 , V_2 , & V_9 ) ;
V_208 -> V_212 = V_9 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_6 . V_9 = V_9 ;
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
F_9 ( L_19 ,
V_208 -> type , V_208 -> V_209 , V_208 -> V_44 ,
V_208 -> V_212 . V_12 , V_208 -> V_212 . V_10 , V_208 -> V_212 . V_13 , V_208 -> V_212 . V_67 ) ;
return 0 ;
}
static int F_127 ( struct V_214 * V_215 )
{
struct V_1 * V_2 = V_215 -> V_76 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_9 ( L_20 , V_2 -> V_124 ,
V_215 -> V_151 , V_215 -> V_216 ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_215 -> V_124 ) {
case V_217 :
V_2 -> V_218 = V_215 -> V_216 ;
break;
case V_219 :
V_2 -> V_220 = V_215 -> V_216 ;
break;
}
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_128 ( struct V_14 * V_15 , int V_221 )
{
struct V_1 * V_2 = & V_15 -> V_2 [ V_221 ] ;
struct V_95 * V_222 = & V_2 -> V_121 ;
struct V_223 * V_224 = & V_2 -> V_99 ;
struct V_214 * V_215 ;
int V_58 ;
memset ( V_224 , 0 , sizeof( * V_224 ) ) ;
snprintf ( V_224 -> V_151 , sizeof( V_224 -> V_151 ) , L_21 ,
V_2 -> V_124 == 0 ? L_22 : L_23 ) ;
V_224 -> V_225 = & V_226 ;
V_224 -> V_227 = & V_228 ;
V_224 -> V_229 = & V_15 -> V_229 ;
V_224 -> V_230 = - 1 ;
V_224 -> V_231 = V_232 ;
V_224 -> V_122 = & V_15 -> V_122 ;
V_2 -> V_200 = 0 ;
F_129 ( & V_2 -> V_54 ) ;
F_129 ( & V_2 -> V_57 ) ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> type = V_194 ;
V_222 -> V_233 = V_234 | V_235 ;
V_222 -> V_236 = & V_237 ;
V_222 -> V_238 = & V_239 ;
V_222 -> V_240 = sizeof( struct V_42 ) ;
V_222 -> V_241 = V_2 ;
V_222 -> V_242 = V_243 ;
V_58 = F_130 ( V_222 ) ;
if ( V_58 )
goto V_244;
V_2 -> V_180 . V_44 = V_245 ;
V_58 = F_131 ( & V_224 -> V_182 , 1 , & V_2 -> V_180 , 0 ) ;
if ( V_58 )
goto V_244;
F_132 ( V_224 , V_2 ) ;
F_133 ( V_246 , & V_224 -> V_44 ) ;
F_134 ( & V_2 -> V_247 , 1 ) ;
V_215 = F_135 ( & V_2 -> V_247 , & V_248 ,
V_217 , 0 , 1 , 1 , 0 ) ;
if ( V_215 )
V_215 -> V_76 = V_2 ;
V_215 = F_135 ( & V_2 -> V_247 , & V_248 ,
V_219 , 0 , 1 , 1 , 0 ) ;
if ( V_215 )
V_215 -> V_76 = V_2 ;
V_58 = V_2 -> V_247 . error ;
if ( V_58 < 0 )
goto V_249;
V_224 -> V_247 = & V_2 -> V_247 ;
V_58 = F_136 ( V_224 , V_250 , - 1 ) ;
if ( V_58 )
goto V_251;
F_137 ( & V_15 -> V_229 , L_24 ,
V_224 -> V_151 , F_138 ( V_224 ) ) ;
return 0 ;
V_251:
F_139 ( & V_2 -> V_247 ) ;
V_249:
F_140 ( & V_224 -> V_182 ) ;
V_244:
F_141 ( V_224 ) ;
return V_58 ;
}
void F_142 ( struct V_14 * V_15 , int V_221 )
{
struct V_223 * V_224 = & V_15 -> V_2 [ V_221 ] . V_99 ;
if ( F_143 ( V_224 ) ) {
F_144 ( V_224 ) ;
F_140 ( & V_224 -> V_182 ) ;
F_139 ( V_224 -> V_247 ) ;
}
}
static int F_145 ( struct V_149 * V_19 ,
struct V_252 * V_253 ,
struct V_254 * V_191 )
{
if ( V_191 -> V_79 >= F_146 ( V_255 ) )
return - V_21 ;
V_191 -> V_191 = V_255 [ V_191 -> V_79 ] ;
return 0 ;
}
static int F_147 ( struct V_149 * V_19 ,
struct V_252 * V_253 ,
struct V_177 * V_111 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_256 * V_257 = & V_111 -> V_189 ;
if ( V_111 -> V_185 == V_258 ) {
V_257 = F_149 ( V_253 , V_111 -> V_180 ) ;
V_111 -> V_189 = * V_257 ;
return 0 ;
}
F_69 ( & V_15 -> V_122 ) ;
switch ( V_111 -> V_180 ) {
case V_259 :
* V_257 = V_15 -> V_190 ;
break;
case V_260 ... V_261 :
V_257 -> V_13 = V_15 -> V_165 . V_13 ;
V_257 -> V_67 = V_15 -> V_165 . V_67 ;
V_257 -> V_191 = V_15 -> V_190 . V_191 ;
break;
}
F_71 ( & V_15 -> V_122 ) ;
V_257 -> V_160 = V_161 ;
return 0 ;
}
static void F_150 ( struct V_14 * V_15 ,
struct V_256 * V_257 , int V_180 )
{
const struct V_16 * V_17 = V_15 -> V_17 ;
const struct V_170 * V_171 ;
int V_152 = F_146 ( V_255 ) ;
V_171 = & V_17 -> V_170 [ V_262 ] ;
while ( V_152 -- >= 0 )
if ( V_255 [ V_152 ] == V_257 -> V_191 )
break;
V_257 -> V_191 = V_255 [ V_152 ] ;
if ( V_180 == V_259 ) {
F_99 ( & V_257 -> V_13 , 8 , V_263 ,
F_96 ( V_171 -> V_174 ) - 1 ,
& V_257 -> V_67 , 8 , V_264 , 0 ,
0 ) ;
} else {
struct V_163 * V_164 = & V_15 -> V_165 ;
F_99 ( & V_257 -> V_13 , 8 , V_164 -> V_13 ,
F_96 ( V_171 -> V_174 ) - 1 ,
& V_257 -> V_67 , 8 , V_164 -> V_67 ,
0 , 0 ) ;
}
F_151 ( 1 , V_100 , & V_15 -> V_265 , L_25 , V_257 -> V_13 , V_257 -> V_67 ) ;
}
static int F_152 ( struct V_149 * V_19 ,
struct V_252 * V_253 ,
struct V_177 * V_111 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_256 * V_257 = & V_111 -> V_189 ;
struct V_163 * V_164 = & V_15 -> V_165 ;
int V_152 ;
F_151 ( 1 , V_100 , V_19 , L_26 ,
V_111 -> V_180 , V_257 -> V_191 , V_257 -> V_13 , V_257 -> V_67 ) ;
V_257 -> V_160 = V_161 ;
F_69 ( & V_15 -> V_122 ) ;
if ( F_102 ( & V_15 -> V_2 [ V_262 ] . V_121 ) ||
F_102 ( & V_15 -> V_2 [ V_266 ] . V_121 ) ) {
F_71 ( & V_15 -> V_122 ) ;
return - V_133 ;
}
F_150 ( V_15 , V_257 , V_111 -> V_180 ) ;
if ( V_111 -> V_185 == V_258 ) {
V_257 = F_149 ( V_253 , V_111 -> V_180 ) ;
* V_257 = V_111 -> V_189 ;
F_71 ( & V_15 -> V_122 ) ;
return 0 ;
}
switch ( V_111 -> V_180 ) {
case V_259 :
V_15 -> V_190 = * V_257 ;
V_164 -> V_13 = V_257 -> V_13 ;
V_164 -> V_67 = V_257 -> V_67 ;
V_164 -> V_12 = 0 ;
V_164 -> V_10 = 0 ;
for ( V_152 = 0 ; V_152 < V_267 ; V_152 ++ ) {
struct V_4 * V_65 = & V_15 -> V_2 [ V_152 ] . V_6 ;
V_65 -> V_9 = * V_164 ;
V_65 -> V_11 = V_257 -> V_13 ;
V_65 -> V_115 = V_257 -> V_67 ;
}
break;
case V_260 ... V_261 :
V_257 -> V_191 = V_15 -> V_190 . V_191 ;
V_257 -> V_13 = V_164 -> V_13 ;
V_257 -> V_67 = V_164 -> V_67 ;
break;
}
F_71 ( & V_15 -> V_122 ) ;
return 0 ;
}
static int F_153 ( struct V_149 * V_19 ,
struct V_252 * V_253 ,
struct V_268 * V_208 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_163 * V_164 = & V_15 -> V_165 ;
struct V_256 * V_257 = & V_15 -> V_190 ;
if ( ( V_208 -> V_209 != V_269 &&
V_208 -> V_209 != V_270 ) ||
V_208 -> V_180 != V_259 )
return - V_21 ;
if ( V_208 -> V_185 == V_258 ) {
V_208 -> V_212 = * F_154 ( V_253 , V_208 -> V_180 ) ;
return 0 ;
}
F_69 ( & V_15 -> V_122 ) ;
if ( V_208 -> V_209 == V_269 ) {
V_208 -> V_212 = * V_164 ;
} else {
V_208 -> V_212 . V_13 = V_257 -> V_13 ;
V_208 -> V_212 . V_67 = V_257 -> V_67 ;
V_208 -> V_212 . V_12 = 0 ;
V_208 -> V_212 . V_10 = 0 ;
}
F_71 ( & V_15 -> V_122 ) ;
F_151 ( 1 , V_100 , V_19 , L_27 ,
V_101 , V_164 -> V_12 , V_164 -> V_10 , V_164 -> V_13 ,
V_164 -> V_67 , V_257 -> V_13 , V_257 -> V_67 ) ;
return 0 ;
}
static void F_155 ( struct V_14 * V_15 , struct V_163 * V_212 )
{
struct V_256 * V_257 = & V_15 -> V_190 ;
const struct V_271 * V_171 = & V_15 -> V_17 -> V_272 ;
unsigned int V_12 = 2 * V_212 -> V_12 ;
unsigned int V_10 = 2 * V_212 -> V_10 ;
F_99 ( & V_212 -> V_13 , 0 , V_257 -> V_13 ,
F_96 ( V_171 -> V_273 ) - 1 ,
& V_212 -> V_67 , 0 , V_257 -> V_67 , 1 , 0 ) ;
F_99 ( & V_12 , 0 , V_257 -> V_13 - V_212 -> V_13 ,
F_96 ( V_171 -> V_273 ) ,
& V_10 , 0 , V_257 -> V_67 - V_212 -> V_67 , 2 , 0 ) ;
V_212 -> V_12 = V_12 / 2 ;
V_212 -> V_10 = V_10 / 2 ;
V_212 -> V_13 = V_257 -> V_13 - V_12 ;
V_212 -> V_67 = V_257 -> V_67 - V_10 ;
if ( V_15 -> V_17 -> V_22 == V_23 &&
F_30 ( V_15 ) ) {
unsigned int V_152 ;
for ( V_152 = 0 ; V_152 < V_267 ; V_152 ++ ) {
struct V_163 * V_274 = & V_15 -> V_2 [ V_152 ] . V_6 . V_9 ;
if ( ( V_274 -> V_13 > V_212 -> V_13 ) == ( V_274 -> V_67 > V_212 -> V_67 ) )
continue;
* V_212 = V_15 -> V_165 ;
F_9 ( L_28 ) ;
break;
}
}
F_151 ( 1 , V_100 , & V_15 -> V_229 , L_29 ,
V_212 -> V_12 , V_212 -> V_10 , V_212 -> V_13 , V_212 -> V_67 , V_257 -> V_13 , V_257 -> V_67 ) ;
}
static int F_156 ( struct V_149 * V_19 ,
struct V_252 * V_253 ,
struct V_268 * V_208 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_163 * V_164 = & V_15 -> V_165 ;
struct V_275 V_3 ;
if ( V_208 -> V_209 != V_269 || V_208 -> V_180 != V_259 )
return - V_21 ;
F_69 ( & V_15 -> V_122 ) ;
F_155 ( V_15 , & V_208 -> V_212 ) ;
if ( V_208 -> V_185 == V_258 ) {
* F_154 ( V_253 , V_208 -> V_180 ) = V_208 -> V_212 ;
} else {
unsigned long V_44 ;
unsigned int V_152 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
* V_164 = V_208 -> V_212 ;
for ( V_152 = 0 ; V_152 < V_267 ; V_152 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_152 ] ;
V_3 = V_2 -> V_3 ;
if ( F_3 ( V_2 , & V_3 ) )
continue;
V_2 -> V_3 = V_3 ;
V_2 -> V_30 |= V_31 ;
}
F_28 ( & V_15 -> V_46 , V_44 ) ;
}
F_71 ( & V_15 -> V_122 ) ;
F_151 ( 1 , V_100 , V_19 , L_30 ,
V_101 , V_164 -> V_12 , V_164 -> V_10 , V_164 -> V_13 , V_164 -> V_67 ,
V_15 -> V_190 . V_13 , V_15 -> V_190 . V_67 ) ;
return 0 ;
}
static int F_157 ( struct V_214 * V_215 )
{
struct V_14 * V_15 = F_65 ( V_215 -> V_276 , struct V_14 ,
V_247 ) ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_215 -> V_124 ) {
case V_277 :
V_15 -> V_26 = V_15 -> V_278 -> V_216 ;
switch ( V_215 -> V_216 ) {
case V_279 :
V_15 -> V_27 = 115 ;
V_15 -> V_28 = 145 ;
break;
case V_280 :
V_15 -> V_27 = V_15 -> V_281 -> V_216 >> 8 ;
V_15 -> V_28 = V_15 -> V_281 -> V_216 & 0xff ;
break;
default:
V_15 -> V_27 = 128 ;
V_15 -> V_28 = 128 ;
}
break;
case V_282 :
V_15 -> V_24 = V_15 -> V_283 -> V_216 ;
break;
default:
F_2 ( 1 ) ;
}
V_15 -> V_2 [ V_262 ] . V_30 |= V_31 ;
V_15 -> V_2 [ V_266 ] . V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_158 ( struct V_14 * V_15 )
{
struct V_284 * V_276 = & V_15 -> V_247 ;
struct V_149 * V_19 = & V_15 -> V_265 ;
int V_58 ;
F_159 ( V_19 , & V_285 ) ;
V_19 -> V_44 |= V_286 ;
F_87 ( V_19 -> V_151 , L_31 , sizeof( V_19 -> V_151 ) ) ;
V_15 -> V_181 [ V_259 ] . V_44 = V_245 ;
V_15 -> V_181 [ V_260 ] . V_44 = V_287 ;
V_15 -> V_181 [ V_261 ] . V_44 = V_287 ;
V_58 = F_131 ( & V_19 -> V_182 , V_288 ,
V_15 -> V_181 , 0 ) ;
if ( V_58 )
return V_58 ;
F_134 ( V_276 , 3 ) ;
V_15 -> V_283 = F_160 ( V_276 ,
& V_289 , V_282 ,
F_146 ( V_290 ) - 1 , 0 , 0 ,
V_290 ) ;
if ( V_15 -> V_17 -> V_25 ) {
V_15 -> V_278 = F_161 ( V_276 ,
& V_289 ,
V_277 , V_280 ,
~ 0x981f , V_291 ) ;
V_15 -> V_281 = F_135 ( V_276 ,
& V_289 ,
V_292 , 0 , 0xffff , 1 , 0 ) ;
}
if ( V_276 -> error ) {
F_139 ( V_276 ) ;
F_140 ( & V_19 -> V_182 ) ;
return V_276 -> error ;
}
if ( V_15 -> V_17 -> V_25 )
F_162 ( 2 , & V_15 -> V_278 ,
V_280 , false ) ;
V_19 -> V_247 = V_276 ;
F_163 ( V_19 , V_15 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_15 )
{
struct V_149 * V_19 = & V_15 -> V_265 ;
if ( F_148 ( V_19 ) == NULL )
return;
F_165 ( V_19 ) ;
F_140 ( & V_19 -> V_182 ) ;
F_139 ( & V_15 -> V_247 ) ;
F_163 ( V_19 , NULL ) ;
}
int F_166 ( struct V_14 * V_15 )
{
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < V_267 ; V_152 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_152 ] ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_124 = V_152 ;
V_2 -> V_293 = V_15 -> V_17 -> V_294 ;
if ( V_32 == V_23 )
V_2 -> V_295 = V_152 ? V_296 :
V_297 ;
else
V_2 -> V_295 = V_298 ;
V_2 -> V_20 = F_59 ( V_2 , NULL , 0 ) ;
F_167 ( V_2 -> V_20 == NULL ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_11 = V_299 ;
V_5 -> V_115 = V_300 ;
V_5 -> V_9 . V_13 = V_299 ;
V_5 -> V_9 . V_67 = V_300 ;
V_2 -> V_3 . V_98 = 1 ;
V_2 -> V_118 = ( V_5 -> V_11 * V_5 -> V_115 *
V_2 -> V_20 -> V_114 ) / 8 ;
}
memset ( & V_15 -> V_190 , 0 , sizeof( V_15 -> V_190 ) ) ;
V_15 -> V_190 . V_13 = V_299 ;
V_15 -> V_190 . V_67 = V_300 ;
V_15 -> V_190 . V_191 = V_255 [ 0 ] ;
memset ( & V_15 -> V_165 , 0 , sizeof( V_15 -> V_165 ) ) ;
V_15 -> V_165 . V_13 = V_299 ;
V_15 -> V_165 . V_67 = V_300 ;
return 0 ;
}
