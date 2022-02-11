static int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 ) ;
if ( ! V_1 )
return - V_3 ;
V_4 = F_3 ( V_5 ) ;
if ( V_4 == NULL ) {
F_4 ( L_1 , V_6 ) ;
F_5 ( V_1 ) ;
return - V_3 ;
}
V_1 -> V_7 = L_2 ;
V_1 -> V_8 = L_2 ;
V_1 -> V_9 = V_10 ;
V_1 -> V_11 = V_12 ;
V_1 -> type = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_16 . V_18 = V_19 | V_20 | V_21 | V_22 | V_23 ;
V_1 -> V_24 = V_25 ;
F_6 ( V_1 , & V_26 ) ;
if ( F_7 ( V_1 ) ) {
F_4 ( L_3 ,
V_6 ) ;
F_5 ( V_1 ) ;
return - 1 ;
}
return 0 ;
}
static void T_2 F_8 ( struct V_27 * V_28 )
{
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_11 ( V_28 ) ;
V_28 -> V_29 = 0 ;
F_12 ( V_28 ) ;
}
static void T_2 F_13 ( void )
{
int V_30 ;
F_9 ( 4 , L_4 , V_6 ) ;
V_30 = F_14 ( V_1 ) ;
if ( V_30 ) {
F_4 ( L_5 ,
V_6 ) ;
return;
}
F_15 ( V_4 , ( V_31 ) F_8 ) ;
F_5 ( V_1 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
T_3 V_32 ;
int V_30 = - V_33 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_17 ( V_34 , & V_28 -> V_24 ) ) {
F_9 ( 2 , L_6 , V_6 ) ;
return 0 ;
}
F_18 ( & V_32 ) ;
V_32 . V_35 = V_36 ;
V_32 . V_37 = V_38 ;
V_32 . V_39 = V_40 ;
V_32 . V_41 = V_42 ;
V_32 . V_43 = V_44 ;
V_32 . V_45 = V_46 ;
F_19 ( V_32 . V_8 , L_7 , sizeof( V_32 . V_8 ) ) ;
V_32 . V_47 = V_28 ;
if ( ! V_28 -> V_48 ) {
V_28 -> V_48 = F_20 ( & V_32 , V_28 -> V_49 ,
V_28 -> line ) ;
}
if ( ! V_28 -> V_48 )
goto V_50;
V_28 -> V_51 = V_28 -> V_48 -> V_51 ;
V_30 = F_21 ( V_28 ) ;
if ( V_30 < 0 ) {
F_4 ( L_8 , V_6 ) ;
goto V_50;
}
return 0 ;
V_50:
F_22 ( V_34 , & V_28 -> V_24 ) ;
return V_30 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_52 * V_53 )
{
F_24 ( V_54 , V_55 ) ;
int V_56 ;
int V_57 = 0 , V_58 = 0 ;
unsigned long V_24 ;
struct V_59 * V_60 ;
F_9 ( 2 , L_4 , V_6 ) ;
V_60 = V_28 -> V_60 ;
if ( V_53 -> V_61 & V_62 || V_60 -> V_24 & ( 1 << V_63 ) ) {
V_28 -> V_24 |= V_64 ;
F_9 ( 1 , L_9 , V_6 ) ;
return 0 ;
}
if ( V_60 -> V_65 -> V_18 & V_23 ) {
F_9 ( 1 , L_10 , V_6 ) ;
V_57 = 1 ;
}
V_56 = 0 ;
F_25 ( & V_28 -> V_66 , & V_54 ) ;
F_9 ( 2 , L_11 ,
__FILE__ , __LINE__ , V_60 -> V_1 -> V_8 , V_28 -> V_67 ) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
if ( ! F_27 ( V_53 ) ) {
V_58 = 1 ;
V_28 -> V_67 -- ;
}
F_28 ( & V_28 -> V_68 , V_24 ) ;
V_28 -> V_69 ++ ;
while ( 1 ) {
if ( V_60 -> V_65 -> V_18 & V_70 ) {
V_28 -> V_71 . V_72 |= V_73 + V_74 ;
F_29 ( V_28 , V_75 , TRUE ) ;
}
V_55 -> V_76 = V_77 ;
if ( F_27 ( V_53 ) ||
! F_30 ( V_34 , & V_28 -> V_24 ) ) {
V_56 = ( V_28 -> V_24 & V_78 ) ?
- V_79 : - V_80 ;
break;
}
if ( ! F_30 ( V_81 , & V_28 -> V_24 ) &&
( V_57 || ( V_28 -> V_71 . V_82 & V_83 ) ) &&
V_28 -> V_76 == V_84 )
{
break;
}
if ( F_31 ( V_55 ) ) {
V_56 = - V_80 ;
break;
}
F_9 ( 1 , L_12 ,
__FILE__ , __LINE__ , V_60 -> V_1 -> V_8 , V_28 -> V_67 ) ;
F_32 () ;
}
F_33 ( V_85 ) ;
F_34 ( & V_28 -> V_66 , & V_54 ) ;
if ( V_58 ) {
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_28 -> V_67 ++ ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
}
V_28 -> V_69 -- ;
F_9 ( 1 , L_13 ,
__FILE__ , __LINE__ , V_60 -> V_1 -> V_8 , V_28 -> V_67 ) ;
if ( ! V_56 )
V_28 -> V_24 |= V_64 ;
return V_56 ;
}
static int F_35 ( struct V_59 * V_60 , struct V_52 * V_53 )
{
struct V_27 * V_28 ;
unsigned int line = V_60 -> V_86 ;
unsigned long V_24 ;
int V_30 ;
F_9 ( 2 , L_4 , V_6 ) ;
V_28 = F_36 ( V_4 , line , NULL ) ;
if ( ! V_28 ) {
V_28 = F_37 ( sizeof( struct V_27 ) , V_87 ) ;
if ( V_28 == NULL ) {
F_4 ( L_14 , V_6 ) ;
return - V_3 ;
}
V_28 -> V_29 = V_88 ;
V_28 -> V_89 = V_90 ;
V_28 -> line = line ;
F_38 ( & V_28 -> V_91 , V_92 ) ;
V_28 -> V_93 = V_94 ;
V_28 -> V_95 = V_96 ;
V_28 -> V_97 = 5 * V_98 / 10 ;
V_28 -> V_99 = 30 * V_98 ;
F_39 ( & V_28 -> V_100 ) ;
F_40 ( & V_28 -> V_66 ) ;
F_40 ( & V_28 -> V_101 ) ;
F_41 ( & V_28 -> V_68 ) ;
V_60 -> V_65 -> V_102 = 0 ;
V_60 -> V_65 -> V_103 = 0 ;
F_42 ( V_4 , ( V_104 * ) V_28 , line , NULL ) ;
}
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_28 -> V_67 ++ ;
V_60 -> V_105 = V_28 ;
V_28 -> V_60 = V_60 ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_9 ( 1 , L_15 , V_6 , V_60 -> V_1 -> V_8 ,
V_28 -> line , V_28 -> V_67 ) ;
V_28 -> V_60 -> V_106 = ( V_28 -> V_24 & V_107 ) ? 1 : 0 ;
if ( F_27 ( V_53 ) ||
F_30 ( V_81 , & V_28 -> V_24 ) ) {
if ( F_43 ( V_28 -> V_101 , ! F_30 ( V_81 , & V_28 -> V_24 ) ) ) {
F_44 ( L_16 ,
V_6 ) ;
return - V_80 ;
}
#ifdef F_45
return ( V_28 -> V_24 & V_78 ) ?
- V_79 : - V_80 ;
#else
return - V_79 ;
#endif
}
if ( line < 0x10 ) {
V_28 -> V_49 = V_108 | V_109 ;
V_28 -> V_71 . V_49 = V_109 ;
V_28 -> V_71 . V_82 = V_110 | V_83 | V_111 | V_112 ;
F_9 ( 2 , L_17 , V_6 ) ;
} else {
F_9 ( 2 , L_18 , V_6 ) ;
V_28 -> V_49 = V_113 ;
V_28 -> V_71 . V_49 = V_113 ;
}
V_30 = F_16 ( V_28 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_23 ( V_28 , V_53 ) ;
if ( V_30 ) {
F_9 ( 2 ,
L_19 , V_6 ,
V_30 ) ;
return V_30 ;
}
return 0 ;
}
static void F_46 ( struct V_59 * V_60 , struct V_52 * V_53 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_24 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
if ( F_27 ( V_53 ) ) {
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_9 ( 0 , L_20 , V_6 ) ;
return;
}
if ( ( V_60 -> V_114 == 1 ) && ( V_28 -> V_67 != 1 ) ) {
F_9 ( 0 , L_21
L_22 , V_6 ,
V_28 -> V_67 ) ;
V_28 -> V_67 = 1 ;
}
if ( -- V_28 -> V_67 < 0 ) {
F_4 ( L_23 ,
V_6 , V_28 -> line , V_28 -> V_67 ) ;
V_28 -> V_67 = 0 ;
}
if ( V_28 -> V_67 ) {
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_9 ( 0 , L_24 , V_6 ) ;
return;
}
F_47 ( V_81 , & V_28 -> V_24 ) ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
V_60 -> V_115 = 1 ;
if ( V_28 -> V_99 != V_116 )
F_48 ( V_60 , V_28 -> V_99 ) ;
F_11 ( V_28 ) ;
F_49 ( V_60 ) ;
F_50 ( V_60 ) ;
V_60 -> V_115 = 0 ;
V_28 -> V_60 = NULL ;
if ( V_28 -> V_69 ) {
if ( V_28 -> V_97 )
F_51 ( V_28 -> V_97 ) ;
F_52 ( & V_28 -> V_66 ) ;
}
V_28 -> V_24 &= ~ ( V_64 | V_117 ) ;
F_52 ( & V_28 -> V_101 ) ;
}
static void F_53 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_54 ( & V_28 -> V_91 ) ;
}
static void V_92 ( struct V_118 * V_119 )
{
struct V_27 * V_28 =
F_55 ( V_119 , struct V_27 , V_91 ) ;
struct V_59 * V_60 ;
unsigned long V_24 ;
struct V_120 * V_121 , * V_122 ;
F_9 ( 2 , L_4 , V_6 ) ;
if ( ! V_28 || V_28 -> V_29 != V_88 )
return;
V_60 = V_28 -> V_60 ;
if ( ! V_60 )
return;
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_122 = V_28 -> V_122 ;
V_28 -> V_122 = NULL ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
if( V_122 ) {
if( V_28 -> V_89 == V_123 )
F_56 ( V_28 -> V_48 , V_122 ) ;
F_57 ( V_122 ) ;
}
if ( V_60 -> V_124 )
return;
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_121 = V_28 -> V_125 ;
V_28 -> V_125 = NULL ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
if ( V_121 ) {
F_58 ( V_28 , V_126 , V_121 , NULL ) ;
F_57 ( V_121 ) ;
}
F_59 ( V_60 ) ;
}
static int F_60 ( struct V_59 * V_60 ,
const unsigned char * V_127 , int V_114 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_24 ;
struct V_120 * V_121 ;
int V_128 = 0 ;
int V_129 = 0 ;
int V_130 ;
F_9 ( 2 , L_25 , V_6 , V_114 ,
V_60 -> V_124 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_28 -> V_93 == V_94 ) {
F_9 ( 1 , L_26 , V_6 ) ;
#ifdef F_61
return 0 ;
#endif
}
if ( V_114 < 1 )
return 0 ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_121 = V_28 -> V_125 ;
while ( V_114 ) {
V_130 = V_114 ;
if ( V_130 > V_28 -> V_95 )
V_130 = V_28 -> V_95 ;
if ( V_121 ) {
if ( ( V_128 = ( V_28 -> V_131 - V_121 -> V_129 ) ) > 0 ) {
if ( V_130 > V_128 )
V_130 = V_128 ;
} else {
break;
}
} else {
V_121 = F_62 ( V_28 -> V_95 +
V_28 -> V_93 ,
V_132 ) ;
if ( ! V_121 ) {
F_28 ( & V_28 -> V_68 , V_24 ) ;
return - V_133 ;
}
F_63 ( V_121 , V_28 -> V_93 ) ;
V_28 -> V_125 = V_121 ;
V_28 -> V_131 = V_28 -> V_95 ;
}
memcpy ( F_64 ( V_121 , V_130 ) , V_127 + V_129 , V_130 ) ;
V_114 -= V_130 ;
V_129 += V_130 ;
}
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_54 ( & V_28 -> V_91 ) ;
return V_129 ;
}
static int F_65 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_24 ;
int V_30 ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_61
if ( V_28 -> V_93 == V_94 )
return 0 ;
#endif
if ( V_60 -> V_124 )
V_30 = 0 ;
else {
F_26 ( & V_28 -> V_68 , V_24 ) ;
if ( V_28 -> V_125 )
V_30 = V_28 -> V_131 - V_28 -> V_125 -> V_129 ;
else
V_30 = V_28 -> V_95 ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
}
F_9 ( 2 , L_27 , V_6 , V_30 ) ;
return V_30 ;
}
static void F_66 ( struct V_59 * V_60 , int V_134 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_135 , V_136 ;
unsigned long V_24 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_135 = V_137 ;
V_136 = F_67 ( V_134 , F_68 ( 200 ) ) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
while ( V_28 -> V_125 && V_28 -> V_125 -> V_129 ) {
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_51 ( V_136 ) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
if ( F_31 ( V_55 ) )
break;
if ( V_134 && F_69 ( V_137 , V_135 + V_134 ) )
break;
}
F_28 ( & V_28 -> V_68 , V_24 ) ;
V_55 -> V_76 = V_85 ;
}
static void F_70 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_71 ( V_60 ) )
F_72 ( V_60 , F_73 ( V_60 ) ) ;
if ( V_60 -> V_65 -> V_18 & V_138 ) {
V_28 -> V_71 . V_72 &= ~ V_73 ;
V_28 -> V_71 . V_72 |= V_139 ;
F_29 ( V_28 , V_75 , TRUE ) ;
}
F_74 ( V_28 -> V_48 , V_90 ) ;
}
static void F_75 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_71 ( V_60 ) ) {
F_72 ( V_60 , F_76 ( V_60 ) ) ;
}
if ( V_60 -> V_65 -> V_18 & V_138 ) {
V_28 -> V_71 . V_72 |= ( V_73 | V_139 ) ;
F_29 ( V_28 , V_75 , TRUE ) ;
F_9 ( 1 , L_28 , V_6 ) ;
}
F_74 ( V_28 -> V_48 , V_123 ) ;
}
static int F_77 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_24 ;
int V_129 = 0 ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
if ( V_28 -> V_125 )
V_129 = V_28 -> V_125 -> V_129 ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
return V_129 ;
}
static void F_11 ( struct V_27 * V_28 )
{
unsigned long V_24 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_9 ( 0 , L_4 , V_6 ) ;
if ( ! F_78 ( V_34 , & V_28 -> V_24 ) )
return;
F_79 ( V_28 ) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
F_80 ( & V_28 -> V_100 ) ;
if ( V_28 -> V_122 ) {
F_57 ( V_28 -> V_122 ) ;
V_28 -> V_122 = NULL ;
}
if ( V_28 -> V_125 ) {
F_57 ( V_28 -> V_125 ) ;
V_28 -> V_125 = NULL ;
}
if ( V_28 -> V_48 ) {
F_81 ( V_28 -> V_48 ) ;
V_28 -> V_48 = NULL ;
}
F_28 ( & V_28 -> V_68 , V_24 ) ;
}
static void F_82 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
unsigned long V_24 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_11 ( V_28 ) ;
F_26 ( & V_28 -> V_68 , V_24 ) ;
V_28 -> V_24 &= ~ V_64 ;
V_28 -> V_60 = NULL ;
V_28 -> V_67 = 0 ;
F_28 ( & V_28 -> V_68 , V_24 ) ;
F_52 ( & V_28 -> V_66 ) ;
}
static void F_72 ( struct V_59 * V_60 , char V_140 )
{
F_9 ( 0 , L_29 , V_6 ) ;
}
void F_83 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
F_74 ( V_28 -> V_48 , V_123 ) ;
}
static void F_84 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = (struct V_27 * ) V_60 -> V_105 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_74 ( V_28 -> V_48 , V_90 ) ;
}
void F_85 ( struct V_27 * V_28 )
{
struct V_59 * V_60 ;
int V_141 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_60 = V_28 -> V_60 ;
V_141 = V_28 -> V_71 . V_82 ;
if ( V_141 & V_142 ) {
}
if ( ( V_28 -> V_24 & V_143 ) && ( V_141 & V_144 ) ) {
F_9 ( 2 ,
L_30 , V_6 , V_28 -> line ,
( V_141 & V_83 ) ? L_31 : L_32 ) ;
if ( V_141 & V_83 ) {
F_52 ( & V_28 -> V_66 ) ;
} else {
F_9 ( 2 ,
L_33 , V_6 ) ;
if ( V_60 )
F_86 ( V_60 ) ;
return;
}
}
if ( V_28 -> V_24 & V_145 ) {
if ( V_60 -> V_124 ) {
if ( V_141 & V_110 ) {
F_9 ( 2 ,
L_34 , V_6 ) ;
V_60 -> V_124 = 0 ;
F_52 ( & V_28 -> V_66 ) ;
F_54 ( & V_28 -> V_91 ) ;
return;
}
} else {
if ( ! ( V_141 & V_110 ) ) {
F_9 ( 2 ,
L_35 , V_6 ) ;
V_60 -> V_124 = 1 ;
}
}
}
}
static int V_36 ( void * V_47 , void * V_146 ,
struct V_120 * V_121 )
{
struct V_27 * V_28 = (struct V_27 * ) V_47 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_10 (skb != NULL, return -1;) ;
if ( ! V_28 -> V_60 ) {
F_9 ( 0 , L_36 , V_6 ) ;
return 0 ;
}
if ( V_28 -> V_60 -> V_124 && ( V_28 -> V_89 == V_123 ) ) {
F_9 ( 0 , L_37 , V_6 ) ;
F_29 ( V_28 , V_147 , TRUE ) ;
F_87 ( V_28 ) ;
F_88 ( V_28 ) ;
}
F_89 ( V_28 -> V_60 , V_121 -> V_148 , V_121 -> V_129 ) ;
F_90 ( V_28 -> V_60 ) ;
return 0 ;
}
static int V_38 ( void * V_47 , void * V_146 ,
struct V_120 * V_121 )
{
struct V_27 * V_28 = (struct V_27 * ) V_47 ;
int V_149 ;
F_9 ( 4 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_10 (skb != NULL, return -1;) ;
V_149 = V_121 -> V_148 [ 0 ] ;
F_91 ( V_28 , V_121 -> V_148 + 1 , F_67 ( V_121 -> V_129 - 1 , V_149 ) ,
& V_150 ) ;
return 0 ;
}
static void V_40 ( void * V_47 , void * V_146 ,
T_4 V_151 )
{
struct V_27 * V_28 = (struct V_27 * ) V_47 ;
struct V_59 * V_60 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_60 = V_28 -> V_60 ;
switch ( V_151 ) {
case V_123 :
F_9 ( 2 , L_38 , V_6 ) ;
V_60 -> V_124 = 0 ;
F_54 ( & V_28 -> V_91 ) ;
break;
default:
case V_90 :
F_9 ( 2 , L_39 , V_6 ) ;
V_60 -> V_124 = 1 ;
break;
}
V_28 -> V_89 = V_151 ;
}
static void F_92 ( struct V_27 * V_28 , struct V_152 * V_153 )
{
char V_154 ;
F_93 ( V_153 , L_40 , V_155 [ V_28 -> V_76 ] ) ;
F_94 ( V_153 , L_41 ) ;
if ( V_28 -> V_49 & V_109 )
F_94 ( V_153 , L_42 ) ;
else if ( V_28 -> V_49 & V_108 )
F_94 ( V_153 , L_43 ) ;
else if ( V_28 -> V_49 & V_113 )
F_94 ( V_153 , L_44 ) ;
else
F_94 ( V_153 , L_45 ) ;
F_95 ( V_153 , '\n' ) ;
F_93 ( V_153 , L_46 , V_28 -> V_71 . V_156 ) ;
F_93 ( V_153 , L_47 ) ;
V_154 = ' ' ;
if ( V_28 -> V_71 . V_72 & V_73 ) {
F_93 ( V_153 , L_48 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_72 & V_74 ) {
F_93 ( V_153 , L_49 , V_154 ) ;
V_154 = '|' ;
}
F_95 ( V_153 , '\n' ) ;
F_94 ( V_153 , L_50 ) ;
V_154 = ' ' ;
if ( V_28 -> V_71 . V_82 & V_110 ) {
F_93 ( V_153 , L_51 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_82 & V_111 ) {
F_93 ( V_153 , L_52 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_82 & V_83 ) {
F_93 ( V_153 , L_53 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_82 & V_112 ) {
F_93 ( V_153 , L_54 , V_154 ) ;
V_154 = '|' ;
}
F_95 ( V_153 , '\n' ) ;
F_94 ( V_153 , L_55 ) ;
if ( ! V_28 -> V_71 . V_157 )
F_94 ( V_153 , L_56 ) ;
else
F_94 ( V_153 , L_57 ) ;
F_93 ( V_153 , L_58 , V_28 -> V_71 . V_158 ) ;
F_94 ( V_153 , L_59 ) ;
V_154 = ' ' ;
if ( V_28 -> V_71 . V_159 & V_160 ) {
F_93 ( V_153 , L_60 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_161 ) {
F_93 ( V_153 , L_61 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_162 ) {
F_93 ( V_153 , L_62 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_163 ) {
F_93 ( V_153 , L_63 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_164 ) {
F_93 ( V_153 , L_64 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_165 ) {
F_93 ( V_153 , L_65 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_166 ) {
F_93 ( V_153 , L_66 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_71 . V_159 & V_167 ) {
F_93 ( V_153 , L_67 , V_154 ) ;
V_154 = '|' ;
}
F_95 ( V_153 , '\n' ) ;
F_94 ( V_153 , L_68 ) ;
V_154 = ' ' ;
if ( V_28 -> V_24 & V_145 ) {
F_93 ( V_153 , L_69 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_24 & V_143 ) {
F_93 ( V_153 , L_70 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_24 & V_168 ) {
F_93 ( V_153 , L_71 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_24 & V_107 ) {
F_93 ( V_153 , L_72 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_24 & V_117 ) {
F_93 ( V_153 , L_73 , V_154 ) ;
V_154 = '|' ;
}
if ( V_28 -> V_24 & V_64 ) {
F_93 ( V_153 , L_74 , V_154 ) ;
V_154 = '|' ;
}
F_95 ( V_153 , '\n' ) ;
F_93 ( V_153 , L_75 , V_28 -> V_169 ? L_76 : L_77 ) ;
F_93 ( V_153 , L_78 , V_28 -> V_67 ) ;
F_93 ( V_153 , L_79 , V_28 -> V_95 ) ;
F_93 ( V_153 , L_80 , V_28 -> V_93 ) ;
if ( V_28 -> V_60 )
F_93 ( V_153 , L_81 ,
V_28 -> V_60 -> V_124 ? L_82 : L_83 ) ;
}
static int F_96 ( struct V_152 * V_153 , void * V_170 )
{
struct V_27 * V_28 ;
unsigned long V_24 ;
F_26 ( & V_4 -> V_171 , V_24 ) ;
V_28 = (struct V_27 * ) F_97 ( V_4 ) ;
while ( V_28 != NULL ) {
if ( V_28 -> V_29 != V_88 )
break;
F_92 ( V_28 , V_153 ) ;
V_28 = (struct V_27 * ) F_98 ( V_4 ) ;
}
F_28 ( & V_4 -> V_171 , V_24 ) ;
return 0 ;
}
static int F_99 ( struct V_172 * V_172 , struct V_52 * V_52 )
{
return F_100 ( V_52 , F_96 , NULL ) ;
}
