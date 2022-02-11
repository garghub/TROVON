static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 , V_4 ) ;
F_3 ( & V_2 -> V_5 , L_1 , V_4 ) ;
V_6 . V_5 = & V_2 -> V_5 ;
F_3 ( & V_2 -> V_5 , L_2 ,
V_4 , V_6 . V_7 ) ;
F_4 ( V_2 , & V_6 ) ;
F_5 ( & V_6 , NULL ) ;
F_3 ( & V_2 -> V_5 , L_3 ,
V_4 , V_6 . V_7 , V_6 . V_8 ) ;
F_3 ( & V_2 -> V_5 , L_4 ,
V_4 , V_6 . V_7 , V_6 . V_9 [ 0 ] . V_7 ) ;
F_3 ( & V_2 -> V_5 , L_5 ,
V_4 , V_6 . V_7 ,
V_6 . V_9 [ 0 ] . V_10 ) ;
V_3 = F_6 ( & V_6 ) ;
if ( V_3 )
F_7 ( & V_2 -> V_5 ,
L_6 ,
V_3 ) ;
return V_3 ;
}
static int T_2 F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_6 = F_9 ( V_2 ) ;
F_2 ( L_1 , V_4 ) ;
F_10 ( V_6 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
