static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 ;
int V_9 ;
V_8 = ~ F_2 ( V_4 -> V_10 ) >> 24 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_4 -> V_11 ) ; V_9 ++ ) {
if ( V_8 & ( 1U << V_9 ) ) {
if ( ++ V_4 -> V_12 [ V_9 ] == V_13 ) {
F_4 ( V_7 , V_14 , V_15 , V_9 ) ;
F_5 ( V_7 , V_4 -> V_11 [ V_9 ] , 1 ) ;
F_6 ( V_7 ) ;
}
} else {
if ( V_4 -> V_12 [ V_9 ] >= V_13 ) {
F_4 ( V_7 , V_14 , V_15 , V_9 ) ;
F_5 ( V_7 , V_4 -> V_11 [ V_9 ] , 0 ) ;
F_6 ( V_7 ) ;
}
V_4 -> V_12 [ V_9 ] = 0 ;
}
}
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_3 * V_4 ;
struct V_1 * V_18 ;
struct V_6 * V_7 ;
struct V_19 * V_20 ;
int error , V_9 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_21 ) ;
V_18 = F_9 () ;
if ( ! V_4 || ! V_18 ) {
error = - V_22 ;
goto V_23;
}
memcpy ( V_4 -> V_11 , V_24 , sizeof( V_4 -> V_11 ) ) ;
V_18 -> V_5 = V_4 ;
V_18 -> V_25 = F_1 ;
V_18 -> V_26 = V_27 ;
V_7 = V_18 -> V_7 ;
V_7 -> V_28 = L_1 ;
V_7 -> V_29 = L_2 ;
V_7 -> V_30 . V_31 = V_32 ;
V_7 -> V_2 . V_33 = & V_17 -> V_2 ;
V_7 -> V_34 = V_4 -> V_11 ;
V_7 -> V_35 = F_3 ( V_4 -> V_11 ) ;
V_7 -> V_36 = sizeof( unsigned short ) ;
F_10 ( V_7 , V_14 , V_15 ) ;
F_11 ( V_37 , V_7 -> V_38 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_24 ) ; V_9 ++ )
F_11 ( V_4 -> V_11 [ V_9 ] , V_7 -> V_39 ) ;
F_12 ( V_40 , V_7 -> V_39 ) ;
V_20 = F_13 ( V_17 , V_41 , 0 ) ;
if ( ! V_20 ) {
error = - V_42 ;
goto V_23;
}
V_4 -> V_18 = V_18 ;
V_4 -> V_10 = F_14 ( V_20 -> V_43 , F_15 ( V_20 ) ) ;
F_16 ( & V_17 -> V_2 , V_4 ) ;
error = F_17 ( V_18 ) ;
if ( error )
goto V_44;
return 0 ;
V_44:
F_18 ( V_4 -> V_10 ) ;
V_23:
F_19 ( V_18 ) ;
F_20 ( V_4 ) ;
F_16 ( & V_17 -> V_2 , NULL ) ;
return error ;
}
static int T_3 F_21 ( struct V_16 * V_17 )
{
struct V_45 * V_2 = & V_17 -> V_2 ;
struct V_3 * V_4 = F_22 ( V_2 ) ;
F_23 ( V_4 -> V_18 ) ;
F_19 ( V_4 -> V_18 ) ;
F_18 ( V_4 -> V_10 ) ;
F_20 ( V_4 ) ;
F_16 ( V_2 , NULL ) ;
return 0 ;
}
