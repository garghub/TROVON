void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 ;
V_7 = V_2 ;
V_6 = F_2 ( & V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( L_1 , V_6 ) ;
return;
}
if ( F_4 ( V_7 -> V_9 , V_10 , & V_5 ) < 0 ) {
F_3 ( L_2 ) ;
return;
}
V_11 [ 0 ] . V_12 = V_5 + 0x0 ;
V_11 [ 0 ] . V_13 = V_5 + 0xff ;
if ( F_5 ( V_7 -> V_14 , V_15 , L_3 ) ) {
F_3 ( L_4 , V_7 -> V_14 ) ;
goto V_16;
}
V_11 [ 1 ] . V_12 = F_6 ( V_7 -> V_14 ) ;
if ( F_7 ( V_7 -> V_17 ) ) {
V_6 = F_5 ( V_7 -> V_17 ,
V_18 , L_5 ) ;
if ( V_6 ) {
F_3 ( L_6 ,
V_7 -> V_17 ) ;
goto V_19;
}
F_8 ( V_7 -> V_17 , 0 ) ;
F_9 ( 100 ) ;
F_8 ( V_7 -> V_17 , 1 ) ;
}
if ( V_7 -> V_20 )
V_21 . V_20 = V_7 -> V_20 ;
V_4 = F_10 ( NULL , L_7 , V_7 -> V_22 ,
V_11 , F_11 ( V_11 ) ,
& V_21 , sizeof( V_21 ) ) ;
if ( ! V_4 ) {
F_3 ( L_8 ) ;
F_12 ( V_7 -> V_17 ) ;
goto V_19;
}
return;
V_19:
F_12 ( V_7 -> V_14 ) ;
V_16:
F_13 ( V_7 -> V_9 ) ;
F_3 ( L_9 ) ;
}
