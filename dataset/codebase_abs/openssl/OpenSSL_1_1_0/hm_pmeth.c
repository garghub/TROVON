static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_2 -> V_3 . type = V_4 ;
V_2 -> V_1 = F_3 () ;
if ( V_2 -> V_1 == NULL ) {
F_4 ( V_2 ) ;
return 0 ;
}
V_1 -> V_5 = V_2 ;
V_1 -> V_6 = 0 ;
return 1 ;
}
static int F_5 ( T_1 * V_7 , T_1 * V_8 )
{
T_2 * V_9 , * V_10 ;
if ( ! F_1 ( V_7 ) )
return 0 ;
V_9 = F_6 ( V_8 ) ;
V_10 = F_6 ( V_7 ) ;
V_10 -> V_11 = V_9 -> V_11 ;
if ( ! F_7 ( V_10 -> V_1 , V_9 -> V_1 ) )
goto V_12;
if ( V_9 -> V_3 . V_5 ) {
if ( ! F_8 ( & V_10 -> V_3 ,
V_9 -> V_3 . V_5 , V_9 -> V_3 . V_13 ) )
goto V_12;
}
return 1 ;
V_12:
F_9 ( V_7 ) ;
return 0 ;
}
static void F_9 ( T_1 * V_1 )
{
T_2 * V_2 = F_6 ( V_1 ) ;
if ( V_2 != NULL ) {
F_10 ( V_2 -> V_1 ) ;
F_11 ( V_2 -> V_3 . V_5 , V_2 -> V_3 . V_13 ) ;
F_4 ( V_2 ) ;
F_12 ( V_1 , NULL ) ;
}
}
static int F_13 ( T_1 * V_1 , T_3 * V_14 )
{
T_4 * V_15 = NULL ;
T_2 * V_2 = V_1 -> V_5 ;
if ( ! V_2 -> V_3 . V_5 )
return 0 ;
V_15 = F_14 ( & V_2 -> V_3 ) ;
if ( ! V_15 )
return 0 ;
F_15 ( V_14 , V_16 , V_15 ) ;
return 1 ;
}
static int F_16 ( T_5 * V_1 , const void * V_5 , T_6 V_17 )
{
T_2 * V_2 = F_17 ( V_1 ) -> V_5 ;
if ( ! F_18 ( V_2 -> V_1 , V_5 , V_17 ) )
return 0 ;
return 1 ;
}
static int F_19 ( T_1 * V_1 , T_5 * V_18 )
{
T_2 * V_2 = V_1 -> V_5 ;
F_20 ( V_2 -> V_1 ,
F_21 ( V_18 , ~ V_19 ) ) ;
F_22 ( V_18 , V_19 ) ;
F_23 ( V_18 , F_16 ) ;
return 1 ;
}
static int F_24 ( T_1 * V_1 , unsigned char * V_20 , T_6 * V_21 ,
T_5 * V_18 )
{
unsigned int V_22 ;
T_2 * V_2 = V_1 -> V_5 ;
int V_23 = F_25 ( V_18 ) ;
if ( V_23 < 0 )
return 0 ;
* V_21 = V_23 ;
if ( ! V_20 )
return 1 ;
if ( ! F_26 ( V_2 -> V_1 , V_20 , & V_22 ) )
return 0 ;
* V_21 = ( T_6 ) V_22 ;
return 1 ;
}
static int F_27 ( T_1 * V_1 , int type , int V_24 , void * V_25 )
{
T_2 * V_2 = V_1 -> V_5 ;
T_4 * V_26 ;
switch ( type ) {
case V_27 :
if ( ( ! V_25 && V_24 > 0 ) || ( V_24 < - 1 ) )
return 0 ;
if ( ! F_8 ( & V_2 -> V_3 , V_25 , V_24 ) )
return 0 ;
break;
case V_28 :
V_2 -> V_11 = V_25 ;
break;
case V_29 :
V_26 = ( T_4 * ) V_1 -> V_14 -> V_14 . V_30 ;
if ( ! F_28 ( V_2 -> V_1 , V_26 -> V_5 , V_26 -> V_13 , V_2 -> V_11 ,
V_1 -> V_31 ) )
return 0 ;
break;
default:
return - 2 ;
}
return 1 ;
}
static int F_29 ( T_1 * V_1 ,
const char * type , const char * V_32 )
{
if ( ! V_32 ) {
return 0 ;
}
if ( strcmp ( type , L_1 ) == 0 )
return F_30 ( V_1 , V_27 , V_32 ) ;
if ( strcmp ( type , L_2 ) == 0 )
return F_31 ( V_1 , V_27 , V_32 ) ;
return - 2 ;
}
