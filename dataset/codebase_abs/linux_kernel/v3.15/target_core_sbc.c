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
struct V_19 * V_20 = V_2 -> V_21 ;
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
if ( V_20 -> V_22 & ( V_23 | V_24 ) ) {
if ( V_4 -> V_15 . V_25 )
V_12 [ 12 ] = ( V_4 -> V_15 . V_25 - 1 ) << 1 | 0x1 ;
}
if ( V_4 -> V_9 -> V_26 )
V_12 [ 13 ] = V_4 -> V_9 -> V_26 ( V_4 ) & 0x0f ;
if ( V_4 -> V_9 -> V_27 ) {
T_3 V_28 = V_4 -> V_9 -> V_27 ( V_4 ) ;
V_12 [ 14 ] = ( V_28 >> 8 ) & 0x3f ;
V_12 [ 15 ] = V_28 & 0xff ;
}
if ( V_4 -> V_15 . V_29 || V_4 -> V_15 . V_30 )
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
T_2 V_31 ;
if ( V_2 -> V_7 [ 0 ] == V_32 )
V_31 = F_8 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_33 )
V_31 = F_9 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_31 = F_9 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_31 )
return V_31 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_34 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_35 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_35 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_36 ;
T_2 V_35 ;
V_35 = V_2 -> V_17 / V_4 -> V_15 . V_16 ;
V_36 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_34 + V_35 > V_36 ) {
F_13 ( L_1 ,
V_2 -> V_34 , V_35 , V_36 ) ;
return - V_37 ;
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
unsigned int V_38 , V_39 ;
V_38 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_39 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_39 ) | ( unsigned long long ) V_38 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_38 , V_39 ;
V_38 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_39 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_39 ) | ( unsigned long long ) V_38 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_40 , struct V_41 * V_42 )
{
unsigned int V_35 = F_7 ( V_2 ) ;
if ( ( V_40 [ 0 ] & 0x04 ) || ( V_40 [ 0 ] & 0x02 ) ) {
F_13 ( L_2
L_3
L_4 ) ;
return V_43 ;
}
if ( V_35 > V_2 -> V_5 -> V_15 . V_44 ) {
F_24 ( L_5 ,
V_35 , V_2 -> V_5 -> V_15 . V_44 ) ;
return V_14 ;
}
if ( V_40 [ 0 ] & 0x10 ) {
F_24 ( L_6 ) ;
return V_14 ;
}
if ( V_40 [ 0 ] & 0x08 ) {
if ( ! V_42 -> V_45 )
return V_43 ;
V_2 -> V_46 = V_42 -> V_45 ;
return 0 ;
}
if ( ! V_42 -> V_47 )
return V_43 ;
V_2 -> V_46 = V_42 -> V_47 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_48 ;
struct V_49 * V_50 ;
unsigned int V_51 ;
T_1 V_52 = V_53 ;
int V_54 , V_55 ;
V_12 = F_26 ( V_2 -> V_17 , V_56 ) ;
if ( ! V_12 ) {
F_13 ( L_7 ) ;
return V_57 ;
}
F_27 ( V_2 -> V_58 ,
V_2 -> V_59 ,
V_12 ,
V_2 -> V_17 ) ;
V_51 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_48 = F_29 ( F_30 ( V_50 ) ) ;
if ( ! V_48 ) {
V_52 = V_57 ;
goto V_60;
}
for ( V_54 = 0 ; V_54 < V_50 -> V_61 ; V_54 ++ )
* ( V_48 + V_50 -> V_51 + V_54 ) ^= * ( V_12 + V_51 + V_54 ) ;
V_51 += V_50 -> V_61 ;
F_31 ( V_48 ) ;
}
V_60:
F_32 ( V_12 ) ;
return V_52 ;
}
static T_1
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_62 ( V_2 , V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_63 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_64 ) ;
if ( ( V_2 -> V_65 & V_66 ) && ! V_2 -> V_67 )
V_2 -> V_68 |= V_69 ;
F_36 ( & V_2 -> V_64 ) ;
F_37 ( & V_4 -> V_70 ) ;
return V_53 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_49 * V_71 = NULL , * V_50 ;
unsigned char * V_12 = NULL , * V_48 ;
struct V_72 V_73 ;
unsigned int V_51 = 0 , V_74 ;
unsigned int V_75 = V_2 -> V_76 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_77 = ( V_75 * V_16 ) ;
T_1 V_52 = V_53 ;
int V_78 , V_54 ;
if ( ! V_2 -> V_58 || ! V_2 -> V_79 )
return V_53 ;
if ( V_2 -> V_67 ) {
F_13 ( L_8
L_9 , V_2 -> V_67 ) ;
goto V_60;
}
V_12 = F_39 ( V_2 -> V_17 , V_56 ) ;
if ( ! V_12 ) {
F_13 ( L_10 ) ;
V_52 = V_57 ;
goto V_60;
}
V_71 = F_26 ( sizeof( struct V_49 ) * V_2 -> V_59 ,
V_56 ) ;
if ( ! V_71 ) {
F_13 ( L_11 ) ;
V_52 = V_57 ;
goto V_60;
}
F_40 ( V_71 , V_2 -> V_59 ) ;
V_78 = F_27 ( V_2 -> V_58 , V_2 -> V_59 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_78 ) {
F_13 ( L_12 ) ;
V_52 = V_57 ;
goto V_60;
}
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_48 = ( unsigned char * ) F_29 ( F_30 ( V_50 ) ) ;
if ( ! V_48 ) {
V_52 = V_57 ;
goto V_60;
}
V_74 = F_41 ( V_50 -> V_61 , V_77 ) ;
if ( memcmp ( V_48 , V_12 + V_51 , V_74 ) ) {
F_24 ( L_13 ,
V_48 , V_12 + V_51 ) ;
F_31 ( V_48 ) ;
goto V_80;
}
F_31 ( V_48 ) ;
V_51 += V_74 ;
V_77 -= V_74 ;
if ( ! V_77 )
break;
}
V_54 = 0 ;
V_74 = V_2 -> V_76 * V_16 ;
F_42 ( & V_73 , V_2 -> V_58 , V_2 -> V_59 , V_81 ) ;
while ( V_74 ) {
F_43 ( & V_73 ) ;
if ( V_16 < V_82 ) {
F_44 ( & V_71 [ V_54 ] , V_73 . V_83 , V_16 ,
V_16 ) ;
} else {
F_43 ( & V_73 ) ;
F_44 ( & V_71 [ V_54 ] , V_73 . V_83 , V_16 ,
0 ) ;
}
V_74 -= V_16 ;
V_54 ++ ;
}
F_45 ( & V_73 ) ;
V_2 -> V_84 = V_2 -> V_58 ;
V_2 -> V_58 = V_71 ;
V_2 -> V_85 = V_2 -> V_59 ;
V_2 -> V_59 = 1 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = F_34 ;
V_2 -> V_46 = F_33 ;
F_35 ( & V_2 -> V_64 ) ;
V_2 -> V_89 = V_90 ;
V_2 -> V_65 |= V_91 | V_92 | V_66 ;
F_36 ( & V_2 -> V_64 ) ;
F_46 ( V_2 ) ;
F_32 ( V_12 ) ;
return V_52 ;
V_80:
F_24 ( L_14 ,
V_4 -> V_9 -> V_93 ) ;
V_52 = V_94 ;
V_60:
F_37 ( & V_4 -> V_70 ) ;
F_32 ( V_71 ) ;
F_32 ( V_12 ) ;
return V_52 ;
}
static T_1
F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_52 ;
int V_78 ;
V_78 = F_48 ( & V_4 -> V_70 ) ;
if ( ( V_78 != 0 ) || F_49 ( V_95 ) ) {
V_2 -> V_88 = NULL ;
return V_96 ;
}
V_2 -> V_17 = V_2 -> V_76 * V_4 -> V_15 . V_16 ;
V_52 = V_2 -> V_62 ( V_2 , V_2 -> V_79 , V_2 -> V_97 ,
V_98 ) ;
if ( V_52 ) {
V_2 -> V_88 = NULL ;
F_37 ( & V_4 -> V_70 ) ;
return V_52 ;
}
return V_53 ;
}
static int
F_50 ( T_5 V_99 , enum V_100 V_101 ,
bool V_102 , struct V_1 * V_2 )
{
if ( V_102 ) {
V_2 -> V_103 = V_99 ? V_24 :
V_104 ;
switch ( V_99 ) {
case 0x0 :
case 0x3 :
V_2 -> V_105 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_105 = V_106 ;
if ( V_101 == V_107 )
V_2 -> V_105 |= V_108 ;
break;
case 0x2 :
if ( V_101 == V_107 )
V_2 -> V_105 = V_108 ;
break;
case 0x4 :
V_2 -> V_105 = V_106 ;
break;
default:
F_13 ( L_15 , V_99 ) ;
return - V_37 ;
}
} else {
V_2 -> V_103 = V_99 ? V_23 :
V_109 ;
switch ( V_99 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_105 = V_106 ;
if ( V_101 == V_107 )
V_2 -> V_105 |= V_108 ;
break;
case 0x2 :
if ( V_101 == V_107 )
V_2 -> V_105 = V_108 ;
break;
case 0x3 :
V_2 -> V_105 = 0 ;
break;
case 0x4 :
V_2 -> V_105 = V_106 ;
break;
default:
F_13 ( L_15 , V_99 ) ;
return - V_37 ;
}
}
return 0 ;
}
static bool
F_51 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_35 , bool V_102 )
{
T_5 V_99 = V_6 [ 1 ] >> 5 ;
if ( ( ! V_2 -> V_110 || ! V_2 -> V_111 ) && V_2 -> V_112 )
return true ;
switch ( V_4 -> V_15 . V_25 ) {
case V_113 :
V_2 -> V_114 = 0xffffffff ;
break;
case V_115 :
if ( V_99 )
return false ;
V_2 -> V_114 = V_2 -> V_34 ;
break;
case V_107 :
V_2 -> V_114 = V_2 -> V_34 ;
break;
case V_116 :
default:
return true ;
}
if ( F_50 ( V_99 , V_4 -> V_15 . V_25 ,
V_102 , V_2 ) )
return false ;
V_2 -> V_101 = V_4 -> V_15 . V_25 ;
V_2 -> V_117 = V_4 -> V_117 * V_35 ;
F_52 ( L_16 ,
V_118 , V_2 -> V_101 , V_2 -> V_117 ,
V_2 -> V_103 , V_2 -> V_105 ) ;
return true ;
}
T_1
F_53 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_119 ;
T_2 V_35 = 0 ;
T_1 V_52 ;
switch ( V_6 [ 0 ] ) {
case V_120 :
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_122 :
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_43 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_123 :
V_35 = F_16 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_43 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_124 :
V_35 = F_17 ( V_6 ) ;
V_2 -> V_34 = F_21 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_43 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_125 :
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_126 :
case V_127 :
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_43 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_68 |= V_128 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_129 :
V_35 = F_16 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_43 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_68 |= V_128 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_130 :
V_35 = F_17 ( V_6 ) ;
V_2 -> V_34 = F_21 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_43 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_68 |= V_128 ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
break;
case V_131 :
if ( V_2 -> V_63 != V_132 ||
! ( V_2 -> V_68 & V_133 ) )
return V_14 ;
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
V_2 -> V_88 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_68 |= V_128 ;
break;
case V_134 :
{
T_3 V_135 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_135 ) {
case V_136 :
V_35 = F_18 ( V_6 ) ;
V_2 -> V_34 = F_22 ( V_6 ) ;
V_2 -> V_68 |= V_121 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_33 ;
V_2 -> V_88 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_68 |= V_128 ;
break;
case V_137 :
V_35 = F_18 ( V_6 ) ;
if ( ! V_35 ) {
F_13 ( L_17
L_18 ) ;
return V_14 ;
}
V_119 = F_11 ( V_2 , 1 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 12 ] ) ;
V_52 = F_23 ( V_2 , & V_6 [ 10 ] , V_42 ) ;
if ( V_52 )
return V_52 ;
break;
default:
F_13 ( L_19
L_20 , V_135 ) ;
return V_43 ;
}
break;
}
case V_138 :
V_35 = V_6 [ 13 ] ;
if ( V_35 > 1 ) {
F_13 ( L_21
L_22 , V_35 ) ;
return V_14 ;
}
V_119 = 2 * F_11 ( V_2 , V_35 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 2 ] ) ;
V_2 -> V_76 = V_35 ;
V_2 -> V_68 |= V_121 | V_139 ;
V_2 -> V_62 = V_42 -> V_62 ;
V_2 -> V_46 = F_47 ;
V_2 -> V_88 = F_38 ;
break;
case V_140 :
V_119 = V_141 ;
V_2 -> V_46 = F_1 ;
break;
case V_142 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_143 :
V_2 -> V_46 = F_6 ;
break;
case V_144 :
V_2 -> V_46 = V_145 ;
break;
default:
F_13 ( L_23 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_119 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_146 :
case V_147 :
if ( ! V_42 -> V_148 ) {
V_119 = 0 ;
V_2 -> V_46 = F_10 ;
break;
}
if ( V_6 [ 0 ] == V_146 ) {
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
} else {
V_35 = F_17 ( V_6 ) ;
V_2 -> V_34 = F_21 ( V_6 ) ;
}
V_119 = F_11 ( V_2 , V_35 ) ;
if ( V_2 -> V_34 || V_35 ) {
if ( F_12 ( V_2 ) < 0 )
return V_149 ;
}
V_2 -> V_46 = V_42 -> V_148 ;
break;
case V_150 :
if ( ! V_42 -> V_151 )
return V_43 ;
V_119 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_46 = V_42 -> V_151 ;
break;
case V_33 :
V_35 = F_17 ( V_6 ) ;
if ( ! V_35 ) {
F_13 ( L_24 ) ;
return V_14 ;
}
V_119 = F_11 ( V_2 , 1 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 2 ] ) ;
V_52 = F_23 ( V_2 , & V_6 [ 1 ] , V_42 ) ;
if ( V_52 )
return V_52 ;
break;
case V_32 :
V_35 = F_15 ( V_6 ) ;
if ( ! V_35 ) {
F_13 ( L_24 ) ;
return V_14 ;
}
V_119 = F_11 ( V_2 , 1 ) ;
V_2 -> V_34 = F_9 ( & V_6 [ 2 ] ) ;
V_52 = F_23 ( V_2 , & V_6 [ 1 ] , V_42 ) ;
if ( V_52 )
return V_52 ;
break;
case V_152 :
V_119 = 0 ;
V_2 -> V_46 = F_10 ;
break;
case V_153 :
case V_154 :
case V_155 :
V_119 = 0 ;
V_2 -> V_46 = F_10 ;
break;
default:
V_52 = F_55 ( V_2 , & V_119 ) ;
if ( V_52 )
return V_52 ;
}
if ( ! ( V_2 -> V_68 & V_121 ) && ! V_2 -> V_46 )
return V_43 ;
if ( V_2 -> V_68 & V_121 ) {
unsigned long long V_36 ;
if ( V_35 > V_4 -> V_15 . V_156 ) {
F_56 ( V_157 L_25
L_26
L_27 , V_6 [ 0 ] , V_35 ,
V_4 -> V_15 . V_156 ) ;
return V_14 ;
}
if ( V_35 > V_4 -> V_15 . V_158 ) {
F_56 ( V_157 L_25
L_28
L_27 , V_6 [ 0 ] , V_35 ,
V_4 -> V_15 . V_158 ) ;
return V_14 ;
}
V_36 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_34 + V_35 > V_36 ) {
F_13 ( L_29
L_30 ,
V_36 , V_2 -> V_34 , V_35 ) ;
return V_149 ;
}
if ( ! ( V_2 -> V_68 & V_139 ) )
V_119 = F_11 ( V_2 , V_35 ) ;
}
return F_57 ( V_2 , V_119 ) ;
}
T_2 F_58 ( struct V_3 * V_4 )
{
return V_159 ;
}
T_1
F_59 ( struct V_1 * V_2 ,
T_1 (* F_60)( struct V_1 * , void * ,
T_4 , T_4 ) ,
void * V_160 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_161 = NULL ;
T_4 V_162 ;
int V_119 ;
T_2 V_163 ;
T_1 V_52 = 0 ;
int V_164 , V_165 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_5 ( V_2 , V_166 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_31 ,
V_2 -> V_17 ) ;
return V_167 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_96 ;
V_164 = F_8 ( & V_12 [ 0 ] ) ;
V_165 = F_8 ( & V_12 [ 2 ] ) ;
V_119 = V_2 -> V_17 - 8 ;
if ( V_165 > V_119 )
F_24 ( L_32 ,
V_2 -> V_17 , V_165 ) ;
else
V_119 = V_165 ;
if ( V_119 / 16 > V_4 -> V_15 . V_168 ) {
V_52 = V_169 ;
goto V_170;
}
V_161 = & V_12 [ 8 ] ;
F_52 ( L_33
L_34 , V_4 -> V_9 -> V_93 , V_164 , V_165 , V_119 , V_161 ) ;
while ( V_119 >= 16 ) {
V_162 = F_54 ( & V_161 [ 0 ] ) ;
V_163 = F_9 ( & V_161 [ 8 ] ) ;
F_52 ( L_35 ,
( unsigned long long ) V_162 , V_163 ) ;
if ( V_163 > V_4 -> V_15 . V_171 ) {
V_52 = V_169 ;
goto V_170;
}
if ( V_162 + V_163 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_52 = V_149 ;
goto V_170;
}
V_52 = F_60 ( V_2 , V_160 , V_162 , V_163 ) ;
if ( V_52 )
goto V_170;
V_161 += 16 ;
V_119 -= 16 ;
}
V_170:
F_4 ( V_2 ) ;
if ( ! V_52 )
F_5 ( V_2 , V_18 ) ;
return V_52 ;
}
void
F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_172 * V_173 ;
struct V_49 * V_174 , * V_175 = V_2 -> V_110 ;
T_4 V_176 = V_2 -> V_34 ;
void * V_177 , * V_178 ;
int V_54 , V_179 , V_51 = 0 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_177 = F_29 ( F_30 ( V_174 ) ) + V_174 -> V_51 ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
for ( V_179 = 0 ; V_179 < V_174 -> V_61 ; V_179 += V_4 -> V_15 . V_16 ) {
if ( V_51 >= V_175 -> V_61 ) {
F_31 ( V_178 ) ;
V_175 = F_62 ( V_175 ) ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
V_51 = 0 ;
}
V_173 = V_178 + V_51 ;
V_173 -> V_180 = F_63 ( F_64 ( V_177 + V_179 ,
V_4 -> V_15 . V_16 ) ) ;
if ( V_4 -> V_15 . V_25 == V_107 )
V_173 -> V_181 = F_65 ( V_176 & 0xffffffff ) ;
V_173 -> V_182 = 0 ;
F_52 ( L_36
L_37 ,
( unsigned long long ) V_176 , V_173 -> V_180 ,
V_173 -> V_182 , F_66 ( V_173 -> V_181 ) ) ;
V_176 ++ ;
V_51 += sizeof( struct V_172 ) ;
}
F_31 ( V_178 ) ;
F_31 ( V_177 ) ;
}
}
static T_1
F_67 ( struct V_3 * V_4 , struct V_172 * V_173 ,
const void * V_183 , T_4 V_176 , unsigned int V_184 )
{
int V_16 = V_4 -> V_15 . V_16 ;
T_6 V_185 ;
V_185 = F_63 ( F_64 ( V_183 , V_16 ) ) ;
if ( V_173 -> V_180 != V_185 ) {
F_13 ( L_38
L_39 , ( unsigned long long ) V_176 ,
F_68 ( V_173 -> V_180 ) , F_68 ( V_185 ) ) ;
return V_186 ;
}
if ( V_4 -> V_15 . V_25 == V_107 &&
F_66 ( V_173 -> V_181 ) != ( V_176 & 0xffffffff ) ) {
F_13 ( L_40
L_41 , ( unsigned long long ) V_176 ,
F_66 ( V_173 -> V_181 ) , ( T_2 ) ( V_176 & 0xffffffff ) ) ;
return V_187 ;
}
if ( V_4 -> V_15 . V_25 == V_115 &&
F_66 ( V_173 -> V_181 ) != V_184 ) {
F_13 ( L_42
L_43 , ( unsigned long long ) V_176 ,
F_66 ( V_173 -> V_181 ) , V_184 ) ;
return V_187 ;
}
return 0 ;
}
static void
F_69 ( struct V_1 * V_2 , unsigned int V_35 , bool V_188 ,
struct V_49 * V_50 , int V_189 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_49 * V_175 ;
void * V_178 , * V_48 ;
unsigned int V_54 , V_74 , V_190 ;
unsigned int V_51 = V_189 ;
V_190 = V_35 * V_4 -> V_117 ;
F_28 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_191 , V_192 = 0 ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
V_191 = F_41 ( V_190 , V_175 -> V_61 ) ;
while ( V_191 ) {
V_74 = F_41 ( V_191 , V_50 -> V_61 - V_51 ) ;
V_48 = F_29 ( F_30 ( V_50 ) ) + V_50 -> V_51 + V_51 ;
if ( V_188 )
memcpy ( V_178 + V_192 , V_48 , V_74 ) ;
else
memcpy ( V_48 , V_178 + V_192 , V_74 ) ;
V_190 -= V_74 ;
V_51 += V_74 ;
V_192 += V_74 ;
V_191 -= V_74 ;
if ( V_51 >= V_50 -> V_61 ) {
V_50 = F_62 ( V_50 ) ;
V_51 = 0 ;
}
F_31 ( V_48 ) ;
}
F_31 ( V_178 ) ;
}
}
T_1
F_70 ( struct V_1 * V_2 , T_4 V_193 , unsigned int V_35 ,
unsigned int V_184 , struct V_49 * V_50 , int V_189 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_172 * V_173 ;
struct V_49 * V_174 , * V_175 = V_2 -> V_110 ;
T_4 V_176 = V_193 ;
void * V_177 , * V_178 ;
int V_54 , V_179 , V_51 = 0 ;
T_1 V_78 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_177 = F_29 ( F_30 ( V_174 ) ) + V_174 -> V_51 ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
for ( V_179 = 0 ; V_179 < V_174 -> V_61 ; V_179 += V_4 -> V_15 . V_16 ) {
if ( V_51 >= V_175 -> V_61 ) {
F_31 ( V_178 ) ;
V_175 = F_62 ( V_175 ) ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
V_51 = 0 ;
}
V_173 = V_178 + V_51 ;
F_52 ( L_44
L_37 ,
( unsigned long long ) V_176 , V_173 -> V_180 ,
V_173 -> V_182 , F_66 ( V_173 -> V_181 ) ) ;
V_78 = F_67 ( V_4 , V_173 , V_177 + V_179 , V_176 ,
V_184 ) ;
if ( V_78 ) {
F_31 ( V_178 ) ;
F_31 ( V_177 ) ;
V_2 -> V_194 = V_176 ;
return V_78 ;
}
V_176 ++ ;
V_184 ++ ;
V_51 += sizeof( struct V_172 ) ;
}
F_31 ( V_178 ) ;
F_31 ( V_177 ) ;
}
F_69 ( V_2 , V_35 , false , V_50 , V_189 ) ;
return 0 ;
}
static T_1
F_71 ( struct V_1 * V_2 , T_4 V_193 , unsigned int V_35 ,
unsigned int V_184 , struct V_49 * V_50 , int V_189 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_172 * V_173 ;
struct V_49 * V_174 , * V_175 = V_50 ;
T_4 V_176 = V_193 ;
void * V_177 , * V_178 ;
int V_54 , V_179 , V_51 = V_189 ;
T_1 V_78 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_177 = F_29 ( F_30 ( V_174 ) ) + V_174 -> V_51 ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_50 -> V_51 ;
for ( V_179 = 0 ; V_179 < V_174 -> V_61 ; V_179 += V_4 -> V_15 . V_16 ) {
if ( V_51 >= V_175 -> V_61 ) {
F_31 ( V_178 ) ;
V_175 = F_62 ( V_175 ) ;
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_51 ;
V_51 = 0 ;
}
V_173 = V_178 + V_51 ;
F_52 ( L_45
L_37 ,
( unsigned long long ) V_176 , V_173 -> V_180 ,
V_173 -> V_182 , F_66 ( V_173 -> V_181 ) ) ;
if ( V_173 -> V_182 == F_63 ( 0xffff ) ) {
V_176 ++ ;
V_51 += sizeof( struct V_172 ) ;
continue;
}
V_78 = F_67 ( V_4 , V_173 , V_177 + V_179 , V_176 ,
V_184 ) ;
if ( V_78 ) {
F_31 ( V_178 ) ;
F_31 ( V_177 ) ;
V_2 -> V_194 = V_176 ;
return V_78 ;
}
V_176 ++ ;
V_184 ++ ;
V_51 += sizeof( struct V_172 ) ;
}
F_31 ( V_178 ) ;
F_31 ( V_177 ) ;
}
return 0 ;
}
T_1
F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_35 = V_2 -> V_117 / V_4 -> V_117 ;
return F_71 ( V_2 , V_2 -> V_34 , V_35 , 0 ,
V_2 -> V_110 , 0 ) ;
}
T_1
F_73 ( struct V_1 * V_2 , T_4 V_193 , unsigned int V_35 ,
unsigned int V_184 , struct V_49 * V_50 , int V_189 )
{
T_1 V_78 ;
V_78 = F_71 ( V_2 , V_193 , V_35 , V_184 , V_50 , V_189 ) ;
if ( V_78 )
return V_78 ;
F_69 ( V_2 , V_35 , true , V_50 , V_189 ) ;
return 0 ;
}
