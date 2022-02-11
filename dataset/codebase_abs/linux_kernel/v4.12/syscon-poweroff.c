static void F_1 ( void )
{
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
F_3 ( 1000 ) ;
F_4 ( L_1 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
char V_7 [ V_8 ] ;
int V_9 , V_10 ;
V_1 = F_6 ( V_6 -> V_11 . V_12 , L_2 ) ;
if ( F_7 ( V_1 ) ) {
F_8 ( & V_6 -> V_11 , L_3 ) ;
return F_9 ( V_1 ) ;
}
if ( F_10 ( V_6 -> V_11 . V_12 , L_4 , & V_2 ) ) {
F_8 ( & V_6 -> V_11 , L_5 ) ;
return - V_13 ;
}
V_10 = F_10 ( V_6 -> V_11 . V_12 , L_6 , & V_4 ) ;
V_9 = F_10 ( V_6 -> V_11 . V_12 , L_7 , & V_3 ) ;
if ( V_10 && V_9 ) {
F_8 ( & V_6 -> V_11 , L_8 ) ;
return - V_13 ;
}
if ( V_10 ) {
V_4 = V_3 ;
V_3 = 0xFFFFFFFF ;
} else if ( V_9 ) {
V_3 = 0xFFFFFFFF ;
}
if ( V_14 ) {
F_11 ( ( V_15 ) V_14 , V_7 ) ;
F_8 ( & V_6 -> V_11 ,
L_9 ,
V_14 , V_7 ) ;
return - V_16 ;
}
V_14 = F_1 ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
if ( V_14 == F_1 )
V_14 = NULL ;
return 0 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_17 ) ;
}
