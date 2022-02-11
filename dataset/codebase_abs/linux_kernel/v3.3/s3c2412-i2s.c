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
if ( F_5 ( V_5 . V_11 ) ) {
F_6 ( L_3 ) ;
F_7 ( V_5 . V_13 ) ;
return F_8 ( V_5 . V_11 ) ;
}
F_9 ( V_5 . V_11 , F_4 ( NULL , L_4 ) ) ;
F_10 ( V_5 . V_11 ) ;
V_5 . V_11 = V_5 . V_14 ;
F_11 ( V_15 , V_16 ) ;
F_11 ( V_17 , V_18 ) ;
F_11 ( V_19 , V_20 ) ;
F_11 ( V_21 , V_22 ) ;
F_11 ( V_23 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_13 ( V_5 . V_11 ) ;
F_14 ( V_5 . V_11 ) ;
F_7 ( V_5 . V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_1 * V_29 )
{
struct V_30 * V_31 = F_16 ( V_29 ) ;
struct V_32 * V_33 ;
T_1 V_34 ;
F_2 ( L_1 , V_4 ) ;
if ( V_26 -> V_35 == V_36 )
V_33 = V_31 -> V_9 ;
else
V_33 = V_31 -> V_7 ;
F_17 ( V_29 , V_26 , V_33 ) ;
V_34 = F_18 ( V_31 -> V_13 + V_37 ) ;
F_2 ( L_5 , V_4 , V_34 ) ;
switch ( F_19 ( V_28 ) ) {
case V_38 :
V_34 |= V_39 ;
break;
case V_40 :
V_34 &= ~ V_39 ;
break;
}
F_20 ( V_34 , V_31 -> V_13 + V_37 ) ;
F_2 ( L_6 , V_4 , V_34 ) ;
return 0 ;
}
static T_2 int F_21 ( struct V_41 * V_42 )
{
return F_22 ( & V_42 -> V_12 , & V_43 ) ;
}
static T_3 int F_23 ( struct V_41 * V_42 )
{
F_24 ( & V_42 -> V_12 ) ;
return 0 ;
}
