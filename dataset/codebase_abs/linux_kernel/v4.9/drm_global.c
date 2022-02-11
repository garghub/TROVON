void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_3 * V_4 = & V_5 [ V_1 ] ;
F_2 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = NULL ;
V_4 -> V_8 = 0 ;
}
}
void F_3 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_3 * V_4 = & V_5 [ V_1 ] ;
F_4 ( V_4 -> V_7 != NULL ) ;
F_4 ( V_4 -> V_8 != 0 ) ;
}
}
int F_5 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_3 * V_4 = & V_5 [ V_10 -> V_12 ] ;
F_6 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_8 == 0 ) {
V_10 -> V_7 = F_7 ( V_10 -> V_13 , V_14 ) ;
if ( F_8 ( V_10 -> V_7 == NULL ) ) {
V_11 = - V_15 ;
goto V_16;
}
V_11 = V_10 -> V_17 ( V_10 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_18;
V_4 -> V_7 = V_10 -> V_7 ;
} else {
V_10 -> V_7 = V_4 -> V_7 ;
}
++ V_4 -> V_8 ;
F_9 ( & V_4 -> V_6 ) ;
return 0 ;
V_18:
F_10 ( V_10 -> V_7 ) ;
V_10 -> V_7 = NULL ;
V_16:
F_9 ( & V_4 -> V_6 ) ;
return V_11 ;
}
void F_11 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = & V_5 [ V_10 -> V_12 ] ;
F_6 ( & V_4 -> V_6 ) ;
F_4 ( V_4 -> V_8 == 0 ) ;
F_4 ( V_10 -> V_7 != V_4 -> V_7 ) ;
if ( -- V_4 -> V_8 == 0 ) {
V_10 -> V_19 ( V_10 ) ;
V_4 -> V_7 = NULL ;
}
F_9 ( & V_4 -> V_6 ) ;
}
