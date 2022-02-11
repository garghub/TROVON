int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( V_6 [ V_2 -> V_3 ] )
return - V_7 ;
V_6 [ V_2 -> V_3 ] = V_2 ;
F_2 ( L_1 , V_2 -> V_8 ) ;
return 0 ;
}
int F_3 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( ! V_6 [ V_2 -> V_3 ] )
return - V_5 ;
V_6 [ V_2 -> V_3 ] = NULL ;
return 0 ;
}
static const struct V_1 * F_4 ( unsigned int V_3 )
{
if ( V_3 >= V_4 )
return NULL ;
return V_6 [ V_3 ] ;
}
static inline void F_5 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
switch ( V_11 ) {
case V_14 :
V_13 -> V_15 . V_16 ++ ;
break;
case V_17 :
V_13 -> V_15 . V_18 ++ ;
break;
case V_19 :
V_13 -> V_15 . V_20 ++ ;
break;
}
}
static inline struct V_21 * F_6 ( struct V_9 * V_10 )
{
struct V_21 * V_22 = V_10 -> V_23 ;
if ( ! V_22 )
V_22 = V_10 -> V_24 -> V_25 ( V_10 ) ;
else
V_10 -> V_23 = NULL ;
return V_22 ;
}
int F_7 ( struct V_9 * V_10 )
{
if ( F_8 ( V_26 , & V_10 -> V_27 ) ) {
F_9 ( V_28 , & V_10 -> V_27 ) ;
return 0 ;
}
F_10 ( L_2 ) ;
F_11 ( & V_10 -> V_29 ) ;
return 0 ;
}
static void F_12 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_13 ( V_31 , struct V_9 , V_29 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_21 * V_22 ;
V_34:
F_14 ( V_28 , & V_10 -> V_27 ) ;
while ( ( V_22 = F_6 ( V_10 ) ) ) {
int V_35 ;
F_9 ( V_36 , & V_33 -> V_37 ) ;
V_35 = V_33 -> V_38 -> V_39 ( V_33 , V_22 -> V_40 , V_22 -> V_35 ) ;
V_13 -> V_15 . V_41 += V_35 ;
F_15 ( V_22 , V_35 ) ;
if ( V_22 -> V_35 ) {
V_10 -> V_23 = V_22 ;
break;
}
F_5 ( V_10 , F_16 ( V_22 ) -> V_11 ) ;
F_17 ( V_22 ) ;
}
if ( F_18 ( V_28 , & V_10 -> V_27 ) )
goto V_34;
F_14 ( V_26 , & V_10 -> V_27 ) ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_13 ( V_31 , struct V_9 , V_42 ) ;
int V_43 ;
if ( ! F_20 ( V_44 , & V_10 -> V_45 ) )
return;
V_43 = F_21 ( V_10 -> V_13 ) ;
if ( V_43 < 0 ) {
F_22 ( L_3 ) ;
F_23 ( V_10 -> V_13 ) ;
V_10 -> V_13 = NULL ;
V_10 -> V_24 -> V_46 ( V_10 ) ;
}
F_9 ( V_47 , & V_10 -> V_37 ) ;
}
int F_24 ( struct V_9 * V_10 )
{
if ( ! F_18 ( V_44 , & V_10 -> V_45 ) )
return - V_48 ;
F_11 ( & V_10 -> V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
F_10 ( L_4 , V_13 -> V_8 , V_13 ) ;
F_9 ( V_49 , & V_13 -> V_37 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
F_10 ( L_5 , V_13 , V_33 ) ;
if ( V_10 -> V_23 ) {
F_17 ( V_10 -> V_23 ) ; V_10 -> V_23 = NULL ;
}
F_28 ( V_33 ) ;
F_29 ( V_33 ) ;
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
V_10 -> V_24 -> V_51 ( V_10 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_13 )
{
F_10 ( L_6 , V_13 ) ;
if ( ! F_20 ( V_49 , & V_13 -> V_37 ) )
return 0 ;
F_26 ( V_13 ) ;
V_13 -> V_51 = NULL ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
if ( ! F_18 ( V_49 , & V_13 -> V_37 ) )
return - V_52 ;
F_10 ( L_7 , V_13 -> V_8 , F_16 ( V_22 ) -> V_11 , V_22 -> V_35 ) ;
V_10 -> V_24 -> V_53 ( V_10 , V_22 ) ;
F_7 ( V_10 ) ;
return 0 ;
}
void F_32 ( struct V_9 * V_10 , bool V_54 )
{
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_55 V_55 ;
int V_56 ;
unsigned int V_57 = 0 ;
unsigned int V_58 = 0 ;
if ( V_54 ) {
V_55 = V_33 -> V_59 ;
V_55 . V_60 &= ~ V_61 ;
V_56 = F_33 ( V_33 , & V_55 ) ;
F_10 ( L_8 ,
V_56 ? L_9 : L_10 ) ;
V_56 = V_33 -> V_62 -> V_38 -> V_63 ( V_33 ) ;
F_10 ( L_11 , V_56 ) ;
V_57 &= ~ ( V_64 | V_65 ) ;
V_58 = ~ V_57 ;
V_57 &= V_66 | V_65 | V_67 |
V_64 | V_68 ;
V_58 &= V_66 | V_65 | V_67 |
V_64 | V_68 ;
V_56 = V_33 -> V_62 -> V_38 -> V_69 ( V_33 , V_57 , V_58 ) ;
F_10 ( L_12 , V_56 ? L_9 : L_10 ) ;
} else {
V_56 = V_33 -> V_62 -> V_38 -> V_63 ( V_33 ) ;
F_10 ( L_11 , V_56 ) ;
V_57 |= ( V_64 | V_65 ) ;
V_58 = ~ V_57 ;
V_57 &= V_66 | V_65 | V_67 |
V_64 | V_68 ;
V_58 &= V_66 | V_65 | V_67 |
V_64 | V_68 ;
V_56 = V_33 -> V_62 -> V_38 -> V_69 ( V_33 , V_57 , V_58 ) ;
F_10 ( L_13 , V_56 ? L_9 : L_10 ) ;
V_55 = V_33 -> V_59 ;
V_55 . V_60 |= V_61 ;
V_56 = F_33 ( V_33 , & V_55 ) ;
F_10 ( L_14 ,
V_56 ? L_9 : L_10 ) ;
}
}
void F_34 ( struct V_9 * V_10 , unsigned int V_70 ,
unsigned int V_71 )
{
V_10 -> V_70 = V_70 ;
V_10 -> V_71 = V_71 ;
}
void F_35 ( struct V_9 * V_10 )
{
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_55 V_55 ;
V_55 = V_33 -> V_59 ;
V_55 . V_72 &= ~ ( V_73 | V_74 | V_75 | V_76 |
V_77 | V_78 | V_79 | V_80 ) ;
V_55 . V_81 &= ~ V_82 ;
V_55 . V_83 &= ~ ( V_84 | V_85 | V_86 | V_87 | V_88 ) ;
V_55 . V_60 &= ~ ( V_89 | V_90 ) ;
V_55 . V_60 |= V_91 ;
V_55 . V_60 |= V_61 ;
F_33 ( V_33 , & V_55 ) ;
}
void F_36 ( struct V_9 * V_10 , unsigned int V_92 )
{
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_55 V_55 ;
V_55 = V_33 -> V_59 ;
V_55 . V_60 &= ~ V_93 ;
F_37 ( & V_55 , V_92 , V_92 ) ;
F_33 ( V_33 , & V_55 ) ;
F_10 ( L_15 , V_10 -> V_13 -> V_8 ,
V_33 -> V_59 . V_94 , V_33 -> V_59 . V_95 ) ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_96 * V_97 ;
struct V_21 * V_22 ;
unsigned int V_92 ;
int V_43 ;
if ( V_10 -> V_70 )
V_92 = V_10 -> V_70 ;
else if ( V_10 -> V_24 -> V_70 )
V_92 = V_10 -> V_24 -> V_70 ;
else
V_92 = 0 ;
if ( V_92 )
F_36 ( V_10 , V_92 ) ;
if ( V_10 -> V_71 )
V_92 = V_10 -> V_71 ;
else if ( V_10 -> V_24 -> V_71 )
V_92 = V_10 -> V_24 -> V_71 ;
else
V_92 = 0 ;
if ( V_10 -> V_24 -> V_98 && V_92 ) {
V_43 = V_10 -> V_24 -> V_98 ( V_10 , V_92 ) ;
if ( ! V_43 )
F_36 ( V_10 , V_92 ) ;
}
if ( V_10 -> V_24 -> V_99 )
return V_10 -> V_24 -> V_99 ( V_10 ) ;
if ( ! F_18 ( V_100 , & V_10 -> V_45 ) )
return 0 ;
V_22 = F_39 ( V_13 , V_101 , 0 , NULL ,
V_102 ) ;
if ( F_40 ( V_22 ) ) {
F_22 ( L_16 ,
V_13 -> V_8 , F_41 ( V_22 ) ) ;
return 0 ;
}
if ( V_22 -> V_35 != sizeof( * V_97 ) ) {
F_22 ( L_17 ,
V_13 -> V_8 ) ;
goto V_103;
}
V_97 = (struct V_96 * ) V_22 -> V_40 ;
switch ( F_42 ( V_97 -> V_104 ) ) {
#ifdef F_43
case 2 :
V_13 -> V_105 = V_106 ;
F_44 ( V_13 ) ;
break;
#endif
#ifdef F_45
case 15 :
V_13 -> V_105 = V_107 ;
F_46 ( V_13 ) ;
break;
#endif
}
V_103:
F_17 ( V_22 ) ;
return 0 ;
}
static int F_47 ( struct V_32 * V_33 )
{
struct V_9 * V_10 ;
F_10 ( L_18 , V_33 ) ;
if ( V_33 -> V_38 -> V_39 == NULL )
return - V_108 ;
V_10 = F_48 ( sizeof( struct V_9 ) , V_109 ) ;
if ( ! V_10 ) {
F_22 ( L_19 ) ;
return - V_110 ;
}
V_33 -> V_111 = V_10 ;
V_10 -> V_33 = V_33 ;
V_33 -> V_112 = 65536 ;
F_49 ( & V_10 -> V_42 , F_19 ) ;
F_49 ( & V_10 -> V_29 , F_12 ) ;
F_50 ( & V_10 -> V_113 ) ;
if ( V_33 -> V_114 -> V_38 -> V_115 )
V_33 -> V_114 -> V_38 -> V_115 ( V_33 ) ;
F_29 ( V_33 ) ;
return 0 ;
}
static void F_51 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_111 ;
struct V_12 * V_13 ;
F_10 ( L_18 , V_33 ) ;
V_33 -> V_111 = NULL ;
if ( ! V_10 )
return;
V_13 = V_10 -> V_13 ;
if ( V_13 )
F_30 ( V_13 ) ;
F_52 ( & V_10 -> V_29 ) ;
if ( F_20 ( V_50 , & V_10 -> V_37 ) ) {
if ( V_13 ) {
if ( F_18 ( V_47 , & V_10 -> V_37 ) )
F_53 ( V_13 ) ;
F_23 ( V_13 ) ;
}
V_10 -> V_24 -> V_46 ( V_10 ) ;
}
F_54 ( V_10 ) ;
}
static void F_55 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_111 ;
F_10 ( L_2 ) ;
if ( ! V_10 )
return;
F_14 ( V_36 , & V_33 -> V_37 ) ;
if ( V_33 != V_10 -> V_33 )
return;
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
F_7 ( V_10 ) ;
}
static void F_56 ( struct V_32 * V_33 , const T_1 * V_40 ,
char * V_37 , int V_116 )
{
struct V_9 * V_10 = V_33 -> V_111 ;
if ( ! V_10 || V_33 != V_10 -> V_33 )
return;
if ( ! F_18 ( V_50 , & V_10 -> V_37 ) )
return;
F_57 ( & V_10 -> V_113 ) ;
V_10 -> V_24 -> V_117 ( V_10 , V_40 , V_116 ) ;
if ( V_10 -> V_13 )
V_10 -> V_13 -> V_15 . V_118 += V_116 ;
F_58 ( & V_10 -> V_113 ) ;
F_59 ( V_33 ) ;
}
static int F_60 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
F_10 ( L_2 ) ;
V_13 = F_61 () ;
if ( ! V_13 ) {
F_22 ( L_20 ) ;
return - V_119 ;
}
V_10 -> V_13 = V_13 ;
V_13 -> V_120 = V_121 ;
F_62 ( V_13 , V_10 ) ;
V_13 -> V_122 = F_25 ;
V_13 -> V_46 = F_30 ;
V_13 -> V_51 = F_26 ;
V_13 -> V_123 = F_31 ;
V_13 -> V_99 = F_38 ;
F_63 ( V_13 , V_10 -> V_33 -> V_124 ) ;
if ( F_18 ( V_125 , & V_10 -> V_45 ) )
F_9 ( V_126 , & V_13 -> V_127 ) ;
if ( F_18 ( V_128 , & V_10 -> V_45 ) )
F_9 ( V_129 , & V_13 -> V_127 ) ;
if ( ! F_18 ( V_130 , & V_10 -> V_45 ) )
F_9 ( V_131 , & V_13 -> V_127 ) ;
if ( F_18 ( V_132 , & V_10 -> V_45 ) )
V_13 -> V_133 = V_134 ;
else
V_13 -> V_133 = V_135 ;
if ( F_18 ( V_44 , & V_10 -> V_45 ) )
return 0 ;
if ( F_21 ( V_13 ) < 0 ) {
F_22 ( L_3 ) ;
F_23 ( V_13 ) ;
return - V_136 ;
}
F_9 ( V_47 , & V_10 -> V_37 ) ;
return 0 ;
}
static int F_64 ( struct V_9 * V_10 , int V_3 )
{
const struct V_1 * V_2 ;
int V_43 ;
V_2 = F_4 ( V_3 ) ;
if ( ! V_2 )
return - V_137 ;
V_43 = V_2 -> V_122 ( V_10 ) ;
if ( V_43 )
return V_43 ;
V_10 -> V_24 = V_2 ;
V_43 = F_60 ( V_10 ) ;
if ( V_43 ) {
V_2 -> V_46 ( V_10 ) ;
return V_43 ;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_10 , unsigned long V_37 )
{
unsigned long V_138 = F_66 ( V_125 ) |
F_66 ( V_130 ) |
F_66 ( V_132 ) |
F_66 ( V_44 ) |
F_66 ( V_128 ) |
F_66 ( V_100 ) ;
if ( V_37 & ~ V_138 )
return - V_5 ;
V_10 -> V_45 = V_37 ;
return 0 ;
}
static int F_67 ( struct V_32 * V_33 , struct V_139 * V_139 ,
unsigned int V_140 , unsigned long V_141 )
{
struct V_9 * V_10 = V_33 -> V_111 ;
int V_43 = 0 ;
F_10 ( L_2 ) ;
if ( ! V_10 )
return - V_142 ;
switch ( V_140 ) {
case V_143 :
if ( ! F_8 ( V_50 , & V_10 -> V_37 ) ) {
V_43 = F_64 ( V_10 , V_141 ) ;
if ( V_43 ) {
F_14 ( V_50 , & V_10 -> V_37 ) ;
return V_43 ;
}
} else
return - V_52 ;
break;
case V_144 :
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
return V_10 -> V_24 -> V_3 ;
return - V_145 ;
case V_146 :
if ( F_18 ( V_47 , & V_10 -> V_37 ) )
return V_10 -> V_13 -> V_3 ;
return - V_145 ;
case V_147 :
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
return - V_52 ;
V_43 = F_65 ( V_10 , V_141 ) ;
if ( V_43 )
return V_43 ;
break;
case V_148 :
return V_10 -> V_45 ;
default:
V_43 = F_68 ( V_33 , V_139 , V_140 , V_141 ) ;
break;
}
return V_43 ;
}
static T_2 F_69 ( struct V_32 * V_33 , struct V_139 * V_139 ,
unsigned char T_3 * V_149 , T_4 V_150 )
{
return 0 ;
}
static T_2 F_70 ( struct V_32 * V_33 , struct V_139 * V_139 ,
const unsigned char * V_40 , T_4 V_116 )
{
return 0 ;
}
static unsigned int F_71 ( struct V_32 * V_33 ,
struct V_139 * V_151 , T_5 * V_152 )
{
return 0 ;
}
static int T_6 F_72 ( void )
{
static struct V_153 V_154 ;
int V_43 ;
F_2 ( L_21 , V_155 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = V_157 ;
V_154 . V_8 = L_22 ;
V_154 . V_122 = F_47 ;
V_154 . V_46 = F_51 ;
V_154 . V_158 = F_69 ;
V_154 . V_39 = F_70 ;
V_154 . V_159 = F_67 ;
V_154 . V_160 = F_71 ;
V_154 . V_161 = F_56 ;
V_154 . V_162 = F_55 ;
V_154 . V_163 = V_164 ;
V_43 = F_73 ( V_165 , & V_154 ) ;
if ( V_43 ) {
F_22 ( L_23 , V_43 ) ;
return V_43 ;
}
#ifdef F_74
F_75 () ;
#endif
#ifdef F_76
F_77 () ;
#endif
#ifdef F_78
F_79 () ;
#endif
#ifdef F_80
F_81 () ;
#endif
#ifdef F_82
F_83 () ;
#endif
#ifdef F_43
F_84 () ;
#endif
#ifdef F_45
F_85 () ;
#endif
#ifdef F_86
F_87 () ;
#endif
return 0 ;
}
static void T_7 F_88 ( void )
{
int V_43 ;
#ifdef F_74
F_89 () ;
#endif
#ifdef F_76
F_90 () ;
#endif
#ifdef F_78
F_91 () ;
#endif
#ifdef F_80
F_92 () ;
#endif
#ifdef F_82
F_93 () ;
#endif
#ifdef F_43
F_94 () ;
#endif
#ifdef F_45
F_95 () ;
#endif
#ifdef F_86
F_96 () ;
#endif
V_43 = F_97 ( V_165 ) ;
if ( V_43 )
F_22 ( L_24 , V_43 ) ;
}
