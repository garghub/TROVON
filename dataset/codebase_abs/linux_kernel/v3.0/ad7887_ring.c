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
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_4 * V_5 = V_20 -> V_5 ;
V_2 -> V_22 = V_5 -> V_23 *
V_2 -> V_24 -> V_25 [ 0 ] . V_26 . V_27 / 8 ;
if ( V_5 -> V_28 ) {
V_2 -> V_22 += sizeof( V_29 ) ;
if ( V_2 -> V_22 % sizeof( V_29 ) )
V_2 -> V_22 += sizeof( V_29 ) - ( V_2 -> V_22 % sizeof( V_29 ) ) ;
}
if ( V_20 -> V_5 -> V_12 -> V_30 )
V_20 -> V_5 -> V_12 -> V_30 ( V_20 -> V_5 ,
V_2 -> V_22 ) ;
switch ( V_5 -> V_9 ) {
case ( 1 << 0 ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_33 ] ;
break;
case ( 1 << 1 ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_34 ] ;
F_7 ( V_2 -> V_35 , V_2 -> V_31 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_36 ] ;
break;
}
return 0 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
return F_7 ( V_2 -> V_35 , & V_2 -> V_32 [ V_33 ] ) ;
}
static T_2 F_9 ( int V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_19 * V_20 = V_40 -> V_41 ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
V_29 V_42 ;
T_3 * V_43 ;
int V_44 ;
unsigned int V_45 = V_5 -> V_23 *
V_2 -> V_24 -> V_25 [ 0 ] . V_26 . V_27 / 8 ;
V_43 = F_11 ( V_2 -> V_22 , V_14 ) ;
if ( V_43 == NULL )
return - V_15 ;
V_44 = F_7 ( V_2 -> V_35 , V_2 -> V_31 ) ;
if ( V_44 )
goto V_46;
V_42 = F_12 () ;
memcpy ( V_43 , V_2 -> V_47 , V_45 ) ;
if ( V_5 -> V_28 )
memcpy ( V_43 + V_2 -> V_22 - sizeof( V_29 ) ,
& V_42 , sizeof( V_42 ) ) ;
V_20 -> V_5 -> V_12 -> V_48 ( V_20 -> V_5 , V_43 , V_42 ) ;
V_46:
F_5 ( V_43 ) ;
F_13 ( V_20 -> V_49 ) ;
return V_50 ;
}
int F_14 ( struct V_19 * V_20 )
{
int V_7 ;
V_20 -> V_5 = F_15 ( V_20 ) ;
if ( ! V_20 -> V_5 ) {
V_7 = - V_15 ;
goto V_11;
}
V_20 -> V_5 -> V_12 = & V_51 ;
V_20 -> V_52 = F_16 ( & V_53 ,
& F_9 ,
V_54 ,
V_20 ,
L_1 ,
V_20 -> V_55 ) ;
if ( V_20 -> V_52 == NULL ) {
V_7 = - V_15 ;
goto V_56;
}
V_20 -> V_5 -> V_57 = & V_58 ;
V_20 -> V_59 |= V_60 ;
return 0 ;
V_56:
F_17 ( V_20 -> V_5 ) ;
V_11:
return V_7 ;
}
void F_18 ( struct V_19 * V_20 )
{
if ( V_20 -> V_49 ) {
F_19 ( V_20 -> V_49 ) ;
F_20 ( V_20 -> V_49 ,
V_20 -> V_52 ) ;
}
F_21 ( V_20 -> V_52 ) ;
F_17 ( V_20 -> V_5 ) ;
}
