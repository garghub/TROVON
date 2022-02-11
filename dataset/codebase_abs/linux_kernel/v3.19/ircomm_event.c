static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
switch ( V_3 ) {
case V_9 :
F_2 ( V_2 , V_10 ) ;
V_8 = V_2 -> V_11 . V_12 ( V_2 , V_5 , V_7 ) ;
break;
case V_13 :
case V_14 :
F_2 ( V_2 , V_15 ) ;
F_3 ( V_2 , V_5 , V_7 ) ;
break;
default:
F_4 ( L_1 , V_16 ,
V_17 [ V_3 ] ) ;
V_8 = - V_18 ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
switch ( V_3 ) {
case V_19 :
case V_20 :
F_2 ( V_2 , V_21 ) ;
F_6 ( V_2 , V_5 , V_7 ) ;
break;
case V_22 :
case V_23 :
F_2 ( V_2 , V_24 ) ;
F_7 ( V_2 , V_5 , V_7 ) ;
break;
default:
F_4 ( L_1 , V_16 ,
V_17 [ V_3 ] ) ;
V_8 = - V_18 ;
}
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
switch ( V_3 ) {
case V_25 :
F_2 ( V_2 , V_21 ) ;
V_8 = V_2 -> V_11 . V_26 ( V_2 , V_5 ) ;
break;
case V_27 :
F_2 ( V_2 , V_24 ) ;
V_8 = V_2 -> V_11 . V_28 ( V_2 , V_5 , V_7 ) ;
break;
case V_22 :
case V_23 :
F_2 ( V_2 , V_24 ) ;
F_7 ( V_2 , V_5 , V_7 ) ;
break;
default:
F_4 ( L_2 , V_16 ,
V_17 [ V_3 ] ) ;
V_8 = - V_18 ;
}
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
switch ( V_3 ) {
case V_29 :
V_8 = V_2 -> V_11 . V_30 ( V_2 , V_5 , 0 ) ;
break;
case V_31 :
F_10 ( V_2 , V_5 ) ;
break;
case V_32 :
F_11 ( V_2 , V_5 ) ;
break;
case V_33 :
V_8 = V_2 -> V_11 . V_30 ( V_2 , V_5 , V_5 -> V_34 ) ;
break;
case V_22 :
case V_23 :
F_2 ( V_2 , V_24 ) ;
F_7 ( V_2 , V_5 , V_7 ) ;
break;
case V_27 :
F_2 ( V_2 , V_24 ) ;
V_8 = V_2 -> V_11 . V_28 ( V_2 , V_5 , V_7 ) ;
break;
default:
F_4 ( L_2 , V_16 ,
V_17 [ V_3 ] ) ;
V_8 = - V_18 ;
}
return V_8 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
F_4 ( L_3 , V_16 ,
V_35 [ V_2 -> V_36 ] , V_17 [ V_3 ] ) ;
return (* V_36 [ V_2 -> V_36 ])( V_2 , V_3 , V_5 , V_7 ) ;
}
void F_2 ( struct V_1 * V_2 , T_2 V_36 )
{
V_2 -> V_36 = V_36 ;
F_4 ( L_4 , V_16 ,
V_35 [ V_2 -> V_36 ] , V_2 -> V_37 ) ;
}
