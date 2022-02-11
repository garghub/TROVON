static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_8 -> V_9 &= ~ V_7 [ 0 ] ;
V_8 -> V_9 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_8 -> V_9 , V_2 -> V_10 + V_11 ) ;
}
V_7 [ 1 ] = F_3 ( V_2 -> V_10 + V_11 ) ;
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_13 = 0xff ;
V_8 -> V_14 &= ~ ( 1 << 5 ) ;
} else {
V_4 -> V_13 = 0 ;
V_8 -> V_14 |= ( 1 << 5 ) ;
}
F_2 ( V_8 -> V_14 , V_2 -> V_10 + V_15 ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
}
V_7 [ 1 ] = ( F_3 ( V_2 -> V_10 + V_16 ) >> 3 ) ;
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] &= 0x0f ;
if ( V_7 [ 0 ] ) {
V_8 -> V_14 &= ~ V_7 [ 0 ] ;
V_8 -> V_14 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_8 -> V_14 , V_2 -> V_10 + V_15 ) ;
}
V_7 [ 1 ] = V_8 -> V_14 & 0xf ;
return V_6 -> V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * V_18 )
{
int V_19 = 0 ;
int V_20 ;
V_20 = V_18 -> V_21 ;
V_18 -> V_21 &= V_22 ;
if ( ! V_18 -> V_21 || V_20 != V_18 -> V_21 )
V_19 ++ ;
V_20 = V_18 -> V_23 ;
V_18 -> V_23 &= V_24 ;
if ( ! V_18 -> V_23 || V_20 != V_18 -> V_23 )
V_19 ++ ;
V_20 = V_18 -> V_25 ;
V_18 -> V_25 &= V_26 ;
if ( ! V_18 -> V_25 || V_20 != V_18 -> V_25 )
V_19 ++ ;
V_20 = V_18 -> V_27 ;
V_18 -> V_27 &= V_28 ;
if ( ! V_18 -> V_27 || V_20 != V_18 -> V_27 )
V_19 ++ ;
V_20 = V_18 -> V_29 ;
V_18 -> V_29 &= V_30 ;
if ( ! V_18 -> V_29 || V_20 != V_18 -> V_29 )
V_19 ++ ;
if ( V_19 )
return 1 ;
if ( V_19 )
return 2 ;
if ( V_18 -> V_31 != 0 ) {
V_18 -> V_31 = 0 ;
V_19 ++ ;
}
if ( V_18 -> V_32 != 0 ) {
V_18 -> V_32 = 0 ;
V_19 ++ ;
}
if ( V_18 -> V_33 != 0 ) {
V_18 -> V_33 = 0 ;
V_19 ++ ;
}
if ( V_18 -> V_34 != 1 ) {
V_18 -> V_34 = 1 ;
V_19 ++ ;
}
if ( V_18 -> V_35 != 0 ) {
V_18 -> V_35 = 0 ;
V_19 ++ ;
}
if ( V_19 )
return 3 ;
if ( V_19 )
return 4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_8 -> V_14 |= 0x10 ;
F_2 ( V_8 -> V_14 , V_2 -> V_10 + V_15 ) ;
V_8 -> V_36 = 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_11 ( V_37 L_1 ) ;
V_8 -> V_14 &= ~ 0x10 ;
F_2 ( V_8 -> V_14 , V_2 -> V_10 + V_15 ) ;
V_8 -> V_36 = 0 ;
return 0 ;
}
static T_1 F_12 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_3 * V_4 = V_2 -> V_40 + 3 ;
if ( ! V_8 -> V_36 ) {
F_11 ( V_41 L_2 ) ;
return V_42 ;
}
F_13 ( V_4 -> V_43 , 0 ) ;
V_4 -> V_43 -> V_44 |= V_45 | V_46 ;
F_14 ( V_2 , V_4 ) ;
return V_47 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_50 ;
unsigned int V_38 ;
unsigned long V_10 ;
struct V_3 * V_4 ;
V_10 = V_49 -> V_51 [ 0 ] ;
F_11 ( V_52 L_3 , V_2 -> V_53 , V_10 ) ;
if ( ! F_16 ( V_10 , V_54 , L_4 ) ) {
F_11 ( V_41 L_5 ) ;
return - V_55 ;
}
V_2 -> V_10 = V_10 ;
V_38 = V_49 -> V_51 [ 1 ] ;
if ( V_38 ) {
F_11 ( V_52 L_6 , V_38 ) ;
V_50 = F_17 ( V_38 , F_12 , 0 , L_7 ,
V_2 ) ;
if ( V_50 < 0 ) {
F_11 ( V_41 L_8 ) ;
return - V_56 ;
}
V_2 -> V_38 = V_38 ;
}
V_2 -> V_57 = L_9 ;
V_50 = F_18 ( V_2 , 4 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_19 ( V_2 , sizeof( struct V_58 ) ) ;
if ( V_50 < 0 )
return V_50 ;
V_4 = V_2 -> V_40 + 0 ;
V_4 -> type = V_59 ;
V_4 -> V_60 = V_61 | V_62 ;
V_4 -> V_63 = 8 ;
V_4 -> V_64 = 1 ;
V_4 -> V_65 = & V_66 ;
V_4 -> V_67 = F_1 ;
V_4 -> V_68 = F_4 ;
V_4 = V_2 -> V_40 + 1 ;
V_4 -> type = V_69 ;
V_4 -> V_60 = V_61 ;
V_4 -> V_63 = 5 ;
V_4 -> V_64 = 1 ;
V_4 -> V_65 = & V_66 ;
V_4 -> V_67 = F_5 ;
V_4 = V_2 -> V_40 + 2 ;
V_4 -> type = V_70 ;
V_4 -> V_60 = V_62 ;
V_4 -> V_63 = 4 ;
V_4 -> V_64 = 1 ;
V_4 -> V_65 = & V_66 ;
V_4 -> V_67 = F_6 ;
V_4 = V_2 -> V_40 + 3 ;
if ( V_38 ) {
V_2 -> V_71 = V_4 ;
V_4 -> type = V_69 ;
V_4 -> V_60 = V_61 | V_72 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = 1 ;
V_4 -> V_65 = & V_66 ;
V_4 -> V_67 = F_7 ;
V_4 -> V_73 = F_8 ;
V_4 -> V_74 = F_9 ;
V_4 -> V_75 = F_10 ;
} else {
V_4 -> type = V_76 ;
}
V_8 -> V_9 = 0 ;
F_2 ( V_8 -> V_9 , V_2 -> V_10 + V_11 ) ;
V_8 -> V_14 = 0 ;
F_2 ( V_8 -> V_14 , V_2 -> V_10 + V_15 ) ;
F_11 ( V_52 L_10 ) ;
return 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 )
F_21 ( V_2 -> V_10 , V_54 ) ;
if ( V_2 -> V_38 )
F_22 ( V_2 -> V_38 , V_2 ) ;
}
