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
T_3 V_77 ;
V_69 = F_54 ( F_55 ( V_58 ) , V_58 -> V_70 , ( T_3 * ) V_63 ) ;
V_77 = F_56 ( ( T_3 * ) V_63 ) ;
if ( ! F_46 ( V_77 ) )
goto V_78;
V_71 = F_57 ( V_77 ) ;
V_72 = F_49 ( V_71 ) ;
if ( F_33 ( V_72 , * V_18 ) == ! ! ( V_12 & V_73 ) )
goto V_78;
if ( V_12 & ( V_75 ) ||
( V_12 & V_74 && F_58 ( V_71 ) == 1 ) )
F_59 ( V_71 , V_66 ) ;
V_78:
F_60 ( V_69 ) ;
#else
F_31 () ;
#endif
}
static inline int F_61 ( struct V_57 * V_58 , T_5 * V_79 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_2 * V_63 ;
unsigned long V_80 ;
V_63 = F_62 ( V_79 , V_64 ) ;
do {
V_80 = F_63 ( V_64 , V_65 ) ;
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
if ( F_44 ( V_58 , V_63 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_63 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_69 ( struct V_57 * V_58 , T_6 * V_82 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_5 * V_79 ;
unsigned long V_80 ;
V_79 = F_70 ( V_82 , V_64 ) ;
do {
V_80 = F_71 ( V_64 , V_65 ) ;
if ( F_72 ( * V_79 ) && F_66 ( V_58 ) )
continue;
if ( F_73 ( V_79 ) )
continue;
if ( F_61 ( V_58 , V_79 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_79 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_74 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_6 * V_82 ;
unsigned long V_80 ;
V_82 = F_75 ( V_58 -> V_70 , V_64 ) ;
do {
V_80 = F_76 ( V_64 , V_65 ) ;
if ( F_77 ( V_82 ) )
continue;
if ( F_69 ( V_58 , V_82 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_82 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
unsigned long F_78 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_83 ;
V_83 = F_79 ( V_58 , V_64 , V_65 , V_58 -> V_84 , 0 , 1 ) ;
if ( V_83 )
F_80 ( V_85 , V_83 ) ;
return V_83 ;
}
static unsigned long F_78 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static int
F_81 ( struct V_55 * V_56 , unsigned long V_86 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_87 = 0 ;
struct V_57 * V_58 , * V_88 ;
V_58 = F_82 ( V_56 , V_86 ) ;
if ( ! V_58 )
return - V_89 ;
V_88 = NULL ;
for (; V_58 && V_58 -> V_90 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_91 = V_58 -> V_92 ;
if ( V_91 > V_65 )
V_91 = V_65 ;
if ( V_58 -> V_90 > V_86 )
V_86 = V_58 -> V_90 ;
if ( ! ( V_12 & V_93 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_92 < V_65 )
return - V_89 ;
if ( V_88 && V_88 -> V_92 < V_58 -> V_90 )
return - V_89 ;
}
if ( V_12 & V_94 ) {
F_78 ( V_58 , V_86 , V_91 ) ;
goto V_80;
}
if ( ( V_12 & V_95 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_83 ( V_58 ) ) ) {
V_87 = F_74 ( V_58 , V_86 , V_91 , V_18 ,
V_12 , V_66 ) ;
if ( V_87 )
break;
}
V_80:
V_88 = V_58 ;
}
return V_87 ;
}
static int F_84 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_87 ;
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
V_87 = V_58 -> V_98 -> V_100 ( V_58 , V_54 ) ;
if ( V_87 )
goto V_101;
}
V_96 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_88 ( V_96 ) ;
return 0 ;
V_101:
F_88 ( V_54 ) ;
return V_87 ;
}
static int F_89 ( struct V_55 * V_56 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_102 )
{
struct V_57 * V_80 ;
struct V_57 * V_88 ;
struct V_57 * V_58 ;
int V_87 = 0 ;
T_7 V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_58 = F_82 ( V_56 , V_86 ) ;
if ( ! V_58 || V_58 -> V_90 > V_86 )
return - V_89 ;
V_88 = V_58 -> V_106 ;
if ( V_86 > V_58 -> V_90 )
V_88 = V_58 ;
for (; V_58 && V_58 -> V_90 < V_65 ; V_88 = V_58 , V_58 = V_80 ) {
V_80 = V_58 -> V_61 ;
V_104 = F_90 ( V_86 , V_58 -> V_90 ) ;
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
V_80 = V_58 -> V_61 ;
if ( F_92 ( F_93 ( V_58 ) , V_102 ) )
continue;
goto V_110;
}
if ( V_58 -> V_90 != V_104 ) {
V_87 = F_95 ( V_58 -> V_70 , V_58 , V_104 , 1 ) ;
if ( V_87 )
goto V_111;
}
if ( V_58 -> V_92 != V_105 ) {
V_87 = F_95 ( V_58 -> V_70 , V_58 , V_105 , 0 ) ;
if ( V_87 )
goto V_111;
}
V_110:
V_87 = F_84 ( V_58 , V_102 ) ;
if ( V_87 )
goto V_111;
}
V_111:
return V_87 ;
}
static long F_96 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_96 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_97 ( V_112 ) ;
int V_14 ;
if ( ! V_112 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_86 ( V_54 ) ) {
V_14 = F_87 ( V_54 ) ;
goto V_111;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_98 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_112 ) ;
if ( V_14 ) {
F_99 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_54 ) ;
goto V_111;
}
V_96 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_113 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_99 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_96 ) ;
V_14 = 0 ;
V_111:
F_100 ( V_112 ) ;
return V_14 ;
}
static void F_101 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_102 ( * V_18 ) ;
if ( V_3 == & V_114 )
return;
switch ( V_3 -> V_8 ) {
case V_115 :
case V_113 :
* V_18 = V_3 -> V_20 . V_18 ;
break;
case V_27 :
if ( ! ( V_3 -> V_12 & V_21 ) )
F_103 ( V_3 -> V_20 . V_22 , * V_18 ) ;
break;
default:
F_31 () ;
}
}
static int F_104 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_71 * V_3 ;
int V_87 ;
V_87 = F_105 ( V_47 , V_56 , V_64 & V_116 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_87 >= 0 ) {
V_87 = F_49 ( V_3 ) ;
F_106 ( V_3 ) ;
}
return V_87 ;
}
static long F_107 ( int * V_34 , T_1 * V_117 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_87 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_12 &
~ ( unsigned long ) ( V_118 | V_119 | V_120 ) )
return - V_19 ;
if ( V_12 & V_120 ) {
if ( V_12 & ( V_118 | V_119 ) )
return - V_19 ;
* V_34 = 0 ;
F_98 ( V_47 ) ;
* V_117 = V_26 ;
F_99 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_119 ) {
F_108 ( & V_56 -> V_59 ) ;
V_58 = F_109 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_110 ( & V_56 -> V_59 ) ;
return - V_89 ;
}
if ( V_58 -> V_98 && V_58 -> V_98 -> V_121 )
V_4 = V_58 -> V_98 -> V_121 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_114 ;
if ( V_12 & V_118 ) {
if ( V_12 & V_119 ) {
V_87 = F_104 ( V_56 , V_64 ) ;
if ( V_87 < 0 )
goto V_111;
* V_34 = V_87 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_113 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_87 = - V_19 ;
goto V_111;
}
} else {
* V_34 = V_4 == & V_114 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_110 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_87 = 0 ;
if ( V_117 ) {
if ( F_5 ( V_4 ) ) {
* V_117 = V_4 -> V_30 . V_31 ;
} else {
F_98 ( V_47 ) ;
F_101 ( V_4 , V_117 ) ;
F_99 ( V_47 ) ;
}
}
V_111:
F_111 ( V_4 ) ;
if ( V_58 )
F_110 ( & V_47 -> V_56 -> V_59 ) ;
return V_87 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_122 * V_123 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_58 ( V_71 ) == 1 ) {
if ( ! F_112 ( V_71 ) ) {
F_113 ( & V_71 -> V_124 , V_123 ) ;
F_114 ( V_71 , V_125 +
F_115 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_116 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_126 )
{
if ( F_117 ( V_71 ) )
return F_118 ( F_119 ( F_120 ( V_71 ) ) ,
V_5 ) ;
else
return F_121 ( V_5 , V_127 , 0 ) ;
}
static int F_122 ( struct V_55 * V_56 , int V_128 , int V_129 ,
int V_12 )
{
T_1 V_117 ;
F_123 ( V_123 ) ;
int V_87 = 0 ;
F_102 ( V_117 ) ;
F_103 ( V_128 , V_117 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_81 ( V_56 , V_56 -> V_60 -> V_90 , V_56 -> V_130 , & V_117 ,
V_12 | V_93 , & V_123 ) ;
if ( ! F_124 ( & V_123 ) ) {
V_87 = F_125 ( & V_123 , F_116 , NULL , V_129 ,
V_131 , V_132 ) ;
if ( V_87 )
F_126 ( & V_123 ) ;
}
return V_87 ;
}
int F_127 ( struct V_55 * V_56 , const T_1 * V_133 ,
const T_1 * V_134 , int V_12 )
{
int V_135 = 0 ;
int V_87 ;
T_1 V_17 ;
V_87 = F_128 () ;
if ( V_87 )
return V_87 ;
F_108 ( & V_56 -> V_59 ) ;
V_87 = F_129 ( V_56 , V_133 , V_134 , V_12 ) ;
if ( V_87 )
goto V_111;
V_17 = * V_133 ;
while ( ! F_11 ( V_17 ) ) {
int V_136 , V_137 ;
int V_128 = V_6 ;
int V_129 = 0 ;
F_130 (s, tmp) {
if ( ( F_8 ( * V_133 ) != F_8 ( * V_134 ) ) &&
( F_33 ( V_136 , * V_134 ) ) )
continue;
V_137 = F_36 ( V_136 , * V_133 , * V_134 ) ;
if ( V_136 == V_137 )
continue;
V_128 = V_136 ;
V_129 = V_137 ;
if ( ! F_33 ( V_129 , V_17 ) )
break;
}
if ( V_128 == V_6 )
break;
F_131 ( V_128 , V_17 ) ;
V_87 = F_122 ( V_56 , V_128 , V_129 , V_12 ) ;
if ( V_87 > 0 )
V_135 += V_87 ;
if ( V_87 < 0 )
break;
}
V_111:
F_110 ( & V_56 -> V_59 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_135 ;
}
static struct V_71 * F_132 ( struct V_71 * V_71 , unsigned long V_86 , int * * V_126 )
{
struct V_57 * V_58 ;
unsigned long V_138 ( V_139 ) ;
V_58 = F_82 ( V_47 -> V_56 , V_86 ) ;
while ( V_58 ) {
V_139 = F_133 ( V_71 , V_58 ) ;
if ( V_139 != - V_89 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_117 ( V_71 ) ) {
F_134 ( ! V_58 ) ;
return F_135 ( V_58 , V_139 , 1 ) ;
}
return F_136 ( V_127 , V_58 , V_139 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_122 * V_123 ,
unsigned long V_12 )
{
}
int F_127 ( struct V_55 * V_56 , const T_1 * V_133 ,
const T_1 * V_134 , int V_12 )
{
return - V_140 ;
}
static struct V_71 * F_132 ( struct V_71 * V_71 , unsigned long V_86 , int * * V_126 )
{
return NULL ;
}
static long F_137 ( unsigned long V_86 , unsigned long V_141 ,
unsigned short V_8 , unsigned short V_142 ,
T_1 * V_117 , unsigned long V_12 )
{
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_87 ;
F_123 ( V_123 ) ;
if ( V_12 & ~ ( unsigned long ) V_143 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_138 ( V_144 ) )
return - V_145 ;
if ( V_86 & ~ V_116 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_95 ;
V_141 = ( V_141 + V_76 - 1 ) & V_116 ;
V_65 = V_86 + V_141 ;
if ( V_65 < V_86 )
return - V_19 ;
if ( V_65 == V_86 )
return 0 ;
V_54 = F_19 ( V_8 , V_142 , V_117 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_12 & V_94 )
V_54 -> V_12 |= V_146 ;
if ( ! V_54 )
V_12 |= V_93 ;
F_20 ( L_3 ,
V_86 , V_86 + V_141 , V_8 , V_142 ,
V_117 ? F_21 ( * V_117 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_87 = F_128 () ;
if ( V_87 )
goto V_147;
}
{
F_97 ( V_112 ) ;
if ( V_112 ) {
F_42 ( & V_56 -> V_59 ) ;
F_98 ( V_47 ) ;
V_87 = F_15 ( V_54 , V_117 , V_112 ) ;
F_99 ( V_47 ) ;
if ( V_87 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_87 = - V_40 ;
F_100 ( V_112 ) ;
}
if ( V_87 )
goto V_147;
V_87 = F_81 ( V_56 , V_86 , V_65 , V_117 ,
V_12 | V_73 , & V_123 ) ;
if ( ! V_87 )
V_87 = F_89 ( V_56 , V_86 , V_65 , V_54 ) ;
if ( ! V_87 ) {
int V_148 = 0 ;
if ( ! F_124 ( & V_123 ) ) {
F_139 ( V_12 & V_94 ) ;
V_148 = F_125 ( & V_123 , F_132 , NULL ,
V_86 , V_131 , V_149 ) ;
if ( V_148 )
F_126 ( & V_123 ) ;
}
if ( V_148 && ( V_12 & V_95 ) )
V_87 = - V_81 ;
} else
F_126 ( & V_123 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_147:
F_88 ( V_54 ) ;
return V_87 ;
}
static int F_140 ( T_1 * V_18 , const unsigned long T_8 * V_117 ,
unsigned long V_150 )
{
unsigned long V_151 ;
unsigned long V_152 ;
unsigned long V_153 ;
-- V_150 ;
F_102 ( * V_18 ) ;
if ( V_150 == 0 || ! V_117 )
return 0 ;
if ( V_150 > V_76 * V_154 )
return - V_19 ;
V_152 = F_141 ( V_150 ) ;
if ( ( V_150 % V_155 ) == 0 )
V_153 = ~ 0UL ;
else
V_153 = ( 1UL << ( V_150 % V_155 ) ) - 1 ;
if ( V_152 > F_141 ( V_49 ) ) {
if ( V_152 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_151 = F_141 ( V_49 ) ; V_151 < V_152 ; V_151 ++ ) {
unsigned long V_156 ;
if ( F_142 ( V_156 , V_117 + V_151 ) )
return - V_89 ;
if ( V_151 == V_152 - 1 ) {
if ( V_156 & V_153 )
return - V_19 ;
} else if ( V_156 )
return - V_19 ;
}
V_152 = F_141 ( V_49 ) ;
V_153 = ~ 0UL ;
}
if ( F_143 ( F_21 ( * V_18 ) , V_117 , V_152 *sizeof( unsigned long ) ) )
return - V_89 ;
F_21 ( * V_18 ) [ V_152 - 1 ] &= V_153 ;
return 0 ;
}
static int F_144 ( unsigned long T_8 * V_157 , unsigned long V_150 ,
T_1 * V_18 )
{
unsigned long V_158 = F_145 ( V_150 - 1 , 64 ) / 8 ;
const int V_159 = F_141 ( V_49 ) * sizeof( long ) ;
if ( V_158 > V_159 ) {
if ( V_158 > V_76 )
return - V_19 ;
if ( F_146 ( ( char T_8 * ) V_157 + V_159 , V_158 - V_159 ) )
return - V_89 ;
V_158 = V_159 ;
}
return F_147 ( V_157 , F_21 ( * V_18 ) , V_158 ) ? - V_89 : 0 ;
}
struct V_1 * F_148 ( struct V_2 * V_160 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_160 ) ;
if ( V_58 ) {
if ( V_58 -> V_98 && V_58 -> V_98 -> V_121 ) {
struct V_1 * V_161 = V_58 -> V_98 -> V_121 ( V_58 ,
V_64 ) ;
if ( V_161 )
V_4 = V_161 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_149 ( V_4 ) )
F_150 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_114 ;
return V_4 ;
}
bool F_151 ( struct V_2 * V_160 , struct V_57 * V_58 )
{
struct V_1 * V_4 = F_1 ( V_160 ) ;
if ( V_58 ) {
if ( V_58 -> V_98 && V_58 -> V_98 -> V_121 ) {
bool V_14 = false ;
V_4 = V_58 -> V_98 -> V_121 ( V_58 , V_58 -> V_90 ) ;
if ( V_4 && ( V_4 -> V_12 & V_146 ) )
V_14 = true ;
F_111 ( V_4 ) ;
return V_14 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
}
}
if ( ! V_4 )
return V_114 . V_12 & V_146 ;
return V_4 -> V_12 & V_146 ;
}
static int F_152 ( struct V_1 * V_34 , enum V_162 V_163 )
{
enum V_162 V_164 = V_165 ;
F_134 ( V_164 == V_166 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_167 ] ) )
V_164 = V_166 ;
return V_163 >= V_164 ;
}
static T_1 * F_153 ( T_9 V_168 , struct V_1 * V_34 )
{
if ( F_154 ( V_34 -> V_8 == V_115 ) &&
F_152 ( V_34 , F_155 ( V_168 ) ) &&
F_156 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_169 * F_157 ( T_9 V_168 , struct V_1 * V_34 ,
int V_170 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_170 = V_34 -> V_20 . V_22 ;
break;
case V_115 :
if ( F_154 ( V_168 & V_171 ) &&
F_154 ( ! F_33 ( V_170 , V_34 -> V_20 . V_18 ) ) )
V_170 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_158 ( V_170 , V_168 ) ;
}
static unsigned F_159 ( struct V_1 * V_34 )
{
unsigned V_72 , V_80 ;
struct V_2 * V_172 = V_47 ;
V_72 = V_172 -> V_48 ;
V_80 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_80 >= V_49 )
V_80 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_80 < V_49 )
V_172 -> V_48 = V_80 ;
return V_72 ;
}
unsigned int F_160 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_161 () ;
if ( F_162 () )
return V_5 ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_12 & V_21 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_20 . V_22 ;
case V_113 :
return F_159 ( V_34 ) ;
case V_115 : {
struct V_169 * V_169 ;
struct V_163 * V_163 ;
enum V_162 V_173 = F_155 ( V_39 ) ;
V_169 = & F_163 ( V_5 ) -> V_174 [ 0 ] ;
( void ) F_164 ( V_169 , V_173 ,
& V_34 -> V_20 . V_18 ,
& V_163 ) ;
return V_163 ? V_163 -> V_5 : V_5 ;
}
default:
F_31 () ;
}
}
static unsigned F_165 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_175 )
{
unsigned V_176 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_177 ;
int V_178 ;
int V_72 = V_6 ;
if ( ! V_176 )
return F_2 () ;
V_177 = ( unsigned int ) V_175 % V_176 ;
V_178 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_178 ++ ;
} while ( V_178 <= V_177 );
return V_72 ;
}
static inline unsigned F_166 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_179 )
{
if ( V_58 ) {
unsigned long V_175 ;
F_134 ( V_179 < V_107 ) ;
V_175 = V_58 -> V_97 >> ( V_179 - V_107 ) ;
V_175 += ( V_64 - V_58 -> V_90 ) >> V_179 ;
return F_165 ( V_4 , V_58 , V_175 ) ;
} else
return F_159 ( V_4 ) ;
}
int F_167 ( const T_1 * V_180 )
{
int V_30 , V_181 = V_6 ;
V_30 = F_8 ( * V_180 ) ;
if ( V_30 )
V_181 = F_168 ( V_180 -> V_182 ,
F_169 () % V_30 , V_49 ) ;
return V_181 ;
}
struct V_169 * F_170 ( struct V_57 * V_58 , unsigned long V_64 ,
T_9 V_183 , struct V_1 * * V_184 ,
T_1 * * V_9 )
{
struct V_169 * V_185 ;
* V_184 = F_148 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_154 ( ( * V_184 ) -> V_8 == V_113 ) ) {
V_185 = F_158 ( F_166 ( * V_184 , V_58 , V_64 ,
F_171 ( F_55 ( V_58 ) ) ) , V_183 ) ;
} else {
V_185 = F_157 ( V_183 , * V_184 , F_2 () ) ;
if ( ( * V_184 ) -> V_8 == V_115 )
* V_9 = & ( * V_184 ) -> V_20 . V_18 ;
}
return V_185 ;
}
bool F_172 ( T_1 * V_157 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_157 && V_47 -> V_1 ) )
return false ;
F_98 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_173 ( V_157 , V_72 ) ;
break;
case V_115 :
case V_113 :
* V_157 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_99 ( V_47 ) ;
return true ;
}
bool F_174 ( struct V_2 * V_53 ,
const T_1 * V_157 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_157 )
return V_14 ;
F_98 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_111;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_115 :
case V_113 :
V_14 = F_4 ( V_1 -> V_20 . V_18 , * V_157 ) ;
break;
default:
F_31 () ;
}
V_111:
F_99 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_175 ( T_9 V_168 , unsigned V_186 ,
unsigned V_72 )
{
struct V_169 * V_185 ;
struct V_71 * V_71 ;
V_185 = F_158 ( V_72 , V_168 ) ;
V_71 = F_176 ( V_168 , V_186 , V_185 ) ;
if ( V_71 && F_177 ( V_71 ) == F_178 ( & V_185 -> V_187 [ 0 ] ) )
F_114 ( V_71 , V_188 ) ;
return V_71 ;
}
struct V_71 *
F_179 ( T_9 V_168 , int V_186 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_189 ;
V_190:
V_4 = F_148 ( V_47 , V_58 , V_64 ) ;
V_189 = F_180 () ;
if ( F_154 ( V_4 -> V_8 == V_113 ) ) {
unsigned V_72 ;
V_72 = F_166 ( V_4 , V_58 , V_64 , V_107 + V_186 ) ;
F_111 ( V_4 ) ;
V_71 = F_175 ( V_168 , V_186 , V_72 ) ;
if ( F_154 ( ! V_71 && F_181 ( V_189 ) ) )
goto V_190;
return V_71 ;
}
V_71 = F_182 ( V_168 , V_186 ,
F_157 ( V_168 , V_4 , V_5 ) ,
F_153 ( V_168 , V_4 ) ) ;
if ( F_154 ( F_149 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_154 ( ! V_71 && F_181 ( V_189 ) ) )
goto V_190;
return V_71 ;
}
struct V_71 * F_183 ( T_9 V_168 , unsigned V_186 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_189 ;
if ( ! V_4 || F_162 () || ( V_168 & V_171 ) )
V_4 = & V_114 ;
V_190:
V_189 = F_180 () ;
if ( V_4 -> V_8 == V_113 )
V_71 = F_175 ( V_168 , V_186 , F_159 ( V_4 ) ) ;
else
V_71 = F_182 ( V_168 , V_186 ,
F_157 ( V_168 , V_4 , F_2 () ) ,
F_153 ( V_168 , V_4 ) ) ;
if ( F_154 ( ! V_71 && F_181 ( V_189 ) ) )
goto V_190;
return V_71 ;
}
int F_184 ( struct V_57 * V_191 , struct V_57 * V_192 )
{
struct V_1 * V_4 = F_85 ( F_93 ( V_191 ) ) ;
if ( F_86 ( V_4 ) )
return F_87 ( V_4 ) ;
V_192 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_185 ( struct V_1 * V_96 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_96 == V_47 -> V_1 ) {
F_98 ( V_47 ) ;
* V_54 = * V_96 ;
F_99 ( V_47 ) ;
} else
* V_54 = * V_96 ;
if ( F_186 () ) {
T_1 V_193 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_193 , V_46 ) ;
else
F_37 ( V_54 , & V_193 , V_44 ) ;
}
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_187 ( struct V_1 * V_194 , struct V_1 * V_195 )
{
if ( ! V_194 || ! V_195 )
return false ;
if ( V_194 -> V_8 != V_195 -> V_8 )
return false ;
if ( V_194 -> V_12 != V_195 -> V_12 )
return false ;
if ( F_5 ( V_194 ) )
if ( ! F_38 ( V_194 -> V_30 . V_31 , V_195 -> V_30 . V_31 ) )
return false ;
switch ( V_194 -> V_8 ) {
case V_115 :
case V_113 :
return ! ! F_38 ( V_194 -> V_20 . V_18 , V_195 -> V_20 . V_18 ) ;
case V_27 :
return V_194 -> V_20 . V_22 == V_195 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_196 *
F_188 ( struct V_197 * V_198 , unsigned long V_86 , unsigned long V_65 )
{
struct V_199 * V_200 = V_198 -> V_201 . V_199 ;
while ( V_200 ) {
struct V_196 * V_3 = F_189 ( V_200 , struct V_196 , V_170 ) ;
if ( V_86 >= V_3 -> V_65 )
V_200 = V_200 -> V_202 ;
else if ( V_65 <= V_3 -> V_86 )
V_200 = V_200 -> V_203 ;
else
break;
}
if ( ! V_200 )
return NULL ;
for (; ; ) {
struct V_196 * V_30 = NULL ;
struct V_199 * V_88 = F_190 ( V_200 ) ;
if ( ! V_88 )
break;
V_30 = F_189 ( V_88 , struct V_196 , V_170 ) ;
if ( V_30 -> V_65 <= V_86 )
break;
V_200 = V_88 ;
}
return F_189 ( V_200 , struct V_196 , V_170 ) ;
}
static void F_191 ( struct V_197 * V_198 , struct V_196 * V_54 )
{
struct V_199 * * V_3 = & V_198 -> V_201 . V_199 ;
struct V_199 * V_204 = NULL ;
struct V_196 * V_170 ;
while ( * V_3 ) {
V_204 = * V_3 ;
V_170 = F_189 ( V_204 , struct V_196 , V_170 ) ;
if ( V_54 -> V_86 < V_170 -> V_86 )
V_3 = & ( * V_3 ) -> V_203 ;
else if ( V_54 -> V_65 > V_170 -> V_65 )
V_3 = & ( * V_3 ) -> V_202 ;
else
F_31 () ;
}
F_192 ( & V_54 -> V_170 , V_204 , V_3 ) ;
F_193 ( & V_54 -> V_170 , & V_198 -> V_201 ) ;
F_20 ( L_4 , V_54 -> V_86 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_194 ( struct V_197 * V_198 , unsigned long V_205 )
{
struct V_1 * V_4 = NULL ;
struct V_196 * V_206 ;
if ( ! V_198 -> V_201 . V_199 )
return NULL ;
F_195 ( & V_198 -> V_207 ) ;
V_206 = F_188 ( V_198 , V_205 , V_205 + 1 ) ;
if ( V_206 ) {
F_150 ( V_206 -> V_34 ) ;
V_4 = V_206 -> V_34 ;
}
F_60 ( & V_198 -> V_207 ) ;
return V_4 ;
}
static void F_196 ( struct V_196 * V_200 )
{
F_88 ( V_200 -> V_34 ) ;
F_27 ( V_208 , V_200 ) ;
}
int F_197 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_163 * V_163 ;
int V_209 = F_49 ( V_71 ) ;
unsigned long V_103 ;
int V_210 = F_198 () ;
int V_211 = F_199 ( V_210 ) ;
int V_212 = - 1 ;
int V_14 = - 1 ;
F_134 ( ! V_58 ) ;
V_4 = F_148 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_146 ) )
goto V_111;
switch ( V_4 -> V_8 ) {
case V_113 :
F_134 ( V_64 >= V_58 -> V_92 ) ;
F_134 ( V_64 < V_58 -> V_90 ) ;
V_103 = V_58 -> V_97 ;
V_103 += ( V_64 - V_58 -> V_90 ) >> V_107 ;
V_212 = F_165 ( V_4 , V_58 , V_103 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_212 = F_2 () ;
else
V_212 = V_4 -> V_20 . V_22 ;
break;
case V_115 :
if ( F_33 ( V_209 , V_4 -> V_20 . V_18 ) )
goto V_111;
( void ) F_164 (
F_158 ( F_2 () , V_213 ) ,
F_155 ( V_213 ) ,
& V_4 -> V_20 . V_18 , & V_163 ) ;
V_212 = V_163 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_214 ) {
V_212 = V_211 ;
if ( ! F_200 ( V_47 , V_71 , V_209 , V_210 ) )
goto V_111;
}
if ( V_209 != V_212 )
V_14 = V_212 ;
V_111:
F_111 ( V_4 ) ;
return V_14 ;
}
static void F_201 ( struct V_197 * V_198 , struct V_196 * V_200 )
{
F_20 ( L_5 , V_200 -> V_86 , V_200 -> V_65 ) ;
F_202 ( & V_200 -> V_170 , & V_198 -> V_201 ) ;
F_196 ( V_200 ) ;
}
static void F_203 ( struct V_196 * V_5 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_86 = V_86 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_196 * F_204 ( unsigned long V_86 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_196 * V_200 ;
struct V_1 * V_215 ;
V_200 = F_23 ( V_208 , V_39 ) ;
if ( ! V_200 )
return NULL ;
V_215 = F_85 ( V_4 ) ;
if ( F_86 ( V_215 ) ) {
F_27 ( V_208 , V_200 ) ;
return NULL ;
}
V_215 -> V_12 |= V_216 ;
F_203 ( V_200 , V_86 , V_65 , V_215 ) ;
return V_200 ;
}
static int F_205 ( struct V_197 * V_198 , unsigned long V_86 ,
unsigned long V_65 , struct V_196 * V_54 )
{
struct V_196 * V_200 ;
struct V_196 * V_217 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_218:
F_195 ( & V_198 -> V_207 ) ;
V_200 = F_188 ( V_198 , V_86 , V_65 ) ;
while ( V_200 && V_200 -> V_86 < V_65 ) {
struct V_199 * V_80 = F_206 ( & V_200 -> V_170 ) ;
if ( V_200 -> V_86 >= V_86 ) {
if ( V_200 -> V_65 <= V_65 )
F_201 ( V_198 , V_200 ) ;
else
V_200 -> V_86 = V_65 ;
} else {
if ( V_200 -> V_65 > V_65 ) {
if ( ! V_217 )
goto V_219;
* F_19 = * V_200 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_203 ( V_217 , V_65 , V_200 -> V_65 , F_19 ) ;
V_200 -> V_65 = V_86 ;
F_191 ( V_198 , V_217 ) ;
V_217 = NULL ;
F_19 = NULL ;
break;
} else
V_200 -> V_65 = V_86 ;
}
if ( ! V_80 )
break;
V_200 = F_189 ( V_80 , struct V_196 , V_170 ) ;
}
if ( V_54 )
F_191 ( V_198 , V_54 ) ;
F_60 ( & V_198 -> V_207 ) ;
V_14 = 0 ;
V_101:
if ( F_19 )
F_88 ( F_19 ) ;
if ( V_217 )
F_27 ( V_208 , V_217 ) ;
return V_14 ;
V_219:
F_60 ( & V_198 -> V_207 ) ;
V_14 = - V_40 ;
V_217 = F_23 ( V_208 , V_39 ) ;
if ( ! V_217 )
goto V_101;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_101;
goto V_218;
}
void F_207 ( struct V_197 * V_198 , struct V_1 * V_184 )
{
int V_14 ;
V_198 -> V_201 = V_220 ;
F_208 ( & V_198 -> V_207 ) ;
if ( V_184 ) {
struct V_57 V_221 ;
struct V_1 * V_54 ;
F_97 ( V_112 ) ;
if ( ! V_112 )
goto V_222;
V_54 = F_19 ( V_184 -> V_8 , V_184 -> V_12 , & V_184 -> V_30 . V_31 ) ;
if ( F_86 ( V_54 ) )
goto V_223;
F_98 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_184 -> V_30 . V_31 , V_112 ) ;
F_99 ( V_47 ) ;
if ( V_14 )
goto V_224;
memset ( & V_221 , 0 , sizeof( struct V_57 ) ) ;
V_221 . V_92 = V_225 ;
F_209 ( V_198 , & V_221 , V_54 ) ;
V_224:
F_88 ( V_54 ) ;
V_223:
F_100 ( V_112 ) ;
V_222:
F_88 ( V_184 ) ;
}
}
int F_209 ( struct V_197 * V_226 ,
struct V_57 * V_58 , struct V_1 * V_227 )
{
int V_87 ;
struct V_196 * V_54 = NULL ;
unsigned long V_228 = F_210 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_97 ,
V_228 , V_227 ? V_227 -> V_8 : - 1 ,
V_227 ? V_227 -> V_12 : - 1 ,
V_227 ? F_21 ( V_227 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_227 ) {
V_54 = F_204 ( V_58 -> V_97 , V_58 -> V_97 + V_228 , V_227 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_87 = F_205 ( V_226 , V_58 -> V_97 , V_58 -> V_97 + V_228 , V_54 ) ;
if ( V_87 && V_54 )
F_196 ( V_54 ) ;
return V_87 ;
}
void F_211 ( struct V_197 * V_3 )
{
struct V_196 * V_200 ;
struct V_199 * V_80 ;
if ( ! V_3 -> V_201 . V_199 )
return;
F_195 ( & V_3 -> V_207 ) ;
V_80 = F_212 ( & V_3 -> V_201 ) ;
while ( V_80 ) {
V_200 = F_189 ( V_80 , struct V_196 , V_170 ) ;
V_80 = F_206 ( & V_200 -> V_170 ) ;
F_201 ( V_3 , V_200 ) ;
}
F_60 ( & V_3 -> V_207 ) ;
}
static void T_10 F_213 ( void )
{
bool V_229 = false ;
if ( F_214 ( V_230 ) )
V_229 = true ;
if ( V_231 )
F_215 ( V_231 == 1 ) ;
if ( V_232 > 1 && ! V_231 ) {
F_216 ( L_7
L_8
L_9 ,
V_229 ? L_10 : L_11 ) ;
F_215 ( V_229 ) ;
}
}
static int T_10 F_217 ( char * V_233 )
{
int V_14 = 0 ;
if ( ! V_233 )
goto V_111;
if ( ! strcmp ( V_233 , L_12 ) ) {
V_231 = 1 ;
V_14 = 1 ;
} else if ( ! strcmp ( V_233 , L_13 ) ) {
V_231 = - 1 ;
V_14 = 1 ;
}
V_111:
if ( ! V_14 )
F_218 ( L_14 ) ;
return V_14 ;
}
static inline void T_10 F_213 ( void )
{
}
void T_10 F_219 ( void )
{
T_1 F_159 ;
unsigned long V_234 = 0 ;
int V_72 , V_235 = 0 ;
V_38 = F_220 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_236 , NULL ) ;
V_208 = F_220 ( L_16 ,
sizeof( struct V_196 ) ,
0 , V_236 , NULL ) ;
F_221 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_222 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_146 | V_214 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_102 ( F_159 ) ;
F_223 (nid, N_MEMORY) {
unsigned long V_237 = F_224 ( V_72 ) ;
if ( V_234 < V_237 ) {
V_234 = V_237 ;
V_235 = V_72 ;
}
if ( ( V_237 << V_107 ) >= ( 16 << 20 ) )
F_103 ( V_72 , F_159 ) ;
}
if ( F_154 ( F_11 ( F_159 ) ) )
F_103 ( V_235 , F_159 ) ;
if ( F_96 ( V_113 , 0 , & F_159 ) )
F_225 ( L_17 , V_238 ) ;
F_213 () ;
}
void F_226 ( void )
{
F_96 ( V_35 , 0 , NULL ) ;
}
int F_227 ( char * V_233 , struct V_1 * * V_184 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_142 ;
T_1 V_18 ;
char * V_239 = strchr ( V_233 , ':' ) ;
char * V_12 = strchr ( V_233 , '=' ) ;
int V_87 = 1 ;
if ( V_239 ) {
* V_239 ++ = '\0' ;
if ( F_228 ( V_239 , V_18 ) )
goto V_111;
if ( ! F_229 ( V_18 , V_10 [ V_11 ] ) )
goto V_111;
} else
F_102 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_240 ; V_8 ++ ) {
if ( ! strcmp ( V_233 , V_241 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_240 )
goto V_111;
switch ( V_8 ) {
case V_27 :
if ( V_239 ) {
char * V_242 = V_239 ;
while ( isdigit ( * V_242 ) )
V_242 ++ ;
if ( * V_242 )
goto V_111;
}
break;
case V_113 :
if ( ! V_239 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_239 )
goto V_111;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_239 )
V_87 = 0 ;
goto V_111;
case V_115 :
if ( ! V_239 )
goto V_111;
}
V_142 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_18 ) )
V_142 |= V_36 ;
else if ( ! strcmp ( V_12 , L_19 ) )
V_142 |= V_28 ;
else
goto V_111;
}
V_54 = F_19 ( V_8 , V_142 , & V_18 ) ;
if ( F_86 ( V_54 ) )
goto V_111;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_239 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_87 = 0 ;
V_111:
if ( V_239 )
* -- V_239 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_87 )
* V_184 = V_54 ;
return V_87 ;
}
void F_230 ( char * V_243 , int V_244 , struct V_1 * V_4 )
{
char * V_3 = V_243 ;
T_1 V_18 = V_245 ;
unsigned short V_8 = V_35 ;
unsigned short V_12 = 0 ;
if ( V_4 && V_4 != & V_114 && ! ( V_4 -> V_12 & V_214 ) ) {
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
F_103 ( V_4 -> V_20 . V_22 , V_18 ) ;
break;
case V_115 :
case V_113 :
V_18 = V_4 -> V_20 . V_18 ;
break;
default:
F_139 ( 1 ) ;
snprintf ( V_3 , V_244 , L_20 ) ;
return;
}
V_3 += snprintf ( V_3 , V_244 , L_21 , V_241 [ V_8 ] ) ;
if ( V_12 & V_13 ) {
V_3 += snprintf ( V_3 , V_243 + V_244 - V_3 , L_22 ) ;
if ( V_12 & V_36 )
V_3 += snprintf ( V_3 , V_243 + V_244 - V_3 , L_18 ) ;
else if ( V_12 & V_28 )
V_3 += snprintf ( V_3 , V_243 + V_244 - V_3 , L_19 ) ;
}
if ( ! F_11 ( V_18 ) ) {
V_3 += snprintf ( V_3 , V_243 + V_244 - V_3 , L_23 ) ;
V_3 += F_231 ( V_3 , V_243 + V_244 - V_3 , V_18 ) ;
}
}
