int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_6 , & V_2 -> V_4 -> V_7 ) ;
V_2 -> V_8 = V_9 ;
if ( V_4 -> V_10 && V_4 -> V_10 -> V_11 )
return F_4 ( V_2 ) ;
V_2 -> V_12 = NULL ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
if ( F_6 ( V_13 , & V_2 -> V_4 -> V_7 ) )
F_7 ( V_2 -> V_4 -> V_8 , & V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
F_9 ( & V_2 -> V_5 , & V_2 -> V_4 -> V_15 ) ;
F_10 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
}
int F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_12 ( V_17 ) ;
struct V_1 * V_2 = F_13 ( sizeof( * V_2 ) , V_18 ) ;
V_17 -> V_19 = V_2 ;
if ( V_2 == NULL )
return - V_20 ;
F_1 ( V_2 , V_4 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_8 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
F_15 ( & V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
if ( F_6 ( V_13 , & V_2 -> V_4 -> V_7 ) )
F_16 ( V_2 -> V_4 -> V_8 , V_2 -> V_8 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == NULL )
return;
V_2 -> V_4 = NULL ;
F_18 ( V_2 ) ;
}
int F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
if ( V_2 ) {
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_20 ( V_2 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
int V_21 ;
if ( V_2 == NULL || V_2 -> V_4 == NULL )
return 0 ;
F_8 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
V_21 = F_22 ( & V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_4 -> V_14 , V_7 ) ;
return V_21 ;
}
