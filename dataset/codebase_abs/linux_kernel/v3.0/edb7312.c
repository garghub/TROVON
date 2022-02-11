static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 & V_8 ) {
unsigned char V_9 = 0x80 ;
V_9 |= ( V_4 & ( V_10 | V_11 ) ) << 3 ;
V_9 |= ( V_4 & V_12 ) ? 0x00 : 0x40 ;
F_2 ( ( F_3 ( V_13 ) & 0xF0 ) | V_9 ,
V_13 ) ;
}
if ( V_3 != V_14 )
F_4 ( V_3 , V_6 -> V_15 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 1 ;
}
static int T_1 F_6 ( void )
{
struct V_5 * V_16 ;
const char * V_17 = 0 ;
int V_18 = 0 ;
struct V_19 * V_20 = 0 ;
void T_2 * V_21 ;
V_22 = F_7 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_23 ) ;
if ( ! V_22 ) {
F_8 ( L_1 ) ;
return - V_24 ;
}
V_21 = F_9 ( V_25 , V_26 ) ;
if ( ! V_21 ) {
F_8 ( L_2 ) ;
F_10 ( V_22 ) ;
return - V_27 ;
}
V_16 = (struct V_5 * ) ( & V_22 [ 1 ] ) ;
memset ( V_22 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_16 , 0 , sizeof( struct V_5 ) ) ;
V_22 -> V_7 = V_16 ;
V_22 -> V_28 = V_29 ;
F_2 ( 0xf0 , V_30 ) ;
V_16 -> V_31 = V_21 ;
V_16 -> V_15 = V_21 ;
V_16 -> V_32 = F_1 ;
V_16 -> V_33 = F_5 ;
V_16 -> V_34 = 15 ;
if ( F_11 ( V_22 , 1 ) ) {
F_12 ( ( void * ) V_21 ) ;
F_10 ( V_22 ) ;
return - V_35 ;
}
V_22 -> V_36 = L_3 ;
V_18 = F_13 ( V_22 , V_37 , & V_20 , 0 ) ;
if ( V_18 > 0 )
V_17 = L_4 ;
else
V_18 = 0 ;
if ( V_18 == 0 ) {
V_20 = V_38 ;
V_18 = V_39 ;
V_17 = L_5 ;
}
F_8 ( V_40 L_6 , V_17 ) ;
F_14 ( V_22 , V_20 , V_18 ) ;
return 0 ;
}
static void T_3 F_15 ( void )
{
struct V_5 * V_16 = (struct V_5 * ) & V_22 [ 1 ] ;
F_16 ( V_41 ) ;
F_12 ( V_16 -> V_31 ) ;
F_10 ( V_22 ) ;
}
