static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return true ;
}
static bool F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_5 ( V_2 ) ;
if ( F_6 ( & V_1 -> V_4 -> V_5 ) >= V_1 -> V_6 )
return true ;
return false ;
}
static void F_7 ( struct V_1 * V_2 , char * V_7 , int V_8 )
{
struct V_3 * V_1 = F_5 ( V_2 ) ;
snprintf ( V_7 , V_8 , L_3 , V_1 -> V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , char * V_7 , int V_8 )
{
struct V_3 * V_1 = F_5 ( V_2 ) ;
snprintf ( V_7 , V_8 , L_4 , F_6 ( & V_1 -> V_4 -> V_5 ) ) ;
}
int F_9 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_3 * * V_1 )
{
struct V_13 * V_4 = & V_10 -> V_14 ;
unsigned long V_15 ;
* V_1 = F_10 ( sizeof( struct V_3 ) , V_16 ) ;
if ( ( * V_1 ) == NULL )
return - V_17 ;
F_11 ( & V_4 -> V_18 , V_15 ) ;
( * V_1 ) -> V_4 = V_4 ;
( * V_1 ) -> V_6 = ++ V_4 -> V_19 ;
F_12 ( & ( * V_1 ) -> V_2 , & V_20 , & V_4 -> V_18 ,
0 , ( * V_1 ) -> V_6 ) ;
F_13 ( & ( * V_1 ) -> V_2 ) ;
F_14 ( & ( * V_1 ) -> V_21 , & V_4 -> V_22 ) ;
F_15 ( & V_4 -> V_18 , V_15 ) ;
V_12 -> V_23 |= F_16 ( V_24 ) ;
V_12 -> V_25 = F_17 ( ( * V_1 ) -> V_6 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_10 ,
T_1 V_5 )
{
struct V_13 * V_4 = & V_10 -> V_14 ;
struct V_3 * V_1 , * V_26 ;
unsigned long V_15 ;
F_11 ( & V_4 -> V_18 , V_15 ) ;
F_19 ( & V_10 -> V_14 . V_5 , V_5 ) ;
F_20 (fence, tmp, &drv->fences, node) {
if ( V_5 < V_1 -> V_6 )
continue;
F_21 ( & V_1 -> V_2 ) ;
F_22 ( & V_1 -> V_21 ) ;
F_23 ( & V_1 -> V_2 ) ;
}
F_15 ( & V_4 -> V_18 , V_15 ) ;
}
