static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
return F_4 ( V_4 ) ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_6 ( V_4 ) ;
if ( V_5 < 0 ) {
F_7 ( V_4 , L_1 ) ;
F_8 ( V_2 ) ;
}
return V_5 ;
}
static int F_9 ( struct V_6 * V_7 )
{
unsigned int V_8 = 0 ;
int V_5 ;
F_10 ( & V_7 -> V_7 , L_2 ) ;
if ( F_11 () ||
F_12 () ||
F_13 () ||
F_14 () )
V_8 = V_9 | V_10 ;
F_15 ( V_8 | V_11 | V_12 ,
V_7 -> V_13 + V_14 ) ;
V_5 = F_16 ( V_7 ) ;
if ( V_5 == 0 ) {
F_17 ( 11 ) ;
F_15 ( V_8 , V_7 -> V_13 + V_14 ) ;
}
return V_5 ;
}
static void F_18 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_10 ( & V_7 -> V_7 , L_3 ) ;
V_8 = F_19 ( V_7 -> V_13 + V_14 ) ;
F_15 ( V_8 | V_11 | V_12 ,
V_7 -> V_13 + V_14 ) ;
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
int V_5 ;
if ( F_22 () )
return - V_15 ;
V_2 = F_23 ( & V_16 , & V_7 -> V_7 , L_4 ) ;
if ( ! V_2 )
return - V_17 ;
V_2 -> V_18 = V_7 -> V_19 . V_20 ;
V_2 -> V_21 = F_24 ( & V_7 -> V_19 ) ;
if ( ! F_25 ( V_2 -> V_18 , V_2 -> V_21 , V_22 ) ) {
F_10 ( & V_7 -> V_7 , L_5 ) ;
V_5 = - V_23 ;
goto V_24;
}
V_2 -> V_25 = V_7 -> V_13 ;
V_5 = F_9 ( V_7 ) ;
if ( V_5 )
goto V_26;
V_5 = F_26 ( V_2 , V_7 -> V_27 [ 1 ] , 0 ) ;
if ( V_5 == 0 )
return V_5 ;
F_18 ( V_7 ) ;
V_26:
F_27 ( V_2 -> V_18 , V_2 -> V_21 ) ;
V_24:
F_28 ( V_2 ) ;
return V_5 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
F_31 ( V_2 ) ;
F_18 ( V_7 ) ;
F_27 ( V_2 -> V_18 , V_2 -> V_21 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
if ( F_33 ( V_28 , & V_2 -> V_29 ) ) {
V_2 -> V_30 -> V_31 ( V_2 ) ;
F_18 ( V_7 ) ;
}
}
