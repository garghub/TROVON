static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
V_3 -> V_4 = 1 ;
F_2 ( V_2 , V_5 ,
F_3 ( V_2 , V_5 ) | ( 1 << V_3 -> V_6 ) ) ;
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) |
V_8 | V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) &
~ ( V_8 | V_9 ) ) ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_6 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_5 ,
F_3 ( V_2 , V_5 ) & ~ ( 1 << V_3 -> V_6 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned char V_11 ;
int V_12 ;
F_6 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) |
V_13 ) ;
F_9 ( 3 ) ;
V_12 = 300 ;
while ( ! ( ( V_11 = F_5 ( V_2 , V_3 , V_7 ) ) &
V_13 ) && -- V_12 )
;
V_11 &= ~ V_13 ;
F_4 ( V_2 , V_3 , V_7 , V_11 ) ;
F_9 ( 3 ) ;
V_12 = 300 ;
while ( ( ( V_11 = F_5 ( V_2 , V_3 , V_7 ) ) &
V_13 ) && -- V_12 )
;
* V_3 -> V_14 = 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned int V_11 ;
F_6 ( V_2 , V_3 ) ;
V_11 = F_11 ( V_2 , V_3 , V_7 ) ;
V_11 = ( V_11 & ~ V_15 ) |
( V_3 -> V_16 << V_17 ) ;
if ( ! F_12 ( V_2 ) )
V_11 |= V_18 ;
F_13 ( V_2 , V_3 , V_7 , V_11 ) ;
F_13 ( V_2 , V_3 , V_19 , V_3 -> V_20 ) ;
F_14 ( V_2 , V_3 , V_21 , V_3 -> V_22 ) ;
F_14 ( V_2 , V_3 , V_23 , V_3 -> V_24 - 1 ) ;
F_13 ( V_2 , V_3 , V_25 , ( V_26 ) V_3 -> V_27 . V_28 ) ;
F_13 ( V_2 , V_3 , V_29 ,
F_15 ( V_3 -> V_27 . V_28 ) ) ;
if ( V_2 -> V_30 [ 0 ] != V_31 ||
V_2 -> V_30 [ 1 ] != V_31 ) {
if ( ! ( F_3 ( V_2 , V_32 ) & V_33 ) )
F_2 ( V_2 , V_32 ,
( V_26 ) V_2 -> V_14 . V_28 | V_33 ) ;
}
F_13 ( V_2 , V_3 , V_7 ,
F_11 ( V_2 , V_3 , V_7 ) | V_9 ) ;
return 0 ;
}
static inline struct V_3 *
F_16 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_36 , V_37 , V_38 ;
struct V_3 * V_39 = NULL ;
int V_40 = ( V_35 -> V_41 -> V_42 << 16 ) | ( V_35 -> V_43 << 2 ) |
( V_35 -> V_44 + 1 ) ;
if ( V_35 -> V_44 == V_45 ) {
V_36 = V_2 -> V_46 ;
V_38 = V_2 -> V_47 ;
} else {
V_36 = V_2 -> V_48 ;
V_38 = V_2 -> V_49 ;
}
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ , V_36 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_36 ] ;
F_17 ( V_3 ) ;
if ( ! V_3 -> V_50 && ! F_18 ( V_3 ) ) {
if ( V_3 -> V_51 == V_40 ) {
V_3 -> V_50 = 1 ;
V_3 -> V_51 = V_40 ;
F_19 ( V_3 ) ;
return V_3 ;
}
if ( ! V_39 )
V_39 = V_3 ;
}
F_19 ( V_3 ) ;
}
if ( V_39 ) {
F_17 ( V_39 ) ;
V_39 -> V_50 = 1 ;
V_39 -> V_51 = V_40 ;
F_19 ( V_39 ) ;
}
return V_39 ;
}
static inline void F_20 ( struct V_3 * V_3 )
{
V_3 -> V_50 = 0 ;
}
static T_1 F_21 ( const struct V_52 * V_53 )
{
struct V_3 * V_3 = F_22 ( V_53 , struct V_3 , V_54 ) ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
return F_3 ( V_2 , V_57 ) ;
}
static void F_24 ( struct V_34 * V_35 ,
bool V_58 , T_1 V_59 )
{
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_60 * V_61 = & V_3 -> V_62 ;
struct V_52 * V_53 = & V_3 -> V_54 ;
T_2 V_63 ;
V_53 -> V_64 = F_21 ;
V_53 -> V_65 = F_26 ( 32 ) ;
V_53 -> V_66 = 125 ;
V_53 -> V_67 = 0 ;
V_63 = 0 ;
F_27 ( V_61 , V_53 , V_63 ) ;
if ( V_58 )
V_61 -> V_68 = V_59 ;
}
static T_2 F_28 ( struct V_34 * V_35 ,
T_2 V_63 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_69 * V_70 = V_56 -> V_70 [ V_35 -> V_44 ] ;
T_2 V_71 , V_72 ;
if ( ! V_70 -> V_73 . V_74 )
return V_63 ;
V_71 = V_70 -> V_73 . V_74 ( V_70 , V_56 -> V_75 , V_35 ) ;
V_72 = F_29 ( V_71 * 1000000000LL ,
V_35 -> V_76 -> V_77 ) ;
if ( V_35 -> V_44 == V_78 )
return V_63 + V_72 ;
return ( V_63 > V_72 ) ? V_63 - V_72 : 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
struct V_3 * V_3 , V_26 * * V_81 ,
int V_82 , int V_83 , int V_84 )
{
V_26 * V_27 = * V_81 ;
while ( V_83 > 0 ) {
T_3 V_28 ;
int V_85 ;
if ( V_3 -> V_24 >= V_86 )
return - V_87 ;
V_28 = F_31 ( V_80 , V_82 ) ;
V_27 [ 0 ] = F_32 ( ( V_26 ) V_28 ) ;
V_27 [ 1 ] = F_32 ( F_15 ( V_28 ) ) ;
V_85 = F_33 ( V_80 , V_82 , V_83 ) ;
if ( V_2 -> V_88 & V_89 ) {
V_26 V_90 = 0x1000 - ( V_82 & 0xfff ) ;
if ( V_85 > V_90 )
V_85 = V_90 ;
}
V_27 [ 2 ] = F_32 ( V_85 ) ;
V_83 -= V_85 ;
V_27 [ 3 ] = ( V_83 || ! V_84 ) ? 0 : F_32 ( 0x01 ) ;
V_27 += 4 ;
V_3 -> V_24 ++ ;
V_82 += V_85 ;
}
* V_81 = V_27 ;
return V_82 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_3 )
{
V_26 * V_27 ;
int V_37 , V_82 , V_91 , V_92 ;
int V_93 = 0 ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
V_92 = V_3 -> V_92 ;
V_91 = V_3 -> V_20 / V_92 ;
V_27 = ( V_26 * ) V_3 -> V_27 . V_94 ;
V_82 = 0 ;
V_3 -> V_24 = 0 ;
if ( V_2 -> V_95 )
V_93 = V_2 -> V_95 [ V_2 -> V_96 ] ;
if ( ! V_3 -> V_97 && V_93 > 0 ) {
struct V_98 * V_76 = V_35 -> V_76 ;
int V_99 = V_93 ;
V_93 = ( V_93 * V_76 -> V_77 + 47999 ) / 48000 ;
if ( ! V_93 )
V_93 = V_99 ;
else
V_93 = ( ( V_93 + V_99 - 1 ) / V_99 ) *
V_99 ;
V_93 = F_35 ( V_76 , V_93 ) ;
if ( V_93 >= V_92 ) {
F_36 ( V_2 -> V_100 -> V_36 , L_1 ,
V_93 ) ;
V_93 = 0 ;
} else {
V_82 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 ,
& V_27 , V_82 , V_93 , true ) ;
if ( V_82 < 0 )
goto error;
}
} else
V_93 = 0 ;
for ( V_37 = 0 ; V_37 < V_91 ; V_37 ++ ) {
if ( V_37 == V_91 - 1 && V_93 )
V_82 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 , & V_27 , V_82 ,
V_92 - V_93 , 0 ) ;
else
V_82 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 , & V_27 , V_82 ,
V_92 ,
! V_3 -> V_97 ) ;
if ( V_82 < 0 )
goto error;
}
return 0 ;
error:
F_38 ( V_2 -> V_100 -> V_36 , L_2 ,
V_3 -> V_20 , V_92 ) ;
return - V_87 ;
}
static int F_39 ( struct V_34 * V_35 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_69 * V_70 = V_56 -> V_70 [ V_35 -> V_44 ] ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
unsigned long V_101 ;
F_40 ( & V_2 -> V_102 ) ;
F_41 ( & V_2 -> V_103 , V_101 ) ;
V_3 -> V_35 = NULL ;
V_3 -> V_104 = 0 ;
F_42 ( & V_2 -> V_103 , V_101 ) ;
F_20 ( V_3 ) ;
V_70 -> V_73 . V_105 ( V_70 , V_56 -> V_75 , V_35 ) ;
F_43 ( V_56 -> V_75 ) ;
F_44 ( & V_2 -> V_102 ) ;
return 0 ;
}
static int F_45 ( struct V_34 * V_35 ,
struct V_106 * V_107 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_108 ;
F_17 ( F_25 ( V_35 ) ) ;
if ( F_18 ( F_25 ( V_35 ) ) ) {
V_108 = - V_109 ;
goto V_110;
}
V_108 = V_2 -> V_73 -> V_111 ( V_2 , V_35 ,
F_46 ( V_107 ) ) ;
V_110:
F_19 ( F_25 ( V_35 ) ) ;
return V_108 ;
}
static int F_47 ( struct V_34 * V_35 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_69 * V_70 = V_56 -> V_70 [ V_35 -> V_44 ] ;
int V_112 ;
F_17 ( V_3 ) ;
if ( ! F_18 ( V_3 ) ) {
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
F_13 ( V_2 , V_3 , V_7 , 0 ) ;
V_3 -> V_20 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_22 = 0 ;
}
F_48 ( V_56 -> V_75 , V_70 , V_35 ) ;
V_112 = V_2 -> V_73 -> V_113 ( V_2 , V_35 ) ;
V_3 -> V_114 = 0 ;
F_19 ( V_3 ) ;
return V_112 ;
}
static int F_49 ( struct V_34 * V_35 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_69 * V_70 = V_56 -> V_70 [ V_35 -> V_44 ] ;
struct V_98 * V_76 = V_35 -> V_76 ;
unsigned int V_20 , V_92 , V_22 , V_16 ;
int V_112 ;
struct V_115 * V_116 =
F_50 ( V_56 -> V_75 , V_70 -> V_117 ) ;
unsigned short V_118 = V_116 ? V_116 -> V_118 : 0 ;
F_17 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
V_112 = - V_109 ;
goto V_110;
}
F_8 ( V_2 , V_3 ) ;
V_22 = F_51 ( V_76 -> V_77 ,
V_76 -> V_119 ,
V_76 -> V_120 ,
V_70 -> V_121 ,
V_118 ) ;
if ( ! V_22 ) {
F_38 ( V_2 -> V_100 -> V_36 ,
L_3 ,
V_76 -> V_77 , V_76 -> V_119 , V_76 -> V_120 ) ;
V_112 = - V_87 ;
goto V_110;
}
V_20 = F_52 ( V_35 ) ;
V_92 = F_53 ( V_35 ) ;
F_54 ( V_2 -> V_100 -> V_36 , L_4 ,
V_20 , V_22 ) ;
if ( V_20 != V_3 -> V_20 ||
V_92 != V_3 -> V_92 ||
V_22 != V_3 -> V_22 ||
V_76 -> V_97 != V_3 -> V_97 ) {
V_3 -> V_20 = V_20 ;
V_3 -> V_92 = V_92 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_97 = V_76 -> V_97 ;
V_112 = F_34 ( V_2 , V_35 , V_3 ) ;
if ( V_112 < 0 )
goto V_110;
}
if ( V_76 -> V_122 > 64 )
V_3 -> V_123 = - F_35 ( V_76 , 64 ) ;
else
V_3 -> V_123 = 0 ;
V_3 -> V_124 = ( ( ( V_76 -> V_122 * 24000 ) /
V_76 -> V_77 ) * 1000 ) ;
F_10 ( V_2 , V_3 ) ;
if ( V_35 -> V_44 == V_45 )
V_3 -> V_125 =
F_55 ( V_2 , V_3 , V_126 ) + 1 ;
else
V_3 -> V_125 = 0 ;
V_16 = V_3 -> V_16 ;
if ( ( V_2 -> V_88 & V_127 ) &&
V_16 > V_2 -> V_49 )
V_16 -= V_2 -> V_49 ;
V_112 = F_56 ( V_56 -> V_75 , V_70 , V_16 ,
V_3 -> V_22 , V_35 ) ;
V_110:
if ( ! V_112 )
V_3 -> V_114 = 1 ;
F_19 ( V_3 ) ;
return V_112 ;
}
static int F_57 ( struct V_34 * V_35 , int V_128 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_3 ;
struct V_34 * V_129 ;
int V_130 = 0 , V_131 , V_132 = 0 , V_133 = 0 ;
int V_134 , V_12 ;
V_3 = F_25 ( V_35 ) ;
F_58 ( V_2 , V_3 , V_128 ) ;
if ( F_18 ( V_3 ) || ! V_3 -> V_114 )
return - V_135 ;
switch ( V_128 ) {
case V_136 :
V_130 = 1 ;
case V_137 :
case V_138 :
V_131 = 1 ;
break;
case V_139 :
case V_140 :
case V_141 :
V_131 = 0 ;
break;
default:
return - V_87 ;
}
F_59 (s, substream) {
if ( V_129 -> V_41 -> V_100 != V_35 -> V_41 -> V_100 )
continue;
V_3 = F_25 ( V_129 ) ;
V_133 |= 1 << V_3 -> V_6 ;
V_132 ++ ;
F_60 ( V_129 , V_35 ) ;
}
F_61 ( & V_2 -> V_103 ) ;
if ( V_2 -> V_88 & V_142 )
F_2 ( V_2 , V_143 ,
F_3 ( V_2 , V_143 ) | V_133 ) ;
else
F_2 ( V_2 , V_144 , F_3 ( V_2 , V_144 ) | V_133 ) ;
F_59 (s, substream) {
if ( V_129 -> V_41 -> V_100 != V_35 -> V_41 -> V_100 )
continue;
V_3 = F_25 ( V_129 ) ;
if ( V_131 ) {
V_3 -> V_145 = F_3 ( V_2 , V_57 ) ;
if ( ! V_130 )
V_3 -> V_145 -=
V_3 -> V_124 ;
F_1 ( V_2 , V_3 ) ;
} else {
F_7 ( V_2 , V_3 ) ;
}
V_3 -> V_104 = V_131 ;
}
F_62 ( & V_2 -> V_103 ) ;
if ( V_131 ) {
for ( V_12 = 5000 ; V_12 ; V_12 -- ) {
V_134 = 0 ;
F_59 (s, substream) {
if ( V_129 -> V_41 -> V_100 != V_35 -> V_41 -> V_100 )
continue;
V_3 = F_25 ( V_129 ) ;
if ( ! ( F_5 ( V_2 , V_3 , V_10 ) &
V_146 ) )
V_134 ++ ;
}
if ( ! V_134 )
break;
F_63 () ;
}
} else {
for ( V_12 = 5000 ; V_12 ; V_12 -- ) {
V_134 = 0 ;
F_59 (s, substream) {
if ( V_129 -> V_41 -> V_100 != V_35 -> V_41 -> V_100 )
continue;
V_3 = F_25 ( V_129 ) ;
if ( F_5 ( V_2 , V_3 , V_7 ) &
V_8 )
V_134 ++ ;
}
if ( ! V_134 )
break;
F_63 () ;
}
}
F_61 ( & V_2 -> V_103 ) ;
if ( V_2 -> V_88 & V_142 )
F_2 ( V_2 , V_143 ,
F_3 ( V_2 , V_143 ) & ~ V_133 ) ;
else
F_2 ( V_2 , V_144 , F_3 ( V_2 , V_144 ) & ~ V_133 ) ;
if ( V_131 ) {
F_24 ( V_35 , 0 , 0 ) ;
if ( V_132 > 1 ) {
T_1 V_68 ;
V_3 = F_25 ( V_35 ) ;
V_68 = V_3 -> V_62 . V_68 ;
F_59 (s, substream) {
if ( V_129 -> V_41 -> V_100 != V_35 -> V_41 -> V_100 )
continue;
F_24 ( V_129 , 1 , V_68 ) ;
}
}
}
F_62 ( & V_2 -> V_103 ) ;
return 0 ;
}
static unsigned int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_147 , V_148 , V_149 ;
unsigned int V_150 , V_151 , V_152 ;
unsigned int V_125 ;
V_147 = F_11 ( V_2 , V_3 , V_153 ) ;
if ( V_3 -> V_35 -> V_44 == V_45 ) {
return V_147 ;
}
V_151 = F_65 ( * V_3 -> V_14 ) ;
V_151 %= V_3 -> V_92 ;
V_125 = F_66 ( V_2 -> V_154 + V_155 ) ;
if ( V_3 -> V_4 ) {
if ( V_147 <= V_125 )
return 0 ;
V_3 -> V_4 = 0 ;
}
if ( V_147 <= V_125 )
V_148 = V_3 -> V_20 + V_147 - V_125 ;
else
V_148 = V_147 - V_125 ;
V_152 = V_148 % V_3 -> V_92 ;
V_150 = V_147 % V_3 -> V_92 ;
if ( V_150 >= V_125 )
V_149 = V_147 - V_150 ;
else if ( V_151 >= V_152 )
V_149 = V_148 - V_152 ;
else {
V_149 = V_148 - V_152 + V_3 -> V_92 ;
if ( V_149 >= V_3 -> V_20 )
V_149 = 0 ;
}
return V_149 + V_151 ;
}
unsigned int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
bool V_156 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_55 * V_56 = F_23 ( V_35 ) ;
unsigned int V_157 ;
int V_44 = V_35 -> V_44 ;
struct V_69 * V_70 = V_56 -> V_70 [ V_44 ] ;
int V_158 = 0 ;
switch ( V_2 -> V_30 [ V_44 ] ) {
case V_31 :
V_157 = F_11 ( V_2 , V_3 , V_153 ) ;
break;
case V_159 :
V_157 = F_64 ( V_2 , V_3 ) ;
break;
default:
V_157 = F_65 ( * V_3 -> V_14 ) ;
if ( V_156 && V_2 -> V_30 [ V_44 ] == V_160 ) {
if ( ! V_157 || V_157 == ( V_26 ) - 1 ) {
F_68 ( V_2 -> V_100 -> V_36 ,
L_5 ) ;
V_2 -> V_30 [ V_44 ] = V_31 ;
V_157 = F_11 ( V_2 , V_3 , V_153 ) ;
} else
V_2 -> V_30 [ V_44 ] = V_161 ;
}
break;
}
if ( V_157 >= V_3 -> V_20 )
V_157 = 0 ;
if ( V_35 -> V_76 &&
V_2 -> V_30 [ V_44 ] == V_161 &&
( V_2 -> V_88 & V_162 ) ) {
unsigned int V_163 = F_11 ( V_2 , V_3 , V_153 ) ;
if ( V_44 == V_45 )
V_158 = V_157 - V_163 ;
else
V_158 = V_163 - V_157 ;
if ( V_158 < 0 ) {
if ( V_158 >= V_3 -> V_123 )
V_158 = 0 ;
else
V_158 += V_3 -> V_20 ;
}
if ( V_158 >= V_3 -> V_92 ) {
F_68 ( V_2 -> V_100 -> V_36 ,
L_6 ,
V_158 , V_3 -> V_92 ) ;
V_158 = 0 ;
V_2 -> V_88 &= ~ V_162 ;
}
V_158 = F_69 ( V_35 -> V_76 , V_158 ) ;
}
if ( V_35 -> V_76 ) {
if ( V_70 -> V_73 . V_74 )
V_158 += V_70 -> V_73 . V_74 ( V_70 , V_56 -> V_75 ,
V_35 ) ;
V_35 -> V_76 -> V_158 = V_158 ;
}
F_70 ( V_2 , V_3 , V_157 , V_158 ) ;
return V_157 ;
}
static T_4 F_71 ( struct V_34 * V_35 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
return F_69 ( V_35 -> V_76 ,
F_67 ( V_2 , V_3 , false ) ) ;
}
static int F_72 ( struct V_34 * V_35 ,
struct V_164 * V_165 )
{
struct V_3 * V_3 = F_25 ( V_35 ) ;
T_2 V_63 ;
V_63 = F_73 ( & V_3 -> V_62 ) ;
V_63 = F_29 ( V_63 , 3 ) ;
V_63 = F_28 ( V_35 , V_63 ) ;
* V_165 = F_74 ( V_63 ) ;
return 0 ;
}
static int F_75 ( struct V_34 * V_35 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_69 * V_70 = V_56 -> V_70 [ V_35 -> V_44 ] ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_3 ;
struct V_98 * V_76 = V_35 -> V_76 ;
unsigned long V_101 ;
int V_112 ;
int V_166 ;
F_40 ( & V_2 -> V_102 ) ;
V_3 = F_16 ( V_2 , V_35 ) ;
if ( V_3 == NULL ) {
F_44 ( & V_2 -> V_102 ) ;
return - V_109 ;
}
V_76 -> V_167 = V_168 ;
V_76 -> V_167 . V_169 = V_70 -> V_169 ;
V_76 -> V_167 . V_170 = V_70 -> V_170 ;
V_76 -> V_167 . V_171 = V_70 -> V_171 ;
V_76 -> V_167 . V_172 = V_70 -> V_172 ;
F_76 ( V_76 ) ;
F_77 ( V_76 , V_173 ) ;
F_78 ( V_76 , V_174 ,
20 ,
178000000 ) ;
if ( V_2 -> V_175 )
V_166 = 128 ;
else
V_166 = 4 ;
F_79 ( V_76 , 0 , V_176 ,
V_166 ) ;
F_79 ( V_76 , 0 , V_177 ,
V_166 ) ;
F_80 ( V_56 -> V_75 ) ;
V_112 = V_70 -> V_73 . V_178 ( V_70 , V_56 -> V_75 , V_35 ) ;
if ( V_112 < 0 ) {
F_20 ( V_3 ) ;
F_43 ( V_56 -> V_75 ) ;
F_44 ( & V_2 -> V_102 ) ;
return V_112 ;
}
F_76 ( V_76 ) ;
if ( F_81 ( ! V_76 -> V_167 . V_169 ) ||
F_81 ( ! V_76 -> V_167 . V_170 ) ||
F_81 ( ! V_76 -> V_167 . V_171 ) ||
F_81 ( ! V_76 -> V_167 . V_172 ) ) {
F_20 ( V_3 ) ;
V_70 -> V_73 . V_105 ( V_70 , V_56 -> V_75 , V_35 ) ;
F_43 ( V_56 -> V_75 ) ;
F_44 ( & V_2 -> V_102 ) ;
return - V_87 ;
}
if ( V_35 -> V_44 == V_78 )
V_76 -> V_167 . V_179 &= ~ V_180 ;
F_41 ( & V_2 -> V_103 , V_101 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_104 = 0 ;
F_42 ( & V_2 -> V_103 , V_101 ) ;
V_76 -> V_181 = V_3 ;
F_82 ( V_35 ) ;
F_44 ( & V_2 -> V_102 ) ;
return 0 ;
}
static int F_83 ( struct V_34 * V_35 ,
struct V_182 * V_94 )
{
struct V_55 * V_56 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
if ( V_2 -> V_73 -> V_183 )
V_2 -> V_73 -> V_183 ( V_35 , V_94 ) ;
return F_84 ( V_35 , V_94 ) ;
}
static void F_85 ( struct V_184 * V_41 )
{
struct V_55 * V_56 = V_41 -> V_181 ;
if ( V_56 ) {
F_86 ( & V_56 -> V_185 ) ;
F_87 ( V_56 ) ;
}
}
static int F_88 ( struct V_186 * V_187 , struct V_188 * V_75 ,
struct V_189 * V_190 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
struct V_184 * V_41 ;
struct V_55 * V_56 ;
int V_191 = V_190 -> V_42 ;
unsigned int V_83 ;
int V_129 , V_112 ;
F_89 (apcm, &chip->pcm_list, list) {
if ( V_56 -> V_41 -> V_42 == V_191 ) {
F_38 ( V_2 -> V_100 -> V_36 , L_7 ,
V_191 ) ;
return - V_109 ;
}
}
V_112 = F_90 ( V_2 -> V_100 , V_190 -> V_192 , V_191 ,
V_190 -> V_44 [ V_45 ] . V_193 ,
V_190 -> V_44 [ V_78 ] . V_193 ,
& V_41 ) ;
if ( V_112 < 0 )
return V_112 ;
F_91 ( V_41 -> V_192 , V_190 -> V_192 , sizeof( V_41 -> V_192 ) ) ;
V_56 = F_92 ( sizeof( * V_56 ) , V_194 ) ;
if ( V_56 == NULL )
return - V_195 ;
V_56 -> V_2 = V_2 ;
V_56 -> V_41 = V_41 ;
V_56 -> V_75 = V_75 ;
V_41 -> V_181 = V_56 ;
V_41 -> V_196 = F_85 ;
if ( V_190 -> V_197 == V_198 )
V_41 -> V_199 = V_200 ;
F_93 ( & V_56 -> V_185 , & V_2 -> V_201 ) ;
V_190 -> V_41 = V_41 ;
for ( V_129 = 0 ; V_129 < 2 ; V_129 ++ ) {
V_56 -> V_70 [ V_129 ] = & V_190 -> V_44 [ V_129 ] ;
if ( V_190 -> V_44 [ V_129 ] . V_193 )
F_94 ( V_41 , V_129 , & V_202 ) ;
}
V_83 = V_203 * 1024 ;
if ( V_83 > V_204 )
V_83 = V_204 ;
F_95 ( V_41 , V_205 ,
V_2 -> V_100 -> V_36 ,
V_83 , V_204 ) ;
V_41 -> V_36 = & V_75 -> V_36 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_112 ;
V_112 = V_2 -> V_73 -> V_206 ( V_2 , V_207 ,
V_208 , & V_2 -> V_209 ) ;
if ( V_112 < 0 )
F_38 ( V_2 -> V_100 -> V_36 , L_8 ) ;
return V_112 ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_12 ;
F_98 ( & V_2 -> V_103 ) ;
V_2 -> V_210 . V_28 = V_2 -> V_209 . V_28 ;
V_2 -> V_210 . V_211 = ( V_26 * ) V_2 -> V_209 . V_94 ;
F_2 ( V_2 , V_212 , ( V_26 ) V_2 -> V_210 . V_28 ) ;
F_2 ( V_2 , V_213 , F_15 ( V_2 -> V_210 . V_28 ) ) ;
F_99 ( V_2 , V_214 , 0x02 ) ;
F_100 ( V_2 , V_215 , 0 ) ;
F_100 ( V_2 , V_216 , V_217 ) ;
if ( ! ( V_2 -> V_88 & V_218 ) ) {
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( ( F_101 ( V_2 , V_216 ) & V_217 ) == V_217 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_100 -> V_36 , L_9 ,
F_101 ( V_2 , V_216 ) ) ;
F_100 ( V_2 , V_216 , 0 ) ;
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( F_101 ( V_2 , V_216 ) == 0 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_100 -> V_36 , L_10 ,
F_101 ( V_2 , V_216 ) ) ;
}
F_99 ( V_2 , V_219 , V_220 ) ;
V_2 -> V_221 . V_28 = V_2 -> V_209 . V_28 + 2048 ;
V_2 -> V_221 . V_211 = ( V_26 * ) ( V_2 -> V_209 . V_94 + 2048 ) ;
V_2 -> V_221 . V_222 = V_2 -> V_221 . V_223 = 0 ;
memset ( V_2 -> V_221 . V_224 , 0 , sizeof( V_2 -> V_221 . V_224 ) ) ;
F_2 ( V_2 , V_225 , ( V_26 ) V_2 -> V_221 . V_28 ) ;
F_2 ( V_2 , V_226 , F_15 ( V_2 -> V_221 . V_28 ) ) ;
F_99 ( V_2 , V_227 , 0x02 ) ;
F_100 ( V_2 , V_228 , V_229 ) ;
if ( V_2 -> V_88 & V_127 )
F_100 ( V_2 , V_230 , 0xc0 ) ;
else
F_100 ( V_2 , V_230 , 1 ) ;
F_99 ( V_2 , V_231 , V_232 | V_233 ) ;
F_102 ( & V_2 -> V_103 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_98 ( & V_2 -> V_103 ) ;
F_99 ( V_2 , V_231 , 0 ) ;
F_99 ( V_2 , V_219 , 0 ) ;
F_102 ( & V_2 -> V_103 ) ;
}
static unsigned int F_104 ( V_26 V_128 )
{
unsigned int V_28 = V_128 >> 28 ;
if ( V_28 >= V_234 ) {
F_105 () ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_106 ( struct V_186 * V_187 , V_26 V_11 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
unsigned int V_28 = F_104 ( V_11 ) ;
unsigned int V_222 , V_223 ;
F_98 ( & V_2 -> V_103 ) ;
V_222 = F_101 ( V_2 , V_215 ) ;
if ( V_222 == 0xffff ) {
F_102 ( & V_2 -> V_103 ) ;
return - V_235 ;
}
V_222 ++ ;
V_222 %= V_236 ;
V_223 = F_101 ( V_2 , V_216 ) ;
if ( V_222 == V_223 ) {
F_102 ( & V_2 -> V_103 ) ;
return - V_237 ;
}
V_2 -> V_221 . V_224 [ V_28 ] ++ ;
V_2 -> V_210 . V_211 [ V_222 ] = F_32 ( V_11 ) ;
F_100 ( V_2 , V_215 , V_222 ) ;
F_102 ( & V_2 -> V_103 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
unsigned int V_223 , V_222 ;
unsigned int V_28 ;
V_26 V_39 , V_238 ;
V_222 = F_101 ( V_2 , V_228 ) ;
if ( V_222 == 0xffff ) {
return;
}
if ( V_222 == V_2 -> V_221 . V_222 )
return;
V_2 -> V_221 . V_222 = V_222 ;
while ( V_2 -> V_221 . V_223 != V_222 ) {
V_2 -> V_221 . V_223 ++ ;
V_2 -> V_221 . V_223 %= V_239 ;
V_223 = V_2 -> V_221 . V_223 << 1 ;
V_238 = F_65 ( V_2 -> V_221 . V_211 [ V_223 + 1 ] ) ;
V_39 = F_65 ( V_2 -> V_221 . V_211 [ V_223 ] ) ;
V_28 = V_238 & 0xf ;
if ( ( V_28 >= V_234 ) || ! ( V_2 -> V_240 & ( 1 << V_28 ) ) ) {
F_38 ( V_2 -> V_100 -> V_36 , L_11 ,
V_39 , V_238 ,
V_2 -> V_221 . V_223 , V_222 ) ;
F_105 () ;
}
else if ( V_238 & V_241 )
F_108 ( V_2 -> V_187 , V_39 , V_238 ) ;
else if ( V_2 -> V_221 . V_224 [ V_28 ] ) {
V_2 -> V_221 . V_39 [ V_28 ] = V_39 ;
F_109 () ;
V_2 -> V_221 . V_224 [ V_28 ] -- ;
} else if ( F_110 () ) {
F_38 ( V_2 -> V_100 -> V_36 , L_12 ,
V_39 , V_238 ,
V_2 -> V_242 [ V_28 ] ) ;
}
}
}
static unsigned int F_111 ( struct V_186 * V_187 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
unsigned long V_12 ;
unsigned long V_243 ;
int V_244 = 0 ;
V_245:
V_12 = V_246 + F_112 ( 1000 ) ;
for ( V_243 = 0 ; ; V_243 ++ ) {
if ( V_2 -> V_247 || V_244 ) {
F_98 ( & V_2 -> V_103 ) ;
F_107 ( V_2 ) ;
F_102 ( & V_2 -> V_103 ) ;
}
if ( ! V_2 -> V_221 . V_224 [ V_28 ] ) {
F_113 () ;
V_187 -> V_248 = 0 ;
if ( ! V_244 )
V_2 -> V_249 = 0 ;
return V_2 -> V_221 . V_39 [ V_28 ] ;
}
if ( F_114 ( V_246 , V_12 ) )
break;
if ( V_187 -> V_250 || V_243 > 3000 )
F_115 ( 2 ) ;
else {
F_9 ( 10 ) ;
F_116 () ;
}
}
if ( ! V_187 -> V_251 )
return - 1 ;
if ( ! V_2 -> V_247 && V_2 -> V_249 < 2 ) {
F_54 ( V_2 -> V_100 -> V_36 ,
L_13 ,
V_2 -> V_242 [ V_28 ] ) ;
V_244 = 1 ;
V_2 -> V_249 ++ ;
goto V_245;
}
if ( ! V_2 -> V_247 ) {
F_36 ( V_2 -> V_100 -> V_36 ,
L_14 ,
V_2 -> V_242 [ V_28 ] ) ;
V_2 -> V_247 = 1 ;
goto V_245;
}
if ( V_2 -> V_252 ) {
F_36 ( V_2 -> V_100 -> V_36 ,
L_15 ,
V_2 -> V_242 [ V_28 ] ) ;
if ( V_2 -> V_73 -> V_253 ( V_2 ) &&
V_2 -> V_73 -> V_253 ( V_2 ) < 0 ) {
V_187 -> V_248 = 1 ;
return - 1 ;
}
goto V_245;
}
if ( V_2 -> V_254 ) {
return - 1 ;
}
V_187 -> V_248 = 1 ;
if ( V_187 -> V_255 && ! V_187 -> V_256 && ! V_187 -> V_257 ) {
V_187 -> V_256 = 1 ;
return - 1 ;
}
F_38 ( V_2 -> V_100 -> V_36 ,
L_16 ,
V_2 -> V_242 [ V_28 ] ) ;
V_2 -> V_258 = 1 ;
V_187 -> V_256 = 0 ;
F_103 ( V_2 ) ;
F_2 ( V_2 , V_259 , F_3 ( V_2 , V_259 ) & ~ V_260 ) ;
return - 1 ;
}
static int F_117 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_12 = 50 ;
while ( V_12 -- ) {
if ( F_101 ( V_2 , V_261 ) & V_262 ) {
V_2 -> V_221 . V_39 [ V_28 ] = F_3 ( V_2 , V_263 ) ;
return 0 ;
}
F_9 ( 1 ) ;
}
if ( F_110 () )
F_54 ( V_2 -> V_100 -> V_36 , L_17 ,
F_101 ( V_2 , V_261 ) ) ;
V_2 -> V_221 . V_39 [ V_28 ] = - 1 ;
return - V_235 ;
}
static int F_118 ( struct V_186 * V_187 , V_26 V_11 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
unsigned int V_28 = F_104 ( V_11 ) ;
int V_12 = 50 ;
V_187 -> V_248 = 0 ;
while ( V_12 -- ) {
if ( ! ( ( F_101 ( V_2 , V_261 ) & V_264 ) ) ) {
F_100 ( V_2 , V_261 , F_101 ( V_2 , V_261 ) |
V_262 ) ;
F_2 ( V_2 , V_265 , V_11 ) ;
F_100 ( V_2 , V_261 , F_101 ( V_2 , V_261 ) |
V_264 ) ;
return F_117 ( V_2 , V_28 ) ;
}
F_9 ( 1 ) ;
}
if ( F_110 () )
F_54 ( V_2 -> V_100 -> V_36 ,
L_18 ,
F_101 ( V_2 , V_261 ) , V_11 ) ;
return - V_235 ;
}
static unsigned int F_119 ( struct V_186 * V_187 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
return V_2 -> V_221 . V_39 [ V_28 ] ;
}
static int F_120 ( struct V_186 * V_187 , unsigned int V_11 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
if ( V_2 -> V_266 )
return 0 ;
V_2 -> V_242 [ F_104 ( V_11 ) ] = V_11 ;
if ( V_2 -> V_258 )
return F_118 ( V_187 , V_11 ) ;
else
return F_106 ( V_187 , V_11 ) ;
}
static unsigned int F_121 ( struct V_186 * V_187 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
if ( V_2 -> V_266 )
return 0 ;
if ( V_2 -> V_258 )
return F_119 ( V_187 , V_28 ) ;
else
return F_111 ( V_187 , V_28 ) ;
}
static struct V_3 *
F_122 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 [ V_2 -> V_46 ] ;
}
static int F_123 ( struct V_186 * V_187 , unsigned int V_120 ,
unsigned int V_267 ,
struct V_79 * V_268 )
{
V_26 * V_27 ;
struct V_1 * V_2 = V_187 -> V_181 ;
struct V_3 * V_3 ;
int V_112 ;
V_3 = F_122 ( V_2 ) ;
F_17 ( V_3 ) ;
F_98 ( & V_2 -> V_103 ) ;
if ( V_3 -> V_104 || V_3 -> V_269 ) {
F_102 ( & V_2 -> V_103 ) ;
V_112 = - V_109 ;
goto V_110;
}
V_3 -> V_114 = 0 ;
V_2 -> V_270 = * V_3 ;
V_3 -> V_269 = 1 ;
F_102 ( & V_2 -> V_103 ) ;
V_112 = V_2 -> V_73 -> V_206 ( V_2 , V_205 ,
V_267 , V_268 ) ;
if ( V_112 < 0 )
goto V_271;
V_3 -> V_20 = V_267 ;
V_3 -> V_92 = V_267 ;
V_3 -> V_22 = V_120 ;
F_8 ( V_2 , V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
V_3 -> V_24 = 0 ;
V_27 = ( V_26 * ) V_3 -> V_27 . V_94 ;
V_112 = F_30 ( V_2 , V_268 , V_3 , & V_27 , 0 , V_267 , 0 ) ;
if ( V_112 < 0 )
goto error;
F_10 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_3 -> V_16 ;
error:
V_2 -> V_73 -> V_272 ( V_2 , V_268 ) ;
V_271:
F_98 ( & V_2 -> V_103 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_270 ;
V_3 -> V_269 = 0 ;
F_102 ( & V_2 -> V_103 ) ;
V_110:
F_19 ( V_3 ) ;
return V_112 ;
}
static void F_124 ( struct V_186 * V_187 , bool V_131 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
struct V_3 * V_3 = F_122 ( V_2 ) ;
if ( V_131 )
F_1 ( V_2 , V_3 ) ;
else
F_7 ( V_2 , V_3 ) ;
V_3 -> V_104 = V_131 ;
}
static void F_125 ( struct V_186 * V_187 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
struct V_3 * V_3 = F_122 ( V_2 ) ;
if ( ! V_80 -> V_94 || ! V_3 -> V_269 )
return;
F_17 ( V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
F_13 ( V_2 , V_3 , V_7 , 0 ) ;
V_3 -> V_20 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_22 = 0 ;
V_2 -> V_73 -> V_272 ( V_2 , V_80 ) ;
V_80 -> V_94 = NULL ;
F_98 ( & V_2 -> V_103 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_270 ;
V_3 -> V_269 = 0 ;
F_102 ( & V_2 -> V_103 ) ;
F_19 ( V_3 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_37 , V_112 ;
struct V_273 * V_100 = V_2 -> V_100 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ ) {
F_127 ( & V_2 -> V_3 [ V_37 ] ) ;
V_112 = V_2 -> V_73 -> V_206 ( V_2 , V_207 ,
V_275 ,
& V_2 -> V_3 [ V_37 ] . V_27 ) ;
if ( V_112 < 0 ) {
F_38 ( V_100 -> V_36 , L_19 ) ;
return - V_195 ;
}
}
V_112 = V_2 -> V_73 -> V_206 ( V_2 , V_207 ,
V_2 -> V_274 * 8 , & V_2 -> V_14 ) ;
if ( V_112 < 0 ) {
F_38 ( V_100 -> V_36 , L_20 ) ;
return - V_195 ;
}
V_112 = F_96 ( V_2 ) ;
if ( V_112 < 0 )
return V_112 ;
return 0 ;
}
void F_128 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_3 ) {
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ )
if ( V_2 -> V_3 [ V_37 ] . V_27 . V_94 )
V_2 -> V_73 -> V_272 (
V_2 , & V_2 -> V_3 [ V_37 ] . V_27 ) ;
}
if ( V_2 -> V_209 . V_94 )
V_2 -> V_73 -> V_272 ( V_2 , & V_2 -> V_209 ) ;
if ( V_2 -> V_14 . V_94 )
V_2 -> V_73 -> V_272 ( V_2 , & V_2 -> V_14 ) ;
}
void F_129 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_2 ( V_2 , V_259 , F_3 ( V_2 , V_259 ) & ~ V_276 ) ;
V_12 = V_246 + F_112 ( 100 ) ;
while ( ( F_130 ( V_2 , V_259 ) & V_276 ) &&
F_131 ( V_246 , V_12 ) )
F_132 ( 500 , 1000 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_99 ( V_2 , V_259 , F_130 ( V_2 , V_259 ) | V_276 ) ;
V_12 = V_246 + F_112 ( 100 ) ;
while ( ! F_130 ( V_2 , V_259 ) &&
F_131 ( V_246 , V_12 ) )
F_132 ( 500 , 1000 ) ;
}
static int F_134 ( struct V_1 * V_2 , bool V_277 )
{
if ( ! V_277 )
goto V_278;
F_100 ( V_2 , V_279 , V_280 ) ;
F_129 ( V_2 ) ;
F_132 ( 500 , 1000 ) ;
F_133 ( V_2 ) ;
F_132 ( 1000 , 1200 ) ;
V_278:
if ( ! F_130 ( V_2 , V_259 ) ) {
F_54 ( V_2 -> V_100 -> V_36 , L_21 ) ;
return - V_109 ;
}
if ( ! V_2 -> V_258 )
F_2 ( V_2 , V_259 , F_3 ( V_2 , V_259 ) |
V_260 ) ;
if ( ! V_2 -> V_240 ) {
V_2 -> V_240 = F_101 ( V_2 , V_279 ) ;
F_54 ( V_2 -> V_100 -> V_36 , L_22 ,
V_2 -> V_240 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) |
V_281 | V_282 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) &
~ V_9 ) ;
}
F_99 ( V_2 , V_5 , 0 ) ;
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) &
~ ( V_281 | V_282 ) ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
}
F_100 ( V_2 , V_279 , V_280 ) ;
F_99 ( V_2 , V_283 , V_284 ) ;
F_2 ( V_2 , V_285 , V_281 | V_286 ) ;
}
void F_138 ( struct V_1 * V_2 , bool V_277 )
{
if ( V_2 -> V_287 )
return;
F_134 ( V_2 , V_277 ) ;
F_137 ( V_2 ) ;
F_135 ( V_2 ) ;
if ( ! V_2 -> V_258 )
F_97 ( V_2 ) ;
F_2 ( V_2 , V_32 , ( V_26 ) V_2 -> V_14 . V_28 ) ;
F_2 ( V_2 , V_288 , F_15 ( V_2 -> V_14 . V_28 ) ) ;
V_2 -> V_287 = 1 ;
}
void F_139 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_287 )
return;
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
F_103 ( V_2 ) ;
F_2 ( V_2 , V_32 , 0 ) ;
F_2 ( V_2 , V_288 , 0 ) ;
V_2 -> V_287 = 0 ;
}
T_5 F_140 ( int V_289 , void * V_290 )
{
struct V_1 * V_2 = V_290 ;
struct V_3 * V_3 ;
V_26 V_291 ;
T_6 V_292 ;
int V_37 ;
#ifdef F_141
if ( V_2 -> V_88 & V_293 )
if ( ! F_142 ( V_2 -> V_100 -> V_36 ) )
return V_294 ;
#endif
F_61 ( & V_2 -> V_103 ) ;
if ( V_2 -> V_266 ) {
F_62 ( & V_2 -> V_103 ) ;
return V_294 ;
}
V_291 = F_3 ( V_2 , V_285 ) ;
if ( V_291 == 0 || V_291 == 0xffffffff ) {
F_62 ( & V_2 -> V_103 ) ;
return V_294 ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ ) {
V_3 = & V_2 -> V_3 [ V_37 ] ;
if ( V_291 & V_3 -> V_295 ) {
V_292 = F_5 ( V_2 , V_3 , V_10 ) ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
if ( ! V_3 -> V_35 || ! V_3 -> V_104 ||
! ( V_292 & V_296 ) )
continue;
if ( ! V_2 -> V_73 -> V_297 ||
V_2 -> V_73 -> V_297 ( V_2 , V_3 ) ) {
F_62 ( & V_2 -> V_103 ) ;
F_143 ( V_3 -> V_35 ) ;
F_61 ( & V_2 -> V_103 ) ;
}
}
}
V_291 = F_130 ( V_2 , V_283 ) ;
if ( V_291 & V_284 ) {
if ( V_291 & V_298 ) {
if ( V_2 -> V_88 & V_299 )
F_9 ( 80 ) ;
F_107 ( V_2 ) ;
}
F_99 ( V_2 , V_283 , V_284 ) ;
}
F_62 ( & V_2 -> V_103 ) ;
return V_300 ;
}
static int F_144 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_128 = ( V_28 << 28 ) | ( V_301 << 20 ) |
( V_302 << 8 ) | V_303 ;
unsigned int V_39 ;
F_40 ( & V_2 -> V_187 -> V_304 ) ;
V_2 -> V_254 = 1 ;
F_120 ( V_2 -> V_187 , V_128 ) ;
V_39 = F_121 ( V_2 -> V_187 , V_28 ) ;
V_2 -> V_254 = 0 ;
F_44 ( & V_2 -> V_187 -> V_304 ) ;
if ( V_39 == - 1 )
return - V_235 ;
F_54 ( V_2 -> V_100 -> V_36 , L_23 , V_28 ) ;
return 0 ;
}
static void F_145 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
V_187 -> V_257 = 1 ;
F_139 ( V_2 ) ;
F_138 ( V_2 , true ) ;
#ifdef F_146
if ( V_2 -> V_287 ) {
struct V_55 * V_305 ;
F_89 (p, &chip->pcm_list, list)
F_147 ( V_305 -> V_41 ) ;
F_148 ( V_2 -> V_187 ) ;
F_149 ( V_2 -> V_187 ) ;
}
#endif
V_187 -> V_257 = 0 ;
}
static void F_150 ( struct V_186 * V_187 , bool V_306 )
{
struct V_1 * V_2 = V_187 -> V_181 ;
if ( ! ( V_2 -> V_88 & V_293 ) )
return;
if ( V_306 )
F_151 ( V_2 -> V_100 -> V_36 ) ;
else
F_152 ( V_2 -> V_100 -> V_36 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned int V_307 ;
if ( ! V_2 -> V_308 )
return 0 ;
V_37 = V_2 -> V_308 [ V_2 -> V_96 ] ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 < 50 || V_37 > 60000 )
V_307 = 0 ;
else
V_307 = F_112 ( V_37 ) ;
if ( V_307 == 0 )
F_36 ( V_2 -> V_100 -> V_36 ,
L_24 , V_37 ) ;
return V_307 ;
}
int F_154 ( struct V_1 * V_2 , const char * V_309 ,
unsigned int V_310 ,
int * V_311 )
{
struct V_312 V_313 ;
int V_314 , V_315 , V_112 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_181 = V_2 ;
V_313 . V_316 = V_309 ;
V_313 . V_317 = V_2 -> V_317 ;
V_313 . V_73 . V_318 = F_120 ;
V_313 . V_73 . V_319 = F_121 ;
V_313 . V_73 . V_320 = F_88 ;
V_313 . V_73 . V_321 = F_145 ;
#ifdef F_146
V_313 . V_322 = V_311 ;
V_313 . V_73 . V_323 = F_150 ;
#endif
#ifdef F_155
V_313 . V_73 . V_324 = F_123 ;
V_313 . V_73 . V_325 = F_124 ;
V_313 . V_73 . V_326 = F_125 ;
#endif
V_112 = F_156 ( V_2 -> V_100 , & V_313 , & V_2 -> V_187 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_2 -> V_88 & V_327 ) {
F_54 ( V_2 -> V_100 -> V_36 , L_25 ) ;
V_2 -> V_187 -> V_250 = 1 ;
}
V_315 = 0 ;
if ( ! V_310 )
V_310 = V_328 ;
for ( V_314 = 0 ; V_314 < V_310 ; V_314 ++ ) {
if ( ( V_2 -> V_240 & ( 1 << V_314 ) ) & V_2 -> V_329 ) {
if ( F_144 ( V_2 , V_314 ) < 0 ) {
F_36 ( V_2 -> V_100 -> V_36 ,
L_26 , V_314 ) ;
V_2 -> V_240 &= ~ ( 1 << V_314 ) ;
F_139 ( V_2 ) ;
F_138 ( V_2 , true ) ;
}
}
}
if ( V_2 -> V_88 & V_330 ) {
F_54 ( V_2 -> V_100 -> V_36 , L_27 ) ;
V_2 -> V_187 -> V_331 = 1 ;
V_2 -> V_187 -> V_255 = 1 ;
}
for ( V_314 = 0 ; V_314 < V_310 ; V_314 ++ ) {
if ( ( V_2 -> V_240 & ( 1 << V_314 ) ) & V_2 -> V_329 ) {
struct V_188 * V_75 ;
V_112 = F_157 ( V_2 -> V_187 , V_314 , & V_75 ) ;
if ( V_112 < 0 )
continue;
V_75 -> V_332 = F_153 ( V_2 ) ;
V_75 -> V_333 = V_2 -> V_333 ;
V_315 ++ ;
}
}
if ( ! V_315 ) {
F_38 ( V_2 -> V_100 -> V_36 , L_28 ) ;
return - V_334 ;
}
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
struct V_188 * V_75 ;
F_89 (codec, &chip->bus->codec_list, list) {
F_159 ( V_75 ) ;
}
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
return F_161 ( V_2 -> V_187 ) ;
}
int F_162 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_274 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
V_3 -> V_14 = ( V_26 V_335 * ) ( V_2 -> V_14 . V_94 + V_37 * 8 ) ;
V_3 -> V_336 = V_2 -> V_154 + ( 0x20 * V_37 + 0x80 ) ;
V_3 -> V_295 = 1 << V_37 ;
V_3 -> V_6 = V_37 ;
V_3 -> V_16 = V_37 + 1 ;
}
return 0 ;
}
