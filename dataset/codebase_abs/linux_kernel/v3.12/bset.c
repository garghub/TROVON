void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
* V_2 = * V_3 ;
if ( V_3 -> V_4 == V_3 -> V_5 ) {
T_1 V_6 = ( V_7 * ) V_3 -> V_8 - V_3 -> V_5 ;
V_2 -> V_8 = (struct V_9 * ) & V_2 -> V_5 [ V_6 ] ;
V_2 -> V_4 = V_2 -> V_5 ;
}
}
int F_2 ( struct V_1 * V_10 , int V_11 , struct V_12 * V_13 )
{
unsigned V_14 = ( V_7 * ) V_10 -> V_8 - V_10 -> V_4 ;
unsigned V_15 = V_14 + 2 + V_11 ;
V_7 * V_16 ;
if ( V_15 * sizeof( V_7 ) > F_3 ( V_13 ) - sizeof( struct V_17 ) )
return - V_18 ;
V_15 = F_4 ( V_15 ) ;
if ( V_15 <= V_19 ||
F_4 ( V_14 ) == V_15 )
return 0 ;
V_16 = F_5 ( V_10 -> V_4 == V_10 -> V_5 ? NULL : V_10 -> V_4 ,
sizeof( V_7 ) * V_15 , V_20 ) ;
if ( ! V_16 )
return - V_18 ;
if ( V_10 -> V_4 == V_10 -> V_5 )
memcpy ( V_16 , V_10 -> V_4 , sizeof( V_7 ) * V_19 ) ;
V_10 -> V_4 = V_16 ;
V_10 -> V_8 = (struct V_9 * ) ( & V_10 -> V_4 [ V_14 ] ) ;
return 0 ;
}
struct V_9 * F_6 ( struct V_1 * V_10 )
{
struct V_9 * V_21 = V_10 -> V_22 ;
if ( V_21 == V_10 -> V_8 )
return NULL ;
while ( F_7 ( V_21 ) != V_10 -> V_8 )
V_21 = F_7 ( V_21 ) ;
return V_10 -> V_8 = V_21 ;
}
bool F_8 ( struct V_12 * V_13 , int V_23 , const struct V_9 * V_21 )
{
unsigned V_24 ;
char V_25 [ 80 ] ;
if ( V_23 && ( ! F_9 ( V_21 ) || ! F_10 ( V_21 ) || F_11 ( V_21 ) ) )
goto V_26;
if ( ! V_23 && F_10 ( V_21 ) > F_12 ( V_21 ) )
goto V_26;
if ( ! F_10 ( V_21 ) )
return true ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
if ( F_13 ( V_13 , V_21 , V_24 ) ) {
struct V_27 * V_28 = F_14 ( V_13 , V_21 , V_24 ) ;
T_1 V_29 = F_15 ( V_13 , V_21 , V_24 ) ;
T_1 V_30 = F_16 ( V_13 , F_17 ( V_21 , V_24 ) ) ;
if ( F_10 ( V_21 ) + V_30 > V_13 -> V_31 . V_32 ||
V_29 < V_28 -> V_31 . V_33 ||
V_29 >= V_28 -> V_31 . V_34 )
goto V_26;
}
return false ;
V_26:
F_18 ( V_25 , sizeof( V_25 ) , V_21 ) ;
F_19 ( V_13 , L_1 , V_25 , F_20 ( V_13 , V_21 ) ) ;
return true ;
}
bool F_21 ( struct V_35 * V_36 , const struct V_9 * V_21 )
{
struct V_29 * V_37 ;
unsigned V_24 , V_38 ;
if ( ! F_22 ( V_21 , & V_39 ) ||
! F_9 ( V_21 ) ||
F_23 ( V_36 , V_21 ) )
return true ;
if ( F_9 ( V_21 ) && F_24 ( V_21 , 0 ) == V_40 )
return true ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
if ( F_13 ( V_36 -> V_13 , V_21 , V_24 ) ) {
V_37 = F_25 ( V_36 -> V_13 , V_21 , V_24 ) ;
V_38 = F_26 ( V_36 -> V_13 , V_21 , V_24 ) ;
F_27 ( V_38 > 96 , V_36 ,
L_2 ,
V_38 , V_36 -> V_13 -> V_41 ) ;
F_27 ( V_38 && F_11 ( V_21 ) && F_10 ( V_21 ) ,
V_36 , L_3 ) ;
if ( V_38 )
return true ;
#ifdef F_28
if ( ! F_29 ( & V_36 -> V_13 -> V_42 ) )
continue;
if ( V_36 -> V_23 ) {
if ( F_11 ( V_21 ) ||
V_37 -> V_43 != V_44 ||
( V_36 -> V_13 -> V_45 &&
F_30 ( V_37 ) != V_46 ) )
goto V_47;
} else {
if ( V_37 -> V_43 == V_44 )
goto V_47;
if ( F_11 ( V_21 ) &&
V_36 -> V_13 -> V_45 &&
F_30 ( V_37 ) != V_48 )
goto V_47;
}
F_31 ( & V_36 -> V_13 -> V_42 ) ;
#endif
}
return false ;
#ifdef F_28
V_47:
F_31 ( & V_36 -> V_13 -> V_42 ) ;
{
char V_25 [ 80 ] ;
F_18 ( V_25 , sizeof( V_25 ) , V_21 ) ;
F_32 ( V_36 ,
L_4 ,
V_25 , F_15 ( V_36 -> V_13 , V_21 , V_24 ) , F_33 ( & V_37 -> V_49 ) ,
V_37 -> V_43 , V_37 -> V_50 , V_37 -> V_51 , F_30 ( V_37 ) , V_37 -> V_52 ) ;
}
return true ;
#endif
}
void F_34 ( struct V_9 * V_2 , const struct V_9 * V_3 ,
unsigned V_24 )
{
F_35 ( V_24 > F_9 ( V_3 ) ) ;
memcpy ( V_2 , V_3 , 2 * sizeof( V_7 ) ) ;
V_2 -> V_53 [ 0 ] = V_3 -> V_53 [ V_24 ] ;
F_36 ( V_2 , 1 ) ;
F_37 ( V_2 , 0 ) ;
}
bool F_38 ( const struct V_9 * V_54 , struct V_9 * V_21 )
{
unsigned V_24 , V_55 = 0 ;
if ( F_22 ( V_54 , & F_39 ( V_21 ) ) <= 0 )
return false ;
if ( F_22 ( V_54 , V_21 ) < 0 )
V_55 = F_12 ( V_21 ) - F_12 ( V_54 ) ;
else
F_40 ( V_21 , V_54 ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
F_41 ( V_21 , V_24 , F_17 ( V_21 , V_24 ) + F_10 ( V_21 ) - V_55 ) ;
F_35 ( V_55 > F_10 ( V_21 ) ) ;
F_42 ( V_21 , V_55 ) ;
return true ;
}
bool F_43 ( const struct V_9 * V_54 , struct V_9 * V_21 )
{
unsigned V_55 = 0 ;
if ( F_22 ( V_54 , V_21 ) >= 0 )
return false ;
F_35 ( F_44 ( V_54 ) != F_44 ( V_21 ) ) ;
if ( F_22 ( V_54 , & F_39 ( V_21 ) ) > 0 )
V_55 = F_12 ( V_54 ) - F_45 ( V_21 ) ;
F_40 ( V_21 , V_54 ) ;
F_35 ( V_55 > F_10 ( V_21 ) ) ;
F_42 ( V_21 , V_55 ) ;
return true ;
}
static V_7 F_46 ( struct V_9 * V_10 , struct V_9 * V_30 )
{
return ( V_10 -> V_53 [ F_9 ( V_10 ) ] + V_30 -> V_53 [ F_9 ( V_30 ) ] ) &
~ ( ( V_7 ) 1 << 63 ) ;
}
bool F_47 ( struct V_35 * V_36 , struct V_9 * V_10 , struct V_9 * V_30 )
{
unsigned V_24 ;
if ( F_48 ( V_36 -> V_13 ) )
return false ;
if ( F_9 ( V_10 ) != F_9 ( V_30 ) ||
F_11 ( V_10 ) != F_11 ( V_30 ) ||
F_22 ( V_10 , & F_39 ( V_30 ) ) )
return false ;
for ( V_24 = 0 ; V_24 < F_9 ( V_10 ) ; V_24 ++ )
if ( V_10 -> V_53 [ V_24 ] + F_49 ( 0 , F_10 ( V_10 ) , 0 ) != V_30 -> V_53 [ V_24 ] ||
F_15 ( V_36 -> V_13 , V_10 , V_24 ) != F_15 ( V_36 -> V_13 , V_30 , V_24 ) )
return false ;
if ( F_10 ( V_10 ) + F_10 ( V_30 ) > V_56 ) {
F_50 ( V_10 , F_12 ( V_10 ) + V_56 - F_10 ( V_10 ) ) ;
F_42 ( V_10 , V_56 ) ;
F_51 ( V_10 , V_30 ) ;
return false ;
}
if ( F_52 ( V_10 ) ) {
if ( F_52 ( V_30 ) )
V_10 -> V_53 [ F_9 ( V_10 ) ] = F_46 ( V_10 , V_30 ) ;
else
F_37 ( V_10 , 0 ) ;
}
F_50 ( V_10 , F_12 ( V_10 ) + F_10 ( V_30 ) ) ;
F_42 ( V_10 , F_10 ( V_10 ) + F_10 ( V_30 ) ) ;
return true ;
}
static unsigned F_53 ( unsigned V_57 , unsigned V_58 )
{
if ( V_57 * 2 + 1 < V_58 ) {
V_57 = V_57 * 2 + 1 ;
while ( V_57 * 2 < V_58 )
V_57 *= 2 ;
} else
V_57 >>= F_54 ( V_57 ) + 1 ;
return V_57 ;
}
static unsigned F_55 ( unsigned V_57 , unsigned V_58 )
{
if ( V_57 * 2 < V_58 ) {
V_57 = V_57 * 2 ;
while ( V_57 * 2 + 1 < V_58 )
V_57 = V_57 * 2 + 1 ;
} else
V_57 >>= F_56 ( V_57 ) ;
return V_57 ;
}
static unsigned F_57 ( unsigned V_57 , unsigned V_58 , unsigned V_59 )
{
unsigned V_36 = F_58 ( V_57 ) ;
unsigned V_60 = F_58 ( V_58 - 1 ) - V_36 ;
V_57 ^= 1U << ( V_36 - 1 ) ;
V_57 <<= 1 ;
V_57 |= 1 ;
V_57 <<= V_60 ;
if ( V_57 > V_59 )
V_57 -= ( V_57 - V_59 ) >> 1 ;
return V_57 ;
}
static unsigned F_59 ( unsigned V_57 , struct V_61 * V_62 )
{
return F_57 ( V_57 , V_62 -> V_58 , V_62 -> V_59 ) ;
}
static unsigned F_60 ( unsigned V_57 , unsigned V_58 , unsigned V_59 )
{
unsigned V_60 ;
if ( V_57 > V_59 )
V_57 += V_57 - V_59 ;
V_60 = F_56 ( V_57 ) ;
V_57 >>= V_60 ;
V_57 |= F_4 ( V_58 ) >> V_60 ;
return V_57 ;
}
static unsigned F_61 ( unsigned V_57 , struct V_61 * V_62 )
{
return F_60 ( V_57 , V_62 -> V_58 , V_62 -> V_59 ) ;
}
static struct V_9 * F_62 ( struct V_61 * V_62 , unsigned V_63 ,
unsigned V_64 )
{
return ( ( void * ) V_62 -> V_65 ) + V_63 * V_66 + V_64 * 8 ;
}
static unsigned F_63 ( struct V_61 * V_62 , struct V_9 * V_21 )
{
return ( ( void * ) V_21 - ( void * ) V_62 -> V_65 ) / V_66 ;
}
static unsigned F_64 ( struct V_9 * V_21 )
{
return ( ( T_1 ) V_21 & ( V_66 - 1 ) ) / sizeof( V_7 ) ;
}
static struct V_9 * F_65 ( struct V_61 * V_62 , unsigned V_57 )
{
return F_62 ( V_62 , F_59 ( V_57 , V_62 ) , V_62 -> V_67 [ V_57 ] . V_68 ) ;
}
static struct V_9 * F_66 ( struct V_61 * V_62 , unsigned V_57 )
{
return ( void * ) ( ( ( V_7 * ) F_65 ( V_62 , V_57 ) ) - V_62 -> V_69 [ V_57 ] ) ;
}
static struct V_9 * F_67 ( struct V_61 * V_62 , unsigned V_63 )
{
return F_62 ( V_62 , V_63 , V_62 -> V_69 [ V_63 ] ) ;
}
static inline V_7 F_68 ( V_7 V_70 , V_7 V_71 , T_2 V_60 )
{
#ifdef F_69
asm("shrd %[shift],%[high],%[low]"
: [low] "+Rm" (low)
: [high] "R" (high),
[shift] "ci" (shift)
: "cc");
#else
V_71 >>= V_60 ;
V_71 |= ( V_70 << 1 ) << ( 63U - V_60 ) ;
#endif
return V_71 ;
}
static inline unsigned F_70 ( const struct V_9 * V_21 ,
struct V_72 * V_73 )
{
const V_7 * V_74 = & V_21 -> V_71 - ( V_73 -> V_75 >> 6 ) ;
return F_68 ( V_74 [ - 1 ] , V_74 [ 0 ] , V_73 -> V_75 & 63 ) & V_76 ;
}
static void F_71 ( struct V_61 * V_62 , unsigned V_57 )
{
struct V_72 * V_73 = & V_62 -> V_67 [ V_57 ] ;
struct V_9 * V_68 = F_65 ( V_62 , V_57 ) ;
struct V_9 * V_74 = F_66 ( V_62 , V_57 ) ;
struct V_9 * V_10 = F_72 ( V_57 )
? V_62 -> V_65 -> V_77
: F_66 ( V_62 , V_57 >> F_56 ( V_57 ) ) ;
struct V_9 * V_30 = F_72 ( V_57 + 1 )
? F_73 ( V_62 -> V_65 , V_62 -> V_65 -> V_78 - F_74 ( & V_62 -> V_79 ) )
: F_65 ( V_62 , V_57 >> ( F_54 ( V_57 ) + 1 ) ) ;
F_35 ( V_68 < V_10 || V_68 > V_30 ) ;
F_35 ( F_7 ( V_74 ) != V_68 ) ;
if ( F_44 ( V_10 ) != F_44 ( V_30 ) )
V_73 -> V_75 = F_75 ( F_44 ( V_30 ) ^ F_44 ( V_10 ) ) + 64 ;
else
V_73 -> V_75 = F_75 ( V_30 -> V_71 ^ V_10 -> V_71 ) ;
V_73 -> V_75 = F_76 ( int , V_73 -> V_75 - V_80 , 0 ) ;
if ( F_70 ( V_68 , V_73 ) != F_70 ( V_74 , V_73 ) )
V_73 -> V_81 = F_70 ( V_68 , V_73 ) - 1 ;
else
V_73 -> V_75 = 127 ;
}
static void F_77 ( struct V_35 * V_36 , struct V_61 * V_62 )
{
if ( V_62 != V_36 -> V_82 ) {
unsigned V_57 = F_78 ( V_62 [ - 1 ] . V_58 ,
64 / sizeof( struct V_72 ) ) ;
V_62 -> V_67 = V_62 [ - 1 ] . V_67 + V_57 ;
V_62 -> V_69 = V_62 [ - 1 ] . V_69 + V_57 ;
}
while ( V_62 < V_36 -> V_82 + V_83 )
V_62 ++ -> V_58 = 0 ;
}
static void F_79 ( struct V_35 * V_36 )
{
struct V_61 * V_62 = V_36 -> V_82 + V_36 -> V_84 ;
F_77 ( V_36 , V_62 ) ;
if ( V_62 -> V_67 != V_36 -> V_82 -> V_67 + F_80 ( V_36 ) ) {
V_62 -> V_69 [ 0 ] = F_64 ( V_62 -> V_65 -> V_77 ) ;
V_62 -> V_58 = 1 ;
}
}
static void F_81 ( struct V_35 * V_36 )
{
struct V_61 * V_62 = V_36 -> V_82 + V_36 -> V_84 ;
struct V_9 * V_21 = V_62 -> V_65 -> V_77 ;
unsigned V_57 , V_63 = 1 ;
F_77 ( V_36 , V_62 ) ;
V_62 -> V_58 = F_82 ( unsigned ,
F_63 ( V_62 , V_79 ( V_62 -> V_65 ) ) ,
V_36 -> V_82 -> V_67 + F_80 ( V_36 ) - V_62 -> V_67 ) ;
if ( V_62 -> V_58 < 2 ) {
V_62 -> V_58 = 0 ;
return;
}
V_62 -> V_59 = ( V_62 -> V_58 - F_83 ( V_62 -> V_58 - 1 ) ) << 1 ;
for ( V_57 = F_53 ( 0 , V_62 -> V_58 ) ;
V_57 ;
V_57 = F_53 ( V_57 , V_62 -> V_58 ) ) {
while ( F_63 ( V_62 , V_21 ) != V_63 )
V_21 = F_7 ( V_21 ) ;
V_62 -> V_69 [ V_57 ] = F_74 ( V_21 ) ;
V_21 = F_7 ( V_21 ) ;
V_63 ++ ;
V_62 -> V_67 [ V_57 ] . V_68 = F_64 ( V_21 ) ;
}
while ( F_7 ( V_21 ) != V_79 ( V_62 -> V_65 ) )
V_21 = F_7 ( V_21 ) ;
V_62 -> V_79 = * V_21 ;
for ( V_57 = F_53 ( 0 , V_62 -> V_58 ) ;
V_57 ;
V_57 = F_53 ( V_57 , V_62 -> V_58 ) )
F_71 ( V_62 , V_57 ) ;
}
void F_84 ( struct V_35 * V_36 , struct V_9 * V_21 )
{
struct V_61 * V_62 ;
unsigned V_85 , V_57 = 1 ;
for ( V_62 = V_36 -> V_82 ; V_62 <= & V_36 -> V_82 [ V_36 -> V_84 ] ; V_62 ++ )
if ( V_21 < V_79 ( V_62 -> V_65 ) )
goto V_86;
F_85 () ;
V_86:
if ( ! V_62 -> V_58 || ! F_86 ( V_36 , V_62 ) )
return;
V_85 = F_63 ( V_62 , V_21 ) ;
if ( V_21 == V_62 -> V_65 -> V_77 )
goto V_87;
if ( F_7 ( V_21 ) == V_79 ( V_62 -> V_65 ) ) {
V_62 -> V_79 = * V_21 ;
goto V_88;
}
V_57 = F_61 ( V_85 , V_62 ) ;
if ( V_57 &&
V_57 < V_62 -> V_58 &&
V_21 == F_65 ( V_62 , V_57 ) )
V_87: do {
F_71 ( V_62 , V_57 ) ;
V_57 = V_57 * 2 ;
} while ( V_57 < V_62 -> V_58 );
V_57 = F_61 ( V_85 + 1 , V_62 ) ;
if ( V_57 &&
V_57 < V_62 -> V_58 &&
V_21 == F_66 ( V_62 , V_57 ) )
V_88: do {
F_71 ( V_62 , V_57 ) ;
V_57 = V_57 * 2 + 1 ;
} while ( V_57 < V_62 -> V_58 );
}
void F_87 ( struct V_35 * V_36 , struct V_9 * V_21 )
{
struct V_61 * V_62 = & V_36 -> V_82 [ V_36 -> V_84 ] ;
unsigned V_60 = F_74 ( V_21 ) ;
unsigned V_57 = F_63 ( V_62 , V_21 ) ;
if ( ! V_62 -> V_58 )
return;
if ( V_57 < V_62 -> V_58 &&
F_67 ( V_62 , V_57 ) <= V_21 )
V_57 ++ ;
for (; V_57 < V_62 -> V_58 ; V_57 ++ ) {
V_62 -> V_69 [ V_57 ] += V_60 ;
if ( V_62 -> V_69 [ V_57 ] > 7 ) {
V_21 = F_67 ( V_62 , V_57 - 1 ) ;
while ( V_21 < F_62 ( V_62 , V_57 , 0 ) )
V_21 = F_7 ( V_21 ) ;
V_62 -> V_69 [ V_57 ] = F_64 ( V_21 ) ;
}
}
if ( V_62 -> V_58 == V_36 -> V_82 -> V_67 + F_80 ( V_36 ) - V_62 -> V_67 )
return;
for ( V_21 = F_67 ( V_62 , V_62 -> V_58 - 1 ) ;
V_21 != V_79 ( V_62 -> V_65 ) ;
V_21 = F_7 ( V_21 ) )
if ( V_62 -> V_58 == F_63 ( V_62 , V_21 ) ) {
V_62 -> V_69 [ V_62 -> V_58 ] = F_64 ( V_21 ) ;
V_62 -> V_58 ++ ;
}
}
void F_88 ( struct V_35 * V_36 )
{
struct V_89 * V_24 = F_89 ( V_36 ) ;
if ( V_24 != V_36 -> V_82 [ 0 ] . V_65 ) {
V_36 -> V_82 [ ++ V_36 -> V_84 ] . V_65 = V_24 ;
V_24 -> V_90 = V_36 -> V_82 [ 0 ] . V_65 -> V_90 ;
} else
F_90 ( & V_24 -> V_90 , sizeof( V_7 ) ) ;
V_24 -> V_91 = F_91 ( V_36 -> V_13 ) ;
V_24 -> V_92 = 0 ;
V_24 -> V_78 = 0 ;
F_79 ( V_36 ) ;
}
static struct V_93 F_92 ( struct V_35 * V_36 ,
struct V_61 * V_62 ,
const struct V_9 * V_94 )
{
unsigned V_95 = 0 , V_96 = V_62 -> V_58 ;
F_35 ( ! V_36 -> V_84 &&
V_62 -> V_58 < F_63 ( V_62 , V_79 ( V_62 -> V_65 ) ) ) ;
while ( V_95 + 1 != V_96 ) {
unsigned V_68 = ( V_95 + V_96 ) >> 1 ;
if ( F_22 ( F_67 ( V_62 , V_68 ) , V_94 ) > 0 )
V_96 = V_68 ;
else
V_95 = V_68 ;
}
return (struct V_93 ) {
F_67 ( V_62 , V_95 ) ,
V_96 < V_62 -> V_58 ? F_67 ( V_62 , V_96 ) : V_79 (t->data)
} ;
}
static struct V_93 F_93 ( struct V_35 * V_36 ,
struct V_61 * V_62 ,
const struct V_9 * V_94 )
{
struct V_9 * V_10 , * V_30 ;
struct V_72 * V_73 ;
unsigned V_85 , V_57 , V_6 = 1 ;
do {
unsigned V_74 = V_6 << 4 ;
V_74 &= ( ( int ) ( V_74 - V_62 -> V_58 ) ) >> 31 ;
F_94 ( & V_62 -> V_67 [ V_74 ] ) ;
V_57 = V_6 ;
V_73 = & V_62 -> V_67 [ V_57 ] ;
if ( F_95 ( V_73 -> V_75 != 127 ) )
V_6 = V_57 * 2 + ( ( ( unsigned )
( V_73 -> V_81 -
F_70 ( V_94 , V_73 ) ) ) >> 31 ) ;
else
V_6 = ( F_22 ( F_65 ( V_62 , V_57 ) , V_94 ) > 0 )
? V_57 * 2
: V_57 * 2 + 1 ;
} while ( V_6 < V_62 -> V_58 );
V_85 = F_59 ( V_57 , V_62 ) ;
if ( V_6 & 1 ) {
V_10 = F_62 ( V_62 , V_85 , V_73 -> V_68 ) ;
if ( ++ V_85 != V_62 -> V_58 ) {
V_73 = & V_62 -> V_67 [ F_53 ( V_57 , V_62 -> V_58 ) ] ;
V_30 = F_62 ( V_62 , V_85 , V_73 -> V_68 ) ;
} else
V_30 = V_79 ( V_62 -> V_65 ) ;
} else {
V_30 = F_62 ( V_62 , V_85 , V_73 -> V_68 ) ;
if ( -- V_85 ) {
V_73 = & V_62 -> V_67 [ F_55 ( V_57 , V_62 -> V_58 ) ] ;
V_10 = F_62 ( V_62 , V_85 , V_73 -> V_68 ) ;
} else
V_10 = V_62 -> V_65 -> V_77 ;
}
return (struct V_93 ) { V_10 , V_30 } ;
}
struct V_9 * F_96 ( struct V_35 * V_36 , struct V_61 * V_62 ,
const struct V_9 * V_94 )
{
struct V_93 V_24 ;
if ( F_97 ( ! V_62 -> V_58 ) ) {
V_24 . V_10 = V_62 -> V_65 -> V_77 ;
V_24 . V_30 = V_79 ( V_62 -> V_65 ) ;
} else if ( F_86 ( V_36 , V_62 ) ) {
if ( F_97 ( F_22 ( V_94 , & V_62 -> V_79 ) >= 0 ) )
return V_79 ( V_62 -> V_65 ) ;
if ( F_97 ( F_22 ( V_94 , V_62 -> V_65 -> V_77 ) < 0 ) )
return V_62 -> V_65 -> V_77 ;
V_24 = F_93 ( V_36 , V_62 , V_94 ) ;
} else
V_24 = F_92 ( V_36 , V_62 , V_94 ) ;
#ifdef F_28
F_35 ( F_86 ( V_36 , V_62 ) &&
V_24 . V_10 != V_62 -> V_65 -> V_77 &&
F_22 ( F_66 ( V_62 ,
F_61 ( F_63 ( V_62 , V_24 . V_10 ) , V_62 ) ) ,
V_94 ) > 0 ) ;
F_35 ( V_24 . V_30 != V_79 ( V_62 -> V_65 ) &&
F_22 ( V_24 . V_30 , V_94 ) <= 0 ) ;
#endif
while ( F_95 ( V_24 . V_10 != V_24 . V_30 ) &&
F_22 ( V_24 . V_10 , V_94 ) <= 0 )
V_24 . V_10 = F_7 ( V_24 . V_10 ) ;
return V_24 . V_10 ;
}
static inline bool F_98 ( struct V_97 V_10 ,
struct V_97 V_30 )
{
T_3 V_13 = F_22 ( & F_39 ( V_10 . V_21 ) , & F_39 ( V_30 . V_21 ) ) ;
return V_13 ? V_13 > 0 : V_10 . V_21 < V_30 . V_21 ;
}
static inline bool F_99 ( struct V_98 * V_99 )
{
return ! V_99 -> V_100 ;
}
void F_100 ( struct V_98 * V_99 , struct V_9 * V_21 ,
struct V_9 * V_79 )
{
if ( V_21 != V_79 )
F_35 (!heap_add(iter,
((struct btree_iter_set) { k, end }),
btree_iter_cmp)) ;
}
struct V_9 * F_101 ( struct V_35 * V_36 , struct V_98 * V_99 ,
struct V_9 * V_94 , struct V_61 * V_77 )
{
struct V_9 * V_101 = NULL ;
V_99 -> V_58 = F_102 ( V_99 -> V_65 ) ;
V_99 -> V_100 = 0 ;
for (; V_77 <= & V_36 -> V_82 [ V_36 -> V_84 ] ; V_77 ++ ) {
V_101 = F_103 ( V_36 , V_77 , V_94 ) ;
F_100 ( V_99 , V_101 , V_79 ( V_77 -> V_65 ) ) ;
}
return V_101 ;
}
struct V_9 * F_104 ( struct V_98 * V_99 )
{
struct V_97 V_102 ;
struct V_9 * V_101 = NULL ;
if ( ! F_99 ( V_99 ) ) {
V_101 = V_99 -> V_65 -> V_21 ;
V_99 -> V_65 -> V_21 = F_7 ( V_99 -> V_65 -> V_21 ) ;
if ( V_99 -> V_65 -> V_21 > V_99 -> V_65 -> V_79 ) {
F_105 ( 1 , L_5 ) ;
V_99 -> V_65 -> V_21 = V_99 -> V_65 -> V_79 ;
}
if ( V_99 -> V_65 -> V_21 == V_99 -> V_65 -> V_79 )
F_106 ( V_99 , V_102 , F_98 ) ;
else
F_107 ( V_99 , 0 , F_98 ) ;
}
return V_101 ;
}
struct V_9 * F_108 ( struct V_98 * V_99 ,
struct V_35 * V_36 , T_4 V_103 )
{
struct V_9 * V_101 ;
do {
V_101 = F_104 ( V_99 ) ;
} while ( V_101 && V_103 ( V_36 , V_101 ) );
return V_101 ;
}
struct V_9 * F_109 ( struct V_35 * V_36 , struct V_9 * V_94 )
{
struct V_98 V_99 ;
F_110 ( V_36 , & V_99 , V_94 ) ;
return F_108 ( & V_99 , V_36 , F_21 ) ;
}
static void F_111 ( struct V_98 * V_99 ,
struct V_97 * V_24 )
{
V_24 -> V_21 = F_7 ( V_24 -> V_21 ) ;
if ( V_24 -> V_21 == V_24 -> V_79 )
* V_24 = V_99 -> V_65 [ -- V_99 -> V_100 ] ;
}
static void F_112 ( struct V_98 * V_99 )
{
while ( V_99 -> V_100 > 1 ) {
struct V_97 * V_8 = V_99 -> V_65 , * V_24 = V_8 + 1 ;
if ( V_99 -> V_100 > 2 &&
F_98 ( V_24 [ 0 ] , V_24 [ 1 ] ) )
V_24 ++ ;
if ( F_22 ( V_8 -> V_21 , & F_39 ( V_24 -> V_21 ) ) <= 0 )
break;
if ( ! F_10 ( V_24 -> V_21 ) ) {
F_111 ( V_99 , V_24 ) ;
F_107 ( V_99 , V_24 - V_8 , F_98 ) ;
continue;
}
if ( V_8 -> V_21 > V_24 -> V_21 ) {
if ( F_22 ( V_8 -> V_21 , V_24 -> V_21 ) >= 0 )
F_111 ( V_99 , V_24 ) ;
else
F_51 ( V_8 -> V_21 , V_24 -> V_21 ) ;
F_107 ( V_99 , V_24 - V_8 , F_98 ) ;
} else {
F_35 ( ! F_22 ( & F_39 ( V_8 -> V_21 ) , & F_39 ( V_24 -> V_21 ) ) ) ;
F_113 ( & F_39 ( V_24 -> V_21 ) , V_8 -> V_21 ) ;
}
}
}
static void F_114 ( struct V_35 * V_36 , struct V_89 * V_104 ,
struct V_98 * V_99 ,
bool V_105 , bool V_106 )
{
struct V_9 * V_21 , * V_107 = NULL ;
bool (* V_26)( struct V_35 * , const struct V_9 * ) = V_106
? F_21
: F_23 ;
while ( ! F_99 ( V_99 ) ) {
if ( V_105 && ! V_36 -> V_23 )
F_112 ( V_99 ) ;
V_21 = F_104 ( V_99 ) ;
if ( V_26 ( V_36 , V_21 ) )
continue;
if ( ! V_107 ) {
V_107 = V_104 -> V_77 ;
F_115 ( V_107 , V_21 ) ;
} else if ( V_36 -> V_23 ||
! F_47 ( V_36 , V_107 , V_21 ) ) {
V_107 = F_7 ( V_107 ) ;
F_115 ( V_107 , V_21 ) ;
}
}
V_104 -> V_78 = V_107 ? ( V_7 * ) F_7 ( V_107 ) - V_104 -> V_5 : 0 ;
F_116 ( L_6 , V_104 -> V_78 ) ;
F_117 ( V_36 , V_104 ) ;
}
static void F_118 ( struct V_35 * V_36 , struct V_98 * V_99 ,
unsigned V_77 , unsigned V_108 , bool V_105 )
{
V_7 V_109 ;
bool V_106 = ! V_36 -> V_110 ;
struct V_89 * V_104 = ( void * ) F_119 ( V_111 | V_20 ,
V_108 ) ;
if ( ! V_104 ) {
F_120 ( & V_36 -> V_13 -> V_112 ) ;
V_104 = V_36 -> V_13 -> V_113 ;
V_108 = F_121 ( F_122 ( V_36 -> V_13 ) ) ;
}
V_109 = F_123 () ;
F_114 ( V_36 , V_104 , V_99 , V_105 , V_106 ) ;
V_36 -> V_84 = V_77 ;
if ( ! V_105 && ! V_77 && V_36 -> V_110 )
F_124 ( V_36 , V_104 ) ;
if ( ! V_77 && V_108 == V_36 -> V_114 ) {
V_104 -> V_91 = F_91 ( V_36 -> V_13 ) ;
V_104 -> V_90 = V_36 -> V_82 [ 0 ] . V_65 -> V_90 ;
V_104 -> V_92 = V_36 -> V_82 [ 0 ] . V_65 -> V_92 ;
F_125 ( V_104 , V_36 -> V_82 [ 0 ] . V_65 ) ;
if ( V_36 -> V_13 -> V_113 == V_36 -> V_82 [ 0 ] . V_65 )
V_36 -> V_13 -> V_113 = V_104 ;
} else {
V_36 -> V_82 [ V_77 ] . V_65 -> V_78 = V_104 -> V_78 ;
memcpy ( V_36 -> V_82 [ V_77 ] . V_65 -> V_77 , V_104 -> V_77 ,
( void * ) V_79 ( V_104 ) - ( void * ) V_104 -> V_77 ) ;
}
if ( V_104 == V_36 -> V_13 -> V_113 )
F_31 ( & V_36 -> V_13 -> V_112 ) ;
else
F_126 ( ( unsigned long ) V_104 , V_108 ) ;
if ( V_36 -> V_110 )
F_81 ( V_36 ) ;
if ( ! V_77 ) {
F_127 ( & V_36 -> V_13 -> V_115 ) ;
F_128 ( & V_36 -> V_13 -> V_116 , V_109 ) ;
F_129 ( & V_36 -> V_13 -> V_115 ) ;
}
}
void F_130 ( struct V_35 * V_36 , unsigned V_77 )
{
T_1 V_14 = 0 , V_108 = V_36 -> V_114 , V_78 = 0 ;
struct V_98 V_99 ;
F_101 ( V_36 , & V_99 , NULL , & V_36 -> V_82 [ V_77 ] ) ;
F_35 ( V_36 -> V_82 [ V_36 -> V_84 ] . V_65 == F_89 ( V_36 ) &&
( V_36 -> V_82 [ V_36 -> V_84 ] . V_58 || V_36 -> V_84 ) ) ;
if ( V_36 -> V_110 )
V_14 = F_131 ( V_36 ) ;
if ( V_77 ) {
unsigned V_24 ;
for ( V_24 = V_77 ; V_24 <= V_36 -> V_84 ; V_24 ++ )
V_78 += V_36 -> V_82 [ V_24 ] . V_65 -> V_78 ;
V_108 = F_4 ( F_132 ( V_36 -> V_82 -> V_65 ,
V_78 ) ) / V_117 ;
if ( V_108 )
V_108 = F_121 ( V_108 ) ;
}
F_118 ( V_36 , & V_99 , V_77 , V_108 , false ) ;
F_133 ( V_36 -> V_110 && F_131 ( V_36 ) != V_14 ) ;
}
void F_134 ( struct V_35 * V_36 , struct V_98 * V_99 )
{
F_35 ( ! V_36 -> V_110 ) ;
F_118 ( V_36 , V_99 , 0 , V_36 -> V_114 , true ) ;
}
void F_135 ( struct V_35 * V_36 , struct V_35 * V_16 )
{
V_7 V_109 = F_123 () ;
struct V_98 V_99 ;
F_110 ( V_36 , & V_99 , NULL ) ;
F_114 ( V_36 , V_16 -> V_82 -> V_65 , & V_99 , false , true ) ;
F_127 ( & V_36 -> V_13 -> V_115 ) ;
F_128 ( & V_36 -> V_13 -> V_116 , V_109 ) ;
F_129 ( & V_36 -> V_13 -> V_115 ) ;
F_40 ( & V_16 -> V_118 , & V_36 -> V_118 ) ;
V_16 -> V_82 -> V_58 = 0 ;
}
void F_136 ( struct V_35 * V_36 )
{
unsigned V_119 = V_120 ;
int V_24 ;
if ( ! V_36 -> V_84 )
goto V_104;
if ( V_36 -> V_23 ) {
F_137 ( V_36 ) ;
return;
}
for ( V_24 = V_36 -> V_84 - 1 ; V_24 >= 0 ; -- V_24 ) {
V_119 *= V_36 -> V_13 -> V_121 ;
if ( V_36 -> V_82 [ V_24 ] . V_65 -> V_78 < V_119 ) {
F_130 ( V_36 , V_24 ) ;
return;
}
}
if ( V_36 -> V_84 + 1 == V_83 ) {
F_137 ( V_36 ) ;
return;
}
V_104:
F_81 ( V_36 ) ;
}
static int F_138 ( struct V_35 * V_36 , struct V_122 * V_123 ,
struct V_124 * V_125 )
{
struct V_9 * V_21 ;
unsigned V_24 ;
V_125 -> V_126 ++ ;
for ( V_24 = 0 ; V_24 <= V_36 -> V_84 ; V_24 ++ ) {
struct V_61 * V_62 = & V_36 -> V_82 [ V_24 ] ;
T_1 V_127 = V_62 -> V_65 -> V_78 * sizeof( V_7 ) ;
T_1 V_57 ;
if ( F_86 ( V_36 , V_62 ) ) {
V_125 -> V_128 ++ ;
V_125 -> V_129 += V_127 ;
V_125 -> V_130 += V_62 -> V_58 - 1 ;
for ( V_57 = 1 ; V_57 < V_62 -> V_58 ; V_57 ++ )
if ( V_62 -> V_67 [ V_57 ] . V_75 == 127 )
V_125 -> V_131 ++ ;
} else {
V_125 -> V_132 ++ ;
V_125 -> V_133 += V_127 ;
}
}
if ( V_36 -> V_23 ) {
struct V_98 V_99 ;
F_139 (b, k, &iter, bch_ptr_bad) {
int V_101 = V_35 ( V_124 , V_21 , V_36 , V_123 , V_125 ) ;
if ( V_101 )
return V_101 ;
}
}
return 0 ;
}
int F_140 ( struct V_12 * V_13 , char * V_25 )
{
struct V_122 V_123 ;
struct V_124 V_62 ;
int V_101 ;
F_141 ( & V_123 ) ;
memset ( & V_62 , 0 , sizeof( struct V_124 ) ) ;
V_101 = F_142 ( V_124 , V_13 , & V_123 , & V_62 ) ;
if ( V_101 )
return V_101 ;
return snprintf ( V_25 , V_117 ,
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ,
V_62 . V_126 ,
V_62 . V_128 , V_62 . V_132 ,
V_62 . V_129 , V_62 . V_133 ,
V_62 . V_130 , V_62 . V_131 ) ;
}
