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
T_1 static long F_10 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_1 ;
}
T_1 static inline long F_11 ( void )
{
long V_13 ;
T_4 V_14 ;
if ( V_15 -> clock . V_16 == V_17 )
V_14 = F_1 () ;
else if ( V_15 -> clock . V_16 == V_18 )
V_14 = F_6 () ;
else
return 0 ;
V_13 = ( V_14 - V_15 -> clock . V_4 ) & V_15 -> clock . V_19 ;
return ( V_13 * V_15 -> clock . V_20 ) >> V_15 -> clock . V_21 ;
}
T_1 static int T_5 F_12 ( struct V_7 * V_8 )
{
unsigned long V_22 , V_23 ;
int V_24 ;
do {
V_22 = F_13 ( & V_15 -> V_22 ) ;
V_24 = V_15 -> clock . V_16 ;
V_8 -> V_25 = V_15 -> V_26 ;
V_8 -> V_27 = V_15 -> V_28 ;
V_23 = F_11 () ;
} while ( F_14 ( F_15 ( & V_15 -> V_22 , V_22 ) ) );
F_16 ( V_8 , V_23 ) ;
return V_24 ;
}
T_1 static int F_17 ( struct V_7 * V_8 )
{
unsigned long V_22 , V_23 ;
int V_24 ;
do {
V_22 = F_13 ( & V_15 -> V_22 ) ;
V_24 = V_15 -> clock . V_16 ;
V_8 -> V_25 = V_15 -> V_29 ;
V_8 -> V_27 = V_15 -> V_30 ;
V_23 = F_11 () ;
} while ( F_14 ( F_15 ( & V_15 -> V_22 , V_22 ) ) );
F_16 ( V_8 , V_23 ) ;
return V_24 ;
}
T_1 static int F_18 ( struct V_7 * V_8 )
{
unsigned long V_22 ;
do {
V_22 = F_13 ( & V_15 -> V_22 ) ;
V_8 -> V_25 = V_15 -> V_31 . V_25 ;
V_8 -> V_27 = V_15 -> V_31 . V_27 ;
} while ( F_14 ( F_15 ( & V_15 -> V_22 , V_22 ) ) );
return 0 ;
}
T_1 static int F_19 ( struct V_7 * V_8 )
{
unsigned long V_22 ;
do {
V_22 = F_13 ( & V_15 -> V_22 ) ;
V_8 -> V_25 = V_15 -> V_32 . V_25 ;
V_8 -> V_27 = V_15 -> V_32 . V_27 ;
} while ( F_14 ( F_15 ( & V_15 -> V_22 , V_22 ) ) );
return 0 ;
}
T_1 int F_20 ( T_6 clock , struct V_7 * V_8 )
{
int V_1 = V_33 ;
switch ( clock ) {
case V_34 :
V_1 = F_12 ( V_8 ) ;
break;
case V_35 :
V_1 = F_17 ( V_8 ) ;
break;
case V_36 :
return F_18 ( V_8 ) ;
case V_37 :
return F_19 ( V_8 ) ;
}
if ( V_1 == V_33 )
return F_9 ( clock , V_8 ) ;
return 0 ;
}
T_1 int F_21 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
long V_1 = V_33 ;
if ( F_5 ( V_10 != NULL ) ) {
F_22 ( F_23 ( struct V_9 , V_38 ) !=
F_23 ( struct V_7 , V_27 ) ||
sizeof( * V_10 ) != sizeof( struct V_7 ) ) ;
V_1 = F_12 ( (struct V_7 * ) V_10 ) ;
V_10 -> V_38 /= 1000 ;
}
if ( F_14 ( V_12 != NULL ) ) {
V_12 -> V_39 = V_15 -> V_40 . V_39 ;
V_12 -> V_41 = V_15 -> V_40 . V_41 ;
}
if ( V_1 == V_33 )
return F_10 ( V_10 , V_12 ) ;
return 0 ;
}
T_1 T_7 F_24 ( T_7 * V_42 )
{
T_7 V_43 = F_25 ( F_4 ( V_3 ) . V_26 ) ;
if ( V_42 )
* V_42 = V_43 ;
return V_43 ;
}
