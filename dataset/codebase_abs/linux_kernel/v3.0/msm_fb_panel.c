int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_1 * V_7 ;
V_5 = (struct V_4 * ) V_2 -> V_8 . V_9 ;
if ( V_5 ) {
V_7 = V_5 -> V_10 ;
if ( V_7 ) {
V_6 =
(struct V_4 * ) V_7 -> V_8 .
V_9 ;
if ( ( V_6 ) && ( V_6 -> V_11 ) )
V_3 = V_6 -> V_11 ( V_7 ) ;
}
}
return V_3 ;
}
int F_2 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_1 * V_7 ;
V_5 = (struct V_4 * ) V_2 -> V_8 . V_9 ;
if ( V_5 ) {
V_7 = V_5 -> V_10 ;
if ( V_7 ) {
V_6 =
(struct V_4 * ) V_7 -> V_8 .
V_9 ;
if ( ( V_6 ) && ( V_6 -> V_11 ) )
V_3 = V_6 -> V_12 ( V_7 ) ;
}
}
return V_3 ;
}
struct V_1 * F_3 ( struct V_4 * V_5 ,
T_1 type , T_1 V_13 )
{
struct V_1 * V_14 = NULL ;
char V_15 [ 16 ] ;
switch ( type ) {
case V_16 :
snprintf ( V_15 , sizeof( V_15 ) , L_1 ) ;
break;
case V_17 :
snprintf ( V_15 , sizeof( V_15 ) , L_2 ) ;
break;
case V_18 :
snprintf ( V_15 , sizeof( V_15 ) , L_3 ) ;
break;
case V_19 :
snprintf ( V_15 , sizeof( V_15 ) , L_4 ) ;
break;
case V_20 :
case V_21 :
snprintf ( V_15 , sizeof( V_15 ) , L_5 ) ;
break;
default:
return NULL ;
}
if ( V_5 != NULL )
V_5 -> V_10 = NULL ;
else
return NULL ;
V_14 =
F_4 ( V_15 , ( ( T_1 ) type << 16 ) | ( T_1 ) V_13 ) ;
if ( V_14 ) {
if ( F_5
( V_14 , V_5 , sizeof( struct V_4 ) ) ) {
F_6
( L_6 ) ;
F_7 ( V_14 ) ;
return NULL ;
}
}
return V_14 ;
}
