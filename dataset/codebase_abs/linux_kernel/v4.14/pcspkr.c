static int F_1 ( struct V_1 * V_2 , unsigned int type ,
unsigned int V_3 , int V_4 )
{
unsigned int V_5 = 0 ;
unsigned long V_6 ;
if ( type != V_7 )
return - V_8 ;
switch ( V_3 ) {
case V_9 :
if ( V_4 )
V_4 = 1000 ;
case V_10 :
break;
default:
return - V_8 ;
}
if ( V_4 > 20 && V_4 < 32767 )
V_5 = V_11 / V_4 ;
F_2 ( & V_12 , V_6 ) ;
if ( V_5 ) {
F_3 ( 0xB6 , 0x43 ) ;
F_3 ( V_5 & 0xff , 0x42 ) ;
F_4 ( ( V_5 >> 8 ) & 0xff , 0x42 ) ;
F_3 ( F_5 ( 0x61 ) | 3 , 0x61 ) ;
} else {
F_4 ( F_5 ( 0x61 ) & 0xFC , 0x61 ) ;
}
F_6 ( & V_12 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_2 )
{
struct V_1 * V_14 ;
int V_15 ;
V_14 = F_8 () ;
if ( ! V_14 )
return - V_16 ;
V_14 -> V_17 = L_1 ;
V_14 -> V_18 = L_2 ;
V_14 -> V_19 . V_20 = V_21 ;
V_14 -> V_19 . V_22 = 0x001f ;
V_14 -> V_19 . V_23 = 0x0001 ;
V_14 -> V_19 . V_24 = 0x0100 ;
V_14 -> V_2 . V_25 = & V_2 -> V_2 ;
V_14 -> V_26 [ 0 ] = F_9 ( V_7 ) ;
V_14 -> V_27 [ 0 ] = F_9 ( V_9 ) | F_9 ( V_10 ) ;
V_14 -> V_28 = F_1 ;
V_15 = F_10 ( V_14 ) ;
if ( V_15 ) {
F_11 ( V_14 ) ;
return V_15 ;
}
F_12 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_2 )
{
struct V_1 * V_14 = F_14 ( V_2 ) ;
F_15 ( V_14 ) ;
F_1 ( NULL , V_7 , V_9 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_2 )
{
F_1 ( NULL , V_7 , V_9 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_13 * V_2 )
{
F_1 ( NULL , V_7 , V_9 , 0 ) ;
}
