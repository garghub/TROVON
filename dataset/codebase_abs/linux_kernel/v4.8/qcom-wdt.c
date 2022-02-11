static void T_1 * F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
return V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ;
}
static inline
struct V_1 * F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , struct V_1 , V_8 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_2 ( V_8 ) ;
F_5 ( 0 , F_1 ( V_2 , V_9 ) ) ;
F_5 ( 1 , F_1 ( V_2 , V_10 ) ) ;
F_5 ( V_8 -> V_11 * V_2 -> V_12 , F_1 ( V_2 , V_13 ) ) ;
F_5 ( V_8 -> V_11 * V_2 -> V_12 , F_1 ( V_2 , V_14 ) ) ;
F_5 ( 1 , F_1 ( V_2 , V_9 ) ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_2 ( V_8 ) ;
F_5 ( 0 , F_1 ( V_2 , V_9 ) ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_2 ( V_8 ) ;
F_5 ( 1 , F_1 ( V_2 , V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned int V_11 )
{
V_8 -> V_11 = V_11 ;
return F_4 ( V_8 ) ;
}
static int F_9 ( struct V_7 * V_8 , unsigned long V_15 ,
void * V_16 )
{
struct V_1 * V_2 = F_2 ( V_8 ) ;
T_2 V_11 ;
V_11 = 128 * V_2 -> V_12 / 1000 ;
F_5 ( 0 , F_1 ( V_2 , V_9 ) ) ;
F_5 ( 1 , F_1 ( V_2 , V_10 ) ) ;
F_5 ( V_11 , F_1 ( V_2 , V_13 ) ) ;
F_5 ( V_11 , F_1 ( V_2 , V_14 ) ) ;
F_5 ( 1 , F_1 ( V_2 , V_9 ) ) ;
F_10 () ;
F_11 ( 150 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
const T_2 * V_25 ;
T_2 V_26 ;
int V_27 ;
V_25 = F_13 ( & V_18 -> V_23 ) ;
if ( ! V_25 ) {
F_14 ( & V_18 -> V_23 , L_1 ) ;
return - V_28 ;
}
V_2 = F_15 ( & V_18 -> V_23 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_20 = F_16 ( V_18 , V_31 , 0 ) ;
if ( F_17 ( V_22 , L_2 , & V_26 ) )
V_26 = 0 ;
V_20 -> V_32 += V_26 ;
V_20 -> V_33 += V_26 ;
V_2 -> V_5 = F_18 ( & V_18 -> V_23 , V_20 ) ;
if ( F_19 ( V_2 -> V_5 ) )
return F_20 ( V_2 -> V_5 ) ;
V_2 -> V_34 = F_21 ( & V_18 -> V_23 , NULL ) ;
if ( F_19 ( V_2 -> V_34 ) ) {
F_14 ( & V_18 -> V_23 , L_3 ) ;
return F_20 ( V_2 -> V_34 ) ;
}
V_27 = F_22 ( V_2 -> V_34 ) ;
if ( V_27 ) {
F_14 ( & V_18 -> V_23 , L_4 ) ;
return V_27 ;
}
V_2 -> V_12 = F_23 ( V_2 -> V_34 ) ;
if ( V_2 -> V_12 == 0 ||
V_2 -> V_12 > 0x10000000U ) {
F_14 ( & V_18 -> V_23 , L_5 ) ;
V_27 = - V_35 ;
goto V_36;
}
V_2 -> V_8 . V_37 = & V_38 ;
V_2 -> V_8 . V_39 = & V_40 ;
V_2 -> V_8 . V_41 = 1 ;
V_2 -> V_8 . V_42 = 0x10000000U / V_2 -> V_12 ;
V_2 -> V_8 . V_43 = & V_18 -> V_23 ;
V_2 -> V_6 = V_25 ;
if ( F_24 ( V_2 -> V_5 + V_44 ) & 1 )
V_2 -> V_8 . V_45 = V_46 ;
V_2 -> V_8 . V_11 = F_25 ( V_2 -> V_8 . V_42 , 30U ) ;
F_26 ( & V_2 -> V_8 , 0 , & V_18 -> V_23 ) ;
V_27 = F_27 ( & V_2 -> V_8 ) ;
if ( V_27 ) {
F_14 ( & V_18 -> V_23 , L_6 ) ;
goto V_36;
}
F_28 ( V_18 , V_2 ) ;
return 0 ;
V_36:
F_29 ( V_2 -> V_34 ) ;
return V_27 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
F_32 ( & V_2 -> V_8 ) ;
F_29 ( V_2 -> V_34 ) ;
return 0 ;
}
