static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
V_10 = F_3 ( V_4 ) ;
if ( V_10 == NULL )
return - V_12 ;
if ( V_10 -> V_13 <= 0 )
return 0 ;
if ( V_10 -> V_14 < 1 )
V_10 -> V_14 = 1 ;
else if ( V_10 -> V_14 > 64 )
V_10 -> V_14 = 64 ;
if ( F_4 ( & V_6 ) < 0 )
return - V_15 ;
F_5 ( V_6 ) ;
V_8 = V_10 -> V_16 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_14 = V_10 -> V_14 ;
V_6 -> V_17 = V_10 -> V_13 ;
V_6 -> V_18 = - 501 ;
V_6 -> V_19 = V_8 -> V_19 ;
V_6 -> V_20 = V_10 -> V_13 < 2 ? V_10 -> V_13 : 2 ;
V_6 -> V_21 = V_8 -> V_22 ? 2 : 1 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 2 ;
if ( F_6 ( V_6 , V_4 -> V_25 , V_10 -> V_26 , L_1 ) < 0 ) {
F_7 ( V_6 ) ;
return - V_15 ;
}
F_8 ( & V_8 -> V_27 , V_11 ) ;
V_8 -> V_28 = V_6 ;
V_8 -> V_29 = V_30 ;
F_9 ( & V_8 -> V_27 , V_11 ) ;
V_4 -> V_31 = V_6 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_11 ;
if ( V_4 -> V_31 == NULL )
return 0 ;
V_6 = V_4 -> V_31 ;
V_8 = V_6 -> V_8 ;
F_8 ( & V_8 -> V_27 , V_11 ) ;
V_8 -> V_28 = NULL ;
V_8 -> V_29 = NULL ;
F_9 ( & V_8 -> V_27 , V_11 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
