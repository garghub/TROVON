static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 , * V_7 = NULL ;
if ( ( V_3 = F_2 ( V_2 ) ) ) {
F_3 ( & V_2 -> V_8 , L_1 ) ;
return V_3 ;
}
F_4 (pdev->bus, res, i)
if ( V_6 && ( V_6 -> V_9 & V_10 ) ) {
V_7 = V_6 ;
break;
}
if ( ! V_7 ) {
F_3 ( & V_2 -> V_8 , L_2 ) ;
return - 1 ;
}
V_11 . V_8 = & V_2 -> V_8 ;
V_11 . V_6 = V_7 ;
V_11 . V_12 = V_7 -> V_13 ;
V_11 . V_14 = V_15 ;
V_11 . V_16 = V_2 -> V_16 ;
F_5 ( V_11 . V_8 , & V_11 ) ;
if ( F_6 ( & V_11 ) ) {
F_3 ( & V_2 -> V_8 , L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_7 ( void )
{
struct V_1 * V_8 = NULL ;
int V_17 ;
F_8 (dev)
if ( ( V_8 -> V_18 >> 8 ) == V_19 ) {
V_17 = F_1 ( V_8 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
