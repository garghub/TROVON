static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 , * V_7 = NULL ;
if ( ( V_3 = F_2 ( V_2 ) ) ) {
F_3 ( V_8 L_1 ,
F_4 ( V_2 ) ) ;
return V_3 ;
}
F_5 (pdev->bus, res, i)
if ( V_6 && ( V_6 -> V_9 & V_10 ) ) {
V_7 = V_6 ;
break;
}
if ( ! V_7 ) {
F_6 ( & V_2 -> V_11 , L_2 ) ;
return - 1 ;
}
V_12 . V_11 = & V_2 -> V_11 ;
V_12 . V_6 = V_7 ;
V_12 . V_13 = V_7 -> V_14 ;
V_12 . V_15 = V_16 ;
V_12 . V_17 = V_2 -> V_17 ;
F_7 ( V_12 . V_11 , & V_12 ) ;
if ( F_8 ( & V_12 ) ) {
F_3 ( V_8 L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_9 ( void )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
F_10 (dev)
if ( ( V_11 -> V_19 >> 8 ) == V_20 ) {
V_18 = F_1 ( V_11 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
