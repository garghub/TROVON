static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
int V_7 = V_5 -> V_8 [ 0 ] ;
int V_9 = V_5 -> V_8 [ 1 ] ;
int V_10 ;
F_2 (pcidev) {
if ( V_7 || V_9 ) {
if ( V_7 != V_6 -> V_7 -> V_11 ||
V_9 != F_3 ( V_6 -> V_12 ) )
continue;
}
if ( V_6 -> V_13 != V_14 )
continue;
for ( V_10 = 0 ; V_10 < F_4 ( V_15 ) ; V_10 ++ ) {
if ( V_15 [ V_10 ] . V_16 != V_6 -> V_17 )
continue;
V_3 -> V_18 = V_15 + V_10 ;
return V_6 ;
}
}
F_5 ( V_3 -> V_19 ,
L_1 ,
V_7 , V_9 ) ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
if ( F_7 ( V_3 , sizeof( struct V_24 ) ) < 0 )
return - V_25 ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_26 ;
F_8 ( V_3 , & V_6 -> V_3 ) ;
if ( F_9 ( V_6 , V_27 -> V_28 ) ) {
F_5 ( V_3 -> V_19 ,
L_2 ) ;
return - V_26 ;
}
V_29 -> V_30 = F_10 ( V_6 , V_31 ) ;
V_29 -> V_32 = F_10 ( V_6 , V_33 ) ;
V_3 -> V_34 = V_29 -> V_32 ;
if ( V_27 -> V_35 == 2 )
F_11
( L_3
L_4
L_5 ) ;
V_3 -> V_36 = V_27 -> V_28 ;
V_23 = F_12 ( V_3 , 3 ) ;
if ( V_23 )
return V_23 ;
V_21 = V_3 -> V_37 + 0 ;
V_21 -> type = V_38 ;
V_21 -> V_39 = V_40 ;
V_21 -> V_41 = V_27 -> V_42 ;
V_21 -> V_43 = ( 1 << V_27 -> V_44 ) - 1 ;
V_21 -> V_45 = V_27 -> V_46 ;
V_21 -> V_47 = V_48 ;
V_21 = V_3 -> V_37 + 1 ;
F_13 ( V_3 , V_21 , NULL , V_29 -> V_30 ) ;
V_21 = V_3 -> V_37 + 2 ;
F_13 ( V_3 , V_21 , NULL , V_29 -> V_30 + V_49 ) ;
F_14 ( V_3 -> V_19 , L_6 ) ;
for ( V_22 = 0 ; V_22 < V_50 ; V_22 ++ ) {
V_29 -> V_51 [ V_22 ] = F_15 ( V_3 , V_22 ) ;
F_14 ( V_3 -> V_19 , L_7 , V_22 ,
V_29 -> V_51 [ V_22 ] ) ;
}
for ( V_22 = 0 ; V_22 < V_27 -> V_42 ; V_22 ++ )
F_16 ( V_3 , V_22 , V_29 -> V_52 [ V_22 ] ) ;
return 1 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_18 ( V_3 ) ;
if ( V_6 ) {
if ( V_3 -> V_34 )
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
}
if ( V_3 -> V_37 ) {
F_21 ( V_3 , V_3 -> V_37 + 1 ) ;
F_21 ( V_3 , V_3 -> V_37 + 2 ) ;
}
}
static int V_48 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_53 * V_54 , unsigned int * V_55 )
{
unsigned int V_56 ;
unsigned int V_57 , V_58 ;
V_57 = F_22 ( V_54 -> V_59 ) ;
V_58 = F_23 ( V_54 -> V_59 ) ;
if ( V_58 != V_29 -> V_52 [ V_57 ] )
F_16 ( V_3 , V_57 , V_58 ) ;
V_56 = V_60 | V_61 ;
switch ( V_58 ) {
case 0 :
V_56 |= V_62 | V_63 ;
break;
case 1 :
V_56 |= V_62 | V_64 ;
break;
case 2 :
V_56 |= V_62 | V_65 ;
break;
case 3 :
V_56 |= V_66 | V_63 ;
break;
case 4 :
V_56 |= V_66 | V_64 ;
break;
case 5 :
V_56 |= V_66 | V_65 ;
break;
}
V_56 |= V_57 << 2 ;
F_24 ( V_56 , V_29 -> V_32 + V_67 ) ;
F_24 ( V_55 [ 0 ] , V_29 -> V_32 + V_68 + V_57 * 2 ) ;
return 1 ;
}
static unsigned int F_25 ( struct V_2 * V_3 )
{
unsigned int V_69 = 0 ;
int V_10 ;
const int V_70 = 16 ;
for ( V_10 = 1 ; V_10 <= V_70 ; V_10 ++ ) {
if ( F_26 ( V_29 -> V_32 + V_71 ) & V_72 )
V_69 |= 1 << ( V_70 - V_10 ) ;
}
return V_69 ;
}
static void F_27 ( struct V_2 * V_3 , unsigned int V_69 ,
unsigned int V_73 )
{
int V_10 ;
for ( V_10 = 1 ; V_10 <= V_73 ; V_10 ++ ) {
if ( V_69 & ( 1 << ( V_73 - V_10 ) ) )
V_29 -> V_74 |= V_75 ;
else
V_29 -> V_74 &= ~ V_75 ;
F_28 ( V_29 -> V_74 , V_29 -> V_32 + V_71 ) ;
}
}
static unsigned int F_15 ( struct V_2 * V_3 ,
unsigned int V_76 )
{
unsigned int V_10 ;
unsigned int V_77 ;
unsigned int V_69 ;
const int V_78 = 4 ;
const int V_79 = 0x6 ;
const int V_80 = 3 ;
const int V_81 = 8 ;
V_77 = V_82 | V_83 | V_84 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ )
V_77 |= F_29 ( V_10 ) ;
F_28 ( V_77 , V_29 -> V_32 + V_85 ) ;
F_27 ( V_3 , V_79 , V_80 ) ;
F_27 ( V_3 , V_76 , V_81 ) ;
V_69 = F_25 ( V_3 ) ;
V_77 &= ~ V_82 ;
F_28 ( V_77 , V_29 -> V_32 + V_85 ) ;
return V_69 ;
}
static void F_30 ( struct V_2 * V_3 ,
unsigned int V_86 , unsigned int V_57 ,
unsigned int V_69 )
{
unsigned int V_77 ;
unsigned int V_10 ;
const int V_87 = 3 ;
const int V_88 = 8 ;
const int V_78 = 4 ;
F_27 ( V_3 , V_57 , V_87 ) ;
F_27 ( V_3 , V_69 , V_88 ) ;
V_77 = V_83 | V_84 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ )
V_77 |= F_29 ( V_10 ) ;
V_77 &= ~ F_29 ( V_86 ) ;
F_28 ( V_77 , V_29 -> V_32 + V_85 ) ;
V_77 |= F_29 ( V_86 ) ;
F_28 ( V_77 , V_29 -> V_32 + V_85 ) ;
}
static unsigned int F_31 ( unsigned int V_57 )
{
return V_57 / 2 ;
}
static unsigned int F_32 ( unsigned int V_89 )
{
return 4 * ( V_89 % 2 ) ;
}
static unsigned int F_33 ( unsigned int V_89 )
{
return 1 + 4 * ( V_89 % 2 ) ;
}
static unsigned int F_34 ( unsigned int V_89 )
{
return 2 + 4 * ( V_89 % 2 ) ;
}
static unsigned int F_35 ( unsigned int V_89 )
{
return 3 + 4 * ( V_89 % 2 ) ;
}
static unsigned int F_36 ( unsigned int V_89 ,
unsigned int V_58 )
{
return 0x7 + 2 * V_58 + 12 * V_89 ;
}
static unsigned int F_37 ( unsigned int V_89 ,
unsigned int V_58 )
{
return 0x8 + 2 * V_58 + 12 * V_89 ;
}
static unsigned int F_38 ( unsigned int V_90 )
{
return ( V_90 >> 8 ) & 0xff ;
}
static unsigned int F_39 ( unsigned int V_90 )
{
return V_90 & 0xff ;
}
static void F_16 ( struct V_2 * V_3 , unsigned int V_57 ,
unsigned int V_58 )
{
unsigned int V_91 , V_92 , V_93 , V_94 ;
V_29 -> V_52 [ V_57 ] = V_58 ;
V_91 =
F_38 ( V_29 -> V_51
[ F_36 ( V_57 , V_58 ) ] ) ;
V_92 =
F_39 ( V_29 -> V_51
[ F_36 ( V_57 , V_58 ) ] ) ;
V_93 =
F_38 ( V_29 -> V_51
[ F_37 ( V_57 , V_58 ) ] ) ;
V_94 =
F_39 ( V_29 -> V_51
[ F_37 ( V_57 , V_58 ) ] ) ;
F_30 ( V_3 , F_31 ( V_57 ) ,
F_34 ( V_57 ) , V_91 ) ;
F_30 ( V_3 , F_31 ( V_57 ) ,
F_35 ( V_57 ) , V_92 ) ;
F_30 ( V_3 , F_31 ( V_57 ) ,
F_33 ( V_57 ) , V_93 ) ;
F_30 ( V_3 , F_31 ( V_57 ) ,
F_32 ( V_57 ) , V_94 ) ;
}
static int T_1 F_40 ( struct V_1 * V_3 ,
const struct V_95 * V_96 )
{
return F_41 ( V_3 , & V_97 ) ;
}
static void T_2 F_42 ( struct V_1 * V_3 )
{
F_43 ( V_3 ) ;
}
