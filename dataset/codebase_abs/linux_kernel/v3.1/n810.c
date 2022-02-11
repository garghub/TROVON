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
struct V_24 * V_26 = V_18 -> V_26 ;
int V_27 ;
V_27 = F_11 ( V_25 ,
V_28 |
V_29 |
V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_11 ( V_26 ,
V_28 |
V_29 |
V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_25 , 0 , 12000000 ,
V_31 ) ;
return V_27 ;
}
static int F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 . integer . V_36 [ 0 ] = V_11 ;
return 0 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
if ( V_11 == V_35 -> V_36 . integer . V_36 [ 0 ] )
return 0 ;
V_11 = V_35 -> V_36 . integer . V_36 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 . integer . V_36 [ 0 ] = V_7 ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
if ( V_7 == V_35 -> V_36 . integer . V_36 [ 0 ] )
return 0 ;
V_7 = V_35 -> V_36 . integer . V_36 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_18 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 . integer . V_36 [ 0 ] = V_12 ;
return 0 ;
}
static int F_19 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
if ( V_12 == V_35 -> V_36 . integer . V_36 [ 0 ] )
return 0 ;
V_12 = V_35 -> V_36 . integer . V_36 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_32 * V_39 , int V_40 )
{
if ( F_21 ( V_40 ) )
F_22 ( V_41 , 1 ) ;
else
F_22 ( V_41 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 ,
struct V_32 * V_39 , int V_40 )
{
if ( F_21 ( V_40 ) )
F_22 ( V_42 , 1 ) ;
else
F_22 ( V_42 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_27 ;
F_25 ( V_4 , L_5 ) ;
F_25 ( V_4 , L_6 ) ;
F_25 ( V_4 , L_7 ) ;
F_25 ( V_4 , L_8 ) ;
F_25 ( V_4 , L_9 ) ;
F_25 ( V_4 , L_10 ) ;
F_25 ( V_4 , L_11 ) ;
F_25 ( V_4 , L_12 ) ;
V_27 = F_26 ( V_2 , V_43 ,
F_27 ( V_43 ) ) ;
if ( V_27 < 0 )
return V_27 ;
F_28 ( V_4 , V_44 ,
F_27 ( V_44 ) ) ;
F_29 ( V_4 , V_45 , F_27 ( V_45 ) ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
int V_27 ;
struct V_46 * V_47 ;
if ( ! ( F_31 () || F_32 () ) )
return - V_48 ;
V_49 = F_33 ( L_13 , - 1 ) ;
if ( ! V_49 )
return - V_50 ;
F_34 ( V_49 , & V_51 ) ;
V_27 = F_35 ( V_49 ) ;
if ( V_27 )
goto V_52;
V_47 = & V_49 -> V_47 ;
V_53 = F_36 ( V_47 , L_14 ) ;
if ( F_37 ( V_53 ) ) {
F_38 ( V_47 , L_15 ) ;
V_27 = F_39 ( V_53 ) ;
goto V_54;
}
V_21 = F_36 ( V_47 , L_16 ) ;
if ( F_37 ( V_21 ) ) {
F_38 ( V_47 , L_17 ) ;
V_27 = F_39 ( V_21 ) ;
goto V_55;
}
V_56 = F_36 ( V_47 , L_18 ) ;
if ( F_37 ( V_56 ) ) {
F_38 ( V_47 , L_19 ) ;
V_27 = F_39 ( V_56 ) ;
goto V_57;
}
F_40 ( V_53 , V_56 ) ;
F_41 ( V_21 , 12000000 ) ;
F_42 ( ( F_43 ( V_42 , L_20 ) < 0 ) ||
( F_43 ( V_41 , L_21 ) < 0 ) ) ;
F_44 ( V_42 , 0 ) ;
F_44 ( V_41 , 0 ) ;
return 0 ;
V_57:
F_45 ( V_21 ) ;
V_55:
F_45 ( V_53 ) ;
V_54:
F_46 ( V_49 ) ;
V_52:
F_47 ( V_49 ) ;
return V_27 ;
}
static void T_2 F_48 ( void )
{
F_49 ( V_41 ) ;
F_49 ( V_42 ) ;
F_45 ( V_53 ) ;
F_45 ( V_21 ) ;
F_45 ( V_56 ) ;
F_50 ( V_49 ) ;
}
