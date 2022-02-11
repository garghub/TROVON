static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
int V_9 ;
if ( F_2 ( V_2 , sizeof( struct V_10 ) ) < 0 )
return - V_11 ;
F_3 (pcidev) {
if ( V_8 -> V_12 == V_13 ) {
if ( V_4 -> V_14 [ 0 ] || V_4 -> V_14 [ 1 ] ) {
if ( V_8 -> V_15 -> V_16 != V_4 -> V_14 [ 0 ] ||
F_4 ( V_8 -> V_17 ) != V_4 -> V_14 [ 1 ] ) {
continue;
}
}
for ( V_9 = 0 ; V_9 < F_5 ( V_18 ) ; V_9 ++ ) {
if ( V_18 [ V_9 ] . V_19 ==
V_8 -> V_20 ) {
goto V_21;
}
}
}
}
if ( ! V_8 ) {
F_6 ( V_2 -> V_22 , L_1 ) ;
return - V_23 ;
}
V_21:
V_24 -> V_7 = V_8 ;
V_2 -> V_25 = V_18 + V_9 ;
F_7 ( V_2 -> V_22 , L_2 ,
V_26 -> V_27 ) ;
if ( F_8 ( V_8 , V_26 -> V_27 ) ) {
F_6 ( V_2 -> V_22 , L_3 ) ;
return - V_23 ;
}
V_24 -> V_28 =
F_9 ( V_24 -> V_7 , V_29 ) ;
V_24 -> V_30 = F_9 ( V_24 -> V_7 , V_31 ) ;
if ( V_26 -> V_32 == 2 )
F_10
( L_4
L_5
L_6 ) ;
V_2 -> V_33 = V_26 -> V_27 ;
if ( F_11 ( V_2 , 3 ) < 0 )
return - V_11 ;
V_6 = V_2 -> V_34 + 0 ;
V_6 -> type = V_35 ;
V_6 -> V_36 = V_37 ;
V_6 -> V_38 = V_26 -> V_39 ;
V_6 -> V_40 = ( 1 << V_26 -> V_41 ) - 1 ;
V_6 -> V_42 = V_26 -> V_43 ;
V_6 -> V_44 = V_45 ;
V_6 = V_2 -> V_34 + 1 ;
F_12 ( V_2 , V_6 , NULL , V_24 -> V_28 ) ;
V_6 = V_2 -> V_34 + 2 ;
F_12 ( V_2 , V_6 , NULL , V_24 -> V_28 + V_46 ) ;
F_7 ( V_2 -> V_22 , L_7 ) ;
for ( V_9 = 0 ; V_9 < V_47 ; V_9 ++ ) {
V_24 -> V_48 [ V_9 ] = F_13 ( V_2 , V_9 ) ;
F_7 ( V_2 -> V_22 , L_8 , V_9 , V_24 -> V_48 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_26 -> V_39 ; V_9 ++ )
F_14 ( V_2 , V_9 , V_24 -> V_49 [ V_9 ] ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( V_24 ) {
if ( V_24 -> V_7 ) {
if ( V_24 -> V_30 )
F_16 ( V_24 -> V_7 ) ;
F_17 ( V_24 -> V_7 ) ;
}
}
if ( V_2 -> V_34 ) {
F_18 ( V_2 , V_2 -> V_34 + 1 ) ;
F_18 ( V_2 , V_2 -> V_34 + 2 ) ;
}
return 0 ;
}
static int V_45 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
unsigned int V_53 ;
unsigned int V_54 , V_55 ;
V_54 = F_19 ( V_51 -> V_56 ) ;
V_55 = F_20 ( V_51 -> V_56 ) ;
if ( V_55 != V_24 -> V_49 [ V_54 ] )
F_14 ( V_2 , V_54 , V_55 ) ;
V_53 = V_57 | V_58 ;
switch ( V_55 ) {
case 0 :
V_53 |= V_59 | V_60 ;
break;
case 1 :
V_53 |= V_59 | V_61 ;
break;
case 2 :
V_53 |= V_59 | V_62 ;
break;
case 3 :
V_53 |= V_63 | V_60 ;
break;
case 4 :
V_53 |= V_63 | V_61 ;
break;
case 5 :
V_53 |= V_63 | V_62 ;
break;
}
V_53 |= V_54 << 2 ;
F_21 ( V_53 , V_24 -> V_30 + V_64 ) ;
F_21 ( V_52 [ 0 ] , V_24 -> V_30 + V_65 + V_54 * 2 ) ;
return 1 ;
}
static unsigned int F_22 ( struct V_1 * V_2 )
{
unsigned int V_66 = 0 ;
int V_67 ;
const int V_68 = 16 ;
for ( V_67 = 1 ; V_67 <= V_68 ; V_67 ++ ) {
if ( F_23 ( V_24 -> V_30 + V_69 ) & V_70 )
V_66 |= 1 << ( V_68 - V_67 ) ;
}
return V_66 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_66 ,
unsigned int V_71 )
{
int V_67 ;
for ( V_67 = 1 ; V_67 <= V_71 ; V_67 ++ ) {
if ( V_66 & ( 1 << ( V_71 - V_67 ) ) )
V_24 -> V_72 |= V_73 ;
else
V_24 -> V_72 &= ~ V_73 ;
F_25 ( V_24 -> V_72 , V_24 -> V_30 + V_69 ) ;
}
}
static unsigned int F_13 ( struct V_1 * V_2 ,
unsigned int V_74 )
{
unsigned int V_67 ;
unsigned int V_75 ;
unsigned int V_66 ;
const int V_76 = 4 ;
const int V_77 = 0x6 ;
const int V_78 = 3 ;
const int V_79 = 8 ;
V_75 = V_80 | V_81 | V_82 ;
for ( V_67 = 0 ; V_67 < V_76 ; V_67 ++ )
V_75 |= F_26 ( V_67 ) ;
F_25 ( V_75 , V_24 -> V_30 + V_83 ) ;
F_24 ( V_2 , V_77 , V_78 ) ;
F_24 ( V_2 , V_74 , V_79 ) ;
V_66 = F_22 ( V_2 ) ;
V_75 &= ~ V_80 ;
F_25 ( V_75 , V_24 -> V_30 + V_83 ) ;
return V_66 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_84 , unsigned int V_54 ,
unsigned int V_66 )
{
unsigned int V_75 ;
unsigned int V_67 ;
const int V_85 = 3 ;
const int V_86 = 8 ;
const int V_76 = 4 ;
F_24 ( V_2 , V_54 , V_85 ) ;
F_24 ( V_2 , V_66 , V_86 ) ;
V_75 = V_81 | V_82 ;
for ( V_67 = 0 ; V_67 < V_76 ; V_67 ++ )
V_75 |= F_26 ( V_67 ) ;
V_75 &= ~ F_26 ( V_84 ) ;
F_25 ( V_75 , V_24 -> V_30 + V_83 ) ;
V_75 |= F_26 ( V_84 ) ;
F_25 ( V_75 , V_24 -> V_30 + V_83 ) ;
}
static unsigned int F_28 ( unsigned int V_54 )
{
return V_54 / 2 ;
}
static unsigned int F_29 ( unsigned int V_87 )
{
return 4 * ( V_87 % 2 ) ;
}
static unsigned int F_30 ( unsigned int V_87 )
{
return 1 + 4 * ( V_87 % 2 ) ;
}
static unsigned int F_31 ( unsigned int V_87 )
{
return 2 + 4 * ( V_87 % 2 ) ;
}
static unsigned int F_32 ( unsigned int V_87 )
{
return 3 + 4 * ( V_87 % 2 ) ;
}
static unsigned int F_33 ( unsigned int V_87 ,
unsigned int V_55 )
{
return 0x7 + 2 * V_55 + 12 * V_87 ;
}
static unsigned int F_34 ( unsigned int V_87 ,
unsigned int V_55 )
{
return 0x8 + 2 * V_55 + 12 * V_87 ;
}
static unsigned int F_35 ( unsigned int V_88 )
{
return ( V_88 >> 8 ) & 0xff ;
}
static unsigned int F_36 ( unsigned int V_88 )
{
return V_88 & 0xff ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned int V_55 )
{
unsigned int V_89 , V_90 , V_91 , V_92 ;
V_24 -> V_49 [ V_54 ] = V_55 ;
V_89 =
F_35 ( V_24 -> V_48
[ F_33 ( V_54 , V_55 ) ] ) ;
V_90 =
F_36 ( V_24 -> V_48
[ F_33 ( V_54 , V_55 ) ] ) ;
V_91 =
F_35 ( V_24 -> V_48
[ F_34 ( V_54 , V_55 ) ] ) ;
V_92 =
F_36 ( V_24 -> V_48
[ F_34 ( V_54 , V_55 ) ] ) ;
F_27 ( V_2 , F_28 ( V_54 ) ,
F_31 ( V_54 ) , V_89 ) ;
F_27 ( V_2 , F_28 ( V_54 ) ,
F_32 ( V_54 ) , V_90 ) ;
F_27 ( V_2 , F_28 ( V_54 ) ,
F_30 ( V_54 ) , V_91 ) ;
F_27 ( V_2 , F_28 ( V_54 ) ,
F_29 ( V_54 ) , V_92 ) ;
}
static int T_1 F_37 ( struct V_7 * V_2 ,
const struct V_93 * V_94 )
{
return F_38 ( V_2 , V_95 . V_96 ) ;
}
static void T_2 F_39 ( struct V_7 * V_2 )
{
F_40 ( V_2 ) ;
}
static int T_3 F_41 ( void )
{
int V_97 ;
V_97 = F_42 ( & V_95 ) ;
if ( V_97 < 0 )
return V_97 ;
V_98 . V_27 = ( char * ) V_95 . V_96 ;
return F_43 ( & V_98 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_98 ) ;
F_46 ( & V_95 ) ;
}
