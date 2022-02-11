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
unsigned long V_16 )
{
struct V_8 * V_9 = F_7 ( V_7 ) ;
const struct V_10 * V_11 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
T_2 V_4 ;
unsigned long V_21 ;
int V_22 ;
int V_12 ;
V_11 = F_4 ( V_7 , V_9 ) ;
if ( ! V_11 )
return - V_23 ;
V_7 -> V_24 = V_11 ;
V_7 -> V_25 = V_11 -> V_26 ;
V_18 = F_8 ( sizeof( * V_18 ) , V_27 ) ;
if ( ! V_18 )
return - V_28 ;
V_7 -> V_29 = V_18 ;
V_22 = F_9 ( V_9 , V_7 -> V_25 ) ;
if ( V_22 )
return V_22 ;
V_4 = F_10 ( V_9 , V_11 -> V_30 ) ;
V_21 = F_11 ( V_9 , V_11 -> V_30 ) ;
if ( V_11 -> V_31 ) {
V_18 -> V_5 = F_12 ( V_4 , V_21 ) ;
if ( ! V_18 -> V_5 )
return - V_28 ;
}
V_7 -> V_4 = V_4 ;
V_22 = F_13 ( V_7 , V_11 -> V_32 ) ;
if ( V_22 )
return V_22 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_32 ; V_12 ++ ) {
V_20 = & V_7 -> V_33 [ V_12 ] ;
if ( V_11 -> V_31 ) {
V_4 = ( unsigned long ) ( V_18 -> V_5 + ( V_12 * 4 ) ) ;
V_22 = F_14 ( V_7 , V_20 , F_1 , V_4 ) ;
} else {
V_4 = V_7 -> V_4 + ( V_12 * 4 ) ;
V_22 = F_14 ( V_7 , V_20 , NULL , V_4 ) ;
}
if ( V_22 )
return V_22 ;
}
F_15 ( V_7 -> V_34 , L_1 ,
V_7 -> V_25 , V_11 -> V_32 * 24 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_7 ( V_7 ) ;
const struct V_10 * V_11 = F_17 ( V_7 ) ;
struct V_17 * V_18 = V_7 -> V_29 ;
struct V_19 * V_20 ;
int V_12 ;
if ( ! V_11 || ! V_18 )
return;
if ( V_7 -> V_33 ) {
for ( V_12 = 0 ; V_12 < V_11 -> V_32 ; V_12 ++ ) {
V_20 = & V_7 -> V_33 [ V_12 ] ;
F_18 ( V_7 , V_20 ) ;
}
}
if ( V_9 ) {
if ( V_18 -> V_5 )
F_19 ( V_18 -> V_5 ) ;
if ( V_7 -> V_4 )
F_20 ( V_9 ) ;
}
}
static int F_21 ( struct V_8 * V_7 ,
const struct V_35 * V_36 )
{
return F_22 ( V_7 , & V_37 ) ;
}
