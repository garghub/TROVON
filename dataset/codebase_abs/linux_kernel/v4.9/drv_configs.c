static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
bool V_5 = false ;
int V_6 = 0 ;
struct V_3 * V_7 ;
struct V_8 * V_9 = NULL ;
while ( ( V_9 = F_2 ( V_9 ) ) != NULL )
if ( V_9 -> type == V_2 -> V_10 . type ) {
V_5 = true ;
break;
}
F_3 (term, &evsel->config_terms, list) {
if ( V_7 -> type != V_11 )
continue;
if ( ! V_5 || ! V_9 -> V_12 ) {
V_6 = - V_13 ;
* V_4 = V_7 ;
break;
}
V_6 = V_9 -> V_12 ( V_7 ) ;
if ( V_6 ) {
* V_4 = V_7 ;
break;
}
}
return V_6 ;
}
int F_4 ( struct V_14 * V_15 ,
struct V_1 * * V_16 ,
struct V_3 * * V_4 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
F_5 (evlist, evsel) {
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 ) {
* V_16 = V_2 ;
break;
}
}
return V_6 ;
}
