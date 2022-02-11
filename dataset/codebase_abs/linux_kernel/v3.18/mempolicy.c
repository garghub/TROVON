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
static int F_3 ( const T_1 * V_10 )
{
return F_4 ( * V_10 , V_11 [ V_12 ] ) ;
}
static inline int F_5 ( const struct V_1 * V_4 )
{
return V_4 -> V_13 & V_14 ;
}
static void F_6 ( T_1 * V_15 , const T_1 * V_16 ,
const T_1 * V_17 )
{
T_1 V_18 ;
F_7 ( V_18 , * V_16 , F_8 ( * V_17 ) ) ;
F_9 ( * V_15 , V_18 , * V_17 ) ;
}
static int F_10 ( struct V_1 * V_4 , const T_1 * V_19 )
{
if ( F_11 ( * V_19 ) )
return - V_20 ;
V_4 -> V_21 . V_19 = * V_19 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , const T_1 * V_19 )
{
if ( ! V_19 )
V_4 -> V_13 |= V_22 ;
else if ( F_11 ( * V_19 ) )
return - V_20 ;
else
V_4 -> V_21 . V_23 = F_13 ( * V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_4 , const T_1 * V_19 )
{
if ( ! F_3 ( V_19 ) )
return - V_20 ;
V_4 -> V_21 . V_19 = * V_19 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_4 ,
const T_1 * V_19 , struct V_24 * V_25 )
{
int V_15 ;
if ( V_4 == NULL )
return 0 ;
F_16 ( V_25 -> V_26 ,
V_27 , V_11 [ V_12 ] ) ;
F_17 ( ! V_19 ) ;
if ( V_4 -> V_8 == V_28 && F_11 ( * V_19 ) )
V_19 = NULL ;
else {
if ( V_4 -> V_13 & V_29 )
F_6 ( & V_25 -> V_30 , V_19 , & V_25 -> V_26 ) ;
else
F_16 ( V_25 -> V_30 , * V_19 , V_25 -> V_26 ) ;
if ( F_5 ( V_4 ) )
V_4 -> V_31 . V_32 = * V_19 ;
else
V_4 -> V_31 . V_33 =
V_27 ;
}
if ( V_19 )
V_15 = V_34 [ V_4 -> V_8 ] . F_18 ( V_4 , & V_25 -> V_30 ) ;
else
V_15 = V_34 [ V_4 -> V_8 ] . F_18 ( V_4 , NULL ) ;
return V_15 ;
}
static struct V_1 * F_19 ( unsigned short V_8 , unsigned short V_13 ,
T_1 * V_19 )
{
struct V_1 * V_35 ;
F_20 ( L_1 ,
V_8 , V_13 , V_19 ? F_21 ( * V_19 ) [ 0 ] : V_6 ) ;
if ( V_8 == V_36 ) {
if ( V_19 && ! F_11 ( * V_19 ) )
return F_22 ( - V_20 ) ;
return NULL ;
}
F_17 ( ! V_19 ) ;
if ( V_8 == V_28 ) {
if ( F_11 ( * V_19 ) ) {
if ( ( ( V_13 & V_37 ) ||
( V_13 & V_29 ) ) )
return F_22 ( - V_20 ) ;
}
} else if ( V_8 == V_38 ) {
if ( ! F_11 ( * V_19 ) )
return F_22 ( - V_20 ) ;
V_8 = V_28 ;
} else if ( F_11 ( * V_19 ) )
return F_22 ( - V_20 ) ;
V_35 = F_23 ( V_39 , V_40 ) ;
if ( ! V_35 )
return F_22 ( - V_41 ) ;
F_24 ( & V_35 -> V_42 , 1 ) ;
V_35 -> V_8 = V_8 ;
V_35 -> V_13 = V_13 ;
return V_35 ;
}
void F_25 ( struct V_1 * V_3 )
{
if ( ! F_26 ( & V_3 -> V_42 ) )
return;
F_27 ( V_39 , V_3 ) ;
}
static void F_28 ( struct V_1 * V_4 , const T_1 * V_19 ,
enum V_43 V_44 )
{
}
static void F_29 ( struct V_1 * V_4 , const T_1 * V_19 ,
enum V_43 V_44 )
{
T_1 V_18 ;
if ( V_4 -> V_13 & V_37 )
F_16 ( V_18 , V_4 -> V_31 . V_32 , * V_19 ) ;
else if ( V_4 -> V_13 & V_29 )
F_6 ( & V_18 , & V_4 -> V_31 . V_32 , V_19 ) ;
else {
if ( V_44 == V_45 || V_44 == V_46 ) {
F_30 ( V_18 , V_4 -> V_21 . V_19 ,
V_4 -> V_31 . V_33 , * V_19 ) ;
V_4 -> V_31 . V_33 = V_44 ? V_18 : * V_19 ;
} else if ( V_44 == V_47 ) {
V_18 = V_4 -> V_31 . V_33 ;
V_4 -> V_31 . V_33 = * V_19 ;
} else
F_31 () ;
}
if ( F_11 ( V_18 ) )
V_18 = * V_19 ;
if ( V_44 == V_46 )
F_32 ( V_4 -> V_21 . V_19 , V_4 -> V_21 . V_19 , V_18 ) ;
else if ( V_44 == V_45 || V_44 == V_47 )
V_4 -> V_21 . V_19 = V_18 ;
else
F_31 () ;
if ( ! F_33 ( V_48 -> V_49 , V_18 ) ) {
V_48 -> V_49 = F_34 ( V_48 -> V_49 , V_18 ) ;
if ( V_48 -> V_49 >= V_50 )
V_48 -> V_49 = F_13 ( V_18 ) ;
if ( V_48 -> V_49 >= V_50 )
V_48 -> V_49 = F_2 () ;
}
}
static void F_35 ( struct V_1 * V_4 ,
const T_1 * V_19 ,
enum V_43 V_44 )
{
T_1 V_18 ;
if ( V_4 -> V_13 & V_37 ) {
int V_5 = F_13 ( V_4 -> V_31 . V_32 ) ;
if ( F_33 ( V_5 , * V_19 ) ) {
V_4 -> V_21 . V_23 = V_5 ;
V_4 -> V_13 &= ~ V_22 ;
} else
V_4 -> V_13 |= V_22 ;
} else if ( V_4 -> V_13 & V_29 ) {
F_6 ( & V_18 , & V_4 -> V_31 . V_32 , V_19 ) ;
V_4 -> V_21 . V_23 = F_13 ( V_18 ) ;
} else if ( ! ( V_4 -> V_13 & V_22 ) ) {
V_4 -> V_21 . V_23 = F_36 ( V_4 -> V_21 . V_23 ,
V_4 -> V_31 . V_33 ,
* V_19 ) ;
V_4 -> V_31 . V_33 = * V_19 ;
}
}
static void F_37 ( struct V_1 * V_4 , const T_1 * V_51 ,
enum V_43 V_44 )
{
if ( ! V_4 )
return;
if ( ! F_5 ( V_4 ) && V_44 == V_45 &&
F_38 ( V_4 -> V_31 . V_33 , * V_51 ) )
return;
if ( V_44 == V_46 && ( V_4 -> V_13 & V_52 ) )
return;
if ( V_44 == V_47 && ! ( V_4 -> V_13 & V_52 ) )
F_31 () ;
if ( V_44 == V_46 )
V_4 -> V_13 |= V_52 ;
else if ( V_44 == V_47 )
V_4 -> V_13 &= ~ V_52 ;
else if ( V_44 >= V_53 )
F_31 () ;
V_34 [ V_4 -> V_8 ] . F_39 ( V_4 , V_51 , V_44 ) ;
}
void F_40 ( struct V_2 * V_54 , const T_1 * V_55 ,
enum V_43 V_44 )
{
F_37 ( V_54 -> V_1 , V_55 , V_44 ) ;
}
void F_41 ( struct V_56 * V_57 , T_1 * V_55 )
{
struct V_58 * V_59 ;
F_42 ( & V_57 -> V_60 ) ;
for ( V_59 = V_57 -> V_61 ; V_59 ; V_59 = V_59 -> V_62 )
F_37 ( V_59 -> V_63 , V_55 , V_45 ) ;
F_43 ( & V_57 -> V_60 ) ;
}
static int F_44 ( struct V_58 * V_59 , T_2 * V_64 ,
unsigned long V_65 , unsigned long V_66 ,
const T_1 * V_19 , unsigned long V_13 ,
void * V_67 )
{
T_3 * V_68 ;
T_3 * V_69 ;
T_4 * V_70 ;
V_68 = V_69 = F_45 ( V_59 -> V_71 , V_64 , V_65 , & V_70 ) ;
do {
struct V_72 * V_72 ;
int V_73 ;
if ( ! F_46 ( * V_69 ) )
continue;
V_72 = F_47 ( V_59 , V_65 , * V_69 ) ;
if ( ! V_72 )
continue;
if ( F_48 ( V_72 ) )
continue;
V_73 = F_49 ( V_72 ) ;
if ( F_33 ( V_73 , * V_19 ) == ! ! ( V_13 & V_74 ) )
continue;
if ( V_13 & ( V_75 | V_76 ) )
F_50 ( V_72 , V_67 , V_13 ) ;
else
break;
} while ( V_69 ++ , V_65 += V_77 , V_65 != V_66 );
F_51 ( V_68 , V_70 ) ;
return V_65 != V_66 ;
}
static void F_52 ( struct V_58 * V_59 ,
T_2 * V_64 , const T_1 * V_19 , unsigned long V_13 ,
void * V_67 )
{
#ifdef F_53
int V_73 ;
struct V_72 * V_72 ;
T_4 * V_70 ;
T_3 V_78 ;
V_70 = F_54 ( F_55 ( V_59 ) , V_59 -> V_71 , ( T_3 * ) V_64 ) ;
V_78 = F_56 ( ( T_3 * ) V_64 ) ;
if ( ! F_46 ( V_78 ) )
goto V_79;
V_72 = F_57 ( V_78 ) ;
V_73 = F_49 ( V_72 ) ;
if ( F_33 ( V_73 , * V_19 ) == ! ! ( V_13 & V_74 ) )
goto V_79;
if ( V_13 & ( V_76 ) ||
( V_13 & V_75 && F_58 ( V_72 ) == 1 ) )
F_59 ( V_72 , V_67 ) ;
V_79:
F_60 ( V_70 ) ;
#else
F_31 () ;
#endif
}
static inline int F_61 ( struct V_58 * V_59 , T_5 * V_80 ,
unsigned long V_65 , unsigned long V_66 ,
const T_1 * V_19 , unsigned long V_13 ,
void * V_67 )
{
T_2 * V_64 ;
unsigned long V_81 ;
V_64 = F_62 ( V_80 , V_65 ) ;
do {
V_81 = F_63 ( V_65 , V_66 ) ;
if ( ! F_64 ( * V_64 ) )
continue;
if ( F_65 ( * V_64 ) && F_66 ( V_59 ) ) {
F_52 ( V_59 , V_64 , V_19 ,
V_13 , V_67 ) ;
continue;
}
F_67 ( V_59 , V_65 , V_64 ) ;
if ( F_68 ( V_64 ) )
continue;
if ( F_44 ( V_59 , V_64 , V_65 , V_81 , V_19 ,
V_13 , V_67 ) )
return - V_82 ;
} while ( V_64 ++ , V_65 = V_81 , V_65 != V_66 );
return 0 ;
}
static inline int F_69 ( struct V_58 * V_59 , T_6 * V_83 ,
unsigned long V_65 , unsigned long V_66 ,
const T_1 * V_19 , unsigned long V_13 ,
void * V_67 )
{
T_5 * V_80 ;
unsigned long V_81 ;
V_80 = F_70 ( V_83 , V_65 ) ;
do {
V_81 = F_71 ( V_65 , V_66 ) ;
if ( F_72 ( * V_80 ) && F_66 ( V_59 ) )
continue;
if ( F_73 ( V_80 ) )
continue;
if ( F_61 ( V_59 , V_80 , V_65 , V_81 , V_19 ,
V_13 , V_67 ) )
return - V_82 ;
} while ( V_80 ++ , V_65 = V_81 , V_65 != V_66 );
return 0 ;
}
static inline int F_74 ( struct V_58 * V_59 ,
unsigned long V_65 , unsigned long V_66 ,
const T_1 * V_19 , unsigned long V_13 ,
void * V_67 )
{
T_6 * V_83 ;
unsigned long V_81 ;
V_83 = F_75 ( V_59 -> V_71 , V_65 ) ;
do {
V_81 = F_76 ( V_65 , V_66 ) ;
if ( F_77 ( V_83 ) )
continue;
if ( F_69 ( V_59 , V_83 , V_65 , V_81 , V_19 ,
V_13 , V_67 ) )
return - V_82 ;
} while ( V_83 ++ , V_65 = V_81 , V_65 != V_66 );
return 0 ;
}
unsigned long F_78 ( struct V_58 * V_59 ,
unsigned long V_65 , unsigned long V_66 )
{
int V_84 ;
V_84 = F_79 ( V_59 , V_65 , V_66 , V_59 -> V_85 , 0 , 1 ) ;
if ( V_84 )
F_80 ( V_86 , V_84 ) ;
return V_84 ;
}
static unsigned long F_78 ( struct V_58 * V_59 ,
unsigned long V_65 , unsigned long V_66 )
{
return 0 ;
}
static int
F_81 ( struct V_56 * V_57 , unsigned long V_87 , unsigned long V_66 ,
const T_1 * V_19 , unsigned long V_13 , void * V_67 )
{
int V_88 = 0 ;
struct V_58 * V_59 , * V_89 ;
V_59 = F_82 ( V_57 , V_87 ) ;
if ( ! V_59 )
return - V_90 ;
V_89 = NULL ;
for (; V_59 && V_59 -> V_91 < V_66 ; V_59 = V_59 -> V_62 ) {
unsigned long V_92 = V_59 -> V_93 ;
if ( V_92 > V_66 )
V_92 = V_66 ;
if ( V_59 -> V_91 > V_87 )
V_87 = V_59 -> V_91 ;
if ( ! ( V_13 & V_94 ) ) {
if ( ! V_59 -> V_62 && V_59 -> V_93 < V_66 )
return - V_90 ;
if ( V_89 && V_89 -> V_93 < V_59 -> V_91 )
return - V_90 ;
}
if ( V_13 & V_95 ) {
if ( V_59 -> V_96 & ( V_97 | V_98 | V_99 ) )
F_78 ( V_59 , V_87 , V_92 ) ;
goto V_81;
}
if ( ( V_13 & V_100 ) ||
( ( V_13 & ( V_75 | V_76 ) ) &&
F_83 ( V_59 ) ) ) {
V_88 = F_74 ( V_59 , V_87 , V_92 , V_19 ,
V_13 , V_67 ) ;
if ( V_88 )
break;
}
V_81:
V_89 = V_59 ;
}
return V_88 ;
}
static int F_84 ( struct V_58 * V_59 ,
struct V_1 * V_4 )
{
int V_88 ;
struct V_1 * V_101 ;
struct V_1 * V_55 ;
F_20 ( L_2 ,
V_59 -> V_91 , V_59 -> V_93 , V_59 -> V_102 ,
V_59 -> V_103 , V_59 -> V_104 ,
V_59 -> V_103 ? V_59 -> V_103 -> V_105 : NULL ) ;
V_55 = F_85 ( V_4 ) ;
if ( F_86 ( V_55 ) )
return F_87 ( V_55 ) ;
if ( V_59 -> V_103 && V_59 -> V_103 -> V_105 ) {
V_88 = V_59 -> V_103 -> V_105 ( V_59 , V_55 ) ;
if ( V_88 )
goto V_106;
}
V_101 = V_59 -> V_63 ;
V_59 -> V_63 = V_55 ;
F_88 ( V_101 ) ;
return 0 ;
V_106:
F_88 ( V_55 ) ;
return V_88 ;
}
static int F_89 ( struct V_56 * V_57 , unsigned long V_87 ,
unsigned long V_66 , struct V_1 * V_107 )
{
struct V_58 * V_81 ;
struct V_58 * V_89 ;
struct V_58 * V_59 ;
int V_88 = 0 ;
T_7 V_108 ;
unsigned long V_109 ;
unsigned long V_110 ;
V_59 = F_82 ( V_57 , V_87 ) ;
if ( ! V_59 || V_59 -> V_91 > V_87 )
return - V_90 ;
V_89 = V_59 -> V_111 ;
if ( V_87 > V_59 -> V_91 )
V_89 = V_59 ;
for (; V_59 && V_59 -> V_91 < V_66 ; V_89 = V_59 , V_59 = V_81 ) {
V_81 = V_59 -> V_62 ;
V_109 = F_90 ( V_87 , V_59 -> V_91 ) ;
V_110 = F_91 ( V_66 , V_59 -> V_93 ) ;
if ( F_92 ( F_93 ( V_59 ) , V_107 ) )
continue;
V_108 = V_59 -> V_102 +
( ( V_109 - V_59 -> V_91 ) >> V_112 ) ;
V_89 = F_94 ( V_57 , V_89 , V_109 , V_110 , V_59 -> V_96 ,
V_59 -> V_113 , V_59 -> V_104 , V_108 ,
V_107 ) ;
if ( V_89 ) {
V_59 = V_89 ;
V_81 = V_59 -> V_62 ;
if ( F_92 ( F_93 ( V_59 ) , V_107 ) )
continue;
goto V_114;
}
if ( V_59 -> V_91 != V_109 ) {
V_88 = F_95 ( V_59 -> V_71 , V_59 , V_109 , 1 ) ;
if ( V_88 )
goto V_115;
}
if ( V_59 -> V_93 != V_110 ) {
V_88 = F_95 ( V_59 -> V_71 , V_59 , V_110 , 0 ) ;
if ( V_88 )
goto V_115;
}
V_114:
V_88 = F_84 ( V_59 , V_107 ) ;
if ( V_88 )
goto V_115;
}
V_115:
return V_88 ;
}
static long F_96 ( unsigned short V_8 , unsigned short V_13 ,
T_1 * V_19 )
{
struct V_1 * V_55 , * V_101 ;
F_97 ( V_116 ) ;
int V_15 ;
if ( ! V_116 )
return - V_41 ;
V_55 = F_19 ( V_8 , V_13 , V_19 ) ;
if ( F_86 ( V_55 ) ) {
V_15 = F_87 ( V_55 ) ;
goto V_115;
}
F_98 ( V_48 ) ;
V_15 = F_15 ( V_55 , V_19 , V_116 ) ;
if ( V_15 ) {
F_99 ( V_48 ) ;
F_88 ( V_55 ) ;
goto V_115;
}
V_101 = V_48 -> V_1 ;
V_48 -> V_1 = V_55 ;
if ( V_55 && V_55 -> V_8 == V_117 &&
F_8 ( V_55 -> V_21 . V_19 ) )
V_48 -> V_49 = F_13 ( V_55 -> V_21 . V_19 ) ;
F_99 ( V_48 ) ;
F_88 ( V_101 ) ;
V_15 = 0 ;
V_115:
F_100 ( V_116 ) ;
return V_15 ;
}
static void F_101 ( struct V_1 * V_3 , T_1 * V_19 )
{
F_102 ( * V_19 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_118 :
case V_117 :
* V_19 = V_3 -> V_21 . V_19 ;
break;
case V_28 :
if ( ! ( V_3 -> V_13 & V_22 ) )
F_103 ( V_3 -> V_21 . V_23 , * V_19 ) ;
break;
default:
F_31 () ;
}
}
static int F_104 ( struct V_56 * V_57 , unsigned long V_65 )
{
struct V_72 * V_3 ;
int V_88 ;
V_88 = F_105 ( V_48 , V_57 , V_65 & V_119 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_88 >= 0 ) {
V_88 = F_49 ( V_3 ) ;
F_106 ( V_3 ) ;
}
return V_88 ;
}
static long F_107 ( int * V_35 , T_1 * V_120 ,
unsigned long V_65 , unsigned long V_13 )
{
int V_88 ;
struct V_56 * V_57 = V_48 -> V_57 ;
struct V_58 * V_59 = NULL ;
struct V_1 * V_4 = V_48 -> V_1 ;
if ( V_13 &
~ ( unsigned long ) ( V_121 | V_122 | V_123 ) )
return - V_20 ;
if ( V_13 & V_123 ) {
if ( V_13 & ( V_121 | V_122 ) )
return - V_20 ;
* V_35 = 0 ;
F_98 ( V_48 ) ;
* V_120 = V_27 ;
F_99 ( V_48 ) ;
return 0 ;
}
if ( V_13 & V_122 ) {
F_108 ( & V_57 -> V_60 ) ;
V_59 = F_109 ( V_57 , V_65 , V_65 + 1 ) ;
if ( ! V_59 ) {
F_110 ( & V_57 -> V_60 ) ;
return - V_90 ;
}
if ( V_59 -> V_103 && V_59 -> V_103 -> V_124 )
V_4 = V_59 -> V_103 -> V_124 ( V_59 , V_65 ) ;
else
V_4 = V_59 -> V_63 ;
} else if ( V_65 )
return - V_20 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_13 & V_121 ) {
if ( V_13 & V_122 ) {
V_88 = F_104 ( V_57 , V_65 ) ;
if ( V_88 < 0 )
goto V_115;
* V_35 = V_88 ;
} else if ( V_4 == V_48 -> V_1 &&
V_4 -> V_8 == V_117 ) {
* V_35 = V_48 -> V_49 ;
} else {
V_88 = - V_20 ;
goto V_115;
}
} else {
* V_35 = V_4 == & V_9 ? V_36 :
V_4 -> V_8 ;
* V_35 |= ( V_4 -> V_13 & V_14 ) ;
}
if ( V_59 ) {
F_110 ( & V_48 -> V_57 -> V_60 ) ;
V_59 = NULL ;
}
V_88 = 0 ;
if ( V_120 ) {
if ( F_5 ( V_4 ) ) {
* V_120 = V_4 -> V_31 . V_32 ;
} else {
F_98 ( V_48 ) ;
F_101 ( V_4 , V_120 ) ;
F_99 ( V_48 ) ;
}
}
V_115:
F_111 ( V_4 ) ;
if ( V_59 )
F_110 ( & V_48 -> V_57 -> V_60 ) ;
return V_88 ;
}
static void F_50 ( struct V_72 * V_72 , struct V_125 * V_126 ,
unsigned long V_13 )
{
if ( ( V_13 & V_76 ) || F_58 ( V_72 ) == 1 ) {
if ( ! F_112 ( V_72 ) ) {
F_113 ( & V_72 -> V_127 , V_126 ) ;
F_114 ( V_72 , V_128 +
F_115 ( V_72 ) ) ;
}
}
}
static struct V_72 * F_116 ( struct V_72 * V_72 , unsigned long V_5 , int * * V_129 )
{
if ( F_117 ( V_72 ) )
return F_118 ( F_119 ( F_120 ( V_72 ) ) ,
V_5 ) ;
else
return F_121 ( V_5 , V_130 , 0 ) ;
}
static int F_122 ( struct V_56 * V_57 , int V_131 , int V_132 ,
int V_13 )
{
T_1 V_120 ;
F_123 ( V_126 ) ;
int V_88 = 0 ;
F_102 ( V_120 ) ;
F_103 ( V_131 , V_120 ) ;
F_17 ( ! ( V_13 & ( V_75 | V_76 ) ) ) ;
F_81 ( V_57 , V_57 -> V_61 -> V_91 , V_57 -> V_133 , & V_120 ,
V_13 | V_94 , & V_126 ) ;
if ( ! F_124 ( & V_126 ) ) {
V_88 = F_125 ( & V_126 , F_116 , NULL , V_132 ,
V_134 , V_135 ) ;
if ( V_88 )
F_126 ( & V_126 ) ;
}
return V_88 ;
}
int F_127 ( struct V_56 * V_57 , const T_1 * V_136 ,
const T_1 * V_137 , int V_13 )
{
int V_138 = 0 ;
int V_88 ;
T_1 V_18 ;
V_88 = F_128 () ;
if ( V_88 )
return V_88 ;
F_108 ( & V_57 -> V_60 ) ;
V_88 = F_129 ( V_57 , V_136 , V_137 , V_13 ) ;
if ( V_88 )
goto V_115;
V_18 = * V_136 ;
while ( ! F_11 ( V_18 ) ) {
int V_139 , V_140 ;
int V_131 = V_6 ;
int V_132 = 0 ;
F_130 (s, tmp) {
if ( ( F_8 ( * V_136 ) != F_8 ( * V_137 ) ) &&
( F_33 ( V_139 , * V_137 ) ) )
continue;
V_140 = F_36 ( V_139 , * V_136 , * V_137 ) ;
if ( V_139 == V_140 )
continue;
V_131 = V_139 ;
V_132 = V_140 ;
if ( ! F_33 ( V_132 , V_18 ) )
break;
}
if ( V_131 == V_6 )
break;
F_131 ( V_131 , V_18 ) ;
V_88 = F_122 ( V_57 , V_131 , V_132 , V_13 ) ;
if ( V_88 > 0 )
V_138 += V_88 ;
if ( V_88 < 0 )
break;
}
V_115:
F_110 ( & V_57 -> V_60 ) ;
if ( V_88 < 0 )
return V_88 ;
return V_138 ;
}
static struct V_72 * F_132 ( struct V_72 * V_72 , unsigned long V_87 , int * * V_129 )
{
struct V_58 * V_59 ;
unsigned long V_141 ( V_142 ) ;
V_59 = F_82 ( V_48 -> V_57 , V_87 ) ;
while ( V_59 ) {
V_142 = F_133 ( V_72 , V_59 ) ;
if ( V_142 != - V_90 )
break;
V_59 = V_59 -> V_62 ;
}
if ( F_117 ( V_72 ) ) {
F_134 ( ! V_59 ) ;
return F_135 ( V_59 , V_142 , 1 ) ;
}
return F_136 ( V_130 , V_59 , V_142 ) ;
}
static void F_50 ( struct V_72 * V_72 , struct V_125 * V_126 ,
unsigned long V_13 )
{
}
int F_127 ( struct V_56 * V_57 , const T_1 * V_136 ,
const T_1 * V_137 , int V_13 )
{
return - V_143 ;
}
static struct V_72 * F_132 ( struct V_72 * V_72 , unsigned long V_87 , int * * V_129 )
{
return NULL ;
}
static long F_137 ( unsigned long V_87 , unsigned long V_144 ,
unsigned short V_8 , unsigned short V_145 ,
T_1 * V_120 , unsigned long V_13 )
{
struct V_56 * V_57 = V_48 -> V_57 ;
struct V_1 * V_55 ;
unsigned long V_66 ;
int V_88 ;
F_123 ( V_126 ) ;
if ( V_13 & ~ ( unsigned long ) V_146 )
return - V_20 ;
if ( ( V_13 & V_76 ) && ! F_138 ( V_147 ) )
return - V_148 ;
if ( V_87 & ~ V_119 )
return - V_20 ;
if ( V_8 == V_36 )
V_13 &= ~ V_100 ;
V_144 = ( V_144 + V_77 - 1 ) & V_119 ;
V_66 = V_87 + V_144 ;
if ( V_66 < V_87 )
return - V_20 ;
if ( V_66 == V_87 )
return 0 ;
V_55 = F_19 ( V_8 , V_145 , V_120 ) ;
if ( F_86 ( V_55 ) )
return F_87 ( V_55 ) ;
if ( V_13 & V_95 )
V_55 -> V_13 |= V_149 ;
if ( ! V_55 )
V_13 |= V_94 ;
F_20 ( L_3 ,
V_87 , V_87 + V_144 , V_8 , V_145 ,
V_120 ? F_21 ( * V_120 ) [ 0 ] : V_6 ) ;
if ( V_13 & ( V_75 | V_76 ) ) {
V_88 = F_128 () ;
if ( V_88 )
goto V_150;
}
{
F_97 ( V_116 ) ;
if ( V_116 ) {
F_42 ( & V_57 -> V_60 ) ;
F_98 ( V_48 ) ;
V_88 = F_15 ( V_55 , V_120 , V_116 ) ;
F_99 ( V_48 ) ;
if ( V_88 )
F_43 ( & V_57 -> V_60 ) ;
} else
V_88 = - V_41 ;
F_100 ( V_116 ) ;
}
if ( V_88 )
goto V_150;
V_88 = F_81 ( V_57 , V_87 , V_66 , V_120 ,
V_13 | V_74 , & V_126 ) ;
if ( ! V_88 )
V_88 = F_89 ( V_57 , V_87 , V_66 , V_55 ) ;
if ( ! V_88 ) {
int V_151 = 0 ;
if ( ! F_124 ( & V_126 ) ) {
F_139 ( V_13 & V_95 ) ;
V_151 = F_125 ( & V_126 , F_132 , NULL ,
V_87 , V_134 , V_152 ) ;
if ( V_151 )
F_126 ( & V_126 ) ;
}
if ( V_151 && ( V_13 & V_100 ) )
V_88 = - V_82 ;
} else
F_126 ( & V_126 ) ;
F_43 ( & V_57 -> V_60 ) ;
V_150:
F_88 ( V_55 ) ;
return V_88 ;
}
static int F_140 ( T_1 * V_19 , const unsigned long T_8 * V_120 ,
unsigned long V_153 )
{
unsigned long V_154 ;
unsigned long V_155 ;
unsigned long V_156 ;
-- V_153 ;
F_102 ( * V_19 ) ;
if ( V_153 == 0 || ! V_120 )
return 0 ;
if ( V_153 > V_77 * V_157 )
return - V_20 ;
V_155 = F_141 ( V_153 ) ;
if ( ( V_153 % V_158 ) == 0 )
V_156 = ~ 0UL ;
else
V_156 = ( 1UL << ( V_153 % V_158 ) ) - 1 ;
if ( V_155 > F_141 ( V_50 ) ) {
if ( V_155 > V_77 / sizeof( long ) )
return - V_20 ;
for ( V_154 = F_141 ( V_50 ) ; V_154 < V_155 ; V_154 ++ ) {
unsigned long V_159 ;
if ( F_142 ( V_159 , V_120 + V_154 ) )
return - V_90 ;
if ( V_154 == V_155 - 1 ) {
if ( V_159 & V_156 )
return - V_20 ;
} else if ( V_159 )
return - V_20 ;
}
V_155 = F_141 ( V_50 ) ;
V_156 = ~ 0UL ;
}
if ( F_143 ( F_21 ( * V_19 ) , V_120 , V_155 *sizeof( unsigned long ) ) )
return - V_90 ;
F_21 ( * V_19 ) [ V_155 - 1 ] &= V_156 ;
return 0 ;
}
static int F_144 ( unsigned long T_8 * V_160 , unsigned long V_153 ,
T_1 * V_19 )
{
unsigned long V_161 = F_145 ( V_153 - 1 , 64 ) / 8 ;
const int V_162 = F_141 ( V_50 ) * sizeof( long ) ;
if ( V_161 > V_162 ) {
if ( V_161 > V_77 )
return - V_20 ;
if ( F_146 ( ( char T_8 * ) V_160 + V_162 , V_161 - V_162 ) )
return - V_90 ;
V_161 = V_162 ;
}
return F_147 ( V_160 , F_21 ( * V_19 ) , V_161 ) ? - V_90 : 0 ;
}
struct V_1 * F_148 ( struct V_58 * V_59 ,
unsigned long V_65 )
{
struct V_1 * V_4 = NULL ;
if ( V_59 ) {
if ( V_59 -> V_103 && V_59 -> V_103 -> V_124 ) {
V_4 = V_59 -> V_103 -> V_124 ( V_59 , V_65 ) ;
} else if ( V_59 -> V_63 ) {
V_4 = V_59 -> V_63 ;
if ( F_149 ( V_4 ) )
F_150 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_151 ( struct V_58 * V_59 ,
unsigned long V_65 )
{
struct V_1 * V_4 = F_148 ( V_59 , V_65 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_48 ) ;
return V_4 ;
}
bool F_152 ( struct V_58 * V_59 )
{
struct V_1 * V_4 ;
if ( V_59 -> V_103 && V_59 -> V_103 -> V_124 ) {
bool V_15 = false ;
V_4 = V_59 -> V_103 -> V_124 ( V_59 , V_59 -> V_91 ) ;
if ( V_4 && ( V_4 -> V_13 & V_149 ) )
V_15 = true ;
F_111 ( V_4 ) ;
return V_15 ;
}
V_4 = V_59 -> V_63 ;
if ( ! V_4 )
V_4 = F_1 ( V_48 ) ;
return V_4 -> V_13 & V_149 ;
}
static int F_153 ( struct V_1 * V_35 , enum V_163 V_164 )
{
enum V_163 V_165 = V_166 ;
F_134 ( V_165 == V_167 ) ;
if ( ! F_4 ( V_35 -> V_21 . V_19 , V_11 [ V_168 ] ) )
V_165 = V_167 ;
return V_164 >= V_165 ;
}
static T_1 * F_154 ( T_9 V_169 , struct V_1 * V_35 )
{
if ( F_155 ( V_35 -> V_8 == V_118 ) &&
F_153 ( V_35 , F_156 ( V_169 ) ) &&
F_157 ( & V_35 -> V_21 . V_19 ) )
return & V_35 -> V_21 . V_19 ;
return NULL ;
}
static struct V_170 * F_158 ( T_9 V_169 , struct V_1 * V_35 ,
int V_171 )
{
switch ( V_35 -> V_8 ) {
case V_28 :
if ( ! ( V_35 -> V_13 & V_22 ) )
V_171 = V_35 -> V_21 . V_23 ;
break;
case V_118 :
if ( F_155 ( V_169 & V_172 ) &&
F_155 ( ! F_33 ( V_171 , V_35 -> V_21 . V_19 ) ) )
V_171 = F_13 ( V_35 -> V_21 . V_19 ) ;
break;
default:
F_31 () ;
}
return F_159 ( V_171 , V_169 ) ;
}
static unsigned F_160 ( struct V_1 * V_35 )
{
unsigned V_73 , V_81 ;
struct V_2 * V_173 = V_48 ;
V_73 = V_173 -> V_49 ;
V_81 = F_34 ( V_73 , V_35 -> V_21 . V_19 ) ;
if ( V_81 >= V_50 )
V_81 = F_13 ( V_35 -> V_21 . V_19 ) ;
if ( V_81 < V_50 )
V_173 -> V_49 = V_81 ;
return V_73 ;
}
unsigned int F_161 ( void )
{
struct V_1 * V_35 ;
int V_5 = F_162 () ;
if ( F_163 () )
return V_5 ;
V_35 = V_48 -> V_1 ;
if ( ! V_35 || V_35 -> V_13 & V_22 )
return V_5 ;
switch ( V_35 -> V_8 ) {
case V_28 :
return V_35 -> V_21 . V_23 ;
case V_117 :
return F_160 ( V_35 ) ;
case V_118 : {
struct V_170 * V_170 ;
struct V_164 * V_164 ;
enum V_163 V_174 = F_156 ( V_40 ) ;
V_170 = & F_164 ( V_5 ) -> V_175 [ 0 ] ;
( void ) F_165 ( V_170 , V_174 ,
& V_35 -> V_21 . V_19 ,
& V_164 ) ;
return V_164 ? V_164 -> V_5 : V_5 ;
}
default:
F_31 () ;
}
}
static unsigned F_166 ( struct V_1 * V_4 ,
struct V_58 * V_59 , unsigned long V_176 )
{
unsigned V_177 = F_8 ( V_4 -> V_21 . V_19 ) ;
unsigned V_178 ;
int V_179 ;
int V_73 = V_6 ;
if ( ! V_177 )
return F_2 () ;
V_178 = ( unsigned int ) V_176 % V_177 ;
V_179 = 0 ;
do {
V_73 = F_34 ( V_73 , V_4 -> V_21 . V_19 ) ;
V_179 ++ ;
} while ( V_179 <= V_178 );
return V_73 ;
}
static inline unsigned F_167 ( struct V_1 * V_4 ,
struct V_58 * V_59 , unsigned long V_65 , int V_180 )
{
if ( V_59 ) {
unsigned long V_176 ;
F_134 ( V_180 < V_112 ) ;
V_176 = V_59 -> V_102 >> ( V_180 - V_112 ) ;
V_176 += ( V_65 - V_59 -> V_91 ) >> V_180 ;
return F_166 ( V_4 , V_59 , V_176 ) ;
} else
return F_160 ( V_4 ) ;
}
int F_168 ( const T_1 * V_181 )
{
int V_31 , V_182 = V_6 ;
V_31 = F_8 ( * V_181 ) ;
if ( V_31 )
V_182 = F_169 ( V_181 -> V_183 ,
F_170 () % V_31 , V_50 ) ;
return V_182 ;
}
struct V_170 * F_171 ( struct V_58 * V_59 , unsigned long V_65 ,
T_9 V_184 , struct V_1 * * V_185 ,
T_1 * * V_10 )
{
struct V_170 * V_186 ;
* V_185 = F_151 ( V_59 , V_65 ) ;
* V_10 = NULL ;
if ( F_155 ( ( * V_185 ) -> V_8 == V_117 ) ) {
V_186 = F_159 ( F_167 ( * V_185 , V_59 , V_65 ,
F_172 ( F_55 ( V_59 ) ) ) , V_184 ) ;
} else {
V_186 = F_158 ( V_184 , * V_185 , F_2 () ) ;
if ( ( * V_185 ) -> V_8 == V_118 )
* V_10 = & ( * V_185 ) -> V_21 . V_19 ;
}
return V_186 ;
}
bool F_173 ( T_1 * V_160 )
{
struct V_1 * V_1 ;
int V_73 ;
if ( ! ( V_160 && V_48 -> V_1 ) )
return false ;
F_98 ( V_48 ) ;
V_1 = V_48 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_28 :
if ( V_1 -> V_13 & V_22 )
V_73 = F_2 () ;
else
V_73 = V_1 -> V_21 . V_23 ;
F_174 ( V_160 , V_73 ) ;
break;
case V_118 :
case V_117 :
* V_160 = V_1 -> V_21 . V_19 ;
break;
default:
F_31 () ;
}
F_99 ( V_48 ) ;
return true ;
}
bool F_175 ( struct V_2 * V_54 ,
const T_1 * V_160 )
{
struct V_1 * V_1 ;
bool V_15 = true ;
if ( ! V_160 )
return V_15 ;
F_98 ( V_54 ) ;
V_1 = V_54 -> V_1 ;
if ( ! V_1 )
goto V_115;
switch ( V_1 -> V_8 ) {
case V_28 :
break;
case V_118 :
case V_117 :
V_15 = F_4 ( V_1 -> V_21 . V_19 , * V_160 ) ;
break;
default:
F_31 () ;
}
V_115:
F_99 ( V_54 ) ;
return V_15 ;
}
static struct V_72 * F_176 ( T_9 V_169 , unsigned V_187 ,
unsigned V_73 )
{
struct V_170 * V_186 ;
struct V_72 * V_72 ;
V_186 = F_159 ( V_73 , V_169 ) ;
V_72 = F_177 ( V_169 , V_187 , V_186 ) ;
if ( V_72 && F_178 ( V_72 ) == F_179 ( & V_186 -> V_188 [ 0 ] ) )
F_114 ( V_72 , V_189 ) ;
return V_72 ;
}
struct V_72 *
F_180 ( T_9 V_169 , int V_187 , struct V_58 * V_59 ,
unsigned long V_65 , int V_5 )
{
struct V_1 * V_4 ;
struct V_72 * V_72 ;
unsigned int V_190 ;
V_191:
V_4 = F_151 ( V_59 , V_65 ) ;
V_190 = F_181 () ;
if ( F_155 ( V_4 -> V_8 == V_117 ) ) {
unsigned V_73 ;
V_73 = F_167 ( V_4 , V_59 , V_65 , V_112 + V_187 ) ;
F_111 ( V_4 ) ;
V_72 = F_176 ( V_169 , V_187 , V_73 ) ;
if ( F_155 ( ! V_72 && F_182 ( V_190 ) ) )
goto V_191;
return V_72 ;
}
V_72 = F_183 ( V_169 , V_187 ,
F_158 ( V_169 , V_4 , V_5 ) ,
F_154 ( V_169 , V_4 ) ) ;
F_111 ( V_4 ) ;
if ( F_155 ( ! V_72 && F_182 ( V_190 ) ) )
goto V_191;
return V_72 ;
}
struct V_72 * F_184 ( T_9 V_169 , unsigned V_187 )
{
struct V_1 * V_4 = & V_9 ;
struct V_72 * V_72 ;
unsigned int V_190 ;
if ( ! F_163 () && ! ( V_169 & V_172 ) )
V_4 = F_1 ( V_48 ) ;
V_191:
V_190 = F_181 () ;
if ( V_4 -> V_8 == V_117 )
V_72 = F_176 ( V_169 , V_187 , F_160 ( V_4 ) ) ;
else
V_72 = F_183 ( V_169 , V_187 ,
F_158 ( V_169 , V_4 , F_2 () ) ,
F_154 ( V_169 , V_4 ) ) ;
if ( F_155 ( ! V_72 && F_182 ( V_190 ) ) )
goto V_191;
return V_72 ;
}
int F_185 ( struct V_58 * V_192 , struct V_58 * V_193 )
{
struct V_1 * V_4 = F_85 ( F_93 ( V_192 ) ) ;
if ( F_86 ( V_4 ) )
return F_87 ( V_4 ) ;
V_193 -> V_63 = V_4 ;
return 0 ;
}
struct V_1 * F_186 ( struct V_1 * V_101 )
{
struct V_1 * V_55 = F_23 ( V_39 , V_40 ) ;
if ( ! V_55 )
return F_22 ( - V_41 ) ;
if ( V_101 == V_48 -> V_1 ) {
F_98 ( V_48 ) ;
* V_55 = * V_101 ;
F_99 ( V_48 ) ;
} else
* V_55 = * V_101 ;
if ( F_187 () ) {
T_1 V_194 = V_33 ( V_48 ) ;
if ( V_55 -> V_13 & V_52 )
F_37 ( V_55 , & V_194 , V_47 ) ;
else
F_37 ( V_55 , & V_194 , V_45 ) ;
}
F_24 ( & V_55 -> V_42 , 1 ) ;
return V_55 ;
}
bool F_188 ( struct V_1 * V_195 , struct V_1 * V_196 )
{
if ( ! V_195 || ! V_196 )
return false ;
if ( V_195 -> V_8 != V_196 -> V_8 )
return false ;
if ( V_195 -> V_13 != V_196 -> V_13 )
return false ;
if ( F_5 ( V_195 ) )
if ( ! F_38 ( V_195 -> V_31 . V_32 , V_196 -> V_31 . V_32 ) )
return false ;
switch ( V_195 -> V_8 ) {
case V_118 :
case V_117 :
return ! ! F_38 ( V_195 -> V_21 . V_19 , V_196 -> V_21 . V_19 ) ;
case V_28 :
return V_195 -> V_21 . V_23 == V_196 -> V_21 . V_23 ;
default:
F_31 () ;
return false ;
}
}
static struct V_197 *
F_189 ( struct V_198 * V_199 , unsigned long V_87 , unsigned long V_66 )
{
struct V_200 * V_201 = V_199 -> V_202 . V_200 ;
while ( V_201 ) {
struct V_197 * V_3 = F_190 ( V_201 , struct V_197 , V_171 ) ;
if ( V_87 >= V_3 -> V_66 )
V_201 = V_201 -> V_203 ;
else if ( V_66 <= V_3 -> V_87 )
V_201 = V_201 -> V_204 ;
else
break;
}
if ( ! V_201 )
return NULL ;
for (; ; ) {
struct V_197 * V_31 = NULL ;
struct V_200 * V_89 = F_191 ( V_201 ) ;
if ( ! V_89 )
break;
V_31 = F_190 ( V_89 , struct V_197 , V_171 ) ;
if ( V_31 -> V_66 <= V_87 )
break;
V_201 = V_89 ;
}
return F_190 ( V_201 , struct V_197 , V_171 ) ;
}
static void F_192 ( struct V_198 * V_199 , struct V_197 * V_55 )
{
struct V_200 * * V_3 = & V_199 -> V_202 . V_200 ;
struct V_200 * V_205 = NULL ;
struct V_197 * V_171 ;
while ( * V_3 ) {
V_205 = * V_3 ;
V_171 = F_190 ( V_205 , struct V_197 , V_171 ) ;
if ( V_55 -> V_87 < V_171 -> V_87 )
V_3 = & ( * V_3 ) -> V_204 ;
else if ( V_55 -> V_66 > V_171 -> V_66 )
V_3 = & ( * V_3 ) -> V_203 ;
else
F_31 () ;
}
F_193 ( & V_55 -> V_171 , V_205 , V_3 ) ;
F_194 ( & V_55 -> V_171 , & V_199 -> V_202 ) ;
F_20 ( L_4 , V_55 -> V_87 , V_55 -> V_66 ,
V_55 -> V_35 ? V_55 -> V_35 -> V_8 : 0 ) ;
}
struct V_1 *
F_195 ( struct V_198 * V_199 , unsigned long V_206 )
{
struct V_1 * V_4 = NULL ;
struct V_197 * V_207 ;
if ( ! V_199 -> V_202 . V_200 )
return NULL ;
F_196 ( & V_199 -> V_208 ) ;
V_207 = F_189 ( V_199 , V_206 , V_206 + 1 ) ;
if ( V_207 ) {
F_150 ( V_207 -> V_35 ) ;
V_4 = V_207 -> V_35 ;
}
F_60 ( & V_199 -> V_208 ) ;
return V_4 ;
}
static void F_197 ( struct V_197 * V_201 )
{
F_88 ( V_201 -> V_35 ) ;
F_27 ( V_209 , V_201 ) ;
}
int F_198 ( struct V_72 * V_72 , struct V_58 * V_59 , unsigned long V_65 )
{
struct V_1 * V_4 ;
struct V_164 * V_164 ;
int V_210 = F_49 ( V_72 ) ;
unsigned long V_108 ;
int V_211 = F_199 () ;
int V_212 = F_200 ( V_211 ) ;
int V_213 = - 1 ;
int V_15 = - 1 ;
F_134 ( ! V_59 ) ;
V_4 = F_151 ( V_59 , V_65 ) ;
if ( ! ( V_4 -> V_13 & V_149 ) )
goto V_115;
switch ( V_4 -> V_8 ) {
case V_117 :
F_134 ( V_65 >= V_59 -> V_93 ) ;
F_134 ( V_65 < V_59 -> V_91 ) ;
V_108 = V_59 -> V_102 ;
V_108 += ( V_65 - V_59 -> V_91 ) >> V_112 ;
V_213 = F_166 ( V_4 , V_59 , V_108 ) ;
break;
case V_28 :
if ( V_4 -> V_13 & V_22 )
V_213 = F_2 () ;
else
V_213 = V_4 -> V_21 . V_23 ;
break;
case V_118 :
if ( F_33 ( V_210 , V_4 -> V_21 . V_19 ) )
goto V_115;
( void ) F_165 (
F_159 ( F_2 () , V_214 ) ,
F_156 ( V_214 ) ,
& V_4 -> V_21 . V_19 , & V_164 ) ;
V_213 = V_164 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_13 & V_215 ) {
V_213 = V_212 ;
if ( ! F_201 ( V_48 , V_72 , V_210 , V_211 ) )
goto V_115;
}
if ( V_210 != V_213 )
V_15 = V_213 ;
V_115:
F_111 ( V_4 ) ;
return V_15 ;
}
static void F_202 ( struct V_198 * V_199 , struct V_197 * V_201 )
{
F_20 ( L_5 , V_201 -> V_87 , V_201 -> V_66 ) ;
F_203 ( & V_201 -> V_171 , & V_199 -> V_202 ) ;
F_197 ( V_201 ) ;
}
static void F_204 ( struct V_197 * V_5 , unsigned long V_87 ,
unsigned long V_66 , struct V_1 * V_4 )
{
V_5 -> V_87 = V_87 ;
V_5 -> V_66 = V_66 ;
V_5 -> V_35 = V_4 ;
}
static struct V_197 * F_205 ( unsigned long V_87 , unsigned long V_66 ,
struct V_1 * V_4 )
{
struct V_197 * V_201 ;
struct V_1 * V_216 ;
V_201 = F_23 ( V_209 , V_40 ) ;
if ( ! V_201 )
return NULL ;
V_216 = F_85 ( V_4 ) ;
if ( F_86 ( V_216 ) ) {
F_27 ( V_209 , V_201 ) ;
return NULL ;
}
V_216 -> V_13 |= V_217 ;
F_204 ( V_201 , V_87 , V_66 , V_216 ) ;
return V_201 ;
}
static int F_206 ( struct V_198 * V_199 , unsigned long V_87 ,
unsigned long V_66 , struct V_197 * V_55 )
{
struct V_197 * V_201 ;
struct V_197 * V_218 = NULL ;
struct V_1 * F_19 = NULL ;
int V_15 = 0 ;
V_219:
F_196 ( & V_199 -> V_208 ) ;
V_201 = F_189 ( V_199 , V_87 , V_66 ) ;
while ( V_201 && V_201 -> V_87 < V_66 ) {
struct V_200 * V_81 = F_207 ( & V_201 -> V_171 ) ;
if ( V_201 -> V_87 >= V_87 ) {
if ( V_201 -> V_66 <= V_66 )
F_202 ( V_199 , V_201 ) ;
else
V_201 -> V_87 = V_66 ;
} else {
if ( V_201 -> V_66 > V_66 ) {
if ( ! V_218 )
goto V_220;
* F_19 = * V_201 -> V_35 ;
F_24 ( & F_19 -> V_42 , 1 ) ;
F_204 ( V_218 , V_66 , V_201 -> V_66 , F_19 ) ;
V_201 -> V_66 = V_87 ;
F_192 ( V_199 , V_218 ) ;
V_218 = NULL ;
F_19 = NULL ;
break;
} else
V_201 -> V_66 = V_87 ;
}
if ( ! V_81 )
break;
V_201 = F_190 ( V_81 , struct V_197 , V_171 ) ;
}
if ( V_55 )
F_192 ( V_199 , V_55 ) ;
F_60 ( & V_199 -> V_208 ) ;
V_15 = 0 ;
V_106:
if ( F_19 )
F_88 ( F_19 ) ;
if ( V_218 )
F_27 ( V_209 , V_218 ) ;
return V_15 ;
V_220:
F_60 ( & V_199 -> V_208 ) ;
V_15 = - V_41 ;
V_218 = F_23 ( V_209 , V_40 ) ;
if ( ! V_218 )
goto V_106;
F_19 = F_23 ( V_39 , V_40 ) ;
if ( ! F_19 )
goto V_106;
goto V_219;
}
void F_208 ( struct V_198 * V_199 , struct V_1 * V_185 )
{
int V_15 ;
V_199 -> V_202 = V_221 ;
F_209 ( & V_199 -> V_208 ) ;
if ( V_185 ) {
struct V_58 V_222 ;
struct V_1 * V_55 ;
F_97 ( V_116 ) ;
if ( ! V_116 )
goto V_223;
V_55 = F_19 ( V_185 -> V_8 , V_185 -> V_13 , & V_185 -> V_31 . V_32 ) ;
if ( F_86 ( V_55 ) )
goto V_224;
F_98 ( V_48 ) ;
V_15 = F_15 ( V_55 , & V_185 -> V_31 . V_32 , V_116 ) ;
F_99 ( V_48 ) ;
if ( V_15 )
goto V_225;
memset ( & V_222 , 0 , sizeof( struct V_58 ) ) ;
V_222 . V_93 = V_226 ;
F_210 ( V_199 , & V_222 , V_55 ) ;
V_225:
F_88 ( V_55 ) ;
V_224:
F_100 ( V_116 ) ;
V_223:
F_88 ( V_185 ) ;
}
}
int F_210 ( struct V_198 * V_227 ,
struct V_58 * V_59 , struct V_1 * V_228 )
{
int V_88 ;
struct V_197 * V_55 = NULL ;
unsigned long V_229 = F_211 ( V_59 ) ;
F_20 ( L_6 ,
V_59 -> V_102 ,
V_229 , V_228 ? V_228 -> V_8 : - 1 ,
V_228 ? V_228 -> V_13 : - 1 ,
V_228 ? F_21 ( V_228 -> V_21 . V_19 ) [ 0 ] : V_6 ) ;
if ( V_228 ) {
V_55 = F_205 ( V_59 -> V_102 , V_59 -> V_102 + V_229 , V_228 ) ;
if ( ! V_55 )
return - V_41 ;
}
V_88 = F_206 ( V_227 , V_59 -> V_102 , V_59 -> V_102 + V_229 , V_55 ) ;
if ( V_88 && V_55 )
F_197 ( V_55 ) ;
return V_88 ;
}
void F_212 ( struct V_198 * V_3 )
{
struct V_197 * V_201 ;
struct V_200 * V_81 ;
if ( ! V_3 -> V_202 . V_200 )
return;
F_196 ( & V_3 -> V_208 ) ;
V_81 = F_213 ( & V_3 -> V_202 ) ;
while ( V_81 ) {
V_201 = F_190 ( V_81 , struct V_197 , V_171 ) ;
V_81 = F_207 ( & V_201 -> V_171 ) ;
F_202 ( V_3 , V_201 ) ;
}
F_60 ( & V_3 -> V_208 ) ;
}
static void T_10 F_214 ( void )
{
bool V_230 = false ;
if ( F_215 ( V_231 ) )
V_230 = true ;
if ( V_232 )
F_216 ( V_232 == 1 ) ;
if ( V_233 > 1 && ! V_232 ) {
F_217 ( L_7
L_8
L_9 ,
V_230 ? L_10 : L_11 ) ;
F_216 ( V_230 ) ;
}
}
static int T_10 F_218 ( char * V_234 )
{
int V_15 = 0 ;
if ( ! V_234 )
goto V_115;
if ( ! strcmp ( V_234 , L_12 ) ) {
V_232 = 1 ;
V_15 = 1 ;
} else if ( ! strcmp ( V_234 , L_13 ) ) {
V_232 = - 1 ;
V_15 = 1 ;
}
V_115:
if ( ! V_15 )
F_219 ( L_14 ) ;
return V_15 ;
}
static inline void T_10 F_214 ( void )
{
}
void T_10 F_220 ( void )
{
T_1 F_160 ;
unsigned long V_235 = 0 ;
int V_73 , V_236 = 0 ;
V_39 = F_221 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_237 , NULL ) ;
V_209 = F_221 ( L_16 ,
sizeof( struct V_197 ) ,
0 , V_237 , NULL ) ;
F_222 (nid) {
V_7 [ V_73 ] = (struct V_1 ) {
. V_42 = F_223 ( 1 ) ,
. V_8 = V_28 ,
. V_13 = V_149 | V_215 ,
. V_21 = { . V_23 = V_73 , } ,
} ;
}
F_102 ( F_160 ) ;
F_224 (nid, N_MEMORY) {
unsigned long V_238 = F_225 ( V_73 ) ;
if ( V_235 < V_238 ) {
V_235 = V_238 ;
V_236 = V_73 ;
}
if ( ( V_238 << V_112 ) >= ( 16 << 20 ) )
F_103 ( V_73 , F_160 ) ;
}
if ( F_155 ( F_11 ( F_160 ) ) )
F_103 ( V_236 , F_160 ) ;
if ( F_96 ( V_117 , 0 , & F_160 ) )
F_226 ( L_17 , V_239 ) ;
F_214 () ;
}
void F_227 ( void )
{
F_96 ( V_36 , 0 , NULL ) ;
}
int F_228 ( char * V_234 , struct V_1 * * V_185 )
{
struct V_1 * V_55 = NULL ;
unsigned short V_8 ;
unsigned short V_145 ;
T_1 V_19 ;
char * V_240 = strchr ( V_234 , ':' ) ;
char * V_13 = strchr ( V_234 , '=' ) ;
int V_88 = 1 ;
if ( V_240 ) {
* V_240 ++ = '\0' ;
if ( F_229 ( V_240 , V_19 ) )
goto V_115;
if ( ! F_230 ( V_19 , V_11 [ V_12 ] ) )
goto V_115;
} else
F_102 ( V_19 ) ;
if ( V_13 )
* V_13 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_241 ; V_8 ++ ) {
if ( ! strcmp ( V_234 , V_242 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_241 )
goto V_115;
switch ( V_8 ) {
case V_28 :
if ( V_240 ) {
char * V_243 = V_240 ;
while ( isdigit ( * V_243 ) )
V_243 ++ ;
if ( * V_243 )
goto V_115;
}
break;
case V_117 :
if ( ! V_240 )
V_19 = V_11 [ V_12 ] ;
break;
case V_38 :
if ( V_240 )
goto V_115;
V_8 = V_28 ;
break;
case V_36 :
if ( ! V_240 )
V_88 = 0 ;
goto V_115;
case V_118 :
if ( ! V_240 )
goto V_115;
}
V_145 = 0 ;
if ( V_13 ) {
if ( ! strcmp ( V_13 , L_18 ) )
V_145 |= V_37 ;
else if ( ! strcmp ( V_13 , L_19 ) )
V_145 |= V_29 ;
else
goto V_115;
}
V_55 = F_19 ( V_8 , V_145 , & V_19 ) ;
if ( F_86 ( V_55 ) )
goto V_115;
if ( V_8 != V_28 )
V_55 -> V_21 . V_19 = V_19 ;
else if ( V_240 )
V_55 -> V_21 . V_23 = F_13 ( V_19 ) ;
else
V_55 -> V_13 |= V_22 ;
V_55 -> V_31 . V_32 = V_19 ;
V_88 = 0 ;
V_115:
if ( V_240 )
* -- V_240 = ':' ;
if ( V_13 )
* -- V_13 = '=' ;
if ( ! V_88 )
* V_185 = V_55 ;
return V_88 ;
}
void F_231 ( char * V_244 , int V_245 , struct V_1 * V_4 )
{
char * V_3 = V_244 ;
T_1 V_19 = V_246 ;
unsigned short V_8 = V_36 ;
unsigned short V_13 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_13 & V_215 ) ) {
V_8 = V_4 -> V_8 ;
V_13 = V_4 -> V_13 ;
}
switch ( V_8 ) {
case V_36 :
break;
case V_28 :
if ( V_13 & V_22 )
V_8 = V_38 ;
else
F_103 ( V_4 -> V_21 . V_23 , V_19 ) ;
break;
case V_118 :
case V_117 :
V_19 = V_4 -> V_21 . V_19 ;
break;
default:
F_139 ( 1 ) ;
snprintf ( V_3 , V_245 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_245 , L_21 , V_242 [ V_8 ] ) ;
if ( V_13 & V_14 ) {
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_22 ) ;
if ( V_13 & V_37 )
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_18 ) ;
else if ( V_13 & V_29 )
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_19 ) ;
}
if ( ! F_11 ( V_19 ) ) {
V_3 += snprintf ( V_3 , V_244 + V_245 - V_3 , L_23 ) ;
V_3 += F_232 ( V_3 , V_244 + V_245 - V_3 , V_19 ) ;
}
}
