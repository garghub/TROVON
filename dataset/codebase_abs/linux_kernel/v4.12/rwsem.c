void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 () ;
F_3 ( & V_2 -> V_3 , 0 , 0 , V_4 ) ;
F_4 ( V_2 , V_5 , V_6 ) ;
F_5 ( V_2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_7 = V_5 ( V_2 ) ;
if ( V_7 == 1 ) {
F_3 ( & V_2 -> V_3 , 0 , 1 , V_4 ) ;
F_5 ( V_2 ) ;
}
return V_7 ;
}
void T_1 F_7 ( struct V_1 * V_2 )
{
F_2 () ;
F_8 ( & V_2 -> V_3 , 0 , 0 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_9 ( V_2 ) ;
}
int T_1 F_10 ( struct V_1 * V_2 )
{
F_2 () ;
F_8 ( & V_2 -> V_3 , 0 , 0 , V_4 ) ;
if ( F_11 ( V_2 , V_8 , V_10 ) ) {
F_12 ( & V_2 -> V_3 , 1 , V_4 ) ;
return - V_11 ;
}
F_9 ( V_2 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_7 = V_8 ( V_2 ) ;
if ( V_7 == 1 ) {
F_8 ( & V_2 -> V_3 , 0 , 1 , V_4 ) ;
F_9 ( V_2 ) ;
}
return V_7 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_3 , 1 , V_4 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_3 , 1 , V_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_3 , V_4 ) ;
F_5 ( V_2 ) ;
F_21 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_12 )
{
F_2 () ;
F_3 ( & V_2 -> V_3 , V_12 , 0 , V_4 ) ;
F_4 ( V_2 , V_5 , V_6 ) ;
F_5 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_2 () ;
F_24 ( & V_2 -> V_3 , 0 , 0 , V_14 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_9 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_2 () ;
V_6 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_12 )
{
F_2 () ;
F_8 ( & V_2 -> V_3 , V_12 , 0 , V_4 ) ;
F_4 ( V_2 , V_8 , V_9 ) ;
F_9 ( V_2 ) ;
}
int T_1 F_27 ( struct V_1 * V_2 , int V_12 )
{
F_2 () ;
F_8 ( & V_2 -> V_3 , V_12 , 0 , V_4 ) ;
if ( F_11 ( V_2 , V_8 , V_10 ) ) {
F_12 ( & V_2 -> V_3 , 1 , V_4 ) ;
return - V_11 ;
}
F_9 ( V_2 ) ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
}
