static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_3 , V_1 ) ;
if ( V_4 ) {
if ( F_4 ( V_4 -> V_6 ) )
V_4 = NULL ;
else
F_5 ( & V_4 -> V_7 ) ;
}
F_6 ( & V_5 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_4 )
{
T_1 * V_6 = V_4 -> V_6 ;
F_2 ( & V_5 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_6 ) ;
F_6 ( & V_5 ) ;
}
static void F_10 ( T_1 * V_6 )
{
V_6 -> V_8 |= V_9 ;
V_6 -> V_10 &= ~ V_11 ;
}
static int F_11 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_6 -> V_16 ;
int log = 0 ;
if ( ! V_15 || ! V_13 || ( V_13 -> V_17 & V_18 ) )
return 0 ;
F_12 ( V_19 , L_1 , V_15 -> V_20 ) ;
switch ( V_15 -> V_20 ) {
case V_21 :
case V_22 :
break;
case V_23 :
if ( V_15 -> V_24 == 0x3a || V_15 -> V_24 == 0x04 )
break;
log = 1 ;
break;
case V_25 :
if ( V_13 -> V_26 [ 0 ] == V_27 && V_15 -> V_24 == 0x24 )
break;
log = 1 ;
break;
case V_28 :
F_10 ( V_6 ) ;
break;
default:
log = 1 ;
break;
}
return log ;
}
static void F_13 ( T_1 * V_6 ,
struct V_12 * V_29 )
{
struct V_14 * V_15 = & V_6 -> V_16 ;
struct V_1 * V_30 = V_6 -> V_31 ;
unsigned long V_32 ;
unsigned long V_33 ;
F_12 ( V_19 , L_2 ,
V_15 -> V_34 , V_15 -> V_20 ) ;
if ( V_29 )
F_12 ( V_19 , L_3 ,
V_29 -> V_26 [ 0 ] ) ;
if ( ! F_11 ( V_6 , V_29 ) )
return;
if ( V_29 && V_29 -> V_26 [ 0 ] == V_35 )
if ( V_15 -> V_20 == 0x05 && V_15 -> V_24 == 0x24 )
return;
if ( V_15 -> V_34 == 0x70 ) {
switch ( V_15 -> V_20 ) {
case V_36 :
case V_37 :
case V_25 :
if ( ! V_15 -> V_38 )
break;
if ( V_29 == NULL ||
V_29 -> V_39 != V_40 )
break;
V_32 = ( V_15 -> V_41 [ 0 ] << 24 ) |
( V_15 -> V_41 [ 1 ] << 16 ) |
( V_15 -> V_41 [ 2 ] << 8 ) |
( V_15 -> V_41 [ 3 ] ) ;
if ( F_14 ( V_6 -> V_42 ) == 2048 )
V_32 <<= 2 ;
V_33 = F_15 ( V_33 ( V_29 -> V_43 ) , 4U ) ;
V_32 &= ~ ( V_33 - 1 ) ;
if ( V_32 < F_16 ( V_30 -> V_3 ) &&
V_6 -> V_44 - V_32 < 4 * 75 )
F_17 ( V_30 -> V_3 , V_32 ) ;
}
}
F_18 ( V_6 -> V_45 , V_29 , V_15 ) ;
}
static void F_19 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_12 * V_46 = (struct V_12 * ) V_13 -> V_47 ;
void * V_15 = F_20 ( V_13 -> V_43 ) ;
if ( V_46 ) {
if ( V_46 -> V_15 ) {
memcpy ( V_46 -> V_15 , V_15 , 18 ) ;
V_46 -> V_48 = V_13 -> V_48 ;
}
F_13 ( V_6 , V_46 ) ;
if ( F_21 ( V_6 , V_46 , - V_49 , F_22 ( V_46 ) ) )
F_23 () ;
} else
F_13 ( V_6 , NULL ) ;
}
static int F_24 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
if ( ! V_13 -> V_50 )
V_30 -> V_51 = V_52 + V_53 ;
V_13 -> V_50 = 1 ;
if ( F_25 ( V_52 , V_30 -> V_51 ) )
return 0 ;
else {
F_26 ( V_6 -> V_42 , 1 ) ;
return 1 ;
}
}
static int F_27 ( T_1 * V_6 , T_2 V_54 )
{
T_3 * V_55 = V_6 -> V_55 ;
struct V_12 * V_13 = V_55 -> V_13 ;
int V_56 , V_20 , V_57 = 0 ;
V_56 = F_28 ( V_6 ) ;
V_20 = V_56 >> 4 ;
F_12 ( V_58 , L_4
L_5 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_39 , V_56 , V_54 ) ;
if ( V_13 -> V_39 == V_59 ) {
V_13 -> V_17 |= V_60 ;
return 2 ;
}
if ( V_13 -> V_39 == V_61 && ! V_13 -> V_50 )
V_13 -> V_50 = V_62 ;
if ( F_29 ( V_13 ) )
V_57 = 1 ;
switch ( V_20 ) {
case V_23 :
if ( V_13 -> V_39 == V_40 && F_30 ( V_13 ) == V_63 ) {
if ( F_24 ( V_6 , V_13 ) )
return 1 ;
} else {
F_10 ( V_6 ) ;
if ( V_13 -> V_39 == V_40 &&
! ( V_13 -> V_17 & V_18 ) )
F_31 (KERN_ERR PFX L_6 ,
drive->name) ;
}
V_57 = 1 ;
break;
case V_28 :
F_10 ( V_6 ) ;
if ( V_13 -> V_39 != V_40 )
return 0 ;
if ( ++ V_13 -> V_50 > V_64 )
V_57 = 1 ;
break;
case V_25 :
if ( V_13 -> V_26 [ 0 ] == V_27 )
break;
case V_65 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_32 ( V_6 , L_7 , V_54 ) ;
V_57 = 1 ;
break;
case V_36 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_32 ( V_6 , L_8
L_9 , V_54 ) ;
V_57 = 1 ;
break;
case V_66 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_32 ( V_6 , L_10 ,
V_54 ) ;
V_57 = 1 ;
break;
default:
if ( V_13 -> V_39 != V_40 )
break;
if ( V_56 & ~ V_67 ) {
F_33 ( V_6 , L_11 , V_54 ) ;
return 1 ;
} else if ( ++ V_13 -> V_50 > V_64 )
V_57 = 1 ;
}
if ( V_13 -> V_39 != V_40 ) {
V_13 -> V_17 |= V_60 ;
V_57 = 1 ;
}
if ( V_57 )
goto V_68;
if ( V_54 & V_69 )
return F_34 ( V_6 , NULL ) ? 2 : 1 ;
return 1 ;
V_68:
if ( V_54 & V_69 ) {
V_55 -> V_13 = NULL ;
return F_34 ( V_6 , V_13 ) ? 2 : 1 ;
} else
return 2 ;
}
static void F_35 ( T_1 * V_6 , struct V_70 * V_26 )
{
struct V_12 * V_13 = V_26 -> V_13 ;
F_12 ( V_71 , L_12 , V_13 -> V_26 [ 0 ] ) ;
if ( V_13 -> V_26 [ 0 ] == V_72 &&
V_26 -> V_73 > 0 && V_26 -> V_73 <= 5 )
V_26 -> V_73 = 0 ;
}
int F_36 ( T_1 * V_6 , const unsigned char * V_26 ,
int V_74 , void * V_75 , unsigned * V_76 ,
struct V_14 * V_15 , int V_77 ,
T_4 V_17 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_14 V_78 ;
int V_79 = 10 ;
T_4 V_80 = 0 ;
if ( ! V_15 )
V_15 = & V_78 ;
F_12 ( V_81 , L_13
L_14 ,
V_26 [ 0 ] , V_74 , V_77 , V_17 ) ;
do {
struct V_12 * V_13 ;
int error ;
V_13 = F_37 ( V_6 -> V_42 , V_74 , V_82 ) ;
memcpy ( V_13 -> V_26 , V_26 , V_83 ) ;
V_13 -> V_39 = V_84 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_17 |= V_17 ;
V_13 -> V_77 = V_77 ;
if ( V_75 ) {
error = F_38 ( V_6 -> V_42 , V_13 , V_75 ,
* V_76 , V_85 ) ;
if ( error ) {
F_39 ( V_13 ) ;
return error ;
}
}
error = F_40 ( V_6 -> V_42 , V_30 -> V_3 , V_13 , 0 ) ;
if ( V_75 )
* V_76 = V_13 -> V_86 ;
V_80 = V_13 -> V_17 ;
F_39 ( V_13 ) ;
if ( V_80 & V_60 ) {
struct V_14 * V_87 = V_15 ;
if ( V_87 -> V_20 == V_28 )
F_10 ( V_6 ) ;
else if ( V_87 -> V_20 == V_23 &&
V_87 -> V_24 == 4 && V_87 -> V_88 != 4 ) {
F_41 ( 2 ) ;
} else {
V_79 = 0 ;
}
-- V_79 ;
}
} while ( ( V_80 & V_60 ) && V_79 >= 0 );
return ( V_80 & V_60 ) ? - V_49 : 0 ;
}
static bool F_42 ( T_1 * V_6 , struct V_70 * V_26 )
{
unsigned int V_89 = V_26 -> V_90 - V_26 -> V_73 ;
if ( V_26 -> V_91 & V_92 )
V_89 -= V_26 -> V_93 ;
if ( V_89 > 0 ) {
F_43 ( V_6 , 0 , V_89 ) ;
return true ;
}
return false ;
}
static T_5 F_44 ( T_1 * V_6 )
{
T_3 * V_55 = V_6 -> V_55 ;
struct V_70 * V_26 = & V_55 -> V_26 ;
struct V_12 * V_13 = V_55 -> V_13 ;
T_6 * V_94 = NULL ;
int V_95 = 0 , V_96 , V_97 , V_98 = 0 ;
int V_74 = ( F_30 ( V_13 ) == V_63 ) ? 1 : 0 , V_99 = 0 ;
int V_15 = ( V_13 -> V_39 == V_59 ) ;
unsigned int V_77 ;
T_7 V_100 ;
T_2 V_101 , V_54 ;
F_12 ( V_81 , L_15 , V_13 -> V_26 [ 0 ] , V_74 ) ;
V_96 = V_6 -> V_96 ;
if ( V_96 ) {
V_6 -> V_96 = 0 ;
V_6 -> V_102 = 0 ;
V_95 = V_55 -> V_103 -> V_104 ( V_6 ) ;
F_45 ( V_6 , V_26 ) ;
if ( V_95 ) {
F_31 (KERN_ERR PFX L_16 , drive->name,
write ? L_17 : L_18 ) ;
F_46 ( V_6 ) ;
}
}
V_54 = V_55 -> V_105 -> V_106 ( V_55 ) ;
if ( ! F_47 ( V_54 , 0 , V_107 ) ) {
V_99 = F_27 ( V_6 , V_54 ) ;
if ( V_99 ) {
if ( V_99 == 2 )
goto V_108;
return V_109 ;
}
}
if ( V_96 ) {
if ( V_95 )
return F_33 ( V_6 , L_19 , V_54 ) ;
V_98 = 1 ;
goto V_108;
}
F_48 ( V_6 , & V_100 , & V_101 ) ;
V_97 = ( V_13 -> V_39 == V_40 ) ? V_100 : V_26 -> V_73 ;
if ( V_97 > V_100 )
V_97 = V_100 ;
F_12 ( V_81 , L_20 ,
V_54 , V_97 ) ;
if ( ( V_54 & V_110 ) == 0 ) {
if ( V_13 -> V_39 == V_40 ) {
V_98 = 1 ;
if ( V_26 -> V_73 > 0 ) {
F_31 (KERN_ERR PFX L_21
L_22 , drive->name, __func__,
cmd->nleft) ;
if ( ! V_74 )
V_13 -> V_17 |= V_60 ;
V_98 = 0 ;
}
} else if ( V_13 -> V_39 != V_61 ) {
F_35 ( V_6 , V_26 ) ;
V_98 = V_26 -> V_73 ? 0 : 1 ;
if ( ! ( V_54 & V_69 ) && ! V_98 && V_97 ) {
F_49 ( V_6 , V_26 , V_74 , V_97 ) ;
V_98 = V_26 -> V_73 ? 0 : 1 ;
}
if ( ! V_98 )
V_13 -> V_17 |= V_60 ;
}
goto V_108;
}
V_99 = F_50 ( V_6 , V_13 , V_100 , V_101 , V_74 ) ;
if ( V_99 )
goto V_108;
V_26 -> V_93 = 0 ;
F_12 ( V_81 , L_23
L_24 ,
V_13 -> V_39 , V_101 ) ;
while ( V_97 > 0 ) {
int V_111 = F_51 ( int , V_97 , V_26 -> V_73 ) ;
if ( V_26 -> V_73 == 0 )
break;
F_49 ( V_6 , V_26 , V_74 , V_111 ) ;
V_26 -> V_93 += V_111 ;
V_97 -= V_111 ;
V_100 -= V_111 ;
if ( V_15 && V_74 == 0 )
V_13 -> V_48 += V_111 ;
}
if ( V_100 > 0 ) {
if ( V_13 -> V_39 != V_40 || V_74 == 0 )
F_52 ( V_6 , V_74 , V_100 ) ;
else {
F_31 (KERN_ERR PFX L_25 ,
drive->name) ;
F_53 ( V_13 , L_26 ) ;
}
}
if ( V_13 -> V_39 == V_61 ) {
V_77 = V_13 -> V_77 ;
} else {
V_77 = V_112 ;
if ( V_13 -> V_39 != V_40 )
V_94 = V_113 ;
}
V_55 -> V_94 = V_94 ;
F_54 ( V_6 , F_44 , V_77 ) ;
return V_114 ;
V_108:
if ( V_13 -> V_39 == V_61 && V_99 == 0 ) {
V_13 -> V_86 = 0 ;
F_55 ( V_13 , 0 ) ;
V_55 -> V_13 = NULL ;
} else {
if ( V_15 && V_98 )
F_19 ( V_6 , V_13 ) ;
if ( V_13 -> V_39 == V_40 ) {
if ( V_26 -> V_73 == 0 )
V_98 = 1 ;
} else {
if ( V_98 <= 0 && V_13 -> V_50 == 0 )
V_13 -> V_50 = - V_49 ;
}
if ( V_98 == 0 && V_13 -> V_43 )
if ( F_42 ( V_6 , V_26 ) )
return V_109 ;
if ( V_13 -> V_39 != V_40 ) {
V_13 -> V_86 -= V_26 -> V_90 - V_26 -> V_73 ;
if ( V_98 == 0 && ( V_26 -> V_91 & V_92 ) )
V_13 -> V_86 += V_26 -> V_93 ;
}
F_43 ( V_6 , V_98 ? 0 : - V_49 , F_22 ( V_13 ) ) ;
if ( V_15 && V_99 == 2 )
F_33 ( V_6 , L_27 , V_54 ) ;
}
return V_109 ;
}
static T_5 F_56 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_115 * V_116 = V_6 -> V_42 ;
int V_74 = F_30 ( V_13 ) == V_63 ;
unsigned short V_117 =
F_14 ( V_116 ) >> V_118 ;
F_12 ( V_58 , L_28
L_29 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_119 , V_117 ) ;
if ( V_74 ) {
if ( F_57 ( V_4 -> V_3 ) )
return V_109 ;
} else {
V_116 -> V_120 ( V_116 , V_13 ) ;
}
if ( ( F_58 ( V_13 ) & ( V_117 - 1 ) ) ||
( F_59 ( V_13 ) & ( V_117 - 1 ) ) )
return V_109 ;
V_6 -> V_96 = ! ! ( V_6 -> V_8 & V_121 ) ;
if ( V_74 )
V_4 -> V_122 . V_123 = 1 ;
V_13 -> V_77 = V_112 ;
return V_114 ;
}
static void F_60 ( T_1 * V_6 , struct V_12 * V_13 )
{
F_12 ( V_81 , L_30 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_39 ) ;
if ( V_13 -> V_39 == V_61 )
V_13 -> V_17 |= V_18 ;
else
V_13 -> V_17 &= ~ V_60 ;
V_6 -> V_96 = 0 ;
if ( V_13 -> V_43 ) {
struct V_115 * V_116 = V_6 -> V_42 ;
char * V_124 = F_20 ( V_13 -> V_43 ) ;
unsigned int V_125 ;
V_6 -> V_96 = ! ! ( V_6 -> V_8 & V_121 ) ;
V_125 = F_61 ( V_116 ) | V_116 -> V_126 ;
if ( ( unsigned long ) V_124 & V_125
|| F_22 ( V_13 ) & V_116 -> V_126
|| F_62 ( V_124 ) )
V_6 -> V_96 = 0 ;
}
}
static T_5 F_63 ( T_1 * V_6 , struct V_12 * V_13 ,
T_8 V_127 )
{
struct V_70 V_26 ;
int V_98 = 0 ;
unsigned int V_128 ;
F_12 ( V_58 , L_31 ,
V_13 -> V_26 [ 0 ] , ( unsigned long long ) V_127 ) ;
if ( V_6 -> V_129 & V_58 )
F_53 ( V_13 , L_32 ) ;
switch ( V_13 -> V_39 ) {
case V_40 :
if ( F_56 ( V_6 , V_13 ) == V_109 )
goto V_108;
break;
case V_59 :
case V_61 :
case V_84 :
if ( ! V_13 -> V_77 )
V_13 -> V_77 = V_112 ;
F_60 ( V_6 , V_13 ) ;
break;
case V_130 :
V_98 = 1 ;
goto V_108;
default:
F_23 () ;
}
F_64 ( V_6 , V_13 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_30 ( V_13 ) )
V_26 . V_91 |= V_92 ;
V_26 . V_13 = V_13 ;
if ( V_13 -> V_39 == V_40 || F_22 ( V_13 ) ) {
F_65 ( & V_26 , F_22 ( V_13 ) ) ;
F_66 ( V_6 , & V_26 ) ;
}
return F_67 ( V_6 , & V_26 ) ;
V_108:
V_128 = F_58 ( V_13 ) ;
if ( V_128 == 0 )
V_128 = 1 ;
F_43 ( V_6 , V_98 ? 0 : - V_49 , V_128 << 9 ) ;
return V_109 ;
}
static void F_68 ( struct V_131 * V_132 )
{
V_132 -> V_133 = F_69 ( V_132 -> V_133 ) ;
V_132 -> V_134 = F_69 ( V_132 -> V_134 ) ;
V_132 -> V_135 = F_69 ( V_132 -> V_135 ) ;
}
int F_70 ( T_1 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_136 * V_137 = & V_30 -> V_122 ;
unsigned char V_26 [ V_83 ] ;
F_12 ( V_71 , L_33 ) ;
memset ( V_26 , 0 , V_83 ) ;
V_26 [ 0 ] = V_138 ;
V_26 [ 7 ] = V_137 -> V_139 % 3 ;
return F_36 ( V_6 , V_26 , 0 , NULL , NULL , V_15 , 0 , V_18 ) ;
}
static int F_71 ( T_1 * V_6 , unsigned long * V_140 ,
unsigned long * V_117 ,
struct V_14 * V_15 )
{
struct {
T_9 V_141 ;
T_9 V_142 ;
} V_143 ;
int V_54 ;
unsigned char V_26 [ V_83 ] ;
unsigned V_100 = sizeof( V_143 ) ;
T_10 V_142 ;
F_12 ( V_71 , L_33 ) ;
memset ( V_26 , 0 , V_83 ) ;
V_26 [ 0 ] = V_144 ;
V_54 = F_36 ( V_6 , V_26 , 0 , & V_143 , & V_100 , V_15 , 0 ,
V_18 ) ;
if ( V_54 )
return V_54 ;
V_142 = F_72 ( V_143 . V_142 ) ;
V_142 = ( V_142 >> V_118 ) << V_118 ;
switch ( V_142 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_73 (KERN_ERR PFX L_34
L_35 ,
drive->name, blocklen) ;
V_142 = 2048 ;
break;
}
* V_140 = 1 + F_72 ( V_143 . V_141 ) ;
* V_117 = V_142 >> V_118 ;
F_12 ( V_145 , L_36 ,
* V_140 , * V_117 ) ;
return 0 ;
}
static int F_74 ( T_1 * V_6 , int V_146 , int V_147 ,
int V_148 , char * V_124 , int V_149 ,
struct V_14 * V_15 )
{
unsigned char V_26 [ V_83 ] ;
F_12 ( V_71 , L_33 ) ;
memset ( V_26 , 0 , V_83 ) ;
V_26 [ 0 ] = V_35 ;
V_26 [ 6 ] = V_146 ;
V_26 [ 7 ] = ( V_149 >> 8 ) ;
V_26 [ 8 ] = ( V_149 & 0xff ) ;
V_26 [ 9 ] = ( V_148 << 6 ) ;
if ( V_147 )
V_26 [ 1 ] = 2 ;
return F_36 ( V_6 , V_26 , 0 , V_124 , & V_149 , V_15 , 0 , V_18 ) ;
}
int F_75 ( T_1 * V_6 , struct V_14 * V_15 )
{
int V_54 , V_150 , V_151 ;
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_136 * V_137 = & V_30 -> V_122 ;
struct V_152 * V_153 = V_30 -> V_153 ;
struct {
struct V_154 V_155 ;
struct V_156 V_157 ;
} V_158 ;
long V_159 ;
unsigned long V_117 = V_160 ;
F_12 ( V_71 , L_33 ) ;
if ( V_153 == NULL ) {
V_153 = F_76 ( sizeof( struct V_152 ) , V_161 ) ;
if ( V_153 == NULL ) {
F_31 (KERN_ERR PFX L_37 ,
drive->name) ;
return - V_162 ;
}
V_30 -> V_153 = V_153 ;
}
( void ) F_70 ( V_6 , V_15 ) ;
if ( V_6 -> V_10 & V_11 )
return 0 ;
V_54 = F_71 ( V_6 , & V_153 -> V_140 , & V_117 ,
V_15 ) ;
if ( V_54 )
V_153 -> V_140 = 0x1fffff ;
F_17 ( V_30 -> V_3 , V_153 -> V_140 * V_117 ) ;
V_6 -> V_44 = V_153 -> V_140 * V_117 ;
F_77 ( V_6 -> V_42 ,
V_117 << V_118 ) ;
V_54 = F_74 ( V_6 , 0 , 1 , 0 , ( char * ) & V_153 -> V_155 ,
sizeof( struct V_154 ) , V_15 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_10 & V_163 ) {
V_153 -> V_155 . V_164 = F_69 ( V_153 -> V_155 . V_164 ) ;
V_153 -> V_155 . V_165 = F_69 ( V_153 -> V_155 . V_165 ) ;
}
V_150 = V_153 -> V_155 . V_165 - V_153 -> V_155 . V_164 + 1 ;
if ( V_150 <= 0 )
return - V_49 ;
if ( V_150 > V_166 )
V_150 = V_166 ;
V_54 = F_74 ( V_6 , V_153 -> V_155 . V_164 , 1 , 0 ,
( char * ) & V_153 -> V_155 ,
sizeof( struct V_154 ) +
( V_150 + 1 ) *
sizeof( struct V_156 ) , V_15 ) ;
if ( V_54 && V_153 -> V_155 . V_164 > 1 ) {
V_150 = 0 ;
V_54 = F_74 ( V_6 , V_167 , 1 , 0 ,
( char * ) & V_153 -> V_155 ,
sizeof( struct V_154 ) +
( V_150 + 1 ) *
sizeof( struct V_156 ) ,
V_15 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_10 & V_163 ) {
V_153 -> V_155 . V_164 = ( T_2 ) F_78 ( V_167 ) ;
V_153 -> V_155 . V_165 = ( T_2 ) F_78 ( V_167 ) ;
} else {
V_153 -> V_155 . V_164 = V_167 ;
V_153 -> V_155 . V_165 = V_167 ;
}
}
if ( V_54 )
return V_54 ;
V_153 -> V_155 . V_168 = F_79 ( V_153 -> V_155 . V_168 ) ;
if ( V_6 -> V_10 & V_163 ) {
V_153 -> V_155 . V_164 = F_69 ( V_153 -> V_155 . V_164 ) ;
V_153 -> V_155 . V_165 = F_69 ( V_153 -> V_155 . V_165 ) ;
}
for ( V_151 = 0 ; V_151 <= V_150 ; V_151 ++ ) {
if ( V_6 -> V_10 & V_169 ) {
if ( V_6 -> V_10 & V_163 )
V_153 -> V_157 [ V_151 ] . V_170 = F_69 ( V_153 -> V_157 [ V_151 ] . V_170 ) ;
F_68 ( & V_153 -> V_157 [ V_151 ] . V_171 . V_132 ) ;
}
V_153 -> V_157 [ V_151 ] . V_171 . V_141 = F_80 ( V_153 -> V_157 [ V_151 ] . V_171 . V_132 . V_133 ,
V_153 -> V_157 [ V_151 ] . V_171 . V_132 . V_134 ,
V_153 -> V_157 [ V_151 ] . V_171 . V_132 . V_135 ) ;
}
if ( V_153 -> V_155 . V_164 != V_167 ) {
V_54 = F_74 ( V_6 , 0 , 0 , 1 , ( char * ) & V_158 ,
sizeof( V_158 ) , V_15 ) ;
if ( V_54 )
return V_54 ;
V_153 -> V_172 = F_72 ( V_158 . V_157 . V_171 . V_141 ) ;
} else {
V_158 . V_155 . V_165 = V_167 ;
V_158 . V_155 . V_164 = V_158 . V_155 . V_165 ;
V_153 -> V_172 = F_80 ( 0 , 2 , 0 ) ;
}
if ( V_6 -> V_10 & V_169 ) {
V_54 = F_74 ( V_6 , 0 , 1 , 1 , ( char * ) & V_158 ,
sizeof( V_158 ) , V_15 ) ;
if ( V_54 )
return V_54 ;
F_68 ( & V_158 . V_157 . V_171 . V_132 ) ;
V_153 -> V_172 = F_80 ( V_158 . V_157 . V_171 . V_132 . V_133 ,
V_158 . V_157 . V_171 . V_132 . V_134 ,
V_158 . V_157 . V_171 . V_132 . V_135 ) ;
}
V_153 -> V_173 = ( V_158 . V_155 . V_164 != V_158 . V_155 . V_165 ) ;
V_54 = F_81 ( V_137 , & V_159 ) ;
if ( ! V_54 && ( V_159 > V_153 -> V_140 ) ) {
V_153 -> V_140 = V_159 ;
F_17 ( V_30 -> V_3 , V_153 -> V_140 * V_117 ) ;
V_6 -> V_44 = V_153 -> V_140 * V_117 ;
}
V_6 -> V_10 |= V_11 ;
return 0 ;
}
int F_82 ( T_1 * V_6 , T_2 * V_124 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_136 * V_137 = & V_30 -> V_122 ;
struct V_174 V_175 ;
int V_54 , V_176 = 3 , V_177 = V_178 ;
F_12 ( V_71 , L_33 ) ;
if ( ( V_6 -> V_10 & V_179 ) == 0 )
V_177 -= V_180 ;
F_83 ( & V_175 , V_124 , V_177 , V_181 ) ;
do {
V_54 = F_84 ( V_137 , & V_175 , V_182 , 0 ) ;
if ( ! V_54 )
break;
} while ( -- V_176 );
return V_54 ;
}
void F_85 ( T_1 * V_6 , T_2 * V_124 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
T_7 V_183 , V_184 ;
F_12 ( V_71 , L_33 ) ;
if ( V_6 -> V_10 & V_185 ) {
V_183 = F_86 ( ( V_186 * ) & V_124 [ 8 + 14 ] ) ;
V_184 = F_86 ( ( V_186 * ) & V_124 [ 8 + 8 ] ) ;
} else {
V_183 = F_87 ( ( V_187 * ) & V_124 [ 8 + 14 ] ) ;
V_184 = F_87 ( ( V_187 * ) & V_124 [ 8 + 8 ] ) ;
}
F_12 ( V_145 , L_38 ,
V_183 , V_184 ) ;
V_4 -> V_188 = F_88 ( V_183 , 176 ) ;
V_4 -> V_189 = F_88 ( V_184 , 176 ) ;
}
static int F_89 ( T_1 * V_6 , int V_190 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_136 * V_122 = & V_30 -> V_122 ;
F_12 ( V_145 , L_39 , V_190 ) ;
V_122 -> V_191 = & V_192 ;
V_122 -> V_193 = V_30 -> V_188 ;
V_122 -> V_140 = V_190 ;
V_122 -> V_194 = V_6 ;
strcpy ( V_122 -> V_45 , V_6 -> V_45 ) ;
if ( V_6 -> V_10 & V_195 )
V_122 -> V_196 |= V_197 ;
V_122 -> V_3 = V_30 -> V_3 ;
return F_90 ( V_122 ) ;
}
static int F_91 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_136 * V_137 = & V_4 -> V_122 ;
T_2 V_124 [ V_178 ] ;
T_11 V_198 ;
int V_190 = 1 ;
F_12 ( V_145 , L_40 ,
V_6 -> V_199 , V_6 -> V_10 ) ;
V_137 -> V_196 = ( V_200 | V_201 | V_202 | V_203 |
V_204 | V_205 | V_206 |
V_207 | V_208 ) ;
if ( V_6 -> V_199 == V_209 ) {
V_137 -> V_196 &= ~ ( V_207 | V_208 ) ;
F_31 (KERN_ERR PFX L_41 ,
drive->name) ;
return V_190 ;
}
if ( V_6 -> V_10 & V_210 ) {
V_6 -> V_10 &= ~ V_211 ;
V_137 -> V_196 &= ~ V_206 ;
return V_190 ;
}
V_137 -> V_194 = V_6 ;
V_137 -> V_191 = & V_192 ;
if ( F_82 ( V_6 , V_124 ) )
return 0 ;
if ( ( V_124 [ 8 + 6 ] & 0x01 ) == 0 )
V_6 -> V_8 &= ~ V_212 ;
if ( V_124 [ 8 + 6 ] & 0x08 )
V_6 -> V_10 &= ~ V_211 ;
if ( V_124 [ 8 + 3 ] & 0x01 )
V_137 -> V_196 &= ~ V_200 ;
if ( V_124 [ 8 + 3 ] & 0x02 )
V_137 -> V_196 &= ~ ( V_201 | V_208 ) ;
if ( V_124 [ 8 + 2 ] & 0x38 )
V_137 -> V_196 &= ~ V_202 ;
if ( V_124 [ 8 + 3 ] & 0x20 )
V_137 -> V_196 &= ~ ( V_204 | V_208 ) ;
if ( V_124 [ 8 + 3 ] & 0x10 )
V_137 -> V_196 &= ~ V_203 ;
if ( ( V_124 [ 8 + 4 ] & 0x01 ) || ( V_6 -> V_10 & V_213 ) )
V_137 -> V_196 &= ~ V_206 ;
V_198 = V_124 [ 8 + 6 ] >> 5 ;
if ( V_198 == V_214 ||
V_198 == V_215 ||
( V_6 -> V_10 & V_216 ) )
V_137 -> V_196 |= V_217 ;
if ( V_137 -> V_139 > 0 ) {
V_137 -> V_196 &= ~ V_205 ;
V_190 = 3 ;
} else if ( V_198 == V_218 ||
V_198 == V_219 ) {
V_190 = F_92 ( V_137 ) ;
if ( V_190 > 1 )
V_137 -> V_196 &= ~ V_205 ;
}
F_85 ( V_6 , V_124 ) ;
F_31 (KERN_INFO PFX L_42 , drive->name) ;
if ( V_4 -> V_189 )
F_31 ( V_220 L_43 , V_4 -> V_189 ) ;
F_31 ( V_220 L_44 , ( V_137 -> V_196 & V_202 ) ? L_45 : L_46 ) ;
if ( ( V_137 -> V_196 & V_203 ) == 0 || ( V_137 -> V_196 & V_204 ) == 0 )
F_31 ( V_220 L_47 ,
( V_137 -> V_196 & V_203 ) ? L_48 : L_49 ,
( V_137 -> V_196 & V_204 ) ? L_48 : L_50 ) ;
if ( ( V_137 -> V_196 & V_200 ) == 0 || ( V_137 -> V_196 & V_201 ) == 0 )
F_31 ( V_220 L_51 ,
( V_137 -> V_196 & V_200 ) ? L_48 : L_49 ,
( V_137 -> V_196 & V_201 ) ? L_48 : L_52 ) ;
if ( ( V_137 -> V_196 & V_205 ) == 0 )
F_31 ( V_220 L_53 , V_190 ) ;
else
F_31 ( V_220 L_54 ) ;
F_31 ( V_220 L_55 ,
F_87 ( ( V_187 * ) & V_124 [ 8 + 12 ] ) ) ;
return V_190 ;
}
static int F_93 ( struct V_115 * V_116 , struct V_12 * V_13 )
{
int V_221 = F_14 ( V_116 ) ;
long V_127 = ( long ) F_59 ( V_13 ) / ( V_221 >> 9 ) ;
unsigned long V_222 = F_58 ( V_13 ) / ( V_221 >> 9 ) ;
memset ( V_13 -> V_26 , 0 , V_83 ) ;
if ( F_30 ( V_13 ) == V_223 )
V_13 -> V_26 [ 0 ] = V_224 ;
else
V_13 -> V_26 [ 0 ] = V_225 ;
V_13 -> V_26 [ 2 ] = ( V_127 >> 24 ) & 0xff ;
V_13 -> V_26 [ 3 ] = ( V_127 >> 16 ) & 0xff ;
V_13 -> V_26 [ 4 ] = ( V_127 >> 8 ) & 0xff ;
V_13 -> V_26 [ 5 ] = V_127 & 0xff ;
V_13 -> V_26 [ 7 ] = ( V_222 >> 8 ) & 0xff ;
V_13 -> V_26 [ 8 ] = V_222 & 0xff ;
V_13 -> V_226 = 10 ;
return V_227 ;
}
static int F_94 ( struct V_12 * V_13 )
{
T_2 * V_228 = V_13 -> V_26 ;
if ( V_228 [ 0 ] == V_229 || V_228 [ 0 ] == V_230 ) {
V_228 [ 8 ] = V_228 [ 4 ] ;
V_228 [ 5 ] = V_228 [ 3 ] ;
V_228 [ 4 ] = V_228 [ 2 ] ;
V_228 [ 3 ] = V_228 [ 1 ] & 0x1f ;
V_228 [ 2 ] = 0 ;
V_228 [ 1 ] &= 0xe0 ;
V_228 [ 0 ] += ( V_231 - V_229 ) ;
V_13 -> V_226 = 10 ;
return V_227 ;
}
if ( V_228 [ 0 ] == V_232 || V_228 [ 0 ] == V_233 ) {
V_13 -> V_50 = V_25 ;
return V_234 ;
}
return V_227 ;
}
static int F_95 ( struct V_115 * V_116 , struct V_12 * V_13 )
{
if ( V_13 -> V_39 == V_40 )
return F_93 ( V_116 , V_13 ) ;
else if ( V_13 -> V_39 == V_61 )
return F_94 ( V_13 ) ;
return 0 ;
}
static T_8 F_96 ( T_1 * V_6 )
{
unsigned long V_140 , V_117 ;
if ( F_71 ( V_6 , & V_140 , & V_117 , NULL ) )
return 0 ;
return V_140 * V_117 ;
}
static int F_97 ( struct V_235 * V_236 , void * V_237 )
{
T_1 * V_6 = V_236 -> V_238 ;
F_98 ( V_236 , L_56 , ( long long ) F_96 ( V_6 ) ) ;
return 0 ;
}
static int F_99 ( struct V_239 * V_239 , struct V_240 * V_240 )
{
return F_100 ( V_240 , F_97 , F_101 ( V_239 ) ) ;
}
static T_12 * F_102 ( T_1 * V_6 )
{
return V_241 ;
}
static const struct V_242 * F_103 ( T_1 * V_6 )
{
return NULL ;
}
static unsigned int F_104 ( T_7 * V_243 )
{
const struct V_244 * V_245 = V_246 ;
while ( V_245 -> V_247 ) {
if ( strcmp ( V_245 -> V_247 , ( char * ) & V_243 [ V_248 ] ) == 0 &&
( V_245 -> V_249 == NULL ||
strstr ( ( char * ) & V_243 [ V_250 ] , V_245 -> V_249 ) ) )
return V_245 -> V_251 ;
V_245 ++ ;
}
return 0 ;
}
static int F_105 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_136 * V_137 = & V_4 -> V_122 ;
struct V_115 * V_116 = V_6 -> V_42 ;
T_7 * V_243 = V_6 -> V_243 ;
char * V_252 = ( char * ) & V_243 [ V_250 ] ;
int V_190 ;
F_12 ( V_145 , L_33 ) ;
F_106 ( V_116 , F_95 ) ;
F_107 ( V_116 , 31 ) ;
F_108 ( V_116 , 15 ) ;
V_6 -> V_8 |= V_9 ;
V_6 -> V_10 = V_211 | F_104 ( V_243 ) ;
if ( ( V_6 -> V_10 & V_253 ) &&
V_252 [ 4 ] == '1' && V_252 [ 6 ] <= '2' )
V_6 -> V_10 |= ( V_163 |
V_169 ) ;
else if ( ( V_6 -> V_10 & V_254 ) &&
V_252 [ 4 ] == '1' && V_252 [ 6 ] <= '2' )
V_6 -> V_10 |= V_163 ;
else if ( V_6 -> V_10 & V_255 )
V_137 -> V_139 = 3 ;
V_190 = F_91 ( V_6 ) ;
F_77 ( V_116 , V_256 ) ;
if ( F_89 ( V_6 , V_190 ) ) {
F_31 (KERN_ERR PFX L_57
L_58 , drive->name, __func__) ;
V_4 -> V_122 . V_194 = NULL ;
return 1 ;
}
F_109 ( V_6 , V_4 -> V_257 ) ;
return 0 ;
}
static void F_110 ( T_1 * V_6 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
F_12 ( V_71 , L_33 ) ;
F_111 ( V_6 , V_30 -> V_257 ) ;
F_112 ( & V_30 -> V_7 ) ;
F_113 ( V_30 -> V_3 ) ;
F_2 ( & V_5 ) ;
F_8 ( & V_30 -> V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_114 ( struct V_258 * V_7 )
{
struct V_1 * V_30 = F_115 ( V_7 , V_1 ) ;
struct V_136 * V_122 = & V_30 -> V_122 ;
T_1 * V_6 = V_30 -> V_6 ;
struct V_2 * V_259 = V_30 -> V_3 ;
F_12 ( V_71 , L_33 ) ;
F_116 ( V_30 -> V_153 ) ;
if ( V_122 -> V_194 == V_6 )
F_117 ( V_122 ) ;
V_6 -> V_31 = NULL ;
F_106 ( V_6 -> V_42 , NULL ) ;
V_259 -> V_260 = NULL ;
F_118 ( V_259 ) ;
F_116 ( V_30 ) ;
}
static int F_119 ( struct V_261 * V_262 , T_13 V_263 )
{
struct V_1 * V_30 ;
int V_99 = - V_264 ;
F_2 ( & V_265 ) ;
V_30 = F_1 ( V_262 -> V_266 ) ;
if ( ! V_30 )
goto V_267;
V_99 = F_120 ( & V_30 -> V_122 , V_262 , V_263 ) ;
if ( V_99 < 0 )
F_7 ( V_30 ) ;
V_267:
F_6 ( & V_265 ) ;
return V_99 ;
}
static void F_121 ( struct V_2 * V_3 , T_13 V_263 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
F_2 ( & V_265 ) ;
F_122 ( & V_30 -> V_122 , V_263 ) ;
F_7 ( V_30 ) ;
F_6 ( & V_265 ) ;
}
static int F_123 ( struct V_136 * V_137 , unsigned long V_268 )
{
struct V_174 V_175 ;
char V_75 [ 16 ] ;
int V_54 ;
char V_269 ;
if ( F_124 ( & V_269 , ( void V_270 * ) V_268 , sizeof( char ) ) )
return - V_271 ;
F_83 ( & V_175 , V_75 , sizeof( V_75 ) , V_181 ) ;
V_54 = F_84 ( V_137 , & V_175 , V_272 , 0 ) ;
if ( V_54 )
return V_54 ;
V_75 [ 11 ] = ( V_75 [ 11 ] & 0xf0 ) | ( V_269 & 0x0f ) ;
return F_125 ( V_137 , & V_175 ) ;
}
static int F_126 ( struct V_136 * V_137 , unsigned long V_268 )
{
struct V_174 V_175 ;
char V_75 [ 16 ] ;
int V_54 ;
char V_269 ;
F_83 ( & V_175 , V_75 , sizeof( V_75 ) , V_181 ) ;
V_54 = F_84 ( V_137 , & V_175 , V_272 , 0 ) ;
if ( V_54 )
return V_54 ;
V_269 = V_75 [ 11 ] & 0x0f ;
if ( F_127 ( ( void V_270 * ) V_268 , & V_269 , sizeof( char ) ) )
return - V_271 ;
return 0 ;
}
static int F_128 ( struct V_261 * V_262 , T_13 V_263 ,
unsigned int V_26 , unsigned long V_268 )
{
struct V_1 * V_30 = F_3 ( V_262 -> V_266 , V_1 ) ;
int V_56 ;
switch ( V_26 ) {
case V_273 :
return F_123 ( & V_30 -> V_122 , V_268 ) ;
case V_274 :
return F_126 ( & V_30 -> V_122 , V_268 ) ;
default:
break;
}
V_56 = F_129 ( V_30 -> V_6 , V_262 , V_26 , V_268 ) ;
if ( V_56 == - V_275 )
V_56 = F_130 ( & V_30 -> V_122 , V_262 , V_263 , V_26 , V_268 ) ;
return V_56 ;
}
static int F_131 ( struct V_261 * V_262 , T_13 V_263 ,
unsigned int V_26 , unsigned long V_268 )
{
int V_276 ;
F_2 ( & V_265 ) ;
V_276 = F_128 ( V_262 , V_263 , V_26 , V_268 ) ;
F_6 ( & V_265 ) ;
return V_276 ;
}
static unsigned int F_132 ( struct V_2 * V_3 ,
unsigned int V_277 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
return F_133 ( & V_30 -> V_122 , V_277 ) ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
struct V_14 V_15 ;
F_75 ( V_30 -> V_6 , & V_15 ) ;
return 0 ;
}
static int F_135 ( T_1 * V_6 )
{
struct V_1 * V_30 ;
struct V_2 * V_259 ;
struct V_14 V_15 ;
F_12 ( V_145 , L_59 ,
V_6 -> V_278 , V_6 -> V_199 ) ;
if ( ! strstr ( L_60 , V_6 -> V_278 ) )
goto V_46;
if ( V_6 -> V_199 != V_279 && V_6 -> V_199 != V_209 )
goto V_46;
V_6 -> V_129 = V_129 ;
V_6 -> V_280 = F_44 ;
V_30 = F_136 ( sizeof( struct V_1 ) , V_161 ) ;
if ( V_30 == NULL ) {
F_31 (KERN_ERR PFX L_61 ,
drive->name) ;
goto V_46;
}
V_259 = F_137 ( 1 << V_281 ) ;
if ( ! V_259 )
goto V_282;
F_138 ( V_259 , V_6 ) ;
V_30 -> V_7 . V_283 = & V_6 -> V_284 ;
V_30 -> V_7 . V_285 = F_114 ;
F_139 ( & V_30 -> V_7 , L_62 , F_140 ( & V_6 -> V_284 ) ) ;
if ( F_141 ( & V_30 -> V_7 ) )
goto V_286;
V_30 -> V_6 = V_6 ;
V_30 -> V_257 = & V_287 ;
V_30 -> V_3 = V_259 ;
V_259 -> V_260 = & V_30 -> V_257 ;
V_6 -> V_31 = V_30 ;
V_259 -> V_288 = 1 ;
V_259 -> V_80 = V_289 | V_290 ;
if ( F_105 ( V_6 ) ) {
F_8 ( & V_30 -> V_7 ) ;
goto V_46;
}
F_75 ( V_6 , & V_15 ) ;
V_259 -> V_291 = & V_292 ;
V_259 -> V_80 |= V_290 | V_293 ;
F_142 ( & V_6 -> V_284 , V_259 ) ;
return 0 ;
V_286:
F_118 ( V_259 ) ;
V_282:
F_116 ( V_30 ) ;
V_46:
return - V_294 ;
}
static void T_14 F_143 ( void )
{
F_144 ( & V_287 . V_295 ) ;
}
static int T_15 F_145 ( void )
{
F_31 (KERN_INFO DRV_NAME L_63 IDECD_VERSION L_64 ) ;
return F_146 ( & V_287 . V_295 ) ;
}
