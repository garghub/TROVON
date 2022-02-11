struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
F_3 ( & V_3 -> V_4 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = - 1 ;
V_3 -> V_6 = malloc ( 32 ) ;
if ( V_3 -> V_6 )
snprintf ( V_3 -> V_6 , 32 , L_1 , V_3 -> V_2 ) ;
}
return V_3 ;
}
void F_4 ( struct V_1 * V_3 )
{
F_5 ( & V_3 -> V_4 ) ;
free ( V_3 -> V_6 ) ;
free ( V_3 ) ;
}
int F_6 ( struct V_1 * V_3 , const char * V_6 )
{
int V_7 ;
if ( V_3 -> V_6 )
free ( V_3 -> V_6 ) ;
V_3 -> V_6 = F_7 ( V_6 ) ;
V_7 = V_3 -> V_6 == NULL ? - V_8 : 0 ;
if ( ! V_7 ) {
V_3 -> V_9 = true ;
}
return V_7 ;
}
int F_8 ( struct V_1 * V_3 )
{
if ( ! V_3 -> V_10 ) {
if ( ! V_3 -> V_6 )
return 0 ;
V_3 -> V_10 = strlen ( V_3 -> V_6 ) ;
}
return V_3 -> V_10 ;
}
T_2 F_9 ( struct V_1 * V_1 , T_3 * V_11 )
{
return fprintf ( V_11 , L_2 , V_1 -> V_2 , V_1 -> V_6 ) +
F_10 ( & V_1 -> V_4 , V_12 , V_11 ) ;
}
void F_11 ( struct V_1 * V_3 , struct V_13 * V_13 )
{
F_12 ( & V_3 -> V_4 , V_13 , V_12 , V_14 ) ;
F_13 ( & V_3 -> V_4 , V_13 ) ;
}
int F_14 ( struct V_1 * V_3 , struct V_1 * V_15 )
{
int V_16 ;
if ( V_15 -> V_9 ) {
if ( V_3 -> V_6 )
free ( V_3 -> V_6 ) ;
V_3 -> V_6 = F_7 ( V_15 -> V_6 ) ;
if ( ! V_3 -> V_6 )
return - V_8 ;
V_3 -> V_9 = true ;
}
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 )
if ( F_15 ( & V_3 -> V_4 , & V_15 -> V_4 , V_16 ) < 0 )
return - V_8 ;
V_3 -> V_5 = V_15 -> V_2 ;
return 0 ;
}
