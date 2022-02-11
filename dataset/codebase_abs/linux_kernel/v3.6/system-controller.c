void F_1 ( char V_1 , const char * V_2 )
{
if ( ! V_3 ) {
F_2 ( L_1 ) ;
} else {
F_3 ( V_4 -> V_5 ,
V_3 +
V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ,
V_3 +
V_4 -> V_8 ) ;
}
while ( 1 )
;
}
static int T_1 F_4 ( void )
{
struct V_9 * V_10 ;
V_10 = F_5 ( NULL , V_11 ) ;
if ( V_10 ) {
const struct V_12 * V_13 =
F_6 ( V_11 , V_10 ) ;
F_7 ( ! V_13 ) ;
V_3 = F_8 ( V_10 , 0 ) ;
V_4 = (struct V_14 * ) V_13 -> V_15 ;
}
return 0 ;
}
