static T_1 void F_1 ( volatile struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
}
static T_1 T_3 F_2 ( volatile struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
return V_2 -> V_6 ;
}
static T_1 void F_3 ( volatile struct V_1 * V_2 , T_2 V_3 , T_3 V_7 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
V_2 -> V_6 = V_7 ;
}
static T_1 void F_4 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 &= ~ V_9 ;
}
static T_1 void F_5 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 = V_9 | V_10 ;
}
static T_1 void F_6 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 |= V_11 ;
}
static T_1 void F_7 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 |= V_12 ;
}
static int F_8 ( volatile struct V_1 * V_2 )
{
int V_13 ;
V_13 = ( F_2 ( V_2 , V_14 ) == 0xFF ) ;
F_3 ( V_2 , V_14 , 0 ) ;
return V_13 ;
}
static struct V_15 * F_9 ( void )
{
int V_16 ;
unsigned long V_17 ;
F_10 ( V_17 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
if ( V_19 [ V_16 ] . V_20 == V_21 ) {
V_19 [ V_16 ] . V_20 = V_22 ;
F_11 ( V_17 ) ;
return & V_19 [ V_16 ] ;
}
}
F_11 ( V_17 ) ;
return NULL ;
}
static void F_12 ( struct V_15 * V_23 )
{
V_23 -> V_20 = V_21 ;
}
void T_4 F_13 ( void )
{
if ( V_24 -> V_25 == V_26 ) {
if ( V_24 -> V_27 == V_28 ) {
V_29 [ V_30 ] = (struct V_1 * ) V_31 ;
} else {
V_29 [ V_30 ] = (struct V_1 * ) V_32 ;
}
V_29 [ V_30 ] -> V_8 = 0x87 ;
V_33 = 1 ;
} else {
V_29 [ V_30 ] = NULL ;
V_33 = 0 ;
}
if ( V_24 -> V_34 == V_35 ) {
if ( V_24 -> V_27 == V_28 ) {
V_29 [ V_36 ] = (struct V_1 * ) V_37 ;
} else {
V_29 [ V_36 ] = (struct V_1 * ) V_38 ;
}
V_29 [ V_36 ] -> V_8 = 0 ;
V_39 = 1 ;
} else {
V_29 [ V_36 ] = NULL ;
V_39 = 0 ;
}
}
void T_4 F_14 ( void )
{
int V_16 ;
if ( V_33 ) {
F_15 ( L_1 , V_29 [ V_30 ] ) ;
}
if ( V_39 ) {
F_15 ( L_2 , V_29 [ V_36 ] ) ;
F_5 ( V_29 [ V_36 ] ) ;
F_8 ( V_29 [ V_36 ] ) ;
}
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_19 [ V_16 ] . V_20 = V_21 ;
}
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ ) {
V_41 [ V_30 ] [ V_16 ] = NULL ;
V_41 [ V_36 ] [ V_16 ] = NULL ;
V_42 [ V_30 ] [ V_16 ] . V_43 = NULL ;
V_42 [ V_30 ] [ V_16 ] . V_44 = NULL ;
V_42 [ V_36 ] [ V_16 ] . V_43 = NULL ;
V_42 [ V_36 ] [ V_16 ] . V_44 = NULL ;
}
}
void T_4 F_16 ( void )
{
if ( V_39 ) {
if ( V_45 ) {
if ( F_17 ( V_46 , V_47 , 0 ,
L_3 , ( void * ) V_36 ) )
F_18 ( L_4 ) ;
F_19 ( V_48 ) ;
} else {
if ( F_17 ( V_49 , V_47 , 0 , L_3 ,
( void * ) V_36 ) )
F_18 ( L_4 ) ;
}
if ( ! F_8 ( V_29 [ V_36 ] ) ) {
F_15 ( L_5 ) ;
} else {
F_15 ( L_6 ) ;
}
}
}
int F_20 ( T_5 V_50 , T_5 V_51 ,
void (* V_44)( struct V_15 * ) ,
const char * V_43 )
{
if ( ( V_50 >= V_52 ) || ! V_29 [ V_50 ] ) return - V_53 ;
if ( V_51 >= V_40 ) return - V_53 ;
if ( V_42 [ V_50 ] [ V_51 ] . V_44 && V_44 ) return - V_53 ;
V_42 [ V_50 ] [ V_51 ] . V_43 = V_43 ;
V_42 [ V_50 ] [ V_51 ] . V_44 = V_44 ;
return 0 ;
}
void F_21 ( struct V_15 * V_23 )
{
int V_50 = V_23 -> V_50 ;
int V_51 = V_23 -> V_54 ;
int V_16 , V_55 ;
#ifdef F_22
F_15 ( L_7 , V_23 , V_23 -> V_50 , V_23 -> V_54 ) ;
#endif
V_55 = V_56 + ( V_23 -> V_54 * V_57 ) ;
for ( V_16 = 0 ; V_16 < V_57 ; V_16 ++ , V_55 ++ ) {
F_3 ( V_29 [ V_50 ] , V_55 , V_23 -> V_58 [ V_16 ] ) ;
}
F_3 ( V_29 [ V_50 ] ,
V_59 + V_51 , V_60 ) ;
F_7 ( V_29 [ V_23 -> V_50 ] ) ;
F_12 ( V_23 ) ;
}
static void F_23 ( struct V_15 * V_23 )
{
volatile struct V_1 * V_2 = V_29 [ V_23 -> V_50 ] ;
int V_16 , V_55 ;
V_55 = V_61 + ( V_23 -> V_54 * V_57 ) ;
for ( V_16 = 0 ; V_16 < V_57 ; V_16 ++ , V_55 ++ ) {
F_3 ( V_2 , V_55 , V_23 -> V_62 [ V_16 ] ) ;
}
F_3 ( V_2 , V_63 + V_23 -> V_54 , V_64 ) ;
F_7 ( V_2 ) ;
}
static void F_24 ( T_5 V_50 , T_5 V_51 )
{
volatile struct V_1 * V_2 = V_29 [ V_50 ] ;
struct V_15 * V_23 , * V_65 ;
int V_16 , V_55 ;
#ifdef F_22
F_15 ( L_8 , V_50 , V_51 ) ;
#endif
F_3 ( V_2 , V_63 + V_51 , V_66 ) ;
if ( ! ( V_23 = V_41 [ V_50 ] [ V_51 ] ) ) return;
V_23 -> V_20 = V_67 ;
V_55 = V_61 + ( V_51 * V_57 ) ;
for ( V_16 = 0 ; V_16 < V_57 ; V_16 ++ , V_55 ++ ) {
V_23 -> V_58 [ V_16 ] = F_2 ( V_2 , V_55 ) ;
}
if ( V_23 -> V_44 ) (* V_23 -> V_44 )( V_23 ) ;
V_65 = V_23 ;
V_23 = V_23 -> V_68 ;
F_12 ( V_65 ) ;
V_41 [ V_50 ] [ V_51 ] = V_23 ;
if ( V_23 ) F_23 ( V_23 ) ;
}
static void F_25 ( T_5 V_50 , T_5 V_51 )
{
volatile struct V_1 * V_2 = V_29 [ V_50 ] ;
int V_16 , V_55 ;
struct V_15 * V_23 ;
#ifdef F_22
F_15 ( L_9 , V_50 , V_51 ) ;
#endif
V_23 = F_9 () ;
V_23 -> V_50 = V_50 ;
V_23 -> V_54 = V_51 ;
V_23 -> V_20 = V_69 ;
V_23 -> V_44 = V_42 [ V_50 ] [ V_51 ] . V_44 ;
V_55 = V_56 + ( V_51 * V_57 ) ;
for ( V_16 = 0 ; V_16 < V_57 ; V_16 ++ , V_55 ++ ) {
V_23 -> V_62 [ V_16 ] = F_2 ( V_2 , V_55 ) ;
}
F_3 ( V_2 , V_59 + V_51 , V_70 ) ;
if ( V_23 -> V_44 ) {
(* V_23 -> V_44 )( V_23 ) ;
} else {
#ifdef F_22
F_15 ( L_10 , V_50 , V_51 ) ;
F_15 ( L_11 ) ;
for ( V_16 = 0 ; V_16 < V_57 ; V_16 ++ ) {
F_15 ( L_12 , ( T_5 ) V_23 -> V_62 [ V_16 ] ) ;
}
F_15 ( L_13 ) ;
#endif
F_21 ( V_23 ) ;
}
}
int F_26 ( T_5 V_50 , T_5 V_51 , void * V_71 ,
T_5 V_72 , T_3 * V_73 ,
void (* V_44)( struct V_15 * ) )
{
struct V_15 * V_23 , * V_74 ;
if ( ( V_50 >= V_52 ) || ! V_29 [ V_50 ] ) return - V_53 ;
if ( V_51 >= V_40 ) return - V_53 ;
if ( V_72 > V_57 ) return - V_53 ;
V_23 = F_9 () ;
if ( ! V_23 ) return - V_75 ;
V_23 -> V_68 = NULL ;
V_23 -> V_20 = V_22 ;
V_23 -> V_50 = V_50 ;
V_23 -> V_54 = V_51 ;
V_23 -> V_76 = V_71 ;
memcpy ( V_23 -> V_62 , V_73 , V_72 ) ;
V_23 -> V_44 = V_44 ;
if ( ! ( V_74 = V_41 [ V_50 ] [ V_51 ] ) ) {
V_41 [ V_50 ] [ V_51 ] = V_23 ;
} else {
while ( V_74 -> V_68 ) V_74 = V_74 -> V_68 ;
V_74 -> V_68 = V_23 ;
}
if ( F_2 ( V_29 [ V_50 ] ,
V_63 + V_51 ) == V_66 ) {
F_23 ( V_23 ) ;
}
return 0 ;
}
void F_27 ( T_5 V_50 , T_3 * V_77 ,
T_5 V_78 , T_2 V_79 )
{
if ( ( V_50 >= V_52 ) || ! V_29 [ V_50 ] ) return;
F_1 ( V_29 [ V_50 ] , V_79 ) ;
while ( V_78 -- ) {
V_29 [ V_50 ] -> V_6 = * V_77 ++ ;
}
}
void F_28 ( T_5 V_50 , T_3 * V_77 ,
T_5 V_78 , T_2 V_79 )
{
if ( ( V_50 >= V_52 ) || ! V_29 [ V_50 ] ) return;
F_1 ( V_29 [ V_50 ] , V_79 ) ;
while ( V_78 -- ) {
* V_77 ++ = V_29 [ V_50 ] -> V_6 ;
}
}
T_3 * F_29 ( T_5 V_50 , T_3 * V_77 ,
T_5 V_78 , T_2 V_79 )
{
if ( ( V_50 >= V_52 ) || ! V_29 [ V_50 ] ) return V_77 ;
F_1 ( V_29 [ V_50 ] , V_79 ) ;
while ( V_78 -- ) {
if ( * V_77 != V_29 [ V_50 ] -> V_6 ) {
return V_77 ;
}
V_77 ++ ;
}
return ( T_3 * ) 0 ;
}
T_6 V_47 ( int V_80 , void * V_81 )
{
T_5 V_50 = ( T_5 ) V_81 ;
volatile struct V_1 * V_2 = V_29 [ V_50 ] ;
int V_16 , V_82 ;
#ifdef F_22
F_15 ( L_14 , ( T_5 ) V_2 -> V_8 ) ;
#endif
if ( V_2 -> V_8 & V_83 ) {
V_2 -> V_8 = V_83 | V_9 | V_10 ;
#ifdef F_22
F_15 ( L_15 ,
( T_5 ) V_2 -> V_8 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ ) {
V_82 = F_2 ( V_2 , V_63 + V_16 ) ;
#ifdef F_22
F_15 ( L_12 , V_82 ) ;
#endif
if ( V_82 == V_60 ) {
F_24 ( V_50 , V_16 ) ;
}
}
#ifdef F_22
F_15 ( L_13 ) ;
#endif
}
if ( V_2 -> V_8 & V_84 ) {
V_2 -> V_8 = V_84 | V_9 | V_10 ;
#ifdef F_22
F_15 ( L_16 ,
( T_5 ) V_2 -> V_8 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ ) {
V_82 = F_2 ( V_2 , V_59 + V_16 ) ;
#ifdef F_22
F_15 ( L_12 , V_82 ) ;
#endif
if ( V_82 == V_64 ) {
F_25 ( V_50 , V_16 ) ;
}
}
#ifdef F_22
F_15 ( L_13 ) ;
#endif
}
return V_85 ;
}
