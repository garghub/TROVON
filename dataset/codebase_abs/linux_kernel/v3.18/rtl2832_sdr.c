static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_6 ;
#define F_2 24
#define F_3 (MAX_WR_LEN + 1)
T_1 V_7 [ F_3 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( F_4 ( V_5 > F_2 ) )
return - V_14 ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_5 ( V_2 -> V_15 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_6 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_18 ;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_19 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_5 ( V_2 -> V_15 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_6 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_18 ;
}
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_3 ,
const T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_20 = ( V_3 >> 0 ) & 0xff ;
T_1 V_21 = ( V_3 >> 8 ) & 0xff ;
if ( V_21 != V_2 -> V_21 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_21 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_21 = V_21 ;
}
return F_1 ( V_2 , V_20 , V_4 , V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_20 = ( V_3 >> 0 ) & 0xff ;
T_1 V_21 = ( V_3 >> 8 ) & 0xff ;
if ( V_21 != V_2 -> V_21 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_21 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_21 = V_21 ;
}
return F_7 ( V_2 , V_20 , V_4 , V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 )
{
return F_8 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_4 , T_1 V_22 )
{
int V_6 ;
T_1 V_23 ;
if ( V_22 != 0xff ) {
V_6 = F_9 ( V_2 , V_3 , & V_23 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_22 ;
V_23 &= ~ V_22 ;
V_4 |= V_23 ;
}
return F_8 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static struct V_24 * F_12 (
struct V_1 * V_2 )
{
unsigned long V_13 ;
struct V_24 * V_7 = NULL ;
F_13 ( & V_2 -> V_25 , V_13 ) ;
if ( F_14 ( & V_2 -> V_26 ) )
goto V_27;
V_7 = F_15 ( V_2 -> V_26 . V_28 ,
struct V_24 , V_29 ) ;
F_16 ( & V_7 -> V_29 ) ;
V_27:
F_17 ( & V_2 -> V_25 , V_13 ) ;
return V_7 ;
}
static unsigned int F_18 ( struct V_1 * V_2 ,
void * V_30 , const T_1 * V_31 , unsigned int V_32 )
{
unsigned int V_33 ;
if ( V_2 -> V_34 == V_35 ) {
memcpy ( V_30 , V_31 , V_32 ) ;
V_33 = V_32 ;
} else if ( V_2 -> V_34 == V_36 ) {
unsigned int V_37 ;
T_2 * V_38 = V_30 ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ )
* V_38 ++ = ( V_31 [ V_37 ] << 8 ) | ( V_31 [ V_37 ] >> 0 ) ;
V_33 = 2 * V_32 ;
} else {
V_33 = 0 ;
}
if ( F_19 ( F_20 ( V_2 -> V_39 ) ) ) {
#define F_21 10000UL
unsigned int V_40 = F_22 ( V_41 -
V_2 -> V_39 + F_23 ( F_21 ) ) ;
unsigned int V_42 = V_2 -> V_43 - V_2 -> V_44 ;
V_2 -> V_39 = V_41 + F_23 ( F_21 ) ;
V_2 -> V_44 = V_2 -> V_43 ;
F_24 ( & V_2 -> V_45 -> V_16 ,
L_3 ,
V_32 , V_42 , V_40 ,
V_42 * 1000UL / V_40 ) ;
}
V_2 -> V_43 += V_32 / 2 ;
return V_33 ;
}
static void F_25 ( struct V_46 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_47 ;
struct V_24 * V_48 ;
F_26 ( & V_2 -> V_45 -> V_16 ,
L_4 ,
V_46 -> V_49 , V_46 -> V_50 ,
V_46 -> V_51 , V_46 -> V_52 ) ;
switch ( V_46 -> V_49 ) {
case 0 :
case - V_53 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
return;
default:
F_27 ( & V_2 -> V_45 -> V_16 , L_5 ,
V_46 -> V_49 ) ;
break;
}
if ( F_28 ( V_46 -> V_50 > 0 ) ) {
void * V_57 ;
unsigned int V_5 ;
V_48 = F_12 ( V_2 ) ;
if ( F_19 ( V_48 == NULL ) ) {
V_2 -> V_58 ++ ;
F_29 ( & V_2 -> V_45 -> V_16 ,
L_6 ,
V_2 -> V_58 ) ;
goto V_59;
}
V_57 = F_30 ( & V_48 -> V_60 , 0 ) ;
V_5 = F_18 ( V_2 , V_57 , V_46 -> V_61 ,
V_46 -> V_50 ) ;
F_31 ( & V_48 -> V_60 , 0 , V_5 ) ;
F_32 ( & V_48 -> V_60 . V_62 . V_63 ) ;
V_48 -> V_60 . V_62 . V_64 = V_2 -> V_64 ++ ;
F_33 ( & V_48 -> V_60 , V_65 ) ;
}
V_59:
F_34 ( V_46 , V_66 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = V_2 -> V_67 - 1 ; V_37 >= 0 ; V_37 -- ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_7 , V_37 ) ;
F_36 ( V_2 -> V_68 [ V_37 ] ) ;
}
V_2 -> V_67 = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_37 , V_6 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_69 ; V_37 ++ ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_8 , V_37 ) ;
V_6 = F_34 ( V_2 -> V_68 [ V_37 ] , V_66 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_45 -> V_16 ,
L_9 ,
V_37 ) ;
F_35 ( V_2 ) ;
return V_6 ;
}
V_2 -> V_67 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_70 ) {
while ( V_2 -> V_71 ) {
V_2 -> V_71 -- ;
F_24 ( & V_2 -> V_45 -> V_16 , L_10 , V_2 -> V_71 ) ;
F_39 ( V_2 -> V_45 , V_2 -> V_72 ,
V_2 -> V_73 [ V_2 -> V_71 ] ,
V_2 -> V_74 [ V_2 -> V_71 ] ) ;
}
}
V_2 -> V_13 &= ~ V_70 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
V_2 -> V_71 = 0 ;
V_2 -> V_72 = V_75 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_11 ,
V_76 * V_75 ) ;
for ( V_2 -> V_71 = 0 ; V_2 -> V_71 < V_76 ; V_2 -> V_71 ++ ) {
V_2 -> V_73 [ V_2 -> V_71 ] = F_41 ( V_2 -> V_45 ,
V_75 , V_66 ,
& V_2 -> V_74 [ V_2 -> V_71 ] ) ;
if ( ! V_2 -> V_73 [ V_2 -> V_71 ] ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_12 ,
V_2 -> V_71 ) ;
F_38 ( V_2 ) ;
return - V_77 ;
}
F_24 ( & V_2 -> V_45 -> V_16 , L_13 ,
V_2 -> V_71 , V_2 -> V_73 [ V_2 -> V_71 ] ,
( long long ) V_2 -> V_74 [ V_2 -> V_71 ] ) ;
V_2 -> V_13 |= V_70 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_37 ;
F_35 ( V_2 ) ;
for ( V_37 = V_2 -> V_69 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_2 -> V_68 [ V_37 ] ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_14 , V_37 ) ;
F_43 ( V_2 -> V_68 [ V_37 ] ) ;
}
}
V_2 -> V_69 = 0 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_37 , V_78 ;
for ( V_37 = 0 ; V_37 < V_76 ; V_37 ++ ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_15 , V_37 ) ;
V_2 -> V_68 [ V_37 ] = F_45 ( 0 , V_66 ) ;
if ( ! V_2 -> V_68 [ V_37 ] ) {
F_24 ( & V_2 -> V_45 -> V_16 , L_16 ) ;
for ( V_78 = 0 ; V_78 < V_37 ; V_78 ++ )
F_43 ( V_2 -> V_68 [ V_78 ] ) ;
return - V_77 ;
}
F_46 ( V_2 -> V_68 [ V_37 ] ,
V_2 -> V_45 ,
F_47 ( V_2 -> V_45 , 0x81 ) ,
V_2 -> V_73 [ V_37 ] ,
V_75 ,
F_25 , V_2 ) ;
V_2 -> V_68 [ V_37 ] -> V_79 = V_80 ;
V_2 -> V_68 [ V_37 ] -> V_81 = V_2 -> V_74 [ V_37 ] ;
V_2 -> V_69 ++ ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
F_13 ( & V_2 -> V_25 , V_13 ) ;
while ( ! F_14 ( & V_2 -> V_26 ) ) {
struct V_24 * V_7 ;
V_7 = F_15 ( V_2 -> V_26 . V_28 ,
struct V_24 , V_29 ) ;
F_16 ( & V_7 -> V_29 ) ;
F_33 ( & V_7 -> V_60 , V_82 ) ;
}
F_17 ( & V_2 -> V_25 , V_13 ) ;
}
static void F_49 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_85 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
F_50 ( & V_2 -> V_86 ) ;
F_50 ( & V_2 -> V_87 ) ;
V_2 -> V_45 = NULL ;
F_51 ( & V_2 -> V_88 ) ;
F_52 ( & V_2 -> V_89 ) ;
F_53 ( & V_2 -> V_87 ) ;
F_53 ( & V_2 -> V_86 ) ;
F_54 ( & V_2 -> V_88 ) ;
V_84 -> V_85 = NULL ;
}
static int F_55 ( struct V_90 * V_90 , void * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
F_57 ( V_93 -> V_94 , V_17 , sizeof( V_93 -> V_94 ) ) ;
F_57 ( V_93 -> V_95 , V_2 -> V_89 . V_96 , sizeof( V_93 -> V_95 ) ) ;
F_58 ( V_2 -> V_45 , V_93 -> V_97 , sizeof( V_93 -> V_97 ) ) ;
V_93 -> V_98 = V_99 | V_100 |
V_101 | V_102 ;
V_93 -> V_103 = V_93 -> V_98 | V_104 ;
return 0 ;
}
static int F_59 ( struct V_105 * V_106 ,
const struct V_107 * V_108 , unsigned int * V_109 ,
unsigned int * V_110 , unsigned int V_111 [] , void * V_112 [] )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_18 , * V_109 ) ;
if ( V_106 -> V_113 + * V_109 < 8 )
* V_109 = 8 - V_106 -> V_113 ;
* V_110 = 1 ;
V_111 [ 0 ] = F_61 ( V_2 -> V_114 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_19 ,
* V_109 , V_111 [ 0 ] ) ;
return 0 ;
}
static int F_62 ( struct V_115 * V_60 )
{
struct V_1 * V_2 = F_60 ( V_60 -> V_105 ) ;
if ( ! V_2 -> V_45 )
return - V_116 ;
return 0 ;
}
static void F_63 ( struct V_115 * V_60 )
{
struct V_1 * V_2 = F_60 ( V_60 -> V_105 ) ;
struct V_24 * V_7 =
F_64 ( V_60 , struct V_24 , V_60 ) ;
unsigned long V_13 ;
if ( ! V_2 -> V_45 ) {
F_33 ( & V_7 -> V_60 , V_82 ) ;
return;
}
F_13 ( & V_2 -> V_25 , V_13 ) ;
F_65 ( & V_7 -> V_29 , & V_2 -> V_26 ) ;
F_17 ( & V_2 -> V_25 , V_13 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
int V_6 ;
unsigned int V_117 , V_118 ;
T_1 V_7 [ 4 ] , V_119 , V_120 ;
T_3 V_121 ;
T_4 V_122 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_20 , V_2 -> V_123 ) ;
if ( ! F_67 ( V_124 , & V_2 -> V_13 ) )
return 0 ;
if ( V_2 -> V_123 == 0 )
return 0 ;
V_117 = V_2 -> V_123 ;
V_6 = F_8 ( V_2 , 0x13e , L_21 , 2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x115 , L_22 , 4 ) ;
if ( V_6 )
goto V_125;
if ( V_84 -> V_126 . V_127 . V_128 )
V_6 = V_84 -> V_126 . V_127 . V_128 ( V_84 , & V_118 ) ;
else
V_6 = - V_14 ;
if ( V_6 )
goto V_125;
V_121 = V_118 % V_2 -> V_11 -> V_129 ;
V_121 *= 0x400000 ;
V_121 = F_68 ( V_121 , V_2 -> V_11 -> V_129 ) ;
V_121 = - V_121 ;
V_122 = V_121 & 0x3fffff ;
F_24 ( & V_2 -> V_45 -> V_16 , L_23 , V_118 , V_122 ) ;
V_7 [ 0 ] = ( V_122 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( V_122 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_122 >> 0 ) & 0xff ;
V_6 = F_8 ( V_2 , 0x119 , V_7 , 3 ) ;
if ( V_6 )
goto V_125;
if ( V_118 ) {
V_119 = 0x1a ;
V_120 = 0x8d ;
} else {
V_119 = 0x1b ;
V_120 = 0xcd ;
}
V_6 = F_10 ( V_2 , 0x1b1 , V_119 ) ;
if ( V_6 )
goto V_125;
V_6 = F_10 ( V_2 , 0x008 , V_120 ) ;
if ( V_6 )
goto V_125;
V_6 = F_10 ( V_2 , 0x006 , 0x80 ) ;
if ( V_6 )
goto V_125;
V_122 = F_68 ( V_2 -> V_11 -> V_129 * 0x400000ULL , V_117 * 4U ) ;
V_122 <<= 2 ;
V_7 [ 0 ] = ( V_122 >> 24 ) & 0xff ;
V_7 [ 1 ] = ( V_122 >> 16 ) & 0xff ;
V_7 [ 2 ] = ( V_122 >> 8 ) & 0xff ;
V_7 [ 3 ] = ( V_122 >> 0 ) & 0xff ;
V_6 = F_8 ( V_2 , 0x19f , V_7 , 4 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x11c ,
L_24 ,
20 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x017 , L_25 , 2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x019 , L_26 , 1 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x01a , L_27 , 6 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x192 , L_28 , 3 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x061 , L_29 , 1 ) ;
if ( V_6 )
goto V_125;
switch ( V_2 -> V_11 -> V_130 ) {
case V_131 :
V_6 = F_8 ( V_2 , 0x112 , L_30 , 1 ) ;
V_6 = F_8 ( V_2 , 0x102 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x103 , L_30 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c7 , L_32 , 1 ) ;
V_6 = F_8 ( V_2 , 0x104 , L_33 , 1 ) ;
V_6 = F_8 ( V_2 , 0x105 , L_34 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c8 , L_35 , 1 ) ;
V_6 = F_8 ( V_2 , 0x106 , L_36 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c9 , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ca , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cb , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x107 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cd , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ce , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x108 , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x109 , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10a , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10b , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x011 , L_43 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1e5 , L_44 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d9 , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1db , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1dd , L_45 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1de , L_46 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d8 , L_47 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1e6 , L_48 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d7 , L_49 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00d , L_50 , 1 ) ;
V_6 = F_8 ( V_2 , 0x010 , L_51 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00d , L_52 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00d , L_53 , 1 ) ;
V_6 = F_8 ( V_2 , 0x013 , L_48 , 1 ) ;
break;
case V_132 :
case V_133 :
V_6 = F_8 ( V_2 , 0x112 , L_30 , 1 ) ;
V_6 = F_8 ( V_2 , 0x102 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x103 , L_30 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c7 , L_54 , 1 ) ;
V_6 = F_8 ( V_2 , 0x104 , L_55 , 1 ) ;
V_6 = F_8 ( V_2 , 0x105 , L_34 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c8 , L_56 , 1 ) ;
V_6 = F_8 ( V_2 , 0x106 , L_36 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c9 , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ca , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cb , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x107 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cd , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ce , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x108 , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x109 , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10a , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10b , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x011 , L_57 , 2 ) ;
V_6 = F_8 ( V_2 , 0x1e5 , L_44 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d9 , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1db , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1dd , L_58 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1de , L_59 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d8 , L_47 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1e6 , L_48 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1d7 , L_49 , 1 ) ;
break;
case V_134 :
V_6 = F_8 ( V_2 , 0x112 , L_30 , 1 ) ;
V_6 = F_8 ( V_2 , 0x102 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x115 , L_60 , 1 ) ;
V_6 = F_8 ( V_2 , 0x103 , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c7 , L_61 , 1 ) ;
V_6 = F_8 ( V_2 , 0x104 , L_55 , 1 ) ;
V_6 = F_8 ( V_2 , 0x105 , L_34 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c8 , L_45 , 1 ) ;
V_6 = F_8 ( V_2 , 0x106 , L_36 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1c9 , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ca , L_37 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cb , L_38 , 1 ) ;
V_6 = F_8 ( V_2 , 0x107 , L_31 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1cd , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x1ce , L_39 , 1 ) ;
V_6 = F_8 ( V_2 , 0x108 , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x109 , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10a , L_40 , 1 ) ;
V_6 = F_8 ( V_2 , 0x10b , L_41 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x00e , L_42 , 1 ) ;
V_6 = F_8 ( V_2 , 0x011 , L_62 , 1 ) ;
break;
default:
F_69 ( & V_2 -> V_45 -> V_16 , L_63 ) ;
}
V_6 = F_11 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_6 )
goto V_125;
V_6 = F_11 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_6 )
goto V_125;
V_125:
return V_6 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_6 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
V_6 = F_8 ( V_2 , 0x061 , L_64 , 1 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x019 , L_65 , 1 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x017 , L_25 , 2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x192 , L_66 , 3 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x13e , L_67 , 2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_8 ( V_2 , 0x115 , L_68 , 4 ) ;
if ( V_6 )
goto V_125;
V_125:
return;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_135 * V_136 = & V_84 -> V_137 ;
struct V_138 * V_139 ;
struct V_138 * V_140 ;
if ( V_2 -> V_141 == 0 )
return 0 ;
V_139 = F_72 ( & V_2 -> V_142 ,
V_143 ) ;
V_140 = F_72 ( & V_2 -> V_142 , V_144 ) ;
if ( F_73 ( V_139 ) ) {
V_136 -> V_145 = V_2 -> V_123 ;
F_74 ( V_140 , V_2 -> V_123 ) ;
} else {
V_136 -> V_145 = F_73 ( V_140 ) ;
}
V_136 -> V_146 = V_2 -> V_141 ;
V_136 -> V_147 = V_148 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_69 ,
V_136 -> V_146 , V_136 -> V_145 ) ;
if ( ! F_67 ( V_124 , & V_2 -> V_13 ) )
return 0 ;
if ( V_84 -> V_126 . V_127 . V_149 )
V_84 -> V_126 . V_127 . V_149 ( V_84 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
if ( V_84 -> V_126 . V_127 . V_150 )
V_84 -> V_126 . V_127 . V_150 ( V_84 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
if ( V_84 -> V_126 . V_127 . V_151 )
V_84 -> V_126 . V_127 . V_151 ( V_84 ) ;
return;
}
static int F_77 ( struct V_105 * V_106 , unsigned int V_152 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
int V_6 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
if ( ! V_2 -> V_45 )
return - V_116 ;
if ( F_78 ( & V_2 -> V_87 ) )
return - V_153 ;
if ( V_2 -> V_154 -> V_155 -> V_156 )
V_2 -> V_154 -> V_155 -> V_156 ( V_2 -> V_154 , 1 ) ;
F_79 ( V_124 , & V_2 -> V_13 ) ;
V_6 = F_75 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_71 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_66 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_40 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_6 = F_44 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_2 -> V_64 = 0 ;
V_6 = F_37 ( V_2 ) ;
if ( V_6 )
goto V_125;
V_125:
F_53 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static void F_80 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_35 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
F_48 ( V_2 ) ;
F_70 ( V_2 ) ;
F_76 ( V_2 ) ;
F_81 ( V_124 , & V_2 -> V_13 ) ;
if ( V_2 -> V_154 -> V_155 -> V_156 )
V_2 -> V_154 -> V_155 -> V_156 ( V_2 -> V_154 , 0 ) ;
F_53 ( & V_2 -> V_87 ) ;
}
static int F_82 ( struct V_90 * V_90 , void * V_157 ,
struct V_158 * V_159 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_70 , V_159 -> V_160 , V_159 -> type ) ;
if ( V_159 -> V_160 == 0 ) {
F_57 ( V_159 -> V_96 , L_71 , sizeof( V_159 -> V_96 ) ) ;
V_159 -> type = V_161 ;
V_159 -> V_162 = V_163 | V_164 ;
V_159 -> V_165 = 300000 ;
V_159 -> V_166 = 3200000 ;
} else if ( V_159 -> V_160 == 1 ) {
F_57 ( V_159 -> V_96 , L_72 , sizeof( V_159 -> V_96 ) ) ;
V_159 -> type = V_167 ;
V_159 -> V_162 = V_163 | V_164 ;
V_159 -> V_165 = 50000000 ;
V_159 -> V_166 = 2000000000 ;
} else {
return - V_14 ;
}
return 0 ;
}
static int F_83 ( struct V_90 * V_90 , void * V_157 ,
const struct V_158 * V_159 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
if ( V_159 -> V_160 > 1 )
return - V_14 ;
return 0 ;
}
static int F_84 ( struct V_90 * V_90 , void * V_157 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_73 ,
V_169 -> V_130 , V_169 -> type , V_169 -> V_160 ) ;
if ( V_169 -> V_130 == 0 ) {
if ( V_169 -> V_160 >= F_85 ( V_170 ) )
return - V_14 ;
* V_169 = V_170 [ V_169 -> V_160 ] ;
} else if ( V_169 -> V_130 == 1 ) {
if ( V_169 -> V_160 >= F_85 ( V_171 ) )
return - V_14 ;
* V_169 = V_171 [ V_169 -> V_160 ] ;
} else {
return - V_14 ;
}
return 0 ;
}
static int F_86 ( struct V_90 * V_90 , void * V_157 ,
struct V_172 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
int V_6 = 0 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_74 ,
V_173 -> V_130 , V_173 -> type ) ;
if ( V_173 -> V_130 == 0 ) {
V_173 -> V_146 = V_2 -> V_123 ;
V_173 -> type = V_161 ;
} else if ( V_173 -> V_130 == 1 ) {
V_173 -> V_146 = V_2 -> V_141 ;
V_173 -> type = V_167 ;
} else {
return - V_14 ;
}
return V_6 ;
}
static int F_87 ( struct V_90 * V_90 , void * V_157 ,
const struct V_172 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
int V_6 , V_169 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_75 ,
V_173 -> V_130 , V_173 -> type , V_173 -> V_146 ) ;
#define F_88 ((bands_adc[0].rangehigh + bands_adc[1].rangelow) / 2)
#define F_89 ((bands_adc[1].rangehigh + bands_adc[2].rangelow) / 2)
if ( V_173 -> V_130 == 0 && V_173 -> type == V_161 ) {
if ( V_173 -> V_146 < F_88 )
V_169 = 0 ;
else if ( V_173 -> V_146 < F_89 )
V_169 = 1 ;
else
V_169 = 2 ;
V_2 -> V_123 = F_90 (unsigned int, f->frequency,
bands_adc[band].rangelow,
bands_adc[band].rangehigh) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_76 , V_2 -> V_123 ) ;
V_6 = F_66 ( V_2 ) ;
} else if ( V_173 -> V_130 == 1 ) {
V_2 -> V_141 = F_90 (unsigned int, f->frequency,
bands_fm[0].rangelow,
bands_fm[0].rangehigh) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_77 , V_173 -> V_146 ) ;
V_6 = F_71 ( V_2 ) ;
} else {
V_6 = - V_14 ;
}
return V_6 ;
}
static int F_91 ( struct V_90 * V_90 , void * V_157 ,
struct V_174 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
if ( V_173 -> V_160 >= V_2 -> V_175 )
return - V_14 ;
F_57 ( V_173 -> V_176 , V_177 [ V_173 -> V_160 ] . V_96 , sizeof( V_173 -> V_176 ) ) ;
V_173 -> V_34 = V_177 [ V_173 -> V_160 ] . V_34 ;
return 0 ;
}
static int F_92 ( struct V_90 * V_90 , void * V_157 ,
struct V_107 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
F_24 ( & V_2 -> V_45 -> V_16 , L_17 ) ;
V_173 -> V_108 . V_178 . V_34 = V_2 -> V_34 ;
V_173 -> V_108 . V_178 . V_114 = V_2 -> V_114 ;
memset ( V_173 -> V_108 . V_178 . V_179 , 0 , sizeof( V_173 -> V_108 . V_178 . V_179 ) ) ;
return 0 ;
}
static int F_93 ( struct V_90 * V_90 , void * V_157 ,
struct V_107 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
struct V_105 * V_180 = & V_2 -> V_181 ;
int V_37 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_78 ,
( char * ) & V_173 -> V_108 . V_178 . V_34 ) ;
if ( F_94 ( V_180 ) )
return - V_182 ;
memset ( V_173 -> V_108 . V_178 . V_179 , 0 , sizeof( V_173 -> V_108 . V_178 . V_179 ) ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_175 ; V_37 ++ ) {
if ( V_177 [ V_37 ] . V_34 == V_173 -> V_108 . V_178 . V_34 ) {
V_2 -> V_34 = V_177 [ V_37 ] . V_34 ;
V_2 -> V_114 = V_177 [ V_37 ] . V_114 ;
V_173 -> V_108 . V_178 . V_114 = V_177 [ V_37 ] . V_114 ;
return 0 ;
}
}
V_2 -> V_34 = V_177 [ 0 ] . V_34 ;
V_2 -> V_114 = V_177 [ 0 ] . V_114 ;
V_173 -> V_108 . V_178 . V_34 = V_177 [ 0 ] . V_34 ;
V_173 -> V_108 . V_178 . V_114 = V_177 [ 0 ] . V_114 ;
return 0 ;
}
static int F_95 ( struct V_90 * V_90 , void * V_157 ,
struct V_107 * V_173 )
{
struct V_1 * V_2 = F_56 ( V_90 ) ;
int V_37 ;
F_24 ( & V_2 -> V_45 -> V_16 , L_78 ,
( char * ) & V_173 -> V_108 . V_178 . V_34 ) ;
memset ( V_173 -> V_108 . V_178 . V_179 , 0 , sizeof( V_173 -> V_108 . V_178 . V_179 ) ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_175 ; V_37 ++ ) {
if ( V_177 [ V_37 ] . V_34 == V_173 -> V_108 . V_178 . V_34 ) {
V_173 -> V_108 . V_178 . V_114 = V_177 [ V_37 ] . V_114 ;
return 0 ;
}
}
V_173 -> V_108 . V_178 . V_34 = V_177 [ 0 ] . V_34 ;
V_173 -> V_108 . V_178 . V_114 = V_177 [ 0 ] . V_114 ;
return 0 ;
}
static int F_96 ( struct V_138 * V_183 )
{
struct V_1 * V_2 =
F_64 ( V_183 -> V_184 , struct V_1 ,
V_142 ) ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_135 * V_136 = & V_84 -> V_137 ;
int V_6 ;
F_24 ( & V_2 -> V_45 -> V_16 ,
L_79 ,
V_183 -> V_185 , V_183 -> V_96 , V_183 -> V_4 ,
V_183 -> V_186 , V_183 -> V_187 , V_183 -> V_188 ) ;
switch ( V_183 -> V_185 ) {
case V_143 :
case V_144 :
if ( V_2 -> V_139 -> V_4 ) {
T_5 V_4 = V_2 -> V_123 + F_68 ( V_2 -> V_140 -> V_188 , 2 ) ;
T_4 V_189 ;
V_4 = F_90 ( T_5 , V_4 , V_2 -> V_140 -> V_186 ,
V_2 -> V_140 -> V_187 ) ;
V_189 = V_4 - V_2 -> V_140 -> V_186 ;
V_189 = V_2 -> V_140 -> V_188 *
F_68 ( V_189 , V_2 -> V_140 -> V_188 ) ;
V_2 -> V_140 -> V_4 = V_2 -> V_140 -> V_186 + V_189 ;
}
V_136 -> V_145 = V_2 -> V_140 -> V_4 ;
if ( ! F_67 ( V_124 , & V_2 -> V_13 ) )
return 0 ;
if ( V_84 -> V_126 . V_127 . V_149 )
V_6 = V_84 -> V_126 . V_127 . V_149 ( V_84 ) ;
else
V_6 = 0 ;
break;
default:
V_6 = - V_14 ;
}
return V_6 ;
}
static void F_97 ( struct V_190 * V_159 )
{
struct V_1 * V_2 =
F_64 ( V_159 , struct V_1 , V_88 ) ;
F_98 ( & V_2 -> V_142 ) ;
F_99 ( & V_2 -> V_88 ) ;
F_100 ( V_2 ) ;
}
struct V_83 * F_101 ( struct V_83 * V_84 ,
struct V_191 * V_15 , const struct V_192 * V_11 ,
struct V_193 * V_194 )
{
int V_6 ;
struct V_1 * V_2 ;
const struct V_195 * V_126 = & V_196 ;
struct V_197 * V_154 = F_102 ( V_15 ) ;
V_2 = F_103 ( sizeof( struct V_1 ) , V_198 ) ;
if ( V_2 == NULL ) {
F_6 ( & V_154 -> V_45 -> V_16 ,
L_80 ) ;
return NULL ;
}
V_2 -> V_84 = V_84 ;
V_2 -> V_154 = V_154 ;
V_2 -> V_45 = V_154 -> V_45 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_123 = V_170 [ 0 ] . V_165 ;
V_2 -> V_141 = V_171 [ 0 ] . V_165 ;
V_2 -> V_34 = V_177 [ 0 ] . V_34 ;
V_2 -> V_114 = V_177 [ 0 ] . V_114 ;
V_2 -> V_175 = V_199 ;
if ( ! V_200 )
V_2 -> V_175 -= 1 ;
F_104 ( & V_2 -> V_87 ) ;
F_104 ( & V_2 -> V_86 ) ;
F_105 ( & V_2 -> V_25 ) ;
F_106 ( & V_2 -> V_26 ) ;
V_2 -> V_181 . type = V_201 ;
V_2 -> V_181 . V_202 = V_203 | V_204 | V_205 ;
V_2 -> V_181 . V_206 = V_2 ;
V_2 -> V_181 . V_207 = sizeof( struct V_24 ) ;
V_2 -> V_181 . V_126 = & V_208 ;
V_2 -> V_181 . V_209 = & V_210 ;
V_2 -> V_181 . V_211 = V_212 ;
V_6 = F_107 ( & V_2 -> V_181 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_45 -> V_16 , L_81 ) ;
goto V_213;
}
switch ( V_2 -> V_11 -> V_130 ) {
case V_131 :
F_108 ( & V_2 -> V_142 , 9 ) ;
if ( V_194 )
F_109 ( & V_2 -> V_142 , V_194 -> V_214 , NULL ) ;
break;
case V_134 :
F_108 ( & V_2 -> V_142 , 2 ) ;
V_2 -> V_139 = F_110 ( & V_2 -> V_142 , V_126 ,
V_143 ,
0 , 1 , 1 , 1 ) ;
V_2 -> V_140 = F_110 ( & V_2 -> V_142 , V_126 ,
V_144 ,
0 , 8000000 , 100000 , 0 ) ;
F_111 ( 2 , & V_2 -> V_139 , 0 , false ) ;
break;
case V_132 :
case V_133 :
F_108 ( & V_2 -> V_142 , 2 ) ;
V_2 -> V_139 = F_110 ( & V_2 -> V_142 , V_126 ,
V_143 ,
0 , 1 , 1 , 1 ) ;
V_2 -> V_140 = F_110 ( & V_2 -> V_142 , V_126 ,
V_144 ,
6000000 , 8000000 , 1000000 ,
6000000 ) ;
F_111 ( 2 , & V_2 -> V_139 , 0 , false ) ;
break;
default:
F_108 ( & V_2 -> V_142 , 0 ) ;
F_69 ( & V_2 -> V_45 -> V_16 , L_82 ,
V_17 ) ;
goto V_215;
}
if ( V_2 -> V_142 . error ) {
V_6 = V_2 -> V_142 . error ;
F_6 ( & V_2 -> V_45 -> V_16 , L_83 ) ;
goto V_215;
}
V_2 -> V_89 = V_216 ;
V_2 -> V_89 . V_217 = & V_2 -> V_181 ;
V_2 -> V_89 . V_217 -> V_218 = & V_2 -> V_86 ;
F_112 ( & V_2 -> V_89 , V_2 ) ;
V_2 -> V_88 . V_219 = F_97 ;
V_6 = F_113 ( & V_2 -> V_45 -> V_16 , & V_2 -> V_88 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_45 -> V_16 ,
L_84 , V_6 ) ;
goto V_215;
}
V_2 -> V_88 . V_214 = & V_2 -> V_142 ;
V_2 -> V_89 . V_88 = & V_2 -> V_88 ;
V_2 -> V_89 . V_218 = & V_2 -> V_87 ;
V_2 -> V_89 . V_220 = V_221 ;
V_6 = F_114 ( & V_2 -> V_89 , V_222 , - 1 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_45 -> V_16 ,
L_85 ,
V_6 ) ;
goto V_223;
}
F_115 ( & V_2 -> V_45 -> V_16 , L_86 ,
F_116 ( & V_2 -> V_89 ) ) ;
V_84 -> V_85 = V_2 ;
V_84 -> V_126 . V_224 = F_49 ;
F_115 ( & V_2 -> V_15 -> V_16 , L_87 ,
V_17 ) ;
F_69 ( & V_2 -> V_45 -> V_16 ,
L_88 ,
V_17 ) ;
return V_84 ;
V_223:
F_99 ( & V_2 -> V_88 ) ;
V_215:
F_98 ( & V_2 -> V_142 ) ;
V_213:
F_100 ( V_2 ) ;
return NULL ;
}
