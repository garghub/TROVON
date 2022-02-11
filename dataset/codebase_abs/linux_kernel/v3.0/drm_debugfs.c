static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_2 ( V_2 , V_4 -> V_6 -> V_7 , V_4 ) ;
}
int F_3 ( struct V_8 * V_9 , int V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_11 * V_17 ;
struct V_3 * V_18 ;
char V_19 [ 64 ] ;
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
T_1 V_22 = V_9 [ V_20 ] . V_23 ;
if ( V_22 != 0 &&
( V_16 -> V_24 -> V_23 & V_22 ) != V_22 )
continue;
V_18 = F_4 ( sizeof( struct V_3 ) , V_25 ) ;
if ( V_18 == NULL ) {
V_21 = - 1 ;
goto V_26;
}
V_17 = F_5 ( V_9 [ V_20 ] . V_19 , V_27 | V_28 ,
V_12 , V_18 , & V_29 ) ;
if ( ! V_17 ) {
F_6 ( L_1 ,
V_19 , V_9 [ V_20 ] . V_19 ) ;
F_7 ( V_18 ) ;
V_21 = - 1 ;
goto V_26;
}
V_18 -> V_14 = V_14 ;
V_18 -> V_30 = V_17 ;
V_18 -> V_6 = & V_9 [ V_20 ] ;
F_8 ( & ( V_18 -> V_31 ) , & ( V_14 -> V_32 . V_31 ) ) ;
}
return 0 ;
V_26:
F_9 ( V_9 , V_10 , V_14 ) ;
return V_21 ;
}
int F_10 ( struct V_13 * V_14 , int V_33 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
char V_19 [ 64 ] ;
int V_21 ;
F_11 ( & V_14 -> V_32 . V_31 ) ;
sprintf ( V_19 , L_2 , V_33 ) ;
V_14 -> V_34 = F_12 ( V_19 , V_12 ) ;
if ( ! V_14 -> V_34 ) {
F_6 ( L_3 , V_19 ) ;
return - 1 ;
}
V_21 = F_3 ( V_35 , V_36 ,
V_14 -> V_34 , V_14 ) ;
if ( V_21 ) {
F_13 ( V_14 -> V_34 ) ;
V_14 -> V_34 = NULL ;
F_6 ( L_4 ) ;
return V_21 ;
}
if ( V_16 -> V_24 -> V_37 ) {
V_21 = V_16 -> V_24 -> V_37 ( V_14 ) ;
if ( V_21 ) {
F_6 ( L_5
L_6 ) ;
return V_21 ;
}
}
return 0 ;
}
int F_9 ( struct V_8 * V_9 , int V_10 ,
struct V_13 * V_14 )
{
struct V_38 * V_39 , * V_40 ;
struct V_3 * V_18 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
F_14 (pos, q, &minor->debugfs_nodes.list) {
V_18 = F_15 ( V_39 , struct V_3 , V_31 ) ;
if ( V_18 -> V_6 == & V_9 [ V_20 ] ) {
F_13 ( V_18 -> V_30 ) ;
F_16 ( V_39 ) ;
F_7 ( V_18 ) ;
}
}
}
return 0 ;
}
int F_17 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_34 )
return 0 ;
if ( V_16 -> V_24 -> V_41 )
V_16 -> V_24 -> V_41 ( V_14 ) ;
F_9 ( V_35 , V_36 , V_14 ) ;
F_13 ( V_14 -> V_34 ) ;
V_14 -> V_34 = NULL ;
return 0 ;
}
