static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = 0 , V_6 = 0 , V_7 = 0 ;
switch ( V_8 ) {
case V_9 :
V_7 = 1 ;
V_5 = 1 ;
break;
case V_10 :
V_6 = 1 ;
case V_11 :
V_5 = 1 ;
break;
}
if ( V_12 )
F_2 ( V_4 , L_1 ) ;
else
F_3 ( V_4 , L_1 ) ;
if ( V_13 )
F_2 ( V_4 , L_2 ) ;
else
F_3 ( V_4 , L_2 ) ;
if ( V_5 )
F_2 ( V_4 , L_3 ) ;
else
F_3 ( V_4 , L_3 ) ;
if ( V_6 )
F_2 ( V_4 , L_4 ) ;
else
F_3 ( V_4 , L_4 ) ;
F_4 ( V_14 , V_7 ) ;
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_7 ( V_18 ,
V_22 , 2 , 2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_23 * V_24 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_25 * V_26 = V_20 -> V_26 ;
struct V_25 * V_27 = V_20 -> V_27 ;
int V_28 ;
V_28 = F_9 ( V_26 ,
V_29 |
V_30 |
V_31 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_9 ( V_27 ,
V_29 |
V_30 |
V_31 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_10 ( V_26 , 0 , 19200000 ,
V_32 ) ;
}
static int F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 . integer . V_37 [ 0 ] = V_12 ;
return 0 ;
}
static int F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_34 ) ;
if ( V_12 == V_36 -> V_37 . integer . V_37 [ 0 ] )
return 0 ;
V_12 = V_36 -> V_37 . integer . V_37 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_14 ( struct V_38 * V_39 ,
struct V_33 * V_40 , int V_41 )
{
if ( F_15 ( V_41 ) )
F_16 ( V_42 , 1 ) ;
else
F_16 ( V_42 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 ,
struct V_33 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_39 -> V_4 -> V_2 ;
if ( F_15 ( V_41 ) )
F_18 ( V_2 , 1 ) ;
else
F_18 ( V_2 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 . integer . V_37 [ 0 ] = V_13 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_34 ) ;
if ( V_13 == V_36 -> V_37 . integer . V_37 [ 0 ] )
return 0 ;
V_13 = V_36 -> V_37 . integer . V_37 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 . integer . V_37 [ 0 ] = V_8 ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_34 ) ;
if ( V_8 == V_36 -> V_37 . integer . V_37 [ 0 ] )
return 0 ;
V_8 = V_36 -> V_37 . integer . V_37 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_28 ;
F_24 ( V_4 , L_5 ) ;
F_24 ( V_4 , L_6 ) ;
F_24 ( V_4 , L_7 ) ;
V_28 = F_25 ( V_2 , V_43 ,
F_26 ( V_43 ) ) ;
if ( V_28 < 0 )
return V_28 ;
F_27 ( V_4 , V_44 ,
F_26 ( V_44 ) ) ;
F_28 ( V_4 , V_45 , F_26 ( V_45 ) ) ;
V_28 = F_29 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
F_30 ( V_2 , L_8 , 42 ) ;
V_28 = F_31 ( V_2 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
F_5 ( V_4 ) ;
V_28 = F_32 ( V_2 , L_9 ,
V_46 | V_47 ,
& V_48 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_33 ( & V_48 ,
F_26 ( V_49 ) ,
V_49 ) ;
return V_28 ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_28 ;
V_28 = F_25 ( V_4 -> V_2 , V_50 ,
F_26 ( V_50 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_27 ( V_4 , V_51 ,
F_26 ( V_51 ) ) ;
if ( V_28 < 0 )
return 0 ;
return F_28 ( V_4 , V_52 ,
F_26 ( V_52 ) ) ;
}
static int T_1 F_35 ( void )
{
int V_28 ;
if ( ! F_36 () )
return - V_53 ;
V_28 = F_37 ( V_14 ,
V_54 | V_55 , L_10 ) ;
if ( V_28 )
goto V_56;
V_28 = F_37 ( V_57 ,
V_54 | V_58 , L_11 ) ;
if ( V_28 )
goto V_59;
V_60 = F_38 ( L_12 , - 1 ) ;
if ( ! V_60 ) {
V_28 = - V_61 ;
goto V_62;
}
F_39 ( V_60 , & V_63 ) ;
V_28 = F_40 ( V_60 ) ;
if ( V_28 )
goto V_64;
return 0 ;
V_64:
F_41 ( V_60 ) ;
V_62:
F_42 ( V_57 ) ;
V_59:
F_42 ( V_14 ) ;
V_56:
return V_28 ;
}
static void T_2 F_43 ( void )
{
F_44 ( & V_48 , F_26 ( V_49 ) ,
V_49 ) ;
F_45 ( V_60 ) ;
F_42 ( V_57 ) ;
F_42 ( V_14 ) ;
}
