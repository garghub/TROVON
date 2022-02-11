void F_1 ( T_1 * V_1 )
{
memset ( V_1 , '\0' , sizeof *V_1 ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_1 = F_3 ( sizeof *V_1 ) ;
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
if ( V_1 -> V_4 && V_1 -> V_5 && ( ! type ||
( type && ( type -> type == V_1 -> V_5 -> type ) ) ) )
goto V_6;
if ( type )
{
if( V_1 -> V_4 )
F_7 ( V_1 -> V_4 ) ;
if( V_2 )
{
if ( ! F_8 ( V_2 ) )
{
F_9 ( V_7 , V_8 ) ;
return 0 ;
}
}
else
V_2 = F_10 ( type -> type ) ;
if( V_2 )
{
const T_2 * V_9 = F_11 ( V_2 , type -> type ) ;
if( ! V_9 )
{
F_9 ( V_7 , V_8 ) ;
return 0 ;
}
type = V_9 ;
V_1 -> V_4 = V_2 ;
}
else
V_1 -> V_4 = NULL ;
}
else if( ! V_1 -> V_5 )
{
F_9 ( V_7 , V_10 ) ;
return 0 ;
}
if ( V_1 -> V_5 != type )
{
if ( V_1 -> V_5 && V_1 -> V_5 -> V_11 )
F_12 ( V_1 -> V_12 ) ;
V_1 -> V_5 = type ;
if ( type -> V_11 )
V_1 -> V_12 = F_3 ( type -> V_11 ) ;
}
V_6:
return V_1 -> V_5 -> V_13 ( V_1 ) ;
}
int F_13 ( T_1 * V_1 , const void * V_14 ,
unsigned int V_15 )
{
return V_1 -> V_5 -> V_16 ( V_1 , V_14 , ( unsigned long ) V_15 ) ;
}
int F_14 ( T_1 * V_1 , unsigned char * V_17 , unsigned int * V_18 )
{
int V_19 ;
V_19 = F_15 ( V_1 , V_17 , V_18 ) ;
F_16 ( V_1 ) ;
return V_19 ;
}
int F_15 ( T_1 * V_1 , unsigned char * V_17 , unsigned int * V_18 )
{
int V_19 ;
F_17 ( V_1 -> V_5 -> V_20 <= V_21 ) ;
V_19 = V_1 -> V_5 -> V_22 ( V_1 , V_17 ) ;
if ( V_18 != NULL )
* V_18 = V_1 -> V_5 -> V_20 ;
if ( V_1 -> V_5 -> V_23 )
{
V_1 -> V_5 -> V_23 ( V_1 ) ;
F_18 ( V_1 , V_3 ) ;
}
memset ( V_1 -> V_12 , 0 , V_1 -> V_5 -> V_11 ) ;
return V_19 ;
}
int F_19 ( T_1 * V_24 , const T_1 * V_25 )
{
F_1 ( V_24 ) ;
return F_20 ( V_24 , V_25 ) ;
}
int F_20 ( T_1 * V_24 , const T_1 * V_25 )
{
if ( ( V_25 == NULL ) || ( V_25 -> V_5 == NULL ) )
{
F_9 ( V_26 , V_27 ) ;
return 0 ;
}
if ( V_25 -> V_4 && ! F_8 ( V_25 -> V_4 ) )
{
F_9 ( V_26 , V_28 ) ;
return 0 ;
}
F_16 ( V_24 ) ;
memcpy ( V_24 , V_25 , sizeof *V_24 ) ;
if ( V_24 -> V_5 -> V_11 )
{
V_24 -> V_12 = F_3 ( V_24 -> V_5 -> V_11 ) ;
memcpy ( V_24 -> V_12 , V_25 -> V_12 , V_24 -> V_5 -> V_11 ) ;
}
if ( V_24 -> V_5 -> V_29 )
return V_24 -> V_5 -> V_29 ( V_24 , V_25 ) ;
return 1 ;
}
int F_21 ( void * V_14 , unsigned int V_15 ,
unsigned char * V_17 , unsigned int * V_18 , const T_2 * type , T_3 * V_2 )
{
T_1 V_1 ;
int V_19 ;
F_1 ( & V_1 ) ;
F_18 ( & V_1 , V_30 ) ;
V_19 = F_5 ( & V_1 , type , V_2 )
&& F_13 ( & V_1 , V_14 , V_15 )
&& F_15 ( & V_1 , V_17 , V_18 ) ;
F_16 ( & V_1 ) ;
return V_19 ;
}
void F_22 ( T_1 * V_1 )
{
F_16 ( V_1 ) ;
F_12 ( V_1 ) ;
}
int F_16 ( T_1 * V_1 )
{
if ( V_1 -> V_5 && V_1 -> V_5 -> V_23
&& ! F_23 ( V_1 , V_3 ) )
V_1 -> V_5 -> V_23 ( V_1 ) ;
if ( V_1 -> V_5 && V_1 -> V_5 -> V_11 && V_1 -> V_12 )
{
F_24 ( V_1 -> V_12 , V_1 -> V_5 -> V_11 ) ;
F_12 ( V_1 -> V_12 ) ;
}
if( V_1 -> V_4 )
F_7 ( V_1 -> V_4 ) ;
memset ( V_1 , '\0' , sizeof *V_1 ) ;
return 1 ;
}
