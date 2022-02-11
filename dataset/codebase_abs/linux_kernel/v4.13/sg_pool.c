static inline unsigned int F_1 ( unsigned short V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 > V_3 ) ;
if ( V_1 <= 8 )
V_2 = 0 ;
else
V_2 = F_3 ( V_1 ) - 3 ;
return V_2 ;
}
static void F_4 ( struct V_4 * V_5 , unsigned int V_1 )
{
struct V_6 * V_7 ;
V_7 = V_8 + F_1 ( V_1 ) ;
F_5 ( V_5 , V_7 -> V_9 ) ;
}
static struct V_4 * F_6 ( unsigned int V_1 , T_1 V_10 )
{
struct V_6 * V_7 ;
V_7 = V_8 + F_1 ( V_1 ) ;
return F_7 ( V_7 -> V_9 , V_10 ) ;
}
void F_8 ( struct V_11 * V_12 , bool V_13 )
{
if ( V_13 && V_12 -> V_14 <= V_3 )
return;
F_9 ( V_12 , V_3 , V_13 , F_4 ) ;
}
int F_10 ( struct V_11 * V_12 , int V_1 ,
struct V_4 * V_13 )
{
int V_15 ;
F_2 ( ! V_1 ) ;
if ( V_13 ) {
if ( V_1 <= V_3 ) {
V_12 -> V_1 = V_12 -> V_14 = V_1 ;
F_11 ( V_12 -> V_5 , V_1 ) ;
return 0 ;
}
}
V_15 = F_12 ( V_12 , V_1 , V_3 ,
V_13 , V_16 , F_6 ) ;
if ( F_13 ( V_15 ) )
F_8 ( V_12 , ( bool ) V_13 ) ;
return V_15 ;
}
static T_2 int F_14 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
struct V_6 * V_7 = V_8 + V_17 ;
int V_19 = V_7 -> V_19 * sizeof( struct V_4 ) ;
V_7 -> V_20 = F_15 ( V_7 -> V_21 , V_19 , 0 ,
V_22 , NULL ) ;
if ( ! V_7 -> V_20 ) {
F_16 ( V_23 L_1 ,
V_7 -> V_21 ) ;
goto V_24;
}
V_7 -> V_9 = F_17 ( V_25 ,
V_7 -> V_20 ) ;
if ( ! V_7 -> V_9 ) {
F_16 ( V_23 L_2 ,
V_7 -> V_21 ) ;
goto V_24;
}
}
return 0 ;
V_24:
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
struct V_6 * V_7 = V_8 + V_17 ;
if ( V_7 -> V_9 )
F_18 ( V_7 -> V_9 ) ;
if ( V_7 -> V_20 )
F_19 ( V_7 -> V_20 ) ;
}
return - V_26 ;
}
static T_3 void F_20 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
struct V_6 * V_7 = V_8 + V_17 ;
F_18 ( V_7 -> V_9 ) ;
F_19 ( V_7 -> V_20 ) ;
}
}
