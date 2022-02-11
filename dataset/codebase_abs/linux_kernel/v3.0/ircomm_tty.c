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
V_1 -> V_7 = V_8 ;
V_1 -> V_9 = L_2 ;
V_1 -> V_10 = L_2 ;
V_1 -> V_11 = V_12 ;
V_1 -> V_13 = V_14 ;
V_1 -> type = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_18 . V_20 = V_21 | V_22 | V_23 | V_24 | V_25 ;
V_1 -> V_26 = V_27 ;
F_6 ( V_1 , & V_28 ) ;
if ( F_7 ( V_1 ) ) {
F_4 ( L_3 ,
V_6 ) ;
F_5 ( V_1 ) ;
return - 1 ;
}
return 0 ;
}
static void T_2 F_8 ( struct V_29 * V_30 )
{
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_11 ( V_30 ) ;
V_30 -> V_31 = 0 ;
F_12 ( V_30 ) ;
}
static void T_2 F_13 ( void )
{
int V_32 ;
F_9 ( 4 , L_4 , V_6 ) ;
V_32 = F_14 ( V_1 ) ;
if ( V_32 ) {
F_4 ( L_5 ,
V_6 ) ;
return;
}
F_15 ( V_4 , ( V_33 ) F_8 ) ;
F_5 ( V_1 ) ;
}
static int F_16 ( struct V_29 * V_30 )
{
T_3 V_34 ;
int V_32 = - V_35 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_17 ( V_36 , & V_30 -> V_26 ) ) {
F_9 ( 2 , L_6 , V_6 ) ;
return 0 ;
}
F_18 ( & V_34 ) ;
V_34 . V_37 = V_38 ;
V_34 . V_39 = V_40 ;
V_34 . V_41 = V_42 ;
V_34 . V_43 = V_44 ;
V_34 . V_45 = V_46 ;
V_34 . V_47 = V_48 ;
F_19 ( V_34 . V_10 , L_7 , sizeof( V_34 . V_10 ) ) ;
V_34 . V_49 = V_30 ;
if ( ! V_30 -> V_50 ) {
V_30 -> V_50 = F_20 ( & V_34 , V_30 -> V_51 ,
V_30 -> line ) ;
}
if ( ! V_30 -> V_50 )
goto V_52;
V_30 -> V_53 = V_30 -> V_50 -> V_53 ;
V_32 = F_21 ( V_30 ) ;
if ( V_32 < 0 ) {
F_4 ( L_8 , V_6 ) ;
goto V_52;
}
return 0 ;
V_52:
F_22 ( V_36 , & V_30 -> V_26 ) ;
return V_32 ;
}
static int F_23 ( struct V_29 * V_30 ,
struct V_54 * V_55 )
{
F_24 ( V_56 , V_57 ) ;
int V_58 ;
int V_59 = 0 , V_60 = 0 ;
unsigned long V_26 ;
struct V_61 * V_62 ;
F_9 ( 2 , L_4 , V_6 ) ;
V_62 = V_30 -> V_62 ;
if ( V_55 -> V_63 & V_64 || V_62 -> V_26 & ( 1 << V_65 ) ) {
V_30 -> V_26 |= V_66 ;
F_9 ( 1 , L_9 , V_6 ) ;
return 0 ;
}
if ( V_62 -> V_67 -> V_20 & V_25 ) {
F_9 ( 1 , L_10 , V_6 ) ;
V_59 = 1 ;
}
V_58 = 0 ;
F_25 ( & V_30 -> V_68 , & V_56 ) ;
F_9 ( 2 , L_11 ,
__FILE__ , __LINE__ , V_62 -> V_1 -> V_10 , V_30 -> V_69 ) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
if ( ! F_27 ( V_55 ) ) {
V_60 = 1 ;
V_30 -> V_69 -- ;
}
F_28 ( & V_30 -> V_70 , V_26 ) ;
V_30 -> V_71 ++ ;
while ( 1 ) {
if ( V_62 -> V_67 -> V_20 & V_72 ) {
V_30 -> V_73 . V_74 |= V_75 + V_76 ;
F_29 ( V_30 , V_77 , TRUE ) ;
}
V_57 -> V_78 = V_79 ;
if ( F_27 ( V_55 ) ||
! F_30 ( V_36 , & V_30 -> V_26 ) ) {
V_58 = ( V_30 -> V_26 & V_80 ) ?
- V_81 : - V_82 ;
break;
}
if ( ! F_30 ( V_83 , & V_30 -> V_26 ) &&
( V_59 || ( V_30 -> V_73 . V_84 & V_85 ) ) &&
V_30 -> V_78 == V_86 )
{
break;
}
if ( F_31 ( V_57 ) ) {
V_58 = - V_82 ;
break;
}
F_9 ( 1 , L_12 ,
__FILE__ , __LINE__ , V_62 -> V_1 -> V_10 , V_30 -> V_69 ) ;
F_32 () ;
}
F_33 ( V_87 ) ;
F_34 ( & V_30 -> V_68 , & V_56 ) ;
if ( V_60 ) {
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_30 -> V_69 ++ ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
}
V_30 -> V_71 -- ;
F_9 ( 1 , L_13 ,
__FILE__ , __LINE__ , V_62 -> V_1 -> V_10 , V_30 -> V_69 ) ;
if ( ! V_58 )
V_30 -> V_26 |= V_66 ;
return V_58 ;
}
static int F_35 ( struct V_61 * V_62 , struct V_54 * V_55 )
{
struct V_29 * V_30 ;
unsigned int line ;
unsigned long V_26 ;
int V_32 ;
F_9 ( 2 , L_4 , V_6 ) ;
line = V_62 -> V_88 ;
if ( line >= V_2 )
return - V_35 ;
V_30 = F_36 ( V_4 , line , NULL ) ;
if ( ! V_30 ) {
V_30 = F_37 ( sizeof( struct V_29 ) , V_89 ) ;
if ( V_30 == NULL ) {
F_4 ( L_14 , V_6 ) ;
return - V_3 ;
}
V_30 -> V_31 = V_90 ;
V_30 -> V_91 = V_92 ;
V_30 -> line = line ;
F_38 ( & V_30 -> V_93 , V_94 ) ;
V_30 -> V_95 = V_96 ;
V_30 -> V_97 = V_98 ;
V_30 -> V_99 = 5 * V_100 / 10 ;
V_30 -> V_101 = 30 * V_100 ;
F_39 ( & V_30 -> V_102 ) ;
F_40 ( & V_30 -> V_68 ) ;
F_40 ( & V_30 -> V_103 ) ;
F_41 ( & V_30 -> V_70 ) ;
V_62 -> V_67 -> V_104 = 0 ;
V_62 -> V_67 -> V_105 = 0 ;
F_42 ( V_4 , ( V_106 * ) V_30 , line , NULL ) ;
}
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_30 -> V_69 ++ ;
V_62 -> V_107 = V_30 ;
V_30 -> V_62 = V_62 ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_9 ( 1 , L_15 , V_6 , V_62 -> V_1 -> V_10 ,
V_30 -> line , V_30 -> V_69 ) ;
V_30 -> V_62 -> V_108 = ( V_30 -> V_26 & V_109 ) ? 1 : 0 ;
if ( F_27 ( V_55 ) ||
F_30 ( V_83 , & V_30 -> V_26 ) ) {
if ( F_43 ( V_30 -> V_103 , ! F_30 ( V_83 , & V_30 -> V_26 ) ) ) {
F_44 ( L_16 ,
V_6 ) ;
return - V_82 ;
}
#ifdef F_45
return ( V_30 -> V_26 & V_80 ) ?
- V_81 : - V_82 ;
#else
return - V_81 ;
#endif
}
if ( line < 0x10 ) {
V_30 -> V_51 = V_110 | V_111 ;
V_30 -> V_73 . V_51 = V_111 ;
V_30 -> V_73 . V_84 = V_112 | V_85 | V_113 | V_114 ;
F_9 ( 2 , L_17 , V_6 ) ;
} else {
F_9 ( 2 , L_18 , V_6 ) ;
V_30 -> V_51 = V_115 ;
V_30 -> V_73 . V_51 = V_115 ;
}
V_32 = F_16 ( V_30 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_23 ( V_30 , V_55 ) ;
if ( V_32 ) {
F_9 ( 2 ,
L_19 , V_6 ,
V_32 ) ;
return V_32 ;
}
return 0 ;
}
static void F_46 ( struct V_61 * V_62 , struct V_54 * V_55 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_26 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
if ( F_27 ( V_55 ) ) {
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_9 ( 0 , L_20 , V_6 ) ;
return;
}
if ( ( V_62 -> V_116 == 1 ) && ( V_30 -> V_69 != 1 ) ) {
F_9 ( 0 , L_21
L_22 , V_6 ,
V_30 -> V_69 ) ;
V_30 -> V_69 = 1 ;
}
if ( -- V_30 -> V_69 < 0 ) {
F_4 ( L_23 ,
V_6 , V_30 -> line , V_30 -> V_69 ) ;
V_30 -> V_69 = 0 ;
}
if ( V_30 -> V_69 ) {
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_9 ( 0 , L_24 , V_6 ) ;
return;
}
F_47 ( V_83 , & V_30 -> V_26 ) ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
V_62 -> V_117 = 1 ;
if ( V_30 -> V_101 != V_118 )
F_48 ( V_62 , V_30 -> V_101 ) ;
F_11 ( V_30 ) ;
F_49 ( V_62 ) ;
F_50 ( V_62 ) ;
V_62 -> V_117 = 0 ;
V_30 -> V_62 = NULL ;
if ( V_30 -> V_71 ) {
if ( V_30 -> V_99 )
F_51 ( V_30 -> V_99 ) ;
F_52 ( & V_30 -> V_68 ) ;
}
V_30 -> V_26 &= ~ ( V_66 | V_119 ) ;
F_52 ( & V_30 -> V_103 ) ;
}
static void F_53 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_54 ( & V_30 -> V_93 ) ;
}
static void V_94 ( struct V_120 * V_121 )
{
struct V_29 * V_30 =
F_55 ( V_121 , struct V_29 , V_93 ) ;
struct V_61 * V_62 ;
unsigned long V_26 ;
struct V_122 * V_123 , * V_124 ;
F_9 ( 2 , L_4 , V_6 ) ;
if ( ! V_30 || V_30 -> V_31 != V_90 )
return;
V_62 = V_30 -> V_62 ;
if ( ! V_62 )
return;
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_124 = V_30 -> V_124 ;
V_30 -> V_124 = NULL ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
if( V_124 ) {
if( V_30 -> V_91 == V_125 )
F_56 ( V_30 -> V_50 , V_124 ) ;
F_57 ( V_124 ) ;
}
if ( V_62 -> V_126 )
return;
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_123 = V_30 -> V_127 ;
V_30 -> V_127 = NULL ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
if ( V_123 ) {
F_58 ( V_30 , V_128 , V_123 , NULL ) ;
F_57 ( V_123 ) ;
}
F_59 ( V_62 ) ;
}
static int F_60 ( struct V_61 * V_62 ,
const unsigned char * V_129 , int V_116 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_26 ;
struct V_122 * V_123 ;
int V_130 = 0 ;
int V_131 = 0 ;
int V_132 ;
F_9 ( 2 , L_25 , V_6 , V_116 ,
V_62 -> V_126 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_30 -> V_95 == V_96 ) {
F_9 ( 1 , L_26 , V_6 ) ;
#ifdef F_61
return 0 ;
#endif
}
if ( V_116 < 1 )
return 0 ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_123 = V_30 -> V_127 ;
while ( V_116 ) {
V_132 = V_116 ;
if ( V_132 > V_30 -> V_97 )
V_132 = V_30 -> V_97 ;
if ( V_123 ) {
if ( ( V_130 = ( V_30 -> V_133 - V_123 -> V_131 ) ) > 0 ) {
if ( V_132 > V_130 )
V_132 = V_130 ;
} else {
break;
}
} else {
V_123 = F_62 ( V_30 -> V_97 +
V_30 -> V_95 ,
V_134 ) ;
if ( ! V_123 ) {
F_28 ( & V_30 -> V_70 , V_26 ) ;
return - V_135 ;
}
F_63 ( V_123 , V_30 -> V_95 ) ;
V_30 -> V_127 = V_123 ;
V_30 -> V_133 = V_30 -> V_97 ;
}
memcpy ( F_64 ( V_123 , V_132 ) , V_129 + V_131 , V_132 ) ;
V_116 -= V_132 ;
V_131 += V_132 ;
}
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_54 ( & V_30 -> V_93 ) ;
return V_131 ;
}
static int F_65 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_26 ;
int V_32 ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_61
if ( V_30 -> V_95 == V_96 )
return 0 ;
#endif
if ( V_62 -> V_126 )
V_32 = 0 ;
else {
F_26 ( & V_30 -> V_70 , V_26 ) ;
if ( V_30 -> V_127 )
V_32 = V_30 -> V_133 - V_30 -> V_127 -> V_131 ;
else
V_32 = V_30 -> V_97 ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
}
F_9 ( 2 , L_27 , V_6 , V_32 ) ;
return V_32 ;
}
static void F_66 ( struct V_61 * V_62 , int V_136 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_137 , V_138 ;
unsigned long V_26 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_137 = V_139 ;
V_138 = F_67 ( V_136 , F_68 ( 200 ) ) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
while ( V_30 -> V_127 && V_30 -> V_127 -> V_131 ) {
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_51 ( V_138 ) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
if ( F_31 ( V_57 ) )
break;
if ( V_136 && F_69 ( V_139 , V_137 + V_136 ) )
break;
}
F_28 ( & V_30 -> V_70 , V_26 ) ;
V_57 -> V_78 = V_87 ;
}
static void F_70 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_71 ( V_62 ) )
F_72 ( V_62 , F_73 ( V_62 ) ) ;
if ( V_62 -> V_67 -> V_20 & V_140 ) {
V_30 -> V_73 . V_74 &= ~ V_75 ;
V_30 -> V_73 . V_74 |= V_141 ;
F_29 ( V_30 , V_77 , TRUE ) ;
}
F_74 ( V_30 -> V_50 , V_92 ) ;
}
static void F_75 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_71 ( V_62 ) ) {
F_72 ( V_62 , F_76 ( V_62 ) ) ;
}
if ( V_62 -> V_67 -> V_20 & V_140 ) {
V_30 -> V_73 . V_74 |= ( V_75 | V_141 ) ;
F_29 ( V_30 , V_77 , TRUE ) ;
F_9 ( 1 , L_28 , V_6 ) ;
}
F_74 ( V_30 -> V_50 , V_125 ) ;
}
static int F_77 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_26 ;
int V_131 = 0 ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
if ( V_30 -> V_127 )
V_131 = V_30 -> V_127 -> V_131 ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
return V_131 ;
}
static void F_11 ( struct V_29 * V_30 )
{
unsigned long V_26 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_9 ( 0 , L_4 , V_6 ) ;
if ( ! F_78 ( V_36 , & V_30 -> V_26 ) )
return;
F_79 ( V_30 ) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
F_80 ( & V_30 -> V_102 ) ;
if ( V_30 -> V_124 ) {
F_57 ( V_30 -> V_124 ) ;
V_30 -> V_124 = NULL ;
}
if ( V_30 -> V_127 ) {
F_57 ( V_30 -> V_127 ) ;
V_30 -> V_127 = NULL ;
}
if ( V_30 -> V_50 ) {
F_81 ( V_30 -> V_50 ) ;
V_30 -> V_50 = NULL ;
}
F_28 ( & V_30 -> V_70 , V_26 ) ;
}
static void F_82 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
unsigned long V_26 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_11 ( V_30 ) ;
F_26 ( & V_30 -> V_70 , V_26 ) ;
V_30 -> V_26 &= ~ V_66 ;
V_30 -> V_62 = NULL ;
V_30 -> V_69 = 0 ;
F_28 ( & V_30 -> V_70 , V_26 ) ;
F_52 ( & V_30 -> V_68 ) ;
}
static void F_72 ( struct V_61 * V_62 , char V_142 )
{
F_9 ( 0 , L_29 , V_6 ) ;
}
void F_83 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
F_74 ( V_30 -> V_50 , V_125 ) ;
}
static void F_84 ( struct V_61 * V_62 )
{
struct V_29 * V_30 = (struct V_29 * ) V_62 -> V_107 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_74 ( V_30 -> V_50 , V_92 ) ;
}
void F_85 ( struct V_29 * V_30 )
{
struct V_61 * V_62 ;
int V_143 ;
F_9 ( 0 , L_4 , V_6 ) ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = V_30 -> V_62 ;
V_143 = V_30 -> V_73 . V_84 ;
if ( V_143 & V_144 ) {
}
if ( ( V_30 -> V_26 & V_145 ) && ( V_143 & V_146 ) ) {
F_9 ( 2 ,
L_30 , V_6 , V_30 -> line ,
( V_143 & V_85 ) ? L_31 : L_32 ) ;
if ( V_143 & V_85 ) {
F_52 ( & V_30 -> V_68 ) ;
} else {
F_9 ( 2 ,
L_33 , V_6 ) ;
if ( V_62 )
F_86 ( V_62 ) ;
return;
}
}
if ( V_30 -> V_26 & V_147 ) {
if ( V_62 -> V_126 ) {
if ( V_143 & V_112 ) {
F_9 ( 2 ,
L_34 , V_6 ) ;
V_62 -> V_126 = 0 ;
F_52 ( & V_30 -> V_68 ) ;
F_54 ( & V_30 -> V_93 ) ;
return;
}
} else {
if ( ! ( V_143 & V_112 ) ) {
F_9 ( 2 ,
L_35 , V_6 ) ;
V_62 -> V_126 = 1 ;
}
}
}
}
static int V_38 ( void * V_49 , void * V_148 ,
struct V_122 * V_123 )
{
struct V_29 * V_30 = (struct V_29 * ) V_49 ;
F_9 ( 2 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_10 (skb != NULL, return -1;) ;
if ( ! V_30 -> V_62 ) {
F_9 ( 0 , L_36 , V_6 ) ;
return 0 ;
}
if ( V_30 -> V_62 -> V_126 && ( V_30 -> V_91 == V_125 ) ) {
F_9 ( 0 , L_37 , V_6 ) ;
F_29 ( V_30 , V_149 , TRUE ) ;
F_87 ( V_30 ) ;
F_88 ( V_30 ) ;
}
F_89 ( V_30 -> V_62 , V_123 -> V_150 , V_123 -> V_131 ) ;
F_90 ( V_30 -> V_62 ) ;
return 0 ;
}
static int V_40 ( void * V_49 , void * V_148 ,
struct V_122 * V_123 )
{
struct V_29 * V_30 = (struct V_29 * ) V_49 ;
int V_151 ;
F_9 ( 4 , L_4 , V_6 ) ;
F_10 (self != NULL, return -1;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_10 (skb != NULL, return -1;) ;
V_151 = V_123 -> V_150 [ 0 ] ;
F_91 ( V_30 , V_123 -> V_150 + 1 , F_67 ( V_123 -> V_131 - 1 , V_151 ) ,
& V_152 ) ;
return 0 ;
}
static void V_42 ( void * V_49 , void * V_148 ,
T_4 V_153 )
{
struct V_29 * V_30 = (struct V_29 * ) V_49 ;
struct V_61 * V_62 ;
F_10 (self != NULL, return;) ;
F_10 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = V_30 -> V_62 ;
switch ( V_153 ) {
case V_125 :
F_9 ( 2 , L_38 , V_6 ) ;
V_62 -> V_126 = 0 ;
F_54 ( & V_30 -> V_93 ) ;
break;
default:
case V_92 :
F_9 ( 2 , L_39 , V_6 ) ;
V_62 -> V_126 = 1 ;
break;
}
V_30 -> V_91 = V_153 ;
}
static void F_92 ( struct V_29 * V_30 , struct V_154 * V_155 )
{
char V_156 ;
F_93 ( V_155 , L_40 , V_157 [ V_30 -> V_78 ] ) ;
F_94 ( V_155 , L_41 ) ;
if ( V_30 -> V_51 & V_111 )
F_94 ( V_155 , L_42 ) ;
else if ( V_30 -> V_51 & V_110 )
F_94 ( V_155 , L_43 ) ;
else if ( V_30 -> V_51 & V_115 )
F_94 ( V_155 , L_44 ) ;
else
F_94 ( V_155 , L_45 ) ;
F_95 ( V_155 , '\n' ) ;
F_93 ( V_155 , L_46 , V_30 -> V_73 . V_158 ) ;
F_93 ( V_155 , L_47 ) ;
V_156 = ' ' ;
if ( V_30 -> V_73 . V_74 & V_75 ) {
F_93 ( V_155 , L_48 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_74 & V_76 ) {
F_93 ( V_155 , L_49 , V_156 ) ;
V_156 = '|' ;
}
F_95 ( V_155 , '\n' ) ;
F_94 ( V_155 , L_50 ) ;
V_156 = ' ' ;
if ( V_30 -> V_73 . V_84 & V_112 ) {
F_93 ( V_155 , L_51 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_84 & V_113 ) {
F_93 ( V_155 , L_52 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_84 & V_85 ) {
F_93 ( V_155 , L_53 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_84 & V_114 ) {
F_93 ( V_155 , L_54 , V_156 ) ;
V_156 = '|' ;
}
F_95 ( V_155 , '\n' ) ;
F_94 ( V_155 , L_55 ) ;
if ( ! V_30 -> V_73 . V_159 )
F_94 ( V_155 , L_56 ) ;
else
F_94 ( V_155 , L_57 ) ;
F_93 ( V_155 , L_58 , V_30 -> V_73 . V_160 ) ;
F_94 ( V_155 , L_59 ) ;
V_156 = ' ' ;
if ( V_30 -> V_73 . V_161 & V_162 ) {
F_93 ( V_155 , L_60 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_163 ) {
F_93 ( V_155 , L_61 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_164 ) {
F_93 ( V_155 , L_62 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_165 ) {
F_93 ( V_155 , L_63 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_166 ) {
F_93 ( V_155 , L_64 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_167 ) {
F_93 ( V_155 , L_65 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_168 ) {
F_93 ( V_155 , L_66 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_73 . V_161 & V_169 ) {
F_93 ( V_155 , L_67 , V_156 ) ;
V_156 = '|' ;
}
F_95 ( V_155 , '\n' ) ;
F_94 ( V_155 , L_68 ) ;
V_156 = ' ' ;
if ( V_30 -> V_26 & V_147 ) {
F_93 ( V_155 , L_69 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_26 & V_145 ) {
F_93 ( V_155 , L_70 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_26 & V_170 ) {
F_93 ( V_155 , L_71 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_26 & V_109 ) {
F_93 ( V_155 , L_72 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_26 & V_119 ) {
F_93 ( V_155 , L_73 , V_156 ) ;
V_156 = '|' ;
}
if ( V_30 -> V_26 & V_66 ) {
F_93 ( V_155 , L_74 , V_156 ) ;
V_156 = '|' ;
}
F_95 ( V_155 , '\n' ) ;
F_93 ( V_155 , L_75 , V_30 -> V_171 ? L_76 : L_77 ) ;
F_93 ( V_155 , L_78 , V_30 -> V_69 ) ;
F_93 ( V_155 , L_79 , V_30 -> V_97 ) ;
F_93 ( V_155 , L_80 , V_30 -> V_95 ) ;
if ( V_30 -> V_62 )
F_93 ( V_155 , L_81 ,
V_30 -> V_62 -> V_126 ? L_82 : L_83 ) ;
}
static int F_96 ( struct V_154 * V_155 , void * V_172 )
{
struct V_29 * V_30 ;
unsigned long V_26 ;
F_26 ( & V_4 -> V_173 , V_26 ) ;
V_30 = (struct V_29 * ) F_97 ( V_4 ) ;
while ( V_30 != NULL ) {
if ( V_30 -> V_31 != V_90 )
break;
F_92 ( V_30 , V_155 ) ;
V_30 = (struct V_29 * ) F_98 ( V_4 ) ;
}
F_28 ( & V_4 -> V_173 , V_26 ) ;
return 0 ;
}
static int F_99 ( struct V_174 * V_174 , struct V_54 * V_54 )
{
return F_100 ( V_54 , F_96 , NULL ) ;
}
