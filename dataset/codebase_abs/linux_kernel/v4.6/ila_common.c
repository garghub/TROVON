static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( * ( V_5 * ) & V_2 -> V_6 == V_4 -> V_7 )
return V_4 -> V_8 ;
else
return F_2 ( ( V_9 * ) & V_2 -> V_6 ,
( V_9 * ) & V_4 -> V_10 ) ;
}
void F_3 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
T_1 V_13 ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
T_2 V_14 = sizeof( struct V_1 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
if ( F_5 ( F_6 ( V_12 , V_14 + sizeof( struct V_17 ) ) ) ) {
struct V_17 * V_18 = (struct V_17 * )
( F_7 ( V_12 ) + V_14 ) ;
V_13 = F_1 ( V_2 , V_4 ) ;
F_8 ( & V_18 -> V_19 , V_12 ,
V_13 , true ) ;
}
break;
case V_20 :
if ( F_5 ( F_6 ( V_12 , V_14 + sizeof( struct V_21 ) ) ) ) {
struct V_21 * V_22 = (struct V_21 * )
( F_7 ( V_12 ) + V_14 ) ;
if ( V_22 -> V_19 || V_12 -> V_23 == V_24 ) {
V_13 = F_1 ( V_2 , V_4 ) ;
F_8 ( & V_22 -> V_19 , V_12 ,
V_13 , true ) ;
if ( ! V_22 -> V_19 )
V_22 -> V_19 = V_25 ;
}
}
break;
case V_26 :
if ( F_5 ( F_6 ( V_12 ,
V_14 + sizeof( struct V_27 ) ) ) ) {
struct V_27 * V_28 = (struct V_27 * )
( F_7 ( V_12 ) + V_14 ) ;
V_13 = F_1 ( V_2 , V_4 ) ;
F_8 ( & V_28 -> V_29 , V_12 ,
V_13 , true ) ;
}
break;
}
* ( V_5 * ) & V_2 -> V_6 = V_4 -> V_10 ;
}
static int T_3 F_9 ( void )
{
int V_30 ;
V_30 = F_10 () ;
if ( V_30 )
goto V_31;
V_30 = F_11 () ;
if ( V_30 )
goto V_32;
return 0 ;
V_32:
F_12 () ;
V_31:
return V_30 ;
}
static void T_4 F_13 ( void )
{
F_14 () ;
F_12 () ;
}
