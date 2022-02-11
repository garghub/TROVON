static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
return F_3 ( V_2 , V_4 -> V_5 -> V_6 , V_4 ) ;
}
static int F_4 ( const struct V_7 * V_8 , int V_9 ,
struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_10 * V_16 ;
struct V_3 * V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
T_1 V_19 = V_8 [ V_18 ] . V_20 ;
if ( V_19 != 0 &&
( V_15 -> V_21 -> V_20 & V_19 ) != V_19 )
continue;
V_17 = F_5 ( sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_13 = V_13 ;
V_17 -> V_5 = & V_8 [ V_18 ] ;
F_6 ( & V_17 -> V_23 , & V_13 -> V_24 . V_23 ) ;
V_16 = F_7 ( V_8 [ V_18 ] . V_25 , V_26 , V_11 ,
& V_27 , V_17 ) ;
if ( ! V_16 ) {
F_8 ( L_1 ,
V_13 -> V_28 , V_8 [ V_18 ] . V_25 ) ;
F_9 ( & V_17 -> V_23 ) ;
F_10 ( V_17 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_11 ( struct V_12 * V_13 , struct V_10 * V_11 )
{
char V_25 [ 12 ] ;
int V_29 ;
F_12 ( & V_13 -> V_24 . V_23 ) ;
sprintf ( V_25 , L_2 , V_13 -> V_28 ) ;
V_13 -> V_30 = F_13 ( V_25 , V_11 ) ;
if ( ! V_13 -> V_30 ) {
F_8 ( L_3 , V_25 ) ;
return - 1 ;
}
V_29 = F_4 ( V_31 , V_32 ,
V_13 -> V_30 , V_13 ) ;
if ( V_29 ) {
F_14 ( V_25 , V_11 ) ;
V_13 -> V_30 = NULL ;
F_8 ( L_4 ) ;
return V_29 ;
}
return 0 ;
}
static int F_15 ( const struct V_7 * V_8 , int V_9 ,
struct V_12 * V_13 )
{
struct V_33 * V_34 , * V_35 ;
struct V_3 * V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
F_16 (pos, q, &minor->proc_nodes.list) {
V_17 = F_17 ( V_34 , struct V_3 , V_23 ) ;
if ( V_17 -> V_5 == & V_8 [ V_18 ] ) {
F_18 ( V_8 [ V_18 ] . V_25 ,
V_13 -> V_30 ) ;
F_9 ( V_34 ) ;
F_10 ( V_17 ) ;
}
}
}
return 0 ;
}
int F_19 ( struct V_12 * V_13 , struct V_10 * V_11 )
{
char V_25 [ 64 ] ;
if ( ! V_11 || ! V_13 -> V_30 )
return 0 ;
F_15 ( V_31 , V_32 , V_13 ) ;
sprintf ( V_25 , L_5 , V_13 -> V_28 ) ;
F_14 ( V_25 , V_11 ) ;
return 0 ;
}
