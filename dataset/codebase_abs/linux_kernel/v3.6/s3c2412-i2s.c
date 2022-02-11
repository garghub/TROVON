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
F_11 ( F_12 ( 0 ) , 5 , F_13 ( 2 ) ,
V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( V_5 . V_11 ) ;
F_16 ( V_5 . V_11 ) ;
F_7 ( V_5 . V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_1 * V_20 )
{
struct V_21 * V_22 = F_18 ( V_20 ) ;
struct V_23 * V_24 ;
T_1 V_25 ;
F_2 ( L_1 , V_4 ) ;
if ( V_17 -> V_26 == V_27 )
V_24 = V_22 -> V_9 ;
else
V_24 = V_22 -> V_7 ;
F_19 ( V_20 , V_17 , V_24 ) ;
V_25 = F_20 ( V_22 -> V_13 + V_28 ) ;
F_2 ( L_5 , V_4 , V_25 ) ;
switch ( F_21 ( V_19 ) ) {
case V_29 :
V_25 |= V_30 ;
break;
case V_31 :
V_25 &= ~ V_30 ;
break;
}
F_22 ( V_25 , V_22 -> V_13 + V_28 ) ;
F_2 ( L_6 , V_4 , V_25 ) ;
return 0 ;
}
static T_2 int F_23 ( struct V_32 * V_33 )
{
return F_24 ( & V_33 -> V_12 , - 1 , & V_34 ) ;
}
static T_3 int F_25 ( struct V_32 * V_33 )
{
F_26 ( & V_33 -> V_12 ) ;
return 0 ;
}
