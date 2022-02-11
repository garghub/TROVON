int F_1 ( struct V_1 * V_2 ,
const char * V_3 , struct V_4 * V_5 )
{
V_2 -> V_6 = F_2 ( int ) ;
if ( F_3 ( ! V_2 -> V_6 ) )
return - V_7 ;
F_4 ( & V_2 -> V_8 , V_3 , V_5 ) ;
F_5 ( & V_2 -> V_9 , 0 ) ;
F_5 ( & V_2 -> V_10 , 0 ) ;
F_6 ( & V_2 -> V_11 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static bool F_9 ( struct V_1 * V_2 , unsigned int V_12 )
{
bool V_13 = false ;
F_10 () ;
if ( F_11 ( ! F_12 ( & V_2 -> V_9 ) ) ) {
F_13 ( * V_2 -> V_6 , V_12 ) ;
V_13 = true ;
}
F_14 () ;
return V_13 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 () ;
if ( F_11 ( F_9 ( V_2 , + 1 ) ) ) {
F_17 ( & V_2 -> V_8 . V_14 , 0 , 0 , V_15 ) ;
return;
}
F_18 ( & V_2 -> V_8 ) ;
F_19 ( & V_2 -> V_10 ) ;
F_20 ( & V_2 -> V_8 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_8 . V_14 , 1 , V_15 ) ;
if ( F_11 ( F_9 ( V_2 , - 1 ) ) )
return;
if ( F_23 ( & V_2 -> V_10 ) )
F_24 ( & V_2 -> V_11 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned int V_16 = 0 ;
int V_17 ;
F_26 (cpu) {
V_16 += F_27 ( * V_2 -> V_6 , V_17 ) ;
F_27 ( * V_2 -> V_6 , V_17 ) = 0 ;
}
return V_16 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_9 ) ;
F_29 () ;
F_30 ( & V_2 -> V_8 ) ;
F_31 ( F_25 ( V_2 ) , & V_2 -> V_10 ) ;
F_32 ( V_2 -> V_11 , ! F_12 ( & V_2 -> V_10 ) ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_8 ) ;
F_29 () ;
F_35 ( & V_2 -> V_9 ) ;
}
