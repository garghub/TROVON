static void F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
if ( V_1 ) {
F_3 ( 0xB6 , 0x43 ) ;
F_3 ( V_1 & 0xff , 0x42 ) ;
F_4 ( ( V_1 >> 8 ) & 0xff , 0x42 ) ;
F_3 ( F_5 ( 0x61 ) | 3 , 0x61 ) ;
} else {
F_4 ( F_5 ( 0x61 ) & 0xFC , 0x61 ) ;
}
F_6 ( & V_3 , V_2 ) ;
}
void F_7 ( void )
{
F_1 ( 0 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int type ,
unsigned int V_6 , int V_7 )
{
unsigned int V_1 = 0 ;
if ( F_9 ( & V_8 . V_9 ) || ! V_8 . V_10 )
return 0 ;
switch ( type ) {
case V_11 :
switch ( V_6 ) {
case V_12 :
if ( V_7 )
V_7 = 1000 ;
case V_13 :
break;
default:
return - 1 ;
}
break;
default:
return - 1 ;
}
if ( V_7 > 20 && V_7 < 32767 )
V_1 = V_14 / V_7 ;
F_1 ( V_1 ) ;
return 0 ;
}
int F_10 ( struct V_4 * * V_15 , struct V_16 * V_5 )
{
int V_17 ;
struct V_4 * V_4 = F_11 () ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_19 = L_1 ;
V_4 -> V_20 = L_2 ;
V_4 -> V_21 . V_22 = V_23 ;
V_4 -> V_21 . V_24 = 0x001f ;
V_4 -> V_21 . V_25 = 0x0001 ;
V_4 -> V_21 . V_26 = 0x0100 ;
V_4 -> V_5 . V_27 = V_5 ;
V_4 -> V_28 [ 0 ] = F_12 ( V_11 ) ;
V_4 -> V_29 [ 0 ] = F_12 ( V_12 ) | F_12 ( V_13 ) ;
V_4 -> V_30 = F_8 ;
V_17 = F_13 ( V_4 ) ;
if ( V_17 ) {
F_14 ( V_4 ) ;
return V_17 ;
}
* V_15 = V_4 ;
return 0 ;
}
int F_15 ( struct V_4 * V_5 )
{
F_7 () ;
F_16 ( V_5 ) ;
return 0 ;
}
