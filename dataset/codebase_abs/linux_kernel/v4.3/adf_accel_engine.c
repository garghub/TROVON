int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
void * V_8 , * V_9 ;
T_1 V_10 , V_11 ;
if ( ! V_7 -> V_12 )
return 0 ;
if ( F_2 ( & V_4 -> V_13 , V_7 -> V_14 ,
& V_2 -> V_15 . V_16 -> V_17 ) ) {
F_3 ( & F_4 ( V_2 ) , L_1 ,
V_7 -> V_14 ) ;
return - V_18 ;
}
if ( F_2 ( & V_4 -> V_19 , V_7 -> V_12 ,
& V_2 -> V_15 . V_16 -> V_17 ) ) {
F_3 ( & F_4 ( V_2 ) , L_2 ,
V_7 -> V_12 ) ;
goto V_20;
}
V_10 = V_4 -> V_19 -> V_21 ;
V_8 = ( void * ) V_4 -> V_19 -> V_22 ;
V_11 = V_4 -> V_13 -> V_21 ;
V_9 = ( void * ) V_4 -> V_13 -> V_22 ;
F_5 ( V_4 -> V_5 , V_9 , V_11 ) ;
if ( F_6 ( V_4 -> V_5 , V_8 , V_10 ) ) {
F_3 ( & F_4 ( V_2 ) , L_3 ) ;
goto V_20;
}
if ( F_7 ( V_4 -> V_5 ) ) {
F_3 ( & F_4 ( V_2 ) , L_4 ) ;
goto V_20;
}
return 0 ;
V_20:
F_8 ( V_2 ) ;
return - V_18 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_12 )
return;
F_9 ( V_4 -> V_5 ) ;
F_10 ( V_4 -> V_5 ) ;
F_11 ( V_4 -> V_19 ) ;
F_11 ( V_4 -> V_13 ) ;
V_4 -> V_19 = NULL ;
V_4 -> V_13 = NULL ;
V_4 -> V_5 = NULL ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_23 = V_2 -> V_7 ;
T_2 V_24 , V_25 , V_26 = F_13 ( V_2 ) ;
if ( ! V_23 -> V_12 )
return 0 ;
for ( V_25 = 0 , V_24 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_23 -> V_27 & ( 1 << V_25 ) ) {
F_14 ( V_4 -> V_5 , V_25 , 0xFF ) ;
V_24 ++ ;
}
}
F_15 ( & F_4 ( V_2 ) ,
L_5 ,
V_2 -> V_28 , V_24 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_23 = V_2 -> V_7 ;
T_2 V_24 , V_25 , V_26 = F_13 ( V_2 ) ;
if ( ! V_23 -> V_12 )
return 0 ;
for ( V_25 = 0 , V_24 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_23 -> V_27 & ( 1 << V_25 ) ) {
F_17 ( V_4 -> V_5 , V_25 , 0xFF ) ;
V_24 ++ ;
}
}
F_15 ( & F_4 ( V_2 ) ,
L_6 ,
V_2 -> V_28 , V_24 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_19 ( V_4 -> V_5 ) ;
if ( F_20 ( V_4 -> V_5 ) )
return - V_18 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_12 )
return 0 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_2 -> V_5 = V_4 ;
if ( F_23 ( V_2 ) ) {
F_3 ( & F_4 ( V_2 ) , L_7 ) ;
F_24 ( V_4 ) ;
return - V_18 ;
}
if ( F_18 ( V_2 , 0 ) ) {
F_3 ( & F_4 ( V_2 ) , L_8 ) ;
F_10 ( V_4 -> V_5 ) ;
F_24 ( V_4 ) ;
return - V_18 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_12 )
return 0 ;
F_10 ( V_4 -> V_5 ) ;
F_24 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
