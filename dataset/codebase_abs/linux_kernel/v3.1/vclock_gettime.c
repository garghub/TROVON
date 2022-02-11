T_1 static T_2 F_1 ( void )
{
T_2 V_1 ;
T_3 V_2 ;
F_2 () ;
V_1 = ( T_2 ) F_3 () ;
V_2 = F_4 ( V_3 ) . clock . V_4 ;
if ( F_5 ( V_1 >= V_2 ) )
return V_1 ;
asm volatile ("");
return V_2 ;
}
static T_1 T_2 F_6 ( void )
{
return F_7 ( ( const void V_5 * ) F_8 ( V_6 ) + 0xf0 ) ;
}
T_1 static long F_9 ( long clock , struct V_7 * V_8 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return V_1 ;
}
T_1 static inline long F_10 ( void )
{
long V_9 ;
T_4 V_10 ;
if ( V_11 -> clock . V_12 == V_13 )
V_10 = F_1 () ;
else
V_10 = F_6 () ;
V_9 = ( V_10 - V_11 -> clock . V_4 ) & V_11 -> clock . V_14 ;
return ( V_9 * V_11 -> clock . V_15 ) >> V_11 -> clock . V_16 ;
}
T_1 static T_5 int F_11 ( struct V_7 * V_8 )
{
unsigned long V_17 , V_18 ;
do {
V_17 = F_12 ( & V_11 -> V_19 ) ;
V_8 -> V_20 = V_11 -> V_21 ;
V_8 -> V_22 = V_11 -> V_23 ;
V_18 = F_10 () ;
} while ( F_13 ( F_14 ( & V_11 -> V_19 , V_17 ) ) );
F_15 ( V_8 , V_18 ) ;
return 0 ;
}
T_1 static T_5 int F_16 ( struct V_7 * V_8 )
{
unsigned long V_17 , V_18 , V_24 ;
do {
V_17 = F_12 ( & V_11 -> V_19 ) ;
V_24 = V_11 -> V_21 ;
V_18 = V_11 -> V_23 + F_10 () ;
V_24 += V_11 -> V_25 . V_20 ;
V_18 += V_11 -> V_25 . V_22 ;
} while ( F_13 ( F_14 ( & V_11 -> V_19 , V_17 ) ) );
while ( V_18 >= V_26 ) {
V_18 -= V_26 ;
++ V_24 ;
}
V_8 -> V_20 = V_24 ;
V_8 -> V_22 = V_18 ;
return 0 ;
}
T_1 static T_5 int F_17 ( struct V_7 * V_8 )
{
unsigned long V_17 ;
do {
V_17 = F_12 ( & V_11 -> V_19 ) ;
V_8 -> V_20 = V_11 -> V_27 . V_20 ;
V_8 -> V_22 = V_11 -> V_27 . V_22 ;
} while ( F_13 ( F_14 ( & V_11 -> V_19 , V_17 ) ) );
return 0 ;
}
T_1 static T_5 int F_18 ( struct V_7 * V_8 )
{
unsigned long V_17 , V_18 , V_24 ;
do {
V_17 = F_12 ( & V_11 -> V_19 ) ;
V_24 = V_11 -> V_27 . V_20 ;
V_18 = V_11 -> V_27 . V_22 ;
V_24 += V_11 -> V_25 . V_20 ;
V_18 += V_11 -> V_25 . V_22 ;
} while ( F_13 ( F_14 ( & V_11 -> V_19 , V_17 ) ) );
if ( V_18 >= V_26 ) {
V_18 -= V_26 ;
++ V_24 ;
}
V_8 -> V_20 = V_24 ;
V_8 -> V_22 = V_18 ;
return 0 ;
}
T_1 int F_19 ( T_6 clock , struct V_7 * V_8 )
{
switch ( clock ) {
case V_28 :
if ( F_5 ( V_11 -> clock . V_12 != V_29 ) )
return F_11 ( V_8 ) ;
break;
case V_30 :
if ( F_5 ( V_11 -> clock . V_12 != V_29 ) )
return F_16 ( V_8 ) ;
break;
case V_31 :
return F_17 ( V_8 ) ;
case V_32 :
return F_18 ( V_8 ) ;
}
return F_9 ( clock , V_8 ) ;
}
T_1 int F_20 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
long V_1 ;
if ( F_5 ( V_11 -> clock . V_12 != V_29 ) ) {
if ( F_5 ( V_34 != NULL ) ) {
F_21 ( F_22 ( struct V_33 , V_37 ) !=
F_22 ( struct V_7 , V_22 ) ||
sizeof( * V_34 ) != sizeof( struct V_7 ) ) ;
F_11 ( (struct V_7 * ) V_34 ) ;
V_34 -> V_37 /= 1000 ;
}
if ( F_13 ( V_36 != NULL ) ) {
V_36 -> V_38 = V_11 -> V_39 . V_38 ;
V_36 -> V_40 = V_11 -> V_39 . V_40 ;
}
return 0 ;
}
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_1 ;
}
T_1 T_7 F_23 ( T_7 * V_41 )
{
T_7 V_42 = F_24 ( F_4 ( V_3 ) . V_21 ) ;
if ( V_41 )
* V_41 = V_42 ;
return V_42 ;
}
