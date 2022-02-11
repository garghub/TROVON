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
static int F_15 ( struct V_40 * V_41 ,
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
return - V_53 ;
V_1 = F_2 ( V_3 ) ;
if ( ( V_1 > V_54 ) || ( V_1 < V_55 ) )
return - V_53 ;
if ( V_33 && V_56 < V_42 )
V_23 = 1 ;
V_44 . V_57 = F_2 ( F_3 () ) ;
V_44 . V_58 = V_1 ;
F_16 ( L_4 ,
V_5 , V_3 / 10 , V_3 % 10 , F_1 ( V_1 / 1000 ) ) ;
V_59:
F_17 () ;
F_18 ( V_45 ) ;
V_47 = F_13 ( 0xA1 ) ;
V_46 = F_13 ( 0x21 ) ;
F_19 ( 0xFF , 0xA1 ) ;
F_19 ( 0xFE , 0x21 ) ;
if ( V_60 && ( V_61 & V_62
|| ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) ) ) {
V_48 = F_20 ( V_60 ) ;
V_48 &= 1 << 4 ;
while ( V_48 && V_49 ) {
F_21 ( 1 << 4 , V_60 ) ;
V_49 -- ;
V_48 = F_20 ( V_60 ) ;
V_48 &= 1 << 4 ;
}
}
if ( V_61 & V_62 ) {
F_19 ( 3 , 0x22 ) ;
} else if ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) {
F_22 ( V_65 , 1 ) ;
}
switch ( V_10 ) {
case V_66 :
F_5 ( V_14 ) ;
break;
case V_11 :
case V_12 :
if ( V_61 & V_67 ) {
F_22 ( V_68 , 0 ) ;
F_12 ( V_69 -> V_38 , V_14 , V_23 ) ;
} else {
F_12 ( 0 , V_14 , V_23 ) ;
}
break;
}
if ( V_61 & V_62 ) {
F_19 ( 0 , 0x22 ) ;
} else if ( ( V_63 != NULL ) && V_63 -> V_45 . V_64 ) {
F_22 ( V_65 , 0 ) ;
}
F_19 ( V_47 , 0xA1 ) ;
F_19 ( V_46 , 0x21 ) ;
F_23 ( V_45 ) ;
F_24 () ;
V_44 . V_58 = F_2 ( F_3 () ) ;
if ( F_25 ( V_44 . V_58 != V_1 ) ) {
F_26 (KERN_INFO PFX L_5 ) ;
if ( ! V_28 ) {
F_26 (KERN_INFO PFX L_6
L_7 ) ;
V_28 = 1 ;
F_27 ( 200 ) ;
goto V_59;
}
if ( V_61 & V_67 ) {
F_26 (KERN_INFO PFX L_8 ) ;
V_61 &= ~ V_67 ;
if ( V_28 ) {
F_26 (KERN_INFO PFX L_9
L_10 ) ;
V_28 = 0 ;
}
F_27 ( 200 ) ;
goto V_59;
}
if ( V_10 == V_11 ) {
F_26 (KERN_INFO PFX L_11 ) ;
V_10 = V_66 ;
F_27 ( 200 ) ;
goto V_59;
}
}
if ( ! V_49 ) {
F_26 (KERN_INFO PFX L_12
L_13 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_28 ( int V_3 )
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
static int F_29 ( void )
{
unsigned int V_72 , V_77 , V_78 = 0 ;
unsigned int V_79 ;
int V_3 ;
V_3 = F_3 () ;
if ( V_3 == - 1 ) {
F_26 (KERN_INFO PFX L_14 ) ;
return - V_53 ;
}
V_5 = F_28 ( V_3 ) ;
if ( V_5 == 0 ) {
F_26 (KERN_INFO PFX L_15 ) ;
return - V_53 ;
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
F_16 ( L_16 ,
V_83 / 10 , V_83 % 10 , V_80 / 10 , V_80 % 10 ) ;
V_54 = F_2 ( V_80 ) ;
V_55 = F_2 ( V_83 ) ;
F_16 ( L_17 , V_5 ,
F_1 ( V_55 / 1000 ) ,
F_1 ( V_54 / 1000 ) ) ;
if ( V_55 == V_54 ) {
F_26 (KERN_INFO PFX L_18 ) ;
return - V_53 ;
}
if ( V_55 > V_54 ) {
F_26 (KERN_INFO PFX L_19 ,
lowest_speed, highest_speed) ;
return - V_53 ;
}
V_50 = F_30 ( ( V_85 + 1 ) * sizeof( * V_50 ) ,
V_86 ) ;
if ( ! V_50 )
return - V_87 ;
for ( V_77 = 0 ; V_77 < V_85 ; V_77 ++ ) {
V_79 = V_52 [ V_77 ] ;
if ( V_79 == - 1 )
continue;
if ( V_79 > V_80 || V_79 < V_83 )
continue;
V_50 [ V_78 ] . V_88 = F_2 ( V_79 ) ;
V_50 [ V_78 ] . V_51 = V_77 ;
V_78 ++ ;
}
if ( V_78 <= 1 ) {
F_31 ( V_50 ) ;
return - V_89 ;
}
for ( V_77 = 0 ; V_77 < V_78 - 1 ; V_77 ++ ) {
unsigned int V_90 , V_91 ;
V_90 = V_50 [ V_77 ] . V_88 ;
V_91 = V_77 ;
for ( V_72 = V_77 + 1 ; V_72 < V_78 ; V_72 ++ ) {
if ( V_50 [ V_72 ] . V_88 < V_90 ) {
V_90 = V_50 [ V_72 ] . V_88 ;
V_91 = V_72 ;
}
}
if ( V_91 != V_77 ) {
F_32 ( V_50 [ V_77 ] . V_88 ,
V_50 [ V_91 ] . V_88 ) ;
F_32 ( V_50 [ V_77 ] . V_51 ,
V_50 [ V_91 ] . V_51 ) ;
}
}
V_50 [ V_78 ] . V_88 = V_92 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
if ( V_52 [ V_50 [ V_77 ] . V_51 & 0x1f ] == V_3 ) {
V_56 = V_77 ;
break;
}
}
return 0 ;
}
static void F_33 ( void )
{
union V_24 V_25 ;
struct V_93 V_94 , V_95 , V_96 ;
unsigned int V_77 , V_1 , V_97 , V_98 , V_99 ;
int V_100 ;
F_6 ( V_27 , V_25 . V_18 ) ;
if ( ! ( V_25 . V_19 . V_30 & 1 ) ) {
F_26 (KERN_INFO PFX L_20 ) ;
return;
}
if ( ! V_25 . V_19 . V_101 ) {
F_26 (KERN_INFO PFX L_21 ) ;
V_102 = & V_103 [ 0 ] ;
V_104 = & V_105 [ 0 ] ;
} else {
F_26 (KERN_INFO PFX L_22 ) ;
if ( V_81 < V_82 )
return;
V_102 = & V_106 [ 0 ] ;
V_104 = & V_107 [ 0 ] ;
}
V_94 = V_102 [ V_25 . V_19 . V_108 ] ;
V_95 = V_102 [ V_25 . V_19 . V_109 ] ;
if ( V_94 . V_110 == 0 || V_95 . V_110 == 0 || V_94 . V_110 > V_95 . V_110 ) {
F_26 (KERN_INFO PFX L_23
L_24 ,
minvid.mV/1000 , minvid.mV%1000 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
if ( V_94 . V_110 == V_95 . V_110 ) {
F_26 (KERN_INFO PFX L_25
L_26
L_27 ,
maxvid.mV/1000 , maxvid.mV%1000 ) ;
return;
}
V_99 = V_95 . V_97 - V_94 . V_97 + 1 ;
F_26 (KERN_INFO PFX
L_28
L_29
L_30 ,
maxvid.mV/1000 , maxvid.mV%1000 ,
minvid.mV/1000 , minvid.mV%1000 ,
numvscales) ;
V_77 = V_25 . V_19 . V_111 ;
if ( V_25 . V_19 . V_112 )
V_77 += 16 ;
V_100 = V_13 [ V_77 ] ;
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
if ( V_100 >= V_54 )
return;
V_98 = ( V_54 - V_100 ) / V_99 ;
V_77 = 0 ;
while ( V_50 [ V_77 ] . V_88 != V_92 ) {
V_1 = V_50 [ V_77 ] . V_88 ;
if ( V_1 > V_100 )
V_97 = ( V_1 - V_100 ) / V_98 + V_94 . V_97 ;
else
V_97 = V_94 . V_97 ;
V_50 [ V_77 ] . V_51 |= V_104 [ V_97 ] << 8 ;
V_96 = V_102 [ V_104 [ V_97 ] ] ;
F_26 (KERN_INFO PFX L_31 ,
speed, j, vid.mV) ;
V_77 ++ ;
}
V_33 = 1 ;
F_26 (KERN_INFO PFX L_32 ) ;
}
static int F_34 ( struct V_40 * V_41 ,
unsigned int V_42 )
{
unsigned int V_72 ;
unsigned int V_23 = 0 ;
T_3 V_96 , V_114 ;
int V_115 = 0 ;
if ( ! V_33 )
V_115 = F_15 ( V_41 , V_42 ) ;
else {
V_72 = V_56 ;
V_114 = ( V_50 [ V_56 ] . V_51 >> 8 ) ;
V_114 &= 0x1f ;
if ( V_42 > V_56 )
V_23 = 1 ;
while ( V_72 != V_42 ) {
V_96 = ( V_50 [ V_72 ] . V_51 >> 8 ) & 0x1f ;
if ( V_96 != V_114 ) {
V_115 = F_15 ( V_41 , V_72 ) ;
V_114 = V_96 ;
F_27 ( 200 ) ;
}
if ( V_23 )
V_72 ++ ;
else
V_72 -- ;
}
V_115 = F_15 ( V_41 , V_42 ) ;
}
V_56 = V_42 ;
return V_115 ;
}
static unsigned int F_35 ( unsigned int V_116 )
{
if ( V_116 )
return 0 ;
return F_2 ( F_3 () ) ;
}
static T_4 F_36 ( T_5 V_117 ,
T_1 V_118 ,
void * V_119 , void * * V_120 )
{
struct V_121 * V_122 ;
if ( F_37 ( V_117 , & V_122 ) )
return 0 ;
* V_120 = F_38 ( V_122 ) ;
return 1 ;
}
static int F_39 ( void )
{
struct V_123 * V_124 ;
int V_125 = 1 ;
int V_126 ;
T_3 V_127 ;
V_126 = 0x78 ;
V_124 = F_40 ( V_128 , V_129 ,
NULL ) ;
if ( V_124 == NULL )
V_124 = F_40 ( V_128 ,
V_130 , NULL ) ;
if ( V_124 == NULL ) {
V_126 = 0x76 ;
V_124 = F_40 ( V_128 ,
V_131 , NULL ) ;
if ( V_124 == NULL )
V_124 = F_40 ( V_128 , 0x7259 , NULL ) ;
}
if ( V_124 != NULL ) {
F_41 ( V_124 , V_126 , & V_127 ) ;
if ( ! ( V_127 & 1 << 7 ) ) {
V_127 |= 1 << 7 ;
F_42 ( V_124 , V_126 , V_127 ) ;
F_41 ( V_124 , V_126 , & V_127 ) ;
if ( ! ( V_127 & 1 << 7 ) ) {
F_26 (KERN_ERR PFX
L_33 ) ;
V_125 = 0 ;
}
}
F_43 ( V_124 ) ;
return V_125 ;
}
return 0 ;
}
static int F_44 ( void )
{
struct V_123 * V_124 ;
T_3 V_127 ;
V_124 = F_40 ( V_128 , V_132 , NULL ) ;
if ( V_124 == NULL )
V_124 = F_40 ( V_128 ,
V_133 , NULL ) ;
if ( V_124 != NULL ) {
F_41 ( V_124 , 0xec , & V_127 ) ;
V_127 &= ~ ( 1 << 2 ) ;
F_42 ( V_124 , 0xec , V_127 ) ;
F_41 ( V_124 , 0xe4 , & V_127 ) ;
V_127 &= ~ ( 1 << 7 ) ;
F_42 ( V_124 , 0xe4 , V_127 ) ;
F_41 ( V_124 , 0xe5 , & V_127 ) ;
V_127 |= 1 << 7 ;
F_42 ( V_124 , 0xe5 , V_127 ) ;
F_41 ( V_124 , 0x81 , & V_127 ) ;
if ( V_127 & 1 << 7 ) {
F_45 ( V_124 , 0x88 , & V_60 ) ;
V_60 &= 0xff00 ;
F_26 (KERN_INFO PFX L_34 ,
acpi_regs_addr) ;
}
F_43 ( V_124 ) ;
return 1 ;
}
return 0 ;
}
static int F_46 ( struct V_40 * V_41 )
{
struct V_134 * V_135 = & F_47 ( 0 ) ;
char * V_136 = NULL ;
int V_137 ;
T_1 V_7 , V_8 ;
switch ( V_135 -> V_138 ) {
case 6 :
V_81 = V_139 ;
V_136 = L_35 ;
V_10 = V_66 ;
memcpy ( V_52 , V_140 , sizeof( V_140 ) ) ;
memcpy ( V_13 , V_141 , sizeof( V_141 ) ) ;
break;
case 7 :
switch ( V_135 -> V_142 ) {
case 0 :
V_10 = V_66 ;
V_81 = V_143 ;
V_136 = L_36 ;
memcpy ( V_52 , V_140 , sizeof( V_140 ) ) ;
memcpy ( V_13 , V_144 , sizeof( V_144 ) ) ;
break;
case 1 ... 15 :
V_10 = V_11 ;
if ( V_135 -> V_142 < 8 ) {
V_81 = V_143 ;
V_136 = L_36 ;
} else {
V_81 = V_145 ;
V_136 = L_37 ;
}
memcpy ( V_52 , V_146 , sizeof( V_146 ) ) ;
memcpy ( V_13 , V_147 , sizeof( V_147 ) ) ;
break;
}
break;
case 8 :
V_81 = V_148 ;
V_136 = L_38 ;
V_10 = V_12 ;
V_85 = 32 ;
memcpy ( V_52 , V_149 , sizeof( V_149 ) ) ;
memcpy ( V_13 , V_150 , sizeof( V_150 ) ) ;
break;
case 9 :
V_10 = V_12 ;
V_85 = 32 ;
memcpy ( V_52 , V_151 , sizeof( V_151 ) ) ;
memcpy ( V_13 , V_152 , sizeof( V_152 ) ) ;
switch ( V_135 -> V_142 ) {
case 0 ... 1 :
V_81 = V_82 ;
V_136 = L_39 ;
break;
case 2 ... 4 :
V_81 = V_82 ;
V_136 = L_40 ;
break;
case 5 ... 15 :
V_81 = V_84 ;
V_136 = L_41 ;
break;
}
break;
default:
V_136 = L_42 ;
break;
}
if ( V_10 == V_11 ) {
F_4 ( V_27 , V_7 , V_8 ) ;
if ( V_7 == 0 && V_8 == 0 )
V_10 = V_66 ;
}
F_26 (KERN_INFO PFX L_43 , cpuname) ;
switch ( V_10 ) {
case V_66 :
case V_11 :
F_26 ( V_153 L_44 , V_10 ) ;
break;
case V_12 :
F_26 ( V_153 L_45 ) ;
break;
} ;
F_44 () ;
F_48 ( V_154 , V_155 ,
V_156 , & F_36 , NULL ,
NULL , ( void * ) & V_63 ) ;
if ( V_63 != NULL && V_10 == V_12 ) {
V_69 = & V_63 -> V_157 . V_158 [ V_159 ] ;
if ( V_69 -> V_38 > 0 && V_69 -> V_160 <= 1000 )
V_61 |= V_67 ;
}
if ( V_161 )
V_61 &= ~ V_67 ;
if ( F_39 () )
V_61 |= V_62 ;
if ( ! ( V_61 & V_67
|| V_61 & V_62 )
&& ( ( V_63 == NULL ) || ! ( V_63 -> V_45 . V_64 ) ) ) {
F_26 (KERN_ERR PFX
L_46 ) ;
return - V_89 ;
}
if ( V_61 & V_62 )
F_26 (KERN_INFO PFX L_47 ) ;
if ( V_61 & V_67 )
F_26 (KERN_INFO PFX L_48 ) ;
V_137 = F_29 () ;
if ( V_137 != 0 )
return V_137 ;
if ( ( V_10 != V_66 ) && ( V_162 != 0 ) )
F_33 () ;
V_41 -> V_163 . V_164 = 200000 ;
return F_49 ( V_41 , V_50 ) ;
}
static int T_6 F_50 ( void )
{
struct V_134 * V_135 = & F_47 ( 0 ) ;
if ( ! F_51 ( V_165 ) )
return - V_89 ;
if ( ! V_166 ) {
F_26 (KERN_ERR PFX L_49 ) ;
return - V_89 ;
}
#ifdef F_52
if ( F_53 () > 1 ) {
F_26 (KERN_ERR PFX L_50
L_51 ) ;
return - V_89 ;
}
#endif
#ifdef F_54
if ( V_167 ) {
F_26 (KERN_ERR PFX L_52
L_53 ) ;
return - V_89 ;
}
#endif
switch ( V_135 -> V_138 ) {
case 6 ... 9 :
return F_55 ( & V_168 ) ;
case 10 :
F_26 (KERN_ERR PFX L_54 ) ;
default:
;
}
return - V_89 ;
}
static void T_7 F_56 ( void )
{
struct V_40 * V_41 = F_57 ( 0 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_85 ; V_72 ++ ) {
if ( V_52 [ V_72 ] == V_80 ) {
struct V_43 V_44 ;
V_44 . V_57 = V_41 -> V_169 ;
V_44 . V_58 = V_50 [ V_72 ] . V_88 ;
V_44 . V_45 = 0 ;
F_58 ( V_41 , & V_44 ) ;
F_15 ( V_41 , V_72 ) ;
F_59 ( V_41 , & V_44 , 0 ) ;
break;
}
}
F_60 ( V_41 ) ;
F_61 ( & V_168 ) ;
F_31 ( V_50 ) ;
}
