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
if ( V_62 -> V_73 . V_29 & V_74 )
F_31 ( V_2 ) ;
V_2 -> V_35 |= V_70 ;
F_22 ( L_8 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_73 . V_29 & V_34 ) {
F_22 ( L_9 , V_17 ) ;
V_68 = 1 ;
}
V_67 = 0 ;
F_32 ( & V_2 -> V_75 , & V_65 ) ;
F_22 ( L_10 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_76 -- ;
V_2 -> V_78 ++ ;
F_34 ( & V_2 -> V_77 , V_35 ) ;
while ( 1 ) {
if ( F_35 ( V_62 ) && F_30 ( V_43 , & V_2 -> V_35 ) )
F_31 ( V_2 ) ;
F_36 ( V_79 ) ;
if ( F_37 ( V_64 ) ||
! F_30 ( V_43 , & V_2 -> V_35 ) ) {
V_67 = ( V_2 -> V_35 & V_80 ) ?
- V_81 : - V_82 ;
break;
}
if ( ( V_68 || F_38 ( V_2 ) ) &&
V_4 -> V_83 == V_84 )
{
break;
}
if ( F_39 ( V_66 ) ) {
V_67 = - V_82 ;
break;
}
F_22 ( L_11 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
F_40 () ;
}
F_41 ( V_85 ) ;
F_42 ( & V_2 -> V_75 , & V_65 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
if ( ! F_37 ( V_64 ) )
V_2 -> V_76 ++ ;
V_2 -> V_78 -- ;
F_34 ( & V_2 -> V_77 , V_35 ) ;
F_22 ( L_12 ,
__FILE__ , __LINE__ , V_62 -> V_12 -> V_19 , V_2 -> V_76 ) ;
if ( ! V_67 )
V_2 -> V_35 |= V_70 ;
return V_67 ;
}
static int F_43 ( struct V_86 * V_12 , struct V_61 * V_62 )
{
struct V_3 * V_4 ;
unsigned int line = V_62 -> V_87 ;
V_4 = F_44 ( V_15 , line , NULL ) ;
if ( ! V_4 ) {
V_4 = F_45 ( sizeof( struct V_3 ) , V_88 ) ;
if ( V_4 == NULL )
return - V_14 ;
F_46 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_37 = & V_89 ;
V_4 -> V_38 = V_90 ;
V_4 -> V_91 = V_92 ;
V_4 -> line = line ;
F_47 ( & V_4 -> V_93 , V_94 ) ;
V_4 -> V_95 = V_96 ;
V_4 -> V_97 = V_98 ;
F_48 ( & V_4 -> V_99 ) ;
F_49 ( & V_4 -> V_100 ) ;
V_62 -> V_73 . V_101 = 0 ;
V_62 -> V_73 . V_102 = 0 ;
F_50 ( V_15 , ( V_103 * ) V_4 , line , NULL ) ;
}
V_62 -> V_104 = V_4 ;
return F_51 ( & V_4 -> V_2 , V_12 , V_62 ) ;
}
static int F_52 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = V_62 -> V_104 ;
unsigned long V_35 ;
int V_39 ;
F_33 ( & V_4 -> V_2 . V_77 , V_35 ) ;
V_4 -> V_2 . V_76 ++ ;
F_34 ( & V_4 -> V_2 . V_77 , V_35 ) ;
F_53 ( & V_4 -> V_2 , V_62 ) ;
F_22 ( L_13 , V_17 , V_62 -> V_12 -> V_19 ,
V_4 -> line , V_4 -> V_2 . V_76 ) ;
V_4 -> V_2 . V_105 = ( V_4 -> V_2 . V_35 & V_106 ) ? 1 : 0 ;
if ( V_4 -> line < 0x10 ) {
V_4 -> V_58 = V_107 | V_108 ;
V_4 -> V_5 . V_58 = V_108 ;
V_4 -> V_5 . V_10 = V_109 | V_11 | V_110 | V_111 ;
F_22 ( L_14 , V_17 ) ;
} else {
F_22 ( L_15 , V_17 ) ;
V_4 -> V_58 = V_112 ;
V_4 -> V_5 . V_58 = V_112 ;
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
static void F_54 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_55 ( V_2 , V_62 , V_64 ) == 0 )
return;
F_14 ( V_4 ) ;
F_56 ( V_62 ) ;
F_57 ( V_2 , V_62 ) ;
F_53 ( V_2 , NULL ) ;
}
static void F_58 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_59 ( & V_4 -> V_93 ) ;
}
static void V_94 ( struct V_113 * V_114 )
{
struct V_3 * V_4 =
F_2 ( V_114 , struct V_3 , V_93 ) ;
struct V_61 * V_62 ;
unsigned long V_35 ;
struct V_115 * V_116 , * V_117 ;
if ( ! V_4 || V_4 -> V_38 != V_90 )
return;
V_62 = F_60 ( & V_4 -> V_2 ) ;
if ( ! V_62 )
return;
F_33 ( & V_4 -> V_100 , V_35 ) ;
V_117 = V_4 -> V_117 ;
V_4 -> V_117 = NULL ;
F_34 ( & V_4 -> V_100 , V_35 ) ;
if( V_117 ) {
if( V_4 -> V_91 == V_118 )
F_61 ( V_4 -> V_57 , V_117 ) ;
F_62 ( V_117 ) ;
}
if ( V_62 -> V_119 )
goto V_120;
F_33 ( & V_4 -> V_100 , V_35 ) ;
V_116 = V_4 -> V_121 ;
V_4 -> V_121 = NULL ;
F_34 ( & V_4 -> V_100 , V_35 ) ;
if ( V_116 ) {
F_63 ( V_4 , V_122 , V_116 , NULL ) ;
F_62 ( V_116 ) ;
}
F_64 ( V_62 ) ;
V_120:
F_65 ( V_62 ) ;
}
static int F_66 ( struct V_61 * V_62 ,
const unsigned char * V_123 , int V_76 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
unsigned long V_35 ;
struct V_115 * V_116 ;
int V_124 = 0 ;
int V_125 = 0 ;
int V_126 ;
F_22 ( L_17 , V_17 , V_76 ,
V_62 -> V_119 ) ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_4 -> V_95 == V_96 ) {
F_22 ( L_18 , V_17 ) ;
#ifdef F_67
return 0 ;
#endif
}
if ( V_76 < 1 )
return 0 ;
F_33 ( & V_4 -> V_100 , V_35 ) ;
V_116 = V_4 -> V_121 ;
while ( V_76 ) {
V_126 = V_76 ;
if ( V_126 > V_4 -> V_97 )
V_126 = V_4 -> V_97 ;
if ( V_116 ) {
if ( ( V_124 = ( V_4 -> V_127 - V_116 -> V_125 ) ) > 0 ) {
if ( V_126 > V_124 )
V_126 = V_124 ;
} else {
break;
}
} else {
V_116 = F_68 ( V_4 -> V_97 +
V_4 -> V_95 ,
V_128 ) ;
if ( ! V_116 ) {
F_34 ( & V_4 -> V_100 , V_35 ) ;
return - V_129 ;
}
F_69 ( V_116 , V_4 -> V_95 ) ;
V_4 -> V_121 = V_116 ;
V_4 -> V_127 = V_4 -> V_97 ;
}
memcpy ( F_70 ( V_116 , V_126 ) , V_123 + V_125 , V_126 ) ;
V_76 -= V_126 ;
V_125 += V_126 ;
}
F_34 ( & V_4 -> V_100 , V_35 ) ;
F_59 ( & V_4 -> V_93 ) ;
return V_125 ;
}
static int F_71 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
unsigned long V_35 ;
int V_39 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_67
if ( V_4 -> V_95 == V_96 )
return 0 ;
#endif
if ( V_62 -> V_119 )
V_39 = 0 ;
else {
F_33 ( & V_4 -> V_100 , V_35 ) ;
if ( V_4 -> V_121 )
V_39 = V_4 -> V_127 - V_4 -> V_121 -> V_125 ;
else
V_39 = V_4 -> V_97 ;
F_34 ( & V_4 -> V_100 , V_35 ) ;
}
F_22 ( L_19 , V_17 , V_39 ) ;
return V_39 ;
}
static void F_72 ( struct V_61 * V_62 , int V_130 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
unsigned long V_131 , V_132 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_131 = V_133 ;
V_132 = F_73 ( 200 ) ;
if ( V_130 )
V_132 = F_74 (unsigned long, timeout, poll_time) ;
F_33 ( & V_4 -> V_100 , V_35 ) ;
while ( V_4 -> V_121 && V_4 -> V_121 -> V_125 ) {
F_34 ( & V_4 -> V_100 , V_35 ) ;
F_75 ( V_132 ) ;
F_33 ( & V_4 -> V_100 , V_35 ) ;
if ( F_39 ( V_66 ) )
break;
if ( V_130 && F_76 ( V_133 , V_131 + V_130 ) )
break;
}
F_34 ( & V_4 -> V_100 , V_35 ) ;
F_41 ( V_85 ) ;
}
static void F_77 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_78 ( V_62 ) )
F_79 ( V_62 , F_80 ( V_62 ) ) ;
if ( V_62 -> V_73 . V_29 & V_134 ) {
V_4 -> V_5 . V_6 &= ~ V_7 ;
V_4 -> V_5 . V_6 |= V_135 ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
F_81 ( V_4 -> V_57 , V_92 ) ;
}
static void F_82 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_78 ( V_62 ) ) {
F_79 ( V_62 , F_83 ( V_62 ) ) ;
}
if ( V_62 -> V_73 . V_29 & V_134 ) {
V_4 -> V_5 . V_6 |= ( V_7 | V_135 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
F_22 ( L_20 , V_17 ) ;
}
F_81 ( V_4 -> V_57 , V_118 ) ;
}
static int F_84 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
unsigned long V_35 ;
int V_125 = 0 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_33 ( & V_4 -> V_100 , V_35 ) ;
if ( V_4 -> V_121 )
V_125 = V_4 -> V_121 -> V_125 ;
F_34 ( & V_4 -> V_100 , V_35 ) ;
return V_125 ;
}
static void F_14 ( struct V_3 * V_4 )
{
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( ! F_85 ( V_43 , & V_4 -> V_2 . V_35 ) )
return;
F_86 ( V_4 ) ;
F_33 ( & V_4 -> V_100 , V_35 ) ;
F_87 ( & V_4 -> V_99 ) ;
if ( V_4 -> V_117 ) {
F_62 ( V_4 -> V_117 ) ;
V_4 -> V_117 = NULL ;
}
if ( V_4 -> V_121 ) {
F_62 ( V_4 -> V_121 ) ;
V_4 -> V_121 = NULL ;
}
if ( V_4 -> V_57 ) {
F_88 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
}
F_34 ( & V_4 -> V_100 , V_35 ) ;
}
static void F_89 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_14 ( V_4 ) ;
F_33 ( & V_2 -> V_77 , V_35 ) ;
V_2 -> V_35 &= ~ V_70 ;
if ( V_2 -> V_62 ) {
F_90 ( V_69 , & V_2 -> V_62 -> V_35 ) ;
F_65 ( V_2 -> V_62 ) ;
}
V_2 -> V_62 = NULL ;
V_2 -> V_76 = 0 ;
F_34 ( & V_2 -> V_77 , V_35 ) ;
F_91 ( & V_2 -> V_75 ) ;
}
static void F_79 ( struct V_61 * V_62 , char V_136 )
{
F_22 ( L_21 , V_17 ) ;
}
void F_92 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
F_81 ( V_4 -> V_57 , V_118 ) ;
}
static void F_93 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 -> V_104 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_81 ( V_4 -> V_57 , V_92 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
struct V_61 * V_62 ;
int V_137 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_60 ( & V_4 -> V_2 ) ;
V_137 = V_4 -> V_5 . V_10 ;
if ( V_137 & V_138 ) {
}
if ( ( V_4 -> V_2 . V_35 & V_139 ) && ( V_137 & V_140 ) ) {
F_22 ( L_22 , V_17 , V_4 -> line ,
( V_137 & V_11 ) ? L_23 : L_24 ) ;
if ( V_137 & V_11 ) {
F_91 ( & V_4 -> V_2 . V_75 ) ;
} else {
F_22 ( L_25 , V_17 ) ;
if ( V_62 )
F_95 ( V_62 ) ;
goto V_120;
}
}
if ( V_62 && F_96 ( & V_4 -> V_2 ) ) {
if ( V_62 -> V_119 ) {
if ( V_137 & V_109 ) {
F_22 ( L_26 , V_17 ) ;
V_62 -> V_119 = 0 ;
F_91 ( & V_4 -> V_2 . V_75 ) ;
F_59 ( & V_4 -> V_93 ) ;
goto V_120;
}
} else {
if ( ! ( V_137 & V_109 ) ) {
F_22 ( L_27 , V_17 ) ;
V_62 -> V_119 = 1 ;
}
}
}
V_120:
F_65 ( V_62 ) ;
}
static int V_45 ( void * V_56 , void * V_141 ,
struct V_115 * V_116 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_62 = F_60 ( & V_4 -> V_2 ) ;
if ( ! V_62 ) {
F_22 ( L_28 , V_17 ) ;
return 0 ;
}
if ( V_62 -> V_119 && ( V_4 -> V_91 == V_118 ) ) {
F_22 ( L_29 , V_17 ) ;
F_3 ( V_4 , V_142 , TRUE ) ;
F_97 ( V_4 ) ;
F_98 ( V_4 ) ;
}
F_65 ( V_62 ) ;
F_99 ( & V_4 -> V_2 , V_116 -> V_143 , V_116 -> V_125 ) ;
F_100 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int V_47 ( void * V_56 , void * V_141 ,
struct V_115 * V_116 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
int V_144 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_144 = V_116 -> V_143 [ 0 ] ;
F_101 ( V_4 , V_116 -> V_143 + 1 , F_102 ( V_116 -> V_125 - 1 , V_144 ) ,
& V_145 ) ;
return 0 ;
}
static void V_49 ( void * V_56 , void * V_141 ,
T_4 V_146 )
{
struct V_3 * V_4 = (struct V_3 * ) V_56 ;
struct V_61 * V_62 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_62 = F_60 ( & V_4 -> V_2 ) ;
switch ( V_146 ) {
case V_118 :
F_22 ( L_30 , V_17 ) ;
if ( V_62 )
V_62 -> V_119 = 0 ;
F_59 ( & V_4 -> V_93 ) ;
break;
default:
case V_92 :
F_22 ( L_31 , V_17 ) ;
if ( V_62 )
V_62 -> V_119 = 1 ;
break;
}
F_65 ( V_62 ) ;
V_4 -> V_91 = V_146 ;
}
static void F_103 ( struct V_3 * V_4 , struct V_147 * V_148 )
{
struct V_61 * V_62 ;
char V_149 ;
F_104 ( V_148 , L_32 , V_150 [ V_4 -> V_83 ] ) ;
F_105 ( V_148 , L_33 ) ;
if ( V_4 -> V_58 & V_108 )
F_105 ( V_148 , L_34 ) ;
else if ( V_4 -> V_58 & V_107 )
F_105 ( V_148 , L_35 ) ;
else if ( V_4 -> V_58 & V_112 )
F_105 ( V_148 , L_36 ) ;
else
F_105 ( V_148 , L_37 ) ;
F_106 ( V_148 , '\n' ) ;
F_104 ( V_148 , L_38 , V_4 -> V_5 . V_151 ) ;
F_104 ( V_148 , L_39 ) ;
V_149 = ' ' ;
if ( V_4 -> V_5 . V_6 & V_7 ) {
F_104 ( V_148 , L_40 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_6 & V_8 ) {
F_104 ( V_148 , L_41 , V_149 ) ;
V_149 = '|' ;
}
F_106 ( V_148 , '\n' ) ;
F_105 ( V_148 , L_42 ) ;
V_149 = ' ' ;
if ( V_4 -> V_5 . V_10 & V_109 ) {
F_104 ( V_148 , L_43 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_110 ) {
F_104 ( V_148 , L_44 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_11 ) {
F_104 ( V_148 , L_45 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_111 ) {
F_104 ( V_148 , L_46 , V_149 ) ;
V_149 = '|' ;
}
F_106 ( V_148 , '\n' ) ;
F_105 ( V_148 , L_47 ) ;
if ( ! V_4 -> V_5 . V_152 )
F_105 ( V_148 , L_48 ) ;
else
F_105 ( V_148 , L_49 ) ;
F_104 ( V_148 , L_50 , V_4 -> V_5 . V_153 ) ;
F_105 ( V_148 , L_51 ) ;
V_149 = ' ' ;
if ( V_4 -> V_5 . V_154 & V_155 ) {
F_104 ( V_148 , L_52 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_156 ) {
F_104 ( V_148 , L_53 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_157 ) {
F_104 ( V_148 , L_54 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_158 ) {
F_104 ( V_148 , L_55 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_159 ) {
F_104 ( V_148 , L_56 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_160 ) {
F_104 ( V_148 , L_57 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_161 ) {
F_104 ( V_148 , L_58 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_5 . V_154 & V_162 ) {
F_104 ( V_148 , L_59 , V_149 ) ;
V_149 = '|' ;
}
F_106 ( V_148 , '\n' ) ;
F_105 ( V_148 , L_60 ) ;
V_149 = ' ' ;
if ( F_96 ( & V_4 -> V_2 ) ) {
F_104 ( V_148 , L_61 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_139 ) {
F_104 ( V_148 , L_62 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_163 ) {
F_104 ( V_148 , L_63 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_106 ) {
F_104 ( V_148 , L_64 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_164 ) {
F_104 ( V_148 , L_65 , V_149 ) ;
V_149 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_70 ) {
F_104 ( V_148 , L_66 , V_149 ) ;
V_149 = '|' ;
}
F_106 ( V_148 , '\n' ) ;
F_104 ( V_148 , L_67 , V_4 -> V_165 ? L_68 : L_69 ) ;
F_104 ( V_148 , L_70 , V_4 -> V_2 . V_76 ) ;
F_104 ( V_148 , L_71 , V_4 -> V_97 ) ;
F_104 ( V_148 , L_72 , V_4 -> V_95 ) ;
V_62 = F_60 ( & V_4 -> V_2 ) ;
if ( V_62 ) {
F_104 ( V_148 , L_73 ,
V_62 -> V_119 ? L_74 : L_75 ) ;
F_65 ( V_62 ) ;
}
}
static int F_107 ( struct V_147 * V_148 , void * V_166 )
{
struct V_3 * V_4 ;
unsigned long V_35 ;
F_33 ( & V_15 -> V_167 , V_35 ) ;
V_4 = (struct V_3 * ) F_108 ( V_15 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_38 != V_90 )
break;
F_103 ( V_4 , V_148 ) ;
V_4 = (struct V_3 * ) F_109 ( V_15 ) ;
}
F_34 ( & V_15 -> V_167 , V_35 ) ;
return 0 ;
}
static int F_110 ( struct V_168 * V_168 , struct V_63 * V_63 )
{
return F_111 ( V_63 , F_107 , NULL ) ;
}
