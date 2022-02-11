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
F_8 ( V_14 ,
V_18 , 2 , 2 ) ;
F_1 ( & V_16 -> V_19 -> V_2 ) ;
return F_9 ( V_20 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_11 ( V_20 ) ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_21 * V_22 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_23 * V_24 = V_16 -> V_24 ;
int V_25 ;
V_25 = F_13 ( V_24 , 0 , 12000000 ,
V_26 ) ;
return V_25 ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . integer . V_31 [ 0 ] = V_9 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_32 * V_19 = F_16 ( V_28 ) ;
if ( V_9 == V_30 -> V_31 . integer . V_31 [ 0 ] )
return 0 ;
V_9 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
F_1 ( & V_19 -> V_2 ) ;
return 1 ;
}
static int F_17 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . integer . V_31 [ 0 ] = V_5 ;
return 0 ;
}
static int F_18 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_32 * V_19 = F_16 ( V_28 ) ;
if ( V_5 == V_30 -> V_31 . integer . V_31 [ 0 ] )
return 0 ;
V_5 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
F_1 ( & V_19 -> V_2 ) ;
return 1 ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . integer . V_31 [ 0 ] = V_10 ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_32 * V_19 = F_16 ( V_28 ) ;
if ( V_10 == V_30 -> V_31 . integer . V_31 [ 0 ] )
return 0 ;
V_10 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
F_1 ( & V_19 -> V_2 ) ;
return 1 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_27 * V_35 , int V_36 )
{
if ( F_22 ( V_36 ) )
F_23 ( V_37 , 1 ) ;
else
F_23 ( V_37 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_33 * V_34 ,
struct V_27 * V_35 , int V_36 )
{
if ( F_22 ( V_36 ) )
F_23 ( V_38 , 1 ) ;
else
F_23 ( V_38 , 0 ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
int V_25 ;
struct V_39 * V_40 ;
if ( ! F_26 () ||
( ! F_27 ( L_5 ) &&
! F_27 ( L_6 ) ) )
return - V_41 ;
V_42 = F_28 ( L_7 , - 1 ) ;
if ( ! V_42 )
return - V_43 ;
F_29 ( V_42 , & V_44 ) ;
V_25 = F_30 ( V_42 ) ;
if ( V_25 )
goto V_45;
V_40 = & V_42 -> V_40 ;
V_46 = F_31 ( V_40 , L_8 ) ;
if ( F_32 ( V_46 ) ) {
F_33 ( V_40 , L_9 ) ;
V_25 = F_34 ( V_46 ) ;
goto V_47;
}
V_20 = F_31 ( V_40 , L_10 ) ;
if ( F_32 ( V_20 ) ) {
F_33 ( V_40 , L_11 ) ;
V_25 = F_34 ( V_20 ) ;
goto V_48;
}
V_49 = F_31 ( V_40 , L_12 ) ;
if ( F_32 ( V_49 ) ) {
F_33 ( V_40 , L_13 ) ;
V_25 = F_34 ( V_49 ) ;
goto V_50;
}
F_35 ( V_46 , V_49 ) ;
F_36 ( V_20 , 12000000 ) ;
if ( F_37 ( ( F_38 ( V_38 , L_14 ) < 0 ) ||
( F_38 ( V_37 , L_15 ) < 0 ) ) ) {
V_25 = - V_51 ;
goto V_50;
}
F_39 ( V_38 , 0 ) ;
F_39 ( V_37 , 0 ) ;
return 0 ;
V_50:
F_40 ( V_20 ) ;
V_48:
F_40 ( V_46 ) ;
V_47:
F_41 ( V_42 ) ;
V_45:
F_42 ( V_42 ) ;
return V_25 ;
}
static void T_2 F_43 ( void )
{
F_44 ( V_37 ) ;
F_44 ( V_38 ) ;
F_40 ( V_46 ) ;
F_40 ( V_20 ) ;
F_40 ( V_49 ) ;
F_45 ( V_42 ) ;
}
