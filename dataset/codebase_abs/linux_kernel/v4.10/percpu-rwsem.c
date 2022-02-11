int F_1 ( struct V_1 * V_2 ,
const char * V_3 , struct V_4 * V_5 )
{
V_2 -> V_6 = F_2 ( int ) ;
if ( F_3 ( ! V_2 -> V_6 ) )
return - V_7 ;
F_4 ( & V_2 -> V_8 , V_9 ) ;
F_5 ( & V_2 -> V_10 , V_3 , V_5 ) ;
F_6 ( & V_2 -> V_11 ) ;
V_2 -> V_12 = 0 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return;
F_8 ( & V_2 -> V_8 ) ;
F_9 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
int F_10 ( struct V_1 * V_2 , int V_13 )
{
F_11 () ;
if ( F_12 ( ! F_13 ( & V_2 -> V_12 ) ) )
return 1 ;
F_14 ( V_2 ) ;
if ( V_13 )
return 0 ;
F_15 () ;
F_16 ( & V_2 -> V_10 ) ;
F_17 ( * V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_19 () ;
return 1 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_11 () ;
F_20 ( * V_2 -> V_6 ) ;
F_21 ( & V_2 -> V_11 ) ;
}
static bool F_22 ( struct V_1 * V_2 )
{
if ( F_23 ( * V_2 -> V_6 ) != 0 )
return false ;
F_11 () ;
return true ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_8 ) ;
F_26 ( & V_2 -> V_10 ) ;
F_27 ( V_2 -> V_12 , 1 ) ;
F_11 () ;
F_28 ( V_2 -> V_11 , F_22 ( V_2 ) ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_12 , 0 ) ;
F_31 ( & V_2 -> V_10 ) ;
F_32 ( & V_2 -> V_8 ) ;
}
