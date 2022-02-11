int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_2 ( & ( V_1 -> V_3 -> V_4 ) , V_2 ) ) ;
}
T_2 * F_3 ( T_1 * V_1 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) )
return ( NULL ) ;
return ( F_4 ( V_1 -> V_3 -> V_4 ) ) ;
}
T_1 * F_5 ( const char * V_5 , int V_6 )
{
unsigned char * V_7 , * V_8 ;
int V_9 ;
T_1 * V_10 ;
if( V_6 <= 0 ) V_6 = strlen ( V_5 ) ;
if ( ! ( V_7 = F_6 ( V_6 + 1 ) ) ) {
F_7 ( V_11 , V_12 ) ;
return NULL ;
}
V_9 = F_8 ( V_7 , ( const unsigned char * ) V_5 , V_6 ) ;
if( V_9 < 0 ) {
F_7 ( V_11 ,
V_13 ) ;
F_9 ( V_7 ) ;
return NULL ;
}
V_8 = V_7 ;
V_10 = F_10 ( NULL , & V_8 , V_9 ) ;
F_9 ( V_7 ) ;
return V_10 ;
}
char * F_11 ( T_1 * V_10 )
{
unsigned char * V_14 , * V_8 ;
char * V_15 ;
int V_16 ;
V_16 = F_12 ( V_10 , NULL ) ;
V_14 = F_6 ( V_16 ) ;
V_15 = F_6 ( V_16 * 2 ) ;
if( ! V_14 || ! V_15 ) {
F_7 ( V_17 , V_12 ) ;
return NULL ;
}
V_8 = V_14 ;
F_12 ( V_10 , & V_8 ) ;
F_13 ( ( unsigned char * ) V_15 , V_14 , V_16 ) ;
F_9 ( V_14 ) ;
return V_15 ;
}
