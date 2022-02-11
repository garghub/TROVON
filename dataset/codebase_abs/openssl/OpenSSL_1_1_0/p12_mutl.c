int F_1 ( const T_1 * V_1 )
{
return V_1 -> V_2 ? 1 : 0 ;
}
void F_2 ( const T_2 * * V_3 ,
const T_3 * * V_4 ,
const T_2 * * V_5 ,
const T_4 * * V_6 ,
const T_1 * V_1 )
{
if ( V_1 -> V_2 ) {
F_3 ( V_1 -> V_2 -> V_7 , V_4 , V_3 ) ;
if ( V_5 )
* V_5 = V_1 -> V_2 -> V_8 ;
if ( V_6 )
* V_6 = V_1 -> V_2 -> V_9 ;
} else {
if ( V_3 )
* V_3 = NULL ;
if ( V_4 )
* V_4 = NULL ;
if ( V_5 )
* V_5 = NULL ;
if ( V_6 )
* V_6 = NULL ;
}
}
static int F_4 ( const char * V_10 , int V_11 ,
const unsigned char * V_8 , int V_12 ,
int V_9 , int V_13 , unsigned char * V_14 ,
const T_5 * V_15 )
{
unsigned char V_16 [ 96 ] ;
if ( V_13 != V_17 ) {
return 0 ;
}
if ( ! F_5 ( V_10 , V_11 , V_8 , V_12 , V_9 ,
V_15 , sizeof( V_16 ) , V_16 ) ) {
return 0 ;
}
memcpy ( V_14 , V_16 + sizeof( V_16 ) - V_17 , V_17 ) ;
F_6 ( V_16 , sizeof( V_16 ) ) ;
return 1 ;
}
static int F_7 ( T_1 * V_1 , const char * V_10 , int V_11 ,
unsigned char * V_2 , unsigned int * V_18 ,
int (* F_8)( const char * V_10 , int V_11 ,
unsigned char * V_8 , int V_19 ,
int V_20 , int V_9 , int V_21 ,
unsigned char * V_16 ,
const T_5 * V_22 ) )
{
const T_5 * V_22 ;
T_6 * V_23 = NULL ;
unsigned char V_14 [ V_24 ] , * V_8 ;
int V_12 , V_9 ;
int V_25 = 0 ;
int V_26 ;
const T_3 * V_27 ;
const T_7 * V_28 ;
if ( F_8 == NULL )
F_8 = V_29 ;
if ( ! F_9 ( V_1 -> V_30 ) ) {
F_10 ( V_31 , V_32 ) ;
return 0 ;
}
V_8 = V_1 -> V_2 -> V_8 -> V_33 ;
V_12 = V_1 -> V_2 -> V_8 -> V_34 ;
if ( ! V_1 -> V_2 -> V_9 )
V_9 = 1 ;
else
V_9 = F_11 ( V_1 -> V_2 -> V_9 ) ;
F_3 ( V_1 -> V_2 -> V_7 , & V_27 , NULL ) ;
F_12 ( & V_28 , NULL , NULL , V_27 ) ;
if ( ( V_22 = F_13 ( V_28 ) ) == NULL ) {
F_10 ( V_31 , V_35 ) ;
return 0 ;
}
V_25 = F_14 ( V_22 ) ;
V_26 = F_15 ( V_22 ) ;
if ( V_25 < 0 )
return 0 ;
if ( ( V_26 == V_36
|| V_26 == V_37
|| V_26 == V_38 )
&& ! getenv ( L_1 ) ) {
V_25 = V_17 ;
if ( ! F_4 ( V_10 , V_11 , V_8 , V_12 , V_9 ,
V_25 , V_14 , V_22 ) ) {
F_10 ( V_31 , V_39 ) ;
return 0 ;
}
} else
if ( ! (* F_8)( V_10 , V_11 , V_8 , V_12 , V_40 ,
V_9 , V_25 , V_14 , V_22 ) ) {
F_10 ( V_31 , V_39 ) ;
return 0 ;
}
V_23 = F_16 () ;
if ( ! F_17 ( V_23 , V_14 , V_25 , V_22 , NULL )
|| ! F_18 ( V_23 , V_1 -> V_30 -> V_41 . V_33 -> V_33 ,
V_1 -> V_30 -> V_41 . V_33 -> V_34 )
|| ! F_19 ( V_23 , V_2 , V_18 ) ) {
F_20 ( V_23 ) ;
return 0 ;
}
F_20 ( V_23 ) ;
return 1 ;
}
int F_21 ( T_1 * V_1 , const char * V_10 , int V_11 ,
unsigned char * V_2 , unsigned int * V_18 )
{
return F_7 ( V_1 , V_10 , V_11 , V_2 , V_18 , NULL ) ;
}
int F_22 ( T_1 * V_1 , const char * V_10 , int V_11 )
{
unsigned char V_2 [ V_24 ] ;
unsigned int V_18 ;
const T_2 * V_42 ;
if ( V_1 -> V_2 == NULL ) {
F_10 ( V_43 , V_44 ) ;
return 0 ;
}
if ( ! F_7 ( V_1 , V_10 , V_11 , V_2 , & V_18 ,
V_29 ) ) {
F_10 ( V_43 , V_45 ) ;
return 0 ;
}
F_3 ( V_1 -> V_2 -> V_7 , NULL , & V_42 ) ;
if ( ( V_18 != ( unsigned int ) F_23 ( V_42 ) )
|| F_24 ( V_2 , F_25 ( V_42 ) , V_18 ) != 0 )
return 0 ;
return 1 ;
}
int F_26 ( T_1 * V_1 , const char * V_10 , int V_11 ,
unsigned char * V_8 , int V_12 , int V_9 ,
const T_5 * V_22 )
{
unsigned char V_2 [ V_24 ] ;
unsigned int V_18 ;
T_2 * V_42 ;
if ( ! V_22 )
V_22 = F_27 () ;
if ( F_28 ( V_1 , V_9 , V_8 , V_12 , V_22 ) == V_46 ) {
F_10 ( V_47 , V_48 ) ;
return 0 ;
}
if ( ! F_7 ( V_1 , V_10 , V_11 , V_2 , & V_18 ,
V_29 ) ) {
F_10 ( V_47 , V_45 ) ;
return 0 ;
}
F_29 ( V_1 -> V_2 -> V_7 , NULL , & V_42 ) ;
if ( ! F_30 ( V_42 , V_2 , V_18 ) ) {
F_10 ( V_47 , V_49 ) ;
return 0 ;
}
return 1 ;
}
int F_28 ( T_1 * V_1 , int V_9 , unsigned char * V_8 , int V_12 ,
const T_5 * V_22 )
{
T_3 * V_27 ;
if ( ( V_1 -> V_2 = F_31 () ) == NULL )
return V_46 ;
if ( V_9 > 1 ) {
if ( ( V_1 -> V_2 -> V_9 = F_32 () ) == NULL ) {
F_10 ( V_50 , V_51 ) ;
return 0 ;
}
if ( ! F_33 ( V_1 -> V_2 -> V_9 , V_9 ) ) {
F_10 ( V_50 , V_51 ) ;
return 0 ;
}
}
if ( ! V_12 )
V_12 = V_52 ;
if ( ( V_1 -> V_2 -> V_8 -> V_33 = F_34 ( V_12 ) ) == NULL ) {
F_10 ( V_50 , V_51 ) ;
return 0 ;
}
V_1 -> V_2 -> V_8 -> V_34 = V_12 ;
if ( ! V_8 ) {
if ( F_35 ( V_1 -> V_2 -> V_8 -> V_33 , V_12 ) <= 0 )
return 0 ;
} else
memcpy ( V_1 -> V_2 -> V_8 -> V_33 , V_8 , V_12 ) ;
F_29 ( V_1 -> V_2 -> V_7 , & V_27 , NULL ) ;
if ( ! F_36 ( V_27 , F_37 ( F_15 ( V_22 ) ) ,
V_53 , NULL ) ) {
F_10 ( V_50 , V_51 ) ;
return 0 ;
}
return 1 ;
}
