static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = 0 , V_6 = 0 ;
switch ( V_7 ) {
case V_8 :
V_6 = 1 ;
case V_9 :
V_5 = 1 ;
break;
case V_10 :
V_6 = 1 ;
break;
}
if ( V_11 )
F_2 ( V_4 , L_1 ) ;
else
F_3 ( V_4 , L_1 ) ;
if ( V_5 )
F_2 ( V_4 , L_2 ) ;
else
F_3 ( V_4 , L_2 ) ;
if ( V_6 )
F_2 ( V_4 , L_3 ) ;
else
F_3 ( V_4 , L_3 ) ;
if ( V_12 )
F_2 ( V_4 , L_4 ) ;
else
F_3 ( V_4 , L_4 ) ;
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_6 ( V_16 ,
V_20 , 2 , 2 ) ;
F_1 ( V_2 ) ;
return F_7 ( V_21 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
F_9 ( V_21 ) ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_22 * V_23 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_24 * V_25 = V_18 -> V_25 ;
int V_26 ;
V_26 = F_11 ( V_25 , 0 , 12000000 ,
V_27 ) ;
return V_26 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_11 ;
return 0 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
if ( V_11 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_11 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_7 ;
return 0 ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
if ( V_7 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_7 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_12 ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
if ( V_12 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_12 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_19 ( struct V_33 * V_34 ,
struct V_28 * V_35 , int V_36 )
{
if ( F_20 ( V_36 ) )
F_21 ( V_37 , 1 ) ;
else
F_21 ( V_37 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_28 * V_35 , int V_36 )
{
if ( F_20 ( V_36 ) )
F_21 ( V_38 , 1 ) ;
else
F_21 ( V_38 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
F_24 ( V_4 , L_5 ) ;
F_24 ( V_4 , L_6 ) ;
F_24 ( V_4 , L_7 ) ;
F_24 ( V_4 , L_8 ) ;
F_24 ( V_4 , L_9 ) ;
F_24 ( V_4 , L_10 ) ;
F_24 ( V_4 , L_11 ) ;
F_24 ( V_4 , L_12 ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
int V_26 ;
struct V_39 * V_40 ;
if ( ! ( F_26 () || F_27 () ) )
return - V_41 ;
V_42 = F_28 ( L_13 , - 1 ) ;
if ( ! V_42 )
return - V_43 ;
F_29 ( V_42 , & V_44 ) ;
V_26 = F_30 ( V_42 ) ;
if ( V_26 )
goto V_45;
V_40 = & V_42 -> V_40 ;
V_46 = F_31 ( V_40 , L_14 ) ;
if ( F_32 ( V_46 ) ) {
F_33 ( V_40 , L_15 ) ;
V_26 = F_34 ( V_46 ) ;
goto V_47;
}
V_21 = F_31 ( V_40 , L_16 ) ;
if ( F_32 ( V_21 ) ) {
F_33 ( V_40 , L_17 ) ;
V_26 = F_34 ( V_21 ) ;
goto V_48;
}
V_49 = F_31 ( V_40 , L_18 ) ;
if ( F_32 ( V_49 ) ) {
F_33 ( V_40 , L_19 ) ;
V_26 = F_34 ( V_49 ) ;
goto V_50;
}
F_35 ( V_46 , V_49 ) ;
F_36 ( V_21 , 12000000 ) ;
F_37 ( ( F_38 ( V_38 , L_20 ) < 0 ) ||
( F_38 ( V_37 , L_21 ) < 0 ) ) ;
F_39 ( V_38 , 0 ) ;
F_39 ( V_37 , 0 ) ;
return 0 ;
V_50:
F_40 ( V_21 ) ;
V_48:
F_40 ( V_46 ) ;
V_47:
F_41 ( V_42 ) ;
V_45:
F_42 ( V_42 ) ;
return V_26 ;
}
static void T_2 F_43 ( void )
{
F_44 ( V_37 ) ;
F_44 ( V_38 ) ;
F_40 ( V_46 ) ;
F_40 ( V_21 ) ;
F_40 ( V_49 ) ;
F_45 ( V_42 ) ;
}
