static unsigned char F_1 ( unsigned char V_1 )
{
return V_1 >> 3 ;
}
static unsigned char F_2 ( unsigned char V_1 )
{
return 1u << ( V_1 & 0x7 ) ;
}
static unsigned char F_3 ( unsigned char V_2 )
{
return V_2 ;
}
static unsigned char F_4 ( unsigned char V_1 )
{
return V_1 > V_3 ;
}
static unsigned char F_5 ( unsigned char V_1 )
{
return ( V_1 > V_3 ) ?
1u << ( V_1 - V_4 ) : 1u << V_1 ;
}
static unsigned char F_6 ( unsigned char V_2 )
{
return V_5 [ V_2 ] ;
}
static int F_7 ( struct V_6 * V_7 , T_1 V_2 )
{
int V_8 = F_8 ( V_7 , V_2 ) ;
if ( V_8 < 0 )
F_9 ( & V_7 -> V_9 , L_1 ) ;
return V_8 ;
}
static int F_10 ( struct V_6 * V_7 , T_1 V_2 , T_1 V_10 )
{
return F_11 ( V_7 , V_2 , V_10 ) ;
}
static int F_12 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_14 * V_15 = F_13 ( V_12 , struct V_14 , V_16 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_17 ( V_15 -> V_19 [ V_13 ] ) ;
unsigned int V_20 = V_15 -> V_18 -> V_20 ( V_15 -> V_19 [ V_13 ] ) ;
return ! ! ( F_7 ( V_15 -> V_7 ,
V_15 -> V_18 -> V_2 ( V_21 ) + V_17 ) &
V_20 ) ;
}
static void F_14 ( struct V_11 * V_12 ,
unsigned V_13 , int V_10 )
{
struct V_14 * V_15 = F_13 ( V_12 , struct V_14 , V_16 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_17 ( V_15 -> V_19 [ V_13 ] ) ;
unsigned int V_20 = V_15 -> V_18 -> V_20 ( V_15 -> V_19 [ V_13 ] ) ;
F_15 ( & V_15 -> V_22 ) ;
if ( V_10 )
V_15 -> V_23 [ V_17 ] |= V_20 ;
else
V_15 -> V_23 [ V_17 ] &= ~ V_20 ;
F_10 ( V_15 -> V_7 , V_15 -> V_18 -> V_2 ( V_24 ) +
V_17 , V_15 -> V_23 [ V_17 ] ) ;
F_16 ( & V_15 -> V_22 ) ;
}
static int F_17 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_14 * V_15 = F_13 ( V_12 , struct V_14 , V_16 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_17 ( V_15 -> V_19 [ V_13 ] ) ;
unsigned int V_20 = V_15 -> V_18 -> V_20 ( V_15 -> V_19 [ V_13 ] ) ;
int V_8 ;
F_15 ( & V_15 -> V_22 ) ;
V_15 -> V_25 [ V_17 ] &= ~ V_20 ;
V_8 = F_10 ( V_15 -> V_7 ,
V_15 -> V_18 -> V_2 ( V_26 ) + V_17 ,
V_15 -> V_25 [ V_17 ] ) ;
F_16 ( & V_15 -> V_22 ) ;
return V_8 ;
}
static int F_18 ( struct V_11 * V_12 ,
unsigned V_13 , int V_10 )
{
struct V_14 * V_15 = F_13 ( V_12 , struct V_14 , V_16 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_17 ( V_15 -> V_19 [ V_13 ] ) ;
unsigned int V_20 = V_15 -> V_18 -> V_20 ( V_15 -> V_19 [ V_13 ] ) ;
int V_8 ;
F_15 ( & V_15 -> V_22 ) ;
V_15 -> V_25 [ V_17 ] |= V_20 ;
if ( V_10 )
V_15 -> V_23 [ V_17 ] |= V_20 ;
else
V_15 -> V_23 [ V_17 ] &= ~ V_20 ;
V_8 = F_10 ( V_15 -> V_7 , V_15 -> V_18 -> V_2 ( V_24 )
+ V_17 , V_15 -> V_23 [ V_17 ] ) ;
V_8 |= F_10 ( V_15 -> V_7 ,
V_15 -> V_18 -> V_2 ( V_26 ) + V_17 ,
V_15 -> V_25 [ V_17 ] ) ;
F_16 ( & V_15 -> V_22 ) ;
return V_8 ;
}
static int T_2 F_19 ( struct V_14 * V_15 ,
const struct V_27 * V_28 )
{
bool V_29 [ V_30 ] ;
int V_31 = 0 ;
int V_32 ;
memset ( V_29 , false , sizeof( V_29 ) ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_18 -> V_33 ; V_32 ++ )
if ( V_28 -> V_34 & ( 1 << V_32 ) )
V_29 [ V_32 ] = true ;
for ( V_32 = 0 ; V_32 < V_15 -> V_35 ; V_32 ++ )
V_29 [ V_15 -> V_36 [ V_32 ] . V_37 - V_15 -> V_18 -> V_38 ] = true ;
if ( V_15 -> V_39 & V_40 )
V_29 [ 4 ] = true ;
if ( V_15 -> V_39 & V_41 )
V_29 [ V_15 -> V_18 -> V_42 ] = true ;
if ( ! V_15 -> V_43 )
V_29 [ 5 ] = true ;
for ( V_32 = 0 ; V_32 < V_15 -> V_18 -> V_33 ; V_32 ++ )
if ( ! V_29 [ V_32 ] )
V_15 -> V_19 [ V_31 ++ ] = V_32 ;
return V_31 ;
}
static int T_2 F_20 ( struct V_14 * V_15 )
{
struct V_44 * V_9 = & V_15 -> V_7 -> V_9 ;
const struct V_27 * V_28 = V_9 -> V_45 ;
const struct V_46 * V_47 = V_28 -> V_47 ;
int V_32 , error ;
if ( ! V_47 )
return 0 ;
V_15 -> V_16 . V_48 = F_19 ( V_15 , V_28 ) ;
if ( V_15 -> V_16 . V_48 == 0 ) {
F_21 ( V_9 , L_2 ) ;
return 0 ;
}
V_15 -> V_49 = true ;
V_15 -> V_16 . V_50 = F_17 ;
V_15 -> V_16 . V_51 = F_18 ;
V_15 -> V_16 . V_52 = F_12 ;
V_15 -> V_16 . V_53 = F_14 ;
V_15 -> V_16 . V_54 = 1 ;
V_15 -> V_16 . V_55 = V_47 -> V_56 ;
V_15 -> V_16 . V_57 = V_15 -> V_7 -> V_58 ;
V_15 -> V_16 . V_59 = V_60 ;
F_22 ( & V_15 -> V_22 ) ;
error = F_23 ( & V_15 -> V_16 ) ;
if ( error ) {
F_9 ( V_9 , L_3 , error ) ;
return error ;
}
for ( V_32 = 0 ; V_32 <= V_15 -> V_18 -> V_17 ( V_15 -> V_18 -> V_33 ) ; V_32 ++ ) {
V_15 -> V_23 [ V_32 ] = F_7 ( V_15 -> V_7 , V_15 -> V_18 -> V_2 (
V_24 ) + V_32 ) ;
V_15 -> V_25 [ V_32 ] = F_7 ( V_15 -> V_7 , V_15 -> V_18 -> V_2 (
V_26 ) + V_32 ) ;
}
if ( V_47 -> V_61 ) {
error = V_47 -> V_61 ( V_15 -> V_7 ,
V_15 -> V_16 . V_55 , V_15 -> V_16 . V_48 ,
V_47 -> V_62 ) ;
if ( error )
F_24 ( V_9 , L_4 , error ) ;
}
return 0 ;
}
static void T_3 F_25 ( struct V_14 * V_15 )
{
struct V_44 * V_9 = & V_15 -> V_7 -> V_9 ;
const struct V_27 * V_28 = V_9 -> V_45 ;
const struct V_46 * V_47 = V_28 -> V_47 ;
int error ;
if ( ! V_15 -> V_49 )
return;
if ( V_47 -> V_63 ) {
error = V_47 -> V_63 ( V_15 -> V_7 ,
V_15 -> V_16 . V_55 , V_15 -> V_16 . V_48 ,
V_47 -> V_62 ) ;
if ( error )
F_24 ( V_9 , L_5 , error ) ;
}
error = F_26 ( & V_15 -> V_16 ) ;
if ( error )
F_24 ( V_9 , L_6 , error ) ;
}
static inline int F_20 ( struct V_14 * V_15 )
{
return 0 ;
}
static inline void F_25 ( struct V_14 * V_15 )
{
}
static void F_27 ( struct V_14 * V_15 ,
int V_64 , int V_65 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_15 -> V_35 ; V_32 ++ ) {
if ( V_65 == V_15 -> V_36 [ V_32 ] . V_37 ) {
F_28 ( V_15 -> V_66 ,
V_15 -> V_36 [ V_32 ] . V_67 ,
V_64 & V_68 ) ;
break;
}
}
}
static void F_29 ( struct V_14 * V_15 , int V_69 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_69 ; V_32 ++ ) {
int V_64 = F_7 ( V_15 -> V_7 , V_70 + V_32 ) ;
int V_65 = V_64 & V_71 ;
if ( V_65 >= V_15 -> V_18 -> V_38 &&
V_65 <= V_15 -> V_18 -> V_72 ) {
F_27 ( V_15 , V_64 , V_65 ) ;
} else {
F_30 ( V_15 -> V_66 ,
V_15 -> V_73 [ V_65 - 1 ] ,
V_64 & V_68 ) ;
}
}
}
static T_4 F_31 ( int V_74 , void * V_75 )
{
struct V_14 * V_15 = V_75 ;
struct V_6 * V_7 = V_15 -> V_7 ;
int V_76 , V_69 ;
V_76 = F_7 ( V_7 , V_77 ) ;
if ( V_76 & V_78 )
F_9 ( & V_7 -> V_9 , L_7 ) ;
if ( V_76 & V_79 ) {
V_69 = F_7 ( V_7 , V_80 ) & V_81 ;
if ( V_69 ) {
F_29 ( V_15 , V_69 ) ;
F_32 ( V_15 -> V_66 ) ;
}
}
F_10 ( V_7 , V_77 , V_76 ) ;
return V_82 ;
}
static int T_2 F_33 ( struct V_14 * V_15 ,
unsigned short V_64 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_15 -> V_18 -> V_83 ; V_32 ++ )
if ( V_64 == V_15 -> V_73 [ V_32 ] )
return ( V_32 + 1 ) | V_68 ;
F_9 ( & V_15 -> V_7 -> V_9 , L_8 ) ;
return - V_84 ;
}
static int T_2 F_34 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
const struct V_27 * V_28 =
V_7 -> V_9 . V_45 ;
T_1 (* V_2) ( T_1 ) = V_15 -> V_18 -> V_2 ;
unsigned char V_85 = 0 , V_86 = 0 , V_87 = 0 ;
unsigned char V_88 = 0 ;
int V_32 , V_8 ;
V_8 = F_10 ( V_7 , V_2 ( V_89 ) ,
V_28 -> V_34 & V_15 -> V_18 -> V_90 ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_91 ) ,
( V_28 -> V_34 >> V_15 -> V_18 -> V_92 ) &
V_15 -> V_18 -> V_93 ) ;
if ( ! V_15 -> V_94 )
V_8 |= F_10 ( V_7 , V_95 ,
( V_28 -> V_34 >> 16 ) & 0xFF ) ;
if ( ! V_15 -> V_94 && V_28 -> V_96 ) {
V_8 |= F_10 ( V_7 , V_97 ,
V_28 -> V_98 ) ;
V_8 |= F_10 ( V_7 , V_99 ,
V_28 -> V_100 ) ;
V_8 |= F_10 ( V_7 , V_101 ,
V_28 -> V_102 & V_103 ) ;
V_8 |= F_10 ( V_7 , V_104 , V_105 ) ;
}
for ( V_32 = 0 ; V_32 < V_106 ; V_32 ++ )
V_8 |= F_7 ( V_7 , V_70 + V_32 ) ;
for ( V_32 = 0 ; V_32 < V_28 -> V_35 ; V_32 ++ ) {
unsigned short V_37 = V_28 -> V_36 [ V_32 ] . V_37 ;
if ( V_37 <= V_15 -> V_18 -> V_107 ) {
V_85 |= ( 1 << ( V_37 - V_15 -> V_18 -> V_108 ) ) ;
} else {
V_86 |=
( ( 1 << ( V_37 - V_15 -> V_18 -> V_109 ) ) & 0xFF ) ;
if ( ! V_15 -> V_94 )
V_87 |= ( ( 1 << ( V_37 -
V_15 -> V_18 -> V_109 ) ) >> 8 ) ;
}
}
if ( V_28 -> V_35 ) {
V_8 |= F_10 ( V_7 , V_2 ( V_110 ) ,
V_85 ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_111 ) ,
V_86 ) ;
if ( ! V_15 -> V_94 )
V_8 |= F_10 ( V_7 ,
V_2 ( V_112 ) ,
V_87 ) ;
}
if ( V_28 -> V_113 & V_28 -> V_114 &
V_28 -> V_115 & V_28 -> V_116 )
F_24 ( & V_7 -> V_9 , L_9 ) ;
for ( V_32 = 0 ; V_32 <= V_15 -> V_18 -> V_117 ; V_32 ++ ) {
unsigned V_10 = 0 , V_20 = ( 1 << V_32 ) ;
if ( V_28 -> V_115 & V_20 )
V_10 = 0 ;
else if ( V_28 -> V_116 & V_20 )
V_10 = 1 ;
else if ( V_28 -> V_114 & V_20 )
V_10 = 2 ;
else if ( V_28 -> V_113 & V_20 )
V_10 = 3 ;
V_88 |= V_10 << ( 2 * ( V_32 & 0x3 ) ) ;
if ( V_32 == 3 || V_32 == V_15 -> V_18 -> V_117 ) {
V_8 |= F_10 ( V_7 , V_2 ( V_118 )
+ ( V_32 >> 2 ) , V_88 ) ;
V_88 = 0 ;
}
}
for ( V_32 = 0 ; V_32 <= V_15 -> V_18 -> V_119 ; V_32 ++ ) {
unsigned V_10 = 0 , V_20 = 1 << ( V_32 + V_15 -> V_18 -> V_92 ) ;
if ( V_28 -> V_115 & V_20 )
V_10 = 0 ;
else if ( V_28 -> V_116 & V_20 )
V_10 = 1 ;
else if ( V_28 -> V_114 & V_20 )
V_10 = 2 ;
else if ( V_28 -> V_113 & V_20 )
V_10 = 3 ;
V_88 |= V_10 << ( 2 * ( V_32 & 0x3 ) ) ;
if ( V_32 == 3 || V_32 == V_15 -> V_18 -> V_119 ) {
V_8 |= F_10 ( V_7 ,
V_2 ( V_120 ) +
( V_32 >> 2 ) , V_88 ) ;
V_88 = 0 ;
}
}
if ( V_28 -> V_121 && V_28 -> V_122 && V_28 -> V_123 ) {
V_8 |= F_10 ( V_7 , V_2 ( V_124 ) ,
F_33 ( V_15 ,
V_28 -> V_121 ) ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_125 ) ,
F_33 ( V_15 ,
V_28 -> V_122 ) ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_126 ) ,
F_33 ( V_15 ,
V_28 -> V_123 ) ) ;
V_15 -> V_39 |= V_40 ;
}
if ( V_28 -> V_127 && V_28 -> V_128 ) {
V_8 |= F_10 ( V_7 , V_2 ( V_129 ) ,
F_33 ( V_15 ,
V_28 -> V_127 ) ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_130 ) ,
F_33 ( V_15 ,
V_28 -> V_128 ) ) ;
V_15 -> V_39 |= V_41 ;
}
if ( V_15 -> V_39 ) {
V_8 |= F_10 ( V_7 , V_2 ( V_131 ) ,
V_28 -> V_132 ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_133 ) ,
V_15 -> V_39 ) ;
}
V_8 |= F_10 ( V_7 , V_2 ( V_134 ) ,
V_28 -> V_135 & V_15 -> V_18 -> V_90 ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_136 ) ,
( V_28 -> V_135 >> V_15 -> V_18 -> V_92 )
& V_15 -> V_18 -> V_93 ) ;
if ( ! V_15 -> V_94 )
V_8 |= F_10 ( V_7 , V_2 ( V_137 ) ,
( V_28 -> V_135 >> 16 ) & 0xFF ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_138 ) ,
V_28 -> V_139 & V_140 ) ;
V_8 |= F_10 ( V_7 , V_77 ,
( V_15 -> V_94 ? 0 : V_141 ) |
V_142 | V_78 |
( V_15 -> V_94 ? 0 : V_143 ) |
V_144 | V_79 ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_145 ) ,
V_146 | V_147 | F_35 ( 3 ) ) ;
V_8 |= F_10 ( V_7 , V_2 ( V_148 ) ,
V_149 | V_150 | V_151 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_7 -> V_9 , L_10 ) ;
return V_8 ;
}
return 0 ;
}
static void T_2 F_36 ( struct V_14 * V_15 )
{
int V_152 , V_153 ;
int V_32 ;
int V_154 = F_7 ( V_15 -> V_7 ,
V_15 -> V_18 -> V_2 ( V_21 ) ) ;
int V_155 = F_7 ( V_15 -> V_7 ,
V_15 -> V_18 -> V_2 ( V_156 ) ) ;
int V_157 = ! V_15 -> V_94 ?
F_7 ( V_15 -> V_7 , V_158 ) : 0 ;
for ( V_32 = 0 ; V_32 < V_15 -> V_35 ; V_32 ++ ) {
unsigned short V_37 = V_15 -> V_36 [ V_32 ] . V_37 ;
if ( V_37 <= V_15 -> V_18 -> V_107 ) {
V_152 = V_154 ;
V_153 = V_37 - V_15 -> V_18 -> V_108 ;
} else if ( ( V_37 - V_15 -> V_18 -> V_109 ) < 8 ) {
V_152 = V_155 ;
V_153 = V_37 - V_15 -> V_18 -> V_109 ;
} else {
V_152 = V_157 ;
V_153 = V_37 - V_15 -> V_18 -> V_109 - 8 ;
}
if ( V_152 < 0 ) {
F_9 ( & V_15 -> V_7 -> V_9 ,
L_11 ,
V_37 ) ;
V_152 = 0 ;
}
F_28 ( V_15 -> V_66 ,
V_15 -> V_36 [ V_32 ] . V_67 ,
! ( V_152 & ( 1 << V_153 ) ) ) ;
}
F_32 ( V_15 -> V_66 ) ;
}
static int T_2 F_37 ( struct V_6 * V_7 ,
const struct V_159 * V_160 )
{
struct V_14 * V_15 ;
const struct V_27 * V_28 =
V_7 -> V_9 . V_45 ;
struct V_161 * V_66 ;
unsigned int V_162 ;
int V_8 , V_32 ;
int error ;
if ( ! F_38 ( V_7 -> V_163 ,
V_164 ) ) {
F_9 ( & V_7 -> V_9 , L_12 ) ;
return - V_165 ;
}
if ( ! V_28 ) {
F_9 ( & V_7 -> V_9 , L_13 ) ;
return - V_84 ;
}
V_15 = F_39 ( sizeof( * V_15 ) , V_166 ) ;
if ( ! V_15 )
return - V_167 ;
switch ( V_160 -> V_168 ) {
case V_169 :
V_15 -> V_43 = true ;
case V_170 :
V_15 -> V_94 = true ;
V_15 -> V_18 = & V_171 ;
break;
case V_172 :
V_15 -> V_18 = & V_173 ;
break;
}
if ( ! ( ( V_28 -> V_34 & V_15 -> V_18 -> V_90 ) &&
( V_28 -> V_34 >> V_15 -> V_18 -> V_92 ) ) ||
! V_28 -> V_174 ) {
F_9 ( & V_7 -> V_9 , L_14 ) ;
error = - V_84 ;
goto V_175;
}
if ( V_28 -> V_83 != V_15 -> V_18 -> V_83 ) {
F_9 ( & V_7 -> V_9 , L_15 ) ;
error = - V_84 ;
goto V_175;
}
if ( ! V_28 -> V_36 && V_28 -> V_35 ) {
F_9 ( & V_7 -> V_9 , L_16 ) ;
error = - V_84 ;
goto V_175;
}
if ( V_28 -> V_35 > V_15 -> V_18 -> V_176 ) {
F_9 ( & V_7 -> V_9 , L_17 ) ;
error = - V_84 ;
goto V_175;
}
for ( V_32 = 0 ; V_32 < V_28 -> V_35 ; V_32 ++ ) {
unsigned short V_37 = V_28 -> V_36 [ V_32 ] . V_37 ;
if ( V_37 < V_15 -> V_18 -> V_38 ||
V_37 > V_15 -> V_18 -> V_72 ) {
F_9 ( & V_7 -> V_9 , L_18 ) ;
error = - V_84 ;
goto V_175;
}
if ( ( 1 << ( V_37 - V_15 -> V_18 -> V_108 ) ) &
V_28 -> V_34 ) {
F_9 ( & V_7 -> V_9 , L_19 ) ;
error = - V_84 ;
goto V_175;
}
}
if ( ! V_7 -> V_74 ) {
F_9 ( & V_7 -> V_9 , L_20 ) ;
error = - V_84 ;
goto V_175;
}
V_66 = F_40 () ;
if ( ! V_66 ) {
error = - V_167 ;
goto V_175;
}
V_15 -> V_7 = V_7 ;
V_15 -> V_66 = V_66 ;
V_8 = F_7 ( V_7 , V_177 ) ;
if ( V_8 < 0 ) {
error = V_8 ;
goto V_178;
}
V_162 = ( T_1 ) V_8 & V_179 ;
V_66 -> V_58 = V_7 -> V_58 ;
V_66 -> V_180 = L_21 ;
V_66 -> V_9 . V_181 = & V_7 -> V_9 ;
F_41 ( V_66 , V_15 ) ;
V_66 -> V_160 . V_182 = V_183 ;
V_66 -> V_160 . V_184 = 0x0001 ;
V_66 -> V_160 . V_185 = 0x0001 ;
V_66 -> V_160 . V_186 = V_162 ;
V_66 -> V_187 = sizeof( V_15 -> V_73 [ 0 ] ) ;
V_66 -> V_188 = V_28 -> V_83 ;
V_66 -> V_73 = V_15 -> V_73 ;
memcpy ( V_15 -> V_73 , V_28 -> V_174 ,
V_28 -> V_83 * V_66 -> V_187 ) ;
V_15 -> V_36 = V_28 -> V_36 ;
V_15 -> V_35 = V_28 -> V_35 ;
F_42 ( V_189 , V_66 -> V_190 ) ;
if ( V_28 -> V_191 )
F_42 ( V_192 , V_66 -> V_190 ) ;
for ( V_32 = 0 ; V_32 < V_66 -> V_188 ; V_32 ++ )
F_42 ( V_15 -> V_73 [ V_32 ] & V_193 , V_66 -> V_194 ) ;
F_43 ( V_195 , V_66 -> V_194 ) ;
if ( V_15 -> V_35 )
F_42 ( V_196 , V_66 -> V_190 ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_35 ; V_32 ++ )
F_42 ( V_15 -> V_36 [ V_32 ] . V_67 , V_66 -> V_197 ) ;
error = F_44 ( V_66 ) ;
if ( error ) {
F_9 ( & V_7 -> V_9 , L_22 ) ;
goto V_178;
}
error = F_45 ( V_7 -> V_74 , NULL , F_31 ,
V_198 | V_199 ,
V_7 -> V_9 . V_200 -> V_58 , V_15 ) ;
if ( error ) {
F_9 ( & V_7 -> V_9 , L_23 , V_7 -> V_74 ) ;
goto V_201;
}
error = F_34 ( V_15 ) ;
if ( error )
goto V_202;
if ( V_15 -> V_35 )
F_36 ( V_15 ) ;
error = F_20 ( V_15 ) ;
if ( error )
goto V_202;
F_46 ( & V_7 -> V_9 , 1 ) ;
F_47 ( V_7 , V_15 ) ;
F_21 ( & V_7 -> V_9 , L_24 , V_162 , V_7 -> V_74 ) ;
return 0 ;
V_202:
F_48 ( V_7 -> V_74 , V_15 ) ;
V_201:
F_49 ( V_66 ) ;
V_66 = NULL ;
V_178:
F_50 ( V_66 ) ;
V_175:
F_51 ( V_15 ) ;
return error ;
}
static int T_3 F_52 ( struct V_6 * V_7 )
{
struct V_14 * V_15 = F_53 ( V_7 ) ;
F_10 ( V_7 , V_15 -> V_18 -> V_2 ( V_145 ) , 0 ) ;
F_48 ( V_7 -> V_74 , V_15 ) ;
F_49 ( V_15 -> V_66 ) ;
F_25 ( V_15 ) ;
F_51 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_44 * V_9 )
{
struct V_14 * V_15 = F_55 ( V_9 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
F_56 ( V_7 -> V_74 ) ;
if ( F_57 ( & V_7 -> V_9 ) )
F_58 ( V_7 -> V_74 ) ;
return 0 ;
}
static int F_59 ( struct V_44 * V_9 )
{
struct V_14 * V_15 = F_55 ( V_9 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
if ( F_57 ( & V_7 -> V_9 ) )
F_60 ( V_7 -> V_74 ) ;
F_61 ( V_7 -> V_74 ) ;
return 0 ;
}
