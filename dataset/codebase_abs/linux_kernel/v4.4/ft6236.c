static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
int error ;
error = F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( error < 0 )
return error ;
if ( error != V_4 )
return - V_6 ;
return 0 ;
}
static T_2 F_3 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_11 * V_12 = & V_10 -> V_2 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 V_16 ;
T_1 V_17 ;
int V_18 , error ;
error = F_1 ( V_10 -> V_2 , 0 , sizeof( V_16 ) , & V_16 ) ;
if ( error ) {
F_4 ( V_12 , L_1 , error ) ;
return V_19 ;
}
V_17 = V_16 . V_17 & 0xf ;
if ( V_17 > V_20 ) {
F_5 ( V_12 ,
L_2 ,
V_17 , V_20 ) ;
V_17 = V_20 ;
}
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
struct V_21 * V_22 = & V_16 . V_23 [ V_18 ] ;
T_3 V_24 = ( ( V_22 -> V_25 & 0xf ) << 8 ) | V_16 . V_23 [ V_18 ] . V_26 ;
T_3 V_27 = ( ( V_22 -> V_28 & 0xf ) << 8 ) | V_16 . V_23 [ V_18 ] . V_29 ;
T_1 V_30 = V_22 -> V_30 >> 6 ;
T_1 V_31 = V_22 -> V_31 >> 4 ;
bool V_32 = ( V_30 == V_33 ||
V_30 == V_34 ) ;
F_6 ( V_14 , V_31 ) ;
F_7 ( V_14 , V_35 , V_32 ) ;
if ( ! V_32 )
continue;
if ( V_10 -> V_36 )
V_24 = V_10 -> V_37 - V_24 ;
if ( V_10 -> V_38 )
V_27 = V_10 -> V_39 - V_27 ;
if ( V_10 -> V_40 ) {
F_8 ( V_14 , V_41 , V_27 ) ;
F_8 ( V_14 , V_42 , V_24 ) ;
} else {
F_8 ( V_14 , V_41 , V_24 ) ;
F_8 ( V_14 , V_42 , V_27 ) ;
}
}
F_9 ( V_14 ) ;
F_10 ( V_14 ) ;
return V_19 ;
}
static T_1 F_11 ( struct V_9 * V_10 , T_1 V_3 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_43 = 0 ;
int error ;
error = F_1 ( V_2 , V_3 , 1 , & V_43 ) ;
if ( error )
F_5 ( & V_2 -> V_12 ,
L_3 , V_3 , error ) ;
return V_43 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_2 -> V_12 ;
F_5 ( V_12 , L_4 ,
F_11 ( V_10 , V_44 ) * 4 ) ;
F_5 ( V_12 , L_5 ,
F_11 ( V_10 , V_45 ) * 10 ) ;
F_5 ( V_12 , L_6 ,
F_11 ( V_10 , V_46 ) ,
F_11 ( V_10 , V_47 ) ) ;
F_5 ( V_12 , L_7 ,
F_11 ( V_10 , V_48 ) ) ;
F_5 ( V_12 , L_8 ,
F_11 ( V_10 , V_49 ) ) ;
F_5 ( V_12 , L_9 ,
F_11 ( V_10 , V_50 ) ) ;
F_5 ( V_12 , L_10 ,
F_11 ( V_10 , V_51 ) ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_52 )
return;
F_14 ( V_10 -> V_52 , 1 ) ;
F_15 ( 5000 , 20000 ) ;
F_14 ( V_10 -> V_52 , 0 ) ;
F_16 ( 300 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_53 * V_31 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
T_4 V_54 = 0 , V_55 = 0 ;
T_1 V_43 ;
int error ;
if ( ! F_18 ( V_2 -> V_56 , V_57 ) )
return - V_58 ;
if ( ! V_2 -> V_7 ) {
F_4 ( V_12 , L_11 ) ;
return - V_59 ;
}
V_10 = F_19 ( V_12 , sizeof( * V_10 ) , V_60 ) ;
if ( ! V_10 )
return - V_61 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_52 = F_20 ( V_12 , L_12 ,
V_62 ) ;
if ( F_21 ( V_10 -> V_52 ) ) {
error = F_22 ( V_10 -> V_52 ) ;
if ( error != - V_63 )
F_4 ( V_12 , L_13 , error ) ;
return error ;
}
F_13 ( V_10 ) ;
error = F_1 ( V_2 , 0x00 , 1 , & V_43 ) ;
if ( error ) {
F_4 ( V_12 , L_14 , error ) ;
return error ;
}
F_12 ( V_10 ) ;
V_14 = F_23 ( V_12 ) ;
if ( ! V_14 )
return - V_61 ;
V_10 -> V_14 = V_14 ;
V_14 -> V_64 = V_2 -> V_64 ;
V_14 -> V_31 . V_65 = V_66 ;
if ( F_24 ( V_12 , L_15 ,
& V_10 -> V_37 ) ||
F_24 ( V_12 , L_16 ,
& V_10 -> V_39 ) ) {
F_4 ( V_12 , L_17 ) ;
return - V_59 ;
}
F_24 ( V_12 , L_18 , & V_54 ) ;
F_24 ( V_12 , L_19 , & V_55 ) ;
V_10 -> V_36 = F_25 ( V_12 ,
L_20 ) ;
V_10 -> V_38 = F_25 ( V_12 ,
L_21 ) ;
V_10 -> V_40 = F_25 ( V_12 ,
L_22 ) ;
if ( V_10 -> V_40 ) {
F_26 ( V_14 , V_41 , 0 ,
V_10 -> V_39 , V_55 , 0 ) ;
F_26 ( V_14 , V_42 , 0 ,
V_10 -> V_37 , V_54 , 0 ) ;
} else {
F_26 ( V_14 , V_41 , 0 ,
V_10 -> V_37 , V_54 , 0 ) ;
F_26 ( V_14 , V_42 , 0 ,
V_10 -> V_39 , V_55 , 0 ) ;
}
error = F_27 ( V_14 , V_20 ,
V_67 | V_68 ) ;
if ( error )
return error ;
error = F_28 ( V_12 , V_2 -> V_7 , NULL ,
F_3 , V_69 ,
V_2 -> V_64 , V_10 ) ;
if ( error ) {
F_4 ( V_12 , L_23 , V_2 -> V_7 , error ) ;
return error ;
}
error = F_29 ( V_14 ) ;
if ( error ) {
F_4 ( V_12 , L_24 , error ) ;
return error ;
}
return 0 ;
}
