static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 ( & V_2 -> V_6 , L_1 ) ;
V_6 = F_3 ( sizeof( struct V_3 ) ) ;
if ( ! V_6 )
return - V_7 ;
V_4 = F_4 ( V_6 ) ;
V_2 -> V_8 = V_6 ;
V_4 -> V_9 = V_2 ;
F_5 ( & V_4 -> V_10 ) ;
V_2 -> V_11 [ 0 ] -> V_12 = 16 ;
V_2 -> V_11 [ 0 ] -> V_13 |= V_14 ;
V_2 -> V_15 |= V_16 ;
V_2 -> V_17 = 1 ;
V_6 -> V_18 = & V_19 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_22 = & V_23 ;
return F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_6 , L_2 ) ;
F_8 ( V_6 ) ;
F_9 ( V_2 ) ;
F_10 ( V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
T_1 * V_24 ;
int V_25 , V_26 , V_27 , V_28 = 0 , V_29 ;
unsigned int V_30 ;
static const char * const V_31 [] = { L_3 , L_4 , L_5 , L_6 } ;
T_2 * V_32 ;
T_3 V_33 ;
F_2 ( & V_2 -> V_6 , L_7 ) ;
V_24 = ( T_1 * ) V_6 -> V_34 ;
if ( V_2 -> V_35 != V_36 )
F_11 ( & V_2 -> V_6 , L_8 ) ;
V_28 = ( V_2 -> V_37 == V_38 ) ;
V_2 -> V_39 = 16 ;
for ( V_26 = V_27 = 0 ; V_27 < 0x400 ; V_27 += 0x10 ) {
if ( V_28 && ( V_27 & 0x80 ) )
continue;
V_2 -> V_11 [ 0 ] -> V_40 = V_27 ^ 0x300 ;
V_26 = F_12 ( V_2 ) ;
if ( V_26 == 0 )
break;
}
if ( V_26 != 0 )
goto V_41;
V_25 = F_13 ( V_2 , V_42 ) ;
if ( V_25 )
goto V_41;
V_25 = F_14 ( V_2 ) ;
if ( V_25 )
goto V_41;
V_6 -> V_43 = V_2 -> V_43 ;
V_6 -> V_44 = V_2 -> V_11 [ 0 ] -> V_40 ;
V_30 = V_6 -> V_44 ;
F_15 ( 0 ) ;
V_33 = F_16 ( V_2 , 0x88 , & V_32 ) ;
if ( V_32 && V_33 >= 6 ) {
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ )
V_24 [ V_26 ] = F_17 ( F_18 ( V_32 [ V_26 * 2 ] ) ) ;
F_19 ( V_32 ) ;
} else {
F_19 ( V_32 ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ )
V_24 [ V_26 ] = F_17 ( F_20 ( V_30 , V_26 ) ) ;
if ( V_24 [ 0 ] == F_17 ( 0x6060 ) ) {
F_21 ( & V_2 -> V_6 , L_9 ,
V_6 -> V_44 , V_6 -> V_44 + 15 ) ;
goto V_41;
}
}
F_22 ( 0x3f00 , V_30 + 8 ) ;
V_29 = F_23 ( V_30 ) ;
if ( ( V_45 >= 0 ) && ( V_45 <= 3 ) )
V_6 -> V_45 = V_45 ;
else
F_21 ( & V_2 -> V_6 , L_10 ) ;
F_24 ( V_6 , & V_2 -> V_6 ) ;
if ( F_25 ( V_6 ) != 0 ) {
F_21 ( & V_2 -> V_6 , L_11 ) ;
goto V_41;
}
F_26 ( V_6 , L_12 ,
( V_28 ? L_13 : L_14 ) , V_6 -> V_44 , V_6 -> V_43 ,
V_6 -> V_34 ) ;
F_26 ( V_6 , L_15 ,
( V_29 & 7 ) ? 32 : 8 , V_31 [ ( V_29 >> 16 ) & 3 ] ,
V_46 [ V_6 -> V_45 ] ) ;
return 0 ;
V_41:
F_9 ( V_2 ) ;
return - V_47 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_48 )
F_29 ( V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_48 ) {
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
}
return 0 ;
}
static void F_33 ( struct V_5 * V_6 , int V_49 )
{
int V_26 = 100 ;
F_22 ( V_49 , V_6 -> V_44 + V_50 ) ;
while ( -- V_26 > 0 )
if ( ! ( F_34 ( V_6 -> V_44 + V_51 ) & 0x1000 ) )
break;
if ( V_26 == 0 )
F_35 ( V_6 , L_16 , V_49 ) ;
}
static T_4 F_20 ( unsigned int V_30 , int V_52 )
{
int V_26 ;
F_22 ( V_53 + V_52 , V_30 + 10 ) ;
for ( V_26 = 1620 ; V_26 >= 0 ; V_26 -- )
if ( ( F_34 ( V_30 + 10 ) & V_54 ) == 0 )
break;
return F_34 ( V_30 + 12 ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_45 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_30 = V_6 -> V_44 ;
F_15 ( 0 ) ;
switch ( V_45 ) {
case 0 :
case 1 :
F_22 ( 0 , V_30 + 6 ) ;
break;
case 2 :
F_22 ( 3 << 14 , V_30 + 6 ) ;
break;
case 3 :
F_22 ( 1 << 14 , V_30 + 6 ) ;
break;
}
F_22 ( ( V_45 == 2 ) ? V_55 : V_56 , V_30 + V_50 ) ;
F_15 ( 4 ) ;
F_22 ( V_57 | ( ( V_45 < 2 ) ? V_58 : 0 ) , V_30 + V_59 ) ;
F_15 ( 1 ) ;
if ( V_45 == 2 )
V_4 -> V_60 = ( ( V_6 -> V_45 == 0 ) ? 0x8000 : 0x4000 ) ;
else
V_4 -> V_60 = ( ( V_6 -> V_45 == 0 ) ? 0x4010 : 0x8800 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
F_15 ( 1 ) ;
F_26 ( V_6 , L_17 ,
F_34 ( V_30 + V_51 ) , F_34 ( V_30 + V_61 ) ,
F_38 ( V_30 + V_62 ) , F_34 ( V_30 + V_63 ) ) ;
F_15 ( 4 ) ;
F_26 ( V_6 , L_18 ,
F_34 ( V_30 + 0x04 ) , F_34 ( V_30 + 0x06 ) , F_34 ( V_30 + 0x08 ) ,
F_34 ( V_30 + 0x0a ) ) ;
F_15 ( 1 ) ;
}
static void F_31 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
int V_26 ;
F_15 ( 0 ) ;
F_22 ( 0x0001 , V_30 + 4 ) ;
F_22 ( 0x3f00 , V_30 + 8 ) ;
F_15 ( 2 ) ;
for ( V_26 = 0 ; V_26 < 6 ; V_26 ++ )
F_39 ( V_6 -> V_34 [ V_26 ] , V_30 + V_26 ) ;
F_36 ( V_6 , V_6 -> V_45 ) ;
F_22 ( V_64 , V_30 + V_50 ) ;
F_15 ( 6 ) ;
for ( V_26 = 0 ; V_26 < 9 ; V_26 ++ )
F_38 ( V_30 + V_26 ) ;
F_34 ( V_30 + 10 ) ;
F_34 ( V_30 + 12 ) ;
F_15 ( 1 ) ;
F_40 ( V_6 ) ;
F_22 ( V_65 , V_30 + V_50 ) ;
F_22 ( V_66 , V_30 + V_50 ) ;
F_22 ( V_67 , V_30 + V_50 ) ;
F_22 ( V_68 | 0xff , V_30 + V_50 ) ;
F_22 ( V_69 | V_70 | V_71 | V_72 | V_73 ,
V_30 + V_50 ) ;
F_22 ( V_74 | V_70 | V_71 | V_75 | V_76
| V_77 , V_30 + V_50 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
F_42 ( V_79 -> V_80 , V_81 , sizeof( V_79 -> V_80 ) ) ;
F_42 ( V_79 -> V_82 , V_83 , sizeof( V_79 -> V_82 ) ) ;
snprintf ( V_79 -> V_84 , sizeof( V_79 -> V_84 ) ,
L_19 , V_6 -> V_44 ) ;
}
static int F_43 ( struct V_5 * V_6 , struct V_85 * V_86 )
{
if ( ( V_86 -> V_87 != ( V_88 ) ( - 1 ) ) && ( V_86 -> V_87 != V_6 -> V_45 ) ) {
if ( V_86 -> V_87 <= 3 ) {
V_6 -> V_45 = V_86 -> V_87 ;
F_26 ( V_6 , L_20 , V_46 [ V_6 -> V_45 ] ) ;
F_36 ( V_6 , V_6 -> V_45 ) ;
} else {
return - V_89 ;
}
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
if ( ! F_45 ( V_2 ) )
return - V_47 ;
V_2 -> V_48 ++ ;
F_46 ( V_6 ) ;
F_31 ( V_6 ) ;
F_47 ( & V_4 -> V_90 ) ;
V_4 -> V_90 . V_91 = V_92 ;
V_4 -> V_90 . V_93 = ( unsigned long ) V_6 ;
V_4 -> V_90 . V_94 = V_95 + V_96 ;
F_48 ( & V_4 -> V_90 ) ;
F_2 ( & V_2 -> V_6 , L_21 ,
V_6 -> V_97 , F_34 ( V_6 -> V_44 + V_51 ) ) ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
F_35 ( V_6 , L_22 ) ;
F_37 ( V_6 ) ;
V_6 -> V_98 . V_99 ++ ;
V_6 -> V_100 = V_95 ;
F_33 ( V_6 , V_101 ) ;
F_22 ( V_67 , V_30 + V_50 ) ;
F_50 ( V_6 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
int V_26 ;
for ( V_26 = 32 ; V_26 > 0 ; V_26 -- ) {
V_88 V_102 = F_38 ( V_30 + V_62 ) ;
if ( ! ( V_102 & 0x84 ) )
break;
if ( V_102 & 0x30 )
F_33 ( V_6 , V_101 ) ;
if ( V_102 & 0x38 ) {
F_52 ( V_6 , L_23 , V_102 ) ;
F_22 ( V_67 , V_30 + V_50 ) ;
V_6 -> V_98 . V_103 ++ ;
}
F_39 ( 0x00 , V_30 + V_62 ) ;
}
}
static T_5 F_53 ( struct V_104 * V_105 ,
struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
struct V_3 * V_8 = F_4 ( V_6 ) ;
unsigned long V_13 ;
F_52 ( V_6 , L_24 ,
( long ) V_105 -> V_33 , F_34 ( V_30 + V_51 ) ) ;
F_54 ( & V_8 -> V_10 , V_13 ) ;
V_6 -> V_98 . V_106 += V_105 -> V_33 ;
F_22 ( V_105 -> V_33 , V_30 + V_107 ) ;
F_22 ( 0x00 , V_30 + V_107 ) ;
F_55 ( V_30 + V_107 , V_105 -> V_93 , ( V_105 -> V_33 + 3 ) >> 2 ) ;
if ( F_34 ( V_30 + V_63 ) <= 1536 ) {
F_56 ( V_6 ) ;
F_22 ( V_108 + 1536 , V_30 + V_50 ) ;
}
F_51 ( V_6 ) ;
F_57 ( & V_8 -> V_10 , V_13 ) ;
F_58 ( V_105 ) ;
return V_109 ;
}
static T_6 V_42 ( int V_43 , void * V_110 )
{
struct V_5 * V_6 = (struct V_5 * ) V_110 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_30 ;
T_7 V_111 ;
int V_26 = 0 , V_112 = 1 ;
if ( ! F_59 ( V_6 ) )
return V_113 ;
V_30 = V_6 -> V_44 ;
F_52 ( V_6 , L_25 , F_34 ( V_30 + V_51 ) ) ;
F_60 ( & V_4 -> V_10 ) ;
while ( ( V_111 = F_34 ( V_30 + V_51 ) ) &
( V_70 | V_75 | V_76 ) ) {
if ( ( V_111 & 0xe000 ) != 0x2000 ) {
F_52 ( V_6 , L_26 ) ;
V_112 = 0 ;
break;
}
if ( V_111 & V_75 )
F_61 ( V_6 ) ;
if ( V_111 & V_71 ) {
F_52 ( V_6 , L_27 ) ;
F_22 ( V_69 | V_71 , V_30 + V_50 ) ;
F_50 ( V_6 ) ;
}
if ( V_111 & V_114 )
F_51 ( V_6 ) ;
if ( V_111 & ( V_77 | V_72 | V_76 ) ) {
if ( V_111 & V_76 )
F_62 ( V_6 ) ;
if ( V_111 & V_72 ) {
F_61 ( V_6 ) ;
F_22 ( V_69 | V_72 , V_30 + V_50 ) ;
}
if ( V_111 & V_77 ) {
T_4 V_115 ;
F_15 ( 4 ) ;
V_115 = F_34 ( V_30 + 4 ) ;
F_15 ( 1 ) ;
F_35 ( V_6 , L_28 ,
V_115 ) ;
if ( V_115 & 0x0400 ) {
F_33 ( V_6 , V_101 ) ;
F_22 ( V_67 , V_30 + V_50 ) ;
}
if ( V_115 & 0x2000 ) {
F_33 ( V_6 , V_116 ) ;
F_40 ( V_6 ) ;
F_22 ( V_66 , V_30 + V_50 ) ;
}
F_22 ( V_69 | V_77 , V_30 + V_50 ) ;
}
}
if ( ++ V_26 > 10 ) {
F_63 ( V_6 , L_29 ,
V_111 ) ;
F_22 ( V_69 | 0xFF , V_30 + V_50 ) ;
break;
}
F_22 ( V_69 | V_73 | V_70 , V_30 + V_50 ) ;
}
V_4 -> V_117 = V_95 ;
F_64 ( & V_4 -> V_10 ) ;
F_52 ( V_6 , L_30 ,
F_34 ( V_30 + V_51 ) ) ;
return F_65 ( V_112 ) ;
}
static void V_92 ( unsigned long V_118 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_118 ) ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_30 = V_6 -> V_44 ;
T_4 V_90 , V_119 ;
unsigned long V_13 ;
if ( ! F_59 ( V_6 ) )
goto V_120;
if ( ( F_34 ( V_30 + V_51 ) & V_70 ) &&
( F_38 ( V_30 + V_121 ) == 0xff ) ) {
if ( ! V_4 -> V_122 )
F_35 ( V_6 , L_31 ) ;
F_66 ( V_13 ) ;
V_42 ( V_6 -> V_43 , V_6 ) ;
F_67 ( V_13 ) ;
V_4 -> V_122 = V_96 ;
}
if ( V_4 -> V_122 ) {
V_4 -> V_122 -- ;
V_4 -> V_90 . V_94 = V_95 + V_96 / 100 ;
F_48 ( & V_4 -> V_90 ) ;
return;
}
F_54 ( & V_4 -> V_10 , V_13 ) ;
F_15 ( 4 ) ;
V_90 = F_34 ( V_30 + V_59 ) & 0xc810 ;
if ( F_68 ( V_95 , V_4 -> V_117 + V_96 ) ) {
V_90 &= ~ 0x0010 ;
} else {
F_15 ( 6 ) ;
F_22 ( V_64 , V_30 + V_50 ) ;
V_119 = F_38 ( V_30 + 0 ) ;
F_22 ( V_65 , V_30 + V_50 ) ;
V_6 -> V_98 . V_123 += V_119 ;
if ( V_119 || ( V_4 -> V_60 & 0x0010 ) )
V_90 |= 0x0010 ;
}
if ( V_90 != V_4 -> V_60 ) {
if ( ( V_90 & V_4 -> V_60 & 0x8000 ) &&
( ( V_4 -> V_60 ^ V_90 ) & 0x0800 ) )
F_26 ( V_6 , L_32 ,
( V_4 -> V_60 & 0x0800 ? L_33 : L_34 ) ) ;
else if ( ( V_90 & V_4 -> V_60 & 0x4000 ) &&
( ( V_4 -> V_60 ^ V_90 ) & 0x0010 ) )
F_26 ( V_6 , L_35 ,
( V_4 -> V_60 & 0x0010 ? L_36 : L_37 ) ) ;
if ( V_6 -> V_45 == 0 ) {
if ( V_90 & 0x8000 ) {
if ( V_90 & 0x0800 )
F_26 ( V_6 , L_38 ) ;
else
F_36 ( V_6 , 2 ) ;
} else if ( V_90 & 0x4000 ) {
if ( V_90 & 0x0010 )
F_36 ( V_6 , 1 ) ;
else
F_26 ( V_6 , L_39 ) ;
}
}
V_4 -> V_60 = V_90 ;
}
F_15 ( 1 ) ;
F_57 ( & V_4 -> V_10 , V_13 ) ;
V_120:
V_4 -> V_90 . V_94 = V_95 + V_96 ;
F_48 ( & V_4 -> V_90 ) ;
}
static struct V_124 * F_69 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned long V_13 ;
struct V_1 * V_2 = V_4 -> V_9 ;
if ( F_45 ( V_2 ) ) {
F_54 ( & V_4 -> V_10 , V_13 ) ;
F_62 ( V_6 ) ;
F_57 ( & V_4 -> V_10 , V_13 ) ;
}
return & V_6 -> V_98 ;
}
static void F_62 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
F_52 ( V_6 , L_40 ) ;
F_22 ( V_64 , V_30 + V_50 ) ;
F_15 ( 6 ) ;
V_6 -> V_98 . V_123 += F_38 ( V_30 + 0 ) ;
V_6 -> V_98 . V_125 += F_38 ( V_30 + 1 ) ;
F_38 ( V_30 + 2 ) ;
V_6 -> V_98 . V_126 += F_38 ( V_30 + 3 ) ;
V_6 -> V_98 . V_127 += F_38 ( V_30 + 4 ) ;
V_6 -> V_98 . V_128 += F_38 ( V_30 + 5 ) ;
V_6 -> V_98 . V_129 += F_38 ( V_30 + 6 ) ;
F_38 ( V_30 + 7 ) ;
F_38 ( V_30 + 8 ) ;
F_34 ( V_30 + 10 ) ;
F_34 ( V_30 + 12 ) ;
F_15 ( 1 ) ;
F_22 ( V_65 , V_30 + V_50 ) ;
}
static int F_61 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
int V_130 = 32 ;
short V_131 ;
F_52 ( V_6 , L_41 ,
F_34 ( V_30 + V_51 ) , F_34 ( V_30 + V_61 ) ) ;
while ( ! ( ( V_131 = F_34 ( V_30 + V_61 ) ) & 0x8000 ) &&
V_130 > 0 ) {
V_130 -- ;
if ( V_131 & 0x4000 ) {
short error = V_131 & 0x3800 ;
V_6 -> V_98 . V_132 ++ ;
switch ( error ) {
case 0x0000 :
V_6 -> V_98 . V_133 ++ ;
break;
case 0x0800 :
V_6 -> V_98 . V_134 ++ ;
break;
case 0x1000 :
V_6 -> V_98 . V_135 ++ ;
break;
case 0x1800 :
V_6 -> V_98 . V_134 ++ ;
break;
case 0x2000 :
V_6 -> V_98 . V_135 ++ ;
break;
case 0x2800 :
V_6 -> V_98 . V_136 ++ ;
break;
}
} else {
short V_137 = V_131 & 0x7ff ;
struct V_104 * V_105 ;
V_105 = F_70 ( V_6 , V_137 + 5 ) ;
F_52 ( V_6 , L_42 ,
V_137 , V_131 ) ;
if ( V_105 != NULL ) {
F_71 ( V_105 , 2 ) ;
F_72 ( V_30 + V_138 , F_73 ( V_105 , V_137 ) ,
( V_137 + 3 ) >> 2 ) ;
V_105 -> V_139 = F_74 ( V_105 , V_6 ) ;
F_75 ( V_105 ) ;
V_6 -> V_98 . V_140 ++ ;
V_6 -> V_98 . V_141 += V_137 ;
} else {
F_52 ( V_6 , L_43 ,
V_137 ) ;
V_6 -> V_98 . V_142 ++ ;
}
}
F_33 ( V_6 , V_143 ) ;
}
if ( V_130 == 0 )
F_35 ( V_6 , L_44 ) ;
return 0 ;
}
static void F_40 ( struct V_5 * V_6 )
{
unsigned int V_30 = V_6 -> V_44 ;
T_4 V_144 = V_145 | V_146 | V_147 ;
if ( V_6 -> V_13 & V_148 )
V_144 |= V_149 | V_150 ;
else if ( ! F_76 ( V_6 ) || ( V_6 -> V_13 & V_151 ) )
V_144 |= V_149 ;
F_22 ( V_144 , V_30 + V_50 ) ;
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_3 * V_8 = F_4 ( V_6 ) ;
unsigned long V_13 ;
F_54 ( & V_8 -> V_10 , V_13 ) ;
F_40 ( V_6 ) ;
F_57 ( & V_8 -> V_10 , V_13 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
unsigned int V_30 = V_6 -> V_44 ;
F_2 ( & V_2 -> V_6 , L_45 , V_6 -> V_97 ) ;
if ( F_45 ( V_2 ) ) {
F_22 ( V_64 , V_30 + V_50 ) ;
F_22 ( V_152 , V_30 + V_50 ) ;
F_22 ( V_153 , V_30 + V_50 ) ;
if ( V_6 -> V_45 == 2 )
F_22 ( V_56 , V_30 + V_50 ) ;
else if ( V_6 -> V_45 == 1 ) {
F_15 ( 4 ) ;
F_22 ( 0 , V_30 + V_59 ) ;
}
F_15 ( 0 ) ;
F_22 ( 0x0f00 , V_30 + V_154 ) ;
if ( ( F_34 ( V_30 + V_51 ) & 0xe000 ) == 0x2000 )
F_62 ( V_6 ) ;
}
V_2 -> V_48 -- ;
F_56 ( V_6 ) ;
F_79 ( & V_4 -> V_90 ) ;
return 0 ;
}
