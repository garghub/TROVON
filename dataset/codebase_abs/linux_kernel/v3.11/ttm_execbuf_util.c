static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 (entry, list, head) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_6 -> V_9 )
continue;
V_6 -> V_9 = false ;
if ( V_6 -> V_10 ) {
F_3 ( V_8 ) ;
V_6 -> V_10 = false ;
}
F_4 ( & V_8 -> V_11 -> V_12 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_2 (entry, list, head) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_6 -> V_9 )
continue;
if ( ! V_6 -> V_10 ) {
V_6 -> V_13 = F_6 ( V_8 ) ;
V_6 -> V_10 = true ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_2 (entry, list, head) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_13 ) {
F_8 ( V_8 , V_6 -> V_13 , true ) ;
V_6 -> V_13 = 0 ;
}
}
}
void F_9 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 ;
if ( F_10 ( V_2 ) )
return;
V_6 = F_11 ( V_2 , struct V_5 , V_16 ) ;
V_15 = V_6 -> V_8 -> V_15 ;
F_12 ( & V_15 -> V_17 ) ;
F_1 ( V_2 , V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_15 -> V_17 ) ;
}
int F_15 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_5 * V_6 ;
int V_18 ;
if ( F_10 ( V_2 ) )
return 0 ;
F_2 (entry, list, head) {
V_6 -> V_9 = false ;
V_6 -> V_13 = 0 ;
V_6 -> V_10 = false ;
}
V_6 = F_11 ( V_2 , struct V_5 , V_16 ) ;
V_15 = V_6 -> V_8 -> V_15 ;
F_16 ( V_4 , & V_19 ) ;
V_20:
F_2 (entry, list, head) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_9 )
continue;
V_18 = F_17 ( V_8 , true , false , true , V_4 ) ;
if ( V_18 == - V_21 ) {
F_12 ( & V_15 -> V_17 ) ;
F_1 ( V_2 , V_4 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_7 ( V_2 ) ;
V_18 = F_18 ( & V_8 -> V_11 -> V_12 ,
V_4 ) ;
if ( F_19 ( V_18 != 0 ) ) {
if ( V_18 == - V_22 )
V_18 = - V_23 ;
goto V_24;
}
V_6 -> V_9 = true ;
if ( F_19 ( F_20 ( & V_8 -> V_25 ) > 0 ) ) {
V_18 = - V_26 ;
goto V_27;
}
goto V_20;
} else if ( V_18 )
goto V_27;
V_6 -> V_9 = true ;
if ( F_19 ( F_20 ( & V_8 -> V_25 ) > 0 ) ) {
V_18 = - V_26 ;
goto V_27;
}
}
F_21 ( V_4 ) ;
F_12 ( & V_15 -> V_17 ) ;
F_5 ( V_2 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_7 ( V_2 ) ;
return 0 ;
V_27:
F_12 ( & V_15 -> V_17 ) ;
F_1 ( V_2 , V_4 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_7 ( V_2 ) ;
V_24:
F_21 ( V_4 ) ;
F_13 ( V_4 ) ;
return V_18 ;
}
void F_22 ( struct V_3 * V_4 ,
struct V_1 * V_2 , void * V_28 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
if ( F_10 ( V_2 ) )
return;
V_8 = F_11 ( V_2 , struct V_5 , V_16 ) -> V_8 ;
V_30 = V_8 -> V_30 ;
V_32 = V_30 -> V_32 ;
V_15 = V_8 -> V_15 ;
F_12 ( & V_15 -> V_17 ) ;
F_12 ( & V_30 -> V_33 ) ;
F_2 (entry, list, head) {
V_8 = V_6 -> V_8 ;
V_6 -> V_34 = V_8 -> V_28 ;
V_8 -> V_28 = V_32 -> V_35 ( V_28 ) ;
F_3 ( V_8 ) ;
F_4 ( & V_8 -> V_11 -> V_12 ) ;
V_6 -> V_9 = false ;
}
F_14 ( & V_30 -> V_33 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_13 ( V_4 ) ;
F_2 (entry, list, head) {
if ( V_6 -> V_34 )
V_32 -> V_36 ( & V_6 -> V_34 ) ;
}
}
