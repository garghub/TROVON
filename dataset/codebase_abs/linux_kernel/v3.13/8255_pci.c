static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
void T_1 * V_5 = ( void T_1 * ) V_4 ;
if ( V_1 ) {
F_2 ( V_3 , V_5 + V_2 ) ;
return 0 ;
} else {
return F_3 ( V_5 + V_2 ) ;
}
}
static int F_4 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
const struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
bool V_17 ;
int V_18 ;
int V_19 ;
if ( V_8 < F_6 ( V_20 ) )
V_12 = & V_20 [ V_8 ] ;
if ( ! V_12 )
return - V_21 ;
V_7 -> V_22 = V_12 ;
V_7 -> V_23 = V_12 -> V_24 ;
V_14 = F_7 ( V_7 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_25 ;
V_18 = F_8 ( V_7 ) ;
if ( V_18 )
return V_18 ;
V_17 = ( F_9 ( V_10 , V_12 -> V_26 ) &
V_27 ) != 0 ;
if ( V_17 ) {
V_14 -> V_5 = F_10 ( V_10 , V_12 -> V_26 ) ;
if ( ! V_14 -> V_5 )
return - V_25 ;
} else {
V_7 -> V_4 = F_11 ( V_10 , V_12 -> V_26 ) ;
}
V_18 = F_12 ( V_7 , V_12 -> V_28 ) ;
if ( V_18 )
return V_18 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_28 ; V_19 ++ ) {
unsigned long V_4 ;
V_16 = & V_7 -> V_29 [ V_19 ] ;
if ( V_17 ) {
V_4 = ( unsigned long ) ( V_14 -> V_5 + ( V_19 * 4 ) ) ;
V_18 = F_13 ( V_7 , V_16 , F_1 , V_4 ) ;
} else {
V_4 = V_7 -> V_4 + ( V_19 * 4 ) ;
V_18 = F_13 ( V_7 , V_16 , NULL , V_4 ) ;
}
if ( V_18 )
return V_18 ;
}
F_14 ( V_7 -> V_30 , L_1 ,
V_7 -> V_23 , V_12 -> V_28 * 24 ) ;
return 0 ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_31 ;
if ( V_14 && V_14 -> V_5 )
F_16 ( V_14 -> V_5 ) ;
F_17 ( V_7 ) ;
}
static int F_18 ( struct V_9 * V_7 ,
const struct V_32 * V_33 )
{
return F_19 ( V_7 , & V_34 , V_33 -> V_35 ) ;
}
