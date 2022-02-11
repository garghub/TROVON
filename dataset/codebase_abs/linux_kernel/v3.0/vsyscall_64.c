void F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 . V_3 , V_1 ) ;
V_2 . V_4 = V_4 ;
F_3 ( & V_2 . V_3 , V_1 ) ;
}
void F_4 ( struct V_5 * V_6 , struct V_5 * V_7 ,
struct V_8 * clock , T_1 V_9 )
{
unsigned long V_1 ;
F_2 ( & V_2 . V_3 , V_1 ) ;
V_2 . clock . V_10 = clock -> V_10 ;
V_2 . clock . V_11 = clock -> V_11 ;
V_2 . clock . V_12 = clock -> V_12 ;
V_2 . clock . V_9 = V_9 ;
V_2 . clock . V_13 = clock -> V_13 ;
V_2 . V_14 = V_6 -> V_15 ;
V_2 . V_16 = V_6 -> V_17 ;
V_2 . V_18 = * V_7 ;
V_2 . V_19 = F_5 () ;
F_3 ( & V_2 . V_3 , V_1 ) ;
}
static T_2 void F_6 ( struct V_20 * V_21 )
{
* V_21 = F_7 ( V_2 ) . V_4 ;
}
static T_2 int F_8 ( struct V_22 * V_23 , struct V_20 * V_21 )
{
int V_24 ;
asm volatile("syscall"
: "=a" (ret)
: "0" (__NR_gettimeofday),"D" (tv),"S" (tz)
: __syscall_clobber );
return V_24 ;
}
static T_2 long F_9 ( long * V_25 )
{
long V_26 ;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time),"D" (t) : __syscall_clobber);
return V_26 ;
}
static T_2 void F_10 ( struct V_22 * V_23 )
{
T_3 V_27 , V_28 , V_12 , V_29 ;
unsigned V_30 ;
unsigned long V_9 , V_13 , V_31 ;
T_3 (* V_10)( void );
do {
V_30 = F_11 ( & F_7 ( V_2 ) . V_3 ) ;
V_10 = F_7 ( V_2 ) . clock . V_10 ;
if ( F_12 ( ! F_7 ( V_2 ) . V_32 ||
! V_10 ) ) {
F_8 ( V_23 , NULL ) ;
return;
}
V_27 = V_10 () ;
V_28 = F_7 ( V_2 ) . clock . V_11 ;
V_12 = F_7 ( V_2 ) . clock . V_12 ;
V_9 = F_7 ( V_2 ) . clock . V_9 ;
V_13 = F_7 ( V_2 ) . clock . V_13 ;
V_23 -> V_15 = F_7 ( V_2 ) . V_14 ;
V_31 = F_7 ( V_2 ) . V_16 ;
} while ( F_13 ( & F_7 ( V_2 ) . V_3 , V_30 ) );
V_29 = ( V_27 - V_28 ) & V_12 ;
V_31 += ( V_29 * V_9 ) >> V_13 ;
while ( V_31 >= V_33 ) {
V_23 -> V_15 += 1 ;
V_31 -= V_33 ;
}
V_23 -> V_34 = V_31 / V_35 ;
}
static void T_4 F_14 ( int V_36 )
{
unsigned long V_37 ;
unsigned long V_38 = 0 ;
#ifdef F_15
V_38 = F_16 ( V_36 ) ;
#endif
if ( F_17 ( & F_18 ( V_36 ) , V_39 ) )
F_19 ( ( V_38 << 12 ) | V_36 ) ;
V_37 = 0x0f40000000000ULL ;
V_37 |= V_36 ;
V_37 |= ( V_38 & 0xf ) << 12 ;
V_37 |= ( V_38 >> 4 ) << 48 ;
F_20 ( F_21 ( V_36 ) , V_40 , & V_37 , V_41 ) ;
}
static void T_4 F_22 ( void * V_42 )
{
F_14 ( F_23 () ) ;
}
static int T_4
F_24 ( struct V_43 * V_44 , unsigned long V_45 , void * V_42 )
{
long V_36 = ( long ) V_42 ;
if ( V_45 == V_46 || V_45 == V_47 )
F_25 ( V_36 , F_22 , NULL , 1 ) ;
return V_48 ;
}
void T_5 F_26 ( void )
{
extern char V_49 ;
unsigned long V_50 = F_27 ( & V_49 ) ;
F_28 ( V_51 , V_50 , V_52 ) ;
}
static int T_5 F_29 ( void )
{
F_30 ( ( ( unsigned long ) & V_53 !=
F_31 ( V_54 ) ) ) ;
F_30 ( ( unsigned long ) & V_55 != F_31 ( V_56 ) ) ;
F_30 ( ( F_31 ( 0 ) != F_32 ( V_51 ) ) ) ;
F_30 ( ( unsigned long ) & V_57 != F_31 ( V_58 ) ) ;
#ifdef F_33
F_34 ( V_59 ) ;
#endif
F_35 ( F_22 , NULL , 1 ) ;
F_36 ( F_24 , 30 ) ;
return 0 ;
}
