static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! V_5 -> V_6 ) {
V_5 -> V_7 = ( void * ) V_2 -> V_8 ;
return 1 ;
} else {
-- V_5 -> V_6 ;
return 0 ;
}
}
void * F_2 ( unsigned int V_6 )
{
struct V_4 V_5 ;
struct V_1 V_2 ;
V_5 . V_6 = V_6 + 2 ;
V_5 . V_7 = NULL ;
V_2 . V_9 = ( unsigned long ) F_3 ( 0 ) ;
V_2 . V_8 = ( unsigned long ) F_2 ;
#ifdef F_4
V_2 . V_10 = V_11 -> V_12 ;
#endif
F_5 ( V_11 , & V_2 , F_1 , & V_5 ) ;
if ( ! V_5 . V_6 )
return V_5 . V_7 ;
else
return NULL ;
}
