static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if ( V_1 == V_5 ) {
T_3 * V_6 = ( T_3 * ) * V_2 ;
F_2 ( V_6 -> V_7 ) ;
}
return 1 ;
}
T_4 * F_3 ( T_4 * * V_8 , const unsigned char * * V_9 , long V_10 )
{
T_5 * V_7 ;
T_4 * V_11 ;
const unsigned char * V_12 ;
V_12 = * V_9 ;
V_7 = F_4 ( NULL , & V_12 , V_10 ) ;
if ( ! V_7 )
return NULL ;
V_11 = F_5 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_11 )
return NULL ;
* V_9 = V_12 ;
if ( V_8 ) {
F_6 ( * V_8 ) ;
* V_8 = V_11 ;
}
return V_11 ;
}
int F_7 ( T_4 * V_8 , unsigned char * * V_9 )
{
T_5 * V_13 ;
int V_14 ;
if ( ! V_8 )
return 0 ;
V_13 = F_8 () ;
if ( ! V_13 ) {
F_9 ( V_15 , V_16 ) ;
return 0 ;
}
F_10 ( V_13 , V_8 ) ;
V_14 = F_11 ( V_13 , V_9 ) ;
F_2 ( V_13 ) ;
return V_14 ;
}
T_6 * F_12 ( T_6 * * V_8 , const unsigned char * * V_9 , long V_10 )
{
T_5 * V_7 ;
T_6 * V_11 ;
const unsigned char * V_12 ;
V_12 = * V_9 ;
V_7 = F_4 ( NULL , & V_12 , V_10 ) ;
if ( ! V_7 )
return NULL ;
V_11 = F_13 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_11 )
return NULL ;
* V_9 = V_12 ;
if ( V_8 ) {
F_14 ( * V_8 ) ;
* V_8 = V_11 ;
}
return V_11 ;
}
int F_15 ( T_6 * V_8 , unsigned char * * V_9 )
{
T_5 * V_13 ;
int V_14 ;
if ( ! V_8 )
return 0 ;
V_13 = F_8 () ;
if ( ! V_13 ) {
F_9 ( V_17 , V_16 ) ;
return 0 ;
}
F_16 ( V_13 , V_8 ) ;
V_14 = F_11 ( V_13 , V_9 ) ;
F_2 ( V_13 ) ;
return V_14 ;
}
T_7 * F_17 ( T_7 * * V_8 , const unsigned char * * V_9 , long V_10 )
{
T_5 * V_7 ;
T_7 * V_11 ;
const unsigned char * V_12 ;
V_12 = * V_9 ;
V_7 = F_4 ( NULL , & V_12 , V_10 ) ;
if ( ! V_7 )
return ( NULL ) ;
V_11 = F_18 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_11 )
return ( NULL ) ;
* V_9 = V_12 ;
if ( V_8 ) {
F_19 ( * V_8 ) ;
* V_8 = V_11 ;
}
return ( V_11 ) ;
}
int F_20 ( T_7 * V_8 , unsigned char * * V_9 )
{
T_5 * V_13 ;
int V_14 ;
if ( ! V_8 )
return ( 0 ) ;
if ( ( V_13 = F_8 () ) == NULL ) {
F_9 ( V_18 , V_16 ) ;
return ( 0 ) ;
}
F_21 ( V_13 , V_8 ) ;
V_14 = F_11 ( V_13 , V_9 ) ;
F_2 ( V_13 ) ;
return ( V_14 ) ;
}
int F_22 ( T_3 * V_19 , T_8 * V_20 ,
int V_21 , void * V_2 ,
unsigned char * V_22 , int V_23 )
{
if ( ! F_23 ( V_19 -> V_24 , V_20 , V_21 , V_2 ) )
return 0 ;
if ( V_22 ) {
if ( V_19 -> V_25 -> V_26 )
F_24 ( V_19 -> V_25 -> V_26 ) ;
V_19 -> V_25 -> V_26 = V_22 ;
V_19 -> V_25 -> V_10 = V_23 ;
V_19 -> V_25 -> V_27 &= ~ ( V_28 | 0x07 ) ;
V_19 -> V_25 -> V_27 |= V_28 ;
}
return 1 ;
}
int F_25 ( T_8 * * V_29 ,
const unsigned char * * V_30 , int * V_31 ,
T_9 * * V_32 , T_3 * V_19 )
{
if ( V_29 )
* V_29 = V_19 -> V_24 -> V_33 ;
if ( V_30 ) {
* V_30 = V_19 -> V_25 -> V_26 ;
* V_31 = V_19 -> V_25 -> V_10 ;
}
if ( V_32 )
* V_32 = V_19 -> V_24 ;
return 1 ;
}
