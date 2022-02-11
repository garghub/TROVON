void F_1 ( void )
{
T_1 V_1 ;
void T_2 * V_2 ;
bool V_3 = false ;
struct V_4 V_4 ;
if ( V_5 )
return;
V_1 = F_2 ( L_1 , 0 ,
(struct V_6 * * ) & V_7 ) ;
if ( F_3 ( V_1 ) )
return;
if ( V_7 -> V_8 != 1 )
return;
if ( V_7 -> V_9 != 0 || ! V_7 -> V_10 )
return;
V_2 = F_4 ( V_7 -> V_10 ) ;
if ( ! V_2 ) {
V_2 = F_5 ( V_7 -> V_10 , sizeof( V_4 ) ) ;
V_3 = true ;
if ( ! V_2 )
return;
}
F_6 ( & V_4 , V_2 , sizeof( V_4 ) ) ;
if ( V_3 )
F_7 ( V_2 ) ;
V_11 = V_4 . V_12 ;
V_13 = F_8 ( V_11 , V_14 ) ;
if ( ! V_13 )
return;
if ( V_3 ) {
V_2 = F_5 ( V_7 -> V_10 , V_4 . V_12 ) ;
if ( ! V_2 ) {
F_9 ( V_13 ) ;
V_13 = NULL ;
return;
}
}
F_6 ( V_13 , V_2 , V_11 ) ;
if ( V_3 )
F_7 ( V_2 ) ;
}
