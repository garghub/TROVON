static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
V_4 -> V_7 = false ;
V_4 -> V_8 = V_9 ;
V_6 = F_2 ( V_4 -> V_10 , V_4 -> V_11 , V_4 -> V_12 , V_4 -> V_12 ) ;
if ( V_6 )
F_3 ( V_4 -> V_2 , L_1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_4 -> V_10 , V_4 -> V_11 , V_4 -> V_12 , 0 ) ;
if ( V_6 )
F_3 ( V_4 -> V_2 , L_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_15 = F_6 ( V_4 -> V_16 + V_17 ) ;
T_1 V_18 = F_6 ( V_4 -> V_16 + V_19 ) ;
bool V_7 = V_15 & V_20 ;
if ( V_7 ) {
if ( V_4 -> V_8 ) {
V_4 -> V_8 -- ;
return;
}
if ( ! V_4 -> V_7 ) {
F_7 ( V_13 , V_21 , 1 ) ;
V_4 -> V_7 = true ;
}
V_15 = ( ( ~ V_15 ) >> 4 ) & V_22 ;
V_18 = ( ( ~ V_18 ) >> 4 ) & V_22 ;
F_8 ( V_13 , V_23 , V_15 ) ;
F_8 ( V_13 , V_24 , V_18 ) ;
F_9 ( V_13 ) ;
} else if ( V_4 -> V_7 ) {
V_4 -> V_7 = false ;
V_4 -> V_8 = V_9 ;
F_7 ( V_13 , V_21 , 0 ) ;
F_9 ( V_13 ) ;
}
}
static int F_10 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
struct V_27 * V_2 = & V_26 -> V_2 ;
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_28 * V_31 ;
T_2 V_11 , V_12 ;
int error ;
V_31 = F_11 ( V_29 , L_3 , 0 ) ;
if ( ! V_31 ) {
F_12 ( V_2 , L_4 ) ;
return - V_32 ;
}
V_4 -> V_10 = F_13 ( V_31 ) ;
F_14 ( V_31 ) ;
if ( F_15 ( V_4 -> V_10 ) ) {
F_12 ( V_2 , L_5 ) ;
return F_16 ( V_4 -> V_10 ) ;
}
error = F_17 ( V_29 , L_3 , 1 , & V_11 ) ;
if ( error < 0 ) {
F_12 ( V_2 , L_6 ) ;
return error ;
}
V_4 -> V_11 = V_11 ;
error = F_17 ( V_29 , L_3 , 2 , & V_12 ) ;
if ( error < 0 ) {
F_12 ( V_2 , L_7 ) ;
return error ;
}
V_4 -> V_12 = F_18 ( V_12 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_33 ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int error ;
V_4 = F_20 ( & V_26 -> V_2 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
error = F_10 ( V_26 , V_4 ) ;
if ( error )
return error ;
V_35 = F_21 ( V_26 , V_38 , 0 ) ;
V_4 -> V_16 = F_22 ( & V_26 -> V_2 , V_35 ) ;
if ( F_15 ( V_4 -> V_16 ) )
return F_16 ( V_4 -> V_16 ) ;
V_33 = F_23 ( & V_26 -> V_2 ) ;
if ( ! V_33 )
return - V_37 ;
snprintf ( V_4 -> V_39 , sizeof( V_4 -> V_39 ) , L_8 , F_24 ( & V_26 -> V_2 ) ) ;
V_4 -> V_33 = V_33 ;
V_4 -> V_2 = & V_26 -> V_2 ;
V_33 -> V_5 = V_4 ;
V_33 -> V_40 = V_41 ;
V_33 -> V_42 = F_1 ;
V_33 -> V_43 = F_4 ;
V_33 -> V_44 = F_5 ;
V_33 -> V_14 -> V_45 = L_9 ;
V_33 -> V_14 -> V_39 = V_4 -> V_39 ;
F_25 ( V_33 -> V_14 , V_46 , V_21 ) ;
F_26 ( V_33 -> V_14 , V_23 , 0 , V_22 , 0 , 0 ) ;
F_26 ( V_33 -> V_14 , V_24 , 0 , V_22 , 0 , 0 ) ;
error = F_27 ( V_33 ) ;
if ( error ) {
F_12 ( & V_26 -> V_2 ,
L_10 ,
error ) ;
return error ;
}
return 0 ;
}
