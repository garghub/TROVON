static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned short V_6 ;
int V_7 ;
F_2 ( V_2 , V_8 , & V_5 ) ;
if ( ! ( V_5 & ( 1 << 31 ) ) ) {
F_3 ( & V_2 -> V_2 , L_1 ) ;
return - V_9 ;
}
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_2 ) ;
return - V_9 ;
}
V_10 . V_11 = V_6 ;
V_10 . V_12 = V_6 + V_13 - 1 ;
F_2 ( V_2 , V_14 , & V_5 ) ;
if ( ! ( V_5 & ( 1 << 31 ) ) ) {
F_3 ( & V_2 -> V_2 , L_3 ) ;
return - V_9 ;
}
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_4 ) ;
return - V_9 ;
}
V_15 . V_11 = V_6 ;
V_15 . V_12 = V_6 + V_16 - 1 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_17 ) ; V_7 ++ )
V_17 [ V_7 ] . V_4 = V_4 -> V_18 ;
return F_5 ( & V_2 -> V_2 , 0 ,
V_17 , F_4 ( V_17 ) , NULL , 0 ) ;
}
static void T_2 F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_2 ) ;
}
static int T_3 F_8 ( void )
{
return F_9 ( & V_19 ) ;
}
static void T_4 F_10 ( void )
{
F_11 ( & V_19 ) ;
}
