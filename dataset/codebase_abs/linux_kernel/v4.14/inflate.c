static void * malloc ( int V_1 )
{
void * V_2 ;
if ( V_1 < 0 )
error ( L_1 ) ;
if ( ! V_3 )
V_3 = V_4 ;
V_3 = ( V_3 + 3 ) & ~ 3 ;
V_2 = ( void * ) V_3 ;
V_3 += V_1 ;
if ( V_5 && V_3 >= V_5 )
error ( L_2 ) ;
V_6 ++ ;
return V_2 ;
}
static void free ( void * V_7 )
{
V_6 -- ;
if ( ! V_6 )
V_3 = V_4 ;
}
STATIC int T_1 F_1 (
unsigned * V_8 ,
unsigned V_9 ,
unsigned V_10 ,
const T_2 * V_11 ,
const T_2 * V_12 ,
struct V_13 * * V_14 ,
int * V_15
)
{
unsigned V_16 ;
unsigned V_17 ;
int V_18 ;
int V_19 ;
register unsigned V_20 ;
register unsigned V_21 ;
register int V_22 ;
int V_23 ;
register unsigned * V_2 ;
register struct V_13 * V_24 ;
struct V_13 V_25 ;
register int V_26 ;
unsigned * V_27 ;
int V_28 ;
unsigned V_29 ;
struct {
unsigned V_30 [ V_31 + 1 ] ;
struct V_13 * V_32 [ V_31 ] ;
unsigned V_33 [ V_34 ] ;
unsigned V_35 [ V_31 + 1 ] ;
} * V_36 ;
unsigned * V_30 , * V_33 , * V_35 ;
struct V_13 * * V_32 ;
int V_37 ;
F_2 ( L_3 ) ;
V_36 = malloc ( sizeof( * V_36 ) ) ;
if ( V_36 == NULL )
return 3 ;
V_30 = V_36 -> V_30 ;
V_33 = V_36 -> V_33 ;
V_35 = V_36 -> V_35 ;
V_32 = V_36 -> V_32 ;
F_3 ( V_36 -> V_30 , sizeof( V_36 -> V_30 ) ) ;
V_2 = V_8 ; V_20 = V_9 ;
do {
F_4 ( * V_2 , ( V_38 , ( V_9 - V_20 >= ' ' && V_9 - V_20 <= '~' ? L_4 : L_5 ) ,
V_9 - V_20 , * V_2 ) ) ;
V_30 [ * V_2 ] ++ ;
V_2 ++ ;
} while ( -- V_20 );
if ( V_30 [ 0 ] == V_9 )
{
* V_14 = (struct V_13 * ) NULL ;
* V_15 = 0 ;
V_37 = 2 ;
goto V_39;
}
F_2 ( L_6 ) ;
V_23 = * V_15 ;
for ( V_21 = 1 ; V_21 <= V_31 ; V_21 ++ )
if ( V_30 [ V_21 ] )
break;
V_22 = V_21 ;
if ( ( unsigned ) V_23 < V_21 )
V_23 = V_21 ;
for ( V_20 = V_31 ; V_20 ; V_20 -- )
if ( V_30 [ V_20 ] )
break;
V_18 = V_20 ;
if ( ( unsigned ) V_23 > V_20 )
V_23 = V_20 ;
* V_15 = V_23 ;
F_2 ( L_7 ) ;
for ( V_28 = 1 << V_21 ; V_21 < V_20 ; V_21 ++ , V_28 <<= 1 )
if ( ( V_28 -= V_30 [ V_21 ] ) < 0 ) {
V_37 = 2 ;
goto V_39;
}
if ( ( V_28 -= V_30 [ V_20 ] ) < 0 ) {
V_37 = 2 ;
goto V_39;
}
V_30 [ V_20 ] += V_28 ;
F_2 ( L_8 ) ;
V_35 [ 1 ] = V_21 = 0 ;
V_2 = V_30 + 1 ; V_27 = V_35 + 2 ;
while ( -- V_20 ) {
* V_27 ++ = ( V_21 += * V_2 ++ ) ;
}
F_2 ( L_9 ) ;
V_2 = V_8 ; V_20 = 0 ;
do {
if ( ( V_21 = * V_2 ++ ) != 0 )
V_33 [ V_35 [ V_21 ] ++ ] = V_20 ;
} while ( ++ V_20 < V_9 );
V_9 = V_35 [ V_18 ] ;
F_2 ( L_10 ) ;
V_35 [ 0 ] = V_20 = 0 ;
V_2 = V_33 ;
V_19 = - 1 ;
V_26 = - V_23 ;
V_32 [ 0 ] = (struct V_13 * ) NULL ;
V_24 = (struct V_13 * ) NULL ;
V_29 = 0 ;
F_2 ( L_11 ) ;
for (; V_22 <= V_18 ; V_22 ++ )
{
F_2 ( L_12 ) ;
V_16 = V_30 [ V_22 ] ;
while ( V_16 -- )
{
F_2 ( L_13 ) ;
while ( V_22 > V_26 + V_23 )
{
F_5 ( L_14 ) ;
V_19 ++ ;
V_26 += V_23 ;
V_29 = ( V_29 = V_18 - V_26 ) > ( unsigned ) V_23 ? V_23 : V_29 ;
if ( ( V_17 = 1 << ( V_21 = V_22 - V_26 ) ) > V_16 + 1 )
{
F_5 ( L_15 ) ;
V_17 -= V_16 + 1 ;
V_27 = V_30 + V_22 ;
if ( V_21 < V_29 )
while ( ++ V_21 < V_29 )
{
if ( ( V_17 <<= 1 ) <= * ++ V_27 )
break;
V_17 -= * V_27 ;
}
}
F_5 ( L_16 ) ;
V_29 = 1 << V_21 ;
if ( ( V_24 = (struct V_13 * ) malloc ( ( V_29 + 1 ) * sizeof( struct V_13 ) ) ) ==
(struct V_13 * ) NULL )
{
if ( V_19 )
F_6 ( V_32 [ 0 ] ) ;
V_37 = 3 ;
goto V_39;
}
F_5 ( L_17 ) ;
V_40 += V_29 + 1 ;
* V_14 = V_24 + 1 ;
* ( V_14 = & ( V_24 -> V_33 . V_14 ) ) = (struct V_13 * ) NULL ;
V_32 [ V_19 ] = ++ V_24 ;
F_5 ( L_18 ) ;
if ( V_19 )
{
V_35 [ V_19 ] = V_20 ;
V_25 . V_8 = ( V_41 ) V_23 ;
V_25 . V_12 = ( V_41 ) ( 16 + V_21 ) ;
V_25 . V_33 . V_14 = V_24 ;
V_21 = V_20 >> ( V_26 - V_23 ) ;
V_32 [ V_19 - 1 ] [ V_21 ] = V_25 ;
}
F_5 ( L_19 ) ;
}
F_2 ( L_20 ) ;
V_25 . V_8 = ( V_41 ) ( V_22 - V_26 ) ;
if ( V_2 >= V_33 + V_9 )
V_25 . V_12 = 99 ;
else if ( * V_2 < V_10 )
{
V_25 . V_12 = ( V_41 ) ( * V_2 < 256 ? 16 : 15 ) ;
V_25 . V_33 . V_9 = ( T_2 ) ( * V_2 ) ;
V_2 ++ ;
}
else
{
V_25 . V_12 = ( V_41 ) V_12 [ * V_2 - V_10 ] ;
V_25 . V_33 . V_9 = V_11 [ * V_2 ++ - V_10 ] ;
}
F_2 ( L_21 ) ;
V_17 = 1 << ( V_22 - V_26 ) ;
for ( V_21 = V_20 >> V_26 ; V_21 < V_29 ; V_21 += V_17 )
V_24 [ V_21 ] = V_25 ;
for ( V_21 = 1 << ( V_22 - 1 ) ; V_20 & V_21 ; V_21 >>= 1 )
V_20 ^= V_21 ;
V_20 ^= V_21 ;
while ( ( V_20 & ( ( 1 << V_26 ) - 1 ) ) != V_35 [ V_19 ] )
{
V_19 -- ;
V_26 -= V_23 ;
}
F_2 ( L_22 ) ;
}
F_2 ( L_23 ) ;
}
F_2 ( L_24 ) ;
V_37 = V_28 != 0 && V_18 != 1 ;
V_39:
free ( V_36 ) ;
return V_37 ;
}
STATIC int T_1 F_6 (
struct V_13 * V_14
)
{
register struct V_13 * V_2 , * V_24 ;
V_2 = V_14 ;
while ( V_2 != (struct V_13 * ) NULL )
{
V_24 = ( -- V_2 ) -> V_33 . V_14 ;
free ( ( char * ) V_2 ) ;
V_2 = V_24 ;
}
return 0 ;
}
STATIC int T_1 F_7 (
struct V_13 * V_42 ,
struct V_13 * V_43 ,
int V_44 ,
int V_45
)
{
register unsigned V_12 ;
unsigned V_9 , V_11 ;
unsigned V_26 ;
struct V_13 * V_14 ;
unsigned V_46 , V_47 ;
register T_3 V_8 ;
register unsigned V_22 ;
V_8 = V_48 ;
V_22 = V_49 ;
V_26 = V_50 ;
V_46 = V_51 [ V_44 ] ;
V_47 = V_51 [ V_45 ] ;
for (; ; )
{
F_8 ((unsigned)bl)
if ( ( V_12 = ( V_14 = V_42 + ( ( unsigned ) V_8 & V_46 ) ) -> V_12 ) > 16 )
do {
if ( V_12 == 99 )
return 1 ;
F_9 (t->b)
V_12 -= 16 ;
F_8 (e)
} while ( ( V_12 = ( V_14 = V_14 -> V_33 . V_14 + ( ( unsigned ) V_8 & V_51 [ V_12 ] ) ) -> V_12 ) > 16 );
F_9 (t->b)
if ( V_12 == 16 )
{
V_52 [ V_26 ++ ] = ( V_41 ) V_14 -> V_33 . V_9 ;
F_10 ( ( V_38 , L_25 , V_52 [ V_26 - 1 ] ) ) ;
if ( V_26 == V_53 )
{
F_11 ( V_26 ) ;
V_26 = 0 ;
}
}
else
{
if ( V_12 == 15 )
break;
F_8 (e)
V_9 = V_14 -> V_33 . V_9 + ( ( unsigned ) V_8 & V_51 [ V_12 ] ) ;
F_9 ( V_12 ) ;
F_8 ((unsigned)bd)
if ( ( V_12 = ( V_14 = V_43 + ( ( unsigned ) V_8 & V_47 ) ) -> V_12 ) > 16 )
do {
if ( V_12 == 99 )
return 1 ;
F_9 (t->b)
V_12 -= 16 ;
F_8 (e)
} while ( ( V_12 = ( V_14 = V_14 -> V_33 . V_14 + ( ( unsigned ) V_8 & V_51 [ V_12 ] ) ) -> V_12 ) > 16 );
F_9 (t->b)
F_8 (e)
V_11 = V_26 - V_14 -> V_33 . V_9 - ( ( unsigned ) V_8 & V_51 [ V_12 ] ) ;
F_9 (e)
F_10 ( ( V_38 , L_26 , V_26 - V_11 , V_9 ) ) ;
do {
V_9 -= ( V_12 = ( V_12 = V_53 - ( ( V_11 &= V_53 - 1 ) > V_26 ? V_11 : V_26 ) ) > V_9 ? V_9 : V_12 ) ;
#if ! F_12 ( V_54 ) && ! F_12 ( V_55 )
if ( V_26 - V_11 >= V_12 )
{
memcpy ( V_52 + V_26 , V_52 + V_11 , V_12 ) ;
V_26 += V_12 ;
V_11 += V_12 ;
}
else
#endif
do {
V_52 [ V_26 ++ ] = V_52 [ V_11 ++ ] ;
F_10 ( ( V_38 , L_25 , V_52 [ V_26 - 1 ] ) ) ;
} while ( -- V_12 );
if ( V_26 == V_53 )
{
F_11 ( V_26 ) ;
V_26 = 0 ;
}
} while ( V_9 );
}
}
V_50 = V_26 ;
V_48 = V_8 ;
V_49 = V_22 ;
return 0 ;
V_56:
return 4 ;
}
STATIC int T_1 F_13 ( void )
{
unsigned V_9 ;
unsigned V_26 ;
register T_3 V_8 ;
register unsigned V_22 ;
F_2 ( L_27 ) ;
V_8 = V_48 ;
V_22 = V_49 ;
V_26 = V_50 ;
V_9 = V_22 & 7 ;
F_9 ( V_9 ) ;
F_8 ( 16 )
V_9 = ( ( unsigned ) V_8 & 0xffff ) ;
F_9 ( 16 )
F_8 ( 16 )
if ( V_9 != ( unsigned ) ( ( ~ V_8 ) & 0xffff ) )
return 1 ;
F_9 ( 16 )
while ( V_9 -- )
{
F_8 ( 8 )
V_52 [ V_26 ++ ] = ( V_41 ) V_8 ;
if ( V_26 == V_53 )
{
F_11 ( V_26 ) ;
V_26 = 0 ;
}
F_9 ( 8 )
}
V_50 = V_26 ;
V_48 = V_8 ;
V_49 = V_22 ;
F_2 ( L_28 ) ;
return 0 ;
V_56:
return 4 ;
}
STATIC int T_4 T_1 F_14 ( void )
{
int V_20 ;
struct V_13 * V_42 ;
struct V_13 * V_43 ;
int V_44 ;
int V_45 ;
unsigned * V_23 ;
F_2 ( L_29 ) ;
V_23 = malloc ( sizeof( * V_23 ) * 288 ) ;
if ( V_23 == NULL )
return 3 ;
for ( V_20 = 0 ; V_20 < 144 ; V_20 ++ )
V_23 [ V_20 ] = 8 ;
for (; V_20 < 256 ; V_20 ++ )
V_23 [ V_20 ] = 9 ;
for (; V_20 < 280 ; V_20 ++ )
V_23 [ V_20 ] = 7 ;
for (; V_20 < 288 ; V_20 ++ )
V_23 [ V_20 ] = 8 ;
V_44 = 7 ;
if ( ( V_20 = F_1 ( V_23 , 288 , 257 , V_57 , V_58 , & V_42 , & V_44 ) ) != 0 ) {
free ( V_23 ) ;
return V_20 ;
}
for ( V_20 = 0 ; V_20 < 30 ; V_20 ++ )
V_23 [ V_20 ] = 5 ;
V_45 = 5 ;
if ( ( V_20 = F_1 ( V_23 , 30 , 0 , V_59 , V_60 , & V_43 , & V_45 ) ) > 1 )
{
F_6 ( V_42 ) ;
free ( V_23 ) ;
F_2 ( L_28 ) ;
return V_20 ;
}
if ( F_7 ( V_42 , V_43 , V_44 , V_45 ) ) {
free ( V_23 ) ;
return 1 ;
}
free ( V_23 ) ;
F_6 ( V_42 ) ;
F_6 ( V_43 ) ;
return 0 ;
}
STATIC int T_4 T_1 F_15 ( void )
{
int V_20 ;
unsigned V_21 ;
unsigned V_23 ;
unsigned V_15 ;
unsigned V_9 ;
struct V_13 * V_42 ;
struct V_13 * V_43 ;
int V_44 ;
int V_45 ;
unsigned V_61 ;
unsigned V_62 ;
unsigned V_63 ;
unsigned * V_64 ;
register T_3 V_8 ;
register unsigned V_22 ;
int V_37 ;
F_2 ( L_30 ) ;
#ifdef F_16
V_64 = malloc ( sizeof( * V_64 ) * ( 288 + 32 ) ) ;
#else
V_64 = malloc ( sizeof( * V_64 ) * ( 286 + 30 ) ) ;
#endif
if ( V_64 == NULL )
return 1 ;
V_8 = V_48 ;
V_22 = V_49 ;
F_8 ( 5 )
V_62 = 257 + ( ( unsigned ) V_8 & 0x1f ) ;
F_9 ( 5 )
F_8 ( 5 )
V_63 = 1 + ( ( unsigned ) V_8 & 0x1f ) ;
F_9 ( 5 )
F_8 ( 4 )
V_61 = 4 + ( ( unsigned ) V_8 & 0xf ) ;
F_9 ( 4 )
#ifdef F_16
if ( V_62 > 288 || V_63 > 32 )
#else
if ( V_62 > 286 || V_63 > 30 )
#endif
{
V_37 = 1 ;
goto V_39;
}
F_2 ( L_31 ) ;
for ( V_21 = 0 ; V_21 < V_61 ; V_21 ++ )
{
F_8 ( 3 )
V_64 [ V_65 [ V_21 ] ] = ( unsigned ) V_8 & 7 ;
F_9 ( 3 )
}
for (; V_21 < 19 ; V_21 ++ )
V_64 [ V_65 [ V_21 ] ] = 0 ;
F_2 ( L_32 ) ;
V_44 = 7 ;
if ( ( V_20 = F_1 ( V_64 , 19 , 19 , NULL , NULL , & V_42 , & V_44 ) ) != 0 )
{
if ( V_20 == 1 )
F_6 ( V_42 ) ;
V_37 = V_20 ;
goto V_39;
}
F_2 ( L_33 ) ;
V_9 = V_62 + V_63 ;
V_15 = V_51 [ V_44 ] ;
V_20 = V_23 = 0 ;
while ( ( unsigned ) V_20 < V_9 )
{
F_8 ((unsigned)bl)
V_21 = ( V_43 = V_42 + ( ( unsigned ) V_8 & V_15 ) ) -> V_8 ;
F_9 (j)
V_21 = V_43 -> V_33 . V_9 ;
if ( V_21 < 16 )
V_64 [ V_20 ++ ] = V_23 = V_21 ;
else if ( V_21 == 16 )
{
F_8 ( 2 )
V_21 = 3 + ( ( unsigned ) V_8 & 3 ) ;
F_9 ( 2 )
if ( ( unsigned ) V_20 + V_21 > V_9 ) {
V_37 = 1 ;
goto V_39;
}
while ( V_21 -- )
V_64 [ V_20 ++ ] = V_23 ;
}
else if ( V_21 == 17 )
{
F_8 ( 3 )
V_21 = 3 + ( ( unsigned ) V_8 & 7 ) ;
F_9 ( 3 )
if ( ( unsigned ) V_20 + V_21 > V_9 ) {
V_37 = 1 ;
goto V_39;
}
while ( V_21 -- )
V_64 [ V_20 ++ ] = 0 ;
V_23 = 0 ;
}
else
{
F_8 ( 7 )
V_21 = 11 + ( ( unsigned ) V_8 & 0x7f ) ;
F_9 ( 7 )
if ( ( unsigned ) V_20 + V_21 > V_9 ) {
V_37 = 1 ;
goto V_39;
}
while ( V_21 -- )
V_64 [ V_20 ++ ] = 0 ;
V_23 = 0 ;
}
}
F_2 ( L_34 ) ;
F_6 ( V_42 ) ;
F_2 ( L_35 ) ;
V_48 = V_8 ;
V_49 = V_22 ;
F_2 ( L_36 ) ;
V_44 = V_66 ;
if ( ( V_20 = F_1 ( V_64 , V_62 , 257 , V_57 , V_58 , & V_42 , & V_44 ) ) != 0 )
{
F_2 ( L_37 ) ;
if ( V_20 == 1 ) {
error ( L_38 ) ;
F_6 ( V_42 ) ;
}
V_37 = V_20 ;
goto V_39;
}
F_2 ( L_39 ) ;
V_45 = V_67 ;
if ( ( V_20 = F_1 ( V_64 + V_62 , V_63 , 0 , V_59 , V_60 , & V_43 , & V_45 ) ) != 0 )
{
F_2 ( L_40 ) ;
if ( V_20 == 1 ) {
error ( L_41 ) ;
#ifdef F_16
V_20 = 0 ;
}
#else
F_6 ( V_43 ) ;
}
F_6 ( V_42 ) ;
V_37 = V_20 ;
goto V_39;
#endif
}
int T_1 F_17 (
int * V_12
)
{
unsigned V_14 ;
register T_3 V_8 ;
register unsigned V_22 ;
F_2 ( L_42 ) ;
V_8 = V_48 ;
V_22 = V_49 ;
F_8 ( 1 )
* V_12 = ( int ) V_8 & 1 ;
F_9 ( 1 )
F_8 ( 2 )
V_14 = ( unsigned ) V_8 & 3 ;
F_9 ( 2 )
V_48 = V_8 ;
V_49 = V_22 ;
if ( V_14 == 2 )
return F_15 () ;
if ( V_14 == 0 )
return F_13 () ;
if ( V_14 == 1 )
return F_14 () ;
F_2 ( L_28 ) ;
return 2 ;
V_56:
return 4 ;
}
STATIC int T_1 F_18 ( void )
{
int V_12 ;
int V_25 ;
unsigned V_19 ;
V_50 = 0 ;
V_49 = 0 ;
V_48 = 0 ;
V_19 = 0 ;
do {
V_40 = 0 ;
#ifdef F_19
F_20 () ;
#endif
V_25 = F_17 ( & V_12 ) ;
if ( V_25 )
return V_25 ;
if ( V_40 > V_19 )
V_19 = V_40 ;
} while ( ! V_12 );
while ( V_49 >= 8 ) {
V_49 -= 8 ;
V_68 -- ;
}
F_11 ( V_50 ) ;
#ifdef V_55
fprintf ( V_38 , L_43 , V_19 ) ;
#endif
return 0 ;
}
static void T_1
F_21 ( void )
{
unsigned long V_30 ;
unsigned long V_12 ;
int V_20 ;
int V_22 ;
static const int V_2 [] = { 0 , 1 , 2 , 4 , 5 , 7 , 8 , 10 , 11 , 12 , 16 , 22 , 23 , 26 } ;
V_12 = 0 ;
for ( V_20 = 0 ; V_20 < sizeof( V_2 ) / sizeof( int ) ; V_20 ++ )
V_12 |= 1L << ( 31 - V_2 [ V_20 ] ) ;
V_69 [ 0 ] = 0 ;
for ( V_20 = 1 ; V_20 < 256 ; V_20 ++ )
{
V_30 = 0 ;
for ( V_22 = V_20 | 256 ; V_22 != 1 ; V_22 >>= 1 )
{
V_30 = V_30 & 1 ? ( V_30 >> 1 ) ^ V_12 : V_30 >> 1 ;
if ( V_22 & 1 )
V_30 ^= V_12 ;
}
V_69 [ V_20 ] = V_30 ;
}
V_70 = ( T_3 ) 0xffffffffUL ;
}
static int T_1 F_22 ( void )
{
V_41 V_71 ;
unsigned char V_72 [ 2 ] ;
char V_73 ;
T_3 V_74 = 0 ;
T_3 V_75 = 0 ;
int V_76 ;
V_72 [ 0 ] = F_23 () ;
V_72 [ 1 ] = F_23 () ;
V_73 = F_23 () ;
if ( V_72 [ 0 ] != 037 ||
( ( V_72 [ 1 ] != 0213 ) && ( V_72 [ 1 ] != 0236 ) ) ) {
error ( L_44 ) ;
return - 1 ;
}
if ( V_73 != 8 ) {
error ( L_45 ) ;
return - 1 ;
}
V_71 = ( V_41 ) F_24 () ;
if ( ( V_71 & V_77 ) != 0 ) {
error ( L_46 ) ;
return - 1 ;
}
if ( ( V_71 & V_78 ) != 0 ) {
error ( L_47 ) ;
return - 1 ;
}
if ( ( V_71 & V_79 ) != 0 ) {
error ( L_48 ) ;
return - 1 ;
}
F_23 () ;
F_23 () ;
F_23 () ;
F_23 () ;
( void ) F_23 () ;
( void ) F_23 () ;
if ( ( V_71 & V_80 ) != 0 ) {
unsigned V_81 = ( unsigned ) F_23 () ;
V_81 |= ( ( unsigned ) F_23 () ) << 8 ;
while ( V_81 -- ) ( void ) F_23 () ;
}
if ( ( V_71 & V_82 ) != 0 ) {
while ( F_23 () != 0 ) ;
}
if ( ( V_71 & V_83 ) != 0 ) {
while ( F_23 () != 0 ) ;
}
if ( ( V_76 = F_18 () ) ) {
switch ( V_76 ) {
case 0 :
break;
case 1 :
error ( L_49 ) ;
break;
case 2 :
error ( L_50 ) ;
break;
case 3 :
error ( L_51 ) ;
break;
case 4 :
error ( L_52 ) ;
break;
default:
error ( L_53 ) ;
}
return - 1 ;
}
V_74 = ( T_3 ) F_23 () ;
V_74 |= ( T_3 ) F_23 () << 8 ;
V_74 |= ( T_3 ) F_23 () << 16 ;
V_74 |= ( T_3 ) F_23 () << 24 ;
V_75 = ( T_3 ) F_23 () ;
V_75 |= ( T_3 ) F_23 () << 8 ;
V_75 |= ( T_3 ) F_23 () << 16 ;
V_75 |= ( T_3 ) F_23 () << 24 ;
if ( V_74 != V_84 ) {
error ( L_54 ) ;
return - 1 ;
}
if ( V_75 != V_85 ) {
error ( L_55 ) ;
return - 1 ;
}
return 0 ;
V_56:
error ( L_52 ) ;
return - 1 ;
}
