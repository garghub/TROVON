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
unsigned long V_13 = 0 ;
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
unsigned int V_40 = V_2 -> V_41 - V_2 -> V_42 ;
V_2 -> V_39 = V_43 + F_22 ( F_21 ) ;
V_2 -> V_42 = V_2 -> V_41 ;
F_23 ( & V_2 -> V_44 -> V_16 ,
L_3 ,
V_32 , V_40 , F_21 ,
V_40 * 1000UL / F_21 ) ;
}
V_2 -> V_41 += V_32 / 2 ;
return V_33 ;
}
static void F_24 ( struct V_45 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_24 * V_47 ;
F_25 ( & V_2 -> V_44 -> V_16 ,
L_4 ,
V_48 , V_45 -> V_49 , V_45 -> V_50 ,
V_45 -> V_51 , V_45 -> V_52 ) ;
switch ( V_45 -> V_49 ) {
case 0 :
case - V_53 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
return;
default:
F_26 ( & V_2 -> V_44 -> V_16 , L_5 ,
V_45 -> V_49 ) ;
break;
}
if ( F_27 ( V_45 -> V_50 > 0 ) ) {
void * V_57 ;
unsigned int V_5 ;
V_47 = F_12 ( V_2 ) ;
if ( F_19 ( V_47 == NULL ) ) {
V_2 -> V_58 ++ ;
F_28 ( & V_2 -> V_44 -> V_16 ,
L_6 ,
V_2 -> V_58 ) ;
goto V_59;
}
V_57 = F_29 ( & V_47 -> V_60 , 0 ) ;
V_5 = F_18 ( V_2 , V_57 , V_45 -> V_61 ,
V_45 -> V_50 ) ;
F_30 ( & V_47 -> V_60 , 0 , V_5 ) ;
F_31 ( & V_47 -> V_60 . V_62 . V_63 ) ;
V_47 -> V_60 . V_62 . V_64 = V_2 -> V_64 ++ ;
F_32 ( & V_47 -> V_60 , V_65 ) ;
}
V_59:
F_33 ( V_45 , V_66 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = V_2 -> V_67 - 1 ; V_37 >= 0 ; V_37 -- ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_7 , V_48 , V_37 ) ;
F_35 ( V_2 -> V_68 [ V_37 ] ) ;
}
V_2 -> V_67 = 0 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_37 , V_6 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_69 ; V_37 ++ ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_8 , V_48 , V_37 ) ;
V_6 = F_33 ( V_2 -> V_68 [ V_37 ] , V_66 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_44 -> V_16 ,
L_9 ,
V_37 ) ;
F_34 ( V_2 ) ;
return V_6 ;
}
V_2 -> V_67 ++ ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_70 ) {
while ( V_2 -> V_71 ) {
V_2 -> V_71 -- ;
F_23 ( & V_2 -> V_44 -> V_16 , L_10 ,
V_48 , V_2 -> V_71 ) ;
F_38 ( V_2 -> V_44 , V_2 -> V_72 ,
V_2 -> V_73 [ V_2 -> V_71 ] ,
V_2 -> V_74 [ V_2 -> V_71 ] ) ;
}
}
V_2 -> V_13 &= ~ V_70 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
V_2 -> V_71 = 0 ;
V_2 -> V_72 = V_75 ;
F_23 ( & V_2 -> V_44 -> V_16 ,
L_11 ,
V_48 , V_76 * V_75 ) ;
for ( V_2 -> V_71 = 0 ; V_2 -> V_71 < V_76 ; V_2 -> V_71 ++ ) {
V_2 -> V_73 [ V_2 -> V_71 ] = F_40 ( V_2 -> V_44 ,
V_75 , V_66 ,
& V_2 -> V_74 [ V_2 -> V_71 ] ) ;
if ( ! V_2 -> V_73 [ V_2 -> V_71 ] ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_12 ,
V_48 , V_2 -> V_71 ) ;
F_37 ( V_2 ) ;
return - V_77 ;
}
F_23 ( & V_2 -> V_44 -> V_16 , L_13 ,
V_48 , V_2 -> V_71 ,
V_2 -> V_73 [ V_2 -> V_71 ] ,
( long long ) V_2 -> V_74 [ V_2 -> V_71 ] ) ;
V_2 -> V_13 |= V_70 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_37 ;
F_34 ( V_2 ) ;
for ( V_37 = V_2 -> V_69 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_2 -> V_68 [ V_37 ] ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_14 ,
V_48 , V_37 ) ;
F_42 ( V_2 -> V_68 [ V_37 ] ) ;
}
}
V_2 -> V_69 = 0 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_37 , V_78 ;
for ( V_37 = 0 ; V_37 < V_76 ; V_37 ++ ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_15 , V_48 , V_37 ) ;
V_2 -> V_68 [ V_37 ] = F_44 ( 0 , V_66 ) ;
if ( ! V_2 -> V_68 [ V_37 ] ) {
F_23 ( & V_2 -> V_44 -> V_16 , L_16 , V_48 ) ;
for ( V_78 = 0 ; V_78 < V_37 ; V_78 ++ )
F_42 ( V_2 -> V_68 [ V_78 ] ) ;
return - V_77 ;
}
F_45 ( V_2 -> V_68 [ V_37 ] ,
V_2 -> V_44 ,
F_46 ( V_2 -> V_44 , 0x81 ) ,
V_2 -> V_73 [ V_37 ] ,
V_75 ,
F_24 , V_2 ) ;
V_2 -> V_68 [ V_37 ] -> V_79 = V_80 ;
V_2 -> V_68 [ V_37 ] -> V_81 = V_2 -> V_74 [ V_37 ] ;
V_2 -> V_69 ++ ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned long V_13 = 0 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
F_13 ( & V_2 -> V_25 , V_13 ) ;
while ( ! F_14 ( & V_2 -> V_26 ) ) {
struct V_24 * V_7 ;
V_7 = F_15 ( V_2 -> V_26 . V_28 ,
struct V_24 , V_29 ) ;
F_16 ( & V_7 -> V_29 ) ;
F_32 ( & V_7 -> V_60 , V_82 ) ;
}
F_17 ( & V_2 -> V_25 , V_13 ) ;
}
static void F_48 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_85 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
F_49 ( & V_2 -> V_86 ) ;
F_49 ( & V_2 -> V_87 ) ;
V_2 -> V_44 = NULL ;
F_50 ( & V_2 -> V_88 ) ;
F_51 ( & V_2 -> V_89 ) ;
F_52 ( & V_2 -> V_87 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_53 ( & V_2 -> V_88 ) ;
V_84 -> V_85 = NULL ;
}
static int F_54 ( struct V_90 * V_90 , void * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
F_56 ( V_93 -> V_94 , V_17 , sizeof( V_93 -> V_94 ) ) ;
F_56 ( V_93 -> V_95 , V_2 -> V_89 . V_96 , sizeof( V_93 -> V_95 ) ) ;
F_57 ( V_2 -> V_44 , V_93 -> V_97 , sizeof( V_93 -> V_97 ) ) ;
V_93 -> V_98 = V_99 | V_100 |
V_101 | V_102 ;
V_93 -> V_103 = V_93 -> V_98 | V_104 ;
return 0 ;
}
static int F_58 ( struct V_105 * V_106 ,
const struct V_107 * V_108 , unsigned int * V_109 ,
unsigned int * V_110 , unsigned int V_111 [] , void * V_112 [] )
{
struct V_1 * V_2 = F_59 ( V_106 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_18 , V_48 , * V_109 ) ;
if ( V_106 -> V_113 + * V_109 < 8 )
* V_109 = 8 - V_106 -> V_113 ;
* V_110 = 1 ;
V_111 [ 0 ] = F_60 ( V_75 * 2 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_19 ,
V_48 , * V_109 , V_111 [ 0 ] ) ;
return 0 ;
}
static int F_61 ( struct V_114 * V_60 )
{
struct V_1 * V_2 = F_59 ( V_60 -> V_105 ) ;
if ( ! V_2 -> V_44 )
return - V_115 ;
return 0 ;
}
static void F_62 ( struct V_114 * V_60 )
{
struct V_1 * V_2 = F_59 ( V_60 -> V_105 ) ;
struct V_24 * V_7 =
F_63 ( V_60 , struct V_24 , V_60 ) ;
unsigned long V_13 = 0 ;
if ( ! V_2 -> V_44 ) {
F_32 ( & V_7 -> V_60 , V_82 ) ;
return;
}
F_13 ( & V_2 -> V_25 , V_13 ) ;
F_64 ( & V_7 -> V_29 , & V_2 -> V_26 ) ;
F_17 ( & V_2 -> V_25 , V_13 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
int V_6 ;
unsigned int V_116 , V_117 ;
T_1 V_7 [ 4 ] , V_118 , V_119 ;
T_3 V_120 ;
T_4 V_121 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_20 , V_48 , V_2 -> V_122 ) ;
if ( ! F_66 ( V_123 , & V_2 -> V_13 ) )
return 0 ;
if ( V_2 -> V_122 == 0 )
return 0 ;
V_116 = V_2 -> V_122 ;
V_6 = F_8 ( V_2 , 0x13e , L_21 , 2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x115 , L_22 , 4 ) ;
if ( V_6 )
goto V_124;
if ( V_84 -> V_125 . V_126 . V_127 )
V_6 = V_84 -> V_125 . V_126 . V_127 ( V_84 , & V_117 ) ;
else
V_6 = - V_14 ;
if ( V_6 )
goto V_124;
V_120 = V_117 % V_2 -> V_11 -> V_128 ;
V_120 *= 0x400000 ;
V_120 = F_67 ( V_120 , V_2 -> V_11 -> V_128 ) ;
V_120 = - V_120 ;
V_121 = V_120 & 0x3fffff ;
F_23 ( & V_2 -> V_44 -> V_16 , L_23 ,
V_48 , V_117 , V_121 ) ;
V_7 [ 0 ] = ( V_121 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( V_121 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_121 >> 0 ) & 0xff ;
V_6 = F_8 ( V_2 , 0x119 , V_7 , 3 ) ;
if ( V_6 )
goto V_124;
if ( V_117 ) {
V_118 = 0x1a ;
V_119 = 0x8d ;
} else {
V_118 = 0x1b ;
V_119 = 0xcd ;
}
V_6 = F_10 ( V_2 , 0x1b1 , V_118 ) ;
if ( V_6 )
goto V_124;
V_6 = F_10 ( V_2 , 0x008 , V_119 ) ;
if ( V_6 )
goto V_124;
V_6 = F_10 ( V_2 , 0x006 , 0x80 ) ;
if ( V_6 )
goto V_124;
V_121 = F_67 ( V_2 -> V_11 -> V_128 * 0x400000ULL , V_116 * 4U ) ;
V_121 <<= 2 ;
V_7 [ 0 ] = ( V_121 >> 24 ) & 0xff ;
V_7 [ 1 ] = ( V_121 >> 16 ) & 0xff ;
V_7 [ 2 ] = ( V_121 >> 8 ) & 0xff ;
V_7 [ 3 ] = ( V_121 >> 0 ) & 0xff ;
V_6 = F_8 ( V_2 , 0x19f , V_7 , 4 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x11c ,
L_24 ,
20 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x017 , L_25 , 2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x019 , L_26 , 1 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x01a , L_27 , 6 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x192 , L_28 , 3 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x061 , L_29 , 1 ) ;
if ( V_6 )
goto V_124;
switch ( V_2 -> V_11 -> V_129 ) {
case V_130 :
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
case V_131 :
case V_132 :
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
case V_133 :
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
F_68 ( & V_2 -> V_44 -> V_16 , L_63 ) ;
}
V_6 = F_11 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_6 )
goto V_124;
V_6 = F_11 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_6 )
goto V_124;
V_124:
return V_6 ;
}
static void F_69 ( struct V_1 * V_2 )
{
int V_6 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
V_6 = F_8 ( V_2 , 0x061 , L_64 , 1 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x019 , L_65 , 1 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x017 , L_25 , 2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x192 , L_66 , 3 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x13e , L_67 , 2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_8 ( V_2 , 0x115 , L_68 , 4 ) ;
if ( V_6 )
goto V_124;
V_124:
return;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_134 * V_135 = & V_84 -> V_136 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
if ( V_2 -> V_140 == 0 )
return 0 ;
V_138 = F_71 ( & V_2 -> V_141 , V_142 ) ;
V_139 = F_71 ( & V_2 -> V_141 , V_143 ) ;
if ( F_72 ( V_138 ) ) {
V_135 -> V_144 = V_2 -> V_122 ;
F_73 ( V_139 , V_2 -> V_122 ) ;
} else {
V_135 -> V_144 = F_72 ( V_139 ) ;
}
V_135 -> V_145 = V_2 -> V_140 ;
V_135 -> V_146 = V_147 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_69 ,
V_48 , V_135 -> V_145 , V_135 -> V_144 ) ;
if ( ! F_66 ( V_123 , & V_2 -> V_13 ) )
return 0 ;
if ( V_84 -> V_125 . V_126 . V_148 )
V_84 -> V_125 . V_126 . V_148 ( V_84 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
if ( V_84 -> V_125 . V_126 . V_149 )
V_84 -> V_125 . V_126 . V_149 ( V_84 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
if ( V_84 -> V_125 . V_126 . V_150 )
V_84 -> V_125 . V_126 . V_150 ( V_84 ) ;
return;
}
static int F_76 ( struct V_105 * V_106 , unsigned int V_151 )
{
struct V_1 * V_2 = F_59 ( V_106 ) ;
int V_6 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
if ( ! V_2 -> V_44 )
return - V_115 ;
if ( F_77 ( & V_2 -> V_87 ) )
return - V_152 ;
if ( V_2 -> V_153 -> V_154 -> V_155 )
V_2 -> V_153 -> V_154 -> V_155 ( V_2 -> V_153 , 1 ) ;
F_78 ( V_123 , & V_2 -> V_13 ) ;
V_6 = F_74 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_70 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_65 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_39 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_6 = F_43 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_2 -> V_64 = 0 ;
V_6 = F_36 ( V_2 ) ;
if ( V_6 )
goto V_124;
V_124:
F_52 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static void F_79 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_59 ( V_106 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
F_49 ( & V_2 -> V_87 ) ;
F_34 ( V_2 ) ;
F_41 ( V_2 ) ;
F_37 ( V_2 ) ;
F_47 ( V_2 ) ;
F_69 ( V_2 ) ;
F_75 ( V_2 ) ;
F_80 ( V_123 , & V_2 -> V_13 ) ;
if ( V_2 -> V_153 -> V_154 -> V_155 )
V_2 -> V_153 -> V_154 -> V_155 ( V_2 -> V_153 , 0 ) ;
F_52 ( & V_2 -> V_87 ) ;
}
static int F_81 ( struct V_90 * V_90 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_70 ,
V_48 , V_158 -> V_159 , V_158 -> type ) ;
if ( V_158 -> V_159 == 0 ) {
F_56 ( V_158 -> V_96 , L_71 , sizeof( V_158 -> V_96 ) ) ;
V_158 -> type = V_160 ;
V_158 -> V_161 = V_162 | V_163 ;
V_158 -> V_164 = 300000 ;
V_158 -> V_165 = 3200000 ;
} else if ( V_158 -> V_159 == 1 ) {
F_56 ( V_158 -> V_96 , L_72 , sizeof( V_158 -> V_96 ) ) ;
V_158 -> type = V_166 ;
V_158 -> V_161 = V_162 | V_163 ;
V_158 -> V_164 = 50000000 ;
V_158 -> V_165 = 2000000000 ;
} else {
return - V_14 ;
}
return 0 ;
}
static int F_82 ( struct V_90 * V_90 , void * V_156 ,
const struct V_157 * V_158 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
if ( V_158 -> V_159 > 1 )
return - V_14 ;
return 0 ;
}
static int F_83 ( struct V_90 * V_90 , void * V_156 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_73 ,
V_48 , V_168 -> V_129 , V_168 -> type , V_168 -> V_159 ) ;
if ( V_168 -> V_129 == 0 ) {
if ( V_168 -> V_159 >= F_84 ( V_169 ) )
return - V_14 ;
* V_168 = V_169 [ V_168 -> V_159 ] ;
} else if ( V_168 -> V_129 == 1 ) {
if ( V_168 -> V_159 >= F_84 ( V_170 ) )
return - V_14 ;
* V_168 = V_170 [ V_168 -> V_159 ] ;
} else {
return - V_14 ;
}
return 0 ;
}
static int F_85 ( struct V_90 * V_90 , void * V_156 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
int V_6 = 0 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_74 ,
V_48 , V_172 -> V_129 , V_172 -> type ) ;
if ( V_172 -> V_129 == 0 ) {
V_172 -> V_145 = V_2 -> V_122 ;
V_172 -> type = V_160 ;
} else if ( V_172 -> V_129 == 1 ) {
V_172 -> V_145 = V_2 -> V_140 ;
V_172 -> type = V_166 ;
} else {
return - V_14 ;
}
return V_6 ;
}
static int F_86 ( struct V_90 * V_90 , void * V_156 ,
const struct V_171 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
int V_6 , V_168 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_75 ,
V_48 , V_172 -> V_129 , V_172 -> type , V_172 -> V_145 ) ;
#define F_87 ((bands_adc[0].rangehigh + bands_adc[1].rangelow) / 2)
#define F_88 ((bands_adc[1].rangehigh + bands_adc[2].rangelow) / 2)
if ( V_172 -> V_129 == 0 && V_172 -> type == V_160 ) {
if ( V_172 -> V_145 < F_87 )
V_168 = 0 ;
else if ( V_172 -> V_145 < F_88 )
V_168 = 1 ;
else
V_168 = 2 ;
V_2 -> V_122 = F_89 (unsigned int, f->frequency,
bands_adc[band].rangelow,
bands_adc[band].rangehigh) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_76 ,
V_48 , V_2 -> V_122 ) ;
V_6 = F_65 ( V_2 ) ;
} else if ( V_172 -> V_129 == 1 ) {
V_2 -> V_140 = F_89 (unsigned int, f->frequency,
bands_fm[0].rangelow,
bands_fm[0].rangehigh) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_77 ,
V_48 , V_172 -> V_145 ) ;
V_6 = F_70 ( V_2 ) ;
} else {
V_6 = - V_14 ;
}
return V_6 ;
}
static int F_90 ( struct V_90 * V_90 , void * V_156 ,
struct V_173 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
if ( V_172 -> V_159 >= V_174 )
return - V_14 ;
F_56 ( V_172 -> V_175 , V_176 [ V_172 -> V_159 ] . V_96 , sizeof( V_172 -> V_175 ) ) ;
V_172 -> V_34 = V_176 [ V_172 -> V_159 ] . V_34 ;
return 0 ;
}
static int F_91 ( struct V_90 * V_90 , void * V_156 ,
struct V_107 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_23 ( & V_2 -> V_44 -> V_16 , L_17 , V_48 ) ;
V_172 -> V_108 . V_177 . V_34 = V_2 -> V_34 ;
memset ( V_172 -> V_108 . V_177 . V_178 , 0 , sizeof( V_172 -> V_108 . V_177 . V_178 ) ) ;
return 0 ;
}
static int F_92 ( struct V_90 * V_90 , void * V_156 ,
struct V_107 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
struct V_105 * V_179 = & V_2 -> V_180 ;
int V_37 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_78 , V_48 ,
( char * ) & V_172 -> V_108 . V_177 . V_34 ) ;
if ( F_93 ( V_179 ) )
return - V_181 ;
memset ( V_172 -> V_108 . V_177 . V_178 , 0 , sizeof( V_172 -> V_108 . V_177 . V_178 ) ) ;
for ( V_37 = 0 ; V_37 < V_174 ; V_37 ++ ) {
if ( V_176 [ V_37 ] . V_34 == V_172 -> V_108 . V_177 . V_34 ) {
V_2 -> V_34 = V_172 -> V_108 . V_177 . V_34 ;
return 0 ;
}
}
V_172 -> V_108 . V_177 . V_34 = V_176 [ 0 ] . V_34 ;
V_2 -> V_34 = V_176 [ 0 ] . V_34 ;
return 0 ;
}
static int F_94 ( struct V_90 * V_90 , void * V_156 ,
struct V_107 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
int V_37 ;
F_23 ( & V_2 -> V_44 -> V_16 , L_78 , V_48 ,
( char * ) & V_172 -> V_108 . V_177 . V_34 ) ;
memset ( V_172 -> V_108 . V_177 . V_178 , 0 , sizeof( V_172 -> V_108 . V_177 . V_178 ) ) ;
for ( V_37 = 0 ; V_37 < V_174 ; V_37 ++ ) {
if ( V_176 [ V_37 ] . V_34 == V_172 -> V_108 . V_177 . V_34 )
return 0 ;
}
V_172 -> V_108 . V_177 . V_34 = V_176 [ 0 ] . V_34 ;
return 0 ;
}
static int F_95 ( struct V_137 * V_182 )
{
struct V_1 * V_2 =
F_63 ( V_182 -> V_183 , struct V_1 ,
V_141 ) ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_134 * V_135 = & V_84 -> V_136 ;
int V_6 ;
F_23 ( & V_2 -> V_44 -> V_16 ,
L_79 ,
V_48 , V_182 -> V_184 , V_182 -> V_96 , V_182 -> V_4 ,
V_182 -> V_185 , V_182 -> V_186 , V_182 -> V_187 ) ;
switch ( V_182 -> V_184 ) {
case V_142 :
case V_143 :
if ( V_2 -> V_138 -> V_4 ) {
T_5 V_4 = V_2 -> V_122 + V_2 -> V_139 -> V_187 / 2 ;
T_4 V_188 ;
V_4 = F_96 ( V_4 , V_2 -> V_139 -> V_185 , V_2 -> V_139 -> V_186 ) ;
V_188 = V_4 - V_2 -> V_139 -> V_185 ;
V_188 = V_2 -> V_139 -> V_187 * ( V_188 / V_2 -> V_139 -> V_187 ) ;
V_2 -> V_139 -> V_4 = V_2 -> V_139 -> V_185 + V_188 ;
}
V_135 -> V_144 = V_2 -> V_139 -> V_4 ;
if ( ! F_66 ( V_123 , & V_2 -> V_13 ) )
return 0 ;
if ( V_84 -> V_125 . V_126 . V_148 )
V_6 = V_84 -> V_125 . V_126 . V_148 ( V_84 ) ;
else
V_6 = 0 ;
break;
default:
V_6 = - V_14 ;
}
return V_6 ;
}
static void F_97 ( struct V_189 * V_158 )
{
struct V_1 * V_2 =
F_63 ( V_158 , struct V_1 , V_88 ) ;
F_98 ( & V_2 -> V_141 ) ;
F_99 ( & V_2 -> V_88 ) ;
F_100 ( V_2 ) ;
}
struct V_83 * F_101 ( struct V_83 * V_84 ,
struct V_190 * V_15 , const struct V_191 * V_11 ,
struct V_192 * V_193 )
{
int V_6 ;
struct V_1 * V_2 ;
const struct V_194 * V_125 = & V_195 ;
struct V_196 * V_153 = F_102 ( V_15 ) ;
V_2 = F_103 ( sizeof( struct V_1 ) , V_197 ) ;
if ( V_2 == NULL ) {
F_6 ( & V_153 -> V_44 -> V_16 ,
L_80 ) ;
return NULL ;
}
V_2 -> V_84 = V_84 ;
V_2 -> V_153 = V_153 ;
V_2 -> V_44 = V_153 -> V_44 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_122 = V_169 [ 0 ] . V_164 ;
V_2 -> V_140 = V_170 [ 0 ] . V_164 ;
V_2 -> V_34 = V_35 ;
F_104 ( & V_2 -> V_87 ) ;
F_104 ( & V_2 -> V_86 ) ;
F_105 ( & V_2 -> V_25 ) ;
F_106 ( & V_2 -> V_26 ) ;
V_2 -> V_180 . type = V_198 ;
V_2 -> V_180 . V_199 = V_200 | V_201 | V_202 ;
V_2 -> V_180 . V_203 = V_2 ;
V_2 -> V_180 . V_204 = sizeof( struct V_24 ) ;
V_2 -> V_180 . V_125 = & V_205 ;
V_2 -> V_180 . V_206 = & V_207 ;
V_2 -> V_180 . V_208 = V_209 ;
V_6 = F_107 ( & V_2 -> V_180 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_44 -> V_16 , L_81 ) ;
goto V_210;
}
switch ( V_2 -> V_11 -> V_129 ) {
case V_130 :
F_108 ( & V_2 -> V_141 , 9 ) ;
if ( V_193 )
F_109 ( & V_2 -> V_141 , V_193 -> V_211 , NULL ) ;
break;
case V_133 :
F_108 ( & V_2 -> V_141 , 2 ) ;
V_2 -> V_138 = F_110 ( & V_2 -> V_141 , V_125 , V_142 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_139 = F_110 ( & V_2 -> V_141 , V_125 , V_143 , 0 , 8000000 , 100000 , 0 ) ;
F_111 ( 2 , & V_2 -> V_138 , 0 , false ) ;
break;
case V_131 :
case V_132 :
F_108 ( & V_2 -> V_141 , 2 ) ;
V_2 -> V_138 = F_110 ( & V_2 -> V_141 , V_125 , V_142 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_139 = F_110 ( & V_2 -> V_141 , V_125 , V_143 , 6000000 , 8000000 , 1000000 , 6000000 ) ;
F_111 ( 2 , & V_2 -> V_138 , 0 , false ) ;
break;
default:
F_108 ( & V_2 -> V_141 , 0 ) ;
F_68 ( & V_2 -> V_44 -> V_16 , L_82 ,
V_17 ) ;
goto V_212;
}
if ( V_2 -> V_141 . error ) {
V_6 = V_2 -> V_141 . error ;
F_6 ( & V_2 -> V_44 -> V_16 , L_83 ) ;
goto V_212;
}
V_2 -> V_89 = V_213 ;
V_2 -> V_89 . V_214 = & V_2 -> V_180 ;
V_2 -> V_89 . V_214 -> V_215 = & V_2 -> V_86 ;
F_78 ( V_216 , & V_2 -> V_89 . V_13 ) ;
F_112 ( & V_2 -> V_89 , V_2 ) ;
V_2 -> V_88 . V_217 = F_97 ;
V_6 = F_113 ( & V_2 -> V_44 -> V_16 , & V_2 -> V_88 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_44 -> V_16 ,
L_84 , V_6 ) ;
goto V_212;
}
V_2 -> V_88 . V_211 = & V_2 -> V_141 ;
V_2 -> V_89 . V_88 = & V_2 -> V_88 ;
V_2 -> V_89 . V_215 = & V_2 -> V_87 ;
V_2 -> V_89 . V_218 = V_219 ;
V_6 = F_114 ( & V_2 -> V_89 , V_220 , - 1 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_44 -> V_16 ,
L_85 ,
V_6 ) ;
goto V_221;
}
F_115 ( & V_2 -> V_44 -> V_16 , L_86 ,
F_116 ( & V_2 -> V_89 ) ) ;
V_84 -> V_85 = V_2 ;
V_84 -> V_125 . V_222 = F_48 ;
F_115 ( & V_2 -> V_15 -> V_16 , L_87 ,
V_17 ) ;
return V_84 ;
V_221:
F_99 ( & V_2 -> V_88 ) ;
V_212:
F_98 ( & V_2 -> V_141 ) ;
V_210:
F_100 ( V_2 ) ;
return NULL ;
}
