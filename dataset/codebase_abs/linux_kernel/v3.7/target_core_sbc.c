static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_6 = V_4 -> V_7 -> V_8 ( V_4 ) ;
unsigned char * V_9 ;
unsigned char V_10 [ 8 ] ;
T_1 V_11 ;
if ( V_6 >= 0x00000000ffffffff )
V_11 = 0xffffffff ;
else
V_11 = ( T_1 ) V_6 ;
V_10 [ 0 ] = ( V_11 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_11 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_11 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_11 & 0xff ;
V_10 [ 4 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 24 ) & 0xff ;
V_10 [ 5 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 16 ) & 0xff ;
V_10 [ 6 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 8 ) & 0xff ;
V_10 [ 7 ] = V_4 -> V_12 -> V_13 . V_14 & 0xff ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 ) {
memcpy ( V_9 , V_10 , F_3 ( T_1 , sizeof( V_10 ) , V_2 -> V_15 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
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
V_10 [ 8 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 24 ) & 0xff ;
V_10 [ 9 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 16 ) & 0xff ;
V_10 [ 10 ] = ( V_4 -> V_12 -> V_13 . V_14 >> 8 ) & 0xff ;
V_10 [ 11 ] = V_4 -> V_12 -> V_13 . V_14 & 0xff ;
if ( V_4 -> V_12 -> V_13 . V_17 || V_4 -> V_12 -> V_13 . V_18 )
V_10 [ 14 ] = 0x80 ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 ) {
memcpy ( V_9 , V_10 , F_3 ( T_1 , sizeof( V_10 ) , V_2 -> V_15 ) ) ;
F_4 ( V_2 ) ;
}
F_5 ( V_2 , V_16 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( V_2 -> V_20 [ 0 ] == V_21 )
V_19 = F_8 ( & V_2 -> V_20 [ 7 ] ) ;
else if ( V_2 -> V_20 [ 0 ] == V_22 )
V_19 = F_9 ( & V_2 -> V_20 [ 10 ] ) ;
else
V_19 = F_9 ( & V_2 -> V_20 [ 28 ] ) ;
if ( V_19 )
return V_19 ;
return V_2 -> V_5 -> V_7 -> V_8 ( V_2 -> V_5 ) -
V_2 -> V_23 + 1 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_16 ) ;
return 0 ;
}
static inline T_1 F_12 ( struct V_1 * V_2 , T_1 V_24 )
{
return V_2 -> V_5 -> V_12 -> V_13 . V_14 * V_24 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_25 ;
T_1 V_24 ;
V_24 = V_2 -> V_15 / V_4 -> V_12 -> V_13 . V_14 ;
V_25 = V_4 -> V_7 -> V_8 ( V_4 ) + 1 ;
if ( V_2 -> V_23 + V_24 > V_25 ) {
F_14 ( L_1 ,
V_2 -> V_23 , V_24 , V_25 ) ;
return - V_26 ;
}
return 0 ;
}
static inline T_1 F_15 ( unsigned char * V_27 )
{
return V_27 [ 4 ] ? : 256 ;
}
static inline T_1 F_16 ( unsigned char * V_27 )
{
return ( T_1 ) ( V_27 [ 7 ] << 8 ) + V_27 [ 8 ] ;
}
static inline T_1 F_17 ( unsigned char * V_27 )
{
return ( T_1 ) ( V_27 [ 6 ] << 24 ) + ( V_27 [ 7 ] << 16 ) + ( V_27 [ 8 ] << 8 ) + V_27 [ 9 ] ;
}
static inline T_1 F_18 ( unsigned char * V_27 )
{
return ( T_1 ) ( V_27 [ 10 ] << 24 ) + ( V_27 [ 11 ] << 16 ) +
( V_27 [ 12 ] << 8 ) + V_27 [ 13 ] ;
}
static inline T_1 F_19 ( unsigned char * V_27 )
{
return ( T_1 ) ( V_27 [ 28 ] << 24 ) + ( V_27 [ 29 ] << 16 ) +
( V_27 [ 30 ] << 8 ) + V_27 [ 31 ] ;
}
static inline T_1 F_20 ( unsigned char * V_27 )
{
return ( ( V_27 [ 1 ] & 0x1f ) << 16 ) | ( V_27 [ 2 ] << 8 ) | V_27 [ 3 ] ;
}
static inline T_1 F_21 ( unsigned char * V_27 )
{
return ( V_27 [ 2 ] << 24 ) | ( V_27 [ 3 ] << 16 ) | ( V_27 [ 4 ] << 8 ) | V_27 [ 5 ] ;
}
static inline unsigned long long F_22 ( unsigned char * V_27 )
{
unsigned int V_28 , V_29 ;
V_28 = ( V_27 [ 2 ] << 24 ) | ( V_27 [ 3 ] << 16 ) | ( V_27 [ 4 ] << 8 ) | V_27 [ 5 ] ;
V_29 = ( V_27 [ 6 ] << 24 ) | ( V_27 [ 7 ] << 16 ) | ( V_27 [ 8 ] << 8 ) | V_27 [ 9 ] ;
return ( ( unsigned long long ) V_29 ) | ( unsigned long long ) V_28 << 32 ;
}
static inline unsigned long long F_23 ( unsigned char * V_27 )
{
unsigned int V_28 , V_29 ;
V_28 = ( V_27 [ 12 ] << 24 ) | ( V_27 [ 13 ] << 16 ) | ( V_27 [ 14 ] << 8 ) | V_27 [ 15 ] ;
V_29 = ( V_27 [ 16 ] << 24 ) | ( V_27 [ 17 ] << 16 ) | ( V_27 [ 18 ] << 8 ) | V_27 [ 19 ] ;
return ( ( unsigned long long ) V_29 ) | ( unsigned long long ) V_28 << 32 ;
}
static int F_24 ( struct V_3 * V_4 ,
unsigned char * V_30 )
{
if ( ( V_30 [ 0 ] & 0x04 ) || ( V_30 [ 0 ] & 0x02 ) ) {
F_14 ( L_2
L_3
L_4 ) ;
return - V_31 ;
}
if ( ! ( V_30 [ 0 ] & 0x08 ) ) {
F_14 ( L_5
L_6 ) ;
return - V_31 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char * V_10 , * V_32 ;
struct V_33 * V_34 ;
unsigned int V_35 ;
int V_36 ;
int V_37 ;
V_10 = F_26 ( V_2 -> V_15 , V_38 ) ;
if ( ! V_10 ) {
F_14 ( L_7 ) ;
return;
}
F_27 ( V_2 -> V_39 ,
V_2 -> V_40 ,
V_10 ,
V_2 -> V_15 ) ;
V_35 = 0 ;
F_28 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_32 = F_29 ( F_30 ( V_34 ) ) ;
if ( ! V_32 )
goto V_41;
for ( V_36 = 0 ; V_36 < V_34 -> V_42 ; V_36 ++ )
* ( V_32 + V_34 -> V_35 + V_36 ) ^= * ( V_10 + V_35 + V_36 ) ;
V_35 += V_34 -> V_42 ;
F_31 ( V_32 ) ;
}
V_41:
F_32 ( V_10 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 = V_2 -> V_5 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_27 = V_2 -> V_20 ;
unsigned int V_47 ;
T_1 V_24 = 0 ;
int V_48 ;
switch ( V_27 [ 0 ] ) {
case V_49 :
V_24 = F_15 ( V_27 ) ;
V_2 -> V_23 = F_20 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_54 :
V_24 = F_16 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_55 :
V_24 = F_17 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_56 :
V_24 = F_18 ( V_27 ) ;
V_2 -> V_23 = F_22 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_57 :
V_24 = F_15 ( V_27 ) ;
V_2 -> V_23 = F_20 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_58 :
case V_59 :
V_24 = F_16 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
if ( V_27 [ 1 ] & 0x8 )
V_2 -> V_50 |= V_60 ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_61 :
V_24 = F_17 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
if ( V_27 [ 1 ] & 0x8 )
V_2 -> V_50 |= V_60 ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_62 :
V_24 = F_18 ( V_27 ) ;
V_2 -> V_23 = F_22 ( V_27 ) ;
if ( V_27 [ 1 ] & 0x8 )
V_2 -> V_50 |= V_60 ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
break;
case V_63 :
if ( ( V_2 -> V_64 != V_65 ) ||
! ( V_2 -> V_50 & V_66 ) )
goto V_67;
V_24 = F_16 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
V_2 -> V_68 = & F_25 ;
if ( V_27 [ 1 ] & 0x8 )
V_2 -> V_50 |= V_60 ;
break;
case V_69 :
{
T_2 V_70 = F_8 ( & V_27 [ 8 ] ) ;
switch ( V_70 ) {
case V_71 :
V_24 = F_19 ( V_27 ) ;
V_2 -> V_23 = F_23 ( V_27 ) ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = V_44 -> V_53 ;
V_2 -> V_68 = & F_25 ;
if ( V_27 [ 1 ] & 0x8 )
V_2 -> V_50 |= V_60 ;
break;
case V_72 :
if ( ! V_44 -> V_73 )
goto V_74;
V_24 = F_19 ( V_27 ) ;
if ( ! V_24 ) {
F_14 ( L_8
L_9 ) ;
goto V_67;
}
V_47 = F_12 ( V_2 , 1 ) ;
V_2 -> V_23 = F_34 ( & V_27 [ 12 ] ) ;
if ( F_24 ( V_4 , & V_27 [ 10 ] ) < 0 )
goto V_74;
V_2 -> V_52 = V_44 -> V_73 ;
break;
default:
F_14 ( L_10
L_11 , V_70 ) ;
goto V_74;
}
break;
}
case V_75 :
V_47 = V_76 ;
V_2 -> V_52 = F_1 ;
break;
case V_77 :
switch ( V_2 -> V_20 [ 1 ] & 0x1f ) {
case V_78 :
V_2 -> V_52 = F_6 ;
break;
default:
F_14 ( L_12 ,
V_2 -> V_20 [ 1 ] & 0x1f ) ;
goto V_67;
}
V_47 = ( V_27 [ 10 ] << 24 ) | ( V_27 [ 11 ] << 16 ) |
( V_27 [ 12 ] << 8 ) | V_27 [ 13 ] ;
break;
case V_79 :
case V_80 :
if ( ! V_44 -> V_81 )
goto V_74;
if ( V_27 [ 0 ] == V_79 ) {
V_24 = F_16 ( V_27 ) ;
V_2 -> V_23 = F_21 ( V_27 ) ;
} else {
V_24 = F_18 ( V_27 ) ;
V_2 -> V_23 = F_22 ( V_27 ) ;
}
V_47 = F_12 ( V_2 , V_24 ) ;
if ( V_2 -> V_23 || V_24 ) {
if ( F_13 ( V_2 ) < 0 )
goto V_67;
}
V_2 -> V_52 = V_44 -> V_81 ;
break;
case V_82 :
if ( ! V_44 -> V_83 )
goto V_74;
V_47 = F_8 ( & V_27 [ 7 ] ) ;
V_2 -> V_52 = V_44 -> V_83 ;
break;
case V_22 :
if ( ! V_44 -> V_73 )
goto V_74;
V_24 = F_18 ( V_27 ) ;
if ( ! V_24 ) {
F_14 ( L_13 ) ;
goto V_67;
}
V_47 = F_12 ( V_2 , 1 ) ;
V_2 -> V_23 = F_34 ( & V_27 [ 2 ] ) ;
if ( F_24 ( V_4 , & V_27 [ 1 ] ) < 0 )
goto V_74;
V_2 -> V_52 = V_44 -> V_73 ;
break;
case V_21 :
if ( ! V_44 -> V_73 )
goto V_74;
V_24 = F_16 ( V_27 ) ;
if ( ! V_24 ) {
F_14 ( L_13 ) ;
goto V_67;
}
V_47 = F_12 ( V_2 , 1 ) ;
V_2 -> V_23 = F_9 ( & V_27 [ 2 ] ) ;
if ( F_24 ( V_4 , & V_27 [ 1 ] ) < 0 )
goto V_74;
V_2 -> V_52 = V_44 -> V_73 ;
break;
case V_84 :
V_47 = 0 ;
V_2 -> V_52 = F_10 ;
break;
case V_85 :
case V_86 :
case V_87 :
V_47 = 0 ;
V_2 -> V_52 = F_11 ;
break;
default:
V_48 = F_35 ( V_2 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( ! ( V_2 -> V_50 & V_51 ) && ! V_2 -> V_52 )
goto V_74;
if ( V_2 -> V_50 & V_51 ) {
unsigned long long V_25 ;
if ( V_24 > V_46 -> V_13 . V_88 ) {
F_36 ( V_89 L_14
L_15
L_16 , V_27 [ 0 ] , V_24 ,
V_46 -> V_13 . V_88 ) ;
goto V_67;
}
if ( V_24 > V_46 -> V_13 . V_90 ) {
F_36 ( V_89 L_14
L_17
L_16 , V_27 [ 0 ] , V_24 ,
V_46 -> V_13 . V_90 ) ;
goto V_67;
}
V_25 = V_4 -> V_7 -> V_8 ( V_4 ) + 1 ;
if ( V_2 -> V_23 + V_24 > V_25 ) {
F_14 ( L_18
L_19 ,
V_25 , V_2 -> V_23 , V_24 ) ;
goto V_67;
}
V_47 = F_12 ( V_2 , V_24 ) ;
}
V_48 = F_37 ( V_2 , V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
V_74:
V_2 -> V_50 |= V_91 ;
V_2 -> V_92 = V_93 ;
return - V_26 ;
V_67:
V_2 -> V_50 |= V_91 ;
V_2 -> V_92 = V_94 ;
return - V_26 ;
}
