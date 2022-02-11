void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( V_6 ) ;
if ( F_3 ( & V_2 -> V_7 ) == 1 )
return;
F_4 () ;
F_5 (g, p) {
if ( V_2 == V_5 -> V_2 )
F_6 ( V_5 ) ;
}
F_7 () ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
return V_8 -> V_2 == V_2 && ! ( V_8 -> V_9 & V_10 ) ;
}
void F_9 ( unsigned long V_11 , struct V_12 * V_13 )
{
if ( F_8 ( V_13 -> V_14 ) )
V_8 -> V_15 [ F_10 ( V_11 ) ] = V_13 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_16 ;
if ( ! F_8 ( V_2 ) )
return false ;
V_16 = V_8 ;
if ( V_2 -> V_17 != V_16 -> V_17 ) {
V_16 -> V_17 = V_2 -> V_17 ;
F_6 ( V_16 ) ;
return false ;
}
return true ;
}
struct V_12 * F_12 ( struct V_1 * V_2 , unsigned long V_11 )
{
int V_18 ;
F_2 ( V_19 ) ;
if ( ! F_11 ( V_2 ) )
return NULL ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_12 * V_21 = V_8 -> V_15 [ V_18 ] ;
if ( ! V_21 )
continue;
if ( F_13 ( V_21 -> V_14 != V_2 ) )
break;
if ( V_21 -> V_22 <= V_11 && V_21 -> V_23 > V_11 ) {
F_2 ( V_24 ) ;
return V_21 ;
}
}
return NULL ;
}
struct V_12 * F_14 ( struct V_1 * V_2 ,
unsigned long V_25 ,
unsigned long V_26 )
{
int V_18 ;
F_2 ( V_19 ) ;
if ( ! F_11 ( V_2 ) )
return NULL ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_12 * V_21 = V_8 -> V_15 [ V_18 ] ;
if ( V_21 && V_21 -> V_22 == V_25 && V_21 -> V_23 == V_26 ) {
F_2 ( V_24 ) ;
return V_21 ;
}
}
return NULL ;
}
