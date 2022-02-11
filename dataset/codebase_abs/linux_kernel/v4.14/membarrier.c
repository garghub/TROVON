static void F_1 ( void * V_1 )
{
F_2 () ;
}
static int F_3 ( void )
{
int V_2 ;
bool V_3 = false ;
T_1 V_4 ;
if ( ! ( F_4 ( & V_5 -> V_6 -> V_7 )
& V_8 ) )
return - V_9 ;
if ( F_5 () == 1 )
return 0 ;
F_2 () ;
if ( ! F_6 ( & V_4 , V_10 ) ) {
V_3 = true ;
}
F_7 () ;
F_8 (cpu) {
struct V_11 * V_12 ;
if ( V_2 == F_9 () )
continue;
F_10 () ;
V_12 = F_11 ( & F_12 ( V_2 ) -> V_13 ) ;
if ( V_12 && V_12 -> V_6 == V_5 -> V_6 ) {
if ( ! V_3 )
F_13 ( V_2 , V_4 ) ;
else
F_14 ( V_2 , F_1 , NULL , 1 ) ;
}
F_15 () ;
}
if ( ! V_3 ) {
F_16 ( V_4 , F_1 , NULL , 1 ) ;
F_17 ( V_4 ) ;
}
F_18 () ;
F_2 () ;
return 0 ;
}
static void F_19 ( void )
{
struct V_11 * V_12 = V_5 ;
struct V_14 * V_6 = V_12 -> V_6 ;
if ( F_4 ( & V_6 -> V_7 )
& V_8 )
return;
F_20 ( V_8 ,
& V_6 -> V_7 ) ;
}
