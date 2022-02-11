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
static inline void F_13 ( void * V_1 )
{
F_14 () ;
}
static int F_15 ( void )
{
unsigned int V_10 = F_16 () ;
if ( ( V_10 & 0xff0ffff0 ) != 0x410fc0f0 || V_10 > 0x413fc0f2 )
return 0 ;
return 1 ;
}
static int F_15 ( void )
{
return 0 ;
}
static void F_17 ( void * V_2 )
{
F_18 () ;
}
static void F_19 ( void )
{
if ( ! F_15 () )
return;
F_20 () ;
F_21 ( V_11 , F_17 ,
NULL , 1 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
int V_12 ;
T_1 V_13 = { V_14 } ;
if ( ! F_15 () )
return;
F_20 () ;
F_23 (cpu) {
if ( V_12 == F_24 () )
continue;
if ( F_25 ( & V_4 -> V_15 . V_16 ) ==
F_25 ( & F_26 ( V_17 , V_12 ) ) )
F_27 ( V_12 , & V_13 ) ;
}
F_21 ( & V_13 , F_17 , NULL , 1 ) ;
}
void F_28 ( void )
{
if ( F_29 () )
F_30 ( F_1 , NULL , 1 ) ;
else
F_2 () ;
F_19 () ;
}
void F_31 ( struct V_3 * V_4 )
{
if ( F_29 () )
F_32 ( F_33 ( V_4 ) , F_3 , V_4 , 1 ) ;
else
F_4 ( V_4 ) ;
F_22 ( V_4 ) ;
}
void F_34 ( struct V_18 * V_19 , unsigned long V_20 )
{
if ( F_29 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_19 ;
V_6 . V_8 = V_20 ;
F_32 ( F_33 ( V_19 -> V_21 ) , F_5 ,
& V_6 , 1 ) ;
} else
F_6 ( V_19 , V_20 ) ;
F_22 ( V_19 -> V_21 ) ;
}
void F_35 ( unsigned long V_22 )
{
if ( F_29 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_22 ;
F_30 ( F_7 , & V_6 , 1 ) ;
} else
F_8 ( V_22 ) ;
F_19 () ;
}
void F_36 ( struct V_18 * V_19 ,
unsigned long V_23 , unsigned long V_24 )
{
if ( F_29 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_19 ;
V_6 . V_8 = V_23 ;
V_6 . V_9 = V_24 ;
F_32 ( F_33 ( V_19 -> V_21 ) , F_9 ,
& V_6 , 1 ) ;
} else
F_10 ( V_19 , V_23 , V_24 ) ;
F_22 ( V_19 -> V_21 ) ;
}
void F_37 ( unsigned long V_23 , unsigned long V_24 )
{
if ( F_29 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_23 ;
V_6 . V_9 = V_24 ;
F_30 ( F_11 , & V_6 , 1 ) ;
} else
F_12 ( V_23 , V_24 ) ;
F_19 () ;
}
void F_38 ( void )
{
if ( F_29 () )
F_30 ( F_13 , NULL , 1 ) ;
else
F_14 () ;
}
