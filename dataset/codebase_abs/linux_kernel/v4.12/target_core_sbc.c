static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned long long V_8 = V_4 -> V_9 -> V_10 ( V_4 ) ;
unsigned char * V_11 ;
unsigned char V_12 [ 8 ] ;
T_2 V_13 ;
if ( ! ( V_6 [ 8 ] & 1 ) && ! ! ( V_6 [ 2 ] | V_6 [ 3 ] | V_6 [ 4 ] | V_6 [ 5 ] ) )
return V_14 ;
if ( V_8 >= 0x00000000ffffffff )
V_13 = 0xffffffff ;
else
V_13 = ( T_2 ) V_8 ;
V_12 [ 0 ] = ( V_13 >> 24 ) & 0xff ;
V_12 [ 1 ] = ( V_13 >> 16 ) & 0xff ;
V_12 [ 2 ] = ( V_13 >> 8 ) & 0xff ;
V_12 [ 3 ] = V_13 & 0xff ;
V_12 [ 4 ] = ( V_4 -> V_15 . V_16 >> 24 ) & 0xff ;
V_12 [ 5 ] = ( V_4 -> V_15 . V_16 >> 16 ) & 0xff ;
V_12 [ 6 ] = ( V_4 -> V_15 . V_16 >> 8 ) & 0xff ;
V_12 [ 7 ] = V_4 -> V_15 . V_16 & 0xff ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_3 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_18 , 8 ) ;
return 0 ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 = V_2 -> V_21 ;
int V_22 = V_4 -> V_15 . V_22 ;
unsigned char * V_11 ;
unsigned char V_12 [ 32 ] ;
unsigned long long V_13 = V_4 -> V_9 -> V_10 ( V_4 ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_12 [ 0 ] = ( V_13 >> 56 ) & 0xff ;
V_12 [ 1 ] = ( V_13 >> 48 ) & 0xff ;
V_12 [ 2 ] = ( V_13 >> 40 ) & 0xff ;
V_12 [ 3 ] = ( V_13 >> 32 ) & 0xff ;
V_12 [ 4 ] = ( V_13 >> 24 ) & 0xff ;
V_12 [ 5 ] = ( V_13 >> 16 ) & 0xff ;
V_12 [ 6 ] = ( V_13 >> 8 ) & 0xff ;
V_12 [ 7 ] = V_13 & 0xff ;
V_12 [ 8 ] = ( V_4 -> V_15 . V_16 >> 24 ) & 0xff ;
V_12 [ 9 ] = ( V_4 -> V_15 . V_16 >> 16 ) & 0xff ;
V_12 [ 10 ] = ( V_4 -> V_15 . V_16 >> 8 ) & 0xff ;
V_12 [ 11 ] = V_4 -> V_15 . V_16 & 0xff ;
if ( V_20 -> V_23 & ( V_24 | V_25 ) ) {
if ( ! V_22 )
V_22 = V_20 -> V_26 ;
if ( V_22 )
V_12 [ 12 ] = ( V_22 - 1 ) << 1 | 0x1 ;
}
if ( V_4 -> V_9 -> V_27 )
V_12 [ 13 ] = V_4 -> V_9 -> V_27 ( V_4 ) & 0x0f ;
if ( V_4 -> V_9 -> V_28 ) {
T_3 V_29 = V_4 -> V_9 -> V_28 ( V_4 ) ;
V_12 [ 14 ] = ( V_29 >> 8 ) & 0x3f ;
V_12 [ 15 ] = V_29 & 0xff ;
}
if ( V_4 -> V_15 . V_30 || V_4 -> V_15 . V_31 ) {
V_12 [ 14 ] |= 0x80 ;
if ( V_4 -> V_15 . V_32 )
V_12 [ 14 ] |= 0x40 ;
}
V_11 = F_2 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_3 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_18 , 32 ) ;
return 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 )
{
unsigned char * V_6 = V_2 -> V_7 ;
if ( ! ( V_6 [ 1 ] & 1 ) || V_6 [ 2 ] || V_6 [ 3 ] )
return V_14 ;
if ( V_6 [ 4 ] >> 4 & 0xf )
return V_14 ;
if ( ! ( V_6 [ 4 ] & 1 ) || ( V_6 [ 4 ] & 2 ) || ( V_6 [ 4 ] & 4 ) )
return V_14 ;
F_8 ( V_2 , V_33 ) ;
return 0 ;
}
T_4 F_9 ( struct V_1 * V_2 )
{
T_2 V_34 ;
if ( V_2 -> V_7 [ 0 ] == V_35 )
V_34 = F_10 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_36 )
V_34 = F_11 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_34 = F_11 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_34 )
return V_34 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_37 + 1 ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
T_4 V_41 = F_9 ( V_2 ) ;
T_1 V_42 ;
if ( V_41 ) {
V_42 = V_39 -> V_43 ( V_2 , V_2 -> V_37 , V_41 ) ;
if ( V_42 )
return V_42 ;
}
F_8 ( V_2 , V_18 ) ;
return 0 ;
}
static T_1
F_13 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_14 ( struct V_1 * V_2 , T_2 V_44 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_44 ;
}
static inline T_2 F_15 ( unsigned char * V_6 )
{
return V_6 [ 4 ] ? : 256 ;
}
static inline T_2 F_16 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 7 ] << 8 ) + V_6 [ 8 ] ;
}
static inline T_2 F_17 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 6 ] << 24 ) + ( V_6 [ 7 ] << 16 ) + ( V_6 [ 8 ] << 8 ) + V_6 [ 9 ] ;
}
static inline T_2 F_18 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 10 ] << 24 ) + ( V_6 [ 11 ] << 16 ) +
( V_6 [ 12 ] << 8 ) + V_6 [ 13 ] ;
}
static inline T_2 F_19 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 28 ] << 24 ) + ( V_6 [ 29 ] << 16 ) +
( V_6 [ 30 ] << 8 ) + V_6 [ 31 ] ;
}
static inline T_2 F_20 ( unsigned char * V_6 )
{
return ( ( V_6 [ 1 ] & 0x1f ) << 16 ) | ( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
}
static inline T_2 F_21 ( unsigned char * V_6 )
{
return ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_45 , V_46 ;
V_45 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_46 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_46 ) | ( unsigned long long ) V_45 << 32 ;
}
static inline unsigned long long F_23 ( unsigned char * V_6 )
{
unsigned int V_45 , V_46 ;
V_45 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_46 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_46 ) | ( unsigned long long ) V_45 << 32 ;
}
static T_1
F_24 ( struct V_1 * V_2 , unsigned char * V_47 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_48 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
unsigned int V_44 = F_9 ( V_2 ) ;
T_1 V_42 ;
if ( ( V_47 [ 0 ] & 0x04 ) || ( V_47 [ 0 ] & 0x02 ) ) {
F_25 ( L_1
L_2
L_3 ) ;
return V_49 ;
}
if ( V_44 > V_2 -> V_5 -> V_15 . V_50 ) {
F_26 ( L_4 ,
V_44 , V_2 -> V_5 -> V_15 . V_50 ) ;
return V_14 ;
}
if ( ( ( V_2 -> V_37 + V_44 ) < V_2 -> V_37 ) ||
( ( V_2 -> V_37 + V_44 ) > V_48 ) ) {
F_25 ( L_5 ,
( unsigned long long ) V_48 , V_2 -> V_37 , V_44 ) ;
return V_51 ;
}
if ( V_47 [ 0 ] & 0x10 ) {
F_26 ( L_6 ) ;
return V_14 ;
}
if ( V_47 [ 0 ] & 0x08 ) {
if ( ! V_39 -> V_43 )
return V_49 ;
if ( ! V_4 -> V_15 . V_31 ) {
F_25 ( L_7
L_8 ) ;
return V_49 ;
}
V_2 -> V_52 = F_12 ;
return 0 ;
}
if ( ! V_39 -> V_53 )
return V_49 ;
V_42 = F_27 ( V_4 , V_2 , & V_2 -> V_7 [ 0 ] , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_52 = V_39 -> V_53 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 , bool V_54 ,
int * V_55 )
{
unsigned char * V_12 , * V_56 ;
struct V_57 * V_58 ;
unsigned int V_59 ;
T_1 V_42 = V_60 ;
int V_61 , V_62 ;
V_12 = F_29 ( V_2 -> V_17 , V_63 ) ;
if ( ! V_12 ) {
F_25 ( L_9 ) ;
return V_64 ;
}
F_30 ( V_2 -> V_65 ,
V_2 -> V_66 ,
V_12 ,
V_2 -> V_17 ) ;
V_59 = 0 ;
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_56 = F_32 ( F_33 ( V_58 ) ) ;
if ( ! V_56 ) {
V_42 = V_64 ;
goto V_67;
}
for ( V_61 = 0 ; V_61 < V_58 -> V_68 ; V_61 ++ )
* ( V_56 + V_58 -> V_59 + V_61 ) ^= * ( V_12 + V_59 + V_61 ) ;
V_59 += V_58 -> V_68 ;
F_34 ( V_56 ) ;
}
V_67:
F_35 ( V_12 ) ;
return V_42 ;
}
static T_1
F_36 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return V_39 -> V_69 ( V_2 , V_2 -> V_65 , V_2 -> V_66 ,
V_2 -> V_70 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 , bool V_54 ,
int * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 = V_60 ;
F_38 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_72 & V_73 ) {
V_2 -> V_74 |= V_75 ;
* V_55 = 1 ;
if ( V_2 -> V_76 == V_77 )
V_42 = V_78 ;
}
F_39 ( & V_2 -> V_71 ) ;
F_40 ( & V_4 -> V_79 ) ;
return V_42 ;
}
static T_1 F_41 ( struct V_1 * V_2 , bool V_54 ,
int * V_55 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_57 * V_80 = NULL , * V_58 ;
unsigned char * V_12 = NULL , * V_56 ;
struct V_81 V_82 ;
unsigned int V_59 = 0 , V_83 ;
unsigned int V_84 = V_2 -> V_85 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_86 = ( V_84 * V_16 ) ;
T_1 V_42 = V_60 ;
int V_87 , V_61 ;
if ( ! V_54 && ( ! V_2 -> V_65 || ! V_2 -> V_88 ) )
return V_60 ;
if ( ! V_2 -> V_17 )
goto V_67;
if ( V_2 -> V_76 ) {
F_42 ( L_10
L_11 , V_2 -> V_76 ) ;
* V_55 = 1 ;
if ( V_2 -> V_76 == V_77 )
V_42 = V_78 ;
goto V_67;
}
V_12 = F_43 ( V_2 -> V_17 , V_63 ) ;
if ( ! V_12 ) {
F_25 ( L_12 ) ;
V_42 = V_64 ;
goto V_67;
}
V_80 = F_44 ( V_2 -> V_66 , sizeof( * V_80 ) ,
V_63 ) ;
if ( ! V_80 ) {
F_25 ( L_13 ) ;
V_42 = V_64 ;
goto V_67;
}
F_45 ( V_80 , V_2 -> V_66 ) ;
V_87 = F_30 ( V_2 -> V_65 , V_2 -> V_66 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_87 ) {
F_25 ( L_14 ) ;
V_42 = V_64 ;
goto V_67;
}
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_56 = ( unsigned char * ) F_32 ( F_33 ( V_58 ) ) ;
if ( ! V_56 ) {
V_42 = V_64 ;
goto V_67;
}
V_83 = F_46 ( V_58 -> V_68 , V_86 ) ;
if ( memcmp ( V_56 , V_12 + V_59 , V_83 ) ) {
F_26 ( L_15 ,
V_56 , V_12 + V_59 ) ;
F_34 ( V_56 ) ;
goto V_89;
}
F_34 ( V_56 ) ;
V_59 += V_83 ;
V_86 -= V_83 ;
if ( ! V_86 )
break;
}
V_61 = 0 ;
V_83 = V_2 -> V_85 * V_16 ;
F_47 ( & V_82 , V_2 -> V_65 , V_2 -> V_66 , V_90 ) ;
while ( V_83 ) {
F_48 ( & V_82 ) ;
if ( V_16 < V_91 ) {
F_49 ( & V_80 [ V_61 ] , V_82 . V_92 , V_16 ,
V_82 . V_93 . V_58 -> V_59 + V_16 ) ;
} else {
F_48 ( & V_82 ) ;
F_49 ( & V_80 [ V_61 ] , V_82 . V_92 , V_16 ,
V_82 . V_93 . V_58 -> V_59 ) ;
}
V_83 -= V_16 ;
V_61 ++ ;
}
F_50 ( & V_82 ) ;
V_2 -> V_94 = V_2 -> V_65 ;
V_2 -> V_65 = V_80 ;
V_2 -> V_95 = V_2 -> V_66 ;
V_2 -> V_66 = 1 ;
V_2 -> V_96 = V_97 ;
V_2 -> V_98 = F_37 ;
V_2 -> V_52 = F_36 ;
F_38 ( & V_2 -> V_71 ) ;
V_2 -> V_99 = V_100 ;
V_2 -> V_72 |= V_101 | V_73 ;
F_39 ( & V_2 -> V_71 ) ;
F_51 ( V_2 , false ) ;
F_35 ( V_12 ) ;
return V_42 ;
V_89:
F_26 ( L_16 ,
V_4 -> V_9 -> V_102 ) ;
V_42 = V_103 ;
V_67:
F_40 ( & V_4 -> V_79 ) ;
F_35 ( V_80 ) ;
F_35 ( V_12 ) ;
return V_42 ;
}
static T_1
F_52 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
int V_87 ;
V_87 = F_53 ( & V_4 -> V_79 ) ;
if ( V_87 != 0 ) {
V_2 -> V_98 = NULL ;
return V_78 ;
}
V_2 -> V_17 = V_2 -> V_85 * V_4 -> V_15 . V_16 ;
V_42 = V_39 -> V_69 ( V_2 , V_2 -> V_88 , V_2 -> V_104 ,
V_105 ) ;
if ( V_42 ) {
V_2 -> V_98 = NULL ;
F_40 ( & V_4 -> V_79 ) ;
return V_42 ;
}
return V_60 ;
}
static int
F_54 ( T_5 V_106 , bool V_107 , enum V_108 V_109 ,
bool V_110 , struct V_1 * V_2 )
{
if ( V_110 ) {
V_2 -> V_111 = V_107 ? V_112 :
V_106 ? V_25 :
V_113 ;
switch ( V_106 ) {
case 0x0 :
case 0x3 :
V_2 -> V_114 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_114 = V_115 ;
if ( V_109 == V_116 )
V_2 -> V_114 |= V_117 ;
break;
case 0x2 :
if ( V_109 == V_116 )
V_2 -> V_114 = V_117 ;
break;
case 0x4 :
V_2 -> V_114 = V_115 ;
break;
default:
F_25 ( L_17 , V_106 ) ;
return - V_118 ;
}
} else {
V_2 -> V_111 = V_107 ? V_119 :
V_106 ? V_24 :
V_120 ;
switch ( V_106 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_114 = V_115 ;
if ( V_109 == V_116 )
V_2 -> V_114 |= V_117 ;
break;
case 0x2 :
if ( V_109 == V_116 )
V_2 -> V_114 = V_117 ;
break;
case 0x3 :
V_2 -> V_114 = 0 ;
break;
case 0x4 :
V_2 -> V_114 = V_115 ;
break;
default:
F_25 ( L_17 , V_106 ) ;
return - V_118 ;
}
}
return 0 ;
}
static T_1
F_27 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_44 , bool V_110 )
{
T_5 V_106 = V_6 [ 1 ] >> 5 ;
int V_121 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_107 = false ;
if ( ! V_2 -> V_122 || ! V_2 -> V_123 ) {
if ( F_55 ( V_106 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_25 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_124 )
return V_60 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_125 :
V_2 -> V_126 = 0xffffffff ;
break;
case V_127 :
if ( V_106 )
return V_14 ;
V_2 -> V_126 = V_2 -> V_37 ;
break;
case V_116 :
V_2 -> V_126 = V_2 -> V_37 ;
break;
case V_128 :
V_107 = V_110 ?
! ! ( V_121 & ( V_25 | V_112 ) ) :
! ! ( V_121 & ( V_24 | V_119 ) ) ;
if ( V_107 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_106 )
return V_60 ;
default:
F_25 ( L_20
L_21 , V_6 [ 0 ] , V_106 ) ;
return V_14 ;
}
if ( F_54 ( V_106 , V_107 , V_22 , V_110 , V_2 ) )
return V_14 ;
V_2 -> V_109 = V_22 ;
V_2 -> V_129 = V_4 -> V_129 * V_44 ;
if ( V_106 )
V_2 -> V_17 = V_44 * V_4 -> V_15 . V_16 ;
F_42 ( L_22
L_23 ,
V_130 , V_2 -> V_109 , V_2 -> V_17 , V_2 -> V_129 ,
V_2 -> V_111 , V_2 -> V_114 ) ;
return V_60 ;
}
static int
F_56 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! F_57 ( V_4 ) ) {
F_25 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_118 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! F_57 ( V_4 ) ) {
F_25 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_118 ;
}
V_2 -> V_74 |= V_131 ;
}
return 0 ;
}
T_1
F_58 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_132 ;
T_2 V_44 = 0 ;
T_1 V_42 ;
V_2 -> V_40 = V_39 ;
switch ( V_6 [ 0 ] ) {
case V_133 :
V_44 = F_15 ( V_6 ) ;
V_2 -> V_37 = F_20 ( V_6 ) ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_135 :
V_44 = F_16 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_136 :
V_44 = F_17 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_137 :
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_22 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_138 :
V_44 = F_15 ( V_6 ) ;
V_2 -> V_37 = F_20 ( V_6 ) ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_139 :
case V_140 :
V_44 = F_16 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_141 :
V_44 = F_17 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_142 :
case V_143 :
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_22 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_27 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
break;
case V_144 :
if ( V_2 -> V_70 != V_145 ||
! ( V_2 -> V_74 & V_146 ) )
return V_14 ;
V_44 = F_16 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_37 = F_21 ( V_6 ) ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
V_2 -> V_98 = & F_28 ;
break;
case V_147 :
{
T_3 V_148 = F_10 ( & V_6 [ 8 ] ) ;
switch ( V_148 ) {
case V_149 :
V_44 = F_19 ( V_6 ) ;
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_37 = F_23 ( V_6 ) ;
V_2 -> V_74 |= V_134 ;
V_2 -> V_52 = F_36 ;
V_2 -> V_98 = & F_28 ;
break;
case V_150 :
V_44 = F_19 ( V_6 ) ;
if ( ! V_44 ) {
F_25 ( L_28
L_29 ) ;
return V_14 ;
}
V_132 = F_14 ( V_2 , 1 ) ;
V_2 -> V_37 = F_59 ( & V_6 [ 12 ] ) ;
V_42 = F_24 ( V_2 , & V_6 [ 10 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
default:
F_25 ( L_30
L_31 , V_148 ) ;
return V_49 ;
}
break;
}
case V_151 :
V_44 = V_6 [ 13 ] ;
if ( V_44 > 1 ) {
F_25 ( L_32
L_33 , V_44 ) ;
return V_14 ;
}
if ( F_56 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_132 = 2 * F_14 ( V_2 , V_44 ) ;
V_2 -> V_37 = F_59 ( & V_6 [ 2 ] ) ;
V_2 -> V_85 = V_44 ;
V_2 -> V_74 |= V_134 | V_152 ;
V_2 -> V_52 = F_52 ;
V_2 -> V_98 = F_41 ;
break;
case V_153 :
V_132 = V_154 ;
V_2 -> V_52 = F_1 ;
break;
case V_155 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_156 :
V_2 -> V_52 = F_6 ;
break;
case V_157 :
V_2 -> V_52 = V_158 ;
break;
default:
F_25 ( L_34 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_132 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_159 :
case V_160 :
if ( V_6 [ 0 ] == V_159 ) {
V_44 = F_16 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
} else {
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_22 ( V_6 ) ;
}
if ( V_39 -> V_161 ) {
V_2 -> V_52 = V_39 -> V_161 ;
goto V_162;
}
V_132 = 0 ;
V_2 -> V_52 = F_13 ;
break;
case V_163 :
if ( ! V_39 -> V_43 )
return V_49 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_25 ( L_35
L_36 ) ;
return V_49 ;
}
V_132 = F_10 ( & V_6 [ 7 ] ) ;
V_2 -> V_52 = V_164 ;
break;
case V_36 :
V_44 = F_18 ( V_6 ) ;
if ( ! V_44 ) {
F_25 ( L_37 ) ;
return V_14 ;
}
V_132 = F_14 ( V_2 , 1 ) ;
V_2 -> V_37 = F_59 ( & V_6 [ 2 ] ) ;
V_42 = F_24 ( V_2 , & V_6 [ 1 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
case V_35 :
V_44 = F_16 ( V_6 ) ;
if ( ! V_44 ) {
F_25 ( L_37 ) ;
return V_14 ;
}
V_132 = F_14 ( V_2 , 1 ) ;
V_2 -> V_37 = F_11 ( & V_6 [ 2 ] ) ;
V_42 = F_24 ( V_2 , & V_6 [ 1 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
case V_165 :
case V_166 :
V_132 = 0 ;
if ( V_6 [ 0 ] == V_165 ) {
V_44 = F_16 ( V_6 ) ;
V_2 -> V_37 = F_21 ( V_6 ) ;
} else {
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_22 ( V_6 ) ;
}
V_2 -> V_52 = F_13 ;
goto V_162;
case V_167 :
case V_168 :
case V_169 :
V_132 = 0 ;
V_2 -> V_52 = F_13 ;
break;
case V_170 :
V_132 = 0 ;
V_2 -> V_52 = F_7 ;
break;
default:
V_42 = F_60 ( V_2 , & V_132 ) ;
if ( V_42 )
return V_42 ;
}
if ( ! V_2 -> V_52 )
return V_49 ;
if ( V_2 -> V_74 & V_134 ) {
unsigned long long V_48 ;
V_162:
V_48 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_37 + V_44 ) < V_2 -> V_37 ) ||
( ( V_2 -> V_37 + V_44 ) > V_48 ) ) {
F_25 ( L_38
L_39 ,
V_48 , V_2 -> V_37 , V_44 ) ;
return V_51 ;
}
if ( ! ( V_2 -> V_74 & V_152 ) )
V_132 = F_14 ( V_2 , V_44 ) ;
}
return F_61 ( V_2 , V_132 ) ;
}
T_2 F_62 ( struct V_3 * V_4 )
{
return V_171 ;
}
static T_1
V_164 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_172 = NULL ;
T_4 V_173 ;
int V_132 ;
T_2 V_174 ;
T_1 V_42 = 0 ;
int V_175 , V_176 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_8 ( V_2 , V_33 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_26 ( L_40 ,
V_2 -> V_17 ) ;
return V_177 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_78 ;
V_175 = F_10 ( & V_12 [ 0 ] ) ;
V_176 = F_10 ( & V_12 [ 2 ] ) ;
V_132 = V_2 -> V_17 - 8 ;
if ( V_176 > V_132 )
F_26 ( L_41 ,
V_2 -> V_17 , V_176 ) ;
else
V_132 = V_176 ;
if ( V_132 / 16 > V_4 -> V_15 . V_178 ) {
V_42 = V_179 ;
goto V_180;
}
V_172 = & V_12 [ 8 ] ;
F_42 ( L_42
L_43 , V_4 -> V_9 -> V_102 , V_175 , V_176 , V_132 , V_172 ) ;
while ( V_132 >= 16 ) {
V_173 = F_59 ( & V_172 [ 0 ] ) ;
V_174 = F_11 ( & V_172 [ 8 ] ) ;
F_42 ( L_44 ,
( unsigned long long ) V_173 , V_174 ) ;
if ( V_174 > V_4 -> V_15 . V_181 ) {
V_42 = V_179 ;
goto V_180;
}
if ( V_173 + V_174 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_42 = V_51 ;
goto V_180;
}
V_42 = V_39 -> V_43 ( V_2 , V_173 , V_174 ) ;
if ( V_42 )
goto V_180;
V_172 += 16 ;
V_132 -= 16 ;
}
V_180:
F_4 ( V_2 ) ;
if ( ! V_42 )
F_8 ( V_2 , V_18 ) ;
return V_42 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_182 * V_183 ;
struct V_57 * V_184 = V_2 -> V_65 , * V_185 ;
T_4 V_186 = V_2 -> V_37 ;
void * V_187 , * V_188 ;
int V_61 , V_189 , V_59 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
V_188 = F_32 ( F_33 ( V_185 ) ) + V_185 -> V_59 ;
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
for ( V_189 = 0 ; V_189 < V_185 -> V_68 ;
V_189 += sizeof( * V_183 ) ) {
T_6 V_190 ;
unsigned int V_191 ;
if ( V_59 >= V_184 -> V_68 ) {
V_59 -= V_184 -> V_68 ;
F_34 ( V_187 - V_184 -> V_59 ) ;
V_184 = F_64 ( V_184 ) ;
if ( ! V_184 ) {
F_34 ( V_188 - V_185 -> V_59 ) ;
return;
}
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
}
V_183 = V_188 + V_189 ;
V_191 = F_46 ( V_16 , V_184 -> V_68 - V_59 ) ;
V_190 = F_65 ( V_187 + V_59 , V_191 ) ;
if ( V_191 < V_16 ) {
F_34 ( V_187 - V_184 -> V_59 ) ;
V_184 = F_64 ( V_184 ) ;
if ( ! V_184 ) {
F_34 ( V_188 - V_185 -> V_59 ) ;
return;
}
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
V_59 = V_16 - V_191 ;
V_190 = F_66 ( V_190 , V_187 , V_59 ) ;
} else {
V_59 += V_16 ;
}
V_183 -> V_192 = F_67 ( V_190 ) ;
if ( V_2 -> V_109 == V_116 )
V_183 -> V_193 = F_68 ( V_186 & 0xffffffff ) ;
V_183 -> V_194 = 0 ;
F_42 ( L_45
L_46 ,
( V_2 -> V_70 == V_145 ) ?
L_47 : L_48 , ( unsigned long long ) V_186 ,
V_183 -> V_192 , V_183 -> V_194 ,
F_69 ( V_183 -> V_193 ) ) ;
V_186 ++ ;
}
F_34 ( V_187 - V_184 -> V_59 ) ;
F_34 ( V_188 - V_185 -> V_59 ) ;
}
}
static T_1
F_70 ( struct V_1 * V_2 , struct V_182 * V_183 ,
T_6 V_190 , T_4 V_186 , unsigned int V_195 )
{
T_7 V_196 ;
if ( ! ( V_2 -> V_114 & V_115 ) )
goto V_197;
V_196 = F_67 ( V_190 ) ;
if ( V_183 -> V_192 != V_196 ) {
F_25 ( L_49
L_50 , ( unsigned long long ) V_186 ,
F_71 ( V_183 -> V_192 ) , F_71 ( V_196 ) ) ;
return V_198 ;
}
V_197:
if ( ! ( V_2 -> V_114 & V_117 ) )
return 0 ;
if ( V_2 -> V_109 == V_116 &&
F_69 ( V_183 -> V_193 ) != ( V_186 & 0xffffffff ) ) {
F_25 ( L_51
L_52 , ( unsigned long long ) V_186 ,
F_69 ( V_183 -> V_193 ) , ( T_2 ) ( V_186 & 0xffffffff ) ) ;
return V_199 ;
}
if ( V_2 -> V_109 == V_127 &&
F_69 ( V_183 -> V_193 ) != V_195 ) {
F_25 ( L_53
L_54 , ( unsigned long long ) V_186 ,
F_69 ( V_183 -> V_193 ) , V_195 ) ;
return V_199 ;
}
return 0 ;
}
void F_72 ( struct V_1 * V_2 , unsigned int V_44 , bool V_200 ,
struct V_57 * V_58 , int V_201 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_57 * V_185 ;
void * V_188 , * V_56 ;
unsigned int V_61 , V_83 , V_202 ;
unsigned int V_59 = V_201 ;
if ( ! V_58 )
return;
V_202 = V_44 * V_4 -> V_129 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_203 , V_204 = 0 ;
V_188 = F_32 ( F_33 ( V_185 ) ) + V_185 -> V_59 ;
V_203 = F_46 ( V_202 , V_185 -> V_68 ) ;
while ( V_203 ) {
V_83 = F_46 ( V_203 , V_58 -> V_68 - V_59 ) ;
V_56 = F_32 ( F_33 ( V_58 ) ) + V_58 -> V_59 + V_59 ;
if ( V_200 )
memcpy ( V_188 + V_204 , V_56 , V_83 ) ;
else
memcpy ( V_56 , V_188 + V_204 , V_83 ) ;
V_202 -= V_83 ;
V_59 += V_83 ;
V_204 += V_83 ;
V_203 -= V_83 ;
F_34 ( V_56 - V_58 -> V_59 - V_59 ) ;
if ( V_59 >= V_58 -> V_68 ) {
V_58 = F_64 ( V_58 ) ;
V_59 = 0 ;
}
}
F_34 ( V_188 - V_185 -> V_59 ) ;
}
}
T_1
F_73 ( struct V_1 * V_2 , T_4 V_205 , unsigned int V_44 ,
unsigned int V_195 , struct V_57 * V_185 , int V_206 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_182 * V_183 ;
struct V_57 * V_184 = V_2 -> V_65 ;
T_4 V_186 = V_205 ;
void * V_187 , * V_188 ;
int V_61 ;
T_1 V_87 ;
int V_207 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
for (; V_185 && V_186 < V_205 + V_44 ; V_185 = F_64 ( V_185 ) ) {
V_188 = F_32 ( F_33 ( V_185 ) ) + V_185 -> V_59 ;
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
for ( V_61 = V_206 ; V_61 < V_185 -> V_68 &&
V_186 < V_205 + V_44 ;
V_61 += sizeof( * V_183 ) ) {
T_6 V_190 ;
unsigned int V_191 ;
if ( V_207 >= V_184 -> V_68 ) {
V_207 -= V_184 -> V_68 ;
F_34 ( V_187 - V_184 -> V_59 ) ;
V_184 = F_64 ( V_184 ) ;
if ( ! V_184 ) {
F_34 ( V_188 - V_185 -> V_59 ) ;
return 0 ;
}
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
}
V_183 = V_188 + V_61 ;
F_42 ( L_55
L_46 ,
( unsigned long long ) V_186 , V_183 -> V_192 ,
V_183 -> V_194 , F_69 ( V_183 -> V_193 ) ) ;
if ( V_183 -> V_194 == F_67 ( 0xffff ) ) {
V_207 += V_16 ;
goto V_208;
}
V_191 = F_46 ( V_16 , V_184 -> V_68 - V_207 ) ;
V_190 = F_65 ( V_187 + V_207 , V_191 ) ;
if ( V_191 < V_16 ) {
F_34 ( V_187 - V_184 -> V_59 ) ;
V_184 = F_64 ( V_184 ) ;
if ( ! V_184 ) {
F_34 ( V_188 - V_185 -> V_59 ) ;
return 0 ;
}
V_187 = F_32 ( F_33 ( V_184 ) ) + V_184 -> V_59 ;
V_207 = V_16 - V_191 ;
V_190 = F_66 ( V_190 , V_187 , V_207 ) ;
} else {
V_207 += V_16 ;
}
V_87 = F_70 ( V_2 , V_183 , V_190 , V_186 , V_195 ) ;
if ( V_87 ) {
F_34 ( V_187 - V_184 -> V_59 ) ;
F_34 ( V_188 - V_185 -> V_59 ) ;
V_2 -> V_209 = V_186 ;
return V_87 ;
}
V_208:
V_186 ++ ;
V_195 ++ ;
}
V_206 = 0 ;
F_34 ( V_187 - V_184 -> V_59 ) ;
F_34 ( V_188 - V_185 -> V_59 ) ;
}
return 0 ;
}
