int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_2 -> V_5 [ V_3 ] . V_6 == V_7 ) {
V_2 -> V_5 [ V_3 ] . V_8 . V_9 = false ;
V_2 -> V_5 [ V_3 ] . V_8 . V_10 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 = 0 ;
break;
}
}
if ( V_3 == V_4 ) {
F_2 ( L_1 ) ;
V_3 = - V_11 ;
}
return V_3 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 = 0 ;
if ( ! F_4 ( V_2 -> V_15 ,
V_13 -> V_9 ) ) {
if ( V_13 -> V_10 < 0 ) {
F_2 ( L_2 , V_13 -> V_10 ) ;
V_14 = - V_11 ;
} else {
F_5 ( L_3 ) ;
V_14 = 0 ;
}
} else {
F_2 ( L_4 ) ;
V_14 = - V_16 ;
}
return V_14 ;
}
int F_6 (
struct V_1 * V_2 ,
struct V_12 * V_13 , int V_17 )
{
int V_14 = 0 ;
F_5 ( L_5 ) ;
if ( F_7 ( V_2 -> V_15 ,
V_13 -> V_9 ,
F_8 ( V_17 ) ) ) {
if ( V_13 -> V_10 < 0 )
F_2 ( L_2 , V_13 -> V_10 ) ;
else
F_5 ( L_3 ) ;
V_14 = V_13 -> V_10 ;
} else {
V_13 -> V_18 = false ;
F_2 ( L_6 ) ;
V_14 = - V_11 ;
}
return V_14 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_19 * V_13 )
{
int V_14 = 0 ;
F_5 ( L_7 ,
V_13 -> V_6 , V_13 -> V_8 . V_9 ) ;
if ( F_7 ( V_2 -> V_15 ,
V_13 -> V_8 . V_9 ,
F_8 ( V_20 ) ) ) {
F_5 ( L_8 , V_13 -> V_8 . V_9 ) ;
F_5 ( L_9 , V_13 -> V_8 . V_10 ) ;
V_14 = V_13 -> V_8 . V_10 ;
} else {
V_13 -> V_8 . V_18 = false ;
F_2 ( L_10 , V_13 -> V_8 . V_9 ) ;
V_14 = - V_11 ;
}
return V_14 ;
}
int F_10 ( struct V_21 * * V_22 )
{
struct V_21 * V_23 ;
V_23 = F_11 ( sizeof( struct V_21 ) , V_24 ) ;
if ( ! V_23 ) {
F_2 ( L_11 ) ;
return - V_25 ;
}
V_23 -> V_26 = F_11 ( V_27 , V_24 ) ;
if ( ! V_23 -> V_26 ) {
F_12 ( V_23 ) ;
F_2 ( L_12 ) ;
return - V_25 ;
}
* V_22 = V_23 ;
return 0 ;
}
int F_13 ( struct V_21 * * V_22 )
{
struct V_21 * V_23 ;
V_23 = F_11 ( sizeof( * V_23 ) , V_24 ) ;
if ( ! V_23 ) {
F_2 ( L_11 ) ;
return - V_25 ;
}
V_23 -> V_26 = NULL ;
* V_22 = V_23 ;
return 0 ;
}
void F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = NULL , * V_32 ;
V_29 -> V_33 = V_34 ;
V_29 -> V_35 = V_34 ;
F_15 ( & V_29 -> V_36 ) ;
F_16 (bufs, _bufs, &stream->bufs, node) {
F_17 ( & V_31 -> V_37 ) ;
F_12 ( V_31 ) ;
}
F_18 ( & V_29 -> V_36 ) ;
if ( V_29 -> V_38 != V_39 )
F_12 ( V_29 -> V_40 ) ;
}
void F_19 ( struct V_1 * V_2 ,
T_1 V_6 , int V_33 , void * V_41 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_6 == V_2 -> V_5 [ V_3 ] . V_6 ) {
V_2 -> V_5 [ V_3 ] . V_8 . V_9 = true ;
V_2 -> V_5 [ V_3 ] . V_8 . V_10 = V_33 ;
V_2 -> V_5 [ V_3 ] . V_8 . V_41 = V_41 ;
F_20 ( & V_2 -> V_15 ) ;
break;
}
}
}
int F_21 ( int V_33 )
{
int V_14 = 0 ;
struct V_21 * V_23 = NULL ;
if ( F_13 ( & V_23 ) ) {
F_2 ( L_13 ) ;
return - V_25 ;
}
F_5 ( L_14 ) ;
F_22 ( & V_23 -> V_42 , V_43 , 0 , 0 ) ;
V_23 -> V_42 . V_44 . V_41 = V_33 ;
V_2 -> V_45 . V_9 = false ;
V_2 -> V_45 . V_10 = 0 ;
V_2 -> V_45 . V_18 = true ;
F_23 ( & V_2 -> V_46 ) ;
F_24 ( & V_23 -> V_37 ,
& V_2 -> V_47 ) ;
F_25 ( & V_2 -> V_46 ) ;
F_26 ( & V_2 -> V_48 ) ;
V_14 = F_6 ( V_2 ,
& V_2 -> V_45 , V_20 ) ;
return V_14 ;
}
