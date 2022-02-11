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
T_4 V_12 ;
T_5 V_13 ;
unsigned V_14 , V_15 ;
do {
V_14 = F_10 () & V_16 ;
V_10 = F_11 ( V_14 ) ;
V_12 = V_10 -> V_12 ;
V_11 = F_12 ( & V_10 -> V_10 , & V_1 , & V_13 ) ;
V_15 = F_10 () & V_16 ;
} while ( F_13 ( V_14 != V_15 ||
( V_10 -> V_10 . V_11 & 1 ) ||
V_10 -> V_10 . V_11 != V_11 ||
V_10 -> V_12 != V_12 ) );
if ( F_13 ( ! ( V_13 & V_17 ) ) )
* V_8 = V_18 ;
V_2 = F_4 ( V_3 ) . clock . V_4 ;
if ( F_5 ( V_1 >= V_2 ) )
return V_1 ;
return V_2 ;
}
T_1 static long F_14 ( long clock , struct V_19 * V_20 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return V_1 ;
}
T_1 static long F_15 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
long V_1 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_1 ;
}
T_1 static inline T_3 F_16 ( int * V_8 )
{
long V_25 ;
T_6 V_26 ;
if ( V_27 -> clock . V_28 == V_29 )
V_26 = F_1 () ;
else if ( V_27 -> clock . V_28 == V_30 )
V_26 = F_6 () ;
#ifdef F_17
else if ( V_27 -> clock . V_28 == V_31 )
V_26 = F_9 ( V_8 ) ;
#endif
else
return 0 ;
V_25 = ( V_26 - V_27 -> clock . V_4 ) & V_27 -> clock . V_32 ;
return V_25 * V_27 -> clock . V_33 ;
}
T_1 static int T_7 F_18 ( struct V_19 * V_20 )
{
unsigned long V_34 ;
T_3 V_35 ;
int V_8 ;
V_20 -> V_36 = 0 ;
do {
V_34 = F_19 ( & V_27 -> V_34 ) ;
V_8 = V_27 -> clock . V_28 ;
V_20 -> V_37 = V_27 -> V_38 ;
V_35 = V_27 -> V_39 ;
V_35 += F_16 ( & V_8 ) ;
V_35 >>= V_27 -> clock . V_40 ;
} while ( F_13 ( F_20 ( & V_27 -> V_34 , V_34 ) ) );
F_21 ( V_20 , V_35 ) ;
return V_8 ;
}
T_1 static int F_22 ( struct V_19 * V_20 )
{
unsigned long V_34 ;
T_3 V_35 ;
int V_8 ;
V_20 -> V_36 = 0 ;
do {
V_34 = F_19 ( & V_27 -> V_34 ) ;
V_8 = V_27 -> clock . V_28 ;
V_20 -> V_37 = V_27 -> V_41 ;
V_35 = V_27 -> V_42 ;
V_35 += F_16 ( & V_8 ) ;
V_35 >>= V_27 -> clock . V_40 ;
} while ( F_13 ( F_20 ( & V_27 -> V_34 , V_34 ) ) );
F_21 ( V_20 , V_35 ) ;
return V_8 ;
}
T_1 static int F_23 ( struct V_19 * V_20 )
{
unsigned long V_34 ;
do {
V_34 = F_19 ( & V_27 -> V_34 ) ;
V_20 -> V_37 = V_27 -> V_43 . V_37 ;
V_20 -> V_36 = V_27 -> V_43 . V_36 ;
} while ( F_13 ( F_20 ( & V_27 -> V_34 , V_34 ) ) );
return 0 ;
}
T_1 static int F_24 ( struct V_19 * V_20 )
{
unsigned long V_34 ;
do {
V_34 = F_19 ( & V_27 -> V_34 ) ;
V_20 -> V_37 = V_27 -> V_44 . V_37 ;
V_20 -> V_36 = V_27 -> V_44 . V_36 ;
} while ( F_13 ( F_20 ( & V_27 -> V_34 , V_34 ) ) );
return 0 ;
}
T_1 int F_25 ( T_8 clock , struct V_19 * V_20 )
{
int V_1 = V_18 ;
switch ( clock ) {
case V_45 :
V_1 = F_18 ( V_20 ) ;
break;
case V_46 :
V_1 = F_22 ( V_20 ) ;
break;
case V_47 :
return F_23 ( V_20 ) ;
case V_48 :
return F_24 ( V_20 ) ;
}
if ( V_1 == V_18 )
return F_14 ( clock , V_20 ) ;
return 0 ;
}
T_1 int F_26 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
long V_1 = V_18 ;
if ( F_5 ( V_22 != NULL ) ) {
F_27 ( F_28 ( struct V_21 , V_49 ) !=
F_28 ( struct V_19 , V_36 ) ||
sizeof( * V_22 ) != sizeof( struct V_19 ) ) ;
V_1 = F_18 ( (struct V_19 * ) V_22 ) ;
V_22 -> V_49 /= 1000 ;
}
if ( F_13 ( V_24 != NULL ) ) {
V_24 -> V_50 = V_27 -> V_51 . V_50 ;
V_24 -> V_52 = V_27 -> V_51 . V_52 ;
}
if ( V_1 == V_18 )
return F_15 ( V_22 , V_24 ) ;
return 0 ;
}
T_1 T_9 F_29 ( T_9 * V_53 )
{
T_9 V_54 = F_30 ( F_4 ( V_3 ) . V_38 ) ;
if ( V_53 )
* V_53 = V_54 ;
return V_54 ;
}
