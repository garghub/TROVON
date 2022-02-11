static inline T_1 F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( & V_2 -> V_3 ) ^ 0xa0 ;
return ( ( V_1 & 0x80 ) >> 6 ) | ( ( V_1 & 0x20 ) >> 5 ) ;
}
static inline T_1 F_1 ( void )
{
T_2 V_1 ;
V_1 = F_3 ( & V_4 -> V_5 . V_6 . V_7 ) ;
F_4 ( V_1 & ~ ( 3U << 23 ) , & V_4 -> V_5 . V_6 . V_7 ) ;
return ( V_1 >> 23 ) & 3 ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_1 V_1 ;
int V_15 ;
V_1 = F_1 () ;
for ( V_15 = 0 ; V_15 < F_6 ( V_11 -> V_16 ) ; V_15 ++ ) {
if ( V_1 & ( 1U << V_15 ) ) {
if ( ++ V_11 -> V_17 [ V_15 ] == V_18 ) {
F_7 ( V_14 , V_19 , V_20 , V_15 ) ;
F_8 ( V_14 , V_11 -> V_16 [ V_15 ] , 1 ) ;
F_9 ( V_14 ) ;
}
} else {
if ( V_11 -> V_17 [ V_15 ] >= V_18 ) {
F_7 ( V_14 , V_19 , V_20 , V_15 ) ;
F_8 ( V_14 , V_11 -> V_16 [ V_15 ] , 0 ) ;
F_9 ( V_14 ) ;
}
V_11 -> V_17 [ V_15 ] = 0 ;
}
}
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_10 * V_11 ;
struct V_8 * V_23 ;
struct V_13 * V_14 ;
int error , V_15 ;
V_11 = F_11 ( sizeof( struct V_10 ) , V_24 ) ;
V_23 = F_12 () ;
if ( ! V_11 || ! V_23 ) {
error = - V_25 ;
goto V_26;
}
memcpy ( V_11 -> V_16 , V_27 , sizeof( V_11 -> V_16 ) ) ;
V_23 -> V_12 = V_11 ;
V_23 -> V_28 = F_5 ;
V_23 -> V_29 = V_30 ;
V_14 = V_23 -> V_14 ;
V_14 -> V_31 = L_1 ;
V_14 -> V_32 = L_2 ;
V_14 -> V_33 . V_34 = V_35 ;
V_14 -> V_9 . V_36 = & V_22 -> V_9 ;
V_14 -> V_37 = V_11 -> V_16 ;
V_14 -> V_38 = F_6 ( V_11 -> V_16 ) ;
V_14 -> V_39 = sizeof( unsigned short ) ;
F_13 ( V_14 , V_19 , V_20 ) ;
F_14 ( V_40 , V_14 -> V_41 ) ;
for ( V_15 = 0 ; V_15 < F_6 ( V_27 ) ; V_15 ++ )
F_14 ( V_11 -> V_16 [ V_15 ] , V_14 -> V_42 ) ;
F_15 ( V_43 , V_14 -> V_42 ) ;
V_11 -> V_23 = V_23 ;
F_16 ( V_22 , V_11 ) ;
error = F_17 ( V_23 ) ;
if ( error )
goto V_26;
return 0 ;
V_26:
F_18 ( V_23 ) ;
F_19 ( V_11 ) ;
return error ;
}
static int F_20 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_21 ( V_22 ) ;
F_22 ( V_11 -> V_23 ) ;
F_18 ( V_11 -> V_23 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
