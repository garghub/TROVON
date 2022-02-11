static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) -> V_5 ;
return F_3 ( V_2 , V_4 -> V_6 -> V_7 , V_4 ) ;
}
int F_4 ( struct V_8 * V_9 , int V_10 ,
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
V_18 = F_5 ( sizeof( struct V_3 ) , V_25 ) ;
if ( V_18 == NULL ) {
V_21 = - 1 ;
goto V_26;
}
V_18 -> V_14 = V_14 ;
V_18 -> V_6 = & V_9 [ V_20 ] ;
F_6 ( & V_18 -> V_27 , & V_14 -> V_28 . V_27 ) ;
V_17 = F_7 ( V_9 [ V_20 ] . V_19 , V_29 , V_12 ,
& V_30 , V_18 ) ;
if ( ! V_17 ) {
F_8 ( L_1 ,
V_19 , V_9 [ V_20 ] . V_19 ) ;
F_9 ( & V_18 -> V_27 ) ;
F_10 ( V_18 ) ;
V_21 = - 1 ;
goto V_26;
}
}
return 0 ;
V_26:
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ )
F_11 ( V_31 [ V_20 ] . V_19 , V_14 -> V_32 ) ;
return V_21 ;
}
int F_12 ( struct V_13 * V_14 , int V_33 ,
struct V_11 * V_12 )
{
char V_19 [ 64 ] ;
int V_21 ;
F_13 ( & V_14 -> V_28 . V_27 ) ;
sprintf ( V_19 , L_2 , V_33 ) ;
V_14 -> V_32 = F_14 ( V_19 , V_12 ) ;
if ( ! V_14 -> V_32 ) {
F_8 ( L_3 , V_19 ) ;
return - 1 ;
}
V_21 = F_4 ( V_31 , V_34 ,
V_14 -> V_32 , V_14 ) ;
if ( V_21 ) {
F_11 ( V_19 , V_12 ) ;
V_14 -> V_32 = NULL ;
F_8 ( L_4 ) ;
return V_21 ;
}
return 0 ;
}
int F_15 ( struct V_8 * V_9 , int V_10 ,
struct V_13 * V_14 )
{
struct V_35 * V_36 , * V_37 ;
struct V_3 * V_18 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
F_16 (pos, q, &minor->proc_nodes.list) {
V_18 = F_17 ( V_36 , struct V_3 , V_27 ) ;
if ( V_18 -> V_6 == & V_9 [ V_20 ] ) {
F_11 ( V_9 [ V_20 ] . V_19 ,
V_14 -> V_32 ) ;
F_9 ( V_36 ) ;
F_10 ( V_18 ) ;
}
}
}
return 0 ;
}
int F_18 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
char V_19 [ 64 ] ;
if ( ! V_12 || ! V_14 -> V_32 )
return 0 ;
F_15 ( V_31 , V_34 , V_14 ) ;
sprintf ( V_19 , L_2 , V_14 -> V_38 ) ;
F_11 ( V_19 , V_12 ) ;
return 0 ;
}
