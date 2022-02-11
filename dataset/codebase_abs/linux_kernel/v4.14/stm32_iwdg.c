static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
T_1 V_3 = V_8 | V_9 ;
T_1 V_10 ;
int V_11 ;
F_7 ( V_5 -> V_12 , L_1 , V_13 ) ;
V_10 = F_8 (unsigned int, ((wdd->timeout * wdt->rate) / 256) - 1 ,
RLR_MIN, RLR_MAX) ;
F_3 ( V_7 -> V_14 , V_15 , V_16 ) ;
F_3 ( V_7 -> V_14 , V_17 , V_18 ) ;
F_3 ( V_7 -> V_14 , V_19 , V_10 ) ;
F_3 ( V_7 -> V_14 , V_15 , V_20 ) ;
V_11 = F_9 ( V_7 -> V_14 + V_21 , V_3 ,
! ( V_3 & ( V_8 | V_9 ) ) ,
V_22 , V_23 ) ;
if ( V_11 ) {
F_10 ( V_5 -> V_12 ,
L_2 ) ;
return V_11 ;
}
F_3 ( V_7 -> V_14 , V_15 , V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
F_7 ( V_5 -> V_12 , L_1 , V_13 ) ;
F_3 ( V_7 -> V_14 , V_15 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_25 )
{
F_7 ( V_5 -> V_12 , L_3 , V_13 , V_25 ) ;
V_5 -> V_25 = V_25 ;
if ( F_13 ( V_5 ) )
return F_5 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
void T_2 * V_14 ;
struct V_30 * V_30 ;
int V_11 ;
V_29 = F_15 ( V_27 , V_31 , 0 ) ;
V_14 = F_16 ( & V_27 -> V_32 , V_29 ) ;
if ( F_17 ( V_14 ) ) {
F_10 ( & V_27 -> V_32 , L_4 ) ;
return F_18 ( V_14 ) ;
}
V_30 = F_19 ( & V_27 -> V_32 , NULL ) ;
if ( F_17 ( V_30 ) ) {
F_10 ( & V_27 -> V_32 , L_5 ) ;
return F_18 ( V_30 ) ;
}
V_11 = F_20 ( V_30 ) ;
if ( V_11 ) {
F_10 ( & V_27 -> V_32 , L_6 , V_30 ) ;
return V_11 ;
}
V_7 = F_21 ( & V_27 -> V_32 , sizeof( * V_7 ) , V_33 ) ;
if ( ! V_7 ) {
V_11 = - V_34 ;
goto V_35;
}
V_7 -> V_14 = V_14 ;
V_7 -> V_30 = V_30 ;
V_7 -> V_36 = F_22 ( V_30 ) ;
V_5 = & V_7 -> V_5 ;
V_5 -> V_37 = & V_38 ;
V_5 -> V_39 = & V_40 ;
V_5 -> V_41 = ( ( V_42 + 1 ) * 256 ) / V_7 -> V_36 ;
V_5 -> V_43 = ( ( V_44 + 1 ) * 256 * 1000 ) / V_7 -> V_36 ;
V_5 -> V_12 = & V_27 -> V_32 ;
F_23 ( V_5 , V_7 ) ;
F_24 ( V_5 , V_45 ) ;
V_11 = F_25 ( V_5 , 0 , & V_27 -> V_32 ) ;
if ( V_11 )
F_26 ( & V_27 -> V_32 ,
L_7 ) ;
V_11 = F_27 ( V_5 ) ;
if ( V_11 ) {
F_10 ( & V_27 -> V_32 , L_8 ) ;
goto V_35;
}
F_28 ( V_27 , V_7 ) ;
return 0 ;
V_35:
F_29 ( V_30 ) ;
return V_11 ;
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_31 ( V_27 ) ;
F_32 ( & V_7 -> V_5 ) ;
F_29 ( V_7 -> V_30 ) ;
return 0 ;
}
