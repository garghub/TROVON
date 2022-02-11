static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
switch ( V_2 -> V_5 . V_6 ) {
case 0x73 : V_4 = 1 ; break;
case 0x8c : V_4 = 6 ; break;
case 0x90 : V_4 = 10 ; break;
default: return;
}
F_2 ( V_3 , V_4 , & V_2 -> V_4 ) ;
switch ( V_2 -> V_5 . V_6 ) {
case 0x73 : V_4 = 2 ; break;
case 0x90 : V_4 = 0 ; break;
default: return;
}
F_2 ( V_3 , V_4 , & V_2 -> V_7 ) ;
}
static void T_1
F_3 ( struct V_8 * V_9 )
{
unsigned long V_10 = V_9 -> V_11 ;
F_4 ( 0x00000000 , V_10 + V_12 ) ;
F_5 ( V_10 + V_13 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_1 * V_14 ;
struct V_15 V_15 ;
int V_16 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_9 -> V_19 = L_1 ;
V_9 -> V_11 = V_2 -> V_11 . V_20 ;
V_9 -> V_21 = 0 ;
F_8 ( V_22 L_2 , V_9 -> V_19 , V_9 -> V_11 ) ;
F_3 ( V_9 ) ;
V_2 -> V_4 = F_9 ( & V_15 , V_23 ) ;
if ( V_2 -> V_4 < 0 ) {
F_8 ( V_24 L_3 ,
V_25 ) ;
F_10 ( V_9 ) ;
return - V_26 ;
}
V_9 -> V_27 = ( ( V_28 ) V_15 . V_29 ) | V_15 . V_30 ;
V_16 = F_11 ( V_15 . V_4 , V_31 , 0 , L_1 , V_9 ) ;
if ( V_16 < 0 ) {
F_10 ( V_9 ) ;
return V_16 ;
}
F_4 ( V_9 -> V_27 , V_9 -> V_11 + V_32 ) ;
V_16 = F_12 ( V_2 , V_9 ) ;
if ( V_16 ) {
F_10 ( V_9 ) ;
return V_16 ;
}
F_13 ( V_2 , V_9 , F_1 ) ;
V_14 = F_14 ( V_2 ) ;
if ( V_14 -> V_5 . V_33 != V_34 ) {
F_13 ( V_14 , V_9 , F_1 ) ;
}
return V_16 ;
}
