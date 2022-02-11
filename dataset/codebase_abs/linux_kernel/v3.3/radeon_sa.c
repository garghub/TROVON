int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , T_1 V_6 )
{
int V_7 ;
V_4 -> V_8 = NULL ;
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
F_2 ( & V_4 -> V_9 ) ;
V_7 = F_3 ( V_2 , V_5 , V_10 , true ,
V_11 , & V_4 -> V_8 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_12 , L_1 , V_7 ) ;
return V_7 ;
}
return V_7 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_9 , * V_14 ;
if ( ! F_6 ( & V_4 -> V_9 ) ) {
F_4 ( V_2 -> V_12 , L_2 ) ;
}
F_7 (sa_bo, tmp, &sa_manager->sa_bo, list) {
F_8 ( & V_9 -> V_15 ) ;
}
F_9 ( & V_4 -> V_8 ) ;
V_4 -> V_5 = 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 ;
if ( V_4 -> V_8 == NULL ) {
F_4 ( V_2 -> V_12 , L_3 ) ;
return - V_16 ;
}
V_7 = F_11 ( V_4 -> V_8 , false ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_12 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_12 ( V_4 -> V_8 , V_4 -> V_6 , & V_4 -> V_17 ) ;
if ( V_7 ) {
F_13 ( V_4 -> V_8 ) ;
F_4 ( V_2 -> V_12 , L_5 , V_7 ) ;
return V_7 ;
}
V_7 = F_14 ( V_4 -> V_8 , & V_4 -> V_18 ) ;
F_13 ( V_4 -> V_8 ) ;
return V_7 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 ;
if ( V_4 -> V_8 == NULL ) {
F_4 ( V_2 -> V_12 , L_3 ) ;
return - V_16 ;
}
V_7 = F_11 ( V_4 -> V_8 , false ) ;
if ( ! V_7 ) {
F_16 ( V_4 -> V_8 ) ;
F_17 ( V_4 -> V_8 ) ;
F_13 ( V_4 -> V_8 ) ;
}
return V_7 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_13 * V_9 ,
unsigned V_5 , unsigned V_19 )
{
struct V_13 * V_14 ;
struct V_20 * V_21 ;
unsigned V_22 = 0 , V_23 = 0 ;
F_19 ( V_19 > V_10 ) ;
F_19 ( V_5 > V_4 -> V_5 ) ;
V_21 = V_4 -> V_9 . V_24 ;
if ( F_6 ( & V_4 -> V_9 ) ) {
goto V_25;
}
V_22 = 0 ;
F_20 (tmp, &sa_manager->sa_bo, list) {
if ( ( V_14 -> V_22 - V_22 ) >= V_5 ) {
V_21 = V_14 -> V_15 . V_24 ;
goto V_25;
}
V_22 = V_14 -> V_22 + V_14 -> V_5 ;
V_23 = V_22 % V_19 ;
if ( V_23 ) {
V_23 = V_19 - V_23 ;
}
V_22 += V_23 ;
}
V_21 = V_4 -> V_9 . V_24 ;
V_14 = F_21 ( V_21 , struct V_13 , V_15 ) ;
V_22 = V_14 -> V_22 + V_14 -> V_5 ;
V_23 = V_22 % V_19 ;
if ( V_23 ) {
V_23 = V_19 - V_23 ;
}
V_22 += V_23 ;
if ( ( V_4 -> V_5 - V_22 ) < V_5 ) {
return - V_26 ;
}
V_25:
V_9 -> V_27 = V_4 ;
V_9 -> V_22 = V_22 ;
V_9 -> V_5 = V_5 ;
F_22 ( & V_9 -> V_15 , V_21 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 , struct V_13 * V_9 )
{
F_8 ( & V_9 -> V_15 ) ;
}
