static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 )
return - V_5 ;
V_4 = F_3 ( V_2 , 1 ) ;
F_4 ( V_4 | V_6 , V_3 + V_7 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( int V_8 , int V_9 , int V_10 , unsigned long V_11 )
{
void T_1 * V_12 = ( void T_1 * ) V_11 ;
if ( V_8 ) {
F_7 ( V_10 , V_12 + V_9 ) ;
return 0 ;
}
return F_8 ( V_12 + V_9 ) ;
}
static int F_9 ( struct V_13 * V_14 ,
unsigned long V_15 )
{
struct V_1 * V_2 = F_10 ( V_14 ) ;
const struct V_16 * V_17 = NULL ;
struct V_18 * V_19 ;
bool V_20 ;
int V_21 ;
int V_22 ;
if ( V_15 < F_11 ( V_23 ) )
V_17 = & V_23 [ V_15 ] ;
if ( ! V_17 )
return - V_24 ;
V_14 -> V_25 = V_17 ;
V_14 -> V_26 = V_17 -> V_27 ;
V_21 = F_12 ( V_14 ) ;
if ( V_21 )
return V_21 ;
if ( V_17 -> V_28 ) {
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
return V_21 ;
}
V_20 = ( F_13 ( V_2 , V_17 -> V_29 ) &
V_30 ) != 0 ;
if ( V_20 ) {
V_14 -> V_31 = F_2 ( V_2 , V_17 -> V_29 ) ;
if ( ! V_14 -> V_31 )
return - V_5 ;
} else {
V_14 -> V_11 = F_3 ( V_2 , V_17 -> V_29 ) ;
}
V_21 = F_14 ( V_14 , V_17 -> V_32 ) ;
if ( V_21 )
return V_21 ;
for ( V_22 = 0 ; V_22 < V_17 -> V_32 ; V_22 ++ ) {
unsigned long V_11 ;
V_19 = & V_14 -> V_33 [ V_22 ] ;
if ( V_20 ) {
V_11 = ( unsigned long ) ( V_14 -> V_31 + ( V_22 * 4 ) ) ;
V_21 = F_15 ( V_14 , V_19 , F_6 , V_11 ) ;
} else {
V_11 = V_14 -> V_11 + ( V_22 * 4 ) ;
V_21 = F_15 ( V_14 , V_19 , NULL , V_11 ) ;
}
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static void F_16 ( struct V_13 * V_14 )
{
if ( V_14 -> V_31 )
F_5 ( V_14 -> V_31 ) ;
F_17 ( V_14 ) ;
}
static int F_18 ( struct V_1 * V_14 ,
const struct V_34 * V_35 )
{
return F_19 ( V_14 , & V_36 , V_35 -> V_37 ) ;
}
