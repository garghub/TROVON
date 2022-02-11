void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_4 -> V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( V_7 , & V_2 -> V_4 -> V_8 ) ;
F_3 ( F_4 ( V_9 ) , V_4 -> V_10 ) ;
F_3 ( F_4 ( V_11 ) , V_4 -> V_10 ) ;
V_2 -> V_12 = V_13 ;
F_5 ( & V_2 -> V_14 ) ;
F_2 ( & V_2 -> V_15 ) ;
F_2 ( & V_2 -> V_16 ) ;
V_2 -> V_17 = - 1 ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_7 ( V_2 -> V_4 -> V_12 , & V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
F_9 ( & V_2 -> V_6 , & V_2 -> V_4 -> V_19 ) ;
F_10 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
}
int F_11 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_12 ( V_21 ) ;
struct V_1 * V_2 = F_13 ( sizeof( * V_2 ) , V_22 ) ;
V_21 -> V_23 = V_2 ;
if ( V_2 == NULL )
return - V_24 ;
F_1 ( V_2 , V_4 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_8 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
F_15 ( & V_2 -> V_6 ) ;
F_10 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
F_16 ( V_2 -> V_4 -> V_12 , V_2 -> V_12 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == NULL )
return;
F_18 ( V_2 ) ;
V_2 -> V_4 = NULL ;
}
int F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( V_2 ) {
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_20 ( V_2 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
int V_25 ;
if ( V_2 == NULL || V_2 -> V_4 == NULL )
return 0 ;
F_8 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
V_25 = F_22 ( & V_2 -> V_6 ) ;
F_10 ( & V_2 -> V_4 -> V_18 , V_8 ) ;
return V_25 ;
}
