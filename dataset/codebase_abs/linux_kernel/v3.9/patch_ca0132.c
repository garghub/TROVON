unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
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
static int F_100 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_101 ( V_2 , & V_23 -> V_253 ) ;
}
static int F_102 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_205 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_103 ( V_2 , & V_23 -> V_253 ,
V_236 , V_205 , V_246 ) ;
}
static int F_104 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_105 ( V_2 , & V_23 -> V_253 ) ;
}
static int F_106 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_107 ( V_2 , & V_23 -> V_253 ) ;
}
static int F_108 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_205 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_96 ( V_2 , V_23 -> V_254 [ V_246 -> V_255 ] ,
V_236 , 0 , V_205 ) ;
return 0 ;
}
static int F_109 ( struct V_243 * V_244 ,
struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_248 == V_249 )
return 0 ;
F_97 ( V_2 , V_244 -> V_3 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_256 , int V_257 )
{
int V_258 = 0 ;
for ( V_258 = 0 ; V_258 < V_259 ; V_258 ++ )
if ( V_3 == V_260 [ V_258 ] . V_3 )
break;
F_111 ( V_2 ) ;
F_37 ( V_2 , V_260 [ V_258 ] . V_261 ,
V_260 [ V_258 ] . V_77 ,
& ( V_256 [ V_257 ] ) , sizeof( unsigned int ) ) ;
F_112 ( V_2 ) ;
return 1 ;
}
static int F_113 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
int V_257 = V_3 - V_268 ;
* V_266 = V_23 -> V_269 [ V_257 ] ;
return 0 ;
}
static int F_116 ( struct V_262 * V_263 ,
struct V_270 * V_271 )
{
int V_272 = F_117 ( V_263 ) ;
V_271 -> type = V_273 ;
V_271 -> V_29 = V_272 == 3 ? 2 : 1 ;
V_271 -> V_267 . integer . F_36 = 20 ;
V_271 -> V_267 . integer . V_274 = 180 ;
V_271 -> V_267 . integer . V_275 = 1 ;
return 0 ;
}
static int F_118 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
int V_257 ;
V_257 = V_3 - V_268 ;
if ( V_23 -> V_269 [ V_257 ] == * V_266 )
return 0 ;
V_23 -> V_269 [ V_257 ] = * V_266 ;
V_257 = * V_266 - 20 ;
F_110 ( V_2 , V_3 , V_276 , V_257 ) ;
return 1 ;
}
static int F_119 ( struct V_262 * V_263 ,
struct V_270 * V_271 )
{
int V_272 = F_117 ( V_263 ) ;
V_271 -> type = V_273 ;
V_271 -> V_29 = V_272 == 3 ? 2 : 1 ;
V_271 -> V_267 . integer . F_36 = 0 ;
V_271 -> V_267 . integer . V_274 = 100 ;
V_271 -> V_267 . integer . V_275 = 1 ;
return 0 ;
}
static int F_120 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
int V_257 ;
V_257 = V_3 - V_268 ;
if ( V_23 -> V_269 [ V_257 ] == * V_266 )
return 0 ;
V_23 -> V_269 [ V_257 ] = * V_266 ;
V_257 = * V_266 ;
F_110 ( V_2 , V_3 , V_277 , V_257 ) ;
return 0 ;
}
static int F_121 ( struct V_262 * V_263 ,
struct V_270 * V_271 )
{
int V_272 = F_117 ( V_263 ) ;
V_271 -> type = V_273 ;
V_271 -> V_29 = V_272 == 3 ? 2 : 1 ;
V_271 -> V_267 . integer . F_36 = 0 ;
V_271 -> V_267 . integer . V_274 = 48 ;
V_271 -> V_267 . integer . V_275 = 1 ;
return 0 ;
}
static int F_122 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
int V_257 ;
V_257 = V_3 - V_268 ;
if ( V_23 -> V_269 [ V_257 ] == * V_266 )
return 0 ;
V_23 -> V_269 [ V_257 ] = * V_266 ;
V_257 = * V_266 ;
F_110 ( V_2 , V_3 , V_278 , V_257 ) ;
return 1 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_1 V_279 , T_1 V_3 ,
const char * V_280 , int V_104 )
{
char V_281 [ 44 ] ;
int type = V_104 ? V_282 : V_283 ;
struct V_284 V_285 =
F_124 ( V_281 , V_3 , 1 , 0 , type ) ;
V_285 . V_286 = V_287 |
V_288 ;
V_285 . V_289 . V_290 = 0 ;
V_285 . V_289 . V_207 = 0 ;
switch ( V_279 ) {
case V_291 :
V_285 . V_292 = F_116 ;
V_285 . V_293 = F_113 ;
V_285 . V_294 = F_118 ;
V_285 . V_289 . V_207 = V_295 ;
break;
case V_296 :
V_285 . V_292 = F_119 ;
V_285 . V_293 = F_113 ;
V_285 . V_294 = F_120 ;
break;
case V_297 :
V_285 . V_292 = F_121 ;
V_285 . V_293 = F_113 ;
V_285 . V_294 = F_122 ;
V_285 . V_289 . V_207 = V_298 ;
break;
default:
return 0 ;
}
V_285 . V_299 =
F_125 ( V_3 , 1 , 0 , type ) ;
sprintf ( V_281 , L_95 , V_280 , V_300 [ V_104 ] ) ;
return F_126 ( V_2 , V_3 , F_127 ( & V_285 , V_2 ) ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
int V_258 ;
int V_36 ;
for ( V_258 = 0 ; V_258 < V_259 ; V_258 ++ ) {
V_36 = F_123 ( V_2 ,
V_260 [ V_258 ] . V_301 ,
V_260 [ V_258 ] . V_3 ,
V_260 [ V_258 ] . V_280 ,
V_260 [ V_258 ] . V_302 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_258 ;
V_23 -> V_269 [ V_303 - V_268 ] = 10 ;
V_23 -> V_269 [ V_304 - V_268 ] = 74 ;
for ( V_258 = 2 ; V_258 < V_259 ; V_258 ++ )
V_23 -> V_269 [ V_258 ] = 24 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_305 ;
int V_306 ;
int V_307 ;
unsigned int V_308 ;
int V_36 ;
F_12 ( V_121 L_96 ) ;
F_111 ( V_2 ) ;
V_307 = V_23 -> V_309 [ V_310 - V_311 ] ;
if ( V_307 )
V_306 = F_131 ( V_2 , V_23 -> V_312 [ 1 ] ) ;
else
V_306 =
V_23 -> V_309 [ V_313 - V_311 ] ;
if ( V_306 )
V_23 -> V_314 = V_315 ;
else
V_23 -> V_314 = V_316 ;
if ( V_23 -> V_314 == V_316 ) {
F_12 ( V_121 L_97 ) ;
V_308 = V_317 ;
V_36 = F_38 ( V_2 , 0x80 , 0x04 , V_308 ) ;
if ( V_36 < 0 )
goto exit;
V_308 = V_317 ;
V_36 = F_38 ( V_2 , 0x8f , 0x00 , V_308 ) ;
if ( V_36 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_312 [ 1 ] , 0 ,
V_318 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_319 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_318 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_319 , 0x02 ) ;
V_305 = F_2 ( V_2 , V_23 -> V_312 [ 1 ] , 0 ,
V_320 , 0 ) ;
F_132 ( V_2 , V_23 -> V_312 [ 1 ] ,
V_305 & ~ V_321 ) ;
V_305 = F_2 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_320 , 0 ) ;
F_132 ( V_2 , V_23 -> V_312 [ 0 ] ,
V_305 | V_322 ) ;
} else {
F_12 ( V_121 L_98 ) ;
V_308 = V_323 ;
V_36 = F_38 ( V_2 , 0x80 , 0x04 , V_308 ) ;
if ( V_36 < 0 )
goto exit;
V_308 = V_323 ;
V_36 = F_38 ( V_2 , 0x8f , 0x00 , V_308 ) ;
if ( V_36 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_318 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_319 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 1 ] , 0 ,
V_318 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_319 , 0x02 ) ;
V_305 = F_2 ( V_2 , V_23 -> V_312 [ 0 ] , 0 ,
V_320 , 0 ) ;
F_132 ( V_2 , V_23 -> V_312 [ 0 ] ,
V_305 & ~ V_321 ) ;
V_305 = F_2 ( V_2 , V_23 -> V_312 [ 1 ] , 0 ,
V_320 , 0 ) ;
F_132 ( V_2 , V_23 -> V_312 [ 1 ] ,
V_305 | V_321 ) ;
}
exit:
F_112 ( V_2 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_133 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_308 ;
if ( V_23 -> V_248 != V_324 )
return 0 ;
if ( ! V_23 -> V_250 [ V_325 - V_252 ] ||
( V_41 == 0 ) ) {
F_21 ( V_2 , V_326 , 0 ) ;
F_22 ( V_2 , V_327 , V_328 ) ;
F_22 ( V_2 , V_329 , V_328 ) ;
if ( V_23 -> V_330 == V_331 )
V_308 = V_332 ;
else
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x00 , V_308 ) ;
V_308 = V_323 ;
F_38 ( V_2 , 0x80 , 0x05 , V_308 ) ;
} else {
F_22 ( V_2 , V_327 , V_333 ) ;
F_22 ( V_2 , V_329 , V_333 ) ;
if ( V_23 -> V_330 == V_331 )
V_308 = V_332 ;
else
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x00 , V_308 ) ;
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x05 , V_308 ) ;
F_7 ( 20 ) ;
F_21 ( V_2 , V_326 , V_41 ) ;
}
return 1 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_306 ;
int V_307 ;
F_12 ( V_121 L_99 ) ;
F_111 ( V_2 ) ;
V_307 = V_23 -> V_309 [ V_334 - V_311 ] ;
if ( V_307 )
V_306 = F_131 ( V_2 , V_23 -> V_335 [ 0 ] ) ;
else
V_306 =
V_23 -> V_309 [ V_336 - V_311 ] ;
if ( V_306 )
V_23 -> V_330 = V_337 ;
else
V_23 -> V_330 = V_331 ;
if ( V_23 -> V_330 == V_331 ) {
F_22 ( V_2 , V_338 , V_339 ) ;
F_135 ( V_2 , 1 ) ;
F_136 ( V_2 , 0 ) ;
F_137 ( V_2 , V_291 ,
V_23 -> V_250
[ V_291 - V_252 ] ) ;
} else {
F_22 ( V_2 , V_338 , V_328 ) ;
F_135 ( V_2 , 0 ) ;
F_136 ( V_2 , V_23 -> V_340 ) ;
F_137 ( V_2 , V_291 , 0 ) ;
}
F_112 ( V_2 ) ;
return 0 ;
}
static bool F_138 ( struct V_1 * V_2 ,
T_1 V_341 ,
T_1 * V_342 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
switch ( V_341 ) {
case V_343 :
V_3 = V_23 -> V_344 ;
break;
case V_345 :
V_3 = V_23 -> V_346 ;
break;
default:
return false ;
}
if ( V_342 )
* V_342 = V_3 ;
return true ;
}
static int F_139 ( struct V_1 * V_2 , int V_347 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_308 ;
if ( V_347 ) {
V_308 = V_23 -> V_250 [ V_325 - V_252 ] ?
V_317 : V_323 ;
} else {
V_308 = V_323 ;
}
F_38 ( V_2 , V_348 . V_261 ,
V_348 . V_349 [ 0 ] , V_308 ) ;
return 1 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_3 , long V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_350 ;
int V_351 = V_352 + V_353 ;
int V_36 = 0 ;
int V_257 = V_3 - V_252 ;
if ( ( V_257 < 0 ) || ( V_257 >= V_351 ) )
return 0 ;
if ( ( V_3 >= V_354 ) && ( V_3 < V_355 ) ) {
if ( ! V_23 -> V_250 [ V_251 - V_252 ] )
V_41 = 0 ;
}
if ( ( V_3 >= V_356 ) && ( V_3 < V_357 ) ) {
if ( ! V_23 -> V_250 [ V_325 - V_252 ] )
V_41 = 0 ;
if ( ( V_3 == V_291 ) && ( V_23 -> V_330 != V_331 ) )
V_41 = 0 ;
}
F_12 ( V_121 L_100 ,
V_3 , V_41 ) ;
V_350 = ( V_41 == 0 ) ? V_323 : V_317 ;
V_36 = F_38 ( V_2 , V_358 [ V_257 ] . V_261 ,
V_358 [ V_257 ] . V_349 [ 0 ] , V_350 ) ;
if ( V_36 < 0 )
return 0 ;
return 1 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_258 , V_359 = 0 ;
F_12 ( V_121 L_101 ,
V_23 -> V_250 [ V_251 - V_252 ] ) ;
V_258 = V_354 - V_252 ;
V_3 = V_354 ;
for (; V_3 < V_355 ; V_3 ++ , V_258 ++ )
V_359 |= F_137 ( V_2 , V_3 , V_23 -> V_250 [ V_258 ] ) ;
return V_359 ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_238 = F_2 ( V_2 , V_23 -> V_254 [ 0 ] , 0 ,
V_242 , 0 ) ;
if ( V_238 != 0 )
F_20 ( V_2 , V_23 -> V_254 [ 0 ] , 0 ,
V_13 ,
0 ) ;
return V_238 ;
}
static void F_142 ( struct V_1 * V_2 , unsigned int V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_238 != 0 )
F_20 ( V_2 , V_23 -> V_254 [ 0 ] , 0 ,
V_13 ,
V_238 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_258 , V_359 = 0 ;
unsigned int V_238 ;
F_12 ( V_121 L_102 ,
V_23 -> V_250 [ V_325 - V_252 ] ) ;
V_258 = V_356 - V_252 ;
V_3 = V_356 ;
for (; V_3 < V_357 ; V_3 ++ , V_258 ++ )
V_359 |= F_137 ( V_2 , V_3 , V_23 -> V_250 [ V_258 ] ) ;
V_359 |= F_139 ( V_2 , ( V_23 -> V_360 ? 1 : 0 ) ) ;
V_238 = F_141 ( V_2 ) ;
V_359 |= F_133 ( V_2 , 1 ) ;
F_142 ( V_2 , V_238 ) ;
return V_359 ;
}
static int F_136 ( struct V_1 * V_2 , long V_41 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_359 = 0 ;
if ( V_41 )
V_359 = F_144 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_282 , 0 , V_361 , 3 ) ;
else
V_359 = F_144 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_282 , 0 , V_361 , 0 ) ;
return V_359 ;
}
static int F_145 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
T_1 V_3 = F_115 ( V_263 ) ;
T_1 V_342 = 0 ;
bool V_362 ;
int V_359 = 0 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_307 ;
if ( V_3 == V_313 ) {
V_307 =
V_23 -> V_309 [ V_310 - V_311 ] ;
if ( ! V_307 )
F_130 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_336 ) {
V_307 =
V_23 -> V_309 [ V_334 - V_311 ] ;
if ( ! V_307 )
F_134 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_310 ) {
F_130 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_334 ) {
F_134 ( V_2 ) ;
return 1 ;
}
V_362 = F_138 ( V_2 , V_3 , & V_342 ) ;
if ( V_362 ) {
int V_104 = F_146 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
unsigned long V_364 ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_342 , V_363 ,
0 , V_104 ) ;
V_359 = F_147 ( V_263 , V_265 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
}
return V_359 ;
}
static int F_148 ( struct V_262 * V_263 ,
struct V_270 * V_271 )
{
unsigned int V_366 = sizeof( V_367 )
/ sizeof( struct V_368 ) ;
V_271 -> type = V_369 ;
V_271 -> V_29 = 1 ;
V_271 -> V_267 . V_370 . V_366 = V_366 ;
if ( V_271 -> V_267 . V_370 . V_371 >= V_366 )
V_271 -> V_267 . V_370 . V_371 = V_366 - 1 ;
strcpy ( V_271 -> V_267 . V_370 . V_280 ,
V_367 [ V_271 -> V_267 . V_370 . V_371 ] . V_280 ) ;
return 0 ;
}
static int F_149 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
V_265 -> V_267 . V_370 . V_371 [ 0 ] = V_23 -> V_360 ;
return 0 ;
}
static int F_150 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_258 , V_36 = 0 ;
int V_372 = V_265 -> V_267 . V_370 . V_371 [ 0 ] ;
unsigned int V_366 = sizeof( V_367 )
/ sizeof( struct V_368 ) ;
if ( V_372 >= V_366 )
return 0 ;
F_12 ( V_121 L_103 ,
V_372 , V_367 [ V_372 ] . V_280 ) ;
for ( V_258 = 0 ; V_258 < V_373 ; V_258 ++ ) {
V_36 = F_38 ( V_2 , V_348 . V_261 ,
V_348 . V_349 [ V_258 ] ,
V_367 [ V_372 ] . V_374 [ V_258 ] ) ;
if ( V_36 < 0 )
break;
}
if ( V_36 >= 0 ) {
V_23 -> V_360 = V_372 ;
F_139 ( V_2 , ( V_372 ? 1 : 0 ) ) ;
}
return 1 ;
}
static int F_151 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
if ( ( V_3 >= V_311 ) && ( V_3 < V_375 ) ) {
if ( V_363 & 1 ) {
* V_266 = V_23 -> V_309 [ V_3 - V_311 ] ;
V_266 ++ ;
}
if ( V_363 & 2 ) {
* V_266 = V_23 -> V_376 [ V_3 - V_311 ] ;
V_266 ++ ;
}
return 0 ;
}
if ( ( V_3 >= V_252 ) && ( V_3 < V_377 ) ) {
* V_266 = V_23 -> V_250 [ V_3 - V_252 ] ;
return 0 ;
}
if ( V_3 == V_23 -> V_335 [ 0 ] ) {
* V_266 = V_23 -> V_340 ;
return 0 ;
}
return 0 ;
}
static int F_152 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
int V_378 = 1 ;
F_12 ( V_121 L_104 ,
V_3 , * V_266 ) ;
F_111 ( V_2 ) ;
if ( ( V_3 >= V_311 ) && ( V_3 < V_375 ) ) {
if ( V_363 & 1 ) {
V_23 -> V_309 [ V_3 - V_311 ] = * V_266 ;
V_266 ++ ;
}
if ( V_363 & 2 ) {
V_23 -> V_376 [ V_3 - V_311 ] = * V_266 ;
V_266 ++ ;
}
V_378 = F_145 ( V_263 , V_265 ) ;
goto exit;
}
if ( V_3 == V_251 ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_266 ;
V_378 = F_140 ( V_2 ) ;
goto exit;
}
if ( V_3 == V_325 ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_266 ;
V_378 = F_143 ( V_2 ) ;
goto exit;
}
if ( ( ( V_3 >= V_354 ) && ( V_3 < V_355 ) ) ||
( ( V_3 >= V_356 ) && ( V_3 < V_357 ) ) ) {
V_23 -> V_250 [ V_3 - V_252 ] = * V_266 ;
V_378 = F_137 ( V_2 , V_3 , * V_266 ) ;
goto exit;
}
if ( V_3 == V_23 -> V_335 [ 0 ] ) {
V_23 -> V_340 = * V_266 ;
if ( V_23 -> V_330 != V_331 )
V_378 = F_136 ( V_2 , * V_266 ) ;
goto exit;
}
exit:
F_112 ( V_2 ) ;
return V_378 ;
}
static int F_153 ( struct V_262 * V_263 ,
struct V_270 * V_271 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
int V_104 = F_146 ( V_263 ) ;
unsigned long V_364 ;
int V_36 ;
switch ( V_3 ) {
case V_343 :
V_3 = V_23 -> V_344 ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_3 , V_363 , 0 , V_104 ) ;
V_36 = F_154 ( V_263 , V_271 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
break;
case V_345 :
V_3 = V_23 -> V_346 ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_3 , V_363 , 0 , V_104 ) ;
V_36 = F_154 ( V_263 , V_271 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
break;
default:
V_36 = F_154 ( V_263 , V_271 ) ;
}
return V_36 ;
}
static int F_155 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
if ( V_363 & 1 ) {
* V_266 = V_23 -> V_379 [ V_3 - V_311 ] ;
V_266 ++ ;
}
if ( V_363 & 2 ) {
* V_266 = V_23 -> V_380 [ V_3 - V_311 ] ;
V_266 ++ ;
}
return 0 ;
}
static int F_156 ( struct V_262 * V_263 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
long * V_266 = V_265 -> V_267 . integer . V_267 ;
T_1 V_342 = 0 ;
bool V_362 ;
int V_378 = 1 ;
if ( V_363 & 1 ) {
V_23 -> V_379 [ V_3 - V_311 ] = * V_266 ;
V_266 ++ ;
}
if ( V_363 & 2 ) {
V_23 -> V_380 [ V_3 - V_311 ] = * V_266 ;
V_266 ++ ;
}
V_362 = F_138 ( V_2 , V_3 , & V_342 ) ;
if ( V_362 ) {
int V_104 = F_146 ( V_263 ) ;
unsigned long V_364 ;
F_111 ( V_2 ) ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_342 , V_363 ,
0 , V_104 ) ;
V_378 = F_157 ( V_263 , V_265 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
F_112 ( V_2 ) ;
}
return V_378 ;
}
static int F_158 ( struct V_262 * V_263 , int V_381 ,
unsigned int V_67 , unsigned int T_5 * V_289 )
{
struct V_1 * V_2 = F_114 ( V_263 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_115 ( V_263 ) ;
int V_363 = F_117 ( V_263 ) ;
int V_104 = F_146 ( V_263 ) ;
unsigned long V_364 ;
int V_36 ;
switch ( V_3 ) {
case V_343 :
V_3 = V_23 -> V_344 ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_3 , V_363 , 0 , V_104 ) ;
V_36 = F_159 ( V_263 , V_381 , V_67 , V_289 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
break;
case V_345 :
V_3 = V_23 -> V_346 ;
F_15 ( & V_2 -> V_365 ) ;
V_364 = V_263 -> V_299 ;
V_263 -> V_299 = F_125 ( V_3 , V_363 , 0 , V_104 ) ;
V_36 = F_159 ( V_263 , V_381 , V_67 , V_289 ) ;
V_263 -> V_299 = V_364 ;
F_16 ( & V_2 -> V_365 ) ;
break;
default:
V_36 = F_159 ( V_263 , V_381 , V_67 , V_289 ) ;
}
return V_36 ;
}
static int F_160 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_382 , int V_104 )
{
char V_281 [ 44 ] ;
int type = V_104 ? V_282 : V_283 ;
struct V_284 V_285 =
F_161 ( V_281 , V_3 , 1 , type ) ;
sprintf ( V_281 , L_105 , V_382 , V_300 [ V_104 ] ) ;
return F_126 ( V_2 , V_3 , F_127 ( & V_285 , V_2 ) ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_284 V_285 =
F_163 ( V_348 . V_280 ,
V_383 , 1 , 0 , V_282 ) ;
V_285 . V_292 = F_148 ;
V_285 . V_293 = F_149 ;
V_285 . V_294 = F_150 ;
return F_126 ( V_2 , V_383 , F_127 ( & V_285 , V_2 ) ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_258 , V_351 ;
int V_36 = 0 ;
for ( V_258 = 0 ; V_258 < V_23 -> V_384 ; V_258 ++ ) {
V_36 = F_165 ( V_2 , V_23 -> V_385 [ V_258 ] ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_351 = V_352 + V_353 ;
for ( V_258 = 0 ; V_258 < V_351 ; V_258 ++ ) {
V_36 = F_160 ( V_2 , V_358 [ V_258 ] . V_3 ,
V_358 [ V_258 ] . V_280 ,
V_358 [ V_258 ] . V_302 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_160 ( V_2 , V_251 , L_106 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_160 ( V_2 , V_325 , L_107 , 1 ) ;
if ( V_36 < 0 )
return V_36 ;
F_162 ( V_2 ) ;
#ifdef F_166
F_128 ( V_2 ) ;
#endif
V_36 = F_167 ( V_2 , & V_23 -> V_386 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_23 -> V_387 ) {
V_36 = F_168 ( V_2 , V_23 -> V_387 ,
V_23 -> V_387 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_169 ( V_2 , & V_23 -> V_253 ) ;
if ( V_36 < 0 )
return V_36 ;
}
if ( V_23 -> V_388 ) {
V_36 = F_170 ( V_2 , V_23 -> V_388 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_389 * V_292 = V_23 -> V_390 ;
V_2 -> V_391 = V_292 ;
V_2 -> V_392 = 0 ;
V_292 -> V_280 = L_108 ;
V_292 -> V_10 [ V_393 ] = V_394 ;
V_292 -> V_10 [ V_393 ] . V_3 = V_23 -> V_247 [ 0 ] ;
V_292 -> V_10 [ V_393 ] . V_395 =
V_23 -> V_253 . V_396 ;
V_292 -> V_10 [ V_397 ] = V_398 ;
V_292 -> V_10 [ V_397 ] . V_399 = 1 ;
V_292 -> V_10 [ V_397 ] . V_3 = V_23 -> V_254 [ 0 ] ;
V_2 -> V_392 ++ ;
V_292 ++ ;
V_292 -> V_280 = L_109 ;
V_292 -> V_10 [ V_397 ] = V_398 ;
V_292 -> V_10 [ V_397 ] . V_399 = 1 ;
V_292 -> V_10 [ V_397 ] . V_3 = V_23 -> V_254 [ 1 ] ;
V_2 -> V_392 ++ ;
V_292 ++ ;
V_292 -> V_280 = L_110 ;
V_292 -> V_10 [ V_397 ] = V_398 ;
V_292 -> V_10 [ V_397 ] . V_399 = 1 ;
V_292 -> V_10 [ V_397 ] . V_3 = V_23 -> V_254 [ 2 ] ;
V_2 -> V_392 ++ ;
if ( ! V_23 -> V_387 && ! V_23 -> V_388 )
return 0 ;
V_292 ++ ;
V_292 -> V_280 = L_111 ;
V_292 -> V_400 = V_401 ;
if ( V_23 -> V_387 ) {
V_292 -> V_10 [ V_393 ] =
V_402 ;
V_292 -> V_10 [ V_393 ] . V_3 = V_23 -> V_387 ;
}
if ( V_23 -> V_388 ) {
V_292 -> V_10 [ V_397 ] =
V_403 ;
V_292 -> V_10 [ V_397 ] . V_3 = V_23 -> V_388 ;
}
V_2 -> V_392 ++ ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 , T_1 V_404 , T_1 V_405 )
{
if ( V_404 ) {
F_132 ( V_2 , V_404 , V_321 ) ;
if ( F_173 ( V_2 , V_404 ) & V_406 )
F_20 ( V_2 , V_404 , 0 ,
V_407 ,
V_408 ) ;
}
if ( V_405 && ( F_173 ( V_2 , V_405 ) & V_406 ) )
F_20 ( V_2 , V_405 , 0 ,
V_407 , V_409 ) ;
}
static void F_174 ( struct V_1 * V_2 , T_1 V_404 , T_1 V_410 )
{
if ( V_404 ) {
F_132 ( V_2 , V_404 , V_411 ) ;
if ( F_173 ( V_2 , V_404 ) & V_412 )
F_20 ( V_2 , V_404 , 0 ,
V_407 ,
F_175 ( 0 ) ) ;
}
if ( V_410 && ( F_173 ( V_2 , V_410 ) & V_412 ) ) {
F_20 ( V_2 , V_410 , 0 , V_407 ,
F_175 ( 0 ) ) ;
F_176 ( V_2 , V_410 , V_282 , 0 ,
V_361 , 0x5a ) ;
F_176 ( V_2 , V_410 , V_282 , 0 ,
V_413 , 0 ) ;
}
}
static void F_177 ( struct V_1 * V_2 )
{
F_178 ( V_2 , V_414 , V_414 ) ;
F_178 ( V_2 , V_415 , V_415 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_1 V_3 , int V_104 )
{
unsigned int V_416 ;
V_416 = F_180 ( V_2 , V_3 , V_104 == V_283 ?
V_417 : V_418 ) ;
F_181 ( V_2 , V_3 , V_104 , V_416 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_347 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_308 ;
T_3 V_41 ;
unsigned int V_238 ;
F_12 ( V_121 L_112 , V_347 ) ;
V_238 = F_141 ( V_2 ) ;
F_133 ( V_2 , 0 ) ;
if ( V_347 ) {
V_308 = V_332 ;
F_38 ( V_2 , 0x80 , 0x00 , V_308 ) ;
V_41 = V_23 -> V_419 ;
V_41 |= 0x80 ;
F_20 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_420 , V_41 ) ;
if ( ! ( V_23 -> V_419 & 0x20 ) )
F_19 ( V_2 , V_421 , 1 ) ;
} else {
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x00 , V_308 ) ;
V_41 = V_23 -> V_419 ;
V_41 &= 0x5f ;
F_20 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_420 , V_41 ) ;
if ( ! ( V_23 -> V_419 & 0x20 ) )
F_19 ( V_2 , V_421 , 0 ) ;
}
F_133 ( V_2 , 1 ) ;
F_142 ( V_2 , V_238 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_3 V_41 ;
V_41 = 0x01 ;
F_20 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_422 , V_41 ) ;
V_41 = 0x83 ;
F_20 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_423 , V_41 ) ;
V_41 = 0x23 ;
V_23 -> V_419 = V_41 ;
F_20 ( V_2 , V_23 -> V_335 [ 0 ] , 0 ,
V_420 , V_41 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_15 ( & V_23 -> V_37 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0x20 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_424 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_425 , 0x00 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0x2D ) ;
F_20 ( V_2 , V_18 , 0 ,
V_424 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_425 , 0x00 ) ;
F_16 ( & V_23 -> V_37 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_258 ;
T_1 V_3 ;
F_12 ( V_121 L_113 ) ;
V_3 = V_2 -> V_426 ;
for ( V_258 = 0 ; V_258 < V_2 -> V_427 ; V_258 ++ , V_3 ++ )
V_2 -> V_428 [ V_258 ] = F_180 ( V_2 , V_3 ,
V_429 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_253 . V_430 ; V_258 ++ )
F_179 ( V_2 , V_23 -> V_247 [ V_258 ] , V_283 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_431 ; V_258 ++ )
F_179 ( V_2 , V_23 -> V_312 [ V_258 ] , V_283 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_432 ; V_258 ++ ) {
F_179 ( V_2 , V_23 -> V_254 [ V_258 ] , V_282 ) ;
F_179 ( V_2 , V_23 -> V_335 [ V_258 ] , V_282 ) ;
}
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_308 ;
int V_351 ;
int V_257 , V_258 ;
if ( V_23 -> V_248 != V_324 )
return;
V_351 = V_352 + V_353 + 1 ;
for ( V_257 = 0 ; V_257 < V_351 ; V_257 ++ ) {
for ( V_258 = 0 ; V_258 <= V_358 [ V_257 ] . V_433 ; V_258 ++ ) {
F_38 ( V_2 , V_358 [ V_257 ] . V_261 ,
V_358 [ V_257 ] . V_349 [ V_258 ] ,
V_358 [ V_257 ] . V_434 [ V_258 ] ) ;
}
}
V_308 = V_323 ;
F_38 ( V_2 , 0x96 , 0x3C , V_308 ) ;
F_38 ( V_2 , 0x8f , 0x01 , V_308 ) ;
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x00 , V_308 ) ;
F_38 ( V_2 , 0x80 , 0x01 , V_308 ) ;
V_308 = V_317 ;
F_38 ( V_2 , 0x80 , 0x05 , V_308 ) ;
V_308 = V_332 ;
F_38 ( V_2 , 0x31 , 0x00 , V_308 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_435 , 0 ) ;
F_19 ( V_2 , V_436 , 0 ) ;
F_19 ( V_2 , V_437 , 0 ) ;
F_19 ( V_2 , V_438 , 0 ) ;
F_19 ( V_2 , V_439 , 0 ) ;
F_19 ( V_2 , V_440 , 1 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_441 , 6 ) ;
F_21 ( V_2 , V_442 , 6 ) ;
}
static void F_188 ( struct V_1 * V_2 , bool V_443 )
{
F_19 ( V_2 , V_444 , V_443 ) ;
F_19 ( V_2 , V_445 , V_443 ) ;
F_19 ( V_2 , V_446 , V_443 ) ;
F_19 ( V_2 , V_447 , V_443 ) ;
F_19 ( V_2 , V_448 , V_443 ) ;
F_19 ( V_2 , V_449 , V_443 ) ;
F_22 ( V_2 , V_327 , V_328 ) ;
F_22 ( V_2 , V_329 , V_328 ) ;
F_22 ( V_2 , V_450 , V_451 ) ;
}
static bool F_189 ( struct V_1 * V_2 )
{
bool V_452 = false ;
const struct V_206 * V_453 ;
const struct V_454 * V_455 ;
if ( F_190 ( & V_455 , V_456 , V_2 -> V_457 -> V_458 -> V_459 ) != 0 )
return false ;
V_453 = (struct V_206 * ) ( V_455 -> V_15 ) ;
if ( F_91 ( V_2 , V_453 , 0 , 0 , true , 0 ) ) {
F_95 ( L_114 ) ;
goto V_460;
}
V_452 = F_93 ( V_2 ) ;
V_460:
F_191 ( V_455 ) ;
return V_452 ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
#ifndef F_193
return;
#endif
F_23 ( V_2 ) ;
V_23 -> V_248 = V_249 ;
if ( ! F_189 ( V_2 ) )
V_23 -> V_248 = V_461 ;
else
V_23 -> V_248 = V_324 ;
if ( V_23 -> V_248 == V_324 )
F_188 ( V_2 , true ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_12 ( V_121 L_115 ) ;
if ( V_23 -> V_101 ) {
if ( F_33 ( V_2 ) >= 0 )
V_23 -> V_101 = 0 ;
}
F_32 ( V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_12 ( V_121 L_116 , V_6 ) ;
if ( ( ( V_6 >> V_462 ) & 0x3f ) == V_463 ) {
F_194 ( V_2 ) ;
} else {
V_6 = F_196 ( V_2 ,
( V_6 >> V_462 ) & 0x3f ) ;
F_12 ( V_121 L_117 , V_6 ) ;
switch ( V_6 ) {
case V_414 :
F_130 ( V_2 ) ;
F_197 ( V_2 ) ;
break;
case V_415 :
F_134 ( V_2 ) ;
F_197 ( V_2 ) ;
break;
default:
break;
}
}
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_351 ;
int V_258 ;
unsigned int V_350 ;
F_199 ( & V_23 -> V_37 ) ;
V_23 -> V_314 = V_316 ;
V_23 -> V_330 = V_331 ;
V_23 -> V_340 = 0 ;
for ( V_258 = 0 ; V_258 < V_464 ; V_258 ++ ) {
V_23 -> V_379 [ V_258 ] = 0x5a ;
V_23 -> V_380 [ V_258 ] = 0x5a ;
V_23 -> V_309 [ V_258 ] = 0 ;
V_23 -> V_376 [ V_258 ] = 0 ;
}
V_351 = V_352 + V_353 ;
for ( V_258 = 0 ; V_258 < V_351 ; V_258 ++ ) {
V_350 = ( unsigned int ) V_358 [ V_258 ] . V_349 [ 0 ] ;
V_23 -> V_250 [ V_258 ] = V_350 ? 1 : 0 ;
}
V_23 -> V_360 = 0 ;
V_23 -> V_250 [ V_251 - V_252 ] = 1 ;
V_23 -> V_250 [ V_325 - V_252 ] = 0 ;
#ifdef F_166
F_129 ( V_2 ) ;
#endif
}
static void F_200 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
F_42 ( V_2 ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_465 * V_466 = & V_23 -> V_386 ;
int V_258 ;
V_23 -> V_248 = V_467 ;
V_23 -> V_24 = V_138 ;
F_111 ( V_2 ) ;
F_187 ( V_2 ) ;
F_186 ( V_2 ) ;
F_202 ( V_2 , V_23 -> V_468 ) ;
F_192 ( V_2 ) ;
F_184 ( V_2 ) ;
F_185 ( V_2 ) ;
F_183 ( V_2 ) ;
F_182 ( V_2 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_431 ; V_258 ++ )
F_172 ( V_2 , V_23 -> V_312 [ V_258 ] , V_23 -> V_247 [ 0 ] ) ;
F_172 ( V_2 , V_466 -> V_469 [ 0 ] , V_23 -> V_387 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_432 ; V_258 ++ )
F_174 ( V_2 , V_23 -> V_335 [ V_258 ] , V_23 -> V_254 [ V_258 ] ) ;
F_174 ( V_2 , V_466 -> V_470 , V_23 -> V_388 ) ;
for ( V_258 = 0 ; V_258 < V_23 -> V_471 ; V_258 ++ )
F_202 ( V_2 , V_23 -> V_472 [ V_258 ] ) ;
F_177 ( V_2 ) ;
F_130 ( V_2 ) ;
F_134 ( V_2 ) ;
F_197 ( V_2 ) ;
F_112 ( V_2 ) ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_111 ( V_2 ) ;
F_202 ( V_2 , V_23 -> V_473 ) ;
F_200 ( V_2 ) ;
F_112 ( V_2 ) ;
F_88 ( V_2 -> V_23 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_465 * V_466 = & V_23 -> V_386 ;
V_23 -> V_247 [ 0 ] = 0x2 ;
V_23 -> V_247 [ 1 ] = 0x3 ;
V_23 -> V_247 [ 2 ] = 0x4 ;
V_23 -> V_253 . V_474 = V_23 -> V_247 ;
V_23 -> V_253 . V_430 = 3 ;
V_23 -> V_253 . V_396 = 2 ;
V_23 -> V_431 = 2 ;
V_23 -> V_312 [ 0 ] = 0x0b ;
V_23 -> V_312 [ 1 ] = 0x10 ;
V_23 -> V_344 = 0x2 ;
V_23 -> V_432 = 3 ;
V_23 -> V_254 [ 0 ] = 0x7 ;
V_23 -> V_254 [ 1 ] = 0x8 ;
V_23 -> V_254 [ 2 ] = 0xa ;
V_23 -> V_346 = 0x7 ;
V_23 -> V_335 [ 0 ] = 0x12 ;
V_23 -> V_335 [ 1 ] = 0x11 ;
V_23 -> V_335 [ 2 ] = 0x13 ;
V_23 -> V_387 = 0x05 ;
V_23 -> V_253 . V_475 = V_23 -> V_387 ;
V_466 -> V_469 [ 0 ] = 0x0c ;
V_466 -> V_476 = 1 ;
V_466 -> V_477 [ 0 ] = V_401 ;
V_23 -> V_388 = 0x09 ;
V_466 -> V_470 = 0x0e ;
V_466 -> V_478 = V_401 ;
}
static int F_205 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_36 ;
F_12 ( L_118 ) ;
V_23 = F_87 ( sizeof( * V_23 ) , V_227 ) ;
if ( ! V_23 )
return - V_228 ;
V_2 -> V_23 = V_23 ;
V_23 -> V_384 = 1 ;
V_23 -> V_385 [ 0 ] = V_479 ;
V_23 -> V_468 = V_480 ;
V_23 -> V_473 = V_481 ;
V_23 -> V_472 [ 0 ] = V_482 ;
V_23 -> V_472 [ 1 ] = V_483 ;
V_23 -> V_471 = 2 ;
F_198 ( V_2 ) ;
F_204 ( V_2 ) ;
V_36 = F_206 ( V_2 , & V_23 -> V_386 , NULL ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_484 = V_485 ;
return 0 ;
}
static int T_6 F_207 ( void )
{
return F_208 ( & V_486 ) ;
}
static void T_7 F_209 ( void )
{
F_210 ( & V_486 ) ;
}
