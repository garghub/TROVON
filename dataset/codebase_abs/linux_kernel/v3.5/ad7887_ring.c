static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( * V_2 -> V_6 ) {
case ( 1 << 0 ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_9 ] ;
break;
case ( 1 << 1 ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_10 ] ;
F_4 ( V_4 -> V_11 , V_4 -> V_7 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_12 ] ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_11 , & V_4 -> V_8 [ V_9 ] ) ;
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_17 ;
T_3 * V_18 ;
int V_19 ;
unsigned int V_20 = F_7 ( V_2 -> V_6 ,
V_2 -> V_21 ) *
V_4 -> V_22 -> V_23 [ 0 ] . V_24 . V_25 / 8 ;
V_18 = F_8 ( V_2 -> V_26 , V_27 ) ;
if ( V_18 == NULL )
return - V_28 ;
V_19 = F_4 ( V_4 -> V_11 , V_4 -> V_7 ) ;
if ( V_19 )
goto V_29;
V_17 = F_9 () ;
memcpy ( V_18 , V_4 -> V_30 , V_20 ) ;
if ( V_2 -> V_31 )
memcpy ( V_18 + V_2 -> V_26 - sizeof( T_2 ) ,
& V_17 , sizeof( V_17 ) ) ;
V_2 -> V_32 -> V_33 -> V_34 ( V_2 -> V_32 , V_18 , V_17 ) ;
V_29:
F_10 ( V_18 ) ;
F_11 ( V_2 -> V_35 ) ;
return V_36 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_32 = F_13 ( V_2 ) ;
if ( ! V_2 -> V_32 ) {
V_5 = - V_28 ;
goto V_37;
}
V_2 -> V_38 = F_14 ( & V_39 ,
& F_6 ,
V_40 ,
V_2 ,
L_1 ,
V_2 -> V_41 ) ;
if ( V_2 -> V_38 == NULL ) {
V_5 = - V_28 ;
goto V_42;
}
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 |= V_46 ;
return 0 ;
V_42:
F_15 ( V_2 -> V_32 ) ;
V_37:
return V_5 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_38 ) ;
F_15 ( V_2 -> V_32 ) ;
}
