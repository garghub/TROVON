static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_7 , V_8 ;
T_1 V_9 , V_10 = 0xffffffff ;
int V_11 = 0 ;
V_8 = F_2 ( V_4 -> V_12 , & V_7 ) ;
if ( F_3 ( V_8 < 0 ) ) {
V_7 = V_4 -> V_13 ;
} else {
for ( V_6 = 0 ; V_6 < V_4 -> V_14 ; V_6 ++ ) {
V_9 = abs ( V_4 -> V_15 [ V_6 ] . V_16 - V_7 ) ;
if ( V_9 < V_10 ) {
V_10 = V_9 ;
V_11 = V_4 -> V_15 [ V_6 ] . V_11 ;
}
}
}
if ( abs ( V_4 -> V_13 - V_7 ) < V_10 )
V_11 = 0 ;
if ( V_4 -> V_17 && V_4 -> V_17 != V_11 )
F_4 ( V_2 -> V_18 , V_4 -> V_17 , 0 ) ;
if ( V_11 )
F_4 ( V_2 -> V_18 , V_11 , 1 ) ;
F_5 ( V_2 -> V_18 ) ;
V_4 -> V_17 = V_11 ;
}
static int F_6 ( struct V_19 * V_2 , struct V_3 * V_4 )
{
struct V_20 * V_15 ;
struct V_21 * V_22 ;
int V_6 ;
V_4 -> V_14 = F_7 ( V_2 ) ;
if ( V_4 -> V_14 == 0 ) {
F_8 ( V_2 , L_1 ) ;
return - V_23 ;
}
V_15 = F_9 ( V_2 , V_4 -> V_14 , sizeof( * V_15 ) , V_24 ) ;
if ( ! V_15 )
return - V_25 ;
V_6 = 0 ;
F_10 (dev, child) {
if ( F_11 ( V_22 , L_2 ,
& V_15 [ V_6 ] . V_16 ) ) {
F_8 ( V_2 , L_3 ) ;
F_12 ( V_22 ) ;
return - V_23 ;
}
V_15 [ V_6 ] . V_16 /= 1000 ;
if ( F_11 ( V_22 , L_4 ,
& V_15 [ V_6 ] . V_11 ) ) {
F_8 ( V_2 , L_5 ) ;
F_12 ( V_22 ) ;
return - V_23 ;
}
V_6 ++ ;
}
V_4 -> V_15 = V_15 ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_19 * V_2 = & V_27 -> V_2 ;
struct V_3 * V_4 ;
struct V_1 * V_28 ;
struct V_29 * V_18 ;
enum V_30 type ;
int V_6 , V_7 ;
int error ;
V_4 = F_14 ( V_2 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_12 = F_15 ( V_2 , L_6 ) ;
if ( F_16 ( V_4 -> V_12 ) )
return F_17 ( V_4 -> V_12 ) ;
if ( ! V_4 -> V_12 -> V_31 )
return - V_32 ;
error = F_18 ( V_4 -> V_12 , & type ) ;
if ( error < 0 )
return error ;
if ( type != V_33 ) {
F_8 ( V_2 , L_7 , type ) ;
return - V_23 ;
}
if ( F_19 ( V_2 , L_8 ,
& V_4 -> V_13 ) ) {
F_8 ( V_2 , L_9 ) ;
return - V_23 ;
}
V_4 -> V_13 /= 1000 ;
error = F_6 ( V_2 , V_4 ) ;
if ( error )
return error ;
F_20 ( V_27 , V_4 ) ;
V_28 = F_21 ( V_2 ) ;
if ( ! V_28 ) {
F_8 ( V_2 , L_10 ) ;
return - V_25 ;
}
if ( ! F_19 ( V_2 , L_11 , & V_7 ) )
V_28 -> V_34 = V_7 ;
V_28 -> V_35 = F_1 ;
V_28 -> V_5 = V_4 ;
V_18 = V_28 -> V_18 ;
V_18 -> V_36 = V_27 -> V_36 ;
V_18 -> V_37 = L_12 ;
V_18 -> V_38 . V_39 = V_40 ;
V_18 -> V_38 . V_41 = 0x0001 ;
V_18 -> V_38 . V_42 = 0x0001 ;
V_18 -> V_38 . V_43 = 0x0100 ;
F_22 ( V_44 , V_18 -> V_45 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_14 ; V_6 ++ )
F_22 ( V_4 -> V_15 [ V_6 ] . V_11 , V_18 -> V_46 ) ;
if ( F_23 ( V_2 , L_13 ) )
F_22 ( V_47 , V_18 -> V_45 ) ;
error = F_24 ( V_28 ) ;
if ( error ) {
F_8 ( V_2 , L_14 , error ) ;
return error ;
}
return 0 ;
}
