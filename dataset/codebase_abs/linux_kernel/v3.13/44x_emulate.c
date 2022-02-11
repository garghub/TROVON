static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
switch ( V_4 ) {
case V_5 :
V_2 -> V_6 . V_7 = F_2 ( V_2 , V_3 ) ;
return V_8 ;
default:
V_2 -> V_9 -> V_10 . V_4 = V_4 ;
V_2 -> V_9 -> V_10 . V_11 = F_2 ( V_2 , V_3 ) ;
V_2 -> V_9 -> V_10 . V_12 = 1 ;
V_2 -> V_6 . V_13 = 1 ;
V_2 -> V_6 . V_14 = 1 ;
F_3 ( V_2 , V_15 ) ;
return V_16 ;
}
}
static int F_4 ( struct V_1 * V_2 , int V_17 , int V_4 )
{
switch ( V_4 ) {
case V_5 :
F_5 ( V_2 , V_17 , V_2 -> V_6 . V_7 ) ;
break;
case V_18 :
F_6 () ;
F_7 ( V_5 ,
V_2 -> V_6 . V_7 ) ;
F_5 ( V_2 , V_17 ,
F_8 ( V_18 ) ) ;
F_9 () ;
break;
default:
V_2 -> V_9 -> V_10 . V_4 = V_4 ;
V_2 -> V_9 -> V_10 . V_11 = 0 ;
V_2 -> V_9 -> V_10 . V_12 = 0 ;
V_2 -> V_6 . V_13 = 0 ;
V_2 -> V_6 . V_19 = V_17 ;
V_2 -> V_6 . V_14 = 1 ;
F_3 ( V_2 , V_15 ) ;
return V_16 ;
}
return V_8 ;
}
int F_10 ( struct V_20 * V_9 , struct V_1 * V_2 ,
unsigned int V_21 , int * V_22 )
{
int V_23 = V_8 ;
int V_4 = F_11 ( V_21 ) ;
int V_24 = F_12 ( V_21 ) ;
int V_25 = F_13 ( V_21 ) ;
int V_26 = F_14 ( V_21 ) ;
int V_3 = F_15 ( V_21 ) ;
int V_17 = F_16 ( V_21 ) ;
int V_27 = F_17 ( V_21 ) ;
switch ( F_18 ( V_21 ) ) {
case 31 :
switch ( F_19 ( V_21 ) ) {
case V_28 :
V_23 = F_4 ( V_2 , V_17 , V_4 ) ;
break;
case V_29 :
V_23 = F_4 ( V_2 , V_17 ,
F_2 ( V_2 , V_24 ) ) ;
break;
case V_30 :
V_23 = F_1 ( V_2 , V_3 , V_4 ) ;
break;
case V_31 :
V_23 = F_1 ( V_2 , V_3 ,
F_2 ( V_2 , V_24 ) ) ;
break;
case V_32 :
V_23 = F_20 ( V_2 , V_24 , V_3 , V_27 ) ;
break;
case V_33 :
V_23 = F_21 ( V_2 , V_17 , V_24 , V_25 , V_26 ) ;
break;
case V_34 :
break;
default:
V_23 = V_35 ;
}
break;
default:
V_23 = V_35 ;
}
if ( V_23 == V_35 )
V_23 = F_22 ( V_9 , V_2 , V_21 , V_22 ) ;
return V_23 ;
}
int F_23 ( struct V_1 * V_2 , int V_36 , T_1 V_37 )
{
int V_23 = V_8 ;
switch ( V_36 ) {
case V_38 :
F_24 ( V_2 , V_37 ) ; break;
case V_39 :
V_2 -> V_6 . V_40 = V_37 ; break;
case V_41 :
V_2 -> V_6 . V_42 = V_37 ; break;
case V_43 :
V_2 -> V_6 . V_44 = V_37 ; break;
default:
V_23 = F_25 ( V_2 , V_36 , V_37 ) ;
}
return V_23 ;
}
int F_26 ( struct V_1 * V_2 , int V_36 , T_1 * V_37 )
{
int V_23 = V_8 ;
switch ( V_36 ) {
case V_38 :
* V_37 = V_2 -> V_6 . V_45 ; break;
case V_39 :
* V_37 = V_2 -> V_6 . V_40 ; break;
case V_41 :
* V_37 = V_2 -> V_6 . V_42 ; break;
case V_43 :
* V_37 = V_2 -> V_6 . V_44 ; break;
default:
V_23 = F_27 ( V_2 , V_36 , V_37 ) ;
}
return V_23 ;
}
