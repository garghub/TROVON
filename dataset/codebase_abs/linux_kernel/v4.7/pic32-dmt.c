static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_2 -> V_4 + V_5 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_5 ( V_2 -> V_4 + V_5 ) ) ;
F_6 () ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_8 ( V_2 -> V_4 + V_7 ) ;
V_6 &= ( V_8 | V_9 | V_10 ) ;
if ( V_6 )
return - V_11 ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
T_1 V_12 ;
T_1 V_13 = 500 ;
F_2 ( V_14 << 8 , V_2 -> V_4 + V_15 ) ;
while ( -- V_13 ) {
V_12 = F_8 ( V_2 -> V_4 + V_7 ) & V_16 ;
if ( V_12 == V_16 )
break;
}
F_2 ( V_17 , V_2 -> V_4 + V_18 ) ;
return F_7 ( V_2 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
V_19 = F_11 ( V_2 -> V_20 ) ;
if ( V_19 )
return F_8 ( V_2 -> V_4 + V_21 ) / V_19 ;
return 0 ;
}
static inline T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_12 ;
void T_2 * V_22 ;
V_22 = F_13 ( V_23 , 0x10 ) ;
if ( ! V_22 )
return 0 ;
V_12 = F_8 ( V_22 ) ;
F_2 ( V_24 , F_5 ( V_22 ) ) ;
F_14 ( V_22 ) ;
return V_12 & V_24 ;
}
static int F_15 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
F_1 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
return F_9 ( V_2 ) ;
}
static int F_19 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_25 * V_26 = & V_32 ;
V_2 = F_20 ( & V_28 -> V_33 , sizeof( * V_2 ) , V_34 ) ;
if ( F_21 ( V_2 ) )
return F_22 ( V_2 ) ;
V_31 = F_23 ( V_28 , V_35 , 0 ) ;
V_2 -> V_4 = F_24 ( & V_28 -> V_33 , V_31 ) ;
if ( F_21 ( V_2 -> V_4 ) )
return F_22 ( V_2 -> V_4 ) ;
V_2 -> V_20 = F_25 ( & V_28 -> V_33 , NULL ) ;
if ( F_21 ( V_2 -> V_20 ) ) {
F_26 ( & V_28 -> V_33 , L_1 ) ;
return F_22 ( V_2 -> V_20 ) ;
}
V_29 = F_27 ( V_2 -> V_20 ) ;
if ( V_29 )
return V_29 ;
V_26 -> V_13 = F_10 ( V_2 ) ;
if ( ! V_26 -> V_13 ) {
F_26 ( & V_28 -> V_33 ,
L_2 ) ;
V_29 = - V_36 ;
goto V_37;
}
F_28 ( & V_28 -> V_33 , L_3 , V_26 -> V_13 ) ;
V_26 -> V_38 = F_12 ( V_2 ) ? V_39 : 0 ;
F_29 ( V_26 , V_40 ) ;
F_30 ( V_26 , V_2 ) ;
V_29 = F_31 ( V_26 ) ;
if ( V_29 ) {
F_26 ( & V_28 -> V_33 , L_4 , V_29 ) ;
goto V_37;
}
F_32 ( V_28 , V_26 ) ;
return 0 ;
V_37:
F_33 ( V_2 -> V_20 ) ;
return V_29 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_25 * V_26 = F_35 ( V_28 ) ;
struct V_1 * V_2 = F_16 ( V_26 ) ;
F_36 ( V_26 ) ;
F_33 ( V_2 -> V_20 ) ;
return 0 ;
}
