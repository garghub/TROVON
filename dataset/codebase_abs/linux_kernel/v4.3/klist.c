static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * )
( ( unsigned long ) V_3 -> V_4 & V_5 ) ;
}
static bool F_2 ( struct V_2 * V_3 )
{
return ( unsigned long ) V_3 -> V_4 & V_6 ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
V_3 -> V_4 = V_1 ;
F_4 ( F_2 ( V_3 ) ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_4 ( F_2 ( V_3 ) ) ;
* ( unsigned long * ) & V_3 -> V_4 |= V_6 ;
}
void F_6 ( struct V_1 * V_7 , void (* F_7)( struct V_2 * ) ,
void (* F_8)( struct V_2 * ) )
{
F_9 ( & V_7 -> V_8 ) ;
F_10 ( & V_7 -> V_9 ) ;
V_7 -> F_7 = F_7 ;
V_7 -> F_8 = F_8 ;
}
static void F_11 ( struct V_1 * V_7 , struct V_2 * V_10 )
{
F_12 ( & V_7 -> V_9 ) ;
F_13 ( & V_10 -> V_11 , & V_7 -> V_8 ) ;
F_14 ( & V_7 -> V_9 ) ;
}
static void F_15 ( struct V_1 * V_7 , struct V_2 * V_10 )
{
F_12 ( & V_7 -> V_9 ) ;
F_16 ( & V_10 -> V_11 , & V_7 -> V_8 ) ;
F_14 ( & V_7 -> V_9 ) ;
}
static void F_17 ( struct V_1 * V_7 , struct V_2 * V_10 )
{
F_9 ( & V_10 -> V_11 ) ;
F_18 ( & V_10 -> V_12 ) ;
F_3 ( V_10 , V_7 ) ;
if ( V_7 -> F_7 )
V_7 -> F_7 ( V_10 ) ;
}
void F_19 ( struct V_2 * V_10 , struct V_1 * V_7 )
{
F_17 ( V_7 , V_10 ) ;
F_11 ( V_7 , V_10 ) ;
}
void F_20 ( struct V_2 * V_10 , struct V_1 * V_7 )
{
F_17 ( V_7 , V_10 ) ;
F_15 ( V_7 , V_10 ) ;
}
void F_21 ( struct V_2 * V_10 , struct V_2 * V_13 )
{
struct V_1 * V_7 = F_1 ( V_13 ) ;
F_17 ( V_7 , V_10 ) ;
F_12 ( & V_7 -> V_9 ) ;
F_13 ( & V_10 -> V_11 , & V_13 -> V_11 ) ;
F_14 ( & V_7 -> V_9 ) ;
}
void F_22 ( struct V_2 * V_10 , struct V_2 * V_13 )
{
struct V_1 * V_7 = F_1 ( V_13 ) ;
F_17 ( V_7 , V_10 ) ;
F_12 ( & V_7 -> V_9 ) ;
F_16 ( & V_10 -> V_11 , & V_13 -> V_11 ) ;
F_14 ( & V_7 -> V_9 ) ;
}
static void F_23 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
struct V_2 * V_10 = F_24 ( V_14 , struct V_2 , V_12 ) ;
F_4 ( ! F_2 ( V_10 ) ) ;
F_25 ( & V_10 -> V_11 ) ;
F_12 ( & V_18 ) ;
F_26 (waiter, tmp, &klist_remove_waiters, list) {
if ( V_16 -> V_19 != V_10 )
continue;
F_25 ( & V_16 -> V_20 ) ;
V_16 -> V_21 = 1 ;
F_27 () ;
F_28 ( V_16 -> V_22 ) ;
}
F_14 ( & V_18 ) ;
F_3 ( V_10 , NULL ) ;
}
static int F_29 ( struct V_2 * V_10 )
{
return F_30 ( & V_10 -> V_12 , F_23 ) ;
}
static void F_31 ( struct V_2 * V_10 , bool V_23 )
{
struct V_1 * V_7 = F_1 ( V_10 ) ;
void (* F_8)( struct V_2 * ) = V_7 -> F_8 ;
F_12 ( & V_7 -> V_9 ) ;
if ( V_23 )
F_5 ( V_10 ) ;
if ( ! F_29 ( V_10 ) )
F_8 = NULL ;
F_14 ( & V_7 -> V_9 ) ;
if ( F_8 )
F_8 ( V_10 ) ;
}
void F_32 ( struct V_2 * V_10 )
{
F_31 ( V_10 , true ) ;
}
void F_33 ( struct V_2 * V_10 )
{
struct V_15 V_16 ;
V_16 . V_19 = V_10 ;
V_16 . V_22 = V_24 ;
V_16 . V_21 = 0 ;
F_12 ( & V_18 ) ;
F_13 ( & V_16 . V_20 , & V_25 ) ;
F_14 ( & V_18 ) ;
F_32 ( V_10 ) ;
for (; ; ) {
F_34 ( V_26 ) ;
if ( V_16 . V_21 )
break;
F_35 () ;
}
F_36 ( V_27 ) ;
}
int F_37 ( struct V_2 * V_10 )
{
return ( V_10 -> V_4 != NULL ) ;
}
void F_38 ( struct V_1 * V_7 , struct V_28 * V_29 ,
struct V_2 * V_10 )
{
V_29 -> V_30 = V_7 ;
V_29 -> V_31 = V_10 ;
if ( V_10 )
F_39 ( & V_10 -> V_12 ) ;
}
void F_40 ( struct V_1 * V_7 , struct V_28 * V_29 )
{
F_38 ( V_7 , V_29 , NULL ) ;
}
void F_41 ( struct V_28 * V_29 )
{
if ( V_29 -> V_31 ) {
F_31 ( V_29 -> V_31 , false ) ;
V_29 -> V_31 = NULL ;
}
}
static struct V_2 * F_42 ( struct V_32 * V_10 )
{
return F_24 ( V_10 , struct V_2 , V_11 ) ;
}
struct V_2 * F_43 ( struct V_28 * V_29 )
{
void (* F_8)( struct V_2 * ) = V_29 -> V_30 -> F_8 ;
struct V_2 * V_33 = V_29 -> V_31 ;
struct V_2 * V_34 ;
F_12 ( & V_29 -> V_30 -> V_9 ) ;
if ( V_33 ) {
V_34 = F_42 ( V_33 -> V_11 . V_34 ) ;
if ( ! F_29 ( V_33 ) )
F_8 = NULL ;
} else
V_34 = F_42 ( V_29 -> V_30 -> V_8 . V_34 ) ;
V_29 -> V_31 = NULL ;
while ( V_34 != F_42 ( & V_29 -> V_30 -> V_8 ) ) {
if ( F_44 ( ! F_2 ( V_34 ) ) ) {
F_39 ( & V_34 -> V_12 ) ;
V_29 -> V_31 = V_34 ;
break;
}
V_34 = F_42 ( V_34 -> V_11 . V_34 ) ;
}
F_14 ( & V_29 -> V_30 -> V_9 ) ;
if ( F_8 && V_33 )
F_8 ( V_33 ) ;
return V_29 -> V_31 ;
}
struct V_2 * F_45 ( struct V_28 * V_29 )
{
void (* F_8)( struct V_2 * ) = V_29 -> V_30 -> F_8 ;
struct V_2 * V_33 = V_29 -> V_31 ;
struct V_2 * V_35 ;
F_12 ( & V_29 -> V_30 -> V_9 ) ;
if ( V_33 ) {
V_35 = F_42 ( V_33 -> V_11 . V_35 ) ;
if ( ! F_29 ( V_33 ) )
F_8 = NULL ;
} else
V_35 = F_42 ( V_29 -> V_30 -> V_8 . V_35 ) ;
V_29 -> V_31 = NULL ;
while ( V_35 != F_42 ( & V_29 -> V_30 -> V_8 ) ) {
if ( F_44 ( ! F_2 ( V_35 ) ) ) {
F_39 ( & V_35 -> V_12 ) ;
V_29 -> V_31 = V_35 ;
break;
}
V_35 = F_42 ( V_35 -> V_11 . V_35 ) ;
}
F_14 ( & V_29 -> V_30 -> V_9 ) ;
if ( F_8 && V_33 )
F_8 ( V_33 ) ;
return V_29 -> V_31 ;
}
