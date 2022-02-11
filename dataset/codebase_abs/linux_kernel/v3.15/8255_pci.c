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
} else {
return F_8 ( V_12 + V_9 ) ;
}
}
static int F_9 ( struct V_13 * V_14 ,
unsigned long V_15 )
{
struct V_1 * V_2 = F_10 ( V_14 ) ;
const struct V_16 * V_17 = NULL ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
bool V_22 ;
int V_23 ;
int V_24 ;
if ( V_15 < F_11 ( V_25 ) )
V_17 = & V_25 [ V_15 ] ;
if ( ! V_17 )
return - V_26 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_17 -> V_29 ;
V_19 = F_12 ( V_14 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_5 ;
V_23 = F_13 ( V_14 ) ;
if ( V_23 )
return V_23 ;
if ( V_17 -> V_30 ) {
V_23 = F_1 ( V_2 ) ;
if ( V_23 )
return V_23 ;
}
V_22 = ( F_14 ( V_2 , V_17 -> V_31 ) &
V_32 ) != 0 ;
if ( V_22 ) {
V_19 -> V_12 = F_2 ( V_2 , V_17 -> V_31 ) ;
if ( ! V_19 -> V_12 )
return - V_5 ;
} else {
V_14 -> V_11 = F_3 ( V_2 , V_17 -> V_31 ) ;
}
V_23 = F_15 ( V_14 , V_17 -> V_33 ) ;
if ( V_23 )
return V_23 ;
for ( V_24 = 0 ; V_24 < V_17 -> V_33 ; V_24 ++ ) {
unsigned long V_11 ;
V_21 = & V_14 -> V_34 [ V_24 ] ;
if ( V_22 ) {
V_11 = ( unsigned long ) ( V_19 -> V_12 + ( V_24 * 4 ) ) ;
V_23 = F_16 ( V_14 , V_21 , F_6 , V_11 ) ;
} else {
V_11 = V_14 -> V_11 + ( V_24 * 4 ) ;
V_23 = F_16 ( V_14 , V_21 , NULL , V_11 ) ;
}
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static void F_17 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = V_14 -> V_35 ;
if ( V_19 && V_19 -> V_12 )
F_5 ( V_19 -> V_12 ) ;
F_18 ( V_14 ) ;
}
static int F_19 ( struct V_1 * V_14 ,
const struct V_36 * V_37 )
{
return F_20 ( V_14 , & V_38 , V_37 -> V_39 ) ;
}
