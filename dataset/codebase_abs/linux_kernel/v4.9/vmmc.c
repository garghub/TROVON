unsigned int * F_1 ( void )
{
if ( ! V_1 )
F_2 ( L_1 ) ;
return V_1 ;
}
static int F_3 ( struct V_2 * V_3 )
{
#define F_4 (1 << 20)
int V_4 ;
T_1 V_5 ;
V_1 =
( void * ) F_5 ( F_6 ( NULL , F_4 ,
& V_5 , V_6 ) ) ;
V_4 = F_7 ( V_3 -> V_7 . V_8 ) ;
while ( V_4 > 0 ) {
enum V_9 V_10 ;
int V_11 = F_8 ( V_3 -> V_7 . V_8 ,
-- V_4 , & V_10 ) ;
if ( F_9 ( V_11 , L_2 ) )
continue;
F_10 ( & V_3 -> V_7 , L_3 , V_11 ) ;
F_11 ( V_11 ,
( V_10 & V_12 ) ? ( 0 ) : ( 1 ) ) ;
}
F_10 ( & V_3 -> V_7 , L_4 , F_4 >> 20 , V_1 ) ;
return 0 ;
}
