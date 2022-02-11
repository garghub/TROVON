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
unsigned long V_10 ;
T_2 V_11 ;
T_3 V_12 ;
int V_13 ;
unsigned int V_14 , V_15 ;
V_14 = F_4 ( V_4 -> V_3 * ( V_16 / 100 ) ,
V_4 -> V_6 ) ;
V_15 = F_4 ( ( 100 - V_4 -> V_3 ) *
( V_16 / 100 ) , V_4 -> V_6 ) ;
F_5 ( & V_4 -> V_17 , V_10 ) ;
V_11 = F_6 () ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ ) {
if ( V_13 % 2 ) {
V_11 = F_7 ( V_11 , V_8 [ V_13 ] ) ;
V_12 = F_8 ( V_11 , F_6 () ) ;
if ( V_12 > 10 ) {
F_9 ( & V_4 -> V_17 , V_10 ) ;
F_10 ( V_12 , V_12 + 10 ) ;
F_5 ( & V_4 -> V_17 , V_10 ) ;
} else if ( V_12 > 0 ) {
F_11 ( V_12 ) ;
}
} else {
T_2 V_18 = F_7 ( V_11 , V_8 [ V_13 ] ) ;
while ( F_12 ( F_6 () , V_18 ) ) {
F_13 ( V_4 -> V_19 , 1 ) ;
V_11 = F_14 ( V_11 , V_14 ) ;
V_12 = F_15 ( F_16 ( V_11 ,
F_6 () ) ) ;
if ( V_12 > 0 )
F_17 ( V_12 ) ;
F_13 ( V_4 -> V_19 , 0 ) ;
V_11 = F_14 ( V_11 , V_15 ) ;
V_12 = F_15 ( F_16 ( V_11 ,
F_6 () ) ) ;
if ( V_12 > 0 )
F_17 ( V_12 ) ;
}
V_11 = V_18 ;
}
}
F_9 ( & V_4 -> V_17 , V_10 ) ;
return V_9 ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_4 * V_4 ;
struct V_1 * V_22 ;
int V_23 ;
V_4 = F_19 ( & V_21 -> V_2 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_22 = F_20 ( & V_21 -> V_2 , V_26 ) ;
if ( ! V_22 )
return - V_25 ;
V_4 -> V_19 = F_21 ( & V_21 -> V_2 , NULL , V_27 ) ;
if ( F_22 ( V_4 -> V_19 ) ) {
if ( F_23 ( V_4 -> V_19 ) != - V_28 )
F_24 ( & V_21 -> V_2 , L_1 ,
F_23 ( V_4 -> V_19 ) ) ;
return F_23 ( V_4 -> V_19 ) ;
}
V_22 -> V_5 = V_4 ;
V_22 -> V_29 = V_30 ;
V_22 -> V_31 = V_32 ;
V_22 -> V_33 = F_3 ;
V_22 -> V_34 = F_1 ;
V_22 -> V_35 = F_2 ;
V_4 -> V_6 = 38000 ;
V_4 -> V_3 = 50 ;
F_25 ( & V_4 -> V_17 ) ;
V_23 = F_26 ( & V_21 -> V_2 , V_22 ) ;
if ( V_23 < 0 )
F_24 ( & V_21 -> V_2 , L_2 ) ;
return V_23 ;
}
