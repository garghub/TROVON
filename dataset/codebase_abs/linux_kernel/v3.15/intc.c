static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static unsigned int F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( T_1 V_1 , void T_2 * V_2 )
{
F_6 ( V_1 , V_2 ) ;
}
static unsigned int F_7 ( void T_2 * V_2 )
{
return F_8 ( V_2 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
unsigned long V_5 = 1 << V_4 -> V_6 ;
F_10 ( L_1 , V_4 -> V_6 ) ;
if ( F_11 ( V_4 ) )
F_12 ( V_5 , V_7 + V_8 ) ;
F_12 ( V_5 , V_7 + V_9 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_10 ( L_2 , V_4 -> V_6 ) ;
F_12 ( 1 << V_4 -> V_6 , V_7 + V_10 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_10 ( L_3 , V_4 -> V_6 ) ;
F_12 ( 1 << V_4 -> V_6 , V_7 + V_8 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
unsigned long V_5 = 1 << V_4 -> V_6 ;
F_10 ( L_4 , V_4 -> V_6 ) ;
F_12 ( V_5 , V_7 + V_10 ) ;
F_12 ( V_5 , V_7 + V_8 ) ;
}
unsigned int F_16 ( void )
{
unsigned int V_6 , V_11 = - 1 ;
V_6 = F_17 ( V_7 + V_12 ) ;
if ( V_6 != - 1U )
V_11 = F_18 ( V_13 , V_6 ) ;
F_10 ( L_5 , V_6 , V_11 ) ;
return V_11 ;
}
static int F_19 ( struct V_14 * V_4 , unsigned int V_11 , T_3 V_15 )
{
T_1 V_16 = ( T_1 ) V_4 -> V_17 ;
if ( V_16 & ( 1 << V_15 ) ) {
F_20 ( V_11 , & V_18 ,
V_19 , L_6 ) ;
F_21 ( V_11 , V_20 ) ;
} else {
F_20 ( V_11 , & V_18 ,
V_21 , L_7 ) ;
F_22 ( V_11 , V_20 ) ;
}
return 0 ;
}
static int T_4 F_23 ( struct V_22 * V_23 ,
struct V_22 * V_24 )
{
T_1 V_25 , V_16 ;
int V_26 ;
V_7 = F_24 ( V_23 , 0 ) ;
F_25 ( ! V_7 ) ;
V_26 = F_26 ( V_23 , L_8 , & V_25 ) ;
if ( V_26 < 0 ) {
F_27 ( L_9 , V_27 ) ;
return - V_28 ;
}
V_26 = F_26 ( V_23 , L_10 , & V_16 ) ;
if ( V_26 < 0 ) {
F_27 ( L_11 , V_27 ) ;
return - V_28 ;
}
if ( V_16 > ( T_1 ) ( ( 1ULL << V_25 ) - 1 ) )
F_28 ( L_12 ) ;
F_28 ( L_13 ,
V_23 -> V_29 , V_25 , V_16 ) ;
F_12 = F_1 ;
F_17 = F_3 ;
F_12 ( 0 , V_7 + V_30 ) ;
F_12 ( 0xffffffff , V_7 + V_8 ) ;
F_12 ( V_31 | V_32 , V_7 + V_33 ) ;
if ( ! ( F_17 ( V_7 + V_33 ) & ( V_31 | V_32 ) ) ) {
F_12 = F_5 ;
F_17 = F_7 ;
F_12 ( V_31 | V_32 , V_7 + V_33 ) ;
}
V_13 = F_29 ( V_23 , V_25 , & V_34 ,
( void * ) V_16 ) ;
F_30 ( V_13 ) ;
return 0 ;
}
