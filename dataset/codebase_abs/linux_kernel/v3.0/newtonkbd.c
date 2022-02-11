static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
if ( V_4 -> V_5 [ V_2 & V_6 ] ) {
F_3 ( V_4 -> V_7 , V_4 -> V_5 [ V_2 & V_6 ] , V_2 & V_8 ) ;
F_4 ( V_4 -> V_7 ) ;
}
else if ( V_2 == 0xe7 )
F_5 ( V_9 L_1 , V_4 -> V_7 -> V_10 , V_1 -> V_11 ) ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_13 * V_14 )
{
struct V_4 * V_4 ;
struct V_15 * V_15 ;
int V_16 = - V_17 ;
int V_18 ;
V_4 = F_7 ( sizeof( struct V_4 ) , V_19 ) ;
V_15 = F_8 () ;
if ( ! V_4 || ! V_15 )
goto V_20;
V_4 -> V_1 = V_1 ;
V_4 -> V_7 = V_15 ;
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) , L_2 , V_1 -> V_11 ) ;
memcpy ( V_4 -> V_5 , V_21 , sizeof( V_4 -> V_5 ) ) ;
V_15 -> V_10 = L_3 ;
V_15 -> V_11 = V_4 -> V_11 ;
V_15 -> V_22 . V_23 = V_24 ;
V_15 -> V_22 . V_25 = V_26 ;
V_15 -> V_22 . V_27 = 0x0001 ;
V_15 -> V_22 . V_28 = 0x0100 ;
V_15 -> V_7 . V_29 = & V_1 -> V_7 ;
V_15 -> V_30 [ 0 ] = F_9 ( V_31 ) | F_9 ( V_32 ) ;
V_15 -> V_5 = V_4 -> V_5 ;
V_15 -> V_33 = sizeof( unsigned char ) ;
V_15 -> V_34 = F_10 ( V_21 ) ;
for ( V_18 = 0 ; V_18 < 128 ; V_18 ++ )
F_11 ( V_4 -> V_5 [ V_18 ] , V_15 -> V_35 ) ;
F_12 ( 0 , V_15 -> V_35 ) ;
F_13 ( V_1 , V_4 ) ;
V_16 = F_14 ( V_1 , V_14 ) ;
if ( V_16 )
goto V_36;
V_16 = F_15 ( V_4 -> V_7 ) ;
if ( V_16 )
goto V_37;
return 0 ;
V_37: F_16 ( V_1 ) ;
V_36: F_13 ( V_1 , NULL ) ;
V_20: F_17 ( V_15 ) ;
F_18 ( V_4 ) ;
return V_16 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_16 ( V_1 ) ;
F_13 ( V_1 , NULL ) ;
F_20 ( V_4 -> V_7 ) ;
F_18 ( V_4 ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_38 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_38 ) ;
}
