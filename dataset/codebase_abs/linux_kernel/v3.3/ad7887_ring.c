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
switch ( * V_2 -> V_9 ) {
case ( 1 << 0 ) :
V_4 -> V_19 = & V_4 -> V_20 [ V_21 ] ;
break;
case ( 1 << 1 ) :
V_4 -> V_19 = & V_4 -> V_20 [ V_22 ] ;
F_4 ( V_4 -> V_23 , V_4 -> V_19 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_4 -> V_19 = & V_4 -> V_20 [ V_24 ] ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_23 , & V_4 -> V_20 [ V_21 ] ) ;
}
static T_1 F_6 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_16 V_29 ;
T_2 * V_30 ;
int V_31 ;
unsigned int V_32 = F_3 ( V_2 -> V_9 ,
V_2 -> V_10 ) *
V_4 -> V_11 -> V_12 [ 0 ] . V_13 . V_14 / 8 ;
V_30 = F_7 ( V_4 -> V_8 , V_33 ) ;
if ( V_30 == NULL )
return - V_34 ;
V_31 = F_4 ( V_4 -> V_23 , V_4 -> V_19 ) ;
if ( V_31 )
goto V_35;
V_29 = F_8 () ;
memcpy ( V_30 , V_4 -> V_36 , V_32 ) ;
if ( V_6 -> V_15 )
memcpy ( V_30 + V_4 -> V_8 - sizeof( V_16 ) ,
& V_29 , sizeof( V_29 ) ) ;
V_2 -> V_7 -> V_17 -> V_37 ( V_2 -> V_7 , V_30 , V_29 ) ;
V_35:
F_9 ( V_30 ) ;
F_10 ( V_2 -> V_38 ) ;
return V_39 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_7 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_7 ) {
V_40 = - V_34 ;
goto V_41;
}
V_2 -> V_7 -> V_17 = & V_42 ;
V_2 -> V_43 = F_13 ( & V_44 ,
& F_6 ,
V_45 ,
V_2 ,
L_1 ,
V_2 -> V_46 ) ;
if ( V_2 -> V_43 == NULL ) {
V_40 = - V_34 ;
goto V_47;
}
V_2 -> V_48 = & V_49 ;
V_2 -> V_50 |= V_51 ;
return 0 ;
V_47:
F_14 ( V_2 -> V_7 ) ;
V_41:
return V_40 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_43 ) ;
F_14 ( V_2 -> V_7 ) ;
}
