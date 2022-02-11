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
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
T_1 V_21 = V_9 [ V_19 ] . V_22 ;
if ( V_21 != 0 &&
( V_16 -> V_23 -> V_22 & V_21 ) != V_21 )
continue;
V_18 = F_4 ( sizeof( struct V_3 ) , V_24 ) ;
if ( V_18 == NULL ) {
V_20 = - 1 ;
goto V_25;
}
V_17 = F_5 ( V_9 [ V_19 ] . V_26 , V_27 | V_28 ,
V_12 , V_18 , & V_29 ) ;
if ( ! V_17 ) {
F_6 ( L_1 ,
V_12 -> V_30 . V_26 , V_9 [ V_19 ] . V_26 ) ;
F_7 ( V_18 ) ;
V_20 = - 1 ;
goto V_25;
}
V_18 -> V_14 = V_14 ;
V_18 -> V_31 = V_17 ;
V_18 -> V_6 = & V_9 [ V_19 ] ;
F_8 ( & V_14 -> V_32 ) ;
F_9 ( & V_18 -> V_33 , & V_14 -> V_34 ) ;
F_10 ( & V_14 -> V_32 ) ;
}
return 0 ;
V_25:
F_11 ( V_9 , V_10 , V_14 ) ;
return V_20 ;
}
int F_12 ( struct V_13 * V_14 , int V_35 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
char V_26 [ 64 ] ;
int V_20 ;
F_13 ( & V_14 -> V_34 ) ;
F_14 ( & V_14 -> V_32 ) ;
sprintf ( V_26 , L_2 , V_35 ) ;
V_14 -> V_36 = F_15 ( V_26 , V_12 ) ;
if ( ! V_14 -> V_36 ) {
F_6 ( L_3 , V_26 ) ;
return - 1 ;
}
V_20 = F_3 ( V_37 , V_38 ,
V_14 -> V_36 , V_14 ) ;
if ( V_20 ) {
F_16 ( V_14 -> V_36 ) ;
V_14 -> V_36 = NULL ;
F_6 ( L_4 ) ;
return V_20 ;
}
if ( V_16 -> V_23 -> V_39 ) {
V_20 = V_16 -> V_23 -> V_39 ( V_14 ) ;
if ( V_20 ) {
F_6 ( L_5
L_6 ) ;
return V_20 ;
}
}
return 0 ;
}
int F_11 ( struct V_8 * V_9 , int V_10 ,
struct V_13 * V_14 )
{
struct V_40 * V_41 , * V_42 ;
struct V_3 * V_18 ;
int V_19 ;
F_8 ( & V_14 -> V_32 ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
F_17 (pos, q, &minor->debugfs_list) {
V_18 = F_18 ( V_41 , struct V_3 , V_33 ) ;
if ( V_18 -> V_6 == & V_9 [ V_19 ] ) {
F_16 ( V_18 -> V_31 ) ;
F_19 ( V_41 ) ;
F_7 ( V_18 ) ;
}
}
}
F_10 ( & V_14 -> V_32 ) ;
return 0 ;
}
int F_20 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_36 )
return 0 ;
if ( V_16 -> V_23 -> V_43 )
V_16 -> V_23 -> V_43 ( V_14 ) ;
F_11 ( V_37 , V_38 , V_14 ) ;
F_16 ( V_14 -> V_36 ) ;
V_14 -> V_36 = NULL ;
return 0 ;
}
