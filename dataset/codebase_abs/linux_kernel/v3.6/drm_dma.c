int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( sizeof( * V_2 -> V_4 ) , V_5 ) ;
if ( ! V_2 -> V_4 )
return - V_6 ;
for ( V_3 = 0 ; V_3 <= V_7 ; V_3 ++ )
memset ( & V_2 -> V_4 -> V_8 [ V_3 ] , 0 , sizeof( V_2 -> V_4 -> V_8 [ 0 ] ) ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
int V_3 , V_10 ;
if ( ! V_4 )
return;
for ( V_3 = 0 ; V_3 <= V_7 ; V_3 ++ ) {
if ( V_4 -> V_8 [ V_3 ] . V_11 ) {
F_4 ( L_1
L_2 ,
V_3 ,
V_4 -> V_8 [ V_3 ] . V_12 ,
V_4 -> V_8 [ V_3 ] . V_11 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_8 [ V_3 ] . V_11 ; V_10 ++ ) {
if ( V_4 -> V_8 [ V_3 ] . V_13 [ V_10 ] ) {
F_5 ( V_2 , V_4 -> V_8 [ V_3 ] . V_13 [ V_10 ] ) ;
}
}
F_6 ( V_4 -> V_8 [ V_3 ] . V_13 ) ;
}
if ( V_4 -> V_8 [ V_3 ] . V_12 ) {
for ( V_10 = 0 ; V_10 < V_4 -> V_8 [ V_3 ] . V_12 ; V_10 ++ ) {
F_6 ( V_4 -> V_8 [ V_3 ] . V_14 [ V_10 ] . V_15 ) ;
}
F_6 ( V_4 -> V_8 [ V_3 ] . V_14 ) ;
}
}
F_6 ( V_4 -> V_14 ) ;
F_6 ( V_4 -> V_16 ) ;
F_6 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_7 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( ! V_18 )
return;
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 0 ;
V_18 -> V_21 = NULL ;
V_18 -> V_22 = 0 ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_23 * V_21 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
int V_3 ;
if ( ! V_4 )
return;
for ( V_3 = 0 ; V_3 < V_4 -> V_12 ; V_3 ++ ) {
if ( V_4 -> V_14 [ V_3 ] -> V_21 == V_21 ) {
switch ( V_4 -> V_14 [ V_3 ] -> V_24 ) {
case V_25 :
F_7 ( V_2 , V_4 -> V_14 [ V_3 ] ) ;
break;
case V_26 :
V_4 -> V_14 [ V_3 ] -> V_24 = V_27 ;
break;
default:
break;
}
}
}
}
