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
V_19 = ( V_11 -> V_6 ^ V_6 ) ;
F_18 (i, &change, gpio->chip.ngpio)
F_19 ( F_20 ( V_11 -> V_8 . V_23 , V_20 ) ) ;
V_11 -> V_6 = V_6 ;
F_21 ( & V_11 -> V_22 , V_21 ) ;
return V_24 ;
}
static void F_22 ( struct V_25 * V_3 ) { }
static unsigned int F_23 ( struct V_25 * V_3 )
{
return 0 ;
}
static int F_24 ( struct V_25 * V_3 , unsigned int V_26 )
{
struct V_10 * V_11 = F_25 ( V_3 ) ;
F_26 ( V_11 -> V_2 -> V_18 , V_26 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = F_28 ( & V_2 -> V_31 ) ;
struct V_32 * V_33 = V_2 -> V_31 . V_34 ;
struct V_10 * V_11 ;
unsigned int V_35 = 0 ;
int V_6 ;
if ( F_29 ( V_36 ) && V_33 )
F_30 ( V_33 , L_1 , & V_35 ) ;
else if ( V_30 )
V_35 = V_30 -> V_35 ;
else
F_31 ( & V_2 -> V_31 , L_2 ) ;
V_11 = F_32 ( & V_2 -> V_31 , sizeof( * V_11 ) , V_37 ) ;
if ( ! V_11 )
return - V_38 ;
F_33 ( & V_11 -> V_12 ) ;
F_34 ( & V_11 -> V_22 ) ;
V_11 -> V_8 . V_39 = V_30 ? V_30 -> V_40 : - 1 ;
V_11 -> V_8 . V_41 = true ;
V_11 -> V_8 . V_31 = & V_2 -> V_31 ;
V_11 -> V_8 . V_42 = V_43 ;
V_11 -> V_8 . V_44 = F_13 ;
V_11 -> V_8 . V_45 = F_15 ;
V_11 -> V_8 . V_46 = F_9 ;
V_11 -> V_8 . V_47 = F_14 ;
V_11 -> V_8 . V_48 = V_28 -> V_49 ;
if ( V_11 -> V_8 . V_48 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_35 ( V_2 -> V_50 ,
V_51 ) )
V_6 = - V_52 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_48 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_35 ( V_2 -> V_50 , V_53 ) )
V_6 = - V_52 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_31 ( & V_2 -> V_31 , L_3 ) ;
V_6 = - V_54 ;
}
if ( V_6 < 0 )
goto V_55;
V_11 -> V_8 . V_56 = V_2 -> V_57 ;
V_11 -> V_2 = V_2 ;
F_36 ( V_2 , V_11 ) ;
V_11 -> V_13 = ~ V_35 ;
V_11 -> V_6 = V_11 -> V_13 ;
V_6 = F_37 ( & V_11 -> V_8 ) ;
if ( V_6 < 0 )
goto V_55;
if ( V_2 -> V_18 ) {
V_6 = F_38 ( & V_11 -> V_8 , & V_58 ,
0 , V_59 ,
V_60 ) ;
if ( V_6 ) {
F_39 ( & V_2 -> V_31 , L_4 ) ;
goto V_61;
}
V_6 = F_40 ( & V_2 -> V_31 , V_2 -> V_18 ,
NULL , F_16 , V_62 |
V_63 | V_64 ,
F_41 ( & V_2 -> V_31 ) , V_11 ) ;
if ( V_6 )
goto V_61;
F_42 ( & V_11 -> V_8 , & V_58 ,
V_2 -> V_18 , NULL ) ;
}
if ( V_30 && V_30 -> V_65 ) {
V_6 = V_30 -> V_65 ( V_2 ,
V_11 -> V_8 . V_39 , V_11 -> V_8 . V_48 ,
V_30 -> V_66 ) ;
if ( V_6 < 0 )
F_43 ( & V_2 -> V_31 , L_5 , V_6 ) ;
}
F_44 ( & V_2 -> V_31 , L_6 ) ;
return 0 ;
V_61:
F_45 ( & V_11 -> V_8 ) ;
V_55:
F_31 ( & V_2 -> V_31 , L_7 , V_6 ,
V_2 -> V_57 ) ;
return V_6 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_28 ( & V_2 -> V_31 ) ;
struct V_10 * V_11 = F_47 ( V_2 ) ;
int V_6 = 0 ;
if ( V_30 && V_30 -> V_67 ) {
V_6 = V_30 -> V_67 ( V_2 ,
V_11 -> V_8 . V_39 , V_11 -> V_8 . V_48 ,
V_30 -> V_66 ) ;
if ( V_6 < 0 ) {
F_39 ( & V_2 -> V_31 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
F_45 ( & V_11 -> V_8 ) ;
return V_6 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_68 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_68 ) ;
}
