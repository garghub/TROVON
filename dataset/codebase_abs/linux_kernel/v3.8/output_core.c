void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static T_1 V_5 ;
int V_6 , V_7 ;
#if F_2 ( V_8 )
if ( V_4 && ! ( V_4 -> V_9 . V_10 & V_11 ) ) {
struct V_12 * V_13 ;
struct V_14 * V_14 ;
V_14 = F_3 ( V_4 -> V_9 . V_15 ) ;
V_13 = F_4 ( V_14 -> V_16 . V_17 , & V_4 -> V_18 . V_19 , 1 ) ;
if ( V_13 ) {
V_2 -> V_20 = F_5 ( F_6 ( V_13 , 0 ) ) ;
F_7 ( V_13 ) ;
return;
}
}
#endif
do {
V_6 = F_8 ( & V_5 ) ;
V_7 = V_6 + 1 ;
if ( ! V_7 )
V_7 = 1 ;
} while ( F_9 ( & V_5 , V_6 , V_7 ) != V_6 );
V_2 -> V_20 = F_5 ( V_7 ) ;
}
int F_10 ( struct V_21 * V_22 , T_2 * * V_23 )
{
T_3 V_24 = sizeof( struct V_25 ) ;
struct V_26 * V_27 =
(struct V_26 * ) ( F_11 ( V_22 ) + 1 ) ;
unsigned int V_28 = V_22 -> V_29 - V_22 -> V_30 ;
int V_31 = 0 ;
* V_23 = & F_11 ( V_22 ) -> V_23 ;
while ( V_24 + 1 <= V_28 ) {
switch ( * * V_23 ) {
case V_32 :
break;
case V_33 :
V_31 = 1 ;
break;
case V_34 :
#if F_2 ( V_35 )
if ( F_12 ( V_22 , V_24 , V_36 ) >= 0 )
break;
#endif
if ( V_31 )
return V_24 ;
break;
default :
return V_24 ;
}
V_24 += F_13 ( V_27 ) ;
* V_23 = & V_27 -> V_23 ;
V_27 = (struct V_26 * ) ( F_14 ( V_22 ) +
V_24 ) ;
}
return V_24 ;
}
