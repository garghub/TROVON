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
struct V_1 * V_2 , bool V_14 ,
struct V_1 * V_15 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_16 ;
if ( F_9 ( V_2 ) )
return 0 ;
V_4 = F_10 ( V_2 , struct V_3 , V_12 ) ;
V_11 = V_4 -> V_6 -> V_11 ;
if ( V_9 )
F_16 ( V_9 , & V_17 ) ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
V_16 = F_17 ( V_6 , V_14 , ( V_9 == NULL ) , V_9 ) ;
if ( ! V_16 && F_18 ( F_19 ( & V_6 -> V_18 ) > 0 ) ) {
F_3 ( V_6 ) ;
V_16 = - V_19 ;
} else if ( V_16 == - V_20 && V_15 ) {
struct V_3 * V_21 = V_4 ;
V_4 = F_20 ( V_4 , V_12 ) ;
F_21 ( & V_21 -> V_12 ) ;
F_22 ( & V_21 -> V_12 , V_15 ) ;
continue;
}
if ( ! V_16 ) {
if ( ! V_4 -> V_22 )
continue;
V_16 = F_23 ( V_6 -> V_23 ) ;
if ( ! V_16 )
continue;
}
F_1 ( V_2 , V_4 ) ;
if ( V_16 == - V_24 && V_14 ) {
V_16 = F_24 ( & V_6 -> V_23 -> V_25 ,
V_9 ) ;
} else if ( V_16 == - V_24 ) {
F_25 ( & V_6 -> V_23 -> V_25 , V_9 ) ;
V_16 = 0 ;
}
if ( ! V_16 && V_4 -> V_22 )
V_16 = F_23 ( V_6 -> V_23 ) ;
if ( F_18 ( V_16 != 0 ) ) {
if ( V_16 == - V_26 )
V_16 = - V_27 ;
if ( V_9 ) {
F_26 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_16 ;
}
F_21 ( & V_4 -> V_12 ) ;
F_22 ( & V_4 -> V_12 , V_2 ) ;
}
if ( V_9 )
F_26 ( V_9 ) ;
F_11 ( & V_11 -> V_13 ) ;
F_4 ( V_2 ) ;
F_13 ( & V_11 -> V_13 ) ;
return 0 ;
}
void F_27 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_10 * V_11 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( F_9 ( V_2 ) )
return;
V_6 = F_10 ( V_2 , struct V_3 , V_12 ) -> V_6 ;
V_31 = V_6 -> V_31 ;
V_33 = V_31 -> V_33 ;
V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_13 ) ;
F_5 (entry, list, head) {
V_6 = V_4 -> V_6 ;
if ( V_4 -> V_22 )
F_28 ( V_6 -> V_23 , V_29 ) ;
else
F_29 ( V_6 -> V_23 , V_29 ) ;
F_12 ( V_6 ) ;
F_3 ( V_6 ) ;
}
F_13 ( & V_11 -> V_13 ) ;
if ( V_9 )
F_14 ( V_9 ) ;
}
