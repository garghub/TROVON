void *
F_1 ( int V_1 )
{
T_1 * V_2 ;
V_2 = F_2 ( V_1 ) ;
return V_2 ? V_2 -> V_3 : NULL ;
}
char *
F_3 ( T_2 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_1 ( V_6 -> V_1 ) ;
return V_8 -> V_9 ;
}
void
F_4 ( T_1 * V_2 )
{
T_3 * V_10 = V_2 -> V_11 ;
#ifdef F_5
F_6 ( L_1 ,
V_12 , V_10 -> V_13 , V_2 -> V_1 , V_2 ) ;
#endif
F_7 ( V_10 -> V_14 , & V_2 -> V_15 ) ;
}
T_4
F_8 ( T_3 * V_10 , T_1 * V_2 )
{
F_9 ( & V_2 -> V_15 , ( void * ) V_16 ) ;
return 0 ;
}
T_4
F_10 ( T_3 * V_10 )
{
char V_9 [ 16 ] ;
if ( V_10 -> V_14 )
return 0 ;
snprintf ( V_9 , sizeof( V_9 ) , L_2 , V_10 -> V_11 -> V_17 , V_10 -> V_13 ) ;
#ifdef F_5
F_6 ( L_3 ,
V_12 , V_9 , V_10 -> V_13 ) ;
#endif
V_10 -> V_14 = F_11 ( V_9 ) ;
if ( ! V_10 -> V_14 )
return - V_18 ;
return 0 ;
}
void
F_12 ( T_3 * V_10 )
{
if ( V_10 -> V_14 ) {
F_13 ( V_10 -> V_14 ) ;
V_10 -> V_14 = NULL ;
}
}
static T_5
F_14 ( int V_19 , void * V_20 )
{
struct V_7 * V_21 = V_20 ;
return F_15 ( F_16 ( V_21 ) ) ;
}
static T_5
F_17 ( int V_19 , void * V_20 )
{
struct V_7 * V_21 = V_20 ;
return F_18 ( F_16 ( V_21 ) ) ;
}
static int
F_19 ( struct V_7 * V_21 )
{
F_6 ( L_4 , V_21 -> V_9 ) ;
return - 1 ;
}
static int
F_20 ( struct V_7 * V_21 )
{
T_2 * V_4 = F_21 ( V_21 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_22 ;
V_22 = F_22 ( V_21 ) ;
if ( V_22 ) {
F_6 ( L_5 , V_22 ) ;
return V_22 ;
}
V_22 = F_23 ( V_6 -> V_23 , V_6 -> V_1 ) ;
if ( V_22 < 0 )
return V_22 ;
F_24 ( V_24 ) ;
F_25 ( V_21 ) ;
return 0 ;
}
static int
F_26 ( struct V_7 * V_21 )
{
T_2 * V_4 = F_21 ( V_21 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
F_27 ( V_21 ) ;
F_28 ( ( V_25 * ) 0 , V_6 -> V_1 ) ;
F_29 ( V_21 ) ;
F_30 ( V_24 ) ;
return 0 ;
}
static int
F_31 ( struct V_7 * V_8 , struct V_26 * V_27 , int V_28 )
{
return F_32 ( V_8 , V_27 , V_28 ) ;
}
static int
F_33 ( struct V_7 * V_21 , unsigned short V_29 ,
unsigned short V_30 )
{
return 0 ;
}
static struct V_31 *
F_34 ( struct V_7 * V_21 )
{
T_1 * V_2 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_1 ;
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) F_21 ( V_21 ) -> V_6 ;
V_1 = V_6 -> V_1 ;
}
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL )
return NULL ;
V_32 = & V_21 -> V_34 ;
V_34 = & V_2 -> V_35 ;
memset ( V_32 , 0 , sizeof( struct V_31 ) ) ;
V_32 -> V_36 = V_34 -> V_36 ;
V_32 -> V_37 = V_34 -> V_37 ;
V_32 -> V_38 = V_34 -> V_38 ;
V_32 -> V_39 = V_34 -> V_39 ;
V_32 -> V_40 = V_34 -> V_41 +
V_34 -> V_42 +
V_34 -> V_43 +
V_34 -> V_44 +
V_34 -> V_45 +
V_34 -> V_46 ;
V_32 -> V_47 = V_34 -> V_48 +
V_34 -> V_49 +
V_34 -> V_50 ;
V_32 -> V_51 = V_34 -> V_51 ;
V_32 -> V_48 = V_34 -> V_48 ;
V_32 -> V_41 = V_34 -> V_41 ;
V_32 -> V_42 = V_34 -> V_42 ;
V_32 -> V_43 = V_34 -> V_43 ;
V_32 -> V_44 = V_34 -> V_44 ;
V_32 -> V_45 = V_34 -> V_45 ;
V_32 -> V_46 = V_34 -> V_46 ;
V_32 -> V_49 = V_34 -> V_49 ;
V_32 -> V_50 = V_34 -> V_50 ;
return V_32 ;
}
static V_25 *
F_35 ( struct V_7 * V_21 )
{
return ( V_25 * ) ( F_16 ( V_21 ) ) ;
}
static int
F_36 ( struct V_52 * V_53 , struct V_7 * V_21 )
{
const struct V_5 * V_6 ;
int V_54 ;
T_2 * V_4 = F_21 ( V_21 ) ;
V_6 = V_4 -> V_6 ;
V_54 = F_37 ( V_6 -> V_23 , V_6 -> V_1 , V_53 ) ;
return V_54 ;
}
static struct V_7 *
F_38 ( struct V_7 * V_21 , V_25 * V_23 ,
struct V_55 * V_56 )
{
T_2 * V_4 ;
struct V_7 * V_8 ;
T_6 * V_57 ;
int V_22 ;
if ( F_2 ( V_56 -> V_1 ) )
return NULL ;
{
struct V_5 * V_6 ;
V_6 = F_39 ( sizeof( struct V_5 ) ) ;
if ( ! V_6 ) {
F_40 ( L_6 ,
V_23 -> V_17 ) ;
return NULL ;
}
V_8 = F_41 ( V_6 ) ;
if ( ! V_8 ) {
F_40 ( L_7 ,
V_23 -> V_17 ) ;
F_42 ( V_6 ) ;
return NULL ;
}
V_6 -> V_23 = V_23 ;
V_6 -> V_1 = V_56 -> V_1 ;
}
V_4 = F_21 ( V_8 ) ;
V_8 -> V_58 = 0 ;
V_8 -> V_19 = V_21 -> V_19 ;
V_8 -> type = V_59 ;
* V_8 -> V_9 = 0 ;
V_57 = ( T_6 * ) V_23 -> V_60 ;
if ( V_57 -> V_61 == V_62 ) {
switch ( V_57 -> V_63 ) {
case V_64 :
memcpy ( V_8 -> V_65 ,
( V_66 * ) ( V_57 -> V_67 . V_68 . V_69 ) , 6 ) ;
break;
case V_70 :
memcpy ( V_8 -> V_65 ,
( V_71 * ) ( V_57 -> V_67 . V_72 . V_69 ) , 6 ) ;
break;
default:
memset ( V_8 -> V_65 , 0 , 6 ) ;
break;
}
} else
memset ( V_8 -> V_65 , 0 , 6 ) ;
V_4 -> V_73 = F_36 ;
V_8 -> V_74 = & V_75 ;
V_4 -> V_76 = F_33 ;
F_43 () ;
V_22 = F_44 ( V_8 ) ;
V_8 -> V_77 = V_78 ;
F_45 () ;
if ( V_22 ) {
if ( V_79 >= V_80 )
F_6 ( L_8 ,
V_23 -> V_17 , V_56 -> V_1 , V_22 ) ;
F_46 ( V_8 ) ;
return NULL ;
}
return V_8 ;
}
static T_4
F_47 ( struct V_7 * V_21 , void * V_81 )
{
int V_22 ;
V_25 * V_23 ;
struct V_82 V_83 ;
if ( F_48 ( & V_83 , V_81 , sizeof( struct V_82 ) ) )
return - V_84 ;
if ( V_83 . V_13 >= V_85 )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
V_22 = F_49 ( V_23 , V_83 . V_13 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_81 , & V_23 -> V_87 [ V_83 . V_13 ] . V_88 ,
sizeof( struct V_82 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_51 ( struct V_7 * V_21 , void * V_81 )
{
V_25 * V_23 ;
struct V_82 V_83 ;
if ( F_48 ( & V_83 , V_81 , sizeof( struct V_82 ) ) )
return - V_84 ;
if ( V_83 . V_13 >= V_85 )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
if ( V_83 . V_13 >= V_23 -> V_89 )
return - V_90 ;
memcpy ( & V_23 -> V_87 [ V_83 . V_13 ] . V_88 , & V_83 , sizeof( struct V_82 ) ) ;
return F_52 ( V_23 , V_83 . V_13 ) ;
}
static T_4
F_53 ( struct V_7 * V_21 , void * V_81 )
{
struct V_82 V_83 ;
V_25 * V_23 ;
if ( F_48 ( & V_83 , V_81 , sizeof( struct V_82 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
return F_54 ( V_23 , V_83 . V_13 , V_83 . V_91 ) ;
}
static T_4
F_55 ( struct V_7 * V_21 , void * V_81 )
{
struct V_82 V_83 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_83 , V_81 , sizeof( struct V_82 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
V_22 = F_56 ( V_23 , & V_83 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_81 , & V_83 , sizeof( struct V_82 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_57 ( struct V_7 * V_21 , void * V_81 )
{
struct V_82 V_83 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_83 , V_81 , sizeof( struct V_82 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
V_22 = F_58 ( V_23 , & V_83 ) ;
if ( V_22 )
return V_22 ;
if ( F_50 ( V_81 , & V_83 , sizeof( struct V_82 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_59 ( struct V_7 * V_21 , void * V_81 )
{
struct V_92 V_93 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_93 , V_81 , sizeof( struct V_92 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
V_22 = F_60 ( V_23 , & V_93 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_81 , & V_93 , sizeof( struct V_92 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_61 ( struct V_7 * V_21 , void * V_81 )
{
struct V_55 V_56 ;
int V_22 ;
if ( F_48 ( & V_56 , V_81 ,
sizeof( struct V_55 ) ) )
return - V_84 ;
V_22 = F_62 ( V_56 . V_1 , & V_56 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_81 , & V_56 , sizeof( struct V_55 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_63 ( struct V_7 * V_21 , void * V_81 )
{
struct V_55 V_56 ;
V_25 * V_23 ;
if ( F_48 ( & V_56 , V_81 , sizeof( struct V_55 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
return F_64 ( V_56 . V_1 , & V_56 ) ;
}
static T_4
F_65 ( struct V_7 * V_21 , void * V_81 )
{
V_25 * V_23 ;
struct V_7 * V_8 ;
struct V_55 V_56 ;
int V_22 ;
if ( F_48 ( & V_56 , V_81 , sizeof( struct V_55 ) ) )
return - V_84 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
V_8 = F_38 ( V_21 , V_23 , & V_56 ) ;
if ( ! V_8 )
return - V_94 ;
V_22 = F_66 ( V_23 , V_56 . V_87 , V_56 . V_1 , V_8 ) ;
if ( V_22 < 0 ) {
F_43 () ;
F_67 ( V_8 ) ;
F_45 () ;
F_46 ( V_8 ) ;
}
return V_22 ;
}
static T_4
F_68 ( struct V_7 * V_21 , void * V_81 )
{
struct V_95 V_96 ;
int V_22 ;
if ( F_48 ( & V_96 , V_81 ,
sizeof( struct V_95 ) ) )
return - V_84 ;
V_22 = F_69 ( V_96 . V_1 , & V_96 . V_34 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_81 , & V_96 ,
sizeof( struct V_95 ) ) )
return - V_84 ;
return 0 ;
}
static T_4
F_70 ( struct V_7 * V_21 , void * V_81 )
{
unsigned int V_79 ;
if ( F_48 ( & V_79 , V_81 , sizeof( int ) ) )
return - V_84 ;
F_71 ( V_79 ) ;
return 0 ;
}
static T_4
F_72 ( struct V_7 * V_21 , int V_97 )
{
if ( V_21 -> V_98 & V_99 )
return - V_94 ;
{
V_25 * V_23 ;
T_1 * V_2 ;
const struct V_5 * V_6 ;
int V_1 ;
V_6 = (struct V_5 * ) F_21 ( V_21 ) -> V_6 ;
V_23 = V_6 -> V_23 ;
V_1 = V_6 -> V_1 ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL )
return - V_100 ;
V_2 -> V_3 = NULL ;
}
if ( V_97 )
F_43 () ;
F_67 ( V_21 ) ;
if ( V_97 )
F_45 () ;
F_46 ( V_21 ) ;
return 0 ;
}
int
F_73 ( struct V_7 * V_101 , void * V_81 )
{
struct V_55 V_56 ;
char V_102 [ sizeof( V_103 ) + 3 ] ;
struct V_7 * V_8 ;
int V_22 ;
if ( F_48 ( & V_56 , V_81 ,
sizeof( struct V_55 ) ) )
return - V_84 ;
if ( V_56 . V_1 > 999 )
return - V_86 ;
snprintf ( V_102 , sizeof( V_102 ) , V_103 L_9 , V_56 . V_1 ) ;
V_8 = F_74 ( & V_104 , V_102 ) ;
if ( ! V_8 )
return - V_105 ;
V_22 = F_72 ( V_8 , 1 ) ;
if ( V_22 )
return V_22 ;
return F_75 ( V_56 . V_1 ) ;
}
int
F_76 ( struct V_7 * V_101 , void * V_81 )
{
const struct V_5 * V_6 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < 128 ; V_106 ++ ) {
struct V_7 * V_21 ;
char V_102 [ sizeof( V_103 ) + 3 ] ;
sprintf ( V_102 , V_103 L_9 , V_106 ) ;
V_21 = F_74 ( & V_104 , V_102 ) ;
if ( ! V_21 )
continue;
V_6 = F_21 ( V_21 ) -> V_6 ;
if ( ( unsigned long ) ( V_6 -> V_23 ) ==
( unsigned long ) ( F_16 ( V_101 ) ) ) {
V_21 -> V_98 &= ~ V_99 ;
F_27 ( V_21 ) ;
F_72 ( V_21 , 1 ) ;
}
}
return 0 ;
}
int
F_77 ( struct V_7 * V_101 , void * V_81 )
{
struct V_55 V_56 ;
if ( F_48 ( & V_56 , V_81 ,
sizeof( struct V_55 ) ) )
return - V_84 ;
return F_78 ( V_56 . V_1 ) ;
}
static T_4
F_79 ( struct V_7 * V_21 , struct V_26 * V_27 , int V_28 )
{
V_25 * V_23 ;
void * V_81 ;
int V_107 , V_108 ;
T_4 V_22 ;
static struct V_81 {
union {
T_7 V_109 ;
T_8 V_106 ;
struct V_110 V_111 ;
struct V_112 V_113 ;
struct V_114 V_115 ;
struct V_116 V_117 ;
struct V_33 V_34 ;
struct V_55 V_118 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 V_124 ;
} V_125 ;
} V_126 ;
if ( ! F_80 ( V_127 ) )
return - V_128 ;
if ( V_28 != V_129 + 15 )
return - V_86 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_86 ;
if ( V_23 -> V_130 != V_131 )
return - V_105 ;
if ( F_48 ( & V_107 , V_27 -> V_132 , sizeof( V_107 ) ) )
return - V_84 ;
#if 0
if (copy_from_user(&len, ifr->ifr_data + sizeof(iocmd), sizeof(len)))
return -EFAULT;
#endif
#if 0
pr_info("c4_ioctl: iocmd %x, dir %x type %x nr %x iolen %d.\n", iocmd,
_IOC_DIR(iocmd), _IOC_TYPE(iocmd), _IOC_NR(iocmd),
_IOC_SIZE(iocmd));
#endif
V_108 = F_81 ( V_107 ) ;
if ( V_108 > sizeof( V_126 ) )
return - V_84 ;
V_81 = V_27 -> V_132 + sizeof( V_107 ) ;
if ( F_48 ( & V_126 , V_81 , V_108 ) )
return - V_84 ;
V_22 = 0 ;
switch ( V_107 ) {
case V_133 :
V_22 = F_47 ( V_21 , V_81 ) ;
break;
case V_134 :
V_22 = F_51 ( V_21 , V_81 ) ;
break;
case V_135 :
V_22 = F_61 ( V_21 , V_81 ) ;
break;
case V_136 :
V_22 = F_63 ( V_21 , V_81 ) ;
break;
case V_137 :
V_22 = F_73 ( V_21 , V_81 ) ;
break;
case V_138 :
V_22 = F_65 ( V_21 , V_81 ) ;
break;
case V_139 :
V_22 = F_68 ( V_21 , V_81 ) ;
break;
case V_140 :
V_22 = F_70 ( V_21 , V_81 ) ;
break;
case V_141 :
V_22 = F_76 ( V_21 , V_81 ) ;
break;
case V_142 :
V_22 = F_77 ( V_21 , V_81 ) ;
break;
case V_143 :
V_22 = F_53 ( V_21 , V_81 ) ;
break;
case V_144 :
V_22 = F_55 ( V_21 , V_81 ) ;
break;
case V_145 :
V_22 = F_59 ( V_21 , V_81 ) ;
break;
case V_146 :
V_22 = F_57 ( V_21 , V_81 ) ;
break;
case V_147 :
V_22 = ( V_108 == sizeof( struct V_114 ) ) ?
F_82 ( V_23 , & V_126 . V_125 . V_115 ) : - V_84 ;
if ( V_22 == 0 )
if ( F_50 ( V_81 , & V_126 , V_108 ) )
return - V_84 ;
break;
default:
V_22 = - V_86 ;
break;
}
return V_22 ;
}
static void F_83 ( struct V_7 * V_8 )
{
V_8 -> type = V_148 ;
V_8 -> V_74 = & V_149 ;
}
struct V_7 * T_9
F_84 ( T_6 * V_57 , int V_150 , unsigned long V_151 , unsigned long V_152 ,
int V_153 , int V_154 )
{
struct V_7 * V_21 ;
V_25 * V_23 ;
V_21 = F_85 ( sizeof( V_25 ) , V_155 , F_83 ) ;
if ( ! V_21 ) {
F_40 ( L_10 ,
V_57 -> V_17 ) ;
V_156 = - V_18 ;
return NULL ;
}
V_23 = ( V_25 * ) ( F_16 ( V_21 ) ) ;
V_21 -> V_19 = V_153 ;
V_23 -> V_60 = V_57 ;
V_23 -> V_130 = V_157 ;
V_23 -> V_158 = V_159 ;
V_159 = V_23 ;
V_23 -> V_150 = V_23 -> V_158 ? V_23 -> V_158 -> V_150 + 1 : 0 ;
if ( ! V_160 )
V_160 = V_23 ;
strcpy ( V_23 -> V_17 , V_57 -> V_17 ) ;
#if F_86 ( V_161 )
F_87 ( & V_23 -> V_162 ,
( void (*) ( unsigned long ) ) V_163 ,
( unsigned long ) V_23 ) ;
if ( F_88 ( & V_23 -> V_162 . V_164 ) == 0 )
F_89 ( & V_23 -> V_162 ) ;
#elif F_86 ( V_165 )
V_23 -> V_166 . V_167 = ( void * ) ( unsigned long ) V_163 ;
V_23 -> V_166 . V_81 = V_23 ;
#endif
if ( F_90 ( V_21 ) ||
( F_91 ( V_23 , ( V_168 * ) V_151 , ( V_168 * ) V_152 ) != V_169 ) ) {
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_156 = - V_105 ;
return NULL ;
}
if ( F_92 ( V_153 , & F_14 ,
V_170 ,
V_21 -> V_9 , V_21 ) ) {
F_40 ( L_11 ,
V_21 -> V_9 , V_153 ) ;
F_93 ( V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_156 = - V_171 ;
return NULL ;
}
#ifdef F_94
if ( F_92 ( V_154 , & F_17 , V_170 , V_21 -> V_9 , V_21 ) ) {
F_40 ( L_12 , V_57 -> V_17 , V_154 ) ;
F_93 ( V_21 ) ;
F_95 ( V_153 , V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_156 = - V_171 ;
return NULL ;
}
#endif
{
T_8 V_172 ;
F_96 ( V_57 , V_150 ) ;
switch ( V_57 -> V_63 ) {
case V_64 :
memcpy ( V_21 -> V_65 ,
( V_66 * ) ( V_57 -> V_67 . V_68 . V_69 ) , 6 ) ;
memcpy ( & V_172 , ( V_66 * ) ( V_57 -> V_67 . V_68 . V_173 ) , 4 ) ;
V_23 -> V_174 = F_97 ( V_172 ) ;
break;
case V_70 :
memcpy ( V_21 -> V_65 ,
( V_71 * ) ( V_57 -> V_67 . V_72 . V_69 ) , 6 ) ;
memcpy ( & V_172 , ( V_71 * ) ( V_57 -> V_67 . V_72 . V_173 ) , 4 ) ;
V_23 -> V_174 = F_97 ( V_172 ) ;
break;
default:
V_23 -> V_174 = 0 ;
memset ( V_21 -> V_65 , 0 , 6 ) ;
break;
}
#if 1
F_98 ( V_23 ) ;
#else
F_99 ( V_23 ) ;
#endif
}
#ifdef F_100
F_101 ( V_23 ) ;
#endif
#if F_86 ( V_161 )
F_102 ( & V_23 -> V_162 ) ;
#endif
V_156 = F_103 ( V_23 ) ;
if ( V_156 != V_169 ) {
#ifdef F_100
F_104 ( V_23 ) ;
#endif
F_93 ( V_21 ) ;
F_95 ( V_154 , V_21 ) ;
F_95 ( V_153 , V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
static int T_9
F_105 ( void )
{
int V_175 ;
V_175 = F_106 () ;
if ( V_175 )
return - V_175 ;
if ( V_79 != V_176 )
F_6 ( L_13 ,
V_176 , V_79 ) ;
if ( V_177 != V_178 )
F_6 ( L_14 ,
V_178 , V_177 ) ;
if ( V_179 != V_180 )
F_6 ( L_15 ,
V_180 , V_179 ) ;
if ( V_181 != V_182 ) {
if ( V_181 > 2000 )
V_181 = 2000 ;
F_6 ( L_16 ,
V_182 , V_181 ) ;
}
if ( V_183 != V_184 ) {
if ( V_183 > 1000 )
V_183 = 1000 ;
F_6 ( L_17 ,
V_184 , V_183 ) ;
}
return 0 ;
}
static void T_10
F_107 ( void )
{
T_6 * V_57 ;
V_25 * V_23 ;
struct V_7 * V_21 ;
int V_106 , V_185 , V_186 ;
for ( V_106 = 0 , V_57 = V_60 ; V_106 < V_187 ; V_106 ++ , V_57 ++ ) {
if ( V_57 -> V_21 ) {
V_23 = ( V_25 * ) ( F_16 ( V_57 -> V_21 ) ) ;
for ( V_185 = 0 ; V_185 < V_23 -> V_89 ; V_185 ++ )
for ( V_186 = 0 ; V_186 < V_188 ; V_186 ++ ) {
V_21 = V_23 -> V_87 [ V_185 ] . V_189 [ V_186 ] -> V_3 ;
if ( V_21 )
F_72 ( V_21 , 0 ) ;
}
}
}
}
static void T_10
F_108 ( void )
{
F_107 () ;
F_109 () ;
F_110 () ;
F_111 () ;
F_6 ( L_18 ) ;
}
