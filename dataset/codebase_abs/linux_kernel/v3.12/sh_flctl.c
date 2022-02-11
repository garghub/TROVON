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
struct V_22 * V_23 = F_17 ( & V_8 -> V_9 ) ;
int V_24 ;
if ( ! V_23 )
return;
if ( V_23 -> V_25 <= 0 || V_23 -> V_26 <= 0 )
return;
F_18 ( V_18 ) ;
F_19 ( V_27 , V_18 ) ;
V_2 -> V_17 = F_20 ( V_18 , V_28 ,
( void * ) V_23 -> V_25 ) ;
F_21 ( & V_8 -> V_9 , L_2 , V_13 ,
V_2 -> V_17 ) ;
if ( ! V_2 -> V_17 )
return;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_29 = V_23 -> V_25 ;
V_20 . V_30 = V_31 ;
V_20 . V_32 = ( V_33 ) F_22 ( V_2 ) ;
V_20 . V_34 = 0 ;
V_24 = F_23 ( V_2 -> V_17 , & V_20 ) ;
if ( V_24 < 0 )
goto V_35;
V_2 -> V_16 = F_20 ( V_18 , V_28 ,
( void * ) V_23 -> V_26 ) ;
F_21 ( & V_8 -> V_9 , L_3 , V_13 ,
V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_35;
V_20 . V_29 = V_23 -> V_26 ;
V_20 . V_30 = V_36 ;
V_20 . V_32 = 0 ;
V_20 . V_34 = ( V_33 ) F_22 ( V_2 ) ;
V_24 = F_23 ( V_2 -> V_16 , & V_20 ) ;
if ( V_24 < 0 )
goto V_35;
F_24 ( & V_2 -> V_15 ) ;
return;
V_35:
F_14 ( V_2 ) ;
}
static void F_25 ( struct V_37 * V_38 , int V_39 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_1 V_41 = 0 ;
if ( V_39 == - 1 ) {
V_41 = V_40 ;
} else if ( V_40 != - 1 ) {
if ( V_2 -> V_42 . V_43 & V_44 )
V_39 >>= 1 ;
if ( V_2 -> V_45 ) {
V_41 = V_39 & 0x0FFF ;
V_41 |= ( V_40 & 0xff ) << 16 ;
V_41 |= ( ( V_40 >> 8 ) & 0xff ) << 24 ;
if ( V_2 -> V_46 == V_47 ) {
T_1 V_48 ;
V_48 = ( V_40 >> 16 ) & 0xff ;
F_2 ( V_48 , F_27 ( V_2 ) ) ;
}
} else {
V_41 = V_39 ;
V_41 |= ( V_40 & 0xff ) << 8 ;
V_41 |= ( ( V_40 >> 8 ) & 0xff ) << 16 ;
V_41 |= ( ( V_40 >> 16 ) & 0xff ) << 24 ;
}
}
F_2 ( V_41 , F_28 ( V_2 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
T_1 V_49 ;
V_49 = F_30 ( F_31 ( V_2 ) ) >> 16 ;
if ( V_49 & 0xFF )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_50 , V_10 = V_11 ;
while ( V_10 -- ) {
V_50 = ( F_30 ( F_31 ( V_2 ) ) >> 16 ) & 0xFF ;
if ( V_50 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static enum V_51 F_33
( struct V_1 * V_2 , int V_52 )
{
T_1 V_10 = V_11 ;
void T_3 * V_53 [ 4 ] ;
int V_54 ;
int V_55 = V_56 ;
T_1 V_57 , V_58 ;
while ( V_10 -- ) {
V_58 = F_30 ( F_31 ( V_2 ) ) >> 24 ;
if ( ( V_58 & 0xFF ) == 4 )
return V_55 ;
if ( ! ( F_30 ( F_34 ( V_2 ) ) & V_59 ) ) {
F_11 ( 1 ) ;
continue;
}
if ( F_30 ( F_34 ( V_2 ) ) & V_60 ) {
for ( V_54 = 0 ; V_54 < 512 ; V_54 ++ ) {
if ( V_2 -> V_61 [ V_54 ] != 0xff ) {
V_55 = V_62 ;
break;
}
}
if ( V_55 == V_56 )
F_21 ( & V_2 -> V_8 -> V_9 ,
L_4 ,
V_52 ) ;
F_2 ( 0 , F_34 ( V_2 ) ) ;
continue;
}
V_53 [ 0 ] = F_35 ( V_2 ) ;
V_53 [ 1 ] = F_36 ( V_2 ) ;
V_53 [ 2 ] = F_37 ( V_2 ) ;
V_53 [ 3 ] = F_38 ( V_2 ) ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
T_4 V_63 ;
unsigned int V_64 ;
V_57 = F_30 ( V_53 [ V_54 ] ) ;
if ( V_2 -> V_45 )
V_64 = ( 512 * V_52 ) +
( V_57 >> 16 ) ;
else
V_64 = V_57 >> 16 ;
V_63 = V_2 -> V_61 [ V_64 ] ;
V_2 -> V_61 [ V_64 ] = V_63 ^ ( V_57 & 0xFF ) ;
}
V_55 = V_65 ;
F_2 ( 0 , F_34 ( V_2 ) ) ;
}
F_7 ( V_2 , V_13 ) ;
return V_66 ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
T_1 V_50 ;
while ( V_10 -- ) {
V_50 = ( F_30 ( F_31 ( V_2 ) ) >> 24 ) & 0xFF ;
if ( V_50 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned long * V_67 ,
int V_50 , enum V_68 V_69 )
{
struct V_70 * V_71 = NULL ;
struct V_72 * V_73 ;
enum V_74 V_75 ;
V_33 V_76 ;
T_5 V_77 = - V_78 ;
T_1 V_79 ;
int V_24 ;
if ( V_69 == V_80 ) {
V_73 = V_2 -> V_16 ;
V_75 = V_36 ;
} else {
V_73 = V_2 -> V_17 ;
V_75 = V_31 ;
}
V_76 = F_41 ( V_73 -> V_81 -> V_9 , V_67 , V_50 , V_69 ) ;
if ( V_76 )
V_71 = F_42 ( V_73 , V_76 , V_50 ,
V_75 , V_82 | V_83 ) ;
if ( V_71 ) {
V_79 = F_30 ( F_3 ( V_2 ) ) ;
V_79 |= V_84 ;
F_2 ( V_79 , F_3 ( V_2 ) ) ;
V_71 -> V_85 = F_12 ;
V_71 -> V_86 = V_2 ;
V_77 = F_43 ( V_71 ) ;
F_44 ( V_73 ) ;
} else {
F_14 ( V_2 ) ;
F_45 ( & V_2 -> V_8 -> V_9 ,
L_5 ) ;
V_24 = - V_87 ;
goto V_88;
}
V_24 =
F_46 ( & V_2 -> V_15 ,
F_47 ( 3000 ) ) ;
if ( V_24 <= 0 ) {
V_73 -> V_81 -> V_89 ( V_73 , V_90 , 0 ) ;
F_8 ( & V_2 -> V_8 -> V_9 , L_6 ) ;
}
V_88:
V_79 = F_30 ( F_3 ( V_2 ) ) ;
V_79 &= ~ V_84 ;
F_2 ( V_79 , F_3 ( V_2 ) ) ;
F_48 ( V_73 -> V_81 -> V_9 , V_76 , V_50 , V_69 ) ;
return V_24 ;
}
static void F_49 ( struct V_1 * V_2 , int V_91 )
{
unsigned long V_57 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_91 ] ;
F_9 ( V_2 ) ;
V_57 = F_30 ( F_50 ( V_2 ) ) ;
* V_67 = F_51 ( V_57 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_92 , int V_91 )
{
int V_54 , V_93 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_91 ] ;
V_93 = ( V_92 + 3 ) / 4 ;
if ( V_2 -> V_16 && V_92 >= 32 &&
F_40 ( V_2 , V_67 , V_92 , V_36 ) > 0 )
goto V_94;
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ ) {
F_29 ( V_2 ) ;
V_67 [ V_54 ] = F_30 ( F_22 ( V_2 ) ) ;
}
V_94:
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ )
V_67 [ V_54 ] = F_53 ( V_67 [ V_54 ] ) ;
}
static enum V_51 F_54
( struct V_1 * V_2 , T_4 * V_95 , int V_96 )
{
int V_54 ;
enum V_51 V_97 ;
unsigned long * V_98 = ( unsigned long * ) V_95 ;
V_97 = F_33 ( V_2 , V_96 ) ;
if ( V_97 != V_62 ) {
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_98 [ V_54 ] = F_30 ( F_55 ( V_2 ) ) ;
V_98 [ V_54 ] = F_53 ( V_98 [ V_54 ] ) ;
}
}
return V_97 ;
}
static void F_56 ( struct V_1 * V_2 , int V_92 ,
unsigned int V_91 )
{
int V_54 , V_93 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_91 ] ;
V_93 = ( V_92 + 3 ) / 4 ;
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ ) {
F_32 ( V_2 ) ;
F_2 ( F_57 ( V_67 [ V_54 ] ) , F_22 ( V_2 ) ) ;
}
}
static void F_58 ( struct V_1 * V_2 , int V_92 ,
unsigned int V_91 )
{
int V_54 , V_93 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_91 ] ;
V_93 = ( V_92 + 3 ) / 4 ;
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ )
V_67 [ V_54 ] = F_57 ( V_67 [ V_54 ] ) ;
if ( V_2 -> V_17 && V_92 >= 32 &&
F_40 ( V_2 , V_67 , V_92 , V_31 ) > 0 )
return;
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ ) {
F_39 ( V_2 ) ;
F_2 ( V_67 [ V_54 ] , F_55 ( V_2 ) ) ;
}
}
static void F_59 ( struct V_37 * V_38 , T_1 V_99 , T_1 V_100 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_1 V_101 = V_2 -> V_102 & ~ V_103 ;
T_1 V_104 , V_105 = 0 ;
if ( V_2 -> V_45 )
V_101 |= V_106 ;
else
V_101 &= ~ V_106 ;
V_104 = V_107 | V_108 ;
switch ( V_99 ) {
case V_109 :
V_105 = V_2 -> V_110 ;
V_104 |= V_111 ;
break;
case V_112 :
case V_113 :
case V_114 :
V_105 = V_2 -> V_46 ;
V_104 |= V_115 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_101 |= V_103 ;
break;
case V_116 :
V_104 &= ~ V_108 ;
break;
case V_117 :
V_105 = V_2 -> V_46 ;
V_104 |= V_111 | V_115 | V_118 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_101 |= V_103 ;
break;
case V_119 :
V_101 &= ~ V_106 ;
V_104 |= V_115 ;
V_105 = V_120 ;
break;
case V_121 :
case V_122 :
V_101 &= ~ V_106 ;
V_104 &= ~ ( V_108 | V_123 ) ;
break;
default:
break;
}
V_104 |= V_105 ;
F_2 ( V_101 , F_60 ( V_2 ) ) ;
F_2 ( V_104 , F_61 ( V_2 ) ) ;
F_2 ( V_100 , F_62 ( V_2 ) ) ;
}
static int F_63 ( struct V_37 * V_38 , struct V_124 * V_42 ,
T_4 * V_67 , int V_125 , int V_126 )
{
V_42 -> V_127 ( V_38 , V_67 , V_38 -> V_128 ) ;
if ( V_125 )
V_42 -> V_127 ( V_38 , V_42 -> V_129 , V_38 -> V_130 ) ;
return 0 ;
}
static int F_64 ( struct V_37 * V_38 , struct V_124 * V_42 ,
const T_4 * V_67 , int V_125 )
{
V_42 -> V_131 ( V_38 , V_67 , V_38 -> V_128 ) ;
V_42 -> V_131 ( V_38 , V_42 -> V_129 , V_38 -> V_130 ) ;
return 0 ;
}
static void F_65 ( struct V_37 * V_38 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_96 , V_132 ;
enum V_51 V_133 ;
V_132 = V_2 -> V_45 ? 4 : 1 ;
F_59 ( V_38 , V_112 ,
( V_134 << 8 ) | V_112 ) ;
F_2 ( F_30 ( F_60 ( V_2 ) ) | V_135 | V_136 ,
F_60 ( V_2 ) ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_132 , F_61 ( V_2 ) ) ;
F_2 ( V_40 << 2 , F_28 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_96 = 0 ; V_96 < V_132 ; V_96 ++ ) {
F_52 ( V_2 , 512 , 512 * V_96 ) ;
V_133 = F_54 ( V_2 ,
& V_2 -> V_61 [ V_38 -> V_128 + 16 * V_96 ] ,
V_96 ) ;
switch ( V_133 ) {
case V_65 :
F_66 ( & V_2 -> V_8 -> V_9 ,
L_7 , V_40 ) ;
V_2 -> V_38 . V_137 . V_138 ++ ;
break;
case V_62 :
F_45 ( & V_2 -> V_8 -> V_9 ,
L_8 ,
V_40 ) ;
V_2 -> V_38 . V_137 . V_139 ++ ;
break;
default:
;
}
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_60 ( V_2 ) ) & ~ ( V_135 | V_136 ) ,
F_60 ( V_2 ) ) ;
}
static void F_67 ( struct V_37 * V_38 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_132 = V_2 -> V_45 ? 4 : 1 ;
int V_54 ;
F_59 ( V_38 , V_112 ,
( V_134 << 8 ) | V_112 ) ;
F_1 ( V_2 ) ;
for ( V_54 = 0 ; V_54 < V_132 ; V_54 ++ ) {
F_25 ( V_38 , ( 512 + 16 ) * V_54 + 512 , V_40 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_52 ( V_2 , 16 , 16 * V_54 ) ;
F_9 ( V_2 ) ;
}
}
static void F_68 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_40 = V_2 -> V_140 ;
int V_96 , V_132 ;
V_132 = V_2 -> V_45 ? 4 : 1 ;
F_59 ( V_38 , V_117 ,
( V_117 << 8 ) | V_116 ) ;
F_1 ( V_2 ) ;
F_2 ( F_30 ( F_60 ( V_2 ) ) | V_135 , F_60 ( V_2 ) ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_132 , F_61 ( V_2 ) ) ;
F_2 ( V_40 << 2 , F_28 ( V_2 ) ) ;
F_4 ( V_2 ) ;
for ( V_96 = 0 ; V_96 < V_132 ; V_96 ++ ) {
F_56 ( V_2 , 512 , 512 * V_96 ) ;
F_58 ( V_2 , 16 , V_38 -> V_128 + 16 * V_96 ) ;
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_60 ( V_2 ) ) & ~ V_135 , F_60 ( V_2 ) ) ;
}
static void F_69 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_40 = V_2 -> V_140 ;
int V_96 , V_132 ;
V_132 = V_2 -> V_45 ? 4 : 1 ;
F_59 ( V_38 , V_117 ,
( V_117 << 8 ) | V_116 ) ;
for ( V_96 = 0 ; V_96 < V_132 ; V_96 ++ ) {
F_1 ( V_2 ) ;
F_25 ( V_38 , V_96 * 528 + 512 , V_40 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_56 ( V_2 , 16 , 16 * V_96 ) ;
F_9 ( V_2 ) ;
}
}
static void F_70 ( struct V_37 * V_38 , unsigned int V_141 ,
int V_39 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_1 V_142 = 0 ;
F_71 ( & V_2 -> V_8 -> V_9 ) ;
V_2 -> V_143 = 0 ;
if ( V_141 != V_117 )
V_2 -> V_64 = 0 ;
switch ( V_141 ) {
case V_144 :
case V_112 :
if ( V_2 -> V_145 ) {
F_65 ( V_38 , V_40 ) ;
break;
}
if ( V_2 -> V_45 )
F_59 ( V_38 , V_141 , ( V_134 << 8 )
| V_141 ) ;
else
F_59 ( V_38 , V_141 , V_141 ) ;
F_25 ( V_38 , 0 , V_40 ) ;
V_2 -> V_143 = V_38 -> V_128 + V_38 -> V_130 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_39 >>= 1 ;
V_2 -> V_64 += V_39 ;
goto V_146;
case V_113 :
if ( V_2 -> V_145 ) {
F_67 ( V_38 , V_40 ) ;
break;
}
if ( V_2 -> V_45 ) {
F_59 ( V_38 , V_141 , ( V_134 << 8 )
| V_112 ) ;
F_25 ( V_38 , V_38 -> V_128 , V_40 ) ;
} else {
F_59 ( V_38 , V_141 , V_141 ) ;
F_25 ( V_38 , 0 , V_40 ) ;
}
V_2 -> V_143 = V_38 -> V_130 ;
goto V_146;
case V_114 :
if ( V_2 -> V_145 )
break;
if ( V_2 -> V_45 )
F_59 ( V_38 , V_141 , ( V_147 << 8 )
| V_141 ) ;
else
F_59 ( V_38 , V_141 , V_141 ) ;
F_25 ( V_38 , V_39 , 0 ) ;
V_2 -> V_143 = V_38 -> V_128 + V_38 -> V_130 - V_39 ;
goto V_146;
case V_119 :
F_59 ( V_38 , V_141 , V_141 ) ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_39 <<= 1 ;
F_25 ( V_38 , V_39 , 0 ) ;
V_2 -> V_143 = 8 ;
F_2 ( V_2 -> V_143 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_52 ( V_2 , V_2 -> V_143 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_109 :
V_2 -> V_148 = V_40 ;
break;
case V_149 :
F_59 ( V_38 , V_109 ,
( V_141 << 8 ) | V_109 ) ;
F_25 ( V_38 , - 1 , V_2 -> V_148 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_116 :
if ( ! V_2 -> V_45 ) {
if ( V_39 >= V_38 -> V_128 ) {
V_39 -= V_38 -> V_128 ;
V_142 = V_113 ;
} else if ( V_39 < 256 ) {
V_142 = V_112 ;
} else {
V_39 -= 256 ;
V_142 = V_144 ;
}
}
V_2 -> V_150 = V_39 ;
V_2 -> V_140 = V_40 ;
V_2 -> V_151 = V_142 ;
break;
case V_117 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_45 ) {
F_59 ( V_38 , V_116 ,
V_2 -> V_151 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_145 ) {
if ( V_2 -> V_150 == V_38 -> V_128 )
F_69 ( V_38 ) ;
else if ( ! V_2 -> V_150 )
F_68 ( V_38 ) ;
else
F_72 ( V_152 L_9 ) ;
break;
}
F_59 ( V_38 , V_141 , ( V_141 << 8 ) | V_116 ) ;
F_25 ( V_38 , V_2 -> V_150 , V_2 -> V_140 ) ;
F_2 ( V_2 -> V_64 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_56 ( V_2 , V_2 -> V_64 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_121 :
F_59 ( V_38 , V_141 , V_141 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
V_2 -> V_143 = 1 ;
F_2 ( V_2 -> V_143 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_49 ( V_2 , 0 ) ;
break;
case V_122 :
F_59 ( V_38 , V_141 , V_141 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_153;
V_146:
F_2 ( V_2 -> V_143 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_52 ( V_2 , V_2 -> V_143 , 0 ) ;
F_9 ( V_2 ) ;
V_153:
F_73 ( & V_2 -> V_8 -> V_9 ) ;
return;
}
static void F_74 ( struct V_37 * V_38 , int V_154 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_24 ;
switch ( V_154 ) {
case - 1 :
V_2 -> V_102 &= ~ V_155 ;
F_71 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_2 -> V_102 , F_60 ( V_2 ) ) ;
if ( V_2 -> V_156 ) {
F_75 ( & V_2 -> V_157 ) ;
V_2 -> V_156 = 0 ;
}
F_73 ( & V_2 -> V_8 -> V_9 ) ;
break;
case 0 :
V_2 -> V_102 |= V_155 ;
if ( ! V_2 -> V_156 ) {
V_24 = F_76 ( & V_2 -> V_8 -> V_9 ,
& V_2 -> V_157 ,
V_158 ,
100 ) ;
if ( V_24 < 0 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_10 , V_24 ) ;
V_2 -> V_156 = 1 ;
}
if ( V_2 -> V_159 ) {
F_71 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_160 , F_77 ( V_2 ) ) ;
F_73 ( & V_2 -> V_8 -> V_9 ) ;
}
break;
default:
F_78 () ;
}
}
static void F_79 ( struct V_37 * V_38 , const T_4 * V_67 , int V_50 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
memcpy ( & V_2 -> V_61 [ V_2 -> V_64 ] , V_67 , V_50 ) ;
V_2 -> V_64 += V_50 ;
}
static T_4 F_80 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_4 V_57 ;
V_57 = V_2 -> V_61 [ V_2 -> V_64 ] ;
V_2 -> V_64 ++ ;
return V_57 ;
}
static T_6 F_81 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_6 * V_67 = ( T_6 * ) & V_2 -> V_61 [ V_2 -> V_64 ] ;
V_2 -> V_64 += 2 ;
return * V_67 ;
}
static void F_82 ( struct V_37 * V_38 , T_4 * V_67 , int V_50 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
memcpy ( V_67 , & V_2 -> V_61 [ V_2 -> V_64 ] , V_50 ) ;
V_2 -> V_64 += V_50 ;
}
static int F_83 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
struct V_124 * V_42 = & V_2 -> V_42 ;
if ( V_38 -> V_128 == 512 ) {
V_2 -> V_45 = 0 ;
if ( V_42 -> V_161 > ( 32 << 20 ) ) {
V_2 -> V_46 = V_162 ;
V_2 -> V_110 = V_163 ;
} else if ( V_42 -> V_161 > ( 2 << 16 ) ) {
V_2 -> V_46 = V_163 ;
V_2 -> V_110 = V_164 ;
} else {
V_2 -> V_46 = V_164 ;
V_2 -> V_110 = V_120 ;
}
} else {
V_2 -> V_45 = 1 ;
if ( V_42 -> V_161 > ( 128 << 20 ) ) {
V_2 -> V_46 = V_47 ;
V_2 -> V_110 = V_163 ;
} else if ( V_42 -> V_161 > ( 8 << 16 ) ) {
V_2 -> V_46 = V_162 ;
V_2 -> V_110 = V_164 ;
} else {
V_2 -> V_46 = V_163 ;
V_2 -> V_110 = V_120 ;
}
}
if ( V_2 -> V_145 ) {
if ( V_38 -> V_128 == 512 ) {
V_42 -> V_165 . V_166 = & V_167 ;
V_42 -> V_168 = & V_169 ;
} else {
V_42 -> V_165 . V_166 = & V_170 ;
V_42 -> V_168 = & V_171 ;
}
V_42 -> V_165 . V_58 = 512 ;
V_42 -> V_165 . V_172 = 10 ;
V_42 -> V_165 . V_173 = 4 ;
V_42 -> V_165 . V_174 = F_63 ;
V_42 -> V_165 . V_175 = F_64 ;
V_42 -> V_165 . V_176 = V_177 ;
V_2 -> V_102 |= V_178 ;
} else {
V_42 -> V_165 . V_176 = V_179 ;
}
return 0 ;
}
static T_7 F_84 ( int V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
F_8 ( & V_2 -> V_8 -> V_9 , L_11 , F_30 ( F_3 ( V_2 ) ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
return V_182 ;
}
static struct V_22 * F_85 ( struct V_81 * V_9 )
{
const struct V_183 * V_184 ;
struct V_185 * V_186 ;
struct V_22 * V_23 ;
struct V_187 * V_188 = V_9 -> V_189 ;
int V_24 ;
V_184 = F_86 ( V_190 , V_9 ) ;
if ( V_184 )
V_186 = (struct V_185 * ) V_184 -> V_57 ;
else {
F_8 ( V_9 , L_12 , V_13 ) ;
return NULL ;
}
V_23 = F_87 ( V_9 , sizeof( struct V_22 ) ,
V_191 ) ;
if ( ! V_23 ) {
F_8 ( V_9 , L_13 , V_13 ) ;
return NULL ;
}
V_23 -> V_101 = V_186 -> V_101 ;
V_23 -> V_192 = V_186 -> V_192 ;
V_23 -> V_193 = V_186 -> V_193 ;
V_24 = F_88 ( V_188 ) ;
if ( V_24 == 16 )
V_23 -> V_101 |= V_103 ;
else if ( V_24 != 8 ) {
F_8 ( V_9 , L_14 , V_13 ) ;
return NULL ;
}
return V_23 ;
}
static struct V_22 * F_85 ( struct V_81 * V_9 )
{
return NULL ;
}
static int F_89 ( struct V_21 * V_8 )
{
struct V_194 * V_97 ;
struct V_1 * V_2 ;
struct V_37 * V_195 ;
struct V_124 * V_196 ;
struct V_22 * V_23 ;
int V_24 = - V_197 ;
int V_180 ;
struct V_198 V_199 = {} ;
V_2 = F_90 ( sizeof( struct V_1 ) , V_191 ) ;
if ( ! V_2 ) {
F_8 ( & V_8 -> V_9 , L_15 ) ;
return - V_200 ;
}
V_97 = F_91 ( V_8 , V_201 , 0 ) ;
if ( ! V_97 ) {
F_8 ( & V_8 -> V_9 , L_16 ) ;
goto V_202;
}
V_2 -> V_79 = F_92 ( V_97 -> V_203 , F_93 ( V_97 ) ) ;
if ( V_2 -> V_79 == NULL ) {
F_8 ( & V_8 -> V_9 , L_17 ) ;
goto V_202;
}
V_180 = F_94 ( V_8 , 0 ) ;
if ( V_180 < 0 ) {
F_8 ( & V_8 -> V_9 , L_18 ) ;
goto V_204;
}
V_24 = F_95 ( V_180 , F_84 , V_205 , L_19 , V_2 ) ;
if ( V_24 ) {
F_8 ( & V_8 -> V_9 , L_20 ) ;
goto V_204;
}
if ( V_8 -> V_9 . V_189 )
V_23 = F_85 ( & V_8 -> V_9 ) ;
else
V_23 = F_17 ( & V_8 -> V_9 ) ;
if ( ! V_23 ) {
F_8 ( & V_8 -> V_9 , L_21 ) ;
V_24 = - V_78 ;
goto V_206;
}
F_96 ( V_8 , V_2 ) ;
V_195 = & V_2 -> V_38 ;
V_196 = & V_2 -> V_42 ;
V_195 -> V_207 = V_196 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_145 = V_23 -> V_192 ;
V_2 -> V_159 = V_23 -> V_193 ;
V_2 -> V_102 = V_23 -> V_101 ;
V_2 -> V_3 = V_2 -> V_145 ? ( V_208 | V_209 ) : V_208 ;
V_196 -> V_210 = 20 ;
V_196 -> V_211 = F_80 ;
V_196 -> V_131 = F_79 ;
V_196 -> V_127 = F_82 ;
V_196 -> V_212 = F_74 ;
V_196 -> V_213 = F_70 ;
if ( V_23 -> V_101 & V_103 ) {
V_196 -> V_43 |= V_44 ;
V_196 -> V_214 = F_81 ;
}
F_97 ( & V_8 -> V_9 ) ;
F_98 ( & V_8 -> V_9 ) ;
F_16 ( V_2 ) ;
V_24 = F_99 ( V_195 , 1 , NULL ) ;
if ( V_24 )
goto V_215;
V_24 = F_83 ( V_195 ) ;
if ( V_24 )
goto V_215;
V_24 = F_100 ( V_195 ) ;
if ( V_24 )
goto V_215;
V_199 . V_189 = V_8 -> V_9 . V_189 ;
V_24 = F_101 ( V_195 , NULL , & V_199 , V_23 -> V_216 ,
V_23 -> V_217 ) ;
return 0 ;
V_215:
F_14 ( V_2 ) ;
F_102 ( & V_8 -> V_9 ) ;
V_206:
F_103 ( V_180 , V_2 ) ;
V_204:
F_104 ( V_2 -> V_79 ) ;
V_202:
F_105 ( V_2 ) ;
return V_24 ;
}
static int F_106 ( struct V_21 * V_8 )
{
struct V_1 * V_2 = F_107 ( V_8 ) ;
F_14 ( V_2 ) ;
F_108 ( & V_2 -> V_38 ) ;
F_102 ( & V_8 -> V_9 ) ;
F_103 ( F_94 ( V_8 , 0 ) , V_2 ) ;
F_104 ( V_2 -> V_79 ) ;
F_105 ( V_2 ) ;
return 0 ;
}
