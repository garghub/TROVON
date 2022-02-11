static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div , V_7 , V_8 ;
if ( * V_1 > V_2 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div < 16 )
V_8 = 0 ;
else if ( div / 2 < 16 )
V_8 = 1 ;
else if ( div / 4 < 16 )
V_8 = 2 ;
else
V_8 = 3 ;
V_7 = F_2 ( div , 1 << V_8 ) ;
* V_1 = ( V_2 >> V_8 ) / V_7 ;
if ( V_3 == NULL )
return;
* V_5 = V_7 - 1 ;
* V_6 = V_8 ;
}
static void T_3 F_3 ( struct V_9 * V_10 )
{
F_4 ( V_10 , & V_11 , & V_12 ) ;
}
static void T_3 F_5 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 , & V_11 , & V_15 ) ;
F_6 ( V_14 ) ;
F_7 ( V_14 ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_13 * V_18 , * V_19 , * V_13 = V_17 -> V_13 ;
struct V_20 * V_21 = F_9 ( V_17 ) ;
unsigned int V_22 , V_23 ;
T_4 V_24 , V_25 ;
T_1 V_26 ;
T_2 V_27 ;
V_26 = F_10 ( V_21 -> V_28 ) ;
V_27 = ( V_26 >> V_21 -> V_29 -> V_30 ) & 0x3 ;
if ( ! V_27 )
return 180 ;
V_18 = F_11 ( V_13 ) ;
if ( ! V_18 )
return - V_31 ;
V_22 = F_12 ( V_18 ) ;
if ( ! V_22 )
return - V_31 ;
V_19 = F_11 ( V_18 ) ;
if ( ! V_19 )
return - V_31 ;
V_23 = F_12 ( V_19 ) ;
if ( ! V_23 )
return - V_31 ;
V_25 = V_23 / V_22 ;
V_24 = F_13 ( 360 , V_25 ) ;
return V_27 * V_24 ;
}
static int F_14 ( struct V_16 * V_17 , int V_32 )
{
struct V_13 * V_18 , * V_19 , * V_13 = V_17 -> V_13 ;
struct V_20 * V_21 = F_9 ( V_17 ) ;
unsigned int V_22 , V_23 ;
unsigned long V_33 ;
T_1 V_26 ;
T_2 V_27 ;
V_18 = F_11 ( V_13 ) ;
if ( ! V_18 )
return - V_31 ;
V_22 = F_12 ( V_18 ) ;
if ( ! V_22 )
return - V_31 ;
V_19 = F_11 ( V_18 ) ;
if ( ! V_19 )
return - V_31 ;
V_23 = F_12 ( V_19 ) ;
if ( ! V_23 )
return - V_31 ;
if ( V_32 != 180 ) {
T_4 V_24 , V_25 ;
V_25 = V_23 / V_22 ;
V_24 = F_13 ( 360 , V_25 ) ;
V_27 = F_13 ( V_32 , V_24 ) ;
} else {
V_27 = 0 ;
}
F_15 ( V_21 -> V_34 , V_33 ) ;
V_26 = F_10 ( V_21 -> V_28 ) ;
V_26 &= ~ F_16 ( V_21 -> V_29 -> V_30 + 3 , V_21 -> V_29 -> V_30 ) ;
V_26 |= V_27 << V_21 -> V_29 -> V_30 ;
F_17 ( V_26 , V_21 -> V_28 ) ;
F_18 ( V_21 -> V_34 , V_33 ) ;
return 0 ;
}
static void T_3 F_19 ( struct V_9 * V_10 ,
struct V_35 * V_29 )
{
const char * V_36 [ 1 ] = { F_20 (node, 0 ) } ;
struct V_37 V_38 = {
. V_39 = 1 ,
. V_36 = V_36 ,
. V_40 = & V_41 ,
} ;
struct V_20 * V_21 ;
struct V_13 * V_13 ;
V_21 = F_21 ( sizeof( * V_21 ) , V_42 ) ;
if ( ! V_21 )
return;
V_21 -> V_17 . V_38 = & V_38 ;
V_21 -> V_28 = F_22 ( V_10 , 0 ) ;
if ( ! V_21 -> V_28 )
goto V_43;
V_21 -> V_29 = V_29 ;
V_21 -> V_34 = & V_12 ;
if ( F_23 ( V_10 , L_1 , & V_38 . V_44 ) )
V_38 . V_44 = V_10 -> V_44 ;
V_13 = F_24 ( NULL , & V_21 -> V_17 ) ;
if ( F_25 ( V_13 ) )
goto V_45;
F_26 ( V_10 , V_46 , V_13 ) ;
return;
V_45:
F_27 ( V_21 -> V_28 ) ;
V_43:
F_28 ( V_21 ) ;
}
static void T_3 F_29 ( struct V_9 * V_10 )
{
F_19 ( V_10 , & V_47 ) ;
}
static void T_3 F_30 ( struct V_9 * V_10 )
{
F_19 ( V_10 , & V_48 ) ;
}
