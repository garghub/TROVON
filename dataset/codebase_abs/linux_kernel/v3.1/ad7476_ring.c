int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 * V_6 ;
V_6 = F_2 ( V_4 -> V_7 -> V_8 ( V_4 ) ,
V_9 ) ;
if ( V_6 == NULL ) {
V_5 = - V_10 ;
goto V_11;
}
V_5 = V_4 -> V_7 -> V_12 ( V_4 , V_6 ) ;
if ( V_5 )
goto V_13;
V_5 = ( V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_13:
F_3 ( V_6 ) ;
V_11:
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_5 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_15 -> V_16 = V_4 -> V_17 *
V_15 -> V_18 -> V_19 [ 0 ] . V_20 . V_21 / 8 ;
if ( V_4 -> V_22 ) {
V_15 -> V_16 += sizeof( V_23 ) ;
if ( V_15 -> V_16 % sizeof( V_23 ) )
V_15 -> V_16 += sizeof( V_23 ) - ( V_15 -> V_16 % sizeof( V_23 ) ) ;
}
if ( V_2 -> V_4 -> V_7 -> V_24 )
V_2 -> V_4 -> V_7 -> V_24 ( V_2 -> V_4 ,
V_15 -> V_16 ) ;
return 0 ;
}
static T_2 F_6 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_14 * V_15 = F_5 ( V_2 ) ;
V_23 V_30 ;
T_3 * V_31 ;
int V_32 ;
V_31 = F_7 ( V_15 -> V_16 , V_9 ) ;
if ( V_31 == NULL )
return - V_10 ;
V_32 = F_8 ( V_15 -> V_33 , V_31 ,
V_15 -> V_18 -> V_19 [ 0 ] . V_20 . V_21 / 8 ) ;
if ( V_32 < 0 )
goto V_34;
V_30 = F_9 () ;
if ( V_2 -> V_4 -> V_22 )
memcpy ( V_31 + V_15 -> V_16 - sizeof( V_23 ) ,
& V_30 , sizeof( V_30 ) ) ;
V_2 -> V_4 -> V_7 -> V_35 ( V_2 -> V_4 , V_31 , V_30 ) ;
V_34:
F_10 ( V_2 -> V_36 ) ;
F_3 ( V_31 ) ;
return V_37 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_5 ( V_2 ) ;
int V_5 = 0 ;
V_2 -> V_4 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_4 ) {
V_5 = - V_10 ;
goto V_11;
}
V_2 -> V_4 -> V_7 = & V_38 ;
V_2 -> V_39
= F_13 ( NULL ,
& F_6 ,
V_40 ,
V_2 ,
L_1 ,
F_14 ( V_15 -> V_33 ) -> V_41 ,
V_2 -> V_42 ) ;
if ( V_2 -> V_39 == NULL ) {
V_5 = - V_10 ;
goto V_43;
}
V_2 -> V_4 -> V_44 = & V_45 ;
V_2 -> V_4 -> V_22 = true ;
V_2 -> V_46 |= V_47 ;
return 0 ;
V_43:
F_15 ( V_2 -> V_4 ) ;
V_11:
return V_5 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 ) {
F_17 ( V_2 -> V_36 ) ;
F_18 ( V_2 -> V_36 ,
V_2 -> V_39 ) ;
}
F_19 ( V_2 -> V_39 ) ;
F_15 ( V_2 -> V_4 ) ;
}
