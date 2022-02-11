int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_6 ;
int V_7 = 0 ;
F_2 ( & V_8 ) ;
F_3 (ent, n, &w1_families) {
V_6 = F_4 ( V_4 , struct V_1 , V_9 ) ;
if ( V_6 -> V_10 == V_2 -> V_10 ) {
V_7 = - V_11 ;
break;
}
}
if ( ! V_7 ) {
F_5 ( & V_2 -> V_12 , 0 ) ;
F_6 ( & V_2 -> V_9 , & V_13 ) ;
}
F_7 ( & V_8 ) ;
F_8 ( V_2 , 1 ) ;
return V_7 ;
}
void F_9 ( struct V_1 * V_14 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_6 ;
F_2 ( & V_8 ) ;
F_3 (ent, n, &w1_families) {
V_6 = F_4 ( V_4 , struct V_1 , V_9 ) ;
if ( V_6 -> V_10 == V_14 -> V_10 ) {
F_10 ( & V_14 -> V_9 ) ;
break;
}
}
F_7 ( & V_8 ) ;
F_8 ( V_14 , 0 ) ;
while ( F_11 ( & V_14 -> V_12 ) ) {
F_12 ( L_1 ,
V_14 -> V_10 , F_11 ( & V_14 -> V_12 ) ) ;
if ( F_13 ( 1000 ) )
F_14 ( V_15 ) ;
}
}
struct V_1 * F_15 ( T_1 V_10 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_6 = NULL ;
int V_7 = 0 ;
F_3 (ent, n, &w1_families) {
V_6 = F_4 ( V_4 , struct V_1 , V_9 ) ;
if ( V_6 -> V_10 == V_10 ) {
V_7 = 1 ;
break;
}
}
return ( V_7 ) ? V_6 : NULL ;
}
static void F_16 ( struct V_1 * V_6 )
{
F_17 ( & V_6 -> V_12 ) ;
}
void F_18 ( struct V_1 * V_6 )
{
F_2 ( & V_8 ) ;
F_16 ( V_6 ) ;
F_7 ( & V_8 ) ;
}
void F_19 ( struct V_1 * V_6 )
{
F_20 () ;
F_21 ( & V_6 -> V_12 ) ;
F_22 () ;
}
