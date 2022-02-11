static inline int F_1 ( T_1 * V_1 )
{
return V_1 -> V_2 == V_3 || V_1 -> V_2 == V_4 ;
}
int F_2 ( T_1 * V_1 , const char * V_5 )
{
T_2 * V_6 = V_1 -> V_6 ;
T_3 V_7 [ 2 ] , V_8 , V_9 , V_10 , V_11 , V_12 ;
* ( ( T_2 * ) & V_7 ) = V_6 [ V_13 ] ;
V_8 = ( V_7 [ 1 ] & 0xC0 ) >> 6 ;
V_9 = V_7 [ 1 ] & 0x1F ;
V_10 = ( V_7 [ 0 ] & 0x80 ) >> 7 ;
V_11 = ( V_7 [ 0 ] & 0x60 ) >> 5 ;
V_12 = V_7 [ 0 ] & 0x03 ;
#ifdef F_3
if ( V_1 -> V_2 == V_14 && V_9 == 5 &&
! strstr ( ( char * ) & V_6 [ V_15 ] , L_1 ) &&
strstr ( ( char * ) & V_6 [ V_15 ] , L_2 ) )
V_9 = 0 ;
#endif
if ( V_8 != 2 )
F_4 ( V_16 L_3 ,
V_5 , V_1 -> V_17 , V_8 ) ;
else if ( ( V_1 -> V_2 == V_14 && V_9 != 0 ) ||
( V_1 -> V_2 == V_18 && V_9 != 1 ) )
F_4 ( V_16 L_4 ,
V_5 , V_1 -> V_17 , V_9 ) ;
else if ( V_10 == 0 )
F_4 ( V_16 L_5 ,
V_5 , V_1 -> V_17 ) ;
else if ( V_1 -> V_2 == V_14 && V_11 == 3 )
F_4 ( V_16 L_6
L_7 , V_5 , V_1 -> V_17 , V_11 ) ;
else if ( V_12 != 0 )
F_4 ( V_16 L_8
L_9 , V_5 , V_1 -> V_17 , V_12 ) ;
else
return 1 ;
return 0 ;
}
void F_5 ( struct V_19 * V_20 )
{
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
}
int F_6 ( T_1 * V_1 , struct V_21 * V_22 ,
struct V_19 * V_20 , void * V_23 , unsigned int V_24 )
{
struct V_25 * V_26 ;
int error ;
V_26 = F_7 ( V_1 -> V_27 , V_28 , V_29 ) ;
V_26 -> V_30 = V_31 ;
V_26 -> V_32 = ( char * ) V_20 ;
if ( V_23 && V_24 ) {
error = F_8 ( V_1 -> V_27 , V_26 , V_23 , V_24 ,
V_33 ) ;
if ( error )
goto V_34;
}
memcpy ( V_26 -> V_35 , V_20 -> V_36 , 12 ) ;
if ( V_1 -> V_2 == V_18 )
V_26 -> V_35 [ 13 ] = V_37 ;
error = F_9 ( V_1 -> V_27 , V_22 , V_26 , 0 ) ;
V_34:
F_10 ( V_26 ) ;
return error ;
}
int F_11 ( T_1 * V_1 , struct V_21 * V_22 )
{
struct V_19 V_20 ;
F_5 ( & V_20 ) ;
V_20 . V_36 [ 0 ] = V_38 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
int F_12 ( T_1 * V_1 , struct V_21 * V_22 , int V_39 )
{
struct V_19 V_20 ;
F_5 ( & V_20 ) ;
V_20 . V_36 [ 0 ] = V_40 ;
V_20 . V_36 [ 4 ] = V_39 ;
if ( V_1 -> V_2 == V_18 )
V_20 . V_41 |= V_42 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
int F_13 ( T_1 * V_1 , struct V_21 * V_22 , int V_43 )
{
struct V_19 V_20 ;
if ( ( V_1 -> V_44 & V_45 ) == 0 )
return 0 ;
F_5 ( & V_20 ) ;
V_20 . V_36 [ 0 ] = V_46 ;
V_20 . V_36 [ 4 ] = V_43 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
void F_14 ( T_1 * V_1 , struct V_19 * V_20 )
{
F_5 ( V_20 ) ;
V_20 -> V_36 [ 0 ] = V_47 ;
if ( V_1 -> V_2 == V_14 ) {
V_20 -> V_36 [ 4 ] = 255 ;
V_20 -> V_48 = 18 ;
} else {
V_20 -> V_36 [ 4 ] = 20 ;
V_20 -> V_48 = 20 ;
}
}
void F_15 ( T_1 * V_1 , struct V_25 * V_26 )
{
struct V_49 * V_50 = & V_1 -> V_51 ;
struct V_25 * V_52 = & V_1 -> V_52 ;
unsigned int V_53 , V_54 ;
int V_55 ;
switch ( V_1 -> V_2 ) {
case V_14 :
V_53 = 255 ;
V_54 = 18 ;
break;
case V_18 :
V_53 = 20 ;
V_54 = 20 ;
break;
default:
V_53 = 18 ;
V_54 = 18 ;
}
F_16 ( V_54 > sizeof( * V_50 ) ) ;
if ( V_26 -> V_30 == V_56 || V_1 -> V_57 )
return;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_17 ( V_26 -> V_58 , V_52 ) ;
V_55 = F_8 ( V_1 -> V_27 , V_52 , V_50 , V_54 ,
V_33 ) ;
if ( F_18 ( V_55 ) ) {
if ( F_19 () )
F_4 (KERN_WARNING PFX L_10
L_11 , drive->name) ;
return;
}
V_52 -> V_59 = V_26 -> V_59 ;
V_52 -> V_35 [ 0 ] = V_60 ;
V_52 -> V_35 [ 4 ] = V_53 ;
V_52 -> V_30 = V_56 ;
V_52 -> V_61 |= V_62 ;
if ( V_1 -> V_2 == V_18 )
V_52 -> V_35 [ 13 ] = V_37 ;
V_1 -> V_57 = true ;
}
int F_20 ( T_1 * V_1 , void * V_32 )
{
if ( ! V_1 -> V_57 ) {
F_4 (KERN_WARNING PFX L_12 ,
drive->name) ;
return - V_63 ;
}
V_1 -> V_52 . V_32 = V_32 ;
V_1 -> V_57 = false ;
V_1 -> V_64 -> V_26 = NULL ;
F_21 ( V_1 -> V_27 , & V_1 -> V_52 , V_65 ) ;
return 0 ;
}
void F_22 ( T_1 * V_1 )
{
struct V_25 * V_66 = V_1 -> V_64 -> V_26 ;
struct V_25 * V_52 = & V_1 -> V_52 ;
struct V_19 * V_20 = & V_1 -> V_67 ;
( void ) F_23 ( V_1 ) ;
F_5 ( V_20 ) ;
memcpy ( V_20 -> V_36 , V_52 -> V_35 , 12 ) ;
if ( V_1 -> V_2 == V_18 )
V_1 -> V_68 |= V_69 ;
V_1 -> V_64 -> V_26 = NULL ;
F_24 ( V_1 , V_66 ) ;
if ( F_20 ( V_1 , V_20 ) ) {
F_25 ( V_66 ) ;
F_26 ( V_1 , - V_70 , F_27 ( V_66 ) ) ;
}
}
int F_28 ( T_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_64 -> V_26 ;
unsigned long V_71 = 0 ;
F_29 ( L_13 , V_72 , V_26 -> V_35 [ 0 ] ) ;
switch ( V_26 -> V_35 [ 0 ] ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_71 = V_78 ;
break;
default:
if ( ! ( V_26 -> V_61 & V_79 ) )
F_4 (KERN_INFO PFX L_14 ,
rq->cmd[0]) ;
V_71 = 0 ;
break;
}
return V_71 ;
}
int F_30 ( struct V_25 * V_26 )
{
switch ( V_26 -> V_30 ) {
case V_80 :
return 32768 ;
case V_56 :
case V_81 :
case V_82 :
return F_27 ( V_26 ) ;
default:
return 0 ;
}
}
void F_31 ( T_1 * V_1 , T_2 * V_83 , T_3 * V_84 )
{
struct V_85 V_86 ;
V_1 -> V_64 -> V_87 -> V_88 ( V_1 , & V_86 , V_89 |
V_90 | V_91 ) ;
* V_83 = ( V_86 . V_92 << 8 ) | V_86 . V_93 ;
* V_84 = V_86 . V_94 & 3 ;
}
int F_32 ( T_1 * V_1 , struct V_25 * V_26 , int V_95 ,
int V_84 , int V_96 )
{
T_4 * V_64 = V_1 -> V_64 ;
F_29 ( L_15 , V_84 , V_96 ) ;
if ( V_84 == ( ! V_96 << 1 ) )
return 0 ;
else if ( V_84 == ( V_96 << 1 ) ) {
F_4 (KERN_ERR PFX L_16 ,
drive->name, __func__) ;
if ( F_1 ( V_1 ) )
F_33 ( V_1 , V_96 , V_95 ) ;
} else if ( ! V_96 && V_84 == V_97 ) {
if ( F_1 ( V_1 ) ) {
( void ) V_64 -> V_87 -> V_98 ( V_64 ) ;
return 0 ;
}
} else {
if ( V_84 & V_97 )
F_4 (KERN_ERR PFX L_17 , drive->name,
__func__) ;
F_4 (KERN_ERR PFX L_18 ,
drive->name, __func__, ireason) ;
}
if ( F_1 ( V_1 ) && V_26 -> V_30 == V_82 )
V_26 -> V_61 |= V_99 ;
return 1 ;
}
static T_5 F_34 ( T_1 * V_1 )
{
struct V_19 * V_20 = V_1 -> V_20 ;
T_4 * V_64 = V_1 -> V_64 ;
struct V_100 * V_35 = & V_64 -> V_35 ;
struct V_25 * V_26 = V_64 -> V_26 ;
const struct V_101 * V_87 = V_64 -> V_87 ;
unsigned int V_102 , V_103 ;
T_2 V_83 ;
T_3 V_104 , V_84 , V_105 = 0 ;
T_3 V_106 = ! ! ( V_20 -> V_41 & V_107 ) ;
F_29 ( L_19 , V_72 ) ;
V_102 = ( V_1 -> V_2 == V_14 ) ? V_108
: V_109 ;
V_104 = V_87 -> V_98 ( V_64 ) ;
if ( V_20 -> V_41 & V_110 ) {
int V_111 ;
V_1 -> V_112 = 0 ;
V_111 = V_64 -> V_113 -> V_114 ( V_1 ) ;
F_35 ( V_1 , V_35 ) ;
if ( V_111 || ( V_1 -> V_2 == V_18 && ( V_104 & V_115 ) ) ) {
if ( V_1 -> V_2 == V_14 )
F_4 (KERN_ERR PFX L_20 ,
drive->name, rq_data_dir(pc->rq)
? L_21 : L_22 ) ;
V_20 -> V_41 |= V_116 ;
} else
V_26 -> V_117 = 0 ;
F_29 ( L_23 , V_1 -> V_17 ) ;
}
if ( ( V_104 & V_118 ) == 0 ) {
int V_119 , error ;
F_29 ( L_24 ,
F_27 ( V_26 ) ) ;
V_20 -> V_41 &= ~ V_110 ;
F_36 () ;
if ( V_1 -> V_2 == V_18 &&
( V_104 & V_115 ) && V_26 -> V_35 [ 0 ] == V_47 )
V_104 &= ~ V_115 ;
if ( ( V_104 & V_115 ) || ( V_20 -> V_41 & V_116 ) ) {
F_29 ( L_25 , V_1 -> V_17 ) ;
if ( V_1 -> V_2 != V_18 )
V_20 -> V_26 -> V_120 ++ ;
if ( V_26 -> V_35 [ 0 ] == V_47 ) {
F_4 (KERN_ERR PFX L_26
L_27 , drive->name) ;
return F_37 ( V_1 ) ;
}
F_29 ( L_28 , V_26 -> V_35 [ 0 ] ) ;
F_22 ( V_1 ) ;
return V_121 ;
}
V_20 -> error = 0 ;
if ( ( V_20 -> V_41 & V_42 ) && ( V_104 & V_122 ) == 0 )
V_105 = 1 ;
V_103 = F_27 ( V_26 ) ;
V_119 = V_1 -> V_123 ( V_1 , V_105 ) ;
if ( V_119 == 0 )
V_1 -> V_124 = NULL ;
if ( V_26 -> V_30 == V_31 ) {
V_26 -> V_120 = 0 ;
error = 0 ;
} else {
if ( V_26 -> V_30 != V_80 && V_119 <= 0 ) {
if ( V_26 -> V_120 == 0 )
V_26 -> V_120 = - V_70 ;
}
error = V_119 ? 0 : - V_70 ;
}
F_26 ( V_1 , error , F_27 ( V_26 ) ) ;
return V_121 ;
}
if ( V_20 -> V_41 & V_110 ) {
V_20 -> V_41 &= ~ V_110 ;
F_4 (KERN_ERR PFX L_29
L_30 , drive->name) ;
F_38 ( V_1 ) ;
return F_37 ( V_1 ) ;
}
F_31 ( V_1 , & V_83 , & V_84 ) ;
if ( F_32 ( V_1 , V_26 , V_83 , V_84 , V_106 ) )
return F_37 ( V_1 ) ;
V_103 = F_39 (unsigned int, bcount, cmd->nleft) ;
F_40 ( V_1 , V_35 , V_106 , V_103 ) ;
V_26 -> V_117 -= V_103 ;
V_83 -= V_103 ;
if ( V_83 )
F_33 ( V_1 , V_106 , V_83 ) ;
F_29 ( L_31 ,
V_26 -> V_35 [ 0 ] , V_103 , V_83 , V_26 -> V_117 ) ;
F_41 ( V_1 , F_34 , V_102 ) ;
return V_125 ;
}
static void F_42 ( struct V_100 * V_35 , T_3 V_126 ,
T_2 V_83 , T_3 V_127 )
{
V_35 -> V_8 = V_127 ? V_128 : V_129 ;
V_35 -> V_130 . V_131 . V_86 = V_91 | V_90 |
V_132 | V_126 ;
V_35 -> V_86 . V_133 = V_134 ;
V_35 -> V_86 . V_135 = V_127 ;
V_35 -> V_86 . V_93 = V_83 & 0xff ;
V_35 -> V_86 . V_92 = ( V_83 >> 8 ) & 0xff ;
}
static T_3 F_43 ( T_1 * V_1 )
{
struct V_85 V_86 ;
V_1 -> V_64 -> V_87 -> V_88 ( V_1 , & V_86 , V_89 ) ;
return V_86 . V_94 & 3 ;
}
static T_3 F_44 ( T_1 * V_1 , T_3 V_84 )
{
int V_136 = 100 ;
while ( V_136 -- && ( ( V_84 & V_97 ) == 0 ||
( V_84 & V_137 ) ) ) {
F_4 (KERN_ERR PFX L_32
L_33 , drive->name) ;
F_45 ( 100 ) ;
V_84 = F_43 ( V_1 ) ;
if ( V_136 == 0 ) {
F_4 (KERN_ERR PFX L_34
L_35 ,
drive->name) ;
V_84 |= V_97 ;
V_84 &= ~ V_137 ;
}
}
return V_84 ;
}
static int F_46 ( T_1 * V_1 )
{
V_1 -> V_64 -> V_87 -> V_138 ( V_1 , NULL , V_1 -> V_20 -> V_36 , 12 ) ;
return V_108 ;
}
static T_5 F_47 ( T_1 * V_1 )
{
struct V_19 * V_139 ( V_20 ) ;
T_4 * V_64 = V_1 -> V_64 ;
struct V_25 * V_26 = V_64 -> V_26 ;
T_6 * V_140 ;
unsigned int V_102 ;
int V_53 ;
T_5 V_141 ;
T_3 V_84 ;
if ( F_48 ( & V_141 , V_1 , V_118 , V_142 , V_143 ) ) {
F_4 (KERN_ERR PFX L_36
L_37 , drive->name) ;
return V_141 ;
}
if ( V_1 -> V_68 & V_144 ) {
if ( V_1 -> V_127 )
V_1 -> V_112 = 1 ;
}
if ( F_1 ( V_1 ) ) {
V_53 = F_49 ( V_26 -> V_35 [ 0 ] ) ;
if ( V_53 < V_145 )
V_53 = V_145 ;
V_102 = V_26 -> V_102 ;
V_140 = F_28 ;
} else {
V_20 = V_1 -> V_20 ;
V_53 = V_145 ;
if ( V_1 -> V_68 & V_146 ) {
V_102 = V_1 -> V_147 ;
V_140 = & F_46 ;
} else {
V_102 = ( V_1 -> V_2 == V_14 ) ? V_108
: V_109 ;
V_140 = NULL ;
}
V_84 = F_43 ( V_1 ) ;
if ( V_1 -> V_2 == V_18 )
V_84 = F_44 ( V_1 , V_84 ) ;
if ( ( V_84 & V_97 ) == 0 || ( V_84 & V_137 ) ) {
F_4 (KERN_ERR PFX L_38
L_39 , drive->name) ;
return F_37 ( V_1 ) ;
}
}
V_64 -> V_140 = V_140 ;
F_41 ( V_1 ,
( F_1 ( V_1 ) ? V_1 -> V_148
: F_34 ) ,
V_102 ) ;
if ( ( V_1 -> V_68 & V_146 ) == 0 )
V_64 -> V_87 -> V_138 ( V_1 , NULL , V_26 -> V_35 , V_53 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_127 )
V_64 -> V_113 -> V_149 ( V_1 ) ;
} else {
if ( V_20 -> V_41 & V_150 ) {
V_20 -> V_41 |= V_110 ;
V_64 -> V_113 -> V_149 ( V_1 ) ;
}
}
return V_125 ;
}
T_5 F_50 ( T_1 * V_1 , struct V_100 * V_35 )
{
struct V_19 * V_20 ;
T_4 * V_64 = V_1 -> V_64 ;
T_6 * V_140 = NULL ;
struct V_25 * V_26 = V_64 -> V_26 ;
unsigned int V_102 , V_151 ;
T_2 V_83 ;
T_3 V_126 ;
T_3 V_152 = ! ! ( V_1 -> V_68 & V_144 ) ;
if ( F_1 ( V_1 ) ) {
V_126 = V_89 | V_153 ;
V_83 = F_30 ( V_26 ) ;
V_140 = F_28 ;
V_102 = V_78 ;
if ( V_1 -> V_127 )
V_1 -> V_127 = ! F_51 ( V_1 , V_35 ) ;
} else {
V_20 = V_1 -> V_20 ;
V_126 = V_154 ;
V_151 = F_27 ( V_26 ) ;
V_83 = ( ( V_1 -> V_2 == V_18 ) ? V_151
: F_39 (unsigned int,
bytes, 63 * 1024 ) ) ;
V_26 -> V_117 = V_83 ;
if ( V_20 -> V_41 & V_116 ) {
V_20 -> V_41 &= ~ V_116 ;
F_38 ( V_1 ) ;
}
if ( V_20 -> V_41 & V_150 )
V_1 -> V_127 = ! F_51 ( V_1 , V_35 ) ;
if ( ! V_1 -> V_127 )
V_20 -> V_41 &= ~ V_150 ;
V_102 = ( V_1 -> V_2 == V_14 ) ? V_108
: V_109 ;
}
F_42 ( V_35 , V_126 , V_83 , V_1 -> V_127 ) ;
( void ) F_52 ( V_1 , V_35 ) ;
if ( V_152 ) {
if ( V_1 -> V_127 )
V_1 -> V_112 = 0 ;
V_64 -> V_140 = V_140 ;
}
F_53 ( V_1 , V_35 , F_47 , V_102 ) ;
return V_152 ? V_125 : F_47 ( V_1 ) ;
}
