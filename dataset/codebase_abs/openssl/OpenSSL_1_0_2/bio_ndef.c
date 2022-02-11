T_1 * F_1 ( T_1 * V_1 , T_2 * V_2 , const T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_1 * V_5 = NULL ;
const T_5 * V_6 = V_3 -> V_7 ;
T_6 V_8 ;
if ( ! V_6 || ! V_6 -> V_9 ) {
F_2 ( V_10 , V_11 ) ;
return NULL ;
}
V_4 = F_3 ( sizeof( T_4 ) ) ;
V_5 = F_4 ( F_5 () ) ;
V_1 = F_6 ( V_5 , V_1 ) ;
if ( ! V_4 || ! V_5 || ! V_1 )
goto V_12;
F_7 ( V_5 , V_13 , V_14 ) ;
F_8 ( V_5 , V_15 , V_16 ) ;
V_8 . V_1 = V_1 ;
V_8 . V_17 = NULL ;
V_8 . V_18 = NULL ;
if ( V_6 -> V_9 ( V_19 , & V_2 , V_3 , & V_8 ) <= 0 )
goto V_12;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_17 = V_8 . V_17 ;
V_4 -> V_18 = V_8 . V_18 ;
V_4 -> V_1 = V_1 ;
F_9 ( V_5 , V_20 , 0 , V_4 ) ;
return V_8 . V_17 ;
V_12:
if ( V_5 )
F_10 ( V_5 ) ;
if ( V_4 )
F_11 ( V_4 ) ;
return NULL ;
}
static int V_13 ( T_1 * V_21 , unsigned char * * V_22 , int * V_23 , void * V_24 )
{
T_4 * V_4 ;
unsigned char * V_25 ;
int V_26 ;
if ( ! V_24 )
return 0 ;
V_4 = * ( T_4 * * ) V_24 ;
V_26 = F_12 ( V_4 -> V_2 , NULL , V_4 -> V_3 ) ;
V_25 = F_3 ( V_26 ) ;
V_4 -> V_27 = V_25 ;
* V_22 = V_25 ;
V_26 = F_12 ( V_4 -> V_2 , & V_25 , V_4 -> V_3 ) ;
if ( ! * V_4 -> V_18 )
return 0 ;
* V_23 = * V_4 -> V_18 - * V_22 ;
return 1 ;
}
static int V_14 ( T_1 * V_21 , unsigned char * * V_22 , int * V_23 ,
void * V_24 )
{
T_4 * V_4 ;
if ( ! V_24 )
return 0 ;
V_4 = * ( T_4 * * ) V_24 ;
if ( V_4 -> V_27 )
F_11 ( V_4 -> V_27 ) ;
V_4 -> V_27 = NULL ;
* V_22 = NULL ;
* V_23 = 0 ;
return 1 ;
}
static int V_16 ( T_1 * V_21 , unsigned char * * V_22 , int * V_23 ,
void * V_24 )
{
T_4 * * V_28 = ( T_4 * * ) V_24 ;
if ( ! V_14 ( V_21 , V_22 , V_23 , V_24 ) )
return 0 ;
F_11 ( * V_28 ) ;
* V_28 = NULL ;
return 1 ;
}
static int V_15 ( T_1 * V_21 , unsigned char * * V_22 , int * V_23 , void * V_24 )
{
T_4 * V_4 ;
unsigned char * V_25 ;
int V_26 ;
const T_5 * V_6 ;
T_6 V_8 ;
if ( ! V_24 )
return 0 ;
V_4 = * ( T_4 * * ) V_24 ;
V_6 = V_4 -> V_3 -> V_7 ;
V_8 . V_17 = V_4 -> V_17 ;
V_8 . V_1 = V_4 -> V_1 ;
V_8 . V_18 = V_4 -> V_18 ;
if ( V_6 -> V_9 ( V_29 ,
& V_4 -> V_2 , V_4 -> V_3 , & V_8 ) <= 0 )
return 0 ;
V_26 = F_12 ( V_4 -> V_2 , NULL , V_4 -> V_3 ) ;
V_25 = F_3 ( V_26 ) ;
V_4 -> V_27 = V_25 ;
* V_22 = V_25 ;
V_26 = F_12 ( V_4 -> V_2 , & V_25 , V_4 -> V_3 ) ;
if ( ! * V_4 -> V_18 )
return 0 ;
* V_22 = * V_4 -> V_18 ;
* V_23 = V_26 - ( * V_4 -> V_18 - V_4 -> V_27 ) ;
return 1 ;
}
