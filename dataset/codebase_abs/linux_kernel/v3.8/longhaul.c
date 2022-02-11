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
static void F_15 ( unsigned int V_40 )
{
unsigned int V_14 ;
int V_1 , V_3 ;
struct V_41 V_42 ;
unsigned long V_43 ;
unsigned int V_44 , V_45 ;
T_2 V_46 = 0 ;
T_1 V_47 = 1000 ;
unsigned int V_23 = 0 ;
V_14 = V_48 [ V_40 ] . V_49 ;
V_3 = V_50 [ V_14 & 0x1f ] ;
if ( V_3 == - 1 )
return;
V_1 = F_2 ( V_3 ) ;
if ( ( V_1 > V_51 ) || ( V_1 < V_52 ) )
return;
if ( V_33 && V_53 < V_40 )
V_23 = 1 ;
V_42 . V_54 = F_2 ( F_3 () ) ;
V_42 . V_55 = V_1 ;
V_42 . V_56 = 0 ;
F_16 ( & V_42 , V_57 ) ;
F_17 ( L_4 ,
V_5 , V_3 / 10 , V_3 % 10 , F_1 ( V_1 / 1000 ) ) ;
V_58:
F_18 () ;
F_19 ( V_43 ) ;
V_45 = F_13 ( 0xA1 ) ;
V_44 = F_13 ( 0x21 ) ;
F_20 ( 0xFF , 0xA1 ) ;
F_20 ( 0xFE , 0x21 ) ;
if ( V_59 && ( V_60 & V_61
|| ( ( V_62 != NULL ) && V_62 -> V_43 . V_63 ) ) ) {
V_46 = F_21 ( V_59 ) ;
V_46 &= 1 << 4 ;
while ( V_46 && V_47 ) {
F_22 ( 1 << 4 , V_59 ) ;
V_47 -- ;
V_46 = F_21 ( V_59 ) ;
V_46 &= 1 << 4 ;
}
}
if ( V_60 & V_61 ) {
F_20 ( 3 , 0x22 ) ;
} else if ( ( V_62 != NULL ) && V_62 -> V_43 . V_63 ) {
F_23 ( V_64 , 1 ) ;
}
switch ( V_10 ) {
case V_65 :
F_5 ( V_14 ) ;
break;
case V_11 :
case V_12 :
if ( V_60 & V_66 ) {
F_23 ( V_67 , 0 ) ;
F_12 ( V_68 -> V_38 , V_14 , V_23 ) ;
} else {
F_12 ( 0 , V_14 , V_23 ) ;
}
break;
}
if ( V_60 & V_61 ) {
F_20 ( 0 , 0x22 ) ;
} else if ( ( V_62 != NULL ) && V_62 -> V_43 . V_63 ) {
F_23 ( V_64 , 0 ) ;
}
F_20 ( V_45 , 0xA1 ) ;
F_20 ( V_44 , 0x21 ) ;
F_24 ( V_43 ) ;
F_25 () ;
V_42 . V_55 = F_2 ( F_3 () ) ;
if ( F_26 ( V_42 . V_55 != V_1 ) ) {
F_27 (KERN_INFO PFX L_5 ) ;
if ( ! V_28 ) {
F_27 (KERN_INFO PFX L_6
L_7 ) ;
V_28 = 1 ;
F_28 ( 200 ) ;
goto V_58;
}
if ( V_60 & V_66 ) {
F_27 (KERN_INFO PFX L_8 ) ;
V_60 &= ~ V_66 ;
if ( V_28 ) {
F_27 (KERN_INFO PFX L_9
L_10 ) ;
V_28 = 0 ;
}
F_28 ( 200 ) ;
goto V_58;
}
if ( V_10 == V_11 ) {
F_27 (KERN_INFO PFX L_11 ) ;
V_10 = V_65 ;
F_28 ( 200 ) ;
goto V_58;
}
}
F_16 ( & V_42 , V_69 ) ;
if ( ! V_47 )
F_27 (KERN_INFO PFX L_12
L_13 ) ;
}
static int F_29 ( int V_3 )
{
int V_1 = V_70 / 1000 ;
int V_71 ;
int V_72 [] = { 666 , 1000 , 1333 , 2000 } ;
int V_73 , V_74 ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ ) {
V_73 = ( ( V_72 [ V_71 ] * V_3 ) + 50 ) / 100 ;
V_73 += ( V_75 / 2 ) ;
V_74 = V_73 - V_75 ;
if ( ( V_1 <= V_73 ) && ( V_1 >= V_74 ) )
return V_72 [ V_71 ] / 10 ;
}
return 0 ;
}
static int T_3 F_30 ( void )
{
unsigned int V_71 , V_76 , V_77 = 0 ;
unsigned int V_78 ;
int V_3 ;
V_3 = F_3 () ;
if ( V_3 == - 1 ) {
F_27 (KERN_INFO PFX L_14 ) ;
return - V_79 ;
}
V_5 = F_29 ( V_3 ) ;
if ( V_5 == 0 ) {
F_27 (KERN_INFO PFX L_15 ) ;
return - V_79 ;
}
V_80 = V_3 ;
switch ( V_81 ) {
case V_82 :
V_83 = 50 ;
break;
case V_84 :
V_83 = 40 ;
break;
default:
V_83 = 30 ;
break;
}
F_17 ( L_16 ,
V_83 / 10 , V_83 % 10 , V_80 / 10 , V_80 % 10 ) ;
V_51 = F_2 ( V_80 ) ;
V_52 = F_2 ( V_83 ) ;
F_17 ( L_17 , V_5 ,
F_1 ( V_52 / 1000 ) ,
F_1 ( V_51 / 1000 ) ) ;
if ( V_52 == V_51 ) {
F_27 (KERN_INFO PFX L_18 ) ;
return - V_79 ;
}
if ( V_52 > V_51 ) {
F_27 (KERN_INFO PFX L_19 ,
lowest_speed, highest_speed) ;
return - V_79 ;
}
V_48 = F_31 ( ( V_85 + 1 ) * sizeof( * V_48 ) ,
V_86 ) ;
if ( ! V_48 )
return - V_87 ;
for ( V_76 = 0 ; V_76 < V_85 ; V_76 ++ ) {
V_78 = V_50 [ V_76 ] ;
if ( V_78 == - 1 )
continue;
if ( V_78 > V_80 || V_78 < V_83 )
continue;
V_48 [ V_77 ] . V_88 = F_2 ( V_78 ) ;
V_48 [ V_77 ] . V_49 = V_76 ;
V_77 ++ ;
}
if ( V_77 <= 1 ) {
F_32 ( V_48 ) ;
return - V_89 ;
}
for ( V_76 = 0 ; V_76 < V_77 - 1 ; V_76 ++ ) {
unsigned int V_90 , V_91 ;
V_90 = V_48 [ V_76 ] . V_88 ;
V_91 = V_76 ;
for ( V_71 = V_76 + 1 ; V_71 < V_77 ; V_71 ++ ) {
if ( V_48 [ V_71 ] . V_88 < V_90 ) {
V_90 = V_48 [ V_71 ] . V_88 ;
V_91 = V_71 ;
}
}
if ( V_91 != V_76 ) {
F_33 ( V_48 [ V_76 ] . V_88 ,
V_48 [ V_91 ] . V_88 ) ;
F_33 ( V_48 [ V_76 ] . V_49 ,
V_48 [ V_91 ] . V_49 ) ;
}
}
V_48 [ V_77 ] . V_88 = V_92 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
if ( V_50 [ V_48 [ V_76 ] . V_49 & 0x1f ] == V_3 ) {
V_53 = V_76 ;
break;
}
}
return 0 ;
}
static void T_3 F_34 ( void )
{
union V_24 V_25 ;
struct V_93 V_94 , V_95 , V_96 ;
unsigned int V_76 , V_1 , V_97 , V_98 , V_99 ;
int V_100 ;
F_6 ( V_27 , V_25 . V_18 ) ;
if ( ! ( V_25 . V_19 . V_30 & 1 ) ) {
F_27 (KERN_INFO PFX L_20 ) ;
return;
}
if ( ! V_25 . V_19 . V_101 ) {
F_27 (KERN_INFO PFX L_21 ) ;
V_102 = & V_103 [ 0 ] ;
V_104 = & V_105 [ 0 ] ;
} else {
F_27 (KERN_INFO PFX L_22 ) ;
if ( V_81 < V_82 )
return;
V_102 = & V_106 [ 0 ] ;
V_104 = & V_107 [ 0 ] ;
}
V_94 = V_102 [ V_25 . V_19 . V_108 ] ;
V_95 = V_102 [ V_25 . V_19 . V_109 ] ;
if ( V_94 . V_110 == 0 || V_95 . V_110 == 0 || V_94 . V_110 > V_95 . V_110 ) {
F_27 (KERN_INFO PFX L_23
L_24 ,
minvid.mV/1000 , minvid.mV%1000 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
if ( V_94 . V_110 == V_95 . V_110 ) {
F_27 (KERN_INFO PFX L_25
L_26
L_27 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
V_99 = V_95 . V_97 - V_94 . V_97 + 1 ;
F_27 (KERN_INFO PFX
L_28
L_29
L_30 ,
maxvid.mV/1000 , maxvid.mV%1000 ,
minvid.mV/1000 , minvid.mV%1000 ,
numvscales) ;
V_76 = V_25 . V_19 . V_111 ;
if ( V_25 . V_19 . V_112 )
V_76 += 16 ;
V_100 = V_13 [ V_76 ] ;
if ( V_100 == - 1 )
return;
switch ( V_25 . V_19 . V_113 ) {
case 0 :
V_100 *= 13333 ;
break;
case 1 :
V_100 *= 10000 ;
break;
case 3 :
V_100 *= 6666 ;
break;
default:
return;
break;
}
if ( V_100 >= V_51 )
return;
V_98 = ( V_51 - V_100 ) / V_99 ;
V_76 = 0 ;
while ( V_48 [ V_76 ] . V_88 != V_92 ) {
V_1 = V_48 [ V_76 ] . V_88 ;
if ( V_1 > V_100 )
V_97 = ( V_1 - V_100 ) / V_98 + V_94 . V_97 ;
else
V_97 = V_94 . V_97 ;
V_48 [ V_76 ] . V_49 |= V_104 [ V_97 ] << 8 ;
V_96 = V_102 [ V_104 [ V_97 ] ] ;
F_27 (KERN_INFO PFX L_31 ,
speed, j, vid.mV) ;
V_76 ++ ;
}
V_33 = 1 ;
F_27 (KERN_INFO PFX L_32 ) ;
}
static int F_35 ( struct V_114 * V_115 )
{
return F_36 ( V_115 , V_48 ) ;
}
static int F_37 ( struct V_114 * V_115 ,
unsigned int V_116 , unsigned int V_117 )
{
unsigned int V_40 = 0 ;
unsigned int V_71 ;
unsigned int V_23 = 0 ;
T_4 V_96 , V_118 ;
if ( F_38 ( V_115 , V_48 , V_116 ,
V_117 , & V_40 ) )
return - V_79 ;
if ( V_53 == V_40 )
return 0 ;
if ( ! V_33 )
F_15 ( V_40 ) ;
else {
V_71 = V_53 ;
V_118 = ( V_48 [ V_53 ] . V_49 >> 8 ) ;
V_118 &= 0x1f ;
if ( V_40 > V_53 )
V_23 = 1 ;
while ( V_71 != V_40 ) {
V_96 = ( V_48 [ V_71 ] . V_49 >> 8 ) & 0x1f ;
if ( V_96 != V_118 ) {
F_15 ( V_71 ) ;
V_118 = V_96 ;
F_28 ( 200 ) ;
}
if ( V_23 )
V_71 ++ ;
else
V_71 -- ;
}
F_15 ( V_40 ) ;
}
V_53 = V_40 ;
return 0 ;
}
static unsigned int F_39 ( unsigned int V_56 )
{
if ( V_56 )
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
F_49 ( V_126 , 0x88 , & V_59 ) ;
V_59 &= 0xff00 ;
F_27 (KERN_INFO PFX L_34 ,
acpi_regs_addr) ;
}
F_47 ( V_126 ) ;
return 1 ;
}
return 0 ;
}
static int T_3 F_50 ( struct V_114 * V_115 )
{
struct V_136 * V_137 = & F_51 ( 0 ) ;
char * V_138 = NULL ;
int V_139 ;
T_1 V_7 , V_8 ;
switch ( V_137 -> V_140 ) {
case 6 :
V_81 = V_141 ;
V_138 = L_35 ;
V_10 = V_65 ;
memcpy ( V_50 , V_142 , sizeof( V_142 ) ) ;
memcpy ( V_13 , V_143 , sizeof( V_143 ) ) ;
break;
case 7 :
switch ( V_137 -> V_144 ) {
case 0 :
V_10 = V_65 ;
V_81 = V_145 ;
V_138 = L_36 ;
memcpy ( V_50 , V_142 , sizeof( V_142 ) ) ;
memcpy ( V_13 , V_146 , sizeof( V_146 ) ) ;
break;
case 1 ... 15 :
V_10 = V_11 ;
if ( V_137 -> V_144 < 8 ) {
V_81 = V_145 ;
V_138 = L_36 ;
} else {
V_81 = V_147 ;
V_138 = L_37 ;
}
memcpy ( V_50 , V_148 , sizeof( V_148 ) ) ;
memcpy ( V_13 , V_149 , sizeof( V_149 ) ) ;
break;
}
break;
case 8 :
V_81 = V_150 ;
V_138 = L_38 ;
V_10 = V_12 ;
V_85 = 32 ;
memcpy ( V_50 , V_151 , sizeof( V_151 ) ) ;
memcpy ( V_13 , V_152 , sizeof( V_152 ) ) ;
break;
case 9 :
V_10 = V_12 ;
V_85 = 32 ;
memcpy ( V_50 , V_153 , sizeof( V_153 ) ) ;
memcpy ( V_13 , V_154 , sizeof( V_154 ) ) ;
switch ( V_137 -> V_144 ) {
case 0 ... 1 :
V_81 = V_82 ;
V_138 = L_39 ;
break;
case 2 ... 4 :
V_81 = V_82 ;
V_138 = L_40 ;
break;
case 5 ... 15 :
V_81 = V_84 ;
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
V_10 = V_65 ;
}
F_27 (KERN_INFO PFX L_43 , cpuname) ;
switch ( V_10 ) {
case V_65 :
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
NULL , ( void * ) & V_62 ) ;
if ( V_62 != NULL && V_10 == V_12 ) {
V_68 = & V_62 -> V_159 . V_160 [ V_161 ] ;
if ( V_68 -> V_38 > 0 && V_68 -> V_162 <= 1000 )
V_60 |= V_66 ;
}
if ( V_163 )
V_60 &= ~ V_66 ;
if ( F_43 () )
V_60 |= V_61 ;
if ( ! ( V_60 & V_66
|| V_60 & V_61 )
&& ( ( V_62 == NULL ) || ! ( V_62 -> V_43 . V_63 ) ) ) {
F_27 (KERN_ERR PFX
L_46 ) ;
return - V_89 ;
}
if ( V_60 & V_61 )
F_27 (KERN_INFO PFX L_47 ) ;
if ( V_60 & V_66 )
F_27 (KERN_INFO PFX L_48 ) ;
V_139 = F_30 () ;
if ( V_139 != 0 )
return V_139 ;
if ( ( V_10 != V_65 ) && ( V_164 != 0 ) )
F_34 () ;
V_115 -> V_165 . V_166 = 200000 ;
V_115 -> V_167 = F_2 ( F_3 () ) ;
V_139 = F_53 ( V_115 , V_48 ) ;
if ( V_139 )
return V_139 ;
F_54 ( V_48 , V_115 -> V_56 ) ;
return 0 ;
}
static int F_55 ( struct V_114 * V_115 )
{
F_56 ( V_115 -> V_56 ) ;
return 0 ;
}
static int T_7 F_57 ( void )
{
struct V_136 * V_137 = & F_51 ( 0 ) ;
if ( ! F_58 ( V_168 ) )
return - V_89 ;
if ( ! V_169 ) {
F_27 (KERN_ERR PFX L_49 ) ;
return - V_89 ;
}
#ifdef F_59
if ( F_60 () > 1 ) {
F_27 (KERN_ERR PFX L_50
L_51 ) ;
return - V_89 ;
}
#endif
#ifdef F_61
if ( V_170 ) {
F_27 (KERN_ERR PFX L_52
L_53 ) ;
return - V_89 ;
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
return - V_89 ;
}
static void T_8 F_63 ( void )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_85 ; V_71 ++ ) {
if ( V_50 [ V_71 ] == V_80 ) {
F_15 ( V_71 ) ;
break;
}
}
F_64 ( & V_171 ) ;
F_32 ( V_48 ) ;
}
