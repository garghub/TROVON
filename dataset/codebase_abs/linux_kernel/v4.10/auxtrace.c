static
struct V_1 * F_1 ( struct V_2 * V_3 ,
int * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 ;
struct V_8 * V_9 ;
bool V_10 = false ;
bool V_11 = false ;
V_6 = F_2 ( V_12 ) ;
V_7 = F_2 ( V_13 ) ;
if ( V_3 ) {
F_3 (evlist, evsel) {
if ( V_6 &&
V_9 -> V_14 . type == V_6 -> type )
V_10 = true ;
if ( V_7 &&
V_9 -> V_14 . type == V_7 -> type )
V_11 = true ;
}
}
if ( V_10 && V_11 ) {
F_4 ( L_1 ) ;
* V_4 = - V_15 ;
return NULL ;
}
if ( V_10 )
return F_5 ( V_4 ) ;
if ( V_11 )
return F_6 ( V_4 ) ;
return NULL ;
}
struct V_1 * F_7 ( struct V_2 * V_3 ,
int * V_4 )
{
char V_16 [ 64 ] ;
int V_17 ;
* V_4 = 0 ;
V_17 = F_8 ( V_16 , sizeof( V_16 ) ) ;
if ( V_17 ) {
* V_4 = V_17 ;
return NULL ;
}
if ( ! strncmp ( V_16 , L_2 , 13 ) )
return F_1 ( V_3 , V_4 ) ;
return NULL ;
}
