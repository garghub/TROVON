static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if ( V_1 == V_5 ) {
T_3 * V_6 = ( T_3 * ) * V_2 ;
F_2 ( V_6 -> V_7 ) ;
} else if ( V_1 == V_8 ) {
T_3 * V_6 = ( T_3 * ) * V_2 ;
F_2 ( V_6 -> V_7 ) ;
F_3 () ;
if ( F_4 ( & V_6 -> V_7 , V_6 ) == - 1 )
return 0 ;
F_5 () ;
}
return 1 ;
}
int F_4 ( T_4 * * V_9 , T_3 * V_10 )
{
T_4 * V_7 = F_6 () ;
if ( V_7 == NULL ) {
F_7 ( V_11 , V_12 ) ;
return - 1 ;
}
if ( ! F_8 ( V_7 , F_9 ( V_10 -> V_13 -> V_14 ) ) ) {
F_7 ( V_11 , V_15 ) ;
goto error;
}
if ( V_7 -> V_16 -> V_17 ) {
if ( ! V_7 -> V_16 -> V_17 ( V_7 , V_10 ) ) {
F_7 ( V_11 , V_18 ) ;
goto error;
}
} else {
F_7 ( V_11 , V_19 ) ;
goto error;
}
* V_9 = V_7 ;
return 1 ;
error:
F_2 ( V_7 ) ;
return 0 ;
}
T_4 * F_10 ( T_3 * V_10 )
{
T_4 * V_20 = NULL ;
if ( V_10 == NULL || V_10 -> V_21 == NULL )
return NULL ;
if ( V_10 -> V_7 != NULL )
return V_10 -> V_7 ;
F_4 ( & V_20 , V_10 ) ;
if ( V_20 != NULL ) {
F_7 ( V_22 , V_23 ) ;
F_2 ( V_20 ) ;
}
return NULL ;
}
T_4 * F_11 ( T_3 * V_10 )
{
T_4 * V_20 = F_10 ( V_10 ) ;
if ( V_20 != NULL )
F_12 ( V_20 ) ;
return V_20 ;
}
T_4 * F_13 ( T_4 * * V_24 , const unsigned char * * V_25 , long V_26 )
{
T_3 * V_27 ;
T_4 * V_28 ;
const unsigned char * V_29 ;
V_29 = * V_25 ;
V_27 = F_14 ( NULL , & V_29 , V_26 ) ;
if ( ! V_27 )
return NULL ;
V_28 = F_11 ( V_27 ) ;
F_15 ( V_27 ) ;
if ( ! V_28 )
return NULL ;
* V_25 = V_29 ;
if ( V_24 ) {
F_2 ( * V_24 ) ;
* V_24 = V_28 ;
}
return V_28 ;
}
int F_16 ( T_4 * V_24 , unsigned char * * V_25 )
{
T_3 * V_27 = NULL ;
int V_20 ;
if ( ! V_24 )
return 0 ;
if ( ! F_17 ( & V_27 , V_24 ) )
return 0 ;
V_20 = F_18 ( V_27 , V_25 ) ;
F_15 ( V_27 ) ;
return V_20 ;
}
T_5 * F_19 ( T_5 * * V_24 , const unsigned char * * V_25 , long V_26 )
{
T_4 * V_7 ;
T_5 * V_10 ;
const unsigned char * V_29 ;
V_29 = * V_25 ;
V_7 = F_13 ( NULL , & V_29 , V_26 ) ;
if ( ! V_7 )
return NULL ;
V_10 = F_20 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_10 )
return NULL ;
* V_25 = V_29 ;
if ( V_24 ) {
F_21 ( * V_24 ) ;
* V_24 = V_10 ;
}
return V_10 ;
}
int F_22 ( T_5 * V_24 , unsigned char * * V_25 )
{
T_4 * V_28 ;
int V_20 ;
if ( ! V_24 )
return 0 ;
V_28 = F_6 () ;
if ( V_28 == NULL ) {
F_23 ( V_30 , V_12 ) ;
return 0 ;
}
F_24 ( V_28 , V_24 ) ;
V_20 = F_16 ( V_28 , V_25 ) ;
F_2 ( V_28 ) ;
return V_20 ;
}
T_6 * F_25 ( T_6 * * V_24 , const unsigned char * * V_25 , long V_26 )
{
T_4 * V_7 ;
T_6 * V_10 ;
const unsigned char * V_29 ;
V_29 = * V_25 ;
V_7 = F_13 ( NULL , & V_29 , V_26 ) ;
if ( ! V_7 )
return NULL ;
V_10 = F_26 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_10 )
return NULL ;
* V_25 = V_29 ;
if ( V_24 ) {
F_27 ( * V_24 ) ;
* V_24 = V_10 ;
}
return V_10 ;
}
int F_28 ( T_6 * V_24 , unsigned char * * V_25 )
{
T_4 * V_28 ;
int V_20 ;
if ( ! V_24 )
return 0 ;
V_28 = F_6 () ;
if ( V_28 == NULL ) {
F_23 ( V_31 , V_12 ) ;
return 0 ;
}
F_29 ( V_28 , V_24 ) ;
V_20 = F_16 ( V_28 , V_25 ) ;
F_2 ( V_28 ) ;
return V_20 ;
}
T_7 * F_30 ( T_7 * * V_24 , const unsigned char * * V_25 , long V_26 )
{
T_4 * V_7 ;
T_7 * V_10 ;
const unsigned char * V_29 ;
V_29 = * V_25 ;
V_7 = F_13 ( NULL , & V_29 , V_26 ) ;
if ( ! V_7 )
return ( NULL ) ;
V_10 = F_31 ( V_7 ) ;
F_2 ( V_7 ) ;
if ( ! V_10 )
return ( NULL ) ;
* V_25 = V_29 ;
if ( V_24 ) {
F_32 ( * V_24 ) ;
* V_24 = V_10 ;
}
return ( V_10 ) ;
}
int F_33 ( T_7 * V_24 , unsigned char * * V_25 )
{
T_4 * V_28 ;
int V_20 ;
if ( ! V_24 )
return ( 0 ) ;
if ( ( V_28 = F_6 () ) == NULL ) {
F_23 ( V_32 , V_12 ) ;
return ( 0 ) ;
}
F_34 ( V_28 , V_24 ) ;
V_20 = F_16 ( V_28 , V_25 ) ;
F_2 ( V_28 ) ;
return ( V_20 ) ;
}
int F_35 ( T_3 * V_33 , T_8 * V_34 ,
int V_35 , void * V_2 ,
unsigned char * V_36 , int V_37 )
{
if ( ! F_36 ( V_33 -> V_13 , V_34 , V_35 , V_2 ) )
return 0 ;
if ( V_36 ) {
F_37 ( V_33 -> V_21 -> V_38 ) ;
V_33 -> V_21 -> V_38 = V_36 ;
V_33 -> V_21 -> V_26 = V_37 ;
V_33 -> V_21 -> V_39 &= ~ ( V_40 | 0x07 ) ;
V_33 -> V_21 -> V_39 |= V_40 ;
}
return 1 ;
}
int F_38 ( T_8 * * V_41 ,
const unsigned char * * V_42 , int * V_43 ,
T_9 * * V_44 , T_3 * V_33 )
{
if ( V_41 )
* V_41 = V_33 -> V_13 -> V_14 ;
if ( V_42 ) {
* V_42 = V_33 -> V_21 -> V_38 ;
* V_43 = V_33 -> V_21 -> V_26 ;
}
if ( V_44 )
* V_44 = V_33 -> V_13 ;
return 1 ;
}
T_10 * F_39 ( const T_11 * V_45 )
{
if ( V_45 == NULL )
return NULL ;
return V_45 -> V_46 . V_10 -> V_21 ;
}
