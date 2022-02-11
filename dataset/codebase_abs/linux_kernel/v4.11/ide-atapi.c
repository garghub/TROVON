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
F_8 ( V_26 ) ;
F_9 ( V_26 ) -> type = V_30 ;
V_26 -> V_31 = ( char * ) V_20 ;
if ( V_23 && V_24 ) {
error = F_10 ( V_1 -> V_27 , V_26 , V_23 , V_24 ,
V_32 ) ;
if ( error )
goto V_33;
}
memcpy ( F_11 ( V_26 ) -> V_34 , V_20 -> V_35 , 12 ) ;
if ( V_1 -> V_2 == V_18 )
F_11 ( V_26 ) -> V_34 [ 13 ] = V_36 ;
error = F_12 ( V_1 -> V_27 , V_22 , V_26 , 0 ) ;
V_33:
F_13 ( V_26 ) ;
return error ;
}
int F_14 ( T_1 * V_1 , struct V_21 * V_22 )
{
struct V_19 V_20 ;
F_5 ( & V_20 ) ;
V_20 . V_35 [ 0 ] = V_37 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
int F_15 ( T_1 * V_1 , struct V_21 * V_22 , int V_38 )
{
struct V_19 V_20 ;
F_5 ( & V_20 ) ;
V_20 . V_35 [ 0 ] = V_39 ;
V_20 . V_35 [ 4 ] = V_38 ;
if ( V_1 -> V_2 == V_18 )
V_20 . V_40 |= V_41 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
int F_16 ( T_1 * V_1 , struct V_21 * V_22 , int V_42 )
{
struct V_19 V_20 ;
if ( ( V_1 -> V_43 & V_44 ) == 0 )
return 0 ;
F_5 ( & V_20 ) ;
V_20 . V_35 [ 0 ] = V_45 ;
V_20 . V_35 [ 4 ] = V_42 ;
return F_6 ( V_1 , V_22 , & V_20 , NULL , 0 ) ;
}
void F_17 ( T_1 * V_1 , struct V_19 * V_20 )
{
F_5 ( V_20 ) ;
V_20 -> V_35 [ 0 ] = V_46 ;
if ( V_1 -> V_2 == V_14 ) {
V_20 -> V_35 [ 4 ] = 255 ;
V_20 -> V_47 = 18 ;
} else {
V_20 -> V_35 [ 4 ] = 20 ;
V_20 -> V_47 = 20 ;
}
}
void F_18 ( T_1 * V_1 , struct V_25 * V_26 )
{
struct V_48 * V_49 = & V_1 -> V_50 ;
struct V_25 * V_51 = V_1 -> V_51 ;
struct V_52 * V_53 = F_11 ( V_51 ) ;
unsigned int V_54 , V_55 ;
int V_56 ;
switch ( V_1 -> V_2 ) {
case V_14 :
V_54 = 255 ;
V_55 = 18 ;
break;
case V_18 :
V_54 = 20 ;
V_55 = 20 ;
break;
default:
V_54 = 18 ;
V_55 = 18 ;
}
F_19 ( V_55 > sizeof( * V_49 ) ) ;
if ( F_20 ( V_26 ) || V_1 -> V_57 )
return;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_21 ( V_26 -> V_58 , V_51 ) ;
F_8 ( V_51 ) ;
V_56 = F_10 ( V_1 -> V_27 , V_51 , V_49 , V_55 ,
V_32 ) ;
if ( F_22 ( V_56 ) ) {
if ( F_23 () )
F_4 (KERN_WARNING PFX L_10
L_11 , drive->name) ;
return;
}
V_51 -> V_59 = V_26 -> V_59 ;
V_51 -> V_60 = V_28 ;
F_9 ( V_51 ) -> type = V_61 ;
V_51 -> V_62 |= V_63 ;
V_53 -> V_34 [ 0 ] = V_64 ;
V_53 -> V_34 [ 4 ] = V_54 ;
if ( V_1 -> V_2 == V_18 )
V_53 -> V_34 [ 13 ] = V_36 ;
V_1 -> V_57 = true ;
}
int F_24 ( T_1 * V_1 , void * V_31 )
{
if ( ! V_1 -> V_57 ) {
F_4 (KERN_WARNING PFX L_12 ,
drive->name) ;
return - V_65 ;
}
V_1 -> V_51 -> V_31 = V_31 ;
V_1 -> V_57 = false ;
V_1 -> V_66 -> V_26 = NULL ;
F_25 ( V_1 -> V_27 , V_1 -> V_51 , V_67 ) ;
return 0 ;
}
void F_26 ( T_1 * V_1 )
{
struct V_25 * V_68 = V_1 -> V_66 -> V_26 ;
struct V_25 * V_51 = V_1 -> V_51 ;
struct V_19 * V_20 = & V_1 -> V_69 ;
( void ) F_27 ( V_1 ) ;
F_5 ( V_20 ) ;
memcpy ( V_20 -> V_35 , F_11 ( V_51 ) -> V_34 , 12 ) ;
if ( V_1 -> V_2 == V_18 )
V_1 -> V_70 |= V_71 ;
V_1 -> V_66 -> V_26 = NULL ;
F_28 ( V_1 , V_68 ) ;
if ( F_24 ( V_1 , V_20 ) ) {
F_29 ( V_68 ) ;
F_30 ( V_1 , - V_72 , F_31 ( V_68 ) ) ;
}
}
int F_32 ( T_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_66 -> V_26 ;
unsigned long V_73 = 0 ;
F_33 ( L_13 , V_74 , V_26 -> V_34 [ 0 ] ) ;
switch ( F_11 ( V_26 ) -> V_34 [ 0 ] ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_73 = V_80 ;
break;
default:
if ( ! ( V_26 -> V_62 & V_81 ) )
F_4 (KERN_INFO PFX L_14 ,
scsi_req(rq)->cmd[0]) ;
V_73 = 0 ;
break;
}
return V_73 ;
}
int F_34 ( struct V_25 * V_26 )
{
switch ( F_35 ( V_26 ) ) {
default:
return 32768 ;
case V_82 :
case V_83 :
return F_31 ( V_26 ) ;
case V_28 :
case V_84 :
switch ( F_9 ( V_26 ) -> type ) {
case V_85 :
case V_61 :
return F_31 ( V_26 ) ;
default:
return 0 ;
}
}
}
void F_36 ( T_1 * V_1 , T_2 * V_86 , T_3 * V_87 )
{
struct V_88 V_89 ;
V_1 -> V_66 -> V_90 -> V_91 ( V_1 , & V_89 , V_92 |
V_93 | V_94 ) ;
* V_86 = ( V_89 . V_95 << 8 ) | V_89 . V_96 ;
* V_87 = V_89 . V_97 & 3 ;
}
int F_37 ( T_1 * V_1 , struct V_25 * V_26 , int V_98 ,
int V_87 , int V_99 )
{
T_4 * V_66 = V_1 -> V_66 ;
F_33 ( L_15 , V_87 , V_99 ) ;
if ( V_87 == ( ! V_99 << 1 ) )
return 0 ;
else if ( V_87 == ( V_99 << 1 ) ) {
F_4 (KERN_ERR PFX L_16 ,
drive->name, __func__) ;
if ( F_1 ( V_1 ) )
F_38 ( V_1 , V_99 , V_98 ) ;
} else if ( ! V_99 && V_87 == V_100 ) {
if ( F_1 ( V_1 ) ) {
( void ) V_66 -> V_90 -> V_101 ( V_66 ) ;
return 0 ;
}
} else {
if ( V_87 & V_100 )
F_4 (KERN_ERR PFX L_17 , drive->name,
__func__) ;
F_4 (KERN_ERR PFX L_18 ,
drive->name, __func__, ireason) ;
}
if ( F_1 ( V_1 ) && F_39 ( V_26 ) )
V_26 -> V_62 |= V_102 ;
return 1 ;
}
static T_5 F_40 ( T_1 * V_1 )
{
struct V_19 * V_20 = V_1 -> V_20 ;
T_4 * V_66 = V_1 -> V_66 ;
struct V_103 * V_34 = & V_66 -> V_34 ;
struct V_25 * V_26 = V_66 -> V_26 ;
const struct V_104 * V_90 = V_66 -> V_90 ;
unsigned int V_105 , V_106 ;
T_2 V_86 ;
T_3 V_107 , V_87 , V_108 = 0 ;
T_3 V_109 = ! ! ( V_20 -> V_40 & V_110 ) ;
F_33 ( L_19 , V_74 ) ;
V_105 = ( V_1 -> V_2 == V_14 ) ? V_111
: V_112 ;
V_107 = V_90 -> V_101 ( V_66 ) ;
if ( V_20 -> V_40 & V_113 ) {
int V_114 ;
V_1 -> V_115 = 0 ;
V_114 = V_66 -> V_116 -> V_117 ( V_1 ) ;
F_41 ( V_1 , V_34 ) ;
if ( V_114 || ( V_1 -> V_2 == V_18 && ( V_107 & V_118 ) ) ) {
if ( V_1 -> V_2 == V_14 )
F_4 (KERN_ERR PFX L_20 ,
drive->name, rq_data_dir(pc->rq)
? L_21 : L_22 ) ;
V_20 -> V_40 |= V_119 ;
} else
F_11 ( V_26 ) -> V_120 = 0 ;
F_33 ( L_23 , V_1 -> V_17 ) ;
}
if ( ( V_107 & V_121 ) == 0 ) {
int V_122 , error ;
F_33 ( L_24 ,
F_31 ( V_26 ) ) ;
V_20 -> V_40 &= ~ V_113 ;
F_42 () ;
if ( V_1 -> V_2 == V_18 &&
( V_107 & V_118 ) && F_11 ( V_26 ) -> V_34 [ 0 ] == V_46 )
V_107 &= ~ V_118 ;
if ( ( V_107 & V_118 ) || ( V_20 -> V_40 & V_119 ) ) {
F_33 ( L_25 , V_1 -> V_17 ) ;
if ( V_1 -> V_2 != V_18 )
V_20 -> V_26 -> V_123 ++ ;
if ( F_11 ( V_26 ) -> V_34 [ 0 ] == V_46 ) {
F_4 (KERN_ERR PFX L_26
L_27 , drive->name) ;
return F_43 ( V_1 ) ;
}
F_33 ( L_28 , V_26 -> V_34 [ 0 ] ) ;
F_26 ( V_1 ) ;
return V_124 ;
}
V_20 -> error = 0 ;
if ( ( V_20 -> V_40 & V_41 ) && ( V_107 & V_125 ) == 0 )
V_108 = 1 ;
V_106 = F_31 ( V_26 ) ;
V_122 = V_1 -> V_126 ( V_1 , V_108 ) ;
if ( V_122 == 0 )
V_1 -> V_127 = NULL ;
if ( F_44 ( V_26 ) ) {
V_26 -> V_123 = 0 ;
error = 0 ;
} else {
if ( F_45 ( V_26 ) && V_122 <= 0 ) {
if ( V_26 -> V_123 == 0 )
V_26 -> V_123 = - V_72 ;
}
error = V_122 ? 0 : - V_72 ;
}
F_30 ( V_1 , error , F_31 ( V_26 ) ) ;
return V_124 ;
}
if ( V_20 -> V_40 & V_113 ) {
V_20 -> V_40 &= ~ V_113 ;
F_4 (KERN_ERR PFX L_29
L_30 , drive->name) ;
F_46 ( V_1 ) ;
return F_43 ( V_1 ) ;
}
F_36 ( V_1 , & V_86 , & V_87 ) ;
if ( F_37 ( V_1 , V_26 , V_86 , V_87 , V_109 ) )
return F_43 ( V_1 ) ;
V_106 = F_47 (unsigned int, bcount, cmd->nleft) ;
F_48 ( V_1 , V_34 , V_109 , V_106 ) ;
F_11 ( V_26 ) -> V_120 -= V_106 ;
V_86 -= V_106 ;
if ( V_86 )
F_38 ( V_1 , V_109 , V_86 ) ;
F_33 ( L_31 ,
V_26 -> V_34 [ 0 ] , V_106 , V_86 , F_11 ( V_26 ) -> V_120 ) ;
F_49 ( V_1 , F_40 , V_105 ) ;
return V_128 ;
}
static void F_50 ( struct V_103 * V_34 , T_3 V_129 ,
T_2 V_86 , T_3 V_130 )
{
V_34 -> V_8 = V_130 ? V_131 : V_132 ;
V_34 -> V_133 . V_134 . V_89 = V_94 | V_93 |
V_135 | V_129 ;
V_34 -> V_89 . V_136 = V_137 ;
V_34 -> V_89 . V_138 = V_130 ;
V_34 -> V_89 . V_96 = V_86 & 0xff ;
V_34 -> V_89 . V_95 = ( V_86 >> 8 ) & 0xff ;
}
static T_3 F_51 ( T_1 * V_1 )
{
struct V_88 V_89 ;
V_1 -> V_66 -> V_90 -> V_91 ( V_1 , & V_89 , V_92 ) ;
return V_89 . V_97 & 3 ;
}
static T_3 F_52 ( T_1 * V_1 , T_3 V_87 )
{
int V_139 = 100 ;
while ( V_139 -- && ( ( V_87 & V_100 ) == 0 ||
( V_87 & V_140 ) ) ) {
F_4 (KERN_ERR PFX L_32
L_33 , drive->name) ;
F_53 ( 100 ) ;
V_87 = F_51 ( V_1 ) ;
if ( V_139 == 0 ) {
F_4 (KERN_ERR PFX L_34
L_35 ,
drive->name) ;
V_87 |= V_100 ;
V_87 &= ~ V_140 ;
}
}
return V_87 ;
}
static int F_54 ( T_1 * V_1 )
{
V_1 -> V_66 -> V_90 -> V_141 ( V_1 , NULL , V_1 -> V_20 -> V_35 , 12 ) ;
return V_111 ;
}
static T_5 F_55 ( T_1 * V_1 )
{
struct V_19 * V_142 ( V_20 ) ;
T_4 * V_66 = V_1 -> V_66 ;
struct V_25 * V_26 = V_66 -> V_26 ;
T_6 * V_143 ;
unsigned int V_105 ;
int V_54 ;
T_5 V_144 ;
T_3 V_87 ;
if ( F_56 ( & V_144 , V_1 , V_121 , V_145 , V_146 ) ) {
F_4 (KERN_ERR PFX L_36
L_37 , drive->name) ;
return V_144 ;
}
if ( V_1 -> V_70 & V_147 ) {
if ( V_1 -> V_130 )
V_1 -> V_115 = 1 ;
}
if ( F_1 ( V_1 ) ) {
V_54 = F_57 ( F_11 ( V_26 ) -> V_34 [ 0 ] ) ;
if ( V_54 < V_148 )
V_54 = V_148 ;
V_105 = V_26 -> V_105 ;
V_143 = F_32 ;
} else {
V_20 = V_1 -> V_20 ;
V_54 = V_148 ;
if ( V_1 -> V_70 & V_149 ) {
V_105 = V_1 -> V_150 ;
V_143 = & F_54 ;
} else {
V_105 = ( V_1 -> V_2 == V_14 ) ? V_111
: V_112 ;
V_143 = NULL ;
}
V_87 = F_51 ( V_1 ) ;
if ( V_1 -> V_2 == V_18 )
V_87 = F_52 ( V_1 , V_87 ) ;
if ( ( V_87 & V_100 ) == 0 || ( V_87 & V_140 ) ) {
F_4 (KERN_ERR PFX L_38
L_39 , drive->name) ;
return F_43 ( V_1 ) ;
}
}
V_66 -> V_143 = V_143 ;
F_49 ( V_1 ,
( F_1 ( V_1 ) ? V_1 -> V_151
: F_40 ) ,
V_105 ) ;
if ( ( V_1 -> V_70 & V_149 ) == 0 )
V_66 -> V_90 -> V_141 ( V_1 , NULL , F_11 ( V_26 ) -> V_34 , V_54 ) ;
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_130 )
V_66 -> V_116 -> V_152 ( V_1 ) ;
} else {
if ( V_20 -> V_40 & V_153 ) {
V_20 -> V_40 |= V_113 ;
V_66 -> V_116 -> V_152 ( V_1 ) ;
}
}
return V_128 ;
}
T_5 F_58 ( T_1 * V_1 , struct V_103 * V_34 )
{
struct V_19 * V_20 ;
T_4 * V_66 = V_1 -> V_66 ;
T_6 * V_143 = NULL ;
struct V_25 * V_26 = V_66 -> V_26 ;
unsigned int V_105 , V_154 ;
T_2 V_86 ;
T_3 V_129 ;
T_3 V_155 = ! ! ( V_1 -> V_70 & V_147 ) ;
if ( F_1 ( V_1 ) ) {
V_129 = V_92 | V_156 ;
V_86 = F_34 ( V_26 ) ;
V_143 = F_32 ;
V_105 = V_80 ;
if ( V_1 -> V_130 )
V_1 -> V_130 = ! F_59 ( V_1 , V_34 ) ;
} else {
V_20 = V_1 -> V_20 ;
V_129 = V_157 ;
V_154 = F_31 ( V_26 ) ;
V_86 = ( ( V_1 -> V_2 == V_18 ) ? V_154
: F_47 (unsigned int,
bytes, 63 * 1024 ) ) ;
F_11 ( V_26 ) -> V_120 = V_86 ;
if ( V_20 -> V_40 & V_119 ) {
V_20 -> V_40 &= ~ V_119 ;
F_46 ( V_1 ) ;
}
if ( V_20 -> V_40 & V_153 )
V_1 -> V_130 = ! F_59 ( V_1 , V_34 ) ;
if ( ! V_1 -> V_130 )
V_20 -> V_40 &= ~ V_153 ;
V_105 = ( V_1 -> V_2 == V_14 ) ? V_111
: V_112 ;
}
F_50 ( V_34 , V_129 , V_86 , V_1 -> V_130 ) ;
( void ) F_60 ( V_1 , V_34 ) ;
if ( V_155 ) {
if ( V_1 -> V_130 )
V_1 -> V_115 = 0 ;
V_66 -> V_143 = V_143 ;
}
F_61 ( V_1 , V_34 , F_55 , V_105 ) ;
return V_155 ? V_128 : F_55 ( V_1 ) ;
}
