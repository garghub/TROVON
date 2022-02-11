void F_1 ( const struct V_1 * V_2 )
{
F_2 ( L_1
L_2 ,
V_2 -> V_3 . V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> clock ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_10 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_2 -> V_13 , V_2 -> V_14 , V_2 -> type , V_2 -> V_15 ) ;
}
struct V_1 * F_3 ( struct V_16 * V_17 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_18 )
return NULL ;
if ( F_5 ( V_17 , & V_18 -> V_3 , V_20 ) ) {
F_6 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
void F_7 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_8 ( V_17 , & V_2 -> V_3 ) ;
F_6 ( V_2 ) ;
}
void F_9 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
F_10 ( ! F_11 ( & V_22 -> V_17 -> V_23 . V_24 ) ) ;
F_12 ( & V_2 -> V_25 , & V_22 -> V_26 ) ;
}
struct V_1 * F_13 ( struct V_16 * V_17 , int V_7 ,
int V_11 , int V_6 ,
bool V_27 , bool V_28 , bool V_29 )
{
#define F_14 1000
#define F_15 18
#define F_16 8
#define F_17 3
#define F_18 6
#define F_19 250
struct V_1 * V_30 ;
unsigned int V_31 , V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 ;
int V_38 ;
V_30 = F_3 ( V_17 ) ;
if ( ! V_30 )
return NULL ;
if ( ! V_6 )
V_6 = 60 ;
if ( V_28 )
V_31 = V_6 * 2 ;
else
V_31 = V_6 ;
V_33 = V_7 - ( V_7 % F_16 ) ;
V_34 = 0 ;
if ( V_29 ) {
V_34 = V_33 * F_15 / 1000 ;
V_34 -= V_34 % F_16 ;
}
V_30 -> V_7 = V_33 + 2 * V_34 ;
if ( V_28 )
V_35 = V_11 / 2 ;
else
V_35 = V_11 ;
V_36 = 0 ;
if ( V_29 )
V_36 = V_35 * F_15 / 1000 ;
V_30 -> V_11 = V_11 + 2 * V_36 ;
if ( V_28 )
V_38 = 1 ;
else
V_38 = 0 ;
if ( ! ( V_11 % 3 ) && ( ( V_11 * 4 / 3 ) == V_7 ) )
V_37 = 4 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 16 / 9 ) == V_7 ) )
V_37 = 5 ;
else if ( ! ( V_11 % 10 ) && ( ( V_11 * 16 / 10 ) == V_7 ) )
V_37 = 6 ;
else if ( ! ( V_11 % 4 ) && ( ( V_11 * 5 / 4 ) == V_7 ) )
V_37 = 7 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 15 / 9 ) == V_7 ) )
V_37 = 7 ;
else
V_37 = 10 ;
if ( ! V_27 ) {
int V_39 , V_40 ;
#define F_20 550
#define F_21 8
unsigned int V_41 ;
int V_42 , V_43 , V_44 ;
V_39 = F_14 * 1000000 -
F_20 * F_14 * V_31 ;
V_40 = ( V_35 + 2 * V_36 + F_17 ) * 2 +
V_38 ;
V_32 = V_39 * 2 / ( V_40 * V_31 ) ;
V_39 = F_20 * F_14 / V_32 + 1 ;
if ( V_39 < ( V_37 + F_17 ) )
V_42 = V_37 + F_17 ;
else
V_42 = V_39 ;
V_43 = V_42 - V_37 ;
V_30 -> V_14 = V_35 + 2 * V_36 +
V_42 + F_17 ;
#define F_22 600
#define F_23 40
#define F_24 128
#define F_25 20
#define F_26 (CVT_M_FACTOR * CVT_K_FACTOR / 256)
#define F_27 ((CVT_C_FACTOR - CVT_J_FACTOR) * CVT_K_FACTOR / 256 + \
CVT_J_FACTOR)
V_41 = F_27 * F_14 - F_26 *
V_32 / 1000 ;
if ( V_41 < 20 * F_14 )
V_41 = 20 * F_14 ;
V_44 = V_30 -> V_7 * V_41 /
( 100 * F_14 - V_41 ) ;
V_44 -= V_44 % ( 2 * F_16 ) ;
V_30 -> V_10 = V_30 -> V_7 + V_44 ;
V_30 -> V_9 = V_30 -> V_7 + V_44 / 2 ;
V_30 -> V_8 = V_30 -> V_9 -
( V_30 -> V_10 * F_21 ) / 100 ;
V_30 -> V_8 += F_16 -
V_30 -> V_8 % F_16 ;
V_30 -> V_12 = V_30 -> V_11 + F_17 ;
V_30 -> V_13 = V_30 -> V_12 + V_37 ;
} else {
#define F_28 460
#define F_29 32
#define F_30 160
#define F_31 3
int V_45 ;
int V_39 , V_40 ;
V_39 = F_14 * 1000000 -
F_28 * F_14 * V_31 ;
V_40 = V_35 + 2 * V_36 ;
V_32 = V_39 / ( V_40 * V_31 ) ;
V_45 = F_28 * F_14 / V_32 + 1 ;
if ( V_45 < ( F_31 + V_37 + F_18 ) )
V_45 = F_31 + V_37 + F_18 ;
V_30 -> V_14 = V_35 + 2 * V_36 + V_45 ;
V_30 -> V_10 = V_30 -> V_7 + F_30 ;
V_30 -> V_9 = V_30 -> V_7 + F_30 / 2 ;
V_30 -> V_8 = V_30 -> V_9 - F_29 ;
V_30 -> V_12 = V_30 -> V_11 + F_31 ;
V_30 -> V_13 = V_30 -> V_12 + V_37 ;
}
V_30 -> clock = V_30 -> V_10 * F_14 * 1000 / V_32 ;
V_30 -> clock -= V_30 -> clock % F_19 ;
if ( V_28 ) {
V_30 -> V_14 *= 2 ;
V_30 -> V_15 |= V_46 ;
}
F_32 ( V_30 ) ;
if ( V_27 )
V_30 -> V_15 |= ( V_47 |
V_48 ) ;
else
V_30 -> V_15 |= ( V_49 |
V_50 ) ;
return V_30 ;
}
struct V_1 *
F_33 ( struct V_16 * V_17 , int V_7 , int V_11 ,
int V_6 , bool V_28 , int V_29 ,
int V_51 , int V_52 , int V_53 , int V_54 )
{
#define F_34 18
#define F_35 8
#define F_36 1
#define F_37 3
#define F_38 8
#define F_39 550
#define F_40 ((((GTF_2C - GTF_2J) * GTF_K / 256) + GTF_2J) / 2)
#define F_41 (GTF_K * GTF_M / 256)
struct V_1 * V_30 ;
unsigned int V_33 , V_35 , V_55 ;
int V_56 , V_57 ;
int V_38 ;
unsigned int V_58 ;
int V_59 , V_43 ;
unsigned int V_60 , V_61 , V_32 ;
unsigned int V_62 , V_63 ;
int V_64 , V_65 ;
unsigned int V_66 , V_67 ;
unsigned int V_44 , V_68 , V_69 ;
int V_70 , V_71 , V_72 ;
unsigned int V_39 , V_40 ;
V_30 = F_3 ( V_17 ) ;
if ( ! V_30 )
return NULL ;
V_33 = ( V_7 + F_35 / 2 ) / F_35 ;
V_33 = V_33 * F_35 ;
if ( V_28 )
V_35 = V_11 / 2 ;
else
V_35 = V_11 ;
if ( V_28 )
V_55 = V_6 * 2 ;
else
V_55 = V_6 ;
V_56 = 0 ;
if ( V_29 )
V_56 = ( V_35 * F_34 + 500 ) /
1000 ;
V_57 = V_56 ;
if ( V_28 )
V_38 = 1 ;
else
V_38 = 0 ;
{
V_39 = ( 1000000 - F_39 * V_55 ) / 500 ;
V_40 = ( V_35 + 2 * V_56 + F_36 ) *
2 + V_38 ;
V_58 = ( V_40 * 1000 * V_55 ) / V_39 ;
}
V_59 = F_39 * V_58 / 1000 ;
V_59 = ( V_59 + 500 ) / 1000 ;
V_43 = V_59 - F_37 ;
V_60 = V_35 + V_56 + V_57 +
V_59 + F_36 ;
V_61 = V_58 / V_60 ;
V_32 = 1000000 / ( V_55 * V_60 ) ;
V_62 = V_58 / V_60 ;
if ( V_28 )
V_63 = V_62 / 2 ;
else
V_63 = V_62 ;
if ( V_29 )
V_64 = ( V_33 * F_34 + 500 ) /
1000 ;
else
V_64 = 0 ;
V_65 = V_64 ;
V_66 = V_33 + V_64 + V_65 ;
V_67 = F_40 * 1000 -
( F_41 * 1000000 / V_58 ) ;
V_44 = V_66 * V_67 /
( 100000 - V_67 ) ;
V_44 = ( V_44 + F_35 ) / ( 2 * F_35 ) ;
V_44 = V_44 * 2 * F_35 ;
V_68 = V_66 + V_44 ;
V_69 = V_68 * V_58 / 1000 ;
V_70 = F_38 * V_68 / 100 ;
V_70 = ( V_70 + F_35 / 2 ) / F_35 ;
V_70 = V_70 * F_35 ;
V_71 = V_44 / 2 - V_70 ;
V_72 = F_36 ;
V_30 -> V_7 = V_33 ;
V_30 -> V_8 = V_33 + V_71 ;
V_30 -> V_9 = V_30 -> V_8 + V_70 ;
V_30 -> V_10 = V_68 ;
V_30 -> V_11 = V_35 ;
V_30 -> V_12 = V_35 + V_72 ;
V_30 -> V_13 = V_30 -> V_12 + F_37 ;
V_30 -> V_14 = V_60 ;
V_30 -> clock = V_69 ;
if ( V_28 ) {
V_30 -> V_14 *= 2 ;
V_30 -> V_15 |= V_46 ;
}
F_32 ( V_30 ) ;
if ( V_51 == 600 && V_52 == 80 && V_53 == 128 && V_54 == 40 )
V_30 -> V_15 = V_50 | V_49 ;
else
V_30 -> V_15 = V_47 | V_48 ;
return V_30 ;
}
struct V_1 *
F_42 ( struct V_16 * V_17 , int V_7 , int V_11 , int V_6 ,
bool V_28 , int V_29 )
{
return F_33 ( V_17 , V_7 , V_11 , V_6 ,
V_28 , V_29 ,
600 , 40 * 2 , 128 , 20 * 2 ) ;
}
void F_43 ( const struct V_73 * V_74 ,
struct V_1 * V_75 )
{
V_75 -> V_7 = V_74 -> V_76 ;
V_75 -> V_8 = V_75 -> V_7 + V_74 -> V_71 ;
V_75 -> V_9 = V_75 -> V_8 + V_74 -> V_77 ;
V_75 -> V_10 = V_75 -> V_9 + V_74 -> V_78 ;
V_75 -> V_11 = V_74 -> V_79 ;
V_75 -> V_12 = V_75 -> V_11 + V_74 -> V_80 ;
V_75 -> V_13 = V_75 -> V_12 + V_74 -> V_81 ;
V_75 -> V_14 = V_75 -> V_13 + V_74 -> V_43 ;
V_75 -> clock = V_74 -> V_82 / 1000 ;
V_75 -> V_15 = 0 ;
if ( V_74 -> V_15 & V_83 )
V_75 -> V_15 |= V_47 ;
else if ( V_74 -> V_15 & V_84 )
V_75 -> V_15 |= V_50 ;
if ( V_74 -> V_15 & V_85 )
V_75 -> V_15 |= V_49 ;
else if ( V_74 -> V_15 & V_86 )
V_75 -> V_15 |= V_48 ;
if ( V_74 -> V_15 & V_87 )
V_75 -> V_15 |= V_46 ;
if ( V_74 -> V_15 & V_88 )
V_75 -> V_15 |= V_89 ;
if ( V_74 -> V_15 & V_90 )
V_75 -> V_15 |= V_91 ;
F_32 ( V_75 ) ;
}
void F_44 ( const struct V_1 * V_75 ,
struct V_73 * V_74 )
{
V_74 -> V_76 = V_75 -> V_7 ;
V_74 -> V_71 = V_75 -> V_8 - V_75 -> V_7 ;
V_74 -> V_77 = V_75 -> V_9 - V_75 -> V_8 ;
V_74 -> V_78 = V_75 -> V_10 - V_75 -> V_9 ;
V_74 -> V_79 = V_75 -> V_11 ;
V_74 -> V_80 = V_75 -> V_12 - V_75 -> V_11 ;
V_74 -> V_81 = V_75 -> V_13 - V_75 -> V_12 ;
V_74 -> V_43 = V_75 -> V_14 - V_75 -> V_13 ;
V_74 -> V_82 = V_75 -> clock * 1000 ;
V_74 -> V_15 = 0 ;
if ( V_75 -> V_15 & V_47 )
V_74 -> V_15 |= V_83 ;
else if ( V_75 -> V_15 & V_50 )
V_74 -> V_15 |= V_84 ;
if ( V_75 -> V_15 & V_49 )
V_74 -> V_15 |= V_85 ;
else if ( V_75 -> V_15 & V_48 )
V_74 -> V_15 |= V_86 ;
if ( V_75 -> V_15 & V_46 )
V_74 -> V_15 |= V_87 ;
if ( V_75 -> V_15 & V_89 )
V_74 -> V_15 |= V_88 ;
if ( V_75 -> V_15 & V_91 )
V_74 -> V_15 |= V_90 ;
}
void F_45 ( const struct V_73 * V_74 , T_1 * V_92 )
{
* V_92 = 0 ;
if ( V_74 -> V_15 & V_93 )
* V_92 |= V_94 ;
if ( V_74 -> V_15 & V_95 )
* V_92 |= V_96 ;
if ( V_74 -> V_15 & V_97 )
* V_92 |= V_98 ;
if ( V_74 -> V_15 & V_99 )
* V_92 |= V_100 ;
}
int F_46 ( struct V_101 * V_102 ,
struct V_1 * V_75 , T_1 * V_92 ,
int V_103 )
{
struct V_73 V_74 ;
int V_104 ;
V_104 = F_47 ( V_102 , & V_74 , V_103 ) ;
if ( V_104 )
return V_104 ;
F_43 ( & V_74 , V_75 ) ;
if ( V_92 )
F_45 ( & V_74 , V_92 ) ;
F_48 ( L_3 ,
F_49 ( V_102 ) , V_74 . V_76 , V_74 . V_79 , V_102 -> V_5 ) ;
F_1 ( V_75 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
bool V_28 = ! ! ( V_2 -> V_15 & V_46 ) ;
snprintf ( V_2 -> V_5 , V_105 , L_4 ,
V_2 -> V_7 , V_2 -> V_11 ,
V_28 ? L_5 : L_6 ) ;
}
int F_50 ( const struct V_1 * V_2 )
{
unsigned int V_106 ;
if ( V_2 -> V_70 )
return V_2 -> V_70 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_106 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_106 += 500 ;
V_106 /= 1000 ;
return V_106 ;
}
int F_51 ( const struct V_1 * V_2 )
{
int V_107 = 0 ;
unsigned int V_106 ;
if ( V_2 -> V_6 > 0 )
V_107 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_106 = ( V_2 -> clock * 1000 ) ;
V_106 /= V_2 -> V_10 ;
V_107 = ( V_106 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_46 )
V_107 *= 2 ;
if ( V_2 -> V_15 & V_89 )
V_107 /= 2 ;
if ( V_2 -> V_108 > 1 )
V_107 /= V_2 -> V_108 ;
}
return V_107 ;
}
void F_52 ( struct V_1 * V_109 , int V_110 )
{
if ( ( V_109 == NULL ) || ( ( V_109 -> type & V_111 ) == V_112 ) )
return;
V_109 -> V_113 = V_109 -> clock ;
V_109 -> V_114 = V_109 -> V_7 ;
V_109 -> V_115 = V_109 -> V_8 ;
V_109 -> V_116 = V_109 -> V_9 ;
V_109 -> V_117 = V_109 -> V_10 ;
V_109 -> V_118 = V_109 -> V_119 ;
V_109 -> V_120 = V_109 -> V_11 ;
V_109 -> V_121 = V_109 -> V_12 ;
V_109 -> V_122 = V_109 -> V_13 ;
V_109 -> V_123 = V_109 -> V_14 ;
if ( V_109 -> V_15 & V_46 ) {
if ( V_110 & V_124 ) {
V_109 -> V_120 /= 2 ;
V_109 -> V_121 /= 2 ;
V_109 -> V_122 /= 2 ;
V_109 -> V_123 /= 2 ;
}
}
if ( ! ( V_110 & V_125 ) ) {
if ( V_109 -> V_15 & V_89 ) {
V_109 -> V_120 *= 2 ;
V_109 -> V_121 *= 2 ;
V_109 -> V_122 *= 2 ;
V_109 -> V_123 *= 2 ;
}
}
if ( ! ( V_110 & V_126 ) ) {
if ( V_109 -> V_108 > 1 ) {
V_109 -> V_120 *= V_109 -> V_108 ;
V_109 -> V_121 *= V_109 -> V_108 ;
V_109 -> V_122 *= V_109 -> V_108 ;
V_109 -> V_123 *= V_109 -> V_108 ;
}
}
if ( V_110 & V_127 ) {
unsigned int V_128 = V_109 -> V_15 & V_129 ;
switch ( V_128 ) {
case V_130 :
V_109 -> V_113 *= 2 ;
V_109 -> V_120 += V_109 -> V_123 ;
V_109 -> V_121 += V_109 -> V_123 ;
V_109 -> V_122 += V_109 -> V_123 ;
V_109 -> V_123 += V_109 -> V_123 ;
break;
}
}
V_109 -> V_131 = F_53 ( V_109 -> V_121 , V_109 -> V_120 ) ;
V_109 -> V_132 = F_54 ( V_109 -> V_122 , V_109 -> V_123 ) ;
V_109 -> V_133 = F_53 ( V_109 -> V_115 , V_109 -> V_114 ) ;
V_109 -> V_134 = F_54 ( V_109 -> V_116 , V_109 -> V_117 ) ;
}
void F_55 ( struct V_1 * V_135 , const struct V_1 * V_136 )
{
int V_4 = V_135 -> V_3 . V_4 ;
struct V_137 V_25 = V_135 -> V_25 ;
* V_135 = * V_136 ;
V_135 -> V_3 . V_4 = V_4 ;
V_135 -> V_25 = V_25 ;
}
struct V_1 * F_56 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_3 ( V_17 ) ;
if ( ! V_18 )
return NULL ;
F_55 ( V_18 , V_2 ) ;
return V_18 ;
}
bool F_57 ( const struct V_1 * V_138 , const struct V_1 * V_139 )
{
if ( ! V_138 && ! V_139 )
return true ;
if ( ! V_138 || ! V_139 )
return false ;
if ( V_138 -> clock && V_139 -> clock ) {
if ( F_58 ( V_138 -> clock ) != F_58 ( V_139 -> clock ) )
return false ;
} else if ( V_138 -> clock != V_139 -> clock )
return false ;
return F_59 ( V_138 , V_139 ) ;
}
bool F_59 ( const struct V_1 * V_138 , const struct V_1 * V_139 )
{
if ( ( V_138 -> V_15 & V_129 ) !=
( V_139 -> V_15 & V_129 ) )
return false ;
return F_60 ( V_138 , V_139 ) ;
}
bool F_60 ( const struct V_1 * V_138 ,
const struct V_1 * V_139 )
{
if ( V_138 -> V_7 == V_139 -> V_7 &&
V_138 -> V_8 == V_139 -> V_8 &&
V_138 -> V_9 == V_139 -> V_9 &&
V_138 -> V_10 == V_139 -> V_10 &&
V_138 -> V_119 == V_139 -> V_119 &&
V_138 -> V_11 == V_139 -> V_11 &&
V_138 -> V_12 == V_139 -> V_12 &&
V_138 -> V_13 == V_139 -> V_13 &&
V_138 -> V_14 == V_139 -> V_14 &&
V_138 -> V_108 == V_139 -> V_108 &&
( V_138 -> V_15 & ~ V_129 ) ==
( V_139 -> V_15 & ~ V_129 ) )
return true ;
return false ;
}
enum V_140
F_61 ( const struct V_1 * V_2 )
{
if ( V_2 -> clock == 0 )
return V_141 ;
if ( V_2 -> V_7 == 0 ||
V_2 -> V_8 < V_2 -> V_7 ||
V_2 -> V_9 < V_2 -> V_8 ||
V_2 -> V_10 < V_2 -> V_9 )
return V_142 ;
if ( V_2 -> V_11 == 0 ||
V_2 -> V_12 < V_2 -> V_11 ||
V_2 -> V_13 < V_2 -> V_12 ||
V_2 -> V_14 < V_2 -> V_13 )
return V_143 ;
return V_144 ;
}
enum V_140
F_62 ( const struct V_1 * V_2 ,
int V_145 , int V_146 )
{
if ( V_145 > 0 && V_2 -> V_7 > V_145 )
return V_147 ;
if ( V_146 > 0 && V_2 -> V_11 > V_146 )
return V_148 ;
return V_144 ;
}
static const char * F_63 ( enum V_140 V_149 )
{
int V_103 = V_149 + 3 ;
if ( F_10 ( V_103 < 0 || V_103 >= F_64 ( V_150 ) ) )
return L_6 ;
return V_150 [ V_103 ] ;
}
void F_65 ( struct V_16 * V_17 ,
struct V_137 * V_151 , bool V_152 )
{
struct V_1 * V_2 , * V_153 ;
F_66 (mode, t, mode_list, head) {
if ( V_2 -> V_149 != V_144 ) {
F_67 ( & V_2 -> V_25 ) ;
if ( V_152 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_5 ,
F_63 ( V_2 -> V_149 ) ) ;
}
F_7 ( V_17 , V_2 ) ;
}
}
}
static int F_68 ( void * V_154 , struct V_137 * V_155 , struct V_137 * V_156 )
{
struct V_1 * V_157 = F_69 ( V_155 , struct V_1 , V_25 ) ;
struct V_1 * V_158 = F_69 ( V_156 , struct V_1 , V_25 ) ;
int V_159 ;
V_159 = ( ( V_158 -> type & V_160 ) != 0 ) -
( ( V_157 -> type & V_160 ) != 0 ) ;
if ( V_159 )
return V_159 ;
V_159 = V_158 -> V_7 * V_158 -> V_11 - V_157 -> V_7 * V_157 -> V_11 ;
if ( V_159 )
return V_159 ;
V_159 = V_158 -> V_6 - V_157 -> V_6 ;
if ( V_159 )
return V_159 ;
V_159 = V_158 -> clock - V_157 -> clock ;
return V_159 ;
}
void F_70 ( struct V_137 * V_151 )
{
F_71 ( NULL , V_151 , F_68 ) ;
}
void F_72 ( struct V_21 * V_22 )
{
struct V_1 * V_161 , * V_162 ;
F_10 ( ! F_11 ( & V_22 -> V_17 -> V_23 . V_24 ) ) ;
F_66 (pmode, pt, &connector->probed_modes, head) {
struct V_1 * V_2 ;
bool V_163 = false ;
F_73 (mode, &connector->modes, head) {
if ( ! F_57 ( V_161 , V_2 ) )
continue;
V_163 = true ;
if ( V_2 -> V_149 == V_164 ) {
F_55 ( V_2 , V_161 ) ;
} else if ( ( V_2 -> type & V_160 ) == 0 &&
( V_161 -> type & V_160 ) != 0 ) {
V_161 -> type |= V_2 -> type ;
F_55 ( V_2 , V_161 ) ;
} else {
V_2 -> type |= V_161 -> type ;
}
F_67 ( & V_161 -> V_25 ) ;
F_7 ( V_22 -> V_17 , V_161 ) ;
break;
}
if ( ! V_163 ) {
F_74 ( & V_161 -> V_25 , & V_22 -> V_165 ) ;
}
}
}
bool F_75 ( const char * V_166 ,
struct V_21 * V_22 ,
struct V_167 * V_2 )
{
const char * V_5 ;
unsigned int V_168 ;
bool V_169 = false , V_170 = false , V_171 = false ;
unsigned int V_172 = 0 , V_173 = 0 , V_174 = 32 , V_107 = 0 ;
bool V_175 = false , V_176 = false , V_177 = false ;
bool V_38 = false , V_29 = false , V_178 = false ;
int V_179 ;
enum V_180 V_181 = V_182 ;
#ifdef F_76
if ( ! V_166 )
V_166 = V_183 ;
#endif
if ( ! V_166 ) {
V_2 -> V_184 = false ;
return false ;
}
V_5 = V_166 ;
V_168 = strlen ( V_5 ) ;
for ( V_179 = V_168 - 1 ; V_179 >= 0 ; V_179 -- ) {
switch ( V_5 [ V_179 ] ) {
case '@' :
if ( ! V_171 && ! V_170 &&
! V_175 && ! V_176 && ! V_177 && V_178 ) {
V_107 = F_77 ( & V_5 [ V_179 + 1 ] , NULL , 10 ) ;
V_171 = true ;
V_178 = false ;
} else
goto V_185;
break;
case '-' :
if ( ! V_170 && ! V_175 && ! V_176 &&
! V_177 && V_178 ) {
V_174 = F_77 ( & V_5 [ V_179 + 1 ] , NULL , 10 ) ;
V_170 = true ;
V_178 = false ;
} else
goto V_185;
break;
case 'x' :
if ( ! V_175 && V_178 ) {
V_173 = F_77 ( & V_5 [ V_179 + 1 ] , NULL , 10 ) ;
V_175 = true ;
V_178 = false ;
} else
goto V_185;
break;
case '0' ... '9' :
V_178 = true ;
break;
case 'M' :
if ( V_175 || V_176 || V_178 )
goto V_185;
V_176 = true ;
break;
case 'R' :
if ( V_175 || V_176 || V_177 || V_178 )
goto V_185;
V_177 = true ;
break;
case 'm' :
if ( V_176 || V_175 || V_178 )
goto V_185;
V_29 = true ;
break;
case 'i' :
if ( V_176 || V_175 || V_178 )
goto V_185;
V_38 = true ;
break;
case 'e' :
if ( V_175 || V_170 || V_171 ||
V_178 || ( V_181 != V_182 ) )
goto V_185;
V_181 = V_186 ;
break;
case 'D' :
if ( V_175 || V_170 || V_171 ||
V_178 || ( V_181 != V_182 ) )
goto V_185;
if ( ( V_22 -> V_187 != V_188 ) &&
( V_22 -> V_187 != V_189 ) )
V_181 = V_186 ;
else
V_181 = V_190 ;
break;
case 'd' :
if ( V_175 || V_170 || V_171 ||
V_178 || ( V_181 != V_182 ) )
goto V_185;
V_181 = V_191 ;
break;
default:
goto V_185;
}
}
if ( V_179 < 0 && V_175 ) {
char * V_192 ;
V_172 = F_77 ( V_5 , & V_192 , 10 ) ;
if ( ( V_192 != NULL ) && ( * V_192 == 'x' ) )
V_169 = true ;
else
V_179 = V_192 - V_5 ;
} else if ( ! V_175 && V_178 ) {
V_179 = 0 ;
}
V_185:
if ( V_179 >= 0 ) {
F_78 ( L_8 ,
V_179 , V_5 ) ;
V_2 -> V_184 = false ;
return false ;
}
if ( V_169 ) {
V_2 -> V_184 = true ;
V_2 -> V_172 = V_172 ;
V_2 -> V_173 = V_173 ;
}
if ( V_171 ) {
V_2 -> V_171 = true ;
V_2 -> V_107 = V_107 ;
}
if ( V_170 ) {
V_2 -> V_170 = true ;
V_2 -> V_174 = V_174 ;
}
V_2 -> V_177 = V_177 ;
V_2 -> V_176 = V_176 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_181 = V_181 ;
return true ;
}
struct V_1 *
F_79 ( struct V_16 * V_17 ,
struct V_167 * V_193 )
{
struct V_1 * V_2 ;
if ( V_193 -> V_176 )
V_2 = F_13 ( V_17 ,
V_193 -> V_172 , V_193 -> V_173 ,
V_193 -> V_171 ? V_193 -> V_107 : 60 ,
V_193 -> V_177 , V_193 -> V_38 ,
V_193 -> V_29 ) ;
else
V_2 = F_42 ( V_17 ,
V_193 -> V_172 , V_193 -> V_173 ,
V_193 -> V_171 ? V_193 -> V_107 : 60 ,
V_193 -> V_38 ,
V_193 -> V_29 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type |= V_194 ;
F_52 ( V_2 , V_124 ) ;
return V_2 ;
}
void F_80 ( struct V_195 * V_196 ,
const struct V_1 * V_197 )
{
F_81 ( V_197 -> V_7 > V_198 || V_197 -> V_8 > V_198 ||
V_197 -> V_9 > V_198 || V_197 -> V_10 > V_198 ||
V_197 -> V_119 > V_198 || V_197 -> V_11 > V_198 ||
V_197 -> V_12 > V_198 || V_197 -> V_13 > V_198 ||
V_197 -> V_14 > V_198 || V_197 -> V_108 > V_198 ,
L_9 ) ;
V_196 -> clock = V_197 -> clock ;
V_196 -> V_7 = V_197 -> V_7 ;
V_196 -> V_8 = V_197 -> V_8 ;
V_196 -> V_9 = V_197 -> V_9 ;
V_196 -> V_10 = V_197 -> V_10 ;
V_196 -> V_119 = V_197 -> V_119 ;
V_196 -> V_11 = V_197 -> V_11 ;
V_196 -> V_12 = V_197 -> V_12 ;
V_196 -> V_13 = V_197 -> V_13 ;
V_196 -> V_14 = V_197 -> V_14 ;
V_196 -> V_108 = V_197 -> V_108 ;
V_196 -> V_6 = V_197 -> V_6 ;
V_196 -> V_15 = V_197 -> V_15 ;
V_196 -> type = V_197 -> type ;
strncpy ( V_196 -> V_5 , V_197 -> V_5 , V_105 ) ;
V_196 -> V_5 [ V_105 - 1 ] = 0 ;
}
int F_82 ( struct V_1 * V_196 ,
const struct V_195 * V_197 )
{
int V_104 = - V_199 ;
if ( V_197 -> clock > V_200 || V_197 -> V_6 > V_200 ) {
V_104 = - V_201 ;
goto V_196;
}
if ( ( V_197 -> V_15 & V_129 ) > V_202 )
goto V_196;
V_196 -> clock = V_197 -> clock ;
V_196 -> V_7 = V_197 -> V_7 ;
V_196 -> V_8 = V_197 -> V_8 ;
V_196 -> V_9 = V_197 -> V_9 ;
V_196 -> V_10 = V_197 -> V_10 ;
V_196 -> V_119 = V_197 -> V_119 ;
V_196 -> V_11 = V_197 -> V_11 ;
V_196 -> V_12 = V_197 -> V_12 ;
V_196 -> V_13 = V_197 -> V_13 ;
V_196 -> V_14 = V_197 -> V_14 ;
V_196 -> V_108 = V_197 -> V_108 ;
V_196 -> V_6 = V_197 -> V_6 ;
V_196 -> V_15 = V_197 -> V_15 ;
V_196 -> type = V_197 -> type ;
strncpy ( V_196 -> V_5 , V_197 -> V_5 , V_105 ) ;
V_196 -> V_5 [ V_105 - 1 ] = 0 ;
V_196 -> V_149 = F_61 ( V_196 ) ;
if ( V_196 -> V_149 != V_144 )
goto V_196;
F_52 ( V_196 , V_124 ) ;
V_104 = 0 ;
V_196:
return V_104 ;
}
