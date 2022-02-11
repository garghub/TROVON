void T_1 F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
struct V_4 V_4 ;
struct V_5 * V_6 = & V_7 ;
if ( V_8 )
return;
if ( V_2 -> V_9 < sizeof( V_7 ) ) {
F_2 ( L_1 ,
V_2 -> V_9 , sizeof( V_7 ) ) ;
return;
}
* V_6 = * (struct V_5 * ) V_2 ;
if ( V_6 -> V_10 != 1 ) {
F_2 ( L_2 ,
V_6 -> V_10 ) ;
goto V_11;
}
if ( V_6 -> V_12 & 0xfe ) {
F_2 ( L_3 ,
V_6 -> V_12 ) ;
goto V_11;
}
if ( V_6 -> V_13 != 0 ) {
F_2 ( L_4 ,
V_6 -> V_13 ) ;
goto V_11;
}
if ( ! V_6 -> V_14 ) {
F_2 ( L_5 ) ;
goto V_11;
}
V_3 = F_3 ( V_6 -> V_14 , sizeof( V_4 ) ) ;
if ( ! V_3 ) {
F_2 ( L_6 ) ;
goto V_11;
}
memcpy ( & V_4 , V_3 , sizeof( V_4 ) ) ;
F_4 ( V_3 , sizeof( V_4 ) ) ;
if ( V_4 . V_15 != 0x4d42 ) {
F_2 ( L_7 ,
V_4 . V_15 ) ;
goto V_11;
}
V_16 = V_4 . V_17 ;
F_5 ( V_6 -> V_14 , V_16 ) ;
return;
V_11:
memset ( V_6 , 0 , sizeof( V_7 ) ) ;
}
