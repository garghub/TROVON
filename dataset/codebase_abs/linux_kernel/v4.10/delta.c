static void F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
int V_5 ;
for ( V_5 = 7 ; V_5 >= 0 ; V_5 -- ) {
V_4 &= ~ ( V_6 | V_7 ) ;
if ( V_3 & ( 1 << V_5 ) )
V_4 |= V_6 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
V_4 |= V_7 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
}
}
static unsigned char F_4 ( struct V_1 * V_2 , unsigned char V_4 )
{
unsigned char V_3 = 0 ;
int V_5 ;
for ( V_5 = 7 ; V_5 >= 0 ; V_5 -- ) {
V_4 &= ~ V_7 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
if ( F_5 ( V_2 , V_8 ) & V_9 )
V_3 |= 1 << V_5 ;
V_4 |= V_7 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
}
return V_3 ;
}
static unsigned char F_6 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
V_4 = F_5 ( V_2 , V_8 ) ;
switch ( V_2 -> V_10 . V_11 ) {
case V_12 :
case V_13 :
V_4 &= ~ V_14 ;
V_4 |= V_15 | V_16 ;
break;
case V_17 :
case V_18 :
V_4 |= V_7 | V_19 ;
V_4 &= ~ V_20 ;
break;
case V_21 :
V_4 |= V_22 | V_23 |
V_24 ;
V_4 &= ~ V_25 ;
break;
case V_26 :
V_4 |= V_27 | V_28 | V_29 ;
V_4 &= ~ V_30 ;
break;
}
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned char V_4 )
{
switch ( V_2 -> V_10 . V_11 ) {
case V_12 :
case V_13 :
V_4 &= ~ V_14 ;
V_4 |= V_31 ;
break;
case V_17 :
case V_18 :
V_4 |= V_20 ;
break;
case V_21 :
V_4 |= V_25 ;
break;
case V_26 :
V_4 |= V_30 ;
break;
}
F_2 ( V_2 , V_8 , V_4 ) ;
}
static int F_8 ( struct V_32 * V_33 , unsigned char * V_34 , int V_35 )
{
struct V_1 * V_2 = V_33 -> V_36 -> V_37 ;
int V_38 = V_35 ;
unsigned char V_4 ;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_6 ( V_2 ) ;
F_1 ( V_2 , ( V_33 -> V_40 << 1 ) | 0 , V_4 ) ;
while ( V_35 -- > 0 )
F_1 ( V_2 , * V_34 ++ , V_4 ) ;
F_7 ( V_2 , V_4 ) ;
F_10 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_11 ( struct V_32 * V_33 , unsigned char * V_34 , int V_35 )
{
struct V_1 * V_2 = V_33 -> V_36 -> V_37 ;
int V_38 = V_35 ;
unsigned char V_4 ;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_6 ( V_2 ) ;
F_1 ( V_2 , ( V_33 -> V_40 << 1 ) | 1 , V_4 ) ;
while ( V_35 -- > 0 )
* V_34 ++ = F_4 ( V_2 , V_4 ) ;
F_7 ( V_2 , V_4 ) ;
F_10 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_12 ( struct V_41 * V_36 , unsigned short V_40 )
{
if ( V_40 == 0x10 )
return 1 ;
return - V_42 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned char V_43 )
{
unsigned char V_4 , V_44 , V_45 ;
int V_5 ;
V_44 = V_46 ;
V_45 = V_47 ;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_5 ( V_2 , V_8 ) ;
for ( V_5 = 7 ; V_5 >= 0 ; V_5 -- ) {
V_4 &= ~ ( V_44 | V_45 ) ;
if ( V_43 & ( 1 << V_5 ) )
V_4 |= V_45 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 100 ) ;
V_4 |= V_44 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 100 ) ;
}
V_4 &= ~ V_44 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_10 ( & V_2 -> V_39 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
F_15 ( & V_49 -> V_50 . V_51 , V_2 -> V_52 . V_53 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
unsigned int V_54 ;
int V_55 ;
V_54 = F_17 ( & V_49 -> V_50 . V_51 ) ;
F_18 ( & V_2 -> V_56 ) ;
V_55 = V_2 -> V_52 . V_53 != V_54 ;
V_2 -> V_52 . V_53 = V_54 ;
if ( V_55 && V_2 -> V_57 == NULL ) {
F_19 ( & V_2 -> V_56 ) ;
F_13 ( V_2 , V_54 ) ;
} else {
F_19 ( & V_2 -> V_56 ) ;
}
return V_55 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
F_15 ( & V_49 -> V_50 . V_51 , V_2 -> V_52 . V_58 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
unsigned int V_54 ;
int V_55 ;
V_54 = F_17 ( & V_49 -> V_50 . V_51 ) ;
F_18 ( & V_2 -> V_56 ) ;
V_55 = V_2 -> V_52 . V_58 != V_54 ;
V_2 -> V_52 . V_58 = V_54 ;
if ( V_55 && V_2 -> V_57 != NULL ) {
F_19 ( & V_2 -> V_56 ) ;
F_13 ( V_2 , V_54 ) ;
} else {
F_19 ( & V_2 -> V_56 ) ;
}
return V_55 ;
}
static void F_22 ( struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_60 -> V_64 [ 0 ] ;
struct V_1 * V_2 = V_60 -> V_37 [ 0 ] ;
F_23 ( V_2 ) ;
V_63 -> V_65 =
V_63 -> V_66 = V_61 == 0 ? V_67 :
V_68 ;
}
static void F_24 ( struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_60 -> V_64 [ 0 ] ;
struct V_1 * V_2 = V_60 -> V_37 [ 0 ] ;
F_23 ( V_2 ) ;
V_63 -> V_65 = V_14 ;
V_63 -> V_66 = V_61 << 4 ;
}
static void F_25 ( struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_60 -> V_64 [ 0 ] ;
struct V_1 * V_2 = V_60 -> V_37 [ 0 ] ;
F_23 ( V_2 ) ;
V_63 -> V_65 =
V_63 -> V_66 = V_61 == 0 ? V_23 :
V_24 ;
}
static void F_26 ( struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_60 -> V_64 [ 0 ] ;
struct V_1 * V_2 = V_60 -> V_37 [ 0 ] ;
F_23 ( V_2 ) ;
V_63 -> V_65 =
V_63 -> V_66 = V_61 == 0 ? V_28 :
V_29 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_69 )
{
unsigned char V_4 , V_70 ;
if ( V_69 == 0 )
return;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_5 ( V_2 , V_8 ) ;
V_70 = V_4 & ~ V_71 ;
if ( V_69 > 48000 )
V_70 |= V_71 ;
if ( V_4 != V_70 )
F_2 ( V_2 , V_8 , V_70 ) ;
F_10 ( & V_2 -> V_39 ) ;
}
static void F_28 ( struct V_59 * V_60 , unsigned int V_69 )
{
unsigned char V_4 , V_70 ;
struct V_1 * V_2 = V_60 -> V_37 [ 0 ] ;
if ( V_69 == 0 )
return;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_5 ( V_2 , V_8 ) ;
F_10 ( & V_2 -> V_39 ) ;
V_70 = V_4 & ~ V_71 ;
if ( V_69 > 48000 )
V_70 |= V_71 ;
if ( V_4 == V_70 )
return;
F_29 ( V_60 , 1 ) ;
F_9 ( & V_2 -> V_39 ) ;
V_4 = F_5 ( V_2 , V_8 ) & ~ V_71 ;
if ( V_69 > 48000 )
V_4 |= V_71 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_10 ( & V_2 -> V_39 ) ;
F_29 ( V_60 , 0 ) ;
}
static void F_30 ( struct V_59 * V_60 , unsigned int V_69 )
{
unsigned char V_54 ;
V_54 = ( V_69 > 48000 ) ? 0x65 : 0x60 ;
if ( F_31 ( V_60 , 0 , 0x02 ) != V_54 ||
F_31 ( V_60 , 1 , 0x02 ) != V_54 ) {
F_29 ( V_60 , 1 ) ;
F_32 ( V_60 , 0 , 0x02 , V_54 ) ;
F_32 ( V_60 , 1 , 0x02 , V_54 ) ;
F_29 ( V_60 , 0 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
V_2 -> V_52 . V_58 = V_2 -> V_52 . V_53 ;
}
static void F_34 ( struct V_1 * V_2 , int V_69 )
{
unsigned long V_74 ;
unsigned int V_4 ;
int V_55 ;
F_35 ( & V_2 -> V_56 , V_74 ) ;
V_4 = V_2 -> V_52 . V_58 ;
if ( V_4 & 0x01 )
V_4 &= ( V_4 & 0x01 ) ? ~ 0x06 : ~ 0x18 ;
switch ( V_69 ) {
case 32000 : V_4 |= ( V_4 & 0x01 ) ? 0x04 : 0x00 ; break;
case 44100 : V_4 |= ( V_4 & 0x01 ) ? 0x00 : 0x10 ; break;
case 48000 : V_4 |= ( V_4 & 0x01 ) ? 0x02 : 0x08 ; break;
default: V_4 |= ( V_4 & 0x01 ) ? 0x00 : 0x18 ; break;
}
V_55 = V_2 -> V_52 . V_58 != V_4 ;
V_2 -> V_52 . V_58 = V_4 ;
F_36 ( & V_2 -> V_56 , V_74 ) ;
if ( V_55 )
F_37 ( V_2 -> V_75 , V_76 , & V_2 -> V_52 . V_77 -> V_78 ) ;
F_13 ( V_2 , V_4 ) ;
}
static int F_38 ( struct V_79 * V_80 ,
struct V_48 * V_49 )
{
char V_81 = 0x10 ;
struct V_1 * V_2 = F_39 ( V_80 ) ;
if ( F_40 ( V_2 -> V_82 , & V_81 , 1 ) != 1 )
F_41 ( V_2 -> V_75 -> V_83 ,
L_1 , V_81 ) ;
F_42 ( V_2 -> V_82 , & V_81 , 1 ) ;
V_49 -> V_50 . integer . V_50 [ 0 ] = ( V_81 & V_84 ) ? 1 : 0 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
unsigned char V_85 [ V_86 ] ;
unsigned char V_87 [ V_86 ] ;
switch ( V_2 -> V_10 . V_11 ) {
case V_17 :
case V_18 :
case V_12 :
case V_13 :
case V_26 :
case V_21 :
F_44 ( V_2 -> V_88 , V_2 -> V_82 ) ;
break;
case V_89 :
case V_90 :
break;
case V_91 :
case V_92 :
F_13 ( V_2 , V_2 -> V_52 . V_53 ) ;
break;
}
if ( V_2 -> V_93 ) {
memcpy ( V_85 , V_2 -> V_94 -> V_95 , sizeof( V_85 ) ) ;
memcpy ( V_87 , V_2 -> V_94 -> V_96 , sizeof( V_87 ) ) ;
F_45 ( V_2 -> V_94 ) ;
memcpy ( V_2 -> V_94 -> V_95 , V_85 , sizeof( V_85 ) ) ;
memcpy ( V_2 -> V_94 -> V_96 , V_87 , sizeof( V_87 ) ) ;
F_29 ( V_2 -> V_94 , 0 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 )
F_29 ( V_2 -> V_94 , 1 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_97 ;
struct V_59 * V_60 ;
unsigned char V_4 ;
if ( V_2 -> V_10 . V_11 == V_89 &&
V_2 -> V_10 . V_98 == 0x7b )
V_2 -> V_10 . V_11 = V_12 ;
if ( V_2 -> V_10 . V_11 == V_92 &&
V_2 -> V_10 . V_98 == 0xfb )
V_2 -> V_10 . V_11 = V_21 ;
switch ( V_2 -> V_10 . V_11 ) {
case V_17 :
V_2 -> V_99 = 2 ;
V_2 -> V_100 = 2 ;
break;
case V_18 :
V_2 -> V_99 = 8 ;
V_2 -> V_100 = 2 ;
break;
case V_101 :
case V_92 :
V_2 -> V_99 = V_2 -> V_102 ? 8 : 4 ;
V_2 -> V_100 = V_2 -> V_102 ? 8 : 4 ;
break;
case V_89 :
case V_12 :
case V_13 :
case V_90 :
case V_103 :
V_2 -> V_99 = 8 ;
V_2 -> V_100 = 8 ;
break;
case V_91 :
V_2 -> V_99 = 4 ;
break;
case V_26 :
case V_21 :
V_2 -> V_99 = 4 ;
V_2 -> V_100 = 4 ;
break;
}
#ifdef F_48
V_2 -> V_104 = F_43 ;
V_2 -> V_105 = F_46 ;
V_2 -> V_106 = 1 ;
#endif
V_4 = F_5 ( V_2 , V_8 ) ;
V_4 |= V_7 ;
F_2 ( V_2 , V_8 , V_4 ) ;
F_3 ( 5 ) ;
switch ( V_2 -> V_10 . V_11 ) {
case V_17 :
case V_18 :
case V_12 :
case V_13 :
case V_26 :
case V_21 :
if ( ( V_97 = F_49 ( V_2 -> V_75 , L_2 , NULL , & V_2 -> V_88 ) ) < 0 ) {
F_41 ( V_2 -> V_75 -> V_83 , L_3 ) ;
return V_97 ;
}
V_2 -> V_88 -> V_37 = V_2 ;
V_2 -> V_88 -> V_107 = & V_108 ;
if ( ( V_97 = F_50 ( V_2 , V_109 ) ) < 0 )
return V_97 ;
break;
case V_89 :
case V_90 :
V_2 -> V_110 . V_111 = F_27 ;
break;
case V_91 :
V_2 -> V_110 . V_111 = F_27 ;
case V_92 :
V_2 -> V_52 . V_107 . V_112 = F_33 ;
V_2 -> V_52 . V_107 . V_113 = F_34 ;
V_2 -> V_52 . V_107 . V_114 = F_14 ;
V_2 -> V_52 . V_107 . V_115 = F_16 ;
V_2 -> V_52 . V_107 . V_116 = F_20 ;
V_2 -> V_52 . V_107 . V_117 = F_21 ;
F_13 ( V_2 , V_2 -> V_52 . V_53 ) ;
break;
}
switch ( V_2 -> V_10 . V_11 ) {
case V_89 :
case V_12 :
case V_91 :
case V_90 :
return 0 ;
}
V_60 = V_2 -> V_94 = F_51 ( sizeof( struct V_59 ) , V_118 ) ;
if ( ! V_60 )
return - V_119 ;
V_2 -> V_93 = 1 ;
switch ( V_2 -> V_10 . V_11 ) {
case V_17 :
V_97 = F_52 ( V_60 , & V_120 , & V_121 , V_2 ) ;
break;
case V_18 :
V_97 = F_52 ( V_60 , & V_122 , & V_123 , V_2 ) ;
break;
case V_13 :
case V_103 :
V_97 = F_52 ( V_60 , & V_124 , & V_125 , V_2 ) ;
break;
case V_92 :
case V_101 :
V_97 = F_52 ( V_60 , & V_126 , & V_127 , V_2 ) ;
break;
case V_26 :
V_97 = F_52 ( V_60 , & V_128 , & V_129 , V_2 ) ;
break;
case V_21 :
V_97 = F_52 ( V_60 , & V_130 , & V_131 , V_2 ) ;
break;
default:
F_53 () ;
return - V_132 ;
}
return V_97 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_97 ;
switch ( V_2 -> V_10 . V_11 ) {
case V_89 :
case V_90 :
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_133 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_134 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
break;
case V_91 :
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_135 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
break;
case V_12 :
case V_13 :
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_136 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_137 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
break;
}
switch ( V_2 -> V_10 . V_11 ) {
case V_89 :
case V_91 :
case V_92 :
case V_90 :
V_97 = F_57 ( V_2 ) ;
if ( V_97 < 0 )
return V_97 ;
break;
}
switch ( V_2 -> V_10 . V_11 ) {
case V_89 :
case V_91 :
case V_92 :
case V_90 :
V_97 = F_55 ( V_2 -> V_75 , F_56 ( & V_138 , V_2 ) ) ;
if ( V_97 < 0 )
return V_97 ;
break;
}
switch ( V_2 -> V_10 . V_11 ) {
case V_13 :
case V_17 :
case V_18 :
case V_101 :
case V_92 :
case V_26 :
case V_21 :
case V_103 :
V_97 = F_58 ( V_2 ) ;
if ( V_97 < 0 )
return V_97 ;
break;
}
return 0 ;
}
