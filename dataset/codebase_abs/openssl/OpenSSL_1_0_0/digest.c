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
#ifndef F_7
if ( V_1 -> V_4 && V_1 -> V_5 && ( ! type ||
( type && ( type -> type == V_1 -> V_5 -> type ) ) ) )
goto V_6;
if ( type )
{
if( V_1 -> V_4 )
F_8 ( V_1 -> V_4 ) ;
if( V_2 )
{
if ( ! F_9 ( V_2 ) )
{
F_10 ( V_7 , V_8 ) ;
return 0 ;
}
}
else
V_2 = F_11 ( type -> type ) ;
if( V_2 )
{
const T_2 * V_9 = F_12 ( V_2 , type -> type ) ;
if( ! V_9 )
{
F_10 ( V_7 , V_8 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
type = V_9 ;
V_1 -> V_4 = V_2 ;
}
else
V_1 -> V_4 = NULL ;
}
else
if( ! V_1 -> V_5 )
{
F_10 ( V_7 , V_10 ) ;
return 0 ;
}
#endif
if ( V_1 -> V_5 != type )
{
if ( V_1 -> V_5 && V_1 -> V_5 -> V_11 )
F_13 ( V_1 -> V_12 ) ;
V_1 -> V_5 = type ;
if ( ! ( V_1 -> V_13 & V_14 ) && type -> V_11 )
{
V_1 -> V_15 = type -> V_15 ;
V_1 -> V_12 = F_3 ( type -> V_11 ) ;
if ( V_1 -> V_12 == NULL )
{
F_10 ( V_7 ,
V_16 ) ;
return 0 ;
}
}
}
#ifndef F_7
V_6:
#endif
if ( V_1 -> V_17 )
{
int V_18 ;
V_18 = F_14 ( V_1 -> V_17 , - 1 , V_19 ,
V_20 , 0 , V_1 ) ;
if ( V_18 <= 0 && ( V_18 != - 2 ) )
return 0 ;
}
if ( V_1 -> V_13 & V_14 )
return 1 ;
return V_1 -> V_5 -> V_21 ( V_1 ) ;
}
int F_15 ( T_1 * V_1 , const void * V_22 , T_4 V_23 )
{
return V_1 -> V_15 ( V_1 , V_22 , V_23 ) ;
}
int F_16 ( T_1 * V_1 , unsigned char * V_24 , unsigned int * V_25 )
{
int V_26 ;
V_26 = F_17 ( V_1 , V_24 , V_25 ) ;
F_18 ( V_1 ) ;
return V_26 ;
}
int F_17 ( T_1 * V_1 , unsigned char * V_24 , unsigned int * V_25 )
{
int V_26 ;
F_19 ( V_1 -> V_5 -> V_27 <= V_28 ) ;
V_26 = V_1 -> V_5 -> V_29 ( V_1 , V_24 ) ;
if ( V_25 != NULL )
* V_25 = V_1 -> V_5 -> V_27 ;
if ( V_1 -> V_5 -> V_30 )
{
V_1 -> V_5 -> V_30 ( V_1 ) ;
F_20 ( V_1 , V_3 ) ;
}
memset ( V_1 -> V_12 , 0 , V_1 -> V_5 -> V_11 ) ;
return V_26 ;
}
int F_21 ( T_1 * V_31 , const T_1 * V_32 )
{
F_1 ( V_31 ) ;
return F_22 ( V_31 , V_32 ) ;
}
int F_22 ( T_1 * V_31 , const T_1 * V_32 )
{
unsigned char * V_33 ;
if ( ( V_32 == NULL ) || ( V_32 -> V_5 == NULL ) )
{
F_10 ( V_34 , V_35 ) ;
return 0 ;
}
#ifndef F_7
if ( V_32 -> V_4 && ! F_9 ( V_32 -> V_4 ) )
{
F_10 ( V_34 , V_36 ) ;
return 0 ;
}
#endif
if ( V_31 -> V_5 == V_32 -> V_5 )
{
V_33 = V_31 -> V_12 ;
F_20 ( V_31 , V_37 ) ;
}
else V_33 = NULL ;
F_18 ( V_31 ) ;
memcpy ( V_31 , V_32 , sizeof *V_31 ) ;
if ( V_32 -> V_12 && V_31 -> V_5 -> V_11 )
{
if ( V_33 )
V_31 -> V_12 = V_33 ;
else
{
V_31 -> V_12 = F_3 ( V_31 -> V_5 -> V_11 ) ;
if ( ! V_31 -> V_12 )
{
F_10 ( V_34 , V_16 ) ;
return 0 ;
}
}
memcpy ( V_31 -> V_12 , V_32 -> V_12 , V_31 -> V_5 -> V_11 ) ;
}
V_31 -> V_15 = V_32 -> V_15 ;
if ( V_32 -> V_17 )
{
V_31 -> V_17 = F_23 ( V_32 -> V_17 ) ;
if ( ! V_31 -> V_17 )
{
F_18 ( V_31 ) ;
return 0 ;
}
}
if ( V_31 -> V_5 -> V_38 )
return V_31 -> V_5 -> V_38 ( V_31 , V_32 ) ;
return 1 ;
}
int F_24 ( const void * V_22 , T_4 V_23 ,
unsigned char * V_24 , unsigned int * V_25 , const T_2 * type , T_3 * V_2 )
{
T_1 V_1 ;
int V_26 ;
F_1 ( & V_1 ) ;
F_20 ( & V_1 , V_39 ) ;
V_26 = F_5 ( & V_1 , type , V_2 )
&& F_15 ( & V_1 , V_22 , V_23 )
&& F_17 ( & V_1 , V_24 , V_25 ) ;
F_18 ( & V_1 ) ;
return V_26 ;
}
void F_25 ( T_1 * V_1 )
{
F_18 ( V_1 ) ;
F_13 ( V_1 ) ;
}
int F_18 ( T_1 * V_1 )
{
if ( V_1 -> V_5 && V_1 -> V_5 -> V_30
&& ! F_26 ( V_1 , V_3 ) )
V_1 -> V_5 -> V_30 ( V_1 ) ;
if ( V_1 -> V_5 && V_1 -> V_5 -> V_11 && V_1 -> V_12
&& ! F_26 ( V_1 , V_37 ) )
{
F_27 ( V_1 -> V_12 , V_1 -> V_5 -> V_11 ) ;
F_13 ( V_1 -> V_12 ) ;
}
if ( V_1 -> V_17 )
F_28 ( V_1 -> V_17 ) ;
#ifndef F_7
if( V_1 -> V_4 )
F_8 ( V_1 -> V_4 ) ;
#endif
memset ( V_1 , '\0' , sizeof *V_1 ) ;
return 1 ;
}
