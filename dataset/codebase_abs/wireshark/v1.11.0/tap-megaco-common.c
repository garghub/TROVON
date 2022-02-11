static T_1
F_1 ( const T_2 * V_1 )
{
switch ( V_1 -> type ) {
F_2
{
T_3 * V_2 ;
for ( V_2 = V_1 -> V_3 -> V_4 ;
( V_2 != NULL ) && ( V_2 -> V_1 -> V_5 -> V_6 != V_1 -> V_5 -> V_6 ) ;
V_2 = V_2 -> V_7 ) {
if ( V_2 -> V_1 -> type == V_1 -> type )
return TRUE ;
}
return FALSE ;
}
break;
default:
return FALSE ;
break;
}
}
static T_1
F_3 ( const T_2 * V_1 )
{
switch ( V_1 -> type ) {
F_2
{
T_3 * V_2 ;
for ( V_2 = V_1 -> V_3 -> V_4 ;
( V_2 != NULL ) && ( V_2 -> V_1 -> V_5 -> V_6 != V_1 -> V_5 -> V_6 ) ;
V_2 = V_2 -> V_7 ) {
switch ( V_2 -> V_1 -> type ) {
F_4
return TRUE ;
break;
default:
return FALSE ;
break;
}
}
return FALSE ;
}
break;
default:
return FALSE ;
break;
}
}
int
F_5 ( void * V_8 , T_4 * V_9 , T_5 * T_6 V_10 , const void * V_11 )
{
T_7 * V_12 = ( T_7 * ) V_8 ;
const T_2 * V_13 = ( const T_2 * ) V_11 ;
T_8 V_14 ;
int V_15 = 0 ;
switch ( V_13 -> type ) {
F_4
if( ! V_13 -> V_3 -> V_16 ) {
return 0 ;
}
else if( V_13 -> V_3 -> V_16 -> V_6 != V_13 -> V_5 -> V_6 ) {
V_12 -> V_17 ++ ;
}
else {
V_12 -> V_18 ++ ;
}
break;
F_2
if( F_1 ( V_13 ) ) {
V_12 -> V_19 ++ ;
}
else if ( ! F_3 ( V_13 ) ) {
V_12 -> V_20 ++ ;
}
else {
V_12 -> V_18 -- ;
F_6 ( & V_14 , & V_9 -> V_21 -> V_22 , & V_13 -> V_3 -> V_16 -> time ) ;
switch( V_13 -> type ) {
case V_23 :
F_7 ( & ( V_12 -> V_24 [ 0 ] ) , & V_14 , V_9 ) ;
break;
case V_25 :
F_7 ( & ( V_12 -> V_24 [ 1 ] ) , & V_14 , V_9 ) ;
break;
case V_26 :
F_7 ( & ( V_12 -> V_24 [ 2 ] ) , & V_14 , V_9 ) ;
break;
case V_27 :
F_7 ( & ( V_12 -> V_24 [ 3 ] ) , & V_14 , V_9 ) ;
break;
case V_28 :
F_7 ( & ( V_12 -> V_24 [ 4 ] ) , & V_14 , V_9 ) ;
break;
case V_29 :
F_7 ( & ( V_12 -> V_24 [ 5 ] ) , & V_14 , V_9 ) ;
break;
case V_30 :
F_7 ( & ( V_12 -> V_24 [ 6 ] ) , & V_14 , V_9 ) ;
break;
case V_31 :
F_7 ( & ( V_12 -> V_24 [ 7 ] ) , & V_14 , V_9 ) ;
break;
case V_32 :
F_7 ( & ( V_12 -> V_24 [ 8 ] ) , & V_14 , V_9 ) ;
break;
case V_33 :
F_7 ( & ( V_12 -> V_24 [ 9 ] ) , & V_14 , V_9 ) ;
break;
default:
F_7 ( & ( V_12 -> V_24 [ 11 ] ) , & V_14 , V_9 ) ;
}
F_7 ( & ( V_12 -> V_24 [ 10 ] ) , & V_14 , V_9 ) ;
V_15 = 1 ;
}
break;
default:
break;
}
return V_15 ;
}
