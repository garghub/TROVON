static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ( int ) F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_4 )
{
T_1 V_5 [ 2 ] = { V_4 & 0xff , V_4 >> 8 , } ;
int V_6 ;
V_6 = F_6 ( V_2 , V_5 , 2 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] ;
int V_6 ;
V_6 = F_8 ( V_2 , V_5 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
return ( V_5 [ 1 ] << 8 ) | V_5 [ 0 ] ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
int V_6 ;
F_11 ( & V_11 -> V_12 ) ;
V_11 -> V_13 |= ( 1 << V_9 ) ;
V_6 = V_11 -> V_14 ( V_11 -> V_2 , V_11 -> V_13 ) ;
F_12 ( & V_11 -> V_12 ) ;
return V_6 ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
int V_15 ;
V_15 = V_11 -> V_16 ( V_11 -> V_2 ) ;
return ( V_15 < 0 ) ? 0 : ( V_15 & ( 1 << V_9 ) ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_9 , int V_15 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
unsigned V_17 = 1 << V_9 ;
int V_6 ;
F_11 ( & V_11 -> V_12 ) ;
if ( V_15 )
V_11 -> V_13 |= V_17 ;
else
V_11 -> V_13 &= ~ V_17 ;
V_6 = V_11 -> V_14 ( V_11 -> V_2 , V_11 -> V_13 ) ;
F_12 ( & V_11 -> V_12 ) ;
return V_6 ;
}
static void F_15 ( struct V_7 * V_8 , unsigned V_9 , int V_15 )
{
F_14 ( V_8 , V_9 , V_15 ) ;
}
static T_2 F_16 ( int V_18 , void * V_3 )
{
struct V_10 * V_11 = V_3 ;
unsigned long V_19 , V_20 , V_6 , V_21 ;
V_6 = V_11 -> V_16 ( V_11 -> V_2 ) ;
F_17 ( & V_11 -> V_22 , V_21 ) ;
V_19 = ( V_11 -> V_6 ^ V_6 ) & V_11 -> V_23 ;
F_18 (i, &change, gpio->chip.ngpio)
F_19 ( F_20 ( V_11 -> V_8 . V_24 , V_20 ) ) ;
V_11 -> V_6 = V_6 ;
F_21 ( & V_11 -> V_22 , V_21 ) ;
return V_25 ;
}
static void F_22 ( struct V_26 * V_3 ) { }
static int F_23 ( struct V_26 * V_3 , unsigned int V_27 )
{
struct V_10 * V_11 = F_24 ( V_3 ) ;
int error = 0 ;
if ( V_11 -> V_28 ) {
error = F_25 ( V_11 -> V_28 , V_27 ) ;
if ( error ) {
F_26 ( & V_11 -> V_2 -> V_29 ,
L_1 ,
V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
}
}
return error ;
}
static void F_27 ( struct V_26 * V_3 )
{
struct V_10 * V_11 = F_24 ( V_3 ) ;
V_11 -> V_23 |= ( 1 << V_3 -> V_30 ) ;
}
static void F_28 ( struct V_26 * V_3 )
{
struct V_10 * V_11 = F_24 ( V_3 ) ;
V_11 -> V_23 &= ~ ( 1 << V_3 -> V_30 ) ;
}
static void F_29 ( struct V_26 * V_3 )
{
struct V_10 * V_11 = F_24 ( V_3 ) ;
F_11 ( & V_11 -> V_12 ) ;
}
static void F_30 ( struct V_26 * V_3 )
{
struct V_10 * V_11 = F_24 ( V_3 ) ;
F_12 ( & V_11 -> V_12 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_33 * V_34 = F_32 ( & V_2 -> V_29 ) ;
struct V_35 * V_36 = V_2 -> V_29 . V_37 ;
struct V_10 * V_11 ;
unsigned int V_38 = 0 ;
int V_6 ;
if ( F_33 ( V_39 ) && V_36 )
F_34 ( V_36 , L_2 , & V_38 ) ;
else if ( V_34 )
V_38 = V_34 -> V_38 ;
else
F_26 ( & V_2 -> V_29 , L_3 ) ;
V_11 = F_35 ( & V_2 -> V_29 , sizeof( * V_11 ) , V_40 ) ;
if ( ! V_11 )
return - V_41 ;
F_36 ( & V_11 -> V_12 ) ;
F_37 ( & V_11 -> V_22 ) ;
V_11 -> V_8 . V_42 = V_34 ? V_34 -> V_43 : - 1 ;
V_11 -> V_8 . V_44 = true ;
V_11 -> V_8 . V_29 = & V_2 -> V_29 ;
V_11 -> V_8 . V_45 = V_46 ;
V_11 -> V_8 . V_47 = F_13 ;
V_11 -> V_8 . V_48 = F_15 ;
V_11 -> V_8 . V_49 = F_9 ;
V_11 -> V_8 . V_50 = F_14 ;
V_11 -> V_8 . V_51 = V_32 -> V_52 ;
if ( V_11 -> V_8 . V_51 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_38 ( V_2 -> V_53 ,
V_54 ) )
V_6 = - V_55 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_51 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_38 ( V_2 -> V_53 , V_56 ) )
V_6 = - V_55 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_26 ( & V_2 -> V_29 , L_4 ) ;
V_6 = - V_57 ;
}
if ( V_6 < 0 )
goto V_58;
V_11 -> V_8 . V_59 = V_2 -> V_60 ;
V_11 -> V_2 = V_2 ;
F_39 ( V_2 , V_11 ) ;
V_11 -> V_13 = ~ V_38 ;
V_11 -> V_6 = V_11 -> V_13 ;
V_6 = F_40 ( & V_11 -> V_8 ) ;
if ( V_6 < 0 )
goto V_58;
if ( V_2 -> V_18 ) {
V_6 = F_41 ( & V_11 -> V_8 , & V_61 ,
0 , V_62 ,
V_63 ) ;
if ( V_6 ) {
F_42 ( & V_2 -> V_29 , L_5 ) ;
goto V_64;
}
V_6 = F_43 ( & V_2 -> V_29 , V_2 -> V_18 ,
NULL , F_16 , V_65 |
V_66 | V_67 ,
F_44 ( & V_2 -> V_29 ) , V_11 ) ;
if ( V_6 )
goto V_64;
F_45 ( & V_11 -> V_8 , & V_61 ,
V_2 -> V_18 , NULL ) ;
V_11 -> V_28 = V_2 -> V_18 ;
}
if ( V_34 && V_34 -> V_68 ) {
V_6 = V_34 -> V_68 ( V_2 ,
V_11 -> V_8 . V_42 , V_11 -> V_8 . V_51 ,
V_34 -> V_69 ) ;
if ( V_6 < 0 )
F_46 ( & V_2 -> V_29 , L_6 , V_6 ) ;
}
F_47 ( & V_2 -> V_29 , L_7 ) ;
return 0 ;
V_64:
F_48 ( & V_11 -> V_8 ) ;
V_58:
F_26 ( & V_2 -> V_29 , L_8 , V_6 ,
V_2 -> V_60 ) ;
return V_6 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_32 ( & V_2 -> V_29 ) ;
struct V_10 * V_11 = F_50 ( V_2 ) ;
int V_6 = 0 ;
if ( V_34 && V_34 -> V_70 ) {
V_6 = V_34 -> V_70 ( V_2 ,
V_11 -> V_8 . V_42 , V_11 -> V_8 . V_51 ,
V_34 -> V_69 ) ;
if ( V_6 < 0 ) {
F_42 ( & V_2 -> V_29 , L_9 ,
L_10 , V_6 ) ;
return V_6 ;
}
}
F_48 ( & V_11 -> V_8 ) ;
return V_6 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_71 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_71 ) ;
}
