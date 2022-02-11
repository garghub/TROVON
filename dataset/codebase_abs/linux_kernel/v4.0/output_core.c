static T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 )
{
T_1 V_5 , V_6 ;
V_5 = F_2 ( V_3 , V_1 ) ;
V_5 = F_2 ( V_4 , V_5 ) ;
V_6 = F_3 ( V_5 , 1 ) ;
if ( F_4 ( ! V_6 ) )
V_6 = 1 << 31 ;
return V_6 ;
}
void F_5 ( struct V_7 * V_8 )
{
static T_1 T_2 V_9 ;
struct V_2 V_10 [ 2 ] ;
struct V_2 * V_11 ;
T_1 V_6 ;
V_11 = F_6 ( V_8 ,
F_7 ( V_8 ) +
F_8 ( struct V_12 , V_13 ) ,
sizeof( V_10 ) , V_10 ) ;
if ( ! V_11 )
return;
F_9 ( & T_2 ,
sizeof( T_2 ) ) ;
V_6 = F_1 ( T_2 ,
& V_11 [ 1 ] , & V_11 [ 0 ] ) ;
F_10 ( V_8 ) -> V_14 = F_11 ( V_6 ) ;
}
void F_12 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
static T_1 T_3 V_9 ;
T_1 V_6 ;
F_9 ( & T_3 , sizeof( T_3 ) ) ;
V_6 = F_1 ( T_3 , & V_18 -> V_19 . V_20 ,
& V_18 -> V_21 . V_20 ) ;
V_16 -> V_22 = F_11 ( V_6 ) ;
}
int F_13 ( struct V_7 * V_8 , T_4 * * V_23 )
{
T_5 V_24 = sizeof( struct V_12 ) ;
struct V_25 * V_26 =
(struct V_25 * ) ( F_14 ( V_8 ) + 1 ) ;
unsigned int V_27 = F_15 ( V_8 ) -
F_16 ( V_8 ) ;
int V_28 = 0 ;
* V_23 = & F_14 ( V_8 ) -> V_23 ;
while ( V_24 + 1 <= V_27 ) {
switch ( * * V_23 ) {
case V_29 :
break;
case V_30 :
V_28 = 1 ;
break;
case V_31 :
#if F_17 ( V_32 )
if ( F_18 ( V_8 , V_24 , V_33 ) >= 0 )
break;
#endif
if ( V_28 )
return V_24 ;
break;
default:
return V_24 ;
}
V_24 += F_19 ( V_26 ) ;
* V_23 = & V_26 -> V_23 ;
V_26 = (struct V_25 * ) ( F_16 ( V_8 ) +
V_24 ) ;
}
return V_24 ;
}
int F_20 ( struct V_34 * V_3 )
{
int V_35 = F_21 ( V_3 , V_36 ) ;
if ( V_35 == 0 ) {
struct V_37 * V_38 = V_3 -> V_38 ;
struct V_39 * V_40 ;
F_22 () ;
V_40 = F_23 ( V_38 ) ;
if ( V_40 )
V_35 = V_40 -> V_41 . V_42 ;
else
V_35 = F_24 ( V_38 ) -> V_43 . V_44 -> V_42 ;
F_25 () ;
}
return V_35 ;
}
int F_26 ( struct V_7 * V_8 )
{
int V_45 ;
V_45 = V_8 -> V_45 - sizeof( struct V_12 ) ;
if ( V_45 > V_46 )
V_45 = 0 ;
F_14 ( V_8 ) -> V_47 = F_27 ( V_45 ) ;
F_28 ( V_8 ) -> V_48 = F_8 ( struct V_12 , V_23 ) ;
return F_29 ( V_49 , V_50 , V_8 , NULL ,
F_30 ( V_8 ) -> V_38 , V_51 ) ;
}
int F_31 ( struct V_7 * V_8 )
{
int V_52 ;
V_52 = F_26 ( V_8 ) ;
if ( F_32 ( V_52 == 1 ) )
V_52 = V_51 ( V_8 ) ;
return V_52 ;
}
