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
snprintf ( V_7 , V_8 , L_3 , ( V_9 ) F_6 ( & V_1 -> V_4 -> V_5 ) ) ;
}
int F_9 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_3 * * V_1 )
{
struct V_14 * V_4 = & V_11 -> V_15 ;
unsigned long V_16 ;
* V_1 = F_10 ( sizeof( struct V_3 ) , V_17 ) ;
if ( ( * V_1 ) == NULL )
return - V_18 ;
F_11 ( & V_4 -> V_19 , V_16 ) ;
( * V_1 ) -> V_4 = V_4 ;
( * V_1 ) -> V_6 = ++ V_4 -> V_20 ;
F_12 ( & ( * V_1 ) -> V_2 , & V_21 , & V_4 -> V_19 ,
V_4 -> V_22 , ( * V_1 ) -> V_6 ) ;
F_13 ( & ( * V_1 ) -> V_2 ) ;
F_14 ( & ( * V_1 ) -> V_23 , & V_4 -> V_24 ) ;
F_15 ( & V_4 -> V_19 , V_16 ) ;
V_13 -> V_25 |= F_16 ( V_26 ) ;
V_13 -> V_27 = F_17 ( ( * V_1 ) -> V_6 ) ;
return 0 ;
}
void F_18 ( struct V_10 * V_11 ,
V_9 V_5 )
{
struct V_14 * V_4 = & V_11 -> V_15 ;
struct V_3 * V_1 , * V_28 ;
unsigned long V_16 ;
F_11 ( & V_4 -> V_19 , V_16 ) ;
F_19 ( & V_11 -> V_15 . V_5 , V_5 ) ;
F_20 (fence, tmp, &drv->fences, node) {
if ( V_5 < V_1 -> V_6 )
continue;
F_21 ( & V_1 -> V_2 ) ;
F_22 ( & V_1 -> V_23 ) ;
F_23 ( & V_1 -> V_2 ) ;
}
F_15 ( & V_4 -> V_19 , V_16 ) ;
}
