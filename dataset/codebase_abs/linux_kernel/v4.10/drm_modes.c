void F_1 ( const struct V_1 * V_2 )
{
F_2 ( L_1 V_3 L_2 , F_3 ( V_2 ) ) ;
}
struct V_1 * F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_5 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_6 )
return NULL ;
if ( F_6 ( V_5 , & V_6 -> V_8 , V_9 ) ) {
F_7 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
void F_8 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_5 , & V_2 -> V_8 ) ;
F_7 ( V_2 ) ;
}
void F_10 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_11 ( ! F_12 ( & V_11 -> V_5 -> V_12 . V_13 ) ) ;
F_13 ( & V_2 -> V_14 , & V_11 -> V_15 ) ;
}
struct V_1 * F_14 ( struct V_4 * V_5 , int V_16 ,
int V_17 , int V_18 ,
bool V_19 , bool V_20 , bool V_21 )
{
#define F_15 1000
#define F_16 18
#define F_17 8
#define F_18 3
#define F_19 6
#define F_20 250
struct V_1 * V_22 ;
unsigned int V_23 , V_24 ;
int V_25 , V_26 , V_27 , V_28 , V_29 ;
int V_30 ;
T_1 V_31 ;
V_22 = F_4 ( V_5 ) ;
if ( ! V_22 )
return NULL ;
if ( ! V_18 )
V_18 = 60 ;
if ( V_20 )
V_23 = V_18 * 2 ;
else
V_23 = V_18 ;
V_25 = V_16 - ( V_16 % F_17 ) ;
V_26 = 0 ;
if ( V_21 ) {
V_26 = V_25 * F_16 / 1000 ;
V_26 -= V_26 % F_17 ;
}
V_22 -> V_16 = V_25 + 2 * V_26 ;
if ( V_20 )
V_27 = V_17 / 2 ;
else
V_27 = V_17 ;
V_28 = 0 ;
if ( V_21 )
V_28 = V_27 * F_16 / 1000 ;
V_22 -> V_17 = V_17 + 2 * V_28 ;
if ( V_20 )
V_30 = 1 ;
else
V_30 = 0 ;
if ( ! ( V_17 % 3 ) && ( ( V_17 * 4 / 3 ) == V_16 ) )
V_29 = 4 ;
else if ( ! ( V_17 % 9 ) && ( ( V_17 * 16 / 9 ) == V_16 ) )
V_29 = 5 ;
else if ( ! ( V_17 % 10 ) && ( ( V_17 * 16 / 10 ) == V_16 ) )
V_29 = 6 ;
else if ( ! ( V_17 % 4 ) && ( ( V_17 * 5 / 4 ) == V_16 ) )
V_29 = 7 ;
else if ( ! ( V_17 % 9 ) && ( ( V_17 * 15 / 9 ) == V_16 ) )
V_29 = 7 ;
else
V_29 = 10 ;
if ( ! V_19 ) {
int V_32 , V_33 ;
#define F_21 550
#define F_22 8
unsigned int V_34 ;
int V_35 , V_36 , V_37 ;
V_32 = F_15 * 1000000 -
F_21 * F_15 * V_23 ;
V_33 = ( V_27 + 2 * V_28 + F_18 ) * 2 +
V_30 ;
V_24 = V_32 * 2 / ( V_33 * V_23 ) ;
V_32 = F_21 * F_15 / V_24 + 1 ;
if ( V_32 < ( V_29 + F_18 ) )
V_35 = V_29 + F_18 ;
else
V_35 = V_32 ;
V_36 = V_35 - V_29 ;
V_22 -> V_38 = V_27 + 2 * V_28 +
V_35 + F_18 ;
#define F_23 600
#define F_24 40
#define F_25 128
#define F_26 20
#define F_27 (CVT_M_FACTOR * CVT_K_FACTOR / 256)
#define F_28 ((CVT_C_FACTOR - CVT_J_FACTOR) * CVT_K_FACTOR / 256 + \
CVT_J_FACTOR)
V_34 = F_28 * F_15 - F_27 *
V_24 / 1000 ;
if ( V_34 < 20 * F_15 )
V_34 = 20 * F_15 ;
V_37 = V_22 -> V_16 * V_34 /
( 100 * F_15 - V_34 ) ;
V_37 -= V_37 % ( 2 * F_17 ) ;
V_22 -> V_39 = V_22 -> V_16 + V_37 ;
V_22 -> V_40 = V_22 -> V_16 + V_37 / 2 ;
V_22 -> V_41 = V_22 -> V_40 -
( V_22 -> V_39 * F_22 ) / 100 ;
V_22 -> V_41 += F_17 -
V_22 -> V_41 % F_17 ;
V_22 -> V_42 = V_22 -> V_17 + F_18 ;
V_22 -> V_43 = V_22 -> V_42 + V_29 ;
} else {
#define F_29 460
#define F_30 32
#define F_31 160
#define F_32 3
int V_44 ;
int V_32 , V_33 ;
V_32 = F_15 * 1000000 -
F_29 * F_15 * V_23 ;
V_33 = V_27 + 2 * V_28 ;
V_24 = V_32 / ( V_33 * V_23 ) ;
V_44 = F_29 * F_15 / V_24 + 1 ;
if ( V_44 < ( F_32 + V_29 + F_19 ) )
V_44 = F_32 + V_29 + F_19 ;
V_22 -> V_38 = V_27 + 2 * V_28 + V_44 ;
V_22 -> V_39 = V_22 -> V_16 + F_31 ;
V_22 -> V_40 = V_22 -> V_16 + F_31 / 2 ;
V_22 -> V_41 = V_22 -> V_40 - F_30 ;
V_22 -> V_42 = V_22 -> V_17 + F_32 ;
V_22 -> V_43 = V_22 -> V_42 + V_29 ;
}
V_31 = V_22 -> V_39 ;
V_31 *= F_15 * 1000 ;
F_33 ( V_31 , V_24 ) ;
V_31 -= V_22 -> clock % F_20 ;
V_22 -> clock = V_31 ;
if ( V_20 ) {
V_22 -> V_38 *= 2 ;
V_22 -> V_45 |= V_46 ;
}
F_34 ( V_22 ) ;
if ( V_19 )
V_22 -> V_45 |= ( V_47 |
V_48 ) ;
else
V_22 -> V_45 |= ( V_49 |
V_50 ) ;
return V_22 ;
}
struct V_1 *
F_35 ( struct V_4 * V_5 , int V_16 , int V_17 ,
int V_18 , bool V_20 , int V_21 ,
int V_51 , int V_52 , int V_53 , int V_54 )
{
#define F_36 18
#define F_37 8
#define F_38 1
#define F_39 3
#define F_40 8
#define F_41 550
#define F_42 ((((GTF_2C - GTF_2J) * GTF_K / 256) + GTF_2J) / 2)
#define F_43 (GTF_K * GTF_M / 256)
struct V_1 * V_22 ;
unsigned int V_25 , V_27 , V_55 ;
int V_56 , V_57 ;
int V_30 ;
unsigned int V_58 ;
int V_59 , V_36 ;
unsigned int V_60 , V_61 , V_24 ;
unsigned int V_62 , V_63 ;
int V_64 , V_65 ;
unsigned int V_66 , V_67 ;
unsigned int V_37 , V_68 , V_69 ;
int V_70 , V_71 , V_72 ;
unsigned int V_32 , V_33 ;
V_22 = F_4 ( V_5 ) ;
if ( ! V_22 )
return NULL ;
V_25 = ( V_16 + F_37 / 2 ) / F_37 ;
V_25 = V_25 * F_37 ;
if ( V_20 )
V_27 = V_17 / 2 ;
else
V_27 = V_17 ;
if ( V_20 )
V_55 = V_18 * 2 ;
else
V_55 = V_18 ;
V_56 = 0 ;
if ( V_21 )
V_56 = ( V_27 * F_36 + 500 ) /
1000 ;
V_57 = V_56 ;
if ( V_20 )
V_30 = 1 ;
else
V_30 = 0 ;
{
V_32 = ( 1000000 - F_41 * V_55 ) / 500 ;
V_33 = ( V_27 + 2 * V_56 + F_38 ) *
2 + V_30 ;
V_58 = ( V_33 * 1000 * V_55 ) / V_32 ;
}
V_59 = F_41 * V_58 / 1000 ;
V_59 = ( V_59 + 500 ) / 1000 ;
V_36 = V_59 - F_39 ;
V_60 = V_27 + V_56 + V_57 +
V_59 + F_38 ;
V_61 = V_58 / V_60 ;
V_24 = 1000000 / ( V_55 * V_60 ) ;
V_62 = V_58 / V_60 ;
if ( V_20 )
V_63 = V_62 / 2 ;
else
V_63 = V_62 ;
if ( V_21 )
V_64 = ( V_25 * F_36 + 500 ) /
1000 ;
else
V_64 = 0 ;
V_65 = V_64 ;
V_66 = V_25 + V_64 + V_65 ;
V_67 = F_42 * 1000 -
( F_43 * 1000000 / V_58 ) ;
V_37 = V_66 * V_67 /
( 100000 - V_67 ) ;
V_37 = ( V_37 + F_37 ) / ( 2 * F_37 ) ;
V_37 = V_37 * 2 * F_37 ;
V_68 = V_66 + V_37 ;
V_69 = V_68 * V_58 / 1000 ;
V_70 = F_40 * V_68 / 100 ;
V_70 = ( V_70 + F_37 / 2 ) / F_37 ;
V_70 = V_70 * F_37 ;
V_71 = V_37 / 2 - V_70 ;
V_72 = F_38 ;
V_22 -> V_16 = V_25 ;
V_22 -> V_41 = V_25 + V_71 ;
V_22 -> V_40 = V_22 -> V_41 + V_70 ;
V_22 -> V_39 = V_68 ;
V_22 -> V_17 = V_27 ;
V_22 -> V_42 = V_27 + V_72 ;
V_22 -> V_43 = V_22 -> V_42 + F_39 ;
V_22 -> V_38 = V_60 ;
V_22 -> clock = V_69 ;
if ( V_20 ) {
V_22 -> V_38 *= 2 ;
V_22 -> V_45 |= V_46 ;
}
F_34 ( V_22 ) ;
if ( V_51 == 600 && V_52 == 80 && V_53 == 128 && V_54 == 40 )
V_22 -> V_45 = V_50 | V_49 ;
else
V_22 -> V_45 = V_47 | V_48 ;
return V_22 ;
}
struct V_1 *
F_44 ( struct V_4 * V_5 , int V_16 , int V_17 , int V_18 ,
bool V_20 , int V_21 )
{
return F_35 ( V_5 , V_16 , V_17 , V_18 ,
V_20 , V_21 ,
600 , 40 * 2 , 128 , 20 * 2 ) ;
}
void F_45 ( const struct V_73 * V_74 ,
struct V_1 * V_75 )
{
V_75 -> V_16 = V_74 -> V_76 ;
V_75 -> V_41 = V_75 -> V_16 + V_74 -> V_71 ;
V_75 -> V_40 = V_75 -> V_41 + V_74 -> V_77 ;
V_75 -> V_39 = V_75 -> V_40 + V_74 -> V_78 ;
V_75 -> V_17 = V_74 -> V_79 ;
V_75 -> V_42 = V_75 -> V_17 + V_74 -> V_80 ;
V_75 -> V_43 = V_75 -> V_42 + V_74 -> V_81 ;
V_75 -> V_38 = V_75 -> V_43 + V_74 -> V_36 ;
V_75 -> clock = V_74 -> V_82 / 1000 ;
V_75 -> V_45 = 0 ;
if ( V_74 -> V_45 & V_83 )
V_75 -> V_45 |= V_47 ;
else if ( V_74 -> V_45 & V_84 )
V_75 -> V_45 |= V_50 ;
if ( V_74 -> V_45 & V_85 )
V_75 -> V_45 |= V_49 ;
else if ( V_74 -> V_45 & V_86 )
V_75 -> V_45 |= V_48 ;
if ( V_74 -> V_45 & V_87 )
V_75 -> V_45 |= V_46 ;
if ( V_74 -> V_45 & V_88 )
V_75 -> V_45 |= V_89 ;
if ( V_74 -> V_45 & V_90 )
V_75 -> V_45 |= V_91 ;
F_34 ( V_75 ) ;
}
void F_46 ( const struct V_1 * V_75 ,
struct V_73 * V_74 )
{
V_74 -> V_76 = V_75 -> V_16 ;
V_74 -> V_71 = V_75 -> V_41 - V_75 -> V_16 ;
V_74 -> V_77 = V_75 -> V_40 - V_75 -> V_41 ;
V_74 -> V_78 = V_75 -> V_39 - V_75 -> V_40 ;
V_74 -> V_79 = V_75 -> V_17 ;
V_74 -> V_80 = V_75 -> V_42 - V_75 -> V_17 ;
V_74 -> V_81 = V_75 -> V_43 - V_75 -> V_42 ;
V_74 -> V_36 = V_75 -> V_38 - V_75 -> V_43 ;
V_74 -> V_82 = V_75 -> clock * 1000 ;
V_74 -> V_45 = 0 ;
if ( V_75 -> V_45 & V_47 )
V_74 -> V_45 |= V_83 ;
else if ( V_75 -> V_45 & V_50 )
V_74 -> V_45 |= V_84 ;
if ( V_75 -> V_45 & V_49 )
V_74 -> V_45 |= V_85 ;
else if ( V_75 -> V_45 & V_48 )
V_74 -> V_45 |= V_86 ;
if ( V_75 -> V_45 & V_46 )
V_74 -> V_45 |= V_87 ;
if ( V_75 -> V_45 & V_89 )
V_74 -> V_45 |= V_88 ;
if ( V_75 -> V_45 & V_91 )
V_74 -> V_45 |= V_90 ;
}
void F_47 ( const struct V_73 * V_74 , T_2 * V_92 )
{
* V_92 = 0 ;
if ( V_74 -> V_45 & V_93 )
* V_92 |= V_94 ;
if ( V_74 -> V_45 & V_95 )
* V_92 |= V_96 ;
if ( V_74 -> V_45 & V_97 )
* V_92 |= V_98 ;
if ( V_74 -> V_45 & V_99 )
* V_92 |= V_100 ;
}
int F_48 ( struct V_101 * V_102 ,
struct V_1 * V_75 , T_2 * V_92 ,
int V_103 )
{
struct V_73 V_74 ;
int V_104 ;
V_104 = F_49 ( V_102 , & V_74 , V_103 ) ;
if ( V_104 )
return V_104 ;
F_45 ( & V_74 , V_75 ) ;
if ( V_92 )
F_47 ( & V_74 , V_92 ) ;
F_50 ( L_3 ,
F_51 ( V_102 ) , V_74 . V_76 , V_74 . V_79 , V_102 -> V_105 ) ;
F_1 ( V_75 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
bool V_20 = ! ! ( V_2 -> V_45 & V_46 ) ;
snprintf ( V_2 -> V_105 , V_106 , L_4 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_20 ? L_5 : L_6 ) ;
}
int F_52 ( const struct V_1 * V_2 )
{
unsigned int V_107 ;
if ( V_2 -> V_70 )
return V_2 -> V_70 ;
if ( V_2 -> V_39 < 0 )
return 0 ;
V_107 = ( V_2 -> clock * 1000 ) / V_2 -> V_39 ;
V_107 += 500 ;
V_107 /= 1000 ;
return V_107 ;
}
int F_53 ( const struct V_1 * V_2 )
{
int V_108 = 0 ;
unsigned int V_107 ;
if ( V_2 -> V_18 > 0 )
V_108 = V_2 -> V_18 ;
else if ( V_2 -> V_39 > 0 && V_2 -> V_38 > 0 ) {
int V_38 ;
V_38 = V_2 -> V_38 ;
V_107 = ( V_2 -> clock * 1000 ) ;
V_107 /= V_2 -> V_39 ;
V_108 = ( V_107 + V_38 / 2 ) / V_38 ;
if ( V_2 -> V_45 & V_46 )
V_108 *= 2 ;
if ( V_2 -> V_45 & V_89 )
V_108 /= 2 ;
if ( V_2 -> V_109 > 1 )
V_108 /= V_2 -> V_109 ;
}
return V_108 ;
}
void F_54 ( struct V_1 * V_110 , int V_111 )
{
if ( ( V_110 == NULL ) || ( ( V_110 -> type & V_112 ) == V_113 ) )
return;
V_110 -> V_114 = V_110 -> clock ;
V_110 -> V_115 = V_110 -> V_16 ;
V_110 -> V_116 = V_110 -> V_41 ;
V_110 -> V_117 = V_110 -> V_40 ;
V_110 -> V_118 = V_110 -> V_39 ;
V_110 -> V_119 = V_110 -> V_120 ;
V_110 -> V_121 = V_110 -> V_17 ;
V_110 -> V_122 = V_110 -> V_42 ;
V_110 -> V_123 = V_110 -> V_43 ;
V_110 -> V_124 = V_110 -> V_38 ;
if ( V_110 -> V_45 & V_46 ) {
if ( V_111 & V_125 ) {
V_110 -> V_121 /= 2 ;
V_110 -> V_122 /= 2 ;
V_110 -> V_123 /= 2 ;
V_110 -> V_124 /= 2 ;
}
}
if ( ! ( V_111 & V_126 ) ) {
if ( V_110 -> V_45 & V_89 ) {
V_110 -> V_121 *= 2 ;
V_110 -> V_122 *= 2 ;
V_110 -> V_123 *= 2 ;
V_110 -> V_124 *= 2 ;
}
}
if ( ! ( V_111 & V_127 ) ) {
if ( V_110 -> V_109 > 1 ) {
V_110 -> V_121 *= V_110 -> V_109 ;
V_110 -> V_122 *= V_110 -> V_109 ;
V_110 -> V_123 *= V_110 -> V_109 ;
V_110 -> V_124 *= V_110 -> V_109 ;
}
}
if ( V_111 & V_128 ) {
unsigned int V_129 = V_110 -> V_45 & V_130 ;
switch ( V_129 ) {
case V_131 :
V_110 -> V_114 *= 2 ;
V_110 -> V_121 += V_110 -> V_124 ;
V_110 -> V_122 += V_110 -> V_124 ;
V_110 -> V_123 += V_110 -> V_124 ;
V_110 -> V_124 += V_110 -> V_124 ;
break;
}
}
V_110 -> V_132 = F_55 ( V_110 -> V_122 , V_110 -> V_121 ) ;
V_110 -> V_133 = F_56 ( V_110 -> V_123 , V_110 -> V_124 ) ;
V_110 -> V_134 = F_55 ( V_110 -> V_116 , V_110 -> V_115 ) ;
V_110 -> V_135 = F_56 ( V_110 -> V_117 , V_110 -> V_118 ) ;
}
void F_57 ( struct V_1 * V_136 , const struct V_1 * V_137 )
{
int V_138 = V_136 -> V_8 . V_138 ;
struct V_139 V_14 = V_136 -> V_14 ;
* V_136 = * V_137 ;
V_136 -> V_8 . V_138 = V_138 ;
V_136 -> V_14 = V_14 ;
}
struct V_1 * F_58 ( struct V_4 * V_5 ,
const struct V_1 * V_2 )
{
struct V_1 * V_6 ;
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 )
return NULL ;
F_57 ( V_6 , V_2 ) ;
return V_6 ;
}
bool F_59 ( const struct V_1 * V_140 , const struct V_1 * V_141 )
{
if ( ! V_140 && ! V_141 )
return true ;
if ( ! V_140 || ! V_141 )
return false ;
if ( V_140 -> clock && V_141 -> clock ) {
if ( F_60 ( V_140 -> clock ) != F_60 ( V_141 -> clock ) )
return false ;
} else if ( V_140 -> clock != V_141 -> clock )
return false ;
return F_61 ( V_140 , V_141 ) ;
}
bool F_61 ( const struct V_1 * V_140 , const struct V_1 * V_141 )
{
if ( ( V_140 -> V_45 & V_130 ) !=
( V_141 -> V_45 & V_130 ) )
return false ;
return F_62 ( V_140 , V_141 ) ;
}
bool F_62 ( const struct V_1 * V_140 ,
const struct V_1 * V_141 )
{
if ( V_140 -> V_16 == V_141 -> V_16 &&
V_140 -> V_41 == V_141 -> V_41 &&
V_140 -> V_40 == V_141 -> V_40 &&
V_140 -> V_39 == V_141 -> V_39 &&
V_140 -> V_120 == V_141 -> V_120 &&
V_140 -> V_17 == V_141 -> V_17 &&
V_140 -> V_42 == V_141 -> V_42 &&
V_140 -> V_43 == V_141 -> V_43 &&
V_140 -> V_38 == V_141 -> V_38 &&
V_140 -> V_109 == V_141 -> V_109 &&
( V_140 -> V_45 & ~ V_130 ) ==
( V_141 -> V_45 & ~ V_130 ) )
return true ;
return false ;
}
enum V_142
F_63 ( const struct V_1 * V_2 )
{
if ( V_2 -> clock == 0 )
return V_143 ;
if ( V_2 -> V_16 == 0 ||
V_2 -> V_41 < V_2 -> V_16 ||
V_2 -> V_40 < V_2 -> V_41 ||
V_2 -> V_39 < V_2 -> V_40 )
return V_144 ;
if ( V_2 -> V_17 == 0 ||
V_2 -> V_42 < V_2 -> V_17 ||
V_2 -> V_43 < V_2 -> V_42 ||
V_2 -> V_38 < V_2 -> V_43 )
return V_145 ;
return V_146 ;
}
enum V_142
F_64 ( const struct V_1 * V_2 ,
int V_147 , int V_148 )
{
if ( V_147 > 0 && V_2 -> V_16 > V_147 )
return V_149 ;
if ( V_148 > 0 && V_2 -> V_17 > V_148 )
return V_150 ;
return V_146 ;
}
static const char * F_65 ( enum V_142 V_151 )
{
int V_103 = V_151 + 3 ;
if ( F_11 ( V_103 < 0 || V_103 >= F_66 ( V_152 ) ) )
return L_6 ;
return V_152 [ V_103 ] ;
}
void F_67 ( struct V_4 * V_5 ,
struct V_139 * V_153 , bool V_154 )
{
struct V_1 * V_2 , * V_155 ;
F_68 (mode, t, mode_list, head) {
if ( V_2 -> V_151 != V_146 ) {
F_69 ( & V_2 -> V_14 ) ;
if ( V_154 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_105 ,
F_65 ( V_2 -> V_151 ) ) ;
}
F_8 ( V_5 , V_2 ) ;
}
}
}
static int F_70 ( void * V_156 , struct V_139 * V_157 , struct V_139 * V_158 )
{
struct V_1 * V_159 = F_71 ( V_157 , struct V_1 , V_14 ) ;
struct V_1 * V_160 = F_71 ( V_158 , struct V_1 , V_14 ) ;
int V_161 ;
V_161 = ( ( V_160 -> type & V_162 ) != 0 ) -
( ( V_159 -> type & V_162 ) != 0 ) ;
if ( V_161 )
return V_161 ;
V_161 = V_160 -> V_16 * V_160 -> V_17 - V_159 -> V_16 * V_159 -> V_17 ;
if ( V_161 )
return V_161 ;
V_161 = V_160 -> V_18 - V_159 -> V_18 ;
if ( V_161 )
return V_161 ;
V_161 = V_160 -> clock - V_159 -> clock ;
return V_161 ;
}
void F_72 ( struct V_139 * V_153 )
{
F_73 ( NULL , V_153 , F_70 ) ;
}
void F_74 ( struct V_10 * V_11 )
{
struct V_1 * V_163 , * V_164 ;
F_11 ( ! F_12 ( & V_11 -> V_5 -> V_12 . V_13 ) ) ;
F_68 (pmode, pt, &connector->probed_modes, head) {
struct V_1 * V_2 ;
bool V_165 = false ;
F_75 (mode, &connector->modes, head) {
if ( ! F_59 ( V_163 , V_2 ) )
continue;
V_165 = true ;
if ( V_2 -> V_151 == V_166 ) {
F_57 ( V_2 , V_163 ) ;
} else if ( ( V_2 -> type & V_162 ) == 0 &&
( V_163 -> type & V_162 ) != 0 ) {
V_163 -> type |= V_2 -> type ;
F_57 ( V_2 , V_163 ) ;
} else {
V_2 -> type |= V_163 -> type ;
}
F_69 ( & V_163 -> V_14 ) ;
F_8 ( V_11 -> V_5 , V_163 ) ;
break;
}
if ( ! V_165 ) {
F_76 ( & V_163 -> V_14 , & V_11 -> V_167 ) ;
}
}
}
bool F_77 ( const char * V_168 ,
struct V_10 * V_11 ,
struct V_169 * V_2 )
{
const char * V_105 ;
unsigned int V_170 ;
bool V_171 = false , V_172 = false , V_173 = false ;
unsigned int V_174 = 0 , V_175 = 0 , V_176 = 32 , V_108 = 0 ;
bool V_177 = false , V_178 = false , V_179 = false ;
bool V_30 = false , V_21 = false , V_180 = false ;
int V_181 ;
enum V_182 V_183 = V_184 ;
#ifdef F_78
if ( ! V_168 )
V_168 = V_185 ;
#endif
if ( ! V_168 ) {
V_2 -> V_186 = false ;
return false ;
}
V_105 = V_168 ;
V_170 = strlen ( V_105 ) ;
for ( V_181 = V_170 - 1 ; V_181 >= 0 ; V_181 -- ) {
switch ( V_105 [ V_181 ] ) {
case '@' :
if ( ! V_173 && ! V_172 &&
! V_177 && ! V_178 && ! V_179 && V_180 ) {
V_108 = F_79 ( & V_105 [ V_181 + 1 ] , NULL , 10 ) ;
V_173 = true ;
V_180 = false ;
} else
goto V_187;
break;
case '-' :
if ( ! V_172 && ! V_177 && ! V_178 &&
! V_179 && V_180 ) {
V_176 = F_79 ( & V_105 [ V_181 + 1 ] , NULL , 10 ) ;
V_172 = true ;
V_180 = false ;
} else
goto V_187;
break;
case 'x' :
if ( ! V_177 && V_180 ) {
V_175 = F_79 ( & V_105 [ V_181 + 1 ] , NULL , 10 ) ;
V_177 = true ;
V_180 = false ;
} else
goto V_187;
break;
case '0' ... '9' :
V_180 = true ;
break;
case 'M' :
if ( V_177 || V_178 || V_180 )
goto V_187;
V_178 = true ;
break;
case 'R' :
if ( V_177 || V_178 || V_179 || V_180 )
goto V_187;
V_179 = true ;
break;
case 'm' :
if ( V_178 || V_177 || V_180 )
goto V_187;
V_21 = true ;
break;
case 'i' :
if ( V_178 || V_177 || V_180 )
goto V_187;
V_30 = true ;
break;
case 'e' :
if ( V_177 || V_172 || V_173 ||
V_180 || ( V_183 != V_184 ) )
goto V_187;
V_183 = V_188 ;
break;
case 'D' :
if ( V_177 || V_172 || V_173 ||
V_180 || ( V_183 != V_184 ) )
goto V_187;
if ( ( V_11 -> V_189 != V_190 ) &&
( V_11 -> V_189 != V_191 ) )
V_183 = V_188 ;
else
V_183 = V_192 ;
break;
case 'd' :
if ( V_177 || V_172 || V_173 ||
V_180 || ( V_183 != V_184 ) )
goto V_187;
V_183 = V_193 ;
break;
default:
goto V_187;
}
}
if ( V_181 < 0 && V_177 ) {
char * V_194 ;
V_174 = F_79 ( V_105 , & V_194 , 10 ) ;
if ( ( V_194 != NULL ) && ( * V_194 == 'x' ) )
V_171 = true ;
else
V_181 = V_194 - V_105 ;
} else if ( ! V_177 && V_180 ) {
V_181 = 0 ;
}
V_187:
if ( V_181 >= 0 ) {
F_80 ( L_8 ,
V_181 , V_105 ) ;
V_2 -> V_186 = false ;
return false ;
}
if ( V_171 ) {
V_2 -> V_186 = true ;
V_2 -> V_174 = V_174 ;
V_2 -> V_175 = V_175 ;
}
if ( V_173 ) {
V_2 -> V_173 = true ;
V_2 -> V_108 = V_108 ;
}
if ( V_172 ) {
V_2 -> V_172 = true ;
V_2 -> V_176 = V_176 ;
}
V_2 -> V_179 = V_179 ;
V_2 -> V_178 = V_178 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_183 = V_183 ;
return true ;
}
struct V_1 *
F_81 ( struct V_4 * V_5 ,
struct V_169 * V_195 )
{
struct V_1 * V_2 ;
if ( V_195 -> V_178 )
V_2 = F_14 ( V_5 ,
V_195 -> V_174 , V_195 -> V_175 ,
V_195 -> V_173 ? V_195 -> V_108 : 60 ,
V_195 -> V_179 , V_195 -> V_30 ,
V_195 -> V_21 ) ;
else
V_2 = F_44 ( V_5 ,
V_195 -> V_174 , V_195 -> V_175 ,
V_195 -> V_173 ? V_195 -> V_108 : 60 ,
V_195 -> V_30 ,
V_195 -> V_21 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type |= V_196 ;
if ( V_195 -> V_174 == 1366 && V_2 -> V_16 == 1368 ) {
V_2 -> V_16 = 1366 ;
V_2 -> V_41 -- ;
V_2 -> V_40 -- ;
F_34 ( V_2 ) ;
}
F_54 ( V_2 , V_125 ) ;
return V_2 ;
}
void F_82 ( struct V_197 * V_198 ,
const struct V_1 * V_199 )
{
F_83 ( V_199 -> V_16 > V_200 || V_199 -> V_41 > V_200 ||
V_199 -> V_40 > V_200 || V_199 -> V_39 > V_200 ||
V_199 -> V_120 > V_200 || V_199 -> V_17 > V_200 ||
V_199 -> V_42 > V_200 || V_199 -> V_43 > V_200 ||
V_199 -> V_38 > V_200 || V_199 -> V_109 > V_200 ,
L_9 ) ;
V_198 -> clock = V_199 -> clock ;
V_198 -> V_16 = V_199 -> V_16 ;
V_198 -> V_41 = V_199 -> V_41 ;
V_198 -> V_40 = V_199 -> V_40 ;
V_198 -> V_39 = V_199 -> V_39 ;
V_198 -> V_120 = V_199 -> V_120 ;
V_198 -> V_17 = V_199 -> V_17 ;
V_198 -> V_42 = V_199 -> V_42 ;
V_198 -> V_43 = V_199 -> V_43 ;
V_198 -> V_38 = V_199 -> V_38 ;
V_198 -> V_109 = V_199 -> V_109 ;
V_198 -> V_18 = V_199 -> V_18 ;
V_198 -> V_45 = V_199 -> V_45 ;
V_198 -> type = V_199 -> type ;
strncpy ( V_198 -> V_105 , V_199 -> V_105 , V_106 ) ;
V_198 -> V_105 [ V_106 - 1 ] = 0 ;
}
int F_84 ( struct V_1 * V_198 ,
const struct V_197 * V_199 )
{
int V_104 = - V_201 ;
if ( V_199 -> clock > V_202 || V_199 -> V_18 > V_202 ) {
V_104 = - V_203 ;
goto V_198;
}
if ( ( V_199 -> V_45 & V_130 ) > V_204 )
goto V_198;
V_198 -> clock = V_199 -> clock ;
V_198 -> V_16 = V_199 -> V_16 ;
V_198 -> V_41 = V_199 -> V_41 ;
V_198 -> V_40 = V_199 -> V_40 ;
V_198 -> V_39 = V_199 -> V_39 ;
V_198 -> V_120 = V_199 -> V_120 ;
V_198 -> V_17 = V_199 -> V_17 ;
V_198 -> V_42 = V_199 -> V_42 ;
V_198 -> V_43 = V_199 -> V_43 ;
V_198 -> V_38 = V_199 -> V_38 ;
V_198 -> V_109 = V_199 -> V_109 ;
V_198 -> V_18 = V_199 -> V_18 ;
V_198 -> V_45 = V_199 -> V_45 ;
V_198 -> type = V_199 -> type ;
strncpy ( V_198 -> V_105 , V_199 -> V_105 , V_106 ) ;
V_198 -> V_105 [ V_106 - 1 ] = 0 ;
V_198 -> V_151 = F_63 ( V_198 ) ;
if ( V_198 -> V_151 != V_146 )
goto V_198;
F_54 ( V_198 , V_125 ) ;
V_104 = 0 ;
V_198:
return V_104 ;
}
