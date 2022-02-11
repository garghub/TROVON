void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( ! F_3 () )
return;
if ( V_4 && ( V_4 -> V_6 & V_7 ) )
return;
V_5 += F_4 ( & V_2 -> V_8 , & V_9 ) ;
V_5 += F_4 ( & V_2 -> V_8 , & V_10 ) ;
V_5 += F_4 ( & V_2 -> V_8 , & V_11 ) ;
if ( V_5 )
F_5 ( V_12 L_1 ) ;
else if ( V_4 )
V_4 -> V_6 |= V_7 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_8 . V_13 . V_14 ) {
if ( V_4 )
V_4 -> V_6 &= ~ V_7 ;
return;
}
F_7 ( & V_2 -> V_8 , & V_9 ) ;
F_7 ( & V_2 -> V_8 , & V_10 ) ;
F_7 ( & V_2 -> V_8 , & V_11 ) ;
if ( V_4 )
V_4 -> V_6 &= ~ V_7 ;
}
