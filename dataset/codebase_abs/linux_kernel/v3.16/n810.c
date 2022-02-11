static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 , V_4 = 0 ;
switch ( V_5 ) {
case V_6 :
V_4 = 1 ;
case V_7 :
V_3 = 1 ;
break;
case V_8 :
V_4 = 1 ;
break;
}
F_2 ( V_2 ) ;
if ( V_9 )
F_3 ( V_2 , L_1 ) ;
else
F_4 ( V_2 , L_1 ) ;
if ( V_3 )
F_3 ( V_2 , L_2 ) ;
else
F_4 ( V_2 , L_2 ) ;
if ( V_4 )
F_3 ( V_2 , L_3 ) ;
else
F_4 ( V_2 , L_3 ) ;
if ( V_10 )
F_3 ( V_2 , L_4 ) ;
else
F_4 ( V_2 , L_4 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
F_8 ( V_14 ,
V_20 , 2 , 2 ) ;
F_1 ( & V_19 -> V_2 ) ;
return F_9 ( V_21 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_11 ( V_21 ) ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_22 * V_23 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_24 * V_25 = V_16 -> V_25 ;
int V_26 ;
V_26 = F_13 ( V_25 , 0 , 12000000 ,
V_27 ) ;
return V_26 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_9 ;
return 0 ;
}
static int F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = F_16 ( V_29 ) ;
if ( V_9 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_9 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_34 -> V_2 ) ;
return 1 ;
}
static int F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_5 ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = F_16 ( V_29 ) ;
if ( V_5 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_5 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_34 -> V_2 ) ;
return 1 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . integer . V_32 [ 0 ] = V_10 ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = F_16 ( V_29 ) ;
if ( V_10 == V_31 -> V_32 . integer . V_32 [ 0 ] )
return 0 ;
V_10 = V_31 -> V_32 . integer . V_32 [ 0 ] ;
F_1 ( & V_34 -> V_2 ) ;
return 1 ;
}
static int F_21 ( struct V_35 * V_36 ,
struct V_28 * V_37 , int V_38 )
{
if ( F_22 ( V_38 ) )
F_23 ( V_39 , 1 ) ;
else
F_23 ( V_39 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 ,
struct V_28 * V_37 , int V_38 )
{
if ( F_22 ( V_38 ) )
F_23 ( V_40 , 1 ) ;
else
F_23 ( V_40 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_1 * V_2 = & V_19 -> V_2 ;
F_26 ( V_2 , L_5 ) ;
F_26 ( V_2 , L_6 ) ;
F_26 ( V_2 , L_7 ) ;
F_26 ( V_2 , L_8 ) ;
F_26 ( V_2 , L_9 ) ;
F_26 ( V_2 , L_10 ) ;
F_26 ( V_2 , L_11 ) ;
F_26 ( V_2 , L_12 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
int V_26 ;
struct V_41 * V_42 ;
if ( ! F_28 () ||
( ! F_29 ( L_13 ) &&
! F_29 ( L_14 ) ) )
return - V_43 ;
V_44 = F_30 ( L_15 , - 1 ) ;
if ( ! V_44 )
return - V_45 ;
F_31 ( V_44 , & V_46 ) ;
V_26 = F_32 ( V_44 ) ;
if ( V_26 )
goto V_47;
V_42 = & V_44 -> V_42 ;
V_48 = F_33 ( V_42 , L_16 ) ;
if ( F_34 ( V_48 ) ) {
F_35 ( V_42 , L_17 ) ;
V_26 = F_36 ( V_48 ) ;
goto V_49;
}
V_21 = F_33 ( V_42 , L_18 ) ;
if ( F_34 ( V_21 ) ) {
F_35 ( V_42 , L_19 ) ;
V_26 = F_36 ( V_21 ) ;
goto V_50;
}
V_51 = F_33 ( V_42 , L_20 ) ;
if ( F_34 ( V_51 ) ) {
F_35 ( V_42 , L_21 ) ;
V_26 = F_36 ( V_51 ) ;
goto V_52;
}
F_37 ( V_48 , V_51 ) ;
F_38 ( V_21 , 12000000 ) ;
if ( F_39 ( ( F_40 ( V_40 , L_22 ) < 0 ) ||
( F_40 ( V_39 , L_23 ) < 0 ) ) ) {
V_26 = - V_53 ;
goto V_52;
}
F_41 ( V_40 , 0 ) ;
F_41 ( V_39 , 0 ) ;
return 0 ;
V_52:
F_42 ( V_21 ) ;
V_50:
F_42 ( V_48 ) ;
V_49:
F_43 ( V_44 ) ;
V_47:
F_44 ( V_44 ) ;
return V_26 ;
}
static void T_2 F_45 ( void )
{
F_46 ( V_39 ) ;
F_46 ( V_40 ) ;
F_42 ( V_48 ) ;
F_42 ( V_21 ) ;
F_42 ( V_51 ) ;
F_47 ( V_44 ) ;
}
