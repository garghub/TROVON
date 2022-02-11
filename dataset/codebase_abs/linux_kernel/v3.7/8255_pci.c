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
static const void * F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
const struct V_10 * V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_13 ) ; V_12 ++ ) {
V_11 = & V_13 [ V_12 ] ;
if ( V_9 -> V_14 == V_11 -> V_14 &&
V_9 -> V_15 == V_11 -> V_15 )
return V_11 ;
}
return NULL ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
const struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
T_2 V_4 ;
unsigned long V_20 ;
int V_21 ;
int V_12 ;
F_7 ( V_7 , & V_9 -> V_7 ) ;
V_11 = F_4 ( V_7 , V_9 ) ;
if ( ! V_11 )
return - V_22 ;
V_7 -> V_23 = V_11 ;
V_7 -> V_24 = V_11 -> V_25 ;
V_21 = F_8 ( V_7 , sizeof( * V_17 ) ) ;
if ( V_21 < 0 )
return V_21 ;
V_17 = V_7 -> V_26 ;
V_21 = F_9 ( V_9 , V_7 -> V_24 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_10 ( V_9 , V_11 -> V_27 ) ;
V_20 = F_11 ( V_9 , V_11 -> V_27 ) ;
if ( V_11 -> V_28 ) {
V_17 -> V_5 = F_12 ( V_4 , V_20 ) ;
if ( ! V_17 -> V_5 )
return - V_29 ;
}
V_7 -> V_4 = V_4 ;
V_21 = F_13 ( V_7 , V_11 -> V_30 ) ;
if ( V_21 )
return V_21 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_30 ; V_12 ++ ) {
V_19 = & V_7 -> V_31 [ V_12 ] ;
if ( V_11 -> V_28 ) {
V_4 = ( unsigned long ) ( V_17 -> V_5 + ( V_12 * 4 ) ) ;
V_21 = F_14 ( V_7 , V_19 , F_1 , V_4 ) ;
} else {
V_4 = V_7 -> V_4 + ( V_12 * 4 ) ;
V_21 = F_14 ( V_7 , V_19 , NULL , V_4 ) ;
}
if ( V_21 )
return V_21 ;
}
F_15 ( V_7 -> V_32 , L_1 ,
V_7 -> V_24 , V_11 -> V_30 * 24 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_17 ( V_7 ) ;
const struct V_10 * V_11 = F_18 ( V_7 ) ;
struct V_16 * V_17 = V_7 -> V_26 ;
struct V_18 * V_19 ;
int V_12 ;
if ( ! V_11 || ! V_17 )
return;
if ( V_7 -> V_31 ) {
for ( V_12 = 0 ; V_12 < V_11 -> V_30 ; V_12 ++ ) {
V_19 = & V_7 -> V_31 [ V_12 ] ;
F_19 ( V_7 , V_19 ) ;
}
}
if ( V_9 ) {
if ( V_17 -> V_5 )
F_20 ( V_17 -> V_5 ) ;
if ( V_7 -> V_4 )
F_21 ( V_9 ) ;
}
}
static int T_3 F_22 ( struct V_8 * V_7 ,
const struct V_33 * V_34 )
{
return F_23 ( V_7 , & V_35 ) ;
}
static void T_4 F_24 ( struct V_8 * V_7 )
{
F_25 ( V_7 ) ;
}
