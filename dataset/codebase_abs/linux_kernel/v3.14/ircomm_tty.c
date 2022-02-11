static void F_1 ( struct V_1 * V_2 , int raise )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
if ( raise )
V_4 -> V_5 . V_6 |= V_7 | V_8 ;
else
V_4 -> V_5 . V_6 &= ~ ( V_7 | V_8 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
return V_4 -> V_5 . V_10 & V_11 ;
}
static int T_1 F_5 ( void )
{
V_12 = F_6 ( V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_15 = F_7 ( V_16 ) ;
if ( V_15 == NULL ) {
F_8 ( L_1 , V_17 ) ;
F_9 ( V_12 ) ;
return - V_14 ;
}
V_12 -> V_18 = L_2 ;
V_12 -> V_19 = L_2 ;
V_12 -> V_20 = V_21 ;
V_12 -> V_22 = V_23 ;
V_12 -> type = V_24 ;
V_12 -> V_25 = V_26 ;
V_12 -> V_27 = V_28 ;
V_12 -> V_27 . V_29 = V_30 | V_31 | V_32 | V_33 | V_34 ;
V_12 -> V_35 = V_36 ;
F_10 ( V_12 , & V_37 ) ;
if ( F_11 ( V_12 ) ) {
F_8 ( L_3 ,
V_17 ) ;
F_9 ( V_12 ) ;
return - 1 ;
}
return 0 ;
}
static void T_2 F_12 ( struct V_3 * V_4 )
{
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_15 ( V_4 ) ;
V_4 -> V_38 = 0 ;
F_16 ( & V_4 -> V_2 ) ;
F_17 ( V_4 ) ;
}
static void T_2 F_18 ( void )
{
int V_39 ;
F_13 ( 4 , L_4 , V_17 ) ;
V_39 = F_19 ( V_12 ) ;
if ( V_39 ) {
F_8 ( L_5 ,
V_17 ) ;
return;
}
F_20 ( V_15 , ( V_40 ) F_12 ) ;
F_9 ( V_12 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
T_3 V_41 ;
int V_39 = - V_42 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_22 ( V_43 , & V_4 -> V_2 . V_35 ) ) {
F_13 ( 2 , L_6 , V_17 ) ;
return 0 ;
}
F_23 ( & V_41 ) ;
V_41 . V_44 = V_45 ;
V_41 . V_46 = V_47 ;
V_41 . V_48 = V_49 ;
V_41 . V_50 = V_51 ;
V_41 . V_52 = V_53 ;
V_41 . V_54 = V_55 ;
F_24 ( V_41 . V_19 , L_7 , sizeof( V_41 . V_19 ) ) ;
V_41 . V_56 = V_4 ;
if ( ! V_4 -> V_57 ) {
V_4 -> V_57 = F_25 ( & V_41 , V_4 -> V_58 ,
V_4 -> line ) ;
}
if ( ! V_4 -> V_57 )
goto V_59;
V_4 -> V_60 = V_4 -> V_57 -> V_60 ;
V_39 = F_26 ( V_4 ) ;
if ( V_39 < 0 ) {
F_8 ( L_8 , V_17 ) ;
goto V_59;
}
return 0 ;
V_59:
F_27 ( V_43 , & V_4 -> V_2 . V_35 ) ;
return V_39 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_29 ( V_65 , V_66 ) ;
int V_67 ;
int V_68 = 0 ;
unsigned long V_35 ;
F_13 ( 2 , L_4 , V_17 ) ;
if ( F_30 ( V_69 , & V_62 -> V_35 ) ) {
V_2 -> V_35 |= V_70 ;
return 0 ;
}
if ( V_64 -> V_71 & V_72 ) {
if ( V_62 -> V_73 . V_29 & V_74 )
F_31 ( V_2 ) ;
V_2 -> V_35 |= V_70 ;
F_13 ( 1 , L_9 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_73 . V_29 & V_34 ) {
F_13 ( 1 , L_10 , V_17 ) ;
V_68 = 1 ;
}
V_67 = 0 ;
F_32 ( & V_2 -> V_75 , & V_65 ) ;
F_13 ( 2 , L_11 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
if ( ! F_34 ( V_64 ) )
V_2 -> V_76 -- ;
V_2 -> V_78 ++ ;
F_35 ( & V_2 -> V_77 , V_35 ) ;
while ( 1 ) {
if ( F_36 ( V_62 ) && F_30 ( V_43 , & V_2 -> V_35 ) )
F_31 ( V_2 ) ;
F_37 ( V_79 ) ;
if ( F_34 ( V_64 ) ||
! F_30 ( V_43 , & V_2 -> V_35 ) ) {
V_67 = ( V_2 -> V_35 & V_80 ) ?
- V_81 : - V_82 ;
break;
}
if ( ! F_30 ( V_83 , & V_2 -> V_35 ) &&
( V_68 || F_38 ( V_2 ) ) &&
V_4 -> V_84 == V_85 )
{
break;
}
if ( F_39 ( V_66 ) ) {
V_67 = - V_82 ;
break;
}
F_13 ( 1 , L_12 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_40 () ;
}
F_41 ( V_86 ) ;
F_42 ( & V_2 -> V_75 , & V_65 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
if ( ! F_34 ( V_64 ) )
V_2 -> V_76 ++ ;
V_2 -> V_78 -- ;
F_35 ( & V_2 -> V_77 , V_35 ) ;
F_13 ( 1 , L_13 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
if ( ! V_67 )
V_2 -> V_35 |= V_70 ;
return V_67 ;
}
static int F_43 ( struct V_87 * V_12 , struct V_61 * V_62 )
{
struct V_3 * V_4 ;
unsigned int line = V_62 -> V_88 ;
V_4 = F_44 ( V_15 , line , NULL ) ;
if ( ! V_4 ) {
V_4 = F_45 ( sizeof( struct V_3 ) , V_89 ) ;
if ( V_4 == NULL ) {
F_8 ( L_14 , V_17 ) ;
return - V_14 ;
}
F_46 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_37 = & V_90 ;
V_4 -> V_38 = V_91 ;
V_4 -> V_92 = V_93 ;
V_4 -> line = line ;
F_47 ( & V_4 -> V_94 , V_95 ) ;
V_4 -> V_96 = V_97 ;
V_4 -> V_98 = V_99 ;
F_48 ( & V_4 -> V_100 ) ;
F_49 ( & V_4 -> V_101 ) ;
V_62 -> V_73 . V_102 = 0 ;
V_62 -> V_73 . V_103 = 0 ;
F_50 ( V_15 , ( V_104 * ) V_4 , line , NULL ) ;
}
V_62 -> V_105 = V_4 ;
return F_51 ( & V_4 -> V_2 , V_12 , V_62 ) ;
}
static int F_52 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = V_62 -> V_105 ;
unsigned long V_35 ;
int V_39 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_33 ( & V_4 -> V_2 . V_77 , V_35 ) ;
V_4 -> V_2 . V_76 ++ ;
F_35 ( & V_4 -> V_2 . V_77 , V_35 ) ;
F_53 ( & V_4 -> V_2 , V_62 ) ;
F_13 ( 1 , L_15 , V_17 , V_62 -> V_12 -> V_19 ,
V_4 -> line , V_4 -> V_2 . V_76 ) ;
V_4 -> V_2 . V_106 = ( V_4 -> V_2 . V_35 & V_107 ) ? 1 : 0 ;
if ( F_34 ( V_64 ) ||
F_30 ( V_83 , & V_4 -> V_2 . V_35 ) ) {
if ( F_54 ( V_4 -> V_2 . V_108 ,
! F_30 ( V_83 , & V_4 -> V_2 . V_35 ) ) ) {
F_55 ( L_16 ,
V_17 ) ;
return - V_82 ;
}
#ifdef F_56
return ( V_4 -> V_2 . V_35 & V_80 ) ?
- V_81 : - V_82 ;
#else
return - V_81 ;
#endif
}
if ( V_4 -> line < 0x10 ) {
V_4 -> V_58 = V_109 | V_110 ;
V_4 -> V_5 . V_58 = V_110 ;
V_4 -> V_5 . V_10 = V_111 | V_11 | V_112 | V_113 ;
F_13 ( 2 , L_17 , V_17 ) ;
} else {
F_13 ( 2 , L_18 , V_17 ) ;
V_4 -> V_58 = V_114 ;
V_4 -> V_5 . V_58 = V_114 ;
}
V_39 = F_21 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_28 ( V_4 , V_62 , V_64 ) ;
if ( V_39 ) {
F_13 ( 2 ,
L_19 , V_17 ,
V_39 ) ;
return V_39 ;
}
return 0 ;
}
static void F_57 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_58 ( V_2 , V_62 , V_64 ) == 0 )
return;
F_15 ( V_4 ) ;
F_59 ( V_62 ) ;
F_60 ( V_2 , V_62 ) ;
F_53 ( V_2 , NULL ) ;
}
static void F_61 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_62 ( & V_4 -> V_94 ) ;
}
static void V_95 ( struct V_115 * V_116 )
{
struct V_3 * V_4 =
F_2 ( V_116 , struct V_3 , V_94 ) ;
struct V_61 * V_62 ;
unsigned long V_35 ;
struct V_117 * V_118 , * V_119 ;
F_13 ( 2 , L_4 , V_17 ) ;
if ( ! V_4 || V_4 -> V_38 != V_91 )
return;
V_62 = F_63 ( & V_4 -> V_2 ) ;
if ( ! V_62 )
return;
F_33 ( & V_4 -> V_101 , V_35 ) ;
V_119 = V_4 -> V_119 ;
V_4 -> V_119 = NULL ;
F_35 ( & V_4 -> V_101 , V_35 ) ;
if( V_119 ) {
if( V_4 -> V_92 == V_120 )
F_64 ( V_4 -> V_57 , V_119 ) ;
F_65 ( V_119 ) ;
}
if ( V_62 -> V_121 )
goto V_122;
F_33 ( & V_4 -> V_101 , V_35 ) ;
V_118 = V_4 -> V_123 ;
V_4 -> V_123 = NULL ;
F_35 ( & V_4 -> V_101 , V_35 ) ;
if ( V_118 ) {
F_66 ( V_4 , V_124 , V_118 , NULL ) ;
F_65 ( V_118 ) ;
}
F_67 ( V_62 ) ;
V_122:
F_68 ( V_62 ) ;
}
static int F_69 ( struct V_61 * V_62 ,
const unsigned char * V_125 , int V_76 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
unsigned long V_35 ;
struct V_117 * V_118 ;
int V_126 = 0 ;
int V_127 = 0 ;
int V_128 ;
F_13 ( 2 , L_20 , V_17 , V_76 ,
V_62 -> V_121 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_4 -> V_96 == V_97 ) {
F_13 ( 1 , L_21 , V_17 ) ;
#ifdef F_70
return 0 ;
#endif
}
if ( V_76 < 1 )
return 0 ;
F_33 ( & V_4 -> V_101 , V_35 ) ;
V_118 = V_4 -> V_123 ;
while ( V_76 ) {
V_128 = V_76 ;
if ( V_128 > V_4 -> V_98 )
V_128 = V_4 -> V_98 ;
if ( V_118 ) {
if ( ( V_126 = ( V_4 -> V_129 - V_118 -> V_127 ) ) > 0 ) {
if ( V_128 > V_126 )
V_128 = V_126 ;
} else {
break;
}
} else {
V_118 = F_71 ( V_4 -> V_98 +
V_4 -> V_96 ,
V_130 ) ;
if ( ! V_118 ) {
F_35 ( & V_4 -> V_101 , V_35 ) ;
return - V_131 ;
}
F_72 ( V_118 , V_4 -> V_96 ) ;
V_4 -> V_123 = V_118 ;
V_4 -> V_129 = V_4 -> V_98 ;
}
memcpy ( F_73 ( V_118 , V_128 ) , V_125 + V_127 , V_128 ) ;
V_76 -= V_128 ;
V_127 += V_128 ;
}
F_35 ( & V_4 -> V_101 , V_35 ) ;
F_62 ( & V_4 -> V_94 ) ;
return V_127 ;
}
static int F_74 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
unsigned long V_35 ;
int V_39 ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_70
if ( V_4 -> V_96 == V_97 )
return 0 ;
#endif
if ( V_62 -> V_121 )
V_39 = 0 ;
else {
F_33 ( & V_4 -> V_101 , V_35 ) ;
if ( V_4 -> V_123 )
V_39 = V_4 -> V_129 - V_4 -> V_123 -> V_127 ;
else
V_39 = V_4 -> V_98 ;
F_35 ( & V_4 -> V_101 , V_35 ) ;
}
F_13 ( 2 , L_22 , V_17 , V_39 ) ;
return V_39 ;
}
static void F_75 ( struct V_61 * V_62 , int V_132 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
unsigned long V_133 , V_134 ;
unsigned long V_35 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_133 = V_135 ;
V_134 = F_76 ( V_132 , F_77 ( 200 ) ) ;
F_33 ( & V_4 -> V_101 , V_35 ) ;
while ( V_4 -> V_123 && V_4 -> V_123 -> V_127 ) {
F_35 ( & V_4 -> V_101 , V_35 ) ;
F_78 ( V_134 ) ;
F_33 ( & V_4 -> V_101 , V_35 ) ;
if ( F_39 ( V_66 ) )
break;
if ( V_132 && F_79 ( V_135 , V_133 + V_132 ) )
break;
}
F_35 ( & V_4 -> V_101 , V_35 ) ;
V_66 -> V_84 = V_86 ;
}
static void F_80 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_81 ( V_62 ) )
F_82 ( V_62 , F_83 ( V_62 ) ) ;
if ( V_62 -> V_73 . V_29 & V_136 ) {
V_4 -> V_5 . V_6 &= ~ V_7 ;
V_4 -> V_5 . V_6 |= V_137 ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
F_84 ( V_4 -> V_57 , V_93 ) ;
}
static void F_85 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_81 ( V_62 ) ) {
F_82 ( V_62 , F_86 ( V_62 ) ) ;
}
if ( V_62 -> V_73 . V_29 & V_136 ) {
V_4 -> V_5 . V_6 |= ( V_7 | V_137 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
F_13 ( 1 , L_23 , V_17 ) ;
}
F_84 ( V_4 -> V_57 , V_120 ) ;
}
static int F_87 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
unsigned long V_35 ;
int V_127 = 0 ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_33 ( & V_4 -> V_101 , V_35 ) ;
if ( V_4 -> V_123 )
V_127 = V_4 -> V_123 -> V_127 ;
F_35 ( & V_4 -> V_101 , V_35 ) ;
return V_127 ;
}
static void F_15 ( struct V_3 * V_4 )
{
unsigned long V_35 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_13 ( 0 , L_4 , V_17 ) ;
if ( ! F_88 ( V_43 , & V_4 -> V_2 . V_35 ) )
return;
F_89 ( V_4 ) ;
F_33 ( & V_4 -> V_101 , V_35 ) ;
F_90 ( & V_4 -> V_100 ) ;
if ( V_4 -> V_119 ) {
F_65 ( V_4 -> V_119 ) ;
V_4 -> V_119 = NULL ;
}
if ( V_4 -> V_123 ) {
F_65 ( V_4 -> V_123 ) ;
V_4 -> V_123 = NULL ;
}
if ( V_4 -> V_57 ) {
F_91 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
}
F_35 ( & V_4 -> V_101 , V_35 ) ;
}
static void F_92 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned long V_35 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_15 ( V_4 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_35 &= ~ V_70 ;
if ( V_2 -> V_62 ) {
F_93 ( V_69 , & V_2 -> V_62 -> V_35 ) ;
F_68 ( V_2 -> V_62 ) ;
}
V_2 -> V_62 = NULL ;
V_2 -> V_76 = 0 ;
F_35 ( & V_2 -> V_77 , V_35 ) ;
F_94 ( & V_2 -> V_75 ) ;
}
static void F_82 ( struct V_61 * V_62 , char V_138 )
{
F_13 ( 0 , L_24 , V_17 ) ;
}
void F_95 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
F_84 ( V_4 -> V_57 , V_120 ) ;
}
static void F_96 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_105 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_84 ( V_4 -> V_57 , V_93 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
struct V_61 * V_62 ;
int V_139 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_63 ( & V_4 -> V_2 ) ;
V_139 = V_4 -> V_5 . V_10 ;
if ( V_139 & V_140 ) {
}
if ( ( V_4 -> V_2 . V_35 & V_141 ) && ( V_139 & V_142 ) ) {
F_13 ( 2 ,
L_25 , V_17 , V_4 -> line ,
( V_139 & V_11 ) ? L_26 : L_27 ) ;
if ( V_139 & V_11 ) {
F_94 ( & V_4 -> V_2 . V_75 ) ;
} else {
F_13 ( 2 ,
L_28 , V_17 ) ;
if ( V_62 )
F_98 ( V_62 ) ;
goto V_122;
}
}
if ( V_62 && F_99 ( & V_4 -> V_2 ) ) {
if ( V_62 -> V_121 ) {
if ( V_139 & V_111 ) {
F_13 ( 2 ,
L_29 , V_17 ) ;
V_62 -> V_121 = 0 ;
F_94 ( & V_4 -> V_2 . V_75 ) ;
F_62 ( & V_4 -> V_94 ) ;
goto V_122;
}
} else {
if ( ! ( V_139 & V_111 ) ) {
F_13 ( 2 ,
L_30 , V_17 ) ;
V_62 -> V_121 = 1 ;
}
}
}
V_122:
F_68 ( V_62 ) ;
}
static int V_45 ( void * V_56 , void * V_143 ,
struct V_117 * V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_14 (skb != NULL, return -1;) ;
V_62 = F_63 ( & V_4 -> V_2 ) ;
if ( ! V_62 ) {
F_13 ( 0 , L_31 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_121 && ( V_4 -> V_92 == V_120 ) ) {
F_13 ( 0 , L_32 , V_17 ) ;
F_3 ( V_4 , V_144 , TRUE ) ;
F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
}
F_68 ( V_62 ) ;
F_102 ( & V_4 -> V_2 , V_118 -> V_145 , V_118 -> V_127 ) ;
F_103 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int V_47 ( void * V_56 , void * V_143 ,
struct V_117 * V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
int V_146 ;
F_13 ( 4 , L_4 , V_17 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_14 (skb != NULL, return -1;) ;
V_146 = V_118 -> V_145 [ 0 ] ;
F_104 ( V_4 , V_118 -> V_145 + 1 , F_76 ( V_118 -> V_127 - 1 , V_146 ) ,
& V_147 ) ;
return 0 ;
}
static void V_49 ( void * V_56 , void * V_143 ,
T_4 V_148 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_63 ( & V_4 -> V_2 ) ;
switch ( V_148 ) {
case V_120 :
F_13 ( 2 , L_33 , V_17 ) ;
if ( V_62 )
V_62 -> V_121 = 0 ;
F_62 ( & V_4 -> V_94 ) ;
break;
default:
case V_93 :
F_13 ( 2 , L_34 , V_17 ) ;
if ( V_62 )
V_62 -> V_121 = 1 ;
break;
}
F_68 ( V_62 ) ;
V_4 -> V_92 = V_148 ;
}
static void F_105 ( struct V_3 * V_4 , struct V_149 * V_150 )
{
struct V_61 * V_62 ;
char V_151 ;
F_106 ( V_150 , L_35 , V_152 [ V_4 -> V_84 ] ) ;
F_107 ( V_150 , L_36 ) ;
if ( V_4 -> V_58 & V_110 )
F_107 ( V_150 , L_37 ) ;
else if ( V_4 -> V_58 & V_109 )
F_107 ( V_150 , L_38 ) ;
else if ( V_4 -> V_58 & V_114 )
F_107 ( V_150 , L_39 ) ;
else
F_107 ( V_150 , L_40 ) ;
F_108 ( V_150 , '\n' ) ;
F_106 ( V_150 , L_41 , V_4 -> V_5 . V_153 ) ;
F_106 ( V_150 , L_42 ) ;
V_151 = ' ' ;
if ( V_4 -> V_5 . V_6 & V_7 ) {
F_106 ( V_150 , L_43 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_6 & V_8 ) {
F_106 ( V_150 , L_44 , V_151 ) ;
V_151 = '|' ;
}
F_108 ( V_150 , '\n' ) ;
F_107 ( V_150 , L_45 ) ;
V_151 = ' ' ;
if ( V_4 -> V_5 . V_10 & V_111 ) {
F_106 ( V_150 , L_46 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_112 ) {
F_106 ( V_150 , L_47 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_11 ) {
F_106 ( V_150 , L_48 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_113 ) {
F_106 ( V_150 , L_49 , V_151 ) ;
V_151 = '|' ;
}
F_108 ( V_150 , '\n' ) ;
F_107 ( V_150 , L_50 ) ;
if ( ! V_4 -> V_5 . V_154 )
F_107 ( V_150 , L_51 ) ;
else
F_107 ( V_150 , L_52 ) ;
F_106 ( V_150 , L_53 , V_4 -> V_5 . V_155 ) ;
F_107 ( V_150 , L_54 ) ;
V_151 = ' ' ;
if ( V_4 -> V_5 . V_156 & V_157 ) {
F_106 ( V_150 , L_55 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_158 ) {
F_106 ( V_150 , L_56 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_159 ) {
F_106 ( V_150 , L_57 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_160 ) {
F_106 ( V_150 , L_58 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_161 ) {
F_106 ( V_150 , L_59 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_162 ) {
F_106 ( V_150 , L_60 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_163 ) {
F_106 ( V_150 , L_61 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_5 . V_156 & V_164 ) {
F_106 ( V_150 , L_62 , V_151 ) ;
V_151 = '|' ;
}
F_108 ( V_150 , '\n' ) ;
F_107 ( V_150 , L_63 ) ;
V_151 = ' ' ;
if ( F_99 ( & V_4 -> V_2 ) ) {
F_106 ( V_150 , L_64 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_141 ) {
F_106 ( V_150 , L_65 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_165 ) {
F_106 ( V_150 , L_66 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_107 ) {
F_106 ( V_150 , L_67 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_166 ) {
F_106 ( V_150 , L_68 , V_151 ) ;
V_151 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_70 ) {
F_106 ( V_150 , L_69 , V_151 ) ;
V_151 = '|' ;
}
F_108 ( V_150 , '\n' ) ;
F_106 ( V_150 , L_70 , V_4 -> V_167 ? L_71 : L_72 ) ;
F_106 ( V_150 , L_73 , V_4 -> V_2 . V_76 ) ;
F_106 ( V_150 , L_74 , V_4 -> V_98 ) ;
F_106 ( V_150 , L_75 , V_4 -> V_96 ) ;
V_62 = F_63 ( & V_4 -> V_2 ) ;
if ( V_62 ) {
F_106 ( V_150 , L_76 ,
V_62 -> V_121 ? L_77 : L_78 ) ;
F_68 ( V_62 ) ;
}
}
static int F_109 ( struct V_149 * V_150 , void * V_168 )
{
struct V_3 * V_4 ;
unsigned long V_35 ;
F_33 ( & V_15 -> V_169 , V_35 ) ;
V_4 = (struct V_3 * ) F_110 ( V_15 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_38 != V_91 )
break;
F_105 ( V_4 , V_150 ) ;
V_4 = (struct V_3 * ) F_111 ( V_15 ) ;
}
F_35 ( & V_15 -> V_169 , V_35 ) ;
return 0 ;
}
static int F_112 ( struct V_170 * V_170 , struct V_63 * V_63 )
{
return F_113 ( V_63 , F_109 , NULL ) ;
}
