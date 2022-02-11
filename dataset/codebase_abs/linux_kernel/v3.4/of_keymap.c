struct V_1 *
F_1 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
T_1 * V_6 ;
int V_7 , V_8 ;
const T_2 * V_9 ;
if ( ! V_3 )
return NULL ;
if ( ! V_4 )
V_4 = L_1 ;
V_9 = F_2 ( V_3 , V_4 , & V_7 ) ;
if ( ! V_9 )
return NULL ;
if ( V_7 % sizeof( T_1 ) ) {
F_3 ( L_2 ,
V_4 , V_3 -> V_10 ) ;
return NULL ;
}
V_5 = F_4 ( sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_6 = V_6 = F_4 ( V_7 , V_11 ) ;
if ( ! V_5 -> V_6 ) {
F_5 ( V_5 ) ;
return NULL ;
}
V_5 -> V_12 = V_7 / sizeof( T_1 ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_12 ; V_8 ++ ) {
T_1 V_13 = F_6 ( V_9 + V_8 ) ;
int V_14 , V_15 , V_16 ;
V_15 = ( V_13 >> 24 ) & 0xff ;
V_16 = ( V_13 >> 16 ) & 0xff ;
V_14 = V_13 & 0xffff ;
V_6 [ V_8 ] = F_7 ( V_15 , V_16 , V_14 ) ;
}
return V_5 ;
}
void F_8 ( const struct V_1 * V_5 )
{
if ( V_5 ) {
F_5 ( V_5 -> V_6 ) ;
F_5 ( V_5 ) ;
}
}
