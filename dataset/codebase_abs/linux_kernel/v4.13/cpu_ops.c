static const struct V_1 * T_1 F_1 ( const char * V_2 )
{
const struct V_1 * * V_3 ;
V_3 = V_4 ? V_5 : V_6 ;
while ( * V_3 ) {
if ( ! strcmp ( V_2 , ( * V_3 ) -> V_2 ) )
return * V_3 ;
V_3 ++ ;
}
return NULL ;
}
static const char * T_1 F_2 ( int V_7 )
{
const char * V_8 ;
if ( V_4 ) {
struct V_9 * V_10 = F_3 ( V_7 , NULL ) ;
if ( ! V_10 ) {
if ( ! V_7 )
F_4 ( L_1 ) ;
return NULL ;
}
V_8 = F_5 ( V_10 , L_2 , NULL ) ;
if ( ! V_8 ) {
if ( V_7 != 0 )
F_4 ( L_3 ,
V_10 ) ;
}
} else {
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 ) {
if ( V_7 != 0 )
F_4 ( L_4 ) ;
}
}
return V_8 ;
}
int T_1 F_7 ( int V_7 )
{
const char * V_8 = F_2 ( V_7 ) ;
if ( ! V_8 )
return - V_11 ;
V_12 [ V_7 ] = F_1 ( V_8 ) ;
if ( ! V_12 [ V_7 ] ) {
F_8 ( L_5 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
