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
int F_34 ( T_2 * V_7 , unsigned V_10 , int V_23 , void * V_25 )
{
struct V_26 * V_4 = V_25 ;
struct V_27 * V_28
= F_35 ( V_7 , struct V_27 , V_7 ) ;
if ( V_28 -> V_4 . V_8 != V_4 -> V_8 ||
V_28 -> V_4 . V_29 != V_4 -> V_29 ||
F_36 ( V_4 -> V_29 , V_4 -> V_8 ) )
return 0 ;
else
return V_21 ( V_7 , V_10 , V_23 , V_4 ) ;
}
int T_3
F_37 ( T_1 * V_30 , struct V_27 * V_1 ,
int (* F_38)( void * ) , unsigned V_10 )
{
int V_24 = 0 ;
do {
F_21 ( V_30 , & V_1 -> V_7 , V_10 ) ;
if ( F_36 ( V_1 -> V_4 . V_29 , V_1 -> V_4 . V_8 ) )
V_24 = (* F_38)( V_1 -> V_4 . V_8 ) ;
} while ( F_36 ( V_1 -> V_4 . V_29 , V_1 -> V_4 . V_8 ) && ! V_24 );
F_27 ( V_30 , & V_1 -> V_7 ) ;
return V_24 ;
}
int T_3 F_39 ( void * V_31 , int V_32 ,
int (* F_38)( void * ) , unsigned V_10 )
{
T_1 * V_30 = F_40 ( V_31 , V_32 ) ;
F_41 ( V_7 , V_31 , V_32 ) ;
return F_37 ( V_30 , & V_7 , F_38 , V_10 ) ;
}
int T_3
F_42 ( T_1 * V_30 , struct V_27 * V_1 ,
int (* F_38)( void * ) , unsigned V_10 )
{
do {
int V_24 ;
F_24 ( V_30 , & V_1 -> V_7 , V_10 ) ;
if ( ! F_36 ( V_1 -> V_4 . V_29 , V_1 -> V_4 . V_8 ) )
continue;
V_24 = F_38 ( V_1 -> V_4 . V_8 ) ;
if ( ! V_24 )
continue;
F_31 ( V_30 , & V_1 -> V_7 , V_10 , & V_1 -> V_4 ) ;
return V_24 ;
} while ( F_43 ( V_1 -> V_4 . V_29 , V_1 -> V_4 . V_8 ) );
F_27 ( V_30 , & V_1 -> V_7 ) ;
return 0 ;
}
int T_3 F_44 ( void * V_31 , int V_32 ,
int (* F_38)( void * ) , unsigned V_10 )
{
T_1 * V_30 = F_40 ( V_31 , V_32 ) ;
F_41 ( V_7 , V_31 , V_32 ) ;
return F_42 ( V_30 , & V_7 , F_38 , V_10 ) ;
}
void F_45 ( T_1 * V_30 , void * V_31 , int V_32 )
{
struct V_26 V_4 = F_46 ( V_31 , V_32 ) ;
if ( F_32 ( V_30 ) )
F_15 ( V_30 , V_33 , 1 , & V_4 ) ;
}
void F_47 ( void * V_31 , int V_32 )
{
F_45 ( F_40 ( V_31 , V_32 ) , V_31 , V_32 ) ;
}
T_1 * F_40 ( void * V_31 , int V_32 )
{
const int V_34 = V_35 == 32 ? 5 : 6 ;
const struct V_36 * V_36 = F_48 ( F_49 ( V_31 ) ) ;
unsigned long V_37 = ( unsigned long ) V_31 << V_34 | V_32 ;
return & V_36 -> V_38 [ F_50 ( V_37 , V_36 -> V_39 ) ] ;
}
static inline T_1 * F_51 ( T_4 * V_40 )
{
if ( V_35 == 64 ) {
unsigned long V_1 = ( unsigned long ) V_40 ;
return F_40 ( ( void * ) ( V_1 & ~ 1 ) , V_1 & 1 ) ;
}
return F_40 ( V_40 , 0 ) ;
}
static int F_52 ( T_2 * V_7 , unsigned V_10 , int V_23 ,
void * V_25 )
{
struct V_26 * V_4 = V_25 ;
struct V_27 * V_28
= F_35 ( V_7 , struct V_27 , V_7 ) ;
T_4 * V_37 = V_4 -> V_8 ;
if ( V_28 -> V_4 . V_8 != V_4 -> V_8 ||
V_28 -> V_4 . V_29 != V_4 -> V_29 ||
F_53 ( V_37 ) != 0 )
return 0 ;
return V_21 ( V_7 , V_10 , V_23 , V_4 ) ;
}
static T_3
int F_54 ( T_1 * V_30 , struct V_27 * V_1 ,
int (* F_38)( T_4 * ) , unsigned V_10 )
{
T_4 * V_37 ;
int V_24 = 0 ;
do {
F_21 ( V_30 , & V_1 -> V_7 , V_10 ) ;
V_37 = V_1 -> V_4 . V_8 ;
if ( F_53 ( V_37 ) == 0 )
break;
V_24 = (* F_38)( V_37 ) ;
} while ( ! V_24 && F_53 ( V_37 ) != 0 );
F_27 ( V_30 , & V_1 -> V_7 ) ;
return V_24 ;
}
T_3 int F_55 ( T_4 * V_40 , int (* F_38)( T_4 * ) ,
unsigned V_10 )
{
T_1 * V_30 = F_51 ( V_40 ) ;
F_56 ( V_7 , V_40 ) ;
return F_54 ( V_30 , & V_7 , F_38 , V_10 ) ;
}
void F_57 ( T_4 * V_40 )
{
F_45 ( F_51 ( V_40 ) , V_40 , V_41 ) ;
}
