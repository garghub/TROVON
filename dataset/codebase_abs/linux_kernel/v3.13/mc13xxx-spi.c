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
struct V_27 * V_28 = F_9 ( & V_12 -> V_10 ) ;
int V_20 ;
V_26 = F_10 ( & V_12 -> V_10 , sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 )
return - V_30 ;
F_11 ( V_12 , V_26 ) ;
V_12 -> V_31 = V_32 | V_33 ;
V_26 -> V_10 = & V_12 -> V_10 ;
F_12 ( & V_26 -> V_34 ) ;
V_26 -> V_35 = F_13 ( & V_12 -> V_10 , & V_36 ,
& V_12 -> V_10 ,
& V_37 ) ;
if ( F_14 ( V_26 -> V_35 ) ) {
V_20 = F_15 ( V_26 -> V_35 ) ;
F_16 ( V_26 -> V_10 , L_1 ,
V_20 ) ;
F_11 ( V_12 , NULL ) ;
return V_20 ;
}
if ( V_12 -> V_10 . V_38 ) {
const struct V_39 * V_40 =
F_17 ( V_41 , & V_12 -> V_10 ) ;
V_26 -> V_42 = V_40 -> V_22 ;
} else {
const struct V_43 * V_44 = F_18 ( V_12 ) ;
V_26 -> V_42 = ( void * ) V_44 -> V_45 ;
}
return F_19 ( V_26 , V_28 , V_12 -> V_46 ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_26 * V_26 = F_21 ( V_12 ) ;
F_22 ( V_26 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_47 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_47 ) ;
}
