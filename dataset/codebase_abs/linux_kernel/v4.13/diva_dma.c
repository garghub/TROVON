struct V_1 * F_1 ( void * V_2 , int V_3 ) {
T_1 * V_4 = F_2 ( 0 , sizeof( * V_4 ) * ( V_3 + 1 ) ) ;
if ( V_4 )
memset ( V_4 , 0 , sizeof( * V_4 ) * ( V_3 + 1 ) ) ;
return V_4 ;
}
void F_3 ( struct V_1 * V_4 ) {
if ( V_4 ) {
F_4 ( 0 , V_4 ) ;
}
}
void F_5 ( struct V_1 * V_4 ,
int V_5 , void * V_6 , T_2 V_7 ,
void * V_8 ) {
V_4 [ V_5 ] . V_9 = V_7 ;
V_4 [ V_5 ] . V_10 = V_6 ;
V_4 [ V_5 ] . V_8 = V_8 ;
}
int F_6 ( struct V_1 * V_4 ) {
int V_11 ;
for ( V_11 = 0 ; ( V_4 && V_4 [ V_11 ] . V_10 ) ; V_11 ++ ) {
if ( ! V_4 [ V_11 ] . V_12 ) {
V_4 [ V_11 ] . V_12 = 1 ;
return ( V_11 ) ;
}
}
return ( - 1 ) ;
}
void F_7 ( struct V_1 * V_4 , int V_5 ) {
V_4 [ V_5 ] . V_12 = 0 ;
}
void F_8 ( struct V_1 * V_4 , int V_5 ,
void * * V_13 , T_2 * V_14 ) {
* V_14 = V_4 [ V_5 ] . V_9 ;
* V_13 = V_4 [ V_5 ] . V_10 ;
}
void * F_9 ( struct V_1 * V_4 , int V_5 ) {
return ( V_4 [ V_5 ] . V_8 ) ;
}
