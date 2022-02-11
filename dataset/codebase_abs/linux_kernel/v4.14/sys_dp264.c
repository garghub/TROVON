static void
F_1 ( unsigned long V_1 )
{
register T_1 * V_2 = V_3 ;
unsigned long V_4 = 1UL << 55 ;
register int V_5 = V_6 ;
#ifdef F_2
volatile unsigned long * V_7 , * V_8 , * V_9 , * V_10 ;
unsigned long V_11 , V_12 , V_13 , V_14 , V_15 ;
V_1 &= ~ V_4 ;
V_11 = V_1 & V_16 [ 0 ] ;
V_12 = V_1 & V_16 [ 1 ] ;
V_13 = V_1 & V_16 [ 2 ] ;
V_14 = V_1 & V_16 [ 3 ] ;
if ( V_5 == 0 ) V_11 |= V_4 ;
else if ( V_5 == 1 ) V_12 |= V_4 ;
else if ( V_5 == 2 ) V_13 |= V_4 ;
else V_14 |= V_4 ;
V_7 = & V_2 -> V_7 . V_17 ;
V_8 = & V_2 -> V_8 . V_17 ;
V_9 = & V_2 -> V_9 . V_17 ;
V_10 = & V_2 -> V_10 . V_17 ;
if ( ! F_3 ( 0 ) ) V_7 = & V_15 ;
if ( ! F_3 ( 1 ) ) V_8 = & V_15 ;
if ( ! F_3 ( 2 ) ) V_9 = & V_15 ;
if ( ! F_3 ( 3 ) ) V_10 = & V_15 ;
* V_7 = V_11 ;
* V_8 = V_12 ;
* V_9 = V_13 ;
* V_10 = V_14 ;
F_4 () ;
* V_7 ;
* V_8 ;
* V_9 ;
* V_10 ;
#else
volatile unsigned long * V_18 ;
if ( V_5 == 0 ) V_18 = & V_2 -> V_7 . V_17 ;
else if ( V_5 == 1 ) V_18 = & V_2 -> V_8 . V_17 ;
else if ( V_5 == 2 ) V_18 = & V_2 -> V_9 . V_17 ;
else V_18 = & V_2 -> V_10 . V_17 ;
* V_18 = V_1 | V_4 ;
F_4 () ;
* V_18 ;
#endif
}
static void
F_5 ( struct V_19 * V_20 )
{
F_6 ( & V_21 ) ;
V_22 |= 1UL << V_20 -> V_23 ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
}
static void
F_8 ( struct V_19 * V_20 )
{
F_6 ( & V_21 ) ;
V_22 &= ~ ( 1UL << V_20 -> V_23 ) ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
}
static void
F_9 ( struct V_19 * V_20 )
{
F_6 ( & V_21 ) ;
V_22 |= 1UL << ( V_20 -> V_23 - 16 ) ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
}
static void
F_10 ( struct V_19 * V_20 )
{
F_6 ( & V_21 ) ;
V_22 &= ~ ( 1UL << ( V_20 -> V_23 - 16 ) ) ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
}
static void
F_11 ( unsigned int V_23 , T_2 V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
unsigned long V_26 = V_16 [ V_25 ] ;
if ( F_12 ( V_25 , & V_24 ) )
V_26 |= 1UL << V_23 ;
else
V_26 &= ~ ( 1UL << V_23 ) ;
V_16 [ V_25 ] = V_26 ;
}
}
static int
F_13 ( struct V_19 * V_20 , const struct V_27 * V_24 ,
bool V_28 )
{
F_6 ( & V_21 ) ;
F_11 ( V_20 -> V_23 , * V_24 ) ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
return 0 ;
}
static int
F_14 ( struct V_19 * V_20 , const struct V_27 * V_24 ,
bool V_28 )
{
F_6 ( & V_21 ) ;
F_11 ( V_20 -> V_23 - 16 , * V_24 ) ;
F_1 ( V_22 ) ;
F_7 ( & V_21 ) ;
return 0 ;
}
static void
F_15 ( unsigned long V_29 )
{
unsigned long V_30 ;
unsigned int V_31 ;
V_30 = V_3 -> V_32 . V_17 ;
while ( V_30 ) {
V_31 = F_16 ( ~ V_30 ) ;
V_30 &= V_30 - 1 ;
if ( V_31 == 55 )
F_17 ( V_29 ) ;
else
F_18 ( 16 + V_31 ) ;
}
}
static void
F_19 ( unsigned long V_29 )
{
int V_23 ;
V_23 = ( V_29 - 0x800 ) >> 4 ;
if ( V_23 >= 32 )
V_23 -= 16 ;
F_18 ( V_23 ) ;
}
static void
F_20 ( unsigned long V_29 )
{
int V_23 ;
V_23 = ( V_29 - 0x800 ) >> 4 ;
F_18 ( V_23 ) ;
}
static void T_3
F_21 ( struct V_33 * V_34 , int V_35 , int V_36 )
{
long V_31 ;
for ( V_31 = V_35 ; V_31 <= V_36 ; ++ V_31 ) {
F_22 ( V_31 , V_34 , V_37 ) ;
F_23 ( V_31 , V_38 ) ;
}
}
static void T_3
F_24 ( void )
{
F_25 ( 0 , V_39 ) ;
F_25 ( 0 , V_40 ) ;
F_25 ( V_41 , V_42 ) ;
F_25 ( 0 , V_43 ) ;
if ( V_44 )
V_45 . V_46 = F_19 ;
F_1 ( 0 ) ;
F_26 () ;
F_21 ( & V_47 , 16 , 47 ) ;
}
static void T_3
F_27 ( void )
{
F_25 ( 0 , V_39 ) ;
F_25 ( 0 , V_40 ) ;
F_25 ( V_41 , V_42 ) ;
F_25 ( 0 , V_43 ) ;
if ( V_44 )
V_45 . V_46 = F_20 ;
F_1 ( 0 ) ;
F_26 () ;
F_21 ( & V_48 , 24 , 63 ) ;
}
static int
F_28 ( const struct V_49 * V_50 , int V_23 )
{
T_4 V_51 ;
if ( V_23 > 0 )
return V_23 ;
F_29 ( V_50 , V_52 , & V_51 ) ;
return V_51 & 0xf ;
}
static int
F_30 ( const struct V_49 * V_50 , T_4 V_53 , T_4 V_54 )
{
static char V_55 [ 6 ] [ 5 ] = {
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 3 , 16 + 3 , 16 + 2 , 16 + 2 , 16 + 2 } ,
{ 16 + 15 , 16 + 15 , 16 + 14 , 16 + 13 , 16 + 12 } ,
{ 16 + 11 , 16 + 11 , 16 + 10 , 16 + 9 , 16 + 8 } ,
{ 16 + 7 , 16 + 7 , 16 + 6 , 16 + 5 , 16 + 4 } ,
{ 16 + 3 , 16 + 3 , 16 + 2 , 16 + 1 , 16 + 0 }
} ;
const long V_56 = 5 , V_57 = 10 , V_58 = 5 ;
struct V_59 * V_60 = V_50 -> V_61 ;
int V_23 = V_62 ;
if ( V_23 > 0 )
V_23 += 16 * V_60 -> V_63 ;
return F_28 ( V_50 , V_23 ) ;
}
static int
F_31 ( const struct V_49 * V_50 , T_4 V_53 , T_4 V_54 )
{
static char V_55 [ 13 ] [ 5 ] = {
{ 45 , 45 , 45 , 45 , 45 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 47 , 47 , 47 , 47 , 47 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
#if 1
{ 28 , 28 , 29 , 30 , 31 } ,
{ 24 , 24 , 25 , 26 , 27 } ,
#else
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
#endif
{ 40 , 40 , 41 , 42 , 43 } ,
{ 36 , 36 , 37 , 38 , 39 } ,
{ 32 , 32 , 33 , 34 , 35 } ,
{ 28 , 28 , 29 , 30 , 31 } ,
{ 24 , 24 , 25 , 26 , 27 }
} ;
const long V_56 = 3 , V_57 = 15 , V_58 = 5 ;
return F_28 ( V_50 , V_62 ) ;
}
static T_4
F_32 ( struct V_49 * V_50 , T_4 * V_64 )
{
struct V_59 * V_60 = V_50 -> V_61 ;
int V_53 , V_54 = * V_64 ;
if ( ! V_50 -> V_65 -> V_66 ) {
V_53 = F_33 ( V_50 -> V_67 ) ;
}
else if ( V_60 -> V_63 == 1 && F_33 ( V_50 -> V_65 -> V_68 -> V_67 ) == 8 ) {
V_53 = F_33 ( V_50 -> V_67 ) ;
} else {
do {
if ( V_60 -> V_63 == 1 &&
F_33 ( V_50 -> V_65 -> V_68 -> V_67 ) == 8 ) {
V_53 = F_33 ( V_50 -> V_67 ) ;
break;
}
V_54 = F_34 ( V_50 , V_54 ) ;
V_50 = V_50 -> V_65 -> V_68 ;
V_53 = F_33 ( V_50 -> V_67 ) ;
} while ( V_50 -> V_65 -> V_68 );
}
* V_64 = V_54 ;
return V_53 ;
}
static int
F_35 ( const struct V_49 * V_50 , T_4 V_53 , T_4 V_54 )
{
static char V_55 [ 13 ] [ 5 ] = {
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 29 , 29 , 29 , 29 , 29 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 30 , 30 , 30 , 30 , 30 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 35 , 35 , 34 , 33 , 32 } ,
{ 39 , 39 , 38 , 37 , 36 } ,
{ 43 , 43 , 42 , 41 , 40 } ,
{ 47 , 47 , 46 , 45 , 44 } ,
} ;
const long V_56 = 7 , V_57 = 17 , V_58 = 5 ;
return F_28 ( V_50 , V_62 ) ;
}
static int
F_36 ( const struct V_49 * V_50 , T_4 V_53 , T_4 V_54 )
{
static char V_55 [ 7 ] [ 5 ] = {
{ 16 + 8 , 16 + 8 , 16 + 9 , 16 + 10 , 16 + 11 } ,
{ 16 + 12 , 16 + 12 , 16 + 13 , 16 + 14 , 16 + 15 } ,
{ 16 + 16 , 16 + 16 , 16 + 17 , 16 + 18 , 16 + 19 } ,
{ 16 + 20 , 16 + 20 , 16 + 21 , 16 + 22 , 16 + 23 } ,
{ 16 + 24 , 16 + 24 , 16 + 25 , 16 + 26 , 16 + 27 } ,
{ 16 + 28 , 16 + 28 , 16 + 29 , 16 + 30 , 16 + 31 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 }
} ;
const long V_56 = 1 , V_57 = 7 , V_58 = 5 ;
struct V_59 * V_60 = V_50 -> V_61 ;
int V_23 = V_62 ;
if ( V_23 > 0 )
V_23 += 16 * V_60 -> V_63 ;
return F_28 ( V_50 , V_23 ) ;
}
static void T_3
F_37 ( void )
{
F_38 () ;
F_39 ( 0 ) ;
F_40 ( NULL ) ;
}
static void T_3
F_41 ( void )
{
F_38 () ;
F_39 ( 1 ) ;
F_42 () ;
F_40 ( NULL ) ;
}
static void T_3
F_43 ( void )
{
F_38 () ;
F_40 ( NULL ) ;
}
static void T_3
F_44 ( void )
{
F_45 () ;
V_69 -> V_70 -> V_71 = 4 ;
V_69 -> V_72 -> V_71 = 4 ;
}
