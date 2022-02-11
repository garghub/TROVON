static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_6 = V_4 -> V_7 -> V_8 ( V_4 ) ;
unsigned char * V_9 ;
unsigned char V_10 [ 8 ] ;
T_2 V_11 ;
if ( V_6 >= 0x00000000ffffffff )
V_11 = 0xffffffff ;
else
V_11 = ( T_2 ) V_6 ;
V_10 [ 0 ] = ( V_11 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_11 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_11 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_11 & 0xff ;
V_10 [ 4 ] = ( V_4 -> V_12 . V_13 >> 24 ) & 0xff ;
V_10 [ 5 ] = ( V_4 -> V_12 . V_13 >> 16 ) & 0xff ;
V_10 [ 6 ] = ( V_4 -> V_12 . V_13 >> 8 ) & 0xff ;
V_10 [ 7 ] = V_4 -> V_12 . V_13 & 0xff ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 ) {
memcpy ( V_9 , V_10 , F_3 ( T_2 , sizeof( V_10 ) , V_2 -> V_14 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_15 ) ;
return 0 ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_9 ;
unsigned char V_10 [ 32 ] ;
unsigned long long V_11 = V_4 -> V_7 -> V_8 ( V_4 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 0 ] = ( V_11 >> 56 ) & 0xff ;
V_10 [ 1 ] = ( V_11 >> 48 ) & 0xff ;
V_10 [ 2 ] = ( V_11 >> 40 ) & 0xff ;
V_10 [ 3 ] = ( V_11 >> 32 ) & 0xff ;
V_10 [ 4 ] = ( V_11 >> 24 ) & 0xff ;
V_10 [ 5 ] = ( V_11 >> 16 ) & 0xff ;
V_10 [ 6 ] = ( V_11 >> 8 ) & 0xff ;
V_10 [ 7 ] = V_11 & 0xff ;
V_10 [ 8 ] = ( V_4 -> V_12 . V_13 >> 24 ) & 0xff ;
V_10 [ 9 ] = ( V_4 -> V_12 . V_13 >> 16 ) & 0xff ;
V_10 [ 10 ] = ( V_4 -> V_12 . V_13 >> 8 ) & 0xff ;
V_10 [ 11 ] = V_4 -> V_12 . V_13 & 0xff ;
if ( V_4 -> V_12 . V_16 || V_4 -> V_12 . V_17 )
V_10 [ 14 ] = 0x80 ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 ) {
memcpy ( V_9 , V_10 , F_3 ( T_2 , sizeof( V_10 ) , V_2 -> V_14 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_15 ) ;
return 0 ;
}
T_3 F_7 ( struct V_1 * V_2 )
{
T_2 V_18 ;
if ( V_2 -> V_19 [ 0 ] == V_20 )
V_18 = F_8 ( & V_2 -> V_19 [ 7 ] ) ;
else if ( V_2 -> V_19 [ 0 ] == V_21 )
V_18 = F_9 ( & V_2 -> V_19 [ 10 ] ) ;
else
V_18 = F_9 ( & V_2 -> V_19 [ 28 ] ) ;
if ( V_18 )
return V_18 ;
return V_2 -> V_5 -> V_7 -> V_8 ( V_2 -> V_5 ) -
V_2 -> V_22 + 1 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 ) ;
return 0 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 , T_2 V_23 )
{
return V_2 -> V_5 -> V_12 . V_13 * V_23 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_24 ;
T_2 V_23 ;
V_23 = V_2 -> V_14 / V_4 -> V_12 . V_13 ;
V_24 = V_4 -> V_7 -> V_8 ( V_4 ) + 1 ;
if ( V_2 -> V_22 + V_23 > V_24 ) {
F_13 ( L_1 ,
V_2 -> V_22 , V_23 , V_24 ) ;
return - V_25 ;
}
return 0 ;
}
static inline T_2 F_14 ( unsigned char * V_26 )
{
return V_26 [ 4 ] ? : 256 ;
}
static inline T_2 F_15 ( unsigned char * V_26 )
{
return ( T_2 ) ( V_26 [ 7 ] << 8 ) + V_26 [ 8 ] ;
}
static inline T_2 F_16 ( unsigned char * V_26 )
{
return ( T_2 ) ( V_26 [ 6 ] << 24 ) + ( V_26 [ 7 ] << 16 ) + ( V_26 [ 8 ] << 8 ) + V_26 [ 9 ] ;
}
static inline T_2 F_17 ( unsigned char * V_26 )
{
return ( T_2 ) ( V_26 [ 10 ] << 24 ) + ( V_26 [ 11 ] << 16 ) +
( V_26 [ 12 ] << 8 ) + V_26 [ 13 ] ;
}
static inline T_2 F_18 ( unsigned char * V_26 )
{
return ( T_2 ) ( V_26 [ 28 ] << 24 ) + ( V_26 [ 29 ] << 16 ) +
( V_26 [ 30 ] << 8 ) + V_26 [ 31 ] ;
}
static inline T_2 F_19 ( unsigned char * V_26 )
{
return ( ( V_26 [ 1 ] & 0x1f ) << 16 ) | ( V_26 [ 2 ] << 8 ) | V_26 [ 3 ] ;
}
static inline T_2 F_20 ( unsigned char * V_26 )
{
return ( V_26 [ 2 ] << 24 ) | ( V_26 [ 3 ] << 16 ) | ( V_26 [ 4 ] << 8 ) | V_26 [ 5 ] ;
}
static inline unsigned long long F_21 ( unsigned char * V_26 )
{
unsigned int V_27 , V_28 ;
V_27 = ( V_26 [ 2 ] << 24 ) | ( V_26 [ 3 ] << 16 ) | ( V_26 [ 4 ] << 8 ) | V_26 [ 5 ] ;
V_28 = ( V_26 [ 6 ] << 24 ) | ( V_26 [ 7 ] << 16 ) | ( V_26 [ 8 ] << 8 ) | V_26 [ 9 ] ;
return ( ( unsigned long long ) V_28 ) | ( unsigned long long ) V_27 << 32 ;
}
static inline unsigned long long F_22 ( unsigned char * V_26 )
{
unsigned int V_27 , V_28 ;
V_27 = ( V_26 [ 12 ] << 24 ) | ( V_26 [ 13 ] << 16 ) | ( V_26 [ 14 ] << 8 ) | V_26 [ 15 ] ;
V_28 = ( V_26 [ 16 ] << 24 ) | ( V_26 [ 17 ] << 16 ) | ( V_26 [ 18 ] << 8 ) | V_26 [ 19 ] ;
return ( ( unsigned long long ) V_28 ) | ( unsigned long long ) V_27 << 32 ;
}
static T_1
F_23 ( struct V_1 * V_2 , unsigned char * V_29 , struct V_30 * V_31 )
{
unsigned int V_23 = F_7 ( V_2 ) ;
if ( ( V_29 [ 0 ] & 0x04 ) || ( V_29 [ 0 ] & 0x02 ) ) {
F_13 ( L_2
L_3
L_4 ) ;
return V_32 ;
}
if ( V_23 > V_2 -> V_5 -> V_12 . V_33 ) {
F_24 ( L_5 ,
V_23 , V_2 -> V_5 -> V_12 . V_33 ) ;
return V_34 ;
}
if ( V_29 [ 0 ] & 0x08 ) {
if ( ! V_31 -> V_35 )
return V_32 ;
V_2 -> V_36 = V_31 -> V_35 ;
return 0 ;
}
if ( ! V_31 -> V_37 )
return V_32 ;
V_2 -> V_36 = V_31 -> V_37 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char * V_10 , * V_38 ;
struct V_39 * V_40 ;
unsigned int V_41 ;
int V_42 ;
int V_43 ;
V_10 = F_26 ( V_2 -> V_14 , V_44 ) ;
if ( ! V_10 ) {
F_13 ( L_6 ) ;
return;
}
F_27 ( V_2 -> V_45 ,
V_2 -> V_46 ,
V_10 ,
V_2 -> V_14 ) ;
V_41 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_38 = F_29 ( F_30 ( V_40 ) ) ;
if ( ! V_38 )
goto V_47;
for ( V_42 = 0 ; V_42 < V_40 -> V_48 ; V_42 ++ )
* ( V_38 + V_40 -> V_41 + V_42 ) ^= * ( V_10 + V_41 + V_42 ) ;
V_41 += V_40 -> V_48 ;
F_31 ( V_38 ) ;
}
V_47:
F_32 ( V_10 ) ;
}
T_1
F_33 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_26 = V_2 -> V_19 ;
unsigned int V_49 ;
T_2 V_23 = 0 ;
T_1 V_50 ;
switch ( V_26 [ 0 ] ) {
case V_51 :
V_23 = F_14 ( V_26 ) ;
V_2 -> V_22 = F_19 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_55 :
V_23 = F_15 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_56 :
V_23 = F_16 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_57 :
V_23 = F_17 ( V_26 ) ;
V_2 -> V_22 = F_21 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_58 :
V_23 = F_14 ( V_26 ) ;
V_2 -> V_22 = F_19 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_59 :
case V_60 :
V_23 = F_15 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_62 :
V_23 = F_16 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_63 :
V_23 = F_17 ( V_26 ) ;
V_2 -> V_22 = F_21 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
break;
case V_64 :
if ( V_2 -> V_65 != V_66 ||
! ( V_2 -> V_52 & V_67 ) )
return V_34 ;
V_23 = F_15 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
V_2 -> V_68 = & F_25 ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
break;
case V_69 :
{
T_4 V_70 = F_8 ( & V_26 [ 8 ] ) ;
switch ( V_70 ) {
case V_71 :
V_23 = F_18 ( V_26 ) ;
V_2 -> V_22 = F_22 ( V_26 ) ;
V_2 -> V_52 |= V_53 ;
V_2 -> V_36 = V_31 -> V_54 ;
V_2 -> V_68 = & F_25 ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_52 |= V_61 ;
break;
case V_72 :
V_23 = F_18 ( V_26 ) ;
if ( ! V_23 ) {
F_13 ( L_7
L_8 ) ;
return V_34 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_22 = F_34 ( & V_26 [ 12 ] ) ;
V_50 = F_23 ( V_2 , & V_26 [ 10 ] , V_31 ) ;
if ( V_50 )
return V_50 ;
break;
default:
F_13 ( L_9
L_10 , V_70 ) ;
return V_32 ;
}
break;
}
case V_73 :
V_49 = V_74 ;
V_2 -> V_36 = F_1 ;
break;
case V_75 :
switch ( V_2 -> V_19 [ 1 ] & 0x1f ) {
case V_76 :
V_2 -> V_36 = F_6 ;
break;
default:
F_13 ( L_11 ,
V_2 -> V_19 [ 1 ] & 0x1f ) ;
return V_34 ;
}
V_49 = ( V_26 [ 10 ] << 24 ) | ( V_26 [ 11 ] << 16 ) |
( V_26 [ 12 ] << 8 ) | V_26 [ 13 ] ;
break;
case V_77 :
case V_78 :
if ( ! V_31 -> V_79 )
return V_32 ;
if ( V_26 [ 0 ] == V_77 ) {
V_23 = F_15 ( V_26 ) ;
V_2 -> V_22 = F_20 ( V_26 ) ;
} else {
V_23 = F_17 ( V_26 ) ;
V_2 -> V_22 = F_21 ( V_26 ) ;
}
V_49 = F_11 ( V_2 , V_23 ) ;
if ( V_2 -> V_22 || V_23 ) {
if ( F_12 ( V_2 ) < 0 )
return V_34 ;
}
V_2 -> V_36 = V_31 -> V_79 ;
break;
case V_80 :
if ( ! V_31 -> V_81 )
return V_32 ;
V_49 = F_8 ( & V_26 [ 7 ] ) ;
V_2 -> V_36 = V_31 -> V_81 ;
break;
case V_21 :
V_23 = F_17 ( V_26 ) ;
if ( ! V_23 ) {
F_13 ( L_12 ) ;
return V_34 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_22 = F_34 ( & V_26 [ 2 ] ) ;
V_50 = F_23 ( V_2 , & V_26 [ 1 ] , V_31 ) ;
if ( V_50 )
return V_50 ;
break;
case V_20 :
V_23 = F_15 ( V_26 ) ;
if ( ! V_23 ) {
F_13 ( L_12 ) ;
return V_34 ;
}
V_49 = F_11 ( V_2 , 1 ) ;
V_2 -> V_22 = F_9 ( & V_26 [ 2 ] ) ;
V_50 = F_23 ( V_2 , & V_26 [ 1 ] , V_31 ) ;
if ( V_50 )
return V_50 ;
break;
case V_82 :
V_49 = 0 ;
V_2 -> V_36 = F_10 ;
break;
case V_83 :
case V_84 :
case V_85 :
V_49 = 0 ;
V_2 -> V_36 = F_10 ;
break;
default:
V_50 = F_35 ( V_2 , & V_49 ) ;
if ( V_50 )
return V_50 ;
}
if ( ! ( V_2 -> V_52 & V_53 ) && ! V_2 -> V_36 )
return V_32 ;
if ( V_2 -> V_52 & V_53 ) {
unsigned long long V_24 ;
if ( V_23 > V_4 -> V_12 . V_86 ) {
F_36 ( V_87 L_13
L_14
L_15 , V_26 [ 0 ] , V_23 ,
V_4 -> V_12 . V_86 ) ;
return V_34 ;
}
if ( V_23 > V_4 -> V_12 . V_88 ) {
F_36 ( V_87 L_13
L_16
L_15 , V_26 [ 0 ] , V_23 ,
V_4 -> V_12 . V_88 ) ;
return V_34 ;
}
V_24 = V_4 -> V_7 -> V_8 ( V_4 ) + 1 ;
if ( V_2 -> V_22 + V_23 > V_24 ) {
F_13 ( L_17
L_18 ,
V_24 , V_2 -> V_22 , V_23 ) ;
return V_34 ;
}
V_49 = F_11 ( V_2 , V_23 ) ;
}
return F_37 ( V_2 , V_49 ) ;
}
T_2 F_38 ( struct V_3 * V_4 )
{
return V_89 ;
}
