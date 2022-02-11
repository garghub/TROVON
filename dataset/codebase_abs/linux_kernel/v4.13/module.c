int F_1 ( T_1 * V_1 ,
const char * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned int V_7 ;
T_2 * V_8 = ( void * ) V_1 [ V_4 ] . V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
F_2 ( L_1 , V_4 ,
V_1 [ V_4 ] . V_12 ) ;
for ( V_7 = 0 ; V_7 < V_1 [ V_4 ] . V_13 / sizeof( * V_8 ) ; V_7 ++ ) {
V_11 = ( void * ) V_1 [ V_1 [ V_4 ] . V_12 ] . V_9
+ V_8 [ V_7 ] . V_14 ;
V_10 = ( T_3 * ) V_1 [ V_3 ] . V_9
+ F_3 ( V_8 [ V_7 ] . V_15 ) ;
switch ( F_4 ( V_8 [ V_7 ] . V_15 ) ) {
case V_16 :
* V_11 += V_10 -> V_17 ;
break;
case V_18 :
* V_11 += V_10 -> V_17 - ( T_4 ) V_11 ;
break;
default:
F_5 ( L_2 , V_6 -> V_19 ,
F_4 ( V_8 [ V_7 ] . V_15 ) ) ;
return - V_20 ;
}
}
return 0 ;
}
int F_6 ( T_1 * V_1 ,
const char * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned int V_7 ;
T_5 * V_8 = ( void * ) V_1 [ V_4 ] . V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
F_2 ( L_3 , V_4 ,
V_1 [ V_4 ] . V_12 ) ;
for ( V_7 = 0 ; V_7 < V_1 [ V_4 ] . V_13 / sizeof( * V_8 ) ; V_7 ++ ) {
V_11 = ( void * ) V_1 [ V_1 [ V_4 ] . V_12 ] . V_9
+ V_8 [ V_7 ] . V_14 ;
V_10 = ( T_3 * ) V_1 [ V_3 ] . V_9
+ F_3 ( V_8 [ V_7 ] . V_15 ) ;
switch ( F_4 ( V_8 [ V_7 ] . V_15 ) ) {
case V_16 :
* V_11 = V_8 [ V_7 ] . V_21 + V_10 -> V_17 ;
break;
case V_18 :
* V_11 = V_8 [ V_7 ] . V_21 + V_10 -> V_17 - ( T_4 ) V_11 ;
break;
default:
F_5 ( L_2 , V_6 -> V_19 ,
F_4 ( V_8 [ V_7 ] . V_15 ) ) ;
return - V_20 ;
}
}
return 0 ;
}
int F_7 ( const T_6 * V_22 ,
const T_7 * V_1 ,
struct V_5 * V_23 )
{
F_8 ( V_23 , V_23 -> V_24 . V_25 , V_23 -> V_24 . V_26 ) ;
return 0 ;
}
void F_8 ( struct V_5 * V_23 , struct V_27 * V_28 ,
struct V_27 * V_29 )
{
#ifdef F_9
struct V_27 * V_30 ;
for ( V_30 = V_28 ; V_30 < V_29 ; V_30 ++ ) {
switch ( V_30 -> type ) {
case V_31 :
* ( V_32 * ) V_30 -> V_33 = V_34 ;
break;
case V_35 :
* ( V_36 * ) V_30 -> V_33 += V_37 ;
break;
}
}
#endif
}
