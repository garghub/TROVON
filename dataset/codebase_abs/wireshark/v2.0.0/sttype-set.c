static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( V_3 * ) V_1 ) ;
}
void
F_3 ( T_3 * V_4 )
{
F_4 ( V_4 , F_1 , NULL ) ;
F_5 ( V_4 ) ;
}
void
F_6 ( V_3 * V_5 , V_3 * V_6 , V_3 * V_7 )
{
T_3 * V_8 = ( T_3 * ) F_7 ( V_5 ) ;
while ( V_8 ) {
if ( V_8 -> V_1 == V_6 ) {
V_8 -> V_1 = V_7 ;
break;
}
V_8 = F_8 ( V_8 ) ;
}
}
void
F_9 ( void )
{
static T_4 V_9 = {
V_10 ,
L_1 ,
NULL ,
NULL ,
NULL
} ;
F_10 ( & V_9 ) ;
}
