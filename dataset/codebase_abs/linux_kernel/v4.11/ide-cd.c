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
if ( F_13 ( V_13 ) -> V_26 [ 0 ] == V_27 && V_15 -> V_24 == 0x24 )
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
static void F_14 ( T_1 * V_6 ,
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
if ( V_29 && F_13 ( V_29 ) -> V_26 [ 0 ] == V_35 )
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
F_15 ( V_29 ) )
break;
V_32 = ( V_15 -> V_39 [ 0 ] << 24 ) |
( V_15 -> V_39 [ 1 ] << 16 ) |
( V_15 -> V_39 [ 2 ] << 8 ) |
( V_15 -> V_39 [ 3 ] ) ;
if ( F_16 ( V_6 -> V_40 ) == 2048 )
V_32 <<= 2 ;
V_33 = F_17 ( V_33 ( V_29 -> V_41 ) , 4U ) ;
V_32 &= ~ ( V_33 - 1 ) ;
if ( V_32 < F_18 ( V_30 -> V_3 ) &&
V_6 -> V_42 - V_32 < 4 * 75 )
F_19 ( V_30 -> V_3 , V_32 ) ;
}
}
F_20 ( V_6 -> V_43 , V_29 , V_15 ) ;
}
static void F_21 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_12 * V_44 = (struct V_12 * ) V_13 -> V_45 ;
void * V_15 = F_22 ( V_13 -> V_41 ) ;
if ( V_44 ) {
memcpy ( F_13 ( V_44 ) -> V_15 , V_15 , 18 ) ;
F_13 ( V_44 ) -> V_46 = F_13 ( V_13 ) -> V_46 ;
F_14 ( V_6 , V_44 ) ;
if ( F_23 ( V_6 , V_44 , - V_47 , F_24 ( V_44 ) ) )
F_25 () ;
} else
F_14 ( V_6 , NULL ) ;
}
static int F_26 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
if ( ! V_13 -> V_48 )
V_30 -> V_49 = V_50 + V_51 ;
V_13 -> V_48 = 1 ;
if ( F_27 ( V_50 , V_30 -> V_49 ) )
return 0 ;
else {
F_28 ( V_6 -> V_40 , 1 ) ;
return 1 ;
}
}
static int F_29 ( T_1 * V_6 , T_2 V_52 )
{
T_3 * V_53 = V_6 -> V_53 ;
struct V_12 * V_13 = V_53 -> V_13 ;
int V_54 , V_20 , V_55 = 0 ;
V_54 = F_30 ( V_6 ) ;
V_20 = V_54 >> 4 ;
F_12 ( V_56 , L_4
L_5 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_57 , V_54 , V_52 ) ;
if ( F_31 ( V_13 ) ) {
V_13 -> V_17 |= V_58 ;
return 2 ;
}
if ( F_32 ( V_13 ) && ! V_13 -> V_48 )
V_13 -> V_48 = V_59 ;
if ( F_33 ( V_13 ) )
V_55 = 1 ;
switch ( V_20 ) {
case V_23 :
if ( F_34 ( V_13 ) == V_60 ) {
if ( F_26 ( V_6 , V_13 ) )
return 1 ;
} else {
F_10 ( V_6 ) ;
if ( ! F_15 ( V_13 ) &&
! ( V_13 -> V_17 & V_18 ) )
F_35 (KERN_ERR PFX L_6 ,
drive->name) ;
}
V_55 = 1 ;
break;
case V_28 :
F_10 ( V_6 ) ;
if ( F_15 ( V_13 ) )
return 0 ;
if ( ++ V_13 -> V_48 > V_61 )
V_55 = 1 ;
break;
case V_25 :
if ( F_13 ( V_13 ) -> V_26 [ 0 ] == V_27 )
break;
case V_62 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_36 ( V_6 , L_7 , V_52 ) ;
V_55 = 1 ;
break;
case V_36 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_36 ( V_6 , L_8
L_9 , V_52 ) ;
V_55 = 1 ;
break;
case V_63 :
if ( ! ( V_13 -> V_17 & V_18 ) )
F_36 ( V_6 , L_10 ,
V_52 ) ;
V_55 = 1 ;
break;
default:
if ( F_15 ( V_13 ) )
break;
if ( V_54 & ~ V_64 ) {
F_37 ( V_6 , L_11 , V_52 ) ;
return 1 ;
} else if ( ++ V_13 -> V_48 > V_61 )
V_55 = 1 ;
}
if ( F_15 ( V_13 ) ) {
V_13 -> V_17 |= V_58 ;
V_55 = 1 ;
}
if ( V_55 )
goto V_65;
if ( V_52 & V_66 )
return F_38 ( V_6 , NULL ) ? 2 : 1 ;
return 1 ;
V_65:
if ( V_52 & V_66 ) {
V_53 -> V_13 = NULL ;
return F_38 ( V_6 , V_13 ) ? 2 : 1 ;
} else
return 2 ;
}
static void F_39 ( T_1 * V_6 , struct V_67 * V_26 )
{
struct V_12 * V_13 = V_26 -> V_13 ;
F_12 ( V_68 , L_12 , V_13 -> V_26 [ 0 ] ) ;
if ( F_13 ( V_13 ) -> V_26 [ 0 ] == V_69 &&
V_26 -> V_70 > 0 && V_26 -> V_70 <= 5 )
V_26 -> V_70 = 0 ;
}
int F_40 ( T_1 * V_6 , const unsigned char * V_26 ,
int V_71 , void * V_72 , unsigned * V_73 ,
struct V_14 * V_15 , int V_74 ,
T_4 V_17 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
int V_75 = 10 ;
bool V_44 ;
F_12 ( V_76 , L_13
L_14 ,
V_26 [ 0 ] , V_71 , V_74 , V_17 ) ;
do {
struct V_12 * V_13 ;
int error ;
bool V_77 = false ;
V_13 = F_41 ( V_6 -> V_40 ,
V_71 ? V_78 : V_79 , V_80 ) ;
F_42 ( V_13 ) ;
memcpy ( F_13 ( V_13 ) -> V_26 , V_26 , V_81 ) ;
F_43 ( V_13 ) -> type = V_82 ;
V_13 -> V_17 |= V_17 ;
V_13 -> V_74 = V_74 ;
if ( V_72 ) {
error = F_44 ( V_6 -> V_40 , V_13 , V_72 ,
* V_73 , V_83 ) ;
if ( error ) {
F_45 ( V_13 ) ;
return error ;
}
}
error = F_46 ( V_6 -> V_40 , V_30 -> V_3 , V_13 , 0 ) ;
if ( V_72 )
* V_73 = F_13 ( V_13 ) -> V_84 ;
if ( V_15 )
memcpy ( V_15 , F_13 ( V_13 ) -> V_15 , sizeof( * V_15 ) ) ;
V_44 = ( V_13 -> V_17 & V_58 ) != 0 ;
if ( V_44 ) {
struct V_14 * V_85 = F_13 ( V_13 ) -> V_15 ;
if ( V_85 -> V_20 == V_28 )
F_10 ( V_6 ) ;
else if ( V_85 -> V_20 == V_23 &&
V_85 -> V_24 == 4 && V_85 -> V_86 != 4 ) {
V_77 = true ;
} else {
V_75 = 0 ;
}
-- V_75 ;
}
F_45 ( V_13 ) ;
if ( V_77 )
F_47 ( 2 ) ;
} while ( V_44 && V_75 >= 0 );
return V_44 ? - V_47 : 0 ;
}
static bool F_48 ( T_1 * V_6 , struct V_67 * V_26 )
{
unsigned int V_87 = V_26 -> V_88 - V_26 -> V_70 ;
if ( V_26 -> V_89 & V_90 )
V_87 -= V_26 -> V_91 ;
if ( V_87 > 0 ) {
F_49 ( V_6 , 0 , V_87 ) ;
return true ;
}
return false ;
}
static T_5 F_50 ( T_1 * V_6 )
{
T_3 * V_53 = V_6 -> V_53 ;
struct V_67 * V_26 = & V_53 -> V_26 ;
struct V_12 * V_13 = V_53 -> V_13 ;
T_6 * V_92 = NULL ;
int V_93 = 0 , V_94 , V_95 , V_96 = 0 ;
int V_71 = ( F_51 ( V_13 ) == V_97 ) ? 1 : 0 , V_98 = 0 ;
int V_15 = F_31 ( V_13 ) ;
unsigned int V_74 ;
T_7 V_99 ;
T_2 V_100 , V_52 ;
F_12 ( V_76 , L_15 , V_13 -> V_26 [ 0 ] , V_71 ) ;
V_94 = V_6 -> V_94 ;
if ( V_94 ) {
V_6 -> V_94 = 0 ;
V_6 -> V_101 = 0 ;
V_93 = V_53 -> V_102 -> V_103 ( V_6 ) ;
F_52 ( V_6 , V_26 ) ;
if ( V_93 ) {
F_35 (KERN_ERR PFX L_16 , drive->name,
write ? L_17 : L_18 ) ;
F_53 ( V_6 ) ;
}
}
V_52 = V_53 -> V_104 -> V_105 ( V_53 ) ;
if ( ! F_54 ( V_52 , 0 , V_106 ) ) {
V_98 = F_29 ( V_6 , V_52 ) ;
if ( V_98 ) {
if ( V_98 == 2 )
goto V_107;
return V_108 ;
}
}
if ( V_94 ) {
if ( V_93 )
return F_37 ( V_6 , L_19 , V_52 ) ;
V_96 = 1 ;
goto V_107;
}
F_55 ( V_6 , & V_99 , & V_100 ) ;
V_95 = ! F_15 ( V_13 ) ? V_99 : V_26 -> V_70 ;
if ( V_95 > V_99 )
V_95 = V_99 ;
F_12 ( V_76 , L_20 ,
V_52 , V_95 ) ;
if ( ( V_52 & V_109 ) == 0 ) {
switch ( F_34 ( V_13 ) ) {
default:
V_96 = 1 ;
if ( V_26 -> V_70 > 0 ) {
F_35 (KERN_ERR PFX L_21
L_22 , drive->name, __func__,
cmd->nleft) ;
if ( ! V_71 )
V_13 -> V_17 |= V_58 ;
V_96 = 0 ;
}
goto V_107;
case V_79 :
case V_78 :
F_39 ( V_6 , V_26 ) ;
V_96 = V_26 -> V_70 ? 0 : 1 ;
if ( ! ( V_52 & V_66 ) && ! V_96 && V_95 ) {
F_56 ( V_6 , V_26 , V_71 , V_95 ) ;
V_96 = V_26 -> V_70 ? 0 : 1 ;
}
if ( ! V_96 )
V_13 -> V_17 |= V_58 ;
goto V_107;
case V_110 :
case V_111 :
goto V_107;
}
}
V_98 = F_57 ( V_6 , V_13 , V_99 , V_100 , V_71 ) ;
if ( V_98 )
goto V_107;
V_26 -> V_91 = 0 ;
F_12 ( V_76 , L_23
L_24 ,
V_13 -> V_57 , V_100 ) ;
while ( V_95 > 0 ) {
int V_112 = F_58 ( int , V_95 , V_26 -> V_70 ) ;
if ( V_26 -> V_70 == 0 )
break;
F_56 ( V_6 , V_26 , V_71 , V_112 ) ;
V_26 -> V_91 += V_112 ;
V_95 -= V_112 ;
V_99 -= V_112 ;
if ( V_15 && V_71 == 0 )
F_13 ( V_13 ) -> V_46 += V_112 ;
}
if ( V_99 > 0 ) {
if ( F_15 ( V_13 ) || V_71 == 0 )
F_59 ( V_6 , V_71 , V_99 ) ;
else {
F_35 (KERN_ERR PFX L_25 ,
drive->name) ;
F_60 ( V_13 , L_26 ) ;
}
}
switch ( F_34 ( V_13 ) ) {
case V_110 :
case V_111 :
V_74 = V_13 -> V_74 ;
break;
case V_79 :
case V_78 :
V_92 = V_113 ;
default:
V_74 = V_114 ;
break;
}
V_53 -> V_92 = V_92 ;
F_61 ( V_6 , F_50 , V_74 ) ;
return V_115 ;
V_107:
if ( F_32 ( V_13 ) && V_98 == 0 ) {
F_13 ( V_13 ) -> V_84 = 0 ;
F_62 ( V_13 , 0 ) ;
V_53 -> V_13 = NULL ;
} else {
if ( V_15 && V_96 )
F_21 ( V_6 , V_13 ) ;
if ( ! F_15 ( V_13 ) ) {
if ( V_26 -> V_70 == 0 )
V_96 = 1 ;
} else {
if ( V_96 <= 0 && V_13 -> V_48 == 0 )
V_13 -> V_48 = - V_47 ;
}
if ( V_96 == 0 && V_13 -> V_41 )
if ( F_48 ( V_6 , V_26 ) )
return V_108 ;
if ( F_15 ( V_13 ) ) {
F_13 ( V_13 ) -> V_84 -= V_26 -> V_88 - V_26 -> V_70 ;
if ( V_96 == 0 && ( V_26 -> V_89 & V_90 ) )
F_13 ( V_13 ) -> V_84 += V_26 -> V_91 ;
}
F_49 ( V_6 , V_96 ? 0 : - V_47 , F_24 ( V_13 ) ) ;
if ( V_15 && V_98 == 2 )
F_37 ( V_6 , L_27 , V_52 ) ;
}
return V_108 ;
}
static T_5 F_63 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_116 * V_117 = V_6 -> V_40 ;
int V_71 = F_51 ( V_13 ) == V_97 ;
unsigned short V_118 =
F_16 ( V_117 ) >> V_119 ;
F_12 ( V_56 , L_28
L_29 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_120 , V_118 ) ;
if ( V_71 ) {
if ( F_64 ( V_4 -> V_3 ) )
return V_108 ;
} else {
V_117 -> V_121 ( V_117 , V_13 ) ;
}
if ( ( F_65 ( V_13 ) & ( V_118 - 1 ) ) ||
( F_66 ( V_13 ) & ( V_118 - 1 ) ) )
return V_108 ;
V_6 -> V_94 = ! ! ( V_6 -> V_8 & V_122 ) ;
if ( V_71 )
V_4 -> V_123 . V_124 = 1 ;
V_13 -> V_74 = V_114 ;
return V_115 ;
}
static void F_67 ( T_1 * V_6 , struct V_12 * V_13 )
{
F_12 ( V_76 , L_30 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_57 ) ;
if ( F_32 ( V_13 ) )
V_13 -> V_17 |= V_18 ;
else
V_13 -> V_17 &= ~ V_58 ;
V_6 -> V_94 = 0 ;
if ( V_13 -> V_41 ) {
struct V_116 * V_117 = V_6 -> V_40 ;
char * V_125 = F_22 ( V_13 -> V_41 ) ;
unsigned int V_126 ;
V_6 -> V_94 = ! ! ( V_6 -> V_8 & V_122 ) ;
V_126 = F_68 ( V_117 ) | V_117 -> V_127 ;
if ( ( unsigned long ) V_125 & V_126
|| F_24 ( V_13 ) & V_117 -> V_127
|| F_69 ( V_125 ) )
V_6 -> V_94 = 0 ;
}
}
static T_5 F_70 ( T_1 * V_6 , struct V_12 * V_13 ,
T_8 V_128 )
{
struct V_67 V_26 ;
int V_96 = 0 ;
unsigned int V_129 ;
F_12 ( V_56 , L_31 ,
V_13 -> V_26 [ 0 ] , ( unsigned long long ) V_128 ) ;
if ( V_6 -> V_130 & V_56 )
F_60 ( V_13 , L_32 ) ;
switch ( F_34 ( V_13 ) ) {
default:
if ( F_63 ( V_6 , V_13 ) == V_108 )
goto V_107;
break;
case V_110 :
case V_111 :
V_131:
if ( ! V_13 -> V_74 )
V_13 -> V_74 = V_114 ;
F_67 ( V_6 , V_13 ) ;
break;
case V_79 :
case V_78 :
switch ( F_43 ( V_13 ) -> type ) {
case V_132 :
V_96 = 1 ;
goto V_107;
case V_133 :
case V_82 :
goto V_131;
default:
F_25 () ;
}
}
F_71 ( V_6 , V_13 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_51 ( V_13 ) )
V_26 . V_89 |= V_90 ;
V_26 . V_13 = V_13 ;
if ( ! F_15 ( V_13 ) || F_24 ( V_13 ) ) {
F_72 ( & V_26 , F_24 ( V_13 ) ) ;
F_73 ( V_6 , & V_26 ) ;
}
return F_74 ( V_6 , & V_26 ) ;
V_107:
V_129 = F_65 ( V_13 ) ;
if ( V_129 == 0 )
V_129 = 1 ;
F_49 ( V_6 , V_96 ? 0 : - V_47 , V_129 << 9 ) ;
return V_108 ;
}
static void F_75 ( struct V_134 * V_135 )
{
V_135 -> V_136 = F_76 ( V_135 -> V_136 ) ;
V_135 -> V_137 = F_76 ( V_135 -> V_137 ) ;
V_135 -> V_138 = F_76 ( V_135 -> V_138 ) ;
}
int F_77 ( T_1 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_139 * V_140 = & V_30 -> V_123 ;
unsigned char V_26 [ V_81 ] ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_141 ;
V_26 [ 7 ] = V_140 -> V_142 % 3 ;
return F_40 ( V_6 , V_26 , 0 , NULL , NULL , V_15 , 0 , V_18 ) ;
}
static int F_78 ( T_1 * V_6 , unsigned long * V_143 ,
unsigned long * V_118 ,
struct V_14 * V_15 )
{
struct {
T_9 V_144 ;
T_9 V_145 ;
} V_146 ;
int V_52 ;
unsigned char V_26 [ V_81 ] ;
unsigned V_99 = sizeof( V_146 ) ;
T_10 V_145 ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_147 ;
V_52 = F_40 ( V_6 , V_26 , 0 , & V_146 , & V_99 , V_15 , 0 ,
V_18 ) ;
if ( V_52 )
return V_52 ;
V_145 = F_79 ( V_146 . V_145 ) ;
V_145 = ( V_145 >> V_119 ) << V_119 ;
switch ( V_145 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_80 (KERN_ERR PFX L_34
L_35 ,
drive->name, blocklen) ;
V_145 = 2048 ;
break;
}
* V_143 = 1 + F_79 ( V_146 . V_144 ) ;
* V_118 = V_145 >> V_119 ;
F_12 ( V_148 , L_36 ,
* V_143 , * V_118 ) ;
return 0 ;
}
static int F_81 ( T_1 * V_6 , int V_149 , int V_150 ,
int V_151 , char * V_125 , int V_152 ,
struct V_14 * V_15 )
{
unsigned char V_26 [ V_81 ] ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_35 ;
V_26 [ 6 ] = V_149 ;
V_26 [ 7 ] = ( V_152 >> 8 ) ;
V_26 [ 8 ] = ( V_152 & 0xff ) ;
V_26 [ 9 ] = ( V_151 << 6 ) ;
if ( V_150 )
V_26 [ 1 ] = 2 ;
return F_40 ( V_6 , V_26 , 0 , V_125 , & V_152 , V_15 , 0 , V_18 ) ;
}
int F_82 ( T_1 * V_6 , struct V_14 * V_15 )
{
int V_52 , V_153 , V_154 ;
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_139 * V_140 = & V_30 -> V_123 ;
struct V_155 * V_156 = V_30 -> V_156 ;
struct {
struct V_157 V_158 ;
struct V_159 V_160 ;
} V_161 ;
long V_162 ;
unsigned long V_118 = V_163 ;
F_12 ( V_68 , L_33 ) ;
if ( V_156 == NULL ) {
V_156 = F_83 ( sizeof( struct V_155 ) , V_164 ) ;
if ( V_156 == NULL ) {
F_35 (KERN_ERR PFX L_37 ,
drive->name) ;
return - V_165 ;
}
V_30 -> V_156 = V_156 ;
}
( void ) F_77 ( V_6 , V_15 ) ;
if ( V_6 -> V_10 & V_11 )
return 0 ;
V_52 = F_78 ( V_6 , & V_156 -> V_143 , & V_118 ,
V_15 ) ;
if ( V_52 )
V_156 -> V_143 = 0x1fffff ;
F_19 ( V_30 -> V_3 , V_156 -> V_143 * V_118 ) ;
V_6 -> V_42 = V_156 -> V_143 * V_118 ;
F_84 ( V_6 -> V_40 ,
V_118 << V_119 ) ;
V_52 = F_81 ( V_6 , 0 , 1 , 0 , ( char * ) & V_156 -> V_158 ,
sizeof( struct V_157 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
if ( V_6 -> V_10 & V_166 ) {
V_156 -> V_158 . V_167 = F_76 ( V_156 -> V_158 . V_167 ) ;
V_156 -> V_158 . V_168 = F_76 ( V_156 -> V_158 . V_168 ) ;
}
V_153 = V_156 -> V_158 . V_168 - V_156 -> V_158 . V_167 + 1 ;
if ( V_153 <= 0 )
return - V_47 ;
if ( V_153 > V_169 )
V_153 = V_169 ;
V_52 = F_81 ( V_6 , V_156 -> V_158 . V_167 , 1 , 0 ,
( char * ) & V_156 -> V_158 ,
sizeof( struct V_157 ) +
( V_153 + 1 ) *
sizeof( struct V_159 ) , V_15 ) ;
if ( V_52 && V_156 -> V_158 . V_167 > 1 ) {
V_153 = 0 ;
V_52 = F_81 ( V_6 , V_170 , 1 , 0 ,
( char * ) & V_156 -> V_158 ,
sizeof( struct V_157 ) +
( V_153 + 1 ) *
sizeof( struct V_159 ) ,
V_15 ) ;
if ( V_52 )
return V_52 ;
if ( V_6 -> V_10 & V_166 ) {
V_156 -> V_158 . V_167 = ( T_2 ) F_85 ( V_170 ) ;
V_156 -> V_158 . V_168 = ( T_2 ) F_85 ( V_170 ) ;
} else {
V_156 -> V_158 . V_167 = V_170 ;
V_156 -> V_158 . V_168 = V_170 ;
}
}
if ( V_52 )
return V_52 ;
V_156 -> V_158 . V_171 = F_86 ( V_156 -> V_158 . V_171 ) ;
if ( V_6 -> V_10 & V_166 ) {
V_156 -> V_158 . V_167 = F_76 ( V_156 -> V_158 . V_167 ) ;
V_156 -> V_158 . V_168 = F_76 ( V_156 -> V_158 . V_168 ) ;
}
for ( V_154 = 0 ; V_154 <= V_153 ; V_154 ++ ) {
if ( V_6 -> V_10 & V_172 ) {
if ( V_6 -> V_10 & V_166 )
V_156 -> V_160 [ V_154 ] . V_173 = F_76 ( V_156 -> V_160 [ V_154 ] . V_173 ) ;
F_75 ( & V_156 -> V_160 [ V_154 ] . V_174 . V_135 ) ;
}
V_156 -> V_160 [ V_154 ] . V_174 . V_144 = F_87 ( V_156 -> V_160 [ V_154 ] . V_174 . V_135 . V_136 ,
V_156 -> V_160 [ V_154 ] . V_174 . V_135 . V_137 ,
V_156 -> V_160 [ V_154 ] . V_174 . V_135 . V_138 ) ;
}
if ( V_156 -> V_158 . V_167 != V_170 ) {
V_52 = F_81 ( V_6 , 0 , 0 , 1 , ( char * ) & V_161 ,
sizeof( V_161 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
V_156 -> V_175 = F_79 ( V_161 . V_160 . V_174 . V_144 ) ;
} else {
V_161 . V_158 . V_168 = V_170 ;
V_161 . V_158 . V_167 = V_161 . V_158 . V_168 ;
V_156 -> V_175 = F_87 ( 0 , 2 , 0 ) ;
}
if ( V_6 -> V_10 & V_172 ) {
V_52 = F_81 ( V_6 , 0 , 1 , 1 , ( char * ) & V_161 ,
sizeof( V_161 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
F_75 ( & V_161 . V_160 . V_174 . V_135 ) ;
V_156 -> V_175 = F_87 ( V_161 . V_160 . V_174 . V_135 . V_136 ,
V_161 . V_160 . V_174 . V_135 . V_137 ,
V_161 . V_160 . V_174 . V_135 . V_138 ) ;
}
V_156 -> V_176 = ( V_161 . V_158 . V_167 != V_161 . V_158 . V_168 ) ;
V_52 = F_88 ( V_140 , & V_162 ) ;
if ( ! V_52 && ( V_162 > V_156 -> V_143 ) ) {
V_156 -> V_143 = V_162 ;
F_19 ( V_30 -> V_3 , V_156 -> V_143 * V_118 ) ;
V_6 -> V_42 = V_156 -> V_143 * V_118 ;
}
V_6 -> V_10 |= V_11 ;
return 0 ;
}
int F_89 ( T_1 * V_6 , T_2 * V_125 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_139 * V_140 = & V_30 -> V_123 ;
struct V_177 V_178 ;
int V_52 , V_179 = 3 , V_180 = V_181 ;
F_12 ( V_68 , L_33 ) ;
if ( ( V_6 -> V_10 & V_182 ) == 0 )
V_180 -= V_183 ;
F_90 ( & V_178 , V_125 , V_180 , V_184 ) ;
do {
V_52 = F_91 ( V_140 , & V_178 , V_185 , 0 ) ;
if ( ! V_52 )
break;
} while ( -- V_179 );
return V_52 ;
}
void F_92 ( T_1 * V_6 , T_2 * V_125 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
T_7 V_186 , V_187 ;
F_12 ( V_68 , L_33 ) ;
if ( V_6 -> V_10 & V_188 ) {
V_186 = F_93 ( ( V_189 * ) & V_125 [ 8 + 14 ] ) ;
V_187 = F_93 ( ( V_189 * ) & V_125 [ 8 + 8 ] ) ;
} else {
V_186 = F_94 ( ( V_190 * ) & V_125 [ 8 + 14 ] ) ;
V_187 = F_94 ( ( V_190 * ) & V_125 [ 8 + 8 ] ) ;
}
F_12 ( V_148 , L_38 ,
V_186 , V_187 ) ;
V_4 -> V_191 = F_95 ( V_186 , 176 ) ;
V_4 -> V_192 = F_95 ( V_187 , 176 ) ;
}
static int F_96 ( T_1 * V_6 , int V_193 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_139 * V_123 = & V_30 -> V_123 ;
F_12 ( V_148 , L_39 , V_193 ) ;
V_123 -> V_194 = & V_195 ;
V_123 -> V_196 = V_30 -> V_191 ;
V_123 -> V_143 = V_193 ;
V_123 -> V_197 = V_6 ;
strcpy ( V_123 -> V_43 , V_6 -> V_43 ) ;
if ( V_6 -> V_10 & V_198 )
V_123 -> V_199 |= V_200 ;
V_123 -> V_3 = V_30 -> V_3 ;
return F_97 ( V_123 ) ;
}
static int F_98 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_139 * V_140 = & V_4 -> V_123 ;
T_2 V_125 [ V_181 ] ;
T_11 V_201 ;
int V_193 = 1 ;
F_12 ( V_148 , L_40 ,
V_6 -> V_202 , V_6 -> V_10 ) ;
V_140 -> V_199 = ( V_203 | V_204 | V_205 | V_206 |
V_207 | V_208 | V_209 |
V_210 | V_211 ) ;
if ( V_6 -> V_202 == V_212 ) {
V_140 -> V_199 &= ~ ( V_210 | V_211 ) ;
F_35 (KERN_ERR PFX L_41 ,
drive->name) ;
return V_193 ;
}
if ( V_6 -> V_10 & V_213 ) {
V_6 -> V_10 &= ~ V_214 ;
V_140 -> V_199 &= ~ V_209 ;
return V_193 ;
}
V_140 -> V_197 = V_6 ;
V_140 -> V_194 = & V_195 ;
if ( F_89 ( V_6 , V_125 ) )
return 0 ;
if ( ( V_125 [ 8 + 6 ] & 0x01 ) == 0 )
V_6 -> V_8 &= ~ V_215 ;
if ( V_125 [ 8 + 6 ] & 0x08 )
V_6 -> V_10 &= ~ V_214 ;
if ( V_125 [ 8 + 3 ] & 0x01 )
V_140 -> V_199 &= ~ V_203 ;
if ( V_125 [ 8 + 3 ] & 0x02 )
V_140 -> V_199 &= ~ ( V_204 | V_211 ) ;
if ( V_125 [ 8 + 2 ] & 0x38 )
V_140 -> V_199 &= ~ V_205 ;
if ( V_125 [ 8 + 3 ] & 0x20 )
V_140 -> V_199 &= ~ ( V_207 | V_211 ) ;
if ( V_125 [ 8 + 3 ] & 0x10 )
V_140 -> V_199 &= ~ V_206 ;
if ( ( V_125 [ 8 + 4 ] & 0x01 ) || ( V_6 -> V_10 & V_216 ) )
V_140 -> V_199 &= ~ V_209 ;
V_201 = V_125 [ 8 + 6 ] >> 5 ;
if ( V_201 == V_217 ||
V_201 == V_218 ||
( V_6 -> V_10 & V_219 ) )
V_140 -> V_199 |= V_220 ;
if ( V_140 -> V_142 > 0 ) {
V_140 -> V_199 &= ~ V_208 ;
V_193 = 3 ;
} else if ( V_201 == V_221 ||
V_201 == V_222 ) {
V_193 = F_99 ( V_140 ) ;
if ( V_193 > 1 )
V_140 -> V_199 &= ~ V_208 ;
}
F_92 ( V_6 , V_125 ) ;
F_35 (KERN_INFO PFX L_42 , drive->name) ;
if ( V_4 -> V_192 )
F_35 ( V_223 L_43 , V_4 -> V_192 ) ;
F_35 ( V_223 L_44 , ( V_140 -> V_199 & V_205 ) ? L_45 : L_46 ) ;
if ( ( V_140 -> V_199 & V_206 ) == 0 || ( V_140 -> V_199 & V_207 ) == 0 )
F_35 ( V_223 L_47 ,
( V_140 -> V_199 & V_206 ) ? L_48 : L_49 ,
( V_140 -> V_199 & V_207 ) ? L_48 : L_50 ) ;
if ( ( V_140 -> V_199 & V_203 ) == 0 || ( V_140 -> V_199 & V_204 ) == 0 )
F_35 ( V_223 L_51 ,
( V_140 -> V_199 & V_203 ) ? L_48 : L_49 ,
( V_140 -> V_199 & V_204 ) ? L_48 : L_52 ) ;
if ( ( V_140 -> V_199 & V_208 ) == 0 )
F_35 ( V_223 L_53 , V_193 ) ;
else
F_35 ( V_223 L_54 ) ;
F_35 ( V_223 L_55 ,
F_94 ( ( V_190 * ) & V_125 [ 8 + 12 ] ) ) ;
return V_193 ;
}
static int F_100 ( struct V_116 * V_117 , struct V_12 * V_13 )
{
int V_224 = F_16 ( V_117 ) ;
long V_128 = ( long ) F_66 ( V_13 ) / ( V_224 >> 9 ) ;
unsigned long V_225 = F_65 ( V_13 ) / ( V_224 >> 9 ) ;
struct V_226 * V_227 = F_13 ( V_13 ) ;
memset ( V_227 -> V_26 , 0 , V_81 ) ;
if ( F_51 ( V_13 ) == V_228 )
V_227 -> V_26 [ 0 ] = V_229 ;
else
V_227 -> V_26 [ 0 ] = V_230 ;
V_227 -> V_26 [ 2 ] = ( V_128 >> 24 ) & 0xff ;
V_227 -> V_26 [ 3 ] = ( V_128 >> 16 ) & 0xff ;
V_227 -> V_26 [ 4 ] = ( V_128 >> 8 ) & 0xff ;
V_227 -> V_26 [ 5 ] = V_128 & 0xff ;
V_227 -> V_26 [ 7 ] = ( V_225 >> 8 ) & 0xff ;
V_227 -> V_26 [ 8 ] = V_225 & 0xff ;
V_227 -> V_231 = 10 ;
return V_232 ;
}
static int F_101 ( struct V_12 * V_13 )
{
T_2 * V_233 = F_13 ( V_13 ) -> V_26 ;
if ( V_233 [ 0 ] == V_234 || V_233 [ 0 ] == V_235 ) {
V_233 [ 8 ] = V_233 [ 4 ] ;
V_233 [ 5 ] = V_233 [ 3 ] ;
V_233 [ 4 ] = V_233 [ 2 ] ;
V_233 [ 3 ] = V_233 [ 1 ] & 0x1f ;
V_233 [ 2 ] = 0 ;
V_233 [ 1 ] &= 0xe0 ;
V_233 [ 0 ] += ( V_236 - V_234 ) ;
F_13 ( V_13 ) -> V_231 = 10 ;
return V_232 ;
}
if ( V_233 [ 0 ] == V_237 || V_233 [ 0 ] == V_238 ) {
V_13 -> V_48 = V_25 ;
return V_239 ;
}
return V_232 ;
}
static int F_102 ( struct V_116 * V_117 , struct V_12 * V_13 )
{
if ( ! F_15 ( V_13 ) )
return F_100 ( V_117 , V_13 ) ;
else if ( F_32 ( V_13 ) )
return F_101 ( V_13 ) ;
return 0 ;
}
static T_8 F_103 ( T_1 * V_6 )
{
unsigned long V_143 , V_118 ;
if ( F_78 ( V_6 , & V_143 , & V_118 , NULL ) )
return 0 ;
return V_143 * V_118 ;
}
static int F_104 ( struct V_240 * V_241 , void * V_242 )
{
T_1 * V_6 = V_241 -> V_243 ;
F_105 ( V_241 , L_56 , ( long long ) F_103 ( V_6 ) ) ;
return 0 ;
}
static int F_106 ( struct V_244 * V_244 , struct V_245 * V_245 )
{
return F_107 ( V_245 , F_104 , F_108 ( V_244 ) ) ;
}
static T_12 * F_109 ( T_1 * V_6 )
{
return V_246 ;
}
static const struct V_247 * F_110 ( T_1 * V_6 )
{
return NULL ;
}
static unsigned int F_111 ( T_7 * V_248 )
{
const struct V_249 * V_250 = V_251 ;
while ( V_250 -> V_252 ) {
if ( strcmp ( V_250 -> V_252 , ( char * ) & V_248 [ V_253 ] ) == 0 &&
( V_250 -> V_254 == NULL ||
strstr ( ( char * ) & V_248 [ V_255 ] , V_250 -> V_254 ) ) )
return V_250 -> V_256 ;
V_250 ++ ;
}
return 0 ;
}
static int F_112 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_139 * V_140 = & V_4 -> V_123 ;
struct V_116 * V_117 = V_6 -> V_40 ;
T_7 * V_248 = V_6 -> V_248 ;
char * V_257 = ( char * ) & V_248 [ V_255 ] ;
int V_193 ;
F_12 ( V_148 , L_33 ) ;
F_113 ( V_117 , F_102 ) ;
F_114 ( V_117 , 31 ) ;
F_115 ( V_117 , 15 ) ;
V_6 -> V_8 |= V_9 ;
V_6 -> V_10 = V_214 | F_111 ( V_248 ) ;
if ( ( V_6 -> V_10 & V_258 ) &&
V_257 [ 4 ] == '1' && V_257 [ 6 ] <= '2' )
V_6 -> V_10 |= ( V_166 |
V_172 ) ;
else if ( ( V_6 -> V_10 & V_259 ) &&
V_257 [ 4 ] == '1' && V_257 [ 6 ] <= '2' )
V_6 -> V_10 |= V_166 ;
else if ( V_6 -> V_10 & V_260 )
V_140 -> V_142 = 3 ;
V_193 = F_98 ( V_6 ) ;
F_84 ( V_117 , V_261 ) ;
if ( F_96 ( V_6 , V_193 ) ) {
F_35 (KERN_ERR PFX L_57
L_58 , drive->name, __func__) ;
V_4 -> V_123 . V_197 = NULL ;
return 1 ;
}
F_116 ( V_6 , V_4 -> V_262 ) ;
return 0 ;
}
static void F_117 ( T_1 * V_6 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
F_12 ( V_68 , L_33 ) ;
F_118 ( V_6 , V_30 -> V_262 ) ;
F_119 ( & V_30 -> V_7 ) ;
F_120 ( V_30 -> V_3 ) ;
F_2 ( & V_5 ) ;
F_8 ( & V_30 -> V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_121 ( struct V_263 * V_7 )
{
struct V_1 * V_30 = F_122 ( V_7 , V_1 ) ;
struct V_139 * V_123 = & V_30 -> V_123 ;
T_1 * V_6 = V_30 -> V_6 ;
struct V_2 * V_264 = V_30 -> V_3 ;
F_12 ( V_68 , L_33 ) ;
F_123 ( V_30 -> V_156 ) ;
if ( V_123 -> V_197 == V_6 )
F_124 ( V_123 ) ;
V_6 -> V_31 = NULL ;
F_113 ( V_6 -> V_40 , NULL ) ;
V_264 -> V_265 = NULL ;
F_125 ( V_264 ) ;
F_123 ( V_30 ) ;
}
static int F_126 ( struct V_266 * V_267 , T_13 V_268 )
{
struct V_1 * V_30 ;
int V_98 = - V_269 ;
F_2 ( & V_270 ) ;
V_30 = F_1 ( V_267 -> V_271 ) ;
if ( ! V_30 )
goto V_272;
V_98 = F_127 ( & V_30 -> V_123 , V_267 , V_268 ) ;
if ( V_98 < 0 )
F_7 ( V_30 ) ;
V_272:
F_6 ( & V_270 ) ;
return V_98 ;
}
static void F_128 ( struct V_2 * V_3 , T_13 V_268 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
F_2 ( & V_270 ) ;
F_129 ( & V_30 -> V_123 , V_268 ) ;
F_7 ( V_30 ) ;
F_6 ( & V_270 ) ;
}
static int F_130 ( struct V_139 * V_140 , unsigned long V_273 )
{
struct V_177 V_178 ;
char V_72 [ 16 ] ;
int V_52 ;
char V_274 ;
if ( F_131 ( & V_274 , ( void V_275 * ) V_273 , sizeof( char ) ) )
return - V_276 ;
F_90 ( & V_178 , V_72 , sizeof( V_72 ) , V_184 ) ;
V_52 = F_91 ( V_140 , & V_178 , V_277 , 0 ) ;
if ( V_52 )
return V_52 ;
V_72 [ 11 ] = ( V_72 [ 11 ] & 0xf0 ) | ( V_274 & 0x0f ) ;
return F_132 ( V_140 , & V_178 ) ;
}
static int F_133 ( struct V_139 * V_140 , unsigned long V_273 )
{
struct V_177 V_178 ;
char V_72 [ 16 ] ;
int V_52 ;
char V_274 ;
F_90 ( & V_178 , V_72 , sizeof( V_72 ) , V_184 ) ;
V_52 = F_91 ( V_140 , & V_178 , V_277 , 0 ) ;
if ( V_52 )
return V_52 ;
V_274 = V_72 [ 11 ] & 0x0f ;
if ( F_134 ( ( void V_275 * ) V_273 , & V_274 , sizeof( char ) ) )
return - V_276 ;
return 0 ;
}
static int F_135 ( struct V_266 * V_267 , T_13 V_268 ,
unsigned int V_26 , unsigned long V_273 )
{
struct V_1 * V_30 = F_3 ( V_267 -> V_271 , V_1 ) ;
int V_54 ;
switch ( V_26 ) {
case V_278 :
return F_130 ( & V_30 -> V_123 , V_273 ) ;
case V_279 :
return F_133 ( & V_30 -> V_123 , V_273 ) ;
default:
break;
}
V_54 = F_136 ( V_30 -> V_6 , V_267 , V_26 , V_273 ) ;
if ( V_54 == - V_280 )
V_54 = F_137 ( & V_30 -> V_123 , V_267 , V_268 , V_26 , V_273 ) ;
return V_54 ;
}
static int F_138 ( struct V_266 * V_267 , T_13 V_268 ,
unsigned int V_26 , unsigned long V_273 )
{
int V_281 ;
F_2 ( & V_270 ) ;
V_281 = F_135 ( V_267 , V_268 , V_26 , V_273 ) ;
F_6 ( & V_270 ) ;
return V_281 ;
}
static unsigned int F_139 ( struct V_2 * V_3 ,
unsigned int V_282 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
return F_140 ( & V_30 -> V_123 , V_282 ) ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
struct V_14 V_15 ;
F_82 ( V_30 -> V_6 , & V_15 ) ;
return 0 ;
}
static int F_142 ( T_1 * V_6 )
{
struct V_1 * V_30 ;
struct V_2 * V_264 ;
struct V_14 V_15 ;
F_12 ( V_148 , L_59 ,
V_6 -> V_283 , V_6 -> V_202 ) ;
if ( ! strstr ( L_60 , V_6 -> V_283 ) )
goto V_44;
if ( V_6 -> V_202 != V_284 && V_6 -> V_202 != V_212 )
goto V_44;
V_6 -> V_130 = V_130 ;
V_6 -> V_285 = F_50 ;
V_30 = F_143 ( sizeof( struct V_1 ) , V_164 ) ;
if ( V_30 == NULL ) {
F_35 (KERN_ERR PFX L_61 ,
drive->name) ;
goto V_44;
}
V_264 = F_144 ( 1 << V_286 ) ;
if ( ! V_264 )
goto V_287;
F_145 ( V_264 , V_6 ) ;
V_30 -> V_7 . V_288 = & V_6 -> V_289 ;
V_30 -> V_7 . V_290 = F_121 ;
F_146 ( & V_30 -> V_7 , L_62 , F_147 ( & V_6 -> V_289 ) ) ;
if ( F_148 ( & V_30 -> V_7 ) )
goto V_291;
V_30 -> V_6 = V_6 ;
V_30 -> V_262 = & V_292 ;
V_30 -> V_3 = V_264 ;
V_264 -> V_265 = & V_30 -> V_262 ;
V_6 -> V_31 = V_30 ;
V_264 -> V_293 = 1 ;
V_264 -> V_294 = V_295 | V_296 ;
if ( F_112 ( V_6 ) ) {
F_8 ( & V_30 -> V_7 ) ;
goto V_44;
}
F_82 ( V_6 , & V_15 ) ;
V_264 -> V_297 = & V_298 ;
V_264 -> V_294 |= V_296 | V_299 ;
F_149 ( & V_6 -> V_289 , V_264 ) ;
return 0 ;
V_291:
F_125 ( V_264 ) ;
V_287:
F_123 ( V_30 ) ;
V_44:
return - V_300 ;
}
static void T_14 F_150 ( void )
{
F_151 ( & V_292 . V_301 ) ;
}
static int T_15 F_152 ( void )
{
F_35 (KERN_INFO DRV_NAME L_63 IDECD_VERSION L_64 ) ;
return F_153 ( & V_292 . V_301 ) ;
}
