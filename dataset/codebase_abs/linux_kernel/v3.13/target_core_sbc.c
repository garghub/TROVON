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
if ( V_4 -> V_9 -> V_19 )
V_12 [ 13 ] = V_4 -> V_9 -> V_19 ( V_4 ) & 0x0f ;
if ( V_4 -> V_9 -> V_20 ) {
T_3 V_21 = V_4 -> V_9 -> V_20 ( V_4 ) ;
V_12 [ 14 ] = ( V_21 >> 8 ) & 0x3f ;
V_12 [ 15 ] = V_21 & 0xff ;
}
if ( V_4 -> V_15 . V_22 || V_4 -> V_15 . V_23 )
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
T_2 V_24 ;
if ( V_2 -> V_7 [ 0 ] == V_25 )
V_24 = F_8 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_26 )
V_24 = F_9 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_24 = F_9 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_24 )
return V_24 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_27 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_28 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_28 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_29 ;
T_2 V_28 ;
V_28 = V_2 -> V_17 / V_4 -> V_15 . V_16 ;
V_29 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_27 + V_28 > V_29 ) {
F_13 ( L_1 ,
V_2 -> V_27 , V_28 , V_29 ) ;
return - V_30 ;
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
unsigned int V_31 , V_32 ;
V_31 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_32 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_32 ) | ( unsigned long long ) V_31 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_31 , V_32 ;
V_31 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_32 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_32 ) | ( unsigned long long ) V_31 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_33 , struct V_34 * V_35 )
{
unsigned int V_28 = F_7 ( V_2 ) ;
if ( ( V_33 [ 0 ] & 0x04 ) || ( V_33 [ 0 ] & 0x02 ) ) {
F_13 ( L_2
L_3
L_4 ) ;
return V_36 ;
}
if ( V_28 > V_2 -> V_5 -> V_15 . V_37 ) {
F_24 ( L_5 ,
V_28 , V_2 -> V_5 -> V_15 . V_37 ) ;
return V_14 ;
}
if ( V_33 [ 0 ] & 0x10 ) {
F_24 ( L_6 ) ;
return V_14 ;
}
if ( V_33 [ 0 ] & 0x08 ) {
if ( ! V_35 -> V_38 )
return V_36 ;
V_2 -> V_39 = V_35 -> V_38 ;
return 0 ;
}
if ( ! V_35 -> V_40 )
return V_36 ;
V_2 -> V_39 = V_35 -> V_40 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_41 ;
struct V_42 * V_43 ;
unsigned int V_44 ;
T_1 V_45 = V_46 ;
int V_47 , V_48 ;
V_12 = F_26 ( V_2 -> V_17 , V_49 ) ;
if ( ! V_12 ) {
F_13 ( L_7 ) ;
return V_50 ;
}
F_27 ( V_2 -> V_51 ,
V_2 -> V_52 ,
V_12 ,
V_2 -> V_17 ) ;
V_44 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_41 = F_29 ( F_30 ( V_43 ) ) ;
if ( ! V_41 ) {
V_45 = V_50 ;
goto V_53;
}
for ( V_47 = 0 ; V_47 < V_43 -> V_54 ; V_47 ++ )
* ( V_41 + V_43 -> V_44 + V_47 ) ^= * ( V_12 + V_44 + V_47 ) ;
V_44 += V_43 -> V_54 ;
F_31 ( V_41 ) ;
}
V_53:
F_32 ( V_12 ) ;
return V_45 ;
}
static T_1
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_55 ( V_2 , V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_56 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_57 ) ;
if ( ( V_2 -> V_58 & V_59 ) && ! V_2 -> V_60 )
V_2 -> V_61 |= V_62 ;
F_36 ( & V_2 -> V_57 ) ;
F_37 ( & V_4 -> V_63 ) ;
return V_46 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_64 = NULL , * V_43 ;
unsigned char * V_12 = NULL , * V_41 ;
struct V_65 V_66 ;
unsigned int V_44 = 0 , V_67 ;
unsigned int V_68 = V_2 -> V_69 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_70 = ( V_68 * V_16 ) ;
T_1 V_45 = V_46 ;
int V_71 , V_47 ;
if ( ! V_2 -> V_51 || ! V_2 -> V_72 )
return V_46 ;
if ( V_2 -> V_60 ) {
F_13 ( L_8
L_9 , V_2 -> V_60 ) ;
goto V_53;
}
V_12 = F_39 ( V_2 -> V_17 , V_49 ) ;
if ( ! V_12 ) {
F_13 ( L_10 ) ;
V_45 = V_50 ;
goto V_53;
}
V_64 = F_39 ( sizeof( struct V_42 ) * V_2 -> V_52 ,
V_49 ) ;
if ( ! V_64 ) {
F_13 ( L_11 ) ;
V_45 = V_50 ;
goto V_53;
}
V_71 = F_27 ( V_2 -> V_51 , V_2 -> V_52 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_71 ) {
F_13 ( L_12 ) ;
V_45 = V_50 ;
goto V_53;
}
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_41 = ( unsigned char * ) F_29 ( F_30 ( V_43 ) ) ;
if ( ! V_41 ) {
V_45 = V_50 ;
goto V_53;
}
V_67 = F_40 ( V_43 -> V_54 , V_70 ) ;
if ( memcmp ( V_41 , V_12 + V_44 , V_67 ) ) {
F_24 ( L_13 ,
V_41 , V_12 + V_44 ) ;
F_31 ( V_41 ) ;
goto V_73;
}
F_31 ( V_41 ) ;
V_44 += V_67 ;
V_70 -= V_67 ;
if ( ! V_70 )
break;
}
V_47 = 0 ;
V_67 = V_2 -> V_69 * V_16 ;
F_41 ( & V_66 , V_2 -> V_51 , V_2 -> V_52 , V_74 ) ;
while ( V_67 ) {
F_42 ( & V_66 ) ;
if ( V_16 < V_75 ) {
F_43 ( & V_64 [ V_47 ] , V_66 . V_76 , V_16 ,
V_16 ) ;
} else {
F_42 ( & V_66 ) ;
F_43 ( & V_64 [ V_47 ] , V_66 . V_76 , V_16 ,
0 ) ;
}
V_67 -= V_16 ;
V_47 ++ ;
}
F_44 ( & V_66 ) ;
V_2 -> V_77 = V_2 -> V_51 ;
V_2 -> V_51 = V_64 ;
V_2 -> V_78 = V_2 -> V_52 ;
V_2 -> V_52 = 1 ;
V_2 -> V_79 = V_80 ;
V_2 -> V_81 = F_34 ;
V_2 -> V_39 = F_33 ;
F_35 ( & V_2 -> V_57 ) ;
V_2 -> V_82 = V_83 ;
V_2 -> V_58 |= V_84 | V_85 | V_59 ;
F_36 ( & V_2 -> V_57 ) ;
F_45 ( V_2 ) ;
F_32 ( V_12 ) ;
return V_45 ;
V_73:
F_24 ( L_14 ,
V_4 -> V_9 -> V_86 ) ;
V_45 = V_87 ;
V_53:
F_37 ( & V_4 -> V_63 ) ;
F_32 ( V_64 ) ;
F_32 ( V_12 ) ;
return V_45 ;
}
static T_1
F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_45 ;
int V_71 ;
V_71 = F_47 ( & V_4 -> V_63 ) ;
if ( ( V_71 != 0 ) || F_48 ( V_88 ) ) {
V_2 -> V_81 = NULL ;
return V_89 ;
}
V_2 -> V_17 = V_2 -> V_69 * V_4 -> V_15 . V_16 ;
V_45 = V_2 -> V_55 ( V_2 , V_2 -> V_72 , V_2 -> V_90 ,
V_91 ) ;
if ( V_45 ) {
V_2 -> V_81 = NULL ;
F_37 ( & V_4 -> V_63 ) ;
return V_45 ;
}
return V_46 ;
}
T_1
F_49 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_92 ;
T_2 V_28 = 0 ;
T_1 V_45 ;
switch ( V_6 [ 0 ] ) {
case V_93 :
V_28 = F_14 ( V_6 ) ;
V_2 -> V_27 = F_19 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_95 :
V_28 = F_15 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_96 :
V_28 = F_16 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_97 :
V_28 = F_17 ( V_6 ) ;
V_2 -> V_27 = F_21 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_98 :
V_28 = F_14 ( V_6 ) ;
V_2 -> V_27 = F_19 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_99 :
case V_100 :
V_28 = F_15 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_61 |= V_101 ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_102 :
V_28 = F_16 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_61 |= V_101 ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_103 :
V_28 = F_17 ( V_6 ) ;
V_2 -> V_27 = F_21 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_61 |= V_101 ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
break;
case V_104 :
if ( V_2 -> V_56 != V_105 ||
! ( V_2 -> V_61 & V_106 ) )
return V_14 ;
V_28 = F_15 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
V_2 -> V_81 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_61 |= V_101 ;
break;
case V_107 :
{
T_3 V_108 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_108 ) {
case V_109 :
V_28 = F_18 ( V_6 ) ;
V_2 -> V_27 = F_22 ( V_6 ) ;
V_2 -> V_61 |= V_94 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_33 ;
V_2 -> V_81 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_61 |= V_101 ;
break;
case V_110 :
V_28 = F_18 ( V_6 ) ;
if ( ! V_28 ) {
F_13 ( L_15
L_16 ) ;
return V_14 ;
}
V_92 = F_11 ( V_2 , 1 ) ;
V_2 -> V_27 = F_50 ( & V_6 [ 12 ] ) ;
V_45 = F_23 ( V_2 , & V_6 [ 10 ] , V_35 ) ;
if ( V_45 )
return V_45 ;
break;
default:
F_13 ( L_17
L_18 , V_108 ) ;
return V_36 ;
}
break;
}
case V_111 :
V_28 = V_6 [ 13 ] ;
if ( V_28 > 1 ) {
F_13 ( L_19
L_20 , V_28 ) ;
return V_14 ;
}
V_92 = 2 * F_11 ( V_2 , V_28 ) ;
V_2 -> V_27 = F_50 ( & V_6 [ 2 ] ) ;
V_2 -> V_69 = V_28 ;
V_2 -> V_61 |= V_94 | V_112 ;
V_2 -> V_55 = V_35 -> V_55 ;
V_2 -> V_39 = F_46 ;
V_2 -> V_81 = F_38 ;
break;
case V_113 :
V_92 = V_114 ;
V_2 -> V_39 = F_1 ;
break;
case V_115 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_116 :
V_2 -> V_39 = F_6 ;
break;
default:
F_13 ( L_21 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_92 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_117 :
case V_118 :
if ( ! V_35 -> V_119 ) {
V_92 = 0 ;
V_2 -> V_39 = F_10 ;
break;
}
if ( V_6 [ 0 ] == V_117 ) {
V_28 = F_15 ( V_6 ) ;
V_2 -> V_27 = F_20 ( V_6 ) ;
} else {
V_28 = F_17 ( V_6 ) ;
V_2 -> V_27 = F_21 ( V_6 ) ;
}
V_92 = F_11 ( V_2 , V_28 ) ;
if ( V_2 -> V_27 || V_28 ) {
if ( F_12 ( V_2 ) < 0 )
return V_120 ;
}
V_2 -> V_39 = V_35 -> V_119 ;
break;
case V_121 :
if ( ! V_35 -> V_122 )
return V_36 ;
V_92 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_39 = V_35 -> V_122 ;
break;
case V_26 :
V_28 = F_17 ( V_6 ) ;
if ( ! V_28 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_92 = F_11 ( V_2 , 1 ) ;
V_2 -> V_27 = F_50 ( & V_6 [ 2 ] ) ;
V_45 = F_23 ( V_2 , & V_6 [ 1 ] , V_35 ) ;
if ( V_45 )
return V_45 ;
break;
case V_25 :
V_28 = F_15 ( V_6 ) ;
if ( ! V_28 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_92 = F_11 ( V_2 , 1 ) ;
V_2 -> V_27 = F_9 ( & V_6 [ 2 ] ) ;
V_45 = F_23 ( V_2 , & V_6 [ 1 ] , V_35 ) ;
if ( V_45 )
return V_45 ;
break;
case V_123 :
V_92 = 0 ;
V_2 -> V_39 = F_10 ;
break;
case V_124 :
case V_125 :
case V_126 :
V_92 = 0 ;
V_2 -> V_39 = F_10 ;
break;
default:
V_45 = F_51 ( V_2 , & V_92 ) ;
if ( V_45 )
return V_45 ;
}
if ( ! ( V_2 -> V_61 & V_94 ) && ! V_2 -> V_39 )
return V_36 ;
if ( V_2 -> V_61 & V_94 ) {
unsigned long long V_29 ;
if ( V_28 > V_4 -> V_15 . V_127 ) {
F_52 ( V_128 L_23
L_24
L_25 , V_6 [ 0 ] , V_28 ,
V_4 -> V_15 . V_127 ) ;
return V_14 ;
}
if ( V_28 > V_4 -> V_15 . V_129 ) {
F_52 ( V_128 L_23
L_26
L_25 , V_6 [ 0 ] , V_28 ,
V_4 -> V_15 . V_129 ) ;
return V_14 ;
}
V_29 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_27 + V_28 > V_29 ) {
F_13 ( L_27
L_28 ,
V_29 , V_2 -> V_27 , V_28 ) ;
return V_120 ;
}
if ( ! ( V_2 -> V_61 & V_112 ) )
V_92 = F_11 ( V_2 , V_28 ) ;
}
return F_53 ( V_2 , V_92 ) ;
}
T_2 F_54 ( struct V_3 * V_4 )
{
return V_130 ;
}
T_1
F_55 ( struct V_1 * V_2 ,
T_1 (* F_56)( struct V_1 * , void * ,
T_4 , T_4 ) ,
void * V_131 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_132 = NULL ;
T_4 V_133 ;
int V_92 ;
T_2 V_134 ;
T_1 V_45 = 0 ;
int V_135 , V_136 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_5 ( V_2 , V_137 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_29 ,
V_2 -> V_17 ) ;
return V_138 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_89 ;
V_135 = F_8 ( & V_12 [ 0 ] ) ;
V_136 = F_8 ( & V_12 [ 2 ] ) ;
V_92 = V_2 -> V_17 - 8 ;
if ( V_136 > V_92 )
F_24 ( L_30 ,
V_2 -> V_17 , V_136 ) ;
else
V_92 = V_136 ;
if ( V_92 / 16 > V_4 -> V_15 . V_139 ) {
V_45 = V_140 ;
goto V_141;
}
V_132 = & V_12 [ 8 ] ;
F_57 ( L_31
L_32 , V_4 -> V_9 -> V_86 , V_135 , V_136 , V_92 , V_132 ) ;
while ( V_92 >= 16 ) {
V_133 = F_50 ( & V_132 [ 0 ] ) ;
V_134 = F_9 ( & V_132 [ 8 ] ) ;
F_57 ( L_33 ,
( unsigned long long ) V_133 , V_134 ) ;
if ( V_134 > V_4 -> V_15 . V_142 ) {
V_45 = V_140 ;
goto V_141;
}
if ( V_133 + V_134 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_45 = V_120 ;
goto V_141;
}
V_45 = F_56 ( V_2 , V_131 , V_133 , V_134 ) ;
if ( V_45 )
goto V_141;
V_132 += 16 ;
V_92 -= 16 ;
}
V_141:
F_4 ( V_2 ) ;
if ( ! V_45 )
F_5 ( V_2 , V_18 ) ;
return V_45 ;
}
