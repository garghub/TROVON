static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
struct V_3 * F_4 ( struct V_1 * V_5 , int V_6 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_7 ) ;
if ( V_4 ) {
F_6 ( & V_4 -> V_2 , L_1 , F_7 ( V_5 ) , V_6 ) ;
V_4 -> V_2 . V_5 = V_5 ;
V_4 -> V_2 . V_8 = & V_9 ;
V_4 -> V_2 . V_10 = F_1 ;
V_4 -> V_2 . V_11 = V_5 -> V_11 ;
}
return V_4 ;
}
int F_8 ( struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_9 ( V_4 -> V_13 . V_5 , & V_4 -> V_13 ) ;
if ( V_12 < 0 ) {
F_10 ( & V_4 -> V_2 , L_2 ,
& V_4 -> V_13 , V_12 ) ;
goto V_14;
}
V_12 = F_11 ( & V_4 -> V_2 ) ;
if ( V_12 < 0 )
goto V_15;
return 0 ;
V_15:
F_12 ( & V_4 -> V_13 ) ;
V_14:
return V_12 ;
}
void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_14 ( & V_4 -> V_2 ) ;
F_15 ( & V_4 -> V_2 ) ;
F_12 ( & V_4 -> V_13 ) ;
F_16 ( V_2 ) ;
}
