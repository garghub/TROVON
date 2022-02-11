static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 , V_6 , V_7 , V_8 , V_9 , V_10 = 0 , V_11 = 0xffffffff ;
V_6 = F_2 ( V_4 -> V_12 + V_13 ) ;
if ( V_6 & V_14 ) {
F_3 ( V_4 -> V_15 , V_4 -> V_16 , 0 ) ;
V_4 -> V_16 = 0 ;
}
if ( ( V_6 & V_17 ) && V_4 -> V_16 == 0 ) {
V_7 = F_2 ( V_4 -> V_12 + V_18 ) & 0x3f ;
V_8 = V_7 * V_4 -> V_19 / 63 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_20 ; V_5 ++ ) {
V_9 = abs ( V_4 -> V_21 [ V_5 ] . V_8 - V_8 ) ;
if ( V_9 < V_11 ) {
V_11 = V_9 ;
V_10 = V_4 -> V_21 [ V_5 ] . V_10 ;
}
}
V_4 -> V_16 = V_10 ;
F_3 ( V_4 -> V_15 , V_4 -> V_16 , 1 ) ;
}
F_4 ( V_4 -> V_15 ) ;
F_5 ( V_6 , V_4 -> V_12 + V_13 ) ;
return V_22 ;
}
static int F_6 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_7 ( V_24 ) ;
int error ;
error = F_8 ( V_4 -> V_25 ) ;
if ( error )
return error ;
V_4 -> V_19 = F_9 ( V_4 -> V_25 ) * 2 / 3 ;
F_5 ( F_10 ( 2 ) | F_11 ( 1 ) | F_12 ( 1 ) |
F_13 ( 0 ) | F_14 ( 1 ) , V_4 -> V_12 + V_26 ) ;
F_5 ( V_14 | V_17 , V_4 -> V_12 + V_27 ) ;
return 0 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_7 ( V_24 ) ;
F_5 ( F_10 ( 2 ) | F_11 ( 1 ) | F_12 ( 1 ) |
F_13 ( 2 ) , V_4 -> V_12 + V_26 ) ;
F_5 ( 0 , V_4 -> V_12 + V_27 ) ;
F_16 ( V_4 -> V_25 ) ;
}
static int F_17 ( struct V_28 * V_24 ,
struct V_3 * V_4 )
{
struct V_29 * V_30 , * V_31 ;
int V_5 ;
int error ;
V_30 = V_24 -> V_32 ;
if ( ! V_30 )
return - V_33 ;
V_4 -> V_20 = F_18 ( V_30 ) ;
if ( V_4 -> V_20 == 0 ) {
F_19 ( V_24 , L_1 ) ;
return - V_33 ;
}
V_4 -> V_21 = F_20 ( V_24 , V_4 -> V_20 ,
sizeof( struct V_34 ) ,
V_35 ) ;
if ( ! V_4 -> V_21 )
return - V_36 ;
V_5 = 0 ;
F_21 (np, pp) {
struct V_34 * V_37 = & V_4 -> V_21 [ V_5 ] ;
T_2 V_38 ;
error = F_22 ( V_31 , L_2 , & V_38 ) ;
if ( error || V_38 != 0 ) {
F_19 ( V_24 , L_3 , V_31 -> V_39 ) ;
return - V_33 ;
}
error = F_22 ( V_31 , L_4 , & V_37 -> V_8 ) ;
if ( error ) {
F_19 ( V_24 , L_5 , V_31 -> V_39 ) ;
return - V_33 ;
}
error = F_22 ( V_31 , L_6 , & V_37 -> V_10 ) ;
if ( error ) {
F_19 ( V_24 , L_7 , V_31 -> V_39 ) ;
return - V_33 ;
}
V_5 ++ ;
}
return 0 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
struct V_28 * V_24 = & V_41 -> V_24 ;
int V_5 ;
int error ;
V_4 = F_24 ( V_24 , sizeof( struct V_3 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
error = F_17 ( V_24 , V_4 ) ;
if ( error )
return error ;
V_4 -> V_25 = F_25 ( V_24 , L_8 ) ;
if ( F_26 ( V_4 -> V_25 ) )
return F_27 ( V_4 -> V_25 ) ;
V_4 -> V_24 = V_24 ;
V_4 -> V_15 = F_28 ( V_24 ) ;
if ( ! V_4 -> V_15 )
return - V_36 ;
V_4 -> V_15 -> V_39 = V_41 -> V_39 ;
V_4 -> V_15 -> V_42 = L_9 ;
V_4 -> V_15 -> V_43 = F_6 ;
V_4 -> V_15 -> V_44 = F_15 ;
V_4 -> V_15 -> V_45 . V_46 = V_47 ;
V_4 -> V_15 -> V_45 . V_48 = 0x0001 ;
V_4 -> V_15 -> V_45 . V_49 = 0x0001 ;
V_4 -> V_15 -> V_45 . V_50 = 0x0100 ;
F_29 ( V_51 , V_4 -> V_15 -> V_52 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_20 ; V_5 ++ )
F_29 ( V_4 -> V_21 [ V_5 ] . V_10 , V_4 -> V_15 -> V_53 ) ;
F_30 ( V_4 -> V_15 , V_4 ) ;
V_4 -> V_12 = F_31 ( V_24 ,
F_32 ( V_41 , V_54 , 0 ) ) ;
if ( F_26 ( V_4 -> V_12 ) )
return F_27 ( V_4 -> V_12 ) ;
error = F_33 ( V_24 , F_34 ( V_41 , 0 ) ,
F_1 , 0 ,
L_10 , V_4 ) ;
if ( error )
return error ;
error = F_35 ( V_4 -> V_15 ) ;
if ( error )
return error ;
return 0 ;
}
