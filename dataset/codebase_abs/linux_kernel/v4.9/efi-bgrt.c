void T_1 F_1 ( void )
{
T_2 V_1 ;
void * V_2 ;
struct V_3 V_3 ;
if ( V_4 )
return;
V_1 = F_2 ( L_1 , 0 ,
(struct V_5 * * ) & V_6 ) ;
if ( F_3 ( V_1 ) )
return;
if ( V_6 -> V_7 . V_8 < sizeof( * V_6 ) ) {
F_4 ( L_2 ,
V_6 -> V_7 . V_8 , sizeof( * V_6 ) ) ;
return;
}
if ( V_6 -> V_9 != 1 ) {
F_4 ( L_3 ,
V_6 -> V_9 ) ;
return;
}
if ( V_6 -> V_1 & 0xfe ) {
F_4 ( L_4 ,
V_6 -> V_1 ) ;
return;
}
if ( V_6 -> V_10 != 0 ) {
F_4 ( L_5 ,
V_6 -> V_10 ) ;
return;
}
if ( ! V_6 -> V_11 ) {
F_4 ( L_6 ) ;
return;
}
V_2 = F_5 ( V_6 -> V_11 , sizeof( V_3 ) , V_12 ) ;
if ( ! V_2 ) {
F_4 ( L_7 ) ;
return;
}
memcpy ( & V_3 , V_2 , sizeof( V_3 ) ) ;
F_6 ( V_2 ) ;
if ( V_3 . V_13 != 0x4d42 ) {
F_4 ( L_8 ,
V_3 . V_13 ) ;
return;
}
V_14 = V_3 . V_15 ;
V_16 = F_5 ( V_6 -> V_11 , V_3 . V_15 , V_12 ) ;
if ( ! V_16 ) {
F_4 ( L_9 ) ;
V_16 = NULL ;
return;
}
F_7 ( V_6 -> V_11 , V_14 ) ;
}
