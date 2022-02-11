struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
F_3 ( & V_3 -> V_4 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = malloc ( 32 ) ;
if ( V_3 -> V_5 )
snprintf ( V_3 -> V_5 , 32 , L_1 , V_3 -> V_2 ) ;
}
return V_3 ;
}
void F_4 ( struct V_1 * V_3 )
{
F_5 ( & V_3 -> V_4 ) ;
free ( V_3 -> V_5 ) ;
free ( V_3 ) ;
}
int F_6 ( struct V_1 * V_3 , const char * V_5 )
{
int V_6 ;
if ( V_3 -> V_5 )
free ( V_3 -> V_5 ) ;
V_3 -> V_5 = F_7 ( V_5 ) ;
V_6 = V_3 -> V_5 == NULL ? - V_7 : 0 ;
if ( ! V_6 ) {
V_3 -> V_8 = true ;
}
return V_6 ;
}
int F_8 ( struct V_1 * V_3 )
{
if ( ! V_3 -> V_9 ) {
if ( ! V_3 -> V_5 )
return 0 ;
V_3 -> V_9 = strlen ( V_3 -> V_5 ) ;
}
return V_3 -> V_9 ;
}
static T_2 F_9 ( struct V_1 * V_3 , T_3 * V_10 )
{
return fprintf ( V_10 , L_2 , V_3 -> V_2 , V_3 -> V_5 ) +
F_10 ( & V_3 -> V_4 , V_11 , V_10 ) ;
}
void F_11 ( struct V_1 * V_3 , struct V_12 * V_12 )
{
F_12 ( & V_3 -> V_4 , V_12 , V_11 , V_13 ) ;
F_13 ( & V_3 -> V_4 , V_12 ) ;
}
int F_14 ( struct V_1 * V_3 , struct V_1 * V_14 )
{
int V_15 ;
if ( V_14 -> V_8 ) {
if ( V_3 -> V_5 )
free ( V_3 -> V_5 ) ;
V_3 -> V_5 = F_7 ( V_14 -> V_5 ) ;
if ( ! V_3 -> V_5 )
return - V_7 ;
V_3 -> V_8 = true ;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 )
if ( F_15 ( & V_3 -> V_4 , & V_14 -> V_4 , V_15 ) < 0 )
return - V_7 ;
return 0 ;
}
T_2 F_16 ( struct V_17 * V_17 , T_3 * V_10 )
{
T_2 V_18 = 0 ;
struct V_19 * V_20 ;
for ( V_20 = F_17 ( & V_17 -> V_21 ) ; V_20 ; V_20 = F_18 ( V_20 ) ) {
struct V_1 * V_22 = F_19 ( V_20 , struct V_1 , V_19 ) ;
V_18 += F_9 ( V_22 , V_10 ) ;
}
return V_18 ;
}
