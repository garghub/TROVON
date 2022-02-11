static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 , V_7 = V_5 -> V_8 ;
if ( ! ( V_2 & V_9 ) ) {
F_2 ( & V_5 -> V_10 , L_1 ) ;
return - V_11 ;
}
V_5 -> V_8 = ( V_2 & V_9 ) >> V_12 ;
V_6 = F_3 ( V_5 , V_2 & V_13 ) ;
V_5 -> V_8 = V_7 ;
if ( V_6 < 0 )
return V_6 ;
* V_3 = V_6 ;
return 0 ;
}
static int F_4 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 , V_7 = V_5 -> V_8 ;
if ( ! ( V_2 & V_9 ) ) {
F_2 ( & V_5 -> V_10 , L_1 ) ;
return - V_11 ;
}
V_5 -> V_8 = ( V_2 & V_9 ) >> V_12 ;
V_6 = F_5 ( V_5 , V_2 & V_13 , V_3 ) ;
V_5 -> V_8 = V_7 ;
return V_6 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_14 * V_10 = & V_5 -> V_10 ;
struct V_15 * V_16 ;
T_1 V_17 ;
unsigned long long V_18 ;
int V_6 ;
V_17 = F_7 ( F_8 ( V_10 ) , L_2 , NULL , & V_18 ) ;
if ( F_9 ( V_17 ) ) {
F_2 ( V_10 , L_3 ) ;
return - V_19 ;
}
if ( V_18 != V_20 ) {
F_2 ( V_10 , L_4 , V_18 ) ;
return - V_19 ;
}
if ( V_5 -> V_21 < 0 ) {
F_2 ( V_10 , L_5 ) ;
return - V_11 ;
}
V_16 = F_10 ( V_10 , sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
V_16 -> V_21 = V_5 -> V_21 ;
V_16 -> V_10 = V_10 ;
F_11 ( V_5 , V_16 ) ;
V_16 -> V_24 = F_12 ( V_10 , NULL , V_5 , & V_25 ) ;
if ( F_13 ( V_16 -> V_24 ) )
return F_14 ( V_16 -> V_24 ) ;
V_6 = F_15 ( V_10 , V_16 -> V_24 , V_16 -> V_21 ,
V_26 | V_27 , 0 ,
& V_28 ,
& V_16 -> V_29 ) ;
if ( V_6 )
return V_6 ;
return F_16 ( V_10 , V_30 ,
V_31 , F_17 ( V_31 ) , NULL , 0 ,
F_18 ( V_16 -> V_29 ) ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = F_20 ( V_5 ) ;
F_21 ( V_16 -> V_21 ) ;
}
static int T_2 F_22 ( struct V_14 * V_10 )
{
struct V_15 * V_16 = F_23 ( V_10 ) ;
F_21 ( V_16 -> V_21 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_14 * V_10 )
{
struct V_15 * V_16 = F_23 ( V_10 ) ;
F_25 ( V_16 -> V_21 ) ;
return 0 ;
}
