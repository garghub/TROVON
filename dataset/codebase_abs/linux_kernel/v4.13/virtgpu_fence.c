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
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( F_6 ( & V_4 -> V_5 -> V_6 ) >= V_4 -> V_7 )
return true ;
return false ;
}
static void F_7 ( struct V_1 * V_2 , char * V_8 , int V_9 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
snprintf ( V_8 , V_9 , L_3 , V_4 -> V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 , char * V_8 , int V_9 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
snprintf ( V_8 , V_9 , L_3 , ( V_10 ) F_6 ( & V_4 -> V_5 -> V_6 ) ) ;
}
int F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_3 * * V_4 )
{
struct V_15 * V_5 = & V_12 -> V_16 ;
unsigned long V_17 ;
* V_4 = F_10 ( sizeof( struct V_3 ) , V_18 ) ;
if ( ( * V_4 ) == NULL )
return - V_19 ;
F_11 ( & V_5 -> V_20 , V_17 ) ;
( * V_4 ) -> V_5 = V_5 ;
( * V_4 ) -> V_7 = ++ V_5 -> V_21 ;
F_12 ( & ( * V_4 ) -> V_2 , & V_22 , & V_5 -> V_20 ,
V_5 -> V_23 , ( * V_4 ) -> V_7 ) ;
F_13 ( & ( * V_4 ) -> V_2 ) ;
F_14 ( & ( * V_4 ) -> V_24 , & V_5 -> V_25 ) ;
F_15 ( & V_5 -> V_20 , V_17 ) ;
V_14 -> V_26 |= F_16 ( V_27 ) ;
V_14 -> V_28 = F_17 ( ( * V_4 ) -> V_7 ) ;
return 0 ;
}
void F_18 ( struct V_11 * V_12 ,
V_10 V_6 )
{
struct V_15 * V_5 = & V_12 -> V_16 ;
struct V_3 * V_4 , * V_29 ;
unsigned long V_17 ;
F_11 ( & V_5 -> V_20 , V_17 ) ;
F_19 ( & V_12 -> V_16 . V_6 , V_6 ) ;
F_20 (fence, tmp, &drv->fences, node) {
if ( V_6 < V_4 -> V_7 )
continue;
F_21 ( & V_4 -> V_2 ) ;
F_22 ( & V_4 -> V_24 ) ;
F_23 ( & V_4 -> V_2 ) ;
}
F_15 ( & V_5 -> V_20 , V_17 ) ;
}
