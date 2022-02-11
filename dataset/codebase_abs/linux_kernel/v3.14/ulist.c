void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
V_1 -> V_5 = 0 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_6 * V_8 ;
F_4 (node, next, &ulist->nodes, list) {
F_5 ( V_7 ) ;
}
V_1 -> V_3 = V_4 ;
F_2 ( & V_1 -> V_2 ) ;
}
void F_6 ( struct V_1 * V_1 )
{
F_3 ( V_1 ) ;
F_1 ( V_1 ) ;
}
struct V_1 * F_7 ( T_1 V_9 )
{
struct V_1 * V_1 = F_8 ( sizeof( * V_1 ) , V_9 ) ;
if ( ! V_1 )
return NULL ;
F_1 ( V_1 ) ;
return V_1 ;
}
void F_9 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return;
F_3 ( V_1 ) ;
F_5 ( V_1 ) ;
}
static struct V_6 * F_10 ( struct V_1 * V_1 , T_2 V_10 )
{
struct V_11 * V_12 = V_1 -> V_3 . V_11 ;
struct V_6 * V_13 = NULL ;
while ( V_12 ) {
V_13 = F_11 ( V_12 , struct V_6 , V_11 ) ;
if ( V_13 -> V_10 < V_10 )
V_12 = V_12 -> V_14 ;
else if ( V_13 -> V_10 > V_10 )
V_12 = V_12 -> V_15 ;
else
return V_13 ;
}
return NULL ;
}
static int F_12 ( struct V_1 * V_1 , struct V_6 * V_16 )
{
struct V_11 * * V_17 = & V_1 -> V_3 . V_11 ;
struct V_11 * V_18 = NULL ;
struct V_6 * V_19 = NULL ;
while ( * V_17 ) {
V_18 = * V_17 ;
V_19 = F_11 ( V_18 , struct V_6 , V_11 ) ;
if ( V_19 -> V_10 < V_16 -> V_10 )
V_17 = & ( * V_17 ) -> V_14 ;
else if ( V_19 -> V_10 > V_16 -> V_10 )
V_17 = & ( * V_17 ) -> V_15 ;
else
return - V_20 ;
}
F_13 ( & V_16 -> V_11 , V_18 , V_17 ) ;
F_14 ( & V_16 -> V_11 , & V_1 -> V_3 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_1 , T_2 V_10 , T_2 V_21 , T_1 V_9 )
{
return F_16 ( V_1 , V_10 , V_21 , NULL , V_9 ) ;
}
int F_16 ( struct V_1 * V_1 , T_2 V_10 , T_2 V_21 ,
T_2 * V_22 , T_1 V_9 )
{
int V_23 ;
struct V_6 * V_7 ;
V_7 = F_10 ( V_1 , V_10 ) ;
if ( V_7 ) {
if ( V_22 )
* V_22 = V_7 -> V_21 ;
return 0 ;
}
V_7 = F_8 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return - V_24 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_21 = V_21 ;
#ifdef F_17
V_7 -> V_25 = V_1 -> V_5 ;
#endif
V_23 = F_12 ( V_1 , V_7 ) ;
ASSERT ( ! V_23 ) ;
F_18 ( & V_7 -> V_26 , & V_1 -> V_2 ) ;
V_1 -> V_5 ++ ;
return 1 ;
}
struct V_6 * F_19 ( struct V_1 * V_1 , struct V_27 * V_28 )
{
struct V_6 * V_7 ;
if ( F_20 ( & V_1 -> V_2 ) )
return NULL ;
if ( V_28 -> V_29 && V_28 -> V_29 -> V_8 == & V_1 -> V_2 )
return NULL ;
if ( V_28 -> V_29 ) {
V_28 -> V_29 = V_28 -> V_29 -> V_8 ;
} else {
V_28 -> V_29 = V_1 -> V_2 . V_8 ;
#ifdef F_17
V_28 -> V_30 = 0 ;
#endif
}
V_7 = F_21 ( V_28 -> V_29 , struct V_6 , V_26 ) ;
#ifdef F_17
ASSERT ( V_7 -> V_25 == V_28 -> V_30 ) ;
ASSERT ( V_28 -> V_30 >= 0 && V_28 -> V_30 < V_1 -> V_5 ) ;
V_28 -> V_30 ++ ;
#endif
return V_7 ;
}
