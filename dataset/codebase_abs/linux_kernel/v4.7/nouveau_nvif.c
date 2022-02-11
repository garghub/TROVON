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
F_12 ( & V_9 ) ;
}
static int
F_13 ( const void * V_10 , T_2 V_11 , const void * V_6 , T_2 V_3 )
{
const union {
struct V_12 V_13 ;
} * args = V_10 ;
T_4 V_14 ;
if ( V_11 == sizeof( args -> V_13 ) && args -> V_13 . V_15 == 0 ) {
V_14 = args -> V_13 . V_14 ;
} else {
F_14 ( 1 ) ;
return V_16 ;
}
switch ( V_14 ) {
case V_17 :
return F_15 ( V_10 , V_11 , V_6 , V_3 ) ;
case V_18 :
return F_16 ( V_10 , V_11 , V_6 , V_3 ) ;
default:
F_14 ( 1 ) ;
break;
}
return V_16 ;
}
static int
F_17 ( const char * V_19 , T_3 V_20 , const char * V_21 ,
const char * V_22 , void * * V_23 )
{
struct V_8 * V_9 ;
int V_24 ;
V_24 = F_18 ( V_19 , V_20 , V_21 , V_22 , & V_9 ) ;
* V_23 = V_9 ;
if ( V_24 )
return V_24 ;
V_9 -> V_25 = F_13 ;
return 0 ;
}
