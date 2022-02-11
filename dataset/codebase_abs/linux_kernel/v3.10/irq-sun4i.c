void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = V_3 % 32 ;
int V_5 = V_3 / 32 ;
T_1 V_6 ;
V_6 = F_3 ( V_7 + F_4 ( V_5 ) ) ;
F_5 ( V_6 | ( 1 << V_4 ) ,
V_7 + F_4 ( V_5 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = V_3 % 32 ;
int V_5 = V_3 / 32 ;
T_1 V_6 ;
V_6 = F_3 ( V_7 + F_7 ( V_5 ) ) ;
F_5 ( V_6 & ~ ( 1 << V_4 ) ,
V_7 + F_7 ( V_5 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = V_3 % 32 ;
int V_5 = V_3 / 32 ;
T_1 V_6 ;
V_6 = F_3 ( V_7 + F_7 ( V_5 ) ) ;
F_5 ( V_6 | ( 1 << V_4 ) ,
V_7 + F_7 ( V_5 ) ) ;
}
static int F_9 ( struct V_8 * V_9 , unsigned int V_10 ,
T_2 V_11 )
{
F_10 ( V_10 , & V_12 ,
V_13 ) ;
F_11 ( V_10 , V_14 | V_15 ) ;
return 0 ;
}
static int T_3 F_12 ( struct V_16 * V_17 ,
struct V_16 * V_18 )
{
V_7 = F_13 ( V_17 , 0 ) ;
if ( ! V_7 )
F_14 ( L_1 ,
V_17 -> V_19 ) ;
F_5 ( 0 , V_7 + F_7 ( 0 ) ) ;
F_5 ( 0 , V_7 + F_7 ( 1 ) ) ;
F_5 ( 0 , V_7 + F_7 ( 2 ) ) ;
F_5 ( 0 , V_7 + F_15 ( 0 ) ) ;
F_5 ( 0 , V_7 + F_15 ( 1 ) ) ;
F_5 ( 0 , V_7 + F_15 ( 2 ) ) ;
F_5 ( 0xffffffff , V_7 + F_4 ( 0 ) ) ;
F_5 ( 0xffffffff , V_7 + F_4 ( 1 ) ) ;
F_5 ( 0xffffffff , V_7 + F_4 ( 2 ) ) ;
F_5 ( 0x01 , V_7 + V_20 ) ;
F_5 ( 0x00 , V_7 + V_21 ) ;
V_22 = F_16 ( V_17 , 3 * 32 ,
& V_23 , NULL ) ;
if ( ! V_22 )
F_14 ( L_2 , V_17 -> V_19 ) ;
F_17 ( V_24 ) ;
return 0 ;
}
static T_4 void T_5 V_24 ( struct V_25 * V_26 )
{
T_1 V_3 , V_27 ;
V_27 = F_3 ( V_7 + V_28 ) >> 2 ;
while ( V_27 != 0 ) {
V_3 = F_18 ( V_22 , V_27 ) ;
F_19 ( V_3 , V_26 ) ;
V_27 = F_3 ( V_7 + V_28 ) >> 2 ;
}
}
