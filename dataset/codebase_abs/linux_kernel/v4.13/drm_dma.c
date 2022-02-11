int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! F_2 ( V_2 , V_4 ) ||
! F_2 ( V_2 , V_5 ) )
return 0 ;
V_2 -> V_6 = 0 ;
F_3 ( & V_2 -> V_7 , 0 ) ;
V_2 -> V_8 = F_4 ( sizeof( * V_2 -> V_8 ) , V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
for ( V_3 = 0 ; V_3 <= V_11 ; V_3 ++ )
memset ( & V_2 -> V_8 -> V_12 [ V_3 ] , 0 , sizeof( V_2 -> V_8 -> V_12 [ 0 ] ) ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_8 = V_2 -> V_8 ;
int V_3 , V_14 ;
if ( ! F_2 ( V_2 , V_4 ) ||
! F_2 ( V_2 , V_5 ) )
return;
if ( ! V_8 )
return;
for ( V_3 = 0 ; V_3 <= V_11 ; V_3 ++ ) {
if ( V_8 -> V_12 [ V_3 ] . V_15 ) {
F_6 ( L_1
L_2 ,
V_3 ,
V_8 -> V_12 [ V_3 ] . V_16 ,
V_8 -> V_12 [ V_3 ] . V_15 ) ;
for ( V_14 = 0 ; V_14 < V_8 -> V_12 [ V_3 ] . V_15 ; V_14 ++ ) {
if ( V_8 -> V_12 [ V_3 ] . V_17 [ V_14 ] ) {
F_7 ( V_2 , V_8 -> V_12 [ V_3 ] . V_17 [ V_14 ] ) ;
}
}
F_8 ( V_8 -> V_12 [ V_3 ] . V_17 ) ;
}
if ( V_8 -> V_12 [ V_3 ] . V_16 ) {
for ( V_14 = 0 ; V_14 < V_8 -> V_12 [ V_3 ] . V_16 ; V_14 ++ ) {
F_8 ( V_8 -> V_12 [ V_3 ] . V_18 [ V_14 ] . V_19 ) ;
}
F_8 ( V_8 -> V_12 [ V_3 ] . V_18 ) ;
}
}
F_8 ( V_8 -> V_18 ) ;
F_8 ( V_8 -> V_20 ) ;
F_8 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
void F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( ! V_22 )
return;
V_22 -> V_23 = 0 ;
V_22 -> V_24 = 0 ;
V_22 -> V_25 = NULL ;
V_22 -> V_26 = 0 ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_27 * V_25 )
{
struct V_13 * V_8 = V_2 -> V_8 ;
int V_3 ;
if ( ! V_8 )
return;
for ( V_3 = 0 ; V_3 < V_8 -> V_16 ; V_3 ++ ) {
if ( V_8 -> V_18 [ V_3 ] -> V_25 == V_25 ) {
switch ( V_8 -> V_18 [ V_3 ] -> V_28 ) {
case V_29 :
F_9 ( V_2 , V_8 -> V_18 [ V_3 ] ) ;
break;
case V_30 :
V_8 -> V_18 [ V_3 ] -> V_28 = V_31 ;
break;
default:
break;
}
}
}
}
