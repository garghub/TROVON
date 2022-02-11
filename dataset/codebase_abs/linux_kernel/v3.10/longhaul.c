static char * F_1 ( int V_1 )
{
if ( V_1 < 1000 ) {
snprintf ( V_2 , sizeof( V_2 ) , L_1 , V_1 ) ;
return V_2 ;
}
if ( V_1 % 1000 == 0 )
snprintf ( V_2 , sizeof( V_2 ) ,
L_2 , V_1 / 1000 ) ;
else
snprintf ( V_2 , sizeof( V_2 ) ,
L_3 , V_1 / 1000 , ( V_1 % 1000 ) / 100 ) ;
return V_2 ;
}
static unsigned int F_2 ( int V_3 )
{
int V_4 ;
V_4 = ( V_3 / 10 ) * V_5 ;
if ( V_3 % 10 )
V_4 += V_5 / 2 ;
V_4 *= 1000 ;
return V_4 ;
}
static int F_3 ( void )
{
unsigned long V_6 = 0 , V_7 , V_8 ;
F_4 ( V_9 , V_7 , V_8 ) ;
V_6 = ( V_7 & ( 1 << 22 | 1 << 23 | 1 << 24 | 1 << 25 ) ) >> 22 ;
if ( V_10 == V_11 ||
V_10 == V_12 ) {
if ( V_7 & ( 1 << 27 ) )
V_6 += 16 ;
}
return V_13 [ V_6 ] ;
}
static void F_5 ( unsigned int V_14 )
{
union V_15 V_16 ;
F_6 ( V_17 , V_16 . V_18 ) ;
V_16 . V_19 . V_20 = 1 ;
V_16 . V_19 . V_21 = V_14 & 0xff ;
F_7 () ;
F_8 ( V_17 , V_16 . V_18 ) ;
F_9 () ;
F_10 () ;
F_11 () ;
F_6 ( V_17 , V_16 . V_18 ) ;
V_16 . V_19 . V_20 = 0 ;
F_8 ( V_17 , V_16 . V_18 ) ;
}
static void F_12 ( int V_22 , unsigned int V_14 ,
unsigned int V_23 )
{
union V_24 V_25 ;
T_1 V_26 ;
F_6 ( V_27 , V_25 . V_18 ) ;
if ( ! V_28 )
V_25 . V_19 . V_29 = V_25 . V_19 . V_30 ;
else
V_25 . V_19 . V_29 = 0 ;
V_25 . V_19 . V_31 = V_14 & 0xf ;
V_25 . V_19 . V_32 = ( V_14 & 0x10 ) >> 4 ;
if ( V_33 )
V_25 . V_19 . V_34 = ( V_14 >> 8 ) & 0x1f ;
F_7 () ;
if ( V_33 && V_23 ) {
V_25 . V_19 . V_35 = 1 ;
F_8 ( V_27 , V_25 . V_18 ) ;
if ( ! V_22 ) {
F_9 () ;
F_10 () ;
} else {
F_9 () ;
F_13 ( V_22 ) ;
V_26 = F_14 ( V_36 . V_37 . V_38 ) ;
}
V_25 . V_19 . V_35 = 0 ;
F_8 ( V_27 , V_25 . V_18 ) ;
}
V_25 . V_19 . V_39 = 1 ;
F_8 ( V_27 , V_25 . V_18 ) ;
if ( ! V_22 ) {
F_9 () ;
F_10 () ;
} else {
F_9 () ;
F_13 ( V_22 ) ;
V_26 = F_14 ( V_36 . V_37 . V_38 ) ;
}
V_25 . V_19 . V_39 = 0 ;
F_8 ( V_27 , V_25 . V_18 ) ;
if ( V_33 && ! V_23 ) {
V_25 . V_19 . V_35 = 1 ;
F_8 ( V_27 , V_25 . V_18 ) ;
if ( ! V_22 ) {
F_9 () ;
F_10 () ;
} else {
F_9 () ;
F_13 ( V_22 ) ;
V_26 = F_14 ( V_36 . V_37 . V_38 ) ;
}
V_25 . V_19 . V_35 = 0 ;
F_8 ( V_27 , V_25 . V_18 ) ;
}
}
static void F_15 ( struct V_40 * V_41 ,
unsigned int V_42 )
{
unsigned int V_14 ;
int V_1 , V_3 ;
struct V_43 V_44 ;
unsigned long V_45 ;
unsigned int V_46 , V_47 ;
T_2 V_48 = 0 ;
T_1 V_49 = 1000 ;
unsigned int V_23 = 0 ;
V_14 = V_50 [ V_42 ] . V_51 ;
V_3 = V_52 [ V_14 & 0x1f ] ;
if ( V_3 == - 1 )
return;
V_1 = F_2 ( V_3 ) ;
if ( ( V_1 > V_53 ) || ( V_1 < V_54 ) )
return;
if ( V_33 && V_55 < V_42 )
V_23 = 1 ;
V_44 . V_56 = F_2 ( F_3 () ) ;
V_44 . V_57 = V_1 ;
F_16 ( V_41 , & V_44 , V_58 ) ;
F_17 ( L_4 ,
V_5 , V_3 / 10 , V_3 % 10 , F_1 ( V_1 / 1000 ) ) ;
V_59:
F_18 () ;
F_19 ( V_45 ) ;
V_47 = F_13 ( 0xA1 ) ;
V_46 = F_13 ( 0x21 ) ;
F_20 ( 0xFF , 0xA1 ) ;
F_20 ( 0xFE , 0x21 ) ;
if ( V_60 && ( V_61 & V_62
|| ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) ) ) {
V_48 = F_21 ( V_60 ) ;
V_48 &= 1 << 4 ;
while ( V_48 && V_49 ) {
F_22 ( 1 << 4 , V_60 ) ;
V_49 -- ;
V_48 = F_21 ( V_60 ) ;
V_48 &= 1 << 4 ;
}
}
if ( V_61 & V_62 ) {
F_20 ( 3 , 0x22 ) ;
} else if ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) {
F_23 ( V_65 , 1 ) ;
}
switch ( V_10 ) {
case V_66 :
F_5 ( V_14 ) ;
break;
case V_11 :
case V_12 :
if ( V_61 & V_67 ) {
F_23 ( V_68 , 0 ) ;
F_12 ( V_69 -> V_38 , V_14 , V_23 ) ;
} else {
F_12 ( 0 , V_14 , V_23 ) ;
}
break;
}
if ( V_61 & V_62 ) {
F_20 ( 0 , 0x22 ) ;
} else if ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) {
F_23 ( V_65 , 0 ) ;
}
F_20 ( V_47 , 0xA1 ) ;
F_20 ( V_46 , 0x21 ) ;
F_24 ( V_45 ) ;
F_25 () ;
V_44 . V_57 = F_2 ( F_3 () ) ;
if ( F_26 ( V_44 . V_57 != V_1 ) ) {
F_27 (KERN_INFO PFX L_5 ) ;
if ( ! V_28 ) {
F_27 (KERN_INFO PFX L_6
L_7 ) ;
V_28 = 1 ;
F_28 ( 200 ) ;
goto V_59;
}
if ( V_61 & V_67 ) {
F_27 (KERN_INFO PFX L_8 ) ;
V_61 &= ~ V_67 ;
if ( V_28 ) {
F_27 (KERN_INFO PFX L_9
L_10 ) ;
V_28 = 0 ;
}
F_28 ( 200 ) ;
goto V_59;
}
if ( V_10 == V_11 ) {
F_27 (KERN_INFO PFX L_11 ) ;
V_10 = V_66 ;
F_28 ( 200 ) ;
goto V_59;
}
}
F_16 ( V_41 , & V_44 , V_70 ) ;
if ( ! V_49 )
F_27 (KERN_INFO PFX L_12
L_13 ) ;
}
static int F_29 ( int V_3 )
{
int V_1 = V_71 / 1000 ;
int V_72 ;
int V_73 [] = { 666 , 1000 , 1333 , 2000 } ;
int V_74 , V_75 ;
for ( V_72 = 0 ; V_72 < 4 ; V_72 ++ ) {
V_74 = ( ( V_73 [ V_72 ] * V_3 ) + 50 ) / 100 ;
V_74 += ( V_76 / 2 ) ;
V_75 = V_74 - V_76 ;
if ( ( V_1 <= V_74 ) && ( V_1 >= V_75 ) )
return V_73 [ V_72 ] / 10 ;
}
return 0 ;
}
static int T_3 F_30 ( void )
{
unsigned int V_72 , V_77 , V_78 = 0 ;
unsigned int V_79 ;
int V_3 ;
V_3 = F_3 () ;
if ( V_3 == - 1 ) {
F_27 (KERN_INFO PFX L_14 ) ;
return - V_80 ;
}
V_5 = F_29 ( V_3 ) ;
if ( V_5 == 0 ) {
F_27 (KERN_INFO PFX L_15 ) ;
return - V_80 ;
}
V_81 = V_3 ;
switch ( V_82 ) {
case V_83 :
V_84 = 50 ;
break;
case V_85 :
V_84 = 40 ;
break;
default:
V_84 = 30 ;
break;
}
F_17 ( L_16 ,
V_84 / 10 , V_84 % 10 , V_81 / 10 , V_81 % 10 ) ;
V_53 = F_2 ( V_81 ) ;
V_54 = F_2 ( V_84 ) ;
F_17 ( L_17 , V_5 ,
F_1 ( V_54 / 1000 ) ,
F_1 ( V_53 / 1000 ) ) ;
if ( V_54 == V_53 ) {
F_27 (KERN_INFO PFX L_18 ) ;
return - V_80 ;
}
if ( V_54 > V_53 ) {
F_27 (KERN_INFO PFX L_19 ,
lowest_speed, highest_speed) ;
return - V_80 ;
}
V_50 = F_31 ( ( V_86 + 1 ) * sizeof( * V_50 ) ,
V_87 ) ;
if ( ! V_50 )
return - V_88 ;
for ( V_77 = 0 ; V_77 < V_86 ; V_77 ++ ) {
V_79 = V_52 [ V_77 ] ;
if ( V_79 == - 1 )
continue;
if ( V_79 > V_81 || V_79 < V_84 )
continue;
V_50 [ V_78 ] . V_89 = F_2 ( V_79 ) ;
V_50 [ V_78 ] . V_51 = V_77 ;
V_78 ++ ;
}
if ( V_78 <= 1 ) {
F_32 ( V_50 ) ;
return - V_90 ;
}
for ( V_77 = 0 ; V_77 < V_78 - 1 ; V_77 ++ ) {
unsigned int V_91 , V_92 ;
V_91 = V_50 [ V_77 ] . V_89 ;
V_92 = V_77 ;
for ( V_72 = V_77 + 1 ; V_72 < V_78 ; V_72 ++ ) {
if ( V_50 [ V_72 ] . V_89 < V_91 ) {
V_91 = V_50 [ V_72 ] . V_89 ;
V_92 = V_72 ;
}
}
if ( V_92 != V_77 ) {
F_33 ( V_50 [ V_77 ] . V_89 ,
V_50 [ V_92 ] . V_89 ) ;
F_33 ( V_50 [ V_77 ] . V_51 ,
V_50 [ V_92 ] . V_51 ) ;
}
}
V_50 [ V_78 ] . V_89 = V_93 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
if ( V_52 [ V_50 [ V_77 ] . V_51 & 0x1f ] == V_3 ) {
V_55 = V_77 ;
break;
}
}
return 0 ;
}
static void T_3 F_34 ( void )
{
union V_24 V_25 ;
struct V_94 V_95 , V_96 , V_97 ;
unsigned int V_77 , V_1 , V_98 , V_99 , V_100 ;
int V_101 ;
F_6 ( V_27 , V_25 . V_18 ) ;
if ( ! ( V_25 . V_19 . V_30 & 1 ) ) {
F_27 (KERN_INFO PFX L_20 ) ;
return;
}
if ( ! V_25 . V_19 . V_102 ) {
F_27 (KERN_INFO PFX L_21 ) ;
V_103 = & V_104 [ 0 ] ;
V_105 = & V_106 [ 0 ] ;
} else {
F_27 (KERN_INFO PFX L_22 ) ;
if ( V_82 < V_83 )
return;
V_103 = & V_107 [ 0 ] ;
V_105 = & V_108 [ 0 ] ;
}
V_95 = V_103 [ V_25 . V_19 . V_109 ] ;
V_96 = V_103 [ V_25 . V_19 . V_110 ] ;
if ( V_95 . V_111 == 0 || V_96 . V_111 == 0 || V_95 . V_111 > V_96 . V_111 ) {
F_27 (KERN_INFO PFX L_23
L_24 ,
minvid.mV/1000 , minvid.mV%1000 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
if ( V_95 . V_111 == V_96 . V_111 ) {
F_27 (KERN_INFO PFX L_25
L_26
L_27 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
V_100 = V_96 . V_98 - V_95 . V_98 + 1 ;
F_27 (KERN_INFO PFX
L_28
L_29
L_30 ,
maxvid.mV/1000 , maxvid.mV%1000 ,
minvid.mV/1000 , minvid.mV%1000 ,
numvscales) ;
V_77 = V_25 . V_19 . V_112 ;
if ( V_25 . V_19 . V_113 )
V_77 += 16 ;
V_101 = V_13 [ V_77 ] ;
if ( V_101 == - 1 )
return;
switch ( V_25 . V_19 . V_114 ) {
case 0 :
V_101 *= 13333 ;
break;
case 1 :
V_101 *= 10000 ;
break;
case 3 :
V_101 *= 6666 ;
break;
default:
return;
break;
}
if ( V_101 >= V_53 )
return;
V_99 = ( V_53 - V_101 ) / V_100 ;
V_77 = 0 ;
while ( V_50 [ V_77 ] . V_89 != V_93 ) {
V_1 = V_50 [ V_77 ] . V_89 ;
if ( V_1 > V_101 )
V_98 = ( V_1 - V_101 ) / V_99 + V_95 . V_98 ;
else
V_98 = V_95 . V_98 ;
V_50 [ V_77 ] . V_51 |= V_105 [ V_98 ] << 8 ;
V_97 = V_103 [ V_105 [ V_98 ] ] ;
F_27 (KERN_INFO PFX L_31 ,
speed, j, vid.mV) ;
V_77 ++ ;
}
V_33 = 1 ;
F_27 (KERN_INFO PFX L_32 ) ;
}
static int F_35 ( struct V_40 * V_41 )
{
return F_36 ( V_41 , V_50 ) ;
}
static int F_37 ( struct V_40 * V_41 ,
unsigned int V_115 , unsigned int V_116 )
{
unsigned int V_42 = 0 ;
unsigned int V_72 ;
unsigned int V_23 = 0 ;
T_4 V_97 , V_117 ;
if ( F_38 ( V_41 , V_50 , V_115 ,
V_116 , & V_42 ) )
return - V_80 ;
if ( V_55 == V_42 )
return 0 ;
if ( ! V_33 )
F_15 ( V_41 , V_42 ) ;
else {
V_72 = V_55 ;
V_117 = ( V_50 [ V_55 ] . V_51 >> 8 ) ;
V_117 &= 0x1f ;
if ( V_42 > V_55 )
V_23 = 1 ;
while ( V_72 != V_42 ) {
V_97 = ( V_50 [ V_72 ] . V_51 >> 8 ) & 0x1f ;
if ( V_97 != V_117 ) {
F_15 ( V_41 , V_72 ) ;
V_117 = V_97 ;
F_28 ( 200 ) ;
}
if ( V_23 )
V_72 ++ ;
else
V_72 -- ;
}
F_15 ( V_41 , V_42 ) ;
}
V_55 = V_42 ;
return 0 ;
}
static unsigned int F_39 ( unsigned int V_118 )
{
if ( V_118 )
return 0 ;
return F_2 ( F_3 () ) ;
}
static T_5 F_40 ( T_6 V_119 ,
T_1 V_120 ,
void * V_121 , void * * V_122 )
{
struct V_123 * V_124 ;
if ( F_41 ( V_119 , & V_124 ) )
return 0 ;
* V_122 = F_42 ( V_124 ) ;
return 1 ;
}
static int F_43 ( void )
{
struct V_125 * V_126 ;
int V_127 = 1 ;
int V_128 ;
T_4 V_129 ;
V_128 = 0x78 ;
V_126 = F_44 ( V_130 , V_131 ,
NULL ) ;
if ( V_126 == NULL )
V_126 = F_44 ( V_130 ,
V_132 , NULL ) ;
if ( V_126 == NULL ) {
V_128 = 0x76 ;
V_126 = F_44 ( V_130 ,
V_133 , NULL ) ;
if ( V_126 == NULL )
V_126 = F_44 ( V_130 , 0x7259 , NULL ) ;
}
if ( V_126 != NULL ) {
F_45 ( V_126 , V_128 , & V_129 ) ;
if ( ! ( V_129 & 1 << 7 ) ) {
V_129 |= 1 << 7 ;
F_46 ( V_126 , V_128 , V_129 ) ;
F_45 ( V_126 , V_128 , & V_129 ) ;
if ( ! ( V_129 & 1 << 7 ) ) {
F_27 (KERN_ERR PFX
L_33 ) ;
V_127 = 0 ;
}
}
F_47 ( V_126 ) ;
return V_127 ;
}
return 0 ;
}
static int F_48 ( void )
{
struct V_125 * V_126 ;
T_4 V_129 ;
V_126 = F_44 ( V_130 , V_134 , NULL ) ;
if ( V_126 == NULL )
V_126 = F_44 ( V_130 ,
V_135 , NULL ) ;
if ( V_126 != NULL ) {
F_45 ( V_126 , 0xec , & V_129 ) ;
V_129 &= ~ ( 1 << 2 ) ;
F_46 ( V_126 , 0xec , V_129 ) ;
F_45 ( V_126 , 0xe4 , & V_129 ) ;
V_129 &= ~ ( 1 << 7 ) ;
F_46 ( V_126 , 0xe4 , V_129 ) ;
F_45 ( V_126 , 0xe5 , & V_129 ) ;
V_129 |= 1 << 7 ;
F_46 ( V_126 , 0xe5 , V_129 ) ;
F_45 ( V_126 , 0x81 , & V_129 ) ;
if ( V_129 & 1 << 7 ) {
F_49 ( V_126 , 0x88 , & V_60 ) ;
V_60 &= 0xff00 ;
F_27 (KERN_INFO PFX L_34 ,
acpi_regs_addr) ;
}
F_47 ( V_126 ) ;
return 1 ;
}
return 0 ;
}
static int T_3 F_50 ( struct V_40 * V_41 )
{
struct V_136 * V_137 = & F_51 ( 0 ) ;
char * V_138 = NULL ;
int V_139 ;
T_1 V_7 , V_8 ;
switch ( V_137 -> V_140 ) {
case 6 :
V_82 = V_141 ;
V_138 = L_35 ;
V_10 = V_66 ;
memcpy ( V_52 , V_142 , sizeof( V_142 ) ) ;
memcpy ( V_13 , V_143 , sizeof( V_143 ) ) ;
break;
case 7 :
switch ( V_137 -> V_144 ) {
case 0 :
V_10 = V_66 ;
V_82 = V_145 ;
V_138 = L_36 ;
memcpy ( V_52 , V_142 , sizeof( V_142 ) ) ;
memcpy ( V_13 , V_146 , sizeof( V_146 ) ) ;
break;
case 1 ... 15 :
V_10 = V_11 ;
if ( V_137 -> V_144 < 8 ) {
V_82 = V_145 ;
V_138 = L_36 ;
} else {
V_82 = V_147 ;
V_138 = L_37 ;
}
memcpy ( V_52 , V_148 , sizeof( V_148 ) ) ;
memcpy ( V_13 , V_149 , sizeof( V_149 ) ) ;
break;
}
break;
case 8 :
V_82 = V_150 ;
V_138 = L_38 ;
V_10 = V_12 ;
V_86 = 32 ;
memcpy ( V_52 , V_151 , sizeof( V_151 ) ) ;
memcpy ( V_13 , V_152 , sizeof( V_152 ) ) ;
break;
case 9 :
V_10 = V_12 ;
V_86 = 32 ;
memcpy ( V_52 , V_153 , sizeof( V_153 ) ) ;
memcpy ( V_13 , V_154 , sizeof( V_154 ) ) ;
switch ( V_137 -> V_144 ) {
case 0 ... 1 :
V_82 = V_83 ;
V_138 = L_39 ;
break;
case 2 ... 4 :
V_82 = V_83 ;
V_138 = L_40 ;
break;
case 5 ... 15 :
V_82 = V_85 ;
V_138 = L_41 ;
break;
}
break;
default:
V_138 = L_42 ;
break;
}
if ( V_10 == V_11 ) {
F_4 ( V_27 , V_7 , V_8 ) ;
if ( V_7 == 0 && V_8 == 0 )
V_10 = V_66 ;
}
F_27 (KERN_INFO PFX L_43 , cpuname) ;
switch ( V_10 ) {
case V_66 :
case V_11 :
F_27 ( V_155 L_44 , V_10 ) ;
break;
case V_12 :
F_27 ( V_155 L_45 ) ;
break;
} ;
F_48 () ;
F_52 ( V_156 , V_157 ,
V_158 , & F_40 , NULL ,
NULL , ( void * ) & V_63 ) ;
if ( V_63 != NULL && V_10 == V_12 ) {
V_69 = & V_63 -> V_159 . V_160 [ V_161 ] ;
if ( V_69 -> V_38 > 0 && V_69 -> V_162 <= 1000 )
V_61 |= V_67 ;
}
if ( V_163 )
V_61 &= ~ V_67 ;
if ( F_43 () )
V_61 |= V_62 ;
if ( ! ( V_61 & V_67
|| V_61 & V_62 )
&& ( ( V_63 == NULL ) || ! ( V_63 -> V_45 . V_64 ) ) ) {
F_27 (KERN_ERR PFX
L_46 ) ;
return - V_90 ;
}
if ( V_61 & V_62 )
F_27 (KERN_INFO PFX L_47 ) ;
if ( V_61 & V_67 )
F_27 (KERN_INFO PFX L_48 ) ;
V_139 = F_30 () ;
if ( V_139 != 0 )
return V_139 ;
if ( ( V_10 != V_66 ) && ( V_164 != 0 ) )
F_34 () ;
V_41 -> V_165 . V_166 = 200000 ;
V_41 -> V_167 = F_2 ( F_3 () ) ;
V_139 = F_53 ( V_41 , V_50 ) ;
if ( V_139 )
return V_139 ;
F_54 ( V_50 , V_41 -> V_118 ) ;
return 0 ;
}
static int F_55 ( struct V_40 * V_41 )
{
F_56 ( V_41 -> V_118 ) ;
return 0 ;
}
static int T_7 F_57 ( void )
{
struct V_136 * V_137 = & F_51 ( 0 ) ;
if ( ! F_58 ( V_168 ) )
return - V_90 ;
if ( ! V_169 ) {
F_27 (KERN_ERR PFX L_49 ) ;
return - V_90 ;
}
#ifdef F_59
if ( F_60 () > 1 ) {
F_27 (KERN_ERR PFX L_50
L_51 ) ;
return - V_90 ;
}
#endif
#ifdef F_61
if ( V_170 ) {
F_27 (KERN_ERR PFX L_52
L_53 ) ;
return - V_90 ;
}
#endif
switch ( V_137 -> V_140 ) {
case 6 ... 9 :
return F_62 ( & V_171 ) ;
case 10 :
F_27 (KERN_ERR PFX L_54 ) ;
default:
;
}
return - V_90 ;
}
static void T_8 F_63 ( void )
{
struct V_40 * V_41 = F_64 ( 0 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_86 ; V_72 ++ ) {
if ( V_52 [ V_72 ] == V_81 ) {
F_15 ( V_41 , V_72 ) ;
break;
}
}
F_65 ( V_41 ) ;
F_66 ( & V_171 ) ;
F_32 ( V_50 ) ;
}
