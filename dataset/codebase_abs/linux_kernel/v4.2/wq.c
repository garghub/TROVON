T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) V_2 -> V_3 + 1 ;
}
T_1 F_2 ( struct V_4 * V_2 )
{
return V_2 -> V_3 + 1 ;
}
T_1 F_3 ( struct V_5 * V_2 )
{
return ( T_1 ) V_2 -> V_3 + 1 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) << V_2 -> V_6 ;
}
static T_1 F_5 ( struct V_4 * V_2 )
{
return F_2 ( V_2 ) << V_2 -> V_6 ;
}
static T_1 F_6 ( struct V_5 * V_2 )
{
return F_3 ( V_2 ) << V_2 -> V_6 ;
}
int F_7 ( struct V_7 * V_8 , struct V_9 * V_10 ,
void * V_11 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
V_2 -> V_6 = F_8 ( V_2 , V_11 , V_15 ) ;
V_2 -> V_3 = ( 1 << F_8 ( V_2 , V_11 , V_16 ) ) - 1 ;
V_14 = F_9 ( V_8 , & V_13 -> V_17 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_11 ( V_8 , F_4 ( V_2 ) , & V_13 -> V_18 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_2 , V_14 ) ;
goto V_19;
}
V_2 -> V_18 = V_13 -> V_18 . V_20 . V_18 ;
V_2 -> V_17 = V_13 -> V_17 . V_17 ;
V_13 -> V_8 = V_8 ;
return 0 ;
V_19:
F_12 ( V_8 , & V_13 -> V_17 ) ;
return V_14 ;
}
int F_13 ( struct V_7 * V_8 , struct V_9 * V_10 ,
void * V_21 , struct V_4 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
V_2 -> V_6 = 6 + F_8 ( V_21 , V_21 , V_22 ) ;
V_2 -> V_23 = F_8 ( V_21 , V_21 , V_24 ) ;
V_2 -> V_3 = ( 1 << V_2 -> V_23 ) - 1 ;
V_14 = F_9 ( V_8 , & V_13 -> V_17 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_11 ( V_8 , F_5 ( V_2 ) , & V_13 -> V_18 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_2 , V_14 ) ;
goto V_19;
}
V_2 -> V_18 = V_13 -> V_18 . V_20 . V_18 ;
V_2 -> V_17 = V_13 -> V_17 . V_17 ;
V_13 -> V_8 = V_8 ;
return 0 ;
V_19:
F_12 ( V_8 , & V_13 -> V_17 ) ;
return V_14 ;
}
int F_14 ( struct V_7 * V_8 , struct V_9 * V_10 ,
void * V_11 , struct V_5 * V_2 ,
struct V_12 * V_13 )
{
struct V_25 * V_26 ;
int V_14 ;
int V_27 ;
V_2 -> V_6 = F_8 ( V_2 , V_11 , V_15 ) ;
V_2 -> V_3 = ( 1 << F_8 ( V_2 , V_11 , V_16 ) ) - 1 ;
V_14 = F_9 ( V_8 , & V_13 -> V_17 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_11 ( V_8 , F_6 ( V_2 ) , & V_13 -> V_18 ) ;
if ( V_14 ) {
F_10 ( V_8 , L_2 , V_14 ) ;
goto V_19;
}
V_2 -> V_18 = V_13 -> V_18 . V_20 . V_18 ;
V_2 -> V_17 = V_13 -> V_17 . V_17 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 ; V_27 ++ ) {
V_26 = F_15 ( V_2 , V_27 ) ;
V_26 -> V_28 = F_16 ( V_27 + 1 ) ;
}
V_26 = F_15 ( V_2 , V_27 ) ;
V_2 -> V_29 = & V_26 -> V_28 ;
V_13 -> V_8 = V_8 ;
return 0 ;
V_19:
F_12 ( V_8 , & V_13 -> V_17 ) ;
return V_14 ;
}
void F_17 ( struct V_12 * V_13 )
{
F_18 ( V_13 -> V_8 , & V_13 -> V_18 ) ;
F_12 ( V_13 -> V_8 , & V_13 -> V_17 ) ;
}
