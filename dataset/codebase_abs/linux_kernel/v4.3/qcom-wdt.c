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
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
T_1 V_25 ;
int V_26 ;
V_4 = F_12 ( & V_18 -> V_23 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_20 = F_13 ( V_18 , V_29 , 0 ) ;
if ( F_14 ( V_22 , L_1 , & V_25 ) )
V_25 = 0 ;
V_20 -> V_30 += V_25 ;
V_20 -> V_31 += V_25 ;
V_4 -> V_5 = F_15 ( & V_18 -> V_23 , V_20 ) ;
if ( F_16 ( V_4 -> V_5 ) )
return F_17 ( V_4 -> V_5 ) ;
V_4 -> V_32 = F_18 ( & V_18 -> V_23 , NULL ) ;
if ( F_16 ( V_4 -> V_32 ) ) {
F_19 ( & V_18 -> V_23 , L_2 ) ;
return F_17 ( V_4 -> V_32 ) ;
}
V_26 = F_20 ( V_4 -> V_32 ) ;
if ( V_26 ) {
F_19 ( & V_18 -> V_23 , L_3 ) ;
return V_26 ;
}
V_4 -> V_9 = F_21 ( V_4 -> V_32 ) ;
if ( V_4 -> V_9 == 0 ||
V_4 -> V_9 > 0x10000000U ) {
F_19 ( & V_18 -> V_23 , L_4 ) ;
V_26 = - V_33 ;
goto V_34;
}
V_4 -> V_3 . V_23 = & V_18 -> V_23 ;
V_4 -> V_3 . V_35 = & V_36 ;
V_4 -> V_3 . V_37 = & V_38 ;
V_4 -> V_3 . V_39 = 1 ;
V_4 -> V_3 . V_40 = 0x10000000U / V_4 -> V_9 ;
V_4 -> V_3 . V_41 = & V_18 -> V_23 ;
V_4 -> V_3 . V_8 = F_22 ( V_4 -> V_3 . V_40 , 30U ) ;
F_23 ( & V_4 -> V_3 , 0 , & V_18 -> V_23 ) ;
V_26 = F_24 ( & V_4 -> V_3 ) ;
if ( V_26 ) {
F_19 ( & V_18 -> V_23 , L_5 ) ;
goto V_34;
}
V_4 -> V_15 . V_42 = F_8 ;
V_26 = F_25 ( & V_4 -> V_15 ) ;
if ( V_26 )
F_19 ( & V_18 -> V_23 , L_6 ) ;
F_26 ( V_18 , V_4 ) ;
return 0 ;
V_34:
F_27 ( V_4 -> V_32 ) ;
return V_26 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_1 * V_4 = F_29 ( V_18 ) ;
F_30 ( & V_4 -> V_15 ) ;
F_31 ( & V_4 -> V_3 ) ;
F_27 ( V_4 -> V_32 ) ;
return 0 ;
}
