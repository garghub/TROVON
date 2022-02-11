bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_5 ) )
return false ;
if ( F_4 ( V_2 -> V_6 , V_7 ) >= V_8 ) {
F_5 ( V_5 ) ;
return false ;
}
if ( V_3 )
F_5 ( V_5 ) ;
return true ;
}
void F_6 ( struct V_4 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_10 * V_11 = V_2 -> V_4 . V_11 ;
if ( F_8 ( ! F_3 ( & V_2 -> V_4 ) ) )
return;
F_5 ( & V_2 -> V_4 ) ;
if ( F_9 ( & V_2 -> V_4 ) ) {
F_10 ( 1 ) ;
return;
}
if ( F_11 ( F_12 ( V_2 -> V_6 ) ) )
return;
if ( ! V_11 -> V_12 )
return;
F_13 ( & V_2 -> V_13 ) ;
if ( F_4 ( V_2 -> V_6 , V_7 ) < V_8 )
F_14 ( & V_2 -> V_4 , V_2 -> V_6 , false ) ;
F_15 ( V_2 -> V_6 ) ;
}
void F_16 ( struct V_4 * V_9 )
{
bool V_14 ;
V_9 = F_2 ( F_7 ( V_9 ) ) ;
if ( F_8 ( ! F_3 ( V_9 ) ) )
return;
if ( F_11 ( F_17 ( V_9 ) ) )
return;
V_14 = F_18 ( V_9 ) ;
if ( ! V_14 )
V_9 -> V_11 -> V_15 ( V_9 ) ;
F_6 ( V_9 ) ;
if ( ! V_14 )
V_9 -> V_11 -> V_16 ( V_9 ) ;
}
