static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 ;
V_7 = ( ( V_4 [ 1 ] & 0x7f ) << 7 ) | ( V_4 [ 0 ] & 0x7f ) ;
for ( V_6 = V_10 ; V_6 -> V_11 ; V_6 ++ ) {
int V_12 = ( V_7 & ( V_6 -> V_11 << V_6 -> V_13 ) ) >> V_6 -> V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_11 ; V_14 ++ )
F_2 ( V_3 , V_6 -> V_15 [ V_14 ] , V_14 + 1 == V_12 ) ;
}
V_8 = ( ( V_4 [ 4 ] & 0x07 ) << 5 ) | ( ( V_4 [ 3 ] & 0x7C ) >> 2 ) ;
if ( V_4 [ 4 ] & 0x08 ) V_8 -= 256 ;
V_9 = ( ( V_4 [ 3 ] & 0x01 ) << 7 ) | ( ( V_4 [ 2 ] & 0x7F ) >> 0 ) ;
if ( V_4 [ 3 ] & 0x02 ) V_9 -= 256 ;
F_3 ( V_3 , V_16 , - V_8 ) ;
F_3 ( V_3 , V_17 , + V_9 ) ;
F_4 ( V_3 ) ;
}
static T_1 F_5 ( struct V_18 * V_18 , unsigned char V_4 , unsigned int V_19 )
{
struct V_1 * V_1 = F_6 ( V_18 ) ;
if ( ( V_4 & 0x80 ) == 0 )
V_1 -> V_20 = 0 ;
else if ( V_1 -> V_20 == 0 )
return V_21 ;
if ( V_1 -> V_20 < V_22 )
V_1 -> V_4 [ V_1 -> V_20 ++ ] = V_4 ;
if ( V_1 -> V_20 == V_22 ) {
F_1 ( V_1 ) ;
V_1 -> V_20 = 0 ;
}
return V_21 ;
}
static void F_7 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = F_6 ( V_18 ) ;
F_8 ( V_18 ) ;
F_9 ( V_18 , NULL ) ;
F_10 ( V_1 -> V_3 ) ;
F_11 ( V_1 ) ;
}
static int F_12 ( struct V_18 * V_18 , struct V_23 * V_24 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_25 = - V_26 ;
int V_14 ;
V_1 = F_13 ( sizeof( struct V_1 ) , V_27 ) ;
V_2 = F_14 () ;
if ( ! V_1 || ! V_2 )
goto V_28;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_29 , sizeof( V_1 -> V_29 ) , L_1 , V_18 -> V_29 ) ;
V_2 -> V_30 = L_2 ;
V_2 -> V_29 = V_1 -> V_29 ;
V_2 -> V_31 . V_32 = V_33 ;
V_2 -> V_31 . V_34 = V_35 ;
V_2 -> V_31 . V_36 = 0x0001 ;
V_2 -> V_31 . V_37 = 0x0100 ;
V_2 -> V_3 . V_38 = & V_18 -> V_3 ;
V_2 -> V_39 [ 0 ] = F_15 ( V_40 ) | F_15 ( V_41 ) ;
F_16 ( V_2 , V_16 , - 50 , 50 , 4 , 4 ) ;
F_16 ( V_2 , V_17 , - 50 , 50 , 4 , 4 ) ;
for ( V_6 = V_10 ; V_6 -> V_11 ; V_6 ++ )
for ( V_14 = 0 ; V_14 < V_6 -> V_11 ; V_14 ++ )
F_17 ( V_6 -> V_15 [ V_14 ] , V_2 -> V_42 ) ;
F_9 ( V_18 , V_1 ) ;
V_25 = F_18 ( V_18 , V_24 ) ;
if ( V_25 )
goto V_43;
V_25 = F_19 ( V_1 -> V_3 ) ;
if ( V_25 )
goto V_44;
return 0 ;
V_44: F_8 ( V_18 ) ;
V_43: F_9 ( V_18 , NULL ) ;
V_28: F_20 ( V_2 ) ;
F_11 ( V_1 ) ;
return V_25 ;
}
