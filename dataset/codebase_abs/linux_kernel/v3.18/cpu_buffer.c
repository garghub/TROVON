unsigned long F_1 ( void )
{
return V_1 ;
}
void F_2 ( void )
{
struct V_2 * V_3 = F_3 ( & V_4 ) ;
V_3 -> V_5 ++ ;
}
void F_4 ( void )
{
if ( V_6 )
F_5 ( V_6 ) ;
V_6 = NULL ;
}
int F_6 ( void )
{
int V_7 ;
unsigned long V_8 = V_1 ;
unsigned long V_9 = V_8 * ( sizeof( struct V_10 ) +
V_11 ) ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( ! V_6 )
goto V_13;
F_8 (i) {
struct V_2 * V_14 = & F_9 ( V_4 , V_7 ) ;
V_14 -> V_15 = NULL ;
V_14 -> V_16 = - 1 ;
V_14 -> V_17 = 0 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_18 = 0 ;
V_14 -> V_5 = 0 ;
V_14 -> V_19 = 0 ;
V_14 -> V_20 = 0 ;
V_14 -> V_21 = V_7 ;
F_10 ( & V_14 -> V_22 , V_23 ) ;
}
return 0 ;
V_13:
F_4 () ;
return - V_24 ;
}
void F_11 ( void )
{
int V_7 ;
V_25 = 1 ;
F_12 (i) {
struct V_2 * V_14 = & F_9 ( V_4 , V_7 ) ;
F_13 ( V_7 , & V_14 -> V_22 , V_26 + V_7 ) ;
}
}
void F_14 ( void )
{
V_25 = 0 ;
}
void F_15 ( void )
{
int V_7 ;
F_12 (i) {
struct V_2 * V_14 = & F_9 ( V_4 , V_7 ) ;
F_16 ( & V_14 -> V_22 ) ;
}
}
struct V_10
* F_17 ( struct V_27 * V_28 , unsigned long V_29 )
{
V_28 -> V_30 = F_18
( V_6 , sizeof( struct V_10 ) +
V_29 * sizeof( V_28 -> V_31 -> V_32 [ 0 ] ) ) ;
if ( ! V_28 -> V_30 )
return NULL ;
V_28 -> V_31 = F_19 ( V_28 -> V_30 ) ;
V_28 -> V_29 = V_29 ;
V_28 -> V_32 = V_28 -> V_31 -> V_32 ;
return V_28 -> V_31 ;
}
int F_20 ( struct V_27 * V_28 )
{
return F_21 ( V_6 , V_28 -> V_30 ) ;
}
struct V_10 * F_22 ( struct V_27 * V_28 , int V_21 )
{
struct V_33 * V_34 ;
V_34 = F_23 ( V_6 , V_21 , NULL , NULL ) ;
if ( ! V_34 )
return NULL ;
V_28 -> V_30 = V_34 ;
V_28 -> V_31 = F_19 ( V_34 ) ;
V_28 -> V_29 = ( F_24 ( V_34 ) - sizeof( struct V_10 ) )
/ sizeof( V_28 -> V_31 -> V_32 [ 0 ] ) ;
V_28 -> V_32 = V_28 -> V_31 -> V_32 ;
return V_28 -> V_31 ;
}
unsigned long F_25 ( int V_21 )
{
return F_26 ( V_6 , V_21 ) ;
}
static int
F_27 ( struct V_2 * V_3 , unsigned long V_35 ,
int V_36 , struct V_37 * V_38 )
{
struct V_27 V_28 ;
struct V_10 * V_31 ;
unsigned long V_39 ;
int V_29 ;
V_39 = 0 ;
if ( V_35 )
V_39 |= V_40 ;
V_36 = ! ! V_36 ;
if ( V_3 -> V_16 != V_36 ) {
V_3 -> V_16 = V_36 ;
V_39 |= V_41 ;
if ( V_36 )
V_39 |= V_42 ;
}
if ( V_3 -> V_15 != V_38 ) {
V_3 -> V_15 = V_38 ;
V_39 |= V_43 ;
}
if ( ! V_39 )
return 0 ;
if ( V_39 & V_43 )
V_29 = 1 ;
else
V_29 = 0 ;
V_31 = F_17 ( & V_28 , V_29 ) ;
if ( ! V_31 )
return - V_24 ;
V_31 -> V_44 = V_45 ;
V_31 -> V_30 = V_39 ;
if ( V_29 )
F_28 ( & V_28 , ( unsigned long ) V_38 ) ;
F_20 ( & V_28 ) ;
return 0 ;
}
static inline int
F_29 ( struct V_2 * V_3 ,
unsigned long V_46 , unsigned long V_30 )
{
struct V_27 V_28 ;
struct V_10 * V_31 ;
V_31 = F_17 ( & V_28 , 0 ) ;
if ( ! V_31 )
return - V_24 ;
V_31 -> V_44 = V_46 ;
V_31 -> V_30 = V_30 ;
return F_20 ( & V_28 ) ;
}
static int
F_30 ( struct V_2 * V_3 , unsigned long V_46 ,
unsigned long V_35 , int V_36 , unsigned long V_30 ,
struct V_37 * V_38 )
{
struct V_37 * V_47 = V_38 ? V_38 : V_48 ;
V_3 -> V_18 ++ ;
if ( V_46 == V_45 ) {
V_3 -> V_20 ++ ;
return 0 ;
}
if ( F_27 ( V_3 , V_35 , V_36 , V_47 ) )
goto V_13;
if ( F_29 ( V_3 , V_46 , V_30 ) )
goto V_13;
return 1 ;
V_13:
V_3 -> V_5 ++ ;
return 0 ;
}
static inline void F_31 ( struct V_2 * V_3 )
{
V_3 -> V_17 = 1 ;
}
static inline void F_32 ( struct V_2 * V_3 )
{
V_3 -> V_17 = 0 ;
}
static inline void
F_33 ( unsigned long V_46 , struct V_49 * const V_50 ,
unsigned long V_30 , int V_36 ,
struct V_37 * V_38 )
{
struct V_2 * V_3 = F_3 ( & V_4 ) ;
unsigned long V_35 = V_51 ;
if ( ! F_30 ( V_3 , V_46 , V_35 , V_36 , V_30 , V_38 ) )
return;
if ( ! V_35 )
return;
F_31 ( V_3 ) ;
V_52 . V_35 ( V_50 , V_35 ) ;
F_32 ( V_3 ) ;
}
void F_34 ( unsigned long V_46 , struct V_49 * const V_50 ,
unsigned long V_30 , int V_36 ,
struct V_37 * V_38 )
{
F_33 ( V_46 , V_50 , V_30 , V_36 , V_38 ) ;
}
void F_35 ( unsigned long V_46 , struct V_49 * const V_50 ,
unsigned long V_30 , int V_36 )
{
F_33 ( V_46 , V_50 , V_30 , V_36 , NULL ) ;
}
void F_36 ( struct V_49 * const V_50 , unsigned long V_30 )
{
int V_36 ;
unsigned long V_46 ;
if ( F_37 ( V_50 ) ) {
V_36 = ! F_38 ( V_50 ) ;
V_46 = F_39 ( V_50 ) ;
} else {
V_36 = 0 ;
V_46 = V_45 ;
}
F_33 ( V_46 , V_50 , V_30 , V_36 , NULL ) ;
}
void
F_40 ( struct V_27 * V_28 , struct V_49 * const V_50 ,
unsigned long V_46 , int V_53 , int V_29 )
{
struct V_10 * V_31 ;
int V_36 = ! F_38 ( V_50 ) ;
struct V_2 * V_3 = F_3 ( & V_4 ) ;
V_3 -> V_18 ++ ;
if ( F_27 ( V_3 , 0 , V_36 , V_48 ) )
goto V_13;
V_31 = F_17 ( V_28 , V_29 + 2 ) ;
if ( ! V_31 )
goto V_13;
V_31 -> V_44 = V_45 ;
V_31 -> V_30 = 0 ;
F_28 ( V_28 , V_53 ) ;
F_28 ( V_28 , V_46 ) ;
return;
V_13:
V_28 -> V_30 = NULL ;
V_3 -> V_5 ++ ;
}
int F_41 ( struct V_27 * V_28 , unsigned long V_54 )
{
if ( ! V_28 -> V_30 )
return 0 ;
return F_28 ( V_28 , V_54 ) ;
}
int F_42 ( struct V_27 * V_28 , T_1 V_54 )
{
if ( ! V_28 -> V_30 )
return 0 ;
if ( F_43 ( V_28 ) < 2 )
return 0 ;
if ( ! F_28 ( V_28 , ( V_55 ) V_54 ) )
return 0 ;
return F_28 ( V_28 , ( V_55 ) ( V_54 >> 32 ) ) ;
}
int F_44 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_30 )
return - V_56 ;
return F_20 ( V_28 ) ;
}
void F_45 ( unsigned long V_46 , int V_36 , unsigned long V_30 )
{
struct V_2 * V_3 = F_3 ( & V_4 ) ;
F_30 ( V_3 , V_46 , 0 , V_36 , V_30 , NULL ) ;
}
void F_46 ( unsigned long V_46 )
{
struct V_2 * V_3 = F_3 ( & V_4 ) ;
if ( ! V_3 -> V_17 )
return;
if ( V_46 == V_45 )
goto V_13;
if ( F_29 ( V_3 , V_46 , 0 ) )
goto V_13;
return;
V_13:
V_3 -> V_17 = 0 ;
V_3 -> V_19 ++ ;
return;
}
static void V_23 ( struct V_57 * V_22 )
{
struct V_2 * V_14 =
F_47 ( V_22 , struct V_2 , V_22 . V_22 ) ;
if ( V_14 -> V_21 != F_48 () && ! F_49 ( V_14 -> V_21 ) ) {
F_50 ( & V_14 -> V_22 ) ;
return;
}
F_51 ( V_14 -> V_21 ) ;
if ( V_25 )
F_52 ( & V_14 -> V_22 , V_26 ) ;
}
