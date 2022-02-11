int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 ;
T_1 * V_7 ;
V_7 = F_2 ( V_4 -> V_8 -> V_9 ( V_4 ) ,
V_10 ) ;
if ( V_7 == NULL ) {
V_6 = - V_11 ;
goto V_12;
}
V_6 = V_4 -> V_8 -> V_13 ( V_4 , V_7 ) ;
if ( V_6 )
goto V_14;
V_6 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
V_14:
F_3 ( V_7 ) ;
V_12:
return V_6 ;
}
static int F_4 ( struct V_15 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_16 ;
struct V_3 * V_4 = V_5 -> V_4 ;
V_2 -> V_17 = V_4 -> V_18 *
V_2 -> V_19 -> V_20 [ 0 ] . V_21 . V_22 / 8 ;
if ( V_4 -> V_23 ) {
V_2 -> V_17 += sizeof( V_24 ) ;
if ( V_2 -> V_17 % sizeof( V_24 ) )
V_2 -> V_17 += sizeof( V_24 ) - ( V_2 -> V_17 % sizeof( V_24 ) ) ;
}
if ( V_5 -> V_4 -> V_8 -> V_25 )
V_5 -> V_4 -> V_8 -> V_25 ( V_5 -> V_4 ,
V_2 -> V_17 ) ;
return 0 ;
}
static T_2 F_5 ( int V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_15 * V_5 = V_29 -> V_30 ;
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_24 V_31 ;
T_3 * V_32 ;
int V_33 ;
V_32 = F_7 ( V_2 -> V_17 , V_10 ) ;
if ( V_32 == NULL )
return - V_11 ;
V_33 = F_8 ( V_2 -> V_34 , V_32 ,
V_2 -> V_19 -> V_20 [ 0 ] . V_21 . V_22 / 8 ) ;
if ( V_33 < 0 )
goto V_35;
V_31 = F_9 () ;
if ( V_5 -> V_4 -> V_23 )
memcpy ( V_32 + V_2 -> V_17 - sizeof( V_24 ) ,
& V_31 , sizeof( V_31 ) ) ;
V_5 -> V_4 -> V_8 -> V_36 ( V_5 -> V_4 , V_32 , V_31 ) ;
V_35:
F_10 ( V_5 -> V_37 ) ;
F_3 ( V_32 ) ;
return V_38 ;
}
int F_11 ( struct V_15 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_16 ;
int V_6 = 0 ;
V_5 -> V_4 = F_12 ( V_5 ) ;
if ( ! V_5 -> V_4 ) {
V_6 = - V_11 ;
goto V_12;
}
V_5 -> V_4 -> V_8 = & V_39 ;
V_5 -> V_40
= F_13 ( NULL ,
& F_5 ,
V_41 ,
V_5 ,
L_1 ,
F_14 ( V_2 -> V_34 ) -> V_42 ,
V_5 -> V_43 ) ;
if ( V_5 -> V_40 == NULL ) {
V_6 = - V_11 ;
goto V_44;
}
V_5 -> V_4 -> V_45 = & V_46 ;
V_5 -> V_4 -> V_23 = true ;
V_5 -> V_47 |= V_48 ;
return 0 ;
V_44:
F_15 ( V_5 -> V_4 ) ;
V_12:
return V_6 ;
}
void F_16 ( struct V_15 * V_5 )
{
if ( V_5 -> V_37 ) {
F_17 ( V_5 -> V_37 ) ;
F_18 ( V_5 -> V_37 ,
V_5 -> V_40 ) ;
}
F_19 ( V_5 -> V_40 ) ;
F_15 ( V_5 -> V_4 ) ;
}
