void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned V_5 )
{
struct V_6 * V_7 , * V_8 ;
for ( V_7 = V_4 -> V_9 ; V_7 < F_2 ( V_4 ) ; V_7 = V_8 ) {
V_8 = F_3 ( V_7 ) ;
F_4 ( V_10 L_1 , V_5 ,
( V_11 * ) V_7 - V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_2 -> V_14 -> V_15 )
V_2 -> V_14 -> V_15 ( V_2 , V_7 ) ;
else
F_4 ( L_2 , F_5 ( V_7 ) , F_6 ( V_7 ) ) ;
if ( V_8 < F_2 ( V_4 ) &&
F_7 ( V_7 , V_2 -> V_14 -> V_16 ?
& F_8 ( V_8 ) : V_8 ) > 0 )
F_4 ( V_10 L_3 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
unsigned V_4 ;
F_10 () ;
for ( V_4 = 0 ; V_4 <= V_2 -> V_17 ; V_4 ++ )
F_1 ( V_2 , V_2 -> V_5 [ V_4 ] . V_18 ,
F_11 ( V_2 , V_2 -> V_5 [ V_4 ] . V_18 ) ) ;
F_12 () ;
}
int F_13 ( struct V_1 * V_2 )
{
unsigned V_19 = 0 ;
struct V_20 V_21 ;
struct V_6 * V_7 ;
if ( V_2 -> V_14 -> V_16 )
F_14 (b, k, &iter)
V_19 += F_15 ( V_7 ) ;
return V_19 ;
}
void F_16 ( struct V_1 * V_2 , const char * V_22 , ... )
{
T_1 args ;
struct V_6 * V_7 , * V_23 = NULL ;
struct V_20 V_21 ;
const char * V_24 ;
F_14 (b, k, &iter) {
if ( V_2 -> V_14 -> V_16 ) {
V_24 = L_4 ;
if ( V_23 && F_7 ( & F_8 ( V_23 ) , & F_8 ( V_7 ) ) > 0 )
goto V_25;
if ( F_17 ( V_2 , V_7 ) )
continue;
V_24 = L_5 ;
if ( V_23 && F_7 ( V_23 , & F_8 ( V_7 ) ) > 0 )
goto V_25;
} else {
if ( F_18 ( V_2 , V_7 ) )
continue;
V_24 = L_6 ;
if ( V_23 && ! F_7 ( V_23 , V_7 ) )
goto V_25;
}
V_23 = V_7 ;
}
#if 0
err = "Key larger than btree node key";
if (p && bkey_cmp(p, &b->key) > 0)
goto bug;
#endif
return;
V_25:
F_9 ( V_2 ) ;
va_start ( args , V_22 ) ;
F_19 ( V_22 , args ) ;
va_end ( args ) ;
F_20 ( L_7 , V_24 ) ;
}
static void F_21 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_18 -> V_7 , * V_8 = F_3 ( V_7 ) ;
if ( V_8 < V_21 -> V_18 -> V_26 &&
F_7 ( V_7 , V_21 -> V_2 -> V_14 -> V_16 ?
& F_8 ( V_8 ) : V_8 ) > 0 ) {
F_9 ( V_21 -> V_2 ) ;
F_20 ( L_3 ) ;
}
}
static inline void F_21 ( struct V_20 * V_21 ) {}
int F_22 ( struct V_27 * V_28 , unsigned V_29 )
{
T_2 V_30 = F_23 ( V_28 ) ;
T_2 V_31 = V_30 + V_29 ;
V_11 * V_32 = V_28 -> V_33 == V_28 -> V_34 ? NULL : V_28 -> V_33 ;
V_11 * V_35 ;
V_31 = F_24 ( V_31 ) ;
if ( V_31 <= V_36 ||
F_24 ( V_30 ) == V_31 )
return 0 ;
V_35 = F_25 ( V_32 , sizeof( V_11 ) * V_31 , V_37 ) ;
if ( ! V_35 )
return - V_38 ;
if ( ! V_32 )
memcpy ( V_35 , V_28 -> V_34 , sizeof( V_11 ) * V_30 ) ;
V_28 -> V_33 = V_35 ;
V_28 -> V_39 = V_35 + V_30 ;
return 0 ;
}
struct V_6 * F_26 ( struct V_27 * V_28 )
{
struct V_6 * V_7 = V_28 -> V_13 ;
if ( V_7 == V_28 -> V_40 )
return NULL ;
while ( F_3 ( V_7 ) != V_28 -> V_40 )
V_7 = F_3 ( V_7 ) ;
return V_28 -> V_40 = V_7 ;
}
void F_27 ( struct V_27 * V_28 )
{
V_28 -> V_39 -= F_28 ( V_28 -> V_13 ) ;
memmove ( V_28 -> V_13 ,
F_3 ( V_28 -> V_13 ) ,
F_29 ( V_28 ) ) ;
}
void F_30 ( struct V_6 * V_41 , const struct V_6 * V_42 ,
unsigned V_4 )
{
F_31 ( V_4 > F_32 ( V_42 ) ) ;
memcpy ( V_41 , V_42 , 2 * sizeof( V_11 ) ) ;
V_41 -> V_43 [ 0 ] = V_42 -> V_43 [ V_4 ] ;
F_33 ( V_41 , 1 ) ;
F_34 ( V_41 , 0 ) ;
}
bool F_35 ( const struct V_6 * V_44 , struct V_6 * V_7 )
{
unsigned V_4 , V_45 = 0 ;
if ( F_7 ( V_44 , & F_8 ( V_7 ) ) <= 0 )
return false ;
if ( F_7 ( V_44 , V_7 ) < 0 )
V_45 = F_6 ( V_7 ) - F_6 ( V_44 ) ;
else
F_36 ( V_7 , V_44 ) ;
for ( V_4 = 0 ; V_4 < F_32 ( V_7 ) ; V_4 ++ )
F_37 ( V_7 , V_4 , F_38 ( V_7 , V_4 ) + F_15 ( V_7 ) - V_45 ) ;
F_31 ( V_45 > F_15 ( V_7 ) ) ;
F_39 ( V_7 , V_45 ) ;
return true ;
}
bool F_40 ( const struct V_6 * V_44 , struct V_6 * V_7 )
{
unsigned V_45 = 0 ;
if ( F_7 ( V_44 , V_7 ) >= 0 )
return false ;
F_31 ( F_5 ( V_44 ) != F_5 ( V_7 ) ) ;
if ( F_7 ( V_44 , & F_8 ( V_7 ) ) > 0 )
V_45 = F_6 ( V_44 ) - F_41 ( V_7 ) ;
F_36 ( V_7 , V_44 ) ;
F_31 ( V_45 > F_15 ( V_7 ) ) ;
F_39 ( V_7 , V_45 ) ;
return true ;
}
static inline T_2 F_42 ( struct V_1 * V_2 )
{
return V_46 << V_2 -> V_47 ;
}
static inline T_2 F_43 ( struct V_1 * V_2 )
{
return F_42 ( V_2 ) / V_48 ;
}
static inline T_2 F_44 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) * sizeof( struct V_49 ) ;
}
static inline T_2 F_45 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) * sizeof( V_50 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = V_2 -> V_5 ;
if ( F_45 ( V_2 ) < V_46 )
F_47 ( V_52 -> V_53 ) ;
else
F_48 ( ( unsigned long ) V_52 -> V_53 ,
F_49 ( F_45 ( V_2 ) ) ) ;
if ( F_44 ( V_2 ) < V_46 )
F_47 ( V_52 -> V_54 ) ;
else
F_48 ( ( unsigned long ) V_52 -> V_54 ,
F_49 ( F_44 ( V_2 ) ) ) ;
F_48 ( ( unsigned long ) V_52 -> V_18 , V_2 -> V_47 ) ;
V_52 -> V_53 = NULL ;
V_52 -> V_54 = NULL ;
V_52 -> V_18 = NULL ;
}
int F_50 ( struct V_1 * V_2 , unsigned V_47 , T_3 V_55 )
{
struct V_51 * V_52 = V_2 -> V_5 ;
F_31 ( V_52 -> V_18 ) ;
V_2 -> V_47 = V_47 ;
V_52 -> V_18 = ( void * ) F_51 ( V_55 , V_2 -> V_47 ) ;
if ( ! V_52 -> V_18 )
goto V_24;
V_52 -> V_54 = F_44 ( V_2 ) < V_46
? F_52 ( F_44 ( V_2 ) , V_55 )
: ( void * ) F_51 ( V_55 , F_49 ( F_44 ( V_2 ) ) ) ;
if ( ! V_52 -> V_54 )
goto V_24;
V_52 -> V_53 = F_45 ( V_2 ) < V_46
? F_52 ( F_45 ( V_2 ) , V_55 )
: ( void * ) F_51 ( V_55 , F_49 ( F_45 ( V_2 ) ) ) ;
if ( ! V_52 -> V_53 )
goto V_24;
return 0 ;
V_24:
F_46 ( V_2 ) ;
return - V_38 ;
}
void F_53 ( struct V_1 * V_2 , const struct V_56 * V_14 ,
bool * V_57 )
{
unsigned V_4 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_17 = 0 ;
V_2 -> V_58 = 0 ;
for ( V_4 = 0 ; V_4 < V_59 ; V_4 ++ )
V_2 -> V_5 [ V_4 ] . V_60 = 0 ;
for ( V_4 = 1 ; V_4 < V_59 ; V_4 ++ )
V_2 -> V_5 [ V_4 ] . V_18 = NULL ;
}
static unsigned F_54 ( unsigned V_61 , unsigned V_60 )
{
if ( V_61 * 2 + 1 < V_60 ) {
V_61 = V_61 * 2 + 1 ;
while ( V_61 * 2 < V_60 )
V_61 *= 2 ;
} else
V_61 >>= F_55 ( V_61 ) + 1 ;
return V_61 ;
}
static unsigned F_56 ( unsigned V_61 , unsigned V_60 )
{
if ( V_61 * 2 < V_60 ) {
V_61 = V_61 * 2 ;
while ( V_61 * 2 + 1 < V_60 )
V_61 = V_61 * 2 + 1 ;
} else
V_61 >>= F_57 ( V_61 ) ;
return V_61 ;
}
static unsigned F_58 ( unsigned V_61 , unsigned V_60 , unsigned V_62 )
{
unsigned V_2 = F_59 ( V_61 ) ;
unsigned V_63 = F_59 ( V_60 - 1 ) - V_2 ;
V_61 ^= 1U << ( V_2 - 1 ) ;
V_61 <<= 1 ;
V_61 |= 1 ;
V_61 <<= V_63 ;
if ( V_61 > V_62 )
V_61 -= ( V_61 - V_62 ) >> 1 ;
return V_61 ;
}
static unsigned F_60 ( unsigned V_61 , struct V_51 * V_52 )
{
return F_58 ( V_61 , V_52 -> V_60 , V_52 -> V_62 ) ;
}
static unsigned F_61 ( unsigned V_61 , unsigned V_60 , unsigned V_62 )
{
unsigned V_63 ;
if ( V_61 > V_62 )
V_61 += V_61 - V_62 ;
V_63 = F_57 ( V_61 ) ;
V_61 >>= V_63 ;
V_61 |= F_24 ( V_60 ) >> V_63 ;
return V_61 ;
}
static unsigned F_62 ( unsigned V_61 , struct V_51 * V_52 )
{
return F_61 ( V_61 , V_52 -> V_60 , V_52 -> V_62 ) ;
}
static struct V_6 * F_63 ( struct V_51 * V_52 , unsigned V_64 ,
unsigned V_65 )
{
return ( ( void * ) V_52 -> V_18 ) + V_64 * V_48 + V_65 * 8 ;
}
static unsigned F_64 ( struct V_51 * V_52 , struct V_6 * V_7 )
{
return ( ( void * ) V_7 - ( void * ) V_52 -> V_18 ) / V_48 ;
}
static unsigned F_65 ( struct V_51 * V_52 ,
unsigned V_64 ,
struct V_6 * V_7 )
{
return ( V_66 * ) V_7 - ( V_66 * ) F_63 ( V_52 , V_64 , 0 ) ;
}
static struct V_6 * F_66 ( struct V_51 * V_52 , unsigned V_61 )
{
return F_63 ( V_52 , F_60 ( V_61 , V_52 ) , V_52 -> V_54 [ V_61 ] . V_67 ) ;
}
static struct V_6 * F_67 ( struct V_51 * V_52 , unsigned V_61 )
{
return ( void * ) ( ( ( V_11 * ) F_66 ( V_52 , V_61 ) ) - V_52 -> V_53 [ V_61 ] ) ;
}
static struct V_6 * F_68 ( struct V_51 * V_52 , unsigned V_64 )
{
return F_63 ( V_52 , V_64 , V_52 -> V_53 [ V_64 ] ) ;
}
static inline V_11 F_69 ( V_11 V_68 , V_11 V_69 , V_50 V_63 )
{
V_69 >>= V_63 ;
V_69 |= ( V_68 << 1 ) << ( 63U - V_63 ) ;
return V_69 ;
}
static inline unsigned F_70 ( const struct V_6 * V_7 ,
struct V_49 * V_70 )
{
const V_11 * V_23 = & V_7 -> V_69 - ( V_70 -> V_71 >> 6 ) ;
return F_69 ( V_23 [ - 1 ] , V_23 [ 0 ] , V_70 -> V_71 & 63 ) & V_72 ;
}
static void F_71 ( struct V_51 * V_52 , unsigned V_61 )
{
struct V_49 * V_70 = & V_52 -> V_54 [ V_61 ] ;
struct V_6 * V_67 = F_66 ( V_52 , V_61 ) ;
struct V_6 * V_23 = F_67 ( V_52 , V_61 ) ;
struct V_6 * V_28 = F_72 ( V_61 )
? V_52 -> V_18 -> V_9
: F_67 ( V_52 , V_61 >> F_57 ( V_61 ) ) ;
struct V_6 * V_73 = F_72 ( V_61 + 1 )
? F_73 ( V_52 -> V_18 , V_52 -> V_18 -> V_13 - F_28 ( & V_52 -> V_26 ) )
: F_66 ( V_52 , V_61 >> ( F_55 ( V_61 ) + 1 ) ) ;
F_31 ( V_67 < V_28 || V_67 > V_73 ) ;
F_31 ( F_3 ( V_23 ) != V_67 ) ;
if ( F_5 ( V_28 ) != F_5 ( V_73 ) )
V_70 -> V_71 = F_74 ( F_5 ( V_73 ) ^ F_5 ( V_28 ) ) + 64 ;
else
V_70 -> V_71 = F_74 ( V_73 -> V_69 ^ V_28 -> V_69 ) ;
V_70 -> V_71 = F_75 ( int , V_70 -> V_71 - V_74 , 0 ) ;
if ( F_70 ( V_67 , V_70 ) != F_70 ( V_23 , V_70 ) )
V_70 -> V_75 = F_70 ( V_67 , V_70 ) - 1 ;
else
V_70 -> V_71 = 127 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
if ( V_52 != V_2 -> V_5 ) {
unsigned V_61 = F_77 ( V_52 [ - 1 ] . V_60 ,
64 / sizeof( struct V_49 ) ) ;
V_52 -> V_54 = V_52 [ - 1 ] . V_54 + V_61 ;
V_52 -> V_53 = V_52 [ - 1 ] . V_53 + V_61 ;
}
while ( V_52 < V_2 -> V_5 + V_59 )
V_52 ++ -> V_60 = 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_79 ( V_2 ) ;
F_31 ( V_2 -> V_58 ) ;
V_2 -> V_58 = 1 ;
F_76 ( V_2 , V_52 ) ;
if ( V_52 -> V_54 != V_2 -> V_5 -> V_54 + F_43 ( V_2 ) ) {
V_52 -> V_53 [ 0 ] = F_65 ( V_52 , 0 , V_52 -> V_18 -> V_9 ) ;
V_52 -> V_60 = 1 ;
}
}
void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 , V_11 V_76 )
{
if ( V_4 != V_2 -> V_5 -> V_18 ) {
V_2 -> V_5 [ ++ V_2 -> V_17 ] . V_18 = V_4 ;
V_4 -> V_77 = V_2 -> V_5 -> V_18 -> V_77 ;
} else
F_81 ( & V_4 -> V_77 , sizeof( V_11 ) ) ;
V_4 -> V_76 = V_76 ;
V_4 -> V_78 = 0 ;
V_4 -> V_13 = 0 ;
F_78 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_79 ( V_2 ) ;
struct V_6 * V_53 = NULL , * V_7 = V_52 -> V_18 -> V_9 ;
unsigned V_61 , V_64 = 1 ;
V_2 -> V_58 = 0 ;
F_76 ( V_2 , V_52 ) ;
V_52 -> V_60 = F_83 ( unsigned ,
F_64 ( V_52 , F_2 ( V_52 -> V_18 ) ) ,
V_2 -> V_5 -> V_54 + F_43 ( V_2 ) - V_52 -> V_54 ) ;
if ( V_52 -> V_60 < 2 ) {
V_52 -> V_60 = 0 ;
return;
}
V_52 -> V_62 = ( V_52 -> V_60 - F_84 ( V_52 -> V_60 - 1 ) ) << 1 ;
for ( V_61 = F_54 ( 0 , V_52 -> V_60 ) ;
V_61 ;
V_61 = F_54 ( V_61 , V_52 -> V_60 ) ) {
while ( F_64 ( V_52 , V_7 ) < V_64 )
V_53 = V_7 , V_7 = F_3 ( V_7 ) ;
V_52 -> V_53 [ V_61 ] = F_28 ( V_53 ) ;
V_52 -> V_54 [ V_61 ] . V_67 = F_65 ( V_52 , V_64 ++ , V_7 ) ;
}
while ( F_3 ( V_7 ) != F_2 ( V_52 -> V_18 ) )
V_7 = F_3 ( V_7 ) ;
V_52 -> V_26 = * V_7 ;
for ( V_61 = F_54 ( 0 , V_52 -> V_60 ) ;
V_61 ;
V_61 = F_54 ( V_61 , V_52 -> V_60 ) )
F_71 ( V_52 , V_61 ) ;
}
void F_85 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_51 * V_52 ;
unsigned V_79 , V_61 = 1 ;
for ( V_52 = V_2 -> V_5 ; V_52 <= F_79 ( V_2 ) ; V_52 ++ )
if ( V_7 < F_2 ( V_52 -> V_18 ) )
goto V_80;
F_86 () ;
V_80:
if ( ! V_52 -> V_60 || ! F_87 ( V_2 , V_52 ) )
return;
V_79 = F_64 ( V_52 , V_7 ) ;
if ( V_7 == V_52 -> V_18 -> V_9 )
goto V_81;
if ( F_3 ( V_7 ) == F_2 ( V_52 -> V_18 ) ) {
V_52 -> V_26 = * V_7 ;
goto V_82;
}
V_61 = F_62 ( V_79 , V_52 ) ;
if ( V_61 &&
V_61 < V_52 -> V_60 &&
V_7 == F_66 ( V_52 , V_61 ) )
V_81: do {
F_71 ( V_52 , V_61 ) ;
V_61 = V_61 * 2 ;
} while ( V_61 < V_52 -> V_60 );
V_61 = F_62 ( V_79 + 1 , V_52 ) ;
if ( V_61 &&
V_61 < V_52 -> V_60 &&
V_7 == F_67 ( V_52 , V_61 ) )
V_82: do {
F_71 ( V_52 , V_61 ) ;
V_61 = V_61 * 2 + 1 ;
} while ( V_61 < V_52 -> V_60 );
}
static void F_88 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_6 * V_7 )
{
unsigned V_63 = F_28 ( V_7 ) ;
unsigned V_61 = F_64 ( V_52 , V_7 ) ;
if ( ! V_52 -> V_60 )
return;
while ( V_61 < V_52 -> V_60 &&
F_68 ( V_52 , V_61 ) <= V_7 )
V_61 ++ ;
for (; V_61 < V_52 -> V_60 ; V_61 ++ ) {
V_52 -> V_53 [ V_61 ] += V_63 ;
if ( V_52 -> V_53 [ V_61 ] > 7 ) {
V_7 = F_68 ( V_52 , V_61 - 1 ) ;
while ( V_7 < F_63 ( V_52 , V_61 , 0 ) )
V_7 = F_3 ( V_7 ) ;
V_52 -> V_53 [ V_61 ] = F_65 ( V_52 , V_61 , V_7 ) ;
}
}
if ( V_52 -> V_60 == V_2 -> V_5 -> V_54 + F_43 ( V_2 ) - V_52 -> V_54 )
return;
for ( V_7 = F_68 ( V_52 , V_52 -> V_60 - 1 ) ;
V_7 != F_2 ( V_52 -> V_18 ) ;
V_7 = F_3 ( V_7 ) )
if ( V_52 -> V_60 == F_64 ( V_52 , V_7 ) ) {
V_52 -> V_53 [ V_52 -> V_60 ] = F_65 ( V_52 , V_52 -> V_60 , V_7 ) ;
V_52 -> V_60 ++ ;
}
}
bool F_89 ( struct V_1 * V_2 , struct V_6 * V_28 , struct V_6 * V_73 )
{
if ( ! V_2 -> V_14 -> V_83 )
return false ;
if ( ! F_90 ( V_28 , V_73 ) ||
F_7 ( V_28 , & F_8 ( V_73 ) ) )
return false ;
return V_2 -> V_14 -> V_83 ( V_2 , V_28 , V_73 ) ;
}
void F_91 ( struct V_1 * V_2 , struct V_6 * V_44 ,
struct V_6 * V_84 )
{
struct V_51 * V_52 = F_79 ( V_2 ) ;
F_31 ( ! V_2 -> V_58 ) ;
F_31 ( F_92 ( V_2 , V_52 -> V_18 ) +
F_93 ( V_52 -> V_18 , V_52 -> V_18 -> V_13 + F_28 ( V_84 ) ) >
V_46 << V_2 -> V_47 ) ;
memmove ( ( V_11 * ) V_44 + F_28 ( V_84 ) ,
V_44 ,
( void * ) F_2 ( V_52 -> V_18 ) - ( void * ) V_44 ) ;
V_52 -> V_18 -> V_13 += F_28 ( V_84 ) ;
F_94 ( V_44 , V_84 ) ;
F_88 ( V_2 , V_52 , V_44 ) ;
}
unsigned F_95 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_6 * V_85 )
{
unsigned V_86 = V_87 ;
struct V_3 * V_4 = F_79 ( V_2 ) -> V_18 ;
struct V_6 * V_67 , * V_53 = NULL ;
struct V_20 V_21 ;
F_31 ( V_2 -> V_14 -> V_16 && ! F_15 ( V_7 ) ) ;
V_67 = F_96 ( V_2 , & V_21 , V_2 -> V_14 -> V_16
? F_97 ( & F_8 ( V_7 ) )
: F_97 ( V_7 ) ) ;
if ( V_2 -> V_14 -> V_88 ( V_2 , V_7 , & V_21 , V_85 ) )
return V_86 ;
V_86 = V_89 ;
while ( V_67 != F_2 ( V_4 ) &&
F_7 ( V_7 , V_2 -> V_14 -> V_16 ? & F_8 ( V_67 ) : V_67 ) > 0 )
V_53 = V_67 , V_67 = F_3 ( V_67 ) ;
V_86 = V_90 ;
if ( V_53 &&
F_89 ( V_2 , V_53 , V_7 ) )
goto V_91;
#if 0
status = BTREE_INSERT_STATUS_OVERWROTE;
if (m != bset_bkey_last(i) &&
KEY_PTRS(m) == KEY_PTRS(k) && !KEY_SIZE(m))
goto copy;
#endif
V_86 = V_92 ;
if ( V_67 != F_2 ( V_4 ) &&
F_89 ( V_2 , V_7 , V_67 ) )
goto V_93;
F_91 ( V_2 , V_67 , V_7 ) ;
V_93: F_94 ( V_67 , V_7 ) ;
V_91:
return V_86 ;
}
static struct V_94 F_98 ( struct V_51 * V_52 ,
const struct V_6 * V_95 )
{
unsigned V_96 = 0 , V_97 = V_52 -> V_60 ;
while ( V_96 + 1 != V_97 ) {
unsigned V_67 = ( V_96 + V_97 ) >> 1 ;
if ( F_7 ( F_68 ( V_52 , V_67 ) , V_95 ) > 0 )
V_97 = V_67 ;
else
V_96 = V_67 ;
}
return (struct V_94 ) {
F_68 ( V_52 , V_96 ) ,
V_97 < V_52 -> V_60 ? F_68 ( V_52 , V_97 ) : F_2 (t->data)
} ;
}
static struct V_94 F_99 ( struct V_51 * V_52 ,
const struct V_6 * V_95 )
{
struct V_6 * V_28 , * V_73 ;
struct V_49 * V_70 ;
unsigned V_79 , V_61 , V_98 = 1 ;
do {
unsigned V_23 = V_98 << 4 ;
V_23 &= ( ( int ) ( V_23 - V_52 -> V_60 ) ) >> 31 ;
F_100 ( & V_52 -> V_54 [ V_23 ] ) ;
V_61 = V_98 ;
V_70 = & V_52 -> V_54 [ V_61 ] ;
if ( F_101 ( V_70 -> V_71 != 127 ) )
V_98 = V_61 * 2 + ( ( ( unsigned )
( V_70 -> V_75 -
F_70 ( V_95 , V_70 ) ) ) >> 31 ) ;
else
V_98 = ( F_7 ( F_66 ( V_52 , V_61 ) , V_95 ) > 0 )
? V_61 * 2
: V_61 * 2 + 1 ;
} while ( V_98 < V_52 -> V_60 );
V_79 = F_60 ( V_61 , V_52 ) ;
if ( V_98 & 1 ) {
V_28 = F_63 ( V_52 , V_79 , V_70 -> V_67 ) ;
if ( ++ V_79 != V_52 -> V_60 ) {
V_70 = & V_52 -> V_54 [ F_54 ( V_61 , V_52 -> V_60 ) ] ;
V_73 = F_63 ( V_52 , V_79 , V_70 -> V_67 ) ;
} else
V_73 = F_2 ( V_52 -> V_18 ) ;
} else {
V_73 = F_63 ( V_52 , V_79 , V_70 -> V_67 ) ;
if ( -- V_79 ) {
V_70 = & V_52 -> V_54 [ F_56 ( V_61 , V_52 -> V_60 ) ] ;
V_28 = F_63 ( V_52 , V_79 , V_70 -> V_67 ) ;
} else
V_28 = V_52 -> V_18 -> V_9 ;
}
return (struct V_94 ) { V_28 , V_73 } ;
}
struct V_6 * F_102 ( struct V_1 * V_2 , struct V_51 * V_52 ,
const struct V_6 * V_95 )
{
struct V_94 V_4 ;
if ( F_103 ( ! V_52 -> V_60 ) ) {
V_4 . V_28 = V_52 -> V_18 -> V_9 ;
V_4 . V_73 = F_2 ( V_52 -> V_18 ) ;
} else if ( F_87 ( V_2 , V_52 ) ) {
if ( F_103 ( F_7 ( V_95 , & V_52 -> V_26 ) >= 0 ) )
return F_2 ( V_52 -> V_18 ) ;
if ( F_103 ( F_7 ( V_95 , V_52 -> V_18 -> V_9 ) < 0 ) )
return V_52 -> V_18 -> V_9 ;
V_4 = F_99 ( V_52 , V_95 ) ;
} else {
F_31 ( ! V_2 -> V_17 &&
V_52 -> V_60 < F_64 ( V_52 , F_2 ( V_52 -> V_18 ) ) ) ;
V_4 = F_98 ( V_52 , V_95 ) ;
}
if ( F_104 ( V_2 ) ) {
F_31 ( F_87 ( V_2 , V_52 ) &&
V_4 . V_28 != V_52 -> V_18 -> V_9 &&
F_7 ( F_67 ( V_52 ,
F_62 ( F_64 ( V_52 , V_4 . V_28 ) , V_52 ) ) ,
V_95 ) > 0 ) ;
F_31 ( V_4 . V_73 != F_2 ( V_52 -> V_18 ) &&
F_7 ( V_4 . V_73 , V_95 ) <= 0 ) ;
}
while ( F_101 ( V_4 . V_28 != V_4 . V_73 ) &&
F_7 ( V_4 . V_28 , V_95 ) <= 0 )
V_4 . V_28 = F_3 ( V_4 . V_28 ) ;
return V_4 . V_28 ;
}
static inline bool F_105 ( struct V_99 V_28 ,
struct V_99 V_73 )
{
return F_7 ( V_28 . V_7 , V_73 . V_7 ) > 0 ;
}
static inline bool F_106 ( struct V_20 * V_21 )
{
return ! V_21 -> V_100 ;
}
void F_107 ( struct V_20 * V_21 , struct V_6 * V_7 ,
struct V_6 * V_26 )
{
if ( V_7 != V_26 )
F_31 (!heap_add(iter,
((struct btree_iter_set) { k, end }),
btree_iter_cmp)) ;
}
static struct V_6 * F_108 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_6 * V_95 ,
struct V_51 * V_9 )
{
struct V_6 * V_19 = NULL ;
V_21 -> V_60 = F_109 ( V_21 -> V_18 ) ;
V_21 -> V_100 = 0 ;
#ifdef F_110
V_21 -> V_2 = V_2 ;
#endif
for (; V_9 <= F_79 ( V_2 ) ; V_9 ++ ) {
V_19 = F_111 ( V_2 , V_9 , V_95 ) ;
F_107 ( V_21 , V_19 , F_2 ( V_9 -> V_18 ) ) ;
}
return V_19 ;
}
struct V_6 * F_96 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_6 * V_95 )
{
return F_108 ( V_2 , V_21 , V_95 , V_2 -> V_5 ) ;
}
static inline struct V_6 * F_112 ( struct V_20 * V_21 ,
T_4 * V_101 )
{
struct V_99 V_102 ;
struct V_6 * V_19 = NULL ;
if ( ! F_106 ( V_21 ) ) {
F_21 ( V_21 ) ;
V_19 = V_21 -> V_18 -> V_7 ;
V_21 -> V_18 -> V_7 = F_3 ( V_21 -> V_18 -> V_7 ) ;
if ( V_21 -> V_18 -> V_7 > V_21 -> V_18 -> V_26 ) {
F_113 ( 1 , L_8 ) ;
V_21 -> V_18 -> V_7 = V_21 -> V_18 -> V_26 ;
}
if ( V_21 -> V_18 -> V_7 == V_21 -> V_18 -> V_26 )
F_114 ( V_21 , V_102 , V_101 ) ;
else
F_115 ( V_21 , 0 , V_101 ) ;
}
return V_19 ;
}
struct V_6 * F_116 ( struct V_20 * V_21 )
{
return F_112 ( V_21 , F_105 ) ;
}
struct V_6 * F_117 ( struct V_20 * V_21 ,
struct V_1 * V_2 , T_5 V_103 )
{
struct V_6 * V_19 ;
do {
V_19 = F_116 ( V_21 ) ;
} while ( V_19 && V_103 ( V_2 , V_19 ) );
return V_19 ;
}
void F_118 ( struct V_104 * V_105 )
{
if ( V_105 -> V_106 )
F_119 ( V_105 -> V_106 ) ;
}
int F_120 ( struct V_104 * V_105 , unsigned V_47 )
{
F_121 ( & V_105 -> time . V_107 ) ;
V_105 -> V_47 = V_47 ;
V_105 -> V_108 = F_122 ( 1 << V_47 ) ;
V_105 -> V_106 = F_123 ( 1 , V_47 ) ;
if ( ! V_105 -> V_106 )
return - V_38 ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 , struct V_3 * V_109 ,
struct V_20 * V_21 ,
bool V_110 , bool V_111 )
{
int V_4 ;
struct V_6 * V_7 , * V_112 = NULL ;
F_125 (k) V_113 ;
bool (* F_126)( struct V_1 * , const struct V_6 * ) = V_111
? F_18
: F_17 ;
for ( V_4 = V_21 -> V_100 / 2 - 1 ; V_4 >= 0 ; -- V_4 )
F_115 ( V_21 , V_4 , V_2 -> V_14 -> V_114 ) ;
while ( ! F_106 ( V_21 ) ) {
if ( V_2 -> V_14 -> V_115 && V_110 )
V_7 = V_2 -> V_14 -> V_115 ( V_21 , & V_113 . V_7 ) ;
else
V_7 = NULL ;
if ( ! V_7 )
V_7 = F_112 ( V_21 , V_2 -> V_14 -> V_114 ) ;
if ( F_126 ( V_2 , V_7 ) )
continue;
if ( ! V_112 ) {
V_112 = V_109 -> V_9 ;
F_94 ( V_112 , V_7 ) ;
} else if ( ! F_89 ( V_2 , V_112 , V_7 ) ) {
V_112 = F_3 ( V_112 ) ;
F_94 ( V_112 , V_7 ) ;
}
}
V_109 -> V_13 = V_112 ? ( V_11 * ) F_3 ( V_112 ) - V_109 -> V_12 : 0 ;
F_127 ( L_9 , V_109 -> V_13 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_20 * V_21 ,
unsigned V_9 , unsigned V_116 , bool V_110 ,
struct V_104 * V_105 )
{
V_11 V_117 ;
bool V_118 = false ;
struct V_3 * V_109 = ( void * ) F_51 ( V_119 | V_37 ,
V_116 ) ;
if ( ! V_109 ) {
struct V_120 * V_121 ;
F_31 ( V_116 > V_105 -> V_47 ) ;
V_121 = F_129 ( V_105 -> V_106 , V_37 ) ;
V_109 = F_130 ( V_121 ) ;
V_118 = true ;
V_116 = V_105 -> V_47 ;
}
V_117 = F_131 () ;
F_124 ( V_2 , V_109 , V_21 , V_110 , false ) ;
V_2 -> V_17 = V_9 ;
if ( ! V_9 && V_116 == V_2 -> V_47 ) {
V_109 -> V_76 = V_2 -> V_5 -> V_18 -> V_76 ;
V_109 -> V_77 = V_2 -> V_5 -> V_18 -> V_77 ;
V_109 -> V_78 = V_2 -> V_5 -> V_18 -> V_78 ;
F_132 ( V_109 , V_2 -> V_5 -> V_18 ) ;
} else {
V_2 -> V_5 [ V_9 ] . V_18 -> V_13 = V_109 -> V_13 ;
memcpy ( V_2 -> V_5 [ V_9 ] . V_18 -> V_9 , V_109 -> V_9 ,
( void * ) F_2 ( V_109 ) - ( void * ) V_109 -> V_9 ) ;
}
if ( V_118 )
F_133 ( F_134 ( V_109 ) , V_105 -> V_106 ) ;
else
F_48 ( ( unsigned long ) V_109 , V_116 ) ;
F_82 ( V_2 ) ;
if ( ! V_9 )
F_135 ( & V_105 -> time , V_117 ) ;
}
void F_136 ( struct V_1 * V_2 , unsigned V_9 ,
struct V_104 * V_105 )
{
T_2 V_116 = V_2 -> V_47 , V_13 = 0 ;
struct V_20 V_21 ;
int V_30 = F_137 ( V_2 ) ;
F_108 ( V_2 , & V_21 , NULL , & V_2 -> V_5 [ V_9 ] ) ;
if ( V_9 ) {
unsigned V_4 ;
for ( V_4 = V_9 ; V_4 <= V_2 -> V_17 ; V_4 ++ )
V_13 += V_2 -> V_5 [ V_4 ] . V_18 -> V_13 ;
V_116 = F_49 ( F_93 ( V_2 -> V_5 -> V_18 , V_13 ) ) ;
}
F_128 ( V_2 , & V_21 , V_9 , V_116 , false , V_105 ) ;
F_138 ( V_30 >= 0 && F_137 ( V_2 ) != V_30 ) ;
}
void F_139 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_104 * V_105 )
{
F_128 ( V_2 , V_21 , 0 , V_2 -> V_47 , true , V_105 ) ;
}
void F_140 ( struct V_1 * V_2 , struct V_1 * V_122 ,
struct V_104 * V_105 )
{
V_11 V_117 = F_131 () ;
struct V_20 V_21 ;
F_96 ( V_2 , & V_21 , NULL ) ;
F_124 ( V_2 , V_122 -> V_5 -> V_18 , & V_21 , false , true ) ;
F_135 ( & V_105 -> time , V_117 ) ;
V_122 -> V_5 -> V_60 = 0 ;
}
void F_141 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
unsigned V_123 = V_124 ;
int V_4 ;
if ( ! V_2 -> V_17 )
goto V_109;
for ( V_4 = V_2 -> V_17 - 1 ; V_4 >= 0 ; -- V_4 ) {
V_123 *= V_105 -> V_108 ;
if ( V_2 -> V_5 [ V_4 ] . V_18 -> V_13 < V_123 ) {
F_136 ( V_2 , V_4 , V_105 ) ;
return;
}
}
if ( V_2 -> V_17 + 1 == V_59 ) {
F_142 ( V_2 , V_105 ) ;
return;
}
V_109:
F_82 ( V_2 ) ;
}
void F_143 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
unsigned V_4 ;
for ( V_4 = 0 ; V_4 <= V_2 -> V_17 ; V_4 ++ ) {
struct V_51 * V_52 = & V_2 -> V_5 [ V_4 ] ;
T_2 V_127 = V_52 -> V_18 -> V_13 * sizeof( V_11 ) ;
T_2 V_61 ;
if ( F_87 ( V_2 , V_52 ) ) {
V_126 -> V_128 ++ ;
V_126 -> V_129 += V_127 ;
V_126 -> V_130 += V_52 -> V_60 - 1 ;
for ( V_61 = 1 ; V_61 < V_52 -> V_60 ; V_61 ++ )
if ( V_52 -> V_54 [ V_61 ] . V_71 == 127 )
V_126 -> V_131 ++ ;
} else {
V_126 -> V_132 ++ ;
V_126 -> V_133 += V_127 ;
}
}
}
