static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
if ( V_4 -> V_7 )
return F_2 ( V_2 , V_4 ) ;
V_4 -> V_8 = F_3 ( V_2 , V_9 ) ;
return true ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
T_1 V_10 ;
asm volatile("mrs %0, actlr_el1\n" : "=r" (actlr));
F_3 ( V_2 , V_9 ) = V_10 ;
}
static int T_2 F_5 ( void )
{
unsigned int V_11 ;
for ( V_11 = 1 ; V_11 < F_6 ( V_12 ) ; V_11 ++ )
F_7 ( F_8 ( & V_12 [ V_11 - 1 ] ,
& V_12 [ V_11 ] ) >= 0 ) ;
F_9 ( V_13 ,
& V_14 ) ;
F_9 ( V_15 ,
& V_14 ) ;
F_9 ( V_16 ,
& V_14 ) ;
F_9 ( V_17 ,
& V_14 ) ;
F_9 ( V_18 ,
& V_14 ) ;
F_9 ( V_19 ,
& V_14 ) ;
return 0 ;
}
