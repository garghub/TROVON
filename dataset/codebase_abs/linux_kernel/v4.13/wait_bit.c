T_1 * F_1 ( void * V_1 , int V_2 )
{
const int V_3 = V_4 == 32 ? 5 : 6 ;
unsigned long V_5 = ( unsigned long ) V_1 << V_3 | V_2 ;
return V_6 + F_2 ( V_5 , V_7 ) ;
}
int F_3 ( struct V_8 * V_9 , unsigned V_10 , int V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 = F_4 ( V_9 , struct V_15 , V_9 ) ;
if ( V_16 -> V_14 . V_17 != V_14 -> V_17 ||
V_16 -> V_14 . V_18 != V_14 -> V_18 ||
F_5 ( V_14 -> V_18 , V_14 -> V_17 ) )
return 0 ;
else
return F_6 ( V_9 , V_10 , V_11 , V_14 ) ;
}
int T_2
F_7 ( struct V_19 * V_20 , struct V_15 * V_21 ,
T_3 * V_22 , unsigned V_10 )
{
int V_23 = 0 ;
do {
F_8 ( V_20 , & V_21 -> V_9 , V_10 ) ;
if ( F_5 ( V_21 -> V_14 . V_18 , V_21 -> V_14 . V_17 ) )
V_23 = (* V_22)( & V_21 -> V_14 , V_10 ) ;
} while ( F_5 ( V_21 -> V_14 . V_18 , V_21 -> V_14 . V_17 ) && ! V_23 );
F_9 ( V_20 , & V_21 -> V_9 ) ;
return V_23 ;
}
int T_2 F_10 ( void * V_1 , int V_2 ,
T_3 * V_22 , unsigned V_10 )
{
struct V_19 * V_20 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_9 , V_1 , V_2 ) ;
return F_7 ( V_20 , & V_9 , V_22 , V_10 ) ;
}
int T_2 F_12 (
void * V_1 , int V_2 , T_3 * V_22 ,
unsigned V_10 , unsigned long V_24 )
{
struct V_19 * V_20 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_9 , V_1 , V_2 ) ;
V_9 . V_14 . V_24 = V_25 + V_24 ;
return F_7 ( V_20 , & V_9 , V_22 , V_10 ) ;
}
int T_2
F_13 ( struct V_19 * V_20 , struct V_15 * V_21 ,
T_3 * V_22 , unsigned V_10 )
{
int V_23 = 0 ;
for (; ; ) {
F_14 ( V_20 , & V_21 -> V_9 , V_10 ) ;
if ( F_5 ( V_21 -> V_14 . V_18 , V_21 -> V_14 . V_17 ) ) {
V_23 = V_22 ( & V_21 -> V_14 , V_10 ) ;
if ( V_23 )
F_9 ( V_20 , & V_21 -> V_9 ) ;
}
if ( ! F_15 ( V_21 -> V_14 . V_18 , V_21 -> V_14 . V_17 ) ) {
if ( ! V_23 )
F_9 ( V_20 , & V_21 -> V_9 ) ;
return 0 ;
} else if ( V_23 ) {
return V_23 ;
}
}
}
int T_2 F_16 ( void * V_1 , int V_2 ,
T_3 * V_22 , unsigned V_10 )
{
struct V_19 * V_20 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_9 , V_1 , V_2 ) ;
return F_13 ( V_20 , & V_9 , V_22 , V_10 ) ;
}
void F_17 ( struct V_19 * V_20 , void * V_1 , int V_2 )
{
struct V_13 V_14 = F_18 ( V_1 , V_2 ) ;
if ( F_19 ( V_20 ) )
F_20 ( V_20 , V_26 , 1 , & V_14 ) ;
}
void F_21 ( void * V_1 , int V_2 )
{
F_17 ( F_1 ( V_1 , V_2 ) , V_1 , V_2 ) ;
}
static inline T_1 * F_22 ( T_4 * V_27 )
{
if ( V_4 == 64 ) {
unsigned long V_28 = ( unsigned long ) V_27 ;
return F_1 ( ( void * ) ( V_28 & ~ 1 ) , V_28 & 1 ) ;
}
return F_1 ( V_27 , 0 ) ;
}
static int F_23 ( struct V_8 * V_9 , unsigned V_10 , int V_11 ,
void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 = F_4 ( V_9 , struct V_15 , V_9 ) ;
T_4 * V_5 = V_14 -> V_17 ;
if ( V_16 -> V_14 . V_17 != V_14 -> V_17 ||
V_16 -> V_14 . V_18 != V_14 -> V_18 ||
F_24 ( V_5 ) != 0 )
return 0 ;
return F_6 ( V_9 , V_10 , V_11 , V_14 ) ;
}
static T_2
int F_25 ( struct V_19 * V_20 , struct V_15 * V_21 ,
int (* V_22)( T_4 * ) , unsigned V_10 )
{
T_4 * V_5 ;
int V_23 = 0 ;
do {
F_8 ( V_20 , & V_21 -> V_9 , V_10 ) ;
V_5 = V_21 -> V_14 . V_17 ;
if ( F_24 ( V_5 ) == 0 )
break;
V_23 = (* V_22)( V_5 ) ;
} while ( ! V_23 && F_24 ( V_5 ) != 0 );
F_9 ( V_20 , & V_21 -> V_9 ) ;
return V_23 ;
}
T_2 int F_26 ( T_4 * V_27 , int (* V_22)( T_4 * ) ,
unsigned V_10 )
{
struct V_19 * V_20 = F_22 ( V_27 ) ;
F_27 ( V_9 , V_27 ) ;
return F_25 ( V_20 , & V_9 , V_22 , V_10 ) ;
}
void F_28 ( T_4 * V_27 )
{
F_17 ( F_22 ( V_27 ) , V_27 , V_29 ) ;
}
T_2 int F_29 ( struct V_13 * V_1 , int V_10 )
{
F_30 () ;
if ( F_31 ( V_10 , V_30 ) )
return - V_31 ;
return 0 ;
}
T_2 int F_32 ( struct V_13 * V_1 , int V_10 )
{
F_33 () ;
if ( F_31 ( V_10 , V_30 ) )
return - V_31 ;
return 0 ;
}
T_2 int F_34 ( struct V_13 * V_1 , int V_10 )
{
unsigned long V_32 = F_35 ( V_25 ) ;
if ( F_36 ( V_32 , V_1 -> V_24 ) )
return - V_33 ;
F_37 ( V_1 -> V_24 - V_32 ) ;
if ( F_31 ( V_10 , V_30 ) )
return - V_31 ;
return 0 ;
}
T_2 int F_38 ( struct V_13 * V_1 , int V_10 )
{
unsigned long V_32 = F_35 ( V_25 ) ;
if ( F_36 ( V_32 , V_1 -> V_24 ) )
return - V_33 ;
F_39 ( V_1 -> V_24 - V_32 ) ;
if ( F_31 ( V_10 , V_30 ) )
return - V_31 ;
return 0 ;
}
void T_5 F_40 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_41 ( V_6 + V_34 ) ;
}
