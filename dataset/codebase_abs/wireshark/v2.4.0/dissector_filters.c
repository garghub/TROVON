void F_1 ( const char * V_1 , const char * V_2 ,
T_1 V_3 , T_2 V_4 ) {
T_3 * V_5 ;
V_5 = ( T_3 * ) F_2 ( sizeof( T_3 ) ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_6 = F_3 ( V_6 , V_5 ) ;
}
struct V_7 * F_4 ( const char * V_8 )
{
T_4 * V_9 = V_6 ;
T_3 * V_10 ;
while ( V_9 != NULL ) {
V_10 = ( T_3 * ) V_9 -> V_11 ;
if ( ! strcmp ( V_10 -> V_1 , V_8 ) )
return V_10 ;
V_9 = F_5 ( V_9 ) ;
}
return NULL ;
}
static void F_6 ( T_5 V_12 , T_5 T_6 V_13 )
{
F_7 ( V_12 ) ;
}
void F_8 ( void )
{
F_9 ( V_6 , F_6 , NULL ) ;
F_10 ( V_6 ) ;
}
T_7 * F_11 ( struct V_14 * V_15 )
{
const char * V_16 [] = { L_1 , L_2 , L_3 , L_4 , L_5 } ;
T_3 * V_17 ;
T_7 * V_10 ;
T_8 V_18 ;
for ( V_18 = 0 ; V_18 < F_12 ( V_16 ) ; V_18 ++ ) {
V_17 = F_4 ( V_16 [ V_18 ] ) ;
if ( V_17 && V_17 -> V_3 ( V_15 ) ) {
if ( ( V_10 = V_17 -> V_4 ( V_15 ) ) != NULL )
return V_10 ;
}
}
return NULL ;
}
