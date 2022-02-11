static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_4 ) & ~ ( 0x03 << 27 ) ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_4 ) & ~ ( 0x03 << 27 ) ;
V_3 |= ( V_5 | V_6 | V_7 | V_8 ) ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_4 ) & ~ ( 0x03 << 27 ) ;
F_3 ( V_9 , V_10 ) ;
V_3 |= ( V_11 | V_6 | V_7 | V_8 ) ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_6 ( unsigned long V_2 ,
struct V_1 * V_12 )
{
unsigned int V_3 ;
F_3 ( V_2 , V_10 ) ;
V_3 = F_2 ( V_4 ) ;
V_3 |= ( V_6 | V_7 | V_8 ) ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static T_1 F_7 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = & V_15 ;
F_3 ( 0x01 , V_16 ) ;
V_2 -> V_17 ( V_2 ) ;
return V_18 ;
}
static void T_2 F_8 ( void )
{
unsigned int V_19 ;
struct V_12 * V_12 = F_9 ( NULL , L_1 ) ;
F_10 ( F_11 ( V_12 ) ) ;
F_3 ( 0x00 , V_4 ) ;
F_12 ( V_12 ) ;
V_19 = F_13 ( V_12 ) / ( V_8 + 1 ) ;
V_9 = ( V_19 / V_20 ) ;
F_3 ( V_21 , V_16 ) ;
F_14 ( V_22 , & V_23 ) ;
V_15 . V_24 = F_15 ( 0 ) ;
F_16 ( & V_15 , V_19 ,
0xf , 0xffffffff ) ;
}
static void T_2 F_17 ( void )
{
unsigned int V_3 ;
unsigned int V_19 ;
struct V_12 * V_12 = F_9 ( NULL , L_2 ) ;
F_10 ( F_11 ( V_12 ) ) ;
F_3 ( 0x00 , V_25 ) ;
F_12 ( V_12 ) ;
V_19 = F_13 ( V_12 ) / ( V_8 + 1 ) ;
F_3 ( 0xffffffff , V_26 ) ;
V_3 = F_2 ( V_25 ) ;
V_3 |= ( V_6 | V_11 | V_8 ) ;
F_3 ( V_3 , V_25 ) ;
F_18 ( V_27 , L_3 , V_19 , 200 ,
V_28 , V_29 ) ;
}
void T_2 F_19 ( void )
{
F_17 () ;
F_8 () ;
}
