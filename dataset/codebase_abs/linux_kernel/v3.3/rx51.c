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
return F_9 ( V_26 , 0 , 19200000 ,
V_27 ) ;
}
static int F_10 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_12 ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_29 ) ;
if ( V_12 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_12 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
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
struct V_1 * V_2 = V_34 -> V_4 -> V_2 ;
if ( F_14 ( V_36 ) )
F_17 ( V_2 , 1 ) ;
else
F_17 ( V_2 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_13 ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_29 ) ;
if ( V_13 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_13 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_8 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_29 ) ;
if ( V_8 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_8 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_38 ;
F_23 ( V_4 , L_5 ) ;
F_23 ( V_4 , L_6 ) ;
F_23 ( V_4 , L_7 ) ;
V_38 = F_24 ( V_2 , V_39 ,
F_25 ( V_39 ) ) ;
if ( V_38 < 0 )
return V_38 ;
F_26 ( V_4 , V_40 ,
F_25 ( V_40 ) ) ;
F_27 ( V_4 , V_41 , F_25 ( V_41 ) ) ;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
F_29 ( V_2 , L_8 , 42 ) ;
V_38 = F_30 ( V_2 , 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_31 ( V_2 , L_9 ,
V_42 | V_43 ,
& V_44 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_32 ( & V_44 ,
F_25 ( V_45 ) ,
V_45 ) ;
return V_38 ;
}
static int F_33 ( struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_24 ( V_4 -> V_2 , V_46 ,
F_25 ( V_46 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_26 ( V_4 , V_47 ,
F_25 ( V_47 ) ) ;
if ( V_38 < 0 )
return 0 ;
return F_27 ( V_4 , V_48 ,
F_25 ( V_48 ) ) ;
}
static int T_1 F_34 ( void )
{
int V_38 ;
if ( ! F_35 () )
return - V_49 ;
V_38 = F_36 ( V_14 ,
V_50 | V_51 , L_10 ) ;
if ( V_38 )
goto V_52;
V_38 = F_36 ( V_53 ,
V_50 | V_54 , L_11 ) ;
if ( V_38 )
goto V_55;
V_56 = F_37 ( L_12 , - 1 ) ;
if ( ! V_56 ) {
V_38 = - V_57 ;
goto V_58;
}
F_38 ( V_56 , & V_59 ) ;
V_38 = F_39 ( V_56 ) ;
if ( V_38 )
goto V_60;
return 0 ;
V_60:
F_40 ( V_56 ) ;
V_58:
F_41 ( V_53 ) ;
V_55:
F_41 ( V_14 ) ;
V_52:
return V_38 ;
}
static void T_2 F_42 ( void )
{
F_43 ( & V_44 , F_25 ( V_45 ) ,
V_45 ) ;
F_44 ( V_56 ) ;
F_41 ( V_53 ) ;
F_41 ( V_14 ) ;
}
