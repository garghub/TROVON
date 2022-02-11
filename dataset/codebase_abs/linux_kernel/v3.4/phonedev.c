static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = F_2 ( V_1 ) ;
int V_4 = 0 ;
struct V_5 * V_6 ;
const struct V_7 * V_8 , * V_9 = NULL ;
if ( V_3 >= V_10 )
return - V_11 ;
F_3 ( & V_12 ) ;
V_6 = V_5 [ V_3 ] ;
if ( V_6 )
V_9 = F_4 ( V_6 -> V_13 ) ;
if ( ! V_9 ) {
F_5 ( & V_12 ) ;
F_6 ( L_1 , V_14 , V_3 ) ;
F_3 ( & V_12 ) ;
V_6 = V_5 [ V_3 ] ;
if ( V_6 == NULL || ( V_9 = F_4 ( V_6 -> V_13 ) ) == NULL )
{
V_4 = - V_11 ;
goto V_15;
}
}
V_8 = V_2 -> V_13 ;
V_2 -> V_13 = V_9 ;
if ( V_6 -> V_16 )
V_4 = V_6 -> V_16 ( V_6 , V_2 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = F_4 ( V_8 ) ;
}
F_7 ( V_8 ) ;
V_15:
F_5 ( & V_12 ) ;
return V_4 ;
}
int F_8 ( struct V_5 * V_6 , int V_17 )
{
int V_18 ;
int V_15 ;
int V_19 ;
V_18 = 0 ;
V_15 = V_10 - 1 ;
if ( V_17 != V_20 ) {
V_18 = V_17 ;
V_15 = V_17 + 1 ;
}
F_3 ( & V_12 ) ;
for ( V_19 = V_18 ; V_19 < V_15 ; V_19 ++ ) {
if ( V_5 [ V_19 ] == NULL ) {
V_5 [ V_19 ] = V_6 ;
V_6 -> V_3 = V_19 ;
F_5 ( & V_12 ) ;
return 0 ;
}
}
F_5 ( & V_12 ) ;
return - V_21 ;
}
void F_9 ( struct V_5 * V_22 )
{
F_3 ( & V_12 ) ;
if ( F_10 ( V_5 [ V_22 -> V_3 ] == V_22 ) )
V_5 [ V_22 -> V_3 ] = NULL ;
F_5 ( & V_12 ) ;
}
static int T_1 F_11 ( void )
{
F_12 ( V_23 L_2 ) ;
if ( F_13 ( V_14 , L_3 , & V_24 ) ) {
F_12 ( L_4 , V_14 ) ;
return - V_25 ;
}
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_14 , L_3 ) ;
}
