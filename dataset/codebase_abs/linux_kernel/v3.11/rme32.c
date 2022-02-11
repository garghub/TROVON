static inline unsigned int F_1 ( struct V_1 * V_1 )
{
return ( F_2 ( V_1 -> V_2 + V_3 )
& V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , int V_7 ,
T_1 V_8 ,
T_1 V_9 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
V_9 <<= V_1 -> V_10 ;
V_8 <<= V_1 -> V_10 ;
F_5 ( V_1 -> V_2 + V_11 + V_8 , 0 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , int V_7 ,
T_1 V_8 ,
void T_2 * V_12 , T_1 V_9 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
V_9 <<= V_1 -> V_10 ;
V_8 <<= V_1 -> V_10 ;
if ( F_7 ( V_1 -> V_2 + V_11 + V_8 ,
V_12 , V_9 ) )
return - V_13 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_7 ,
T_1 V_8 ,
void T_2 * V_14 , T_1 V_9 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
V_9 <<= V_1 -> V_15 ;
V_8 <<= V_1 -> V_15 ;
if ( F_9 ( V_14 ,
V_1 -> V_2 + V_11 + V_8 ,
V_9 ) )
return - V_13 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_11 ( V_1 -> V_16 | V_17 ,
V_1 -> V_2 + V_18 ) ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_19 ;
V_19 = ( ( V_1 -> V_16 >> V_20 ) & 1 ) +
( ( ( V_1 -> V_16 >> V_21 ) & 1 ) << 1 ) ;
switch ( V_19 ) {
case 1 :
V_19 = 32000 ;
break;
case 2 :
V_19 = 44100 ;
break;
case 3 :
V_19 = 48000 ;
break;
default:
return - 1 ;
}
return ( V_1 -> V_16 & V_22 ) ? V_19 << 1 : V_19 ;
}
static int F_13 ( struct V_1 * V_1 , int * V_23 )
{
int V_24 ;
* V_23 = 0 ;
if ( V_1 -> V_25 & V_26 ) {
* V_23 = 1 ;
}
if ( V_1 -> V_25 & V_27 ) {
return - 1 ;
}
V_24 = ( ( V_1 -> V_25 >> V_28 ) & 1 ) +
( ( ( V_1 -> V_25 >> V_29 ) & 1 ) << 1 ) +
( ( ( V_1 -> V_25 >> V_30 ) & 1 ) << 2 ) ;
if ( F_14 ( V_1 ) )
switch ( V_24 ) {
case 0 :
case 1 :
case 2 :
return - 1 ;
case 3 :
return 96000 ;
case 4 :
return 88200 ;
case 5 :
return 48000 ;
case 6 :
return 44100 ;
case 7 :
return 32000 ;
default:
return - 1 ;
break;
}
else
switch ( V_24 ) {
case 0 :
return - 1 ;
case 1 :
return 48000 ;
case 2 :
return 44100 ;
case 3 :
return 32000 ;
case 4 :
return 48000 ;
case 5 :
return 44100 ;
case 6 :
return 44056 ;
case 7 :
return 32000 ;
default:
break;
}
return - 1 ;
}
static int F_15 ( struct V_1 * V_1 , int V_19 )
{
int V_31 ;
V_31 = V_1 -> V_16 & V_22 ;
switch ( V_19 ) {
case 32000 :
V_1 -> V_16 &= ~ V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) &
~ V_33 ;
break;
case 44100 :
V_1 -> V_16 &= ~ V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_33 ) &
~ V_32 ;
break;
case 48000 :
V_1 -> V_16 &= ~ V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) |
V_33 ;
break;
case 64000 :
if ( V_1 -> V_34 -> V_35 != V_36 )
return - V_37 ;
V_1 -> V_16 |= V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) &
~ V_33 ;
break;
case 88200 :
if ( V_1 -> V_34 -> V_35 != V_36 )
return - V_37 ;
V_1 -> V_16 |= V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_33 ) &
~ V_32 ;
break;
case 96000 :
if ( V_1 -> V_34 -> V_35 != V_36 )
return - V_37 ;
V_1 -> V_16 |= V_22 ;
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) |
V_33 ;
break;
default:
return - V_37 ;
}
if ( ( ! V_31 && V_1 -> V_16 & V_22 ) ||
( V_31 && ! ( V_1 -> V_16 & V_22 ) ) )
{
F_10 ( V_1 ) ;
} else {
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , int V_38 )
{
switch ( V_38 ) {
case V_39 :
V_1 -> V_16 = ( V_1 -> V_16 & ~ V_32 ) &
~ V_33 ;
break;
case V_40 :
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) &
~ V_33 ;
break;
case V_41 :
V_1 -> V_16 = ( V_1 -> V_16 & ~ V_32 ) |
V_33 ;
break;
case V_42 :
V_1 -> V_16 = ( V_1 -> V_16 | V_32 ) |
V_33 ;
break;
default:
return - V_37 ;
}
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
return ( ( V_1 -> V_16 >> V_20 ) & 1 ) +
( ( ( V_1 -> V_16 >> V_21 ) & 1 ) << 1 ) ;
}
static int F_18 ( struct V_1 * V_1 , int type )
{
switch ( type ) {
case V_43 :
V_1 -> V_16 = ( V_1 -> V_16 & ~ V_44 ) &
~ V_45 ;
break;
case V_46 :
V_1 -> V_16 = ( V_1 -> V_16 | V_44 ) &
~ V_45 ;
break;
case V_47 :
V_1 -> V_16 = ( V_1 -> V_16 & ~ V_44 ) |
V_45 ;
break;
case V_48 :
V_1 -> V_16 = ( V_1 -> V_16 | V_44 ) |
V_45 ;
break;
default:
return - V_37 ;
}
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
return ( ( V_1 -> V_16 >> V_49 ) & 1 ) +
( ( ( V_1 -> V_16 >> V_50 ) & 1 ) << 1 ) ;
}
static void
F_20 ( struct V_1 * V_1 , int V_51 , int V_52 )
{
int V_53 ;
if ( V_51 == 2 ) {
V_53 = 1 ;
} else {
V_53 = 3 ;
}
if ( V_52 ) {
V_53 += ( V_1 -> V_16 & V_54 ) ? 2 : 1 ;
V_1 -> V_10 = V_53 ;
} else {
V_53 += ( V_1 -> V_16 & V_54 ) ? 2 : 1 ;
V_1 -> V_15 = V_53 ;
}
}
static int F_21 ( struct V_1 * V_1 , int V_55 )
{
switch ( V_55 ) {
case V_56 :
V_1 -> V_16 &= ~ V_54 ;
break;
case V_57 :
V_1 -> V_16 |= V_54 ;
break;
default:
return - V_37 ;
}
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
return 0 ;
}
static int
F_22 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_60 , V_19 , V_61 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
if ( V_1 -> V_64 ) {
V_60 = F_23 ( V_6 , F_24 ( V_59 ) ) ;
if ( V_60 < 0 )
return V_60 ;
} else {
V_63 -> V_65 = ( void V_66 * ) ( V_1 -> V_2 +
V_11 ) ;
V_63 -> V_67 = V_1 -> V_68 + V_11 ;
V_63 -> V_69 = V_70 ;
}
F_25 ( & V_1 -> V_71 ) ;
if ( ( V_1 -> V_25 & V_72 ) &&
( V_19 = F_13 ( V_1 , & V_61 ) ) > 0 ) {
if ( ( int ) F_26 ( V_59 ) != V_19 ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_73 ;
}
} else if ( ( V_60 = F_15 ( V_1 , F_26 ( V_59 ) ) ) < 0 ) {
F_27 ( & V_1 -> V_71 ) ;
return V_60 ;
}
if ( ( V_60 = F_21 ( V_1 , F_28 ( V_59 ) ) ) < 0 ) {
F_27 ( & V_1 -> V_71 ) ;
return V_60 ;
}
F_20 ( V_1 , F_29 ( V_59 ) , 1 ) ;
if ( V_1 -> V_74 != 0 ) {
if ( F_30 ( V_59 ) << V_1 -> V_10 != V_1 -> V_74 ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
}
V_1 -> V_76 = F_30 ( V_59 ) << V_1 -> V_10 ;
if ( ( V_1 -> V_16 & V_77 ) == 0 ) {
V_1 -> V_16 &= ~ ( V_78 | V_79 ) ;
V_1 -> V_16 |= V_1 -> V_80 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
}
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int
F_31 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
int V_60 , V_81 , V_19 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
if ( V_1 -> V_64 ) {
V_60 = F_23 ( V_6 , F_24 ( V_59 ) ) ;
if ( V_60 < 0 )
return V_60 ;
} else {
V_63 -> V_65 = ( void V_66 * ) V_1 -> V_2 +
V_11 ;
V_63 -> V_67 = V_1 -> V_68 + V_11 ;
V_63 -> V_69 = V_70 ;
}
F_25 ( & V_1 -> V_71 ) ;
V_1 -> V_16 |= V_82 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
if ( ( V_60 = F_21 ( V_1 , F_28 ( V_59 ) ) ) < 0 ) {
F_27 ( & V_1 -> V_71 ) ;
return V_60 ;
}
if ( ( V_60 = F_15 ( V_1 , F_26 ( V_59 ) ) ) < 0 ) {
F_27 ( & V_1 -> V_71 ) ;
return V_60 ;
}
if ( ( V_19 = F_13 ( V_1 , & V_81 ) ) > 0 ) {
if ( ( int ) F_26 ( V_59 ) != V_19 ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_73 ;
}
if ( ( V_81 && V_63 -> V_83 . V_84 == 2 ) ||
( ! V_81 && V_63 -> V_83 . V_84 == 8 ) ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_73 ;
}
}
V_1 -> V_16 &= ~ V_82 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
F_20 ( V_1 , F_29 ( V_59 ) , 0 ) ;
if ( V_1 -> V_76 != 0 ) {
if ( F_30 ( V_59 ) << V_1 -> V_15 !=
V_1 -> V_76 ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
}
V_1 -> V_74 =
F_30 ( V_59 ) << V_1 -> V_15 ;
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
if ( ! V_1 -> V_64 )
return 0 ;
return F_33 ( V_6 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_85 )
{
if ( ! V_85 ) {
F_11 ( 0 , V_1 -> V_2 + V_86 ) ;
}
V_1 -> V_16 |= V_87 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
}
static void F_35 ( struct V_1 * V_1 , int V_88 )
{
V_1 -> V_25 = F_2 ( V_1 -> V_2 + V_18 ) ;
if ( V_1 -> V_25 & V_89 ) {
F_11 ( 0 , V_1 -> V_2 + V_90 ) ;
}
V_1 -> V_16 &= ~ V_87 ;
if ( V_1 -> V_16 & V_91 )
V_1 -> V_16 |= V_92 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
if ( ! V_88 )
F_11 ( 0 , V_1 -> V_2 + V_86 ) ;
}
static T_3 F_36 ( int V_93 , void * V_94 )
{
struct V_1 * V_1 = (struct V_1 * ) V_94 ;
V_1 -> V_25 = F_2 ( V_1 -> V_2 + V_18 ) ;
if ( ! ( V_1 -> V_25 & V_89 ) ) {
return V_95 ;
} else {
if ( V_1 -> V_96 ) {
F_37 ( V_1 -> V_96 ) ;
}
if ( V_1 -> V_97 ) {
F_37 ( V_1 -> V_97 ) ;
}
F_11 ( 0 , V_1 -> V_2 + V_90 ) ;
}
return V_98 ;
}
static void F_38 ( struct V_1 * V_1 , struct V_62 * V_63 )
{
if ( ! V_1 -> V_64 ) {
F_39 ( V_63 ,
V_99 ,
V_70 , V_70 ) ;
F_40 ( V_63 , 0 ,
V_100 ,
& V_101 ) ;
}
}
static int F_41 ( struct V_5 * V_6 )
{
int V_19 , V_61 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
F_42 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_97 != NULL ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
V_1 -> V_16 &= ~ V_77 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
V_1 -> V_97 = V_6 ;
F_27 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_64 )
V_63 -> V_83 = V_102 ;
else
V_63 -> V_83 = V_103 ;
if ( V_1 -> V_34 -> V_35 == V_36 ) {
V_63 -> V_83 . V_104 |= V_105 | V_106 | V_107 ;
V_63 -> V_83 . V_108 = 96000 ;
}
if ( ( V_1 -> V_25 & V_72 ) &&
( V_19 = F_13 ( V_1 , & V_61 ) ) > 0 ) {
V_63 -> V_83 . V_104 = F_43 ( V_19 ) ;
V_63 -> V_83 . V_109 = V_19 ;
V_63 -> V_83 . V_108 = V_19 ;
}
F_38 ( V_1 , V_63 ) ;
V_1 -> V_80 = V_1 -> V_110 ;
V_1 -> V_111 -> V_112 [ 0 ] . V_113 &= ~ V_114 ;
F_44 ( V_1 -> V_115 , V_116 |
V_117 , & V_1 -> V_111 -> V_118 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
int V_81 , V_19 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
F_42 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_96 != NULL ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
V_1 -> V_96 = V_6 ;
F_27 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_64 )
V_63 -> V_83 = V_102 ;
else
V_63 -> V_83 = V_103 ;
if ( F_14 ( V_1 ) ) {
V_63 -> V_83 . V_104 |= V_106 | V_107 ;
V_63 -> V_83 . V_108 = 96000 ;
}
if ( ( V_19 = F_13 ( V_1 , & V_81 ) ) > 0 ) {
if ( V_81 ) {
return - V_73 ;
}
V_63 -> V_83 . V_104 = F_43 ( V_19 ) ;
V_63 -> V_83 . V_109 = V_19 ;
V_63 -> V_83 . V_108 = V_19 ;
}
F_38 ( V_1 , V_63 ) ;
return 0 ;
}
static int
F_46 ( struct V_5 * V_6 )
{
int V_19 , V_61 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
F_42 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_97 != NULL ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
V_1 -> V_16 |= V_77 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
V_1 -> V_97 = V_6 ;
F_27 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_64 )
V_63 -> V_83 = V_119 ;
else
V_63 -> V_83 = V_120 ;
if ( ( V_1 -> V_25 & V_72 ) &&
( V_19 = F_13 ( V_1 , & V_61 ) ) > 0 ) {
V_63 -> V_83 . V_104 = F_43 ( V_19 ) ;
V_63 -> V_83 . V_109 = V_19 ;
V_63 -> V_83 . V_108 = V_19 ;
}
F_38 ( V_1 , V_63 ) ;
return 0 ;
}
static int
F_47 ( struct V_5 * V_6 )
{
int V_81 , V_19 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_62 * V_63 = V_6 -> V_63 ;
if ( V_1 -> V_64 )
V_63 -> V_83 = V_119 ;
else
V_63 -> V_83 = V_120 ;
if ( ( V_19 = F_13 ( V_1 , & V_81 ) ) > 0 ) {
if ( ! V_81 ) {
return - V_73 ;
}
V_63 -> V_83 . V_104 = F_43 ( V_19 ) ;
V_63 -> V_83 . V_109 = V_19 ;
V_63 -> V_83 . V_108 = V_19 ;
}
F_42 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_96 != NULL ) {
F_27 ( & V_1 -> V_71 ) ;
return - V_75 ;
}
V_1 -> V_96 = V_6 ;
F_27 ( & V_1 -> V_71 ) ;
F_38 ( V_1 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
int V_121 = 0 ;
F_25 ( & V_1 -> V_71 ) ;
V_1 -> V_97 = NULL ;
V_1 -> V_76 = 0 ;
V_121 = ( V_1 -> V_16 & V_77 ) == 0 ;
F_27 ( & V_1 -> V_71 ) ;
if ( V_121 ) {
V_1 -> V_111 -> V_112 [ 0 ] . V_113 |= V_114 ;
F_44 ( V_1 -> V_115 , V_116 |
V_117 ,
& V_1 -> V_111 -> V_118 ) ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
V_1 -> V_96 = NULL ;
V_1 -> V_74 = 0 ;
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_64 ) {
memset ( & V_1 -> V_122 , 0 , sizeof( V_1 -> V_122 ) ) ;
V_1 -> V_122 . V_123 = V_70 ;
V_1 -> V_122 . V_124 = F_51 ( V_6 ) ;
} else {
F_11 ( 0 , V_1 -> V_2 + V_86 ) ;
}
if ( V_1 -> V_16 & V_91 )
V_1 -> V_16 &= ~ V_92 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_25 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_64 ) {
memset ( & V_1 -> V_125 , 0 , sizeof( V_1 -> V_125 ) ) ;
V_1 -> V_125 . V_123 = V_70 ;
V_1 -> V_125 . V_126 = V_70 / 2 ;
V_1 -> V_125 . V_124 = F_51 ( V_6 ) ;
} else {
F_11 ( 0 , V_1 -> V_2 + V_86 ) ;
}
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int
F_53 ( struct V_5 * V_6 , int V_127 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_5 * V_128 ;
F_54 ( & V_1 -> V_71 ) ;
F_55 (s, substream) {
if ( V_128 != V_1 -> V_97 &&
V_128 != V_1 -> V_96 )
continue;
switch ( V_127 ) {
case V_129 :
V_1 -> V_130 |= ( 1 << V_128 -> V_131 ) ;
if ( V_1 -> V_64 ) {
if ( V_128 == V_1 -> V_97 ) {
V_1 -> V_122 . V_132 =
V_1 -> V_122 . V_133 = F_1 ( V_1 ) ;
} else {
V_1 -> V_125 . V_132 =
V_1 -> V_125 . V_133 = F_1 ( V_1 ) ;
}
}
break;
case V_134 :
V_1 -> V_130 &= ~ ( 1 << V_128 -> V_131 ) ;
break;
}
F_56 ( V_128 , V_6 ) ;
}
if ( V_127 == V_129 && V_1 -> V_64 ) {
F_55 (s, substream) {
if ( V_128 == V_1 -> V_97 ) {
V_128 -> V_135 -> V_136 ( V_128 ) ;
break;
}
}
}
switch ( V_127 ) {
case V_129 :
if ( V_1 -> V_130 && ! F_57 ( V_1 ) )
F_34 ( V_1 , 0 ) ;
break;
case V_134 :
if ( ! V_1 -> V_130 && F_57 ( V_1 ) )
F_35 ( V_1 , 0 ) ;
break;
case V_137 :
if ( V_1 -> V_130 && F_57 ( V_1 ) )
F_35 ( V_1 , 1 ) ;
break;
case V_138 :
if ( V_1 -> V_130 && ! F_57 ( V_1 ) )
F_34 ( V_1 , 1 ) ;
break;
}
F_58 ( & V_1 -> V_71 ) ;
return 0 ;
}
static T_1
F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return F_1 ( V_1 ) >> V_1 -> V_10 ;
}
static T_1
F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return F_1 ( V_1 ) >> V_1 -> V_15 ;
}
static void F_61 ( struct V_5 * V_6 ,
struct V_139 * V_140 , T_4 V_141 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_62 ( V_1 -> V_2 + V_11 + V_140 -> V_133 ,
V_6 -> V_63 -> V_65 + V_140 -> V_142 , V_141 ) ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_139 * V_140 , * V_143 ;
V_140 = & V_1 -> V_122 ;
V_143 = & V_1 -> V_125 ;
F_54 ( & V_1 -> V_71 ) ;
V_140 -> V_126 = V_70 ;
if ( V_1 -> V_130 & ( 1 << V_144 ) )
V_140 -> V_126 -= V_143 -> V_145 ;
F_58 ( & V_1 -> V_71 ) ;
F_64 ( V_6 , V_140 ,
F_61 ) ;
return 0 ;
}
static void F_65 ( struct V_5 * V_6 ,
struct V_139 * V_140 , T_4 V_141 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_66 ( V_6 -> V_63 -> V_65 + V_140 -> V_142 ,
V_1 -> V_2 + V_11 + V_140 -> V_133 ,
V_141 ) ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
F_68 ( V_6 , & V_1 -> V_125 ,
F_65 ) ;
return 0 ;
}
static T_1
F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return F_70 ( V_6 , & V_1 -> V_122 ,
F_1 ( V_1 ) ) ;
}
static T_1
F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return F_72 ( V_6 , & V_1 -> V_125 ,
F_1 ( V_1 ) ) ;
}
static void F_73 ( void * V_146 )
{
struct V_1 * V_1 = (struct V_1 * ) V_146 ;
if ( V_1 == NULL ) {
return;
}
if ( V_1 -> V_93 >= 0 ) {
F_35 ( V_1 , 0 ) ;
F_74 ( V_1 -> V_93 , ( void * ) V_1 ) ;
V_1 -> V_93 = - 1 ;
}
if ( V_1 -> V_2 ) {
F_75 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
if ( V_1 -> V_68 ) {
F_76 ( V_1 -> V_34 ) ;
V_1 -> V_68 = 0 ;
}
F_77 ( V_1 -> V_34 ) ;
}
static void F_78 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = (struct V_1 * ) V_148 -> V_146 ;
V_1 -> V_149 = NULL ;
}
static void
F_79 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = (struct V_1 * ) V_148 -> V_146 ;
V_1 -> V_150 = NULL ;
}
static int F_80 ( struct V_1 * V_1 )
{
struct V_151 * V_34 = V_1 -> V_34 ;
int V_60 ;
V_1 -> V_93 = - 1 ;
F_81 ( & V_1 -> V_71 ) ;
if ( ( V_60 = F_82 ( V_34 ) ) < 0 )
return V_60 ;
if ( ( V_60 = F_83 ( V_34 , L_1 ) ) < 0 )
return V_60 ;
V_1 -> V_68 = F_84 ( V_1 -> V_34 , 0 ) ;
V_1 -> V_2 = F_85 ( V_1 -> V_68 , V_152 ) ;
if ( ! V_1 -> V_2 ) {
F_86 ( V_153 L_2 ,
V_1 -> V_68 , V_1 -> V_68 + V_152 - 1 ) ;
return - V_154 ;
}
if ( F_87 ( V_34 -> V_93 , F_36 , V_155 ,
V_156 , V_1 ) ) {
F_86 ( V_153 L_3 , V_34 -> V_93 ) ;
return - V_75 ;
}
V_1 -> V_93 = V_34 -> V_93 ;
F_88 ( V_34 , 8 , & V_1 -> V_157 ) ;
if ( ( V_60 = F_89 ( V_1 -> V_115 , L_4 , 0 , 1 , 1 , & V_1 -> V_149 ) ) < 0 ) {
return V_60 ;
}
V_1 -> V_149 -> V_146 = V_1 ;
V_1 -> V_149 -> V_158 = F_78 ;
strcpy ( V_1 -> V_149 -> V_159 , L_4 ) ;
if ( V_1 -> V_64 ) {
F_90 ( V_1 -> V_149 , V_160 ,
& V_161 ) ;
F_90 ( V_1 -> V_149 , V_144 ,
& V_162 ) ;
F_91 ( V_1 -> V_149 , V_163 ,
F_92 ( V_164 ) ,
0 , V_165 ) ;
V_1 -> V_149 -> V_166 = V_167 ;
} else {
F_90 ( V_1 -> V_149 , V_160 ,
& V_168 ) ;
F_90 ( V_1 -> V_149 , V_144 ,
& V_169 ) ;
V_1 -> V_149 -> V_166 = V_170 ;
}
if ( ( V_34 -> V_35 == V_171 ) ||
( V_34 -> V_35 == V_36 ) ) {
V_1 -> V_150 = NULL ;
}
else {
if ( ( V_60 = F_89 ( V_1 -> V_115 , L_5 , 1 ,
1 , 1 , & V_1 -> V_150 ) ) < 0 )
{
return V_60 ;
}
V_1 -> V_150 -> V_146 = V_1 ;
V_1 -> V_150 -> V_158 = F_79 ;
strcpy ( V_1 -> V_150 -> V_159 , L_5 ) ;
if ( V_1 -> V_64 ) {
F_90 ( V_1 -> V_150 , V_160 ,
& V_172 ) ;
F_90 ( V_1 -> V_150 , V_144 ,
& V_173 ) ;
F_91 ( V_1 -> V_150 , V_163 ,
F_92 ( V_164 ) ,
0 , V_165 ) ;
V_1 -> V_150 -> V_166 = V_167 ;
} else {
F_90 ( V_1 -> V_150 , V_160 ,
& V_174 ) ;
F_90 ( V_1 -> V_150 , V_144 ,
& V_175 ) ;
V_1 -> V_150 -> V_166 = V_170 ;
}
}
V_1 -> V_76 = 0 ;
V_1 -> V_74 = 0 ;
F_35 ( V_1 , 0 ) ;
F_10 ( V_1 ) ;
F_11 ( 0 , V_1 -> V_2 + V_86 ) ;
V_1 -> V_16 = V_91 |
V_44 |
V_92 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
if ( ( V_60 = F_93 ( V_1 -> V_115 , V_1 ) ) < 0 ) {
return V_60 ;
}
F_94 ( V_1 ) ;
V_1 -> V_96 = NULL ;
V_1 -> V_97 = NULL ;
return 0 ;
}
static void
F_95 ( struct V_176 * V_177 , struct V_178 * V_179 )
{
int V_24 ;
struct V_1 * V_1 = (struct V_1 * ) V_177 -> V_146 ;
V_1 -> V_25 = F_2 ( V_1 -> V_2 + V_18 ) ;
F_96 ( V_179 , V_1 -> V_115 -> V_180 ) ;
F_96 ( V_179 , L_6 , V_1 -> V_115 -> V_181 + 1 ) ;
F_96 ( V_179 , L_7 ) ;
if ( V_1 -> V_64 )
F_96 ( V_179 , L_8 ) ;
else
F_96 ( V_179 , L_9 ) ;
if ( F_14 ( V_1 ) ) {
F_96 ( V_179 , L_10 ) ;
} else {
F_96 ( V_179 , L_11 ) ;
}
if ( V_1 -> V_16 & V_54 ) {
F_96 ( V_179 , L_12 ) ;
} else {
F_96 ( V_179 , L_13 ) ;
}
if ( V_1 -> V_16 & V_182 ) {
F_96 ( V_179 , L_14 ) ;
} else {
F_96 ( V_179 , L_15 ) ;
}
F_96 ( V_179 , L_16 ) ;
switch ( F_19 ( V_1 ) ) {
case V_43 :
F_96 ( V_179 , L_17 ) ;
break;
case V_46 :
F_96 ( V_179 , L_18 ) ;
break;
case V_47 :
F_96 ( V_179 , L_19 ) ;
break;
case V_48 :
F_96 ( V_179 , L_20 ) ;
break;
}
if ( F_13 ( V_1 , & V_24 ) < 0 ) {
F_96 ( V_179 , L_21 ) ;
} else {
if ( V_24 ) {
F_96 ( V_179 , L_22 ) ;
} else {
F_96 ( V_179 , L_23 ) ;
}
F_96 ( V_179 , L_24 ,
F_13 ( V_1 , & V_24 ) ) ;
}
F_96 ( V_179 , L_25 ) ;
if ( V_1 -> V_16 & V_91 ) {
F_96 ( V_179 , L_26 ) ;
} else {
F_96 ( V_179 , L_27 ) ;
}
if ( V_1 -> V_16 & V_92 ) {
F_96 ( V_179 , L_28 ) ;
} else {
F_96 ( V_179 , L_29 ) ;
}
if ( !
( ( ! ( V_1 -> V_16 & V_32 ) )
&& ( ! ( V_1 -> V_16 & V_33 ) ) ) ) {
F_96 ( V_179 , L_24 ,
F_12 ( V_1 ) ) ;
}
if ( V_1 -> V_25 & V_72 ) {
F_96 ( V_179 , L_30 ) ;
} else {
F_96 ( V_179 , L_31 ) ;
}
if ( V_1 -> V_16 & V_78 ) {
F_96 ( V_179 , L_32 ) ;
} else {
F_96 ( V_179 , L_33 ) ;
}
if ( V_1 -> V_16 & V_79 ) {
F_96 ( V_179 , L_34 ) ;
} else {
F_96 ( V_179 , L_35 ) ;
}
}
static void F_94 ( struct V_1 * V_1 )
{
struct V_176 * V_177 ;
if ( ! F_97 ( V_1 -> V_115 , L_36 , & V_177 ) )
F_98 ( V_177 , V_1 , F_95 ) ;
}
static int
F_99 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
F_25 ( & V_1 -> V_71 ) ;
V_186 -> V_187 . integer . V_187 [ 0 ] =
V_1 -> V_16 & V_91 ? 0 : 1 ;
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int
F_101 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
unsigned int V_188 ;
int V_189 ;
V_188 = V_186 -> V_187 . integer . V_187 [ 0 ] ? 0 : V_91 ;
F_25 ( & V_1 -> V_71 ) ;
V_188 = ( V_1 -> V_16 & ~ V_91 ) | V_188 ;
V_189 = V_188 != V_1 -> V_16 ;
if ( V_186 -> V_187 . integer . V_187 [ 0 ] )
V_188 &= ~ V_92 ;
else
V_188 |= V_92 ;
V_1 -> V_16 = V_188 ;
F_11 ( V_188 , V_1 -> V_2 + V_18 ) ;
F_27 ( & V_1 -> V_71 ) ;
return V_189 ;
}
static int
F_102 ( struct V_183 * V_184 ,
struct V_190 * V_191 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
static char * V_192 [ 4 ] = { L_37 , L_38 , L_39 , L_40 } ;
V_191 -> type = V_193 ;
V_191 -> V_9 = 1 ;
switch ( V_1 -> V_34 -> V_35 ) {
case V_171 :
case V_194 :
V_191 -> V_187 . V_195 . V_196 = 3 ;
break;
case V_36 :
V_191 -> V_187 . V_195 . V_196 = 4 ;
break;
default:
F_103 () ;
break;
}
if ( V_191 -> V_187 . V_195 . V_197 >
V_191 -> V_187 . V_195 . V_196 - 1 ) {
V_191 -> V_187 . V_195 . V_197 =
V_191 -> V_187 . V_195 . V_196 - 1 ;
}
strcpy ( V_191 -> V_187 . V_195 . V_159 ,
V_192 [ V_191 -> V_187 . V_195 . V_197 ] ) ;
return 0 ;
}
static int
F_104 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
unsigned int V_196 = 3 ;
F_25 ( & V_1 -> V_71 ) ;
V_186 -> V_187 . V_195 . V_197 [ 0 ] = F_19 ( V_1 ) ;
switch ( V_1 -> V_34 -> V_35 ) {
case V_171 :
case V_194 :
V_196 = 3 ;
break;
case V_36 :
V_196 = 4 ;
break;
default:
F_103 () ;
break;
}
if ( V_186 -> V_187 . V_195 . V_197 [ 0 ] >= V_196 ) {
V_186 -> V_187 . V_195 . V_197 [ 0 ] = V_196 - 1 ;
}
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int
F_105 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
unsigned int V_188 ;
int V_189 , V_196 = 3 ;
switch ( V_1 -> V_34 -> V_35 ) {
case V_171 :
case V_194 :
V_196 = 3 ;
break;
case V_36 :
V_196 = 4 ;
break;
default:
F_103 () ;
break;
}
V_188 = V_186 -> V_187 . V_195 . V_197 [ 0 ] % V_196 ;
F_25 ( & V_1 -> V_71 ) ;
V_189 = V_188 != ( unsigned int ) F_19 ( V_1 ) ;
F_18 ( V_1 , V_188 ) ;
F_27 ( & V_1 -> V_71 ) ;
return V_189 ;
}
static int
F_106 ( struct V_183 * V_184 ,
struct V_190 * V_191 )
{
static char * V_192 [ 4 ] = { L_41 ,
L_42 ,
L_43 ,
L_44 } ;
V_191 -> type = V_193 ;
V_191 -> V_9 = 1 ;
V_191 -> V_187 . V_195 . V_196 = 4 ;
if ( V_191 -> V_187 . V_195 . V_197 > 3 ) {
V_191 -> V_187 . V_195 . V_197 = 3 ;
}
strcpy ( V_191 -> V_187 . V_195 . V_159 ,
V_192 [ V_191 -> V_187 . V_195 . V_197 ] ) ;
return 0 ;
}
static int
F_107 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
F_25 ( & V_1 -> V_71 ) ;
V_186 -> V_187 . V_195 . V_197 [ 0 ] = F_17 ( V_1 ) ;
F_27 ( & V_1 -> V_71 ) ;
return 0 ;
}
static int
F_108 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
unsigned int V_188 ;
int V_189 ;
V_188 = V_186 -> V_187 . V_195 . V_197 [ 0 ] % 3 ;
F_25 ( & V_1 -> V_71 ) ;
V_189 = V_188 != ( unsigned int ) F_17 ( V_1 ) ;
F_16 ( V_1 , V_188 ) ;
F_27 ( & V_1 -> V_71 ) ;
return V_189 ;
}
static T_5 F_109 ( struct V_198 * V_199 )
{
T_5 V_188 = 0 ;
V_188 |= ( V_199 -> V_200 [ 0 ] & V_201 ) ? V_78 : 0 ;
if ( V_188 & V_78 )
V_188 |= ( V_199 -> V_200 [ 0 ] & V_202 ) ? V_79 : 0 ;
else
V_188 |= ( V_199 -> V_200 [ 0 ] & V_203 ) ? V_79 : 0 ;
return V_188 ;
}
static void F_110 ( struct V_198 * V_199 , T_5 V_188 )
{
V_199 -> V_200 [ 0 ] = ( ( V_188 & V_78 ) ? V_201 : 0 ) ;
if ( V_188 & V_78 )
V_199 -> V_200 [ 0 ] |= ( V_188 & V_79 ) ? V_202 : 0 ;
else
V_199 -> V_200 [ 0 ] |= ( V_188 & V_79 ) ? V_203 : 0 ;
}
static int F_111 ( struct V_183 * V_184 ,
struct V_190 * V_191 )
{
V_191 -> type = V_204 ;
V_191 -> V_9 = 1 ;
return 0 ;
}
static int F_112 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
F_110 ( & V_186 -> V_187 . V_205 ,
V_1 -> V_110 ) ;
return 0 ;
}
static int F_113 ( struct V_183 * V_184 ,
struct V_185 * V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
int V_189 ;
T_5 V_188 ;
V_188 = F_109 ( & V_186 -> V_187 . V_205 ) ;
F_25 ( & V_1 -> V_71 ) ;
V_189 = V_188 != V_1 -> V_110 ;
V_1 -> V_110 = V_188 ;
F_27 ( & V_1 -> V_71 ) ;
return V_189 ;
}
static int F_114 ( struct V_183 * V_184 ,
struct V_190 * V_191 )
{
V_191 -> type = V_204 ;
V_191 -> V_9 = 1 ;
return 0 ;
}
static int F_115 ( struct V_183 * V_184 ,
struct V_185 *
V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
F_110 ( & V_186 -> V_187 . V_205 ,
V_1 -> V_80 ) ;
return 0 ;
}
static int F_116 ( struct V_183 * V_184 ,
struct V_185 *
V_186 )
{
struct V_1 * V_1 = F_100 ( V_184 ) ;
int V_189 ;
T_5 V_188 ;
V_188 = F_109 ( & V_186 -> V_187 . V_205 ) ;
F_25 ( & V_1 -> V_71 ) ;
V_189 = V_188 != V_1 -> V_80 ;
V_1 -> V_80 = V_188 ;
V_1 -> V_16 &= ~ ( V_78 | V_79 ) ;
V_1 -> V_16 |= V_188 ;
F_11 ( V_1 -> V_16 , V_1 -> V_2 + V_18 ) ;
F_27 ( & V_1 -> V_71 ) ;
return V_189 ;
}
static int F_117 ( struct V_183 * V_184 ,
struct V_190 * V_191 )
{
V_191 -> type = V_204 ;
V_191 -> V_9 = 1 ;
return 0 ;
}
static int F_118 ( struct V_183 * V_184 ,
struct V_185 *
V_186 )
{
V_186 -> V_187 . V_205 . V_200 [ 0 ] = V_184 -> V_206 ;
return 0 ;
}
static int F_93 ( struct V_207 * V_115 , struct V_1 * V_1 )
{
int V_208 , V_60 ;
struct V_183 * V_209 ;
for ( V_208 = 0 ; V_208 < ( int ) F_119 ( V_210 ) ; V_208 ++ ) {
if ( ( V_60 = F_120 ( V_115 , V_209 = F_121 ( & V_210 [ V_208 ] , V_1 ) ) ) < 0 )
return V_60 ;
if ( V_208 == 1 )
V_1 -> V_111 = V_209 ;
}
return 0 ;
}
static void F_122 ( struct V_207 * V_115 )
{
F_73 ( V_115 -> V_146 ) ;
}
static int
F_123 ( struct V_151 * V_34 , const struct V_211 * V_212 )
{
static int V_213 ;
struct V_1 * V_1 ;
struct V_207 * V_115 ;
int V_60 ;
if ( V_213 >= V_214 ) {
return - V_215 ;
}
if ( ! V_216 [ V_213 ] ) {
V_213 ++ ;
return - V_217 ;
}
V_60 = F_124 ( V_218 [ V_213 ] , V_118 [ V_213 ] , V_219 ,
sizeof( struct V_1 ) , & V_115 ) ;
if ( V_60 < 0 )
return V_60 ;
V_115 -> V_158 = F_122 ;
V_1 = (struct V_1 * ) V_115 -> V_146 ;
V_1 -> V_115 = V_115 ;
V_1 -> V_34 = V_34 ;
F_125 ( V_115 , & V_34 -> V_213 ) ;
if ( V_220 [ V_213 ] )
V_1 -> V_64 = 1 ;
if ( ( V_60 = F_80 ( V_1 ) ) < 0 ) {
F_126 ( V_115 ) ;
return V_60 ;
}
strcpy ( V_115 -> V_221 , L_45 ) ;
switch ( V_1 -> V_34 -> V_35 ) {
case V_171 :
strcpy ( V_115 -> V_222 , L_46 ) ;
break;
case V_194 :
strcpy ( V_115 -> V_222 , L_47 ) ;
break;
case V_36 :
strcpy ( V_115 -> V_222 , L_48 ) ;
break;
}
sprintf ( V_115 -> V_180 , L_49 ,
V_115 -> V_222 , V_1 -> V_157 , V_1 -> V_68 , V_1 -> V_93 ) ;
if ( ( V_60 = F_127 ( V_115 ) ) < 0 ) {
F_126 ( V_115 ) ;
return V_60 ;
}
F_128 ( V_34 , V_115 ) ;
V_213 ++ ;
return 0 ;
}
static void F_129 ( struct V_151 * V_34 )
{
F_126 ( F_130 ( V_34 ) ) ;
}
