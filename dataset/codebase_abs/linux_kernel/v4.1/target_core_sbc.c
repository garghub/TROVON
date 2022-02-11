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
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_12 ( struct V_1 * V_2 , T_2 V_36 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_36 ;
}
static inline T_2 F_13 ( unsigned char * V_6 )
{
return V_6 [ 4 ] ? : 256 ;
}
static inline T_2 F_14 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 7 ] << 8 ) + V_6 [ 8 ] ;
}
static inline T_2 F_15 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 6 ] << 24 ) + ( V_6 [ 7 ] << 16 ) + ( V_6 [ 8 ] << 8 ) + V_6 [ 9 ] ;
}
static inline T_2 F_16 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 10 ] << 24 ) + ( V_6 [ 11 ] << 16 ) +
( V_6 [ 12 ] << 8 ) + V_6 [ 13 ] ;
}
static inline T_2 F_17 ( unsigned char * V_6 )
{
return ( T_2 ) ( V_6 [ 28 ] << 24 ) + ( V_6 [ 29 ] << 16 ) +
( V_6 [ 30 ] << 8 ) + V_6 [ 31 ] ;
}
static inline T_2 F_18 ( unsigned char * V_6 )
{
return ( ( V_6 [ 1 ] & 0x1f ) << 16 ) | ( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
}
static inline T_2 F_19 ( unsigned char * V_6 )
{
return ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
}
static inline unsigned long long F_20 ( unsigned char * V_6 )
{
unsigned int V_37 , V_38 ;
V_37 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_38 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_38 ) | ( unsigned long long ) V_37 << 32 ;
}
static inline unsigned long long F_21 ( unsigned char * V_6 )
{
unsigned int V_37 , V_38 ;
V_37 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_38 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_38 ) | ( unsigned long long ) V_37 << 32 ;
}
static T_1
F_22 ( struct V_1 * V_2 , unsigned char * V_39 , struct V_40 * V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_42 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
unsigned int V_36 = F_7 ( V_2 ) ;
T_1 V_43 ;
if ( ( V_39 [ 0 ] & 0x04 ) || ( V_39 [ 0 ] & 0x02 ) ) {
F_23 ( L_1
L_2
L_3 ) ;
return V_44 ;
}
if ( V_36 > V_2 -> V_5 -> V_15 . V_45 ) {
F_24 ( L_4 ,
V_36 , V_2 -> V_5 -> V_15 . V_45 ) ;
return V_14 ;
}
if ( ( ( V_2 -> V_35 + V_36 ) < V_2 -> V_35 ) ||
( ( V_2 -> V_35 + V_36 ) > V_42 ) ) {
F_23 ( L_5 ,
( unsigned long long ) V_42 , V_2 -> V_35 , V_36 ) ;
return V_46 ;
}
if ( V_39 [ 0 ] & 0x10 ) {
F_24 ( L_6 ) ;
return V_14 ;
}
if ( V_39 [ 0 ] & 0x08 ) {
if ( ! V_41 -> V_47 )
return V_44 ;
if ( ! V_4 -> V_15 . V_31 ) {
F_23 ( L_7
L_8 ) ;
return V_44 ;
}
V_2 -> V_48 = V_41 -> V_47 ;
return 0 ;
}
if ( ! V_41 -> V_49 )
return V_44 ;
V_43 = F_25 ( V_4 , V_2 , & V_2 -> V_7 [ 0 ] , V_36 , true ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_48 = V_41 -> V_49 ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 , bool V_50 )
{
unsigned char * V_12 , * V_51 ;
struct V_52 * V_53 ;
unsigned int V_54 ;
T_1 V_43 = V_55 ;
int V_56 , V_57 ;
V_12 = F_27 ( V_2 -> V_17 , V_58 ) ;
if ( ! V_12 ) {
F_23 ( L_9 ) ;
return V_59 ;
}
F_28 ( V_2 -> V_60 ,
V_2 -> V_61 ,
V_12 ,
V_2 -> V_17 ) ;
V_54 = 0 ;
F_29 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_51 = F_30 ( F_31 ( V_53 ) ) ;
if ( ! V_51 ) {
V_43 = V_59 ;
goto V_62;
}
for ( V_56 = 0 ; V_56 < V_53 -> V_63 ; V_56 ++ )
* ( V_51 + V_53 -> V_54 + V_56 ) ^= * ( V_12 + V_54 + V_56 ) ;
V_54 += V_53 -> V_63 ;
F_32 ( V_51 ) ;
}
V_62:
F_33 ( V_12 ) ;
return V_43 ;
}
static T_1
F_34 ( struct V_1 * V_2 )
{
return V_2 -> V_64 ( V_2 , V_2 -> V_60 , V_2 -> V_61 ,
V_2 -> V_65 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , bool V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( & V_2 -> V_66 ) ;
if ( ( V_2 -> V_67 & V_68 ) && ! V_2 -> V_69 )
V_2 -> V_70 |= V_71 ;
F_37 ( & V_2 -> V_66 ) ;
F_38 ( & V_4 -> V_72 ) ;
return V_55 ;
}
static T_1 F_39 ( struct V_1 * V_2 , bool V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_73 = NULL , * V_53 ;
unsigned char * V_12 = NULL , * V_51 ;
struct V_74 V_75 ;
unsigned int V_54 = 0 , V_76 ;
unsigned int V_77 = V_2 -> V_78 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_79 = ( V_77 * V_16 ) ;
T_1 V_43 = V_55 ;
int V_80 , V_56 ;
if ( ! V_50 && ( ! V_2 -> V_60 || ! V_2 -> V_81 ) )
return V_55 ;
if ( ! V_2 -> V_17 )
goto V_62;
if ( V_2 -> V_69 ) {
F_23 ( L_10
L_11 , V_2 -> V_69 ) ;
goto V_62;
}
V_12 = F_40 ( V_2 -> V_17 , V_58 ) ;
if ( ! V_12 ) {
F_23 ( L_12 ) ;
V_43 = V_59 ;
goto V_62;
}
V_73 = F_27 ( sizeof( struct V_52 ) * V_2 -> V_61 ,
V_58 ) ;
if ( ! V_73 ) {
F_23 ( L_13 ) ;
V_43 = V_59 ;
goto V_62;
}
F_41 ( V_73 , V_2 -> V_61 ) ;
V_80 = F_28 ( V_2 -> V_60 , V_2 -> V_61 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_80 ) {
F_23 ( L_14 ) ;
V_43 = V_59 ;
goto V_62;
}
F_29 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_51 = ( unsigned char * ) F_30 ( F_31 ( V_53 ) ) ;
if ( ! V_51 ) {
V_43 = V_59 ;
goto V_62;
}
V_76 = F_42 ( V_53 -> V_63 , V_79 ) ;
if ( memcmp ( V_51 , V_12 + V_54 , V_76 ) ) {
F_24 ( L_15 ,
V_51 , V_12 + V_54 ) ;
F_32 ( V_51 ) ;
goto V_82;
}
F_32 ( V_51 ) ;
V_54 += V_76 ;
V_79 -= V_76 ;
if ( ! V_79 )
break;
}
V_56 = 0 ;
V_76 = V_2 -> V_78 * V_16 ;
F_43 ( & V_75 , V_2 -> V_60 , V_2 -> V_61 , V_83 ) ;
while ( V_76 ) {
F_44 ( & V_75 ) ;
if ( V_16 < V_84 ) {
F_45 ( & V_73 [ V_56 ] , V_75 . V_85 , V_16 ,
V_16 ) ;
} else {
F_44 ( & V_75 ) ;
F_45 ( & V_73 [ V_56 ] , V_75 . V_85 , V_16 ,
0 ) ;
}
V_76 -= V_16 ;
V_56 ++ ;
}
F_46 ( & V_75 ) ;
V_2 -> V_86 = V_2 -> V_60 ;
V_2 -> V_60 = V_73 ;
V_2 -> V_87 = V_2 -> V_61 ;
V_2 -> V_61 = 1 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = F_35 ;
V_2 -> V_48 = F_34 ;
F_36 ( & V_2 -> V_66 ) ;
V_2 -> V_91 = V_92 ;
V_2 -> V_67 |= V_93 | V_94 | V_68 ;
F_37 ( & V_2 -> V_66 ) ;
F_47 ( V_2 ) ;
F_33 ( V_12 ) ;
return V_43 ;
V_82:
F_24 ( L_16 ,
V_4 -> V_9 -> V_95 ) ;
V_43 = V_96 ;
V_62:
F_38 ( & V_4 -> V_72 ) ;
F_33 ( V_73 ) ;
F_33 ( V_12 ) ;
return V_43 ;
}
static T_1
F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_43 ;
int V_80 ;
V_80 = F_49 ( & V_4 -> V_72 ) ;
if ( V_80 != 0 ) {
V_2 -> V_90 = NULL ;
return V_97 ;
}
V_2 -> V_17 = V_2 -> V_78 * V_4 -> V_15 . V_16 ;
V_43 = V_2 -> V_64 ( V_2 , V_2 -> V_81 , V_2 -> V_98 ,
V_99 ) ;
if ( V_43 ) {
V_2 -> V_90 = NULL ;
F_38 ( & V_4 -> V_72 ) ;
return V_43 ;
}
return V_55 ;
}
static int
F_50 ( T_5 V_100 , bool V_101 , enum V_102 V_103 ,
bool V_104 , struct V_1 * V_2 )
{
if ( V_104 ) {
V_2 -> V_105 = V_101 ? V_106 :
V_100 ? V_25 :
V_107 ;
switch ( V_100 ) {
case 0x0 :
case 0x3 :
V_2 -> V_108 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_108 = V_109 ;
if ( V_103 == V_110 )
V_2 -> V_108 |= V_111 ;
break;
case 0x2 :
if ( V_103 == V_110 )
V_2 -> V_108 = V_111 ;
break;
case 0x4 :
V_2 -> V_108 = V_109 ;
break;
default:
F_23 ( L_17 , V_100 ) ;
return - V_112 ;
}
} else {
V_2 -> V_105 = V_101 ? V_113 :
V_100 ? V_24 :
V_114 ;
switch ( V_100 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_108 = V_109 ;
if ( V_103 == V_110 )
V_2 -> V_108 |= V_111 ;
break;
case 0x2 :
if ( V_103 == V_110 )
V_2 -> V_108 = V_111 ;
break;
case 0x3 :
V_2 -> V_108 = 0 ;
break;
case 0x4 :
V_2 -> V_108 = V_109 ;
break;
default:
F_23 ( L_17 , V_100 ) ;
return - V_112 ;
}
}
return 0 ;
}
static T_1
F_25 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_36 , bool V_104 )
{
T_5 V_100 = V_6 [ 1 ] >> 5 ;
int V_115 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_101 = false ;
if ( ! V_2 -> V_116 || ! V_2 -> V_117 ) {
if ( F_51 ( V_100 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_23 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_118 )
return V_55 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_119 :
V_2 -> V_120 = 0xffffffff ;
break;
case V_121 :
if ( V_100 )
return V_14 ;
V_2 -> V_120 = V_2 -> V_35 ;
break;
case V_110 :
V_2 -> V_120 = V_2 -> V_35 ;
break;
case V_122 :
V_101 = V_104 ?
! ! ( V_115 & ( V_25 | V_106 ) ) :
! ! ( V_115 & ( V_24 | V_113 ) ) ;
if ( V_101 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_100 )
return V_55 ;
default:
F_23 ( L_20
L_21 , V_6 [ 0 ] , V_100 ) ;
return V_14 ;
}
if ( F_50 ( V_100 , V_101 , V_22 , V_104 , V_2 ) )
return V_14 ;
V_2 -> V_103 = V_22 ;
V_2 -> V_123 = V_4 -> V_123 * V_36 ;
if ( V_100 )
V_2 -> V_17 = V_36 * V_4 -> V_15 . V_16 ;
F_52 ( L_22
L_23 ,
V_124 , V_2 -> V_103 , V_2 -> V_17 , V_2 -> V_123 ,
V_2 -> V_105 , V_2 -> V_108 ) ;
return V_55 ;
}
static int
F_53 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! V_4 -> V_15 . V_125 ) {
F_23 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_112 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! V_4 -> V_15 . V_126 || ! F_54 ( V_4 ) ) {
F_23 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_112 ;
}
V_2 -> V_70 |= V_127 ;
}
return 0 ;
}
T_1
F_55 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_128 ;
T_2 V_36 = 0 ;
T_1 V_43 ;
switch ( V_6 [ 0 ] ) {
case V_129 :
V_36 = F_13 ( V_6 ) ;
V_2 -> V_35 = F_18 ( V_6 ) ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_131 :
V_36 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , false ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_132 :
V_36 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , false ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_133 :
V_36 = F_16 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , false ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_134 :
V_36 = F_13 ( V_6 ) ;
V_2 -> V_35 = F_18 ( V_6 ) ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_135 :
case V_136 :
V_36 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , true ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_137 :
V_36 = F_15 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , true ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_138 :
V_36 = F_16 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_43 = F_25 ( V_4 , V_2 , V_6 , V_36 , true ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
break;
case V_139 :
if ( V_2 -> V_65 != V_140 ||
! ( V_2 -> V_70 & V_141 ) )
return V_14 ;
V_36 = F_14 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_35 = F_19 ( V_6 ) ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
V_2 -> V_90 = & F_26 ;
break;
case V_142 :
{
T_3 V_143 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_143 ) {
case V_144 :
V_36 = F_17 ( V_6 ) ;
if ( F_53 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_35 = F_21 ( V_6 ) ;
V_2 -> V_70 |= V_130 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_34 ;
V_2 -> V_90 = & F_26 ;
break;
case V_145 :
V_36 = F_17 ( V_6 ) ;
if ( ! V_36 ) {
F_23 ( L_28
L_29 ) ;
return V_14 ;
}
V_128 = F_12 ( V_2 , 1 ) ;
V_2 -> V_35 = F_56 ( & V_6 [ 12 ] ) ;
V_43 = F_22 ( V_2 , & V_6 [ 10 ] , V_41 ) ;
if ( V_43 )
return V_43 ;
break;
default:
F_23 ( L_30
L_31 , V_143 ) ;
return V_44 ;
}
break;
}
case V_146 :
V_36 = V_6 [ 13 ] ;
if ( V_36 > 1 ) {
F_23 ( L_32
L_33 , V_36 ) ;
return V_14 ;
}
V_128 = 2 * F_12 ( V_2 , V_36 ) ;
V_2 -> V_35 = F_56 ( & V_6 [ 2 ] ) ;
V_2 -> V_78 = V_36 ;
V_2 -> V_70 |= V_130 | V_147 ;
V_2 -> V_64 = V_41 -> V_64 ;
V_2 -> V_48 = F_48 ;
V_2 -> V_90 = F_39 ;
break;
case V_148 :
V_128 = V_149 ;
V_2 -> V_48 = F_1 ;
break;
case V_150 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_151 :
V_2 -> V_48 = F_6 ;
break;
case V_152 :
V_2 -> V_48 = V_153 ;
break;
default:
F_23 ( L_34 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_128 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_154 :
case V_155 :
if ( V_6 [ 0 ] == V_154 ) {
V_36 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
} else {
V_36 = F_16 ( V_6 ) ;
V_2 -> V_35 = F_20 ( V_6 ) ;
}
if ( V_41 -> V_156 ) {
V_2 -> V_48 = V_41 -> V_156 ;
goto V_157;
}
V_128 = 0 ;
V_2 -> V_48 = F_10 ;
break;
case V_158 :
if ( ! V_41 -> V_159 )
return V_44 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_23 ( L_35
L_36 ) ;
return V_44 ;
}
V_128 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_48 = V_41 -> V_159 ;
break;
case V_34 :
V_36 = F_16 ( V_6 ) ;
if ( ! V_36 ) {
F_23 ( L_37 ) ;
return V_14 ;
}
V_128 = F_12 ( V_2 , 1 ) ;
V_2 -> V_35 = F_56 ( & V_6 [ 2 ] ) ;
V_43 = F_22 ( V_2 , & V_6 [ 1 ] , V_41 ) ;
if ( V_43 )
return V_43 ;
break;
case V_33 :
V_36 = F_14 ( V_6 ) ;
if ( ! V_36 ) {
F_23 ( L_37 ) ;
return V_14 ;
}
V_128 = F_12 ( V_2 , 1 ) ;
V_2 -> V_35 = F_9 ( & V_6 [ 2 ] ) ;
V_43 = F_22 ( V_2 , & V_6 [ 1 ] , V_41 ) ;
if ( V_43 )
return V_43 ;
break;
case V_160 :
V_128 = 0 ;
V_36 = F_14 ( V_6 ) ;
V_2 -> V_35 = F_19 ( V_6 ) ;
V_2 -> V_48 = F_10 ;
goto V_157;
case V_161 :
case V_162 :
case V_163 :
V_128 = 0 ;
V_2 -> V_48 = F_10 ;
break;
default:
V_43 = F_57 ( V_2 , & V_128 ) ;
if ( V_43 )
return V_43 ;
}
if ( ! V_2 -> V_48 )
return V_44 ;
if ( V_2 -> V_70 & V_130 ) {
unsigned long long V_42 ;
V_157:
V_42 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_35 + V_36 ) < V_2 -> V_35 ) ||
( ( V_2 -> V_35 + V_36 ) > V_42 ) ) {
F_23 ( L_38
L_39 ,
V_42 , V_2 -> V_35 , V_36 ) ;
return V_46 ;
}
if ( ! ( V_2 -> V_70 & V_147 ) )
V_128 = F_12 ( V_2 , V_36 ) ;
}
return F_58 ( V_2 , V_128 ) ;
}
T_2 F_59 ( struct V_3 * V_4 )
{
return V_164 ;
}
T_1
F_60 ( struct V_1 * V_2 ,
T_1 (* F_61)( struct V_1 * , void * ,
T_4 , T_4 ) ,
void * V_165 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_166 = NULL ;
T_4 V_167 ;
int V_128 ;
T_2 V_168 ;
T_1 V_43 = 0 ;
int V_169 , V_170 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_11 ( V_2 , V_171 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_40 ,
V_2 -> V_17 ) ;
return V_172 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_97 ;
V_169 = F_8 ( & V_12 [ 0 ] ) ;
V_170 = F_8 ( & V_12 [ 2 ] ) ;
V_128 = V_2 -> V_17 - 8 ;
if ( V_170 > V_128 )
F_24 ( L_41 ,
V_2 -> V_17 , V_170 ) ;
else
V_128 = V_170 ;
if ( V_128 / 16 > V_4 -> V_15 . V_173 ) {
V_43 = V_174 ;
goto V_175;
}
V_166 = & V_12 [ 8 ] ;
F_52 ( L_42
L_43 , V_4 -> V_9 -> V_95 , V_169 , V_170 , V_128 , V_166 ) ;
while ( V_128 >= 16 ) {
V_167 = F_56 ( & V_166 [ 0 ] ) ;
V_168 = F_9 ( & V_166 [ 8 ] ) ;
F_52 ( L_44 ,
( unsigned long long ) V_167 , V_168 ) ;
if ( V_168 > V_4 -> V_15 . V_176 ) {
V_43 = V_174 ;
goto V_175;
}
if ( V_167 + V_168 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_43 = V_46 ;
goto V_175;
}
V_43 = F_61 ( V_2 , V_165 , V_167 , V_168 ) ;
if ( V_43 )
goto V_175;
V_166 += 16 ;
V_128 -= 16 ;
}
V_175:
F_4 ( V_2 ) ;
if ( ! V_43 )
F_11 ( V_2 , V_18 ) ;
return V_43 ;
}
void
F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_177 * V_178 ;
struct V_52 * V_179 , * V_180 = V_2 -> V_116 ;
T_4 V_181 = V_2 -> V_35 ;
void * V_182 , * V_183 ;
int V_56 , V_184 , V_54 = 0 ;
F_29 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_182 = F_30 ( F_31 ( V_179 ) ) + V_179 -> V_54 ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
for ( V_184 = 0 ; V_184 < V_179 -> V_63 ; V_184 += V_4 -> V_15 . V_16 ) {
if ( V_54 >= V_180 -> V_63 ) {
F_32 ( V_183 ) ;
V_180 = F_63 ( V_180 ) ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
V_54 = 0 ;
}
V_178 = V_183 + V_54 ;
V_178 -> V_185 = F_64 ( F_65 ( V_182 + V_184 ,
V_4 -> V_15 . V_16 ) ) ;
if ( V_2 -> V_103 == V_110 )
V_178 -> V_186 = F_66 ( V_181 & 0xffffffff ) ;
V_178 -> V_187 = 0 ;
F_52 ( L_45
L_46 ,
( V_2 -> V_65 == V_140 ) ?
L_47 : L_48 , ( unsigned long long ) V_181 ,
V_178 -> V_185 , V_178 -> V_187 ,
F_67 ( V_178 -> V_186 ) ) ;
V_181 ++ ;
V_54 += sizeof( struct V_177 ) ;
}
F_32 ( V_183 ) ;
F_32 ( V_182 ) ;
}
}
static T_1
F_68 ( struct V_1 * V_2 , struct V_177 * V_178 ,
const void * V_188 , T_4 V_181 , unsigned int V_189 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_16 = V_4 -> V_15 . V_16 ;
T_6 V_190 ;
if ( ! ( V_2 -> V_108 & V_109 ) )
goto V_191;
V_190 = F_64 ( F_65 ( V_188 , V_16 ) ) ;
if ( V_178 -> V_185 != V_190 ) {
F_23 ( L_49
L_50 , ( unsigned long long ) V_181 ,
F_69 ( V_178 -> V_185 ) , F_69 ( V_190 ) ) ;
return V_192 ;
}
V_191:
if ( ! ( V_2 -> V_108 & V_111 ) )
return 0 ;
if ( V_2 -> V_103 == V_110 &&
F_67 ( V_178 -> V_186 ) != ( V_181 & 0xffffffff ) ) {
F_23 ( L_51
L_52 , ( unsigned long long ) V_181 ,
F_67 ( V_178 -> V_186 ) , ( T_2 ) ( V_181 & 0xffffffff ) ) ;
return V_193 ;
}
if ( V_2 -> V_103 == V_121 &&
F_67 ( V_178 -> V_186 ) != V_189 ) {
F_23 ( L_53
L_54 , ( unsigned long long ) V_181 ,
F_67 ( V_178 -> V_186 ) , V_189 ) ;
return V_193 ;
}
return 0 ;
}
static void
F_70 ( struct V_1 * V_2 , unsigned int V_36 , bool V_194 ,
struct V_52 * V_53 , int V_195 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_180 ;
void * V_183 , * V_51 ;
unsigned int V_56 , V_76 , V_196 ;
unsigned int V_54 = V_195 ;
if ( ! V_53 )
return;
V_196 = V_36 * V_4 -> V_123 ;
F_29 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_197 , V_198 = 0 ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
V_197 = F_42 ( V_196 , V_180 -> V_63 ) ;
while ( V_197 ) {
V_76 = F_42 ( V_197 , V_53 -> V_63 - V_54 ) ;
V_51 = F_30 ( F_31 ( V_53 ) ) + V_53 -> V_54 + V_54 ;
if ( V_194 )
memcpy ( V_183 + V_198 , V_51 , V_76 ) ;
else
memcpy ( V_51 , V_183 + V_198 , V_76 ) ;
V_196 -= V_76 ;
V_54 += V_76 ;
V_198 += V_76 ;
V_197 -= V_76 ;
if ( V_54 >= V_53 -> V_63 ) {
V_53 = F_63 ( V_53 ) ;
V_54 = 0 ;
}
F_32 ( V_51 ) ;
}
F_32 ( V_183 ) ;
}
}
T_1
F_71 ( struct V_1 * V_2 , T_4 V_199 , unsigned int V_36 ,
unsigned int V_189 , struct V_52 * V_53 , int V_195 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_177 * V_178 ;
struct V_52 * V_179 , * V_180 = V_2 -> V_116 ;
T_4 V_181 = V_199 ;
void * V_182 , * V_183 ;
int V_56 , V_184 , V_54 = 0 ;
T_1 V_80 ;
F_29 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_182 = F_30 ( F_31 ( V_179 ) ) + V_179 -> V_54 ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
for ( V_184 = 0 ; V_184 < V_179 -> V_63 ; V_184 += V_4 -> V_15 . V_16 ) {
if ( V_54 >= V_180 -> V_63 ) {
F_32 ( V_183 ) ;
V_180 = F_63 ( V_180 ) ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
V_54 = 0 ;
}
V_178 = V_183 + V_54 ;
F_52 ( L_55
L_46 ,
( unsigned long long ) V_181 , V_178 -> V_185 ,
V_178 -> V_187 , F_67 ( V_178 -> V_186 ) ) ;
V_80 = F_68 ( V_2 , V_178 , V_182 + V_184 , V_181 ,
V_189 ) ;
if ( V_80 ) {
F_32 ( V_183 ) ;
F_32 ( V_182 ) ;
V_2 -> V_200 = V_181 ;
return V_80 ;
}
V_181 ++ ;
V_189 ++ ;
V_54 += sizeof( struct V_177 ) ;
}
F_32 ( V_183 ) ;
F_32 ( V_182 ) ;
}
if ( ! V_53 )
return 0 ;
F_70 ( V_2 , V_36 , false , V_53 , V_195 ) ;
return 0 ;
}
static T_1
F_72 ( struct V_1 * V_2 , T_4 V_199 , unsigned int V_36 ,
unsigned int V_189 , struct V_52 * V_53 , int V_195 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_177 * V_178 ;
struct V_52 * V_179 , * V_180 = V_53 ;
T_4 V_181 = V_199 ;
void * V_182 , * V_183 ;
int V_56 , V_184 , V_54 = V_195 ;
T_1 V_80 ;
F_29 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_182 = F_30 ( F_31 ( V_179 ) ) + V_179 -> V_54 ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_53 -> V_54 ;
for ( V_184 = 0 ; V_184 < V_179 -> V_63 ; V_184 += V_4 -> V_15 . V_16 ) {
if ( V_54 >= V_180 -> V_63 ) {
F_32 ( V_183 ) ;
V_180 = F_63 ( V_180 ) ;
V_183 = F_30 ( F_31 ( V_180 ) ) + V_180 -> V_54 ;
V_54 = 0 ;
}
V_178 = V_183 + V_54 ;
F_52 ( L_56
L_46 ,
( unsigned long long ) V_181 , V_178 -> V_185 ,
V_178 -> V_187 , F_67 ( V_178 -> V_186 ) ) ;
if ( V_178 -> V_187 == F_64 ( 0xffff ) ) {
V_181 ++ ;
V_54 += sizeof( struct V_177 ) ;
continue;
}
V_80 = F_68 ( V_2 , V_178 , V_182 + V_184 , V_181 ,
V_189 ) ;
if ( V_80 ) {
F_32 ( V_183 ) ;
F_32 ( V_182 ) ;
V_2 -> V_200 = V_181 ;
return V_80 ;
}
V_181 ++ ;
V_189 ++ ;
V_54 += sizeof( struct V_177 ) ;
}
F_32 ( V_183 ) ;
F_32 ( V_182 ) ;
}
return 0 ;
}
T_1
F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_36 = V_2 -> V_123 / V_4 -> V_123 ;
return F_72 ( V_2 , V_2 -> V_35 , V_36 , 0 ,
V_2 -> V_116 , 0 ) ;
}
T_1
F_74 ( struct V_1 * V_2 , T_4 V_199 , unsigned int V_36 ,
unsigned int V_189 , struct V_52 * V_53 , int V_195 )
{
T_1 V_80 ;
V_80 = F_72 ( V_2 , V_199 , V_36 , V_189 , V_53 , V_195 ) ;
if ( V_80 )
return V_80 ;
F_70 ( V_2 , V_36 , true , V_53 , V_195 ) ;
return 0 ;
}
