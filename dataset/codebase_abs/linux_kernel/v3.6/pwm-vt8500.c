static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = F_2 ( 10 ) ;
while ( ( F_3 ( V_1 ) & V_2 ) && -- V_3 )
F_4 () ;
if ( F_5 ( ! V_3 ) )
F_6 ( L_1 ,
V_2 ) ;
}
static int F_7 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = F_8 ( V_5 ) ;
unsigned long long V_12 ;
unsigned long V_13 , V_14 , V_15 , V_16 ;
V_12 = 25000000 / 2 ;
V_12 = V_12 * V_9 ;
F_9 ( V_12 , 1000000000 ) ;
V_13 = V_12 ;
if ( V_13 < 1 )
V_13 = 1 ;
V_14 = ( V_13 - 1 ) / 4096 ;
V_15 = V_13 / ( V_14 + 1 ) - 1 ;
if ( V_15 > 4095 )
V_15 = 4095 ;
if ( V_14 > 1023 )
return - V_17 ;
V_12 = ( unsigned long long ) V_15 * V_8 ;
F_9 ( V_12 , V_9 ) ;
V_16 = V_12 ;
F_1 ( V_11 -> V_18 + 0x40 + V_7 -> V_19 , ( 1 << 1 ) ) ;
F_10 ( V_14 , V_11 -> V_18 + 0x4 + ( V_7 -> V_19 << 4 ) ) ;
F_1 ( V_11 -> V_18 + 0x40 + V_7 -> V_19 , ( 1 << 2 ) ) ;
F_10 ( V_15 , V_11 -> V_18 + 0x8 + ( V_7 -> V_19 << 4 ) ) ;
F_1 ( V_11 -> V_18 + 0x40 + V_7 -> V_19 , ( 1 << 3 ) ) ;
F_10 ( V_16 , V_11 -> V_18 + 0xc + ( V_7 -> V_19 << 4 ) ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_5 ) ;
F_1 ( V_11 -> V_18 + 0x40 + V_7 -> V_19 , ( 1 << 0 ) ) ;
F_10 ( 5 , V_11 -> V_18 + ( V_7 -> V_19 << 4 ) ) ;
return 0 ;
}
static void F_12 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_5 ) ;
F_1 ( V_11 -> V_18 + 0x40 + V_7 -> V_19 , ( 1 << 0 ) ) ;
F_10 ( 0 , V_11 -> V_18 + ( V_7 -> V_19 << 4 ) ) ;
}
static int T_3 F_13 ( struct V_20 * V_21 )
{
struct V_10 * V_5 ;
struct V_22 * V_23 ;
int V_24 ;
V_5 = F_14 ( & V_21 -> V_25 , sizeof( * V_5 ) , V_26 ) ;
if ( V_5 == NULL ) {
F_15 ( & V_21 -> V_25 , L_2 ) ;
return - V_27 ;
}
V_5 -> V_5 . V_25 = & V_21 -> V_25 ;
V_5 -> V_5 . V_28 = & V_29 ;
V_5 -> V_5 . V_18 = - 1 ;
V_5 -> V_5 . V_30 = V_31 ;
V_23 = F_16 ( V_21 , V_32 , 0 ) ;
if ( V_23 == NULL ) {
F_15 ( & V_21 -> V_25 , L_3 ) ;
return - V_33 ;
}
V_5 -> V_18 = F_17 ( & V_21 -> V_25 , V_23 ) ;
if ( V_5 -> V_18 == NULL )
return - V_34 ;
V_24 = F_18 ( & V_5 -> V_5 ) ;
if ( V_24 < 0 )
return V_24 ;
F_19 ( V_21 , V_5 ) ;
return V_24 ;
}
static int T_4 F_20 ( struct V_20 * V_21 )
{
struct V_10 * V_5 ;
V_5 = F_21 ( V_21 ) ;
if ( V_5 == NULL )
return - V_33 ;
return F_22 ( & V_5 -> V_5 ) ;
}
static int T_5 F_23 ( void )
{
return F_24 ( & V_35 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_35 ) ;
}
