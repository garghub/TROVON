static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 )
{
if( V_1 == V_4 ) {
T_3 * V_5 = ( T_3 * ) * V_2 ;
F_2 ( V_5 -> V_6 ) ;
}
return 1 ;
}
T_4 * F_3 ( T_4 * * V_7 , unsigned char * * V_8 ,
long V_9 )
{
T_5 * V_6 ;
T_4 * V_10 ;
unsigned char * V_11 ;
V_11 = * V_8 ;
V_6 = F_4 ( NULL , & V_11 , V_9 ) ;
if( ! V_6 ) return NULL ;
V_10 = F_5 ( V_6 ) ;
F_2 ( V_6 ) ;
if( ! V_10 ) return NULL ;
* V_8 = V_11 ;
if( V_7 ) {
F_6 ( * V_7 ) ;
* V_7 = V_10 ;
}
return V_10 ;
}
int F_7 ( T_4 * V_7 , unsigned char * * V_8 )
{
T_5 * V_12 ;
int V_13 ;
if( ! V_7 ) return 0 ;
V_12 = F_8 () ;
if( ! V_12 ) {
F_9 ( V_14 , V_15 ) ;
return 0 ;
}
F_10 ( V_12 , V_7 ) ;
V_13 = F_11 ( V_12 , V_8 ) ;
F_2 ( V_12 ) ;
return V_13 ;
}
T_6 * F_12 ( T_6 * * V_7 , unsigned char * * V_8 ,
long V_9 )
{
T_5 * V_6 ;
T_6 * V_10 ;
unsigned char * V_11 ;
V_11 = * V_8 ;
V_6 = F_4 ( NULL , & V_11 , V_9 ) ;
if( ! V_6 ) return NULL ;
V_10 = F_13 ( V_6 ) ;
F_2 ( V_6 ) ;
if( ! V_10 ) return NULL ;
* V_8 = V_11 ;
if( V_7 ) {
F_14 ( * V_7 ) ;
* V_7 = V_10 ;
}
return V_10 ;
}
int F_15 ( T_6 * V_7 , unsigned char * * V_8 )
{
T_5 * V_12 ;
int V_13 ;
if( ! V_7 ) return 0 ;
V_12 = F_8 () ;
if( ! V_12 ) {
F_9 ( V_16 , V_15 ) ;
return 0 ;
}
F_16 ( V_12 , V_7 ) ;
V_13 = F_11 ( V_12 , V_8 ) ;
F_2 ( V_12 ) ;
return V_13 ;
}
