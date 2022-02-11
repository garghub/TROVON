T_1 * F_1 ( unsigned char * V_1 , int V_2 , char * (* F_2)() ,
void (* F_3)( void * ) )
{
T_1 * V_3 ;
unsigned char * V_4 ;
V_4 = V_1 ;
if ( ! ( V_3 = F_4 ( NULL , & V_4 , V_2 , F_2 , F_3 ,
V_5 , V_6 ) ) )
F_5 ( V_7 , V_8 ) ;
return V_3 ;
}
unsigned char * F_6 ( T_1 * V_9 , int (* F_7)() , unsigned char * * V_1 ,
int * V_2 )
{
int V_10 ;
unsigned char * V_11 , * V_12 ;
if ( ! ( V_10 = F_8 ( V_9 , NULL , F_7 , V_5 ,
V_6 , V_13 ) ) ) {
F_5 ( V_14 , V_15 ) ;
return NULL ;
}
if ( ! ( V_11 = F_9 ( V_10 ) ) ) {
F_5 ( V_14 , V_16 ) ;
return NULL ;
}
V_12 = V_11 ;
F_8 ( V_9 , & V_12 , F_7 , V_5 , V_6 ,
V_13 ) ;
if ( V_2 ) * V_2 = V_10 ;
if ( V_1 ) * V_1 = V_11 ;
return V_11 ;
}
void * F_10 ( T_2 * V_17 , char * (* F_2)() )
{
unsigned char * V_12 ;
char * V_18 ;
V_12 = V_17 -> V_19 ;
if( ! ( V_18 = F_2 ( NULL , & V_12 , V_17 -> V_20 ) ) )
F_5 ( V_21 , V_8 ) ;
return V_18 ;
}
T_2 * F_11 ( void * V_22 , int (* F_7)() , T_2 * * V_17 )
{
unsigned char * V_12 ;
T_2 * V_23 ;
if ( ! V_17 || ! * V_17 ) {
if ( ! ( V_23 = F_12 () ) ) {
F_5 ( V_24 , V_16 ) ;
return NULL ;
}
if ( V_17 ) * V_17 = V_23 ;
} else V_23 = * V_17 ;
if ( ! ( V_23 -> V_20 = F_7 ( V_22 , NULL ) ) ) {
F_5 ( V_24 , V_15 ) ;
return NULL ;
}
if ( ! ( V_12 = F_9 ( V_23 -> V_20 ) ) ) {
F_5 ( V_24 , V_16 ) ;
return NULL ;
}
V_23 -> V_19 = V_12 ;
F_7 ( V_22 , & V_12 ) ;
return V_23 ;
}
