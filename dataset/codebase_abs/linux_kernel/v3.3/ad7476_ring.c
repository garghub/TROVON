static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> V_8 = F_3 ( V_2 -> V_9 ,
V_2 -> V_10 ) *
V_4 -> V_11 -> V_12 [ 0 ] . V_13 . V_14 / 8 ;
if ( V_6 -> V_15 ) {
V_4 -> V_8 += sizeof( V_16 ) ;
if ( V_4 -> V_8 % sizeof( V_16 ) )
V_4 -> V_8 += sizeof( V_16 ) - ( V_4 -> V_8 % sizeof( V_16 ) ) ;
}
if ( V_2 -> V_7 -> V_17 -> V_18 )
V_2 -> V_7 -> V_17 ->
V_18 ( V_2 -> V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static T_1 F_4 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 V_23 ;
T_2 * V_24 ;
int V_25 ;
V_24 = F_5 ( V_4 -> V_8 , V_26 ) ;
if ( V_24 == NULL )
return - V_27 ;
V_25 = F_6 ( V_4 -> V_28 , V_24 ,
V_4 -> V_11 -> V_12 [ 0 ] . V_13 . V_14 / 8 ) ;
if ( V_25 < 0 )
goto V_29;
V_23 = F_7 () ;
if ( V_2 -> V_7 -> V_15 )
memcpy ( V_24 + V_4 -> V_8 - sizeof( V_16 ) ,
& V_23 , sizeof( V_23 ) ) ;
V_2 -> V_7 -> V_17 -> V_30 ( V_2 -> V_7 , V_24 , V_23 ) ;
V_29:
F_8 ( V_2 -> V_31 ) ;
F_9 ( V_24 ) ;
return V_32 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_33 = 0 ;
V_2 -> V_7 = F_11 ( V_2 ) ;
if ( ! V_2 -> V_7 ) {
V_33 = - V_27 ;
goto V_34;
}
V_2 -> V_7 -> V_17 = & V_35 ;
V_2 -> V_36
= F_12 ( NULL ,
& F_4 ,
V_37 ,
V_2 ,
L_1 ,
F_13 ( V_4 -> V_28 ) -> V_38 ,
V_2 -> V_39 ) ;
if ( V_2 -> V_36 == NULL ) {
V_33 = - V_27 ;
goto V_40;
}
V_2 -> V_41 = & V_42 ;
V_2 -> V_7 -> V_15 = true ;
V_2 -> V_43 |= V_44 ;
return 0 ;
V_40:
F_14 ( V_2 -> V_7 ) ;
V_34:
return V_33 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_36 ) ;
F_14 ( V_2 -> V_7 ) ;
}
