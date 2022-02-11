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
if ( ! V_22 ) {
F_7 ( & V_10 -> V_24 ) ;
if ( F_8 ( V_25 , & V_10 -> V_26 ) )
V_22 = V_10 -> V_27 -> V_28 ( V_10 ) ;
F_9 ( & V_10 -> V_24 ) ;
} else {
V_10 -> V_23 = NULL ;
}
return V_22 ;
}
int F_10 ( struct V_9 * V_10 )
{
F_7 ( & V_10 -> V_24 ) ;
if ( ! F_8 ( V_25 , & V_10 -> V_26 ) )
goto V_29;
if ( F_11 ( V_30 , & V_10 -> V_31 ) ) {
F_12 ( V_32 , & V_10 -> V_31 ) ;
goto V_29;
}
F_13 ( L_2 ) ;
F_14 ( & V_10 -> V_33 ) ;
V_29:
F_9 ( & V_10 -> V_24 ) ;
return 0 ;
}
static void F_15 ( struct V_34 * V_35 )
{
struct V_9 * V_10 = F_16 ( V_35 , struct V_9 , V_33 ) ;
struct V_36 * V_37 = V_10 -> V_37 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_21 * V_22 ;
V_38:
F_17 ( V_32 , & V_10 -> V_31 ) ;
while ( ( V_22 = F_6 ( V_10 ) ) ) {
int V_39 ;
F_12 ( V_40 , & V_37 -> V_26 ) ;
V_39 = V_37 -> V_41 -> V_42 ( V_37 , V_22 -> V_43 , V_22 -> V_39 ) ;
V_13 -> V_15 . V_44 += V_39 ;
F_18 ( V_22 , V_39 ) ;
if ( V_22 -> V_39 ) {
V_10 -> V_23 = V_22 ;
break;
}
F_5 ( V_10 , F_19 ( V_22 ) ) ;
F_20 ( V_22 ) ;
}
if ( F_8 ( V_32 , & V_10 -> V_31 ) )
goto V_38;
F_17 ( V_30 , & V_10 -> V_31 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_9 * V_10 = F_16 ( V_35 , struct V_9 , V_45 ) ;
int V_46 ;
struct V_12 * V_13 ;
if ( ! F_22 ( V_47 , & V_10 -> V_48 ) )
return;
V_46 = F_23 ( V_10 -> V_13 ) ;
if ( V_46 < 0 ) {
F_24 ( L_3 ) ;
V_13 = V_10 -> V_13 ;
V_10 -> V_13 = NULL ;
F_25 ( V_13 ) ;
F_17 ( V_25 , & V_10 -> V_26 ) ;
V_10 -> V_27 -> V_49 ( V_10 ) ;
return;
}
F_12 ( V_50 , & V_10 -> V_26 ) ;
}
int F_26 ( struct V_9 * V_10 )
{
if ( ! F_8 ( V_47 , & V_10 -> V_48 ) )
return - V_51 ;
F_14 ( & V_10 -> V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 )
{
F_13 ( L_4 , V_13 -> V_8 , V_13 ) ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_29 ( V_13 ) ;
struct V_36 * V_37 = V_10 -> V_37 ;
F_13 ( L_5 , V_13 , V_37 ) ;
if ( V_10 -> V_23 ) {
F_20 ( V_10 -> V_23 ) ; V_10 -> V_23 = NULL ;
}
F_30 ( V_37 ) ;
F_31 ( V_37 ) ;
F_7 ( & V_10 -> V_24 ) ;
if ( F_8 ( V_25 , & V_10 -> V_26 ) )
V_10 -> V_27 -> V_52 ( V_10 ) ;
F_9 ( & V_10 -> V_24 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
F_13 ( L_6 , V_13 ) ;
F_28 ( V_13 ) ;
V_13 -> V_52 = NULL ;
return 0 ;
}
static int F_33 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_9 * V_10 = F_29 ( V_13 ) ;
F_13 ( L_7 , V_13 -> V_8 , F_19 ( V_22 ) ,
V_22 -> V_39 ) ;
F_7 ( & V_10 -> V_24 ) ;
if ( ! F_8 ( V_25 , & V_10 -> V_26 ) ) {
F_9 ( & V_10 -> V_24 ) ;
return - V_53 ;
}
V_10 -> V_27 -> V_54 ( V_10 , V_22 ) ;
F_9 ( & V_10 -> V_24 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
void F_34 ( struct V_9 * V_10 , bool V_55 )
{
struct V_36 * V_37 = V_10 -> V_37 ;
struct V_56 V_56 ;
int V_57 ;
unsigned int V_58 = 0 ;
unsigned int V_59 = 0 ;
if ( V_55 ) {
V_56 = V_37 -> V_60 ;
V_56 . V_61 &= ~ V_62 ;
V_57 = F_35 ( V_37 , & V_56 ) ;
F_13 ( L_8 ,
V_57 ? L_9 : L_10 ) ;
V_57 = V_37 -> V_63 -> V_41 -> V_64 ( V_37 ) ;
F_13 ( L_11 , V_57 ) ;
V_58 &= ~ ( V_65 | V_66 ) ;
V_59 = ~ V_58 ;
V_58 &= V_67 | V_66 | V_68 |
V_65 | V_69 ;
V_59 &= V_67 | V_66 | V_68 |
V_65 | V_69 ;
V_57 = V_37 -> V_63 -> V_41 -> V_70 ( V_37 , V_58 , V_59 ) ;
F_13 ( L_12 , V_57 ? L_9 : L_10 ) ;
} else {
V_57 = V_37 -> V_63 -> V_41 -> V_64 ( V_37 ) ;
F_13 ( L_11 , V_57 ) ;
V_58 |= ( V_65 | V_66 ) ;
V_59 = ~ V_58 ;
V_58 &= V_67 | V_66 | V_68 |
V_65 | V_69 ;
V_59 &= V_67 | V_66 | V_68 |
V_65 | V_69 ;
V_57 = V_37 -> V_63 -> V_41 -> V_70 ( V_37 , V_58 , V_59 ) ;
F_13 ( L_13 , V_57 ? L_9 : L_10 ) ;
V_56 = V_37 -> V_60 ;
V_56 . V_61 |= V_62 ;
V_57 = F_35 ( V_37 , & V_56 ) ;
F_13 ( L_14 ,
V_57 ? L_9 : L_10 ) ;
}
}
void F_36 ( struct V_9 * V_10 , unsigned int V_71 ,
unsigned int V_72 )
{
V_10 -> V_71 = V_71 ;
V_10 -> V_72 = V_72 ;
}
void F_37 ( struct V_9 * V_10 , unsigned int V_73 )
{
struct V_36 * V_37 = V_10 -> V_37 ;
struct V_56 V_56 ;
V_56 = V_37 -> V_60 ;
V_56 . V_61 &= ~ V_74 ;
F_38 ( & V_56 , V_73 , V_73 ) ;
F_35 ( V_37 , & V_56 ) ;
F_13 ( L_15 , V_10 -> V_13 -> V_8 ,
V_37 -> V_60 . V_75 , V_37 -> V_60 . V_76 ) ;
}
static int F_39 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_29 ( V_13 ) ;
struct V_77 * V_78 ;
struct V_21 * V_22 ;
unsigned int V_73 ;
int V_46 ;
if ( V_10 -> V_71 )
V_73 = V_10 -> V_71 ;
else if ( V_10 -> V_27 -> V_71 )
V_73 = V_10 -> V_27 -> V_71 ;
else
V_73 = 0 ;
if ( V_73 )
F_37 ( V_10 , V_73 ) ;
if ( V_10 -> V_72 )
V_73 = V_10 -> V_72 ;
else if ( V_10 -> V_27 -> V_72 )
V_73 = V_10 -> V_27 -> V_72 ;
else
V_73 = 0 ;
if ( V_10 -> V_27 -> V_79 && V_73 ) {
V_46 = V_10 -> V_27 -> V_79 ( V_10 , V_73 ) ;
if ( ! V_46 )
F_37 ( V_10 , V_73 ) ;
}
if ( V_10 -> V_27 -> V_80 )
return V_10 -> V_27 -> V_80 ( V_10 ) ;
if ( ! F_8 ( V_81 , & V_10 -> V_48 ) )
return 0 ;
V_22 = F_40 ( V_13 , V_82 , 0 , NULL ,
V_83 ) ;
if ( F_41 ( V_22 ) ) {
F_24 ( L_16 ,
V_13 -> V_8 , F_42 ( V_22 ) ) ;
return 0 ;
}
if ( V_22 -> V_39 != sizeof( * V_78 ) ) {
F_24 ( L_17 ,
V_13 -> V_8 ) ;
goto V_84;
}
V_78 = (struct V_77 * ) V_22 -> V_43 ;
switch ( F_43 ( V_78 -> V_85 ) ) {
#ifdef F_44
case 2 :
V_13 -> V_86 = V_87 ;
F_45 ( V_13 ) ;
break;
#endif
#ifdef F_46
case 15 :
V_13 -> V_86 = V_88 ;
F_47 ( V_13 ) ;
break;
#endif
}
V_84:
F_20 ( V_22 ) ;
return 0 ;
}
static int F_48 ( struct V_36 * V_37 )
{
struct V_9 * V_10 ;
F_13 ( L_18 , V_37 ) ;
if ( V_37 -> V_41 -> V_42 == NULL )
return - V_89 ;
V_10 = F_49 ( sizeof( struct V_9 ) , V_90 ) ;
if ( ! V_10 ) {
F_24 ( L_19 ) ;
return - V_91 ;
}
V_37 -> V_92 = V_10 ;
V_10 -> V_37 = V_37 ;
V_37 -> V_93 = 65536 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 0 ;
F_50 ( & V_10 -> V_45 , F_21 ) ;
F_50 ( & V_10 -> V_33 , F_15 ) ;
F_51 ( & V_10 -> V_24 ) ;
F_31 ( V_37 ) ;
return 0 ;
}
static void F_52 ( struct V_36 * V_37 )
{
struct V_9 * V_10 = V_37 -> V_92 ;
struct V_12 * V_13 ;
unsigned long V_26 ;
F_13 ( L_18 , V_37 ) ;
V_37 -> V_92 = NULL ;
if ( ! V_10 )
return;
V_13 = V_10 -> V_13 ;
if ( V_13 )
F_32 ( V_13 ) ;
F_53 ( & V_10 -> V_33 ) ;
if ( F_8 ( V_25 , & V_10 -> V_26 ) ) {
F_54 ( & V_10 -> V_24 , V_26 ) ;
F_17 ( V_25 , & V_10 -> V_26 ) ;
F_55 ( & V_10 -> V_24 , V_26 ) ;
if ( V_13 ) {
if ( F_8 ( V_50 , & V_10 -> V_26 ) )
F_56 ( V_13 ) ;
F_25 ( V_13 ) ;
}
V_10 -> V_27 -> V_49 ( V_10 ) ;
}
F_17 ( V_96 , & V_10 -> V_26 ) ;
F_57 ( V_10 ) ;
}
static void F_58 ( struct V_36 * V_37 )
{
struct V_9 * V_10 = V_37 -> V_92 ;
F_13 ( L_2 ) ;
if ( ! V_10 )
return;
F_17 ( V_40 , & V_37 -> V_26 ) ;
if ( V_37 != V_10 -> V_37 )
return;
if ( F_8 ( V_25 , & V_10 -> V_26 ) )
F_10 ( V_10 ) ;
}
static void F_59 ( struct V_36 * V_37 , const T_1 * V_43 ,
char * V_26 , int V_97 )
{
struct V_9 * V_10 = V_37 -> V_92 ;
if ( ! V_10 || V_37 != V_10 -> V_37 )
return;
F_7 ( & V_10 -> V_24 ) ;
if ( ! F_8 ( V_25 , & V_10 -> V_26 ) ) {
F_9 ( & V_10 -> V_24 ) ;
return;
}
V_10 -> V_27 -> V_98 ( V_10 , V_43 , V_97 ) ;
F_9 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_13 )
V_10 -> V_13 -> V_15 . V_99 += V_97 ;
F_60 ( V_37 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
F_13 ( L_2 ) ;
V_13 = F_62 () ;
if ( ! V_13 ) {
F_24 ( L_20 ) ;
return - V_100 ;
}
V_10 -> V_13 = V_13 ;
V_13 -> V_101 = V_102 ;
F_63 ( V_13 , V_10 ) ;
if ( V_10 -> V_27 -> V_80 )
V_13 -> V_85 = V_10 -> V_27 -> V_85 ;
V_13 -> V_103 = F_27 ;
V_13 -> V_49 = F_32 ;
V_13 -> V_52 = F_28 ;
V_13 -> V_104 = F_33 ;
V_13 -> V_80 = F_39 ;
F_64 ( V_13 , V_10 -> V_37 -> V_105 ) ;
if ( F_8 ( V_106 , & V_10 -> V_48 ) )
F_12 ( V_107 , & V_13 -> V_108 ) ;
if ( F_8 ( V_109 , & V_10 -> V_48 ) )
F_12 ( V_110 , & V_13 -> V_108 ) ;
if ( ! F_8 ( V_111 , & V_10 -> V_48 ) )
F_12 ( V_112 , & V_13 -> V_108 ) ;
if ( F_8 ( V_113 , & V_10 -> V_48 ) )
V_13 -> V_114 = V_115 ;
else
V_13 -> V_114 = V_116 ;
if ( F_8 ( V_47 , & V_10 -> V_48 ) )
return 0 ;
if ( F_23 ( V_13 ) < 0 ) {
F_24 ( L_3 ) ;
V_10 -> V_13 = NULL ;
F_25 ( V_13 ) ;
return - V_117 ;
}
F_12 ( V_50 , & V_10 -> V_26 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 , int V_3 )
{
const struct V_1 * V_2 ;
int V_46 ;
V_2 = F_4 ( V_3 ) ;
if ( ! V_2 )
return - V_118 ;
V_46 = V_2 -> V_103 ( V_10 ) ;
if ( V_46 )
return V_46 ;
V_10 -> V_27 = V_2 ;
F_12 ( V_25 , & V_10 -> V_26 ) ;
V_46 = F_61 ( V_10 ) ;
if ( V_46 ) {
F_17 ( V_25 , & V_10 -> V_26 ) ;
V_2 -> V_49 ( V_10 ) ;
return V_46 ;
}
return 0 ;
}
static int F_66 ( struct V_9 * V_10 , unsigned long V_26 )
{
unsigned long V_119 = F_67 ( V_106 ) |
F_67 ( V_111 ) |
F_67 ( V_113 ) |
F_67 ( V_47 ) |
F_67 ( V_109 ) |
F_67 ( V_81 ) ;
if ( V_26 & ~ V_119 )
return - V_5 ;
V_10 -> V_48 = V_26 ;
return 0 ;
}
static int F_68 ( struct V_36 * V_37 , struct V_120 * V_120 ,
unsigned int V_121 , unsigned long V_122 )
{
struct V_9 * V_10 = V_37 -> V_92 ;
int V_46 = 0 ;
F_13 ( L_2 ) ;
if ( ! V_10 )
return - V_123 ;
switch ( V_121 ) {
case V_124 :
if ( ! F_11 ( V_96 , & V_10 -> V_26 ) ) {
V_46 = F_65 ( V_10 , V_122 ) ;
if ( V_46 )
F_17 ( V_96 , & V_10 -> V_26 ) ;
} else
V_46 = - V_125 ;
break;
case V_126 :
if ( F_8 ( V_96 , & V_10 -> V_26 ) )
V_46 = V_10 -> V_27 -> V_3 ;
else
V_46 = - V_53 ;
break;
case V_127 :
if ( F_8 ( V_50 , & V_10 -> V_26 ) )
V_46 = V_10 -> V_13 -> V_3 ;
else
V_46 = - V_53 ;
break;
case V_128 :
if ( F_8 ( V_96 , & V_10 -> V_26 ) )
V_46 = - V_125 ;
else
V_46 = F_66 ( V_10 , V_122 ) ;
break;
case V_129 :
V_46 = V_10 -> V_48 ;
break;
default:
V_46 = F_69 ( V_37 , V_120 , V_121 , V_122 ) ;
break;
}
return V_46 ;
}
static T_2 F_70 ( struct V_36 * V_37 , struct V_120 * V_120 ,
unsigned char T_3 * V_130 , T_4 V_131 )
{
return 0 ;
}
static T_2 F_71 ( struct V_36 * V_37 , struct V_120 * V_120 ,
const unsigned char * V_43 , T_4 V_97 )
{
return 0 ;
}
static unsigned int F_72 ( struct V_36 * V_37 ,
struct V_120 * V_132 , T_5 * V_133 )
{
return 0 ;
}
static int T_6 F_73 ( void )
{
static struct V_134 V_135 ;
int V_46 ;
F_2 ( L_21 , V_136 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_137 = V_138 ;
V_135 . V_8 = L_22 ;
V_135 . V_103 = F_48 ;
V_135 . V_49 = F_52 ;
V_135 . V_139 = F_70 ;
V_135 . V_42 = F_71 ;
V_135 . V_140 = F_68 ;
V_135 . V_141 = F_72 ;
V_135 . V_142 = F_59 ;
V_135 . V_143 = F_58 ;
V_135 . V_144 = V_145 ;
V_46 = F_74 ( V_146 , & V_135 ) ;
if ( V_46 ) {
F_24 ( L_23 , V_46 ) ;
return V_46 ;
}
#ifdef F_75
F_76 () ;
#endif
#ifdef F_77
F_78 () ;
#endif
#ifdef F_79
F_80 () ;
#endif
#ifdef F_81
F_82 () ;
#endif
#ifdef F_83
F_84 () ;
#endif
#ifdef F_44
F_85 () ;
#endif
#ifdef F_46
F_86 () ;
#endif
#ifdef F_87
F_88 () ;
#endif
#ifdef F_89
F_90 () ;
#endif
#ifdef F_91
F_92 () ;
#endif
return 0 ;
}
static void T_7 F_93 ( void )
{
int V_46 ;
#ifdef F_75
F_94 () ;
#endif
#ifdef F_77
F_95 () ;
#endif
#ifdef F_79
F_96 () ;
#endif
#ifdef F_81
F_97 () ;
#endif
#ifdef F_83
F_98 () ;
#endif
#ifdef F_44
F_99 () ;
#endif
#ifdef F_46
F_100 () ;
#endif
#ifdef F_87
F_101 () ;
#endif
#ifdef F_89
F_102 () ;
#endif
#ifdef F_91
F_103 () ;
#endif
V_46 = F_104 ( V_146 ) ;
if ( V_46 )
F_24 ( L_24 , V_46 ) ;
}
