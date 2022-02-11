static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
int V_10 , V_11 , type , V_12 ;
V_10 = F_2 ( V_4 ) ;
V_11 = F_3 ( V_4 ) ;
type = ! ! V_3 -> V_13 ;
V_12 = V_5 & ~ 3 ;
if ( V_3 -> V_14 > 255 || V_10 > 31 || V_11 > 7 )
return V_15 ;
if ( F_4 ( V_3 ) ) {
if ( V_10 == 0 ) {
if ( V_1 == V_16 )
* V_6 = F_5 ( V_8 , F_6 ( V_12 ) ) ;
else
F_7 ( V_8 , * V_6 , F_6 ( V_12 ) ) ;
return V_17 ;
} else if ( V_10 > 1 )
return V_18 ;
}
F_7 ( V_8 , F_5 ( V_8 , V_19 ) , V_19 ) ;
F_7 ( V_8 , ( V_3 -> V_14 << 24 ) | ( V_10 << 19 ) |
( V_11 << 16 ) | V_12 , V_20 ) ;
F_7 ( V_8 , ( 1 << 31 ) | ( type << 8 ) , V_21 ) ;
if ( F_5 ( V_8 , V_19 ) & 0x10 )
return V_18 ;
if ( F_5 ( V_8 , V_22 ) & ( ( 1 << 29 ) | ( 1 << 28 ) ) )
return V_18 ;
if ( V_1 == V_16 )
* V_6 = F_5 ( V_8 , V_23 ) ;
else
F_7 ( V_8 , * V_6 , V_23 ) ;
F_7 ( V_8 , 0 , V_21 ) ;
return V_17 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_24 , T_1 * V_25 )
{
unsigned long V_26 ;
int V_27 ;
T_1 V_6 ;
if ( ( V_24 == 2 ) && ( V_5 & 1 ) )
return V_28 ;
else if ( ( V_24 == 4 ) && ( V_5 & 3 ) )
return V_28 ;
F_9 ( & V_29 , V_26 ) ;
V_27 = F_1 ( V_16 , V_3 ,
V_4 , V_5 , & V_6 ) ;
if ( V_27 != V_17 ) {
* V_25 = 0xffffffff ;
goto V_30;
}
if ( V_24 == 1 )
* V_25 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_24 == 2 )
* V_25 = ( V_6 >> ( ( V_5 & 2 ) << 3 ) ) & 0xffff ;
else
* V_25 = V_6 ;
F_10 ( & V_3 -> V_10 , L_1
L_2 , V_3 -> V_14 ,
V_4 , V_5 , V_24 , ( unsigned long ) * V_25 ) ;
V_30:
F_11 ( & V_29 , V_26 ) ;
return V_27 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_24 , T_1 V_25 )
{
unsigned long V_26 ;
int V_31 , V_27 ;
T_1 V_6 ;
if ( ( V_24 == 2 ) && ( V_5 & 1 ) )
return V_28 ;
else if ( ( V_24 == 4 ) && ( V_5 & 3 ) )
return V_28 ;
F_9 ( & V_29 , V_26 ) ;
V_27 = F_1 ( V_16 , V_3 ,
V_4 , V_5 , & V_6 ) ;
if ( V_27 != V_17 )
goto V_30;
F_10 ( & V_3 -> V_10 , L_3
L_4 , V_3 -> V_14 ,
V_4 , V_5 , V_24 , ( unsigned long ) V_25 ) ;
if ( V_24 == 1 ) {
V_31 = ( V_5 & 3 ) << 3 ;
V_6 &= ~ ( 0xff << V_31 ) ;
V_6 |= ( ( V_25 & 0xff ) << V_31 ) ;
} else if ( V_24 == 2 ) {
V_31 = ( V_5 & 2 ) << 3 ;
V_6 &= ~ ( 0xffff << V_31 ) ;
V_6 |= ( ( V_25 & 0xffff ) << V_31 ) ;
} else
V_6 = V_25 ;
V_27 = F_1 ( V_32 , V_3 ,
V_4 , V_5 , & V_6 ) ;
V_30:
F_11 ( & V_29 , V_26 ) ;
return V_27 ;
}
