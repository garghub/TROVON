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
unsigned int V_28 = F_12 ( V_22 ) -
F_13 ( V_22 ) ;
int V_29 = 0 ;
* V_23 = & F_11 ( V_22 ) -> V_23 ;
while ( V_24 + 1 <= V_28 ) {
switch ( * * V_23 ) {
case V_30 :
break;
case V_31 :
V_29 = 1 ;
break;
case V_32 :
#if F_2 ( V_33 )
if ( F_14 ( V_22 , V_24 , V_34 ) >= 0 )
break;
#endif
if ( V_29 )
return V_24 ;
break;
default :
return V_24 ;
}
V_24 += F_15 ( V_27 ) ;
* V_23 = & V_27 -> V_23 ;
V_27 = (struct V_26 * ) ( F_13 ( V_22 ) +
V_24 ) ;
}
return V_24 ;
}
int F_16 ( struct V_35 * V_9 )
{
int V_36 = F_17 ( V_9 , V_37 ) ;
if ( V_36 == 0 ) {
struct V_38 * V_15 = V_9 -> V_15 ;
struct V_39 * V_40 ;
F_18 () ;
V_40 = F_19 ( V_15 ) ;
if ( V_40 )
V_36 = V_40 -> V_41 . V_42 ;
else
V_36 = F_3 ( V_15 ) -> V_16 . V_43 -> V_42 ;
F_20 () ;
}
return V_36 ;
}
int F_21 ( struct V_21 * V_22 )
{
int V_44 ;
V_44 = V_22 -> V_44 - sizeof( struct V_25 ) ;
if ( V_44 > V_45 )
V_44 = 0 ;
F_11 ( V_22 ) -> V_46 = F_22 ( V_44 ) ;
return F_23 ( V_47 , V_48 , V_22 , NULL ,
F_24 ( V_22 ) -> V_15 , V_49 ) ;
}
int F_25 ( struct V_21 * V_22 )
{
int V_50 ;
V_50 = F_21 ( V_22 ) ;
if ( F_26 ( V_50 == 1 ) )
V_50 = V_49 ( V_22 ) ;
return V_50 ;
}
