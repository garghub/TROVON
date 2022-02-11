struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof *V_2 , V_3 ) ;
if ( ! V_2 )
goto V_4;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_9 ) ;
V_4:
return V_2 ;
}
static void F_6 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_5 , struct V_1 , V_5 ) ;
F_8 ( V_2 -> V_10 || ! F_9 ( & V_2 -> V_8 ) ) ;
F_10 ( V_2 ) ;
}
struct V_1 * F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_5 ) ;
return V_2 ;
}
int F_13 ( struct V_1 * V_2 )
{
return F_14 ( & V_2 -> V_5 , & F_6 ) ;
}
void F_15 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_16 ( & V_2 -> V_6 ) ;
V_12 -> V_2 = F_11 ( V_2 ) ;
F_17 ( & V_12 -> V_13 , & V_2 -> V_8 ) ;
V_2 -> V_10 ++ ;
F_18 ( & V_2 -> V_6 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_16 ( & V_2 -> V_6 ) ;
F_8 ( V_12 -> V_2 != V_2 ) ;
if ( ! F_9 ( & V_12 -> V_14 ) ) {
F_20 ( & V_12 -> V_14 ) ;
V_2 -> V_15 &= ~ V_16 ;
}
F_20 ( & V_12 -> V_13 ) ;
V_2 -> V_10 -- ;
F_18 ( & V_2 -> V_6 ) ;
F_13 ( V_2 ) ;
}
