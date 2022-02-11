static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_7 = V_4 -> V_11 [ V_9 ] ;
if ( ! V_7 )
break;
}
if ( V_9 == 0 ) {
F_2 ( V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_6 = & V_2 -> V_15 [ V_9 ] ;
V_7 = V_4 -> V_11 [ V_9 ] ;
V_8 = F_4 ( V_2 , V_7 , V_16 ) ;
if ( V_8 ) {
V_6 -> type = V_17 ;
} else {
V_8 = F_5 ( V_2 , V_6 , NULL , V_7 ) ;
if ( V_8 ) {
F_6 ( V_7 , V_16 ) ;
V_6 -> type = V_17 ;
return V_8 ;
}
}
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_6 = & V_2 -> V_15 [ V_9 ] ;
if ( V_6 -> type != V_17 ) {
unsigned long V_18 = F_8 ( V_6 ) ;
F_6 ( V_18 , V_16 ) ;
}
}
}
