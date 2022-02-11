static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned long V_11 = V_12 ;
F_2 ( & V_13 ) ;
V_9 -> V_14 += ( V_11 - F_3 ( & V_9 -> V_15 , V_11 ) ) * V_16 ;
if ( V_9 -> V_14 > V_6 -> V_17 )
V_9 -> V_14 = V_6 -> V_17 ;
if ( V_9 -> V_14 >= V_6 -> V_18 ) {
V_9 -> V_14 -= V_6 -> V_18 ;
F_4 ( & V_13 ) ;
return true ;
}
F_4 ( & V_13 ) ;
return false ;
}
static T_1 F_5 ( T_1 V_19 )
{
if ( V_19 > 0xFFFFFFFF / ( V_20 * V_16 ) )
return ( V_19 / V_21 ) * V_20 * V_16 ;
return ( V_19 * V_20 * V_16 ) / V_21 ;
}
static int F_6 ( const struct V_22 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
if ( V_6 -> V_23 == 0
|| F_5 ( V_6 -> V_24 * V_6 -> V_23 ) < F_5 ( V_6 -> V_24 ) ) {
F_7 ( L_1 ,
V_6 -> V_24 , V_6 -> V_23 ) ;
return - V_25 ;
}
V_9 = F_8 ( sizeof( * V_9 ) , V_26 ) ;
if ( V_9 == NULL )
return - V_27 ;
V_6 -> V_10 = V_9 ;
if ( V_6 -> V_18 == 0 ) {
V_9 -> V_15 = V_12 ;
V_9 -> V_14 = F_5 ( V_6 -> V_24 * V_6 -> V_23 ) ;
V_6 -> V_17 = V_9 -> V_14 ;
V_6 -> V_18 = F_5 ( V_6 -> V_24 ) ;
}
return 0 ;
}
static void F_9 ( const struct V_28 * V_4 )
{
const struct V_5 * V_29 = V_4 -> V_7 ;
F_10 ( V_29 -> V_10 ) ;
}
static void F_11 ( void * V_30 , const void * V_31 )
{
const struct V_32 * V_33 = V_31 ;
struct V_5 V_34 = {
. V_24 = V_33 -> V_24 ,
. V_23 = V_33 -> V_23 ,
. V_15 = V_33 -> V_15 | ( unsigned long ) V_33 -> V_10 << 32 ,
. V_14 = V_33 -> V_14 ,
. V_17 = V_33 -> V_17 ,
. V_18 = V_33 -> V_18 ,
} ;
memcpy ( V_30 , & V_34 , sizeof( V_34 ) ) ;
}
static int F_12 ( void T_2 * V_30 , const void * V_31 )
{
const struct V_5 * V_34 = V_31 ;
struct V_32 V_33 = {
. V_24 = V_34 -> V_24 ,
. V_23 = V_34 -> V_23 ,
. V_15 = V_34 -> V_15 ,
. V_14 = V_34 -> V_14 ,
. V_17 = V_34 -> V_17 ,
. V_18 = V_34 -> V_18 ,
. V_10 = V_34 -> V_15 >> 32 ,
} ;
return F_13 ( V_30 , & V_33 , sizeof( V_33 ) ) ? - V_35 : 0 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_36 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_36 ) ;
}
