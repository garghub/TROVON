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
int V_93 = V_2 -> V_94 * 4 ;
int V_95 , V_96 , V_56 , V_97 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
if ( ! V_92 )
V_2 -> V_9 = V_2 -> V_67 ;
else {
if ( V_5 -> V_98 >
( V_2 -> V_99 - V_5 -> V_10 ) + V_93 ) {
V_95 = V_2 -> V_99 - V_5 -> V_10 ;
V_96 = V_5 -> V_98 + V_2 -> V_94 ;
} else {
V_95 = 0 ;
V_96 = V_5 -> V_71 ;
}
V_56 = ( V_2 -> V_9 - V_5 -> V_10 - V_95 + V_96 ) % V_96 +
V_92 * V_2 -> V_94 ;
V_97 = ( V_2 -> V_67 - V_5 -> V_10 - V_95 + V_96 ) % V_96 ;
if ( V_97 < 2 * V_93 )
V_93 = 0 ;
if ( V_56 < V_93 )
V_56 = 0 ;
if ( V_56 > V_97 - V_93 )
V_56 = V_97 ;
V_2 -> V_9 = V_5 -> V_10 + ( V_56 + V_95 ) % V_96 ;
}
F_5 ( V_5 , V_2 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_43 ( struct V_7 * V_2 , int V_100 )
{
struct V_4 * V_5 ;
int V_101 , V_102 , V_103 ;
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
if ( V_100 == V_104 ) {
F_44 ( V_5 , V_6 , 0x0a , 0x20 ) ;
V_5 -> V_105 = - 1 ;
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_6 ( V_5 , ( V_2 -> V_106 - V_5 -> V_10 ) / 2 ) ;
V_103 = V_2 -> V_35 . V_36 - ( V_2 -> V_35 . V_36 < 10 ? 1 : 2 ) ;
switch ( V_2 -> V_107 & 0x0f ) {
case V_108 : V_101 = 1 ;
V_102 = V_2 -> V_35 . V_36 ;
break;
case V_109 : V_101 = V_2 -> V_35 . V_36 / 3 ;
V_102 = V_103 ;
break;
case V_110 : V_101 = V_2 -> V_35 . V_36 / 2 ;
V_102 = V_103 ;
break;
case V_111 : V_101 = ( V_2 -> V_35 . V_36 * 2 ) / 3 ;
V_102 = V_103 ;
break;
case V_112 : V_101 = 31 ;
V_102 = 30 ;
break;
default:
case V_113 : V_101 = V_103 - 1 ;
V_102 = V_103 ;
break;
}
if ( V_5 -> V_114 != V_101 ||
V_5 -> V_105 != V_102 ) {
F_4 ( V_5 , V_6 , 0x0a , V_101 ) ;
F_7 ( V_5 , V_6 , 0x0b , 0xe0 , V_102 ) ;
V_5 -> V_114 = V_101 ;
V_5 -> V_105 = V_102 ;
}
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_45 ( struct V_7 * V_2 , struct V_4 * V_5 ,
int V_115 , int V_116 , int V_117 , int V_92 )
{
int V_26 = V_5 -> V_66 ;
int V_65 = ( ( V_116 - V_115 ) * V_26 ) * 2 ;
T_1 V_63 = V_2 -> V_64 ;
switch ( V_117 ) {
case V_118 :
F_46 ( F_29 ( 0 , V_115 ) ,
F_29 ( 0 , V_115 + V_92 ) ,
( V_116 - V_115 - V_92 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_116 - V_92 ) , V_63 ,
V_92 * V_26 * 2 ) ;
break;
case V_119 :
F_46 ( F_29 ( 0 , V_115 + V_92 ) ,
F_29 ( 0 , V_115 ) ,
( V_116 - V_115 - V_92 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_115 ) , V_63 ,
V_92 * V_26 * 2 ) ;
break;
}
F_28 ( V_5 , ( char * ) F_29 ( 0 , V_115 ) ,
( long ) F_30 ( 0 , V_115 ) , V_65 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_47 ( struct V_7 * V_2 , int V_115 , int V_116 , int V_117 , int V_92 )
{
struct V_4 * V_5 ;
T_1 V_63 = V_2 -> V_64 ;
int V_120 = 0 ;
unsigned long V_121 ;
unsigned int V_122 = V_92 * V_2 -> V_94 ;
V_84 V_123 ;
if ( ! V_92 )
return 1 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( V_115 || V_116 != V_2 -> V_41 )
return F_45 ( V_2 , V_5 , V_115 , V_116 , V_117 , V_92 ) ;
if ( V_2 -> V_67 != V_2 -> V_9 ) {
V_2 -> V_9 = V_2 -> V_67 ;
F_5 ( V_5 , V_2 ) ;
}
if ( V_92 > V_2 -> V_41 )
V_92 = V_2 -> V_41 ;
V_121 = V_2 -> V_67 ;
switch ( V_117 ) {
case V_118 :
if ( V_2 -> V_99 + V_122 >=
V_5 -> V_10 + V_5 -> V_71 ) {
F_36 ( ( T_1 * ) V_5 -> V_10 ,
( T_1 * ) ( V_121 + V_122 ) ,
V_2 -> V_70 - V_122 ) ;
V_2 -> V_67 = V_5 -> V_10 ;
V_5 -> V_98 = V_121 - V_5 -> V_10 ;
V_120 = 1 ;
} else
V_2 -> V_67 += V_122 ;
F_1 (
( T_1 * ) ( V_2 -> V_67 + V_2 -> V_70 - V_122 ) ,
V_63 , V_122 ) ;
break;
case V_119 :
if ( V_121 - V_122 < V_5 -> V_10 ) {
F_46 ( ( T_1 * ) ( V_5 -> V_10 +
V_5 -> V_71 -
V_2 -> V_70 +
V_122 ) ,
( T_1 * ) V_121 ,
V_2 -> V_70 - V_122 ) ;
V_2 -> V_67 = V_5 -> V_10 +
V_5 -> V_71 -
V_2 -> V_70 ;
V_5 -> V_98 = 0 ;
V_120 = 1 ;
} else
V_2 -> V_67 -= V_122 ;
V_2 -> V_99 = V_2 -> V_67 + V_2 -> V_70 ;
F_48 ( ( T_1 * ) ( V_2 -> V_67 ) , V_63 , V_122 ) ;
break;
}
V_123 = ( V_84 ) ( V_2 -> V_67 - V_5 -> V_10 ) ;
if ( V_120 )
F_28 ( V_5 ,
( char * ) V_2 -> V_67 ,
( V_84 ) ( V_5 -> V_85 + V_123 ) ,
V_2 -> V_70 ) ;
else if ( V_117 == V_118 )
F_28 ( V_5 ,
( char * ) V_2 -> V_67 + V_2 -> V_70 - V_122 ,
( V_84 ) V_5 -> V_85 + V_123 +
V_2 -> V_70 - V_122 ,
V_122 ) ;
else
F_28 ( V_5 ,
( char * ) V_2 -> V_67 ,
( V_84 ) ( V_5 -> V_85 + V_123 ) ,
V_122 ) ;
V_2 -> V_99 = V_2 -> V_67 + V_2 -> V_70 ;
V_2 -> V_9 = V_2 -> V_67 ;
F_5 ( V_5 , V_2 ) ;
V_2 -> V_106 = V_2 -> V_106 - V_121 + V_2 -> V_67 ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_49 ( struct V_7 * V_2 )
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
V_5 -> V_98 = 0 ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_50 ( struct V_7 * V_2 , unsigned int V_124 , unsigned int V_125 ,
unsigned int V_126 )
{
struct V_4 * V_5 ;
int V_127 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_128 ;
V_127 = V_5 -> V_37 ;
F_14 ( & V_5 -> V_19 ) ;
if ( V_124 != 80 || V_2 -> V_34 / V_127 != V_125 )
return - V_90 ;
return 0 ;
}
int
F_51 ( struct V_4 * V_5 , int V_129 , int V_130 ,
T_2 * V_131 , int V_132 , int V_133 , int V_134 ,
struct V_7 * V_2 , int V_127 , int V_135 )
{
int V_136 = 0x00 , V_42 , V_137 = 0 ;
V_84 V_138 = 0 ;
T_2 V_139 ;
if ( ( V_130 != 0 && V_130 != 2 ) || ! V_127 ) {
if ( V_135 )
F_14 ( & V_5 -> V_19 ) ;
return - V_90 ;
}
if ( V_129 )
V_5 -> V_140 = V_130 ;
if ( V_130 == 0 )
V_133 = 0 ;
else
V_138 = 4 * V_132 ;
V_136 = ( V_130 == 0 ) ? 0x00 : ( V_133 ? 0x0e : 0x0a ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x00 , 0x01 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x02 , 0x04 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x04 , 0x07 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x00 , 0x03 ) ;
if ( V_137 )
goto V_141;
V_137 |= F_4 ( V_5 , V_142 , 0x04 , 0x03 ) ;
V_137 |= F_4 ( V_5 , V_142 , 0x05 , 0x00 ) ;
V_137 |= F_4 ( V_5 , V_142 , 0x06 , 0x00 ) ;
if ( V_137 )
goto V_141;
if ( V_131 ) {
if ( V_129 )
for ( V_42 = 0 ; V_42 < V_132 ; V_42 ++ ) {
V_137 |= F_52 ( V_5 ,
V_5 -> V_85 + V_138 + V_42 ,
V_131 [ V_42 ] ) ;
if ( V_137 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_132 ; V_42 ++ ) {
V_137 |= F_53 ( V_5 ,
V_5 -> V_85 + V_138 + V_42 ,
& V_131 [ V_42 ] ) ;
if ( V_137 )
break;
}
if ( V_133 ) {
if ( V_129 )
for ( V_42 = 0 ; V_42 < V_132 ; V_42 ++ ) {
V_137 |= F_52 ( V_5 ,
V_5 -> V_85 + V_138 +
( 2 * V_132 ) + V_42 ,
V_131 [ V_132 + V_42 ] ) ;
if ( V_137 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_132 ; V_42 ++ ) {
V_137 |= F_53 ( V_5 ,
V_5 -> V_85 + V_138 +
( 2 * V_132 ) + V_42 ,
& V_131 [ V_132 + V_42 ] ) ;
if ( V_137 )
break;
}
}
}
if ( V_137 )
goto V_141;
V_137 |= F_4 ( V_5 , V_91 , 0x00 , 0x01 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x02 , 0x03 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x04 , 0x03 ) ;
if ( V_129 )
F_4 ( V_5 , V_91 , 0x03 , V_136 ) ;
V_137 |= F_4 ( V_5 , V_91 , 0x00 , 0x03 ) ;
if ( V_137 )
goto V_141;
V_137 |= F_4 ( V_5 , V_142 , 0x04 , 0x00 ) ;
V_137 |= F_4 ( V_5 , V_142 , 0x05 , 0x10 ) ;
V_137 |= F_4 ( V_5 , V_142 , 0x06 , 0x06 ) ;
if ( V_137 )
goto V_141;
if ( ( V_129 ) && ( V_133 != V_5 -> V_32 ) ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_143 = V_144 [ V_42 ] . V_143 ;
if ( V_143 && V_143 -> V_145 == & V_146 )
V_143 -> V_31 = V_133 ? 0x0800 : 0 ;
}
V_5 -> V_32 = V_133 ;
F_54 ( V_5 , V_147 , & V_139 ) ;
F_40 ( V_5 , V_148 , 0x12 ) ;
F_40 ( V_5 , V_148 , V_133 ? 0x07 : 0x0f ) ;
F_54 ( V_5 , V_147 , & V_139 ) ;
F_40 ( V_5 , V_148 , 0x20 ) ;
F_54 ( V_5 , V_147 , & V_139 ) ;
}
if ( V_134 ) {
unsigned char V_149 , V_150 , V_151 ;
int V_27 = 0 , V_152 = 0 ;
if ( V_2 ) {
V_27 = V_2 -> V_34 / V_127 ;
V_152 = V_27 * V_127 - 1 ;
F_55 ( V_5 , V_6 , 0x07 , & V_149 ) ;
V_150 = V_152 & 0xff ;
V_149 = ( V_149 & 0xbd ) |
( ( V_152 & 0x100 ) >> 7 ) |
( ( V_152 & 0x200 ) >> 3 ) ;
F_4 ( V_5 , V_6 , 0x07 , V_149 ) ;
F_4 ( V_5 , V_6 , 0x12 , V_150 ) ;
}
F_55 ( V_5 , V_6 , 0x09 , & V_151 ) ;
V_151 = ( V_151 & 0xe0 ) | ( V_127 - 1 ) ;
F_4 ( V_5 , V_6 , 0x09 , V_151 ) ;
V_5 -> V_37 = V_127 ;
V_5 -> V_114 = - 1 ;
V_5 -> V_105 = - 1 ;
}
if ( V_135 )
F_14 ( & V_5 -> V_19 ) ;
if ( V_134 && V_2 ) {
int V_27 = V_2 -> V_34 / V_127 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_55 = V_144 [ V_42 ] . V_143 ;
if ( V_55 && V_55 -> V_145 == & V_146 ) {
if ( F_39 ( V_55 ) ) {
V_55 -> V_145 -> V_153 ( V_55 , V_154 ) ;
}
V_55 -> V_35 . V_36 = V_127 ;
F_20 ( V_55 , 0 , V_27 ) ;
}
}
}
return 0 ;
V_141:
if ( V_135 )
F_14 ( & V_5 -> V_19 ) ;
return - V_155 ;
}
static int
F_56 ( struct V_7 * V_2 , struct V_156 * V_157 ,
unsigned V_158 )
{
struct V_4 * V_5 ;
unsigned V_159 = V_157 -> V_159 ;
if ( V_157 -> V_62 != 8 || ( V_159 != 256 && V_159 != 512 ) )
return - V_90 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_128 ;
if ( V_5 -> V_43 ) {
if ( V_5 -> V_160 < V_159 ) {
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
}
if ( ! V_5 -> V_43 )
V_5 -> V_43 = F_57 ( V_159 * 32 ) ;
if ( V_5 -> V_43 ) {
memcpy ( V_5 -> V_43 , V_157 -> V_161 , V_159 * 32 ) ;
V_5 -> V_160 = V_159 ;
V_5 -> V_162 = V_157 -> V_36 ;
V_5 -> V_163 = ( V_159 == 512 ) ? 1 : 0 ;
}
return F_51 ( V_5 , 1 , 2 , V_157 -> V_161 ,
8192 , ( V_159 == 512 ) ,
( ! ( V_158 & V_164 ) ) ? 1 : 0 ,
V_2 , V_157 -> V_36 , 1 ) ;
}
static int
F_58 ( struct V_7 * V_2 , struct V_156 * V_157 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_128 ;
V_157 -> V_62 = 8 ;
V_157 -> V_36 = V_2 -> V_35 . V_36 ;
V_157 -> V_159 = 256 ;
if ( ! V_157 -> V_161 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( ! V_5 -> V_43 ) {
F_14 ( & V_5 -> V_19 ) ;
return - V_128 ;
}
memcpy ( V_157 -> V_161 , V_5 -> V_43 , 256 * 32 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
static const char * F_59 ( void )
{
return L_3 ;
}
static void F_60 ( struct V_7 * V_55 , int V_25 )
{
V_55 -> V_29 = 1 ;
if ( V_25 ) {
V_55 -> V_40 = 80 ;
V_55 -> V_41 = 25 ;
} else
F_20 ( V_55 , 80 , 25 ) ;
}
static int F_61 ( void )
{
return 0 ;
}
int
F_62 ( struct V_4 * V_5 , int V_165 , int V_166 )
{
int V_42 , V_83 ;
F_13 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_33 || ! V_5 -> V_167 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
V_5 -> V_168 = V_165 ;
V_5 -> V_169 = V_166 ;
if ( V_165 > V_166 ||
V_165 > V_44 ||
V_166 > V_44 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
if ( ! V_5 -> V_170 || V_165 < 1 || V_166 < 1 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
V_5 -> V_12 = - 1 ;
V_5 -> V_114 = - 1 ;
V_5 -> V_105 = - 1 ;
if ( F_63 ( V_5 , 1 ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_64 ( & V_5 -> V_18 -> V_69 , L_4 ) ;
return 1 ;
}
F_3 ( V_5 ) ;
for ( V_42 = V_165 - 1 ; V_42 <= V_166 - 1 ; V_42 ++ ) {
V_15 [ V_42 ] = V_5 ;
}
V_5 -> V_66 = 80 ;
V_5 -> V_71 = 32 * 1024 ;
if ( ! ( V_5 -> V_10 = ( unsigned long ) F_57 ( V_5 -> V_71 ) ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_64 ( & V_5 -> V_18 -> V_69 , L_5 ) ;
return 1 ;
}
F_14 ( & V_5 -> V_19 ) ;
F_65 () ;
V_83 = F_66 ( & V_146 , V_165 - 1 , V_166 - 1 , 0 ) ;
F_67 () ;
if ( ! V_83 )
V_5 -> V_33 = 1 ;
else {
for ( V_42 = V_165 - 1 ; V_42 <= V_166 - 1 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
return V_83 ;
}
void
F_68 ( struct V_4 * V_5 )
{
int V_42 ;
if ( V_5 -> V_33 ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
if ( V_5 -> V_20 [ V_42 ] ) {
F_65 () ;
F_66 ( & V_171 , V_42 , V_42 , 0 ) ;
F_67 () ;
}
V_5 -> V_33 = 0 ;
}
F_22 ( ( void * ) V_5 -> V_10 ) ;
V_5 -> V_10 = 0 ;
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
void T_3 F_69 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
