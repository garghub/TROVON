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
int V_72 ;
T_3 * V_73 ;
T_4 * V_74 ;
F_43 ( V_58 , V_64 , V_63 ) ;
if ( F_44 ( V_63 ) )
return 0 ;
V_73 = F_45 ( V_67 -> V_56 , V_63 , V_64 , & V_74 ) ;
for (; V_64 != V_65 ; V_73 ++ , V_64 += V_75 ) {
if ( ! F_46 ( * V_73 ) )
continue;
V_68 = F_47 ( V_58 , V_64 , * V_73 ) ;
if ( ! V_68 )
continue;
if ( F_48 ( V_68 ) )
continue;
V_72 = F_49 ( V_68 ) ;
if ( F_31 ( V_72 , * V_70 -> V_76 ) == ! ! ( V_10 & V_77 ) )
continue;
if ( V_10 & ( V_78 | V_79 ) )
F_50 ( V_68 , V_70 -> V_80 , V_10 ) ;
}
F_51 ( V_73 - 1 , V_74 ) ;
F_52 () ;
return 0 ;
}
static int F_53 ( T_3 * V_73 , unsigned long V_81 ,
unsigned long V_64 , unsigned long V_65 ,
struct V_66 * V_67 )
{
#ifdef F_54
struct V_69 * V_70 = V_67 -> V_71 ;
unsigned long V_10 = V_70 -> V_10 ;
int V_72 ;
struct V_68 * V_68 ;
T_4 * V_74 ;
T_3 V_82 ;
V_74 = F_55 ( F_56 ( V_67 -> V_58 ) , V_67 -> V_56 , V_73 ) ;
V_82 = F_57 ( V_73 ) ;
if ( ! F_46 ( V_82 ) )
goto V_83;
V_68 = F_58 ( V_82 ) ;
V_72 = F_49 ( V_68 ) ;
if ( F_31 ( V_72 , * V_70 -> V_76 ) == ! ! ( V_10 & V_77 ) )
goto V_83;
if ( V_10 & ( V_79 ) ||
( V_10 & V_78 && F_59 ( V_68 ) == 1 ) )
F_60 ( V_68 , V_70 -> V_80 ) ;
V_83:
F_61 ( V_74 ) ;
#else
F_29 () ;
#endif
return 0 ;
}
unsigned long F_62 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_84 ;
V_84 = F_63 ( V_58 , V_64 , V_65 , V_85 , 0 , 1 ) ;
if ( V_84 )
F_64 ( V_86 , V_84 ) ;
return V_84 ;
}
static unsigned long F_62 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static int F_65 ( unsigned long V_87 , unsigned long V_65 ,
struct V_66 * V_67 )
{
struct V_57 * V_58 = V_67 -> V_58 ;
struct V_69 * V_70 = V_67 -> V_71 ;
unsigned long V_88 = V_58 -> V_89 ;
unsigned long V_10 = V_70 -> V_10 ;
if ( V_58 -> V_90 & V_91 )
return 1 ;
if ( V_88 > V_65 )
V_88 = V_65 ;
if ( V_58 -> V_92 > V_87 )
V_87 = V_58 -> V_92 ;
if ( ! ( V_10 & V_93 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_89 < V_65 )
return - V_94 ;
if ( V_70 -> V_95 && V_70 -> V_95 -> V_89 < V_58 -> V_92 )
return - V_94 ;
}
V_70 -> V_95 = V_58 ;
if ( V_58 -> V_90 & V_91 )
return 1 ;
if ( V_10 & V_96 ) {
if ( V_58 -> V_90 & ( V_97 | V_98 | V_99 ) )
F_62 ( V_58 , V_87 , V_88 ) ;
return 1 ;
}
if ( ( V_10 & V_100 ) ||
( ( V_10 & ( V_78 | V_79 ) ) &&
F_66 ( V_58 ) ) )
return 0 ;
return 1 ;
}
static int
F_67 ( struct V_55 * V_56 , unsigned long V_87 , unsigned long V_65 ,
T_1 * V_16 , unsigned long V_10 ,
struct V_101 * V_80 )
{
struct V_69 V_70 = {
. V_80 = V_80 ,
. V_10 = V_10 ,
. V_76 = V_16 ,
. V_95 = NULL ,
} ;
struct V_66 V_102 = {
. V_103 = F_53 ,
. V_104 = F_42 ,
. V_105 = F_65 ,
. V_56 = V_56 ,
. V_71 = & V_70 ,
} ;
return F_68 ( V_87 , V_65 , & V_102 ) ;
}
static int F_69 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_106 ;
struct V_1 * V_107 ;
struct V_1 * V_54 ;
F_18 ( L_2 ,
V_58 -> V_92 , V_58 -> V_89 , V_58 -> V_108 ,
V_58 -> V_109 , V_58 -> V_110 ,
V_58 -> V_109 ? V_58 -> V_109 -> V_111 : NULL ) ;
V_54 = F_70 ( V_4 ) ;
if ( F_71 ( V_54 ) )
return F_72 ( V_54 ) ;
if ( V_58 -> V_109 && V_58 -> V_109 -> V_111 ) {
V_106 = V_58 -> V_109 -> V_111 ( V_58 , V_54 ) ;
if ( V_106 )
goto V_112;
}
V_107 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_73 ( V_107 ) ;
return 0 ;
V_112:
F_73 ( V_54 ) ;
return V_106 ;
}
static int F_74 ( struct V_55 * V_56 , unsigned long V_87 ,
unsigned long V_65 , struct V_1 * V_113 )
{
struct V_57 * V_114 ;
struct V_57 * V_95 ;
struct V_57 * V_58 ;
int V_106 = 0 ;
T_5 V_115 ;
unsigned long V_116 ;
unsigned long V_117 ;
V_58 = F_75 ( V_56 , V_87 ) ;
if ( ! V_58 || V_58 -> V_92 > V_87 )
return - V_94 ;
V_95 = V_58 -> V_118 ;
if ( V_87 > V_58 -> V_92 )
V_95 = V_58 ;
for (; V_58 && V_58 -> V_92 < V_65 ; V_95 = V_58 , V_58 = V_114 ) {
V_114 = V_58 -> V_61 ;
V_116 = F_76 ( V_87 , V_58 -> V_92 ) ;
V_117 = F_77 ( V_65 , V_58 -> V_89 ) ;
if ( F_78 ( F_79 ( V_58 ) , V_113 ) )
continue;
V_115 = V_58 -> V_108 +
( ( V_116 - V_58 -> V_92 ) >> V_119 ) ;
V_95 = F_80 ( V_56 , V_95 , V_116 , V_117 , V_58 -> V_90 ,
V_58 -> V_120 , V_58 -> V_110 , V_115 ,
V_113 ) ;
if ( V_95 ) {
V_58 = V_95 ;
V_114 = V_58 -> V_61 ;
if ( F_78 ( F_79 ( V_58 ) , V_113 ) )
continue;
goto V_121;
}
if ( V_58 -> V_92 != V_116 ) {
V_106 = F_81 ( V_58 -> V_122 , V_58 , V_116 , 1 ) ;
if ( V_106 )
goto V_123;
}
if ( V_58 -> V_89 != V_117 ) {
V_106 = F_81 ( V_58 -> V_122 , V_58 , V_117 , 0 ) ;
if ( V_106 )
goto V_123;
}
V_121:
V_106 = F_69 ( V_58 , V_113 ) ;
if ( V_106 )
goto V_123;
}
V_123:
return V_106 ;
}
static long F_82 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_54 , * V_107 ;
F_83 ( V_124 ) ;
int V_12 ;
if ( ! V_124 )
return - V_40 ;
V_54 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_71 ( V_54 ) ) {
V_12 = F_72 ( V_54 ) ;
goto V_123;
}
F_84 ( V_47 ) ;
V_12 = F_13 ( V_54 , V_16 , V_124 ) ;
if ( V_12 ) {
F_85 ( V_47 ) ;
F_73 ( V_54 ) ;
goto V_123;
}
V_107 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_125 &&
F_6 ( V_54 -> V_18 . V_16 ) )
V_47 -> V_48 = F_11 ( V_54 -> V_18 . V_16 ) ;
F_85 ( V_47 ) ;
F_73 ( V_107 ) ;
V_12 = 0 ;
V_123:
F_86 ( V_124 ) ;
return V_12 ;
}
static void F_87 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_88 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_126 :
case V_125 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_89 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_29 () ;
}
}
static int F_90 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_68 * V_3 ;
int V_106 ;
V_106 = F_91 ( V_47 , V_56 , V_64 & V_127 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_106 >= 0 ) {
V_106 = F_49 ( V_3 ) ;
F_92 ( V_3 ) ;
}
return V_106 ;
}
static long F_93 ( int * V_34 , T_1 * V_76 ,
unsigned long V_64 , unsigned long V_10 )
{
int V_106 ;
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
F_84 ( V_47 ) ;
* V_76 = V_24 ;
F_85 ( V_47 ) ;
return 0 ;
}
if ( V_10 & V_129 ) {
F_94 ( & V_56 -> V_59 ) ;
V_58 = F_95 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_96 ( & V_56 -> V_59 ) ;
return - V_94 ;
}
if ( V_58 -> V_109 && V_58 -> V_109 -> V_131 )
V_4 = V_58 -> V_109 -> V_131 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_128 ) {
if ( V_10 & V_129 ) {
V_106 = F_90 ( V_56 , V_64 ) ;
if ( V_106 < 0 )
goto V_123;
* V_34 = V_106 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_125 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_106 = - V_17 ;
goto V_123;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
if ( V_58 ) {
F_96 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_106 = 0 ;
if ( V_76 ) {
if ( F_3 ( V_4 ) ) {
* V_76 = V_4 -> V_30 . V_31 ;
} else {
F_84 ( V_47 ) ;
F_87 ( V_4 , V_76 ) ;
F_85 ( V_47 ) ;
}
}
V_123:
F_97 ( V_4 ) ;
if ( V_58 )
F_96 ( & V_47 -> V_56 -> V_59 ) ;
return V_106 ;
}
static void F_50 ( struct V_68 * V_68 , struct V_101 * V_80 ,
unsigned long V_10 )
{
if ( ( V_10 & V_79 ) || F_59 ( V_68 ) == 1 ) {
if ( ! F_98 ( V_68 ) ) {
F_99 ( & V_68 -> V_132 , V_80 ) ;
F_100 ( V_68 , V_133 +
F_101 ( V_68 ) ) ;
}
}
}
static struct V_68 * F_102 ( struct V_68 * V_68 , unsigned long V_5 , int * * V_134 )
{
if ( F_103 ( V_68 ) )
return F_104 ( F_105 ( F_106 ( V_68 ) ) ,
V_5 ) ;
else
return F_107 ( V_5 , V_135 |
V_136 , 0 ) ;
}
static int F_108 ( struct V_55 * V_56 , int V_137 , int V_138 ,
int V_10 )
{
T_1 V_76 ;
F_109 ( V_80 ) ;
int V_106 = 0 ;
F_88 ( V_76 ) ;
F_89 ( V_137 , V_76 ) ;
F_15 ( ! ( V_10 & ( V_78 | V_79 ) ) ) ;
F_67 ( V_56 , V_56 -> V_60 -> V_92 , V_56 -> V_139 , & V_76 ,
V_10 | V_93 , & V_80 ) ;
if ( ! F_110 ( & V_80 ) ) {
V_106 = F_111 ( & V_80 , F_102 , NULL , V_138 ,
V_140 , V_141 ) ;
if ( V_106 )
F_112 ( & V_80 ) ;
}
return V_106 ;
}
int F_113 ( struct V_55 * V_56 , const T_1 * V_142 ,
const T_1 * V_143 , int V_10 )
{
int V_144 = 0 ;
int V_106 ;
T_1 V_15 ;
V_106 = F_114 () ;
if ( V_106 )
return V_106 ;
F_94 ( & V_56 -> V_59 ) ;
V_15 = * V_142 ;
while ( ! F_9 ( V_15 ) ) {
int V_145 , V_146 ;
int V_137 = V_6 ;
int V_138 = 0 ;
F_115 (s, tmp) {
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
F_116 ( V_137 , V_15 ) ;
V_106 = F_108 ( V_56 , V_137 , V_138 , V_10 ) ;
if ( V_106 > 0 )
V_144 += V_106 ;
if ( V_106 < 0 )
break;
}
F_96 ( & V_56 -> V_59 ) ;
if ( V_106 < 0 )
return V_106 ;
return V_144 ;
}
static struct V_68 * F_117 ( struct V_68 * V_68 , unsigned long V_87 , int * * V_134 )
{
struct V_57 * V_58 ;
unsigned long V_147 ( V_148 ) ;
V_58 = F_75 ( V_47 -> V_56 , V_87 ) ;
while ( V_58 ) {
V_148 = F_118 ( V_68 , V_58 ) ;
if ( V_148 != - V_94 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_103 ( V_68 ) ) {
F_119 ( ! V_58 ) ;
return F_120 ( V_58 , V_148 , 1 ) ;
}
return F_121 ( V_135 , V_58 , V_148 ) ;
}
static void F_50 ( struct V_68 * V_68 , struct V_101 * V_80 ,
unsigned long V_10 )
{
}
int F_113 ( struct V_55 * V_56 , const T_1 * V_142 ,
const T_1 * V_143 , int V_10 )
{
return - V_149 ;
}
static struct V_68 * F_117 ( struct V_68 * V_68 , unsigned long V_87 , int * * V_134 )
{
return NULL ;
}
static long F_122 ( unsigned long V_87 , unsigned long V_150 ,
unsigned short V_8 , unsigned short V_151 ,
T_1 * V_76 , unsigned long V_10 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_106 ;
F_109 ( V_80 ) ;
if ( V_10 & ~ ( unsigned long ) V_152 )
return - V_17 ;
if ( ( V_10 & V_79 ) && ! F_123 ( V_153 ) )
return - V_154 ;
if ( V_87 & ~ V_127 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_100 ;
V_150 = ( V_150 + V_75 - 1 ) & V_127 ;
V_65 = V_87 + V_150 ;
if ( V_65 < V_87 )
return - V_17 ;
if ( V_65 == V_87 )
return 0 ;
V_54 = F_17 ( V_8 , V_151 , V_76 ) ;
if ( F_71 ( V_54 ) )
return F_72 ( V_54 ) ;
if ( V_10 & V_96 )
V_54 -> V_10 |= V_155 ;
if ( ! V_54 )
V_10 |= V_93 ;
F_18 ( L_3 ,
V_87 , V_87 + V_150 , V_8 , V_151 ,
V_76 ? F_19 ( * V_76 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_78 | V_79 ) ) {
V_106 = F_114 () ;
if ( V_106 )
goto V_156;
}
{
F_83 ( V_124 ) ;
if ( V_124 ) {
F_40 ( & V_56 -> V_59 ) ;
F_84 ( V_47 ) ;
V_106 = F_13 ( V_54 , V_76 , V_124 ) ;
F_85 ( V_47 ) ;
if ( V_106 )
F_41 ( & V_56 -> V_59 ) ;
} else
V_106 = - V_40 ;
F_86 ( V_124 ) ;
}
if ( V_106 )
goto V_156;
V_106 = F_67 ( V_56 , V_87 , V_65 , V_76 ,
V_10 | V_77 , & V_80 ) ;
if ( ! V_106 )
V_106 = F_74 ( V_56 , V_87 , V_65 , V_54 ) ;
if ( ! V_106 ) {
int V_157 = 0 ;
if ( ! F_110 ( & V_80 ) ) {
F_124 ( V_10 & V_96 ) ;
V_157 = F_111 ( & V_80 , F_117 , NULL ,
V_87 , V_140 , V_158 ) ;
if ( V_157 )
F_112 ( & V_80 ) ;
}
if ( V_157 && ( V_10 & V_100 ) )
V_106 = - V_159 ;
} else
F_112 ( & V_80 ) ;
F_41 ( & V_56 -> V_59 ) ;
V_156:
F_73 ( V_54 ) ;
return V_106 ;
}
static int F_125 ( T_1 * V_16 , const unsigned long T_6 * V_76 ,
unsigned long V_160 )
{
unsigned long V_161 ;
unsigned long V_162 ;
unsigned long V_163 ;
-- V_160 ;
F_88 ( * V_16 ) ;
if ( V_160 == 0 || ! V_76 )
return 0 ;
if ( V_160 > V_75 * V_164 )
return - V_17 ;
V_162 = F_126 ( V_160 ) ;
if ( ( V_160 % V_165 ) == 0 )
V_163 = ~ 0UL ;
else
V_163 = ( 1UL << ( V_160 % V_165 ) ) - 1 ;
if ( V_162 > F_126 ( V_49 ) ) {
if ( V_162 > V_75 / sizeof( long ) )
return - V_17 ;
for ( V_161 = F_126 ( V_49 ) ; V_161 < V_162 ; V_161 ++ ) {
unsigned long V_166 ;
if ( F_127 ( V_166 , V_76 + V_161 ) )
return - V_94 ;
if ( V_161 == V_162 - 1 ) {
if ( V_166 & V_163 )
return - V_17 ;
} else if ( V_166 )
return - V_17 ;
}
V_162 = F_126 ( V_49 ) ;
V_163 = ~ 0UL ;
}
if ( F_128 ( F_19 ( * V_16 ) , V_76 , V_162 *sizeof( unsigned long ) ) )
return - V_94 ;
F_19 ( * V_16 ) [ V_162 - 1 ] &= V_163 ;
return 0 ;
}
static int F_129 ( unsigned long T_6 * V_167 , unsigned long V_160 ,
T_1 * V_16 )
{
unsigned long V_168 = F_130 ( V_160 - 1 , 64 ) / 8 ;
const int V_169 = F_126 ( V_49 ) * sizeof( long ) ;
if ( V_168 > V_169 ) {
if ( V_168 > V_75 )
return - V_17 ;
if ( F_131 ( ( char T_6 * ) V_167 + V_169 , V_168 - V_169 ) )
return - V_94 ;
V_168 = V_169 ;
}
return F_132 ( V_167 , F_19 ( * V_16 ) , V_168 ) ? - V_94 : 0 ;
}
struct V_1 * F_133 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = NULL ;
if ( V_58 ) {
if ( V_58 -> V_109 && V_58 -> V_109 -> V_131 ) {
V_4 = V_58 -> V_109 -> V_131 ( V_58 , V_64 ) ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_134 ( V_4 ) )
F_135 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_136 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = F_133 ( V_58 , V_64 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 ;
}
bool F_137 ( struct V_57 * V_58 )
{
struct V_1 * V_4 ;
if ( V_58 -> V_109 && V_58 -> V_109 -> V_131 ) {
bool V_12 = false ;
V_4 = V_58 -> V_109 -> V_131 ( V_58 , V_58 -> V_92 ) ;
if ( V_4 && ( V_4 -> V_10 & V_155 ) )
V_12 = true ;
F_97 ( V_4 ) ;
return V_12 ;
}
V_4 = V_58 -> V_62 ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 -> V_10 & V_155 ;
}
static int F_138 ( struct V_1 * V_34 , enum V_170 V_171 )
{
enum V_170 V_172 = V_173 ;
F_119 ( V_172 == V_174 ) ;
if ( ! F_139 ( V_34 -> V_18 . V_16 , V_25 [ V_175 ] ) )
V_172 = V_174 ;
return V_171 >= V_172 ;
}
static T_1 * F_140 ( T_7 V_176 , struct V_1 * V_34 )
{
if ( F_141 ( V_34 -> V_8 == V_126 ) &&
F_138 ( V_34 , F_142 ( V_176 ) ) &&
F_143 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static struct V_177 * F_144 ( T_7 V_176 , struct V_1 * V_34 ,
int V_178 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_10 & V_19 ) )
V_178 = V_34 -> V_18 . V_20 ;
break;
case V_126 :
if ( F_141 ( V_176 & V_136 ) &&
F_141 ( ! F_31 ( V_178 , V_34 -> V_18 . V_16 ) ) )
V_178 = F_11 ( V_34 -> V_18 . V_16 ) ;
break;
default:
F_29 () ;
}
return F_145 ( V_178 , V_176 ) ;
}
static unsigned F_146 ( struct V_1 * V_34 )
{
unsigned V_72 , V_114 ;
struct V_2 * V_179 = V_47 ;
V_72 = V_179 -> V_48 ;
V_114 = F_32 ( V_72 , V_34 -> V_18 . V_16 ) ;
if ( V_114 >= V_49 )
V_114 = F_11 ( V_34 -> V_18 . V_16 ) ;
if ( V_114 < V_49 )
V_179 -> V_48 = V_114 ;
return V_72 ;
}
unsigned int F_147 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_148 () ;
if ( F_149 () )
return V_5 ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_125 :
return F_146 ( V_34 ) ;
case V_126 : {
struct V_177 * V_177 ;
struct V_171 * V_171 ;
enum V_170 V_180 = F_142 ( V_39 ) ;
V_177 = & F_150 ( V_5 ) -> V_181 [ 0 ] ;
( void ) F_151 ( V_177 , V_180 ,
& V_34 -> V_18 . V_16 ,
& V_171 ) ;
return V_171 ? V_171 -> V_5 : V_5 ;
}
default:
F_29 () ;
}
}
static unsigned F_152 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_182 )
{
unsigned V_183 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_184 ;
int V_185 ;
int V_72 = V_6 ;
if ( ! V_183 )
return F_2 () ;
V_184 = ( unsigned int ) V_182 % V_183 ;
V_185 = 0 ;
do {
V_72 = F_32 ( V_72 , V_4 -> V_18 . V_16 ) ;
V_185 ++ ;
} while ( V_185 <= V_184 );
return V_72 ;
}
static inline unsigned F_153 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_186 )
{
if ( V_58 ) {
unsigned long V_182 ;
F_119 ( V_186 < V_119 ) ;
V_182 = V_58 -> V_108 >> ( V_186 - V_119 ) ;
V_182 += ( V_64 - V_58 -> V_92 ) >> V_186 ;
return F_152 ( V_4 , V_58 , V_182 ) ;
} else
return F_146 ( V_4 ) ;
}
int F_154 ( const T_1 * V_187 )
{
int V_30 , V_188 = V_6 ;
V_30 = F_6 ( * V_187 ) ;
if ( V_30 )
V_188 = F_155 ( V_187 -> V_189 ,
F_156 () % V_30 , V_49 ) ;
return V_188 ;
}
struct V_177 * F_157 ( struct V_57 * V_58 , unsigned long V_64 ,
T_7 V_190 , struct V_1 * * V_191 ,
T_1 * * V_192 )
{
struct V_177 * V_193 ;
* V_191 = F_136 ( V_58 , V_64 ) ;
* V_192 = NULL ;
if ( F_141 ( ( * V_191 ) -> V_8 == V_125 ) ) {
V_193 = F_145 ( F_153 ( * V_191 , V_58 , V_64 ,
F_158 ( F_56 ( V_58 ) ) ) , V_190 ) ;
} else {
V_193 = F_144 ( V_190 , * V_191 , F_2 () ) ;
if ( ( * V_191 ) -> V_8 == V_126 )
* V_192 = & ( * V_191 ) -> V_18 . V_16 ;
}
return V_193 ;
}
bool F_159 ( T_1 * V_167 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_167 && V_47 -> V_1 ) )
return false ;
F_84 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_18 . V_20 ;
F_160 ( V_167 , V_72 ) ;
break;
case V_126 :
case V_125 :
* V_167 = V_1 -> V_18 . V_16 ;
break;
default:
F_29 () ;
}
F_85 ( V_47 ) ;
return true ;
}
bool F_161 ( struct V_2 * V_53 ,
const T_1 * V_167 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_167 )
return V_12 ;
F_84 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_123;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_126 :
case V_125 :
V_12 = F_139 ( V_1 -> V_18 . V_16 , * V_167 ) ;
break;
default:
F_29 () ;
}
V_123:
F_85 ( V_53 ) ;
return V_12 ;
}
static struct V_68 * F_162 ( T_7 V_176 , unsigned V_194 ,
unsigned V_72 )
{
struct V_177 * V_193 ;
struct V_68 * V_68 ;
V_193 = F_145 ( V_72 , V_176 ) ;
V_68 = F_163 ( V_176 , V_194 , V_193 ) ;
if ( V_68 && F_164 ( V_68 ) == F_165 ( & V_193 -> V_195 [ 0 ] ) )
F_100 ( V_68 , V_196 ) ;
return V_68 ;
}
struct V_68 *
F_166 ( T_7 V_176 , int V_194 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 , bool V_197 )
{
struct V_1 * V_4 ;
struct V_68 * V_68 ;
unsigned int V_198 ;
struct V_177 * V_193 ;
T_1 * V_76 ;
V_199:
V_4 = F_136 ( V_58 , V_64 ) ;
V_198 = F_167 () ;
if ( F_141 ( F_168 ( V_200 ) && V_197 &&
V_4 -> V_8 != V_125 ) ) {
V_76 = F_140 ( V_176 , V_4 ) ;
if ( ! V_76 || F_31 ( V_5 , * V_76 ) ) {
F_97 ( V_4 ) ;
V_68 = F_107 ( V_5 ,
V_176 | V_136 , V_194 ) ;
goto V_123;
}
}
if ( V_4 -> V_8 == V_125 ) {
unsigned V_72 ;
V_72 = F_153 ( V_4 , V_58 , V_64 , V_119 + V_194 ) ;
F_97 ( V_4 ) ;
V_68 = F_162 ( V_176 , V_194 , V_72 ) ;
goto V_123;
}
V_76 = F_140 ( V_176 , V_4 ) ;
V_193 = F_144 ( V_176 , V_4 , V_5 ) ;
F_97 ( V_4 ) ;
V_68 = F_169 ( V_176 , V_194 , V_193 , V_76 ) ;
V_123:
if ( F_141 ( ! V_68 && F_170 ( V_198 ) ) )
goto V_199;
return V_68 ;
}
struct V_68 * F_171 ( T_7 V_176 , unsigned V_194 )
{
struct V_1 * V_4 = & V_9 ;
struct V_68 * V_68 ;
unsigned int V_198 ;
if ( ! F_149 () && ! ( V_176 & V_136 ) )
V_4 = F_1 ( V_47 ) ;
V_199:
V_198 = F_167 () ;
if ( V_4 -> V_8 == V_125 )
V_68 = F_162 ( V_176 , V_194 , F_146 ( V_4 ) ) ;
else
V_68 = F_169 ( V_176 , V_194 ,
F_144 ( V_176 , V_4 , F_2 () ) ,
F_140 ( V_176 , V_4 ) ) ;
if ( F_141 ( ! V_68 && F_170 ( V_198 ) ) )
goto V_199;
return V_68 ;
}
int F_172 ( struct V_57 * V_201 , struct V_57 * V_202 )
{
struct V_1 * V_4 = F_70 ( F_79 ( V_201 ) ) ;
if ( F_71 ( V_4 ) )
return F_72 ( V_4 ) ;
V_202 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_173 ( struct V_1 * V_107 )
{
struct V_1 * V_54 = F_21 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_20 ( - V_40 ) ;
if ( V_107 == V_47 -> V_1 ) {
F_84 ( V_47 ) ;
* V_54 = * V_107 ;
F_85 ( V_47 ) ;
} else
* V_54 = * V_107 ;
if ( F_174 () ) {
T_1 V_203 = V_32 ( V_47 ) ;
if ( V_54 -> V_10 & V_51 )
F_35 ( V_54 , & V_203 , V_46 ) ;
else
F_35 ( V_54 , & V_203 , V_44 ) ;
}
F_22 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_175 ( struct V_1 * V_204 , struct V_1 * V_205 )
{
if ( ! V_204 || ! V_205 )
return false ;
if ( V_204 -> V_8 != V_205 -> V_8 )
return false ;
if ( V_204 -> V_10 != V_205 -> V_10 )
return false ;
if ( F_3 ( V_204 ) )
if ( ! F_36 ( V_204 -> V_30 . V_31 , V_205 -> V_30 . V_31 ) )
return false ;
switch ( V_204 -> V_8 ) {
case V_126 :
case V_125 :
return ! ! F_36 ( V_204 -> V_18 . V_16 , V_205 -> V_18 . V_16 ) ;
case V_27 :
return V_204 -> V_18 . V_20 == V_205 -> V_18 . V_20 ;
default:
F_29 () ;
return false ;
}
}
static struct V_206 *
F_176 ( struct V_207 * V_208 , unsigned long V_87 , unsigned long V_65 )
{
struct V_209 * V_210 = V_208 -> V_211 . V_209 ;
while ( V_210 ) {
struct V_206 * V_3 = F_177 ( V_210 , struct V_206 , V_178 ) ;
if ( V_87 >= V_3 -> V_65 )
V_210 = V_210 -> V_212 ;
else if ( V_65 <= V_3 -> V_87 )
V_210 = V_210 -> V_213 ;
else
break;
}
if ( ! V_210 )
return NULL ;
for (; ; ) {
struct V_206 * V_30 = NULL ;
struct V_209 * V_95 = F_178 ( V_210 ) ;
if ( ! V_95 )
break;
V_30 = F_177 ( V_95 , struct V_206 , V_178 ) ;
if ( V_30 -> V_65 <= V_87 )
break;
V_210 = V_95 ;
}
return F_177 ( V_210 , struct V_206 , V_178 ) ;
}
static void F_179 ( struct V_207 * V_208 , struct V_206 * V_54 )
{
struct V_209 * * V_3 = & V_208 -> V_211 . V_209 ;
struct V_209 * V_214 = NULL ;
struct V_206 * V_178 ;
while ( * V_3 ) {
V_214 = * V_3 ;
V_178 = F_177 ( V_214 , struct V_206 , V_178 ) ;
if ( V_54 -> V_87 < V_178 -> V_87 )
V_3 = & ( * V_3 ) -> V_213 ;
else if ( V_54 -> V_65 > V_178 -> V_65 )
V_3 = & ( * V_3 ) -> V_212 ;
else
F_29 () ;
}
F_180 ( & V_54 -> V_178 , V_214 , V_3 ) ;
F_181 ( & V_54 -> V_178 , & V_208 -> V_211 ) ;
F_18 ( L_4 , V_54 -> V_87 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_182 ( struct V_207 * V_208 , unsigned long V_215 )
{
struct V_1 * V_4 = NULL ;
struct V_206 * V_216 ;
if ( ! V_208 -> V_211 . V_209 )
return NULL ;
F_183 ( & V_208 -> V_217 ) ;
V_216 = F_176 ( V_208 , V_215 , V_215 + 1 ) ;
if ( V_216 ) {
F_135 ( V_216 -> V_34 ) ;
V_4 = V_216 -> V_34 ;
}
F_61 ( & V_208 -> V_217 ) ;
return V_4 ;
}
static void F_184 ( struct V_206 * V_210 )
{
F_73 ( V_210 -> V_34 ) ;
F_25 ( V_218 , V_210 ) ;
}
int F_185 ( struct V_68 * V_68 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_171 * V_171 ;
int V_219 = F_49 ( V_68 ) ;
unsigned long V_115 ;
int V_220 = F_186 () ;
int V_221 = F_187 ( V_220 ) ;
int V_222 = - 1 ;
int V_12 = - 1 ;
F_119 ( ! V_58 ) ;
V_4 = F_136 ( V_58 , V_64 ) ;
if ( ! ( V_4 -> V_10 & V_155 ) )
goto V_123;
switch ( V_4 -> V_8 ) {
case V_125 :
F_119 ( V_64 >= V_58 -> V_89 ) ;
F_119 ( V_64 < V_58 -> V_92 ) ;
V_115 = V_58 -> V_108 ;
V_115 += ( V_64 - V_58 -> V_92 ) >> V_119 ;
V_222 = F_152 ( V_4 , V_58 , V_115 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_222 = F_2 () ;
else
V_222 = V_4 -> V_18 . V_20 ;
break;
case V_126 :
if ( F_31 ( V_219 , V_4 -> V_18 . V_16 ) )
goto V_123;
( void ) F_151 (
F_145 ( F_2 () , V_223 ) ,
F_142 ( V_223 ) ,
& V_4 -> V_18 . V_16 , & V_171 ) ;
V_222 = V_171 -> V_5 ;
break;
default:
F_29 () ;
}
if ( V_4 -> V_10 & V_224 ) {
V_222 = V_221 ;
if ( ! F_188 ( V_47 , V_68 , V_219 , V_220 ) )
goto V_123;
}
if ( V_219 != V_222 )
V_12 = V_222 ;
V_123:
F_97 ( V_4 ) ;
return V_12 ;
}
static void F_189 ( struct V_207 * V_208 , struct V_206 * V_210 )
{
F_18 ( L_5 , V_210 -> V_87 , V_210 -> V_65 ) ;
F_190 ( & V_210 -> V_178 , & V_208 -> V_211 ) ;
F_184 ( V_210 ) ;
}
static void F_191 ( struct V_206 * V_5 , unsigned long V_87 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_87 = V_87 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_206 * F_192 ( unsigned long V_87 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_206 * V_210 ;
struct V_1 * V_225 ;
V_210 = F_21 ( V_218 , V_39 ) ;
if ( ! V_210 )
return NULL ;
V_225 = F_70 ( V_4 ) ;
if ( F_71 ( V_225 ) ) {
F_25 ( V_218 , V_210 ) ;
return NULL ;
}
V_225 -> V_10 |= V_226 ;
F_191 ( V_210 , V_87 , V_65 , V_225 ) ;
return V_210 ;
}
static int F_193 ( struct V_207 * V_208 , unsigned long V_87 ,
unsigned long V_65 , struct V_206 * V_54 )
{
struct V_206 * V_210 ;
struct V_206 * V_227 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_228:
F_183 ( & V_208 -> V_217 ) ;
V_210 = F_176 ( V_208 , V_87 , V_65 ) ;
while ( V_210 && V_210 -> V_87 < V_65 ) {
struct V_209 * V_114 = F_194 ( & V_210 -> V_178 ) ;
if ( V_210 -> V_87 >= V_87 ) {
if ( V_210 -> V_65 <= V_65 )
F_189 ( V_208 , V_210 ) ;
else
V_210 -> V_87 = V_65 ;
} else {
if ( V_210 -> V_65 > V_65 ) {
if ( ! V_227 )
goto V_229;
* F_17 = * V_210 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_191 ( V_227 , V_65 , V_210 -> V_65 , F_17 ) ;
V_210 -> V_65 = V_87 ;
F_179 ( V_208 , V_227 ) ;
V_227 = NULL ;
F_17 = NULL ;
break;
} else
V_210 -> V_65 = V_87 ;
}
if ( ! V_114 )
break;
V_210 = F_177 ( V_114 , struct V_206 , V_178 ) ;
}
if ( V_54 )
F_179 ( V_208 , V_54 ) ;
F_61 ( & V_208 -> V_217 ) ;
V_12 = 0 ;
V_112:
if ( F_17 )
F_73 ( F_17 ) ;
if ( V_227 )
F_25 ( V_218 , V_227 ) ;
return V_12 ;
V_229:
F_61 ( & V_208 -> V_217 ) ;
V_12 = - V_40 ;
V_227 = F_21 ( V_218 , V_39 ) ;
if ( ! V_227 )
goto V_112;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_112;
goto V_228;
}
void F_195 ( struct V_207 * V_208 , struct V_1 * V_191 )
{
int V_12 ;
V_208 -> V_211 = V_230 ;
F_196 ( & V_208 -> V_217 ) ;
if ( V_191 ) {
struct V_57 V_231 ;
struct V_1 * V_54 ;
F_83 ( V_124 ) ;
if ( ! V_124 )
goto V_232;
V_54 = F_17 ( V_191 -> V_8 , V_191 -> V_10 , & V_191 -> V_30 . V_31 ) ;
if ( F_71 ( V_54 ) )
goto V_233;
F_84 ( V_47 ) ;
V_12 = F_13 ( V_54 , & V_191 -> V_30 . V_31 , V_124 ) ;
F_85 ( V_47 ) ;
if ( V_12 )
goto V_234;
memset ( & V_231 , 0 , sizeof( struct V_57 ) ) ;
V_231 . V_89 = V_235 ;
F_197 ( V_208 , & V_231 , V_54 ) ;
V_234:
F_73 ( V_54 ) ;
V_233:
F_86 ( V_124 ) ;
V_232:
F_73 ( V_191 ) ;
}
}
int F_197 ( struct V_207 * V_236 ,
struct V_57 * V_58 , struct V_1 * V_237 )
{
int V_106 ;
struct V_206 * V_54 = NULL ;
unsigned long V_238 = F_198 ( V_58 ) ;
F_18 ( L_6 ,
V_58 -> V_108 ,
V_238 , V_237 ? V_237 -> V_8 : - 1 ,
V_237 ? V_237 -> V_10 : - 1 ,
V_237 ? F_19 ( V_237 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_237 ) {
V_54 = F_192 ( V_58 -> V_108 , V_58 -> V_108 + V_238 , V_237 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_106 = F_193 ( V_236 , V_58 -> V_108 , V_58 -> V_108 + V_238 , V_54 ) ;
if ( V_106 && V_54 )
F_184 ( V_54 ) ;
return V_106 ;
}
void F_199 ( struct V_207 * V_3 )
{
struct V_206 * V_210 ;
struct V_209 * V_114 ;
if ( ! V_3 -> V_211 . V_209 )
return;
F_183 ( & V_3 -> V_217 ) ;
V_114 = F_200 ( & V_3 -> V_211 ) ;
while ( V_114 ) {
V_210 = F_177 ( V_114 , struct V_206 , V_178 ) ;
V_114 = F_194 ( & V_210 -> V_178 ) ;
F_189 ( V_3 , V_210 ) ;
}
F_61 ( & V_3 -> V_217 ) ;
}
static void T_8 F_201 ( void )
{
bool V_239 = false ;
if ( F_168 ( V_240 ) )
V_239 = true ;
if ( V_241 )
F_202 ( V_241 == 1 ) ;
if ( F_203 () > 1 && ! V_241 ) {
F_204 ( L_7
L_8
L_9 ,
V_239 ? L_10 : L_11 ) ;
F_202 ( V_239 ) ;
}
}
static int T_8 F_205 ( char * V_242 )
{
int V_12 = 0 ;
if ( ! V_242 )
goto V_123;
if ( ! strcmp ( V_242 , L_12 ) ) {
V_241 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_242 , L_13 ) ) {
V_241 = - 1 ;
V_12 = 1 ;
}
V_123:
if ( ! V_12 )
F_206 ( L_14 ) ;
return V_12 ;
}
static inline void T_8 F_201 ( void )
{
}
void T_8 F_207 ( void )
{
T_1 F_146 ;
unsigned long V_243 = 0 ;
int V_72 , V_244 = 0 ;
V_38 = F_208 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_245 , NULL ) ;
V_218 = F_208 ( L_16 ,
sizeof( struct V_206 ) ,
0 , V_245 , NULL ) ;
F_209 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_210 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_155 | V_224 ,
. V_18 = { . V_20 = V_72 , } ,
} ;
}
F_88 ( F_146 ) ;
F_211 (nid, N_MEMORY) {
unsigned long V_246 = F_212 ( V_72 ) ;
if ( V_243 < V_246 ) {
V_243 = V_246 ;
V_244 = V_72 ;
}
if ( ( V_246 << V_119 ) >= ( 16 << 20 ) )
F_89 ( V_72 , F_146 ) ;
}
if ( F_141 ( F_9 ( F_146 ) ) )
F_89 ( V_244 , F_146 ) ;
if ( F_82 ( V_125 , 0 , & F_146 ) )
F_213 ( L_17 , V_247 ) ;
F_201 () ;
}
void F_214 ( void )
{
F_82 ( V_35 , 0 , NULL ) ;
}
int F_215 ( char * V_242 , struct V_1 * * V_191 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_151 ;
T_1 V_16 ;
char * V_248 = strchr ( V_242 , ':' ) ;
char * V_10 = strchr ( V_242 , '=' ) ;
int V_106 = 1 ;
if ( V_248 ) {
* V_248 ++ = '\0' ;
if ( F_216 ( V_248 , V_16 ) )
goto V_123;
if ( ! F_217 ( V_16 , V_25 [ V_26 ] ) )
goto V_123;
} else
F_88 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_249 ; V_8 ++ ) {
if ( ! strcmp ( V_242 , V_250 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_249 )
goto V_123;
switch ( V_8 ) {
case V_27 :
if ( V_248 ) {
char * V_251 = V_248 ;
while ( isdigit ( * V_251 ) )
V_251 ++ ;
if ( * V_251 )
goto V_123;
}
break;
case V_125 :
if ( ! V_248 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_248 )
goto V_123;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_248 )
V_106 = 0 ;
goto V_123;
case V_126 :
if ( ! V_248 )
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
if ( F_71 ( V_54 ) )
goto V_123;
if ( V_8 != V_27 )
V_54 -> V_18 . V_16 = V_16 ;
else if ( V_248 )
V_54 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_54 -> V_10 |= V_19 ;
V_54 -> V_30 . V_31 = V_16 ;
V_106 = 0 ;
V_123:
if ( V_248 )
* -- V_248 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_106 )
* V_191 = V_54 ;
return V_106 ;
}
void F_218 ( char * V_252 , int V_253 , struct V_1 * V_4 )
{
char * V_3 = V_252 ;
T_1 V_16 = V_254 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_224 ) ) {
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
F_89 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_126 :
case V_125 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_124 ( 1 ) ;
snprintf ( V_3 , V_253 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_253 , L_21 , V_250 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_22 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_18 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_19 ) ;
}
if ( ! F_9 ( V_16 ) )
V_3 += F_219 ( V_3 , V_252 + V_253 - V_3 , L_23 ,
F_220 ( & V_16 ) ) ;
}
