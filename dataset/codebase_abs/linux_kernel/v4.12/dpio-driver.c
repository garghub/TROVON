static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_3 ( V_6 -> V_7 ) ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = V_9 -> V_12 [ 0 ] ;
F_5 ( V_11 -> V_13 -> V_11 , NULL ) ;
}
static int F_6 ( struct V_8 * V_9 , int V_14 )
{
struct V_5 * V_6 ;
int error ;
struct V_10 * V_11 ;
T_2 V_15 ;
V_6 = F_2 ( & V_9 -> V_4 ) ;
V_11 = V_9 -> V_12 [ 0 ] ;
error = F_7 ( & V_9 -> V_4 ,
V_11 -> V_13 -> V_11 ,
F_1 ,
0 ,
F_8 ( & V_9 -> V_4 ) ,
& V_9 -> V_4 ) ;
if ( error < 0 ) {
F_9 ( & V_9 -> V_4 ,
L_1 ,
error ) ;
return error ;
}
F_10 ( & V_15 ) ;
F_11 ( V_14 , & V_15 ) ;
if ( F_5 ( V_11 -> V_13 -> V_11 , & V_15 ) )
F_9 ( & V_9 -> V_4 ,
L_2 ,
V_11 -> V_13 -> V_11 , V_14 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_16 V_17 ;
struct V_18 V_19 ;
struct V_5 * V_6 ;
int V_20 = - V_21 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
static int V_22 = - 1 ;
V_6 = F_13 ( V_4 , sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
goto V_24;
F_14 ( V_4 , V_6 ) ;
V_20 = F_15 ( V_9 , 0 , & V_9 -> V_25 ) ;
if ( V_20 ) {
F_16 ( V_4 , L_3 ) ;
V_20 = - V_26 ;
goto V_27;
}
V_20 = F_17 ( V_9 -> V_25 , 0 , V_9 -> V_28 . V_29 ,
& V_9 -> V_30 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_4 ) ;
goto V_31;
}
V_20 = F_18 ( V_9 -> V_25 , 0 , V_9 -> V_30 ,
& V_17 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_5 , V_20 ) ;
goto V_32;
}
V_19 . V_33 = V_17 . V_34 ;
V_20 = F_19 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_6 , V_20 ) ;
goto V_32;
}
V_19 . V_35 = V_17 . V_36 ? 1 : 0 ;
V_19 . V_37 = V_17 . V_36 == 8 ? 1 : 0 ;
V_19 . V_38 = V_9 -> V_28 . V_29 ;
if ( V_22 == - 1 )
V_22 = F_20 ( V_39 ) ;
else
V_22 = F_21 ( V_22 , V_39 ) ;
if ( ! F_22 ( V_22 ) ) {
F_9 ( V_4 , L_7 ) ;
V_20 = - V_40 ;
goto V_41;
}
V_19 . V_14 = V_22 ;
V_19 . V_42 = F_23 ( V_9 -> V_43 [ 1 ] . V_44 ,
F_24 ( & V_9 -> V_43 [ 1 ] ) ) ;
V_19 . V_45 = F_25 ( V_9 -> V_43 [ 1 ] . V_44 ,
F_24 ( & V_9 -> V_43 [ 1 ] ) ) ;
V_20 = F_26 ( V_9 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_8 , V_20 ) ;
goto V_41;
}
V_20 = F_6 ( V_9 , V_19 . V_14 ) ;
if ( V_20 )
goto V_46;
V_6 -> V_7 = F_27 ( & V_19 ) ;
if ( ! V_6 -> V_7 ) {
F_9 ( V_4 , L_9 ) ;
goto V_47;
}
F_28 ( V_4 , L_10 ) ;
F_16 ( V_4 , L_11 ,
V_19 . V_35 ) ;
F_29 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
F_30 ( V_9 -> V_25 ) ;
return 0 ;
V_47:
F_4 ( V_9 ) ;
V_46:
F_31 ( V_9 ) ;
V_41:
F_32 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
V_32:
F_29 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
V_31:
F_30 ( V_9 -> V_25 ) ;
V_27:
F_14 ( V_4 , NULL ) ;
V_24:
return V_20 ;
}
static void F_33 ( struct V_8 * V_9 )
{
F_4 ( V_9 ) ;
F_31 ( V_9 ) ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_20 ;
V_4 = & V_9 -> V_4 ;
V_6 = F_2 ( V_4 ) ;
F_35 ( V_6 -> V_7 ) ;
F_33 ( V_9 ) ;
V_20 = F_15 ( V_9 , 0 , & V_9 -> V_25 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_3 ) ;
goto V_27;
}
V_20 = F_17 ( V_9 -> V_25 , 0 , V_9 -> V_28 . V_29 ,
& V_9 -> V_30 ) ;
if ( V_20 ) {
F_9 ( V_4 , L_4 ) ;
goto V_31;
}
F_32 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
F_29 ( V_9 -> V_25 , 0 , V_9 -> V_30 ) ;
F_30 ( V_9 -> V_25 ) ;
F_14 ( V_4 , NULL ) ;
return 0 ;
V_31:
F_30 ( V_9 -> V_25 ) ;
V_27:
return V_20 ;
}
static int F_36 ( void )
{
return F_37 ( & V_48 ) ;
}
static void F_38 ( void )
{
F_39 ( & V_48 ) ;
}
