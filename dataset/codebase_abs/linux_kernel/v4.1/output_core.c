static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
T_1 V_6 , V_7 ;
V_6 = F_2 ( V_4 , V_2 ) ;
V_6 = F_2 ( V_5 , V_6 ) ;
V_6 ^= F_3 ( V_1 ) ;
V_7 = F_4 ( V_6 , 1 ) ;
if ( F_5 ( ! V_7 ) )
V_7 = 1 << 31 ;
return V_7 ;
}
void F_6 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
static T_1 T_2 V_10 ;
struct V_3 V_11 [ 2 ] ;
struct V_3 * V_12 ;
T_1 V_7 ;
V_12 = F_7 ( V_9 ,
F_8 ( V_9 ) +
F_9 ( struct V_13 , V_14 ) ,
sizeof( V_11 ) , V_11 ) ;
if ( ! V_12 )
return;
F_10 ( & T_2 ,
sizeof( T_2 ) ) ;
V_7 = F_1 ( V_1 , T_2 ,
& V_12 [ 1 ] , & V_12 [ 0 ] ) ;
F_11 ( V_9 ) -> V_15 = F_12 ( V_7 ) ;
}
void F_13 ( struct V_1 * V_1 , struct V_16 * V_17 ,
struct V_18 * V_19 )
{
static T_1 T_3 V_10 ;
T_1 V_7 ;
F_10 ( & T_3 , sizeof( T_3 ) ) ;
V_7 = F_1 ( V_1 , T_3 , & V_19 -> V_20 . V_21 ,
& V_19 -> V_22 . V_21 ) ;
V_17 -> V_23 = F_12 ( V_7 ) ;
}
int F_14 ( struct V_8 * V_9 , T_4 * * V_24 )
{
T_5 V_25 = sizeof( struct V_13 ) ;
struct V_26 * V_27 =
(struct V_26 * ) ( F_15 ( V_9 ) + 1 ) ;
unsigned int V_28 = F_16 ( V_9 ) -
F_17 ( V_9 ) ;
int V_29 = 0 ;
* V_24 = & F_15 ( V_9 ) -> V_24 ;
while ( V_25 + 1 <= V_28 ) {
switch ( * * V_24 ) {
case V_30 :
break;
case V_31 :
V_29 = 1 ;
break;
case V_32 :
#if F_18 ( V_33 )
if ( F_19 ( V_9 , V_25 , V_34 ) >= 0 )
break;
#endif
if ( V_29 )
return V_25 ;
break;
default:
return V_25 ;
}
V_25 += F_20 ( V_27 ) ;
* V_24 = & V_27 -> V_24 ;
V_27 = (struct V_26 * ) ( F_17 ( V_9 ) +
V_25 ) ;
}
return V_25 ;
}
int F_21 ( struct V_35 * V_4 )
{
int V_36 = F_22 ( V_4 , V_37 ) ;
if ( V_36 == 0 ) {
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_40 * V_41 ;
F_23 () ;
V_41 = F_24 ( V_39 ) ;
if ( V_41 )
V_36 = V_41 -> V_42 . V_43 ;
else
V_36 = F_25 ( V_39 ) -> V_44 . V_45 -> V_43 ;
F_26 () ;
}
return V_36 ;
}
static int F_27 ( struct V_46 * V_47 , struct V_8 * V_9 )
{
int V_48 ;
V_48 = V_9 -> V_48 - sizeof( struct V_13 ) ;
if ( V_48 > V_49 )
V_48 = 0 ;
F_15 ( V_9 ) -> V_50 = F_28 ( V_48 ) ;
F_29 ( V_9 ) -> V_51 = F_9 ( struct V_13 , V_24 ) ;
return F_30 ( V_52 , V_53 , V_47 , V_9 ,
NULL , F_31 ( V_9 ) -> V_39 , V_54 ) ;
}
int F_32 ( struct V_8 * V_9 )
{
return F_27 ( V_9 -> V_47 , V_9 ) ;
}
int F_33 ( struct V_46 * V_47 , struct V_8 * V_9 )
{
int V_55 ;
V_55 = F_27 ( V_47 , V_9 ) ;
if ( F_34 ( V_55 == 1 ) )
V_55 = V_54 ( V_47 , V_9 ) ;
return V_55 ;
}
int F_35 ( struct V_8 * V_9 )
{
return F_33 ( V_9 -> V_47 , V_9 ) ;
}
