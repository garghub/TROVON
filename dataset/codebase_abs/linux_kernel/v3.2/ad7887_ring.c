int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) -> V_6 ;
int V_7 = 0 , V_8 ;
T_1 * V_9 ;
if ( ! ( F_3 ( V_3 , V_5 -> V_10 ) ) ) {
V_8 = - V_11 ;
goto V_12;
}
V_9 = F_4 ( V_5 -> V_13 -> V_14 ( V_5 ) ,
V_15 ) ;
if ( V_9 == NULL ) {
V_8 = - V_16 ;
goto V_12;
}
V_8 = V_5 -> V_13 -> V_17 ( V_5 , ( V_18 * ) V_9 ) ;
if ( V_8 )
goto V_19;
if ( ( F_3 ( 1 , V_5 -> V_10 ) || F_3 ( 0 , V_5 -> V_10 ) ) &&
( V_3 == 1 ) )
V_7 = 1 ;
V_8 = F_5 ( V_9 [ V_7 ] ) ;
V_19:
F_6 ( V_9 ) ;
V_12:
return V_8 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
struct V_4 * V_5 = V_21 -> V_6 ;
V_2 -> V_22 = V_5 -> V_23 *
V_2 -> V_24 -> V_25 [ 0 ] . V_26 . V_27 / 8 ;
if ( V_5 -> V_28 ) {
V_2 -> V_22 += sizeof( V_29 ) ;
if ( V_2 -> V_22 % sizeof( V_29 ) )
V_2 -> V_22 += sizeof( V_29 ) - ( V_2 -> V_22 % sizeof( V_29 ) ) ;
}
if ( V_21 -> V_6 -> V_13 -> V_30 )
V_21 -> V_6 -> V_13 ->
V_30 ( V_21 -> V_6 , V_2 -> V_22 ) ;
switch ( * V_5 -> V_10 ) {
case ( 1 << 0 ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_33 ] ;
break;
case ( 1 << 1 ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_34 ] ;
F_9 ( V_2 -> V_35 , V_2 -> V_31 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_2 -> V_31 = & V_2 -> V_32 [ V_36 ] ;
break;
}
return 0 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
return F_9 ( V_2 -> V_35 , & V_2 -> V_32 [ V_33 ] ) ;
}
static T_2 F_11 ( int V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_20 * V_21 = V_40 -> V_21 ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
struct V_4 * V_5 = V_21 -> V_6 ;
V_29 V_41 ;
T_3 * V_42 ;
int V_43 ;
unsigned int V_44 = V_5 -> V_23 *
V_2 -> V_24 -> V_25 [ 0 ] . V_26 . V_27 / 8 ;
V_42 = F_12 ( V_2 -> V_22 , V_15 ) ;
if ( V_42 == NULL )
return - V_16 ;
V_43 = F_9 ( V_2 -> V_35 , V_2 -> V_31 ) ;
if ( V_43 )
goto V_45;
V_41 = F_13 () ;
memcpy ( V_42 , V_2 -> V_46 , V_44 ) ;
if ( V_5 -> V_28 )
memcpy ( V_42 + V_2 -> V_22 - sizeof( V_29 ) ,
& V_41 , sizeof( V_41 ) ) ;
V_21 -> V_6 -> V_13 -> V_47 ( V_21 -> V_6 , V_42 , V_41 ) ;
V_45:
F_6 ( V_42 ) ;
F_14 ( V_21 -> V_48 ) ;
return V_49 ;
}
int F_15 ( struct V_20 * V_21 )
{
int V_8 ;
V_21 -> V_6 = F_16 ( V_21 ) ;
if ( ! V_21 -> V_6 ) {
V_8 = - V_16 ;
goto V_12;
}
V_21 -> V_6 -> V_13 = & V_50 ;
V_21 -> V_51 = F_17 ( & V_52 ,
& F_11 ,
V_53 ,
V_21 ,
L_1 ,
V_21 -> V_54 ) ;
if ( V_21 -> V_51 == NULL ) {
V_8 = - V_16 ;
goto V_55;
}
V_21 -> V_6 -> V_56 = & V_57 ;
V_21 -> V_58 |= V_59 ;
return 0 ;
V_55:
F_18 ( V_21 -> V_6 ) ;
V_12:
return V_8 ;
}
void F_19 ( struct V_20 * V_21 )
{
F_20 ( V_21 -> V_51 ) ;
F_18 ( V_21 -> V_6 ) ;
}
