static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_1 ;
if ( ! V_4 ) {
int V_5 = F_2 () ;
if ( V_5 != V_6 ) {
V_4 = & V_7 [ V_5 ] ;
if ( ! V_4 -> V_8 )
V_4 = NULL ;
}
}
return V_4 ;
}
static int F_3 ( const T_1 * V_9 )
{
return F_4 ( * V_9 , V_10 [ V_11 ] ) ;
}
static inline int F_5 ( const struct V_1 * V_4 )
{
return V_4 -> V_12 & V_13 ;
}
static void F_6 ( T_1 * V_14 , const T_1 * V_15 ,
const T_1 * V_16 )
{
T_1 V_17 ;
F_7 ( V_17 , * V_15 , F_8 ( * V_16 ) ) ;
F_9 ( * V_14 , V_17 , * V_16 ) ;
}
static int F_10 ( struct V_1 * V_4 , const T_1 * V_18 )
{
if ( F_11 ( * V_18 ) )
return - V_19 ;
V_4 -> V_20 . V_18 = * V_18 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , const T_1 * V_18 )
{
if ( ! V_18 )
V_4 -> V_12 |= V_21 ;
else if ( F_11 ( * V_18 ) )
return - V_19 ;
else
V_4 -> V_20 . V_22 = F_13 ( * V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_4 , const T_1 * V_18 )
{
if ( ! F_3 ( V_18 ) )
return - V_19 ;
V_4 -> V_20 . V_18 = * V_18 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_4 ,
const T_1 * V_18 , struct V_23 * V_24 )
{
int V_14 ;
if ( V_4 == NULL )
return 0 ;
F_16 ( V_24 -> V_25 ,
V_26 , V_10 [ V_11 ] ) ;
F_17 ( ! V_18 ) ;
if ( V_4 -> V_8 == V_27 && F_11 ( * V_18 ) )
V_18 = NULL ;
else {
if ( V_4 -> V_12 & V_28 )
F_6 ( & V_24 -> V_29 , V_18 , & V_24 -> V_25 ) ;
else
F_16 ( V_24 -> V_29 , * V_18 , V_24 -> V_25 ) ;
if ( F_5 ( V_4 ) )
V_4 -> V_30 . V_31 = * V_18 ;
else
V_4 -> V_30 . V_32 =
V_26 ;
}
if ( V_18 )
V_14 = V_33 [ V_4 -> V_8 ] . F_18 ( V_4 , & V_24 -> V_29 ) ;
else
V_14 = V_33 [ V_4 -> V_8 ] . F_18 ( V_4 , NULL ) ;
return V_14 ;
}
static struct V_1 * F_19 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_34 ;
F_20 ( L_1 ,
V_8 , V_12 , V_18 ? F_21 ( * V_18 ) [ 0 ] : V_6 ) ;
if ( V_8 == V_35 ) {
if ( V_18 && ! F_11 ( * V_18 ) )
return F_22 ( - V_19 ) ;
return NULL ;
}
F_17 ( ! V_18 ) ;
if ( V_8 == V_27 ) {
if ( F_11 ( * V_18 ) ) {
if ( ( ( V_12 & V_36 ) ||
( V_12 & V_28 ) ) )
return F_22 ( - V_19 ) ;
}
} else if ( V_8 == V_37 ) {
if ( ! F_11 ( * V_18 ) )
return F_22 ( - V_19 ) ;
V_8 = V_27 ;
} else if ( F_11 ( * V_18 ) )
return F_22 ( - V_19 ) ;
V_34 = F_23 ( V_38 , V_39 ) ;
if ( ! V_34 )
return F_22 ( - V_40 ) ;
F_24 ( & V_34 -> V_41 , 1 ) ;
V_34 -> V_8 = V_8 ;
V_34 -> V_12 = V_12 ;
return V_34 ;
}
void F_25 ( struct V_1 * V_3 )
{
if ( ! F_26 ( & V_3 -> V_41 ) )
return;
F_27 ( V_38 , V_3 ) ;
}
static void F_28 ( struct V_1 * V_4 , const T_1 * V_18 ,
enum V_42 V_43 )
{
}
static void F_29 ( struct V_1 * V_4 , const T_1 * V_18 ,
enum V_42 V_43 )
{
T_1 V_17 ;
if ( V_4 -> V_12 & V_36 )
F_16 ( V_17 , V_4 -> V_30 . V_31 , * V_18 ) ;
else if ( V_4 -> V_12 & V_28 )
F_6 ( & V_17 , & V_4 -> V_30 . V_31 , V_18 ) ;
else {
if ( V_43 == V_44 || V_43 == V_45 ) {
F_30 ( V_17 , V_4 -> V_20 . V_18 ,
V_4 -> V_30 . V_32 , * V_18 ) ;
V_4 -> V_30 . V_32 = V_43 ? V_17 : * V_18 ;
} else if ( V_43 == V_46 ) {
V_17 = V_4 -> V_30 . V_32 ;
V_4 -> V_30 . V_32 = * V_18 ;
} else
F_31 () ;
}
if ( F_11 ( V_17 ) )
V_17 = * V_18 ;
if ( V_43 == V_45 )
F_32 ( V_4 -> V_20 . V_18 , V_4 -> V_20 . V_18 , V_17 ) ;
else if ( V_43 == V_44 || V_43 == V_46 )
V_4 -> V_20 . V_18 = V_17 ;
else
F_31 () ;
if ( ! F_33 ( V_47 -> V_48 , V_17 ) ) {
V_47 -> V_48 = F_34 ( V_47 -> V_48 , V_17 ) ;
if ( V_47 -> V_48 >= V_49 )
V_47 -> V_48 = F_13 ( V_17 ) ;
if ( V_47 -> V_48 >= V_49 )
V_47 -> V_48 = F_2 () ;
}
}
static void F_35 ( struct V_1 * V_4 ,
const T_1 * V_18 ,
enum V_42 V_43 )
{
T_1 V_17 ;
if ( V_4 -> V_12 & V_36 ) {
int V_5 = F_13 ( V_4 -> V_30 . V_31 ) ;
if ( F_33 ( V_5 , * V_18 ) ) {
V_4 -> V_20 . V_22 = V_5 ;
V_4 -> V_12 &= ~ V_21 ;
} else
V_4 -> V_12 |= V_21 ;
} else if ( V_4 -> V_12 & V_28 ) {
F_6 ( & V_17 , & V_4 -> V_30 . V_31 , V_18 ) ;
V_4 -> V_20 . V_22 = F_13 ( V_17 ) ;
} else if ( ! ( V_4 -> V_12 & V_21 ) ) {
V_4 -> V_20 . V_22 = F_36 ( V_4 -> V_20 . V_22 ,
V_4 -> V_30 . V_32 ,
* V_18 ) ;
V_4 -> V_30 . V_32 = * V_18 ;
}
}
static void F_37 ( struct V_1 * V_4 , const T_1 * V_50 ,
enum V_42 V_43 )
{
if ( ! V_4 )
return;
if ( ! F_5 ( V_4 ) && V_43 == V_44 &&
F_38 ( V_4 -> V_30 . V_32 , * V_50 ) )
return;
if ( V_43 == V_45 && ( V_4 -> V_12 & V_51 ) )
return;
if ( V_43 == V_46 && ! ( V_4 -> V_12 & V_51 ) )
F_31 () ;
if ( V_43 == V_45 )
V_4 -> V_12 |= V_51 ;
else if ( V_43 == V_46 )
V_4 -> V_12 &= ~ V_51 ;
else if ( V_43 >= V_52 )
F_31 () ;
V_33 [ V_4 -> V_8 ] . F_39 ( V_4 , V_50 , V_43 ) ;
}
void F_40 ( struct V_2 * V_53 , const T_1 * V_54 ,
enum V_42 V_43 )
{
F_37 ( V_53 -> V_1 , V_54 , V_43 ) ;
}
void F_41 ( struct V_55 * V_56 , T_1 * V_54 )
{
struct V_57 * V_58 ;
F_42 ( & V_56 -> V_59 ) ;
for ( V_58 = V_56 -> V_60 ; V_58 ; V_58 = V_58 -> V_61 )
F_37 ( V_58 -> V_62 , V_54 , V_44 ) ;
F_43 ( & V_56 -> V_59 ) ;
}
static int F_44 ( struct V_57 * V_58 , T_2 * V_63 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_3 * V_67 ;
T_3 * V_68 ;
T_4 * V_69 ;
V_67 = V_68 = F_45 ( V_58 -> V_70 , V_63 , V_64 , & V_69 ) ;
do {
struct V_71 * V_71 ;
int V_72 ;
if ( ! F_46 ( * V_68 ) )
continue;
V_71 = F_47 ( V_58 , V_64 , * V_68 ) ;
if ( ! V_71 )
continue;
if ( F_48 ( V_71 ) )
continue;
V_72 = F_49 ( V_71 ) ;
if ( F_33 ( V_72 , * V_18 ) == ! ! ( V_12 & V_73 ) )
continue;
if ( V_12 & ( V_74 | V_75 ) )
F_50 ( V_71 , V_66 , V_12 ) ;
else
break;
} while ( V_68 ++ , V_64 += V_76 , V_64 != V_65 );
F_51 ( V_67 , V_69 ) ;
return V_64 != V_65 ;
}
static void F_52 ( struct V_57 * V_58 ,
T_2 * V_63 , const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
#ifdef F_53
int V_72 ;
struct V_71 * V_71 ;
T_4 * V_69 ;
V_69 = F_54 ( F_55 ( V_58 ) , V_58 -> V_70 , ( T_3 * ) V_63 ) ;
V_71 = F_56 ( F_57 ( ( T_3 * ) V_63 ) ) ;
V_72 = F_49 ( V_71 ) ;
if ( F_33 ( V_72 , * V_18 ) == ! ! ( V_12 & V_73 ) )
goto V_77;
if ( V_12 & ( V_75 ) ||
( V_12 & V_74 && F_58 ( V_71 ) == 1 ) )
F_59 ( V_71 , V_66 ) ;
V_77:
F_60 ( V_69 ) ;
#else
F_31 () ;
#endif
}
static inline int F_61 ( struct V_57 * V_58 , T_5 * V_78 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_2 * V_63 ;
unsigned long V_79 ;
V_63 = F_62 ( V_78 , V_64 ) ;
do {
V_79 = F_63 ( V_64 , V_65 ) ;
if ( ! F_64 ( * V_63 ) )
continue;
if ( F_65 ( * V_63 ) && F_66 ( V_58 ) ) {
F_52 ( V_58 , V_63 , V_18 ,
V_12 , V_66 ) ;
continue;
}
F_67 ( V_58 , V_64 , V_63 ) ;
if ( F_68 ( V_63 ) )
continue;
if ( F_44 ( V_58 , V_63 , V_64 , V_79 , V_18 ,
V_12 , V_66 ) )
return - V_80 ;
} while ( V_63 ++ , V_64 = V_79 , V_64 != V_65 );
return 0 ;
}
static inline int F_69 ( struct V_57 * V_58 , T_6 * V_81 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_5 * V_78 ;
unsigned long V_79 ;
V_78 = F_70 ( V_81 , V_64 ) ;
do {
V_79 = F_71 ( V_64 , V_65 ) ;
if ( F_72 ( * V_78 ) && F_66 ( V_58 ) )
continue;
if ( F_73 ( V_78 ) )
continue;
if ( F_61 ( V_58 , V_78 , V_64 , V_79 , V_18 ,
V_12 , V_66 ) )
return - V_80 ;
} while ( V_78 ++ , V_64 = V_79 , V_64 != V_65 );
return 0 ;
}
static inline int F_74 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_6 * V_81 ;
unsigned long V_79 ;
V_81 = F_75 ( V_58 -> V_70 , V_64 ) ;
do {
V_79 = F_76 ( V_64 , V_65 ) ;
if ( F_77 ( V_81 ) )
continue;
if ( F_69 ( V_58 , V_81 , V_64 , V_79 , V_18 ,
V_12 , V_66 ) )
return - V_80 ;
} while ( V_81 ++ , V_64 = V_79 , V_64 != V_65 );
return 0 ;
}
unsigned long F_78 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_82 ;
V_82 = F_79 ( V_58 , V_64 , V_65 , V_58 -> V_83 , 0 , 1 ) ;
if ( V_82 )
F_80 ( V_84 , V_82 ) ;
return V_82 ;
}
static unsigned long F_78 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static struct V_57 *
F_81 ( struct V_55 * V_56 , unsigned long V_85 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_86 ;
struct V_57 * V_87 , * V_58 , * V_88 ;
V_87 = F_82 ( V_56 , V_85 ) ;
if ( ! V_87 )
return F_22 ( - V_89 ) ;
V_88 = NULL ;
for ( V_58 = V_87 ; V_58 && V_58 -> V_90 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_91 = V_58 -> V_92 ;
if ( V_91 > V_65 )
V_91 = V_65 ;
if ( V_58 -> V_90 > V_85 )
V_85 = V_58 -> V_90 ;
if ( ! ( V_12 & V_93 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_92 < V_65 )
return F_22 ( - V_89 ) ;
if ( V_88 && V_88 -> V_92 < V_58 -> V_90 )
return F_22 ( - V_89 ) ;
}
if ( V_12 & V_94 ) {
F_78 ( V_58 , V_85 , V_91 ) ;
goto V_79;
}
if ( ( V_12 & V_95 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_83 ( V_58 ) ) ) {
V_86 = F_74 ( V_58 , V_85 , V_91 , V_18 ,
V_12 , V_66 ) ;
if ( V_86 ) {
V_87 = F_22 ( V_86 ) ;
break;
}
}
V_79:
V_88 = V_58 ;
}
return V_87 ;
}
static int F_84 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_86 ;
struct V_1 * V_96 ;
struct V_1 * V_54 ;
F_20 ( L_2 ,
V_58 -> V_90 , V_58 -> V_92 , V_58 -> V_97 ,
V_58 -> V_98 , V_58 -> V_99 ,
V_58 -> V_98 ? V_58 -> V_98 -> V_100 : NULL ) ;
V_54 = F_85 ( V_4 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_58 -> V_98 && V_58 -> V_98 -> V_100 ) {
V_86 = V_58 -> V_98 -> V_100 ( V_58 , V_54 ) ;
if ( V_86 )
goto V_101;
}
V_96 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_88 ( V_96 ) ;
return 0 ;
V_101:
F_88 ( V_54 ) ;
return V_86 ;
}
static int F_89 ( struct V_55 * V_56 , unsigned long V_85 ,
unsigned long V_65 , struct V_1 * V_102 )
{
struct V_57 * V_79 ;
struct V_57 * V_88 ;
struct V_57 * V_58 ;
int V_86 = 0 ;
T_7 V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_58 = F_82 ( V_56 , V_85 ) ;
if ( ! V_58 || V_58 -> V_90 > V_85 )
return - V_89 ;
V_88 = V_58 -> V_106 ;
if ( V_85 > V_58 -> V_90 )
V_88 = V_58 ;
for (; V_58 && V_58 -> V_90 < V_65 ; V_88 = V_58 , V_58 = V_79 ) {
V_79 = V_58 -> V_61 ;
V_104 = F_90 ( V_85 , V_58 -> V_90 ) ;
V_105 = F_91 ( V_65 , V_58 -> V_92 ) ;
if ( F_92 ( F_93 ( V_58 ) , V_102 ) )
continue;
V_103 = V_58 -> V_97 +
( ( V_104 - V_58 -> V_90 ) >> V_107 ) ;
V_88 = F_94 ( V_56 , V_88 , V_104 , V_105 , V_58 -> V_108 ,
V_58 -> V_109 , V_58 -> V_99 , V_103 ,
V_102 ) ;
if ( V_88 ) {
V_58 = V_88 ;
V_79 = V_58 -> V_61 ;
if ( F_92 ( F_93 ( V_58 ) , V_102 ) )
continue;
goto V_110;
}
if ( V_58 -> V_90 != V_104 ) {
V_86 = F_95 ( V_58 -> V_70 , V_58 , V_104 , 1 ) ;
if ( V_86 )
goto V_111;
}
if ( V_58 -> V_92 != V_105 ) {
V_86 = F_95 ( V_58 -> V_70 , V_58 , V_105 , 0 ) ;
if ( V_86 )
goto V_111;
}
V_110:
V_86 = F_84 ( V_58 , V_102 ) ;
if ( V_86 )
goto V_111;
}
V_111:
return V_86 ;
}
void F_96 ( struct V_2 * V_3 )
{
if ( V_3 -> V_1 )
V_3 -> V_12 |= V_112 ;
else
V_3 -> V_12 &= ~ V_112 ;
}
static void F_97 ( void )
{
F_96 ( V_47 ) ;
}
static long F_98 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_96 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_99 ( V_113 ) ;
int V_14 ;
if ( ! V_113 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_86 ( V_54 ) ) {
V_14 = F_87 ( V_54 ) ;
goto V_111;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_100 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_113 ) ;
if ( V_14 ) {
F_101 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_54 ) ;
goto V_111;
}
V_96 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
F_97 () ;
if ( V_54 && V_54 -> V_8 == V_114 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_101 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_96 ) ;
V_14 = 0 ;
V_111:
F_102 ( V_113 ) ;
return V_14 ;
}
static void F_103 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_104 ( * V_18 ) ;
if ( V_3 == & V_115 )
return;
switch ( V_3 -> V_8 ) {
case V_116 :
case V_114 :
* V_18 = V_3 -> V_20 . V_18 ;
break;
case V_27 :
if ( ! ( V_3 -> V_12 & V_21 ) )
F_105 ( V_3 -> V_20 . V_22 , * V_18 ) ;
break;
default:
F_31 () ;
}
}
static int F_106 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_71 * V_3 ;
int V_86 ;
V_86 = F_107 ( V_47 , V_56 , V_64 & V_117 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_49 ( V_3 ) ;
F_108 ( V_3 ) ;
}
return V_86 ;
}
static long F_109 ( int * V_34 , T_1 * V_118 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_86 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_12 &
~ ( unsigned long ) ( V_119 | V_120 | V_121 ) )
return - V_19 ;
if ( V_12 & V_121 ) {
if ( V_12 & ( V_119 | V_120 ) )
return - V_19 ;
* V_34 = 0 ;
F_100 ( V_47 ) ;
* V_118 = V_26 ;
F_101 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_120 ) {
F_110 ( & V_56 -> V_59 ) ;
V_58 = F_111 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_112 ( & V_56 -> V_59 ) ;
return - V_89 ;
}
if ( V_58 -> V_98 && V_58 -> V_98 -> V_122 )
V_4 = V_58 -> V_98 -> V_122 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_115 ;
if ( V_12 & V_119 ) {
if ( V_12 & V_120 ) {
V_86 = F_106 ( V_56 , V_64 ) ;
if ( V_86 < 0 )
goto V_111;
* V_34 = V_86 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_114 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_86 = - V_19 ;
goto V_111;
}
} else {
* V_34 = V_4 == & V_115 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_112 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_86 = 0 ;
if ( V_118 ) {
if ( F_5 ( V_4 ) ) {
* V_118 = V_4 -> V_30 . V_31 ;
} else {
F_100 ( V_47 ) ;
F_103 ( V_4 , V_118 ) ;
F_101 ( V_47 ) ;
}
}
V_111:
F_113 ( V_4 ) ;
if ( V_58 )
F_112 ( & V_47 -> V_56 -> V_59 ) ;
return V_86 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_123 * V_124 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_58 ( V_71 ) == 1 ) {
if ( ! F_114 ( V_71 ) ) {
F_115 ( & V_71 -> V_125 , V_124 ) ;
F_116 ( V_71 , V_126 +
F_117 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_118 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_127 )
{
if ( F_119 ( V_71 ) )
return F_120 ( F_121 ( F_122 ( V_71 ) ) ,
V_5 ) ;
else
return F_123 ( V_5 , V_128 , 0 ) ;
}
static int F_124 ( struct V_55 * V_56 , int V_129 , int V_130 ,
int V_12 )
{
T_1 V_118 ;
F_125 ( V_124 ) ;
int V_86 = 0 ;
F_104 ( V_118 ) ;
F_105 ( V_129 , V_118 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_81 ( V_56 , V_56 -> V_60 -> V_90 , V_56 -> V_131 , & V_118 ,
V_12 | V_93 , & V_124 ) ;
if ( ! F_126 ( & V_124 ) ) {
V_86 = F_127 ( & V_124 , F_118 , V_130 ,
V_132 , V_133 ) ;
if ( V_86 )
F_128 ( & V_124 ) ;
}
return V_86 ;
}
int F_129 ( struct V_55 * V_56 , const T_1 * V_134 ,
const T_1 * V_135 , int V_12 )
{
int V_136 = 0 ;
int V_86 ;
T_1 V_17 ;
V_86 = F_130 () ;
if ( V_86 )
return V_86 ;
F_110 ( & V_56 -> V_59 ) ;
V_86 = F_131 ( V_56 , V_134 , V_135 , V_12 ) ;
if ( V_86 )
goto V_111;
V_17 = * V_134 ;
while ( ! F_11 ( V_17 ) ) {
int V_137 , V_138 ;
int V_129 = V_6 ;
int V_130 = 0 ;
F_132 (s, tmp) {
if ( ( F_8 ( * V_134 ) != F_8 ( * V_135 ) ) &&
( F_33 ( V_137 , * V_135 ) ) )
continue;
V_138 = F_36 ( V_137 , * V_134 , * V_135 ) ;
if ( V_137 == V_138 )
continue;
V_129 = V_137 ;
V_130 = V_138 ;
if ( ! F_33 ( V_130 , V_17 ) )
break;
}
if ( V_129 == V_6 )
break;
F_133 ( V_129 , V_17 ) ;
V_86 = F_124 ( V_56 , V_129 , V_130 , V_12 ) ;
if ( V_86 > 0 )
V_136 += V_86 ;
if ( V_86 < 0 )
break;
}
V_111:
F_112 ( & V_56 -> V_59 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_136 ;
}
static struct V_71 * F_134 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_127 )
{
struct V_57 * V_58 = (struct V_57 * ) V_66 ;
unsigned long V_139 ( V_140 ) ;
while ( V_58 ) {
V_140 = F_135 ( V_71 , V_58 ) ;
if ( V_140 != - V_89 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_119 ( V_71 ) ) {
F_136 ( ! V_58 ) ;
return F_137 ( V_58 , V_140 , 1 ) ;
}
return F_138 ( V_128 , V_58 , V_140 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_123 * V_124 ,
unsigned long V_12 )
{
}
int F_129 ( struct V_55 * V_56 , const T_1 * V_134 ,
const T_1 * V_135 , int V_12 )
{
return - V_141 ;
}
static struct V_71 * F_134 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_127 )
{
return NULL ;
}
static long F_139 ( unsigned long V_85 , unsigned long V_142 ,
unsigned short V_8 , unsigned short V_143 ,
T_1 * V_118 , unsigned long V_12 )
{
struct V_57 * V_58 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_86 ;
F_125 ( V_124 ) ;
if ( V_12 & ~ ( unsigned long ) V_144 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_140 ( V_145 ) )
return - V_146 ;
if ( V_85 & ~ V_117 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_95 ;
V_142 = ( V_142 + V_76 - 1 ) & V_117 ;
V_65 = V_85 + V_142 ;
if ( V_65 < V_85 )
return - V_19 ;
if ( V_65 == V_85 )
return 0 ;
V_54 = F_19 ( V_8 , V_143 , V_118 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_12 & V_94 )
V_54 -> V_12 |= V_147 ;
if ( ! V_54 )
V_12 |= V_93 ;
F_20 ( L_3 ,
V_85 , V_85 + V_142 , V_8 , V_143 ,
V_118 ? F_21 ( * V_118 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_86 = F_130 () ;
if ( V_86 )
goto V_148;
}
{
F_99 ( V_113 ) ;
if ( V_113 ) {
F_42 ( & V_56 -> V_59 ) ;
F_100 ( V_47 ) ;
V_86 = F_15 ( V_54 , V_118 , V_113 ) ;
F_101 ( V_47 ) ;
if ( V_86 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_86 = - V_40 ;
F_102 ( V_113 ) ;
}
if ( V_86 )
goto V_148;
V_58 = F_81 ( V_56 , V_85 , V_65 , V_118 ,
V_12 | V_73 , & V_124 ) ;
V_86 = F_87 ( V_58 ) ;
if ( ! F_86 ( V_58 ) )
V_86 = F_89 ( V_56 , V_85 , V_65 , V_54 ) ;
if ( ! V_86 ) {
int V_149 = 0 ;
if ( ! F_126 ( & V_124 ) ) {
F_141 ( V_12 & V_94 ) ;
V_149 = F_127 ( & V_124 , F_134 ,
( unsigned long ) V_58 ,
V_132 , V_150 ) ;
if ( V_149 )
F_128 ( & V_124 ) ;
}
if ( V_149 && ( V_12 & V_95 ) )
V_86 = - V_80 ;
} else
F_128 ( & V_124 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_148:
F_88 ( V_54 ) ;
return V_86 ;
}
static int F_142 ( T_1 * V_18 , const unsigned long T_8 * V_118 ,
unsigned long V_151 )
{
unsigned long V_152 ;
unsigned long V_153 ;
unsigned long V_154 ;
-- V_151 ;
F_104 ( * V_18 ) ;
if ( V_151 == 0 || ! V_118 )
return 0 ;
if ( V_151 > V_76 * V_155 )
return - V_19 ;
V_153 = F_143 ( V_151 ) ;
if ( ( V_151 % V_156 ) == 0 )
V_154 = ~ 0UL ;
else
V_154 = ( 1UL << ( V_151 % V_156 ) ) - 1 ;
if ( V_153 > F_143 ( V_49 ) ) {
if ( V_153 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_152 = F_143 ( V_49 ) ; V_152 < V_153 ; V_152 ++ ) {
unsigned long V_157 ;
if ( F_144 ( V_157 , V_118 + V_152 ) )
return - V_89 ;
if ( V_152 == V_153 - 1 ) {
if ( V_157 & V_154 )
return - V_19 ;
} else if ( V_157 )
return - V_19 ;
}
V_153 = F_143 ( V_49 ) ;
V_154 = ~ 0UL ;
}
if ( F_145 ( F_21 ( * V_18 ) , V_118 , V_153 *sizeof( unsigned long ) ) )
return - V_89 ;
F_21 ( * V_18 ) [ V_153 - 1 ] &= V_154 ;
return 0 ;
}
static int F_146 ( unsigned long T_8 * V_158 , unsigned long V_151 ,
T_1 * V_18 )
{
unsigned long V_159 = F_147 ( V_151 - 1 , 64 ) / 8 ;
const int V_160 = F_143 ( V_49 ) * sizeof( long ) ;
if ( V_159 > V_160 ) {
if ( V_159 > V_76 )
return - V_19 ;
if ( F_148 ( ( char T_8 * ) V_158 + V_160 , V_159 - V_160 ) )
return - V_89 ;
V_159 = V_160 ;
}
return F_149 ( V_158 , F_21 ( * V_18 ) , V_159 ) ? - V_89 : 0 ;
}
T_9 long F_150 ( int T_8 * V_34 ,
T_10 T_8 * V_118 ,
T_10 V_151 ,
T_10 V_64 , T_10 V_12 )
{
long V_86 ;
unsigned long T_8 * V_161 = NULL ;
unsigned long V_162 , V_163 ;
F_151 ( V_164 , V_49 ) ;
V_162 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_163 = F_147 ( V_162 , V_156 ) / 8 ;
if ( V_118 )
V_161 = F_153 ( V_163 ) ;
V_86 = F_154 ( V_34 , V_161 , V_162 + 1 , V_64 , V_12 ) ;
if ( ! V_86 && V_118 ) {
unsigned long V_165 ;
V_165 = F_152 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_145 ( V_164 , V_161 , V_165 ) ;
V_86 |= F_148 ( V_118 , F_147 ( V_151 - 1 , 8 ) / 8 ) ;
V_86 |= F_155 ( V_118 , V_164 , V_162 ) ;
}
return V_86 ;
}
T_9 long F_156 ( int V_8 , T_10 T_8 * V_118 ,
T_10 V_151 )
{
long V_86 = 0 ;
unsigned long T_8 * V_161 = NULL ;
unsigned long V_162 , V_163 ;
F_151 ( V_164 , V_49 ) ;
V_162 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_163 = F_147 ( V_162 , V_156 ) / 8 ;
if ( V_118 ) {
V_86 = F_157 ( V_164 , V_118 , V_162 ) ;
V_161 = F_153 ( V_163 ) ;
V_86 |= F_149 ( V_161 , V_164 , V_163 ) ;
}
if ( V_86 )
return - V_89 ;
return F_158 ( V_8 , V_161 , V_162 + 1 ) ;
}
T_9 long F_159 ( T_10 V_85 , T_10 V_142 ,
T_10 V_8 , T_10 T_8 * V_118 ,
T_10 V_151 , T_10 V_12 )
{
long V_86 = 0 ;
unsigned long T_8 * V_161 = NULL ;
unsigned long V_162 , V_163 ;
T_1 V_164 ;
V_162 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_163 = F_147 ( V_162 , V_156 ) / 8 ;
if ( V_118 ) {
V_86 = F_157 ( F_21 ( V_164 ) , V_118 , V_162 ) ;
V_161 = F_153 ( V_163 ) ;
V_86 |= F_149 ( V_161 , F_21 ( V_164 ) , V_163 ) ;
}
if ( V_86 )
return - V_89 ;
return F_160 ( V_85 , V_142 , V_8 , V_161 , V_162 + 1 , V_12 ) ;
}
struct V_1 * F_161 ( struct V_2 * V_166 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_166 ) ;
if ( V_58 ) {
if ( V_58 -> V_98 && V_58 -> V_98 -> V_122 ) {
struct V_1 * V_167 = V_58 -> V_98 -> V_122 ( V_58 ,
V_64 ) ;
if ( V_167 )
V_4 = V_167 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_162 ( V_4 ) )
F_163 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_115 ;
return V_4 ;
}
bool F_164 ( struct V_2 * V_166 , struct V_57 * V_58 )
{
struct V_1 * V_4 = F_1 ( V_166 ) ;
if ( V_58 ) {
if ( V_58 -> V_98 && V_58 -> V_98 -> V_122 ) {
bool V_14 = false ;
V_4 = V_58 -> V_98 -> V_122 ( V_58 , V_58 -> V_90 ) ;
if ( V_4 && ( V_4 -> V_12 & V_147 ) )
V_14 = true ;
F_113 ( V_4 ) ;
return V_14 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
}
}
if ( ! V_4 )
return V_115 . V_12 & V_147 ;
return V_4 -> V_12 & V_147 ;
}
static int F_165 ( struct V_1 * V_34 , enum V_168 V_169 )
{
enum V_168 V_170 = V_171 ;
F_136 ( V_170 == V_172 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_173 ] ) )
V_170 = V_172 ;
return V_169 >= V_170 ;
}
static T_1 * F_166 ( T_11 V_174 , struct V_1 * V_34 )
{
if ( F_167 ( V_34 -> V_8 == V_116 ) &&
F_165 ( V_34 , F_168 ( V_174 ) ) &&
F_169 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_175 * F_170 ( T_11 V_174 , struct V_1 * V_34 ,
int V_176 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_176 = V_34 -> V_20 . V_22 ;
break;
case V_116 :
if ( F_167 ( V_174 & V_177 ) &&
F_167 ( ! F_33 ( V_176 , V_34 -> V_20 . V_18 ) ) )
V_176 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_171 ( V_176 , V_174 ) ;
}
static unsigned F_172 ( struct V_1 * V_34 )
{
unsigned V_72 , V_79 ;
struct V_2 * V_178 = V_47 ;
V_72 = V_178 -> V_48 ;
V_79 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_79 >= V_49 )
V_79 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_79 < V_49 )
V_178 -> V_48 = V_79 ;
return V_72 ;
}
unsigned F_173 ( void )
{
struct V_1 * V_34 ;
if ( F_174 () )
return F_2 () ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_12 & V_21 )
return F_2 () ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_20 . V_22 ;
case V_114 :
return F_172 ( V_34 ) ;
case V_116 : {
struct V_175 * V_175 ;
struct V_169 * V_169 ;
enum V_168 V_179 = F_168 ( V_39 ) ;
V_175 = & F_175 ( F_2 () ) -> V_180 [ 0 ] ;
( void ) F_176 ( V_175 , V_179 ,
& V_34 -> V_20 . V_18 ,
& V_169 ) ;
return V_169 ? V_169 -> V_5 : F_2 () ;
}
default:
F_31 () ;
}
}
static unsigned F_177 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_181 )
{
unsigned V_182 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_183 ;
int V_184 ;
int V_72 = V_6 ;
if ( ! V_182 )
return F_2 () ;
V_183 = ( unsigned int ) V_181 % V_182 ;
V_184 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_184 ++ ;
} while ( V_184 <= V_183 );
return V_72 ;
}
static inline unsigned F_178 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_185 )
{
if ( V_58 ) {
unsigned long V_181 ;
F_136 ( V_185 < V_107 ) ;
V_181 = V_58 -> V_97 >> ( V_185 - V_107 ) ;
V_181 += ( V_64 - V_58 -> V_90 ) >> V_185 ;
return F_177 ( V_4 , V_58 , V_181 ) ;
} else
return F_172 ( V_4 ) ;
}
int F_179 ( const T_1 * V_186 )
{
int V_30 , V_187 = V_6 ;
V_30 = F_8 ( * V_186 ) ;
if ( V_30 )
V_187 = F_180 ( V_186 -> V_188 ,
F_181 () % V_30 , V_49 ) ;
return V_187 ;
}
struct V_175 * F_182 ( struct V_57 * V_58 , unsigned long V_64 ,
T_11 V_189 , struct V_1 * * V_190 ,
T_1 * * V_9 )
{
struct V_175 * V_191 ;
* V_190 = F_161 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_167 ( ( * V_190 ) -> V_8 == V_114 ) ) {
V_191 = F_171 ( F_178 ( * V_190 , V_58 , V_64 ,
F_183 ( F_55 ( V_58 ) ) ) , V_189 ) ;
} else {
V_191 = F_170 ( V_189 , * V_190 , F_2 () ) ;
if ( ( * V_190 ) -> V_8 == V_116 )
* V_9 = & ( * V_190 ) -> V_20 . V_18 ;
}
return V_191 ;
}
bool F_184 ( T_1 * V_158 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_158 && V_47 -> V_1 ) )
return false ;
F_100 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_185 ( V_158 , V_72 ) ;
break;
case V_116 :
case V_114 :
* V_158 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_101 ( V_47 ) ;
return true ;
}
bool F_186 ( struct V_2 * V_53 ,
const T_1 * V_158 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_158 )
return V_14 ;
F_100 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_111;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_116 :
case V_114 :
V_14 = F_4 ( V_1 -> V_20 . V_18 , * V_158 ) ;
break;
default:
F_31 () ;
}
V_111:
F_101 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_187 ( T_11 V_174 , unsigned V_192 ,
unsigned V_72 )
{
struct V_175 * V_191 ;
struct V_71 * V_71 ;
V_191 = F_171 ( V_72 , V_174 ) ;
V_71 = F_188 ( V_174 , V_192 , V_191 ) ;
if ( V_71 && F_189 ( V_71 ) == F_190 ( & V_191 -> V_193 [ 0 ] ) )
F_116 ( V_71 , V_194 ) ;
return V_71 ;
}
struct V_71 *
F_191 ( T_11 V_174 , int V_192 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_195 ;
V_196:
V_4 = F_161 ( V_47 , V_58 , V_64 ) ;
V_195 = F_192 () ;
if ( F_167 ( V_4 -> V_8 == V_114 ) ) {
unsigned V_72 ;
V_72 = F_178 ( V_4 , V_58 , V_64 , V_107 + V_192 ) ;
F_113 ( V_4 ) ;
V_71 = F_187 ( V_174 , V_192 , V_72 ) ;
if ( F_167 ( ! F_193 ( V_195 ) && ! V_71 ) )
goto V_196;
return V_71 ;
}
V_71 = F_194 ( V_174 , V_192 ,
F_170 ( V_174 , V_4 , V_5 ) ,
F_166 ( V_174 , V_4 ) ) ;
if ( F_167 ( F_162 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_167 ( ! F_193 ( V_195 ) && ! V_71 ) )
goto V_196;
return V_71 ;
}
struct V_71 * F_195 ( T_11 V_174 , unsigned V_192 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_195 ;
if ( ! V_4 || F_174 () || ( V_174 & V_177 ) )
V_4 = & V_115 ;
V_196:
V_195 = F_192 () ;
if ( V_4 -> V_8 == V_114 )
V_71 = F_187 ( V_174 , V_192 , F_172 ( V_4 ) ) ;
else
V_71 = F_194 ( V_174 , V_192 ,
F_170 ( V_174 , V_4 , F_2 () ) ,
F_166 ( V_174 , V_4 ) ) ;
if ( F_167 ( ! F_193 ( V_195 ) && ! V_71 ) )
goto V_196;
return V_71 ;
}
int F_196 ( struct V_57 * V_197 , struct V_57 * V_198 )
{
struct V_1 * V_4 = F_85 ( F_93 ( V_197 ) ) ;
if ( F_86 ( V_4 ) )
return F_87 ( V_4 ) ;
V_198 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_197 ( struct V_1 * V_96 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_96 == V_47 -> V_1 ) {
F_100 ( V_47 ) ;
* V_54 = * V_96 ;
F_101 ( V_47 ) ;
} else
* V_54 = * V_96 ;
F_198 () ;
if ( F_199 () ) {
T_1 V_199 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_199 , V_46 ) ;
else
F_37 ( V_54 , & V_199 , V_44 ) ;
}
F_200 () ;
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_201 ( struct V_1 * V_200 , struct V_1 * V_201 )
{
if ( ! V_200 || ! V_201 )
return false ;
if ( V_200 -> V_8 != V_201 -> V_8 )
return false ;
if ( V_200 -> V_12 != V_201 -> V_12 )
return false ;
if ( F_5 ( V_200 ) )
if ( ! F_38 ( V_200 -> V_30 . V_31 , V_201 -> V_30 . V_31 ) )
return false ;
switch ( V_200 -> V_8 ) {
case V_116 :
case V_114 :
return ! ! F_38 ( V_200 -> V_20 . V_18 , V_201 -> V_20 . V_18 ) ;
case V_27 :
return V_200 -> V_20 . V_22 == V_201 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_202 *
F_202 ( struct V_203 * V_204 , unsigned long V_85 , unsigned long V_65 )
{
struct V_205 * V_206 = V_204 -> V_207 . V_205 ;
while ( V_206 ) {
struct V_202 * V_3 = F_203 ( V_206 , struct V_202 , V_176 ) ;
if ( V_85 >= V_3 -> V_65 )
V_206 = V_206 -> V_208 ;
else if ( V_65 <= V_3 -> V_85 )
V_206 = V_206 -> V_209 ;
else
break;
}
if ( ! V_206 )
return NULL ;
for (; ; ) {
struct V_202 * V_30 = NULL ;
struct V_205 * V_88 = F_204 ( V_206 ) ;
if ( ! V_88 )
break;
V_30 = F_203 ( V_88 , struct V_202 , V_176 ) ;
if ( V_30 -> V_65 <= V_85 )
break;
V_206 = V_88 ;
}
return F_203 ( V_206 , struct V_202 , V_176 ) ;
}
static void F_205 ( struct V_203 * V_204 , struct V_202 * V_54 )
{
struct V_205 * * V_3 = & V_204 -> V_207 . V_205 ;
struct V_205 * V_210 = NULL ;
struct V_202 * V_176 ;
while ( * V_3 ) {
V_210 = * V_3 ;
V_176 = F_203 ( V_210 , struct V_202 , V_176 ) ;
if ( V_54 -> V_85 < V_176 -> V_85 )
V_3 = & ( * V_3 ) -> V_209 ;
else if ( V_54 -> V_65 > V_176 -> V_65 )
V_3 = & ( * V_3 ) -> V_208 ;
else
F_31 () ;
}
F_206 ( & V_54 -> V_176 , V_210 , V_3 ) ;
F_207 ( & V_54 -> V_176 , & V_204 -> V_207 ) ;
F_20 ( L_4 , V_54 -> V_85 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_208 ( struct V_203 * V_204 , unsigned long V_211 )
{
struct V_1 * V_4 = NULL ;
struct V_202 * V_212 ;
if ( ! V_204 -> V_207 . V_205 )
return NULL ;
F_209 ( & V_204 -> V_213 ) ;
V_212 = F_202 ( V_204 , V_211 , V_211 + 1 ) ;
if ( V_212 ) {
F_163 ( V_212 -> V_34 ) ;
V_4 = V_212 -> V_34 ;
}
F_60 ( & V_204 -> V_213 ) ;
return V_4 ;
}
static void F_210 ( struct V_202 * V_206 )
{
F_88 ( V_206 -> V_34 ) ;
F_27 ( V_214 , V_206 ) ;
}
static bool F_211 ( struct V_2 * V_3 , int V_215 )
{
if ( F_212 ( V_3 , V_215 ) )
return false ;
if ( V_3 -> F_211 ) {
V_3 -> F_211 -- ;
return true ;
}
return false ;
}
static inline void F_213 ( struct V_2 * V_3 )
{
V_3 -> F_211 = V_216 ;
}
static inline bool F_211 ( struct V_2 * V_3 , int V_215 )
{
return false ;
}
static inline void F_213 ( struct V_2 * V_3 )
{
}
int F_214 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_169 * V_169 ;
int V_217 = F_49 ( V_71 ) ;
unsigned long V_103 ;
int V_218 = F_215 () ;
int V_219 = F_216 ( V_218 ) ;
int V_220 = - 1 ;
int V_14 = - 1 ;
F_136 ( ! V_58 ) ;
V_4 = F_161 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_147 ) )
goto V_111;
switch ( V_4 -> V_8 ) {
case V_114 :
F_136 ( V_64 >= V_58 -> V_92 ) ;
F_136 ( V_64 < V_58 -> V_90 ) ;
V_103 = V_58 -> V_97 ;
V_103 += ( V_64 - V_58 -> V_90 ) >> V_107 ;
V_220 = F_177 ( V_4 , V_58 , V_103 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_220 = F_2 () ;
else
V_220 = V_4 -> V_20 . V_22 ;
break;
case V_116 :
if ( F_33 ( V_217 , V_4 -> V_20 . V_18 ) )
goto V_111;
( void ) F_176 (
F_171 ( F_2 () , V_221 ) ,
F_168 ( V_221 ) ,
& V_4 -> V_20 . V_18 , & V_169 ) ;
V_220 = V_169 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_222 ) {
int V_215 ;
int V_223 ;
V_220 = V_219 ;
V_223 = F_217 ( V_218 , V_47 -> V_224 ) ;
V_215 = F_218 ( V_71 , V_223 ) ;
if ( ! F_219 ( V_215 ) && F_220 ( V_215 ) != V_219 ) {
if ( ! F_212 ( V_47 , V_215 ) )
F_213 ( V_47 ) ;
goto V_111;
}
if ( F_211 ( V_47 , V_215 ) )
goto V_111;
}
if ( V_217 != V_220 )
V_14 = V_220 ;
V_111:
F_113 ( V_4 ) ;
return V_14 ;
}
static void F_221 ( struct V_203 * V_204 , struct V_202 * V_206 )
{
F_20 ( L_5 , V_206 -> V_85 , V_206 -> V_65 ) ;
F_222 ( & V_206 -> V_176 , & V_204 -> V_207 ) ;
F_210 ( V_206 ) ;
}
static void F_223 ( struct V_202 * V_5 , unsigned long V_85 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_85 = V_85 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_202 * F_224 ( unsigned long V_85 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_202 * V_206 ;
struct V_1 * V_225 ;
V_206 = F_23 ( V_214 , V_39 ) ;
if ( ! V_206 )
return NULL ;
V_225 = F_85 ( V_4 ) ;
if ( F_86 ( V_225 ) ) {
F_27 ( V_214 , V_206 ) ;
return NULL ;
}
V_225 -> V_12 |= V_226 ;
F_223 ( V_206 , V_85 , V_65 , V_225 ) ;
return V_206 ;
}
static int F_225 ( struct V_203 * V_204 , unsigned long V_85 ,
unsigned long V_65 , struct V_202 * V_54 )
{
struct V_202 * V_206 ;
struct V_202 * V_227 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_228:
F_209 ( & V_204 -> V_213 ) ;
V_206 = F_202 ( V_204 , V_85 , V_65 ) ;
while ( V_206 && V_206 -> V_85 < V_65 ) {
struct V_205 * V_79 = F_226 ( & V_206 -> V_176 ) ;
if ( V_206 -> V_85 >= V_85 ) {
if ( V_206 -> V_65 <= V_65 )
F_221 ( V_204 , V_206 ) ;
else
V_206 -> V_85 = V_65 ;
} else {
if ( V_206 -> V_65 > V_65 ) {
if ( ! V_227 )
goto V_229;
* F_19 = * V_206 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_223 ( V_227 , V_65 , V_206 -> V_65 , F_19 ) ;
V_206 -> V_65 = V_85 ;
F_205 ( V_204 , V_227 ) ;
V_227 = NULL ;
F_19 = NULL ;
break;
} else
V_206 -> V_65 = V_85 ;
}
if ( ! V_79 )
break;
V_206 = F_203 ( V_79 , struct V_202 , V_176 ) ;
}
if ( V_54 )
F_205 ( V_204 , V_54 ) ;
F_60 ( & V_204 -> V_213 ) ;
V_14 = 0 ;
V_101:
if ( F_19 )
F_88 ( F_19 ) ;
if ( V_227 )
F_27 ( V_214 , V_227 ) ;
return V_14 ;
V_229:
F_60 ( & V_204 -> V_213 ) ;
V_14 = - V_40 ;
V_227 = F_23 ( V_214 , V_39 ) ;
if ( ! V_227 )
goto V_101;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_101;
goto V_228;
}
void F_227 ( struct V_203 * V_204 , struct V_1 * V_190 )
{
int V_14 ;
V_204 -> V_207 = V_230 ;
F_228 ( & V_204 -> V_213 ) ;
if ( V_190 ) {
struct V_57 V_231 ;
struct V_1 * V_54 ;
F_99 ( V_113 ) ;
if ( ! V_113 )
goto V_232;
V_54 = F_19 ( V_190 -> V_8 , V_190 -> V_12 , & V_190 -> V_30 . V_31 ) ;
if ( F_86 ( V_54 ) )
goto V_233;
F_100 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_190 -> V_30 . V_31 , V_113 ) ;
F_101 ( V_47 ) ;
if ( V_14 )
goto V_234;
memset ( & V_231 , 0 , sizeof( struct V_57 ) ) ;
V_231 . V_92 = V_235 ;
F_229 ( V_204 , & V_231 , V_54 ) ;
V_234:
F_88 ( V_54 ) ;
V_233:
F_102 ( V_113 ) ;
V_232:
F_88 ( V_190 ) ;
}
}
int F_229 ( struct V_203 * V_236 ,
struct V_57 * V_58 , struct V_1 * V_237 )
{
int V_86 ;
struct V_202 * V_54 = NULL ;
unsigned long V_238 = F_230 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_97 ,
V_238 , V_237 ? V_237 -> V_8 : - 1 ,
V_237 ? V_237 -> V_12 : - 1 ,
V_237 ? F_21 ( V_237 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_237 ) {
V_54 = F_224 ( V_58 -> V_97 , V_58 -> V_97 + V_238 , V_237 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_86 = F_225 ( V_236 , V_58 -> V_97 , V_58 -> V_97 + V_238 , V_54 ) ;
if ( V_86 && V_54 )
F_210 ( V_54 ) ;
return V_86 ;
}
void F_231 ( struct V_203 * V_3 )
{
struct V_202 * V_206 ;
struct V_205 * V_79 ;
if ( ! V_3 -> V_207 . V_205 )
return;
F_209 ( & V_3 -> V_213 ) ;
V_79 = F_232 ( & V_3 -> V_207 ) ;
while ( V_79 ) {
V_206 = F_203 ( V_79 , struct V_202 , V_176 ) ;
V_79 = F_226 ( & V_206 -> V_176 ) ;
F_221 ( V_3 , V_206 ) ;
}
F_60 ( & V_3 -> V_213 ) ;
}
static void T_12 F_233 ( void )
{
bool V_239 = false ;
if ( F_234 ( V_240 ) )
V_239 = true ;
if ( V_241 )
F_235 ( V_241 == 1 ) ;
if ( V_242 > 1 && ! V_241 ) {
F_236 ( L_7
L_8
L_9 ,
V_239 ? L_10 : L_11 ) ;
F_235 ( V_239 ) ;
}
}
static int T_12 F_237 ( char * V_243 )
{
int V_14 = 0 ;
if ( ! V_243 )
goto V_111;
if ( ! strcmp ( V_243 , L_12 ) ) {
V_241 = 1 ;
V_14 = 1 ;
} else if ( ! strcmp ( V_243 , L_13 ) ) {
V_241 = - 1 ;
V_14 = 1 ;
}
V_111:
if ( ! V_14 )
F_238 ( L_14 ) ;
return V_14 ;
}
static inline void T_12 F_233 ( void )
{
}
void T_12 F_239 ( void )
{
T_1 F_172 ;
unsigned long V_244 = 0 ;
int V_72 , V_245 = 0 ;
V_38 = F_240 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_246 , NULL ) ;
V_214 = F_240 ( L_16 ,
sizeof( struct V_202 ) ,
0 , V_246 , NULL ) ;
F_241 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_242 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_147 | V_222 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_104 ( F_172 ) ;
F_243 (nid, N_MEMORY) {
unsigned long V_247 = F_244 ( V_72 ) ;
if ( V_244 < V_247 ) {
V_244 = V_247 ;
V_245 = V_72 ;
}
if ( ( V_247 << V_107 ) >= ( 16 << 20 ) )
F_105 ( V_72 , F_172 ) ;
}
if ( F_167 ( F_11 ( F_172 ) ) )
F_105 ( V_245 , F_172 ) ;
if ( F_98 ( V_114 , 0 , & F_172 ) )
F_245 ( L_17 ) ;
F_233 () ;
}
void F_246 ( void )
{
F_98 ( V_35 , 0 , NULL ) ;
}
int F_247 ( char * V_243 , struct V_1 * * V_190 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_143 ;
T_1 V_18 ;
char * V_248 = strchr ( V_243 , ':' ) ;
char * V_12 = strchr ( V_243 , '=' ) ;
int V_86 = 1 ;
if ( V_248 ) {
* V_248 ++ = '\0' ;
if ( F_248 ( V_248 , V_18 ) )
goto V_111;
if ( ! F_249 ( V_18 , V_10 [ V_11 ] ) )
goto V_111;
} else
F_104 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_249 ; V_8 ++ ) {
if ( ! strcmp ( V_243 , V_250 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_249 )
goto V_111;
switch ( V_8 ) {
case V_27 :
if ( V_248 ) {
char * V_251 = V_248 ;
while ( isdigit ( * V_251 ) )
V_251 ++ ;
if ( * V_251 )
goto V_111;
}
break;
case V_114 :
if ( ! V_248 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_248 )
goto V_111;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_248 )
V_86 = 0 ;
goto V_111;
case V_116 :
if ( ! V_248 )
goto V_111;
}
V_143 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_18 ) )
V_143 |= V_36 ;
else if ( ! strcmp ( V_12 , L_19 ) )
V_143 |= V_28 ;
else
goto V_111;
}
V_54 = F_19 ( V_8 , V_143 , & V_18 ) ;
if ( F_86 ( V_54 ) )
goto V_111;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_248 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_86 = 0 ;
V_111:
if ( V_248 )
* -- V_248 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_86 )
* V_190 = V_54 ;
return V_86 ;
}
void F_250 ( char * V_252 , int V_253 , struct V_1 * V_4 )
{
char * V_3 = V_252 ;
T_1 V_18 = V_254 ;
unsigned short V_8 = V_35 ;
unsigned short V_12 = 0 ;
if ( V_4 && V_4 != & V_115 && ! ( V_4 -> V_12 & V_222 ) ) {
V_8 = V_4 -> V_8 ;
V_12 = V_4 -> V_12 ;
}
switch ( V_8 ) {
case V_35 :
break;
case V_27 :
if ( V_12 & V_21 )
V_8 = V_37 ;
else
F_105 ( V_4 -> V_20 . V_22 , V_18 ) ;
break;
case V_116 :
case V_114 :
V_18 = V_4 -> V_20 . V_18 ;
break;
default:
F_141 ( 1 ) ;
snprintf ( V_3 , V_253 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_253 , L_21 , V_250 [ V_8 ] ) ;
if ( V_12 & V_13 ) {
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_22 ) ;
if ( V_12 & V_36 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_18 ) ;
else if ( V_12 & V_28 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_19 ) ;
}
if ( ! F_11 ( V_18 ) ) {
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_23 ) ;
V_3 += F_251 ( V_3 , V_252 + V_253 - V_3 , V_18 ) ;
}
}
