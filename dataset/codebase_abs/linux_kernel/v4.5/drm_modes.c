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
int F_45 ( struct V_92 * V_93 ,
struct V_1 * V_75 , int V_94 )
{
struct V_73 V_74 ;
int V_95 ;
V_95 = F_46 ( V_93 , & V_74 , V_94 ) ;
if ( V_95 )
return V_95 ;
F_43 ( & V_74 , V_75 ) ;
F_47 ( L_3 ,
F_48 ( V_93 ) , V_74 . V_76 , V_74 . V_79 , V_93 -> V_5 ) ;
F_1 ( V_75 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
bool V_28 = ! ! ( V_2 -> V_15 & V_46 ) ;
snprintf ( V_2 -> V_5 , V_96 , L_4 ,
V_2 -> V_7 , V_2 -> V_11 ,
V_28 ? L_5 : L_6 ) ;
}
int F_49 ( const struct V_1 * V_2 )
{
unsigned int V_97 ;
if ( V_2 -> V_70 )
return V_2 -> V_70 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_97 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_97 += 500 ;
V_97 /= 1000 ;
return V_97 ;
}
int F_50 ( const struct V_1 * V_2 )
{
int V_98 = 0 ;
unsigned int V_97 ;
if ( V_2 -> V_6 > 0 )
V_98 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_97 = ( V_2 -> clock * 1000 ) ;
V_97 /= V_2 -> V_10 ;
V_98 = ( V_97 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_46 )
V_98 *= 2 ;
if ( V_2 -> V_15 & V_89 )
V_98 /= 2 ;
if ( V_2 -> V_99 > 1 )
V_98 /= V_2 -> V_99 ;
}
return V_98 ;
}
void F_51 ( struct V_1 * V_100 , int V_101 )
{
if ( ( V_100 == NULL ) || ( ( V_100 -> type & V_102 ) == V_103 ) )
return;
V_100 -> V_104 = V_100 -> clock ;
V_100 -> V_105 = V_100 -> V_7 ;
V_100 -> V_106 = V_100 -> V_8 ;
V_100 -> V_107 = V_100 -> V_9 ;
V_100 -> V_108 = V_100 -> V_10 ;
V_100 -> V_109 = V_100 -> V_110 ;
V_100 -> V_111 = V_100 -> V_11 ;
V_100 -> V_112 = V_100 -> V_12 ;
V_100 -> V_113 = V_100 -> V_13 ;
V_100 -> V_114 = V_100 -> V_14 ;
if ( V_100 -> V_15 & V_46 ) {
if ( V_101 & V_115 ) {
V_100 -> V_111 /= 2 ;
V_100 -> V_112 /= 2 ;
V_100 -> V_113 /= 2 ;
V_100 -> V_114 /= 2 ;
}
}
if ( ! ( V_101 & V_116 ) ) {
if ( V_100 -> V_15 & V_89 ) {
V_100 -> V_111 *= 2 ;
V_100 -> V_112 *= 2 ;
V_100 -> V_113 *= 2 ;
V_100 -> V_114 *= 2 ;
}
}
if ( ! ( V_101 & V_117 ) ) {
if ( V_100 -> V_99 > 1 ) {
V_100 -> V_111 *= V_100 -> V_99 ;
V_100 -> V_112 *= V_100 -> V_99 ;
V_100 -> V_113 *= V_100 -> V_99 ;
V_100 -> V_114 *= V_100 -> V_99 ;
}
}
if ( V_101 & V_118 ) {
unsigned int V_119 = V_100 -> V_15 & V_120 ;
switch ( V_119 ) {
case V_121 :
V_100 -> V_104 *= 2 ;
V_100 -> V_111 += V_100 -> V_114 ;
V_100 -> V_112 += V_100 -> V_114 ;
V_100 -> V_113 += V_100 -> V_114 ;
V_100 -> V_114 += V_100 -> V_114 ;
break;
}
}
V_100 -> V_122 = F_52 ( V_100 -> V_112 , V_100 -> V_111 ) ;
V_100 -> V_123 = F_53 ( V_100 -> V_113 , V_100 -> V_114 ) ;
V_100 -> V_124 = F_52 ( V_100 -> V_106 , V_100 -> V_105 ) ;
V_100 -> V_125 = F_53 ( V_100 -> V_107 , V_100 -> V_108 ) ;
}
void F_54 ( struct V_1 * V_126 , const struct V_1 * V_127 )
{
int V_4 = V_126 -> V_3 . V_4 ;
struct V_128 V_25 = V_126 -> V_25 ;
* V_126 = * V_127 ;
V_126 -> V_3 . V_4 = V_4 ;
V_126 -> V_25 = V_25 ;
}
struct V_1 * F_55 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_3 ( V_17 ) ;
if ( ! V_18 )
return NULL ;
F_54 ( V_18 , V_2 ) ;
return V_18 ;
}
bool F_56 ( const struct V_1 * V_129 , const struct V_1 * V_130 )
{
if ( ! V_129 && ! V_130 )
return true ;
if ( ! V_129 || ! V_130 )
return false ;
if ( V_129 -> clock && V_130 -> clock ) {
if ( F_57 ( V_129 -> clock ) != F_57 ( V_130 -> clock ) )
return false ;
} else if ( V_129 -> clock != V_130 -> clock )
return false ;
return F_58 ( V_129 , V_130 ) ;
}
bool F_58 ( const struct V_1 * V_129 , const struct V_1 * V_130 )
{
if ( ( V_129 -> V_15 & V_120 ) !=
( V_130 -> V_15 & V_120 ) )
return false ;
return F_59 ( V_129 , V_130 ) ;
}
bool F_59 ( const struct V_1 * V_129 ,
const struct V_1 * V_130 )
{
if ( V_129 -> V_7 == V_130 -> V_7 &&
V_129 -> V_8 == V_130 -> V_8 &&
V_129 -> V_9 == V_130 -> V_9 &&
V_129 -> V_10 == V_130 -> V_10 &&
V_129 -> V_110 == V_130 -> V_110 &&
V_129 -> V_11 == V_130 -> V_11 &&
V_129 -> V_12 == V_130 -> V_12 &&
V_129 -> V_13 == V_130 -> V_13 &&
V_129 -> V_14 == V_130 -> V_14 &&
V_129 -> V_99 == V_130 -> V_99 &&
( V_129 -> V_15 & ~ V_120 ) ==
( V_130 -> V_15 & ~ V_120 ) )
return true ;
return false ;
}
enum V_131
F_60 ( const struct V_1 * V_2 )
{
if ( V_2 -> clock == 0 )
return V_132 ;
if ( V_2 -> V_7 == 0 ||
V_2 -> V_8 < V_2 -> V_7 ||
V_2 -> V_9 < V_2 -> V_8 ||
V_2 -> V_10 < V_2 -> V_9 )
return V_133 ;
if ( V_2 -> V_11 == 0 ||
V_2 -> V_12 < V_2 -> V_11 ||
V_2 -> V_13 < V_2 -> V_12 ||
V_2 -> V_14 < V_2 -> V_13 )
return V_134 ;
return V_135 ;
}
enum V_131
F_61 ( const struct V_1 * V_2 ,
int V_136 , int V_137 )
{
if ( V_136 > 0 && V_2 -> V_7 > V_136 )
return V_138 ;
if ( V_137 > 0 && V_2 -> V_11 > V_137 )
return V_139 ;
return V_135 ;
}
static const char * F_62 ( enum V_131 V_140 )
{
int V_94 = V_140 + 3 ;
if ( F_10 ( V_94 < 0 || V_94 >= F_63 ( V_141 ) ) )
return L_6 ;
return V_141 [ V_94 ] ;
}
void F_64 ( struct V_16 * V_17 ,
struct V_128 * V_142 , bool V_143 )
{
struct V_1 * V_2 , * V_144 ;
F_65 (mode, t, mode_list, head) {
if ( V_2 -> V_140 != V_135 ) {
F_66 ( & V_2 -> V_25 ) ;
if ( V_143 ) {
F_1 ( V_2 ) ;
F_2 ( L_7 ,
V_2 -> V_5 ,
F_62 ( V_2 -> V_140 ) ) ;
}
F_7 ( V_17 , V_2 ) ;
}
}
}
static int F_67 ( void * V_145 , struct V_128 * V_146 , struct V_128 * V_147 )
{
struct V_1 * V_148 = F_68 ( V_146 , struct V_1 , V_25 ) ;
struct V_1 * V_149 = F_68 ( V_147 , struct V_1 , V_25 ) ;
int V_150 ;
V_150 = ( ( V_149 -> type & V_151 ) != 0 ) -
( ( V_148 -> type & V_151 ) != 0 ) ;
if ( V_150 )
return V_150 ;
V_150 = V_149 -> V_7 * V_149 -> V_11 - V_148 -> V_7 * V_148 -> V_11 ;
if ( V_150 )
return V_150 ;
V_150 = V_149 -> V_6 - V_148 -> V_6 ;
if ( V_150 )
return V_150 ;
V_150 = V_149 -> clock - V_148 -> clock ;
return V_150 ;
}
void F_69 ( struct V_128 * V_142 )
{
F_70 ( NULL , V_142 , F_67 ) ;
}
void F_71 ( struct V_21 * V_22 )
{
struct V_1 * V_152 , * V_153 ;
F_10 ( ! F_11 ( & V_22 -> V_17 -> V_23 . V_24 ) ) ;
F_65 (pmode, pt, &connector->probed_modes, head) {
struct V_1 * V_2 ;
bool V_154 = false ;
F_72 (mode, &connector->modes, head) {
if ( ! F_56 ( V_152 , V_2 ) )
continue;
V_154 = true ;
if ( V_2 -> V_140 == V_155 ) {
F_54 ( V_2 , V_152 ) ;
} else if ( ( V_2 -> type & V_151 ) == 0 &&
( V_152 -> type & V_151 ) != 0 ) {
V_152 -> type |= V_2 -> type ;
F_54 ( V_2 , V_152 ) ;
} else {
V_2 -> type |= V_152 -> type ;
}
F_66 ( & V_152 -> V_25 ) ;
F_7 ( V_22 -> V_17 , V_152 ) ;
break;
}
if ( ! V_154 ) {
F_73 ( & V_152 -> V_25 , & V_22 -> V_156 ) ;
}
}
}
bool F_74 ( const char * V_157 ,
struct V_21 * V_22 ,
struct V_158 * V_2 )
{
const char * V_5 ;
unsigned int V_159 ;
bool V_160 = false , V_161 = false , V_162 = false ;
unsigned int V_163 = 0 , V_164 = 0 , V_165 = 32 , V_98 = 0 ;
bool V_166 = false , V_167 = false , V_168 = false ;
bool V_38 = false , V_29 = false , V_169 = false ;
int V_170 ;
enum V_171 V_172 = V_173 ;
#ifdef F_75
if ( ! V_157 )
V_157 = V_174 ;
#endif
if ( ! V_157 ) {
V_2 -> V_175 = false ;
return false ;
}
V_5 = V_157 ;
V_159 = strlen ( V_5 ) ;
for ( V_170 = V_159 - 1 ; V_170 >= 0 ; V_170 -- ) {
switch ( V_5 [ V_170 ] ) {
case '@' :
if ( ! V_162 && ! V_161 &&
! V_166 && ! V_167 && ! V_168 && V_169 ) {
V_98 = F_76 ( & V_5 [ V_170 + 1 ] , NULL , 10 ) ;
V_162 = true ;
V_169 = false ;
} else
goto V_176;
break;
case '-' :
if ( ! V_161 && ! V_166 && ! V_167 &&
! V_168 && V_169 ) {
V_165 = F_76 ( & V_5 [ V_170 + 1 ] , NULL , 10 ) ;
V_161 = true ;
V_169 = false ;
} else
goto V_176;
break;
case 'x' :
if ( ! V_166 && V_169 ) {
V_164 = F_76 ( & V_5 [ V_170 + 1 ] , NULL , 10 ) ;
V_166 = true ;
V_169 = false ;
} else
goto V_176;
break;
case '0' ... '9' :
V_169 = true ;
break;
case 'M' :
if ( V_166 || V_167 || V_169 )
goto V_176;
V_167 = true ;
break;
case 'R' :
if ( V_166 || V_167 || V_168 || V_169 )
goto V_176;
V_168 = true ;
break;
case 'm' :
if ( V_167 || V_166 || V_169 )
goto V_176;
V_29 = true ;
break;
case 'i' :
if ( V_167 || V_166 || V_169 )
goto V_176;
V_38 = true ;
break;
case 'e' :
if ( V_166 || V_161 || V_162 ||
V_169 || ( V_172 != V_173 ) )
goto V_176;
V_172 = V_177 ;
break;
case 'D' :
if ( V_166 || V_161 || V_162 ||
V_169 || ( V_172 != V_173 ) )
goto V_176;
if ( ( V_22 -> V_178 != V_179 ) &&
( V_22 -> V_178 != V_180 ) )
V_172 = V_177 ;
else
V_172 = V_181 ;
break;
case 'd' :
if ( V_166 || V_161 || V_162 ||
V_169 || ( V_172 != V_173 ) )
goto V_176;
V_172 = V_182 ;
break;
default:
goto V_176;
}
}
if ( V_170 < 0 && V_166 ) {
char * V_183 ;
V_163 = F_76 ( V_5 , & V_183 , 10 ) ;
if ( ( V_183 != NULL ) && ( * V_183 == 'x' ) )
V_160 = true ;
else
V_170 = V_183 - V_5 ;
} else if ( ! V_166 && V_169 ) {
V_170 = 0 ;
}
V_176:
if ( V_170 >= 0 ) {
F_77 ( V_184
L_8 ,
V_170 , V_5 ) ;
V_2 -> V_175 = false ;
return false ;
}
if ( V_160 ) {
V_2 -> V_175 = true ;
V_2 -> V_163 = V_163 ;
V_2 -> V_164 = V_164 ;
}
if ( V_162 ) {
V_2 -> V_162 = true ;
V_2 -> V_98 = V_98 ;
}
if ( V_161 ) {
V_2 -> V_161 = true ;
V_2 -> V_165 = V_165 ;
}
V_2 -> V_168 = V_168 ;
V_2 -> V_167 = V_167 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_172 = V_172 ;
return true ;
}
struct V_1 *
F_78 ( struct V_16 * V_17 ,
struct V_158 * V_185 )
{
struct V_1 * V_2 ;
if ( V_185 -> V_167 )
V_2 = F_13 ( V_17 ,
V_185 -> V_163 , V_185 -> V_164 ,
V_185 -> V_162 ? V_185 -> V_98 : 60 ,
V_185 -> V_168 , V_185 -> V_38 ,
V_185 -> V_29 ) ;
else
V_2 = F_42 ( V_17 ,
V_185 -> V_163 , V_185 -> V_164 ,
V_185 -> V_162 ? V_185 -> V_98 : 60 ,
V_185 -> V_38 ,
V_185 -> V_29 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type |= V_186 ;
F_51 ( V_2 , V_115 ) ;
return V_2 ;
}
void F_79 ( struct V_187 * V_188 ,
const struct V_1 * V_189 )
{
F_80 ( V_189 -> V_7 > V_190 || V_189 -> V_8 > V_190 ||
V_189 -> V_9 > V_190 || V_189 -> V_10 > V_190 ||
V_189 -> V_110 > V_190 || V_189 -> V_11 > V_190 ||
V_189 -> V_12 > V_190 || V_189 -> V_13 > V_190 ||
V_189 -> V_14 > V_190 || V_189 -> V_99 > V_190 ,
L_9 ) ;
V_188 -> clock = V_189 -> clock ;
V_188 -> V_7 = V_189 -> V_7 ;
V_188 -> V_8 = V_189 -> V_8 ;
V_188 -> V_9 = V_189 -> V_9 ;
V_188 -> V_10 = V_189 -> V_10 ;
V_188 -> V_110 = V_189 -> V_110 ;
V_188 -> V_11 = V_189 -> V_11 ;
V_188 -> V_12 = V_189 -> V_12 ;
V_188 -> V_13 = V_189 -> V_13 ;
V_188 -> V_14 = V_189 -> V_14 ;
V_188 -> V_99 = V_189 -> V_99 ;
V_188 -> V_6 = V_189 -> V_6 ;
V_188 -> V_15 = V_189 -> V_15 ;
V_188 -> type = V_189 -> type ;
strncpy ( V_188 -> V_5 , V_189 -> V_5 , V_96 ) ;
V_188 -> V_5 [ V_96 - 1 ] = 0 ;
}
int F_81 ( struct V_1 * V_188 ,
const struct V_187 * V_189 )
{
int V_95 = - V_191 ;
if ( V_189 -> clock > V_192 || V_189 -> V_6 > V_192 ) {
V_95 = - V_193 ;
goto V_188;
}
if ( ( V_189 -> V_15 & V_120 ) > V_194 )
goto V_188;
V_188 -> clock = V_189 -> clock ;
V_188 -> V_7 = V_189 -> V_7 ;
V_188 -> V_8 = V_189 -> V_8 ;
V_188 -> V_9 = V_189 -> V_9 ;
V_188 -> V_10 = V_189 -> V_10 ;
V_188 -> V_110 = V_189 -> V_110 ;
V_188 -> V_11 = V_189 -> V_11 ;
V_188 -> V_12 = V_189 -> V_12 ;
V_188 -> V_13 = V_189 -> V_13 ;
V_188 -> V_14 = V_189 -> V_14 ;
V_188 -> V_99 = V_189 -> V_99 ;
V_188 -> V_6 = V_189 -> V_6 ;
V_188 -> V_15 = V_189 -> V_15 ;
V_188 -> type = V_189 -> type ;
strncpy ( V_188 -> V_5 , V_189 -> V_5 , V_96 ) ;
V_188 -> V_5 [ V_96 - 1 ] = 0 ;
V_188 -> V_140 = F_60 ( V_188 ) ;
if ( V_188 -> V_140 != V_135 )
goto V_188;
V_95 = 0 ;
V_188:
return V_95 ;
}
