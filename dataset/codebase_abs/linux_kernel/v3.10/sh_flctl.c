static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 | V_4 | V_5 , F_3 ( V_2 ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_6 , F_6 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , const char * V_7 )
{
F_8 ( & V_2 -> V_8 -> V_9 , L_1 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
if ( F_10 ( F_6 ( V_2 ) ) & V_12 ) {
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
return;
}
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
}
static void F_12 ( void * V_14 )
{
struct V_1 * V_2 = V_14 ;
F_13 ( & V_2 -> V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 ) {
F_15 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
if ( V_2 -> V_17 ) {
F_15 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_8 = V_2 -> V_8 ;
struct V_22 * V_23 = V_8 -> V_9 . V_24 ;
int V_25 ;
if ( ! V_23 )
return;
if ( V_23 -> V_26 <= 0 || V_23 -> V_27 <= 0 )
return;
F_17 ( V_18 ) ;
F_18 ( V_28 , V_18 ) ;
V_2 -> V_17 = F_19 ( V_18 , V_29 ,
( void * ) V_23 -> V_26 ) ;
F_20 ( & V_8 -> V_9 , L_2 , V_13 ,
V_2 -> V_17 ) ;
if ( ! V_2 -> V_17 )
return;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_30 = V_23 -> V_26 ;
V_20 . V_31 = V_32 ;
V_20 . V_33 = ( V_34 ) F_21 ( V_2 ) ;
V_20 . V_35 = 0 ;
V_25 = F_22 ( V_2 -> V_17 , & V_20 ) ;
if ( V_25 < 0 )
goto V_36;
V_2 -> V_16 = F_19 ( V_18 , V_29 ,
( void * ) V_23 -> V_27 ) ;
F_20 ( & V_8 -> V_9 , L_3 , V_13 ,
V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_36;
V_20 . V_30 = V_23 -> V_27 ;
V_20 . V_31 = V_37 ;
V_20 . V_33 = 0 ;
V_20 . V_35 = ( V_34 ) F_21 ( V_2 ) ;
V_25 = F_22 ( V_2 -> V_16 , & V_20 ) ;
if ( V_25 < 0 )
goto V_36;
F_23 ( & V_2 -> V_15 ) ;
return;
V_36:
F_14 ( V_2 ) ;
}
static void F_24 ( struct V_38 * V_39 , int V_40 , int V_41 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
T_1 V_42 = 0 ;
if ( V_40 == - 1 ) {
V_42 = V_41 ;
} else if ( V_41 != - 1 ) {
if ( V_2 -> V_43 . V_44 & V_45 )
V_40 >>= 1 ;
if ( V_2 -> V_46 ) {
V_42 = V_40 & 0x0FFF ;
V_42 |= ( V_41 & 0xff ) << 16 ;
V_42 |= ( ( V_41 >> 8 ) & 0xff ) << 24 ;
if ( V_2 -> V_47 == V_48 ) {
T_1 V_49 ;
V_49 = ( V_41 >> 16 ) & 0xff ;
F_2 ( V_49 , F_26 ( V_2 ) ) ;
}
} else {
V_42 = V_40 ;
V_42 |= ( V_41 & 0xff ) << 8 ;
V_42 |= ( ( V_41 >> 8 ) & 0xff ) << 16 ;
V_42 |= ( ( V_41 >> 16 ) & 0xff ) << 24 ;
}
}
F_2 ( V_42 , F_27 ( V_2 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
T_1 V_50 ;
V_50 = F_29 ( F_30 ( V_2 ) ) >> 16 ;
if ( V_50 & 0xFF )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_51 , V_10 = V_11 ;
while ( V_10 -- ) {
V_51 = ( F_29 ( F_30 ( V_2 ) ) >> 16 ) & 0xFF ;
if ( V_51 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static enum V_52 F_32
( struct V_1 * V_2 , int V_53 )
{
T_1 V_10 = V_11 ;
void T_3 * V_54 [ 4 ] ;
int V_55 ;
int V_56 = V_57 ;
T_1 V_58 , V_59 ;
while ( V_10 -- ) {
V_59 = F_29 ( F_30 ( V_2 ) ) >> 24 ;
if ( ( V_59 & 0xFF ) == 4 )
return V_56 ;
if ( ! ( F_29 ( F_33 ( V_2 ) ) & V_60 ) ) {
F_11 ( 1 ) ;
continue;
}
if ( F_29 ( F_33 ( V_2 ) ) & V_61 ) {
for ( V_55 = 0 ; V_55 < 512 ; V_55 ++ ) {
if ( V_2 -> V_62 [ V_55 ] != 0xff ) {
V_56 = V_63 ;
break;
}
}
if ( V_56 == V_57 )
F_20 ( & V_2 -> V_8 -> V_9 ,
L_4 ,
V_53 ) ;
F_2 ( 0 , F_33 ( V_2 ) ) ;
continue;
}
V_54 [ 0 ] = F_34 ( V_2 ) ;
V_54 [ 1 ] = F_35 ( V_2 ) ;
V_54 [ 2 ] = F_36 ( V_2 ) ;
V_54 [ 3 ] = F_37 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
T_4 V_64 ;
unsigned int V_65 ;
V_58 = F_29 ( V_54 [ V_55 ] ) ;
if ( V_2 -> V_46 )
V_65 = ( 512 * V_53 ) +
( V_58 >> 16 ) ;
else
V_65 = V_58 >> 16 ;
V_64 = V_2 -> V_62 [ V_65 ] ;
V_2 -> V_62 [ V_65 ] = V_64 ^ ( V_58 & 0xFF ) ;
}
V_56 = V_66 ;
F_2 ( 0 , F_33 ( V_2 ) ) ;
}
F_7 ( V_2 , V_13 ) ;
return V_67 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
T_1 V_51 ;
while ( V_10 -- ) {
V_51 = ( F_29 ( F_30 ( V_2 ) ) >> 24 ) & 0xFF ;
if ( V_51 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long * V_68 ,
int V_51 , enum V_69 V_70 )
{
struct V_71 * V_72 = NULL ;
struct V_73 * V_74 ;
enum V_75 V_76 ;
V_34 V_77 ;
T_5 V_78 = - V_79 ;
T_1 V_80 ;
int V_25 ;
if ( V_70 == V_81 ) {
V_74 = V_2 -> V_16 ;
V_76 = V_37 ;
} else {
V_74 = V_2 -> V_17 ;
V_76 = V_32 ;
}
V_77 = F_40 ( V_74 -> V_82 -> V_9 , V_68 , V_51 , V_70 ) ;
if ( V_77 )
V_72 = F_41 ( V_74 , V_77 , V_51 ,
V_76 , V_83 | V_84 ) ;
if ( V_72 ) {
V_80 = F_29 ( F_3 ( V_2 ) ) ;
V_80 |= V_85 ;
F_2 ( V_80 , F_3 ( V_2 ) ) ;
V_72 -> V_86 = F_12 ;
V_72 -> V_87 = V_2 ;
V_78 = F_42 ( V_72 ) ;
F_43 ( V_74 ) ;
} else {
F_14 ( V_2 ) ;
F_44 ( & V_2 -> V_8 -> V_9 ,
L_5 ) ;
V_25 = - V_88 ;
goto V_89;
}
V_25 =
F_45 ( & V_2 -> V_15 ,
F_46 ( 3000 ) ) ;
if ( V_25 <= 0 ) {
V_74 -> V_82 -> V_90 ( V_74 , V_91 , 0 ) ;
F_8 ( & V_2 -> V_8 -> V_9 , L_6 ) ;
}
V_89:
V_80 = F_29 ( F_3 ( V_2 ) ) ;
V_80 &= ~ V_85 ;
F_2 ( V_80 , F_3 ( V_2 ) ) ;
F_47 ( V_74 -> V_82 -> V_9 , V_77 , V_51 , V_70 ) ;
return V_25 ;
}
static void F_48 ( struct V_1 * V_2 , int V_92 )
{
unsigned long V_58 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_92 ] ;
F_9 ( V_2 ) ;
V_58 = F_29 ( F_49 ( V_2 ) ) ;
* V_68 = F_50 ( V_58 ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_93 , int V_92 )
{
int V_55 , V_94 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_92 ] ;
V_94 = ( V_93 + 3 ) / 4 ;
if ( V_2 -> V_16 && V_93 >= 32 &&
F_39 ( V_2 , V_68 , V_93 , V_37 ) > 0 )
goto V_95;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ ) {
F_28 ( V_2 ) ;
V_68 [ V_55 ] = F_29 ( F_21 ( V_2 ) ) ;
}
V_95:
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ )
V_68 [ V_55 ] = F_52 ( V_68 [ V_55 ] ) ;
}
static enum V_52 F_53
( struct V_1 * V_2 , T_4 * V_96 , int V_97 )
{
int V_55 ;
enum V_52 V_98 ;
unsigned long * V_99 = ( unsigned long * ) V_96 ;
V_98 = F_32 ( V_2 , V_97 ) ;
if ( V_98 != V_63 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
V_99 [ V_55 ] = F_29 ( F_54 ( V_2 ) ) ;
V_99 [ V_55 ] = F_52 ( V_99 [ V_55 ] ) ;
}
}
return V_98 ;
}
static void F_55 ( struct V_1 * V_2 , int V_93 ,
unsigned int V_92 )
{
int V_55 , V_94 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_92 ] ;
V_94 = ( V_93 + 3 ) / 4 ;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ ) {
F_31 ( V_2 ) ;
F_2 ( F_56 ( V_68 [ V_55 ] ) , F_21 ( V_2 ) ) ;
}
}
static void F_57 ( struct V_1 * V_2 , int V_93 ,
unsigned int V_92 )
{
int V_55 , V_94 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_92 ] ;
V_94 = ( V_93 + 3 ) / 4 ;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ )
V_68 [ V_55 ] = F_56 ( V_68 [ V_55 ] ) ;
if ( V_2 -> V_17 && V_93 >= 32 &&
F_39 ( V_2 , V_68 , V_93 , V_32 ) > 0 )
return;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ ) {
F_38 ( V_2 ) ;
F_2 ( V_68 [ V_55 ] , F_54 ( V_2 ) ) ;
}
}
static void F_58 ( struct V_38 * V_39 , T_1 V_100 , T_1 V_101 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
T_1 V_102 = V_2 -> V_103 & ~ V_104 ;
T_1 V_105 , V_106 = 0 ;
if ( V_2 -> V_46 )
V_102 |= V_107 ;
else
V_102 &= ~ V_107 ;
V_105 = V_108 | V_109 ;
switch ( V_100 ) {
case V_110 :
V_106 = V_2 -> V_111 ;
V_105 |= V_112 ;
break;
case V_113 :
case V_114 :
case V_115 :
V_106 = V_2 -> V_47 ;
V_105 |= V_116 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_102 |= V_104 ;
break;
case V_117 :
V_105 &= ~ V_109 ;
break;
case V_118 :
V_106 = V_2 -> V_47 ;
V_105 |= V_112 | V_116 | V_119 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_102 |= V_104 ;
break;
case V_120 :
V_102 &= ~ V_107 ;
V_105 |= V_116 ;
V_106 = V_121 ;
break;
case V_122 :
case V_123 :
V_102 &= ~ V_107 ;
V_105 &= ~ ( V_109 | V_124 ) ;
break;
default:
break;
}
V_105 |= V_106 ;
F_2 ( V_102 , F_59 ( V_2 ) ) ;
F_2 ( V_105 , F_60 ( V_2 ) ) ;
F_2 ( V_101 , F_61 ( V_2 ) ) ;
}
static int F_62 ( struct V_38 * V_39 , struct V_125 * V_43 ,
T_4 * V_68 , int V_126 , int V_127 )
{
V_43 -> V_128 ( V_39 , V_68 , V_39 -> V_129 ) ;
if ( V_126 )
V_43 -> V_128 ( V_39 , V_43 -> V_130 , V_39 -> V_131 ) ;
return 0 ;
}
static int F_63 ( struct V_38 * V_39 , struct V_125 * V_43 ,
const T_4 * V_68 , int V_126 )
{
V_43 -> V_132 ( V_39 , V_68 , V_39 -> V_129 ) ;
V_43 -> V_132 ( V_39 , V_43 -> V_130 , V_39 -> V_131 ) ;
return 0 ;
}
static void F_64 ( struct V_38 * V_39 , int V_41 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
int V_97 , V_133 ;
enum V_52 V_134 ;
V_133 = V_2 -> V_46 ? 4 : 1 ;
F_58 ( V_39 , V_113 ,
( V_135 << 8 ) | V_113 ) ;
F_2 ( F_29 ( F_59 ( V_2 ) ) | V_136 | V_137 ,
F_59 ( V_2 ) ) ;
F_2 ( F_29 ( F_60 ( V_2 ) ) | V_133 , F_60 ( V_2 ) ) ;
F_2 ( V_41 << 2 , F_27 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_97 = 0 ; V_97 < V_133 ; V_97 ++ ) {
F_51 ( V_2 , 512 , 512 * V_97 ) ;
V_134 = F_53 ( V_2 ,
& V_2 -> V_62 [ V_39 -> V_129 + 16 * V_97 ] ,
V_97 ) ;
switch ( V_134 ) {
case V_66 :
F_65 ( & V_2 -> V_8 -> V_9 ,
L_7 , V_41 ) ;
V_2 -> V_39 . V_138 . V_139 ++ ;
break;
case V_63 :
F_44 ( & V_2 -> V_8 -> V_9 ,
L_8 ,
V_41 ) ;
V_2 -> V_39 . V_138 . V_140 ++ ;
break;
default:
;
}
}
F_9 ( V_2 ) ;
F_2 ( F_29 ( F_59 ( V_2 ) ) & ~ ( V_136 | V_137 ) ,
F_59 ( V_2 ) ) ;
}
static void F_66 ( struct V_38 * V_39 , int V_41 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
int V_133 = V_2 -> V_46 ? 4 : 1 ;
int V_55 ;
F_58 ( V_39 , V_113 ,
( V_135 << 8 ) | V_113 ) ;
F_1 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_133 ; V_55 ++ ) {
F_24 ( V_39 , ( 512 + 16 ) * V_55 + 512 , V_41 ) ;
F_2 ( 16 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_51 ( V_2 , 16 , 16 * V_55 ) ;
F_9 ( V_2 ) ;
}
}
static void F_67 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
int V_41 = V_2 -> V_141 ;
int V_97 , V_133 ;
V_133 = V_2 -> V_46 ? 4 : 1 ;
F_58 ( V_39 , V_118 ,
( V_118 << 8 ) | V_117 ) ;
F_1 ( V_2 ) ;
F_2 ( F_29 ( F_59 ( V_2 ) ) | V_136 , F_59 ( V_2 ) ) ;
F_2 ( F_29 ( F_60 ( V_2 ) ) | V_133 , F_60 ( V_2 ) ) ;
F_2 ( V_41 << 2 , F_27 ( V_2 ) ) ;
F_4 ( V_2 ) ;
for ( V_97 = 0 ; V_97 < V_133 ; V_97 ++ ) {
F_55 ( V_2 , 512 , 512 * V_97 ) ;
F_57 ( V_2 , 16 , V_39 -> V_129 + 16 * V_97 ) ;
}
F_9 ( V_2 ) ;
F_2 ( F_29 ( F_59 ( V_2 ) ) & ~ V_136 , F_59 ( V_2 ) ) ;
}
static void F_68 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
int V_41 = V_2 -> V_141 ;
int V_97 , V_133 ;
V_133 = V_2 -> V_46 ? 4 : 1 ;
F_58 ( V_39 , V_118 ,
( V_118 << 8 ) | V_117 ) ;
for ( V_97 = 0 ; V_97 < V_133 ; V_97 ++ ) {
F_1 ( V_2 ) ;
F_24 ( V_39 , V_97 * 528 + 512 , V_41 ) ;
F_2 ( 16 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_55 ( V_2 , 16 , 16 * V_97 ) ;
F_9 ( V_2 ) ;
}
}
static void F_69 ( struct V_38 * V_39 , unsigned int V_142 ,
int V_40 , int V_41 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
T_1 V_143 = 0 ;
F_70 ( & V_2 -> V_8 -> V_9 ) ;
V_2 -> V_144 = 0 ;
if ( V_142 != V_118 )
V_2 -> V_65 = 0 ;
switch ( V_142 ) {
case V_145 :
case V_113 :
if ( V_2 -> V_146 ) {
F_64 ( V_39 , V_41 ) ;
break;
}
if ( V_2 -> V_46 )
F_58 ( V_39 , V_142 , ( V_135 << 8 )
| V_142 ) ;
else
F_58 ( V_39 , V_142 , V_142 ) ;
F_24 ( V_39 , 0 , V_41 ) ;
V_2 -> V_144 = V_39 -> V_129 + V_39 -> V_131 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_40 >>= 1 ;
V_2 -> V_65 += V_40 ;
goto V_147;
case V_114 :
if ( V_2 -> V_146 ) {
F_66 ( V_39 , V_41 ) ;
break;
}
if ( V_2 -> V_46 ) {
F_58 ( V_39 , V_142 , ( V_135 << 8 )
| V_113 ) ;
F_24 ( V_39 , V_39 -> V_129 , V_41 ) ;
} else {
F_58 ( V_39 , V_142 , V_142 ) ;
F_24 ( V_39 , 0 , V_41 ) ;
}
V_2 -> V_144 = V_39 -> V_131 ;
goto V_147;
case V_115 :
if ( V_2 -> V_146 )
break;
if ( V_2 -> V_46 )
F_58 ( V_39 , V_142 , ( V_148 << 8 )
| V_142 ) ;
else
F_58 ( V_39 , V_142 , V_142 ) ;
F_24 ( V_39 , V_40 , 0 ) ;
V_2 -> V_144 = V_39 -> V_129 + V_39 -> V_131 - V_40 ;
goto V_147;
case V_120 :
F_58 ( V_39 , V_142 , V_142 ) ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_40 <<= 1 ;
F_24 ( V_39 , V_40 , 0 ) ;
V_2 -> V_144 = 8 ;
F_2 ( V_2 -> V_144 , F_30 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_51 ( V_2 , V_2 -> V_144 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_110 :
V_2 -> V_149 = V_41 ;
break;
case V_150 :
F_58 ( V_39 , V_110 ,
( V_142 << 8 ) | V_110 ) ;
F_24 ( V_39 , - 1 , V_2 -> V_149 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_117 :
if ( ! V_2 -> V_46 ) {
if ( V_40 >= V_39 -> V_129 ) {
V_40 -= V_39 -> V_129 ;
V_143 = V_114 ;
} else if ( V_40 < 256 ) {
V_143 = V_113 ;
} else {
V_40 -= 256 ;
V_143 = V_145 ;
}
}
V_2 -> V_151 = V_40 ;
V_2 -> V_141 = V_41 ;
V_2 -> V_152 = V_143 ;
break;
case V_118 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_46 ) {
F_58 ( V_39 , V_117 ,
V_2 -> V_152 ) ;
F_24 ( V_39 , - 1 , - 1 ) ;
F_2 ( 0 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_146 ) {
if ( V_2 -> V_151 == V_39 -> V_129 )
F_68 ( V_39 ) ;
else if ( ! V_2 -> V_151 )
F_67 ( V_39 ) ;
else
F_71 ( V_153 L_9 ) ;
break;
}
F_58 ( V_39 , V_142 , ( V_142 << 8 ) | V_117 ) ;
F_24 ( V_39 , V_2 -> V_151 , V_2 -> V_141 ) ;
F_2 ( V_2 -> V_65 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_55 ( V_2 , V_2 -> V_65 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_122 :
F_58 ( V_39 , V_142 , V_142 ) ;
F_24 ( V_39 , - 1 , - 1 ) ;
V_2 -> V_144 = 1 ;
F_2 ( V_2 -> V_144 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_48 ( V_2 , 0 ) ;
break;
case V_123 :
F_58 ( V_39 , V_142 , V_142 ) ;
F_24 ( V_39 , - 1 , - 1 ) ;
F_2 ( 0 , F_30 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_154;
V_147:
F_2 ( V_2 -> V_144 , F_30 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_51 ( V_2 , V_2 -> V_144 , 0 ) ;
F_9 ( V_2 ) ;
V_154:
F_72 ( & V_2 -> V_8 -> V_9 ) ;
return;
}
static void F_73 ( struct V_38 * V_39 , int V_155 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
int V_25 ;
switch ( V_155 ) {
case - 1 :
V_2 -> V_103 &= ~ V_156 ;
F_70 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_2 -> V_103 , F_59 ( V_2 ) ) ;
if ( V_2 -> V_157 ) {
F_74 ( & V_2 -> V_158 ) ;
V_2 -> V_157 = 0 ;
}
F_72 ( & V_2 -> V_8 -> V_9 ) ;
break;
case 0 :
V_2 -> V_103 |= V_156 ;
if ( ! V_2 -> V_157 ) {
V_25 = F_75 ( & V_2 -> V_8 -> V_9 ,
& V_2 -> V_158 ,
V_159 ,
100 ) ;
if ( V_25 < 0 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_10 , V_25 ) ;
V_2 -> V_157 = 1 ;
}
if ( V_2 -> V_160 ) {
F_70 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_161 , F_76 ( V_2 ) ) ;
F_72 ( & V_2 -> V_8 -> V_9 ) ;
}
break;
default:
F_77 () ;
}
}
static void F_78 ( struct V_38 * V_39 , const T_4 * V_68 , int V_51 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
memcpy ( & V_2 -> V_62 [ V_2 -> V_65 ] , V_68 , V_51 ) ;
V_2 -> V_65 += V_51 ;
}
static T_4 F_79 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
T_4 V_58 ;
V_58 = V_2 -> V_62 [ V_2 -> V_65 ] ;
V_2 -> V_65 ++ ;
return V_58 ;
}
static T_6 F_80 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
T_6 * V_68 = ( T_6 * ) & V_2 -> V_62 [ V_2 -> V_65 ] ;
V_2 -> V_65 += 2 ;
return * V_68 ;
}
static void F_81 ( struct V_38 * V_39 , T_4 * V_68 , int V_51 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
memcpy ( V_68 , & V_2 -> V_62 [ V_2 -> V_65 ] , V_51 ) ;
V_2 -> V_65 += V_51 ;
}
static int F_82 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
struct V_125 * V_43 = & V_2 -> V_43 ;
if ( V_39 -> V_129 == 512 ) {
V_2 -> V_46 = 0 ;
if ( V_43 -> V_162 > ( 32 << 20 ) ) {
V_2 -> V_47 = V_163 ;
V_2 -> V_111 = V_164 ;
} else if ( V_43 -> V_162 > ( 2 << 16 ) ) {
V_2 -> V_47 = V_164 ;
V_2 -> V_111 = V_165 ;
} else {
V_2 -> V_47 = V_165 ;
V_2 -> V_111 = V_121 ;
}
} else {
V_2 -> V_46 = 1 ;
if ( V_43 -> V_162 > ( 128 << 20 ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_111 = V_164 ;
} else if ( V_43 -> V_162 > ( 8 << 16 ) ) {
V_2 -> V_47 = V_163 ;
V_2 -> V_111 = V_165 ;
} else {
V_2 -> V_47 = V_164 ;
V_2 -> V_111 = V_121 ;
}
}
if ( V_2 -> V_146 ) {
if ( V_39 -> V_129 == 512 ) {
V_43 -> V_166 . V_167 = & V_168 ;
V_43 -> V_169 = & V_170 ;
} else {
V_43 -> V_166 . V_167 = & V_171 ;
V_43 -> V_169 = & V_172 ;
}
V_43 -> V_166 . V_59 = 512 ;
V_43 -> V_166 . V_173 = 10 ;
V_43 -> V_166 . V_174 = 4 ;
V_43 -> V_166 . V_175 = F_62 ;
V_43 -> V_166 . V_176 = F_63 ;
V_43 -> V_166 . V_177 = V_178 ;
V_2 -> V_103 |= V_179 ;
} else {
V_43 -> V_166 . V_177 = V_180 ;
}
return 0 ;
}
static T_7 F_83 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
F_8 ( & V_2 -> V_8 -> V_9 , L_11 , F_29 ( F_3 ( V_2 ) ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
return V_183 ;
}
static struct V_22 * F_84 ( struct V_82 * V_9 )
{
const struct V_184 * V_185 ;
struct V_186 * V_187 ;
struct V_22 * V_23 ;
struct V_188 * V_189 = V_9 -> V_190 ;
int V_25 ;
V_185 = F_85 ( V_191 , V_9 ) ;
if ( V_185 )
V_187 = (struct V_186 * ) V_185 -> V_58 ;
else {
F_8 ( V_9 , L_12 , V_13 ) ;
return NULL ;
}
V_23 = F_86 ( V_9 , sizeof( struct V_22 ) ,
V_192 ) ;
if ( ! V_23 ) {
F_8 ( V_9 , L_13 , V_13 ) ;
return NULL ;
}
V_23 -> V_102 = V_187 -> V_102 ;
V_23 -> V_193 = V_187 -> V_193 ;
V_23 -> V_194 = V_187 -> V_194 ;
V_25 = F_87 ( V_189 ) ;
if ( V_25 == 16 )
V_23 -> V_102 |= V_104 ;
else if ( V_25 != 8 ) {
F_8 ( V_9 , L_14 , V_13 ) ;
return NULL ;
}
return V_23 ;
}
static struct V_22 * F_84 ( struct V_82 * V_9 )
{
return NULL ;
}
static int F_88 ( struct V_21 * V_8 )
{
struct V_195 * V_98 ;
struct V_1 * V_2 ;
struct V_38 * V_196 ;
struct V_125 * V_197 ;
struct V_22 * V_23 ;
int V_25 = - V_198 ;
int V_181 ;
struct V_199 V_200 = {} ;
V_2 = F_89 ( sizeof( struct V_1 ) , V_192 ) ;
if ( ! V_2 ) {
F_8 ( & V_8 -> V_9 , L_15 ) ;
return - V_201 ;
}
V_98 = F_90 ( V_8 , V_202 , 0 ) ;
if ( ! V_98 ) {
F_8 ( & V_8 -> V_9 , L_16 ) ;
goto V_203;
}
V_2 -> V_80 = F_91 ( V_98 -> V_204 , F_92 ( V_98 ) ) ;
if ( V_2 -> V_80 == NULL ) {
F_8 ( & V_8 -> V_9 , L_17 ) ;
goto V_203;
}
V_181 = F_93 ( V_8 , 0 ) ;
if ( V_181 < 0 ) {
F_8 ( & V_8 -> V_9 , L_18 ) ;
goto V_205;
}
V_25 = F_94 ( V_181 , F_83 , V_206 , L_19 , V_2 ) ;
if ( V_25 ) {
F_8 ( & V_8 -> V_9 , L_20 ) ;
goto V_205;
}
if ( V_8 -> V_9 . V_190 )
V_23 = F_84 ( & V_8 -> V_9 ) ;
else
V_23 = V_8 -> V_9 . V_24 ;
if ( ! V_23 ) {
F_8 ( & V_8 -> V_9 , L_21 ) ;
V_25 = - V_79 ;
goto V_207;
}
F_95 ( V_8 , V_2 ) ;
V_196 = & V_2 -> V_39 ;
V_197 = & V_2 -> V_43 ;
V_196 -> V_208 = V_197 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_146 = V_23 -> V_193 ;
V_2 -> V_160 = V_23 -> V_194 ;
V_2 -> V_103 = V_23 -> V_102 ;
V_2 -> V_3 = V_2 -> V_146 ? ( V_209 | V_210 ) : V_209 ;
V_197 -> V_211 = 20 ;
V_197 -> V_212 = F_79 ;
V_197 -> V_132 = F_78 ;
V_197 -> V_128 = F_81 ;
V_197 -> V_213 = F_73 ;
V_197 -> V_214 = F_69 ;
if ( V_23 -> V_102 & V_104 ) {
V_197 -> V_44 |= V_45 ;
V_197 -> V_215 = F_80 ;
}
F_96 ( & V_8 -> V_9 ) ;
F_97 ( & V_8 -> V_9 ) ;
F_16 ( V_2 ) ;
V_25 = F_98 ( V_196 , 1 , NULL ) ;
if ( V_25 )
goto V_216;
V_25 = F_82 ( V_196 ) ;
if ( V_25 )
goto V_216;
V_25 = F_99 ( V_196 ) ;
if ( V_25 )
goto V_216;
V_200 . V_190 = V_8 -> V_9 . V_190 ;
V_25 = F_100 ( V_196 , NULL , & V_200 , V_23 -> V_217 ,
V_23 -> V_218 ) ;
return 0 ;
V_216:
F_14 ( V_2 ) ;
F_101 ( & V_8 -> V_9 ) ;
V_207:
F_102 ( V_181 , V_2 ) ;
V_205:
F_103 ( V_2 -> V_80 ) ;
V_203:
F_104 ( V_2 ) ;
return V_25 ;
}
static int F_105 ( struct V_21 * V_8 )
{
struct V_1 * V_2 = F_106 ( V_8 ) ;
F_14 ( V_2 ) ;
F_107 ( & V_2 -> V_39 ) ;
F_101 ( & V_8 -> V_9 ) ;
F_102 ( F_93 ( V_8 , 0 ) , V_2 ) ;
F_103 ( V_2 -> V_80 ) ;
F_104 ( V_2 ) ;
return 0 ;
}
