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
if ( V_4 -> V_15 . V_30 || V_4 -> V_15 . V_31 )
V_12 [ 14 ] |= 0x80 ;
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
F_8 ( V_2 , V_32 ) ;
return 0 ;
}
T_4 F_9 ( struct V_1 * V_2 )
{
T_2 V_33 ;
if ( V_2 -> V_7 [ 0 ] == V_34 )
V_33 = F_10 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_35 )
V_33 = F_11 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_33 = F_11 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_33 )
return V_33 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_36 + 1 ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
T_4 V_40 = F_9 ( V_2 ) ;
T_1 V_41 ;
if ( V_40 ) {
V_41 = V_38 -> V_42 ( V_2 , V_2 -> V_36 , V_40 ) ;
if ( V_41 )
return V_41 ;
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
static inline T_2 F_14 ( struct V_1 * V_2 , T_2 V_43 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_43 ;
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
unsigned int V_44 , V_45 ;
V_44 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_45 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_45 ) | ( unsigned long long ) V_44 << 32 ;
}
static inline unsigned long long F_23 ( unsigned char * V_6 )
{
unsigned int V_44 , V_45 ;
V_44 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_45 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_45 ) | ( unsigned long long ) V_44 << 32 ;
}
static T_1
F_24 ( struct V_1 * V_2 , unsigned char * V_46 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_47 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
unsigned int V_43 = F_9 ( V_2 ) ;
T_1 V_41 ;
if ( ( V_46 [ 0 ] & 0x04 ) || ( V_46 [ 0 ] & 0x02 ) ) {
F_25 ( L_1
L_2
L_3 ) ;
return V_48 ;
}
if ( V_43 > V_2 -> V_5 -> V_15 . V_49 ) {
F_26 ( L_4 ,
V_43 , V_2 -> V_5 -> V_15 . V_49 ) ;
return V_14 ;
}
if ( ( ( V_2 -> V_36 + V_43 ) < V_2 -> V_36 ) ||
( ( V_2 -> V_36 + V_43 ) > V_47 ) ) {
F_25 ( L_5 ,
( unsigned long long ) V_47 , V_2 -> V_36 , V_43 ) ;
return V_50 ;
}
if ( V_46 [ 0 ] & 0x10 ) {
F_26 ( L_6 ) ;
return V_14 ;
}
if ( V_46 [ 0 ] & 0x08 ) {
if ( ! V_38 -> V_42 )
return V_48 ;
if ( ! V_4 -> V_15 . V_31 ) {
F_25 ( L_7
L_8 ) ;
return V_48 ;
}
V_2 -> V_51 = F_12 ;
return 0 ;
}
if ( ! V_38 -> V_52 )
return V_48 ;
V_41 = F_27 ( V_4 , V_2 , & V_2 -> V_7 [ 0 ] , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_51 = V_38 -> V_52 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 , bool V_53 )
{
unsigned char * V_12 , * V_54 ;
struct V_55 * V_56 ;
unsigned int V_57 ;
T_1 V_41 = V_58 ;
int V_59 , V_60 ;
V_12 = F_29 ( V_2 -> V_17 , V_61 ) ;
if ( ! V_12 ) {
F_25 ( L_9 ) ;
return V_62 ;
}
F_30 ( V_2 -> V_63 ,
V_2 -> V_64 ,
V_12 ,
V_2 -> V_17 ) ;
V_57 = 0 ;
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_54 = F_32 ( F_33 ( V_56 ) ) ;
if ( ! V_54 ) {
V_41 = V_62 ;
goto V_65;
}
for ( V_59 = 0 ; V_59 < V_56 -> V_66 ; V_59 ++ )
* ( V_54 + V_56 -> V_57 + V_59 ) ^= * ( V_12 + V_57 + V_59 ) ;
V_57 += V_56 -> V_66 ;
F_34 ( V_54 ) ;
}
V_65:
F_35 ( V_12 ) ;
return V_41 ;
}
static T_1
F_36 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
return V_38 -> V_67 ( V_2 , V_2 -> V_63 , V_2 -> V_64 ,
V_2 -> V_68 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 , bool V_53 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_38 ( & V_2 -> V_69 ) ;
if ( ( V_2 -> V_70 & V_71 ) && ! V_2 -> V_72 )
V_2 -> V_73 |= V_74 ;
F_39 ( & V_2 -> V_69 ) ;
F_40 ( & V_4 -> V_75 ) ;
return V_58 ;
}
static T_1 F_41 ( struct V_1 * V_2 , bool V_53 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_55 * V_76 = NULL , * V_56 ;
unsigned char * V_12 = NULL , * V_54 ;
struct V_77 V_78 ;
unsigned int V_57 = 0 , V_79 ;
unsigned int V_80 = V_2 -> V_81 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_82 = ( V_80 * V_16 ) ;
T_1 V_41 = V_58 ;
int V_83 , V_59 ;
if ( ! V_53 && ( ! V_2 -> V_63 || ! V_2 -> V_84 ) )
return V_58 ;
if ( ! V_2 -> V_17 )
goto V_65;
if ( V_2 -> V_72 ) {
F_25 ( L_10
L_11 , V_2 -> V_72 ) ;
goto V_65;
}
V_12 = F_42 ( V_2 -> V_17 , V_61 ) ;
if ( ! V_12 ) {
F_25 ( L_12 ) ;
V_41 = V_62 ;
goto V_65;
}
V_76 = F_29 ( sizeof( struct V_55 ) * V_2 -> V_64 ,
V_61 ) ;
if ( ! V_76 ) {
F_25 ( L_13 ) ;
V_41 = V_62 ;
goto V_65;
}
F_43 ( V_76 , V_2 -> V_64 ) ;
V_83 = F_30 ( V_2 -> V_63 , V_2 -> V_64 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_83 ) {
F_25 ( L_14 ) ;
V_41 = V_62 ;
goto V_65;
}
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_54 = ( unsigned char * ) F_32 ( F_33 ( V_56 ) ) ;
if ( ! V_54 ) {
V_41 = V_62 ;
goto V_65;
}
V_79 = F_44 ( V_56 -> V_66 , V_82 ) ;
if ( memcmp ( V_54 , V_12 + V_57 , V_79 ) ) {
F_26 ( L_15 ,
V_54 , V_12 + V_57 ) ;
F_34 ( V_54 ) ;
goto V_85;
}
F_34 ( V_54 ) ;
V_57 += V_79 ;
V_82 -= V_79 ;
if ( ! V_82 )
break;
}
V_59 = 0 ;
V_79 = V_2 -> V_81 * V_16 ;
F_45 ( & V_78 , V_2 -> V_63 , V_2 -> V_64 , V_86 ) ;
while ( V_79 ) {
F_46 ( & V_78 ) ;
if ( V_16 < V_87 ) {
F_47 ( & V_76 [ V_59 ] , V_78 . V_88 , V_16 ,
V_16 ) ;
} else {
F_46 ( & V_78 ) ;
F_47 ( & V_76 [ V_59 ] , V_78 . V_88 , V_16 ,
0 ) ;
}
V_79 -= V_16 ;
V_59 ++ ;
}
F_48 ( & V_78 ) ;
V_2 -> V_89 = V_2 -> V_63 ;
V_2 -> V_63 = V_76 ;
V_2 -> V_90 = V_2 -> V_64 ;
V_2 -> V_64 = 1 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = F_37 ;
V_2 -> V_51 = F_36 ;
F_38 ( & V_2 -> V_69 ) ;
V_2 -> V_94 = V_95 ;
V_2 -> V_70 |= V_96 | V_97 | V_71 ;
F_39 ( & V_2 -> V_69 ) ;
F_49 ( V_2 ) ;
F_35 ( V_12 ) ;
return V_41 ;
V_85:
F_26 ( L_16 ,
V_4 -> V_9 -> V_98 ) ;
V_41 = V_99 ;
V_65:
F_40 ( & V_4 -> V_75 ) ;
F_35 ( V_76 ) ;
F_35 ( V_12 ) ;
return V_41 ;
}
static T_1
F_50 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
int V_83 ;
V_83 = F_51 ( & V_4 -> V_75 ) ;
if ( V_83 != 0 ) {
V_2 -> V_93 = NULL ;
return V_100 ;
}
V_2 -> V_17 = V_2 -> V_81 * V_4 -> V_15 . V_16 ;
V_41 = V_38 -> V_67 ( V_2 , V_2 -> V_84 , V_2 -> V_101 ,
V_102 ) ;
if ( V_41 ) {
V_2 -> V_93 = NULL ;
F_40 ( & V_4 -> V_75 ) ;
return V_41 ;
}
return V_58 ;
}
static int
F_52 ( T_5 V_103 , bool V_104 , enum V_105 V_106 ,
bool V_107 , struct V_1 * V_2 )
{
if ( V_107 ) {
V_2 -> V_108 = V_104 ? V_109 :
V_103 ? V_25 :
V_110 ;
switch ( V_103 ) {
case 0x0 :
case 0x3 :
V_2 -> V_111 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_111 = V_112 ;
if ( V_106 == V_113 )
V_2 -> V_111 |= V_114 ;
break;
case 0x2 :
if ( V_106 == V_113 )
V_2 -> V_111 = V_114 ;
break;
case 0x4 :
V_2 -> V_111 = V_112 ;
break;
default:
F_25 ( L_17 , V_103 ) ;
return - V_115 ;
}
} else {
V_2 -> V_108 = V_104 ? V_116 :
V_103 ? V_24 :
V_117 ;
switch ( V_103 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_111 = V_112 ;
if ( V_106 == V_113 )
V_2 -> V_111 |= V_114 ;
break;
case 0x2 :
if ( V_106 == V_113 )
V_2 -> V_111 = V_114 ;
break;
case 0x3 :
V_2 -> V_111 = 0 ;
break;
case 0x4 :
V_2 -> V_111 = V_112 ;
break;
default:
F_25 ( L_17 , V_103 ) ;
return - V_115 ;
}
}
return 0 ;
}
static T_1
F_27 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_43 , bool V_107 )
{
T_5 V_103 = V_6 [ 1 ] >> 5 ;
int V_118 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_104 = false ;
if ( ! V_2 -> V_119 || ! V_2 -> V_120 ) {
if ( F_53 ( V_103 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_25 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_121 )
return V_58 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_122 :
V_2 -> V_123 = 0xffffffff ;
break;
case V_124 :
if ( V_103 )
return V_14 ;
V_2 -> V_123 = V_2 -> V_36 ;
break;
case V_113 :
V_2 -> V_123 = V_2 -> V_36 ;
break;
case V_125 :
V_104 = V_107 ?
! ! ( V_118 & ( V_25 | V_109 ) ) :
! ! ( V_118 & ( V_24 | V_116 ) ) ;
if ( V_104 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_103 )
return V_58 ;
default:
F_25 ( L_20
L_21 , V_6 [ 0 ] , V_103 ) ;
return V_14 ;
}
if ( F_52 ( V_103 , V_104 , V_22 , V_107 , V_2 ) )
return V_14 ;
V_2 -> V_106 = V_22 ;
V_2 -> V_126 = V_4 -> V_126 * V_43 ;
if ( V_103 )
V_2 -> V_17 = V_43 * V_4 -> V_15 . V_16 ;
F_54 ( L_22
L_23 ,
V_127 , V_2 -> V_106 , V_2 -> V_17 , V_2 -> V_126 ,
V_2 -> V_108 , V_2 -> V_111 ) ;
return V_58 ;
}
static int
F_55 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! F_56 ( V_4 ) ) {
F_25 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_115 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! F_56 ( V_4 ) ) {
F_25 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_115 ;
}
V_2 -> V_73 |= V_128 ;
}
return 0 ;
}
T_1
F_57 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_129 ;
T_2 V_43 = 0 ;
T_1 V_41 ;
V_2 -> V_39 = V_38 ;
switch ( V_6 [ 0 ] ) {
case V_130 :
V_43 = F_15 ( V_6 ) ;
V_2 -> V_36 = F_20 ( V_6 ) ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_132 :
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_133 :
V_43 = F_17 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_134 :
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_135 :
V_43 = F_15 ( V_6 ) ;
V_2 -> V_36 = F_20 ( V_6 ) ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_136 :
case V_137 :
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_138 :
V_43 = F_17 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_139 :
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
break;
case V_140 :
if ( V_2 -> V_68 != V_141 ||
! ( V_2 -> V_73 & V_142 ) )
return V_14 ;
V_43 = F_16 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_36 = F_21 ( V_6 ) ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
V_2 -> V_93 = & F_28 ;
break;
case V_143 :
{
T_3 V_144 = F_10 ( & V_6 [ 8 ] ) ;
switch ( V_144 ) {
case V_145 :
V_43 = F_19 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_36 = F_23 ( V_6 ) ;
V_2 -> V_73 |= V_131 ;
V_2 -> V_51 = F_36 ;
V_2 -> V_93 = & F_28 ;
break;
case V_146 :
V_43 = F_19 ( V_6 ) ;
if ( ! V_43 ) {
F_25 ( L_28
L_29 ) ;
return V_14 ;
}
V_129 = F_14 ( V_2 , 1 ) ;
V_2 -> V_36 = F_58 ( & V_6 [ 12 ] ) ;
V_41 = F_24 ( V_2 , & V_6 [ 10 ] , V_38 ) ;
if ( V_41 )
return V_41 ;
break;
default:
F_25 ( L_30
L_31 , V_144 ) ;
return V_48 ;
}
break;
}
case V_147 :
V_43 = V_6 [ 13 ] ;
if ( V_43 > 1 ) {
F_25 ( L_32
L_33 , V_43 ) ;
return V_14 ;
}
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_129 = 2 * F_14 ( V_2 , V_43 ) ;
V_2 -> V_36 = F_58 ( & V_6 [ 2 ] ) ;
V_2 -> V_81 = V_43 ;
V_2 -> V_73 |= V_131 | V_148 ;
V_2 -> V_51 = F_50 ;
V_2 -> V_93 = F_41 ;
break;
case V_149 :
V_129 = V_150 ;
V_2 -> V_51 = F_1 ;
break;
case V_151 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_152 :
V_2 -> V_51 = F_6 ;
break;
case V_153 :
V_2 -> V_51 = V_154 ;
break;
default:
F_25 ( L_34 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_129 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_155 :
case V_156 :
if ( V_6 [ 0 ] == V_155 ) {
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
} else {
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
}
if ( V_38 -> V_157 ) {
V_2 -> V_51 = V_38 -> V_157 ;
goto V_158;
}
V_129 = 0 ;
V_2 -> V_51 = F_13 ;
break;
case V_159 :
if ( ! V_38 -> V_42 )
return V_48 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_25 ( L_35
L_36 ) ;
return V_48 ;
}
V_129 = F_10 ( & V_6 [ 7 ] ) ;
V_2 -> V_51 = V_160 ;
break;
case V_35 :
V_43 = F_18 ( V_6 ) ;
if ( ! V_43 ) {
F_25 ( L_37 ) ;
return V_14 ;
}
V_129 = F_14 ( V_2 , 1 ) ;
V_2 -> V_36 = F_58 ( & V_6 [ 2 ] ) ;
V_41 = F_24 ( V_2 , & V_6 [ 1 ] , V_38 ) ;
if ( V_41 )
return V_41 ;
break;
case V_34 :
V_43 = F_16 ( V_6 ) ;
if ( ! V_43 ) {
F_25 ( L_37 ) ;
return V_14 ;
}
V_129 = F_14 ( V_2 , 1 ) ;
V_2 -> V_36 = F_11 ( & V_6 [ 2 ] ) ;
V_41 = F_24 ( V_2 , & V_6 [ 1 ] , V_38 ) ;
if ( V_41 )
return V_41 ;
break;
case V_161 :
V_129 = 0 ;
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
V_2 -> V_51 = F_13 ;
goto V_158;
case V_162 :
case V_163 :
case V_164 :
V_129 = 0 ;
V_2 -> V_51 = F_13 ;
break;
case V_165 :
V_129 = 0 ;
V_2 -> V_51 = F_7 ;
break;
default:
V_41 = F_59 ( V_2 , & V_129 ) ;
if ( V_41 )
return V_41 ;
}
if ( ! V_2 -> V_51 )
return V_48 ;
if ( V_2 -> V_73 & V_131 ) {
unsigned long long V_47 ;
V_158:
V_47 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_36 + V_43 ) < V_2 -> V_36 ) ||
( ( V_2 -> V_36 + V_43 ) > V_47 ) ) {
F_25 ( L_38
L_39 ,
V_47 , V_2 -> V_36 , V_43 ) ;
return V_50 ;
}
if ( ! ( V_2 -> V_73 & V_148 ) )
V_129 = F_14 ( V_2 , V_43 ) ;
}
return F_60 ( V_2 , V_129 ) ;
}
T_2 F_61 ( struct V_3 * V_4 )
{
return V_166 ;
}
static T_1
V_160 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_167 = NULL ;
T_4 V_168 ;
int V_129 ;
T_2 V_169 ;
T_1 V_41 = 0 ;
int V_170 , V_171 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_8 ( V_2 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_26 ( L_40 ,
V_2 -> V_17 ) ;
return V_172 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_100 ;
V_170 = F_10 ( & V_12 [ 0 ] ) ;
V_171 = F_10 ( & V_12 [ 2 ] ) ;
V_129 = V_2 -> V_17 - 8 ;
if ( V_171 > V_129 )
F_26 ( L_41 ,
V_2 -> V_17 , V_171 ) ;
else
V_129 = V_171 ;
if ( V_129 / 16 > V_4 -> V_15 . V_173 ) {
V_41 = V_174 ;
goto V_175;
}
V_167 = & V_12 [ 8 ] ;
F_54 ( L_42
L_43 , V_4 -> V_9 -> V_98 , V_170 , V_171 , V_129 , V_167 ) ;
while ( V_129 >= 16 ) {
V_168 = F_58 ( & V_167 [ 0 ] ) ;
V_169 = F_11 ( & V_167 [ 8 ] ) ;
F_54 ( L_44 ,
( unsigned long long ) V_168 , V_169 ) ;
if ( V_169 > V_4 -> V_15 . V_176 ) {
V_41 = V_174 ;
goto V_175;
}
if ( V_168 + V_169 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_41 = V_50 ;
goto V_175;
}
V_41 = V_38 -> V_42 ( V_2 , V_168 , V_169 ) ;
if ( V_41 )
goto V_175;
V_167 += 16 ;
V_129 -= 16 ;
}
V_175:
F_4 ( V_2 ) ;
if ( ! V_41 )
F_8 ( V_2 , V_18 ) ;
return V_41 ;
}
void
F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_177 * V_178 ;
struct V_55 * V_179 = V_2 -> V_63 , * V_180 ;
T_4 V_181 = V_2 -> V_36 ;
void * V_182 , * V_183 ;
int V_59 , V_184 , V_57 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
V_183 = F_32 ( F_33 ( V_180 ) ) + V_180 -> V_57 ;
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
for ( V_184 = 0 ; V_184 < V_180 -> V_66 ;
V_184 += sizeof( * V_178 ) ) {
T_6 V_185 ;
unsigned int V_186 ;
if ( V_57 >= V_179 -> V_66 ) {
V_57 -= V_179 -> V_66 ;
F_34 ( V_182 - V_179 -> V_57 ) ;
V_179 = F_63 ( V_179 ) ;
if ( ! V_179 ) {
F_34 ( V_183 - V_180 -> V_57 ) ;
return;
}
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
}
V_178 = V_183 + V_184 ;
V_186 = F_44 ( V_16 , V_179 -> V_66 - V_57 ) ;
V_185 = F_64 ( V_182 + V_57 , V_186 ) ;
if ( V_186 < V_16 ) {
F_34 ( V_182 - V_179 -> V_57 ) ;
V_179 = F_63 ( V_179 ) ;
if ( ! V_179 ) {
F_34 ( V_183 - V_180 -> V_57 ) ;
return;
}
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
V_57 = V_16 - V_186 ;
V_185 = F_65 ( V_185 , V_182 , V_57 ) ;
} else {
V_57 += V_16 ;
}
V_178 -> V_187 = F_66 ( V_185 ) ;
if ( V_2 -> V_106 == V_113 )
V_178 -> V_188 = F_67 ( V_181 & 0xffffffff ) ;
V_178 -> V_189 = 0 ;
F_54 ( L_45
L_46 ,
( V_2 -> V_68 == V_141 ) ?
L_47 : L_48 , ( unsigned long long ) V_181 ,
V_178 -> V_187 , V_178 -> V_189 ,
F_68 ( V_178 -> V_188 ) ) ;
V_181 ++ ;
}
F_34 ( V_182 - V_179 -> V_57 ) ;
F_34 ( V_183 - V_180 -> V_57 ) ;
}
}
static T_1
F_69 ( struct V_1 * V_2 , struct V_177 * V_178 ,
T_6 V_185 , T_4 V_181 , unsigned int V_190 )
{
T_7 V_191 ;
if ( ! ( V_2 -> V_111 & V_112 ) )
goto V_192;
V_191 = F_66 ( V_185 ) ;
if ( V_178 -> V_187 != V_191 ) {
F_25 ( L_49
L_50 , ( unsigned long long ) V_181 ,
F_70 ( V_178 -> V_187 ) , F_70 ( V_191 ) ) ;
return V_193 ;
}
V_192:
if ( ! ( V_2 -> V_111 & V_114 ) )
return 0 ;
if ( V_2 -> V_106 == V_113 &&
F_68 ( V_178 -> V_188 ) != ( V_181 & 0xffffffff ) ) {
F_25 ( L_51
L_52 , ( unsigned long long ) V_181 ,
F_68 ( V_178 -> V_188 ) , ( T_2 ) ( V_181 & 0xffffffff ) ) ;
return V_194 ;
}
if ( V_2 -> V_106 == V_124 &&
F_68 ( V_178 -> V_188 ) != V_190 ) {
F_25 ( L_53
L_54 , ( unsigned long long ) V_181 ,
F_68 ( V_178 -> V_188 ) , V_190 ) ;
return V_194 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , unsigned int V_43 , bool V_195 ,
struct V_55 * V_56 , int V_196 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_55 * V_180 ;
void * V_183 , * V_54 ;
unsigned int V_59 , V_79 , V_197 ;
unsigned int V_57 = V_196 ;
if ( ! V_56 )
return;
V_197 = V_43 * V_4 -> V_126 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_198 , V_199 = 0 ;
V_183 = F_32 ( F_33 ( V_180 ) ) + V_180 -> V_57 ;
V_198 = F_44 ( V_197 , V_180 -> V_66 ) ;
while ( V_198 ) {
V_79 = F_44 ( V_198 , V_56 -> V_66 - V_57 ) ;
V_54 = F_32 ( F_33 ( V_56 ) ) + V_56 -> V_57 + V_57 ;
if ( V_195 )
memcpy ( V_183 + V_199 , V_54 , V_79 ) ;
else
memcpy ( V_54 , V_183 + V_199 , V_79 ) ;
V_197 -= V_79 ;
V_57 += V_79 ;
V_199 += V_79 ;
V_198 -= V_79 ;
F_34 ( V_54 - V_56 -> V_57 - V_57 ) ;
if ( V_57 >= V_56 -> V_66 ) {
V_56 = F_63 ( V_56 ) ;
V_57 = 0 ;
}
}
F_34 ( V_183 - V_180 -> V_57 ) ;
}
}
T_1
F_72 ( struct V_1 * V_2 , T_4 V_200 , unsigned int V_43 ,
unsigned int V_190 , struct V_55 * V_180 , int V_201 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_177 * V_178 ;
struct V_55 * V_179 = V_2 -> V_63 ;
T_4 V_181 = V_200 ;
void * V_182 , * V_183 ;
int V_59 ;
T_1 V_83 ;
int V_202 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
for (; V_180 && V_181 < V_200 + V_43 ; V_180 = F_63 ( V_180 ) ) {
V_183 = F_32 ( F_33 ( V_180 ) ) + V_180 -> V_57 ;
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
for ( V_59 = V_201 ; V_59 < V_180 -> V_66 &&
V_181 < V_200 + V_43 ;
V_59 += sizeof( * V_178 ) ) {
T_6 V_185 ;
unsigned int V_186 ;
if ( V_202 >= V_179 -> V_66 ) {
V_202 -= V_179 -> V_66 ;
F_34 ( V_182 - V_179 -> V_57 ) ;
V_179 = F_63 ( V_179 ) ;
if ( ! V_179 ) {
F_34 ( V_183 - V_180 -> V_57 ) ;
return 0 ;
}
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
}
V_178 = V_183 + V_59 ;
F_54 ( L_55
L_46 ,
( unsigned long long ) V_181 , V_178 -> V_187 ,
V_178 -> V_189 , F_68 ( V_178 -> V_188 ) ) ;
if ( V_178 -> V_189 == F_66 ( 0xffff ) ) {
V_202 += V_16 ;
goto V_203;
}
V_186 = F_44 ( V_16 , V_179 -> V_66 - V_202 ) ;
V_185 = F_64 ( V_182 + V_202 , V_186 ) ;
if ( V_186 < V_16 ) {
F_34 ( V_182 - V_179 -> V_57 ) ;
V_179 = F_63 ( V_179 ) ;
if ( ! V_179 ) {
F_34 ( V_183 - V_180 -> V_57 ) ;
return 0 ;
}
V_182 = F_32 ( F_33 ( V_179 ) ) + V_179 -> V_57 ;
V_202 = V_16 - V_186 ;
V_185 = F_65 ( V_185 , V_182 , V_202 ) ;
} else {
V_202 += V_16 ;
}
V_83 = F_69 ( V_2 , V_178 , V_185 , V_181 , V_190 ) ;
if ( V_83 ) {
F_34 ( V_182 - V_179 -> V_57 ) ;
F_34 ( V_183 - V_180 -> V_57 ) ;
V_2 -> V_204 = V_181 ;
return V_83 ;
}
V_203:
V_181 ++ ;
V_190 ++ ;
}
V_201 = 0 ;
F_34 ( V_182 - V_179 -> V_57 ) ;
F_34 ( V_183 - V_180 -> V_57 ) ;
}
return 0 ;
}
