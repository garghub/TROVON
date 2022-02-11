const T_1 * F_1 ( void )
{
return & V_1 ;
}
const T_1 * F_2 ( void )
{
return V_2 ;
}
void F_3 ( const T_1 * V_3 )
{
if ( V_3 == NULL )
V_2 = & V_1 ;
else
V_2 = V_3 ;
}
const T_1 * F_4 ( const T_2 * V_4 )
{
return V_4 -> V_3 ;
}
int F_5 ( T_2 * V_4 , const T_1 * V_3 )
{
void (* F_6)( T_2 * V_4 ) = V_4 -> V_3 -> F_6 ;
if ( F_6 != NULL )
F_6 ( V_4 ) ;
#ifndef F_7
F_8 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
#endif
V_4 -> V_3 = V_3 ;
if ( V_3 -> V_6 != NULL )
return V_3 -> V_6 ( V_4 ) ;
return 1 ;
}
T_2 * F_9 ( T_3 * V_5 )
{
T_2 * V_7 = F_10 ( sizeof( * V_7 ) ) ;
if ( V_7 == NULL ) {
F_11 ( V_8 , V_9 ) ;
return NULL ;
}
V_7 -> V_10 = 1 ;
V_7 -> V_11 = F_12 () ;
if ( V_7 -> V_11 == NULL ) {
F_11 ( V_8 , V_9 ) ;
F_13 ( V_7 ) ;
return NULL ;
}
V_7 -> V_3 = F_2 () ;
#ifndef F_7
if ( V_5 != NULL ) {
if ( ! F_14 ( V_5 ) ) {
F_11 ( V_8 , V_12 ) ;
goto V_13;
}
V_7 -> V_5 = V_5 ;
} else
V_7 -> V_5 = F_15 () ;
if ( V_7 -> V_5 != NULL ) {
V_7 -> V_3 = F_16 ( V_7 -> V_5 ) ;
if ( V_7 -> V_3 == NULL ) {
F_11 ( V_8 , V_12 ) ;
goto V_13;
}
}
#endif
V_7 -> V_14 = 1 ;
V_7 -> V_15 = V_16 ;
if ( ! F_17 ( V_17 , V_7 , & V_7 -> V_18 ) ) {
goto V_13;
}
if ( V_7 -> V_3 -> V_6 != NULL && V_7 -> V_3 -> V_6 ( V_7 ) == 0 ) {
F_11 ( V_8 , V_19 ) ;
goto V_13;
}
return V_7 ;
V_13:
F_18 ( V_7 ) ;
return NULL ;
}
int F_19 ( void * V_20 , T_4 V_21 , const T_5 * V_22 ,
const T_2 * V_23 ,
void * (* F_20) ( const void * V_24 , T_4 V_25 , void * V_20 ,
T_4 * V_21 ) )
{
unsigned char * V_26 = NULL ;
T_4 V_27 ;
if ( V_23 -> V_3 -> V_28 == NULL ) {
F_11 ( V_29 , V_30 ) ;
return 0 ;
}
if ( V_21 > V_31 ) {
F_11 ( V_29 , V_32 ) ;
return 0 ;
}
if ( ! V_23 -> V_3 -> V_28 ( & V_26 , & V_27 , V_22 , V_23 ) )
return 0 ;
if ( F_20 != NULL ) {
F_20 ( V_26 , V_27 , V_20 , & V_21 ) ;
} else {
if ( V_21 > V_27 )
V_21 = V_27 ;
memcpy ( V_20 , V_26 , V_21 ) ;
}
F_21 ( V_26 , V_27 ) ;
return V_21 ;
}
T_1 * F_22 ( const T_1 * V_3 )
{
T_1 * V_7 = F_10 ( sizeof( * V_3 ) ) ;
if ( V_7 == NULL )
return NULL ;
if ( V_3 != NULL )
* V_7 = * V_3 ;
V_7 -> V_33 |= V_34 ;
return V_7 ;
}
void F_23 ( T_1 * V_3 )
{
if ( V_3 -> V_33 & V_34 )
F_13 ( V_3 ) ;
}
void F_24 ( T_1 * V_3 ,
int (* V_6)( T_2 * V_4 ) ,
void (* F_6)( T_2 * V_4 ) ,
int (* F_25)( T_2 * V_35 , const T_2 * V_36 ) ,
int (* F_26)( T_2 * V_4 , const T_6 * V_37 ) ,
int (* F_27)( T_2 * V_4 ,
const T_7 * V_38 ) ,
int (* F_28)( T_2 * V_4 ,
const T_5 * V_22 ) )
{
V_3 -> V_6 = V_6 ;
V_3 -> F_6 = F_6 ;
V_3 -> F_25 = F_25 ;
V_3 -> F_26 = F_26 ;
V_3 -> F_27 = F_27 ;
V_3 -> F_28 = F_28 ;
}
void F_29 ( T_1 * V_3 ,
int (* F_30)( T_2 * V_4 ) )
{
V_3 -> F_30 = F_30 ;
}
void F_31 ( T_1 * V_3 ,
int (* F_32)( unsigned char * * V_39 ,
T_4 * V_40 ,
const T_5 * V_22 ,
const T_2 * V_41 ) )
{
V_3 -> V_28 = F_32 ;
}
void F_33 ( T_1 * V_3 ,
int (* F_34)( int type , const unsigned char * V_42 ,
int V_43 , unsigned char * V_44 ,
unsigned int * V_45 ,
const T_7 * V_46 , const T_7 * V_47 ,
T_2 * V_23 ) ,
int (* F_35)( T_2 * V_23 , T_8 * V_48 ,
T_7 * * V_49 , T_7 * * V_50 ) ,
T_9 * (* F_36)( const unsigned char * V_42 ,
int V_51 ,
const T_7 * V_52 ,
const T_7 * V_53 ,
T_2 * V_23 ) )
{
V_3 -> F_34 = F_34 ;
V_3 -> F_35 = F_35 ;
V_3 -> F_36 = F_36 ;
}
void F_37 ( T_1 * V_3 ,
int (* F_38)( int type , const unsigned
char * V_42 , int V_51 ,
const unsigned char * V_54 ,
int V_55 , T_2 * V_23 ) ,
int (* F_39)( const unsigned char * V_42 ,
int V_51 ,
const T_9 * V_44 ,
T_2 * V_23 ) )
{
V_3 -> F_38 = F_38 ;
V_3 -> F_39 = F_39 ;
}
void F_40 ( T_1 * V_3 ,
int (* * F_41)( T_2 * V_4 ) ,
void (* * F_42)( T_2 * V_4 ) ,
int (* * F_43)( T_2 * V_35 , const T_2 * V_36 ) ,
int (* * F_44)( T_2 * V_4 ,
const T_6 * V_37 ) ,
int (* * F_45)( T_2 * V_4 ,
const T_7 * V_38 ) ,
int (* * F_46)( T_2 * V_4 ,
const T_5 * V_22 ) )
{
if ( F_41 != NULL )
* F_41 = V_3 -> V_6 ;
if ( F_42 != NULL )
* F_42 = V_3 -> F_6 ;
if ( F_43 != NULL )
* F_43 = V_3 -> F_25 ;
if ( F_44 != NULL )
* F_44 = V_3 -> F_26 ;
if ( F_45 != NULL )
* F_45 = V_3 -> F_27 ;
if ( F_46 != NULL )
* F_46 = V_3 -> F_28 ;
}
void F_47 ( T_1 * V_3 ,
int (* * F_48)( T_2 * V_4 ) )
{
if ( F_48 != NULL )
* F_48 = V_3 -> F_30 ;
}
void F_49 ( T_1 * V_3 ,
int (* * F_50)( unsigned char * * V_56 ,
T_4 * V_57 ,
const T_5 * V_22 ,
const T_2 * V_41 ) )
{
if ( F_50 != NULL )
* F_50 = V_3 -> V_28 ;
}
void F_51 ( T_1 * V_3 ,
int (* * F_52)( int type , const unsigned char * V_42 ,
int V_43 , unsigned char * V_44 ,
unsigned int * V_45 ,
const T_7 * V_46 , const T_7 * V_47 ,
T_2 * V_23 ) ,
int (* * F_53)( T_2 * V_23 , T_8 * V_48 ,
T_7 * * V_49 , T_7 * * V_50 ) ,
T_9 * (* * F_54)( const unsigned char * V_42 ,
int V_51 ,
const T_7 * V_52 ,
const T_7 * V_53 ,
T_2 * V_23 ) )
{
if ( F_52 != NULL )
* F_52 = V_3 -> F_34 ;
if ( F_53 != NULL )
* F_53 = V_3 -> F_35 ;
if ( F_54 != NULL )
* F_54 = V_3 -> F_36 ;
}
void F_55 ( T_1 * V_3 ,
int (* * F_56)( int type , const unsigned
char * V_42 , int V_51 ,
const unsigned char * V_54 ,
int V_55 , T_2 * V_23 ) ,
int (* * F_57)( const unsigned char * V_42 ,
int V_51 ,
const T_9 * V_44 ,
T_2 * V_23 ) )
{
if ( F_56 != NULL )
* F_56 = V_3 -> F_38 ;
if ( F_57 != NULL )
* F_57 = V_3 -> F_39 ;
}
