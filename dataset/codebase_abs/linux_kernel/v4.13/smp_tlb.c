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
unsigned int V_7 = F_6 () ;
F_7 ( V_6 -> V_8 , V_6 -> V_9 ) ;
F_8 ( V_7 ) ;
}
static inline void F_9 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_10 ( V_6 -> V_9 ) ;
}
static inline void F_11 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
unsigned int V_7 = F_6 () ;
F_12 ( V_6 -> V_8 , V_6 -> V_9 , V_6 -> V_10 ) ;
F_8 ( V_7 ) ;
}
static inline void F_13 ( void * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_14 ( V_6 -> V_9 , V_6 -> V_10 ) ;
}
static inline void F_15 ( void * V_1 )
{
F_16 () ;
}
static bool F_17 ( void )
{
asm("mcr p15, 0, %0, c8, c3, 1" : : "r" (0));
F_18 ( V_11 ) ;
return false ;
}
static bool F_19 ( void )
{
asm("mcr p15, 0, %0, c8, c3, 1" : : "r" (0));
F_18 ( V_11 ) ;
return true ;
}
void F_20 ( void )
{
unsigned int V_12 = F_21 () ;
unsigned int V_13 = F_22 ( V_14 ) ;
if ( ( V_12 & 0xff0ffff0 ) == 0x420f00f0 && V_12 <= 0x420f00f2 ) {
V_15 = F_19 ;
} else if ( ( V_12 & 0xff0ffff0 ) == 0x410fc0f0 && V_12 < 0x412fc0f2 ) {
V_15 = F_19 ;
} else if ( ( V_12 & 0xff0ffff0 ) == 0x410fc0f0 && V_12 < 0x412fc0f4 ) {
if ( V_13 & 0x10 )
V_15 =
F_17 ;
else
V_15 =
F_19 ;
} else if ( ( V_12 & 0xff0ffff0 ) == 0x410fc0f0 && V_12 < 0x413fc0f3 ) {
if ( ( V_13 & 0x210 ) == 0 )
V_15 =
F_19 ;
else if ( V_13 & 0x10 )
V_15 =
F_17 ;
} else if ( ( V_12 & 0xff0ffff0 ) == 0x410fc0f0 && V_12 < 0x414fc0f0 ) {
if ( ( V_13 & 0x200 ) == 0 )
V_15 =
F_17 ;
}
}
static void F_23 ( void * V_2 )
{
F_24 () ;
}
static void F_25 ( void )
{
if ( ! F_26 () )
return;
F_27 ( F_23 , NULL , 1 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
int V_16 ;
T_1 V_17 = { V_18 } ;
if ( ! F_26 () )
return;
V_16 = F_29 () ;
F_30 ( V_16 , V_4 , & V_17 ) ;
F_31 ( & V_17 , F_23 , NULL , 1 ) ;
F_32 () ;
}
void F_33 ( void )
{
if ( F_34 () )
F_35 ( F_1 , NULL , 1 ) ;
else
F_36 () ;
F_25 () ;
}
void F_37 ( struct V_3 * V_4 )
{
if ( F_34 () )
F_38 ( F_39 ( V_4 ) , F_3 , V_4 , 1 ) ;
else
F_40 ( V_4 ) ;
F_28 ( V_4 ) ;
}
void F_41 ( struct V_19 * V_20 , unsigned long V_21 )
{
if ( F_34 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_20 ;
V_6 . V_9 = V_21 ;
F_38 ( F_39 ( V_20 -> V_22 ) , F_5 ,
& V_6 , 1 ) ;
} else
F_42 ( V_20 , V_21 ) ;
F_28 ( V_20 -> V_22 ) ;
}
void F_43 ( unsigned long V_23 )
{
if ( F_34 () ) {
struct V_5 V_6 ;
V_6 . V_9 = V_23 ;
F_35 ( F_9 , & V_6 , 1 ) ;
} else
F_44 ( V_23 ) ;
F_25 () ;
}
void F_45 ( struct V_19 * V_20 ,
unsigned long V_24 , unsigned long V_25 )
{
if ( F_34 () ) {
struct V_5 V_6 ;
V_6 . V_8 = V_20 ;
V_6 . V_9 = V_24 ;
V_6 . V_10 = V_25 ;
F_38 ( F_39 ( V_20 -> V_22 ) , F_11 ,
& V_6 , 1 ) ;
} else
F_12 ( V_20 , V_24 , V_25 ) ;
F_28 ( V_20 -> V_22 ) ;
}
void F_46 ( unsigned long V_24 , unsigned long V_25 )
{
if ( F_34 () ) {
struct V_5 V_6 ;
V_6 . V_9 = V_24 ;
V_6 . V_10 = V_25 ;
F_35 ( F_13 , & V_6 , 1 ) ;
} else
F_14 ( V_24 , V_25 ) ;
F_25 () ;
}
void F_47 ( void )
{
if ( F_34 () )
F_35 ( F_15 , NULL , 1 ) ;
else
F_48 () ;
}
