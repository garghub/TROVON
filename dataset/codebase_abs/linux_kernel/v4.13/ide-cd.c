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
if ( F_23 ( V_6 , V_44 , V_47 , F_24 ( V_44 ) ) )
F_25 () ;
} else
F_14 ( V_6 , NULL ) ;
}
static int F_26 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
if ( ! F_13 ( V_13 ) -> V_48 )
V_30 -> V_49 = V_50 + V_51 ;
F_13 ( V_13 ) -> V_48 = 1 ;
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
if ( F_32 ( V_13 ) && ! F_13 ( V_13 ) -> V_48 )
F_13 ( V_13 ) -> V_48 = V_59 ;
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
if ( ++ F_13 ( V_13 ) -> V_48 > V_61 )
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
} else if ( ++ F_13 ( V_13 ) -> V_48 > V_61 )
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
memcpy ( F_13 ( V_13 ) -> V_26 , V_26 , V_81 ) ;
F_42 ( V_13 ) -> type = V_82 ;
V_13 -> V_17 |= V_17 ;
V_13 -> V_74 = V_74 ;
if ( V_72 ) {
error = F_43 ( V_6 -> V_40 , V_13 , V_72 ,
* V_73 , V_83 ) ;
if ( error ) {
F_44 ( V_13 ) ;
return error ;
}
}
F_45 ( V_6 -> V_40 , V_30 -> V_3 , V_13 , 0 ) ;
error = F_13 ( V_13 ) -> V_48 ? - V_84 : 0 ;
if ( V_72 )
* V_73 = F_13 ( V_13 ) -> V_85 ;
if ( V_15 )
memcpy ( V_15 , F_13 ( V_13 ) -> V_15 , sizeof( * V_15 ) ) ;
V_44 = ( V_13 -> V_17 & V_58 ) != 0 ;
if ( V_44 ) {
struct V_14 * V_86 = F_13 ( V_13 ) -> V_15 ;
if ( V_86 -> V_20 == V_28 )
F_10 ( V_6 ) ;
else if ( V_86 -> V_20 == V_23 &&
V_86 -> V_24 == 4 && V_86 -> V_87 != 4 ) {
V_77 = true ;
} else {
V_75 = 0 ;
}
-- V_75 ;
}
F_44 ( V_13 ) ;
if ( V_77 )
F_46 ( 2 ) ;
} while ( V_44 && V_75 >= 0 );
return V_44 ? - V_84 : 0 ;
}
static bool F_47 ( T_1 * V_6 , struct V_67 * V_26 )
{
unsigned int V_88 = V_26 -> V_89 - V_26 -> V_70 ;
if ( V_26 -> V_90 & V_91 )
V_88 -= V_26 -> V_92 ;
if ( V_88 > 0 ) {
F_48 ( V_6 , V_93 , V_88 ) ;
return true ;
}
return false ;
}
static T_5 F_49 ( T_1 * V_6 )
{
T_3 * V_53 = V_6 -> V_53 ;
struct V_67 * V_26 = & V_53 -> V_26 ;
struct V_12 * V_13 = V_53 -> V_13 ;
T_6 * V_94 = NULL ;
int V_95 = 0 , V_96 , V_97 , V_98 = 0 ;
int V_71 = ( F_50 ( V_13 ) == V_99 ) ? 1 : 0 , V_100 = 0 ;
int V_15 = F_31 ( V_13 ) ;
unsigned int V_74 ;
T_7 V_101 ;
T_2 V_102 , V_52 ;
F_12 ( V_76 , L_15 , V_13 -> V_26 [ 0 ] , V_71 ) ;
V_96 = V_6 -> V_96 ;
if ( V_96 ) {
V_6 -> V_96 = 0 ;
V_6 -> V_103 = 0 ;
V_95 = V_53 -> V_104 -> V_105 ( V_6 ) ;
F_51 ( V_6 , V_26 ) ;
if ( V_95 ) {
F_35 (KERN_ERR PFX L_16 , drive->name,
write ? L_17 : L_18 ) ;
F_52 ( V_6 ) ;
}
}
V_52 = V_53 -> V_106 -> V_107 ( V_53 ) ;
if ( ! F_53 ( V_52 , 0 , V_108 ) ) {
V_100 = F_29 ( V_6 , V_52 ) ;
if ( V_100 ) {
if ( V_100 == 2 )
goto V_109;
return V_110 ;
}
}
if ( V_96 ) {
if ( V_95 )
return F_37 ( V_6 , L_19 , V_52 ) ;
V_98 = 1 ;
goto V_109;
}
F_54 ( V_6 , & V_101 , & V_102 ) ;
V_97 = ! F_15 ( V_13 ) ? V_101 : V_26 -> V_70 ;
if ( V_97 > V_101 )
V_97 = V_101 ;
F_12 ( V_76 , L_20 ,
V_52 , V_97 ) ;
if ( ( V_52 & V_111 ) == 0 ) {
switch ( F_34 ( V_13 ) ) {
default:
V_98 = 1 ;
if ( V_26 -> V_70 > 0 ) {
F_35 (KERN_ERR PFX L_21
L_22 , drive->name, __func__,
cmd->nleft) ;
if ( ! V_71 )
V_13 -> V_17 |= V_58 ;
V_98 = 0 ;
}
goto V_109;
case V_79 :
case V_78 :
F_39 ( V_6 , V_26 ) ;
V_98 = V_26 -> V_70 ? 0 : 1 ;
if ( ! ( V_52 & V_66 ) && ! V_98 && V_97 ) {
F_55 ( V_6 , V_26 , V_71 , V_97 ) ;
V_98 = V_26 -> V_70 ? 0 : 1 ;
}
if ( ! V_98 )
V_13 -> V_17 |= V_58 ;
goto V_109;
case V_112 :
case V_113 :
goto V_109;
}
}
V_100 = F_56 ( V_6 , V_13 , V_101 , V_102 , V_71 ) ;
if ( V_100 )
goto V_109;
V_26 -> V_92 = 0 ;
F_12 ( V_76 , L_23
L_24 ,
V_13 -> V_57 , V_102 ) ;
while ( V_97 > 0 ) {
int V_114 = F_57 ( int , V_97 , V_26 -> V_70 ) ;
if ( V_26 -> V_70 == 0 )
break;
F_55 ( V_6 , V_26 , V_71 , V_114 ) ;
V_26 -> V_92 += V_114 ;
V_97 -= V_114 ;
V_101 -= V_114 ;
if ( V_15 && V_71 == 0 )
F_13 ( V_13 ) -> V_46 += V_114 ;
}
if ( V_101 > 0 ) {
if ( F_15 ( V_13 ) || V_71 == 0 )
F_58 ( V_6 , V_71 , V_101 ) ;
else {
F_35 (KERN_ERR PFX L_25 ,
drive->name) ;
F_59 ( V_13 , L_26 ) ;
}
}
switch ( F_34 ( V_13 ) ) {
case V_112 :
case V_113 :
V_74 = V_13 -> V_74 ;
break;
case V_79 :
case V_78 :
V_94 = V_115 ;
default:
V_74 = V_116 ;
break;
}
V_53 -> V_94 = V_94 ;
F_60 ( V_6 , F_49 , V_74 ) ;
return V_117 ;
V_109:
if ( F_32 ( V_13 ) && V_100 == 0 ) {
F_13 ( V_13 ) -> V_85 = 0 ;
F_61 ( V_13 , V_93 ) ;
V_53 -> V_13 = NULL ;
} else {
if ( V_15 && V_98 )
F_21 ( V_6 , V_13 ) ;
if ( ! F_15 ( V_13 ) ) {
if ( V_26 -> V_70 == 0 )
V_98 = 1 ;
} else {
if ( V_98 <= 0 && F_13 ( V_13 ) -> V_48 == 0 )
F_13 ( V_13 ) -> V_48 = - V_84 ;
}
if ( V_98 == 0 && V_13 -> V_41 )
if ( F_47 ( V_6 , V_26 ) )
return V_110 ;
if ( F_15 ( V_13 ) ) {
F_13 ( V_13 ) -> V_85 -= V_26 -> V_89 - V_26 -> V_70 ;
if ( V_98 == 0 && ( V_26 -> V_90 & V_91 ) )
F_13 ( V_13 ) -> V_85 += V_26 -> V_92 ;
}
F_48 ( V_6 , V_98 ? V_93 : V_47 , F_24 ( V_13 ) ) ;
if ( V_15 && V_100 == 2 )
F_37 ( V_6 , L_27 , V_52 ) ;
}
return V_110 ;
}
static T_5 F_62 ( T_1 * V_6 , struct V_12 * V_13 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_118 * V_119 = V_6 -> V_40 ;
int V_71 = F_50 ( V_13 ) == V_99 ;
unsigned short V_120 =
F_16 ( V_119 ) >> V_121 ;
F_12 ( V_56 , L_28
L_29 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_122 , V_120 ) ;
if ( V_71 ) {
if ( F_63 ( V_4 -> V_3 ) )
return V_110 ;
} else {
V_119 -> V_123 ( V_119 , V_13 ) ;
}
if ( ( F_64 ( V_13 ) & ( V_120 - 1 ) ) ||
( F_65 ( V_13 ) & ( V_120 - 1 ) ) )
return V_110 ;
V_6 -> V_96 = ! ! ( V_6 -> V_8 & V_124 ) ;
if ( V_71 )
V_4 -> V_125 . V_126 = 1 ;
V_13 -> V_74 = V_116 ;
return V_117 ;
}
static void F_66 ( T_1 * V_6 , struct V_12 * V_13 )
{
F_12 ( V_76 , L_30 ,
V_13 -> V_26 [ 0 ] , V_13 -> V_57 ) ;
if ( F_32 ( V_13 ) )
V_13 -> V_17 |= V_18 ;
else
V_13 -> V_17 &= ~ V_58 ;
V_6 -> V_96 = 0 ;
if ( V_13 -> V_41 ) {
struct V_118 * V_119 = V_6 -> V_40 ;
char * V_127 = F_22 ( V_13 -> V_41 ) ;
unsigned int V_128 ;
V_6 -> V_96 = ! ! ( V_6 -> V_8 & V_124 ) ;
V_128 = F_67 ( V_119 ) | V_119 -> V_129 ;
if ( ( unsigned long ) V_127 & V_128
|| F_24 ( V_13 ) & V_119 -> V_129
|| F_68 ( V_127 ) )
V_6 -> V_96 = 0 ;
}
}
static T_5 F_69 ( T_1 * V_6 , struct V_12 * V_13 ,
T_8 V_130 )
{
struct V_67 V_26 ;
int V_98 = 0 ;
unsigned int V_131 ;
F_12 ( V_56 , L_31 ,
V_13 -> V_26 [ 0 ] , ( unsigned long long ) V_130 ) ;
if ( V_6 -> V_132 & V_56 )
F_59 ( V_13 , L_32 ) ;
switch ( F_34 ( V_13 ) ) {
default:
if ( F_62 ( V_6 , V_13 ) == V_110 )
goto V_109;
break;
case V_112 :
case V_113 :
V_133:
if ( ! V_13 -> V_74 )
V_13 -> V_74 = V_116 ;
F_66 ( V_6 , V_13 ) ;
break;
case V_79 :
case V_78 :
switch ( F_42 ( V_13 ) -> type ) {
case V_134 :
V_98 = 1 ;
goto V_109;
case V_135 :
case V_82 :
goto V_133;
default:
F_25 () ;
}
}
F_70 ( V_6 , V_13 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_50 ( V_13 ) )
V_26 . V_90 |= V_91 ;
V_26 . V_13 = V_13 ;
if ( ! F_15 ( V_13 ) || F_24 ( V_13 ) ) {
F_71 ( & V_26 , F_24 ( V_13 ) ) ;
F_72 ( V_6 , & V_26 ) ;
}
return F_73 ( V_6 , & V_26 ) ;
V_109:
V_131 = F_64 ( V_13 ) ;
if ( V_131 == 0 )
V_131 = 1 ;
F_48 ( V_6 , V_98 ? V_93 : V_47 , V_131 << 9 ) ;
return V_110 ;
}
static void F_74 ( struct V_136 * V_137 )
{
V_137 -> V_138 = F_75 ( V_137 -> V_138 ) ;
V_137 -> V_139 = F_75 ( V_137 -> V_139 ) ;
V_137 -> V_140 = F_75 ( V_137 -> V_140 ) ;
}
int F_76 ( T_1 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_141 * V_142 = & V_30 -> V_125 ;
unsigned char V_26 [ V_81 ] ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_143 ;
V_26 [ 7 ] = V_142 -> V_144 % 3 ;
return F_40 ( V_6 , V_26 , 0 , NULL , NULL , V_15 , 0 , V_18 ) ;
}
static int F_77 ( T_1 * V_6 , unsigned long * V_145 ,
unsigned long * V_120 ,
struct V_14 * V_15 )
{
struct {
T_9 V_146 ;
T_9 V_147 ;
} V_148 ;
int V_52 ;
unsigned char V_26 [ V_81 ] ;
unsigned V_101 = sizeof( V_148 ) ;
T_10 V_147 ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_149 ;
V_52 = F_40 ( V_6 , V_26 , 0 , & V_148 , & V_101 , V_15 , 0 ,
V_18 ) ;
if ( V_52 )
return V_52 ;
V_147 = F_78 ( V_148 . V_147 ) ;
V_147 = ( V_147 >> V_121 ) << V_121 ;
switch ( V_147 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_79 (KERN_ERR PFX L_34
L_35 ,
drive->name, blocklen) ;
V_147 = 2048 ;
break;
}
* V_145 = 1 + F_78 ( V_148 . V_146 ) ;
* V_120 = V_147 >> V_121 ;
F_12 ( V_150 , L_36 ,
* V_145 , * V_120 ) ;
return 0 ;
}
static int F_80 ( T_1 * V_6 , int V_151 , int V_152 ,
int V_153 , char * V_127 , int V_154 ,
struct V_14 * V_15 )
{
unsigned char V_26 [ V_81 ] ;
F_12 ( V_68 , L_33 ) ;
memset ( V_26 , 0 , V_81 ) ;
V_26 [ 0 ] = V_35 ;
V_26 [ 6 ] = V_151 ;
V_26 [ 7 ] = ( V_154 >> 8 ) ;
V_26 [ 8 ] = ( V_154 & 0xff ) ;
V_26 [ 9 ] = ( V_153 << 6 ) ;
if ( V_152 )
V_26 [ 1 ] = 2 ;
return F_40 ( V_6 , V_26 , 0 , V_127 , & V_154 , V_15 , 0 , V_18 ) ;
}
int F_81 ( T_1 * V_6 , struct V_14 * V_15 )
{
int V_52 , V_155 , V_156 ;
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_141 * V_142 = & V_30 -> V_125 ;
struct V_157 * V_158 = V_30 -> V_158 ;
struct {
struct V_159 V_160 ;
struct V_161 V_162 ;
} V_163 ;
long V_164 ;
unsigned long V_120 = V_165 ;
F_12 ( V_68 , L_33 ) ;
if ( V_158 == NULL ) {
V_158 = F_82 ( sizeof( struct V_157 ) , V_166 ) ;
if ( V_158 == NULL ) {
F_35 (KERN_ERR PFX L_37 ,
drive->name) ;
return - V_167 ;
}
V_30 -> V_158 = V_158 ;
}
( void ) F_76 ( V_6 , V_15 ) ;
if ( V_6 -> V_10 & V_11 )
return 0 ;
V_52 = F_77 ( V_6 , & V_158 -> V_145 , & V_120 ,
V_15 ) ;
if ( V_52 )
V_158 -> V_145 = 0x1fffff ;
F_19 ( V_30 -> V_3 , V_158 -> V_145 * V_120 ) ;
V_6 -> V_42 = V_158 -> V_145 * V_120 ;
F_83 ( V_6 -> V_40 ,
V_120 << V_121 ) ;
V_52 = F_80 ( V_6 , 0 , 1 , 0 , ( char * ) & V_158 -> V_160 ,
sizeof( struct V_159 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
if ( V_6 -> V_10 & V_168 ) {
V_158 -> V_160 . V_169 = F_75 ( V_158 -> V_160 . V_169 ) ;
V_158 -> V_160 . V_170 = F_75 ( V_158 -> V_160 . V_170 ) ;
}
V_155 = V_158 -> V_160 . V_170 - V_158 -> V_160 . V_169 + 1 ;
if ( V_155 <= 0 )
return - V_84 ;
if ( V_155 > V_171 )
V_155 = V_171 ;
V_52 = F_80 ( V_6 , V_158 -> V_160 . V_169 , 1 , 0 ,
( char * ) & V_158 -> V_160 ,
sizeof( struct V_159 ) +
( V_155 + 1 ) *
sizeof( struct V_161 ) , V_15 ) ;
if ( V_52 && V_158 -> V_160 . V_169 > 1 ) {
V_155 = 0 ;
V_52 = F_80 ( V_6 , V_172 , 1 , 0 ,
( char * ) & V_158 -> V_160 ,
sizeof( struct V_159 ) +
( V_155 + 1 ) *
sizeof( struct V_161 ) ,
V_15 ) ;
if ( V_52 )
return V_52 ;
if ( V_6 -> V_10 & V_168 ) {
V_158 -> V_160 . V_169 = ( T_2 ) F_84 ( V_172 ) ;
V_158 -> V_160 . V_170 = ( T_2 ) F_84 ( V_172 ) ;
} else {
V_158 -> V_160 . V_169 = V_172 ;
V_158 -> V_160 . V_170 = V_172 ;
}
}
if ( V_52 )
return V_52 ;
V_158 -> V_160 . V_173 = F_85 ( V_158 -> V_160 . V_173 ) ;
if ( V_6 -> V_10 & V_168 ) {
V_158 -> V_160 . V_169 = F_75 ( V_158 -> V_160 . V_169 ) ;
V_158 -> V_160 . V_170 = F_75 ( V_158 -> V_160 . V_170 ) ;
}
for ( V_156 = 0 ; V_156 <= V_155 ; V_156 ++ ) {
if ( V_6 -> V_10 & V_174 ) {
if ( V_6 -> V_10 & V_168 )
V_158 -> V_162 [ V_156 ] . V_175 = F_75 ( V_158 -> V_162 [ V_156 ] . V_175 ) ;
F_74 ( & V_158 -> V_162 [ V_156 ] . V_176 . V_137 ) ;
}
V_158 -> V_162 [ V_156 ] . V_176 . V_146 = F_86 ( V_158 -> V_162 [ V_156 ] . V_176 . V_137 . V_138 ,
V_158 -> V_162 [ V_156 ] . V_176 . V_137 . V_139 ,
V_158 -> V_162 [ V_156 ] . V_176 . V_137 . V_140 ) ;
}
if ( V_158 -> V_160 . V_169 != V_172 ) {
V_52 = F_80 ( V_6 , 0 , 0 , 1 , ( char * ) & V_163 ,
sizeof( V_163 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
V_158 -> V_177 = F_78 ( V_163 . V_162 . V_176 . V_146 ) ;
} else {
V_163 . V_160 . V_170 = V_172 ;
V_163 . V_160 . V_169 = V_163 . V_160 . V_170 ;
V_158 -> V_177 = F_86 ( 0 , 2 , 0 ) ;
}
if ( V_6 -> V_10 & V_174 ) {
V_52 = F_80 ( V_6 , 0 , 1 , 1 , ( char * ) & V_163 ,
sizeof( V_163 ) , V_15 ) ;
if ( V_52 )
return V_52 ;
F_74 ( & V_163 . V_162 . V_176 . V_137 ) ;
V_158 -> V_177 = F_86 ( V_163 . V_162 . V_176 . V_137 . V_138 ,
V_163 . V_162 . V_176 . V_137 . V_139 ,
V_163 . V_162 . V_176 . V_137 . V_140 ) ;
}
V_158 -> V_178 = ( V_163 . V_160 . V_169 != V_163 . V_160 . V_170 ) ;
V_52 = F_87 ( V_142 , & V_164 ) ;
if ( ! V_52 && ( V_164 > V_158 -> V_145 ) ) {
V_158 -> V_145 = V_164 ;
F_19 ( V_30 -> V_3 , V_158 -> V_145 * V_120 ) ;
V_6 -> V_42 = V_158 -> V_145 * V_120 ;
}
V_6 -> V_10 |= V_11 ;
return 0 ;
}
int F_88 ( T_1 * V_6 , T_2 * V_127 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_141 * V_142 = & V_30 -> V_125 ;
struct V_179 V_180 ;
int V_52 , V_181 = 3 , V_182 = V_183 ;
F_12 ( V_68 , L_33 ) ;
if ( ( V_6 -> V_10 & V_184 ) == 0 )
V_182 -= V_185 ;
F_89 ( & V_180 , V_127 , V_182 , V_186 ) ;
do {
V_52 = F_90 ( V_142 , & V_180 , V_187 , 0 ) ;
if ( ! V_52 )
break;
} while ( -- V_181 );
return V_52 ;
}
void F_91 ( T_1 * V_6 , T_2 * V_127 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
T_7 V_188 , V_189 ;
F_12 ( V_68 , L_33 ) ;
if ( V_6 -> V_10 & V_190 ) {
V_188 = F_92 ( ( V_191 * ) & V_127 [ 8 + 14 ] ) ;
V_189 = F_92 ( ( V_191 * ) & V_127 [ 8 + 8 ] ) ;
} else {
V_188 = F_93 ( ( V_192 * ) & V_127 [ 8 + 14 ] ) ;
V_189 = F_93 ( ( V_192 * ) & V_127 [ 8 + 8 ] ) ;
}
F_12 ( V_150 , L_38 ,
V_188 , V_189 ) ;
V_4 -> V_193 = F_94 ( V_188 , 176 ) ;
V_4 -> V_194 = F_94 ( V_189 , 176 ) ;
}
static int F_95 ( T_1 * V_6 , int V_195 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_141 * V_125 = & V_30 -> V_125 ;
F_12 ( V_150 , L_39 , V_195 ) ;
V_125 -> V_196 = & V_197 ;
V_125 -> V_198 = V_30 -> V_193 ;
V_125 -> V_145 = V_195 ;
V_125 -> V_199 = V_6 ;
strcpy ( V_125 -> V_43 , V_6 -> V_43 ) ;
if ( V_6 -> V_10 & V_200 )
V_125 -> V_201 |= V_202 ;
V_125 -> V_3 = V_30 -> V_3 ;
return F_96 ( V_125 ) ;
}
static int F_97 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_141 * V_142 = & V_4 -> V_125 ;
T_2 V_127 [ V_183 ] ;
T_11 V_203 ;
int V_195 = 1 ;
F_12 ( V_150 , L_40 ,
V_6 -> V_204 , V_6 -> V_10 ) ;
V_142 -> V_201 = ( V_205 | V_206 | V_207 | V_208 |
V_209 | V_210 | V_211 |
V_212 | V_213 ) ;
if ( V_6 -> V_204 == V_214 ) {
V_142 -> V_201 &= ~ ( V_212 | V_213 ) ;
F_35 (KERN_ERR PFX L_41 ,
drive->name) ;
return V_195 ;
}
if ( V_6 -> V_10 & V_215 ) {
V_6 -> V_10 &= ~ V_216 ;
V_142 -> V_201 &= ~ V_211 ;
return V_195 ;
}
V_142 -> V_199 = V_6 ;
V_142 -> V_196 = & V_197 ;
if ( F_88 ( V_6 , V_127 ) )
return 0 ;
if ( ( V_127 [ 8 + 6 ] & 0x01 ) == 0 )
V_6 -> V_8 &= ~ V_217 ;
if ( V_127 [ 8 + 6 ] & 0x08 )
V_6 -> V_10 &= ~ V_216 ;
if ( V_127 [ 8 + 3 ] & 0x01 )
V_142 -> V_201 &= ~ V_205 ;
if ( V_127 [ 8 + 3 ] & 0x02 )
V_142 -> V_201 &= ~ ( V_206 | V_213 ) ;
if ( V_127 [ 8 + 2 ] & 0x38 )
V_142 -> V_201 &= ~ V_207 ;
if ( V_127 [ 8 + 3 ] & 0x20 )
V_142 -> V_201 &= ~ ( V_209 | V_213 ) ;
if ( V_127 [ 8 + 3 ] & 0x10 )
V_142 -> V_201 &= ~ V_208 ;
if ( ( V_127 [ 8 + 4 ] & 0x01 ) || ( V_6 -> V_10 & V_218 ) )
V_142 -> V_201 &= ~ V_211 ;
V_203 = V_127 [ 8 + 6 ] >> 5 ;
if ( V_203 == V_219 ||
V_203 == V_220 ||
( V_6 -> V_10 & V_221 ) )
V_142 -> V_201 |= V_222 ;
if ( V_142 -> V_144 > 0 ) {
V_142 -> V_201 &= ~ V_210 ;
V_195 = 3 ;
} else if ( V_203 == V_223 ||
V_203 == V_224 ) {
V_195 = F_98 ( V_142 ) ;
if ( V_195 > 1 )
V_142 -> V_201 &= ~ V_210 ;
}
F_91 ( V_6 , V_127 ) ;
F_35 (KERN_INFO PFX L_42 , drive->name) ;
if ( V_4 -> V_194 )
F_35 ( V_225 L_43 , V_4 -> V_194 ) ;
F_35 ( V_225 L_44 , ( V_142 -> V_201 & V_207 ) ? L_45 : L_46 ) ;
if ( ( V_142 -> V_201 & V_208 ) == 0 || ( V_142 -> V_201 & V_209 ) == 0 )
F_35 ( V_225 L_47 ,
( V_142 -> V_201 & V_208 ) ? L_48 : L_49 ,
( V_142 -> V_201 & V_209 ) ? L_48 : L_50 ) ;
if ( ( V_142 -> V_201 & V_205 ) == 0 || ( V_142 -> V_201 & V_206 ) == 0 )
F_35 ( V_225 L_51 ,
( V_142 -> V_201 & V_205 ) ? L_48 : L_49 ,
( V_142 -> V_201 & V_206 ) ? L_48 : L_52 ) ;
if ( ( V_142 -> V_201 & V_210 ) == 0 )
F_35 ( V_225 L_53 , V_195 ) ;
else
F_35 ( V_225 L_54 ) ;
F_35 ( V_225 L_55 ,
F_93 ( ( V_192 * ) & V_127 [ 8 + 12 ] ) ) ;
return V_195 ;
}
static int F_99 ( struct V_118 * V_119 , struct V_12 * V_13 )
{
int V_226 = F_16 ( V_119 ) ;
long V_130 = ( long ) F_65 ( V_13 ) / ( V_226 >> 9 ) ;
unsigned long V_227 = F_64 ( V_13 ) / ( V_226 >> 9 ) ;
struct V_228 * V_229 = F_13 ( V_13 ) ;
memset ( V_229 -> V_26 , 0 , V_81 ) ;
if ( F_50 ( V_13 ) == V_230 )
V_229 -> V_26 [ 0 ] = V_231 ;
else
V_229 -> V_26 [ 0 ] = V_232 ;
V_229 -> V_26 [ 2 ] = ( V_130 >> 24 ) & 0xff ;
V_229 -> V_26 [ 3 ] = ( V_130 >> 16 ) & 0xff ;
V_229 -> V_26 [ 4 ] = ( V_130 >> 8 ) & 0xff ;
V_229 -> V_26 [ 5 ] = V_130 & 0xff ;
V_229 -> V_26 [ 7 ] = ( V_227 >> 8 ) & 0xff ;
V_229 -> V_26 [ 8 ] = V_227 & 0xff ;
V_229 -> V_233 = 10 ;
return V_234 ;
}
static int F_100 ( struct V_12 * V_13 )
{
T_2 * V_235 = F_13 ( V_13 ) -> V_26 ;
if ( V_235 [ 0 ] == V_236 || V_235 [ 0 ] == V_237 ) {
V_235 [ 8 ] = V_235 [ 4 ] ;
V_235 [ 5 ] = V_235 [ 3 ] ;
V_235 [ 4 ] = V_235 [ 2 ] ;
V_235 [ 3 ] = V_235 [ 1 ] & 0x1f ;
V_235 [ 2 ] = 0 ;
V_235 [ 1 ] &= 0xe0 ;
V_235 [ 0 ] += ( V_238 - V_236 ) ;
F_13 ( V_13 ) -> V_233 = 10 ;
return V_234 ;
}
if ( V_235 [ 0 ] == V_239 || V_235 [ 0 ] == V_240 ) {
F_13 ( V_13 ) -> V_48 = V_25 ;
return V_241 ;
}
return V_234 ;
}
static int F_101 ( struct V_118 * V_119 , struct V_12 * V_13 )
{
if ( ! F_15 ( V_13 ) )
return F_99 ( V_119 , V_13 ) ;
else if ( F_32 ( V_13 ) )
return F_100 ( V_13 ) ;
return 0 ;
}
static T_8 F_102 ( T_1 * V_6 )
{
unsigned long V_145 , V_120 ;
if ( F_77 ( V_6 , & V_145 , & V_120 , NULL ) )
return 0 ;
return V_145 * V_120 ;
}
static int F_103 ( struct V_242 * V_243 , void * V_244 )
{
T_1 * V_6 = V_243 -> V_245 ;
F_104 ( V_243 , L_56 , ( long long ) F_102 ( V_6 ) ) ;
return 0 ;
}
static int F_105 ( struct V_246 * V_246 , struct V_247 * V_247 )
{
return F_106 ( V_247 , F_103 , F_107 ( V_246 ) ) ;
}
static T_12 * F_108 ( T_1 * V_6 )
{
return V_248 ;
}
static const struct V_249 * F_109 ( T_1 * V_6 )
{
return NULL ;
}
static unsigned int F_110 ( T_7 * V_250 )
{
const struct V_251 * V_252 = V_253 ;
while ( V_252 -> V_254 ) {
if ( strcmp ( V_252 -> V_254 , ( char * ) & V_250 [ V_255 ] ) == 0 &&
( V_252 -> V_256 == NULL ||
strstr ( ( char * ) & V_250 [ V_257 ] , V_252 -> V_256 ) ) )
return V_252 -> V_258 ;
V_252 ++ ;
}
return 0 ;
}
static int F_111 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_31 ;
struct V_141 * V_142 = & V_4 -> V_125 ;
struct V_118 * V_119 = V_6 -> V_40 ;
T_7 * V_250 = V_6 -> V_250 ;
char * V_259 = ( char * ) & V_250 [ V_257 ] ;
int V_195 ;
F_12 ( V_150 , L_33 ) ;
F_112 ( V_119 , F_101 ) ;
F_113 ( V_119 , 31 ) ;
F_114 ( V_119 , 15 ) ;
V_6 -> V_8 |= V_9 ;
V_6 -> V_10 = V_216 | F_110 ( V_250 ) ;
if ( ( V_6 -> V_10 & V_260 ) &&
V_259 [ 4 ] == '1' && V_259 [ 6 ] <= '2' )
V_6 -> V_10 |= ( V_168 |
V_174 ) ;
else if ( ( V_6 -> V_10 & V_261 ) &&
V_259 [ 4 ] == '1' && V_259 [ 6 ] <= '2' )
V_6 -> V_10 |= V_168 ;
else if ( V_6 -> V_10 & V_262 )
V_142 -> V_144 = 3 ;
V_195 = F_97 ( V_6 ) ;
F_83 ( V_119 , V_263 ) ;
if ( F_95 ( V_6 , V_195 ) ) {
F_35 (KERN_ERR PFX L_57
L_58 , drive->name, __func__) ;
V_4 -> V_125 . V_199 = NULL ;
return 1 ;
}
F_115 ( V_6 , V_4 -> V_264 ) ;
return 0 ;
}
static void F_116 ( T_1 * V_6 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
F_12 ( V_68 , L_33 ) ;
F_117 ( V_6 , V_30 -> V_264 ) ;
F_118 ( & V_30 -> V_7 ) ;
F_119 ( V_30 -> V_3 ) ;
F_2 ( & V_5 ) ;
F_8 ( & V_30 -> V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_120 ( struct V_265 * V_7 )
{
struct V_1 * V_30 = F_121 ( V_7 , V_1 ) ;
struct V_141 * V_125 = & V_30 -> V_125 ;
T_1 * V_6 = V_30 -> V_6 ;
struct V_2 * V_266 = V_30 -> V_3 ;
F_12 ( V_68 , L_33 ) ;
F_122 ( V_30 -> V_158 ) ;
if ( V_125 -> V_199 == V_6 )
F_123 ( V_125 ) ;
V_6 -> V_31 = NULL ;
F_112 ( V_6 -> V_40 , NULL ) ;
V_266 -> V_267 = NULL ;
F_124 ( V_266 ) ;
F_122 ( V_30 ) ;
}
static int F_125 ( struct V_268 * V_269 , T_13 V_270 )
{
struct V_1 * V_30 ;
int V_100 = - V_271 ;
F_2 ( & V_272 ) ;
V_30 = F_1 ( V_269 -> V_273 ) ;
if ( ! V_30 )
goto V_274;
V_100 = F_126 ( & V_30 -> V_125 , V_269 , V_270 ) ;
if ( V_100 < 0 )
F_7 ( V_30 ) ;
V_274:
F_6 ( & V_272 ) ;
return V_100 ;
}
static void F_127 ( struct V_2 * V_3 , T_13 V_270 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
F_2 ( & V_272 ) ;
F_128 ( & V_30 -> V_125 , V_270 ) ;
F_7 ( V_30 ) ;
F_6 ( & V_272 ) ;
}
static int F_129 ( struct V_141 * V_142 , unsigned long V_275 )
{
struct V_179 V_180 ;
char V_72 [ 16 ] ;
int V_52 ;
char V_276 ;
if ( F_130 ( & V_276 , ( void V_277 * ) V_275 , sizeof( char ) ) )
return - V_278 ;
F_89 ( & V_180 , V_72 , sizeof( V_72 ) , V_186 ) ;
V_52 = F_90 ( V_142 , & V_180 , V_279 , 0 ) ;
if ( V_52 )
return V_52 ;
V_72 [ 11 ] = ( V_72 [ 11 ] & 0xf0 ) | ( V_276 & 0x0f ) ;
return F_131 ( V_142 , & V_180 ) ;
}
static int F_132 ( struct V_141 * V_142 , unsigned long V_275 )
{
struct V_179 V_180 ;
char V_72 [ 16 ] ;
int V_52 ;
char V_276 ;
F_89 ( & V_180 , V_72 , sizeof( V_72 ) , V_186 ) ;
V_52 = F_90 ( V_142 , & V_180 , V_279 , 0 ) ;
if ( V_52 )
return V_52 ;
V_276 = V_72 [ 11 ] & 0x0f ;
if ( F_133 ( ( void V_277 * ) V_275 , & V_276 , sizeof( char ) ) )
return - V_278 ;
return 0 ;
}
static int F_134 ( struct V_268 * V_269 , T_13 V_270 ,
unsigned int V_26 , unsigned long V_275 )
{
struct V_1 * V_30 = F_3 ( V_269 -> V_273 , V_1 ) ;
int V_54 ;
switch ( V_26 ) {
case V_280 :
return F_129 ( & V_30 -> V_125 , V_275 ) ;
case V_281 :
return F_132 ( & V_30 -> V_125 , V_275 ) ;
default:
break;
}
V_54 = F_135 ( V_30 -> V_6 , V_269 , V_26 , V_275 ) ;
if ( V_54 == - V_282 )
V_54 = F_136 ( & V_30 -> V_125 , V_269 , V_270 , V_26 , V_275 ) ;
return V_54 ;
}
static int F_137 ( struct V_268 * V_269 , T_13 V_270 ,
unsigned int V_26 , unsigned long V_275 )
{
int V_283 ;
F_2 ( & V_272 ) ;
V_283 = F_134 ( V_269 , V_270 , V_26 , V_275 ) ;
F_6 ( & V_272 ) ;
return V_283 ;
}
static unsigned int F_138 ( struct V_2 * V_3 ,
unsigned int V_284 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
return F_139 ( & V_30 -> V_125 , V_284 ) ;
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_3 ( V_3 , V_1 ) ;
struct V_14 V_15 ;
F_81 ( V_30 -> V_6 , & V_15 ) ;
return 0 ;
}
static int F_141 ( T_1 * V_6 )
{
struct V_1 * V_30 ;
struct V_2 * V_266 ;
struct V_14 V_15 ;
F_12 ( V_150 , L_59 ,
V_6 -> V_285 , V_6 -> V_204 ) ;
if ( ! strstr ( L_60 , V_6 -> V_285 ) )
goto V_44;
if ( V_6 -> V_204 != V_286 && V_6 -> V_204 != V_214 )
goto V_44;
V_6 -> V_132 = V_132 ;
V_6 -> V_287 = F_49 ;
V_30 = F_142 ( sizeof( struct V_1 ) , V_166 ) ;
if ( V_30 == NULL ) {
F_35 (KERN_ERR PFX L_61 ,
drive->name) ;
goto V_44;
}
V_266 = F_143 ( 1 << V_288 ) ;
if ( ! V_266 )
goto V_289;
F_144 ( V_266 , V_6 ) ;
V_30 -> V_7 . V_290 = & V_6 -> V_291 ;
V_30 -> V_7 . V_292 = F_120 ;
F_145 ( & V_30 -> V_7 , L_62 , F_146 ( & V_6 -> V_291 ) ) ;
if ( F_147 ( & V_30 -> V_7 ) )
goto V_293;
V_30 -> V_6 = V_6 ;
V_30 -> V_264 = & V_294 ;
V_30 -> V_3 = V_266 ;
V_266 -> V_267 = & V_30 -> V_264 ;
V_6 -> V_31 = V_30 ;
V_266 -> V_295 = 1 ;
V_266 -> V_296 = V_297 | V_298 ;
if ( F_111 ( V_6 ) ) {
F_8 ( & V_30 -> V_7 ) ;
goto V_44;
}
F_81 ( V_6 , & V_15 ) ;
V_266 -> V_299 = & V_300 ;
V_266 -> V_296 |= V_298 | V_301 ;
F_148 ( & V_6 -> V_291 , V_266 ) ;
return 0 ;
V_293:
F_124 ( V_266 ) ;
V_289:
F_122 ( V_30 ) ;
V_44:
return - V_302 ;
}
static void T_14 F_149 ( void )
{
F_150 ( & V_294 . V_303 ) ;
}
static int T_15 F_151 ( void )
{
F_35 (KERN_INFO DRV_NAME L_63 IDECD_VERSION L_64 ) ;
return F_152 ( & V_294 . V_303 ) ;
}
