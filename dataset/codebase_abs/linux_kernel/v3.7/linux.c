void *
F_1 ( int V_1 )
{
T_1 * V_2 ;
V_2 = F_2 ( V_1 ) ;
return V_2 ? V_2 -> V_3 : 0 ;
}
char *
F_3 ( T_2 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_1 ( V_6 -> V_1 ) ;
return V_8 -> V_9 ;
}
static T_3
F_4 ( int V_10 )
{
if ( V_10 > 0 )
return - V_10 ;
else
return V_10 ;
}
void
F_5 ( T_1 * V_2 )
{
T_4 * V_11 = V_2 -> V_12 ;
#ifdef F_6
F_7 ( L_1 ,
V_13 , V_11 -> V_14 , V_2 -> V_1 , V_2 ) ;
#endif
F_8 ( V_11 -> V_15 , & V_2 -> V_16 ) ;
}
T_3
F_9 ( T_4 * V_11 , T_1 * V_2 )
{
F_10 ( & V_2 -> V_16 , ( void * ) V_17 ) ;
return 0 ;
}
T_3
F_11 ( T_4 * V_11 )
{
char V_9 [ 16 ] , * V_18 ;
if ( V_11 -> V_15 )
return 0 ;
V_18 = V_9 ;
memset ( V_9 , 0 , 16 ) ;
sprintf ( V_18 , L_2 , V_11 -> V_12 -> V_19 , V_11 -> V_14 ) ;
#ifdef F_6
F_7 ( L_3 ,
V_13 , V_9 , V_11 -> V_14 ) ;
#endif
if ( ! ( V_11 -> V_15 = F_12 ( V_9 ) ) )
return V_20 ;
return 0 ;
}
void
F_13 ( T_4 * V_11 )
{
if ( V_11 -> V_15 )
{
F_14 ( V_11 -> V_15 ) ;
V_11 -> V_15 = 0 ;
}
}
T_5
F_15 ( int V_21 , void * V_22 )
{
struct V_7 * V_23 = V_22 ;
return F_16 ( F_17 ( V_23 ) ) ;
}
T_5
F_18 ( int V_21 , void * V_22 )
{
struct V_7 * V_23 = V_22 ;
return F_19 ( F_17 ( V_23 ) ) ;
}
static int
F_20 ( struct V_7 * V_23 )
{
F_7 ( L_4 , V_23 -> V_9 ) ;
return - 1 ;
}
STATIC int
F_21 ( struct V_7 * V_23 )
{
T_2 * V_4 = F_22 ( V_23 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_24 ;
if ( ( V_24 = F_23 ( V_23 ) ) )
{
F_7 ( L_5 , V_24 ) ;
return V_24 ;
}
if ( ( V_24 = F_24 ( V_6 -> V_25 , V_6 -> V_1 ) ) )
return - V_24 ;
F_25 ( V_26 ) ;
F_26 ( V_23 ) ;
return 0 ;
}
STATIC int
F_27 ( struct V_7 * V_23 )
{
T_2 * V_4 = F_22 ( V_23 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
F_28 ( V_23 ) ;
F_29 ( ( V_27 * ) 0 , V_6 -> V_1 ) ;
F_30 ( V_23 ) ;
F_31 ( V_26 ) ;
return 0 ;
}
STATIC int
F_32 ( struct V_7 * V_8 , struct V_28 * V_29 , int V_30 )
{
return F_33 ( V_8 , V_29 , V_30 ) ;
}
STATIC int
F_34 ( struct V_7 * V_23 , unsigned short V_31 , unsigned short V_32 )
{
return 0 ;
}
STATIC struct V_33 *
F_35 ( struct V_7 * V_23 )
{
T_1 * V_2 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_1 ;
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) F_22 ( V_23 ) -> V_6 ;
V_1 = V_6 -> V_1 ;
}
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL )
return NULL ;
V_34 = & V_23 -> V_36 ;
V_36 = & V_2 -> V_37 ;
memset ( V_34 , 0 , sizeof ( struct V_33 ) ) ;
V_34 -> V_38 = V_36 -> V_38 ;
V_34 -> V_39 = V_36 -> V_39 ;
V_34 -> V_40 = V_36 -> V_40 ;
V_34 -> V_41 = V_36 -> V_41 ;
V_34 -> V_42 = V_36 -> V_43 +
V_36 -> V_44 +
V_36 -> V_45 +
V_36 -> V_46 +
V_36 -> V_47 +
V_36 -> V_48 ;
V_34 -> V_49 = V_36 -> V_50 +
V_36 -> V_51 +
V_36 -> V_52 ;
V_34 -> V_53 = V_36 -> V_53 ;
V_34 -> V_50 = V_36 -> V_50 ;
V_34 -> V_43 = V_36 -> V_43 ;
V_34 -> V_44 = V_36 -> V_44 ;
V_34 -> V_45 = V_36 -> V_45 ;
V_34 -> V_46 = V_36 -> V_46 ;
V_34 -> V_47 = V_36 -> V_47 ;
V_34 -> V_48 = V_36 -> V_48 ;
V_34 -> V_51 = V_36 -> V_51 ;
V_34 -> V_52 = V_36 -> V_52 ;
return V_34 ;
}
static V_27 *
F_36 ( struct V_7 * V_23 )
{
return ( V_27 * ) ( F_17 ( V_23 ) ) ;
}
STATIC int
F_37 ( struct V_54 * V_55 , struct V_7 * V_23 )
{
const struct V_5 * V_6 ;
int V_56 ;
T_2 * V_4 = F_22 ( V_23 ) ;
V_6 = V_4 -> V_6 ;
V_56 = F_38 ( V_6 -> V_25 , V_6 -> V_1 , V_55 ) ;
return V_56 ;
}
STATIC struct V_7 *
F_39 ( struct V_7 * V_23 , V_27 * V_25 ,
struct V_57 * V_58 )
{
T_2 * V_4 ;
struct V_7 * V_8 ;
T_6 * V_59 ;
int V_24 ;
if ( F_2 ( V_58 -> V_1 ) )
return 0 ;
{
struct V_5 * V_6 ;
V_6 = F_40 ( sizeof ( struct V_5 ) ) ;
if ( ! V_6 )
{
F_41 ( L_6 , V_25 -> V_19 ) ;
return 0 ;
}
V_8 = F_42 ( V_6 ) ;
if ( ! V_8 )
{
F_41 ( L_7 , V_25 -> V_19 ) ;
F_43 ( V_6 ) ;
return 0 ;
}
V_6 -> V_25 = V_25 ;
V_6 -> V_1 = V_58 -> V_1 ;
}
V_4 = F_22 ( V_8 ) ;
V_8 -> V_60 = 0 ;
V_8 -> V_21 = V_23 -> V_21 ;
V_8 -> type = V_61 ;
* V_8 -> V_9 = 0 ;
V_59 = ( T_6 * ) V_25 -> V_62 ;
if ( V_59 -> V_63 == V_64 )
{
switch ( V_59 -> V_65 )
{
case V_66 :
memcpy ( V_8 -> V_67 , ( V_68 * ) ( V_59 -> V_69 . V_70 . V_71 ) , 6 ) ;
break;
case V_72 :
memcpy ( V_8 -> V_67 , ( V_73 * ) ( V_59 -> V_69 . V_74 . V_71 ) , 6 ) ;
break;
default:
memset ( V_8 -> V_67 , 0 , 6 ) ;
break;
}
} else
{
memset ( V_8 -> V_67 , 0 , 6 ) ;
}
V_4 -> V_75 = F_37 ;
V_8 -> V_76 = & V_77 ;
V_4 -> V_78 = F_34 ;
F_44 () ;
V_24 = F_45 ( V_8 ) ;
V_8 -> V_79 = V_80 ;
F_46 () ;
if ( V_24 )
{
if ( V_81 >= V_82 )
F_7 ( L_8 ,
V_25 -> V_19 , V_58 -> V_1 , V_24 ) ;
F_47 ( V_8 ) ;
return 0 ;
}
return V_8 ;
}
STATIC T_3
F_48 ( struct V_7 * V_23 , void * V_83 )
{
int V_24 ;
V_27 * V_25 ;
struct V_84 V_85 ;
if ( F_49 ( & V_85 , V_83 , sizeof ( struct V_84 ) ) )
return - V_86 ;
if ( V_85 . V_14 >= V_87 )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
V_24 = F_4 ( F_50 ( V_25 , V_85 . V_14 ) ) ;
if ( V_24 )
return V_24 ;
if ( F_51 ( V_83 , & V_25 -> V_89 [ V_85 . V_14 ] . V_90 ,
sizeof ( struct V_84 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_52 ( struct V_7 * V_23 , void * V_83 )
{
V_27 * V_25 ;
struct V_84 V_85 ;
if ( F_49 ( & V_85 , V_83 , sizeof ( struct V_84 ) ) )
return - V_86 ;
if ( V_85 . V_14 >= V_87 )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
if ( V_85 . V_14 >= V_25 -> V_91 )
return - V_92 ;
memcpy ( & V_25 -> V_89 [ V_85 . V_14 ] . V_90 , & V_85 , sizeof ( struct V_84 ) ) ;
return F_4 ( F_53 ( V_25 , V_85 . V_14 ) ) ;
}
STATIC T_3
F_54 ( struct V_7 * V_23 , void * V_83 )
{
struct V_84 V_85 ;
V_27 * V_25 ;
if ( F_49 ( & V_85 , V_83 , sizeof ( struct V_84 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
return F_4 ( F_55 ( V_25 , V_85 . V_14 , V_85 . V_93 ) ) ;
}
STATIC T_3
F_56 ( struct V_7 * V_23 , void * V_83 )
{
struct V_84 V_85 ;
V_27 * V_25 ;
int V_24 ;
if ( F_49 ( & V_85 , V_83 , sizeof ( struct V_84 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
V_24 = F_4 ( F_57 ( V_25 , & V_85 ) ) ;
if ( V_24 )
return V_24 ;
if ( F_51 ( V_83 , & V_85 , sizeof ( struct V_84 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_58 ( struct V_7 * V_23 , void * V_83 )
{
struct V_84 V_85 ;
V_27 * V_25 ;
int V_24 ;
if ( F_49 ( & V_85 , V_83 , sizeof ( struct V_84 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
V_24 = F_4 ( F_59 ( V_25 , & V_85 ) ) ;
if ( V_24 )
return V_24 ;
if ( F_51 ( V_83 , & V_85 , sizeof ( struct V_84 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_60 ( struct V_7 * V_23 , void * V_83 )
{
struct V_94 V_95 ;
V_27 * V_25 ;
int V_24 ;
if ( F_49 ( & V_95 , V_83 , sizeof ( struct V_94 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
V_24 = F_4 ( F_61 ( V_25 , & V_95 ) ) ;
if ( V_24 )
return V_24 ;
if ( F_51 ( V_83 , & V_95 , sizeof ( struct V_94 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_62 ( struct V_7 * V_23 , void * V_83 )
{
struct V_57 V_58 ;
int V_24 ;
if ( F_49 ( & V_58 , V_83 ,
sizeof ( struct V_57 ) ) )
return - V_86 ;
if ( ( V_24 = F_4 ( F_63 ( V_58 . V_1 , & V_58 ) ) ) )
return V_24 ;
if ( F_51 ( V_83 , & V_58 , sizeof ( struct V_57 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_64 ( struct V_7 * V_23 , void * V_83 )
{
struct V_57 V_58 ;
int V_24 ;
V_27 * V_25 ;
if ( F_49 ( & V_58 , V_83 , sizeof ( struct V_57 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
switch ( V_24 = F_4 ( F_65 ( V_58 . V_1 , & V_58 ) ) )
{
case 0 :
return 0 ;
default:
return V_24 ;
}
}
STATIC T_3
F_66 ( struct V_7 * V_23 , void * V_83 )
{
V_27 * V_25 ;
struct V_7 * V_8 ;
struct V_57 V_58 ;
int V_24 ;
if ( F_49 ( & V_58 , V_83 , sizeof ( struct V_57 ) ) )
return - V_86 ;
V_25 = F_36 ( V_23 ) ;
if ( ! V_25 )
return - V_88 ;
V_8 = F_39 ( V_23 , V_25 , & V_58 ) ;
if ( ! V_8 )
return - V_96 ;
V_24 = F_4 ( F_67 ( V_25 , V_58 . V_89 , V_58 . V_1 , V_8 ) ) ;
if ( V_24 )
{
F_44 () ;
F_68 ( V_8 ) ;
F_46 () ;
F_47 ( V_8 ) ;
}
return V_24 ;
}
STATIC T_3
F_69 ( struct V_7 * V_23 , void * V_83 )
{
struct V_97 V_98 ;
int V_24 ;
if ( F_49 ( & V_98 , V_83 ,
sizeof ( struct V_97 ) ) )
return - V_86 ;
switch ( V_24 = F_4 ( F_70 ( V_98 . V_1 , & V_98 . V_36 ) ) )
{
case 0 :
break;
default:
return V_24 ;
}
if ( F_51 ( V_83 , & V_98 ,
sizeof ( struct V_97 ) ) )
return - V_86 ;
return 0 ;
}
STATIC T_3
F_71 ( struct V_7 * V_23 , void * V_83 )
{
unsigned int V_81 ;
if ( F_49 ( & V_81 , V_83 , sizeof ( int ) ) )
return - V_86 ;
F_72 ( V_81 ) ;
return 0 ;
}
STATIC T_3
F_73 ( struct V_7 * V_23 , int V_99 )
{
if ( V_23 -> V_100 & V_101 )
return - V_96 ;
{
V_27 * V_25 ;
T_1 * V_2 ;
const struct V_5 * V_6 ;
int V_1 ;
V_6 = (struct V_5 * ) F_22 ( V_23 ) -> V_6 ;
V_25 = V_6 -> V_25 ;
V_1 = V_6 -> V_1 ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL )
return - V_102 ;
V_2 -> V_3 = 0 ;
}
if ( V_99 )
F_44 () ;
F_68 ( V_23 ) ;
if ( V_99 )
F_46 () ;
F_47 ( V_23 ) ;
return 0 ;
}
int
F_74 ( struct V_7 * V_103 , void * V_83 )
{
struct V_57 V_58 ;
char V_104 [ sizeof ( V_105 ) + 3 ] ;
struct V_7 * V_8 ;
int V_24 ;
if ( F_49 ( & V_58 , V_83 ,
sizeof ( struct V_57 ) ) )
return - V_86 ;
sprintf ( V_104 , V_105 L_9 , V_58 . V_1 ) ;
if ( ! ( V_8 = F_75 ( & V_106 , V_104 ) ) )
return - V_102 ;
F_76 ( V_8 ) ;
V_24 = F_73 ( V_8 , 1 ) ;
if ( V_24 )
return V_24 ;
return F_77 ( V_58 . V_1 ) ;
}
int
F_78 ( struct V_7 * V_103 , void * V_83 )
{
const struct V_5 * V_6 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < 128 ; V_107 ++ )
{
struct V_7 * V_23 ;
char V_104 [ sizeof ( V_105 ) + 3 ] ;
sprintf ( V_104 , V_105 L_9 , V_107 ) ;
if ( ! ( V_23 = F_75 ( & V_106 , V_104 ) ) )
continue;
V_6 = F_22 ( V_23 ) -> V_6 ;
if ( ( unsigned long ) ( V_6 -> V_25 ) ==
( unsigned long ) ( F_17 ( V_103 ) ) )
{
V_23 -> V_100 &= ~ V_101 ;
F_76 ( V_23 ) ;
F_28 ( V_23 ) ;
F_73 ( V_23 , 1 ) ;
} else
F_76 ( V_23 ) ;
}
return 0 ;
}
int
F_79 ( struct V_7 * V_103 , void * V_83 )
{
struct V_57 V_58 ;
if ( F_49 ( & V_58 , V_83 ,
sizeof ( struct V_57 ) ) )
return - V_86 ;
return F_4 ( F_80 ( V_58 . V_1 ) ) ;
}
STATIC T_3
F_81 ( struct V_7 * V_23 , struct V_28 * V_29 , int V_30 )
{
V_27 * V_25 ;
void * V_83 ;
int V_108 , V_109 ;
T_3 V_24 ;
static struct V_83
{
union
{
T_7 V_110 ;
T_8 V_107 ;
struct V_111 V_112 ;
struct V_113 V_114 ;
struct V_115 V_116 ;
struct V_117 V_118 ;
struct V_35 V_36 ;
struct V_57 V_119 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
} V_126 ;
} V_127 ;
if ( ! F_82 ( V_128 ) )
return - V_129 ;
if ( V_30 != V_130 + 15 )
return - V_88 ;
if ( ! ( V_25 = F_36 ( V_23 ) ) )
return - V_88 ;
if ( V_25 -> V_131 != V_132 )
return - V_133 ;
if ( F_49 ( & V_108 , V_29 -> V_134 , sizeof ( V_108 ) ) )
return - V_86 ;
#if 0
if (copy_from_user (&len, ifr->ifr_data + sizeof (iocmd), sizeof (len)))
return -EFAULT;
#endif
#if 0
pr_info("c4_ioctl: iocmd %x, dir %x type %x nr %x iolen %d.\n", iocmd,
_IOC_DIR (iocmd), _IOC_TYPE (iocmd), _IOC_NR (iocmd),
_IOC_SIZE (iocmd));
#endif
V_109 = F_83 ( V_108 ) ;
V_83 = V_29 -> V_134 + sizeof ( V_108 ) ;
if ( F_49 ( & V_127 , V_83 , V_109 ) )
return - V_86 ;
V_24 = 0 ;
switch ( V_108 )
{
case V_135 :
V_24 = F_48 ( V_23 , V_83 ) ;
break;
case V_136 :
V_24 = F_52 ( V_23 , V_83 ) ;
break;
case V_137 :
V_24 = F_62 ( V_23 , V_83 ) ;
break;
case V_138 :
V_24 = F_64 ( V_23 , V_83 ) ;
break;
case V_139 :
V_24 = F_74 ( V_23 , V_83 ) ;
break;
case V_140 :
V_24 = F_66 ( V_23 , V_83 ) ;
break;
case V_141 :
V_24 = F_69 ( V_23 , V_83 ) ;
break;
case V_142 :
V_24 = F_71 ( V_23 , V_83 ) ;
break;
case V_143 :
V_24 = F_78 ( V_23 , V_83 ) ;
break;
case V_144 :
V_24 = F_79 ( V_23 , V_83 ) ;
break;
case V_145 :
V_24 = F_54 ( V_23 , V_83 ) ;
break;
case V_146 :
V_24 = F_56 ( V_23 , V_83 ) ;
break;
case V_147 :
V_24 = F_60 ( V_23 , V_83 ) ;
break;
case V_148 :
V_24 = F_58 ( V_23 , V_83 ) ;
break;
case V_149 :
V_24 = ( V_109 == sizeof ( struct V_115 ) ) ? F_84 ( V_25 , & V_127 . V_126 . V_116 ) : - V_86 ;
if ( V_24 == 0 )
if ( F_51 ( V_83 , & V_127 , V_109 ) )
return - V_86 ;
break;
default:
V_24 = - V_88 ;
break;
}
return F_4 ( V_24 ) ;
}
static void F_85 ( struct V_7 * V_8 )
{
V_8 -> type = V_150 ;
V_8 -> V_76 = & V_151 ;
}
struct V_7 * T_9
F_86 ( T_6 * V_59 , int V_152 , unsigned long V_153 , unsigned long V_154 ,
int V_155 , int V_156 )
{
struct V_7 * V_23 ;
V_27 * V_25 ;
V_23 = F_87 ( sizeof( V_27 ) , V_157 , F_85 ) ;
if ( ! V_23 )
{
F_41 ( L_10 , V_59 -> V_19 ) ;
V_158 = V_20 ;
return 0 ;
}
V_25 = ( V_27 * ) ( F_17 ( V_23 ) ) ;
V_23 -> V_21 = V_155 ;
V_25 -> V_62 = V_59 ;
V_25 -> V_131 = V_159 ;
V_25 -> V_160 = V_161 ;
V_161 = V_25 ;
V_25 -> V_152 = V_25 -> V_160 ? V_25 -> V_160 -> V_152 + 1 : 0 ;
if ( V_162 == 0 )
V_162 = V_25 ;
strcpy ( V_25 -> V_19 , V_59 -> V_19 ) ;
V_25 -> V_163 = & V_164 [ 0 ] ;
#if F_88 ( V_165 )
F_89 ( & V_25 -> V_166 ,
( void (*) ( unsigned long ) ) V_167 ,
( unsigned long ) V_25 ) ;
if ( F_90 ( & V_25 -> V_166 . V_168 ) == 0 )
F_91 ( & V_25 -> V_166 ) ;
#elif F_88 ( V_169 )
V_25 -> V_170 . V_171 = ( void * ) ( unsigned long ) V_167 ;
V_25 -> V_170 . V_83 = V_25 ;
#endif
if ( F_92 ( V_23 ) ||
( F_93 ( V_25 , ( V_172 * ) V_153 , ( V_172 * ) V_154 ) != V_173 ) )
{
F_43 ( F_17 ( V_23 ) ) ;
F_43 ( V_23 ) ;
V_158 = V_133 ;
return 0 ;
}
if ( F_94 ( V_155 , & F_15 ,
V_174 ,
V_23 -> V_9 , V_23 ) )
{
F_41 ( L_11 , V_23 -> V_9 , V_155 ) ;
F_95 ( V_23 ) ;
F_43 ( F_17 ( V_23 ) ) ;
F_43 ( V_23 ) ;
V_158 = V_175 ;
return 0 ;
}
#ifdef F_96
if ( F_94 ( V_156 , & F_18 , V_174 , V_23 -> V_9 , V_23 ) )
{
F_41 ( L_12 , V_59 -> V_19 , V_156 ) ;
F_95 ( V_23 ) ;
F_97 ( V_155 , V_23 ) ;
F_43 ( F_17 ( V_23 ) ) ;
F_43 ( V_23 ) ;
V_158 = V_175 ;
return 0 ;
}
#endif
{
T_8 V_176 ;
F_98 ( V_59 , V_152 ) ;
switch ( V_59 -> V_65 )
{
case V_66 :
memcpy ( V_23 -> V_67 , ( V_68 * ) ( V_59 -> V_69 . V_70 . V_71 ) , 6 ) ;
memcpy ( & V_176 , ( V_68 * ) ( V_59 -> V_69 . V_70 . V_177 ) , 4 ) ;
V_25 -> V_178 = F_99 ( V_176 ) ;
break;
case V_72 :
memcpy ( V_23 -> V_67 , ( V_73 * ) ( V_59 -> V_69 . V_74 . V_71 ) , 6 ) ;
memcpy ( & V_176 , ( V_73 * ) ( V_59 -> V_69 . V_74 . V_177 ) , 4 ) ;
V_25 -> V_178 = F_99 ( V_176 ) ;
break;
default:
V_25 -> V_178 = 0 ;
memset ( V_23 -> V_67 , 0 , 6 ) ;
break;
}
#if 1
F_100 ( V_25 ) ;
#else
F_101 ( V_25 ) ;
#endif
}
#ifdef F_102
F_103 ( V_25 ) ;
#endif
#if F_88 ( V_165 )
F_104 ( & V_25 -> V_166 ) ;
#endif
if ( ( V_158 = F_105 ( V_25 ) ) != V_173 )
{
#ifdef F_102
F_106 ( V_25 ) ;
#endif
F_95 ( V_23 ) ;
F_97 ( V_156 , V_23 ) ;
F_97 ( V_155 , V_23 ) ;
F_43 ( F_17 ( V_23 ) ) ;
F_43 ( V_23 ) ;
return 0 ;
}
return V_23 ;
}
STATIC int T_9
F_107 ( void )
{
int V_179 ;
F_41 ( L_13 , V_164 ) ;
if ( ( V_179 = F_108 () ) )
return - V_179 ;
if ( V_81 != V_180 )
F_7 ( L_14 ,
V_180 , V_81 ) ;
if ( V_181 != V_182 )
F_7 ( L_15 ,
V_182 , V_181 ) ;
if ( V_183 != V_184 )
F_7 ( L_16 ,
V_184 , V_183 ) ;
if ( V_185 != V_186 )
{
if ( V_185 > 2000 )
V_185 = 2000 ;
F_7 ( L_17 ,
V_186 , V_185 ) ;
}
if ( V_187 != V_188 )
{
if ( V_187 > 1000 )
V_187 = 1000 ;
F_7 ( L_18 ,
V_188 , V_187 ) ;
}
return 0 ;
}
STATIC void T_10
F_109 ( void )
{
T_6 * V_59 ;
V_27 * V_25 ;
struct V_7 * V_23 ;
int V_107 , V_189 , V_190 ;
for ( V_107 = 0 , V_59 = V_62 ; V_107 < V_191 ; V_107 ++ , V_59 ++ )
{
if ( V_59 -> V_23 )
{
V_25 = ( V_27 * ) ( F_17 ( V_59 -> V_23 ) ) ;
for ( V_189 = 0 ; V_189 < V_25 -> V_91 ; V_189 ++ )
for ( V_190 = 0 ; V_190 < V_192 ; V_190 ++ )
if ( ( V_23 = V_25 -> V_89 [ V_189 ] . V_193 [ V_190 ] -> V_3 ) )
{
F_73 ( V_23 , 0 ) ;
}
}
}
}
STATIC void T_10
F_110 ( void )
{
F_109 () ;
F_111 () ;
F_112 () ;
F_113 () ;
F_7 ( L_19 ) ;
}
