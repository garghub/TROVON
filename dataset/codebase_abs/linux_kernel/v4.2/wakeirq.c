static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
unsigned long V_6 ;
int V_7 ;
if ( ! V_2 || ! V_5 )
return - V_8 ;
F_2 ( & V_2 -> V_9 . V_10 , V_6 ) ;
if ( F_3 ( V_2 , V_2 -> V_9 . V_11 ,
L_1 ) ) {
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
return - V_12 ;
}
V_7 = F_5 ( V_2 , V_5 ) ;
if ( ! V_7 )
V_2 -> V_9 . V_11 = V_5 ;
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_7 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_7 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_7 )
F_8 ( V_5 ) ;
return V_7 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
unsigned long V_6 ;
if ( ! V_5 )
return;
F_2 ( & V_2 -> V_9 . V_10 , V_6 ) ;
F_10 ( V_2 ) ;
V_2 -> V_9 . V_11 = NULL ;
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
if ( V_5 -> V_15 )
F_11 ( V_5 -> V_3 , V_5 ) ;
F_8 ( V_5 ) ;
}
static T_1 F_12 ( int V_3 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
int V_17 ;
V_17 = F_13 ( V_5 -> V_2 ) ;
if ( V_17 < 0 )
F_14 ( V_5 -> V_2 ,
L_2 , V_17 ) ;
return V_18 ;
}
int F_15 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_7 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_15 = true ;
F_16 ( V_3 , V_19 ) ;
V_7 = F_17 ( V_3 , NULL , F_12 ,
V_20 , F_18 ( V_2 ) , V_5 ) ;
if ( V_7 )
goto V_21;
V_7 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_7 )
goto V_22;
return V_7 ;
V_22:
F_11 ( V_3 , V_5 ) ;
V_21:
F_8 ( V_5 ) ;
return V_7 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( V_5 && V_5 -> V_15 )
F_20 ( V_5 -> V_3 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( V_5 && V_5 -> V_15 )
F_22 ( V_5 -> V_3 ) ;
}
void F_23 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
if ( F_24 ( V_5 -> V_2 ) )
F_25 ( V_5 -> V_3 ) ;
}
void F_26 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
if ( F_24 ( V_5 -> V_2 ) )
F_27 ( V_5 -> V_3 ) ;
}
