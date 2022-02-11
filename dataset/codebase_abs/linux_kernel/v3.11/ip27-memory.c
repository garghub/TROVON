static int F_1 ( void )
{
return ( ( ( F_2 ( V_1 ) & V_2 )
>> V_3 ) & V_4 ) ;
}
static T_1 F_3 ( T_2 V_5 )
{
if ( V_6 )
return F_4 ( V_5 ) >> V_7 ;
else
return F_4 ( V_5 ) >> V_8 ;
}
static void F_5 ( T_1 * V_9 )
{
T_2 V_5 ;
( * V_9 ) = 0 ;
F_6 (cnode) {
( * V_9 ) |= 1ULL << F_3 ( V_5 ) ;
}
}
static void F_7 ( T_3 * V_10 , T_3 * V_11 , int V_12 )
{
T_3 * V_13 ;
T_4 * V_14 ;
int V_15 ;
if ( V_10 -> V_16 == 1 )
return;
if ( V_12 >= V_17 )
return;
V_10 -> V_16 = 1 ;
for ( V_15 = 1 ; V_15 <= V_18 ; V_15 ++ ) {
if ( V_10 -> V_19 [ V_15 ] . V_20 == V_21 )
continue;
V_14 = ( T_4 * ) F_8 (
V_10 -> V_19 [ V_15 ] . V_20 ,
V_10 -> V_19 [ V_15 ] . V_22 ) ;
if ( V_14 -> V_23 == V_24 ) {
V_13 = ( T_3 * ) F_8 ( F_9 ( V_14 ) , V_14 -> V_25 [ 0 ] ) ;
if ( V_13 == V_11 ) {
if ( V_12 < V_17 )
V_17 = V_12 ;
}
else
F_7 ( V_13 , V_11 , V_12 + 1 ) ;
}
}
V_10 -> V_16 = 0 ;
}
static int T_5 F_10 ( T_6 V_26 , T_6 V_27 )
{
T_3 * V_13 , * V_10 = NULL , * V_11 = NULL ;
T_4 * V_14 , * V_28 ;
T_2 V_5 ;
T_6 V_29 ;
int V_15 ;
F_6 (cnode) {
V_29 = F_4 ( V_5 ) ;
if ( V_29 == - 1 ) continue;
V_14 = F_11 ( ( T_4 * ) F_12 ( V_29 ) ,
V_24 ) ;
if ( ! V_14 )
continue;
do {
if ( V_14 -> V_30 & V_31 )
continue;
V_13 = ( T_3 * ) F_8 ( F_9 ( V_14 ) , V_14 -> V_25 [ 0 ] ) ;
V_13 -> V_16 = 0 ;
for ( V_15 = 1 ; V_15 <= V_18 ; V_15 ++ ) {
if ( V_13 -> V_19 [ V_15 ] . V_20 == V_21 )
continue;
V_28 = ( T_4 * ) F_8 (
V_13 -> V_19 [ V_15 ] . V_20 ,
V_13 -> V_19 [ V_15 ] . V_22 ) ;
if ( V_28 -> V_23 == V_32 ) {
if ( V_28 -> V_33 == V_26 )
V_10 = V_13 ;
if ( V_28 -> V_33 == V_27 )
V_11 = V_13 ;
}
}
} while ( ( V_14 = F_11 ( F_13 ( V_14 ) , V_24 ) ) );
}
if ( V_10 == NULL ) {
F_14 ( L_1 ) ;
return - 1 ;
}
if ( V_11 == NULL ) {
F_14 ( L_2 ) ;
return - 1 ;
}
if ( V_26 == V_27 )
return 0 ;
if ( V_10 == V_11 )
return 1 ;
V_17 = 100 ;
F_7 ( V_10 , V_11 , 2 ) ;
return V_17 ;
}
static void T_5 F_15 ( void )
{
T_6 V_29 , V_34 ;
T_2 V_35 , V_36 ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ )
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_38 [ V_35 ] [ V_36 ] = - 1 ;
F_6 (row) {
V_29 = F_4 ( V_35 ) ;
F_6 (col) {
V_34 = F_4 ( V_36 ) ;
V_38 [ V_35 ] [ V_36 ] =
F_10 ( V_29 , V_34 ) ;
}
}
}
static void T_5 F_16 ( void )
{
T_6 V_29 ;
T_2 V_5 ;
T_4 * V_14 , * V_28 ;
int V_15 ;
int V_39 = 0 ;
T_3 * V_13 ;
T_2 V_35 , V_36 ;
F_14 ( L_3 ) ;
F_14 ( L_4 ) ;
F_6 (col)
F_14 ( L_5 , V_36 ) ;
F_14 ( L_6 ) ;
F_6 (row) {
F_14 ( L_7 , V_35 ) ;
F_6 (col)
F_14 ( L_8 , F_17 ( V_35 , V_36 ) ) ;
F_14 ( L_6 ) ;
}
F_6 (cnode) {
V_29 = F_4 ( V_5 ) ;
if ( V_29 == - 1 ) continue;
V_14 = F_11 ( ( T_4 * ) F_12 ( V_29 ) ,
V_24 ) ;
if ( ! V_14 )
continue;
do {
if ( V_14 -> V_30 & V_31 )
continue;
F_14 ( L_9 , V_39 ) ;
V_39 ++ ;
V_13 = ( T_3 * ) F_8 ( F_9 ( V_14 ) , V_14 -> V_25 [ 0 ] ) ;
for ( V_15 = 1 ; V_15 <= V_18 ; V_15 ++ ) {
if ( V_13 -> V_19 [ V_15 ] . V_20 == V_21 )
continue;
V_28 = ( T_4 * ) F_8 (
V_13 -> V_19 [ V_15 ] . V_20 ,
V_13 -> V_19 [ V_15 ] . V_22 ) ;
if ( V_28 -> V_23 == V_32 )
F_14 ( L_10 , V_28 -> V_33 ) ;
if ( V_28 -> V_23 == V_24 )
F_14 ( L_11 ) ;
}
F_14 ( L_6 ) ;
} while ( ( V_14 = F_11 ( F_13 ( V_14 ) , V_24 ) ) );
}
}
static unsigned long T_5 F_18 ( T_2 V_5 , int V_40 )
{
T_6 V_29 = F_4 ( V_5 ) ;
return ( ( unsigned long ) V_29 << V_41 ) | ( V_40 << V_42 ) ;
}
static unsigned long T_5 F_19 ( T_2 V_43 , int V_40 )
{
T_6 V_29 ;
T_4 * V_14 ;
T_7 * V_44 ;
unsigned long V_45 ;
V_29 = F_4 ( V_43 ) ;
V_14 = F_20 ( ( T_4 * ) F_12 ( V_29 ) , V_32 ) ;
if ( ! V_14 )
return 0 ;
V_44 = ( T_7 * ) F_21 ( V_14 , V_46 ) ;
if ( ! V_44 )
return 0 ;
V_45 = ( unsigned long ) V_44 -> V_47 [ V_40 / 4 ] ;
if ( V_45 <= 128 ) {
if ( V_40 % 4 == 0 ) {
V_45 <<= 20 ;
return ( V_45 >> V_48 ) ;
} else
return 0 ;
} else {
V_45 /= 4 ;
V_45 <<= 20 ;
return V_45 >> V_48 ;
}
}
static void T_5 F_22 ( void )
{
int V_49 ;
V_50 = F_23 () ;
V_6 = F_1 () ;
#ifdef F_24
F_25 () ;
#endif
F_15 () ;
F_16 () ;
F_5 ( & V_9 ) ;
F_26 () ;
F_6 (i) {
T_6 V_29 ;
V_29 = F_4 ( V_49 ) ;
F_27 ( V_29 , V_51 , ( V_9 | 1 ) ) ;
#ifdef F_28
F_27 ( V_29 , V_52 , V_53 ) ;
#else
F_27 ( V_29 , V_52 , V_54 ) ;
#endif
#ifdef F_29
F_27 ( V_29 , F_30 ( V_55 ) ,
( ( V_56 << V_57 ) |
( 0 << V_58 ) ) ) ;
#endif
}
}
static void T_5 F_31 ( void )
{
unsigned long V_59 , V_60 = 0 , V_61 ;
int V_40 ;
T_2 V_43 ;
F_6 (node) {
V_61 = 0 ;
for ( V_40 = 0 ; V_40 < V_62 ; V_40 ++ ) {
V_59 = F_19 ( V_43 , V_40 ) ;
if ( V_40 == 0 )
V_60 = V_59 ;
V_61 += ( 1LL << V_63 ) ;
if ( ! V_59 )
continue;
if ( ( V_61 >> V_48 ) * ( sizeof( struct V_64 ) ) >
( V_60 << V_48 ) ) {
F_14 ( L_12 ,
V_40 , V_43 ) ;
V_40 = V_62 ;
continue;
}
F_32 ( F_33 ( F_18 ( V_43 , V_40 ) ) ,
F_33 ( V_59 ) , V_43 ) ;
}
}
}
static void T_5 F_34 ( T_2 V_43 )
{
unsigned long V_65 = F_18 ( V_43 , 0 ) ;
unsigned long V_66 = F_35 ( V_43 ) ;
unsigned long V_67 ;
unsigned long V_68 , V_69 ;
F_36 ( V_43 , & V_68 , & V_69 ) ;
V_70 [ V_43 ] = F_37 ( V_66 << V_48 ) ;
memset ( V_70 [ V_43 ] , 0 , V_71 ) ;
F_38 ( V_43 ) -> V_72 = & V_73 [ V_43 ] ;
F_38 ( V_43 ) -> V_74 = V_68 ;
F_38 ( V_43 ) -> V_75 = V_69 - V_68 ;
F_39 ( F_40 ( V_43 ) -> V_76 ) ;
V_66 += F_41 ( sizeof( struct V_77 ) +
sizeof( struct F_40 ) ) ;
V_67 = F_42 ( F_38 ( V_43 ) , V_66 ,
V_68 , V_69 ) ;
F_43 ( V_43 , V_69 ) ;
F_44 ( F_38 ( V_43 ) , V_65 << V_48 ,
( ( V_66 - V_65 ) << V_48 ) + V_67 ,
V_78 ) ;
F_45 ( V_43 ) ;
}
void T_5 F_46 ( void )
{
T_2 V_43 ;
F_22 () ;
F_31 () ;
for ( V_43 = 0 ; V_43 < V_37 ; V_43 ++ ) {
if ( F_47 ( V_43 ) ) {
F_34 ( V_43 ) ;
continue;
}
V_70 [ V_43 ] = & V_79 ;
}
}
void T_5 F_48 ( void )
{
}
void T_5 F_49 ( void )
{
unsigned long V_80 [ V_81 ] = { 0 , } ;
unsigned V_43 ;
F_50 () ;
F_6 (node) {
unsigned long V_68 , V_69 ;
F_36 ( V_43 , & V_68 , & V_69 ) ;
if ( V_69 > V_82 )
V_82 = V_69 ;
}
V_80 [ V_83 ] = V_82 ;
F_51 ( V_80 ) ;
}
void T_5 F_52 ( void )
{
V_84 = ( void * ) F_37 ( F_53 () << V_48 ) ;
F_54 () ;
F_55 () ;
F_56 ( NULL ) ;
}
