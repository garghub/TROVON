T_1 * F_1 ( const unsigned char * V_1 , int V_2 ,
T_2 * V_3 , void (* F_2)( void * ) )
{
T_1 * V_4 ;
const unsigned char * V_5 ;
V_5 = V_1 ;
if ( ! ( V_4 = F_3 ( NULL , & V_5 , V_2 , V_3 , F_2 ,
V_6 , V_7 ) ) )
F_4 ( V_8 , V_9 ) ;
return V_4 ;
}
unsigned char * F_5 ( T_1 * V_10 , T_3 * V_11 ,
unsigned char * * V_1 , int * V_2 )
{
int V_12 ;
unsigned char * V_13 , * V_14 ;
if ( ! ( V_12 = F_6 ( V_10 , NULL , V_11 , V_6 ,
V_7 , V_15 ) ) ) {
F_4 ( V_16 , V_17 ) ;
return NULL ;
}
if ( ! ( V_13 = F_7 ( V_12 ) ) ) {
F_4 ( V_16 , V_18 ) ;
return NULL ;
}
V_14 = V_13 ;
F_6 ( V_10 , & V_14 , V_11 , V_6 , V_7 ,
V_15 ) ;
if ( V_2 ) * V_2 = V_12 ;
if ( V_1 ) * V_1 = V_13 ;
return V_13 ;
}
void * F_8 ( T_4 * V_19 , T_2 * V_3 )
{
const unsigned char * V_14 ;
char * V_20 ;
V_14 = V_19 -> V_21 ;
if( ! ( V_20 = V_3 ( NULL , & V_14 , V_19 -> V_22 ) ) )
F_4 ( V_23 , V_9 ) ;
return V_20 ;
}
T_4 * F_9 ( void * V_24 , T_3 * V_11 , T_4 * * V_19 )
{
unsigned char * V_14 ;
T_4 * V_25 ;
if ( ! V_19 || ! * V_19 ) {
if ( ! ( V_25 = F_10 () ) ) {
F_4 ( V_26 , V_18 ) ;
return NULL ;
}
if ( V_19 ) * V_19 = V_25 ;
} else V_25 = * V_19 ;
if ( ! ( V_25 -> V_22 = V_11 ( V_24 , NULL ) ) ) {
F_4 ( V_26 , V_17 ) ;
return NULL ;
}
if ( ! ( V_14 = F_7 ( V_25 -> V_22 ) ) ) {
F_4 ( V_26 , V_18 ) ;
return NULL ;
}
V_25 -> V_21 = V_14 ;
V_11 ( V_24 , & V_14 ) ;
return V_25 ;
}
T_4 * F_11 ( void * V_24 , const T_5 * V_27 , T_4 * * V_19 )
{
T_4 * V_25 ;
if ( ! V_19 || ! * V_19 ) {
if ( ! ( V_25 = F_10 () ) ) {
F_4 ( V_28 , V_18 ) ;
return NULL ;
}
if ( V_19 ) * V_19 = V_25 ;
} else V_25 = * V_19 ;
if( V_25 -> V_21 ) {
F_12 ( V_25 -> V_21 ) ;
V_25 -> V_21 = NULL ;
}
if ( ! ( V_25 -> V_22 = F_13 ( V_24 , & V_25 -> V_21 , V_27 ) ) ) {
F_4 ( V_28 , V_17 ) ;
return NULL ;
}
if ( ! V_25 -> V_21 ) {
F_4 ( V_28 , V_18 ) ;
return NULL ;
}
return V_25 ;
}
void * F_14 ( T_4 * V_19 , const T_5 * V_27 )
{
const unsigned char * V_14 ;
void * V_20 ;
V_14 = V_19 -> V_21 ;
if( ! ( V_20 = F_15 ( NULL , & V_14 , V_19 -> V_22 , V_27 ) ) )
F_4 ( V_29 , V_9 ) ;
return V_20 ;
}
