int F_1 ( struct V_1 * V_2 ,
const char * V_3 , struct V_4 * V_5 )
{
V_2 -> V_6 = F_2 ( int ) ;
if ( F_3 ( ! V_2 -> V_6 ) )
return - V_7 ;
F_4 ( & V_2 -> V_8 , V_3 , V_5 ) ;
F_5 ( & V_2 -> V_9 , V_10 ) ;
F_6 ( & V_2 -> V_11 , 0 ) ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return;
F_9 ( & V_2 -> V_9 ) ;
F_10 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static bool F_11 ( struct V_1 * V_2 , unsigned int V_13 )
{
bool V_14 ;
F_12 () ;
V_14 = F_13 ( & V_2 -> V_9 ) ;
if ( F_14 ( V_14 ) )
F_15 ( * V_2 -> V_6 , V_13 ) ;
F_16 () ;
return V_14 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 () ;
F_19 ( & V_2 -> V_8 . V_15 , 0 , 0 , V_16 ) ;
if ( F_14 ( F_11 ( V_2 , + 1 ) ) )
return;
F_20 ( & V_2 -> V_8 ) ;
F_21 ( & V_2 -> V_11 ) ;
F_22 ( & V_2 -> V_8 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
if ( F_3 ( ! F_11 ( V_2 , + 1 ) ) ) {
if ( ! F_24 ( & V_2 -> V_8 ) )
return 0 ;
F_21 ( & V_2 -> V_11 ) ;
F_22 ( & V_2 -> V_8 ) ;
}
F_19 ( & V_2 -> V_8 . V_15 , 0 , 1 , V_16 ) ;
return 1 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_8 . V_15 , 1 , V_16 ) ;
if ( F_14 ( F_11 ( V_2 , - 1 ) ) )
return;
if ( F_27 ( & V_2 -> V_11 ) )
F_28 ( & V_2 -> V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned int V_17 = 0 ;
int V_18 ;
F_30 (cpu) {
V_17 += F_31 ( * V_2 -> V_6 , V_18 ) ;
F_31 ( * V_2 -> V_6 , V_18 ) = 0 ;
}
return V_17 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_9 ) ;
F_34 ( & V_2 -> V_8 ) ;
F_35 ( F_29 ( V_2 ) , & V_2 -> V_11 ) ;
F_36 ( V_2 -> V_12 , ! F_37 ( & V_2 -> V_11 ) ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_8 ) ;
F_40 ( & V_2 -> V_9 ) ;
}
