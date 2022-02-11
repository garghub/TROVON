static int F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = F_2 () ;
if ( V_1 -> V_2 == NULL )
return 0 ;
V_1 -> V_3 = 0 ;
return 1 ;
}
static int F_3 ( T_1 * V_4 , T_1 * V_5 )
{
if ( ! F_1 ( V_4 ) )
return 0 ;
if ( ! F_4 ( V_4 -> V_2 , V_5 -> V_2 ) )
return 0 ;
return 1 ;
}
static void F_5 ( T_1 * V_1 )
{
F_6 ( V_1 -> V_2 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_6 )
{
T_3 * V_7 = F_2 () ;
T_3 * V_8 = V_1 -> V_2 ;
if ( V_7 == NULL )
return 0 ;
if ( ! F_4 ( V_7 , V_8 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
F_8 ( V_6 , V_9 , V_7 ) ;
return 1 ;
}
static int F_9 ( T_4 * V_1 , const void * V_2 , T_5 V_10 )
{
if ( ! F_10 ( F_11 ( V_1 ) -> V_2 , V_2 , V_10 ) )
return 0 ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , T_4 * V_11 )
{
F_13 ( V_11 , V_12 ) ;
F_14 ( V_11 , F_9 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_13 , T_5 * V_14 ,
T_4 * V_11 )
{
return F_16 ( V_1 -> V_2 , V_13 , V_14 ) ;
}
static int F_17 ( T_1 * V_1 , int type , int V_15 , void * V_16 )
{
T_3 * V_8 = V_1 -> V_2 ;
switch ( type ) {
case V_17 :
if ( ! V_16 || V_15 < 0 )
return 0 ;
if ( ! F_18 ( V_8 , V_16 , V_15 , NULL , NULL ) )
return 0 ;
break;
case V_18 :
if ( ! F_18 ( V_8 , NULL , 0 , V_16 , V_1 -> V_19 ) )
return 0 ;
break;
case V_20 :
if ( V_1 -> V_6 && ! F_4 ( V_1 -> V_2 ,
( T_3 * ) V_1 -> V_6 -> V_6 . V_21 ) )
return 0 ;
if ( ! F_18 ( V_8 , NULL , 0 , NULL , NULL ) )
return 0 ;
break;
default:
return - 2 ;
}
return 1 ;
}
static int F_19 ( T_1 * V_1 ,
const char * type , const char * V_22 )
{
if ( ! V_22 ) {
return 0 ;
}
if ( strcmp ( type , L_1 ) == 0 ) {
const T_6 * V_23 ;
V_23 = F_20 ( V_22 ) ;
if ( ! V_23 )
return 0 ;
return F_17 ( V_1 , V_18 , - 1 , ( void * ) V_23 ) ;
}
if ( strcmp ( type , L_2 ) == 0 )
return F_21 ( V_1 , V_17 , V_22 ) ;
if ( strcmp ( type , L_3 ) == 0 )
return F_22 ( V_1 , V_17 , V_22 ) ;
return - 2 ;
}
