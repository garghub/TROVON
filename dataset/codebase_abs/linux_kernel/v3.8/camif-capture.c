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
static int F_57 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_52 ( V_96 ) ;
return F_31 ( V_2 ) ;
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
if ( ! V_58 ) {
V_2 -> V_199 = V_197 -> V_97 ;
if ( V_2 -> V_125 == NULL && V_197 -> V_97 > 0 )
V_2 -> V_125 = V_76 ;
}
return V_58 ;
}
static int F_114 ( struct V_123 * V_123 , void * V_76 ,
struct V_200 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
return F_115 ( & V_2 -> V_121 , V_43 ) ;
}
static int F_116 ( struct V_123 * V_123 , void * V_76 ,
struct V_200 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
F_9 ( L_15 , V_2 -> V_124 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
return F_117 ( & V_2 -> V_121 , V_43 ) ;
}
static int F_118 ( struct V_123 * V_123 , void * V_76 ,
struct V_200 * V_43 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
F_9 ( L_18 , V_2 -> V_124 , V_2 -> V_92 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
return F_119 ( & V_2 -> V_121 , V_43 , V_123 -> V_201 & V_202 ) ;
}
static int F_120 ( struct V_123 * V_123 , void * V_76 ,
struct V_203 * V_204 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
int V_58 ;
if ( V_2 -> V_125 && V_2 -> V_125 != V_76 )
return - V_133 ;
V_204 -> V_97 = F_97 ( T_1 , 1 , V_204 -> V_97 ) ;
V_58 = F_121 ( & V_2 -> V_121 , V_204 ) ;
if ( ! V_58 && V_2 -> V_125 == NULL )
V_2 -> V_125 = V_76 ;
return V_58 ;
}
static int F_122 ( struct V_123 * V_123 , void * V_76 ,
struct V_200 * V_205 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
return F_123 ( & V_2 -> V_121 , V_205 ) ;
}
static int F_124 ( struct V_123 * V_123 , void * V_76 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
if ( V_207 -> type != V_194 )
return - V_21 ;
switch ( V_207 -> V_208 ) {
case V_209 :
case V_210 :
V_207 -> V_211 . V_12 = 0 ;
V_207 -> V_211 . V_10 = 0 ;
V_207 -> V_211 . V_13 = V_2 -> V_6 . V_11 ;
V_207 -> V_211 . V_67 = V_2 -> V_6 . V_115 ;
return 0 ;
case V_212 :
V_207 -> V_211 = V_2 -> V_6 . V_9 ;
return 0 ;
}
return - V_21 ;
}
static void F_125 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_163 * V_211 )
{
if ( V_15 -> V_17 -> V_22 == V_23 ) {
* V_211 = V_2 -> V_6 . V_9 ;
return;
}
}
static int F_126 ( struct V_123 * V_123 , void * V_76 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_73 ( V_123 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_163 V_9 = V_207 -> V_211 ;
unsigned long V_44 ;
if ( V_207 -> type != V_194 ||
V_207 -> V_208 != V_212 )
return - V_21 ;
F_125 ( V_15 , V_2 , & V_9 ) ;
V_207 -> V_211 = V_9 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
V_2 -> V_6 . V_9 = V_9 ;
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
F_9 ( L_19 ,
V_207 -> type , V_207 -> V_208 , V_207 -> V_44 ,
V_207 -> V_211 . V_12 , V_207 -> V_211 . V_10 , V_207 -> V_211 . V_13 , V_207 -> V_211 . V_67 ) ;
return 0 ;
}
static int F_127 ( struct V_213 * V_214 )
{
struct V_1 * V_2 = V_214 -> V_76 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_44 ;
F_9 ( L_20 , V_2 -> V_124 ,
V_214 -> V_151 , V_214 -> V_215 ) ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_214 -> V_124 ) {
case V_216 :
V_2 -> V_217 = V_214 -> V_215 ;
break;
case V_218 :
V_2 -> V_219 = V_214 -> V_215 ;
break;
}
V_2 -> V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_128 ( struct V_14 * V_15 , int V_220 )
{
struct V_1 * V_2 = & V_15 -> V_2 [ V_220 ] ;
struct V_95 * V_221 = & V_2 -> V_121 ;
struct V_222 * V_223 = & V_2 -> V_99 ;
struct V_213 * V_214 ;
int V_58 ;
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
snprintf ( V_223 -> V_151 , sizeof( V_223 -> V_151 ) , L_21 ,
V_2 -> V_124 == 0 ? L_22 : L_23 ) ;
V_223 -> V_224 = & V_225 ;
V_223 -> V_226 = & V_227 ;
V_223 -> V_228 = & V_15 -> V_228 ;
V_223 -> V_229 = - 1 ;
V_223 -> V_230 = V_231 ;
V_223 -> V_122 = & V_15 -> V_122 ;
V_2 -> V_199 = 0 ;
F_129 ( & V_2 -> V_54 ) ;
F_129 ( & V_2 -> V_57 ) ;
memset ( V_221 , 0 , sizeof( * V_221 ) ) ;
V_221 -> type = V_194 ;
V_221 -> V_232 = V_233 | V_234 ;
V_221 -> V_235 = & V_236 ;
V_221 -> V_237 = & V_238 ;
V_221 -> V_239 = sizeof( struct V_42 ) ;
V_221 -> V_240 = V_2 ;
V_58 = F_130 ( V_221 ) ;
if ( V_58 )
goto V_241;
V_2 -> V_180 . V_44 = V_242 ;
V_58 = F_131 ( & V_223 -> V_182 , 1 , & V_2 -> V_180 , 0 ) ;
if ( V_58 )
goto V_241;
F_132 ( V_223 , V_2 ) ;
F_133 ( V_243 , & V_223 -> V_44 ) ;
F_134 ( & V_2 -> V_244 , 1 ) ;
V_214 = F_135 ( & V_2 -> V_244 , & V_245 ,
V_216 , 0 , 1 , 1 , 0 ) ;
if ( V_214 )
V_214 -> V_76 = V_2 ;
V_214 = F_135 ( & V_2 -> V_244 , & V_245 ,
V_218 , 0 , 1 , 1 , 0 ) ;
if ( V_214 )
V_214 -> V_76 = V_2 ;
V_58 = V_2 -> V_244 . error ;
if ( V_58 < 0 )
goto V_246;
V_223 -> V_244 = & V_2 -> V_244 ;
V_58 = F_136 ( V_223 , V_247 , - 1 ) ;
if ( V_58 )
goto V_248;
F_137 ( & V_15 -> V_228 , L_24 ,
V_223 -> V_151 , F_138 ( V_223 ) ) ;
return 0 ;
V_248:
F_139 ( & V_2 -> V_244 ) ;
V_246:
F_140 ( & V_223 -> V_182 ) ;
V_241:
F_141 ( V_223 ) ;
return V_58 ;
}
void F_142 ( struct V_14 * V_15 , int V_220 )
{
struct V_222 * V_223 = & V_15 -> V_2 [ V_220 ] . V_99 ;
if ( F_143 ( V_223 ) ) {
F_144 ( V_223 ) ;
F_140 ( & V_223 -> V_182 ) ;
F_139 ( V_223 -> V_244 ) ;
}
}
static int F_145 ( struct V_149 * V_19 ,
struct V_249 * V_250 ,
struct V_251 * V_191 )
{
if ( V_191 -> V_79 >= F_146 ( V_252 ) )
return - V_21 ;
V_191 -> V_191 = V_252 [ V_191 -> V_79 ] ;
return 0 ;
}
static int F_147 ( struct V_149 * V_19 ,
struct V_249 * V_250 ,
struct V_177 * V_111 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_253 * V_254 = & V_111 -> V_189 ;
if ( V_111 -> V_185 == V_255 ) {
V_254 = F_149 ( V_250 , V_111 -> V_180 ) ;
V_111 -> V_189 = * V_254 ;
return 0 ;
}
F_69 ( & V_15 -> V_122 ) ;
switch ( V_111 -> V_180 ) {
case V_256 :
* V_254 = V_15 -> V_190 ;
break;
case V_257 ... V_258 :
V_254 -> V_13 = V_15 -> V_165 . V_13 ;
V_254 -> V_67 = V_15 -> V_165 . V_67 ;
V_254 -> V_191 = V_15 -> V_190 . V_191 ;
break;
}
F_71 ( & V_15 -> V_122 ) ;
V_254 -> V_160 = V_161 ;
return 0 ;
}
static void F_150 ( struct V_14 * V_15 ,
struct V_253 * V_254 , int V_180 )
{
const struct V_16 * V_17 = V_15 -> V_17 ;
const struct V_170 * V_171 ;
int V_152 = F_146 ( V_252 ) ;
V_171 = & V_17 -> V_170 [ V_259 ] ;
while ( V_152 -- >= 0 )
if ( V_252 [ V_152 ] == V_254 -> V_191 )
break;
V_254 -> V_191 = V_252 [ V_152 ] ;
if ( V_180 == V_256 ) {
F_99 ( & V_254 -> V_13 , 8 , V_260 ,
F_96 ( V_171 -> V_174 ) - 1 ,
& V_254 -> V_67 , 8 , V_261 , 0 ,
0 ) ;
} else {
struct V_163 * V_164 = & V_15 -> V_165 ;
F_99 ( & V_254 -> V_13 , 8 , V_164 -> V_13 ,
F_96 ( V_171 -> V_174 ) - 1 ,
& V_254 -> V_67 , 8 , V_164 -> V_67 ,
0 , 0 ) ;
}
F_151 ( 1 , V_100 , & V_15 -> V_262 , L_25 , V_254 -> V_13 , V_254 -> V_67 ) ;
}
static int F_152 ( struct V_149 * V_19 ,
struct V_249 * V_250 ,
struct V_177 * V_111 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_253 * V_254 = & V_111 -> V_189 ;
struct V_163 * V_164 = & V_15 -> V_165 ;
int V_152 ;
F_151 ( 1 , V_100 , V_19 , L_26 ,
V_111 -> V_180 , V_254 -> V_191 , V_254 -> V_13 , V_254 -> V_67 ) ;
V_254 -> V_160 = V_161 ;
F_69 ( & V_15 -> V_122 ) ;
if ( F_102 ( & V_15 -> V_2 [ V_259 ] . V_121 ) ||
F_102 ( & V_15 -> V_2 [ V_263 ] . V_121 ) ) {
F_71 ( & V_15 -> V_122 ) ;
return - V_133 ;
}
F_150 ( V_15 , V_254 , V_111 -> V_180 ) ;
if ( V_111 -> V_185 == V_255 ) {
V_254 = F_149 ( V_250 , V_111 -> V_180 ) ;
* V_254 = V_111 -> V_189 ;
F_71 ( & V_15 -> V_122 ) ;
return 0 ;
}
switch ( V_111 -> V_180 ) {
case V_256 :
V_15 -> V_190 = * V_254 ;
V_164 -> V_13 = V_254 -> V_13 ;
V_164 -> V_67 = V_254 -> V_67 ;
V_164 -> V_12 = 0 ;
V_164 -> V_10 = 0 ;
for ( V_152 = 0 ; V_152 < V_264 ; V_152 ++ ) {
struct V_4 * V_65 = & V_15 -> V_2 [ V_152 ] . V_6 ;
V_65 -> V_9 = * V_164 ;
V_65 -> V_11 = V_254 -> V_13 ;
V_65 -> V_115 = V_254 -> V_67 ;
}
break;
case V_257 ... V_258 :
V_254 -> V_191 = V_15 -> V_190 . V_191 ;
V_254 -> V_13 = V_164 -> V_13 ;
V_254 -> V_67 = V_164 -> V_67 ;
break;
}
F_71 ( & V_15 -> V_122 ) ;
return 0 ;
}
static int F_153 ( struct V_149 * V_19 ,
struct V_249 * V_250 ,
struct V_265 * V_207 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_163 * V_164 = & V_15 -> V_165 ;
struct V_253 * V_254 = & V_15 -> V_190 ;
if ( ( V_207 -> V_208 != V_266 &&
V_207 -> V_208 != V_267 ) ||
V_207 -> V_180 != V_256 )
return - V_21 ;
if ( V_207 -> V_185 == V_255 ) {
V_207 -> V_211 = * F_154 ( V_250 , V_207 -> V_180 ) ;
return 0 ;
}
F_69 ( & V_15 -> V_122 ) ;
if ( V_207 -> V_208 == V_266 ) {
V_207 -> V_211 = * V_164 ;
} else {
V_207 -> V_211 . V_13 = V_254 -> V_13 ;
V_207 -> V_211 . V_67 = V_254 -> V_67 ;
V_207 -> V_211 . V_12 = 0 ;
V_207 -> V_211 . V_10 = 0 ;
}
F_71 ( & V_15 -> V_122 ) ;
F_151 ( 1 , V_100 , V_19 , L_27 ,
V_101 , V_164 -> V_12 , V_164 -> V_10 , V_164 -> V_13 ,
V_164 -> V_67 , V_254 -> V_13 , V_254 -> V_67 ) ;
return 0 ;
}
static void F_155 ( struct V_14 * V_15 , struct V_163 * V_211 )
{
struct V_253 * V_254 = & V_15 -> V_190 ;
const struct V_268 * V_171 = & V_15 -> V_17 -> V_269 ;
unsigned int V_12 = 2 * V_211 -> V_12 ;
unsigned int V_10 = 2 * V_211 -> V_10 ;
F_99 ( & V_211 -> V_13 , 0 , V_254 -> V_13 ,
F_96 ( V_171 -> V_270 ) - 1 ,
& V_211 -> V_67 , 0 , V_254 -> V_67 , 1 , 0 ) ;
F_99 ( & V_12 , 0 , V_254 -> V_13 - V_211 -> V_13 ,
F_96 ( V_171 -> V_270 ) ,
& V_10 , 0 , V_254 -> V_67 - V_211 -> V_67 , 2 , 0 ) ;
V_211 -> V_12 = V_12 / 2 ;
V_211 -> V_10 = V_10 / 2 ;
V_211 -> V_13 = V_254 -> V_13 - V_12 ;
V_211 -> V_67 = V_254 -> V_67 - V_10 ;
if ( V_15 -> V_17 -> V_22 == V_23 &&
F_30 ( V_15 ) ) {
unsigned int V_152 ;
for ( V_152 = 0 ; V_152 < V_264 ; V_152 ++ ) {
struct V_163 * V_271 = & V_15 -> V_2 [ V_152 ] . V_6 . V_9 ;
if ( ( V_271 -> V_13 > V_211 -> V_13 ) == ( V_271 -> V_67 > V_211 -> V_67 ) )
continue;
* V_211 = V_15 -> V_165 ;
F_9 ( L_28 ) ;
break;
}
}
F_151 ( 1 , V_100 , & V_15 -> V_228 , L_29 ,
V_211 -> V_12 , V_211 -> V_10 , V_211 -> V_13 , V_211 -> V_67 , V_254 -> V_13 , V_254 -> V_67 ) ;
}
static int F_156 ( struct V_149 * V_19 ,
struct V_249 * V_250 ,
struct V_265 * V_207 )
{
struct V_14 * V_15 = F_148 ( V_19 ) ;
struct V_163 * V_164 = & V_15 -> V_165 ;
struct V_272 V_3 ;
if ( V_207 -> V_208 != V_266 || V_207 -> V_180 != V_256 )
return - V_21 ;
F_69 ( & V_15 -> V_122 ) ;
F_155 ( V_15 , & V_207 -> V_211 ) ;
if ( V_207 -> V_185 == V_255 ) {
* F_154 ( V_250 , V_207 -> V_180 ) = V_207 -> V_211 ;
} else {
unsigned long V_44 ;
unsigned int V_152 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
* V_164 = V_207 -> V_211 ;
for ( V_152 = 0 ; V_152 < V_264 ; V_152 ++ ) {
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
static int F_157 ( struct V_213 * V_214 )
{
struct V_14 * V_15 = F_65 ( V_214 -> V_273 , struct V_14 ,
V_244 ) ;
unsigned long V_44 ;
F_23 ( & V_15 -> V_46 , V_44 ) ;
switch ( V_214 -> V_124 ) {
case V_274 :
V_15 -> V_26 = V_15 -> V_275 -> V_215 ;
switch ( V_214 -> V_215 ) {
case V_276 :
V_15 -> V_27 = 115 ;
V_15 -> V_28 = 145 ;
break;
case V_277 :
V_15 -> V_27 = V_15 -> V_278 -> V_215 >> 8 ;
V_15 -> V_28 = V_15 -> V_278 -> V_215 & 0xff ;
break;
default:
V_15 -> V_27 = 128 ;
V_15 -> V_28 = 128 ;
}
break;
case V_279 :
V_15 -> V_24 = V_15 -> V_280 -> V_215 ;
break;
default:
F_2 ( 1 ) ;
}
V_15 -> V_2 [ V_259 ] . V_30 |= V_31 ;
V_15 -> V_2 [ V_263 ] . V_30 |= V_31 ;
F_28 ( & V_15 -> V_46 , V_44 ) ;
return 0 ;
}
int F_158 ( struct V_14 * V_15 )
{
struct V_281 * V_273 = & V_15 -> V_244 ;
struct V_149 * V_19 = & V_15 -> V_262 ;
int V_58 ;
F_159 ( V_19 , & V_282 ) ;
V_19 -> V_44 |= V_283 ;
F_87 ( V_19 -> V_151 , L_31 , sizeof( V_19 -> V_151 ) ) ;
V_15 -> V_181 [ V_256 ] . V_44 = V_242 ;
V_15 -> V_181 [ V_257 ] . V_44 = V_284 ;
V_15 -> V_181 [ V_258 ] . V_44 = V_284 ;
V_58 = F_131 ( & V_19 -> V_182 , V_285 ,
V_15 -> V_181 , 0 ) ;
if ( V_58 )
return V_58 ;
F_134 ( V_273 , 3 ) ;
V_15 -> V_280 = F_160 ( V_273 ,
& V_286 , V_279 ,
F_146 ( V_287 ) - 1 , 0 , 0 ,
V_287 ) ;
V_15 -> V_275 = F_161 ( V_273 ,
& V_286 ,
V_274 , V_277 ,
~ 0x981f , V_288 ) ;
V_15 -> V_278 = F_135 ( V_273 ,
& V_286 ,
V_289 , 0 , 0xffff , 1 , 0 ) ;
if ( V_273 -> error ) {
F_139 ( V_273 ) ;
F_140 ( & V_19 -> V_182 ) ;
return V_273 -> error ;
}
F_162 ( 2 , & V_15 -> V_275 ,
V_277 , false ) ;
if ( ! V_15 -> V_17 -> V_25 ) {
V_15 -> V_275 -> V_44 |= V_290 ;
V_15 -> V_278 -> V_44 |= V_290 ;
}
V_19 -> V_244 = V_273 ;
F_163 ( V_19 , V_15 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_15 )
{
struct V_149 * V_19 = & V_15 -> V_262 ;
if ( F_148 ( V_19 ) == NULL )
return;
F_165 ( V_19 ) ;
F_140 ( & V_19 -> V_182 ) ;
F_139 ( & V_15 -> V_244 ) ;
F_163 ( V_19 , NULL ) ;
}
int F_166 ( struct V_14 * V_15 )
{
unsigned int V_32 = V_15 -> V_17 -> V_22 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < V_264 ; V_152 ++ ) {
struct V_1 * V_2 = & V_15 -> V_2 [ V_152 ] ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_124 = V_152 ;
V_2 -> V_291 = V_15 -> V_17 -> V_292 ;
if ( V_32 == V_23 )
V_2 -> V_293 = V_152 ? V_294 :
V_295 ;
else
V_2 -> V_293 = V_296 ;
V_2 -> V_20 = F_59 ( V_2 , NULL , 0 ) ;
F_167 ( V_2 -> V_20 == NULL ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_11 = V_297 ;
V_5 -> V_115 = V_298 ;
V_5 -> V_9 . V_13 = V_297 ;
V_5 -> V_9 . V_67 = V_298 ;
V_2 -> V_3 . V_98 = 1 ;
V_2 -> V_118 = ( V_5 -> V_11 * V_5 -> V_115 *
V_2 -> V_20 -> V_114 ) / 8 ;
}
memset ( & V_15 -> V_190 , 0 , sizeof( V_15 -> V_190 ) ) ;
V_15 -> V_190 . V_13 = V_297 ;
V_15 -> V_190 . V_67 = V_298 ;
V_15 -> V_190 . V_191 = V_252 [ 0 ] ;
memset ( & V_15 -> V_165 , 0 , sizeof( V_15 -> V_165 ) ) ;
V_15 -> V_165 . V_13 = V_297 ;
V_15 -> V_165 . V_67 = V_298 ;
return 0 ;
}
