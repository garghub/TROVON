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
static void F_11 ( struct V_11 * V_12 )
{
}
static void F_12 ( struct V_11 * V_12 , int V_18 )
{
}
static void F_13 ( struct V_11 * V_12 )
{
int V_19 ;
struct V_20 * V_21 = & V_12 -> V_22 -> V_21 ;
if( V_12 -> V_23 ) {
F_14 ( V_12 , V_12 -> V_23 ) ;
V_12 -> V_24 . V_25 ++ ;
V_12 -> V_23 = 0 ;
return;
}
if( F_15 ( V_21 ) || F_16 ( V_12 ) ) {
F_8 ( V_12 ) ;
return;
}
V_19 = ( V_12 -> V_26 ) - F_5 ( V_12 ) ;
do {
F_14 ( V_12 , V_21 -> V_27 [ V_21 -> V_28 ] ) ;
V_21 -> V_28 = ( V_21 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_12 -> V_24 . V_25 ++ ;
if( F_15 ( V_21 ) )
break;
} while( -- V_19 > 0 );
while( F_5 ( V_12 ) )
F_17 ( 1 ) ;
if( F_18 ( V_21 ) < V_30 )
F_19 ( V_12 ) ;
if ( F_15 ( V_21 ) )
F_8 ( V_12 ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
int V_31 ;
struct V_32 * V_33 = V_12 -> V_22 -> V_12 . V_33 ;
T_3 V_34 = V_12 -> V_24 . V_35 ;
while( 1 ) {
V_31 = F_21 ( V_12 -> V_36 + V_37 ) ;
if ( F_22 ( V_31 ) )
continue;
if ( F_23 ( V_31 ) )
break;
V_12 -> V_24 . V_35 ++ ;
if ( F_24 ( V_31 ) ) {
V_12 -> V_24 . V_38 ++ ;
if( F_25 ( V_12 ) )
continue;
}
if ( F_26 ( V_12 , V_31 & 0xffu ) )
continue;
F_27 ( V_33 , V_31 & 0xFF , V_39 ) ;
}
if ( V_34 != V_12 -> V_24 . V_35 ) {
F_28 ( V_33 ) ;
}
}
static int F_29 ( struct V_11 * V_12 )
{
V_40 [ V_12 -> line ] . V_41 = 1 ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 )
{
V_40 [ V_12 -> line ] . V_41 = 0 ;
}
static void
F_31 ( struct V_11 * V_12 , struct V_42 * V_43 ,
struct V_42 * V_44 )
{
}
static const char * F_32 ( struct V_11 * V_12 )
{
return L_1 ;
}
static void F_33 ( struct V_11 * V_12 )
{
}
static int F_34 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_35 ( struct V_11 * V_12 , int type )
{
V_12 -> type = V_45 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_46 * V_47 )
{
if( V_12 -> V_36 == NULL )
return - V_48 ;
return 0 ;
}
static void F_37 ( unsigned long V_49 )
{
int V_50 ;
for( V_50 = 0 ; V_50 < V_51 ; ++ V_50 ) {
if( ! V_40 [ V_50 ] . V_41 )
continue;
F_20 ( & V_40 [ V_50 ] . V_12 ) ;
F_13 ( & V_40 [ V_50 ] . V_12 ) ;
}
F_38 ( & V_52 , V_53 + V_54 ) ;
}
static void F_39 ( struct V_55 * V_56 , const char * V_57 , unsigned V_19 )
{
while( F_5 ( & V_40 [ 0 ] . V_12 ) )
F_17 ( 1 ) ;
while( V_19 -- ) {
if( * V_57 == '\n' ) {
F_14 ( & V_40 [ 0 ] . V_12 , '\r' ) ;
}
F_14 ( & V_40 [ 0 ] . V_12 , * V_57 ++ ) ;
}
}
static int F_40 ( struct V_55 * V_56 , char * V_58 )
{
return 0 ;
}
struct V_59 * F_41 ( struct V_55 * V_56 , int * V_60 )
{
* V_60 = V_56 -> V_60 ;
return V_61 . V_59 ;
}
static int T_1 F_42 ( struct V_1 * V_2 )
{
int V_50 , V_3 ;
int V_62 = F_1 ( V_2 ) ;
F_43 ( V_63 L_2 , V_62 ) ;
F_44 ( & V_2 -> V_2 , ( void * ) ( long ) V_62 ) ;
F_45 ( V_2 -> V_8 . V_9 + V_64 ,
V_62 * V_65 , L_1 ) ;
if( ! V_51 ) {
V_61 . V_66 = V_67 ;
V_3 = F_46 ( & V_61 ) ;
if( V_3 ) {
F_43 ( V_68 L_3 ) ;
return 1 ;
}
}
for( V_50 = 0 ; V_50 < V_62 ; ++ V_50 , ++ V_51 ) {
struct V_11 * V_12 = & V_40 [ V_51 ] . V_12 ;
V_12 -> V_69 = 0 ;
V_12 -> V_70 = V_2 -> V_8 . V_9 + V_64 +
( V_50 * V_65 ) ;
V_12 -> V_36 = F_47 ( V_12 -> V_70 , V_65 ) ;
V_12 -> V_71 = V_72 ;
V_12 -> type = V_45 ;
V_12 -> V_73 = 0 ;
V_12 -> V_74 = 0 ;
V_12 -> V_26 = V_75 ;
V_12 -> V_76 = & V_77 ;
V_12 -> V_78 = V_79 ;
V_12 -> line = V_51 ;
V_12 -> V_80 = V_81 / 50 ;
F_48 ( & V_12 -> V_82 ) ;
V_3 = F_49 ( & V_61 , V_12 ) ;
F_3 ( V_3 ) ;
}
return 0 ;
}
static int T_4 F_50 ( struct V_1 * V_2 )
{
int V_50 , V_83 ;
int V_62 = ( long ) F_51 ( & V_2 -> V_2 ) ;
for( V_50 = 0 ; V_50 < V_51 ; ++ V_50 ) {
if( V_40 [ V_50 ] . V_12 . V_70 == V_2 -> V_8 . V_9 + V_64 )
break;
}
F_3 ( V_50 + V_62 > V_51 ) ;
for( V_83 = 0 ; V_83 < V_62 ; ++ V_83 , ++ V_50 ) {
struct V_11 * V_12 = & V_40 [ V_50 ] . V_12 ;
F_52 ( & V_61 , V_12 ) ;
if( V_12 -> V_36 )
F_53 ( V_12 -> V_36 ) ;
}
F_54 ( V_2 -> V_8 . V_9 + V_64 , V_62 * V_65 ) ;
return 0 ;
}
static int T_1 F_55 ( void )
{
F_56 ( & V_84 ) ;
F_56 ( & V_85 ) ;
if( V_51 > 0 ) {
F_57 ( & V_52 ) ;
V_52 . V_86 = F_37 ;
F_38 ( & V_52 , V_53 + V_54 ) ;
#ifdef F_58
F_59 ( & V_87 ) ;
#endif
}
return 0 ;
}
static void T_5 F_60 ( void )
{
if( V_51 > 0 ) {
F_61 ( & V_52 ) ;
#ifdef F_58
F_62 ( & V_87 ) ;
#endif
}
F_63 ( & V_84 ) ;
F_63 ( & V_85 ) ;
F_64 ( & V_61 ) ;
}
