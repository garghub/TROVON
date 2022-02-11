static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
V_4 -> V_3 = V_3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
if ( ! V_6 )
return - V_7 ;
V_4 -> V_6 = V_6 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int * V_8 ,
unsigned int V_9 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_11 ;
int V_12 , V_13 , V_14 ;
T_2 V_15 ;
long V_16 ;
V_14 = F_4 ( V_17 , V_4 -> V_6 ) ;
V_13 = F_4 ( V_4 -> V_3 * V_14 , 100 ) ;
F_5 ( V_11 , V_13 , V_14 ) ;
V_15 = F_6 () ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( V_12 % 2 )
F_7 ( V_11 ) ;
else
F_8 ( V_11 ) ;
V_15 = F_9 ( V_15 , V_8 [ V_12 ] ) ;
V_16 = F_10 ( V_15 , F_6 () ) ;
if ( V_16 > 0 )
F_11 ( V_16 , V_16 + 10 ) ;
}
F_7 ( V_11 ) ;
return V_9 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_4 * V_4 ;
struct V_1 * V_20 ;
int V_21 ;
V_4 = F_13 ( & V_19 -> V_2 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_11 = F_14 ( & V_19 -> V_2 , NULL ) ;
if ( F_15 ( V_4 -> V_11 ) )
return F_16 ( V_4 -> V_11 ) ;
V_4 -> V_6 = 38000 ;
V_4 -> V_3 = 50 ;
V_20 = F_17 ( & V_19 -> V_2 , V_24 ) ;
if ( ! V_20 )
return - V_23 ;
V_20 -> V_5 = V_4 ;
V_20 -> V_25 = V_26 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = F_3 ;
V_20 -> V_30 = F_1 ;
V_20 -> V_31 = F_2 ;
V_21 = F_18 ( & V_19 -> V_2 , V_20 ) ;
if ( V_21 < 0 )
F_19 ( & V_19 -> V_2 , L_1 ) ;
return V_21 ;
}
