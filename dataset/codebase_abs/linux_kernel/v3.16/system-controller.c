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
void F_4 ( void * V_10 )
{
F_5 ( V_4 == NULL ) ;
F_5 ( V_5 -> V_11 == 0 ) ;
F_3 ( F_6 ( V_10 ) , V_4 +
V_5 -> V_11 ) ;
}
static int T_1 F_7 ( void )
{
const struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_15 = F_8 ( NULL , V_16 ,
& V_13 ) ;
if ( V_15 ) {
V_4 = F_9 ( V_15 , 0 ) ;
V_5 = (struct V_17 * ) V_13 -> V_18 ;
F_10 ( V_15 ) ;
}
return 0 ;
}
