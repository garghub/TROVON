T_1 * F_1 ( T_2 V_1 )
{
T_1 * V_2 = NULL ;
if ( V_3 )
{
V_2 = V_3 -> V_4 ;
while ( V_2 )
{
if ( V_2 -> V_1 == V_1 )
{
break;
}
else
{
V_2 = V_2 -> V_5 ;
}
}
}
return V_2 ;
}
static const T_3 * F_2 ( T_1 * V_2 , T_2 V_6 )
{
const T_3 * V_7 = V_2 -> V_8 ;
if ( V_2 -> V_9 )
{
return ( const T_3 * ) V_2 -> V_9 ( ( T_3 * ) V_7 , V_6 ) ;
}
while ( V_7 )
{
if ( V_7 -> V_10 == NULL )
{
V_7 = NULL ;
break;
}
if ( V_7 -> V_6 == V_6 )
{
break;
}
else
{
V_7 ++ ;
}
}
return V_7 ;
}
static void * F_3 ( T_2 V_1 ,
T_4 V_11 ,
T_5 * V_12 )
{
T_1 * V_2 ;
T_5 * V_13 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 )
{
const T_3 * V_7 ;
T_2 V_14 = 0 ;
T_4 V_15 = 0 ;
F_4 ( & V_14 , V_12 , & V_15 ) ;
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 )
{
V_13 = V_7 -> V_16 ( V_12 , V_11 ) ;
}
else
{
V_13 = NULL ;
}
}
else
{
V_13 = NULL ;
}
return V_13 ;
}
static T_4 F_5 ( T_2 V_1 , void * V_17 )
{
T_1 * V_2 = F_1 ( V_1 ) ;
T_4 V_13 ;
if ( V_2 )
{
const T_3 * V_7 ;
T_2 V_14 = * ( T_2 * ) V_17 ;
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 )
{
V_13 = V_7 -> V_18 ( V_17 ) ;
}
else
{
V_13 = 0 ;
}
}
else
{
V_13 = 0 ;
}
return V_13 ;
}
static T_5 F_6 ( T_2 V_1 , T_5 * V_12 )
{
T_1 * V_2 ;
T_5 V_13 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 )
{
const T_3 * V_7 ;
T_2 V_14 = * ( T_2 * ) V_12 ;
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 )
{
V_7 -> V_19 ( V_12 ) ;
V_13 = TRUE ;
}
else
{
V_13 = FALSE ;
}
}
else
{
V_13 = FALSE ;
}
return V_13 ;
}
static T_5 * F_7 ( T_2 V_1 ,
void * V_17 ,
T_4 * V_11 ,
T_5 * V_20 )
{
T_1 * V_2 ;
T_5 * V_13 ;
V_2 = F_1 ( V_1 ) ;
* V_11 = 0 ;
if ( V_2 )
{
const T_3 * V_7 ;
V_7 = F_2 ( V_2 , * ( T_2 * ) V_17 ) ;
if ( V_7 )
{
V_13 = V_7 -> V_10 ( V_20 , V_11 , V_17 ) ;
}
else
{
V_13 = NULL ;
}
}
else
{
V_13 = NULL ;
}
return V_13 ;
}
T_4 F_8 ( T_2 V_1 , void * V_17 )
{
return F_5 ( V_1 , V_17 ) ;
}
T_5 * F_9 ( T_5 * V_20 , T_4 V_21 , T_4 * V_15 , T_2 V_1 , void * V_17 )
{
if ( V_3 )
{
T_4 V_22 ;
T_5 * V_23 ;
T_5 * V_24 = & V_20 [ * V_15 ] ;
V_23 = V_3 -> F_7 ( V_1 , V_17 , & V_22 , V_24 ) ;
* V_15 += V_22 ;
return V_23 ;
}
else
{
return NULL ;
}
}
void F_10 ( T_2 V_1 , const T_3 * V_25 )
{
T_1 * V_26 ;
V_26 = F_1 ( V_1 ) ;
if ( V_26 )
{
}
else
{
V_26 = F_11 ( sizeof( * V_26 ) , V_27 ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_8 = V_25 ;
V_26 -> V_9 = NULL ;
V_26 -> V_5 = V_3 -> V_4 ;
V_3 -> V_4 = V_26 ;
}
}
T_3 * F_12 ( T_2 V_1 , T_2 V_6 )
{
T_1 * V_2 = F_1 ( V_1 ) ;
if ( V_2 )
{
return ( T_3 * ) F_2 ( V_2 , V_6 ) ;
}
return NULL ;
}
T_3 * F_13 ( T_2 V_1 , const void * V_17 )
{
T_1 * V_2 = F_1 ( V_1 ) ;
if ( V_2 && V_17 )
{
T_2 V_6 = * ( ( T_2 * ) V_17 ) ;
return ( T_3 * ) F_2 ( V_2 , V_6 ) ;
}
return NULL ;
}
void F_14 ( T_2 V_1 , T_6 * V_9 )
{
T_1 * V_2 = F_1 ( V_1 ) ;
if ( V_2 )
{
V_2 -> V_9 = V_9 ;
}
}
T_7 * F_15 ( void )
{
if ( ! V_3 )
{
V_3 = F_11 ( sizeof( T_7 ) , V_27 ) ;
V_3 -> V_4 = NULL ;
V_3 -> F_6 = F_6 ;
V_3 -> F_5 = F_5 ;
V_3 -> F_7 = F_7 ;
V_3 -> F_3 = F_3 ;
}
return V_3 ;
}
