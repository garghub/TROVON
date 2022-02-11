void F_1 ( T_1 * V_1 , const char * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_1 -> V_5 ) ;
F_3 ( & V_1 -> V_5 , V_4 , V_2 ) ;
F_4 ( & V_1 -> V_6 ) ;
}
void F_5 ( T_1 * V_1 , T_2 * V_7 )
{
unsigned long V_8 ;
V_7 -> V_8 &= ~ V_9 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_7 ( V_1 , V_7 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
void F_9 ( T_1 * V_1 , T_2 * V_7 )
{
unsigned long V_8 ;
V_7 -> V_8 |= V_9 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_10 ( V_1 , V_7 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
void F_11 ( T_1 * V_1 , T_2 * V_7 )
{
unsigned long V_8 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_12 ( V_1 , V_7 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
static void F_13 ( T_1 * V_1 , unsigned int V_10 ,
int V_11 , int V_12 , void * V_4 )
{
T_2 * V_13 , * V_14 ;
F_14 (curr, next, &q->task_list, task_list) {
unsigned V_8 = V_13 -> V_8 ;
if ( V_13 -> V_15 ( V_13 , V_10 , V_12 , V_4 ) &&
( V_8 & V_9 ) && ! -- V_11 )
break;
}
}
void F_15 ( T_1 * V_1 , unsigned int V_10 ,
int V_11 , void * V_4 )
{
unsigned long V_8 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_13 ( V_1 , V_10 , V_11 , 0 , V_4 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
void F_16 ( T_1 * V_1 , unsigned int V_10 , int V_16 )
{
F_13 ( V_1 , V_10 , V_16 , 0 , NULL ) ;
}
void F_17 ( T_1 * V_1 , unsigned int V_10 , void * V_4 )
{
F_13 ( V_1 , V_10 , 1 , 0 , V_4 ) ;
}
void F_18 ( T_1 * V_1 , unsigned int V_10 ,
int V_11 , void * V_4 )
{
unsigned long V_8 ;
int V_12 = 1 ;
if ( F_19 ( ! V_1 ) )
return;
if ( F_19 ( V_11 != 1 ) )
V_12 = 0 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_13 ( V_1 , V_10 , V_11 , V_12 , V_4 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
void F_20 ( T_1 * V_1 , unsigned int V_10 , int V_11 )
{
F_18 ( V_1 , V_10 , V_11 , NULL ) ;
}
void
F_21 ( T_1 * V_1 , T_2 * V_7 , int V_17 )
{
unsigned long V_8 ;
V_7 -> V_8 &= ~ V_9 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
if ( F_22 ( & V_7 -> V_6 ) )
F_7 ( V_1 , V_7 ) ;
F_23 ( V_17 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
void
F_24 ( T_1 * V_1 , T_2 * V_7 , int V_17 )
{
unsigned long V_8 ;
V_7 -> V_8 |= V_9 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
if ( F_22 ( & V_7 -> V_6 ) )
F_10 ( V_1 , V_7 ) ;
F_23 ( V_17 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
long F_25 ( T_1 * V_1 , T_2 * V_7 , int V_17 )
{
unsigned long V_8 ;
if ( F_26 ( V_17 , V_18 ) )
return - V_19 ;
V_7 -> V_20 = V_18 ;
V_7 -> V_15 = V_21 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
if ( F_22 ( & V_7 -> V_6 ) ) {
if ( V_7 -> V_8 & V_9 )
F_10 ( V_1 , V_7 ) ;
else
F_7 ( V_1 , V_7 ) ;
}
F_23 ( V_17 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
return 0 ;
}
void F_27 ( T_1 * V_1 , T_2 * V_7 )
{
unsigned long V_8 ;
F_28 ( V_22 ) ;
if ( ! F_29 ( & V_7 -> V_6 ) ) {
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_30 ( & V_7 -> V_6 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
}
void F_31 ( T_1 * V_1 , T_2 * V_7 ,
unsigned int V_10 , void * V_4 )
{
unsigned long V_8 ;
F_28 ( V_22 ) ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
if ( ! F_22 ( & V_7 -> V_6 ) )
F_30 ( & V_7 -> V_6 ) ;
else if ( F_32 ( V_1 ) )
F_17 ( V_1 , V_10 , V_4 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
int V_21 ( T_2 * V_7 , unsigned V_10 , int V_23 , void * V_4 )
{
int V_24 = F_33 ( V_7 , V_10 , V_23 , V_4 ) ;
if ( V_24 )
F_30 ( & V_7 -> V_6 ) ;
return V_24 ;
}
static inline bool F_34 ( void )
{
return ( V_18 -> V_8 & V_25 ) && F_35 () ;
}
long F_36 ( T_2 * V_7 , unsigned V_10 , long V_26 )
{
F_23 ( V_10 ) ;
if ( ! ( V_7 -> V_8 & V_27 ) && ! F_34 () )
V_26 = F_37 ( V_26 ) ;
F_28 ( V_22 ) ;
F_38 ( V_7 -> V_8 , V_7 -> V_8 & ~ V_27 ) ;
return V_26 ;
}
int F_39 ( T_2 * V_7 , unsigned V_10 , int V_23 , void * V_4 )
{
F_40 () ;
V_7 -> V_8 |= V_27 ;
return F_33 ( V_7 , V_10 , V_23 , V_4 ) ;
}
int F_41 ( T_2 * V_7 , unsigned V_10 , int V_23 , void * V_28 )
{
struct V_29 * V_4 = V_28 ;
struct V_30 * V_31
= F_42 ( V_7 , struct V_30 , V_7 ) ;
if ( V_31 -> V_4 . V_8 != V_4 -> V_8 ||
V_31 -> V_4 . V_32 != V_4 -> V_32 ||
F_43 ( V_4 -> V_32 , V_4 -> V_8 ) )
return 0 ;
else
return V_21 ( V_7 , V_10 , V_23 , V_4 ) ;
}
int T_3
F_44 ( T_1 * V_33 , struct V_30 * V_1 ,
T_4 * V_34 , unsigned V_10 )
{
int V_24 = 0 ;
do {
F_21 ( V_33 , & V_1 -> V_7 , V_10 ) ;
if ( F_43 ( V_1 -> V_4 . V_32 , V_1 -> V_4 . V_8 ) )
V_24 = (* V_34)( & V_1 -> V_4 , V_10 ) ;
} while ( F_43 ( V_1 -> V_4 . V_32 , V_1 -> V_4 . V_8 ) && ! V_24 );
F_27 ( V_33 , & V_1 -> V_7 ) ;
return V_24 ;
}
int T_3 F_45 ( void * V_35 , int V_36 ,
T_4 * V_34 , unsigned V_10 )
{
T_1 * V_33 = F_46 ( V_35 , V_36 ) ;
F_47 ( V_7 , V_35 , V_36 ) ;
return F_44 ( V_33 , & V_7 , V_34 , V_10 ) ;
}
int T_3 F_48 (
void * V_35 , int V_36 , T_4 * V_34 ,
unsigned V_10 , unsigned long V_26 )
{
T_1 * V_33 = F_46 ( V_35 , V_36 ) ;
F_47 ( V_7 , V_35 , V_36 ) ;
V_7 . V_4 . V_26 = V_37 + V_26 ;
return F_44 ( V_33 , & V_7 , V_34 , V_10 ) ;
}
int T_3
F_49 ( T_1 * V_33 , struct V_30 * V_1 ,
T_4 * V_34 , unsigned V_10 )
{
do {
int V_24 ;
F_24 ( V_33 , & V_1 -> V_7 , V_10 ) ;
if ( ! F_43 ( V_1 -> V_4 . V_32 , V_1 -> V_4 . V_8 ) )
continue;
V_24 = V_34 ( & V_1 -> V_4 , V_10 ) ;
if ( ! V_24 )
continue;
F_31 ( V_33 , & V_1 -> V_7 , V_10 , & V_1 -> V_4 ) ;
return V_24 ;
} while ( F_50 ( V_1 -> V_4 . V_32 , V_1 -> V_4 . V_8 ) );
F_27 ( V_33 , & V_1 -> V_7 ) ;
return 0 ;
}
int T_3 F_51 ( void * V_35 , int V_36 ,
T_4 * V_34 , unsigned V_10 )
{
T_1 * V_33 = F_46 ( V_35 , V_36 ) ;
F_47 ( V_7 , V_35 , V_36 ) ;
return F_49 ( V_33 , & V_7 , V_34 , V_10 ) ;
}
void F_52 ( T_1 * V_33 , void * V_35 , int V_36 )
{
struct V_29 V_4 = F_53 ( V_35 , V_36 ) ;
if ( F_32 ( V_33 ) )
F_15 ( V_33 , V_38 , 1 , & V_4 ) ;
}
void F_54 ( void * V_35 , int V_36 )
{
F_52 ( F_46 ( V_35 , V_36 ) , V_35 , V_36 ) ;
}
T_1 * F_46 ( void * V_35 , int V_36 )
{
const int V_39 = V_40 == 32 ? 5 : 6 ;
const struct V_41 * V_41 = F_55 ( F_56 ( V_35 ) ) ;
unsigned long V_42 = ( unsigned long ) V_35 << V_39 | V_36 ;
return & V_41 -> V_43 [ F_57 ( V_42 , V_41 -> V_44 ) ] ;
}
static inline T_1 * F_58 ( T_5 * V_45 )
{
if ( V_40 == 64 ) {
unsigned long V_1 = ( unsigned long ) V_45 ;
return F_46 ( ( void * ) ( V_1 & ~ 1 ) , V_1 & 1 ) ;
}
return F_46 ( V_45 , 0 ) ;
}
static int F_59 ( T_2 * V_7 , unsigned V_10 , int V_23 ,
void * V_28 )
{
struct V_29 * V_4 = V_28 ;
struct V_30 * V_31
= F_42 ( V_7 , struct V_30 , V_7 ) ;
T_5 * V_42 = V_4 -> V_8 ;
if ( V_31 -> V_4 . V_8 != V_4 -> V_8 ||
V_31 -> V_4 . V_32 != V_4 -> V_32 ||
F_60 ( V_42 ) != 0 )
return 0 ;
return V_21 ( V_7 , V_10 , V_23 , V_4 ) ;
}
static T_3
int F_61 ( T_1 * V_33 , struct V_30 * V_1 ,
int (* V_34)( T_5 * ) , unsigned V_10 )
{
T_5 * V_42 ;
int V_24 = 0 ;
do {
F_21 ( V_33 , & V_1 -> V_7 , V_10 ) ;
V_42 = V_1 -> V_4 . V_8 ;
if ( F_60 ( V_42 ) == 0 )
break;
V_24 = (* V_34)( V_42 ) ;
} while ( ! V_24 && F_60 ( V_42 ) != 0 );
F_27 ( V_33 , & V_1 -> V_7 ) ;
return V_24 ;
}
T_3 int F_62 ( T_5 * V_45 , int (* V_34)( T_5 * ) ,
unsigned V_10 )
{
T_1 * V_33 = F_58 ( V_45 ) ;
F_63 ( V_7 , V_45 ) ;
return F_61 ( V_33 , & V_7 , V_34 , V_10 ) ;
}
void F_64 ( T_5 * V_45 )
{
F_52 ( F_58 ( V_45 ) , V_45 , V_46 ) ;
}
T_3 int F_65 ( struct V_29 * V_35 , int V_10 )
{
F_66 () ;
if ( F_26 ( V_10 , V_18 ) )
return - V_47 ;
return 0 ;
}
T_3 int F_67 ( struct V_29 * V_35 , int V_10 )
{
F_68 () ;
if ( F_26 ( V_10 , V_18 ) )
return - V_47 ;
return 0 ;
}
T_3 int F_69 ( struct V_29 * V_35 , int V_10 )
{
unsigned long V_48 = F_70 ( V_37 ) ;
if ( F_71 ( V_48 , V_35 -> V_26 ) )
return - V_49 ;
F_37 ( V_35 -> V_26 - V_48 ) ;
if ( F_26 ( V_10 , V_18 ) )
return - V_47 ;
return 0 ;
}
T_3 int F_72 ( struct V_29 * V_35 , int V_10 )
{
unsigned long V_48 = F_70 ( V_37 ) ;
if ( F_71 ( V_48 , V_35 -> V_26 ) )
return - V_49 ;
F_73 ( V_35 -> V_26 - V_48 ) ;
if ( F_26 ( V_10 , V_18 ) )
return - V_47 ;
return 0 ;
}
