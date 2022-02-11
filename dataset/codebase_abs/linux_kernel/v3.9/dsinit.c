static T_1
F_1 ( T_2 V_1 ,
T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_3 ;
struct V_7 * V_8 =
(struct V_7 * ) V_1 ;
T_4 type ;
T_1 V_9 ;
F_2 () ;
if ( V_8 -> V_10 != V_6 -> V_10 ) {
return ( V_11 ) ;
}
V_6 -> V_12 ++ ;
type = F_3 ( V_1 ) ;
switch ( type ) {
case V_13 :
V_9 = F_4 ( V_1 ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( ( V_14 , V_9 ,
L_1 ,
V_1 ,
F_7 ( V_1 ) ) ) ;
}
V_6 -> V_15 ++ ;
break;
case V_16 :
V_6 -> V_17 ++ ;
break;
case V_18 :
V_6 -> V_19 ++ ;
break;
default:
break;
}
return ( V_11 ) ;
}
T_1
F_8 ( T_3 V_20 ,
struct V_7 * V_21 )
{
T_1 V_9 ;
struct V_5 V_6 ;
struct V_22 * V_23 ;
T_5 V_10 ;
F_9 ( V_24 ) ;
V_9 = F_10 ( V_20 , & V_10 ) ;
if ( F_5 ( V_9 ) ) {
F_11 ( V_9 ) ;
}
F_12 ( ( V_25 ,
L_2 ) ) ;
F_13 ( ( V_26 , L_3 ) ) ;
F_14 ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_10 = V_10 ;
V_6 . V_20 = V_20 ;
V_9 = F_15 ( V_27 ) ;
if ( F_5 ( V_9 ) ) {
F_11 ( V_9 ) ;
}
V_9 =
F_16 ( V_28 , V_21 , V_29 ,
V_30 , F_1 ,
NULL , & V_6 , NULL ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( ( V_14 , V_9 , L_4 ) ) ;
}
( void ) F_17 ( V_27 ) ;
V_9 = F_18 ( V_20 , & V_23 ) ;
if ( F_5 ( V_9 ) ) {
F_11 ( V_9 ) ;
}
F_13 ( ( V_26 ,
L_5 ,
V_23 -> V_31 , V_10 , V_6 . V_12 ,
V_6 . V_19 , V_6 . V_17 ,
V_6 . V_15 ) ) ;
F_12 ( ( V_25 ,
L_6 , V_6 . V_17 ,
V_6 . V_15 ) ) ;
F_11 ( V_11 ) ;
}
