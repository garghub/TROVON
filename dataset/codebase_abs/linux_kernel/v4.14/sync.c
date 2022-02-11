static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 )
F_2 ( V_2 ) ;
else
F_3 ( V_2 , V_4 ) ;
if ( V_2 -> V_5 -> V_6 )
V_2 -> V_5 -> V_6 ( V_2 , V_3 ) ;
return F_4 ( V_2 -> V_7 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_8 ;
F_6 ( ! F_7 ( & V_2 -> V_9 ) ) ;
if ( F_8 ( V_2 ) )
return 0 ;
V_8 = F_1 ( V_2 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_1 ( V_2 , 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , void * V_10 )
{
if ( ! F_8 ( V_2 ) )
F_2 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_10 )
{
if ( ! F_8 ( V_2 ) && V_2 -> V_5 -> V_6 )
V_2 -> V_5 -> V_6 ( V_2 , * ( int * ) V_10 ) ;
}
static void F_11 ( struct V_11 * V_12 , void * V_10 )
{
F_12 ( V_12 -> V_13 -> V_14 ) ;
}
static void F_13 ( struct V_11 * V_12 , void * V_10 )
{
F_14 ( V_12 -> V_13 -> V_14 ) ;
}
static void F_15 ( struct V_15 * V_16 )
{
int V_17 = 0 ;
F_16 ( F_9 , & V_17 ) ;
F_16 ( F_10 , & V_17 ) ;
F_17 ( F_11 , NULL ) ;
F_16 ( F_9 , & V_17 ) ;
F_16 ( F_10 , & V_17 ) ;
F_17 ( F_11 , NULL ) ;
F_18 ( L_1 ) ;
F_19 ( V_16 ) ;
}
void F_20 ( void )
{
struct V_15 * V_16 ;
V_16 = F_21 ( sizeof( * V_16 ) , V_18 ) ;
if ( V_16 ) {
F_22 ( V_16 , F_15 ) ;
F_23 ( V_16 ) ;
}
}
int F_24 ( struct V_19 * V_19 , T_1 V_20 , T_1 V_21 , int V_22 )
{
struct V_23 * V_23 = V_19 -> V_24 -> V_25 ;
if ( ! V_19 -> V_26 -> V_27 )
return - V_28 ;
if ( ! V_22 && ( V_23 -> V_29 & V_30 ) ) {
F_25 ( & V_23 -> V_31 ) ;
V_23 -> V_29 &= ~ V_30 ;
F_26 ( & V_23 -> V_31 ) ;
F_27 ( V_23 ) ;
}
return V_19 -> V_26 -> V_27 ( V_19 , V_20 , V_21 , V_22 ) ;
}
int F_28 ( struct V_19 * V_19 , int V_22 )
{
return F_24 ( V_19 , 0 , V_32 , V_22 ) ;
}
static int F_29 ( unsigned int V_33 , int V_22 )
{
struct V_33 V_34 = F_30 ( V_33 ) ;
int V_8 = - V_35 ;
if ( V_34 . V_19 ) {
V_8 = F_28 ( V_34 . V_19 , V_22 ) ;
F_31 ( V_34 ) ;
}
return V_8 ;
}
