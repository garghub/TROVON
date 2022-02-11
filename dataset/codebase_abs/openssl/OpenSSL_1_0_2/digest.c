void F_1 ( T_1 * V_1 )
{
memset ( V_1 , '\0' , sizeof *V_1 ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_1 = F_3 ( sizeof *V_1 ) ;
if ( V_1 )
F_1 ( V_1 ) ;
return V_1 ;
}
int F_4 ( T_1 * V_1 , const T_2 * type )
{
F_1 ( V_1 ) ;
return F_5 ( V_1 , type , NULL ) ;
}
int F_5 ( T_1 * V_1 , const T_2 * type , T_3 * V_2 )
{
F_6 ( V_1 , V_3 ) ;
#ifdef F_7
if ( F_8 () ) {
const T_2 * V_4 ;
if ( type ) {
V_4 = F_9 ( type ) ;
if ( V_4 )
type = V_4 ;
}
}
#endif
#ifndef F_10
if ( V_1 -> V_5 && V_1 -> V_6 && ( ! type ||
( type
&& ( type -> type ==
V_1 -> V_6 -> type ) ) ) )
goto V_7;
if ( type ) {
if ( V_1 -> V_5 )
F_11 ( V_1 -> V_5 ) ;
if ( V_2 ) {
if ( ! F_12 ( V_2 ) ) {
F_13 ( V_8 , V_9 ) ;
return 0 ;
}
} else
V_2 = F_14 ( type -> type ) ;
if ( V_2 ) {
const T_2 * V_10 = F_15 ( V_2 , type -> type ) ;
if ( ! V_10 ) {
F_13 ( V_8 , V_9 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
type = V_10 ;
V_1 -> V_5 = V_2 ;
} else
V_1 -> V_5 = NULL ;
} else if ( ! V_1 -> V_6 ) {
F_13 ( V_8 , V_11 ) ;
return 0 ;
}
#endif
if ( V_1 -> V_6 != type ) {
if ( V_1 -> V_6 && V_1 -> V_6 -> V_12 )
F_16 ( V_1 -> V_13 ) ;
V_1 -> V_6 = type ;
if ( ! ( V_1 -> V_14 & V_15 ) && type -> V_12 ) {
V_1 -> V_16 = type -> V_16 ;
V_1 -> V_13 = F_3 ( type -> V_12 ) ;
if ( V_1 -> V_13 == NULL ) {
F_13 ( V_8 , V_17 ) ;
return 0 ;
}
}
}
#ifndef F_10
V_7:
#endif
if ( V_1 -> V_18 ) {
int V_19 ;
V_19 = F_17 ( V_1 -> V_18 , - 1 , V_20 ,
V_21 , 0 , V_1 ) ;
if ( V_19 <= 0 && ( V_19 != - 2 ) )
return 0 ;
}
if ( V_1 -> V_14 & V_15 )
return 1 ;
#ifdef F_7
if ( F_8 () ) {
if ( F_18 ( V_1 , type ) )
return 1 ;
F_16 ( V_1 -> V_13 ) ;
V_1 -> V_13 = NULL ;
return 0 ;
}
#endif
return V_1 -> V_6 -> V_22 ( V_1 ) ;
}
int F_19 ( T_1 * V_1 , const void * V_23 , T_4 V_24 )
{
#ifdef F_7
return F_20 ( V_1 , V_23 , V_24 ) ;
#else
return V_1 -> V_16 ( V_1 , V_23 , V_24 ) ;
#endif
}
int F_21 ( T_1 * V_1 , unsigned char * V_25 , unsigned int * V_26 )
{
int V_27 ;
V_27 = F_22 ( V_1 , V_25 , V_26 ) ;
F_23 ( V_1 ) ;
return V_27 ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_25 , unsigned int * V_26 )
{
#ifdef F_7
return F_24 ( V_1 , V_25 , V_26 ) ;
#else
int V_27 ;
F_25 ( V_1 -> V_6 -> V_28 <= V_29 ) ;
V_27 = V_1 -> V_6 -> V_30 ( V_1 , V_25 ) ;
if ( V_26 != NULL )
* V_26 = V_1 -> V_6 -> V_28 ;
if ( V_1 -> V_6 -> V_31 ) {
V_1 -> V_6 -> V_31 ( V_1 ) ;
F_26 ( V_1 , V_3 ) ;
}
memset ( V_1 -> V_13 , 0 , V_1 -> V_6 -> V_12 ) ;
return V_27 ;
#endif
}
int F_27 ( T_1 * V_32 , const T_1 * V_33 )
{
F_1 ( V_32 ) ;
return F_28 ( V_32 , V_33 ) ;
}
int F_28 ( T_1 * V_32 , const T_1 * V_33 )
{
unsigned char * V_34 ;
if ( ( V_33 == NULL ) || ( V_33 -> V_6 == NULL ) ) {
F_13 ( V_35 , V_36 ) ;
return 0 ;
}
#ifndef F_10
if ( V_33 -> V_5 && ! F_12 ( V_33 -> V_5 ) ) {
F_13 ( V_35 , V_37 ) ;
return 0 ;
}
#endif
if ( V_32 -> V_6 == V_33 -> V_6 ) {
V_34 = V_32 -> V_13 ;
F_26 ( V_32 , V_38 ) ;
} else
V_34 = NULL ;
F_23 ( V_32 ) ;
memcpy ( V_32 , V_33 , sizeof *V_32 ) ;
if ( V_33 -> V_13 && V_32 -> V_6 -> V_12 ) {
if ( V_34 )
V_32 -> V_13 = V_34 ;
else {
V_32 -> V_13 = F_3 ( V_32 -> V_6 -> V_12 ) ;
if ( ! V_32 -> V_13 ) {
F_13 ( V_35 , V_17 ) ;
return 0 ;
}
}
memcpy ( V_32 -> V_13 , V_33 -> V_13 , V_32 -> V_6 -> V_12 ) ;
}
V_32 -> V_16 = V_33 -> V_16 ;
if ( V_33 -> V_18 ) {
V_32 -> V_18 = F_29 ( V_33 -> V_18 ) ;
if ( ! V_32 -> V_18 ) {
F_23 ( V_32 ) ;
return 0 ;
}
}
if ( V_32 -> V_6 -> V_39 )
return V_32 -> V_6 -> V_39 ( V_32 , V_33 ) ;
return 1 ;
}
int F_30 ( const void * V_23 , T_4 V_24 ,
unsigned char * V_25 , unsigned int * V_26 , const T_2 * type ,
T_3 * V_2 )
{
T_1 V_1 ;
int V_27 ;
F_1 ( & V_1 ) ;
F_26 ( & V_1 , V_40 ) ;
V_27 = F_5 ( & V_1 , type , V_2 )
&& F_19 ( & V_1 , V_23 , V_24 )
&& F_22 ( & V_1 , V_25 , V_26 ) ;
F_23 ( & V_1 ) ;
return V_27 ;
}
void F_31 ( T_1 * V_1 )
{
if ( V_1 ) {
F_23 ( V_1 ) ;
F_16 ( V_1 ) ;
}
}
int F_23 ( T_1 * V_1 )
{
#ifndef F_7
if ( V_1 -> V_6 && V_1 -> V_6 -> V_31
&& ! F_32 ( V_1 , V_3 ) )
V_1 -> V_6 -> V_31 ( V_1 ) ;
if ( V_1 -> V_6 && V_1 -> V_6 -> V_12 && V_1 -> V_13
&& ! F_32 ( V_1 , V_38 ) ) {
F_33 ( V_1 -> V_13 , V_1 -> V_6 -> V_12 ) ;
F_16 ( V_1 -> V_13 ) ;
}
#endif
if ( V_1 -> V_18 )
F_34 ( V_1 -> V_18 ) ;
#ifndef F_10
if ( V_1 -> V_5 )
F_11 ( V_1 -> V_5 ) ;
#endif
#ifdef F_7
F_35 ( V_1 ) ;
#endif
memset ( V_1 , '\0' , sizeof *V_1 ) ;
return 1 ;
}
