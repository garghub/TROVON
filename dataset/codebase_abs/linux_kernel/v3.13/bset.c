int F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
T_1 V_6 = F_2 ( V_2 ) ;
T_1 V_7 = V_6 + 2 + V_3 ;
T_2 * V_8 = V_2 -> V_9 == V_2 -> V_10 ? NULL : V_2 -> V_9 ;
T_2 * V_11 ;
if ( V_7 * sizeof( T_2 ) > F_3 ( V_5 ) - sizeof( struct V_12 ) )
return - V_13 ;
V_7 = F_4 ( V_7 ) ;
if ( V_7 <= V_14 ||
F_4 ( V_6 ) == V_7 )
return 0 ;
V_11 = F_5 ( V_8 , sizeof( T_2 ) * V_7 , V_15 ) ;
if ( ! V_11 )
return - V_13 ;
if ( ! V_8 )
memcpy ( V_11 , V_2 -> V_10 , sizeof( T_2 ) * V_6 ) ;
V_2 -> V_9 = V_11 ;
V_2 -> V_16 = V_11 + V_6 ;
return 0 ;
}
struct V_17 * F_6 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 == V_2 -> V_20 )
return NULL ;
while ( F_7 ( V_18 ) != V_2 -> V_20 )
V_18 = F_7 ( V_18 ) ;
return V_2 -> V_20 = V_18 ;
}
void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_16 -= F_9 ( V_2 -> V_19 ) ;
memmove ( V_2 -> V_19 ,
F_7 ( V_2 -> V_19 ) ,
F_10 ( V_2 ) ) ;
}
static bool F_11 ( struct V_4 * V_5 , const struct V_17 * V_18 )
{
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < F_12 ( V_18 ) ; V_21 ++ )
if ( F_13 ( V_5 , V_18 , V_21 ) ) {
struct V_22 * V_23 = F_14 ( V_5 , V_18 , V_21 ) ;
T_1 V_24 = F_15 ( V_5 , V_18 , V_21 ) ;
T_1 V_25 = F_16 ( V_5 , F_17 ( V_18 , V_21 ) ) ;
if ( F_18 ( V_18 ) + V_25 > V_5 -> V_26 . V_27 ||
V_24 < V_23 -> V_26 . V_28 ||
V_24 >= V_23 -> V_26 . V_29 )
return true ;
}
return false ;
}
bool F_19 ( struct V_4 * V_5 , const struct V_17 * V_18 )
{
char V_30 [ 80 ] ;
if ( ! F_12 ( V_18 ) || ! F_18 ( V_18 ) || F_20 ( V_18 ) )
goto V_31;
if ( F_11 ( V_5 , V_18 ) )
goto V_31;
return false ;
V_31:
F_21 ( V_30 , sizeof( V_30 ) , V_18 ) ;
F_22 ( V_5 , L_1 , V_30 , F_23 ( V_5 , V_18 ) ) ;
return true ;
}
bool F_24 ( struct V_4 * V_5 , const struct V_17 * V_18 )
{
char V_30 [ 80 ] ;
if ( ! F_18 ( V_18 ) )
return true ;
if ( F_18 ( V_18 ) > F_25 ( V_18 ) )
goto V_31;
if ( F_11 ( V_5 , V_18 ) )
goto V_31;
return false ;
V_31:
F_21 ( V_30 , sizeof( V_30 ) , V_18 ) ;
F_22 ( V_5 , L_2 , V_30 , F_23 ( V_5 , V_18 ) ) ;
return true ;
}
static bool F_26 ( struct V_32 * V_33 , const struct V_17 * V_18 ,
unsigned V_34 )
{
struct V_24 * V_35 = F_27 ( V_33 -> V_5 , V_18 , V_34 ) ;
char V_30 [ 80 ] ;
if ( F_28 ( & V_33 -> V_5 -> V_36 ) ) {
if ( V_33 -> V_37 ) {
if ( F_20 ( V_18 ) ||
V_35 -> V_38 != V_39 ||
( V_33 -> V_5 -> V_40 &&
F_29 ( V_35 ) != V_41 ) )
goto V_42;
} else {
if ( V_35 -> V_38 == V_39 )
goto V_42;
if ( F_20 ( V_18 ) &&
V_33 -> V_5 -> V_40 &&
F_29 ( V_35 ) != V_43 )
goto V_42;
}
F_30 ( & V_33 -> V_5 -> V_36 ) ;
}
return false ;
V_42:
F_30 ( & V_33 -> V_5 -> V_36 ) ;
F_21 ( V_30 , sizeof( V_30 ) , V_18 ) ;
F_31 ( V_33 ,
L_3 ,
V_30 , F_15 ( V_33 -> V_5 , V_18 , V_34 ) , F_32 ( & V_35 -> V_44 ) ,
V_35 -> V_38 , V_35 -> V_45 , V_35 -> V_46 , F_29 ( V_35 ) , V_35 -> V_47 ) ;
return true ;
}
bool F_33 ( struct V_32 * V_33 , const struct V_17 * V_18 )
{
struct V_24 * V_35 ;
unsigned V_21 , V_48 ;
if ( ! F_34 ( V_18 , & V_49 ) ||
! F_12 ( V_18 ) ||
F_35 ( V_33 , V_18 ) )
return true ;
for ( V_21 = 0 ; V_21 < F_12 ( V_18 ) ; V_21 ++ ) {
if ( ! F_13 ( V_33 -> V_5 , V_18 , V_21 ) )
return true ;
V_35 = F_27 ( V_33 -> V_5 , V_18 , V_21 ) ;
V_48 = F_36 ( V_33 -> V_5 , V_18 , V_21 ) ;
F_37 ( V_48 > 96 , V_33 ,
L_4 ,
V_48 , V_33 -> V_5 -> V_50 ) ;
F_37 ( V_48 && F_20 ( V_18 ) && F_18 ( V_18 ) ,
V_33 , L_5 ) ;
if ( V_48 )
return true ;
if ( F_38 ( V_33 -> V_5 ) &&
F_26 ( V_33 , V_18 , V_21 ) )
return true ;
}
return false ;
}
void F_39 ( struct V_17 * V_51 , const struct V_17 * V_52 ,
unsigned V_21 )
{
F_40 ( V_21 > F_12 ( V_52 ) ) ;
memcpy ( V_51 , V_52 , 2 * sizeof( T_2 ) ) ;
V_51 -> V_34 [ 0 ] = V_52 -> V_34 [ V_21 ] ;
F_41 ( V_51 , 1 ) ;
F_42 ( V_51 , 0 ) ;
}
bool F_43 ( const struct V_17 * V_53 , struct V_17 * V_18 )
{
unsigned V_21 , V_54 = 0 ;
if ( F_34 ( V_53 , & F_44 ( V_18 ) ) <= 0 )
return false ;
if ( F_34 ( V_53 , V_18 ) < 0 )
V_54 = F_25 ( V_18 ) - F_25 ( V_53 ) ;
else
F_45 ( V_18 , V_53 ) ;
for ( V_21 = 0 ; V_21 < F_12 ( V_18 ) ; V_21 ++ )
F_46 ( V_18 , V_21 , F_17 ( V_18 , V_21 ) + F_18 ( V_18 ) - V_54 ) ;
F_40 ( V_54 > F_18 ( V_18 ) ) ;
F_47 ( V_18 , V_54 ) ;
return true ;
}
bool F_48 ( const struct V_17 * V_53 , struct V_17 * V_18 )
{
unsigned V_54 = 0 ;
if ( F_34 ( V_53 , V_18 ) >= 0 )
return false ;
F_40 ( F_49 ( V_53 ) != F_49 ( V_18 ) ) ;
if ( F_34 ( V_53 , & F_44 ( V_18 ) ) > 0 )
V_54 = F_25 ( V_53 ) - F_50 ( V_18 ) ;
F_45 ( V_18 , V_53 ) ;
F_40 ( V_54 > F_18 ( V_18 ) ) ;
F_47 ( V_18 , V_54 ) ;
return true ;
}
static T_2 F_51 ( struct V_17 * V_2 , struct V_17 * V_25 )
{
return ( V_2 -> V_34 [ F_12 ( V_2 ) ] + V_25 -> V_34 [ F_12 ( V_25 ) ] ) &
~ ( ( T_2 ) 1 << 63 ) ;
}
bool F_52 ( struct V_32 * V_33 , struct V_17 * V_2 , struct V_17 * V_25 )
{
unsigned V_21 ;
if ( F_53 ( V_33 -> V_5 ) )
return false ;
if ( F_12 ( V_2 ) != F_12 ( V_25 ) ||
F_20 ( V_2 ) != F_20 ( V_25 ) ||
F_34 ( V_2 , & F_44 ( V_25 ) ) )
return false ;
for ( V_21 = 0 ; V_21 < F_12 ( V_2 ) ; V_21 ++ )
if ( V_2 -> V_34 [ V_21 ] + F_54 ( 0 , F_18 ( V_2 ) , 0 ) != V_25 -> V_34 [ V_21 ] ||
F_15 ( V_33 -> V_5 , V_2 , V_21 ) != F_15 ( V_33 -> V_5 , V_25 , V_21 ) )
return false ;
if ( F_18 ( V_2 ) + F_18 ( V_25 ) > V_55 ) {
F_55 ( V_2 , F_25 ( V_2 ) + V_55 - F_18 ( V_2 ) ) ;
F_47 ( V_2 , V_55 ) ;
F_56 ( V_2 , V_25 ) ;
return false ;
}
if ( F_57 ( V_2 ) ) {
if ( F_57 ( V_25 ) )
V_2 -> V_34 [ F_12 ( V_2 ) ] = F_51 ( V_2 , V_25 ) ;
else
F_42 ( V_2 , 0 ) ;
}
F_55 ( V_2 , F_25 ( V_2 ) + F_18 ( V_25 ) ) ;
F_47 ( V_2 , F_18 ( V_2 ) + F_18 ( V_25 ) ) ;
return true ;
}
static unsigned F_58 ( unsigned V_56 , unsigned V_57 )
{
if ( V_56 * 2 + 1 < V_57 ) {
V_56 = V_56 * 2 + 1 ;
while ( V_56 * 2 < V_57 )
V_56 *= 2 ;
} else
V_56 >>= F_59 ( V_56 ) + 1 ;
return V_56 ;
}
static unsigned F_60 ( unsigned V_56 , unsigned V_57 )
{
if ( V_56 * 2 < V_57 ) {
V_56 = V_56 * 2 ;
while ( V_56 * 2 + 1 < V_57 )
V_56 = V_56 * 2 + 1 ;
} else
V_56 >>= F_61 ( V_56 ) ;
return V_56 ;
}
static unsigned F_62 ( unsigned V_56 , unsigned V_57 , unsigned V_58 )
{
unsigned V_33 = F_63 ( V_56 ) ;
unsigned V_59 = F_63 ( V_57 - 1 ) - V_33 ;
V_56 ^= 1U << ( V_33 - 1 ) ;
V_56 <<= 1 ;
V_56 |= 1 ;
V_56 <<= V_59 ;
if ( V_56 > V_58 )
V_56 -= ( V_56 - V_58 ) >> 1 ;
return V_56 ;
}
static unsigned F_64 ( unsigned V_56 , struct V_60 * V_61 )
{
return F_62 ( V_56 , V_61 -> V_57 , V_61 -> V_58 ) ;
}
static unsigned F_65 ( unsigned V_56 , unsigned V_57 , unsigned V_58 )
{
unsigned V_59 ;
if ( V_56 > V_58 )
V_56 += V_56 - V_58 ;
V_59 = F_61 ( V_56 ) ;
V_56 >>= V_59 ;
V_56 |= F_4 ( V_57 ) >> V_59 ;
return V_56 ;
}
static unsigned F_66 ( unsigned V_56 , struct V_60 * V_61 )
{
return F_65 ( V_56 , V_61 -> V_57 , V_61 -> V_58 ) ;
}
static struct V_17 * F_67 ( struct V_60 * V_61 , unsigned V_62 ,
unsigned V_63 )
{
return ( ( void * ) V_61 -> V_64 ) + V_62 * V_65 + V_63 * 8 ;
}
static unsigned F_68 ( struct V_60 * V_61 , struct V_17 * V_18 )
{
return ( ( void * ) V_18 - ( void * ) V_61 -> V_64 ) / V_65 ;
}
static unsigned F_69 ( struct V_17 * V_18 )
{
return ( ( T_1 ) V_18 & ( V_65 - 1 ) ) / sizeof( T_2 ) ;
}
static struct V_17 * F_70 ( struct V_60 * V_61 , unsigned V_56 )
{
return F_67 ( V_61 , F_64 ( V_56 , V_61 ) , V_61 -> V_66 [ V_56 ] . V_67 ) ;
}
static struct V_17 * F_71 ( struct V_60 * V_61 , unsigned V_56 )
{
return ( void * ) ( ( ( T_2 * ) F_70 ( V_61 , V_56 ) ) - V_61 -> V_68 [ V_56 ] ) ;
}
static struct V_17 * F_72 ( struct V_60 * V_61 , unsigned V_62 )
{
return F_67 ( V_61 , V_62 , V_61 -> V_68 [ V_62 ] ) ;
}
static inline T_2 F_73 ( T_2 V_69 , T_2 V_70 , T_3 V_59 )
{
V_70 >>= V_59 ;
V_70 |= ( V_69 << 1 ) << ( 63U - V_59 ) ;
return V_70 ;
}
static inline unsigned F_74 ( const struct V_17 * V_18 ,
struct V_71 * V_72 )
{
const T_2 * V_73 = & V_18 -> V_70 - ( V_72 -> V_74 >> 6 ) ;
return F_73 ( V_73 [ - 1 ] , V_73 [ 0 ] , V_72 -> V_74 & 63 ) & V_75 ;
}
static void F_75 ( struct V_60 * V_61 , unsigned V_56 )
{
struct V_71 * V_72 = & V_61 -> V_66 [ V_56 ] ;
struct V_17 * V_67 = F_70 ( V_61 , V_56 ) ;
struct V_17 * V_73 = F_71 ( V_61 , V_56 ) ;
struct V_17 * V_2 = F_76 ( V_56 )
? V_61 -> V_64 -> V_76
: F_71 ( V_61 , V_56 >> F_61 ( V_56 ) ) ;
struct V_17 * V_25 = F_76 ( V_56 + 1 )
? F_77 ( V_61 -> V_64 , V_61 -> V_64 -> V_19 - F_9 ( & V_61 -> V_77 ) )
: F_70 ( V_61 , V_56 >> ( F_59 ( V_56 ) + 1 ) ) ;
F_40 ( V_67 < V_2 || V_67 > V_25 ) ;
F_40 ( F_7 ( V_73 ) != V_67 ) ;
if ( F_49 ( V_2 ) != F_49 ( V_25 ) )
V_72 -> V_74 = F_78 ( F_49 ( V_25 ) ^ F_49 ( V_2 ) ) + 64 ;
else
V_72 -> V_74 = F_78 ( V_25 -> V_70 ^ V_2 -> V_70 ) ;
V_72 -> V_74 = F_79 ( int , V_72 -> V_74 - V_78 , 0 ) ;
if ( F_74 ( V_67 , V_72 ) != F_74 ( V_73 , V_72 ) )
V_72 -> V_79 = F_74 ( V_67 , V_72 ) - 1 ;
else
V_72 -> V_74 = 127 ;
}
static void F_80 ( struct V_32 * V_33 , struct V_60 * V_61 )
{
if ( V_61 != V_33 -> V_80 ) {
unsigned V_56 = F_81 ( V_61 [ - 1 ] . V_57 ,
64 / sizeof( struct V_71 ) ) ;
V_61 -> V_66 = V_61 [ - 1 ] . V_66 + V_56 ;
V_61 -> V_68 = V_61 [ - 1 ] . V_68 + V_56 ;
}
while ( V_61 < V_33 -> V_80 + V_81 )
V_61 ++ -> V_57 = 0 ;
}
static void F_82 ( struct V_32 * V_33 )
{
struct V_60 * V_61 = V_33 -> V_80 + V_33 -> V_82 ;
F_80 ( V_33 , V_61 ) ;
if ( V_61 -> V_66 != V_33 -> V_80 -> V_66 + F_83 ( V_33 ) ) {
V_61 -> V_68 [ 0 ] = F_69 ( V_61 -> V_64 -> V_76 ) ;
V_61 -> V_57 = 1 ;
}
}
static void F_84 ( struct V_32 * V_33 )
{
struct V_60 * V_61 = V_33 -> V_80 + V_33 -> V_82 ;
struct V_17 * V_18 = V_61 -> V_64 -> V_76 ;
unsigned V_56 , V_62 = 1 ;
F_80 ( V_33 , V_61 ) ;
V_61 -> V_57 = F_85 ( unsigned ,
F_68 ( V_61 , V_77 ( V_61 -> V_64 ) ) ,
V_33 -> V_80 -> V_66 + F_83 ( V_33 ) - V_61 -> V_66 ) ;
if ( V_61 -> V_57 < 2 ) {
V_61 -> V_57 = 0 ;
return;
}
V_61 -> V_58 = ( V_61 -> V_57 - F_86 ( V_61 -> V_57 - 1 ) ) << 1 ;
for ( V_56 = F_58 ( 0 , V_61 -> V_57 ) ;
V_56 ;
V_56 = F_58 ( V_56 , V_61 -> V_57 ) ) {
while ( F_68 ( V_61 , V_18 ) != V_62 )
V_18 = F_7 ( V_18 ) ;
V_61 -> V_68 [ V_56 ] = F_9 ( V_18 ) ;
V_18 = F_7 ( V_18 ) ;
V_62 ++ ;
V_61 -> V_66 [ V_56 ] . V_67 = F_69 ( V_18 ) ;
}
while ( F_7 ( V_18 ) != V_77 ( V_61 -> V_64 ) )
V_18 = F_7 ( V_18 ) ;
V_61 -> V_77 = * V_18 ;
for ( V_56 = F_58 ( 0 , V_61 -> V_57 ) ;
V_56 ;
V_56 = F_58 ( V_56 , V_61 -> V_57 ) )
F_75 ( V_61 , V_56 ) ;
}
void F_87 ( struct V_32 * V_33 , struct V_17 * V_18 )
{
struct V_60 * V_61 ;
unsigned V_83 , V_56 = 1 ;
for ( V_61 = V_33 -> V_80 ; V_61 <= & V_33 -> V_80 [ V_33 -> V_82 ] ; V_61 ++ )
if ( V_18 < V_77 ( V_61 -> V_64 ) )
goto V_84;
F_88 () ;
V_84:
if ( ! V_61 -> V_57 || ! F_89 ( V_33 , V_61 ) )
return;
V_83 = F_68 ( V_61 , V_18 ) ;
if ( V_18 == V_61 -> V_64 -> V_76 )
goto V_85;
if ( F_7 ( V_18 ) == V_77 ( V_61 -> V_64 ) ) {
V_61 -> V_77 = * V_18 ;
goto V_86;
}
V_56 = F_66 ( V_83 , V_61 ) ;
if ( V_56 &&
V_56 < V_61 -> V_57 &&
V_18 == F_70 ( V_61 , V_56 ) )
V_85: do {
F_75 ( V_61 , V_56 ) ;
V_56 = V_56 * 2 ;
} while ( V_56 < V_61 -> V_57 );
V_56 = F_66 ( V_83 + 1 , V_61 ) ;
if ( V_56 &&
V_56 < V_61 -> V_57 &&
V_18 == F_71 ( V_61 , V_56 ) )
V_86: do {
F_75 ( V_61 , V_56 ) ;
V_56 = V_56 * 2 + 1 ;
} while ( V_56 < V_61 -> V_57 );
}
void F_90 ( struct V_32 * V_33 , struct V_17 * V_18 )
{
struct V_60 * V_61 = & V_33 -> V_80 [ V_33 -> V_82 ] ;
unsigned V_59 = F_9 ( V_18 ) ;
unsigned V_56 = F_68 ( V_61 , V_18 ) ;
if ( ! V_61 -> V_57 )
return;
if ( V_56 < V_61 -> V_57 &&
F_72 ( V_61 , V_56 ) <= V_18 )
V_56 ++ ;
for (; V_56 < V_61 -> V_57 ; V_56 ++ ) {
V_61 -> V_68 [ V_56 ] += V_59 ;
if ( V_61 -> V_68 [ V_56 ] > 7 ) {
V_18 = F_72 ( V_61 , V_56 - 1 ) ;
while ( V_18 < F_67 ( V_61 , V_56 , 0 ) )
V_18 = F_7 ( V_18 ) ;
V_61 -> V_68 [ V_56 ] = F_69 ( V_18 ) ;
}
}
if ( V_61 -> V_57 == V_33 -> V_80 -> V_66 + F_83 ( V_33 ) - V_61 -> V_66 )
return;
for ( V_18 = F_72 ( V_61 , V_61 -> V_57 - 1 ) ;
V_18 != V_77 ( V_61 -> V_64 ) ;
V_18 = F_7 ( V_18 ) )
if ( V_61 -> V_57 == F_68 ( V_61 , V_18 ) ) {
V_61 -> V_68 [ V_61 -> V_57 ] = F_69 ( V_18 ) ;
V_61 -> V_57 ++ ;
}
}
void F_91 ( struct V_32 * V_33 )
{
struct V_87 * V_21 = F_92 ( V_33 ) ;
if ( V_21 != V_33 -> V_80 [ 0 ] . V_64 ) {
V_33 -> V_80 [ ++ V_33 -> V_82 ] . V_64 = V_21 ;
V_21 -> V_88 = V_33 -> V_80 [ 0 ] . V_64 -> V_88 ;
} else
F_93 ( & V_21 -> V_88 , sizeof( T_2 ) ) ;
V_21 -> V_89 = F_94 ( & V_33 -> V_5 -> V_26 ) ;
V_21 -> V_90 = 0 ;
V_21 -> V_19 = 0 ;
F_82 ( V_33 ) ;
}
static struct V_91 F_95 ( struct V_32 * V_33 ,
struct V_60 * V_61 ,
const struct V_17 * V_92 )
{
unsigned V_93 = 0 , V_94 = V_61 -> V_57 ;
F_40 ( ! V_33 -> V_82 &&
V_61 -> V_57 < F_68 ( V_61 , V_77 ( V_61 -> V_64 ) ) ) ;
while ( V_93 + 1 != V_94 ) {
unsigned V_67 = ( V_93 + V_94 ) >> 1 ;
if ( F_34 ( F_72 ( V_61 , V_67 ) , V_92 ) > 0 )
V_94 = V_67 ;
else
V_93 = V_67 ;
}
return (struct V_91 ) {
F_72 ( V_61 , V_93 ) ,
V_94 < V_61 -> V_57 ? F_72 ( V_61 , V_94 ) : V_77 (t->data)
} ;
}
static struct V_91 F_96 ( struct V_32 * V_33 ,
struct V_60 * V_61 ,
const struct V_17 * V_92 )
{
struct V_17 * V_2 , * V_25 ;
struct V_71 * V_72 ;
unsigned V_83 , V_56 , V_95 = 1 ;
do {
unsigned V_73 = V_95 << 4 ;
V_73 &= ( ( int ) ( V_73 - V_61 -> V_57 ) ) >> 31 ;
F_97 ( & V_61 -> V_66 [ V_73 ] ) ;
V_56 = V_95 ;
V_72 = & V_61 -> V_66 [ V_56 ] ;
if ( F_98 ( V_72 -> V_74 != 127 ) )
V_95 = V_56 * 2 + ( ( ( unsigned )
( V_72 -> V_79 -
F_74 ( V_92 , V_72 ) ) ) >> 31 ) ;
else
V_95 = ( F_34 ( F_70 ( V_61 , V_56 ) , V_92 ) > 0 )
? V_56 * 2
: V_56 * 2 + 1 ;
} while ( V_95 < V_61 -> V_57 );
V_83 = F_64 ( V_56 , V_61 ) ;
if ( V_95 & 1 ) {
V_2 = F_67 ( V_61 , V_83 , V_72 -> V_67 ) ;
if ( ++ V_83 != V_61 -> V_57 ) {
V_72 = & V_61 -> V_66 [ F_58 ( V_56 , V_61 -> V_57 ) ] ;
V_25 = F_67 ( V_61 , V_83 , V_72 -> V_67 ) ;
} else
V_25 = V_77 ( V_61 -> V_64 ) ;
} else {
V_25 = F_67 ( V_61 , V_83 , V_72 -> V_67 ) ;
if ( -- V_83 ) {
V_72 = & V_61 -> V_66 [ F_60 ( V_56 , V_61 -> V_57 ) ] ;
V_2 = F_67 ( V_61 , V_83 , V_72 -> V_67 ) ;
} else
V_2 = V_61 -> V_64 -> V_76 ;
}
return (struct V_91 ) { V_2 , V_25 } ;
}
struct V_17 * F_99 ( struct V_32 * V_33 , struct V_60 * V_61 ,
const struct V_17 * V_92 )
{
struct V_91 V_21 ;
if ( F_100 ( ! V_61 -> V_57 ) ) {
V_21 . V_2 = V_61 -> V_64 -> V_76 ;
V_21 . V_25 = V_77 ( V_61 -> V_64 ) ;
} else if ( F_89 ( V_33 , V_61 ) ) {
if ( F_100 ( F_34 ( V_92 , & V_61 -> V_77 ) >= 0 ) )
return V_77 ( V_61 -> V_64 ) ;
if ( F_100 ( F_34 ( V_92 , V_61 -> V_64 -> V_76 ) < 0 ) )
return V_61 -> V_64 -> V_76 ;
V_21 = F_96 ( V_33 , V_61 , V_92 ) ;
} else
V_21 = F_95 ( V_33 , V_61 , V_92 ) ;
if ( F_38 ( V_33 -> V_5 ) ) {
F_40 ( F_89 ( V_33 , V_61 ) &&
V_21 . V_2 != V_61 -> V_64 -> V_76 &&
F_34 ( F_71 ( V_61 ,
F_66 ( F_68 ( V_61 , V_21 . V_2 ) , V_61 ) ) ,
V_92 ) > 0 ) ;
F_40 ( V_21 . V_25 != V_77 ( V_61 -> V_64 ) &&
F_34 ( V_21 . V_25 , V_92 ) <= 0 ) ;
}
while ( F_98 ( V_21 . V_2 != V_21 . V_25 ) &&
F_34 ( V_21 . V_2 , V_92 ) <= 0 )
V_21 . V_2 = F_7 ( V_21 . V_2 ) ;
return V_21 . V_2 ;
}
static inline bool F_101 ( struct V_96 V_2 ,
struct V_96 V_25 )
{
T_4 V_5 = F_34 ( & F_44 ( V_2 . V_18 ) , & F_44 ( V_25 . V_18 ) ) ;
return V_5 ? V_5 > 0 : V_2 . V_18 < V_25 . V_18 ;
}
static inline bool F_102 ( struct V_97 * V_98 )
{
return ! V_98 -> V_99 ;
}
void F_103 ( struct V_97 * V_98 , struct V_17 * V_18 ,
struct V_17 * V_77 )
{
if ( V_18 != V_77 )
F_40 (!heap_add(iter,
((struct btree_iter_set) { k, end }),
btree_iter_cmp)) ;
}
struct V_17 * F_104 ( struct V_32 * V_33 , struct V_97 * V_98 ,
struct V_17 * V_92 , struct V_60 * V_76 )
{
struct V_17 * V_100 = NULL ;
V_98 -> V_57 = F_105 ( V_98 -> V_64 ) ;
V_98 -> V_99 = 0 ;
#ifdef F_106
V_98 -> V_33 = V_33 ;
#endif
for (; V_76 <= & V_33 -> V_80 [ V_33 -> V_82 ] ; V_76 ++ ) {
V_100 = F_107 ( V_33 , V_76 , V_92 ) ;
F_103 ( V_98 , V_100 , V_77 ( V_76 -> V_64 ) ) ;
}
return V_100 ;
}
struct V_17 * F_108 ( struct V_97 * V_98 )
{
struct V_96 V_101 ;
struct V_17 * V_100 = NULL ;
if ( ! F_102 ( V_98 ) ) {
F_109 ( V_98 ) ;
V_100 = V_98 -> V_64 -> V_18 ;
V_98 -> V_64 -> V_18 = F_7 ( V_98 -> V_64 -> V_18 ) ;
if ( V_98 -> V_64 -> V_18 > V_98 -> V_64 -> V_77 ) {
F_110 ( 1 , L_6 ) ;
V_98 -> V_64 -> V_18 = V_98 -> V_64 -> V_77 ;
}
if ( V_98 -> V_64 -> V_18 == V_98 -> V_64 -> V_77 )
F_111 ( V_98 , V_101 , F_101 ) ;
else
F_112 ( V_98 , 0 , F_101 ) ;
}
return V_100 ;
}
struct V_17 * F_113 ( struct V_97 * V_98 ,
struct V_32 * V_33 , T_5 V_102 )
{
struct V_17 * V_100 ;
do {
V_100 = F_108 ( V_98 ) ;
} while ( V_100 && V_102 ( V_33 , V_100 ) );
return V_100 ;
}
static void F_114 ( struct V_97 * V_98 ,
struct V_96 * V_21 )
{
V_21 -> V_18 = F_7 ( V_21 -> V_18 ) ;
if ( V_21 -> V_18 == V_21 -> V_77 )
* V_21 = V_98 -> V_64 [ -- V_98 -> V_99 ] ;
}
static void F_115 ( struct V_97 * V_98 )
{
while ( V_98 -> V_99 > 1 ) {
struct V_96 * V_20 = V_98 -> V_64 , * V_21 = V_20 + 1 ;
if ( V_98 -> V_99 > 2 &&
F_101 ( V_21 [ 0 ] , V_21 [ 1 ] ) )
V_21 ++ ;
if ( F_34 ( V_20 -> V_18 , & F_44 ( V_21 -> V_18 ) ) <= 0 )
break;
if ( ! F_18 ( V_21 -> V_18 ) ) {
F_114 ( V_98 , V_21 ) ;
F_112 ( V_98 , V_21 - V_20 , F_101 ) ;
continue;
}
if ( V_20 -> V_18 > V_21 -> V_18 ) {
if ( F_34 ( V_20 -> V_18 , V_21 -> V_18 ) >= 0 )
F_114 ( V_98 , V_21 ) ;
else
F_56 ( V_20 -> V_18 , V_21 -> V_18 ) ;
F_112 ( V_98 , V_21 - V_20 , F_101 ) ;
} else {
F_40 ( ! F_34 ( & F_44 ( V_20 -> V_18 ) , & F_44 ( V_21 -> V_18 ) ) ) ;
F_116 ( & F_44 ( V_21 -> V_18 ) , V_20 -> V_18 ) ;
}
}
}
static void F_117 ( struct V_32 * V_33 , struct V_87 * V_103 ,
struct V_97 * V_98 ,
bool V_104 , bool V_105 )
{
struct V_17 * V_18 , * V_106 = NULL ;
bool (* V_31)( struct V_32 * , const struct V_17 * ) = V_105
? F_33
: F_35 ;
while ( ! F_102 ( V_98 ) ) {
if ( V_104 && ! V_33 -> V_37 )
F_115 ( V_98 ) ;
V_18 = F_108 ( V_98 ) ;
if ( V_31 ( V_33 , V_18 ) )
continue;
if ( ! V_106 ) {
V_106 = V_103 -> V_76 ;
F_118 ( V_106 , V_18 ) ;
} else if ( V_33 -> V_37 ||
! F_52 ( V_33 , V_106 , V_18 ) ) {
V_106 = F_7 ( V_106 ) ;
F_118 ( V_106 , V_18 ) ;
}
}
V_103 -> V_19 = V_106 ? ( T_2 * ) F_7 ( V_106 ) - V_103 -> V_107 : 0 ;
F_119 ( L_7 , V_103 -> V_19 ) ;
}
static void F_120 ( struct V_32 * V_33 , struct V_97 * V_98 ,
unsigned V_76 , unsigned V_108 , bool V_104 )
{
T_2 V_109 ;
bool V_105 = ! V_33 -> V_110 ;
struct V_87 * V_103 = ( void * ) F_121 ( V_111 | V_15 ,
V_108 ) ;
if ( ! V_103 ) {
F_122 ( & V_33 -> V_5 -> V_112 ) ;
V_103 = V_33 -> V_5 -> V_113 ;
V_108 = F_123 ( F_124 ( V_33 -> V_5 ) ) ;
}
V_109 = F_125 () ;
F_117 ( V_33 , V_103 , V_98 , V_104 , V_105 ) ;
V_33 -> V_82 = V_76 ;
if ( ! V_104 && ! V_76 && V_33 -> V_110 )
F_126 ( V_33 , V_103 ) ;
if ( ! V_76 && V_108 == V_33 -> V_114 ) {
V_103 -> V_89 = F_94 ( & V_33 -> V_5 -> V_26 ) ;
V_103 -> V_88 = V_33 -> V_80 [ 0 ] . V_64 -> V_88 ;
V_103 -> V_90 = V_33 -> V_80 [ 0 ] . V_64 -> V_90 ;
F_127 ( V_103 , V_33 -> V_80 [ 0 ] . V_64 ) ;
if ( V_33 -> V_5 -> V_113 == V_33 -> V_80 [ 0 ] . V_64 )
V_33 -> V_5 -> V_113 = V_103 ;
} else {
V_33 -> V_80 [ V_76 ] . V_64 -> V_19 = V_103 -> V_19 ;
memcpy ( V_33 -> V_80 [ V_76 ] . V_64 -> V_76 , V_103 -> V_76 ,
( void * ) V_77 ( V_103 ) - ( void * ) V_103 -> V_76 ) ;
}
if ( V_103 == V_33 -> V_5 -> V_113 )
F_30 ( & V_33 -> V_5 -> V_112 ) ;
else
F_128 ( ( unsigned long ) V_103 , V_108 ) ;
if ( V_33 -> V_110 )
F_84 ( V_33 ) ;
if ( ! V_76 )
F_129 ( & V_33 -> V_5 -> V_115 , V_109 ) ;
}
void F_130 ( struct V_32 * V_33 , unsigned V_76 )
{
T_1 V_108 = V_33 -> V_114 , V_19 = 0 ;
struct V_97 V_98 ;
int V_6 = F_131 ( V_33 ) ;
F_104 ( V_33 , & V_98 , NULL , & V_33 -> V_80 [ V_76 ] ) ;
F_40 ( V_33 -> V_80 [ V_33 -> V_82 ] . V_64 == F_92 ( V_33 ) &&
( V_33 -> V_80 [ V_33 -> V_82 ] . V_57 || V_33 -> V_82 ) ) ;
if ( V_76 ) {
unsigned V_21 ;
for ( V_21 = V_76 ; V_21 <= V_33 -> V_82 ; V_21 ++ )
V_19 += V_33 -> V_80 [ V_21 ] . V_64 -> V_19 ;
V_108 = F_4 ( F_132 ( V_33 -> V_80 -> V_64 ,
V_19 ) ) / V_116 ;
if ( V_108 )
V_108 = F_123 ( V_108 ) ;
}
F_120 ( V_33 , & V_98 , V_76 , V_108 , false ) ;
F_133 ( V_33 -> V_110 && V_6 >= 0 && F_131 ( V_33 ) != V_6 ) ;
}
void F_134 ( struct V_32 * V_33 , struct V_97 * V_98 )
{
F_40 ( ! V_33 -> V_110 ) ;
F_120 ( V_33 , V_98 , 0 , V_33 -> V_114 , true ) ;
}
void F_135 ( struct V_32 * V_33 , struct V_32 * V_117 )
{
T_2 V_109 = F_125 () ;
struct V_97 V_98 ;
F_136 ( V_33 , & V_98 , NULL ) ;
F_117 ( V_33 , V_117 -> V_80 -> V_64 , & V_98 , false , true ) ;
F_129 ( & V_33 -> V_5 -> V_115 , V_109 ) ;
F_45 ( & V_117 -> V_118 , & V_33 -> V_118 ) ;
V_117 -> V_80 -> V_57 = 0 ;
}
void F_137 ( struct V_32 * V_33 )
{
unsigned V_119 = V_120 ;
int V_21 ;
if ( ! V_33 -> V_82 )
goto V_103;
if ( V_33 -> V_37 ) {
F_138 ( V_33 ) ;
return;
}
for ( V_21 = V_33 -> V_82 - 1 ; V_21 >= 0 ; -- V_21 ) {
V_119 *= V_33 -> V_5 -> V_121 ;
if ( V_33 -> V_80 [ V_21 ] . V_64 -> V_19 < V_119 ) {
F_130 ( V_33 , V_21 ) ;
return;
}
}
if ( V_33 -> V_82 + 1 == V_81 ) {
F_138 ( V_33 ) ;
return;
}
V_103:
F_84 ( V_33 ) ;
}
static int F_139 ( struct V_122 * V_123 , struct V_32 * V_33 )
{
struct V_124 * V_125 = F_140 ( V_123 , struct V_124 , V_123 ) ;
unsigned V_21 ;
V_125 -> V_126 ++ ;
for ( V_21 = 0 ; V_21 <= V_33 -> V_82 ; V_21 ++ ) {
struct V_60 * V_61 = & V_33 -> V_80 [ V_21 ] ;
T_1 V_127 = V_61 -> V_64 -> V_19 * sizeof( T_2 ) ;
T_1 V_56 ;
if ( F_89 ( V_33 , V_61 ) ) {
V_125 -> V_128 ++ ;
V_125 -> V_129 += V_127 ;
V_125 -> V_130 += V_61 -> V_57 - 1 ;
for ( V_56 = 1 ; V_56 < V_61 -> V_57 ; V_56 ++ )
if ( V_61 -> V_66 [ V_56 ] . V_74 == 127 )
V_125 -> V_131 ++ ;
} else {
V_125 -> V_132 ++ ;
V_125 -> V_133 += V_127 ;
}
}
return V_134 ;
}
int F_141 ( struct V_4 * V_5 , char * V_30 )
{
struct V_124 V_61 ;
int V_100 ;
memset ( & V_61 , 0 , sizeof( struct V_124 ) ) ;
F_142 ( & V_61 . V_123 , - 1 ) ;
V_100 = F_143 ( & V_61 . V_123 , V_5 , & V_49 , F_139 ) ;
if ( V_100 < 0 )
return V_100 ;
return snprintf ( V_30 , V_116 ,
L_8
L_9
L_10
L_11
L_12
L_13
L_14 ,
V_61 . V_126 ,
V_61 . V_128 , V_61 . V_132 ,
V_61 . V_129 , V_61 . V_133 ,
V_61 . V_130 , V_61 . V_131 ) ;
}
