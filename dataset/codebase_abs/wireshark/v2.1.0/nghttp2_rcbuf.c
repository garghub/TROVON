int F_1 ( T_1 * * V_1 , T_2 V_2 ,
T_3 * V_3 ) {
T_4 * V_4 ;
V_4 = ( T_4 * ) F_2 ( V_3 , sizeof( T_1 ) + V_2 ) ;
if ( V_4 == NULL ) {
return V_5 ;
}
* V_1 = ( T_1 * ) ( void * ) V_4 ;
( * V_1 ) -> V_6 = V_3 -> V_6 ;
( * V_1 ) -> free = V_3 -> free ;
( * V_1 ) -> V_7 = V_4 + sizeof( T_1 ) ;
( * V_1 ) -> V_8 = V_2 ;
( * V_1 ) -> V_9 = 1 ;
return 0 ;
}
int F_3 ( T_1 * * V_1 , const T_4 * V_10 ,
T_2 V_11 , T_3 * V_3 ) {
int V_12 ;
V_12 = F_1 ( V_1 , V_11 + 1 , V_3 ) ;
if ( V_12 != 0 ) {
return V_12 ;
}
memcpy ( ( * V_1 ) -> V_7 , V_10 , V_11 ) ;
( * V_1 ) -> V_8 = V_11 ;
( * V_1 ) -> V_7 [ V_11 ] = '\0' ;
return 0 ;
}
void F_4 ( T_1 * V_13 ) {
F_5 ( V_13 -> free , V_13 , V_13 -> V_6 ) ;
}
void F_6 ( T_1 * V_13 ) {
if ( V_13 -> V_9 == - 1 ) {
return;
}
++ V_13 -> V_9 ;
}
void F_7 ( T_1 * V_13 ) {
if ( V_13 == NULL || V_13 -> V_9 == - 1 ) {
return;
}
assert ( V_13 -> V_9 > 0 ) ;
if ( -- V_13 -> V_9 == 0 ) {
F_4 ( V_13 ) ;
}
}
T_5 F_8 ( T_1 * V_13 ) {
T_5 V_14 = { V_13 -> V_7 , V_13 -> V_8 } ;
return V_14 ;
}
