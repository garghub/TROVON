static inline void
F_1 ( T_1 * V_1 , T_1 V_2 , unsigned int V_3 )
{
V_3 /= 2 ;
while ( V_3 -- )
F_2 ( V_2 , V_1 ++ ) ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
if ( F_4 ( V_5 , V_6 , 0x0c , 0x00 ) )
return;
if ( F_4 ( V_5 , V_6 , 0x0d , 0x00 ) )
return;
if ( F_4 ( V_5 , V_6 , 0x0e , 0x00 ) )
return;
F_4 ( V_5 , V_6 , 0x0f , 0x00 ) ;
}
static inline void
F_5 ( struct V_4 * V_5 , struct V_7 * V_2 )
{
V_5 -> V_8 = ( V_2 -> V_9 - V_5 -> V_10 ) / 2 ;
F_4 ( V_5 , V_6 , 0x0c , ( V_5 -> V_8 >> 8 ) ) ;
F_4 ( V_5 , V_6 , 0x0d , ( V_5 -> V_8 & 0xff ) ) ;
}
void
F_6 ( struct V_4 * V_5 , unsigned int V_11 )
{
if ( V_5 -> V_12 == V_11 )
return;
V_5 -> V_12 = V_11 ;
if ( ( V_11 & 0x0007 ) == 0x0007 ) {
V_5 -> V_13 = 1 ;
V_11 -- ;
if ( F_7 ( V_5 , V_6 , 0x0b , 0x1f , 0x20 ) )
return;
} else if ( V_5 -> V_13 ) {
if ( F_8 ( V_5 , V_6 , 0x0b , 0x1f ) )
return;
V_5 -> V_13 = 0 ;
}
if ( F_4 ( V_5 , V_6 , 0x0e , ( V_11 >> 8 ) ) )
return;
F_4 ( V_5 , V_6 , 0x0f , ( V_11 & 0xff ) ) ;
}
static inline struct V_4 *
F_9 ( unsigned short V_14 )
{
return V_15 [ V_14 ] ;
}
static inline int
F_10 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_16 || ! V_5 -> V_17 || ! V_5 -> V_18 )
return 0 ;
return 1 ;
}
static struct V_4 *
F_11 ( unsigned short V_14 )
{
struct V_4 * V_5 ;
if ( F_12 () )
return NULL ;
V_5 = F_9 ( V_14 ) ;
if ( ! V_5 )
return NULL ;
F_13 ( & V_5 -> V_19 ) ;
if ( ! F_10 ( V_5 ) ||
! V_5 -> V_20 [ V_14 ] ) {
F_14 ( & V_5 -> V_19 ) ;
return NULL ;
}
return V_5 ;
}
static int
F_15 ( struct V_7 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_21 ||
V_5 -> V_22 ||
V_2 -> V_23 != V_24 )
return 1 ;
return 0 ;
}
static const char *
F_16 ( void )
{
return L_1 ;
}
static void
F_17 ( struct V_7 * V_2 , int V_25 )
{
struct V_4 * V_5 ;
int V_26 , V_27 ;
V_5 = F_9 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
F_13 ( & V_5 -> V_19 ) ;
if ( ! F_10 ( V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_2 -> V_29 = 1 ;
V_2 -> V_30 = 0x7700 ;
V_2 -> V_31 = V_5 -> V_32 ? 0x0800 : 0 ;
V_5 -> V_33 = 1 ;
V_5 -> V_20 [ V_2 -> V_28 ] = 1 ;
V_2 -> V_34 = 400 ;
V_2 -> V_35 . V_36 = V_5 -> V_37 ;
V_26 = 80 ;
V_27 = V_2 -> V_34 / V_2 -> V_35 . V_36 ;
F_18 ( & V_5 -> V_38 ) ;
if ( ! * V_2 -> V_39 )
F_19 ( V_2 ) ;
F_14 ( & V_5 -> V_19 ) ;
if ( V_25 ) {
V_2 -> V_40 = V_26 ;
V_2 -> V_41 = V_27 ;
} else
F_20 ( V_2 , V_26 , V_27 ) ;
}
static void
F_21 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
int V_42 ;
V_5 = F_9 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
F_13 ( & V_5 -> V_19 ) ;
V_15 [ V_2 -> V_28 ] = NULL ;
V_5 -> V_20 [ V_2 -> V_28 ] = 0 ;
if ( V_5 -> V_43 ) {
for( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
if ( V_5 -> V_20 [ V_2 -> V_28 ] )
break;
}
if ( V_42 == V_44 ) {
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
}
F_14 ( & V_5 -> V_19 ) ;
F_23 ( & V_5 -> V_38 , V_45 ) ;
}
static T_2
F_24 ( struct V_7 * V_2 , T_2 V_46 , T_2 V_47 ,
T_2 V_48 , T_2 V_49 , T_2 V_50 , T_2 V_51 )
{
T_2 V_52 = V_46 ;
if ( V_49 )
V_52 = ( V_52 & 0xf0 ) | V_2 -> V_53 ;
else if ( V_47 == 0 )
V_52 = ( V_52 & 0xf0 ) | V_2 -> V_54 ;
if ( V_50 )
V_52 = ( ( V_52 ) & 0x88 ) |
( ( ( ( V_52 ) >> 4 ) |
( ( V_52 ) << 4 ) ) & 0x77 ) ;
if ( V_48 )
V_52 ^= 0x80 ;
if ( V_47 == 2 )
V_52 ^= 0x08 ;
return V_52 ;
}
static void
F_25 ( struct V_7 * V_55 , T_1 * V_56 , int V_3 )
{
while ( V_3 -- ) {
T_1 V_57 = F_26 ( V_56 ) ;
V_57 = ( ( V_57 ) & 0x88ff ) |
( ( ( V_57 ) & 0x7000 ) >> 4 ) |
( ( ( V_57 ) & 0x0700 ) << 4 ) ;
F_2 ( V_57 , V_56 ++ ) ;
}
}
static void
F_27 ( struct V_7 * V_2 , int V_58 , int V_59 , int V_60 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_28 ( V_5 , ( char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , 2 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_31 ( struct V_7 * V_2 , const unsigned short * V_1 ,
int V_3 , int V_59 , int V_60 )
{
struct V_4 * V_5 ;
T_1 * V_61 ;
int V_42 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
V_61 = F_29 ( V_60 , V_59 ) ;
for ( V_42 = V_3 ; V_42 > 0 ; V_42 -- )
F_2 ( F_26 ( V_1 ++ ) , V_61 ++ ) ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_28 ( V_5 , ( char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , V_3 * 2 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_32 ( struct V_7 * V_2 , int V_59 , int V_60 , int V_36 , int V_62 )
{
struct V_4 * V_5 ;
T_1 V_63 = V_2 -> V_64 ;
int V_42 , V_65 , V_26 ;
T_1 * V_61 ;
if ( V_62 <= 0 || V_36 <= 0 )
return;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
V_61 = F_29 ( V_60 , V_59 ) ;
V_26 = V_5 -> V_66 ;
if ( V_62 > V_26 )
V_62 = V_26 ;
if ( V_60 == 0 && V_62 >= V_2 -> V_40 ) {
F_1 ( V_61 , V_63 , V_36 * V_26 * 2 ) ;
} else {
for ( V_42 = V_36 ; V_42 > 0 ; V_42 -- , V_61 += V_26 )
F_1 ( V_61 , V_63 , V_62 * 2 ) ;
}
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_65 = ( ( V_36 * V_26 ) - V_60 - ( V_26 - V_62 - V_60 ) ) * 2 ;
F_28 ( V_5 , ( unsigned char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , V_65 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_33 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
int V_65 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( V_2 -> V_67 == ( unsigned long ) V_2 -> V_68 ) {
F_14 ( & V_5 -> V_19 ) ;
F_34 ( & V_5 -> V_18 -> V_69 , L_2 ) ;
return 0 ;
}
V_65 = F_35 ( ( int ) V_2 -> V_70 ,
( int ) ( V_5 -> V_10 + V_5 -> V_71 - V_2 -> V_67 ) ) ;
F_36 ( ( T_1 * ) V_2 -> V_67 , ( T_1 * ) V_2 -> V_68 ,
V_65 ) ;
F_28 ( V_5 , ( unsigned char * ) V_2 -> V_67 ,
( long ) F_30 ( 0 , 0 ) ,
V_65 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
static void
F_37 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
int V_65 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_65 = F_35 ( ( int ) V_2 -> V_70 ,
( int ) ( V_5 -> V_10 + V_5 -> V_71 - V_2 -> V_67 ) ) ;
F_36 ( ( T_1 * ) V_2 -> V_68 , ( T_1 * ) V_2 -> V_67 ,
V_65 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_38 ( struct V_7 * V_2 , const unsigned char * V_72 )
{
struct V_4 * V_5 ;
int V_42 , V_73 ;
if ( ! F_39 ( V_2 ) )
return;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
for ( V_42 = V_73 = 0 ; V_42 < 16 ; V_42 ++ ) {
if ( F_40 ( V_5 , V_74 , V_72 [ V_42 ] ) )
break;
if ( F_40 ( V_5 , V_75 , V_2 -> V_76 [ V_73 ++ ] >> 2 ) )
break;
if ( F_40 ( V_5 , V_75 , V_2 -> V_76 [ V_73 ++ ] >> 2 ) )
break;
if ( F_40 ( V_5 , V_75 , V_2 -> V_76 [ V_73 ++ ] >> 2 ) )
break;
}
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_41 ( struct V_7 * V_2 , int V_77 , int V_78 )
{
struct V_4 * V_5 ;
T_2 V_79 , V_80 , V_81 , V_82 ;
int V_83 = 0 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( V_78 )
V_5 -> V_21 = V_77 ? 1 : 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
switch ( V_77 ) {
case 1 :
case - 1 :
F_1 ( ( T_1 * ) V_2 -> V_67 ,
V_2 -> V_64 ,
V_2 -> V_70 ) ;
F_28 ( V_5 ,
( unsigned char * ) V_2 -> V_67 ,
( V_84 ) ( V_5 -> V_85 +
( V_2 -> V_67 - V_5 -> V_10 ) ) ,
V_2 -> V_70 ) ;
V_5 -> V_86 = 1 ;
V_83 = 1 ;
break;
default:
switch ( V_77 ) {
case 0 :
V_79 = 0x00 ;
V_80 = 0x80 ;
V_81 = 0x00 ;
V_82 = 0x00 ;
V_83 = 1 ;
V_5 -> V_86 = 0 ;
break;
case V_87 + 1 :
V_79 = 0x20 ;
V_80 = 0x80 ;
V_81 = 0x80 ;
V_82 = 0x40 ;
break;
case V_88 + 1 :
V_79 = 0x20 ;
V_80 = 0x80 ;
V_81 = 0x40 ;
V_82 = 0x40 ;
break;
case V_89 + 1 :
V_79 = 0x20 ;
V_80 = 0x00 ;
V_81 = 0xc0 ;
V_82 = 0x40 ;
break;
default:
F_14 ( & V_5 -> V_19 ) ;
return - V_90 ;
}
F_7 ( V_5 , V_91 , 0x01 , ~ 0x20 , V_79 ) ;
F_7 ( V_5 , V_6 , 0x17 , 0x7f , V_80 ) ;
F_7 ( V_5 , V_91 , 0x1f , 0x3f , V_81 ) ;
F_7 ( V_5 , V_6 , 0x63 , 0xbf , V_82 ) ;
}
F_14 ( & V_5 -> V_19 ) ;
return V_83 ;
}
static void
F_42 ( struct V_7 * V_2 , int V_92 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_43 ( V_2 , V_92 , V_5 -> V_93 ,
( void * ) V_5 -> V_10 , V_5 -> V_71 ) ;
F_5 ( V_5 , V_2 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_44 ( struct V_7 * V_2 , int V_94 )
{
struct V_4 * V_5 ;
int V_95 , V_96 , V_97 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
if ( V_2 -> V_67 != V_2 -> V_9 ) {
V_2 -> V_9 = V_2 -> V_67 ;
F_5 ( V_5 , V_2 ) ;
}
if ( V_94 == V_98 ) {
F_45 ( V_5 , V_6 , 0x0a , 0x20 ) ;
V_5 -> V_99 = - 1 ;
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_6 ( V_5 , ( V_2 -> V_100 - V_5 -> V_10 ) / 2 ) ;
V_97 = V_2 -> V_35 . V_36 - ( V_2 -> V_35 . V_36 < 10 ? 1 : 2 ) ;
switch ( V_2 -> V_101 & 0x0f ) {
case V_102 : V_95 = 1 ;
V_96 = V_2 -> V_35 . V_36 ;
break;
case V_103 : V_95 = V_2 -> V_35 . V_36 / 3 ;
V_96 = V_97 ;
break;
case V_104 : V_95 = V_2 -> V_35 . V_36 / 2 ;
V_96 = V_97 ;
break;
case V_105 : V_95 = ( V_2 -> V_35 . V_36 * 2 ) / 3 ;
V_96 = V_97 ;
break;
case V_106 : V_95 = 31 ;
V_96 = 30 ;
break;
default:
case V_107 : V_95 = V_97 - 1 ;
V_96 = V_97 ;
break;
}
if ( V_5 -> V_108 != V_95 ||
V_5 -> V_99 != V_96 ) {
F_4 ( V_5 , V_6 , 0x0a , V_95 ) ;
F_7 ( V_5 , V_6 , 0x0b , 0xe0 , V_96 ) ;
V_5 -> V_108 = V_95 ;
V_5 -> V_99 = V_96 ;
}
F_14 ( & V_5 -> V_19 ) ;
}
static bool
F_46 ( struct V_7 * V_2 , struct V_4 * V_5 ,
unsigned int V_109 , unsigned int V_110 , enum V_111 V_112 ,
unsigned int V_92 )
{
int V_26 = V_5 -> V_66 ;
int V_65 = ( ( V_110 - V_109 ) * V_26 ) * 2 ;
T_1 V_63 = V_2 -> V_64 ;
switch ( V_112 ) {
case V_113 :
F_47 ( F_29 ( 0 , V_109 ) ,
F_29 ( 0 , V_109 + V_92 ) ,
( V_110 - V_109 - V_92 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_110 - V_92 ) , V_63 ,
V_92 * V_26 * 2 ) ;
break;
case V_114 :
F_47 ( F_29 ( 0 , V_109 + V_92 ) ,
F_29 ( 0 , V_109 ) ,
( V_110 - V_109 - V_92 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_109 ) , V_63 ,
V_92 * V_26 * 2 ) ;
break;
}
F_28 ( V_5 , ( char * ) F_29 ( 0 , V_109 ) ,
( long ) F_30 ( 0 , V_109 ) , V_65 ) ;
F_14 ( & V_5 -> V_19 ) ;
return true ;
}
static bool
F_48 ( struct V_7 * V_2 , unsigned int V_109 , unsigned int V_110 ,
enum V_111 V_112 , unsigned int V_92 )
{
struct V_4 * V_5 ;
T_1 V_63 = V_2 -> V_64 ;
int V_115 = 0 ;
unsigned long V_116 ;
unsigned int V_117 = V_92 * V_2 -> V_118 ;
V_84 V_119 ;
if ( ! V_92 )
return true ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return false ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return false ;
}
if ( V_109 || V_110 != V_2 -> V_41 )
return F_46 ( V_2 , V_5 , V_109 , V_110 , V_112 , V_92 ) ;
if ( V_2 -> V_67 != V_2 -> V_9 ) {
V_2 -> V_9 = V_2 -> V_67 ;
F_5 ( V_5 , V_2 ) ;
}
if ( V_92 > V_2 -> V_41 )
V_92 = V_2 -> V_41 ;
V_116 = V_2 -> V_67 ;
switch ( V_112 ) {
case V_113 :
if ( V_2 -> V_120 + V_117 >=
V_5 -> V_10 + V_5 -> V_71 ) {
F_36 ( ( T_1 * ) V_5 -> V_10 ,
( T_1 * ) ( V_116 + V_117 ) ,
V_2 -> V_70 - V_117 ) ;
V_2 -> V_67 = V_5 -> V_10 ;
V_5 -> V_93 = V_116 - V_5 -> V_10 ;
V_115 = 1 ;
} else
V_2 -> V_67 += V_117 ;
F_1 (
( T_1 * ) ( V_2 -> V_67 + V_2 -> V_70 - V_117 ) ,
V_63 , V_117 ) ;
break;
case V_114 :
if ( V_116 - V_117 < V_5 -> V_10 ) {
F_47 ( ( T_1 * ) ( V_5 -> V_10 +
V_5 -> V_71 -
V_2 -> V_70 +
V_117 ) ,
( T_1 * ) V_116 ,
V_2 -> V_70 - V_117 ) ;
V_2 -> V_67 = V_5 -> V_10 +
V_5 -> V_71 -
V_2 -> V_70 ;
V_5 -> V_93 = 0 ;
V_115 = 1 ;
} else
V_2 -> V_67 -= V_117 ;
V_2 -> V_120 = V_2 -> V_67 + V_2 -> V_70 ;
F_49 ( ( T_1 * ) ( V_2 -> V_67 ) , V_63 , V_117 ) ;
break;
}
V_119 = ( V_84 ) ( V_2 -> V_67 - V_5 -> V_10 ) ;
if ( V_115 )
F_28 ( V_5 ,
( char * ) V_2 -> V_67 ,
( V_84 ) ( V_5 -> V_85 + V_119 ) ,
V_2 -> V_70 ) ;
else if ( V_112 == V_113 )
F_28 ( V_5 ,
( char * ) V_2 -> V_67 + V_2 -> V_70 - V_117 ,
( V_84 ) V_5 -> V_85 + V_119 +
V_2 -> V_70 - V_117 ,
V_117 ) ;
else
F_28 ( V_5 ,
( char * ) V_2 -> V_67 ,
( V_84 ) ( V_5 -> V_85 + V_119 ) ,
V_117 ) ;
V_2 -> V_120 = V_2 -> V_67 + V_2 -> V_70 ;
V_2 -> V_9 = V_2 -> V_67 ;
F_5 ( V_5 , V_2 ) ;
V_2 -> V_100 = V_2 -> V_100 - V_116 + V_2 -> V_67 ;
F_14 ( & V_5 -> V_19 ) ;
return true ;
}
static int
F_50 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) || V_5 -> V_86 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
V_2 -> V_67 = V_2 -> V_9 = V_5 -> V_10 ;
F_5 ( V_5 , V_2 ) ;
V_5 -> V_93 = 0 ;
F_14 ( & V_5 -> V_19 ) ;
return true ;
}
static int
F_51 ( struct V_7 * V_2 , unsigned int V_121 , unsigned int V_122 ,
unsigned int V_123 )
{
struct V_4 * V_5 ;
int V_124 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_125 ;
V_124 = V_5 -> V_37 ;
F_14 ( & V_5 -> V_19 ) ;
if ( V_121 != 80 || V_2 -> V_34 / V_124 != V_122 )
return - V_90 ;
return 0 ;
}
int
F_52 ( struct V_4 * V_5 , int V_126 , int V_127 ,
T_2 * V_128 , int V_129 , int V_130 , int V_131 ,
struct V_7 * V_2 , int V_124 , int V_132 )
{
int V_133 = 0x00 , V_42 , V_134 = 0 ;
V_84 V_135 = 0 ;
T_2 V_136 ;
if ( ( V_127 != 0 && V_127 != 2 ) || ! V_124 ) {
if ( V_132 )
F_14 ( & V_5 -> V_19 ) ;
return - V_90 ;
}
if ( V_126 )
V_5 -> V_137 = V_127 ;
if ( V_127 == 0 )
V_130 = 0 ;
else
V_135 = 4 * V_129 ;
V_133 = ( V_127 == 0 ) ? 0x00 : ( V_130 ? 0x0e : 0x0a ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x00 , 0x01 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x02 , 0x04 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x04 , 0x07 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x00 , 0x03 ) ;
if ( V_134 )
goto V_138;
V_134 |= F_4 ( V_5 , V_139 , 0x04 , 0x03 ) ;
V_134 |= F_4 ( V_5 , V_139 , 0x05 , 0x00 ) ;
V_134 |= F_4 ( V_5 , V_139 , 0x06 , 0x00 ) ;
if ( V_134 )
goto V_138;
if ( V_128 ) {
if ( V_126 )
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
V_134 |= F_53 ( V_5 ,
V_5 -> V_85 + V_135 + V_42 ,
V_128 [ V_42 ] ) ;
if ( V_134 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
V_134 |= F_54 ( V_5 ,
V_5 -> V_85 + V_135 + V_42 ,
& V_128 [ V_42 ] ) ;
if ( V_134 )
break;
}
if ( V_130 ) {
if ( V_126 )
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
V_134 |= F_53 ( V_5 ,
V_5 -> V_85 + V_135 +
( 2 * V_129 ) + V_42 ,
V_128 [ V_129 + V_42 ] ) ;
if ( V_134 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
V_134 |= F_54 ( V_5 ,
V_5 -> V_85 + V_135 +
( 2 * V_129 ) + V_42 ,
& V_128 [ V_129 + V_42 ] ) ;
if ( V_134 )
break;
}
}
}
if ( V_134 )
goto V_138;
V_134 |= F_4 ( V_5 , V_91 , 0x00 , 0x01 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x02 , 0x03 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x04 , 0x03 ) ;
if ( V_126 )
F_4 ( V_5 , V_91 , 0x03 , V_133 ) ;
V_134 |= F_4 ( V_5 , V_91 , 0x00 , 0x03 ) ;
if ( V_134 )
goto V_138;
V_134 |= F_4 ( V_5 , V_139 , 0x04 , 0x00 ) ;
V_134 |= F_4 ( V_5 , V_139 , 0x05 , 0x10 ) ;
V_134 |= F_4 ( V_5 , V_139 , 0x06 , 0x06 ) ;
if ( V_134 )
goto V_138;
if ( ( V_126 ) && ( V_130 != V_5 -> V_32 ) ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_140 = V_141 [ V_42 ] . V_140 ;
if ( V_140 && V_140 -> V_142 == & V_143 )
V_140 -> V_31 = V_130 ? 0x0800 : 0 ;
}
V_5 -> V_32 = V_130 ;
F_55 ( V_5 , V_144 , & V_136 ) ;
F_40 ( V_5 , V_145 , 0x12 ) ;
F_40 ( V_5 , V_145 , V_130 ? 0x07 : 0x0f ) ;
F_55 ( V_5 , V_144 , & V_136 ) ;
F_40 ( V_5 , V_145 , 0x20 ) ;
F_55 ( V_5 , V_144 , & V_136 ) ;
}
if ( V_131 ) {
unsigned char V_146 , V_147 , V_148 ;
int V_27 = 0 , V_149 = 0 ;
if ( V_2 ) {
V_27 = V_2 -> V_34 / V_124 ;
V_149 = V_27 * V_124 - 1 ;
F_56 ( V_5 , V_6 , 0x07 , & V_146 ) ;
V_147 = V_149 & 0xff ;
V_146 = ( V_146 & 0xbd ) |
( ( V_149 & 0x100 ) >> 7 ) |
( ( V_149 & 0x200 ) >> 3 ) ;
F_4 ( V_5 , V_6 , 0x07 , V_146 ) ;
F_4 ( V_5 , V_6 , 0x12 , V_147 ) ;
}
F_56 ( V_5 , V_6 , 0x09 , & V_148 ) ;
V_148 = ( V_148 & 0xe0 ) | ( V_124 - 1 ) ;
F_4 ( V_5 , V_6 , 0x09 , V_148 ) ;
V_5 -> V_37 = V_124 ;
V_5 -> V_108 = - 1 ;
V_5 -> V_99 = - 1 ;
}
if ( V_132 )
F_14 ( & V_5 -> V_19 ) ;
if ( V_131 && V_2 ) {
int V_27 = V_2 -> V_34 / V_124 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_55 = V_141 [ V_42 ] . V_140 ;
if ( V_55 && V_55 -> V_142 == & V_143 ) {
if ( F_39 ( V_55 ) ) {
V_55 -> V_142 -> V_150 ( V_55 , V_151 ) ;
}
V_55 -> V_35 . V_36 = V_124 ;
F_20 ( V_55 , 0 , V_27 ) ;
}
}
}
return 0 ;
V_138:
if ( V_132 )
F_14 ( & V_5 -> V_19 ) ;
return - V_152 ;
}
static int
F_57 ( struct V_7 * V_2 , struct V_153 * V_154 ,
unsigned V_155 )
{
struct V_4 * V_5 ;
unsigned V_156 = V_154 -> V_156 ;
if ( V_154 -> V_62 != 8 || ( V_156 != 256 && V_156 != 512 ) )
return - V_90 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_125 ;
if ( V_5 -> V_43 ) {
if ( V_5 -> V_157 < V_156 ) {
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
}
if ( ! V_5 -> V_43 )
V_5 -> V_43 = F_58 ( V_156 * 32 ) ;
if ( V_5 -> V_43 ) {
memcpy ( V_5 -> V_43 , V_154 -> V_158 , V_156 * 32 ) ;
V_5 -> V_157 = V_156 ;
V_5 -> V_159 = V_154 -> V_36 ;
V_5 -> V_160 = ( V_156 == 512 ) ? 1 : 0 ;
}
return F_52 ( V_5 , 1 , 2 , V_154 -> V_158 ,
8192 , ( V_156 == 512 ) ,
( ! ( V_155 & V_161 ) ) ? 1 : 0 ,
V_2 , V_154 -> V_36 , 1 ) ;
}
static int
F_59 ( struct V_7 * V_2 , struct V_153 * V_154 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_125 ;
V_154 -> V_62 = 8 ;
V_154 -> V_36 = V_2 -> V_35 . V_36 ;
V_154 -> V_156 = 256 ;
if ( ! V_154 -> V_158 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( ! V_5 -> V_43 ) {
F_14 ( & V_5 -> V_19 ) ;
return - V_125 ;
}
memcpy ( V_154 -> V_158 , V_5 -> V_43 , 256 * 32 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
static const char * F_60 ( void )
{
return L_3 ;
}
static void F_61 ( struct V_7 * V_55 , int V_25 )
{
V_55 -> V_29 = 1 ;
if ( V_25 ) {
V_55 -> V_40 = 80 ;
V_55 -> V_41 = 25 ;
} else
F_20 ( V_55 , 80 , 25 ) ;
}
static int F_62 ( void )
{
return 0 ;
}
int
F_63 ( struct V_4 * V_5 , int V_162 , int V_163 )
{
int V_42 , V_83 ;
F_13 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_33 || ! V_5 -> V_164 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
V_5 -> V_165 = V_162 ;
V_5 -> V_166 = V_163 ;
if ( V_162 > V_163 ||
V_162 > V_44 ||
V_163 > V_44 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
if ( ! V_5 -> V_167 || V_162 < 1 || V_163 < 1 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
V_5 -> V_12 = - 1 ;
V_5 -> V_108 = - 1 ;
V_5 -> V_99 = - 1 ;
if ( F_64 ( V_5 , 1 ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_65 ( & V_5 -> V_18 -> V_69 , L_4 ) ;
return 1 ;
}
F_3 ( V_5 ) ;
for ( V_42 = V_162 - 1 ; V_42 <= V_163 - 1 ; V_42 ++ ) {
V_15 [ V_42 ] = V_5 ;
}
V_5 -> V_66 = 80 ;
V_5 -> V_71 = 32 * 1024 ;
if ( ! ( V_5 -> V_10 = ( unsigned long ) F_58 ( V_5 -> V_71 ) ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_65 ( & V_5 -> V_18 -> V_69 , L_5 ) ;
return 1 ;
}
F_14 ( & V_5 -> V_19 ) ;
F_66 () ;
V_83 = F_67 ( & V_143 , V_162 - 1 , V_163 - 1 , 0 ) ;
F_68 () ;
if ( ! V_83 )
V_5 -> V_33 = 1 ;
else {
for ( V_42 = V_162 - 1 ; V_42 <= V_163 - 1 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
return V_83 ;
}
void
F_69 ( struct V_4 * V_5 )
{
int V_42 ;
if ( V_5 -> V_33 ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
if ( V_5 -> V_20 [ V_42 ] ) {
F_66 () ;
F_67 ( & V_168 , V_42 , V_42 , 0 ) ;
F_68 () ;
}
V_5 -> V_33 = 0 ;
}
F_22 ( ( void * ) V_5 -> V_10 ) ;
V_5 -> V_10 = 0 ;
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
void T_3 F_70 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
