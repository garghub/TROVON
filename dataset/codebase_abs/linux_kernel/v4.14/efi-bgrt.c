void T_1 F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
struct V_4 V_4 ;
struct V_5 * V_6 = & V_7 ;
if ( V_8 )
return;
if ( ! F_2 ( V_9 ) )
return;
if ( V_2 -> V_10 < sizeof( V_7 ) ) {
F_3 ( L_1 ,
V_2 -> V_10 , sizeof( V_7 ) ) ;
return;
}
* V_6 = * (struct V_5 * ) V_2 ;
if ( V_6 -> V_11 != 1 ) {
F_3 ( L_2 ,
V_6 -> V_11 ) ;
goto V_12;
}
if ( V_6 -> V_13 & 0xfe ) {
F_3 ( L_3 ,
V_6 -> V_13 ) ;
goto V_12;
}
if ( V_6 -> V_14 != 0 ) {
F_3 ( L_4 ,
V_6 -> V_14 ) ;
goto V_12;
}
if ( ! V_6 -> V_15 ) {
F_3 ( L_5 ) ;
goto V_12;
}
if ( F_4 ( V_6 -> V_15 ) != V_16 ) {
F_3 ( L_6 ) ;
goto V_12;
}
V_3 = F_5 ( V_6 -> V_15 , sizeof( V_4 ) ) ;
if ( ! V_3 ) {
F_3 ( L_7 ) ;
goto V_12;
}
memcpy ( & V_4 , V_3 , sizeof( V_4 ) ) ;
F_6 ( V_3 , sizeof( V_4 ) ) ;
if ( V_4 . V_17 != 0x4d42 ) {
F_3 ( L_8 ,
V_4 . V_17 ) ;
goto V_12;
}
V_18 = V_4 . V_19 ;
F_7 ( V_6 -> V_15 , V_18 ) ;
return;
V_12:
memset ( V_6 , 0 , sizeof( V_7 ) ) ;
}
