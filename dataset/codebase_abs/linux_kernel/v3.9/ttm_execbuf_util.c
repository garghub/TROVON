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
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
if ( F_11 ( V_2 ) )
return;
V_4 = F_12 ( V_2 , struct V_3 , V_13 ) ;
V_12 = V_4 -> V_6 -> V_12 ;
F_13 ( & V_12 -> V_14 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_12 -> V_14 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 ;
int V_15 ;
T_1 V_16 ;
if ( F_11 ( V_2 ) )
return 0 ;
F_2 (entry, list, head) {
V_4 -> V_7 = false ;
V_4 -> V_10 = 0 ;
V_4 -> V_8 = false ;
}
V_4 = F_12 ( V_2 , struct V_3 , V_13 ) ;
V_12 = V_4 -> V_6 -> V_12 ;
F_13 ( & V_12 -> V_14 ) ;
V_16 = V_4 -> V_6 -> V_17 -> V_16 ++ ;
V_18:
F_2 (entry, list, head) {
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_7 )
continue;
V_15 = F_16 ( V_6 , true , true , true , V_16 ) ;
switch ( V_15 ) {
case 0 :
break;
case - V_19 :
F_6 ( V_2 ) ;
F_14 ( & V_12 -> V_14 ) ;
V_15 = F_16 ( V_6 , true , false ,
true , V_16 ) ;
F_13 ( & V_12 -> V_14 ) ;
if ( ! V_15 )
break;
if ( F_17 ( V_15 != - V_20 ) )
goto V_21;
case - V_20 :
F_1 ( V_2 ) ;
V_16 = V_4 -> V_6 -> V_17 -> V_16 ++ ;
F_14 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
V_15 = F_18 ( V_6 , true , V_16 ) ;
if ( F_17 ( V_15 != 0 ) )
return V_15 ;
F_13 ( & V_12 -> V_14 ) ;
V_4 -> V_7 = true ;
if ( F_17 ( F_19 ( & V_6 -> V_22 ) > 0 ) ) {
V_15 = - V_19 ;
goto V_21;
}
goto V_18;
default:
goto V_21;
}
V_4 -> V_7 = true ;
if ( F_17 ( F_19 ( & V_6 -> V_22 ) > 0 ) ) {
V_15 = - V_19 ;
goto V_21;
}
}
F_6 ( V_2 ) ;
F_14 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return 0 ;
V_21:
F_1 ( V_2 ) ;
F_14 ( & V_12 -> V_14 ) ;
F_8 ( V_2 ) ;
return V_15 ;
}
void F_20 ( struct V_1 * V_2 , void * V_23 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_24 * V_17 ;
struct V_25 * V_26 ;
if ( F_11 ( V_2 ) )
return;
V_6 = F_12 ( V_2 , struct V_3 , V_13 ) -> V_6 ;
V_17 = V_6 -> V_17 ;
V_26 = V_17 -> V_26 ;
V_12 = V_6 -> V_12 ;
F_13 ( & V_12 -> V_14 ) ;
F_13 ( & V_17 -> V_27 ) ;
F_2 (entry, list, head) {
V_6 = V_4 -> V_6 ;
V_4 -> V_28 = V_6 -> V_23 ;
V_6 -> V_23 = V_26 -> V_29 ( V_23 ) ;
F_21 ( V_6 ) ;
V_4 -> V_7 = false ;
}
F_14 ( & V_17 -> V_27 ) ;
F_14 ( & V_12 -> V_14 ) ;
F_2 (entry, list, head) {
if ( V_4 -> V_28 )
V_26 -> V_30 ( & V_4 -> V_28 ) ;
}
}
