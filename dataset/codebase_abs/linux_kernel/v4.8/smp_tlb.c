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
static bool F_15 ( void )
{
asm("mcr p15, 0, %0, c8, c3, 1" : : "r" (0));
F_16 ( V_10 ) ;
return false ;
}
static bool F_17 ( void )
{
asm("mcr p15, 0, %0, c8, c3, 1" : : "r" (0));
F_16 ( V_10 ) ;
return true ;
}
void F_18 ( void )
{
unsigned int V_11 = F_19 () ;
unsigned int V_12 = F_20 ( V_13 ) ;
if ( ( V_11 & 0xff0ffff0 ) == 0x420f00f0 && V_11 <= 0x420f00f2 ) {
V_14 = F_17 ;
} else if ( ( V_11 & 0xff0ffff0 ) == 0x410fc0f0 && V_11 < 0x412fc0f2 ) {
V_14 = F_17 ;
} else if ( ( V_11 & 0xff0ffff0 ) == 0x410fc0f0 && V_11 < 0x412fc0f4 ) {
if ( V_12 & 0x10 )
V_14 =
F_15 ;
else
V_14 =
F_17 ;
} else if ( ( V_11 & 0xff0ffff0 ) == 0x410fc0f0 && V_11 < 0x413fc0f3 ) {
if ( ( V_12 & 0x210 ) == 0 )
V_14 =
F_17 ;
else if ( V_12 & 0x10 )
V_14 =
F_15 ;
} else if ( ( V_11 & 0xff0ffff0 ) == 0x410fc0f0 && V_11 < 0x414fc0f0 ) {
if ( ( V_12 & 0x200 ) == 0 )
V_14 =
F_15 ;
}
}
static void F_21 ( void * V_2 )
{
F_22 () ;
}
static void F_23 ( void )
{
if ( ! F_24 () )
return;
F_25 ( F_21 , NULL , 1 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
int V_15 ;
T_1 V_16 = { V_17 } ;
if ( ! F_24 () )
return;
V_15 = F_27 () ;
F_28 ( V_15 , V_4 , & V_16 ) ;
F_29 ( & V_16 , F_21 , NULL , 1 ) ;
F_30 () ;
}
void F_31 ( void )
{
if ( F_32 () )
F_33 ( F_1 , NULL , 1 ) ;
else
F_34 () ;
F_23 () ;
}
void F_35 ( struct V_3 * V_4 )
{
if ( F_32 () )
F_36 ( F_37 ( V_4 ) , F_3 , V_4 , 1 ) ;
else
F_38 ( V_4 ) ;
F_26 ( V_4 ) ;
}
void F_39 ( struct V_18 * V_19 , unsigned long V_20 )
{
if ( F_32 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_19 ;
V_6 . V_8 = V_20 ;
F_36 ( F_37 ( V_19 -> V_21 ) , F_5 ,
& V_6 , 1 ) ;
} else
F_40 ( V_19 , V_20 ) ;
F_26 ( V_19 -> V_21 ) ;
}
void F_41 ( unsigned long V_22 )
{
if ( F_32 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_22 ;
F_33 ( F_7 , & V_6 , 1 ) ;
} else
F_42 ( V_22 ) ;
F_23 () ;
}
void F_43 ( struct V_18 * V_19 ,
unsigned long V_23 , unsigned long V_24 )
{
if ( F_32 () ) {
struct V_5 V_6 ;
V_6 . V_7 = V_19 ;
V_6 . V_8 = V_23 ;
V_6 . V_9 = V_24 ;
F_36 ( F_37 ( V_19 -> V_21 ) , F_9 ,
& V_6 , 1 ) ;
} else
F_10 ( V_19 , V_23 , V_24 ) ;
F_26 ( V_19 -> V_21 ) ;
}
void F_44 ( unsigned long V_23 , unsigned long V_24 )
{
if ( F_32 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_23 ;
V_6 . V_9 = V_24 ;
F_33 ( F_11 , & V_6 , 1 ) ;
} else
F_12 ( V_23 , V_24 ) ;
F_23 () ;
}
void F_45 ( void )
{
if ( F_32 () )
F_33 ( F_13 , NULL , 1 ) ;
else
F_46 () ;
}
