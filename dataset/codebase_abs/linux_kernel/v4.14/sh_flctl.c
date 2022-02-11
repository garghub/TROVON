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
T_6 V_87 ;
T_1 V_88 ;
int V_37 ;
if ( V_79 == V_89 ) {
V_83 = V_15 -> V_29 ;
V_85 = V_49 ;
} else {
V_83 = V_15 -> V_30 ;
V_85 = V_44 ;
}
V_86 = F_45 ( V_83 -> V_90 -> V_22 , V_77 , V_60 , V_79 ) ;
if ( ! F_46 ( V_83 -> V_90 -> V_22 , V_86 ) )
V_81 = F_47 ( V_83 , V_86 , V_60 ,
V_85 , V_91 | V_92 ) ;
if ( V_81 ) {
V_88 = F_34 ( F_8 ( V_15 ) ) ;
V_88 |= V_93 ;
F_7 ( V_88 , F_8 ( V_15 ) ) ;
V_81 -> V_94 = F_17 ;
V_81 -> V_95 = V_15 ;
V_87 = F_48 ( V_81 ) ;
if ( F_49 ( V_87 ) ) {
V_37 = F_49 ( V_87 ) ;
F_50 ( & V_15 -> V_21 -> V_22 ,
L_5 ) ;
goto V_96;
}
F_51 ( V_83 ) ;
} else {
F_19 ( V_15 ) ;
F_50 ( & V_15 -> V_21 -> V_22 ,
L_6 ) ;
V_37 = - V_97 ;
goto V_96;
}
V_37 =
F_52 ( & V_15 -> V_28 ,
F_53 ( 3000 ) ) ;
if ( V_37 <= 0 ) {
F_54 ( V_83 ) ;
F_13 ( & V_15 -> V_21 -> V_22 , L_7 ) ;
}
V_96:
V_88 = F_34 ( F_8 ( V_15 ) ) ;
V_88 &= ~ V_93 ;
F_7 ( V_88 , F_8 ( V_15 ) ) ;
F_55 ( V_83 -> V_90 -> V_22 , V_86 , V_60 , V_79 ) ;
return V_37 ;
}
static void F_56 ( struct V_14 * V_15 , int V_9 )
{
unsigned long V_67 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
F_14 ( V_15 ) ;
V_67 = F_34 ( F_57 ( V_15 ) ) ;
* V_77 = F_58 ( V_67 ) ;
}
static void F_59 ( struct V_14 * V_15 , int V_98 , int V_9 )
{
int V_64 , V_99 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_99 = ( V_98 + 3 ) / 4 ;
if ( V_15 -> V_29 && V_98 >= 32 &&
F_44 ( V_15 , V_77 , V_98 , V_49 ) > 0 )
goto V_100;
for ( V_64 = 0 ; V_64 < V_99 ; V_64 ++ ) {
F_33 ( V_15 ) ;
V_77 [ V_64 ] = F_34 ( F_60 ( V_15 ) ) ;
}
V_100:
for ( V_64 = 0 ; V_64 < V_99 ; V_64 ++ )
V_77 [ V_64 ] = F_61 ( V_77 [ V_64 ] ) ;
}
static enum V_61 F_62
( struct V_14 * V_15 , T_4 * V_101 , int V_102 )
{
int V_64 ;
enum V_61 V_103 ;
unsigned long * V_104 = ( unsigned long * ) V_101 ;
V_103 = F_37 ( V_15 , V_102 ) ;
if ( V_103 != V_72 ) {
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
V_104 [ V_64 ] = F_34 ( F_63 ( V_15 ) ) ;
V_104 [ V_64 ] = F_61 ( V_104 [ V_64 ] ) ;
}
}
return V_103 ;
}
static void F_64 ( struct V_14 * V_15 , int V_98 ,
unsigned int V_9 )
{
int V_64 , V_99 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_99 = ( V_98 + 3 ) / 4 ;
for ( V_64 = 0 ; V_64 < V_99 ; V_64 ++ ) {
F_36 ( V_15 ) ;
F_7 ( F_65 ( V_77 [ V_64 ] ) , F_60 ( V_15 ) ) ;
}
}
static void F_66 ( struct V_14 * V_15 , int V_98 ,
unsigned int V_9 )
{
int V_64 , V_99 ;
unsigned long * V_77 = ( unsigned long * ) & V_15 -> V_71 [ V_9 ] ;
V_99 = ( V_98 + 3 ) / 4 ;
for ( V_64 = 0 ; V_64 < V_99 ; V_64 ++ )
V_77 [ V_64 ] = F_65 ( V_77 [ V_64 ] ) ;
if ( V_15 -> V_30 && V_98 >= 32 &&
F_44 ( V_15 , V_77 , V_98 , V_44 ) > 0 )
return;
for ( V_64 = 0 ; V_64 < V_99 ; V_64 ++ ) {
F_43 ( V_15 ) ;
F_7 ( V_77 [ V_64 ] , F_63 ( V_15 ) ) ;
}
}
static void F_67 ( struct V_1 * V_2 , T_1 V_105 , T_1 V_106 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_1 V_107 = V_15 -> V_108 & ~ V_109 ;
T_1 V_110 , V_111 = 0 ;
if ( V_15 -> V_55 )
V_107 |= V_112 ;
else
V_107 &= ~ V_112 ;
V_110 = V_113 | V_114 ;
switch ( V_105 ) {
case V_115 :
V_111 = V_15 -> V_116 ;
V_110 |= V_117 ;
break;
case V_118 :
case V_119 :
case V_120 :
V_111 = V_15 -> V_56 ;
V_110 |= V_121 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_107 |= V_109 ;
break;
case V_122 :
V_110 &= ~ V_114 ;
break;
case V_123 :
V_111 = V_15 -> V_56 ;
V_110 |= V_117 | V_121 | V_124 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_107 |= V_109 ;
break;
case V_125 :
V_107 &= ~ V_112 ;
V_110 |= V_121 ;
V_111 = V_126 ;
break;
case V_127 :
case V_128 :
V_107 &= ~ V_112 ;
V_110 &= ~ ( V_114 | V_129 ) ;
break;
default:
break;
}
V_110 |= V_111 ;
F_7 ( V_107 , F_68 ( V_15 ) ) ;
F_7 ( V_110 , F_69 ( V_15 ) ) ;
F_7 ( V_106 , F_70 ( V_15 ) ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_4 * V_77 , int V_130 , int V_131 )
{
V_7 -> V_132 ( V_2 , V_77 , V_2 -> V_133 ) ;
if ( V_130 )
V_7 -> V_132 ( V_2 , V_7 -> V_134 , V_2 -> V_135 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_4 * V_77 , int V_130 ,
int V_131 )
{
V_7 -> V_136 ( V_2 , V_77 , V_2 -> V_133 ) ;
V_7 -> V_136 ( V_2 , V_7 -> V_134 , V_2 -> V_135 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_102 , V_137 ;
enum V_61 V_138 ;
V_137 = V_15 -> V_55 ? 4 : 1 ;
F_67 ( V_2 , V_118 ,
( V_139 << 8 ) | V_118 ) ;
F_7 ( F_34 ( F_68 ( V_15 ) ) | V_140 | V_141 ,
F_68 ( V_15 ) ) ;
F_7 ( F_34 ( F_69 ( V_15 ) ) | V_137 , F_69 ( V_15 ) ) ;
F_7 ( V_51 << 2 , F_32 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
for ( V_102 = 0 ; V_102 < V_137 ; V_102 ++ ) {
F_59 ( V_15 , 512 , 512 * V_102 ) ;
V_138 = F_62 ( V_15 ,
& V_15 -> V_71 [ V_2 -> V_133 + 16 * V_102 ] ,
V_102 ) ;
switch ( V_138 ) {
case V_75 :
F_74 ( & V_15 -> V_21 -> V_22 ,
L_8 , V_51 ) ;
V_2 -> V_142 . V_143 ++ ;
break;
case V_72 :
F_50 ( & V_15 -> V_21 -> V_22 ,
L_9 ,
V_51 ) ;
V_2 -> V_142 . V_144 ++ ;
break;
default:
;
}
}
F_14 ( V_15 ) ;
F_7 ( F_34 ( F_68 ( V_15 ) ) & ~ ( V_140 | V_141 ) ,
F_68 ( V_15 ) ) ;
}
static void F_75 ( struct V_1 * V_2 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_137 = V_15 -> V_55 ? 4 : 1 ;
int V_64 ;
F_67 ( V_2 , V_118 ,
( V_139 << 8 ) | V_118 ) ;
F_6 ( V_15 ) ;
for ( V_64 = 0 ; V_64 < V_137 ; V_64 ++ ) {
F_29 ( V_2 , ( 512 + 16 ) * V_64 + 512 , V_51 ) ;
F_7 ( 16 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_59 ( V_15 , 16 , 16 * V_64 ) ;
F_14 ( V_15 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_51 = V_15 -> V_145 ;
int V_102 , V_137 ;
V_137 = V_15 -> V_55 ? 4 : 1 ;
F_67 ( V_2 , V_123 ,
( V_123 << 8 ) | V_122 ) ;
F_6 ( V_15 ) ;
F_7 ( F_34 ( F_68 ( V_15 ) ) | V_140 , F_68 ( V_15 ) ) ;
F_7 ( F_34 ( F_69 ( V_15 ) ) | V_137 , F_69 ( V_15 ) ) ;
F_7 ( V_51 << 2 , F_32 ( V_15 ) ) ;
F_9 ( V_15 ) ;
for ( V_102 = 0 ; V_102 < V_137 ; V_102 ++ ) {
F_64 ( V_15 , 512 , 512 * V_102 ) ;
F_66 ( V_15 , 16 , V_2 -> V_133 + 16 * V_102 ) ;
}
F_14 ( V_15 ) ;
F_7 ( F_34 ( F_68 ( V_15 ) ) & ~ V_140 , F_68 ( V_15 ) ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_51 = V_15 -> V_145 ;
int V_102 , V_137 ;
V_137 = V_15 -> V_55 ? 4 : 1 ;
F_67 ( V_2 , V_123 ,
( V_123 << 8 ) | V_122 ) ;
for ( V_102 = 0 ; V_102 < V_137 ; V_102 ++ ) {
F_6 ( V_15 ) ;
F_29 ( V_2 , V_102 * 528 + 512 , V_51 ) ;
F_7 ( 16 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_64 ( V_15 , 16 , 16 * V_102 ) ;
F_14 ( V_15 ) ;
}
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_146 ,
int V_50 , int V_51 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_1 V_147 = 0 ;
F_79 ( & V_15 -> V_21 -> V_22 ) ;
V_15 -> V_148 = 0 ;
if ( V_146 != V_123 )
V_15 -> V_74 = 0 ;
switch ( V_146 ) {
case V_149 :
case V_118 :
if ( V_15 -> V_150 ) {
F_73 ( V_2 , V_51 ) ;
break;
}
if ( V_15 -> V_55 )
F_67 ( V_2 , V_146 , ( V_139 << 8 )
| V_146 ) ;
else
F_67 ( V_2 , V_146 , V_146 ) ;
F_29 ( V_2 , 0 , V_51 ) ;
V_15 -> V_148 = V_2 -> V_133 + V_2 -> V_135 ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_50 >>= 1 ;
V_15 -> V_74 += V_50 ;
goto V_151;
case V_119 :
if ( V_15 -> V_150 ) {
F_75 ( V_2 , V_51 ) ;
break;
}
if ( V_15 -> V_55 ) {
F_67 ( V_2 , V_146 , ( V_139 << 8 )
| V_118 ) ;
F_29 ( V_2 , V_2 -> V_133 , V_51 ) ;
} else {
F_67 ( V_2 , V_146 , V_146 ) ;
F_29 ( V_2 , 0 , V_51 ) ;
}
V_15 -> V_148 = V_2 -> V_135 ;
goto V_151;
case V_120 :
if ( V_15 -> V_150 )
break;
if ( V_15 -> V_55 )
F_67 ( V_2 , V_146 , ( V_152 << 8 )
| V_146 ) ;
else
F_67 ( V_2 , V_146 , V_146 ) ;
F_29 ( V_2 , V_50 , 0 ) ;
V_15 -> V_148 = V_2 -> V_133 + V_2 -> V_135 - V_50 ;
goto V_151;
case V_125 :
F_67 ( V_2 , V_146 , V_146 ) ;
if ( V_15 -> V_7 . V_53 & V_54 )
V_50 <<= 1 ;
F_29 ( V_2 , V_50 , 0 ) ;
V_15 -> V_148 = 8 ;
F_7 ( V_15 -> V_148 , F_35 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
F_59 ( V_15 , V_15 -> V_148 , 0 ) ;
F_14 ( V_15 ) ;
break;
case V_115 :
V_15 -> V_153 = V_51 ;
break;
case V_154 :
F_67 ( V_2 , V_115 ,
( V_146 << 8 ) | V_115 ) ;
F_29 ( V_2 , - 1 , V_15 -> V_153 ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
break;
case V_122 :
if ( ! V_15 -> V_55 ) {
if ( V_50 >= V_2 -> V_133 ) {
V_50 -= V_2 -> V_133 ;
V_147 = V_119 ;
} else if ( V_50 < 256 ) {
V_147 = V_118 ;
} else {
V_50 -= 256 ;
V_147 = V_149 ;
}
}
V_15 -> V_155 = V_50 ;
V_15 -> V_145 = V_51 ;
V_15 -> V_156 = V_147 ;
break;
case V_123 :
F_6 ( V_15 ) ;
if ( ! V_15 -> V_55 ) {
F_67 ( V_2 , V_122 ,
V_15 -> V_156 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
F_7 ( 0 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
}
if ( V_15 -> V_150 ) {
if ( V_15 -> V_155 == V_2 -> V_133 )
F_77 ( V_2 ) ;
else if ( ! V_15 -> V_155 )
F_76 ( V_2 ) ;
else
F_80 ( V_157 L_10 ) ;
break;
}
F_67 ( V_2 , V_146 , ( V_146 << 8 ) | V_122 ) ;
F_29 ( V_2 , V_15 -> V_155 , V_15 -> V_145 ) ;
F_7 ( V_15 -> V_74 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_64 ( V_15 , V_15 -> V_74 , 0 ) ;
F_14 ( V_15 ) ;
break;
case V_127 :
F_67 ( V_2 , V_146 , V_146 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
V_15 -> V_148 = 1 ;
F_7 ( V_15 -> V_148 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_56 ( V_15 , 0 ) ;
break;
case V_128 :
F_67 ( V_2 , V_146 , V_146 ) ;
F_29 ( V_2 , - 1 , - 1 ) ;
F_7 ( 0 , F_35 ( V_15 ) ) ;
F_9 ( V_15 ) ;
F_14 ( V_15 ) ;
break;
default:
break;
}
goto V_158;
V_151:
F_7 ( V_15 -> V_148 , F_35 ( V_15 ) ) ;
F_6 ( V_15 ) ;
F_9 ( V_15 ) ;
F_59 ( V_15 , V_15 -> V_148 , 0 ) ;
F_14 ( V_15 ) ;
V_158:
F_81 ( & V_15 -> V_21 -> V_22 ) ;
return;
}
static void F_82 ( struct V_1 * V_2 , int V_159 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
int V_37 ;
switch ( V_159 ) {
case - 1 :
V_15 -> V_108 &= ~ V_160 ;
F_79 ( & V_15 -> V_21 -> V_22 ) ;
F_7 ( V_15 -> V_108 , F_68 ( V_15 ) ) ;
if ( V_15 -> V_161 ) {
F_83 ( & V_15 -> V_162 ) ;
V_15 -> V_161 = 0 ;
}
F_81 ( & V_15 -> V_21 -> V_22 ) ;
break;
case 0 :
V_15 -> V_108 |= V_160 ;
if ( ! V_15 -> V_161 ) {
V_37 = F_84 ( & V_15 -> V_21 -> V_22 ,
& V_15 -> V_162 ,
V_163 ,
100 ) ;
if ( V_37 < 0 )
F_13 ( & V_15 -> V_21 -> V_22 ,
L_11 , V_37 ) ;
V_15 -> V_161 = 1 ;
}
if ( V_15 -> V_164 ) {
F_79 ( & V_15 -> V_21 -> V_22 ) ;
F_7 ( V_165 , F_85 ( V_15 ) ) ;
F_81 ( & V_15 -> V_21 -> V_22 ) ;
}
break;
default:
F_86 () ;
}
}
static void F_87 ( struct V_1 * V_2 , const T_4 * V_77 , int V_60 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
memcpy ( & V_15 -> V_71 [ V_15 -> V_74 ] , V_77 , V_60 ) ;
V_15 -> V_74 += V_60 ;
}
static T_4 F_88 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_4 V_67 ;
V_67 = V_15 -> V_71 [ V_15 -> V_74 ] ;
V_15 -> V_74 ++ ;
return V_67 ;
}
static T_7 F_89 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
T_7 * V_77 = ( T_7 * ) & V_15 -> V_71 [ V_15 -> V_74 ] ;
V_15 -> V_74 += 2 ;
return * V_77 ;
}
static void F_90 ( struct V_1 * V_2 , T_4 * V_77 , int V_60 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
memcpy ( V_77 , & V_15 -> V_71 [ V_15 -> V_74 ] , V_60 ) ;
V_15 -> V_74 += V_60 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_30 ( V_2 ) ;
struct V_6 * V_7 = & V_15 -> V_7 ;
if ( V_2 -> V_133 == 512 ) {
V_15 -> V_55 = 0 ;
if ( V_7 -> V_166 > ( 32 << 20 ) ) {
V_15 -> V_56 = V_167 ;
V_15 -> V_116 = V_168 ;
} else if ( V_7 -> V_166 > ( 2 << 16 ) ) {
V_15 -> V_56 = V_168 ;
V_15 -> V_116 = V_169 ;
} else {
V_15 -> V_56 = V_169 ;
V_15 -> V_116 = V_126 ;
}
} else {
V_15 -> V_55 = 1 ;
if ( V_7 -> V_166 > ( 128 << 20 ) ) {
V_15 -> V_56 = V_57 ;
V_15 -> V_116 = V_168 ;
} else if ( V_7 -> V_166 > ( 8 << 16 ) ) {
V_15 -> V_56 = V_167 ;
V_15 -> V_116 = V_169 ;
} else {
V_15 -> V_56 = V_168 ;
V_15 -> V_116 = V_126 ;
}
}
if ( V_15 -> V_150 ) {
if ( V_2 -> V_133 == 512 ) {
F_92 ( V_2 , & V_170 ) ;
V_7 -> V_171 = & V_172 ;
} else {
F_92 ( V_2 , & V_173 ) ;
V_7 -> V_171 = & V_174 ;
}
V_7 -> V_11 . V_68 = 512 ;
V_7 -> V_11 . V_12 = 10 ;
V_7 -> V_11 . V_175 = 4 ;
V_7 -> V_11 . V_176 = F_71 ;
V_7 -> V_11 . V_177 = F_72 ;
V_7 -> V_11 . V_178 = V_179 ;
V_15 -> V_108 |= V_180 ;
} else {
V_7 -> V_11 . V_178 = V_181 ;
V_7 -> V_11 . V_182 = V_183 ;
}
return 0 ;
}
static T_8 F_93 ( int V_184 , void * V_185 )
{
struct V_14 * V_15 = V_185 ;
F_13 ( & V_15 -> V_21 -> V_22 , L_12 , F_34 ( F_8 ( V_15 ) ) ) ;
F_7 ( V_15 -> V_16 , F_8 ( V_15 ) ) ;
return V_186 ;
}
static struct V_35 * F_94 ( struct V_90 * V_22 )
{
const struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_35 * V_36 ;
V_188 = F_95 ( V_191 , V_22 ) ;
if ( V_188 )
V_190 = (struct V_189 * ) V_188 -> V_67 ;
else {
F_13 ( V_22 , L_13 , V_26 ) ;
return NULL ;
}
V_36 = F_96 ( V_22 , sizeof( struct V_35 ) ,
V_192 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_107 = V_190 -> V_107 ;
V_36 -> V_193 = V_190 -> V_193 ;
V_36 -> V_194 = V_190 -> V_194 ;
return V_36 ;
}
static int F_97 ( struct V_34 * V_21 )
{
struct V_195 * V_103 ;
struct V_14 * V_15 ;
struct V_1 * V_196 ;
struct V_6 * V_197 ;
struct V_35 * V_36 ;
int V_37 ;
int V_184 ;
V_15 = F_96 ( & V_21 -> V_22 , sizeof( struct V_14 ) , V_192 ) ;
if ( ! V_15 )
return - V_198 ;
V_103 = F_98 ( V_21 , V_199 , 0 ) ;
V_15 -> V_88 = F_99 ( & V_21 -> V_22 , V_103 ) ;
if ( F_100 ( V_15 -> V_88 ) )
return F_101 ( V_15 -> V_88 ) ;
V_15 -> V_46 = V_103 -> V_200 + 0x24 ;
V_184 = F_102 ( V_21 , 0 ) ;
if ( V_184 < 0 ) {
F_13 ( & V_21 -> V_22 , L_14 , V_184 ) ;
return V_184 ;
}
V_37 = F_103 ( & V_21 -> V_22 , V_184 , F_93 , V_201 ,
L_15 , V_15 ) ;
if ( V_37 ) {
F_13 ( & V_21 -> V_22 , L_16 ) ;
return V_37 ;
}
if ( V_21 -> V_22 . V_202 )
V_36 = F_94 ( & V_21 -> V_22 ) ;
else
V_36 = F_22 ( & V_21 -> V_22 ) ;
if ( ! V_36 ) {
F_13 ( & V_21 -> V_22 , L_17 ) ;
return - V_203 ;
}
F_104 ( V_21 , V_15 ) ;
V_197 = & V_15 -> V_7 ;
V_196 = F_105 ( V_197 ) ;
F_106 ( V_197 , V_21 -> V_22 . V_202 ) ;
V_196 -> V_22 . V_204 = & V_21 -> V_22 ;
V_15 -> V_21 = V_21 ;
V_15 -> V_150 = V_36 -> V_193 ;
V_15 -> V_164 = V_36 -> V_194 ;
V_15 -> V_108 = V_36 -> V_107 ;
V_15 -> V_16 = V_15 -> V_150 ? ( V_205 | V_206 ) : V_205 ;
V_197 -> V_207 = 20 ;
V_197 -> V_208 = F_88 ;
V_197 -> V_209 = F_89 ;
V_197 -> V_136 = F_87 ;
V_197 -> V_132 = F_90 ;
V_197 -> V_210 = F_82 ;
V_197 -> V_211 = F_78 ;
V_197 -> V_212 = V_213 ;
V_197 -> V_214 = V_213 ;
if ( V_36 -> V_107 & V_109 )
V_197 -> V_53 |= V_54 ;
F_107 ( & V_21 -> V_22 ) ;
F_108 ( & V_21 -> V_22 ) ;
F_21 ( V_15 ) ;
V_37 = F_109 ( V_196 , 1 , NULL ) ;
if ( V_37 )
goto V_215;
if ( V_197 -> V_53 & V_54 ) {
V_36 -> V_107 |= V_109 ;
V_15 -> V_108 = V_36 -> V_107 ;
}
V_37 = F_91 ( V_196 ) ;
if ( V_37 )
goto V_215;
V_37 = F_110 ( V_196 ) ;
if ( V_37 )
goto V_215;
V_37 = F_111 ( V_196 , V_36 -> V_216 , V_36 -> V_217 ) ;
return 0 ;
V_215:
F_19 ( V_15 ) ;
F_112 ( & V_21 -> V_22 ) ;
return V_37 ;
}
static int F_113 ( struct V_34 * V_21 )
{
struct V_14 * V_15 = F_114 ( V_21 ) ;
F_19 ( V_15 ) ;
F_115 ( F_105 ( & V_15 -> V_7 ) ) ;
F_112 ( & V_21 -> V_22 ) ;
return 0 ;
}
