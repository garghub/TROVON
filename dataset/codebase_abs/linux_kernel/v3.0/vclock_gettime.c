T_1 static long F_1 ( long clock , struct V_1 * V_2 )
{
long V_3 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return V_3 ;
}
T_1 static inline long F_2 ( void )
{
long V_4 ;
T_2 (* F_3)( void );
F_3 = V_5 -> clock . F_3 ;
V_4 = ( F_3 () - V_5 -> clock . V_6 ) & V_5 -> clock . V_7 ;
return ( V_4 * V_5 -> clock . V_8 ) >> V_5 -> clock . V_9 ;
}
T_1 static T_3 int F_4 ( struct V_1 * V_2 )
{
unsigned long V_10 , V_11 ;
do {
V_10 = F_5 ( & V_5 -> V_12 ) ;
V_2 -> V_13 = V_5 -> V_14 ;
V_2 -> V_15 = V_5 -> V_16 ;
V_11 = F_2 () ;
} while ( F_6 ( F_7 ( & V_5 -> V_12 , V_10 ) ) );
F_8 ( V_2 , V_11 ) ;
return 0 ;
}
T_1 static T_3 int F_9 ( struct V_1 * V_2 )
{
unsigned long V_10 , V_11 , V_17 ;
do {
V_10 = F_5 ( & V_5 -> V_12 ) ;
V_17 = V_5 -> V_14 ;
V_11 = V_5 -> V_16 + F_2 () ;
V_17 += V_5 -> V_18 . V_13 ;
V_11 += V_5 -> V_18 . V_15 ;
} while ( F_6 ( F_7 ( & V_5 -> V_12 , V_10 ) ) );
while ( V_11 >= V_19 ) {
V_11 -= V_19 ;
++ V_17 ;
}
V_2 -> V_13 = V_17 ;
V_2 -> V_15 = V_11 ;
return 0 ;
}
T_1 static T_3 int F_10 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
do {
V_10 = F_5 ( & V_5 -> V_12 ) ;
V_2 -> V_13 = V_5 -> V_20 . V_13 ;
V_2 -> V_15 = V_5 -> V_20 . V_15 ;
} while ( F_6 ( F_7 ( & V_5 -> V_12 , V_10 ) ) );
return 0 ;
}
T_1 static T_3 int F_11 ( struct V_1 * V_2 )
{
unsigned long V_10 , V_11 , V_17 ;
do {
V_10 = F_5 ( & V_5 -> V_12 ) ;
V_17 = V_5 -> V_20 . V_13 ;
V_11 = V_5 -> V_20 . V_15 ;
V_17 += V_5 -> V_18 . V_13 ;
V_11 += V_5 -> V_18 . V_15 ;
} while ( F_6 ( F_7 ( & V_5 -> V_12 , V_10 ) ) );
if ( V_11 >= V_19 ) {
V_11 -= V_19 ;
++ V_17 ;
}
V_2 -> V_13 = V_17 ;
V_2 -> V_15 = V_11 ;
return 0 ;
}
T_1 int F_12 ( T_4 clock , struct V_1 * V_2 )
{
if ( F_13 ( V_5 -> V_21 ) )
switch ( clock ) {
case V_22 :
if ( F_13 ( V_5 -> clock . F_3 ) )
return F_4 ( V_2 ) ;
break;
case V_23 :
if ( F_13 ( V_5 -> clock . F_3 ) )
return F_9 ( V_2 ) ;
break;
case V_24 :
return F_10 ( V_2 ) ;
case V_25 :
return F_11 ( V_2 ) ;
}
return F_1 ( clock , V_2 ) ;
}
T_1 int F_14 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
long V_3 ;
if ( F_13 ( V_5 -> V_21 && V_5 -> clock . F_3 ) ) {
if ( F_13 ( V_27 != NULL ) ) {
F_15 ( F_16 ( struct V_26 , V_30 ) !=
F_16 ( struct V_1 , V_15 ) ||
sizeof( * V_27 ) != sizeof( struct V_1 ) ) ;
F_4 ( (struct V_1 * ) V_27 ) ;
V_27 -> V_30 /= 1000 ;
}
if ( F_6 ( V_29 != NULL ) ) {
V_29 -> V_31 = V_5 -> V_32 . V_31 ;
V_29 -> V_33 = V_5 -> V_32 . V_33 ;
}
return 0 ;
}
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_3 ;
}
static T_5 long F_17 ( long * V_34 )
{
long V_17 ;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time), "D" (t) : "cc", "r11", "cx", "memory");
return V_17 ;
}
T_1 T_6 F_18 ( T_6 * V_34 )
{
T_6 V_35 ;
if ( F_6 ( ! F_19 ( V_36 ) . V_21 ) )
return F_17 ( V_34 ) ;
V_35 = F_20 ( F_19 ( V_36 ) . V_14 ) ;
if ( V_34 )
* V_34 = V_35 ;
return V_35 ;
}
