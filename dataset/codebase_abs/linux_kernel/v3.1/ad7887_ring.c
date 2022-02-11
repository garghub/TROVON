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
if ( ( V_5 -> V_9 == ( ( 1 << 1 ) | ( 1 << 0 ) ) ) && ( V_3 == ( 1 << 1 ) ) )
V_6 = 1 ;
V_7 = F_4 ( V_8 [ V_6 ] ) ;
V_18:
F_5 ( V_8 ) ;
V_11:
return V_7 ;
}
static int F_6 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
V_2 -> V_21 = V_5 -> V_22 *
V_2 -> V_23 -> V_24 [ 0 ] . V_25 . V_26 / 8 ;
if ( V_5 -> V_27 ) {
V_2 -> V_21 += sizeof( V_28 ) ;
if ( V_2 -> V_21 % sizeof( V_28 ) )
V_2 -> V_21 += sizeof( V_28 ) - ( V_2 -> V_21 % sizeof( V_28 ) ) ;
}
if ( V_20 -> V_5 -> V_12 -> V_29 )
V_20 -> V_5 -> V_12 -> V_29 ( V_20 -> V_5 ,
V_2 -> V_21 ) ;
switch ( V_5 -> V_9 ) {
case ( 1 << 0 ) :
V_2 -> V_30 = & V_2 -> V_31 [ V_32 ] ;
break;
case ( 1 << 1 ) :
V_2 -> V_30 = & V_2 -> V_31 [ V_33 ] ;
F_8 ( V_2 -> V_34 , V_2 -> V_30 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_2 -> V_30 = & V_2 -> V_31 [ V_35 ] ;
break;
}
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
return F_8 ( V_2 -> V_34 , & V_2 -> V_31 [ V_32 ] ) ;
}
static T_2 F_10 ( int V_36 , void * V_37 )
{
struct V_38 * V_39 = V_37 ;
struct V_19 * V_20 = V_39 -> V_40 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
V_28 V_41 ;
T_3 * V_42 ;
int V_43 ;
unsigned int V_44 = V_5 -> V_22 *
V_2 -> V_23 -> V_24 [ 0 ] . V_25 . V_26 / 8 ;
V_42 = F_11 ( V_2 -> V_21 , V_14 ) ;
if ( V_42 == NULL )
return - V_15 ;
V_43 = F_8 ( V_2 -> V_34 , V_2 -> V_30 ) ;
if ( V_43 )
goto V_45;
V_41 = F_12 () ;
memcpy ( V_42 , V_2 -> V_46 , V_44 ) ;
if ( V_5 -> V_27 )
memcpy ( V_42 + V_2 -> V_21 - sizeof( V_28 ) ,
& V_41 , sizeof( V_41 ) ) ;
V_20 -> V_5 -> V_12 -> V_47 ( V_20 -> V_5 , V_42 , V_41 ) ;
V_45:
F_5 ( V_42 ) ;
F_13 ( V_20 -> V_48 ) ;
return V_49 ;
}
int F_14 ( struct V_19 * V_20 )
{
int V_7 ;
V_20 -> V_5 = F_15 ( V_20 ) ;
if ( ! V_20 -> V_5 ) {
V_7 = - V_15 ;
goto V_11;
}
V_20 -> V_5 -> V_12 = & V_50 ;
V_20 -> V_51 = F_16 ( & V_52 ,
& F_10 ,
V_53 ,
V_20 ,
L_1 ,
V_20 -> V_54 ) ;
if ( V_20 -> V_51 == NULL ) {
V_7 = - V_15 ;
goto V_55;
}
V_20 -> V_5 -> V_56 = & V_57 ;
V_20 -> V_58 |= V_59 ;
return 0 ;
V_55:
F_17 ( V_20 -> V_5 ) ;
V_11:
return V_7 ;
}
void F_18 ( struct V_19 * V_20 )
{
if ( V_20 -> V_48 ) {
F_19 ( V_20 -> V_48 ) ;
F_20 ( V_20 -> V_48 ,
V_20 -> V_51 ) ;
}
F_21 ( V_20 -> V_51 ) ;
F_17 ( V_20 -> V_5 ) ;
}
