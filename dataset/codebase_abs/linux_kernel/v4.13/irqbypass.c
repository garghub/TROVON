static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_6 )
V_2 -> V_6 ( V_2 ) ;
if ( V_4 -> V_6 )
V_4 -> V_6 ( V_4 ) ;
if ( V_2 -> V_7 )
V_5 = V_2 -> V_7 ( V_2 , V_4 ) ;
if ( ! V_5 ) {
V_5 = V_4 -> V_8 ( V_4 , V_2 ) ;
if ( V_5 && V_2 -> V_9 )
V_2 -> V_9 ( V_2 , V_4 ) ;
}
if ( V_4 -> V_10 )
V_4 -> V_10 ( V_4 ) ;
if ( V_2 -> V_10 )
V_2 -> V_10 ( V_2 ) ;
return V_5 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_6 )
V_2 -> V_6 ( V_2 ) ;
if ( V_4 -> V_6 )
V_4 -> V_6 ( V_4 ) ;
V_4 -> V_11 ( V_4 , V_2 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 ( V_2 , V_4 ) ;
if ( V_4 -> V_10 )
V_4 -> V_10 ( V_4 ) ;
if ( V_2 -> V_10 )
V_2 -> V_10 ( V_2 ) ;
}
int F_3 ( struct V_1 * V_12 )
{
struct V_1 * V_13 ;
struct V_3 * V_14 ;
if ( ! V_12 -> V_15 )
return - V_16 ;
F_4 () ;
if ( ! F_5 ( V_17 ) )
return - V_18 ;
F_6 ( & V_19 ) ;
F_7 (tmp, &producers, node) {
if ( V_13 -> V_15 == V_12 -> V_15 ) {
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
return - V_20 ;
}
}
F_7 (consumer, &consumers, node) {
if ( V_14 -> V_15 == V_12 -> V_15 ) {
int V_5 = F_1 ( V_12 , V_14 ) ;
if ( V_5 ) {
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
return V_5 ;
}
break;
}
}
F_10 ( & V_12 -> V_21 , & V_22 ) ;
F_8 ( & V_19 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_12 )
{
struct V_1 * V_13 ;
struct V_3 * V_14 ;
if ( ! V_12 -> V_15 )
return;
F_4 () ;
if ( ! F_5 ( V_17 ) )
return;
F_6 ( & V_19 ) ;
F_7 (tmp, &producers, node) {
if ( V_13 -> V_15 != V_12 -> V_15 )
continue;
F_7 (consumer, &consumers, node) {
if ( V_14 -> V_15 == V_12 -> V_15 ) {
F_2 ( V_12 , V_14 ) ;
break;
}
}
F_12 ( & V_12 -> V_21 ) ;
F_9 ( V_17 ) ;
break;
}
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
}
int F_13 ( struct V_3 * V_14 )
{
struct V_3 * V_13 ;
struct V_1 * V_12 ;
if ( ! V_14 -> V_15 ||
! V_14 -> V_8 || ! V_14 -> V_11 )
return - V_16 ;
F_4 () ;
if ( ! F_5 ( V_17 ) )
return - V_18 ;
F_6 ( & V_19 ) ;
F_7 (tmp, &consumers, node) {
if ( V_13 -> V_15 == V_14 -> V_15 || V_13 == V_14 ) {
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
return - V_20 ;
}
}
F_7 (producer, &producers, node) {
if ( V_12 -> V_15 == V_14 -> V_15 ) {
int V_5 = F_1 ( V_12 , V_14 ) ;
if ( V_5 ) {
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
return V_5 ;
}
break;
}
}
F_10 ( & V_14 -> V_21 , & V_23 ) ;
F_8 ( & V_19 ) ;
return 0 ;
}
void F_14 ( struct V_3 * V_14 )
{
struct V_3 * V_13 ;
struct V_1 * V_12 ;
if ( ! V_14 -> V_15 )
return;
F_4 () ;
if ( ! F_5 ( V_17 ) )
return;
F_6 ( & V_19 ) ;
F_7 (tmp, &consumers, node) {
if ( V_13 != V_14 )
continue;
F_7 (producer, &producers, node) {
if ( V_12 -> V_15 == V_14 -> V_15 ) {
F_2 ( V_12 , V_14 ) ;
break;
}
}
F_12 ( & V_14 -> V_21 ) ;
F_9 ( V_17 ) ;
break;
}
F_8 ( & V_19 ) ;
F_9 ( V_17 ) ;
}
