static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_8 == V_9 || V_7 -> V_8 == V_10 )
F_3 ( V_7 , * V_2 -> V_11 ) ;
V_7 -> V_12 = F_4 ( V_2 -> V_11 ,
V_2 -> V_13 ) * 2 ;
if ( V_4 -> V_14 ) {
V_7 -> V_12 += sizeof( V_15 ) ;
if ( V_7 -> V_12 % sizeof( V_15 ) )
V_7 -> V_12 += sizeof( V_15 ) - ( V_7 -> V_12 % sizeof( V_15 ) ) ;
}
if ( V_2 -> V_5 -> V_16 -> V_17 )
V_2 -> V_5 -> V_16 ->
V_17 ( V_2 -> V_5 , V_7 -> V_12 ) ;
return 0 ;
}
static T_1 F_5 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_15 V_22 ;
T_2 * V_23 ;
int V_24 ;
T_3 V_25 ;
V_23 = F_6 ( V_7 -> V_12 , V_26 ) ;
if ( V_23 == NULL )
goto V_27;
switch ( V_7 -> V_8 ) {
case V_28 :
case V_29 :
case V_30 :
V_25 = V_7 -> V_31 |
( * V_2 -> V_11 << V_32 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
V_25 = ( * V_2 -> V_11 << V_32 ) |
V_36 ;
break;
case V_9 :
case V_10 :
V_25 = V_37 | V_36 ;
break;
default:
V_25 = 0 ;
}
V_24 = F_7 ( V_7 -> V_38 ,
V_25 , F_4 ( V_2 -> V_11 ,
V_2 -> V_13 ) * 2 , V_23 ) ;
if ( V_24 < 0 )
goto V_39;
V_22 = F_8 () ;
if ( V_4 -> V_14 )
memcpy ( V_23 + V_7 -> V_12 - sizeof( V_15 ) ,
& V_22 , sizeof( V_22 ) ) ;
V_4 -> V_16 -> V_40 ( V_2 -> V_5 , V_23 , V_22 ) ;
V_39:
F_9 ( V_23 ) ;
if ( V_24 < 0 )
return V_24 ;
V_27:
F_10 ( V_2 -> V_41 ) ;
return V_42 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_43 = 0 ;
V_2 -> V_5 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_5 ) {
V_43 = - V_44 ;
goto V_45;
}
V_2 -> V_5 -> V_16 = & V_46 ;
V_2 -> V_47 = F_13 ( NULL ,
& F_5 ,
V_48 ,
V_2 ,
L_1 ,
V_2 -> V_49 ,
V_2 -> V_8 ) ;
if ( V_2 -> V_47 == NULL ) {
V_43 = - V_44 ;
goto V_50;
}
V_2 -> V_51 = & V_52 ;
V_2 -> V_5 -> V_14 = true ;
V_2 -> V_53 |= V_54 ;
return 0 ;
V_50:
F_14 ( V_2 -> V_5 ) ;
V_45:
return V_43 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_47 ) ;
F_14 ( V_2 -> V_5 ) ;
}
