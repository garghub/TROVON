static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = V_2 -> V_5 -> V_3 ;
V_4 = F_2 ( & V_6 [ F_3 ( V_3 ) ] . V_4 ) ;
F_4 ( V_2 -> V_4 , EXP , V_4 * V_7 ) ;
F_5 ( L_1 ,
V_3 , V_4 , V_2 -> V_4 ) ;
return V_2 -> V_5 -> V_8 * V_2 -> V_4 / V_7 ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
unsigned long V_12 ;
V_2 = F_7 ( V_10 , struct V_1 , V_10 . V_10 ) ;
F_8 ( V_2 -> V_5 == NULL ) ;
V_12 = F_1 ( V_2 ) ;
F_9 ( V_2 -> V_5 , V_12 , V_13 ) ;
V_11 = F_10 ( V_2 -> V_14 ) ;
F_11 ( V_2 -> V_5 -> V_3 , & V_2 -> V_10 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_11 = F_10 ( V_2 -> V_14 ) ;
F_13 ( & V_2 -> V_10 , F_6 ) ;
F_11 ( V_2 -> V_5 -> V_3 , & V_2 -> V_10 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_10 ) ;
}
static int F_16 ( struct V_15 * V_5 )
{
unsigned int V_3 = V_5 -> V_3 ;
struct V_1 * V_2 = & F_17 ( V_16 , V_3 ) ;
struct V_1 * V_17 ;
int V_18 ;
if ( ! F_18 ( V_3 ) ) {
F_19 ( V_19 L_2 , V_3 ) ;
return - V_20 ;
}
if ( ! V_5 -> V_21 ) {
F_19 ( V_19 L_3 ) ;
return - V_20 ;
}
F_20 (i, policy->cpus) {
V_17 = & F_17 ( V_16 , V_18 ) ;
V_17 -> V_5 = V_5 ;
}
V_2 -> V_14 = V_22 ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_21 ( struct V_15 * V_5 )
{
unsigned int V_3 = V_5 -> V_3 ;
struct V_1 * V_2 = & F_17 ( V_16 , V_3 ) ;
int V_18 ;
F_14 ( V_2 ) ;
F_20 (i, policy->cpus) {
V_2 = & F_17 ( V_16 , V_18 ) ;
V_2 -> V_5 = NULL ;
}
}
static int T_1 F_22 ( void )
{
int V_23 ;
V_23 = F_23 ( & V_24 ) ;
if ( V_23 )
F_19 ( V_19 L_4 ) ;
return V_23 ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_24 ) ;
}
