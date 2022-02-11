int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 0 , V_8 ;
T_1 * V_9 ;
if ( ! ( F_2 ( V_3 , V_5 -> V_10 ) ) ) {
V_8 = - V_11 ;
goto V_12;
}
V_9 = F_3 ( V_5 -> V_13 -> V_14 ( V_5 ) ,
V_15 ) ;
if ( V_9 == NULL ) {
V_8 = - V_16 ;
goto V_12;
}
V_8 = V_5 -> V_13 -> V_17 ( V_5 , ( V_18 * ) V_9 ) ;
if ( V_8 )
goto V_19;
V_7 = F_4 ( V_5 -> V_10 , V_3 ) ;
V_8 = F_5 ( V_9 [ V_7 ] ) ;
V_19:
F_6 ( V_9 ) ;
V_12:
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
if ( V_21 -> V_22 == V_23 || V_21 -> V_22 == V_24 )
F_9 ( V_21 , * V_5 -> V_10 ) ;
V_21 -> V_25 = V_5 -> V_26 * 2 ;
if ( V_5 -> V_27 ) {
V_21 -> V_25 += sizeof( V_28 ) ;
if ( V_21 -> V_25 % sizeof( V_28 ) )
V_21 -> V_25 += sizeof( V_28 ) - ( V_21 -> V_25 % sizeof( V_28 ) ) ;
}
if ( V_2 -> V_6 -> V_13 -> V_29 )
V_2 -> V_6 -> V_13 ->
V_29 ( V_2 -> V_6 , V_21 -> V_25 ) ;
return 0 ;
}
static T_2 F_10 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_28 V_34 ;
T_3 * V_35 ;
int V_36 ;
V_18 V_37 ;
V_35 = F_3 ( V_21 -> V_25 , V_15 ) ;
if ( V_35 == NULL )
goto V_38;
switch ( V_21 -> V_22 ) {
case V_39 :
case V_40 :
case V_41 :
V_37 = V_21 -> V_42 | ( * V_5 -> V_10 << V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
V_37 = ( * V_5 -> V_10 << V_43 ) |
V_47 ;
break;
case V_23 :
case V_24 :
V_37 = V_48 | V_47 ;
break;
default:
V_37 = 0 ;
}
V_36 = F_11 ( V_21 -> V_49 ,
V_37 , V_5 -> V_26 * 2 , V_35 ) ;
if ( V_36 < 0 )
goto V_50;
V_34 = F_12 () ;
if ( V_5 -> V_27 )
memcpy ( V_35 + V_21 -> V_25 - sizeof( V_28 ) ,
& V_34 , sizeof( V_34 ) ) ;
V_5 -> V_13 -> V_51 ( V_2 -> V_6 , V_35 , V_34 ) ;
V_50:
F_6 ( V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
V_38:
F_13 ( V_2 -> V_52 ) ;
return V_53 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
V_2 -> V_6 = F_15 ( V_2 ) ;
if ( ! V_2 -> V_6 ) {
V_8 = - V_16 ;
goto V_12;
}
V_2 -> V_6 -> V_13 = & V_54 ;
V_2 -> V_55 = F_16 ( NULL ,
& F_10 ,
V_56 ,
V_2 ,
L_1 ,
V_2 -> V_57 ,
V_2 -> V_22 ) ;
if ( V_2 -> V_55 == NULL ) {
V_8 = - V_16 ;
goto V_58;
}
V_2 -> V_6 -> V_59 = & V_60 ;
V_2 -> V_6 -> V_27 = true ;
V_2 -> V_61 |= V_62 ;
return 0 ;
V_58:
F_17 ( V_2 -> V_6 ) ;
V_12:
return V_8 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_55 ) ;
F_17 ( V_2 -> V_6 ) ;
}
