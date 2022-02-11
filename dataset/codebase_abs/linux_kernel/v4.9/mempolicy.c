struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_1 ;
int V_5 ;
if ( V_4 )
return V_4 ;
V_5 = F_2 () ;
if ( V_5 != V_6 ) {
V_4 = & V_7 [ V_5 ] ;
if ( V_4 -> V_8 )
return V_4 ;
}
return & V_9 ;
}
static inline int F_3 ( const struct V_1 * V_4 )
{
return V_4 -> V_10 & V_11 ;
}
static void F_4 ( T_1 * V_12 , const T_1 * V_13 ,
const T_1 * V_14 )
{
T_1 V_15 ;
F_5 ( V_15 , * V_13 , F_6 ( * V_14 ) ) ;
F_7 ( * V_12 , V_15 , * V_14 ) ;
}
static int F_8 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( F_9 ( * V_16 ) )
return - V_17 ;
V_4 -> V_18 . V_16 = * V_16 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( ! V_16 )
V_4 -> V_10 |= V_19 ;
else if ( F_9 ( * V_16 ) )
return - V_17 ;
else
V_4 -> V_18 . V_20 = F_11 ( * V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( F_9 ( * V_16 ) )
return - V_17 ;
V_4 -> V_18 . V_16 = * V_16 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_4 ,
const T_1 * V_16 , struct V_21 * V_22 )
{
int V_12 ;
if ( V_4 == NULL )
return 0 ;
F_14 ( V_22 -> V_23 ,
V_24 , V_25 [ V_26 ] ) ;
F_15 ( ! V_16 ) ;
if ( V_4 -> V_8 == V_27 && F_9 ( * V_16 ) )
V_16 = NULL ;
else {
if ( V_4 -> V_10 & V_28 )
F_4 ( & V_22 -> V_29 , V_16 , & V_22 -> V_23 ) ;
else
F_14 ( V_22 -> V_29 , * V_16 , V_22 -> V_23 ) ;
if ( F_3 ( V_4 ) )
V_4 -> V_30 . V_31 = * V_16 ;
else
V_4 -> V_30 . V_32 =
V_24 ;
}
if ( V_16 )
V_12 = V_33 [ V_4 -> V_8 ] . F_16 ( V_4 , & V_22 -> V_29 ) ;
else
V_12 = V_33 [ V_4 -> V_8 ] . F_16 ( V_4 , NULL ) ;
return V_12 ;
}
static struct V_1 * F_17 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_34 ;
F_18 ( L_1 ,
V_8 , V_10 , V_16 ? F_19 ( * V_16 ) [ 0 ] : V_6 ) ;
if ( V_8 == V_35 ) {
if ( V_16 && ! F_9 ( * V_16 ) )
return F_20 ( - V_17 ) ;
return NULL ;
}
F_15 ( ! V_16 ) ;
if ( V_8 == V_27 ) {
if ( F_9 ( * V_16 ) ) {
if ( ( ( V_10 & V_36 ) ||
( V_10 & V_28 ) ) )
return F_20 ( - V_17 ) ;
}
} else if ( V_8 == V_37 ) {
if ( ! F_9 ( * V_16 ) )
return F_20 ( - V_17 ) ;
V_8 = V_27 ;
} else if ( F_9 ( * V_16 ) )
return F_20 ( - V_17 ) ;
V_34 = F_21 ( V_38 , V_39 ) ;
if ( ! V_34 )
return F_20 ( - V_40 ) ;
F_22 ( & V_34 -> V_41 , 1 ) ;
V_34 -> V_8 = V_8 ;
V_34 -> V_10 = V_10 ;
return V_34 ;
}
void F_23 ( struct V_1 * V_3 )
{
if ( ! F_24 ( & V_3 -> V_41 ) )
return;
F_25 ( V_38 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_4 , const T_1 * V_16 ,
enum V_42 V_43 )
{
}
static void F_27 ( struct V_1 * V_4 , const T_1 * V_16 ,
enum V_42 V_43 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 )
F_14 ( V_15 , V_4 -> V_30 . V_31 , * V_16 ) ;
else if ( V_4 -> V_10 & V_28 )
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
else {
if ( V_43 == V_44 || V_43 == V_45 ) {
F_28 ( V_15 , V_4 -> V_18 . V_16 ,
V_4 -> V_30 . V_32 , * V_16 ) ;
V_4 -> V_30 . V_32 = V_43 ? V_15 : * V_16 ;
} else if ( V_43 == V_46 ) {
V_15 = V_4 -> V_30 . V_32 ;
V_4 -> V_30 . V_32 = * V_16 ;
} else
F_29 () ;
}
if ( F_9 ( V_15 ) )
V_15 = * V_16 ;
if ( V_43 == V_45 )
F_30 ( V_4 -> V_18 . V_16 , V_4 -> V_18 . V_16 , V_15 ) ;
else if ( V_43 == V_44 || V_43 == V_46 )
V_4 -> V_18 . V_16 = V_15 ;
else
F_29 () ;
if ( ! F_31 ( V_47 -> V_48 , V_15 ) ) {
V_47 -> V_48 = F_32 ( V_47 -> V_48 , V_15 ) ;
if ( V_47 -> V_48 >= V_49 )
V_47 -> V_48 = F_2 () ;
}
}
static void F_33 ( struct V_1 * V_4 ,
const T_1 * V_16 ,
enum V_42 V_43 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 ) {
int V_5 = F_11 ( V_4 -> V_30 . V_31 ) ;
if ( F_31 ( V_5 , * V_16 ) ) {
V_4 -> V_18 . V_20 = V_5 ;
V_4 -> V_10 &= ~ V_19 ;
} else
V_4 -> V_10 |= V_19 ;
} else if ( V_4 -> V_10 & V_28 ) {
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
V_4 -> V_18 . V_20 = F_11 ( V_15 ) ;
} else if ( ! ( V_4 -> V_10 & V_19 ) ) {
V_4 -> V_18 . V_20 = F_34 ( V_4 -> V_18 . V_20 ,
V_4 -> V_30 . V_32 ,
* V_16 ) ;
V_4 -> V_30 . V_32 = * V_16 ;
}
}
static void F_35 ( struct V_1 * V_4 , const T_1 * V_50 ,
enum V_42 V_43 )
{
if ( ! V_4 )
return;
if ( ! F_3 ( V_4 ) && V_43 == V_44 &&
F_36 ( V_4 -> V_30 . V_32 , * V_50 ) )
return;
if ( V_43 == V_45 && ( V_4 -> V_10 & V_51 ) )
return;
if ( V_43 == V_46 && ! ( V_4 -> V_10 & V_51 ) )
F_29 () ;
if ( V_43 == V_45 )
V_4 -> V_10 |= V_51 ;
else if ( V_43 == V_46 )
V_4 -> V_10 &= ~ V_51 ;
else if ( V_43 >= V_52 )
F_29 () ;
V_33 [ V_4 -> V_8 ] . F_37 ( V_4 , V_50 , V_43 ) ;
}
void F_38 ( struct V_2 * V_53 , const T_1 * V_54 ,
enum V_42 V_43 )
{
F_35 ( V_53 -> V_1 , V_54 , V_43 ) ;
}
void F_39 ( struct V_55 * V_56 , T_1 * V_54 )
{
struct V_57 * V_58 ;
F_40 ( & V_56 -> V_59 ) ;
for ( V_58 = V_56 -> V_60 ; V_58 ; V_58 = V_58 -> V_61 )
F_35 ( V_58 -> V_62 , V_54 , V_44 ) ;
F_41 ( & V_56 -> V_59 ) ;
}
static int F_42 ( T_2 * V_63 , unsigned long V_64 ,
unsigned long V_65 , struct V_66 * V_67 )
{
struct V_57 * V_58 = V_67 -> V_58 ;
struct V_68 * V_68 ;
struct V_69 * V_70 = V_67 -> V_71 ;
unsigned long V_10 = V_70 -> V_10 ;
int V_72 , V_12 ;
T_3 * V_73 ;
T_4 * V_74 ;
if ( F_43 ( * V_63 ) ) {
V_74 = F_44 ( V_67 -> V_56 , V_63 ) ;
if ( F_43 ( * V_63 ) ) {
V_68 = F_45 ( * V_63 ) ;
if ( F_46 ( V_68 ) ) {
F_47 ( V_74 ) ;
F_48 ( V_58 , V_63 , V_64 ) ;
} else {
F_49 ( V_68 ) ;
F_47 ( V_74 ) ;
F_50 ( V_68 ) ;
V_12 = F_51 ( V_68 ) ;
F_52 ( V_68 ) ;
F_53 ( V_68 ) ;
if ( V_12 )
return 0 ;
}
} else {
F_47 ( V_74 ) ;
}
}
if ( F_54 ( V_63 ) )
return 0 ;
V_75:
V_73 = F_55 ( V_67 -> V_56 , V_63 , V_64 , & V_74 ) ;
for (; V_64 != V_65 ; V_73 ++ , V_64 += V_76 ) {
if ( ! F_56 ( * V_73 ) )
continue;
V_68 = F_57 ( V_58 , V_64 , * V_73 ) ;
if ( ! V_68 )
continue;
if ( F_58 ( V_68 ) )
continue;
V_72 = F_59 ( V_68 ) ;
if ( F_31 ( V_72 , * V_70 -> V_77 ) == ! ! ( V_10 & V_78 ) )
continue;
if ( F_60 ( V_68 ) ) {
F_49 ( V_68 ) ;
F_61 ( V_73 , V_74 ) ;
F_50 ( V_68 ) ;
V_12 = F_51 ( V_68 ) ;
F_52 ( V_68 ) ;
F_53 ( V_68 ) ;
if ( V_12 ) {
V_73 = F_55 ( V_67 -> V_56 , V_63 ,
V_64 , & V_74 ) ;
continue;
}
goto V_75;
}
F_62 ( V_68 , V_70 -> V_79 , V_10 ) ;
}
F_61 ( V_73 - 1 , V_74 ) ;
F_63 () ;
return 0 ;
}
static int F_64 ( T_3 * V_73 , unsigned long V_80 ,
unsigned long V_64 , unsigned long V_65 ,
struct V_66 * V_67 )
{
#ifdef F_65
struct V_69 * V_70 = V_67 -> V_71 ;
unsigned long V_10 = V_70 -> V_10 ;
int V_72 ;
struct V_68 * V_68 ;
T_4 * V_74 ;
T_3 V_81 ;
V_74 = F_66 ( F_67 ( V_67 -> V_58 ) , V_67 -> V_56 , V_73 ) ;
V_81 = F_68 ( V_73 ) ;
if ( ! F_56 ( V_81 ) )
goto V_82;
V_68 = F_69 ( V_81 ) ;
V_72 = F_59 ( V_68 ) ;
if ( F_31 ( V_72 , * V_70 -> V_77 ) == ! ! ( V_10 & V_78 ) )
goto V_82;
if ( V_10 & ( V_83 ) ||
( V_10 & V_84 && F_70 ( V_68 ) == 1 ) )
F_71 ( V_68 , V_70 -> V_79 ) ;
V_82:
F_47 ( V_74 ) ;
#else
F_29 () ;
#endif
return 0 ;
}
unsigned long F_72 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_85 ;
V_85 = F_73 ( V_58 , V_64 , V_65 , V_86 , 0 , 1 ) ;
if ( V_85 )
F_74 ( V_87 , V_85 ) ;
return V_85 ;
}
static unsigned long F_72 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static int F_75 ( unsigned long V_88 , unsigned long V_65 ,
struct V_66 * V_67 )
{
struct V_57 * V_58 = V_67 -> V_58 ;
struct V_69 * V_70 = V_67 -> V_71 ;
unsigned long V_89 = V_58 -> V_90 ;
unsigned long V_10 = V_70 -> V_10 ;
if ( ! F_76 ( V_58 ) )
return 1 ;
if ( V_89 > V_65 )
V_89 = V_65 ;
if ( V_58 -> V_91 > V_88 )
V_88 = V_58 -> V_91 ;
if ( ! ( V_10 & V_92 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_90 < V_65 )
return - V_93 ;
if ( V_70 -> V_94 && V_70 -> V_94 -> V_90 < V_58 -> V_91 )
return - V_93 ;
}
V_70 -> V_94 = V_58 ;
if ( V_10 & V_95 ) {
if ( ! F_77 ( V_58 ) &&
( V_58 -> V_96 & ( V_97 | V_98 | V_99 ) ) &&
! ( V_58 -> V_96 & V_100 ) )
F_72 ( V_58 , V_88 , V_89 ) ;
return 1 ;
}
if ( V_10 & ( V_84 | V_83 ) )
return 0 ;
return 1 ;
}
static int
F_78 ( struct V_55 * V_56 , unsigned long V_88 , unsigned long V_65 ,
T_1 * V_16 , unsigned long V_10 ,
struct V_101 * V_79 )
{
struct V_69 V_70 = {
. V_79 = V_79 ,
. V_10 = V_10 ,
. V_77 = V_16 ,
. V_94 = NULL ,
} ;
struct V_66 V_102 = {
. V_103 = F_64 ,
. V_104 = F_42 ,
. V_105 = F_75 ,
. V_56 = V_56 ,
. V_71 = & V_70 ,
} ;
return F_79 ( V_88 , V_65 , & V_102 ) ;
}
static int F_80 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_106 ;
struct V_1 * V_107 ;
struct V_1 * V_54 ;
F_18 ( L_2 ,
V_58 -> V_91 , V_58 -> V_90 , V_58 -> V_108 ,
V_58 -> V_109 , V_58 -> V_110 ,
V_58 -> V_109 ? V_58 -> V_109 -> V_111 : NULL ) ;
V_54 = F_81 ( V_4 ) ;
if ( F_82 ( V_54 ) )
return F_83 ( V_54 ) ;
if ( V_58 -> V_109 && V_58 -> V_109 -> V_111 ) {
V_106 = V_58 -> V_109 -> V_111 ( V_58 , V_54 ) ;
if ( V_106 )
goto V_112;
}
V_107 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_84 ( V_107 ) ;
return 0 ;
V_112:
F_84 ( V_54 ) ;
return V_106 ;
}
static int F_85 ( struct V_55 * V_56 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_113 )
{
struct V_57 * V_114 ;
struct V_57 * V_94 ;
struct V_57 * V_58 ;
int V_106 = 0 ;
T_5 V_115 ;
unsigned long V_116 ;
unsigned long V_117 ;
V_58 = F_86 ( V_56 , V_88 ) ;
if ( ! V_58 || V_58 -> V_91 > V_88 )
return - V_93 ;
V_94 = V_58 -> V_118 ;
if ( V_88 > V_58 -> V_91 )
V_94 = V_58 ;
for (; V_58 && V_58 -> V_91 < V_65 ; V_94 = V_58 , V_58 = V_114 ) {
V_114 = V_58 -> V_61 ;
V_116 = F_87 ( V_88 , V_58 -> V_91 ) ;
V_117 = F_88 ( V_65 , V_58 -> V_90 ) ;
if ( F_89 ( F_90 ( V_58 ) , V_113 ) )
continue;
V_115 = V_58 -> V_108 +
( ( V_116 - V_58 -> V_91 ) >> V_119 ) ;
V_94 = F_91 ( V_56 , V_94 , V_116 , V_117 , V_58 -> V_96 ,
V_58 -> V_120 , V_58 -> V_110 , V_115 ,
V_113 , V_58 -> V_121 ) ;
if ( V_94 ) {
V_58 = V_94 ;
V_114 = V_58 -> V_61 ;
if ( F_89 ( F_90 ( V_58 ) , V_113 ) )
continue;
goto V_122;
}
if ( V_58 -> V_91 != V_116 ) {
V_106 = F_92 ( V_58 -> V_123 , V_58 , V_116 , 1 ) ;
if ( V_106 )
goto V_124;
}
if ( V_58 -> V_90 != V_117 ) {
V_106 = F_92 ( V_58 -> V_123 , V_58 , V_117 , 0 ) ;
if ( V_106 )
goto V_124;
}
V_122:
V_106 = F_80 ( V_58 , V_113 ) ;
if ( V_106 )
goto V_124;
}
V_124:
return V_106 ;
}
static long F_93 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_54 , * V_107 ;
F_94 ( V_125 ) ;
int V_12 ;
if ( ! V_125 )
return - V_40 ;
V_54 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_82 ( V_54 ) ) {
V_12 = F_83 ( V_54 ) ;
goto V_124;
}
F_95 ( V_47 ) ;
V_12 = F_13 ( V_54 , V_16 , V_125 ) ;
if ( V_12 ) {
F_96 ( V_47 ) ;
F_84 ( V_54 ) ;
goto V_124;
}
V_107 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_126 &&
F_6 ( V_54 -> V_18 . V_16 ) )
V_47 -> V_48 = F_11 ( V_54 -> V_18 . V_16 ) ;
F_96 ( V_47 ) ;
F_84 ( V_107 ) ;
V_12 = 0 ;
V_124:
F_97 ( V_125 ) ;
return V_12 ;
}
static void F_98 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_99 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_127 :
case V_126 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_100 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_29 () ;
}
}
static int F_101 ( unsigned long V_64 )
{
struct V_68 * V_3 ;
int V_106 ;
V_106 = F_102 ( V_64 & V_128 , 1 , 0 , & V_3 , NULL ) ;
if ( V_106 >= 0 ) {
V_106 = F_59 ( V_3 ) ;
F_53 ( V_3 ) ;
}
return V_106 ;
}
static long F_103 ( int * V_34 , T_1 * V_77 ,
unsigned long V_64 , unsigned long V_10 )
{
int V_106 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_10 &
~ ( unsigned long ) ( V_129 | V_130 | V_131 ) )
return - V_17 ;
if ( V_10 & V_131 ) {
if ( V_10 & ( V_129 | V_130 ) )
return - V_17 ;
* V_34 = 0 ;
F_95 ( V_47 ) ;
* V_77 = V_24 ;
F_96 ( V_47 ) ;
return 0 ;
}
if ( V_10 & V_130 ) {
F_104 ( & V_56 -> V_59 ) ;
V_58 = F_105 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_106 ( & V_56 -> V_59 ) ;
return - V_93 ;
}
if ( V_58 -> V_109 && V_58 -> V_109 -> V_132 )
V_4 = V_58 -> V_109 -> V_132 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_129 ) {
if ( V_10 & V_130 ) {
V_106 = F_101 ( V_64 ) ;
if ( V_106 < 0 )
goto V_124;
* V_34 = V_106 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_126 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_106 = - V_17 ;
goto V_124;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
if ( V_58 ) {
F_106 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_106 = 0 ;
if ( V_77 ) {
if ( F_3 ( V_4 ) ) {
* V_77 = V_4 -> V_30 . V_31 ;
} else {
F_95 ( V_47 ) ;
F_98 ( V_4 , V_77 ) ;
F_96 ( V_47 ) ;
}
}
V_124:
F_107 ( V_4 ) ;
if ( V_58 )
F_106 ( & V_47 -> V_56 -> V_59 ) ;
return V_106 ;
}
static void F_62 ( struct V_68 * V_68 , struct V_101 * V_79 ,
unsigned long V_10 )
{
if ( ( V_10 & V_83 ) || F_70 ( V_68 ) == 1 ) {
if ( ! F_108 ( V_68 ) ) {
F_109 ( & V_68 -> V_133 , V_79 ) ;
F_110 ( V_68 , V_134 +
F_111 ( V_68 ) ) ;
}
}
}
static struct V_68 * F_112 ( struct V_68 * V_68 , unsigned long V_5 , int * * V_135 )
{
if ( F_113 ( V_68 ) )
return F_114 ( F_115 ( F_116 ( V_68 ) ) ,
V_5 ) ;
else
return F_117 ( V_5 , V_136 |
V_137 , 0 ) ;
}
static int F_118 ( struct V_55 * V_56 , int V_138 , int V_139 ,
int V_10 )
{
T_1 V_77 ;
F_119 ( V_79 ) ;
int V_106 = 0 ;
F_99 ( V_77 ) ;
F_100 ( V_138 , V_77 ) ;
F_15 ( ! ( V_10 & ( V_84 | V_83 ) ) ) ;
F_78 ( V_56 , V_56 -> V_60 -> V_91 , V_56 -> V_140 , & V_77 ,
V_10 | V_92 , & V_79 ) ;
if ( ! F_120 ( & V_79 ) ) {
V_106 = F_121 ( & V_79 , F_112 , NULL , V_139 ,
V_141 , V_142 ) ;
if ( V_106 )
F_122 ( & V_79 ) ;
}
return V_106 ;
}
int F_123 ( struct V_55 * V_56 , const T_1 * V_143 ,
const T_1 * V_144 , int V_10 )
{
int V_145 = 0 ;
int V_106 ;
T_1 V_15 ;
V_106 = F_124 () ;
if ( V_106 )
return V_106 ;
F_104 ( & V_56 -> V_59 ) ;
V_15 = * V_143 ;
while ( ! F_9 ( V_15 ) ) {
int V_146 , V_147 ;
int V_138 = V_6 ;
int V_139 = 0 ;
F_125 (s, tmp) {
if ( ( F_6 ( * V_143 ) != F_6 ( * V_144 ) ) &&
( F_31 ( V_146 , * V_144 ) ) )
continue;
V_147 = F_34 ( V_146 , * V_143 , * V_144 ) ;
if ( V_146 == V_147 )
continue;
V_138 = V_146 ;
V_139 = V_147 ;
if ( ! F_31 ( V_139 , V_15 ) )
break;
}
if ( V_138 == V_6 )
break;
F_126 ( V_138 , V_15 ) ;
V_106 = F_118 ( V_56 , V_138 , V_139 , V_10 ) ;
if ( V_106 > 0 )
V_145 += V_106 ;
if ( V_106 < 0 )
break;
}
F_106 ( & V_56 -> V_59 ) ;
if ( V_106 < 0 )
return V_106 ;
return V_145 ;
}
static struct V_68 * F_127 ( struct V_68 * V_68 , unsigned long V_88 , int * * V_135 )
{
struct V_57 * V_58 ;
unsigned long V_148 ( V_149 ) ;
V_58 = F_86 ( V_47 -> V_56 , V_88 ) ;
while ( V_58 ) {
V_149 = F_128 ( V_68 , V_58 ) ;
if ( V_149 != - V_93 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_113 ( V_68 ) ) {
F_129 ( ! V_58 ) ;
return F_130 ( V_58 , V_149 , 1 ) ;
}
return F_131 ( V_136 , V_58 , V_149 ) ;
}
static void F_62 ( struct V_68 * V_68 , struct V_101 * V_79 ,
unsigned long V_10 )
{
}
int F_123 ( struct V_55 * V_56 , const T_1 * V_143 ,
const T_1 * V_144 , int V_10 )
{
return - V_150 ;
}
static struct V_68 * F_127 ( struct V_68 * V_68 , unsigned long V_88 , int * * V_135 )
{
return NULL ;
}
static long F_132 ( unsigned long V_88 , unsigned long V_151 ,
unsigned short V_8 , unsigned short V_152 ,
T_1 * V_77 , unsigned long V_10 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_106 ;
F_119 ( V_79 ) ;
if ( V_10 & ~ ( unsigned long ) V_153 )
return - V_17 ;
if ( ( V_10 & V_83 ) && ! F_133 ( V_154 ) )
return - V_155 ;
if ( V_88 & ~ V_128 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_156 ;
V_151 = ( V_151 + V_76 - 1 ) & V_128 ;
V_65 = V_88 + V_151 ;
if ( V_65 < V_88 )
return - V_17 ;
if ( V_65 == V_88 )
return 0 ;
V_54 = F_17 ( V_8 , V_152 , V_77 ) ;
if ( F_82 ( V_54 ) )
return F_83 ( V_54 ) ;
if ( V_10 & V_95 )
V_54 -> V_10 |= V_157 ;
if ( ! V_54 )
V_10 |= V_92 ;
F_18 ( L_3 ,
V_88 , V_88 + V_151 , V_8 , V_152 ,
V_77 ? F_19 ( * V_77 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_84 | V_83 ) ) {
V_106 = F_124 () ;
if ( V_106 )
goto V_158;
}
{
F_94 ( V_125 ) ;
if ( V_125 ) {
F_40 ( & V_56 -> V_59 ) ;
F_95 ( V_47 ) ;
V_106 = F_13 ( V_54 , V_77 , V_125 ) ;
F_96 ( V_47 ) ;
if ( V_106 )
F_41 ( & V_56 -> V_59 ) ;
} else
V_106 = - V_40 ;
F_97 ( V_125 ) ;
}
if ( V_106 )
goto V_158;
V_106 = F_78 ( V_56 , V_88 , V_65 , V_77 ,
V_10 | V_78 , & V_79 ) ;
if ( ! V_106 )
V_106 = F_85 ( V_56 , V_88 , V_65 , V_54 ) ;
if ( ! V_106 ) {
int V_159 = 0 ;
if ( ! F_120 ( & V_79 ) ) {
F_134 ( V_10 & V_95 ) ;
V_159 = F_121 ( & V_79 , F_127 , NULL ,
V_88 , V_141 , V_160 ) ;
if ( V_159 )
F_122 ( & V_79 ) ;
}
if ( V_159 && ( V_10 & V_156 ) )
V_106 = - V_161 ;
} else
F_122 ( & V_79 ) ;
F_41 ( & V_56 -> V_59 ) ;
V_158:
F_84 ( V_54 ) ;
return V_106 ;
}
static int F_135 ( T_1 * V_16 , const unsigned long T_6 * V_77 ,
unsigned long V_162 )
{
unsigned long V_163 ;
unsigned long V_164 ;
unsigned long V_165 ;
-- V_162 ;
F_99 ( * V_16 ) ;
if ( V_162 == 0 || ! V_77 )
return 0 ;
if ( V_162 > V_76 * V_166 )
return - V_17 ;
V_164 = F_136 ( V_162 ) ;
if ( ( V_162 % V_167 ) == 0 )
V_165 = ~ 0UL ;
else
V_165 = ( 1UL << ( V_162 % V_167 ) ) - 1 ;
if ( V_164 > F_136 ( V_49 ) ) {
if ( V_164 > V_76 / sizeof( long ) )
return - V_17 ;
for ( V_163 = F_136 ( V_49 ) ; V_163 < V_164 ; V_163 ++ ) {
unsigned long V_168 ;
if ( F_137 ( V_168 , V_77 + V_163 ) )
return - V_93 ;
if ( V_163 == V_164 - 1 ) {
if ( V_168 & V_165 )
return - V_17 ;
} else if ( V_168 )
return - V_17 ;
}
V_164 = F_136 ( V_49 ) ;
V_165 = ~ 0UL ;
}
if ( F_138 ( F_19 ( * V_16 ) , V_77 , V_164 *sizeof( unsigned long ) ) )
return - V_93 ;
F_19 ( * V_16 ) [ V_164 - 1 ] &= V_165 ;
return 0 ;
}
static int F_139 ( unsigned long T_6 * V_169 , unsigned long V_162 ,
T_1 * V_16 )
{
unsigned long V_170 = F_140 ( V_162 - 1 , 64 ) / 8 ;
const int V_171 = F_136 ( V_49 ) * sizeof( long ) ;
if ( V_170 > V_171 ) {
if ( V_170 > V_76 )
return - V_17 ;
if ( F_141 ( ( char T_6 * ) V_169 + V_171 , V_170 - V_171 ) )
return - V_93 ;
V_170 = V_171 ;
}
return F_142 ( V_169 , F_19 ( * V_16 ) , V_170 ) ? - V_93 : 0 ;
}
struct V_1 * F_143 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = NULL ;
if ( V_58 ) {
if ( V_58 -> V_109 && V_58 -> V_109 -> V_132 ) {
V_4 = V_58 -> V_109 -> V_132 ( V_58 , V_64 ) ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_144 ( V_4 ) )
F_145 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_146 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = F_143 ( V_58 , V_64 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 ;
}
bool F_147 ( struct V_57 * V_58 )
{
struct V_1 * V_4 ;
if ( V_58 -> V_109 && V_58 -> V_109 -> V_132 ) {
bool V_12 = false ;
V_4 = V_58 -> V_109 -> V_132 ( V_58 , V_58 -> V_91 ) ;
if ( V_4 && ( V_4 -> V_10 & V_157 ) )
V_12 = true ;
F_107 ( V_4 ) ;
return V_12 ;
}
V_4 = V_58 -> V_62 ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 -> V_10 & V_157 ;
}
static int F_148 ( struct V_1 * V_34 , enum V_172 V_173 )
{
enum V_172 V_174 = V_175 ;
F_129 ( V_174 == V_176 ) ;
if ( ! F_149 ( V_34 -> V_18 . V_16 , V_25 [ V_177 ] ) )
V_174 = V_176 ;
return V_173 >= V_174 ;
}
static T_1 * F_150 ( T_7 V_178 , struct V_1 * V_34 )
{
if ( F_151 ( V_34 -> V_8 == V_127 ) &&
F_148 ( V_34 , F_152 ( V_178 ) ) &&
F_153 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static struct V_179 * F_154 ( T_7 V_178 , struct V_1 * V_34 ,
int V_180 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_10 & V_19 ) )
V_180 = V_34 -> V_18 . V_20 ;
break;
case V_127 :
if ( F_151 ( V_178 & V_137 ) &&
F_151 ( ! F_31 ( V_180 , V_34 -> V_18 . V_16 ) ) )
V_180 = F_11 ( V_34 -> V_18 . V_16 ) ;
break;
default:
F_29 () ;
}
return F_155 ( V_180 , V_178 ) ;
}
static unsigned F_156 ( struct V_1 * V_34 )
{
unsigned V_72 , V_114 ;
struct V_2 * V_181 = V_47 ;
V_72 = V_181 -> V_48 ;
V_114 = F_32 ( V_72 , V_34 -> V_18 . V_16 ) ;
if ( V_114 < V_49 )
V_181 -> V_48 = V_114 ;
return V_72 ;
}
unsigned int F_157 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_158 () ;
if ( F_159 () )
return V_5 ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_126 :
return F_156 ( V_34 ) ;
case V_127 : {
struct V_182 * V_183 ;
struct V_179 * V_179 ;
enum V_172 V_184 = F_152 ( V_39 ) ;
V_179 = & F_160 ( V_5 ) -> V_185 [ V_186 ] ;
V_183 = F_161 ( V_179 , V_184 ,
& V_34 -> V_18 . V_16 ) ;
return V_183 -> V_173 ? V_183 -> V_173 -> V_5 : V_5 ;
}
default:
F_29 () ;
}
}
static unsigned F_162 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_187 )
{
unsigned V_188 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_189 ;
int V_190 ;
int V_72 ;
if ( ! V_188 )
return F_2 () ;
V_189 = ( unsigned int ) V_187 % V_188 ;
V_72 = F_11 ( V_4 -> V_18 . V_16 ) ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ )
V_72 = F_163 ( V_72 , V_4 -> V_18 . V_16 ) ;
return V_72 ;
}
static inline unsigned F_164 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_191 )
{
if ( V_58 ) {
unsigned long V_192 ;
F_129 ( V_191 < V_119 ) ;
V_192 = V_58 -> V_108 >> ( V_191 - V_119 ) ;
V_192 += ( V_64 - V_58 -> V_91 ) >> V_191 ;
return F_162 ( V_4 , V_58 , V_192 ) ;
} else
return F_156 ( V_4 ) ;
}
struct V_179 * F_165 ( struct V_57 * V_58 , unsigned long V_64 ,
T_7 V_193 , struct V_1 * * V_194 ,
T_1 * * V_195 )
{
struct V_179 * V_196 ;
* V_194 = F_146 ( V_58 , V_64 ) ;
* V_195 = NULL ;
if ( F_151 ( ( * V_194 ) -> V_8 == V_126 ) ) {
V_196 = F_155 ( F_164 ( * V_194 , V_58 , V_64 ,
F_166 ( F_67 ( V_58 ) ) ) , V_193 ) ;
} else {
V_196 = F_154 ( V_193 , * V_194 , F_2 () ) ;
if ( ( * V_194 ) -> V_8 == V_127 )
* V_195 = & ( * V_194 ) -> V_18 . V_16 ;
}
return V_196 ;
}
bool F_167 ( T_1 * V_169 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_169 && V_47 -> V_1 ) )
return false ;
F_95 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_18 . V_20 ;
F_168 ( V_169 , V_72 ) ;
break;
case V_127 :
case V_126 :
* V_169 = V_1 -> V_18 . V_16 ;
break;
default:
F_29 () ;
}
F_96 ( V_47 ) ;
return true ;
}
bool F_169 ( struct V_2 * V_53 ,
const T_1 * V_169 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_169 )
return V_12 ;
F_95 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_124;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_127 :
case V_126 :
V_12 = F_149 ( V_1 -> V_18 . V_16 , * V_169 ) ;
break;
default:
F_29 () ;
}
V_124:
F_96 ( V_53 ) ;
return V_12 ;
}
static struct V_68 * F_170 ( T_7 V_178 , unsigned V_197 ,
unsigned V_72 )
{
struct V_179 * V_196 ;
struct V_68 * V_68 ;
V_196 = F_155 ( V_72 , V_178 ) ;
V_68 = F_171 ( V_178 , V_197 , V_196 ) ;
if ( V_68 && F_172 ( V_68 ) == F_173 ( & V_196 -> V_198 [ 0 ] ) )
F_174 ( V_68 , V_199 ) ;
return V_68 ;
}
struct V_68 *
F_175 ( T_7 V_178 , int V_197 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 , bool V_200 )
{
struct V_1 * V_4 ;
struct V_68 * V_68 ;
unsigned int V_201 ;
struct V_179 * V_196 ;
T_1 * V_77 ;
V_202:
V_4 = F_146 ( V_58 , V_64 ) ;
V_201 = F_176 () ;
if ( V_4 -> V_8 == V_126 ) {
unsigned V_72 ;
V_72 = F_164 ( V_4 , V_58 , V_64 , V_119 + V_197 ) ;
F_107 ( V_4 ) ;
V_68 = F_170 ( V_178 , V_197 , V_72 ) ;
goto V_124;
}
if ( F_151 ( F_177 ( V_203 ) && V_200 ) ) {
int V_204 = V_5 ;
if ( V_4 -> V_8 == V_27 &&
! ( V_4 -> V_10 & V_19 ) )
V_204 = V_4 -> V_18 . V_20 ;
V_77 = F_150 ( V_178 , V_4 ) ;
if ( ! V_77 || F_31 ( V_204 , * V_77 ) ) {
F_107 ( V_4 ) ;
V_68 = F_117 ( V_204 ,
V_178 | V_137 , V_197 ) ;
goto V_124;
}
}
V_77 = F_150 ( V_178 , V_4 ) ;
V_196 = F_154 ( V_178 , V_4 , V_5 ) ;
F_107 ( V_4 ) ;
V_68 = F_178 ( V_178 , V_197 , V_196 , V_77 ) ;
V_124:
if ( F_151 ( ! V_68 && F_179 ( V_201 ) ) )
goto V_202;
return V_68 ;
}
struct V_68 * F_180 ( T_7 V_178 , unsigned V_197 )
{
struct V_1 * V_4 = & V_9 ;
struct V_68 * V_68 ;
unsigned int V_201 ;
if ( ! F_159 () && ! ( V_178 & V_137 ) )
V_4 = F_1 ( V_47 ) ;
V_202:
V_201 = F_176 () ;
if ( V_4 -> V_8 == V_126 )
V_68 = F_170 ( V_178 , V_197 , F_156 ( V_4 ) ) ;
else
V_68 = F_178 ( V_178 , V_197 ,
F_154 ( V_178 , V_4 , F_2 () ) ,
F_150 ( V_178 , V_4 ) ) ;
if ( F_151 ( ! V_68 && F_179 ( V_201 ) ) )
goto V_202;
return V_68 ;
}
int F_181 ( struct V_57 * V_205 , struct V_57 * V_206 )
{
struct V_1 * V_4 = F_81 ( F_90 ( V_205 ) ) ;
if ( F_82 ( V_4 ) )
return F_83 ( V_4 ) ;
V_206 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_182 ( struct V_1 * V_107 )
{
struct V_1 * V_54 = F_21 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_20 ( - V_40 ) ;
if ( V_107 == V_47 -> V_1 ) {
F_95 ( V_47 ) ;
* V_54 = * V_107 ;
F_96 ( V_47 ) ;
} else
* V_54 = * V_107 ;
if ( F_183 () ) {
T_1 V_207 = V_32 ( V_47 ) ;
if ( V_54 -> V_10 & V_51 )
F_35 ( V_54 , & V_207 , V_46 ) ;
else
F_35 ( V_54 , & V_207 , V_44 ) ;
}
F_22 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_184 ( struct V_1 * V_208 , struct V_1 * V_209 )
{
if ( ! V_208 || ! V_209 )
return false ;
if ( V_208 -> V_8 != V_209 -> V_8 )
return false ;
if ( V_208 -> V_10 != V_209 -> V_10 )
return false ;
if ( F_3 ( V_208 ) )
if ( ! F_36 ( V_208 -> V_30 . V_31 , V_209 -> V_30 . V_31 ) )
return false ;
switch ( V_208 -> V_8 ) {
case V_127 :
case V_126 :
return ! ! F_36 ( V_208 -> V_18 . V_16 , V_209 -> V_18 . V_16 ) ;
case V_27 :
return V_208 -> V_18 . V_20 == V_209 -> V_18 . V_20 ;
default:
F_29 () ;
return false ;
}
}
static struct V_210 *
F_185 ( struct V_211 * V_212 , unsigned long V_88 , unsigned long V_65 )
{
struct V_213 * V_187 = V_212 -> V_214 . V_213 ;
while ( V_187 ) {
struct V_210 * V_3 = F_186 ( V_187 , struct V_210 , V_180 ) ;
if ( V_88 >= V_3 -> V_65 )
V_187 = V_187 -> V_215 ;
else if ( V_65 <= V_3 -> V_88 )
V_187 = V_187 -> V_216 ;
else
break;
}
if ( ! V_187 )
return NULL ;
for (; ; ) {
struct V_210 * V_30 = NULL ;
struct V_213 * V_94 = F_187 ( V_187 ) ;
if ( ! V_94 )
break;
V_30 = F_186 ( V_94 , struct V_210 , V_180 ) ;
if ( V_30 -> V_65 <= V_88 )
break;
V_187 = V_94 ;
}
return F_186 ( V_187 , struct V_210 , V_180 ) ;
}
static void F_188 ( struct V_211 * V_212 , struct V_210 * V_54 )
{
struct V_213 * * V_3 = & V_212 -> V_214 . V_213 ;
struct V_213 * V_217 = NULL ;
struct V_210 * V_180 ;
while ( * V_3 ) {
V_217 = * V_3 ;
V_180 = F_186 ( V_217 , struct V_210 , V_180 ) ;
if ( V_54 -> V_88 < V_180 -> V_88 )
V_3 = & ( * V_3 ) -> V_216 ;
else if ( V_54 -> V_65 > V_180 -> V_65 )
V_3 = & ( * V_3 ) -> V_215 ;
else
F_29 () ;
}
F_189 ( & V_54 -> V_180 , V_217 , V_3 ) ;
F_190 ( & V_54 -> V_180 , & V_212 -> V_214 ) ;
F_18 ( L_4 , V_54 -> V_88 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_191 ( struct V_211 * V_212 , unsigned long V_218 )
{
struct V_1 * V_4 = NULL ;
struct V_210 * V_219 ;
if ( ! V_212 -> V_214 . V_213 )
return NULL ;
F_192 ( & V_212 -> V_220 ) ;
V_219 = F_185 ( V_212 , V_218 , V_218 + 1 ) ;
if ( V_219 ) {
F_145 ( V_219 -> V_34 ) ;
V_4 = V_219 -> V_34 ;
}
F_193 ( & V_212 -> V_220 ) ;
return V_4 ;
}
static void F_194 ( struct V_210 * V_187 )
{
F_84 ( V_187 -> V_34 ) ;
F_25 ( V_221 , V_187 ) ;
}
int F_195 ( struct V_68 * V_68 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_182 * V_183 ;
int V_222 = F_59 ( V_68 ) ;
unsigned long V_115 ;
int V_223 = F_196 () ;
int V_224 = F_197 ( V_223 ) ;
int V_225 = - 1 ;
int V_12 = - 1 ;
F_129 ( ! V_58 ) ;
V_4 = F_146 ( V_58 , V_64 ) ;
if ( ! ( V_4 -> V_10 & V_157 ) )
goto V_124;
switch ( V_4 -> V_8 ) {
case V_126 :
F_129 ( V_64 >= V_58 -> V_90 ) ;
F_129 ( V_64 < V_58 -> V_91 ) ;
V_115 = V_58 -> V_108 ;
V_115 += ( V_64 - V_58 -> V_91 ) >> V_119 ;
V_225 = F_162 ( V_4 , V_58 , V_115 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_225 = F_2 () ;
else
V_225 = V_4 -> V_18 . V_20 ;
break;
case V_127 :
if ( F_31 ( V_222 , V_4 -> V_18 . V_16 ) )
goto V_124;
V_183 = F_161 (
F_155 ( F_2 () , V_226 ) ,
F_152 ( V_226 ) ,
& V_4 -> V_18 . V_16 ) ;
V_225 = V_183 -> V_173 -> V_5 ;
break;
default:
F_29 () ;
}
if ( V_4 -> V_10 & V_227 ) {
V_225 = V_224 ;
if ( ! F_198 ( V_47 , V_68 , V_222 , V_223 ) )
goto V_124;
}
if ( V_222 != V_225 )
V_12 = V_225 ;
V_124:
F_107 ( V_4 ) ;
return V_12 ;
}
void F_199 ( struct V_2 * V_228 )
{
struct V_1 * V_4 ;
F_95 ( V_228 ) ;
V_4 = V_228 -> V_1 ;
V_228 -> V_1 = NULL ;
F_96 ( V_228 ) ;
F_84 ( V_4 ) ;
}
static void F_200 ( struct V_211 * V_212 , struct V_210 * V_187 )
{
F_18 ( L_5 , V_187 -> V_88 , V_187 -> V_65 ) ;
F_201 ( & V_187 -> V_180 , & V_212 -> V_214 ) ;
F_194 ( V_187 ) ;
}
static void F_202 ( struct V_210 * V_5 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_88 = V_88 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_210 * F_203 ( unsigned long V_88 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_210 * V_187 ;
struct V_1 * V_229 ;
V_187 = F_21 ( V_221 , V_39 ) ;
if ( ! V_187 )
return NULL ;
V_229 = F_81 ( V_4 ) ;
if ( F_82 ( V_229 ) ) {
F_25 ( V_221 , V_187 ) ;
return NULL ;
}
V_229 -> V_10 |= V_230 ;
F_202 ( V_187 , V_88 , V_65 , V_229 ) ;
return V_187 ;
}
static int F_204 ( struct V_211 * V_212 , unsigned long V_88 ,
unsigned long V_65 , struct V_210 * V_54 )
{
struct V_210 * V_187 ;
struct V_210 * V_231 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_232:
F_205 ( & V_212 -> V_220 ) ;
V_187 = F_185 ( V_212 , V_88 , V_65 ) ;
while ( V_187 && V_187 -> V_88 < V_65 ) {
struct V_213 * V_114 = F_206 ( & V_187 -> V_180 ) ;
if ( V_187 -> V_88 >= V_88 ) {
if ( V_187 -> V_65 <= V_65 )
F_200 ( V_212 , V_187 ) ;
else
V_187 -> V_88 = V_65 ;
} else {
if ( V_187 -> V_65 > V_65 ) {
if ( ! V_231 )
goto V_233;
* F_17 = * V_187 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_202 ( V_231 , V_65 , V_187 -> V_65 , F_17 ) ;
V_187 -> V_65 = V_88 ;
F_188 ( V_212 , V_231 ) ;
V_231 = NULL ;
F_17 = NULL ;
break;
} else
V_187 -> V_65 = V_88 ;
}
if ( ! V_114 )
break;
V_187 = F_186 ( V_114 , struct V_210 , V_180 ) ;
}
if ( V_54 )
F_188 ( V_212 , V_54 ) ;
F_207 ( & V_212 -> V_220 ) ;
V_12 = 0 ;
V_112:
if ( F_17 )
F_84 ( F_17 ) ;
if ( V_231 )
F_25 ( V_221 , V_231 ) ;
return V_12 ;
V_233:
F_207 ( & V_212 -> V_220 ) ;
V_12 = - V_40 ;
V_231 = F_21 ( V_221 , V_39 ) ;
if ( ! V_231 )
goto V_112;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_112;
goto V_232;
}
void F_208 ( struct V_211 * V_212 , struct V_1 * V_194 )
{
int V_12 ;
V_212 -> V_214 = V_234 ;
F_209 ( & V_212 -> V_220 ) ;
if ( V_194 ) {
struct V_57 V_235 ;
struct V_1 * V_54 ;
F_94 ( V_125 ) ;
if ( ! V_125 )
goto V_236;
V_54 = F_17 ( V_194 -> V_8 , V_194 -> V_10 , & V_194 -> V_30 . V_31 ) ;
if ( F_82 ( V_54 ) )
goto V_237;
F_95 ( V_47 ) ;
V_12 = F_13 ( V_54 , & V_194 -> V_30 . V_31 , V_125 ) ;
F_96 ( V_47 ) ;
if ( V_12 )
goto V_238;
memset ( & V_235 , 0 , sizeof( struct V_57 ) ) ;
V_235 . V_90 = V_239 ;
F_210 ( V_212 , & V_235 , V_54 ) ;
V_238:
F_84 ( V_54 ) ;
V_237:
F_97 ( V_125 ) ;
V_236:
F_84 ( V_194 ) ;
}
}
int F_210 ( struct V_211 * V_240 ,
struct V_57 * V_58 , struct V_1 * V_241 )
{
int V_106 ;
struct V_210 * V_54 = NULL ;
unsigned long V_242 = F_211 ( V_58 ) ;
F_18 ( L_6 ,
V_58 -> V_108 ,
V_242 , V_241 ? V_241 -> V_8 : - 1 ,
V_241 ? V_241 -> V_10 : - 1 ,
V_241 ? F_19 ( V_241 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_241 ) {
V_54 = F_203 ( V_58 -> V_108 , V_58 -> V_108 + V_242 , V_241 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_106 = F_204 ( V_240 , V_58 -> V_108 , V_58 -> V_108 + V_242 , V_54 ) ;
if ( V_106 && V_54 )
F_194 ( V_54 ) ;
return V_106 ;
}
void F_212 ( struct V_211 * V_3 )
{
struct V_210 * V_187 ;
struct V_213 * V_114 ;
if ( ! V_3 -> V_214 . V_213 )
return;
F_205 ( & V_3 -> V_220 ) ;
V_114 = F_213 ( & V_3 -> V_214 ) ;
while ( V_114 ) {
V_187 = F_186 ( V_114 , struct V_210 , V_180 ) ;
V_114 = F_206 ( & V_187 -> V_180 ) ;
F_200 ( V_3 , V_187 ) ;
}
F_207 ( & V_3 -> V_220 ) ;
}
static void T_8 F_214 ( void )
{
bool V_243 = false ;
if ( F_177 ( V_244 ) )
V_243 = true ;
if ( V_245 )
F_215 ( V_245 == 1 ) ;
if ( F_216 () > 1 && ! V_245 ) {
F_217 ( L_7 ,
V_243 ? L_8 : L_9 ) ;
F_215 ( V_243 ) ;
}
}
static int T_8 F_218 ( char * V_246 )
{
int V_12 = 0 ;
if ( ! V_246 )
goto V_124;
if ( ! strcmp ( V_246 , L_10 ) ) {
V_245 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_246 , L_11 ) ) {
V_245 = - 1 ;
V_12 = 1 ;
}
V_124:
if ( ! V_12 )
F_219 ( L_12 ) ;
return V_12 ;
}
static inline void T_8 F_214 ( void )
{
}
void T_8 F_220 ( void )
{
T_1 F_156 ;
unsigned long V_247 = 0 ;
int V_72 , V_248 = 0 ;
V_38 = F_221 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_249 , NULL ) ;
V_221 = F_221 ( L_14 ,
sizeof( struct V_210 ) ,
0 , V_249 , NULL ) ;
F_222 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_223 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_157 | V_227 ,
. V_18 = { . V_20 = V_72 , } ,
} ;
}
F_99 ( F_156 ) ;
F_224 (nid, N_MEMORY) {
unsigned long V_250 = F_225 ( V_72 ) ;
if ( V_247 < V_250 ) {
V_247 = V_250 ;
V_248 = V_72 ;
}
if ( ( V_250 << V_119 ) >= ( 16 << 20 ) )
F_100 ( V_72 , F_156 ) ;
}
if ( F_151 ( F_9 ( F_156 ) ) )
F_100 ( V_248 , F_156 ) ;
if ( F_93 ( V_126 , 0 , & F_156 ) )
F_226 ( L_15 , V_251 ) ;
F_214 () ;
}
void F_227 ( void )
{
F_93 ( V_35 , 0 , NULL ) ;
}
int F_228 ( char * V_246 , struct V_1 * * V_194 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_152 ;
T_1 V_16 ;
char * V_252 = strchr ( V_246 , ':' ) ;
char * V_10 = strchr ( V_246 , '=' ) ;
int V_106 = 1 ;
if ( V_252 ) {
* V_252 ++ = '\0' ;
if ( F_229 ( V_252 , V_16 ) )
goto V_124;
if ( ! F_230 ( V_16 , V_25 [ V_26 ] ) )
goto V_124;
} else
F_99 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_253 ; V_8 ++ ) {
if ( ! strcmp ( V_246 , V_254 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_253 )
goto V_124;
switch ( V_8 ) {
case V_27 :
if ( V_252 ) {
char * V_255 = V_252 ;
while ( isdigit ( * V_255 ) )
V_255 ++ ;
if ( * V_255 )
goto V_124;
}
break;
case V_126 :
if ( ! V_252 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_252 )
goto V_124;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_252 )
V_106 = 0 ;
goto V_124;
case V_127 :
if ( ! V_252 )
goto V_124;
}
V_152 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_16 ) )
V_152 |= V_36 ;
else if ( ! strcmp ( V_10 , L_17 ) )
V_152 |= V_28 ;
else
goto V_124;
}
V_54 = F_17 ( V_8 , V_152 , & V_16 ) ;
if ( F_82 ( V_54 ) )
goto V_124;
if ( V_8 != V_27 )
V_54 -> V_18 . V_16 = V_16 ;
else if ( V_252 )
V_54 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_54 -> V_10 |= V_19 ;
V_54 -> V_30 . V_31 = V_16 ;
V_106 = 0 ;
V_124:
if ( V_252 )
* -- V_252 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_106 )
* V_194 = V_54 ;
return V_106 ;
}
void F_231 ( char * V_256 , int V_257 , struct V_1 * V_4 )
{
char * V_3 = V_256 ;
T_1 V_16 = V_258 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_227 ) ) {
V_8 = V_4 -> V_8 ;
V_10 = V_4 -> V_10 ;
}
switch ( V_8 ) {
case V_35 :
break;
case V_27 :
if ( V_10 & V_19 )
V_8 = V_37 ;
else
F_100 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_127 :
case V_126 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_134 ( 1 ) ;
snprintf ( V_3 , V_257 , L_18 ) ;
return;
}
V_3 += snprintf ( V_3 , V_257 , L_19 , V_254 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_20 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_16 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_17 ) ;
}
if ( ! F_9 ( V_16 ) )
V_3 += F_232 ( V_3 , V_256 + V_257 - V_3 , L_21 ,
F_233 ( & V_16 ) ) ;
}
