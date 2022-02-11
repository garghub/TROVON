static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
while ( V_5 -> V_8 ) {
if ( V_5 -> V_8 == V_3 )
return V_5 -> V_9 ;
V_5 ++ ;
}
F_2 () ;
return 0xffffffffU ;
}
static int F_3 ( const struct V_10 * V_11 , char * V_12 ,
const char * const V_13 [] )
{
unsigned char V_14 [ V_15 + 1 ] ;
int V_16 = 0 ;
F_4 ( V_11 -> V_17 , V_14 , V_18 , sizeof( V_14 ) ) ;
while ( V_13 [ V_16 ] != NULL ) {
if ( ! strcmp ( V_13 [ V_16 ] , V_14 ) ) {
F_5 ( L_1 ,
V_12 , V_13 [ V_16 ] ) ;
return 1 ;
}
V_16 ++ ;
}
return 0 ;
}
static unsigned long F_6 ( struct V_10 * V_19 , unsigned long V_20 )
{
if ( V_19 -> V_21 == V_22 ) {
if ( F_3 ( V_19 , L_2 , V_23 ) )
V_20 &= ~ V_24 ;
if ( F_3 ( V_19 , L_3 , V_25 ) )
V_20 &= ~ ( 0xE0 << V_26 ) ;
}
return V_20 ;
}
static unsigned long F_7 ( struct V_10 * V_19 , unsigned long V_20 )
{
if ( V_19 -> V_21 == V_22 ) {
if ( F_3 ( V_19 , L_3 , V_25 ) )
V_20 &= ~ ( 0xE0 << V_26 ) ;
}
return V_20 ;
}
static unsigned long F_8 ( struct V_10 * V_19 , unsigned long V_20 )
{
if ( F_9 ( V_19 -> V_17 ) )
V_20 &= ~ ( ( 0xE << V_26 ) | V_27 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
T_2 V_30 , V_31 ;
F_12 ( V_29 , 0x5B , & V_30 ) ;
F_13 ( V_29 , 0x5B , V_30 & ~ 0x01 ) ;
F_14 ( 10 ) ;
F_12 ( V_29 , 0x5A , & V_31 ) ;
F_13 ( V_29 , 0x5B , V_30 ) ;
if ( V_31 & ( 2 >> V_2 -> V_32 ) )
return V_33 ;
else
return V_34 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
unsigned int V_35 = 0x50 + 4 * V_2 -> V_32 ;
T_3 V_36 ;
T_2 V_31 ;
F_16 ( V_29 , V_35 + 2 , & V_36 ) ;
F_17 ( V_29 , V_35 + 2 , V_36 | 0x8000 ) ;
F_12 ( V_29 , 0x5A , & V_31 ) ;
F_17 ( V_29 , V_35 + 2 , V_36 ) ;
if ( V_31 & ( 2 >> V_2 -> V_32 ) )
return V_33 ;
else
return V_34 ;
}
static int F_18 ( struct V_37 * V_38 , unsigned long V_39 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
static const struct V_40 V_41 [] = {
{ 0x50 , 1 , 0x04 , 0x04 } ,
{ 0x54 , 1 , 0x04 , 0x04 }
} ;
if ( ! F_19 ( V_29 , & V_41 [ V_2 -> V_32 ] ) )
return - V_42 ;
F_13 ( V_29 , 0x50 + 4 * V_2 -> V_32 , 0x37 ) ;
F_14 ( 100 ) ;
return F_20 ( V_38 , V_39 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_10 * V_19 ,
T_2 V_43 )
{
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
T_1 V_44 , V_45 ;
T_1 V_46 , V_9 , V_20 ;
T_2 V_47 ;
V_44 = 0x40 + 4 * ( V_19 -> V_48 + 2 * V_2 -> V_32 ) ;
V_45 = 0x51 + 4 * V_2 -> V_32 ;
F_12 ( V_29 , V_45 , & V_47 ) ;
V_47 &= ~ 0x02 ;
V_47 |= 0x01 ;
F_13 ( V_29 , V_45 , V_47 ) ;
if ( V_43 < V_49 )
V_20 = 0xcfc3ffff ;
else if ( V_43 < V_50 )
V_20 = 0x31c001ff ;
else
V_20 = 0x303c0000 ;
V_9 = F_1 ( V_2 , V_43 ) ;
F_22 ( V_29 , V_44 , & V_46 ) ;
V_46 = ( V_46 & ~ V_20 ) | ( V_9 & V_20 ) ;
F_23 ( V_29 , V_44 , V_46 ) ;
}
static void F_24 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_21 ( V_2 , V_19 , V_19 -> V_51 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_21 ( V_2 , V_19 , V_19 -> V_52 ) ;
}
static void F_26 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
void T_4 * V_55 = V_2 -> V_56 . V_57 ;
T_2 V_58 = F_27 ( V_55 + V_59 ) ;
T_2 V_60 ;
if ( V_58 & V_61 ) {
F_14 ( 20 ) ;
V_58 = F_27 ( V_55 + V_59 ) ;
}
if ( V_58 & V_61 ) {
F_13 ( V_29 , 0x50 + 4 * V_2 -> V_32 , 0x37 ) ;
F_14 ( 10 ) ;
V_60 = F_27 ( V_55 + V_62 ) ;
F_28 ( V_60 & ~ V_63 , V_55 + V_62 ) ;
V_58 = F_27 ( V_55 + V_59 ) ;
F_28 ( V_58 | V_64 | V_65 ,
V_55 + V_59 ) ;
F_13 ( V_29 , 0x50 + 4 * V_2 -> V_32 , 0x37 ) ;
F_14 ( 10 ) ;
}
F_29 ( V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_10 * V_19 ,
T_2 V_43 )
{
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
T_1 V_44 , V_45 ;
T_1 V_46 , V_9 , V_20 ;
T_2 V_47 ;
V_44 = 0x40 + 4 * ( V_19 -> V_48 + 2 * V_2 -> V_32 ) ;
V_45 = 0x51 + 4 * V_2 -> V_32 ;
F_12 ( V_29 , V_45 , & V_47 ) ;
V_47 &= ~ 0x07 ;
F_13 ( V_29 , V_45 , V_47 ) ;
if ( V_43 < V_49 )
V_20 = 0xcfc3ffff ;
else if ( V_43 < V_50 )
V_20 = 0x31c001ff ;
else
V_20 = 0x303c0000 ;
V_9 = F_1 ( V_2 , V_43 ) ;
F_22 ( V_29 , V_44 , & V_46 ) ;
V_46 = ( V_46 & ~ V_20 ) | ( V_9 & V_20 ) ;
F_23 ( V_29 , V_44 , V_46 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_30 ( V_2 , V_19 , V_19 -> V_51 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_10 * V_19 )
{
F_30 ( V_2 , V_19 , V_19 -> V_52 ) ;
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_29 = F_11 ( V_2 -> V_6 -> V_11 ) ;
int V_66 = 0x50 + 4 * V_2 -> V_32 ;
T_2 V_67 , V_68 ;
F_12 ( V_29 , 0x6A , & V_67 ) ;
F_12 ( V_29 , V_66 , & V_68 ) ;
if ( V_67 & ( 1 << V_2 -> V_32 ) )
F_13 ( V_29 , V_66 , V_68 | 0x30 ) ;
F_29 ( V_54 ) ;
}
static int F_34 ( unsigned int V_69 , unsigned int V_70 )
{
unsigned int V_71 = ( V_70 * V_69 ) / 192 ;
if ( V_71 < 40 )
return 0 ;
if ( V_71 < 45 )
return 1 ;
if ( V_71 < 55 )
return 2 ;
return 3 ;
}
static int F_35 ( struct V_28 * V_11 )
{
T_2 V_72 ;
T_1 V_73 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < 0x5000 ; V_74 ++ ) {
F_14 ( 50 ) ;
F_12 ( V_11 , 0x5b , & V_72 ) ;
if ( V_72 & 0x80 ) {
for ( V_74 = 0 ; V_74 < 0x1000 ; V_74 ++ ) {
F_12 ( V_11 , 0x5b , & V_72 ) ;
if ( ( V_72 & 0x80 ) == 0 )
return 0 ;
}
F_22 ( V_11 , 0x5c , & V_73 ) ;
F_23 ( V_11 , 0x5c , V_73 & ~ 0x100 ) ;
return 1 ;
}
}
return 0 ;
}
static T_1 F_36 ( struct V_28 * V_29 )
{
T_1 V_69 ;
unsigned long V_75 = F_37 ( V_29 , 4 ) ;
if ( F_38 ( V_29 -> V_76 ) & 1 ) {
struct V_28 * V_77 ;
V_77 = F_39 ( V_29 -> V_78 , V_29 -> V_76 - 1 ) ;
if ( V_77 == NULL )
return 0 ;
V_75 = F_37 ( V_77 , 4 ) ;
V_69 = F_40 ( V_75 + 0x90 ) ;
F_41 ( V_77 ) ;
} else
V_69 = F_40 ( V_75 + 0x90 ) ;
return V_69 ;
}
static int F_42 ( struct V_28 * V_11 , const struct V_79 * V_17 )
{
static const struct V_80 V_81 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = & V_91
} ;
static const struct V_80 V_92 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = & V_93
} ;
static const struct V_80 V_94 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_95 ,
. V_90 = & V_91
} ;
static const struct V_80 V_96 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_95 ,
. V_90 = & V_93
} ;
static const struct V_80 V_97 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_98 ,
. V_90 = & V_99
} ;
static const struct V_80 V_100 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_98 ,
. V_90 = & V_101
} ;
static const struct V_80 V_102 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = & V_99
} ;
static const struct V_80 V_103 = {
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = & V_104
} ;
static const int V_105 [ 4 ] = { 33 , 40 , 50 , 66 } ;
void * V_7 = NULL ;
const struct V_80 * V_106 [] = { NULL , NULL } ;
T_2 V_107 = V_11 -> V_108 ;
T_2 V_109 ;
T_2 V_110 ;
T_1 V_69 ;
int V_111 = 1 ;
unsigned long V_112 = F_37 ( V_11 , 4 ) ;
const struct V_113 * V_114 ;
int V_115 ;
int V_116 ;
V_116 = F_43 ( V_11 ) ;
if ( V_116 )
return V_116 ;
switch ( V_11 -> V_117 ) {
case V_118 :
if ( V_107 < 3 )
return - V_119 ;
if ( V_107 == 6 )
return - V_119 ;
switch ( V_107 ) {
case 3 :
V_106 [ 0 ] = & V_81 ;
V_114 = & V_120 ;
V_111 = 0 ;
break;
case 4 :
V_106 [ 0 ] = & V_92 ;
V_114 = & V_121 ;
V_111 = 0 ;
break;
case 5 :
V_106 [ 0 ] = & V_97 ;
V_114 = & V_122 ;
break;
default:
F_44 ( L_4 ,
V_107 ) ;
return - V_119 ;
}
break;
case V_123 :
if ( V_107 >= 2 )
return - V_119 ;
V_106 [ 0 ] = & V_97 ;
V_114 = & V_124 ;
break;
case V_125 :
if ( V_107 > 1 )
return - V_119 ;
V_106 [ 0 ] = & V_100 ;
V_114 = & V_126 ;
break;
case V_127 :
if ( V_107 > 1 )
return - V_119 ;
V_106 [ 0 ] = & V_100 ;
V_114 = & V_128 ;
F_12 ( V_11 , 0x50 , & V_110 ) ;
V_110 &= ~ 0x04 ;
F_13 ( V_11 , 0x50 , V_110 ) ;
break;
case V_129 :
V_114 = & V_130 ;
if ( ! ( F_38 ( V_11 -> V_76 ) & 1 ) )
* V_106 = & V_102 ;
else
* V_106 = & V_103 ;
break;
default:
F_44 ( L_5 , V_11 -> V_117 ) ;
return - V_119 ;
}
F_13 ( V_11 , V_131 , ( V_132 / 4 ) ) ;
F_13 ( V_11 , V_133 , 0x78 ) ;
F_13 ( V_11 , V_134 , 0x08 ) ;
F_13 ( V_11 , V_135 , 0x08 ) ;
F_12 ( V_11 , 0x5A , & V_109 ) ;
V_109 &= ~ 0x10 ;
F_13 ( V_11 , 0x5a , V_109 ) ;
F_13 ( V_11 , 0x5b , 0x23 ) ;
if ( V_114 == & V_124 )
F_45 ( 0x0e , V_112 + 0x9c ) ;
if ( V_114 == & V_130 ) {
V_69 = F_36 ( V_11 ) ;
if ( V_69 == 0 )
return - V_119 ;
} else
V_69 = F_40 ( V_112 + 0x90 ) ;
if ( ( V_69 >> 12 ) != 0xABCDE ) {
int V_16 ;
T_2 V_136 ;
T_1 V_137 = 0 ;
F_5 ( L_6 ) ;
for ( V_16 = 0 ; V_16 < 128 ; V_16 ++ ) {
F_12 ( V_11 , 0x78 , & V_136 ) ;
V_137 += V_136 & 0x1FF ;
F_14 ( 15 ) ;
}
V_69 = V_137 / 128 ;
}
V_69 &= 0x1FF ;
V_115 = F_34 ( V_69 , V_114 -> V_70 ) ;
if ( V_114 -> V_5 [ V_115 ] == NULL || V_111 ) {
unsigned int V_138 , V_139 ;
int V_140 , V_141 ;
V_140 = ( V_106 [ 0 ] -> V_88 & 0xC0 ) ? 3 : 2 ;
V_138 = ( V_105 [ V_115 ] * 48 ) / V_105 [ V_140 ] ;
V_139 = V_138 + 2 ;
if ( V_115 > 1 )
V_139 += 2 ;
F_13 ( V_11 , 0x5b , 0x21 ) ;
F_23 ( V_11 , 0x5C ,
( V_139 << 16 ) | V_138 | 0x100 ) ;
for ( V_141 = 0 ; V_141 < 8 ; V_141 ++ ) {
if ( F_35 ( V_11 ) )
break;
if ( V_141 & 1 )
V_138 -= V_141 >> 1 ;
else
V_139 += V_141 >> 1 ;
F_23 ( V_11 , 0x5C ,
( V_139 << 16 ) | V_138 | 0x100 ) ;
}
if ( V_141 == 8 ) {
F_44 ( L_7 ) ;
return - V_119 ;
}
if ( V_140 == 3 )
V_7 = ( void * ) V_142 ;
else
V_7 = ( void * ) V_143 ;
F_46 ( L_8 ,
V_105 [ V_115 ] , V_105 [ V_140 ] ) ;
} else {
V_7 = ( void * ) V_114 -> V_5 [ V_115 ] ;
if ( V_115 < 2 && V_106 [ 0 ] == & V_81 )
V_106 [ 0 ] = & V_94 ;
if ( V_115 < 2 && V_106 [ 0 ] == & V_92 )
V_106 [ 0 ] = & V_96 ;
F_46 ( L_9 ,
V_114 -> V_144 , V_105 [ V_115 ] ) ;
}
return F_47 ( V_11 , V_106 , & V_145 , V_7 , 0 ) ;
}
