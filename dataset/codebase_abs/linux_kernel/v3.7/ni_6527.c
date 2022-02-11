static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
if ( V_6 -> V_11 != 2 )
return - V_12 ;
if ( V_7 [ 0 ] != V_13 )
return - V_12 ;
if ( V_7 [ 1 ] ) {
V_10 = ( V_7 [ 1 ] + 100 ) / 200 ;
V_7 [ 1 ] = V_10 * 200 ;
if ( V_10 != V_14 -> V_15 ) {
F_3 ( V_10 & 0xff ,
V_14 -> V_16 -> V_17 + F_4 ( 0 ) ) ;
F_3 ( ( V_10 >> 8 ) & 0xff ,
V_14 -> V_16 -> V_17 + F_4 ( 1 ) ) ;
F_3 ( ( V_10 >> 16 ) & 0x0f ,
V_14 -> V_16 -> V_17 + F_4 ( 2 ) ) ;
F_3 ( V_18 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
V_14 -> V_15 = V_10 ;
}
V_14 -> V_20 |= 1 << V_8 ;
} else {
V_14 -> V_20 &= ~ ( 1 << V_8 ) ;
}
F_3 ( V_14 -> V_20 ,
V_14 -> V_16 -> V_17 + F_5 ( 0 ) ) ;
F_3 ( V_14 -> V_20 >> 8 ,
V_14 -> V_16 -> V_17 + F_5 ( 1 ) ) ;
F_3 ( V_14 -> V_20 >> 16 ,
V_14 -> V_16 -> V_17 + F_5 ( 2 ) ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 0 ) ) ;
V_7 [ 1 ] |= F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 1 ) ) << 8 ;
V_7 [ 1 ] |= F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 2 ) ) << 16 ;
return V_6 -> V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_21 &= ~ V_7 [ 0 ] ;
V_4 -> V_21 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0x0000ff ) {
F_3 ( ( V_4 -> V_21 ^ 0xff ) ,
V_14 -> V_16 -> V_17 + F_8 ( 3 ) ) ;
}
if ( V_7 [ 0 ] & 0x00ff00 ) {
F_3 ( ( V_4 -> V_21 >> 8 ) ^ 0xff ,
V_14 -> V_16 -> V_17 + F_8 ( 4 ) ) ;
}
if ( V_7 [ 0 ] & 0xff0000 ) {
F_3 ( ( V_4 -> V_21 >> 16 ) ^ 0xff ,
V_14 -> V_16 -> V_17 + F_8 ( 5 ) ) ;
}
}
V_7 [ 1 ] = V_4 -> V_21 ;
return V_6 -> V_11 ;
}
static T_1 F_10 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_3 * V_4 = & V_2 -> V_24 [ 2 ] ;
unsigned int V_25 ;
V_25 = F_7 ( V_14 -> V_16 -> V_17 + V_26 ) ;
if ( ( V_25 & V_27 ) == 0 )
return V_28 ;
if ( ( V_25 & V_29 ) == 0 )
return V_28 ;
F_3 ( V_30 | V_31 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_11 ( V_4 -> V_32 , 0 ) ;
V_4 -> V_32 -> V_33 |= V_34 ;
F_12 ( V_2 , V_4 ) ;
return V_35 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
V_38 |= F_14 ( & V_37 -> V_39 , V_40 ) ;
V_38 |= F_14 ( & V_37 -> V_41 , V_42 ) ;
V_38 |= F_14 ( & V_37 -> V_43 , V_44 ) ;
V_38 |= F_14 ( & V_37 -> V_45 , V_46 ) ;
V_38 |= F_14 ( & V_37 -> V_47 , V_46 ) ;
if ( V_38 )
return 1 ;
if ( V_38 )
return 2 ;
if ( V_37 -> V_48 != 0 ) {
V_37 -> V_48 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_49 != 0 ) {
V_37 -> V_49 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_50 != 0 ) {
V_37 -> V_50 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_51 != 1 ) {
V_37 -> V_51 = 1 ;
V_38 ++ ;
}
if ( V_37 -> V_52 != 0 ) {
V_37 -> V_52 = 0 ;
V_38 ++ ;
}
if ( V_38 )
return 3 ;
if ( V_38 )
return 4 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( V_30 | V_31 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_3 ( V_53 | V_54 |
V_55 | V_56 ,
V_14 -> V_16 -> V_17 + V_57 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + V_57 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_11 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_11 < 1 )
return - V_12 ;
if ( V_7 [ 0 ] != V_58 )
return - V_12 ;
F_3 ( V_7 [ 1 ] ,
V_14 -> V_16 -> V_17 + F_19 ( 0 ) ) ;
F_3 ( V_7 [ 1 ] >> 8 ,
V_14 -> V_16 -> V_17 + F_19 ( 1 ) ) ;
F_3 ( V_7 [ 1 ] >> 16 ,
V_14 -> V_16 -> V_17 + F_19 ( 2 ) ) ;
F_3 ( V_7 [ 2 ] ,
V_14 -> V_16 -> V_17 + F_20 ( 0 ) ) ;
F_3 ( V_7 [ 2 ] >> 8 ,
V_14 -> V_16 -> V_17 + F_20 ( 1 ) ) ;
F_3 ( V_7 [ 2 ] >> 16 ,
V_14 -> V_16 -> V_17 + F_20 ( 2 ) ) ;
return 2 ;
}
static const struct V_59 *
F_21 ( struct V_60 * V_61 )
{
unsigned int V_62 = V_61 -> V_63 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_22 ( V_64 ) ; V_11 ++ ) {
const struct V_59 * V_65 = & V_64 [ V_11 ] ;
if ( V_65 -> V_62 == V_62 )
return V_65 ;
}
return NULL ;
}
static int T_2 F_23 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_3 * V_4 ;
int V_66 ;
V_66 = F_24 ( V_2 , sizeof( struct V_67 ) ) ;
if ( V_66 < 0 )
return V_66 ;
V_2 -> V_68 = F_21 ( V_61 ) ;
if ( ! V_2 -> V_68 )
return - V_69 ;
V_14 -> V_16 = F_25 ( V_61 ) ;
if ( ! V_14 -> V_16 )
return - V_70 ;
V_66 = F_26 ( V_14 -> V_16 ) ;
if ( V_66 < 0 ) {
F_27 ( V_2 -> V_71 , L_1 ) ;
return V_66 ;
}
V_2 -> V_72 = V_73 -> V_74 ;
F_28 ( V_2 -> V_71 , L_2 , V_2 -> V_72 ,
F_7 ( V_14 -> V_16 -> V_17 + V_75 ) ) ;
V_66 = F_29 ( V_2 , 3 ) ;
if ( V_66 )
return V_66 ;
V_4 = & V_2 -> V_24 [ 0 ] ;
V_4 -> type = V_76 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_79 = 24 ;
V_4 -> V_80 = & V_81 ;
V_4 -> V_82 = 1 ;
V_4 -> V_83 = F_1 ;
V_4 -> V_84 = F_6 ;
V_4 = & V_2 -> V_24 [ 1 ] ;
V_4 -> type = V_85 ;
V_4 -> V_77 = V_78 | V_86 ;
V_4 -> V_79 = 24 ;
V_4 -> V_80 = & V_87 ;
V_4 -> V_82 = 1 ;
V_4 -> V_84 = F_9 ;
V_4 = & V_2 -> V_24 [ 2 ] ;
V_2 -> V_88 = V_4 ;
V_4 -> type = V_76 ;
V_4 -> V_77 = V_78 | V_89 ;
V_4 -> V_79 = 1 ;
V_4 -> V_80 = & V_87 ;
V_4 -> V_82 = 1 ;
V_4 -> V_90 = F_13 ;
V_4 -> V_91 = F_15 ;
V_4 -> V_92 = F_16 ;
V_4 -> V_84 = F_17 ;
V_4 -> V_83 = F_18 ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 0 ) ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 1 ) ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 2 ) ) ;
F_3 ( V_30 | V_31 | V_93 | V_18 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + V_57 ) ;
V_66 = F_30 ( F_31 ( V_14 -> V_16 ) , F_10 ,
V_94 , V_95 , V_2 ) ;
if ( V_66 < 0 )
F_32 ( V_2 -> V_71 , L_3 ) ;
else
V_2 -> V_22 = F_31 ( V_14 -> V_16 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_14 && V_14 -> V_16 && V_14 -> V_16 -> V_17 )
F_3 ( 0x00 ,
V_14 -> V_16 -> V_17 + V_57 ) ;
if ( V_2 -> V_22 )
F_34 ( V_2 -> V_22 , V_2 ) ;
if ( V_14 && V_14 -> V_16 ) {
F_35 ( V_14 -> V_16 ) ;
F_36 ( V_14 -> V_16 ) ;
}
}
static int T_2 F_37 ( struct V_60 * V_2 ,
const struct V_96 * V_97 )
{
return F_38 ( V_2 , & V_98 ) ;
}
static void T_3 F_39 ( struct V_60 * V_2 )
{
F_40 ( V_2 ) ;
}
