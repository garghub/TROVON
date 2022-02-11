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
unsigned long V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 ;
V_20 = F_5 ( V_5 -> V_7 + V_21 ) ;
if ( V_20 & V_19 )
return 0 ;
return - V_22 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 , V_9 ;
int V_24 ;
int V_25 ;
F_2 ( V_26 |
V_27 |
V_28 , V_5 -> V_7 + V_21 ) ;
F_7 ( 1000000 , V_5 -> V_7 + V_29 ) ;
F_2 ( 0 , V_5 -> V_7 + V_30 ) ;
V_10 = F_8 ( V_18 -> V_31 ) ;
V_9 = F_9 ( V_18 -> V_31 ) ;
for ( V_25 = 0 ; V_25 < V_18 -> V_32 ; V_25 ++ ) {
F_3 ( V_2 , V_9 , V_10 ) ;
F_2 ( V_33 ,
V_5 -> V_7 + V_21 ) ;
V_24 = F_10 ( V_2 , V_16 , V_18 , F_4 ,
V_34 ) ;
if ( V_24 )
return V_24 ;
F_2 ( V_35 , V_5 -> V_7 + V_21 ) ;
V_24 = F_10 ( V_2 , V_16 , V_18 , F_4 ,
V_36 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_10 ( V_2 , V_16 , V_18 , F_4 ,
V_37 ) ;
if ( V_24 )
return V_24 ;
V_23 [ V_25 ] = F_5 ( V_5 -> V_7 + V_38 ) ;
F_2 ( V_39 , V_5 -> V_7 + V_21 ) ;
F_2 ( V_40 , V_5 -> V_7 + V_21 ) ;
}
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = F_9 ( V_18 -> V_31 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_18 -> V_32 ; V_25 ++ )
V_23 [ V_25 ] = V_5 -> V_41 [ V_9 ] ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned long V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_9 = F_9 ( V_18 -> V_31 ) ;
unsigned int V_20 ;
V_20 = F_5 ( V_5 -> V_7 + V_42 ) ;
if ( ( V_20 & ( ( V_9 + 1 ) * 0x0010 ) ) == 0 )
return 0 ;
return - V_22 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = F_9 ( V_18 -> V_31 ) ;
int V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_18 -> V_32 ; V_25 ++ ) {
#if 0
writew((chan + 2) * 0x0010 | 0x0001,
devpriv->daq + dacControl);
udelay(1000);
#endif
F_2 ( V_23 [ V_25 ] , V_5 -> V_7 + F_14 ( V_9 ) ) ;
V_24 = F_10 ( V_2 , V_16 , V_18 , F_12 , 0 ) ;
if ( V_24 )
return V_24 ;
V_5 -> V_41 [ V_9 ] = V_23 [ V_25 ] ;
#if 0
writew((chan + 2) * 0x0010 | 0x0000,
devpriv->daq + dacControl);
udelay(1000);
#endif
}
return V_25 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_7 ( V_43 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_45 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_7 ( V_46 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_47 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_46 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_7 ( V_48 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_49 , V_5 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_50 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_51 = 0 ;
int V_25 ;
int V_52 ;
for ( V_25 = 0 ; V_25 < 50 ; V_25 ++ ) {
V_52 = F_5 ( V_5 -> V_7 + 0x1000 ) ;
if ( ( V_52 & V_50 ) == V_50 ) {
V_51 = 1 ;
break;
}
F_20 ( 100 ) ;
}
F_20 ( 5 ) ;
return V_51 ;
}
static int F_21 ( struct V_1 * V_2 , int V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_51 = 0 ;
F_20 ( 10 ) ;
F_2 ( V_23 , V_5 -> V_7 + 0x1000 ) ;
if ( ( F_5 ( V_5 -> V_7 + 0x1000 ) & V_53 ) ==
V_53 ) {
V_51 = 1 ;
}
return V_51 ;
}
static int F_22 ( struct V_1 * V_2 ,
const T_2 * V_54 , T_3 V_55 ,
unsigned long V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_51 = - V_56 ;
int V_57 ;
int V_58 ;
T_3 V_25 ;
V_57 = F_23 ( V_5 -> V_44 + 0x6c ) ;
if ( ! ( V_57 & V_59 ) )
return - V_56 ;
for ( V_58 = 0 ; V_58 < 3 ; V_58 ++ ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( F_19 ( V_2 , V_53 ) ) {
for ( V_25 = 0 ; V_25 < V_55 ; V_25 ++ ) {
if ( V_54 [ V_25 ] == 0xff &&
V_54 [ V_25 + 1 ] == 0x20 )
break;
}
for (; V_25 < V_55 ; V_25 += 2 ) {
int V_23 =
( V_54 [ V_25 ] << 8 ) + V_54 [ V_25 + 1 ] ;
if ( ! F_21 ( V_2 , V_23 ) )
break;
}
if ( V_25 >= V_55 ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
V_51 = 0 ;
break;
}
}
}
return V_51 ;
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_20 ( 2 ) ;
F_2 ( V_60 | V_61 ,
V_5 -> V_7 + V_62 ) ;
F_20 ( 2 ) ;
F_2 ( V_63 | V_61 ,
V_5 -> V_7 + V_62 ) ;
F_20 ( 2 ) ;
F_2 ( V_40 , V_5 -> V_7 + V_21 ) ;
F_20 ( 2 ) ;
F_2 ( V_39 , V_5 -> V_7 + V_21 ) ;
F_24 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_64 ;
int V_65 ;
F_2 ( 0x80 | V_66 , V_5 -> V_7 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_64 = F_5 ( V_5 -> V_7 + V_42 ) ;
if ( ( V_64 & V_68 ) == 0 )
break;
F_20 ( 2 ) ;
}
F_2 ( 0x80 | V_69 , V_5 -> V_7 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_64 = F_5 ( V_5 -> V_7 + V_42 ) ;
if ( ( V_64 & V_68 ) == 0 )
break;
F_20 ( 2 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
}
static int F_32 ( int V_70 , int V_71 , int V_23 ,
unsigned long V_72 )
{
void T_4 * V_73 = ( void T_4 * ) V_72 ;
if ( V_70 ) {
F_2 ( V_23 , V_73 + V_71 * 2 ) ;
return 0 ;
} else {
return F_5 ( V_73 + V_71 * 2 ) ;
}
}
static const void * F_33 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
const struct V_76 * V_77 ;
int V_25 ;
if ( V_75 -> V_78 != V_79 )
return NULL ;
for ( V_25 = 0 ; V_25 < F_34 ( V_80 ) ; V_25 ++ ) {
V_77 = & V_80 [ V_25 ] ;
if ( V_75 -> V_78 == V_77 -> V_81 )
return V_77 ;
}
return NULL ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned long V_82 )
{
struct V_74 * V_75 = F_36 ( V_2 ) ;
const struct V_76 * V_77 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_51 ;
V_77 = F_33 ( V_2 , V_75 ) ;
if ( ! V_77 )
return - V_83 ;
V_2 -> V_84 = V_77 ;
V_2 -> V_85 = V_77 -> V_86 ;
V_5 = F_37 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_87 ;
V_51 = F_38 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_5 -> V_44 = F_39 ( V_75 , 0 ) ;
V_5 -> V_7 = F_39 ( V_75 , 2 ) ;
if ( ! V_5 -> V_44 || ! V_5 -> V_7 )
return - V_87 ;
V_51 = F_40 ( V_2 , 3 ) ;
if ( V_51 )
return V_51 ;
F_23 ( V_5 -> V_44 + 0x6c ) ;
V_51 = F_41 ( V_2 , & F_36 ( V_2 ) -> V_2 ,
V_88 ,
F_22 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
V_16 = & V_2 -> V_89 [ 0 ] ;
V_16 -> type = V_90 ;
V_16 -> V_91 = V_92 | V_93 ;
V_16 -> V_94 = 24 ;
V_16 -> V_95 = 0xffff ;
V_16 -> V_96 = F_6 ;
V_16 -> V_97 = & V_98 ;
V_16 = & V_2 -> V_89 [ 1 ] ;
V_16 -> type = V_99 ;
V_16 -> V_91 = V_100 ;
V_16 -> V_94 = 2 ;
V_16 -> V_95 = 0xffff ;
V_16 -> V_96 = F_11 ;
V_16 -> V_101 = F_13 ;
V_16 -> V_97 = & V_102 ;
V_16 = & V_2 -> V_89 [ 2 ] ;
V_51 = F_42 ( V_2 , V_16 , F_32 ,
( unsigned long ) ( V_5 -> V_7 + V_103 ) ) ;
if ( V_51 )
return V_51 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_104 )
F_44 ( V_2 -> V_104 , V_2 ) ;
if ( V_5 ) {
if ( V_5 -> V_7 )
F_45 ( V_5 -> V_7 ) ;
if ( V_5 -> V_44 )
F_45 ( V_5 -> V_44 ) ;
}
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_74 * V_2 ,
const struct V_105 * V_81 )
{
return F_48 ( V_2 , & V_106 ,
V_81 -> V_107 ) ;
}
