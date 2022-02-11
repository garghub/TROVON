int F_1 ( struct V_1 * V_2 , T_1 * * V_3 )
{
T_2 V_4 = sizeof( struct V_5 ) ;
struct V_6 * V_7 =
(struct V_6 * ) ( F_2 ( V_2 ) + 1 ) ;
unsigned int V_8 = F_3 ( V_2 ) -
F_4 ( V_2 ) ;
int V_9 = 0 ;
* V_3 = & F_2 ( V_2 ) -> V_3 ;
while ( V_4 + 1 <= V_8 ) {
switch ( * * V_3 ) {
case V_10 :
break;
case V_11 :
V_9 = 1 ;
break;
case V_12 :
#if F_5 ( V_13 )
if ( F_6 ( V_2 , V_4 , V_14 ) >= 0 )
break;
#endif
if ( V_9 )
return V_4 ;
break;
default :
return V_4 ;
}
V_4 += F_7 ( V_7 ) ;
* V_3 = & V_7 -> V_3 ;
V_7 = (struct V_6 * ) ( F_4 ( V_2 ) +
V_4 ) ;
}
return V_4 ;
}
int F_8 ( struct V_15 * V_16 )
{
int V_17 = F_9 ( V_16 , V_18 ) ;
if ( V_17 == 0 ) {
struct V_19 * V_20 = V_16 -> V_20 ;
struct V_21 * V_22 ;
F_10 () ;
V_22 = F_11 ( V_20 ) ;
if ( V_22 )
V_17 = V_22 -> V_23 . V_24 ;
else
V_17 = F_12 ( V_20 ) -> V_25 . V_26 -> V_24 ;
F_13 () ;
}
return V_17 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = V_2 -> V_27 - sizeof( struct V_5 ) ;
if ( V_27 > V_28 )
V_27 = 0 ;
F_2 ( V_2 ) -> V_29 = F_15 ( V_27 ) ;
F_16 ( V_2 ) -> V_30 = F_17 ( struct V_5 , V_3 ) ;
return F_18 ( V_31 , V_32 , V_2 , NULL ,
F_19 ( V_2 ) -> V_20 , V_33 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_34 ;
V_34 = F_14 ( V_2 ) ;
if ( F_21 ( V_34 == 1 ) )
V_34 = V_33 ( V_2 ) ;
return V_34 ;
}
