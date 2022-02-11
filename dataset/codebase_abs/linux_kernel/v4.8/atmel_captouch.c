static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_10 V_11 [ 2 ] ;
int V_12 ;
if ( V_5 > sizeof( V_2 -> V_13 ) - 2 )
return - V_14 ;
V_2 -> V_13 [ 0 ] = V_3 ;
V_2 -> V_13 [ 1 ] = V_5 ;
V_11 [ 0 ] . V_15 = V_7 -> V_15 ;
V_11 [ 0 ] . V_16 = 0 ;
V_11 [ 0 ] . V_17 = V_2 -> V_13 ;
V_11 [ 0 ] . V_5 = 2 ;
V_11 [ 1 ] . V_15 = V_7 -> V_15 ;
V_11 [ 1 ] . V_16 = V_18 ;
V_11 [ 1 ] . V_17 = V_2 -> V_13 ;
V_11 [ 1 ] . V_5 = V_5 + 2 ;
V_12 = F_2 ( V_7 -> V_19 , V_11 , F_3 ( V_11 ) ) ;
if ( V_12 != F_3 ( V_11 ) )
return V_12 < 0 ? V_12 : - V_20 ;
if ( V_2 -> V_13 [ 0 ] != V_3 ) {
F_4 ( V_9 ,
L_1 ,
V_2 -> V_13 [ 0 ] , V_3 ) ;
return - V_21 ;
}
memcpy ( V_4 , & V_2 -> V_13 [ 2 ] , V_5 ) ;
return 0 ;
}
static T_3 F_5 ( int V_22 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_8 * V_9 = & V_2 -> V_7 -> V_9 ;
int error ;
int V_23 ;
T_1 V_24 ;
T_1 V_25 ;
error = F_1 ( V_2 , V_26 , & V_24 , 1 ) ;
if ( error ) {
F_4 ( V_9 , L_2 , error ) ;
goto V_27;
}
F_6 ( V_9 , L_3 , V_28 , V_24 ) ;
V_25 = V_24 ^ V_2 -> V_29 ;
V_2 -> V_29 = V_24 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_30 ; V_23 ++ ) {
if ( V_25 & F_7 ( V_23 ) )
F_8 ( V_2 -> V_31 ,
V_2 -> V_32 [ V_23 ] ,
V_24 & F_7 ( V_23 ) ) ;
}
F_9 ( V_2 -> V_31 ) ;
V_27:
return V_33 ;
}
static int F_10 ( struct V_6 * V_7 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_36 * V_37 ;
int V_23 ;
int V_12 ;
if ( ! F_11 ( V_7 -> V_19 ,
V_38 |
V_39 |
V_40 ) ) {
F_4 ( V_9 , L_4 ) ;
return - V_14 ;
}
V_2 = F_12 ( V_9 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_7 = V_7 ;
F_13 ( V_7 , V_2 ) ;
V_12 = F_1 ( V_2 , V_26 ,
& V_2 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
if ( V_12 ) {
F_4 ( V_9 , L_5 , V_12 ) ;
return V_12 ;
}
V_2 -> V_31 = F_14 ( V_9 ) ;
if ( ! V_2 -> V_31 ) {
F_4 ( V_9 , L_6 ) ;
return - V_42 ;
}
V_2 -> V_31 -> V_35 . V_43 = V_44 ;
V_2 -> V_31 -> V_35 . V_45 = 0x880A ;
V_2 -> V_31 -> V_35 . V_46 = 0 ;
V_2 -> V_31 -> V_47 = L_7 ;
F_15 ( V_48 , V_2 -> V_31 -> V_49 ) ;
V_37 = V_9 -> V_50 ;
if ( ! V_37 ) {
F_4 ( V_9 , L_8 ) ;
return - V_14 ;
}
if ( F_16 ( V_37 , L_9 ) )
F_15 ( V_51 , V_2 -> V_31 -> V_49 ) ;
V_2 -> V_30 = F_17 ( V_37 , L_10 ) ;
if ( V_2 -> V_30 > V_52 )
V_2 -> V_30 = V_52 ;
V_12 = F_18 ( V_37 , L_11 ,
V_2 -> V_32 ,
V_2 -> V_30 ) ;
if ( V_12 ) {
F_4 ( V_9 ,
L_12 , V_12 ) ;
return V_12 ;
}
for ( V_23 = 0 ; V_23 < V_2 -> V_30 ; V_23 ++ )
F_15 ( V_2 -> V_32 [ V_23 ] , V_2 -> V_31 -> V_53 ) ;
V_2 -> V_31 -> V_54 = V_2 -> V_32 ;
V_2 -> V_31 -> V_55 = sizeof( V_2 -> V_32 [ 0 ] ) ;
V_2 -> V_31 -> V_56 = V_2 -> V_30 ;
V_12 = F_19 ( V_2 -> V_31 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_20 ( V_9 , V_7 -> V_22 ,
NULL , F_5 ,
V_57 ,
L_13 , V_2 ) ;
if ( V_12 ) {
F_4 ( V_9 , L_14 ,
V_7 -> V_22 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
