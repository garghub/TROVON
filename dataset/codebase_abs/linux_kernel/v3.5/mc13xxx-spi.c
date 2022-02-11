static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
unsigned char V_6 [ 4 ] = { * ( ( unsigned char * ) V_2 ) , 0 , 0 , 0 } ;
unsigned char V_7 [ 4 ] ;
unsigned char * V_8 = V_4 ;
struct V_9 * V_10 = V_1 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_13 V_14 = {
. V_15 = V_6 ,
. V_16 = V_7 ,
. V_17 = 4 ,
} ;
struct V_18 V_19 ;
int V_20 ;
if ( V_5 != 3 || V_3 != 1 )
return - V_21 ;
F_3 ( & V_19 ) ;
F_4 ( & V_14 , & V_19 ) ;
V_20 = F_5 ( V_12 , & V_19 ) ;
memcpy ( V_8 , & V_7 [ 1 ] , 3 ) ;
return V_20 ;
}
static int F_6 ( void * V_1 , const void * V_22 , T_1 V_23 )
{
struct V_9 * V_10 = V_1 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
if ( V_23 != 4 )
return - V_21 ;
return F_7 ( V_12 , V_22 , V_23 ) ;
}
static int F_8 ( struct V_11 * V_12 )
{
const struct V_24 * V_25 ;
struct V_26 * V_27 = F_9 ( V_12 -> V_10 . V_28 ) ;
struct V_29 * V_29 ;
struct V_30 * V_31 = F_10 ( & V_12 -> V_10 ) ;
int V_20 ;
V_25 = F_11 ( V_32 , & V_12 -> V_10 ) ;
if ( V_25 )
V_27 -> V_33 = & V_34 [ ( enum V_35 ) of_id->data];
int T_2 F_12 ( struct V_11 * V_12 )
{
struct V_29 * V_29 = F_13 ( & V_12 -> V_10 ) ;
F_14 ( V_29 ) ;
return 0 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_36 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_36 ) ;
}
