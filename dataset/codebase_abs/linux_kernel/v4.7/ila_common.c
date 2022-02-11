static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_4 -> V_8 . V_9 )
return V_4 -> V_10 ;
else
return F_3 ( ( V_11 * ) & V_6 -> V_12 ,
( V_11 * ) & V_4 -> V_13 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
T_2 * V_14 = ( V_15 T_2 * ) & V_6 -> V_16 . V_17 [ 3 ] ;
T_1 V_18 , V_19 ;
if ( V_4 -> V_8 . V_9 ) {
V_18 = V_4 -> V_10 ;
} else {
V_18 = F_3 ( ( V_11 * ) V_6 ,
( V_11 * ) & V_4 -> V_13 ) ;
}
V_19 = ( V_15 T_1 ) ( F_5 ( V_6 -> V_16 ) ?
~ V_20 : V_20 ) ;
V_18 = F_6 ( V_18 , V_19 ) ;
* V_14 = ~ F_7 ( F_6 ( V_18 , F_8 ( * V_14 ) ) ) ;
V_6 -> V_16 . V_21 ^= 1 ;
}
static void F_9 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
T_1 V_18 ;
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_3 V_24 = sizeof( struct V_1 ) ;
switch ( V_2 -> V_25 ) {
case V_26 :
if ( F_11 ( F_12 ( V_23 , V_24 + sizeof( struct V_27 ) ) ) ) {
struct V_27 * V_28 = (struct V_27 * )
( F_13 ( V_23 ) + V_24 ) ;
V_18 = F_1 ( V_2 , V_4 ) ;
F_14 ( & V_28 -> V_29 , V_23 ,
V_18 , true ) ;
}
break;
case V_30 :
if ( F_11 ( F_12 ( V_23 , V_24 + sizeof( struct V_31 ) ) ) ) {
struct V_31 * V_32 = (struct V_31 * )
( F_13 ( V_23 ) + V_24 ) ;
if ( V_32 -> V_29 || V_23 -> V_33 == V_34 ) {
V_18 = F_1 ( V_2 , V_4 ) ;
F_14 ( & V_32 -> V_29 , V_23 ,
V_18 , true ) ;
if ( ! V_32 -> V_29 )
V_32 -> V_29 = V_35 ;
}
}
break;
case V_36 :
if ( F_11 ( F_12 ( V_23 ,
V_24 + sizeof( struct V_37 ) ) ) ) {
struct V_37 * V_38 = (struct V_37 * )
( F_13 ( V_23 ) + V_24 ) ;
V_18 = F_1 ( V_2 , V_4 ) ;
F_14 ( & V_38 -> V_39 , V_23 ,
V_18 , true ) ;
}
break;
}
V_6 -> V_12 = V_4 -> V_13 ;
}
void F_15 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( F_5 ( V_6 -> V_16 ) ) {
F_4 ( V_6 , V_4 ) ;
} else {
switch ( V_4 -> V_40 ) {
case V_41 :
F_9 ( V_23 , V_4 ) ;
break;
case V_42 :
F_4 ( V_6 , V_4 ) ;
break;
case V_43 :
break;
}
}
V_6 -> V_12 = V_4 -> V_13 ;
}
void F_16 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 . V_9 )
return;
V_4 -> V_10 = F_3 (
( V_11 * ) & V_4 -> V_8 ,
( V_11 * ) & V_4 -> V_13 ) ;
}
static int T_4 F_17 ( void )
{
int V_44 ;
V_44 = F_18 () ;
if ( V_44 )
goto V_45;
V_44 = F_19 () ;
if ( V_44 )
goto V_46;
return 0 ;
V_46:
F_20 () ;
V_45:
return V_44 ;
}
static void T_5 F_21 ( void )
{
F_22 () ;
F_20 () ;
}
