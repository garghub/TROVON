bool F_1 ( void )
{
struct V_1 * V_2 = V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_1 * V_6 , * V_7 ;
bool V_8 ;
if ( F_2 ( & V_2 -> signal -> V_9 ) != 1 )
return false ;
if ( F_2 ( & V_5 -> V_10 ) == 1 )
return true ;
V_8 = false ;
F_3 () ;
F_4 (p) {
if ( F_5 ( V_6 -> V_11 & V_12 ) )
continue;
if ( F_5 ( V_6 == V_2 -> V_13 ) )
continue;
V_7 = V_6 ;
do {
if ( F_5 ( V_7 -> V_5 == V_5 ) )
goto V_14;
if ( F_6 ( V_7 -> V_5 ) )
break;
F_7 () ;
} while_each_thread(p, t) ;
}
