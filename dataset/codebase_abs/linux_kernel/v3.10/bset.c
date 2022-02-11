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
if ( V_23 && ( ! F_9 ( V_21 ) || ! F_10 ( V_21 ) || F_11 ( V_21 ) ) )
goto V_25;
if ( ! V_23 && F_10 ( V_21 ) > F_12 ( V_21 ) )
goto V_25;
if ( ! F_10 ( V_21 ) )
return true ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
if ( F_13 ( V_13 , V_21 , V_24 ) ) {
struct V_26 * V_27 = F_14 ( V_13 , V_21 , V_24 ) ;
T_1 V_28 = F_15 ( V_13 , V_21 , V_24 ) ;
T_1 V_29 = F_16 ( V_13 , F_17 ( V_21 , V_24 ) ) ;
if ( F_10 ( V_21 ) + V_29 > V_13 -> V_30 . V_31 ||
V_28 < V_27 -> V_30 . V_32 ||
V_28 >= V_27 -> V_30 . V_33 )
goto V_25;
}
return false ;
V_25:
F_18 ( V_13 , L_1 , F_19 ( V_21 ) , F_20 ( V_13 , V_21 ) ) ;
return true ;
}
bool F_21 ( struct V_34 * V_35 , const struct V_9 * V_21 )
{
struct V_28 * V_36 ;
unsigned V_24 , V_37 ;
if ( ! F_22 ( V_21 , & V_38 ) ||
! F_9 ( V_21 ) ||
F_23 ( V_35 , V_21 ) )
return true ;
if ( F_9 ( V_21 ) && F_24 ( V_21 , 0 ) == V_39 )
return true ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
if ( F_13 ( V_35 -> V_13 , V_21 , V_24 ) ) {
V_36 = F_25 ( V_35 -> V_13 , V_21 , V_24 ) ;
V_37 = F_26 ( V_35 -> V_13 , V_21 , V_24 ) ;
F_27 ( V_37 > 96 , V_35 ,
L_2 ,
V_37 , V_35 -> V_13 -> V_40 ) ;
F_27 ( V_37 && F_11 ( V_21 ) && F_10 ( V_21 ) ,
V_35 , L_3 ) ;
if ( V_37 )
return true ;
#ifdef F_28
if ( ! F_29 ( & V_35 -> V_13 -> V_41 ) )
continue;
if ( V_35 -> V_23 ) {
if ( F_11 ( V_21 ) ||
V_36 -> V_42 != V_43 ||
( V_35 -> V_13 -> V_44 &&
F_30 ( V_36 ) != V_45 ) )
goto V_46;
} else {
if ( V_36 -> V_42 == V_43 )
goto V_46;
if ( F_11 ( V_21 ) &&
V_35 -> V_13 -> V_44 &&
F_30 ( V_36 ) != V_47 )
goto V_46;
}
F_31 ( & V_35 -> V_13 -> V_41 ) ;
#endif
}
return false ;
#ifdef F_28
V_46:
F_31 ( & V_35 -> V_13 -> V_41 ) ;
F_32 ( V_35 ,
L_4 ,
F_19 ( V_21 ) , F_15 ( V_35 -> V_13 , V_21 , V_24 ) , F_33 ( & V_36 -> V_48 ) ,
V_36 -> V_42 , V_36 -> V_49 , V_36 -> V_50 , F_30 ( V_36 ) , V_36 -> V_51 ) ;
return true ;
#endif
}
void F_34 ( struct V_9 * V_2 , const struct V_9 * V_3 ,
unsigned V_24 )
{
F_35 ( V_24 > F_9 ( V_3 ) ) ;
memcpy ( V_2 , V_3 , 2 * sizeof( V_7 ) ) ;
V_2 -> V_52 [ 0 ] = V_3 -> V_52 [ V_24 ] ;
F_36 ( V_2 , 1 ) ;
F_37 ( V_2 , 0 ) ;
}
bool F_38 ( const struct V_9 * V_53 , struct V_9 * V_21 )
{
unsigned V_24 , V_54 = 0 ;
if ( F_22 ( V_53 , & F_39 ( V_21 ) ) <= 0 )
return false ;
if ( F_22 ( V_53 , V_21 ) < 0 )
V_54 = F_12 ( V_21 ) - F_12 ( V_53 ) ;
else
F_40 ( V_21 , V_53 ) ;
for ( V_24 = 0 ; V_24 < F_9 ( V_21 ) ; V_24 ++ )
F_41 ( V_21 , V_24 , F_17 ( V_21 , V_24 ) + F_10 ( V_21 ) - V_54 ) ;
F_35 ( V_54 > F_10 ( V_21 ) ) ;
F_42 ( V_21 , V_54 ) ;
return true ;
}
bool F_43 ( const struct V_9 * V_53 , struct V_9 * V_21 )
{
unsigned V_54 = 0 ;
if ( F_22 ( V_53 , V_21 ) >= 0 )
return false ;
F_35 ( F_44 ( V_53 ) != F_44 ( V_21 ) ) ;
if ( F_22 ( V_53 , & F_39 ( V_21 ) ) > 0 )
V_54 = F_12 ( V_53 ) - F_45 ( V_21 ) ;
F_40 ( V_21 , V_53 ) ;
F_35 ( V_54 > F_10 ( V_21 ) ) ;
F_42 ( V_21 , V_54 ) ;
return true ;
}
static V_7 F_46 ( struct V_9 * V_10 , struct V_9 * V_29 )
{
return ( V_10 -> V_52 [ F_9 ( V_10 ) ] + V_29 -> V_52 [ F_9 ( V_29 ) ] ) &
~ ( ( V_7 ) 1 << 63 ) ;
}
bool F_47 ( struct V_34 * V_35 , struct V_9 * V_10 , struct V_9 * V_29 )
{
unsigned V_24 ;
if ( F_48 ( V_35 -> V_13 ) )
return false ;
if ( F_9 ( V_10 ) != F_9 ( V_29 ) ||
F_11 ( V_10 ) != F_11 ( V_29 ) ||
F_22 ( V_10 , & F_39 ( V_29 ) ) )
return false ;
for ( V_24 = 0 ; V_24 < F_9 ( V_10 ) ; V_24 ++ )
if ( V_10 -> V_52 [ V_24 ] + F_49 ( 0 , F_10 ( V_10 ) , 0 ) != V_29 -> V_52 [ V_24 ] ||
F_15 ( V_35 -> V_13 , V_10 , V_24 ) != F_15 ( V_35 -> V_13 , V_29 , V_24 ) )
return false ;
if ( F_10 ( V_10 ) + F_10 ( V_29 ) > V_55 ) {
F_50 ( V_10 , F_12 ( V_10 ) + V_55 - F_10 ( V_10 ) ) ;
F_42 ( V_10 , V_55 ) ;
F_51 ( V_10 , V_29 ) ;
return false ;
}
if ( F_52 ( V_10 ) ) {
if ( F_52 ( V_29 ) )
V_10 -> V_52 [ F_9 ( V_10 ) ] = F_46 ( V_10 , V_29 ) ;
else
F_37 ( V_10 , 0 ) ;
}
F_50 ( V_10 , F_12 ( V_10 ) + F_10 ( V_29 ) ) ;
F_42 ( V_10 , F_10 ( V_10 ) + F_10 ( V_29 ) ) ;
return true ;
}
static unsigned F_53 ( unsigned V_56 , unsigned V_57 )
{
if ( V_56 * 2 + 1 < V_57 ) {
V_56 = V_56 * 2 + 1 ;
while ( V_56 * 2 < V_57 )
V_56 *= 2 ;
} else
V_56 >>= F_54 ( V_56 ) + 1 ;
return V_56 ;
}
static unsigned F_55 ( unsigned V_56 , unsigned V_57 )
{
if ( V_56 * 2 < V_57 ) {
V_56 = V_56 * 2 ;
while ( V_56 * 2 + 1 < V_57 )
V_56 = V_56 * 2 + 1 ;
} else
V_56 >>= F_56 ( V_56 ) ;
return V_56 ;
}
static unsigned F_57 ( unsigned V_56 , unsigned V_57 , unsigned V_58 )
{
unsigned V_35 = F_58 ( V_56 ) ;
unsigned V_59 = F_58 ( V_57 - 1 ) - V_35 ;
V_56 ^= 1U << ( V_35 - 1 ) ;
V_56 <<= 1 ;
V_56 |= 1 ;
V_56 <<= V_59 ;
if ( V_56 > V_58 )
V_56 -= ( V_56 - V_58 ) >> 1 ;
return V_56 ;
}
static unsigned F_59 ( unsigned V_56 , struct V_60 * V_61 )
{
return F_57 ( V_56 , V_61 -> V_57 , V_61 -> V_58 ) ;
}
static unsigned F_60 ( unsigned V_56 , unsigned V_57 , unsigned V_58 )
{
unsigned V_59 ;
if ( V_56 > V_58 )
V_56 += V_56 - V_58 ;
V_59 = F_56 ( V_56 ) ;
V_56 >>= V_59 ;
V_56 |= F_4 ( V_57 ) >> V_59 ;
return V_56 ;
}
static unsigned F_61 ( unsigned V_56 , struct V_60 * V_61 )
{
return F_60 ( V_56 , V_61 -> V_57 , V_61 -> V_58 ) ;
}
static struct V_9 * F_62 ( struct V_60 * V_61 , unsigned V_62 ,
unsigned V_63 )
{
return ( ( void * ) V_61 -> V_64 ) + V_62 * V_65 + V_63 * 8 ;
}
static unsigned F_63 ( struct V_60 * V_61 , struct V_9 * V_21 )
{
return ( ( void * ) V_21 - ( void * ) V_61 -> V_64 ) / V_65 ;
}
static unsigned F_64 ( struct V_9 * V_21 )
{
return ( ( T_1 ) V_21 & ( V_65 - 1 ) ) / sizeof( V_7 ) ;
}
static struct V_9 * F_65 ( struct V_60 * V_61 , unsigned V_56 )
{
return F_62 ( V_61 , F_59 ( V_56 , V_61 ) , V_61 -> V_66 [ V_56 ] . V_67 ) ;
}
static struct V_9 * F_66 ( struct V_60 * V_61 , unsigned V_56 )
{
return ( void * ) ( ( ( V_7 * ) F_65 ( V_61 , V_56 ) ) - V_61 -> V_68 [ V_56 ] ) ;
}
static struct V_9 * F_67 ( struct V_60 * V_61 , unsigned V_62 )
{
return F_62 ( V_61 , V_62 , V_61 -> V_68 [ V_62 ] ) ;
}
static inline V_7 F_68 ( V_7 V_69 , V_7 V_70 , T_2 V_59 )
{
#ifdef F_69
asm("shrd %[shift],%[high],%[low]"
: [low] "+Rm" (low)
: [high] "R" (high),
[shift] "ci" (shift)
: "cc");
#else
V_70 >>= V_59 ;
V_70 |= ( V_69 << 1 ) << ( 63U - V_59 ) ;
#endif
return V_70 ;
}
static inline unsigned F_70 ( const struct V_9 * V_21 ,
struct V_71 * V_72 )
{
const V_7 * V_73 = & V_21 -> V_70 - ( V_72 -> V_74 >> 6 ) ;
return F_68 ( V_73 [ - 1 ] , V_73 [ 0 ] , V_72 -> V_74 & 63 ) & V_75 ;
}
static void F_71 ( struct V_60 * V_61 , unsigned V_56 )
{
struct V_71 * V_72 = & V_61 -> V_66 [ V_56 ] ;
struct V_9 * V_67 = F_65 ( V_61 , V_56 ) ;
struct V_9 * V_73 = F_66 ( V_61 , V_56 ) ;
struct V_9 * V_10 = F_72 ( V_56 )
? V_61 -> V_64 -> V_76
: F_66 ( V_61 , V_56 >> F_56 ( V_56 ) ) ;
struct V_9 * V_29 = F_72 ( V_56 + 1 )
? F_73 ( V_61 -> V_64 , V_61 -> V_64 -> V_77 - F_74 ( & V_61 -> V_78 ) )
: F_65 ( V_61 , V_56 >> ( F_54 ( V_56 ) + 1 ) ) ;
F_35 ( V_67 < V_10 || V_67 > V_29 ) ;
F_35 ( F_7 ( V_73 ) != V_67 ) ;
if ( F_44 ( V_10 ) != F_44 ( V_29 ) )
V_72 -> V_74 = F_75 ( F_44 ( V_29 ) ^ F_44 ( V_10 ) ) + 64 ;
else
V_72 -> V_74 = F_75 ( V_29 -> V_70 ^ V_10 -> V_70 ) ;
V_72 -> V_74 = F_76 ( int , V_72 -> V_74 - V_79 , 0 ) ;
if ( F_70 ( V_67 , V_72 ) != F_70 ( V_73 , V_72 ) )
V_72 -> V_80 = F_70 ( V_67 , V_72 ) - 1 ;
else
V_72 -> V_74 = 127 ;
}
static void F_77 ( struct V_34 * V_35 , struct V_60 * V_61 )
{
if ( V_61 != V_35 -> V_81 ) {
unsigned V_56 = F_78 ( V_61 [ - 1 ] . V_57 ,
64 / sizeof( struct V_71 ) ) ;
V_61 -> V_66 = V_61 [ - 1 ] . V_66 + V_56 ;
V_61 -> V_68 = V_61 [ - 1 ] . V_68 + V_56 ;
}
while ( V_61 < V_35 -> V_81 + V_82 )
V_61 ++ -> V_57 = 0 ;
}
static void F_79 ( struct V_34 * V_35 )
{
struct V_60 * V_61 = V_35 -> V_81 + V_35 -> V_83 ;
F_77 ( V_35 , V_61 ) ;
if ( V_61 -> V_66 != V_35 -> V_81 -> V_66 + F_80 ( V_35 ) ) {
V_61 -> V_68 [ 0 ] = F_64 ( V_61 -> V_64 -> V_76 ) ;
V_61 -> V_57 = 1 ;
}
}
static void F_81 ( struct V_34 * V_35 )
{
struct V_60 * V_61 = V_35 -> V_81 + V_35 -> V_83 ;
struct V_9 * V_21 = V_61 -> V_64 -> V_76 ;
unsigned V_56 , V_62 = 1 ;
F_77 ( V_35 , V_61 ) ;
V_61 -> V_57 = F_82 ( unsigned ,
F_63 ( V_61 , V_78 ( V_61 -> V_64 ) ) ,
V_35 -> V_81 -> V_66 + F_80 ( V_35 ) - V_61 -> V_66 ) ;
if ( V_61 -> V_57 < 2 ) {
V_61 -> V_57 = 0 ;
return;
}
V_61 -> V_58 = ( V_61 -> V_57 - F_83 ( V_61 -> V_57 - 1 ) ) << 1 ;
for ( V_56 = F_53 ( 0 , V_61 -> V_57 ) ;
V_56 ;
V_56 = F_53 ( V_56 , V_61 -> V_57 ) ) {
while ( F_63 ( V_61 , V_21 ) != V_62 )
V_21 = F_7 ( V_21 ) ;
V_61 -> V_68 [ V_56 ] = F_74 ( V_21 ) ;
V_21 = F_7 ( V_21 ) ;
V_62 ++ ;
V_61 -> V_66 [ V_56 ] . V_67 = F_64 ( V_21 ) ;
}
while ( F_7 ( V_21 ) != V_78 ( V_61 -> V_64 ) )
V_21 = F_7 ( V_21 ) ;
V_61 -> V_78 = * V_21 ;
for ( V_56 = F_53 ( 0 , V_61 -> V_57 ) ;
V_56 ;
V_56 = F_53 ( V_56 , V_61 -> V_57 ) )
F_71 ( V_61 , V_56 ) ;
}
void F_84 ( struct V_34 * V_35 , struct V_9 * V_21 )
{
struct V_60 * V_61 ;
unsigned V_84 , V_56 = 1 ;
for ( V_61 = V_35 -> V_81 ; V_61 <= & V_35 -> V_81 [ V_35 -> V_83 ] ; V_61 ++ )
if ( V_21 < V_78 ( V_61 -> V_64 ) )
goto V_85;
F_85 () ;
V_85:
if ( ! V_61 -> V_57 || ! F_86 ( V_35 , V_61 ) )
return;
V_84 = F_63 ( V_61 , V_21 ) ;
if ( V_21 == V_61 -> V_64 -> V_76 )
goto V_86;
if ( F_7 ( V_21 ) == V_78 ( V_61 -> V_64 ) ) {
V_61 -> V_78 = * V_21 ;
goto V_87;
}
V_56 = F_61 ( V_84 , V_61 ) ;
if ( V_56 &&
V_56 < V_61 -> V_57 &&
V_21 == F_65 ( V_61 , V_56 ) )
V_86: do {
F_71 ( V_61 , V_56 ) ;
V_56 = V_56 * 2 ;
} while ( V_56 < V_61 -> V_57 );
V_56 = F_61 ( V_84 + 1 , V_61 ) ;
if ( V_56 &&
V_56 < V_61 -> V_57 &&
V_21 == F_66 ( V_61 , V_56 ) )
V_87: do {
F_71 ( V_61 , V_56 ) ;
V_56 = V_56 * 2 + 1 ;
} while ( V_56 < V_61 -> V_57 );
}
void F_87 ( struct V_34 * V_35 , struct V_9 * V_21 )
{
struct V_60 * V_61 = & V_35 -> V_81 [ V_35 -> V_83 ] ;
unsigned V_59 = F_74 ( V_21 ) ;
unsigned V_56 = F_63 ( V_61 , V_21 ) ;
if ( ! V_61 -> V_57 )
return;
if ( V_56 < V_61 -> V_57 &&
F_67 ( V_61 , V_56 ) <= V_21 )
V_56 ++ ;
for (; V_56 < V_61 -> V_57 ; V_56 ++ ) {
V_61 -> V_68 [ V_56 ] += V_59 ;
if ( V_61 -> V_68 [ V_56 ] > 7 ) {
V_21 = F_67 ( V_61 , V_56 - 1 ) ;
while ( V_21 < F_62 ( V_61 , V_56 , 0 ) )
V_21 = F_7 ( V_21 ) ;
V_61 -> V_68 [ V_56 ] = F_64 ( V_21 ) ;
}
}
if ( V_61 -> V_57 == V_35 -> V_81 -> V_66 + F_80 ( V_35 ) - V_61 -> V_66 )
return;
for ( V_21 = F_67 ( V_61 , V_61 -> V_57 - 1 ) ;
V_21 != V_78 ( V_61 -> V_64 ) ;
V_21 = F_7 ( V_21 ) )
if ( V_61 -> V_57 == F_63 ( V_61 , V_21 ) ) {
V_61 -> V_68 [ V_61 -> V_57 ] = F_64 ( V_21 ) ;
V_61 -> V_57 ++ ;
}
}
void F_88 ( struct V_34 * V_35 )
{
struct V_88 * V_24 = F_89 ( V_35 ) ;
if ( V_24 != V_35 -> V_81 [ 0 ] . V_64 ) {
V_35 -> V_81 [ ++ V_35 -> V_83 ] . V_64 = V_24 ;
V_24 -> V_89 = V_35 -> V_81 [ 0 ] . V_64 -> V_89 ;
} else
F_90 ( & V_24 -> V_89 , sizeof( V_7 ) ) ;
V_24 -> V_90 = F_91 ( V_35 -> V_13 ) ;
V_24 -> V_91 = 0 ;
V_24 -> V_77 = 0 ;
F_79 ( V_35 ) ;
}
static struct V_92 F_92 ( struct V_34 * V_35 ,
struct V_60 * V_61 ,
const struct V_9 * V_93 )
{
unsigned V_94 = 0 , V_95 = V_61 -> V_57 ;
F_35 ( ! V_35 -> V_83 &&
V_61 -> V_57 < F_63 ( V_61 , V_78 ( V_61 -> V_64 ) ) ) ;
while ( V_94 + 1 != V_95 ) {
unsigned V_67 = ( V_94 + V_95 ) >> 1 ;
if ( F_22 ( F_67 ( V_61 , V_67 ) , V_93 ) > 0 )
V_95 = V_67 ;
else
V_94 = V_67 ;
}
return (struct V_92 ) {
F_67 ( V_61 , V_94 ) ,
V_95 < V_61 -> V_57 ? F_67 ( V_61 , V_95 ) : V_78 (t->data)
} ;
}
static struct V_92 F_93 ( struct V_34 * V_35 ,
struct V_60 * V_61 ,
const struct V_9 * V_93 )
{
struct V_9 * V_10 , * V_29 ;
struct V_71 * V_72 ;
unsigned V_84 , V_56 , V_6 = 1 ;
do {
unsigned V_73 = V_6 << 4 ;
V_73 &= ( ( int ) ( V_73 - V_61 -> V_57 ) ) >> 31 ;
F_94 ( & V_61 -> V_66 [ V_73 ] ) ;
V_56 = V_6 ;
V_72 = & V_61 -> V_66 [ V_56 ] ;
if ( F_95 ( V_72 -> V_74 != 127 ) )
V_6 = V_56 * 2 + ( ( ( unsigned )
( V_72 -> V_80 -
F_70 ( V_93 , V_72 ) ) ) >> 31 ) ;
else
V_6 = ( F_22 ( F_65 ( V_61 , V_56 ) , V_93 ) > 0 )
? V_56 * 2
: V_56 * 2 + 1 ;
} while ( V_6 < V_61 -> V_57 );
V_84 = F_59 ( V_56 , V_61 ) ;
if ( V_6 & 1 ) {
V_10 = F_62 ( V_61 , V_84 , V_72 -> V_67 ) ;
if ( ++ V_84 != V_61 -> V_57 ) {
V_72 = & V_61 -> V_66 [ F_53 ( V_56 , V_61 -> V_57 ) ] ;
V_29 = F_62 ( V_61 , V_84 , V_72 -> V_67 ) ;
} else
V_29 = V_78 ( V_61 -> V_64 ) ;
} else {
V_29 = F_62 ( V_61 , V_84 , V_72 -> V_67 ) ;
if ( -- V_84 ) {
V_72 = & V_61 -> V_66 [ F_55 ( V_56 , V_61 -> V_57 ) ] ;
V_10 = F_62 ( V_61 , V_84 , V_72 -> V_67 ) ;
} else
V_10 = V_61 -> V_64 -> V_76 ;
}
return (struct V_92 ) { V_10 , V_29 } ;
}
struct V_9 * F_96 ( struct V_34 * V_35 , struct V_60 * V_61 ,
const struct V_9 * V_93 )
{
struct V_92 V_24 ;
if ( F_97 ( ! V_61 -> V_57 ) ) {
V_24 . V_10 = V_61 -> V_64 -> V_76 ;
V_24 . V_29 = V_78 ( V_61 -> V_64 ) ;
} else if ( F_86 ( V_35 , V_61 ) ) {
if ( F_97 ( F_22 ( V_93 , & V_61 -> V_78 ) >= 0 ) )
return V_78 ( V_61 -> V_64 ) ;
if ( F_97 ( F_22 ( V_93 , V_61 -> V_64 -> V_76 ) < 0 ) )
return V_61 -> V_64 -> V_76 ;
V_24 = F_93 ( V_35 , V_61 , V_93 ) ;
} else
V_24 = F_92 ( V_35 , V_61 , V_93 ) ;
#ifdef F_28
F_35 ( F_86 ( V_35 , V_61 ) &&
V_24 . V_10 != V_61 -> V_64 -> V_76 &&
F_22 ( F_66 ( V_61 ,
F_61 ( F_63 ( V_61 , V_24 . V_10 ) , V_61 ) ) ,
V_93 ) > 0 ) ;
F_35 ( V_24 . V_29 != V_78 ( V_61 -> V_64 ) &&
F_22 ( V_24 . V_29 , V_93 ) <= 0 ) ;
#endif
while ( F_95 ( V_24 . V_10 != V_24 . V_29 ) &&
F_22 ( V_24 . V_10 , V_93 ) <= 0 )
V_24 . V_10 = F_7 ( V_24 . V_10 ) ;
return V_24 . V_10 ;
}
static inline bool F_98 ( struct V_96 V_10 ,
struct V_96 V_29 )
{
T_3 V_13 = F_22 ( & F_39 ( V_10 . V_21 ) , & F_39 ( V_29 . V_21 ) ) ;
return V_13 ? V_13 > 0 : V_10 . V_21 < V_29 . V_21 ;
}
static inline bool F_99 ( struct V_97 * V_98 )
{
return ! V_98 -> V_99 ;
}
void F_100 ( struct V_97 * V_98 , struct V_9 * V_21 ,
struct V_9 * V_78 )
{
if ( V_21 != V_78 )
F_35 (!heap_add(iter,
((struct btree_iter_set) { k, end }),
btree_iter_cmp)) ;
}
struct V_9 * F_101 ( struct V_34 * V_35 , struct V_97 * V_98 ,
struct V_9 * V_93 , struct V_60 * V_76 )
{
struct V_9 * V_100 = NULL ;
V_98 -> V_57 = F_102 ( V_98 -> V_64 ) ;
V_98 -> V_99 = 0 ;
for (; V_76 <= & V_35 -> V_81 [ V_35 -> V_83 ] ; V_76 ++ ) {
V_100 = F_103 ( V_35 , V_76 , V_93 ) ;
F_100 ( V_98 , V_100 , V_78 ( V_76 -> V_64 ) ) ;
}
return V_100 ;
}
struct V_9 * F_104 ( struct V_97 * V_98 )
{
struct V_96 V_101 ;
struct V_9 * V_100 = NULL ;
if ( ! F_99 ( V_98 ) ) {
V_100 = V_98 -> V_64 -> V_21 ;
V_98 -> V_64 -> V_21 = F_7 ( V_98 -> V_64 -> V_21 ) ;
if ( V_98 -> V_64 -> V_21 > V_98 -> V_64 -> V_78 ) {
F_105 ( 1 , L_5 ) ;
V_98 -> V_64 -> V_21 = V_98 -> V_64 -> V_78 ;
}
if ( V_98 -> V_64 -> V_21 == V_98 -> V_64 -> V_78 )
F_106 ( V_98 , V_101 , F_98 ) ;
else
F_107 ( V_98 , 0 , F_98 ) ;
}
return V_100 ;
}
struct V_9 * F_108 ( struct V_97 * V_98 ,
struct V_34 * V_35 , T_4 V_102 )
{
struct V_9 * V_100 ;
do {
V_100 = F_104 ( V_98 ) ;
} while ( V_100 && V_102 ( V_35 , V_100 ) );
return V_100 ;
}
struct V_9 * F_109 ( struct V_34 * V_35 , struct V_9 * V_93 )
{
struct V_97 V_98 ;
F_110 ( V_35 , & V_98 , V_93 ) ;
return F_108 ( & V_98 , V_35 , F_21 ) ;
}
static void F_111 ( struct V_97 * V_98 )
{
while ( V_98 -> V_99 > 1 ) {
struct V_96 * V_8 = V_98 -> V_64 , * V_24 = V_8 + 1 ;
struct V_9 * V_21 ;
if ( V_98 -> V_99 > 2 &&
F_98 ( V_24 [ 0 ] , V_24 [ 1 ] ) )
V_24 ++ ;
for ( V_21 = V_24 -> V_21 ;
V_21 != V_24 -> V_78 && F_22 ( V_8 -> V_21 , & F_39 ( V_21 ) ) > 0 ;
V_21 = F_7 ( V_21 ) )
if ( V_8 -> V_21 > V_24 -> V_21 )
F_38 ( V_8 -> V_21 , V_21 ) ;
else if ( F_10 ( V_21 ) )
F_112 ( & F_39 ( V_21 ) , V_8 -> V_21 ) ;
if ( V_8 -> V_21 < V_24 -> V_21 || V_21 == V_24 -> V_21 )
break;
F_107 ( V_98 , V_24 - V_8 , F_98 ) ;
}
}
static void F_113 ( struct V_34 * V_35 , struct V_88 * V_103 ,
struct V_97 * V_98 ,
bool V_104 , bool V_105 )
{
struct V_9 * V_21 , * V_106 = NULL ;
bool (* V_25)( struct V_34 * , const struct V_9 * ) = V_105
? F_21
: F_23 ;
while ( ! F_99 ( V_98 ) ) {
if ( V_104 && ! V_35 -> V_23 )
F_111 ( V_98 ) ;
V_21 = F_104 ( V_98 ) ;
if ( V_25 ( V_35 , V_21 ) )
continue;
if ( ! V_106 ) {
V_106 = V_103 -> V_76 ;
F_114 ( V_106 , V_21 ) ;
} else if ( V_35 -> V_23 ||
! F_47 ( V_35 , V_106 , V_21 ) ) {
V_106 = F_7 ( V_106 ) ;
F_114 ( V_106 , V_21 ) ;
}
}
V_103 -> V_77 = V_106 ? ( V_7 * ) F_7 ( V_106 ) - V_103 -> V_5 : 0 ;
F_115 ( L_6 , V_103 -> V_77 ) ;
F_116 ( V_35 , V_103 ) ;
}
static void F_117 ( struct V_34 * V_35 , struct V_97 * V_98 ,
unsigned V_76 , unsigned V_107 , bool V_104 )
{
V_7 V_108 ;
bool V_105 = ! V_35 -> V_109 ;
struct V_88 * V_103 = ( void * ) F_118 ( V_110 | V_20 ,
V_107 ) ;
if ( ! V_103 ) {
F_119 ( & V_35 -> V_13 -> V_111 ) ;
V_103 = V_35 -> V_13 -> V_112 ;
V_107 = F_120 ( F_121 ( V_35 -> V_13 ) ) ;
}
V_108 = F_122 () ;
F_113 ( V_35 , V_103 , V_98 , V_104 , V_105 ) ;
V_35 -> V_83 = V_76 ;
if ( ! V_104 && ! V_76 && V_35 -> V_109 )
F_123 ( V_35 , V_103 ) ;
if ( ! V_76 && V_107 == V_35 -> V_113 ) {
V_103 -> V_90 = F_91 ( V_35 -> V_13 ) ;
V_103 -> V_89 = V_35 -> V_81 [ 0 ] . V_64 -> V_89 ;
V_103 -> V_91 = V_35 -> V_81 [ 0 ] . V_64 -> V_91 ;
F_124 ( V_103 , V_35 -> V_81 [ 0 ] . V_64 ) ;
if ( V_35 -> V_13 -> V_112 == V_35 -> V_81 [ 0 ] . V_64 )
V_35 -> V_13 -> V_112 = V_103 ;
} else {
V_35 -> V_81 [ V_76 ] . V_64 -> V_77 = V_103 -> V_77 ;
memcpy ( V_35 -> V_81 [ V_76 ] . V_64 -> V_76 , V_103 -> V_76 ,
( void * ) V_78 ( V_103 ) - ( void * ) V_103 -> V_76 ) ;
}
if ( V_103 == V_35 -> V_13 -> V_112 )
F_31 ( & V_35 -> V_13 -> V_111 ) ;
else
F_125 ( ( unsigned long ) V_103 , V_107 ) ;
if ( V_35 -> V_109 )
F_81 ( V_35 ) ;
if ( ! V_76 ) {
F_126 ( & V_35 -> V_13 -> V_114 ) ;
F_127 ( & V_35 -> V_13 -> V_115 , V_108 ) ;
F_128 ( & V_35 -> V_13 -> V_114 ) ;
}
}
void F_129 ( struct V_34 * V_35 , unsigned V_76 )
{
T_1 V_14 = 0 , V_107 = V_35 -> V_113 , V_77 = 0 ;
struct V_97 V_98 ;
F_101 ( V_35 , & V_98 , NULL , & V_35 -> V_81 [ V_76 ] ) ;
F_35 ( V_35 -> V_81 [ V_35 -> V_83 ] . V_64 == F_89 ( V_35 ) &&
( V_35 -> V_81 [ V_35 -> V_83 ] . V_57 || V_35 -> V_83 ) ) ;
if ( V_35 -> V_109 )
V_14 = F_130 ( V_35 ) ;
if ( V_76 ) {
unsigned V_24 ;
for ( V_24 = V_76 ; V_24 <= V_35 -> V_83 ; V_24 ++ )
V_77 += V_35 -> V_81 [ V_24 ] . V_64 -> V_77 ;
V_107 = F_4 ( F_131 ( V_35 -> V_81 -> V_64 ,
V_77 ) ) / V_116 ;
if ( V_107 )
V_107 = F_120 ( V_107 ) ;
}
F_117 ( V_35 , & V_98 , V_76 , V_107 , false ) ;
F_132 ( V_35 -> V_109 && F_130 ( V_35 ) != V_14 ) ;
}
void F_133 ( struct V_34 * V_35 , struct V_97 * V_98 )
{
F_35 ( ! V_35 -> V_109 ) ;
F_117 ( V_35 , V_98 , 0 , V_35 -> V_113 , true ) ;
}
void F_134 ( struct V_34 * V_35 , struct V_34 * V_16 )
{
V_7 V_108 = F_122 () ;
struct V_97 V_98 ;
F_110 ( V_35 , & V_98 , NULL ) ;
F_113 ( V_35 , V_16 -> V_81 -> V_64 , & V_98 , false , true ) ;
F_126 ( & V_35 -> V_13 -> V_114 ) ;
F_127 ( & V_35 -> V_13 -> V_115 , V_108 ) ;
F_128 ( & V_35 -> V_13 -> V_114 ) ;
F_40 ( & V_16 -> V_117 , & V_35 -> V_117 ) ;
V_16 -> V_81 -> V_57 = 0 ;
}
void F_135 ( struct V_34 * V_35 )
{
if ( V_35 -> V_83 ) {
unsigned V_24 , V_56 , V_77 = 0 , V_118 ;
for ( V_24 = 0 ; V_24 <= V_35 -> V_83 ; V_24 ++ )
V_77 += V_35 -> V_81 [ V_24 ] . V_64 -> V_77 ;
V_118 = V_77 ;
for ( V_56 = 0 ; V_56 < V_35 -> V_83 ; V_56 ++ ) {
if ( V_77 * 2 < V_118 ||
V_77 < 1000 ) {
F_129 ( V_35 , V_56 ) ;
return;
}
V_77 -= V_35 -> V_81 [ V_56 ] . V_64 -> V_77 ;
}
if ( V_35 -> V_83 >= ( V_82 - 1 ) - V_35 -> V_23 ) {
F_136 ( V_35 ) ;
return;
}
}
F_81 ( V_35 ) ;
}
static int F_137 ( struct V_34 * V_35 , struct V_119 * V_120 ,
struct V_121 * V_122 )
{
struct V_9 * V_21 ;
unsigned V_24 ;
V_122 -> V_123 ++ ;
for ( V_24 = 0 ; V_24 <= V_35 -> V_83 ; V_24 ++ ) {
struct V_60 * V_61 = & V_35 -> V_81 [ V_24 ] ;
T_1 V_124 = V_61 -> V_64 -> V_77 * sizeof( V_7 ) ;
T_1 V_56 ;
if ( F_86 ( V_35 , V_61 ) ) {
V_122 -> V_125 ++ ;
V_122 -> V_126 += V_124 ;
V_122 -> V_127 += V_61 -> V_57 - 1 ;
for ( V_56 = 1 ; V_56 < V_61 -> V_57 ; V_56 ++ )
if ( V_61 -> V_66 [ V_56 ] . V_74 == 127 )
V_122 -> V_128 ++ ;
} else {
V_122 -> V_129 ++ ;
V_122 -> V_130 += V_124 ;
}
}
if ( V_35 -> V_23 ) {
struct V_97 V_98 ;
F_138 (b, k, &iter, bch_ptr_bad) {
int V_100 = V_34 ( V_121 , V_21 , V_35 , V_120 , V_122 ) ;
if ( V_100 )
return V_100 ;
}
}
return 0 ;
}
int F_139 ( struct V_12 * V_13 , char * V_131 )
{
struct V_119 V_120 ;
struct V_121 V_61 ;
int V_100 ;
F_140 ( & V_120 ) ;
memset ( & V_61 , 0 , sizeof( struct V_121 ) ) ;
V_100 = F_141 ( V_121 , V_13 , & V_120 , & V_61 ) ;
if ( V_100 )
return V_100 ;
return snprintf ( V_131 , V_116 ,
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ,
V_61 . V_123 ,
V_61 . V_125 , V_61 . V_129 ,
V_61 . V_126 , V_61 . V_130 ,
V_61 . V_127 , V_61 . V_128 ) ;
}
