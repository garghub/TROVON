static T_1
F_1 ( T_2 V_1 ,
T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_3 ;
struct V_7 * V_8 =
(struct V_7 * ) V_1 ;
T_1 V_9 ;
union V_10 * V_11 ;
F_2 () ;
if ( V_8 -> V_12 != V_6 -> V_12 ) {
return ( V_13 ) ;
}
V_6 -> V_14 ++ ;
switch ( F_3 ( V_1 ) ) {
case V_15 :
V_9 = F_4 ( V_1 ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( ( V_16 , V_9 ,
L_1 ,
V_1 ,
F_7 ( V_1 ) ) ) ;
}
V_6 -> V_17 ++ ;
break;
case V_18 :
V_6 -> V_19 ++ ;
V_11 = F_8 ( V_8 ) ;
if ( ! V_11 ) {
break;
}
if ( V_11 -> V_20 . V_21 & V_22 ) {
V_6 -> V_23 ++ ;
break;
}
if ( V_24 ) {
F_9 ( V_8 , V_11 ) ;
if ( V_11 -> V_20 .
V_21 & V_22 ) {
V_6 -> V_23 ++ ;
V_6 -> V_25 ++ ;
break;
}
}
V_6 -> V_26 ++ ;
break;
case V_27 :
V_6 -> V_28 ++ ;
break;
default:
break;
}
return ( V_13 ) ;
}
T_1
F_10 ( T_3 V_29 ,
struct V_7 * V_30 )
{
T_1 V_9 ;
struct V_5 V_6 ;
struct V_31 * V_32 ;
T_4 V_12 ;
F_11 ( V_33 ) ;
V_9 = F_12 ( V_29 , & V_12 ) ;
if ( F_5 ( V_9 ) ) {
F_13 ( V_9 ) ;
}
F_14 ( ( V_34 ,
L_2 ) ) ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_12 = V_12 ;
V_6 . V_29 = V_29 ;
V_9 = F_15 ( V_35 ) ;
if ( F_5 ( V_9 ) ) {
F_13 ( V_9 ) ;
}
V_9 =
F_16 ( V_36 , V_30 , V_37 ,
V_38 , F_1 ,
NULL , & V_6 , NULL ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( ( V_16 , V_9 , L_3 ) ) ;
}
( void ) F_17 ( V_35 ) ;
V_9 = F_18 ( V_29 , & V_32 ) ;
if ( F_5 ( V_9 ) ) {
F_13 ( V_9 ) ;
}
F_19 ( ( V_39 ,
L_4
L_5 ,
V_32 -> V_40 , V_12 , V_6 . V_14 ,
V_6 . V_28 , V_6 . V_17 ,
V_6 . V_19 , V_6 . V_23 ,
V_6 . V_26 ,
V_6 . V_25 ) ) ;
F_14 ( ( V_34 , L_6 ,
V_6 . V_19 , V_6 . V_17 ) ) ;
F_13 ( V_13 ) ;
}
