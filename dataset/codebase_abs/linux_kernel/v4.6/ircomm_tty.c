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
F_8 ( L_1 ,
V_17 ) ;
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
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_14 ( V_4 ) ;
V_4 -> V_38 = 0 ;
F_15 ( & V_4 -> V_2 ) ;
F_16 ( V_4 ) ;
}
static void T_2 F_17 ( void )
{
int V_39 ;
V_39 = F_18 ( V_12 ) ;
if ( V_39 ) {
F_8 ( L_4 ,
V_17 ) ;
return;
}
F_19 ( V_15 , ( V_40 ) F_12 ) ;
F_9 ( V_12 ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
T_3 V_41 ;
int V_39 = - V_42 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_21 ( V_43 , & V_4 -> V_2 . V_35 ) ) {
F_22 ( L_5 , V_17 ) ;
return 0 ;
}
F_23 ( & V_41 ) ;
V_41 . V_44 = V_45 ;
V_41 . V_46 = V_47 ;
V_41 . V_48 = V_49 ;
V_41 . V_50 = V_51 ;
V_41 . V_52 = V_53 ;
V_41 . V_54 = V_55 ;
F_24 ( V_41 . V_19 , L_6 , sizeof( V_41 . V_19 ) ) ;
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
F_8 ( L_7 , V_17 ) ;
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
if ( F_30 ( V_69 , & V_62 -> V_35 ) ) {
V_2 -> V_35 |= V_70 ;
return 0 ;
}
if ( V_64 -> V_71 & V_72 ) {
if ( F_31 ( V_62 ) )
F_32 ( V_2 ) ;
V_2 -> V_35 |= V_70 ;
F_22 ( L_8 , V_17 ) ;
return 0 ;
}
if ( F_33 ( V_62 ) ) {
F_22 ( L_9 , V_17 ) ;
V_68 = 1 ;
}
V_67 = 0 ;
F_34 ( & V_2 -> V_73 , & V_65 ) ;
F_22 ( L_10 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_74 ) ;
F_35 ( & V_2 -> V_75 , V_35 ) ;
V_2 -> V_74 -- ;
V_2 -> V_76 ++ ;
F_36 ( & V_2 -> V_75 , V_35 ) ;
while ( 1 ) {
if ( F_31 ( V_62 ) && F_30 ( V_43 , & V_2 -> V_35 ) )
F_32 ( V_2 ) ;
F_37 ( V_77 ) ;
if ( F_38 ( V_64 ) ||
! F_30 ( V_43 , & V_2 -> V_35 ) ) {
V_67 = ( V_2 -> V_35 & V_78 ) ?
- V_79 : - V_80 ;
break;
}
if ( ( V_68 || F_39 ( V_2 ) ) &&
V_4 -> V_81 == V_82 )
{
break;
}
if ( F_40 ( V_66 ) ) {
V_67 = - V_80 ;
break;
}
F_22 ( L_11 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_74 ) ;
F_41 () ;
}
F_42 ( V_83 ) ;
F_43 ( & V_2 -> V_73 , & V_65 ) ;
F_35 ( & V_2 -> V_75 , V_35 ) ;
if ( ! F_38 ( V_64 ) )
V_2 -> V_74 ++ ;
V_2 -> V_76 -- ;
F_36 ( & V_2 -> V_75 , V_35 ) ;
F_22 ( L_12 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_74 ) ;
if ( ! V_67 )
V_2 -> V_35 |= V_70 ;
return V_67 ;
}
static int F_44 ( struct V_84 * V_12 , struct V_61 * V_62 )
{
struct V_3 * V_4 ;
unsigned int line = V_62 -> V_85 ;
V_4 = F_45 ( V_15 , line , NULL ) ;
if ( ! V_4 ) {
V_4 = F_46 ( sizeof( struct V_3 ) , V_86 ) ;
if ( V_4 == NULL )
return - V_14 ;
F_47 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_37 = & V_87 ;
V_4 -> V_38 = V_88 ;
V_4 -> V_89 = V_90 ;
V_4 -> line = line ;
F_48 ( & V_4 -> V_91 , V_92 ) ;
V_4 -> V_93 = V_94 ;
V_4 -> V_95 = V_96 ;
F_49 ( & V_4 -> V_97 ) ;
F_50 ( & V_4 -> V_98 ) ;
V_62 -> V_99 . V_100 = 0 ;
V_62 -> V_99 . V_101 = 0 ;
F_51 ( V_15 , ( V_102 * ) V_4 , line , NULL ) ;
}
V_62 -> V_103 = V_4 ;
return F_52 ( & V_4 -> V_2 , V_12 , V_62 ) ;
}
static int F_53 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = V_62 -> V_103 ;
unsigned long V_35 ;
int V_39 ;
F_35 ( & V_4 -> V_2 . V_75 , V_35 ) ;
V_4 -> V_2 . V_74 ++ ;
F_36 ( & V_4 -> V_2 . V_75 , V_35 ) ;
F_54 ( & V_4 -> V_2 , V_62 ) ;
F_22 ( L_13 , V_17 , V_62 -> V_12 -> V_19 ,
V_4 -> line , V_4 -> V_2 . V_74 ) ;
V_4 -> V_2 . V_104 = ( V_4 -> V_2 . V_35 & V_105 ) ? 1 : 0 ;
if ( V_4 -> line < 0x10 ) {
V_4 -> V_58 = V_106 | V_107 ;
V_4 -> V_5 . V_58 = V_107 ;
V_4 -> V_5 . V_10 = V_108 | V_11 | V_109 | V_110 ;
F_22 ( L_14 , V_17 ) ;
} else {
F_22 ( L_15 , V_17 ) ;
V_4 -> V_58 = V_111 ;
V_4 -> V_5 . V_58 = V_111 ;
}
V_39 = F_20 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_28 ( V_4 , V_62 , V_64 ) ;
if ( V_39 ) {
F_22 ( L_16 ,
V_17 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
static void F_55 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_56 ( V_2 , V_62 , V_64 ) == 0 )
return;
F_14 ( V_4 ) ;
F_57 ( V_62 ) ;
F_58 ( V_2 , V_62 ) ;
F_54 ( V_2 , NULL ) ;
}
static void F_59 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_60 ( & V_4 -> V_91 ) ;
}
static void V_92 ( struct V_112 * V_113 )
{
struct V_3 * V_4 =
F_2 ( V_113 , struct V_3 , V_91 ) ;
struct V_61 * V_62 ;
unsigned long V_35 ;
struct V_114 * V_115 , * V_116 ;
if ( ! V_4 || V_4 -> V_38 != V_88 )
return;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( ! V_62 )
return;
F_35 ( & V_4 -> V_98 , V_35 ) ;
V_116 = V_4 -> V_116 ;
V_4 -> V_116 = NULL ;
F_36 ( & V_4 -> V_98 , V_35 ) ;
if( V_116 ) {
if( V_4 -> V_89 == V_117 )
F_62 ( V_4 -> V_57 , V_116 ) ;
F_63 ( V_116 ) ;
}
if ( V_62 -> V_118 )
goto V_119;
F_35 ( & V_4 -> V_98 , V_35 ) ;
V_115 = V_4 -> V_120 ;
V_4 -> V_120 = NULL ;
F_36 ( & V_4 -> V_98 , V_35 ) ;
if ( V_115 ) {
F_64 ( V_4 , V_121 , V_115 , NULL ) ;
F_63 ( V_115 ) ;
}
F_65 ( V_62 ) ;
V_119:
F_66 ( V_62 ) ;
}
static int F_67 ( struct V_61 * V_62 ,
const unsigned char * V_122 , int V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
unsigned long V_35 ;
struct V_114 * V_115 ;
int V_123 = 0 ;
int V_124 = 0 ;
int V_125 ;
F_22 ( L_17 , V_17 , V_74 ,
V_62 -> V_118 ) ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_4 -> V_93 == V_94 ) {
F_22 ( L_18 , V_17 ) ;
#ifdef F_68
return 0 ;
#endif
}
if ( V_74 < 1 )
return 0 ;
F_35 ( & V_4 -> V_98 , V_35 ) ;
V_115 = V_4 -> V_120 ;
while ( V_74 ) {
V_125 = V_74 ;
if ( V_125 > V_4 -> V_95 )
V_125 = V_4 -> V_95 ;
if ( V_115 ) {
if ( ( V_123 = ( V_4 -> V_126 - V_115 -> V_124 ) ) > 0 ) {
if ( V_125 > V_123 )
V_125 = V_123 ;
} else {
break;
}
} else {
V_115 = F_69 ( V_4 -> V_95 +
V_4 -> V_93 ,
V_127 ) ;
if ( ! V_115 ) {
F_36 ( & V_4 -> V_98 , V_35 ) ;
return - V_128 ;
}
F_70 ( V_115 , V_4 -> V_93 ) ;
V_4 -> V_120 = V_115 ;
V_4 -> V_126 = V_4 -> V_95 ;
}
memcpy ( F_71 ( V_115 , V_125 ) , V_122 + V_124 , V_125 ) ;
V_74 -= V_125 ;
V_124 += V_125 ;
}
F_36 ( & V_4 -> V_98 , V_35 ) ;
F_60 ( & V_4 -> V_91 ) ;
return V_124 ;
}
static int F_72 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
unsigned long V_35 ;
int V_39 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_68
if ( V_4 -> V_93 == V_94 )
return 0 ;
#endif
if ( V_62 -> V_118 )
V_39 = 0 ;
else {
F_35 ( & V_4 -> V_98 , V_35 ) ;
if ( V_4 -> V_120 )
V_39 = V_4 -> V_126 - V_4 -> V_120 -> V_124 ;
else
V_39 = V_4 -> V_95 ;
F_36 ( & V_4 -> V_98 , V_35 ) ;
}
F_22 ( L_19 , V_17 , V_39 ) ;
return V_39 ;
}
static void F_73 ( struct V_61 * V_62 , int V_129 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
unsigned long V_130 , V_131 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_130 = V_132 ;
V_131 = F_74 ( 200 ) ;
if ( V_129 )
V_131 = F_75 (unsigned long, timeout, poll_time) ;
F_35 ( & V_4 -> V_98 , V_35 ) ;
while ( V_4 -> V_120 && V_4 -> V_120 -> V_124 ) {
F_36 ( & V_4 -> V_98 , V_35 ) ;
F_76 ( V_131 ) ;
F_35 ( & V_4 -> V_98 , V_35 ) ;
if ( F_40 ( V_66 ) )
break;
if ( V_129 && F_77 ( V_132 , V_130 + V_129 ) )
break;
}
F_36 ( & V_4 -> V_98 , V_35 ) ;
F_42 ( V_83 ) ;
}
static void F_78 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_79 ( V_62 ) )
F_80 ( V_62 , F_81 ( V_62 ) ) ;
if ( F_82 ( V_62 ) ) {
V_4 -> V_5 . V_6 &= ~ V_7 ;
V_4 -> V_5 . V_6 |= V_133 ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
F_83 ( V_4 -> V_57 , V_90 ) ;
}
static void F_84 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_79 ( V_62 ) )
F_80 ( V_62 , F_85 ( V_62 ) ) ;
if ( F_82 ( V_62 ) ) {
V_4 -> V_5 . V_6 |= ( V_7 | V_133 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
F_22 ( L_20 , V_17 ) ;
}
F_83 ( V_4 -> V_57 , V_117 ) ;
}
static int F_86 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
unsigned long V_35 ;
int V_124 = 0 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_35 ( & V_4 -> V_98 , V_35 ) ;
if ( V_4 -> V_120 )
V_124 = V_4 -> V_120 -> V_124 ;
F_36 ( & V_4 -> V_98 , V_35 ) ;
return V_124 ;
}
static void F_14 ( struct V_3 * V_4 )
{
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( ! F_87 ( V_43 , & V_4 -> V_2 . V_35 ) )
return;
F_88 ( V_4 ) ;
F_35 ( & V_4 -> V_98 , V_35 ) ;
F_89 ( & V_4 -> V_97 ) ;
if ( V_4 -> V_116 ) {
F_63 ( V_4 -> V_116 ) ;
V_4 -> V_116 = NULL ;
}
if ( V_4 -> V_120 ) {
F_63 ( V_4 -> V_120 ) ;
V_4 -> V_120 = NULL ;
}
if ( V_4 -> V_57 ) {
F_90 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
}
F_36 ( & V_4 -> V_98 , V_35 ) ;
}
static void F_91 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_14 ( V_4 ) ;
F_35 ( & V_2 -> V_75 , V_35 ) ;
V_2 -> V_35 &= ~ V_70 ;
if ( V_2 -> V_62 ) {
F_92 ( V_69 , & V_2 -> V_62 -> V_35 ) ;
F_66 ( V_2 -> V_62 ) ;
}
V_2 -> V_62 = NULL ;
V_2 -> V_74 = 0 ;
F_36 ( & V_2 -> V_75 , V_35 ) ;
F_93 ( & V_2 -> V_73 ) ;
}
static void F_80 ( struct V_61 * V_62 , char V_134 )
{
F_22 ( L_21 , V_17 ) ;
}
void F_94 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
F_83 ( V_4 -> V_57 , V_117 ) ;
}
static void F_95 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_103 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_83 ( V_4 -> V_57 , V_90 ) ;
}
void F_96 ( struct V_3 * V_4 )
{
struct V_61 * V_62 ;
int V_135 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
V_135 = V_4 -> V_5 . V_10 ;
if ( V_135 & V_136 ) {
}
if ( ( V_4 -> V_2 . V_35 & V_137 ) && ( V_135 & V_138 ) ) {
F_22 ( L_22 , V_17 , V_4 -> line ,
( V_135 & V_11 ) ? L_23 : L_24 ) ;
if ( V_135 & V_11 ) {
F_93 ( & V_4 -> V_2 . V_73 ) ;
} else {
F_22 ( L_25 , V_17 ) ;
if ( V_62 )
F_97 ( V_62 ) ;
goto V_119;
}
}
if ( V_62 && F_98 ( & V_4 -> V_2 ) ) {
if ( V_62 -> V_118 ) {
if ( V_135 & V_108 ) {
F_22 ( L_26 , V_17 ) ;
V_62 -> V_118 = 0 ;
F_93 ( & V_4 -> V_2 . V_73 ) ;
F_60 ( & V_4 -> V_91 ) ;
goto V_119;
}
} else {
if ( ! ( V_135 & V_108 ) ) {
F_22 ( L_27 , V_17 ) ;
V_62 -> V_118 = 1 ;
}
}
}
V_119:
F_66 ( V_62 ) ;
}
static int V_45 ( void * V_56 , void * V_139 ,
struct V_114 * V_115 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( ! V_62 ) {
F_22 ( L_28 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_118 && ( V_4 -> V_89 == V_117 ) ) {
F_22 ( L_29 , V_17 ) ;
F_3 ( V_4 , V_140 , TRUE ) ;
F_99 ( V_4 ) ;
F_100 ( V_4 ) ;
}
F_66 ( V_62 ) ;
F_101 ( & V_4 -> V_2 , V_115 -> V_141 , V_115 -> V_124 ) ;
F_102 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int V_47 ( void * V_56 , void * V_139 ,
struct V_114 * V_115 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
int V_142 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_142 = V_115 -> V_141 [ 0 ] ;
F_103 ( V_4 , V_115 -> V_141 + 1 , F_104 ( V_115 -> V_124 - 1 , V_142 ) ,
& V_143 ) ;
return 0 ;
}
static void V_49 ( void * V_56 , void * V_139 ,
T_4 V_144 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
switch ( V_144 ) {
case V_117 :
F_22 ( L_30 , V_17 ) ;
if ( V_62 )
V_62 -> V_118 = 0 ;
F_60 ( & V_4 -> V_91 ) ;
break;
default:
case V_90 :
F_22 ( L_31 , V_17 ) ;
if ( V_62 )
V_62 -> V_118 = 1 ;
break;
}
F_66 ( V_62 ) ;
V_4 -> V_89 = V_144 ;
}
static void F_105 ( struct V_3 * V_4 , struct V_145 * V_146 )
{
struct V_61 * V_62 ;
char V_147 ;
F_106 ( V_146 , L_32 , V_148 [ V_4 -> V_81 ] ) ;
F_107 ( V_146 , L_33 ) ;
if ( V_4 -> V_58 & V_107 )
F_107 ( V_146 , L_34 ) ;
else if ( V_4 -> V_58 & V_106 )
F_107 ( V_146 , L_35 ) ;
else if ( V_4 -> V_58 & V_111 )
F_107 ( V_146 , L_36 ) ;
else
F_107 ( V_146 , L_37 ) ;
F_108 ( V_146 , '\n' ) ;
F_106 ( V_146 , L_38 , V_4 -> V_5 . V_149 ) ;
F_106 ( V_146 , L_39 ) ;
V_147 = ' ' ;
if ( V_4 -> V_5 . V_6 & V_7 ) {
F_106 ( V_146 , L_40 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_6 & V_8 ) {
F_106 ( V_146 , L_41 , V_147 ) ;
V_147 = '|' ;
}
F_108 ( V_146 , '\n' ) ;
F_107 ( V_146 , L_42 ) ;
V_147 = ' ' ;
if ( V_4 -> V_5 . V_10 & V_108 ) {
F_106 ( V_146 , L_43 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_109 ) {
F_106 ( V_146 , L_44 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_11 ) {
F_106 ( V_146 , L_45 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_110 ) {
F_106 ( V_146 , L_46 , V_147 ) ;
V_147 = '|' ;
}
F_108 ( V_146 , '\n' ) ;
F_107 ( V_146 , L_47 ) ;
if ( ! V_4 -> V_5 . V_150 )
F_107 ( V_146 , L_48 ) ;
else
F_107 ( V_146 , L_49 ) ;
F_106 ( V_146 , L_50 , V_4 -> V_5 . V_151 ) ;
F_107 ( V_146 , L_51 ) ;
V_147 = ' ' ;
if ( V_4 -> V_5 . V_152 & V_153 ) {
F_106 ( V_146 , L_52 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_154 ) {
F_106 ( V_146 , L_53 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_155 ) {
F_106 ( V_146 , L_54 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_156 ) {
F_106 ( V_146 , L_55 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_157 ) {
F_106 ( V_146 , L_56 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_158 ) {
F_106 ( V_146 , L_57 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_159 ) {
F_106 ( V_146 , L_58 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_5 . V_152 & V_160 ) {
F_106 ( V_146 , L_59 , V_147 ) ;
V_147 = '|' ;
}
F_108 ( V_146 , '\n' ) ;
F_107 ( V_146 , L_60 ) ;
V_147 = ' ' ;
if ( F_98 ( & V_4 -> V_2 ) ) {
F_106 ( V_146 , L_61 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_137 ) {
F_106 ( V_146 , L_62 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_161 ) {
F_106 ( V_146 , L_63 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_105 ) {
F_106 ( V_146 , L_64 , V_147 ) ;
V_147 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_70 ) {
F_106 ( V_146 , L_65 , V_147 ) ;
V_147 = '|' ;
}
F_108 ( V_146 , '\n' ) ;
F_106 ( V_146 , L_66 , V_4 -> V_162 ? L_67 : L_68 ) ;
F_106 ( V_146 , L_69 , V_4 -> V_2 . V_74 ) ;
F_106 ( V_146 , L_70 , V_4 -> V_95 ) ;
F_106 ( V_146 , L_71 , V_4 -> V_93 ) ;
V_62 = F_61 ( & V_4 -> V_2 ) ;
if ( V_62 ) {
F_106 ( V_146 , L_72 ,
V_62 -> V_118 ? L_73 : L_74 ) ;
F_66 ( V_62 ) ;
}
}
static int F_109 ( struct V_145 * V_146 , void * V_163 )
{
struct V_3 * V_4 ;
unsigned long V_35 ;
F_35 ( & V_15 -> V_164 , V_35 ) ;
V_4 = (struct V_3 * ) F_110 ( V_15 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_38 != V_88 )
break;
F_105 ( V_4 , V_146 ) ;
V_4 = (struct V_3 * ) F_111 ( V_15 ) ;
}
F_36 ( & V_15 -> V_164 , V_35 ) ;
return 0 ;
}
static int F_112 ( struct V_165 * V_165 , struct V_63 * V_63 )
{
return F_113 ( V_63 , F_109 , NULL ) ;
}
