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
static int F_8 ( struct V_2 * V_3 )
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
static int F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_4 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_12 -> V_17 . V_18 ;
T_1 V_19 ;
int V_20 ;
V_4 = F_12 ( & V_12 -> V_17 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_14 = F_13 ( V_12 , V_23 , 0 ) ;
if ( F_14 ( V_16 , L_1 , & V_19 ) )
V_19 = 0 ;
V_14 -> V_24 += V_19 ;
V_14 -> V_25 += V_19 ;
V_4 -> V_5 = F_15 ( & V_12 -> V_17 , V_14 ) ;
if ( F_16 ( V_4 -> V_5 ) )
return F_17 ( V_4 -> V_5 ) ;
V_4 -> V_26 = F_18 ( & V_12 -> V_17 , NULL ) ;
if ( F_16 ( V_4 -> V_26 ) ) {
F_19 ( & V_12 -> V_17 , L_2 ) ;
return F_17 ( V_4 -> V_26 ) ;
}
V_20 = F_20 ( V_4 -> V_26 ) ;
if ( V_20 ) {
F_19 ( & V_12 -> V_17 , L_3 ) ;
return V_20 ;
}
V_4 -> V_9 = F_21 ( V_4 -> V_26 ) ;
if ( V_4 -> V_9 == 0 ||
V_4 -> V_9 > 0x10000000U ) {
F_19 ( & V_12 -> V_17 , L_4 ) ;
V_20 = - V_27 ;
goto V_28;
}
V_4 -> V_3 . V_29 = & V_30 ;
V_4 -> V_3 . V_31 = & V_32 ;
V_4 -> V_3 . V_33 = 1 ;
V_4 -> V_3 . V_34 = 0x10000000U / V_4 -> V_9 ;
V_4 -> V_3 . V_35 = & V_12 -> V_17 ;
V_4 -> V_3 . V_8 = F_22 ( V_4 -> V_3 . V_34 , 30U ) ;
F_23 ( & V_4 -> V_3 , 0 , & V_12 -> V_17 ) ;
V_20 = F_24 ( & V_4 -> V_3 ) ;
if ( V_20 ) {
F_19 ( & V_12 -> V_17 , L_5 ) ;
goto V_28;
}
F_25 ( V_12 , V_4 ) ;
return 0 ;
V_28:
F_26 ( V_4 -> V_26 ) ;
return V_20 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_1 * V_4 = F_28 ( V_12 ) ;
F_29 ( & V_4 -> V_3 ) ;
F_26 ( V_4 -> V_26 ) ;
return 0 ;
}
