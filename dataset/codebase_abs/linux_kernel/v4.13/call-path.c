static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , bool V_7 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_5 ? 0 : V_6 ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_7 ;
F_2 ( & V_2 -> V_9 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_12 * F_3 ( void )
{
struct V_12 * V_13 ;
V_13 = F_4 ( sizeof( struct V_12 ) ) ;
if ( ! V_13 )
return NULL ;
F_1 ( & V_13 -> V_1 , NULL , NULL , 0 , false ) ;
F_5 ( & V_13 -> V_14 ) ;
return V_13 ;
}
void F_6 ( struct V_12 * V_13 )
{
struct V_15 * V_16 , * V_17 ;
F_7 (pos, n, &cpr->blocks, node) {
F_8 ( & V_16 -> V_18 ) ;
free ( V_16 ) ;
}
free ( V_13 ) ;
}
static struct V_1 * F_9 ( struct V_12 * V_13 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , T_1 V_6 ,
bool V_7 )
{
struct V_15 * V_19 ;
struct V_1 * V_2 ;
T_2 V_17 ;
if ( V_13 -> V_20 < V_13 -> V_21 ) {
V_19 = F_10 ( & V_13 -> V_14 , struct V_15 ,
V_18 ) ;
} else {
V_19 = F_4 ( sizeof( struct V_15 ) ) ;
if ( ! V_19 )
return NULL ;
F_11 ( & V_19 -> V_18 , & V_13 -> V_14 ) ;
V_13 -> V_21 += V_22 ;
}
V_17 = V_13 -> V_20 ++ & V_23 ;
V_2 = & V_19 -> V_2 [ V_17 ] ;
F_1 ( V_2 , V_3 , V_5 , V_6 , V_7 ) ;
return V_2 ;
}
struct V_1 * F_12 ( struct V_12 * V_13 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_1 V_24 )
{
struct V_9 * * V_25 ;
struct V_9 * V_26 = NULL ;
struct V_1 * V_2 ;
bool V_7 = V_6 >= V_24 ;
if ( V_5 )
V_6 = 0 ;
if ( ! V_3 )
return F_9 ( V_13 , V_3 , V_5 , V_6 , V_7 ) ;
V_25 = & V_3 -> V_10 . V_9 ;
while ( * V_25 != NULL ) {
V_26 = * V_25 ;
V_2 = F_13 ( V_26 , struct V_1 , V_9 ) ;
if ( V_2 -> V_5 == V_5 && V_2 -> V_6 == V_6 )
return V_2 ;
if ( V_5 < V_2 -> V_5 || ( V_5 == V_2 -> V_5 && V_6 < V_2 -> V_6 ) )
V_25 = & ( * V_25 ) -> V_27 ;
else
V_25 = & ( * V_25 ) -> V_28 ;
}
V_2 = F_9 ( V_13 , V_3 , V_5 , V_6 , V_7 ) ;
if ( ! V_2 )
return NULL ;
F_14 ( & V_2 -> V_9 , V_26 , V_25 ) ;
F_15 ( & V_2 -> V_9 , & V_3 -> V_10 ) ;
return V_2 ;
}
