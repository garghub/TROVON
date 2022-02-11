static void
F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
char * V_3 , * V_4 ;
V_2 = V_1 -> V_5 ;
if ( V_2 == 0 || V_1 -> V_1 [ V_2 - 1 ] != '\n' )
F_2 ( V_1 , L_1 ) ;
V_3 = V_1 -> V_1 ;
while ( * V_3 != '\0' ) {
V_4 = strchr ( V_3 , '\n' ) ;
if ( V_4 - V_3 > 80 ) {
V_4 = V_3 + 80 ;
while ( V_4 > V_3 && * V_4 != ' ' )
V_4 -- ;
if ( V_4 != V_3 )
* V_4 = '\n' ;
}
V_3 = V_4 + 1 ;
}
}
void
F_3 ( T_1 * V_1 , void (* F_4)( T_1 * ) ,
void (* F_5)( T_1 * ) )
{
if ( sizeof( V_1 ) == 4 )
F_2 ( V_1 , L_2 ) ;
else
F_2 ( V_1 , L_3 ) ;
if ( F_4 ) {
(* F_4)( V_1 ) ;
F_2 ( V_1 , L_4 ) ;
}
F_6 ( V_1 ) ;
if ( F_5 )
(* F_5)( V_1 ) ;
F_2 ( V_1 , L_5 ) ;
F_1 ( V_1 ) ;
}
void
F_7 ( T_1 * V_1 , void (* F_8)( T_1 * ) )
{
#ifndef F_9
T_3 * V_6 ;
#endif
F_2 ( V_1 , L_6 ) ;
F_10 ( V_1 ) ;
#ifndef F_9
if ( ( V_6 = getenv ( L_7 ) ) != NULL )
F_11 ( V_1 , L_8 , V_6 ) ;
else
F_2 ( V_1 , L_9 ) ;
#endif
if ( F_8 )
(* F_8)( V_1 ) ;
F_2 ( V_1 , L_5 ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_1 ( V_1 ) ;
}
