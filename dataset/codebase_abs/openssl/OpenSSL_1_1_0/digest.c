int F_1 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return 1 ;
if ( V_1 -> V_2 && V_1 -> V_2 -> V_3
&& ! F_2 ( V_1 , V_4 ) )
V_1 -> V_2 -> V_3 ( V_1 ) ;
if ( V_1 -> V_2 && V_1 -> V_2 -> V_5 && V_1 -> V_6
&& ! F_2 ( V_1 , V_7 ) ) {
F_3 ( V_1 -> V_6 , V_1 -> V_2 -> V_5 ) ;
}
F_4 ( V_1 -> V_8 ) ;
#ifndef F_5
F_6 ( V_1 -> V_9 ) ;
#endif
F_7 ( V_1 , sizeof( * V_1 ) ) ;
return 1 ;
}
T_1 * F_8 ( void )
{
return F_9 ( sizeof( T_1 ) ) ;
}
void F_10 ( T_1 * V_1 )
{
F_1 ( V_1 ) ;
F_11 ( V_1 ) ;
}
int F_12 ( T_1 * V_1 , const T_2 * type )
{
F_1 ( V_1 ) ;
return F_13 ( V_1 , type , NULL ) ;
}
int F_13 ( T_1 * V_1 , const T_2 * type , T_3 * V_10 )
{
F_14 ( V_1 , V_4 ) ;
#ifndef F_5
if ( V_1 -> V_9 && V_1 -> V_2 &&
( type == NULL || ( type -> type == V_1 -> V_2 -> type ) ) )
goto V_11;
if ( type ) {
F_6 ( V_1 -> V_9 ) ;
if ( V_10 != NULL ) {
if ( ! F_15 ( V_10 ) ) {
F_16 ( V_12 , V_13 ) ;
return 0 ;
}
} else {
V_10 = F_17 ( type -> type ) ;
}
if ( V_10 != NULL ) {
const T_2 * V_14 = F_18 ( V_10 , type -> type ) ;
if ( V_14 == NULL ) {
F_16 ( V_12 , V_13 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
type = V_14 ;
V_1 -> V_9 = V_10 ;
} else
V_1 -> V_9 = NULL ;
} else {
if ( ! V_1 -> V_2 ) {
F_16 ( V_12 , V_15 ) ;
return 0 ;
}
type = V_1 -> V_2 ;
}
#endif
if ( V_1 -> V_2 != type ) {
if ( V_1 -> V_2 && V_1 -> V_2 -> V_5 ) {
F_3 ( V_1 -> V_6 , V_1 -> V_2 -> V_5 ) ;
V_1 -> V_6 = NULL ;
}
V_1 -> V_2 = type ;
if ( ! ( V_1 -> V_16 & V_17 ) && type -> V_5 ) {
V_1 -> V_18 = type -> V_18 ;
V_1 -> V_6 = F_9 ( type -> V_5 ) ;
if ( V_1 -> V_6 == NULL ) {
F_16 ( V_12 , V_19 ) ;
return 0 ;
}
}
}
#ifndef F_5
V_11:
#endif
if ( V_1 -> V_8 ) {
int V_20 ;
V_20 = F_19 ( V_1 -> V_8 , - 1 , V_21 ,
V_22 , 0 , V_1 ) ;
if ( V_20 <= 0 && ( V_20 != - 2 ) )
return 0 ;
}
if ( V_1 -> V_16 & V_17 )
return 1 ;
return V_1 -> V_2 -> V_23 ( V_1 ) ;
}
int F_20 ( T_1 * V_1 , const void * V_24 , T_4 V_25 )
{
return V_1 -> V_18 ( V_1 , V_24 , V_25 ) ;
}
int F_21 ( T_1 * V_1 , unsigned char * V_26 , unsigned int * V_27 )
{
int V_28 ;
V_28 = F_22 ( V_1 , V_26 , V_27 ) ;
F_1 ( V_1 ) ;
return V_28 ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_26 , unsigned int * V_27 )
{
int V_28 ;
F_23 ( V_1 -> V_2 -> V_29 <= V_30 ) ;
V_28 = V_1 -> V_2 -> V_31 ( V_1 , V_26 ) ;
if ( V_27 != NULL )
* V_27 = V_1 -> V_2 -> V_29 ;
if ( V_1 -> V_2 -> V_3 ) {
V_1 -> V_2 -> V_3 ( V_1 ) ;
F_24 ( V_1 , V_4 ) ;
}
F_7 ( V_1 -> V_6 , V_1 -> V_2 -> V_5 ) ;
return V_28 ;
}
int F_25 ( T_1 * V_32 , const T_1 * V_33 )
{
F_1 ( V_32 ) ;
return F_26 ( V_32 , V_33 ) ;
}
int F_26 ( T_1 * V_32 , const T_1 * V_33 )
{
unsigned char * V_34 ;
if ( ( V_33 == NULL ) || ( V_33 -> V_2 == NULL ) ) {
F_16 ( V_35 , V_36 ) ;
return 0 ;
}
#ifndef F_5
if ( V_33 -> V_9 && ! F_15 ( V_33 -> V_9 ) ) {
F_16 ( V_35 , V_37 ) ;
return 0 ;
}
#endif
if ( V_32 -> V_2 == V_33 -> V_2 ) {
V_34 = V_32 -> V_6 ;
F_24 ( V_32 , V_7 ) ;
} else
V_34 = NULL ;
F_1 ( V_32 ) ;
memcpy ( V_32 , V_33 , sizeof( * V_32 ) ) ;
V_32 -> V_6 = NULL ;
V_32 -> V_8 = NULL ;
if ( V_33 -> V_6 && V_32 -> V_2 -> V_5 ) {
if ( V_34 )
V_32 -> V_6 = V_34 ;
else {
V_32 -> V_6 = F_27 ( V_32 -> V_2 -> V_5 ) ;
if ( V_32 -> V_6 == NULL ) {
F_16 ( V_35 , V_19 ) ;
return 0 ;
}
}
memcpy ( V_32 -> V_6 , V_33 -> V_6 , V_32 -> V_2 -> V_5 ) ;
}
V_32 -> V_18 = V_33 -> V_18 ;
if ( V_33 -> V_8 ) {
V_32 -> V_8 = F_28 ( V_33 -> V_8 ) ;
if ( ! V_32 -> V_8 ) {
F_1 ( V_32 ) ;
return 0 ;
}
}
if ( V_32 -> V_2 -> V_38 )
return V_32 -> V_2 -> V_38 ( V_32 , V_33 ) ;
return 1 ;
}
int F_29 ( const void * V_24 , T_4 V_25 ,
unsigned char * V_26 , unsigned int * V_27 , const T_2 * type ,
T_3 * V_10 )
{
T_1 * V_1 = F_8 () ;
int V_28 ;
if ( V_1 == NULL )
return 0 ;
F_24 ( V_1 , V_39 ) ;
V_28 = F_13 ( V_1 , type , V_10 )
&& F_20 ( V_1 , V_24 , V_25 )
&& F_22 ( V_1 , V_26 , V_27 ) ;
F_10 ( V_1 ) ;
return V_28 ;
}
int F_30 ( T_1 * V_1 , int V_40 , int V_41 , void * V_42 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_43 ) {
int V_28 = V_1 -> V_2 -> V_43 ( V_1 , V_40 , V_41 , V_42 ) ;
if ( V_28 <= 0 )
return 0 ;
return 1 ;
}
return 0 ;
}
