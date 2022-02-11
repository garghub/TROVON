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
if ( ! V_39 ||
( V_2 -> V_52 & V_53 ) )
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
static T_1 F_21 ( const struct V_54 * V_55 )
{
struct V_3 * V_3 = F_22 ( V_55 , struct V_3 , V_56 ) ;
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
return F_3 ( V_2 , V_59 ) ;
}
static void F_24 ( struct V_34 * V_35 ,
bool V_60 , T_1 V_61 )
{
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_62 * V_63 = & V_3 -> V_64 ;
struct V_54 * V_55 = & V_3 -> V_56 ;
T_2 V_65 ;
V_55 -> V_66 = F_21 ;
V_55 -> V_67 = F_26 ( 32 ) ;
V_55 -> V_68 = 125 ;
V_55 -> V_69 = 0 ;
V_65 = 0 ;
F_27 ( V_63 , V_55 , V_65 ) ;
if ( V_60 )
V_63 -> V_70 = V_61 ;
}
static T_2 F_28 ( struct V_34 * V_35 ,
T_2 V_65 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
T_2 V_73 , V_74 ;
if ( ! V_72 -> V_75 . V_76 )
return V_65 ;
V_73 = V_72 -> V_75 . V_76 ( V_72 , V_58 -> V_77 , V_35 ) ;
V_74 = F_29 ( V_73 * 1000000000LL ,
V_35 -> V_78 -> V_79 ) ;
if ( V_35 -> V_44 == V_80 )
return V_65 + V_74 ;
return ( V_65 > V_74 ) ? V_65 - V_74 : 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_3 * V_3 , V_26 * * V_83 ,
int V_84 , int V_85 , int V_86 )
{
V_26 * V_27 = * V_83 ;
while ( V_85 > 0 ) {
T_3 V_28 ;
int V_87 ;
if ( V_3 -> V_24 >= V_88 )
return - V_89 ;
V_28 = F_31 ( V_82 , V_84 ) ;
V_27 [ 0 ] = F_32 ( ( V_26 ) V_28 ) ;
V_27 [ 1 ] = F_32 ( F_15 ( V_28 ) ) ;
V_87 = F_33 ( V_82 , V_84 , V_85 ) ;
if ( V_2 -> V_52 & V_90 ) {
V_26 V_91 = 0x1000 - ( V_84 & 0xfff ) ;
if ( V_87 > V_91 )
V_87 = V_91 ;
}
V_27 [ 2 ] = F_32 ( V_87 ) ;
V_85 -= V_87 ;
V_27 [ 3 ] = ( V_85 || ! V_86 ) ? 0 : F_32 ( 0x01 ) ;
V_27 += 4 ;
V_3 -> V_24 ++ ;
V_84 += V_87 ;
}
* V_83 = V_27 ;
return V_84 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_3 )
{
V_26 * V_27 ;
int V_37 , V_84 , V_92 , V_93 ;
int V_94 = 0 ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
V_93 = V_3 -> V_93 ;
V_92 = V_3 -> V_20 / V_93 ;
V_27 = ( V_26 * ) V_3 -> V_27 . V_95 ;
V_84 = 0 ;
V_3 -> V_24 = 0 ;
if ( V_2 -> V_96 )
V_94 = V_2 -> V_96 [ V_2 -> V_97 ] ;
if ( ! V_3 -> V_98 && V_94 > 0 ) {
struct V_99 * V_78 = V_35 -> V_78 ;
int V_100 = V_94 ;
V_94 = ( V_94 * V_78 -> V_79 + 47999 ) / 48000 ;
if ( ! V_94 )
V_94 = V_100 ;
else
V_94 = ( ( V_94 + V_100 - 1 ) / V_100 ) *
V_100 ;
V_94 = F_35 ( V_78 , V_94 ) ;
if ( V_94 >= V_93 ) {
F_36 ( V_2 -> V_101 -> V_36 , L_1 ,
V_94 ) ;
V_94 = 0 ;
} else {
V_84 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 ,
& V_27 , V_84 , V_94 , true ) ;
if ( V_84 < 0 )
goto error;
}
} else
V_94 = 0 ;
for ( V_37 = 0 ; V_37 < V_92 ; V_37 ++ ) {
if ( V_37 == V_92 - 1 && V_94 )
V_84 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 , & V_27 , V_84 ,
V_93 - V_94 , 0 ) ;
else
V_84 = F_30 ( V_2 , F_37 ( V_35 ) ,
V_3 , & V_27 , V_84 ,
V_93 ,
! V_3 -> V_98 ) ;
if ( V_84 < 0 )
goto error;
}
return 0 ;
error:
F_38 ( V_2 -> V_101 -> V_36 , L_2 ,
V_3 -> V_20 , V_93 ) ;
return - V_89 ;
}
static int F_39 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
unsigned long V_102 ;
F_40 ( & V_2 -> V_103 ) ;
F_41 ( & V_2 -> V_104 , V_102 ) ;
V_3 -> V_35 = NULL ;
V_3 -> V_105 = 0 ;
F_42 ( & V_2 -> V_104 , V_102 ) ;
F_20 ( V_3 ) ;
V_72 -> V_75 . V_106 ( V_72 , V_58 -> V_77 , V_35 ) ;
F_43 ( V_58 -> V_77 ) ;
F_44 ( & V_2 -> V_103 ) ;
return 0 ;
}
static int F_45 ( struct V_34 * V_35 ,
struct V_107 * V_108 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
int V_109 ;
F_17 ( F_25 ( V_35 ) ) ;
if ( F_18 ( F_25 ( V_35 ) ) ) {
V_109 = - V_110 ;
goto V_111;
}
V_109 = V_2 -> V_75 -> V_112 ( V_2 , V_35 ,
F_46 ( V_108 ) ) ;
V_111:
F_19 ( F_25 ( V_35 ) ) ;
return V_109 ;
}
static int F_47 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
int V_113 ;
F_17 ( V_3 ) ;
if ( ! F_18 ( V_3 ) ) {
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
F_13 ( V_2 , V_3 , V_7 , 0 ) ;
V_3 -> V_20 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_22 = 0 ;
}
F_48 ( V_58 -> V_77 , V_72 , V_35 ) ;
V_113 = V_2 -> V_75 -> V_114 ( V_2 , V_35 ) ;
V_3 -> V_115 = 0 ;
F_19 ( V_3 ) ;
return V_113 ;
}
static int F_49 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
struct V_99 * V_78 = V_35 -> V_78 ;
unsigned int V_20 , V_93 , V_22 , V_16 ;
int V_113 ;
struct V_116 * V_117 =
F_50 ( V_58 -> V_77 , V_72 -> V_118 ) ;
unsigned short V_119 = V_117 ? V_117 -> V_119 : 0 ;
F_17 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
V_113 = - V_110 ;
goto V_111;
}
F_8 ( V_2 , V_3 ) ;
V_22 = F_51 ( V_58 -> V_77 ,
V_78 -> V_79 ,
V_78 -> V_120 ,
V_78 -> V_121 ,
V_72 -> V_122 ,
V_119 ) ;
if ( ! V_22 ) {
F_38 ( V_2 -> V_101 -> V_36 ,
L_3 ,
V_78 -> V_79 , V_78 -> V_120 , V_78 -> V_121 ) ;
V_113 = - V_89 ;
goto V_111;
}
V_20 = F_52 ( V_35 ) ;
V_93 = F_53 ( V_35 ) ;
F_54 ( V_2 -> V_101 -> V_36 , L_4 ,
V_20 , V_22 ) ;
if ( V_20 != V_3 -> V_20 ||
V_93 != V_3 -> V_93 ||
V_22 != V_3 -> V_22 ||
V_78 -> V_98 != V_3 -> V_98 ) {
V_3 -> V_20 = V_20 ;
V_3 -> V_93 = V_93 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_98 = V_78 -> V_98 ;
V_113 = F_34 ( V_2 , V_35 , V_3 ) ;
if ( V_113 < 0 )
goto V_111;
}
if ( V_78 -> V_123 > 64 )
V_3 -> V_124 = - F_35 ( V_78 , 64 ) ;
else
V_3 -> V_124 = 0 ;
V_3 -> V_125 = ( ( ( V_78 -> V_123 * 24000 ) /
V_78 -> V_79 ) * 1000 ) ;
F_10 ( V_2 , V_3 ) ;
if ( V_35 -> V_44 == V_45 )
V_3 -> V_126 =
F_55 ( V_2 , V_3 , V_127 ) + 1 ;
else
V_3 -> V_126 = 0 ;
V_16 = V_3 -> V_16 ;
if ( ( V_2 -> V_52 & V_128 ) &&
V_16 > V_2 -> V_49 )
V_16 -= V_2 -> V_49 ;
V_113 = F_56 ( V_58 -> V_77 , V_72 , V_16 ,
V_3 -> V_22 , V_35 ) ;
V_111:
if ( ! V_113 )
V_3 -> V_115 = 1 ;
F_19 ( V_3 ) ;
return V_113 ;
}
static int F_57 ( struct V_34 * V_35 , int V_129 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 ;
struct V_34 * V_130 ;
int V_131 = 0 , V_132 , V_133 = 0 , V_134 = 0 ;
int V_135 , V_12 ;
V_3 = F_25 ( V_35 ) ;
F_58 ( V_2 , V_3 , V_129 ) ;
if ( F_18 ( V_3 ) || ! V_3 -> V_115 )
return - V_136 ;
switch ( V_129 ) {
case V_137 :
V_131 = 1 ;
case V_138 :
case V_139 :
V_132 = 1 ;
break;
case V_140 :
case V_141 :
case V_142 :
V_132 = 0 ;
break;
default:
return - V_89 ;
}
F_59 (s, substream) {
if ( V_130 -> V_41 -> V_101 != V_35 -> V_41 -> V_101 )
continue;
V_3 = F_25 ( V_130 ) ;
V_134 |= 1 << V_3 -> V_6 ;
V_133 ++ ;
F_60 ( V_130 , V_35 ) ;
}
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_52 & V_143 )
F_2 ( V_2 , V_144 ,
F_3 ( V_2 , V_144 ) | V_134 ) ;
else
F_2 ( V_2 , V_145 , F_3 ( V_2 , V_145 ) | V_134 ) ;
F_59 (s, substream) {
if ( V_130 -> V_41 -> V_101 != V_35 -> V_41 -> V_101 )
continue;
V_3 = F_25 ( V_130 ) ;
if ( V_132 ) {
V_3 -> V_146 = F_3 ( V_2 , V_59 ) ;
if ( ! V_131 )
V_3 -> V_146 -=
V_3 -> V_125 ;
F_1 ( V_2 , V_3 ) ;
} else {
F_7 ( V_2 , V_3 ) ;
}
V_3 -> V_105 = V_132 ;
}
F_62 ( & V_2 -> V_104 ) ;
if ( V_132 ) {
for ( V_12 = 5000 ; V_12 ; V_12 -- ) {
V_135 = 0 ;
F_59 (s, substream) {
if ( V_130 -> V_41 -> V_101 != V_35 -> V_41 -> V_101 )
continue;
V_3 = F_25 ( V_130 ) ;
if ( ! ( F_5 ( V_2 , V_3 , V_10 ) &
V_147 ) )
V_135 ++ ;
}
if ( ! V_135 )
break;
F_63 () ;
}
} else {
for ( V_12 = 5000 ; V_12 ; V_12 -- ) {
V_135 = 0 ;
F_59 (s, substream) {
if ( V_130 -> V_41 -> V_101 != V_35 -> V_41 -> V_101 )
continue;
V_3 = F_25 ( V_130 ) ;
if ( F_5 ( V_2 , V_3 , V_7 ) &
V_8 )
V_135 ++ ;
}
if ( ! V_135 )
break;
F_63 () ;
}
}
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_52 & V_143 )
F_2 ( V_2 , V_144 ,
F_3 ( V_2 , V_144 ) & ~ V_134 ) ;
else
F_2 ( V_2 , V_145 , F_3 ( V_2 , V_145 ) & ~ V_134 ) ;
if ( V_132 ) {
F_24 ( V_35 , 0 , 0 ) ;
F_64 ( V_35 -> V_78 , & V_35 -> V_78 -> V_148 ) ;
V_35 -> V_78 -> V_149 = true ;
if ( V_133 > 1 ) {
T_1 V_70 ;
V_3 = F_25 ( V_35 ) ;
V_70 = V_3 -> V_64 . V_70 ;
F_59 (s, substream) {
if ( V_130 -> V_41 -> V_101 != V_35 -> V_41 -> V_101 )
continue;
F_24 ( V_130 , 1 , V_70 ) ;
}
}
}
F_62 ( & V_2 -> V_104 ) ;
return 0 ;
}
unsigned int V_31 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return F_11 ( V_2 , V_3 , V_150 ) ;
}
unsigned int F_65 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return F_66 ( * V_3 -> V_14 ) ;
}
unsigned int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
unsigned int V_151 ;
int V_44 = V_35 -> V_44 ;
int V_152 = 0 ;
if ( V_2 -> V_30 [ V_44 ] )
V_151 = V_2 -> V_30 [ V_44 ] ( V_2 , V_3 ) ;
else
V_151 = F_65 ( V_2 , V_3 ) ;
if ( V_151 >= V_3 -> V_20 )
V_151 = 0 ;
if ( V_35 -> V_78 ) {
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_44 ] ;
if ( V_2 -> V_76 [ V_44 ] )
V_152 += V_2 -> V_76 [ V_44 ] ( V_2 , V_3 , V_151 ) ;
if ( V_72 -> V_75 . V_76 )
V_152 += V_72 -> V_75 . V_76 ( V_72 , V_58 -> V_77 ,
V_35 ) ;
V_35 -> V_78 -> V_152 = V_152 ;
}
F_68 ( V_2 , V_3 , V_151 , V_152 ) ;
return V_151 ;
}
static T_4 F_69 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
return F_70 ( V_35 -> V_78 ,
F_67 ( V_2 , V_3 ) ) ;
}
static int F_71 ( struct V_34 * V_35 ,
struct V_153 * V_154 )
{
struct V_3 * V_3 = F_25 ( V_35 ) ;
T_2 V_65 ;
V_65 = F_72 ( & V_3 -> V_64 ) ;
V_65 = F_29 ( V_65 , 3 ) ;
V_65 = F_28 ( V_35 , V_65 ) ;
* V_154 = F_73 ( V_65 ) ;
return 0 ;
}
static int F_74 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 ;
struct V_99 * V_78 = V_35 -> V_78 ;
unsigned long V_102 ;
int V_113 ;
int V_155 ;
F_40 ( & V_2 -> V_103 ) ;
V_3 = F_16 ( V_2 , V_35 ) ;
if ( V_3 == NULL ) {
F_44 ( & V_2 -> V_103 ) ;
return - V_110 ;
}
V_78 -> V_156 = V_157 ;
V_78 -> V_156 . V_158 = V_72 -> V_158 ;
V_78 -> V_156 . V_159 = V_72 -> V_159 ;
V_78 -> V_156 . V_160 = V_72 -> V_160 ;
V_78 -> V_156 . V_161 = V_72 -> V_161 ;
F_75 ( V_78 ) ;
F_76 ( V_78 , V_162 ) ;
F_77 ( V_78 , V_163 ,
20 ,
178000000 ) ;
if ( V_2 -> V_164 )
V_155 = 128 ;
else
V_155 = 4 ;
F_78 ( V_78 , 0 , V_165 ,
V_155 ) ;
F_78 ( V_78 , 0 , V_166 ,
V_155 ) ;
F_79 ( V_58 -> V_77 ) ;
V_113 = V_72 -> V_75 . V_167 ( V_72 , V_58 -> V_77 , V_35 ) ;
if ( V_113 < 0 ) {
F_20 ( V_3 ) ;
F_43 ( V_58 -> V_77 ) ;
F_44 ( & V_2 -> V_103 ) ;
return V_113 ;
}
F_75 ( V_78 ) ;
if ( F_80 ( ! V_78 -> V_156 . V_158 ) ||
F_80 ( ! V_78 -> V_156 . V_159 ) ||
F_80 ( ! V_78 -> V_156 . V_160 ) ||
F_80 ( ! V_78 -> V_156 . V_161 ) ) {
F_20 ( V_3 ) ;
V_72 -> V_75 . V_106 ( V_72 , V_58 -> V_77 , V_35 ) ;
F_43 ( V_58 -> V_77 ) ;
F_44 ( & V_2 -> V_103 ) ;
return - V_89 ;
}
if ( V_35 -> V_44 == V_80 )
V_78 -> V_156 . V_168 &= ~ V_169 ;
F_41 ( & V_2 -> V_104 , V_102 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_105 = 0 ;
F_42 ( & V_2 -> V_104 , V_102 ) ;
V_78 -> V_170 = V_3 ;
F_81 ( V_35 ) ;
F_44 ( & V_2 -> V_103 ) ;
return 0 ;
}
static int F_82 ( struct V_34 * V_35 ,
struct V_171 * V_95 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
if ( V_2 -> V_75 -> V_172 )
V_2 -> V_75 -> V_172 ( V_35 , V_95 ) ;
return F_83 ( V_35 , V_95 ) ;
}
static void F_84 ( struct V_173 * V_41 )
{
struct V_57 * V_58 = V_41 -> V_170 ;
if ( V_58 ) {
F_85 ( & V_58 -> V_174 ) ;
F_86 ( V_58 ) ;
}
}
static int F_87 ( struct V_175 * V_176 , struct V_177 * V_77 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
struct V_173 * V_41 ;
struct V_57 * V_58 ;
int V_180 = V_179 -> V_42 ;
unsigned int V_85 ;
int V_130 , V_113 ;
F_88 (apcm, &chip->pcm_list, list) {
if ( V_58 -> V_41 -> V_42 == V_180 ) {
F_38 ( V_2 -> V_101 -> V_36 , L_5 ,
V_180 ) ;
return - V_110 ;
}
}
V_113 = F_89 ( V_2 -> V_101 , V_179 -> V_181 , V_180 ,
V_179 -> V_44 [ V_45 ] . V_182 ,
V_179 -> V_44 [ V_80 ] . V_182 ,
& V_41 ) ;
if ( V_113 < 0 )
return V_113 ;
F_90 ( V_41 -> V_181 , V_179 -> V_181 , sizeof( V_41 -> V_181 ) ) ;
V_58 = F_91 ( sizeof( * V_58 ) , V_183 ) ;
if ( V_58 == NULL )
return - V_184 ;
V_58 -> V_2 = V_2 ;
V_58 -> V_41 = V_41 ;
V_58 -> V_77 = V_77 ;
V_41 -> V_170 = V_58 ;
V_41 -> V_185 = F_84 ;
if ( V_179 -> V_186 == V_187 )
V_41 -> V_188 = V_189 ;
F_92 ( & V_58 -> V_174 , & V_2 -> V_190 ) ;
V_179 -> V_41 = V_41 ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ ) {
V_58 -> V_72 [ V_130 ] = & V_179 -> V_44 [ V_130 ] ;
if ( V_179 -> V_44 [ V_130 ] . V_182 )
F_93 ( V_41 , V_130 , & V_191 ) ;
}
V_85 = V_192 * 1024 ;
if ( V_85 > V_193 )
V_85 = V_193 ;
F_94 ( V_41 , V_194 ,
V_2 -> V_101 -> V_36 ,
V_85 , V_193 ) ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ )
V_41 -> V_195 [ V_130 ] . V_36 . V_196 = & V_77 -> V_36 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_113 ;
V_113 = V_2 -> V_75 -> V_197 ( V_2 , V_198 ,
V_199 , & V_2 -> V_200 ) ;
if ( V_113 < 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_6 ) ;
return V_113 ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_12 ;
F_97 ( & V_2 -> V_104 ) ;
V_2 -> V_201 . V_28 = V_2 -> V_200 . V_28 ;
V_2 -> V_201 . V_202 = ( V_26 * ) V_2 -> V_200 . V_95 ;
F_2 ( V_2 , V_203 , ( V_26 ) V_2 -> V_201 . V_28 ) ;
F_2 ( V_2 , V_204 , F_15 ( V_2 -> V_201 . V_28 ) ) ;
F_98 ( V_2 , V_205 , 0x02 ) ;
F_99 ( V_2 , V_206 , 0 ) ;
F_99 ( V_2 , V_207 , V_208 ) ;
if ( ! ( V_2 -> V_52 & V_209 ) ) {
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( ( F_100 ( V_2 , V_207 ) & V_208 ) == V_208 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_7 ,
F_100 ( V_2 , V_207 ) ) ;
F_99 ( V_2 , V_207 , 0 ) ;
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( F_100 ( V_2 , V_207 ) == 0 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_8 ,
F_100 ( V_2 , V_207 ) ) ;
}
F_98 ( V_2 , V_210 , V_211 ) ;
V_2 -> V_212 . V_28 = V_2 -> V_200 . V_28 + 2048 ;
V_2 -> V_212 . V_202 = ( V_26 * ) ( V_2 -> V_200 . V_95 + 2048 ) ;
V_2 -> V_212 . V_213 = V_2 -> V_212 . V_214 = 0 ;
memset ( V_2 -> V_212 . V_215 , 0 , sizeof( V_2 -> V_212 . V_215 ) ) ;
F_2 ( V_2 , V_216 , ( V_26 ) V_2 -> V_212 . V_28 ) ;
F_2 ( V_2 , V_217 , F_15 ( V_2 -> V_212 . V_28 ) ) ;
F_98 ( V_2 , V_218 , 0x02 ) ;
F_99 ( V_2 , V_219 , V_220 ) ;
if ( V_2 -> V_52 & V_128 )
F_99 ( V_2 , V_221 , 0xc0 ) ;
else
F_99 ( V_2 , V_221 , 1 ) ;
F_98 ( V_2 , V_222 , V_223 | V_224 ) ;
F_101 ( & V_2 -> V_104 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_97 ( & V_2 -> V_104 ) ;
F_98 ( V_2 , V_222 , 0 ) ;
F_98 ( V_2 , V_210 , 0 ) ;
F_101 ( & V_2 -> V_104 ) ;
}
static unsigned int F_103 ( V_26 V_129 )
{
unsigned int V_28 = V_129 >> 28 ;
if ( V_28 >= V_225 ) {
F_104 () ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_105 ( struct V_175 * V_176 , V_26 V_11 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
unsigned int V_28 = F_103 ( V_11 ) ;
unsigned int V_213 , V_214 ;
F_97 ( & V_2 -> V_104 ) ;
V_213 = F_100 ( V_2 , V_206 ) ;
if ( V_213 == 0xffff ) {
F_101 ( & V_2 -> V_104 ) ;
return - V_226 ;
}
V_213 ++ ;
V_213 %= V_227 ;
V_214 = F_100 ( V_2 , V_207 ) ;
if ( V_213 == V_214 ) {
F_101 ( & V_2 -> V_104 ) ;
return - V_228 ;
}
V_2 -> V_212 . V_215 [ V_28 ] ++ ;
V_2 -> V_201 . V_202 [ V_213 ] = F_32 ( V_11 ) ;
F_99 ( V_2 , V_206 , V_213 ) ;
F_101 ( & V_2 -> V_104 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
unsigned int V_214 , V_213 ;
unsigned int V_28 ;
V_26 V_39 , V_229 ;
V_213 = F_100 ( V_2 , V_219 ) ;
if ( V_213 == 0xffff ) {
return;
}
if ( V_213 == V_2 -> V_212 . V_213 )
return;
V_2 -> V_212 . V_213 = V_213 ;
while ( V_2 -> V_212 . V_214 != V_213 ) {
V_2 -> V_212 . V_214 ++ ;
V_2 -> V_212 . V_214 %= V_230 ;
V_214 = V_2 -> V_212 . V_214 << 1 ;
V_229 = F_66 ( V_2 -> V_212 . V_202 [ V_214 + 1 ] ) ;
V_39 = F_66 ( V_2 -> V_212 . V_202 [ V_214 ] ) ;
V_28 = V_229 & 0xf ;
if ( ( V_28 >= V_225 ) || ! ( V_2 -> V_231 & ( 1 << V_28 ) ) ) {
F_38 ( V_2 -> V_101 -> V_36 , L_9 ,
V_39 , V_229 ,
V_2 -> V_212 . V_214 , V_213 ) ;
F_104 () ;
} else if ( V_229 & V_232 )
F_107 ( V_2 -> V_176 , V_39 , V_229 ) ;
else if ( V_2 -> V_212 . V_215 [ V_28 ] ) {
V_2 -> V_212 . V_39 [ V_28 ] = V_39 ;
F_108 () ;
V_2 -> V_212 . V_215 [ V_28 ] -- ;
} else if ( F_109 () ) {
F_38 ( V_2 -> V_101 -> V_36 , L_10 ,
V_39 , V_229 ,
V_2 -> V_233 [ V_28 ] ) ;
}
}
}
static unsigned int F_110 ( struct V_175 * V_176 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
unsigned long V_12 ;
unsigned long V_234 ;
int V_235 = 0 ;
V_236:
V_12 = V_237 + F_111 ( 1000 ) ;
for ( V_234 = 0 ; ; V_234 ++ ) {
if ( V_2 -> V_238 || V_235 ) {
F_97 ( & V_2 -> V_104 ) ;
F_106 ( V_2 ) ;
F_101 ( & V_2 -> V_104 ) ;
}
if ( ! V_2 -> V_212 . V_215 [ V_28 ] ) {
F_112 () ;
V_176 -> V_239 = 0 ;
if ( ! V_235 )
V_2 -> V_240 = 0 ;
return V_2 -> V_212 . V_39 [ V_28 ] ;
}
if ( F_113 ( V_237 , V_12 ) )
break;
if ( V_176 -> V_241 || V_234 > 3000 )
F_114 ( 2 ) ;
else {
F_9 ( 10 ) ;
F_115 () ;
}
}
if ( V_176 -> V_242 )
return - 1 ;
if ( ! V_2 -> V_238 && V_2 -> V_240 < 2 ) {
F_54 ( V_2 -> V_101 -> V_36 ,
L_11 ,
V_2 -> V_233 [ V_28 ] ) ;
V_235 = 1 ;
V_2 -> V_240 ++ ;
goto V_236;
}
if ( ! V_2 -> V_238 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_12 ,
V_2 -> V_233 [ V_28 ] ) ;
V_2 -> V_238 = 1 ;
goto V_236;
}
if ( V_2 -> V_243 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_13 ,
V_2 -> V_233 [ V_28 ] ) ;
if ( V_2 -> V_75 -> V_244 ( V_2 ) &&
V_2 -> V_75 -> V_244 ( V_2 ) < 0 ) {
V_176 -> V_239 = 1 ;
return - 1 ;
}
goto V_236;
}
if ( V_2 -> V_245 ) {
return - 1 ;
}
V_176 -> V_239 = 1 ;
if ( V_176 -> V_246 && ! V_176 -> V_247 && ! V_176 -> V_248 ) {
V_176 -> V_247 = 1 ;
return - 1 ;
}
F_38 ( V_2 -> V_101 -> V_36 ,
L_14 ,
V_2 -> V_233 [ V_28 ] ) ;
V_2 -> V_249 = 1 ;
V_176 -> V_247 = 0 ;
F_102 ( V_2 ) ;
F_2 ( V_2 , V_250 , F_3 ( V_2 , V_250 ) & ~ V_251 ) ;
return - 1 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_12 = 50 ;
while ( V_12 -- ) {
if ( F_100 ( V_2 , V_252 ) & V_253 ) {
V_2 -> V_212 . V_39 [ V_28 ] = F_3 ( V_2 , V_254 ) ;
return 0 ;
}
F_9 ( 1 ) ;
}
if ( F_109 () )
F_54 ( V_2 -> V_101 -> V_36 , L_15 ,
F_100 ( V_2 , V_252 ) ) ;
V_2 -> V_212 . V_39 [ V_28 ] = - 1 ;
return - V_226 ;
}
static int F_117 ( struct V_175 * V_176 , V_26 V_11 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
unsigned int V_28 = F_103 ( V_11 ) ;
int V_12 = 50 ;
V_176 -> V_239 = 0 ;
while ( V_12 -- ) {
if ( ! ( ( F_100 ( V_2 , V_252 ) & V_255 ) ) ) {
F_99 ( V_2 , V_252 , F_100 ( V_2 , V_252 ) |
V_253 ) ;
F_2 ( V_2 , V_256 , V_11 ) ;
F_99 ( V_2 , V_252 , F_100 ( V_2 , V_252 ) |
V_255 ) ;
return F_116 ( V_2 , V_28 ) ;
}
F_9 ( 1 ) ;
}
if ( F_109 () )
F_54 ( V_2 -> V_101 -> V_36 ,
L_16 ,
F_100 ( V_2 , V_252 ) , V_11 ) ;
return - V_226 ;
}
static unsigned int F_118 ( struct V_175 * V_176 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
return V_2 -> V_212 . V_39 [ V_28 ] ;
}
static int F_119 ( struct V_175 * V_176 , unsigned int V_11 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
if ( V_2 -> V_257 )
return 0 ;
V_2 -> V_233 [ F_103 ( V_11 ) ] = V_11 ;
if ( V_2 -> V_249 )
return F_117 ( V_176 , V_11 ) ;
else
return F_105 ( V_176 , V_11 ) ;
}
static unsigned int F_120 ( struct V_175 * V_176 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
if ( V_2 -> V_257 )
return 0 ;
if ( V_2 -> V_249 )
return F_118 ( V_176 , V_28 ) ;
else
return F_110 ( V_176 , V_28 ) ;
}
static struct V_3 *
F_121 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 [ V_2 -> V_46 ] ;
}
static int F_122 ( struct V_175 * V_176 , unsigned int V_121 ,
unsigned int V_258 ,
struct V_81 * V_259 )
{
V_26 * V_27 ;
struct V_1 * V_2 = V_176 -> V_170 ;
struct V_3 * V_3 ;
int V_113 ;
V_3 = F_121 ( V_2 ) ;
F_17 ( V_3 ) ;
F_97 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_105 || V_3 -> V_260 ) {
F_101 ( & V_2 -> V_104 ) ;
V_113 = - V_110 ;
goto V_111;
}
V_3 -> V_115 = 0 ;
V_2 -> V_261 = * V_3 ;
V_3 -> V_260 = 1 ;
F_101 ( & V_2 -> V_104 ) ;
V_113 = V_2 -> V_75 -> V_197 ( V_2 , V_194 ,
V_258 , V_259 ) ;
if ( V_113 < 0 )
goto V_262;
V_3 -> V_20 = V_258 ;
V_3 -> V_93 = V_258 ;
V_3 -> V_22 = V_121 ;
F_8 ( V_2 , V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
V_3 -> V_24 = 0 ;
V_27 = ( V_26 * ) V_3 -> V_27 . V_95 ;
V_113 = F_30 ( V_2 , V_259 , V_3 , & V_27 , 0 , V_258 , 0 ) ;
if ( V_113 < 0 )
goto error;
F_10 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_3 -> V_16 ;
error:
V_2 -> V_75 -> V_263 ( V_2 , V_259 ) ;
V_262:
F_97 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_261 ;
V_3 -> V_260 = 0 ;
F_101 ( & V_2 -> V_104 ) ;
V_111:
F_19 ( V_3 ) ;
return V_113 ;
}
static void F_123 ( struct V_175 * V_176 , bool V_132 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
struct V_3 * V_3 = F_121 ( V_2 ) ;
if ( V_132 )
F_1 ( V_2 , V_3 ) ;
else
F_7 ( V_2 , V_3 ) ;
V_3 -> V_105 = V_132 ;
}
static void F_124 ( struct V_175 * V_176 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
struct V_3 * V_3 = F_121 ( V_2 ) ;
if ( ! V_82 -> V_95 || ! V_3 -> V_260 )
return;
F_17 ( V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
F_13 ( V_2 , V_3 , V_7 , 0 ) ;
V_3 -> V_20 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_22 = 0 ;
V_2 -> V_75 -> V_263 ( V_2 , V_82 ) ;
V_82 -> V_95 = NULL ;
F_97 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_261 ;
V_3 -> V_260 = 0 ;
F_101 ( & V_2 -> V_104 ) ;
F_19 ( V_3 ) ;
}
int F_125 ( struct V_1 * V_2 )
{
int V_37 , V_113 ;
struct V_264 * V_101 = V_2 -> V_101 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ ) {
F_126 ( & V_2 -> V_3 [ V_37 ] ) ;
V_113 = V_2 -> V_75 -> V_197 ( V_2 , V_198 ,
V_266 ,
& V_2 -> V_3 [ V_37 ] . V_27 ) ;
if ( V_113 < 0 ) {
F_38 ( V_101 -> V_36 , L_17 ) ;
return - V_184 ;
}
}
V_113 = V_2 -> V_75 -> V_197 ( V_2 , V_198 ,
V_2 -> V_265 * 8 , & V_2 -> V_14 ) ;
if ( V_113 < 0 ) {
F_38 ( V_101 -> V_36 , L_18 ) ;
return - V_184 ;
}
V_113 = F_95 ( V_2 ) ;
if ( V_113 < 0 )
return V_113 ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_3 ) {
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ )
if ( V_2 -> V_3 [ V_37 ] . V_27 . V_95 )
V_2 -> V_75 -> V_263 (
V_2 , & V_2 -> V_3 [ V_37 ] . V_27 ) ;
}
if ( V_2 -> V_200 . V_95 )
V_2 -> V_75 -> V_263 ( V_2 , & V_2 -> V_200 ) ;
if ( V_2 -> V_14 . V_95 )
V_2 -> V_75 -> V_263 ( V_2 , & V_2 -> V_14 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_2 ( V_2 , V_250 , F_3 ( V_2 , V_250 ) & ~ V_267 ) ;
V_12 = V_237 + F_111 ( 100 ) ;
while ( ( F_129 ( V_2 , V_250 ) & V_267 ) &&
F_130 ( V_237 , V_12 ) )
F_131 ( 500 , 1000 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_98 ( V_2 , V_250 , F_129 ( V_2 , V_250 ) | V_267 ) ;
V_12 = V_237 + F_111 ( 100 ) ;
while ( ! F_129 ( V_2 , V_250 ) &&
F_130 ( V_237 , V_12 ) )
F_131 ( 500 , 1000 ) ;
}
static int F_133 ( struct V_1 * V_2 , bool V_268 )
{
if ( ! V_268 )
goto V_269;
F_99 ( V_2 , V_270 , V_271 ) ;
F_128 ( V_2 ) ;
F_131 ( 500 , 1000 ) ;
F_132 ( V_2 ) ;
F_131 ( 1000 , 1200 ) ;
V_269:
if ( ! F_129 ( V_2 , V_250 ) ) {
F_54 ( V_2 -> V_101 -> V_36 , L_19 ) ;
return - V_110 ;
}
if ( ! V_2 -> V_249 )
F_2 ( V_2 , V_250 , F_3 ( V_2 , V_250 ) |
V_251 ) ;
if ( ! V_2 -> V_231 ) {
V_2 -> V_231 = F_100 ( V_2 , V_270 ) ;
F_54 ( V_2 -> V_101 -> V_36 , L_20 ,
V_2 -> V_231 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) |
V_272 | V_273 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) &
~ V_9 ) ;
}
F_98 ( V_2 , V_5 , 0 ) ;
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) &
~ ( V_272 | V_273 ) ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
}
F_99 ( V_2 , V_270 , V_271 ) ;
F_98 ( V_2 , V_274 , V_275 ) ;
F_2 ( V_2 , V_276 , V_272 | V_277 ) ;
}
void F_137 ( struct V_1 * V_2 , bool V_268 )
{
if ( V_2 -> V_278 )
return;
F_133 ( V_2 , V_268 ) ;
F_136 ( V_2 ) ;
F_134 ( V_2 ) ;
if ( ! V_2 -> V_249 )
F_96 ( V_2 ) ;
F_2 ( V_2 , V_32 , ( V_26 ) V_2 -> V_14 . V_28 ) ;
F_2 ( V_2 , V_279 , F_15 ( V_2 -> V_14 . V_28 ) ) ;
V_2 -> V_278 = 1 ;
}
void F_138 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_278 )
return;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
F_102 ( V_2 ) ;
F_2 ( V_2 , V_32 , 0 ) ;
F_2 ( V_2 , V_279 , 0 ) ;
V_2 -> V_278 = 0 ;
}
T_5 F_139 ( int V_280 , void * V_281 )
{
struct V_1 * V_2 = V_281 ;
struct V_3 * V_3 ;
V_26 V_282 ;
T_6 V_283 ;
int V_37 ;
#ifdef F_140
if ( V_2 -> V_52 & V_284 )
if ( ! F_141 ( V_2 -> V_101 -> V_36 ) )
return V_285 ;
#endif
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_257 ) {
F_62 ( & V_2 -> V_104 ) ;
return V_285 ;
}
V_282 = F_3 ( V_2 , V_276 ) ;
if ( V_282 == 0 || V_282 == 0xffffffff ) {
F_62 ( & V_2 -> V_104 ) ;
return V_285 ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ ) {
V_3 = & V_2 -> V_3 [ V_37 ] ;
if ( V_282 & V_3 -> V_286 ) {
V_283 = F_5 ( V_2 , V_3 , V_10 ) ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
if ( ! V_3 -> V_35 || ! V_3 -> V_105 ||
! ( V_283 & V_287 ) )
continue;
if ( ! V_2 -> V_75 -> V_288 ||
V_2 -> V_75 -> V_288 ( V_2 , V_3 ) ) {
F_62 ( & V_2 -> V_104 ) ;
F_142 ( V_3 -> V_35 ) ;
F_61 ( & V_2 -> V_104 ) ;
}
}
}
V_282 = F_129 ( V_2 , V_274 ) ;
if ( V_282 & V_275 ) {
if ( V_282 & V_289 ) {
if ( V_2 -> V_52 & V_290 )
F_9 ( 80 ) ;
F_106 ( V_2 ) ;
}
F_98 ( V_2 , V_274 , V_275 ) ;
}
F_62 ( & V_2 -> V_104 ) ;
return V_291 ;
}
static int F_143 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_129 = ( V_28 << 28 ) | ( V_292 << 20 ) |
( V_293 << 8 ) | V_294 ;
unsigned int V_39 ;
F_40 ( & V_2 -> V_176 -> V_295 ) ;
V_2 -> V_245 = 1 ;
F_119 ( V_2 -> V_176 , V_129 ) ;
V_39 = F_120 ( V_2 -> V_176 , V_28 ) ;
V_2 -> V_245 = 0 ;
F_44 ( & V_2 -> V_176 -> V_295 ) ;
if ( V_39 == - 1 )
return - V_226 ;
F_54 ( V_2 -> V_101 -> V_36 , L_21 , V_28 ) ;
return 0 ;
}
static void F_144 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
V_176 -> V_248 = 1 ;
F_138 ( V_2 ) ;
F_137 ( V_2 , true ) ;
#ifdef F_140
if ( V_2 -> V_278 ) {
struct V_57 * V_296 ;
F_88 (p, &chip->pcm_list, list)
F_145 ( V_296 -> V_41 ) ;
F_146 ( V_2 -> V_176 ) ;
F_147 ( V_2 -> V_176 ) ;
}
#endif
V_176 -> V_248 = 0 ;
}
static void F_148 ( struct V_175 * V_176 , bool V_297 )
{
struct V_1 * V_2 = V_176 -> V_170 ;
if ( ! ( V_2 -> V_52 & V_284 ) )
return;
if ( V_297 )
F_149 ( V_2 -> V_101 -> V_36 ) ;
else
F_150 ( V_2 -> V_101 -> V_36 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned int V_298 ;
if ( ! V_2 -> V_299 )
return 0 ;
V_37 = V_2 -> V_299 [ V_2 -> V_97 ] ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 < 50 || V_37 > 60000 )
V_298 = 0 ;
else
V_298 = F_111 ( V_37 ) ;
if ( V_298 == 0 )
F_36 ( V_2 -> V_101 -> V_36 ,
L_22 , V_37 ) ;
return V_298 ;
}
int F_152 ( struct V_1 * V_2 , const char * V_300 ,
unsigned int V_301 ,
int * V_302 )
{
struct V_303 V_304 ;
int V_305 , V_306 , V_113 ;
memset ( & V_304 , 0 , sizeof( V_304 ) ) ;
V_304 . V_170 = V_2 ;
V_304 . V_307 = V_300 ;
V_304 . V_308 = V_2 -> V_308 ;
V_304 . V_75 . V_309 = F_119 ;
V_304 . V_75 . V_310 = F_120 ;
V_304 . V_75 . V_311 = F_87 ;
V_304 . V_75 . V_312 = F_144 ;
#ifdef F_140
V_304 . V_313 = V_302 ;
V_304 . V_75 . V_314 = F_148 ;
#endif
#ifdef F_153
V_304 . V_75 . V_315 = F_122 ;
V_304 . V_75 . V_316 = F_123 ;
V_304 . V_75 . V_317 = F_124 ;
#endif
V_113 = F_154 ( V_2 -> V_101 , & V_304 , & V_2 -> V_176 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_2 -> V_52 & V_318 ) {
F_54 ( V_2 -> V_101 -> V_36 , L_23 ) ;
V_2 -> V_176 -> V_241 = 1 ;
}
V_306 = 0 ;
if ( ! V_301 )
V_301 = V_319 ;
for ( V_305 = 0 ; V_305 < V_301 ; V_305 ++ ) {
if ( ( V_2 -> V_231 & ( 1 << V_305 ) ) & V_2 -> V_320 ) {
if ( F_143 ( V_2 , V_305 ) < 0 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_24 , V_305 ) ;
V_2 -> V_231 &= ~ ( 1 << V_305 ) ;
F_138 ( V_2 ) ;
F_137 ( V_2 , true ) ;
}
}
}
if ( V_2 -> V_52 & V_321 ) {
F_54 ( V_2 -> V_101 -> V_36 , L_25 ) ;
V_2 -> V_176 -> V_322 = 1 ;
V_2 -> V_176 -> V_246 = 1 ;
}
for ( V_305 = 0 ; V_305 < V_301 ; V_305 ++ ) {
if ( ( V_2 -> V_231 & ( 1 << V_305 ) ) & V_2 -> V_320 ) {
struct V_177 * V_77 ;
V_113 = F_155 ( V_2 -> V_176 , V_305 , & V_77 ) ;
if ( V_113 < 0 )
continue;
V_77 -> V_323 = F_151 ( V_2 ) ;
V_77 -> V_324 = V_2 -> V_324 ;
V_306 ++ ;
}
}
if ( ! V_306 ) {
F_38 ( V_2 -> V_101 -> V_36 , L_26 ) ;
return - V_325 ;
}
return 0 ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_177 * V_77 ;
F_88 (codec, &chip->bus->codec_list, list) {
F_157 ( V_77 ) ;
}
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
return F_159 ( V_2 -> V_176 ) ;
}
static bool F_160 ( struct V_1 * V_2 , unsigned char V_6 )
{
return ( V_6 >= V_2 -> V_48 &&
V_6 < V_2 -> V_48 + V_2 -> V_49 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
int V_37 ;
int V_326 = 0 ;
int V_327 = 0 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_265 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
V_3 -> V_14 = ( V_26 V_328 * ) ( V_2 -> V_14 . V_95 + V_37 * 8 ) ;
V_3 -> V_329 = V_2 -> V_330 + ( 0x20 * V_37 + 0x80 ) ;
V_3 -> V_286 = 1 << V_37 ;
V_3 -> V_6 = V_37 ;
if ( V_2 -> V_52 & V_331 )
V_3 -> V_16 =
F_160 ( V_2 , V_37 ) ?
++ V_326 :
++ V_327 ;
else
V_3 -> V_16 = V_37 + 1 ;
}
return 0 ;
}
static int F_162 ( struct V_332 * V_333 , unsigned long V_334 , void * V_202 )
{
struct V_1 * V_2 = F_22 ( V_333 , struct V_1 , V_335 ) ;
F_163 ( V_2 -> V_176 ) ;
F_138 ( V_2 ) ;
return V_336 ;
}
void F_164 ( struct V_1 * V_2 )
{
V_2 -> V_335 . V_337 = F_162 ;
F_165 ( & V_2 -> V_335 ) ;
}
void F_166 ( struct V_1 * V_2 )
{
if ( V_2 -> V_335 . V_337 )
F_167 ( & V_2 -> V_335 ) ;
}
