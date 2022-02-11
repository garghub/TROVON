static T_1 F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_2 V_5 ;
if ( V_3 > 0 )
return - V_6 ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_10 ) ;
V_5 &= ~ V_11 ;
V_5 |= V_12 ;
F_5 ( V_5 , V_7 -> V_9 + V_10 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
return 0 ;
}
static unsigned long F_7 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
T_2 V_5 ;
unsigned V_14 ;
V_5 = F_4 ( V_7 -> V_9 + V_10 ) ;
V_14 = V_5 & V_15 ;
switch ( V_14 ) {
case V_16 :
return 12000000 ;
case V_17 :
return 24000000 ;
case V_18 :
return 48000000 ;
case V_19 :
return 19200000 ;
}
F_8 () ;
return V_13 ;
}
static long F_9 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long * V_13 )
{
if ( V_20 < 15600000 )
return 12000000 ;
if ( V_20 < 21600000 )
return 19200000 ;
if ( V_20 < 36000000 )
return 24000000 ;
return 48000000 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long V_13 )
{
unsigned long V_4 ;
T_2 V_5 , V_21 ;
switch ( V_20 ) {
case 12000000 :
V_21 = V_16 ;
break;
case 19200000 :
V_21 = V_19 ;
break;
case 24000000 :
V_21 = V_17 ;
break;
case 48000000 :
V_21 = V_18 ;
break;
default:
return - V_6 ;
}
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_10 ) ;
V_5 &= ~ V_15 ;
V_5 |= V_21 ;
F_5 ( V_5 , V_7 -> V_9 + V_10 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
return 0 ;
}
static void T_3 F_11 ( struct V_22 * V_23 )
{
int V_24 ;
V_7 = F_12 ( V_25 ,
F_13 ( V_25 ) , V_23 ) ;
if ( ! V_7 ) {
F_14 ( L_1 , V_26 ) ;
return;
}
V_24 = F_15 ( V_7 ) ;
if ( V_24 ) {
F_14 ( L_2 , V_26 ) ;
return;
}
}
