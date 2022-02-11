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
V_20 . V_30 = V_23 -> V_25 ;
V_20 . V_31 = V_32 ;
V_20 . V_33 = ( V_34 ) F_22 ( V_2 ) ;
V_20 . V_35 = 0 ;
V_24 = F_23 ( V_2 -> V_17 , & V_20 ) ;
if ( V_24 < 0 )
goto V_36;
V_2 -> V_16 = F_20 ( V_18 , V_28 ,
( void * ) ( V_29 ) V_23 -> V_26 ) ;
F_21 ( & V_8 -> V_9 , L_3 , V_13 ,
V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_36;
V_20 . V_30 = V_23 -> V_26 ;
V_20 . V_31 = V_37 ;
V_20 . V_33 = 0 ;
V_20 . V_35 = ( V_34 ) F_22 ( V_2 ) ;
V_24 = F_23 ( V_2 -> V_16 , & V_20 ) ;
if ( V_24 < 0 )
goto V_36;
F_24 ( & V_2 -> V_15 ) ;
return;
V_36:
F_14 ( V_2 ) ;
}
static void F_25 ( struct V_38 * V_39 , int V_40 , int V_41 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
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
F_2 ( V_49 , F_27 ( V_2 ) ) ;
}
} else {
V_42 = V_40 ;
V_42 |= ( V_41 & 0xff ) << 8 ;
V_42 |= ( ( V_41 >> 8 ) & 0xff ) << 16 ;
V_42 |= ( ( V_41 >> 16 ) & 0xff ) << 24 ;
}
}
F_2 ( V_42 , F_28 ( V_2 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
T_1 V_50 ;
V_50 = F_30 ( F_31 ( V_2 ) ) >> 16 ;
if ( V_50 & 0xFF )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_51 , V_10 = V_11 ;
while ( V_10 -- ) {
V_51 = ( F_30 ( F_31 ( V_2 ) ) >> 16 ) & 0xFF ;
if ( V_51 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static enum V_52 F_33
( struct V_1 * V_2 , int V_53 )
{
T_1 V_10 = V_11 ;
void T_3 * V_54 [ 4 ] ;
int V_55 ;
int V_56 = V_57 ;
T_1 V_58 , V_59 ;
while ( V_10 -- ) {
V_59 = F_30 ( F_31 ( V_2 ) ) >> 24 ;
if ( ( V_59 & 0xFF ) == 4 )
return V_56 ;
if ( ! ( F_30 ( F_34 ( V_2 ) ) & V_60 ) ) {
F_11 ( 1 ) ;
continue;
}
if ( F_30 ( F_34 ( V_2 ) ) & V_61 ) {
for ( V_55 = 0 ; V_55 < 512 ; V_55 ++ ) {
if ( V_2 -> V_62 [ V_55 ] != 0xff ) {
V_56 = V_63 ;
break;
}
}
if ( V_56 == V_57 )
F_21 ( & V_2 -> V_8 -> V_9 ,
L_4 ,
V_53 ) ;
F_2 ( 0 , F_34 ( V_2 ) ) ;
continue;
}
V_54 [ 0 ] = F_35 ( V_2 ) ;
V_54 [ 1 ] = F_36 ( V_2 ) ;
V_54 [ 2 ] = F_37 ( V_2 ) ;
V_54 [ 3 ] = F_38 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
T_4 V_64 ;
unsigned int V_65 ;
V_58 = F_30 ( V_54 [ V_55 ] ) ;
if ( V_2 -> V_46 )
V_65 = ( 512 * V_53 ) +
( V_58 >> 16 ) ;
else
V_65 = V_58 >> 16 ;
V_64 = V_2 -> V_62 [ V_65 ] ;
V_2 -> V_62 [ V_65 ] = V_64 ^ ( V_58 & 0xFF ) ;
}
V_56 = V_66 ;
F_2 ( 0 , F_34 ( V_2 ) ) ;
}
F_7 ( V_2 , V_13 ) ;
return V_67 ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
T_1 V_51 ;
while ( V_10 -- ) {
V_51 = ( F_30 ( F_31 ( V_2 ) ) >> 24 ) & 0xFF ;
if ( V_51 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned long * V_68 ,
int V_51 , enum V_69 V_70 )
{
struct V_71 * V_72 = NULL ;
struct V_73 * V_74 ;
enum V_75 V_76 ;
V_34 V_77 ;
T_5 V_78 = - V_79 ;
T_1 V_80 ;
int V_24 ;
if ( V_70 == V_81 ) {
V_74 = V_2 -> V_16 ;
V_76 = V_37 ;
} else {
V_74 = V_2 -> V_17 ;
V_76 = V_32 ;
}
V_77 = F_41 ( V_74 -> V_82 -> V_9 , V_68 , V_51 , V_70 ) ;
if ( V_77 )
V_72 = F_42 ( V_74 , V_77 , V_51 ,
V_76 , V_83 | V_84 ) ;
if ( V_72 ) {
V_80 = F_30 ( F_3 ( V_2 ) ) ;
V_80 |= V_85 ;
F_2 ( V_80 , F_3 ( V_2 ) ) ;
V_72 -> V_86 = F_12 ;
V_72 -> V_87 = V_2 ;
V_78 = F_43 ( V_72 ) ;
F_44 ( V_74 ) ;
} else {
F_14 ( V_2 ) ;
F_45 ( & V_2 -> V_8 -> V_9 ,
L_5 ) ;
V_24 = - V_88 ;
goto V_89;
}
V_24 =
F_46 ( & V_2 -> V_15 ,
F_47 ( 3000 ) ) ;
if ( V_24 <= 0 ) {
F_48 ( V_74 ) ;
F_8 ( & V_2 -> V_8 -> V_9 , L_6 ) ;
}
V_89:
V_80 = F_30 ( F_3 ( V_2 ) ) ;
V_80 &= ~ V_85 ;
F_2 ( V_80 , F_3 ( V_2 ) ) ;
F_49 ( V_74 -> V_82 -> V_9 , V_77 , V_51 , V_70 ) ;
return V_24 ;
}
static void F_50 ( struct V_1 * V_2 , int V_90 )
{
unsigned long V_58 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_90 ] ;
F_9 ( V_2 ) ;
V_58 = F_30 ( F_51 ( V_2 ) ) ;
* V_68 = F_52 ( V_58 ) ;
}
static void F_53 ( struct V_1 * V_2 , int V_91 , int V_90 )
{
int V_55 , V_92 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_90 ] ;
V_92 = ( V_91 + 3 ) / 4 ;
if ( V_2 -> V_16 && V_91 >= 32 &&
F_40 ( V_2 , V_68 , V_91 , V_37 ) > 0 )
goto V_93;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ ) {
F_29 ( V_2 ) ;
V_68 [ V_55 ] = F_30 ( F_22 ( V_2 ) ) ;
}
V_93:
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ )
V_68 [ V_55 ] = F_54 ( V_68 [ V_55 ] ) ;
}
static enum V_52 F_55
( struct V_1 * V_2 , T_4 * V_94 , int V_95 )
{
int V_55 ;
enum V_52 V_96 ;
unsigned long * V_97 = ( unsigned long * ) V_94 ;
V_96 = F_33 ( V_2 , V_95 ) ;
if ( V_96 != V_63 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
V_97 [ V_55 ] = F_30 ( F_56 ( V_2 ) ) ;
V_97 [ V_55 ] = F_54 ( V_97 [ V_55 ] ) ;
}
}
return V_96 ;
}
static void F_57 ( struct V_1 * V_2 , int V_91 ,
unsigned int V_90 )
{
int V_55 , V_92 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_90 ] ;
V_92 = ( V_91 + 3 ) / 4 ;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ ) {
F_32 ( V_2 ) ;
F_2 ( F_58 ( V_68 [ V_55 ] ) , F_22 ( V_2 ) ) ;
}
}
static void F_59 ( struct V_1 * V_2 , int V_91 ,
unsigned int V_90 )
{
int V_55 , V_92 ;
unsigned long * V_68 = ( unsigned long * ) & V_2 -> V_62 [ V_90 ] ;
V_92 = ( V_91 + 3 ) / 4 ;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ )
V_68 [ V_55 ] = F_58 ( V_68 [ V_55 ] ) ;
if ( V_2 -> V_17 && V_91 >= 32 &&
F_40 ( V_2 , V_68 , V_91 , V_32 ) > 0 )
return;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ ) {
F_39 ( V_2 ) ;
F_2 ( V_68 [ V_55 ] , F_56 ( V_2 ) ) ;
}
}
static void F_60 ( struct V_38 * V_39 , T_1 V_98 , T_1 V_99 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
T_1 V_100 = V_2 -> V_101 & ~ V_102 ;
T_1 V_103 , V_104 = 0 ;
if ( V_2 -> V_46 )
V_100 |= V_105 ;
else
V_100 &= ~ V_105 ;
V_103 = V_106 | V_107 ;
switch ( V_98 ) {
case V_108 :
V_104 = V_2 -> V_109 ;
V_103 |= V_110 ;
break;
case V_111 :
case V_112 :
case V_113 :
V_104 = V_2 -> V_47 ;
V_103 |= V_114 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_100 |= V_102 ;
break;
case V_115 :
V_103 &= ~ V_107 ;
break;
case V_116 :
V_104 = V_2 -> V_47 ;
V_103 |= V_110 | V_114 | V_117 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_100 |= V_102 ;
break;
case V_118 :
V_100 &= ~ V_105 ;
V_103 |= V_114 ;
V_104 = V_119 ;
break;
case V_120 :
case V_121 :
V_100 &= ~ V_105 ;
V_103 &= ~ ( V_107 | V_122 ) ;
break;
default:
break;
}
V_103 |= V_104 ;
F_2 ( V_100 , F_61 ( V_2 ) ) ;
F_2 ( V_103 , F_62 ( V_2 ) ) ;
F_2 ( V_99 , F_63 ( V_2 ) ) ;
}
static int F_64 ( struct V_38 * V_39 , struct V_123 * V_43 ,
T_4 * V_68 , int V_124 , int V_125 )
{
V_43 -> V_126 ( V_39 , V_68 , V_39 -> V_127 ) ;
if ( V_124 )
V_43 -> V_126 ( V_39 , V_43 -> V_128 , V_39 -> V_129 ) ;
return 0 ;
}
static int F_65 ( struct V_38 * V_39 , struct V_123 * V_43 ,
const T_4 * V_68 , int V_124 )
{
V_43 -> V_130 ( V_39 , V_68 , V_39 -> V_127 ) ;
V_43 -> V_130 ( V_39 , V_43 -> V_128 , V_39 -> V_129 ) ;
return 0 ;
}
static void F_66 ( struct V_38 * V_39 , int V_41 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_95 , V_131 ;
enum V_52 V_132 ;
V_131 = V_2 -> V_46 ? 4 : 1 ;
F_60 ( V_39 , V_111 ,
( V_133 << 8 ) | V_111 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_134 | V_135 ,
F_61 ( V_2 ) ) ;
F_2 ( F_30 ( F_62 ( V_2 ) ) | V_131 , F_62 ( V_2 ) ) ;
F_2 ( V_41 << 2 , F_28 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_95 = 0 ; V_95 < V_131 ; V_95 ++ ) {
F_53 ( V_2 , 512 , 512 * V_95 ) ;
V_132 = F_55 ( V_2 ,
& V_2 -> V_62 [ V_39 -> V_127 + 16 * V_95 ] ,
V_95 ) ;
switch ( V_132 ) {
case V_66 :
F_67 ( & V_2 -> V_8 -> V_9 ,
L_7 , V_41 ) ;
V_2 -> V_39 . V_136 . V_137 ++ ;
break;
case V_63 :
F_45 ( & V_2 -> V_8 -> V_9 ,
L_8 ,
V_41 ) ;
V_2 -> V_39 . V_136 . V_138 ++ ;
break;
default:
;
}
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) & ~ ( V_134 | V_135 ) ,
F_61 ( V_2 ) ) ;
}
static void F_68 ( struct V_38 * V_39 , int V_41 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_131 = V_2 -> V_46 ? 4 : 1 ;
int V_55 ;
F_60 ( V_39 , V_111 ,
( V_133 << 8 ) | V_111 ) ;
F_1 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_131 ; V_55 ++ ) {
F_25 ( V_39 , ( 512 + 16 ) * V_55 + 512 , V_41 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , 16 , 16 * V_55 ) ;
F_9 ( V_2 ) ;
}
}
static void F_69 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_41 = V_2 -> V_139 ;
int V_95 , V_131 ;
V_131 = V_2 -> V_46 ? 4 : 1 ;
F_60 ( V_39 , V_116 ,
( V_116 << 8 ) | V_115 ) ;
F_1 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) | V_134 , F_61 ( V_2 ) ) ;
F_2 ( F_30 ( F_62 ( V_2 ) ) | V_131 , F_62 ( V_2 ) ) ;
F_2 ( V_41 << 2 , F_28 ( V_2 ) ) ;
F_4 ( V_2 ) ;
for ( V_95 = 0 ; V_95 < V_131 ; V_95 ++ ) {
F_57 ( V_2 , 512 , 512 * V_95 ) ;
F_59 ( V_2 , 16 , V_39 -> V_127 + 16 * V_95 ) ;
}
F_9 ( V_2 ) ;
F_2 ( F_30 ( F_61 ( V_2 ) ) & ~ V_134 , F_61 ( V_2 ) ) ;
}
static void F_70 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_41 = V_2 -> V_139 ;
int V_95 , V_131 ;
V_131 = V_2 -> V_46 ? 4 : 1 ;
F_60 ( V_39 , V_116 ,
( V_116 << 8 ) | V_115 ) ;
for ( V_95 = 0 ; V_95 < V_131 ; V_95 ++ ) {
F_1 ( V_2 ) ;
F_25 ( V_39 , V_95 * 528 + 512 , V_41 ) ;
F_2 ( 16 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_57 ( V_2 , 16 , 16 * V_95 ) ;
F_9 ( V_2 ) ;
}
}
static void F_71 ( struct V_38 * V_39 , unsigned int V_140 ,
int V_40 , int V_41 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
T_1 V_141 = 0 ;
F_72 ( & V_2 -> V_8 -> V_9 ) ;
V_2 -> V_142 = 0 ;
if ( V_140 != V_116 )
V_2 -> V_65 = 0 ;
switch ( V_140 ) {
case V_143 :
case V_111 :
if ( V_2 -> V_144 ) {
F_66 ( V_39 , V_41 ) ;
break;
}
if ( V_2 -> V_46 )
F_60 ( V_39 , V_140 , ( V_133 << 8 )
| V_140 ) ;
else
F_60 ( V_39 , V_140 , V_140 ) ;
F_25 ( V_39 , 0 , V_41 ) ;
V_2 -> V_142 = V_39 -> V_127 + V_39 -> V_129 ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_40 >>= 1 ;
V_2 -> V_65 += V_40 ;
goto V_145;
case V_112 :
if ( V_2 -> V_144 ) {
F_68 ( V_39 , V_41 ) ;
break;
}
if ( V_2 -> V_46 ) {
F_60 ( V_39 , V_140 , ( V_133 << 8 )
| V_111 ) ;
F_25 ( V_39 , V_39 -> V_127 , V_41 ) ;
} else {
F_60 ( V_39 , V_140 , V_140 ) ;
F_25 ( V_39 , 0 , V_41 ) ;
}
V_2 -> V_142 = V_39 -> V_129 ;
goto V_145;
case V_113 :
if ( V_2 -> V_144 )
break;
if ( V_2 -> V_46 )
F_60 ( V_39 , V_140 , ( V_146 << 8 )
| V_140 ) ;
else
F_60 ( V_39 , V_140 , V_140 ) ;
F_25 ( V_39 , V_40 , 0 ) ;
V_2 -> V_142 = V_39 -> V_127 + V_39 -> V_129 - V_40 ;
goto V_145;
case V_118 :
F_60 ( V_39 , V_140 , V_140 ) ;
if ( V_2 -> V_43 . V_44 & V_45 )
V_40 <<= 1 ;
F_25 ( V_39 , V_40 , 0 ) ;
V_2 -> V_142 = 8 ;
F_2 ( V_2 -> V_142 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , V_2 -> V_142 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_108 :
V_2 -> V_147 = V_41 ;
break;
case V_148 :
F_60 ( V_39 , V_108 ,
( V_140 << 8 ) | V_108 ) ;
F_25 ( V_39 , - 1 , V_2 -> V_147 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_115 :
if ( ! V_2 -> V_46 ) {
if ( V_40 >= V_39 -> V_127 ) {
V_40 -= V_39 -> V_127 ;
V_141 = V_112 ;
} else if ( V_40 < 256 ) {
V_141 = V_111 ;
} else {
V_40 -= 256 ;
V_141 = V_143 ;
}
}
V_2 -> V_149 = V_40 ;
V_2 -> V_139 = V_41 ;
V_2 -> V_150 = V_141 ;
break;
case V_116 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_46 ) {
F_60 ( V_39 , V_115 ,
V_2 -> V_150 ) ;
F_25 ( V_39 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_144 ) {
if ( V_2 -> V_149 == V_39 -> V_127 )
F_70 ( V_39 ) ;
else if ( ! V_2 -> V_149 )
F_69 ( V_39 ) ;
else
F_73 ( V_151 L_9 ) ;
break;
}
F_60 ( V_39 , V_140 , ( V_140 << 8 ) | V_115 ) ;
F_25 ( V_39 , V_2 -> V_149 , V_2 -> V_139 ) ;
F_2 ( V_2 -> V_65 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_57 ( V_2 , V_2 -> V_65 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_120 :
F_60 ( V_39 , V_140 , V_140 ) ;
F_25 ( V_39 , - 1 , - 1 ) ;
V_2 -> V_142 = 1 ;
F_2 ( V_2 -> V_142 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_50 ( V_2 , 0 ) ;
break;
case V_121 :
F_60 ( V_39 , V_140 , V_140 ) ;
F_25 ( V_39 , - 1 , - 1 ) ;
F_2 ( 0 , F_31 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_152;
V_145:
F_2 ( V_2 -> V_142 , F_31 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_53 ( V_2 , V_2 -> V_142 , 0 ) ;
F_9 ( V_2 ) ;
V_152:
F_74 ( & V_2 -> V_8 -> V_9 ) ;
return;
}
static void F_75 ( struct V_38 * V_39 , int V_153 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
int V_24 ;
switch ( V_153 ) {
case - 1 :
V_2 -> V_101 &= ~ V_154 ;
F_72 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_2 -> V_101 , F_61 ( V_2 ) ) ;
if ( V_2 -> V_155 ) {
F_76 ( & V_2 -> V_156 ) ;
V_2 -> V_155 = 0 ;
}
F_74 ( & V_2 -> V_8 -> V_9 ) ;
break;
case 0 :
V_2 -> V_101 |= V_154 ;
if ( ! V_2 -> V_155 ) {
V_24 = F_77 ( & V_2 -> V_8 -> V_9 ,
& V_2 -> V_156 ,
V_157 ,
100 ) ;
if ( V_24 < 0 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_10 , V_24 ) ;
V_2 -> V_155 = 1 ;
}
if ( V_2 -> V_158 ) {
F_72 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_159 , F_78 ( V_2 ) ) ;
F_74 ( & V_2 -> V_8 -> V_9 ) ;
}
break;
default:
F_79 () ;
}
}
static void F_80 ( struct V_38 * V_39 , const T_4 * V_68 , int V_51 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
memcpy ( & V_2 -> V_62 [ V_2 -> V_65 ] , V_68 , V_51 ) ;
V_2 -> V_65 += V_51 ;
}
static T_4 F_81 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
T_4 V_58 ;
V_58 = V_2 -> V_62 [ V_2 -> V_65 ] ;
V_2 -> V_65 ++ ;
return V_58 ;
}
static T_6 F_82 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
T_6 * V_68 = ( T_6 * ) & V_2 -> V_62 [ V_2 -> V_65 ] ;
V_2 -> V_65 += 2 ;
return * V_68 ;
}
static void F_83 ( struct V_38 * V_39 , T_4 * V_68 , int V_51 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
memcpy ( V_68 , & V_2 -> V_62 [ V_2 -> V_65 ] , V_51 ) ;
V_2 -> V_65 += V_51 ;
}
static int F_84 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
struct V_123 * V_43 = & V_2 -> V_43 ;
if ( V_39 -> V_127 == 512 ) {
V_2 -> V_46 = 0 ;
if ( V_43 -> V_160 > ( 32 << 20 ) ) {
V_2 -> V_47 = V_161 ;
V_2 -> V_109 = V_162 ;
} else if ( V_43 -> V_160 > ( 2 << 16 ) ) {
V_2 -> V_47 = V_162 ;
V_2 -> V_109 = V_163 ;
} else {
V_2 -> V_47 = V_163 ;
V_2 -> V_109 = V_119 ;
}
} else {
V_2 -> V_46 = 1 ;
if ( V_43 -> V_160 > ( 128 << 20 ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_109 = V_162 ;
} else if ( V_43 -> V_160 > ( 8 << 16 ) ) {
V_2 -> V_47 = V_161 ;
V_2 -> V_109 = V_163 ;
} else {
V_2 -> V_47 = V_162 ;
V_2 -> V_109 = V_119 ;
}
}
if ( V_2 -> V_144 ) {
if ( V_39 -> V_127 == 512 ) {
V_43 -> V_164 . V_165 = & V_166 ;
V_43 -> V_167 = & V_168 ;
} else {
V_43 -> V_164 . V_165 = & V_169 ;
V_43 -> V_167 = & V_170 ;
}
V_43 -> V_164 . V_59 = 512 ;
V_43 -> V_164 . V_171 = 10 ;
V_43 -> V_164 . V_172 = 4 ;
V_43 -> V_164 . V_173 = F_64 ;
V_43 -> V_164 . V_174 = F_65 ;
V_43 -> V_164 . V_175 = V_176 ;
V_2 -> V_101 |= V_177 ;
} else {
V_43 -> V_164 . V_175 = V_178 ;
}
return 0 ;
}
static T_7 F_85 ( int V_179 , void * V_180 )
{
struct V_1 * V_2 = V_180 ;
F_8 ( & V_2 -> V_8 -> V_9 , L_11 , F_30 ( F_3 ( V_2 ) ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
return V_181 ;
}
static struct V_22 * F_86 ( struct V_82 * V_9 )
{
const struct V_182 * V_183 ;
struct V_184 * V_185 ;
struct V_22 * V_23 ;
struct V_186 * V_187 = V_9 -> V_188 ;
int V_24 ;
V_183 = F_87 ( V_189 , V_9 ) ;
if ( V_183 )
V_185 = (struct V_184 * ) V_183 -> V_58 ;
else {
F_8 ( V_9 , L_12 , V_13 ) ;
return NULL ;
}
V_23 = F_88 ( V_9 , sizeof( struct V_22 ) ,
V_190 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_100 = V_185 -> V_100 ;
V_23 -> V_191 = V_185 -> V_191 ;
V_23 -> V_192 = V_185 -> V_192 ;
V_24 = F_89 ( V_187 ) ;
if ( V_24 == 16 )
V_23 -> V_100 |= V_102 ;
else if ( V_24 != 8 ) {
F_8 ( V_9 , L_13 , V_13 ) ;
return NULL ;
}
return V_23 ;
}
static int F_90 ( struct V_21 * V_8 )
{
struct V_193 * V_96 ;
struct V_1 * V_2 ;
struct V_38 * V_194 ;
struct V_123 * V_195 ;
struct V_22 * V_23 ;
int V_24 ;
int V_179 ;
struct V_196 V_197 = {} ;
V_2 = F_88 ( & V_8 -> V_9 , sizeof( struct V_1 ) , V_190 ) ;
if ( ! V_2 )
return - V_198 ;
V_96 = F_91 ( V_8 , V_199 , 0 ) ;
V_2 -> V_80 = F_92 ( & V_8 -> V_9 , V_96 ) ;
if ( F_93 ( V_2 -> V_80 ) )
return F_94 ( V_2 -> V_80 ) ;
V_179 = F_95 ( V_8 , 0 ) ;
if ( V_179 < 0 ) {
F_8 ( & V_8 -> V_9 , L_14 ) ;
return - V_200 ;
}
V_24 = F_96 ( & V_8 -> V_9 , V_179 , F_85 , V_201 ,
L_15 , V_2 ) ;
if ( V_24 ) {
F_8 ( & V_8 -> V_9 , L_16 ) ;
return V_24 ;
}
if ( V_8 -> V_9 . V_188 )
V_23 = F_86 ( & V_8 -> V_9 ) ;
else
V_23 = F_17 ( & V_8 -> V_9 ) ;
if ( ! V_23 ) {
F_8 ( & V_8 -> V_9 , L_17 ) ;
return - V_79 ;
}
F_97 ( V_8 , V_2 ) ;
V_194 = & V_2 -> V_39 ;
V_195 = & V_2 -> V_43 ;
V_194 -> V_202 = V_195 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_144 = V_23 -> V_191 ;
V_2 -> V_158 = V_23 -> V_192 ;
V_2 -> V_101 = V_23 -> V_100 ;
V_2 -> V_3 = V_2 -> V_144 ? ( V_203 | V_204 ) : V_203 ;
V_195 -> V_205 = 20 ;
V_195 -> V_206 = F_81 ;
V_195 -> V_130 = F_80 ;
V_195 -> V_126 = F_83 ;
V_195 -> V_207 = F_75 ;
V_195 -> V_208 = F_71 ;
if ( V_23 -> V_100 & V_102 ) {
V_195 -> V_44 |= V_45 ;
V_195 -> V_209 = F_82 ;
}
F_98 ( & V_8 -> V_9 ) ;
F_99 ( & V_8 -> V_9 ) ;
F_16 ( V_2 ) ;
V_24 = F_100 ( V_194 , 1 , NULL ) ;
if ( V_24 )
goto V_210;
V_24 = F_84 ( V_194 ) ;
if ( V_24 )
goto V_210;
V_24 = F_101 ( V_194 ) ;
if ( V_24 )
goto V_210;
V_197 . V_188 = V_8 -> V_9 . V_188 ;
V_24 = F_102 ( V_194 , NULL , & V_197 , V_23 -> V_211 ,
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
F_106 ( & V_2 -> V_39 ) ;
F_103 ( & V_8 -> V_9 ) ;
return 0 ;
}
