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
if ( F_17 ( V_46 , V_47 ,
V_48 , L_3 ,
( void * ) V_36 ) )
F_18 ( L_4 ) ;
F_19 ( V_49 ) ;
} else {
if ( F_17 ( V_50 , V_47 ,
V_48 | V_51 , L_3 ,
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
int F_20 ( T_5 V_52 , T_5 V_53 ,
void (* V_44)( struct V_15 * ) ,
const char * V_43 )
{
if ( ( V_52 >= V_54 ) || ! V_29 [ V_52 ] ) return - V_55 ;
if ( V_53 >= V_40 ) return - V_55 ;
if ( V_42 [ V_52 ] [ V_53 ] . V_44 && V_44 ) return - V_55 ;
V_42 [ V_52 ] [ V_53 ] . V_43 = V_43 ;
V_42 [ V_52 ] [ V_53 ] . V_44 = V_44 ;
return 0 ;
}
void F_21 ( struct V_15 * V_23 )
{
int V_52 = V_23 -> V_52 ;
int V_53 = V_23 -> V_56 ;
int V_16 , V_57 ;
#ifdef F_22
F_15 ( L_7 , V_23 , V_23 -> V_52 , V_23 -> V_56 ) ;
#endif
V_57 = V_58 + ( V_23 -> V_56 * V_59 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ , V_57 ++ ) {
F_3 ( V_29 [ V_52 ] , V_57 , V_23 -> V_60 [ V_16 ] ) ;
}
F_3 ( V_29 [ V_52 ] ,
V_61 + V_53 , V_62 ) ;
F_7 ( V_29 [ V_23 -> V_52 ] ) ;
F_12 ( V_23 ) ;
}
static void F_23 ( struct V_15 * V_23 )
{
volatile struct V_1 * V_2 = V_29 [ V_23 -> V_52 ] ;
int V_16 , V_57 ;
V_57 = V_63 + ( V_23 -> V_56 * V_59 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ , V_57 ++ ) {
F_3 ( V_2 , V_57 , V_23 -> V_64 [ V_16 ] ) ;
}
F_3 ( V_2 , V_65 + V_23 -> V_56 , V_66 ) ;
F_7 ( V_2 ) ;
}
static void F_24 ( T_5 V_52 , T_5 V_53 )
{
volatile struct V_1 * V_2 = V_29 [ V_52 ] ;
struct V_15 * V_23 , * V_67 ;
int V_16 , V_57 ;
#ifdef F_22
F_15 ( L_8 , V_52 , V_53 ) ;
#endif
F_3 ( V_2 , V_65 + V_53 , V_68 ) ;
if ( ! ( V_23 = V_41 [ V_52 ] [ V_53 ] ) ) return;
V_23 -> V_20 = V_69 ;
V_57 = V_63 + ( V_53 * V_59 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ , V_57 ++ ) {
V_23 -> V_60 [ V_16 ] = F_2 ( V_2 , V_57 ) ;
}
if ( V_23 -> V_44 ) (* V_23 -> V_44 )( V_23 ) ;
V_67 = V_23 ;
V_23 = V_23 -> V_70 ;
F_12 ( V_67 ) ;
V_41 [ V_52 ] [ V_53 ] = V_23 ;
if ( V_23 ) F_23 ( V_23 ) ;
}
static void F_25 ( T_5 V_52 , T_5 V_53 )
{
volatile struct V_1 * V_2 = V_29 [ V_52 ] ;
int V_16 , V_57 ;
struct V_15 * V_23 ;
#ifdef F_22
F_15 ( L_9 , V_52 , V_53 ) ;
#endif
V_23 = F_9 () ;
V_23 -> V_52 = V_52 ;
V_23 -> V_56 = V_53 ;
V_23 -> V_20 = V_71 ;
V_23 -> V_44 = V_42 [ V_52 ] [ V_53 ] . V_44 ;
V_57 = V_58 + ( V_53 * V_59 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ , V_57 ++ ) {
V_23 -> V_64 [ V_16 ] = F_2 ( V_2 , V_57 ) ;
}
F_3 ( V_2 , V_61 + V_53 , V_72 ) ;
if ( V_23 -> V_44 ) {
(* V_23 -> V_44 )( V_23 ) ;
} else {
#ifdef F_22
F_15 ( L_10 , V_52 , V_53 ) ;
F_15 ( L_11 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ ) {
F_15 ( L_12 , ( T_5 ) V_23 -> V_64 [ V_16 ] ) ;
}
F_15 ( L_13 ) ;
#endif
F_21 ( V_23 ) ;
}
}
int F_26 ( T_5 V_52 , T_5 V_53 , void * V_73 ,
T_5 V_74 , T_3 * V_75 ,
void (* V_44)( struct V_15 * ) )
{
struct V_15 * V_23 , * V_76 ;
if ( ( V_52 >= V_54 ) || ! V_29 [ V_52 ] ) return - V_55 ;
if ( V_53 >= V_40 ) return - V_55 ;
if ( V_74 > V_59 ) return - V_55 ;
V_23 = F_9 () ;
if ( ! V_23 ) return - V_77 ;
V_23 -> V_70 = NULL ;
V_23 -> V_20 = V_22 ;
V_23 -> V_52 = V_52 ;
V_23 -> V_56 = V_53 ;
V_23 -> V_78 = V_73 ;
memcpy ( V_23 -> V_64 , V_75 , V_74 ) ;
V_23 -> V_44 = V_44 ;
if ( ! ( V_76 = V_41 [ V_52 ] [ V_53 ] ) ) {
V_41 [ V_52 ] [ V_53 ] = V_23 ;
} else {
while ( V_76 -> V_70 ) V_76 = V_76 -> V_70 ;
V_76 -> V_70 = V_23 ;
}
if ( F_2 ( V_29 [ V_52 ] ,
V_65 + V_53 ) == V_68 ) {
F_23 ( V_23 ) ;
}
return 0 ;
}
void F_27 ( T_5 V_52 , T_3 * V_79 ,
T_5 V_80 , T_2 V_81 )
{
if ( ( V_52 >= V_54 ) || ! V_29 [ V_52 ] ) return;
F_1 ( V_29 [ V_52 ] , V_81 ) ;
while ( V_80 -- ) {
V_29 [ V_52 ] -> V_6 = * V_79 ++ ;
}
}
void F_28 ( T_5 V_52 , T_3 * V_79 ,
T_5 V_80 , T_2 V_81 )
{
if ( ( V_52 >= V_54 ) || ! V_29 [ V_52 ] ) return;
F_1 ( V_29 [ V_52 ] , V_81 ) ;
while ( V_80 -- ) {
* V_79 ++ = V_29 [ V_52 ] -> V_6 ;
}
}
T_3 * F_29 ( T_5 V_52 , T_3 * V_79 ,
T_5 V_80 , T_2 V_81 )
{
if ( ( V_52 >= V_54 ) || ! V_29 [ V_52 ] ) return V_79 ;
F_1 ( V_29 [ V_52 ] , V_81 ) ;
while ( V_80 -- ) {
if ( * V_79 != V_29 [ V_52 ] -> V_6 ) {
return V_79 ;
}
V_79 ++ ;
}
return ( T_3 * ) 0 ;
}
T_6 V_47 ( int V_82 , void * V_83 )
{
T_5 V_52 = ( T_5 ) V_83 ;
volatile struct V_1 * V_2 = V_29 [ V_52 ] ;
int V_16 , V_84 ;
#ifdef F_22
F_15 ( L_14 , ( T_5 ) V_2 -> V_8 ) ;
#endif
if ( V_2 -> V_8 & V_85 ) {
V_2 -> V_8 = V_85 | V_9 | V_10 ;
#ifdef F_22
F_15 ( L_15 ,
( T_5 ) V_2 -> V_8 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ ) {
V_84 = F_2 ( V_2 , V_65 + V_16 ) ;
#ifdef F_22
F_15 ( L_12 , V_84 ) ;
#endif
if ( V_84 == V_62 ) {
F_24 ( V_52 , V_16 ) ;
}
}
#ifdef F_22
F_15 ( L_13 ) ;
#endif
}
if ( V_2 -> V_8 & V_86 ) {
V_2 -> V_8 = V_86 | V_9 | V_10 ;
#ifdef F_22
F_15 ( L_16 ,
( T_5 ) V_2 -> V_8 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ ) {
V_84 = F_2 ( V_2 , V_61 + V_16 ) ;
#ifdef F_22
F_15 ( L_12 , V_84 ) ;
#endif
if ( V_84 == V_66 ) {
F_25 ( V_52 , V_16 ) ;
}
}
#ifdef F_22
F_15 ( L_13 ) ;
#endif
}
return V_87 ;
}
