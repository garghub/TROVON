static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 & 0x00ff , V_2 -> V_4 + V_5 ) ;
F_2 ( ( V_3 >> 8 ) & 0x00ff , V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 , int V_7 )
{
T_1 V_8 , V_9 , V_10 , V_11 ;
V_8 = 0 ;
V_9 = 0x0004 ;
V_10 = ( V_6 << 6 ) & 0x00c0 ;
switch ( V_6 / 4 ) {
case 0 :
V_11 = 0x0001 ;
break;
case 1 :
V_11 = 0x0002 ;
break;
case 2 :
V_11 = 0x0005 ;
break;
case 3 :
V_11 = 0x0006 ;
break;
case 4 :
V_11 = 0x0041 ;
break;
case 5 :
V_11 = 0x0042 ;
break;
default:
V_11 = 0 ;
break;
}
V_10 |= 0x0800 ;
V_11 |= 0xc000 ;
F_1 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_10 ) ;
F_1 ( V_2 , V_11 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_18 ) ;
if ( V_17 & V_16 )
return 0 ;
return - V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
int V_7 , V_6 ;
int V_21 ;
int V_22 ;
F_2 ( V_23 |
V_24 |
V_25 , V_2 -> V_4 + V_18 ) ;
F_7 ( 1000000 , V_2 -> V_4 + V_26 ) ;
F_2 ( 0 , V_2 -> V_4 + V_27 ) ;
V_7 = F_8 ( V_15 -> V_28 ) ;
V_6 = F_9 ( V_15 -> V_28 ) ;
for ( V_22 = 0 ; V_22 < V_15 -> V_29 ; V_22 ++ ) {
F_3 ( V_2 , V_6 , V_7 ) ;
F_2 ( V_30 , V_2 -> V_4 + V_18 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_31 ) ;
if ( V_21 )
return V_21 ;
F_2 ( V_32 , V_2 -> V_4 + V_18 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_33 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_34 ) ;
if ( V_21 )
return V_21 ;
V_20 [ V_22 ] = F_5 ( V_2 -> V_4 + V_35 ) ;
F_2 ( V_36 , V_2 -> V_4 + V_18 ) ;
F_2 ( V_37 , V_2 -> V_4 + V_18 ) ;
}
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_6 = F_9 ( V_15 -> V_28 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_15 -> V_29 ; V_22 ++ )
V_20 [ V_22 ] = V_39 -> V_41 [ V_6 ] ;
return V_22 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
unsigned int V_6 = F_9 ( V_15 -> V_28 ) ;
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_42 ) ;
if ( ( V_17 & ( ( V_6 + 1 ) * 0x0010 ) ) == 0 )
return 0 ;
return - V_19 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_6 = F_9 ( V_15 -> V_28 ) ;
int V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_15 -> V_29 ; V_22 ++ ) {
#if 0
writew((chan + 2) * 0x0010 | 0x0001, dev->mmio + dacControl);
udelay(1000);
#endif
F_2 ( V_20 [ V_22 ] , V_2 -> V_4 + F_14 ( V_6 ) ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_12 , 0 ) ;
if ( V_21 )
return V_21 ;
V_39 -> V_41 [ V_6 ] = V_20 [ V_22 ] ;
#if 0
writew((chan + 2) * 0x0010 | 0x0000, dev->mmio + dacControl);
udelay(1000);
#endif
}
return V_22 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
F_7 ( V_43 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_45 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
F_7 ( V_46 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_47 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_46 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
F_7 ( V_48 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_49 , V_39 -> V_44 + 0x6c ) ;
F_16 ( 10 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_50 )
{
int V_51 = 0 ;
int V_22 ;
int V_52 ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
V_52 = F_5 ( V_2 -> V_4 + 0x1000 ) ;
if ( ( V_52 & V_50 ) == V_50 ) {
V_51 = 1 ;
break;
}
F_20 ( 100 ) ;
}
F_20 ( 5 ) ;
return V_51 ;
}
static int F_21 ( struct V_1 * V_2 , int V_20 )
{
int V_51 = 0 ;
F_20 ( 10 ) ;
F_2 ( V_20 , V_2 -> V_4 + 0x1000 ) ;
if ( ( F_5 ( V_2 -> V_4 + 0x1000 ) & V_53 ) ==
V_53 ) {
V_51 = 1 ;
}
return V_51 ;
}
static int F_22 ( struct V_1 * V_2 ,
const T_2 * V_54 , T_3 V_55 ,
unsigned long V_16 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_51 = - V_56 ;
int V_57 ;
int V_58 ;
T_3 V_22 ;
V_57 = F_23 ( V_39 -> V_44 + 0x6c ) ;
if ( ! ( V_57 & V_59 ) )
return - V_56 ;
for ( V_58 = 0 ; V_58 < 3 ; V_58 ++ ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( F_19 ( V_2 , V_53 ) ) {
for ( V_22 = 0 ; V_22 < V_55 ; V_22 ++ ) {
if ( V_54 [ V_22 ] == 0xff &&
V_54 [ V_22 + 1 ] == 0x20 )
break;
}
for (; V_22 < V_55 ; V_22 += 2 ) {
int V_20 =
( V_54 [ V_22 ] << 8 ) + V_54 [ V_22 + 1 ] ;
if ( ! F_21 ( V_2 , V_20 ) )
break;
}
if ( V_22 >= V_55 ) {
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
F_20 ( 2 ) ;
F_2 ( V_60 | V_61 ,
V_2 -> V_4 + V_62 ) ;
F_20 ( 2 ) ;
F_2 ( V_63 | V_61 ,
V_2 -> V_4 + V_62 ) ;
F_20 ( 2 ) ;
F_2 ( V_37 , V_2 -> V_4 + V_18 ) ;
F_20 ( 2 ) ;
F_2 ( V_36 , V_2 -> V_4 + V_18 ) ;
F_24 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_64 ;
int V_65 ;
F_2 ( 0x80 | V_66 , V_2 -> V_4 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_64 = F_5 ( V_2 -> V_4 + V_42 ) ;
if ( ( V_64 & V_68 ) == 0 )
break;
F_20 ( 2 ) ;
}
F_2 ( 0x80 | V_69 , V_2 -> V_4 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_64 = F_5 ( V_2 -> V_4 + V_42 ) ;
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
static int F_32 ( int V_70 , int V_71 , int V_20 ,
unsigned long V_72 )
{
void T_4 * V_73 = ( void T_4 * ) V_72 ;
if ( V_70 ) {
F_2 ( V_20 , V_73 + V_71 * 2 ) ;
return 0 ;
}
return F_5 ( V_73 + V_71 * 2 ) ;
}
static const void * F_33 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
const struct V_76 * V_77 ;
int V_22 ;
if ( V_75 -> V_78 != V_79 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_34 ( V_80 ) ; V_22 ++ ) {
V_77 = & V_80 [ V_22 ] ;
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
struct V_38 * V_39 ;
struct V_12 * V_13 ;
int V_51 ;
V_77 = F_33 ( V_2 , V_75 ) ;
if ( ! V_77 )
return - V_83 ;
V_2 -> V_84 = V_77 ;
V_2 -> V_85 = V_77 -> V_86 ;
V_39 = F_37 ( V_2 , sizeof( * V_39 ) ) ;
if ( ! V_39 )
return - V_87 ;
V_51 = F_38 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_39 -> V_44 = F_39 ( V_75 , 0 ) ;
V_2 -> V_4 = F_39 ( V_75 , 2 ) ;
if ( ! V_39 -> V_44 || ! V_2 -> V_4 )
return - V_87 ;
V_51 = F_40 ( V_2 , 3 ) ;
if ( V_51 )
return V_51 ;
F_23 ( V_39 -> V_44 + 0x6c ) ;
V_51 = F_41 ( V_2 , & F_36 ( V_2 ) -> V_2 ,
V_88 ,
F_22 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
V_13 = & V_2 -> V_89 [ 0 ] ;
V_13 -> type = V_90 ;
V_13 -> V_91 = V_92 | V_93 ;
V_13 -> V_94 = 24 ;
V_13 -> V_95 = 0xffff ;
V_13 -> V_96 = F_6 ;
V_13 -> V_97 = & V_98 ;
V_13 = & V_2 -> V_89 [ 1 ] ;
V_13 -> type = V_99 ;
V_13 -> V_91 = V_100 ;
V_13 -> V_94 = 2 ;
V_13 -> V_95 = 0xffff ;
V_13 -> V_96 = F_11 ;
V_13 -> V_101 = F_13 ;
V_13 -> V_97 = & V_102 ;
V_13 = & V_2 -> V_89 [ 2 ] ;
V_51 = F_42 ( V_2 , V_13 , F_32 ,
( unsigned long ) ( V_2 -> V_4 + V_103 ) ) ;
if ( V_51 )
return V_51 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
if ( V_2 -> V_104 )
F_44 ( V_2 -> V_104 , V_2 ) ;
if ( V_39 ) {
if ( V_2 -> V_4 )
F_45 ( V_2 -> V_4 ) ;
if ( V_39 -> V_44 )
F_45 ( V_39 -> V_44 ) ;
}
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_74 * V_2 ,
const struct V_105 * V_81 )
{
return F_48 ( V_2 , & V_106 ,
V_81 -> V_107 ) ;
}
