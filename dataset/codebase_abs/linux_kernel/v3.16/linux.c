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
V_6 = F_39 ( sizeof( struct V_5 ) , V_58 ) ;
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
V_8 -> V_59 = 0 ;
V_8 -> V_19 = V_21 -> V_19 ;
V_8 -> type = V_60 ;
* V_8 -> V_9 = 0 ;
V_57 = ( T_6 * ) V_23 -> V_61 ;
if ( V_57 -> V_62 == V_63 ) {
switch ( V_57 -> V_64 ) {
case V_65 :
memcpy ( V_8 -> V_66 ,
( V_67 * ) ( V_57 -> V_68 . V_69 . V_70 ) , 6 ) ;
break;
case V_71 :
memcpy ( V_8 -> V_66 ,
( V_72 * ) ( V_57 -> V_68 . V_73 . V_70 ) , 6 ) ;
break;
default:
memset ( V_8 -> V_66 , 0 , 6 ) ;
break;
}
} else
memset ( V_8 -> V_66 , 0 , 6 ) ;
V_4 -> V_74 = F_36 ;
V_8 -> V_75 = & V_76 ;
V_4 -> V_77 = F_33 ;
F_43 () ;
V_22 = F_44 ( V_8 ) ;
V_8 -> V_78 = V_79 ;
F_45 () ;
if ( V_22 ) {
if ( V_80 >= V_81 )
F_6 ( L_8 ,
V_23 -> V_17 , V_56 -> V_1 , V_22 ) ;
F_46 ( V_8 ) ;
return NULL ;
}
return V_8 ;
}
static T_4
F_47 ( struct V_7 * V_21 , void * V_82 )
{
int V_22 ;
V_25 * V_23 ;
struct V_83 V_84 ;
if ( F_48 ( & V_84 , V_82 , sizeof( struct V_83 ) ) )
return - V_85 ;
if ( V_84 . V_13 >= V_86 )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
V_22 = F_49 ( V_23 , V_84 . V_13 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_82 , & V_23 -> V_88 [ V_84 . V_13 ] . V_89 ,
sizeof( struct V_83 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_51 ( struct V_7 * V_21 , void * V_82 )
{
V_25 * V_23 ;
struct V_83 V_84 ;
if ( F_48 ( & V_84 , V_82 , sizeof( struct V_83 ) ) )
return - V_85 ;
if ( V_84 . V_13 >= V_86 )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
if ( V_84 . V_13 >= V_23 -> V_90 )
return - V_91 ;
memcpy ( & V_23 -> V_88 [ V_84 . V_13 ] . V_89 , & V_84 , sizeof( struct V_83 ) ) ;
return F_52 ( V_23 , V_84 . V_13 ) ;
}
static T_4
F_53 ( struct V_7 * V_21 , void * V_82 )
{
struct V_83 V_84 ;
V_25 * V_23 ;
if ( F_48 ( & V_84 , V_82 , sizeof( struct V_83 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
return F_54 ( V_23 , V_84 . V_13 , V_84 . V_92 ) ;
}
static T_4
F_55 ( struct V_7 * V_21 , void * V_82 )
{
struct V_83 V_84 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_84 , V_82 , sizeof( struct V_83 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
V_22 = F_56 ( V_23 , & V_84 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_82 , & V_84 , sizeof( struct V_83 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_57 ( struct V_7 * V_21 , void * V_82 )
{
struct V_83 V_84 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_84 , V_82 , sizeof( struct V_83 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
V_22 = F_58 ( V_23 , & V_84 ) ;
if ( V_22 )
return V_22 ;
if ( F_50 ( V_82 , & V_84 , sizeof( struct V_83 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_59 ( struct V_7 * V_21 , void * V_82 )
{
struct V_93 V_94 ;
V_25 * V_23 ;
int V_22 ;
if ( F_48 ( & V_94 , V_82 , sizeof( struct V_93 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
V_22 = F_60 ( V_23 , & V_94 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_82 , & V_94 , sizeof( struct V_93 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_61 ( struct V_7 * V_21 , void * V_82 )
{
struct V_55 V_56 ;
int V_22 ;
if ( F_48 ( & V_56 , V_82 ,
sizeof( struct V_55 ) ) )
return - V_85 ;
V_22 = F_62 ( V_56 . V_1 , & V_56 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_82 , & V_56 , sizeof( struct V_55 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_63 ( struct V_7 * V_21 , void * V_82 )
{
struct V_55 V_56 ;
V_25 * V_23 ;
if ( F_48 ( & V_56 , V_82 , sizeof( struct V_55 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
return F_64 ( V_56 . V_1 , & V_56 ) ;
}
static T_4
F_65 ( struct V_7 * V_21 , void * V_82 )
{
V_25 * V_23 ;
struct V_7 * V_8 ;
struct V_55 V_56 ;
int V_22 ;
if ( F_48 ( & V_56 , V_82 , sizeof( struct V_55 ) ) )
return - V_85 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
V_8 = F_38 ( V_21 , V_23 , & V_56 ) ;
if ( ! V_8 )
return - V_95 ;
V_22 = F_66 ( V_23 , V_56 . V_88 , V_56 . V_1 , V_8 ) ;
if ( V_22 < 0 ) {
F_43 () ;
F_67 ( V_8 ) ;
F_45 () ;
F_46 ( V_8 ) ;
}
return V_22 ;
}
static T_4
F_68 ( struct V_7 * V_21 , void * V_82 )
{
struct V_96 V_97 ;
int V_22 ;
if ( F_48 ( & V_97 , V_82 ,
sizeof( struct V_96 ) ) )
return - V_85 ;
V_22 = F_69 ( V_97 . V_1 , & V_97 . V_34 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_50 ( V_82 , & V_97 ,
sizeof( struct V_96 ) ) )
return - V_85 ;
return 0 ;
}
static T_4
F_70 ( struct V_7 * V_21 , void * V_82 )
{
unsigned int V_80 ;
if ( F_48 ( & V_80 , V_82 , sizeof( int ) ) )
return - V_85 ;
F_71 ( V_80 ) ;
return 0 ;
}
static T_4
F_72 ( struct V_7 * V_21 , int V_98 )
{
if ( V_21 -> V_99 & V_100 )
return - V_95 ;
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
return - V_101 ;
V_2 -> V_3 = NULL ;
}
if ( V_98 )
F_43 () ;
F_67 ( V_21 ) ;
if ( V_98 )
F_45 () ;
F_46 ( V_21 ) ;
return 0 ;
}
int
F_73 ( struct V_7 * V_102 , void * V_82 )
{
struct V_55 V_56 ;
char V_103 [ sizeof( V_104 ) + 3 ] ;
struct V_7 * V_8 ;
int V_22 ;
if ( F_48 ( & V_56 , V_82 ,
sizeof( struct V_55 ) ) )
return - V_85 ;
if ( V_56 . V_1 > 999 )
return - V_87 ;
snprintf ( V_103 , sizeof( V_103 ) , V_104 L_9 , V_56 . V_1 ) ;
V_8 = F_74 ( & V_105 , V_103 ) ;
if ( ! V_8 )
return - V_106 ;
V_22 = F_72 ( V_8 , 1 ) ;
if ( V_22 )
return V_22 ;
return F_75 ( V_56 . V_1 ) ;
}
int
F_76 ( struct V_7 * V_102 , void * V_82 )
{
const struct V_5 * V_6 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < 128 ; V_107 ++ ) {
struct V_7 * V_21 ;
char V_103 [ sizeof( V_104 ) + 3 ] ;
sprintf ( V_103 , V_104 L_9 , V_107 ) ;
V_21 = F_74 ( & V_105 , V_103 ) ;
if ( ! V_21 )
continue;
V_6 = F_21 ( V_21 ) -> V_6 ;
if ( ( unsigned long ) ( V_6 -> V_23 ) ==
( unsigned long ) ( F_16 ( V_102 ) ) ) {
V_21 -> V_99 &= ~ V_100 ;
F_27 ( V_21 ) ;
F_72 ( V_21 , 1 ) ;
}
}
return 0 ;
}
int
F_77 ( struct V_7 * V_102 , void * V_82 )
{
struct V_55 V_56 ;
if ( F_48 ( & V_56 , V_82 ,
sizeof( struct V_55 ) ) )
return - V_85 ;
return F_78 ( V_56 . V_1 ) ;
}
static T_4
F_79 ( struct V_7 * V_21 , struct V_26 * V_27 , int V_28 )
{
V_25 * V_23 ;
void * V_82 ;
int V_108 , V_109 ;
T_4 V_22 ;
static struct V_82 {
union {
T_7 V_110 ;
T_8 V_107 ;
struct V_111 V_112 ;
struct V_113 V_114 ;
struct V_115 V_116 ;
struct V_117 V_118 ;
struct V_33 V_34 ;
struct V_55 V_119 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
} V_126 ;
} V_127 ;
if ( ! F_80 ( V_128 ) )
return - V_129 ;
if ( V_28 != V_130 + 15 )
return - V_87 ;
V_23 = F_35 ( V_21 ) ;
if ( ! V_23 )
return - V_87 ;
if ( V_23 -> V_131 != V_132 )
return - V_106 ;
if ( F_48 ( & V_108 , V_27 -> V_133 , sizeof( V_108 ) ) )
return - V_85 ;
#if 0
if (copy_from_user(&len, ifr->ifr_data + sizeof(iocmd), sizeof(len)))
return -EFAULT;
#endif
#if 0
pr_info("c4_ioctl: iocmd %x, dir %x type %x nr %x iolen %d.\n", iocmd,
_IOC_DIR(iocmd), _IOC_TYPE(iocmd), _IOC_NR(iocmd),
_IOC_SIZE(iocmd));
#endif
V_109 = F_81 ( V_108 ) ;
if ( V_109 > sizeof( V_127 ) )
return - V_85 ;
V_82 = V_27 -> V_133 + sizeof( V_108 ) ;
if ( F_48 ( & V_127 , V_82 , V_109 ) )
return - V_85 ;
V_22 = 0 ;
switch ( V_108 ) {
case V_134 :
V_22 = F_47 ( V_21 , V_82 ) ;
break;
case V_135 :
V_22 = F_51 ( V_21 , V_82 ) ;
break;
case V_136 :
V_22 = F_61 ( V_21 , V_82 ) ;
break;
case V_137 :
V_22 = F_63 ( V_21 , V_82 ) ;
break;
case V_138 :
V_22 = F_73 ( V_21 , V_82 ) ;
break;
case V_139 :
V_22 = F_65 ( V_21 , V_82 ) ;
break;
case V_140 :
V_22 = F_68 ( V_21 , V_82 ) ;
break;
case V_141 :
V_22 = F_70 ( V_21 , V_82 ) ;
break;
case V_142 :
V_22 = F_76 ( V_21 , V_82 ) ;
break;
case V_143 :
V_22 = F_77 ( V_21 , V_82 ) ;
break;
case V_144 :
V_22 = F_53 ( V_21 , V_82 ) ;
break;
case V_145 :
V_22 = F_55 ( V_21 , V_82 ) ;
break;
case V_146 :
V_22 = F_59 ( V_21 , V_82 ) ;
break;
case V_147 :
V_22 = F_57 ( V_21 , V_82 ) ;
break;
case V_148 :
V_22 = ( V_109 == sizeof( struct V_115 ) ) ?
F_82 ( V_23 , & V_127 . V_126 . V_116 ) : - V_85 ;
if ( V_22 == 0 )
if ( F_50 ( V_82 , & V_127 , V_109 ) )
return - V_85 ;
break;
default:
V_22 = - V_87 ;
break;
}
return V_22 ;
}
static void F_83 ( struct V_7 * V_8 )
{
V_8 -> type = V_149 ;
V_8 -> V_75 = & V_150 ;
}
struct V_7 * T_9
F_84 ( T_6 * V_57 , int V_151 , unsigned long V_152 , unsigned long V_153 ,
int V_154 , int V_155 )
{
struct V_7 * V_21 ;
V_25 * V_23 ;
V_21 = F_85 ( sizeof( V_25 ) , V_156 , F_83 ) ;
if ( ! V_21 ) {
F_40 ( L_10 ,
V_57 -> V_17 ) ;
V_157 = - V_18 ;
return NULL ;
}
V_23 = ( V_25 * ) ( F_16 ( V_21 ) ) ;
V_21 -> V_19 = V_154 ;
V_23 -> V_61 = V_57 ;
V_23 -> V_131 = V_158 ;
V_23 -> V_159 = V_160 ;
V_160 = V_23 ;
V_23 -> V_151 = V_23 -> V_159 ? V_23 -> V_159 -> V_151 + 1 : 0 ;
if ( ! V_161 )
V_161 = V_23 ;
strcpy ( V_23 -> V_17 , V_57 -> V_17 ) ;
#if F_86 ( V_162 )
F_87 ( & V_23 -> V_163 ,
( void (*) ( unsigned long ) ) V_164 ,
( unsigned long ) V_23 ) ;
if ( F_88 ( & V_23 -> V_163 . V_165 ) == 0 )
F_89 ( & V_23 -> V_163 ) ;
#elif F_86 ( V_166 )
V_23 -> V_167 . V_168 = ( void * ) ( unsigned long ) V_164 ;
V_23 -> V_167 . V_82 = V_23 ;
#endif
if ( F_90 ( V_21 ) ||
( F_91 ( V_23 , ( V_169 * ) V_152 , ( V_169 * ) V_153 ) != V_170 ) ) {
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_157 = - V_106 ;
return NULL ;
}
if ( F_92 ( V_154 , & F_14 ,
V_171 ,
V_21 -> V_9 , V_21 ) ) {
F_40 ( L_11 ,
V_21 -> V_9 , V_154 ) ;
F_93 ( V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_157 = - V_172 ;
return NULL ;
}
#ifdef F_94
if ( F_92 ( V_155 , & F_17 , V_171 , V_21 -> V_9 , V_21 ) ) {
F_40 ( L_12 , V_57 -> V_17 , V_155 ) ;
F_93 ( V_21 ) ;
F_95 ( V_154 , V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
V_157 = - V_172 ;
return NULL ;
}
#endif
{
T_8 V_173 ;
F_96 ( V_57 , V_151 ) ;
switch ( V_57 -> V_64 ) {
case V_65 :
memcpy ( V_21 -> V_66 ,
( V_67 * ) ( V_57 -> V_68 . V_69 . V_70 ) , 6 ) ;
memcpy ( & V_173 , ( V_67 * ) ( V_57 -> V_68 . V_69 . V_174 ) , 4 ) ;
V_23 -> V_175 = F_97 ( V_173 ) ;
break;
case V_71 :
memcpy ( V_21 -> V_66 ,
( V_72 * ) ( V_57 -> V_68 . V_73 . V_70 ) , 6 ) ;
memcpy ( & V_173 , ( V_72 * ) ( V_57 -> V_68 . V_73 . V_174 ) , 4 ) ;
V_23 -> V_175 = F_97 ( V_173 ) ;
break;
default:
V_23 -> V_175 = 0 ;
memset ( V_21 -> V_66 , 0 , 6 ) ;
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
#if F_86 ( V_162 )
F_102 ( & V_23 -> V_163 ) ;
#endif
V_157 = F_103 ( V_23 ) ;
if ( V_157 != V_170 ) {
#ifdef F_100
F_104 ( V_23 ) ;
#endif
F_93 ( V_21 ) ;
F_95 ( V_155 , V_21 ) ;
F_95 ( V_154 , V_21 ) ;
F_42 ( F_16 ( V_21 ) ) ;
F_42 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
static int T_9
F_105 ( void )
{
int V_176 ;
V_176 = F_106 () ;
if ( V_176 )
return - V_176 ;
if ( V_80 != V_177 )
F_6 ( L_13 ,
V_177 , V_80 ) ;
if ( V_178 != V_179 )
F_6 ( L_14 ,
V_179 , V_178 ) ;
if ( V_180 != V_181 )
F_6 ( L_15 ,
V_181 , V_180 ) ;
if ( V_182 != V_183 ) {
if ( V_182 > 2000 )
V_182 = 2000 ;
F_6 ( L_16 ,
V_183 , V_182 ) ;
}
if ( V_184 != V_185 ) {
if ( V_184 > 1000 )
V_184 = 1000 ;
F_6 ( L_17 ,
V_185 , V_184 ) ;
}
return 0 ;
}
static void T_10
F_107 ( void )
{
T_6 * V_57 ;
V_25 * V_23 ;
struct V_7 * V_21 ;
int V_107 , V_186 , V_187 ;
for ( V_107 = 0 , V_57 = V_61 ; V_107 < V_188 ; V_107 ++ , V_57 ++ ) {
if ( V_57 -> V_21 ) {
V_23 = ( V_25 * ) ( F_16 ( V_57 -> V_21 ) ) ;
for ( V_186 = 0 ; V_186 < V_23 -> V_90 ; V_186 ++ )
for ( V_187 = 0 ; V_187 < V_189 ; V_187 ++ ) {
V_21 = V_23 -> V_88 [ V_186 ] . V_190 [ V_187 ] -> V_3 ;
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
