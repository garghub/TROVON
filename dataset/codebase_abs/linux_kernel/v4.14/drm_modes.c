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
V_102 , V_74 . V_76 , V_74 . V_79 , V_102 -> V_105 ) ;
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
int F_51 ( const struct V_1 * V_2 )
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
int F_52 ( const struct V_1 * V_2 )
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
void F_53 ( const struct V_1 * V_2 ,
int * V_16 , int * V_17 )
{
struct V_1 V_110 = * V_2 ;
F_54 ( & V_110 , V_111 ) ;
* V_16 = V_110 . V_112 ;
* V_17 = V_110 . V_113 ;
}
void F_54 ( struct V_1 * V_114 , int V_115 )
{
if ( ( V_114 == NULL ) || ( ( V_114 -> type & V_116 ) == V_117 ) )
return;
V_114 -> V_118 = V_114 -> clock ;
V_114 -> V_112 = V_114 -> V_16 ;
V_114 -> V_119 = V_114 -> V_41 ;
V_114 -> V_120 = V_114 -> V_40 ;
V_114 -> V_121 = V_114 -> V_39 ;
V_114 -> V_122 = V_114 -> V_123 ;
V_114 -> V_113 = V_114 -> V_17 ;
V_114 -> V_124 = V_114 -> V_42 ;
V_114 -> V_125 = V_114 -> V_43 ;
V_114 -> V_126 = V_114 -> V_38 ;
if ( V_114 -> V_45 & V_46 ) {
if ( V_115 & V_127 ) {
V_114 -> V_113 /= 2 ;
V_114 -> V_124 /= 2 ;
V_114 -> V_125 /= 2 ;
V_114 -> V_126 /= 2 ;
}
}
if ( ! ( V_115 & V_128 ) ) {
if ( V_114 -> V_45 & V_89 ) {
V_114 -> V_113 *= 2 ;
V_114 -> V_124 *= 2 ;
V_114 -> V_125 *= 2 ;
V_114 -> V_126 *= 2 ;
}
}
if ( ! ( V_115 & V_129 ) ) {
if ( V_114 -> V_109 > 1 ) {
V_114 -> V_113 *= V_114 -> V_109 ;
V_114 -> V_124 *= V_114 -> V_109 ;
V_114 -> V_125 *= V_114 -> V_109 ;
V_114 -> V_126 *= V_114 -> V_109 ;
}
}
if ( V_115 & V_130 ) {
unsigned int V_131 = V_114 -> V_45 & V_132 ;
switch ( V_131 ) {
case V_133 :
V_114 -> V_118 *= 2 ;
V_114 -> V_113 += V_114 -> V_126 ;
V_114 -> V_124 += V_114 -> V_126 ;
V_114 -> V_125 += V_114 -> V_126 ;
V_114 -> V_126 += V_114 -> V_126 ;
break;
}
}
V_114 -> V_134 = F_55 ( V_114 -> V_124 , V_114 -> V_113 ) ;
V_114 -> V_135 = F_56 ( V_114 -> V_125 , V_114 -> V_126 ) ;
V_114 -> V_136 = F_55 ( V_114 -> V_119 , V_114 -> V_112 ) ;
V_114 -> V_137 = F_56 ( V_114 -> V_120 , V_114 -> V_121 ) ;
}
void F_57 ( struct V_1 * V_138 , const struct V_1 * V_139 )
{
int V_140 = V_138 -> V_8 . V_140 ;
struct V_141 V_14 = V_138 -> V_14 ;
* V_138 = * V_139 ;
V_138 -> V_8 . V_140 = V_140 ;
V_138 -> V_14 = V_14 ;
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
bool F_59 ( const struct V_1 * V_142 , const struct V_1 * V_143 )
{
if ( ! V_142 && ! V_143 )
return true ;
if ( ! V_142 || ! V_143 )
return false ;
if ( V_142 -> clock && V_143 -> clock ) {
if ( F_60 ( V_142 -> clock ) != F_60 ( V_143 -> clock ) )
return false ;
} else if ( V_142 -> clock != V_143 -> clock )
return false ;
return F_61 ( V_142 , V_143 ) ;
}
bool F_61 ( const struct V_1 * V_142 , const struct V_1 * V_143 )
{
if ( ( V_142 -> V_45 & V_132 ) !=
( V_143 -> V_45 & V_132 ) )
return false ;
return F_62 ( V_142 , V_143 ) ;
}
bool F_62 ( const struct V_1 * V_142 ,
const struct V_1 * V_143 )
{
if ( V_142 -> V_16 == V_143 -> V_16 &&
V_142 -> V_41 == V_143 -> V_41 &&
V_142 -> V_40 == V_143 -> V_40 &&
V_142 -> V_39 == V_143 -> V_39 &&
V_142 -> V_123 == V_143 -> V_123 &&
V_142 -> V_17 == V_143 -> V_17 &&
V_142 -> V_42 == V_143 -> V_42 &&
V_142 -> V_43 == V_143 -> V_43 &&
V_142 -> V_38 == V_143 -> V_38 &&
V_142 -> V_109 == V_143 -> V_109 &&
( V_142 -> V_45 & ~ V_132 ) ==
( V_143 -> V_45 & ~ V_132 ) )
return true ;
return false ;
}
enum V_144
F_63 ( const struct V_1 * V_2 )
{
if ( V_2 -> clock == 0 )
return V_145 ;
if ( V_2 -> V_16 == 0 ||
V_2 -> V_41 < V_2 -> V_16 ||
V_2 -> V_40 < V_2 -> V_41 ||
V_2 -> V_39 < V_2 -> V_40 )
return V_146 ;
if ( V_2 -> V_17 == 0 ||
V_2 -> V_42 < V_2 -> V_17 ||
V_2 -> V_43 < V_2 -> V_42 ||
V_2 -> V_38 < V_2 -> V_43 )
return V_147 ;
return V_148 ;
}
enum V_144
F_64 ( const struct V_1 * V_2 ,
int V_149 , int V_150 )
{
if ( V_149 > 0 && V_2 -> V_16 > V_149 )
return V_151 ;
if ( V_150 > 0 && V_2 -> V_17 > V_150 )
return V_152 ;
return V_148 ;
}
enum V_144
F_65 ( const struct V_1 * V_2 ,
struct V_10 * V_11 )
{
T_3 V_153 = F_66 ( V_2 ) ;
enum V_144 V_154 = V_148 ;
struct V_155 * V_156 = & V_11 -> V_157 . V_156 ;
if ( F_67 ( V_153 , V_156 -> V_158 ) ) {
if ( ! V_11 -> V_159 )
V_154 = V_160 ;
}
return V_154 ;
}
static const char * F_68 ( enum V_144 V_154 )
{
int V_103 = V_154 + 3 ;
if ( F_11 ( V_103 < 0 || V_103 >= F_69 ( V_161 ) ) )
return L_6 ;
return V_161 [ V_103 ] ;
}
void F_70 ( struct V_4 * V_5 ,
struct V_141 * V_162 , bool V_163 )
{
struct V_1 * V_2 , * V_164 ;
F_71 (mode, t, mode_list, head) {
if ( V_2 -> V_154 != V_148 ) {
F_72 ( & V_2 -> V_14 ) ;
if ( V_163 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_105 ,
F_68 ( V_2 -> V_154 ) ) ;
}
F_8 ( V_5 , V_2 ) ;
}
}
}
static int F_73 ( void * V_165 , struct V_141 * V_166 , struct V_141 * V_167 )
{
struct V_1 * V_168 = F_74 ( V_166 , struct V_1 , V_14 ) ;
struct V_1 * V_169 = F_74 ( V_167 , struct V_1 , V_14 ) ;
int V_170 ;
V_170 = ( ( V_169 -> type & V_171 ) != 0 ) -
( ( V_168 -> type & V_171 ) != 0 ) ;
if ( V_170 )
return V_170 ;
V_170 = V_169 -> V_16 * V_169 -> V_17 - V_168 -> V_16 * V_168 -> V_17 ;
if ( V_170 )
return V_170 ;
V_170 = V_169 -> V_18 - V_168 -> V_18 ;
if ( V_170 )
return V_170 ;
V_170 = V_169 -> clock - V_168 -> clock ;
return V_170 ;
}
void F_75 ( struct V_141 * V_162 )
{
F_76 ( NULL , V_162 , F_73 ) ;
}
void F_77 ( struct V_10 * V_11 )
{
struct V_1 * V_172 , * V_173 ;
F_11 ( ! F_12 ( & V_11 -> V_5 -> V_12 . V_13 ) ) ;
F_71 (pmode, pt, &connector->probed_modes, head) {
struct V_1 * V_2 ;
bool V_174 = false ;
F_78 (mode, &connector->modes, head) {
if ( ! F_59 ( V_172 , V_2 ) )
continue;
V_174 = true ;
if ( V_2 -> V_154 == V_175 ) {
F_57 ( V_2 , V_172 ) ;
} else if ( ( V_2 -> type & V_171 ) == 0 &&
( V_172 -> type & V_171 ) != 0 ) {
V_172 -> type |= V_2 -> type ;
F_57 ( V_2 , V_172 ) ;
} else {
V_2 -> type |= V_172 -> type ;
}
F_72 ( & V_172 -> V_14 ) ;
F_8 ( V_11 -> V_5 , V_172 ) ;
break;
}
if ( ! V_174 ) {
F_79 ( & V_172 -> V_14 , & V_11 -> V_176 ) ;
}
}
}
bool F_80 ( const char * V_177 ,
struct V_10 * V_11 ,
struct V_178 * V_2 )
{
const char * V_105 ;
unsigned int V_179 ;
bool V_180 = false , V_181 = false , V_182 = false ;
unsigned int V_183 = 0 , V_184 = 0 , V_185 = 32 , V_108 = 0 ;
bool V_186 = false , V_187 = false , V_188 = false ;
bool V_30 = false , V_21 = false , V_189 = false ;
int V_190 ;
enum V_191 V_192 = V_193 ;
#ifdef F_81
if ( ! V_177 )
V_177 = V_194 ;
#endif
if ( ! V_177 ) {
V_2 -> V_195 = false ;
return false ;
}
V_105 = V_177 ;
V_179 = strlen ( V_105 ) ;
for ( V_190 = V_179 - 1 ; V_190 >= 0 ; V_190 -- ) {
switch ( V_105 [ V_190 ] ) {
case '@' :
if ( ! V_182 && ! V_181 &&
! V_186 && ! V_187 && ! V_188 && V_189 ) {
V_108 = F_82 ( & V_105 [ V_190 + 1 ] , NULL , 10 ) ;
V_182 = true ;
V_189 = false ;
} else
goto V_196;
break;
case '-' :
if ( ! V_181 && ! V_186 && ! V_187 &&
! V_188 && V_189 ) {
V_185 = F_82 ( & V_105 [ V_190 + 1 ] , NULL , 10 ) ;
V_181 = true ;
V_189 = false ;
} else
goto V_196;
break;
case 'x' :
if ( ! V_186 && V_189 ) {
V_184 = F_82 ( & V_105 [ V_190 + 1 ] , NULL , 10 ) ;
V_186 = true ;
V_189 = false ;
} else
goto V_196;
break;
case '0' ... '9' :
V_189 = true ;
break;
case 'M' :
if ( V_186 || V_187 || V_189 )
goto V_196;
V_187 = true ;
break;
case 'R' :
if ( V_186 || V_187 || V_188 || V_189 )
goto V_196;
V_188 = true ;
break;
case 'm' :
if ( V_187 || V_186 || V_189 )
goto V_196;
V_21 = true ;
break;
case 'i' :
if ( V_187 || V_186 || V_189 )
goto V_196;
V_30 = true ;
break;
case 'e' :
if ( V_186 || V_181 || V_182 ||
V_189 || ( V_192 != V_193 ) )
goto V_196;
V_192 = V_197 ;
break;
case 'D' :
if ( V_186 || V_181 || V_182 ||
V_189 || ( V_192 != V_193 ) )
goto V_196;
if ( ( V_11 -> V_198 != V_199 ) &&
( V_11 -> V_198 != V_200 ) )
V_192 = V_197 ;
else
V_192 = V_201 ;
break;
case 'd' :
if ( V_186 || V_181 || V_182 ||
V_189 || ( V_192 != V_193 ) )
goto V_196;
V_192 = V_202 ;
break;
default:
goto V_196;
}
}
if ( V_190 < 0 && V_186 ) {
char * V_203 ;
V_183 = F_82 ( V_105 , & V_203 , 10 ) ;
if ( ( V_203 != NULL ) && ( * V_203 == 'x' ) )
V_180 = true ;
else
V_190 = V_203 - V_105 ;
} else if ( ! V_186 && V_189 ) {
V_190 = 0 ;
}
V_196:
if ( V_190 >= 0 ) {
F_83 ( L_8 ,
V_190 , V_105 ) ;
V_2 -> V_195 = false ;
return false ;
}
if ( V_180 ) {
V_2 -> V_195 = true ;
V_2 -> V_183 = V_183 ;
V_2 -> V_184 = V_184 ;
}
if ( V_182 ) {
V_2 -> V_182 = true ;
V_2 -> V_108 = V_108 ;
}
if ( V_181 ) {
V_2 -> V_181 = true ;
V_2 -> V_185 = V_185 ;
}
V_2 -> V_188 = V_188 ;
V_2 -> V_187 = V_187 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_192 = V_192 ;
return true ;
}
struct V_1 *
F_84 ( struct V_4 * V_5 ,
struct V_178 * V_204 )
{
struct V_1 * V_2 ;
if ( V_204 -> V_187 )
V_2 = F_14 ( V_5 ,
V_204 -> V_183 , V_204 -> V_184 ,
V_204 -> V_182 ? V_204 -> V_108 : 60 ,
V_204 -> V_188 , V_204 -> V_30 ,
V_204 -> V_21 ) ;
else
V_2 = F_44 ( V_5 ,
V_204 -> V_183 , V_204 -> V_184 ,
V_204 -> V_182 ? V_204 -> V_108 : 60 ,
V_204 -> V_30 ,
V_204 -> V_21 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type |= V_205 ;
if ( V_204 -> V_183 == 1366 )
F_85 ( V_2 ) ;
F_54 ( V_2 , V_127 ) ;
return V_2 ;
}
void F_86 ( struct V_206 * V_207 ,
const struct V_1 * V_208 )
{
F_87 ( V_208 -> V_16 > V_209 || V_208 -> V_41 > V_209 ||
V_208 -> V_40 > V_209 || V_208 -> V_39 > V_209 ||
V_208 -> V_123 > V_209 || V_208 -> V_17 > V_209 ||
V_208 -> V_42 > V_209 || V_208 -> V_43 > V_209 ||
V_208 -> V_38 > V_209 || V_208 -> V_109 > V_209 ,
L_9 ) ;
V_207 -> clock = V_208 -> clock ;
V_207 -> V_16 = V_208 -> V_16 ;
V_207 -> V_41 = V_208 -> V_41 ;
V_207 -> V_40 = V_208 -> V_40 ;
V_207 -> V_39 = V_208 -> V_39 ;
V_207 -> V_123 = V_208 -> V_123 ;
V_207 -> V_17 = V_208 -> V_17 ;
V_207 -> V_42 = V_208 -> V_42 ;
V_207 -> V_43 = V_208 -> V_43 ;
V_207 -> V_38 = V_208 -> V_38 ;
V_207 -> V_109 = V_208 -> V_109 ;
V_207 -> V_18 = V_208 -> V_18 ;
V_207 -> V_45 = V_208 -> V_45 ;
V_207 -> type = V_208 -> type ;
strncpy ( V_207 -> V_105 , V_208 -> V_105 , V_106 ) ;
V_207 -> V_105 [ V_106 - 1 ] = 0 ;
}
int F_88 ( struct V_1 * V_207 ,
const struct V_206 * V_208 )
{
int V_104 = - V_210 ;
if ( V_208 -> clock > V_211 || V_208 -> V_18 > V_211 ) {
V_104 = - V_212 ;
goto V_207;
}
if ( ( V_208 -> V_45 & V_132 ) > V_213 )
goto V_207;
V_207 -> clock = V_208 -> clock ;
V_207 -> V_16 = V_208 -> V_16 ;
V_207 -> V_41 = V_208 -> V_41 ;
V_207 -> V_40 = V_208 -> V_40 ;
V_207 -> V_39 = V_208 -> V_39 ;
V_207 -> V_123 = V_208 -> V_123 ;
V_207 -> V_17 = V_208 -> V_17 ;
V_207 -> V_42 = V_208 -> V_42 ;
V_207 -> V_43 = V_208 -> V_43 ;
V_207 -> V_38 = V_208 -> V_38 ;
V_207 -> V_109 = V_208 -> V_109 ;
V_207 -> V_18 = V_208 -> V_18 ;
V_207 -> V_45 = V_208 -> V_45 ;
V_207 -> type = V_208 -> type ;
strncpy ( V_207 -> V_105 , V_208 -> V_105 , V_106 ) ;
V_207 -> V_105 [ V_106 - 1 ] = 0 ;
V_207 -> V_154 = F_63 ( V_207 ) ;
if ( V_207 -> V_154 != V_148 )
goto V_207;
F_54 ( V_207 , V_127 ) ;
V_104 = 0 ;
V_207:
return V_104 ;
}
bool F_89 ( const struct V_214 * V_215 ,
const struct V_1 * V_2 )
{
T_3 V_153 = F_66 ( V_2 ) ;
return F_67 ( V_153 , V_215 -> V_156 . V_158 ) ;
}
bool F_90 ( const struct V_214 * V_215 ,
const struct V_1 * V_2 )
{
T_3 V_153 = F_66 ( V_2 ) ;
return F_67 ( V_153 , V_215 -> V_156 . V_216 ) ;
}
bool F_91 ( const struct V_214 * V_215 ,
const struct V_1 * V_2 )
{
return F_89 ( V_215 , V_2 ) ||
F_90 ( V_215 , V_2 ) ;
}
