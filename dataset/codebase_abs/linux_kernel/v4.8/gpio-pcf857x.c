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
struct V_10 * V_11 = F_10 ( V_8 ) ;
int V_6 ;
F_11 ( & V_11 -> V_12 ) ;
V_11 -> V_13 |= ( 1 << V_9 ) ;
V_6 = V_11 -> V_14 ( V_11 -> V_2 , V_11 -> V_13 ) ;
F_12 ( & V_11 -> V_12 ) ;
return V_6 ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 ) ;
int V_15 ;
V_15 = V_11 -> V_16 ( V_11 -> V_2 ) ;
return ( V_15 < 0 ) ? V_15 : ! ! ( V_15 & ( 1 << V_9 ) ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_9 , int V_15 )
{
struct V_10 * V_11 = F_10 ( V_8 ) ;
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
unsigned long V_19 , V_20 , V_6 ;
V_6 = V_11 -> V_16 ( V_11 -> V_2 ) ;
F_11 ( & V_11 -> V_12 ) ;
V_19 = ( V_11 -> V_6 ^ V_6 ) & V_11 -> V_21 ;
V_11 -> V_6 = V_6 ;
F_12 ( & V_11 -> V_12 ) ;
F_17 (i, &change, gpio->chip.ngpio)
F_18 ( F_19 ( V_11 -> V_8 . V_22 , V_20 ) ) ;
return V_23 ;
}
static void F_20 ( struct V_24 * V_3 ) { }
static int F_21 ( struct V_24 * V_3 , unsigned int V_25 )
{
struct V_10 * V_11 = F_22 ( V_3 ) ;
int error = 0 ;
if ( V_11 -> V_26 ) {
error = F_23 ( V_11 -> V_26 , V_25 ) ;
if ( error ) {
F_24 ( & V_11 -> V_2 -> V_27 ,
L_1 ,
V_11 -> V_26 ) ;
V_11 -> V_26 = 0 ;
}
}
return error ;
}
static void F_25 ( struct V_24 * V_3 )
{
struct V_10 * V_11 = F_22 ( V_3 ) ;
V_11 -> V_21 |= ( 1 << V_3 -> V_28 ) ;
}
static void F_26 ( struct V_24 * V_3 )
{
struct V_10 * V_11 = F_22 ( V_3 ) ;
V_11 -> V_21 &= ~ ( 1 << V_3 -> V_28 ) ;
}
static void F_27 ( struct V_24 * V_3 )
{
struct V_10 * V_11 = F_22 ( V_3 ) ;
F_11 ( & V_11 -> V_12 ) ;
}
static void F_28 ( struct V_24 * V_3 )
{
struct V_10 * V_11 = F_22 ( V_3 ) ;
F_12 ( & V_11 -> V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
struct V_31 * V_32 = F_30 ( & V_2 -> V_27 ) ;
struct V_33 * V_34 = V_2 -> V_27 . V_35 ;
struct V_10 * V_11 ;
unsigned int V_36 = 0 ;
int V_6 ;
if ( F_31 ( V_37 ) && V_34 )
F_32 ( V_34 , L_2 , & V_36 ) ;
else if ( V_32 )
V_36 = V_32 -> V_36 ;
else
F_24 ( & V_2 -> V_27 , L_3 ) ;
V_11 = F_33 ( & V_2 -> V_27 , sizeof( * V_11 ) , V_38 ) ;
if ( ! V_11 )
return - V_39 ;
F_34 ( & V_11 -> V_12 ) ;
V_11 -> V_8 . V_40 = V_32 ? V_32 -> V_41 : - 1 ;
V_11 -> V_8 . V_42 = true ;
V_11 -> V_8 . V_43 = & V_2 -> V_27 ;
V_11 -> V_8 . V_44 = V_45 ;
V_11 -> V_8 . V_46 = F_13 ;
V_11 -> V_8 . V_47 = F_15 ;
V_11 -> V_8 . V_48 = F_9 ;
V_11 -> V_8 . V_49 = F_14 ;
V_11 -> V_8 . V_50 = V_30 -> V_51 ;
if ( V_11 -> V_8 . V_50 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_35 ( V_2 -> V_52 ,
V_53 ) )
V_6 = - V_54 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_50 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_35 ( V_2 -> V_52 , V_55 ) )
V_6 = - V_54 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_24 ( & V_2 -> V_27 , L_4 ) ;
V_6 = - V_56 ;
}
if ( V_6 < 0 )
goto V_57;
V_11 -> V_8 . V_58 = V_2 -> V_59 ;
V_11 -> V_2 = V_2 ;
F_36 ( V_2 , V_11 ) ;
V_11 -> V_13 = ~ V_36 ;
V_11 -> V_6 = V_11 -> V_13 ;
V_6 = F_37 ( & V_2 -> V_27 , & V_11 -> V_8 , V_11 ) ;
if ( V_6 < 0 )
goto V_57;
if ( V_2 -> V_18 ) {
V_6 = F_38 ( & V_11 -> V_8 , & V_60 ,
0 , V_61 ,
V_62 ) ;
if ( V_6 ) {
F_39 ( & V_2 -> V_27 , L_5 ) ;
goto V_57;
}
V_6 = F_40 ( & V_2 -> V_27 , V_2 -> V_18 ,
NULL , F_16 , V_63 |
V_64 | V_65 ,
F_41 ( & V_2 -> V_27 ) , V_11 ) ;
if ( V_6 )
goto V_57;
F_42 ( & V_11 -> V_8 , & V_60 ,
V_2 -> V_18 , NULL ) ;
V_11 -> V_26 = V_2 -> V_18 ;
}
if ( V_32 && V_32 -> V_66 ) {
V_6 = V_32 -> V_66 ( V_2 ,
V_11 -> V_8 . V_40 , V_11 -> V_8 . V_50 ,
V_32 -> V_67 ) ;
if ( V_6 < 0 )
F_43 ( & V_2 -> V_27 , L_6 , V_6 ) ;
}
F_44 ( & V_2 -> V_27 , L_7 ) ;
return 0 ;
V_57:
F_24 ( & V_2 -> V_27 , L_8 , V_6 ,
V_2 -> V_59 ) ;
return V_6 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_30 ( & V_2 -> V_27 ) ;
struct V_10 * V_11 = F_46 ( V_2 ) ;
int V_6 = 0 ;
if ( V_32 && V_32 -> V_68 ) {
V_6 = V_32 -> V_68 ( V_2 ,
V_11 -> V_8 . V_40 , V_11 -> V_8 . V_50 ,
V_32 -> V_67 ) ;
if ( V_6 < 0 ) {
F_39 ( & V_2 -> V_27 , L_9 ,
L_10 , V_6 ) ;
return V_6 ;
}
}
return V_6 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_46 ( V_2 ) ;
V_11 -> V_14 ( V_11 -> V_2 , F_48 ( V_11 -> V_8 . V_50 ) - 1 ) ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_69 ) ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_69 ) ;
}
