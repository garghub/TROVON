static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 = V_4 -> V_14 ;
int V_15 = 0 ;
if ( V_13 >= F_3 ( V_16 ) )
return - V_17 ;
if ( V_7 != V_18 )
return - V_17 ;
F_4 ( & V_11 -> V_19 ) ;
switch ( V_4 -> V_14 ) {
case 0 :
* V_5 = F_5 ( V_11 , V_20 ) ;
break;
case 1 :
* V_5 = F_5 ( V_11 , V_21 ) ;
break;
case 2 :
* V_5 = F_5 ( V_11 , V_22 ) ;
break;
case 3 :
* V_5 = F_5 ( V_11 , V_23 ) ;
break;
case 4 :
* V_5 = F_5 ( V_11 , ( V_24 | V_25 ) ) ;
break;
case 5 : {
struct V_26 V_27 ;
V_27 . V_28 = F_5 ( V_11 , V_20 ) ;
V_27 . V_29 = F_5 ( V_11 , V_22 ) ;
V_27 . V_30 = F_5 ( V_11 , V_23 ) ;
* V_5 = F_6 ( V_11 , & V_27 ) ;
break;
}
case 6 :
* V_5 = F_7 ( V_11 ) ;
break;
case 7 :
* V_5 = F_5 ( V_11 ,
( V_24 | V_31 ) ) ;
break;
case 8 :
* V_5 = F_5 ( V_11 ,
( V_24 | V_32 ) ) ;
break;
}
F_5 ( V_11 , V_33 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_15 = V_34 ;
return V_15 ;
}
int F_9 ( struct V_10 * V_12 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int error ;
V_2 = F_10 ( & V_12 -> V_35 -> V_36 , sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
F_11 ( & V_12 -> V_35 -> V_36 , L_1 ) ;
return - V_37 ;
}
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = V_12 ;
V_2 -> V_38 = L_2 ;
V_2 -> V_36 . V_39 = & V_12 -> V_35 -> V_36 ;
V_2 -> V_40 = & V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_16 ;
V_2 -> V_45 = F_3 ( V_16 ) ;
error = F_12 ( & V_12 -> V_35 -> V_36 , V_2 ) ;
if ( error ) {
F_11 ( & V_12 -> V_35 -> V_36 ,
L_3 , error ) ;
return error ;
}
return 0 ;
}
