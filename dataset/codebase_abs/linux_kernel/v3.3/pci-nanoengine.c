static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 , unsigned long * V_5 )
{
int V_6 = V_7 ;
unsigned int V_8 = V_2 -> V_9 ;
* V_5 = V_10 +
( ( V_2 -> V_9 << 16 ) | ( V_3 << 8 ) | ( V_4 & ~ 3 ) ) ;
V_6 = ( V_8 > 255 || V_3 > 255 || V_4 > 255 ) ?
V_7 : V_11 ;
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_12 , T_1 * V_13 )
{
int V_6 ;
unsigned long V_5 ;
unsigned long V_14 ;
T_1 V_15 ;
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
int V_12 , T_1 V_13 )
{
int V_6 ;
unsigned long V_5 ;
unsigned long V_14 ;
unsigned V_18 ;
T_1 V_15 ;
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
static int T_2 F_8 ( const struct V_19 * V_20 , T_3 V_21 ,
T_3 V_22 )
{
return V_23 ;
}
struct V_1 * T_2 F_9 ( int V_24 , struct V_25 * V_26 )
{
return F_10 ( NULL , V_26 -> V_8 , & V_27 , V_26 ,
& V_26 -> V_28 ) ;
}
static int T_2 F_11 ( struct V_25 * V_26 )
{
if ( F_12 ( & V_29 , & V_30 ) ) {
F_13 ( V_31 L_1 ) ;
return - V_32 ;
}
if ( F_12 ( & V_33 , & V_34 ) ) {
F_14 ( & V_30 ) ;
F_13 ( V_31 L_2 ) ;
return - V_32 ;
}
if ( F_12 ( & V_33 , & V_35 ) ) {
F_14 ( & V_30 ) ;
F_14 ( & V_34 ) ;
F_13 ( V_31 L_3 ) ;
return - V_32 ;
}
F_15 ( & V_26 -> V_28 , & V_30 ) ;
F_15 ( & V_26 -> V_28 , & V_34 ) ;
F_15 ( & V_26 -> V_28 , & V_35 ) ;
return 1 ;
}
int T_2 F_16 ( int V_24 , struct V_25 * V_26 )
{
int V_6 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
if ( V_24 == 0 ) {
V_26 -> V_38 = V_39 ;
V_26 -> V_40 = 0x400 ;
V_6 = F_11 ( V_26 ) ;
V_41 = ( V_41 & ~ V_42 ) | V_43 ;
V_44 |= V_43 | V_42 ;
V_45 |= V_46 ;
}
return V_6 ;
}
static int T_2 F_17 ( void )
{
if ( F_18 () )
F_19 ( & V_47 ) ;
return 0 ;
}
