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
T_3 V_61 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_28 ( V_5 , ( char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , 2 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_31 ( struct V_7 * V_2 , const unsigned short * V_1 ,
int V_3 , int V_59 , int V_60 )
{
struct V_4 * V_5 ;
T_3 V_61 ;
T_1 * V_62 ;
int V_42 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
V_62 = F_29 ( V_60 , V_59 ) ;
for ( V_42 = V_3 ; V_42 > 0 ; V_42 -- )
F_2 ( F_26 ( V_1 ++ ) , V_62 ++ ) ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_28 ( V_5 , ( char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , V_3 * 2 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_32 ( struct V_7 * V_2 , int V_59 , int V_60 , int V_36 , int V_63 )
{
struct V_4 * V_5 ;
T_1 V_64 = V_2 -> V_65 ;
T_3 V_61 ;
int V_42 , V_66 , V_26 ;
T_1 * V_62 ;
if ( V_63 <= 0 || V_36 <= 0 )
return;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
V_62 = F_29 ( V_60 , V_59 ) ;
V_26 = V_5 -> V_67 ;
if ( V_63 > V_26 )
V_63 = V_26 ;
if ( V_60 == 0 && V_63 >= V_2 -> V_40 ) {
F_1 ( V_62 , V_64 , V_36 * V_26 * 2 ) ;
} else {
for ( V_42 = V_36 ; V_42 > 0 ; V_42 -- , V_62 += V_26 )
F_1 ( V_62 , V_64 , V_63 * 2 ) ;
}
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_66 = ( ( V_36 * V_26 ) - V_60 - ( V_26 - V_63 - V_60 ) ) * 2 ;
F_28 ( V_5 , ( unsigned char * ) F_29 ( V_60 , V_59 ) ,
( long ) F_30 ( V_60 , V_59 ) , V_66 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static void
F_33 ( struct V_7 * V_2 , int V_68 , int V_69 ,
int V_70 , int V_71 , int V_36 , int V_63 )
{
struct V_4 * V_5 ;
T_3 V_61 ;
int V_26 , V_66 ;
if ( V_63 <= 0 || V_36 <= 0 )
return;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
V_26 = V_5 -> V_67 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_66 = ( ( V_36 * V_26 ) - V_71 - ( V_26 - V_63 - V_71 ) ) * 2 ;
F_28 ( V_5 , ( unsigned char * ) F_29 ( V_71 , V_70 ) ,
( long ) F_30 ( V_71 , V_70 ) , V_66 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_34 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
T_3 V_61 ;
int V_66 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( V_2 -> V_72 == ( unsigned long ) V_2 -> V_73 ) {
F_14 ( & V_5 -> V_19 ) ;
F_35 ( & V_5 -> V_18 -> V_74 , L_2 ) ;
return 0 ;
}
V_66 = F_36 ( ( int ) V_2 -> V_75 ,
( int ) ( V_5 -> V_10 + V_5 -> V_76 - V_2 -> V_72 ) ) ;
F_37 ( ( T_1 * ) V_2 -> V_72 , ( T_1 * ) V_2 -> V_73 ,
V_66 ) ;
F_28 ( V_5 , ( unsigned char * ) V_2 -> V_72 ,
( long ) F_30 ( 0 , 0 ) ,
V_66 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
static void
F_38 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
int V_66 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
V_66 = F_36 ( ( int ) V_2 -> V_75 ,
( int ) ( V_5 -> V_10 + V_5 -> V_76 - V_2 -> V_72 ) ) ;
F_37 ( ( T_1 * ) V_2 -> V_73 , ( T_1 * ) V_2 -> V_72 ,
V_66 ) ;
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_39 ( struct V_7 * V_2 , unsigned char * V_77 )
{
struct V_4 * V_5 ;
int V_42 , V_78 ;
if ( ! F_40 ( V_2 ) )
return - V_79 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_79 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return - V_79 ;
}
for ( V_42 = V_78 = 0 ; V_42 < 16 ; V_42 ++ ) {
if ( F_41 ( V_5 , V_80 , V_77 [ V_42 ] ) )
break;
if ( F_41 ( V_5 , V_81 , V_2 -> V_82 [ V_78 ++ ] >> 2 ) )
break;
if ( F_41 ( V_5 , V_81 , V_2 -> V_82 [ V_78 ++ ] >> 2 ) )
break;
if ( F_41 ( V_5 , V_81 , V_2 -> V_82 [ V_78 ++ ] >> 2 ) )
break;
}
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
static int
F_42 ( struct V_7 * V_2 , int V_83 , int V_84 )
{
struct V_4 * V_5 ;
T_2 V_85 , V_86 , V_87 , V_88 ;
T_3 V_61 ;
int V_89 = 0 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( V_84 )
V_5 -> V_21 = V_83 ? 1 : 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
switch ( V_83 ) {
case 1 :
case - 1 :
F_1 ( ( T_1 * ) V_2 -> V_72 ,
V_2 -> V_65 ,
V_2 -> V_75 ) ;
F_28 ( V_5 ,
( unsigned char * ) V_2 -> V_72 ,
( V_90 ) ( V_5 -> V_91 +
( V_2 -> V_72 - V_5 -> V_10 ) ) ,
V_2 -> V_75 , & V_61 ) ;
V_5 -> V_92 = 1 ;
V_89 = 1 ;
break;
default:
switch ( V_83 ) {
case 0 :
V_85 = 0x00 ;
V_86 = 0x80 ;
V_87 = 0x00 ;
V_88 = 0x00 ;
V_89 = 1 ;
V_5 -> V_92 = 0 ;
break;
case V_93 + 1 :
V_85 = 0x20 ;
V_86 = 0x80 ;
V_87 = 0x80 ;
V_88 = 0x40 ;
break;
case V_94 + 1 :
V_85 = 0x20 ;
V_86 = 0x80 ;
V_87 = 0x40 ;
V_88 = 0x40 ;
break;
case V_95 + 1 :
V_85 = 0x20 ;
V_86 = 0x00 ;
V_87 = 0xc0 ;
V_88 = 0x40 ;
break;
default:
F_14 ( & V_5 -> V_19 ) ;
return - V_79 ;
}
F_7 ( V_5 , V_96 , 0x01 , ~ 0x20 , V_85 ) ;
F_7 ( V_5 , V_6 , 0x17 , 0x7f , V_86 ) ;
F_7 ( V_5 , V_96 , 0x1f , 0x3f , V_87 ) ;
F_7 ( V_5 , V_6 , 0x63 , 0xbf , V_88 ) ;
}
F_14 ( & V_5 -> V_19 ) ;
return V_89 ;
}
static int
F_43 ( struct V_7 * V_2 , int V_97 )
{
struct V_4 * V_5 ;
int V_98 = V_2 -> V_99 * 4 ;
int V_100 , V_101 , V_56 , V_102 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( ! V_97 )
V_2 -> V_9 = V_2 -> V_72 ;
else {
if ( V_5 -> V_103 >
( V_2 -> V_104 - V_5 -> V_10 ) + V_98 ) {
V_100 = V_2 -> V_104 - V_5 -> V_10 ;
V_101 = V_5 -> V_103 + V_2 -> V_99 ;
} else {
V_100 = 0 ;
V_101 = V_5 -> V_76 ;
}
V_56 = ( V_2 -> V_9 - V_5 -> V_10 - V_100 + V_101 ) % V_101 +
V_97 * V_2 -> V_99 ;
V_102 = ( V_2 -> V_72 - V_5 -> V_10 - V_100 + V_101 ) % V_101 ;
if ( V_102 < 2 * V_98 )
V_98 = 0 ;
if ( V_56 < V_98 )
V_56 = 0 ;
if ( V_56 > V_102 - V_98 )
V_56 = V_102 ;
V_2 -> V_9 = V_5 -> V_10 + ( V_56 + V_100 ) % V_101 ;
}
F_5 ( V_5 , V_2 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static void
F_44 ( struct V_7 * V_2 , int V_105 )
{
struct V_4 * V_5 ;
int V_106 , V_107 , V_108 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return;
}
if ( V_2 -> V_72 != V_2 -> V_9 ) {
V_2 -> V_9 = V_2 -> V_72 ;
F_5 ( V_5 , V_2 ) ;
}
if ( V_105 == V_109 ) {
F_45 ( V_5 , V_6 , 0x0a , 0x20 ) ;
V_5 -> V_110 = - 1 ;
F_14 ( & V_5 -> V_19 ) ;
return;
}
F_6 ( V_5 , ( V_2 -> V_111 - V_5 -> V_10 ) / 2 ) ;
V_108 = V_2 -> V_35 . V_36 - ( V_2 -> V_35 . V_36 < 10 ? 1 : 2 ) ;
switch ( V_2 -> V_112 & 0x0f ) {
case V_113 : V_106 = 1 ;
V_107 = V_2 -> V_35 . V_36 ;
break;
case V_114 : V_106 = V_2 -> V_35 . V_36 / 3 ;
V_107 = V_108 ;
break;
case V_115 : V_106 = V_2 -> V_35 . V_36 / 2 ;
V_107 = V_108 ;
break;
case V_116 : V_106 = ( V_2 -> V_35 . V_36 * 2 ) / 3 ;
V_107 = V_108 ;
break;
case V_117 : V_106 = 31 ;
V_107 = 30 ;
break;
default:
case V_118 : V_106 = V_108 - 1 ;
V_107 = V_108 ;
break;
}
if ( V_5 -> V_119 != V_106 ||
V_5 -> V_110 != V_107 ) {
F_4 ( V_5 , V_6 , 0x0a , V_106 ) ;
F_7 ( V_5 , V_6 , 0x0b , 0xe0 , V_107 ) ;
V_5 -> V_119 = V_106 ;
V_5 -> V_110 = V_107 ;
}
F_14 ( & V_5 -> V_19 ) ;
}
static int
F_46 ( struct V_7 * V_2 , struct V_4 * V_5 ,
int V_120 , int V_121 , int V_122 , int V_97 )
{
int V_26 = V_5 -> V_67 ;
int V_66 = ( ( V_121 - V_120 ) * V_26 ) * 2 ;
T_1 V_64 = V_2 -> V_65 ;
T_3 V_61 ;
switch ( V_122 ) {
case V_123 :
F_47 ( F_29 ( 0 , V_120 ) ,
F_29 ( 0 , V_120 + V_97 ) ,
( V_121 - V_120 - V_97 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_121 - V_97 ) , V_64 ,
V_97 * V_26 * 2 ) ;
break;
case V_124 :
F_47 ( F_29 ( 0 , V_120 + V_97 ) ,
F_29 ( 0 , V_120 ) ,
( V_121 - V_120 - V_97 ) * V_26 * 2 ) ;
F_1 ( F_29 ( 0 , V_120 ) , V_64 ,
V_97 * V_26 * 2 ) ;
break;
}
F_28 ( V_5 , ( char * ) F_29 ( 0 , V_120 ) ,
( long ) F_30 ( 0 , V_120 ) , V_66 , & V_61 ) ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_48 ( struct V_7 * V_2 , int V_120 , int V_121 , int V_122 , int V_97 )
{
struct V_4 * V_5 ;
T_1 V_64 = V_2 -> V_65 ;
T_3 V_61 ;
int V_125 = 0 ;
unsigned long V_126 ;
unsigned int V_127 = V_97 * V_2 -> V_99 ;
V_90 V_128 ;
if ( ! V_97 )
return 1 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( V_120 || V_121 != V_2 -> V_41 )
return F_46 ( V_2 , V_5 , V_120 , V_121 , V_122 , V_97 ) ;
if ( V_2 -> V_72 != V_2 -> V_9 ) {
V_2 -> V_9 = V_2 -> V_72 ;
F_5 ( V_5 , V_2 ) ;
}
if ( V_97 > V_2 -> V_41 )
V_97 = V_2 -> V_41 ;
V_126 = V_2 -> V_72 ;
switch ( V_122 ) {
case V_123 :
if ( V_2 -> V_104 + V_127 >=
V_5 -> V_10 + V_5 -> V_76 ) {
F_37 ( ( T_1 * ) V_5 -> V_10 ,
( T_1 * ) ( V_126 + V_127 ) ,
V_2 -> V_75 - V_127 ) ;
V_2 -> V_72 = V_5 -> V_10 ;
V_5 -> V_103 = V_126 - V_5 -> V_10 ;
V_125 = 1 ;
} else
V_2 -> V_72 += V_127 ;
F_1 (
( T_1 * ) ( V_2 -> V_72 + V_2 -> V_75 - V_127 ) ,
V_64 , V_127 ) ;
break;
case V_124 :
if ( V_126 - V_127 < V_5 -> V_10 ) {
F_47 ( ( T_1 * ) ( V_5 -> V_10 +
V_5 -> V_76 -
V_2 -> V_75 +
V_127 ) ,
( T_1 * ) V_126 ,
V_2 -> V_75 - V_127 ) ;
V_2 -> V_72 = V_5 -> V_10 +
V_5 -> V_76 -
V_2 -> V_75 ;
V_5 -> V_103 = 0 ;
V_125 = 1 ;
} else
V_2 -> V_72 -= V_127 ;
V_2 -> V_104 = V_2 -> V_72 + V_2 -> V_75 ;
F_49 ( ( T_1 * ) ( V_2 -> V_72 ) , V_64 , V_127 ) ;
break;
}
V_128 = ( V_90 ) ( V_2 -> V_72 - V_5 -> V_10 ) ;
if ( V_125 )
F_28 ( V_5 ,
( char * ) V_2 -> V_72 ,
( V_90 ) ( V_5 -> V_91 + V_128 ) ,
V_2 -> V_75 , & V_61 ) ;
else if ( V_122 == V_123 )
F_28 ( V_5 ,
( char * ) V_2 -> V_72 + V_2 -> V_75 - V_127 ,
( V_90 ) V_5 -> V_91 + V_128 +
V_2 -> V_75 - V_127 ,
V_127 , & V_61 ) ;
else
F_28 ( V_5 ,
( char * ) V_2 -> V_72 ,
( V_90 ) ( V_5 -> V_91 + V_128 ) ,
V_127 , & V_61 ) ;
V_2 -> V_104 = V_2 -> V_72 + V_2 -> V_75 ;
V_2 -> V_9 = V_2 -> V_72 ;
F_5 ( V_5 , V_2 ) ;
V_2 -> V_111 = V_2 -> V_111 - V_126 + V_2 -> V_72 ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_50 ( struct V_7 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return 0 ;
if ( F_15 ( V_2 , V_5 ) || V_5 -> V_92 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
V_2 -> V_72 = V_2 -> V_9 = V_5 -> V_10 ;
F_5 ( V_5 , V_2 ) ;
V_5 -> V_103 = 0 ;
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
static int
F_51 ( struct V_7 * V_2 , unsigned int V_129 , unsigned int V_130 ,
unsigned int V_131 )
{
struct V_4 * V_5 ;
int V_132 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_133 ;
V_132 = V_5 -> V_37 ;
F_14 ( & V_5 -> V_19 ) ;
if ( V_129 != 80 || V_2 -> V_34 / V_132 != V_130 )
return - V_79 ;
return 0 ;
}
int
F_52 ( struct V_4 * V_5 , int V_134 , int V_135 ,
T_2 * V_136 , int V_137 , int V_138 , int V_139 ,
struct V_7 * V_2 , int V_132 , int V_140 )
{
int V_141 = 0x00 , V_42 , V_142 = 0 ;
V_90 V_143 = 0 ;
T_2 V_144 ;
if ( ( V_135 != 0 && V_135 != 2 ) || ! V_132 ) {
if ( V_140 )
F_14 ( & V_5 -> V_19 ) ;
return - V_79 ;
}
if ( V_134 )
V_5 -> V_145 = V_135 ;
if ( V_135 == 0 )
V_138 = 0 ;
else
V_143 = 4 * V_137 ;
V_141 = ( V_135 == 0 ) ? 0x00 : ( V_138 ? 0x0e : 0x0a ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x00 , 0x01 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x02 , 0x04 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x04 , 0x07 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x00 , 0x03 ) ;
if ( V_142 )
goto V_146;
V_142 |= F_4 ( V_5 , V_147 , 0x04 , 0x03 ) ;
V_142 |= F_4 ( V_5 , V_147 , 0x05 , 0x00 ) ;
V_142 |= F_4 ( V_5 , V_147 , 0x06 , 0x00 ) ;
if ( V_142 )
goto V_146;
if ( V_136 ) {
if ( V_134 )
for ( V_42 = 0 ; V_42 < V_137 ; V_42 ++ ) {
V_142 |= F_53 ( V_5 ,
V_5 -> V_91 + V_143 + V_42 ,
V_136 [ V_42 ] ) ;
if ( V_142 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_137 ; V_42 ++ ) {
V_142 |= F_54 ( V_5 ,
V_5 -> V_91 + V_143 + V_42 ,
& V_136 [ V_42 ] ) ;
if ( V_142 )
break;
}
if ( V_138 ) {
if ( V_134 )
for ( V_42 = 0 ; V_42 < V_137 ; V_42 ++ ) {
V_142 |= F_53 ( V_5 ,
V_5 -> V_91 + V_143 +
( 2 * V_137 ) + V_42 ,
V_136 [ V_137 + V_42 ] ) ;
if ( V_142 )
break;
}
else
for ( V_42 = 0 ; V_42 < V_137 ; V_42 ++ ) {
V_142 |= F_54 ( V_5 ,
V_5 -> V_91 + V_143 +
( 2 * V_137 ) + V_42 ,
& V_136 [ V_137 + V_42 ] ) ;
if ( V_142 )
break;
}
}
}
if ( V_142 )
goto V_146;
V_142 |= F_4 ( V_5 , V_96 , 0x00 , 0x01 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x02 , 0x03 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x04 , 0x03 ) ;
if ( V_134 )
F_4 ( V_5 , V_96 , 0x03 , V_141 ) ;
V_142 |= F_4 ( V_5 , V_96 , 0x00 , 0x03 ) ;
if ( V_142 )
goto V_146;
V_142 |= F_4 ( V_5 , V_147 , 0x04 , 0x00 ) ;
V_142 |= F_4 ( V_5 , V_147 , 0x05 , 0x10 ) ;
V_142 |= F_4 ( V_5 , V_147 , 0x06 , 0x06 ) ;
if ( V_142 )
goto V_146;
if ( ( V_134 ) && ( V_138 != V_5 -> V_32 ) ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_148 = V_149 [ V_42 ] . V_148 ;
if ( V_148 && V_148 -> V_150 == & V_151 )
V_148 -> V_31 = V_138 ? 0x0800 : 0 ;
}
V_5 -> V_32 = V_138 ;
F_55 ( V_5 , V_152 , & V_144 ) ;
F_41 ( V_5 , V_153 , 0x12 ) ;
F_41 ( V_5 , V_153 , V_138 ? 0x07 : 0x0f ) ;
F_55 ( V_5 , V_152 , & V_144 ) ;
F_41 ( V_5 , V_153 , 0x20 ) ;
F_55 ( V_5 , V_152 , & V_144 ) ;
}
if ( V_139 ) {
unsigned char V_154 , V_155 , V_156 ;
int V_27 = 0 , V_157 = 0 ;
if ( V_2 ) {
V_27 = V_2 -> V_34 / V_132 ;
V_157 = V_27 * V_132 - 1 ;
F_56 ( V_5 , V_6 , 0x07 , & V_154 ) ;
V_155 = V_157 & 0xff ;
V_154 = ( V_154 & 0xbd ) |
( ( V_157 & 0x100 ) >> 7 ) |
( ( V_157 & 0x200 ) >> 3 ) ;
F_4 ( V_5 , V_6 , 0x07 , V_154 ) ;
F_4 ( V_5 , V_6 , 0x12 , V_155 ) ;
}
F_56 ( V_5 , V_6 , 0x09 , & V_156 ) ;
V_156 = ( V_156 & 0xe0 ) | ( V_132 - 1 ) ;
F_4 ( V_5 , V_6 , 0x09 , V_156 ) ;
V_5 -> V_37 = V_132 ;
V_5 -> V_119 = - 1 ;
V_5 -> V_110 = - 1 ;
}
if ( V_140 )
F_14 ( & V_5 -> V_19 ) ;
if ( V_139 && V_2 ) {
int V_27 = V_2 -> V_34 / V_132 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_7 * V_55 = V_149 [ V_42 ] . V_148 ;
if ( V_55 && V_55 -> V_150 == & V_151 ) {
if ( F_40 ( V_55 ) ) {
V_55 -> V_150 -> V_158 ( V_55 , V_159 ) ;
}
V_55 -> V_35 . V_36 = V_132 ;
F_20 ( V_55 , 0 , V_27 ) ;
}
}
}
return 0 ;
V_146:
if ( V_140 )
F_14 ( & V_5 -> V_19 ) ;
return - V_160 ;
}
static int
F_57 ( struct V_7 * V_2 , struct V_161 * V_162 ,
unsigned V_163 )
{
struct V_4 * V_5 ;
unsigned V_164 = V_162 -> V_164 ;
if ( V_162 -> V_63 != 8 || ( V_164 != 256 && V_164 != 512 ) )
return - V_79 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_133 ;
if ( V_5 -> V_43 ) {
if ( V_5 -> V_165 < V_164 ) {
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
}
if ( ! V_5 -> V_43 )
V_5 -> V_43 = F_58 ( V_164 * 32 ) ;
if ( V_5 -> V_43 ) {
memcpy ( V_5 -> V_43 , V_162 -> V_166 , V_164 * 32 ) ;
V_5 -> V_165 = V_164 ;
V_5 -> V_167 = V_162 -> V_36 ;
V_5 -> V_168 = ( V_164 == 512 ) ? 1 : 0 ;
}
return F_52 ( V_5 , 1 , 2 , V_162 -> V_166 ,
8192 , ( V_164 == 512 ) ,
( ! ( V_163 & V_169 ) ) ? 1 : 0 ,
V_2 , V_162 -> V_36 , 1 ) ;
}
static int
F_59 ( struct V_7 * V_2 , struct V_161 * V_162 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( V_2 -> V_28 ) ;
if ( ! V_5 )
return - V_133 ;
V_162 -> V_63 = 8 ;
V_162 -> V_36 = V_2 -> V_35 . V_36 ;
V_162 -> V_164 = 256 ;
if ( ! V_162 -> V_166 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
if ( ! V_5 -> V_43 ) {
F_14 ( & V_5 -> V_19 ) ;
return - V_133 ;
}
memcpy ( V_162 -> V_166 , V_5 -> V_43 , 256 * 32 ) ;
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
F_63 ( struct V_4 * V_5 , int V_170 , int V_171 )
{
int V_42 , V_89 ;
F_13 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_33 || ! V_5 -> V_172 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
V_5 -> V_173 = V_170 ;
V_5 -> V_174 = V_171 ;
if ( V_170 > V_171 ||
V_170 > V_44 ||
V_171 > V_44 ) {
F_14 ( & V_5 -> V_19 ) ;
return 1 ;
}
if ( ! V_5 -> V_175 || V_170 < 1 || V_171 < 1 ) {
F_14 ( & V_5 -> V_19 ) ;
return 0 ;
}
V_5 -> V_12 = - 1 ;
V_5 -> V_119 = - 1 ;
V_5 -> V_110 = - 1 ;
if ( F_64 ( V_5 , 1 ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_65 ( & V_5 -> V_18 -> V_74 , L_4 ) ;
return 1 ;
}
F_3 ( V_5 ) ;
for ( V_42 = V_170 - 1 ; V_42 <= V_171 - 1 ; V_42 ++ ) {
V_15 [ V_42 ] = V_5 ;
}
V_5 -> V_67 = 80 ;
V_5 -> V_76 = 32 * 1024 ;
if ( ! ( V_5 -> V_10 = ( unsigned long ) F_58 ( V_5 -> V_76 ) ) ) {
F_14 ( & V_5 -> V_19 ) ;
F_65 ( & V_5 -> V_18 -> V_74 , L_5 ) ;
return 1 ;
}
F_14 ( & V_5 -> V_19 ) ;
F_66 () ;
V_89 = F_67 ( & V_151 , V_170 - 1 , V_171 - 1 , 0 ) ;
F_68 () ;
if ( ! V_89 )
V_5 -> V_33 = 1 ;
else {
for ( V_42 = V_170 - 1 ; V_42 <= V_171 - 1 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
return V_89 ;
}
void
F_69 ( struct V_4 * V_5 )
{
int V_42 ;
if ( V_5 -> V_33 ) {
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
if ( V_5 -> V_20 [ V_42 ] ) {
F_66 () ;
F_67 ( & V_176 , V_42 , V_42 , 0 ) ;
F_68 () ;
}
V_5 -> V_33 = 0 ;
}
F_22 ( ( void * ) V_5 -> V_10 ) ;
V_5 -> V_10 = 0 ;
F_22 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
}
void T_4 F_70 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
V_15 [ V_42 ] = NULL ;
}
