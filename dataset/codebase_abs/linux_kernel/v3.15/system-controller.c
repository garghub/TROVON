void F_1 ( enum V_1 V_2 , const char * V_3 )
{
if ( ! V_4 ) {
F_2 ( L_1 ) ;
} else {
F_3 ( V_5 -> V_6 ,
V_4 +
V_5 -> V_7 ) ;
F_3 ( V_5 -> V_8 ,
V_4 +
V_5 -> V_9 ) ;
}
while ( 1 )
;
}
static int T_1 F_4 ( void )
{
const struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_13 = F_5 ( NULL , V_14 ,
& V_11 ) ;
if ( V_13 ) {
V_4 = F_6 ( V_13 , 0 ) ;
V_5 = (struct V_15 * ) V_11 -> V_16 ;
F_7 ( V_13 ) ;
}
return 0 ;
}
