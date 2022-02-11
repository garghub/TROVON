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
V_7 -> V_20 = F_5 ( V_11 ) ;
if ( ! F_6 ( V_7 -> V_19 , V_7 -> V_20 , V_21 ) ) {
F_2 ( L_5 , __FILE__ ) ;
V_5 = - V_22 ;
goto V_23;
}
V_7 -> V_24 = F_7 ( V_7 -> V_19 , V_7 -> V_20 ) ;
if ( ! V_7 -> V_24 ) {
F_2 ( L_6 , __FILE__ ) ;
V_5 = - V_18 ;
goto V_25;
}
V_9 = F_8 ( V_7 ) ;
V_9 -> V_26 |= V_27 | V_28 ;
#ifdef F_9
V_9 -> V_26 |= V_29 ;
#endif
F_10 ( V_9 ) ;
V_5 = F_11 ( V_7 , V_12 , 0 ) ;
if ( V_5 == 0 )
return V_5 ;
F_2 ( L_7 ) ;
F_12 ( V_7 -> V_24 ) ;
V_25:
F_13 ( V_7 -> V_19 , V_7 -> V_20 ) ;
V_23:
F_14 ( V_7 ) ;
return V_5 ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
F_16 ( V_7 ) ;
F_2 ( L_8 ) ;
F_12 ( V_7 -> V_24 ) ;
F_13 ( V_7 -> V_19 , V_7 -> V_20 ) ;
F_14 ( V_7 ) ;
}
static int T_1
F_17 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_8 ( V_7 ) ;
int V_30 ;
if ( ( V_30 = F_18 ( V_9 ) ) < 0 )
return V_30 ;
if ( ( V_30 = F_19 ( V_9 ) ) < 0 ) {
F_20 ( V_7 -> V_31 . V_32 , L_9 ,
V_7 -> V_31 . V_33 ) ;
F_21 ( V_7 ) ;
return V_30 ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_30 ;
if ( F_23 () )
return - V_14 ;
V_30 = F_1 ( & V_34 , V_4 ) ;
return V_30 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_25 ( V_4 ) ;
F_15 ( V_7 , V_4 ) ;
return 0 ;
}
