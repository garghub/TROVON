static unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_5 , unsigned int * V_6 )
{
unsigned int V_7 ;
V_7 = F_2 ( V_2 , V_3 , 0 , V_4 , V_5 ) ;
* V_6 = V_7 ;
return ( ( V_7 == - 1 ) ? - 1 : 0 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned short V_8 , unsigned int * V_6 )
{
return F_1 ( V_2 , V_3 , V_9 ,
V_8 & 0xffff , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned char V_10 ,
unsigned char V_11 , unsigned int * V_6 )
{
unsigned char V_12 = 0 ;
V_12 = ( V_10 << 4 ) | ( V_11 & 0x0f ) ;
return F_1 ( V_2 , V_3 , V_13 ,
V_12 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_14 ,
unsigned int V_15 )
{
unsigned int V_6 ;
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
do {
V_6 = F_2 ( V_2 , V_18 , 0 ,
V_14 , V_15 ) ;
if ( V_6 == V_19 )
return 0 ;
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
return - V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_6 ;
if ( V_23 -> V_24 == V_21 )
return 0 ;
V_6 = F_5 ( V_2 , V_25 ,
V_21 & 0xffff ) ;
if ( V_6 != - V_20 ) {
V_6 = F_5 ( V_2 , V_26 ,
V_21 >> 16 ) ;
}
V_23 -> V_24 = ( V_6 < 0 ) ? ~ 0UL : V_21 ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_27 , V_15 & 0xffff ) ;
if ( V_6 != - V_20 ) {
V_6 = F_5 ( V_2 , V_28 ,
V_15 >> 16 ) ;
}
V_23 -> V_24 = ( V_6 != - V_20 ) ?
( V_23 -> V_24 + 4 ) : ~ 0UL ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_2 * V_15 ,
unsigned int V_29 )
{
int V_30 = 0 ;
if ( V_15 == NULL ) {
F_12 ( V_31 L_1 ) ;
return - V_32 ;
}
while ( ( V_29 -- != 0 ) && ( V_30 == 0 ) )
V_30 = F_10 ( V_2 , * V_15 ++ ) ;
return V_30 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int * V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_33 , 0 ) ;
if ( V_6 != - V_20 ) {
V_6 = F_5 ( V_2 , V_34 , 0 ) ;
}
if ( V_6 != - V_20 ) {
* V_15 = F_2 ( V_2 , V_18 , 0 ,
V_35 ,
0 ) ;
}
V_23 -> V_24 = ( V_6 != - V_20 ) ?
( V_23 -> V_24 + 4 ) : ~ 0UL ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_21 , const unsigned int V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_36 ;
F_15 ( & V_23 -> V_37 ) ;
V_36 = F_9 ( V_2 , V_21 ) ;
if ( V_36 < 0 )
goto exit;
V_36 = F_10 ( V_2 , V_15 ) ;
if ( V_36 < 0 )
goto exit;
exit:
F_16 ( & V_23 -> V_37 ) ;
return V_36 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_2 V_21 ,
const T_2 * V_15 ,
unsigned int V_29 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
F_15 ( & V_23 -> V_37 ) ;
V_30 = F_9 ( V_2 , V_21 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_11 ( V_2 , V_15 , V_29 ) ;
error:
F_16 ( & V_23 -> V_37 ) ;
return V_30 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_21 , unsigned int * V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_36 ;
F_15 ( & V_23 -> V_37 ) ;
V_36 = F_9 ( V_2 , V_21 ) ;
if ( V_36 < 0 )
goto exit;
V_36 = F_13 ( V_2 , V_15 ) ;
if ( V_36 < 0 )
goto exit;
exit:
F_16 ( & V_23 -> V_37 ) ;
return V_36 ;
}
static void F_19 ( struct V_1 * V_2 ,
enum V_38 V_39 ,
bool V_40 )
{
unsigned int V_41 ;
unsigned int V_42 ;
V_42 = ( V_40 ? 1 : 0 ) ;
V_41 = ( V_42 << 7 ) | ( V_39 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_43 , V_41 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_44 V_45 , int V_46 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_41 ;
if ( ( V_45 < 32 ) && ( V_46 < 8 ) ) {
V_41 = ( V_46 << 5 ) | ( V_45 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_47 , V_41 ) ;
} else {
F_15 ( & V_23 -> V_37 ) ;
if ( F_5 ( V_2 , V_34 , 0 ) == 0 ) {
F_20 ( V_2 , V_18 , 0 ,
V_48 ,
V_45 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_49 ,
V_46 ) ;
}
F_16 ( & V_23 -> V_37 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
int V_50 , enum V_51 V_52 )
{
F_21 ( V_2 , V_53 , V_50 ) ;
F_21 ( V_2 , V_54 ,
V_52 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_15 ( & V_23 -> V_37 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_56 , 0xff ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 5 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_56 , 0x0b ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 6 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_56 , 0xff ) ;
F_16 ( & V_23 -> V_37 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 )
{
int V_6 ;
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
do {
V_6 = F_2 ( V_2 , V_57 , 0 , V_14 , V_15 ) ;
if ( ( V_6 >= 0 ) && ( V_6 != V_58 ) )
return V_6 ;
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
return - V_20 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_30 ;
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
do {
V_30 = F_2 ( V_2 , V_57 , 0 ,
V_59 , 0 ) ;
if ( ( V_30 == V_60 ) ||
( V_30 == V_61 ) )
break;
F_7 ( 1 ) ;
} while ( F_8 ( V_17 , V_16 ) );
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
F_25 ( V_2 ) ;
F_15 ( & V_23 -> V_37 ) ;
V_30 = F_24 ( V_2 , V_63 ,
V_62 & 0xffff ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_24 ( V_2 , V_64 ,
V_62 >> 16 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_2 ( V_2 , V_57 , 0 ,
V_59 , 0 ) ;
error:
F_16 ( & V_23 -> V_37 ) ;
return ( V_30 == V_65 ) ?
- V_20 : 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int * V_66 , unsigned int V_67 )
{
int V_30 = 0 ;
unsigned int V_29 ;
if ( ( V_66 == NULL ) )
return - V_32 ;
V_29 = 0 ;
while ( V_29 < V_67 ) {
V_30 = F_26 ( V_2 , * V_66 ++ ) ;
if ( V_30 != 0 )
break;
V_29 ++ ;
}
return V_30 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int * V_15 )
{
int V_30 ;
V_30 = F_24 ( V_2 , V_68 , 0 ) ;
if ( V_30 == - V_20 )
return V_30 ;
V_30 = F_24 ( V_2 , V_59 , 0 ) ;
if ( V_30 == - V_20 ||
V_30 == V_61 )
return - V_20 ;
* V_15 = F_2 ( V_2 , V_57 , 0 ,
V_69 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int * V_66 ,
unsigned int * V_70 , unsigned int V_71 )
{
int V_30 = 0 ;
unsigned int V_67 = * V_70 ;
unsigned int V_29 ;
unsigned int V_72 ;
unsigned int V_73 ;
if ( ( V_66 == NULL ) )
return - 1 ;
V_29 = 0 ;
while ( V_29 < V_67 && V_29 < V_71 ) {
V_30 = F_28 ( V_2 , V_66 ++ ) ;
if ( V_30 != 0 )
break;
V_29 ++ ;
}
V_72 = V_29 ;
if ( V_30 == 0 ) {
while ( V_72 < V_67 ) {
V_30 = F_28 ( V_2 , & V_73 ) ;
if ( V_30 != 0 )
break;
V_72 ++ ;
}
}
* V_70 = V_29 ;
return V_30 ;
}
static inline unsigned int
F_30 ( unsigned int V_74 , unsigned int V_75 ,
unsigned int V_76 , unsigned int V_77 ,
unsigned int V_78 , unsigned int V_79 ,
unsigned int V_80 , unsigned int V_81 )
{
unsigned int V_82 = 0 ;
V_82 = ( V_81 & 0x1f ) << 27 ;
V_82 |= ( V_80 & 0x01 ) << 26 ;
V_82 |= ( V_79 & 0x01 ) << 25 ;
V_82 |= ( V_78 & 0x01 ) << 24 ;
V_82 |= ( V_77 & 0x7f ) << 17 ;
V_82 |= ( V_76 & 0x01 ) << 16 ;
V_82 |= ( V_75 & 0xff ) << 8 ;
V_82 |= V_74 & 0xff ;
return V_82 ;
}
static inline void
F_31 ( unsigned int V_82 ,
unsigned int * V_74 , unsigned int * V_75 ,
unsigned int * V_76 , unsigned int * V_77 ,
unsigned int * V_78 , unsigned int * V_79 ,
unsigned int * V_80 , unsigned int * V_81 )
{
if ( V_81 )
* V_81 = ( V_82 >> 27 ) & 0x1f ;
if ( V_80 )
* V_80 = ( V_82 >> 26 ) & 0x01 ;
if ( V_79 )
* V_79 = ( V_82 >> 25 ) & 0x01 ;
if ( V_78 )
* V_78 = ( V_82 >> 24 ) & 0x01 ;
if ( V_77 )
* V_77 = ( V_82 >> 17 ) & 0x7f ;
if ( V_76 )
* V_76 = ( V_82 >> 16 ) & 0x01 ;
if ( V_75 )
* V_75 = ( V_82 >> 8 ) & 0xff ;
if ( V_74 )
* V_74 = V_82 & 0xff ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned int V_73 = 0 ;
int V_30 = - 1 ;
do {
V_30 = F_28 ( V_2 , & V_73 ) ;
} while ( V_30 == 0 );
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_15 = 0 ;
unsigned int V_29 ;
if ( F_28 ( V_2 , & V_15 ) < 0 )
return - V_20 ;
if ( ( V_15 & 0x00ffffff ) == V_23 -> V_83 ) {
V_23 -> V_84 = V_15 ;
V_23 -> V_85 = V_15 >> 27 ;
V_29 = V_23 -> V_86 ;
F_29 ( V_2 , V_23 -> V_87 ,
& V_23 -> V_85 , V_29 ) ;
return 0 ;
}
return - V_20 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned char * V_88 ,
unsigned int V_89 ,
unsigned char * V_90 ,
unsigned int V_91 ,
unsigned int * V_92 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 = - 1 ;
unsigned int V_93 = 0 ;
unsigned int V_94 ;
bool V_95 = false ;
unsigned int V_82 ;
struct V_96 * V_97 ;
unsigned int V_98 , V_99 ;
unsigned int V_81 , V_100 , V_74 , V_76 , V_78 ;
if ( V_92 )
* V_92 = 0 ;
V_82 = * ( ( unsigned int * ) V_88 ) ;
F_31 ( V_82 , & V_74 , & V_100 , & V_76 , NULL ,
& V_78 , NULL , NULL , & V_81 ) ;
V_93 = V_81 + 1 ;
V_94 = ( V_93 * 4 ) ;
if ( V_89 < V_94 )
return - V_32 ;
if ( V_76 || V_78 ) {
if ( ! V_90 || V_91 < 4 || ! V_92 )
return - V_32 ;
V_23 -> V_83 = * ( ( unsigned int * ) V_88 ) ;
V_99 = V_100 ;
V_98 = V_74 ;
V_23 -> V_83 &= 0xffff0000 ;
V_23 -> V_83 |= ( V_98 << 8 ) | ( V_99 ) ;
V_23 -> V_86 = V_91 /sizeof( unsigned int ) - 1 ;
V_23 -> V_101 = 1 ;
V_95 = true ;
}
V_30 = F_27 ( V_2 , ( unsigned int * ) V_88 ,
V_93 ) ;
if ( V_30 < 0 ) {
V_23 -> V_101 = 0 ;
return V_30 ;
}
if ( V_95 ) {
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
memset ( V_90 , 0 , V_91 ) ;
do {
F_7 ( 20 ) ;
} while ( V_23 -> V_101 && F_8 ( V_17 , V_16 ) );
V_95 = false ;
if ( ! V_23 -> V_101 ) {
V_97 = (struct V_96 * ) V_90 ;
memcpy ( & V_97 -> V_102 , & V_23 -> V_84 , 4 ) ;
memcpy ( & V_97 -> V_15 , V_23 -> V_87 ,
V_23 -> V_86 ) ;
* V_92 = ( V_23 -> V_85 + 1 ) * 4 ;
V_30 = 0 ;
} else {
V_30 = - V_20 ;
}
V_23 -> V_101 = 0 ;
}
return V_30 ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_103 , int V_77 , int V_104 , void * V_15 , unsigned int V_105 ,
void * V_106 , unsigned int * V_107 )
{
int V_30 = 0 ;
struct V_96 V_108 , V_109 ;
unsigned int V_110 , V_111 , V_112 ;
unsigned int V_113 , V_114 , V_115 ;
unsigned int V_116 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
if ( ( V_105 != 0 && V_15 == NULL ) || ( V_105 > V_117 ) )
return - V_32 ;
if ( V_104 == V_118 && V_106 == NULL ) {
F_12 ( V_31 L_2 ) ;
return - V_32 ;
}
if ( V_106 != NULL && ( V_107 == NULL || ( * V_107 == 0 ) ) ) {
F_12 ( V_31 L_3 ) ;
return - V_32 ;
}
V_108 . V_102 = F_30 ( V_103 , 0x20 , ( V_104 == V_118 ) , V_77 ,
0 , 0 , 0 , V_105 /sizeof( unsigned int ) ) ;
if ( V_15 != NULL && V_105 > 0 ) {
V_105 = F_36 ( ( unsigned int ) ( sizeof( V_108 . V_15 ) ) , V_105 ) ;
memcpy ( V_108 . V_15 , V_15 , V_105 ) ;
}
V_110 = 0 ;
V_111 = sizeof( unsigned int ) + V_105 ;
V_30 = F_34 ( V_2 , ( unsigned char * ) & V_108 ,
V_111 , ( unsigned char * ) & V_109 ,
sizeof( V_109 ) , & V_110 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_4 ) ;
return V_30 ;
}
F_31 ( V_108 . V_102 , NULL , NULL , & V_113 ,
NULL , NULL , NULL , NULL , NULL ) ;
F_31 ( V_109 . V_102 , NULL , NULL , NULL , NULL , NULL ,
& V_114 , & V_115 ,
& V_116 ) ;
if ( ! V_113 )
return 0 ;
if ( V_114 && ! V_115 ) {
V_112 = ( V_110 - sizeof( V_109 . V_102 ) )
/ sizeof( unsigned int ) ;
if ( * V_107 < V_112 *sizeof( unsigned int ) ) {
F_12 ( V_31 L_5 ) ;
return - V_32 ;
} else if ( V_112 != V_116 ) {
F_12 ( V_31 L_6 ) ;
return - V_32 ;
} else {
* V_107 = V_112 *sizeof( unsigned int ) ;
memcpy ( V_106 , V_109 . V_15 , * V_107 ) ;
}
} else {
F_12 ( V_31 L_7 ) ;
return - V_20 ;
}
return V_30 ;
}
static int F_37 ( struct V_1 * V_2 , int V_103 ,
int V_77 , void * V_15 , unsigned int V_105 )
{
return F_35 ( V_2 , V_103 , V_77 , V_119 , V_15 , V_105 , NULL , NULL ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_103 ,
int V_77 , unsigned int V_15 )
{
return F_37 ( V_2 , V_103 , V_77 , & V_15 , sizeof( unsigned int ) ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int * V_120 )
{
int V_30 = 0 ;
unsigned int V_67 = sizeof( V_120 ) ;
F_12 ( V_121 L_8 ) ;
V_30 = F_35 ( V_2 , V_122 , V_123 ,
V_118 , NULL , 0 , V_120 , & V_67 ) ;
if ( V_30 < 0 ) {
F_12 ( V_121 L_9 ) ;
return V_30 ;
}
if ( ( * V_120 + 1 ) == 0 ) {
F_12 ( V_121 L_10 ) ;
return - V_124 ;
}
F_12 ( L_11 , * V_120 ) ;
F_12 ( V_121 L_12 ) ;
return V_30 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_120 )
{
int V_30 = 0 ;
unsigned int V_73 = 0 ;
F_12 ( V_121 L_13 ) ;
F_12 ( L_14 , V_120 ) ;
V_30 = F_35 ( V_2 , V_122 , V_123 ,
V_119 , & V_120 , sizeof( V_120 ) , NULL , & V_73 ) ;
if ( V_30 < 0 ) {
F_12 ( V_121 L_15 ) ;
return V_30 ;
}
F_12 ( V_121 L_16 ) ;
return V_30 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
unsigned int V_126 ;
int V_36 ;
V_36 = F_18 ( V_2 , V_127 , & V_125 ) ;
if ( V_36 < 0 )
return V_36 ;
V_126 = ( V_125 & V_128 ) >>
V_129 ;
if ( V_126 != 0 ) {
V_125 &= ~ ( ( V_126 << V_130 ) &
V_131 ) ;
V_36 = F_14 ( V_2 , V_127 ,
V_125 ) ;
if ( V_36 < 0 )
return V_36 ;
V_125 |= ( V_126 << V_132 ) &
V_133 ;
V_36 = F_14 ( V_2 , V_127 ,
V_125 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
int V_134 = 20 ;
F_12 ( L_17 ) ;
do {
V_6 = F_24 ( V_2 , V_135 , 0 ) ;
V_134 -- ;
} while ( V_6 == - V_20 && V_134 );
if ( ! V_134 ) {
F_12 ( L_18 ) ;
return - V_20 ;
}
return 0 ;
}
static unsigned int F_43 ( unsigned int V_21 ,
bool * V_136 , bool * V_137 )
{
* V_136 = * V_137 = false ;
if ( F_44 ( V_21 , 1 ) ) {
* V_136 = true ;
return F_45 ( V_21 ) ;
} else if ( F_46 ( V_21 , 1 ) ) {
return F_47 ( V_21 ) ;
} else if ( F_48 ( V_21 , 1 ) ) {
* V_137 = true ;
return F_49 ( V_21 ) ;
}
return V_138 ;
}
static bool F_50 ( struct V_1 * V_2 , unsigned int V_120 )
{
unsigned int V_139 ;
F_18 ( V_2 , V_140 , & V_139 ) ;
return ( ( V_139 & ( 1 <<
( V_141 + V_120 ) ) ) != 0 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_120 ,
unsigned int V_142 ,
bool V_143 )
{
int V_30 = 0 ;
unsigned int V_144 ;
unsigned int V_145 ;
unsigned int V_146 ;
bool V_136 , V_137 ;
F_12 ( V_121 L_19 ) ;
if ( V_120 >= V_147 ) {
F_12 ( V_31 L_20 ) ;
return - V_32 ;
}
if ( F_50 ( V_2 , V_120 ) ) {
F_12 ( V_31 L_21 ) ;
return - V_124 ;
}
V_145 = F_43 ( V_21 , & V_136 , & V_137 ) ;
if ( V_145 == V_138 ) {
F_12 ( V_31 L_22 ) ;
return - V_148 ;
}
V_144 = V_149 ;
V_146 = 0 ;
F_12 ( V_121 L_23 ) ;
if ( V_143 ) {
V_30 = F_18 ( V_2 , V_150 ,
& V_144 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_24 ) ;
return V_30 ;
}
F_12 ( V_121 L_25 ) ;
}
if ( ! V_136 )
V_144 &= ~ ( 1 << ( V_151 + V_120 ) ) ;
else
V_144 |= ( 1 << ( V_151 + V_120 ) ) ;
V_144 &= ~ ( 1 << ( V_152 + V_120 ) ) ;
V_30 = F_14 ( V_2 , V_150 , V_144 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_26 ) ;
return V_30 ;
}
F_12 ( V_121 L_27 ) ;
if ( V_143 ) {
V_30 = F_18 ( V_2 , V_153 ,
& V_146 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_28 ) ;
return V_30 ;
}
F_12 ( V_121 L_29 ) ;
}
V_146 &= ( ~ ( 1 << ( V_154 + V_120 ) ) ) &
V_155 ;
V_30 = F_14 ( V_2 , V_153 , V_146 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_30 ) ;
return V_30 ;
}
F_12 ( V_121 L_31 ) ;
V_30 = F_14 ( V_2 , F_52 ( V_120 ) ,
V_142 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_32 ) ;
return V_30 ;
}
F_12 ( V_121 L_33 ) ;
V_30 = F_14 ( V_2 , F_53 ( V_120 ) ,
V_156 | V_157 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_34 ) ;
return V_30 ;
}
F_12 ( V_121 L_35 ) ;
F_12 (
L_36
L_37 ,
V_21 , V_145 , V_120 ,
V_142 , V_144 , V_146 ) ;
F_12 ( V_121 L_38 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_29 ,
unsigned int V_120 )
{
int V_30 = 0 ;
bool V_136 , V_137 ;
unsigned int V_145 ;
unsigned int V_158 ;
unsigned int V_159 ;
unsigned int V_160 ;
unsigned int V_161 ;
unsigned int V_162 = 0 ;
unsigned int V_163 = 0 ;
unsigned int V_164 = 0 ;
const unsigned int V_165 = 1 << ( V_166 -
V_167 + 1 ) ;
F_12 ( V_121 L_39 ) ;
if ( V_29 > V_165 ) {
F_12 ( V_31 L_40 ) ;
return - V_32 ;
}
V_145 = F_43 ( V_21 , & V_136 , & V_137 ) ;
if ( V_145 == V_138 ) {
F_12 ( V_31 L_22 ) ;
return - V_148 ;
}
F_12 ( V_121 L_41 ) ;
V_158 = V_145 << V_168 ;
V_159 = 0 ;
if ( ! V_136 ) {
V_158 <<= 1 ;
if ( V_137 )
V_158 |= ( 1 << V_168 ) ;
V_159 = ( 1 << V_169 ) ;
}
V_162 = V_158 + V_159 ;
V_30 = F_14 ( V_2 , F_55 ( V_120 ) ,
V_162 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_42 ) ;
return V_30 ;
}
F_12 ( V_121 L_43 ) ;
V_163 = ( V_29 - 1 ) << ( V_170 +
( V_136 ? 0 : 1 ) ) ;
V_30 = F_14 ( V_2 , F_56 ( V_120 ) ,
V_163 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_44 ) ;
return V_30 ;
}
F_12 ( V_121 L_45 ) ;
V_160 = ( V_29 - 1 ) << V_167 ;
V_161 = ( V_29 - 1 ) << V_171 ;
V_164 = V_160 | V_161 ;
V_30 = F_14 ( V_2 ,
F_57 ( V_120 ) , V_164 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_46 ) ;
return V_30 ;
}
F_12 ( V_121 L_47 ) ;
F_12 (
L_48
L_49 ,
V_21 , V_29 , V_162 , V_163 , V_164 ) ;
F_12 ( V_121 L_50 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_120 , bool V_143 )
{
unsigned int V_14 = 0 ;
int V_30 = 0 ;
F_12 ( V_121 L_51 ) ;
if ( V_143 ) {
V_30 = F_18 ( V_2 ,
V_140 , & V_14 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_52 ) ;
return V_30 ;
}
F_12 ( V_121 L_53 ) ;
V_14 &= ~ ( V_172 |
V_173 ) ;
}
V_30 = F_14 ( V_2 , V_140 ,
V_14 | ( 1 << ( V_120 + V_141 ) ) ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_54 ) ;
return V_30 ;
}
F_12 ( V_121 L_55 ) ;
return V_30 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_120 , bool V_143 )
{
unsigned int V_14 = 0 ;
int V_30 = 0 ;
F_12 ( V_121 L_56 ) ;
if ( V_143 ) {
V_30 = F_18 ( V_2 ,
V_140 , & V_14 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_52 ) ;
return V_30 ;
}
F_12 ( V_121 L_57 ) ;
V_14 &= ~ ( V_172 |
V_173 ) ;
}
V_30 = F_14 ( V_2 , V_140 ,
V_14 | ( 1 << ( V_120 + V_174 ) ) ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_54 ) ;
return V_30 ;
}
F_12 ( V_121 L_58 ) ;
return V_30 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned int V_175 ,
unsigned int V_176 ,
unsigned int V_177 ,
unsigned int * V_178 )
{
int V_30 = 0 ;
int V_6 ;
T_3 V_41 ;
V_30 = F_5 ( V_2 , V_34 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_41 = V_177 << 6 ;
V_41 |= ( V_176 - 1 ) << 4 ;
V_41 |= V_175 - 1 ;
F_20 ( V_2 , V_18 , 0 ,
V_179 ,
V_41 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_180 ,
V_181 ) ;
V_30 = F_5 ( V_2 , V_34 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 = F_2 ( V_2 , V_18 , 0 ,
V_182 , 0 ) ;
* V_178 = V_6 ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
V_30 = F_5 ( V_2 , V_34 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
F_20 ( V_2 , V_18 , 0 ,
V_183 ,
V_181 ) ;
V_30 = F_5 ( V_2 , V_34 , 0 ) ;
return V_30 ;
}
static int F_62 ( struct V_1 * V_2 ,
unsigned int V_175 ,
unsigned int V_184 , unsigned int * V_178 )
{
int V_30 ;
F_12 ( V_121 L_59 ) ;
if ( ( V_184 != 1 ) && ( V_184 != 2 ) && ( V_184 != 4 ) ) {
F_12 ( V_31 L_60 ) ;
return - V_32 ;
}
V_30 = F_60 ( V_2 , V_175 ,
V_184 , 0 , V_178 ) ;
F_12 ( V_121 L_61 ) ;
return V_30 ;
}
static int F_63 ( struct V_1 * V_2 ,
const unsigned short V_185 ,
unsigned int * V_178 )
{
int V_30 ;
unsigned int V_175 ;
unsigned int V_186 = ( ( F_64 ( V_185 ) >> 0 ) & 3 ) + 1 ;
unsigned int V_187 = ( ( F_64 ( V_185 ) >> 3 ) & 3 ) + 1 ;
unsigned int V_184 = V_187 / V_186 ;
if ( ( V_184 != 1 ) && ( V_184 != 2 ) && ( V_184 != 4 ) ) {
F_12 ( V_31 L_60 ) ;
return - V_32 ;
}
V_175 = F_65 ( V_185 ) + 1 ;
V_30 = F_62 ( V_2 , V_175 , V_184 , V_178 ) ;
return V_30 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_30 ;
F_12 ( V_121 L_62 ) ;
V_30 = F_61 ( V_2 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_63 ) ;
return V_30 ;
}
F_12 ( V_121 L_64 ) ;
return V_30 ;
}
static int F_67 (
unsigned int V_188 ,
unsigned short V_189 ,
unsigned short * V_190 )
{
unsigned int V_191 ;
V_191 = F_68 (
V_188 ,
V_189 ,
V_192 ,
32 , 0 ) ;
if ( V_190 )
* V_190 = ( unsigned short ) V_191 ;
return 0 ;
}
static int F_69 ( struct V_193 * V_194 )
{
struct V_1 * V_2 = V_194 -> V_2 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
if ( V_194 -> V_195 -> V_196 )
F_70 ( V_2 , V_194 -> V_195 ) ;
V_30 = F_71 ( V_2 ,
V_194 -> V_197 ,
V_194 -> V_70 ,
V_194 -> V_195 ) ;
if ( V_30 < 0 )
return V_30 ;
V_23 -> V_198 = V_30 ;
return 0 ;
}
static int F_72 ( struct V_193 * V_194 , enum V_199 V_200 )
{
bool V_201 ;
F_12 ( L_65 , V_200 ) ;
switch ( V_200 ) {
case V_202 :
V_201 = false ;
break;
case V_203 :
V_201 = true ;
break;
default:
return 0 ;
}
F_73 ( V_194 -> V_2 , V_201 ) ;
return 0 ;
}
static unsigned int F_74 ( struct V_193 * V_194 )
{
return V_194 -> V_195 -> V_204 ;
}
static unsigned char * F_75 ( struct V_193 * V_194 )
{
return V_194 -> V_195 -> V_196 ;
}
static int F_76 ( struct V_193 * V_194 ,
const unsigned int * V_15 ,
unsigned int V_29 )
{
memcpy ( V_194 -> V_195 -> V_196 , V_15 , V_29 ) ;
return 0 ;
}
static void F_77 (
struct V_193 * V_194 ,
unsigned short * V_205 )
{
if ( V_205 )
* V_205 = V_194 -> V_197 ;
}
static unsigned int F_78 ( struct V_193 * V_194 )
{
struct V_22 * V_23 = V_194 -> V_2 -> V_23 ;
return V_23 -> V_198 ;
}
static bool F_79 ( const struct V_206 * V_207 )
{
return V_207 -> V_208 == V_209 ;
}
static bool F_80 ( const struct V_206 * V_207 )
{
return V_210 == V_207 -> V_211 ;
}
static bool F_81 ( const struct V_206 * V_207 )
{
return V_207 -> V_29 == 0 ;
}
static T_4 F_82 ( const struct V_206 * V_207 )
{
return sizeof( * V_207 ) + V_207 -> V_29 * sizeof( T_2 ) ;
}
static const struct V_206 * F_83 (
const struct V_206 * V_207 )
{
return (struct V_206 * ) ( ( unsigned char * ) ( V_207 ) + F_82 ( V_207 ) ) ;
}
static int F_84 ( struct V_1 * V_2 ,
const struct V_206 * V_212 )
{
int V_30 ;
const T_2 * V_15 ;
unsigned int V_29 ;
if ( V_212 == NULL || V_212 -> V_211 != V_210 ) {
F_12 ( V_31 L_66 ) ;
return - V_32 ;
}
V_29 = V_212 -> V_29 ;
V_15 = ( T_2 * ) ( V_212 -> V_15 ) ;
while ( V_29 >= 2 ) {
V_30 = F_14 ( V_2 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_67 ) ;
return V_30 ;
}
V_29 -= 2 ;
V_15 += 2 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_206 * V_212 ,
unsigned int V_213 ,
struct V_193 * V_193 ,
unsigned int V_120 ,
unsigned int V_142 ,
bool V_143 )
{
int V_30 = 0 ;
bool V_214 = false ;
const unsigned int * V_15 ;
unsigned int V_21 ;
unsigned int V_215 ;
unsigned int V_216 ;
unsigned char * V_217 ;
unsigned short V_190 ;
unsigned int V_186 ;
unsigned int V_187 ;
unsigned int V_175 ;
unsigned int V_218 ;
unsigned int V_219 ;
const T_2 * V_220 ;
T_2 V_221 ;
unsigned int V_222 ;
const struct V_206 * V_223 = NULL ;
unsigned long V_16 ;
bool V_224 ;
if ( V_212 == NULL )
return - V_32 ;
if ( F_80 ( V_212 ) ) {
V_223 = V_212 ;
V_212 = F_83 ( V_212 ) ;
}
if ( V_223 && ( ! V_212 || F_81 ( V_212 ) ) ) {
F_12 ( L_68 ) ;
return F_84 ( V_2 , V_223 ) ;
}
if ( V_212 == NULL || V_193 == NULL || V_142 == 0 ) {
F_12 ( L_69 ) ;
return - V_32 ;
}
V_15 = V_212 -> V_15 ;
V_21 = V_212 -> V_211 ,
V_215 = V_212 -> V_29 ;
if ( ! V_215 )
return V_223 ? F_84 ( V_2 , V_223 ) : 0 ;
if ( V_213 )
V_21 = ( V_21 & ( 0xFFFF0000 << 2 ) ) + ( V_213 << 2 ) ;
if ( ! F_44 ( V_21 , V_215 ) &&
! F_46 ( V_21 , V_215 ) &&
! F_48 ( V_21 , V_215 ) ) {
F_12 ( L_70 ) ;
return - V_32 ;
}
V_216 = ( unsigned int ) F_74 ( V_193 ) /
sizeof( T_2 ) ;
V_217 = F_75 ( V_193 ) ;
if ( V_217 == NULL ) {
F_12 ( V_31 L_71 ) ;
return - V_32 ;
}
F_77 ( V_193 , & V_190 ) ;
V_186 = ( ( F_64 ( V_190 ) >> 0 ) & 3 ) + 1 ;
V_187 = ( ( F_64 ( V_190 ) >> 3 ) & 3 ) + 1 ;
V_175 = F_65 ( V_190 ) + 1 ;
V_218 = ( ( V_186 == 0 ) ? 0 :
( V_175 * V_187 / V_186 ) ) ;
if ( V_218 == 0 ) {
F_12 ( V_31 L_72 ) ;
return - V_32 ;
}
V_216 = F_36 ( V_216 ,
( unsigned int ) ( F_44 ( V_21 , 1 ) ?
65536 : 32768 ) ) ;
V_216 -= V_216 % V_218 ;
F_12 (
L_73
L_74 ,
V_21 , V_218 , V_175 ,
V_187 , V_186 , V_216 ) ;
if ( V_216 < V_218 ) {
F_12 ( V_31 L_75 ) ;
return - V_32 ;
}
V_219 = V_215 % V_218 ;
V_220 = V_15 ;
V_221 = V_21 ;
V_15 += V_219 ;
V_21 += V_219 * sizeof( T_2 ) ;
V_215 -= V_219 ;
while ( V_215 != 0 ) {
V_222 = F_36 ( V_216 , V_215 ) ;
F_12 ( L_76 ,
V_215 , V_222 , V_219 ) ;
F_76 ( V_193 , V_15 , V_222 * sizeof( T_2 ) ) ;
if ( ! V_214 ) {
V_30 = F_59 ( V_2 , V_120 , V_143 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_51 ( V_2 , V_21 ,
V_120 , V_142 , V_143 ) ;
if ( V_30 < 0 )
return V_30 ;
V_214 = true ;
}
V_30 = F_54 ( V_2 , V_21 ,
V_222 , V_120 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_58 ( V_2 , V_120 , V_143 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! F_50 ( V_2 , V_120 ) ) {
F_12 ( V_31 L_77 ) ;
return - V_20 ;
}
V_30 = F_72 ( V_193 , V_203 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_219 != 0 ) {
V_30 = F_17 ( V_2 ,
V_221 ,
V_220 ,
V_219 ) ;
if ( V_30 < 0 )
return V_30 ;
V_219 = 0 ;
}
if ( V_223 ) {
V_30 = F_84 ( V_2 , V_223 ) ;
if ( V_30 < 0 )
return V_30 ;
V_223 = NULL ;
}
V_16 = V_17 + F_6 ( 2000 ) ;
do {
V_224 = F_50 ( V_2 , V_120 ) ;
if ( ! V_224 )
break;
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
if ( V_224 )
break;
F_12 ( V_121 L_78 ) ;
F_72 ( V_193 , V_202 ) ;
V_30 = F_69 ( V_193 ) ;
if ( V_30 < 0 )
return V_30 ;
V_15 += V_222 ;
V_21 += V_222 * sizeof( T_2 ) ;
V_215 -= V_222 ;
}
if ( V_219 != 0 ) {
V_30 = F_17 ( V_2 , V_221 ,
V_220 , V_219 ) ;
}
return V_30 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_206 * V_225 ,
unsigned int V_213 ,
unsigned int V_188 ,
unsigned short V_189 ,
bool V_143 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
unsigned short V_190 = 0 ;
unsigned int V_7 ;
unsigned char V_226 = 0 ;
struct V_193 * V_193 ;
unsigned int V_120 ;
unsigned int V_142 ;
if ( V_225 == NULL )
return - V_32 ;
V_193 = F_87 ( sizeof( * V_193 ) , V_227 ) ;
if ( ! V_193 )
return - V_228 ;
V_193 -> V_195 = F_87 ( sizeof( * V_193 -> V_195 ) , V_227 ) ;
if ( ! V_193 -> V_195 ) {
F_88 ( V_193 ) ;
return - V_228 ;
}
V_193 -> V_2 = V_2 ;
F_67 ( V_188 , V_189 , & V_190 ) ;
V_193 -> V_197 = V_190 ;
V_193 -> V_70 = ( V_143 ? V_229 :
V_230 ) * 2 ;
V_120 = V_143 ? V_231 : 0 ;
V_30 = F_3 ( V_2 , V_18 ,
V_190 , & V_7 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_79 ) ;
goto exit;
}
V_30 = F_71 ( V_2 ,
V_193 -> V_197 ,
V_193 -> V_70 ,
V_193 -> V_195 ) ;
if ( V_30 < 0 )
goto exit;
V_23 -> V_198 = V_30 ;
if ( V_143 ) {
V_30 = F_39 ( V_2 , & V_120 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_80 ) ;
V_120 = V_231 ;
goto exit;
}
}
V_142 = 0 ;
V_30 = F_63 ( V_2 , V_190 ,
& V_142 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_81 ) ;
goto exit;
}
V_226 = F_78 ( V_193 ) ;
V_30 = F_4 ( V_2 ,
V_18 , V_226 , 0 , & V_7 ) ;
if ( V_30 < 0 ) {
F_12 ( V_31 L_82 ) ;
goto exit;
}
while ( ( V_225 != NULL ) && ! F_81 ( V_225 ) ) {
if ( ! F_79 ( V_225 ) ) {
F_12 ( V_31 L_83 ) ;
V_30 = - V_32 ;
goto exit;
}
V_30 = F_85 ( V_2 , V_225 , V_213 ,
V_193 , V_120 ,
V_142 , V_143 ) ;
if ( V_30 < 0 )
break;
if ( F_80 ( V_225 ) )
V_225 = F_83 ( V_225 ) ;
if ( ( V_225 != NULL ) && ! F_81 ( V_225 ) )
V_225 = F_83 ( V_225 ) ;
}
if ( V_142 != 0 )
V_30 = F_66 ( V_2 ) ;
if ( V_30 < 0 )
goto exit;
V_30 = F_4 ( V_2 ,
V_18 , 0 , 0 , & V_7 ) ;
exit:
if ( V_143 && ( V_120 != V_231 ) )
F_40 ( V_2 , V_120 ) ;
if ( V_193 -> V_195 -> V_196 )
F_70 ( V_2 , V_193 -> V_195 ) ;
F_88 ( V_193 -> V_195 ) ;
F_88 ( V_193 ) ;
return V_30 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_12 ( V_121 L_84 ) ;
F_14 ( V_2 , F_90 ( 0x18 ) , 0x08080080 ) ;
F_14 ( V_2 , F_90 ( 0x19 ) , 0x3f800000 ) ;
F_14 ( V_2 , F_90 ( 0x29 ) , 0x00000002 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
const struct V_206 * V_212 ,
bool V_143 ,
unsigned int V_213 ,
bool V_232 ,
int V_233 )
{
int V_30 = 0 ;
unsigned int V_188 ;
unsigned short V_189 ;
F_12 ( V_121 L_85 ) ;
if ( V_233 == 0 ) {
if ( ! V_143 )
V_233 = V_234 ;
else
V_233 = V_235 ;
}
V_188 = 48000 ;
V_189 = ( unsigned short ) V_233 ;
while ( V_189 > 16 ) {
V_188 *= 2 ;
V_189 /= 2 ;
}
do {
F_12 ( V_121 L_86 ) ;
if ( ! V_143 )
V_30 = F_42 ( V_2 ) ;
if ( V_30 < 0 )
break;
F_12 ( V_121 L_87 ) ;
V_30 = F_86 ( V_2 , V_212 , V_213 , V_188 , V_189 ,
V_143 ) ;
if ( V_30 < 0 )
break;
F_12 ( V_121 L_88 ) ;
if ( V_232 && ! V_143 ) {
F_89 ( V_2 ) ;
V_30 = F_41 ( V_2 ) ;
}
F_12 ( V_121 L_89 ) ;
} while ( 0 );
return V_30 ;
}
static bool F_92 ( struct V_1 * V_2 )
{
unsigned int V_15 = 0 ;
int V_30 = 0 ;
V_30 = F_18 ( V_2 , 0x40004 , & V_15 ) ;
if ( ( V_30 < 0 ) || ( V_15 != 1 ) )
return false ;
return true ;
}
static bool F_93 ( struct V_1 * V_2 )
{
unsigned long V_16 = V_17 + F_6 ( 2000 ) ;
do {
if ( F_92 ( V_2 ) ) {
F_94 ( L_90 ) ;
return true ;
}
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
F_95 ( L_91 ) ;
return false ;
}
static void F_96 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_236 ,
int V_237 , int V_205 )
{
unsigned int V_238 , V_239 ;
if ( ! V_3 )
return;
F_12 (
L_92
L_93 ,
V_3 , V_236 , V_237 , V_205 ) ;
V_238 = F_2 ( V_2 , V_3 , 0 ,
V_240 ,
0 ) ;
if ( V_238 != V_205 ) {
F_7 ( 20 ) ;
F_20 ( V_2 , V_3 , 0 ,
V_241 ,
V_205 ) ;
}
V_238 = F_2 ( V_2 , V_3 , 0 , V_242 , 0 ) ;
V_239 = ( V_236 << 4 ) | V_237 ;
if ( V_238 != V_239 ) {
F_20 ( V_2 , V_3 , 0 ,
V_13 ,
V_239 ) ;
}
}
static void F_97 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_41 ;
if ( ! V_3 )
return;
F_12 ( V_121 L_94 , V_3 ) ;
V_41 = F_2 ( V_2 , V_3 , 0 , V_242 , 0 ) ;
if ( ! V_41 )
return;
F_20 ( V_2 , V_3 , 0 , V_241 , 0 ) ;
F_20 ( V_2 , V_3 , 0 , V_13 , 0 ) ;
}
static int F_98 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_205 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_96 ( V_2 , V_23 -> V_247 [ 0 ] , V_236 , 0 , V_205 ) ;
return 0 ;
}
static int F_99 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_248 == V_249 )
return 0 ;
if ( V_23 -> V_250 [ V_251 - V_252 ] )
F_7 ( 50 ) ;
F_97 ( V_2 , V_23 -> V_247 [ 0 ] ) ;
return 0 ;
}
static unsigned int F_100 ( struct V_243 * V_253 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_254 = V_255 ;
struct V_256 * V_257 = V_246 -> V_257 ;
if ( V_23 -> V_248 != V_258 )
return 0 ;
if ( V_23 -> V_250 [ V_251 - V_252 ] ) {
if ( ( V_23 -> V_250 [ V_259 - V_252 ] ) ||
( V_23 -> V_250 [ V_260 - V_252 ] ) )
V_254 += V_261 ;
}
if ( V_23 -> V_262 == V_263 )
V_254 += V_264 ;
return ( V_254 * V_257 -> V_52 ) / 1000 ;
}
static int F_101 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_102 ( V_2 , & V_23 -> V_265 ) ;
}
static int F_103 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_205 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_104 ( V_2 , & V_23 -> V_265 ,
V_236 , V_205 , V_246 ) ;
}
static int F_105 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_106 ( V_2 , & V_23 -> V_265 ) ;
}
static int F_107 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_108 ( V_2 , & V_23 -> V_265 ) ;
}
static int F_109 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_205 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_96 ( V_2 , V_23 -> V_266 [ V_246 -> V_267 ] ,
V_236 , 0 , V_205 ) ;
return 0 ;
}
static int F_110 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_248 == V_249 )
return 0 ;
F_97 ( V_2 , V_244 -> V_3 ) ;
return 0 ;
}
static unsigned int F_111 ( struct V_243 * V_253 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_254 = V_268 ;
struct V_256 * V_257 = V_246 -> V_257 ;
if ( V_23 -> V_248 != V_258 )
return 0 ;
if ( V_23 -> V_250 [ V_269 - V_252 ] )
V_254 += V_270 ;
return ( V_254 * V_257 -> V_52 ) / 1000 ;
}
static int F_112 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_271 , int V_272 )
{
int V_273 = 0 ;
for ( V_273 = 0 ; V_273 < V_274 ; V_273 ++ )
if ( V_3 == V_275 [ V_273 ] . V_3 )
break;
F_113 ( V_2 ) ;
F_37 ( V_2 , V_275 [ V_273 ] . V_276 ,
V_275 [ V_273 ] . V_77 ,
& ( V_271 [ V_272 ] ) , sizeof( unsigned int ) ) ;
F_114 ( V_2 ) ;
return 1 ;
}
static int F_115 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
int V_272 = V_3 - V_283 ;
* V_281 = V_23 -> V_284 [ V_272 ] ;
return 0 ;
}
static int F_118 ( struct V_277 * V_278 ,
struct V_285 * V_286 )
{
int V_287 = F_119 ( V_278 ) ;
V_286 -> type = V_288 ;
V_286 -> V_29 = V_287 == 3 ? 2 : 1 ;
V_286 -> V_282 . integer . F_36 = 20 ;
V_286 -> V_282 . integer . V_289 = 180 ;
V_286 -> V_282 . integer . V_290 = 1 ;
return 0 ;
}
static int F_120 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
int V_272 ;
V_272 = V_3 - V_283 ;
if ( V_23 -> V_284 [ V_272 ] == * V_281 )
return 0 ;
V_23 -> V_284 [ V_272 ] = * V_281 ;
V_272 = * V_281 - 20 ;
F_112 ( V_2 , V_3 , V_291 , V_272 ) ;
return 1 ;
}
static int F_121 ( struct V_277 * V_278 ,
struct V_285 * V_286 )
{
int V_287 = F_119 ( V_278 ) ;
V_286 -> type = V_288 ;
V_286 -> V_29 = V_287 == 3 ? 2 : 1 ;
V_286 -> V_282 . integer . F_36 = 0 ;
V_286 -> V_282 . integer . V_289 = 100 ;
V_286 -> V_282 . integer . V_290 = 1 ;
return 0 ;
}
static int F_122 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
int V_272 ;
V_272 = V_3 - V_283 ;
if ( V_23 -> V_284 [ V_272 ] == * V_281 )
return 0 ;
V_23 -> V_284 [ V_272 ] = * V_281 ;
V_272 = * V_281 ;
F_112 ( V_2 , V_3 , V_292 , V_272 ) ;
return 0 ;
}
static int F_123 ( struct V_277 * V_278 ,
struct V_285 * V_286 )
{
int V_287 = F_119 ( V_278 ) ;
V_286 -> type = V_288 ;
V_286 -> V_29 = V_287 == 3 ? 2 : 1 ;
V_286 -> V_282 . integer . F_36 = 0 ;
V_286 -> V_282 . integer . V_289 = 48 ;
V_286 -> V_282 . integer . V_290 = 1 ;
return 0 ;
}
static int F_124 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
int V_272 ;
V_272 = V_3 - V_283 ;
if ( V_23 -> V_284 [ V_272 ] == * V_281 )
return 0 ;
V_23 -> V_284 [ V_272 ] = * V_281 ;
V_272 = * V_281 ;
F_112 ( V_2 , V_3 , V_293 , V_272 ) ;
return 1 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_1 V_294 , T_1 V_3 ,
const char * V_295 , int V_104 )
{
char V_296 [ V_297 ] ;
int type = V_104 ? V_298 : V_299 ;
struct V_300 V_301 =
F_126 ( V_296 , V_3 , 1 , 0 , type ) ;
V_301 . V_302 = V_303 |
V_304 ;
V_301 . V_305 . V_306 = 0 ;
V_301 . V_305 . V_207 = 0 ;
switch ( V_294 ) {
case V_307 :
V_301 . V_253 = F_118 ;
V_301 . V_308 = F_115 ;
V_301 . V_309 = F_120 ;
V_301 . V_305 . V_207 = V_310 ;
break;
case V_311 :
V_301 . V_253 = F_121 ;
V_301 . V_308 = F_115 ;
V_301 . V_309 = F_122 ;
break;
case V_312 :
V_301 . V_253 = F_123 ;
V_301 . V_308 = F_115 ;
V_301 . V_309 = F_124 ;
V_301 . V_305 . V_207 = V_313 ;
break;
default:
return 0 ;
}
V_301 . V_314 =
F_127 ( V_3 , 1 , 0 , type ) ;
sprintf ( V_296 , L_95 , V_295 , V_315 [ V_104 ] ) ;
return F_128 ( V_2 , V_3 , F_129 ( & V_301 , V_2 ) ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
int V_273 ;
int V_36 ;
for ( V_273 = 0 ; V_273 < V_274 ; V_273 ++ ) {
V_36 = F_125 ( V_2 ,
V_275 [ V_273 ] . V_316 ,
V_275 [ V_273 ] . V_3 ,
V_275 [ V_273 ] . V_295 ,
V_275 [ V_273 ] . V_317 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_273 ;
V_23 -> V_284 [ V_318 - V_283 ] = 10 ;
V_23 -> V_284 [ V_319 - V_283 ] = 74 ;
for ( V_273 = 2 ; V_273 < V_274 ; V_273 ++ )
V_23 -> V_284 [ V_273 ] = 24 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_320 ;
int V_321 ;
int V_322 ;
unsigned int V_323 ;
int V_36 ;
F_12 ( V_121 L_96 ) ;
F_113 ( V_2 ) ;
V_322 = V_23 -> V_324 [ V_325 - V_326 ] ;
if ( V_322 )
V_321 = F_133 ( V_2 , V_23 -> V_327 [ 1 ] ) ;
else
V_321 =
V_23 -> V_324 [ V_328 - V_326 ] ;
if ( V_321 )
V_23 -> V_262 = V_329 ;
else
V_23 -> V_262 = V_263 ;
if ( V_23 -> V_262 == V_263 ) {
F_12 ( V_121 L_97 ) ;
V_323 = V_330 ;
V_36 = F_38 ( V_2 , 0x80 , 0x04 , V_323 ) ;
if ( V_36 < 0 )
goto exit;
V_323 = V_330 ;
V_36 = F_38 ( V_2 , 0x8f , 0x00 , V_323 ) ;
if ( V_36 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_327 [ 1 ] , 0 ,
V_331 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_332 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_331 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_332 , 0x02 ) ;
V_320 = F_2 ( V_2 , V_23 -> V_327 [ 1 ] , 0 ,
V_333 , 0 ) ;
F_134 ( V_2 , V_23 -> V_327 [ 1 ] ,
V_320 & ~ V_334 ) ;
V_320 = F_2 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_333 , 0 ) ;
F_134 ( V_2 , V_23 -> V_327 [ 0 ] ,
V_320 | V_335 ) ;
} else {
F_12 ( V_121 L_98 ) ;
V_323 = V_336 ;
V_36 = F_38 ( V_2 , 0x80 , 0x04 , V_323 ) ;
if ( V_36 < 0 )
goto exit;
V_323 = V_336 ;
V_36 = F_38 ( V_2 , 0x8f , 0x00 , V_323 ) ;
if ( V_36 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_331 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_332 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 1 ] , 0 ,
V_331 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_332 , 0x02 ) ;
V_320 = F_2 ( V_2 , V_23 -> V_327 [ 0 ] , 0 ,
V_333 , 0 ) ;
F_134 ( V_2 , V_23 -> V_327 [ 0 ] ,
V_320 & ~ V_334 ) ;
V_320 = F_2 ( V_2 , V_23 -> V_327 [ 1 ] , 0 ,
V_333 , 0 ) ;
F_134 ( V_2 , V_23 -> V_327 [ 1 ] ,
V_320 | V_334 ) ;
}
exit:
F_114 ( V_2 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static void F_135 ( struct V_337 * V_338 )
{
struct V_22 * V_23 = F_136 (
F_137 ( V_338 ) , struct V_22 , V_339 ) ;
F_132 ( V_23 -> V_2 ) ;
F_138 ( V_23 -> V_2 ) ;
}
static int F_139 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_323 ;
if ( V_23 -> V_248 != V_258 )
return 0 ;
if ( ! V_23 -> V_250 [ V_269 - V_252 ] ||
( V_41 == 0 ) ) {
F_21 ( V_2 , V_340 , 0 ) ;
F_22 ( V_2 , V_341 , V_342 ) ;
F_22 ( V_2 , V_343 , V_342 ) ;
if ( V_23 -> V_344 == V_345 )
V_323 = V_346 ;
else
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x00 , V_323 ) ;
V_323 = V_336 ;
F_38 ( V_2 , 0x80 , 0x05 , V_323 ) ;
} else {
F_22 ( V_2 , V_341 , V_347 ) ;
F_22 ( V_2 , V_343 , V_347 ) ;
if ( V_23 -> V_344 == V_345 )
V_323 = V_346 ;
else
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x00 , V_323 ) ;
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x05 , V_323 ) ;
F_7 ( 20 ) ;
F_21 ( V_2 , V_340 , V_41 ) ;
}
return 1 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_321 ;
int V_322 ;
F_12 ( V_121 L_99 ) ;
F_113 ( V_2 ) ;
V_322 = V_23 -> V_324 [ V_348 - V_326 ] ;
if ( V_322 )
V_321 = F_133 ( V_2 , V_23 -> V_349 [ 0 ] ) ;
else
V_321 =
V_23 -> V_324 [ V_350 - V_326 ] ;
if ( V_321 )
V_23 -> V_344 = V_351 ;
else
V_23 -> V_344 = V_345 ;
if ( V_23 -> V_344 == V_345 ) {
F_22 ( V_2 , V_352 , V_353 ) ;
F_141 ( V_2 , 1 ) ;
F_142 ( V_2 , 0 ) ;
F_143 ( V_2 , V_307 ,
V_23 -> V_250
[ V_307 - V_252 ] ) ;
} else {
F_22 ( V_2 , V_352 , V_342 ) ;
F_141 ( V_2 , 0 ) ;
F_142 ( V_2 , V_23 -> V_354 ) ;
F_143 ( V_2 , V_307 , 0 ) ;
}
F_114 ( V_2 ) ;
return 0 ;
}
static bool F_144 ( struct V_1 * V_2 ,
T_1 V_355 ,
T_1 * V_356 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
switch ( V_355 ) {
case V_357 :
V_3 = V_23 -> V_358 ;
break;
case V_359 :
V_3 = V_23 -> V_360 ;
break;
default:
return false ;
}
if ( V_356 )
* V_356 = V_3 ;
return true ;
}
static int F_145 ( struct V_1 * V_2 , int V_361 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_323 ;
if ( V_361 ) {
V_323 = V_23 -> V_250 [ V_269 - V_252 ] ?
V_330 : V_336 ;
} else {
V_323 = V_336 ;
}
F_38 ( V_2 , V_362 . V_276 ,
V_362 . V_363 [ 0 ] , V_323 ) ;
return 1 ;
}
static int F_143 ( struct V_1 * V_2 , T_1 V_3 , long V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_364 ;
int V_365 = V_366 + V_367 ;
int V_36 = 0 ;
int V_272 = V_3 - V_252 ;
if ( ( V_272 < 0 ) || ( V_272 >= V_365 ) )
return 0 ;
if ( ( V_3 >= V_368 ) && ( V_3 < V_369 ) ) {
if ( ! V_23 -> V_250 [ V_251 - V_252 ] )
V_41 = 0 ;
}
if ( ( V_3 >= V_370 ) && ( V_3 < V_371 ) ) {
if ( ! V_23 -> V_250 [ V_269 - V_252 ] )
V_41 = 0 ;
if ( ( V_3 == V_307 ) && ( V_23 -> V_344 != V_345 ) )
V_41 = 0 ;
}
F_12 ( V_121 L_100 ,
V_3 , V_41 ) ;
V_364 = ( V_41 == 0 ) ? V_336 : V_330 ;
V_36 = F_38 ( V_2 , V_372 [ V_272 ] . V_276 ,
V_372 [ V_272 ] . V_363 [ 0 ] , V_364 ) ;
if ( V_36 < 0 )
return 0 ;
return 1 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_273 , V_373 = 0 ;
F_12 ( V_121 L_101 ,
V_23 -> V_250 [ V_251 - V_252 ] ) ;
V_273 = V_368 - V_252 ;
V_3 = V_368 ;
for (; V_3 < V_369 ; V_3 ++ , V_273 ++ )
V_373 |= F_143 ( V_2 , V_3 , V_23 -> V_250 [ V_273 ] ) ;
return V_373 ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_238 = F_2 ( V_2 , V_23 -> V_266 [ 0 ] , 0 ,
V_242 , 0 ) ;
if ( V_238 != 0 )
F_20 ( V_2 , V_23 -> V_266 [ 0 ] , 0 ,
V_13 ,
0 ) ;
return V_238 ;
}
static void F_148 ( struct V_1 * V_2 , unsigned int V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_238 != 0 )
F_20 ( V_2 , V_23 -> V_266 [ 0 ] , 0 ,
V_13 ,
V_238 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_273 , V_373 = 0 ;
unsigned int V_238 ;
F_12 ( V_121 L_102 ,
V_23 -> V_250 [ V_269 - V_252 ] ) ;
V_273 = V_370 - V_252 ;
V_3 = V_370 ;
for (; V_3 < V_371 ; V_3 ++ , V_273 ++ )
V_373 |= F_143 ( V_2 , V_3 , V_23 -> V_250 [ V_273 ] ) ;
V_373 |= F_145 ( V_2 , ( V_23 -> V_374 ? 1 : 0 ) ) ;
V_238 = F_147 ( V_2 ) ;
V_373 |= F_139 ( V_2 , 1 ) ;
F_148 ( V_2 , V_238 ) ;
return V_373 ;
}
static int F_142 ( struct V_1 * V_2 , long V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_373 = 0 ;
if ( V_41 )
V_373 = F_150 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_298 , 0 , V_375 , 3 ) ;
else
V_373 = F_150 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_298 , 0 , V_375 , 0 ) ;
return V_373 ;
}
static int F_151 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
T_1 V_3 = F_117 ( V_278 ) ;
T_1 V_356 = 0 ;
bool V_376 ;
int V_373 = 0 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_322 ;
if ( V_3 == V_328 ) {
V_322 =
V_23 -> V_324 [ V_325 - V_326 ] ;
if ( ! V_322 )
F_132 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_350 ) {
V_322 =
V_23 -> V_324 [ V_348 - V_326 ] ;
if ( ! V_322 )
F_140 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_325 ) {
F_132 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_348 ) {
F_140 ( V_2 ) ;
return 1 ;
}
V_376 = F_144 ( V_2 , V_3 , & V_356 ) ;
if ( V_376 ) {
int V_104 = F_152 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
unsigned long V_378 ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_356 , V_377 ,
0 , V_104 ) ;
V_373 = F_153 ( V_278 , V_280 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
}
return V_373 ;
}
static int F_154 ( struct V_277 * V_278 ,
struct V_285 * V_286 )
{
unsigned int V_380 = sizeof( V_381 )
/ sizeof( struct V_382 ) ;
V_286 -> type = V_383 ;
V_286 -> V_29 = 1 ;
V_286 -> V_282 . V_384 . V_380 = V_380 ;
if ( V_286 -> V_282 . V_384 . V_385 >= V_380 )
V_286 -> V_282 . V_384 . V_385 = V_380 - 1 ;
strcpy ( V_286 -> V_282 . V_384 . V_295 ,
V_381 [ V_286 -> V_282 . V_384 . V_385 ] . V_295 ) ;
return 0 ;
}
static int F_155 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
V_280 -> V_282 . V_384 . V_385 [ 0 ] = V_23 -> V_374 ;
return 0 ;
}
static int F_156 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_273 , V_36 = 0 ;
int V_386 = V_280 -> V_282 . V_384 . V_385 [ 0 ] ;
unsigned int V_380 = sizeof( V_381 )
/ sizeof( struct V_382 ) ;
if ( V_386 >= V_380 )
return 0 ;
F_12 ( V_121 L_103 ,
V_386 , V_381 [ V_386 ] . V_295 ) ;
for ( V_273 = 0 ; V_273 < V_387 ; V_273 ++ ) {
V_36 = F_38 ( V_2 , V_362 . V_276 ,
V_362 . V_363 [ V_273 ] ,
V_381 [ V_386 ] . V_388 [ V_273 ] ) ;
if ( V_36 < 0 )
break;
}
if ( V_36 >= 0 ) {
V_23 -> V_374 = V_386 ;
F_145 ( V_2 , ( V_386 ? 1 : 0 ) ) ;
}
return 1 ;
}
static int F_157 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
if ( ( V_3 >= V_326 ) && ( V_3 < V_389 ) ) {
if ( V_377 & 1 ) {
* V_281 = V_23 -> V_324 [ V_3 - V_326 ] ;
V_281 ++ ;
}
if ( V_377 & 2 ) {
* V_281 = V_23 -> V_390 [ V_3 - V_326 ] ;
V_281 ++ ;
}
return 0 ;
}
if ( ( V_3 >= V_252 ) && ( V_3 < V_391 ) ) {
* V_281 = V_23 -> V_250 [ V_3 - V_252 ] ;
return 0 ;
}
if ( V_3 == V_23 -> V_349 [ 0 ] ) {
* V_281 = V_23 -> V_354 ;
return 0 ;
}
return 0 ;
}
static int F_158 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
int V_392 = 1 ;
F_12 ( V_121 L_104 ,
V_3 , * V_281 ) ;
F_113 ( V_2 ) ;
if ( ( V_3 >= V_326 ) && ( V_3 < V_389 ) ) {
if ( V_377 & 1 ) {
V_23 -> V_324 [ V_3 - V_326 ] = * V_281 ;
V_281 ++ ;
}
if ( V_377 & 2 ) {
V_23 -> V_390 [ V_3 - V_326 ] = * V_281 ;
V_281 ++ ;
}
V_392 = F_151 ( V_278 , V_280 ) ;
goto exit;
}
if ( V_3 == V_251 ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_281 ;
V_392 = F_146 ( V_2 ) ;
goto exit;
}
if ( V_3 == V_269 ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_281 ;
V_392 = F_149 ( V_2 ) ;
goto exit;
}
if ( ( ( V_3 >= V_368 ) && ( V_3 < V_369 ) ) ||
( ( V_3 >= V_370 ) && ( V_3 < V_371 ) ) ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_281 ;
V_392 = F_143 ( V_2 , V_3 , * V_281 ) ;
goto exit;
}
if ( V_3 == V_23 -> V_349 [ 0 ] ) {
V_23 -> V_354 = * V_281 ;
if ( V_23 -> V_344 != V_345 )
V_392 = F_142 ( V_2 , * V_281 ) ;
goto exit;
}
exit:
F_114 ( V_2 ) ;
return V_392 ;
}
static int F_159 ( struct V_277 * V_278 ,
struct V_285 * V_286 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
int V_104 = F_152 ( V_278 ) ;
unsigned long V_378 ;
int V_36 ;
switch ( V_3 ) {
case V_357 :
V_3 = V_23 -> V_358 ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_3 , V_377 , 0 , V_104 ) ;
V_36 = F_160 ( V_278 , V_286 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
break;
case V_359 :
V_3 = V_23 -> V_360 ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_3 , V_377 , 0 , V_104 ) ;
V_36 = F_160 ( V_278 , V_286 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
break;
default:
V_36 = F_160 ( V_278 , V_286 ) ;
}
return V_36 ;
}
static int F_161 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
if ( V_377 & 1 ) {
* V_281 = V_23 -> V_393 [ V_3 - V_326 ] ;
V_281 ++ ;
}
if ( V_377 & 2 ) {
* V_281 = V_23 -> V_394 [ V_3 - V_326 ] ;
V_281 ++ ;
}
return 0 ;
}
static int F_162 ( struct V_277 * V_278 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
long * V_281 = V_280 -> V_282 . integer . V_282 ;
T_1 V_356 = 0 ;
bool V_376 ;
int V_392 = 1 ;
if ( V_377 & 1 ) {
V_23 -> V_393 [ V_3 - V_326 ] = * V_281 ;
V_281 ++ ;
}
if ( V_377 & 2 ) {
V_23 -> V_394 [ V_3 - V_326 ] = * V_281 ;
V_281 ++ ;
}
V_376 = F_144 ( V_2 , V_3 , & V_356 ) ;
if ( V_376 ) {
int V_104 = F_152 ( V_278 ) ;
unsigned long V_378 ;
F_113 ( V_2 ) ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_356 , V_377 ,
0 , V_104 ) ;
V_392 = F_163 ( V_278 , V_280 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
F_114 ( V_2 ) ;
}
return V_392 ;
}
static int F_164 ( struct V_277 * V_278 , int V_395 ,
unsigned int V_67 , unsigned int T_5 * V_305 )
{
struct V_1 * V_2 = F_116 ( V_278 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_278 ) ;
int V_377 = F_119 ( V_278 ) ;
int V_104 = F_152 ( V_278 ) ;
unsigned long V_378 ;
int V_36 ;
switch ( V_3 ) {
case V_357 :
V_3 = V_23 -> V_358 ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_3 , V_377 , 0 , V_104 ) ;
V_36 = F_165 ( V_278 , V_395 , V_67 , V_305 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
break;
case V_359 :
V_3 = V_23 -> V_360 ;
F_15 ( & V_2 -> V_379 ) ;
V_378 = V_278 -> V_314 ;
V_278 -> V_314 = F_127 ( V_3 , V_377 , 0 , V_104 ) ;
V_36 = F_165 ( V_278 , V_395 , V_67 , V_305 ) ;
V_278 -> V_314 = V_378 ;
F_16 ( & V_2 -> V_379 ) ;
break;
default:
V_36 = F_165 ( V_278 , V_395 , V_67 , V_305 ) ;
}
return V_36 ;
}
static int F_166 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_396 , int V_104 )
{
char V_296 [ V_297 ] ;
int type = V_104 ? V_298 : V_299 ;
struct V_300 V_301 =
F_167 ( V_296 , V_3 , 1 , type ) ;
sprintf ( V_296 , L_105 , V_396 , V_315 [ V_104 ] ) ;
return F_128 ( V_2 , V_3 , F_129 ( & V_301 , V_2 ) ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_300 V_301 =
F_169 ( V_362 . V_295 ,
V_397 , 1 , 0 , V_298 ) ;
V_301 . V_253 = F_154 ;
V_301 . V_308 = F_155 ;
V_301 . V_309 = F_156 ;
return F_128 ( V_2 , V_397 , F_129 ( & V_301 , V_2 ) ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_273 , V_365 ;
int V_36 = 0 ;
for ( V_273 = 0 ; V_273 < V_23 -> V_398 ; V_273 ++ ) {
V_36 = F_171 ( V_2 , V_23 -> V_399 [ V_273 ] ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_365 = V_366 + V_367 ;
for ( V_273 = 0 ; V_273 < V_365 ; V_273 ++ ) {
V_36 = F_166 ( V_2 , V_372 [ V_273 ] . V_3 ,
V_372 [ V_273 ] . V_295 ,
V_372 [ V_273 ] . V_317 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_166 ( V_2 , V_251 , L_106 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_166 ( V_2 , V_269 , L_107 , 1 ) ;
if ( V_36 < 0 )
return V_36 ;
F_168 ( V_2 ) ;
#ifdef F_172
F_130 ( V_2 ) ;
#endif
V_36 = F_173 ( V_2 , & V_23 -> V_400 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_23 -> V_401 ) {
V_36 = F_174 ( V_2 , V_23 -> V_401 ,
V_23 -> V_401 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_175 ( V_2 , & V_23 -> V_265 ) ;
if ( V_36 < 0 )
return V_36 ;
}
if ( V_23 -> V_402 ) {
V_36 = F_176 ( V_2 , V_23 -> V_402 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_403 * V_253 = V_23 -> V_404 ;
V_2 -> V_405 = V_253 ;
V_2 -> V_406 = 0 ;
V_253 -> V_295 = L_108 ;
V_253 -> V_10 [ V_407 ] = V_408 ;
V_253 -> V_10 [ V_407 ] . V_3 = V_23 -> V_247 [ 0 ] ;
V_253 -> V_10 [ V_407 ] . V_409 =
V_23 -> V_265 . V_410 ;
V_253 -> V_10 [ V_411 ] = V_412 ;
V_253 -> V_10 [ V_411 ] . V_413 = 1 ;
V_253 -> V_10 [ V_411 ] . V_3 = V_23 -> V_266 [ 0 ] ;
V_2 -> V_406 ++ ;
V_253 ++ ;
V_253 -> V_295 = L_109 ;
V_253 -> V_10 [ V_411 ] = V_412 ;
V_253 -> V_10 [ V_411 ] . V_413 = 1 ;
V_253 -> V_10 [ V_411 ] . V_3 = V_23 -> V_266 [ 1 ] ;
V_2 -> V_406 ++ ;
V_253 ++ ;
V_253 -> V_295 = L_110 ;
V_253 -> V_10 [ V_411 ] = V_412 ;
V_253 -> V_10 [ V_411 ] . V_413 = 1 ;
V_253 -> V_10 [ V_411 ] . V_3 = V_23 -> V_266 [ 2 ] ;
V_2 -> V_406 ++ ;
if ( ! V_23 -> V_401 && ! V_23 -> V_402 )
return 0 ;
V_253 ++ ;
V_253 -> V_295 = L_111 ;
V_253 -> V_414 = V_415 ;
if ( V_23 -> V_401 ) {
V_253 -> V_10 [ V_407 ] =
V_416 ;
V_253 -> V_10 [ V_407 ] . V_3 = V_23 -> V_401 ;
}
if ( V_23 -> V_402 ) {
V_253 -> V_10 [ V_411 ] =
V_417 ;
V_253 -> V_10 [ V_411 ] . V_3 = V_23 -> V_402 ;
}
V_2 -> V_406 ++ ;
return 0 ;
}
static void F_178 ( struct V_1 * V_2 , T_1 V_418 , T_1 V_419 )
{
if ( V_418 ) {
F_134 ( V_2 , V_418 , V_334 ) ;
if ( F_179 ( V_2 , V_418 ) & V_420 )
F_20 ( V_2 , V_418 , 0 ,
V_421 ,
V_422 ) ;
}
if ( V_419 && ( F_179 ( V_2 , V_419 ) & V_420 ) )
F_20 ( V_2 , V_419 , 0 ,
V_421 , V_423 ) ;
}
static void F_180 ( struct V_1 * V_2 , T_1 V_418 , T_1 V_424 )
{
if ( V_418 ) {
F_134 ( V_2 , V_418 , V_425 ) ;
if ( F_179 ( V_2 , V_418 ) & V_426 )
F_20 ( V_2 , V_418 , 0 ,
V_421 ,
F_181 ( 0 ) ) ;
}
if ( V_424 && ( F_179 ( V_2 , V_424 ) & V_426 ) ) {
F_20 ( V_2 , V_424 , 0 , V_421 ,
F_181 ( 0 ) ) ;
F_182 ( V_2 , V_424 , V_298 , 0 ,
V_375 , 0x5a ) ;
F_182 ( V_2 , V_424 , V_298 , 0 ,
V_427 , 0 ) ;
}
}
static void F_183 ( struct V_1 * V_2 )
{
F_184 ( V_2 , V_428 , V_428 ) ;
F_184 ( V_2 , V_429 , V_429 ) ;
}
static void F_185 ( struct V_1 * V_2 , T_1 V_3 , int V_104 )
{
unsigned int V_430 ;
V_430 = F_186 ( V_2 , V_3 , V_104 == V_299 ?
V_431 : V_432 ) ;
F_187 ( V_2 , V_3 , V_104 , V_430 ) ;
}
static void F_141 ( struct V_1 * V_2 , int V_361 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_323 ;
T_3 V_41 ;
unsigned int V_238 ;
F_12 ( V_121 L_112 , V_361 ) ;
V_238 = F_147 ( V_2 ) ;
F_139 ( V_2 , 0 ) ;
if ( V_361 ) {
V_323 = V_346 ;
F_38 ( V_2 , 0x80 , 0x00 , V_323 ) ;
V_41 = V_23 -> V_433 ;
V_41 |= 0x80 ;
F_20 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_434 , V_41 ) ;
if ( ! ( V_23 -> V_433 & 0x20 ) )
F_19 ( V_2 , V_435 , 1 ) ;
} else {
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x00 , V_323 ) ;
V_41 = V_23 -> V_433 ;
V_41 &= 0x5f ;
F_20 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_434 , V_41 ) ;
if ( ! ( V_23 -> V_433 & 0x20 ) )
F_19 ( V_2 , V_435 , 0 ) ;
}
F_139 ( V_2 , 1 ) ;
F_148 ( V_2 , V_238 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_3 V_41 ;
V_41 = 0x01 ;
F_20 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_436 , V_41 ) ;
V_41 = 0x83 ;
F_20 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_437 , V_41 ) ;
V_41 = 0x23 ;
V_23 -> V_433 = V_41 ;
F_20 ( V_2 , V_23 -> V_349 [ 0 ] , 0 ,
V_434 , V_41 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_15 ( & V_23 -> V_37 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0x20 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_438 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_439 , 0x00 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0x2D ) ;
F_20 ( V_2 , V_18 , 0 ,
V_438 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_439 , 0x00 ) ;
F_16 ( & V_23 -> V_37 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_273 ;
T_1 V_3 ;
F_12 ( V_121 L_113 ) ;
V_3 = V_2 -> V_440 ;
for ( V_273 = 0 ; V_273 < V_2 -> V_441 ; V_273 ++ , V_3 ++ )
V_2 -> V_442 [ V_273 ] = F_186 ( V_2 , V_3 ,
V_443 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_265 . V_444 ; V_273 ++ )
F_185 ( V_2 , V_23 -> V_247 [ V_273 ] , V_299 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_445 ; V_273 ++ )
F_185 ( V_2 , V_23 -> V_327 [ V_273 ] , V_299 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_446 ; V_273 ++ ) {
F_185 ( V_2 , V_23 -> V_266 [ V_273 ] , V_298 ) ;
F_185 ( V_2 , V_23 -> V_349 [ V_273 ] , V_298 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_323 ;
int V_365 ;
int V_272 , V_273 ;
if ( V_23 -> V_248 != V_258 )
return;
V_365 = V_366 + V_367 + 1 ;
for ( V_272 = 0 ; V_272 < V_365 ; V_272 ++ ) {
for ( V_273 = 0 ; V_273 <= V_372 [ V_272 ] . V_447 ; V_273 ++ ) {
F_38 ( V_2 , V_372 [ V_272 ] . V_276 ,
V_372 [ V_272 ] . V_363 [ V_273 ] ,
V_372 [ V_272 ] . V_448 [ V_273 ] ) ;
}
}
V_323 = V_336 ;
F_38 ( V_2 , 0x96 , 0x3C , V_323 ) ;
F_38 ( V_2 , 0x8f , 0x01 , V_323 ) ;
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x00 , V_323 ) ;
F_38 ( V_2 , 0x80 , 0x01 , V_323 ) ;
V_323 = V_330 ;
F_38 ( V_2 , 0x80 , 0x05 , V_323 ) ;
V_323 = V_346 ;
F_38 ( V_2 , 0x31 , 0x00 , V_323 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_449 , 0 ) ;
F_19 ( V_2 , V_450 , 0 ) ;
F_19 ( V_2 , V_451 , 0 ) ;
F_19 ( V_2 , V_452 , 0 ) ;
F_19 ( V_2 , V_453 , 0 ) ;
F_19 ( V_2 , V_454 , 1 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_455 , 6 ) ;
F_21 ( V_2 , V_456 , 6 ) ;
}
static void F_194 ( struct V_1 * V_2 , bool V_457 )
{
F_19 ( V_2 , V_458 , V_457 ) ;
F_19 ( V_2 , V_459 , V_457 ) ;
F_19 ( V_2 , V_460 , V_457 ) ;
F_19 ( V_2 , V_461 , V_457 ) ;
F_19 ( V_2 , V_462 , V_457 ) ;
F_19 ( V_2 , V_463 , V_457 ) ;
F_22 ( V_2 , V_341 , V_342 ) ;
F_22 ( V_2 , V_343 , V_342 ) ;
F_22 ( V_2 , V_464 , V_465 ) ;
}
static bool F_195 ( struct V_1 * V_2 )
{
bool V_466 = false ;
const struct V_206 * V_467 ;
const struct V_468 * V_469 ;
if ( F_196 ( & V_469 , V_470 , V_2 -> V_471 -> V_472 -> V_473 ) != 0 )
return false ;
V_467 = (struct V_206 * ) ( V_469 -> V_15 ) ;
if ( F_91 ( V_2 , V_467 , 0 , 0 , true , 0 ) ) {
F_95 ( L_114 ) ;
goto V_474;
}
V_466 = F_93 ( V_2 ) ;
V_474:
F_197 ( V_469 ) ;
return V_466 ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
#ifndef F_199
return;
#endif
F_23 ( V_2 ) ;
V_23 -> V_248 = V_249 ;
if ( ! F_195 ( V_2 ) )
V_23 -> V_248 = V_475 ;
else
V_23 -> V_248 = V_258 ;
if ( V_23 -> V_248 == V_258 )
F_194 ( V_2 , true ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_12 ( V_121 L_115 ) ;
if ( V_23 -> V_101 ) {
if ( F_33 ( V_2 ) >= 0 )
V_23 -> V_101 = 0 ;
}
F_32 ( V_2 ) ;
}
static void F_201 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( ( ( V_6 >> V_476 ) & 0x3f ) == V_477 ) {
F_200 ( V_2 ) ;
} else {
V_6 = F_202 ( V_2 ,
( V_6 >> V_476 ) & 0x3f ) ;
F_12 ( V_121 L_116 , V_6 ) ;
switch ( V_6 ) {
case V_428 :
F_203 ( & V_23 -> V_339 ) ;
F_204 ( V_2 -> V_471 -> V_478 ,
& V_23 -> V_339 ,
F_6 ( 500 ) ) ;
break;
case V_429 :
F_140 ( V_2 ) ;
F_138 ( V_2 ) ;
break;
default:
break;
}
}
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_365 ;
int V_273 ;
unsigned int V_364 ;
F_206 ( & V_23 -> V_37 ) ;
V_23 -> V_262 = V_263 ;
V_23 -> V_344 = V_345 ;
V_23 -> V_354 = 0 ;
for ( V_273 = 0 ; V_273 < V_479 ; V_273 ++ ) {
V_23 -> V_393 [ V_273 ] = 0x5a ;
V_23 -> V_394 [ V_273 ] = 0x5a ;
V_23 -> V_324 [ V_273 ] = 0 ;
V_23 -> V_390 [ V_273 ] = 0 ;
}
V_365 = V_366 + V_367 ;
for ( V_273 = 0 ; V_273 < V_365 ; V_273 ++ ) {
V_364 = ( unsigned int ) V_372 [ V_273 ] . V_363 [ 0 ] ;
V_23 -> V_250 [ V_273 ] = V_364 ? 1 : 0 ;
}
V_23 -> V_374 = 0 ;
V_23 -> V_250 [ V_251 - V_252 ] = 1 ;
V_23 -> V_250 [ V_269 - V_252 ] = 0 ;
#ifdef F_172
F_131 ( V_2 ) ;
#endif
}
static void F_207 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
F_42 ( V_2 ) ;
}
static int F_208 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_480 * V_481 = & V_23 -> V_400 ;
int V_273 ;
V_23 -> V_248 = V_482 ;
V_23 -> V_24 = V_138 ;
F_113 ( V_2 ) ;
F_193 ( V_2 ) ;
F_192 ( V_2 ) ;
F_209 ( V_2 , V_23 -> V_483 ) ;
F_198 ( V_2 ) ;
F_190 ( V_2 ) ;
F_191 ( V_2 ) ;
F_189 ( V_2 ) ;
F_188 ( V_2 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_445 ; V_273 ++ )
F_178 ( V_2 , V_23 -> V_327 [ V_273 ] , V_23 -> V_247 [ 0 ] ) ;
F_178 ( V_2 , V_481 -> V_484 [ 0 ] , V_23 -> V_401 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_446 ; V_273 ++ )
F_180 ( V_2 , V_23 -> V_349 [ V_273 ] , V_23 -> V_266 [ V_273 ] ) ;
F_180 ( V_2 , V_481 -> V_485 , V_23 -> V_402 ) ;
for ( V_273 = 0 ; V_273 < V_23 -> V_486 ; V_273 ++ )
F_209 ( V_2 , V_23 -> V_487 [ V_273 ] ) ;
F_183 ( V_2 ) ;
F_132 ( V_2 ) ;
F_140 ( V_2 ) ;
F_138 ( V_2 ) ;
F_114 ( V_2 ) ;
return 0 ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_203 ( & V_23 -> V_339 ) ;
F_113 ( V_2 ) ;
F_209 ( V_2 , V_23 -> V_488 ) ;
F_207 ( V_2 ) ;
F_114 ( V_2 ) ;
F_88 ( V_2 -> V_23 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_480 * V_481 = & V_23 -> V_400 ;
V_23 -> V_247 [ 0 ] = 0x2 ;
V_23 -> V_247 [ 1 ] = 0x3 ;
V_23 -> V_247 [ 2 ] = 0x4 ;
V_23 -> V_265 . V_489 = V_23 -> V_247 ;
V_23 -> V_265 . V_444 = 3 ;
V_23 -> V_265 . V_410 = 2 ;
V_23 -> V_445 = 2 ;
V_23 -> V_327 [ 0 ] = 0x0b ;
V_23 -> V_327 [ 1 ] = 0x10 ;
V_23 -> V_358 = 0x2 ;
V_23 -> V_446 = 3 ;
V_23 -> V_266 [ 0 ] = 0x7 ;
V_23 -> V_266 [ 1 ] = 0x8 ;
V_23 -> V_266 [ 2 ] = 0xa ;
V_23 -> V_360 = 0x7 ;
V_23 -> V_349 [ 0 ] = 0x12 ;
V_23 -> V_349 [ 1 ] = 0x11 ;
V_23 -> V_349 [ 2 ] = 0x13 ;
V_23 -> V_401 = 0x05 ;
V_23 -> V_265 . V_490 = V_23 -> V_401 ;
V_481 -> V_484 [ 0 ] = 0x0c ;
V_481 -> V_491 = 1 ;
V_481 -> V_492 [ 0 ] = V_415 ;
V_23 -> V_402 = 0x09 ;
V_481 -> V_485 = 0x0e ;
V_481 -> V_493 = V_415 ;
}
static int F_212 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_36 ;
F_12 ( L_117 ) ;
V_23 = F_87 ( sizeof( * V_23 ) , V_227 ) ;
if ( ! V_23 )
return - V_228 ;
V_2 -> V_23 = V_23 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_398 = 1 ;
V_23 -> V_399 [ 0 ] = V_494 ;
V_23 -> V_483 = V_495 ;
V_23 -> V_488 = V_496 ;
V_23 -> V_487 [ 0 ] = V_497 ;
V_23 -> V_487 [ 1 ] = V_498 ;
V_23 -> V_486 = 2 ;
F_213 ( & V_23 -> V_339 , F_135 ) ;
F_205 ( V_2 ) ;
F_211 ( V_2 ) ;
V_36 = F_214 ( V_2 , & V_23 -> V_400 , NULL ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_499 = V_500 ;
return 0 ;
}
static int T_6 F_215 ( void )
{
return F_216 ( & V_501 ) ;
}
static void T_7 F_217 ( void )
{
F_218 ( & V_501 ) ;
}
