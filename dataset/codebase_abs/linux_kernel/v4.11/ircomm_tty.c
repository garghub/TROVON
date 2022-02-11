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
if ( F_21 ( & V_4 -> V_2 ) ) {
F_22 ( L_5 , V_17 ) ;
return 0 ;
}
F_23 ( & V_4 -> V_2 , 1 ) ;
F_24 ( & V_41 ) ;
V_41 . V_43 = V_44 ;
V_41 . V_45 = V_46 ;
V_41 . V_47 = V_48 ;
V_41 . V_49 = V_50 ;
V_41 . V_51 = V_52 ;
V_41 . V_53 = V_54 ;
F_25 ( V_41 . V_19 , L_6 , sizeof( V_41 . V_19 ) ) ;
V_41 . V_55 = V_4 ;
if ( ! V_4 -> V_56 ) {
V_4 -> V_56 = F_26 ( & V_41 , V_4 -> V_57 ,
V_4 -> line ) ;
}
if ( ! V_4 -> V_56 )
goto V_58;
V_4 -> V_59 = V_4 -> V_56 -> V_59 ;
V_39 = F_27 ( V_4 ) ;
if ( V_39 < 0 ) {
F_8 ( L_7 , V_17 ) ;
goto V_58;
}
return 0 ;
V_58:
F_23 ( & V_4 -> V_2 , 0 ) ;
return V_39 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_29 ( V_64 , V_65 ) ;
int V_66 ;
int V_67 = 0 ;
unsigned long V_35 ;
if ( F_30 ( V_61 ) ) {
F_31 ( V_2 , 1 ) ;
return 0 ;
}
if ( V_63 -> V_68 & V_69 ) {
if ( F_32 ( V_61 ) )
F_33 ( V_2 ) ;
F_31 ( V_2 , 1 ) ;
F_22 ( L_8 , V_17 ) ;
return 0 ;
}
if ( F_34 ( V_61 ) ) {
F_22 ( L_9 , V_17 ) ;
V_67 = 1 ;
}
V_66 = 0 ;
F_35 ( & V_2 -> V_70 , & V_64 ) ;
F_22 ( L_10 ,
__FILE__ , __LINE__ , V_61 -> V_12 -> V_19 , V_2 -> V_71 ) ;
F_36 ( & V_2 -> V_72 , V_35 ) ;
V_2 -> V_71 -- ;
V_2 -> V_73 ++ ;
F_37 ( & V_2 -> V_72 , V_35 ) ;
while ( 1 ) {
if ( F_32 ( V_61 ) && F_21 ( V_2 ) )
F_33 ( V_2 ) ;
F_38 ( V_74 ) ;
if ( F_39 ( V_63 ) || ! F_21 ( V_2 ) ) {
V_66 = ( V_2 -> V_35 & V_75 ) ?
- V_76 : - V_77 ;
break;
}
if ( ( V_67 || F_40 ( V_2 ) ) &&
V_4 -> V_78 == V_79 )
{
break;
}
if ( F_41 ( V_65 ) ) {
V_66 = - V_77 ;
break;
}
F_22 ( L_11 ,
__FILE__ , __LINE__ , V_61 -> V_12 -> V_19 , V_2 -> V_71 ) ;
F_42 () ;
}
F_43 ( V_80 ) ;
F_44 ( & V_2 -> V_70 , & V_64 ) ;
F_36 ( & V_2 -> V_72 , V_35 ) ;
if ( ! F_39 ( V_63 ) )
V_2 -> V_71 ++ ;
V_2 -> V_73 -- ;
F_37 ( & V_2 -> V_72 , V_35 ) ;
F_22 ( L_12 ,
__FILE__ , __LINE__ , V_61 -> V_12 -> V_19 , V_2 -> V_71 ) ;
if ( ! V_66 )
F_31 ( V_2 , 1 ) ;
return V_66 ;
}
static int F_45 ( struct V_81 * V_12 , struct V_60 * V_61 )
{
struct V_3 * V_4 ;
unsigned int line = V_61 -> V_82 ;
V_4 = F_46 ( V_15 , line , NULL ) ;
if ( ! V_4 ) {
V_4 = F_47 ( sizeof( struct V_3 ) , V_83 ) ;
if ( V_4 == NULL )
return - V_14 ;
F_48 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_37 = & V_84 ;
V_4 -> V_38 = V_85 ;
V_4 -> V_86 = V_87 ;
V_4 -> line = line ;
F_49 ( & V_4 -> V_88 , V_89 ) ;
V_4 -> V_90 = V_91 ;
V_4 -> V_92 = V_93 ;
F_50 ( & V_4 -> V_94 ) ;
F_51 ( & V_4 -> V_95 ) ;
V_61 -> V_96 . V_97 = 0 ;
V_61 -> V_96 . V_98 = 0 ;
F_52 ( V_15 , ( V_99 * ) V_4 , line , NULL ) ;
}
V_61 -> V_100 = V_4 ;
return F_53 ( & V_4 -> V_2 , V_12 , V_61 ) ;
}
static int F_54 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_3 * V_4 = V_61 -> V_100 ;
unsigned long V_35 ;
int V_39 ;
F_36 ( & V_4 -> V_2 . V_72 , V_35 ) ;
V_4 -> V_2 . V_71 ++ ;
F_37 ( & V_4 -> V_2 . V_72 , V_35 ) ;
F_55 ( & V_4 -> V_2 , V_61 ) ;
F_22 ( L_13 , V_17 , V_61 -> V_12 -> V_19 ,
V_4 -> line , V_4 -> V_2 . V_71 ) ;
V_4 -> V_2 . V_101 = ( V_4 -> V_2 . V_35 & V_102 ) ? 1 : 0 ;
if ( V_4 -> line < 0x10 ) {
V_4 -> V_57 = V_103 | V_104 ;
V_4 -> V_5 . V_57 = V_104 ;
V_4 -> V_5 . V_10 = V_105 | V_11 | V_106 | V_107 ;
F_22 ( L_14 , V_17 ) ;
} else {
F_22 ( L_15 , V_17 ) ;
V_4 -> V_57 = V_108 ;
V_4 -> V_5 . V_57 = V_108 ;
}
V_39 = F_20 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_28 ( V_4 , V_61 , V_63 ) ;
if ( V_39 ) {
F_22 ( L_16 ,
V_17 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
static void F_56 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_57 ( V_2 , V_61 , V_63 ) == 0 )
return;
F_14 ( V_4 ) ;
F_58 ( V_61 ) ;
F_59 ( V_2 , V_61 ) ;
F_55 ( V_2 , NULL ) ;
}
static void F_60 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_61 ( & V_4 -> V_88 ) ;
}
static void V_89 ( struct V_109 * V_110 )
{
struct V_3 * V_4 =
F_2 ( V_110 , struct V_3 , V_88 ) ;
struct V_60 * V_61 ;
unsigned long V_35 ;
struct V_111 * V_112 , * V_113 ;
if ( ! V_4 || V_4 -> V_38 != V_85 )
return;
V_61 = F_62 ( & V_4 -> V_2 ) ;
if ( ! V_61 )
return;
F_36 ( & V_4 -> V_95 , V_35 ) ;
V_113 = V_4 -> V_113 ;
V_4 -> V_113 = NULL ;
F_37 ( & V_4 -> V_95 , V_35 ) ;
if( V_113 ) {
if( V_4 -> V_86 == V_114 )
F_63 ( V_4 -> V_56 , V_113 ) ;
F_64 ( V_113 ) ;
}
if ( V_61 -> V_115 )
goto V_116;
F_36 ( & V_4 -> V_95 , V_35 ) ;
V_112 = V_4 -> V_117 ;
V_4 -> V_117 = NULL ;
F_37 ( & V_4 -> V_95 , V_35 ) ;
if ( V_112 ) {
F_65 ( V_4 , V_118 , V_112 , NULL ) ;
F_64 ( V_112 ) ;
}
F_66 ( V_61 ) ;
V_116:
F_67 ( V_61 ) ;
}
static int F_68 ( struct V_60 * V_61 ,
const unsigned char * V_119 , int V_71 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
unsigned long V_35 ;
struct V_111 * V_112 ;
int V_120 = 0 ;
int V_121 = 0 ;
int V_122 ;
F_22 ( L_17 , V_17 , V_71 ,
V_61 -> V_115 ) ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_4 -> V_90 == V_91 ) {
F_22 ( L_18 , V_17 ) ;
#ifdef F_69
return 0 ;
#endif
}
if ( V_71 < 1 )
return 0 ;
F_36 ( & V_4 -> V_95 , V_35 ) ;
V_112 = V_4 -> V_117 ;
while ( V_71 ) {
V_122 = V_71 ;
if ( V_122 > V_4 -> V_92 )
V_122 = V_4 -> V_92 ;
if ( V_112 ) {
if ( ( V_120 = ( V_4 -> V_123 - V_112 -> V_121 ) ) > 0 ) {
if ( V_122 > V_120 )
V_122 = V_120 ;
} else {
break;
}
} else {
V_112 = F_70 ( V_4 -> V_92 +
V_4 -> V_90 ,
V_124 ) ;
if ( ! V_112 ) {
F_37 ( & V_4 -> V_95 , V_35 ) ;
return - V_125 ;
}
F_71 ( V_112 , V_4 -> V_90 ) ;
V_4 -> V_117 = V_112 ;
V_4 -> V_123 = V_4 -> V_92 ;
}
memcpy ( F_72 ( V_112 , V_122 ) , V_119 + V_121 , V_122 ) ;
V_71 -= V_122 ;
V_121 += V_122 ;
}
F_37 ( & V_4 -> V_95 , V_35 ) ;
F_61 ( & V_4 -> V_88 ) ;
return V_121 ;
}
static int F_73 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
unsigned long V_35 ;
int V_39 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
#ifdef F_69
if ( V_4 -> V_90 == V_91 )
return 0 ;
#endif
if ( V_61 -> V_115 )
V_39 = 0 ;
else {
F_36 ( & V_4 -> V_95 , V_35 ) ;
if ( V_4 -> V_117 )
V_39 = V_4 -> V_123 - V_4 -> V_117 -> V_121 ;
else
V_39 = V_4 -> V_92 ;
F_37 ( & V_4 -> V_95 , V_35 ) ;
}
F_22 ( L_19 , V_17 , V_39 ) ;
return V_39 ;
}
static void F_74 ( struct V_60 * V_61 , int V_126 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
unsigned long V_127 , V_128 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_127 = V_129 ;
V_128 = F_75 ( 200 ) ;
if ( V_126 )
V_128 = F_76 (unsigned long, timeout, poll_time) ;
F_36 ( & V_4 -> V_95 , V_35 ) ;
while ( V_4 -> V_117 && V_4 -> V_117 -> V_121 ) {
F_37 ( & V_4 -> V_95 , V_35 ) ;
F_77 ( V_128 ) ;
F_36 ( & V_4 -> V_95 , V_35 ) ;
if ( F_41 ( V_65 ) )
break;
if ( V_126 && F_78 ( V_129 , V_127 + V_126 ) )
break;
}
F_37 ( & V_4 -> V_95 , V_35 ) ;
F_43 ( V_80 ) ;
}
static void F_79 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_80 ( V_61 ) )
F_81 ( V_61 , F_82 ( V_61 ) ) ;
if ( F_83 ( V_61 ) ) {
V_4 -> V_5 . V_6 &= ~ V_7 ;
V_4 -> V_5 . V_6 |= V_130 ;
F_3 ( V_4 , V_9 , TRUE ) ;
}
F_84 ( V_4 -> V_56 , V_87 ) ;
}
static void F_85 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( F_80 ( V_61 ) )
F_81 ( V_61 , F_86 ( V_61 ) ) ;
if ( F_83 ( V_61 ) ) {
V_4 -> V_5 . V_6 |= ( V_7 | V_130 ) ;
F_3 ( V_4 , V_9 , TRUE ) ;
F_22 ( L_20 , V_17 ) ;
}
F_84 ( V_4 -> V_56 , V_114 ) ;
}
static int F_87 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
unsigned long V_35 ;
int V_121 = 0 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_36 ( & V_4 -> V_95 , V_35 ) ;
if ( V_4 -> V_117 )
V_121 = V_4 -> V_117 -> V_121 ;
F_37 ( & V_4 -> V_95 , V_35 ) ;
return V_121 ;
}
static void F_14 ( struct V_3 * V_4 )
{
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( ! F_21 ( & V_4 -> V_2 ) )
return;
F_23 ( & V_4 -> V_2 , 0 ) ;
F_88 ( V_4 ) ;
F_36 ( & V_4 -> V_95 , V_35 ) ;
F_89 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_113 ) {
F_64 ( V_4 -> V_113 ) ;
V_4 -> V_113 = NULL ;
}
if ( V_4 -> V_117 ) {
F_64 ( V_4 -> V_117 ) ;
V_4 -> V_117 = NULL ;
}
if ( V_4 -> V_56 ) {
F_90 ( V_4 -> V_56 ) ;
V_4 -> V_56 = NULL ;
}
F_37 ( & V_4 -> V_95 , V_35 ) ;
}
static void F_91 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned long V_35 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_14 ( V_4 ) ;
F_36 ( & V_2 -> V_72 , V_35 ) ;
if ( V_2 -> V_61 ) {
F_92 ( V_131 , & V_2 -> V_61 -> V_35 ) ;
F_67 ( V_2 -> V_61 ) ;
}
V_2 -> V_61 = NULL ;
V_2 -> V_71 = 0 ;
F_37 ( & V_2 -> V_72 , V_35 ) ;
F_31 ( V_2 , 0 ) ;
F_93 ( & V_2 -> V_70 ) ;
}
static void F_81 ( struct V_60 * V_61 , char V_132 )
{
F_22 ( L_21 , V_17 ) ;
}
void F_94 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
F_84 ( V_4 -> V_56 , V_114 ) ;
}
static void F_95 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_100 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_84 ( V_4 -> V_56 , V_87 ) ;
}
void F_96 ( struct V_3 * V_4 )
{
struct V_60 * V_61 ;
int V_133 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_61 = F_62 ( & V_4 -> V_2 ) ;
V_133 = V_4 -> V_5 . V_10 ;
if ( V_133 & V_134 ) {
}
if ( F_97 ( & V_4 -> V_2 ) && ( V_133 & V_135 ) ) {
F_22 ( L_22 , V_17 , V_4 -> line ,
( V_133 & V_11 ) ? L_23 : L_24 ) ;
if ( V_133 & V_11 ) {
F_93 ( & V_4 -> V_2 . V_70 ) ;
} else {
F_22 ( L_25 , V_17 ) ;
if ( V_61 )
F_98 ( V_61 ) ;
goto V_116;
}
}
if ( V_61 && F_99 ( & V_4 -> V_2 ) ) {
if ( V_61 -> V_115 ) {
if ( V_133 & V_105 ) {
F_22 ( L_26 , V_17 ) ;
V_61 -> V_115 = 0 ;
F_93 ( & V_4 -> V_2 . V_70 ) ;
F_61 ( & V_4 -> V_88 ) ;
goto V_116;
}
} else {
if ( ! ( V_133 & V_105 ) ) {
F_22 ( L_27 , V_17 ) ;
V_61 -> V_115 = 1 ;
}
}
}
V_116:
F_67 ( V_61 ) ;
}
static int V_44 ( void * V_55 , void * V_136 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = (struct V_3 * ) V_55 ;
struct V_60 * V_61 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_61 = F_62 ( & V_4 -> V_2 ) ;
if ( ! V_61 ) {
F_22 ( L_28 , V_17 ) ;
return 0 ;
}
if ( V_61 -> V_115 && ( V_4 -> V_86 == V_114 ) ) {
F_22 ( L_29 , V_17 ) ;
F_3 ( V_4 , V_137 , TRUE ) ;
F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
}
F_67 ( V_61 ) ;
F_102 ( & V_4 -> V_2 , V_112 -> V_138 , V_112 -> V_121 ) ;
F_103 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int V_46 ( void * V_55 , void * V_136 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 = (struct V_3 * ) V_55 ;
int V_139 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_13 (skb != NULL, return -1;) ;
V_139 = V_112 -> V_138 [ 0 ] ;
F_104 ( V_4 , V_112 -> V_138 + 1 , F_105 ( V_112 -> V_121 - 1 , V_139 ) ,
& V_140 ) ;
return 0 ;
}
static void V_48 ( void * V_55 , void * V_136 ,
T_4 V_141 )
{
struct V_3 * V_4 = (struct V_3 * ) V_55 ;
struct V_60 * V_61 ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_61 = F_62 ( & V_4 -> V_2 ) ;
switch ( V_141 ) {
case V_114 :
F_22 ( L_30 , V_17 ) ;
if ( V_61 )
V_61 -> V_115 = 0 ;
F_61 ( & V_4 -> V_88 ) ;
break;
default:
case V_87 :
F_22 ( L_31 , V_17 ) ;
if ( V_61 )
V_61 -> V_115 = 1 ;
break;
}
F_67 ( V_61 ) ;
V_4 -> V_86 = V_141 ;
}
static void F_106 ( struct V_3 * V_4 , struct V_142 * V_143 )
{
struct V_60 * V_61 ;
char V_144 ;
F_107 ( V_143 , L_32 , V_145 [ V_4 -> V_78 ] ) ;
F_108 ( V_143 , L_33 ) ;
if ( V_4 -> V_57 & V_104 )
F_108 ( V_143 , L_34 ) ;
else if ( V_4 -> V_57 & V_103 )
F_108 ( V_143 , L_35 ) ;
else if ( V_4 -> V_57 & V_108 )
F_108 ( V_143 , L_36 ) ;
else
F_108 ( V_143 , L_37 ) ;
F_109 ( V_143 , '\n' ) ;
F_107 ( V_143 , L_38 , V_4 -> V_5 . V_146 ) ;
F_107 ( V_143 , L_39 ) ;
V_144 = ' ' ;
if ( V_4 -> V_5 . V_6 & V_7 ) {
F_107 ( V_143 , L_40 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_6 & V_8 ) {
F_107 ( V_143 , L_41 , V_144 ) ;
V_144 = '|' ;
}
F_109 ( V_143 , '\n' ) ;
F_108 ( V_143 , L_42 ) ;
V_144 = ' ' ;
if ( V_4 -> V_5 . V_10 & V_105 ) {
F_107 ( V_143 , L_43 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_106 ) {
F_107 ( V_143 , L_44 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_11 ) {
F_107 ( V_143 , L_45 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_10 & V_107 ) {
F_107 ( V_143 , L_46 , V_144 ) ;
V_144 = '|' ;
}
F_109 ( V_143 , '\n' ) ;
F_108 ( V_143 , L_47 ) ;
if ( ! V_4 -> V_5 . V_147 )
F_108 ( V_143 , L_48 ) ;
else
F_108 ( V_143 , L_49 ) ;
F_107 ( V_143 , L_50 , V_4 -> V_5 . V_148 ) ;
F_108 ( V_143 , L_51 ) ;
V_144 = ' ' ;
if ( V_4 -> V_5 . V_149 & V_150 ) {
F_107 ( V_143 , L_52 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_151 ) {
F_107 ( V_143 , L_53 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_152 ) {
F_107 ( V_143 , L_54 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_153 ) {
F_107 ( V_143 , L_55 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_154 ) {
F_107 ( V_143 , L_56 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_155 ) {
F_107 ( V_143 , L_57 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_156 ) {
F_107 ( V_143 , L_58 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_5 . V_149 & V_157 ) {
F_107 ( V_143 , L_59 , V_144 ) ;
V_144 = '|' ;
}
F_109 ( V_143 , '\n' ) ;
F_108 ( V_143 , L_60 ) ;
V_144 = ' ' ;
if ( F_99 ( & V_4 -> V_2 ) ) {
F_107 ( V_143 , L_61 , V_144 ) ;
V_144 = '|' ;
}
if ( F_97 ( & V_4 -> V_2 ) ) {
F_107 ( V_143 , L_62 , V_144 ) ;
V_144 = '|' ;
}
if ( F_21 ( & V_4 -> V_2 ) ) {
F_107 ( V_143 , L_63 , V_144 ) ;
V_144 = '|' ;
}
if ( V_4 -> V_2 . V_35 & V_102 ) {
F_107 ( V_143 , L_64 , V_144 ) ;
V_144 = '|' ;
}
if ( F_110 ( & V_4 -> V_2 ) ) {
F_107 ( V_143 , L_65 , V_144 ) ;
V_144 = '|' ;
}
F_109 ( V_143 , '\n' ) ;
F_107 ( V_143 , L_66 , V_4 -> V_158 ? L_67 : L_68 ) ;
F_107 ( V_143 , L_69 , V_4 -> V_2 . V_71 ) ;
F_107 ( V_143 , L_70 , V_4 -> V_92 ) ;
F_107 ( V_143 , L_71 , V_4 -> V_90 ) ;
V_61 = F_62 ( & V_4 -> V_2 ) ;
if ( V_61 ) {
F_107 ( V_143 , L_72 ,
V_61 -> V_115 ? L_73 : L_74 ) ;
F_67 ( V_61 ) ;
}
}
static int F_111 ( struct V_142 * V_143 , void * V_159 )
{
struct V_3 * V_4 ;
unsigned long V_35 ;
F_36 ( & V_15 -> V_160 , V_35 ) ;
V_4 = (struct V_3 * ) F_112 ( V_15 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_38 != V_85 )
break;
F_106 ( V_4 , V_143 ) ;
V_4 = (struct V_3 * ) F_113 ( V_15 ) ;
}
F_37 ( & V_15 -> V_160 , V_35 ) ;
return 0 ;
}
static int F_114 ( struct V_161 * V_161 , struct V_62 * V_62 )
{
return F_115 ( V_62 , F_111 , NULL ) ;
}
