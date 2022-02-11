static int F_1 ( struct V_1 * V_2 , unsigned int type , unsigned int V_3 , int V_4 )
{
unsigned int V_5 = 0 ;
unsigned long V_6 ;
if ( type != V_7 )
return - 1 ;
switch ( V_3 ) {
case V_8 : if ( V_4 ) V_4 = 1000 ;
case V_9 : break;
default: return - 1 ;
}
if ( V_4 > 20 && V_4 < 32767 )
V_5 = V_10 / V_4 ;
F_2 ( & V_11 , V_6 ) ;
if ( V_5 ) {
F_3 ( 0xB6 , 0x43 ) ;
F_3 ( V_5 & 0xff , 0x42 ) ;
F_4 ( ( V_5 >> 8 ) & 0xff , 0x42 ) ;
F_3 ( F_5 ( 0x61 ) | 3 , 0x61 ) ;
} else {
F_4 ( F_5 ( 0x61 ) & 0xFC , 0x61 ) ;
}
F_6 ( & V_11 , V_6 ) ;
return 0 ;
}
static int T_1 F_7 ( struct V_12 * V_2 )
{
struct V_1 * V_13 ;
int V_14 ;
V_13 = F_8 () ;
if ( ! V_13 )
return - V_15 ;
V_13 -> V_16 = L_1 ;
V_13 -> V_17 = L_2 ;
V_13 -> V_18 . V_19 = V_20 ;
V_13 -> V_18 . V_21 = 0x001f ;
V_13 -> V_18 . V_22 = 0x0001 ;
V_13 -> V_18 . V_23 = 0x0100 ;
V_13 -> V_2 . V_24 = & V_2 -> V_2 ;
V_13 -> V_25 [ 0 ] = F_9 ( V_7 ) ;
V_13 -> V_26 [ 0 ] = F_9 ( V_8 ) | F_9 ( V_9 ) ;
V_13 -> V_27 = F_1 ;
V_14 = F_10 ( V_13 ) ;
if ( V_14 ) {
F_11 ( V_13 ) ;
return V_14 ;
}
F_12 ( V_2 , V_13 ) ;
return 0 ;
}
static int T_2 F_13 ( struct V_12 * V_2 )
{
struct V_1 * V_13 = F_14 ( V_2 ) ;
F_15 ( V_13 ) ;
F_12 ( V_2 , NULL ) ;
F_1 ( NULL , V_7 , V_8 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_2 )
{
F_1 ( NULL , V_7 , V_8 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_2 )
{
F_1 ( NULL , V_7 , V_8 , 0 ) ;
}
