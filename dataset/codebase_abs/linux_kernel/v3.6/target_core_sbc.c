static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 ;
unsigned long long V_7 = V_4 -> V_8 -> V_9 ( V_4 ) ;
T_1 V_10 ;
if ( V_7 >= 0x00000000ffffffff )
V_10 = 0xffffffff ;
else
V_10 = ( T_1 ) V_7 ;
V_6 = F_2 ( V_2 ) ;
V_6 [ 0 ] = ( V_10 >> 24 ) & 0xff ;
V_6 [ 1 ] = ( V_10 >> 16 ) & 0xff ;
V_6 [ 2 ] = ( V_10 >> 8 ) & 0xff ;
V_6 [ 3 ] = V_10 & 0xff ;
V_6 [ 4 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 24 ) & 0xff ;
V_6 [ 5 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 16 ) & 0xff ;
V_6 [ 6 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 8 ) & 0xff ;
V_6 [ 7 ] = V_4 -> V_11 -> V_12 . V_13 & 0xff ;
F_3 ( V_2 ) ;
F_4 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 ;
unsigned long long V_10 = V_4 -> V_8 -> V_9 ( V_4 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 [ 0 ] = ( V_10 >> 56 ) & 0xff ;
V_6 [ 1 ] = ( V_10 >> 48 ) & 0xff ;
V_6 [ 2 ] = ( V_10 >> 40 ) & 0xff ;
V_6 [ 3 ] = ( V_10 >> 32 ) & 0xff ;
V_6 [ 4 ] = ( V_10 >> 24 ) & 0xff ;
V_6 [ 5 ] = ( V_10 >> 16 ) & 0xff ;
V_6 [ 6 ] = ( V_10 >> 8 ) & 0xff ;
V_6 [ 7 ] = V_10 & 0xff ;
V_6 [ 8 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 24 ) & 0xff ;
V_6 [ 9 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 16 ) & 0xff ;
V_6 [ 10 ] = ( V_4 -> V_11 -> V_12 . V_13 >> 8 ) & 0xff ;
V_6 [ 11 ] = V_4 -> V_11 -> V_12 . V_13 & 0xff ;
if ( V_4 -> V_11 -> V_12 . V_15 || V_4 -> V_11 -> V_12 . V_16 )
V_6 [ 14 ] = 0x80 ;
F_3 ( V_2 ) ;
F_4 ( V_2 , V_14 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_17 ;
if ( V_2 -> V_18 [ 0 ] == V_19 )
V_17 = F_7 ( & V_2 -> V_18 [ 7 ] ) ;
else if ( V_2 -> V_18 [ 0 ] == V_20 )
V_17 = F_8 ( & V_2 -> V_18 [ 10 ] ) ;
else
V_17 = F_8 ( & V_2 -> V_18 [ 28 ] ) ;
if ( V_17 )
return V_17 ;
return V_2 -> V_5 -> V_8 -> V_9 ( V_2 -> V_5 ) -
V_2 -> V_21 + 1 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_14 ) ;
return 0 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , T_1 V_22 )
{
return V_2 -> V_5 -> V_11 -> V_12 . V_13 * V_22 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_23 ;
T_1 V_22 ;
V_22 = V_2 -> V_24 / V_4 -> V_11 -> V_12 . V_13 ;
V_23 = V_4 -> V_8 -> V_9 ( V_4 ) + 1 ;
if ( V_2 -> V_21 + V_22 > V_23 ) {
F_12 ( L_1 ,
V_2 -> V_21 , V_22 , V_23 ) ;
return - V_25 ;
}
return 0 ;
}
static inline T_1 F_13 ( unsigned char * V_26 )
{
return V_26 [ 4 ] ? : 256 ;
}
static inline T_1 F_14 ( unsigned char * V_26 )
{
return ( T_1 ) ( V_26 [ 7 ] << 8 ) + V_26 [ 8 ] ;
}
static inline T_1 F_15 ( unsigned char * V_26 )
{
return ( T_1 ) ( V_26 [ 6 ] << 24 ) + ( V_26 [ 7 ] << 16 ) + ( V_26 [ 8 ] << 8 ) + V_26 [ 9 ] ;
}
static inline T_1 F_16 ( unsigned char * V_26 )
{
return ( T_1 ) ( V_26 [ 10 ] << 24 ) + ( V_26 [ 11 ] << 16 ) +
( V_26 [ 12 ] << 8 ) + V_26 [ 13 ] ;
}
static inline T_1 F_17 ( unsigned char * V_26 )
{
return ( T_1 ) ( V_26 [ 28 ] << 24 ) + ( V_26 [ 29 ] << 16 ) +
( V_26 [ 30 ] << 8 ) + V_26 [ 31 ] ;
}
static inline T_1 F_18 ( unsigned char * V_26 )
{
return ( ( V_26 [ 1 ] & 0x1f ) << 16 ) | ( V_26 [ 2 ] << 8 ) | V_26 [ 3 ] ;
}
static inline T_1 F_19 ( unsigned char * V_26 )
{
return ( V_26 [ 2 ] << 24 ) | ( V_26 [ 3 ] << 16 ) | ( V_26 [ 4 ] << 8 ) | V_26 [ 5 ] ;
}
static inline unsigned long long F_20 ( unsigned char * V_26 )
{
unsigned int V_27 , V_28 ;
V_27 = ( V_26 [ 2 ] << 24 ) | ( V_26 [ 3 ] << 16 ) | ( V_26 [ 4 ] << 8 ) | V_26 [ 5 ] ;
V_28 = ( V_26 [ 6 ] << 24 ) | ( V_26 [ 7 ] << 16 ) | ( V_26 [ 8 ] << 8 ) | V_26 [ 9 ] ;
return ( ( unsigned long long ) V_28 ) | ( unsigned long long ) V_27 << 32 ;
}
static inline unsigned long long F_21 ( unsigned char * V_26 )
{
unsigned int V_27 , V_28 ;
V_27 = ( V_26 [ 12 ] << 24 ) | ( V_26 [ 13 ] << 16 ) | ( V_26 [ 14 ] << 8 ) | V_26 [ 15 ] ;
V_28 = ( V_26 [ 16 ] << 24 ) | ( V_26 [ 17 ] << 16 ) | ( V_26 [ 18 ] << 8 ) | V_26 [ 19 ] ;
return ( ( unsigned long long ) V_28 ) | ( unsigned long long ) V_27 << 32 ;
}
static int F_22 ( struct V_3 * V_4 ,
unsigned char * V_29 )
{
if ( ( V_29 [ 0 ] & 0x04 ) || ( V_29 [ 0 ] & 0x02 ) ) {
F_12 ( L_2
L_3
L_4 ) ;
return - V_30 ;
}
if ( ! ( V_29 [ 0 ] & 0x08 ) ) {
F_12 ( L_5
L_6 ) ;
return - V_30 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned char * V_6 , * V_31 ;
struct V_32 * V_33 ;
unsigned int V_34 ;
int V_35 ;
int V_36 ;
V_6 = F_24 ( V_2 -> V_24 , V_37 ) ;
if ( ! V_6 ) {
F_12 ( L_7 ) ;
return;
}
F_25 ( V_2 -> V_38 ,
V_2 -> V_39 ,
V_6 ,
V_2 -> V_24 ) ;
V_34 = 0 ;
F_26 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_31 = F_27 ( F_28 ( V_33 ) ) ;
if ( ! V_31 )
goto V_40;
for ( V_35 = 0 ; V_35 < V_33 -> V_41 ; V_35 ++ )
* ( V_31 + V_33 -> V_34 + V_35 ) ^= * ( V_6 + V_34 + V_35 ) ;
V_34 += V_33 -> V_41 ;
F_29 ( V_31 ) ;
}
V_40:
F_30 ( V_6 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_44 * V_45 = V_2 -> V_5 -> V_11 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_26 = V_2 -> V_18 ;
unsigned int V_46 ;
T_1 V_22 = 0 ;
int V_47 ;
switch ( V_26 [ 0 ] ) {
case V_48 :
V_22 = F_13 ( V_26 ) ;
V_2 -> V_21 = F_18 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_53 :
V_22 = F_14 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_54 :
V_22 = F_15 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_55 :
V_22 = F_16 ( V_26 ) ;
V_2 -> V_21 = F_20 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_56 :
V_22 = F_13 ( V_26 ) ;
V_2 -> V_21 = F_18 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_57 :
case V_58 :
V_22 = F_14 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_49 |= V_59 ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_60 :
V_22 = F_15 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_49 |= V_59 ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_61 :
V_22 = F_16 ( V_26 ) ;
V_2 -> V_21 = F_20 ( V_26 ) ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_49 |= V_59 ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
break;
case V_62 :
if ( ( V_2 -> V_63 != V_64 ) ||
! ( V_2 -> V_49 & V_65 ) )
goto V_66;
V_22 = F_14 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
V_2 -> V_67 = & F_23 ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_49 |= V_59 ;
break;
case V_68 :
{
T_2 V_69 = F_7 ( & V_26 [ 8 ] ) ;
switch ( V_69 ) {
case V_70 :
V_22 = F_17 ( V_26 ) ;
V_2 -> V_21 = F_21 ( V_26 ) ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = V_43 -> V_52 ;
V_2 -> V_67 = & F_23 ;
if ( V_26 [ 1 ] & 0x8 )
V_2 -> V_49 |= V_59 ;
break;
case V_71 :
if ( ! V_43 -> V_72 )
goto V_73;
V_22 = F_17 ( V_26 ) ;
if ( ! V_22 ) {
F_12 ( L_8
L_9 ) ;
goto V_66;
}
V_46 = F_10 ( V_2 , 1 ) ;
V_2 -> V_21 = F_32 ( & V_26 [ 12 ] ) ;
if ( F_22 ( V_4 , & V_26 [ 10 ] ) < 0 )
goto V_73;
V_2 -> V_51 = V_43 -> V_72 ;
break;
default:
F_12 ( L_10
L_11 , V_69 ) ;
goto V_73;
}
break;
}
case V_74 :
V_46 = V_75 ;
V_2 -> V_51 = F_1 ;
break;
case V_76 :
switch ( V_2 -> V_18 [ 1 ] & 0x1f ) {
case V_77 :
V_2 -> V_51 = F_5 ;
break;
default:
F_12 ( L_12 ,
V_2 -> V_18 [ 1 ] & 0x1f ) ;
goto V_66;
}
V_46 = ( V_26 [ 10 ] << 24 ) | ( V_26 [ 11 ] << 16 ) |
( V_26 [ 12 ] << 8 ) | V_26 [ 13 ] ;
break;
case V_78 :
case V_79 :
if ( ! V_43 -> V_80 )
goto V_73;
if ( V_26 [ 0 ] == V_78 ) {
V_22 = F_14 ( V_26 ) ;
V_2 -> V_21 = F_19 ( V_26 ) ;
} else {
V_22 = F_16 ( V_26 ) ;
V_2 -> V_21 = F_20 ( V_26 ) ;
}
V_46 = F_10 ( V_2 , V_22 ) ;
if ( V_2 -> V_21 || V_22 ) {
if ( F_11 ( V_2 ) < 0 )
goto V_66;
}
V_2 -> V_51 = V_43 -> V_80 ;
break;
case V_81 :
if ( ! V_43 -> V_82 )
goto V_73;
V_46 = F_7 ( & V_26 [ 7 ] ) ;
V_2 -> V_51 = V_43 -> V_82 ;
break;
case V_20 :
if ( ! V_43 -> V_72 )
goto V_73;
V_22 = F_16 ( V_26 ) ;
if ( ! V_22 ) {
F_12 ( L_13 ) ;
goto V_66;
}
V_46 = F_10 ( V_2 , 1 ) ;
V_2 -> V_21 = F_32 ( & V_26 [ 2 ] ) ;
if ( F_22 ( V_4 , & V_26 [ 1 ] ) < 0 )
goto V_73;
V_2 -> V_51 = V_43 -> V_72 ;
break;
case V_19 :
if ( ! V_43 -> V_72 )
goto V_73;
V_22 = F_14 ( V_26 ) ;
if ( ! V_22 ) {
F_12 ( L_13 ) ;
goto V_66;
}
V_46 = F_10 ( V_2 , 1 ) ;
V_2 -> V_21 = F_8 ( & V_26 [ 2 ] ) ;
if ( F_22 ( V_4 , & V_26 [ 1 ] ) < 0 )
goto V_73;
V_2 -> V_51 = V_43 -> V_72 ;
break;
case V_83 :
V_46 = 0 ;
V_2 -> V_51 = F_9 ;
break;
default:
V_47 = F_33 ( V_2 , & V_46 ) ;
if ( V_47 )
return V_47 ;
}
if ( ! ( V_2 -> V_49 & V_50 ) && ! V_2 -> V_51 )
goto V_73;
if ( V_2 -> V_49 & V_50 ) {
unsigned long long V_23 ;
if ( V_22 > V_45 -> V_12 . V_84 ) {
F_34 ( V_85 L_14
L_15
L_16 , V_26 [ 0 ] , V_22 ,
V_45 -> V_12 . V_84 ) ;
goto V_66;
}
if ( V_22 > V_45 -> V_12 . V_86 ) {
F_34 ( V_85 L_14
L_17
L_16 , V_26 [ 0 ] , V_22 ,
V_45 -> V_12 . V_86 ) ;
goto V_66;
}
V_23 = V_4 -> V_8 -> V_9 ( V_4 ) + 1 ;
if ( V_2 -> V_21 + V_22 > V_23 ) {
F_12 ( L_18
L_19 ,
V_23 , V_2 -> V_21 , V_22 ) ;
goto V_66;
}
V_46 = F_10 ( V_2 , V_22 ) ;
}
V_47 = F_35 ( V_2 , V_46 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
V_73:
V_2 -> V_49 |= V_87 ;
V_2 -> V_88 = V_89 ;
return - V_25 ;
V_66:
V_2 -> V_49 |= V_87 ;
V_2 -> V_88 = V_90 ;
return - V_25 ;
}
