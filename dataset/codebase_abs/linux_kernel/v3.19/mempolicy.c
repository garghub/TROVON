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
static int F_42 ( struct V_57 * V_58 , T_2 * V_63 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_16 , unsigned long V_10 ,
void * V_66 )
{
T_3 * V_67 ;
T_3 * V_68 ;
T_4 * V_69 ;
V_67 = V_68 = F_43 ( V_58 -> V_70 , V_63 , V_64 , & V_69 ) ;
do {
struct V_71 * V_71 ;
int V_72 ;
if ( ! F_44 ( * V_68 ) )
continue;
V_71 = F_45 ( V_58 , V_64 , * V_68 ) ;
if ( ! V_71 )
continue;
if ( F_46 ( V_71 ) )
continue;
V_72 = F_47 ( V_71 ) ;
if ( F_31 ( V_72 , * V_16 ) == ! ! ( V_10 & V_73 ) )
continue;
if ( V_10 & ( V_74 | V_75 ) )
F_48 ( V_71 , V_66 , V_10 ) ;
else
break;
} while ( V_68 ++ , V_64 += V_76 , V_64 != V_65 );
F_49 ( V_67 , V_69 ) ;
return V_64 != V_65 ;
}
static void F_50 ( struct V_57 * V_58 ,
T_2 * V_63 , const T_1 * V_16 , unsigned long V_10 ,
void * V_66 )
{
#ifdef F_51
int V_72 ;
struct V_71 * V_71 ;
T_4 * V_69 ;
T_3 V_77 ;
V_69 = F_52 ( F_53 ( V_58 ) , V_58 -> V_70 , ( T_3 * ) V_63 ) ;
V_77 = F_54 ( ( T_3 * ) V_63 ) ;
if ( ! F_44 ( V_77 ) )
goto V_78;
V_71 = F_55 ( V_77 ) ;
V_72 = F_47 ( V_71 ) ;
if ( F_31 ( V_72 , * V_16 ) == ! ! ( V_10 & V_73 ) )
goto V_78;
if ( V_10 & ( V_75 ) ||
( V_10 & V_74 && F_56 ( V_71 ) == 1 ) )
F_57 ( V_71 , V_66 ) ;
V_78:
F_58 ( V_69 ) ;
#else
F_29 () ;
#endif
}
static inline int F_59 ( struct V_57 * V_58 , T_5 * V_79 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_16 , unsigned long V_10 ,
void * V_66 )
{
T_2 * V_63 ;
unsigned long V_80 ;
V_63 = F_60 ( V_79 , V_64 ) ;
do {
V_80 = F_61 ( V_64 , V_65 ) ;
if ( ! F_62 ( * V_63 ) )
continue;
if ( F_63 ( * V_63 ) && F_64 ( V_58 ) ) {
F_50 ( V_58 , V_63 , V_16 ,
V_10 , V_66 ) ;
continue;
}
F_65 ( V_58 , V_64 , V_63 ) ;
if ( F_66 ( V_63 ) )
continue;
if ( F_42 ( V_58 , V_63 , V_64 , V_80 , V_16 ,
V_10 , V_66 ) )
return - V_81 ;
} while ( V_63 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_67 ( struct V_57 * V_58 , T_6 * V_82 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_16 , unsigned long V_10 ,
void * V_66 )
{
T_5 * V_79 ;
unsigned long V_80 ;
V_79 = F_68 ( V_82 , V_64 ) ;
do {
V_80 = F_69 ( V_64 , V_65 ) ;
if ( F_70 ( * V_79 ) && F_64 ( V_58 ) )
continue;
if ( F_71 ( V_79 ) )
continue;
if ( F_59 ( V_58 , V_79 , V_64 , V_80 , V_16 ,
V_10 , V_66 ) )
return - V_81 ;
} while ( V_79 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_72 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_16 , unsigned long V_10 ,
void * V_66 )
{
T_6 * V_82 ;
unsigned long V_80 ;
V_82 = F_73 ( V_58 -> V_70 , V_64 ) ;
do {
V_80 = F_74 ( V_64 , V_65 ) ;
if ( F_75 ( V_82 ) )
continue;
if ( F_67 ( V_58 , V_82 , V_64 , V_80 , V_16 ,
V_10 , V_66 ) )
return - V_81 ;
} while ( V_82 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
unsigned long F_76 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_83 ;
V_83 = F_77 ( V_58 , V_64 , V_65 , V_58 -> V_84 , 0 , 1 ) ;
if ( V_83 )
F_78 ( V_85 , V_83 ) ;
return V_83 ;
}
static unsigned long F_76 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static int
F_79 ( struct V_55 * V_56 , unsigned long V_86 , unsigned long V_65 ,
const T_1 * V_16 , unsigned long V_10 , void * V_66 )
{
int V_87 = 0 ;
struct V_57 * V_58 , * V_88 ;
V_58 = F_80 ( V_56 , V_86 ) ;
if ( ! V_58 )
return - V_89 ;
V_88 = NULL ;
for (; V_58 && V_58 -> V_90 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_91 = V_58 -> V_92 ;
if ( V_91 > V_65 )
V_91 = V_65 ;
if ( V_58 -> V_90 > V_86 )
V_86 = V_58 -> V_90 ;
if ( ! ( V_10 & V_93 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_92 < V_65 )
return - V_89 ;
if ( V_88 && V_88 -> V_92 < V_58 -> V_90 )
return - V_89 ;
}
if ( V_10 & V_94 ) {
if ( V_58 -> V_95 & ( V_96 | V_97 | V_98 ) )
F_76 ( V_58 , V_86 , V_91 ) ;
goto V_80;
}
if ( ( V_10 & V_99 ) ||
( ( V_10 & ( V_74 | V_75 ) ) &&
F_81 ( V_58 ) ) ) {
V_87 = F_72 ( V_58 , V_86 , V_91 , V_16 ,
V_10 , V_66 ) ;
if ( V_87 )
break;
}
V_80:
V_88 = V_58 ;
}
return V_87 ;
}
static int F_82 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_87 ;
struct V_1 * V_100 ;
struct V_1 * V_54 ;
F_18 ( L_2 ,
V_58 -> V_90 , V_58 -> V_92 , V_58 -> V_101 ,
V_58 -> V_102 , V_58 -> V_103 ,
V_58 -> V_102 ? V_58 -> V_102 -> V_104 : NULL ) ;
V_54 = F_83 ( V_4 ) ;
if ( F_84 ( V_54 ) )
return F_85 ( V_54 ) ;
if ( V_58 -> V_102 && V_58 -> V_102 -> V_104 ) {
V_87 = V_58 -> V_102 -> V_104 ( V_58 , V_54 ) ;
if ( V_87 )
goto V_105;
}
V_100 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_86 ( V_100 ) ;
return 0 ;
V_105:
F_86 ( V_54 ) ;
return V_87 ;
}
static int F_87 ( struct V_55 * V_56 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_106 )
{
struct V_57 * V_80 ;
struct V_57 * V_88 ;
struct V_57 * V_58 ;
int V_87 = 0 ;
T_7 V_107 ;
unsigned long V_108 ;
unsigned long V_109 ;
V_58 = F_80 ( V_56 , V_86 ) ;
if ( ! V_58 || V_58 -> V_90 > V_86 )
return - V_89 ;
V_88 = V_58 -> V_110 ;
if ( V_86 > V_58 -> V_90 )
V_88 = V_58 ;
for (; V_58 && V_58 -> V_90 < V_65 ; V_88 = V_58 , V_58 = V_80 ) {
V_80 = V_58 -> V_61 ;
V_108 = F_88 ( V_86 , V_58 -> V_90 ) ;
V_109 = F_89 ( V_65 , V_58 -> V_92 ) ;
if ( F_90 ( F_91 ( V_58 ) , V_106 ) )
continue;
V_107 = V_58 -> V_101 +
( ( V_108 - V_58 -> V_90 ) >> V_111 ) ;
V_88 = F_92 ( V_56 , V_88 , V_108 , V_109 , V_58 -> V_95 ,
V_58 -> V_112 , V_58 -> V_103 , V_107 ,
V_106 ) ;
if ( V_88 ) {
V_58 = V_88 ;
V_80 = V_58 -> V_61 ;
if ( F_90 ( F_91 ( V_58 ) , V_106 ) )
continue;
goto V_113;
}
if ( V_58 -> V_90 != V_108 ) {
V_87 = F_93 ( V_58 -> V_70 , V_58 , V_108 , 1 ) ;
if ( V_87 )
goto V_114;
}
if ( V_58 -> V_92 != V_109 ) {
V_87 = F_93 ( V_58 -> V_70 , V_58 , V_109 , 0 ) ;
if ( V_87 )
goto V_114;
}
V_113:
V_87 = F_82 ( V_58 , V_106 ) ;
if ( V_87 )
goto V_114;
}
V_114:
return V_87 ;
}
static long F_94 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_54 , * V_100 ;
F_95 ( V_115 ) ;
int V_12 ;
if ( ! V_115 )
return - V_40 ;
V_54 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_84 ( V_54 ) ) {
V_12 = F_85 ( V_54 ) ;
goto V_114;
}
F_96 ( V_47 ) ;
V_12 = F_13 ( V_54 , V_16 , V_115 ) ;
if ( V_12 ) {
F_97 ( V_47 ) ;
F_86 ( V_54 ) ;
goto V_114;
}
V_100 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_116 &&
F_6 ( V_54 -> V_18 . V_16 ) )
V_47 -> V_48 = F_11 ( V_54 -> V_18 . V_16 ) ;
F_97 ( V_47 ) ;
F_86 ( V_100 ) ;
V_12 = 0 ;
V_114:
F_98 ( V_115 ) ;
return V_12 ;
}
static void F_99 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_100 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_117 :
case V_116 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_101 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_29 () ;
}
}
static int F_102 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_71 * V_3 ;
int V_87 ;
V_87 = F_103 ( V_47 , V_56 , V_64 & V_118 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_87 >= 0 ) {
V_87 = F_47 ( V_3 ) ;
F_104 ( V_3 ) ;
}
return V_87 ;
}
static long F_105 ( int * V_34 , T_1 * V_119 ,
unsigned long V_64 , unsigned long V_10 )
{
int V_87 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_10 &
~ ( unsigned long ) ( V_120 | V_121 | V_122 ) )
return - V_17 ;
if ( V_10 & V_122 ) {
if ( V_10 & ( V_120 | V_121 ) )
return - V_17 ;
* V_34 = 0 ;
F_96 ( V_47 ) ;
* V_119 = V_24 ;
F_97 ( V_47 ) ;
return 0 ;
}
if ( V_10 & V_121 ) {
F_106 ( & V_56 -> V_59 ) ;
V_58 = F_107 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_108 ( & V_56 -> V_59 ) ;
return - V_89 ;
}
if ( V_58 -> V_102 && V_58 -> V_102 -> V_123 )
V_4 = V_58 -> V_102 -> V_123 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_120 ) {
if ( V_10 & V_121 ) {
V_87 = F_102 ( V_56 , V_64 ) ;
if ( V_87 < 0 )
goto V_114;
* V_34 = V_87 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_116 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_87 = - V_17 ;
goto V_114;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
if ( V_58 ) {
F_108 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_87 = 0 ;
if ( V_119 ) {
if ( F_3 ( V_4 ) ) {
* V_119 = V_4 -> V_30 . V_31 ;
} else {
F_96 ( V_47 ) ;
F_99 ( V_4 , V_119 ) ;
F_97 ( V_47 ) ;
}
}
V_114:
F_109 ( V_4 ) ;
if ( V_58 )
F_108 ( & V_47 -> V_56 -> V_59 ) ;
return V_87 ;
}
static void F_48 ( struct V_71 * V_71 , struct V_124 * V_125 ,
unsigned long V_10 )
{
if ( ( V_10 & V_75 ) || F_56 ( V_71 ) == 1 ) {
if ( ! F_110 ( V_71 ) ) {
F_111 ( & V_71 -> V_126 , V_125 ) ;
F_112 ( V_71 , V_127 +
F_113 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_114 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_128 )
{
if ( F_115 ( V_71 ) )
return F_116 ( F_117 ( F_118 ( V_71 ) ) ,
V_5 ) ;
else
return F_119 ( V_5 , V_129 , 0 ) ;
}
static int F_120 ( struct V_55 * V_56 , int V_130 , int V_131 ,
int V_10 )
{
T_1 V_119 ;
F_121 ( V_125 ) ;
int V_87 = 0 ;
F_100 ( V_119 ) ;
F_101 ( V_130 , V_119 ) ;
F_15 ( ! ( V_10 & ( V_74 | V_75 ) ) ) ;
F_79 ( V_56 , V_56 -> V_60 -> V_90 , V_56 -> V_132 , & V_119 ,
V_10 | V_93 , & V_125 ) ;
if ( ! F_122 ( & V_125 ) ) {
V_87 = F_123 ( & V_125 , F_114 , NULL , V_131 ,
V_133 , V_134 ) ;
if ( V_87 )
F_124 ( & V_125 ) ;
}
return V_87 ;
}
int F_125 ( struct V_55 * V_56 , const T_1 * V_135 ,
const T_1 * V_136 , int V_10 )
{
int V_137 = 0 ;
int V_87 ;
T_1 V_15 ;
V_87 = F_126 () ;
if ( V_87 )
return V_87 ;
F_106 ( & V_56 -> V_59 ) ;
V_15 = * V_135 ;
while ( ! F_9 ( V_15 ) ) {
int V_138 , V_139 ;
int V_130 = V_6 ;
int V_131 = 0 ;
F_127 (s, tmp) {
if ( ( F_6 ( * V_135 ) != F_6 ( * V_136 ) ) &&
( F_31 ( V_138 , * V_136 ) ) )
continue;
V_139 = F_34 ( V_138 , * V_135 , * V_136 ) ;
if ( V_138 == V_139 )
continue;
V_130 = V_138 ;
V_131 = V_139 ;
if ( ! F_31 ( V_131 , V_15 ) )
break;
}
if ( V_130 == V_6 )
break;
F_128 ( V_130 , V_15 ) ;
V_87 = F_120 ( V_56 , V_130 , V_131 , V_10 ) ;
if ( V_87 > 0 )
V_137 += V_87 ;
if ( V_87 < 0 )
break;
}
F_108 ( & V_56 -> V_59 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_137 ;
}
static struct V_71 * F_129 ( struct V_71 * V_71 , unsigned long V_86 , int * * V_128 )
{
struct V_57 * V_58 ;
unsigned long V_140 ( V_141 ) ;
V_58 = F_80 ( V_47 -> V_56 , V_86 ) ;
while ( V_58 ) {
V_141 = F_130 ( V_71 , V_58 ) ;
if ( V_141 != - V_89 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_115 ( V_71 ) ) {
F_131 ( ! V_58 ) ;
return F_132 ( V_58 , V_141 , 1 ) ;
}
return F_133 ( V_129 , V_58 , V_141 ) ;
}
static void F_48 ( struct V_71 * V_71 , struct V_124 * V_125 ,
unsigned long V_10 )
{
}
int F_125 ( struct V_55 * V_56 , const T_1 * V_135 ,
const T_1 * V_136 , int V_10 )
{
return - V_142 ;
}
static struct V_71 * F_129 ( struct V_71 * V_71 , unsigned long V_86 , int * * V_128 )
{
return NULL ;
}
static long F_134 ( unsigned long V_86 , unsigned long V_143 ,
unsigned short V_8 , unsigned short V_144 ,
T_1 * V_119 , unsigned long V_10 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_87 ;
F_121 ( V_125 ) ;
if ( V_10 & ~ ( unsigned long ) V_145 )
return - V_17 ;
if ( ( V_10 & V_75 ) && ! F_135 ( V_146 ) )
return - V_147 ;
if ( V_86 & ~ V_118 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_99 ;
V_143 = ( V_143 + V_76 - 1 ) & V_118 ;
V_65 = V_86 + V_143 ;
if ( V_65 < V_86 )
return - V_17 ;
if ( V_65 == V_86 )
return 0 ;
V_54 = F_17 ( V_8 , V_144 , V_119 ) ;
if ( F_84 ( V_54 ) )
return F_85 ( V_54 ) ;
if ( V_10 & V_94 )
V_54 -> V_10 |= V_148 ;
if ( ! V_54 )
V_10 |= V_93 ;
F_18 ( L_3 ,
V_86 , V_86 + V_143 , V_8 , V_144 ,
V_119 ? F_19 ( * V_119 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_74 | V_75 ) ) {
V_87 = F_126 () ;
if ( V_87 )
goto V_149;
}
{
F_95 ( V_115 ) ;
if ( V_115 ) {
F_40 ( & V_56 -> V_59 ) ;
F_96 ( V_47 ) ;
V_87 = F_13 ( V_54 , V_119 , V_115 ) ;
F_97 ( V_47 ) ;
if ( V_87 )
F_41 ( & V_56 -> V_59 ) ;
} else
V_87 = - V_40 ;
F_98 ( V_115 ) ;
}
if ( V_87 )
goto V_149;
V_87 = F_79 ( V_56 , V_86 , V_65 , V_119 ,
V_10 | V_73 , & V_125 ) ;
if ( ! V_87 )
V_87 = F_87 ( V_56 , V_86 , V_65 , V_54 ) ;
if ( ! V_87 ) {
int V_150 = 0 ;
if ( ! F_122 ( & V_125 ) ) {
F_136 ( V_10 & V_94 ) ;
V_150 = F_123 ( & V_125 , F_129 , NULL ,
V_86 , V_133 , V_151 ) ;
if ( V_150 )
F_124 ( & V_125 ) ;
}
if ( V_150 && ( V_10 & V_99 ) )
V_87 = - V_81 ;
} else
F_124 ( & V_125 ) ;
F_41 ( & V_56 -> V_59 ) ;
V_149:
F_86 ( V_54 ) ;
return V_87 ;
}
static int F_137 ( T_1 * V_16 , const unsigned long T_8 * V_119 ,
unsigned long V_152 )
{
unsigned long V_153 ;
unsigned long V_154 ;
unsigned long V_155 ;
-- V_152 ;
F_100 ( * V_16 ) ;
if ( V_152 == 0 || ! V_119 )
return 0 ;
if ( V_152 > V_76 * V_156 )
return - V_17 ;
V_154 = F_138 ( V_152 ) ;
if ( ( V_152 % V_157 ) == 0 )
V_155 = ~ 0UL ;
else
V_155 = ( 1UL << ( V_152 % V_157 ) ) - 1 ;
if ( V_154 > F_138 ( V_49 ) ) {
if ( V_154 > V_76 / sizeof( long ) )
return - V_17 ;
for ( V_153 = F_138 ( V_49 ) ; V_153 < V_154 ; V_153 ++ ) {
unsigned long V_158 ;
if ( F_139 ( V_158 , V_119 + V_153 ) )
return - V_89 ;
if ( V_153 == V_154 - 1 ) {
if ( V_158 & V_155 )
return - V_17 ;
} else if ( V_158 )
return - V_17 ;
}
V_154 = F_138 ( V_49 ) ;
V_155 = ~ 0UL ;
}
if ( F_140 ( F_19 ( * V_16 ) , V_119 , V_154 *sizeof( unsigned long ) ) )
return - V_89 ;
F_19 ( * V_16 ) [ V_154 - 1 ] &= V_155 ;
return 0 ;
}
static int F_141 ( unsigned long T_8 * V_159 , unsigned long V_152 ,
T_1 * V_16 )
{
unsigned long V_160 = F_142 ( V_152 - 1 , 64 ) / 8 ;
const int V_161 = F_138 ( V_49 ) * sizeof( long ) ;
if ( V_160 > V_161 ) {
if ( V_160 > V_76 )
return - V_17 ;
if ( F_143 ( ( char T_8 * ) V_159 + V_161 , V_160 - V_161 ) )
return - V_89 ;
V_160 = V_161 ;
}
return F_144 ( V_159 , F_19 ( * V_16 ) , V_160 ) ? - V_89 : 0 ;
}
struct V_1 * F_145 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = NULL ;
if ( V_58 ) {
if ( V_58 -> V_102 && V_58 -> V_102 -> V_123 ) {
V_4 = V_58 -> V_102 -> V_123 ( V_58 , V_64 ) ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_146 ( V_4 ) )
F_147 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_148 ( struct V_57 * V_58 ,
unsigned long V_64 )
{
struct V_1 * V_4 = F_145 ( V_58 , V_64 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 ;
}
bool F_149 ( struct V_57 * V_58 )
{
struct V_1 * V_4 ;
if ( V_58 -> V_102 && V_58 -> V_102 -> V_123 ) {
bool V_12 = false ;
V_4 = V_58 -> V_102 -> V_123 ( V_58 , V_58 -> V_90 ) ;
if ( V_4 && ( V_4 -> V_10 & V_148 ) )
V_12 = true ;
F_109 ( V_4 ) ;
return V_12 ;
}
V_4 = V_58 -> V_62 ;
if ( ! V_4 )
V_4 = F_1 ( V_47 ) ;
return V_4 -> V_10 & V_148 ;
}
static int F_150 ( struct V_1 * V_34 , enum V_162 V_163 )
{
enum V_162 V_164 = V_165 ;
F_131 ( V_164 == V_166 ) ;
if ( ! F_151 ( V_34 -> V_18 . V_16 , V_25 [ V_167 ] ) )
V_164 = V_166 ;
return V_163 >= V_164 ;
}
static T_1 * F_152 ( T_9 V_168 , struct V_1 * V_34 )
{
if ( F_153 ( V_34 -> V_8 == V_117 ) &&
F_150 ( V_34 , F_154 ( V_168 ) ) &&
F_155 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static struct V_169 * F_156 ( T_9 V_168 , struct V_1 * V_34 ,
int V_170 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_10 & V_19 ) )
V_170 = V_34 -> V_18 . V_20 ;
break;
case V_117 :
if ( F_153 ( V_168 & V_171 ) &&
F_153 ( ! F_31 ( V_170 , V_34 -> V_18 . V_16 ) ) )
V_170 = F_11 ( V_34 -> V_18 . V_16 ) ;
break;
default:
F_29 () ;
}
return F_157 ( V_170 , V_168 ) ;
}
static unsigned F_158 ( struct V_1 * V_34 )
{
unsigned V_72 , V_80 ;
struct V_2 * V_172 = V_47 ;
V_72 = V_172 -> V_48 ;
V_80 = F_32 ( V_72 , V_34 -> V_18 . V_16 ) ;
if ( V_80 >= V_49 )
V_80 = F_11 ( V_34 -> V_18 . V_16 ) ;
if ( V_80 < V_49 )
V_172 -> V_48 = V_80 ;
return V_72 ;
}
unsigned int F_159 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_160 () ;
if ( F_161 () )
return V_5 ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_116 :
return F_158 ( V_34 ) ;
case V_117 : {
struct V_169 * V_169 ;
struct V_163 * V_163 ;
enum V_162 V_173 = F_154 ( V_39 ) ;
V_169 = & F_162 ( V_5 ) -> V_174 [ 0 ] ;
( void ) F_163 ( V_169 , V_173 ,
& V_34 -> V_18 . V_16 ,
& V_163 ) ;
return V_163 ? V_163 -> V_5 : V_5 ;
}
default:
F_29 () ;
}
}
static unsigned F_164 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_175 )
{
unsigned V_176 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_177 ;
int V_178 ;
int V_72 = V_6 ;
if ( ! V_176 )
return F_2 () ;
V_177 = ( unsigned int ) V_175 % V_176 ;
V_178 = 0 ;
do {
V_72 = F_32 ( V_72 , V_4 -> V_18 . V_16 ) ;
V_178 ++ ;
} while ( V_178 <= V_177 );
return V_72 ;
}
static inline unsigned F_165 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_179 )
{
if ( V_58 ) {
unsigned long V_175 ;
F_131 ( V_179 < V_111 ) ;
V_175 = V_58 -> V_101 >> ( V_179 - V_111 ) ;
V_175 += ( V_64 - V_58 -> V_90 ) >> V_179 ;
return F_164 ( V_4 , V_58 , V_175 ) ;
} else
return F_158 ( V_4 ) ;
}
int F_166 ( const T_1 * V_180 )
{
int V_30 , V_181 = V_6 ;
V_30 = F_6 ( * V_180 ) ;
if ( V_30 )
V_181 = F_167 ( V_180 -> V_182 ,
F_168 () % V_30 , V_49 ) ;
return V_181 ;
}
struct V_169 * F_169 ( struct V_57 * V_58 , unsigned long V_64 ,
T_9 V_183 , struct V_1 * * V_184 ,
T_1 * * V_185 )
{
struct V_169 * V_186 ;
* V_184 = F_148 ( V_58 , V_64 ) ;
* V_185 = NULL ;
if ( F_153 ( ( * V_184 ) -> V_8 == V_116 ) ) {
V_186 = F_157 ( F_165 ( * V_184 , V_58 , V_64 ,
F_170 ( F_53 ( V_58 ) ) ) , V_183 ) ;
} else {
V_186 = F_156 ( V_183 , * V_184 , F_2 () ) ;
if ( ( * V_184 ) -> V_8 == V_117 )
* V_185 = & ( * V_184 ) -> V_18 . V_16 ;
}
return V_186 ;
}
bool F_171 ( T_1 * V_159 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_159 && V_47 -> V_1 ) )
return false ;
F_96 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_18 . V_20 ;
F_172 ( V_159 , V_72 ) ;
break;
case V_117 :
case V_116 :
* V_159 = V_1 -> V_18 . V_16 ;
break;
default:
F_29 () ;
}
F_97 ( V_47 ) ;
return true ;
}
bool F_173 ( struct V_2 * V_53 ,
const T_1 * V_159 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_159 )
return V_12 ;
F_96 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_114;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_117 :
case V_116 :
V_12 = F_151 ( V_1 -> V_18 . V_16 , * V_159 ) ;
break;
default:
F_29 () ;
}
V_114:
F_97 ( V_53 ) ;
return V_12 ;
}
static struct V_71 * F_174 ( T_9 V_168 , unsigned V_187 ,
unsigned V_72 )
{
struct V_169 * V_186 ;
struct V_71 * V_71 ;
V_186 = F_157 ( V_72 , V_168 ) ;
V_71 = F_175 ( V_168 , V_187 , V_186 ) ;
if ( V_71 && F_176 ( V_71 ) == F_177 ( & V_186 -> V_188 [ 0 ] ) )
F_112 ( V_71 , V_189 ) ;
return V_71 ;
}
struct V_71 *
F_178 ( T_9 V_168 , int V_187 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_190 ;
V_191:
V_4 = F_148 ( V_58 , V_64 ) ;
V_190 = F_179 () ;
if ( F_153 ( V_4 -> V_8 == V_116 ) ) {
unsigned V_72 ;
V_72 = F_165 ( V_4 , V_58 , V_64 , V_111 + V_187 ) ;
F_109 ( V_4 ) ;
V_71 = F_174 ( V_168 , V_187 , V_72 ) ;
if ( F_153 ( ! V_71 && F_180 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
V_71 = F_181 ( V_168 , V_187 ,
F_156 ( V_168 , V_4 , V_5 ) ,
F_152 ( V_168 , V_4 ) ) ;
F_109 ( V_4 ) ;
if ( F_153 ( ! V_71 && F_180 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
struct V_71 * F_182 ( T_9 V_168 , unsigned V_187 )
{
struct V_1 * V_4 = & V_9 ;
struct V_71 * V_71 ;
unsigned int V_190 ;
if ( ! F_161 () && ! ( V_168 & V_171 ) )
V_4 = F_1 ( V_47 ) ;
V_191:
V_190 = F_179 () ;
if ( V_4 -> V_8 == V_116 )
V_71 = F_174 ( V_168 , V_187 , F_158 ( V_4 ) ) ;
else
V_71 = F_181 ( V_168 , V_187 ,
F_156 ( V_168 , V_4 , F_2 () ) ,
F_152 ( V_168 , V_4 ) ) ;
if ( F_153 ( ! V_71 && F_180 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
int F_183 ( struct V_57 * V_192 , struct V_57 * V_193 )
{
struct V_1 * V_4 = F_83 ( F_91 ( V_192 ) ) ;
if ( F_84 ( V_4 ) )
return F_85 ( V_4 ) ;
V_193 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_184 ( struct V_1 * V_100 )
{
struct V_1 * V_54 = F_21 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_20 ( - V_40 ) ;
if ( V_100 == V_47 -> V_1 ) {
F_96 ( V_47 ) ;
* V_54 = * V_100 ;
F_97 ( V_47 ) ;
} else
* V_54 = * V_100 ;
if ( F_185 () ) {
T_1 V_194 = V_32 ( V_47 ) ;
if ( V_54 -> V_10 & V_51 )
F_35 ( V_54 , & V_194 , V_46 ) ;
else
F_35 ( V_54 , & V_194 , V_44 ) ;
}
F_22 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_186 ( struct V_1 * V_195 , struct V_1 * V_196 )
{
if ( ! V_195 || ! V_196 )
return false ;
if ( V_195 -> V_8 != V_196 -> V_8 )
return false ;
if ( V_195 -> V_10 != V_196 -> V_10 )
return false ;
if ( F_3 ( V_195 ) )
if ( ! F_36 ( V_195 -> V_30 . V_31 , V_196 -> V_30 . V_31 ) )
return false ;
switch ( V_195 -> V_8 ) {
case V_117 :
case V_116 :
return ! ! F_36 ( V_195 -> V_18 . V_16 , V_196 -> V_18 . V_16 ) ;
case V_27 :
return V_195 -> V_18 . V_20 == V_196 -> V_18 . V_20 ;
default:
F_29 () ;
return false ;
}
}
static struct V_197 *
F_187 ( struct V_198 * V_199 , unsigned long V_86 , unsigned long V_65 )
{
struct V_200 * V_201 = V_199 -> V_202 . V_200 ;
while ( V_201 ) {
struct V_197 * V_3 = F_188 ( V_201 , struct V_197 , V_170 ) ;
if ( V_86 >= V_3 -> V_65 )
V_201 = V_201 -> V_203 ;
else if ( V_65 <= V_3 -> V_86 )
V_201 = V_201 -> V_204 ;
else
break;
}
if ( ! V_201 )
return NULL ;
for (; ; ) {
struct V_197 * V_30 = NULL ;
struct V_200 * V_88 = F_189 ( V_201 ) ;
if ( ! V_88 )
break;
V_30 = F_188 ( V_88 , struct V_197 , V_170 ) ;
if ( V_30 -> V_65 <= V_86 )
break;
V_201 = V_88 ;
}
return F_188 ( V_201 , struct V_197 , V_170 ) ;
}
static void F_190 ( struct V_198 * V_199 , struct V_197 * V_54 )
{
struct V_200 * * V_3 = & V_199 -> V_202 . V_200 ;
struct V_200 * V_205 = NULL ;
struct V_197 * V_170 ;
while ( * V_3 ) {
V_205 = * V_3 ;
V_170 = F_188 ( V_205 , struct V_197 , V_170 ) ;
if ( V_54 -> V_86 < V_170 -> V_86 )
V_3 = & ( * V_3 ) -> V_204 ;
else if ( V_54 -> V_65 > V_170 -> V_65 )
V_3 = & ( * V_3 ) -> V_203 ;
else
F_29 () ;
}
F_191 ( & V_54 -> V_170 , V_205 , V_3 ) ;
F_192 ( & V_54 -> V_170 , & V_199 -> V_202 ) ;
F_18 ( L_4 , V_54 -> V_86 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_193 ( struct V_198 * V_199 , unsigned long V_206 )
{
struct V_1 * V_4 = NULL ;
struct V_197 * V_207 ;
if ( ! V_199 -> V_202 . V_200 )
return NULL ;
F_194 ( & V_199 -> V_208 ) ;
V_207 = F_187 ( V_199 , V_206 , V_206 + 1 ) ;
if ( V_207 ) {
F_147 ( V_207 -> V_34 ) ;
V_4 = V_207 -> V_34 ;
}
F_58 ( & V_199 -> V_208 ) ;
return V_4 ;
}
static void F_195 ( struct V_197 * V_201 )
{
F_86 ( V_201 -> V_34 ) ;
F_25 ( V_209 , V_201 ) ;
}
int F_196 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_163 * V_163 ;
int V_210 = F_47 ( V_71 ) ;
unsigned long V_107 ;
int V_211 = F_197 () ;
int V_212 = F_198 ( V_211 ) ;
int V_213 = - 1 ;
int V_12 = - 1 ;
F_131 ( ! V_58 ) ;
V_4 = F_148 ( V_58 , V_64 ) ;
if ( ! ( V_4 -> V_10 & V_148 ) )
goto V_114;
switch ( V_4 -> V_8 ) {
case V_116 :
F_131 ( V_64 >= V_58 -> V_92 ) ;
F_131 ( V_64 < V_58 -> V_90 ) ;
V_107 = V_58 -> V_101 ;
V_107 += ( V_64 - V_58 -> V_90 ) >> V_111 ;
V_213 = F_164 ( V_4 , V_58 , V_107 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_213 = F_2 () ;
else
V_213 = V_4 -> V_18 . V_20 ;
break;
case V_117 :
if ( F_31 ( V_210 , V_4 -> V_18 . V_16 ) )
goto V_114;
( void ) F_163 (
F_157 ( F_2 () , V_214 ) ,
F_154 ( V_214 ) ,
& V_4 -> V_18 . V_16 , & V_163 ) ;
V_213 = V_163 -> V_5 ;
break;
default:
F_29 () ;
}
if ( V_4 -> V_10 & V_215 ) {
V_213 = V_212 ;
if ( ! F_199 ( V_47 , V_71 , V_210 , V_211 ) )
goto V_114;
}
if ( V_210 != V_213 )
V_12 = V_213 ;
V_114:
F_109 ( V_4 ) ;
return V_12 ;
}
static void F_200 ( struct V_198 * V_199 , struct V_197 * V_201 )
{
F_18 ( L_5 , V_201 -> V_86 , V_201 -> V_65 ) ;
F_201 ( & V_201 -> V_170 , & V_199 -> V_202 ) ;
F_195 ( V_201 ) ;
}
static void F_202 ( struct V_197 * V_5 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_86 = V_86 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_197 * F_203 ( unsigned long V_86 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_197 * V_201 ;
struct V_1 * V_216 ;
V_201 = F_21 ( V_209 , V_39 ) ;
if ( ! V_201 )
return NULL ;
V_216 = F_83 ( V_4 ) ;
if ( F_84 ( V_216 ) ) {
F_25 ( V_209 , V_201 ) ;
return NULL ;
}
V_216 -> V_10 |= V_217 ;
F_202 ( V_201 , V_86 , V_65 , V_216 ) ;
return V_201 ;
}
static int F_204 ( struct V_198 * V_199 , unsigned long V_86 ,
unsigned long V_65 , struct V_197 * V_54 )
{
struct V_197 * V_201 ;
struct V_197 * V_218 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_219:
F_194 ( & V_199 -> V_208 ) ;
V_201 = F_187 ( V_199 , V_86 , V_65 ) ;
while ( V_201 && V_201 -> V_86 < V_65 ) {
struct V_200 * V_80 = F_205 ( & V_201 -> V_170 ) ;
if ( V_201 -> V_86 >= V_86 ) {
if ( V_201 -> V_65 <= V_65 )
F_200 ( V_199 , V_201 ) ;
else
V_201 -> V_86 = V_65 ;
} else {
if ( V_201 -> V_65 > V_65 ) {
if ( ! V_218 )
goto V_220;
* F_17 = * V_201 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_202 ( V_218 , V_65 , V_201 -> V_65 , F_17 ) ;
V_201 -> V_65 = V_86 ;
F_190 ( V_199 , V_218 ) ;
V_218 = NULL ;
F_17 = NULL ;
break;
} else
V_201 -> V_65 = V_86 ;
}
if ( ! V_80 )
break;
V_201 = F_188 ( V_80 , struct V_197 , V_170 ) ;
}
if ( V_54 )
F_190 ( V_199 , V_54 ) ;
F_58 ( & V_199 -> V_208 ) ;
V_12 = 0 ;
V_105:
if ( F_17 )
F_86 ( F_17 ) ;
if ( V_218 )
F_25 ( V_209 , V_218 ) ;
return V_12 ;
V_220:
F_58 ( & V_199 -> V_208 ) ;
V_12 = - V_40 ;
V_218 = F_21 ( V_209 , V_39 ) ;
if ( ! V_218 )
goto V_105;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_105;
goto V_219;
}
void F_206 ( struct V_198 * V_199 , struct V_1 * V_184 )
{
int V_12 ;
V_199 -> V_202 = V_221 ;
F_207 ( & V_199 -> V_208 ) ;
if ( V_184 ) {
struct V_57 V_222 ;
struct V_1 * V_54 ;
F_95 ( V_115 ) ;
if ( ! V_115 )
goto V_223;
V_54 = F_17 ( V_184 -> V_8 , V_184 -> V_10 , & V_184 -> V_30 . V_31 ) ;
if ( F_84 ( V_54 ) )
goto V_224;
F_96 ( V_47 ) ;
V_12 = F_13 ( V_54 , & V_184 -> V_30 . V_31 , V_115 ) ;
F_97 ( V_47 ) ;
if ( V_12 )
goto V_225;
memset ( & V_222 , 0 , sizeof( struct V_57 ) ) ;
V_222 . V_92 = V_226 ;
F_208 ( V_199 , & V_222 , V_54 ) ;
V_225:
F_86 ( V_54 ) ;
V_224:
F_98 ( V_115 ) ;
V_223:
F_86 ( V_184 ) ;
}
}
int F_208 ( struct V_198 * V_227 ,
struct V_57 * V_58 , struct V_1 * V_228 )
{
int V_87 ;
struct V_197 * V_54 = NULL ;
unsigned long V_229 = F_209 ( V_58 ) ;
F_18 ( L_6 ,
V_58 -> V_101 ,
V_229 , V_228 ? V_228 -> V_8 : - 1 ,
V_228 ? V_228 -> V_10 : - 1 ,
V_228 ? F_19 ( V_228 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_228 ) {
V_54 = F_203 ( V_58 -> V_101 , V_58 -> V_101 + V_229 , V_228 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_87 = F_204 ( V_227 , V_58 -> V_101 , V_58 -> V_101 + V_229 , V_54 ) ;
if ( V_87 && V_54 )
F_195 ( V_54 ) ;
return V_87 ;
}
void F_210 ( struct V_198 * V_3 )
{
struct V_197 * V_201 ;
struct V_200 * V_80 ;
if ( ! V_3 -> V_202 . V_200 )
return;
F_194 ( & V_3 -> V_208 ) ;
V_80 = F_211 ( & V_3 -> V_202 ) ;
while ( V_80 ) {
V_201 = F_188 ( V_80 , struct V_197 , V_170 ) ;
V_80 = F_205 ( & V_201 -> V_170 ) ;
F_200 ( V_3 , V_201 ) ;
}
F_58 ( & V_3 -> V_208 ) ;
}
static void T_10 F_212 ( void )
{
bool V_230 = false ;
if ( F_213 ( V_231 ) )
V_230 = true ;
if ( V_232 )
F_214 ( V_232 == 1 ) ;
if ( V_233 > 1 && ! V_232 ) {
F_215 ( L_7
L_8
L_9 ,
V_230 ? L_10 : L_11 ) ;
F_214 ( V_230 ) ;
}
}
static int T_10 F_216 ( char * V_234 )
{
int V_12 = 0 ;
if ( ! V_234 )
goto V_114;
if ( ! strcmp ( V_234 , L_12 ) ) {
V_232 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_234 , L_13 ) ) {
V_232 = - 1 ;
V_12 = 1 ;
}
V_114:
if ( ! V_12 )
F_217 ( L_14 ) ;
return V_12 ;
}
static inline void T_10 F_212 ( void )
{
}
void T_10 F_218 ( void )
{
T_1 F_158 ;
unsigned long V_235 = 0 ;
int V_72 , V_236 = 0 ;
V_38 = F_219 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_237 , NULL ) ;
V_209 = F_219 ( L_16 ,
sizeof( struct V_197 ) ,
0 , V_237 , NULL ) ;
F_220 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_221 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_148 | V_215 ,
. V_18 = { . V_20 = V_72 , } ,
} ;
}
F_100 ( F_158 ) ;
F_222 (nid, N_MEMORY) {
unsigned long V_238 = F_223 ( V_72 ) ;
if ( V_235 < V_238 ) {
V_235 = V_238 ;
V_236 = V_72 ;
}
if ( ( V_238 << V_111 ) >= ( 16 << 20 ) )
F_101 ( V_72 , F_158 ) ;
}
if ( F_153 ( F_9 ( F_158 ) ) )
F_101 ( V_236 , F_158 ) ;
if ( F_94 ( V_116 , 0 , & F_158 ) )
F_224 ( L_17 , V_239 ) ;
F_212 () ;
}
void F_225 ( void )
{
F_94 ( V_35 , 0 , NULL ) ;
}
int F_226 ( char * V_234 , struct V_1 * * V_184 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_144 ;
T_1 V_16 ;
char * V_240 = strchr ( V_234 , ':' ) ;
char * V_10 = strchr ( V_234 , '=' ) ;
int V_87 = 1 ;
if ( V_240 ) {
* V_240 ++ = '\0' ;
if ( F_227 ( V_240 , V_16 ) )
goto V_114;
if ( ! F_228 ( V_16 , V_25 [ V_26 ] ) )
goto V_114;
} else
F_100 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_241 ; V_8 ++ ) {
if ( ! strcmp ( V_234 , V_242 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_241 )
goto V_114;
switch ( V_8 ) {
case V_27 :
if ( V_240 ) {
char * V_243 = V_240 ;
while ( isdigit ( * V_243 ) )
V_243 ++ ;
if ( * V_243 )
goto V_114;
}
break;
case V_116 :
if ( ! V_240 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_240 )
goto V_114;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_240 )
V_87 = 0 ;
goto V_114;
case V_117 :
if ( ! V_240 )
goto V_114;
}
V_144 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_18 ) )
V_144 |= V_36 ;
else if ( ! strcmp ( V_10 , L_19 ) )
V_144 |= V_28 ;
else
goto V_114;
}
V_54 = F_17 ( V_8 , V_144 , & V_16 ) ;
if ( F_84 ( V_54 ) )
goto V_114;
if ( V_8 != V_27 )
V_54 -> V_18 . V_16 = V_16 ;
else if ( V_240 )
V_54 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_54 -> V_10 |= V_19 ;
V_54 -> V_30 . V_31 = V_16 ;
V_87 = 0 ;
V_114:
if ( V_240 )
* -- V_240 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_87 )
* V_184 = V_54 ;
return V_87 ;
}
void F_229 ( char * V_244 , int V_245 , struct V_1 * V_4 )
{
char * V_3 = V_244 ;
T_1 V_16 = V_246 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_215 ) ) {
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
F_101 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_117 :
case V_116 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_136 ( 1 ) ;
snprintf ( V_3 , V_245 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_245 , L_21 , V_242 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_22 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_18 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_19 ) ;
}
if ( ! F_9 ( V_16 ) ) {
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_23 ) ;
V_3 += F_230 ( V_3 , V_244 + V_245 - V_3 , V_16 ) ;
}
}
