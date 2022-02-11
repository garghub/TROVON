static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 [ 2 ] = { V_7 , V_3 } ;
int V_8 ;
V_8 = F_2 ( V_5 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 != sizeof( V_6 ) ) {
F_3 ( & V_5 -> V_9 ,
L_1 , V_10 , V_8 ) ;
return ( V_8 < 0 ) ? V_8 : - V_11 ;
}
V_2 -> V_3 = V_3 ;
return 0 ;
}
static int F_4 ( struct V_12 * V_13 , T_2 V_14 ,
const void * V_15 , T_3 V_16 )
{
struct V_1 * V_2 =
F_5 ( V_13 , struct V_1 , V_13 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_17 = V_16 + 1 ;
int V_8 ;
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 || V_2 -> V_20 < V_17 ) {
if ( V_2 -> V_19 )
F_7 ( & V_5 -> V_9 , V_2 -> V_19 ) ;
V_2 -> V_20 = V_17 + V_21 ;
V_2 -> V_19 = F_8 ( & V_5 -> V_9 ,
V_2 -> V_20 ,
V_22 ) ;
if ( ! V_2 -> V_19 ) {
V_2 -> V_20 = 0 ;
V_8 = - V_23 ;
goto exit;
}
}
V_2 -> V_19 [ 0 ] = V_14 & 0xff ;
memcpy ( V_2 -> V_19 + 1 , V_15 , V_16 ) ;
if ( F_9 ( V_14 ) != V_2 -> V_3 ) {
V_8 = F_1 ( V_2 , F_9 ( V_14 ) ) ;
if ( V_8 )
goto exit;
}
V_8 = F_2 ( V_5 , V_2 -> V_19 , V_17 ) ;
if ( V_8 == V_17 )
V_8 = 0 ;
else if ( V_8 >= 0 )
V_8 = - V_11 ;
exit:
F_10 ( V_24 , & V_5 -> V_9 ,
L_2 ,
V_16 , V_14 , V_8 , ( int ) V_16 , V_15 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_8 ;
}
static int F_12 ( struct V_12 * V_13 , T_2 V_14 ,
void * V_15 , T_3 V_16 )
{
struct V_1 * V_2 =
F_5 ( V_13 , struct V_1 , V_13 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_25 = V_14 & 0xff ;
int V_8 ;
struct V_26 V_27 [] = {
{
. V_14 = V_5 -> V_14 ,
. V_16 = sizeof( V_25 ) ,
. V_15 = & V_25 ,
} ,
{
. V_14 = V_5 -> V_14 ,
. V_28 = V_29 ,
. V_16 = V_16 ,
. V_15 = V_15 ,
} ,
} ;
F_6 ( & V_2 -> V_18 ) ;
if ( F_9 ( V_14 ) != V_2 -> V_3 ) {
V_8 = F_1 ( V_2 , F_9 ( V_14 ) ) ;
if ( V_8 )
goto exit;
}
V_8 = F_13 ( V_5 -> V_30 , V_27 , F_14 ( V_27 ) ) ;
if ( V_8 == F_14 ( V_27 ) )
V_8 = 0 ;
else if ( V_8 >= 0 )
V_8 = - V_11 ;
exit:
F_10 ( V_24 , & V_5 -> V_9 ,
L_3 ,
V_16 , V_14 , V_8 , ( int ) V_16 , V_15 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_8 ;
}
static void F_15 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
F_16 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
}
static void F_17 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
F_18 ( & V_2 -> V_13 ) ;
}
static int F_19 ( struct V_4 * V_5 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 ;
struct V_35 * V_37 =
F_20 ( & V_5 -> V_9 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_8 ( & V_5 -> V_9 , sizeof( struct V_1 ) ,
V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_36 = & V_2 -> V_13 . V_36 ;
if ( ! V_5 -> V_9 . V_38 && V_37 )
* V_36 = * V_37 ;
V_36 -> V_39 = V_5 -> V_39 ;
F_10 ( V_24 , & V_5 -> V_9 , L_4 ,
F_21 ( & V_5 -> V_9 ) ) ;
if ( ! F_22 ( V_5 -> V_30 , V_40 ) ) {
F_3 ( & V_5 -> V_9 ,
L_5 ) ;
return - V_41 ;
}
V_2 -> V_32 [ 0 ] . V_42 = L_6 ;
V_2 -> V_32 [ 1 ] . V_42 = L_7 ;
error = F_23 ( & V_5 -> V_9 ,
F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
if ( error < 0 )
return error ;
error = F_24 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
if ( error < 0 )
return error ;
error = F_25 ( & V_5 -> V_9 ,
F_15 ,
V_2 ) ;
if ( error )
return error ;
F_26 ( V_5 -> V_9 . V_38 , L_8 ,
& V_2 -> V_43 ) ;
F_27 ( V_2 -> V_43 ) ;
V_2 -> V_5 = V_5 ;
F_28 ( & V_2 -> V_18 ) ;
V_2 -> V_13 . V_9 = & V_5 -> V_9 ;
V_2 -> V_13 . V_44 = L_9 ;
V_2 -> V_13 . V_45 = & V_46 ;
F_29 ( V_5 , V_2 ) ;
error = F_1 ( V_2 , 0 ) ;
if ( error ) {
F_3 ( & V_5 -> V_9 , L_10 ) ;
return error ;
}
F_30 ( & V_5 -> V_9 , L_11 ) ;
error = F_31 ( & V_2 -> V_13 ) ;
if ( error ) {
F_3 ( & V_5 -> V_9 , L_12 , error ) ;
return error ;
}
error = F_25 ( & V_5 -> V_9 ,
F_17 ,
V_2 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_32 ( struct V_47 * V_9 )
{
struct V_4 * V_5 = F_33 ( V_9 ) ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
int V_48 ;
V_48 = F_35 ( V_2 -> V_13 . V_49 , true ) ;
if ( V_48 )
F_36 ( V_9 , L_13 , V_48 ) ;
F_16 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
return V_48 ;
}
static int F_37 ( struct V_47 * V_9 )
{
struct V_4 * V_5 = F_33 ( V_9 ) ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
int V_48 ;
V_48 = F_24 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
if ( V_48 )
return V_48 ;
F_27 ( V_2 -> V_43 ) ;
V_48 = F_38 ( V_2 -> V_13 . V_49 , true ) ;
if ( V_48 )
F_36 ( V_9 , L_13 , V_48 ) ;
return V_48 ;
}
static int F_39 ( struct V_47 * V_9 )
{
struct V_4 * V_5 = F_33 ( V_9 ) ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
int V_48 ;
V_48 = F_35 ( V_2 -> V_13 . V_49 , false ) ;
if ( V_48 )
F_36 ( V_9 , L_13 , V_48 ) ;
F_16 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
return 0 ;
}
static int F_40 ( struct V_47 * V_9 )
{
struct V_4 * V_5 = F_33 ( V_9 ) ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
int V_48 ;
V_48 = F_24 ( F_14 ( V_2 -> V_32 ) ,
V_2 -> V_32 ) ;
if ( V_48 )
return V_48 ;
F_27 ( V_2 -> V_43 ) ;
V_48 = F_38 ( V_2 -> V_13 . V_49 , false ) ;
if ( V_48 )
F_36 ( V_9 , L_13 , V_48 ) ;
return 0 ;
}
