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
return F_11 ( V_2 , V_3 , V_148 ) ;
}
unsigned int F_64 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return F_65 ( * V_3 -> V_14 ) ;
}
unsigned int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
unsigned int V_149 ;
int V_44 = V_35 -> V_44 ;
int V_150 = 0 ;
if ( V_2 -> V_30 [ V_44 ] )
V_149 = V_2 -> V_30 [ V_44 ] ( V_2 , V_3 ) ;
else
V_149 = F_64 ( V_2 , V_3 ) ;
if ( V_149 >= V_3 -> V_20 )
V_149 = 0 ;
if ( V_35 -> V_78 ) {
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_44 ] ;
if ( V_2 -> V_76 [ V_44 ] )
V_150 += V_2 -> V_76 [ V_44 ] ( V_2 , V_3 , V_149 ) ;
if ( V_72 -> V_75 . V_76 )
V_150 += V_72 -> V_75 . V_76 ( V_72 , V_58 -> V_77 ,
V_35 ) ;
V_35 -> V_78 -> V_150 = V_150 ;
}
F_67 ( V_2 , V_3 , V_149 , V_150 ) ;
return V_149 ;
}
static T_4 F_68 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_25 ( V_35 ) ;
return F_69 ( V_35 -> V_78 ,
F_66 ( V_2 , V_3 ) ) ;
}
static int F_70 ( struct V_34 * V_35 ,
struct V_151 * V_152 )
{
struct V_3 * V_3 = F_25 ( V_35 ) ;
T_2 V_65 ;
V_65 = F_71 ( & V_3 -> V_64 ) ;
V_65 = F_29 ( V_65 , 3 ) ;
V_65 = F_28 ( V_35 , V_65 ) ;
* V_152 = F_72 ( V_65 ) ;
return 0 ;
}
static int F_73 ( struct V_34 * V_35 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_71 * V_72 = V_58 -> V_72 [ V_35 -> V_44 ] ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 ;
struct V_99 * V_78 = V_35 -> V_78 ;
unsigned long V_102 ;
int V_113 ;
int V_153 ;
F_40 ( & V_2 -> V_103 ) ;
V_3 = F_16 ( V_2 , V_35 ) ;
if ( V_3 == NULL ) {
F_44 ( & V_2 -> V_103 ) ;
return - V_110 ;
}
V_78 -> V_154 = V_155 ;
V_78 -> V_154 . V_156 = V_72 -> V_156 ;
V_78 -> V_154 . V_157 = V_72 -> V_157 ;
V_78 -> V_154 . V_158 = V_72 -> V_158 ;
V_78 -> V_154 . V_159 = V_72 -> V_159 ;
F_74 ( V_78 ) ;
F_75 ( V_78 , V_160 ) ;
F_76 ( V_78 , V_161 ,
20 ,
178000000 ) ;
if ( V_2 -> V_162 )
V_153 = 128 ;
else
V_153 = 4 ;
F_77 ( V_78 , 0 , V_163 ,
V_153 ) ;
F_77 ( V_78 , 0 , V_164 ,
V_153 ) ;
F_78 ( V_58 -> V_77 ) ;
V_113 = V_72 -> V_75 . V_165 ( V_72 , V_58 -> V_77 , V_35 ) ;
if ( V_113 < 0 ) {
F_20 ( V_3 ) ;
F_43 ( V_58 -> V_77 ) ;
F_44 ( & V_2 -> V_103 ) ;
return V_113 ;
}
F_74 ( V_78 ) ;
if ( F_79 ( ! V_78 -> V_154 . V_156 ) ||
F_79 ( ! V_78 -> V_154 . V_157 ) ||
F_79 ( ! V_78 -> V_154 . V_158 ) ||
F_79 ( ! V_78 -> V_154 . V_159 ) ) {
F_20 ( V_3 ) ;
V_72 -> V_75 . V_106 ( V_72 , V_58 -> V_77 , V_35 ) ;
F_43 ( V_58 -> V_77 ) ;
F_44 ( & V_2 -> V_103 ) ;
return - V_89 ;
}
if ( V_35 -> V_44 == V_80 )
V_78 -> V_154 . V_166 &= ~ V_167 ;
F_41 ( & V_2 -> V_104 , V_102 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_105 = 0 ;
F_42 ( & V_2 -> V_104 , V_102 ) ;
V_78 -> V_168 = V_3 ;
F_80 ( V_35 ) ;
F_44 ( & V_2 -> V_103 ) ;
return 0 ;
}
static int F_81 ( struct V_34 * V_35 ,
struct V_169 * V_95 )
{
struct V_57 * V_58 = F_23 ( V_35 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
if ( V_2 -> V_75 -> V_170 )
V_2 -> V_75 -> V_170 ( V_35 , V_95 ) ;
return F_82 ( V_35 , V_95 ) ;
}
static void F_83 ( struct V_171 * V_41 )
{
struct V_57 * V_58 = V_41 -> V_168 ;
if ( V_58 ) {
F_84 ( & V_58 -> V_172 ) ;
F_85 ( V_58 ) ;
}
}
static int F_86 ( struct V_173 * V_174 , struct V_175 * V_77 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
struct V_171 * V_41 ;
struct V_57 * V_58 ;
int V_178 = V_177 -> V_42 ;
unsigned int V_85 ;
int V_130 , V_113 ;
F_87 (apcm, &chip->pcm_list, list) {
if ( V_58 -> V_41 -> V_42 == V_178 ) {
F_38 ( V_2 -> V_101 -> V_36 , L_5 ,
V_178 ) ;
return - V_110 ;
}
}
V_113 = F_88 ( V_2 -> V_101 , V_177 -> V_179 , V_178 ,
V_177 -> V_44 [ V_45 ] . V_180 ,
V_177 -> V_44 [ V_80 ] . V_180 ,
& V_41 ) ;
if ( V_113 < 0 )
return V_113 ;
F_89 ( V_41 -> V_179 , V_177 -> V_179 , sizeof( V_41 -> V_179 ) ) ;
V_58 = F_90 ( sizeof( * V_58 ) , V_181 ) ;
if ( V_58 == NULL )
return - V_182 ;
V_58 -> V_2 = V_2 ;
V_58 -> V_41 = V_41 ;
V_58 -> V_77 = V_77 ;
V_41 -> V_168 = V_58 ;
V_41 -> V_183 = F_83 ;
if ( V_177 -> V_184 == V_185 )
V_41 -> V_186 = V_187 ;
F_91 ( & V_58 -> V_172 , & V_2 -> V_188 ) ;
V_177 -> V_41 = V_41 ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ ) {
V_58 -> V_72 [ V_130 ] = & V_177 -> V_44 [ V_130 ] ;
if ( V_177 -> V_44 [ V_130 ] . V_180 )
F_92 ( V_41 , V_130 , & V_189 ) ;
}
V_85 = V_190 * 1024 ;
if ( V_85 > V_191 )
V_85 = V_191 ;
F_93 ( V_41 , V_192 ,
V_2 -> V_101 -> V_36 ,
V_85 , V_191 ) ;
V_41 -> V_36 = & V_77 -> V_36 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_113 ;
V_113 = V_2 -> V_75 -> V_193 ( V_2 , V_194 ,
V_195 , & V_2 -> V_196 ) ;
if ( V_113 < 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_6 ) ;
return V_113 ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_12 ;
F_96 ( & V_2 -> V_104 ) ;
V_2 -> V_197 . V_28 = V_2 -> V_196 . V_28 ;
V_2 -> V_197 . V_198 = ( V_26 * ) V_2 -> V_196 . V_95 ;
F_2 ( V_2 , V_199 , ( V_26 ) V_2 -> V_197 . V_28 ) ;
F_2 ( V_2 , V_200 , F_15 ( V_2 -> V_197 . V_28 ) ) ;
F_97 ( V_2 , V_201 , 0x02 ) ;
F_98 ( V_2 , V_202 , 0 ) ;
F_98 ( V_2 , V_203 , V_204 ) ;
if ( ! ( V_2 -> V_52 & V_205 ) ) {
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( ( F_99 ( V_2 , V_203 ) & V_204 ) == V_204 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_7 ,
F_99 ( V_2 , V_203 ) ) ;
F_98 ( V_2 , V_203 , 0 ) ;
for ( V_12 = 1000 ; V_12 > 0 ; V_12 -- ) {
if ( F_99 ( V_2 , V_203 ) == 0 )
break;
F_9 ( 1 ) ;
}
if ( V_12 <= 0 )
F_38 ( V_2 -> V_101 -> V_36 , L_8 ,
F_99 ( V_2 , V_203 ) ) ;
}
F_97 ( V_2 , V_206 , V_207 ) ;
V_2 -> V_208 . V_28 = V_2 -> V_196 . V_28 + 2048 ;
V_2 -> V_208 . V_198 = ( V_26 * ) ( V_2 -> V_196 . V_95 + 2048 ) ;
V_2 -> V_208 . V_209 = V_2 -> V_208 . V_210 = 0 ;
memset ( V_2 -> V_208 . V_211 , 0 , sizeof( V_2 -> V_208 . V_211 ) ) ;
F_2 ( V_2 , V_212 , ( V_26 ) V_2 -> V_208 . V_28 ) ;
F_2 ( V_2 , V_213 , F_15 ( V_2 -> V_208 . V_28 ) ) ;
F_97 ( V_2 , V_214 , 0x02 ) ;
F_98 ( V_2 , V_215 , V_216 ) ;
if ( V_2 -> V_52 & V_128 )
F_98 ( V_2 , V_217 , 0xc0 ) ;
else
F_98 ( V_2 , V_217 , 1 ) ;
F_97 ( V_2 , V_218 , V_219 | V_220 ) ;
F_100 ( & V_2 -> V_104 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_96 ( & V_2 -> V_104 ) ;
F_97 ( V_2 , V_218 , 0 ) ;
F_97 ( V_2 , V_206 , 0 ) ;
F_100 ( & V_2 -> V_104 ) ;
}
static unsigned int F_102 ( V_26 V_129 )
{
unsigned int V_28 = V_129 >> 28 ;
if ( V_28 >= V_221 ) {
F_103 () ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_104 ( struct V_173 * V_174 , V_26 V_11 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
unsigned int V_28 = F_102 ( V_11 ) ;
unsigned int V_209 , V_210 ;
F_96 ( & V_2 -> V_104 ) ;
V_209 = F_99 ( V_2 , V_202 ) ;
if ( V_209 == 0xffff ) {
F_100 ( & V_2 -> V_104 ) ;
return - V_222 ;
}
V_209 ++ ;
V_209 %= V_223 ;
V_210 = F_99 ( V_2 , V_203 ) ;
if ( V_209 == V_210 ) {
F_100 ( & V_2 -> V_104 ) ;
return - V_224 ;
}
V_2 -> V_208 . V_211 [ V_28 ] ++ ;
V_2 -> V_197 . V_198 [ V_209 ] = F_32 ( V_11 ) ;
F_98 ( V_2 , V_202 , V_209 ) ;
F_100 ( & V_2 -> V_104 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
unsigned int V_210 , V_209 ;
unsigned int V_28 ;
V_26 V_39 , V_225 ;
V_209 = F_99 ( V_2 , V_215 ) ;
if ( V_209 == 0xffff ) {
return;
}
if ( V_209 == V_2 -> V_208 . V_209 )
return;
V_2 -> V_208 . V_209 = V_209 ;
while ( V_2 -> V_208 . V_210 != V_209 ) {
V_2 -> V_208 . V_210 ++ ;
V_2 -> V_208 . V_210 %= V_226 ;
V_210 = V_2 -> V_208 . V_210 << 1 ;
V_225 = F_65 ( V_2 -> V_208 . V_198 [ V_210 + 1 ] ) ;
V_39 = F_65 ( V_2 -> V_208 . V_198 [ V_210 ] ) ;
V_28 = V_225 & 0xf ;
if ( ( V_28 >= V_221 ) || ! ( V_2 -> V_227 & ( 1 << V_28 ) ) ) {
F_38 ( V_2 -> V_101 -> V_36 , L_9 ,
V_39 , V_225 ,
V_2 -> V_208 . V_210 , V_209 ) ;
F_103 () ;
} else if ( V_225 & V_228 )
F_106 ( V_2 -> V_174 , V_39 , V_225 ) ;
else if ( V_2 -> V_208 . V_211 [ V_28 ] ) {
V_2 -> V_208 . V_39 [ V_28 ] = V_39 ;
F_107 () ;
V_2 -> V_208 . V_211 [ V_28 ] -- ;
} else if ( F_108 () ) {
F_38 ( V_2 -> V_101 -> V_36 , L_10 ,
V_39 , V_225 ,
V_2 -> V_229 [ V_28 ] ) ;
}
}
}
static unsigned int F_109 ( struct V_173 * V_174 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
unsigned long V_12 ;
unsigned long V_230 ;
int V_231 = 0 ;
V_232:
V_12 = V_233 + F_110 ( 1000 ) ;
for ( V_230 = 0 ; ; V_230 ++ ) {
if ( V_2 -> V_234 || V_231 ) {
F_96 ( & V_2 -> V_104 ) ;
F_105 ( V_2 ) ;
F_100 ( & V_2 -> V_104 ) ;
}
if ( ! V_2 -> V_208 . V_211 [ V_28 ] ) {
F_111 () ;
V_174 -> V_235 = 0 ;
if ( ! V_231 )
V_2 -> V_236 = 0 ;
return V_2 -> V_208 . V_39 [ V_28 ] ;
}
if ( F_112 ( V_233 , V_12 ) )
break;
if ( V_174 -> V_237 || V_230 > 3000 )
F_113 ( 2 ) ;
else {
F_9 ( 10 ) ;
F_114 () ;
}
}
if ( ! V_174 -> V_238 )
return - 1 ;
if ( ! V_2 -> V_234 && V_2 -> V_236 < 2 ) {
F_54 ( V_2 -> V_101 -> V_36 ,
L_11 ,
V_2 -> V_229 [ V_28 ] ) ;
V_231 = 1 ;
V_2 -> V_236 ++ ;
goto V_232;
}
if ( ! V_2 -> V_234 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_12 ,
V_2 -> V_229 [ V_28 ] ) ;
V_2 -> V_234 = 1 ;
goto V_232;
}
if ( V_2 -> V_239 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_13 ,
V_2 -> V_229 [ V_28 ] ) ;
if ( V_2 -> V_75 -> V_240 ( V_2 ) &&
V_2 -> V_75 -> V_240 ( V_2 ) < 0 ) {
V_174 -> V_235 = 1 ;
return - 1 ;
}
goto V_232;
}
if ( V_2 -> V_241 ) {
return - 1 ;
}
V_174 -> V_235 = 1 ;
if ( V_174 -> V_242 && ! V_174 -> V_243 && ! V_174 -> V_244 ) {
V_174 -> V_243 = 1 ;
return - 1 ;
}
F_38 ( V_2 -> V_101 -> V_36 ,
L_14 ,
V_2 -> V_229 [ V_28 ] ) ;
V_2 -> V_245 = 1 ;
V_174 -> V_243 = 0 ;
F_101 ( V_2 ) ;
F_2 ( V_2 , V_246 , F_3 ( V_2 , V_246 ) & ~ V_247 ) ;
return - 1 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_12 = 50 ;
while ( V_12 -- ) {
if ( F_99 ( V_2 , V_248 ) & V_249 ) {
V_2 -> V_208 . V_39 [ V_28 ] = F_3 ( V_2 , V_250 ) ;
return 0 ;
}
F_9 ( 1 ) ;
}
if ( F_108 () )
F_54 ( V_2 -> V_101 -> V_36 , L_15 ,
F_99 ( V_2 , V_248 ) ) ;
V_2 -> V_208 . V_39 [ V_28 ] = - 1 ;
return - V_222 ;
}
static int F_116 ( struct V_173 * V_174 , V_26 V_11 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
unsigned int V_28 = F_102 ( V_11 ) ;
int V_12 = 50 ;
V_174 -> V_235 = 0 ;
while ( V_12 -- ) {
if ( ! ( ( F_99 ( V_2 , V_248 ) & V_251 ) ) ) {
F_98 ( V_2 , V_248 , F_99 ( V_2 , V_248 ) |
V_249 ) ;
F_2 ( V_2 , V_252 , V_11 ) ;
F_98 ( V_2 , V_248 , F_99 ( V_2 , V_248 ) |
V_251 ) ;
return F_115 ( V_2 , V_28 ) ;
}
F_9 ( 1 ) ;
}
if ( F_108 () )
F_54 ( V_2 -> V_101 -> V_36 ,
L_16 ,
F_99 ( V_2 , V_248 ) , V_11 ) ;
return - V_222 ;
}
static unsigned int F_117 ( struct V_173 * V_174 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
return V_2 -> V_208 . V_39 [ V_28 ] ;
}
static int F_118 ( struct V_173 * V_174 , unsigned int V_11 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
if ( V_2 -> V_253 )
return 0 ;
V_2 -> V_229 [ F_102 ( V_11 ) ] = V_11 ;
if ( V_2 -> V_245 )
return F_116 ( V_174 , V_11 ) ;
else
return F_104 ( V_174 , V_11 ) ;
}
static unsigned int F_119 ( struct V_173 * V_174 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
if ( V_2 -> V_253 )
return 0 ;
if ( V_2 -> V_245 )
return F_117 ( V_174 , V_28 ) ;
else
return F_109 ( V_174 , V_28 ) ;
}
static struct V_3 *
F_120 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 [ V_2 -> V_46 ] ;
}
static int F_121 ( struct V_173 * V_174 , unsigned int V_121 ,
unsigned int V_254 ,
struct V_81 * V_255 )
{
V_26 * V_27 ;
struct V_1 * V_2 = V_174 -> V_168 ;
struct V_3 * V_3 ;
int V_113 ;
V_3 = F_120 ( V_2 ) ;
F_17 ( V_3 ) ;
F_96 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_105 || V_3 -> V_256 ) {
F_100 ( & V_2 -> V_104 ) ;
V_113 = - V_110 ;
goto V_111;
}
V_3 -> V_115 = 0 ;
V_2 -> V_257 = * V_3 ;
V_3 -> V_256 = 1 ;
F_100 ( & V_2 -> V_104 ) ;
V_113 = V_2 -> V_75 -> V_193 ( V_2 , V_192 ,
V_254 , V_255 ) ;
if ( V_113 < 0 )
goto V_258;
V_3 -> V_20 = V_254 ;
V_3 -> V_93 = V_254 ;
V_3 -> V_22 = V_121 ;
F_8 ( V_2 , V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
V_3 -> V_24 = 0 ;
V_27 = ( V_26 * ) V_3 -> V_27 . V_95 ;
V_113 = F_30 ( V_2 , V_255 , V_3 , & V_27 , 0 , V_254 , 0 ) ;
if ( V_113 < 0 )
goto error;
F_10 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_3 -> V_16 ;
error:
V_2 -> V_75 -> V_259 ( V_2 , V_255 ) ;
V_258:
F_96 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_257 ;
V_3 -> V_256 = 0 ;
F_100 ( & V_2 -> V_104 ) ;
V_111:
F_19 ( V_3 ) ;
return V_113 ;
}
static void F_122 ( struct V_173 * V_174 , bool V_132 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
struct V_3 * V_3 = F_120 ( V_2 ) ;
if ( V_132 )
F_1 ( V_2 , V_3 ) ;
else
F_7 ( V_2 , V_3 ) ;
V_3 -> V_105 = V_132 ;
}
static void F_123 ( struct V_173 * V_174 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
struct V_3 * V_3 = F_120 ( V_2 ) ;
if ( ! V_82 -> V_95 || ! V_3 -> V_256 )
return;
F_17 ( V_3 ) ;
F_13 ( V_2 , V_3 , V_25 , 0 ) ;
F_13 ( V_2 , V_3 , V_29 , 0 ) ;
F_13 ( V_2 , V_3 , V_7 , 0 ) ;
V_3 -> V_20 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_22 = 0 ;
V_2 -> V_75 -> V_259 ( V_2 , V_82 ) ;
V_82 -> V_95 = NULL ;
F_96 ( & V_2 -> V_104 ) ;
if ( V_3 -> V_50 )
* V_3 = V_2 -> V_257 ;
V_3 -> V_256 = 0 ;
F_100 ( & V_2 -> V_104 ) ;
F_19 ( V_3 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
int V_37 , V_113 ;
struct V_260 * V_101 = V_2 -> V_101 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ ) {
F_125 ( & V_2 -> V_3 [ V_37 ] ) ;
V_113 = V_2 -> V_75 -> V_193 ( V_2 , V_194 ,
V_262 ,
& V_2 -> V_3 [ V_37 ] . V_27 ) ;
if ( V_113 < 0 ) {
F_38 ( V_101 -> V_36 , L_17 ) ;
return - V_182 ;
}
}
V_113 = V_2 -> V_75 -> V_193 ( V_2 , V_194 ,
V_2 -> V_261 * 8 , & V_2 -> V_14 ) ;
if ( V_113 < 0 ) {
F_38 ( V_101 -> V_36 , L_18 ) ;
return - V_182 ;
}
V_113 = F_94 ( V_2 ) ;
if ( V_113 < 0 )
return V_113 ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_3 ) {
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ )
if ( V_2 -> V_3 [ V_37 ] . V_27 . V_95 )
V_2 -> V_75 -> V_259 (
V_2 , & V_2 -> V_3 [ V_37 ] . V_27 ) ;
}
if ( V_2 -> V_196 . V_95 )
V_2 -> V_75 -> V_259 ( V_2 , & V_2 -> V_196 ) ;
if ( V_2 -> V_14 . V_95 )
V_2 -> V_75 -> V_259 ( V_2 , & V_2 -> V_14 ) ;
}
void F_127 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_2 ( V_2 , V_246 , F_3 ( V_2 , V_246 ) & ~ V_263 ) ;
V_12 = V_233 + F_110 ( 100 ) ;
while ( ( F_128 ( V_2 , V_246 ) & V_263 ) &&
F_129 ( V_233 , V_12 ) )
F_130 ( 500 , 1000 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_97 ( V_2 , V_246 , F_128 ( V_2 , V_246 ) | V_263 ) ;
V_12 = V_233 + F_110 ( 100 ) ;
while ( ! F_128 ( V_2 , V_246 ) &&
F_129 ( V_233 , V_12 ) )
F_130 ( 500 , 1000 ) ;
}
static int F_132 ( struct V_1 * V_2 , bool V_264 )
{
if ( ! V_264 )
goto V_265;
F_98 ( V_2 , V_266 , V_267 ) ;
F_127 ( V_2 ) ;
F_130 ( 500 , 1000 ) ;
F_131 ( V_2 ) ;
F_130 ( 1000 , 1200 ) ;
V_265:
if ( ! F_128 ( V_2 , V_246 ) ) {
F_54 ( V_2 -> V_101 -> V_36 , L_19 ) ;
return - V_110 ;
}
if ( ! V_2 -> V_245 )
F_2 ( V_2 , V_246 , F_3 ( V_2 , V_246 ) |
V_247 ) ;
if ( ! V_2 -> V_227 ) {
V_2 -> V_227 = F_99 ( V_2 , V_266 ) ;
F_54 ( V_2 -> V_101 -> V_36 , L_20 ,
V_2 -> V_227 ) ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) |
V_268 | V_269 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_7 ,
F_5 ( V_2 , V_3 , V_7 ) &
~ V_9 ) ;
}
F_97 ( V_2 , V_5 , 0 ) ;
F_2 ( V_2 , V_5 , F_3 ( V_2 , V_5 ) &
~ ( V_268 | V_269 ) ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
}
F_98 ( V_2 , V_266 , V_267 ) ;
F_97 ( V_2 , V_270 , V_271 ) ;
F_2 ( V_2 , V_272 , V_268 | V_273 ) ;
}
void F_136 ( struct V_1 * V_2 , bool V_264 )
{
if ( V_2 -> V_274 )
return;
F_132 ( V_2 , V_264 ) ;
F_135 ( V_2 ) ;
F_133 ( V_2 ) ;
if ( ! V_2 -> V_245 )
F_95 ( V_2 ) ;
F_2 ( V_2 , V_32 , ( V_26 ) V_2 -> V_14 . V_28 ) ;
F_2 ( V_2 , V_275 , F_15 ( V_2 -> V_14 . V_28 ) ) ;
V_2 -> V_274 = 1 ;
}
void F_137 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_274 )
return;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_101 ( V_2 ) ;
F_2 ( V_2 , V_32 , 0 ) ;
F_2 ( V_2 , V_275 , 0 ) ;
V_2 -> V_274 = 0 ;
}
T_5 F_138 ( int V_276 , void * V_277 )
{
struct V_1 * V_2 = V_277 ;
struct V_3 * V_3 ;
V_26 V_278 ;
T_6 V_279 ;
int V_37 ;
#ifdef F_139
if ( V_2 -> V_52 & V_280 )
if ( ! F_140 ( V_2 -> V_101 -> V_36 ) )
return V_281 ;
#endif
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_253 ) {
F_62 ( & V_2 -> V_104 ) ;
return V_281 ;
}
V_278 = F_3 ( V_2 , V_272 ) ;
if ( V_278 == 0 || V_278 == 0xffffffff ) {
F_62 ( & V_2 -> V_104 ) ;
return V_281 ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ ) {
V_3 = & V_2 -> V_3 [ V_37 ] ;
if ( V_278 & V_3 -> V_282 ) {
V_279 = F_5 ( V_2 , V_3 , V_10 ) ;
F_4 ( V_2 , V_3 , V_10 , V_9 ) ;
if ( ! V_3 -> V_35 || ! V_3 -> V_105 ||
! ( V_279 & V_283 ) )
continue;
if ( ! V_2 -> V_75 -> V_284 ||
V_2 -> V_75 -> V_284 ( V_2 , V_3 ) ) {
F_62 ( & V_2 -> V_104 ) ;
F_141 ( V_3 -> V_35 ) ;
F_61 ( & V_2 -> V_104 ) ;
}
}
}
V_278 = F_128 ( V_2 , V_270 ) ;
if ( V_278 & V_271 ) {
if ( V_278 & V_285 ) {
if ( V_2 -> V_52 & V_286 )
F_9 ( 80 ) ;
F_105 ( V_2 ) ;
}
F_97 ( V_2 , V_270 , V_271 ) ;
}
F_62 ( & V_2 -> V_104 ) ;
return V_287 ;
}
static int F_142 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_129 = ( V_28 << 28 ) | ( V_288 << 20 ) |
( V_289 << 8 ) | V_290 ;
unsigned int V_39 ;
F_40 ( & V_2 -> V_174 -> V_291 ) ;
V_2 -> V_241 = 1 ;
F_118 ( V_2 -> V_174 , V_129 ) ;
V_39 = F_119 ( V_2 -> V_174 , V_28 ) ;
V_2 -> V_241 = 0 ;
F_44 ( & V_2 -> V_174 -> V_291 ) ;
if ( V_39 == - 1 )
return - V_222 ;
F_54 ( V_2 -> V_101 -> V_36 , L_21 , V_28 ) ;
return 0 ;
}
static void F_143 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
V_174 -> V_244 = 1 ;
F_137 ( V_2 ) ;
F_136 ( V_2 , true ) ;
#ifdef F_144
if ( V_2 -> V_274 ) {
struct V_57 * V_292 ;
F_87 (p, &chip->pcm_list, list)
F_145 ( V_292 -> V_41 ) ;
F_146 ( V_2 -> V_174 ) ;
F_147 ( V_2 -> V_174 ) ;
}
#endif
V_174 -> V_244 = 0 ;
}
static void F_148 ( struct V_173 * V_174 , bool V_293 )
{
struct V_1 * V_2 = V_174 -> V_168 ;
if ( ! ( V_2 -> V_52 & V_280 ) )
return;
if ( V_293 )
F_149 ( V_2 -> V_101 -> V_36 ) ;
else
F_150 ( V_2 -> V_101 -> V_36 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned int V_294 ;
if ( ! V_2 -> V_295 )
return 0 ;
V_37 = V_2 -> V_295 [ V_2 -> V_97 ] ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 < 50 || V_37 > 60000 )
V_294 = 0 ;
else
V_294 = F_110 ( V_37 ) ;
if ( V_294 == 0 )
F_36 ( V_2 -> V_101 -> V_36 ,
L_22 , V_37 ) ;
return V_294 ;
}
int F_152 ( struct V_1 * V_2 , const char * V_296 ,
unsigned int V_297 ,
int * V_298 )
{
struct V_299 V_300 ;
int V_301 , V_302 , V_113 ;
memset ( & V_300 , 0 , sizeof( V_300 ) ) ;
V_300 . V_168 = V_2 ;
V_300 . V_303 = V_296 ;
V_300 . V_304 = V_2 -> V_304 ;
V_300 . V_75 . V_305 = F_118 ;
V_300 . V_75 . V_306 = F_119 ;
V_300 . V_75 . V_307 = F_86 ;
V_300 . V_75 . V_308 = F_143 ;
#ifdef F_144
V_300 . V_309 = V_298 ;
V_300 . V_75 . V_310 = F_148 ;
#endif
#ifdef F_153
V_300 . V_75 . V_311 = F_121 ;
V_300 . V_75 . V_312 = F_122 ;
V_300 . V_75 . V_313 = F_123 ;
#endif
V_113 = F_154 ( V_2 -> V_101 , & V_300 , & V_2 -> V_174 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_2 -> V_52 & V_314 ) {
F_54 ( V_2 -> V_101 -> V_36 , L_23 ) ;
V_2 -> V_174 -> V_237 = 1 ;
}
V_302 = 0 ;
if ( ! V_297 )
V_297 = V_315 ;
for ( V_301 = 0 ; V_301 < V_297 ; V_301 ++ ) {
if ( ( V_2 -> V_227 & ( 1 << V_301 ) ) & V_2 -> V_316 ) {
if ( F_142 ( V_2 , V_301 ) < 0 ) {
F_36 ( V_2 -> V_101 -> V_36 ,
L_24 , V_301 ) ;
V_2 -> V_227 &= ~ ( 1 << V_301 ) ;
F_137 ( V_2 ) ;
F_136 ( V_2 , true ) ;
}
}
}
if ( V_2 -> V_52 & V_317 ) {
F_54 ( V_2 -> V_101 -> V_36 , L_25 ) ;
V_2 -> V_174 -> V_318 = 1 ;
V_2 -> V_174 -> V_242 = 1 ;
}
for ( V_301 = 0 ; V_301 < V_297 ; V_301 ++ ) {
if ( ( V_2 -> V_227 & ( 1 << V_301 ) ) & V_2 -> V_316 ) {
struct V_175 * V_77 ;
V_113 = F_155 ( V_2 -> V_174 , V_301 , & V_77 ) ;
if ( V_113 < 0 )
continue;
V_77 -> V_319 = F_151 ( V_2 ) ;
V_77 -> V_320 = V_2 -> V_320 ;
V_302 ++ ;
}
}
if ( ! V_302 ) {
F_38 ( V_2 -> V_101 -> V_36 , L_26 ) ;
return - V_321 ;
}
return 0 ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_175 * V_77 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_157 ( V_77 ) ;
}
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
return F_159 ( V_2 -> V_174 ) ;
}
int F_160 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_261 ; V_37 ++ ) {
struct V_3 * V_3 = & V_2 -> V_3 [ V_37 ] ;
V_3 -> V_14 = ( V_26 V_322 * ) ( V_2 -> V_14 . V_95 + V_37 * 8 ) ;
V_3 -> V_323 = V_2 -> V_324 + ( 0x20 * V_37 + 0x80 ) ;
V_3 -> V_282 = 1 << V_37 ;
V_3 -> V_6 = V_37 ;
V_3 -> V_16 = V_37 + 1 ;
}
return 0 ;
}
static int F_161 ( struct V_325 * V_326 , unsigned long V_327 , void * V_198 )
{
struct V_1 * V_2 = F_22 ( V_326 , struct V_1 , V_328 ) ;
F_162 ( V_2 -> V_174 ) ;
F_137 ( V_2 ) ;
return V_329 ;
}
void F_163 ( struct V_1 * V_2 )
{
V_2 -> V_328 . V_330 = F_161 ;
F_164 ( & V_2 -> V_328 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
if ( V_2 -> V_328 . V_330 )
F_166 ( & V_2 -> V_328 ) ;
}
