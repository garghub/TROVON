static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
F_2 ( 0xdeadbeef , V_4 + V_5 ) ;
while ( 1 )
F_3 () ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 ;
V_4 = F_5 ( V_9 , 0 ) ;
if ( ! V_4 ) {
F_6 ( 1 , L_1 ) ;
return - V_12 ;
}
if ( F_7 ( V_9 , L_2 , & V_5 ) < 0 ) {
F_8 ( L_3 ) ;
return - V_13 ;
}
V_14 = F_1 ;
return 0 ;
}
