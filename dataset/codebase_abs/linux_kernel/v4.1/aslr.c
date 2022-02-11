static inline T_1 F_1 ( void )
{
T_1 V_1 , V_2 ;
do {
F_2 ( V_3 ,
V_4 | V_5 ) ;
V_1 = F_3 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
V_2 |= F_3 ( V_6 ) << 8 ;
} while ( V_1 & V_7 );
return V_2 ;
}
static unsigned long F_4 ( unsigned long V_8 , const void * V_9 ,
T_2 V_10 )
{
T_2 V_11 ;
unsigned long * V_12 = ( unsigned long * ) V_9 ;
for ( V_11 = 0 ; V_11 < V_10 / sizeof( V_8 ) ; V_11 ++ ) {
V_8 = ( V_8 << ( ( sizeof( V_8 ) * 8 ) - 7 ) ) | ( V_8 >> 7 ) ;
V_8 ^= V_12 [ V_11 ] ;
}
return V_8 ;
}
static unsigned long F_5 ( void )
{
unsigned long V_8 = 0 ;
V_8 = F_4 ( V_8 , V_13 , sizeof( V_13 ) ) ;
V_8 = F_4 ( V_8 , V_14 , sizeof( * V_14 ) ) ;
return V_8 ;
}
static unsigned long F_6 ( void )
{
#ifdef F_7
const unsigned long V_15 = 0x5d6008cbf3848dd3UL ;
#else
const unsigned long V_15 = 0x3f39e593UL ;
#endif
unsigned long V_16 , V_17 = F_5 () ;
bool V_18 = true ;
F_8 ( L_1 ) ;
if ( F_9 ( V_19 ) ) {
F_8 ( L_2 ) ;
if ( F_10 ( & V_16 ) ) {
V_17 ^= V_16 ;
V_18 = false ;
}
}
if ( F_9 ( V_20 ) ) {
F_8 ( L_3 ) ;
F_11 ( V_16 ) ;
V_17 ^= V_16 ;
V_18 = false ;
}
if ( V_18 ) {
F_8 ( L_4 ) ;
V_17 ^= F_1 () ;
}
asm("mul %3"
: "=a" (random), "=d" (raw)
: "a" (random), "rm" (mix_const));
V_17 += V_16 ;
F_8 ( L_5 ) ;
return V_17 ;
}
static bool F_12 ( struct V_21 * V_22 , struct V_21 * V_23 )
{
if ( V_23 -> V_24 < V_22 -> V_24 )
return false ;
if ( V_23 -> V_24 + V_23 -> V_10 > V_22 -> V_24 + V_22 -> V_10 )
return false ;
return true ;
}
static bool F_13 ( struct V_21 * V_25 , struct V_21 * V_26 )
{
if ( V_25 -> V_24 + V_25 -> V_10 <= V_26 -> V_24 )
return false ;
if ( V_25 -> V_24 >= V_26 -> V_24 + V_26 -> V_10 )
return false ;
return true ;
}
static void F_14 ( unsigned long V_27 , unsigned long V_28 ,
unsigned long V_29 , unsigned long V_30 )
{
T_3 V_31 , V_32 ;
T_3 V_33 , V_34 ;
unsigned long V_35 , V_36 ;
char * V_12 ;
V_36 = ( V_30 >> 12 ) + 32768 + 18 ;
V_35 = ( unsigned long ) V_27 + V_28 - V_36 ;
V_37 [ 0 ] . V_24 = V_35 ;
V_37 [ 0 ] . V_10 = V_36 ;
V_31 = ( T_3 ) V_14 -> V_38 << 32 ;
V_31 |= V_14 -> V_39 . V_40 ;
V_32 = ( T_3 ) V_14 -> V_41 << 32 ;
V_32 |= V_14 -> V_39 . V_42 ;
V_37 [ 1 ] . V_24 = V_31 ;
V_37 [ 1 ] . V_10 = V_32 ;
V_33 = ( T_3 ) V_14 -> V_43 << 32 ;
V_33 |= V_14 -> V_39 . V_44 ;
V_12 = ( char * ) ( unsigned long ) V_33 ;
for ( V_34 = 0 ; V_12 [ V_34 ++ ] ; )
;
V_37 [ 2 ] . V_24 = V_33 ;
V_37 [ 2 ] . V_10 = V_34 ;
V_37 [ 3 ] . V_24 = ( unsigned long ) V_45 ;
V_37 [ 3 ] . V_10 = V_46 ;
V_37 [ 4 ] . V_24 = ( unsigned long ) V_47 ;
V_37 [ 4 ] . V_10 = V_48 ;
}
static bool F_15 ( struct V_21 * V_49 )
{
int V_11 ;
struct V_50 * V_12 ;
for ( V_11 = 0 ; V_11 < V_51 ; V_11 ++ ) {
if ( F_13 ( V_49 , & V_37 [ V_11 ] ) )
return true ;
}
V_12 = (struct V_50 * ) ( unsigned long ) V_14 -> V_39 . V_50 ;
while ( V_12 ) {
struct V_21 V_52 ;
V_52 . V_24 = ( unsigned long ) V_12 ;
V_52 . V_10 = sizeof( * V_12 ) + V_12 -> V_53 ;
if ( F_13 ( V_49 , & V_52 ) )
return true ;
V_12 = (struct V_50 * ) ( unsigned long ) V_12 -> V_54 ;
}
return false ;
}
static void F_16 ( unsigned long V_55 )
{
if ( V_56 >= V_57 /
V_58 )
return;
V_59 [ V_56 ++ ] = V_55 ;
}
static unsigned long F_17 ( void )
{
if ( V_56 == 0 )
return 0 ;
return V_59 [ F_6 () % V_56 ] ;
}
static void F_18 ( struct V_60 * V_61 ,
unsigned long V_62 ,
unsigned long V_63 )
{
struct V_21 V_22 , V_49 ;
if ( V_61 -> type != V_64 )
return;
if ( V_61 -> V_55 >= V_57 )
return;
if ( V_61 -> V_55 + V_61 -> V_10 < V_62 )
return;
V_22 . V_24 = V_61 -> V_55 ;
V_22 . V_10 = V_61 -> V_10 ;
if ( V_22 . V_24 < V_62 )
V_22 . V_24 = V_62 ;
V_22 . V_24 = F_19 ( V_22 . V_24 , V_58 ) ;
if ( V_22 . V_24 > V_61 -> V_55 + V_61 -> V_10 )
return;
V_22 . V_10 -= V_22 . V_24 - V_61 -> V_55 ;
if ( V_22 . V_24 + V_22 . V_10 > V_57 )
V_22 . V_10 = V_57 - V_22 . V_24 ;
for ( V_49 . V_24 = V_22 . V_24 , V_49 . V_10 = V_63 ;
F_12 ( & V_22 , & V_49 ) ;
V_49 . V_24 += V_58 ) {
if ( F_15 ( & V_49 ) )
continue;
F_16 ( V_49 . V_24 ) ;
}
}
static unsigned long F_20 ( unsigned long V_62 ,
unsigned long V_10 )
{
int V_11 ;
unsigned long V_55 ;
V_62 = F_19 ( V_62 , V_58 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_65 ; V_11 ++ ) {
F_18 ( & V_14 -> V_66 [ V_11 ] , V_62 , V_10 ) ;
}
return F_17 () ;
}
unsigned char * F_21 ( struct V_67 * V_67 ,
unsigned char * V_27 ,
unsigned long V_28 ,
unsigned char * V_29 ,
unsigned long V_30 )
{
unsigned long V_68 = ( unsigned long ) V_29 ;
unsigned long V_17 ;
#ifdef F_22
if ( ! F_23 ( L_6 ) ) {
F_8 ( L_7 ) ;
goto V_69;
}
#else
if ( F_23 ( L_8 ) ) {
F_8 ( L_9 ) ;
goto V_69;
}
#endif
V_67 -> V_39 . V_70 |= V_71 ;
F_14 ( ( unsigned long ) V_27 , V_28 ,
( unsigned long ) V_29 , V_30 ) ;
V_17 = F_20 ( V_68 , V_30 ) ;
if ( ! V_17 ) {
F_8 ( L_10 ) ;
goto V_69;
}
if ( V_17 < V_68 )
goto V_69;
V_68 = V_17 ;
V_69:
return ( unsigned char * ) V_68 ;
}
