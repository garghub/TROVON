static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
unsigned long V_9 = F_2 ( V_2 , V_10 ) ;
if ( V_6 -> V_11 & V_12 )
return 0 ;
if ( strcmp ( V_4 -> V_13 , L_1 ) == 0 )
V_9 &= ~ V_14 ;
else if ( strcmp ( V_4 -> V_13 , L_2 ) == 0 )
V_9 |= V_14 ;
else {
F_3 ( V_15 L_3 , V_4 -> V_13 ) ;
return - V_16 ;
}
F_4 ( V_2 , V_10 , V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = F_2 ( V_2 , V_10 ) ;
V_4 -> V_17 = 1 ;
if ( V_6 -> V_11 & V_12 )
return 0 ;
switch ( V_9 & V_14 ) {
case V_18 :
V_4 -> V_13 = L_1 ;
break;
case V_19 :
V_4 -> V_13 = L_2 ;
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
unsigned long V_9 = F_2 ( V_2 , V_10 ) ;
V_9 &= V_14 ;
F_4 ( V_2 , V_10 , V_9 | V_6 -> V_9 ) ;
F_4 ( V_2 , V_20 , V_6 -> V_21 ) ;
F_4 ( V_2 , V_22 , V_6 -> V_23 | V_24 ) ;
F_4 ( V_2 , V_22 , V_6 -> V_23 ) ;
return 0 ;
}
static int F_7 ( struct V_25 * V_26 )
{
return F_8 ( V_26 , V_27 [ V_26 -> V_28 ] ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_29 , V_27 ) ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_29 , * V_27 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_29 ) ;
}
