void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
if ( F_2 ( & V_2 -> V_6 ) == 1 )
return;
F_3 () ;
F_4 (g, p) {
if ( V_2 == V_5 -> V_2 )
F_5 ( V_5 ) ;
}
F_6 () ;
}
static bool F_7 ( struct V_1 * V_2 )
{
return V_7 -> V_2 == V_2 && ! ( V_7 -> V_8 & V_9 ) ;
}
void F_8 ( unsigned long V_10 , struct V_11 * V_12 )
{
if ( F_7 ( V_12 -> V_13 ) )
V_7 -> V_14 [ F_9 ( V_10 ) ] = V_12 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_15 ;
if ( ! F_7 ( V_2 ) )
return false ;
V_15 = V_7 ;
if ( V_2 -> V_16 != V_15 -> V_16 ) {
V_15 -> V_16 = V_2 -> V_16 ;
F_5 ( V_15 ) ;
return false ;
}
return true ;
}
struct V_11 * F_11 ( struct V_1 * V_2 , unsigned long V_10 )
{
int V_17 ;
if ( ! F_10 ( V_2 ) )
return NULL ;
F_12 ( V_18 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
struct V_11 * V_20 = V_7 -> V_14 [ V_17 ] ;
if ( ! V_20 )
continue;
if ( F_13 ( V_20 -> V_13 != V_2 ) )
break;
if ( V_20 -> V_21 <= V_10 && V_20 -> V_22 > V_10 ) {
F_12 ( V_23 ) ;
return V_20 ;
}
}
return NULL ;
}
struct V_11 * F_14 ( struct V_1 * V_2 ,
unsigned long V_24 ,
unsigned long V_25 )
{
int V_17 ;
if ( ! F_10 ( V_2 ) )
return NULL ;
F_12 ( V_18 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
struct V_11 * V_20 = V_7 -> V_14 [ V_17 ] ;
if ( V_20 && V_20 -> V_21 == V_24 && V_20 -> V_22 == V_25 ) {
F_12 ( V_23 ) ;
return V_20 ;
}
}
return NULL ;
}
