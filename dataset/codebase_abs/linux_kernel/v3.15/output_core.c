void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static T_1 V_5 ;
struct V_6 V_7 ;
int V_8 ;
#if F_2 ( V_9 )
struct V_10 * V_11 ;
struct V_12 * V_12 ;
V_12 = F_3 ( V_4 -> V_13 . V_14 ) ;
V_11 = F_4 ( V_12 -> V_15 . V_16 , & V_4 -> V_17 . V_7 , 1 ) ;
if ( V_11 ) {
V_2 -> V_18 = F_5 ( F_6 ( V_11 , 0 ) ) ;
F_7 ( V_11 ) ;
return;
}
#endif
V_8 = F_8 ( & V_5 ) ;
V_7 = V_4 -> V_17 . V_7 ;
V_7 . V_19 [ 0 ] ^= ( V_20 V_21 ) V_8 ;
V_2 -> V_18 = F_5 ( F_9 ( V_7 . V_19 ) ) ;
}
int F_10 ( struct V_22 * V_23 , T_2 * * V_24 )
{
T_3 V_25 = sizeof( struct V_26 ) ;
struct V_27 * V_28 =
(struct V_27 * ) ( F_11 ( V_23 ) + 1 ) ;
unsigned int V_29 = F_12 ( V_23 ) -
F_13 ( V_23 ) ;
int V_30 = 0 ;
* V_24 = & F_11 ( V_23 ) -> V_24 ;
while ( V_25 + 1 <= V_29 ) {
switch ( * * V_24 ) {
case V_31 :
break;
case V_32 :
V_30 = 1 ;
break;
case V_33 :
#if F_2 ( V_34 )
if ( F_14 ( V_23 , V_25 , V_35 ) >= 0 )
break;
#endif
if ( V_30 )
return V_25 ;
break;
default :
return V_25 ;
}
V_25 += F_15 ( V_28 ) ;
* V_24 = & V_28 -> V_24 ;
V_28 = (struct V_27 * ) ( F_13 ( V_23 ) +
V_25 ) ;
}
return V_25 ;
}
int F_16 ( struct V_36 * V_13 )
{
int V_37 = F_17 ( V_13 , V_38 ) ;
if ( V_37 == 0 ) {
struct V_39 * V_14 = V_13 -> V_14 ;
struct V_40 * V_41 ;
F_18 () ;
V_41 = F_19 ( V_14 ) ;
if ( V_41 )
V_37 = V_41 -> V_42 . V_43 ;
else
V_37 = F_3 ( V_14 ) -> V_15 . V_44 -> V_43 ;
F_20 () ;
}
return V_37 ;
}
int F_21 ( struct V_22 * V_23 )
{
int V_45 ;
V_45 = V_23 -> V_45 - sizeof( struct V_26 ) ;
if ( V_45 > V_46 )
V_45 = 0 ;
F_11 ( V_23 ) -> V_47 = F_22 ( V_45 ) ;
return F_23 ( V_48 , V_49 , V_23 , NULL ,
F_24 ( V_23 ) -> V_14 , V_50 ) ;
}
int F_25 ( struct V_22 * V_23 )
{
int V_51 ;
V_51 = F_21 ( V_23 ) ;
if ( F_26 ( V_51 == 1 ) )
V_51 = V_50 ( V_23 ) ;
return V_51 ;
}
