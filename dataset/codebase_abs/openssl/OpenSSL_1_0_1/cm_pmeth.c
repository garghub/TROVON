static int F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = F_2 () ;
if ( ! V_1 -> V_2 )
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
if ( ! V_7 )
return 0 ;
if ( ! F_4 ( V_7 , V_8 ) )
{
F_6 ( V_7 ) ;
return 0 ;
}
F_8 ( V_6 , V_9 , V_7 ) ;
return 1 ;
}
static int F_9 ( T_4 * V_1 , const void * V_2 , T_5 V_10 )
{
if ( ! F_10 ( V_1 -> V_11 -> V_2 , V_2 , V_10 ) )
return 0 ;
return 1 ;
}
static int F_11 ( T_1 * V_1 , T_4 * V_12 )
{
F_12 ( V_12 , V_13 ) ;
V_12 -> V_14 = F_9 ;
return 1 ;
}
static int F_13 ( T_1 * V_1 , unsigned char * V_15 , T_5 * V_16 ,
T_4 * V_12 )
{
return F_14 ( V_1 -> V_2 , V_15 , V_16 ) ;
}
static int F_15 ( T_1 * V_1 , int type , int V_17 , void * V_18 )
{
T_3 * V_8 = V_1 -> V_2 ;
switch ( type )
{
case V_19 :
if ( ! V_18 || V_17 < 0 )
return 0 ;
if ( ! F_16 ( V_8 , V_18 , V_17 , NULL , NULL ) )
return 0 ;
break;
case V_20 :
if ( ! F_16 ( V_8 , NULL , 0 , V_18 , V_1 -> V_21 ) )
return 0 ;
break;
case V_22 :
if ( V_1 -> V_6 && ! F_4 ( V_1 -> V_2 ,
( T_3 * ) V_1 -> V_6 -> V_6 . V_23 ) )
return 0 ;
if ( ! F_16 ( V_8 , NULL , 0 , NULL , NULL ) )
return 0 ;
break;
default:
return - 2 ;
}
return 1 ;
}
static int F_17 ( T_1 * V_1 ,
const char * type , const char * V_24 )
{
if ( ! V_24 )
{
return 0 ;
}
if ( ! strcmp ( type , L_1 ) )
{
void * V_25 = ( void * ) V_24 ;
return F_15 ( V_1 , V_19 ,
strlen ( V_25 ) , V_25 ) ;
}
if ( ! strcmp ( type , L_2 ) )
{
const T_6 * V_26 ;
V_26 = F_18 ( V_24 ) ;
if ( ! V_26 )
return 0 ;
return F_15 ( V_1 , V_20 , - 1 , ( void * ) V_26 ) ;
}
if ( ! strcmp ( type , L_3 ) )
{
unsigned char * V_27 ;
int V_28 ;
long V_29 ;
V_27 = F_19 ( V_24 , & V_29 ) ;
if ( ! V_27 )
return 0 ;
V_28 = F_15 ( V_1 , V_19 , V_29 , V_27 ) ;
F_20 ( V_27 ) ;
return V_28 ;
}
return - 2 ;
}
