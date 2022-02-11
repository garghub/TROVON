static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_7 T_1 * V_8 = V_3 -> V_8 ;
return F_5 ( & V_8 -> V_9 ) & F_6 ( V_6 ) ;
}
static inline void
F_7 ( struct V_4 * V_5 , unsigned int V_6 , int V_10 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_7 T_1 * V_8 = V_3 -> V_8 ;
if ( V_10 )
F_8 ( & V_8 -> V_11 , F_6 ( V_6 ) ) ;
else
F_9 ( & V_8 -> V_11 , F_6 ( V_6 ) ) ;
}
static void
F_10 ( struct V_4 * V_5 , unsigned int V_6 , int V_10 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned long V_13 ;
F_11 ( & V_12 -> V_14 , V_13 ) ;
F_7 ( V_5 , V_6 , V_10 ) ;
F_12 ( & V_12 -> V_14 , V_13 ) ;
F_13 ( L_1 , V_15 , V_6 , V_10 ) ;
}
static int F_14 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_7 T_1 * V_8 = V_3 -> V_8 ;
unsigned long V_13 ;
F_11 ( & V_12 -> V_14 , V_13 ) ;
F_9 ( & V_8 -> V_16 , F_6 ( V_6 ) ) ;
F_9 ( & V_8 -> V_17 , F_6 ( V_6 ) ) ;
if ( V_6 < 16 ) {
F_9 ( & V_8 -> V_18 , F_15 ( V_6 ) ) ;
F_9 ( & V_8 -> V_19 , F_15 ( V_6 ) ) ;
} else {
F_9 ( & V_8 -> V_20 , F_15 ( V_6 ) ) ;
F_9 ( & V_8 -> V_21 , F_15 ( V_6 ) ) ;
}
F_12 ( & V_12 -> V_14 , V_13 ) ;
return 0 ;
}
static int
F_16 ( struct V_4 * V_5 , unsigned int V_6 , int V_10 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_7 T_1 * V_8 = V_3 -> V_8 ;
unsigned long V_13 ;
F_11 ( & V_12 -> V_14 , V_13 ) ;
F_7 ( V_5 , V_6 , V_10 ) ;
F_9 ( & V_8 -> V_16 , F_6 ( V_6 ) ) ;
F_8 ( & V_8 -> V_17 , F_6 ( V_6 ) ) ;
if ( V_6 < 16 ) {
F_9 ( & V_8 -> V_18 , F_15 ( V_6 ) ) ;
F_9 ( & V_8 -> V_19 , F_15 ( V_6 ) ) ;
} else {
F_9 ( & V_8 -> V_20 , F_15 ( V_6 ) ) ;
F_9 ( & V_8 -> V_21 , F_15 ( V_6 ) ) ;
}
F_12 ( & V_12 -> V_14 , V_13 ) ;
F_13 ( L_1 , V_15 , V_6 , V_10 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
struct V_22 * V_23 ;
F_18 (np, NULL, L_2 ) {
int V_24 ;
struct V_1 * V_25 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_25 = F_19 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 ) {
V_24 = - V_27 ;
goto V_28;
}
F_20 ( & V_25 -> V_14 ) ;
V_3 = & V_25 -> V_3 ;
V_5 = & V_3 -> V_5 ;
V_5 -> V_29 = 32 ;
V_5 -> V_30 = F_14 ;
V_5 -> V_31 = F_16 ;
V_5 -> V_32 = F_3 ;
V_5 -> V_33 = F_10 ;
V_24 = F_21 ( V_23 , V_3 ) ;
if ( V_24 )
goto V_28;
continue;
V_28:
F_22 ( L_3 ,
V_23 -> V_34 , V_24 ) ;
F_23 ( V_25 ) ;
}
return 0 ;
}
