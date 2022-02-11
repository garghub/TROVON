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
V_23 -> V_24 = ( V_6 < 0 ) ? ~ 0U : V_21 ;
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
( V_23 -> V_24 + 4 ) : ~ 0U ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_2 * V_15 ,
unsigned int V_29 )
{
int V_30 = 0 ;
if ( V_15 == NULL ) {
F_12 ( V_2 , L_1 ) ;
return - V_31 ;
}
while ( ( V_29 -- != 0 ) && ( V_30 == 0 ) )
V_30 = F_10 ( V_2 , * V_15 ++ ) ;
return V_30 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int * V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_32 , 0 ) ;
if ( V_6 != - V_20 ) {
V_6 = F_5 ( V_2 , V_33 , 0 ) ;
}
if ( V_6 != - V_20 ) {
* V_15 = F_2 ( V_2 , V_18 , 0 ,
V_34 ,
0 ) ;
}
V_23 -> V_24 = ( V_6 != - V_20 ) ?
( V_23 -> V_24 + 4 ) : ~ 0U ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_21 , const unsigned int V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_35 ;
F_15 ( & V_23 -> V_36 ) ;
V_35 = F_9 ( V_2 , V_21 ) ;
if ( V_35 < 0 )
goto exit;
V_35 = F_10 ( V_2 , V_15 ) ;
if ( V_35 < 0 )
goto exit;
exit:
F_16 ( & V_23 -> V_36 ) ;
return V_35 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_2 V_21 ,
const T_2 * V_15 ,
unsigned int V_29 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
F_15 ( & V_23 -> V_36 ) ;
V_30 = F_9 ( V_2 , V_21 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_11 ( V_2 , V_15 , V_29 ) ;
error:
F_16 ( & V_23 -> V_36 ) ;
return V_30 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_21 , unsigned int * V_15 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_35 ;
F_15 ( & V_23 -> V_36 ) ;
V_35 = F_9 ( V_2 , V_21 ) ;
if ( V_35 < 0 )
goto exit;
V_35 = F_13 ( V_2 , V_15 ) ;
if ( V_35 < 0 )
goto exit;
exit:
F_16 ( & V_23 -> V_36 ) ;
return V_35 ;
}
static void F_19 ( struct V_1 * V_2 ,
enum V_37 V_38 ,
bool V_39 )
{
unsigned int V_40 ;
unsigned int V_41 ;
V_41 = ( V_39 ? 1 : 0 ) ;
V_40 = ( V_41 << 7 ) | ( V_38 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_42 , V_40 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_43 V_44 , int V_45 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_40 ;
if ( ( V_44 < 32 ) && ( V_45 < 8 ) ) {
V_40 = ( V_45 << 5 ) | ( V_44 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_46 , V_40 ) ;
} else {
F_15 ( & V_23 -> V_36 ) ;
if ( F_5 ( V_2 , V_33 , 0 ) == 0 ) {
F_20 ( V_2 , V_18 , 0 ,
V_47 ,
V_44 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_48 ,
V_45 ) ;
}
F_16 ( & V_23 -> V_36 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
int V_49 , enum V_50 V_51 )
{
F_21 ( V_2 , V_52 , V_49 ) ;
F_21 ( V_2 , V_53 ,
V_51 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_15 ( & V_23 -> V_36 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_54 , 0 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0xff ) ;
F_20 ( V_2 , V_18 , 0 ,
V_54 , 5 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0x0b ) ;
F_20 ( V_2 , V_18 , 0 ,
V_54 , 6 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_55 , 0xff ) ;
F_16 ( & V_23 -> V_36 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 )
{
int V_6 ;
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
do {
V_6 = F_2 ( V_2 , V_56 , 0 , V_14 , V_15 ) ;
if ( ( V_6 >= 0 ) && ( V_6 != V_57 ) )
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
V_30 = F_2 ( V_2 , V_56 , 0 ,
V_58 , 0 ) ;
if ( ( V_30 == V_59 ) ||
( V_30 == V_60 ) )
break;
F_7 ( 1 ) ;
} while ( F_8 ( V_17 , V_16 ) );
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
F_25 ( V_2 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_30 = F_24 ( V_2 , V_62 ,
V_61 & 0xffff ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_24 ( V_2 , V_63 ,
V_61 >> 16 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_2 ( V_2 , V_56 , 0 ,
V_58 , 0 ) ;
error:
F_16 ( & V_23 -> V_36 ) ;
return ( V_30 == V_64 ) ?
- V_20 : 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int * V_65 , unsigned int V_66 )
{
int V_30 = 0 ;
unsigned int V_29 ;
if ( V_65 == NULL )
return - V_31 ;
V_29 = 0 ;
while ( V_29 < V_66 ) {
V_30 = F_26 ( V_2 , * V_65 ++ ) ;
if ( V_30 != 0 )
break;
V_29 ++ ;
}
return V_30 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int * V_15 )
{
int V_30 ;
V_30 = F_24 ( V_2 , V_67 , 0 ) ;
if ( V_30 == - V_20 )
return V_30 ;
V_30 = F_24 ( V_2 , V_58 , 0 ) ;
if ( V_30 == - V_20 ||
V_30 == V_60 )
return - V_20 ;
* V_15 = F_2 ( V_2 , V_56 , 0 ,
V_68 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int * V_65 ,
unsigned int * V_69 , unsigned int V_70 )
{
int V_30 = 0 ;
unsigned int V_66 = * V_69 ;
unsigned int V_29 ;
unsigned int V_71 ;
unsigned int V_72 ;
if ( V_65 == NULL )
return - 1 ;
V_29 = 0 ;
while ( V_29 < V_66 && V_29 < V_70 ) {
V_30 = F_28 ( V_2 , V_65 ++ ) ;
if ( V_30 != 0 )
break;
V_29 ++ ;
}
V_71 = V_29 ;
if ( V_30 == 0 ) {
while ( V_71 < V_66 ) {
V_30 = F_28 ( V_2 , & V_72 ) ;
if ( V_30 != 0 )
break;
V_71 ++ ;
}
}
* V_69 = V_29 ;
return V_30 ;
}
static inline unsigned int
F_30 ( unsigned int V_73 , unsigned int V_74 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 , unsigned int V_78 ,
unsigned int V_79 , unsigned int V_80 )
{
unsigned int V_81 = 0 ;
V_81 = ( V_80 & 0x1f ) << 27 ;
V_81 |= ( V_79 & 0x01 ) << 26 ;
V_81 |= ( V_78 & 0x01 ) << 25 ;
V_81 |= ( V_77 & 0x01 ) << 24 ;
V_81 |= ( V_76 & 0x7f ) << 17 ;
V_81 |= ( V_75 & 0x01 ) << 16 ;
V_81 |= ( V_74 & 0xff ) << 8 ;
V_81 |= V_73 & 0xff ;
return V_81 ;
}
static inline void
F_31 ( unsigned int V_81 ,
unsigned int * V_73 , unsigned int * V_74 ,
unsigned int * V_75 , unsigned int * V_76 ,
unsigned int * V_77 , unsigned int * V_78 ,
unsigned int * V_79 , unsigned int * V_80 )
{
if ( V_80 )
* V_80 = ( V_81 >> 27 ) & 0x1f ;
if ( V_79 )
* V_79 = ( V_81 >> 26 ) & 0x01 ;
if ( V_78 )
* V_78 = ( V_81 >> 25 ) & 0x01 ;
if ( V_77 )
* V_77 = ( V_81 >> 24 ) & 0x01 ;
if ( V_76 )
* V_76 = ( V_81 >> 17 ) & 0x7f ;
if ( V_75 )
* V_75 = ( V_81 >> 16 ) & 0x01 ;
if ( V_74 )
* V_74 = ( V_81 >> 8 ) & 0xff ;
if ( V_73 )
* V_73 = V_81 & 0xff ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned int V_72 = 0 ;
int V_30 = - 1 ;
do {
V_30 = F_28 ( V_2 , & V_72 ) ;
} while ( V_30 == 0 );
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_15 = 0 ;
unsigned int V_29 ;
if ( F_28 ( V_2 , & V_15 ) < 0 )
return - V_20 ;
if ( ( V_15 & 0x00ffffff ) == V_23 -> V_82 ) {
V_23 -> V_83 = V_15 ;
V_23 -> V_84 = V_15 >> 27 ;
V_29 = V_23 -> V_85 ;
F_29 ( V_2 , V_23 -> V_86 ,
& V_23 -> V_84 , V_29 ) ;
return 0 ;
}
return - V_20 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned char * V_87 ,
unsigned int V_88 ,
unsigned char * V_89 ,
unsigned int V_90 ,
unsigned int * V_91 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 = - 1 ;
unsigned int V_92 = 0 ;
unsigned int V_93 ;
bool V_94 = false ;
unsigned int V_81 ;
struct V_95 * V_96 ;
unsigned int V_97 , V_98 ;
unsigned int V_80 , V_99 , V_73 , V_75 , V_77 ;
if ( V_91 )
* V_91 = 0 ;
V_81 = * ( ( unsigned int * ) V_87 ) ;
F_31 ( V_81 , & V_73 , & V_99 , & V_75 , NULL ,
& V_77 , NULL , NULL , & V_80 ) ;
V_92 = V_80 + 1 ;
V_93 = ( V_92 * 4 ) ;
if ( V_88 < V_93 )
return - V_31 ;
if ( V_75 || V_77 ) {
if ( ! V_89 || V_90 < 4 || ! V_91 )
return - V_31 ;
V_23 -> V_82 = * ( ( unsigned int * ) V_87 ) ;
V_98 = V_99 ;
V_97 = V_73 ;
V_23 -> V_82 &= 0xffff0000 ;
V_23 -> V_82 |= ( V_97 << 8 ) | ( V_98 ) ;
V_23 -> V_85 = V_90 /sizeof( unsigned int ) - 1 ;
V_23 -> V_100 = 1 ;
V_94 = true ;
}
V_30 = F_27 ( V_2 , ( unsigned int * ) V_87 ,
V_92 ) ;
if ( V_30 < 0 ) {
V_23 -> V_100 = 0 ;
return V_30 ;
}
if ( V_94 ) {
unsigned long V_16 = V_17 + F_6 ( 1000 ) ;
memset ( V_89 , 0 , V_90 ) ;
do {
F_7 ( 20 ) ;
} while ( V_23 -> V_100 && F_8 ( V_17 , V_16 ) );
V_94 = false ;
if ( ! V_23 -> V_100 ) {
V_96 = (struct V_95 * ) V_89 ;
memcpy ( & V_96 -> V_101 , & V_23 -> V_83 , 4 ) ;
memcpy ( & V_96 -> V_15 , V_23 -> V_86 ,
V_23 -> V_85 ) ;
* V_91 = ( V_23 -> V_84 + 1 ) * 4 ;
V_30 = 0 ;
} else {
V_30 = - V_20 ;
}
V_23 -> V_100 = 0 ;
}
return V_30 ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_102 , int V_76 , int V_103 , void * V_15 , unsigned int V_104 ,
void * V_105 , unsigned int * V_106 )
{
int V_30 = 0 ;
struct V_95 V_107 , V_108 ;
unsigned int V_109 , V_110 , V_111 ;
unsigned int V_112 , V_113 , V_114 ;
unsigned int V_115 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
if ( ( V_104 != 0 && V_15 == NULL ) || ( V_104 > V_116 ) )
return - V_31 ;
if ( V_103 == V_117 && V_105 == NULL ) {
F_12 ( V_2 , L_2 ) ;
return - V_31 ;
}
if ( V_105 != NULL && ( V_106 == NULL || ( * V_106 == 0 ) ) ) {
F_12 ( V_2 , L_3 ) ;
return - V_31 ;
}
V_107 . V_101 = F_30 ( V_102 , 0x20 , ( V_103 == V_117 ) , V_76 ,
0 , 0 , 0 , V_104 /sizeof( unsigned int ) ) ;
if ( V_15 != NULL && V_104 > 0 ) {
V_104 = F_36 ( ( unsigned int ) ( sizeof( V_107 . V_15 ) ) , V_104 ) ;
memcpy ( V_107 . V_15 , V_15 , V_104 ) ;
}
V_109 = 0 ;
V_110 = sizeof( unsigned int ) + V_104 ;
V_30 = F_34 ( V_2 , ( unsigned char * ) & V_107 ,
V_110 , ( unsigned char * ) & V_108 ,
sizeof( V_108 ) , & V_109 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_4 ) ;
return V_30 ;
}
F_31 ( V_107 . V_101 , NULL , NULL , & V_112 ,
NULL , NULL , NULL , NULL , NULL ) ;
F_31 ( V_108 . V_101 , NULL , NULL , NULL , NULL , NULL ,
& V_113 , & V_114 ,
& V_115 ) ;
if ( ! V_112 )
return 0 ;
if ( V_113 && ! V_114 ) {
V_111 = ( V_109 - sizeof( V_108 . V_101 ) )
/ sizeof( unsigned int ) ;
if ( * V_106 < V_111 *sizeof( unsigned int ) ) {
F_12 ( V_2 , L_5 ) ;
return - V_31 ;
} else if ( V_111 != V_115 ) {
F_12 ( V_2 , L_6 ) ;
return - V_31 ;
} else if ( ! V_105 ) {
F_12 ( V_2 , L_7 ) ;
return - V_31 ;
} else {
* V_106 = V_111 *sizeof( unsigned int ) ;
memcpy ( V_105 , V_108 . V_15 , * V_106 ) ;
}
} else {
F_12 ( V_2 , L_8 ) ;
return - V_20 ;
}
return V_30 ;
}
static int F_37 ( struct V_1 * V_2 , int V_102 ,
int V_76 , void * V_15 , unsigned int V_104 )
{
return F_35 ( V_2 , V_102 , V_76 , V_118 , V_15 , V_104 , NULL , NULL ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_102 ,
int V_76 , unsigned int V_15 )
{
return F_37 ( V_2 , V_102 , V_76 , & V_15 , sizeof( unsigned int ) ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int * V_119 )
{
int V_30 = 0 ;
unsigned int V_66 = sizeof( V_119 ) ;
F_12 ( V_2 , L_9 ) ;
V_30 = F_35 ( V_2 , V_120 , V_121 ,
V_117 , NULL , 0 , V_119 , & V_66 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_10 ) ;
return V_30 ;
}
if ( ( * V_119 + 1 ) == 0 ) {
F_12 ( V_2 , L_11 ) ;
return - V_122 ;
}
F_12 ( V_2 , L_12 , * V_119 ) ;
F_12 ( V_2 , L_13 ) ;
return V_30 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_119 )
{
int V_30 = 0 ;
unsigned int V_72 = 0 ;
F_12 ( V_2 , L_14 ) ;
F_12 ( V_2 , L_15 , V_119 ) ;
V_30 = F_35 ( V_2 , V_120 , V_121 ,
V_118 , & V_119 , sizeof( V_119 ) , NULL , & V_72 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_16 ) ;
return V_30 ;
}
F_12 ( V_2 , L_17 ) ;
return V_30 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
unsigned int V_124 ;
int V_35 ;
V_35 = F_18 ( V_2 , V_125 , & V_123 ) ;
if ( V_35 < 0 )
return V_35 ;
V_124 = ( V_123 & V_126 ) >>
V_127 ;
if ( V_124 != 0 ) {
V_123 &= ~ ( ( V_124 << V_128 ) &
V_129 ) ;
V_35 = F_14 ( V_2 , V_125 ,
V_123 ) ;
if ( V_35 < 0 )
return V_35 ;
V_123 |= ( V_124 << V_130 ) &
V_131 ;
V_35 = F_14 ( V_2 , V_125 ,
V_123 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
int V_132 = 20 ;
F_12 ( V_2 , L_18 ) ;
do {
V_6 = F_24 ( V_2 , V_133 , 0 ) ;
V_132 -- ;
} while ( V_6 == - V_20 && V_132 );
if ( ! V_132 ) {
F_12 ( V_2 , L_19 ) ;
return - V_20 ;
}
return 0 ;
}
static unsigned int F_43 ( unsigned int V_21 ,
bool * V_134 , bool * V_135 )
{
* V_134 = * V_135 = false ;
if ( F_44 ( V_21 , 1 ) ) {
* V_134 = true ;
return F_45 ( V_21 ) ;
} else if ( F_46 ( V_21 , 1 ) ) {
return F_47 ( V_21 ) ;
} else if ( F_48 ( V_21 , 1 ) ) {
* V_135 = true ;
return F_49 ( V_21 ) ;
}
return V_136 ;
}
static bool F_50 ( struct V_1 * V_2 , unsigned int V_119 )
{
unsigned int V_137 ;
F_18 ( V_2 , V_138 , & V_137 ) ;
return ( ( V_137 & ( 1 <<
( V_139 + V_119 ) ) ) != 0 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_119 ,
unsigned int V_140 ,
bool V_141 )
{
int V_30 = 0 ;
unsigned int V_142 ;
unsigned int V_143 ;
unsigned int V_144 ;
bool V_134 , V_135 ;
F_12 ( V_2 , L_20 ) ;
if ( V_119 >= V_145 ) {
F_12 ( V_2 , L_21 ) ;
return - V_31 ;
}
if ( F_50 ( V_2 , V_119 ) ) {
F_12 ( V_2 , L_22 ) ;
return - V_122 ;
}
V_143 = F_43 ( V_21 , & V_134 , & V_135 ) ;
if ( V_143 == V_136 ) {
F_12 ( V_2 , L_23 ) ;
return - V_146 ;
}
V_142 = V_147 ;
V_144 = 0 ;
F_12 ( V_2 , L_24 ) ;
if ( V_141 ) {
V_30 = F_18 ( V_2 , V_148 ,
& V_142 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_25 ) ;
return V_30 ;
}
F_12 ( V_2 , L_26 ) ;
}
if ( ! V_134 )
V_142 &= ~ ( 1 << ( V_149 + V_119 ) ) ;
else
V_142 |= ( 1 << ( V_149 + V_119 ) ) ;
V_142 &= ~ ( 1 << ( V_150 + V_119 ) ) ;
V_30 = F_14 ( V_2 , V_148 , V_142 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_27 ) ;
return V_30 ;
}
F_12 ( V_2 , L_28 ) ;
if ( V_141 ) {
V_30 = F_18 ( V_2 , V_151 ,
& V_144 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_29 ) ;
return V_30 ;
}
F_12 ( V_2 , L_30 ) ;
}
V_144 &= ( ~ ( 1 << ( V_152 + V_119 ) ) ) &
V_153 ;
V_30 = F_14 ( V_2 , V_151 , V_144 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_31 ) ;
return V_30 ;
}
F_12 ( V_2 , L_32 ) ;
V_30 = F_14 ( V_2 , F_52 ( V_119 ) ,
V_140 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_33 ) ;
return V_30 ;
}
F_12 ( V_2 , L_34 ) ;
V_30 = F_14 ( V_2 , F_53 ( V_119 ) ,
V_154 | V_155 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_35 ) ;
return V_30 ;
}
F_12 ( V_2 , L_36 ) ;
F_12 ( V_2 ,
L_37
L_38 ,
V_21 , V_143 , V_119 ,
V_140 , V_142 , V_144 ) ;
F_12 ( V_2 , L_39 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_29 ,
unsigned int V_119 )
{
int V_30 = 0 ;
bool V_134 , V_135 ;
unsigned int V_143 ;
unsigned int V_156 ;
unsigned int V_157 ;
unsigned int V_158 ;
unsigned int V_159 ;
unsigned int V_160 = 0 ;
unsigned int V_161 = 0 ;
unsigned int V_162 = 0 ;
const unsigned int V_163 = 1 << ( V_164 -
V_165 + 1 ) ;
F_12 ( V_2 , L_40 ) ;
if ( V_29 > V_163 ) {
F_12 ( V_2 , L_41 ) ;
return - V_31 ;
}
V_143 = F_43 ( V_21 , & V_134 , & V_135 ) ;
if ( V_143 == V_136 ) {
F_12 ( V_2 , L_23 ) ;
return - V_146 ;
}
F_12 ( V_2 , L_42 ) ;
V_156 = V_143 << V_166 ;
V_157 = 0 ;
if ( ! V_134 ) {
V_156 <<= 1 ;
if ( V_135 )
V_156 |= ( 1 << V_166 ) ;
V_157 = ( 1 << V_167 ) ;
}
V_160 = V_156 + V_157 ;
V_30 = F_14 ( V_2 , F_55 ( V_119 ) ,
V_160 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_43 ) ;
return V_30 ;
}
F_12 ( V_2 , L_44 ) ;
V_161 = ( V_29 - 1 ) << ( V_168 +
( V_134 ? 0 : 1 ) ) ;
V_30 = F_14 ( V_2 , F_56 ( V_119 ) ,
V_161 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_45 ) ;
return V_30 ;
}
F_12 ( V_2 , L_46 ) ;
V_158 = ( V_29 - 1 ) << V_165 ;
V_159 = ( V_29 - 1 ) << V_169 ;
V_162 = V_158 | V_159 ;
V_30 = F_14 ( V_2 ,
F_57 ( V_119 ) , V_162 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_47 ) ;
return V_30 ;
}
F_12 ( V_2 , L_48 ) ;
F_12 ( V_2 ,
L_49
L_50 ,
V_21 , V_29 , V_160 , V_161 , V_162 ) ;
F_12 ( V_2 , L_51 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_119 , bool V_141 )
{
unsigned int V_14 = 0 ;
int V_30 = 0 ;
F_12 ( V_2 , L_52 ) ;
if ( V_141 ) {
V_30 = F_18 ( V_2 ,
V_138 , & V_14 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_53 ) ;
return V_30 ;
}
F_12 ( V_2 , L_54 ) ;
V_14 &= ~ ( V_170 |
V_171 ) ;
}
V_30 = F_14 ( V_2 , V_138 ,
V_14 | ( 1 << ( V_119 + V_139 ) ) ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_55 ) ;
return V_30 ;
}
F_12 ( V_2 , L_56 ) ;
return V_30 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_119 , bool V_141 )
{
unsigned int V_14 = 0 ;
int V_30 = 0 ;
F_12 ( V_2 , L_57 ) ;
if ( V_141 ) {
V_30 = F_18 ( V_2 ,
V_138 , & V_14 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_53 ) ;
return V_30 ;
}
F_12 ( V_2 , L_58 ) ;
V_14 &= ~ ( V_170 |
V_171 ) ;
}
V_30 = F_14 ( V_2 , V_138 ,
V_14 | ( 1 << ( V_119 + V_172 ) ) ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_55 ) ;
return V_30 ;
}
F_12 ( V_2 , L_59 ) ;
return V_30 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned int V_173 ,
unsigned int V_174 ,
unsigned int V_175 ,
unsigned int * V_176 )
{
int V_30 = 0 ;
int V_6 ;
T_3 V_40 ;
V_30 = F_5 ( V_2 , V_33 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_40 = V_175 << 6 ;
V_40 |= ( V_174 - 1 ) << 4 ;
V_40 |= V_173 - 1 ;
F_20 ( V_2 , V_18 , 0 ,
V_177 ,
V_40 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_178 ,
V_179 ) ;
V_30 = F_5 ( V_2 , V_33 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 = F_2 ( V_2 , V_18 , 0 ,
V_180 , 0 ) ;
* V_176 = V_6 ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
V_30 = F_5 ( V_2 , V_33 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
F_20 ( V_2 , V_18 , 0 ,
V_181 ,
V_179 ) ;
V_30 = F_5 ( V_2 , V_33 , 0 ) ;
return V_30 ;
}
static int F_62 ( struct V_1 * V_2 ,
unsigned int V_173 ,
unsigned int V_182 , unsigned int * V_176 )
{
int V_30 ;
F_12 ( V_2 , L_60 ) ;
if ( ( V_182 != 1 ) && ( V_182 != 2 ) && ( V_182 != 4 ) ) {
F_12 ( V_2 , L_61 ) ;
return - V_31 ;
}
V_30 = F_60 ( V_2 , V_173 ,
V_182 , 0 , V_176 ) ;
F_12 ( V_2 , L_62 ) ;
return V_30 ;
}
static int F_63 ( struct V_1 * V_2 ,
const unsigned short V_183 ,
unsigned int * V_176 )
{
int V_30 ;
unsigned int V_173 ;
unsigned int V_184 = ( ( F_64 ( V_183 ) >> 0 ) & 3 ) + 1 ;
unsigned int V_185 = ( ( F_64 ( V_183 ) >> 3 ) & 3 ) + 1 ;
unsigned int V_182 = V_185 / V_184 ;
if ( ( V_182 != 1 ) && ( V_182 != 2 ) && ( V_182 != 4 ) ) {
F_12 ( V_2 , L_61 ) ;
return - V_31 ;
}
V_173 = F_65 ( V_183 ) + 1 ;
V_30 = F_62 ( V_2 , V_173 , V_182 , V_176 ) ;
return V_30 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_30 ;
F_12 ( V_2 , L_63 ) ;
V_30 = F_61 ( V_2 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_64 ) ;
return V_30 ;
}
F_12 ( V_2 , L_65 ) ;
return V_30 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned int V_186 ,
unsigned short V_187 ,
unsigned short * V_188 )
{
unsigned int V_189 ;
V_189 = F_68 ( V_186 ,
V_187 , V_190 , 32 , 0 ) ;
if ( V_188 )
* V_188 = ( unsigned short ) V_189 ;
return 0 ;
}
static int F_69 ( struct V_191 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_2 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
if ( V_192 -> V_193 -> V_194 )
F_70 ( V_2 , V_192 -> V_193 ) ;
V_30 = F_71 ( V_2 ,
V_192 -> V_195 ,
V_192 -> V_69 ,
V_192 -> V_193 ) ;
if ( V_30 < 0 )
return V_30 ;
V_23 -> V_196 = V_30 ;
return 0 ;
}
static int F_72 ( struct V_191 * V_192 , enum V_197 V_198 )
{
bool V_199 ;
switch ( V_198 ) {
case V_200 :
V_199 = false ;
break;
case V_201 :
V_199 = true ;
break;
default:
return 0 ;
}
F_73 ( V_192 -> V_2 , V_199 ) ;
return 0 ;
}
static unsigned int F_74 ( struct V_191 * V_192 )
{
return V_192 -> V_193 -> V_202 ;
}
static unsigned char * F_75 ( struct V_191 * V_192 )
{
return V_192 -> V_193 -> V_194 ;
}
static int F_76 ( struct V_191 * V_192 ,
const unsigned int * V_15 ,
unsigned int V_29 )
{
memcpy ( V_192 -> V_193 -> V_194 , V_15 , V_29 ) ;
return 0 ;
}
static void F_77 (
struct V_191 * V_192 ,
unsigned short * V_203 )
{
if ( V_203 )
* V_203 = V_192 -> V_195 ;
}
static unsigned int F_78 ( struct V_191 * V_192 )
{
struct V_22 * V_23 = V_192 -> V_2 -> V_23 ;
return V_23 -> V_196 ;
}
static bool F_79 ( const struct V_204 * V_205 )
{
return V_205 -> V_206 == V_207 ;
}
static bool F_80 ( const struct V_204 * V_205 )
{
return V_208 == V_205 -> V_209 ;
}
static bool F_81 ( const struct V_204 * V_205 )
{
return V_205 -> V_29 == 0 ;
}
static T_4 F_82 ( const struct V_204 * V_205 )
{
return sizeof( * V_205 ) + V_205 -> V_29 * sizeof( T_2 ) ;
}
static const struct V_204 * F_83 (
const struct V_204 * V_205 )
{
return (struct V_204 * ) ( ( unsigned char * ) ( V_205 ) + F_82 ( V_205 ) ) ;
}
static int F_84 ( struct V_1 * V_2 ,
const struct V_204 * V_210 )
{
int V_30 ;
const T_2 * V_15 ;
unsigned int V_29 ;
if ( V_210 == NULL || V_210 -> V_209 != V_208 ) {
F_12 ( V_2 , L_66 ) ;
return - V_31 ;
}
V_29 = V_210 -> V_29 ;
V_15 = ( T_2 * ) ( V_210 -> V_15 ) ;
while ( V_29 >= 2 ) {
V_30 = F_14 ( V_2 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_67 ) ;
return V_30 ;
}
V_29 -= 2 ;
V_15 += 2 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_204 * V_210 ,
unsigned int V_211 ,
struct V_191 * V_191 ,
unsigned int V_119 ,
unsigned int V_140 ,
bool V_141 )
{
int V_30 = 0 ;
bool V_212 = false ;
const unsigned int * V_15 ;
unsigned int V_21 ;
unsigned int V_213 ;
unsigned int V_214 ;
unsigned char * V_215 ;
unsigned short V_188 ;
unsigned int V_184 ;
unsigned int V_185 ;
unsigned int V_173 ;
unsigned int V_216 ;
unsigned int V_217 ;
const T_2 * V_218 ;
T_2 V_219 ;
unsigned int V_220 ;
const struct V_204 * V_221 = NULL ;
unsigned long V_16 ;
bool V_222 ;
if ( V_210 == NULL )
return - V_31 ;
if ( F_80 ( V_210 ) ) {
V_221 = V_210 ;
V_210 = F_83 ( V_210 ) ;
}
if ( V_221 && ( ! V_210 || F_81 ( V_210 ) ) ) {
F_12 ( V_2 , L_68 ) ;
return F_84 ( V_2 , V_221 ) ;
}
if ( V_210 == NULL || V_191 == NULL || V_140 == 0 ) {
F_12 ( V_2 , L_69 ) ;
return - V_31 ;
}
V_15 = V_210 -> V_15 ;
V_21 = V_210 -> V_209 ,
V_213 = V_210 -> V_29 ;
if ( ! V_213 )
return V_221 ? F_84 ( V_2 , V_221 ) : 0 ;
if ( V_211 )
V_21 = ( V_21 & ( 0xFFFF0000 << 2 ) ) + ( V_211 << 2 ) ;
if ( ! F_44 ( V_21 , V_213 ) &&
! F_46 ( V_21 , V_213 ) &&
! F_48 ( V_21 , V_213 ) ) {
F_12 ( V_2 , L_70 ) ;
return - V_31 ;
}
V_214 = ( unsigned int ) F_74 ( V_191 ) /
sizeof( T_2 ) ;
V_215 = F_75 ( V_191 ) ;
if ( V_215 == NULL ) {
F_12 ( V_2 , L_71 ) ;
return - V_31 ;
}
F_77 ( V_191 , & V_188 ) ;
V_184 = ( ( F_64 ( V_188 ) >> 0 ) & 3 ) + 1 ;
V_185 = ( ( F_64 ( V_188 ) >> 3 ) & 3 ) + 1 ;
V_173 = F_65 ( V_188 ) + 1 ;
V_216 = ( ( V_184 == 0 ) ? 0 :
( V_173 * V_185 / V_184 ) ) ;
if ( V_216 == 0 ) {
F_12 ( V_2 , L_72 ) ;
return - V_31 ;
}
V_214 = F_36 ( V_214 ,
( unsigned int ) ( F_44 ( V_21 , 1 ) ?
65536 : 32768 ) ) ;
V_214 -= V_214 % V_216 ;
F_12 ( V_2 ,
L_73
L_74 ,
V_21 , V_216 , V_173 ,
V_185 , V_184 , V_214 ) ;
if ( V_214 < V_216 ) {
F_12 ( V_2 , L_75 ) ;
return - V_31 ;
}
V_217 = V_213 % V_216 ;
V_218 = V_15 ;
V_219 = V_21 ;
V_15 += V_217 ;
V_21 += V_217 * sizeof( T_2 ) ;
V_213 -= V_217 ;
while ( V_213 != 0 ) {
V_220 = F_36 ( V_214 , V_213 ) ;
F_12 ( V_2 , L_76 ,
V_213 , V_220 , V_217 ) ;
F_76 ( V_191 , V_15 , V_220 * sizeof( T_2 ) ) ;
if ( ! V_212 ) {
V_30 = F_59 ( V_2 , V_119 , V_141 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_51 ( V_2 , V_21 ,
V_119 , V_140 , V_141 ) ;
if ( V_30 < 0 )
return V_30 ;
V_212 = true ;
}
V_30 = F_54 ( V_2 , V_21 ,
V_220 , V_119 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_58 ( V_2 , V_119 , V_141 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! F_50 ( V_2 , V_119 ) ) {
F_12 ( V_2 , L_77 ) ;
return - V_20 ;
}
V_30 = F_72 ( V_191 , V_201 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_217 != 0 ) {
V_30 = F_17 ( V_2 ,
V_219 ,
V_218 ,
V_217 ) ;
if ( V_30 < 0 )
return V_30 ;
V_217 = 0 ;
}
if ( V_221 ) {
V_30 = F_84 ( V_2 , V_221 ) ;
if ( V_30 < 0 )
return V_30 ;
V_221 = NULL ;
}
V_16 = V_17 + F_6 ( 2000 ) ;
do {
V_222 = F_50 ( V_2 , V_119 ) ;
if ( ! V_222 )
break;
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
if ( V_222 )
break;
F_12 ( V_2 , L_78 ) ;
F_72 ( V_191 , V_200 ) ;
V_30 = F_69 ( V_191 ) ;
if ( V_30 < 0 )
return V_30 ;
V_15 += V_220 ;
V_21 += V_220 * sizeof( T_2 ) ;
V_213 -= V_220 ;
}
if ( V_217 != 0 ) {
V_30 = F_17 ( V_2 , V_219 ,
V_218 , V_217 ) ;
}
return V_30 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_204 * V_223 ,
unsigned int V_211 ,
unsigned int V_186 ,
unsigned short V_187 ,
bool V_141 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_30 ;
unsigned short V_188 = 0 ;
unsigned int V_7 ;
unsigned char V_224 = 0 ;
struct V_191 * V_191 ;
unsigned int V_119 ;
unsigned int V_140 ;
if ( V_223 == NULL )
return - V_31 ;
V_191 = F_87 ( sizeof( * V_191 ) , V_225 ) ;
if ( ! V_191 )
return - V_226 ;
V_191 -> V_193 = F_87 ( sizeof( * V_191 -> V_193 ) , V_225 ) ;
if ( ! V_191 -> V_193 ) {
F_88 ( V_191 ) ;
return - V_226 ;
}
V_191 -> V_2 = V_2 ;
F_67 ( V_2 , V_186 , V_187 , & V_188 ) ;
V_191 -> V_195 = V_188 ;
V_191 -> V_69 = ( V_141 ? V_227 :
V_228 ) * 2 ;
V_119 = V_141 ? V_229 : 0 ;
V_30 = F_3 ( V_2 , V_18 ,
V_188 , & V_7 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_79 ) ;
goto exit;
}
V_30 = F_71 ( V_2 ,
V_191 -> V_195 ,
V_191 -> V_69 ,
V_191 -> V_193 ) ;
if ( V_30 < 0 )
goto exit;
V_23 -> V_196 = V_30 ;
if ( V_141 ) {
V_30 = F_39 ( V_2 , & V_119 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_80 ) ;
V_119 = V_229 ;
goto exit;
}
}
V_140 = 0 ;
V_30 = F_63 ( V_2 , V_188 ,
& V_140 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_81 ) ;
goto exit;
}
V_224 = F_78 ( V_191 ) ;
V_30 = F_4 ( V_2 ,
V_18 , V_224 , 0 , & V_7 ) ;
if ( V_30 < 0 ) {
F_12 ( V_2 , L_82 ) ;
goto exit;
}
while ( ( V_223 != NULL ) && ! F_81 ( V_223 ) ) {
if ( ! F_79 ( V_223 ) ) {
F_12 ( V_2 , L_83 ) ;
V_30 = - V_31 ;
goto exit;
}
V_30 = F_85 ( V_2 , V_223 , V_211 ,
V_191 , V_119 ,
V_140 , V_141 ) ;
if ( V_30 < 0 )
break;
if ( F_80 ( V_223 ) )
V_223 = F_83 ( V_223 ) ;
if ( ( V_223 != NULL ) && ! F_81 ( V_223 ) )
V_223 = F_83 ( V_223 ) ;
}
if ( V_140 != 0 )
V_30 = F_66 ( V_2 ) ;
if ( V_30 < 0 )
goto exit;
V_30 = F_4 ( V_2 ,
V_18 , 0 , 0 , & V_7 ) ;
exit:
if ( V_141 && ( V_119 != V_229 ) )
F_40 ( V_2 , V_119 ) ;
if ( V_191 -> V_193 -> V_194 )
F_70 ( V_2 , V_191 -> V_193 ) ;
F_88 ( V_191 -> V_193 ) ;
F_88 ( V_191 ) ;
return V_30 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_12 ( V_2 , L_84 ) ;
F_14 ( V_2 , F_90 ( 0x18 ) , 0x08080080 ) ;
F_14 ( V_2 , F_90 ( 0x19 ) , 0x3f800000 ) ;
F_14 ( V_2 , F_90 ( 0x29 ) , 0x00000002 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
const struct V_204 * V_210 ,
bool V_141 ,
unsigned int V_211 ,
bool V_230 ,
int V_231 )
{
int V_30 = 0 ;
unsigned int V_186 ;
unsigned short V_187 ;
F_12 ( V_2 , L_85 ) ;
if ( V_231 == 0 ) {
if ( ! V_141 )
V_231 = V_232 ;
else
V_231 = V_233 ;
}
V_186 = 48000 ;
V_187 = ( unsigned short ) V_231 ;
while ( V_187 > 16 ) {
V_186 *= 2 ;
V_187 /= 2 ;
}
do {
F_12 ( V_2 , L_86 ) ;
if ( ! V_141 )
V_30 = F_42 ( V_2 ) ;
if ( V_30 < 0 )
break;
F_12 ( V_2 , L_87 ) ;
V_30 = F_86 ( V_2 , V_210 , V_211 , V_186 , V_187 ,
V_141 ) ;
if ( V_30 < 0 )
break;
F_12 ( V_2 , L_88 ) ;
if ( V_230 && ! V_141 ) {
F_89 ( V_2 ) ;
V_30 = F_41 ( V_2 ) ;
}
F_12 ( V_2 , L_89 ) ;
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
F_94 ( V_2 , L_90 ) ;
return true ;
}
F_7 ( 20 ) ;
} while ( F_8 ( V_17 , V_16 ) );
F_95 ( V_2 , L_91 ) ;
return false ;
}
static int F_96 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_203 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_97 ( V_2 , V_23 -> V_239 [ 0 ] , V_236 , 0 , V_203 ) ;
return 0 ;
}
static int F_98 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_240 == V_241 )
return 0 ;
if ( V_23 -> V_242 [ V_243 - V_244 ] )
F_7 ( 50 ) ;
F_99 ( V_2 , V_23 -> V_239 [ 0 ] ) ;
return 0 ;
}
static unsigned int F_100 ( struct V_234 * V_245 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_246 = V_247 ;
struct V_248 * V_249 = V_238 -> V_249 ;
if ( V_23 -> V_240 != V_250 )
return 0 ;
if ( V_23 -> V_242 [ V_243 - V_244 ] ) {
if ( ( V_23 -> V_242 [ V_251 - V_244 ] ) ||
( V_23 -> V_242 [ V_252 - V_244 ] ) )
V_246 += V_253 ;
}
if ( V_23 -> V_254 == V_255 )
V_246 += V_256 ;
return ( V_246 * V_249 -> V_51 ) / 1000 ;
}
static int F_101 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_102 ( V_2 , & V_23 -> V_257 ) ;
}
static int F_103 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_203 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_104 ( V_2 , & V_23 -> V_257 ,
V_236 , V_203 , V_238 ) ;
}
static int F_105 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_106 ( V_2 , & V_23 -> V_257 ) ;
}
static int F_107 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
return F_108 ( V_2 , & V_23 -> V_257 ) ;
}
static int F_109 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_236 ,
unsigned int V_203 ,
struct V_237 * V_238 )
{
F_97 ( V_2 , V_235 -> V_3 ,
V_236 , 0 , V_203 ) ;
return 0 ;
}
static int F_110 ( struct V_234 * V_235 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_240 == V_241 )
return 0 ;
F_99 ( V_2 , V_235 -> V_3 ) ;
return 0 ;
}
static unsigned int F_111 ( struct V_234 * V_245 ,
struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_246 = V_258 ;
struct V_248 * V_249 = V_238 -> V_249 ;
if ( V_23 -> V_240 != V_250 )
return 0 ;
if ( V_23 -> V_242 [ V_259 - V_244 ] )
V_246 += V_260 ;
return ( V_246 * V_249 -> V_51 ) / 1000 ;
}
static int F_112 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_261 , int V_262 )
{
int V_263 = 0 ;
for ( V_263 = 0 ; V_263 < V_264 ; V_263 ++ )
if ( V_3 == V_265 [ V_263 ] . V_3 )
break;
F_113 ( V_2 ) ;
F_37 ( V_2 , V_265 [ V_263 ] . V_266 ,
V_265 [ V_263 ] . V_76 ,
& ( V_261 [ V_262 ] ) , sizeof( unsigned int ) ) ;
F_114 ( V_2 ) ;
return 1 ;
}
static int F_115 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
int V_262 = V_3 - V_273 ;
* V_271 = V_23 -> V_274 [ V_262 ] ;
return 0 ;
}
static int F_118 ( struct V_267 * V_268 ,
struct V_275 * V_276 )
{
int V_277 = F_119 ( V_268 ) ;
V_276 -> type = V_278 ;
V_276 -> V_29 = V_277 == 3 ? 2 : 1 ;
V_276 -> V_272 . integer . F_36 = 20 ;
V_276 -> V_272 . integer . V_279 = 180 ;
V_276 -> V_272 . integer . V_280 = 1 ;
return 0 ;
}
static int F_120 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
int V_262 ;
V_262 = V_3 - V_273 ;
if ( V_23 -> V_274 [ V_262 ] == * V_271 )
return 0 ;
V_23 -> V_274 [ V_262 ] = * V_271 ;
V_262 = * V_271 - 20 ;
F_112 ( V_2 , V_3 , V_281 , V_262 ) ;
return 1 ;
}
static int F_121 ( struct V_267 * V_268 ,
struct V_275 * V_276 )
{
int V_277 = F_119 ( V_268 ) ;
V_276 -> type = V_278 ;
V_276 -> V_29 = V_277 == 3 ? 2 : 1 ;
V_276 -> V_272 . integer . F_36 = 0 ;
V_276 -> V_272 . integer . V_279 = 100 ;
V_276 -> V_272 . integer . V_280 = 1 ;
return 0 ;
}
static int F_122 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
int V_262 ;
V_262 = V_3 - V_273 ;
if ( V_23 -> V_274 [ V_262 ] == * V_271 )
return 0 ;
V_23 -> V_274 [ V_262 ] = * V_271 ;
V_262 = * V_271 ;
F_112 ( V_2 , V_3 , V_282 , V_262 ) ;
return 0 ;
}
static int F_123 ( struct V_267 * V_268 ,
struct V_275 * V_276 )
{
int V_277 = F_119 ( V_268 ) ;
V_276 -> type = V_278 ;
V_276 -> V_29 = V_277 == 3 ? 2 : 1 ;
V_276 -> V_272 . integer . F_36 = 0 ;
V_276 -> V_272 . integer . V_279 = 48 ;
V_276 -> V_272 . integer . V_280 = 1 ;
return 0 ;
}
static int F_124 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
int V_262 ;
V_262 = V_3 - V_273 ;
if ( V_23 -> V_274 [ V_262 ] == * V_271 )
return 0 ;
V_23 -> V_274 [ V_262 ] = * V_271 ;
V_262 = * V_271 ;
F_112 ( V_2 , V_3 , V_283 , V_262 ) ;
return 1 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_1 V_284 , T_1 V_3 ,
const char * V_285 , int V_103 )
{
char V_286 [ V_287 ] ;
int type = V_103 ? V_288 : V_289 ;
struct V_290 V_291 =
F_126 ( V_286 , V_3 , 1 , 0 , type ) ;
V_291 . V_292 = V_293 |
V_294 ;
V_291 . V_295 . V_296 = 0 ;
V_291 . V_295 . V_205 = 0 ;
switch ( V_284 ) {
case V_297 :
V_291 . V_245 = F_118 ;
V_291 . V_298 = F_115 ;
V_291 . V_299 = F_120 ;
V_291 . V_295 . V_205 = V_300 ;
break;
case V_301 :
V_291 . V_245 = F_121 ;
V_291 . V_298 = F_115 ;
V_291 . V_299 = F_122 ;
break;
case V_302 :
V_291 . V_245 = F_123 ;
V_291 . V_298 = F_115 ;
V_291 . V_299 = F_124 ;
V_291 . V_295 . V_205 = V_303 ;
break;
default:
return 0 ;
}
V_291 . V_304 =
F_127 ( V_3 , 1 , 0 , type ) ;
sprintf ( V_286 , L_92 , V_285 , V_305 [ V_103 ] ) ;
return F_128 ( V_2 , V_3 , F_129 ( & V_291 , V_2 ) ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
int V_263 ;
int V_35 ;
for ( V_263 = 0 ; V_263 < V_264 ; V_263 ++ ) {
V_35 = F_125 ( V_2 ,
V_265 [ V_263 ] . V_306 ,
V_265 [ V_263 ] . V_3 ,
V_265 [ V_263 ] . V_285 ,
V_265 [ V_263 ] . V_307 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_263 ;
V_23 -> V_274 [ V_308 - V_273 ] = 10 ;
V_23 -> V_274 [ V_309 - V_273 ] = 74 ;
for ( V_263 = 2 ; V_263 < V_264 ; V_263 ++ )
V_23 -> V_274 [ V_263 ] = 24 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_310 ;
int V_311 ;
int V_312 ;
unsigned int V_313 ;
int V_35 ;
F_12 ( V_2 , L_93 ) ;
F_133 ( V_2 ) ;
V_312 = V_23 -> V_314 [ V_315 - V_316 ] ;
if ( V_312 )
V_311 = F_134 ( V_2 , V_23 -> V_317 ) ;
else
V_311 =
V_23 -> V_314 [ V_318 - V_316 ] ;
if ( V_311 )
V_23 -> V_254 = V_319 ;
else
V_23 -> V_254 = V_255 ;
if ( V_23 -> V_254 == V_255 ) {
F_12 ( V_2 , L_94 ) ;
V_313 = V_320 ;
V_35 = F_38 ( V_2 , 0x80 , 0x04 , V_313 ) ;
if ( V_35 < 0 )
goto exit;
V_313 = V_320 ;
V_35 = F_38 ( V_2 , 0x8f , 0x00 , V_313 ) ;
if ( V_35 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_321 [ 1 ] , 0 ,
V_322 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_323 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_322 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_323 , 0x02 ) ;
V_310 = F_2 ( V_2 , V_23 -> V_321 [ 1 ] , 0 ,
V_324 , 0 ) ;
F_135 ( V_2 , V_23 -> V_321 [ 1 ] ,
V_310 & ~ V_325 ) ;
V_310 = F_2 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_324 , 0 ) ;
F_135 ( V_2 , V_23 -> V_321 [ 0 ] ,
V_310 | V_326 ) ;
} else {
F_12 ( V_2 , L_95 ) ;
V_313 = V_327 ;
V_35 = F_38 ( V_2 , 0x80 , 0x04 , V_313 ) ;
if ( V_35 < 0 )
goto exit;
V_313 = V_327 ;
V_35 = F_38 ( V_2 , 0x8f , 0x00 , V_313 ) ;
if ( V_35 < 0 )
goto exit;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_322 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_323 , 0x00 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 1 ] , 0 ,
V_322 , 0x02 ) ;
F_20 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_323 , 0x02 ) ;
V_310 = F_2 ( V_2 , V_23 -> V_321 [ 0 ] , 0 ,
V_324 , 0 ) ;
F_135 ( V_2 , V_23 -> V_321 [ 0 ] ,
V_310 & ~ V_325 ) ;
V_310 = F_2 ( V_2 , V_23 -> V_321 [ 1 ] , 0 ,
V_324 , 0 ) ;
F_135 ( V_2 , V_23 -> V_321 [ 1 ] ,
V_310 | V_325 ) ;
}
exit:
F_136 ( V_2 ) ;
return V_35 < 0 ? V_35 : 0 ;
}
static void F_137 ( struct V_328 * V_329 )
{
struct V_22 * V_23 = F_138 (
F_139 ( V_329 ) , struct V_22 , V_330 ) ;
struct V_331 * V_332 ;
F_132 ( V_23 -> V_2 ) ;
V_332 = F_140 ( V_23 -> V_2 , V_23 -> V_317 ) ;
if ( V_332 ) {
V_332 -> V_333 = 0 ;
F_141 ( V_23 -> V_2 ) ;
}
}
static int F_142 ( struct V_1 * V_2 , int V_40 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_313 ;
if ( V_23 -> V_240 != V_250 )
return 0 ;
if ( ! V_23 -> V_242 [ V_259 - V_244 ] ||
( V_40 == 0 ) ) {
F_21 ( V_2 , V_334 , 0 ) ;
F_22 ( V_2 , V_335 , V_336 ) ;
F_22 ( V_2 , V_337 , V_336 ) ;
if ( V_23 -> V_338 == V_339 )
V_313 = V_340 ;
else
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x00 , V_313 ) ;
V_313 = V_327 ;
F_38 ( V_2 , 0x80 , 0x05 , V_313 ) ;
} else {
F_22 ( V_2 , V_335 , V_341 ) ;
F_22 ( V_2 , V_337 , V_341 ) ;
if ( V_23 -> V_338 == V_339 )
V_313 = V_340 ;
else
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x00 , V_313 ) ;
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x05 , V_313 ) ;
F_7 ( 20 ) ;
F_21 ( V_2 , V_334 , V_40 ) ;
}
return 1 ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_311 ;
int V_312 ;
F_12 ( V_2 , L_96 ) ;
F_133 ( V_2 ) ;
V_312 = V_23 -> V_314 [ V_342 - V_316 ] ;
if ( V_312 )
V_311 = F_134 ( V_2 , V_23 -> V_343 ) ;
else
V_311 =
V_23 -> V_314 [ V_344 - V_316 ] ;
if ( V_311 )
V_23 -> V_338 = V_345 ;
else
V_23 -> V_338 = V_339 ;
if ( V_23 -> V_338 == V_339 ) {
F_22 ( V_2 , V_346 , V_347 ) ;
F_144 ( V_2 , 1 ) ;
F_145 ( V_2 , 0 ) ;
F_146 ( V_2 , V_297 ,
V_23 -> V_242
[ V_297 - V_244 ] ) ;
} else {
F_22 ( V_2 , V_346 , V_336 ) ;
F_144 ( V_2 , 0 ) ;
F_145 ( V_2 , V_23 -> V_348 ) ;
F_146 ( V_2 , V_297 , 0 ) ;
}
F_136 ( V_2 ) ;
return 0 ;
}
static bool F_147 ( struct V_1 * V_2 ,
T_1 V_349 ,
T_1 * V_350 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
switch ( V_349 ) {
case V_351 :
V_3 = V_23 -> V_352 ;
break;
case V_353 :
V_3 = V_23 -> V_354 ;
break;
default:
return false ;
}
if ( V_350 )
* V_350 = V_3 ;
return true ;
}
static int F_148 ( struct V_1 * V_2 , int V_355 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_313 ;
if ( V_355 ) {
V_313 = V_23 -> V_242 [ V_259 - V_244 ] ?
V_320 : V_327 ;
} else {
V_313 = V_327 ;
}
F_38 ( V_2 , V_356 . V_266 ,
V_356 . V_357 [ 0 ] , V_313 ) ;
return 1 ;
}
static int F_146 ( struct V_1 * V_2 , T_1 V_3 , long V_40 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_358 ;
int V_359 = V_360 + V_361 ;
int V_35 = 0 ;
int V_262 = V_3 - V_244 ;
if ( ( V_262 < 0 ) || ( V_262 >= V_359 ) )
return 0 ;
if ( ( V_3 >= V_362 ) && ( V_3 < V_363 ) ) {
if ( ! V_23 -> V_242 [ V_243 - V_244 ] )
V_40 = 0 ;
}
if ( ( V_3 >= V_364 ) && ( V_3 < V_365 ) ) {
if ( ! V_23 -> V_242 [ V_259 - V_244 ] )
V_40 = 0 ;
if ( ( V_3 == V_297 ) && ( V_23 -> V_338 != V_339 ) )
V_40 = 0 ;
}
F_12 ( V_2 , L_97 ,
V_3 , V_40 ) ;
V_358 = ( V_40 == 0 ) ? V_327 : V_320 ;
V_35 = F_38 ( V_2 , V_366 [ V_262 ] . V_266 ,
V_366 [ V_262 ] . V_357 [ 0 ] , V_358 ) ;
if ( V_35 < 0 )
return 0 ;
return 1 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_263 , V_367 = 0 ;
F_12 ( V_2 , L_98 ,
V_23 -> V_242 [ V_243 - V_244 ] ) ;
V_263 = V_362 - V_244 ;
V_3 = V_362 ;
for (; V_3 < V_363 ; V_3 ++ , V_263 ++ )
V_367 |= F_146 ( V_2 , V_3 , V_23 -> V_242 [ V_263 ] ) ;
return V_367 ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_368 = F_2 ( V_2 , V_23 -> V_369 [ 0 ] , 0 ,
V_370 , 0 ) ;
if ( V_368 != 0 )
F_20 ( V_2 , V_23 -> V_369 [ 0 ] , 0 ,
V_13 ,
0 ) ;
return V_368 ;
}
static void F_151 ( struct V_1 * V_2 , unsigned int V_368 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_368 != 0 )
F_20 ( V_2 , V_23 -> V_369 [ 0 ] , 0 ,
V_13 ,
V_368 ) ;
}
static int F_152 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 ;
int V_263 , V_367 = 0 ;
unsigned int V_368 ;
F_12 ( V_2 , L_99 ,
V_23 -> V_242 [ V_259 - V_244 ] ) ;
V_263 = V_364 - V_244 ;
V_3 = V_364 ;
for (; V_3 < V_365 ; V_3 ++ , V_263 ++ )
V_367 |= F_146 ( V_2 , V_3 , V_23 -> V_242 [ V_263 ] ) ;
V_367 |= F_148 ( V_2 , ( V_23 -> V_371 ? 1 : 0 ) ) ;
V_368 = F_150 ( V_2 ) ;
V_367 |= F_142 ( V_2 , 1 ) ;
F_151 ( V_2 , V_368 ) ;
return V_367 ;
}
static int F_145 ( struct V_1 * V_2 , long V_40 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_367 = 0 ;
if ( V_40 )
V_367 = F_153 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_288 , 0 , V_373 , 3 ) ;
else
V_367 = F_153 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_288 , 0 , V_373 , 0 ) ;
return V_367 ;
}
static int F_154 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
T_1 V_3 = F_117 ( V_268 ) ;
T_1 V_350 = 0 ;
bool V_374 ;
int V_367 = 0 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_312 ;
if ( V_3 == V_318 ) {
V_312 =
V_23 -> V_314 [ V_315 - V_316 ] ;
if ( ! V_312 )
F_132 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_344 ) {
V_312 =
V_23 -> V_314 [ V_342 - V_316 ] ;
if ( ! V_312 )
F_143 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_315 ) {
F_132 ( V_2 ) ;
return 1 ;
}
if ( V_3 == V_342 ) {
F_143 ( V_2 ) ;
return 1 ;
}
V_374 = F_147 ( V_2 , V_3 , & V_350 ) ;
if ( V_374 ) {
int V_103 = F_155 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
unsigned long V_376 ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_350 , V_375 ,
0 , V_103 ) ;
V_367 = F_156 ( V_268 , V_270 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
}
return V_367 ;
}
static int F_157 ( struct V_267 * V_268 ,
struct V_275 * V_276 )
{
unsigned int V_378 = sizeof( V_379 )
/ sizeof( struct V_380 ) ;
V_276 -> type = V_381 ;
V_276 -> V_29 = 1 ;
V_276 -> V_272 . V_382 . V_378 = V_378 ;
if ( V_276 -> V_272 . V_382 . V_383 >= V_378 )
V_276 -> V_272 . V_382 . V_383 = V_378 - 1 ;
strcpy ( V_276 -> V_272 . V_382 . V_285 ,
V_379 [ V_276 -> V_272 . V_382 . V_383 ] . V_285 ) ;
return 0 ;
}
static int F_158 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
V_270 -> V_272 . V_382 . V_383 [ 0 ] = V_23 -> V_371 ;
return 0 ;
}
static int F_159 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_263 , V_35 = 0 ;
int V_384 = V_270 -> V_272 . V_382 . V_383 [ 0 ] ;
unsigned int V_378 = sizeof( V_379 )
/ sizeof( struct V_380 ) ;
if ( V_384 >= V_378 )
return 0 ;
F_12 ( V_2 , L_100 ,
V_384 , V_379 [ V_384 ] . V_285 ) ;
for ( V_263 = 0 ; V_263 < V_385 ; V_263 ++ ) {
V_35 = F_38 ( V_2 , V_356 . V_266 ,
V_356 . V_357 [ V_263 ] ,
V_379 [ V_384 ] . V_386 [ V_263 ] ) ;
if ( V_35 < 0 )
break;
}
if ( V_35 >= 0 ) {
V_23 -> V_371 = V_384 ;
F_148 ( V_2 , ( V_384 ? 1 : 0 ) ) ;
}
return 1 ;
}
static int F_160 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
if ( ( V_3 >= V_316 ) && ( V_3 < V_387 ) ) {
if ( V_375 & 1 ) {
* V_271 = V_23 -> V_314 [ V_3 - V_316 ] ;
V_271 ++ ;
}
if ( V_375 & 2 ) {
* V_271 = V_23 -> V_388 [ V_3 - V_316 ] ;
V_271 ++ ;
}
return 0 ;
}
if ( ( V_3 >= V_244 ) && ( V_3 < V_389 ) ) {
* V_271 = V_23 -> V_242 [ V_3 - V_244 ] ;
return 0 ;
}
if ( V_3 == V_23 -> V_372 [ 0 ] ) {
* V_271 = V_23 -> V_348 ;
return 0 ;
}
return 0 ;
}
static int F_161 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
int V_390 = 1 ;
F_12 ( V_2 , L_101 ,
V_3 , * V_271 ) ;
F_113 ( V_2 ) ;
if ( ( V_3 >= V_316 ) && ( V_3 < V_387 ) ) {
if ( V_375 & 1 ) {
V_23 -> V_314 [ V_3 - V_316 ] = * V_271 ;
V_271 ++ ;
}
if ( V_375 & 2 ) {
V_23 -> V_388 [ V_3 - V_316 ] = * V_271 ;
V_271 ++ ;
}
V_390 = F_154 ( V_268 , V_270 ) ;
goto exit;
}
if ( V_3 == V_243 ) {
V_23 -> V_242 [ V_3 - V_244 ] = * V_271 ;
V_390 = F_149 ( V_2 ) ;
goto exit;
}
if ( V_3 == V_259 ) {
V_23 -> V_242 [ V_3 - V_244 ] = * V_271 ;
V_390 = F_152 ( V_2 ) ;
goto exit;
}
if ( ( ( V_3 >= V_362 ) && ( V_3 < V_363 ) ) ||
( ( V_3 >= V_364 ) && ( V_3 < V_365 ) ) ) {
V_23 -> V_242 [ V_3 - V_244 ] = * V_271 ;
V_390 = F_146 ( V_2 , V_3 , * V_271 ) ;
goto exit;
}
if ( V_3 == V_23 -> V_372 [ 0 ] ) {
V_23 -> V_348 = * V_271 ;
if ( V_23 -> V_338 != V_339 )
V_390 = F_145 ( V_2 , * V_271 ) ;
goto exit;
}
exit:
F_114 ( V_2 ) ;
return V_390 ;
}
static int F_162 ( struct V_267 * V_268 ,
struct V_275 * V_276 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
int V_103 = F_155 ( V_268 ) ;
unsigned long V_376 ;
int V_35 ;
switch ( V_3 ) {
case V_351 :
V_3 = V_23 -> V_352 ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_3 , V_375 , 0 , V_103 ) ;
V_35 = F_163 ( V_268 , V_276 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
break;
case V_353 :
V_3 = V_23 -> V_354 ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_3 , V_375 , 0 , V_103 ) ;
V_35 = F_163 ( V_268 , V_276 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
break;
default:
V_35 = F_163 ( V_268 , V_276 ) ;
}
return V_35 ;
}
static int F_164 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
if ( V_375 & 1 ) {
* V_271 = V_23 -> V_391 [ V_3 - V_316 ] ;
V_271 ++ ;
}
if ( V_375 & 2 ) {
* V_271 = V_23 -> V_392 [ V_3 - V_316 ] ;
V_271 ++ ;
}
return 0 ;
}
static int F_165 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
long * V_271 = V_270 -> V_272 . integer . V_272 ;
T_1 V_350 = 0 ;
bool V_374 ;
int V_390 = 1 ;
if ( V_375 & 1 ) {
V_23 -> V_391 [ V_3 - V_316 ] = * V_271 ;
V_271 ++ ;
}
if ( V_375 & 2 ) {
V_23 -> V_392 [ V_3 - V_316 ] = * V_271 ;
V_271 ++ ;
}
V_374 = F_147 ( V_2 , V_3 , & V_350 ) ;
if ( V_374 ) {
int V_103 = F_155 ( V_268 ) ;
unsigned long V_376 ;
F_113 ( V_2 ) ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_350 , V_375 ,
0 , V_103 ) ;
V_390 = F_166 ( V_268 , V_270 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
F_114 ( V_2 ) ;
}
return V_390 ;
}
static int F_167 ( struct V_267 * V_268 , int V_393 ,
unsigned int V_66 , unsigned int T_5 * V_295 )
{
struct V_1 * V_2 = F_116 ( V_268 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_3 = F_117 ( V_268 ) ;
int V_375 = F_119 ( V_268 ) ;
int V_103 = F_155 ( V_268 ) ;
unsigned long V_376 ;
int V_35 ;
switch ( V_3 ) {
case V_351 :
V_3 = V_23 -> V_352 ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_3 , V_375 , 0 , V_103 ) ;
V_35 = F_168 ( V_268 , V_393 , V_66 , V_295 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
break;
case V_353 :
V_3 = V_23 -> V_354 ;
F_15 ( & V_2 -> V_377 ) ;
V_376 = V_268 -> V_304 ;
V_268 -> V_304 = F_127 ( V_3 , V_375 , 0 , V_103 ) ;
V_35 = F_168 ( V_268 , V_393 , V_66 , V_295 ) ;
V_268 -> V_304 = V_376 ;
F_16 ( & V_2 -> V_377 ) ;
break;
default:
V_35 = F_168 ( V_268 , V_393 , V_66 , V_295 ) ;
}
return V_35 ;
}
static int F_169 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_394 , int V_103 )
{
char V_286 [ V_287 ] ;
int type = V_103 ? V_288 : V_289 ;
struct V_290 V_291 =
F_170 ( V_286 , V_3 , 1 , type ) ;
sprintf ( V_286 , L_102 , V_394 , V_305 [ V_103 ] ) ;
return F_128 ( V_2 , V_3 , F_129 ( & V_291 , V_2 ) ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_290 V_291 =
F_172 ( V_356 . V_285 ,
V_395 , 1 , 0 , V_288 ) ;
V_291 . V_245 = F_157 ;
V_291 . V_298 = F_158 ;
V_291 . V_299 = F_159 ;
return F_128 ( V_2 , V_395 , F_129 ( & V_291 , V_2 ) ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_263 , V_359 ;
int V_35 = 0 ;
for ( V_263 = 0 ; V_263 < V_23 -> V_396 ; V_263 ++ ) {
V_35 = F_174 ( V_2 , V_23 -> V_397 [ V_263 ] ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_359 = V_360 + V_361 ;
for ( V_263 = 0 ; V_263 < V_359 ; V_263 ++ ) {
V_35 = F_169 ( V_2 , V_366 [ V_263 ] . V_3 ,
V_366 [ V_263 ] . V_285 ,
V_366 [ V_263 ] . V_307 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_35 = F_169 ( V_2 , V_243 , L_103 , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_169 ( V_2 , V_259 , L_104 , 1 ) ;
if ( V_35 < 0 )
return V_35 ;
F_171 ( V_2 ) ;
#ifdef F_175
F_130 ( V_2 ) ;
#endif
V_35 = F_176 ( V_2 , & V_23 -> V_398 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_23 -> V_399 ) {
V_35 = F_177 ( V_2 , V_23 -> V_399 ,
V_23 -> V_399 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_178 ( V_2 , & V_23 -> V_257 ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( V_23 -> V_400 ) {
V_35 = F_179 ( V_2 , V_23 -> V_400 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_401 * V_245 ;
V_245 = F_181 ( V_2 , L_105 ) ;
if ( ! V_245 )
return - V_226 ;
V_245 -> V_10 [ V_402 ] = V_403 ;
V_245 -> V_10 [ V_402 ] . V_3 = V_23 -> V_239 [ 0 ] ;
V_245 -> V_10 [ V_402 ] . V_404 =
V_23 -> V_257 . V_405 ;
V_245 -> V_10 [ V_406 ] = V_407 ;
V_245 -> V_10 [ V_406 ] . V_408 = 1 ;
V_245 -> V_10 [ V_406 ] . V_3 = V_23 -> V_369 [ 0 ] ;
V_245 = F_181 ( V_2 , L_106 ) ;
if ( ! V_245 )
return - V_226 ;
V_245 -> V_10 [ V_406 ] = V_407 ;
V_245 -> V_10 [ V_406 ] . V_408 = 1 ;
V_245 -> V_10 [ V_406 ] . V_3 = V_23 -> V_369 [ 1 ] ;
V_245 = F_181 ( V_2 , L_107 ) ;
if ( ! V_245 )
return - V_226 ;
V_245 -> V_10 [ V_406 ] = V_407 ;
V_245 -> V_10 [ V_406 ] . V_408 = 1 ;
V_245 -> V_10 [ V_406 ] . V_3 = V_23 -> V_369 [ 2 ] ;
if ( ! V_23 -> V_399 && ! V_23 -> V_400 )
return 0 ;
V_245 = F_181 ( V_2 , L_108 ) ;
if ( ! V_245 )
return - V_226 ;
V_245 -> V_409 = V_410 ;
if ( V_23 -> V_399 ) {
V_245 -> V_10 [ V_402 ] =
V_411 ;
V_245 -> V_10 [ V_402 ] . V_3 = V_23 -> V_399 ;
}
if ( V_23 -> V_400 ) {
V_245 -> V_10 [ V_406 ] =
V_412 ;
V_245 -> V_10 [ V_406 ] . V_3 = V_23 -> V_400 ;
}
return 0 ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_413 , T_1 V_414 )
{
if ( V_413 ) {
F_135 ( V_2 , V_413 , V_325 ) ;
if ( F_183 ( V_2 , V_413 ) & V_415 )
F_20 ( V_2 , V_413 , 0 ,
V_416 ,
V_417 ) ;
}
if ( V_414 && ( F_183 ( V_2 , V_414 ) & V_415 ) )
F_20 ( V_2 , V_414 , 0 ,
V_416 , V_418 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_413 , T_1 V_419 )
{
if ( V_413 ) {
F_135 ( V_2 , V_413 , V_420 ) ;
if ( F_183 ( V_2 , V_413 ) & V_421 )
F_20 ( V_2 , V_413 , 0 ,
V_416 ,
F_185 ( 0 ) ) ;
}
if ( V_419 && ( F_183 ( V_2 , V_419 ) & V_421 ) ) {
F_20 ( V_2 , V_419 , 0 , V_416 ,
F_185 ( 0 ) ) ;
F_186 ( V_2 , V_419 , V_288 , 0 ,
V_373 , 0x5a ) ;
F_186 ( V_2 , V_419 , V_288 , 0 ,
V_422 , 0 ) ;
}
}
static void F_187 ( struct V_1 * V_2 , T_1 V_3 , int V_103 )
{
unsigned int V_423 ;
V_423 = F_188 ( V_2 , V_3 , V_103 == V_289 ?
V_424 : V_425 ) ;
F_189 ( V_2 , V_3 , V_103 , V_423 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_355 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_313 ;
T_3 V_40 ;
unsigned int V_368 ;
F_12 ( V_2 , L_109 , V_355 ) ;
V_368 = F_150 ( V_2 ) ;
F_142 ( V_2 , 0 ) ;
if ( V_355 ) {
V_313 = V_340 ;
F_38 ( V_2 , 0x80 , 0x00 , V_313 ) ;
V_40 = V_23 -> V_426 ;
V_40 |= 0x80 ;
F_20 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_427 , V_40 ) ;
if ( ! ( V_23 -> V_426 & 0x20 ) )
F_19 ( V_2 , V_428 , 1 ) ;
} else {
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x00 , V_313 ) ;
V_40 = V_23 -> V_426 ;
V_40 &= 0x5f ;
F_20 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_427 , V_40 ) ;
if ( ! ( V_23 -> V_426 & 0x20 ) )
F_19 ( V_2 , V_428 , 0 ) ;
}
F_142 ( V_2 , 1 ) ;
F_151 ( V_2 , V_368 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
T_3 V_40 ;
V_40 = 0x01 ;
F_20 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_429 , V_40 ) ;
V_40 = 0x83 ;
F_20 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_430 , V_40 ) ;
V_40 = 0x23 ;
V_23 -> V_426 = V_40 ;
F_20 ( V_2 , V_23 -> V_372 [ 0 ] , 0 ,
V_427 , V_40 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_15 ( & V_23 -> V_36 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_54 , 0x20 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_431 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_432 , 0x00 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_54 , 0x2D ) ;
F_20 ( V_2 , V_18 , 0 ,
V_431 , 0x19 ) ;
F_20 ( V_2 , V_18 , 0 ,
V_432 , 0x00 ) ;
F_16 ( & V_23 -> V_36 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_263 ;
F_12 ( V_2 , L_110 ) ;
F_193 ( V_2 ) ;
for ( V_263 = 0 ; V_263 < V_23 -> V_257 . V_433 ; V_263 ++ )
F_187 ( V_2 , V_23 -> V_239 [ V_263 ] , V_289 ) ;
for ( V_263 = 0 ; V_263 < V_23 -> V_434 ; V_263 ++ )
F_187 ( V_2 , V_23 -> V_321 [ V_263 ] , V_289 ) ;
for ( V_263 = 0 ; V_263 < V_23 -> V_435 ; V_263 ++ ) {
F_187 ( V_2 , V_23 -> V_369 [ V_263 ] , V_288 ) ;
F_187 ( V_2 , V_23 -> V_372 [ V_263 ] , V_288 ) ;
}
}
static void F_194 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned int V_313 ;
int V_359 ;
int V_262 , V_263 ;
if ( V_23 -> V_240 != V_250 )
return;
V_359 = V_360 + V_361 + 1 ;
for ( V_262 = 0 ; V_262 < V_359 ; V_262 ++ ) {
for ( V_263 = 0 ; V_263 <= V_366 [ V_262 ] . V_436 ; V_263 ++ ) {
F_38 ( V_2 , V_366 [ V_262 ] . V_266 ,
V_366 [ V_262 ] . V_357 [ V_263 ] ,
V_366 [ V_262 ] . V_437 [ V_263 ] ) ;
}
}
V_313 = V_327 ;
F_38 ( V_2 , 0x96 , 0x3C , V_313 ) ;
F_38 ( V_2 , 0x8f , 0x01 , V_313 ) ;
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x00 , V_313 ) ;
F_38 ( V_2 , 0x80 , 0x01 , V_313 ) ;
V_313 = V_320 ;
F_38 ( V_2 , 0x80 , 0x05 , V_313 ) ;
V_313 = V_340 ;
F_38 ( V_2 , 0x31 , 0x00 , V_313 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_438 , 0 ) ;
F_19 ( V_2 , V_439 , 0 ) ;
F_19 ( V_2 , V_440 , 0 ) ;
F_19 ( V_2 , V_441 , 0 ) ;
F_19 ( V_2 , V_442 , 0 ) ;
F_19 ( V_2 , V_443 , 1 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_444 , 6 ) ;
F_21 ( V_2 , V_445 , 6 ) ;
}
static void F_197 ( struct V_1 * V_2 , bool V_446 )
{
F_19 ( V_2 , V_447 , V_446 ) ;
F_19 ( V_2 , V_448 , V_446 ) ;
F_19 ( V_2 , V_449 , V_446 ) ;
F_19 ( V_2 , V_450 , V_446 ) ;
F_19 ( V_2 , V_451 , V_446 ) ;
F_19 ( V_2 , V_452 , V_446 ) ;
F_22 ( V_2 , V_335 , V_336 ) ;
F_22 ( V_2 , V_337 , V_336 ) ;
F_22 ( V_2 , V_453 , V_454 ) ;
}
static bool F_198 ( struct V_1 * V_2 )
{
bool V_455 = false ;
const struct V_204 * V_456 ;
const struct V_457 * V_458 ;
if ( F_199 ( & V_458 , V_459 , V_2 -> V_460 -> V_461 ) != 0 )
return false ;
V_456 = (struct V_204 * ) ( V_458 -> V_15 ) ;
if ( F_91 ( V_2 , V_456 , 0 , 0 , true , 0 ) ) {
F_95 ( V_2 , L_111 ) ;
goto V_462;
}
V_455 = F_93 ( V_2 ) ;
V_462:
F_200 ( V_458 ) ;
return V_455 ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
#ifndef F_202
return;
#endif
if ( V_23 -> V_240 == V_463 )
return;
F_23 ( V_2 ) ;
V_23 -> V_240 = V_241 ;
if ( ! F_198 ( V_2 ) )
V_23 -> V_240 = V_463 ;
else
V_23 -> V_240 = V_250 ;
if ( V_23 -> V_240 == V_250 )
F_197 ( V_2 , true ) ;
}
static void F_203 ( struct V_1 * V_2 ,
struct V_464 * V_465 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_12 ( V_2 , L_112 ) ;
if ( V_23 -> V_100 ) {
if ( F_33 ( V_2 ) >= 0 )
V_23 -> V_100 = 0 ;
}
F_32 ( V_2 ) ;
}
static void F_204 ( struct V_1 * V_2 , struct V_464 * V_466 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_331 * V_467 ;
F_205 ( & V_23 -> V_330 ) ;
F_206 ( & V_23 -> V_330 , F_6 ( 500 ) ) ;
V_467 = F_140 ( V_2 , V_466 -> V_3 ) ;
if ( V_467 )
V_467 -> V_333 = 1 ;
}
static void F_207 ( struct V_1 * V_2 , struct V_464 * V_466 )
{
F_143 ( V_2 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_209 ( V_2 , V_23 -> V_317 , F_204 ) ;
F_209 ( V_2 , V_23 -> V_343 ,
F_207 ) ;
F_209 ( V_2 , V_468 ,
F_203 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_359 ;
int V_263 ;
unsigned int V_358 ;
F_211 ( & V_23 -> V_36 ) ;
V_23 -> V_254 = V_255 ;
V_23 -> V_338 = V_339 ;
V_23 -> V_348 = 0 ;
for ( V_263 = 0 ; V_263 < V_469 ; V_263 ++ ) {
V_23 -> V_391 [ V_263 ] = 0x5a ;
V_23 -> V_392 [ V_263 ] = 0x5a ;
V_23 -> V_314 [ V_263 ] = 0 ;
V_23 -> V_388 [ V_263 ] = 0 ;
}
V_359 = V_360 + V_361 ;
for ( V_263 = 0 ; V_263 < V_359 ; V_263 ++ ) {
V_358 = ( unsigned int ) V_366 [ V_263 ] . V_357 [ 0 ] ;
V_23 -> V_242 [ V_263 ] = V_358 ? 1 : 0 ;
}
V_23 -> V_371 = 0 ;
V_23 -> V_242 [ V_243 - V_244 ] = 1 ;
V_23 -> V_242 [ V_259 - V_244 ] = 0 ;
#ifdef F_175
F_131 ( V_2 ) ;
#endif
}
static void F_212 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
F_42 ( V_2 ) ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_470 * V_471 = & V_23 -> V_398 ;
int V_263 ;
if ( V_23 -> V_240 != V_463 )
V_23 -> V_240 = V_472 ;
V_23 -> V_24 = V_136 ;
F_133 ( V_2 ) ;
F_208 ( V_2 ) ;
F_196 ( V_2 ) ;
F_195 ( V_2 ) ;
F_214 ( V_2 , V_23 -> V_473 ) ;
F_201 ( V_2 ) ;
F_192 ( V_2 ) ;
F_194 ( V_2 ) ;
F_191 ( V_2 ) ;
F_190 ( V_2 ) ;
for ( V_263 = 0 ; V_263 < V_23 -> V_434 ; V_263 ++ )
F_182 ( V_2 , V_23 -> V_321 [ V_263 ] , V_23 -> V_239 [ 0 ] ) ;
F_182 ( V_2 , V_471 -> V_474 [ 0 ] , V_23 -> V_399 ) ;
for ( V_263 = 0 ; V_263 < V_23 -> V_435 ; V_263 ++ )
F_184 ( V_2 , V_23 -> V_372 [ V_263 ] , V_23 -> V_369 [ V_263 ] ) ;
F_184 ( V_2 , V_471 -> V_475 , V_23 -> V_400 ) ;
F_214 ( V_2 , V_23 -> V_476 ) ;
F_214 ( V_2 , V_23 -> V_477 ) ;
F_132 ( V_2 ) ;
F_143 ( V_2 ) ;
F_141 ( V_2 ) ;
F_136 ( V_2 ) ;
return 0 ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_205 ( & V_23 -> V_330 ) ;
F_113 ( V_2 ) ;
F_214 ( V_2 , V_23 -> V_478 ) ;
F_212 ( V_2 ) ;
F_114 ( V_2 ) ;
F_88 ( V_23 -> V_477 ) ;
F_88 ( V_2 -> V_23 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_470 * V_471 = & V_23 -> V_398 ;
V_23 -> V_239 [ 0 ] = 0x2 ;
V_23 -> V_239 [ 1 ] = 0x3 ;
V_23 -> V_239 [ 2 ] = 0x4 ;
V_23 -> V_257 . V_479 = V_23 -> V_239 ;
V_23 -> V_257 . V_433 = 3 ;
V_23 -> V_257 . V_405 = 2 ;
if ( V_23 -> V_480 == V_481 ) {
F_12 ( V_2 , L_113 ) ;
F_217 ( V_2 , V_482 ) ;
V_23 -> V_434 = 2 ;
V_23 -> V_321 [ 0 ] = 0x0b ;
V_23 -> V_321 [ 1 ] = 0x0f ;
V_23 -> V_352 = 0x2 ;
V_23 -> V_317 = 0x0f ;
V_23 -> V_369 [ 0 ] = 0x7 ;
V_23 -> V_369 [ 1 ] = 0x8 ;
V_23 -> V_369 [ 2 ] = 0xa ;
V_23 -> V_435 = 3 ;
V_23 -> V_372 [ 0 ] = 0x12 ;
V_23 -> V_372 [ 1 ] = 0x11 ;
V_23 -> V_372 [ 2 ] = 0x13 ;
V_23 -> V_354 = 0x7 ;
V_23 -> V_343 = 0x11 ;
} else {
V_23 -> V_434 = 2 ;
V_23 -> V_321 [ 0 ] = 0x0b ;
V_23 -> V_321 [ 1 ] = 0x10 ;
V_23 -> V_352 = 0x2 ;
V_23 -> V_317 = V_23 -> V_321 [ 1 ] ;
V_23 -> V_369 [ 0 ] = 0x7 ;
V_23 -> V_369 [ 1 ] = 0x8 ;
V_23 -> V_369 [ 2 ] = 0xa ;
V_23 -> V_435 = 3 ;
V_23 -> V_372 [ 0 ] = 0x12 ;
V_23 -> V_372 [ 1 ] = 0x11 ;
V_23 -> V_372 [ 2 ] = 0x13 ;
V_23 -> V_354 = 0x7 ;
V_23 -> V_343 = V_23 -> V_372 [ 0 ] ;
V_23 -> V_399 = 0x05 ;
V_23 -> V_257 . V_483 = V_23 -> V_399 ;
V_471 -> V_474 [ 0 ] = 0x0c ;
V_471 -> V_484 = 1 ;
V_471 -> V_485 [ 0 ] = V_410 ;
V_23 -> V_400 = 0x09 ;
V_471 -> V_475 = 0x0e ;
V_471 -> V_486 = V_410 ;
}
}
static int F_218 ( struct V_1 * V_2 )
{
#define F_219 4
struct V_22 * V_23 = V_2 -> V_23 ;
V_23 -> V_476 = V_487 ;
V_23 -> V_477 = F_87 ( sizeof( struct V_488 ) * F_219 , V_225 ) ;
if ( ! V_23 -> V_477 )
return - V_226 ;
V_23 -> V_477 [ 0 ] . V_3 = V_23 -> V_317 ;
V_23 -> V_477 [ 0 ] . V_489 = V_490 ;
V_23 -> V_477 [ 0 ] . V_4 = V_491 | V_23 -> V_317 ;
V_23 -> V_477 [ 1 ] . V_3 = V_23 -> V_343 ;
V_23 -> V_477 [ 1 ] . V_489 = V_490 ;
V_23 -> V_477 [ 1 ] . V_4 = V_491 | V_23 -> V_343 ;
V_23 -> V_477 [ 2 ] . V_3 = 0x0b ;
V_23 -> V_477 [ 2 ] . V_489 = 0x78D ;
V_23 -> V_477 [ 2 ] . V_4 = 0x00 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_35 ;
const struct V_492 * V_480 ;
F_12 ( V_2 , L_114 ) ;
V_23 = F_87 ( sizeof( * V_23 ) , V_225 ) ;
if ( ! V_23 )
return - V_226 ;
V_2 -> V_23 = V_23 ;
V_23 -> V_2 = V_2 ;
V_2 -> V_493 = V_494 ;
V_2 -> V_495 = 1 ;
V_2 -> V_496 = 1 ;
V_480 = F_221 ( V_2 -> V_497 -> V_498 , V_499 ) ;
if ( V_480 )
V_23 -> V_480 = V_480 -> V_272 ;
else
V_23 -> V_480 = V_500 ;
V_23 -> V_240 = V_472 ;
V_23 -> V_396 = 1 ;
V_23 -> V_397 [ 0 ] = V_501 ;
V_23 -> V_473 = V_502 ;
V_23 -> V_478 = V_503 ;
F_222 ( & V_23 -> V_330 , F_137 ) ;
F_210 ( V_2 ) ;
F_216 ( V_2 ) ;
V_35 = F_218 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_223 ( V_2 , & V_23 -> V_398 , NULL ) ;
if ( V_35 < 0 )
goto error;
return 0 ;
error:
F_215 ( V_2 ) ;
return V_35 ;
}
