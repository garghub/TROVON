void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( V_4 && ( V_4 -> V_6 & V_7 ) )
return;
V_5 += F_3 ( & V_2 -> V_8 , & V_9 ) ;
V_5 += F_3 ( & V_2 -> V_8 , & V_10 ) ;
V_5 += F_3 ( & V_2 -> V_8 , & V_11 ) ;
if ( V_5 )
F_4 ( V_12 L_1 ) ;
else if ( V_4 )
V_4 -> V_6 |= V_7 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_8 . V_13 . V_14 ) {
if ( V_4 )
V_4 -> V_6 &= ~ V_7 ;
return;
}
F_6 ( & V_2 -> V_8 , & V_9 ) ;
F_6 ( & V_2 -> V_8 , & V_10 ) ;
F_6 ( & V_2 -> V_8 , & V_11 ) ;
if ( V_4 )
V_4 -> V_6 &= ~ V_7 ;
}
