T_1 * F_1 ( unsigned char * V_1 , void * V_2 )
{
T_1 * V_3 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
return NULL ;
memcpy ( V_3 -> V_4 , V_1 , sizeof( V_3 -> V_4 ) ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = NULL ;
return V_3 ;
}
void F_3 ( T_1 * V_3 )
{
if ( V_3 == NULL )
return;
F_4 ( V_3 ) ;
}
T_2 * F_5 ()
{
T_2 * V_6 = ( T_2 * ) F_2 ( sizeof( T_2 ) ) ;
if ( V_6 == NULL )
return NULL ;
memset ( V_6 , 0x00 , sizeof( T_2 ) ) ;
return V_6 ;
}
void F_6 ( T_2 * V_6 )
{
if ( V_6 == NULL )
return;
F_4 ( V_6 ) ;
}
T_1 * F_7 ( T_2 * V_6 , T_1 * V_3 )
{
T_1 * V_7 , * V_5 ;
if ( V_6 -> V_8 == NULL ) {
V_6 -> V_8 = V_3 ;
return V_3 ;
}
for ( V_7 = NULL , V_5 = V_6 -> V_8 ;
V_5 != NULL ; V_7 = V_5 , V_5 = V_5 -> V_5 ) {
int V_9 = memcmp ( V_5 -> V_4 , V_3 -> V_4 , 8 ) ;
if ( V_9 > 0 ) {
V_3 -> V_5 = V_5 ;
if ( V_7 == NULL )
V_6 -> V_8 = V_3 ;
else
V_7 -> V_5 = V_3 ;
return V_3 ;
}
else if ( V_9 == 0 )
return NULL ;
}
V_3 -> V_5 = NULL ;
V_7 -> V_5 = V_3 ;
return V_3 ;
}
T_1 * F_8 ( T_2 * V_6 )
{
return V_6 -> V_8 ;
}
T_1 * F_9 ( T_2 * V_6 )
{
T_1 * V_3 = V_6 -> V_8 ;
if ( V_6 -> V_8 != NULL )
V_6 -> V_8 = V_6 -> V_8 -> V_5 ;
return V_3 ;
}
T_1 * F_10 ( T_2 * V_6 , unsigned char * V_1 )
{
T_1 * V_5 ;
T_1 * V_10 = NULL ;
if ( V_6 -> V_8 == NULL )
return NULL ;
for ( V_5 = V_6 -> V_8 ; V_5 -> V_5 != NULL ; V_5 = V_5 -> V_5 ) {
if ( memcmp ( V_5 -> V_4 , V_1 , 8 ) == 0 ) {
V_10 = V_5 ;
break;
}
}
if ( memcmp ( V_5 -> V_4 , V_1 , 8 ) == 0 )
V_10 = V_5 ;
if ( ! V_10 )
return NULL ;
#if 0
if (prev == NULL)
pq->items = next->next;
else
prev->next = next->next;
#endif
return V_10 ;
}
void F_11 ( T_2 * V_6 )
{
T_1 * V_3 = V_6 -> V_8 ;
while ( V_3 != NULL ) {
printf ( L_1 ,
V_3 -> V_4 [ 0 ] , V_3 -> V_4 [ 1 ] ,
V_3 -> V_4 [ 2 ] , V_3 -> V_4 [ 3 ] ,
V_3 -> V_4 [ 4 ] , V_3 -> V_4 [ 5 ] ,
V_3 -> V_4 [ 6 ] , V_3 -> V_4 [ 7 ] ) ;
V_3 = V_3 -> V_5 ;
}
}
T_1 * F_12 ( T_2 * V_6 )
{
return F_8 ( V_6 ) ;
}
T_1 * F_13 ( T_1 * * V_3 )
{
T_1 * V_11 ;
if ( V_3 == NULL || * V_3 == NULL )
return NULL ;
V_11 = * V_3 ;
* V_3 = ( * V_3 ) -> V_5 ;
return V_11 ;
}
int F_14 ( T_2 * V_6 )
{
T_1 * V_3 = V_6 -> V_8 ;
int V_12 = 0 ;
while ( V_3 != NULL ) {
V_12 ++ ;
V_3 = V_3 -> V_5 ;
}
return V_12 ;
}
