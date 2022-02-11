static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( 0 , V_4 -> V_5 + V_6 ) ;
F_4 ( 1 , V_4 -> V_5 + V_7 ) ;
F_4 ( V_3 -> V_8 * V_4 -> V_9 , V_4 -> V_5 + V_10 ) ;
F_4 ( 1 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( 0 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( 1 , V_4 -> V_5 + V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned int V_8 )
{
V_3 -> V_8 = V_8 ;
return F_3 ( V_3 ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned long V_13 ,
void * V_14 )
{
struct V_1 * V_4 = F_2 ( V_12 , struct V_1 , V_15 ) ;
T_1 V_8 ;
V_8 = 128 * V_4 -> V_9 / 1000 ;
F_4 ( 0 , V_4 -> V_5 + V_6 ) ;
F_4 ( 1 , V_4 -> V_5 + V_7 ) ;
F_4 ( V_8 , V_4 -> V_5 + V_10 ) ;
F_4 ( 1 , V_4 -> V_5 + V_6 ) ;
F_9 () ;
F_10 ( 150 ) ;
return V_16 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_4 ;
struct V_19 * V_20 ;
int V_21 ;
V_4 = F_12 ( & V_18 -> V_22 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_20 = F_13 ( V_18 , V_25 , 0 ) ;
V_4 -> V_5 = F_14 ( & V_18 -> V_22 , V_20 ) ;
if ( F_15 ( V_4 -> V_5 ) )
return F_16 ( V_4 -> V_5 ) ;
V_4 -> V_26 = F_17 ( & V_18 -> V_22 , NULL ) ;
if ( F_15 ( V_4 -> V_26 ) ) {
F_18 ( & V_18 -> V_22 , L_1 ) ;
return F_16 ( V_4 -> V_26 ) ;
}
V_21 = F_19 ( V_4 -> V_26 ) ;
if ( V_21 ) {
F_18 ( & V_18 -> V_22 , L_2 ) ;
return V_21 ;
}
V_4 -> V_9 = F_20 ( V_4 -> V_26 ) ;
if ( V_4 -> V_9 == 0 ||
V_4 -> V_9 > 0x10000000U ) {
F_18 ( & V_18 -> V_22 , L_3 ) ;
V_21 = - V_27 ;
goto V_28;
}
V_4 -> V_3 . V_22 = & V_18 -> V_22 ;
V_4 -> V_3 . V_29 = & V_30 ;
V_4 -> V_3 . V_31 = & V_32 ;
V_4 -> V_3 . V_33 = 1 ;
V_4 -> V_3 . V_34 = 0x10000000U / V_4 -> V_9 ;
V_4 -> V_3 . V_8 = F_21 ( V_4 -> V_3 . V_34 , 30U ) ;
F_22 ( & V_4 -> V_3 , 0 , & V_18 -> V_22 ) ;
V_21 = F_23 ( & V_4 -> V_3 ) ;
if ( V_21 ) {
F_18 ( & V_18 -> V_22 , L_4 ) ;
goto V_28;
}
V_4 -> V_15 . V_35 = F_8 ;
V_21 = F_24 ( & V_4 -> V_15 ) ;
if ( V_21 )
F_18 ( & V_18 -> V_22 , L_5 ) ;
F_25 ( V_18 , V_4 ) ;
return 0 ;
V_28:
F_26 ( V_4 -> V_26 ) ;
return V_21 ;
}
static int F_27 ( struct V_17 * V_18 )
{
struct V_1 * V_4 = F_28 ( V_18 ) ;
F_29 ( & V_4 -> V_15 ) ;
F_30 ( & V_4 -> V_3 ) ;
F_26 ( V_4 -> V_26 ) ;
return 0 ;
}
