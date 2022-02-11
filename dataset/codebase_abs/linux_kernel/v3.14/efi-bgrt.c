void T_1 F_1 ( void )
{
T_2 V_1 ;
void T_3 * V_2 ;
bool V_3 = false ;
struct V_4 V_4 ;
if ( V_5 )
return;
V_1 = F_2 ( L_1 , 0 ,
(struct V_6 * * ) & V_7 ) ;
if ( F_3 ( V_1 ) )
return;
if ( V_7 -> V_8 . V_9 < sizeof( * V_7 ) )
return;
if ( V_7 -> V_10 != 1 || V_7 -> V_1 != 1 )
return;
if ( V_7 -> V_11 != 0 || ! V_7 -> V_12 )
return;
V_2 = F_4 ( V_7 -> V_12 ) ;
if ( ! V_2 ) {
V_2 = F_5 ( V_7 -> V_12 ,
sizeof( V_4 ) ) ;
V_3 = true ;
if ( ! V_2 )
return;
}
F_6 ( & V_4 , V_2 , sizeof( V_4 ) ) ;
if ( V_3 )
F_7 ( V_2 , sizeof( V_4 ) ) ;
V_13 = V_4 . V_14 ;
V_15 = F_8 ( V_13 , V_16 ) ;
if ( ! V_15 )
return;
if ( V_3 ) {
V_2 = F_5 ( V_7 -> V_12 ,
V_4 . V_14 ) ;
if ( ! V_2 ) {
F_9 ( V_15 ) ;
V_15 = NULL ;
return;
}
}
F_6 ( V_15 , V_2 , V_13 ) ;
if ( V_3 )
F_7 ( V_2 , V_4 . V_14 ) ;
}
