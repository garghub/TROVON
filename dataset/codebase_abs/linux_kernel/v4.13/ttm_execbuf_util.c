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
F_6 ( V_6 ) ;
}
}
void F_7 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_9 * V_10 ;
if ( F_8 ( V_2 ) )
return;
V_4 = F_9 ( V_2 , struct V_3 , V_11 ) ;
V_10 = V_4 -> V_6 -> V_10 ;
F_10 ( & V_10 -> V_12 ) ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
F_11 ( V_6 ) ;
F_3 ( V_6 ) ;
}
F_12 ( & V_10 -> V_12 ) ;
if ( V_8 )
F_13 ( V_8 ) ;
}
int F_14 ( struct V_7 * V_8 ,
struct V_1 * V_2 , bool V_13 ,
struct V_1 * V_14 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_15 ;
if ( F_8 ( V_2 ) )
return 0 ;
V_4 = F_9 ( V_2 , struct V_3 , V_11 ) ;
V_10 = V_4 -> V_6 -> V_10 ;
if ( V_8 )
F_15 ( V_8 , & V_16 ) ;
F_5 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
V_15 = F_16 ( V_6 , V_13 , ( V_8 == NULL ) , V_8 ) ;
if ( ! V_15 && F_17 ( F_18 ( & V_6 -> V_17 ) > 0 ) ) {
F_3 ( V_6 ) ;
V_15 = - V_18 ;
} else if ( V_15 == - V_19 && V_14 ) {
struct V_3 * V_20 = V_4 ;
V_4 = F_19 ( V_4 , V_11 ) ;
F_20 ( & V_20 -> V_11 ) ;
F_21 ( & V_20 -> V_11 , V_14 ) ;
continue;
}
if ( ! V_15 ) {
if ( ! V_4 -> V_21 )
continue;
V_15 = F_22 ( V_6 -> V_22 ) ;
if ( ! V_15 )
continue;
}
F_1 ( V_2 , V_4 ) ;
if ( V_15 == - V_23 && V_13 ) {
V_15 = F_23 ( & V_6 -> V_22 -> V_24 ,
V_8 ) ;
} else if ( V_15 == - V_23 ) {
F_24 ( & V_6 -> V_22 -> V_24 , V_8 ) ;
V_15 = 0 ;
}
if ( ! V_15 && V_4 -> V_21 )
V_15 = F_22 ( V_6 -> V_22 ) ;
if ( F_17 ( V_15 != 0 ) ) {
if ( V_15 == - V_25 )
V_15 = - V_26 ;
if ( V_8 ) {
F_25 ( V_8 ) ;
F_13 ( V_8 ) ;
}
return V_15 ;
}
F_20 ( & V_4 -> V_11 ) ;
F_21 ( & V_4 -> V_11 , V_2 ) ;
}
if ( V_8 )
F_25 ( V_8 ) ;
F_10 ( & V_10 -> V_12 ) ;
F_4 ( V_2 ) ;
F_12 ( & V_10 -> V_12 ) ;
return 0 ;
}
void F_26 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
if ( F_8 ( V_2 ) )
return;
V_6 = F_9 ( V_2 , struct V_3 , V_11 ) -> V_6 ;
V_30 = V_6 -> V_30 ;
V_32 = V_30 -> V_32 ;
V_10 = V_6 -> V_10 ;
F_10 ( & V_10 -> V_12 ) ;
F_5 (entry, list, head) {
V_6 = V_4 -> V_6 ;
if ( V_4 -> V_21 )
F_27 ( V_6 -> V_22 , V_28 ) ;
else
F_28 ( V_6 -> V_22 , V_28 ) ;
F_11 ( V_6 ) ;
F_3 ( V_6 ) ;
}
F_12 ( & V_10 -> V_12 ) ;
if ( V_8 )
F_13 ( V_8 ) ;
}
