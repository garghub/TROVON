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
static int F_8 ( struct V_2 * V_3 , unsigned long V_11 ,
void * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
V_8 = 128 * V_4 -> V_9 / 1000 ;
F_4 ( 0 , V_4 -> V_5 + V_6 ) ;
F_4 ( 1 , V_4 -> V_5 + V_7 ) ;
F_4 ( V_8 , V_4 -> V_5 + V_10 ) ;
F_4 ( 1 , V_4 -> V_5 + V_6 ) ;
F_9 () ;
F_10 ( 150 ) ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_19 . V_20 ;
T_1 V_21 ;
int V_22 ;
V_4 = F_12 ( & V_14 -> V_19 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_16 = F_13 ( V_14 , V_25 , 0 ) ;
if ( F_14 ( V_18 , L_1 , & V_21 ) )
V_21 = 0 ;
V_16 -> V_26 += V_21 ;
V_16 -> V_27 += V_21 ;
V_4 -> V_5 = F_15 ( & V_14 -> V_19 , V_16 ) ;
if ( F_16 ( V_4 -> V_5 ) )
return F_17 ( V_4 -> V_5 ) ;
V_4 -> V_28 = F_18 ( & V_14 -> V_19 , NULL ) ;
if ( F_16 ( V_4 -> V_28 ) ) {
F_19 ( & V_14 -> V_19 , L_2 ) ;
return F_17 ( V_4 -> V_28 ) ;
}
V_22 = F_20 ( V_4 -> V_28 ) ;
if ( V_22 ) {
F_19 ( & V_14 -> V_19 , L_3 ) ;
return V_22 ;
}
V_4 -> V_9 = F_21 ( V_4 -> V_28 ) ;
if ( V_4 -> V_9 == 0 ||
V_4 -> V_9 > 0x10000000U ) {
F_19 ( & V_14 -> V_19 , L_4 ) ;
V_22 = - V_29 ;
goto V_30;
}
V_4 -> V_3 . V_31 = & V_32 ;
V_4 -> V_3 . V_33 = & V_34 ;
V_4 -> V_3 . V_35 = 1 ;
V_4 -> V_3 . V_36 = 0x10000000U / V_4 -> V_9 ;
V_4 -> V_3 . V_37 = & V_14 -> V_19 ;
V_4 -> V_3 . V_8 = F_22 ( V_4 -> V_3 . V_36 , 30U ) ;
F_23 ( & V_4 -> V_3 , 0 , & V_14 -> V_19 ) ;
V_22 = F_24 ( & V_4 -> V_3 ) ;
if ( V_22 ) {
F_19 ( & V_14 -> V_19 , L_5 ) ;
goto V_30;
}
F_25 ( V_14 , V_4 ) ;
return 0 ;
V_30:
F_26 ( V_4 -> V_28 ) ;
return V_22 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_4 = F_28 ( V_14 ) ;
F_29 ( & V_4 -> V_3 ) ;
F_26 ( V_4 -> V_28 ) ;
return 0 ;
}
