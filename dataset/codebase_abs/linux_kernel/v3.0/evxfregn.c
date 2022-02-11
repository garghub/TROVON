T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
T_4 V_3 ,
T_5 V_4 , void * V_5 )
{
struct V_6 * V_7 ;
T_1 V_8 ;
F_2 ( F_1 ) ;
if ( ! V_1 ) {
F_3 ( V_9 ) ;
}
V_8 = F_4 ( V_10 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_7 = F_6 ( V_1 ) ;
if ( ! V_7 ) {
V_8 = V_9 ;
goto V_11;
}
V_8 =
F_7 ( V_7 , V_2 , V_3 , V_4 ,
V_5 ) ;
if ( F_5 ( V_8 ) ) {
goto V_11;
}
switch ( V_2 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
if ( ! V_16 ) {
goto V_11;
}
break;
default:
break;
}
V_8 = F_8 ( V_7 , V_2 ) ;
V_11:
( void ) F_9 ( V_10 ) ;
F_3 ( V_8 ) ;
}
T_1
F_10 ( T_2 V_1 ,
T_3 V_2 ,
T_4 V_3 )
{
union V_17 * V_18 ;
union V_17 * V_19 ;
union V_17 * V_20 ;
union V_17 * * V_21 ;
struct V_6 * V_7 ;
T_1 V_8 ;
F_2 ( F_10 ) ;
if ( ! V_1 ) {
F_3 ( V_9 ) ;
}
V_8 = F_4 ( V_10 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_7 = F_6 ( V_1 ) ;
if ( ! V_7 ||
( ( V_7 -> type != V_22 ) &&
( V_7 -> type != V_23 ) &&
( V_7 -> type != V_24 ) &&
( V_7 != V_25 ) ) ) {
V_8 = V_9 ;
goto V_11;
}
V_18 = F_11 ( V_7 ) ;
if ( ! V_18 ) {
V_8 = V_26 ;
goto V_11;
}
V_19 = V_18 -> V_1 . V_3 ;
V_21 = & V_18 -> V_1 . V_3 ;
while ( V_19 ) {
if ( V_19 -> V_27 . V_2 == V_2 ) {
if ( V_19 -> V_27 . V_3 != V_3 ) {
V_8 = V_9 ;
goto V_11;
}
F_12 ( ( V_28 ,
L_1
L_2 ,
V_19 , V_3 ,
F_13 ( V_2 ) ,
V_7 , V_18 ) ) ;
V_20 = V_19 -> V_27 . V_29 ;
while ( V_20 ) {
F_14 ( V_20 , TRUE ) ;
V_20 =
V_19 -> V_27 . V_29 ;
}
* V_21 = V_19 -> V_27 . V_30 ;
F_15 ( V_19 ) ;
goto V_11;
}
V_21 = & V_19 -> V_27 . V_30 ;
V_19 = V_19 -> V_27 . V_30 ;
}
F_12 ( ( V_28 ,
L_3 ,
V_3 , F_13 ( V_2 ) , V_2 ,
V_7 , V_18 ) ) ;
V_8 = V_26 ;
V_11:
( void ) F_9 ( V_10 ) ;
F_3 ( V_8 ) ;
}
