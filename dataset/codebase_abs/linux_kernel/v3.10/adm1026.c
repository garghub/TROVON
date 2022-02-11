static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_3 < 0x80 ) {
V_4 = F_2 ( V_2 , V_3 ) & 0xff ;
} else {
V_4 = 0 ;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_5 )
{
int V_4 ;
if ( V_3 < 0x80 ) {
V_4 = F_4 ( V_2 , V_3 , V_5 ) ;
} else {
V_4 = 0 ;
}
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_5 , V_6 ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_9 , L_1 ) ;
V_8 -> V_10 = F_1 ( V_2 , V_11 ) ;
V_8 -> V_12 = F_1 ( V_2 , V_13 ) ;
V_8 -> V_14 = F_1 ( V_2 , V_15 ) ;
F_7 ( & V_2 -> V_9 , L_2 ,
V_8 -> V_10 ) ;
if ( ( V_8 -> V_10 & V_16 ) == 0 ) {
F_7 ( & V_2 -> V_9 ,
L_3 ) ;
}
if ( V_8 -> V_10 & V_17 ) {
F_7 ( & V_2 -> V_9 ,
L_4 ) ;
}
if ( V_8 -> V_10 & V_18 ) {
F_7 ( & V_2 -> V_9 ,
L_5 ) ;
} else {
F_7 ( & V_2 -> V_9 ,
L_6 ) ;
}
if ( V_8 -> V_10 & V_19 ) {
F_7 ( & V_2 -> V_9 ,
L_7 ) ;
}
if ( V_8 -> V_14 & V_20 ) {
F_7 ( & V_2 -> V_9 ,
L_8 ) ;
} else {
F_7 ( & V_2 -> V_9 ,
L_9 ) ;
}
if ( V_8 -> V_14 & V_21 )
F_7 ( & V_2 -> V_9 , L_10 ) ;
else
F_7 ( & V_2 -> V_9 , L_11 ) ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 <= 15 ; ++ V_6 ) {
if ( ( V_6 & 0x03 ) == 0 ) {
V_5 = F_1 ( V_2 ,
V_22 + V_6 / 4 ) ;
}
V_8 -> V_23 [ V_6 ] = V_5 & 0x03 ;
V_5 >>= 2 ;
}
V_8 -> V_23 [ 16 ] = ( V_8 -> V_14 >> 6 ) & 0x03 ;
F_8 ( V_2 ) ;
if ( V_24 [ 0 ] != - 1 || V_25 [ 0 ] != - 1
|| V_26 [ 0 ] != - 1 || V_27 [ 0 ] != - 1
|| V_28 [ 0 ] != - 1 ) {
F_9 ( V_2 ) ;
}
V_8 -> V_29 . V_30 = 255 ;
V_5 = F_1 ( V_2 , V_11 ) ;
V_5 = ( V_5 | V_16 ) & ( ~ V_31 & ~ V_32 ) ;
F_7 ( & V_2 -> V_9 , L_12 , V_5 ) ;
V_8 -> V_10 = V_5 ;
F_3 ( V_2 , V_11 , V_5 ) ;
V_5 = F_1 ( V_2 , V_33 ) |
( F_1 ( V_2 , V_34 ) << 8 ) ;
for ( V_6 = 0 ; V_6 <= 7 ; ++ V_6 ) {
V_8 -> V_35 [ V_6 ] = F_10 ( V_5 & 0x03 ) ;
V_5 >>= 2 ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_6 ;
F_7 ( & V_2 -> V_9 , L_13 ) ;
for ( V_6 = 0 ; V_6 <= 7 ; ++ V_6 ) {
if ( V_8 -> V_12 & ( 1 << V_6 ) ) {
F_7 ( & V_2 -> V_9 , L_14 ,
V_8 -> V_23 [ V_6 ] & 0x02 ? L_15 : L_16 ,
V_8 -> V_23 [ V_6 ] & 0x01 ? L_17 : L_18 ,
V_6 ) ;
} else {
F_7 ( & V_2 -> V_9 , L_19 , V_6 ) ;
}
}
for ( V_6 = 8 ; V_6 <= 15 ; ++ V_6 ) {
F_7 ( & V_2 -> V_9 , L_14 ,
V_8 -> V_23 [ V_6 ] & 0x02 ? L_15 : L_16 ,
V_8 -> V_23 [ V_6 ] & 0x01 ? L_17 : L_18 ,
V_6 ) ;
}
if ( V_8 -> V_14 & V_20 ) {
F_7 ( & V_2 -> V_9 , L_20 ,
V_8 -> V_23 [ 16 ] & 0x02 ? L_15 : L_16 ,
V_8 -> V_23 [ 16 ] & 0x01 ? L_17 : L_18 ) ;
} else {
F_7 ( & V_2 -> V_9 , L_21 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_6 ;
int V_5 ;
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
if ( V_25 [ V_6 ] >= 0 && V_25 [ V_6 ] <= 16 )
V_8 -> V_23 [ V_25 [ V_6 ] ] |= 0x01 ;
if ( V_25 [ V_6 ] >= 0 && V_25 [ V_6 ] <= 7 )
V_8 -> V_12 |= 1 << V_25 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
if ( V_24 [ V_6 ] >= 0 && V_24 [ V_6 ] <= 16 )
V_8 -> V_23 [ V_24 [ V_6 ] ] &= ~ 0x01 ;
if ( V_24 [ V_6 ] >= 0 && V_24 [ V_6 ] <= 7 )
V_8 -> V_12 |= 1 << V_24 [ V_6 ] ;
}
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
if ( V_26 [ V_6 ] >= 0 && V_26 [ V_6 ] <= 16 )
V_8 -> V_23 [ V_26 [ V_6 ] ] &= ~ 0x02 ;
}
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
if ( V_27 [ V_6 ] >= 0 && V_27 [ V_6 ] <= 16 )
V_8 -> V_23 [ V_27 [ V_6 ] ] |= 0x02 ;
}
for ( V_6 = 0 ; V_6 <= 7 ; ++ V_6 ) {
if ( V_28 [ V_6 ] >= 0 && V_28 [ V_6 ] <= 7 )
V_8 -> V_12 &= ~ ( 1 << V_28 [ V_6 ] ) ;
}
F_3 ( V_2 , V_13 , V_8 -> V_12 ) ;
V_8 -> V_14 = ( V_8 -> V_14 & 0x3f )
| ( ( V_8 -> V_23 [ 16 ] & 0x03 ) << 6 ) ;
F_3 ( V_2 , V_15 , V_8 -> V_14 ) ;
for ( V_6 = 15 , V_5 = 0 ; V_6 >= 0 ; -- V_6 ) {
V_5 <<= 2 ;
V_5 |= V_8 -> V_23 [ V_6 ] & 0x03 ;
if ( ( V_6 & 0x03 ) == 0 ) {
F_3 ( V_2 ,
V_22 + V_6 / 4 ,
V_5 ) ;
V_5 = 0 ;
}
}
F_8 ( V_2 ) ;
}
static struct V_7 * F_11 ( struct V_36 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_6 ;
long V_5 , V_37 , V_38 ;
F_13 ( & V_8 -> V_39 ) ;
if ( ! V_8 -> V_40
|| F_14 ( V_41 ,
V_8 -> V_42 + V_43 ) ) {
F_7 ( & V_2 -> V_9 , L_22 ) ;
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
V_8 -> V_44 [ V_6 ] =
F_1 ( V_2 , V_45 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 <= 7 ; ++ V_6 ) {
V_8 -> V_46 [ V_6 ] =
F_1 ( V_2 , F_15 ( V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 <= 2 ; ++ V_6 ) {
V_8 -> V_47 [ V_6 ] =
F_1 ( V_2 , V_48 [ V_6 ] ) ;
}
V_8 -> V_29 . V_49 = F_1 ( V_2 ,
V_50 ) ;
V_8 -> V_51 = F_1 ( V_2 ,
V_52 ) ;
V_37 = F_1 ( V_2 , V_53 ) ;
V_38 = V_37 & 0x80 ? 0x0100 : 0 ;
V_37 &= 0x7f ;
V_37 <<= 8 ;
V_37 |= F_1 ( V_2 , V_54 ) ;
V_37 <<= 8 ;
V_37 |= F_1 ( V_2 , V_55 ) ;
V_37 <<= 8 ;
V_37 |= F_1 ( V_2 , V_56 ) ;
V_8 -> V_37 = V_37 ;
V_38 |= F_1 ( V_2 ,
V_57 ) ;
V_38 <<= 8 ;
V_38 |= F_1 ( V_2 ,
V_58 ) ;
V_8 -> V_38 = V_38 ;
V_8 -> V_42 = V_41 ;
} ;
if ( ! V_8 -> V_40 ||
F_14 ( V_41 , V_8 -> V_59 + V_60 ) ) {
F_7 ( & V_2 -> V_9 , L_23 ) ;
for ( V_6 = 0 ; V_6 <= 16 ; ++ V_6 ) {
V_8 -> V_61 [ V_6 ] = F_1 ( V_2 ,
V_62 [ V_6 ] ) ;
V_8 -> V_63 [ V_6 ] = F_1 ( V_2 ,
V_64 [ V_6 ] ) ;
}
V_5 = F_1 ( V_2 , V_33 )
| ( F_1 ( V_2 , V_34 )
<< 8 ) ;
for ( V_6 = 0 ; V_6 <= 7 ; ++ V_6 ) {
V_8 -> V_65 [ V_6 ] = F_1 ( V_2 ,
F_16 ( V_6 ) ) ;
V_8 -> V_35 [ V_6 ] = F_10 ( V_5 & 0x03 ) ;
V_5 >>= 2 ;
}
for ( V_6 = 0 ; V_6 <= 2 ; ++ V_6 ) {
V_8 -> V_66 [ V_6 ] = F_1 ( V_2 ,
V_67 [ V_6 ] ) ;
V_8 -> V_68 [ V_6 ] = F_1 ( V_2 ,
V_69 [ V_6 ] ) ;
V_8 -> V_70 [ V_6 ] = F_1 ( V_2 ,
V_71 [ V_6 ] ) ;
V_8 -> V_72 [ V_6 ] = F_1 ( V_2 ,
V_73 [ V_6 ] ) ;
V_8 -> V_74 [ V_6 ] = F_1 ( V_2 ,
V_75 [ V_6 ] ) ;
}
V_37 = F_1 ( V_2 , V_76 ) ;
V_38 = V_37 & 0x80 ? 0x0100 : 0 ;
V_37 = ( V_37 & 0x7f ) << 8 ;
V_37 |= F_1 ( V_2 , V_77 ) ;
V_37 <<= 8 ;
V_37 |= F_1 ( V_2 , V_78 ) ;
V_37 <<= 8 ;
V_37 |= F_1 ( V_2 , V_79 ) ;
V_8 -> V_80 = V_37 ;
V_38 |= F_1 ( V_2 ,
V_81 ) ;
V_38 <<= 8 ;
V_38 |= F_1 ( V_2 , V_82 ) ;
V_8 -> V_83 = V_38 ;
V_8 -> V_10 = F_1 ( V_2 ,
V_11 ) ;
if ( V_8 -> V_10 & V_84 ) {
V_8 -> V_29 . V_85 = 2 ;
V_8 -> V_29 . V_30 =
F_17 ( V_8 -> V_29 . V_49 ) ;
}
V_8 -> V_12 = F_1 ( V_2 ,
V_13 ) ;
V_8 -> V_14 = F_1 ( V_2 ,
V_15 ) ;
V_8 -> V_23 [ 16 ] = ( V_8 -> V_14 >> 6 ) & 0x03 ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 <= 15 ; ++ V_6 ) {
if ( ( V_6 & 0x03 ) == 0 ) {
V_5 = F_1 ( V_2 ,
V_22 + V_6 / 4 ) ;
}
V_8 -> V_23 [ V_6 ] = V_5 & 0x03 ;
V_5 >>= 2 ;
}
V_8 -> V_59 = V_41 ;
} ;
V_8 -> V_40 = 1 ;
F_18 ( & V_8 -> V_39 ) ;
return V_8 ;
}
static T_2 F_19 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( V_91 , V_8 -> V_44 [ V_91 ] ) ) ;
}
static T_2 F_22 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( V_91 , V_8 -> V_61 [ V_91 ] ) ) ;
}
static T_2 F_23 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_61 [ V_91 ] = F_25 ( V_91 , V_94 ) ;
F_3 ( V_2 , V_62 [ V_91 ] , V_8 -> V_61 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_26 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( V_91 , V_8 -> V_63 [ V_91 ] ) ) ;
}
static T_2 F_27 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_63 [ V_91 ] = F_25 ( V_91 , V_94 ) ;
F_3 ( V_2 , V_64 [ V_91 ] , V_8 -> V_63 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_28 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( 16 , V_8 -> V_44 [ 16 ] ) -
V_96 ) ;
}
static T_2 F_29 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( 16 , V_8 -> V_61 [ 16 ] )
- V_96 ) ;
}
static T_2 F_30 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_61 [ 16 ] = F_25 ( 16 , V_94 + V_96 ) ;
F_3 ( V_2 , V_62 [ 16 ] , V_8 -> V_61 [ 16 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_31 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_21 ( 16 , V_8 -> V_63 [ 16 ] )
- V_96 ) ;
}
static T_2 F_32 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_63 [ 16 ] = F_25 ( 16 , V_94 + V_96 ) ;
F_3 ( V_2 , V_64 [ 16 ] , V_8 -> V_63 [ 16 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_33 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_34 ( V_8 -> V_46 [ V_91 ] ,
V_8 -> V_35 [ V_91 ] ) ) ;
}
static T_2 F_35 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_34 ( V_8 -> V_65 [ V_91 ] ,
V_8 -> V_35 [ V_91 ] ) ) ;
}
static T_2 F_36 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_65 [ V_91 ] = F_37 ( V_94 , V_8 -> V_35 [ V_91 ] ) ;
F_3 ( V_2 , F_16 ( V_91 ) ,
V_8 -> V_65 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static void F_38 ( struct V_36 * V_9 , int V_46 , int V_97 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_98 ;
int V_99 = V_8 -> V_35 [ V_46 ] ;
if ( V_8 -> V_65 [ V_46 ] == 0 || V_8 -> V_65 [ V_46 ] == 0xff )
return;
V_98 = V_8 -> V_65 [ V_46 ] * V_97 / V_99 ;
V_98 = F_39 ( V_98 , 1 , 254 ) ;
V_8 -> V_65 [ V_46 ] = V_98 ;
F_3 ( V_2 , F_16 ( V_46 ) , V_98 ) ;
}
static T_2 F_40 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , V_8 -> V_35 [ V_91 ] ) ;
}
static T_2 F_41 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_100 , V_99 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
V_99 = F_42 ( V_94 ) ;
F_13 ( & V_8 -> V_39 ) ;
V_100 = V_8 -> V_35 [ V_91 ] ;
V_8 -> V_35 [ V_91 ] = F_10 ( V_99 ) ;
if ( V_91 < 4 ) {
F_3 ( V_2 , V_33 ,
( F_42 ( V_8 -> V_35 [ 0 ] ) << 0 ) |
( F_42 ( V_8 -> V_35 [ 1 ] ) << 2 ) |
( F_42 ( V_8 -> V_35 [ 2 ] ) << 4 ) |
( F_42 ( V_8 -> V_35 [ 3 ] ) << 6 ) ) ;
} else {
F_3 ( V_2 , V_34 ,
( F_42 ( V_8 -> V_35 [ 4 ] ) << 0 ) |
( F_42 ( V_8 -> V_35 [ 5 ] ) << 2 ) |
( F_42 ( V_8 -> V_35 [ 6 ] ) << 4 ) |
( F_42 ( V_8 -> V_35 [ 7 ] ) << 6 ) ) ;
}
if ( V_8 -> V_35 [ V_91 ] != V_100 )
F_38 ( V_9 , V_91 , V_100 ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_43 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_47 [ V_91 ] ) ) ;
}
static T_2 F_45 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_66 [ V_91 ] ) ) ;
}
static T_2 F_46 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_66 [ V_91 ] = F_47 ( V_94 ) ;
F_3 ( V_2 , V_67 [ V_91 ] ,
V_8 -> V_66 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_48 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_68 [ V_91 ] ) ) ;
}
static T_2 F_49 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_68 [ V_91 ] = F_47 ( V_94 ) ;
F_3 ( V_2 , V_69 [ V_91 ] ,
V_8 -> V_68 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_50 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_74 [ V_91 ] ) ) ;
}
static T_2 F_51 ( struct V_36 * V_9 ,
struct V_86 * V_87 , const char * V_88 ,
T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_74 [ V_91 ] = F_47 ( V_94 ) ;
F_3 ( V_2 , V_75 [ V_91 ] ,
V_8 -> V_74 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_52 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 (
V_101 + V_8 -> V_70 [ V_91 ] ) ) ;
}
static T_2 F_53 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_70 [ V_91 ] +
V_102 ) ) ;
}
static T_2 F_54 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_70 [ V_91 ] ) ) ;
}
static T_2 F_55 ( struct V_36 * V_9 ,
struct V_86 * V_87 , const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_70 [ V_91 ] = F_47 ( V_94 ) ;
F_3 ( V_2 , V_71 [ V_91 ] ,
V_8 -> V_70 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_56 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , ( V_8 -> V_10 & V_19 ) >> 4 ) ;
}
static T_2 F_57 ( struct V_36 * V_9 ,
struct V_86 * V_87 , const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
unsigned long V_94 ;
int V_95 ;
V_95 = F_58 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
if ( V_94 > 1 )
return - V_103 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_10 = ( V_8 -> V_10 & ~ V_19 ) | ( V_94 << 4 ) ;
F_3 ( V_2 , V_11 , V_8 -> V_10 ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_59 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_44 ( V_8 -> V_72 [ V_91 ] ) ) ;
}
static T_2 F_60 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_89 * V_90 = F_20 ( V_87 ) ;
int V_91 = V_90 -> V_92 ;
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_72 [ V_91 ] = F_47 ( V_94 ) ;
F_3 ( V_2 , V_73 [ V_91 ] ,
V_8 -> V_72 [ V_91 ] ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_61 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_62 ( V_8 -> V_51 ) ) ;
}
static T_2 F_63 ( struct V_36 * V_9 ,
struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_51 = F_64 ( V_94 ) ;
F_3 ( V_2 , V_52 , V_8 -> V_51 ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_65 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
int V_104 = ( V_8 -> V_38 >> 11 ) & 0x1f ;
F_7 ( V_9 , L_25 ) ;
return sprintf ( V_88 , L_24 , F_66 ( V_104 , V_8 -> V_105 ) ) ;
}
static T_2 F_67 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_68 ( V_9 ) ;
return sprintf ( V_88 , L_24 , V_8 -> V_105 ) ;
}
static T_2 F_69 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_7 * V_8 = F_68 ( V_9 ) ;
unsigned long V_94 ;
int V_95 ;
V_95 = F_58 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
V_8 -> V_105 = V_94 ;
return V_93 ;
}
static T_2 F_70 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_26 , V_8 -> V_37 ) ;
}
static T_2 F_71 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
int V_106 = F_20 ( V_87 ) -> V_92 ;
return sprintf ( V_88 , L_26 , ( V_8 -> V_37 >> V_106 ) & 1 ) ;
}
static T_2 F_72 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_26 , V_8 -> V_80 ) ;
}
static T_2 F_73 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
unsigned long V_107 ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_80 = V_94 & 0x7fffffff ;
V_107 = V_8 -> V_80
| ( V_8 -> V_83 & 0x10000 ? 0x80000000 : 0 ) ;
F_3 ( V_2 , V_79 ,
V_107 & 0xff ) ;
V_107 >>= 8 ;
F_3 ( V_2 , V_78 ,
V_107 & 0xff ) ;
V_107 >>= 8 ;
F_3 ( V_2 , V_77 ,
V_107 & 0xff ) ;
V_107 >>= 8 ;
F_3 ( V_2 , V_76 ,
V_107 & 0xff ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_74 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_26 , V_8 -> V_38 ) ;
}
static T_2 F_75 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_38 ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_38 = V_94 & 0x1ffff ;
V_38 = V_8 -> V_38 ;
F_3 ( V_2 , V_58 , V_38 & 0xff ) ;
V_38 >>= 8 ;
F_3 ( V_2 , V_57 , V_38 & 0xff ) ;
V_38 = ( ( V_38 >> 1 ) & 0x80 ) | ( V_8 -> V_37 >> 24 & 0x7f ) ;
F_3 ( V_2 , V_53 , V_38 & 0xff ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_76 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_26 , V_8 -> V_83 ) ;
}
static T_2 F_77 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
long V_107 ;
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_83 = V_94 & 0x1ffff ;
V_107 = V_8 -> V_83 ;
F_3 ( V_2 , V_82 , V_107 & 0xff ) ;
V_107 >>= 8 ;
F_3 ( V_2 , V_81 , V_107 & 0xff ) ;
V_107 = ( ( V_107 >> 1 ) & 0x80 ) | ( V_8 -> V_80 >> 24 & 0x7f ) ;
F_3 ( V_2 , V_79 , V_107 & 0xff ) ;
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_78 ( struct V_36 * V_9 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , F_79 ( V_8 -> V_29 . V_49 ) ) ;
}
static T_2 F_80 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
if ( V_8 -> V_29 . V_85 == 1 ) {
long V_94 ;
int V_95 ;
V_95 = F_24 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_29 . V_49 = F_81 ( V_94 ) ;
F_3 ( V_2 , V_50 , V_8 -> V_29 . V_49 ) ;
F_18 ( & V_8 -> V_39 ) ;
}
return V_93 ;
}
static T_2 F_82 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , V_8 -> V_29 . V_30 ) ;
}
static T_2 F_83 ( struct V_36 * V_9 ,
struct V_86 * V_87 , const char * V_88 ,
T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
unsigned long V_94 ;
int V_95 ;
V_95 = F_58 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
F_13 ( & V_8 -> V_39 ) ;
V_8 -> V_29 . V_30 = F_39 ( V_94 , 0 , 255 ) ;
if ( V_8 -> V_29 . V_85 == 2 ) {
V_8 -> V_29 . V_49 = F_81 ( ( V_8 -> V_29 . V_49 & 0x0f ) |
F_84 ( V_8 -> V_29 . V_30 ) ) ;
F_3 ( V_2 , V_50 , V_8 -> V_29 . V_49 ) ;
}
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static T_2 F_85 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
return sprintf ( V_88 , L_24 , V_108 ) ;
}
static T_2 F_86 ( struct V_36 * V_9 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_7 * V_8 = F_11 ( V_9 ) ;
return sprintf ( V_88 , L_24 , V_8 -> V_29 . V_85 ) ;
}
static T_2 F_87 ( struct V_36 * V_9 , struct V_86 * V_87 ,
const char * V_88 , T_3 V_93 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_109 ;
unsigned long V_94 ;
int V_95 ;
V_95 = F_58 ( V_88 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
if ( V_94 >= 3 )
return - V_103 ;
F_13 ( & V_8 -> V_39 ) ;
V_109 = V_8 -> V_29 . V_85 ;
V_8 -> V_29 . V_85 = V_94 ;
V_8 -> V_10 = ( V_8 -> V_10 & ~ V_84 )
| ( ( V_94 == 2 ) ? V_84 : 0 ) ;
F_3 ( V_2 , V_11 , V_8 -> V_10 ) ;
if ( V_94 == 2 ) {
V_8 -> V_29 . V_49 = F_81 ( ( V_8 -> V_29 . V_49 & 0x0f ) |
F_84 ( V_8 -> V_29 . V_30 ) ) ;
F_3 ( V_2 , V_50 , V_8 -> V_29 . V_49 ) ;
} else if ( ! ( ( V_109 == 1 ) && ( V_94 == 1 ) ) ) {
V_8 -> V_29 . V_49 = 255 ;
F_3 ( V_2 , V_50 , V_8 -> V_29 . V_49 ) ;
}
F_18 ( & V_8 -> V_39 ) ;
return V_93 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 = V_2 -> V_113 ;
int V_114 = V_2 -> V_115 ;
int V_116 , V_117 ;
if ( ! F_89 ( V_113 , V_118 ) ) {
return - V_119 ;
} ;
V_116 = F_1 ( V_2 , V_120 ) ;
V_117 = F_1 ( V_2 , V_121 ) ;
F_7 ( & V_113 -> V_9 ,
L_27 ,
F_90 ( V_2 -> V_113 ) , V_2 -> V_115 ,
V_116 , V_117 ) ;
F_7 ( & V_113 -> V_9 , L_28 ,
F_90 ( V_113 ) , V_114 ) ;
if ( V_116 == V_122
&& V_117 == V_123 ) {
} else if ( V_116 == V_122
&& ( V_117 & 0xf0 ) == V_124 ) {
F_91 ( & V_113 -> V_9 ,
L_29 ,
V_117 ) ;
} else if ( ( V_117 & 0xf0 ) == V_124 ) {
F_91 ( & V_113 -> V_9 ,
L_30 ,
V_117 ) ;
} else {
F_7 ( & V_113 -> V_9 , L_31 ) ;
return - V_119 ;
}
F_92 ( V_111 -> type , L_32 , V_125 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
const struct V_126 * V_127 )
{
struct V_7 * V_8 ;
int V_95 ;
V_8 = F_94 ( & V_2 -> V_9 , sizeof( struct V_7 ) ,
V_128 ) ;
if ( ! V_8 )
return - V_129 ;
F_95 ( V_2 , V_8 ) ;
F_96 ( & V_8 -> V_39 ) ;
V_8 -> V_105 = F_97 () ;
F_5 ( V_2 ) ;
V_95 = F_98 ( & V_2 -> V_9 . V_130 , & V_131 ) ;
if ( V_95 )
return V_95 ;
if ( V_8 -> V_10 & V_18 )
V_95 = F_98 ( & V_2 -> V_9 . V_130 ,
& V_132 ) ;
else
V_95 = F_98 ( & V_2 -> V_9 . V_130 ,
& V_133 ) ;
if ( V_95 )
goto V_134;
V_8 -> V_135 = F_99 ( & V_2 -> V_9 ) ;
if ( F_100 ( V_8 -> V_135 ) ) {
V_95 = F_101 ( V_8 -> V_135 ) ;
goto V_134;
}
return 0 ;
V_134:
F_102 ( & V_2 -> V_9 . V_130 , & V_131 ) ;
if ( V_8 -> V_10 & V_18 )
F_102 ( & V_2 -> V_9 . V_130 , & V_132 ) ;
else
F_102 ( & V_2 -> V_9 . V_130 , & V_133 ) ;
return V_95 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 ) ;
F_104 ( V_8 -> V_135 ) ;
F_102 ( & V_2 -> V_9 . V_130 , & V_131 ) ;
if ( V_8 -> V_10 & V_18 )
F_102 ( & V_2 -> V_9 . V_130 , & V_132 ) ;
else
F_102 ( & V_2 -> V_9 . V_130 , & V_133 ) ;
return 0 ;
}
