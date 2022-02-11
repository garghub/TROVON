void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 () ;
F_3 (g, p) {
if ( V_2 == V_5 -> V_2 )
F_4 ( V_5 ) ;
}
F_5 () ;
}
static bool F_6 ( struct V_1 * V_2 )
{
return V_6 -> V_2 == V_2 && ! ( V_6 -> V_7 & V_8 ) ;
}
void F_7 ( unsigned long V_9 , struct V_10 * V_11 )
{
if ( F_6 ( V_11 -> V_12 ) )
V_6 -> V_13 [ F_8 ( V_9 ) ] = V_11 ;
}
static bool F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_14 ;
if ( ! F_6 ( V_2 ) )
return false ;
V_14 = V_6 ;
if ( V_2 -> V_15 != V_14 -> V_15 ) {
V_14 -> V_15 = V_2 -> V_15 ;
F_4 ( V_14 ) ;
return false ;
}
return true ;
}
struct V_10 * F_10 ( struct V_1 * V_2 , unsigned long V_9 )
{
int V_16 ;
if ( ! F_9 ( V_2 ) )
return NULL ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_10 * V_18 = V_6 -> V_13 [ V_16 ] ;
if ( ! V_18 )
continue;
if ( F_11 ( V_18 -> V_12 != V_2 ) )
break;
if ( V_18 -> V_19 <= V_9 && V_18 -> V_20 > V_9 )
return V_18 ;
}
return NULL ;
}
struct V_10 * F_12 ( struct V_1 * V_2 ,
unsigned long V_21 ,
unsigned long V_22 )
{
int V_16 ;
if ( ! F_9 ( V_2 ) )
return NULL ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_10 * V_18 = V_6 -> V_13 [ V_16 ] ;
if ( V_18 && V_18 -> V_19 == V_21 && V_18 -> V_20 == V_22 )
return V_18 ;
}
return NULL ;
}
