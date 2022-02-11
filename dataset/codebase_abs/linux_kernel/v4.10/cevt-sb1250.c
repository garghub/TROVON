static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
V_3 = F_2 ( F_3 ( F_4 () , V_4 ) ) ;
F_5 ( 0 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_4 () ;
void T_1 * V_3 , * V_6 ;
V_3 = F_2 ( F_3 ( V_5 , V_4 ) ) ;
V_6 = F_2 ( F_3 ( V_5 , V_7 ) ) ;
F_5 ( 0 , V_3 ) ;
F_5 ( ( V_8 / V_9 ) - 1 , V_6 ) ;
F_5 ( V_10 | V_11 , V_3 ) ;
return 0 ;
}
static int F_7 ( unsigned long V_12 , struct V_1 * V_13 )
{
unsigned int V_5 = F_4 () ;
void T_1 * V_3 , * V_6 ;
V_3 = F_2 ( F_3 ( V_5 , V_4 ) ) ;
V_6 = F_2 ( F_3 ( V_5 , V_7 ) ) ;
F_5 ( 0 , V_3 ) ;
F_5 ( V_12 - 1 , V_6 ) ;
F_5 ( V_10 , V_3 ) ;
return 0 ;
}
static T_2 F_8 ( int V_14 , void * V_15 )
{
unsigned int V_5 = F_4 () ;
struct V_1 * V_13 = V_15 ;
void T_1 * V_3 ;
unsigned long V_16 ;
if ( F_9 ( V_13 ) )
V_16 = V_10 | V_11 ;
else
V_16 = 0 ;
V_3 = F_2 ( F_3 ( V_5 , V_4 ) ) ;
F_10 ( V_16 , V_3 ) ;
V_13 -> V_17 ( V_13 ) ;
return V_18 ;
}
void F_11 ( void )
{
unsigned int V_5 = F_4 () ;
unsigned int V_14 = V_19 + V_5 ;
struct V_20 * V_21 = & F_12 ( V_22 , V_5 ) ;
struct V_1 * V_13 = & F_12 ( V_23 , V_5 ) ;
unsigned char * V_24 = F_12 ( V_25 , V_5 ) ;
F_13 ( V_5 > 2 ) ;
sprintf ( V_24 , L_1 , V_5 ) ;
V_13 -> V_24 = V_24 ;
V_13 -> V_26 = V_27 |
V_28 ;
F_14 ( V_13 , V_8 ) ;
V_13 -> V_29 = F_15 ( 0x7fffff , V_13 ) ;
V_13 -> V_30 = F_15 ( 2 , V_13 ) ;
V_13 -> V_31 = 200 ;
V_13 -> V_14 = V_14 ;
V_13 -> V_32 = F_16 ( V_5 ) ;
V_13 -> V_33 = F_7 ;
V_13 -> V_34 = F_1 ;
V_13 -> V_35 = F_6 ;
V_13 -> V_36 = F_1 ;
F_17 ( V_13 ) ;
F_18 ( V_5 , V_14 ) ;
F_5 ( V_37 ,
F_2 ( F_19 ( V_5 , V_38 ) +
( V_14 << 3 ) ) ) ;
F_20 ( V_5 , V_14 ) ;
V_21 -> V_39 = F_8 ;
V_21 -> V_40 = V_41 | V_42 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_15 = V_13 ;
F_21 ( V_14 , F_16 ( V_5 ) ) ;
F_22 ( V_14 , V_21 ) ;
}
