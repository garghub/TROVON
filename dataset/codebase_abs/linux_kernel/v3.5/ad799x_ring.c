static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 == V_6 || V_4 -> V_5 == V_7 )
F_3 ( V_4 , * V_2 -> V_8 ) ;
return F_4 ( V_2 ) ;
}
static T_1 F_5 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
T_2 V_16 ;
T_3 * V_17 ;
int V_18 ;
T_4 V_19 ;
V_17 = F_6 ( V_2 -> V_20 , V_21 ) ;
if ( V_17 == NULL )
goto V_22;
switch ( V_4 -> V_5 ) {
case V_23 :
case V_24 :
case V_25 :
V_19 = V_4 -> V_26 |
( * V_2 -> V_8 << V_27 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
V_19 = ( * V_2 -> V_8 << V_27 ) |
V_31 ;
break;
case V_6 :
case V_7 :
V_19 = V_32 | V_31 ;
break;
default:
V_19 = 0 ;
}
V_18 = F_7 ( V_4 -> V_33 ,
V_19 , F_8 ( V_2 -> V_8 ,
V_2 -> V_34 ) * 2 , V_17 ) ;
if ( V_18 < 0 )
goto V_35;
V_16 = F_9 () ;
if ( V_2 -> V_36 )
memcpy ( V_17 + V_2 -> V_20 - sizeof( T_2 ) ,
& V_16 , sizeof( V_16 ) ) ;
V_14 -> V_37 -> V_38 ( V_2 -> V_15 , V_17 , V_16 ) ;
V_35:
F_10 ( V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_22:
F_11 ( V_2 -> V_39 ) ;
return V_40 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
V_2 -> V_15 = F_13 ( V_2 ) ;
if ( ! V_2 -> V_15 ) {
V_41 = - V_42 ;
goto V_43;
}
V_2 -> V_44 = F_14 ( NULL ,
& F_5 ,
V_45 ,
V_2 ,
L_1 ,
V_2 -> V_46 ,
V_2 -> V_5 ) ;
if ( V_2 -> V_44 == NULL ) {
V_41 = - V_42 ;
goto V_47;
}
V_2 -> V_48 = & V_49 ;
V_2 -> V_15 -> V_36 = true ;
V_2 -> V_50 |= V_51 ;
return 0 ;
V_47:
F_15 ( V_2 -> V_15 ) ;
V_43:
return V_41 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_44 ) ;
F_15 ( V_2 -> V_15 ) ;
}
