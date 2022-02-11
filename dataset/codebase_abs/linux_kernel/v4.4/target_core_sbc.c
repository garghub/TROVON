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
static T_1 F_28 ( struct V_1 * V_2 , bool V_53 ,
int * V_54 )
{
unsigned char * V_12 , * V_55 ;
struct V_56 * V_57 ;
unsigned int V_58 ;
T_1 V_41 = V_59 ;
int V_60 , V_61 ;
V_12 = F_29 ( V_2 -> V_17 , V_62 ) ;
if ( ! V_12 ) {
F_25 ( L_9 ) ;
return V_63 ;
}
F_30 ( V_2 -> V_64 ,
V_2 -> V_65 ,
V_12 ,
V_2 -> V_17 ) ;
V_58 = 0 ;
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_55 = F_32 ( F_33 ( V_57 ) ) ;
if ( ! V_55 ) {
V_41 = V_63 ;
goto V_66;
}
for ( V_60 = 0 ; V_60 < V_57 -> V_67 ; V_60 ++ )
* ( V_55 + V_57 -> V_58 + V_60 ) ^= * ( V_12 + V_58 + V_60 ) ;
V_58 += V_57 -> V_67 ;
F_34 ( V_55 ) ;
}
V_66:
F_35 ( V_12 ) ;
return V_41 ;
}
static T_1
F_36 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
return V_38 -> V_68 ( V_2 , V_2 -> V_64 , V_2 -> V_65 ,
V_2 -> V_69 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 , bool V_53 ,
int * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_38 ( & V_2 -> V_70 ) ;
if ( ( V_2 -> V_71 & V_72 ) && ! V_2 -> V_73 ) {
V_2 -> V_74 |= V_75 ;
* V_54 = 1 ;
}
F_39 ( & V_2 -> V_70 ) ;
F_40 ( & V_4 -> V_76 ) ;
return V_59 ;
}
static T_1 F_41 ( struct V_1 * V_2 , bool V_53 ,
int * V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_56 * V_77 = NULL , * V_57 ;
unsigned char * V_12 = NULL , * V_55 ;
struct V_78 V_79 ;
unsigned int V_58 = 0 , V_80 ;
unsigned int V_81 = V_2 -> V_82 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_83 = ( V_81 * V_16 ) ;
T_1 V_41 = V_59 ;
int V_84 , V_60 ;
if ( ! V_53 && ( ! V_2 -> V_64 || ! V_2 -> V_85 ) )
return V_59 ;
if ( ! V_2 -> V_17 )
goto V_66;
if ( V_2 -> V_73 ) {
F_25 ( L_10
L_11 , V_2 -> V_73 ) ;
goto V_66;
}
V_12 = F_42 ( V_2 -> V_17 , V_62 ) ;
if ( ! V_12 ) {
F_25 ( L_12 ) ;
V_41 = V_63 ;
goto V_66;
}
V_77 = F_29 ( sizeof( struct V_56 ) * V_2 -> V_65 ,
V_62 ) ;
if ( ! V_77 ) {
F_25 ( L_13 ) ;
V_41 = V_63 ;
goto V_66;
}
F_43 ( V_77 , V_2 -> V_65 ) ;
V_84 = F_30 ( V_2 -> V_64 , V_2 -> V_65 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_84 ) {
F_25 ( L_14 ) ;
V_41 = V_63 ;
goto V_66;
}
F_31 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_55 = ( unsigned char * ) F_32 ( F_33 ( V_57 ) ) ;
if ( ! V_55 ) {
V_41 = V_63 ;
goto V_66;
}
V_80 = F_44 ( V_57 -> V_67 , V_83 ) ;
if ( memcmp ( V_55 , V_12 + V_58 , V_80 ) ) {
F_26 ( L_15 ,
V_55 , V_12 + V_58 ) ;
F_34 ( V_55 ) ;
goto V_86;
}
F_34 ( V_55 ) ;
V_58 += V_80 ;
V_83 -= V_80 ;
if ( ! V_83 )
break;
}
V_60 = 0 ;
V_80 = V_2 -> V_82 * V_16 ;
F_45 ( & V_79 , V_2 -> V_64 , V_2 -> V_65 , V_87 ) ;
while ( V_80 ) {
F_46 ( & V_79 ) ;
if ( V_16 < V_88 ) {
F_47 ( & V_77 [ V_60 ] , V_79 . V_89 , V_16 ,
V_79 . V_90 . V_57 -> V_58 + V_16 ) ;
} else {
F_46 ( & V_79 ) ;
F_47 ( & V_77 [ V_60 ] , V_79 . V_89 , V_16 ,
V_79 . V_90 . V_57 -> V_58 ) ;
}
V_80 -= V_16 ;
V_60 ++ ;
}
F_48 ( & V_79 ) ;
V_2 -> V_91 = V_2 -> V_64 ;
V_2 -> V_64 = V_77 ;
V_2 -> V_92 = V_2 -> V_65 ;
V_2 -> V_65 = 1 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = F_37 ;
V_2 -> V_51 = F_36 ;
F_38 ( & V_2 -> V_70 ) ;
V_2 -> V_96 = V_97 ;
V_2 -> V_71 |= V_98 | V_99 | V_72 ;
F_39 ( & V_2 -> V_70 ) ;
F_49 ( V_2 ) ;
F_35 ( V_12 ) ;
return V_41 ;
V_86:
F_26 ( L_16 ,
V_4 -> V_9 -> V_100 ) ;
V_41 = V_101 ;
V_66:
F_40 ( & V_4 -> V_76 ) ;
F_35 ( V_77 ) ;
F_35 ( V_12 ) ;
return V_41 ;
}
static T_1
F_50 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
int V_84 ;
V_84 = F_51 ( & V_4 -> V_76 ) ;
if ( V_84 != 0 ) {
V_2 -> V_95 = NULL ;
return V_102 ;
}
V_2 -> V_17 = V_2 -> V_82 * V_4 -> V_15 . V_16 ;
V_41 = V_38 -> V_68 ( V_2 , V_2 -> V_85 , V_2 -> V_103 ,
V_104 ) ;
if ( V_41 ) {
V_2 -> V_95 = NULL ;
F_40 ( & V_4 -> V_76 ) ;
return V_41 ;
}
return V_59 ;
}
static int
F_52 ( T_5 V_105 , bool V_106 , enum V_107 V_108 ,
bool V_109 , struct V_1 * V_2 )
{
if ( V_109 ) {
V_2 -> V_110 = V_106 ? V_111 :
V_105 ? V_25 :
V_112 ;
switch ( V_105 ) {
case 0x0 :
case 0x3 :
V_2 -> V_113 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_113 = V_114 ;
if ( V_108 == V_115 )
V_2 -> V_113 |= V_116 ;
break;
case 0x2 :
if ( V_108 == V_115 )
V_2 -> V_113 = V_116 ;
break;
case 0x4 :
V_2 -> V_113 = V_114 ;
break;
default:
F_25 ( L_17 , V_105 ) ;
return - V_117 ;
}
} else {
V_2 -> V_110 = V_106 ? V_118 :
V_105 ? V_24 :
V_119 ;
switch ( V_105 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_113 = V_114 ;
if ( V_108 == V_115 )
V_2 -> V_113 |= V_116 ;
break;
case 0x2 :
if ( V_108 == V_115 )
V_2 -> V_113 = V_116 ;
break;
case 0x3 :
V_2 -> V_113 = 0 ;
break;
case 0x4 :
V_2 -> V_113 = V_114 ;
break;
default:
F_25 ( L_17 , V_105 ) ;
return - V_117 ;
}
}
return 0 ;
}
static T_1
F_27 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_43 , bool V_109 )
{
T_5 V_105 = V_6 [ 1 ] >> 5 ;
int V_120 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_106 = false ;
if ( ! V_2 -> V_121 || ! V_2 -> V_122 ) {
if ( F_53 ( V_105 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_25 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_123 )
return V_59 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_124 :
V_2 -> V_125 = 0xffffffff ;
break;
case V_126 :
if ( V_105 )
return V_14 ;
V_2 -> V_125 = V_2 -> V_36 ;
break;
case V_115 :
V_2 -> V_125 = V_2 -> V_36 ;
break;
case V_127 :
V_106 = V_109 ?
! ! ( V_120 & ( V_25 | V_111 ) ) :
! ! ( V_120 & ( V_24 | V_118 ) ) ;
if ( V_106 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_105 )
return V_59 ;
default:
F_25 ( L_20
L_21 , V_6 [ 0 ] , V_105 ) ;
return V_14 ;
}
if ( F_52 ( V_105 , V_106 , V_22 , V_109 , V_2 ) )
return V_14 ;
V_2 -> V_108 = V_22 ;
V_2 -> V_128 = V_4 -> V_128 * V_43 ;
if ( V_105 )
V_2 -> V_17 = V_43 * V_4 -> V_15 . V_16 ;
F_54 ( L_22
L_23 ,
V_129 , V_2 -> V_108 , V_2 -> V_17 , V_2 -> V_128 ,
V_2 -> V_110 , V_2 -> V_113 ) ;
return V_59 ;
}
static int
F_55 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! F_56 ( V_4 ) ) {
F_25 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_117 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! F_56 ( V_4 ) ) {
F_25 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_117 ;
}
V_2 -> V_74 |= V_130 ;
}
return 0 ;
}
T_1
F_57 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_131 ;
T_2 V_43 = 0 ;
T_1 V_41 ;
V_2 -> V_39 = V_38 ;
switch ( V_6 [ 0 ] ) {
case V_132 :
V_43 = F_15 ( V_6 ) ;
V_2 -> V_36 = F_20 ( V_6 ) ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_134 :
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_135 :
V_43 = F_17 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_136 :
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , false ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_137 :
V_43 = F_15 ( V_6 ) ;
V_2 -> V_36 = F_20 ( V_6 ) ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_138 :
case V_139 :
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_140 :
V_43 = F_17 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_141 :
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_41 = F_27 ( V_4 , V_2 , V_6 , V_43 , true ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
break;
case V_142 :
if ( V_2 -> V_69 != V_143 ||
! ( V_2 -> V_74 & V_144 ) )
return V_14 ;
V_43 = F_16 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_36 = F_21 ( V_6 ) ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
V_2 -> V_95 = & F_28 ;
break;
case V_145 :
{
T_3 V_146 = F_10 ( & V_6 [ 8 ] ) ;
switch ( V_146 ) {
case V_147 :
V_43 = F_19 ( V_6 ) ;
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_36 = F_23 ( V_6 ) ;
V_2 -> V_74 |= V_133 ;
V_2 -> V_51 = F_36 ;
V_2 -> V_95 = & F_28 ;
break;
case V_148 :
V_43 = F_19 ( V_6 ) ;
if ( ! V_43 ) {
F_25 ( L_28
L_29 ) ;
return V_14 ;
}
V_131 = F_14 ( V_2 , 1 ) ;
V_2 -> V_36 = F_58 ( & V_6 [ 12 ] ) ;
V_41 = F_24 ( V_2 , & V_6 [ 10 ] , V_38 ) ;
if ( V_41 )
return V_41 ;
break;
default:
F_25 ( L_30
L_31 , V_146 ) ;
return V_48 ;
}
break;
}
case V_149 :
V_43 = V_6 [ 13 ] ;
if ( V_43 > 1 ) {
F_25 ( L_32
L_33 , V_43 ) ;
return V_14 ;
}
if ( F_55 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_131 = 2 * F_14 ( V_2 , V_43 ) ;
V_2 -> V_36 = F_58 ( & V_6 [ 2 ] ) ;
V_2 -> V_82 = V_43 ;
V_2 -> V_74 |= V_133 | V_150 ;
V_2 -> V_51 = F_50 ;
V_2 -> V_95 = F_41 ;
break;
case V_151 :
V_131 = V_152 ;
V_2 -> V_51 = F_1 ;
break;
case V_153 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_154 :
V_2 -> V_51 = F_6 ;
break;
case V_155 :
V_2 -> V_51 = V_156 ;
break;
default:
F_25 ( L_34 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_131 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_157 :
case V_158 :
if ( V_6 [ 0 ] == V_157 ) {
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
} else {
V_43 = F_18 ( V_6 ) ;
V_2 -> V_36 = F_22 ( V_6 ) ;
}
if ( V_38 -> V_159 ) {
V_2 -> V_51 = V_38 -> V_159 ;
goto V_160;
}
V_131 = 0 ;
V_2 -> V_51 = F_13 ;
break;
case V_161 :
if ( ! V_38 -> V_42 )
return V_48 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_25 ( L_35
L_36 ) ;
return V_48 ;
}
V_131 = F_10 ( & V_6 [ 7 ] ) ;
V_2 -> V_51 = V_162 ;
break;
case V_35 :
V_43 = F_18 ( V_6 ) ;
if ( ! V_43 ) {
F_25 ( L_37 ) ;
return V_14 ;
}
V_131 = F_14 ( V_2 , 1 ) ;
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
V_131 = F_14 ( V_2 , 1 ) ;
V_2 -> V_36 = F_11 ( & V_6 [ 2 ] ) ;
V_41 = F_24 ( V_2 , & V_6 [ 1 ] , V_38 ) ;
if ( V_41 )
return V_41 ;
break;
case V_163 :
V_131 = 0 ;
V_43 = F_16 ( V_6 ) ;
V_2 -> V_36 = F_21 ( V_6 ) ;
V_2 -> V_51 = F_13 ;
goto V_160;
case V_164 :
case V_165 :
case V_166 :
V_131 = 0 ;
V_2 -> V_51 = F_13 ;
break;
case V_167 :
V_131 = 0 ;
V_2 -> V_51 = F_7 ;
break;
default:
V_41 = F_59 ( V_2 , & V_131 ) ;
if ( V_41 )
return V_41 ;
}
if ( ! V_2 -> V_51 )
return V_48 ;
if ( V_2 -> V_74 & V_133 ) {
unsigned long long V_47 ;
V_160:
V_47 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_36 + V_43 ) < V_2 -> V_36 ) ||
( ( V_2 -> V_36 + V_43 ) > V_47 ) ) {
F_25 ( L_38
L_39 ,
V_47 , V_2 -> V_36 , V_43 ) ;
return V_50 ;
}
if ( ! ( V_2 -> V_74 & V_150 ) )
V_131 = F_14 ( V_2 , V_43 ) ;
}
return F_60 ( V_2 , V_131 ) ;
}
T_2 F_61 ( struct V_3 * V_4 )
{
return V_168 ;
}
static T_1
V_162 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_169 = NULL ;
T_4 V_170 ;
int V_131 ;
T_2 V_171 ;
T_1 V_41 = 0 ;
int V_172 , V_173 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_8 ( V_2 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_26 ( L_40 ,
V_2 -> V_17 ) ;
return V_174 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_102 ;
V_172 = F_10 ( & V_12 [ 0 ] ) ;
V_173 = F_10 ( & V_12 [ 2 ] ) ;
V_131 = V_2 -> V_17 - 8 ;
if ( V_173 > V_131 )
F_26 ( L_41 ,
V_2 -> V_17 , V_173 ) ;
else
V_131 = V_173 ;
if ( V_131 / 16 > V_4 -> V_15 . V_175 ) {
V_41 = V_176 ;
goto V_177;
}
V_169 = & V_12 [ 8 ] ;
F_54 ( L_42
L_43 , V_4 -> V_9 -> V_100 , V_172 , V_173 , V_131 , V_169 ) ;
while ( V_131 >= 16 ) {
V_170 = F_58 ( & V_169 [ 0 ] ) ;
V_171 = F_11 ( & V_169 [ 8 ] ) ;
F_54 ( L_44 ,
( unsigned long long ) V_170 , V_171 ) ;
if ( V_171 > V_4 -> V_15 . V_178 ) {
V_41 = V_176 ;
goto V_177;
}
if ( V_170 + V_171 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_41 = V_50 ;
goto V_177;
}
V_41 = V_38 -> V_42 ( V_2 , V_170 , V_171 ) ;
if ( V_41 )
goto V_177;
V_169 += 16 ;
V_131 -= 16 ;
}
V_177:
F_4 ( V_2 ) ;
if ( ! V_41 )
F_8 ( V_2 , V_18 ) ;
return V_41 ;
}
void
F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_179 * V_180 ;
struct V_56 * V_181 = V_2 -> V_64 , * V_182 ;
T_4 V_183 = V_2 -> V_36 ;
void * V_184 , * V_185 ;
int V_60 , V_186 , V_58 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
V_185 = F_32 ( F_33 ( V_182 ) ) + V_182 -> V_58 ;
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
for ( V_186 = 0 ; V_186 < V_182 -> V_67 ;
V_186 += sizeof( * V_180 ) ) {
T_6 V_187 ;
unsigned int V_188 ;
if ( V_58 >= V_181 -> V_67 ) {
V_58 -= V_181 -> V_67 ;
F_34 ( V_184 - V_181 -> V_58 ) ;
V_181 = F_63 ( V_181 ) ;
if ( ! V_181 ) {
F_34 ( V_185 - V_182 -> V_58 ) ;
return;
}
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
}
V_180 = V_185 + V_186 ;
V_188 = F_44 ( V_16 , V_181 -> V_67 - V_58 ) ;
V_187 = F_64 ( V_184 + V_58 , V_188 ) ;
if ( V_188 < V_16 ) {
F_34 ( V_184 - V_181 -> V_58 ) ;
V_181 = F_63 ( V_181 ) ;
if ( ! V_181 ) {
F_34 ( V_185 - V_182 -> V_58 ) ;
return;
}
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
V_58 = V_16 - V_188 ;
V_187 = F_65 ( V_187 , V_184 , V_58 ) ;
} else {
V_58 += V_16 ;
}
V_180 -> V_189 = F_66 ( V_187 ) ;
if ( V_2 -> V_108 == V_115 )
V_180 -> V_190 = F_67 ( V_183 & 0xffffffff ) ;
V_180 -> V_191 = 0 ;
F_54 ( L_45
L_46 ,
( V_2 -> V_69 == V_143 ) ?
L_47 : L_48 , ( unsigned long long ) V_183 ,
V_180 -> V_189 , V_180 -> V_191 ,
F_68 ( V_180 -> V_190 ) ) ;
V_183 ++ ;
}
F_34 ( V_184 - V_181 -> V_58 ) ;
F_34 ( V_185 - V_182 -> V_58 ) ;
}
}
static T_1
F_69 ( struct V_1 * V_2 , struct V_179 * V_180 ,
T_6 V_187 , T_4 V_183 , unsigned int V_192 )
{
T_7 V_193 ;
if ( ! ( V_2 -> V_113 & V_114 ) )
goto V_194;
V_193 = F_66 ( V_187 ) ;
if ( V_180 -> V_189 != V_193 ) {
F_25 ( L_49
L_50 , ( unsigned long long ) V_183 ,
F_70 ( V_180 -> V_189 ) , F_70 ( V_193 ) ) ;
return V_195 ;
}
V_194:
if ( ! ( V_2 -> V_113 & V_116 ) )
return 0 ;
if ( V_2 -> V_108 == V_115 &&
F_68 ( V_180 -> V_190 ) != ( V_183 & 0xffffffff ) ) {
F_25 ( L_51
L_52 , ( unsigned long long ) V_183 ,
F_68 ( V_180 -> V_190 ) , ( T_2 ) ( V_183 & 0xffffffff ) ) ;
return V_196 ;
}
if ( V_2 -> V_108 == V_126 &&
F_68 ( V_180 -> V_190 ) != V_192 ) {
F_25 ( L_53
L_54 , ( unsigned long long ) V_183 ,
F_68 ( V_180 -> V_190 ) , V_192 ) ;
return V_196 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , unsigned int V_43 , bool V_197 ,
struct V_56 * V_57 , int V_198 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_56 * V_182 ;
void * V_185 , * V_55 ;
unsigned int V_60 , V_80 , V_199 ;
unsigned int V_58 = V_198 ;
if ( ! V_57 )
return;
V_199 = V_43 * V_4 -> V_128 ;
F_31 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_200 , V_201 = 0 ;
V_185 = F_32 ( F_33 ( V_182 ) ) + V_182 -> V_58 ;
V_200 = F_44 ( V_199 , V_182 -> V_67 ) ;
while ( V_200 ) {
V_80 = F_44 ( V_200 , V_57 -> V_67 - V_58 ) ;
V_55 = F_32 ( F_33 ( V_57 ) ) + V_57 -> V_58 + V_58 ;
if ( V_197 )
memcpy ( V_185 + V_201 , V_55 , V_80 ) ;
else
memcpy ( V_55 , V_185 + V_201 , V_80 ) ;
V_199 -= V_80 ;
V_58 += V_80 ;
V_201 += V_80 ;
V_200 -= V_80 ;
F_34 ( V_55 - V_57 -> V_58 - V_58 ) ;
if ( V_58 >= V_57 -> V_67 ) {
V_57 = F_63 ( V_57 ) ;
V_58 = 0 ;
}
}
F_34 ( V_185 - V_182 -> V_58 ) ;
}
}
T_1
F_72 ( struct V_1 * V_2 , T_4 V_202 , unsigned int V_43 ,
unsigned int V_192 , struct V_56 * V_182 , int V_203 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_179 * V_180 ;
struct V_56 * V_181 = V_2 -> V_64 ;
T_4 V_183 = V_202 ;
void * V_184 , * V_185 ;
int V_60 ;
T_1 V_84 ;
int V_204 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
for (; V_182 && V_183 < V_202 + V_43 ; V_182 = F_63 ( V_182 ) ) {
V_185 = F_32 ( F_33 ( V_182 ) ) + V_182 -> V_58 ;
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
for ( V_60 = V_203 ; V_60 < V_182 -> V_67 &&
V_183 < V_202 + V_43 ;
V_60 += sizeof( * V_180 ) ) {
T_6 V_187 ;
unsigned int V_188 ;
if ( V_204 >= V_181 -> V_67 ) {
V_204 -= V_181 -> V_67 ;
F_34 ( V_184 - V_181 -> V_58 ) ;
V_181 = F_63 ( V_181 ) ;
if ( ! V_181 ) {
F_34 ( V_185 - V_182 -> V_58 ) ;
return 0 ;
}
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
}
V_180 = V_185 + V_60 ;
F_54 ( L_55
L_46 ,
( unsigned long long ) V_183 , V_180 -> V_189 ,
V_180 -> V_191 , F_68 ( V_180 -> V_190 ) ) ;
if ( V_180 -> V_191 == F_66 ( 0xffff ) ) {
V_204 += V_16 ;
goto V_205;
}
V_188 = F_44 ( V_16 , V_181 -> V_67 - V_204 ) ;
V_187 = F_64 ( V_184 + V_204 , V_188 ) ;
if ( V_188 < V_16 ) {
F_34 ( V_184 - V_181 -> V_58 ) ;
V_181 = F_63 ( V_181 ) ;
if ( ! V_181 ) {
F_34 ( V_185 - V_182 -> V_58 ) ;
return 0 ;
}
V_184 = F_32 ( F_33 ( V_181 ) ) + V_181 -> V_58 ;
V_204 = V_16 - V_188 ;
V_187 = F_65 ( V_187 , V_184 , V_204 ) ;
} else {
V_204 += V_16 ;
}
V_84 = F_69 ( V_2 , V_180 , V_187 , V_183 , V_192 ) ;
if ( V_84 ) {
F_34 ( V_184 - V_181 -> V_58 ) ;
F_34 ( V_185 - V_182 -> V_58 ) ;
V_2 -> V_206 = V_183 ;
return V_84 ;
}
V_205:
V_183 ++ ;
V_192 ++ ;
}
V_203 = 0 ;
F_34 ( V_184 - V_181 -> V_58 ) ;
F_34 ( V_185 - V_182 -> V_58 ) ;
}
return 0 ;
}
