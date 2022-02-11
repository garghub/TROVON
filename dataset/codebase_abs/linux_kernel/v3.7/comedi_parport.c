static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] ) {
V_9 -> V_11 &= ~ V_7 [ 0 ] ;
V_9 -> V_11 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_9 -> V_11 , V_2 -> V_12 + V_13 ) ;
}
V_7 [ 1 ] = F_3 ( V_2 -> V_12 + V_13 ) ;
return V_6 -> V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_15 = 0xff ;
V_9 -> V_16 &= ~ ( 1 << 5 ) ;
} else {
V_4 -> V_15 = 0 ;
V_9 -> V_16 |= ( 1 << 5 ) ;
}
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
}
V_7 [ 1 ] = ( F_3 ( V_2 -> V_12 + V_18 ) >> 3 ) ;
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] &= 0x0f ;
if ( V_7 [ 0 ] ) {
V_9 -> V_16 &= ~ V_7 [ 0 ] ;
V_9 -> V_16 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
}
V_7 [ 1 ] = V_9 -> V_16 & 0xf ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
V_21 |= F_9 ( & V_20 -> V_22 , V_23 ) ;
V_21 |= F_9 ( & V_20 -> V_24 , V_25 ) ;
V_21 |= F_9 ( & V_20 -> V_26 , V_27 ) ;
V_21 |= F_9 ( & V_20 -> V_28 , V_29 ) ;
V_21 |= F_9 ( & V_20 -> V_30 , V_31 ) ;
if ( V_21 )
return 1 ;
if ( V_21 )
return 2 ;
if ( V_20 -> V_32 != 0 ) {
V_20 -> V_32 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_33 != 0 ) {
V_20 -> V_33 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_34 != 0 ) {
V_20 -> V_34 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_35 != 1 ) {
V_20 -> V_35 = 1 ;
V_21 ++ ;
}
if ( V_20 -> V_36 != 0 ) {
V_20 -> V_36 = 0 ;
V_21 ++ ;
}
if ( V_21 )
return 3 ;
if ( V_21 )
return 4 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_16 |= 0x10 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
V_9 -> V_37 = 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_16 &= ~ 0x10 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
V_9 -> V_37 = 0 ;
return 0 ;
}
static T_1 F_12 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_40 [ 3 ] ;
if ( ! V_9 -> V_37 )
return V_41 ;
F_13 ( V_4 -> V_42 , 0 ) ;
V_4 -> V_42 -> V_43 |= V_44 | V_45 ;
F_14 ( V_2 , V_4 ) ;
return V_46 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 ;
int V_49 ;
unsigned int V_38 ;
unsigned long V_12 ;
struct V_3 * V_4 ;
V_2 -> V_50 = V_2 -> V_51 -> V_52 ;
V_12 = V_48 -> V_53 [ 0 ] ;
if ( ! F_16 ( V_12 , V_54 , V_2 -> V_50 ) ) {
F_17 ( V_2 -> V_55 , L_1 ) ;
return - V_56 ;
}
V_2 -> V_12 = V_12 ;
V_38 = V_48 -> V_53 [ 1 ] ;
if ( V_38 ) {
V_49 = F_18 ( V_38 , F_12 , 0 , V_2 -> V_50 ,
V_2 ) ;
if ( V_49 < 0 ) {
F_17 ( V_2 -> V_55 , L_2 ) ;
return - V_57 ;
}
V_2 -> V_38 = V_38 ;
}
V_49 = F_19 ( V_2 , 4 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_20 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_49 < 0 )
return V_49 ;
V_9 = V_2 -> V_10 ;
V_4 = & V_2 -> V_40 [ 0 ] ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_60 | V_61 ;
V_4 -> V_62 = 8 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = F_1 ;
V_4 -> V_67 = F_4 ;
V_4 = & V_2 -> V_40 [ 1 ] ;
V_4 -> type = V_68 ;
V_4 -> V_59 = V_60 ;
V_4 -> V_62 = 5 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = F_5 ;
V_4 = & V_2 -> V_40 [ 2 ] ;
V_4 -> type = V_69 ;
V_4 -> V_59 = V_61 ;
V_4 -> V_62 = 4 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = F_6 ;
V_4 = & V_2 -> V_40 [ 3 ] ;
if ( V_38 ) {
V_2 -> V_70 = V_4 ;
V_4 -> type = V_68 ;
V_4 -> V_59 = V_60 | V_71 ;
V_4 -> V_62 = 1 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = F_7 ;
V_4 -> V_72 = F_8 ;
V_4 -> V_73 = F_10 ;
V_4 -> V_74 = F_11 ;
} else {
V_4 -> type = V_75 ;
}
V_9 -> V_11 = 0 ;
F_2 ( V_9 -> V_11 , V_2 -> V_12 + V_13 ) ;
V_9 -> V_16 = 0 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
F_21 ( V_2 -> V_55 , L_3 ,
V_2 -> V_50 , V_2 -> V_12 , V_2 -> V_38 ? L_4 : L_5 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_23 ( V_2 -> V_12 , V_54 ) ;
if ( V_2 -> V_38 )
F_24 ( V_2 -> V_38 , V_2 ) ;
}
