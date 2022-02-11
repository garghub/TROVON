static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_8 [ 0 ] ) {
V_9 -> V_10 &= ~ V_8 [ 0 ] ;
V_9 -> V_10 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
F_6 ( V_9 -> V_10 , V_3 -> V_11 + V_12 ) ;
}
V_8 [ 1 ] = F_7 ( V_3 -> V_11 + V_12 ) ;
return 2 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_8 [ 0 ] ) {
V_5 -> V_13 = 0xff ;
V_9 -> V_14 &= ~ ( 1 << 5 ) ;
} else {
V_5 -> V_13 = 0 ;
V_9 -> V_14 |= ( 1 << 5 ) ;
}
F_6 ( V_9 -> V_14 , V_3 -> V_11 + V_15 ) ;
return 1 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_8 [ 0 ] ) {
}
V_8 [ 1 ] = ( F_7 ( V_3 -> V_11 + V_16 ) >> 3 ) ;
return 2 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
V_8 [ 0 ] &= 0x0f ;
if ( V_8 [ 0 ] ) {
V_9 -> V_14 &= ~ V_8 [ 0 ] ;
V_9 -> V_14 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
F_6 ( V_9 -> V_14 , V_3 -> V_11 + V_15 ) ;
}
V_8 [ 1 ] = V_9 -> V_14 & 0xf ;
return 2 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_17 < 1 )
return - V_18 ;
V_8 [ 1 ] = 0 ;
return 2 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
int V_22 ;
V_22 = V_20 -> V_23 ;
V_20 -> V_23 &= V_24 ;
if ( ! V_20 -> V_23 || V_22 != V_20 -> V_23 )
V_21 ++ ;
V_22 = V_20 -> V_25 ;
V_20 -> V_25 &= V_26 ;
if ( ! V_20 -> V_25 || V_22 != V_20 -> V_25 )
V_21 ++ ;
V_22 = V_20 -> V_27 ;
V_20 -> V_27 &= V_28 ;
if ( ! V_20 -> V_27 || V_22 != V_20 -> V_27 )
V_21 ++ ;
V_22 = V_20 -> V_29 ;
V_20 -> V_29 &= V_30 ;
if ( ! V_20 -> V_29 || V_22 != V_20 -> V_29 )
V_21 ++ ;
V_22 = V_20 -> V_31 ;
V_20 -> V_31 &= V_32 ;
if ( ! V_20 -> V_31 || V_22 != V_20 -> V_31 )
V_21 ++ ;
if ( V_21 )
return 1 ;
if ( V_21 )
return 2 ;
if ( V_20 -> V_33 != 0 ) {
V_20 -> V_33 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_34 != 0 ) {
V_20 -> V_34 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_35 != 0 ) {
V_20 -> V_35 = 0 ;
V_21 ++ ;
}
if ( V_20 -> V_36 != 1 ) {
V_20 -> V_36 = 1 ;
V_21 ++ ;
}
if ( V_20 -> V_37 != 0 ) {
V_20 -> V_37 = 0 ;
V_21 ++ ;
}
if ( V_21 )
return 3 ;
if ( V_21 )
return 4 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
V_9 -> V_14 |= 0x10 ;
F_6 ( V_9 -> V_14 , V_3 -> V_11 + V_15 ) ;
V_9 -> V_38 = 1 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_15 ( V_39 L_1 ) ;
V_9 -> V_14 &= ~ 0x10 ;
F_6 ( V_9 -> V_14 , V_3 -> V_11 + V_15 ) ;
V_9 -> V_38 = 0 ;
return 0 ;
}
static T_3 F_16 ( int V_40 , void * V_41 )
{
struct V_2 * V_3 = V_41 ;
struct V_4 * V_5 = V_3 -> V_42 + 3 ;
if ( ! V_9 -> V_38 ) {
F_15 ( V_43 L_2 ) ;
return V_44 ;
}
F_17 ( V_5 -> V_45 , 0 ) ;
V_5 -> V_45 -> V_46 |= V_47 | V_48 ;
F_18 ( V_3 , V_5 ) ;
return V_49 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
int V_52 ;
unsigned int V_40 ;
unsigned long V_11 ;
struct V_4 * V_5 ;
V_11 = V_51 -> V_53 [ 0 ] ;
F_15 ( V_54 L_3 , V_3 -> V_55 , V_11 ) ;
if ( ! F_20 ( V_11 , V_56 , L_4 ) ) {
F_15 ( V_43 L_5 ) ;
return - V_57 ;
}
V_3 -> V_11 = V_11 ;
V_40 = V_51 -> V_53 [ 1 ] ;
if ( V_40 ) {
F_15 ( V_54 L_6 , V_40 ) ;
V_52 = F_21 ( V_40 , F_16 , 0 , L_7 ,
V_3 ) ;
if ( V_52 < 0 ) {
F_15 ( V_43 L_8 ) ;
return - V_18 ;
}
V_3 -> V_40 = V_40 ;
}
V_3 -> V_58 = L_9 ;
V_52 = F_22 ( V_3 , 4 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_23 ( V_3 , sizeof( struct V_59 ) ) ;
if ( V_52 < 0 )
return V_52 ;
V_5 = V_3 -> V_42 + 0 ;
V_5 -> type = V_60 ;
V_5 -> V_61 = V_62 | V_63 ;
V_5 -> V_64 = 8 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_67 ;
V_5 -> V_68 = F_5 ;
V_5 -> V_69 = F_8 ;
V_5 = V_3 -> V_42 + 1 ;
V_5 -> type = V_70 ;
V_5 -> V_61 = V_62 ;
V_5 -> V_64 = 5 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_67 ;
V_5 -> V_68 = F_9 ;
V_5 = V_3 -> V_42 + 2 ;
V_5 -> type = V_71 ;
V_5 -> V_61 = V_63 ;
V_5 -> V_64 = 4 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_67 ;
V_5 -> V_68 = F_10 ;
V_5 = V_3 -> V_42 + 3 ;
if ( V_40 ) {
V_3 -> V_72 = V_5 ;
V_5 -> type = V_70 ;
V_5 -> V_61 = V_62 | V_73 ;
V_5 -> V_64 = 1 ;
V_5 -> V_65 = 1 ;
V_5 -> V_66 = & V_67 ;
V_5 -> V_68 = F_11 ;
V_5 -> V_74 = F_12 ;
V_5 -> V_75 = F_13 ;
V_5 -> V_76 = F_14 ;
} else {
V_5 -> type = V_77 ;
}
V_9 -> V_10 = 0 ;
F_6 ( V_9 -> V_10 , V_3 -> V_11 + V_12 ) ;
V_9 -> V_14 = 0 ;
F_6 ( V_9 -> V_14 , V_3 -> V_11 + V_15 ) ;
F_15 ( V_54 L_10 ) ;
return 1 ;
}
static int F_24 ( struct V_2 * V_3 )
{
F_15 ( V_54 L_11 , V_3 -> V_55 ) ;
if ( V_3 -> V_11 )
F_25 ( V_3 -> V_11 , V_56 ) ;
if ( V_3 -> V_40 )
F_26 ( V_3 -> V_40 , V_3 ) ;
return 0 ;
}
