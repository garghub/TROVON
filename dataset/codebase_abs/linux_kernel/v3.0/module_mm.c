void * F_1 ( unsigned long V_1 )
{
if ( V_1 == 0 )
return NULL ;
return F_2 ( V_1 ) ;
}
void F_3 ( struct V_2 * V_3 , void * V_4 )
{
F_4 ( V_4 ) ;
}
int F_5 ( T_1 * V_5 ,
T_2 * V_6 ,
char * V_7 ,
struct V_2 * V_3 )
{
return 0 ;
}
int F_6 ( T_3 * V_6 ,
const char * V_8 ,
unsigned int V_9 ,
unsigned int V_10 ,
struct V_2 * V_11 )
{
unsigned int V_12 ;
T_4 * V_13 = ( void * ) V_6 [ V_10 ] . V_14 ;
T_5 * V_15 ;
T_6 * V_16 ;
F_7 ( L_1 , V_10 ,
V_6 [ V_10 ] . V_17 ) ;
for ( V_12 = 0 ; V_12 < V_6 [ V_10 ] . V_18 / sizeof( * V_13 ) ; V_12 ++ ) {
V_16 = ( void * ) V_6 [ V_6 [ V_10 ] . V_17 ] . V_14
+ V_13 [ V_12 ] . V_19 ;
V_15 = ( T_5 * ) V_6 [ V_9 ] . V_14
+ F_8 ( V_13 [ V_12 ] . V_20 ) ;
switch ( F_9 ( V_13 [ V_12 ] . V_20 ) ) {
case V_21 :
* V_16 += V_15 -> V_22 ;
break;
case V_23 :
* V_16 += V_15 -> V_22 - ( T_6 ) V_16 ;
break;
default:
F_10 ( V_24 L_2 ,
V_11 -> V_25 , F_9 ( V_13 [ V_12 ] . V_20 ) ) ;
return - V_26 ;
}
}
return 0 ;
}
int F_11 ( T_3 * V_6 ,
const char * V_8 ,
unsigned int V_9 ,
unsigned int V_10 ,
struct V_2 * V_11 )
{
unsigned int V_12 ;
T_7 * V_13 = ( void * ) V_6 [ V_10 ] . V_14 ;
T_5 * V_15 ;
T_6 * V_16 ;
F_7 ( L_3 , V_10 ,
V_6 [ V_10 ] . V_17 ) ;
for ( V_12 = 0 ; V_12 < V_6 [ V_10 ] . V_18 / sizeof( * V_13 ) ; V_12 ++ ) {
V_16 = ( void * ) V_6 [ V_6 [ V_10 ] . V_17 ] . V_14
+ V_13 [ V_12 ] . V_19 ;
V_15 = ( T_5 * ) V_6 [ V_9 ] . V_14
+ F_8 ( V_13 [ V_12 ] . V_20 ) ;
switch ( F_9 ( V_13 [ V_12 ] . V_20 ) ) {
case V_21 :
* V_16 = V_13 [ V_12 ] . V_27 + V_15 -> V_22 ;
break;
case V_23 :
* V_16 = V_13 [ V_12 ] . V_27 + V_15 -> V_22 - ( T_6 ) V_16 ;
break;
default:
F_10 ( V_24 L_2 ,
V_11 -> V_25 , F_9 ( V_13 [ V_12 ] . V_20 ) ) ;
return - V_26 ;
}
}
return 0 ;
}
int F_12 ( const T_1 * V_5 ,
const T_2 * V_6 ,
struct V_2 * V_3 )
{
F_13 ( V_3 , V_3 -> V_28 . V_29 , V_3 -> V_28 . V_30 ) ;
return 0 ;
}
void F_14 ( struct V_2 * V_3 )
{
}
void F_13 ( struct V_2 * V_3 , struct V_31 * V_32 ,
struct V_31 * V_33 )
{
struct V_31 * V_34 ;
for ( V_34 = V_32 ; V_34 < V_33 ; V_34 ++ ) {
switch ( V_34 -> type ) {
case V_35 :
* ( V_36 * ) V_34 -> V_37 = V_38 ;
break;
case V_39 :
* ( V_40 * ) V_34 -> V_37 += V_41 ;
break;
}
}
}
