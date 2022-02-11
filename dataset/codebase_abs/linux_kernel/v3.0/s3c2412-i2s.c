static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 , V_4 ) ;
V_3 = F_3 ( V_2 , & V_5 , V_6 ) ;
if ( V_3 )
return V_3 ;
V_5 . V_7 = & V_8 ;
V_5 . V_9 = & V_10 ;
V_5 . V_11 = F_4 ( V_2 -> V_12 , L_2 ) ;
if ( V_5 . V_11 == NULL ) {
F_5 ( L_3 ) ;
F_6 ( V_5 . V_13 ) ;
return - V_14 ;
}
F_7 ( V_5 . V_11 , F_4 ( NULL , L_4 ) ) ;
F_8 ( V_5 . V_11 ) ;
V_5 . V_11 = V_5 . V_15 ;
F_9 ( V_16 , V_17 ) ;
F_9 ( V_18 , V_19 ) ;
F_9 ( V_20 , V_21 ) ;
F_9 ( V_22 , V_23 ) ;
F_9 ( V_24 , V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_5 . V_11 ) ;
F_12 ( V_5 . V_11 ) ;
F_6 ( V_5 . V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_1 * V_30 )
{
struct V_31 * V_32 = F_14 ( V_30 ) ;
struct V_33 * V_34 ;
T_1 V_35 ;
F_2 ( L_1 , V_4 ) ;
if ( V_27 -> V_36 == V_37 )
V_34 = V_32 -> V_9 ;
else
V_34 = V_32 -> V_7 ;
F_15 ( V_30 , V_27 , V_34 ) ;
V_35 = F_16 ( V_32 -> V_13 + V_38 ) ;
F_2 ( L_5 , V_4 , V_35 ) ;
switch ( F_17 ( V_29 ) ) {
case V_39 :
V_35 |= V_40 ;
break;
case V_41 :
V_35 &= ~ V_40 ;
break;
}
F_18 ( V_35 , V_32 -> V_13 + V_38 ) ;
F_2 ( L_6 , V_4 , V_35 ) ;
return 0 ;
}
static T_2 int F_19 ( struct V_42 * V_43 )
{
return F_20 ( & V_43 -> V_12 , & V_44 ) ;
}
static T_3 int F_21 ( struct V_42 * V_43 )
{
F_22 ( & V_43 -> V_12 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_45 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_45 ) ;
}
