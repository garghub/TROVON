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
int V_68 = 0 , V_69 = 0 ;
unsigned long V_35 ;
F_13 ( 2 , L_4 , V_17 ) ;
if ( V_64 -> V_70 & V_71 || V_62 -> V_35 & ( 1 << V_72 ) ) {
V_2 -> V_35 |= V_73 ;
F_13 ( 1 , L_9 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_74 . V_29 & V_34 ) {
F_13 ( 1 , L_10 , V_17 ) ;
V_68 = 1 ;
}
V_67 = 0 ;
F_30 ( & V_2 -> V_75 , & V_65 ) ;
F_13 ( 2 , L_11 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_31 ( & V_2 -> V_77 , V_35 ) ;
if ( ! F_32 ( V_64 ) ) {
V_69 = 1 ;
V_2 -> V_76 -- ;
}
F_33 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_78 ++ ;
while ( 1 ) {
if ( V_62 -> V_74 . V_29 & V_79 )
F_34 ( V_2 ) ;
V_66 -> V_80 = V_81 ;
if ( F_32 ( V_64 ) ||
! F_35 ( V_43 , & V_2 -> V_35 ) ) {
V_67 = ( V_2 -> V_35 & V_82 ) ?
- V_83 : - V_84 ;
break;
}
if ( ! F_35 ( V_85 , & V_2 -> V_35 ) &&
( V_68 || F_36 ( V_2 ) ) &&
V_4 -> V_80 == V_86 )
{
break;
}
if ( F_37 ( V_66 ) ) {
V_67 = - V_84 ;
break;
}
F_13 ( 1 , L_12 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_38 () ;
}
F_39 ( V_87 ) ;
F_40 ( & V_2 -> V_75 , & V_65 ) ;
if ( V_69 ) {
F_31 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_76 ++ ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
}
V_2 -> V_78 -- ;
F_13 ( 1 , L_13 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
if ( ! V_67 )
V_2 -> V_35 |= V_73 ;
return V_67 ;
}
static int F_41 ( struct V_88 * V_12 , struct V_61 * V_62 )
{
struct V_3 * V_4 ;
unsigned int line = V_62 -> V_89 ;
V_4 = F_42 ( V_15 , line , NULL ) ;
if ( ! V_4 ) {
V_4 = F_43 ( sizeof( struct V_3 ) , V_90 ) ;
if ( V_4 == NULL ) {
F_8 ( L_14 , V_17 ) ;
return - V_14 ;
}
F_44 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_37 = & V_91 ;
V_4 -> V_38 = V_92 ;
V_4 -> V_93 = V_94 ;
V_4 -> line = line ;
F_45 ( & V_4 -> V_95 , V_96 ) ;
V_4 -> V_97 = V_98 ;
V_4 -> V_99 = V_100 ;
F_46 ( & V_4 -> V_101 ) ;
F_47 ( & V_4 -> V_102 ) ;
V_62 -> V_74 . V_103 = 0 ;
V_62 -> V_74 . V_104 = 0 ;
F_48 ( V_15 , ( V_105 * ) V_4 , line , NULL ) ;
}
V_62 -> V_106 = V_4 ;
return F_49 ( & V_4 -> V_2 , V_12 , V_62 ) ;
}
static int F_50 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = V_62 -> V_106 ;
unsigned long V_35 ;
int V_39 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_31 ( & V_4 -> V_2 . V_77 , V_35 ) ;
V_4 -> V_2 . V_76 ++ ;
F_33 ( & V_4 -> V_2 . V_77 , V_35 ) ;
F_51 ( & V_4 -> V_2 , V_62 ) ;
F_13 ( 1 , L_15 , V_17 , V_62 -> V_12 -> V_19 ,
V_4 -> line , V_4 -> V_2 . V_76 ) ;
V_62 -> V_107 = ( V_4 -> V_2 . V_35 & V_108 ) ? 1 : 0 ;
if ( F_32 ( V_64 ) ||
F_35 ( V_85 , & V_4 -> V_2 . V_35 ) ) {
if ( F_52 ( V_4 -> V_2 . V_109 ,
! F_35 ( V_85 , & V_4 -> V_2 . V_35 ) ) ) {
F_53 ( L_16 ,
V_17 ) ;
return - V_84 ;
}
#ifdef F_54
return ( V_4 -> V_2 . V_35 & V_82 ) ?
- V_83 : - V_84 ;
#else
return - V_83 ;
#endif
}
if ( V_4 -> line < 0x10 ) {
V_4 -> V_58 = V_110 | V_111 ;
V_4 -> V_5 . V_58 = V_111 ;
V_4 -> V_5 . V_10 = V_112 | V_11 | V_113 | V_114 ;
F_13 ( 2 , L_17 , V_17 ) ;
} else {
F_13 ( 2 , L_18 , V_17 ) ;
V_4 -> V_58 = V_115 ;
V_4 -> V_5 . V_58 = V_115 ;
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
static void F_55 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_56 ( V_2 , V_62 , V_64 ) == 0 )
return;
F_15 ( V_4 ) ;
F_57 ( V_62 ) ;
F_58 ( V_2 , V_62 ) ;
F_51 ( V_2 , NULL ) ;
}
static void F_59 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_60 ( & V_4 -> V_95 ) ;
}
static void V_96 ( struct V_116 * V_117 )
{
struct V_3 * V_4 =
F_2 ( V_117 , struct V_3 , V_95 ) ;
struct V_61 * V_62 ;
unsigned long V_35 ;
struct V_118 * V_119 , * V_120 ;
F_13 ( 2 , L_4 , V_17 ) ;
if ( ! V_4 || V_4 -> V_38 != V_92 )
return;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( ! V_62 )
return;
F_31 ( & V_4 -> V_102 , V_35 ) ;
V_120 = V_4 -> V_120 ;
V_4 -> V_120 = NULL ;
F_33 ( & V_4 -> V_102 , V_35 ) ;
if( V_120 ) {
if( V_4 -> V_93 == V_121 )
F_62 ( V_4 -> V_57 , V_120 ) ;
F_63 ( V_120 ) ;
}
if ( V_62 -> V_122 )
goto V_123;
F_31 ( & V_4 -> V_102 , V_35 ) ;
V_119 = V_4 -> V_124 ;
V_4 -> V_124 = NULL ;
F_33 ( & V_4 -> V_102 , V_35 ) ;
if ( V_119 ) {
F_64 ( V_4 , V_125 , V_119 , NULL ) ;
F_63 ( V_119 ) ;
}
F_65 ( V_62 ) ;
V_123:
F_66 ( V_62 ) ;
}
static int F_67 ( struct V_61 * V_62 ,
const unsigned char * V_126 , int V_76 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
unsigned long V_35 ;
struct V_118 * V_119 ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_129 ;
F_13 ( 2 , L_20 , V_17 , V_76 ,
V_62 -> V_122 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_4 -> V_97 == V_98 ) {
F_13 ( 1 , L_21 , V_17 ) ;
#ifdef F_68
return 0 ;
#endif
}
if ( V_76 < 1 )
return 0 ;
F_31 ( & V_4 -> V_102 , V_35 ) ;
V_119 = V_4 -> V_124 ;
while ( V_76 ) {
V_129 = V_76 ;
if ( V_129 > V_4 -> V_99 )
V_129 = V_4 -> V_99 ;
if ( V_119 ) {
if ( ( V_127 = ( V_4 -> V_130 - V_119 -> V_128 ) ) > 0 ) {
if ( V_129 > V_127 )
V_129 = V_127 ;
} else {
break;
}
} else {
V_119 = F_69 ( V_4 -> V_99 +
V_4 -> V_97 ,
V_131 ) ;
if ( ! V_119 ) {
F_33 ( & V_4 -> V_102 , V_35 ) ;
return - V_132 ;
}
F_70 ( V_119 , V_4 -> V_97 ) ;
V_4 -> V_124 = V_119 ;
V_4 -> V_130 = V_4 -> V_99 ;
}
memcpy ( F_71 ( V_119 , V_129 ) , V_126 + V_128 , V_129 ) ;
V_76 -= V_129 ;
V_128 += V_129 ;
}
F_33 ( & V_4 -> V_102 , V_35 ) ;
F_60 ( & V_4 -> V_95 ) ;
return V_128 ;
}
static int F_72 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
unsigned long V_35 ;
int V_39 ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_68
if ( V_4 -> V_97 == V_98 )
return 0 ;
#endif
if ( V_62 -> V_122 )
V_39 = 0 ;
else {
F_31 ( & V_4 -> V_102 , V_35 ) ;
if ( V_4 -> V_124 )
V_39 = V_4 -> V_130 - V_4 -> V_124 -> V_128 ;
else
V_39 = V_4 -> V_99 ;
F_33 ( & V_4 -> V_102 , V_35 ) ;
}
F_13 ( 2 , L_22 , V_17 , V_39 ) ;
return V_39 ;
}
static void F_73 ( struct V_61 * V_62 , int V_133 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
unsigned long V_134 , V_135 ;
unsigned long V_35 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_134 = V_136 ;
V_135 = F_74 ( V_133 , F_75 ( 200 ) ) ;
F_31 ( & V_4 -> V_102 , V_35 ) ;
while ( V_4 -> V_124 && V_4 -> V_124 -> V_128 ) {
F_33 ( & V_4 -> V_102 , V_35 ) ;
F_76 ( V_135 ) ;
F_31 ( & V_4 -> V_102 , V_35 ) ;
if ( F_37 ( V_66 ) )
break;
if ( V_133 && F_77 ( V_136 , V_134 + V_133 ) )
break;
}
F_33 ( & V_4 -> V_102 , V_35 ) ;
V_66 -> V_80 = V_87 ;
}
static void F_78 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_79 ( V_62 ) )
F_80 ( V_62 , F_81 ( V_62 ) ) ;
if ( V_62 -> V_74 . V_29 & V_137 ) {
V_4 -> V_5 . V_6 &= ~ V_7 ;
V_4 -> V_5 . V_6 |= V_138 ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
F_82 ( V_4 -> V_57 , V_94 ) ;
}
static void F_83 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_79 ( V_62 ) ) {
F_80 ( V_62 , F_84 ( V_62 ) ) ;
}
if ( V_62 -> V_74 . V_29 & V_137 ) {
V_4 -> V_5 . V_6 |= ( V_7 | V_138 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
F_13 ( 1 , L_23 , V_17 ) ;
}
F_82 ( V_4 -> V_57 , V_121 ) ;
}
static int F_85 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
unsigned long V_35 ;
int V_128 = 0 ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_31 ( & V_4 -> V_102 , V_35 ) ;
if ( V_4 -> V_124 )
V_128 = V_4 -> V_124 -> V_128 ;
F_33 ( & V_4 -> V_102 , V_35 ) ;
return V_128 ;
}
static void F_15 ( struct V_3 * V_4 )
{
unsigned long V_35 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_13 ( 0 , L_4 , V_17 ) ;
if ( ! F_86 ( V_43 , & V_4 -> V_2 . V_35 ) )
return;
F_87 ( V_4 ) ;
F_31 ( & V_4 -> V_102 , V_35 ) ;
F_88 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_120 ) {
F_63 ( V_4 -> V_120 ) ;
V_4 -> V_120 = NULL ;
}
if ( V_4 -> V_124 ) {
F_63 ( V_4 -> V_124 ) ;
V_4 -> V_124 = NULL ;
}
if ( V_4 -> V_57 ) {
F_89 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
}
F_33 ( & V_4 -> V_102 , V_35 ) ;
}
static void F_90 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned long V_35 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_15 ( V_4 ) ;
F_31 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_35 &= ~ V_73 ;
if ( V_2 -> V_62 ) {
F_91 ( V_72 , & V_2 -> V_62 -> V_35 ) ;
F_66 ( V_2 -> V_62 ) ;
}
V_2 -> V_62 = NULL ;
V_2 -> V_76 = 0 ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
F_92 ( & V_2 -> V_75 ) ;
}
static void F_80 ( struct V_61 * V_62 , char V_139 )
{
F_13 ( 0 , L_24 , V_17 ) ;
}
void F_93 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
F_82 ( V_4 -> V_57 , V_121 ) ;
}
static void F_94 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_106 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_82 ( V_4 -> V_57 , V_94 ) ;
}
void F_95 ( struct V_3 * V_4 )
{
struct V_61 * V_62 ;
int V_140 ;
F_13 ( 0 , L_4 , V_17 ) ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
V_140 = V_4 -> V_5 . V_10 ;
if ( V_140 & V_141 ) {
}
if ( ( V_4 -> V_2 . V_35 & V_142 ) && ( V_140 & V_143 ) ) {
F_13 ( 2 ,
L_25 , V_17 , V_4 -> line ,
( V_140 & V_11 ) ? L_26 : L_27 ) ;
if ( V_140 & V_11 ) {
F_92 ( & V_4 -> V_2 . V_75 ) ;
} else {
F_13 ( 2 ,
L_28 , V_17 ) ;
if ( V_62 )
F_96 ( V_62 ) ;
goto V_123;
}
}
if ( V_62 && F_97 ( & V_4 -> V_2 ) ) {
if ( V_62 -> V_122 ) {
if ( V_140 & V_112 ) {
F_13 ( 2 ,
L_29 , V_17 ) ;
V_62 -> V_122 = 0 ;
F_92 ( & V_4 -> V_2 . V_75 ) ;
F_60 ( & V_4 -> V_95 ) ;
goto V_123;
}
} else {
if ( ! ( V_140 & V_112 ) ) {
F_13 ( 2 ,
L_30 , V_17 ) ;
V_62 -> V_122 = 1 ;
}
}
}
V_123:
F_66 ( V_62 ) ;
}
static int V_45 ( void * V_56 , void * V_144 ,
struct V_118 * V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 ( 2 , L_4 , V_17 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_14 (skb != NULL, return -1;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( ! V_62 ) {
F_13 ( 0 , L_31 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_122 && ( V_4 -> V_93 == V_121 ) ) {
F_13 ( 0 , L_32 , V_17 ) ;
F_3 ( V_4 , V_145 , TRUE ) ;
F_98 ( V_4 ) ;
F_99 ( V_4 ) ;
}
F_100 ( V_62 , V_119 -> V_146 , V_119 -> V_128 ) ;
F_101 ( V_62 ) ;
F_66 ( V_62 ) ;
return 0 ;
}
static int V_47 ( void * V_56 , void * V_144 ,
struct V_118 * V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
int V_147 ;
F_13 ( 4 , L_4 , V_17 ) ;
F_14 (self != NULL, return -1;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_14 (skb != NULL, return -1;) ;
V_147 = V_119 -> V_146 [ 0 ] ;
F_102 ( V_4 , V_119 -> V_146 + 1 , F_74 ( V_119 -> V_128 - 1 , V_147 ) ,
& V_148 ) ;
return 0 ;
}
static void V_49 ( void * V_56 , void * V_144 ,
T_4 V_149 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_14 (self != NULL, return;) ;
F_14 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
switch ( V_149 ) {
case V_121 :
F_13 ( 2 , L_33 , V_17 ) ;
if ( V_62 )
V_62 -> V_122 = 0 ;
F_60 ( & V_4 -> V_95 ) ;
break;
default:
case V_94 :
F_13 ( 2 , L_34 , V_17 ) ;
if ( V_62 )
V_62 -> V_122 = 1 ;
break;
}
F_66 ( V_62 ) ;
V_4 -> V_93 = V_149 ;
}
static void F_103 ( struct V_3 * V_4 , struct V_150 * V_151 )
{
struct V_61 * V_62 ;
char V_152 ;
F_104 ( V_151 , L_35 , V_153 [ V_4 -> V_80 ] ) ;
F_105 ( V_151 , L_36 ) ;
if ( V_4 -> V_58 & V_111 )
F_105 ( V_151 , L_37 ) ;
else if ( V_4 -> V_58 & V_110 )
F_105 ( V_151 , L_38 ) ;
else if ( V_4 -> V_58 & V_115 )
F_105 ( V_151 , L_39 ) ;
else
F_105 ( V_151 , L_40 ) ;
F_106 ( V_151 , '\n' ) ;
F_104 ( V_151 , L_41 , V_4 -> V_5 . V_154 ) ;
F_104 ( V_151 , L_42 ) ;
V_152 = ' ' ;
if ( V_4 -> V_5 . V_6 & V_7 ) {
F_104 ( V_151 , L_43 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_6 & V_8 ) {
F_104 ( V_151 , L_44 , V_152 ) ;
V_152 = '|' ;
}
F_106 ( V_151 , '\n' ) ;
F_105 ( V_151 , L_45 ) ;
V_152 = ' ' ;
if ( V_4 -> V_5 . V_10 & V_112 ) {
F_104 ( V_151 , L_46 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_113 ) {
F_104 ( V_151 , L_47 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_11 ) {
F_104 ( V_151 , L_48 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_114 ) {
F_104 ( V_151 , L_49 , V_152 ) ;
V_152 = '|' ;
}
F_106 ( V_151 , '\n' ) ;
F_105 ( V_151 , L_50 ) ;
if ( ! V_4 -> V_5 . V_155 )
F_105 ( V_151 , L_51 ) ;
else
F_105 ( V_151 , L_52 ) ;
F_104 ( V_151 , L_53 , V_4 -> V_5 . V_156 ) ;
F_105 ( V_151 , L_54 ) ;
V_152 = ' ' ;
if ( V_4 -> V_5 . V_157 & V_158 ) {
F_104 ( V_151 , L_55 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_159 ) {
F_104 ( V_151 , L_56 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_160 ) {
F_104 ( V_151 , L_57 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_161 ) {
F_104 ( V_151 , L_58 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_162 ) {
F_104 ( V_151 , L_59 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_163 ) {
F_104 ( V_151 , L_60 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_164 ) {
F_104 ( V_151 , L_61 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_5 . V_157 & V_165 ) {
F_104 ( V_151 , L_62 , V_152 ) ;
V_152 = '|' ;
}
F_106 ( V_151 , '\n' ) ;
F_105 ( V_151 , L_63 ) ;
V_152 = ' ' ;
if ( F_97 ( & V_4 -> V_2 ) ) {
F_104 ( V_151 , L_64 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_142 ) {
F_104 ( V_151 , L_65 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_166 ) {
F_104 ( V_151 , L_66 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_108 ) {
F_104 ( V_151 , L_67 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_167 ) {
F_104 ( V_151 , L_68 , V_152 ) ;
V_152 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_73 ) {
F_104 ( V_151 , L_69 , V_152 ) ;
V_152 = '|' ;
}
F_106 ( V_151 , '\n' ) ;
F_104 ( V_151 , L_70 , V_4 -> V_168 ? L_71 : L_72 ) ;
F_104 ( V_151 , L_73 , V_4 -> V_2 . V_76 ) ;
F_104 ( V_151 , L_74 , V_4 -> V_99 ) ;
F_104 ( V_151 , L_75 , V_4 -> V_97 ) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( V_62 ) {
F_104 ( V_151 , L_76 ,
V_62 -> V_122 ? L_77 : L_78 ) ;
F_66 ( V_62 ) ;
}
}
static int F_107 ( struct V_150 * V_151 , void * V_169 )
{
struct V_3 * V_4 ;
unsigned long V_35 ;
F_31 ( & V_15 -> V_170 , V_35 ) ;
V_4 = (struct V_3 * ) F_108 ( V_15 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_38 != V_92 )
break;
F_103 ( V_4 , V_151 ) ;
V_4 = (struct V_3 * ) F_109 ( V_15 ) ;
}
F_33 ( & V_15 -> V_170 , V_35 ) ;
return 0 ;
}
static int F_110 ( struct V_171 * V_171 , struct V_63 * V_63 )
{
return F_111 ( V_63 , F_107 , NULL ) ;
}
