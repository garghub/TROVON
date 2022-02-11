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
}
int F_3 ( T_1 V_12 , const char * * V_13 )
{
T_1 V_14 = V_12 & ~ V_15 ;
if ( F_4 ( V_13 ) ) {
long V_16 , V_17 ;
T_1 V_18 ;
if ( V_14 )
V_18 = V_14 ;
else
V_18 = V_12 ;
V_16 = F_5 ( V_18 ) - 1 ;
V_17 = F_6 ( V_19 ) - 1 ;
V_16 = F_7 ( V_16 , V_17 ) ;
* V_13 = V_19 [ V_16 ] ;
}
if ( V_14 )
return 0 ;
return 1 ;
}
void F_8 ( struct V_20 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_23 . V_24 ;
int V_25 ;
T_1 V_26 ;
if ( ! F_9 () )
return;
V_26 = V_20 -> V_23 . V_27 . V_28 . V_26 ;
if ( ( V_26 & V_15 ) == V_15 )
return;
if ( ! ( V_26 & V_29 ) ) {
V_22 -> V_30 = 0x37f ;
V_22 -> V_31 = 0 ;
V_22 -> V_32 = 0 ;
V_22 -> V_33 = 0 ;
V_22 -> V_34 = 0 ;
V_22 -> V_35 = 0 ;
memset ( & V_22 -> V_36 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_26 & V_37 ) )
memset ( & V_22 -> V_38 [ 0 ] , 0 , 256 ) ;
V_25 = 0x2 ;
V_26 = ( V_15 & ~ V_26 ) >> 2 ;
while ( V_26 ) {
if ( V_26 & 0x1 ) {
int V_39 = V_40 [ V_25 ] ;
int V_41 = V_42 [ V_25 ] ;
memcpy ( ( void * ) V_22 + V_39 ,
( void * ) & V_43 . V_27 + V_39 ,
V_41 ) ;
}
V_26 >>= 1 ;
V_25 ++ ;
}
}
void F_10 ( void )
{
if ( ! V_44 || ! V_15 )
return;
F_11 ( V_45 ) ;
F_12 ( V_46 , V_15 ) ;
}
static int F_13 ( enum V_47 V_47 )
{
return ! ! ( V_15 & ( 1UL << V_47 ) ) ;
}
static void T_2 F_14 ( void )
{
T_3 V_48 , V_49 , V_50 , V_51 , V_52 ;
unsigned int V_53 = F_15 ( struct V_54 ,
V_55 ) ;
for ( V_52 = V_56 ; V_52 < V_57 ; V_52 ++ ) {
if ( ! F_13 ( V_52 ) )
continue;
F_16 ( V_58 , V_52 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
V_40 [ V_52 ] = V_49 ;
V_42 [ V_52 ] = V_48 ;
F_17 ( V_53 > V_40 [ V_52 ] ,
L_1 , V_53 ) ;
V_53 = V_40 [ V_52 ] ;
F_18 ( V_59 L_2 , V_52 , V_49 , V_52 , V_48 ) ;
}
}
static void T_2 F_19 ( T_1 V_60 )
{
const char * V_13 ;
if ( F_3 ( V_60 , & V_13 ) )
F_20 ( L_3 , V_60 , V_13 ) ;
}
static void T_2 F_21 ( void )
{
F_19 ( V_29 ) ;
F_19 ( V_37 ) ;
F_19 ( V_61 ) ;
F_19 ( V_62 ) ;
F_19 ( V_63 ) ;
F_19 ( V_64 ) ;
F_19 ( V_65 ) ;
F_19 ( V_66 ) ;
}
static void T_2 F_22 ( void )
{
unsigned int V_67 [ sizeof( V_15 ) * 8 ] ;
int V_52 ;
V_68 [ 0 ] = 0 ;
V_68 [ 1 ] = F_15 ( struct V_21 , V_38 ) ;
if ( ! V_69 ) {
for ( V_52 = V_56 ; V_52 < V_57 ; V_52 ++ ) {
if ( F_13 ( V_52 ) ) {
V_68 [ V_52 ] = V_40 [ V_52 ] ;
V_67 [ V_52 ] = V_42 [ V_52 ] ;
}
}
return;
}
V_68 [ V_56 ] =
V_70 + V_71 ;
for ( V_52 = V_56 ; V_52 < V_57 ; V_52 ++ ) {
if ( F_13 ( V_52 ) )
V_67 [ V_52 ] = V_42 [ V_52 ] ;
else
V_67 [ V_52 ] = 0 ;
if ( V_52 > V_56 )
V_68 [ V_52 ] = V_68 [ V_52 - 1 ]
+ V_67 [ V_52 - 1 ] ;
}
}
static void T_2 F_23 ( void )
{
static int V_72 = 1 ;
F_24 ( ! V_72 ) ;
V_72 = 0 ;
if ( ! V_44 )
return;
F_14 () ;
F_21 () ;
if ( V_69 ) {
V_43 . V_27 . V_28 . V_73 = ( T_1 ) 1 << 63 | V_15 ;
V_43 . V_27 . V_28 . V_26 = V_15 ;
}
F_25 ( & V_43 . V_27 ) ;
F_26 ( & V_43 . V_27 ) ;
}
static int F_27 ( int V_74 )
{
return 0 ;
}
static int F_28 ( int V_74 )
{
T_3 V_48 , V_49 , V_50 , V_51 ;
F_29 ( V_74 ) ;
F_16 ( V_58 , V_74 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
return ! ! ( V_50 & 2 ) ;
}
static int F_30 ( int V_74 )
{
T_3 V_48 , V_49 , V_50 , V_51 ;
F_29 ( V_74 ) ;
F_16 ( V_58 , V_74 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
return V_49 ;
}
static int F_31 ( int V_74 )
{
T_3 V_48 , V_49 , V_50 , V_51 ;
F_29 ( V_74 ) ;
F_16 ( V_58 , V_74 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
return V_48 ;
}
static int F_32 ( void )
{
return V_69 ;
}
static void F_33 ( void )
{
int V_52 ;
T_3 V_48 , V_49 , V_50 , V_51 ;
static int V_75 = 1 ;
if ( ! V_75 )
return;
V_75 = 0 ;
for ( V_52 = 0 ; V_52 < V_57 + 10 ; V_52 ++ ) {
F_16 ( V_58 , V_52 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
F_34 ( L_4 ,
V_58 , V_52 , V_48 , V_49 , V_50 , V_51 ) ;
}
}
static void F_35 ( int V_76 )
{
int V_77 = F_31 ( V_76 ) ;
F_36 ( V_77 , V_76 , V_78 , struct V_79 ) ;
F_36 ( V_77 , V_76 , V_80 , struct V_81 ) ;
F_36 ( V_77 , V_76 , V_82 , struct V_83 ) ;
F_36 ( V_77 , V_76 , V_84 , struct V_85 ) ;
F_36 ( V_77 , V_76 , V_86 , struct V_87 ) ;
F_36 ( V_77 , V_76 , V_88 , struct V_89 ) ;
if ( ( V_76 < V_78 ) ||
( V_76 >= V_57 ) ) {
F_17 ( 1 , L_5 , V_76 ) ;
F_37 ( 1 ) ;
}
}
static void F_38 ( void )
{
int V_90 = V_70 + V_71 ;
int V_52 ;
for ( V_52 = V_56 ; V_52 < V_57 ; V_52 ++ ) {
if ( ! F_13 ( V_52 ) )
continue;
F_35 ( V_52 ) ;
if ( ! F_32 () )
F_37 ( F_27 ( V_52 ) ) ;
if ( F_28 ( V_52 ) )
V_90 = F_39 ( V_90 , 64 ) ;
if ( ! F_32 () )
V_90 = F_30 ( V_52 ) ;
V_90 += F_31 ( V_52 ) ;
}
F_37 ( V_90 != V_91 ) ;
}
static unsigned int T_2 F_40 ( void )
{
unsigned int V_48 , V_49 , V_50 , V_51 ;
unsigned int V_92 ;
if ( ! V_69 ) {
F_16 ( V_58 , 0 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
V_92 = V_49 ;
} else {
F_16 ( V_58 , 1 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
V_92 = V_49 ;
}
return V_92 ;
}
static bool F_41 ( unsigned int V_93 )
{
if ( V_93 <= sizeof( union V_94 ) )
return true ;
F_34 ( L_6 ,
sizeof( union V_94 ) , V_93 ) ;
return false ;
}
static int F_42 ( void )
{
unsigned int V_95 = F_40 () ;
if ( ! F_41 ( V_95 ) )
return - V_96 ;
V_91 = V_95 ;
F_38 () ;
return 0 ;
}
static void F_43 ( void )
{
V_15 = 0 ;
F_44 ( V_45 ) ;
F_1 () ;
}
void T_2 F_45 ( void )
{
unsigned int V_48 , V_49 , V_50 , V_51 ;
static int V_72 = 1 ;
int V_97 ;
F_24 ( ! V_72 ) ;
V_72 = 0 ;
if ( ! V_44 ) {
F_20 ( L_7 ) ;
return;
}
if ( V_98 . V_99 < V_58 ) {
F_24 ( 1 ) ;
return;
}
F_16 ( V_58 , 0 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
V_15 = V_48 + ( ( T_1 ) V_51 << 32 ) ;
if ( ( V_15 & V_100 ) != V_100 ) {
F_46 ( L_8 , V_15 ) ;
F_47 () ;
}
V_15 = V_15 & V_101 ;
F_10 () ;
V_97 = F_42 () ;
if ( V_97 ) {
F_43 () ;
return;
}
F_48 ( V_91 , V_15 ) ;
F_49 () ;
F_23 () ;
F_22 () ;
F_20 ( L_9 ,
V_15 ,
V_91 ,
V_69 ? L_10 : L_11 ) ;
}
void F_50 ( void )
{
if ( V_44 )
F_12 ( V_46 , V_15 ) ;
}
void * F_51 ( struct V_54 * V_27 , int V_102 )
{
int V_103 = F_5 ( V_102 ) - 1 ;
if ( ! F_52 ( V_1 ) )
return NULL ;
F_17 ( ! ( V_15 & V_102 ) ,
L_12 ) ;
if ( ! ( V_27 -> V_28 . V_26 & V_102 ) )
return NULL ;
return ( void * ) V_27 + V_68 [ V_103 ] ;
}
const void * F_53 ( int V_104 )
{
struct V_20 * V_20 = & V_105 -> V_106 . V_20 ;
if ( ! V_20 -> V_107 )
return NULL ;
F_54 ( V_20 ) ;
return F_51 ( & V_20 -> V_23 . V_27 , V_104 ) ;
}
