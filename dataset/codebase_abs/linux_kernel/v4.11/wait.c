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
void F_25 ( T_2 * V_7 , int V_8 )
{
V_7 -> V_8 = V_8 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_15 = V_20 ;
F_4 ( & V_7 -> V_6 ) ;
}
long F_26 ( T_1 * V_1 , T_2 * V_7 , int V_17 )
{
unsigned long V_8 ;
long V_21 = 0 ;
F_6 ( & V_1 -> V_5 , V_8 ) ;
if ( F_19 ( F_27 ( V_17 , V_19 ) ) ) {
F_28 ( & V_7 -> V_6 ) ;
V_21 = - V_22 ;
} else {
if ( F_22 ( & V_7 -> V_6 ) ) {
if ( V_7 -> V_8 & V_9 )
F_10 ( V_1 , V_7 ) ;
else
F_7 ( V_1 , V_7 ) ;
}
F_23 ( V_17 ) ;
}
F_8 ( & V_1 -> V_5 , V_8 ) ;
return V_21 ;
}
int F_29 ( T_1 * V_23 , T_2 * V_7 )
{
if ( F_30 ( F_22 ( & V_7 -> V_6 ) ) )
F_10 ( V_23 , V_7 ) ;
F_23 ( V_24 ) ;
if ( F_31 ( V_19 ) )
return - V_22 ;
F_32 ( & V_23 -> V_5 ) ;
F_33 () ;
F_34 ( & V_23 -> V_5 ) ;
return 0 ;
}
int F_35 ( T_1 * V_23 , T_2 * V_7 )
{
if ( F_30 ( F_22 ( & V_7 -> V_6 ) ) )
F_10 ( V_23 , V_7 ) ;
F_23 ( V_24 ) ;
if ( F_31 ( V_19 ) )
return - V_22 ;
F_36 ( & V_23 -> V_5 ) ;
F_33 () ;
F_37 ( & V_23 -> V_5 ) ;
return 0 ;
}
void F_38 ( T_1 * V_1 , T_2 * V_7 )
{
unsigned long V_8 ;
F_39 ( V_25 ) ;
if ( ! F_40 ( & V_7 -> V_6 ) ) {
F_6 ( & V_1 -> V_5 , V_8 ) ;
F_28 ( & V_7 -> V_6 ) ;
F_8 ( & V_1 -> V_5 , V_8 ) ;
}
}
int V_20 ( T_2 * V_7 , unsigned V_10 , int V_26 , void * V_4 )
{
int V_21 = F_41 ( V_7 , V_10 , V_26 , V_4 ) ;
if ( V_21 )
F_28 ( & V_7 -> V_6 ) ;
return V_21 ;
}
static inline bool F_42 ( void )
{
return ( V_19 -> V_8 & V_27 ) && F_43 () ;
}
long F_44 ( T_2 * V_7 , unsigned V_10 , long V_28 )
{
F_23 ( V_10 ) ;
if ( ! ( V_7 -> V_8 & V_29 ) && ! F_42 () )
V_28 = F_45 ( V_28 ) ;
F_39 ( V_25 ) ;
F_46 ( V_7 -> V_8 , V_7 -> V_8 & ~ V_29 ) ;
return V_28 ;
}
int F_47 ( T_2 * V_7 , unsigned V_10 , int V_26 , void * V_4 )
{
F_48 () ;
V_7 -> V_8 |= V_29 ;
return F_41 ( V_7 , V_10 , V_26 , V_4 ) ;
}
int F_49 ( T_2 * V_7 , unsigned V_10 , int V_26 , void * V_30 )
{
struct V_31 * V_4 = V_30 ;
struct V_32 * V_33
= F_50 ( V_7 , struct V_32 , V_7 ) ;
if ( V_33 -> V_4 . V_8 != V_4 -> V_8 ||
V_33 -> V_4 . V_34 != V_4 -> V_34 ||
F_51 ( V_4 -> V_34 , V_4 -> V_8 ) )
return 0 ;
else
return V_20 ( V_7 , V_10 , V_26 , V_4 ) ;
}
int T_3
F_52 ( T_1 * V_23 , struct V_32 * V_1 ,
T_4 * V_35 , unsigned V_10 )
{
int V_21 = 0 ;
do {
F_21 ( V_23 , & V_1 -> V_7 , V_10 ) ;
if ( F_51 ( V_1 -> V_4 . V_34 , V_1 -> V_4 . V_8 ) )
V_21 = (* V_35)( & V_1 -> V_4 , V_10 ) ;
} while ( F_51 ( V_1 -> V_4 . V_34 , V_1 -> V_4 . V_8 ) && ! V_21 );
F_38 ( V_23 , & V_1 -> V_7 ) ;
return V_21 ;
}
int T_3 F_53 ( void * V_36 , int V_37 ,
T_4 * V_35 , unsigned V_10 )
{
T_1 * V_23 = F_54 ( V_36 , V_37 ) ;
F_55 ( V_7 , V_36 , V_37 ) ;
return F_52 ( V_23 , & V_7 , V_35 , V_10 ) ;
}
int T_3 F_56 (
void * V_36 , int V_37 , T_4 * V_35 ,
unsigned V_10 , unsigned long V_28 )
{
T_1 * V_23 = F_54 ( V_36 , V_37 ) ;
F_55 ( V_7 , V_36 , V_37 ) ;
V_7 . V_4 . V_28 = V_38 + V_28 ;
return F_52 ( V_23 , & V_7 , V_35 , V_10 ) ;
}
int T_3
F_57 ( T_1 * V_23 , struct V_32 * V_1 ,
T_4 * V_35 , unsigned V_10 )
{
int V_21 = 0 ;
for (; ; ) {
F_24 ( V_23 , & V_1 -> V_7 , V_10 ) ;
if ( F_51 ( V_1 -> V_4 . V_34 , V_1 -> V_4 . V_8 ) ) {
V_21 = V_35 ( & V_1 -> V_4 , V_10 ) ;
if ( V_21 )
F_38 ( V_23 , & V_1 -> V_7 ) ;
}
if ( ! F_58 ( V_1 -> V_4 . V_34 , V_1 -> V_4 . V_8 ) ) {
if ( ! V_21 )
F_38 ( V_23 , & V_1 -> V_7 ) ;
return 0 ;
} else if ( V_21 ) {
return V_21 ;
}
}
}
int T_3 F_59 ( void * V_36 , int V_37 ,
T_4 * V_35 , unsigned V_10 )
{
T_1 * V_23 = F_54 ( V_36 , V_37 ) ;
F_55 ( V_7 , V_36 , V_37 ) ;
return F_57 ( V_23 , & V_7 , V_35 , V_10 ) ;
}
void F_60 ( T_1 * V_23 , void * V_36 , int V_37 )
{
struct V_31 V_4 = F_61 ( V_36 , V_37 ) ;
if ( F_62 ( V_23 ) )
F_15 ( V_23 , V_39 , 1 , & V_4 ) ;
}
void F_63 ( void * V_36 , int V_37 )
{
F_60 ( F_54 ( V_36 , V_37 ) , V_36 , V_37 ) ;
}
static inline T_1 * F_64 ( T_5 * V_40 )
{
if ( V_41 == 64 ) {
unsigned long V_1 = ( unsigned long ) V_40 ;
return F_54 ( ( void * ) ( V_1 & ~ 1 ) , V_1 & 1 ) ;
}
return F_54 ( V_40 , 0 ) ;
}
static int F_65 ( T_2 * V_7 , unsigned V_10 , int V_26 ,
void * V_30 )
{
struct V_31 * V_4 = V_30 ;
struct V_32 * V_33
= F_50 ( V_7 , struct V_32 , V_7 ) ;
T_5 * V_42 = V_4 -> V_8 ;
if ( V_33 -> V_4 . V_8 != V_4 -> V_8 ||
V_33 -> V_4 . V_34 != V_4 -> V_34 ||
F_66 ( V_42 ) != 0 )
return 0 ;
return V_20 ( V_7 , V_10 , V_26 , V_4 ) ;
}
static T_3
int F_67 ( T_1 * V_23 , struct V_32 * V_1 ,
int (* V_35)( T_5 * ) , unsigned V_10 )
{
T_5 * V_42 ;
int V_21 = 0 ;
do {
F_21 ( V_23 , & V_1 -> V_7 , V_10 ) ;
V_42 = V_1 -> V_4 . V_8 ;
if ( F_66 ( V_42 ) == 0 )
break;
V_21 = (* V_35)( V_42 ) ;
} while ( ! V_21 && F_66 ( V_42 ) != 0 );
F_38 ( V_23 , & V_1 -> V_7 ) ;
return V_21 ;
}
T_3 int F_68 ( T_5 * V_40 , int (* V_35)( T_5 * ) ,
unsigned V_10 )
{
T_1 * V_23 = F_64 ( V_40 ) ;
F_69 ( V_7 , V_40 ) ;
return F_67 ( V_23 , & V_7 , V_35 , V_10 ) ;
}
void F_70 ( T_5 * V_40 )
{
F_60 ( F_64 ( V_40 ) , V_40 , V_43 ) ;
}
T_3 int F_71 ( struct V_31 * V_36 , int V_10 )
{
F_33 () ;
if ( F_27 ( V_10 , V_19 ) )
return - V_44 ;
return 0 ;
}
T_3 int F_72 ( struct V_31 * V_36 , int V_10 )
{
F_73 () ;
if ( F_27 ( V_10 , V_19 ) )
return - V_44 ;
return 0 ;
}
T_3 int F_74 ( struct V_31 * V_36 , int V_10 )
{
unsigned long V_45 = F_75 ( V_38 ) ;
if ( F_76 ( V_45 , V_36 -> V_28 ) )
return - V_46 ;
F_45 ( V_36 -> V_28 - V_45 ) ;
if ( F_27 ( V_10 , V_19 ) )
return - V_44 ;
return 0 ;
}
T_3 int F_77 ( struct V_31 * V_36 , int V_10 )
{
unsigned long V_45 = F_75 ( V_38 ) ;
if ( F_76 ( V_45 , V_36 -> V_28 ) )
return - V_46 ;
F_78 ( V_36 -> V_28 - V_45 ) ;
if ( F_27 ( V_10 , V_19 ) )
return - V_44 ;
return 0 ;
}
