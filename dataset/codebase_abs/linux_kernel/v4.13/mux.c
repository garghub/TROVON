static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_4 [ 32 ] ;
unsigned long V_5 ;
if( V_2 -> V_6 . V_7 == 0x15 )
return 1 ;
V_3 = F_2 ( & V_5 , V_2 -> V_8 . V_9 , 0 , V_4 , 32 ) ;
F_3 ( V_3 != V_10 ) ;
return ( ( ( ( V_4 ) [ 4 ] & 0xf0 ) >> 4 ) * 8 ) + 8 ;
}
static unsigned int F_4 ( struct V_11 * V_12 )
{
return F_5 ( V_12 ) ? 0 : V_13 ;
}
static void F_6 ( struct V_11 * V_12 , unsigned int V_14 )
{
}
static unsigned int F_7 ( struct V_11 * V_12 )
{
return V_15 | V_16 | V_17 ;
}
static void F_8 ( struct V_11 * V_12 )
{
}
static void F_9 ( struct V_11 * V_12 )
{
}
static void F_10 ( struct V_11 * V_12 )
{
}
static void F_11 ( struct V_11 * V_12 , int V_18 )
{
}
static void F_12 ( struct V_11 * V_12 )
{
int V_19 ;
struct V_20 * V_21 = & V_12 -> V_22 -> V_21 ;
if( V_12 -> V_23 ) {
F_13 ( V_12 , V_12 -> V_23 ) ;
V_12 -> V_24 . V_25 ++ ;
V_12 -> V_23 = 0 ;
return;
}
if( F_14 ( V_21 ) || F_15 ( V_12 ) ) {
F_8 ( V_12 ) ;
return;
}
V_19 = ( V_12 -> V_26 ) - F_5 ( V_12 ) ;
do {
F_13 ( V_12 , V_21 -> V_27 [ V_21 -> V_28 ] ) ;
V_21 -> V_28 = ( V_21 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_12 -> V_24 . V_25 ++ ;
if( F_14 ( V_21 ) )
break;
} while( -- V_19 > 0 );
while( F_5 ( V_12 ) )
F_16 ( 1 ) ;
if( F_17 ( V_21 ) < V_30 )
F_18 ( V_12 ) ;
if ( F_14 ( V_21 ) )
F_8 ( V_12 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_31 * V_32 = & V_12 -> V_22 -> V_12 ;
int V_33 ;
T_3 V_34 = V_12 -> V_24 . V_35 ;
while( 1 ) {
V_33 = F_20 ( V_12 -> V_36 + V_37 ) ;
if ( F_21 ( V_33 ) )
continue;
if ( F_22 ( V_33 ) )
break;
V_12 -> V_24 . V_35 ++ ;
if ( F_23 ( V_33 ) ) {
V_12 -> V_24 . V_38 ++ ;
if( F_24 ( V_12 ) )
continue;
}
if ( F_25 ( V_12 , V_33 & 0xffu ) )
continue;
F_26 ( V_32 , V_33 & 0xFF , V_39 ) ;
}
if ( V_34 != V_12 -> V_24 . V_35 )
F_27 ( V_32 ) ;
}
static int F_28 ( struct V_11 * V_12 )
{
V_40 [ V_12 -> line ] . V_41 = 1 ;
return 0 ;
}
static void F_29 ( struct V_11 * V_12 )
{
V_40 [ V_12 -> line ] . V_41 = 0 ;
}
static void
F_30 ( struct V_11 * V_12 , struct V_42 * V_43 ,
struct V_42 * V_44 )
{
}
static const char * F_31 ( struct V_11 * V_12 )
{
return L_1 ;
}
static void F_32 ( struct V_11 * V_12 )
{
}
static int F_33 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_34 ( struct V_11 * V_12 , int type )
{
V_12 -> type = V_45 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_46 * V_47 )
{
if( V_12 -> V_36 == NULL )
return - V_48 ;
return 0 ;
}
static void F_36 ( unsigned long V_49 )
{
int V_50 ;
for( V_50 = 0 ; V_50 < V_51 ; ++ V_50 ) {
if( ! V_40 [ V_50 ] . V_41 )
continue;
F_19 ( & V_40 [ V_50 ] . V_12 ) ;
F_12 ( & V_40 [ V_50 ] . V_12 ) ;
}
F_37 ( & V_52 , V_53 + V_54 ) ;
}
static void F_38 ( struct V_55 * V_56 , const char * V_57 , unsigned V_19 )
{
while( F_5 ( & V_40 [ 0 ] . V_12 ) )
F_16 ( 1 ) ;
while( V_19 -- ) {
if( * V_57 == '\n' ) {
F_13 ( & V_40 [ 0 ] . V_12 , '\r' ) ;
}
F_13 ( & V_40 [ 0 ] . V_12 , * V_57 ++ ) ;
}
}
static int F_39 ( struct V_55 * V_56 , char * V_58 )
{
return 0 ;
}
static int T_1 F_40 ( struct V_1 * V_2 )
{
int V_50 , V_3 ;
int V_59 = F_1 ( V_2 ) ;
F_41 ( V_60 L_2 , V_59 ) ;
F_42 ( & V_2 -> V_2 , ( void * ) ( long ) V_59 ) ;
F_43 ( V_2 -> V_8 . V_9 + V_61 ,
V_59 * V_62 , L_1 ) ;
if( ! V_51 ) {
V_63 . V_64 = V_65 ;
V_3 = F_44 ( & V_63 ) ;
if( V_3 ) {
F_41 ( V_66 L_3 ) ;
return 1 ;
}
}
for( V_50 = 0 ; V_50 < V_59 ; ++ V_50 , ++ V_51 ) {
struct V_11 * V_12 = & V_40 [ V_51 ] . V_12 ;
V_12 -> V_67 = 0 ;
V_12 -> V_68 = V_2 -> V_8 . V_9 + V_61 +
( V_50 * V_62 ) ;
V_12 -> V_36 = F_45 ( V_12 -> V_68 , V_62 ) ;
V_12 -> V_69 = V_70 ;
V_12 -> type = V_45 ;
V_12 -> V_71 = 0 ;
V_12 -> V_72 = 0 ;
V_12 -> V_26 = V_73 ;
V_12 -> V_74 = & V_75 ;
V_12 -> V_76 = V_77 ;
V_12 -> line = V_51 ;
V_12 -> V_78 = V_79 / 50 ;
F_46 ( & V_12 -> V_80 ) ;
V_3 = F_47 ( & V_63 , V_12 ) ;
F_3 ( V_3 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_50 , V_81 ;
int V_59 = ( long ) F_49 ( & V_2 -> V_2 ) ;
for( V_50 = 0 ; V_50 < V_51 ; ++ V_50 ) {
if( V_40 [ V_50 ] . V_12 . V_68 == V_2 -> V_8 . V_9 + V_61 )
break;
}
F_3 ( V_50 + V_59 > V_51 ) ;
for( V_81 = 0 ; V_81 < V_59 ; ++ V_81 , ++ V_50 ) {
struct V_11 * V_12 = & V_40 [ V_50 ] . V_12 ;
F_50 ( & V_63 , V_12 ) ;
if( V_12 -> V_36 )
F_51 ( V_12 -> V_36 ) ;
}
F_52 ( V_2 -> V_8 . V_9 + V_61 , V_59 * V_62 ) ;
return 0 ;
}
static int T_1 F_53 ( void )
{
F_54 ( & V_82 ) ;
F_54 ( & V_83 ) ;
if( V_51 > 0 ) {
F_55 ( & V_52 ) ;
V_52 . V_84 = F_36 ;
F_37 ( & V_52 , V_53 + V_54 ) ;
#ifdef F_56
F_57 ( & V_85 ) ;
#endif
}
return 0 ;
}
static void T_4 F_58 ( void )
{
if( V_51 > 0 ) {
F_59 ( & V_52 ) ;
#ifdef F_56
F_60 ( & V_85 ) ;
#endif
}
F_61 ( & V_82 ) ;
F_61 ( & V_83 ) ;
F_62 ( & V_63 ) ;
}
