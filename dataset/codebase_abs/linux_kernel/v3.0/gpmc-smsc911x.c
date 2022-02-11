void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
V_7 = V_2 ;
if ( F_2 ( V_7 -> V_8 , V_9 , & V_5 ) < 0 ) {
F_3 ( L_1 ) ;
return;
}
V_10 [ 0 ] . V_11 = V_5 + 0x0 ;
V_10 [ 0 ] . V_12 = V_5 + 0xff ;
if ( F_4 ( V_7 -> V_13 , V_14 , L_2 ) ) {
F_3 ( L_3 , V_7 -> V_13 ) ;
goto V_15;
}
V_10 [ 1 ] . V_11 = F_5 ( V_7 -> V_13 ) ;
if ( F_6 ( V_7 -> V_16 ) ) {
V_6 = F_4 ( V_7 -> V_16 ,
V_17 , L_4 ) ;
if ( V_6 ) {
F_3 ( L_5 ,
V_7 -> V_16 ) ;
goto V_18;
}
F_7 ( V_7 -> V_16 , 0 ) ;
F_8 ( 100 ) ;
F_7 ( V_7 -> V_16 , 1 ) ;
}
if ( V_7 -> V_19 )
V_20 . V_19 = V_7 -> V_19 ;
V_4 = F_9 ( NULL , L_6 , V_7 -> V_21 ,
V_10 , F_10 ( V_10 ) ,
& V_20 , sizeof( V_20 ) ) ;
if ( ! V_4 ) {
F_3 ( L_7 ) ;
F_11 ( V_7 -> V_16 ) ;
goto V_18;
}
return;
V_18:
F_11 ( V_7 -> V_13 ) ;
V_15:
F_12 ( V_7 -> V_8 ) ;
F_3 ( L_8 ) ;
}
