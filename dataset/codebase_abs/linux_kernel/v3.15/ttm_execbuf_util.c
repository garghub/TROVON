static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 )
continue;
V_4 -> V_7 = false ;
if ( V_4 -> V_8 ) {
F_3 ( V_6 ) ;
V_4 -> V_8 = false ;
}
F_4 ( V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 )
continue;
if ( ! V_4 -> V_8 ) {
V_4 -> V_9 = F_6 ( V_6 ) ;
V_4 -> V_8 = true ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_9 ) {
F_8 ( V_6 , V_4 -> V_9 , true ) ;
V_4 -> V_9 = 0 ;
}
}
}
void F_9 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
if ( F_10 ( V_2 ) )
return;
V_4 = F_11 ( V_2 , struct V_3 , V_14 ) ;
V_13 = V_4 -> V_6 -> V_13 ;
F_12 ( & V_13 -> V_15 ) ;
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_11 ) ;
F_14 ( & V_13 -> V_15 ) ;
}
int F_15 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 ;
int V_16 ;
if ( F_10 ( V_2 ) )
return 0 ;
F_2 (entry, list, head) {
V_4 -> V_7 = false ;
V_4 -> V_9 = 0 ;
V_4 -> V_8 = false ;
}
V_4 = F_11 ( V_2 , struct V_3 , V_14 ) ;
V_13 = V_4 -> V_6 -> V_13 ;
if ( V_11 )
F_16 ( V_11 , & V_17 ) ;
V_18:
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_7 )
continue;
V_16 = F_17 ( V_6 , true , ( V_11 == NULL ) , true ,
V_11 ) ;
if ( V_16 == - V_19 ) {
F_18 ( V_11 == NULL ) ;
F_12 ( & V_13 -> V_15 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_13 -> V_15 ) ;
F_7 ( V_2 ) ;
V_16 = F_19 ( & V_6 -> V_20 -> V_21 ,
V_11 ) ;
if ( F_20 ( V_16 != 0 ) ) {
if ( V_16 == - V_22 )
V_16 = - V_23 ;
goto V_24;
}
V_4 -> V_7 = true ;
if ( F_20 ( F_21 ( & V_6 -> V_25 ) > 0 ) ) {
V_16 = - V_26 ;
goto V_27;
}
goto V_18;
} else if ( V_16 )
goto V_27;
V_4 -> V_7 = true ;
if ( F_20 ( F_21 ( & V_6 -> V_25 ) > 0 ) ) {
V_16 = - V_26 ;
goto V_27;
}
}
if ( V_11 )
F_22 ( V_11 ) ;
F_12 ( & V_13 -> V_15 ) ;
F_5 ( V_2 ) ;
F_14 ( & V_13 -> V_15 ) ;
F_7 ( V_2 ) ;
return 0 ;
V_27:
F_12 ( & V_13 -> V_15 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_13 -> V_15 ) ;
F_7 ( V_2 ) ;
V_24:
if ( V_11 ) {
F_22 ( V_11 ) ;
F_13 ( V_11 ) ;
}
return V_16 ;
}
void F_23 ( struct V_10 * V_11 ,
struct V_1 * V_2 , void * V_28 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_12 * V_13 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
if ( F_10 ( V_2 ) )
return;
V_6 = F_11 ( V_2 , struct V_3 , V_14 ) -> V_6 ;
V_30 = V_6 -> V_30 ;
V_32 = V_30 -> V_32 ;
V_13 = V_6 -> V_13 ;
F_12 ( & V_13 -> V_15 ) ;
F_12 ( & V_30 -> V_33 ) ;
F_2 (entry, list, head) {
V_6 = V_4 -> V_6 ;
V_4 -> V_34 = V_6 -> V_28 ;
V_6 -> V_28 = V_32 -> V_35 ( V_28 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 ) ;
V_4 -> V_7 = false ;
}
F_14 ( & V_30 -> V_33 ) ;
F_14 ( & V_13 -> V_15 ) ;
if ( V_11 )
F_13 ( V_11 ) ;
F_2 (entry, list, head) {
if ( V_4 -> V_34 )
V_32 -> V_36 ( & V_4 -> V_34 ) ;
}
}
