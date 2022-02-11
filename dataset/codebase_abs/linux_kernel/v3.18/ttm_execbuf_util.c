static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( V_6 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned V_7 = F_6 ( V_6 ) ;
F_7 ( V_6 , V_7 , true ) ;
}
}
void F_8 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
if ( F_9 ( V_2 ) )
return;
V_4 = F_10 ( V_2 , struct V_3 , V_12 ) ;
V_11 = V_4 -> V_6 -> V_11 ;
F_11 ( & V_11 -> V_13 ) ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
F_12 ( V_6 ) ;
F_3 ( V_6 ) ;
}
F_13 ( & V_11 -> V_13 ) ;
if ( V_9 )
F_14 ( V_9 ) ;
}
int F_15 ( struct V_8 * V_9 ,
struct V_1 * V_2 , bool V_14 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_15 ;
if ( F_9 ( V_2 ) )
return 0 ;
V_4 = F_10 ( V_2 , struct V_3 , V_12 ) ;
V_11 = V_4 -> V_6 -> V_11 ;
if ( V_9 )
F_16 ( V_9 , & V_16 ) ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
V_15 = F_17 ( V_6 , V_14 , ( V_9 == NULL ) , true ,
V_9 ) ;
if ( ! V_15 && F_18 ( F_19 ( & V_6 -> V_17 ) > 0 ) ) {
F_3 ( V_6 ) ;
V_15 = - V_18 ;
}
if ( ! V_15 ) {
if ( ! V_4 -> V_19 )
continue;
V_15 = F_20 ( V_6 -> V_20 ) ;
if ( ! V_15 )
continue;
}
F_1 ( V_2 , V_4 ) ;
if ( V_15 == - V_21 && V_14 ) {
V_15 = F_21 ( & V_6 -> V_20 -> V_22 ,
V_9 ) ;
} else if ( V_15 == - V_21 ) {
F_22 ( & V_6 -> V_20 -> V_22 , V_9 ) ;
V_15 = 0 ;
}
if ( ! V_15 && V_4 -> V_19 )
V_15 = F_20 ( V_6 -> V_20 ) ;
if ( F_18 ( V_15 != 0 ) ) {
if ( V_15 == - V_23 )
V_15 = - V_24 ;
if ( V_9 ) {
F_23 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_15 ;
}
F_24 ( & V_4 -> V_12 ) ;
F_25 ( & V_4 -> V_12 , V_2 ) ;
}
if ( V_9 )
F_23 ( V_9 ) ;
F_11 ( & V_11 -> V_13 ) ;
F_4 ( V_2 ) ;
F_13 ( & V_11 -> V_13 ) ;
return 0 ;
}
void F_26 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_25 * V_25 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( F_9 ( V_2 ) )
return;
V_6 = F_10 ( V_2 , struct V_3 , V_12 ) -> V_6 ;
V_27 = V_6 -> V_27 ;
V_29 = V_27 -> V_29 ;
V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_13 ) ;
F_5 (entry, list, head) {
V_6 = V_4 -> V_6 ;
if ( V_4 -> V_19 )
F_27 ( V_6 -> V_20 , V_25 ) ;
else
F_28 ( V_6 -> V_20 , V_25 ) ;
F_12 ( V_6 ) ;
F_3 ( V_6 ) ;
}
F_13 ( & V_11 -> V_13 ) ;
if ( V_9 )
F_14 ( V_9 ) ;
}
