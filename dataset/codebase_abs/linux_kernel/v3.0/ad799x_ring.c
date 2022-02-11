int F_1 ( struct V_1 * V_2 , long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) -> V_5 ;
int V_6 = 0 , V_7 ;
T_1 * V_8 ;
if ( ! ( V_5 -> V_9 & V_3 ) ) {
V_7 = - V_10 ;
goto V_11;
}
V_8 = F_3 ( V_5 -> V_12 -> V_13 ( V_5 ) ,
V_14 ) ;
if ( V_8 == NULL ) {
V_7 = - V_15 ;
goto V_11;
}
V_7 = V_5 -> V_12 -> V_16 ( V_5 , ( V_17 * ) V_8 ) ;
if ( V_7 )
goto V_18;
V_3 >>= 1 ;
while ( V_3 ) {
if ( V_3 & V_5 -> V_9 )
V_6 ++ ;
V_3 >>= 1 ;
}
V_7 = F_4 ( V_8 [ V_6 ] ) ;
V_18:
F_5 ( V_8 ) ;
V_11:
return V_7 ;
}
static int F_6 ( struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
if ( V_2 -> V_21 == V_22 || V_2 -> V_21 == V_23 )
F_8 ( V_2 , V_5 -> V_9 ) ;
V_2 -> V_24 = V_5 -> V_25 * 2 ;
if ( V_5 -> V_26 ) {
V_2 -> V_24 += sizeof( V_27 ) ;
if ( V_2 -> V_24 % sizeof( V_27 ) )
V_2 -> V_24 += sizeof( V_27 ) - ( V_2 -> V_24 % sizeof( V_27 ) ) ;
}
if ( V_20 -> V_5 -> V_12 -> V_28 )
V_20 -> V_5 -> V_12 -> V_28 ( V_20 -> V_5 ,
V_2 -> V_24 ) ;
return 0 ;
}
static T_2 F_9 ( int V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_19 * V_20 = V_32 -> V_33 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
V_27 V_34 ;
T_3 * V_35 ;
int V_36 ;
V_17 V_37 ;
V_35 = F_3 ( V_2 -> V_24 , V_14 ) ;
if ( V_35 == NULL )
goto V_38;
switch ( V_2 -> V_21 ) {
case V_39 :
case V_40 :
case V_41 :
V_37 = V_2 -> V_42 | ( V_5 -> V_9 << V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
V_37 = ( V_5 -> V_9 << V_43 ) |
V_47 ;
break;
case V_22 :
case V_23 :
V_37 = V_48 | V_47 ;
break;
default:
V_37 = 0 ;
}
V_36 = F_10 ( V_2 -> V_49 ,
V_37 , V_5 -> V_25 * 2 , V_35 ) ;
if ( V_36 < 0 )
goto V_50;
V_34 = F_11 () ;
if ( V_5 -> V_26 )
memcpy ( V_35 + V_2 -> V_24 - sizeof( V_27 ) ,
& V_34 , sizeof( V_34 ) ) ;
V_5 -> V_12 -> V_51 ( V_20 -> V_5 , V_35 , V_34 ) ;
V_50:
F_5 ( V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
V_38:
F_12 ( V_20 -> V_52 ) ;
return V_53 ;
}
int F_13 ( struct V_19 * V_20 )
{
int V_7 = 0 ;
V_20 -> V_5 = F_14 ( V_20 ) ;
if ( ! V_20 -> V_5 ) {
V_7 = - V_15 ;
goto V_11;
}
V_20 -> V_5 -> V_12 = & V_54 ;
V_20 -> V_55 = F_15 ( NULL ,
& F_9 ,
V_56 ,
V_20 ,
L_1 ,
V_20 -> V_57 ,
V_20 -> V_21 ) ;
if ( V_20 -> V_55 == NULL ) {
V_7 = - V_15 ;
goto V_58;
}
V_20 -> V_5 -> V_59 = & V_60 ;
V_20 -> V_5 -> V_26 = true ;
V_20 -> V_61 |= V_62 ;
return 0 ;
V_58:
F_16 ( V_20 -> V_5 ) ;
V_11:
return V_7 ;
}
void F_17 ( struct V_19 * V_20 )
{
if ( V_20 -> V_52 ) {
F_18 ( V_20 -> V_52 ) ;
F_19 ( V_20 -> V_52 ,
V_20 -> V_55 ) ;
}
F_20 ( V_20 -> V_55 ) ;
F_16 ( V_20 -> V_5 ) ;
}
