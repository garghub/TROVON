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
if ( F_7 ( V_24 , & V_10 -> V_25 ) )
V_22 = V_10 -> V_26 -> V_27 ( V_10 ) ;
} else {
V_10 -> V_23 = NULL ;
}
return V_22 ;
}
int F_8 ( struct V_9 * V_10 )
{
if ( ! F_7 ( V_24 , & V_10 -> V_25 ) )
return 0 ;
if ( F_9 ( V_28 , & V_10 -> V_29 ) ) {
F_10 ( V_30 , & V_10 -> V_29 ) ;
return 0 ;
}
F_11 ( L_2 ) ;
F_12 ( & V_10 -> V_31 ) ;
return 0 ;
}
static void F_13 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_14 ( V_33 , struct V_9 , V_31 ) ;
struct V_34 * V_35 = V_10 -> V_35 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_21 * V_22 ;
V_36:
F_15 ( V_30 , & V_10 -> V_29 ) ;
while ( ( V_22 = F_6 ( V_10 ) ) ) {
int V_37 ;
F_10 ( V_38 , & V_35 -> V_25 ) ;
V_37 = V_35 -> V_39 -> V_40 ( V_35 , V_22 -> V_41 , V_22 -> V_37 ) ;
V_13 -> V_15 . V_42 += V_37 ;
F_16 ( V_22 , V_37 ) ;
if ( V_22 -> V_37 ) {
V_10 -> V_23 = V_22 ;
break;
}
F_5 ( V_10 , F_17 ( V_22 ) ) ;
F_18 ( V_22 ) ;
}
if ( F_7 ( V_30 , & V_10 -> V_29 ) )
goto V_36;
F_15 ( V_28 , & V_10 -> V_29 ) ;
}
static void F_19 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_14 ( V_33 , struct V_9 , V_43 ) ;
int V_44 ;
struct V_12 * V_13 ;
if ( ! F_20 ( V_45 , & V_10 -> V_46 ) )
return;
V_44 = F_21 ( V_10 -> V_13 ) ;
if ( V_44 < 0 ) {
F_22 ( L_3 ) ;
V_13 = V_10 -> V_13 ;
V_10 -> V_13 = NULL ;
F_23 ( V_13 ) ;
F_15 ( V_24 , & V_10 -> V_25 ) ;
V_10 -> V_26 -> V_47 ( V_10 ) ;
return;
}
F_10 ( V_48 , & V_10 -> V_25 ) ;
}
int F_24 ( struct V_9 * V_10 )
{
if ( ! F_7 ( V_45 , & V_10 -> V_46 ) )
return - V_49 ;
F_12 ( & V_10 -> V_43 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
F_11 ( L_4 , V_13 -> V_8 , V_13 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_34 * V_35 = V_10 -> V_35 ;
F_11 ( L_5 , V_13 , V_35 ) ;
if ( V_10 -> V_23 ) {
F_18 ( V_10 -> V_23 ) ; V_10 -> V_23 = NULL ;
}
F_28 ( V_35 ) ;
F_29 ( V_35 ) ;
if ( F_7 ( V_24 , & V_10 -> V_25 ) )
V_10 -> V_26 -> V_50 ( V_10 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_13 )
{
F_11 ( L_6 , V_13 ) ;
F_26 ( V_13 ) ;
V_13 -> V_50 = NULL ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
F_11 ( L_7 , V_13 -> V_8 , F_17 ( V_22 ) ,
V_22 -> V_37 ) ;
if ( ! F_7 ( V_24 , & V_10 -> V_25 ) )
return - V_51 ;
V_10 -> V_26 -> V_52 ( V_10 , V_22 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
void F_32 ( struct V_9 * V_10 , bool V_53 )
{
struct V_34 * V_35 = V_10 -> V_35 ;
struct V_54 V_54 ;
int V_55 ;
unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
if ( V_53 ) {
V_54 = V_35 -> V_58 ;
V_54 . V_59 &= ~ V_60 ;
V_55 = F_33 ( V_35 , & V_54 ) ;
F_11 ( L_8 ,
V_55 ? L_9 : L_10 ) ;
V_55 = V_35 -> V_61 -> V_39 -> V_62 ( V_35 ) ;
F_11 ( L_11 , V_55 ) ;
V_56 &= ~ ( V_63 | V_64 ) ;
V_57 = ~ V_56 ;
V_56 &= V_65 | V_64 | V_66 |
V_63 | V_67 ;
V_57 &= V_65 | V_64 | V_66 |
V_63 | V_67 ;
V_55 = V_35 -> V_61 -> V_39 -> V_68 ( V_35 , V_56 , V_57 ) ;
F_11 ( L_12 , V_55 ? L_9 : L_10 ) ;
} else {
V_55 = V_35 -> V_61 -> V_39 -> V_62 ( V_35 ) ;
F_11 ( L_11 , V_55 ) ;
V_56 |= ( V_63 | V_64 ) ;
V_57 = ~ V_56 ;
V_56 &= V_65 | V_64 | V_66 |
V_63 | V_67 ;
V_57 &= V_65 | V_64 | V_66 |
V_63 | V_67 ;
V_55 = V_35 -> V_61 -> V_39 -> V_68 ( V_35 , V_56 , V_57 ) ;
F_11 ( L_13 , V_55 ? L_9 : L_10 ) ;
V_54 = V_35 -> V_58 ;
V_54 . V_59 |= V_60 ;
V_55 = F_33 ( V_35 , & V_54 ) ;
F_11 ( L_14 ,
V_55 ? L_9 : L_10 ) ;
}
}
void F_34 ( struct V_9 * V_10 , unsigned int V_69 ,
unsigned int V_70 )
{
V_10 -> V_69 = V_69 ;
V_10 -> V_70 = V_70 ;
}
void F_35 ( struct V_9 * V_10 , unsigned int V_71 )
{
struct V_34 * V_35 = V_10 -> V_35 ;
struct V_54 V_54 ;
V_54 = V_35 -> V_58 ;
V_54 . V_59 &= ~ V_72 ;
F_36 ( & V_54 , V_71 , V_71 ) ;
F_33 ( V_35 , & V_54 ) ;
F_11 ( L_15 , V_10 -> V_13 -> V_8 ,
V_35 -> V_58 . V_73 , V_35 -> V_58 . V_74 ) ;
}
static int F_37 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_75 * V_76 ;
struct V_21 * V_22 ;
unsigned int V_71 ;
int V_44 ;
if ( V_10 -> V_69 )
V_71 = V_10 -> V_69 ;
else if ( V_10 -> V_26 -> V_69 )
V_71 = V_10 -> V_26 -> V_69 ;
else
V_71 = 0 ;
if ( V_71 )
F_35 ( V_10 , V_71 ) ;
if ( V_10 -> V_70 )
V_71 = V_10 -> V_70 ;
else if ( V_10 -> V_26 -> V_70 )
V_71 = V_10 -> V_26 -> V_70 ;
else
V_71 = 0 ;
if ( V_10 -> V_26 -> V_77 && V_71 ) {
V_44 = V_10 -> V_26 -> V_77 ( V_10 , V_71 ) ;
if ( ! V_44 )
F_35 ( V_10 , V_71 ) ;
}
if ( V_10 -> V_26 -> V_78 )
return V_10 -> V_26 -> V_78 ( V_10 ) ;
if ( ! F_7 ( V_79 , & V_10 -> V_46 ) )
return 0 ;
V_22 = F_38 ( V_13 , V_80 , 0 , NULL ,
V_81 ) ;
if ( F_39 ( V_22 ) ) {
F_22 ( L_16 ,
V_13 -> V_8 , F_40 ( V_22 ) ) ;
return 0 ;
}
if ( V_22 -> V_37 != sizeof( * V_76 ) ) {
F_22 ( L_17 ,
V_13 -> V_8 ) ;
goto V_82;
}
V_76 = (struct V_75 * ) V_22 -> V_41 ;
switch ( F_41 ( V_76 -> V_83 ) ) {
#ifdef F_42
case 2 :
V_13 -> V_84 = V_85 ;
F_43 ( V_13 ) ;
break;
#endif
#ifdef F_44
case 15 :
V_13 -> V_84 = V_86 ;
F_45 ( V_13 ) ;
break;
#endif
}
V_82:
F_18 ( V_22 ) ;
return 0 ;
}
static int F_46 ( struct V_34 * V_35 )
{
struct V_9 * V_10 ;
F_11 ( L_18 , V_35 ) ;
if ( V_35 -> V_39 -> V_40 == NULL )
return - V_87 ;
V_10 = F_47 ( sizeof( struct V_9 ) , V_88 ) ;
if ( ! V_10 ) {
F_22 ( L_19 ) ;
return - V_89 ;
}
V_35 -> V_90 = V_10 ;
V_10 -> V_35 = V_35 ;
V_35 -> V_91 = 65536 ;
V_10 -> V_92 = 1 ;
V_10 -> V_93 = 0 ;
F_48 ( & V_10 -> V_43 , F_19 ) ;
F_48 ( & V_10 -> V_31 , F_13 ) ;
F_29 ( V_35 ) ;
return 0 ;
}
static void F_49 ( struct V_34 * V_35 )
{
struct V_9 * V_10 = V_35 -> V_90 ;
struct V_12 * V_13 ;
F_11 ( L_18 , V_35 ) ;
V_35 -> V_90 = NULL ;
if ( ! V_10 )
return;
V_13 = V_10 -> V_13 ;
if ( V_13 )
F_30 ( V_13 ) ;
F_50 ( & V_10 -> V_31 ) ;
if ( F_20 ( V_24 , & V_10 -> V_25 ) ) {
if ( V_13 ) {
if ( F_7 ( V_48 , & V_10 -> V_25 ) )
F_51 ( V_13 ) ;
F_23 ( V_13 ) ;
}
V_10 -> V_26 -> V_47 ( V_10 ) ;
}
F_15 ( V_94 , & V_10 -> V_25 ) ;
F_52 ( V_10 ) ;
}
static void F_53 ( struct V_34 * V_35 )
{
struct V_9 * V_10 = V_35 -> V_90 ;
F_11 ( L_2 ) ;
if ( ! V_10 )
return;
F_15 ( V_38 , & V_35 -> V_25 ) ;
if ( V_35 != V_10 -> V_35 )
return;
if ( F_7 ( V_24 , & V_10 -> V_25 ) )
F_8 ( V_10 ) ;
}
static void F_54 ( struct V_34 * V_35 , const T_1 * V_41 ,
char * V_25 , int V_95 )
{
struct V_9 * V_10 = V_35 -> V_90 ;
if ( ! V_10 || V_35 != V_10 -> V_35 )
return;
if ( ! F_7 ( V_24 , & V_10 -> V_25 ) )
return;
V_10 -> V_26 -> V_96 ( V_10 , V_41 , V_95 ) ;
if ( V_10 -> V_13 )
V_10 -> V_13 -> V_15 . V_97 += V_95 ;
F_55 ( V_35 ) ;
}
static int F_56 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
F_11 ( L_2 ) ;
V_13 = F_57 () ;
if ( ! V_13 ) {
F_22 ( L_20 ) ;
return - V_98 ;
}
V_10 -> V_13 = V_13 ;
V_13 -> V_99 = V_100 ;
F_58 ( V_13 , V_10 ) ;
if ( V_10 -> V_26 -> V_78 )
V_13 -> V_83 = V_10 -> V_26 -> V_83 ;
V_13 -> V_101 = F_25 ;
V_13 -> V_47 = F_30 ;
V_13 -> V_50 = F_26 ;
V_13 -> V_102 = F_31 ;
V_13 -> V_78 = F_37 ;
F_59 ( V_13 , V_10 -> V_35 -> V_103 ) ;
if ( F_7 ( V_104 , & V_10 -> V_46 ) )
F_10 ( V_105 , & V_13 -> V_106 ) ;
if ( F_7 ( V_107 , & V_10 -> V_46 ) )
F_10 ( V_108 , & V_13 -> V_106 ) ;
if ( ! F_7 ( V_109 , & V_10 -> V_46 ) )
F_10 ( V_110 , & V_13 -> V_106 ) ;
if ( F_7 ( V_111 , & V_10 -> V_46 ) )
V_13 -> V_112 = V_113 ;
else
V_13 -> V_112 = V_114 ;
if ( F_7 ( V_45 , & V_10 -> V_46 ) )
return 0 ;
if ( F_21 ( V_13 ) < 0 ) {
F_22 ( L_3 ) ;
V_10 -> V_13 = NULL ;
F_23 ( V_13 ) ;
return - V_115 ;
}
F_10 ( V_48 , & V_10 -> V_25 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_10 , int V_3 )
{
const struct V_1 * V_2 ;
int V_44 ;
V_2 = F_4 ( V_3 ) ;
if ( ! V_2 )
return - V_116 ;
V_44 = V_2 -> V_101 ( V_10 ) ;
if ( V_44 )
return V_44 ;
V_10 -> V_26 = V_2 ;
F_10 ( V_24 , & V_10 -> V_25 ) ;
V_44 = F_56 ( V_10 ) ;
if ( V_44 ) {
F_15 ( V_24 , & V_10 -> V_25 ) ;
V_2 -> V_47 ( V_10 ) ;
return V_44 ;
}
return 0 ;
}
static int F_61 ( struct V_9 * V_10 , unsigned long V_25 )
{
unsigned long V_117 = F_62 ( V_104 ) |
F_62 ( V_109 ) |
F_62 ( V_111 ) |
F_62 ( V_45 ) |
F_62 ( V_107 ) |
F_62 ( V_79 ) ;
if ( V_25 & ~ V_117 )
return - V_5 ;
V_10 -> V_46 = V_25 ;
return 0 ;
}
static int F_63 ( struct V_34 * V_35 , struct V_118 * V_118 ,
unsigned int V_119 , unsigned long V_120 )
{
struct V_9 * V_10 = V_35 -> V_90 ;
int V_44 = 0 ;
F_11 ( L_2 ) ;
if ( ! V_10 )
return - V_121 ;
switch ( V_119 ) {
case V_122 :
if ( ! F_9 ( V_94 , & V_10 -> V_25 ) ) {
V_44 = F_60 ( V_10 , V_120 ) ;
if ( V_44 )
F_15 ( V_94 , & V_10 -> V_25 ) ;
} else
V_44 = - V_123 ;
break;
case V_124 :
if ( F_7 ( V_94 , & V_10 -> V_25 ) )
V_44 = V_10 -> V_26 -> V_3 ;
else
V_44 = - V_51 ;
break;
case V_125 :
if ( F_7 ( V_48 , & V_10 -> V_25 ) )
V_44 = V_10 -> V_13 -> V_3 ;
else
V_44 = - V_51 ;
break;
case V_126 :
if ( F_7 ( V_94 , & V_10 -> V_25 ) )
V_44 = - V_123 ;
else
V_44 = F_61 ( V_10 , V_120 ) ;
break;
case V_127 :
V_44 = V_10 -> V_46 ;
break;
default:
V_44 = F_64 ( V_35 , V_118 , V_119 , V_120 ) ;
break;
}
return V_44 ;
}
static T_2 F_65 ( struct V_34 * V_35 , struct V_118 * V_118 ,
unsigned char T_3 * V_128 , T_4 V_129 )
{
return 0 ;
}
static T_2 F_66 ( struct V_34 * V_35 , struct V_118 * V_118 ,
const unsigned char * V_41 , T_4 V_95 )
{
return 0 ;
}
static unsigned int F_67 ( struct V_34 * V_35 ,
struct V_118 * V_130 , T_5 * V_131 )
{
return 0 ;
}
static int T_6 F_68 ( void )
{
static struct V_132 V_133 ;
int V_44 ;
F_2 ( L_21 , V_134 ) ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_135 = V_136 ;
V_133 . V_8 = L_22 ;
V_133 . V_101 = F_46 ;
V_133 . V_47 = F_49 ;
V_133 . V_137 = F_65 ;
V_133 . V_40 = F_66 ;
V_133 . V_138 = F_63 ;
V_133 . V_139 = F_67 ;
V_133 . V_140 = F_54 ;
V_133 . V_141 = F_53 ;
V_133 . V_142 = V_143 ;
V_44 = F_69 ( V_144 , & V_133 ) ;
if ( V_44 ) {
F_22 ( L_23 , V_44 ) ;
return V_44 ;
}
#ifdef F_70
F_71 () ;
#endif
#ifdef F_72
F_73 () ;
#endif
#ifdef F_74
F_75 () ;
#endif
#ifdef F_76
F_77 () ;
#endif
#ifdef F_78
F_79 () ;
#endif
#ifdef F_42
F_80 () ;
#endif
#ifdef F_44
F_81 () ;
#endif
#ifdef F_82
F_83 () ;
#endif
#ifdef F_84
F_85 () ;
#endif
#ifdef F_86
F_87 () ;
#endif
return 0 ;
}
static void T_7 F_88 ( void )
{
int V_44 ;
#ifdef F_70
F_89 () ;
#endif
#ifdef F_72
F_90 () ;
#endif
#ifdef F_74
F_91 () ;
#endif
#ifdef F_76
F_92 () ;
#endif
#ifdef F_78
F_93 () ;
#endif
#ifdef F_42
F_94 () ;
#endif
#ifdef F_44
F_95 () ;
#endif
#ifdef F_82
F_96 () ;
#endif
#ifdef F_84
F_97 () ;
#endif
#ifdef F_86
F_98 () ;
#endif
V_44 = F_99 ( V_144 ) ;
if ( V_44 )
F_22 ( L_24 , V_44 ) ;
}
