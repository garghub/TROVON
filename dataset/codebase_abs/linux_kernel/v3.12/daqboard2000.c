static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_3 & 0x00ff , V_5 -> V_7 + V_8 ) ;
F_2 ( ( V_3 >> 8 ) & 0x00ff , V_5 -> V_7 + V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
T_1 V_11 , V_12 , V_13 , V_14 ;
V_11 = 0 ;
V_12 = 0x0004 ;
V_13 = ( V_9 << 6 ) & 0x00c0 ;
switch ( V_9 / 4 ) {
case 0 :
V_14 = 0x0001 ;
break;
case 1 :
V_14 = 0x0002 ;
break;
case 2 :
V_14 = 0x0005 ;
break;
case 3 :
V_14 = 0x0006 ;
break;
case 4 :
V_14 = 0x0041 ;
break;
case 5 :
V_14 = 0x0042 ;
break;
default:
V_14 = 0 ;
break;
}
V_13 |= 0x0800 ;
V_14 |= 0xc000 ;
F_1 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_14 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 ;
int V_10 , V_9 , V_21 ;
int V_22 ;
F_2 ( V_23 |
V_24 |
V_25 , V_5 -> V_7 + V_26 ) ;
F_5 ( 1000000 , V_5 -> V_7 + V_27 ) ;
F_2 ( 0 , V_5 -> V_7 + V_28 ) ;
V_10 = F_6 ( V_18 -> V_29 ) ;
V_9 = F_7 ( V_18 -> V_29 ) ;
for ( V_22 = 0 ; V_22 < V_18 -> V_30 ; V_22 ++ ) {
F_3 ( V_2 , V_9 , V_10 ) ;
F_2 ( V_31 ,
V_5 -> V_7 + V_26 ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_26 ) ;
if ( V_20 & V_32 )
break;
}
F_2 ( V_33 , V_5 -> V_7 + V_26 ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_26 ) ;
if ( V_20 & V_34 )
break;
}
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_26 ) ;
if ( V_20 & V_35 )
break;
}
V_19 [ V_22 ] = F_8 ( V_5 -> V_7 + V_36 ) ;
F_2 ( V_37 , V_5 -> V_7 + V_26 ) ;
F_2 ( V_38 , V_5 -> V_7 + V_26 ) ;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = F_7 ( V_18 -> V_29 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_18 -> V_30 ; V_22 ++ )
V_19 [ V_22 ] = V_5 -> V_39 [ V_9 ] ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = F_7 ( V_18 -> V_29 ) ;
unsigned int V_20 ;
int V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_18 -> V_30 ; V_22 ++ ) {
#if 0
writew((chan + 2) * 0x0010 | 0x0001,
devpriv->daq + dacControl);
udelay(1000);
#endif
F_2 ( V_19 [ V_22 ] , V_5 -> V_7 + F_11 ( V_9 ) ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_40 ) ;
if ( ( V_20 & ( ( V_9 + 1 ) * 0x0010 ) ) == 0 )
break;
}
V_5 -> V_39 [ V_9 ] = V_19 [ V_22 ] ;
#if 0
writew((chan + 2) * 0x0010 | 0x0000,
devpriv->daq + dacControl);
udelay(1000);
#endif
}
return V_22 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_5 ( V_41 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
F_5 ( V_43 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_5 ( V_44 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
F_5 ( V_45 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
F_5 ( V_44 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_5 ( V_46 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
F_5 ( V_47 , V_5 -> V_42 + 0x6c ) ;
F_13 ( 10 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_48 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_49 = 0 ;
int V_22 ;
int V_50 ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
V_50 = F_8 ( V_5 -> V_7 + 0x1000 ) ;
if ( ( V_50 & V_48 ) == V_48 ) {
V_49 = 1 ;
break;
}
F_17 ( 100 ) ;
}
F_17 ( 5 ) ;
return V_49 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_49 = 0 ;
F_17 ( 10 ) ;
F_2 ( V_19 , V_5 -> V_7 + 0x1000 ) ;
if ( ( F_8 ( V_5 -> V_7 + 0x1000 ) & V_51 ) ==
V_51 ) {
V_49 = 1 ;
}
return V_49 ;
}
static int F_19 ( struct V_1 * V_2 ,
const T_2 * V_52 , T_3 V_53 ,
unsigned long V_54 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_49 = - V_55 ;
int V_56 ;
int V_57 ;
T_3 V_22 ;
V_56 = F_20 ( V_5 -> V_42 + 0x6c ) ;
if ( ! ( V_56 & V_58 ) )
return - V_55 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( F_16 ( V_2 , V_51 ) ) {
for ( V_22 = 0 ; V_22 < V_53 ; V_22 ++ ) {
if ( V_52 [ V_22 ] == 0xff &&
V_52 [ V_22 + 1 ] == 0x20 )
break;
}
for (; V_22 < V_53 ; V_22 += 2 ) {
int V_19 =
( V_52 [ V_22 ] << 8 ) + V_52 [ V_22 + 1 ] ;
if ( ! F_18 ( V_2 , V_19 ) )
break;
}
if ( V_22 >= V_53 ) {
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
V_49 = 0 ;
break;
}
}
}
return V_49 ;
}
static void F_21 ( struct V_1 * V_2 )
{
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_17 ( 2 ) ;
F_2 ( V_59 | V_60 ,
V_5 -> V_7 + V_61 ) ;
F_17 ( 2 ) ;
F_2 ( V_62 | V_60 ,
V_5 -> V_7 + V_61 ) ;
F_17 ( 2 ) ;
F_2 ( V_38 , V_5 -> V_7 + V_26 ) ;
F_17 ( 2 ) ;
F_2 ( V_37 , V_5 -> V_7 + V_26 ) ;
F_21 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 ;
int V_21 ;
F_2 ( 0x80 | V_63 , V_5 -> V_7 + V_64 ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_40 ) ;
if ( ( V_20 & V_65 ) == 0 )
break;
F_17 ( 2 ) ;
}
F_2 ( 0x80 | V_66 , V_5 -> V_7 + V_64 ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_20 = F_8 ( V_5 -> V_7 + V_40 ) ;
if ( ( V_20 & V_65 ) == 0 )
break;
F_17 ( 2 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
static int F_29 ( int V_67 , int V_68 , int V_19 ,
unsigned long V_69 )
{
void T_4 * V_70 = ( void T_4 * ) V_69 ;
if ( V_67 ) {
F_2 ( V_19 , V_70 + V_68 * 2 ) ;
return 0 ;
} else {
return F_8 ( V_70 + V_68 * 2 ) ;
}
}
static const void * F_30 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
const struct V_73 * V_74 ;
int V_22 ;
if ( V_72 -> V_75 != V_76 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_31 ( V_77 ) ; V_22 ++ ) {
V_74 = & V_77 [ V_22 ] ;
if ( V_72 -> V_75 == V_74 -> V_78 )
return V_74 ;
}
return NULL ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned long V_79 )
{
struct V_71 * V_72 = F_33 ( V_2 ) ;
const struct V_73 * V_74 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_49 ;
V_74 = F_30 ( V_2 , V_72 ) ;
if ( ! V_74 )
return - V_80 ;
V_2 -> V_81 = V_74 ;
V_2 -> V_82 = V_74 -> V_83 ;
V_5 = F_34 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_84 ;
V_49 = F_35 ( V_2 ) ;
if ( V_49 )
return V_49 ;
V_5 -> V_42 = F_36 ( V_72 , 0 ) ;
V_5 -> V_7 = F_36 ( V_72 , 2 ) ;
if ( ! V_5 -> V_42 || ! V_5 -> V_7 )
return - V_84 ;
V_49 = F_37 ( V_2 , 3 ) ;
if ( V_49 )
return V_49 ;
F_20 ( V_5 -> V_42 + 0x6c ) ;
V_49 = F_38 ( V_2 , & F_33 ( V_2 ) -> V_2 ,
V_85 ,
F_19 , 0 ) ;
if ( V_49 < 0 )
return V_49 ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
V_16 = & V_2 -> V_86 [ 0 ] ;
V_16 -> type = V_87 ;
V_16 -> V_88 = V_89 | V_90 ;
V_16 -> V_91 = 24 ;
V_16 -> V_92 = 0xffff ;
V_16 -> V_93 = F_4 ;
V_16 -> V_94 = & V_95 ;
V_16 = & V_2 -> V_86 [ 1 ] ;
V_16 -> type = V_96 ;
V_16 -> V_88 = V_97 ;
V_16 -> V_91 = 2 ;
V_16 -> V_92 = 0xffff ;
V_16 -> V_93 = F_9 ;
V_16 -> V_98 = F_10 ;
V_16 -> V_94 = & V_99 ;
V_16 = & V_2 -> V_86 [ 2 ] ;
V_49 = F_39 ( V_2 , V_16 , F_29 ,
( unsigned long ) ( V_5 -> V_7 + V_100 ) ) ;
if ( V_49 )
return V_49 ;
F_40 ( V_2 -> V_101 , L_1 ,
V_2 -> V_102 -> V_103 , V_2 -> V_82 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_104 )
F_42 ( V_2 -> V_104 , V_2 ) ;
if ( V_5 ) {
if ( V_5 -> V_7 )
F_43 ( V_5 -> V_7 ) ;
if ( V_5 -> V_42 )
F_43 ( V_5 -> V_42 ) ;
}
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_71 * V_2 ,
const struct V_105 * V_78 )
{
return F_46 ( V_2 , & V_106 ,
V_78 -> V_107 ) ;
}
