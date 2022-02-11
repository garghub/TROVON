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
V_47 -> V_48 = F_11 ( V_15 ) ;
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
V_75:
V_73 = F_54 ( V_67 -> V_56 , V_63 , V_64 , & V_74 ) ;
for (; V_64 != V_65 ; V_73 ++ , V_64 += V_76 ) {
if ( ! F_55 ( * V_73 ) )
continue;
V_68 = F_56 ( V_58 , V_64 , * V_73 ) ;
if ( ! V_68 )
continue;
if ( F_57 ( V_68 ) )
continue;
V_72 = F_58 ( V_68 ) ;
if ( F_31 ( V_72 , * V_70 -> V_77 ) == ! ! ( V_10 & V_78 ) )
continue;
if ( F_59 ( V_68 ) && F_60 ( V_68 ) ) {
F_49 ( V_68 ) ;
F_61 ( V_73 , V_74 ) ;
F_50 ( V_68 ) ;
V_12 = F_51 ( V_68 ) ;
F_52 ( V_68 ) ;
F_53 ( V_68 ) ;
if ( V_12 ) {
V_73 = F_54 ( V_67 -> V_56 , V_63 ,
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
if ( ! F_55 ( V_81 ) )
goto V_82;
V_68 = F_69 ( V_81 ) ;
V_72 = F_58 ( V_68 ) ;
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
if ( V_58 -> V_96 & ( V_97 | V_98 | V_99 ) )
F_72 ( V_58 , V_88 , V_89 ) ;
return 1 ;
}
if ( V_10 & ( V_84 | V_83 ) )
return 0 ;
return 1 ;
}
static int
F_77 ( struct V_55 * V_56 , unsigned long V_88 , unsigned long V_65 ,
T_1 * V_16 , unsigned long V_10 ,
struct V_100 * V_79 )
{
struct V_69 V_70 = {
. V_79 = V_79 ,
. V_10 = V_10 ,
. V_77 = V_16 ,
. V_94 = NULL ,
} ;
struct V_66 V_101 = {
. V_102 = F_64 ,
. V_103 = F_42 ,
. V_104 = F_75 ,
. V_56 = V_56 ,
. V_71 = & V_70 ,
} ;
return F_78 ( V_88 , V_65 , & V_101 ) ;
}
static int F_79 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_105 ;
struct V_1 * V_106 ;
struct V_1 * V_54 ;
F_18 ( L_2 ,
V_58 -> V_91 , V_58 -> V_90 , V_58 -> V_107 ,
V_58 -> V_108 , V_58 -> V_109 ,
V_58 -> V_108 ? V_58 -> V_108 -> V_110 : NULL ) ;
V_54 = F_80 ( V_4 ) ;
if ( F_81 ( V_54 ) )
return F_82 ( V_54 ) ;
if ( V_58 -> V_108 && V_58 -> V_108 -> V_110 ) {
V_105 = V_58 -> V_108 -> V_110 ( V_58 , V_54 ) ;
if ( V_105 )
goto V_111;
}
V_106 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_83 ( V_106 ) ;
return 0 ;
V_111:
F_83 ( V_54 ) ;
return V_105 ;
}
static int F_84 ( struct V_55 * V_56 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_112 )
{
struct V_57 * V_113 ;
struct V_57 * V_94 ;
struct V_57 * V_58 ;
int V_105 = 0 ;
T_5 V_114 ;
unsigned long V_115 ;
unsigned long V_116 ;
V_58 = F_85 ( V_56 , V_88 ) ;
if ( ! V_58 || V_58 -> V_91 > V_88 )
return - V_93 ;
V_94 = V_58 -> V_117 ;
if ( V_88 > V_58 -> V_91 )
V_94 = V_58 ;
for (; V_58 && V_58 -> V_91 < V_65 ; V_94 = V_58 , V_58 = V_113 ) {
V_113 = V_58 -> V_61 ;
V_115 = F_86 ( V_88 , V_58 -> V_91 ) ;
V_116 = F_87 ( V_65 , V_58 -> V_90 ) ;
if ( F_88 ( F_89 ( V_58 ) , V_112 ) )
continue;
V_114 = V_58 -> V_107 +
( ( V_115 - V_58 -> V_91 ) >> V_118 ) ;
V_94 = F_90 ( V_56 , V_94 , V_115 , V_116 , V_58 -> V_96 ,
V_58 -> V_119 , V_58 -> V_109 , V_114 ,
V_112 , V_58 -> V_120 ) ;
if ( V_94 ) {
V_58 = V_94 ;
V_113 = V_58 -> V_61 ;
if ( F_88 ( F_89 ( V_58 ) , V_112 ) )
continue;
goto V_121;
}
if ( V_58 -> V_91 != V_115 ) {
V_105 = F_91 ( V_58 -> V_122 , V_58 , V_115 , 1 ) ;
if ( V_105 )
goto V_123;
}
if ( V_58 -> V_90 != V_116 ) {
V_105 = F_91 ( V_58 -> V_122 , V_58 , V_116 , 0 ) ;
if ( V_105 )
goto V_123;
}
V_121:
V_105 = F_79 ( V_58 , V_112 ) ;
if ( V_105 )
goto V_123;
}
V_123:
return V_105 ;
}
static long F_92 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_54 , * V_106 ;
F_93 ( V_124 ) ;
int V_12 ;
if ( ! V_124 )
return - V_40 ;
V_54 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_81 ( V_54 ) ) {
V_12 = F_82 ( V_54 ) ;
goto V_123;
}
F_94 ( V_47 ) ;
V_12 = F_13 ( V_54 , V_16 , V_124 ) ;
if ( V_12 ) {
F_95 ( V_47 ) ;
F_83 ( V_54 ) ;
goto V_123;
}
V_106 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_125 &&
F_6 ( V_54 -> V_18 . V_16 ) )
V_47 -> V_48 = F_11 ( V_54 -> V_18 . V_16 ) ;
F_95 ( V_47 ) ;
F_83 ( V_106 ) ;
V_12 = 0 ;
V_123:
F_96 ( V_124 ) ;
return V_12 ;
}
static void F_97 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_98 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_126 :
case V_125 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_99 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_29 () ;
}
}
static int F_100 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_68 * V_3 ;
int V_105 ;
V_105 = F_101 ( V_47 , V_56 , V_64 & V_127 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_105 >= 0 ) {
V_105 = F_58 ( V_3 ) ;
F_53 ( V_3 ) ;
}
return V_105 ;
}
static long F_102 ( int * V_34 , T_1 * V_77 ,
unsigned long V_64 , unsigned long V_10 )
{
int V_105 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_10 &
~ ( unsigned long ) ( V_128 | V_129 | V_130 ) )
return - V_17 ;
if ( V_10 & V_130 ) {
if ( V_10 & ( V_128 | V_129 ) )
return - V_17 ;
* V_34 = 0 ;
F_94 ( V_47 ) ;
* V_77 = V_24 ;
F_95 ( V_47 ) ;
return 0 ;
}
if ( V_10 & V_129 ) {
F_103 ( & V_56 -> V_59 ) ;
V_58 = F_104 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_105 ( & V_56 -> V_59 ) ;
return - V_93 ;
}
if ( V_58 -> V_108 && V_58 -> V_108 -> V_131 )
V_4 = V_58 -> V_108 -> V_131 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_128 ) {
if ( V_10 & V_129 ) {
V_105 = F_100 ( V_56 , V_64 ) ;
if ( V_105 < 0 )
goto V_123;
* V_34 = V_105 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_125 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_105 = - V_17 ;
goto V_123;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
if ( V_58 ) {
F_105 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_105 = 0 ;
if ( V_77 ) {
if ( F_3 ( V_4 ) ) {
* V_77 = V_4 -> V_30 . V_31 ;
} else {
F_94 ( V_47 ) ;
F_97 ( V_4 , V_77 ) ;
F_95 ( V_47 ) ;
}
}
V_123:
F_106 ( V_4 ) ;
if ( V_58 )
F_105 ( & V_47 -> V_56 -> V_59 ) ;
return V_105 ;
}
static void F_62 ( struct V_68 * V_68 , struct V_100 * V_79 ,
unsigned long V_10 )
{
if ( ( V_10 & V_83 ) || F_70 ( V_68 ) == 1 ) {
if ( ! F_107 ( V_68 ) ) {
F_108 ( & V_68 -> V_132 , V_79 ) ;
F_109 ( V_68 , V_133 +
F_110 ( V_68 ) ) ;
}
}
}
static struct V_68 * F_111 ( struct V_68 * V_68 , unsigned long V_5 , int * * V_134 )
{
if ( F_112 ( V_68 ) )
return F_113 ( F_114 ( F_115 ( V_68 ) ) ,
V_5 ) ;
else
return F_116 ( V_5 , V_135 |
V_136 , 0 ) ;
}
static int F_117 ( struct V_55 * V_56 , int V_137 , int V_138 ,
int V_10 )
{
T_1 V_77 ;
F_118 ( V_79 ) ;
int V_105 = 0 ;
F_98 ( V_77 ) ;
F_99 ( V_137 , V_77 ) ;
F_15 ( ! ( V_10 & ( V_84 | V_83 ) ) ) ;
F_77 ( V_56 , V_56 -> V_60 -> V_91 , V_56 -> V_139 , & V_77 ,
V_10 | V_92 , & V_79 ) ;
if ( ! F_119 ( & V_79 ) ) {
V_105 = F_120 ( & V_79 , F_111 , NULL , V_138 ,
V_140 , V_141 ) ;
if ( V_105 )
F_121 ( & V_79 ) ;
}
return V_105 ;
}
int F_122 ( struct V_55 * V_56 , const T_1 * V_142 ,
const T_1 * V_143 , int V_10 )
{
int V_144 = 0 ;
int V_105 ;
T_1 V_15 ;
V_105 = F_123 () ;
if ( V_105 )
return V_105 ;
F_103 ( & V_56 -> V_59 ) ;
V_15 = * V_142 ;
while ( ! F_9 ( V_15 ) ) {
int V_145 , V_146 ;
int V_137 = V_6 ;
int V_138 = 0 ;
F_124 (s, tmp) {
if ( ( F_6 ( * V_142 ) != F_6 ( * V_143 ) ) &&
( F_31 ( V_145 , * V_143 ) ) )
continue;
V_146 = F_34 ( V_145 , * V_142 , * V_143 ) ;
if ( V_145 == V_146 )
continue;
V_137 = V_145 ;
V_138 = V_146 ;
if ( ! F_31 ( V_138 , V_15 ) )
break;
}
if ( V_137 == V_6 )
break;
F_125 ( V_137 , V_15 ) ;
V_105 = F_117 ( V_56 , V_137 , V_138 , V_10 ) ;
if ( V_105 > 0 )
V_144 += V_105 ;
if ( V_105 < 0 )
break;
}
F_105 ( & V_56 -> V_59 ) ;
if ( V_105 < 0 )
return V_105 ;
return V_144 ;
}
static struct V_68 * F_126 ( struct V_68 * V_68 , unsigned long V_88 , int * * V_134 )
{
struct V_57 * V_58 ;
unsigned long V_147 ( V_148 ) ;
V_58 = F_85 ( V_47 -> V_56 , V_88 ) ;
while ( V_58 ) {
V_148 = F_127 ( V_68 , V_58 ) ;
if ( V_148 != - V_93 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_112 ( V_68 ) ) {
F_128 ( ! V_58 ) ;
return F_129 ( V_58 , V_148 , 1 ) ;
}
return F_130 ( V_135 , V_58 , V_148 ) ;
}
static void F_62 ( struct V_68 * V_68 , struct V_100 * V_79 ,
unsigned long V_10 )
{
}
int F_122 ( struct V_55 * V_56 , const T_1 * V_142 ,
const T_1 * V_143 , int V_10 )
{
return - V_149 ;
}
static struct V_68 * F_126 ( struct V_68 * V_68 , unsigned long V_88 , int * * V_134 )
{
return NULL ;
}
static long F_131 ( unsigned long V_88 , unsigned long V_150 ,
unsigned short V_8 , unsigned short V_151 ,
T_1 * V_77 , unsigned long V_10 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_105 ;
F_118 ( V_79 ) ;
if ( V_10 & ~ ( unsigned long ) V_152 )
return - V_17 ;
if ( ( V_10 & V_83 ) && ! F_132 ( V_153 ) )
return - V_154 ;
if ( V_88 & ~ V_127 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_155 ;
V_150 = ( V_150 + V_76 - 1 ) & V_127 ;
V_65 = V_88 + V_150 ;
if ( V_65 < V_88 )
return - V_17 ;
if ( V_65 == V_88 )
return 0 ;
V_54 = F_17 ( V_8 , V_151 , V_77 ) ;
if ( F_81 ( V_54 ) )
return F_82 ( V_54 ) ;
if ( V_10 & V_95 )
V_54 -> V_10 |= V_156 ;
if ( ! V_54 )
V_10 |= V_92 ;
F_18 ( L_3 ,
V_88 , V_88 + V_150 , V_8 , V_151 ,
V_77 ? F_19 ( * V_77 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_84 | V_83 ) ) {
V_105 = F_123 () ;
if ( V_105 )
goto V_157;
}
{
F_93 ( V_124 ) ;
if ( V_124 ) {
F_40 ( & V_56 -> V_59 ) ;
F_94 ( V_47 ) ;
V_105 = F_13 ( V_54 , V_77 , V_124 ) ;
F_95 ( V_47 ) ;
if ( V_105 )
F_41 ( & V_56 -> V_59 ) ;
} else
V_105 = - V_40 ;
F_96 ( V_124 ) ;
}
if ( V_105 )
goto V_157;
V_105 = F_77 ( V_56 , V_88 , V_65 , V_77 ,
V_10 | V_78 , & V_79 ) ;
if ( ! V_105 )
V_105 = F_84 ( V_56 , V_88 , V_65 , V_54 ) ;
if ( ! V_105 ) {
int V_158 = 0 ;
if ( ! F_119 ( & V_79 ) ) {
F_133 ( V_10 & V_95 ) ;
V_158 = F_120 ( & V_79 , F_126 , NULL ,
V_88 , V_140 , V_159 ) ;
if ( V_158 )
F_121 ( & V_79 ) ;
}
if ( V_158 && ( V_10 & V_155 ) )
V_105 = - V_160 ;
} else
F_121 ( & V_79 ) ;
F_41 ( & V_56 -> V_59 ) ;
V_157:
F_83 ( V_54 ) ;
return V_105 ;
}
static int F_134 ( T_1 * V_16 , const unsigned long T_6 * V_77 ,
unsigned long V_161 )
{
unsigned long V_162 ;
unsigned long V_163 ;
unsigned long V_164 ;
-- V_161 ;
F_98 ( * V_16 ) ;
if ( V_161 == 0 || ! V_77 )
return 0 ;
if ( V_161 > V_76 * V_165 )
return - V_17 ;
V_163 = F_135 ( V_161 ) ;
if ( ( V_161 % V_166 ) == 0 )
V_164 = ~ 0UL ;
else
V_164 = ( 1UL << ( V_161 % V_166 ) ) - 1 ;
if ( V_163 > F_135 ( V_49 ) ) {
if ( V_163 > V_76 / sizeof( long ) )
return - V_17 ;
for ( V_162 = F_135 ( V_49 ) ; V_162 < V_163 ; V_162 ++ ) {
unsigned long V_167 ;
if ( F_136 ( V_167 , V_77 + V_162 ) )
return - V_93 ;
if ( V_162 == V_163 - 1 ) {
if ( V_167 & V_164 )
return - V_17 ;
} else if ( V_167 )
return - V_17 ;
}
V_163 = F_135 ( V_49 ) ;
V_164 = ~ 0UL ;
}
if ( F_137 ( F_19 ( * V_16 ) , V_77 , V_163 *sizeof( unsigned long ) ) )
return - V_93 ;
F_19 ( * V_16 ) [ V_163 - 1 ] &= V_164 ;
return 0 ;
}
static int F_138 ( unsigned long T_6 * V_168 , unsigned long V_161 ,
T_1 * V_16 )
{
unsigned long V_169 = F_139 ( V_161 - 1 , 64 ) / 8 ;
const int V_170 = F_135 ( V_49 ) * sizeof( long ) ;
if ( V_169 > V_170 ) {
if ( V_169 > V_76 )
return - V_17 ;
if ( F_140 ( ( char T_6 * ) V_168 + V_170 , V_169 - V_170 ) )
return - V_93 ;
V_169 = V_170 ;
}
return F_141 ( V_168 , F_19 ( * V_16 ) , V_169 ) ? - V_93 : 0 ;
}
struct V_1 * F_142 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = NULL ;
if ( V_58 ) {
if ( V_58 -> V_108 && V_58 -> V_108 -> V_131 ) {
V_4 = V_58 -> V_108 -> V_131 ( V_58 , V_64 ) ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_143 ( V_4 ) )
F_144 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_145 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = F_142 ( V_58 , V_64 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 ;
}
bool F_146 ( struct V_57 * V_58 )
{
struct V_1 * V_4 ;
if ( V_58 -> V_108 && V_58 -> V_108 -> V_131 ) {
bool V_12 = false ;
V_4 = V_58 -> V_108 -> V_131 ( V_58 , V_58 -> V_91 ) ;
if ( V_4 && ( V_4 -> V_10 & V_156 ) )
V_12 = true ;
F_106 ( V_4 ) ;
return V_12 ;
}
V_4 = V_58 -> V_62 ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 -> V_10 & V_156 ;
}
static int F_147 ( struct V_1 * V_34 , enum V_171 V_172 )
{
enum V_171 V_173 = V_174 ;
F_128 ( V_173 == V_175 ) ;
if ( ! F_148 ( V_34 -> V_18 . V_16 , V_25 [ V_176 ] ) )
V_173 = V_175 ;
return V_172 >= V_173 ;
}
static T_1 * F_149 ( T_7 V_177 , struct V_1 * V_34 )
{
if ( F_150 ( V_34 -> V_8 == V_126 ) &&
F_147 ( V_34 , F_151 ( V_177 ) ) &&
F_152 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static struct V_178 * F_153 ( T_7 V_177 , struct V_1 * V_34 ,
int V_179 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_10 & V_19 ) )
V_179 = V_34 -> V_18 . V_20 ;
break;
case V_126 :
if ( F_150 ( V_177 & V_136 ) &&
F_150 ( ! F_31 ( V_179 , V_34 -> V_18 . V_16 ) ) )
V_179 = F_11 ( V_34 -> V_18 . V_16 ) ;
break;
default:
F_29 () ;
}
return F_154 ( V_179 , V_177 ) ;
}
static unsigned F_155 ( struct V_1 * V_34 )
{
unsigned V_72 , V_113 ;
struct V_2 * V_180 = V_47 ;
V_72 = V_180 -> V_48 ;
V_113 = F_32 ( V_72 , V_34 -> V_18 . V_16 ) ;
if ( V_113 >= V_49 )
V_113 = F_11 ( V_34 -> V_18 . V_16 ) ;
if ( V_113 < V_49 )
V_180 -> V_48 = V_113 ;
return V_72 ;
}
unsigned int F_156 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_157 () ;
if ( F_158 () )
return V_5 ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_125 :
return F_155 ( V_34 ) ;
case V_126 : {
struct V_178 * V_178 ;
struct V_172 * V_172 ;
enum V_171 V_181 = F_151 ( V_39 ) ;
V_178 = & F_159 ( V_5 ) -> V_182 [ 0 ] ;
( void ) F_160 ( V_178 , V_181 ,
& V_34 -> V_18 . V_16 ,
& V_172 ) ;
return V_172 ? V_172 -> V_5 : V_5 ;
}
default:
F_29 () ;
}
}
static unsigned F_161 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_183 )
{
unsigned V_184 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_185 ;
int V_186 ;
int V_72 = V_6 ;
if ( ! V_184 )
return F_2 () ;
V_185 = ( unsigned int ) V_183 % V_184 ;
V_186 = 0 ;
do {
V_72 = F_32 ( V_72 , V_4 -> V_18 . V_16 ) ;
V_186 ++ ;
} while ( V_186 <= V_185 );
return V_72 ;
}
static inline unsigned F_162 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_187 )
{
if ( V_58 ) {
unsigned long V_183 ;
F_128 ( V_187 < V_118 ) ;
V_183 = V_58 -> V_107 >> ( V_187 - V_118 ) ;
V_183 += ( V_64 - V_58 -> V_91 ) >> V_187 ;
return F_161 ( V_4 , V_58 , V_183 ) ;
} else
return F_155 ( V_4 ) ;
}
int F_163 ( const T_1 * V_188 )
{
int V_30 , V_189 = V_6 ;
V_30 = F_6 ( * V_188 ) ;
if ( V_30 )
V_189 = F_164 ( V_188 -> V_190 ,
F_165 () % V_30 , V_49 ) ;
return V_189 ;
}
struct V_178 * F_166 ( struct V_57 * V_58 , unsigned long V_64 ,
T_7 V_191 , struct V_1 * * V_192 ,
T_1 * * V_193 )
{
struct V_178 * V_194 ;
* V_192 = F_145 ( V_58 , V_64 ) ;
* V_193 = NULL ;
if ( F_150 ( ( * V_192 ) -> V_8 == V_125 ) ) {
V_194 = F_154 ( F_162 ( * V_192 , V_58 , V_64 ,
F_167 ( F_67 ( V_58 ) ) ) , V_191 ) ;
} else {
V_194 = F_153 ( V_191 , * V_192 , F_2 () ) ;
if ( ( * V_192 ) -> V_8 == V_126 )
* V_193 = & ( * V_192 ) -> V_18 . V_16 ;
}
return V_194 ;
}
bool F_168 ( T_1 * V_168 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_168 && V_47 -> V_1 ) )
return false ;
F_94 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_18 . V_20 ;
F_169 ( V_168 , V_72 ) ;
break;
case V_126 :
case V_125 :
* V_168 = V_1 -> V_18 . V_16 ;
break;
default:
F_29 () ;
}
F_95 ( V_47 ) ;
return true ;
}
bool F_170 ( struct V_2 * V_53 ,
const T_1 * V_168 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_168 )
return V_12 ;
F_94 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_123;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_126 :
case V_125 :
V_12 = F_148 ( V_1 -> V_18 . V_16 , * V_168 ) ;
break;
default:
F_29 () ;
}
V_123:
F_95 ( V_53 ) ;
return V_12 ;
}
static struct V_68 * F_171 ( T_7 V_177 , unsigned V_195 ,
unsigned V_72 )
{
struct V_178 * V_194 ;
struct V_68 * V_68 ;
V_194 = F_154 ( V_72 , V_177 ) ;
V_68 = F_172 ( V_177 , V_195 , V_194 ) ;
if ( V_68 && F_173 ( V_68 ) == F_174 ( & V_194 -> V_196 [ 0 ] ) )
F_109 ( V_68 , V_197 ) ;
return V_68 ;
}
struct V_68 *
F_175 ( T_7 V_177 , int V_195 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 , bool V_198 )
{
struct V_1 * V_4 ;
struct V_68 * V_68 ;
unsigned int V_199 ;
struct V_178 * V_194 ;
T_1 * V_77 ;
V_200:
V_4 = F_145 ( V_58 , V_64 ) ;
V_199 = F_176 () ;
if ( V_4 -> V_8 == V_125 ) {
unsigned V_72 ;
V_72 = F_162 ( V_4 , V_58 , V_64 , V_118 + V_195 ) ;
F_106 ( V_4 ) ;
V_68 = F_171 ( V_177 , V_195 , V_72 ) ;
goto V_123;
}
if ( F_150 ( F_177 ( V_201 ) && V_198 ) ) {
int V_202 = V_5 ;
if ( V_4 -> V_8 == V_27 &&
! ( V_4 -> V_10 & V_19 ) )
V_202 = V_4 -> V_18 . V_20 ;
V_77 = F_149 ( V_177 , V_4 ) ;
if ( ! V_77 || F_31 ( V_202 , * V_77 ) ) {
F_106 ( V_4 ) ;
V_68 = F_116 ( V_202 ,
V_177 | V_136 , V_195 ) ;
goto V_123;
}
}
V_77 = F_149 ( V_177 , V_4 ) ;
V_194 = F_153 ( V_177 , V_4 , V_5 ) ;
F_106 ( V_4 ) ;
V_68 = F_178 ( V_177 , V_195 , V_194 , V_77 ) ;
V_123:
if ( F_150 ( ! V_68 && F_179 ( V_199 ) ) )
goto V_200;
return V_68 ;
}
struct V_68 * F_180 ( T_7 V_177 , unsigned V_195 )
{
struct V_1 * V_4 = & V_9 ;
struct V_68 * V_68 ;
unsigned int V_199 ;
if ( ! F_158 () && ! ( V_177 & V_136 ) )
V_4 = F_1 ( V_47 ) ;
V_200:
V_199 = F_176 () ;
if ( V_4 -> V_8 == V_125 )
V_68 = F_171 ( V_177 , V_195 , F_155 ( V_4 ) ) ;
else
V_68 = F_178 ( V_177 , V_195 ,
F_153 ( V_177 , V_4 , F_2 () ) ,
F_149 ( V_177 , V_4 ) ) ;
if ( F_150 ( ! V_68 && F_179 ( V_199 ) ) )
goto V_200;
return V_68 ;
}
int F_181 ( struct V_57 * V_203 , struct V_57 * V_204 )
{
struct V_1 * V_4 = F_80 ( F_89 ( V_203 ) ) ;
if ( F_81 ( V_4 ) )
return F_82 ( V_4 ) ;
V_204 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_182 ( struct V_1 * V_106 )
{
struct V_1 * V_54 = F_21 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_20 ( - V_40 ) ;
if ( V_106 == V_47 -> V_1 ) {
F_94 ( V_47 ) ;
* V_54 = * V_106 ;
F_95 ( V_47 ) ;
} else
* V_54 = * V_106 ;
if ( F_183 () ) {
T_1 V_205 = V_32 ( V_47 ) ;
if ( V_54 -> V_10 & V_51 )
F_35 ( V_54 , & V_205 , V_46 ) ;
else
F_35 ( V_54 , & V_205 , V_44 ) ;
}
F_22 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_184 ( struct V_1 * V_206 , struct V_1 * V_207 )
{
if ( ! V_206 || ! V_207 )
return false ;
if ( V_206 -> V_8 != V_207 -> V_8 )
return false ;
if ( V_206 -> V_10 != V_207 -> V_10 )
return false ;
if ( F_3 ( V_206 ) )
if ( ! F_36 ( V_206 -> V_30 . V_31 , V_207 -> V_30 . V_31 ) )
return false ;
switch ( V_206 -> V_8 ) {
case V_126 :
case V_125 :
return ! ! F_36 ( V_206 -> V_18 . V_16 , V_207 -> V_18 . V_16 ) ;
case V_27 :
return V_206 -> V_18 . V_20 == V_207 -> V_18 . V_20 ;
default:
F_29 () ;
return false ;
}
}
static struct V_208 *
F_185 ( struct V_209 * V_210 , unsigned long V_88 , unsigned long V_65 )
{
struct V_211 * V_212 = V_210 -> V_213 . V_211 ;
while ( V_212 ) {
struct V_208 * V_3 = F_186 ( V_212 , struct V_208 , V_179 ) ;
if ( V_88 >= V_3 -> V_65 )
V_212 = V_212 -> V_214 ;
else if ( V_65 <= V_3 -> V_88 )
V_212 = V_212 -> V_215 ;
else
break;
}
if ( ! V_212 )
return NULL ;
for (; ; ) {
struct V_208 * V_30 = NULL ;
struct V_211 * V_94 = F_187 ( V_212 ) ;
if ( ! V_94 )
break;
V_30 = F_186 ( V_94 , struct V_208 , V_179 ) ;
if ( V_30 -> V_65 <= V_88 )
break;
V_212 = V_94 ;
}
return F_186 ( V_212 , struct V_208 , V_179 ) ;
}
static void F_188 ( struct V_209 * V_210 , struct V_208 * V_54 )
{
struct V_211 * * V_3 = & V_210 -> V_213 . V_211 ;
struct V_211 * V_216 = NULL ;
struct V_208 * V_179 ;
while ( * V_3 ) {
V_216 = * V_3 ;
V_179 = F_186 ( V_216 , struct V_208 , V_179 ) ;
if ( V_54 -> V_88 < V_179 -> V_88 )
V_3 = & ( * V_3 ) -> V_215 ;
else if ( V_54 -> V_65 > V_179 -> V_65 )
V_3 = & ( * V_3 ) -> V_214 ;
else
F_29 () ;
}
F_189 ( & V_54 -> V_179 , V_216 , V_3 ) ;
F_190 ( & V_54 -> V_179 , & V_210 -> V_213 ) ;
F_18 ( L_4 , V_54 -> V_88 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_191 ( struct V_209 * V_210 , unsigned long V_217 )
{
struct V_1 * V_4 = NULL ;
struct V_208 * V_218 ;
if ( ! V_210 -> V_213 . V_211 )
return NULL ;
F_192 ( & V_210 -> V_219 ) ;
V_218 = F_185 ( V_210 , V_217 , V_217 + 1 ) ;
if ( V_218 ) {
F_144 ( V_218 -> V_34 ) ;
V_4 = V_218 -> V_34 ;
}
F_193 ( & V_210 -> V_219 ) ;
return V_4 ;
}
static void F_194 ( struct V_208 * V_212 )
{
F_83 ( V_212 -> V_34 ) ;
F_25 ( V_220 , V_212 ) ;
}
int F_195 ( struct V_68 * V_68 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_172 * V_172 ;
int V_221 = F_58 ( V_68 ) ;
unsigned long V_114 ;
int V_222 = F_196 () ;
int V_223 = F_197 ( V_222 ) ;
int V_224 = - 1 ;
int V_12 = - 1 ;
F_128 ( ! V_58 ) ;
V_4 = F_145 ( V_58 , V_64 ) ;
if ( ! ( V_4 -> V_10 & V_156 ) )
goto V_123;
switch ( V_4 -> V_8 ) {
case V_125 :
F_128 ( V_64 >= V_58 -> V_90 ) ;
F_128 ( V_64 < V_58 -> V_91 ) ;
V_114 = V_58 -> V_107 ;
V_114 += ( V_64 - V_58 -> V_91 ) >> V_118 ;
V_224 = F_161 ( V_4 , V_58 , V_114 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_224 = F_2 () ;
else
V_224 = V_4 -> V_18 . V_20 ;
break;
case V_126 :
if ( F_31 ( V_221 , V_4 -> V_18 . V_16 ) )
goto V_123;
( void ) F_160 (
F_154 ( F_2 () , V_225 ) ,
F_151 ( V_225 ) ,
& V_4 -> V_18 . V_16 , & V_172 ) ;
V_224 = V_172 -> V_5 ;
break;
default:
F_29 () ;
}
if ( V_4 -> V_10 & V_226 ) {
V_224 = V_223 ;
if ( ! F_198 ( V_47 , V_68 , V_221 , V_222 ) )
goto V_123;
}
if ( V_221 != V_224 )
V_12 = V_224 ;
V_123:
F_106 ( V_4 ) ;
return V_12 ;
}
static void F_199 ( struct V_209 * V_210 , struct V_208 * V_212 )
{
F_18 ( L_5 , V_212 -> V_88 , V_212 -> V_65 ) ;
F_200 ( & V_212 -> V_179 , & V_210 -> V_213 ) ;
F_194 ( V_212 ) ;
}
static void F_201 ( struct V_208 * V_5 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_88 = V_88 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_208 * F_202 ( unsigned long V_88 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_208 * V_212 ;
struct V_1 * V_227 ;
V_212 = F_21 ( V_220 , V_39 ) ;
if ( ! V_212 )
return NULL ;
V_227 = F_80 ( V_4 ) ;
if ( F_81 ( V_227 ) ) {
F_25 ( V_220 , V_212 ) ;
return NULL ;
}
V_227 -> V_10 |= V_228 ;
F_201 ( V_212 , V_88 , V_65 , V_227 ) ;
return V_212 ;
}
static int F_203 ( struct V_209 * V_210 , unsigned long V_88 ,
unsigned long V_65 , struct V_208 * V_54 )
{
struct V_208 * V_212 ;
struct V_208 * V_229 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_230:
F_204 ( & V_210 -> V_219 ) ;
V_212 = F_185 ( V_210 , V_88 , V_65 ) ;
while ( V_212 && V_212 -> V_88 < V_65 ) {
struct V_211 * V_113 = F_205 ( & V_212 -> V_179 ) ;
if ( V_212 -> V_88 >= V_88 ) {
if ( V_212 -> V_65 <= V_65 )
F_199 ( V_210 , V_212 ) ;
else
V_212 -> V_88 = V_65 ;
} else {
if ( V_212 -> V_65 > V_65 ) {
if ( ! V_229 )
goto V_231;
* F_17 = * V_212 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_201 ( V_229 , V_65 , V_212 -> V_65 , F_17 ) ;
V_212 -> V_65 = V_88 ;
F_188 ( V_210 , V_229 ) ;
V_229 = NULL ;
F_17 = NULL ;
break;
} else
V_212 -> V_65 = V_88 ;
}
if ( ! V_113 )
break;
V_212 = F_186 ( V_113 , struct V_208 , V_179 ) ;
}
if ( V_54 )
F_188 ( V_210 , V_54 ) ;
F_206 ( & V_210 -> V_219 ) ;
V_12 = 0 ;
V_111:
if ( F_17 )
F_83 ( F_17 ) ;
if ( V_229 )
F_25 ( V_220 , V_229 ) ;
return V_12 ;
V_231:
F_206 ( & V_210 -> V_219 ) ;
V_12 = - V_40 ;
V_229 = F_21 ( V_220 , V_39 ) ;
if ( ! V_229 )
goto V_111;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_111;
goto V_230;
}
void F_207 ( struct V_209 * V_210 , struct V_1 * V_192 )
{
int V_12 ;
V_210 -> V_213 = V_232 ;
F_208 ( & V_210 -> V_219 ) ;
if ( V_192 ) {
struct V_57 V_233 ;
struct V_1 * V_54 ;
F_93 ( V_124 ) ;
if ( ! V_124 )
goto V_234;
V_54 = F_17 ( V_192 -> V_8 , V_192 -> V_10 , & V_192 -> V_30 . V_31 ) ;
if ( F_81 ( V_54 ) )
goto V_235;
F_94 ( V_47 ) ;
V_12 = F_13 ( V_54 , & V_192 -> V_30 . V_31 , V_124 ) ;
F_95 ( V_47 ) ;
if ( V_12 )
goto V_236;
memset ( & V_233 , 0 , sizeof( struct V_57 ) ) ;
V_233 . V_90 = V_237 ;
F_209 ( V_210 , & V_233 , V_54 ) ;
V_236:
F_83 ( V_54 ) ;
V_235:
F_96 ( V_124 ) ;
V_234:
F_83 ( V_192 ) ;
}
}
int F_209 ( struct V_209 * V_238 ,
struct V_57 * V_58 , struct V_1 * V_239 )
{
int V_105 ;
struct V_208 * V_54 = NULL ;
unsigned long V_240 = F_210 ( V_58 ) ;
F_18 ( L_6 ,
V_58 -> V_107 ,
V_240 , V_239 ? V_239 -> V_8 : - 1 ,
V_239 ? V_239 -> V_10 : - 1 ,
V_239 ? F_19 ( V_239 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_239 ) {
V_54 = F_202 ( V_58 -> V_107 , V_58 -> V_107 + V_240 , V_239 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_105 = F_203 ( V_238 , V_58 -> V_107 , V_58 -> V_107 + V_240 , V_54 ) ;
if ( V_105 && V_54 )
F_194 ( V_54 ) ;
return V_105 ;
}
void F_211 ( struct V_209 * V_3 )
{
struct V_208 * V_212 ;
struct V_211 * V_113 ;
if ( ! V_3 -> V_213 . V_211 )
return;
F_204 ( & V_3 -> V_219 ) ;
V_113 = F_212 ( & V_3 -> V_213 ) ;
while ( V_113 ) {
V_212 = F_186 ( V_113 , struct V_208 , V_179 ) ;
V_113 = F_205 ( & V_212 -> V_179 ) ;
F_199 ( V_3 , V_212 ) ;
}
F_206 ( & V_3 -> V_219 ) ;
}
static void T_8 F_213 ( void )
{
bool V_241 = false ;
if ( F_177 ( V_242 ) )
V_241 = true ;
if ( V_243 )
F_214 ( V_243 == 1 ) ;
if ( F_215 () > 1 && ! V_243 ) {
F_216 ( L_7
L_8
L_9 ,
V_241 ? L_10 : L_11 ) ;
F_214 ( V_241 ) ;
}
}
static int T_8 F_217 ( char * V_244 )
{
int V_12 = 0 ;
if ( ! V_244 )
goto V_123;
if ( ! strcmp ( V_244 , L_12 ) ) {
V_243 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_244 , L_13 ) ) {
V_243 = - 1 ;
V_12 = 1 ;
}
V_123:
if ( ! V_12 )
F_218 ( L_14 ) ;
return V_12 ;
}
static inline void T_8 F_213 ( void )
{
}
void T_8 F_219 ( void )
{
T_1 F_155 ;
unsigned long V_245 = 0 ;
int V_72 , V_246 = 0 ;
V_38 = F_220 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_247 , NULL ) ;
V_220 = F_220 ( L_16 ,
sizeof( struct V_208 ) ,
0 , V_247 , NULL ) ;
F_221 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_222 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_156 | V_226 ,
. V_18 = { . V_20 = V_72 , } ,
} ;
}
F_98 ( F_155 ) ;
F_223 (nid, N_MEMORY) {
unsigned long V_248 = F_224 ( V_72 ) ;
if ( V_245 < V_248 ) {
V_245 = V_248 ;
V_246 = V_72 ;
}
if ( ( V_248 << V_118 ) >= ( 16 << 20 ) )
F_99 ( V_72 , F_155 ) ;
}
if ( F_150 ( F_9 ( F_155 ) ) )
F_99 ( V_246 , F_155 ) ;
if ( F_92 ( V_125 , 0 , & F_155 ) )
F_225 ( L_17 , V_249 ) ;
F_213 () ;
}
void F_226 ( void )
{
F_92 ( V_35 , 0 , NULL ) ;
}
int F_227 ( char * V_244 , struct V_1 * * V_192 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_151 ;
T_1 V_16 ;
char * V_250 = strchr ( V_244 , ':' ) ;
char * V_10 = strchr ( V_244 , '=' ) ;
int V_105 = 1 ;
if ( V_250 ) {
* V_250 ++ = '\0' ;
if ( F_228 ( V_250 , V_16 ) )
goto V_123;
if ( ! F_229 ( V_16 , V_25 [ V_26 ] ) )
goto V_123;
} else
F_98 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_251 ; V_8 ++ ) {
if ( ! strcmp ( V_244 , V_252 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_251 )
goto V_123;
switch ( V_8 ) {
case V_27 :
if ( V_250 ) {
char * V_253 = V_250 ;
while ( isdigit ( * V_253 ) )
V_253 ++ ;
if ( * V_253 )
goto V_123;
}
break;
case V_125 :
if ( ! V_250 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_250 )
goto V_123;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_250 )
V_105 = 0 ;
goto V_123;
case V_126 :
if ( ! V_250 )
goto V_123;
}
V_151 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_18 ) )
V_151 |= V_36 ;
else if ( ! strcmp ( V_10 , L_19 ) )
V_151 |= V_28 ;
else
goto V_123;
}
V_54 = F_17 ( V_8 , V_151 , & V_16 ) ;
if ( F_81 ( V_54 ) )
goto V_123;
if ( V_8 != V_27 )
V_54 -> V_18 . V_16 = V_16 ;
else if ( V_250 )
V_54 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_54 -> V_10 |= V_19 ;
V_54 -> V_30 . V_31 = V_16 ;
V_105 = 0 ;
V_123:
if ( V_250 )
* -- V_250 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_105 )
* V_192 = V_54 ;
return V_105 ;
}
void F_230 ( char * V_254 , int V_255 , struct V_1 * V_4 )
{
char * V_3 = V_254 ;
T_1 V_16 = V_256 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_226 ) ) {
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
F_99 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_126 :
case V_125 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_133 ( 1 ) ;
snprintf ( V_3 , V_255 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_255 , L_21 , V_252 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_254 + V_255 - V_3 , L_22 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_254 + V_255 - V_3 , L_18 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_254 + V_255 - V_3 , L_19 ) ;
}
if ( ! F_9 ( V_16 ) )
V_3 += F_231 ( V_3 , V_254 + V_255 - V_3 , L_23 ,
F_232 ( & V_16 ) ) ;
}
