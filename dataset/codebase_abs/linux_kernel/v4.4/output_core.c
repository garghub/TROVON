static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
const struct V_3 * V_5 )
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
T_3 F_13 ( struct V_1 * V_1 ,
const struct V_3 * V_16 ,
const struct V_3 * V_14 )
{
static T_1 T_4 V_10 ;
T_1 V_7 ;
F_10 ( & T_4 , sizeof( T_4 ) ) ;
V_7 = F_1 ( V_1 , T_4 , V_16 , V_14 ) ;
return F_12 ( V_7 ) ;
}
int F_14 ( struct V_8 * V_9 , T_5 * * V_17 )
{
T_6 V_18 = sizeof( struct V_13 ) ;
struct V_19 * V_20 =
(struct V_19 * ) ( F_15 ( V_9 ) + 1 ) ;
unsigned int V_21 = F_16 ( V_9 ) -
F_17 ( V_9 ) ;
int V_22 = 0 ;
* V_17 = & F_15 ( V_9 ) -> V_17 ;
while ( V_18 + 1 <= V_21 ) {
switch ( * * V_17 ) {
case V_23 :
break;
case V_24 :
V_22 = 1 ;
break;
case V_25 :
#if F_18 ( V_26 )
if ( F_19 ( V_9 , V_18 , V_27 ) >= 0 )
break;
#endif
if ( V_22 )
return V_18 ;
break;
default:
return V_18 ;
}
V_18 += F_20 ( V_20 ) ;
* V_17 = & V_20 -> V_17 ;
V_20 = (struct V_19 * ) ( F_17 ( V_9 ) +
V_18 ) ;
}
return V_18 ;
}
int F_21 ( struct V_28 * V_4 )
{
int V_29 = F_22 ( V_4 , V_30 ) ;
if ( V_29 == 0 ) {
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_33 * V_34 ;
F_23 () ;
V_34 = F_24 ( V_32 ) ;
if ( V_34 )
V_29 = V_34 -> V_35 . V_36 ;
else
V_29 = F_25 ( V_32 ) -> V_37 . V_38 -> V_36 ;
F_26 () ;
}
return V_29 ;
}
int F_27 ( struct V_1 * V_1 , struct V_39 * V_40 , struct V_8 * V_9 )
{
int V_41 ;
V_41 = V_9 -> V_41 - sizeof( struct V_13 ) ;
if ( V_41 > V_42 )
V_41 = 0 ;
F_15 ( V_9 ) -> V_43 = F_28 ( V_41 ) ;
F_29 ( V_9 ) -> V_44 = F_9 ( struct V_13 , V_17 ) ;
return F_30 ( V_45 , V_46 ,
V_1 , V_40 , V_9 , NULL , F_31 ( V_9 ) -> V_32 ,
V_47 ) ;
}
int F_32 ( struct V_1 * V_1 , struct V_39 * V_40 , struct V_8 * V_9 )
{
int V_48 ;
V_48 = F_27 ( V_1 , V_40 , V_9 ) ;
if ( F_33 ( V_48 == 1 ) )
V_48 = V_47 ( V_1 , V_40 , V_9 ) ;
return V_48 ;
}
