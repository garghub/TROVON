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
static int F_16 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
return F_17 ( V_11 -> V_18 , V_9 ) ;
}
static void F_18 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = F_10 ( V_20 ,
struct V_10 ,
V_20 ) ;
unsigned long V_21 , V_22 , V_6 , V_23 ;
V_6 = V_11 -> V_16 ( V_11 -> V_2 ) ;
F_19 ( & V_11 -> V_24 , V_23 ) ;
V_21 = V_11 -> V_6 ^ V_6 ;
F_20 (i, &change, gpio->chip.ngpio)
F_21 ( F_22 ( V_11 -> V_18 , V_22 ) ) ;
V_11 -> V_6 = V_6 ;
F_23 ( & V_11 -> V_24 , V_23 ) ;
}
static T_2 F_24 ( int V_25 , void * V_3 )
{
struct V_10 * V_11 = V_3 ;
F_25 ( & V_11 -> V_20 ) ;
return V_26 ;
}
static int F_26 ( struct V_18 * V_27 , unsigned int V_28 ,
T_3 V_29 )
{
F_27 ( V_28 ,
& V_30 ,
V_31 ) ;
return 0 ;
}
static void F_28 ( struct V_10 * V_11 )
{
if ( V_11 -> V_18 )
F_29 ( V_11 -> V_18 ) ;
if ( V_11 -> V_25 )
F_30 ( V_11 -> V_25 , V_11 ) ;
}
static int F_31 ( struct V_10 * V_11 ,
struct V_32 * V_33 ,
struct V_1 * V_2 )
{
int V_6 ;
V_11 -> V_18 = F_32 ( V_2 -> V_34 . V_35 ,
V_11 -> V_8 . V_36 ,
& V_37 ,
NULL ) ;
if ( ! V_11 -> V_18 )
goto V_38;
V_6 = F_33 ( V_2 -> V_25 , F_24 , 0 ,
F_34 ( & V_2 -> V_34 ) , V_11 ) ;
if ( V_6 )
goto V_38;
F_35 ( & V_11 -> V_20 , F_18 ) ;
V_11 -> V_8 . V_39 = F_16 ;
V_11 -> V_25 = V_2 -> V_25 ;
return 0 ;
V_38:
F_28 ( V_11 ) ;
return - V_40 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
struct V_32 * V_33 ;
struct V_10 * V_11 ;
int V_6 ;
V_33 = V_2 -> V_34 . V_43 ;
if ( ! V_33 ) {
F_37 ( & V_2 -> V_34 , L_1 ) ;
}
V_11 = F_38 ( sizeof *V_11 , V_44 ) ;
if ( ! V_11 )
return - V_45 ;
F_39 ( & V_11 -> V_12 ) ;
F_40 ( & V_11 -> V_24 ) ;
V_11 -> V_8 . V_46 = V_33 ? V_33 -> V_47 : - 1 ;
V_11 -> V_8 . V_48 = 1 ;
V_11 -> V_8 . V_34 = & V_2 -> V_34 ;
V_11 -> V_8 . V_49 = V_50 ;
V_11 -> V_8 . V_51 = F_13 ;
V_11 -> V_8 . V_52 = F_15 ;
V_11 -> V_8 . V_53 = F_9 ;
V_11 -> V_8 . V_54 = F_14 ;
V_11 -> V_8 . V_36 = V_42 -> V_55 ;
if ( V_33 && V_2 -> V_25 ) {
V_6 = F_31 ( V_11 , V_33 , V_2 ) ;
if ( V_6 < 0 ) {
F_41 ( & V_2 -> V_34 , L_2 ) ;
goto V_38;
}
}
if ( V_11 -> V_8 . V_36 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_42 ( V_2 -> V_56 ,
V_57 ) )
V_6 = - V_58 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_36 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_42 ( V_2 -> V_56 , V_59 ) )
V_6 = - V_58 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_37 ( & V_2 -> V_34 , L_3 ) ;
V_6 = - V_40 ;
}
if ( V_6 < 0 )
goto V_38;
V_11 -> V_8 . V_60 = V_2 -> V_61 ;
V_11 -> V_2 = V_2 ;
F_43 ( V_2 , V_11 ) ;
V_11 -> V_13 = V_33 ? ~ V_33 -> V_62 : ~ 0 ;
V_11 -> V_6 = V_11 -> V_13 ;
V_6 = F_44 ( & V_11 -> V_8 ) ;
if ( V_6 < 0 )
goto V_38;
if ( V_33 && V_33 -> V_63 ) {
V_6 = V_33 -> V_63 ( V_2 ,
V_11 -> V_8 . V_46 , V_11 -> V_8 . V_36 ,
V_33 -> V_64 ) ;
if ( V_6 < 0 )
F_45 ( & V_2 -> V_34 , L_4 , V_6 ) ;
}
F_46 ( & V_2 -> V_34 , L_5 ) ;
return 0 ;
V_38:
F_37 ( & V_2 -> V_34 , L_6 ,
V_6 , V_2 -> V_61 ) ;
if ( V_33 && V_2 -> V_25 )
F_28 ( V_11 ) ;
F_47 ( V_11 ) ;
return V_6 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 . V_43 ;
struct V_10 * V_11 = F_49 ( V_2 ) ;
int V_6 = 0 ;
if ( V_33 && V_33 -> V_65 ) {
V_6 = V_33 -> V_65 ( V_2 ,
V_11 -> V_8 . V_46 , V_11 -> V_8 . V_36 ,
V_33 -> V_64 ) ;
if ( V_6 < 0 ) {
F_41 ( & V_2 -> V_34 , L_7 ,
L_8 , V_6 ) ;
return V_6 ;
}
}
if ( V_33 && V_2 -> V_25 )
F_28 ( V_11 ) ;
V_6 = F_50 ( & V_11 -> V_8 ) ;
if ( V_6 == 0 )
F_47 ( V_11 ) ;
else
F_41 ( & V_2 -> V_34 , L_7 , L_9 , V_6 ) ;
return V_6 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_66 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_66 ) ;
}
