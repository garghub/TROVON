static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned int V_4 ;
T_2 V_5 , V_6 ;
V_4 = F_2 ( V_3 [ 0 ] & ( V_7 | V_8 ) ) ;
V_5 = F_3 ( & V_3 [ 1 ] ) ;
V_6 = F_3 ( & V_3 [ 3 ] ) ;
V_5 >>= V_4 - V_9 ;
V_6 >>= V_4 - V_9 ;
if ( V_10 )
V_5 = V_11 - V_5 ;
if ( V_12 )
V_6 = V_11 - V_6 ;
if ( V_3 [ 0 ] & V_13 )
F_4 ( V_2 -> V_14 , V_15 , V_3 [ 5 ] ) ;
F_4 ( V_2 -> V_14 , V_16 , V_5 ) ;
F_4 ( V_2 -> V_14 , V_17 , V_6 ) ;
F_5 ( V_2 -> V_14 , V_18 , V_3 [ 0 ] & V_19 ) ;
F_6 ( V_2 -> V_14 ) ;
}
static T_3 F_7 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
int V_22 ;
int error ;
char V_3 [ 6 ] ;
do {
V_22 = F_8 ( V_2 -> V_23 , V_3 , sizeof( V_3 ) ) ;
if ( V_22 != sizeof( V_3 ) ) {
error = V_22 < 0 ? V_22 : - V_24 ;
F_9 ( & V_2 -> V_23 -> V_25 ,
L_1 ,
error ) ;
break;
}
if ( V_3 [ 0 ] & 0x80 ) {
F_1 ( V_2 , V_3 ) ;
}
} while ( V_2 -> V_26 &&
V_2 -> V_27 && F_10 ( V_2 -> V_27 ) );
return V_28 ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_26 = true ;
F_12 () ;
F_13 ( V_2 -> V_23 -> V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_26 = false ;
F_12 () ;
F_15 ( V_2 -> V_23 -> V_20 ) ;
}
static int F_16 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_14 ( V_2 ) ;
}
static int F_19 ( struct V_30 * V_23 ,
const struct V_31 * V_32 )
{
struct V_33 * V_25 = & V_23 -> V_25 ;
struct V_1 * V_2 ;
struct V_29 * V_14 ;
int error ;
V_2 = F_20 ( V_25 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
F_9 ( V_25 , L_2 ) ;
return - V_35 ;
}
V_14 = F_21 ( V_25 ) ;
if ( ! V_14 ) {
F_9 ( V_25 , L_3 ) ;
return - V_35 ;
}
F_22 ( V_14 , V_36 , V_18 ) ;
F_23 ( V_14 , V_16 , 0 , V_11 , 0 , 0 ) ;
F_23 ( V_14 , V_17 , 0 , V_11 , 0 , 0 ) ;
F_23 ( V_14 , V_15 , 0 , 0xff , 0 , 0 ) ;
V_14 -> V_37 = V_23 -> V_37 ;
V_14 -> V_38 . V_39 = V_40 ;
V_14 -> V_41 = F_16 ;
V_14 -> V_42 = F_18 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_27 = F_24 ( V_25 , L_4 , V_43 ) ;
if ( F_25 ( V_2 -> V_27 ) )
return F_26 ( V_2 -> V_27 ) ;
F_27 ( V_23 , V_2 ) ;
F_28 ( V_14 , V_2 ) ;
error = F_29 ( V_25 , V_23 -> V_20 ,
NULL , F_7 ,
V_44 ,
V_23 -> V_37 , V_2 ) ;
if ( error ) {
F_9 ( V_25 , L_5 ,
error ) ;
return error ;
}
F_14 ( V_2 ) ;
error = F_30 ( V_14 ) ;
if ( error )
return error ;
return 0 ;
}
static int T_4 F_31 ( struct V_33 * V_25 )
{
struct V_30 * V_23 = F_32 ( V_25 ) ;
struct V_1 * V_2 = F_33 ( V_23 ) ;
struct V_29 * V_29 = V_2 -> V_14 ;
F_34 ( & V_29 -> V_45 ) ;
if ( V_29 -> V_46 )
F_14 ( V_2 ) ;
F_35 ( & V_29 -> V_45 ) ;
if ( F_36 ( & V_23 -> V_25 ) )
F_37 ( V_23 -> V_20 ) ;
return 0 ;
}
static int T_4 F_38 ( struct V_33 * V_25 )
{
struct V_30 * V_23 = F_32 ( V_25 ) ;
struct V_1 * V_2 = F_33 ( V_23 ) ;
struct V_29 * V_29 = V_2 -> V_14 ;
if ( F_36 ( & V_23 -> V_25 ) )
F_39 ( V_23 -> V_20 ) ;
F_34 ( & V_29 -> V_45 ) ;
if ( V_29 -> V_46 )
F_11 ( V_2 ) ;
F_35 ( & V_29 -> V_45 ) ;
return 0 ;
}
