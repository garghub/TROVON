int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 = NULL ;
int V_8 , V_9 , V_10 = 0 ;
unsigned long V_11 ;
F_2 () ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 <= 0 ) {
V_10 = V_9 ? V_9 : - V_12 ;
goto V_13;
}
V_7 = F_4 ( sizeof( * V_7 ) * ( V_9 + 1 ) , V_14 ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
goto V_13;
}
for ( V_8 = 0 , V_11 = 0 ; V_8 < V_9 ; V_8 ++ , V_11 ++ ) {
V_6 = F_5 ( V_2 , & V_11 ) ;
if ( F_6 ( V_6 ) ) {
V_10 = F_7 ( V_6 ) ;
goto V_13;
}
V_7 [ V_8 ] . V_16 = V_8 ;
V_7 [ V_8 ] . V_17 = V_11 / 1000 ;
}
V_7 [ V_8 ] . V_16 = V_8 ;
V_7 [ V_8 ] . V_17 = V_18 ;
* V_4 = & V_7 [ 0 ] ;
V_13:
F_8 () ;
if ( V_10 )
F_9 ( V_7 ) ;
return V_10 ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
if ( ! V_4 )
return;
F_9 ( * V_4 ) ;
* V_4 = NULL ;
}
