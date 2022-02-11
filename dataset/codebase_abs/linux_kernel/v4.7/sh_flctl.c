static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 )
return - V_8 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = V_7 -> V_11 . V_12 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_8 ;
V_5 -> V_9 = 12 ;
V_5 -> V_10 = 4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_11 . V_13 )
return - V_8 ;
V_5 -> V_9 = ( V_3 * 16 ) + 6 ;
V_5 -> V_10 = V_7 -> V_11 . V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_11 . V_13 )
return - V_8 ;
V_5 -> V_9 = V_3 * 16 ;
V_5 -> V_10 = 6 ;
if ( ! V_3 ) {
V_5 -> V_9 += 2 ;
V_5 -> V_10 -= 2 ;
}
return 0 ;
}
static void F_6 ( struct V_14 * V_15 )
{
F_7 ( V_15 -> V_16 | V_17 | V_18 , F_8 ( V_15 ) ) ;
F_7 ( V_15 -> V_16 , F_8 ( V_15 ) ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
F_10 ( V_19 , F_11 ( V_15 ) ) ;
}
static void F_12 ( struct V_14 * V_15 , const char * V_20 )
{
F_13 ( & V_15 -> V_21 -> V_22 , L_1 , V_20 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
T_1 V_23 = V_24 ;
while ( V_23 -- ) {
if ( F_15 ( F_11 ( V_15 ) ) & V_25 ) {
F_10 ( 0x0 , F_11 ( V_15 ) ) ;
return;
}
F_16 ( 1 ) ;
}
F_12 ( V_15 , V_26 ) ;
F_10 ( 0x0 , F_11 ( V_15 ) ) ;
}
static void F_17 ( void * V_27 )
{
struct V_14 * V_15 = V_27 ;
F_18 ( & V_15 -> V_28 ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
if ( V_15 -> V_29 ) {
F_20 ( V_15 -> V_29 ) ;
V_15 -> V_29 = NULL ;
}
if ( V_15 -> V_30 ) {
F_20 ( V_15 -> V_30 ) ;
V_15 -> V_30 = NULL ;
}
}
static void F_21 ( struct V_14 * V_15 )
{
T_2 V_31 ;
struct V_32 V_33 ;
struct V_34 * V_21 = V_15 -> V_21 ;
struct V_35 * V_36 = F_22 ( & V_21 -> V_22 ) ;
int V_37 ;
if ( ! V_36 )
return;
if ( V_36 -> V_38 <= 0 || V_36 -> V_39 <= 0 )
return;
F_23 ( V_31 ) ;
F_24 ( V_40 , V_31 ) ;
V_15 -> V_30 = F_25 ( V_31 , V_41 ,
( void * ) ( V_42 ) V_36 -> V_38 ) ;
F_26 ( & V_21 -> V_22 , L_2 , V_26 ,
V_15 -> V_30 ) ;
if ( ! V_15 -> V_30 )
return;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_43 = V_44 ;
V_33 . V_45 = V_15 -> V_46 ;
V_33 . V_47 = 0 ;
V_37 = F_27 ( V_15 -> V_30 , & V_33 ) ;
if ( V_37 < 0 )
goto V_48;
V_15 -> V_29 = F_25 ( V_31 , V_41 ,
( void * ) ( V_42 ) V_36 -> V_39 ) ;
F_26 ( & V_21 -> V_22 , L_3 , V_26 ,
V_15 -> V_29 ) ;
if ( ! V_15 -> V_29 )
goto V_48;
V_33 . V_43 = V_49 ;
V_33 . V_45 = 0 ;
V_33 . V_47 = V_15 -> V_46 ;
V_37 = F_27 ( V_15 -> V_29 , & V_33 ) ;
if ( V_37 < 0 )
goto V_48;
F_28 ( & V_15 -> V_28 ) ;
return;
V_48:
F_19 ( V_15 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_50 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_1 V_52 = 0 ;
if ( V_50 == - 1 ) {
V_52 = V_51 ;
} else if ( V_51 != - 1 ) {
if ( V_15 -> V_7 . V_53 & V_54 )
V_50 >>= 1 ;
if ( V_15 -> V_55 ) {
V_52 = V_50 & 0x0FFF ;
V_52 |= ( V_51 & 0xff ) << 16 ;
V_52 |= ( ( V_51 >> 8 ) & 0xff ) << 24 ;
if ( V_15 -> V_56 == V_57 ) {
T_1 V_58 ;
V_58 = ( V_51 >> 16 ) & 0xff ;
F_7 ( V_58 , F_31 ( V_15 ) ) ;
}
} else {
V_52 = V_50 ;
V_52 |= ( V_51 & 0xff ) << 8 ;
V_52 |= ( ( V_51 >> 8 ) & 0xff ) << 16 ;
V_52 |= ( ( V_51 >> 16 ) & 0xff ) << 24 ;
}
}
F_7 ( V_52 , F_32 ( V_15 ) ) ;
}
static void F_33 ( struct V_14 * V_15 )
{
T_1 V_23 = V_24 ;
while ( V_23 -- ) {
T_1 V_59 ;
V_59 = F_34 ( F_35 ( V_15 ) ) >> 16 ;
if ( V_59 & 0xFF )
return;
F_16 ( 1 ) ;
}
F_12 ( V_15 , V_26 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
T_1 V_60 , V_23 = V_24 ;
while ( V_23 -- ) {
V_60 = ( F_34 ( F_35 ( V_15 ) ) >> 16 ) & 0xFF ;
if ( V_60 >= 4 )
return;
F_16 ( 1 ) ;
}
F_12 ( V_15 , V_26 ) ;
}
static enum V_61 F_37
( struct V_14 * V_15 , int V_62 )
{
T_1 V_23 = V_24 ;
void T_3 * V_63 [ 4 ] ;
int V_64 ;
int V_65 = V_66 ;
T_1 V_67 , V_68 ;
while ( V_23 -- ) {
V_68 = F_34 ( F_35 ( V_15 ) ) >> 24 ;
if ( ( V_68 & 0xFF ) == 4 )
return V_65 ;
if ( ! ( F_34 ( F_38 ( V_15 ) ) & V_69 ) ) {
F_16 ( 1 ) ;
continue;
}
if ( F_34 ( F_38 ( V_15 ) ) & V_70 ) {
for ( V_64 = 0 ; V_64 < 512 ; V_64 ++ ) {
if ( V_15 -> V_71 [ V_64 ] != 0xff ) {
V_65 = V_72 ;
break;
}
}
if ( V_65 == V_66 )
F_26 ( & V_15 -> V_21 -> V_22 ,
L_4 ,
V_62 ) ;
F_7 ( 0 , F_38 ( V_15 ) ) ;
continue;
}
V_63 [ 0 ] = F_39 ( V_15 ) ;
V_63 [ 1 ] = F_40 ( V_15 ) ;
V_63 [ 2 ] = F_41 ( V_15 ) ;
V_63 [ 3 ] = F_42 ( V_15 ) ;
for ( V_64 = 0 ; V_64 < 3 ; V_64 ++ ) {
T_4 V_73 ;
unsigned int V_74 ;
V_67 = F_34 ( V_63 [ V_64 ] ) ;
if ( V_15 -> V_55 )
V_74 = ( 512 * V_62 ) +
( V_67 >> 16 ) ;
else
V_74 = V_67 >> 16 ;
V_73 = V_15 -> V_71 [ V_74 ] ;
V_15 -> V_71 [ V_74 ] = V_73 ^ ( V_67 & 0xFF ) ;
}
V_65 = V_75 ;
F_7 ( 0 , F_38 ( V_15 ) ) ;
}
F_12 ( V_15 , V_26 ) ;
return V_76 ;
}
static void F_43 ( struct V_14 * V_15 )
{
T_1 V_23 = V_24 ;
T_1 V_60 ;
while ( V_23 -- ) {
V_60 = ( F_34 ( F_35 ( V_15 ) ) >> 24 ) & 0xFF ;
if ( V_60 >= 4 )
return;
F_16 ( 1 ) ;
}
F_12 ( V_15 , V_26 ) ;
}
static int F_44 ( struct V_14 * V_15 , unsigned long * V_77 ,
int V_60 , enum V_78 V_79 )
{
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
enum V_84 V_85 ;
T_5 V_86 ;
T_6 V_87 = - V_88 ;
T_1 V_89 ;
int V_37 ;
if ( V_79 == V_90 ) {
V_83 = V_15 -> V_29 ;
V_85 = V_49 ;
} else {
V_83 = V_15 -> V_30 ;
V_85 = V_44 ;
}
V_86 = F_45 ( V_83 -> V_91 -> V_22 , V_77 , V_60 , V_79 ) ;
if ( V_86 )
V_81 = F_46 ( V_83 , V_86 , V_60 ,
V_85 , V_92 | V_93 ) ;
if ( V_81 ) {
V_89 = F_34 ( F_8 ( V_15 ) ) ;
V_89 |= V_94 ;
F_7 ( V_89 , F_8 ( V_15 ) ) ;
V_81 -> V_95 = F_17 ;
V_81 -> V_96 = V_15 ;
V_87 = F_47 ( V_81 ) ;
F_48 ( V_83 ) ;
} else {
F_19 ( V_15 ) ;
F_49 ( & V_15 -> V_21 -> V_22 ,
L_5 ) ;
V_37 = - V_97 ;
goto V_98;
}
V_37 =
F_50 ( & V_15 -> V_28 ,
F_51 ( 3000 ) ) ;
if ( V_37 <= 0 ) {
F_52 ( V_83 ) ;
F_13 ( & V_15 -> V_21 -> V_22 , L_6 ) ;
}
V_98:
V_89 = F_34 ( F_8 ( V_15 ) ) ;
V_89 &= ~ V_94 ;
F_7 ( V_89 , F_8 ( V_15 ) ) ;
F_53 ( V_83 -> V_91 -> V_22 , V_86 , V_60 , V_79 ) ;
return V_37 ;
}
static void F_54 ( struct V_14 * V_15 , int V_9 )
{
unsigned long V_67 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
F_14 ( V_15 ) ;
V_67 = F_34 ( F_55 ( V_15 ) ) ;
* V_77 = F_56 ( V_67 ) ;
}
static void F_57 ( struct V_14 * V_15 , int V_99 , int V_9 )
{
int V_64 , V_100 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_100 = ( V_99 + 3 ) / 4 ;
if ( V_15 -> V_29 && V_99 >= 32 &&
F_44 ( V_15 , V_77 , V_99 , V_49 ) > 0 )
goto V_101;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ ) {
F_33 ( V_15 ) ;
V_77 [ V_64 ] = F_34 ( F_58 ( V_15 ) ) ;
}
V_101:
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ )
V_77 [ V_64 ] = F_59 ( V_77 [ V_64 ] ) ;
}
static enum V_61 F_60
( struct V_14 * V_15 , T_4 * V_102 , int V_103 )
{
int V_64 ;
enum V_61 V_104 ;
unsigned long * V_105 = ( unsigned long * ) V_102 ;
V_104 = F_37 ( V_15 , V_103 ) ;
if ( V_104 != V_72 ) {
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
V_105 [ V_64 ] = F_34 ( F_61 ( V_15 ) ) ;
V_105 [ V_64 ] = F_59 ( V_105 [ V_64 ] ) ;
}
}
return V_104 ;
}
static void F_62 ( struct V_14 * V_15 , int V_99 ,
unsigned int V_9 )
{
int V_64 , V_100 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_100 = ( V_99 + 3 ) / 4 ;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ ) {
F_36 ( V_15 ) ;
F_7 ( F_63 ( V_77 [ V_64 ] ) , F_58 ( V_15 ) ) ;
}
}
static void F_64 ( struct V_14 * V_15 , int V_99 ,
unsigned int V_9 )
{
int V_64 , V_100 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_100 = ( V_99 + 3 ) / 4 ;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ )
V_77 [ V_64 ] = F_63 ( V_77 [ V_64 ] ) ;
if ( V_15 -> V_30 && V_99 >= 32 &&
F_44 ( V_15 , V_77 , V_99 , V_44 ) > 0 )
return;
for ( V_64 = 0 ; V_64 < V_100 ; V_64 ++ ) {
F_43 ( V_15 ) ;
F_7 ( V_77 [ V_64 ] , F_61 ( V_15 ) ) ;
}
}
static void F_65 ( struct V_1 * V_2 , T_1 V_106 , T_1 V_107 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_1 V_108 = V_15 -> V_109 & ~ V_110 ;
T_1 V_111 , V_112 = 0 ;
if ( V_15 -> V_55 )
V_108 |= V_113 ;
else
V_108 &= ~ V_113 ;
V_111 = V_114 | V_115 ;
switch ( V_106 ) {
case V_116 :
V_112 = V_15 -> V_117 ;
V_111 |= V_118 ;
break;
case V_119 :
case V_120 :
case V_121 :
V_112 = V_15 -> V_56 ;
V_111 |= V_122 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_108 |= V_110 ;
break;
case V_123 :
V_111 &= ~ V_115 ;
break;
case V_124 :
V_112 = V_15 -> V_56 ;
V_111 |= V_118 | V_122 | V_125 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_108 |= V_110 ;
break;
case V_126 :
V_108 &= ~ V_113 ;
V_111 |= V_122 ;
V_112 = V_127 ;
break;
case V_128 :
case V_129 :
V_108 &= ~ V_113 ;
V_111 &= ~ ( V_115 | V_130 ) ;
break;
default:
break;
}
V_111 |= V_112 ;
F_7 ( V_108 , F_66 ( V_15 ) ) ;
F_7 ( V_111 , F_67 ( V_15 ) ) ;
F_7 ( V_107 , F_68 ( V_15 ) ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_4 * V_77 , int V_131 , int V_132 )
{
V_7 -> V_133 ( V_2 , V_77 , V_2 -> V_134 ) ;
if ( V_131 )
V_7 -> V_133 ( V_2 , V_7 -> V_135 , V_2 -> V_136 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_4 * V_77 , int V_131 ,
int V_132 )
{
V_7 -> V_137 ( V_2 , V_77 , V_2 -> V_134 ) ;
V_7 -> V_137 ( V_2 , V_7 -> V_135 , V_2 -> V_136 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_103 , V_138 ;
enum V_61 V_139 ;
V_138 = V_15 -> V_55 ? 4 : 1 ;
F_65 ( V_2 , V_119 ,
( V_140 << 8 ) | V_119 ) ;
F_7 ( F_34 ( F_66 ( V_15 ) ) | V_141 | V_142 ,
F_66 ( V_15 ) ) ;
F_7 ( F_34 ( F_67 ( V_15 ) ) | V_138 , F_67 ( V_15 ) ) ;
F_7 ( V_51 << 2 , F_32 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
for ( V_103 = 0 ; V_103 < V_138 ; V_103 ++ ) {
F_57 ( V_15 , 512 , 512 * V_103 ) ;
V_139 = F_60 ( V_15 ,
& V_15 -> V_71 [ V_2 -> V_134 + 16 * V_103 ] ,
V_103 ) ;
switch ( V_139 ) {
case V_75 :
F_72 ( & V_15 -> V_21 -> V_22 ,
L_7 , V_51 ) ;
V_2 -> V_143 . V_144 ++ ;
break;
case V_72 :
F_49 ( & V_15 -> V_21 -> V_22 ,
L_8 ,
V_51 ) ;
V_2 -> V_143 . V_145 ++ ;
break;
default:
;
}
}
F_14 ( V_15 ) ;
F_7 ( F_34 ( F_66 ( V_15 ) ) & ~ ( V_141 | V_142 ) ,
F_66 ( V_15 ) ) ;
}
static void F_73 ( struct V_1 * V_2 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_138 = V_15 -> V_55 ? 4 : 1 ;
int V_64 ;
F_65 ( V_2 , V_119 ,
( V_140 << 8 ) | V_119 ) ;
F_6 ( V_15 ) ;
for ( V_64 = 0 ; V_64 < V_138 ; V_64 ++ ) {
F_29 ( V_2 , ( 512 + 16 ) * V_64 + 512 , V_51 ) ;
F_7 ( 16 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_57 ( V_15 , 16 , 16 * V_64 ) ;
F_14 ( V_15 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_51 = V_15 -> V_146 ;
int V_103 , V_138 ;
V_138 = V_15 -> V_55 ? 4 : 1 ;
F_65 ( V_2 , V_124 ,
( V_124 << 8 ) | V_123 ) ;
F_6 ( V_15 ) ;
F_7 ( F_34 ( F_66 ( V_15 ) ) | V_141 , F_66 ( V_15 ) ) ;
F_7 ( F_34 ( F_67 ( V_15 ) ) | V_138 , F_67 ( V_15 ) ) ;
F_7 ( V_51 << 2 , F_32 ( V_15 ) ) ;
F_9 ( V_15 ) ;
for ( V_103 = 0 ; V_103 < V_138 ; V_103 ++ ) {
F_62 ( V_15 , 512 , 512 * V_103 ) ;
F_64 ( V_15 , 16 , V_2 -> V_134 + 16 * V_103 ) ;
}
F_14 ( V_15 ) ;
F_7 ( F_34 ( F_66 ( V_15 ) ) & ~ V_141 , F_66 ( V_15 ) ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_51 = V_15 -> V_146 ;
int V_103 , V_138 ;
V_138 = V_15 -> V_55 ? 4 : 1 ;
F_65 ( V_2 , V_124 ,
( V_124 << 8 ) | V_123 ) ;
for ( V_103 = 0 ; V_103 < V_138 ; V_103 ++ ) {
F_6 ( V_15 ) ;
F_29 ( V_2 , V_103 * 528 + 512 , V_51 ) ;
F_7 ( 16 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_62 ( V_15 , 16 , 16 * V_103 ) ;
F_14 ( V_15 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , unsigned int V_147 ,
int V_50 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_1 V_148 = 0 ;
F_77 ( & V_15 -> V_21 -> V_22 ) ;
V_15 -> V_149 = 0 ;
if ( V_147 != V_124 )
V_15 -> V_74 = 0 ;
switch ( V_147 ) {
case V_150 :
case V_119 :
if ( V_15 -> V_151 ) {
F_71 ( V_2 , V_51 ) ;
break;
}
if ( V_15 -> V_55 )
F_65 ( V_2 , V_147 , ( V_140 << 8 )
| V_147 ) ;
else
F_65 ( V_2 , V_147 , V_147 ) ;
F_29 ( V_2 , 0 , V_51 ) ;
V_15 -> V_149 = V_2 -> V_134 + V_2 -> V_136 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_50 >>= 1 ;
V_15 -> V_74 += V_50 ;
goto V_152;
case V_120 :
if ( V_15 -> V_151 ) {
F_73 ( V_2 , V_51 ) ;
break;
}
if ( V_15 -> V_55 ) {
F_65 ( V_2 , V_147 , ( V_140 << 8 )
| V_119 ) ;
F_29 ( V_2 , V_2 -> V_134 , V_51 ) ;
} else {
F_65 ( V_2 , V_147 , V_147 ) ;
F_29 ( V_2 , 0 , V_51 ) ;
}
V_15 -> V_149 = V_2 -> V_136 ;
goto V_152;
case V_121 :
if ( V_15 -> V_151 )
break;
if ( V_15 -> V_55 )
F_65 ( V_2 , V_147 , ( V_153 << 8 )
| V_147 ) ;
else
F_65 ( V_2 , V_147 , V_147 ) ;
F_29 ( V_2 , V_50 , 0 ) ;
V_15 -> V_149 = V_2 -> V_134 + V_2 -> V_136 - V_50 ;
goto V_152;
case V_126 :
F_65 ( V_2 , V_147 , V_147 ) ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_50 <<= 1 ;
F_29 ( V_2 , V_50 , 0 ) ;
V_15 -> V_149 = 8 ;
F_7 ( V_15 -> V_149 , F_35 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
F_57 ( V_15 , V_15 -> V_149 , 0 ) ;
F_14 ( V_15 ) ;
break;
case V_116 :
V_15 -> V_154 = V_51 ;
break;
case V_155 :
F_65 ( V_2 , V_116 ,
( V_147 << 8 ) | V_116 ) ;
F_29 ( V_2 , - 1 , V_15 -> V_154 ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
break;
case V_123 :
if ( ! V_15 -> V_55 ) {
if ( V_50 >= V_2 -> V_134 ) {
V_50 -= V_2 -> V_134 ;
V_148 = V_120 ;
} else if ( V_50 < 256 ) {
V_148 = V_119 ;
} else {
V_50 -= 256 ;
V_148 = V_150 ;
}
}
V_15 -> V_156 = V_50 ;
V_15 -> V_146 = V_51 ;
V_15 -> V_157 = V_148 ;
break;
case V_124 :
F_6 ( V_15 ) ;
if ( ! V_15 -> V_55 ) {
F_65 ( V_2 , V_123 ,
V_15 -> V_157 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
F_7 ( 0 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
}
if ( V_15 -> V_151 ) {
if ( V_15 -> V_156 == V_2 -> V_134 )
F_75 ( V_2 ) ;
else if ( ! V_15 -> V_156 )
F_74 ( V_2 ) ;
else
F_78 ( V_158 L_9 ) ;
break;
}
F_65 ( V_2 , V_147 , ( V_147 << 8 ) | V_123 ) ;
F_29 ( V_2 , V_15 -> V_156 , V_15 -> V_146 ) ;
F_7 ( V_15 -> V_74 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_62 ( V_15 , V_15 -> V_74 , 0 ) ;
F_14 ( V_15 ) ;
break;
case V_128 :
F_65 ( V_2 , V_147 , V_147 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
V_15 -> V_149 = 1 ;
F_7 ( V_15 -> V_149 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_54 ( V_15 , 0 ) ;
break;
case V_129 :
F_65 ( V_2 , V_147 , V_147 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
F_7 ( 0 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
break;
default:
break;
}
goto V_159;
V_152:
F_7 ( V_15 -> V_149 , F_35 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
F_57 ( V_15 , V_15 -> V_149 , 0 ) ;
F_14 ( V_15 ) ;
V_159:
F_79 ( & V_15 -> V_21 -> V_22 ) ;
return;
}
static void F_80 ( struct V_1 * V_2 , int V_160 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_37 ;
switch ( V_160 ) {
case - 1 :
V_15 -> V_109 &= ~ V_161 ;
F_77 ( & V_15 -> V_21 -> V_22 ) ;
F_7 ( V_15 -> V_109 , F_66 ( V_15 ) ) ;
if ( V_15 -> V_162 ) {
F_81 ( & V_15 -> V_163 ) ;
V_15 -> V_162 = 0 ;
}
F_79 ( & V_15 -> V_21 -> V_22 ) ;
break;
case 0 :
V_15 -> V_109 |= V_161 ;
if ( ! V_15 -> V_162 ) {
V_37 = F_82 ( & V_15 -> V_21 -> V_22 ,
& V_15 -> V_163 ,
V_164 ,
100 ) ;
if ( V_37 < 0 )
F_13 ( & V_15 -> V_21 -> V_22 ,
L_10 , V_37 ) ;
V_15 -> V_162 = 1 ;
}
if ( V_15 -> V_165 ) {
F_77 ( & V_15 -> V_21 -> V_22 ) ;
F_7 ( V_166 , F_83 ( V_15 ) ) ;
F_79 ( & V_15 -> V_21 -> V_22 ) ;
}
break;
default:
F_84 () ;
}
}
static void F_85 ( struct V_1 * V_2 , const T_4 * V_77 , int V_60 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
memcpy ( & V_15 -> V_71 [ V_15 -> V_74 ] , V_77 , V_60 ) ;
V_15 -> V_74 += V_60 ;
}
static T_4 F_86 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_4 V_67 ;
V_67 = V_15 -> V_71 [ V_15 -> V_74 ] ;
V_15 -> V_74 ++ ;
return V_67 ;
}
static T_7 F_87 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_7 * V_77 = ( T_7 * ) & V_15 -> V_71 [ V_15 -> V_74 ] ;
V_15 -> V_74 += 2 ;
return * V_77 ;
}
static void F_88 ( struct V_1 * V_2 , T_4 * V_77 , int V_60 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
memcpy ( V_77 , & V_15 -> V_71 [ V_15 -> V_74 ] , V_60 ) ;
V_15 -> V_74 += V_60 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
struct V_6 * V_7 = & V_15 -> V_7 ;
if ( V_2 -> V_134 == 512 ) {
V_15 -> V_55 = 0 ;
if ( V_7 -> V_167 > ( 32 << 20 ) ) {
V_15 -> V_56 = V_168 ;
V_15 -> V_117 = V_169 ;
} else if ( V_7 -> V_167 > ( 2 << 16 ) ) {
V_15 -> V_56 = V_169 ;
V_15 -> V_117 = V_170 ;
} else {
V_15 -> V_56 = V_170 ;
V_15 -> V_117 = V_127 ;
}
} else {
V_15 -> V_55 = 1 ;
if ( V_7 -> V_167 > ( 128 << 20 ) ) {
V_15 -> V_56 = V_57 ;
V_15 -> V_117 = V_169 ;
} else if ( V_7 -> V_167 > ( 8 << 16 ) ) {
V_15 -> V_56 = V_168 ;
V_15 -> V_117 = V_170 ;
} else {
V_15 -> V_56 = V_169 ;
V_15 -> V_117 = V_127 ;
}
}
if ( V_15 -> V_151 ) {
if ( V_2 -> V_134 == 512 ) {
F_90 ( V_2 , & V_171 ) ;
V_7 -> V_172 = & V_173 ;
} else {
F_90 ( V_2 , & V_174 ) ;
V_7 -> V_172 = & V_175 ;
}
V_7 -> V_11 . V_68 = 512 ;
V_7 -> V_11 . V_12 = 10 ;
V_7 -> V_11 . V_176 = 4 ;
V_7 -> V_11 . V_177 = F_69 ;
V_7 -> V_11 . V_178 = F_70 ;
V_7 -> V_11 . V_179 = V_180 ;
V_15 -> V_109 |= V_181 ;
} else {
V_7 -> V_11 . V_179 = V_182 ;
V_7 -> V_11 . V_183 = V_184 ;
}
return 0 ;
}
static T_8 F_91 ( int V_185 , void * V_186 )
{
struct V_14 * V_15 = V_186 ;
F_13 ( & V_15 -> V_21 -> V_22 , L_11 , F_34 ( F_8 ( V_15 ) ) ) ;
F_7 ( V_15 -> V_16 , F_8 ( V_15 ) ) ;
return V_187 ;
}
static struct V_35 * F_92 ( struct V_91 * V_22 )
{
const struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_35 * V_36 ;
V_189 = F_93 ( V_192 , V_22 ) ;
if ( V_189 )
V_191 = (struct V_190 * ) V_189 -> V_67 ;
else {
F_13 ( V_22 , L_12 , V_26 ) ;
return NULL ;
}
V_36 = F_94 ( V_22 , sizeof( struct V_35 ) ,
V_193 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_108 = V_191 -> V_108 ;
V_36 -> V_194 = V_191 -> V_194 ;
V_36 -> V_195 = V_191 -> V_195 ;
return V_36 ;
}
static int F_95 ( struct V_34 * V_21 )
{
struct V_196 * V_104 ;
struct V_14 * V_15 ;
struct V_1 * V_197 ;
struct V_6 * V_198 ;
struct V_35 * V_36 ;
int V_37 ;
int V_185 ;
V_15 = F_94 ( & V_21 -> V_22 , sizeof( struct V_14 ) , V_193 ) ;
if ( ! V_15 )
return - V_199 ;
V_104 = F_96 ( V_21 , V_200 , 0 ) ;
V_15 -> V_89 = F_97 ( & V_21 -> V_22 , V_104 ) ;
if ( F_98 ( V_15 -> V_89 ) )
return F_99 ( V_15 -> V_89 ) ;
V_15 -> V_46 = V_104 -> V_201 + 0x24 ;
V_185 = F_100 ( V_21 , 0 ) ;
if ( V_185 < 0 ) {
F_13 ( & V_21 -> V_22 , L_13 ) ;
return - V_202 ;
}
V_37 = F_101 ( & V_21 -> V_22 , V_185 , F_91 , V_203 ,
L_14 , V_15 ) ;
if ( V_37 ) {
F_13 ( & V_21 -> V_22 , L_15 ) ;
return V_37 ;
}
if ( V_21 -> V_22 . V_204 )
V_36 = F_92 ( & V_21 -> V_22 ) ;
else
V_36 = F_22 ( & V_21 -> V_22 ) ;
if ( ! V_36 ) {
F_13 ( & V_21 -> V_22 , L_16 ) ;
return - V_88 ;
}
F_102 ( V_21 , V_15 ) ;
V_198 = & V_15 -> V_7 ;
V_197 = F_103 ( V_198 ) ;
F_104 ( V_198 , V_21 -> V_22 . V_204 ) ;
V_197 -> V_22 . V_205 = & V_21 -> V_22 ;
V_15 -> V_21 = V_21 ;
V_15 -> V_151 = V_36 -> V_194 ;
V_15 -> V_165 = V_36 -> V_195 ;
V_15 -> V_109 = V_36 -> V_108 ;
V_15 -> V_16 = V_15 -> V_151 ? ( V_206 | V_207 ) : V_206 ;
V_198 -> V_208 = 20 ;
V_198 -> V_209 = F_86 ;
V_198 -> V_210 = F_87 ;
V_198 -> V_137 = F_85 ;
V_198 -> V_133 = F_88 ;
V_198 -> V_211 = F_80 ;
V_198 -> V_212 = F_76 ;
if ( V_36 -> V_108 & V_110 )
V_198 -> V_53 |= V_54 ;
F_105 ( & V_21 -> V_22 ) ;
F_106 ( & V_21 -> V_22 ) ;
F_21 ( V_15 ) ;
V_37 = F_107 ( V_197 , 1 , NULL ) ;
if ( V_37 )
goto V_213;
if ( V_198 -> V_53 & V_54 ) {
V_36 -> V_108 |= V_110 ;
V_15 -> V_109 = V_36 -> V_108 ;
}
V_37 = F_89 ( V_197 ) ;
if ( V_37 )
goto V_213;
V_37 = F_108 ( V_197 ) ;
if ( V_37 )
goto V_213;
V_37 = F_109 ( V_197 , V_36 -> V_214 , V_36 -> V_215 ) ;
return 0 ;
V_213:
F_19 ( V_15 ) ;
F_110 ( & V_21 -> V_22 ) ;
return V_37 ;
}
static int F_111 ( struct V_34 * V_21 )
{
struct V_14 * V_15 = F_112 ( V_21 ) ;
F_19 ( V_15 ) ;
F_113 ( F_103 ( & V_15 -> V_7 ) ) ;
F_110 ( & V_21 -> V_22 ) ;
return 0 ;
}
