static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 = 0 ;
int V_7 ;
const int V_8 = 16 ;
for ( V_7 = 1 ; V_7 <= V_8 ; V_7 ++ ) {
if ( F_2 ( V_4 -> V_9 + V_10 ) & V_11 )
V_6 |= 1 << ( V_8 - V_7 ) ;
}
return V_6 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_7 ;
for ( V_7 = 1 ; V_7 <= V_12 ; V_7 ++ ) {
if ( V_6 & ( 1 << ( V_12 - V_7 ) ) )
V_4 -> V_13 |= V_14 ;
else
V_4 -> V_13 &= ~ V_14 ;
F_4 ( V_4 -> V_13 , V_4 -> V_9 + V_10 ) ;
}
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_7 ;
unsigned int V_16 ;
unsigned int V_6 ;
const int V_17 = 4 ;
const int V_18 = 0x6 ;
const int V_19 = 3 ;
const int V_20 = 8 ;
V_16 = V_21 | V_22 | V_23 ;
for ( V_7 = 0 ; V_7 < V_17 ; V_7 ++ )
V_16 |= F_6 ( V_7 ) ;
F_4 ( V_16 , V_4 -> V_9 + V_24 ) ;
F_3 ( V_2 , V_18 , V_19 ) ;
F_3 ( V_2 , V_15 , V_20 ) ;
V_6 = F_1 ( V_2 ) ;
V_16 &= ~ V_21 ;
F_4 ( V_16 , V_4 -> V_9 + V_24 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_26 ,
unsigned int V_6 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_16 ;
unsigned int V_7 ;
const int V_27 = 3 ;
const int V_28 = 8 ;
const int V_17 = 4 ;
F_3 ( V_2 , V_26 , V_27 ) ;
F_3 ( V_2 , V_6 , V_28 ) ;
V_16 = V_22 | V_23 ;
for ( V_7 = 0 ; V_7 < V_17 ; V_7 ++ )
V_16 |= F_6 ( V_7 ) ;
V_16 &= ~ F_6 ( V_25 ) ;
F_4 ( V_16 , V_4 -> V_9 + V_24 ) ;
V_16 |= F_6 ( V_25 ) ;
F_4 ( V_16 , V_4 -> V_9 + V_24 ) ;
}
static unsigned int F_8 ( unsigned int V_26 )
{
return V_26 / 2 ;
}
static unsigned int F_9 ( unsigned int V_29 )
{
return 4 * ( V_29 % 2 ) ;
}
static unsigned int F_10 ( unsigned int V_29 )
{
return 1 + 4 * ( V_29 % 2 ) ;
}
static unsigned int F_11 ( unsigned int V_29 )
{
return 2 + 4 * ( V_29 % 2 ) ;
}
static unsigned int F_12 ( unsigned int V_29 )
{
return 3 + 4 * ( V_29 % 2 ) ;
}
static unsigned int F_13 ( unsigned int V_29 ,
unsigned int V_30 )
{
return 0x7 + 2 * V_30 + 12 * V_29 ;
}
static unsigned int F_14 ( unsigned int V_29 ,
unsigned int V_30 )
{
return 0x8 + 2 * V_30 + 12 * V_29 ;
}
static unsigned int F_15 ( unsigned int V_31 )
{
return ( V_31 >> 8 ) & 0xff ;
}
static unsigned int F_16 ( unsigned int V_31 )
{
return V_31 & 0xff ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_26 ,
unsigned int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_32 , V_33 , V_34 , V_35 ;
V_4 -> V_36 [ V_26 ] = V_30 ;
V_32 =
F_15 ( V_4 -> V_37
[ F_13 ( V_26 , V_30 ) ] ) ;
V_33 =
F_16 ( V_4 -> V_37
[ F_13 ( V_26 , V_30 ) ] ) ;
V_34 =
F_15 ( V_4 -> V_37
[ F_14 ( V_26 , V_30 ) ] ) ;
V_35 =
F_16 ( V_4 -> V_37
[ F_14 ( V_26 , V_30 ) ] ) ;
F_7 ( V_2 , F_8 ( V_26 ) ,
F_11 ( V_26 ) , V_32 ) ;
F_7 ( V_2 , F_8 ( V_26 ) ,
F_12 ( V_26 ) , V_33 ) ;
F_7 ( V_2 , F_8 ( V_26 ) ,
F_10 ( V_26 ) , V_34 ) ;
F_7 ( V_2 , F_8 ( V_26 ) ,
F_9 ( V_26 ) , V_35 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_43 ;
unsigned int V_26 , V_30 ;
V_26 = F_19 ( V_41 -> V_44 ) ;
V_30 = F_20 ( V_41 -> V_44 ) ;
if ( V_30 != V_4 -> V_36 [ V_26 ] )
F_17 ( V_2 , V_26 , V_30 ) ;
V_43 = V_45 | V_46 ;
switch ( V_30 ) {
case 0 :
V_43 |= V_47 | V_48 ;
break;
case 1 :
V_43 |= V_47 | V_49 ;
break;
case 2 :
V_43 |= V_47 | V_50 ;
break;
case 3 :
V_43 |= V_51 | V_48 ;
break;
case 4 :
V_43 |= V_51 | V_49 ;
break;
case 5 :
V_43 |= V_51 | V_50 ;
break;
}
V_43 |= V_26 << 2 ;
F_21 ( V_43 , V_4 -> V_9 + V_52 ) ;
F_21 ( V_42 [ 0 ] , V_4 -> V_9 + V_53 + V_26 * 2 ) ;
return 1 ;
}
static const void * F_22 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
const struct V_56 * V_57 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_23 ( V_58 ) ; V_7 ++ ) {
V_57 = & V_58 [ V_7 ] ;
if ( V_57 -> V_59 != V_55 -> V_60 )
return V_57 ;
}
return NULL ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
const struct V_56 * V_57 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
int V_61 ;
int V_62 ;
F_25 ( V_2 , & V_55 -> V_2 ) ;
V_57 = F_22 ( V_2 , V_55 ) ;
if ( ! V_55 )
return - V_63 ;
V_2 -> V_64 = V_57 ;
V_2 -> V_65 = V_57 -> V_66 ;
V_62 = F_26 ( V_2 , sizeof( * V_4 ) ) ;
if ( V_62 )
return V_62 ;
V_4 = V_2 -> V_5 ;
V_62 = F_27 ( V_55 , V_2 -> V_65 ) ;
if ( V_62 )
return V_62 ;
V_4 -> V_67 = F_28 ( V_55 , 2 ) ;
V_4 -> V_9 = F_28 ( V_55 , 3 ) ;
V_2 -> V_68 = V_4 -> V_9 ;
if ( V_57 -> V_69 == 2 )
F_29
( L_1
L_2
L_3 ) ;
V_62 = F_30 ( V_2 , 3 ) ;
if ( V_62 )
return V_62 ;
V_39 = & V_2 -> V_70 [ 0 ] ;
V_39 -> type = V_71 ;
V_39 -> V_72 = V_73 ;
V_39 -> V_74 = V_57 -> V_75 ;
V_39 -> V_76 = ( 1 << V_57 -> V_77 ) - 1 ;
V_39 -> V_78 = V_57 -> V_79 ;
V_39 -> V_80 = F_18 ;
V_39 = & V_2 -> V_70 [ 1 ] ;
F_31 ( V_2 , V_39 , NULL , V_4 -> V_67 ) ;
V_39 = & V_2 -> V_70 [ 2 ] ;
F_31 ( V_2 , V_39 , NULL , V_4 -> V_67 + V_81 ) ;
F_32 ( V_2 -> V_82 , L_4 ) ;
for ( V_61 = 0 ; V_61 < V_83 ; V_61 ++ ) {
V_4 -> V_37 [ V_61 ] = F_5 ( V_2 , V_61 ) ;
F_32 ( V_2 -> V_82 , L_5 , V_61 ,
V_4 -> V_37 [ V_61 ] ) ;
}
for ( V_61 = 0 ; V_61 < V_57 -> V_75 ; V_61 ++ )
F_17 ( V_2 , V_61 , V_4 -> V_36 [ V_61 ] ) ;
F_33 ( V_2 -> V_82 , L_6 , V_2 -> V_65 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_35 ( V_2 ) ;
if ( V_2 -> V_70 ) {
F_36 ( V_2 , & V_2 -> V_70 [ 1 ] ) ;
F_36 ( V_2 , & V_2 -> V_70 [ 2 ] ) ;
}
if ( V_55 ) {
if ( V_2 -> V_68 )
F_37 ( V_55 ) ;
}
}
static int T_1 F_38 ( struct V_54 * V_2 ,
const struct V_84 * V_85 )
{
return F_39 ( V_2 , & V_86 ) ;
}
static void T_2 F_40 ( struct V_54 * V_2 )
{
F_41 ( V_2 ) ;
}
