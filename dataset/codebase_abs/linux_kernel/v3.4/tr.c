static inline unsigned long F_1 ( const unsigned char * V_1 )
{
unsigned long V_2 ;
V_2 = V_1 [ 0 ] ;
V_2 = ( V_2 << 2 ) ^ V_1 [ 1 ] ;
V_2 = ( V_2 << 2 ) ^ V_1 [ 2 ] ;
V_2 = ( V_2 << 2 ) ^ V_1 [ 3 ] ;
V_2 = ( V_2 << 2 ) ^ V_1 [ 4 ] ;
V_2 = ( V_2 << 2 ) ^ V_1 [ 5 ] ;
V_2 ^= V_2 >> 8 ;
return V_2 & ( V_3 - 1 ) ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_8 , const void * V_9 , unsigned V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
if ( type == V_14 || type == V_15 || type == V_16 )
{
struct V_17 * V_17 ;
V_13 = sizeof( struct V_11 ) + sizeof( struct V_17 ) ;
V_12 = (struct V_11 * ) F_3 ( V_5 , V_13 ) ;
V_17 = (struct V_17 * ) ( V_12 + 1 ) ;
V_17 -> V_18 = V_17 -> V_19 = V_20 ;
V_17 -> V_21 = V_22 ;
V_17 -> V_23 [ 0 ] = V_17 -> V_23 [ 1 ] = V_17 -> V_23 [ 2 ] = 0x00 ;
V_17 -> V_24 = F_4 ( type ) ;
}
else
{
V_13 = sizeof( struct V_11 ) ;
V_12 = (struct V_11 * ) F_3 ( V_5 , V_13 ) ;
}
V_12 -> V_25 = V_26 ;
V_12 -> V_27 = V_28 ;
if( V_9 )
memcpy ( V_12 -> V_9 , V_9 , V_7 -> V_29 ) ;
else
memcpy ( V_12 -> V_9 , V_7 -> V_30 , V_7 -> V_29 ) ;
if( V_8 )
{
memcpy ( V_12 -> V_8 , V_8 , V_7 -> V_29 ) ;
F_5 ( V_5 , V_12 , V_7 ) ;
return V_13 ;
}
return - V_13 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = (struct V_11 * ) V_5 -> V_31 ;
struct V_17 * V_17 = (struct V_17 * ) ( V_5 -> V_31 + sizeof( struct V_11 ) ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if( V_17 -> V_24 != F_4 ( V_14 ) ) {
F_7 ( L_1 , F_8 ( V_17 -> V_24 ) ) ;
return 0 ;
}
#ifdef F_9
if( F_10 ( V_12 -> V_8 , V_5 ) ) {
return 1 ;
}
else
#endif
{
F_5 ( V_5 , V_12 , V_7 ) ;
return 0 ;
}
}
T_1 F_11 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 ;
struct V_17 * V_17 ;
unsigned V_32 = 0 ;
V_5 -> V_7 = V_7 ;
F_12 ( V_5 ) ;
V_12 = F_13 ( V_5 ) ;
if( V_12 -> V_9 [ 0 ] & V_33 )
V_32 = ( F_8 ( V_12 -> V_34 ) & V_35 ) >> 8 ;
V_17 = (struct V_17 * ) ( V_5 -> V_31 + sizeof( struct V_11 ) - V_36 + V_32 ) ;
F_14 ( V_5 , sizeof( struct V_11 ) - V_36 + V_32 ) ;
if( * V_12 -> V_8 & 0x80 )
{
if( ! memcmp ( V_12 -> V_8 , V_7 -> V_37 , V_38 ) )
V_5 -> V_39 = V_40 ;
else
V_5 -> V_39 = V_41 ;
}
else if ( ( V_12 -> V_8 [ 0 ] & 0x01 ) && ( V_12 -> V_8 [ 1 ] & 0x00 ) && ( V_12 -> V_8 [ 2 ] & 0x5E ) )
{
V_5 -> V_39 = V_41 ;
}
else if( V_7 -> V_42 & V_43 )
{
if( memcmp ( V_12 -> V_8 , V_7 -> V_30 , V_38 ) )
V_5 -> V_39 = V_44 ;
}
if ( ( V_5 -> V_39 != V_40 ) &&
( V_5 -> V_39 != V_41 ) )
F_15 ( V_12 , V_7 ) ;
if ( V_17 -> V_18 == V_20 &&
( V_17 -> V_24 == F_4 ( V_14 ) ||
V_17 -> V_24 == F_4 ( V_15 ) ||
V_17 -> V_24 == F_4 ( V_16 ) ) )
{
F_14 ( V_5 , sizeof( struct V_17 ) ) ;
return V_17 -> V_24 ;
}
return F_4 ( V_45 ) ;
}
void F_5 ( struct V_4 * V_5 , struct V_11 * V_12 ,
struct V_6 * V_7 )
{
int V_46 ;
unsigned int V_47 ;
struct V_48 * V_49 ;
unsigned char * V_50 ;
unsigned long V_42 ;
static const unsigned char V_51 []
= { 0xC0 , 0x00 , 0x00 , 0x04 , 0x00 , 0x00 } ;
F_16 ( & V_52 , V_42 ) ;
if( ( ! memcmp ( & ( V_12 -> V_8 [ 0 ] ) , & ( V_7 -> V_37 [ 0 ] ) , V_38 ) ) ||
( ! memcmp ( & ( V_12 -> V_8 [ 0 ] ) , & ( V_51 [ 0 ] ) , V_38 ) ) )
{
V_12 -> V_34 = F_4 ( ( ( ( sizeof( V_12 -> V_34 ) ) << 8 ) & V_35 )
| V_53 | V_54 ) ;
V_12 -> V_9 [ 0 ] |= V_33 ;
}
else
{
V_47 = F_1 ( V_12 -> V_8 ) ;
for( V_49 = V_55 [ V_47 ] ; V_49 && memcmp ( & ( V_49 -> V_1 [ 0 ] ) , & ( V_12 -> V_8 [ 0 ] ) , V_38 ) ; V_49 = V_49 -> V_56 ) ;
if( V_49 )
{
#if V_57
F_7 ( L_2 , V_12 -> V_8 ) ;
#endif
if( ! V_49 -> V_58 && ( F_8 ( V_49 -> V_34 ) & V_35 ) >> 8 )
{
V_12 -> V_34 = V_49 -> V_34 ;
memcpy ( & V_12 -> V_59 [ 0 ] , & V_49 -> V_59 [ 0 ] , 8 *sizeof( unsigned short ) ) ;
V_12 -> V_34 ^= F_4 ( V_60 ) ;
V_12 -> V_34 &= F_4 ( 0x1fff ) ;
V_12 -> V_9 [ 0 ] |= V_33 ;
#if V_57
F_7 ( L_3 , V_49 -> V_34 ) ;
}
else
{
F_7 ( L_4 , V_49 -> V_58 ) ;
#endif
}
V_49 -> V_61 = V_62 ;
}
else
{
V_12 -> V_34 = F_4 ( ( ( ( sizeof( V_12 -> V_34 ) ) << 8 ) & V_35 )
| V_53 | V_54 ) ;
V_12 -> V_9 [ 0 ] |= V_33 ;
#if V_57
F_7 ( L_5 ) ;
#endif
}
}
if ( ! ( V_12 -> V_9 [ 0 ] & 0x80 ) )
V_46 = 18 ;
else
V_46 = 18 - ( ( F_8 ( V_12 -> V_34 ) & V_35 ) >> 8 ) ;
V_50 = V_5 -> V_31 ;
F_17 ( & V_52 , V_42 ) ;
F_14 ( V_5 , V_46 ) ;
memmove ( V_5 -> V_31 , V_50 , sizeof( struct V_11 ) - V_46 ) ;
}
static void F_15 ( struct V_11 * V_12 , struct V_6 * V_7 )
{
unsigned int V_47 , V_63 = 0 ;
unsigned long V_42 ;
struct V_48 * V_49 ;
unsigned char V_64 ;
F_16 ( & V_52 , V_42 ) ;
V_64 = V_12 -> V_9 [ 0 ] ;
if( V_12 -> V_9 [ 0 ] & V_33 )
{
V_12 -> V_9 [ 0 ] &= 0x7f ;
if ( ( ( F_8 ( V_12 -> V_34 ) & V_35 ) >> 8 ) > 2 )
{
V_63 = 1 ;
}
}
V_47 = F_1 ( V_12 -> V_9 ) ;
for( V_49 = V_55 [ V_47 ] ; V_49 && memcmp ( & ( V_49 -> V_1 [ 0 ] ) , & ( V_12 -> V_9 [ 0 ] ) , V_38 ) ; V_49 = V_49 -> V_56 ) ;
if( V_49 == NULL )
{
#if V_57
F_7 ( L_6 ,
V_12 -> V_9 , F_8 ( V_12 -> V_34 ) ) ;
#endif
V_49 = F_18 ( sizeof( struct V_48 ) , V_65 ) ;
if( ! V_49 )
{
F_7 ( V_66 L_7 ) ;
F_17 ( & V_52 , V_42 ) ;
return;
}
memcpy ( & ( V_49 -> V_1 [ 0 ] ) , & ( V_12 -> V_9 [ 0 ] ) , V_38 ) ;
V_49 -> V_67 = V_7 -> V_68 ;
V_49 -> V_56 = V_55 [ V_47 ] ;
V_49 -> V_61 = V_62 ;
V_55 [ V_47 ] = V_49 ;
if ( V_63 )
{
V_49 -> V_34 = V_12 -> V_34 & F_4 ( ( unsigned short ) ~ V_69 ) ;
memcpy ( & ( V_49 -> V_59 [ 0 ] ) , & ( V_12 -> V_59 [ 0 ] ) , 8 *sizeof( unsigned short ) ) ;
V_49 -> V_58 = 0 ;
}
else
{
V_49 -> V_58 = 1 ;
}
}
else
{
if ( ! V_49 -> V_58 )
if ( V_49 -> V_34 != ( V_12 -> V_34 & F_4 ( ( unsigned short ) ~ V_69 ) ) &&
! ( V_12 -> V_34 & F_4 ( V_69 ) ) )
{
#if V_57
F_7 ( L_8 ,
V_12 -> V_9 , F_8 ( V_12 -> V_34 ) ) ;
#endif
V_49 -> V_34 = V_12 -> V_34 & F_4 ( ( unsigned short ) ~ V_69 ) ;
memcpy ( & ( V_49 -> V_59 [ 0 ] ) , & ( V_12 -> V_59 [ 0 ] ) , 8 *sizeof( unsigned short ) ) ;
}
V_49 -> V_61 = V_62 ;
}
V_12 -> V_9 [ 0 ] = V_64 ;
F_17 ( & V_52 , V_42 ) ;
}
static void F_19 ( unsigned long V_70 )
{
int V_71 ;
unsigned long V_42 , V_72 = V_62 + V_73 / 2 ;
F_16 ( & V_52 , V_42 ) ;
for( V_71 = 0 ; V_71 < V_3 ; V_71 ++ ) {
struct V_48 * V_49 , * * V_74 ;
V_74 = V_55 + V_71 ;
while( ( V_49 = * V_74 ) != NULL ) {
unsigned long V_75
= V_49 -> V_61 + V_73 ;
if ( F_20 ( V_75 , V_62 ) ) {
* V_74 = V_49 -> V_56 ;
F_21 ( V_49 ) ;
} else {
V_74 = & V_49 -> V_56 ;
if ( F_22 ( V_75 , V_72 ) )
V_72 = V_75 ;
}
}
}
F_17 ( & V_52 , V_42 ) ;
F_23 ( & V_76 , V_72 ) ;
}
static struct V_48 * F_24 ( T_2 V_77 )
{
int V_71 ;
struct V_48 * V_49 ;
T_2 V_78 = 0 ;
for( V_71 = 0 ; V_71 < V_3 ; V_71 ++ )
for( V_49 = V_55 [ V_71 ] ; V_49 ; V_49 = V_49 -> V_56 ) {
if ( V_78 == V_77 )
return V_49 ;
++ V_78 ;
}
return NULL ;
}
static void * F_25 ( struct V_79 * V_80 , T_2 * V_77 )
__acquires( &rif_lock
static void * F_26 ( struct V_79 * V_80 , void * V_81 , T_2 * V_77 )
{
int V_71 ;
struct V_48 * V_82 = V_81 ;
++ * V_77 ;
if ( V_81 == V_83 ) {
V_71 = - 1 ;
goto V_84;
}
if ( V_82 -> V_56 )
return V_82 -> V_56 ;
V_71 = F_1 ( V_82 -> V_1 ) ;
V_84:
while ( ++ V_71 < V_3 ) {
if ( ( V_82 = V_55 [ V_71 ] ) != NULL )
return V_82 ;
}
return NULL ;
}
static void F_27 ( struct V_79 * V_80 , void * V_81 )
__releases( &rif_lock
static int F_28 ( struct V_79 * V_80 , void * V_81 )
{
int V_85 , V_86 , V_87 , V_88 ;
struct V_48 * V_49 = V_81 ;
if ( V_81 == V_83 )
F_29 ( V_80 ,
L_9 ) ;
else {
struct V_6 * V_7 = F_30 ( & V_89 , V_49 -> V_67 ) ;
long V_90 = ( long ) ( V_49 -> V_61 + V_73 )
- ( long ) V_62 ;
F_31 ( V_80 , L_10 ,
V_7 ? V_7 -> V_91 : L_11 ,
V_49 -> V_1 ,
V_90 / V_92 ) ;
if ( V_49 -> V_58 )
F_29 ( V_80 , L_12 ) ;
else {
F_31 ( V_80 , L_13 , F_8 ( V_49 -> V_34 ) ) ;
V_86 = ( ( F_8 ( V_49 -> V_34 ) & V_35 ) >> 8 ) - 2 ;
if ( V_86 )
V_86 >>= 1 ;
for( V_85 = 1 ; V_85 < V_86 ; V_85 ++ ) {
if( V_85 == 1 ) {
V_87 = F_8 ( V_49 -> V_59 [ V_85 - 1 ] ) >> 4 ;
F_31 ( V_80 , L_14 , V_87 ) ;
}
V_87 = F_8 ( V_49 -> V_59 [ V_85 ] ) >> 4 ;
V_88 = F_8 ( V_49 -> V_59 [ V_85 - 1 ] ) & 0x00f ;
F_31 ( V_80 , L_15 , V_88 , V_87 ) ;
}
F_32 ( V_80 , '\n' ) ;
}
if ( V_7 )
F_33 ( V_7 ) ;
}
return 0 ;
}
static int F_34 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_35 ( V_94 , & V_95 ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
V_7 -> V_96 = & V_97 ;
V_7 -> type = V_98 ;
V_7 -> V_99 = V_100 ;
V_7 -> V_101 = 2000 ;
V_7 -> V_29 = V_38 ;
V_7 -> V_102 = 100 ;
memset ( V_7 -> V_37 , 0xFF , V_38 ) ;
V_7 -> V_42 = V_103 | V_104 ;
}
struct V_6 * F_37 ( int V_105 )
{
return F_38 ( V_105 , L_16 , F_36 ) ;
}
static int T_3 F_39 ( void )
{
V_76 . V_75 = V_62 + V_73 ;
F_40 ( & V_76 , F_19 , 0 ) ;
F_41 ( & V_76 ) ;
#ifdef F_42
F_43 ( V_106 , V_107 ) ;
#endif
F_44 ( & V_89 , L_17 , V_108 , & V_109 ) ;
return 0 ;
}
