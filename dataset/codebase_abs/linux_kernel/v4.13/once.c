static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_4 ) ;
F_3 ( ! F_4 ( V_4 -> V_5 ) ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_6 * V_5 )
{
struct V_3 * V_2 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return;
F_9 ( & V_2 -> V_4 , F_1 ) ;
V_2 -> V_5 = V_5 ;
F_10 ( & V_2 -> V_4 ) ;
}
bool F_11 ( bool * V_8 , unsigned long * V_9 )
__acquires( T_1 )
{
F_12 ( & T_1 , * V_9 ) ;
if ( * V_8 ) {
F_13 ( & T_1 , * V_9 ) ;
F_14 ( T_1 ) ;
return false ;
}
return true ;
}
void F_15 ( bool * V_8 , struct V_6 * V_10 ,
unsigned long * V_9 )
__releases( T_1 )
{
* V_8 = true ;
F_13 ( & T_1 , * V_9 ) ;
F_7 ( V_10 ) ;
}
