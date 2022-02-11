static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
switch ( V_2 ) {
case V_5 :
case V_6 :
break;
default:
if ( V_4 -> V_7 [ V_2 & V_8 ] ) {
F_3 ( V_4 -> V_9 , V_4 -> V_7 [ V_2 & V_8 ] , ! ( V_2 & V_10 ) ) ;
F_4 ( V_4 -> V_9 ) ;
} else {
F_5 ( V_11 L_1 ,
V_2 & V_8 , V_2 & V_10 ? L_2 : L_3 ) ;
}
}
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
V_4 -> V_9 = V_15 ;
snprintf ( V_4 -> V_21 , sizeof( V_4 -> V_21 ) , L_4 , V_1 -> V_21 ) ;
memcpy ( V_4 -> V_7 , V_22 , sizeof( V_4 -> V_7 ) ) ;
V_15 -> V_23 = L_5 ;
V_15 -> V_21 = V_4 -> V_21 ;
V_15 -> V_24 . V_25 = V_26 ;
V_15 -> V_24 . V_27 = 0x0001 ;
V_15 -> V_24 . V_28 = 0x0001 ;
V_15 -> V_24 . V_29 = 0x0100 ;
V_15 -> V_9 . V_30 = & V_1 -> V_9 ;
V_15 -> V_31 [ 0 ] = F_9 ( V_32 ) | F_9 ( V_33 ) ;
V_15 -> V_7 = V_4 -> V_7 ;
V_15 -> V_34 = sizeof( unsigned char ) ;
V_15 -> V_35 = F_10 ( V_22 ) ;
for ( V_18 = 0 ; V_18 < 255 ; V_18 ++ )
F_11 ( V_4 -> V_7 [ V_18 ] , V_15 -> V_36 ) ;
F_12 ( 0 , V_15 -> V_36 ) ;
F_13 ( V_1 , V_4 ) ;
V_16 = F_14 ( V_1 , V_14 ) ;
if ( V_16 )
goto V_37;
V_16 = F_15 ( V_4 -> V_9 ) ;
if ( V_16 )
goto V_38;
return 0 ;
V_38: F_16 ( V_1 ) ;
V_37: F_13 ( V_1 , NULL ) ;
V_20: F_17 ( V_15 ) ;
F_18 ( V_4 ) ;
return V_16 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_16 ( V_1 ) ;
F_13 ( V_1 , NULL ) ;
F_20 ( V_4 -> V_9 ) ;
F_18 ( V_4 ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_39 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_39 ) ;
}
