static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 , void T_1 * * V_5 )
{
int V_6 = V_7 ;
unsigned int V_8 = V_2 -> V_9 ;
* V_5 = ( void T_1 * ) V_10 +
( ( V_2 -> V_9 << 16 ) | ( V_3 << 8 ) | ( V_4 & ~ 3 ) ) ;
V_6 = ( V_8 > 255 || V_3 > 255 || V_4 > 255 ) ?
V_7 : V_11 ;
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_12 , T_2 * V_13 )
{
int V_6 ;
void T_1 * V_5 ;
unsigned long V_14 ;
T_2 V_15 ;
if ( V_2 -> V_9 != 0 || ( V_3 >> 3 ) != 0 ) {
V_15 = - 1 ;
F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
goto V_16;
}
F_3 ( & V_17 , V_14 ) ;
V_6 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_6 != V_11 )
return V_6 ;
V_15 = F_4 ( V_5 ) ;
F_5 ( & V_17 , V_14 ) ;
V_15 >>= ( ( V_4 & 3 ) * 8 ) ;
V_15 &= ( unsigned long ) ( - 1 ) >> ( ( 4 - V_12 ) * 8 ) ;
V_16:
* V_13 = V_15 ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_12 , T_2 V_13 )
{
int V_6 ;
void T_1 * V_5 ;
unsigned long V_14 ;
unsigned V_18 ;
T_2 V_15 ;
V_18 = ( V_4 & 3 ) * 8 ;
F_3 ( & V_17 , V_14 ) ;
V_6 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_6 != V_11 )
return V_6 ;
V_15 = F_4 ( V_5 ) ;
switch ( V_12 ) {
case 1 :
V_15 &= ~ ( 0xFF << V_18 ) ;
V_15 |= V_13 << V_18 ;
break;
case 2 :
V_15 &= ~ ( 0xFFFF << V_18 ) ;
V_15 |= V_13 << V_18 ;
break;
case 4 :
V_15 = V_13 ;
break;
}
F_7 ( V_15 , V_5 ) ;
F_5 ( & V_17 , V_14 ) ;
return V_11 ;
}
static int T_3 F_8 ( const struct V_19 * V_20 , T_4 V_21 ,
T_4 V_22 )
{
return V_23 ;
}
static int T_3 F_9 ( struct V_24 * V_25 )
{
if ( F_10 ( & V_26 , & V_27 ) ) {
F_11 ( V_28 L_1 ) ;
return - V_29 ;
}
if ( F_10 ( & V_30 , & V_31 ) ) {
F_12 ( & V_27 ) ;
F_11 ( V_28 L_2 ) ;
return - V_29 ;
}
if ( F_10 ( & V_30 , & V_32 ) ) {
F_12 ( & V_27 ) ;
F_12 ( & V_31 ) ;
F_11 ( V_28 L_3 ) ;
return - V_29 ;
}
F_13 ( & V_25 -> V_33 , & V_27 , V_25 -> V_34 ) ;
F_13 ( & V_25 -> V_33 ,
& V_31 , V_25 -> V_35 ) ;
F_13 ( & V_25 -> V_33 ,
& V_32 , V_25 -> V_35 ) ;
return 1 ;
}
int T_3 F_14 ( int V_36 , struct V_24 * V_25 )
{
int V_6 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
if ( V_36 == 0 ) {
V_25 -> V_35 = V_39 ;
V_25 -> V_34 = 0x400 ;
V_6 = F_9 ( V_25 ) ;
V_40 = ( V_40 & ~ V_41 ) | V_42 ;
V_43 |= V_42 | V_41 ;
V_44 |= V_45 ;
}
return V_6 ;
}
static int T_3 F_15 ( void )
{
if ( F_16 () )
F_17 ( & V_46 ) ;
return 0 ;
}
