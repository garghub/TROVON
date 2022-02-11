static T_1
F_1 ( T_2 V_1 )
{
const T_3 * V_2 = ( const T_3 * ) V_1 ;
return V_2 -> V_3 ^ V_2 -> V_4 ;
}
static T_4
F_2 ( T_2 V_1 , T_2 V_5 )
{
const T_3 * V_6 = ( const T_3 * ) V_1 ;
const T_3 * V_7 = ( const T_3 * ) V_5 ;
return V_6 -> V_3 == V_7 -> V_3 && V_6 -> V_4 == V_7 -> V_4 ;
}
void
F_3 ( void )
{
if ( V_8 != NULL )
F_4 ( V_8 ) ;
V_8 = NULL ;
}
void
F_5 ( void )
{
F_6 ( V_8 == NULL ) ;
V_8 = F_7 ( F_1 , F_2 ) ;
V_9 = 0 ;
}
T_5 *
F_8 ( T_6 V_3 , T_7 V_4 , T_7 V_10 )
{
T_5 * V_11 , * V_12 ;
T_3 * V_13 ;
V_13 = F_9 ( F_10 () , struct T_3 ) ;
V_13 -> V_3 = V_3 ;
V_13 -> V_4 = V_4 ;
V_11 = F_9 ( F_10 () , T_5 ) ;
V_11 -> V_14 = NULL ;
V_11 -> V_10 = V_10 ;
V_11 -> V_15 = 0 ;
V_11 -> V_16 = V_9 ;
V_11 -> V_17 = NULL ;
V_11 -> V_18 = NULL ;
V_11 -> V_19 = V_13 ;
V_9 ++ ;
V_12 = ( T_5 * ) F_11 ( V_8 , V_13 ) ;
if ( V_12 != NULL ) {
while ( V_12 -> V_14 != NULL )
V_12 = V_12 -> V_14 ;
if ( V_12 -> V_15 == 0 )
V_12 -> V_15 = V_10 - 1 ;
V_12 -> V_14 = V_11 ;
} else {
F_12 ( V_8 , V_13 , V_11 ) ;
}
return V_11 ;
}
T_5 *
F_13 ( T_6 V_3 , T_7 V_4 , T_7 V_20 )
{
T_3 V_2 ;
T_5 * V_11 ;
V_2 . V_3 = V_3 ;
V_2 . V_4 = V_4 ;
for ( V_11 = ( T_5 * ) F_11 ( V_8 , & V_2 ) ;
V_11 != NULL ; V_11 = V_11 -> V_14 ) {
if ( ( V_11 -> V_10 == 0 || V_11 -> V_10 <= V_20 )
&& ( V_11 -> V_15 == 0 || V_11 -> V_15 >= V_20 ) )
break;
}
return V_11 ;
}
void
F_14 ( T_5 * V_11 , T_7 V_15 )
{
if ( V_11 -> V_15 == 0 )
V_11 -> V_15 = V_15 ;
}
static T_4
F_15 ( T_2 V_21 , T_2 V_22 )
{
const T_8 * V_23 = ( const T_8 * ) V_21 ;
const T_8 * V_24 = ( const T_8 * ) V_22 ;
if ( V_23 -> V_25 > V_24 -> V_25 )
return 1 ;
else if ( V_23 -> V_25 == V_24 -> V_25 )
return 0 ;
else
return - 1 ;
}
void
F_16 ( T_5 * V_26 , int V_25 , void * V_27 )
{
T_8 * V_28 = F_9 ( F_10 () , T_8 ) ;
V_28 -> V_25 = V_25 ;
V_28 -> V_27 = V_27 ;
V_26 -> V_17 = F_17 ( V_26 -> V_17 , ( V_29 * ) V_28 ,
F_15 ) ;
}
void *
F_18 ( T_5 * V_26 , int V_25 )
{
T_8 V_30 , * V_28 ;
T_9 * V_31 ;
V_30 . V_25 = V_25 ;
V_30 . V_27 = NULL ;
V_31 = F_19 ( V_26 -> V_17 , ( V_29 * ) & V_30 ,
F_15 ) ;
if ( V_31 != NULL ) {
V_28 = ( T_8 * ) V_31 -> V_32 ;
return V_28 -> V_27 ;
}
return NULL ;
}
void
F_20 ( T_5 * V_26 , int V_25 )
{
T_8 V_30 ;
T_9 * V_31 ;
V_30 . V_25 = V_25 ;
V_30 . V_27 = NULL ;
V_31 = F_19 ( V_26 -> V_17 , ( V_29 * ) & V_30 ,
F_15 ) ;
if ( V_31 != NULL )
V_26 -> V_17 = F_21 ( V_26 -> V_17 , V_31 ) ;
}
void
F_22 ( T_5 * V_11 , T_10 V_33 )
{
V_11 -> V_18 = V_33 ;
}
T_10
F_23 ( T_5 * V_11 )
{
return V_11 -> V_18 ;
}
T_11
F_24 ( T_6 V_3 , T_7 V_4 , T_7 V_20 ,
T_12 * V_34 , T_13 * V_35 , T_14 * V_36 , void * V_32 )
{
T_5 * V_11 ;
V_11 = F_13 ( V_3 , V_4 , V_20 ) ;
if ( V_11 != NULL ) {
if ( V_11 -> V_18 == NULL )
return FALSE ;
F_25 ( V_11 -> V_18 , V_34 , V_35 ,
V_36 , V_32 ) ;
return TRUE ;
}
return FALSE ;
}
