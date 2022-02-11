static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
if ( V_3 != 0 )
return;
F_3 ( F_4 ( 0 ) , V_4 + F_5 ( 0 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
unsigned int V_5 = V_3 % 32 ;
int V_6 = V_3 / 32 ;
T_1 V_7 ;
V_7 = F_7 ( V_4 + F_8 ( V_6 ) ) ;
F_3 ( V_7 & ~ ( 1 << V_5 ) ,
V_4 + F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
unsigned int V_5 = V_3 % 32 ;
int V_6 = V_3 / 32 ;
T_1 V_7 ;
V_7 = F_7 ( V_4 + F_8 ( V_6 ) ) ;
F_3 ( V_7 | ( 1 << V_5 ) ,
V_4 + F_8 ( V_6 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
T_2 V_11 )
{
F_11 ( V_10 , & V_12 , V_13 ) ;
F_12 ( V_10 ) ;
return 0 ;
}
static int T_3 F_13 ( struct V_14 * V_15 ,
struct V_14 * V_16 )
{
V_4 = F_14 ( V_15 , 0 ) ;
if ( ! V_4 )
F_15 ( L_1 ,
V_15 -> V_17 ) ;
F_3 ( 0 , V_4 + F_8 ( 0 ) ) ;
F_3 ( 0 , V_4 + F_8 ( 1 ) ) ;
F_3 ( 0 , V_4 + F_8 ( 2 ) ) ;
F_3 ( 0 , V_4 + F_16 ( 0 ) ) ;
F_3 ( 0 , V_4 + F_16 ( 1 ) ) ;
F_3 ( 0 , V_4 + F_16 ( 2 ) ) ;
F_3 ( 0xffffffff , V_4 + F_5 ( 0 ) ) ;
F_3 ( 0xffffffff , V_4 + F_5 ( 1 ) ) ;
F_3 ( 0xffffffff , V_4 + F_5 ( 2 ) ) ;
F_3 ( 0x01 , V_4 + V_18 ) ;
F_3 ( 0x00 , V_4 + V_19 ) ;
V_20 = F_17 ( V_15 , 3 * 32 ,
& V_21 , NULL ) ;
if ( ! V_20 )
F_15 ( L_2 , V_15 -> V_17 ) ;
F_18 ( V_22 ) ;
return 0 ;
}
static void T_4 V_22 ( struct V_23 * V_24 )
{
T_1 V_25 ;
V_25 = F_7 ( V_4 + V_26 ) >> 2 ;
if ( V_25 == 0 &&
! ( F_7 ( V_4 + F_5 ( 0 ) ) & F_4 ( 0 ) ) )
return;
do {
F_19 ( V_20 , V_25 , V_24 ) ;
V_25 = F_7 ( V_4 + V_26 ) >> 2 ;
} while ( V_25 != 0 );
}
