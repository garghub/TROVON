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
int V_18 ;
V_18 = F_17 ( V_11 -> V_19 , V_9 ) ;
if ( V_18 > 0 )
V_11 -> V_20 |= ( 1 << V_9 ) ;
return V_18 ;
}
static T_2 F_18 ( int V_21 , void * V_3 )
{
struct V_10 * V_11 = V_3 ;
unsigned long V_22 , V_23 , V_6 , V_24 ;
V_6 = V_11 -> V_16 ( V_11 -> V_2 ) ;
F_19 ( & V_11 -> V_25 , V_24 ) ;
V_22 = ( ( V_11 -> V_6 ^ V_6 ) & V_11 -> V_20 ) ;
F_20 (i, &change, gpio->chip.ngpio)
F_21 ( F_22 ( V_11 -> V_19 , V_23 ) ) ;
V_11 -> V_6 = V_6 ;
F_23 ( & V_11 -> V_25 , V_24 ) ;
return V_26 ;
}
static int F_24 ( struct V_19 * V_27 , unsigned int V_21 ,
T_3 V_28 )
{
struct V_10 * V_11 = V_27 -> V_29 ;
F_25 ( V_21 ,
& V_30 ,
V_31 ) ;
#ifdef F_26
F_27 ( V_21 , V_32 ) ;
#else
F_28 ( V_21 ) ;
#endif
V_11 -> V_20 |= ( 1 << V_28 ) ;
return 0 ;
}
static void F_29 ( struct V_10 * V_11 )
{
if ( V_11 -> V_19 )
F_30 ( V_11 -> V_19 ) ;
}
static int F_31 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_6 ;
V_11 -> V_19 = F_32 ( V_2 -> V_33 . V_34 ,
V_11 -> V_8 . V_35 ,
& V_36 ,
V_11 ) ;
if ( ! V_11 -> V_19 )
goto V_37;
V_6 = F_33 ( & V_2 -> V_33 , V_2 -> V_21 ,
NULL , F_18 , V_38 |
V_39 ,
F_34 ( & V_2 -> V_33 ) , V_11 ) ;
if ( V_6 )
goto V_37;
V_11 -> V_8 . V_40 = F_16 ;
return 0 ;
V_37:
F_29 ( V_11 ) ;
return - V_41 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_42 * V_43 )
{
struct V_44 * V_45 = F_36 ( & V_2 -> V_33 ) ;
struct V_46 * V_47 = V_2 -> V_33 . V_34 ;
struct V_10 * V_11 ;
unsigned int V_48 = 0 ;
int V_6 ;
if ( F_37 ( V_49 ) && V_47 )
F_38 ( V_47 , L_1 , & V_48 ) ;
else if ( V_45 )
V_48 = V_45 -> V_48 ;
else
F_39 ( & V_2 -> V_33 , L_2 ) ;
V_11 = F_40 ( & V_2 -> V_33 , sizeof( * V_11 ) , V_50 ) ;
if ( ! V_11 )
return - V_51 ;
F_41 ( & V_11 -> V_12 ) ;
F_42 ( & V_11 -> V_25 ) ;
V_11 -> V_8 . V_52 = V_45 ? V_45 -> V_53 : - 1 ;
V_11 -> V_8 . V_54 = true ;
V_11 -> V_8 . V_33 = & V_2 -> V_33 ;
V_11 -> V_8 . V_55 = V_56 ;
V_11 -> V_8 . V_57 = F_13 ;
V_11 -> V_8 . V_58 = F_15 ;
V_11 -> V_8 . V_59 = F_9 ;
V_11 -> V_8 . V_60 = F_14 ;
V_11 -> V_8 . V_35 = V_43 -> V_61 ;
if ( V_2 -> V_21 ) {
V_6 = F_31 ( V_11 , V_2 ) ;
if ( V_6 < 0 ) {
F_43 ( & V_2 -> V_33 , L_3 ) ;
goto V_37;
}
}
if ( V_11 -> V_8 . V_35 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_44 ( V_2 -> V_62 ,
V_63 ) )
V_6 = - V_64 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_35 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_44 ( V_2 -> V_62 , V_65 ) )
V_6 = - V_64 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_39 ( & V_2 -> V_33 , L_4 ) ;
V_6 = - V_41 ;
}
if ( V_6 < 0 )
goto V_37;
V_11 -> V_8 . V_66 = V_2 -> V_67 ;
V_11 -> V_2 = V_2 ;
F_45 ( V_2 , V_11 ) ;
V_11 -> V_13 = ~ V_48 ;
V_11 -> V_6 = V_11 -> V_13 ;
V_6 = F_46 ( & V_11 -> V_8 ) ;
if ( V_6 < 0 )
goto V_37;
if ( V_45 && V_45 -> V_68 ) {
V_6 = V_45 -> V_68 ( V_2 ,
V_11 -> V_8 . V_52 , V_11 -> V_8 . V_35 ,
V_45 -> V_69 ) ;
if ( V_6 < 0 )
F_47 ( & V_2 -> V_33 , L_5 , V_6 ) ;
}
F_48 ( & V_2 -> V_33 , L_6 ) ;
return 0 ;
V_37:
F_39 ( & V_2 -> V_33 , L_7 ,
V_6 , V_2 -> V_67 ) ;
if ( V_2 -> V_21 )
F_29 ( V_11 ) ;
return V_6 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_36 ( & V_2 -> V_33 ) ;
struct V_10 * V_11 = F_50 ( V_2 ) ;
int V_6 = 0 ;
if ( V_45 && V_45 -> V_70 ) {
V_6 = V_45 -> V_70 ( V_2 ,
V_11 -> V_8 . V_52 , V_11 -> V_8 . V_35 ,
V_45 -> V_69 ) ;
if ( V_6 < 0 ) {
F_43 ( & V_2 -> V_33 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
if ( V_2 -> V_21 )
F_29 ( V_11 ) ;
V_6 = F_51 ( & V_11 -> V_8 ) ;
if ( V_6 )
F_43 ( & V_2 -> V_33 , L_8 , L_10 , V_6 ) ;
return V_6 ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_71 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_71 ) ;
}
