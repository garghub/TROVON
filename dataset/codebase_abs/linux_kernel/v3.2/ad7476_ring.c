int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
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
static int F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_16 -> V_17 = V_4 -> V_18 *
V_16 -> V_19 -> V_20 [ 0 ] . V_21 . V_22 / 8 ;
if ( V_4 -> V_23 ) {
V_16 -> V_17 += sizeof( V_24 ) ;
if ( V_16 -> V_17 % sizeof( V_24 ) )
V_16 -> V_17 += sizeof( V_24 ) - ( V_16 -> V_17 % sizeof( V_24 ) ) ;
}
if ( V_2 -> V_5 -> V_8 -> V_25 )
V_2 -> V_5 -> V_8 ->
V_25 ( V_2 -> V_5 , V_16 -> V_17 ) ;
return 0 ;
}
static T_2 F_6 ( int V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_15 * V_16 = F_5 ( V_2 ) ;
V_24 V_30 ;
T_3 * V_31 ;
int V_32 ;
V_31 = F_7 ( V_16 -> V_17 , V_10 ) ;
if ( V_31 == NULL )
return - V_11 ;
V_32 = F_8 ( V_16 -> V_33 , V_31 ,
V_16 -> V_19 -> V_20 [ 0 ] . V_21 . V_22 / 8 ) ;
if ( V_32 < 0 )
goto V_34;
V_30 = F_9 () ;
if ( V_2 -> V_5 -> V_23 )
memcpy ( V_31 + V_16 -> V_17 - sizeof( V_24 ) ,
& V_30 , sizeof( V_30 ) ) ;
V_2 -> V_5 -> V_8 -> V_35 ( V_2 -> V_5 , V_31 , V_30 ) ;
V_34:
F_10 ( V_2 -> V_36 ) ;
F_3 ( V_31 ) ;
return V_37 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
int V_6 = 0 ;
V_2 -> V_5 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_5 ) {
V_6 = - V_11 ;
goto V_12;
}
V_2 -> V_5 -> V_8 = & V_38 ;
V_2 -> V_39
= F_13 ( NULL ,
& F_6 ,
V_40 ,
V_2 ,
L_1 ,
F_14 ( V_16 -> V_33 ) -> V_41 ,
V_2 -> V_42 ) ;
if ( V_2 -> V_39 == NULL ) {
V_6 = - V_11 ;
goto V_43;
}
V_2 -> V_5 -> V_44 = & V_45 ;
V_2 -> V_5 -> V_23 = true ;
V_2 -> V_46 |= V_47 ;
return 0 ;
V_43:
F_15 ( V_2 -> V_5 ) ;
V_12:
return V_6 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_39 ) ;
F_15 ( V_2 -> V_5 ) ;
}
