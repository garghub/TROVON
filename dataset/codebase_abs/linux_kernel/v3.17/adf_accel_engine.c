int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
void * V_8 ;
T_1 V_9 ;
if ( F_2 ( & V_4 -> V_10 , V_7 -> V_11 ,
& V_2 -> V_12 . V_13 -> V_14 ) ) {
F_3 ( L_1 , V_7 -> V_11 ) ;
return - V_15 ;
}
V_9 = V_4 -> V_10 -> V_16 ;
V_8 = ( void * ) V_4 -> V_10 -> V_17 ;
if ( F_4 ( V_4 -> V_5 , V_8 , V_9 ) ) {
F_3 ( L_2 ) ;
goto V_18;
}
if ( F_5 ( V_4 -> V_5 ) ) {
F_3 ( L_2 ) ;
goto V_18;
}
return 0 ;
V_18:
F_6 ( V_4 -> V_10 ) ;
return - V_15 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_6 ( V_4 -> V_10 ) ;
F_8 ( V_4 -> V_5 ) ;
F_9 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_19 = V_2 -> V_7 ;
T_1 V_20 , V_21 , V_22 = F_11 ( V_2 ) ;
for ( V_21 = 0 , V_20 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 -> V_23 & ( 1 << V_21 ) ) {
F_12 ( V_4 -> V_5 , V_21 , 0xFF ) ;
V_20 ++ ;
}
}
F_13 ( L_3 ,
V_2 -> V_24 , V_20 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_19 = V_2 -> V_7 ;
T_1 V_20 , V_21 , V_22 = F_11 ( V_2 ) ;
for ( V_21 = 0 , V_20 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 -> V_23 & ( 1 << V_21 ) ) {
F_15 ( V_4 -> V_5 , V_21 , 0xFF ) ;
V_20 ++ ;
}
}
F_13 ( L_4 ,
V_2 -> V_24 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_17 ( V_4 -> V_5 ) ;
if ( F_18 ( V_4 -> V_5 ) )
return - V_15 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_2 -> V_5 = V_4 ;
if ( F_21 ( V_2 ) ) {
F_3 ( L_5 ) ;
F_22 ( V_4 ) ;
return - V_15 ;
}
if ( F_16 ( V_2 , 0 ) ) {
F_3 ( L_6 ) ;
F_9 ( V_4 -> V_5 ) ;
F_22 ( V_4 ) ;
return - V_15 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
