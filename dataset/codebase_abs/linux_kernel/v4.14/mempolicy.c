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
if ( ! F_9 ( * V_16 ) ||
( V_10 & V_36 ) ||
( V_10 & V_28 ) )
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
static void F_26 ( struct V_1 * V_4 , const T_1 * V_16 )
{
}
static void F_27 ( struct V_1 * V_4 , const T_1 * V_16 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 )
F_14 ( V_15 , V_4 -> V_30 . V_31 , * V_16 ) ;
else if ( V_4 -> V_10 & V_28 )
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
else {
F_28 ( V_15 , V_4 -> V_18 . V_16 , V_4 -> V_30 . V_32 ,
* V_16 ) ;
V_4 -> V_30 . V_32 = V_15 ;
}
if ( F_9 ( V_15 ) )
V_15 = * V_16 ;
V_4 -> V_18 . V_16 = V_15 ;
}
static void F_29 ( struct V_1 * V_4 ,
const T_1 * V_16 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 ) {
int V_5 = F_11 ( V_4 -> V_30 . V_31 ) ;
if ( F_30 ( V_5 , * V_16 ) ) {
V_4 -> V_18 . V_20 = V_5 ;
V_4 -> V_10 &= ~ V_19 ;
} else
V_4 -> V_10 |= V_19 ;
} else if ( V_4 -> V_10 & V_28 ) {
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
V_4 -> V_18 . V_20 = F_11 ( V_15 ) ;
} else if ( ! ( V_4 -> V_10 & V_19 ) ) {
V_4 -> V_18 . V_20 = F_31 ( V_4 -> V_18 . V_20 ,
V_4 -> V_30 . V_32 ,
* V_16 ) ;
V_4 -> V_30 . V_32 = * V_16 ;
}
}
static void F_32 ( struct V_1 * V_4 , const T_1 * V_42 )
{
if ( ! V_4 )
return;
if ( ! F_3 ( V_4 ) &&
F_33 ( V_4 -> V_30 . V_32 , * V_42 ) )
return;
V_33 [ V_4 -> V_8 ] . F_34 ( V_4 , V_42 ) ;
}
void F_35 ( struct V_2 * V_43 , const T_1 * V_44 )
{
F_32 ( V_43 -> V_1 , V_44 ) ;
}
void F_36 ( struct V_45 * V_46 , T_1 * V_44 )
{
struct V_47 * V_48 ;
F_37 ( & V_46 -> V_49 ) ;
for ( V_48 = V_46 -> V_50 ; V_48 ; V_48 = V_48 -> V_51 )
F_32 ( V_48 -> V_52 , V_44 ) ;
F_38 ( & V_46 -> V_49 ) ;
}
static inline bool F_39 ( struct V_53 * V_53 ,
struct V_54 * V_55 )
{
int V_56 = F_40 ( V_53 ) ;
unsigned long V_10 = V_55 -> V_10 ;
return F_30 ( V_56 , * V_55 -> V_57 ) == ! ( V_10 & V_58 ) ;
}
static int F_41 ( T_2 * V_59 , T_3 * V_60 , unsigned long V_61 ,
unsigned long V_62 , struct V_63 * V_64 )
{
int V_12 = 0 ;
struct V_53 * V_53 ;
struct V_54 * V_55 = V_64 -> V_65 ;
unsigned long V_10 ;
if ( F_42 ( F_43 ( * V_59 ) ) ) {
V_12 = 1 ;
goto V_66;
}
V_53 = F_44 ( * V_59 ) ;
if ( F_45 ( V_53 ) ) {
F_46 ( V_60 ) ;
F_47 ( V_64 -> V_48 , V_59 , V_61 , false , NULL ) ;
goto V_67;
}
if ( ! F_48 () ) {
F_49 ( V_53 ) ;
F_46 ( V_60 ) ;
F_50 ( V_53 ) ;
V_12 = F_51 ( V_53 ) ;
F_52 ( V_53 ) ;
F_53 ( V_53 ) ;
goto V_67;
}
if ( ! F_39 ( V_53 , V_55 ) ) {
V_12 = 1 ;
goto V_66;
}
V_12 = 1 ;
V_10 = V_55 -> V_10 ;
if ( V_10 & ( V_68 | V_69 ) )
F_54 ( V_53 , V_55 -> V_70 , V_10 ) ;
V_66:
F_46 ( V_60 ) ;
V_67:
return V_12 ;
}
static int F_55 ( T_2 * V_59 , unsigned long V_61 ,
unsigned long V_62 , struct V_63 * V_64 )
{
struct V_47 * V_48 = V_64 -> V_48 ;
struct V_53 * V_53 ;
struct V_54 * V_55 = V_64 -> V_65 ;
unsigned long V_10 = V_55 -> V_10 ;
int V_12 ;
T_4 * V_71 ;
T_3 * V_60 ;
V_60 = F_56 ( V_59 , V_48 ) ;
if ( V_60 ) {
V_12 = F_41 ( V_59 , V_60 , V_61 , V_62 , V_64 ) ;
if ( V_12 )
return 0 ;
}
if ( F_57 ( V_59 ) )
return 0 ;
V_72:
V_71 = F_58 ( V_64 -> V_46 , V_59 , V_61 , & V_60 ) ;
for (; V_61 != V_62 ; V_71 ++ , V_61 += V_73 ) {
if ( ! F_59 ( * V_71 ) )
continue;
V_53 = F_60 ( V_48 , V_61 , * V_71 ) ;
if ( ! V_53 )
continue;
if ( F_61 ( V_53 ) )
continue;
if ( ! F_39 ( V_53 , V_55 ) )
continue;
if ( F_62 ( V_53 ) && ! F_48 () ) {
F_49 ( V_53 ) ;
F_63 ( V_71 , V_60 ) ;
F_50 ( V_53 ) ;
V_12 = F_51 ( V_53 ) ;
F_52 ( V_53 ) ;
F_53 ( V_53 ) ;
if ( V_12 ) {
V_71 = F_58 ( V_64 -> V_46 , V_59 ,
V_61 , & V_60 ) ;
continue;
}
goto V_72;
}
F_54 ( V_53 , V_55 -> V_70 , V_10 ) ;
}
F_63 ( V_71 - 1 , V_60 ) ;
F_64 () ;
return 0 ;
}
static int F_65 ( T_4 * V_71 , unsigned long V_74 ,
unsigned long V_61 , unsigned long V_62 ,
struct V_63 * V_64 )
{
#ifdef F_66
struct V_54 * V_55 = V_64 -> V_65 ;
unsigned long V_10 = V_55 -> V_10 ;
struct V_53 * V_53 ;
T_3 * V_60 ;
T_4 V_75 ;
V_60 = F_67 ( F_68 ( V_64 -> V_48 ) , V_64 -> V_46 , V_71 ) ;
V_75 = F_69 ( V_71 ) ;
if ( ! F_59 ( V_75 ) )
goto V_66;
V_53 = F_70 ( V_75 ) ;
if ( ! F_39 ( V_53 , V_55 ) )
goto V_66;
if ( V_10 & ( V_69 ) ||
( V_10 & V_68 && F_71 ( V_53 ) == 1 ) )
F_72 ( V_53 , V_55 -> V_70 ) ;
V_66:
F_46 ( V_60 ) ;
#else
F_73 () ;
#endif
return 0 ;
}
unsigned long F_74 ( struct V_47 * V_48 ,
unsigned long V_61 , unsigned long V_62 )
{
int V_76 ;
V_76 = F_75 ( V_48 , V_61 , V_62 , V_77 , 0 , 1 ) ;
if ( V_76 )
F_76 ( V_78 , V_76 ) ;
return V_76 ;
}
static unsigned long F_74 ( struct V_47 * V_48 ,
unsigned long V_61 , unsigned long V_62 )
{
return 0 ;
}
static int F_77 ( unsigned long V_79 , unsigned long V_62 ,
struct V_63 * V_64 )
{
struct V_47 * V_48 = V_64 -> V_48 ;
struct V_54 * V_55 = V_64 -> V_65 ;
unsigned long V_80 = V_48 -> V_81 ;
unsigned long V_10 = V_55 -> V_10 ;
if ( ! F_78 ( V_48 ) )
return 1 ;
if ( V_80 > V_62 )
V_80 = V_62 ;
if ( V_48 -> V_82 > V_79 )
V_79 = V_48 -> V_82 ;
if ( ! ( V_10 & V_83 ) ) {
if ( ! V_48 -> V_51 && V_48 -> V_81 < V_62 )
return - V_84 ;
if ( V_55 -> V_85 && V_55 -> V_85 -> V_81 < V_48 -> V_82 )
return - V_84 ;
}
V_55 -> V_85 = V_48 ;
if ( V_10 & V_86 ) {
if ( ! F_79 ( V_48 ) &&
( V_48 -> V_87 & ( V_88 | V_89 | V_90 ) ) &&
! ( V_48 -> V_87 & V_91 ) )
F_74 ( V_48 , V_79 , V_80 ) ;
return 1 ;
}
if ( V_10 & ( V_68 | V_69 ) )
return 0 ;
return 1 ;
}
static int
F_80 ( struct V_45 * V_46 , unsigned long V_79 , unsigned long V_62 ,
T_1 * V_16 , unsigned long V_10 ,
struct V_92 * V_70 )
{
struct V_54 V_55 = {
. V_70 = V_70 ,
. V_10 = V_10 ,
. V_57 = V_16 ,
. V_85 = NULL ,
} ;
struct V_63 V_93 = {
. V_94 = F_65 ,
. V_95 = F_55 ,
. V_96 = F_77 ,
. V_46 = V_46 ,
. V_65 = & V_55 ,
} ;
return F_81 ( V_79 , V_62 , & V_93 ) ;
}
static int F_82 ( struct V_47 * V_48 ,
struct V_1 * V_4 )
{
int V_97 ;
struct V_1 * V_98 ;
struct V_1 * V_44 ;
F_18 ( L_2 ,
V_48 -> V_82 , V_48 -> V_81 , V_48 -> V_99 ,
V_48 -> V_100 , V_48 -> V_101 ,
V_48 -> V_100 ? V_48 -> V_100 -> V_102 : NULL ) ;
V_44 = F_83 ( V_4 ) ;
if ( F_84 ( V_44 ) )
return F_85 ( V_44 ) ;
if ( V_48 -> V_100 && V_48 -> V_100 -> V_102 ) {
V_97 = V_48 -> V_100 -> V_102 ( V_48 , V_44 ) ;
if ( V_97 )
goto V_103;
}
V_98 = V_48 -> V_52 ;
V_48 -> V_52 = V_44 ;
F_86 ( V_98 ) ;
return 0 ;
V_103:
F_86 ( V_44 ) ;
return V_97 ;
}
static int F_87 ( struct V_45 * V_46 , unsigned long V_79 ,
unsigned long V_62 , struct V_1 * V_104 )
{
struct V_47 * V_105 ;
struct V_47 * V_85 ;
struct V_47 * V_48 ;
int V_97 = 0 ;
T_5 V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
V_48 = F_88 ( V_46 , V_79 ) ;
if ( ! V_48 || V_48 -> V_82 > V_79 )
return - V_84 ;
V_85 = V_48 -> V_109 ;
if ( V_79 > V_48 -> V_82 )
V_85 = V_48 ;
for (; V_48 && V_48 -> V_82 < V_62 ; V_85 = V_48 , V_48 = V_105 ) {
V_105 = V_48 -> V_51 ;
V_107 = F_89 ( V_79 , V_48 -> V_82 ) ;
V_108 = F_90 ( V_62 , V_48 -> V_81 ) ;
if ( F_91 ( F_92 ( V_48 ) , V_104 ) )
continue;
V_106 = V_48 -> V_99 +
( ( V_107 - V_48 -> V_82 ) >> V_110 ) ;
V_85 = F_93 ( V_46 , V_85 , V_107 , V_108 , V_48 -> V_87 ,
V_48 -> V_111 , V_48 -> V_101 , V_106 ,
V_104 , V_48 -> V_112 ) ;
if ( V_85 ) {
V_48 = V_85 ;
V_105 = V_48 -> V_51 ;
if ( F_91 ( F_92 ( V_48 ) , V_104 ) )
continue;
goto V_113;
}
if ( V_48 -> V_82 != V_107 ) {
V_97 = F_94 ( V_48 -> V_114 , V_48 , V_107 , 1 ) ;
if ( V_97 )
goto V_67;
}
if ( V_48 -> V_81 != V_108 ) {
V_97 = F_94 ( V_48 -> V_114 , V_48 , V_108 , 0 ) ;
if ( V_97 )
goto V_67;
}
V_113:
V_97 = F_82 ( V_48 , V_104 ) ;
if ( V_97 )
goto V_67;
}
V_67:
return V_97 ;
}
static long F_95 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_44 , * V_98 ;
F_96 ( V_115 ) ;
int V_12 ;
if ( ! V_115 )
return - V_40 ;
V_44 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_84 ( V_44 ) ) {
V_12 = F_85 ( V_44 ) ;
goto V_67;
}
F_97 ( V_116 ) ;
V_12 = F_13 ( V_44 , V_16 , V_115 ) ;
if ( V_12 ) {
F_98 ( V_116 ) ;
F_86 ( V_44 ) ;
goto V_67;
}
V_98 = V_116 -> V_1 ;
V_116 -> V_1 = V_44 ;
if ( V_44 && V_44 -> V_8 == V_117 )
V_116 -> V_118 = V_119 - 1 ;
F_98 ( V_116 ) ;
F_86 ( V_98 ) ;
V_12 = 0 ;
V_67:
F_99 ( V_115 ) ;
return V_12 ;
}
static void F_100 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_101 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_120 :
case V_117 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_102 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_73 () ;
}
}
static int F_103 ( unsigned long V_61 )
{
struct V_53 * V_3 ;
int V_97 ;
V_97 = F_104 ( V_61 & V_121 , 1 , 0 , & V_3 , NULL ) ;
if ( V_97 >= 0 ) {
V_97 = F_40 ( V_3 ) ;
F_53 ( V_3 ) ;
}
return V_97 ;
}
static long F_105 ( int * V_34 , T_1 * V_57 ,
unsigned long V_61 , unsigned long V_10 )
{
int V_97 ;
struct V_45 * V_46 = V_116 -> V_46 ;
struct V_47 * V_48 = NULL ;
struct V_1 * V_4 = V_116 -> V_1 ;
if ( V_10 &
~ ( unsigned long ) ( V_122 | V_123 | V_124 ) )
return - V_17 ;
if ( V_10 & V_124 ) {
if ( V_10 & ( V_122 | V_123 ) )
return - V_17 ;
* V_34 = 0 ;
F_97 ( V_116 ) ;
* V_57 = V_24 ;
F_98 ( V_116 ) ;
return 0 ;
}
if ( V_10 & V_123 ) {
F_106 ( & V_46 -> V_49 ) ;
V_48 = F_107 ( V_46 , V_61 , V_61 + 1 ) ;
if ( ! V_48 ) {
F_108 ( & V_46 -> V_49 ) ;
return - V_84 ;
}
if ( V_48 -> V_100 && V_48 -> V_100 -> V_125 )
V_4 = V_48 -> V_100 -> V_125 ( V_48 , V_61 ) ;
else
V_4 = V_48 -> V_52 ;
} else if ( V_61 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_122 ) {
if ( V_10 & V_123 ) {
V_97 = F_103 ( V_61 ) ;
if ( V_97 < 0 )
goto V_67;
* V_34 = V_97 ;
} else if ( V_4 == V_116 -> V_1 &&
V_4 -> V_8 == V_117 ) {
* V_34 = F_109 ( V_116 -> V_118 , V_4 -> V_18 . V_16 ) ;
} else {
V_97 = - V_17 ;
goto V_67;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
V_97 = 0 ;
if ( V_57 ) {
if ( F_3 ( V_4 ) ) {
* V_57 = V_4 -> V_30 . V_31 ;
} else {
F_97 ( V_116 ) ;
F_100 ( V_4 , V_57 ) ;
F_98 ( V_116 ) ;
}
}
V_67:
F_110 ( V_4 ) ;
if ( V_48 )
F_108 ( & V_116 -> V_46 -> V_49 ) ;
return V_97 ;
}
static void F_54 ( struct V_53 * V_53 , struct V_92 * V_70 ,
unsigned long V_10 )
{
struct V_53 * V_126 = F_111 ( V_53 ) ;
if ( ( V_10 & V_69 ) || F_71 ( V_126 ) == 1 ) {
if ( ! F_112 ( V_126 ) ) {
F_113 ( & V_126 -> V_127 , V_70 ) ;
F_114 ( F_115 ( V_126 ) ,
V_128 + F_116 ( V_126 ) ,
F_117 ( V_126 ) ) ;
}
}
}
static struct V_53 * F_118 ( struct V_53 * V_53 , unsigned long V_5 , int * * V_129 )
{
if ( F_119 ( V_53 ) )
return F_120 ( F_121 ( F_111 ( V_53 ) ) ,
V_5 ) ;
else if ( F_48 () && F_122 ( V_53 ) ) {
struct V_53 * V_130 ;
V_130 = F_123 ( V_5 ,
( V_131 | V_132 ) ,
V_133 ) ;
if ( ! V_130 )
return NULL ;
F_124 ( V_130 ) ;
return V_130 ;
} else
return F_125 ( V_5 , V_134 |
V_132 , 0 ) ;
}
static int F_126 ( struct V_45 * V_46 , int V_135 , int V_136 ,
int V_10 )
{
T_1 V_57 ;
F_127 ( V_70 ) ;
int V_97 = 0 ;
F_101 ( V_57 ) ;
F_102 ( V_135 , V_57 ) ;
F_15 ( ! ( V_10 & ( V_68 | V_69 ) ) ) ;
F_80 ( V_46 , V_46 -> V_50 -> V_82 , V_46 -> V_137 , & V_57 ,
V_10 | V_83 , & V_70 ) ;
if ( ! F_128 ( & V_70 ) ) {
V_97 = F_129 ( & V_70 , F_118 , NULL , V_136 ,
V_138 , V_139 ) ;
if ( V_97 )
F_130 ( & V_70 ) ;
}
return V_97 ;
}
int F_131 ( struct V_45 * V_46 , const T_1 * V_140 ,
const T_1 * V_141 , int V_10 )
{
int V_142 = 0 ;
int V_97 ;
T_1 V_15 ;
V_97 = F_132 () ;
if ( V_97 )
return V_97 ;
F_106 ( & V_46 -> V_49 ) ;
V_15 = * V_140 ;
while ( ! F_9 ( V_15 ) ) {
int V_143 , V_144 ;
int V_135 = V_6 ;
int V_136 = 0 ;
F_133 (s, tmp) {
if ( ( F_6 ( * V_140 ) != F_6 ( * V_141 ) ) &&
( F_30 ( V_143 , * V_141 ) ) )
continue;
V_144 = F_31 ( V_143 , * V_140 , * V_141 ) ;
if ( V_143 == V_144 )
continue;
V_135 = V_143 ;
V_136 = V_144 ;
if ( ! F_30 ( V_136 , V_15 ) )
break;
}
if ( V_135 == V_6 )
break;
F_134 ( V_135 , V_15 ) ;
V_97 = F_126 ( V_46 , V_135 , V_136 , V_10 ) ;
if ( V_97 > 0 )
V_142 += V_97 ;
if ( V_97 < 0 )
break;
}
F_108 ( & V_46 -> V_49 ) ;
if ( V_97 < 0 )
return V_97 ;
return V_142 ;
}
static struct V_53 * F_135 ( struct V_53 * V_53 , unsigned long V_79 , int * * V_129 )
{
struct V_47 * V_48 ;
unsigned long V_145 ( V_146 ) ;
V_48 = F_88 ( V_116 -> V_46 , V_79 ) ;
while ( V_48 ) {
V_146 = F_136 ( V_53 , V_48 ) ;
if ( V_146 != - V_84 )
break;
V_48 = V_48 -> V_51 ;
}
if ( F_119 ( V_53 ) ) {
F_137 ( ! V_48 ) ;
return F_138 ( V_48 , V_146 , 1 ) ;
} else if ( F_48 () && F_122 ( V_53 ) ) {
struct V_53 * V_130 ;
V_130 = F_139 ( V_131 , V_48 , V_146 ,
V_133 ) ;
if ( ! V_130 )
return NULL ;
F_124 ( V_130 ) ;
return V_130 ;
}
return F_140 ( V_134 | V_147 ,
V_48 , V_146 ) ;
}
static void F_54 ( struct V_53 * V_53 , struct V_92 * V_70 ,
unsigned long V_10 )
{
}
int F_131 ( struct V_45 * V_46 , const T_1 * V_140 ,
const T_1 * V_141 , int V_10 )
{
return - V_148 ;
}
static struct V_53 * F_135 ( struct V_53 * V_53 , unsigned long V_79 , int * * V_129 )
{
return NULL ;
}
static long F_141 ( unsigned long V_79 , unsigned long V_149 ,
unsigned short V_8 , unsigned short V_150 ,
T_1 * V_57 , unsigned long V_10 )
{
struct V_45 * V_46 = V_116 -> V_46 ;
struct V_1 * V_44 ;
unsigned long V_62 ;
int V_97 ;
F_127 ( V_70 ) ;
if ( V_10 & ~ ( unsigned long ) V_151 )
return - V_17 ;
if ( ( V_10 & V_69 ) && ! F_142 ( V_152 ) )
return - V_153 ;
if ( V_79 & ~ V_121 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_154 ;
V_149 = ( V_149 + V_73 - 1 ) & V_121 ;
V_62 = V_79 + V_149 ;
if ( V_62 < V_79 )
return - V_17 ;
if ( V_62 == V_79 )
return 0 ;
V_44 = F_17 ( V_8 , V_150 , V_57 ) ;
if ( F_84 ( V_44 ) )
return F_85 ( V_44 ) ;
if ( V_10 & V_86 )
V_44 -> V_10 |= V_155 ;
if ( ! V_44 )
V_10 |= V_83 ;
F_18 ( L_3 ,
V_79 , V_79 + V_149 , V_8 , V_150 ,
V_57 ? F_19 ( * V_57 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_68 | V_69 ) ) {
V_97 = F_132 () ;
if ( V_97 )
goto V_156;
}
{
F_96 ( V_115 ) ;
if ( V_115 ) {
F_37 ( & V_46 -> V_49 ) ;
F_97 ( V_116 ) ;
V_97 = F_13 ( V_44 , V_57 , V_115 ) ;
F_98 ( V_116 ) ;
if ( V_97 )
F_38 ( & V_46 -> V_49 ) ;
} else
V_97 = - V_40 ;
F_99 ( V_115 ) ;
}
if ( V_97 )
goto V_156;
V_97 = F_80 ( V_46 , V_79 , V_62 , V_57 ,
V_10 | V_58 , & V_70 ) ;
if ( ! V_97 )
V_97 = F_87 ( V_46 , V_79 , V_62 , V_44 ) ;
if ( ! V_97 ) {
int V_157 = 0 ;
if ( ! F_128 ( & V_70 ) ) {
F_143 ( V_10 & V_86 ) ;
V_157 = F_129 ( & V_70 , F_135 , NULL ,
V_79 , V_138 , V_158 ) ;
if ( V_157 )
F_130 ( & V_70 ) ;
}
if ( V_157 && ( V_10 & V_154 ) )
V_97 = - V_159 ;
} else
F_130 ( & V_70 ) ;
F_38 ( & V_46 -> V_49 ) ;
V_156:
F_86 ( V_44 ) ;
return V_97 ;
}
static int F_144 ( T_1 * V_16 , const unsigned long T_6 * V_57 ,
unsigned long V_160 )
{
unsigned long V_161 ;
unsigned long V_162 ;
unsigned long V_163 ;
-- V_160 ;
F_101 ( * V_16 ) ;
if ( V_160 == 0 || ! V_57 )
return 0 ;
if ( V_160 > V_73 * V_164 )
return - V_17 ;
V_162 = F_145 ( V_160 ) ;
if ( ( V_160 % V_165 ) == 0 )
V_163 = ~ 0UL ;
else
V_163 = ( 1UL << ( V_160 % V_165 ) ) - 1 ;
if ( V_162 > F_145 ( V_119 ) ) {
if ( V_162 > V_73 / sizeof( long ) )
return - V_17 ;
for ( V_161 = F_145 ( V_119 ) ; V_161 < V_162 ; V_161 ++ ) {
unsigned long V_166 ;
if ( F_146 ( V_166 , V_57 + V_161 ) )
return - V_84 ;
if ( V_161 == V_162 - 1 ) {
if ( V_166 & V_163 )
return - V_17 ;
} else if ( V_166 )
return - V_17 ;
}
V_162 = F_145 ( V_119 ) ;
V_163 = ~ 0UL ;
}
if ( F_147 ( F_19 ( * V_16 ) , V_57 , V_162 *sizeof( unsigned long ) ) )
return - V_84 ;
F_19 ( * V_16 ) [ V_162 - 1 ] &= V_163 ;
return 0 ;
}
static int F_148 ( unsigned long T_6 * V_167 , unsigned long V_160 ,
T_1 * V_16 )
{
unsigned long V_168 = F_149 ( V_160 - 1 , 64 ) / 8 ;
const int V_169 = F_145 ( V_119 ) * sizeof( long ) ;
if ( V_168 > V_169 ) {
if ( V_168 > V_73 )
return - V_17 ;
if ( F_150 ( ( char T_6 * ) V_167 + V_169 , V_168 - V_169 ) )
return - V_84 ;
V_168 = V_169 ;
}
return F_151 ( V_167 , F_19 ( * V_16 ) , V_168 ) ? - V_84 : 0 ;
}
struct V_1 * F_152 ( struct V_47 * V_48 ,
unsigned long V_61 )
{
struct V_1 * V_4 = NULL ;
if ( V_48 ) {
if ( V_48 -> V_100 && V_48 -> V_100 -> V_125 ) {
V_4 = V_48 -> V_100 -> V_125 ( V_48 , V_61 ) ;
} else if ( V_48 -> V_52 ) {
V_4 = V_48 -> V_52 ;
if ( F_153 ( V_4 ) )
F_154 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_155 ( struct V_47 * V_48 ,
unsigned long V_61 )
{
struct V_1 * V_4 = F_152 ( V_48 , V_61 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_116 ) ;
return V_4 ;
}
bool F_156 ( struct V_47 * V_48 )
{
struct V_1 * V_4 ;
if ( V_48 -> V_100 && V_48 -> V_100 -> V_125 ) {
bool V_12 = false ;
V_4 = V_48 -> V_100 -> V_125 ( V_48 , V_48 -> V_82 ) ;
if ( V_4 && ( V_4 -> V_10 & V_155 ) )
V_12 = true ;
F_110 ( V_4 ) ;
return V_12 ;
}
V_4 = V_48 -> V_52 ;
if ( ! V_4 )
V_4 = F_1 ( V_116 ) ;
return V_4 -> V_10 & V_155 ;
}
static int F_157 ( struct V_1 * V_34 , enum V_170 V_171 )
{
enum V_170 V_172 = V_173 ;
F_137 ( V_172 == V_174 ) ;
if ( ! F_158 ( V_34 -> V_18 . V_16 , V_25 [ V_175 ] ) )
V_172 = V_174 ;
return V_171 >= V_172 ;
}
static T_1 * F_159 ( T_7 V_176 , struct V_1 * V_34 )
{
if ( F_42 ( V_34 -> V_8 == V_120 ) &&
F_157 ( V_34 , F_160 ( V_176 ) ) &&
F_161 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static int F_162 ( T_7 V_176 , struct V_1 * V_34 ,
int V_177 )
{
if ( V_34 -> V_8 == V_27 && ! ( V_34 -> V_10 & V_19 ) )
V_177 = V_34 -> V_18 . V_20 ;
else {
F_143 ( V_34 -> V_8 == V_120 && ( V_176 & V_132 ) ) ;
}
return V_177 ;
}
static unsigned F_163 ( struct V_1 * V_34 )
{
unsigned V_105 ;
struct V_2 * V_178 = V_116 ;
V_105 = F_109 ( V_178 -> V_118 , V_34 -> V_18 . V_16 ) ;
if ( V_105 < V_119 )
V_178 -> V_118 = V_105 ;
return V_105 ;
}
unsigned int F_164 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_165 () ;
if ( F_166 () )
return V_5 ;
V_34 = V_116 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_117 :
return F_163 ( V_34 ) ;
case V_120 : {
struct V_179 * V_180 ;
struct V_181 * V_181 ;
enum V_170 V_182 = F_160 ( V_39 ) ;
V_181 = & F_167 ( V_5 ) -> V_183 [ V_184 ] ;
V_180 = F_168 ( V_181 , V_182 ,
& V_34 -> V_18 . V_16 ) ;
return V_180 -> V_171 ? V_180 -> V_171 -> V_5 : V_5 ;
}
default:
F_73 () ;
}
}
static unsigned F_169 ( struct V_1 * V_4 , unsigned long V_185 )
{
unsigned V_186 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_187 ;
int V_188 ;
int V_56 ;
if ( ! V_186 )
return F_2 () ;
V_187 = ( unsigned int ) V_185 % V_186 ;
V_56 = F_11 ( V_4 -> V_18 . V_16 ) ;
for ( V_188 = 0 ; V_188 < V_187 ; V_188 ++ )
V_56 = F_170 ( V_56 , V_4 -> V_18 . V_16 ) ;
return V_56 ;
}
static inline unsigned F_171 ( struct V_1 * V_4 ,
struct V_47 * V_48 , unsigned long V_61 , int V_189 )
{
if ( V_48 ) {
unsigned long V_190 ;
F_137 ( V_189 < V_110 ) ;
V_190 = V_48 -> V_99 >> ( V_189 - V_110 ) ;
V_190 += ( V_61 - V_48 -> V_82 ) >> V_189 ;
return F_169 ( V_4 , V_190 ) ;
} else
return F_163 ( V_4 ) ;
}
int F_172 ( struct V_47 * V_48 , unsigned long V_61 , T_7 V_191 ,
struct V_1 * * V_192 , T_1 * * V_193 )
{
int V_56 ;
* V_192 = F_155 ( V_48 , V_61 ) ;
* V_193 = NULL ;
if ( F_42 ( ( * V_192 ) -> V_8 == V_117 ) ) {
V_56 = F_171 ( * V_192 , V_48 , V_61 ,
F_173 ( F_68 ( V_48 ) ) ) ;
} else {
V_56 = F_162 ( V_191 , * V_192 , F_2 () ) ;
if ( ( * V_192 ) -> V_8 == V_120 )
* V_193 = & ( * V_192 ) -> V_18 . V_16 ;
}
return V_56 ;
}
bool F_174 ( T_1 * V_167 )
{
struct V_1 * V_1 ;
int V_56 ;
if ( ! ( V_167 && V_116 -> V_1 ) )
return false ;
F_97 ( V_116 ) ;
V_1 = V_116 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_56 = F_2 () ;
else
V_56 = V_1 -> V_18 . V_20 ;
F_175 ( V_167 , V_56 ) ;
break;
case V_120 :
case V_117 :
* V_167 = V_1 -> V_18 . V_16 ;
break;
default:
F_73 () ;
}
F_98 ( V_116 ) ;
return true ;
}
bool F_176 ( struct V_2 * V_43 ,
const T_1 * V_167 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_167 )
return V_12 ;
F_97 ( V_43 ) ;
V_1 = V_43 -> V_1 ;
if ( ! V_1 )
goto V_67;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_120 :
case V_117 :
V_12 = F_158 ( V_1 -> V_18 . V_16 , * V_167 ) ;
break;
default:
F_73 () ;
}
V_67:
F_98 ( V_43 ) ;
return V_12 ;
}
static struct V_53 * F_177 ( T_7 V_176 , unsigned V_194 ,
unsigned V_56 )
{
struct V_53 * V_53 ;
V_53 = F_178 ( V_176 , V_194 , V_56 ) ;
if ( V_53 && F_40 ( V_53 ) == V_56 ) {
F_179 () ;
F_180 ( F_181 ( V_53 ) , V_195 ) ;
F_182 () ;
}
return V_53 ;
}
struct V_53 *
F_183 ( T_7 V_176 , int V_194 , struct V_47 * V_48 ,
unsigned long V_61 , int V_5 , bool V_196 )
{
struct V_1 * V_4 ;
struct V_53 * V_53 ;
int V_197 ;
T_1 * V_57 ;
V_4 = F_155 ( V_48 , V_61 ) ;
if ( V_4 -> V_8 == V_117 ) {
unsigned V_56 ;
V_56 = F_171 ( V_4 , V_48 , V_61 , V_110 + V_194 ) ;
F_110 ( V_4 ) ;
V_53 = F_177 ( V_176 , V_194 , V_56 ) ;
goto V_67;
}
if ( F_42 ( F_184 ( V_198 ) && V_196 ) ) {
int V_199 = V_5 ;
if ( V_4 -> V_8 == V_27 &&
! ( V_4 -> V_10 & V_19 ) )
V_199 = V_4 -> V_18 . V_20 ;
V_57 = F_159 ( V_176 , V_4 ) ;
if ( ! V_57 || F_30 ( V_199 , * V_57 ) ) {
F_110 ( V_4 ) ;
V_53 = F_125 ( V_199 ,
V_176 | V_132 , V_194 ) ;
goto V_67;
}
}
V_57 = F_159 ( V_176 , V_4 ) ;
V_197 = F_162 ( V_176 , V_4 , V_5 ) ;
V_53 = F_185 ( V_176 , V_194 , V_197 , V_57 ) ;
F_110 ( V_4 ) ;
V_67:
return V_53 ;
}
struct V_53 * F_186 ( T_7 V_176 , unsigned V_194 )
{
struct V_1 * V_4 = & V_9 ;
struct V_53 * V_53 ;
if ( ! F_166 () && ! ( V_176 & V_132 ) )
V_4 = F_1 ( V_116 ) ;
if ( V_4 -> V_8 == V_117 )
V_53 = F_177 ( V_176 , V_194 , F_163 ( V_4 ) ) ;
else
V_53 = F_185 ( V_176 , V_194 ,
F_162 ( V_176 , V_4 , F_2 () ) ,
F_159 ( V_176 , V_4 ) ) ;
return V_53 ;
}
int F_187 ( struct V_47 * V_200 , struct V_47 * V_201 )
{
struct V_1 * V_4 = F_83 ( F_92 ( V_200 ) ) ;
if ( F_84 ( V_4 ) )
return F_85 ( V_4 ) ;
V_201 -> V_52 = V_4 ;
return 0 ;
}
struct V_1 * F_188 ( struct V_1 * V_98 )
{
struct V_1 * V_44 = F_21 ( V_38 , V_39 ) ;
if ( ! V_44 )
return F_20 ( - V_40 ) ;
if ( V_98 == V_116 -> V_1 ) {
F_97 ( V_116 ) ;
* V_44 = * V_98 ;
F_98 ( V_116 ) ;
} else
* V_44 = * V_98 ;
if ( F_189 () ) {
T_1 V_202 = V_32 ( V_116 ) ;
F_32 ( V_44 , & V_202 ) ;
}
F_22 ( & V_44 -> V_41 , 1 ) ;
return V_44 ;
}
bool F_190 ( struct V_1 * V_203 , struct V_1 * V_204 )
{
if ( ! V_203 || ! V_204 )
return false ;
if ( V_203 -> V_8 != V_204 -> V_8 )
return false ;
if ( V_203 -> V_10 != V_204 -> V_10 )
return false ;
if ( F_3 ( V_203 ) )
if ( ! F_33 ( V_203 -> V_30 . V_31 , V_204 -> V_30 . V_31 ) )
return false ;
switch ( V_203 -> V_8 ) {
case V_120 :
case V_117 :
return ! ! F_33 ( V_203 -> V_18 . V_16 , V_204 -> V_18 . V_16 ) ;
case V_27 :
return V_203 -> V_18 . V_20 == V_204 -> V_18 . V_20 ;
default:
F_73 () ;
return false ;
}
}
static struct V_205 *
F_191 ( struct V_206 * V_207 , unsigned long V_79 , unsigned long V_62 )
{
struct V_208 * V_185 = V_207 -> V_209 . V_208 ;
while ( V_185 ) {
struct V_205 * V_3 = F_192 ( V_185 , struct V_205 , V_177 ) ;
if ( V_79 >= V_3 -> V_62 )
V_185 = V_185 -> V_210 ;
else if ( V_62 <= V_3 -> V_79 )
V_185 = V_185 -> V_211 ;
else
break;
}
if ( ! V_185 )
return NULL ;
for (; ; ) {
struct V_205 * V_30 = NULL ;
struct V_208 * V_85 = F_193 ( V_185 ) ;
if ( ! V_85 )
break;
V_30 = F_192 ( V_85 , struct V_205 , V_177 ) ;
if ( V_30 -> V_62 <= V_79 )
break;
V_185 = V_85 ;
}
return F_192 ( V_185 , struct V_205 , V_177 ) ;
}
static void F_194 ( struct V_206 * V_207 , struct V_205 * V_44 )
{
struct V_208 * * V_3 = & V_207 -> V_209 . V_208 ;
struct V_208 * V_212 = NULL ;
struct V_205 * V_177 ;
while ( * V_3 ) {
V_212 = * V_3 ;
V_177 = F_192 ( V_212 , struct V_205 , V_177 ) ;
if ( V_44 -> V_79 < V_177 -> V_79 )
V_3 = & ( * V_3 ) -> V_211 ;
else if ( V_44 -> V_62 > V_177 -> V_62 )
V_3 = & ( * V_3 ) -> V_210 ;
else
F_73 () ;
}
F_195 ( & V_44 -> V_177 , V_212 , V_3 ) ;
F_196 ( & V_44 -> V_177 , & V_207 -> V_209 ) ;
F_18 ( L_4 , V_44 -> V_79 , V_44 -> V_62 ,
V_44 -> V_34 ? V_44 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_197 ( struct V_206 * V_207 , unsigned long V_213 )
{
struct V_1 * V_4 = NULL ;
struct V_205 * V_214 ;
if ( ! V_207 -> V_209 . V_208 )
return NULL ;
F_198 ( & V_207 -> V_215 ) ;
V_214 = F_191 ( V_207 , V_213 , V_213 + 1 ) ;
if ( V_214 ) {
F_154 ( V_214 -> V_34 ) ;
V_4 = V_214 -> V_34 ;
}
F_199 ( & V_207 -> V_215 ) ;
return V_4 ;
}
static void F_200 ( struct V_205 * V_185 )
{
F_86 ( V_185 -> V_34 ) ;
F_25 ( V_216 , V_185 ) ;
}
int F_201 ( struct V_53 * V_53 , struct V_47 * V_48 , unsigned long V_61 )
{
struct V_1 * V_4 ;
struct V_179 * V_180 ;
int V_217 = F_40 ( V_53 ) ;
unsigned long V_106 ;
int V_218 = F_202 () ;
int V_219 = F_203 ( V_218 ) ;
int V_220 = - 1 ;
int V_12 = - 1 ;
V_4 = F_155 ( V_48 , V_61 ) ;
if ( ! ( V_4 -> V_10 & V_155 ) )
goto V_67;
switch ( V_4 -> V_8 ) {
case V_117 :
V_106 = V_48 -> V_99 ;
V_106 += ( V_61 - V_48 -> V_82 ) >> V_110 ;
V_220 = F_169 ( V_4 , V_106 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_220 = F_2 () ;
else
V_220 = V_4 -> V_18 . V_20 ;
break;
case V_120 :
if ( F_30 ( V_217 , V_4 -> V_18 . V_16 ) )
goto V_67;
V_180 = F_168 (
F_204 ( F_2 () , V_221 ) ,
F_160 ( V_221 ) ,
& V_4 -> V_18 . V_16 ) ;
V_220 = V_180 -> V_171 -> V_5 ;
break;
default:
F_73 () ;
}
if ( V_4 -> V_10 & V_222 ) {
V_220 = V_219 ;
if ( ! F_205 ( V_116 , V_53 , V_217 , V_218 ) )
goto V_67;
}
if ( V_217 != V_220 )
V_12 = V_220 ;
V_67:
F_110 ( V_4 ) ;
return V_12 ;
}
void F_206 ( struct V_2 * V_223 )
{
struct V_1 * V_4 ;
F_97 ( V_223 ) ;
V_4 = V_223 -> V_1 ;
V_223 -> V_1 = NULL ;
F_98 ( V_223 ) ;
F_86 ( V_4 ) ;
}
static void F_207 ( struct V_206 * V_207 , struct V_205 * V_185 )
{
F_18 ( L_5 , V_185 -> V_79 , V_185 -> V_62 ) ;
F_208 ( & V_185 -> V_177 , & V_207 -> V_209 ) ;
F_200 ( V_185 ) ;
}
static void F_209 ( struct V_205 * V_5 , unsigned long V_79 ,
unsigned long V_62 , struct V_1 * V_4 )
{
V_5 -> V_79 = V_79 ;
V_5 -> V_62 = V_62 ;
V_5 -> V_34 = V_4 ;
}
static struct V_205 * F_210 ( unsigned long V_79 , unsigned long V_62 ,
struct V_1 * V_4 )
{
struct V_205 * V_185 ;
struct V_1 * V_224 ;
V_185 = F_21 ( V_216 , V_39 ) ;
if ( ! V_185 )
return NULL ;
V_224 = F_83 ( V_4 ) ;
if ( F_84 ( V_224 ) ) {
F_25 ( V_216 , V_185 ) ;
return NULL ;
}
V_224 -> V_10 |= V_225 ;
F_209 ( V_185 , V_79 , V_62 , V_224 ) ;
return V_185 ;
}
static int F_211 ( struct V_206 * V_207 , unsigned long V_79 ,
unsigned long V_62 , struct V_205 * V_44 )
{
struct V_205 * V_185 ;
struct V_205 * V_226 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_227:
F_212 ( & V_207 -> V_215 ) ;
V_185 = F_191 ( V_207 , V_79 , V_62 ) ;
while ( V_185 && V_185 -> V_79 < V_62 ) {
struct V_208 * V_105 = F_213 ( & V_185 -> V_177 ) ;
if ( V_185 -> V_79 >= V_79 ) {
if ( V_185 -> V_62 <= V_62 )
F_207 ( V_207 , V_185 ) ;
else
V_185 -> V_79 = V_62 ;
} else {
if ( V_185 -> V_62 > V_62 ) {
if ( ! V_226 )
goto V_228;
* F_17 = * V_185 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_209 ( V_226 , V_62 , V_185 -> V_62 , F_17 ) ;
V_185 -> V_62 = V_79 ;
F_194 ( V_207 , V_226 ) ;
V_226 = NULL ;
F_17 = NULL ;
break;
} else
V_185 -> V_62 = V_79 ;
}
if ( ! V_105 )
break;
V_185 = F_192 ( V_105 , struct V_205 , V_177 ) ;
}
if ( V_44 )
F_194 ( V_207 , V_44 ) ;
F_214 ( & V_207 -> V_215 ) ;
V_12 = 0 ;
V_103:
if ( F_17 )
F_86 ( F_17 ) ;
if ( V_226 )
F_25 ( V_216 , V_226 ) ;
return V_12 ;
V_228:
F_214 ( & V_207 -> V_215 ) ;
V_12 = - V_40 ;
V_226 = F_21 ( V_216 , V_39 ) ;
if ( ! V_226 )
goto V_103;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_103;
goto V_227;
}
void F_215 ( struct V_206 * V_207 , struct V_1 * V_192 )
{
int V_12 ;
V_207 -> V_209 = V_229 ;
F_216 ( & V_207 -> V_215 ) ;
if ( V_192 ) {
struct V_47 V_230 ;
struct V_1 * V_44 ;
F_96 ( V_115 ) ;
if ( ! V_115 )
goto V_231;
V_44 = F_17 ( V_192 -> V_8 , V_192 -> V_10 , & V_192 -> V_30 . V_31 ) ;
if ( F_84 ( V_44 ) )
goto V_232;
F_97 ( V_116 ) ;
V_12 = F_13 ( V_44 , & V_192 -> V_30 . V_31 , V_115 ) ;
F_98 ( V_116 ) ;
if ( V_12 )
goto V_233;
memset ( & V_230 , 0 , sizeof( struct V_47 ) ) ;
V_230 . V_81 = V_234 ;
F_217 ( V_207 , & V_230 , V_44 ) ;
V_233:
F_86 ( V_44 ) ;
V_232:
F_99 ( V_115 ) ;
V_231:
F_86 ( V_192 ) ;
}
}
int F_217 ( struct V_206 * V_235 ,
struct V_47 * V_48 , struct V_1 * V_236 )
{
int V_97 ;
struct V_205 * V_44 = NULL ;
unsigned long V_237 = F_218 ( V_48 ) ;
F_18 ( L_6 ,
V_48 -> V_99 ,
V_237 , V_236 ? V_236 -> V_8 : - 1 ,
V_236 ? V_236 -> V_10 : - 1 ,
V_236 ? F_19 ( V_236 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_236 ) {
V_44 = F_210 ( V_48 -> V_99 , V_48 -> V_99 + V_237 , V_236 ) ;
if ( ! V_44 )
return - V_40 ;
}
V_97 = F_211 ( V_235 , V_48 -> V_99 , V_48 -> V_99 + V_237 , V_44 ) ;
if ( V_97 && V_44 )
F_200 ( V_44 ) ;
return V_97 ;
}
void F_219 ( struct V_206 * V_3 )
{
struct V_205 * V_185 ;
struct V_208 * V_105 ;
if ( ! V_3 -> V_209 . V_208 )
return;
F_212 ( & V_3 -> V_215 ) ;
V_105 = F_220 ( & V_3 -> V_209 ) ;
while ( V_105 ) {
V_185 = F_192 ( V_105 , struct V_205 , V_177 ) ;
V_105 = F_213 ( & V_185 -> V_177 ) ;
F_207 ( V_3 , V_185 ) ;
}
F_214 ( & V_3 -> V_215 ) ;
}
static void T_8 F_221 ( void )
{
bool V_238 = false ;
if ( F_184 ( V_239 ) )
V_238 = true ;
if ( V_240 )
F_222 ( V_240 == 1 ) ;
if ( F_223 () > 1 && ! V_240 ) {
F_224 ( L_7 ,
V_238 ? L_8 : L_9 ) ;
F_222 ( V_238 ) ;
}
}
static int T_8 F_225 ( char * V_241 )
{
int V_12 = 0 ;
if ( ! V_241 )
goto V_67;
if ( ! strcmp ( V_241 , L_10 ) ) {
V_240 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_241 , L_11 ) ) {
V_240 = - 1 ;
V_12 = 1 ;
}
V_67:
if ( ! V_12 )
F_226 ( L_12 ) ;
return V_12 ;
}
static inline void T_8 F_221 ( void )
{
}
void T_8 F_227 ( void )
{
T_1 F_163 ;
unsigned long V_242 = 0 ;
int V_56 , V_243 = 0 ;
V_38 = F_228 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_244 , NULL ) ;
V_216 = F_228 ( L_14 ,
sizeof( struct V_205 ) ,
0 , V_244 , NULL ) ;
F_229 (nid) {
V_7 [ V_56 ] = (struct V_1 ) {
. V_41 = F_230 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_155 | V_222 ,
. V_18 = { . V_20 = V_56 , } ,
} ;
}
F_101 ( F_163 ) ;
F_231 (nid, N_MEMORY) {
unsigned long V_245 = F_232 ( V_56 ) ;
if ( V_242 < V_245 ) {
V_242 = V_245 ;
V_243 = V_56 ;
}
if ( ( V_245 << V_110 ) >= ( 16 << 20 ) )
F_102 ( V_56 , F_163 ) ;
}
if ( F_42 ( F_9 ( F_163 ) ) )
F_102 ( V_243 , F_163 ) ;
if ( F_95 ( V_117 , 0 , & F_163 ) )
F_233 ( L_15 , V_246 ) ;
F_221 () ;
}
void F_234 ( void )
{
F_95 ( V_35 , 0 , NULL ) ;
}
int F_235 ( char * V_241 , struct V_1 * * V_192 )
{
struct V_1 * V_44 = NULL ;
unsigned short V_8 ;
unsigned short V_150 ;
T_1 V_16 ;
char * V_247 = strchr ( V_241 , ':' ) ;
char * V_10 = strchr ( V_241 , '=' ) ;
int V_97 = 1 ;
if ( V_247 ) {
* V_247 ++ = '\0' ;
if ( F_236 ( V_247 , V_16 ) )
goto V_67;
if ( ! F_237 ( V_16 , V_25 [ V_26 ] ) )
goto V_67;
} else
F_101 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_248 ; V_8 ++ ) {
if ( ! strcmp ( V_241 , V_249 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_248 )
goto V_67;
switch ( V_8 ) {
case V_27 :
if ( V_247 ) {
char * V_250 = V_247 ;
while ( isdigit ( * V_250 ) )
V_250 ++ ;
if ( * V_250 )
goto V_67;
}
break;
case V_117 :
if ( ! V_247 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_247 )
goto V_67;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_247 )
V_97 = 0 ;
goto V_67;
case V_120 :
if ( ! V_247 )
goto V_67;
}
V_150 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_16 ) )
V_150 |= V_36 ;
else if ( ! strcmp ( V_10 , L_17 ) )
V_150 |= V_28 ;
else
goto V_67;
}
V_44 = F_17 ( V_8 , V_150 , & V_16 ) ;
if ( F_84 ( V_44 ) )
goto V_67;
if ( V_8 != V_27 )
V_44 -> V_18 . V_16 = V_16 ;
else if ( V_247 )
V_44 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_44 -> V_10 |= V_19 ;
V_44 -> V_30 . V_31 = V_16 ;
V_97 = 0 ;
V_67:
if ( V_247 )
* -- V_247 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_97 )
* V_192 = V_44 ;
return V_97 ;
}
void F_238 ( char * V_251 , int V_252 , struct V_1 * V_4 )
{
char * V_3 = V_251 ;
T_1 V_16 = V_253 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_222 ) ) {
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
F_102 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_120 :
case V_117 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_143 ( 1 ) ;
snprintf ( V_3 , V_252 , L_18 ) ;
return;
}
V_3 += snprintf ( V_3 , V_252 , L_19 , V_249 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_251 + V_252 - V_3 , L_20 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_251 + V_252 - V_3 , L_16 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_251 + V_252 - V_3 , L_17 ) ;
}
if ( ! F_9 ( V_16 ) )
V_3 += F_239 ( V_3 , V_251 + V_252 - V_3 , L_21 ,
F_240 ( & V_16 ) ) ;
}
