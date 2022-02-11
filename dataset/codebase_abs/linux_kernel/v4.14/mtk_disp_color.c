static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 , unsigned int V_5 ,
unsigned int V_6 , unsigned int V_7 ,
unsigned int V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_4 ( V_5 , V_3 -> V_10 + F_5 ( V_9 ) ) ;
F_4 ( V_6 , V_3 -> V_10 + F_6 ( V_9 ) ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_4 ( V_11 | V_12 ,
V_3 -> V_10 + V_13 ) ;
F_4 ( 0x1 , V_3 -> V_10 + F_8 ( V_9 ) ) ;
}
static int F_9 ( struct V_14 * V_15 , struct V_14 * V_16 ,
void * V_17 )
{
struct V_1 * V_18 = F_10 ( V_15 ) ;
struct V_19 * V_20 = V_17 ;
int V_21 ;
V_21 = F_11 ( V_20 , & V_18 -> V_4 ) ;
if ( V_21 < 0 ) {
F_12 ( V_15 , L_1 ,
V_15 -> V_22 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static void F_13 ( struct V_14 * V_15 , struct V_14 * V_16 ,
void * V_17 )
{
struct V_1 * V_18 = F_10 ( V_15 ) ;
struct V_19 * V_20 = V_17 ;
F_14 ( V_20 , & V_18 -> V_4 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_14 * V_15 = & V_24 -> V_15 ;
struct V_1 * V_18 ;
int V_25 ;
int V_21 ;
V_18 = F_16 ( V_15 , sizeof( * V_18 ) , V_26 ) ;
if ( ! V_18 )
return - V_27 ;
V_25 = F_17 ( V_15 -> V_22 , V_28 ) ;
if ( V_25 < 0 ) {
F_12 ( V_15 , L_2 , V_25 ) ;
return V_25 ;
}
V_21 = F_18 ( V_15 , V_15 -> V_22 , & V_18 -> V_4 , V_25 ,
& V_29 ) ;
if ( V_21 ) {
F_12 ( V_15 , L_3 , V_21 ) ;
return V_21 ;
}
V_18 -> V_17 = F_19 ( V_15 ) ;
F_20 ( V_24 , V_18 ) ;
V_21 = F_21 ( V_15 , & V_30 ) ;
if ( V_21 )
F_12 ( V_15 , L_4 , V_21 ) ;
return V_21 ;
}
static int F_22 ( struct V_23 * V_24 )
{
F_23 ( & V_24 -> V_15 , & V_30 ) ;
return 0 ;
}
