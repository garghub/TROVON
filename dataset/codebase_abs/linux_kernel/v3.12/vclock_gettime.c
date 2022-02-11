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
return F_7 ( ( const void V_5 * ) F_8 ( V_6 ) + V_7 ) ;
}
static T_1 T_2 F_9 ( int * V_8 )
{
const struct V_9 * V_10 ;
T_2 V_1 ;
T_3 V_2 ;
T_4 V_11 ;
T_5 V_12 ;
unsigned V_13 , V_14 ;
do {
V_13 = F_10 () & V_15 ;
V_10 = F_11 ( V_13 ) ;
V_11 = F_12 ( & V_10 -> V_10 , & V_1 , & V_12 ) ;
V_14 = F_10 () & V_15 ;
} while ( F_13 ( V_13 != V_14 ||
( V_10 -> V_10 . V_11 & 1 ) ||
V_10 -> V_10 . V_11 != V_11 ) );
if ( F_13 ( ! ( V_12 & V_16 ) ) )
* V_8 = V_17 ;
V_2 = F_4 ( V_3 ) . clock . V_4 ;
if ( F_5 ( V_1 >= V_2 ) )
return V_1 ;
return V_2 ;
}
T_1 static long F_14 ( long clock , struct V_18 * V_19 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return V_1 ;
}
T_1 static long F_15 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_1 ;
}
T_1 static inline T_3 F_16 ( int * V_8 )
{
long V_24 ;
T_6 V_25 ;
if ( V_26 -> clock . V_27 == V_28 )
V_25 = F_1 () ;
else if ( V_26 -> clock . V_27 == V_29 )
V_25 = F_6 () ;
#ifdef F_17
else if ( V_26 -> clock . V_27 == V_30 )
V_25 = F_9 ( V_8 ) ;
#endif
else
return 0 ;
V_24 = ( V_25 - V_26 -> clock . V_4 ) & V_26 -> clock . V_31 ;
return V_24 * V_26 -> clock . V_32 ;
}
T_1 static int T_7 F_18 ( struct V_18 * V_19 )
{
unsigned long V_33 ;
T_3 V_34 ;
int V_8 ;
V_19 -> V_35 = 0 ;
do {
V_33 = F_19 ( & V_26 -> V_33 ) ;
V_8 = V_26 -> clock . V_27 ;
V_19 -> V_36 = V_26 -> V_37 ;
V_34 = V_26 -> V_38 ;
V_34 += F_16 ( & V_8 ) ;
V_34 >>= V_26 -> clock . V_39 ;
} while ( F_13 ( F_20 ( & V_26 -> V_33 , V_33 ) ) );
F_21 ( V_19 , V_34 ) ;
return V_8 ;
}
T_1 static int F_22 ( struct V_18 * V_19 )
{
unsigned long V_33 ;
T_3 V_34 ;
int V_8 ;
V_19 -> V_35 = 0 ;
do {
V_33 = F_19 ( & V_26 -> V_33 ) ;
V_8 = V_26 -> clock . V_27 ;
V_19 -> V_36 = V_26 -> V_40 ;
V_34 = V_26 -> V_41 ;
V_34 += F_16 ( & V_8 ) ;
V_34 >>= V_26 -> clock . V_39 ;
} while ( F_13 ( F_20 ( & V_26 -> V_33 , V_33 ) ) );
F_21 ( V_19 , V_34 ) ;
return V_8 ;
}
T_1 static int F_23 ( struct V_18 * V_19 )
{
unsigned long V_33 ;
do {
V_33 = F_19 ( & V_26 -> V_33 ) ;
V_19 -> V_36 = V_26 -> V_42 . V_36 ;
V_19 -> V_35 = V_26 -> V_42 . V_35 ;
} while ( F_13 ( F_20 ( & V_26 -> V_33 , V_33 ) ) );
return 0 ;
}
T_1 static int F_24 ( struct V_18 * V_19 )
{
unsigned long V_33 ;
do {
V_33 = F_19 ( & V_26 -> V_33 ) ;
V_19 -> V_36 = V_26 -> V_43 . V_36 ;
V_19 -> V_35 = V_26 -> V_43 . V_35 ;
} while ( F_13 ( F_20 ( & V_26 -> V_33 , V_33 ) ) );
return 0 ;
}
T_1 int F_25 ( T_8 clock , struct V_18 * V_19 )
{
int V_1 = V_17 ;
switch ( clock ) {
case V_44 :
V_1 = F_18 ( V_19 ) ;
break;
case V_45 :
V_1 = F_22 ( V_19 ) ;
break;
case V_46 :
return F_23 ( V_19 ) ;
case V_47 :
return F_24 ( V_19 ) ;
}
if ( V_1 == V_17 )
return F_14 ( clock , V_19 ) ;
return 0 ;
}
T_1 int F_26 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
long V_1 = V_17 ;
if ( F_5 ( V_21 != NULL ) ) {
F_27 ( F_28 ( struct V_20 , V_48 ) !=
F_28 ( struct V_18 , V_35 ) ||
sizeof( * V_21 ) != sizeof( struct V_18 ) ) ;
V_1 = F_18 ( (struct V_18 * ) V_21 ) ;
V_21 -> V_48 /= 1000 ;
}
if ( F_13 ( V_23 != NULL ) ) {
V_23 -> V_49 = V_26 -> V_50 . V_49 ;
V_23 -> V_51 = V_26 -> V_50 . V_51 ;
}
if ( V_1 == V_17 )
return F_15 ( V_21 , V_23 ) ;
return 0 ;
}
T_1 T_9 F_29 ( T_9 * V_52 )
{
T_9 V_53 = F_30 ( F_4 ( V_3 ) . V_37 ) ;
if ( V_52 )
* V_52 = V_53 ;
return V_53 ;
}
