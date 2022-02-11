static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_3 = F_3 ( V_2 ) ) ) {
F_4 ( V_8 L_1 ) ;
return - V_9 ;
}
V_5 = F_5 ( V_3 , 0 , V_10 ) ;
if ( F_6 ( V_5 ) ) {
F_4 ( V_8 L_2 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_4 ( V_11 L_3 ,
F_8 ( (struct V_1 * ) V_5 ) ) ;
F_9 ( V_5 ,
F_10 ( (struct V_4 * ) V_2 ) ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_5 ) {
F_12 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
int V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 () ;
F_15 () ;
V_14 = F_16 ( V_12 , V_13 * 8 , & V_7 -> V_15 ) ;
V_14 += F_17 ( V_12 , V_13 * 8 , & V_7 -> V_16 ) ;
F_18 () ;
V_14 += F_19 ( V_7 -> V_5 , V_12 , V_13 ) ;
return V_14 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_17 , const T_1 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_21 () ) {
F_22 ( V_7 -> V_5 , V_17 , V_18 ) ;
} else {
F_14 () ;
F_15 () ;
F_23 ( V_18 , V_17 , & V_7 -> V_15 ) ;
F_18 () ;
}
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_17 , const T_1 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_21 () ) {
F_25 ( V_7 -> V_5 , V_17 , V_18 ) ;
} else {
F_14 () ;
F_15 () ;
F_26 ( V_18 , V_17 , & V_7 -> V_16 ) ;
F_18 () ;
}
}
