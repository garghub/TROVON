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
static const char * const V_34 [] = { L_1 , L_2 } ;
return F_16 ( V_15 , 1 , 2 , V_34 ) ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_3 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . V_35 . V_36 [ 0 ] = ! ! ( V_4 & V_37 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_1 , int V_38 )
{
T_3 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_31 , & V_4 ) ;
V_4 &= ~ V_37 ;
if ( V_38 )
V_4 |= V_37 ;
F_3 ( V_1 , V_31 , V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_3 . V_35 . V_36 [ 0 ] > 1 )
return - V_28 ;
F_18 ( F_8 ( V_13 ) ,
V_22 -> V_3 . V_35 . V_36 [ 0 ] ) ;
return 1 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_39 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_40 , & V_39 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] = ! ( V_39 & V_41 ) ;
V_22 -> V_3 . integer . V_3 [ 1 ] = ! ( V_39 & V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 = 0 , V_39 = 0 ;
int V_43 = - V_44 ;
F_9 ( & V_1 -> V_25 ) ;
if ( V_1 -> V_45 )
goto V_46;
F_1 ( V_1 , V_40 , & V_4 ) ;
V_39 = V_4 ;
V_39 &= ~ ( V_42 | V_41 ) ;
if ( ! V_22 -> V_3 . integer . V_3 [ 0 ] )
V_39 |= V_41 ;
if ( ! V_22 -> V_3 . integer . V_3 [ 1 ] )
V_39 |= V_42 ;
V_43 = F_3 ( V_1 , V_40 , V_39 ) ;
V_46:
F_10 ( & V_1 -> V_25 ) ;
return ! V_43 ? ( V_4 != V_39 ) : V_43 ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_39 ;
long int V_47 = V_13 -> V_48 ;
T_1 V_49 = ( V_47 >> 16 ) & V_50 ;
T_1 V_51 = ( V_47 >> 8 ) & 0xff ;
T_1 V_52 = V_47 & 0xff ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_51 , & V_39 ) ;
F_10 ( & V_1 -> V_25 ) ;
V_22 -> V_3 . integer . V_3 [ 0 ] = ! ! ( V_39 & V_52 ) ^ V_49 ;
return 0 ;
}
static int F_23 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 = 0 , V_39 = 0 ;
int V_43 ;
long int V_47 = V_13 -> V_48 ;
T_1 V_49 = ( V_47 >> 16 ) & V_50 ;
T_1 V_53 = ( V_47 >> 16 ) & V_54 ;
T_1 V_51 = ( V_47 >> 8 ) & 0xff ;
T_1 V_52 = V_47 & 0xff ;
F_9 ( & V_1 -> V_25 ) ;
if ( V_53 && V_1 -> V_55 ) {
V_43 = - V_44 ;
goto V_46;
}
F_1 ( V_1 , V_51 , & V_4 ) ;
V_39 = V_4 ;
V_39 &= ~ ( V_52 ) ;
if ( ! ! V_22 -> V_3 . integer . V_3 [ 0 ] ^ V_49 )
V_39 |= V_52 ;
V_43 = F_3 ( V_1 , V_51 , V_39 ) ;
V_46:
F_10 ( & V_1 -> V_25 ) ;
return ! V_43 ? ( V_4 != V_39 ) : V_43 ;
}
static int F_24 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_15 -> type = V_56 ;
V_15 -> V_17 = 1 ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
V_22 -> V_3 . V_57 . V_58 [ 0 ] = 0x3e ;
V_22 -> V_3 . V_57 . V_58 [ 1 ] = 0xff ;
V_22 -> V_3 . V_57 . V_58 [ 3 ] = 0x3f ;
V_22 -> V_3 . V_57 . V_58 [ 4 ] = 0x0f ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_59 , & V_4 ) ;
V_22 -> V_3 . V_57 . V_58 [ 0 ] = V_4 & 0x3e ;
F_1 ( V_1 , V_60 , & V_4 ) ;
V_22 -> V_3 . V_57 . V_58 [ 1 ] = V_4 ;
F_1 ( V_1 , V_61 , & V_4 ) ;
V_22 -> V_3 . V_57 . V_58 [ 3 ] = V_4 & 0x3f ;
F_1 ( V_1 , V_62 , & V_4 ) ;
V_22 -> V_3 . V_57 . V_58 [ 4 ] = V_4 & 0x0f ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_8 ( V_13 ) ;
T_1 V_4 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_59 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x3e ) | ( V_22 -> V_3 . V_57 . V_58 [ 0 ] & 0x3e ) ;
F_3 ( V_1 , V_59 , V_4 ) ;
V_4 = V_22 -> V_3 . V_57 . V_58 [ 1 ] ;
F_3 ( V_1 , V_60 , V_4 ) ;
F_1 ( V_1 , V_61 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x3f ) | ( V_22 -> V_3 . V_57 . V_58 [ 3 ] & 0x3f ) ;
F_3 ( V_1 , V_61 , V_4 ) ;
F_1 ( V_1 , V_62 , & V_4 ) ;
V_4 = ( V_4 & ~ 0x0f ) | ( V_22 -> V_3 . V_57 . V_58 [ 4 ] & 0x0f ) ;
F_3 ( V_1 , V_62 , V_4 ) ;
F_10 ( & V_1 -> V_25 ) ;
return 1 ;
}
static int F_28 ( struct V_1 * V_1 )
{
int V_63 ;
T_1 V_64 ;
T_1 V_65 [ sizeof( V_66 ) ] ;
if ( ! V_1 -> V_67 ) {
memcpy ( V_65 , V_66 , sizeof( V_66 ) ) ;
if ( F_1 ( V_1 , V_5 , & V_64 ) )
return - 1 ;
V_64 &= ~ V_68 ;
V_64 |= V_66 [ 3 ] ;
V_65 [ 3 ] = V_64 ;
} else {
for ( V_63 = 0 ; V_63 < sizeof( V_69 ) ; V_63 ++ )
V_65 [ V_63 ] = V_1 -> V_6 [ V_69 [ V_63 ] - V_7 ] ;
}
for ( V_63 = 0 ; V_63 < sizeof( V_69 ) ; V_63 ++ ) {
if ( F_3 ( V_1 , V_69 [ V_63 ] , V_65 [ V_63 ] ) )
return - 1 ;
}
V_1 -> V_67 = 1 ;
return 0 ;
}
static int F_29 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_72 * V_74 )
{
T_1 V_4 ;
struct V_1 * V_1 = V_71 -> V_75 ;
int V_76 , V_77 ;
F_9 ( & V_1 -> V_25 ) ;
F_1 ( V_1 , V_62 , & V_4 ) ;
V_76 = ! ! ( V_4 & V_78 ) ;
F_1 ( V_1 , V_40 , & V_4 ) ;
V_77 =
( V_4 & ( V_42 | V_41 ) )
!= ( V_42 | V_41 ) ;
F_10 ( & V_1 -> V_25 ) ;
switch ( V_73 -> V_79 ) {
case 0 : return 1 ;
case 1 : return V_77 ;
case 2 : return V_76 ;
}
return 1 ;
}
static int F_30 ( struct V_70 * V_71 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
T_1 V_4 ;
struct V_1 * V_1 = V_71 -> V_75 ;
int V_43 = - V_44 ;
F_9 ( & V_1 -> V_25 ) ;
#ifdef F_31
if ( V_83 -> V_84 -> V_85 == F_31 ) {
F_1 ( V_1 , V_40 , & V_4 ) ;
if ( F_3 ( V_1 ,
V_40 ,
V_4 | V_42 | V_41 ) )
goto V_46;
V_1 -> V_45 = 1 ;
V_43 = 0 ;
goto V_46;
}
#endif
switch ( V_83 -> V_84 -> V_86 ) {
case 32000 :
case 44100 :
case 48000 :
V_43 = 0 ;
goto V_46;
default:
F_1 ( V_71 -> V_75 , V_62 , & V_4 ) ;
if ( F_3 ( V_1 ,
V_62 ,
V_4 & ~ V_78 ) )
goto V_46;
V_1 -> V_55 = 1 ;
V_43 = 0 ;
goto V_46;
}
V_46:
F_10 ( & V_1 -> V_25 ) ;
return V_43 ;
}
static int F_32 ( struct V_70 * V_71 ,
struct V_82 * V_83 )
{
struct V_1 * V_1 = V_71 -> V_75 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_87 ++ ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_33 ( struct V_70 * V_71 ,
struct V_82 * V_83 )
{
struct V_1 * V_1 = V_71 -> V_75 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_87 -- ;
if ( ! V_1 -> V_87 )
V_1 -> V_55 = V_1 -> V_45 = 0 ;
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_34 ( struct V_70 * V_71 ,
enum V_88 V_89 )
{
struct V_1 * V_1 = V_71 -> V_75 ;
F_9 ( & V_1 -> V_25 ) ;
switch ( V_89 ) {
case V_90 :
V_1 -> V_91 . V_92 -> V_93 -> V_94 ( V_1 -> V_91 . V_92 ) ;
break;
case V_95 :
V_1 -> V_91 . V_92 -> V_93 -> V_96 ( V_1 -> V_91 . V_92 ) ;
break;
default:
break;
}
F_10 ( & V_1 -> V_25 ) ;
return 0 ;
}
static int F_35 ( struct V_70 * V_71 , T_4 V_97 )
{
struct V_1 * V_1 = V_71 -> V_75 ;
T_1 V_4 ;
int V_43 = - V_98 ;
F_9 ( & V_1 -> V_25 ) ;
if ( F_1 ( V_1 , V_5 , & V_4 ) )
goto V_46;
F_3 ( V_1 , V_5 , V_4 | V_99 | V_100 ) ;
V_43 = 0 ;
V_46:
F_10 ( & V_1 -> V_25 ) ;
return V_43 ;
}
static int F_36 ( struct V_70 * V_71 )
{
struct V_1 * V_1 = V_71 -> V_75 ;
T_1 V_4 ;
int V_43 = - V_98 ;
F_9 ( & V_1 -> V_25 ) ;
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 0 ) ;
F_37 ( 1 ) ;
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 1 ) ;
F_37 ( 1 ) ;
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 0 ) ;
F_37 ( 1 ) ;
if ( F_1 ( V_1 , V_5 , & V_4 ) )
goto V_46;
F_3 ( V_1 , V_5 , V_4 & ~ ( V_99 | V_100 ) ) ;
F_37 ( 2205000 / 8000 ) ;
F_28 ( V_1 ) ;
V_43 = 0 ;
V_46:
F_10 ( & V_1 -> V_25 ) ;
return V_43 ;
}
static int F_38 ( struct V_102 * V_91 )
{
struct V_1 * V_1 = F_39 ( V_91 ) ;
struct V_12 * V_103 ;
struct V_104 * V_105 = & V_106 ;
T_1 V_4 ;
int V_43 ;
if ( ! V_1 -> V_91 . V_92 || ! V_1 -> V_91 . V_92 -> V_93 ) {
F_40 (KERN_ERR PFX L_3 ) ;
return - V_28 ;
}
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 0 ) ;
F_37 ( 1 ) ;
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 1 ) ;
F_37 ( 1 ) ;
V_1 -> V_91 . V_92 -> V_93 -> V_101 ( V_1 -> V_91 . V_92 , 0 ) ;
F_37 ( 1 ) ;
if ( F_28 ( V_1 ) ) {
F_40 (KERN_ERR PFX L_4 ) ;
return - V_107 ;
}
if ( F_41 ( V_108 , V_1 , & V_109 ) ) {
F_40 (KERN_ERR PFX L_5 ) ;
return - V_107 ;
}
if ( ( V_1 -> V_91 . V_110 & 0xF ) == 0 )
return - V_111 ;
if ( ( V_1 -> V_91 . V_110 & 0xC ) == 0 ) {
if ( ! V_1 -> V_104 )
V_1 -> V_104 = F_42 ( sizeof( struct V_104 ) , V_112 ) ;
if ( ! V_1 -> V_104 )
return - V_113 ;
V_105 = V_1 -> V_104 ;
* V_105 = V_106 ;
V_105 -> V_114 ++ ;
}
if ( ( V_1 -> V_91 . V_110 & 3 ) == 0 ) {
if ( ! V_1 -> V_104 )
V_1 -> V_104 = F_42 ( sizeof( struct V_104 ) , V_112 ) ;
if ( ! V_1 -> V_104 )
return - V_113 ;
V_105 = V_1 -> V_104 ;
* V_105 = V_106 ;
V_105 -> V_114 [ 1 ] . V_115 = 0 ;
}
if ( V_1 -> V_91 . V_116 -> V_117 ( V_1 -> V_91 . V_116 ,
F_43 () ,
V_105 , V_1 ) ) {
F_40 (KERN_ERR PFX L_6 ) ;
return - V_107 ;
}
#define F_44 ( V_33 ) \
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
if ( V_1 -> V_91 . V_116 -> V_118 ) {
if ( ( V_1 -> V_91 . V_110 & 0xC ) == 0xC )
F_44 ( V_119 ) ;
else if ( V_1 -> V_91 . V_110 & 4 )
F_18 ( V_1 , 0 ) ;
else
F_18 ( V_1 , 1 ) ;
if ( V_1 -> V_91 . V_110 & 0xC )
F_44 ( V_120 ) ;
if ( V_1 -> V_91 . V_110 & 1 ) {
F_44 ( V_121 ) ;
F_44 ( V_122 ) ;
F_44 ( V_123 ) ;
F_44 ( V_124 ) ;
F_44 ( V_125 ) ;
F_44 ( V_126 ) ;
}
if ( V_1 -> V_91 . V_110 & 2 ) {
F_44 ( V_127 ) ;
F_44 ( V_128 ) ;
}
if ( ( V_1 -> V_91 . V_110 & 3 ) == 3 )
F_44 ( V_129 ) ;
if ( ( V_1 -> V_91 . V_110 & 3 ) == 2 ) {
F_1 ( V_1 , V_62 , & V_4 ) ;
V_4 |= V_78 ;
F_3 ( V_1 , V_62 , V_4 ) ;
}
}
#undef F_44
F_40 (KERN_INFO PFX L_7 ) ;
return 0 ;
error:
V_1 -> V_91 . V_116 -> V_130 ( V_1 -> V_91 . V_116 , V_1 ) ;
F_45 ( F_43 () , V_1 ) ;
return V_43 ;
}
static void F_46 ( struct V_102 * V_91 )
{
struct V_1 * V_1 = F_39 ( V_91 ) ;
if ( ! V_1 -> V_91 . V_116 ) {
F_40 (KERN_ERR PFX L_8 ) ;
return;
}
V_1 -> V_91 . V_116 -> V_130 ( V_1 -> V_91 . V_116 , V_1 ) ;
}
static int F_47 ( struct V_131 * V_132 ,
const struct V_133 * V_134 )
{
struct V_135 * V_136 = V_132 -> V_11 . V_137 ;
struct V_1 * V_1 ;
T_1 V_138 ;
V_1 = F_48 ( sizeof( struct V_1 ) , V_112 ) ;
if ( ! V_1 )
return - V_113 ;
F_49 ( & V_1 -> V_25 ) ;
V_1 -> V_8 = V_132 ;
F_50 ( V_132 , V_1 ) ;
if ( F_1 ( V_1 , V_5 , & V_138 ) != 0 ) {
F_40 (KERN_ERR PFX L_9 ) ;
goto V_139;
}
F_51 ( V_1 -> V_91 . V_140 , L_10 , V_141 ) ;
V_1 -> V_91 . V_142 = V_143 ;
V_1 -> V_91 . V_144 = F_38 ;
V_1 -> V_91 . exit = F_46 ;
V_1 -> V_91 . V_136 = F_52 ( V_136 ) ;
if ( F_53 ( & V_1 -> V_91 ) ) {
goto V_139;
}
F_40 (KERN_DEBUG PFX L_11 ) ;
return 0 ;
V_139:
F_54 ( V_1 ) ;
return - V_107 ;
}
static int F_55 ( struct V_131 * V_132 )
{
struct V_1 * V_1 = F_56 ( V_132 ) ;
F_57 ( & V_1 -> V_91 ) ;
F_58 ( V_1 -> V_91 . V_136 ) ;
F_54 ( V_1 -> V_104 ) ;
F_54 ( V_1 ) ;
return 0 ;
}
