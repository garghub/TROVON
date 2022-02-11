static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 , V_4 = 0 , V_5 = 0 ;
switch ( V_6 ) {
case V_7 :
V_5 = 1 ;
V_3 = 1 ;
break;
case V_8 :
V_4 = 1 ;
case V_9 :
V_3 = 1 ;
break;
}
if ( V_10 )
F_2 ( V_2 , L_1 ) ;
else
F_3 ( V_2 , L_1 ) ;
if ( V_11 )
F_2 ( V_2 , L_2 ) ;
else
F_3 ( V_2 , L_2 ) ;
if ( V_3 )
F_2 ( V_2 , L_3 ) ;
else
F_3 ( V_2 , L_3 ) ;
if ( V_4 )
F_2 ( V_2 , L_4 ) ;
else
F_3 ( V_2 , L_4 ) ;
F_4 ( V_12 , V_5 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
F_7 ( V_16 ,
V_22 , 2 , 2 ) ;
F_1 ( & V_21 -> V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_23 * V_24 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_25 * V_26 = V_18 -> V_26 ;
return F_9 ( V_26 , 0 , 19200000 ,
V_27 ) ;
}
static int F_10 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_10 ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = F_12 ( V_29 ) ;
if ( V_10 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_10 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_21 -> V_2 ) ;
return 1 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_28 * V_35 , int V_36 )
{
if ( F_14 ( V_36 ) )
F_15 ( V_37 , 1 ) ;
else
F_15 ( V_37 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_28 * V_35 , int V_36 )
{
struct V_38 * V_39 = V_34 -> V_2 -> V_39 ;
if ( F_14 ( V_36 ) )
F_17 ( V_39 , 1 ) ;
else
F_17 ( V_39 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_11 ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = F_12 ( V_29 ) ;
if ( V_11 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_11 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_21 -> V_2 ) ;
return 1 ;
}
static int F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_6 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_20 * V_21 = F_12 ( V_29 ) ;
if ( V_6 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_6 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_21 -> V_2 ) ;
return 1 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_38 * V_39 = V_18 -> V_39 ;
struct V_1 * V_2 = & V_39 -> V_2 ;
int V_40 ;
F_23 ( V_2 , L_5 ) ;
F_23 ( V_2 , L_6 ) ;
F_23 ( V_2 , L_7 ) ;
V_40 = F_24 ( V_18 -> V_21 , V_41 ,
F_25 ( V_41 ) ) ;
if ( V_40 < 0 )
return V_40 ;
F_26 ( V_2 , V_42 ,
F_25 ( V_42 ) ) ;
F_27 ( V_2 , V_43 , F_25 ( V_43 ) ) ;
V_40 = F_28 ( V_39 ) ;
if ( V_40 < 0 )
return V_40 ;
F_29 ( V_39 , L_8 , 42 ) ;
V_40 = F_30 ( V_18 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_31 ( V_39 , L_9 ,
V_44 | V_45 ,
& V_46 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_32 ( & V_46 ,
F_25 ( V_47 ) ,
V_47 ) ;
return V_40 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_24 ( V_2 -> V_21 , V_48 ,
F_25 ( V_48 ) ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_26 ( V_2 , V_49 ,
F_25 ( V_49 ) ) ;
if ( V_40 < 0 )
return 0 ;
return F_27 ( V_2 , V_50 ,
F_25 ( V_50 ) ) ;
}
static int T_1 F_34 ( void )
{
int V_40 ;
if ( ! F_35 () )
return - V_51 ;
V_40 = F_36 ( V_12 ,
V_52 | V_53 , L_10 ) ;
if ( V_40 )
goto V_54;
V_40 = F_36 ( V_55 ,
V_52 | V_56 , L_11 ) ;
if ( V_40 )
goto V_57;
V_58 = F_37 ( L_12 , - 1 ) ;
if ( ! V_58 ) {
V_40 = - V_59 ;
goto V_60;
}
F_38 ( V_58 , & V_61 ) ;
V_40 = F_39 ( V_58 ) ;
if ( V_40 )
goto V_62;
return 0 ;
V_62:
F_40 ( V_58 ) ;
V_60:
F_41 ( V_55 ) ;
V_57:
F_41 ( V_12 ) ;
V_54:
return V_40 ;
}
static void T_2 F_42 ( void )
{
F_43 ( & V_46 , F_25 ( V_47 ) ,
V_47 ) ;
F_44 ( V_58 ) ;
F_41 ( V_55 ) ;
F_41 ( V_12 ) ;
}
