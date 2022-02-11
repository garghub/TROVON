static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
return ! ! ( F_3 ( & V_7 -> V_8 ) & F_4 ( V_3 ) ) ;
}
static inline void
F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
if ( V_9 )
F_6 ( & V_7 -> V_10 , F_4 ( V_3 ) ) ;
else
F_7 ( & V_7 -> V_10 , F_4 ( V_3 ) ) ;
}
static void
F_8 ( struct V_1 * V_2 , unsigned int V_3 , int V_9 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
unsigned long V_13 ;
F_10 ( & V_12 -> V_14 , V_13 ) ;
F_5 ( V_2 , V_3 , V_9 ) ;
F_11 ( & V_12 -> V_14 , V_13 ) ;
F_12 ( L_1 , V_15 , V_3 , V_9 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned long V_13 ;
F_10 ( & V_12 -> V_14 , V_13 ) ;
F_7 ( & V_7 -> V_16 , F_4 ( V_3 ) ) ;
F_7 ( & V_7 -> V_17 , F_4 ( V_3 ) ) ;
if ( V_3 < 16 ) {
F_7 ( & V_7 -> V_18 , F_14 ( V_3 ) ) ;
F_7 ( & V_7 -> V_19 , F_14 ( V_3 ) ) ;
} else {
F_7 ( & V_7 -> V_20 , F_14 ( V_3 ) ) ;
F_7 ( & V_7 -> V_21 , F_14 ( V_3 ) ) ;
}
F_11 ( & V_12 -> V_14 , V_13 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , unsigned int V_3 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned long V_13 ;
F_10 ( & V_12 -> V_14 , V_13 ) ;
F_5 ( V_2 , V_3 , V_9 ) ;
F_7 ( & V_7 -> V_16 , F_4 ( V_3 ) ) ;
F_6 ( & V_7 -> V_17 , F_4 ( V_3 ) ) ;
if ( V_3 < 16 ) {
F_7 ( & V_7 -> V_18 , F_14 ( V_3 ) ) ;
F_7 ( & V_7 -> V_19 , F_14 ( V_3 ) ) ;
} else {
F_7 ( & V_7 -> V_20 , F_14 ( V_3 ) ) ;
F_7 ( & V_7 -> V_21 , F_14 ( V_3 ) ) ;
}
F_11 ( & V_12 -> V_14 , V_13 ) ;
F_12 ( L_1 , V_15 , V_3 , V_9 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
struct V_22 * V_23 ;
F_17 (np, NULL, L_2 ) {
int V_24 ;
struct V_11 * V_25 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_25 = F_18 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 ) {
V_24 = - V_27 ;
goto V_28;
}
F_19 ( & V_25 -> V_14 ) ;
V_5 = & V_25 -> V_5 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_29 = 32 ;
V_2 -> V_30 = F_13 ;
V_2 -> V_31 = F_15 ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_8 ;
V_24 = F_20 ( V_23 , V_5 , V_25 ) ;
if ( V_24 )
goto V_28;
continue;
V_28:
F_21 ( L_3 ,
V_23 -> V_34 , V_24 ) ;
F_22 ( V_25 ) ;
}
return 0 ;
}
