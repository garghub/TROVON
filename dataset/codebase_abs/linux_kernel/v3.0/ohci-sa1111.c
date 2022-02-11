static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
F_2 ( V_4 L_1 ,
__FILE__ ) ;
#ifdef F_3
if ( F_4 () ) {
F_5 ( V_5 , 1 ) ;
}
#endif
if ( F_6 () ||
F_7 () ||
F_8 () ||
F_4 () )
V_3 = V_6 | V_7 ;
F_9 ( V_3 | V_8 | V_9 ,
V_2 -> V_10 + V_11 ) ;
F_10 ( V_2 ) ;
F_11 ( 11 ) ;
F_9 ( V_3 , V_2 -> V_10 + V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_2 ( V_4 L_2 ,
__FILE__ ) ;
V_3 = F_13 ( V_2 -> V_10 + V_11 ) ;
F_9 ( V_3 | V_8 | V_9 ,
V_2 -> V_10 + V_11 ) ;
F_14 ( V_2 ) ;
#ifdef F_3
if ( F_4 () ) {
F_5 ( V_5 , 0 ) ;
}
#endif
}
int F_15 ( const struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_16 ;
V_15 = F_16 ( V_13 , & V_2 -> V_2 , L_3 ) ;
if ( ! V_15 )
return - V_17 ;
V_15 -> V_18 = V_2 -> V_19 . V_20 ;
V_15 -> V_21 = V_2 -> V_19 . V_22 - V_2 -> V_19 . V_20 + 1 ;
if ( ! F_17 ( V_15 -> V_18 , V_15 -> V_21 , V_23 ) ) {
F_18 ( L_4 ) ;
V_16 = - V_24 ;
goto V_25;
}
V_15 -> V_26 = V_2 -> V_10 ;
F_1 ( V_2 ) ;
F_19 ( F_20 ( V_15 ) ) ;
V_16 = F_21 ( V_15 , V_2 -> V_27 [ 1 ] , V_28 ) ;
if ( V_16 == 0 )
return V_16 ;
F_12 ( V_2 ) ;
F_22 ( V_15 -> V_18 , V_15 -> V_21 ) ;
V_25:
F_23 ( V_15 ) ;
return V_16 ;
}
void F_24 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
F_25 ( V_15 ) ;
F_12 ( V_2 ) ;
F_22 ( V_15 -> V_18 , V_15 -> V_21 ) ;
F_23 ( V_15 ) ;
}
static int T_1
F_26 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = F_20 ( V_15 ) ;
int V_31 ;
if ( ( V_31 = F_27 ( V_30 ) ) < 0 )
return V_31 ;
if ( ( V_31 = F_28 ( V_30 ) ) < 0 ) {
F_29 ( L_5 , V_15 -> V_32 . V_33 ) ;
F_30 ( V_15 ) ;
return V_31 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_31 ;
if ( F_32 () )
return - V_34 ;
V_31 = F_15 ( & V_35 , V_2 ) ;
return V_31 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_34 ( V_2 ) ;
F_24 ( V_15 , V_2 ) ;
return 0 ;
}
