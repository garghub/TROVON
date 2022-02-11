static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , F_3 ( * V_6 ) , V_7 . V_2 ) ;
struct V_8 * V_9 = V_4 ;
if ( ! strcmp ( V_9 -> V_10 , L_1 ) )
F_4 ( & V_6 -> V_11 , 1 , 0 , NULL , 0 ) ;
return V_12 ;
}
void
F_5 ( struct V_5 * V_6 )
{
#ifdef F_6
F_7 ( & V_6 -> V_7 . V_2 ) ;
#endif
}
void
F_8 ( struct V_5 * V_6 )
{
#ifdef F_6
V_6 -> V_7 . V_2 . V_13 = F_1 ;
F_9 ( & V_6 -> V_7 . V_2 ) ;
#endif
}
