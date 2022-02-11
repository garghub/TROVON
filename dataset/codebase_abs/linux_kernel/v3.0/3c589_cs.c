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
F_6 ( V_6 , & V_22 ) ;
return F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_6 , L_2 ) ;
F_9 ( V_6 ) ;
F_10 ( V_2 ) ;
F_11 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
T_1 * V_23 ;
int V_24 , V_25 , V_26 , V_27 = 0 , V_28 ;
unsigned int V_29 ;
static const char * const V_30 [] = { L_3 , L_4 , L_5 , L_6 } ;
T_2 * V_31 ;
T_3 V_32 ;
F_2 ( & V_2 -> V_6 , L_7 ) ;
V_23 = ( T_1 * ) V_6 -> V_33 ;
if ( V_2 -> V_34 != V_35 )
F_12 ( & V_2 -> V_6 , L_8 ) ;
V_27 = ( V_2 -> V_36 == V_37 ) ;
V_2 -> V_38 = 16 ;
for ( V_25 = V_26 = 0 ; V_26 < 0x400 ; V_26 += 0x10 ) {
if ( V_27 && ( V_26 & 0x80 ) ) continue;
V_2 -> V_11 [ 0 ] -> V_39 = V_26 ^ 0x300 ;
V_25 = F_13 ( V_2 ) ;
if ( V_25 == 0 )
break;
}
if ( V_25 != 0 )
goto V_40;
V_24 = F_14 ( V_2 , V_41 ) ;
if ( V_24 )
goto V_40;
V_24 = F_15 ( V_2 ) ;
if ( V_24 )
goto V_40;
V_6 -> V_42 = V_2 -> V_42 ;
V_6 -> V_43 = V_2 -> V_11 [ 0 ] -> V_39 ;
V_29 = V_6 -> V_43 ;
F_16 ( 0 ) ;
V_32 = F_17 ( V_2 , 0x88 , & V_31 ) ;
if ( V_31 && V_32 >= 6 ) {
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
V_23 [ V_25 ] = F_18 ( F_19 ( V_31 [ V_25 * 2 ] ) ) ;
F_20 ( V_31 ) ;
} else {
F_20 ( V_31 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
V_23 [ V_25 ] = F_18 ( F_21 ( V_29 , V_25 ) ) ;
if ( V_23 [ 0 ] == F_18 ( 0x6060 ) ) {
F_22 ( & V_2 -> V_6 , L_9 ,
V_6 -> V_43 , V_6 -> V_43 + 15 ) ;
goto V_40;
}
}
F_23 ( 0x3f00 , V_29 + 8 ) ;
V_28 = F_24 ( V_29 ) ;
if ( ( V_44 >= 0 ) && ( V_44 <= 3 ) )
V_6 -> V_44 = V_44 ;
else
F_22 ( & V_2 -> V_6 , L_10 ) ;
F_25 ( V_6 , & V_2 -> V_6 ) ;
if ( F_26 ( V_6 ) != 0 ) {
F_22 ( & V_2 -> V_6 , L_11 ) ;
goto V_40;
}
F_27 ( V_6 , L_12 ,
( V_27 ? L_13 : L_14 ) , V_6 -> V_43 , V_6 -> V_42 ,
V_6 -> V_33 ) ;
F_27 ( V_6 , L_15 ,
( V_28 & 7 ) ? 32 : 8 , V_30 [ ( V_28 >> 16 ) & 3 ] ,
V_45 [ V_6 -> V_44 ] ) ;
return 0 ;
V_40:
F_10 ( V_2 ) ;
return - V_46 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_47 )
F_30 ( V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
if ( V_2 -> V_47 ) {
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
}
return 0 ;
}
static void F_34 ( struct V_5 * V_6 , int V_48 )
{
int V_25 = 100 ;
F_23 ( V_48 , V_6 -> V_43 + V_49 ) ;
while ( -- V_25 > 0 )
if ( ! ( F_35 ( V_6 -> V_43 + V_50 ) & 0x1000 ) ) break;
if ( V_25 == 0 )
F_36 ( V_6 , L_16 , V_48 ) ;
}
static T_4 F_21 ( unsigned int V_29 , int V_51 )
{
int V_25 ;
F_23 ( V_52 + V_51 , V_29 + 10 ) ;
for ( V_25 = 1620 ; V_25 >= 0 ; V_25 -- )
if ( ( F_35 ( V_29 + 10 ) & V_53 ) == 0 )
break;
return F_35 ( V_29 + 12 ) ;
}
static void F_37 ( struct V_5 * V_6 , int V_44 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_29 = V_6 -> V_43 ;
F_16 ( 0 ) ;
switch ( V_44 ) {
case 0 : case 1 : F_23 ( 0 , V_29 + 6 ) ; break;
case 2 : F_23 ( 3 << 14 , V_29 + 6 ) ; break;
case 3 : F_23 ( 1 << 14 , V_29 + 6 ) ; break;
}
F_23 ( ( V_44 == 2 ) ? V_54 : V_55 , V_29 + V_49 ) ;
F_16 ( 4 ) ;
F_23 ( V_56 | ( ( V_44 < 2 ) ? V_57 : 0 ) , V_29 + V_58 ) ;
F_16 ( 1 ) ;
if ( V_44 == 2 )
V_4 -> V_59 = ( ( V_6 -> V_44 == 0 ) ? 0x8000 : 0x4000 ) ;
else
V_4 -> V_59 = ( ( V_6 -> V_44 == 0 ) ? 0x4010 : 0x8800 ) ;
}
static void F_38 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
F_16 ( 1 ) ;
F_27 ( V_6 , L_17 ,
F_35 ( V_29 + V_50 ) , F_35 ( V_29 + V_60 ) ,
F_39 ( V_29 + V_61 ) , F_35 ( V_29 + V_62 ) ) ;
F_16 ( 4 ) ;
F_27 ( V_6 , L_18 ,
F_35 ( V_29 + 0x04 ) , F_35 ( V_29 + 0x06 ) , F_35 ( V_29 + 0x08 ) ,
F_35 ( V_29 + 0x0a ) ) ;
F_16 ( 1 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
int V_25 ;
F_16 ( 0 ) ;
F_23 ( 0x0001 , V_29 + 4 ) ;
F_23 ( 0x3f00 , V_29 + 8 ) ;
F_16 ( 2 ) ;
for ( V_25 = 0 ; V_25 < 6 ; V_25 ++ )
F_40 ( V_6 -> V_33 [ V_25 ] , V_29 + V_25 ) ;
F_37 ( V_6 , V_6 -> V_44 ) ;
F_23 ( V_63 , V_29 + V_49 ) ;
F_16 ( 6 ) ;
for ( V_25 = 0 ; V_25 < 9 ; V_25 ++ )
F_39 ( V_29 + V_25 ) ;
F_35 ( V_29 + 10 ) ;
F_35 ( V_29 + 12 ) ;
F_16 ( 1 ) ;
F_41 ( V_6 ) ;
F_23 ( V_64 , V_29 + V_49 ) ;
F_23 ( V_65 , V_29 + V_49 ) ;
F_23 ( V_66 , V_29 + V_49 ) ;
F_23 ( V_67 | 0xff , V_29 + V_49 ) ;
F_23 ( V_68 | V_69 | V_70 | V_71 | V_72 ,
V_29 + V_49 ) ;
F_23 ( V_73 | V_69 | V_70 | V_74 | V_75
| V_76 , V_29 + V_49 ) ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
strcpy ( V_78 -> V_79 , V_80 ) ;
strcpy ( V_78 -> V_81 , V_82 ) ;
sprintf ( V_78 -> V_83 , L_19 , V_6 -> V_43 ) ;
}
static int F_43 ( struct V_5 * V_6 , struct V_84 * V_85 )
{
if ( ( V_85 -> V_86 != ( V_87 ) ( - 1 ) ) && ( V_85 -> V_86 != V_6 -> V_44 ) ) {
if ( V_85 -> V_86 <= 3 ) {
V_6 -> V_44 = V_85 -> V_86 ;
F_27 ( V_6 , L_20 , V_45 [ V_6 -> V_44 ] ) ;
F_37 ( V_6 , V_6 -> V_44 ) ;
} else
return - V_88 ;
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
if ( ! F_45 ( V_2 ) )
return - V_46 ;
V_2 -> V_47 ++ ;
F_46 ( V_6 ) ;
F_32 ( V_6 ) ;
F_47 ( & V_4 -> V_89 ) ;
V_4 -> V_89 . V_90 = V_91 ;
V_4 -> V_89 . V_92 = ( unsigned long ) V_6 ;
V_4 -> V_89 . V_93 = V_94 + V_95 ;
F_48 ( & V_4 -> V_89 ) ;
F_2 ( & V_2 -> V_6 , L_21 ,
V_6 -> V_96 , F_35 ( V_6 -> V_43 + V_50 ) ) ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
F_36 ( V_6 , L_22 ) ;
F_38 ( V_6 ) ;
V_6 -> V_97 . V_98 ++ ;
V_6 -> V_99 = V_94 ;
F_34 ( V_6 , V_100 ) ;
F_23 ( V_66 , V_29 + V_49 ) ;
F_50 ( V_6 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
int V_25 ;
for ( V_25 = 32 ; V_25 > 0 ; V_25 -- ) {
V_87 V_101 = F_39 ( V_29 + V_61 ) ;
if ( ! ( V_101 & 0x84 ) ) break;
if ( V_101 & 0x30 )
F_34 ( V_6 , V_100 ) ;
if ( V_101 & 0x38 ) {
F_52 ( V_6 , L_23 , V_101 ) ;
F_23 ( V_66 , V_29 + V_49 ) ;
V_6 -> V_97 . V_102 ++ ;
}
F_40 ( 0x00 , V_29 + V_61 ) ;
}
}
static T_5 F_53 ( struct V_103 * V_104 ,
struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
struct V_3 * V_8 = F_4 ( V_6 ) ;
unsigned long V_13 ;
F_52 ( V_6 , L_24 ,
( long ) V_104 -> V_32 , F_35 ( V_29 + V_50 ) ) ;
F_54 ( & V_8 -> V_10 , V_13 ) ;
V_6 -> V_97 . V_105 += V_104 -> V_32 ;
F_23 ( V_104 -> V_32 , V_29 + V_106 ) ;
F_23 ( 0x00 , V_29 + V_106 ) ;
F_55 ( V_29 + V_106 , V_104 -> V_92 , ( V_104 -> V_32 + 3 ) >> 2 ) ;
if ( F_35 ( V_29 + V_62 ) <= 1536 ) {
F_56 ( V_6 ) ;
F_23 ( V_107 + 1536 , V_29 + V_49 ) ;
}
F_51 ( V_6 ) ;
F_57 ( & V_8 -> V_10 , V_13 ) ;
F_58 ( V_104 ) ;
return V_108 ;
}
static T_6 V_41 ( int V_42 , void * V_109 )
{
struct V_5 * V_6 = (struct V_5 * ) V_109 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_29 ;
T_7 V_110 ;
int V_25 = 0 , V_111 = 1 ;
if ( ! F_59 ( V_6 ) )
return V_112 ;
V_29 = V_6 -> V_43 ;
F_52 ( V_6 , L_25 , F_35 ( V_29 + V_50 ) ) ;
F_60 ( & V_4 -> V_10 ) ;
while ( ( V_110 = F_35 ( V_29 + V_50 ) ) &
( V_69 | V_74 | V_75 ) ) {
if ( ( V_110 & 0xe000 ) != 0x2000 ) {
F_52 ( V_6 , L_26 ) ;
V_111 = 0 ;
break;
}
if ( V_110 & V_74 )
F_61 ( V_6 ) ;
if ( V_110 & V_70 ) {
F_52 ( V_6 , L_27 ) ;
F_23 ( V_68 | V_70 , V_29 + V_49 ) ;
F_50 ( V_6 ) ;
}
if ( V_110 & V_113 )
F_51 ( V_6 ) ;
if ( V_110 & ( V_76 | V_71 | V_75 ) ) {
if ( V_110 & V_75 )
F_62 ( V_6 ) ;
if ( V_110 & V_71 ) {
F_61 ( V_6 ) ;
F_23 ( V_68 | V_71 , V_29 + V_49 ) ;
}
if ( V_110 & V_76 ) {
T_4 V_114 ;
F_16 ( 4 ) ;
V_114 = F_35 ( V_29 + 4 ) ;
F_16 ( 1 ) ;
F_36 ( V_6 , L_28 ,
V_114 ) ;
if ( V_114 & 0x0400 ) {
F_34 ( V_6 , V_100 ) ;
F_23 ( V_66 , V_29 + V_49 ) ;
}
if ( V_114 & 0x2000 ) {
F_34 ( V_6 , V_115 ) ;
F_41 ( V_6 ) ;
F_23 ( V_65 , V_29 + V_49 ) ;
}
F_23 ( V_68 | V_76 , V_29 + V_49 ) ;
}
}
if ( ++ V_25 > 10 ) {
F_63 ( V_6 , L_29 ,
V_110 ) ;
F_23 ( V_68 | 0xFF , V_29 + V_49 ) ;
break;
}
F_23 ( V_68 | V_72 | V_69 , V_29 + V_49 ) ;
}
V_4 -> V_116 = V_94 ;
F_64 ( & V_4 -> V_10 ) ;
F_52 ( V_6 , L_30 ,
F_35 ( V_29 + V_50 ) ) ;
return F_65 ( V_111 ) ;
}
static void V_91 ( unsigned long V_117 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_117 ) ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned int V_29 = V_6 -> V_43 ;
T_4 V_89 , V_118 ;
unsigned long V_13 ;
if ( ! F_59 ( V_6 ) ) goto V_119;
if ( ( F_35 ( V_29 + V_50 ) & V_69 ) &&
( F_39 ( V_29 + V_120 ) == 0xff ) ) {
if ( ! V_4 -> V_121 )
F_36 ( V_6 , L_31 ) ;
F_66 ( V_13 ) ;
V_41 ( V_6 -> V_42 , V_6 ) ;
F_67 ( V_13 ) ;
V_4 -> V_121 = V_95 ;
}
if ( V_4 -> V_121 ) {
V_4 -> V_121 -- ;
V_4 -> V_89 . V_93 = V_94 + V_95 / 100 ;
F_48 ( & V_4 -> V_89 ) ;
return;
}
F_54 ( & V_4 -> V_10 , V_13 ) ;
F_16 ( 4 ) ;
V_89 = F_35 ( V_29 + V_58 ) & 0xc810 ;
if ( F_68 ( V_94 , V_4 -> V_116 + V_95 ) ) {
V_89 &= ~ 0x0010 ;
} else {
F_16 ( 6 ) ;
F_23 ( V_63 , V_29 + V_49 ) ;
V_118 = F_39 ( V_29 + 0 ) ;
F_23 ( V_64 , V_29 + V_49 ) ;
V_6 -> V_97 . V_122 += V_118 ;
if ( V_118 || ( V_4 -> V_59 & 0x0010 ) ) V_89 |= 0x0010 ;
}
if ( V_89 != V_4 -> V_59 ) {
if ( ( V_89 & V_4 -> V_59 & 0x8000 ) &&
( ( V_4 -> V_59 ^ V_89 ) & 0x0800 ) )
F_27 ( V_6 , L_32 ,
( V_4 -> V_59 & 0x0800 ? L_33 : L_34 ) ) ;
else if ( ( V_89 & V_4 -> V_59 & 0x4000 ) &&
( ( V_4 -> V_59 ^ V_89 ) & 0x0010 ) )
F_27 ( V_6 , L_35 ,
( V_4 -> V_59 & 0x0010 ? L_36 : L_37 ) ) ;
if ( V_6 -> V_44 == 0 ) {
if ( V_89 & 0x8000 ) {
if ( V_89 & 0x0800 )
F_27 ( V_6 , L_38 ) ;
else
F_37 ( V_6 , 2 ) ;
} else if ( V_89 & 0x4000 ) {
if ( V_89 & 0x0010 )
F_37 ( V_6 , 1 ) ;
else
F_27 ( V_6 , L_39 ) ;
}
}
V_4 -> V_59 = V_89 ;
}
F_16 ( 1 ) ;
F_57 ( & V_4 -> V_10 , V_13 ) ;
V_119:
V_4 -> V_89 . V_93 = V_94 + V_95 ;
F_48 ( & V_4 -> V_89 ) ;
}
static struct V_123 * F_69 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
unsigned long V_13 ;
struct V_1 * V_2 = V_4 -> V_9 ;
if ( F_45 ( V_2 ) ) {
F_54 ( & V_4 -> V_10 , V_13 ) ;
F_62 ( V_6 ) ;
F_57 ( & V_4 -> V_10 , V_13 ) ;
}
return & V_6 -> V_97 ;
}
static void F_62 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
F_52 ( V_6 , L_40 ) ;
F_23 ( V_63 , V_29 + V_49 ) ;
F_16 ( 6 ) ;
V_6 -> V_97 . V_122 += F_39 ( V_29 + 0 ) ;
V_6 -> V_97 . V_124 += F_39 ( V_29 + 1 ) ;
F_39 ( V_29 + 2 ) ;
V_6 -> V_97 . V_125 += F_39 ( V_29 + 3 ) ;
V_6 -> V_97 . V_126 += F_39 ( V_29 + 4 ) ;
V_6 -> V_97 . V_127 += F_39 ( V_29 + 5 ) ;
V_6 -> V_97 . V_128 += F_39 ( V_29 + 6 ) ;
F_39 ( V_29 + 7 ) ;
F_39 ( V_29 + 8 ) ;
F_35 ( V_29 + 10 ) ;
F_35 ( V_29 + 12 ) ;
F_16 ( 1 ) ;
F_23 ( V_64 , V_29 + V_49 ) ;
}
static int F_61 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
int V_129 = 32 ;
short V_130 ;
F_52 ( V_6 , L_41 ,
F_35 ( V_29 + V_50 ) , F_35 ( V_29 + V_60 ) ) ;
while ( ! ( ( V_130 = F_35 ( V_29 + V_60 ) ) & 0x8000 ) &&
V_129 > 0 ) {
V_129 -- ;
if ( V_130 & 0x4000 ) {
short error = V_130 & 0x3800 ;
V_6 -> V_97 . V_131 ++ ;
switch ( error ) {
case 0x0000 : V_6 -> V_97 . V_132 ++ ; break;
case 0x0800 : V_6 -> V_97 . V_133 ++ ; break;
case 0x1000 : V_6 -> V_97 . V_134 ++ ; break;
case 0x1800 : V_6 -> V_97 . V_133 ++ ; break;
case 0x2000 : V_6 -> V_97 . V_134 ++ ; break;
case 0x2800 : V_6 -> V_97 . V_135 ++ ; break;
}
} else {
short V_136 = V_130 & 0x7ff ;
struct V_103 * V_104 ;
V_104 = F_70 ( V_136 + 5 ) ;
F_52 ( V_6 , L_42 ,
V_136 , V_130 ) ;
if ( V_104 != NULL ) {
F_71 ( V_104 , 2 ) ;
F_72 ( V_29 + V_137 , F_73 ( V_104 , V_136 ) ,
( V_136 + 3 ) >> 2 ) ;
V_104 -> V_138 = F_74 ( V_104 , V_6 ) ;
F_75 ( V_104 ) ;
V_6 -> V_97 . V_139 ++ ;
V_6 -> V_97 . V_140 += V_136 ;
} else {
F_52 ( V_6 , L_43 ,
V_136 ) ;
V_6 -> V_97 . V_141 ++ ;
}
}
F_34 ( V_6 , V_142 ) ;
}
if ( V_129 == 0 )
F_36 ( V_6 , L_44 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
unsigned int V_29 = V_6 -> V_43 ;
T_4 V_143 = V_144 | V_145 | V_146 ;
if ( V_6 -> V_13 & V_147 )
V_143 |= V_148 | V_149 ;
else if ( ! F_76 ( V_6 ) || ( V_6 -> V_13 & V_150 ) )
V_143 |= V_148 ;
F_23 ( V_143 , V_29 + V_49 ) ;
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_3 * V_8 = F_4 ( V_6 ) ;
unsigned long V_13 ;
F_54 ( & V_8 -> V_10 , V_13 ) ;
F_41 ( V_6 ) ;
F_57 ( & V_8 -> V_10 , V_13 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_4 -> V_9 ;
unsigned int V_29 = V_6 -> V_43 ;
F_2 ( & V_2 -> V_6 , L_45 , V_6 -> V_96 ) ;
if ( F_45 ( V_2 ) ) {
F_23 ( V_63 , V_29 + V_49 ) ;
F_23 ( V_151 , V_29 + V_49 ) ;
F_23 ( V_152 , V_29 + V_49 ) ;
if ( V_6 -> V_44 == 2 )
F_23 ( V_55 , V_29 + V_49 ) ;
else if ( V_6 -> V_44 == 1 ) {
F_16 ( 4 ) ;
F_23 ( 0 , V_29 + V_58 ) ;
}
F_16 ( 0 ) ;
F_23 ( 0x0f00 , V_29 + V_153 ) ;
if ( ( F_35 ( V_29 + V_50 ) & 0xe000 ) == 0x2000 )
F_62 ( V_6 ) ;
}
V_2 -> V_47 -- ;
F_56 ( V_6 ) ;
F_79 ( & V_4 -> V_89 ) ;
return 0 ;
}
static int T_8 F_80 ( void )
{
return F_81 ( & V_154 ) ;
}
static void T_9 F_82 ( void )
{
F_83 ( & V_154 ) ;
}
