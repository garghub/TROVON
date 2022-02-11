int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
if ( ( F_2 ( V_2 -> V_6 ) != V_7 )
&& ( F_2 ( V_2 -> V_6 ) < 32 ) ) {
V_5 = V_8 [ V_3 ] [ V_4 ] ;
F_3 ( V_9 L_1 , V_3 , V_4 ,
V_5 + V_10 ) ;
if ( V_5 != 0 )
return V_10 + V_5 ;
else
return 0 ;
} else if ( F_2 ( V_2 -> V_6 ) == V_7 ) {
switch ( F_4 ( V_2 -> V_6 ) ) {
case 2 :
F_5 ( V_2 , V_11 ,
V_12 ) ;
return V_12 ;
case 3 :
F_5 ( V_2 , V_11 ,
V_13 ) ;
return V_13 ;
case 4 :
case 5 :
case 6 :
case 7 :
F_5 ( V_2 , V_11 ,
V_14 ) ;
return V_14 ;
}
return V_2 -> V_15 ;
} else {
F_3 ( V_9 L_2 ) ;
return 0 ;
}
}
int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static void T_1 F_7 ( struct V_1 * V_16 )
{
F_8 ( V_16 , V_17 , 1 ) ;
F_8 ( V_16 , V_18 , 1 ) ;
}
static void T_1 F_9 ( struct V_1 * V_16 )
{
F_8 ( V_16 , V_19 ,
V_20 ) ;
}
static void T_1 F_10 ( struct V_1 * V_16 )
{
F_8 ( V_16 , V_21 , 1 ) ;
F_5 ( V_16 , V_22 , 0xc0 ) ;
}
static void T_1 F_11 ( struct V_1 * V_16 )
{
F_8 ( V_16 , V_23 , 1 ) ;
}
static void T_1 F_12 ( struct V_1 * V_16 )
{
T_3 V_24 , V_25 ;
F_13 ( F_14 ( V_26 ) , & V_24 , & V_25 ) ;
F_15 ( F_14 ( V_26 ) , ( 1 << 1 ) | ( 1 << 3 ) , V_25 ) ;
F_8 ( V_16 , V_27 , 0x2000 ) ;
}
static void T_1 F_16 ( struct V_1 * V_16 )
{
unsigned int V_28 ;
F_17 ( V_16 , 0xe0 , & V_28 ) ;
F_8 ( V_16 , 0xe0 , ( V_28 & ~ 3 ) | 0x2 ) ;
}
