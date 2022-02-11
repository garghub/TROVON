void F_1 ( struct V_1 * V_2 )
{
static T_1 T_2 V_3 ;
struct V_4 V_5 [ 2 ] ;
struct V_4 * V_6 ;
T_1 V_7 , V_8 ;
V_6 = F_2 ( V_2 ,
F_3 ( V_2 ) +
F_4 ( struct V_9 , V_10 ) ,
sizeof( V_5 ) , V_5 ) ;
if ( ! V_6 )
return;
F_5 ( & T_2 ,
sizeof( T_2 ) ) ;
V_7 = F_6 ( & V_6 [ 1 ] , T_2 ) ;
V_7 = F_6 ( & V_6 [ 0 ] , V_7 ) ;
V_8 = F_7 ( V_7 , 1 ) ;
F_8 ( V_2 ) -> V_11 = F_9 ( V_8 ) ;
}
int F_10 ( struct V_1 * V_2 , T_3 * * V_12 )
{
T_4 V_13 = sizeof( struct V_9 ) ;
struct V_14 * V_15 =
(struct V_14 * ) ( F_11 ( V_2 ) + 1 ) ;
unsigned int V_16 = F_12 ( V_2 ) -
F_13 ( V_2 ) ;
int V_17 = 0 ;
* V_12 = & F_11 ( V_2 ) -> V_12 ;
while ( V_13 + 1 <= V_16 ) {
switch ( * * V_12 ) {
case V_18 :
break;
case V_19 :
V_17 = 1 ;
break;
case V_20 :
#if F_14 ( V_21 )
if ( F_15 ( V_2 , V_13 , V_22 ) >= 0 )
break;
#endif
if ( V_17 )
return V_13 ;
break;
default:
return V_13 ;
}
V_13 += F_16 ( V_15 ) ;
* V_12 = & V_15 -> V_12 ;
V_15 = (struct V_14 * ) ( F_13 ( V_2 ) +
V_13 ) ;
}
return V_13 ;
}
int F_17 ( struct V_23 * V_24 )
{
int V_25 = F_18 ( V_24 , V_26 ) ;
if ( V_25 == 0 ) {
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_29 * V_30 ;
F_19 () ;
V_30 = F_20 ( V_28 ) ;
if ( V_30 )
V_25 = V_30 -> V_31 . V_32 ;
else
V_25 = F_21 ( V_28 ) -> V_33 . V_34 -> V_32 ;
F_22 () ;
}
return V_25 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = V_2 -> V_35 - sizeof( struct V_9 ) ;
if ( V_35 > V_36 )
V_35 = 0 ;
F_11 ( V_2 ) -> V_37 = F_24 ( V_35 ) ;
F_25 ( V_2 ) -> V_38 = F_4 ( struct V_9 , V_12 ) ;
return F_26 ( V_39 , V_40 , V_2 , NULL ,
F_27 ( V_2 ) -> V_28 , V_41 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_23 ( V_2 ) ;
if ( F_29 ( V_42 == 1 ) )
V_42 = V_41 ( V_2 ) ;
return V_42 ;
}
