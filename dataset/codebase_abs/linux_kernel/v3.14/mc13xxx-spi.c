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
const char * V_2 = V_22 ;
if ( V_23 != 4 )
return - V_21 ;
if ( * V_2 == V_24 || * V_2 == V_25 )
F_7 ( V_12 , V_22 , V_23 ) ;
return F_7 ( V_12 , V_22 , V_23 ) ;
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_26 * V_26 ;
int V_20 ;
V_26 = F_9 ( & V_12 -> V_10 , sizeof( * V_26 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
F_10 ( & V_12 -> V_10 , V_26 ) ;
V_12 -> V_29 = V_30 | V_31 ;
V_26 -> V_32 = V_12 -> V_32 ;
V_26 -> V_33 = F_11 ( & V_12 -> V_10 , & V_34 ,
& V_12 -> V_10 ,
& V_35 ) ;
if ( F_12 ( V_26 -> V_33 ) ) {
V_20 = F_13 ( V_26 -> V_33 ) ;
F_14 ( & V_12 -> V_10 , L_1 , V_20 ) ;
return V_20 ;
}
if ( V_12 -> V_10 . V_36 ) {
const struct V_37 * V_38 =
F_15 ( V_39 , & V_12 -> V_10 ) ;
V_26 -> V_40 = V_38 -> V_22 ;
} else {
const struct V_41 * V_42 = F_16 ( V_12 ) ;
V_26 -> V_40 = ( void * ) V_42 -> V_43 ;
}
return F_17 ( & V_12 -> V_10 ) ;
}
static int F_18 ( struct V_11 * V_12 )
{
return F_19 ( & V_12 -> V_10 ) ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_44 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_44 ) ;
}
