void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
}
int F_3 ( T_1 V_13 , const char * * V_14 )
{
T_1 V_15 = V_13 & ~ V_16 ;
if ( F_4 ( V_14 ) ) {
long V_17 , V_18 ;
T_1 V_19 ;
if ( V_15 )
V_19 = V_15 ;
else
V_19 = V_13 ;
V_17 = F_5 ( V_19 ) - 1 ;
V_18 = F_6 ( V_20 ) - 1 ;
V_17 = F_7 ( V_17 , V_18 ) ;
* V_14 = V_20 [ V_17 ] ;
}
if ( V_15 )
return 0 ;
return 1 ;
}
void F_8 ( struct V_21 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_24 . V_25 ;
int V_26 ;
T_1 V_27 ;
if ( ! F_9 () )
return;
V_27 = V_21 -> V_24 . V_28 . V_29 . V_27 ;
if ( ( V_27 & V_16 ) == V_16 )
return;
if ( ! ( V_27 & V_30 ) ) {
V_23 -> V_31 = 0x37f ;
V_23 -> V_32 = 0 ;
V_23 -> V_33 = 0 ;
V_23 -> V_34 = 0 ;
V_23 -> V_35 = 0 ;
V_23 -> V_36 = 0 ;
memset ( & V_23 -> V_37 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_27 & V_38 ) )
memset ( & V_23 -> V_39 [ 0 ] , 0 , 256 ) ;
V_26 = 0x2 ;
V_27 = ( V_16 & ~ V_27 ) >> 2 ;
while ( V_27 ) {
if ( V_27 & 0x1 ) {
int V_40 = V_41 [ V_26 ] ;
int V_42 = V_43 [ V_26 ] ;
memcpy ( ( void * ) V_23 + V_40 ,
( void * ) & V_44 . V_28 + V_40 ,
V_42 ) ;
}
V_27 >>= 1 ;
V_26 ++ ;
}
}
void F_10 ( void )
{
if ( ! V_45 || ! V_16 )
return;
F_11 ( V_46 ) ;
F_12 ( V_47 , V_16 ) ;
}
static int F_13 ( enum V_48 V_48 )
{
return ! ! ( V_16 & ( 1UL << V_48 ) ) ;
}
static void T_2 F_14 ( void )
{
T_3 V_49 , V_50 , V_51 , V_52 , V_53 ;
unsigned int V_54 = F_15 ( struct V_55 ,
V_56 ) ;
for ( V_53 = V_57 ; V_53 < V_58 ; V_53 ++ ) {
if ( ! F_13 ( V_53 ) )
continue;
F_16 ( V_59 , V_53 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_41 [ V_53 ] = V_50 ;
V_43 [ V_53 ] = V_49 ;
F_17 ( V_54 > V_41 [ V_53 ] ,
L_1 , V_54 ) ;
V_54 = V_41 [ V_53 ] ;
F_18 ( V_60 L_2 , V_53 , V_50 , V_53 , V_49 ) ;
}
}
static void T_2 F_19 ( T_1 V_61 )
{
const char * V_14 ;
if ( F_3 ( V_61 , & V_14 ) )
F_20 ( L_3 , V_61 , V_14 ) ;
}
static void T_2 F_21 ( void )
{
F_19 ( V_30 ) ;
F_19 ( V_38 ) ;
F_19 ( V_62 ) ;
F_19 ( V_63 ) ;
F_19 ( V_64 ) ;
F_19 ( V_65 ) ;
F_19 ( V_66 ) ;
F_19 ( V_67 ) ;
}
static void T_2 F_22 ( void )
{
unsigned int V_68 [ sizeof( V_16 ) * 8 ] ;
int V_53 ;
V_69 [ 0 ] = 0 ;
V_69 [ 1 ] = F_15 ( struct V_22 , V_39 ) ;
if ( ! V_70 ) {
for ( V_53 = V_57 ; V_53 < V_58 ; V_53 ++ ) {
if ( F_13 ( V_53 ) ) {
V_69 [ V_53 ] = V_41 [ V_53 ] ;
V_68 [ V_53 ] = V_43 [ V_53 ] ;
}
}
return;
}
V_69 [ V_57 ] =
V_71 + V_72 ;
for ( V_53 = V_57 ; V_53 < V_58 ; V_53 ++ ) {
if ( F_13 ( V_53 ) )
V_68 [ V_53 ] = V_43 [ V_53 ] ;
else
V_68 [ V_53 ] = 0 ;
if ( V_53 > V_57 )
V_69 [ V_53 ] = V_69 [ V_53 - 1 ]
+ V_68 [ V_53 - 1 ] ;
}
}
static void T_2 F_23 ( void )
{
static int T_4 V_73 = 1 ;
F_24 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! V_45 )
return;
F_14 () ;
F_21 () ;
if ( V_70 ) {
V_44 . V_28 . V_29 . V_74 = ( T_1 ) 1 << 63 | V_16 ;
V_44 . V_28 . V_29 . V_27 = V_16 ;
}
F_25 ( & V_44 . V_28 ) ;
F_26 ( & V_44 . V_28 ) ;
}
static int F_27 ( int V_75 )
{
return 0 ;
}
static int F_28 ( int V_75 )
{
T_3 V_49 , V_50 , V_51 , V_52 ;
F_29 ( V_75 ) ;
F_16 ( V_59 , V_75 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
return ! ! ( V_51 & 2 ) ;
}
static int F_30 ( int V_75 )
{
T_3 V_49 , V_50 , V_51 , V_52 ;
F_29 ( V_75 ) ;
F_16 ( V_59 , V_75 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
return V_50 ;
}
static int F_31 ( int V_75 )
{
T_3 V_49 , V_50 , V_51 , V_52 ;
F_29 ( V_75 ) ;
F_16 ( V_59 , V_75 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
return V_49 ;
}
static int F_32 ( void )
{
return V_70 ;
}
static void F_33 ( void )
{
int V_53 ;
T_3 V_49 , V_50 , V_51 , V_52 ;
static int V_76 = 1 ;
if ( ! V_76 )
return;
V_76 = 0 ;
for ( V_53 = 0 ; V_53 < V_58 + 10 ; V_53 ++ ) {
F_16 ( V_59 , V_53 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
F_34 ( L_4 ,
V_59 , V_53 , V_49 , V_50 , V_51 , V_52 ) ;
}
}
static void F_35 ( int V_77 )
{
int V_78 = F_31 ( V_77 ) ;
F_36 ( V_78 , V_77 , V_79 , struct V_80 ) ;
F_36 ( V_78 , V_77 , V_81 , struct V_82 ) ;
F_36 ( V_78 , V_77 , V_83 , struct V_84 ) ;
F_36 ( V_78 , V_77 , V_85 , struct V_86 ) ;
F_36 ( V_78 , V_77 , V_87 , struct V_88 ) ;
F_36 ( V_78 , V_77 , V_89 , struct V_90 ) ;
if ( ( V_77 < V_79 ) ||
( V_77 >= V_58 ) ) {
F_17 ( 1 , L_5 , V_77 ) ;
F_37 ( 1 ) ;
}
}
static void F_38 ( void )
{
int V_91 = V_71 + V_72 ;
int V_53 ;
for ( V_53 = V_57 ; V_53 < V_58 ; V_53 ++ ) {
if ( ! F_13 ( V_53 ) )
continue;
F_35 ( V_53 ) ;
if ( ! F_32 () )
F_37 ( F_27 ( V_53 ) ) ;
if ( F_28 ( V_53 ) )
V_91 = F_39 ( V_91 , 64 ) ;
if ( ! F_32 () )
V_91 = F_30 ( V_53 ) ;
V_91 += F_31 ( V_53 ) ;
}
F_37 ( V_91 != V_92 ) ;
}
static unsigned int T_2 F_40 ( void )
{
unsigned int V_49 , V_50 , V_51 , V_52 ;
unsigned int V_93 ;
if ( ! V_70 ) {
F_16 ( V_59 , 0 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_93 = V_50 ;
} else {
F_16 ( V_59 , 1 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_93 = V_50 ;
}
return V_93 ;
}
static bool F_41 ( unsigned int V_94 )
{
if ( V_94 <= sizeof( union V_95 ) )
return true ;
F_34 ( L_6 ,
sizeof( union V_95 ) , V_94 ) ;
return false ;
}
static int F_42 ( void )
{
unsigned int V_96 = F_40 () ;
if ( ! F_41 ( V_96 ) )
return - V_97 ;
V_92 = V_96 ;
F_38 () ;
return 0 ;
}
static void F_43 ( void )
{
V_16 = 0 ;
F_44 ( V_46 ) ;
F_1 () ;
}
void T_2 F_45 ( void )
{
unsigned int V_49 , V_50 , V_51 , V_52 ;
static int T_4 V_73 = 1 ;
int V_98 ;
F_24 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! V_45 ) {
F_20 ( L_7 ) ;
return;
}
if ( V_99 . V_100 < V_59 ) {
F_24 ( 1 ) ;
return;
}
F_16 ( V_59 , 0 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_16 = V_49 + ( ( T_1 ) V_52 << 32 ) ;
if ( ( V_16 & V_101 ) != V_101 ) {
F_46 ( L_8 , V_16 ) ;
F_47 () ;
}
V_16 &= F_48 () ;
F_10 () ;
V_98 = F_42 () ;
if ( V_98 ) {
F_43 () ;
return;
}
F_49 ( V_92 , V_16 ) ;
F_50 () ;
F_23 () ;
F_22 () ;
F_20 ( L_9 ,
V_16 ,
V_92 ,
V_70 ? L_10 : L_11 ) ;
}
void F_51 ( void )
{
if ( V_45 )
F_12 ( V_47 , V_16 ) ;
}
void * F_52 ( struct V_55 * V_28 , int V_102 )
{
int V_103 = F_5 ( V_102 ) - 1 ;
if ( ! F_53 ( V_1 ) )
return NULL ;
F_17 ( ! ( V_16 & V_102 ) ,
L_12 ) ;
if ( ! ( V_28 -> V_29 . V_27 & V_102 ) )
return NULL ;
return ( void * ) V_28 + V_69 [ V_103 ] ;
}
const void * F_54 ( int V_104 )
{
struct V_21 * V_21 = & V_105 -> V_106 . V_21 ;
if ( ! V_21 -> V_107 )
return NULL ;
F_55 ( V_21 ) ;
return F_52 ( & V_21 -> V_24 . V_28 , V_104 ) ;
}
