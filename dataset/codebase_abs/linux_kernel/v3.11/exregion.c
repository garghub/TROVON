T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
T_1 V_7 = V_8 ;
void * V_9 = NULL ;
struct V_10 * V_11 = V_6 ;
T_2 V_12 ;
T_5 V_13 ;
T_5 V_14 ;
#ifdef F_2
T_2 V_15 ;
#endif
F_3 ( V_16 ) ;
switch ( V_3 ) {
case 8 :
V_12 = 1 ;
break;
case 16 :
V_12 = 2 ;
break;
case 32 :
V_12 = 4 ;
break;
case 64 :
V_12 = 8 ;
break;
default:
F_4 ( ( V_17 , L_1 ,
V_3 ) ) ;
F_5 ( V_18 ) ;
}
#ifdef F_2
( void ) F_6 ( ( T_4 ) V_2 , V_12 , NULL , & V_15 ) ;
if ( V_15 != 0 ) {
F_5 ( V_19 ) ;
}
#endif
if ( ( V_2 < V_11 -> V_20 ) ||
( ( ( T_4 ) V_2 + V_12 ) > ( ( T_4 )
V_11 -> V_20 +
V_11 -> V_21 ) ) ) {
if ( V_11 -> V_21 ) {
F_7 ( V_11 -> V_22 ,
V_11 -> V_21 ) ;
}
V_13 = ( T_5 )
( ( V_11 -> V_2 + V_11 -> V_12 ) - V_2 ) ;
V_14 =
F_8 ( V_2 , V_23 ) - V_2 ;
if ( V_14 == 0 ) {
V_14 = V_23 ;
}
if ( V_13 > V_14 ) {
V_13 = V_14 ;
}
V_11 -> V_22 = F_9 ( ( T_3 ) V_2 , V_13 ) ;
if ( ! V_11 -> V_22 ) {
F_4 ( ( V_17 ,
L_2 ,
F_10 ( V_2 ) ,
( T_2 ) V_13 ) ) ;
V_11 -> V_21 = 0 ;
F_5 ( V_24 ) ;
}
V_11 -> V_20 = V_2 ;
V_11 -> V_21 = V_13 ;
}
V_9 = V_11 -> V_22 +
( ( T_4 ) V_2 - ( T_4 ) V_11 -> V_20 ) ;
F_11 ( ( V_25 ,
L_3 ,
V_3 , V_1 ,
F_10 ( V_2 ) ) ) ;
switch ( V_1 ) {
case V_26 :
* V_4 = 0 ;
switch ( V_3 ) {
case 8 :
* V_4 = ( T_4 ) F_12 ( V_9 ) ;
break;
case 16 :
* V_4 = ( T_4 ) F_13 ( V_9 ) ;
break;
case 32 :
* V_4 = ( T_4 ) F_14 ( V_9 ) ;
break;
case 64 :
* V_4 = ( T_4 ) F_15 ( V_9 ) ;
break;
default:
break;
}
break;
case V_27 :
switch ( V_3 ) {
case 8 :
F_16 ( V_9 , * V_4 ) ;
break;
case 16 :
F_17 ( V_9 , * V_4 ) ;
break;
case 32 :
F_18 ( V_9 , * V_4 ) ;
break;
case 64 :
F_19 ( V_9 , * V_4 ) ;
break;
default:
break;
}
break;
default:
V_7 = V_28 ;
break;
}
F_5 ( V_7 ) ;
}
T_1
F_20 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
T_1 V_7 = V_8 ;
T_2 V_29 ;
F_3 ( V_30 ) ;
F_11 ( ( V_25 ,
L_4 ,
V_3 , V_1 ,
F_10 ( V_2 ) ) ) ;
switch ( V_1 ) {
case V_26 :
V_7 = F_21 ( ( V_31 ) V_2 ,
& V_29 , V_3 ) ;
* V_4 = V_29 ;
break;
case V_27 :
V_7 = F_22 ( ( V_31 ) V_2 ,
( T_2 ) * V_4 , V_3 ) ;
break;
default:
V_7 = V_28 ;
break;
}
F_5 ( V_7 ) ;
}
T_1
F_23 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
T_1 V_7 = V_8 ;
struct V_32 * V_33 ;
T_6 V_34 ;
F_3 ( V_35 ) ;
V_33 = (struct V_32 * ) V_6 ;
V_34 = ( T_6 ) ( T_2 ) V_2 ;
F_11 ( ( V_25 ,
L_5 ,
V_1 , V_3 , V_33 -> V_36 , V_33 -> V_37 ,
V_33 -> V_38 , V_33 -> V_1 , V_34 ) ) ;
switch ( V_1 ) {
case V_26 :
V_7 = F_24 ( V_33 , V_34 ,
V_4 , V_3 ) ;
break;
case V_27 :
V_7 = F_25 ( V_33 , V_34 ,
* V_4 , V_3 ) ;
break;
default:
V_7 = V_28 ;
break;
}
F_5 ( V_7 ) ;
}
T_1
F_26 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
T_1 V_7 = V_8 ;
F_3 ( V_39 ) ;
F_5 ( V_7 ) ;
}
T_1
F_27 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
T_1 V_7 = V_8 ;
F_3 ( V_40 ) ;
F_5 ( V_7 ) ;
}
T_1
F_28 ( T_2 V_1 ,
T_3 V_2 ,
T_2 V_3 ,
T_4 * V_4 ,
void * V_5 , void * V_6 )
{
F_3 ( V_41 ) ;
switch ( V_1 ) {
case V_26 :
F_29 ( F_30 ( char , V_4 ) ,
F_31 ( V_2 ) ,
F_32 ( V_3 ) ) ;
break;
case V_27 :
F_29 ( F_31 ( V_2 ) ,
F_30 ( char , V_4 ) , F_32 ( V_3 ) ) ;
break;
default:
F_5 ( V_28 ) ;
}
F_5 ( V_8 ) ;
}
