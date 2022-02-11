static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned short V_6 ;
int V_7 ;
int V_8 ;
F_2 ( V_2 , V_9 , & V_5 ) ;
if ( ! ( V_5 & ( 1 << 31 ) ) ) {
F_3 ( & V_2 -> V_2 , L_1 ) ;
return - V_10 ;
}
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_2 ) ;
return - V_10 ;
}
V_11 . V_12 = V_6 ;
V_11 . V_13 = V_6 + V_14 - 1 ;
F_2 ( V_2 , V_15 , & V_5 ) ;
if ( ! ( V_5 & ( 1 << 31 ) ) ) {
F_3 ( & V_2 -> V_2 , L_3 ) ;
return - V_10 ;
}
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_4 ) ;
return - V_10 ;
}
V_16 . V_12 = V_6 ;
if ( V_4 -> V_17 == V_18 )
V_16 . V_13 = V_6 + V_19 - 1 ;
else
V_16 . V_13 = V_6 + V_20 - 1 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_21 ) ; V_7 ++ )
V_21 [ V_7 ] . V_4 = V_4 -> V_17 ;
V_8 = F_5 ( & V_2 -> V_2 , 0 ,
V_21 , F_4 ( V_21 ) , NULL ,
0 , NULL ) ;
if ( V_8 )
goto V_22;
if ( V_4 -> V_17 == V_23
|| V_4 -> V_17 == V_18 ) {
F_2 ( V_2 , V_24 , & V_5 ) ;
if ( ! ( V_5 & ( 1 << 31 ) ) ) {
F_3 ( & V_2 -> V_2 , L_5 ) ;
V_8 = - V_10 ;
goto V_22;
}
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_6 ) ;
V_8 = - V_10 ;
goto V_22;
}
V_25 . V_12 = V_6 ;
V_25 . V_13 = V_6 + V_26 - 1 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_27 ) ; V_7 ++ )
V_27 [ V_7 ] . V_4 = V_4 -> V_17 ;
V_8 = F_5 ( & V_2 -> V_2 , 0 , V_27 ,
F_4 ( V_27 ) , NULL ,
0 , NULL ) ;
}
return V_8 ;
V_22:
F_6 ( & V_2 -> V_2 ) ;
return V_8 ;
}
static void T_2 F_7 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 ) ;
}
