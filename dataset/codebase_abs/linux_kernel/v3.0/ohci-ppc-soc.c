static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
F_2 ( L_1 ) ;
V_11 = F_3 ( V_4 , V_13 , 0 ) ;
if ( ! V_11 ) {
F_2 ( L_2 , __FILE__ ) ;
return - V_14 ;
}
V_12 = V_11 -> V_15 ;
V_11 = F_3 ( V_4 , V_16 , 0 ) ;
if ( ! V_11 ) {
F_2 ( L_3 , __FILE__ ) ;
return - V_14 ;
}
V_7 = F_4 ( V_2 , & V_4 -> V_17 , L_4 ) ;
if ( ! V_7 )
return - V_18 ;
V_7 -> V_19 = V_11 -> V_15 ;
V_7 -> V_20 = V_11 -> V_21 - V_11 -> V_15 + 1 ;
if ( ! F_5 ( V_7 -> V_19 , V_7 -> V_20 , V_22 ) ) {
F_2 ( L_5 , __FILE__ ) ;
V_5 = - V_23 ;
goto V_24;
}
V_7 -> V_25 = F_6 ( V_7 -> V_19 , V_7 -> V_20 ) ;
if ( ! V_7 -> V_25 ) {
F_2 ( L_6 , __FILE__ ) ;
V_5 = - V_18 ;
goto V_26;
}
V_9 = F_7 ( V_7 ) ;
V_9 -> V_27 |= V_28 | V_29 ;
#ifdef F_8
V_9 -> V_27 |= V_30 ;
#endif
F_9 ( V_9 ) ;
V_5 = F_10 ( V_7 , V_12 , V_31 ) ;
if ( V_5 == 0 )
return V_5 ;
F_2 ( L_7 ) ;
F_11 ( V_7 -> V_25 ) ;
V_26:
F_12 ( V_7 -> V_19 , V_7 -> V_20 ) ;
V_24:
F_13 ( V_7 ) ;
return V_5 ;
}
static void F_14 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
F_15 ( V_7 ) ;
F_2 ( L_8 ) ;
F_11 ( V_7 -> V_25 ) ;
F_12 ( V_7 -> V_19 , V_7 -> V_20 ) ;
F_13 ( V_7 ) ;
}
static int T_1
F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_7 ( V_7 ) ;
int V_32 ;
if ( ( V_32 = F_17 ( V_9 ) ) < 0 )
return V_32 ;
if ( ( V_32 = F_18 ( V_9 ) ) < 0 ) {
F_19 ( L_9 , F_20 ( V_9 ) -> V_33 . V_34 ) ;
F_21 ( V_7 ) ;
return V_32 ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_32 ;
if ( F_23 () )
return - V_14 ;
V_32 = F_1 ( & V_35 , V_4 ) ;
return V_32 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_25 ( V_4 ) ;
F_14 ( V_7 , V_4 ) ;
return 0 ;
}
