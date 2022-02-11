const T_1 * F_1 ( const T_1 * V_1 ,
const char * V_2 , int V_3 )
{
const T_1 * V_4 = V_1 ;
bool V_5 = true ;
const T_2 * V_6 ;
if ( V_3 < 0 ) {
V_3 = - V_3 ;
V_5 = false ;
} else {
if ( V_3 && V_2 [ V_3 - 1 ] == '\0' )
V_3 -- ;
}
if ( ! V_4 ) {
V_6 = F_2 ( NULL , F_3 ( V_7 ,
V_8 ,
V_9 ) ) ;
if ( ! V_6 || V_6 -> V_10 < sizeof( T_1 ) )
return NULL ;
V_4 = V_6 -> V_11 ;
}
for (; ; ) {
while ( ! V_4 -> V_12 )
V_4 = ( const T_1 * ) ( ( const char * ) V_4 + 8 ) ;
if ( V_4 -> V_12 == V_13 ) {
V_4 = NULL ;
break;
}
if ( ( V_4 -> V_14 >= V_3 ) &&
( ! V_5 || ( V_4 -> V_14 == V_3 + 1 ) ) &&
( V_4 -> V_12 != V_15 ) ) {
if ( ! strncmp ( V_2 , ( const char * ) V_4 -> String ,
V_3 ) )
break;
}
V_4 = ( const T_1 * ) ( ( const char * ) V_4 + V_4 -> V_10 ) ;
}
return V_4 ;
}
const void * F_4 ( const char * V_2 , int V_16 )
{
const T_1 * V_4 = NULL ;
const void * V_17 = NULL ;
for (; ; ) {
V_4 = F_1 ( V_4 , V_2 , V_16 ) ;
if ( ! V_4 )
break;
if ( V_4 -> V_18 != V_19 ) {
V_17 = ( const char * ) V_4 -> String +
( ( V_4 -> V_14 + 7 ) & ~ 7 ) ;
break;
}
V_4 = ( const T_1 * ) ( ( const char * ) V_4 + V_4 -> V_10 ) ;
}
return V_17 ;
}
