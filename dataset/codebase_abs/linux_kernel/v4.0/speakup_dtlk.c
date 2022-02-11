static inline bool F_1 ( void )
{
V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
return ( V_1 & V_5 ) != 0 ;
}
static inline bool F_3 ( void )
{
V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
return ( V_1 & V_6 ) != 0 ;
}
static inline bool F_4 ( void )
{
V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
return ( V_1 & V_7 ) != 0 ;
}
static void F_5 ( const char V_8 )
{
int V_9 = V_10 ;
while ( ! F_3 () ) {
if ( ! -- V_9 )
break;
F_6 ( 1 ) ;
}
F_7 ( V_8 , V_2 . V_3 ) ;
V_9 = V_10 ;
while ( F_3 () ) {
if ( ! -- V_9 )
break;
F_6 ( 1 ) ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
T_1 V_8 ;
unsigned long V_13 ;
unsigned long V_14 ;
struct V_15 * V_16 ;
struct V_15 * V_17 ;
int V_18 ;
int V_19 ;
V_16 = F_9 ( V_20 ) ;
V_17 = F_9 ( V_21 ) ;
F_10 ( & V_2 . V_22 , V_13 ) ;
V_18 = V_16 -> V_23 . V_24 . V_25 ;
F_11 ( & V_2 . V_22 , V_13 ) ;
V_14 = V_26 + V_18 ;
while ( ! F_12 () ) {
F_10 ( & V_2 . V_22 , V_13 ) ;
if ( V_2 . V_27 ) {
V_2 . V_27 = 0 ;
F_11 ( & V_2 . V_22 , V_13 ) ;
V_12 -> V_28 ( V_12 ) ;
continue;
}
if ( F_13 () ) {
F_11 ( & V_2 . V_22 , V_13 ) ;
break;
}
F_14 ( V_29 ) ;
V_19 = V_17 -> V_23 . V_24 . V_25 ;
F_11 ( & V_2 . V_22 , V_13 ) ;
if ( F_4 () ) {
F_15 ( F_16 ( V_19 ) ) ;
continue;
}
F_14 ( V_30 ) ;
F_10 ( & V_2 . V_22 , V_13 ) ;
V_8 = F_17 () ;
F_11 ( & V_2 . V_22 , V_13 ) ;
if ( V_8 == '\n' )
V_8 = V_31 ;
F_5 ( V_8 ) ;
if ( F_18 ( V_26 , V_14 ) && ( V_8 == V_32 ) ) {
F_5 ( V_31 ) ;
F_10 ( & V_2 . V_22 , V_13 ) ;
V_19 = V_17 -> V_23 . V_24 . V_25 ;
V_18 = V_16 -> V_23 . V_24 . V_25 ;
F_11 ( & V_2 . V_22 , V_13 ) ;
F_15 ( F_16 ( V_19 ) ) ;
V_14 = V_26 + V_18 ;
}
}
F_5 ( V_31 ) ;
}
static const char * F_19 ( struct V_11 * V_12 , const char * V_33 )
{
T_1 V_8 ;
while ( ( V_8 = ( T_1 ) * V_33 ) ) {
if ( F_4 () )
return V_33 ;
if ( V_8 == '\n' )
V_8 = V_31 ;
F_5 ( V_8 ) ;
V_33 ++ ;
}
return NULL ;
}
static void F_20 ( struct V_11 * V_12 )
{
F_7 ( V_34 , V_2 . V_3 ) ;
while ( F_3 () )
F_21 () ;
}
static char F_22 ( void )
{
T_1 V_8 ;
while ( ! F_1 () )
F_21 () ;
V_8 = V_1 & 0x7f ;
F_7 ( V_8 , V_2 . V_3 ) ;
while ( F_1 () )
F_21 () ;
return ( char ) V_8 ;
}
static struct V_35 * F_23 ( struct V_11 * V_12 )
{
T_1 * V_36 ;
static char V_33 [ sizeof( struct V_35 ) + 1 ] ;
int V_37 , V_38 ;
static struct V_35 V_39 ;
F_19 ( V_12 , L_1 ) ;
for ( V_37 = 0 , V_38 = 0 ; V_38 < 50 ; V_38 ++ ) {
V_33 [ V_37 ] = F_22 () ;
if ( V_37 > 2 && V_33 [ V_37 ] == 0x7f )
break;
if ( V_37 < sizeof( struct V_35 ) )
V_37 ++ ;
}
V_36 = V_33 ;
V_39 . V_40 = V_36 [ 0 ] + V_36 [ 1 ] * 256 ;
V_36 += 2 ;
for ( V_38 = 0 ; * V_36 != '\r' ; V_36 ++ ) {
V_39 . V_41 [ V_38 ] = * V_36 ;
if ( V_38 < sizeof( V_39 . V_41 ) - 1 )
V_38 ++ ;
}
V_39 . V_41 [ V_38 ] = 0 ;
V_36 ++ ;
V_39 . V_42 = * V_36 ++ ;
V_39 . V_43 = * V_36 ++ ;
V_39 . V_44 = * V_36 ++ ;
V_39 . V_45 = * V_36 ++ ;
V_39 . V_46 = * V_36 ++ ;
V_39 . V_47 = * V_36 ++ ;
V_39 . V_48 = * V_36 ++ ;
V_39 . V_49 = * V_36 ++ ;
V_39 . V_50 = * V_36 ++ ;
V_39 . V_51 = * V_36 ++ ;
V_39 . V_52 = * V_36 ++ ;
V_39 . V_53 = * V_36 ++ ;
V_39 . V_54 = * V_36 ++ ;
V_39 . V_55 = * V_36 ++ ;
return & V_39 ;
}
static int F_24 ( struct V_11 * V_12 )
{
unsigned int V_56 = 0 ;
int V_38 = 0 ;
struct V_35 * V_57 ;
F_25 ( L_2 ) ;
if ( V_58 ) {
V_2 . V_3 = V_58 ;
F_25 ( L_3 ,
V_2 . V_3 ) ;
if ( ( V_58 & 0xf ) != 0xf )
F_25 ( L_4 ) ;
if ( F_26 ( V_2 . V_3 - 1 ,
V_59 ) ) {
F_27 ( L_5 ) ;
return - V_60 ;
}
V_56 = F_28 ( V_2 . V_3 - 1 ) ;
V_61 = V_2 . V_3 - 1 ;
} else {
for ( V_38 = 0 ; V_62 [ V_38 ] ; V_38 ++ ) {
if ( F_26 ( V_62 [ V_38 ] ,
V_59 ) )
continue;
V_56 = F_28 ( V_62 [ V_38 ] ) & 0xfbff ;
if ( V_56 == 0x107f ) {
V_61 = V_62 [ V_38 ] ;
V_2 . V_3 = V_61 + 1 ;
break;
}
F_29 ( V_62 [ V_38 ] ,
V_59 ) ;
}
}
V_56 &= 0xfbff ;
if ( V_56 != 0x107f ) {
F_25 ( L_6 ) ;
if ( V_61 )
F_29 ( V_61 , V_59 ) ;
return - V_63 ;
}
while ( F_30 ( V_61 ) != 0x147f )
F_21 () ;
V_57 = F_23 ( V_12 ) ;
F_25 ( L_7 ,
V_12 -> V_64 , V_61 , V_61 + V_59 - 1 ,
V_57 -> V_41 , V_57 -> V_40 , V_12 -> V_65 ) ;
V_12 -> V_66 = 1 ;
return 0 ;
}
static void F_31 ( void )
{
if ( V_2 . V_3 )
F_29 ( V_2 . V_3 - 1 , V_59 ) ;
V_2 . V_3 = 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_67 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_67 ) ;
}
