static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 ;
T_1 V_4 [ 10 ] , V_5 [ 1 ] = { 0 } ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_3 -> V_8 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 != sizeof( V_5 ) ) {
F_3 ( & V_3 -> V_8 -> V_9 ,
L_1 ,
V_10 , V_7 ) ;
return;
}
V_7 = F_4 ( V_3 -> V_8 , V_4 , sizeof( V_4 ) ) ;
if ( V_7 != sizeof( V_4 ) ) {
F_3 ( & V_3 -> V_8 -> V_9 ,
L_2 ,
V_10 , V_7 ) ;
return;
}
V_6 = V_4 [ 0 ] ;
if ( V_6 ) {
T_2 V_11 = ( V_4 [ 3 ] << 8 ) | V_4 [ 2 ] ;
T_2 V_12 = ( V_4 [ 5 ] << 8 ) | V_4 [ 4 ] ;
T_2 V_13 = ( V_4 [ 7 ] << 8 ) | V_4 [ 6 ] ;
T_2 V_14 = ( V_4 [ 9 ] << 8 ) | V_4 [ 8 ] ;
F_5 ( V_3 -> V_15 , V_16 , 1 ) ;
F_6 ( V_3 -> V_15 , V_17 , V_11 ) ;
F_6 ( V_3 -> V_15 , V_18 , V_12 ) ;
F_6 ( V_3 -> V_15 , V_19 , V_11 ) ;
F_6 ( V_3 -> V_15 , V_20 , V_12 ) ;
F_7 ( V_3 -> V_15 ) ;
if ( V_6 == 2 ) {
F_6 ( V_3 -> V_15 ,
V_19 , V_13 ) ;
F_6 ( V_3 -> V_15 ,
V_20 , V_14 ) ;
F_7 ( V_3 -> V_15 ) ;
}
} else {
F_5 ( V_3 -> V_15 , V_16 , 0 ) ;
}
F_8 ( V_3 -> V_15 ) ;
}
static T_3 F_9 ( int V_21 , void * V_22 )
{
struct V_1 * V_3 = V_22 ;
while ( ! V_3 -> V_23 ) {
F_1 ( V_3 ) ;
if ( V_3 -> V_24 -> V_25 () )
break;
F_10 ( 20 ) ;
}
return V_26 ;
}
static int F_11 ( struct V_27 * V_9 )
{
struct V_28 * V_8 = F_12 ( V_9 ) ;
if ( F_13 ( & V_8 -> V_9 ) )
F_14 ( V_8 -> V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_9 )
{
struct V_28 * V_8 = F_12 ( V_9 ) ;
if ( F_13 ( & V_8 -> V_9 ) )
F_16 ( V_8 -> V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_8 ,
const struct V_29 * V_30 )
{
const struct V_31 * V_32 =
F_18 ( & V_8 -> V_9 ) ;
struct V_1 * V_3 ;
struct V_33 * V_15 ;
int error ;
if ( ! V_32 ) {
F_3 ( & V_8 -> V_9 , L_3 ) ;
return - V_34 ;
}
V_3 = F_19 ( sizeof( * V_3 ) , V_35 ) ;
V_15 = F_20 () ;
if ( ! V_3 || ! V_15 ) {
F_3 ( & V_8 -> V_9 , L_4 ) ;
error = - V_36 ;
goto V_37;
}
V_3 -> V_8 = V_8 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_24 = V_32 ;
V_15 -> V_38 = V_8 -> V_38 ;
V_15 -> V_30 . V_39 = V_40 ;
V_15 -> V_9 . V_41 = & V_8 -> V_9 ;
F_21 ( V_42 , V_15 -> V_43 ) ;
F_21 ( V_44 , V_15 -> V_43 ) ;
F_21 ( V_16 , V_15 -> V_45 ) ;
F_22 ( V_15 , V_17 , 0 , V_32 -> V_46 , 0 , 0 ) ;
F_22 ( V_15 , V_18 , 0 , V_32 -> V_47 , 0 , 0 ) ;
F_22 ( V_15 , V_19 , 0 , V_32 -> V_46 , 0 , 0 ) ;
F_22 ( V_15 , V_20 , 0 , V_32 -> V_47 , 0 , 0 ) ;
F_23 ( V_15 , V_3 ) ;
error = F_24 ( V_8 -> V_21 , NULL , F_9 ,
V_48 | V_49 ,
V_8 -> V_38 , V_3 ) ;
if ( error ) {
F_3 ( & V_8 -> V_9 , L_5 ) ;
goto V_37;
}
error = F_25 ( V_15 ) ;
if ( error )
goto V_50;
F_26 ( V_8 , V_3 ) ;
F_27 ( & V_8 -> V_9 , 1 ) ;
return 0 ;
V_50:
F_28 ( V_8 -> V_21 , V_3 ) ;
V_37:
F_29 ( V_15 ) ;
F_30 ( V_3 ) ;
return error ;
}
static int F_31 ( struct V_28 * V_8 )
{
struct V_1 * V_3 = F_32 ( V_8 ) ;
F_27 ( & V_8 -> V_9 , 0 ) ;
V_3 -> V_23 = true ;
F_33 () ;
F_28 ( V_8 -> V_21 , V_3 ) ;
F_34 ( V_3 -> V_15 ) ;
F_30 ( V_3 ) ;
return 0 ;
}
