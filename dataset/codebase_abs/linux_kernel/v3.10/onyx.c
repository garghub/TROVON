static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 * V_3 )
{
T_2 V_4 ;
if ( V_2 != V_5 ) {
* V_3 = V_1 -> V_6 [ V_2 - V_7 ] ;
return 0 ;
}
V_4 = F_2 ( V_1 -> V_8 , V_2 ) ;
if ( V_4 < 0 )
return - 1 ;
* V_3 = ( T_1 ) V_4 ;
V_1 -> V_6 [ V_5 - V_7 ] = * V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_9 ;
V_9 = F_4 ( V_1 -> V_8 , V_2 , V_3 ) ;
if ( ! V_9 )
V_1 -> V_6 [ V_2 - V_7 ] = V_3 ;
return V_9 ;
}
static int F_5 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_15 -> type = V_16 ;
V_15 -> V_17 = 2 ;
V_15 -> V_3 . integer . V_18 = - 128 + V_19 ;
V_15 -> V_3 . integer . V_20 = - 1 + V_19 ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_3 V_23 , V_24 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_26 , & V_23 ) ;
F_1 ( V_1 , V_27 , & V_24 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] = V_23 + V_19 ;
V_22 -> V_3 . integer . V_3 [ 1 ] = V_24 + V_19 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_3 V_23 , V_24 ;
if ( V_22 -> V_3 . integer . V_3 [ 0 ] < - 128 + V_19 ||
V_22 -> V_3 . integer . V_3 [ 0 ] > - 1 + V_19 )
return - V_28 ;
if ( V_22 -> V_3 . integer . V_3 [ 1 ] < - 128 + V_19 ||
V_22 -> V_3 . integer . V_3 [ 1 ] > - 1 + V_19 )
return - V_28 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_26 , & V_23 ) ;
F_1 ( V_1 , V_27 , & V_24 ) ;
if ( V_23 + V_19 == V_22 -> V_3 . integer . V_3 [ 0 ] &&
V_24 + V_19 == V_22 -> V_3 . integer . V_3 [ 1 ] ) {
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
F_3 ( V_1 , V_26 ,
V_22 -> V_3 . integer . V_3 [ 0 ]
- V_19 ) ;
F_3 ( V_1 , V_27 ,
V_22 -> V_3 . integer . V_3 [ 1 ]
- V_19 ) ;
F_10 ( & V_1 -> V_25 ) ;
return 1 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_15 -> type = V_16 ;
V_15 -> V_17 = 1 ;
V_15 -> V_3 . integer . V_18 = 3 + V_29 ;
V_15 -> V_3 . integer . V_20 = 28 + V_29 ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_30 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_30 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] =
( V_30 & V_32 ) + V_29 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 , V_33 ;
if ( V_22 -> V_3 . integer . V_3 [ 0 ] < 3 + V_29 ||
V_22 -> V_3 . integer . V_3 [ 0 ] > 28 + V_29 )
return - V_28 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_4 ) ;
V_33 = V_4 ;
V_33 &= ~ V_32 ;
V_33 |= ( V_22 -> V_3 . integer . V_3 [ 0 ] - V_29 )
& V_32 ;
F_3 ( V_1 , V_31 , V_33 ) ;
F_10 ( & V_1 -> V_25 ) ;
return V_33 != V_4 ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
static char * V_34 [] = { L_1 , L_2 } ;
V_15 -> type = V_35 ;
V_15 -> V_17 = 1 ;
V_15 -> V_3 . V_36 . V_37 = 2 ;
if ( V_15 -> V_3 . V_36 . V_38 > 1 )
V_15 -> V_3 . V_36 . V_38 = 1 ;
strcpy ( V_15 -> V_3 . V_36 . V_39 , V_34 [ V_15 -> V_3 . V_36 . V_38 ] ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_3 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . V_36 . V_38 [ 0 ] = ! ! ( V_4 & V_40 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_1 , int V_41 )
{
T_3 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_4 ) ;
V_4 &= ~ V_40 ;
if ( V_41 )
V_4 |= V_40 ;
F_3 ( V_1 , V_31 , V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_3 . V_36 . V_38 [ 0 ] > 1 )
return - V_28 ;
F_17 ( F_8 ( V_13 ) ,
V_22 -> V_3 . V_36 . V_38 [ 0 ] ) ;
return 1 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_42 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_43 , & V_42 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] = ! ( V_42 & V_44 ) ;
V_22 -> V_3 . integer . V_3 [ 1 ] = ! ( V_42 & V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 = 0 , V_42 = 0 ;
int V_46 = - V_47 ;
F_9 ( & V_1 -> V_25 ) ;
if ( V_1 -> V_48 )
goto V_49;
F_1 ( V_1 , V_43 , & V_4 ) ;
V_42 = V_4 ;
V_42 &= ~ ( V_45 | V_44 ) ;
if ( ! V_22 -> V_3 . integer . V_3 [ 0 ] )
V_42 |= V_44 ;
if ( ! V_22 -> V_3 . integer . V_3 [ 1 ] )
V_42 |= V_45 ;
V_46 = F_3 ( V_1 , V_43 , V_42 ) ;
V_49:
F_10 ( & V_1 -> V_25 ) ;
return ! V_46 ? ( V_4 != V_42 ) : V_46 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_42 ;
long int V_50 = V_13 -> V_51 ;
T_1 V_52 = ( V_50 >> 16 ) & V_53 ;
T_1 V_54 = ( V_50 >> 8 ) & 0xff ;
T_1 V_55 = V_50 & 0xff ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_54 , & V_42 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] = ! ! ( V_42 & V_55 ) ^ V_52 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 = 0 , V_42 = 0 ;
int V_46 ;
long int V_50 = V_13 -> V_51 ;
T_1 V_52 = ( V_50 >> 16 ) & V_53 ;
T_1 V_56 = ( V_50 >> 16 ) & V_57 ;
T_1 V_54 = ( V_50 >> 8 ) & 0xff ;
T_1 V_55 = V_50 & 0xff ;
F_9 ( & V_1 -> V_25 ) ;
if ( V_56 && V_1 -> V_58 ) {
V_46 = - V_47 ;
goto V_49;
}
F_1 ( V_1 , V_54 , & V_4 ) ;
V_42 = V_4 ;
V_42 &= ~ ( V_55 ) ;
if ( ! ! V_22 -> V_3 . integer . V_3 [ 0 ] ^ V_52 )
V_42 |= V_55 ;
V_46 = F_3 ( V_1 , V_54 , V_42 ) ;
V_49:
F_10 ( & V_1 -> V_25 ) ;
return ! V_46 ? ( V_4 != V_42 ) : V_46 ;
}
static int F_23 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_15 -> type = V_59 ;
V_15 -> V_17 = 1 ;
return 0 ;
}
static int F_24 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
V_22 -> V_3 . V_60 . V_61 [ 0 ] = 0x3e ;
V_22 -> V_3 . V_60 . V_61 [ 1 ] = 0xff ;
V_22 -> V_3 . V_60 . V_61 [ 3 ] = 0x3f ;
V_22 -> V_3 . V_60 . V_61 [ 4 ] = 0x0f ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_62 , & V_4 ) ;
V_22 -> V_3 . V_60 . V_61 [ 0 ] = V_4 & 0x3e ;
F_1 ( V_1 , V_63 , & V_4 ) ;
V_22 -> V_3 . V_60 . V_61 [ 1 ] = V_4 ;
F_1 ( V_1 , V_64 , & V_4 ) ;
V_22 -> V_3 . V_60 . V_61 [ 3 ] = V_4 & 0x3f ;
F_1 ( V_1 , V_65 , & V_4 ) ;
V_22 -> V_3 . V_60 . V_61 [ 4 ] = V_4 & 0x0f ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_62 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x3e ) | ( V_22 -> V_3 . V_60 . V_61 [ 0 ] & 0x3e ) ;
F_3 ( V_1 , V_62 , V_4 ) ;
V_4 = V_22 -> V_3 . V_60 . V_61 [ 1 ] ;
F_3 ( V_1 , V_63 , V_4 ) ;
F_1 ( V_1 , V_64 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x3f ) | ( V_22 -> V_3 . V_60 . V_61 [ 3 ] & 0x3f ) ;
F_3 ( V_1 , V_64 , V_4 ) ;
F_1 ( V_1 , V_65 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x0f ) | ( V_22 -> V_3 . V_60 . V_61 [ 4 ] & 0x0f ) ;
F_3 ( V_1 , V_65 , V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_66 ;
T_1 V_67 ;
T_1 V_68 [ sizeof( V_69 ) ] ;
if ( ! V_1 -> V_70 ) {
memcpy ( V_68 , V_69 , sizeof( V_69 ) ) ;
if ( F_1 ( V_1 , V_5 , & V_67 ) )
return - 1 ;
V_67 &= ~ V_71 ;
V_67 |= V_69 [ 3 ] ;
V_68 [ 3 ] = V_67 ;
} else {
for ( V_66 = 0 ; V_66 < sizeof( V_72 ) ; V_66 ++ )
V_68 [ V_66 ] = V_1 -> V_6 [ V_72 [ V_66 ] - V_7 ] ;
}
for ( V_66 = 0 ; V_66 < sizeof( V_72 ) ; V_66 ++ ) {
if ( F_3 ( V_1 , V_72 [ V_66 ] , V_68 [ V_66 ] ) )
return - 1 ;
}
V_1 -> V_70 = 1 ;
return 0 ;
}
static int F_28 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_75 * V_77 )
{
T_1 V_4 ;
struct V_1 * V_1 = V_74 -> V_78 ;
int V_79 , V_80 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_65 , & V_4 ) ;
V_79 = ! ! ( V_4 & V_81 ) ;
F_1 ( V_1 , V_43 , & V_4 ) ;
V_80 =
( V_4 & ( V_45 | V_44 ) )
!= ( V_45 | V_44 ) ;
F_10 ( & V_1 -> V_25 ) ;
switch ( V_76 -> V_82 ) {
case 0 : return 1 ;
case 1 : return V_80 ;
case 2 : return V_79 ;
}
return 1 ;
}
static int F_29 ( struct V_73 * V_74 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
T_1 V_4 ;
struct V_1 * V_1 = V_74 -> V_78 ;
int V_46 = - V_47 ;
F_9 ( & V_1 -> V_25 ) ;
#ifdef F_30
if ( V_86 -> V_87 -> V_88 == F_30 ) {
F_1 ( V_1 , V_43 , & V_4 ) ;
if ( F_3 ( V_1 ,
V_43 ,
V_4 | V_45 | V_44 ) )
goto V_49;
V_1 -> V_48 = 1 ;
V_46 = 0 ;
goto V_49;
}
#endif
switch ( V_86 -> V_87 -> V_89 ) {
case 32000 :
case 44100 :
case 48000 :
V_46 = 0 ;
goto V_49;
default:
F_1 ( V_74 -> V_78 , V_65 , & V_4 ) ;
if ( F_3 ( V_1 ,
V_65 ,
V_4 & ~ V_81 ) )
goto V_49;
V_1 -> V_58 = 1 ;
V_46 = 0 ;
goto V_49;
}
V_49:
F_10 ( & V_1 -> V_25 ) ;
return V_46 ;
}
static int F_31 ( struct V_73 * V_74 ,
struct V_85 * V_86 )
{
struct V_1 * V_1 = V_74 -> V_78 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_90 ++ ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_32 ( struct V_73 * V_74 ,
struct V_85 * V_86 )
{
struct V_1 * V_1 = V_74 -> V_78 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_90 -- ;
if ( ! V_1 -> V_90 )
V_1 -> V_58 = V_1 -> V_48 = 0 ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_33 ( struct V_73 * V_74 ,
enum V_91 V_92 )
{
struct V_1 * V_1 = V_74 -> V_78 ;
F_9 ( & V_1 -> V_25 ) ;
switch ( V_92 ) {
case V_93 :
V_1 -> V_94 . V_95 -> V_96 -> V_97 ( V_1 -> V_94 . V_95 ) ;
break;
case V_98 :
V_1 -> V_94 . V_95 -> V_96 -> V_99 ( V_1 -> V_94 . V_95 ) ;
break;
default:
break;
}
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_34 ( struct V_73 * V_74 , T_4 V_100 )
{
struct V_1 * V_1 = V_74 -> V_78 ;
T_1 V_4 ;
int V_46 = - V_101 ;
F_9 ( & V_1 -> V_25 ) ;
if ( F_1 ( V_1 , V_5 , & V_4 ) )
goto V_49;
F_3 ( V_1 , V_5 , V_4 | V_102 | V_103 ) ;
V_46 = 0 ;
V_49:
F_10 ( & V_1 -> V_25 ) ;
return V_46 ;
}
static int F_35 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = V_74 -> V_78 ;
T_1 V_4 ;
int V_46 = - V_101 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 0 ) ;
F_36 ( 1 ) ;
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 1 ) ;
F_36 ( 1 ) ;
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 0 ) ;
F_36 ( 1 ) ;
if ( F_1 ( V_1 , V_5 , & V_4 ) )
goto V_49;
F_3 ( V_1 , V_5 , V_4 & ~ ( V_102 | V_103 ) ) ;
F_36 ( 2205000 / 8000 ) ;
F_27 ( V_1 ) ;
V_46 = 0 ;
V_49:
F_10 ( & V_1 -> V_25 ) ;
return V_46 ;
}
static int F_37 ( struct V_105 * V_94 )
{
struct V_1 * V_1 = F_38 ( V_94 ) ;
struct V_12 * V_106 ;
struct V_107 * V_108 = & V_109 ;
T_1 V_4 ;
int V_46 ;
if ( ! V_1 -> V_94 . V_95 || ! V_1 -> V_94 . V_95 -> V_96 ) {
F_39 (KERN_ERR PFX L_3 ) ;
return - V_28 ;
}
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 0 ) ;
F_36 ( 1 ) ;
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 1 ) ;
F_36 ( 1 ) ;
V_1 -> V_94 . V_95 -> V_96 -> V_104 ( V_1 -> V_94 . V_95 , 0 ) ;
F_36 ( 1 ) ;
if ( F_27 ( V_1 ) ) {
F_39 (KERN_ERR PFX L_4 ) ;
return - V_110 ;
}
if ( F_40 ( V_111 , V_1 , & V_112 ) ) {
F_39 (KERN_ERR PFX L_5 ) ;
return - V_110 ;
}
if ( ( V_1 -> V_94 . V_113 & 0xF ) == 0 )
return - V_114 ;
if ( ( V_1 -> V_94 . V_113 & 0xC ) == 0 ) {
if ( ! V_1 -> V_107 )
V_1 -> V_107 = F_41 ( sizeof( struct V_107 ) , V_115 ) ;
if ( ! V_1 -> V_107 )
return - V_116 ;
V_108 = V_1 -> V_107 ;
* V_108 = V_109 ;
V_108 -> V_117 ++ ;
}
if ( ( V_1 -> V_94 . V_113 & 3 ) == 0 ) {
if ( ! V_1 -> V_107 )
V_1 -> V_107 = F_41 ( sizeof( struct V_107 ) , V_115 ) ;
if ( ! V_1 -> V_107 )
return - V_116 ;
V_108 = V_1 -> V_107 ;
* V_108 = V_109 ;
V_108 -> V_117 [ 1 ] . V_118 = 0 ;
}
if ( V_1 -> V_94 . V_119 -> V_120 ( V_1 -> V_94 . V_119 ,
F_42 () ,
V_108 , V_1 ) ) {
F_39 (KERN_ERR PFX L_6 ) ;
return - V_110 ;
}
#define F_43 ( V_33 ) \
do { \
ctl = snd_ctl_new1(&n, onyx); \
if (ctl) { \
ctl->id.device = \
onyx->codec.soundbus_dev->pcm->device; \
err = aoa_snd_ctl_add(ctl); \
if (err) \
goto error; \
} \
} while (0)
if ( V_1 -> V_94 . V_119 -> V_121 ) {
if ( ( V_1 -> V_94 . V_113 & 0xC ) == 0xC )
F_43 ( V_122 ) ;
else if ( V_1 -> V_94 . V_113 & 4 )
F_17 ( V_1 , 0 ) ;
else
F_17 ( V_1 , 1 ) ;
if ( V_1 -> V_94 . V_113 & 0xC )
F_43 ( V_123 ) ;
if ( V_1 -> V_94 . V_113 & 1 ) {
F_43 ( V_124 ) ;
F_43 ( V_125 ) ;
F_43 ( V_126 ) ;
F_43 ( V_127 ) ;
F_43 ( V_128 ) ;
F_43 ( V_129 ) ;
}
if ( V_1 -> V_94 . V_113 & 2 ) {
F_43 ( V_130 ) ;
F_43 ( V_131 ) ;
}
if ( ( V_1 -> V_94 . V_113 & 3 ) == 3 )
F_43 ( V_132 ) ;
if ( ( V_1 -> V_94 . V_113 & 3 ) == 2 ) {
F_1 ( V_1 , V_65 , & V_4 ) ;
V_4 |= V_81 ;
F_3 ( V_1 , V_65 , V_4 ) ;
}
}
#undef F_43
F_39 (KERN_INFO PFX L_7 ) ;
return 0 ;
error:
V_1 -> V_94 . V_119 -> V_133 ( V_1 -> V_94 . V_119 , V_1 ) ;
F_44 ( F_42 () , V_1 ) ;
return V_46 ;
}
static void F_45 ( struct V_105 * V_94 )
{
struct V_1 * V_1 = F_38 ( V_94 ) ;
if ( ! V_1 -> V_94 . V_119 ) {
F_39 (KERN_ERR PFX L_8 ) ;
return;
}
V_1 -> V_94 . V_119 -> V_133 ( V_1 -> V_94 . V_119 , V_1 ) ;
}
static int F_46 ( struct V_134 * V_135 ,
const struct V_136 * V_137 )
{
struct V_138 * V_139 = V_135 -> V_11 . V_140 ;
struct V_1 * V_1 ;
T_1 V_141 ;
V_1 = F_47 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_1 )
return - V_116 ;
F_48 ( & V_1 -> V_25 ) ;
V_1 -> V_8 = V_135 ;
F_49 ( V_135 , V_1 ) ;
if ( F_1 ( V_1 , V_5 , & V_141 ) != 0 ) {
F_39 (KERN_ERR PFX L_9 ) ;
goto V_142;
}
F_50 ( V_1 -> V_94 . V_39 , L_10 , V_143 ) ;
V_1 -> V_94 . V_144 = V_145 ;
V_1 -> V_94 . V_146 = F_37 ;
V_1 -> V_94 . exit = F_45 ;
V_1 -> V_94 . V_139 = F_51 ( V_139 ) ;
if ( F_52 ( & V_1 -> V_94 ) ) {
goto V_142;
}
F_39 (KERN_DEBUG PFX L_11 ) ;
return 0 ;
V_142:
F_53 ( V_1 ) ;
return - V_110 ;
}
static int F_54 ( struct V_134 * V_135 )
{
struct V_1 * V_1 = F_55 ( V_135 ) ;
F_56 ( & V_1 -> V_94 ) ;
F_57 ( V_1 -> V_94 . V_139 ) ;
F_53 ( V_1 -> V_107 ) ;
F_53 ( V_1 ) ;
return 0 ;
}
