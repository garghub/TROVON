static inline void F_1 ( void * V_1 )
{
F_2 () ;
}
static inline void F_3 ( void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_4 ( V_4 ) ;
}
static inline void F_5 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_6 ( V_6 -> V_7 , V_6 -> V_8 ) ;
}
static inline void F_7 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_8 ( V_6 -> V_8 ) ;
}
static inline void F_9 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_10 ( V_6 -> V_7 , V_6 -> V_8 , V_6 -> V_9 ) ;
}
static inline void F_11 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_12 ( V_6 -> V_8 , V_6 -> V_9 ) ;
}
void F_13 ( void )
{
if ( F_14 () )
F_15 ( F_1 , NULL , 1 ) ;
else
F_2 () ;
}
void F_16 ( struct V_3 * V_4 )
{
if ( F_14 () )
F_17 ( F_18 ( V_4 ) , F_3 , V_4 , 1 ) ;
else
F_4 ( V_4 ) ;
}
void F_19 ( struct V_10 * V_11 , unsigned long V_12 )
{
if ( F_14 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_11 ;
V_6 . V_8 = V_12 ;
F_17 ( F_18 ( V_11 -> V_13 ) , F_5 ,
& V_6 , 1 ) ;
} else
F_6 ( V_11 , V_12 ) ;
}
void F_20 ( unsigned long V_14 )
{
if ( F_14 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_14 ;
F_15 ( F_7 , & V_6 , 1 ) ;
} else
F_8 ( V_14 ) ;
}
void F_21 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_16 )
{
if ( F_14 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_11 ;
V_6 . V_8 = V_15 ;
V_6 . V_9 = V_16 ;
F_17 ( F_18 ( V_11 -> V_13 ) , F_9 ,
& V_6 , 1 ) ;
} else
F_10 ( V_11 , V_15 , V_16 ) ;
}
void F_22 ( unsigned long V_15 , unsigned long V_16 )
{
if ( F_14 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_15 ;
V_6 . V_9 = V_16 ;
F_15 ( F_11 , & V_6 , 1 ) ;
} else
F_12 ( V_15 , V_16 ) ;
}
