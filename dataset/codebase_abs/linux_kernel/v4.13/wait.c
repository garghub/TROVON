void F_1 ( struct V_1 * V_2 , const char * V_3 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_6 , V_5 , V_3 ) ;
F_4 ( & V_2 -> V_7 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned long V_10 ;
V_9 -> V_10 &= ~ V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_7 ( V_2 , V_9 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned long V_10 ;
V_9 -> V_10 |= V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_7 ( V_2 , V_9 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_10 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned long V_10 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_11 ( V_2 , V_9 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , int V_14 , void * V_5 )
{
T_1 * V_15 , * V_16 ;
F_13 (curr, next, &wq_head->head, entry) {
unsigned V_10 = V_15 -> V_10 ;
int V_17 = V_15 -> V_18 ( V_15 , V_12 , V_14 , V_5 ) ;
if ( V_17 < 0 )
break;
if ( V_17 && ( V_10 & V_11 ) && ! -- V_13 )
break;
}
}
void F_14 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , void * V_5 )
{
unsigned long V_10 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_12 ( V_2 , V_12 , V_13 , 0 , V_5 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_12 , int V_19 )
{
F_12 ( V_2 , V_12 , V_19 , 0 , NULL ) ;
}
void F_16 ( struct V_1 * V_2 , unsigned int V_12 , void * V_5 )
{
F_12 ( V_2 , V_12 , 1 , 0 , V_5 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , void * V_5 )
{
unsigned long V_10 ;
int V_14 = 1 ;
if ( F_18 ( ! V_2 ) )
return;
if ( F_18 ( V_13 != 1 ) )
V_14 = 0 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_12 ( V_2 , V_12 , V_13 , V_14 , V_5 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_12 , int V_13 )
{
F_17 ( V_2 , V_12 , V_13 , NULL ) ;
}
void
F_20 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_20 )
{
unsigned long V_10 ;
V_9 -> V_10 &= ~ V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_21 ( & V_9 -> V_21 ) )
F_22 ( V_2 , V_9 ) ;
F_23 ( V_20 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void
F_24 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_20 )
{
unsigned long V_10 ;
V_9 -> V_10 |= V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_21 ( & V_9 -> V_21 ) )
F_7 ( V_2 , V_9 ) ;
F_23 ( V_20 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_25 ( struct V_8 * V_9 , int V_10 )
{
V_9 -> V_10 = V_10 ;
V_9 -> V_22 = V_23 ;
V_9 -> V_18 = V_24 ;
F_4 ( & V_9 -> V_21 ) ;
}
long F_26 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_20 )
{
unsigned long V_10 ;
long V_17 = 0 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_18 ( F_27 ( V_20 , V_23 ) ) ) {
F_28 ( & V_9 -> V_21 ) ;
V_17 = - V_25 ;
} else {
if ( F_21 ( & V_9 -> V_21 ) ) {
if ( V_9 -> V_10 & V_11 )
F_7 ( V_2 , V_9 ) ;
else
F_22 ( V_2 , V_9 ) ;
}
F_23 ( V_20 ) ;
}
F_8 ( & V_2 -> V_6 , V_10 ) ;
return V_17 ;
}
int F_29 ( T_2 * V_26 , T_1 * V_27 )
{
if ( F_30 ( F_21 ( & V_27 -> V_21 ) ) )
F_7 ( V_26 , V_27 ) ;
F_23 ( V_28 ) ;
if ( F_31 ( V_23 ) )
return - V_25 ;
F_32 ( & V_26 -> V_6 ) ;
F_33 () ;
F_34 ( & V_26 -> V_6 ) ;
return 0 ;
}
int F_35 ( T_2 * V_26 , T_1 * V_27 )
{
if ( F_30 ( F_21 ( & V_27 -> V_21 ) ) )
F_7 ( V_26 , V_27 ) ;
F_23 ( V_28 ) ;
if ( F_31 ( V_23 ) )
return - V_25 ;
F_36 ( & V_26 -> V_6 ) ;
F_33 () ;
F_37 ( & V_26 -> V_6 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned long V_10 ;
F_39 ( V_29 ) ;
if ( ! F_40 ( & V_9 -> V_21 ) ) {
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_28 ( & V_9 -> V_21 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
}
int V_24 ( struct V_8 * V_9 , unsigned V_12 , int V_30 , void * V_5 )
{
int V_17 = F_41 ( V_9 , V_12 , V_30 , V_5 ) ;
if ( V_17 )
F_28 ( & V_9 -> V_21 ) ;
return V_17 ;
}
static inline bool F_42 ( void )
{
return ( V_23 -> V_10 & V_31 ) && F_43 () ;
}
long F_44 ( struct V_8 * V_9 , unsigned V_12 , long V_32 )
{
F_23 ( V_12 ) ;
if ( ! ( V_9 -> V_10 & V_33 ) && ! F_42 () )
V_32 = F_45 ( V_32 ) ;
F_39 ( V_29 ) ;
F_46 ( V_9 -> V_10 , V_9 -> V_10 & ~ V_33 ) ;
return V_32 ;
}
int F_47 ( struct V_8 * V_9 , unsigned V_12 , int V_30 , void * V_5 )
{
F_48 () ;
V_9 -> V_10 |= V_33 ;
return F_41 ( V_9 , V_12 , V_30 , V_5 ) ;
}
