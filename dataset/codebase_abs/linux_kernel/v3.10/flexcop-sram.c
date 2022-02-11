static void F_1 ( struct V_1 * V_2 ,
T_1 type )
{
F_2 ( V_3 , V_4 , type ) ;
}
int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
case V_7 :
F_1 ( V_2 , V_8 ) ;
break;
case V_9 :
F_1 ( V_2 , V_10 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_2 V_12 ,
T_3 V_13 )
{
T_4 V_14 ;
V_14 = V_2 -> V_15 ( V_2 , V_16 ) ;
if ( V_2 -> V_5 != V_9 && V_13 == V_17 ) {
F_5 ( L_1 ) ;
return - V_11 ;
}
F_6 ( L_2 , V_12 , V_13 ) ;
if ( V_12 & V_18 )
V_14 . V_16 . V_19 = V_13 ;
if ( V_12 & V_20 )
V_14 . V_16 . V_21 = V_13 ;
if ( V_12 & V_22 )
V_14 . V_16 . V_23 = V_13 ;
if ( V_12 & V_24 )
V_14 . V_16 . V_25 = V_13 ;
V_2 -> V_26 ( V_2 , V_16 , V_14 ) ;
F_7 ( 1000 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 , T_5 V_27 )
{
F_2 ( V_3 , V_28 , V_27 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_29 , int V_30 , int V_31 )
{
T_4 V_14 = V_2 -> V_15 ( V_2 , V_16 ) ;
V_14 . V_16 . V_32 = V_29 ;
V_14 . V_16 . V_33 = V_30 ;
V_14 . V_16 . V_34 = V_31 ;
V_2 -> V_26 ( V_2 , V_16 , V_14 ) ;
}
