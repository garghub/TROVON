void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
if ( F_2 ( V_2 -> V_7 , V_8 , & V_5 ) < 0 ) {
F_3 ( L_1 ) ;
return;
}
V_9 [ 0 ] . V_10 = V_5 + 0x0 ;
V_9 [ 0 ] . V_11 = V_5 + 0xff ;
if ( F_4 ( V_2 -> V_12 , V_13 , L_2 ) ) {
F_3 ( L_3 , V_2 -> V_12 ) ;
goto V_14;
}
V_9 [ 1 ] . V_10 = F_5 ( V_2 -> V_12 ) ;
if ( F_6 ( V_2 -> V_15 ) ) {
V_6 = F_4 ( V_2 -> V_15 ,
V_16 , L_4 ) ;
if ( V_6 ) {
F_3 ( L_5 ,
V_2 -> V_15 ) ;
goto V_17;
}
F_7 ( V_2 -> V_15 , 0 ) ;
F_8 ( 100 ) ;
F_7 ( V_2 -> V_15 , 1 ) ;
}
V_18 . V_19 = V_2 -> V_19 ? : V_20 ;
V_4 = F_9 ( NULL , L_6 , V_2 -> V_21 ,
V_9 , F_10 ( V_9 ) ,
& V_18 , sizeof( V_18 ) ) ;
if ( ! V_4 ) {
F_3 ( L_7 ) ;
F_11 ( V_2 -> V_15 ) ;
goto V_17;
}
return;
V_17:
F_11 ( V_2 -> V_12 ) ;
V_14:
F_12 ( V_2 -> V_7 ) ;
F_3 ( L_8 ) ;
}
