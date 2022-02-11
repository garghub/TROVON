static int F_1 ( T_1 * V_1 , const char * * V_2 )
{
char * V_3 = ( char * ) & V_1 -> V_4 [ V_5 ] ;
while ( * V_2 )
if ( ! strcmp ( * V_2 ++ , V_3 ) )
return 1 ;
return 0 ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_6 * V_11 = (struct V_6 * ) V_10 -> V_12 ;
return V_8 == V_10 -> V_8 [ 1 ] ? V_11 + 1 : V_11 ;
}
static T_2 F_4 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
T_2 V_14 = V_13 -> V_15 ;
switch ( V_11 -> V_16 ) {
case V_17 :
if ( ! V_18 ||
F_1 ( V_1 , V_19 ) )
V_14 = V_20 ;
if ( ! V_21 ||
F_1 ( V_1 , V_22 ) )
V_14 = V_23 ;
break;
case V_24 :
if ( ! V_25 ||
F_1 ( V_1 , V_26 ) )
V_14 = V_27 ;
break;
case V_28 :
if ( ! V_25 ||
F_1 ( V_1 , V_26 ) )
return V_27 ;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
if ( F_5 ( V_1 -> V_4 ) )
V_14 &= ~ 0x0e ;
default:
return V_14 ;
}
return F_1 ( V_1 , V_33 ) ? 0x00 : V_14 ;
}
static T_2 F_6 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
switch ( V_11 -> V_16 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
if ( F_5 ( V_1 -> V_4 ) )
return 0x00 ;
default:
return 0x07 ;
}
}
static T_4 F_7 ( T_2 V_34 , struct V_6 * V_11 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_8 ( V_36 ) - 1 ; V_35 ++ )
if ( V_36 [ V_35 ] == V_34 )
break;
return V_11 -> V_37 -> V_38 [ V_11 -> clock ] [ V_35 ] ;
}
static void F_9 ( T_3 * V_13 , T_1 * V_1 )
{
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
struct V_40 * V_41 = V_11 -> V_37 ;
T_2 V_42 = 0x40 + ( V_1 -> V_43 * 4 ) ;
T_4 V_44 = 0 ;
const T_2 V_34 = V_1 -> V_45 ;
T_4 V_46 = F_7 ( V_34 , V_11 ) ;
T_4 V_47 = V_34 < V_48 ? V_41 -> V_49 :
( V_34 < V_50 ? V_41 -> V_51 :
V_41 -> V_15 ) ;
F_11 ( V_8 , V_42 , & V_44 ) ;
V_46 = ( V_44 & ~ V_47 ) | ( V_46 & V_47 ) ;
V_46 &= ~ 0xc0000000 ;
F_12 ( V_8 , V_42 , V_46 ) ;
}
static void F_13 ( T_3 * V_13 , T_1 * V_1 )
{
V_1 -> V_45 = V_1 -> V_52 ;
F_9 ( V_13 , V_1 ) ;
}
static void F_14 ( T_1 * V_1 , int V_14 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
if ( ( V_1 -> V_53 & V_54 ) == 0 )
return;
if ( V_11 -> V_16 >= V_24 ) {
T_2 V_55 = 0 ;
F_15 ( V_8 , 0x5a , & V_55 ) ;
if ( ( ( V_55 & 0x10 ) >> 4 ) != V_14 ) {
if ( V_14 )
V_55 |= 0x10 ;
else
V_55 &= ~ 0x10 ;
F_16 ( V_8 , 0x5a , V_55 ) ;
}
} else if ( V_14 )
F_17 ( V_13 -> V_56 ) ;
else
F_18 ( V_13 -> V_56 ) ;
}
static void F_19 ( T_1 * V_1 )
{
struct V_39 * V_8 = F_10 ( V_1 -> V_13 -> V_8 ) ;
T_2 V_57 = 0 , V_58 = 0 , V_55 = 0 ;
F_15 ( V_8 , 0x50 , & V_57 ) ;
F_15 ( V_8 , 0x52 , & V_58 ) ;
F_15 ( V_8 , 0x5a , & V_55 ) ;
F_20 ( L_1 ,
V_1 -> V_59 , V_60 , V_57 , V_58 , V_55 ) ;
if ( V_55 & 0x10 )
F_16 ( V_8 , 0x5a , V_55 & ~ 0x10 ) ;
F_21 ( V_1 ) ;
}
static void F_22 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
F_16 ( V_8 , V_13 -> V_61 , 0x37 ) ;
F_23 ( 10 ) ;
}
static void F_24 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
T_5 V_62 = 0 ;
T_2 V_63 ;
F_25 ( V_8 , V_13 -> V_61 + 2 , & V_62 ) ;
F_20 ( V_64 L_2 , V_1 -> V_59 , V_62 & 0x1ff ) ;
V_63 = F_26 ( V_13 -> V_65 + V_66 ) ;
F_27 ( V_63 & ~ V_67 , V_13 -> V_65 + V_66 ) ;
F_22 ( V_1 ) ;
}
static void F_28 ( T_1 * V_1 )
{
#ifdef F_29
F_22 ( V_1 ) ;
#endif
F_30 ( V_1 ) ;
}
static int F_31 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
T_2 V_68 = F_26 ( V_13 -> V_65 + V_69 ) ;
if ( V_68 & V_70 ) {
F_23 ( 20 ) ;
V_68 = F_26 ( V_13 -> V_65 + V_69 ) ;
if ( V_68 & V_70 )
F_24 ( V_1 ) ;
}
return F_32 ( V_1 ) ;
}
static int F_33 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
T_5 V_62 = 0 ;
T_2 V_68 ;
F_25 ( V_8 , V_13 -> V_61 + 2 , & V_62 ) ;
if ( V_62 & 0x1FF ) {
return 0 ;
}
V_68 = F_26 ( V_13 -> V_65 + V_69 ) ;
if ( V_68 & V_71 )
return 1 ;
return 0 ;
}
static int F_34 ( T_1 * V_1 )
{
T_3 * V_13 = V_1 -> V_13 ;
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
T_2 V_72 = 0 , V_73 = V_13 -> V_61 ;
T_2 V_74 = 0 , V_14 = V_13 -> V_75 ? 0x02 : 0x01 ;
F_15 ( V_8 , 0x6a , & V_74 ) ;
F_15 ( V_8 , V_73 , & V_72 ) ;
if ( V_74 & V_14 )
F_16 ( V_8 , V_73 , V_72 | 0x30 ) ;
return F_32 ( V_1 ) ;
}
static void F_35 ( T_3 * V_13 , T_2 V_76 )
{
unsigned long V_77 = V_13 -> V_78 ;
T_2 V_79 = F_26 ( V_77 + 0x6b ) ;
if ( ( V_79 & 0x7f ) == V_76 )
return;
F_27 ( 0x80 , V_77 + 0x63 ) ;
F_27 ( 0x80 , V_77 + 0x67 ) ;
F_27 ( V_76 , V_77 + 0x6b ) ;
F_27 ( 0xc0 , V_77 + 0x69 ) ;
F_27 ( F_26 ( V_77 + 0x60 ) | 0x32 , V_77 + 0x60 ) ;
F_27 ( F_26 ( V_77 + 0x64 ) | 0x32 , V_77 + 0x64 ) ;
F_27 ( 0x00 , V_77 + 0x69 ) ;
F_27 ( 0x00 , V_77 + 0x63 ) ;
F_27 ( 0x00 , V_77 + 0x67 ) ;
}
static void F_36 ( T_1 * V_1 , struct V_80 * V_81 )
{
F_35 ( V_1 -> V_13 , F_37 ( V_81 ) ? 0x21 : 0x23 ) ;
}
static int F_38 ( struct V_39 * V_8 , T_5 V_82 , T_5 V_83 )
{
T_4 V_84 = ( V_83 << 16 ) | V_82 | 0x100 ;
T_2 V_79 ;
int V_35 ;
F_12 ( V_8 , 0x5c , V_84 ) ;
for( V_35 = 0 ; V_35 < 0x5000 ; ++ V_35 ) {
F_23 ( 50 ) ;
F_15 ( V_8 , 0x5b , & V_79 ) ;
if ( V_79 & 0x80 )
break;
}
for( V_35 = 0 ; V_35 < 0x1000 ; ++ V_35 ) {
F_15 ( V_8 , 0x5b , & V_79 ) ;
if( ! ( V_79 & 0x80 ) )
return 0 ;
}
F_11 ( V_8 , 0x5c , & V_84 ) ;
F_12 ( V_8 , 0x5c , ( V_84 & ~ 0x100 ) ) ;
return 1 ;
}
static void F_39 ( struct V_39 * V_8 , T_2 V_73 )
{
struct V_9 * V_10 = F_40 ( V_8 ) ;
struct V_6 * V_11 = V_10 -> V_12 + ( & V_8 -> V_8 == V_10 -> V_8 [ 1 ] ) ;
T_2 V_16 = V_11 -> V_16 ;
T_2 V_85 , V_86 = 0 ;
F_15 ( V_8 , V_73 + 1 , & V_86 ) ;
if ( V_16 >= V_32 )
V_85 = V_86 & ~ 0x07 ;
else if ( V_16 >= V_24 ) {
V_85 = V_86 ;
V_85 &= ~ 0x02 ;
#ifdef F_41
V_85 &= ~ 0x01 ;
#else
V_85 |= 0x01 ;
#endif
} else
V_85 = V_86 & ~ 0x80 ;
if ( V_85 != V_86 )
F_16 ( V_8 , V_73 + 1 , V_85 ) ;
}
static int F_42 ( struct V_39 * V_8 )
{
unsigned long V_87 = F_43 ( V_8 , 4 ) ;
struct V_6 * V_11 = F_2 ( & V_8 -> V_8 ) ;
const char * V_59 = V_88 ;
T_2 V_89 , V_90 = 0 ;
T_2 V_16 ;
enum V_91 clock ;
V_16 = V_11 -> V_16 ;
F_16 ( V_8 , V_92 , ( V_93 / 4 ) ) ;
F_16 ( V_8 , V_94 , 0x78 ) ;
F_16 ( V_8 , V_95 , 0x08 ) ;
F_16 ( V_8 , V_96 , 0x08 ) ;
if ( V_16 >= V_24 ) {
T_2 V_55 = 0 ;
T_5 V_97 = 0 ;
T_4 V_98 = 0 ;
F_15 ( V_8 , 0x5a , & V_55 ) ;
if ( V_55 & 0x10 )
F_16 ( V_8 , 0x5a , V_55 & ~ 0x10 ) ;
if ( V_16 == V_30 )
F_27 ( 0x0e , V_87 + 0x9c ) ;
F_16 ( V_8 , 0x5b , 0x23 ) ;
if ( V_16 == V_32 && ( F_44 ( V_8 -> V_99 ) & 1 ) ) {
struct V_39 * V_100 = F_45 ( V_8 -> V_101 ,
V_8 -> V_99 - 1 ) ;
unsigned long V_87 = F_43 ( V_100 , 4 ) ;
V_98 = F_46 ( V_87 + 0x90 ) ;
F_47 ( V_100 ) ;
} else
V_98 = F_46 ( V_87 + 0x90 ) ;
if ( ( V_98 & 0xFFFFF000 ) != 0xABCDE000 ) {
int V_35 ;
F_20 ( V_102 L_3
L_4 , V_59 , F_48 ( V_8 ) ) ;
for ( V_98 = V_35 = 0 ; V_35 < 128 ; V_35 ++ ) {
F_25 ( V_8 , 0x78 , & V_97 ) ;
V_98 += V_97 & 0x1ff ;
F_49 ( 1 ) ;
}
V_97 = V_98 / 128 ;
} else
V_97 = V_98 & 0x1ff ;
V_90 = V_11 -> V_90 ;
V_89 = ( V_97 * V_90 ) / 192 ;
if ( V_89 < 40 )
V_89 = 33 ;
else if( V_89 < 45 )
V_89 = 40 ;
else if( V_89 < 55 )
V_89 = 50 ;
else
V_89 = 66 ;
F_20 ( V_103 L_5
L_6 , V_59 , F_48 ( V_8 ) ,
V_90 , V_97 , V_89 ) ;
} else {
T_4 V_104 = 0 ;
F_11 ( V_8 , 0x40 , & V_104 ) ;
switch( ( V_104 >> 8 ) & 0x07 ) {
case 0x09 :
V_89 = 40 ;
break;
case 0x05 :
V_89 = 25 ;
break;
case 0x07 :
default:
V_89 = 33 ;
break;
}
}
switch ( V_89 ) {
case 25 :
clock = V_105 ;
break;
case 33 :
default:
clock = V_106 ;
break;
case 40 :
clock = V_107 ;
break;
case 50 :
clock = V_108 ;
break;
case 66 :
clock = V_109 ;
break;
}
if ( V_16 >= V_32 || V_11 -> V_37 -> V_38 [ clock ] == NULL ) {
T_5 V_82 , V_110 = V_89 < 50 ? 2 : 4 ;
int V_111 ;
if ( V_11 -> V_112 == V_113 ) {
V_90 = 66 ;
clock = V_109 ;
} else if ( V_90 ) {
V_90 = 50 ;
clock = V_108 ;
}
if ( V_11 -> V_37 -> V_38 [ clock ] == NULL ) {
F_20 ( V_114 L_7 ,
V_59 , F_48 ( V_8 ) ) ;
return - V_115 ;
}
F_16 ( V_8 , 0x5b , 0x21 ) ;
V_82 = ( V_89 * 48 ) / V_90 ;
for ( V_111 = 0 ; V_111 < 8 ; V_111 ++ ) {
if( F_38 ( V_8 , V_82 , V_82 + V_110 ) )
break;
if ( V_111 & 1 )
V_82 -= V_111 >> 1 ;
else
V_82 += V_111 >> 1 ;
}
if ( V_111 == 8 ) {
F_20 ( V_114 L_8 ,
V_59 , F_48 ( V_8 ) ) ;
return - V_115 ;
}
F_20 ( V_103 L_9 ,
V_59 , F_48 ( V_8 ) , V_90 ) ;
} else {
V_90 = 0 ;
F_20 ( V_103 L_10 ,
V_59 , F_48 ( V_8 ) , V_89 ) ;
}
V_11 -> V_90 = V_90 ;
V_11 -> V_89 = V_89 ;
V_11 -> clock = clock ;
if ( V_16 >= V_24 ) {
T_2 V_57 , V_116 ;
F_15 ( V_8 , 0x50 , & V_57 ) ;
F_15 ( V_8 , 0x54 , & V_116 ) ;
F_16 ( V_8 , 0x50 , ( V_57 | 0x32 ) ) ;
F_16 ( V_8 , 0x54 , ( V_116 | 0x32 ) ) ;
F_23 ( 100 ) ;
}
if ( V_16 == V_117 && clock == V_109 )
F_27 ( F_26 ( V_87 + 0x9c ) | 0x04 , V_87 + 0x9c ) ;
F_39 ( V_8 , 0x50 ) ;
F_39 ( V_8 , 0x54 ) ;
return 0 ;
}
static T_2 F_50 ( T_3 * V_13 )
{
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
T_2 V_16 = V_11 -> V_16 ;
T_2 V_55 = 0 , V_118 = V_13 -> V_75 ? 0x01 : 0x02 ;
if ( V_16 == V_32 && ( F_44 ( V_8 -> V_99 ) & 1 ) ) {
T_2 V_73 = V_13 -> V_61 + 2 ;
T_5 V_72 ;
F_25 ( V_8 , V_73 , & V_72 ) ;
F_51 ( V_8 , V_73 , V_72 | 0x8000 ) ;
F_23 ( 10 ) ;
F_15 ( V_8 , 0x5a , & V_55 ) ;
F_51 ( V_8 , V_73 , V_72 ) ;
} else if ( V_16 >= V_24 ) {
T_2 V_79 = 0 ;
F_15 ( V_8 , 0x5b , & V_79 ) ;
F_16 ( V_8 , 0x5b , V_79 & ~ 1 ) ;
F_23 ( 10 ) ;
F_15 ( V_8 , 0x5a , & V_55 ) ;
F_16 ( V_8 , 0x5b , V_79 ) ;
} else
F_15 ( V_8 , 0x5a , & V_55 ) ;
return ( V_55 & V_118 ) ? V_119 : V_120 ;
}
static void T_6 F_52 ( T_3 * V_13 )
{
struct V_6 * V_11 = F_2 ( V_13 -> V_8 ) ;
T_2 V_16 = V_11 -> V_16 ;
V_13 -> V_61 = V_13 -> V_75 ? 0x54 : 0x50 ;
if ( V_16 >= V_31 && V_11 -> V_90 && V_11 -> V_89 < 66 ) {
V_13 -> V_10 -> V_121 |= V_122 ;
V_13 -> V_123 = & F_36 ;
}
}
static int T_6 F_53 ( T_3 * V_13 ,
const struct V_124 * V_125 )
{
struct V_39 * V_8 = F_10 ( V_13 -> V_8 ) ;
unsigned long V_126 , V_77 = F_54 ( V_13 , V_125 ) ;
T_2 V_127 , V_128 , V_129 = 0 , V_130 = 0 ;
if ( V_77 == 0 )
return - 1 ;
V_13 -> V_65 = V_77 ;
if ( F_55 ( V_13 , V_125 ) < 0 )
return - 1 ;
if ( F_56 ( V_8 , V_125 -> V_59 ) < 0 )
return - 1 ;
V_127 = F_26 ( V_77 + 2 ) ;
F_57 ( V_126 ) ;
V_128 = V_127 ;
F_15 ( V_8 , V_13 -> V_75 ? 0x4b : 0x43 , & V_129 ) ;
F_15 ( V_8 , V_13 -> V_75 ? 0x4f : 0x47 , & V_130 ) ;
if ( V_129 & 0x30 ) V_128 |= 0x20 ;
if ( V_130 & 0x30 ) V_128 |= 0x40 ;
if ( V_128 != V_127 )
F_27 ( V_128 , V_77 + 2 ) ;
F_58 ( V_126 ) ;
F_20 ( V_103 L_11 ,
V_13 -> V_59 , V_77 , V_77 + 7 ) ;
V_13 -> V_78 = V_77 + ( V_13 -> V_75 ? 8 : 16 ) ;
if ( F_59 ( V_13 ) )
return - 1 ;
return 0 ;
}
static void T_6 F_60 ( struct V_39 * V_8 , struct V_39 * V_131 )
{
if ( V_131 -> V_56 != V_8 -> V_56 ) {
V_131 -> V_56 = V_8 -> V_56 ;
F_20 (KERN_INFO DRV_NAME L_12
L_13 , pci_name(dev2)) ;
}
}
static void T_6 F_61 ( struct V_39 * V_8 )
{
T_2 V_57 = 0 ;
F_15 ( V_8 , 0x50 , & V_57 ) ;
if ( V_57 & 0x04 )
F_16 ( V_8 , 0x50 , V_57 & ~ 0x04 ) ;
}
static int T_6 F_62 ( struct V_39 * V_8 , struct V_39 * V_131 )
{
T_2 V_57 = 0 , V_132 = 0 , V_133 = 0 ;
F_15 ( V_8 , 0x50 , & V_57 ) ;
if ( V_57 & 0x30 )
F_16 ( V_8 , 0x50 , V_57 | 0x30 ) ;
F_15 ( V_8 , V_134 , & V_132 ) ;
F_15 ( V_131 , V_134 , & V_133 ) ;
if ( V_132 != V_133 && V_8 -> V_56 == V_131 -> V_56 ) {
F_20 (KERN_INFO DRV_NAME L_14
L_15 , pci_name(dev), pin1, pin2) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_63 ( struct V_39 * V_8 , const struct V_135 * V_4 )
{
const struct V_6 * V_11 = NULL ;
struct V_6 * V_136 ;
struct V_39 * V_131 = NULL ;
struct V_124 V_125 ;
T_2 V_137 = V_4 -> V_138 ;
T_2 V_139 = V_8 -> V_140 ;
int V_141 ;
if ( ( V_137 == 0 || V_137 == 4 ) && ( F_44 ( V_8 -> V_99 ) & 1 ) )
return - V_142 ;
switch ( V_137 ) {
case 0 :
if ( V_139 < 3 )
V_11 = & V_143 ;
else {
switch ( F_64 ( T_2 , V_139 , 6 ) ) {
case 3 : V_11 = & V_144 ; break;
case 4 : V_11 = & V_145 ; break;
case 5 : V_11 = & V_146 ; break;
case 6 : V_11 = & V_147 ; break;
}
V_137 ++ ;
}
break;
case 1 :
V_11 = ( V_139 > 1 ) ? & V_147 : & V_148 ;
break;
case 2 :
V_11 = ( V_139 > 1 ) ? & V_149 : & V_150 ;
break;
case 3 :
F_61 ( V_8 ) ;
V_11 = ( V_139 > 1 ) ? & V_151 : & V_152 ;
break;
case 4 :
V_11 = & V_153 ;
break;
case 5 :
V_11 = & V_147 ;
break;
}
F_20 (KERN_INFO DRV_NAME L_16 , info->chip_name) ;
V_125 = V_154 [ F_64 ( T_2 , V_137 , 1 ) ] ;
V_125 . V_112 = V_11 -> V_112 ;
if ( V_11 == & V_144 || V_11 == & V_145 )
V_125 . V_155 = & V_156 ;
if ( V_11 == & V_143 || V_11 == & V_153 )
V_131 = F_45 ( V_8 -> V_101 , V_8 -> V_99 + 1 ) ;
V_136 = F_65 ( sizeof( * V_136 ) * ( V_131 ? 2 : 1 ) , V_157 ) ;
if ( V_136 == NULL ) {
F_20 ( V_114 L_17 ,
V_125 . V_59 , F_48 ( V_8 ) ) ;
F_47 ( V_131 ) ;
return - V_158 ;
}
memcpy ( V_136 , V_11 , sizeof( * V_136 ) ) ;
if ( V_131 ) {
memcpy ( V_136 + 1 , V_11 , sizeof( * V_136 ) ) ;
if ( V_11 == & V_153 )
F_60 ( V_8 , V_131 ) ;
else {
if ( F_62 ( V_8 , V_131 ) )
V_125 . V_121 &= ~ V_159 ;
}
V_141 = F_66 ( V_8 , V_131 , & V_125 , V_136 ) ;
if ( V_141 < 0 ) {
F_47 ( V_131 ) ;
F_67 ( V_136 ) ;
}
return V_141 ;
}
V_141 = F_68 ( V_8 , & V_125 , V_136 ) ;
if ( V_141 < 0 )
F_67 ( V_136 ) ;
return V_141 ;
}
static void T_7 F_69 ( struct V_39 * V_8 )
{
struct V_9 * V_10 = F_40 ( V_8 ) ;
struct V_160 * V_11 = V_10 -> V_12 ;
struct V_39 * V_131 = V_10 -> V_8 [ 1 ] ? F_10 ( V_10 -> V_8 [ 1 ] ) : NULL ;
F_70 ( V_8 ) ;
F_47 ( V_131 ) ;
F_67 ( V_11 ) ;
}
static int T_8 F_71 ( void )
{
return F_72 ( & V_161 ) ;
}
static void T_9 F_73 ( void )
{
F_74 ( & V_161 ) ;
}
