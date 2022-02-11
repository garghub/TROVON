static void
F_1 ( void * V_1 , void T_1 * V_2 , T_2 V_3 )
{
F_2 ( V_2 ) ;
}
static void T_1 *
F_3 ( void * V_1 , T_3 V_4 , T_2 V_3 )
{
return F_4 ( V_4 , V_3 ) ;
}
static int
F_5 ( void * V_1 , bool V_5 , void * V_6 , T_2 V_3 , void * * V_7 )
{
return F_6 ( V_1 , V_5 , V_6 , V_3 , V_7 ) ;
}
static int
F_7 ( void * V_1 )
{
return F_8 ( V_1 ) ;
}
static int
F_9 ( void * V_1 )
{
return F_10 ( V_1 , true ) ;
}
static void
F_11 ( void * V_1 )
{
struct V_8 * V_9 = V_1 ;
F_10 ( F_12 ( V_9 ) , false ) ;
F_13 ( & V_9 -> V_10 , 1 ) ;
F_14 ( NULL , & V_9 ) ;
}
static int
F_15 ( const void * V_11 , T_2 V_12 , const void * V_6 , T_2 V_3 )
{
const union {
struct V_13 V_14 ;
} * args = V_11 ;
T_4 V_15 ;
if ( V_12 == sizeof( args -> V_14 ) && args -> V_14 . V_16 == 0 ) {
V_15 = args -> V_14 . V_15 ;
} else {
F_16 ( 1 ) ;
return V_17 ;
}
switch ( V_15 ) {
case V_18 :
return F_17 ( V_11 , V_12 , V_6 , V_3 ) ;
case V_19 :
return F_18 ( V_11 , V_12 , V_6 , V_3 ) ;
default:
F_16 ( 1 ) ;
break;
}
return V_17 ;
}
static int
F_19 ( const char * V_20 , T_3 V_21 , const char * V_22 ,
const char * V_23 , void * * V_24 )
{
struct V_25 * V_9 ;
int V_26 ;
V_26 = F_20 ( V_20 , V_21 , V_22 , V_23 , & V_9 ) ;
* V_24 = V_9 ;
if ( V_26 )
return V_26 ;
V_9 -> V_27 = F_15 ;
return 0 ;
}
