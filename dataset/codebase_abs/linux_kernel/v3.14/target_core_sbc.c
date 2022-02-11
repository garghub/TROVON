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
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
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
if ( V_4 -> V_15 . V_19 )
V_12 [ 12 ] = ( V_4 -> V_15 . V_19 - 1 ) << 1 | 0x1 ;
if ( V_4 -> V_9 -> V_20 )
V_12 [ 13 ] = V_4 -> V_9 -> V_20 ( V_4 ) & 0x0f ;
if ( V_4 -> V_9 -> V_21 ) {
T_3 V_22 = V_4 -> V_9 -> V_21 ( V_4 ) ;
V_12 [ 14 ] = ( V_22 >> 8 ) & 0x3f ;
V_12 [ 15 ] = V_22 & 0xff ;
}
if ( V_4 -> V_15 . V_23 || V_4 -> V_15 . V_24 )
V_12 [ 14 ] |= 0x80 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_3 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
T_4 F_7 ( struct V_1 * V_2 )
{
T_2 V_25 ;
if ( V_2 -> V_7 [ 0 ] == V_26 )
V_25 = F_8 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_27 )
V_25 = F_9 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_25 = F_9 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_25 )
return V_25 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_28 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_29 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_29 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_30 ;
T_2 V_29 ;
V_29 = V_2 -> V_17 / V_4 -> V_15 . V_16 ;
V_30 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_28 + V_29 > V_30 ) {
F_13 ( L_1 ,
V_2 -> V_28 , V_29 , V_30 ) ;
return - V_31 ;
}
return 0 ;
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
unsigned int V_32 , V_33 ;
V_32 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_33 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_33 ) | ( unsigned long long ) V_32 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_32 , V_33 ;
V_32 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_33 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_33 ) | ( unsigned long long ) V_32 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_34 , struct V_35 * V_36 )
{
unsigned int V_29 = F_7 ( V_2 ) ;
if ( ( V_34 [ 0 ] & 0x04 ) || ( V_34 [ 0 ] & 0x02 ) ) {
F_13 ( L_2
L_3
L_4 ) ;
return V_37 ;
}
if ( V_29 > V_2 -> V_5 -> V_15 . V_38 ) {
F_24 ( L_5 ,
V_29 , V_2 -> V_5 -> V_15 . V_38 ) ;
return V_14 ;
}
if ( V_34 [ 0 ] & 0x10 ) {
F_24 ( L_6 ) ;
return V_14 ;
}
if ( V_34 [ 0 ] & 0x08 ) {
if ( ! V_36 -> V_39 )
return V_37 ;
V_2 -> V_40 = V_36 -> V_39 ;
return 0 ;
}
if ( ! V_36 -> V_41 )
return V_37 ;
V_2 -> V_40 = V_36 -> V_41 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_42 ;
struct V_43 * V_44 ;
unsigned int V_45 ;
T_1 V_46 = V_47 ;
int V_48 , V_49 ;
V_12 = F_26 ( V_2 -> V_17 , V_50 ) ;
if ( ! V_12 ) {
F_13 ( L_7 ) ;
return V_51 ;
}
F_27 ( V_2 -> V_52 ,
V_2 -> V_53 ,
V_12 ,
V_2 -> V_17 ) ;
V_45 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_42 = F_29 ( F_30 ( V_44 ) ) ;
if ( ! V_42 ) {
V_46 = V_51 ;
goto V_54;
}
for ( V_48 = 0 ; V_48 < V_44 -> V_55 ; V_48 ++ )
* ( V_42 + V_44 -> V_45 + V_48 ) ^= * ( V_12 + V_45 + V_48 ) ;
V_45 += V_44 -> V_55 ;
F_31 ( V_42 ) ;
}
V_54:
F_32 ( V_12 ) ;
return V_46 ;
}
static T_1
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_56 ( V_2 , V_2 -> V_52 , V_2 -> V_53 ,
V_2 -> V_57 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_58 ) ;
if ( ( V_2 -> V_59 & V_60 ) && ! V_2 -> V_61 )
V_2 -> V_62 |= V_63 ;
F_36 ( & V_2 -> V_58 ) ;
F_37 ( & V_4 -> V_64 ) ;
return V_47 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_65 = NULL , * V_44 ;
unsigned char * V_12 = NULL , * V_42 ;
struct V_66 V_67 ;
unsigned int V_45 = 0 , V_68 ;
unsigned int V_69 = V_2 -> V_70 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_71 = ( V_69 * V_16 ) ;
T_1 V_46 = V_47 ;
int V_72 , V_48 ;
if ( ! V_2 -> V_52 || ! V_2 -> V_73 )
return V_47 ;
if ( V_2 -> V_61 ) {
F_13 ( L_8
L_9 , V_2 -> V_61 ) ;
goto V_54;
}
V_12 = F_39 ( V_2 -> V_17 , V_50 ) ;
if ( ! V_12 ) {
F_13 ( L_10 ) ;
V_46 = V_51 ;
goto V_54;
}
V_65 = F_39 ( sizeof( struct V_43 ) * V_2 -> V_53 ,
V_50 ) ;
if ( ! V_65 ) {
F_13 ( L_11 ) ;
V_46 = V_51 ;
goto V_54;
}
V_72 = F_27 ( V_2 -> V_52 , V_2 -> V_53 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_72 ) {
F_13 ( L_12 ) ;
V_46 = V_51 ;
goto V_54;
}
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_42 = ( unsigned char * ) F_29 ( F_30 ( V_44 ) ) ;
if ( ! V_42 ) {
V_46 = V_51 ;
goto V_54;
}
V_68 = F_40 ( V_44 -> V_55 , V_71 ) ;
if ( memcmp ( V_42 , V_12 + V_45 , V_68 ) ) {
F_24 ( L_13 ,
V_42 , V_12 + V_45 ) ;
F_31 ( V_42 ) ;
goto V_74;
}
F_31 ( V_42 ) ;
V_45 += V_68 ;
V_71 -= V_68 ;
if ( ! V_71 )
break;
}
V_48 = 0 ;
V_68 = V_2 -> V_70 * V_16 ;
F_41 ( & V_67 , V_2 -> V_52 , V_2 -> V_53 , V_75 ) ;
while ( V_68 ) {
F_42 ( & V_67 ) ;
if ( V_16 < V_76 ) {
F_43 ( & V_65 [ V_48 ] , V_67 . V_77 , V_16 ,
V_16 ) ;
} else {
F_42 ( & V_67 ) ;
F_43 ( & V_65 [ V_48 ] , V_67 . V_77 , V_16 ,
0 ) ;
}
V_68 -= V_16 ;
V_48 ++ ;
}
F_44 ( & V_67 ) ;
V_2 -> V_78 = V_2 -> V_52 ;
V_2 -> V_52 = V_65 ;
V_2 -> V_79 = V_2 -> V_53 ;
V_2 -> V_53 = 1 ;
V_2 -> V_80 = V_81 ;
V_2 -> V_82 = F_34 ;
V_2 -> V_40 = F_33 ;
F_35 ( & V_2 -> V_58 ) ;
V_2 -> V_83 = V_84 ;
V_2 -> V_59 |= V_85 | V_86 | V_60 ;
F_36 ( & V_2 -> V_58 ) ;
F_45 ( V_2 ) ;
F_32 ( V_12 ) ;
return V_46 ;
V_74:
F_24 ( L_14 ,
V_4 -> V_9 -> V_87 ) ;
V_46 = V_88 ;
V_54:
F_37 ( & V_4 -> V_64 ) ;
F_32 ( V_65 ) ;
F_32 ( V_12 ) ;
return V_46 ;
}
static T_1
F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_46 ;
int V_72 ;
V_72 = F_47 ( & V_4 -> V_64 ) ;
if ( ( V_72 != 0 ) || F_48 ( V_89 ) ) {
V_2 -> V_82 = NULL ;
return V_90 ;
}
V_2 -> V_17 = V_2 -> V_70 * V_4 -> V_15 . V_16 ;
V_46 = V_2 -> V_56 ( V_2 , V_2 -> V_73 , V_2 -> V_91 ,
V_92 ) ;
if ( V_46 ) {
V_2 -> V_82 = NULL ;
F_37 ( & V_4 -> V_64 ) ;
return V_46 ;
}
return V_47 ;
}
static bool
F_49 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_29 )
{
if ( ! V_2 -> V_93 || ! V_2 -> V_94 )
return true ;
switch ( V_4 -> V_15 . V_19 ) {
case V_95 :
if ( ! ( V_6 [ 1 ] & 0xe0 ) )
return true ;
V_2 -> V_96 = 0xffffffff ;
break;
case V_97 :
if ( V_6 [ 1 ] & 0xe0 )
return false ;
V_2 -> V_96 = V_2 -> V_28 ;
break;
case V_98 :
if ( ! ( V_6 [ 1 ] & 0xe0 ) )
return true ;
V_2 -> V_96 = V_2 -> V_28 ;
break;
case V_99 :
default:
return true ;
}
V_2 -> V_100 = V_4 -> V_15 . V_19 ;
V_2 -> V_101 = V_4 -> V_101 * V_29 ;
V_2 -> V_102 = V_103 ;
return true ;
}
T_1
F_50 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_104 ;
T_2 V_29 = 0 ;
T_1 V_46 ;
switch ( V_6 [ 0 ] ) {
case V_105 :
V_29 = F_14 ( V_6 ) ;
V_2 -> V_28 = F_19 ( V_6 ) ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_107 :
V_29 = F_15 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_108 :
V_29 = F_16 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_109 :
V_29 = F_17 ( V_6 ) ;
V_2 -> V_28 = F_21 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_110 :
V_29 = F_14 ( V_6 ) ;
V_2 -> V_28 = F_19 ( V_6 ) ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_111 :
case V_112 :
V_29 = F_15 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_62 |= V_113 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_114 :
V_29 = F_16 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_62 |= V_113 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_115 :
V_29 = F_17 ( V_6 ) ;
V_2 -> V_28 = F_21 ( V_6 ) ;
if ( ! F_49 ( V_4 , V_2 , V_6 , V_29 ) )
return V_37 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_62 |= V_113 ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
break;
case V_116 :
if ( V_2 -> V_57 != V_117 ||
! ( V_2 -> V_62 & V_118 ) )
return V_14 ;
V_29 = F_15 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
V_2 -> V_82 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_62 |= V_113 ;
break;
case V_119 :
{
T_3 V_120 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_120 ) {
case V_121 :
V_29 = F_18 ( V_6 ) ;
V_2 -> V_28 = F_22 ( V_6 ) ;
V_2 -> V_62 |= V_106 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_33 ;
V_2 -> V_82 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_62 |= V_113 ;
break;
case V_122 :
V_29 = F_18 ( V_6 ) ;
if ( ! V_29 ) {
F_13 ( L_15
L_16 ) ;
return V_14 ;
}
V_104 = F_11 ( V_2 , 1 ) ;
V_2 -> V_28 = F_51 ( & V_6 [ 12 ] ) ;
V_46 = F_23 ( V_2 , & V_6 [ 10 ] , V_36 ) ;
if ( V_46 )
return V_46 ;
break;
default:
F_13 ( L_17
L_18 , V_120 ) ;
return V_37 ;
}
break;
}
case V_123 :
V_29 = V_6 [ 13 ] ;
if ( V_29 > 1 ) {
F_13 ( L_19
L_20 , V_29 ) ;
return V_14 ;
}
V_104 = 2 * F_11 ( V_2 , V_29 ) ;
V_2 -> V_28 = F_51 ( & V_6 [ 2 ] ) ;
V_2 -> V_70 = V_29 ;
V_2 -> V_62 |= V_106 | V_124 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_40 = F_46 ;
V_2 -> V_82 = F_38 ;
break;
case V_125 :
V_104 = V_126 ;
V_2 -> V_40 = F_1 ;
break;
case V_127 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_128 :
V_2 -> V_40 = F_6 ;
break;
case V_129 :
V_2 -> V_40 = V_130 ;
break;
default:
F_13 ( L_21 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_104 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_131 :
case V_132 :
if ( ! V_36 -> V_133 ) {
V_104 = 0 ;
V_2 -> V_40 = F_10 ;
break;
}
if ( V_6 [ 0 ] == V_131 ) {
V_29 = F_15 ( V_6 ) ;
V_2 -> V_28 = F_20 ( V_6 ) ;
} else {
V_29 = F_17 ( V_6 ) ;
V_2 -> V_28 = F_21 ( V_6 ) ;
}
V_104 = F_11 ( V_2 , V_29 ) ;
if ( V_2 -> V_28 || V_29 ) {
if ( F_12 ( V_2 ) < 0 )
return V_134 ;
}
V_2 -> V_40 = V_36 -> V_133 ;
break;
case V_135 :
if ( ! V_36 -> V_136 )
return V_37 ;
V_104 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_40 = V_36 -> V_136 ;
break;
case V_27 :
V_29 = F_17 ( V_6 ) ;
if ( ! V_29 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_104 = F_11 ( V_2 , 1 ) ;
V_2 -> V_28 = F_51 ( & V_6 [ 2 ] ) ;
V_46 = F_23 ( V_2 , & V_6 [ 1 ] , V_36 ) ;
if ( V_46 )
return V_46 ;
break;
case V_26 :
V_29 = F_15 ( V_6 ) ;
if ( ! V_29 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_104 = F_11 ( V_2 , 1 ) ;
V_2 -> V_28 = F_9 ( & V_6 [ 2 ] ) ;
V_46 = F_23 ( V_2 , & V_6 [ 1 ] , V_36 ) ;
if ( V_46 )
return V_46 ;
break;
case V_137 :
V_104 = 0 ;
V_2 -> V_40 = F_10 ;
break;
case V_138 :
case V_139 :
case V_140 :
V_104 = 0 ;
V_2 -> V_40 = F_10 ;
break;
default:
V_46 = F_52 ( V_2 , & V_104 ) ;
if ( V_46 )
return V_46 ;
}
if ( ! ( V_2 -> V_62 & V_106 ) && ! V_2 -> V_40 )
return V_37 ;
if ( V_2 -> V_62 & V_106 ) {
unsigned long long V_30 ;
if ( V_29 > V_4 -> V_15 . V_141 ) {
F_53 ( V_142 L_23
L_24
L_25 , V_6 [ 0 ] , V_29 ,
V_4 -> V_15 . V_141 ) ;
return V_14 ;
}
if ( V_29 > V_4 -> V_15 . V_143 ) {
F_53 ( V_142 L_23
L_26
L_25 , V_6 [ 0 ] , V_29 ,
V_4 -> V_15 . V_143 ) ;
return V_14 ;
}
V_30 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_28 + V_29 > V_30 ) {
F_13 ( L_27
L_28 ,
V_30 , V_2 -> V_28 , V_29 ) ;
return V_134 ;
}
if ( ! ( V_2 -> V_62 & V_124 ) )
V_104 = F_11 ( V_2 , V_29 ) ;
}
return F_54 ( V_2 , V_104 ) ;
}
T_2 F_55 ( struct V_3 * V_4 )
{
return V_144 ;
}
T_1
F_56 ( struct V_1 * V_2 ,
T_1 (* F_57)( struct V_1 * , void * ,
T_4 , T_4 ) ,
void * V_145 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_146 = NULL ;
T_4 V_147 ;
int V_104 ;
T_2 V_148 ;
T_1 V_46 = 0 ;
int V_149 , V_150 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_5 ( V_2 , V_151 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_29 ,
V_2 -> V_17 ) ;
return V_152 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_90 ;
V_149 = F_8 ( & V_12 [ 0 ] ) ;
V_150 = F_8 ( & V_12 [ 2 ] ) ;
V_104 = V_2 -> V_17 - 8 ;
if ( V_150 > V_104 )
F_24 ( L_30 ,
V_2 -> V_17 , V_150 ) ;
else
V_104 = V_150 ;
if ( V_104 / 16 > V_4 -> V_15 . V_153 ) {
V_46 = V_154 ;
goto V_155;
}
V_146 = & V_12 [ 8 ] ;
F_58 ( L_31
L_32 , V_4 -> V_9 -> V_87 , V_149 , V_150 , V_104 , V_146 ) ;
while ( V_104 >= 16 ) {
V_147 = F_51 ( & V_146 [ 0 ] ) ;
V_148 = F_9 ( & V_146 [ 8 ] ) ;
F_58 ( L_33 ,
( unsigned long long ) V_147 , V_148 ) ;
if ( V_148 > V_4 -> V_15 . V_156 ) {
V_46 = V_154 ;
goto V_155;
}
if ( V_147 + V_148 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_46 = V_134 ;
goto V_155;
}
V_46 = F_57 ( V_2 , V_145 , V_147 , V_148 ) ;
if ( V_46 )
goto V_155;
V_146 += 16 ;
V_104 -= 16 ;
}
V_155:
F_4 ( V_2 ) ;
if ( ! V_46 )
F_5 ( V_2 , V_18 ) ;
return V_46 ;
}
static T_1
F_59 ( struct V_3 * V_4 , struct V_157 * V_158 ,
const void * V_159 , T_4 V_160 , unsigned int V_161 )
{
int V_16 = V_4 -> V_15 . V_16 ;
T_5 V_162 ;
V_162 = F_60 ( F_61 ( V_159 , V_16 ) ) ;
if ( V_158 -> V_163 != V_162 ) {
F_13 ( L_34
L_35 , ( unsigned long long ) V_160 ,
F_62 ( V_158 -> V_163 ) , F_62 ( V_162 ) ) ;
return V_164 ;
}
if ( V_4 -> V_15 . V_19 == V_98 &&
F_63 ( V_158 -> V_165 ) != ( V_160 & 0xffffffff ) ) {
F_13 ( L_36
L_37 , ( unsigned long long ) V_160 ,
F_63 ( V_158 -> V_165 ) , ( T_2 ) ( V_160 & 0xffffffff ) ) ;
return V_166 ;
}
if ( V_4 -> V_15 . V_19 == V_97 &&
F_63 ( V_158 -> V_165 ) != V_161 ) {
F_13 ( L_38
L_39 , ( unsigned long long ) V_160 ,
F_63 ( V_158 -> V_165 ) , V_161 ) ;
return V_166 ;
}
return 0 ;
}
static void
F_64 ( struct V_1 * V_2 , unsigned int V_29 , bool V_167 ,
struct V_43 * V_44 , int V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_169 ;
void * V_170 , * V_42 ;
unsigned int V_48 , V_68 , V_171 ;
unsigned int V_45 = V_168 ;
V_171 = V_29 * V_4 -> V_101 ;
F_28 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_172 , V_173 = 0 ;
V_170 = F_29 ( F_30 ( V_169 ) ) + V_169 -> V_45 ;
V_172 = F_40 ( V_171 , V_169 -> V_55 ) ;
while ( V_172 ) {
V_68 = F_40 ( V_172 , V_44 -> V_55 - V_45 ) ;
V_42 = F_29 ( F_30 ( V_44 ) ) + V_44 -> V_45 + V_45 ;
if ( V_167 )
memcpy ( V_170 + V_173 , V_42 , V_68 ) ;
else
memcpy ( V_42 , V_170 + V_173 , V_68 ) ;
V_171 -= V_68 ;
V_45 += V_68 ;
V_173 += V_68 ;
V_172 -= V_68 ;
if ( V_45 >= V_44 -> V_55 ) {
V_44 = F_65 ( V_44 ) ;
V_45 = 0 ;
}
F_31 ( V_42 ) ;
}
F_31 ( V_170 ) ;
}
}
T_1
F_66 ( struct V_1 * V_2 , T_4 V_174 , unsigned int V_29 ,
unsigned int V_161 , struct V_43 * V_44 , int V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_157 * V_158 ;
struct V_43 * V_175 , * V_169 = V_2 -> V_93 ;
T_4 V_160 = V_174 ;
void * V_176 , * V_170 ;
int V_48 , V_177 , V_45 = 0 ;
T_1 V_72 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_176 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_45 ;
V_170 = F_29 ( F_30 ( V_169 ) ) + V_169 -> V_45 ;
for ( V_177 = 0 ; V_177 < V_175 -> V_55 ; V_177 += V_4 -> V_15 . V_16 ) {
if ( V_45 >= V_169 -> V_55 ) {
F_31 ( V_170 ) ;
V_169 = F_65 ( V_169 ) ;
V_170 = F_29 ( F_30 ( V_169 ) ) + V_169 -> V_45 ;
V_45 = 0 ;
}
V_158 = V_170 + V_45 ;
F_58 ( L_40
L_41 ,
( unsigned long long ) V_160 , V_158 -> V_163 ,
V_158 -> V_178 , F_63 ( V_158 -> V_165 ) ) ;
V_72 = F_59 ( V_4 , V_158 , V_176 + V_177 , V_160 ,
V_161 ) ;
if ( V_72 ) {
F_31 ( V_170 ) ;
F_31 ( V_176 ) ;
V_2 -> V_179 = V_160 ;
return V_72 ;
}
V_160 ++ ;
V_161 ++ ;
V_45 += sizeof( struct V_157 ) ;
}
F_31 ( V_170 ) ;
F_31 ( V_176 ) ;
}
F_64 ( V_2 , V_29 , false , V_44 , V_168 ) ;
return 0 ;
}
T_1
F_67 ( struct V_1 * V_2 , T_4 V_174 , unsigned int V_29 ,
unsigned int V_161 , struct V_43 * V_44 , int V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_157 * V_158 ;
struct V_43 * V_175 , * V_169 = V_44 ;
T_4 V_160 = V_174 ;
void * V_176 , * V_170 ;
int V_48 , V_177 , V_45 = V_168 ;
T_1 V_72 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_176 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_45 ;
V_170 = F_29 ( F_30 ( V_169 ) ) + V_44 -> V_45 ;
for ( V_177 = 0 ; V_177 < V_175 -> V_55 ; V_177 += V_4 -> V_15 . V_16 ) {
if ( V_45 >= V_169 -> V_55 ) {
F_31 ( V_170 ) ;
V_169 = F_65 ( V_169 ) ;
V_170 = F_29 ( F_30 ( V_169 ) ) + V_169 -> V_45 ;
V_45 = 0 ;
}
V_158 = V_170 + V_45 ;
F_58 ( L_42
L_41 ,
( unsigned long long ) V_160 , V_158 -> V_163 ,
V_158 -> V_178 , F_63 ( V_158 -> V_165 ) ) ;
if ( V_158 -> V_178 == F_60 ( 0xffff ) ) {
V_160 ++ ;
V_45 += sizeof( struct V_157 ) ;
continue;
}
V_72 = F_59 ( V_4 , V_158 , V_176 + V_177 , V_160 ,
V_161 ) ;
if ( V_72 ) {
F_31 ( V_170 ) ;
F_31 ( V_176 ) ;
V_2 -> V_179 = V_160 ;
return V_72 ;
}
V_160 ++ ;
V_161 ++ ;
V_45 += sizeof( struct V_157 ) ;
}
F_31 ( V_170 ) ;
F_31 ( V_176 ) ;
}
F_64 ( V_2 , V_29 , true , V_44 , V_168 ) ;
return 0 ;
}
