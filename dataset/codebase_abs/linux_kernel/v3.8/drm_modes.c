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
struct V_1 * F_3 ( struct V_16 * V_17 , int V_7 ,
int V_11 , int V_6 ,
bool V_18 , bool V_19 , bool V_20 )
{
#define F_4 18
#define F_5 8
#define F_6 3
#define F_7 6
#define F_8 250
struct V_1 * V_21 ;
unsigned int V_22 , V_23 ;
int V_24 , V_25 , V_26 , V_27 , V_28 ;
int V_29 ;
V_21 = F_9 ( V_17 ) ;
if ( ! V_21 )
return NULL ;
if ( ! V_6 )
V_6 = 60 ;
if ( V_19 )
V_22 = V_6 * 2 ;
else
V_22 = V_6 ;
V_24 = V_7 - ( V_7 % F_5 ) ;
V_25 = 0 ;
if ( V_20 ) {
V_25 = V_24 * F_4 / 1000 ;
V_25 -= V_25 % F_5 ;
}
V_21 -> V_7 = V_24 + 2 * V_25 ;
if ( V_19 )
V_26 = V_11 / 2 ;
else
V_26 = V_11 ;
V_27 = 0 ;
if ( V_20 )
V_27 = V_26 * F_4 / 1000 ;
V_21 -> V_11 = V_11 + 2 * V_27 ;
if ( V_19 )
V_29 = 1 ;
else
V_29 = 0 ;
if ( ! ( V_11 % 3 ) && ( ( V_11 * 4 / 3 ) == V_7 ) )
V_28 = 4 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 16 / 9 ) == V_7 ) )
V_28 = 5 ;
else if ( ! ( V_11 % 10 ) && ( ( V_11 * 16 / 10 ) == V_7 ) )
V_28 = 6 ;
else if ( ! ( V_11 % 4 ) && ( ( V_11 * 5 / 4 ) == V_7 ) )
V_28 = 7 ;
else if ( ! ( V_11 % 9 ) && ( ( V_11 * 15 / 9 ) == V_7 ) )
V_28 = 7 ;
else
V_28 = 10 ;
if ( ! V_18 ) {
int V_30 , V_31 ;
#define F_10 550
#define F_11 8
unsigned int V_32 ;
int V_33 , V_34 , V_35 ;
V_30 = V_36 * 1000000 -
F_10 * V_36 * V_22 ;
V_31 = ( V_26 + 2 * V_27 + F_6 ) * 2 +
V_29 ;
V_23 = V_30 * 2 / ( V_31 * V_22 ) ;
V_30 = F_10 * V_36 / V_23 + 1 ;
if ( V_30 < ( V_28 + F_6 ) )
V_33 = V_28 + F_6 ;
else
V_33 = V_30 ;
V_34 = V_33 - V_28 ;
V_21 -> V_14 = V_26 + 2 * V_27 +
V_33 + F_6 ;
#define F_12 600
#define F_13 40
#define F_14 128
#define F_15 20
#define F_16 (CVT_M_FACTOR * CVT_K_FACTOR / 256)
#define F_17 ((CVT_C_FACTOR - CVT_J_FACTOR) * CVT_K_FACTOR / 256 + \
CVT_J_FACTOR)
V_32 = F_17 * V_36 - F_16 *
V_23 / 1000 ;
if ( V_32 < 20 * V_36 )
V_32 = 20 * V_36 ;
V_35 = V_21 -> V_7 * V_32 /
( 100 * V_36 - V_32 ) ;
V_35 -= V_35 % ( 2 * F_5 ) ;
V_21 -> V_10 = V_21 -> V_7 + V_35 ;
V_21 -> V_9 = V_21 -> V_7 + V_35 / 2 ;
V_21 -> V_8 = V_21 -> V_9 -
( V_21 -> V_10 * F_11 ) / 100 ;
V_21 -> V_8 += F_5 -
V_21 -> V_8 % F_5 ;
V_21 -> V_12 = V_21 -> V_11 + F_6 ;
V_21 -> V_13 = V_21 -> V_12 + V_28 ;
} else {
#define F_18 460
#define F_19 32
#define F_20 160
#define F_21 3
int V_37 ;
int V_30 , V_31 ;
V_30 = V_36 * 1000000 -
F_18 * V_36 * V_22 ;
V_31 = V_26 + 2 * V_27 ;
V_23 = V_30 / ( V_31 * V_22 ) ;
V_37 = F_18 * V_36 / V_23 + 1 ;
if ( V_37 < ( F_21 + V_28 + F_7 ) )
V_37 = F_21 + V_28 + F_7 ;
V_21 -> V_14 = V_26 + 2 * V_27 + V_37 ;
V_21 -> V_10 = V_21 -> V_7 + F_20 ;
V_21 -> V_9 = V_21 -> V_7 + F_20 / 2 ;
V_21 -> V_8 = V_21 -> V_9 - F_19 ;
V_21 -> V_12 = V_21 -> V_11 + F_21 ;
V_21 -> V_13 = V_21 -> V_12 + V_28 ;
}
V_21 -> clock = V_21 -> V_10 * V_36 * 1000 / V_23 ;
V_21 -> clock -= V_21 -> clock % F_8 ;
if ( V_19 ) {
V_21 -> V_14 *= 2 ;
V_21 -> V_15 |= V_38 ;
}
F_22 ( V_21 ) ;
if ( V_18 )
V_21 -> V_15 |= ( V_39 |
V_40 ) ;
else
V_21 -> V_15 |= ( V_41 |
V_42 ) ;
return V_21 ;
}
struct V_1 *
F_23 ( struct V_16 * V_17 , int V_7 , int V_11 ,
int V_6 , bool V_19 , int V_20 ,
int V_43 , int V_44 , int V_45 , int V_46 )
{
#define F_24 18
#define F_25 8
#define F_26 1
#define F_27 3
#define F_28 8
#define F_29 550
#define F_30 ((((GTF_2C - GTF_2J) * GTF_K / 256) + GTF_2J) / 2)
#define F_31 (GTF_K * GTF_M / 256)
struct V_1 * V_21 ;
unsigned int V_24 , V_26 , V_47 ;
int V_48 , V_49 ;
int V_29 ;
unsigned int V_50 ;
int V_51 , V_34 ;
unsigned int V_52 , V_53 , V_23 ;
unsigned int V_54 , V_55 ;
int V_56 , V_57 ;
unsigned int V_58 , V_59 ;
unsigned int V_35 , V_60 , V_61 ;
int V_62 , V_63 , V_64 ;
unsigned int V_30 , V_31 ;
V_21 = F_9 ( V_17 ) ;
if ( ! V_21 )
return NULL ;
V_24 = ( V_7 + F_25 / 2 ) / F_25 ;
V_24 = V_24 * F_25 ;
if ( V_19 )
V_26 = V_11 / 2 ;
else
V_26 = V_11 ;
if ( V_19 )
V_47 = V_6 * 2 ;
else
V_47 = V_6 ;
V_48 = 0 ;
if ( V_20 )
V_48 = ( V_26 * F_24 + 500 ) /
1000 ;
V_49 = V_48 ;
if ( V_19 )
V_29 = 1 ;
else
V_29 = 0 ;
{
V_30 = ( 1000000 - F_29 * V_47 ) / 500 ;
V_31 = ( V_26 + 2 * V_48 + F_26 ) *
2 + V_29 ;
V_50 = ( V_31 * 1000 * V_47 ) / V_30 ;
}
V_51 = F_29 * V_50 / 1000 ;
V_51 = ( V_51 + 500 ) / 1000 ;
V_34 = V_51 - F_27 ;
V_52 = V_26 + V_48 + V_49 +
V_51 + F_26 ;
V_53 = V_50 / V_52 ;
V_23 = 1000000 / ( V_47 * V_52 ) ;
V_54 = V_50 / V_52 ;
if ( V_19 )
V_55 = V_54 / 2 ;
else
V_55 = V_54 ;
if ( V_20 )
V_56 = ( V_24 * F_24 + 500 ) /
1000 ;
else
V_56 = 0 ;
V_57 = V_56 ;
V_58 = V_24 + V_56 + V_57 ;
V_59 = F_30 * 1000 -
( F_31 * 1000000 / V_50 ) ;
V_35 = V_58 * V_59 /
( 100000 - V_59 ) ;
V_35 = ( V_35 + F_25 ) / ( 2 * F_25 ) ;
V_35 = V_35 * 2 * F_25 ;
V_60 = V_58 + V_35 ;
V_61 = V_60 * V_50 / 1000 ;
V_62 = F_28 * V_60 / 100 ;
V_62 = ( V_62 + F_25 / 2 ) / F_25 ;
V_62 = V_62 * F_25 ;
V_63 = V_35 / 2 - V_62 ;
V_64 = F_26 ;
V_21 -> V_7 = V_24 ;
V_21 -> V_8 = V_24 + V_63 ;
V_21 -> V_9 = V_21 -> V_8 + V_62 ;
V_21 -> V_10 = V_60 ;
V_21 -> V_11 = V_26 ;
V_21 -> V_12 = V_26 + V_64 ;
V_21 -> V_13 = V_21 -> V_12 + F_27 ;
V_21 -> V_14 = V_52 ;
V_21 -> clock = V_61 ;
if ( V_19 ) {
V_21 -> V_14 *= 2 ;
V_21 -> V_15 |= V_38 ;
}
F_22 ( V_21 ) ;
if ( V_43 == 600 && V_44 == 80 && V_45 == 128 && V_46 == 40 )
V_21 -> V_15 = V_42 | V_41 ;
else
V_21 -> V_15 = V_39 | V_40 ;
return V_21 ;
}
struct V_1 *
F_32 ( struct V_16 * V_17 , int V_7 , int V_11 , int V_6 ,
bool V_65 , int V_20 )
{
return F_23 ( V_17 , V_7 , V_11 , V_6 , V_65 ,
V_20 , 600 , 40 * 2 , 128 , 20 * 2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
bool V_19 = ! ! ( V_2 -> V_15 & V_38 ) ;
snprintf ( V_2 -> V_5 , V_66 , L_3 ,
V_2 -> V_7 , V_2 -> V_11 ,
V_19 ? L_4 : L_5 ) ;
}
void F_33 ( struct V_67 * V_68 , struct V_67 * V_69 )
{
struct V_67 * V_70 , * V_71 ;
F_34 (entry, tmp, head) {
F_35 ( V_70 , V_69 ) ;
}
}
int F_36 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
int F_37 ( const struct V_1 * V_2 )
{
return V_2 -> V_11 ;
}
int F_38 ( const struct V_1 * V_2 )
{
unsigned int V_72 ;
if ( V_2 -> V_62 )
return V_2 -> V_62 ;
if ( V_2 -> V_10 < 0 )
return 0 ;
V_72 = ( V_2 -> clock * 1000 ) / V_2 -> V_10 ;
V_72 += 500 ;
V_72 /= 1000 ;
return V_72 ;
}
int F_39 ( const struct V_1 * V_2 )
{
int V_73 = 0 ;
unsigned int V_72 ;
if ( V_2 -> V_6 > 0 )
V_73 = V_2 -> V_6 ;
else if ( V_2 -> V_10 > 0 && V_2 -> V_14 > 0 ) {
int V_14 ;
V_14 = V_2 -> V_14 ;
V_72 = ( V_2 -> clock * 1000 ) ;
V_72 /= V_2 -> V_10 ;
V_73 = ( V_72 + V_14 / 2 ) / V_14 ;
if ( V_2 -> V_15 & V_38 )
V_73 *= 2 ;
if ( V_2 -> V_15 & V_74 )
V_73 /= 2 ;
if ( V_2 -> V_75 > 1 )
V_73 /= V_2 -> V_75 ;
}
return V_73 ;
}
void F_40 ( struct V_1 * V_76 , int V_77 )
{
if ( ( V_76 == NULL ) || ( ( V_76 -> type & V_78 ) == V_79 ) )
return;
V_76 -> V_80 = V_76 -> V_7 ;
V_76 -> V_81 = V_76 -> V_8 ;
V_76 -> V_82 = V_76 -> V_9 ;
V_76 -> V_83 = V_76 -> V_10 ;
V_76 -> V_84 = V_76 -> V_85 ;
V_76 -> V_86 = V_76 -> V_11 ;
V_76 -> V_87 = V_76 -> V_12 ;
V_76 -> V_88 = V_76 -> V_13 ;
V_76 -> V_89 = V_76 -> V_14 ;
if ( V_76 -> V_15 & V_38 ) {
if ( V_77 & V_90 ) {
V_76 -> V_86 /= 2 ;
V_76 -> V_87 /= 2 ;
V_76 -> V_88 /= 2 ;
V_76 -> V_89 /= 2 ;
}
}
if ( V_76 -> V_15 & V_74 ) {
V_76 -> V_86 *= 2 ;
V_76 -> V_87 *= 2 ;
V_76 -> V_88 *= 2 ;
V_76 -> V_89 *= 2 ;
}
if ( V_76 -> V_75 > 1 ) {
V_76 -> V_86 *= V_76 -> V_75 ;
V_76 -> V_87 *= V_76 -> V_75 ;
V_76 -> V_88 *= V_76 -> V_75 ;
V_76 -> V_89 *= V_76 -> V_75 ;
}
V_76 -> V_91 = F_41 ( V_76 -> V_87 , V_76 -> V_86 ) ;
V_76 -> V_92 = F_42 ( V_76 -> V_88 , V_76 -> V_89 ) ;
V_76 -> V_93 = F_41 ( V_76 -> V_81 , V_76 -> V_80 ) ;
V_76 -> V_94 = F_42 ( V_76 -> V_82 , V_76 -> V_83 ) ;
}
void F_43 ( struct V_1 * V_95 , const struct V_1 * V_96 )
{
int V_4 = V_95 -> V_3 . V_4 ;
* V_95 = * V_96 ;
V_95 -> V_3 . V_4 = V_4 ;
F_44 ( & V_95 -> V_68 ) ;
}
struct V_1 * F_45 ( struct V_16 * V_17 ,
const struct V_1 * V_2 )
{
struct V_1 * V_97 ;
V_97 = F_9 ( V_17 ) ;
if ( ! V_97 )
return NULL ;
F_43 ( V_97 , V_2 ) ;
return V_97 ;
}
bool F_46 ( const struct V_1 * V_98 , const struct V_1 * V_99 )
{
if ( V_98 -> clock && V_99 -> clock ) {
if ( F_47 ( V_98 -> clock ) != F_47 ( V_99 -> clock ) )
return false ;
} else if ( V_98 -> clock != V_99 -> clock )
return false ;
if ( V_98 -> V_7 == V_99 -> V_7 &&
V_98 -> V_8 == V_99 -> V_8 &&
V_98 -> V_9 == V_99 -> V_9 &&
V_98 -> V_10 == V_99 -> V_10 &&
V_98 -> V_85 == V_99 -> V_85 &&
V_98 -> V_11 == V_99 -> V_11 &&
V_98 -> V_12 == V_99 -> V_12 &&
V_98 -> V_13 == V_99 -> V_13 &&
V_98 -> V_14 == V_99 -> V_14 &&
V_98 -> V_75 == V_99 -> V_75 &&
V_98 -> V_15 == V_99 -> V_15 )
return true ;
return false ;
}
void F_48 ( struct V_16 * V_17 ,
struct V_67 * V_100 ,
int V_101 , int V_102 , int V_103 )
{
struct V_1 * V_2 ;
F_49 (mode, mode_list, head) {
if ( V_103 > 0 && V_2 -> V_7 > V_103 )
V_2 -> V_104 = V_105 ;
if ( V_101 > 0 && V_2 -> V_7 > V_101 )
V_2 -> V_104 = V_106 ;
if ( V_102 > 0 && V_2 -> V_11 > V_102 )
V_2 -> V_104 = V_107 ;
}
}
void F_50 ( struct V_16 * V_17 ,
struct V_67 * V_100 ,
int * F_41 , int * F_42 , int V_108 )
{
struct V_1 * V_2 ;
int V_109 ;
F_49 (mode, mode_list, head) {
bool V_110 = false ;
for ( V_109 = 0 ; V_109 < V_108 ; V_109 ++ ) {
if ( V_2 -> clock >= F_41 [ V_109 ] && V_2 -> clock <= F_42 [ V_109 ] ) {
V_110 = true ;
break;
}
}
if ( ! V_110 )
V_2 -> V_104 = V_111 ;
}
}
void F_51 ( struct V_16 * V_17 ,
struct V_67 * V_100 , bool V_112 )
{
struct V_1 * V_2 , * V_113 ;
F_52 (mode, t, mode_list, head) {
if ( V_2 -> V_104 != V_114 ) {
F_53 ( & V_2 -> V_68 ) ;
if ( V_112 ) {
F_1 ( V_2 ) ;
F_2 ( L_6 ,
V_2 -> V_5 , V_2 -> V_104 ) ;
}
F_54 ( V_17 , V_2 ) ;
}
}
}
static int F_55 ( void * V_115 , struct V_67 * V_116 , struct V_67 * V_117 )
{
struct V_1 * V_118 = F_56 ( V_116 , struct V_1 , V_68 ) ;
struct V_1 * V_119 = F_56 ( V_117 , struct V_1 , V_68 ) ;
int V_120 ;
V_120 = ( ( V_119 -> type & V_121 ) != 0 ) -
( ( V_118 -> type & V_121 ) != 0 ) ;
if ( V_120 )
return V_120 ;
V_120 = V_119 -> V_7 * V_119 -> V_11 - V_118 -> V_7 * V_118 -> V_11 ;
if ( V_120 )
return V_120 ;
V_120 = V_119 -> clock - V_118 -> clock ;
return V_120 ;
}
void F_57 ( struct V_67 * V_100 )
{
F_58 ( NULL , V_100 , F_55 ) ;
}
void F_59 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_1 * V_124 , * V_125 ;
int V_126 ;
F_52 (pmode, pt, &connector->probed_modes,
head) {
V_126 = 0 ;
F_49 (mode, &connector->modes, head) {
if ( F_46 ( V_124 , V_2 ) ) {
V_126 = 1 ;
V_2 -> V_104 = V_124 -> V_104 ;
V_2 -> type |= V_124 -> type ;
F_53 ( & V_124 -> V_68 ) ;
F_54 ( V_123 -> V_17 , V_124 ) ;
break;
}
}
if ( ! V_126 ) {
F_35 ( & V_124 -> V_68 , & V_123 -> V_127 ) ;
}
}
}
bool F_60 ( const char * V_128 ,
struct V_122 * V_123 ,
struct V_129 * V_2 )
{
const char * V_5 ;
unsigned int V_130 ;
bool V_131 = false , V_132 = false , V_133 = false ;
unsigned int V_134 = 0 , V_135 = 0 , V_136 = 32 , V_73 = 0 ;
bool V_137 = false , V_138 = false , V_139 = false ;
bool V_29 = false , V_20 = false , V_140 = false ;
int V_109 ;
enum V_141 V_142 = V_143 ;
#ifdef F_61
if ( ! V_128 )
V_128 = V_144 ;
#endif
if ( ! V_128 ) {
V_2 -> V_145 = false ;
return false ;
}
V_5 = V_128 ;
V_130 = strlen ( V_5 ) ;
for ( V_109 = V_130 - 1 ; V_109 >= 0 ; V_109 -- ) {
switch ( V_5 [ V_109 ] ) {
case '@' :
if ( ! V_133 && ! V_132 &&
! V_137 && ! V_138 && ! V_139 && V_140 ) {
V_73 = F_62 ( & V_5 [ V_109 + 1 ] , NULL , 10 ) ;
V_133 = true ;
V_140 = false ;
} else
goto V_146;
break;
case '-' :
if ( ! V_132 && ! V_137 && ! V_138 &&
! V_139 && V_140 ) {
V_136 = F_62 ( & V_5 [ V_109 + 1 ] , NULL , 10 ) ;
V_132 = true ;
V_140 = false ;
} else
goto V_146;
break;
case 'x' :
if ( ! V_137 && V_140 ) {
V_135 = F_62 ( & V_5 [ V_109 + 1 ] , NULL , 10 ) ;
V_137 = true ;
V_140 = false ;
} else
goto V_146;
case '0' ... '9' :
V_140 = true ;
break;
case 'M' :
if ( V_137 || V_138 || V_140 )
goto V_146;
V_138 = true ;
break;
case 'R' :
if ( V_137 || V_138 || V_139 || V_140 )
goto V_146;
V_139 = true ;
break;
case 'm' :
if ( V_138 || V_137 || V_140 )
goto V_146;
V_20 = true ;
break;
case 'i' :
if ( V_138 || V_137 || V_140 )
goto V_146;
V_29 = true ;
break;
case 'e' :
if ( V_137 || V_132 || V_133 ||
V_140 || ( V_142 != V_143 ) )
goto V_146;
V_142 = V_147 ;
break;
case 'D' :
if ( V_137 || V_132 || V_133 ||
V_140 || ( V_142 != V_143 ) )
goto V_146;
if ( ( V_123 -> V_148 != V_149 ) &&
( V_123 -> V_148 != V_150 ) )
V_142 = V_147 ;
else
V_142 = V_151 ;
break;
case 'd' :
if ( V_137 || V_132 || V_133 ||
V_140 || ( V_142 != V_143 ) )
goto V_146;
V_142 = V_152 ;
break;
default:
goto V_146;
}
}
if ( V_109 < 0 && V_137 ) {
char * V_153 ;
V_134 = F_62 ( V_5 , & V_153 , 10 ) ;
if ( ( V_153 != NULL ) && ( * V_153 == 'x' ) )
V_131 = true ;
else
V_109 = V_153 - V_5 ;
} else if ( ! V_137 && V_140 ) {
V_109 = 0 ;
}
V_146:
if ( V_109 >= 0 ) {
F_63 ( V_154
L_7 ,
V_109 , V_5 ) ;
V_2 -> V_145 = false ;
return false ;
}
if ( V_131 ) {
V_2 -> V_145 = true ;
V_2 -> V_134 = V_134 ;
V_2 -> V_135 = V_135 ;
}
if ( V_133 ) {
V_2 -> V_133 = true ;
V_2 -> V_73 = V_73 ;
}
if ( V_132 ) {
V_2 -> V_132 = true ;
V_2 -> V_136 = V_136 ;
}
V_2 -> V_139 = V_139 ;
V_2 -> V_138 = V_138 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_142 = V_142 ;
return true ;
}
struct V_1 *
F_64 ( struct V_16 * V_17 ,
struct V_129 * V_155 )
{
struct V_1 * V_2 ;
if ( V_155 -> V_138 )
V_2 = F_3 ( V_17 ,
V_155 -> V_134 , V_155 -> V_135 ,
V_155 -> V_133 ? V_155 -> V_73 : 60 ,
V_155 -> V_139 , V_155 -> V_29 ,
V_155 -> V_20 ) ;
else
V_2 = F_32 ( V_17 ,
V_155 -> V_134 , V_155 -> V_135 ,
V_155 -> V_133 ? V_155 -> V_73 : 60 ,
V_155 -> V_29 ,
V_155 -> V_20 ) ;
if ( ! V_2 )
return NULL ;
F_40 ( V_2 , V_90 ) ;
return V_2 ;
}
