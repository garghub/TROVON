static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static inline void F_2 ( struct V_1 * V_2 )
{
}
void T_1 F_3 ( struct V_1 * V_2 )
{
F_4 () ;
F_5 ( & V_2 -> V_5 , 0 , 0 , V_6 ) ;
F_6 ( V_2 , V_7 , V_8 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_9 = V_7 ( V_2 ) ;
if ( V_9 == 1 )
F_5 ( & V_2 -> V_5 , 0 , 1 , V_6 ) ;
return V_9 ;
}
void T_1 F_8 ( struct V_1 * V_2 )
{
F_4 () ;
F_9 ( & V_2 -> V_5 , 0 , 0 , V_6 ) ;
F_6 ( V_2 , V_10 , V_11 ) ;
F_1 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_9 = V_10 ( V_2 ) ;
if ( V_9 == 1 ) {
F_9 ( & V_2 -> V_5 , 0 , 1 , V_6 ) ;
F_1 ( V_2 ) ;
}
return V_9 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_5 , 1 , V_6 ) ;
F_13 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_5 , 1 , V_6 ) ;
F_2 ( V_2 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , int V_12 )
{
F_4 () ;
F_5 ( & V_2 -> V_5 , V_12 , 0 , V_6 ) ;
F_6 ( V_2 , V_7 , V_8 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_4 () ;
F_20 ( & V_2 -> V_5 , 0 , 0 , V_14 , V_6 ) ;
F_6 ( V_2 , V_10 , V_11 ) ;
F_1 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_4 () ;
V_8 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_12 )
{
F_4 () ;
F_9 ( & V_2 -> V_5 , V_12 , 0 , V_6 ) ;
F_6 ( V_2 , V_10 , V_11 ) ;
F_1 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
