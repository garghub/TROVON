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
if ( V_4 -> V_15 . V_19 || V_4 -> V_15 . V_20 )
V_12 [ 14 ] = 0x80 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_3 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
T_3 F_7 ( struct V_1 * V_2 )
{
T_2 V_21 ;
if ( V_2 -> V_7 [ 0 ] == V_22 )
V_21 = F_8 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_23 )
V_21 = F_9 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_21 = F_9 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_21 )
return V_21 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_24 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_25 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_25 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_26 ;
T_2 V_25 ;
V_25 = V_2 -> V_17 / V_4 -> V_15 . V_16 ;
V_26 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_24 + V_25 > V_26 ) {
F_13 ( L_1 ,
V_2 -> V_24 , V_25 , V_26 ) ;
return - V_27 ;
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
unsigned int V_28 , V_29 ;
V_28 = ( V_6 [ 2 ] << 24 ) | ( V_6 [ 3 ] << 16 ) | ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
V_29 = ( V_6 [ 6 ] << 24 ) | ( V_6 [ 7 ] << 16 ) | ( V_6 [ 8 ] << 8 ) | V_6 [ 9 ] ;
return ( ( unsigned long long ) V_29 ) | ( unsigned long long ) V_28 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_6 )
{
unsigned int V_28 , V_29 ;
V_28 = ( V_6 [ 12 ] << 24 ) | ( V_6 [ 13 ] << 16 ) | ( V_6 [ 14 ] << 8 ) | V_6 [ 15 ] ;
V_29 = ( V_6 [ 16 ] << 24 ) | ( V_6 [ 17 ] << 16 ) | ( V_6 [ 18 ] << 8 ) | V_6 [ 19 ] ;
return ( ( unsigned long long ) V_29 ) | ( unsigned long long ) V_28 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_30 , struct V_31 * V_32 )
{
unsigned int V_25 = F_7 ( V_2 ) ;
if ( ( V_30 [ 0 ] & 0x04 ) || ( V_30 [ 0 ] & 0x02 ) ) {
F_13 ( L_2
L_3
L_4 ) ;
return V_33 ;
}
if ( V_25 > V_2 -> V_5 -> V_15 . V_34 ) {
F_24 ( L_5 ,
V_25 , V_2 -> V_5 -> V_15 . V_34 ) ;
return V_14 ;
}
if ( V_30 [ 0 ] & 0x10 ) {
F_24 ( L_6 ) ;
return V_14 ;
}
if ( V_30 [ 0 ] & 0x08 ) {
if ( ! V_32 -> V_35 )
return V_33 ;
V_2 -> V_36 = V_32 -> V_35 ;
return 0 ;
}
if ( ! V_32 -> V_37 )
return V_33 ;
V_2 -> V_36 = V_32 -> V_37 ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_38 ;
struct V_39 * V_40 ;
unsigned int V_41 ;
T_1 V_42 = V_43 ;
int V_44 , V_45 ;
V_12 = F_26 ( V_2 -> V_17 , V_46 ) ;
if ( ! V_12 ) {
F_13 ( L_7 ) ;
return V_47 ;
}
F_27 ( V_2 -> V_48 ,
V_2 -> V_49 ,
V_12 ,
V_2 -> V_17 ) ;
V_41 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_38 = F_29 ( F_30 ( V_40 ) ) ;
if ( ! V_38 ) {
V_42 = V_47 ;
goto V_50;
}
for ( V_44 = 0 ; V_44 < V_40 -> V_51 ; V_44 ++ )
* ( V_38 + V_40 -> V_41 + V_44 ) ^= * ( V_12 + V_41 + V_44 ) ;
V_41 += V_40 -> V_51 ;
F_31 ( V_38 ) ;
}
V_50:
F_32 ( V_12 ) ;
return V_42 ;
}
static T_1
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_52 ( V_2 , V_2 -> V_48 , V_2 -> V_49 ,
V_2 -> V_53 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_54 ) ;
if ( ( V_2 -> V_55 & V_56 ) && ! V_2 -> V_57 )
V_2 -> V_58 |= V_59 ;
F_36 ( & V_2 -> V_54 ) ;
F_37 ( & V_4 -> V_60 ) ;
return V_43 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_61 = NULL , * V_40 ;
unsigned char * V_12 = NULL , * V_38 ;
struct V_62 V_63 ;
unsigned int V_41 = 0 , V_64 ;
unsigned int V_65 = V_2 -> V_66 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_67 = ( V_65 * V_16 ) ;
T_1 V_42 = V_43 ;
int V_68 , V_44 ;
if ( ! V_2 -> V_48 || ! V_2 -> V_69 )
return V_43 ;
if ( V_2 -> V_57 ) {
F_13 ( L_8
L_9 , V_2 -> V_57 ) ;
goto V_50;
}
V_12 = F_39 ( V_2 -> V_17 , V_46 ) ;
if ( ! V_12 ) {
F_13 ( L_10 ) ;
V_42 = V_47 ;
goto V_50;
}
V_61 = F_39 ( sizeof( struct V_39 ) * V_2 -> V_49 ,
V_46 ) ;
if ( ! V_61 ) {
F_13 ( L_11 ) ;
V_42 = V_47 ;
goto V_50;
}
V_68 = F_27 ( V_2 -> V_48 , V_2 -> V_49 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_68 ) {
F_13 ( L_12 ) ;
V_42 = V_47 ;
goto V_50;
}
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_38 = ( unsigned char * ) F_29 ( F_30 ( V_40 ) ) ;
if ( ! V_38 ) {
V_42 = V_47 ;
goto V_50;
}
V_64 = F_40 ( V_40 -> V_51 , V_67 ) ;
if ( memcmp ( V_38 , V_12 + V_41 , V_64 ) ) {
F_24 ( L_13 ,
V_38 , V_12 + V_41 ) ;
F_31 ( V_38 ) ;
goto V_70;
}
F_31 ( V_38 ) ;
V_41 += V_64 ;
V_67 -= V_64 ;
if ( ! V_67 )
break;
}
V_44 = 0 ;
V_64 = V_2 -> V_66 * V_16 ;
F_41 ( & V_63 , V_2 -> V_48 , V_2 -> V_49 , V_71 ) ;
while ( V_64 ) {
F_42 ( & V_63 ) ;
if ( V_16 < V_72 ) {
F_43 ( & V_61 [ V_44 ] , V_63 . V_73 , V_16 ,
V_16 ) ;
} else {
F_42 ( & V_63 ) ;
F_43 ( & V_61 [ V_44 ] , V_63 . V_73 , V_16 ,
0 ) ;
}
V_64 -= V_16 ;
V_44 ++ ;
}
F_44 ( & V_63 ) ;
V_2 -> V_74 = V_2 -> V_48 ;
V_2 -> V_48 = V_61 ;
V_2 -> V_75 = V_2 -> V_49 ;
V_2 -> V_49 = 1 ;
V_2 -> V_76 = V_77 ;
V_2 -> V_78 = F_34 ;
V_2 -> V_36 = F_33 ;
F_35 ( & V_2 -> V_54 ) ;
V_2 -> V_79 = V_80 ;
V_2 -> V_55 |= V_81 | V_82 | V_56 ;
F_36 ( & V_2 -> V_54 ) ;
F_45 ( V_2 ) ;
F_32 ( V_12 ) ;
return V_42 ;
V_70:
F_24 ( L_14 ,
V_4 -> V_9 -> V_83 ) ;
V_42 = V_84 ;
V_50:
F_37 ( & V_4 -> V_60 ) ;
F_32 ( V_61 ) ;
F_32 ( V_12 ) ;
return V_42 ;
}
static T_1
F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
int V_68 ;
V_68 = F_47 ( & V_4 -> V_60 ) ;
if ( ( V_68 != 0 ) || F_48 ( V_85 ) ) {
V_2 -> V_78 = NULL ;
return V_86 ;
}
V_2 -> V_17 = V_2 -> V_66 * V_4 -> V_15 . V_16 ;
V_42 = V_2 -> V_52 ( V_2 , V_2 -> V_69 , V_2 -> V_87 ,
V_88 ) ;
if ( V_42 ) {
V_2 -> V_78 = NULL ;
F_37 ( & V_4 -> V_60 ) ;
return V_42 ;
}
return V_43 ;
}
T_1
F_49 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_89 ;
T_2 V_25 = 0 ;
T_1 V_42 ;
switch ( V_6 [ 0 ] ) {
case V_90 :
V_25 = F_14 ( V_6 ) ;
V_2 -> V_24 = F_19 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_92 :
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_93 :
V_25 = F_16 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_94 :
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_95 :
V_25 = F_14 ( V_6 ) ;
V_2 -> V_24 = F_19 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_96 :
case V_97 :
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_58 |= V_98 ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_99 :
V_25 = F_16 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_58 |= V_98 ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_100 :
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_58 |= V_98 ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
break;
case V_101 :
if ( V_2 -> V_53 != V_102 ||
! ( V_2 -> V_58 & V_103 ) )
return V_14 ;
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
V_2 -> V_78 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_58 |= V_98 ;
break;
case V_104 :
{
T_4 V_105 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_105 ) {
case V_106 :
V_25 = F_18 ( V_6 ) ;
V_2 -> V_24 = F_22 ( V_6 ) ;
V_2 -> V_58 |= V_91 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_33 ;
V_2 -> V_78 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_58 |= V_98 ;
break;
case V_107 :
V_25 = F_18 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_15
L_16 ) ;
return V_14 ;
}
V_89 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_50 ( & V_6 [ 12 ] ) ;
V_42 = F_23 ( V_2 , & V_6 [ 10 ] , V_32 ) ;
if ( V_42 )
return V_42 ;
break;
default:
F_13 ( L_17
L_18 , V_105 ) ;
return V_33 ;
}
break;
}
case V_108 :
V_25 = V_6 [ 13 ] ;
if ( V_25 > 1 ) {
F_13 ( L_19
L_20 , V_25 ) ;
return V_14 ;
}
V_89 = 2 * F_11 ( V_2 , V_25 ) ;
V_2 -> V_24 = F_50 ( & V_6 [ 2 ] ) ;
V_2 -> V_66 = V_25 ;
V_2 -> V_58 |= V_91 | V_109 ;
V_2 -> V_52 = V_32 -> V_52 ;
V_2 -> V_36 = F_46 ;
V_2 -> V_78 = F_38 ;
break;
case V_110 :
V_89 = V_111 ;
V_2 -> V_36 = F_1 ;
break;
case V_112 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_113 :
V_2 -> V_36 = F_6 ;
break;
default:
F_13 ( L_21 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_89 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_114 :
case V_115 :
if ( ! V_32 -> V_116 ) {
V_89 = 0 ;
V_2 -> V_36 = F_10 ;
break;
}
if ( V_6 [ 0 ] == V_114 ) {
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
} else {
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
}
V_89 = F_11 ( V_2 , V_25 ) ;
if ( V_2 -> V_24 || V_25 ) {
if ( F_12 ( V_2 ) < 0 )
return V_117 ;
}
V_2 -> V_36 = V_32 -> V_116 ;
break;
case V_118 :
if ( ! V_32 -> V_119 )
return V_33 ;
V_89 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_36 = V_32 -> V_119 ;
break;
case V_23 :
V_25 = F_17 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_89 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_50 ( & V_6 [ 2 ] ) ;
V_42 = F_23 ( V_2 , & V_6 [ 1 ] , V_32 ) ;
if ( V_42 )
return V_42 ;
break;
case V_22 :
V_25 = F_15 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_22 ) ;
return V_14 ;
}
V_89 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_9 ( & V_6 [ 2 ] ) ;
V_42 = F_23 ( V_2 , & V_6 [ 1 ] , V_32 ) ;
if ( V_42 )
return V_42 ;
break;
case V_120 :
V_89 = 0 ;
V_2 -> V_36 = F_10 ;
break;
case V_121 :
case V_122 :
case V_123 :
V_89 = 0 ;
V_2 -> V_36 = F_10 ;
break;
default:
V_42 = F_51 ( V_2 , & V_89 ) ;
if ( V_42 )
return V_42 ;
}
if ( ! ( V_2 -> V_58 & V_91 ) && ! V_2 -> V_36 )
return V_33 ;
if ( V_2 -> V_58 & V_91 ) {
unsigned long long V_26 ;
if ( V_25 > V_4 -> V_15 . V_124 ) {
F_52 ( V_125 L_23
L_24
L_25 , V_6 [ 0 ] , V_25 ,
V_4 -> V_15 . V_124 ) ;
return V_14 ;
}
if ( V_25 > V_4 -> V_15 . V_126 ) {
F_52 ( V_125 L_23
L_26
L_25 , V_6 [ 0 ] , V_25 ,
V_4 -> V_15 . V_126 ) ;
return V_14 ;
}
V_26 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_24 + V_25 > V_26 ) {
F_13 ( L_27
L_28 ,
V_26 , V_2 -> V_24 , V_25 ) ;
return V_117 ;
}
if ( ! ( V_2 -> V_58 & V_109 ) )
V_89 = F_11 ( V_2 , V_25 ) ;
}
return F_53 ( V_2 , V_89 ) ;
}
T_2 F_54 ( struct V_3 * V_4 )
{
return V_127 ;
}
T_1
F_55 ( struct V_1 * V_2 ,
T_1 (* F_56)( struct V_1 * , void * ,
T_3 , T_3 ) ,
void * V_128 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_129 = NULL ;
T_3 V_130 ;
int V_89 ;
T_2 V_131 ;
T_1 V_42 = 0 ;
int V_132 , V_133 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_5 ( V_2 , V_134 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_29 ,
V_2 -> V_17 ) ;
return V_135 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_86 ;
V_132 = F_8 ( & V_12 [ 0 ] ) ;
V_133 = F_8 ( & V_12 [ 2 ] ) ;
V_89 = V_2 -> V_17 - 8 ;
if ( V_133 > V_89 )
F_24 ( L_30 ,
V_2 -> V_17 , V_133 ) ;
else
V_89 = V_133 ;
if ( V_89 / 16 > V_4 -> V_15 . V_136 ) {
V_42 = V_137 ;
goto V_138;
}
V_129 = & V_12 [ 8 ] ;
F_57 ( L_31
L_32 , V_4 -> V_9 -> V_83 , V_132 , V_133 , V_89 , V_129 ) ;
while ( V_89 >= 16 ) {
V_130 = F_50 ( & V_129 [ 0 ] ) ;
V_131 = F_9 ( & V_129 [ 8 ] ) ;
F_57 ( L_33 ,
( unsigned long long ) V_130 , V_131 ) ;
if ( V_131 > V_4 -> V_15 . V_139 ) {
V_42 = V_137 ;
goto V_138;
}
if ( V_130 + V_131 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_42 = V_117 ;
goto V_138;
}
V_42 = F_56 ( V_2 , V_128 , V_130 , V_131 ) ;
if ( V_42 )
goto V_138;
V_129 += 16 ;
V_89 -= 16 ;
}
V_138:
F_4 ( V_2 ) ;
if ( ! V_42 )
F_5 ( V_2 , V_18 ) ;
return V_42 ;
}
