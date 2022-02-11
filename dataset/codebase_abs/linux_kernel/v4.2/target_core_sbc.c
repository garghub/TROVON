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
T_4 F_7 ( struct V_1 * V_2 )
{
T_2 V_32 ;
if ( V_2 -> V_7 [ 0 ] == V_33 )
V_32 = F_8 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_34 )
V_32 = F_9 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_32 = F_9 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_32 )
return V_32 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_35 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
T_4 V_39 = F_7 ( V_2 ) ;
T_1 V_40 ;
if ( V_39 ) {
V_40 = V_37 -> V_41 ( V_2 , V_2 -> V_35 , V_39 ) ;
if ( V_40 )
return V_40 ;
}
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_13 ( struct V_1 * V_2 , T_2 V_42 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_42 ;
}
static inline T_2 F_14 ( unsigned char * V_6 )
{
return V_6 [ 4 ] ? : 256 ;
}
static inline T_2 F_15 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 7 ] << 8 ) + V_6 [ 8 ] ;
}
static inline T_2 F_16 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 6 ] << 24 ) + ( V_6 [ 7 ] << 16 ) + ( V_6 [ 8 ] << 8 ) + V_6 [ 9 ] ;
}
static inline T_2 F_17 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 10 ] << 24 ) + ( V_6 [ 11 ] << 16 ) +
( V_6 [ 12 ] << 8 ) + V_6 [ 13 ] ;
}
static inline T_2 F_18 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 28 ] << 24 ) + ( V_6 [ 29 ] << 16 ) +
( V_6 [ 30 ] << 8 ) + V_6 [ 31 ] ;
}
static inline T_2 F_19 ( unsigned char * V_6 )
{
return ( ( V_6 [ 1 ] & 0x1f ) << 16 ) | ( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
}
static inline T_2 F_20 ( unsigned char * V_6 )
{
return ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
}
static inline unsigned long long F_21 ( unsigned char * V_6 )
{
unsigned int V_43 , V_44 ;
V_43 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_44 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_44 ) | ( unsigned long long ) V_43 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_43 , V_44 ;
V_43 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_44 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_44 ) | ( unsigned long long ) V_43 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_45 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_46 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
unsigned int V_42 = F_7 ( V_2 ) ;
T_1 V_40 ;
if ( ( V_45 [ 0 ] & 0x04 ) || ( V_45 [ 0 ] & 0x02 ) ) {
F_24 ( L_1
L_2
L_3 ) ;
return V_47 ;
}
if ( V_42 > V_2 -> V_5 -> V_15 . V_48 ) {
F_25 ( L_4 ,
V_42 , V_2 -> V_5 -> V_15 . V_48 ) ;
return V_14 ;
}
if ( ( ( V_2 -> V_35 + V_42 ) < V_2 -> V_35 ) ||
( ( V_2 -> V_35 + V_42 ) > V_46 ) ) {
F_24 ( L_5 ,
( unsigned long long ) V_46 , V_2 -> V_35 , V_42 ) ;
return V_49 ;
}
if ( V_45 [ 0 ] & 0x10 ) {
F_25 ( L_6 ) ;
return V_14 ;
}
if ( V_45 [ 0 ] & 0x08 ) {
if ( ! V_37 -> V_41 )
return V_47 ;
if ( ! V_4 -> V_15 . V_31 ) {
F_24 ( L_7
L_8 ) ;
return V_47 ;
}
V_2 -> V_50 = F_10 ;
return 0 ;
}
if ( ! V_37 -> V_51 )
return V_47 ;
V_40 = F_26 ( V_4 , V_2 , & V_2 -> V_7 [ 0 ] , V_42 , true ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_50 = V_37 -> V_51 ;
return 0 ;
}
static T_1 F_27 ( struct V_1 * V_2 , bool V_52 )
{
unsigned char * V_12 , * V_53 ;
struct V_54 * V_55 ;
unsigned int V_56 ;
T_1 V_40 = V_57 ;
int V_58 , V_59 ;
V_12 = F_28 ( V_2 -> V_17 , V_60 ) ;
if ( ! V_12 ) {
F_24 ( L_9 ) ;
return V_61 ;
}
F_29 ( V_2 -> V_62 ,
V_2 -> V_63 ,
V_12 ,
V_2 -> V_17 ) ;
V_56 = 0 ;
F_30 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_53 = F_31 ( F_32 ( V_55 ) ) ;
if ( ! V_53 ) {
V_40 = V_61 ;
goto V_64;
}
for ( V_58 = 0 ; V_58 < V_55 -> V_65 ; V_58 ++ )
* ( V_53 + V_55 -> V_56 + V_58 ) ^= * ( V_12 + V_56 + V_58 ) ;
V_56 += V_55 -> V_65 ;
F_33 ( V_53 ) ;
}
V_64:
F_34 ( V_12 ) ;
return V_40 ;
}
static T_1
F_35 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
return V_37 -> V_66 ( V_2 , V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_67 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , bool V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_37 ( & V_2 -> V_68 ) ;
if ( ( V_2 -> V_69 & V_70 ) && ! V_2 -> V_71 )
V_2 -> V_72 |= V_73 ;
F_38 ( & V_2 -> V_68 ) ;
F_39 ( & V_4 -> V_74 ) ;
return V_57 ;
}
static T_1 F_40 ( struct V_1 * V_2 , bool V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_54 * V_75 = NULL , * V_55 ;
unsigned char * V_12 = NULL , * V_53 ;
struct V_76 V_77 ;
unsigned int V_56 = 0 , V_78 ;
unsigned int V_79 = V_2 -> V_80 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_81 = ( V_79 * V_16 ) ;
T_1 V_40 = V_57 ;
int V_82 , V_58 ;
if ( ! V_52 && ( ! V_2 -> V_62 || ! V_2 -> V_83 ) )
return V_57 ;
if ( ! V_2 -> V_17 )
goto V_64;
if ( V_2 -> V_71 ) {
F_24 ( L_10
L_11 , V_2 -> V_71 ) ;
goto V_64;
}
V_12 = F_41 ( V_2 -> V_17 , V_60 ) ;
if ( ! V_12 ) {
F_24 ( L_12 ) ;
V_40 = V_61 ;
goto V_64;
}
V_75 = F_28 ( sizeof( struct V_54 ) * V_2 -> V_63 ,
V_60 ) ;
if ( ! V_75 ) {
F_24 ( L_13 ) ;
V_40 = V_61 ;
goto V_64;
}
F_42 ( V_75 , V_2 -> V_63 ) ;
V_82 = F_29 ( V_2 -> V_62 , V_2 -> V_63 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_82 ) {
F_24 ( L_14 ) ;
V_40 = V_61 ;
goto V_64;
}
F_30 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_53 = ( unsigned char * ) F_31 ( F_32 ( V_55 ) ) ;
if ( ! V_53 ) {
V_40 = V_61 ;
goto V_64;
}
V_78 = F_43 ( V_55 -> V_65 , V_81 ) ;
if ( memcmp ( V_53 , V_12 + V_56 , V_78 ) ) {
F_25 ( L_15 ,
V_53 , V_12 + V_56 ) ;
F_33 ( V_53 ) ;
goto V_84;
}
F_33 ( V_53 ) ;
V_56 += V_78 ;
V_81 -= V_78 ;
if ( ! V_81 )
break;
}
V_58 = 0 ;
V_78 = V_2 -> V_80 * V_16 ;
F_44 ( & V_77 , V_2 -> V_62 , V_2 -> V_63 , V_85 ) ;
while ( V_78 ) {
F_45 ( & V_77 ) ;
if ( V_16 < V_86 ) {
F_46 ( & V_75 [ V_58 ] , V_77 . V_87 , V_16 ,
V_16 ) ;
} else {
F_45 ( & V_77 ) ;
F_46 ( & V_75 [ V_58 ] , V_77 . V_87 , V_16 ,
0 ) ;
}
V_78 -= V_16 ;
V_58 ++ ;
}
F_47 ( & V_77 ) ;
V_2 -> V_88 = V_2 -> V_62 ;
V_2 -> V_62 = V_75 ;
V_2 -> V_89 = V_2 -> V_63 ;
V_2 -> V_63 = 1 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = F_36 ;
V_2 -> V_50 = F_35 ;
F_37 ( & V_2 -> V_68 ) ;
V_2 -> V_93 = V_94 ;
V_2 -> V_69 |= V_95 | V_96 | V_70 ;
F_38 ( & V_2 -> V_68 ) ;
F_48 ( V_2 ) ;
F_34 ( V_12 ) ;
return V_40 ;
V_84:
F_25 ( L_16 ,
V_4 -> V_9 -> V_97 ) ;
V_40 = V_98 ;
V_64:
F_39 ( & V_4 -> V_74 ) ;
F_34 ( V_75 ) ;
F_34 ( V_12 ) ;
return V_40 ;
}
static T_1
F_49 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
int V_82 ;
V_82 = F_50 ( & V_4 -> V_74 ) ;
if ( V_82 != 0 ) {
V_2 -> V_92 = NULL ;
return V_99 ;
}
V_2 -> V_17 = V_2 -> V_80 * V_4 -> V_15 . V_16 ;
V_40 = V_37 -> V_66 ( V_2 , V_2 -> V_83 , V_2 -> V_100 ,
V_101 ) ;
if ( V_40 ) {
V_2 -> V_92 = NULL ;
F_39 ( & V_4 -> V_74 ) ;
return V_40 ;
}
return V_57 ;
}
static int
F_51 ( T_5 V_102 , bool V_103 , enum V_104 V_105 ,
bool V_106 , struct V_1 * V_2 )
{
if ( V_106 ) {
V_2 -> V_107 = V_103 ? V_108 :
V_102 ? V_25 :
V_109 ;
switch ( V_102 ) {
case 0x0 :
case 0x3 :
V_2 -> V_110 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_110 = V_111 ;
if ( V_105 == V_112 )
V_2 -> V_110 |= V_113 ;
break;
case 0x2 :
if ( V_105 == V_112 )
V_2 -> V_110 = V_113 ;
break;
case 0x4 :
V_2 -> V_110 = V_111 ;
break;
default:
F_24 ( L_17 , V_102 ) ;
return - V_114 ;
}
} else {
V_2 -> V_107 = V_103 ? V_115 :
V_102 ? V_24 :
V_116 ;
switch ( V_102 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_110 = V_111 ;
if ( V_105 == V_112 )
V_2 -> V_110 |= V_113 ;
break;
case 0x2 :
if ( V_105 == V_112 )
V_2 -> V_110 = V_113 ;
break;
case 0x3 :
V_2 -> V_110 = 0 ;
break;
case 0x4 :
V_2 -> V_110 = V_111 ;
break;
default:
F_24 ( L_17 , V_102 ) ;
return - V_114 ;
}
}
return 0 ;
}
static T_1
F_26 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_42 , bool V_106 )
{
T_5 V_102 = V_6 [ 1 ] >> 5 ;
int V_117 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_103 = false ;
if ( ! V_2 -> V_118 || ! V_2 -> V_119 ) {
if ( F_52 ( V_102 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_24 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_120 )
return V_57 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_121 :
V_2 -> V_122 = 0xffffffff ;
break;
case V_123 :
if ( V_102 )
return V_14 ;
V_2 -> V_122 = V_2 -> V_35 ;
break;
case V_112 :
V_2 -> V_122 = V_2 -> V_35 ;
break;
case V_124 :
V_103 = V_106 ?
! ! ( V_117 & ( V_25 | V_108 ) ) :
! ! ( V_117 & ( V_24 | V_115 ) ) ;
if ( V_103 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_102 )
return V_57 ;
default:
F_24 ( L_20
L_21 , V_6 [ 0 ] , V_102 ) ;
return V_14 ;
}
if ( F_51 ( V_102 , V_103 , V_22 , V_106 , V_2 ) )
return V_14 ;
V_2 -> V_105 = V_22 ;
V_2 -> V_125 = V_4 -> V_125 * V_42 ;
if ( V_102 )
V_2 -> V_17 = V_42 * V_4 -> V_15 . V_16 ;
F_53 ( L_22
L_23 ,
V_126 , V_2 -> V_105 , V_2 -> V_17 , V_2 -> V_125 ,
V_2 -> V_107 , V_2 -> V_110 ) ;
return V_57 ;
}
static int
F_54 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! F_55 ( V_4 ) ) {
F_24 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_114 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! F_55 ( V_4 ) ) {
F_24 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_114 ;
}
V_2 -> V_72 |= V_127 ;
}
return 0 ;
}
T_1
F_56 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_128 ;
T_2 V_42 = 0 ;
T_1 V_40 ;
V_2 -> V_38 = V_37 ;
switch ( V_6 [ 0 ] ) {
case V_129 :
V_42 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_131 :
V_42 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , false ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_132 :
V_42 = F_16 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , false ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_133 :
V_42 = F_17 ( V_6 ) ;
V_2 -> V_35 = F_21 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , false ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_134 :
V_42 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_135 :
case V_136 :
V_42 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , true ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_137 :
V_42 = F_16 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , true ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_138 :
V_42 = F_17 ( V_6 ) ;
V_2 -> V_35 = F_21 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_40 = F_26 ( V_4 , V_2 , V_6 , V_42 , true ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
break;
case V_139 :
if ( V_2 -> V_67 != V_140 ||
! ( V_2 -> V_72 & V_141 ) )
return V_14 ;
V_42 = F_15 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_35 = F_20 ( V_6 ) ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
V_2 -> V_92 = & F_27 ;
break;
case V_142 :
{
T_3 V_143 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_143 ) {
case V_144 :
V_42 = F_18 ( V_6 ) ;
if ( F_54 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_35 = F_22 ( V_6 ) ;
V_2 -> V_72 |= V_130 ;
V_2 -> V_50 = F_35 ;
V_2 -> V_92 = & F_27 ;
break;
case V_145 :
V_42 = F_18 ( V_6 ) ;
if ( ! V_42 ) {
F_24 ( L_28
L_29 ) ;
return V_14 ;
}
V_128 = F_13 ( V_2 , 1 ) ;
V_2 -> V_35 = F_57 ( & V_6 [ 12 ] ) ;
V_40 = F_23 ( V_2 , & V_6 [ 10 ] , V_37 ) ;
if ( V_40 )
return V_40 ;
break;
default:
F_24 ( L_30
L_31 , V_143 ) ;
return V_47 ;
}
break;
}
case V_146 :
V_42 = V_6 [ 13 ] ;
if ( V_42 > 1 ) {
F_24 ( L_32
L_33 , V_42 ) ;
return V_14 ;
}
V_128 = 2 * F_13 ( V_2 , V_42 ) ;
V_2 -> V_35 = F_57 ( & V_6 [ 2 ] ) ;
V_2 -> V_80 = V_42 ;
V_2 -> V_72 |= V_130 | V_147 ;
V_2 -> V_50 = F_49 ;
V_2 -> V_92 = F_40 ;
break;
case V_148 :
V_128 = V_149 ;
V_2 -> V_50 = F_1 ;
break;
case V_150 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_151 :
V_2 -> V_50 = F_6 ;
break;
case V_152 :
V_2 -> V_50 = V_153 ;
break;
default:
F_24 ( L_34 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_128 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_154 :
case V_155 :
if ( V_6 [ 0 ] == V_154 ) {
V_42 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
} else {
V_42 = F_17 ( V_6 ) ;
V_2 -> V_35 = F_21 ( V_6 ) ;
}
if ( V_37 -> V_156 ) {
V_2 -> V_50 = V_37 -> V_156 ;
goto V_157;
}
V_128 = 0 ;
V_2 -> V_50 = F_12 ;
break;
case V_158 :
if ( ! V_37 -> V_41 )
return V_47 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_24 ( L_35
L_36 ) ;
return V_47 ;
}
V_128 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_50 = V_159 ;
break;
case V_34 :
V_42 = F_17 ( V_6 ) ;
if ( ! V_42 ) {
F_24 ( L_37 ) ;
return V_14 ;
}
V_128 = F_13 ( V_2 , 1 ) ;
V_2 -> V_35 = F_57 ( & V_6 [ 2 ] ) ;
V_40 = F_23 ( V_2 , & V_6 [ 1 ] , V_37 ) ;
if ( V_40 )
return V_40 ;
break;
case V_33 :
V_42 = F_15 ( V_6 ) ;
if ( ! V_42 ) {
F_24 ( L_37 ) ;
return V_14 ;
}
V_128 = F_13 ( V_2 , 1 ) ;
V_2 -> V_35 = F_9 ( & V_6 [ 2 ] ) ;
V_40 = F_23 ( V_2 , & V_6 [ 1 ] , V_37 ) ;
if ( V_40 )
return V_40 ;
break;
case V_160 :
V_128 = 0 ;
V_42 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
V_2 -> V_50 = F_12 ;
goto V_157;
case V_161 :
case V_162 :
case V_163 :
V_128 = 0 ;
V_2 -> V_50 = F_12 ;
break;
default:
V_40 = F_58 ( V_2 , & V_128 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_2 -> V_50 )
return V_47 ;
if ( V_2 -> V_72 & V_130 ) {
unsigned long long V_46 ;
V_157:
V_46 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_35 + V_42 ) < V_2 -> V_35 ) ||
( ( V_2 -> V_35 + V_42 ) > V_46 ) ) {
F_24 ( L_38
L_39 ,
V_46 , V_2 -> V_35 , V_42 ) ;
return V_49 ;
}
if ( ! ( V_2 -> V_72 & V_147 ) )
V_128 = F_13 ( V_2 , V_42 ) ;
}
return F_59 ( V_2 , V_128 ) ;
}
T_2 F_60 ( struct V_3 * V_4 )
{
return V_164 ;
}
static T_1
V_159 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_165 = NULL ;
T_4 V_166 ;
int V_128 ;
T_2 V_167 ;
T_1 V_40 = 0 ;
int V_168 , V_169 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_11 ( V_2 , V_170 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_25 ( L_40 ,
V_2 -> V_17 ) ;
return V_171 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_99 ;
V_168 = F_8 ( & V_12 [ 0 ] ) ;
V_169 = F_8 ( & V_12 [ 2 ] ) ;
V_128 = V_2 -> V_17 - 8 ;
if ( V_169 > V_128 )
F_25 ( L_41 ,
V_2 -> V_17 , V_169 ) ;
else
V_128 = V_169 ;
if ( V_128 / 16 > V_4 -> V_15 . V_172 ) {
V_40 = V_173 ;
goto V_174;
}
V_165 = & V_12 [ 8 ] ;
F_53 ( L_42
L_43 , V_4 -> V_9 -> V_97 , V_168 , V_169 , V_128 , V_165 ) ;
while ( V_128 >= 16 ) {
V_166 = F_57 ( & V_165 [ 0 ] ) ;
V_167 = F_9 ( & V_165 [ 8 ] ) ;
F_53 ( L_44 ,
( unsigned long long ) V_166 , V_167 ) ;
if ( V_167 > V_4 -> V_15 . V_175 ) {
V_40 = V_173 ;
goto V_174;
}
if ( V_166 + V_167 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_40 = V_49 ;
goto V_174;
}
V_40 = V_37 -> V_41 ( V_2 , V_166 , V_167 ) ;
if ( V_40 )
goto V_174;
V_165 += 16 ;
V_128 -= 16 ;
}
V_174:
F_4 ( V_2 ) ;
if ( ! V_40 )
F_11 ( V_2 , V_18 ) ;
return V_40 ;
}
void
F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_176 * V_177 ;
struct V_54 * V_178 = V_2 -> V_62 , * V_179 ;
T_4 V_180 = V_2 -> V_35 ;
void * V_181 , * V_182 ;
int V_58 , V_183 , V_56 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
F_30 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
V_182 = F_31 ( F_32 ( V_179 ) ) + V_179 -> V_56 ;
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
for ( V_183 = 0 ; V_183 < V_179 -> V_65 ;
V_183 += sizeof( struct V_176 ) ) {
T_6 V_184 ;
unsigned int V_185 ;
if ( V_56 >= V_178 -> V_65 ) {
V_56 -= V_178 -> V_65 ;
F_33 ( V_181 - V_178 -> V_56 ) ;
V_178 = F_62 ( V_178 ) ;
if ( ! V_178 ) {
F_33 ( V_182 - V_179 -> V_56 ) ;
return;
}
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
}
V_177 = V_182 + V_183 ;
V_185 = F_43 ( V_16 , V_178 -> V_65 - V_56 ) ;
V_184 = F_63 ( V_181 + V_56 , V_185 ) ;
if ( V_185 < V_16 ) {
F_33 ( V_181 - V_178 -> V_56 ) ;
V_178 = F_62 ( V_178 ) ;
if ( ! V_178 ) {
F_33 ( V_182 - V_179 -> V_56 ) ;
return;
}
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
V_56 = V_16 - V_185 ;
V_184 = F_64 ( V_184 , V_181 , V_56 ) ;
} else {
V_56 += V_16 ;
}
V_177 -> V_186 = F_65 ( V_184 ) ;
if ( V_2 -> V_105 == V_112 )
V_177 -> V_187 = F_66 ( V_180 & 0xffffffff ) ;
V_177 -> V_188 = 0 ;
F_53 ( L_45
L_46 ,
( V_2 -> V_67 == V_140 ) ?
L_47 : L_48 , ( unsigned long long ) V_180 ,
V_177 -> V_186 , V_177 -> V_188 ,
F_67 ( V_177 -> V_187 ) ) ;
V_180 ++ ;
}
F_33 ( V_181 - V_178 -> V_56 ) ;
F_33 ( V_182 - V_179 -> V_56 ) ;
}
}
static T_1
F_68 ( struct V_1 * V_2 , struct V_176 * V_177 ,
T_6 V_184 , T_4 V_180 , unsigned int V_189 )
{
T_7 V_190 ;
if ( ! ( V_2 -> V_110 & V_111 ) )
goto V_191;
V_190 = F_65 ( V_184 ) ;
if ( V_177 -> V_186 != V_190 ) {
F_24 ( L_49
L_50 , ( unsigned long long ) V_180 ,
F_69 ( V_177 -> V_186 ) , F_69 ( V_190 ) ) ;
return V_192 ;
}
V_191:
if ( ! ( V_2 -> V_110 & V_113 ) )
return 0 ;
if ( V_2 -> V_105 == V_112 &&
F_67 ( V_177 -> V_187 ) != ( V_180 & 0xffffffff ) ) {
F_24 ( L_51
L_52 , ( unsigned long long ) V_180 ,
F_67 ( V_177 -> V_187 ) , ( T_2 ) ( V_180 & 0xffffffff ) ) ;
return V_193 ;
}
if ( V_2 -> V_105 == V_123 &&
F_67 ( V_177 -> V_187 ) != V_189 ) {
F_24 ( L_53
L_54 , ( unsigned long long ) V_180 ,
F_67 ( V_177 -> V_187 ) , V_189 ) ;
return V_193 ;
}
return 0 ;
}
void F_70 ( struct V_1 * V_2 , unsigned int V_42 , bool V_194 ,
struct V_54 * V_55 , int V_195 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_54 * V_179 ;
void * V_182 , * V_53 ;
unsigned int V_58 , V_78 , V_196 ;
unsigned int V_56 = V_195 ;
if ( ! V_55 )
return;
V_196 = V_42 * V_4 -> V_125 ;
F_30 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_197 , V_198 = 0 ;
V_182 = F_31 ( F_32 ( V_179 ) ) + V_179 -> V_56 ;
V_197 = F_43 ( V_196 , V_179 -> V_65 ) ;
while ( V_197 ) {
V_78 = F_43 ( V_197 , V_55 -> V_65 - V_56 ) ;
V_53 = F_31 ( F_32 ( V_55 ) ) + V_55 -> V_56 + V_56 ;
if ( V_194 )
memcpy ( V_182 + V_198 , V_53 , V_78 ) ;
else
memcpy ( V_53 , V_182 + V_198 , V_78 ) ;
V_196 -= V_78 ;
V_56 += V_78 ;
V_198 += V_78 ;
V_197 -= V_78 ;
F_33 ( V_53 - V_55 -> V_56 - V_56 ) ;
if ( V_56 >= V_55 -> V_65 ) {
V_55 = F_62 ( V_55 ) ;
V_56 = 0 ;
}
}
F_33 ( V_182 - V_179 -> V_56 ) ;
}
}
T_1
F_71 ( struct V_1 * V_2 , T_4 V_199 , unsigned int V_42 ,
unsigned int V_189 , struct V_54 * V_179 , int V_200 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_176 * V_177 ;
struct V_54 * V_178 = V_2 -> V_62 ;
T_4 V_180 = V_199 ;
void * V_181 , * V_182 ;
int V_58 ;
T_1 V_82 ;
int V_201 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
for (; V_179 && V_180 < V_199 + V_42 ; V_179 = F_62 ( V_179 ) ) {
V_182 = F_31 ( F_32 ( V_179 ) ) + V_179 -> V_56 ;
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
for ( V_58 = V_200 ; V_58 < V_179 -> V_65 &&
V_180 < V_199 + V_42 ;
V_58 += sizeof( struct V_176 ) ) {
T_6 V_184 ;
unsigned int V_185 ;
if ( V_201 >= V_178 -> V_65 ) {
V_201 -= V_178 -> V_65 ;
F_33 ( V_181 - V_178 -> V_56 ) ;
V_178 = F_62 ( V_178 ) ;
if ( ! V_178 ) {
F_33 ( V_182 - V_179 -> V_56 ) ;
return 0 ;
}
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
}
V_177 = V_182 + V_58 ;
F_53 ( L_55
L_46 ,
( unsigned long long ) V_180 , V_177 -> V_186 ,
V_177 -> V_188 , F_67 ( V_177 -> V_187 ) ) ;
if ( V_177 -> V_188 == F_65 ( 0xffff ) ) {
V_201 += V_16 ;
goto V_202;
}
V_185 = F_43 ( V_16 , V_178 -> V_65 - V_201 ) ;
V_184 = F_63 ( V_181 + V_201 , V_185 ) ;
if ( V_185 < V_16 ) {
F_33 ( V_181 - V_178 -> V_56 ) ;
V_178 = F_62 ( V_178 ) ;
if ( ! V_178 ) {
F_33 ( V_182 - V_179 -> V_56 ) ;
return 0 ;
}
V_181 = F_31 ( F_32 ( V_178 ) ) + V_178 -> V_56 ;
V_201 = V_16 - V_185 ;
V_184 = F_64 ( V_184 , V_181 , V_201 ) ;
} else {
V_201 += V_16 ;
}
V_82 = F_68 ( V_2 , V_177 , V_184 , V_180 , V_189 ) ;
if ( V_82 ) {
F_33 ( V_181 - V_178 -> V_56 ) ;
F_33 ( V_182 - V_179 -> V_56 ) ;
V_2 -> V_203 = V_180 ;
return V_82 ;
}
V_202:
V_180 ++ ;
V_189 ++ ;
}
V_200 = 0 ;
F_33 ( V_181 - V_178 -> V_56 ) ;
F_33 ( V_182 - V_179 -> V_56 ) ;
}
return 0 ;
}
