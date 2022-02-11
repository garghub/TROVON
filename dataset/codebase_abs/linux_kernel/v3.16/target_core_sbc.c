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
F_5 ( V_2 , V_18 , 32 ) ;
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
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_12 ( struct V_1 * V_2 , T_2 V_35 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_35 ;
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
unsigned int V_36 , V_37 ;
V_36 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_37 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_37 ) | ( unsigned long long ) V_36 << 32 ;
}
static inline unsigned long long F_21 ( unsigned char * V_6 )
{
unsigned int V_36 , V_37 ;
V_36 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_37 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_37 ) | ( unsigned long long ) V_36 << 32 ;
}
static T_1
F_22 ( struct V_1 * V_2 , unsigned char * V_38 , struct V_39 * V_40 )
{
unsigned int V_35 = F_7 ( V_2 ) ;
if ( ( V_38 [ 0 ] & 0x04 ) || ( V_38 [ 0 ] & 0x02 ) ) {
F_23 ( L_1
L_2
L_3 ) ;
return V_41 ;
}
if ( V_35 > V_2 -> V_5 -> V_15 . V_42 ) {
F_24 ( L_4 ,
V_35 , V_2 -> V_5 -> V_15 . V_42 ) ;
return V_14 ;
}
if ( V_38 [ 0 ] & 0x10 ) {
F_24 ( L_5 ) ;
return V_14 ;
}
if ( V_38 [ 0 ] & 0x08 ) {
if ( ! V_40 -> V_43 )
return V_41 ;
V_2 -> V_44 = V_40 -> V_43 ;
return 0 ;
}
if ( ! V_40 -> V_45 )
return V_41 ;
V_2 -> V_44 = V_40 -> V_45 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_46 ;
struct V_47 * V_48 ;
unsigned int V_49 ;
T_1 V_50 = V_51 ;
int V_52 , V_53 ;
V_12 = F_26 ( V_2 -> V_17 , V_54 ) ;
if ( ! V_12 ) {
F_23 ( L_6 ) ;
return V_55 ;
}
F_27 ( V_2 -> V_56 ,
V_2 -> V_57 ,
V_12 ,
V_2 -> V_17 ) ;
V_49 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_46 = F_29 ( F_30 ( V_48 ) ) ;
if ( ! V_46 ) {
V_50 = V_55 ;
goto V_58;
}
for ( V_52 = 0 ; V_52 < V_48 -> V_59 ; V_52 ++ )
* ( V_46 + V_48 -> V_49 + V_52 ) ^= * ( V_12 + V_49 + V_52 ) ;
V_49 += V_48 -> V_59 ;
F_31 ( V_46 ) ;
}
V_58:
F_32 ( V_12 ) ;
return V_50 ;
}
static T_1
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_60 ( V_2 , V_2 -> V_56 , V_2 -> V_57 ,
V_2 -> V_61 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_62 ) ;
if ( ( V_2 -> V_63 & V_64 ) && ! V_2 -> V_65 )
V_2 -> V_66 |= V_67 ;
F_36 ( & V_2 -> V_62 ) ;
F_37 ( & V_4 -> V_68 ) ;
return V_51 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_47 * V_69 = NULL , * V_48 ;
unsigned char * V_12 = NULL , * V_46 ;
struct V_70 V_71 ;
unsigned int V_49 = 0 , V_72 ;
unsigned int V_73 = V_2 -> V_74 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_75 = ( V_73 * V_16 ) ;
T_1 V_50 = V_51 ;
int V_76 , V_52 ;
if ( ! V_2 -> V_56 || ! V_2 -> V_77 )
return V_51 ;
if ( V_2 -> V_65 ) {
F_23 ( L_7
L_8 , V_2 -> V_65 ) ;
goto V_58;
}
V_12 = F_39 ( V_2 -> V_17 , V_54 ) ;
if ( ! V_12 ) {
F_23 ( L_9 ) ;
V_50 = V_55 ;
goto V_58;
}
V_69 = F_26 ( sizeof( struct V_47 ) * V_2 -> V_57 ,
V_54 ) ;
if ( ! V_69 ) {
F_23 ( L_10 ) ;
V_50 = V_55 ;
goto V_58;
}
F_40 ( V_69 , V_2 -> V_57 ) ;
V_76 = F_27 ( V_2 -> V_56 , V_2 -> V_57 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_76 ) {
F_23 ( L_11 ) ;
V_50 = V_55 ;
goto V_58;
}
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_46 = ( unsigned char * ) F_29 ( F_30 ( V_48 ) ) ;
if ( ! V_46 ) {
V_50 = V_55 ;
goto V_58;
}
V_72 = F_41 ( V_48 -> V_59 , V_75 ) ;
if ( memcmp ( V_46 , V_12 + V_49 , V_72 ) ) {
F_24 ( L_12 ,
V_46 , V_12 + V_49 ) ;
F_31 ( V_46 ) ;
goto V_78;
}
F_31 ( V_46 ) ;
V_49 += V_72 ;
V_75 -= V_72 ;
if ( ! V_75 )
break;
}
V_52 = 0 ;
V_72 = V_2 -> V_74 * V_16 ;
F_42 ( & V_71 , V_2 -> V_56 , V_2 -> V_57 , V_79 ) ;
while ( V_72 ) {
F_43 ( & V_71 ) ;
if ( V_16 < V_80 ) {
F_44 ( & V_69 [ V_52 ] , V_71 . V_81 , V_16 ,
V_16 ) ;
} else {
F_43 ( & V_71 ) ;
F_44 ( & V_69 [ V_52 ] , V_71 . V_81 , V_16 ,
0 ) ;
}
V_72 -= V_16 ;
V_52 ++ ;
}
F_45 ( & V_71 ) ;
V_2 -> V_82 = V_2 -> V_56 ;
V_2 -> V_56 = V_69 ;
V_2 -> V_83 = V_2 -> V_57 ;
V_2 -> V_57 = 1 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = F_34 ;
V_2 -> V_44 = F_33 ;
F_35 ( & V_2 -> V_62 ) ;
V_2 -> V_87 = V_88 ;
V_2 -> V_63 |= V_89 | V_90 | V_64 ;
F_36 ( & V_2 -> V_62 ) ;
F_46 ( V_2 ) ;
F_32 ( V_12 ) ;
return V_50 ;
V_78:
F_24 ( L_13 ,
V_4 -> V_9 -> V_91 ) ;
V_50 = V_92 ;
V_58:
F_37 ( & V_4 -> V_68 ) ;
F_32 ( V_69 ) ;
F_32 ( V_12 ) ;
return V_50 ;
}
static T_1
F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_50 ;
int V_76 ;
V_76 = F_48 ( & V_4 -> V_68 ) ;
if ( ( V_76 != 0 ) || F_49 ( V_93 ) ) {
V_2 -> V_86 = NULL ;
return V_94 ;
}
V_2 -> V_17 = V_2 -> V_74 * V_4 -> V_15 . V_16 ;
V_50 = V_2 -> V_60 ( V_2 , V_2 -> V_77 , V_2 -> V_95 ,
V_96 ) ;
if ( V_50 ) {
V_2 -> V_86 = NULL ;
F_37 ( & V_4 -> V_68 ) ;
return V_50 ;
}
return V_51 ;
}
static int
F_50 ( T_5 V_97 , enum V_98 V_99 ,
bool V_100 , struct V_1 * V_2 )
{
if ( V_100 ) {
V_2 -> V_101 = V_97 ? V_24 :
V_102 ;
switch ( V_97 ) {
case 0x0 :
case 0x3 :
V_2 -> V_103 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_103 = V_104 ;
if ( V_99 == V_105 )
V_2 -> V_103 |= V_106 ;
break;
case 0x2 :
if ( V_99 == V_105 )
V_2 -> V_103 = V_106 ;
break;
case 0x4 :
V_2 -> V_103 = V_104 ;
break;
default:
F_23 ( L_14 , V_97 ) ;
return - V_107 ;
}
} else {
V_2 -> V_101 = V_97 ? V_23 :
V_108 ;
switch ( V_97 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_103 = V_104 ;
if ( V_99 == V_105 )
V_2 -> V_103 |= V_106 ;
break;
case 0x2 :
if ( V_99 == V_105 )
V_2 -> V_103 = V_106 ;
break;
case 0x3 :
V_2 -> V_103 = 0 ;
break;
case 0x4 :
V_2 -> V_103 = V_104 ;
break;
default:
F_23 ( L_14 , V_97 ) ;
return - V_107 ;
}
}
return 0 ;
}
static bool
F_51 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_35 , bool V_100 )
{
T_5 V_97 = V_6 [ 1 ] >> 5 ;
if ( ( ! V_2 -> V_109 || ! V_2 -> V_110 ) && V_2 -> V_111 )
return true ;
switch ( V_4 -> V_15 . V_25 ) {
case V_112 :
V_2 -> V_113 = 0xffffffff ;
break;
case V_114 :
if ( V_97 )
return false ;
V_2 -> V_113 = V_2 -> V_34 ;
break;
case V_105 :
V_2 -> V_113 = V_2 -> V_34 ;
break;
case V_115 :
default:
return true ;
}
if ( F_50 ( V_97 , V_4 -> V_15 . V_25 ,
V_100 , V_2 ) )
return false ;
V_2 -> V_99 = V_4 -> V_15 . V_25 ;
V_2 -> V_116 = V_4 -> V_116 * V_35 ;
if ( V_97 )
V_2 -> V_17 = V_35 * V_4 -> V_15 . V_16 ;
F_52 ( L_15
L_16 ,
V_117 , V_2 -> V_99 , V_2 -> V_17 , V_2 -> V_116 ,
V_2 -> V_101 , V_2 -> V_103 ) ;
return true ;
}
T_1
F_53 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_118 ;
T_2 V_35 = 0 ;
T_1 V_50 ;
switch ( V_6 [ 0 ] ) {
case V_119 :
V_35 = F_13 ( V_6 ) ;
V_2 -> V_34 = F_18 ( V_6 ) ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_121 :
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_41 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_122 :
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_41 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_123 :
V_35 = F_16 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , false ) )
return V_41 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_124 :
V_35 = F_13 ( V_6 ) ;
V_2 -> V_34 = F_18 ( V_6 ) ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_125 :
case V_126 :
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_41 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_66 |= V_127 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_128 :
V_35 = F_15 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_41 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_66 |= V_127 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_129 :
V_35 = F_16 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
if ( ! F_51 ( V_4 , V_2 , V_6 , V_35 , true ) )
return V_41 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_66 |= V_127 ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
break;
case V_130 :
if ( V_2 -> V_61 != V_131 ||
! ( V_2 -> V_66 & V_132 ) )
return V_14 ;
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
V_2 -> V_86 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_66 |= V_127 ;
break;
case V_133 :
{
T_3 V_134 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_134 ) {
case V_135 :
V_35 = F_17 ( V_6 ) ;
V_2 -> V_34 = F_21 ( V_6 ) ;
V_2 -> V_66 |= V_120 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_33 ;
V_2 -> V_86 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_66 |= V_127 ;
break;
case V_136 :
V_35 = F_17 ( V_6 ) ;
if ( ! V_35 ) {
F_23 ( L_17
L_18 ) ;
return V_14 ;
}
V_118 = F_12 ( V_2 , 1 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 12 ] ) ;
V_50 = F_22 ( V_2 , & V_6 [ 10 ] , V_40 ) ;
if ( V_50 )
return V_50 ;
break;
default:
F_23 ( L_19
L_20 , V_134 ) ;
return V_41 ;
}
break;
}
case V_137 :
V_35 = V_6 [ 13 ] ;
if ( V_35 > 1 ) {
F_23 ( L_21
L_22 , V_35 ) ;
return V_14 ;
}
V_118 = 2 * F_12 ( V_2 , V_35 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 2 ] ) ;
V_2 -> V_74 = V_35 ;
V_2 -> V_66 |= V_120 | V_138 ;
V_2 -> V_60 = V_40 -> V_60 ;
V_2 -> V_44 = F_47 ;
V_2 -> V_86 = F_38 ;
break;
case V_139 :
V_118 = V_140 ;
V_2 -> V_44 = F_1 ;
break;
case V_141 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_142 :
V_2 -> V_44 = F_6 ;
break;
case V_143 :
V_2 -> V_44 = V_144 ;
break;
default:
F_23 ( L_23 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_118 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_145 :
case V_146 :
if ( V_6 [ 0 ] == V_145 ) {
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
} else {
V_35 = F_16 ( V_6 ) ;
V_2 -> V_34 = F_20 ( V_6 ) ;
}
if ( V_40 -> V_147 ) {
V_2 -> V_44 = V_40 -> V_147 ;
goto V_148;
}
V_118 = 0 ;
V_2 -> V_44 = F_10 ;
break;
case V_149 :
if ( ! V_40 -> V_150 )
return V_41 ;
V_118 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_44 = V_40 -> V_150 ;
break;
case V_33 :
V_35 = F_16 ( V_6 ) ;
if ( ! V_35 ) {
F_23 ( L_24 ) ;
return V_14 ;
}
V_118 = F_12 ( V_2 , 1 ) ;
V_2 -> V_34 = F_54 ( & V_6 [ 2 ] ) ;
V_50 = F_22 ( V_2 , & V_6 [ 1 ] , V_40 ) ;
if ( V_50 )
return V_50 ;
break;
case V_32 :
V_35 = F_14 ( V_6 ) ;
if ( ! V_35 ) {
F_23 ( L_24 ) ;
return V_14 ;
}
V_118 = F_12 ( V_2 , 1 ) ;
V_2 -> V_34 = F_9 ( & V_6 [ 2 ] ) ;
V_50 = F_22 ( V_2 , & V_6 [ 1 ] , V_40 ) ;
if ( V_50 )
return V_50 ;
break;
case V_151 :
V_118 = 0 ;
V_35 = F_14 ( V_6 ) ;
V_2 -> V_34 = F_19 ( V_6 ) ;
V_2 -> V_44 = F_10 ;
goto V_148;
case V_152 :
case V_153 :
case V_154 :
V_118 = 0 ;
V_2 -> V_44 = F_10 ;
break;
default:
V_50 = F_55 ( V_2 , & V_118 ) ;
if ( V_50 )
return V_50 ;
}
if ( ! ( V_2 -> V_66 & V_120 ) && ! V_2 -> V_44 )
return V_41 ;
if ( V_2 -> V_66 & V_120 ) {
unsigned long long V_155 ;
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
V_148:
V_155 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_34 + V_35 > V_155 ) {
F_23 ( L_29
L_30 ,
V_155 , V_2 -> V_34 , V_35 ) ;
return V_159 ;
}
if ( ! ( V_2 -> V_66 & V_138 ) )
V_118 = F_12 ( V_2 , V_35 ) ;
}
return F_57 ( V_2 , V_118 ) ;
}
T_2 F_58 ( struct V_3 * V_4 )
{
return V_160 ;
}
T_1
F_59 ( struct V_1 * V_2 ,
T_1 (* F_60)( struct V_1 * , void * ,
T_4 , T_4 ) ,
void * V_161 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_162 = NULL ;
T_4 V_163 ;
int V_118 ;
T_2 V_164 ;
T_1 V_50 = 0 ;
int V_165 , V_166 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_11 ( V_2 , V_167 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_31 ,
V_2 -> V_17 ) ;
return V_168 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_94 ;
V_165 = F_8 ( & V_12 [ 0 ] ) ;
V_166 = F_8 ( & V_12 [ 2 ] ) ;
V_118 = V_2 -> V_17 - 8 ;
if ( V_166 > V_118 )
F_24 ( L_32 ,
V_2 -> V_17 , V_166 ) ;
else
V_118 = V_166 ;
if ( V_118 / 16 > V_4 -> V_15 . V_169 ) {
V_50 = V_170 ;
goto V_171;
}
V_162 = & V_12 [ 8 ] ;
F_52 ( L_33
L_34 , V_4 -> V_9 -> V_91 , V_165 , V_166 , V_118 , V_162 ) ;
while ( V_118 >= 16 ) {
V_163 = F_54 ( & V_162 [ 0 ] ) ;
V_164 = F_9 ( & V_162 [ 8 ] ) ;
F_52 ( L_35 ,
( unsigned long long ) V_163 , V_164 ) ;
if ( V_164 > V_4 -> V_15 . V_172 ) {
V_50 = V_170 ;
goto V_171;
}
if ( V_163 + V_164 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_50 = V_159 ;
goto V_171;
}
V_50 = F_60 ( V_2 , V_161 , V_163 , V_164 ) ;
if ( V_50 )
goto V_171;
V_162 += 16 ;
V_118 -= 16 ;
}
V_171:
F_4 ( V_2 ) ;
if ( ! V_50 )
F_11 ( V_2 , V_18 ) ;
return V_50 ;
}
void
F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_173 * V_174 ;
struct V_47 * V_175 , * V_176 = V_2 -> V_109 ;
T_4 V_177 = V_2 -> V_34 ;
void * V_178 , * V_179 ;
int V_52 , V_180 , V_49 = 0 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_49 ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
for ( V_180 = 0 ; V_180 < V_175 -> V_59 ; V_180 += V_4 -> V_15 . V_16 ) {
if ( V_49 >= V_176 -> V_59 ) {
F_31 ( V_179 ) ;
V_176 = F_62 ( V_176 ) ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
V_49 = 0 ;
}
V_174 = V_179 + V_49 ;
V_174 -> V_181 = F_63 ( F_64 ( V_178 + V_180 ,
V_4 -> V_15 . V_16 ) ) ;
if ( V_4 -> V_15 . V_25 == V_105 )
V_174 -> V_182 = F_65 ( V_177 & 0xffffffff ) ;
V_174 -> V_183 = 0 ;
F_52 ( L_36
L_37 ,
( unsigned long long ) V_177 , V_174 -> V_181 ,
V_174 -> V_183 , F_66 ( V_174 -> V_182 ) ) ;
V_177 ++ ;
V_49 += sizeof( struct V_173 ) ;
}
F_31 ( V_179 ) ;
F_31 ( V_178 ) ;
}
}
static T_1
F_67 ( struct V_3 * V_4 , struct V_173 * V_174 ,
const void * V_184 , T_4 V_177 , unsigned int V_185 )
{
int V_16 = V_4 -> V_15 . V_16 ;
T_6 V_186 ;
V_186 = F_63 ( F_64 ( V_184 , V_16 ) ) ;
if ( V_174 -> V_181 != V_186 ) {
F_23 ( L_38
L_39 , ( unsigned long long ) V_177 ,
F_68 ( V_174 -> V_181 ) , F_68 ( V_186 ) ) ;
return V_187 ;
}
if ( V_4 -> V_15 . V_25 == V_105 &&
F_66 ( V_174 -> V_182 ) != ( V_177 & 0xffffffff ) ) {
F_23 ( L_40
L_41 , ( unsigned long long ) V_177 ,
F_66 ( V_174 -> V_182 ) , ( T_2 ) ( V_177 & 0xffffffff ) ) ;
return V_188 ;
}
if ( V_4 -> V_15 . V_25 == V_114 &&
F_66 ( V_174 -> V_182 ) != V_185 ) {
F_23 ( L_42
L_43 , ( unsigned long long ) V_177 ,
F_66 ( V_174 -> V_182 ) , V_185 ) ;
return V_188 ;
}
return 0 ;
}
static void
F_69 ( struct V_1 * V_2 , unsigned int V_35 , bool V_189 ,
struct V_47 * V_48 , int V_190 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_47 * V_176 ;
void * V_179 , * V_46 ;
unsigned int V_52 , V_72 , V_191 ;
unsigned int V_49 = V_190 ;
V_191 = V_35 * V_4 -> V_116 ;
F_28 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_192 , V_193 = 0 ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
V_192 = F_41 ( V_191 , V_176 -> V_59 ) ;
while ( V_192 ) {
V_72 = F_41 ( V_192 , V_48 -> V_59 - V_49 ) ;
V_46 = F_29 ( F_30 ( V_48 ) ) + V_48 -> V_49 + V_49 ;
if ( V_189 )
memcpy ( V_179 + V_193 , V_46 , V_72 ) ;
else
memcpy ( V_46 , V_179 + V_193 , V_72 ) ;
V_191 -= V_72 ;
V_49 += V_72 ;
V_193 += V_72 ;
V_192 -= V_72 ;
if ( V_49 >= V_48 -> V_59 ) {
V_48 = F_62 ( V_48 ) ;
V_49 = 0 ;
}
F_31 ( V_46 ) ;
}
F_31 ( V_179 ) ;
}
}
T_1
F_70 ( struct V_1 * V_2 , T_4 V_194 , unsigned int V_35 ,
unsigned int V_185 , struct V_47 * V_48 , int V_190 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_173 * V_174 ;
struct V_47 * V_175 , * V_176 = V_2 -> V_109 ;
T_4 V_177 = V_194 ;
void * V_178 , * V_179 ;
int V_52 , V_180 , V_49 = 0 ;
T_1 V_76 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_49 ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
for ( V_180 = 0 ; V_180 < V_175 -> V_59 ; V_180 += V_4 -> V_15 . V_16 ) {
if ( V_49 >= V_176 -> V_59 ) {
F_31 ( V_179 ) ;
V_176 = F_62 ( V_176 ) ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
V_49 = 0 ;
}
V_174 = V_179 + V_49 ;
F_52 ( L_44
L_37 ,
( unsigned long long ) V_177 , V_174 -> V_181 ,
V_174 -> V_183 , F_66 ( V_174 -> V_182 ) ) ;
V_76 = F_67 ( V_4 , V_174 , V_178 + V_180 , V_177 ,
V_185 ) ;
if ( V_76 ) {
F_31 ( V_179 ) ;
F_31 ( V_178 ) ;
V_2 -> V_195 = V_177 ;
return V_76 ;
}
V_177 ++ ;
V_185 ++ ;
V_49 += sizeof( struct V_173 ) ;
}
F_31 ( V_179 ) ;
F_31 ( V_178 ) ;
}
F_69 ( V_2 , V_35 , false , V_48 , V_190 ) ;
return 0 ;
}
static T_1
F_71 ( struct V_1 * V_2 , T_4 V_194 , unsigned int V_35 ,
unsigned int V_185 , struct V_47 * V_48 , int V_190 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_173 * V_174 ;
struct V_47 * V_175 , * V_176 = V_48 ;
T_4 V_177 = V_194 ;
void * V_178 , * V_179 ;
int V_52 , V_180 , V_49 = V_190 ;
T_1 V_76 ;
F_28 (cmd->t_data_sg, dsg, cmd->t_data_nents, i) {
V_178 = F_29 ( F_30 ( V_175 ) ) + V_175 -> V_49 ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_48 -> V_49 ;
for ( V_180 = 0 ; V_180 < V_175 -> V_59 ; V_180 += V_4 -> V_15 . V_16 ) {
if ( V_49 >= V_176 -> V_59 ) {
F_31 ( V_179 ) ;
V_176 = F_62 ( V_176 ) ;
V_179 = F_29 ( F_30 ( V_176 ) ) + V_176 -> V_49 ;
V_49 = 0 ;
}
V_174 = V_179 + V_49 ;
F_52 ( L_45
L_37 ,
( unsigned long long ) V_177 , V_174 -> V_181 ,
V_174 -> V_183 , F_66 ( V_174 -> V_182 ) ) ;
if ( V_174 -> V_183 == F_63 ( 0xffff ) ) {
V_177 ++ ;
V_49 += sizeof( struct V_173 ) ;
continue;
}
V_76 = F_67 ( V_4 , V_174 , V_178 + V_180 , V_177 ,
V_185 ) ;
if ( V_76 ) {
F_31 ( V_179 ) ;
F_31 ( V_178 ) ;
V_2 -> V_195 = V_177 ;
return V_76 ;
}
V_177 ++ ;
V_185 ++ ;
V_49 += sizeof( struct V_173 ) ;
}
F_31 ( V_179 ) ;
F_31 ( V_178 ) ;
}
return 0 ;
}
T_1
F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_35 = V_2 -> V_116 / V_4 -> V_116 ;
return F_71 ( V_2 , V_2 -> V_34 , V_35 , 0 ,
V_2 -> V_109 , 0 ) ;
}
T_1
F_73 ( struct V_1 * V_2 , T_4 V_194 , unsigned int V_35 ,
unsigned int V_185 , struct V_47 * V_48 , int V_190 )
{
T_1 V_76 ;
V_76 = F_71 ( V_2 , V_194 , V_35 , V_185 , V_48 , V_190 ) ;
if ( V_76 )
return V_76 ;
F_69 ( V_2 , V_35 , true , V_48 , V_190 ) ;
return 0 ;
}
