static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 . V_5 = NULL ;
V_2 -> V_4 . V_6 = 0 ;
V_2 -> V_4 . V_7 = 0 ;
V_2 -> V_4 . type = V_8 ;
F_3 ( & V_2 -> V_1 ) ;
V_1 -> V_5 = V_2 ;
V_1 -> V_9 = 0 ;
return 1 ;
}
static int F_4 ( T_1 * V_10 , T_1 * V_11 )
{
T_2 * V_12 , * V_13 ;
if ( ! F_1 ( V_10 ) )
return 0 ;
V_12 = V_11 -> V_5 ;
V_13 = V_10 -> V_5 ;
V_13 -> V_3 = V_12 -> V_3 ;
F_3 ( & V_13 -> V_1 ) ;
if ( ! F_5 ( & V_13 -> V_1 , & V_12 -> V_1 ) )
return 0 ;
if ( V_12 -> V_4 . V_5 )
{
if ( ! F_6 ( & V_13 -> V_4 ,
V_12 -> V_4 . V_5 , V_12 -> V_4 . V_6 ) )
return 0 ;
}
return 1 ;
}
static void F_7 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_5 ;
F_8 ( & V_2 -> V_1 ) ;
if ( V_2 -> V_4 . V_5 )
{
if ( V_2 -> V_4 . V_6 )
F_9 ( V_2 -> V_4 . V_5 , V_2 -> V_4 . V_6 ) ;
F_10 ( V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_5 = NULL ;
}
F_10 ( V_2 ) ;
}
static int F_11 ( T_1 * V_1 , T_3 * V_14 )
{
T_4 * V_15 = NULL ;
T_2 * V_2 = V_1 -> V_5 ;
if ( ! V_2 -> V_4 . V_5 )
return 0 ;
V_15 = F_12 ( & V_2 -> V_4 ) ;
if ( ! V_15 )
return 0 ;
F_13 ( V_14 , V_16 , V_15 ) ;
return 1 ;
}
static int F_14 ( T_5 * V_1 , const void * V_5 , T_6 V_17 )
{
T_2 * V_2 = V_1 -> V_18 -> V_5 ;
if ( ! F_15 ( & V_2 -> V_1 , V_5 , V_17 ) )
return 0 ;
return 1 ;
}
static int F_16 ( T_1 * V_1 , T_5 * V_19 )
{
T_2 * V_2 = V_1 -> V_5 ;
F_17 ( & V_2 -> V_1 , V_19 -> V_7 & ~ V_20 ) ;
F_18 ( V_19 , V_20 ) ;
V_19 -> V_21 = F_14 ;
return 1 ;
}
static int F_19 ( T_1 * V_1 , unsigned char * V_22 , T_6 * V_23 ,
T_5 * V_19 )
{
unsigned int V_24 ;
T_2 * V_2 = V_1 -> V_5 ;
int V_25 = F_20 ( V_19 ) ;
if ( V_25 < 0 )
return 0 ;
* V_23 = V_25 ;
if ( ! V_22 )
return 1 ;
if ( ! F_21 ( & V_2 -> V_1 , V_22 , & V_24 ) )
return 0 ;
* V_23 = ( T_6 ) V_24 ;
return 1 ;
}
static int F_22 ( T_1 * V_1 , int type , int V_26 , void * V_27 )
{
T_2 * V_2 = V_1 -> V_5 ;
T_4 * V_28 ;
switch ( type )
{
case V_29 :
if ( ( ! V_27 && V_26 > 0 ) || ( V_26 < - 1 ) )
return 0 ;
if ( ! F_6 ( & V_2 -> V_4 , V_27 , V_26 ) )
return 0 ;
break;
case V_30 :
V_2 -> V_3 = V_27 ;
break;
case V_31 :
V_28 = ( T_4 * ) V_1 -> V_14 -> V_14 . V_32 ;
if ( ! F_23 ( & V_2 -> V_1 , V_28 -> V_5 , V_28 -> V_6 , V_2 -> V_3 ,
V_1 -> V_33 ) )
return 0 ;
break;
default:
return - 2 ;
}
return 1 ;
}
static int F_24 ( T_1 * V_1 ,
const char * type , const char * V_34 )
{
if ( ! V_34 )
{
return 0 ;
}
if ( ! strcmp ( type , L_1 ) )
{
void * V_35 = ( void * ) V_34 ;
return F_22 ( V_1 , V_29 ,
- 1 , V_35 ) ;
}
if ( ! strcmp ( type , L_2 ) )
{
unsigned char * V_28 ;
int V_36 ;
long V_37 ;
V_28 = F_25 ( V_34 , & V_37 ) ;
if ( ! V_28 )
return 0 ;
V_36 = F_22 ( V_1 , V_29 , V_37 , V_28 ) ;
F_10 ( V_28 ) ;
return V_36 ;
}
return - 2 ;
}
