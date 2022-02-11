void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 () ;
F_3 ( & V_2 -> V_3 , 0 , 0 , V_4 ) ;
F_4 ( V_2 , V_5 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_7 = V_5 ( V_2 ) ;
if ( V_7 == 1 )
F_3 ( & V_2 -> V_3 , 0 , 1 , V_4 ) ;
return V_7 ;
}
void T_1 F_6 ( struct V_1 * V_2 )
{
F_2 () ;
F_7 ( & V_2 -> V_3 , 0 , 0 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_8 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_7 = V_8 ( V_2 ) ;
if ( V_7 == 1 ) {
F_7 ( & V_2 -> V_3 , 0 , 1 , V_4 ) ;
F_8 ( V_2 ) ;
}
return V_7 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_3 , 1 , V_4 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_3 , 1 , V_4 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , int V_10 )
{
F_2 () ;
F_3 ( & V_2 -> V_3 , V_10 , 0 , V_4 ) ;
F_4 ( V_2 , V_5 , V_6 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_2 () ;
F_20 ( & V_2 -> V_3 , 0 , 0 , V_12 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_8 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_2 () ;
V_6 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_10 )
{
F_2 () ;
F_7 ( & V_2 -> V_3 , V_10 , 0 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_8 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
