static void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 64 ; V_1 ++ )
if ( V_2 [ V_1 ] . V_3 & V_4 )
V_2 [ V_1 ] . V_5 = V_2 [ V_1 ] . V_6 ;
}
static void F_2 ( struct V_7 * V_8 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 64 ; V_1 ++ )
if ( ( V_2 [ V_1 ] . V_3 & V_4 ) &&
( V_2 [ V_1 ] . V_5 != V_2 [ V_1 ] . V_6 ) ) {
F_3 ( V_9 , L_1
L_2
L_3 ,
V_1 , V_2 [ V_1 ] . V_5 ,
V_2 [ V_1 ] . V_5 , V_2 [ V_1 ] . V_6 ,
V_2 [ V_1 ] . V_6 ) ;
F_4 ( V_8 , V_1 * 2 , V_2 [ V_1 ] . V_5 ) ;
V_2 [ V_1 ] . V_3 |= V_10 ;
}
}
static T_1
F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_17 = 0 ;
T_2 V_18 = 0 ;
V_16 = F_6 ( V_12 ) ;
F_7 ( & V_16 -> V_19 ) ;
while ( ( V_18 = ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_21 ) ) != V_21 ) {
F_10 ( F_9 ( V_16 , V_22 ) , 0 ) ;
V_17 ++ ;
}
V_14 -> V_23 = 0 ;
F_11 ( & V_16 -> V_19 ) ;
return ( T_1 ) ( V_17 * 2 ) ;
}
static T_1
F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
T_1 V_24 )
{
struct V_15 * V_16 ;
T_3 * V_25 ;
int V_17 = 0 ;
T_2 V_18 = 0 ;
V_16 = F_6 ( V_12 ) ;
V_25 = ( T_3 * ) ( V_12 -> V_26 -> V_27 + V_14 -> V_28 ) ;
F_7 ( & V_16 -> V_19 ) ;
while ( ( ( V_18 = ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_21 ) ) != V_21 ) && ( V_24 > 1 ) ) {
F_10 ( F_9 ( V_16 , V_22 ) ,
F_13 ( V_25 [ V_17 ] ) ) ;
V_17 ++ ;
V_24 = V_24 - 2 ;
}
if ( V_18 != V_21 )
V_14 -> V_23 = 1 ;
else
V_14 -> V_23 = 0 ;
F_11 ( & V_16 -> V_19 ) ;
return ( T_1 ) ( V_17 * 2 ) ;
}
static T_1
F_14 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_17 = 0 ;
T_2 V_29 = 0 ;
V_16 = F_6 ( V_12 ) ;
F_7 ( & V_16 -> V_19 ) ;
while ( ( V_29 = ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_30 ) ) != V_30 ) {
volatile T_2 V_31 ;
V_31 = F_15 ( F_8 ( F_9 ( V_16 , V_32 ) ) ) ;
V_31 ++ ;
V_17 ++ ;
}
V_14 -> V_23 = 0 ;
F_11 ( & V_16 -> V_19 ) ;
return ( T_1 ) ( V_17 * 2 ) ;
}
static T_1
F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 , T_1 V_24 )
{
struct V_15 * V_16 ;
T_3 * V_33 ;
int V_17 = 0 ;
T_2 V_29 = 0 ;
V_16 = F_6 ( V_12 ) ;
V_33 = ( T_3 * ) ( V_12 -> V_26 -> V_27 + V_14 -> V_28 ) ;
F_7 ( & V_16 -> V_19 ) ;
while ( ( ( V_29 = ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_30 ) ) != V_30 ) && ( V_24 > 1 ) ) {
V_33 [ V_17 ] = F_15 ( F_8 ( F_9 ( V_16 ,
V_32 ) ) ) ;
V_17 ++ ;
V_24 = V_24 - 2 ;
}
if ( V_29 != V_30 )
V_14 -> V_23 = 1 ;
else
V_14 -> V_23 = 0 ;
F_11 ( & V_16 -> V_19 ) ;
return ( T_1 ) ( V_17 * 2 ) ;
}
static T_4
F_17 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
struct V_13 * V_34 = NULL ;
V_16 = F_6 ( V_12 ) ;
if ( V_12 == V_16 -> V_35 )
V_34 = & V_16 -> V_36 ;
if ( V_12 == V_16 -> V_37 )
V_34 = & V_16 -> V_38 ;
if ( V_34 != NULL )
return F_18 ( V_12 , V_34 ) ;
return ( T_4 ) 0 ;
}
static int
F_19 ( struct V_11 * V_12 ,
int V_39 )
{
struct V_15 * V_16 ;
int V_40 = 0 ;
V_16 = F_6 ( V_12 ) ;
switch ( V_39 ) {
case V_41 :
F_3 ( V_42 , L_4 ) ;
V_16 -> V_36 . V_23 = 1 ;
F_10 ( F_9 ( V_16 , V_43 ) , V_44 ) ;
V_16 -> V_45 = 1 ;
V_45 ( V_16 -> V_46 ) ;
break;
case V_47 :
F_3 ( V_42 , L_5 ) ;
V_16 -> V_36 . V_23 = 0 ;
#ifdef F_20
F_21 ( V_12 , & V_16 -> V_36 ) ;
#endif
F_22 ( V_16 -> V_46 ) ;
V_16 -> V_45 = 0 ;
break;
default:
V_40 = - V_48 ;
break;
}
F_3 ( V_42 , L_6 ) ;
return V_40 ;
}
static int
F_23 ( struct V_11 * V_12 ,
int V_39 )
{
struct V_15 * V_16 ;
int V_40 = 0 ;
V_16 = F_6 ( V_12 ) ;
switch ( V_39 ) {
case V_41 :
F_3 ( V_42 , L_7 ) ;
V_16 -> V_38 . V_23 = 0 ;
F_10 ( F_9 ( V_16 , V_43 ) , V_49 ) ;
V_16 -> V_50 = 1 ;
V_45 ( V_16 -> V_51 ) ;
break;
case V_47 :
F_3 ( V_42 , L_8 ) ;
V_16 -> V_38 . V_23 = 0 ;
#ifdef F_20
F_21 ( V_12 ,
& V_16 -> V_38 ) ;
#endif
F_22 ( V_16 -> V_51 ) ;
V_16 -> V_50 = 0 ;
break;
default:
V_40 = - V_48 ;
break;
}
F_3 ( V_42 , L_9 ) ;
return V_40 ;
}
static int
F_24 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
struct V_52 * V_26 ;
V_16 = F_6 ( V_12 ) ;
V_26 = V_12 -> V_26 ;
F_3 ( V_42 ,
L_10 ,
F_25 ( V_12 ) , V_53 / 2 ) ;
F_26 ( V_16 -> V_8 , V_54 ,
V_26 -> V_55 ) ;
F_3 ( V_42 , L_11 , V_26 -> V_55 ) ;
memset ( & V_16 -> V_36 , 0 ,
sizeof( struct V_13 ) ) ;
V_16 -> V_36 . V_56 = V_53 ;
V_16 -> V_36 . V_57 =
F_27 ( V_12 ) ;
V_16 -> V_36 . V_58 = - 1 ;
V_16 -> V_36 . V_59 =
F_25 ( V_12 ) / ( V_53 / 2 ) ;
F_3 ( V_42 , L_12
L_13 ,
V_53 , V_16 -> V_36 . V_57 ,
V_16 -> V_36 . V_59 ) ;
return 0 ;
}
static int
F_28 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
struct V_52 * V_26 ;
V_16 = F_6 ( V_12 ) ;
V_26 = V_12 -> V_26 ;
F_3 ( V_42 ,
L_14 ,
F_25 ( V_12 ) , V_53 / 2 ) ;
F_26 ( V_16 -> V_8 , V_60 ,
V_26 -> V_55 ) ;
F_3 ( V_42 , L_15 , V_26 -> V_55 ) ;
memset ( & V_16 -> V_38 , 0 ,
sizeof( struct V_13 ) ) ;
V_16 -> V_38 . V_56 = V_53 ;
V_16 -> V_38 . V_57 =
F_27 ( V_12 ) ;
V_16 -> V_38 . V_59 =
F_25 ( V_12 ) / ( V_53 / 2 ) ;
F_3 ( V_42 , L_16
L_13 , V_53 ,
V_16 -> V_38 . V_57 ,
V_16 -> V_38 . V_59 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
F_3 ( V_42 , L_17 ) ;
return F_30 ( V_12 ) ;
}
static int
F_31 ( struct V_11 * V_12 ,
struct V_61 * V_62 )
{
F_3 ( V_42 , L_18
L_19 ,
F_32 ( V_62 ) , F_33 ( V_62 ) ) ;
return F_34 ( V_12 ,
F_32 ( V_62 ) ) ;
}
static int F_35 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
struct V_52 * V_26 ;
V_16 = F_6 ( V_12 ) ;
V_26 = V_12 -> V_26 ;
F_3 ( V_42 , L_20 ) ;
V_16 -> V_35 = V_12 ;
V_26 -> V_63 = V_64 ;
F_36 ( V_26 , 0 ,
V_65 ,
V_53 / 2 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
struct V_52 * V_26 ;
V_16 = F_6 ( V_12 ) ;
V_26 = V_12 -> V_26 ;
F_3 ( V_42 , L_21 ) ;
V_16 -> V_37 = V_12 ;
V_26 -> V_63 = V_66 ;
F_36 ( V_26 , 0 ,
V_65 ,
V_53 / 2 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
V_16 = F_6 ( V_12 ) ;
F_3 ( V_42 , L_22 ) ;
V_16 -> V_35 = NULL ;
return 0 ;
}
static int F_39 ( struct V_11 * V_12 )
{
struct V_15 * V_16 ;
V_16 = F_6 ( V_12 ) ;
F_3 ( V_42 , L_23 ) ;
V_16 -> V_37 = NULL ;
return 0 ;
}
static T_5 F_40 ( int V_46 , void * V_67 )
{
struct V_15 * V_16 ;
struct V_68 * V_69 ;
int V_70 ;
V_16 = (struct V_15 * ) V_67 ;
if ( V_16 == NULL )
return V_71 ;
V_69 = V_16 -> V_69 ;
V_70 = F_41 ( V_69 , 0 ) ;
if ( V_46 == V_70 ) {
if ( V_16 -> V_45 )
F_42 (
V_16 -> V_35 ,
& V_16 -> V_36 ,
F_12 ,
F_5 ) ;
else
goto V_72;
} else {
V_70 = F_41 ( V_69 , 1 ) ;
if ( V_46 == V_70 ) {
if ( V_16 -> V_50 )
F_43 (
V_16 -> V_37 ,
& V_16 -> V_38 ,
F_16 ,
F_14 ) ;
else
goto V_72;
} else
return V_71 ;
}
return V_73 ;
V_72:
F_3 ( V_74 , L_24
L_25 , V_46 ) ;
F_22 ( V_46 ) ;
return V_73 ;
}
static unsigned short
F_44 ( struct V_7 * V_8 , unsigned short V_75 )
{
struct V_15 * V_16 = V_8 -> V_76 ;
#ifdef F_45
T_2 V_77 ;
T_2 V_78 = 0 ;
#endif
unsigned long V_79 ;
T_3 V_5 = 0 ;
if ( ! F_46 ( V_75 ) ) {
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_27
L_28 , reg) ;
return 0 ;
}
if ( ( V_2 [ V_75 / 2 ] . V_3 &
( V_10 | V_80 ) ) &&
! ( V_2 [ V_75 / 2 ] . V_3 & V_81 ) ) {
if ( V_2 [ V_75 / 2 ] . V_3 & V_82 ) {
F_3 ( V_9 , L_29
L_30 ,
V_75 , V_2 [ V_75 / 2 ] . V_6 ,
V_2 [ V_75 / 2 ] . V_6 ) ;
return V_2 [ V_75 / 2 ] . V_6 ;
} else if ( ( V_2 [ V_75 / 2 ] . V_3 &
V_4 ) &&
V_16 -> V_83 ) {
F_3 ( V_9 , L_29
L_31 ,
V_75 , V_2 [ V_75 / 2 ] . V_5 ,
V_2 [ V_75 / 2 ] . V_5 ) ;
return V_2 [ V_75 / 2 ] . V_5 ;
} else {
#ifdef F_45
F_3 ( V_9 , L_32
L_33
L_34 ,
V_75 , V_2 [ V_75 / 2 ] . V_5 ,
V_2 [ V_75 / 2 ] . V_5 ,
V_16 -> V_84 ,
V_16 -> V_85 ) ;
#else
F_3 ( V_9 , L_32
L_33
L_35 ,
V_75 , V_2 [ V_75 / 2 ] . V_5 ,
V_2 [ V_75 / 2 ] . V_5 ) ;
#endif
return V_2 [ V_75 / 2 ] . V_5 ;
}
}
if ( F_48 ( & V_16 -> V_86 ) != 0 )
return 0 ;
#ifdef F_45
V_16 -> V_85 ++ ;
#endif
F_7 ( & V_16 -> V_19 ) ;
F_10 ( F_9 ( V_16 , V_87 ) ,
F_49 ( V_75 ) | V_88 ) ;
F_11 ( & V_16 -> V_19 ) ;
V_79 = V_89 + ( V_90 / V_91 ) ;
do {
F_7 ( & V_16 -> V_19 ) ;
#ifdef F_45
V_78 ++ ;
V_77 = F_8 ( F_9 ( V_16 , V_20 ) ) ;
if ( ( V_77 & V_92 ) == V_92 ) {
V_5 = F_50 (
F_8 ( F_9 ( V_16 , V_93 ) ) ) ;
F_3 ( V_94 , L_36
L_37 ,
V_75 , V_5 , V_5 , V_77 ) ;
#else
if ( ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_92 ) == V_92 ) {
V_5 = F_50 (
F_8 ( F_9 ( V_16 , V_93 ) ) ) ;
F_3 ( V_94 , L_38
L_39 ,
V_75 , V_5 , V_5 ) ;
#endif
V_2 [ V_75 / 2 ] . V_5 = V_5 ;
V_2 [ V_75 / 2 ] . V_3 |= V_10 ;
F_11 ( & V_16 -> V_19 ) ;
F_51 ( & V_16 -> V_86 ) ;
return V_5 ;
}
F_11 ( & V_16 -> V_19 ) ;
F_52 ( 1 ) ;
} while ( F_53 ( V_79 , V_89 ) ) ;
F_7 ( & V_16 -> V_19 ) ;
V_5 =
F_50 ( F_8 ( F_9 ( V_16 , V_93 ) ) ) ;
F_11 ( & V_16 -> V_19 ) ;
#ifdef F_45
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_40
L_41
L_42 ,
reg, stat, value, value, rafaccess,
ml403_ac97cr->ac97_write, ml403_ac97cr->ac97_read) ;
#else
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_40
L_43 ,
reg, value, value) ;
#endif
V_2 [ V_75 / 2 ] . V_5 = V_5 ;
V_2 [ V_75 / 2 ] . V_3 |= V_10 ;
F_51 ( & V_16 -> V_86 ) ;
return V_5 ;
}
static void
snd_ml403_ac97cr_codec_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct V_15 * V_16 = V_8 -> V_76 ;
#ifdef F_45
T_2 V_77 ;
T_2 V_78 = 0 ;
#endif
#ifdef F_54
unsigned long V_79 ;
#endif
if ( ! F_46 ( V_75 ) ) {
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_27
L_28 , reg) ;
return;
}
if ( V_2 [ V_75 / 2 ] . V_3 & V_95 ) {
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_44
L_28 , reg) ;
return;
}
if ( ( V_96 & V_2 [ V_75 / 2 ] . V_97 ) != V_96 ) {
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_45
L_46 ,
reg, val, val) ;
V_96 = V_96 & V_2 [ V_75 / 2 ] . V_97 ;
}
if ( ( ( V_2 [ V_75 / 2 ] . V_3 & V_4 ) &&
V_16 -> V_83 ) &&
! ( V_2 [ V_75 / 2 ] . V_3 & V_81 ) ) {
F_3 ( V_9 , L_47
L_48 , V_75 , V_96 , V_96 ) ;
V_2 [ V_75 / 2 ] . V_5 = ( V_96 &
V_2 [ V_75 / 2 ] . V_97 ) ;
return;
}
if ( F_48 ( & V_16 -> V_86 ) != 0 )
return;
#ifdef F_45
V_16 -> V_84 ++ ;
#endif
F_7 ( & V_16 -> V_19 ) ;
F_10 ( F_9 ( V_16 , V_98 ) ,
F_55 ( V_96 ) ) ;
F_10 ( F_9 ( V_16 , V_87 ) ,
F_49 ( V_75 ) | V_99 ) ;
F_11 ( & V_16 -> V_19 ) ;
#ifdef F_54
V_79 = V_89 + V_90 / V_100 ;
do {
F_7 ( & V_16 -> V_19 ) ;
#ifdef F_45
V_78 ++ ;
V_77 = F_8 (CR_REG(ml403_ac97cr, STATUS))
if ( ( V_77 & V_92 ) == V_92 ) {
#else
if ( ( F_8 ( F_9 ( V_16 , V_20 ) ) &
V_92 ) == V_92 ) {
#endif
F_3 ( V_94 , L_49
L_50 ,
V_75 , V_96 , V_96 ) ;
if ( ! ( V_2 [ V_75 / 2 ] . V_3 &
V_81 ) &&
! ( V_2 [ V_75 / 2 ] . V_3 &
V_101 ) )
V_2 [ V_75 / 2 ] . V_5 = V_96 ;
V_2 [ V_75 / 2 ] . V_3 |= V_10 ;
F_11 ( & V_16 -> V_19 ) ;
F_51 ( & V_16 -> V_86 ) ;
return;
}
F_11 ( & V_16 -> V_19 ) ;
F_52 ( 1 ) ;
} while ( F_53 ( V_79 , V_89 ) ) ;
#ifdef F_45
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_51
L_52
L_42 ,
reg, val, val, stat, rafaccess, ml403_ac97cr->ac97_write,
ml403_ac97cr->ac97_read) ;
#else
F_47 (KERN_WARNING SND_ML403_AC97CR_DRIVER L_26
L_53 ,
reg, val, val) ;
#endif
#else
#if V_102 > 0
F_52 ( V_90 / V_102 ) ;
#endif
F_3 ( V_94 , L_49
L_54 ,
V_75 , V_96 , V_96 ) ;
#endif
F_51 ( & V_16 -> V_86 ) ;
return;
}
static int __devinit
snd_ml403_ac97cr_chip_init(struct snd_ml403_ac97cr *ml403_ac97cr)
{
unsigned long V_79 ;
F_3 ( V_74 , L_55 ) ;
V_79 = V_89 + V_90 / V_103 ;
do {
if ( F_8 ( F_9 ( V_16 , V_20 ) ) & V_104 ) {
F_10 ( F_9 ( V_16 , V_43 ) ,
V_49 | V_44 ) ;
F_3 ( V_74 , L_56 ) ;
return 0 ;
}
F_52 ( 1 ) ;
} while ( F_53 ( V_79 , V_89 ) );
F_47 (KERN_ERR SND_ML403_AC97CR_DRIVER L_26
L_57
L_58 ) ;
return - V_105 ;
}
static int snd_ml403_ac97cr_free(struct snd_ml403_ac97cr *ml403_ac97cr
static int F_56 ( struct V_106 * V_107 )
{
struct V_15 * V_16 = V_107 -> V_108 ;
F_3 ( V_74 , L_59 ) ;
return F_57 ( V_16 ) ;
}
static int T_6
F_58 ( struct V_109 * V_110 , struct V_68 * V_69 ,
struct V_15 * * V_111 )
{
struct V_15 * V_16 ;
int V_40 ;
static struct V_112 V_113 = {
. V_114 = F_56 ,
} ;
struct V_115 * V_115 ;
int V_46 ;
* V_111 = NULL ;
V_16 = F_59 ( sizeof( * V_16 ) , V_116 ) ;
if ( V_16 == NULL )
return - V_117 ;
F_60 ( & V_16 -> V_19 ) ;
F_61 ( & V_16 -> V_86 ) ;
V_16 -> V_110 = V_110 ;
V_16 -> V_69 = V_69 ;
V_16 -> V_46 = - 1 ;
V_16 -> V_45 = 0 ;
V_16 -> V_51 = - 1 ;
V_16 -> V_50 = 0 ;
V_16 -> V_118 = NULL ;
V_16 -> V_119 = NULL ;
F_3 ( V_74 , L_60 ) ;
V_115 = F_62 ( V_69 , V_120 , 0 ) ;
V_16 -> V_118 = F_63 ( V_115 -> V_121 ,
( V_115 -> V_122 ) -
( V_115 -> V_121 ) + 1 ) ;
if ( V_16 -> V_118 == NULL ) {
F_47 (KERN_ERR SND_ML403_AC97CR_DRIVER L_26
L_61 ,
resource) ;
F_57 ( V_16 ) ;
return - V_105 ;
}
F_47 (KERN_INFO SND_ML403_AC97CR_DRIVER L_26
L_62
L_63 , (unsigned int)ml403_ac97cr->port) ;
V_46 = F_41 ( V_69 , 0 ) ;
if ( F_64 ( V_46 , F_40 , 0 ,
F_65 ( & V_69 -> V_123 ) , ( void * ) V_16 ) ) {
F_47 (KERN_ERR SND_ML403_AC97CR_DRIVER L_26
L_64 ,
irq) ;
F_57 ( V_16 ) ;
return - V_105 ;
}
V_16 -> V_46 = V_46 ;
F_47 (KERN_INFO SND_ML403_AC97CR_DRIVER L_26
L_65 ,
ml403_ac97cr->irq) ;
V_46 = F_41 ( V_69 , 1 ) ;
if ( F_64 ( V_46 , F_40 , 0 ,
F_65 ( & V_69 -> V_123 ) , ( void * ) V_16 ) ) {
F_47 (KERN_ERR SND_ML403_AC97CR_DRIVER L_26
L_64 ,
irq) ;
F_57 ( V_16 ) ;
return - V_105 ;
}
V_16 -> V_51 = V_46 ;
F_47 (KERN_INFO SND_ML403_AC97CR_DRIVER L_26
L_66 ,
ml403_ac97cr->capture_irq) ;
V_40 = F_66 ( V_16 ) ;
if ( V_40 < 0 ) {
F_57 ( V_16 ) ;
return V_40 ;
}
V_40 = F_67 ( V_110 , V_124 , V_16 , & V_113 ) ;
if ( V_40 < 0 ) {
F_3 ( V_125 , L_67 ) ;
F_57 ( V_16 ) ;
return V_40 ;
}
* V_111 = V_16 ;
return 0 ;
}
static void F_68 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_76 ;
F_3 ( V_74 , L_68 ) ;
V_16 -> V_8 = NULL ;
F_3 ( V_74 , L_69 ) ;
}
static int T_6
F_69 ( struct V_15 * V_16 )
{
struct V_126 * V_127 ;
struct V_128 V_8 ;
int V_40 ;
static struct V_129 V_113 = {
. V_130 = V_131 ,
. V_132 = F_44 ,
} ;
F_3 ( V_74 , L_70 ) ;
V_40 = V_126 ( V_16 -> V_110 , 0 , & V_113 , NULL , & V_127 ) ;
if ( V_40 < 0 )
return V_40 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_16 -> V_83 = 1 ;
F_1 () ;
#ifdef F_45
V_16 -> V_85 = 0 ;
V_16 -> V_84 = 0 ;
#endif
V_8 . V_76 = V_16 ;
V_8 . V_133 = F_68 ;
V_8 . V_134 = V_135 | V_136 |
V_137 ;
V_40 = F_70 ( V_127 , & V_8 , & V_16 -> V_8 ) ;
V_16 -> V_83 = 0 ;
F_2 ( V_16 -> V_8 ) ;
F_3 ( V_74 , L_71 , V_40 ) ;
return V_40 ;
}
static int T_6
F_71 ( struct V_15 * V_16 , int V_138 ,
struct V_139 * * V_140 )
{
struct V_139 * V_141 ;
int V_40 ;
if ( V_140 )
* V_140 = NULL ;
V_40 = F_72 ( V_16 -> V_110 , L_72 , V_138 , 1 , 1 ,
& V_141 ) ;
if ( V_40 < 0 )
return V_40 ;
F_73 ( V_141 , V_142 ,
& V_143 ) ;
F_73 ( V_141 , V_144 ,
& V_145 ) ;
V_141 -> V_76 = V_16 ;
V_141 -> V_146 = 0 ;
strcpy ( V_141 -> V_147 , L_73 ) ;
V_16 -> V_141 = V_141 ;
F_74 ( V_141 , V_148 ,
F_75 ( V_116 ) ,
64 * 1024 ,
128 * 1024 ) ;
if ( V_140 )
* V_140 = V_141 ;
return 0 ;
}
static int T_6 F_76 ( struct V_68 * V_69 )
{
struct V_109 * V_110 ;
struct V_15 * V_16 = NULL ;
int V_40 ;
int V_123 = V_69 -> V_149 ;
if ( V_123 >= V_150 )
return - V_151 ;
if ( ! V_152 [ V_123 ] )
return - V_153 ;
V_40 = F_77 ( V_154 [ V_123 ] , V_149 [ V_123 ] , V_155 , 0 , & V_110 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_58 ( V_110 , V_69 , & V_16 ) ;
if ( V_40 < 0 ) {
F_3 ( V_125 , L_74 ) ;
F_78 ( V_110 ) ;
return V_40 ;
}
F_3 ( V_74 , L_75 ) ;
V_110 -> V_76 = V_16 ;
V_40 = F_69 ( V_16 ) ;
if ( V_40 < 0 ) {
F_78 ( V_110 ) ;
return V_40 ;
}
F_3 ( V_74 , L_76 ) ;
V_40 = F_71 ( V_16 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_78 ( V_110 ) ;
return V_40 ;
}
F_3 ( V_74 , L_77 ) ;
strcpy ( V_110 -> V_156 , V_157 ) ;
strcpy ( V_110 -> V_158 , L_78 ) ;
sprintf ( V_110 -> V_159 , L_79 ,
V_110 -> V_158 , V_110 -> V_156 ,
( unsigned long ) V_16 -> V_118 , V_16 -> V_46 ,
V_16 -> V_51 , V_123 + 1 ) ;
F_79 ( V_110 , & V_69 -> V_123 ) ;
V_40 = F_80 ( V_110 ) ;
if ( V_40 < 0 ) {
F_78 ( V_110 ) ;
return V_40 ;
}
F_81 ( V_69 , V_110 ) ;
F_3 ( V_74 , L_80 ) ;
return 0 ;
}
static int F_82 ( struct V_68 * V_69 )
{
F_78 ( F_83 ( V_69 ) ) ;
F_81 ( V_69 , NULL ) ;
return 0 ;
}
