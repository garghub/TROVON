static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
switch ( V_2 -> V_5 . V_6 ) {
case 0x74 : V_4 = 7 ; break;
case 0x7B : V_4 = 13 ; break;
case 0x81 : V_4 = 14 ; break;
case 0x82 : V_4 = 9 ; break;
case 0x83 : V_4 = 20 ; break;
case 0x84 : V_4 = 26 ; break;
case 0x87 : V_4 = 18 ; break;
case 0x8A : V_4 = 8 ; break;
case 0x8C : V_4 = 5 ; break;
case 0x8D : V_4 = ( V_2 -> V_7 == 13 ) ? 16 : 17 ; break;
default: return;
}
F_2 ( V_3 , V_4 , & V_2 -> V_4 ) ;
}
static void T_1
F_3 ( struct V_8 * V_9 )
{
unsigned long V_10 = V_9 -> V_11 ;
F_4 ( 0x00000000 , V_10 + V_12 ) ;
F_5 ( V_10 + V_13 ) ;
if( F_6 ( V_10 + 0x4004 ) == V_14 )
F_4 ( 0xFFFFFFFF , V_10 + 0x4004 ) ;
F_4 ( 0xFFFFFFFF , V_10 + 0x7000 ) ;
F_4 ( 0xFFFFFFFF , V_10 + 0x8000 ) ;
F_4 ( 0xFFFFFFFF , V_10 + 0xA000 ) ;
}
static void T_1 F_7 ( unsigned long V_15 )
{
unsigned long V_16 ;
switch ( V_17 ) {
case 0x600 :
case 0x601 :
case 0x602 :
case 0x603 :
case 0x604 :
case 0x605 :
V_16 = V_15 + 0x0000C000 ;
F_8 ( 0 , V_16 ) ;
return;
case 0x60A :
case 0x60B :
case 0x60C :
case 0x60D :
case 0x60E :
V_16 = V_15 - 0x00020000 ;
break;
default:
V_16 = V_15 + 0x0000C000 ;
break;
}
F_9 ( V_18 , V_19 , V_16 ) ;
}
static void F_10 ( void )
{
unsigned long V_16 ;
V_16 = V_20 + 0x0000C000 ;
F_4 ( 0x02 , V_16 ) ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
extern void (* F_12)( void );
struct V_8 * V_21 ;
struct V_22 V_22 ;
int V_23 ;
V_21 = F_13 ( sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
V_21 -> V_26 = L_1 ;
V_21 -> V_11 = V_2 -> V_11 . V_27 ;
V_21 -> V_28 = F_5 ( V_21 -> V_11 + V_29 ) & 0xf ;
F_14 ( V_30 L_2 ,
V_21 -> V_26 , V_21 -> V_28 , V_21 -> V_11 ) ;
F_7 ( V_21 -> V_11 ) ;
F_3 ( V_21 ) ;
V_2 -> V_4 = F_15 ( & V_22 ) ;
if ( V_2 -> V_4 < 0 ) {
F_14 ( V_31 L_3 ,
V_32 ) ;
F_16 ( V_21 ) ;
return - V_33 ;
}
V_21 -> V_34 = ( ( V_35 ) V_22 . V_36 ) | V_22 . V_37 ;
V_23 = F_17 ( V_22 . V_4 , V_38 , 0 , L_4 , V_21 ) ;
if ( V_23 < 0 ) {
F_16 ( V_21 ) ;
return V_23 ;
}
F_4 ( V_21 -> V_34 , V_21 -> V_11 + V_39 ) ;
V_23 = F_18 ( V_2 , V_21 ) ;
if ( V_23 ) {
F_16 ( V_21 ) ;
return V_23 ;
}
F_19 ( V_2 , V_21 , F_1 ) ;
V_20 = V_21 -> V_11 ;
F_12 = F_10 ;
return V_23 ;
}
