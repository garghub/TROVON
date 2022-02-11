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
static int F_12 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , int V_14 , void * V_5 ,
T_1 * V_15 )
{
T_1 * V_16 , * V_17 ;
int V_18 = 0 ;
if ( V_15 && ( V_15 -> V_10 & V_19 ) ) {
V_16 = F_13 ( V_15 , V_20 ) ;
F_14 ( & V_15 -> V_20 ) ;
V_15 -> V_10 = 0 ;
} else
V_16 = F_15 ( & V_2 -> V_7 , T_1 , V_20 ) ;
if ( & V_16 -> V_20 == & V_2 -> V_7 )
return V_13 ;
F_16 (curr, next, &wq_head->head, entry) {
unsigned V_10 = V_16 -> V_10 ;
int V_21 ;
if ( V_10 & V_19 )
continue;
V_21 = V_16 -> V_22 ( V_16 , V_12 , V_14 , V_5 ) ;
if ( V_21 < 0 )
break;
if ( V_21 && ( V_10 & V_11 ) && ! -- V_13 )
break;
if ( V_15 && ( ++ V_18 > V_23 ) &&
( & V_17 -> V_20 != & V_2 -> V_7 ) ) {
V_15 -> V_10 = V_19 ;
F_17 ( & V_15 -> V_20 , & V_17 -> V_20 ) ;
break;
}
}
return V_13 ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , int V_14 , void * V_5 )
{
unsigned long V_10 ;
T_1 V_15 ;
V_15 . V_10 = 0 ;
V_15 . V_24 = NULL ;
V_15 . V_22 = NULL ;
F_4 ( & V_15 . V_20 ) ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
V_13 = F_12 ( V_2 , V_12 , V_13 , V_14 , V_5 , & V_15 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
while ( V_15 . V_10 & V_19 ) {
F_6 ( & V_2 -> V_6 , V_10 ) ;
V_13 = F_12 ( V_2 , V_12 , V_13 ,
V_14 , V_5 , & V_15 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
}
void F_19 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , void * V_5 )
{
F_18 ( V_2 , V_12 , V_13 , 0 , V_5 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned int V_12 , int V_25 )
{
F_12 ( V_2 , V_12 , V_25 , 0 , NULL , NULL ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_12 , void * V_5 )
{
F_12 ( V_2 , V_12 , 1 , 0 , V_5 , NULL ) ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_12 , void * V_5 , T_1 * V_15 )
{
F_12 ( V_2 , V_12 , 1 , 0 , V_5 , V_15 ) ;
}
void F_23 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_13 , void * V_5 )
{
int V_14 = 1 ;
if ( F_24 ( ! V_2 ) )
return;
if ( F_24 ( V_13 != 1 ) )
V_14 = 0 ;
F_18 ( V_2 , V_12 , V_13 , V_14 , V_5 ) ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_12 , int V_13 )
{
F_23 ( V_2 , V_12 , V_13 , NULL ) ;
}
void
F_26 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_26 )
{
unsigned long V_10 ;
V_9 -> V_10 &= ~ V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_27 ( & V_9 -> V_20 ) )
F_28 ( V_2 , V_9 ) ;
F_29 ( V_26 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void
F_30 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_26 )
{
unsigned long V_10 ;
V_9 -> V_10 |= V_11 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_27 ( & V_9 -> V_20 ) )
F_7 ( V_2 , V_9 ) ;
F_29 ( V_26 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
void F_31 ( struct V_8 * V_9 , int V_10 )
{
V_9 -> V_10 = V_10 ;
V_9 -> V_24 = V_27 ;
V_9 -> V_22 = V_28 ;
F_4 ( & V_9 -> V_20 ) ;
}
long F_32 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_26 )
{
unsigned long V_10 ;
long V_21 = 0 ;
F_6 ( & V_2 -> V_6 , V_10 ) ;
if ( F_24 ( F_33 ( V_26 , V_27 ) ) ) {
F_34 ( & V_9 -> V_20 ) ;
V_21 = - V_29 ;
} else {
if ( F_27 ( & V_9 -> V_20 ) ) {
if ( V_9 -> V_10 & V_11 )
F_7 ( V_2 , V_9 ) ;
else
F_28 ( V_2 , V_9 ) ;
}
F_29 ( V_26 ) ;
}
F_8 ( & V_2 -> V_6 , V_10 ) ;
return V_21 ;
}
int F_35 ( T_2 * V_30 , T_1 * V_31 )
{
if ( F_36 ( F_27 ( & V_31 -> V_20 ) ) )
F_7 ( V_30 , V_31 ) ;
F_29 ( V_32 ) ;
if ( F_37 ( V_27 ) )
return - V_29 ;
F_38 ( & V_30 -> V_6 ) ;
F_39 () ;
F_40 ( & V_30 -> V_6 ) ;
return 0 ;
}
int F_41 ( T_2 * V_30 , T_1 * V_31 )
{
if ( F_36 ( F_27 ( & V_31 -> V_20 ) ) )
F_7 ( V_30 , V_31 ) ;
F_29 ( V_32 ) ;
if ( F_37 ( V_27 ) )
return - V_29 ;
F_42 ( & V_30 -> V_6 ) ;
F_39 () ;
F_43 ( & V_30 -> V_6 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned long V_10 ;
F_45 ( V_33 ) ;
if ( ! F_46 ( & V_9 -> V_20 ) ) {
F_6 ( & V_2 -> V_6 , V_10 ) ;
F_34 ( & V_9 -> V_20 ) ;
F_8 ( & V_2 -> V_6 , V_10 ) ;
}
}
int V_28 ( struct V_8 * V_9 , unsigned V_12 , int V_34 , void * V_5 )
{
int V_21 = F_47 ( V_9 , V_12 , V_34 , V_5 ) ;
if ( V_21 )
F_34 ( & V_9 -> V_20 ) ;
return V_21 ;
}
static inline bool F_48 ( void )
{
return ( V_27 -> V_10 & V_35 ) && F_49 () ;
}
long F_50 ( struct V_8 * V_9 , unsigned V_12 , long V_36 )
{
F_29 ( V_12 ) ;
if ( ! ( V_9 -> V_10 & V_37 ) && ! F_48 () )
V_36 = F_51 ( V_36 ) ;
F_45 ( V_33 ) ;
F_52 ( V_9 -> V_10 , V_9 -> V_10 & ~ V_37 ) ;
return V_36 ;
}
int F_53 ( struct V_8 * V_9 , unsigned V_12 , int V_34 , void * V_5 )
{
F_54 () ;
V_9 -> V_10 |= V_37 ;
return F_47 ( V_9 , V_12 , V_34 , V_5 ) ;
}
