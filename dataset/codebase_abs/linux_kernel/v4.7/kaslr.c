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
static unsigned long F_6 ( const char * V_15 )
{
#ifdef F_7
const unsigned long V_16 = 0x5d6008cbf3848dd3UL ;
#else
const unsigned long V_16 = 0x3f39e593UL ;
#endif
unsigned long V_17 , V_18 = F_5 () ;
bool V_19 = true ;
F_8 ( V_15 ) ;
F_8 ( L_1 ) ;
if ( F_9 ( V_20 ) ) {
F_8 ( L_2 ) ;
if ( F_10 ( & V_17 ) ) {
V_18 ^= V_17 ;
V_19 = false ;
}
}
if ( F_9 ( V_21 ) ) {
F_8 ( L_3 ) ;
V_17 = F_11 () ;
V_18 ^= V_17 ;
V_19 = false ;
}
if ( V_19 ) {
F_8 ( L_4 ) ;
V_18 ^= F_1 () ;
}
asm("mul %3"
: "=a" (random), "=d" (raw)
: "a" (random), "rm" (mix_const));
V_18 += V_17 ;
F_8 ( L_5 ) ;
return V_18 ;
}
static bool F_12 ( struct V_22 * V_23 , struct V_22 * V_24 )
{
if ( V_24 -> V_25 < V_23 -> V_25 )
return false ;
if ( V_24 -> V_25 + V_24 -> V_10 > V_23 -> V_25 + V_23 -> V_10 )
return false ;
return true ;
}
static bool F_13 ( struct V_22 * V_26 , struct V_22 * V_27 )
{
if ( V_26 -> V_25 + V_26 -> V_10 <= V_27 -> V_25 )
return false ;
if ( V_26 -> V_25 >= V_27 -> V_25 + V_27 -> V_10 )
return false ;
return true ;
}
static void F_14 ( unsigned long V_28 , unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_31 = V_14 -> V_32 . V_31 ;
T_3 V_33 , V_34 ;
T_3 V_35 , V_36 ;
char * V_12 ;
V_37 [ V_38 ] . V_25 = V_28 ;
V_37 [ V_38 ] . V_10 = ( V_30 + V_31 ) - V_28 ;
F_15 ( V_37 [ V_38 ] . V_25 ,
V_37 [ V_38 ] . V_10 ) ;
V_33 = ( T_3 ) V_14 -> V_39 << 32 ;
V_33 |= V_14 -> V_32 . V_40 ;
V_34 = ( T_3 ) V_14 -> V_41 << 32 ;
V_34 |= V_14 -> V_32 . V_42 ;
V_37 [ V_43 ] . V_25 = V_33 ;
V_37 [ V_43 ] . V_10 = V_34 ;
V_35 = ( T_3 ) V_14 -> V_44 << 32 ;
V_35 |= V_14 -> V_32 . V_45 ;
V_12 = ( char * ) ( unsigned long ) V_35 ;
for ( V_36 = 0 ; V_12 [ V_36 ++ ] ; )
;
V_37 [ V_46 ] . V_25 = V_35 ;
V_37 [ V_46 ] . V_10 = V_36 ;
F_15 ( V_37 [ V_46 ] . V_25 ,
V_37 [ V_46 ] . V_10 ) ;
V_37 [ V_47 ] . V_25 = ( unsigned long ) V_14 ;
V_37 [ V_47 ] . V_10 = sizeof( * V_14 ) ;
F_15 ( V_37 [ V_47 ] . V_25 ,
V_37 [ V_47 ] . V_10 ) ;
#ifdef F_16
F_15 ( 0 , V_48 ) ;
#endif
}
static bool F_17 ( struct V_22 * V_49 ,
struct V_22 * V_50 )
{
int V_11 ;
struct V_51 * V_12 ;
unsigned long V_52 = V_49 -> V_25 + V_49 -> V_10 ;
bool V_53 = false ;
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
if ( F_13 ( V_49 , & V_37 [ V_11 ] ) &&
V_37 [ V_11 ] . V_25 < V_52 ) {
* V_50 = V_37 [ V_11 ] ;
V_53 = true ;
}
}
V_12 = (struct V_51 * ) ( unsigned long ) V_14 -> V_32 . V_51 ;
while ( V_12 ) {
struct V_22 V_55 ;
V_55 . V_25 = ( unsigned long ) V_12 ;
V_55 . V_10 = sizeof( * V_12 ) + V_12 -> V_56 ;
if ( F_13 ( V_49 , & V_55 ) && ( V_55 . V_25 < V_52 ) ) {
* V_50 = V_55 ;
V_53 = true ;
}
V_12 = (struct V_51 * ) ( unsigned long ) V_12 -> V_57 ;
}
return V_53 ;
}
static void F_18 ( struct V_22 * V_23 , unsigned long V_58 )
{
struct V_59 V_59 ;
if ( V_60 == V_61 )
return;
V_59 . V_62 = V_23 -> V_25 ;
V_59 . V_63 = ( V_23 -> V_10 - V_58 ) /
V_64 + 1 ;
if ( V_59 . V_63 > 0 ) {
V_65 [ V_60 ++ ] = V_59 ;
V_66 += V_59 . V_63 ;
}
}
static void F_19 ( unsigned long V_62 )
{
if ( V_66 >= V_67 / V_64 )
return;
V_68 [ V_66 ++ ] = V_62 ;
}
static unsigned long F_20 ( void )
{
if ( V_66 == 0 )
return 0 ;
return V_68 [ F_6 ( L_6 ) % V_66 ] ;
}
static void F_21 ( struct V_69 * V_70 ,
unsigned long V_71 ,
unsigned long V_58 )
{
struct V_22 V_23 , V_49 , V_50 ;
if ( V_70 -> type != V_72 )
return;
if ( V_70 -> V_62 >= V_67 )
return;
if ( V_70 -> V_62 + V_70 -> V_10 < V_71 )
return;
V_23 . V_25 = V_70 -> V_62 ;
V_23 . V_10 = V_70 -> V_10 ;
if ( V_23 . V_25 < V_71 )
V_23 . V_25 = V_71 ;
V_23 . V_25 = F_22 ( V_23 . V_25 , V_64 ) ;
if ( V_23 . V_25 > V_70 -> V_62 + V_70 -> V_10 )
return;
V_23 . V_10 -= V_23 . V_25 - V_70 -> V_62 ;
if ( V_23 . V_25 + V_23 . V_10 > V_67 )
V_23 . V_10 = V_67 - V_23 . V_25 ;
for ( V_49 . V_25 = V_23 . V_25 , V_49 . V_10 = V_58 ;
F_12 ( & V_23 , & V_49 ) ;
V_49 . V_25 += V_64 ) {
if ( F_17 ( & V_49 , & V_50 ) )
continue;
F_19 ( V_49 . V_25 ) ;
}
}
static unsigned long F_23 ( unsigned long V_71 ,
unsigned long V_58 )
{
int V_11 ;
unsigned long V_62 ;
V_71 = F_22 ( V_71 , V_64 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_73 ; V_11 ++ ) {
F_21 ( & V_14 -> V_74 [ V_11 ] , V_71 ,
V_58 ) ;
}
return F_20 () ;
}
static unsigned long F_24 ( unsigned long V_71 ,
unsigned long V_58 )
{
unsigned long V_68 , V_75 ;
V_71 = F_22 ( V_71 , V_64 ) ;
V_58 = F_22 ( V_58 , V_64 ) ;
V_68 = ( V_67 - V_71 - V_58 ) /
V_64 + 1 ;
V_75 = F_6 ( L_7 ) % V_68 ;
return V_75 * V_64 + V_71 ;
}
unsigned char * F_25 ( unsigned long V_28 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_76 )
{
unsigned long V_77 = V_30 ;
unsigned long V_75 ;
#ifdef F_26
if ( ! F_27 ( L_8 ) ) {
F_28 ( L_9 ) ;
goto V_78;
}
#else
if ( F_27 ( L_10 ) ) {
F_28 ( L_11 ) ;
goto V_78;
}
#endif
V_14 -> V_32 . V_79 |= V_80 ;
F_14 ( V_28 , V_29 , V_30 ) ;
V_75 = F_23 ( V_30 , V_76 ) ;
if ( ! V_75 ) {
F_28 ( L_12 ) ;
goto V_78;
}
if ( V_75 < V_77 )
goto V_78;
V_77 = V_75 ;
F_15 ( V_77 , V_76 ) ;
F_29 () ;
V_78:
return ( unsigned char * ) V_77 ;
}
