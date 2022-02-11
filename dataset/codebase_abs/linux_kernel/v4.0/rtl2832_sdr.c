static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const T_2 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_11 * V_12 = V_9 -> V_11 ;
return V_9 -> V_13 ( V_12 , V_3 , V_4 , V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_14 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_11 * V_12 = V_9 -> V_11 ;
return V_9 -> V_15 ( V_12 , V_3 , V_14 , V_4 ) ;
}
static struct V_16 * F_4 (
struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_16 * V_18 = NULL ;
F_5 ( & V_2 -> V_19 , V_17 ) ;
if ( F_6 ( & V_2 -> V_20 ) )
goto V_21;
V_18 = F_7 ( V_2 -> V_20 . V_22 ,
struct V_16 , V_23 ) ;
F_8 ( & V_18 -> V_23 ) ;
V_21:
F_9 ( & V_2 -> V_19 , V_17 ) ;
return V_18 ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
void * V_24 , const T_2 * V_25 , unsigned int V_26 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned int V_27 ;
if ( V_2 -> V_28 == V_29 ) {
memcpy ( V_24 , V_25 , V_26 ) ;
V_27 = V_26 ;
} else if ( V_2 -> V_28 == V_30 ) {
unsigned int V_31 ;
T_1 * V_32 = V_24 ;
for ( V_31 = 0 ; V_31 < V_26 ; V_31 ++ )
* V_32 ++ = ( V_25 [ V_31 ] << 8 ) | ( V_25 [ V_31 ] >> 0 ) ;
V_27 = 2 * V_26 ;
} else {
V_27 = 0 ;
}
if ( F_11 ( F_12 ( V_2 -> V_33 ) ) ) {
#define F_13 10000UL
unsigned int V_34 = F_14 ( V_35 -
V_2 -> V_33 + F_15 ( F_13 ) ) ;
unsigned int V_36 = V_2 -> V_37 - V_2 -> V_38 ;
V_2 -> V_33 = V_35 + F_15 ( F_13 ) ;
V_2 -> V_38 = V_2 -> V_37 ;
F_16 ( & V_7 -> V_2 ,
L_1 ,
V_26 , V_36 , V_34 , V_36 * 1000UL / V_34 ) ;
}
V_2 -> V_37 += V_26 / 2 ;
return V_27 ;
}
static void F_17 ( struct V_39 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_16 * V_41 ;
F_18 ( & V_7 -> V_2 , L_2 ,
V_39 -> V_42 , V_39 -> V_43 ,
V_39 -> V_44 , V_39 -> V_45 ) ;
switch ( V_39 -> V_42 ) {
case 0 :
case - V_46 :
break;
case - V_47 :
case - V_48 :
case - V_49 :
return;
default:
F_19 ( & V_7 -> V_2 , L_3 , V_39 -> V_42 ) ;
break;
}
if ( F_20 ( V_39 -> V_43 > 0 ) ) {
void * V_50 ;
unsigned int V_5 ;
V_41 = F_4 ( V_2 ) ;
if ( F_11 ( V_41 == NULL ) ) {
V_2 -> V_51 ++ ;
F_21 ( & V_7 -> V_2 ,
L_4 ,
V_2 -> V_51 ) ;
goto V_52;
}
V_50 = F_22 ( & V_41 -> V_53 , 0 ) ;
V_5 = F_10 ( V_2 , V_50 , V_39 -> V_54 ,
V_39 -> V_43 ) ;
F_23 ( & V_41 -> V_53 , 0 , V_5 ) ;
F_24 ( & V_41 -> V_53 . V_55 . V_56 ) ;
V_41 -> V_53 . V_55 . V_57 = V_2 -> V_57 ++ ;
F_25 ( & V_41 -> V_53 , V_58 ) ;
}
V_52:
F_26 ( V_39 , V_59 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_31 ;
for ( V_31 = V_2 -> V_60 - 1 ; V_31 >= 0 ; V_31 -- ) {
F_16 ( & V_7 -> V_2 , L_5 , V_31 ) ;
F_28 ( V_2 -> V_61 [ V_31 ] ) ;
}
V_2 -> V_60 = 0 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_31 , V_62 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_63 ; V_31 ++ ) {
F_16 ( & V_7 -> V_2 , L_6 , V_31 ) ;
V_62 = F_26 ( V_2 -> V_61 [ V_31 ] , V_59 ) ;
if ( V_62 ) {
F_30 ( & V_7 -> V_2 ,
L_7 ,
V_31 ) ;
F_27 ( V_2 ) ;
return V_62 ;
}
V_2 -> V_60 ++ ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_17 & V_64 ) {
while ( V_2 -> V_65 ) {
V_2 -> V_65 -- ;
F_16 ( & V_7 -> V_2 , L_8 , V_2 -> V_65 ) ;
F_32 ( V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_68 [ V_2 -> V_65 ] ,
V_2 -> V_69 [ V_2 -> V_65 ] ) ;
}
}
V_2 -> V_17 &= ~ V_64 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_2 -> V_65 = 0 ;
V_2 -> V_67 = V_70 ;
F_16 ( & V_7 -> V_2 , L_9 ,
V_71 * V_70 ) ;
for ( V_2 -> V_65 = 0 ; V_2 -> V_65 < V_71 ; V_2 -> V_65 ++ ) {
V_2 -> V_68 [ V_2 -> V_65 ] = F_34 ( V_2 -> V_66 ,
V_70 , V_59 ,
& V_2 -> V_69 [ V_2 -> V_65 ] ) ;
if ( ! V_2 -> V_68 [ V_2 -> V_65 ] ) {
F_16 ( & V_7 -> V_2 , L_10 ,
V_2 -> V_65 ) ;
F_31 ( V_2 ) ;
return - V_72 ;
}
F_16 ( & V_7 -> V_2 , L_11 ,
V_2 -> V_65 , V_2 -> V_68 [ V_2 -> V_65 ] ,
( long long ) V_2 -> V_69 [ V_2 -> V_65 ] ) ;
V_2 -> V_17 |= V_64 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_31 ;
F_27 ( V_2 ) ;
for ( V_31 = V_2 -> V_63 - 1 ; V_31 >= 0 ; V_31 -- ) {
if ( V_2 -> V_61 [ V_31 ] ) {
F_16 ( & V_7 -> V_2 , L_12 , V_31 ) ;
F_36 ( V_2 -> V_61 [ V_31 ] ) ;
}
}
V_2 -> V_63 = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_31 , V_73 ;
for ( V_31 = 0 ; V_31 < V_71 ; V_31 ++ ) {
F_16 ( & V_7 -> V_2 , L_13 , V_31 ) ;
V_2 -> V_61 [ V_31 ] = F_38 ( 0 , V_59 ) ;
if ( ! V_2 -> V_61 [ V_31 ] ) {
F_16 ( & V_7 -> V_2 , L_14 ) ;
for ( V_73 = 0 ; V_73 < V_31 ; V_73 ++ )
F_36 ( V_2 -> V_61 [ V_73 ] ) ;
return - V_72 ;
}
F_39 ( V_2 -> V_61 [ V_31 ] ,
V_2 -> V_66 ,
F_40 ( V_2 -> V_66 , 0x81 ) ,
V_2 -> V_68 [ V_31 ] ,
V_70 ,
F_17 , V_2 ) ;
V_2 -> V_61 [ V_31 ] -> V_74 = V_75 ;
V_2 -> V_61 [ V_31 ] -> V_76 = V_2 -> V_69 [ V_31 ] ;
V_2 -> V_63 ++ ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_17 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
F_5 ( & V_2 -> V_19 , V_17 ) ;
while ( ! F_6 ( & V_2 -> V_20 ) ) {
struct V_16 * V_18 ;
V_18 = F_7 ( V_2 -> V_20 . V_22 ,
struct V_16 , V_23 ) ;
F_8 ( & V_18 -> V_23 ) ;
F_25 ( & V_18 -> V_53 , V_77 ) ;
}
F_9 ( & V_2 -> V_19 , V_17 ) ;
}
static int F_42 ( struct V_78 * V_78 , void * V_79 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
F_44 ( V_81 -> V_82 , V_83 , sizeof( V_81 -> V_82 ) ) ;
F_44 ( V_81 -> V_84 , V_2 -> V_85 . V_86 , sizeof( V_81 -> V_84 ) ) ;
F_45 ( V_2 -> V_66 , V_81 -> V_87 , sizeof( V_81 -> V_87 ) ) ;
V_81 -> V_88 = V_89 | V_90 |
V_91 | V_92 ;
V_81 -> V_93 = V_81 -> V_88 | V_94 ;
return 0 ;
}
static int F_46 ( struct V_95 * V_96 ,
const struct V_97 * V_98 , unsigned int * V_99 ,
unsigned int * V_100 , unsigned int V_101 [] , void * V_102 [] )
{
struct V_1 * V_2 = F_47 ( V_96 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_16 , * V_99 ) ;
if ( V_96 -> V_103 + * V_99 < 8 )
* V_99 = 8 - V_96 -> V_103 ;
* V_100 = 1 ;
V_101 [ 0 ] = F_48 ( V_2 -> V_104 ) ;
F_16 ( & V_7 -> V_2 , L_17 , * V_99 , V_101 [ 0 ] ) ;
return 0 ;
}
static int F_49 ( struct V_105 * V_53 )
{
struct V_1 * V_2 = F_47 ( V_53 -> V_95 ) ;
if ( ! V_2 -> V_66 )
return - V_106 ;
return 0 ;
}
static void F_50 ( struct V_105 * V_53 )
{
struct V_1 * V_2 = F_47 ( V_53 -> V_95 ) ;
struct V_16 * V_18 =
F_51 ( V_53 , struct V_16 , V_53 ) ;
unsigned long V_17 ;
if ( ! V_2 -> V_66 ) {
F_25 ( & V_18 -> V_53 , V_77 ) ;
return;
}
F_5 ( & V_2 -> V_19 , V_17 ) ;
F_52 ( & V_18 -> V_23 , & V_2 -> V_20 ) ;
F_9 ( & V_2 -> V_19 , V_17 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_107 * V_108 = V_9 -> V_107 ;
int V_62 ;
unsigned int V_109 , V_110 ;
T_2 V_18 [ 4 ] , V_111 , V_112 ;
T_3 V_113 ;
T_4 V_114 ;
F_16 ( & V_7 -> V_2 , L_18 , V_2 -> V_115 ) ;
if ( ! F_54 ( V_116 , & V_2 -> V_17 ) )
return 0 ;
if ( V_2 -> V_115 == 0 )
return 0 ;
V_109 = V_2 -> V_115 ;
V_62 = F_1 ( V_2 , 0x13e , L_19 , 2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x115 , L_20 , 4 ) ;
if ( V_62 )
goto V_117;
if ( V_108 -> V_118 . V_119 . V_120 )
V_62 = V_108 -> V_118 . V_119 . V_120 ( V_108 , & V_110 ) ;
else
V_62 = - V_121 ;
if ( V_62 )
goto V_117;
V_113 = V_110 % V_9 -> V_122 ;
V_113 *= 0x400000 ;
V_113 = F_55 ( V_113 , V_9 -> V_122 ) ;
V_113 = - V_113 ;
V_114 = V_113 & 0x3fffff ;
F_16 ( & V_7 -> V_2 , L_21 , V_110 , V_114 ) ;
V_18 [ 0 ] = ( V_114 >> 16 ) & 0xff ;
V_18 [ 1 ] = ( V_114 >> 8 ) & 0xff ;
V_18 [ 2 ] = ( V_114 >> 0 ) & 0xff ;
V_62 = F_1 ( V_2 , 0x119 , V_18 , 3 ) ;
if ( V_62 )
goto V_117;
if ( V_110 ) {
V_111 = 0x1a ;
V_112 = 0x8d ;
} else {
V_111 = 0x1b ;
V_112 = 0xcd ;
}
V_62 = F_2 ( V_2 , 0x1b1 , V_111 ) ;
if ( V_62 )
goto V_117;
V_62 = F_2 ( V_2 , 0x008 , V_112 ) ;
if ( V_62 )
goto V_117;
V_62 = F_2 ( V_2 , 0x006 , 0x80 ) ;
if ( V_62 )
goto V_117;
V_114 = F_55 ( V_9 -> V_122 * 0x400000ULL , V_109 * 4U ) ;
V_114 <<= 2 ;
V_18 [ 0 ] = ( V_114 >> 24 ) & 0xff ;
V_18 [ 1 ] = ( V_114 >> 16 ) & 0xff ;
V_18 [ 2 ] = ( V_114 >> 8 ) & 0xff ;
V_18 [ 3 ] = ( V_114 >> 0 ) & 0xff ;
V_62 = F_1 ( V_2 , 0x19f , V_18 , 4 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x11c ,
L_22 ,
20 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x017 , L_23 , 2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x019 , L_24 , 1 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x01a , L_25 , 6 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x192 , L_26 , 3 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x061 , L_27 , 1 ) ;
if ( V_62 )
goto V_117;
switch ( V_9 -> V_123 ) {
case V_124 :
V_62 = F_1 ( V_2 , 0x112 , L_28 , 1 ) ;
V_62 = F_1 ( V_2 , 0x102 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x103 , L_28 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c7 , L_30 , 1 ) ;
V_62 = F_1 ( V_2 , 0x104 , L_31 , 1 ) ;
V_62 = F_1 ( V_2 , 0x105 , L_32 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c8 , L_33 , 1 ) ;
V_62 = F_1 ( V_2 , 0x106 , L_34 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c9 , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ca , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cb , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x107 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cd , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ce , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x108 , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x109 , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10a , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10b , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x011 , L_41 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1e5 , L_42 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d9 , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1db , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1dd , L_43 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1de , L_44 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d8 , L_45 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1e6 , L_46 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d7 , L_47 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00d , L_48 , 1 ) ;
V_62 = F_1 ( V_2 , 0x010 , L_49 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00d , L_50 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00d , L_51 , 1 ) ;
V_62 = F_1 ( V_2 , 0x013 , L_46 , 1 ) ;
break;
case V_125 :
case V_126 :
V_62 = F_1 ( V_2 , 0x112 , L_28 , 1 ) ;
V_62 = F_1 ( V_2 , 0x102 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x103 , L_28 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c7 , L_52 , 1 ) ;
V_62 = F_1 ( V_2 , 0x104 , L_53 , 1 ) ;
V_62 = F_1 ( V_2 , 0x105 , L_32 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c8 , L_54 , 1 ) ;
V_62 = F_1 ( V_2 , 0x106 , L_34 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c9 , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ca , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cb , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x107 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cd , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ce , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x108 , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x109 , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10a , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10b , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x011 , L_55 , 2 ) ;
V_62 = F_1 ( V_2 , 0x1e5 , L_42 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d9 , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1db , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1dd , L_56 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1de , L_57 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d8 , L_45 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1e6 , L_46 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1d7 , L_47 , 1 ) ;
break;
case V_127 :
case V_128 :
V_62 = F_1 ( V_2 , 0x112 , L_28 , 1 ) ;
V_62 = F_1 ( V_2 , 0x102 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x115 , L_58 , 1 ) ;
V_62 = F_1 ( V_2 , 0x103 , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c7 , L_59 , 1 ) ;
V_62 = F_1 ( V_2 , 0x104 , L_53 , 1 ) ;
V_62 = F_1 ( V_2 , 0x105 , L_32 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c8 , L_43 , 1 ) ;
V_62 = F_1 ( V_2 , 0x106 , L_34 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1c9 , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ca , L_35 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cb , L_36 , 1 ) ;
V_62 = F_1 ( V_2 , 0x107 , L_29 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1cd , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x1ce , L_37 , 1 ) ;
V_62 = F_1 ( V_2 , 0x108 , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x109 , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10a , L_38 , 1 ) ;
V_62 = F_1 ( V_2 , 0x10b , L_39 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x00e , L_40 , 1 ) ;
V_62 = F_1 ( V_2 , 0x011 , L_60 , 1 ) ;
break;
default:
F_56 ( & V_7 -> V_2 , L_61 ) ;
}
V_62 = F_3 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_62 )
goto V_117;
V_62 = F_3 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_62 )
goto V_117;
V_117:
return V_62 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_62 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
V_62 = F_1 ( V_2 , 0x061 , L_62 , 1 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x019 , L_63 , 1 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x017 , L_23 , 2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x192 , L_64 , 3 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x13e , L_65 , 2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_1 ( V_2 , 0x115 , L_66 , 4 ) ;
if ( V_62 )
goto V_117;
V_117:
return;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_107 * V_108 = V_9 -> V_107 ;
struct V_129 * V_130 = & V_108 -> V_131 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
if ( V_2 -> V_135 == 0 )
return 0 ;
V_133 = F_59 ( & V_2 -> V_136 ,
V_137 ) ;
V_134 = F_59 ( & V_2 -> V_136 , V_138 ) ;
if ( F_60 ( V_133 ) ) {
V_130 -> V_139 = V_2 -> V_115 ;
F_61 ( V_134 , V_2 -> V_115 ) ;
} else {
V_130 -> V_139 = F_60 ( V_134 ) ;
}
V_130 -> V_140 = V_2 -> V_135 ;
V_130 -> V_141 = V_142 ;
F_16 ( & V_7 -> V_2 , L_67 ,
V_130 -> V_140 , V_130 -> V_139 ) ;
if ( ! F_54 ( V_116 , & V_2 -> V_17 ) )
return 0 ;
if ( V_108 -> V_118 . V_119 . V_143 )
V_108 -> V_118 . V_119 . V_143 ( V_108 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_107 * V_108 = V_9 -> V_107 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( V_108 -> V_118 . V_119 . V_144 )
V_108 -> V_118 . V_119 . V_144 ( V_108 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_107 * V_108 = V_9 -> V_107 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( V_108 -> V_118 . V_119 . V_145 )
V_108 -> V_118 . V_119 . V_145 ( V_108 ) ;
return;
}
static int F_64 ( struct V_95 * V_96 , unsigned int V_146 )
{
struct V_1 * V_2 = F_47 ( V_96 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_147 * V_148 = V_9 -> V_147 ;
int V_62 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( ! V_2 -> V_66 )
return - V_106 ;
if ( F_65 ( & V_2 -> V_149 ) )
return - V_150 ;
if ( V_148 -> V_151 -> V_152 )
V_148 -> V_151 -> V_152 ( V_148 , 1 ) ;
if ( V_148 -> V_151 -> V_153 )
V_148 -> V_151 -> V_153 ( V_9 -> V_107 , 1 ) ;
F_66 ( V_116 , & V_2 -> V_17 ) ;
V_62 = F_62 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_58 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_53 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_33 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_62 = F_37 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_2 -> V_57 = 0 ;
V_62 = F_29 ( V_2 ) ;
if ( V_62 )
goto V_117;
V_117:
F_67 ( & V_2 -> V_149 ) ;
return V_62 ;
}
static void F_68 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_47 ( V_96 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_147 * V_148 = V_9 -> V_147 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
F_69 ( & V_2 -> V_149 ) ;
F_27 ( V_2 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
F_41 ( V_2 ) ;
F_57 ( V_2 ) ;
F_63 ( V_2 ) ;
F_70 ( V_116 , & V_2 -> V_17 ) ;
if ( V_148 -> V_151 -> V_153 )
V_148 -> V_151 -> V_153 ( V_9 -> V_107 , 0 ) ;
if ( V_148 -> V_151 -> V_152 )
V_148 -> V_151 -> V_152 ( V_148 , 0 ) ;
F_67 ( & V_2 -> V_149 ) ;
}
static int F_71 ( struct V_78 * V_78 , void * V_154 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_68 , V_156 -> V_157 , V_156 -> type ) ;
if ( V_156 -> V_157 == 0 ) {
F_44 ( V_156 -> V_86 , L_69 , sizeof( V_156 -> V_86 ) ) ;
V_156 -> type = V_158 ;
V_156 -> V_159 = V_160 | V_161 ;
V_156 -> V_162 = 300000 ;
V_156 -> V_163 = 3200000 ;
} else if ( V_156 -> V_157 == 1 ) {
F_44 ( V_156 -> V_86 , L_70 , sizeof( V_156 -> V_86 ) ) ;
V_156 -> type = V_164 ;
V_156 -> V_159 = V_160 | V_161 ;
V_156 -> V_162 = 50000000 ;
V_156 -> V_163 = 2000000000 ;
} else {
return - V_121 ;
}
return 0 ;
}
static int F_72 ( struct V_78 * V_78 , void * V_154 ,
const struct V_155 * V_156 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( V_156 -> V_157 > 1 )
return - V_121 ;
return 0 ;
}
static int F_73 ( struct V_78 * V_78 , void * V_154 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_71 ,
V_166 -> V_123 , V_166 -> type , V_166 -> V_157 ) ;
if ( V_166 -> V_123 == 0 ) {
if ( V_166 -> V_157 >= F_74 ( V_167 ) )
return - V_121 ;
* V_166 = V_167 [ V_166 -> V_157 ] ;
} else if ( V_166 -> V_123 == 1 ) {
if ( V_166 -> V_157 >= F_74 ( V_168 ) )
return - V_121 ;
* V_166 = V_168 [ V_166 -> V_157 ] ;
} else {
return - V_121 ;
}
return 0 ;
}
static int F_75 ( struct V_78 * V_78 , void * V_154 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_62 = 0 ;
F_16 ( & V_7 -> V_2 , L_72 , V_170 -> V_123 , V_170 -> type ) ;
if ( V_170 -> V_123 == 0 ) {
V_170 -> V_140 = V_2 -> V_115 ;
V_170 -> type = V_158 ;
} else if ( V_170 -> V_123 == 1 ) {
V_170 -> V_140 = V_2 -> V_135 ;
V_170 -> type = V_164 ;
} else {
return - V_121 ;
}
return V_62 ;
}
static int F_76 ( struct V_78 * V_78 , void * V_154 ,
const struct V_169 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_62 , V_166 ;
F_16 ( & V_7 -> V_2 , L_73 ,
V_170 -> V_123 , V_170 -> type , V_170 -> V_140 ) ;
#define F_77 ((bands_adc[0].rangehigh + bands_adc[1].rangelow) / 2)
#define F_78 ((bands_adc[1].rangehigh + bands_adc[2].rangelow) / 2)
if ( V_170 -> V_123 == 0 && V_170 -> type == V_158 ) {
if ( V_170 -> V_140 < F_77 )
V_166 = 0 ;
else if ( V_170 -> V_140 < F_78 )
V_166 = 1 ;
else
V_166 = 2 ;
V_2 -> V_115 = F_79 (unsigned int, f->frequency,
bands_adc[band].rangelow,
bands_adc[band].rangehigh) ;
F_16 ( & V_7 -> V_2 , L_74 , V_2 -> V_115 ) ;
V_62 = F_53 ( V_2 ) ;
} else if ( V_170 -> V_123 == 1 ) {
V_2 -> V_135 = F_79 (unsigned int, f->frequency,
bands_fm[0].rangelow,
bands_fm[0].rangehigh) ;
F_16 ( & V_7 -> V_2 , L_75 , V_170 -> V_140 ) ;
V_62 = F_58 ( V_2 ) ;
} else {
V_62 = - V_121 ;
}
return V_62 ;
}
static int F_80 ( struct V_78 * V_78 , void * V_154 ,
struct V_171 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( V_170 -> V_157 >= V_2 -> V_172 )
return - V_121 ;
F_44 ( V_170 -> V_173 , V_174 [ V_170 -> V_157 ] . V_86 , sizeof( V_170 -> V_173 ) ) ;
V_170 -> V_28 = V_174 [ V_170 -> V_157 ] . V_28 ;
return 0 ;
}
static int F_81 ( struct V_78 * V_78 , void * V_154 ,
struct V_97 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
V_170 -> V_98 . V_175 . V_28 = V_2 -> V_28 ;
V_170 -> V_98 . V_175 . V_104 = V_2 -> V_104 ;
memset ( V_170 -> V_98 . V_175 . V_176 , 0 , sizeof( V_170 -> V_98 . V_175 . V_176 ) ) ;
return 0 ;
}
static int F_82 ( struct V_78 * V_78 , void * V_154 ,
struct V_97 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_95 * V_177 = & V_2 -> V_178 ;
int V_31 ;
F_16 ( & V_7 -> V_2 , L_76 ,
( char * ) & V_170 -> V_98 . V_175 . V_28 ) ;
if ( F_83 ( V_177 ) )
return - V_179 ;
memset ( V_170 -> V_98 . V_175 . V_176 , 0 , sizeof( V_170 -> V_98 . V_175 . V_176 ) ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_172 ; V_31 ++ ) {
if ( V_174 [ V_31 ] . V_28 == V_170 -> V_98 . V_175 . V_28 ) {
V_2 -> V_28 = V_174 [ V_31 ] . V_28 ;
V_2 -> V_104 = V_174 [ V_31 ] . V_104 ;
V_170 -> V_98 . V_175 . V_104 = V_174 [ V_31 ] . V_104 ;
return 0 ;
}
}
V_2 -> V_28 = V_174 [ 0 ] . V_28 ;
V_2 -> V_104 = V_174 [ 0 ] . V_104 ;
V_170 -> V_98 . V_175 . V_28 = V_174 [ 0 ] . V_28 ;
V_170 -> V_98 . V_175 . V_104 = V_174 [ 0 ] . V_104 ;
return 0 ;
}
static int F_84 ( struct V_78 * V_78 , void * V_154 ,
struct V_97 * V_170 )
{
struct V_1 * V_2 = F_43 ( V_78 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_31 ;
F_16 ( & V_7 -> V_2 , L_76 ,
( char * ) & V_170 -> V_98 . V_175 . V_28 ) ;
memset ( V_170 -> V_98 . V_175 . V_176 , 0 , sizeof( V_170 -> V_98 . V_175 . V_176 ) ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_172 ; V_31 ++ ) {
if ( V_174 [ V_31 ] . V_28 == V_170 -> V_98 . V_175 . V_28 ) {
V_170 -> V_98 . V_175 . V_104 = V_174 [ V_31 ] . V_104 ;
return 0 ;
}
}
V_170 -> V_98 . V_175 . V_28 = V_174 [ 0 ] . V_28 ;
V_170 -> V_98 . V_175 . V_104 = V_174 [ 0 ] . V_104 ;
return 0 ;
}
static int F_85 ( struct V_132 * V_180 )
{
struct V_1 * V_2 =
F_51 ( V_180 -> V_181 , struct V_1 ,
V_136 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
struct V_107 * V_108 = V_9 -> V_107 ;
struct V_129 * V_130 = & V_108 -> V_131 ;
int V_62 ;
F_16 ( & V_7 -> V_2 , L_77 ,
V_180 -> V_182 , V_180 -> V_86 , V_180 -> V_4 , V_180 -> V_183 , V_180 -> V_184 ,
V_180 -> V_185 ) ;
switch ( V_180 -> V_182 ) {
case V_137 :
case V_138 :
if ( V_2 -> V_133 -> V_4 ) {
T_5 V_4 = V_2 -> V_115 + F_55 ( V_2 -> V_134 -> V_185 , 2 ) ;
T_4 V_186 ;
V_4 = F_79 ( T_5 , V_4 , V_2 -> V_134 -> V_183 ,
V_2 -> V_134 -> V_184 ) ;
V_186 = V_4 - V_2 -> V_134 -> V_183 ;
V_186 = V_2 -> V_134 -> V_185 *
F_55 ( V_186 , V_2 -> V_134 -> V_185 ) ;
V_2 -> V_134 -> V_4 = V_2 -> V_134 -> V_183 + V_186 ;
}
V_130 -> V_139 = V_2 -> V_134 -> V_4 ;
if ( ! F_54 ( V_116 , & V_2 -> V_17 ) )
return 0 ;
if ( V_108 -> V_118 . V_119 . V_143 )
V_62 = V_108 -> V_118 . V_119 . V_143 ( V_108 ) ;
else
V_62 = 0 ;
break;
default:
V_62 = - V_121 ;
}
return V_62 ;
}
static void F_86 ( struct V_187 * V_156 )
{
struct V_1 * V_2 =
F_51 ( V_156 , struct V_1 , V_188 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
F_87 ( & V_2 -> V_136 ) ;
F_88 ( & V_2 -> V_188 ) ;
F_89 ( V_2 ) ;
}
static int F_90 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 = V_7 -> V_2 . V_10 ;
const struct V_189 * V_118 = & V_190 ;
struct V_191 * V_192 ;
int V_62 ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
if ( ! V_9 ) {
F_30 ( & V_7 -> V_2 , L_78 ) ;
V_62 = - V_121 ;
goto V_117;
}
if ( ! V_7 -> V_2 . V_193 -> V_82 ) {
F_16 ( & V_7 -> V_2 , L_79 ) ;
V_62 = - V_121 ;
goto V_117;
}
if ( ! F_91 ( V_7 -> V_2 . V_193 -> V_82 -> V_194 ) ) {
F_30 ( & V_7 -> V_2 , L_80 ) ;
V_62 = - V_121 ;
goto V_117;
}
V_2 = F_92 ( sizeof( * V_2 ) , V_195 ) ;
if ( V_2 == NULL ) {
V_62 = - V_72 ;
goto V_196;
}
V_192 = V_9 -> V_191 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_66 = V_9 -> V_147 -> V_66 ;
V_2 -> V_115 = V_167 [ 0 ] . V_162 ;
V_2 -> V_135 = V_168 [ 0 ] . V_162 ;
V_2 -> V_28 = V_174 [ 0 ] . V_28 ;
V_2 -> V_104 = V_174 [ 0 ] . V_104 ;
V_2 -> V_172 = V_197 ;
if ( ! V_198 )
V_2 -> V_172 -= 1 ;
F_93 ( & V_2 -> V_149 ) ;
F_93 ( & V_2 -> V_199 ) ;
F_94 ( & V_2 -> V_19 ) ;
F_95 ( & V_2 -> V_20 ) ;
V_2 -> V_178 . type = V_200 ;
V_2 -> V_178 . V_201 = V_202 | V_203 | V_204 ;
V_2 -> V_178 . V_205 = V_2 ;
V_2 -> V_178 . V_206 = sizeof( struct V_16 ) ;
V_2 -> V_178 . V_118 = & V_207 ;
V_2 -> V_178 . V_208 = & V_209 ;
V_2 -> V_178 . V_210 = V_211 ;
V_62 = F_96 ( & V_2 -> V_178 ) ;
if ( V_62 ) {
F_30 ( & V_7 -> V_2 , L_81 ) ;
goto V_212;
}
switch ( V_9 -> V_123 ) {
case V_124 :
F_97 ( & V_2 -> V_136 , 9 ) ;
if ( V_192 )
F_98 ( & V_2 -> V_136 , V_192 -> V_213 , NULL ) ;
break;
case V_127 :
case V_128 :
F_97 ( & V_2 -> V_136 , 2 ) ;
V_2 -> V_133 = F_99 ( & V_2 -> V_136 , V_118 ,
V_137 ,
0 , 1 , 1 , 1 ) ;
V_2 -> V_134 = F_99 ( & V_2 -> V_136 , V_118 ,
V_138 ,
0 , 8000000 , 100000 , 0 ) ;
F_100 ( 2 , & V_2 -> V_133 , 0 , false ) ;
break;
case V_125 :
case V_126 :
F_97 ( & V_2 -> V_136 , 2 ) ;
V_2 -> V_133 = F_99 ( & V_2 -> V_136 , V_118 ,
V_137 ,
0 , 1 , 1 , 1 ) ;
V_2 -> V_134 = F_99 ( & V_2 -> V_136 , V_118 ,
V_138 ,
6000000 , 8000000 , 1000000 ,
6000000 ) ;
F_100 ( 2 , & V_2 -> V_133 , 0 , false ) ;
break;
default:
F_97 ( & V_2 -> V_136 , 0 ) ;
F_30 ( & V_7 -> V_2 , L_61 ) ;
goto V_214;
}
if ( V_2 -> V_136 . error ) {
V_62 = V_2 -> V_136 . error ;
F_30 ( & V_7 -> V_2 , L_82 ) ;
goto V_214;
}
V_2 -> V_85 = V_215 ;
V_2 -> V_85 . V_216 = & V_2 -> V_178 ;
V_2 -> V_85 . V_216 -> V_217 = & V_2 -> V_199 ;
F_101 ( & V_2 -> V_85 , V_2 ) ;
V_2 -> V_188 . V_218 = F_86 ;
V_62 = F_102 ( & V_7 -> V_2 , & V_2 -> V_188 ) ;
if ( V_62 ) {
F_30 ( & V_7 -> V_2 , L_83 , V_62 ) ;
goto V_214;
}
V_2 -> V_188 . V_213 = & V_2 -> V_136 ;
V_2 -> V_85 . V_188 = & V_2 -> V_188 ;
V_2 -> V_85 . V_217 = & V_2 -> V_149 ;
V_2 -> V_85 . V_219 = V_220 ;
V_62 = F_103 ( & V_2 -> V_85 , V_221 , - 1 ) ;
if ( V_62 ) {
F_30 ( & V_7 -> V_2 , L_84 ,
V_62 ) ;
goto V_222;
}
F_104 ( & V_7 -> V_2 , L_85 ,
F_105 ( & V_2 -> V_85 ) ) ;
F_104 ( & V_7 -> V_2 , L_86 ) ;
F_56 ( & V_7 -> V_2 ,
L_87 ) ;
F_106 ( V_7 , V_2 ) ;
return 0 ;
V_222:
F_88 ( & V_2 -> V_188 ) ;
V_214:
F_87 ( & V_2 -> V_136 ) ;
V_212:
F_89 ( V_2 ) ;
V_196:
F_107 ( V_7 -> V_2 . V_193 -> V_82 -> V_194 ) ;
V_117:
return V_62 ;
}
static int F_108 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_109 ( V_7 ) ;
F_16 ( & V_7 -> V_2 , L_15 ) ;
F_69 ( & V_2 -> V_199 ) ;
F_69 ( & V_2 -> V_149 ) ;
V_2 -> V_66 = NULL ;
F_110 ( & V_2 -> V_188 ) ;
F_111 ( & V_2 -> V_85 ) ;
F_67 ( & V_2 -> V_149 ) ;
F_67 ( & V_2 -> V_199 ) ;
F_112 ( & V_2 -> V_188 ) ;
F_107 ( V_7 -> V_2 . V_193 -> V_82 -> V_194 ) ;
return 0 ;
}
