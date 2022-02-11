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
( void * ) ( V_29 ) V_23 -> V_25 ) ;
F_21 ( & V_8 -> V_9 , L_2 , V_13 ,
V_2 -> V_17 ) ;
if ( ! V_2 -> V_17 )
return;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_30 = V_31 ;
V_20 . V_32 = ( V_33 ) F_22 ( V_2 ) ;
V_20 . V_34 = 0 ;
V_24 = F_23 ( V_2 -> V_17 , & V_20 ) ;
if ( V_24 < 0 )
goto V_35;
V_2 -> V_16 = F_20 ( V_18 , V_28 ,
( void * ) ( V_29 ) V_23 -> V_26 ) ;
F_21 ( & V_8 -> V_9 , L_3 , V_13 ,
V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_35;
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
F_48 ( V_73 ) ;
F_8 ( & V_2 -> V_8 -> V_9 , L_6 ) ;
}
V_88:
V_79 = F_30 ( F_3 ( V_2 ) ) ;
V_79 &= ~ V_84 ;
F_2 ( V_79 , F_3 ( V_2 ) ) ;
F_49 ( V_73 -> V_81 -> V_9 , V_76 , V_50 , V_69 ) ;
return V_24 ;
}
static void F_50 ( struct V_1 * V_2 , int V_89 )
{
unsigned long V_57 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_89 ] ;
F_9 ( V_2 ) ;
V_57 = F_30 ( F_51 ( V_2 ) ) ;
* V_67 = F_52 ( V_57 ) ;
}
static void F_53 ( struct V_1 * V_2 , int V_90 , int V_89 )
{
int V_54 , V_91 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_89 ] ;
V_91 = ( V_90 + 3 ) / 4 ;
if ( V_2 -> V_16 && V_90 >= 32 &&
F_40 ( V_2 , V_67 , V_90 , V_36 ) > 0 )
goto V_92;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
F_29 ( V_2 ) ;
V_67 [ V_54 ] = F_30 ( F_22 ( V_2 ) ) ;
}
V_92:
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ )
V_67 [ V_54 ] = F_54 ( V_67 [ V_54 ] ) ;
}
static enum V_51 F_55
( struct V_1 * V_2 , T_4 * V_93 , int V_94 )
{
int V_54 ;
enum V_51 V_95 ;
unsigned long * V_96 = ( unsigned long * ) V_93 ;
V_95 = F_33 ( V_2 , V_94 ) ;
if ( V_95 != V_62 ) {
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_96 [ V_54 ] = F_30 ( F_56 ( V_2 ) ) ;
V_96 [ V_54 ] = F_54 ( V_96 [ V_54 ] ) ;
}
}
return V_95 ;
}
static void F_57 ( struct V_1 * V_2 , int V_90 ,
unsigned int V_89 )
{
int V_54 , V_91 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_89 ] ;
V_91 = ( V_90 + 3 ) / 4 ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
F_32 ( V_2 ) ;
F_2 ( F_58 ( V_67 [ V_54 ] ) , F_22 ( V_2 ) ) ;
}
}
static void F_59 ( struct V_1 * V_2 , int V_90 ,
unsigned int V_89 )
{
int V_54 , V_91 ;
unsigned long * V_67 = ( unsigned long * ) & V_2 -> V_61 [ V_89 ] ;
V_91 = ( V_90 + 3 ) / 4 ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ )
V_67 [ V_54 ] = F_58 ( V_67 [ V_54 ] ) ;
if ( V_2 -> V_17 && V_90 >= 32 &&
F_40 ( V_2 , V_67 , V_90 , V_31 ) > 0 )
return;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
F_39 ( V_2 ) ;
F_2 ( V_67 [ V_54 ] , F_56 ( V_2 ) ) ;
}
}
static void F_60 ( struct V_37 * V_38 , T_1 V_97 , T_1 V_98 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_1 V_99 = V_2 -> V_100 & ~ V_101 ;
T_1 V_102 , V_103 = 0 ;
if ( V_2 -> V_45 )
V_99 |= V_104 ;
else
V_99 &= ~ V_104 ;
V_102 = V_105 | V_106 ;
switch ( V_97 ) {
case V_107 :
V_103 = V_2 -> V_108 ;
V_102 |= V_109 ;
break;
case V_110 :
case V_111 :
case V_112 :
V_103 = V_2 -> V_46 ;
V_102 |= V_113 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_99 |= V_101 ;
break;
case V_114 :
V_102 &= ~ V_106 ;
break;
case V_115 :
V_103 = V_2 -> V_46 ;
V_102 |= V_109 | V_113 | V_116 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_99 |= V_101 ;
break;
case V_117 :
V_99 &= ~ V_104 ;
V_102 |= V_113 ;
V_103 = V_118 ;
break;
case V_119 :
case V_120 :
V_99 &= ~ V_104 ;
V_102 &= ~ ( V_106 | V_121 ) ;
break;
default:
break;
}
V_102 |= V_103 ;
F_2 ( V_99 , F_61 ( V_2 ) ) ;
F_2 ( V_102 , F_62 ( V_2 ) ) ;
F_2 ( V_98 , F_63 ( V_2 ) ) ;
}
static int F_64 ( struct V_37 * V_38 , struct V_122 * V_42 ,
T_4 * V_67 , int V_123 , int V_124 )
{
V_42 -> V_125 ( V_38 , V_67 , V_38 -> V_126 ) ;
if ( V_123 )
V_42 -> V_125 ( V_38 , V_42 -> V_127 , V_38 -> V_128 ) ;
return 0 ;
}
static int F_65 ( struct V_37 * V_38 , struct V_122 * V_42 ,
const T_4 * V_67 , int V_123 ,
int V_124 )
{
V_42 -> V_129 ( V_38 , V_67 , V_38 -> V_126 ) ;
V_42 -> V_129 ( V_38 , V_42 -> V_127 , V_38 -> V_128 ) ;
return 0 ;
}
static void F_66 ( struct V_37 * V_38 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_94 , V_130 ;
enum V_51 V_131 ;
V_130 = V_2 -> V_45 ? 4 : 1 ;
F_60 ( V_38 , V_110 ,
( V_132 << 8 ) | V_110 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_133 | V_134 ,
F_61 ( V_2 ) ) ;
F_2 ( F_30 ( F_62 ( V_2 ) ) | V_130 , F_62 ( V_2 ) ) ;
F_2 ( V_40 << 2 , F_28 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_94 = 0 ; V_94 < V_130 ; V_94 ++ ) {
F_53 ( V_2 , 512 , 512 * V_94 ) ;
V_131 = F_55 ( V_2 ,
& V_2 -> V_61 [ V_38 -> V_126 + 16 * V_94 ] ,
V_94 ) ;
switch ( V_131 ) {
case V_65 :
F_67 ( & V_2 -> V_8 -> V_9 ,
L_7 , V_40 ) ;
V_2 -> V_38 . V_135 . V_136 ++ ;
break;
case V_62 :
F_45 ( & V_2 -> V_8 -> V_9 ,
L_8 ,
V_40 ) ;
V_2 -> V_38 . V_135 . V_137 ++ ;
break;
default:
;
}
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) & ~ ( V_133 | V_134 ) ,
F_61 ( V_2 ) ) ;
}
static void F_68 ( struct V_37 * V_38 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_130 = V_2 -> V_45 ? 4 : 1 ;
int V_54 ;
F_60 ( V_38 , V_110 ,
( V_132 << 8 ) | V_110 ) ;
F_1 ( V_2 ) ;
for ( V_54 = 0 ; V_54 < V_130 ; V_54 ++ ) {
F_25 ( V_38 , ( 512 + 16 ) * V_54 + 512 , V_40 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , 16 , 16 * V_54 ) ;
F_9 ( V_2 ) ;
}
}
static void F_69 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_40 = V_2 -> V_138 ;
int V_94 , V_130 ;
V_130 = V_2 -> V_45 ? 4 : 1 ;
F_60 ( V_38 , V_115 ,
( V_115 << 8 ) | V_114 ) ;
F_1 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_133 , F_61 ( V_2 ) ) ;
F_2 ( F_30 ( F_62 ( V_2 ) ) | V_130 , F_62 ( V_2 ) ) ;
F_2 ( V_40 << 2 , F_28 ( V_2 ) ) ;
F_4 ( V_2 ) ;
for ( V_94 = 0 ; V_94 < V_130 ; V_94 ++ ) {
F_57 ( V_2 , 512 , 512 * V_94 ) ;
F_59 ( V_2 , 16 , V_38 -> V_126 + 16 * V_94 ) ;
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) & ~ V_133 , F_61 ( V_2 ) ) ;
}
static void F_70 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_40 = V_2 -> V_138 ;
int V_94 , V_130 ;
V_130 = V_2 -> V_45 ? 4 : 1 ;
F_60 ( V_38 , V_115 ,
( V_115 << 8 ) | V_114 ) ;
for ( V_94 = 0 ; V_94 < V_130 ; V_94 ++ ) {
F_1 ( V_2 ) ;
F_25 ( V_38 , V_94 * 528 + 512 , V_40 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_57 ( V_2 , 16 , 16 * V_94 ) ;
F_9 ( V_2 ) ;
}
}
static void F_71 ( struct V_37 * V_38 , unsigned int V_139 ,
int V_39 , int V_40 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_1 V_140 = 0 ;
F_72 ( & V_2 -> V_8 -> V_9 ) ;
V_2 -> V_141 = 0 ;
if ( V_139 != V_115 )
V_2 -> V_64 = 0 ;
switch ( V_139 ) {
case V_142 :
case V_110 :
if ( V_2 -> V_143 ) {
F_66 ( V_38 , V_40 ) ;
break;
}
if ( V_2 -> V_45 )
F_60 ( V_38 , V_139 , ( V_132 << 8 )
| V_139 ) ;
else
F_60 ( V_38 , V_139 , V_139 ) ;
F_25 ( V_38 , 0 , V_40 ) ;
V_2 -> V_141 = V_38 -> V_126 + V_38 -> V_128 ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_39 >>= 1 ;
V_2 -> V_64 += V_39 ;
goto V_144;
case V_111 :
if ( V_2 -> V_143 ) {
F_68 ( V_38 , V_40 ) ;
break;
}
if ( V_2 -> V_45 ) {
F_60 ( V_38 , V_139 , ( V_132 << 8 )
| V_110 ) ;
F_25 ( V_38 , V_38 -> V_126 , V_40 ) ;
} else {
F_60 ( V_38 , V_139 , V_139 ) ;
F_25 ( V_38 , 0 , V_40 ) ;
}
V_2 -> V_141 = V_38 -> V_128 ;
goto V_144;
case V_112 :
if ( V_2 -> V_143 )
break;
if ( V_2 -> V_45 )
F_60 ( V_38 , V_139 , ( V_145 << 8 )
| V_139 ) ;
else
F_60 ( V_38 , V_139 , V_139 ) ;
F_25 ( V_38 , V_39 , 0 ) ;
V_2 -> V_141 = V_38 -> V_126 + V_38 -> V_128 - V_39 ;
goto V_144;
case V_117 :
F_60 ( V_38 , V_139 , V_139 ) ;
if ( V_2 -> V_42 . V_43 & V_44 )
V_39 <<= 1 ;
F_25 ( V_38 , V_39 , 0 ) ;
V_2 -> V_141 = 8 ;
F_2 ( V_2 -> V_141 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , V_2 -> V_141 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_107 :
V_2 -> V_146 = V_40 ;
break;
case V_147 :
F_60 ( V_38 , V_107 ,
( V_139 << 8 ) | V_107 ) ;
F_25 ( V_38 , - 1 , V_2 -> V_146 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_114 :
if ( ! V_2 -> V_45 ) {
if ( V_39 >= V_38 -> V_126 ) {
V_39 -= V_38 -> V_126 ;
V_140 = V_111 ;
} else if ( V_39 < 256 ) {
V_140 = V_110 ;
} else {
V_39 -= 256 ;
V_140 = V_142 ;
}
}
V_2 -> V_148 = V_39 ;
V_2 -> V_138 = V_40 ;
V_2 -> V_149 = V_140 ;
break;
case V_115 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_45 ) {
F_60 ( V_38 , V_114 ,
V_2 -> V_149 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_143 ) {
if ( V_2 -> V_148 == V_38 -> V_126 )
F_70 ( V_38 ) ;
else if ( ! V_2 -> V_148 )
F_69 ( V_38 ) ;
else
F_73 ( V_150 L_9 ) ;
break;
}
F_60 ( V_38 , V_139 , ( V_139 << 8 ) | V_114 ) ;
F_25 ( V_38 , V_2 -> V_148 , V_2 -> V_138 ) ;
F_2 ( V_2 -> V_64 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_57 ( V_2 , V_2 -> V_64 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_119 :
F_60 ( V_38 , V_139 , V_139 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
V_2 -> V_141 = 1 ;
F_2 ( V_2 -> V_141 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_50 ( V_2 , 0 ) ;
break;
case V_120 :
F_60 ( V_38 , V_139 , V_139 ) ;
F_25 ( V_38 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_151;
V_144:
F_2 ( V_2 -> V_141 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , V_2 -> V_141 , 0 ) ;
F_9 ( V_2 ) ;
V_151:
F_74 ( & V_2 -> V_8 -> V_9 ) ;
return;
}
static void F_75 ( struct V_37 * V_38 , int V_152 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
int V_24 ;
switch ( V_152 ) {
case - 1 :
V_2 -> V_100 &= ~ V_153 ;
F_72 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_2 -> V_100 , F_61 ( V_2 ) ) ;
if ( V_2 -> V_154 ) {
F_76 ( & V_2 -> V_155 ) ;
V_2 -> V_154 = 0 ;
}
F_74 ( & V_2 -> V_8 -> V_9 ) ;
break;
case 0 :
V_2 -> V_100 |= V_153 ;
if ( ! V_2 -> V_154 ) {
V_24 = F_77 ( & V_2 -> V_8 -> V_9 ,
& V_2 -> V_155 ,
V_156 ,
100 ) ;
if ( V_24 < 0 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_10 , V_24 ) ;
V_2 -> V_154 = 1 ;
}
if ( V_2 -> V_157 ) {
F_72 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_158 , F_78 ( V_2 ) ) ;
F_74 ( & V_2 -> V_8 -> V_9 ) ;
}
break;
default:
F_79 () ;
}
}
static void F_80 ( struct V_37 * V_38 , const T_4 * V_67 , int V_50 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
memcpy ( & V_2 -> V_61 [ V_2 -> V_64 ] , V_67 , V_50 ) ;
V_2 -> V_64 += V_50 ;
}
static T_4 F_81 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_4 V_57 ;
V_57 = V_2 -> V_61 [ V_2 -> V_64 ] ;
V_2 -> V_64 ++ ;
return V_57 ;
}
static T_6 F_82 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
T_6 * V_67 = ( T_6 * ) & V_2 -> V_61 [ V_2 -> V_64 ] ;
V_2 -> V_64 += 2 ;
return * V_67 ;
}
static void F_83 ( struct V_37 * V_38 , T_4 * V_67 , int V_50 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
memcpy ( V_67 , & V_2 -> V_61 [ V_2 -> V_64 ] , V_50 ) ;
V_2 -> V_64 += V_50 ;
}
static int F_84 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_26 ( V_38 ) ;
struct V_122 * V_42 = & V_2 -> V_42 ;
if ( V_38 -> V_126 == 512 ) {
V_2 -> V_45 = 0 ;
if ( V_42 -> V_159 > ( 32 << 20 ) ) {
V_2 -> V_46 = V_160 ;
V_2 -> V_108 = V_161 ;
} else if ( V_42 -> V_159 > ( 2 << 16 ) ) {
V_2 -> V_46 = V_161 ;
V_2 -> V_108 = V_162 ;
} else {
V_2 -> V_46 = V_162 ;
V_2 -> V_108 = V_118 ;
}
} else {
V_2 -> V_45 = 1 ;
if ( V_42 -> V_159 > ( 128 << 20 ) ) {
V_2 -> V_46 = V_47 ;
V_2 -> V_108 = V_161 ;
} else if ( V_42 -> V_159 > ( 8 << 16 ) ) {
V_2 -> V_46 = V_160 ;
V_2 -> V_108 = V_162 ;
} else {
V_2 -> V_46 = V_161 ;
V_2 -> V_108 = V_118 ;
}
}
if ( V_2 -> V_143 ) {
if ( V_38 -> V_126 == 512 ) {
V_42 -> V_163 . V_164 = & V_165 ;
V_42 -> V_166 = & V_167 ;
} else {
V_42 -> V_163 . V_164 = & V_168 ;
V_42 -> V_166 = & V_169 ;
}
V_42 -> V_163 . V_58 = 512 ;
V_42 -> V_163 . V_170 = 10 ;
V_42 -> V_163 . V_171 = 4 ;
V_42 -> V_163 . V_172 = F_64 ;
V_42 -> V_163 . V_173 = F_65 ;
V_42 -> V_163 . V_174 = V_175 ;
V_2 -> V_100 |= V_176 ;
} else {
V_42 -> V_163 . V_174 = V_177 ;
}
return 0 ;
}
static T_7 F_85 ( int V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
F_8 ( & V_2 -> V_8 -> V_9 , L_11 , F_30 ( F_3 ( V_2 ) ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
return V_180 ;
}
static struct V_22 * F_86 ( struct V_81 * V_9 )
{
const struct V_181 * V_182 ;
struct V_183 * V_184 ;
struct V_22 * V_23 ;
struct V_185 * V_186 = V_9 -> V_187 ;
int V_24 ;
V_182 = F_87 ( V_188 , V_9 ) ;
if ( V_182 )
V_184 = (struct V_183 * ) V_182 -> V_57 ;
else {
F_8 ( V_9 , L_12 , V_13 ) ;
return NULL ;
}
V_23 = F_88 ( V_9 , sizeof( struct V_22 ) ,
V_189 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_99 = V_184 -> V_99 ;
V_23 -> V_190 = V_184 -> V_190 ;
V_23 -> V_191 = V_184 -> V_191 ;
V_24 = F_89 ( V_186 ) ;
if ( V_24 == 16 )
V_23 -> V_99 |= V_101 ;
else if ( V_24 != 8 ) {
F_8 ( V_9 , L_13 , V_13 ) ;
return NULL ;
}
return V_23 ;
}
static int F_90 ( struct V_21 * V_8 )
{
struct V_192 * V_95 ;
struct V_1 * V_2 ;
struct V_37 * V_193 ;
struct V_122 * V_194 ;
struct V_22 * V_23 ;
int V_24 ;
int V_178 ;
struct V_195 V_196 = {} ;
V_2 = F_88 ( & V_8 -> V_9 , sizeof( struct V_1 ) , V_189 ) ;
if ( ! V_2 )
return - V_197 ;
V_95 = F_91 ( V_8 , V_198 , 0 ) ;
V_2 -> V_79 = F_92 ( & V_8 -> V_9 , V_95 ) ;
if ( F_93 ( V_2 -> V_79 ) )
return F_94 ( V_2 -> V_79 ) ;
V_178 = F_95 ( V_8 , 0 ) ;
if ( V_178 < 0 ) {
F_8 ( & V_8 -> V_9 , L_14 ) ;
return - V_199 ;
}
V_24 = F_96 ( & V_8 -> V_9 , V_178 , F_85 , V_200 ,
L_15 , V_2 ) ;
if ( V_24 ) {
F_8 ( & V_8 -> V_9 , L_16 ) ;
return V_24 ;
}
if ( V_8 -> V_9 . V_187 )
V_23 = F_86 ( & V_8 -> V_9 ) ;
else
V_23 = F_17 ( & V_8 -> V_9 ) ;
if ( ! V_23 ) {
F_8 ( & V_8 -> V_9 , L_17 ) ;
return - V_78 ;
}
F_97 ( V_8 , V_2 ) ;
V_193 = & V_2 -> V_38 ;
V_194 = & V_2 -> V_42 ;
V_193 -> V_201 = V_194 ;
V_193 -> V_9 . V_202 = & V_8 -> V_9 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_143 = V_23 -> V_190 ;
V_2 -> V_157 = V_23 -> V_191 ;
V_2 -> V_100 = V_23 -> V_99 ;
V_2 -> V_3 = V_2 -> V_143 ? ( V_203 | V_204 ) : V_203 ;
V_194 -> V_205 = 20 ;
V_194 -> V_206 = F_81 ;
V_194 -> V_129 = F_80 ;
V_194 -> V_125 = F_83 ;
V_194 -> V_207 = F_75 ;
V_194 -> V_208 = F_71 ;
if ( V_23 -> V_99 & V_101 ) {
V_194 -> V_43 |= V_44 ;
V_194 -> V_209 = F_82 ;
}
F_98 ( & V_8 -> V_9 ) ;
F_99 ( & V_8 -> V_9 ) ;
F_16 ( V_2 ) ;
V_24 = F_100 ( V_193 , 1 , NULL ) ;
if ( V_24 )
goto V_210;
V_24 = F_84 ( V_193 ) ;
if ( V_24 )
goto V_210;
V_24 = F_101 ( V_193 ) ;
if ( V_24 )
goto V_210;
V_196 . V_187 = V_8 -> V_9 . V_187 ;
V_24 = F_102 ( V_193 , NULL , & V_196 , V_23 -> V_211 ,
V_23 -> V_212 ) ;
return 0 ;
V_210:
F_14 ( V_2 ) ;
F_103 ( & V_8 -> V_9 ) ;
return V_24 ;
}
static int F_104 ( struct V_21 * V_8 )
{
struct V_1 * V_2 = F_105 ( V_8 ) ;
F_14 ( V_2 ) ;
F_106 ( & V_2 -> V_38 ) ;
F_103 ( & V_8 -> V_9 ) ;
return 0 ;
}
