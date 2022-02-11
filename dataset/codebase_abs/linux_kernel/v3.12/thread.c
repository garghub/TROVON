struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( * V_4 ) ) ;
if ( V_4 != NULL ) {
F_3 ( & V_4 -> V_5 ) ;
V_4 -> V_6 = V_2 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_7 = - 1 ;
V_4 -> V_8 = malloc ( 32 ) ;
if ( V_4 -> V_8 )
snprintf ( V_4 -> V_8 , 32 , L_1 , V_4 -> V_3 ) ;
}
return V_4 ;
}
void F_4 ( struct V_1 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
free ( V_4 -> V_8 ) ;
free ( V_4 ) ;
}
int F_6 ( struct V_1 * V_4 , const char * V_8 )
{
int V_9 ;
if ( V_4 -> V_8 )
free ( V_4 -> V_8 ) ;
V_4 -> V_8 = F_7 ( V_8 ) ;
V_9 = V_4 -> V_8 == NULL ? - V_10 : 0 ;
if ( ! V_9 ) {
V_4 -> V_11 = true ;
}
return V_9 ;
}
int F_8 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_12 ) {
if ( ! V_4 -> V_8 )
return 0 ;
V_4 -> V_12 = strlen ( V_4 -> V_8 ) ;
}
return V_4 -> V_12 ;
}
T_2 F_9 ( struct V_1 * V_1 , T_3 * V_13 )
{
return fprintf ( V_13 , L_2 , V_1 -> V_3 , V_1 -> V_8 ) +
F_10 ( & V_1 -> V_5 , V_14 , V_13 ) ;
}
void F_11 ( struct V_1 * V_4 , struct V_15 * V_15 )
{
F_12 ( & V_4 -> V_5 , V_15 , V_14 , V_16 ) ;
F_13 ( & V_4 -> V_5 , V_15 ) ;
}
int F_14 ( struct V_1 * V_4 , struct V_1 * V_17 )
{
int V_18 ;
if ( V_17 -> V_11 ) {
if ( V_4 -> V_8 )
free ( V_4 -> V_8 ) ;
V_4 -> V_8 = F_7 ( V_17 -> V_8 ) ;
if ( ! V_4 -> V_8 )
return - V_10 ;
V_4 -> V_11 = true ;
}
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
if ( F_15 ( & V_4 -> V_5 , & V_17 -> V_5 , V_18 ) < 0 )
return - V_10 ;
V_4 -> V_7 = V_17 -> V_3 ;
return 0 ;
}
