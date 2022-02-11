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
static void F_25 ( struct V_1 * V_2 )
{
unsigned char * V_12 , * V_38 ;
struct V_39 * V_40 ;
unsigned int V_41 ;
int V_42 ;
int V_43 ;
V_12 = F_26 ( V_2 -> V_17 , V_44 ) ;
if ( ! V_12 ) {
F_13 ( L_6 ) ;
return;
}
F_27 ( V_2 -> V_45 ,
V_2 -> V_46 ,
V_12 ,
V_2 -> V_17 ) ;
V_41 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_38 = F_29 ( F_30 ( V_40 ) ) ;
if ( ! V_38 )
goto V_47;
for ( V_42 = 0 ; V_42 < V_40 -> V_48 ; V_42 ++ )
* ( V_38 + V_40 -> V_41 + V_42 ) ^= * ( V_12 + V_41 + V_42 ) ;
V_41 += V_40 -> V_48 ;
F_31 ( V_38 ) ;
}
V_47:
F_32 ( V_12 ) ;
}
T_1
F_33 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_49 ;
T_2 V_25 = 0 ;
T_1 V_50 ;
switch ( V_6 [ 0 ] ) {
case V_51 :
V_25 = F_14 ( V_6 ) ;
V_2 -> V_24 = F_19 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_55 :
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_56 :
V_25 = F_16 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_57 :
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_58 :
V_25 = F_14 ( V_6 ) ;
V_2 -> V_24 = F_19 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_59 :
case V_60 :
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_62 :
V_25 = F_16 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_63 :
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
break;
case V_64 :
if ( V_2 -> V_65 != V_66 ||
! ( V_2 -> V_52 & V_67 ) )
return V_14 ;
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
V_2 -> V_68 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
break;
case V_69 :
{
T_4 V_70 = F_8 ( & V_6 [ 8 ] ) ;
switch ( V_70 ) {
case V_71 :
V_25 = F_18 ( V_6 ) ;
V_2 -> V_24 = F_22 ( V_6 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_32 -> V_54 ;
V_2 -> V_68 = & F_25 ;
if ( V_6 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
break;
case V_72 :
V_25 = F_18 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_7
L_8 ) ;
return V_14 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_34 ( & V_6 [ 12 ] ) ;
V_50 = F_23 ( V_2 , & V_6 [ 10 ] , V_32 ) ;
if ( V_50 )
return V_50 ;
break;
default:
F_13 ( L_9
L_10 , V_70 ) ;
return V_33 ;
}
break;
}
case V_73 :
V_49 = V_74 ;
V_2 -> V_36 = F_1 ;
break;
case V_75 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_76 :
V_2 -> V_36 = F_6 ;
break;
default:
F_13 ( L_11 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_49 = ( V_6 [ 10 ] << 24 ) | ( V_6 [ 11 ] << 16 ) |
( V_6 [ 12 ] << 8 ) | V_6 [ 13 ] ;
break;
case V_77 :
case V_78 :
if ( ! V_32 -> V_79 ) {
V_49 = 0 ;
V_2 -> V_36 = F_10 ;
break;
}
if ( V_6 [ 0 ] == V_77 ) {
V_25 = F_15 ( V_6 ) ;
V_2 -> V_24 = F_20 ( V_6 ) ;
} else {
V_25 = F_17 ( V_6 ) ;
V_2 -> V_24 = F_21 ( V_6 ) ;
}
V_49 = F_11 ( V_2 , V_25 ) ;
if ( V_2 -> V_24 || V_25 ) {
if ( F_12 ( V_2 ) < 0 )
return V_80 ;
}
V_2 -> V_36 = V_32 -> V_79 ;
break;
case V_81 :
if ( ! V_32 -> V_82 )
return V_33 ;
V_49 = F_8 ( & V_6 [ 7 ] ) ;
V_2 -> V_36 = V_32 -> V_82 ;
break;
case V_23 :
V_25 = F_17 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_12 ) ;
return V_14 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_34 ( & V_6 [ 2 ] ) ;
V_50 = F_23 ( V_2 , & V_6 [ 1 ] , V_32 ) ;
if ( V_50 )
return V_50 ;
break;
case V_22 :
V_25 = F_15 ( V_6 ) ;
if ( ! V_25 ) {
F_13 ( L_12 ) ;
return V_14 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_24 = F_9 ( & V_6 [ 2 ] ) ;
V_50 = F_23 ( V_2 , & V_6 [ 1 ] , V_32 ) ;
if ( V_50 )
return V_50 ;
break;
case V_83 :
V_49 = 0 ;
V_2 -> V_36 = F_10 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_49 = 0 ;
V_2 -> V_36 = F_10 ;
break;
default:
V_50 = F_35 ( V_2 , & V_49 ) ;
if ( V_50 )
return V_50 ;
}
if ( ! ( V_2 -> V_52 & V_53 ) && ! V_2 -> V_36 )
return V_33 ;
if ( V_2 -> V_52 & V_53 ) {
unsigned long long V_26 ;
if ( V_25 > V_4 -> V_15 . V_87 ) {
F_36 ( V_88 L_13
L_14
L_15 , V_6 [ 0 ] , V_25 ,
V_4 -> V_15 . V_87 ) ;
return V_14 ;
}
if ( V_25 > V_4 -> V_15 . V_89 ) {
F_36 ( V_88 L_13
L_16
L_15 , V_6 [ 0 ] , V_25 ,
V_4 -> V_15 . V_89 ) ;
return V_14 ;
}
V_26 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( V_2 -> V_24 + V_25 > V_26 ) {
F_13 ( L_17
L_18 ,
V_26 , V_2 -> V_24 , V_25 ) ;
return V_80 ;
}
V_49 = F_11 ( V_2 , V_25 ) ;
}
return F_37 ( V_2 , V_49 ) ;
}
T_2 F_38 ( struct V_3 * V_4 )
{
return V_90 ;
}
T_1
F_39 ( struct V_1 * V_2 ,
T_1 (* F_40)( struct V_1 * , void * ,
T_3 , T_3 ) ,
void * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_92 = NULL ;
T_3 V_93 ;
int V_49 ;
T_2 V_94 ;
T_1 V_50 = 0 ;
int V_95 , V_96 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_5 ( V_2 , V_97 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_24 ( L_19 ,
V_2 -> V_17 ) ;
return V_98 ;
}
V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return V_99 ;
V_95 = F_8 ( & V_12 [ 0 ] ) ;
V_96 = F_8 ( & V_12 [ 2 ] ) ;
V_49 = V_2 -> V_17 - 8 ;
if ( V_96 > V_49 )
F_24 ( L_20 ,
V_2 -> V_17 , V_96 ) ;
else
V_49 = V_96 ;
if ( V_49 / 16 > V_4 -> V_15 . V_100 ) {
V_50 = V_101 ;
goto V_102;
}
V_92 = & V_12 [ 8 ] ;
F_41 ( L_21
L_22 , V_4 -> V_9 -> V_103 , V_95 , V_96 , V_49 , V_92 ) ;
while ( V_49 >= 16 ) {
V_93 = F_34 ( & V_92 [ 0 ] ) ;
V_94 = F_9 ( & V_92 [ 8 ] ) ;
F_41 ( L_23 ,
( unsigned long long ) V_93 , V_94 ) ;
if ( V_94 > V_4 -> V_15 . V_104 ) {
V_50 = V_101 ;
goto V_102;
}
if ( V_93 + V_94 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_50 = V_80 ;
goto V_102;
}
V_50 = F_40 ( V_2 , V_91 , V_93 , V_94 ) ;
if ( V_50 )
goto V_102;
V_92 += 16 ;
V_49 -= 16 ;
}
V_102:
F_4 ( V_2 ) ;
if ( ! V_50 )
F_5 ( V_2 , V_18 ) ;
return V_50 ;
}
