void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 )
F_3 ( V_2 -> V_5 ) ;
F_4 ( & V_3 ) ;
}
int F_5 ( struct V_1 * * V_6 ,
unsigned V_7 , unsigned V_8 ,
unsigned * V_9 )
{
unsigned V_10 ;
int V_11 = - V_12 ;
struct V_13 V_14 ;
F_6 ( & V_14 ) ;
if ( V_15 == V_8 )
V_8 = V_16 ;
F_2 ( & V_3 ) ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( F_7 ( & V_6 [ V_10 ] -> V_4 ) ) {
F_8 ( & V_6 [ V_10 ] -> V_4 ) ;
* V_9 = V_10 ;
F_4 ( & V_3 ) ;
V_11 = 0 ;
goto V_17;
}
}
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
V_6 [ V_10 ] -> V_5 = & V_14 ;
F_4 ( & V_3 ) ;
if ( ! F_9 ( & V_14 ,
F_10 ( V_8 ) ) )
V_11 = - V_18 ;
F_2 ( & V_3 ) ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( F_7 ( & V_6 [ V_10 ] -> V_4 ) ) {
F_8 ( & V_6 [ V_10 ] -> V_4 ) ;
* V_9 = V_10 ;
V_11 = 0 ;
}
V_6 [ V_10 ] -> V_5 = NULL ;
}
F_4 ( & V_3 ) ;
V_17:
return V_11 ;
}
int F_11 ( struct V_19 * V_20 , unsigned long V_2 ,
void * V_21 )
{
struct V_22 * V_23 = F_12 ( V_20 , struct V_22 ,
V_24 ) ;
if ( V_23 -> V_2 & V_2 )
F_1 ( & V_23 -> V_25 ) ;
return V_26 ;
}
