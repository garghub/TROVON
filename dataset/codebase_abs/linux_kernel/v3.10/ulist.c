void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = V_1 -> V_4 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_7 = V_8 ;
}
void F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 > V_6 )
F_3 ( V_1 -> V_3 ) ;
V_1 -> V_5 = 0 ;
V_1 -> V_7 = V_8 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
F_1 ( V_1 ) ;
}
struct V_1 * F_5 ( T_1 V_9 )
{
struct V_1 * V_1 = F_6 ( sizeof( * V_1 ) , V_9 ) ;
if ( ! V_1 )
return NULL ;
F_1 ( V_1 ) ;
return V_1 ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
}
static struct V_10 * F_8 ( struct V_1 * V_1 , T_2 V_11 )
{
struct V_12 * V_13 = V_1 -> V_7 . V_12 ;
struct V_10 * V_14 = NULL ;
while ( V_13 ) {
V_14 = F_9 ( V_13 , struct V_10 , V_12 ) ;
if ( V_14 -> V_11 < V_11 )
V_13 = V_13 -> V_15 ;
else if ( V_14 -> V_11 > V_11 )
V_13 = V_13 -> V_16 ;
else
return V_14 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_1 , struct V_10 * V_17 )
{
struct V_12 * * V_18 = & V_1 -> V_7 . V_12 ;
struct V_12 * V_19 = NULL ;
struct V_10 * V_20 = NULL ;
while ( * V_18 ) {
V_19 = * V_18 ;
V_20 = F_9 ( V_19 , struct V_10 , V_12 ) ;
if ( V_20 -> V_11 < V_17 -> V_11 )
V_18 = & ( * V_18 ) -> V_15 ;
else if ( V_20 -> V_11 > V_17 -> V_11 )
V_18 = & ( * V_18 ) -> V_16 ;
else
return - V_21 ;
}
F_11 ( & V_17 -> V_12 , V_19 , V_18 ) ;
F_12 ( & V_17 -> V_12 , & V_1 -> V_7 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_1 , T_2 V_11 , T_2 V_22 , T_1 V_9 )
{
return F_14 ( V_1 , V_11 , V_22 , NULL , V_9 ) ;
}
int F_14 ( struct V_1 * V_1 , T_2 V_11 , T_2 V_22 ,
T_2 * V_23 , T_1 V_9 )
{
int V_24 = 0 ;
struct V_10 * V_25 = NULL ;
V_25 = F_8 ( V_1 , V_11 ) ;
if ( V_25 ) {
if ( V_23 )
* V_23 = V_25 -> V_22 ;
return 0 ;
}
if ( V_1 -> V_2 >= V_1 -> V_5 ) {
T_2 V_26 = V_1 -> V_5 + 128 ;
struct V_10 * V_27 ;
void * V_28 = NULL ;
if ( V_1 -> V_5 > V_6 )
V_28 = V_1 -> V_3 ;
V_27 = F_15 ( V_28 , sizeof( * V_27 ) * V_26 ,
V_9 ) ;
if ( ! V_27 )
return - V_29 ;
if ( ! V_28 )
memcpy ( V_27 , V_1 -> V_4 ,
sizeof( V_1 -> V_4 ) ) ;
V_1 -> V_3 = V_27 ;
V_1 -> V_5 = V_26 ;
}
V_1 -> V_3 [ V_1 -> V_2 ] . V_11 = V_11 ;
V_1 -> V_3 [ V_1 -> V_2 ] . V_22 = V_22 ;
V_24 = F_10 ( V_1 , & V_1 -> V_3 [ V_1 -> V_2 ] ) ;
F_16 ( V_24 ) ;
++ V_1 -> V_2 ;
return 1 ;
}
struct V_10 * F_17 ( struct V_1 * V_1 , struct V_30 * V_31 )
{
if ( V_1 -> V_2 == 0 )
return NULL ;
if ( V_31 -> V_32 < 0 || V_31 -> V_32 >= V_1 -> V_2 )
return NULL ;
return & V_1 -> V_3 [ V_31 -> V_32 ++ ] ;
}
