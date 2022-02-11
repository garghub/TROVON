static const struct V_1 * T_1 F_1 ( const char * V_2 )
{
const struct V_1 * * V_3 = V_4 ;
while ( * V_3 ) {
if ( ! strcmp ( V_2 , ( * V_3 ) -> V_2 ) )
return * V_3 ;
V_3 ++ ;
}
return NULL ;
}
static const char * T_1 F_2 ( int V_5 )
{
const char * V_6 ;
if ( V_7 ) {
struct V_8 * V_9 = F_3 ( V_5 , NULL ) ;
if ( ! V_9 ) {
if ( ! V_5 )
F_4 ( L_1 ) ;
return NULL ;
}
V_6 = F_5 ( V_9 , L_2 , NULL ) ;
if ( ! V_6 ) {
if ( V_5 != 0 )
F_4 ( L_3 ,
V_9 -> V_10 ) ;
}
} else {
V_6 = F_6 ( V_5 ) ;
if ( ! V_6 )
F_4 ( L_4 ) ;
}
return V_6 ;
}
int T_1 F_7 ( int V_5 )
{
const char * V_6 = F_2 ( V_5 ) ;
if ( ! V_6 )
return - V_11 ;
V_12 [ V_5 ] = F_1 ( V_6 ) ;
if ( ! V_12 [ V_5 ] ) {
F_8 ( L_5 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
