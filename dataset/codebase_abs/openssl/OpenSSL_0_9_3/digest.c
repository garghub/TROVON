void F_1 ( T_1 * V_1 , const T_2 * type )
{
V_1 -> V_2 = type ;
type -> V_3 ( & ( V_1 -> V_4 ) ) ;
}
void F_2 ( T_1 * V_1 , const unsigned char * V_5 ,
unsigned int V_6 )
{
V_1 -> V_2 -> V_7 ( & ( V_1 -> V_4 . V_8 [ 0 ] ) , V_5 , ( unsigned long ) V_6 ) ;
}
void F_3 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_9 )
{
V_1 -> V_2 -> V_10 ( V_4 , & ( V_1 -> V_4 . V_8 [ 0 ] ) ) ;
if ( V_9 != NULL )
* V_9 = V_1 -> V_2 -> V_11 ;
memset ( & ( V_1 -> V_4 ) , 0 , sizeof( V_1 -> V_4 ) ) ;
}
int F_4 ( T_1 * V_12 , T_1 * V_13 )
{
if ( ( V_13 == NULL ) || ( V_13 -> V_2 == NULL ) ) {
F_5 ( V_14 , V_15 ) ;
return 0 ;
}
memcpy ( ( char * ) V_12 , ( char * ) V_13 , V_13 -> V_2 -> V_16 ) ;
return 1 ;
}
