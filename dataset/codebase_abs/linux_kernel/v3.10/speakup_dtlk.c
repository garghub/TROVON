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
F_10 ( V_13 ) ;
V_18 = V_16 -> V_22 . V_23 . V_24 ;
F_11 ( V_13 ) ;
V_14 = V_25 + V_18 ;
while ( ! F_12 () ) {
F_10 ( V_13 ) ;
if ( V_2 . V_26 ) {
V_2 . V_26 = 0 ;
F_11 ( V_13 ) ;
V_12 -> V_27 ( V_12 ) ;
continue;
}
if ( F_13 () ) {
F_11 ( V_13 ) ;
break;
}
F_14 ( V_28 ) ;
V_19 = V_17 -> V_22 . V_23 . V_24 ;
F_11 ( V_13 ) ;
if ( F_4 () ) {
F_15 ( F_16 ( V_19 ) ) ;
continue;
}
F_14 ( V_29 ) ;
F_10 ( V_13 ) ;
V_8 = F_17 () ;
F_11 ( V_13 ) ;
if ( V_8 == '\n' )
V_8 = V_30 ;
F_5 ( V_8 ) ;
if ( ( V_25 >= V_14 ) && ( V_8 == V_31 ) ) {
F_5 ( V_30 ) ;
F_10 ( V_13 ) ;
V_19 = V_17 -> V_22 . V_23 . V_24 ;
V_18 = V_16 -> V_22 . V_23 . V_24 ;
F_11 ( V_13 ) ;
F_15 ( F_16 ( V_19 ) ) ;
V_14 = V_25 + V_18 ;
}
}
F_5 ( V_30 ) ;
}
static const char * F_18 ( struct V_11 * V_12 , const char * V_32 )
{
T_1 V_8 ;
while ( ( V_8 = ( T_1 ) * V_32 ) ) {
if ( F_4 () )
return V_32 ;
if ( V_8 == '\n' )
V_8 = V_30 ;
F_5 ( V_8 ) ;
V_32 ++ ;
}
return 0 ;
}
static void F_19 ( struct V_11 * V_12 )
{
F_7 ( V_33 , V_2 . V_3 ) ;
while ( F_3 () )
F_20 () ;
}
static char F_21 ( void )
{
T_1 V_8 ;
while ( ! F_1 () )
F_20 () ;
V_8 = V_1 & 0x7f ;
F_7 ( V_8 , V_2 . V_3 ) ;
while ( F_1 () )
F_20 () ;
return ( char ) V_8 ;
}
static struct V_34 * F_22 ( struct V_11 * V_12 )
{
T_1 * V_35 ;
static char V_32 [ sizeof( struct V_34 ) + 1 ] ;
int V_36 , V_37 ;
static struct V_34 V_38 ;
F_18 ( V_12 , L_1 ) ;
for ( V_36 = 0 , V_37 = 0 ; V_37 < 50 ; V_37 ++ ) {
V_32 [ V_36 ] = F_21 () ;
if ( V_36 > 2 && V_32 [ V_36 ] == 0x7f )
break;
if ( V_36 < sizeof( struct V_34 ) )
V_36 ++ ;
}
V_35 = V_32 ;
V_38 . V_39 = V_35 [ 0 ] + V_35 [ 1 ] * 256 ;
V_35 += 2 ;
for ( V_37 = 0 ; * V_35 != '\r' ; V_35 ++ ) {
V_38 . V_40 [ V_37 ] = * V_35 ;
if ( V_37 < sizeof( V_38 . V_40 ) - 1 )
V_37 ++ ;
}
V_38 . V_40 [ V_37 ] = 0 ;
V_35 ++ ;
V_38 . V_41 = * V_35 ++ ;
V_38 . V_42 = * V_35 ++ ;
V_38 . V_43 = * V_35 ++ ;
V_38 . V_44 = * V_35 ++ ;
V_38 . V_45 = * V_35 ++ ;
V_38 . V_46 = * V_35 ++ ;
V_38 . V_47 = * V_35 ++ ;
V_38 . V_48 = * V_35 ++ ;
V_38 . V_49 = * V_35 ++ ;
V_38 . V_50 = * V_35 ++ ;
V_38 . V_51 = * V_35 ++ ;
V_38 . V_52 = * V_35 ++ ;
V_38 . V_53 = * V_35 ++ ;
V_38 . V_54 = * V_35 ++ ;
return & V_38 ;
}
static int F_23 ( struct V_11 * V_12 )
{
unsigned int V_55 = 0 ;
int V_37 = 0 ;
struct V_34 * V_56 ;
F_24 ( L_2 ) ;
if ( V_57 ) {
V_2 . V_3 = V_57 ;
F_24 ( L_3 ,
V_2 . V_3 ) ;
if ( ( V_57 & 0xf ) != 0xf )
F_24 ( L_4 ) ;
if ( F_25 ( V_2 . V_3 - 1 ,
V_58 ) ) {
F_26 ( L_5 ) ;
return - V_59 ;
}
V_55 = F_27 ( V_2 . V_3 - 1 ) ;
V_60 = V_2 . V_3 - 1 ;
} else {
for ( V_37 = 0 ; V_61 [ V_37 ] ; V_37 ++ ) {
if ( F_25 ( V_61 [ V_37 ] ,
V_58 ) )
continue;
V_55 = F_27 ( V_61 [ V_37 ] ) & 0xfbff ;
if ( V_55 == 0x107f ) {
V_60 = V_61 [ V_37 ] ;
V_2 . V_3 = V_60 + 1 ;
break;
}
F_28 ( V_61 [ V_37 ] ,
V_58 ) ;
}
}
V_55 &= 0xfbff ;
if ( V_55 != 0x107f ) {
F_24 ( L_6 ) ;
F_28 ( V_60 , V_58 ) ;
return - V_62 ;
}
while ( F_29 ( V_60 ) != 0x147f )
F_20 () ;
V_56 = F_22 ( V_12 ) ;
F_24 ( L_7 ,
V_12 -> V_63 , V_60 , V_60 + V_58 - 1 ,
V_56 -> V_40 , V_56 -> V_39 , V_12 -> V_64 ) ;
V_12 -> V_65 = 1 ;
return 0 ;
}
static void F_30 ( void )
{
if ( V_2 . V_3 )
F_28 ( V_2 . V_3 - 1 , V_58 ) ;
V_2 . V_3 = 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_66 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_66 ) ;
}
