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
V_113 , V_58 -> V_121 ) ;
if ( V_95 ) {
V_58 = V_95 ;
V_114 = V_58 -> V_61 ;
if ( F_78 ( F_79 ( V_58 ) , V_113 ) )
continue;
goto V_122;
}
if ( V_58 -> V_92 != V_116 ) {
V_106 = F_81 ( V_58 -> V_123 , V_58 , V_116 , 1 ) ;
if ( V_106 )
goto V_124;
}
if ( V_58 -> V_89 != V_117 ) {
V_106 = F_81 ( V_58 -> V_123 , V_58 , V_117 , 0 ) ;
if ( V_106 )
goto V_124;
}
V_122:
V_106 = F_69 ( V_58 , V_113 ) ;
if ( V_106 )
goto V_124;
}
V_124:
return V_106 ;
}
static long F_82 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_54 , * V_107 ;
F_83 ( V_125 ) ;
int V_12 ;
if ( ! V_125 )
return - V_40 ;
V_54 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_71 ( V_54 ) ) {
V_12 = F_72 ( V_54 ) ;
goto V_124;
}
F_84 ( V_47 ) ;
V_12 = F_13 ( V_54 , V_16 , V_125 ) ;
if ( V_12 ) {
F_85 ( V_47 ) ;
F_73 ( V_54 ) ;
goto V_124;
}
V_107 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_126 &&
F_6 ( V_54 -> V_18 . V_16 ) )
V_47 -> V_48 = F_11 ( V_54 -> V_18 . V_16 ) ;
F_85 ( V_47 ) ;
F_73 ( V_107 ) ;
V_12 = 0 ;
V_124:
F_86 ( V_125 ) ;
return V_12 ;
}
static void F_87 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_88 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_127 :
case V_126 :
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
V_106 = F_91 ( V_47 , V_56 , V_64 & V_128 , 1 , 0 , 0 , & V_3 , NULL ) ;
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
~ ( unsigned long ) ( V_129 | V_130 | V_131 ) )
return - V_17 ;
if ( V_10 & V_131 ) {
if ( V_10 & ( V_129 | V_130 ) )
return - V_17 ;
* V_34 = 0 ;
F_84 ( V_47 ) ;
* V_76 = V_24 ;
F_85 ( V_47 ) ;
return 0 ;
}
if ( V_10 & V_130 ) {
F_94 ( & V_56 -> V_59 ) ;
V_58 = F_95 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_96 ( & V_56 -> V_59 ) ;
return - V_94 ;
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
V_106 = F_90 ( V_56 , V_64 ) ;
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
V_124:
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
F_99 ( & V_68 -> V_133 , V_80 ) ;
F_100 ( V_68 , V_134 +
F_101 ( V_68 ) ) ;
}
}
}
static struct V_68 * F_102 ( struct V_68 * V_68 , unsigned long V_5 , int * * V_135 )
{
if ( F_103 ( V_68 ) )
return F_104 ( F_105 ( F_106 ( V_68 ) ) ,
V_5 ) ;
else
return F_107 ( V_5 , V_136 |
V_137 , 0 ) ;
}
static int F_108 ( struct V_55 * V_56 , int V_138 , int V_139 ,
int V_10 )
{
T_1 V_76 ;
F_109 ( V_80 ) ;
int V_106 = 0 ;
F_88 ( V_76 ) ;
F_89 ( V_138 , V_76 ) ;
F_15 ( ! ( V_10 & ( V_78 | V_79 ) ) ) ;
F_67 ( V_56 , V_56 -> V_60 -> V_92 , V_56 -> V_140 , & V_76 ,
V_10 | V_93 , & V_80 ) ;
if ( ! F_110 ( & V_80 ) ) {
V_106 = F_111 ( & V_80 , F_102 , NULL , V_139 ,
V_141 , V_142 ) ;
if ( V_106 )
F_112 ( & V_80 ) ;
}
return V_106 ;
}
int F_113 ( struct V_55 * V_56 , const T_1 * V_143 ,
const T_1 * V_144 , int V_10 )
{
int V_145 = 0 ;
int V_106 ;
T_1 V_15 ;
V_106 = F_114 () ;
if ( V_106 )
return V_106 ;
F_94 ( & V_56 -> V_59 ) ;
V_15 = * V_143 ;
while ( ! F_9 ( V_15 ) ) {
int V_146 , V_147 ;
int V_138 = V_6 ;
int V_139 = 0 ;
F_115 (s, tmp) {
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
F_116 ( V_138 , V_15 ) ;
V_106 = F_108 ( V_56 , V_138 , V_139 , V_10 ) ;
if ( V_106 > 0 )
V_145 += V_106 ;
if ( V_106 < 0 )
break;
}
F_96 ( & V_56 -> V_59 ) ;
if ( V_106 < 0 )
return V_106 ;
return V_145 ;
}
static struct V_68 * F_117 ( struct V_68 * V_68 , unsigned long V_87 , int * * V_135 )
{
struct V_57 * V_58 ;
unsigned long V_148 ( V_149 ) ;
V_58 = F_75 ( V_47 -> V_56 , V_87 ) ;
while ( V_58 ) {
V_149 = F_118 ( V_68 , V_58 ) ;
if ( V_149 != - V_94 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_103 ( V_68 ) ) {
F_119 ( ! V_58 ) ;
return F_120 ( V_58 , V_149 , 1 ) ;
}
return F_121 ( V_136 , V_58 , V_149 ) ;
}
static void F_50 ( struct V_68 * V_68 , struct V_101 * V_80 ,
unsigned long V_10 )
{
}
int F_113 ( struct V_55 * V_56 , const T_1 * V_143 ,
const T_1 * V_144 , int V_10 )
{
return - V_150 ;
}
static struct V_68 * F_117 ( struct V_68 * V_68 , unsigned long V_87 , int * * V_135 )
{
return NULL ;
}
static long F_122 ( unsigned long V_87 , unsigned long V_151 ,
unsigned short V_8 , unsigned short V_152 ,
T_1 * V_76 , unsigned long V_10 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_106 ;
F_109 ( V_80 ) ;
if ( V_10 & ~ ( unsigned long ) V_153 )
return - V_17 ;
if ( ( V_10 & V_79 ) && ! F_123 ( V_154 ) )
return - V_155 ;
if ( V_87 & ~ V_128 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_100 ;
V_151 = ( V_151 + V_75 - 1 ) & V_128 ;
V_65 = V_87 + V_151 ;
if ( V_65 < V_87 )
return - V_17 ;
if ( V_65 == V_87 )
return 0 ;
V_54 = F_17 ( V_8 , V_152 , V_76 ) ;
if ( F_71 ( V_54 ) )
return F_72 ( V_54 ) ;
if ( V_10 & V_96 )
V_54 -> V_10 |= V_156 ;
if ( ! V_54 )
V_10 |= V_93 ;
F_18 ( L_3 ,
V_87 , V_87 + V_151 , V_8 , V_152 ,
V_76 ? F_19 ( * V_76 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_78 | V_79 ) ) {
V_106 = F_114 () ;
if ( V_106 )
goto V_157;
}
{
F_83 ( V_125 ) ;
if ( V_125 ) {
F_40 ( & V_56 -> V_59 ) ;
F_84 ( V_47 ) ;
V_106 = F_13 ( V_54 , V_76 , V_125 ) ;
F_85 ( V_47 ) ;
if ( V_106 )
F_41 ( & V_56 -> V_59 ) ;
} else
V_106 = - V_40 ;
F_86 ( V_125 ) ;
}
if ( V_106 )
goto V_157;
V_106 = F_67 ( V_56 , V_87 , V_65 , V_76 ,
V_10 | V_77 , & V_80 ) ;
if ( ! V_106 )
V_106 = F_74 ( V_56 , V_87 , V_65 , V_54 ) ;
if ( ! V_106 ) {
int V_158 = 0 ;
if ( ! F_110 ( & V_80 ) ) {
F_124 ( V_10 & V_96 ) ;
V_158 = F_111 ( & V_80 , F_117 , NULL ,
V_87 , V_141 , V_159 ) ;
if ( V_158 )
F_112 ( & V_80 ) ;
}
if ( V_158 && ( V_10 & V_100 ) )
V_106 = - V_160 ;
} else
F_112 ( & V_80 ) ;
F_41 ( & V_56 -> V_59 ) ;
V_157:
F_73 ( V_54 ) ;
return V_106 ;
}
static int F_125 ( T_1 * V_16 , const unsigned long T_6 * V_76 ,
unsigned long V_161 )
{
unsigned long V_162 ;
unsigned long V_163 ;
unsigned long V_164 ;
-- V_161 ;
F_88 ( * V_16 ) ;
if ( V_161 == 0 || ! V_76 )
return 0 ;
if ( V_161 > V_75 * V_165 )
return - V_17 ;
V_163 = F_126 ( V_161 ) ;
if ( ( V_161 % V_166 ) == 0 )
V_164 = ~ 0UL ;
else
V_164 = ( 1UL << ( V_161 % V_166 ) ) - 1 ;
if ( V_163 > F_126 ( V_49 ) ) {
if ( V_163 > V_75 / sizeof( long ) )
return - V_17 ;
for ( V_162 = F_126 ( V_49 ) ; V_162 < V_163 ; V_162 ++ ) {
unsigned long V_167 ;
if ( F_127 ( V_167 , V_76 + V_162 ) )
return - V_94 ;
if ( V_162 == V_163 - 1 ) {
if ( V_167 & V_164 )
return - V_17 ;
} else if ( V_167 )
return - V_17 ;
}
V_163 = F_126 ( V_49 ) ;
V_164 = ~ 0UL ;
}
if ( F_128 ( F_19 ( * V_16 ) , V_76 , V_163 *sizeof( unsigned long ) ) )
return - V_94 ;
F_19 ( * V_16 ) [ V_163 - 1 ] &= V_164 ;
return 0 ;
}
static int F_129 ( unsigned long T_6 * V_168 , unsigned long V_161 ,
T_1 * V_16 )
{
unsigned long V_169 = F_130 ( V_161 - 1 , 64 ) / 8 ;
const int V_170 = F_126 ( V_49 ) * sizeof( long ) ;
if ( V_169 > V_170 ) {
if ( V_169 > V_75 )
return - V_17 ;
if ( F_131 ( ( char T_6 * ) V_168 + V_170 , V_169 - V_170 ) )
return - V_94 ;
V_169 = V_170 ;
}
return F_132 ( V_168 , F_19 ( * V_16 ) , V_169 ) ? - V_94 : 0 ;
}
struct V_1 * F_133 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = NULL ;
if ( V_58 ) {
if ( V_58 -> V_109 && V_58 -> V_109 -> V_132 ) {
V_4 = V_58 -> V_109 -> V_132 ( V_58 , V_64 ) ;
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
if ( V_58 -> V_109 && V_58 -> V_109 -> V_132 ) {
bool V_12 = false ;
V_4 = V_58 -> V_109 -> V_132 ( V_58 , V_58 -> V_92 ) ;
if ( V_4 && ( V_4 -> V_10 & V_156 ) )
V_12 = true ;
F_97 ( V_4 ) ;
return V_12 ;
}
V_4 = V_58 -> V_62 ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 -> V_10 & V_156 ;
}
static int F_138 ( struct V_1 * V_34 , enum V_171 V_172 )
{
enum V_171 V_173 = V_174 ;
F_119 ( V_173 == V_175 ) ;
if ( ! F_139 ( V_34 -> V_18 . V_16 , V_25 [ V_176 ] ) )
V_173 = V_175 ;
return V_172 >= V_173 ;
}
static T_1 * F_140 ( T_7 V_177 , struct V_1 * V_34 )
{
if ( F_141 ( V_34 -> V_8 == V_127 ) &&
F_138 ( V_34 , F_142 ( V_177 ) ) &&
F_143 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static struct V_178 * F_144 ( T_7 V_177 , struct V_1 * V_34 ,
int V_179 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_10 & V_19 ) )
V_179 = V_34 -> V_18 . V_20 ;
break;
case V_127 :
if ( F_141 ( V_177 & V_137 ) &&
F_141 ( ! F_31 ( V_179 , V_34 -> V_18 . V_16 ) ) )
V_179 = F_11 ( V_34 -> V_18 . V_16 ) ;
break;
default:
F_29 () ;
}
return F_145 ( V_179 , V_177 ) ;
}
static unsigned F_146 ( struct V_1 * V_34 )
{
unsigned V_72 , V_114 ;
struct V_2 * V_180 = V_47 ;
V_72 = V_180 -> V_48 ;
V_114 = F_32 ( V_72 , V_34 -> V_18 . V_16 ) ;
if ( V_114 >= V_49 )
V_114 = F_11 ( V_34 -> V_18 . V_16 ) ;
if ( V_114 < V_49 )
V_180 -> V_48 = V_114 ;
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
case V_126 :
return F_146 ( V_34 ) ;
case V_127 : {
struct V_178 * V_178 ;
struct V_172 * V_172 ;
enum V_171 V_181 = F_142 ( V_39 ) ;
V_178 = & F_150 ( V_5 ) -> V_182 [ 0 ] ;
( void ) F_151 ( V_178 , V_181 ,
& V_34 -> V_18 . V_16 ,
& V_172 ) ;
return V_172 ? V_172 -> V_5 : V_5 ;
}
default:
F_29 () ;
}
}
static unsigned F_152 ( struct V_1 * V_4 ,
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
static inline unsigned F_153 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_187 )
{
if ( V_58 ) {
unsigned long V_183 ;
F_119 ( V_187 < V_119 ) ;
V_183 = V_58 -> V_108 >> ( V_187 - V_119 ) ;
V_183 += ( V_64 - V_58 -> V_92 ) >> V_187 ;
return F_152 ( V_4 , V_58 , V_183 ) ;
} else
return F_146 ( V_4 ) ;
}
int F_154 ( const T_1 * V_188 )
{
int V_30 , V_189 = V_6 ;
V_30 = F_6 ( * V_188 ) ;
if ( V_30 )
V_189 = F_155 ( V_188 -> V_190 ,
F_156 () % V_30 , V_49 ) ;
return V_189 ;
}
struct V_178 * F_157 ( struct V_57 * V_58 , unsigned long V_64 ,
T_7 V_191 , struct V_1 * * V_192 ,
T_1 * * V_193 )
{
struct V_178 * V_194 ;
* V_192 = F_136 ( V_58 , V_64 ) ;
* V_193 = NULL ;
if ( F_141 ( ( * V_192 ) -> V_8 == V_126 ) ) {
V_194 = F_145 ( F_153 ( * V_192 , V_58 , V_64 ,
F_158 ( F_56 ( V_58 ) ) ) , V_191 ) ;
} else {
V_194 = F_144 ( V_191 , * V_192 , F_2 () ) ;
if ( ( * V_192 ) -> V_8 == V_127 )
* V_193 = & ( * V_192 ) -> V_18 . V_16 ;
}
return V_194 ;
}
bool F_159 ( T_1 * V_168 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_168 && V_47 -> V_1 ) )
return false ;
F_84 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_18 . V_20 ;
F_160 ( V_168 , V_72 ) ;
break;
case V_127 :
case V_126 :
* V_168 = V_1 -> V_18 . V_16 ;
break;
default:
F_29 () ;
}
F_85 ( V_47 ) ;
return true ;
}
bool F_161 ( struct V_2 * V_53 ,
const T_1 * V_168 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_168 )
return V_12 ;
F_84 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_124;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_127 :
case V_126 :
V_12 = F_139 ( V_1 -> V_18 . V_16 , * V_168 ) ;
break;
default:
F_29 () ;
}
V_124:
F_85 ( V_53 ) ;
return V_12 ;
}
static struct V_68 * F_162 ( T_7 V_177 , unsigned V_195 ,
unsigned V_72 )
{
struct V_178 * V_194 ;
struct V_68 * V_68 ;
V_194 = F_145 ( V_72 , V_177 ) ;
V_68 = F_163 ( V_177 , V_195 , V_194 ) ;
if ( V_68 && F_164 ( V_68 ) == F_165 ( & V_194 -> V_196 [ 0 ] ) )
F_100 ( V_68 , V_197 ) ;
return V_68 ;
}
struct V_68 *
F_166 ( T_7 V_177 , int V_195 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 , bool V_198 )
{
struct V_1 * V_4 ;
struct V_68 * V_68 ;
unsigned int V_199 ;
struct V_178 * V_194 ;
T_1 * V_76 ;
V_200:
V_4 = F_136 ( V_58 , V_64 ) ;
V_199 = F_167 () ;
if ( V_4 -> V_8 == V_126 ) {
unsigned V_72 ;
V_72 = F_153 ( V_4 , V_58 , V_64 , V_119 + V_195 ) ;
F_97 ( V_4 ) ;
V_68 = F_162 ( V_177 , V_195 , V_72 ) ;
goto V_124;
}
if ( F_141 ( F_168 ( V_201 ) && V_198 ) ) {
int V_202 = V_5 ;
if ( V_4 -> V_8 == V_27 &&
! ( V_4 -> V_10 & V_19 ) )
V_202 = V_4 -> V_18 . V_20 ;
V_76 = F_140 ( V_177 , V_4 ) ;
if ( ! V_76 || F_31 ( V_202 , * V_76 ) ) {
F_97 ( V_4 ) ;
V_68 = F_107 ( V_202 ,
V_177 | V_137 , V_195 ) ;
goto V_124;
}
}
V_76 = F_140 ( V_177 , V_4 ) ;
V_194 = F_144 ( V_177 , V_4 , V_5 ) ;
F_97 ( V_4 ) ;
V_68 = F_169 ( V_177 , V_195 , V_194 , V_76 ) ;
V_124:
if ( F_141 ( ! V_68 && F_170 ( V_199 ) ) )
goto V_200;
return V_68 ;
}
struct V_68 * F_171 ( T_7 V_177 , unsigned V_195 )
{
struct V_1 * V_4 = & V_9 ;
struct V_68 * V_68 ;
unsigned int V_199 ;
if ( ! F_149 () && ! ( V_177 & V_137 ) )
V_4 = F_1 ( V_47 ) ;
V_200:
V_199 = F_167 () ;
if ( V_4 -> V_8 == V_126 )
V_68 = F_162 ( V_177 , V_195 , F_146 ( V_4 ) ) ;
else
V_68 = F_169 ( V_177 , V_195 ,
F_144 ( V_177 , V_4 , F_2 () ) ,
F_140 ( V_177 , V_4 ) ) ;
if ( F_141 ( ! V_68 && F_170 ( V_199 ) ) )
goto V_200;
return V_68 ;
}
int F_172 ( struct V_57 * V_203 , struct V_57 * V_204 )
{
struct V_1 * V_4 = F_70 ( F_79 ( V_203 ) ) ;
if ( F_71 ( V_4 ) )
return F_72 ( V_4 ) ;
V_204 -> V_62 = V_4 ;
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
T_1 V_205 = V_32 ( V_47 ) ;
if ( V_54 -> V_10 & V_51 )
F_35 ( V_54 , & V_205 , V_46 ) ;
else
F_35 ( V_54 , & V_205 , V_44 ) ;
}
F_22 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_175 ( struct V_1 * V_206 , struct V_1 * V_207 )
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
case V_127 :
case V_126 :
return ! ! F_36 ( V_206 -> V_18 . V_16 , V_207 -> V_18 . V_16 ) ;
case V_27 :
return V_206 -> V_18 . V_20 == V_207 -> V_18 . V_20 ;
default:
F_29 () ;
return false ;
}
}
static struct V_208 *
F_176 ( struct V_209 * V_210 , unsigned long V_87 , unsigned long V_65 )
{
struct V_211 * V_212 = V_210 -> V_213 . V_211 ;
while ( V_212 ) {
struct V_208 * V_3 = F_177 ( V_212 , struct V_208 , V_179 ) ;
if ( V_87 >= V_3 -> V_65 )
V_212 = V_212 -> V_214 ;
else if ( V_65 <= V_3 -> V_87 )
V_212 = V_212 -> V_215 ;
else
break;
}
if ( ! V_212 )
return NULL ;
for (; ; ) {
struct V_208 * V_30 = NULL ;
struct V_211 * V_95 = F_178 ( V_212 ) ;
if ( ! V_95 )
break;
V_30 = F_177 ( V_95 , struct V_208 , V_179 ) ;
if ( V_30 -> V_65 <= V_87 )
break;
V_212 = V_95 ;
}
return F_177 ( V_212 , struct V_208 , V_179 ) ;
}
static void F_179 ( struct V_209 * V_210 , struct V_208 * V_54 )
{
struct V_211 * * V_3 = & V_210 -> V_213 . V_211 ;
struct V_211 * V_216 = NULL ;
struct V_208 * V_179 ;
while ( * V_3 ) {
V_216 = * V_3 ;
V_179 = F_177 ( V_216 , struct V_208 , V_179 ) ;
if ( V_54 -> V_87 < V_179 -> V_87 )
V_3 = & ( * V_3 ) -> V_215 ;
else if ( V_54 -> V_65 > V_179 -> V_65 )
V_3 = & ( * V_3 ) -> V_214 ;
else
F_29 () ;
}
F_180 ( & V_54 -> V_179 , V_216 , V_3 ) ;
F_181 ( & V_54 -> V_179 , & V_210 -> V_213 ) ;
F_18 ( L_4 , V_54 -> V_87 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_182 ( struct V_209 * V_210 , unsigned long V_217 )
{
struct V_1 * V_4 = NULL ;
struct V_208 * V_218 ;
if ( ! V_210 -> V_213 . V_211 )
return NULL ;
F_183 ( & V_210 -> V_219 ) ;
V_218 = F_176 ( V_210 , V_217 , V_217 + 1 ) ;
if ( V_218 ) {
F_135 ( V_218 -> V_34 ) ;
V_4 = V_218 -> V_34 ;
}
F_61 ( & V_210 -> V_219 ) ;
return V_4 ;
}
static void F_184 ( struct V_208 * V_212 )
{
F_73 ( V_212 -> V_34 ) ;
F_25 ( V_220 , V_212 ) ;
}
int F_185 ( struct V_68 * V_68 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_172 * V_172 ;
int V_221 = F_49 ( V_68 ) ;
unsigned long V_115 ;
int V_222 = F_186 () ;
int V_223 = F_187 ( V_222 ) ;
int V_224 = - 1 ;
int V_12 = - 1 ;
F_119 ( ! V_58 ) ;
V_4 = F_136 ( V_58 , V_64 ) ;
if ( ! ( V_4 -> V_10 & V_156 ) )
goto V_124;
switch ( V_4 -> V_8 ) {
case V_126 :
F_119 ( V_64 >= V_58 -> V_89 ) ;
F_119 ( V_64 < V_58 -> V_92 ) ;
V_115 = V_58 -> V_108 ;
V_115 += ( V_64 - V_58 -> V_92 ) >> V_119 ;
V_224 = F_152 ( V_4 , V_58 , V_115 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_224 = F_2 () ;
else
V_224 = V_4 -> V_18 . V_20 ;
break;
case V_127 :
if ( F_31 ( V_221 , V_4 -> V_18 . V_16 ) )
goto V_124;
( void ) F_151 (
F_145 ( F_2 () , V_225 ) ,
F_142 ( V_225 ) ,
& V_4 -> V_18 . V_16 , & V_172 ) ;
V_224 = V_172 -> V_5 ;
break;
default:
F_29 () ;
}
if ( V_4 -> V_10 & V_226 ) {
V_224 = V_223 ;
if ( ! F_188 ( V_47 , V_68 , V_221 , V_222 ) )
goto V_124;
}
if ( V_221 != V_224 )
V_12 = V_224 ;
V_124:
F_97 ( V_4 ) ;
return V_12 ;
}
static void F_189 ( struct V_209 * V_210 , struct V_208 * V_212 )
{
F_18 ( L_5 , V_212 -> V_87 , V_212 -> V_65 ) ;
F_190 ( & V_212 -> V_179 , & V_210 -> V_213 ) ;
F_184 ( V_212 ) ;
}
static void F_191 ( struct V_208 * V_5 , unsigned long V_87 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_87 = V_87 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_208 * F_192 ( unsigned long V_87 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_208 * V_212 ;
struct V_1 * V_227 ;
V_212 = F_21 ( V_220 , V_39 ) ;
if ( ! V_212 )
return NULL ;
V_227 = F_70 ( V_4 ) ;
if ( F_71 ( V_227 ) ) {
F_25 ( V_220 , V_212 ) ;
return NULL ;
}
V_227 -> V_10 |= V_228 ;
F_191 ( V_212 , V_87 , V_65 , V_227 ) ;
return V_212 ;
}
static int F_193 ( struct V_209 * V_210 , unsigned long V_87 ,
unsigned long V_65 , struct V_208 * V_54 )
{
struct V_208 * V_212 ;
struct V_208 * V_229 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_230:
F_183 ( & V_210 -> V_219 ) ;
V_212 = F_176 ( V_210 , V_87 , V_65 ) ;
while ( V_212 && V_212 -> V_87 < V_65 ) {
struct V_211 * V_114 = F_194 ( & V_212 -> V_179 ) ;
if ( V_212 -> V_87 >= V_87 ) {
if ( V_212 -> V_65 <= V_65 )
F_189 ( V_210 , V_212 ) ;
else
V_212 -> V_87 = V_65 ;
} else {
if ( V_212 -> V_65 > V_65 ) {
if ( ! V_229 )
goto V_231;
* F_17 = * V_212 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_191 ( V_229 , V_65 , V_212 -> V_65 , F_17 ) ;
V_212 -> V_65 = V_87 ;
F_179 ( V_210 , V_229 ) ;
V_229 = NULL ;
F_17 = NULL ;
break;
} else
V_212 -> V_65 = V_87 ;
}
if ( ! V_114 )
break;
V_212 = F_177 ( V_114 , struct V_208 , V_179 ) ;
}
if ( V_54 )
F_179 ( V_210 , V_54 ) ;
F_61 ( & V_210 -> V_219 ) ;
V_12 = 0 ;
V_112:
if ( F_17 )
F_73 ( F_17 ) ;
if ( V_229 )
F_25 ( V_220 , V_229 ) ;
return V_12 ;
V_231:
F_61 ( & V_210 -> V_219 ) ;
V_12 = - V_40 ;
V_229 = F_21 ( V_220 , V_39 ) ;
if ( ! V_229 )
goto V_112;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_112;
goto V_230;
}
void F_195 ( struct V_209 * V_210 , struct V_1 * V_192 )
{
int V_12 ;
V_210 -> V_213 = V_232 ;
F_196 ( & V_210 -> V_219 ) ;
if ( V_192 ) {
struct V_57 V_233 ;
struct V_1 * V_54 ;
F_83 ( V_125 ) ;
if ( ! V_125 )
goto V_234;
V_54 = F_17 ( V_192 -> V_8 , V_192 -> V_10 , & V_192 -> V_30 . V_31 ) ;
if ( F_71 ( V_54 ) )
goto V_235;
F_84 ( V_47 ) ;
V_12 = F_13 ( V_54 , & V_192 -> V_30 . V_31 , V_125 ) ;
F_85 ( V_47 ) ;
if ( V_12 )
goto V_236;
memset ( & V_233 , 0 , sizeof( struct V_57 ) ) ;
V_233 . V_89 = V_237 ;
F_197 ( V_210 , & V_233 , V_54 ) ;
V_236:
F_73 ( V_54 ) ;
V_235:
F_86 ( V_125 ) ;
V_234:
F_73 ( V_192 ) ;
}
}
int F_197 ( struct V_209 * V_238 ,
struct V_57 * V_58 , struct V_1 * V_239 )
{
int V_106 ;
struct V_208 * V_54 = NULL ;
unsigned long V_240 = F_198 ( V_58 ) ;
F_18 ( L_6 ,
V_58 -> V_108 ,
V_240 , V_239 ? V_239 -> V_8 : - 1 ,
V_239 ? V_239 -> V_10 : - 1 ,
V_239 ? F_19 ( V_239 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_239 ) {
V_54 = F_192 ( V_58 -> V_108 , V_58 -> V_108 + V_240 , V_239 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_106 = F_193 ( V_238 , V_58 -> V_108 , V_58 -> V_108 + V_240 , V_54 ) ;
if ( V_106 && V_54 )
F_184 ( V_54 ) ;
return V_106 ;
}
void F_199 ( struct V_209 * V_3 )
{
struct V_208 * V_212 ;
struct V_211 * V_114 ;
if ( ! V_3 -> V_213 . V_211 )
return;
F_183 ( & V_3 -> V_219 ) ;
V_114 = F_200 ( & V_3 -> V_213 ) ;
while ( V_114 ) {
V_212 = F_177 ( V_114 , struct V_208 , V_179 ) ;
V_114 = F_194 ( & V_212 -> V_179 ) ;
F_189 ( V_3 , V_212 ) ;
}
F_61 ( & V_3 -> V_219 ) ;
}
static void T_8 F_201 ( void )
{
bool V_241 = false ;
if ( F_168 ( V_242 ) )
V_241 = true ;
if ( V_243 )
F_202 ( V_243 == 1 ) ;
if ( F_203 () > 1 && ! V_243 ) {
F_204 ( L_7
L_8
L_9 ,
V_241 ? L_10 : L_11 ) ;
F_202 ( V_241 ) ;
}
}
static int T_8 F_205 ( char * V_244 )
{
int V_12 = 0 ;
if ( ! V_244 )
goto V_124;
if ( ! strcmp ( V_244 , L_12 ) ) {
V_243 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_244 , L_13 ) ) {
V_243 = - 1 ;
V_12 = 1 ;
}
V_124:
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
unsigned long V_245 = 0 ;
int V_72 , V_246 = 0 ;
V_38 = F_208 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_247 , NULL ) ;
V_220 = F_208 ( L_16 ,
sizeof( struct V_208 ) ,
0 , V_247 , NULL ) ;
F_209 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_210 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_156 | V_226 ,
. V_18 = { . V_20 = V_72 , } ,
} ;
}
F_88 ( F_146 ) ;
F_211 (nid, N_MEMORY) {
unsigned long V_248 = F_212 ( V_72 ) ;
if ( V_245 < V_248 ) {
V_245 = V_248 ;
V_246 = V_72 ;
}
if ( ( V_248 << V_119 ) >= ( 16 << 20 ) )
F_89 ( V_72 , F_146 ) ;
}
if ( F_141 ( F_9 ( F_146 ) ) )
F_89 ( V_246 , F_146 ) ;
if ( F_82 ( V_126 , 0 , & F_146 ) )
F_213 ( L_17 , V_249 ) ;
F_201 () ;
}
void F_214 ( void )
{
F_82 ( V_35 , 0 , NULL ) ;
}
int F_215 ( char * V_244 , struct V_1 * * V_192 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_152 ;
T_1 V_16 ;
char * V_250 = strchr ( V_244 , ':' ) ;
char * V_10 = strchr ( V_244 , '=' ) ;
int V_106 = 1 ;
if ( V_250 ) {
* V_250 ++ = '\0' ;
if ( F_216 ( V_250 , V_16 ) )
goto V_124;
if ( ! F_217 ( V_16 , V_25 [ V_26 ] ) )
goto V_124;
} else
F_88 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_251 ; V_8 ++ ) {
if ( ! strcmp ( V_244 , V_252 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_251 )
goto V_124;
switch ( V_8 ) {
case V_27 :
if ( V_250 ) {
char * V_253 = V_250 ;
while ( isdigit ( * V_253 ) )
V_253 ++ ;
if ( * V_253 )
goto V_124;
}
break;
case V_126 :
if ( ! V_250 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_250 )
goto V_124;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_250 )
V_106 = 0 ;
goto V_124;
case V_127 :
if ( ! V_250 )
goto V_124;
}
V_152 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_18 ) )
V_152 |= V_36 ;
else if ( ! strcmp ( V_10 , L_19 ) )
V_152 |= V_28 ;
else
goto V_124;
}
V_54 = F_17 ( V_8 , V_152 , & V_16 ) ;
if ( F_71 ( V_54 ) )
goto V_124;
if ( V_8 != V_27 )
V_54 -> V_18 . V_16 = V_16 ;
else if ( V_250 )
V_54 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_54 -> V_10 |= V_19 ;
V_54 -> V_30 . V_31 = V_16 ;
V_106 = 0 ;
V_124:
if ( V_250 )
* -- V_250 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_106 )
* V_192 = V_54 ;
return V_106 ;
}
void F_218 ( char * V_254 , int V_255 , struct V_1 * V_4 )
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
F_89 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_127 :
case V_126 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_124 ( 1 ) ;
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
V_3 += F_219 ( V_3 , V_254 + V_255 - V_3 , L_23 ,
F_220 ( & V_16 ) ) ;
}
