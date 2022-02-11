static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned V_6 , V_7 , V_8 , V_9 ;
T_1 V_10 ;
V_10 = F_2 ( F_3 ( V_2 -> V_11 , V_3 ) ) ;
V_7 = V_10 ^ V_2 -> V_12 [ V_3 ] ;
V_2 -> V_12 [ V_3 ] = V_10 ;
for ( V_6 = 0 ; V_7 ; V_6 ++ , V_7 >>= 1 ) {
if ( V_7 & 1 ) {
V_8 = F_4 ( V_6 , V_3 ,
V_2 -> V_13 ) ;
V_9 = V_2 -> V_14 [ V_8 ] ;
F_5 ( V_5 , V_15 , V_16 , V_8 ) ;
F_6 ( V_5 , V_9 , V_10 & ( 1 << V_6 ) ) ;
}
}
}
static T_2 F_7 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ )
F_1 ( V_2 , V_19 ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_10 ( V_2 -> V_5 ) ;
return V_21 ;
}
static int F_11 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int error ;
error = F_13 ( V_2 -> V_23 ) ;
if ( error )
return error ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
}
static int F_16 ( struct V_24 * V_22 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_22 -> V_27 ;
T_3 V_28 = 0 , V_29 = 0 ;
int V_30 ;
V_30 = F_17 ( V_22 , & V_28 , & V_29 ) ;
if ( V_30 )
return V_30 ;
if ( V_28 != V_29 ) {
F_18 ( V_22 , L_1 ) ;
return - V_31 ;
}
V_2 -> V_20 = V_28 ;
V_2 -> V_13 = F_19 ( V_29 ) ;
F_20 ( V_26 , L_2 , & V_2 -> V_32 ) ;
F_20 ( V_26 , L_3 , & V_2 -> V_33 ) ;
if ( ! V_2 -> V_32 || ! V_2 -> V_33 ) {
F_18 ( V_22 , L_4 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_36 * V_37 ;
T_4 V_38 ;
int error ;
int V_17 ;
V_37 = F_22 ( V_35 , V_39 , 0 ) ;
if ( ! V_37 ) {
F_18 ( & V_35 -> V_22 , L_5 ) ;
return - V_31 ;
}
V_17 = F_23 ( V_35 , 0 ) ;
if ( V_17 < 0 || V_17 >= V_40 ) {
F_18 ( & V_35 -> V_22 , L_6 ) ;
return - V_31 ;
}
V_2 = F_24 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
F_18 ( & V_35 -> V_22 , L_7 ) ;
return - V_42 ;
}
error = F_16 ( & V_35 -> V_22 , V_2 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_8 ) ;
goto V_43;
}
V_38 = sizeof( V_2 -> V_14 [ 0 ] ) *
( V_2 -> V_20 << V_2 -> V_13 ) ;
V_2 -> V_14 = F_24 ( V_38 , V_41 ) ;
if ( ! V_2 -> V_14 ) {
F_18 ( & V_35 -> V_22 , L_9 ) ;
error = - V_42 ;
goto V_43;
}
V_2 -> V_5 = V_5 = F_25 () ;
if ( ! V_5 ) {
F_18 ( & V_35 -> V_22 , L_10 ) ;
error = - V_42 ;
goto V_44;
}
V_5 -> V_45 = V_35 -> V_45 ;
V_5 -> V_46 = L_11 ;
V_5 -> V_47 . V_48 = 0x0001 ;
V_5 -> V_47 . V_49 = 0x0001 ;
V_5 -> V_47 . V_50 = 0x0100 ;
V_5 -> V_51 = F_11 ;
V_5 -> V_52 = F_14 ;
V_5 -> V_22 . V_53 = & V_35 -> V_22 ;
F_26 ( V_5 , V_15 , V_16 ) ;
error = F_27 ( NULL , NULL ,
V_2 -> V_20 ,
V_2 -> V_20 ,
V_2 -> V_14 , V_2 -> V_5 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_12 ) ;
goto V_54;
}
F_28 ( V_2 -> V_5 , V_2 ) ;
V_2 -> V_55 = F_29 ( V_37 -> V_56 , F_30 ( V_37 ) ,
V_35 -> V_45 ) ;
if ( ! V_2 -> V_55 ) {
F_18 ( & V_35 -> V_22 , L_13 ) ;
error = - V_57 ;
goto V_54;
}
V_2 -> V_11 = F_31 ( V_2 -> V_55 -> V_56 ,
F_30 ( V_2 -> V_55 ) ) ;
if ( ! V_2 -> V_11 ) {
F_18 ( & V_35 -> V_22 , L_14 ) ;
error = - V_57 ;
goto V_58;
}
V_2 -> V_23 = F_32 ( & V_35 -> V_22 , NULL ) ;
if ( F_33 ( V_2 -> V_23 ) ) {
F_18 ( & V_35 -> V_22 , L_15 ) ;
error = F_34 ( V_2 -> V_23 ) ;
goto V_59;
}
error = F_13 ( V_2 -> V_23 ) ;
if ( error )
goto V_60;
F_8 ( V_2 -> V_32 , F_35 ( V_2 -> V_11 ) ) ;
F_8 ( V_2 -> V_33 , F_36 ( V_2 -> V_11 ) ) ;
F_8 ( V_61 ,
F_37 ( V_2 -> V_11 ) ) ;
F_8 ( V_2 -> V_20 ,
F_38 ( V_2 -> V_11 ) ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
error = F_39 ( V_17 , F_7 , 0 , V_35 -> V_45 , V_2 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_16 ) ;
goto V_60;
}
error = F_40 ( V_2 -> V_5 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_17 ) ;
goto V_62;
}
F_41 ( V_35 , V_2 ) ;
return 0 ;
V_62:
F_42 ( V_17 , V_2 ) ;
V_60:
F_43 ( V_2 -> V_23 ) ;
V_59:
F_44 ( V_2 -> V_11 ) ;
V_58:
F_45 ( V_2 -> V_55 -> V_56 ,
F_30 ( V_2 -> V_55 ) ) ;
V_54:
F_46 ( V_2 -> V_5 ) ;
V_44:
F_47 ( V_2 -> V_14 ) ;
V_43:
F_47 ( V_2 ) ;
return error ;
}
static int F_48 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_49 ( V_35 ) ;
F_42 ( F_23 ( V_35 , 0 ) , V_2 ) ;
F_43 ( V_2 -> V_23 ) ;
F_44 ( V_2 -> V_11 ) ;
F_45 ( V_2 -> V_55 -> V_56 ,
F_30 ( V_2 -> V_55 ) ) ;
F_50 ( V_2 -> V_5 ) ;
F_47 ( V_2 -> V_14 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_24 * V_22 )
{
struct V_34 * V_35 = F_52 ( V_22 ) ;
struct V_1 * V_2 = F_49 ( V_35 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_53 ( & V_5 -> V_63 ) ;
if ( V_5 -> V_64 ) {
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
}
F_54 ( & V_5 -> V_63 ) ;
return 0 ;
}
static int F_55 ( struct V_24 * V_22 )
{
struct V_34 * V_35 = F_52 ( V_22 ) ;
struct V_1 * V_2 = F_49 ( V_35 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_65 = 0 ;
F_53 ( & V_5 -> V_63 ) ;
if ( V_5 -> V_64 ) {
V_65 = F_13 ( V_2 -> V_23 ) ;
if ( V_65 == 0 )
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
}
F_54 ( & V_5 -> V_63 ) ;
return V_65 ;
}
