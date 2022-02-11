void F_1 ( void )
{
if ( V_1 ) {
fclose ( V_1 ) ;
V_1 = NULL ;
V_2 = FALSE ;
F_2 ( L_1 ,
V_3 ) ;
}
}
void F_3 ( char * V_4 )
{
F_1 () ;
V_1 = fopen ( V_4 , L_2 ) ;
if ( ! V_1 ) {
F_2 ( L_3 , V_4 ) ;
return;
}
F_2 ( L_4 , V_4 ) ;
strncpy ( V_3 , V_4 ,
sizeof( V_3 ) ) ;
V_2 = TRUE ;
}
T_1 F_4 ( struct V_5 * V_6 )
{
T_1 V_7 ;
struct V_5 * V_8 ;
struct V_9 * V_10 ;
V_8 = V_6 ;
while ( V_8 ) {
V_10 = V_8 -> V_10 ;
V_7 = F_5 ( V_10 ) ;
if ( F_6 ( V_7 ) ) {
if ( V_7 == V_11 ) {
F_2
( L_5 ,
V_10 -> V_12 ) ;
} else {
F_2 ( L_6 ,
F_7 ( V_7 ) ) ;
}
return ( V_7 ) ;
}
F_2
( L_7 ,
V_10 -> V_12 ) ;
V_8 = V_8 -> V_13 ;
}
return ( V_14 ) ;
}
