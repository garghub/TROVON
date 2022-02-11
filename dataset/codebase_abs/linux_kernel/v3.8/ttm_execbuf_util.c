static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 )
continue;
if ( V_4 -> V_8 ) {
F_3 ( V_6 ) ;
V_4 -> V_8 = false ;
}
V_4 -> V_7 = false ;
F_4 ( & V_6 -> V_7 , 0 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 )
continue;
if ( ! V_4 -> V_8 ) {
V_4 -> V_10 = F_7 ( V_6 ) ;
V_4 -> V_8 = true ;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_10 ) {
F_9 ( V_6 , V_4 -> V_10 , true ) ;
V_4 -> V_10 = 0 ;
}
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
int V_13 ;
F_6 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
V_13 = F_12 ( V_6 , true ) ;
F_13 ( & V_12 -> V_14 ) ;
if ( F_14 ( V_13 != 0 ) )
F_1 ( V_2 ) ;
return V_13 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
if ( F_16 ( V_2 ) )
return;
V_4 = F_17 ( V_2 , struct V_3 , V_15 ) ;
V_12 = V_4 -> V_6 -> V_12 ;
F_13 ( & V_12 -> V_14 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 ;
int V_13 ;
T_1 V_16 ;
if ( F_16 ( V_2 ) )
return 0 ;
F_2 (entry, list, head) {
V_4 -> V_7 = false ;
V_4 -> V_10 = 0 ;
V_4 -> V_8 = false ;
}
V_4 = F_17 ( V_2 , struct V_3 , V_15 ) ;
V_12 = V_4 -> V_6 -> V_12 ;
V_17:
F_13 ( & V_12 -> V_14 ) ;
V_16 = V_4 -> V_6 -> V_18 -> V_16 ++ ;
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
V_19:
V_13 = F_19 ( V_6 , true , true , true , V_16 ) ;
switch ( V_13 ) {
case 0 :
break;
case - V_20 :
V_13 = F_10 ( V_2 , V_6 ) ;
if ( F_14 ( V_13 != 0 ) ) {
F_11 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return V_13 ;
}
goto V_19;
case - V_21 :
F_1 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
V_13 = F_12 ( V_6 , true ) ;
if ( F_14 ( V_13 != 0 ) )
return V_13 ;
goto V_17;
default:
F_1 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return V_13 ;
}
V_4 -> V_7 = true ;
if ( F_14 ( F_20 ( & V_6 -> V_22 ) > 0 ) ) {
F_1 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return - V_20 ;
}
}
F_6 ( V_2 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 , void * V_23 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_24 * V_18 ;
struct V_25 * V_26 ;
if ( F_16 ( V_2 ) )
return;
V_6 = F_17 ( V_2 , struct V_3 , V_15 ) -> V_6 ;
V_18 = V_6 -> V_18 ;
V_26 = V_18 -> V_26 ;
V_12 = V_6 -> V_12 ;
F_13 ( & V_12 -> V_14 ) ;
F_13 ( & V_18 -> V_27 ) ;
F_2 (entry, list, head) {
V_6 = V_4 -> V_6 ;
V_4 -> V_28 = V_6 -> V_23 ;
V_6 -> V_23 = V_26 -> V_29 ( V_23 ) ;
F_22 ( V_6 ) ;
V_4 -> V_7 = false ;
}
F_11 ( & V_18 -> V_27 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_2 (entry, list, head) {
if ( V_4 -> V_28 )
V_26 -> V_30 ( & V_4 -> V_28 ) ;
}
}
