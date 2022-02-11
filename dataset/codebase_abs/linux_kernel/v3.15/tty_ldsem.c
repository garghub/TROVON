static inline long F_1 ( long V_1 , struct V_2 * V_3 )
{
return F_2 ( V_1 , ( V_4 * ) & V_3 -> V_5 ) ;
}
static inline int F_3 ( long * V_6 , long V_7 , struct V_2 * V_3 )
{
long V_8 = F_4 ( & V_3 -> V_5 , * V_6 , V_7 ) ;
if ( V_8 == * V_6 ) {
* V_6 = V_7 ;
return 1 ;
} else {
* V_6 = V_8 ;
return 0 ;
}
}
void F_5 ( struct V_2 * V_3 , const char * V_9 ,
struct V_10 * V_11 )
{
#ifdef F_6
F_7 ( ( void * ) V_3 , sizeof( * V_3 ) ) ;
F_8 ( & V_3 -> V_12 , V_9 , V_11 , 0 ) ;
#endif
V_3 -> V_5 = V_13 ;
V_3 -> V_14 = 0 ;
F_9 ( & V_3 -> V_15 ) ;
F_10 ( & V_3 -> V_16 ) ;
F_10 ( & V_3 -> V_17 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_18 * V_19 , * V_20 ;
struct V_21 * V_22 ;
long V_23 , V_5 ;
V_23 = V_3 -> V_14 * ( V_24 - V_25 ) ;
V_5 = F_1 ( V_23 , V_3 ) ;
do {
if ( V_5 > 0 )
break;
if ( F_3 ( & V_5 , V_5 - V_23 , V_3 ) )
return;
} while ( 1 );
F_12 (waiter, next, &sem->read_wait, list) {
V_22 = V_19 -> V_26 ;
F_13 () ;
V_19 -> V_26 = NULL ;
F_14 ( V_22 ) ;
F_15 ( V_22 ) ;
}
F_10 ( & V_3 -> V_16 ) ;
V_3 -> V_14 = 0 ;
}
static inline int F_16 ( struct V_2 * V_3 )
{
long V_5 = F_1 ( V_24 , V_3 ) ;
do {
if ( ( V_5 & V_27 ) == V_24 )
return 1 ;
if ( F_3 ( & V_5 , V_5 - V_24 , V_3 ) )
return 0 ;
} while ( 1 );
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
V_19 = F_18 ( V_3 -> V_17 . V_20 , struct V_18 , V_28 ) ;
F_14 ( V_19 -> V_26 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
if ( ! F_20 ( & V_3 -> V_17 ) )
F_17 ( V_3 ) ;
else if ( ! F_20 ( & V_3 -> V_16 ) )
F_11 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
unsigned long V_29 ;
F_22 ( & V_3 -> V_15 , V_29 ) ;
F_19 ( V_3 ) ;
F_23 ( & V_3 -> V_15 , V_29 ) ;
}
static struct V_2 T_1 *
F_24 ( struct V_2 * V_3 , long V_5 , long V_30 )
{
struct V_18 V_19 ;
struct V_21 * V_22 = V_31 ;
long V_23 = - V_24 + V_25 ;
F_25 ( & V_3 -> V_15 ) ;
do {
if ( F_3 ( & V_5 , V_5 + V_23 , V_3 ) )
break;
if ( V_5 > 0 ) {
F_26 ( & V_3 -> V_15 ) ;
return V_3 ;
}
} while ( 1 );
F_27 ( & V_19 . V_28 , & V_3 -> V_16 ) ;
V_3 -> V_14 ++ ;
V_19 . V_26 = V_22 ;
F_28 ( V_22 ) ;
if ( ( V_5 & V_27 ) == 0 )
F_19 ( V_3 ) ;
F_26 ( & V_3 -> V_15 ) ;
for (; ; ) {
F_29 ( V_22 , V_32 ) ;
if ( ! V_19 . V_26 )
break;
if ( ! V_30 )
break;
V_30 = F_30 ( V_30 ) ;
}
F_31 ( V_22 , V_33 ) ;
if ( ! V_30 ) {
F_25 ( & V_3 -> V_15 ) ;
if ( V_19 . V_26 ) {
F_1 ( - V_25 , V_3 ) ;
F_32 ( & V_19 . V_28 ) ;
F_26 ( & V_3 -> V_15 ) ;
F_15 ( V_19 . V_26 ) ;
return NULL ;
}
F_26 ( & V_3 -> V_15 ) ;
}
return V_3 ;
}
static struct V_2 T_1 *
F_33 ( struct V_2 * V_3 , long V_5 , long V_30 )
{
struct V_18 V_19 ;
struct V_21 * V_22 = V_31 ;
long V_23 = - V_24 ;
int V_34 = 0 ;
F_25 ( & V_3 -> V_15 ) ;
do {
if ( F_3 ( & V_5 , V_5 + V_23 , V_3 ) )
break;
if ( ( V_5 & V_27 ) == V_24 ) {
F_26 ( & V_3 -> V_15 ) ;
return V_3 ;
}
} while ( 1 );
F_27 ( & V_19 . V_28 , & V_3 -> V_17 ) ;
V_19 . V_26 = V_22 ;
F_29 ( V_22 , V_32 ) ;
for (; ; ) {
if ( ! V_30 )
break;
F_26 ( & V_3 -> V_15 ) ;
V_30 = F_30 ( V_30 ) ;
F_25 ( & V_3 -> V_15 ) ;
F_29 ( V_22 , V_32 ) ;
if ( ( V_34 = F_16 ( V_3 ) ) )
break;
}
if ( ! V_34 )
F_1 ( - V_25 , V_3 ) ;
F_32 ( & V_19 . V_28 ) ;
F_26 ( & V_3 -> V_15 ) ;
F_31 ( V_22 , V_33 ) ;
if ( ! V_34 )
return NULL ;
return V_3 ;
}
static inline int F_34 ( struct V_2 * V_3 ,
int V_35 , long V_30 )
{
long V_5 ;
F_35 ( V_3 , V_35 , 0 , V_36 ) ;
V_5 = F_1 ( V_37 , V_3 ) ;
if ( V_5 <= 0 ) {
F_36 ( V_3 , V_38 ) ;
if ( ! F_24 ( V_3 , V_5 , V_30 ) ) {
F_37 ( V_3 , 1 , V_36 ) ;
return 0 ;
}
}
F_36 ( V_3 , V_39 ) ;
return 1 ;
}
static inline int F_38 ( struct V_2 * V_3 ,
int V_35 , long V_30 )
{
long V_5 ;
F_39 ( V_3 , V_35 , 0 , V_36 ) ;
V_5 = F_1 ( V_40 , V_3 ) ;
if ( ( V_5 & V_27 ) != V_24 ) {
F_36 ( V_3 , V_38 ) ;
if ( ! F_33 ( V_3 , V_5 , V_30 ) ) {
F_37 ( V_3 , 1 , V_36 ) ;
return 0 ;
}
}
F_36 ( V_3 , V_39 ) ;
return 1 ;
}
int T_1 F_40 ( struct V_2 * V_3 , long V_30 )
{
F_41 () ;
return F_34 ( V_3 , 0 , V_30 ) ;
}
int F_42 ( struct V_2 * V_3 )
{
long V_5 = V_3 -> V_5 ;
while ( V_5 >= 0 ) {
if ( F_3 ( & V_5 , V_5 + V_37 , V_3 ) ) {
F_35 ( V_3 , 0 , 1 , V_36 ) ;
F_36 ( V_3 , V_39 ) ;
return 1 ;
}
}
return 0 ;
}
int T_1 F_43 ( struct V_2 * V_3 , long V_30 )
{
F_41 () ;
return F_38 ( V_3 , 0 , V_30 ) ;
}
int F_44 ( struct V_2 * V_3 )
{
long V_5 = V_3 -> V_5 ;
while ( ( V_5 & V_27 ) == 0 ) {
if ( F_3 ( & V_5 , V_5 + V_40 , V_3 ) ) {
F_39 ( V_3 , 0 , 1 , V_36 ) ;
F_36 ( V_3 , V_39 ) ;
return 1 ;
}
}
return 0 ;
}
void F_45 ( struct V_2 * V_3 )
{
long V_5 ;
F_37 ( V_3 , 1 , V_36 ) ;
V_5 = F_1 ( - V_37 , V_3 ) ;
if ( V_5 < 0 && ( V_5 & V_27 ) == 0 )
F_21 ( V_3 ) ;
}
void F_46 ( struct V_2 * V_3 )
{
long V_5 ;
F_37 ( V_3 , 1 , V_36 ) ;
V_5 = F_1 ( - V_40 , V_3 ) ;
if ( V_5 < 0 )
F_21 ( V_3 ) ;
}
int F_47 ( struct V_2 * V_3 , int V_35 , long V_30 )
{
F_41 () ;
return F_34 ( V_3 , V_35 , V_30 ) ;
}
int F_48 ( struct V_2 * V_3 , int V_35 ,
long V_30 )
{
F_41 () ;
return F_38 ( V_3 , V_35 , V_30 ) ;
}
