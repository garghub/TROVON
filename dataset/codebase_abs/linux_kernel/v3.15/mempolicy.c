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
static struct V_57 *
F_81 ( struct V_55 * V_56 , unsigned long V_86 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_87 ;
struct V_57 * V_88 , * V_58 , * V_89 ;
V_88 = F_82 ( V_56 , V_86 ) ;
if ( ! V_88 )
return F_22 ( - V_90 ) ;
V_89 = NULL ;
for ( V_58 = V_88 ; V_58 && V_58 -> V_91 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_92 = V_58 -> V_93 ;
if ( V_92 > V_65 )
V_92 = V_65 ;
if ( V_58 -> V_91 > V_86 )
V_86 = V_58 -> V_91 ;
if ( ! ( V_12 & V_94 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_93 < V_65 )
return F_22 ( - V_90 ) ;
if ( V_89 && V_89 -> V_93 < V_58 -> V_91 )
return F_22 ( - V_90 ) ;
}
if ( V_12 & V_95 ) {
F_78 ( V_58 , V_86 , V_92 ) ;
goto V_80;
}
if ( ( V_12 & V_96 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_83 ( V_58 ) ) ) {
V_87 = F_74 ( V_58 , V_86 , V_92 , V_18 ,
V_12 , V_66 ) ;
if ( V_87 ) {
V_88 = F_22 ( V_87 ) ;
break;
}
}
V_80:
V_89 = V_58 ;
}
return V_88 ;
}
static int F_84 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_87 ;
struct V_1 * V_97 ;
struct V_1 * V_54 ;
F_20 ( L_2 ,
V_58 -> V_91 , V_58 -> V_93 , V_58 -> V_98 ,
V_58 -> V_99 , V_58 -> V_100 ,
V_58 -> V_99 ? V_58 -> V_99 -> V_101 : NULL ) ;
V_54 = F_85 ( V_4 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_58 -> V_99 && V_58 -> V_99 -> V_101 ) {
V_87 = V_58 -> V_99 -> V_101 ( V_58 , V_54 ) ;
if ( V_87 )
goto V_102;
}
V_97 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_88 ( V_97 ) ;
return 0 ;
V_102:
F_88 ( V_54 ) ;
return V_87 ;
}
static int F_89 ( struct V_55 * V_56 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_103 )
{
struct V_57 * V_80 ;
struct V_57 * V_89 ;
struct V_57 * V_58 ;
int V_87 = 0 ;
T_7 V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
V_58 = F_82 ( V_56 , V_86 ) ;
if ( ! V_58 || V_58 -> V_91 > V_86 )
return - V_90 ;
V_89 = V_58 -> V_107 ;
if ( V_86 > V_58 -> V_91 )
V_89 = V_58 ;
for (; V_58 && V_58 -> V_91 < V_65 ; V_89 = V_58 , V_58 = V_80 ) {
V_80 = V_58 -> V_61 ;
V_105 = F_90 ( V_86 , V_58 -> V_91 ) ;
V_106 = F_91 ( V_65 , V_58 -> V_93 ) ;
if ( F_92 ( F_93 ( V_58 ) , V_103 ) )
continue;
V_104 = V_58 -> V_98 +
( ( V_105 - V_58 -> V_91 ) >> V_108 ) ;
V_89 = F_94 ( V_56 , V_89 , V_105 , V_106 , V_58 -> V_109 ,
V_58 -> V_110 , V_58 -> V_100 , V_104 ,
V_103 ) ;
if ( V_89 ) {
V_58 = V_89 ;
V_80 = V_58 -> V_61 ;
if ( F_92 ( F_93 ( V_58 ) , V_103 ) )
continue;
goto V_111;
}
if ( V_58 -> V_91 != V_105 ) {
V_87 = F_95 ( V_58 -> V_70 , V_58 , V_105 , 1 ) ;
if ( V_87 )
goto V_112;
}
if ( V_58 -> V_93 != V_106 ) {
V_87 = F_95 ( V_58 -> V_70 , V_58 , V_106 , 0 ) ;
if ( V_87 )
goto V_112;
}
V_111:
V_87 = F_84 ( V_58 , V_103 ) ;
if ( V_87 )
goto V_112;
}
V_112:
return V_87 ;
}
static long F_96 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_97 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_97 ( V_113 ) ;
int V_14 ;
if ( ! V_113 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_86 ( V_54 ) ) {
V_14 = F_87 ( V_54 ) ;
goto V_112;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_98 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_113 ) ;
if ( V_14 ) {
F_99 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_54 ) ;
goto V_112;
}
V_97 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
if ( V_54 && V_54 -> V_8 == V_114 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_99 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_97 ) ;
V_14 = 0 ;
V_112:
F_100 ( V_113 ) ;
return V_14 ;
}
static void F_101 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_102 ( * V_18 ) ;
if ( V_3 == & V_115 )
return;
switch ( V_3 -> V_8 ) {
case V_116 :
case V_114 :
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
V_87 = F_105 ( V_47 , V_56 , V_64 & V_117 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_87 >= 0 ) {
V_87 = F_49 ( V_3 ) ;
F_106 ( V_3 ) ;
}
return V_87 ;
}
static long F_107 ( int * V_34 , T_1 * V_118 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_87 ;
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
F_98 ( V_47 ) ;
* V_118 = V_26 ;
F_99 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_120 ) {
F_108 ( & V_56 -> V_59 ) ;
V_58 = F_109 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_110 ( & V_56 -> V_59 ) ;
return - V_90 ;
}
if ( V_58 -> V_99 && V_58 -> V_99 -> V_122 )
V_4 = V_58 -> V_99 -> V_122 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_115 ;
if ( V_12 & V_119 ) {
if ( V_12 & V_120 ) {
V_87 = F_104 ( V_56 , V_64 ) ;
if ( V_87 < 0 )
goto V_112;
* V_34 = V_87 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_114 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_87 = - V_19 ;
goto V_112;
}
} else {
* V_34 = V_4 == & V_115 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_110 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_87 = 0 ;
if ( V_118 ) {
if ( F_5 ( V_4 ) ) {
* V_118 = V_4 -> V_30 . V_31 ;
} else {
F_98 ( V_47 ) ;
F_101 ( V_4 , V_118 ) ;
F_99 ( V_47 ) ;
}
}
V_112:
F_111 ( V_4 ) ;
if ( V_58 )
F_110 ( & V_47 -> V_56 -> V_59 ) ;
return V_87 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_123 * V_124 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_58 ( V_71 ) == 1 ) {
if ( ! F_112 ( V_71 ) ) {
F_113 ( & V_71 -> V_125 , V_124 ) ;
F_114 ( V_71 , V_126 +
F_115 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_116 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_127 )
{
if ( F_117 ( V_71 ) )
return F_118 ( F_119 ( F_120 ( V_71 ) ) ,
V_5 ) ;
else
return F_121 ( V_5 , V_128 , 0 ) ;
}
static int F_122 ( struct V_55 * V_56 , int V_129 , int V_130 ,
int V_12 )
{
T_1 V_118 ;
F_123 ( V_124 ) ;
int V_87 = 0 ;
F_102 ( V_118 ) ;
F_103 ( V_129 , V_118 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_81 ( V_56 , V_56 -> V_60 -> V_91 , V_56 -> V_131 , & V_118 ,
V_12 | V_94 , & V_124 ) ;
if ( ! F_124 ( & V_124 ) ) {
V_87 = F_125 ( & V_124 , F_116 , V_130 ,
V_132 , V_133 ) ;
if ( V_87 )
F_126 ( & V_124 ) ;
}
return V_87 ;
}
int F_127 ( struct V_55 * V_56 , const T_1 * V_134 ,
const T_1 * V_135 , int V_12 )
{
int V_136 = 0 ;
int V_87 ;
T_1 V_17 ;
V_87 = F_128 () ;
if ( V_87 )
return V_87 ;
F_108 ( & V_56 -> V_59 ) ;
V_87 = F_129 ( V_56 , V_134 , V_135 , V_12 ) ;
if ( V_87 )
goto V_112;
V_17 = * V_134 ;
while ( ! F_11 ( V_17 ) ) {
int V_137 , V_138 ;
int V_129 = V_6 ;
int V_130 = 0 ;
F_130 (s, tmp) {
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
F_131 ( V_129 , V_17 ) ;
V_87 = F_122 ( V_56 , V_129 , V_130 , V_12 ) ;
if ( V_87 > 0 )
V_136 += V_87 ;
if ( V_87 < 0 )
break;
}
V_112:
F_110 ( & V_56 -> V_59 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_136 ;
}
static struct V_71 * F_132 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_127 )
{
struct V_57 * V_58 = (struct V_57 * ) V_66 ;
unsigned long V_139 ( V_140 ) ;
while ( V_58 ) {
V_140 = F_133 ( V_71 , V_58 ) ;
if ( V_140 != - V_90 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_117 ( V_71 ) ) {
F_134 ( ! V_58 ) ;
return F_135 ( V_58 , V_140 , 1 ) ;
}
return F_136 ( V_128 , V_58 , V_140 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_123 * V_124 ,
unsigned long V_12 )
{
}
int F_127 ( struct V_55 * V_56 , const T_1 * V_134 ,
const T_1 * V_135 , int V_12 )
{
return - V_141 ;
}
static struct V_71 * F_132 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_127 )
{
return NULL ;
}
static long F_137 ( unsigned long V_86 , unsigned long V_142 ,
unsigned short V_8 , unsigned short V_143 ,
T_1 * V_118 , unsigned long V_12 )
{
struct V_57 * V_58 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_87 ;
F_123 ( V_124 ) ;
if ( V_12 & ~ ( unsigned long ) V_144 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_138 ( V_145 ) )
return - V_146 ;
if ( V_86 & ~ V_117 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_96 ;
V_142 = ( V_142 + V_76 - 1 ) & V_117 ;
V_65 = V_86 + V_142 ;
if ( V_65 < V_86 )
return - V_19 ;
if ( V_65 == V_86 )
return 0 ;
V_54 = F_19 ( V_8 , V_143 , V_118 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_12 & V_95 )
V_54 -> V_12 |= V_147 ;
if ( ! V_54 )
V_12 |= V_94 ;
F_20 ( L_3 ,
V_86 , V_86 + V_142 , V_8 , V_143 ,
V_118 ? F_21 ( * V_118 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_87 = F_128 () ;
if ( V_87 )
goto V_148;
}
{
F_97 ( V_113 ) ;
if ( V_113 ) {
F_42 ( & V_56 -> V_59 ) ;
F_98 ( V_47 ) ;
V_87 = F_15 ( V_54 , V_118 , V_113 ) ;
F_99 ( V_47 ) ;
if ( V_87 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_87 = - V_40 ;
F_100 ( V_113 ) ;
}
if ( V_87 )
goto V_148;
V_58 = F_81 ( V_56 , V_86 , V_65 , V_118 ,
V_12 | V_73 , & V_124 ) ;
V_87 = F_87 ( V_58 ) ;
if ( ! F_86 ( V_58 ) )
V_87 = F_89 ( V_56 , V_86 , V_65 , V_54 ) ;
if ( ! V_87 ) {
int V_149 = 0 ;
if ( ! F_124 ( & V_124 ) ) {
F_139 ( V_12 & V_95 ) ;
V_149 = F_125 ( & V_124 , F_132 ,
( unsigned long ) V_58 ,
V_132 , V_150 ) ;
if ( V_149 )
F_126 ( & V_124 ) ;
}
if ( V_149 && ( V_12 & V_96 ) )
V_87 = - V_81 ;
} else
F_126 ( & V_124 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_148:
F_88 ( V_54 ) ;
return V_87 ;
}
static int F_140 ( T_1 * V_18 , const unsigned long T_8 * V_118 ,
unsigned long V_151 )
{
unsigned long V_152 ;
unsigned long V_153 ;
unsigned long V_154 ;
-- V_151 ;
F_102 ( * V_18 ) ;
if ( V_151 == 0 || ! V_118 )
return 0 ;
if ( V_151 > V_76 * V_155 )
return - V_19 ;
V_153 = F_141 ( V_151 ) ;
if ( ( V_151 % V_156 ) == 0 )
V_154 = ~ 0UL ;
else
V_154 = ( 1UL << ( V_151 % V_156 ) ) - 1 ;
if ( V_153 > F_141 ( V_49 ) ) {
if ( V_153 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_152 = F_141 ( V_49 ) ; V_152 < V_153 ; V_152 ++ ) {
unsigned long V_157 ;
if ( F_142 ( V_157 , V_118 + V_152 ) )
return - V_90 ;
if ( V_152 == V_153 - 1 ) {
if ( V_157 & V_154 )
return - V_19 ;
} else if ( V_157 )
return - V_19 ;
}
V_153 = F_141 ( V_49 ) ;
V_154 = ~ 0UL ;
}
if ( F_143 ( F_21 ( * V_18 ) , V_118 , V_153 *sizeof( unsigned long ) ) )
return - V_90 ;
F_21 ( * V_18 ) [ V_153 - 1 ] &= V_154 ;
return 0 ;
}
static int F_144 ( unsigned long T_8 * V_158 , unsigned long V_151 ,
T_1 * V_18 )
{
unsigned long V_159 = F_145 ( V_151 - 1 , 64 ) / 8 ;
const int V_160 = F_141 ( V_49 ) * sizeof( long ) ;
if ( V_159 > V_160 ) {
if ( V_159 > V_76 )
return - V_19 ;
if ( F_146 ( ( char T_8 * ) V_158 + V_160 , V_159 - V_160 ) )
return - V_90 ;
V_159 = V_160 ;
}
return F_147 ( V_158 , F_21 ( * V_18 ) , V_159 ) ? - V_90 : 0 ;
}
struct V_1 * F_148 ( struct V_2 * V_161 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_161 ) ;
if ( V_58 ) {
if ( V_58 -> V_99 && V_58 -> V_99 -> V_122 ) {
struct V_1 * V_162 = V_58 -> V_99 -> V_122 ( V_58 ,
V_64 ) ;
if ( V_162 )
V_4 = V_162 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_149 ( V_4 ) )
F_150 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_115 ;
return V_4 ;
}
bool F_151 ( struct V_2 * V_161 , struct V_57 * V_58 )
{
struct V_1 * V_4 = F_1 ( V_161 ) ;
if ( V_58 ) {
if ( V_58 -> V_99 && V_58 -> V_99 -> V_122 ) {
bool V_14 = false ;
V_4 = V_58 -> V_99 -> V_122 ( V_58 , V_58 -> V_91 ) ;
if ( V_4 && ( V_4 -> V_12 & V_147 ) )
V_14 = true ;
F_111 ( V_4 ) ;
return V_14 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
}
}
if ( ! V_4 )
return V_115 . V_12 & V_147 ;
return V_4 -> V_12 & V_147 ;
}
static int F_152 ( struct V_1 * V_34 , enum V_163 V_164 )
{
enum V_163 V_165 = V_166 ;
F_134 ( V_165 == V_167 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_168 ] ) )
V_165 = V_167 ;
return V_164 >= V_165 ;
}
static T_1 * F_153 ( T_9 V_169 , struct V_1 * V_34 )
{
if ( F_154 ( V_34 -> V_8 == V_116 ) &&
F_152 ( V_34 , F_155 ( V_169 ) ) &&
F_156 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_170 * F_157 ( T_9 V_169 , struct V_1 * V_34 ,
int V_171 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_171 = V_34 -> V_20 . V_22 ;
break;
case V_116 :
if ( F_154 ( V_169 & V_172 ) &&
F_154 ( ! F_33 ( V_171 , V_34 -> V_20 . V_18 ) ) )
V_171 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_158 ( V_171 , V_169 ) ;
}
static unsigned F_159 ( struct V_1 * V_34 )
{
unsigned V_72 , V_80 ;
struct V_2 * V_173 = V_47 ;
V_72 = V_173 -> V_48 ;
V_80 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_80 >= V_49 )
V_80 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_80 < V_49 )
V_173 -> V_48 = V_80 ;
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
case V_114 :
return F_159 ( V_34 ) ;
case V_116 : {
struct V_170 * V_170 ;
struct V_164 * V_164 ;
enum V_163 V_174 = F_155 ( V_39 ) ;
V_170 = & F_163 ( V_5 ) -> V_175 [ 0 ] ;
( void ) F_164 ( V_170 , V_174 ,
& V_34 -> V_20 . V_18 ,
& V_164 ) ;
return V_164 ? V_164 -> V_5 : V_5 ;
}
default:
F_31 () ;
}
}
static unsigned F_165 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_176 )
{
unsigned V_177 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_178 ;
int V_179 ;
int V_72 = V_6 ;
if ( ! V_177 )
return F_2 () ;
V_178 = ( unsigned int ) V_176 % V_177 ;
V_179 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_179 ++ ;
} while ( V_179 <= V_178 );
return V_72 ;
}
static inline unsigned F_166 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_180 )
{
if ( V_58 ) {
unsigned long V_176 ;
F_134 ( V_180 < V_108 ) ;
V_176 = V_58 -> V_98 >> ( V_180 - V_108 ) ;
V_176 += ( V_64 - V_58 -> V_91 ) >> V_180 ;
return F_165 ( V_4 , V_58 , V_176 ) ;
} else
return F_159 ( V_4 ) ;
}
int F_167 ( const T_1 * V_181 )
{
int V_30 , V_182 = V_6 ;
V_30 = F_8 ( * V_181 ) ;
if ( V_30 )
V_182 = F_168 ( V_181 -> V_183 ,
F_169 () % V_30 , V_49 ) ;
return V_182 ;
}
struct V_170 * F_170 ( struct V_57 * V_58 , unsigned long V_64 ,
T_9 V_184 , struct V_1 * * V_185 ,
T_1 * * V_9 )
{
struct V_170 * V_186 ;
* V_185 = F_148 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_154 ( ( * V_185 ) -> V_8 == V_114 ) ) {
V_186 = F_158 ( F_166 ( * V_185 , V_58 , V_64 ,
F_171 ( F_55 ( V_58 ) ) ) , V_184 ) ;
} else {
V_186 = F_157 ( V_184 , * V_185 , F_2 () ) ;
if ( ( * V_185 ) -> V_8 == V_116 )
* V_9 = & ( * V_185 ) -> V_20 . V_18 ;
}
return V_186 ;
}
bool F_172 ( T_1 * V_158 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_158 && V_47 -> V_1 ) )
return false ;
F_98 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_173 ( V_158 , V_72 ) ;
break;
case V_116 :
case V_114 :
* V_158 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_99 ( V_47 ) ;
return true ;
}
bool F_174 ( struct V_2 * V_53 ,
const T_1 * V_158 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_158 )
return V_14 ;
F_98 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_112;
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
V_112:
F_99 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_175 ( T_9 V_169 , unsigned V_187 ,
unsigned V_72 )
{
struct V_170 * V_186 ;
struct V_71 * V_71 ;
V_186 = F_158 ( V_72 , V_169 ) ;
V_71 = F_176 ( V_169 , V_187 , V_186 ) ;
if ( V_71 && F_177 ( V_71 ) == F_178 ( & V_186 -> V_188 [ 0 ] ) )
F_114 ( V_71 , V_189 ) ;
return V_71 ;
}
struct V_71 *
F_179 ( T_9 V_169 , int V_187 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_190 ;
V_191:
V_4 = F_148 ( V_47 , V_58 , V_64 ) ;
V_190 = F_180 () ;
if ( F_154 ( V_4 -> V_8 == V_114 ) ) {
unsigned V_72 ;
V_72 = F_166 ( V_4 , V_58 , V_64 , V_108 + V_187 ) ;
F_111 ( V_4 ) ;
V_71 = F_175 ( V_169 , V_187 , V_72 ) ;
if ( F_154 ( ! V_71 && F_181 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
V_71 = F_182 ( V_169 , V_187 ,
F_157 ( V_169 , V_4 , V_5 ) ,
F_153 ( V_169 , V_4 ) ) ;
if ( F_154 ( F_149 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_154 ( ! V_71 && F_181 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
struct V_71 * F_183 ( T_9 V_169 , unsigned V_187 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_190 ;
if ( ! V_4 || F_162 () || ( V_169 & V_172 ) )
V_4 = & V_115 ;
V_191:
V_190 = F_180 () ;
if ( V_4 -> V_8 == V_114 )
V_71 = F_175 ( V_169 , V_187 , F_159 ( V_4 ) ) ;
else
V_71 = F_182 ( V_169 , V_187 ,
F_157 ( V_169 , V_4 , F_2 () ) ,
F_153 ( V_169 , V_4 ) ) ;
if ( F_154 ( ! V_71 && F_181 ( V_190 ) ) )
goto V_191;
return V_71 ;
}
int F_184 ( struct V_57 * V_192 , struct V_57 * V_193 )
{
struct V_1 * V_4 = F_85 ( F_93 ( V_192 ) ) ;
if ( F_86 ( V_4 ) )
return F_87 ( V_4 ) ;
V_193 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_185 ( struct V_1 * V_97 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_97 == V_47 -> V_1 ) {
F_98 ( V_47 ) ;
* V_54 = * V_97 ;
F_99 ( V_47 ) ;
} else
* V_54 = * V_97 ;
F_186 () ;
if ( F_187 () ) {
T_1 V_194 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_194 , V_46 ) ;
else
F_37 ( V_54 , & V_194 , V_44 ) ;
}
F_188 () ;
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_189 ( struct V_1 * V_195 , struct V_1 * V_196 )
{
if ( ! V_195 || ! V_196 )
return false ;
if ( V_195 -> V_8 != V_196 -> V_8 )
return false ;
if ( V_195 -> V_12 != V_196 -> V_12 )
return false ;
if ( F_5 ( V_195 ) )
if ( ! F_38 ( V_195 -> V_30 . V_31 , V_196 -> V_30 . V_31 ) )
return false ;
switch ( V_195 -> V_8 ) {
case V_116 :
case V_114 :
return ! ! F_38 ( V_195 -> V_20 . V_18 , V_196 -> V_20 . V_18 ) ;
case V_27 :
return V_195 -> V_20 . V_22 == V_196 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_197 *
F_190 ( struct V_198 * V_199 , unsigned long V_86 , unsigned long V_65 )
{
struct V_200 * V_201 = V_199 -> V_202 . V_200 ;
while ( V_201 ) {
struct V_197 * V_3 = F_191 ( V_201 , struct V_197 , V_171 ) ;
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
struct V_200 * V_89 = F_192 ( V_201 ) ;
if ( ! V_89 )
break;
V_30 = F_191 ( V_89 , struct V_197 , V_171 ) ;
if ( V_30 -> V_65 <= V_86 )
break;
V_201 = V_89 ;
}
return F_191 ( V_201 , struct V_197 , V_171 ) ;
}
static void F_193 ( struct V_198 * V_199 , struct V_197 * V_54 )
{
struct V_200 * * V_3 = & V_199 -> V_202 . V_200 ;
struct V_200 * V_205 = NULL ;
struct V_197 * V_171 ;
while ( * V_3 ) {
V_205 = * V_3 ;
V_171 = F_191 ( V_205 , struct V_197 , V_171 ) ;
if ( V_54 -> V_86 < V_171 -> V_86 )
V_3 = & ( * V_3 ) -> V_204 ;
else if ( V_54 -> V_65 > V_171 -> V_65 )
V_3 = & ( * V_3 ) -> V_203 ;
else
F_31 () ;
}
F_194 ( & V_54 -> V_171 , V_205 , V_3 ) ;
F_195 ( & V_54 -> V_171 , & V_199 -> V_202 ) ;
F_20 ( L_4 , V_54 -> V_86 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_196 ( struct V_198 * V_199 , unsigned long V_206 )
{
struct V_1 * V_4 = NULL ;
struct V_197 * V_207 ;
if ( ! V_199 -> V_202 . V_200 )
return NULL ;
F_197 ( & V_199 -> V_208 ) ;
V_207 = F_190 ( V_199 , V_206 , V_206 + 1 ) ;
if ( V_207 ) {
F_150 ( V_207 -> V_34 ) ;
V_4 = V_207 -> V_34 ;
}
F_60 ( & V_199 -> V_208 ) ;
return V_4 ;
}
static void F_198 ( struct V_197 * V_201 )
{
F_88 ( V_201 -> V_34 ) ;
F_27 ( V_209 , V_201 ) ;
}
int F_199 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_164 * V_164 ;
int V_210 = F_49 ( V_71 ) ;
unsigned long V_104 ;
int V_211 = F_200 () ;
int V_212 = F_201 ( V_211 ) ;
int V_213 = - 1 ;
int V_14 = - 1 ;
F_134 ( ! V_58 ) ;
V_4 = F_148 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_147 ) )
goto V_112;
switch ( V_4 -> V_8 ) {
case V_114 :
F_134 ( V_64 >= V_58 -> V_93 ) ;
F_134 ( V_64 < V_58 -> V_91 ) ;
V_104 = V_58 -> V_98 ;
V_104 += ( V_64 - V_58 -> V_91 ) >> V_108 ;
V_213 = F_165 ( V_4 , V_58 , V_104 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_213 = F_2 () ;
else
V_213 = V_4 -> V_20 . V_22 ;
break;
case V_116 :
if ( F_33 ( V_210 , V_4 -> V_20 . V_18 ) )
goto V_112;
( void ) F_164 (
F_158 ( F_2 () , V_214 ) ,
F_155 ( V_214 ) ,
& V_4 -> V_20 . V_18 , & V_164 ) ;
V_213 = V_164 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_215 ) {
V_213 = V_212 ;
if ( ! F_202 ( V_47 , V_71 , V_210 , V_211 ) )
goto V_112;
}
if ( V_210 != V_213 )
V_14 = V_213 ;
V_112:
F_111 ( V_4 ) ;
return V_14 ;
}
static void F_203 ( struct V_198 * V_199 , struct V_197 * V_201 )
{
F_20 ( L_5 , V_201 -> V_86 , V_201 -> V_65 ) ;
F_204 ( & V_201 -> V_171 , & V_199 -> V_202 ) ;
F_198 ( V_201 ) ;
}
static void F_205 ( struct V_197 * V_5 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_86 = V_86 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_197 * F_206 ( unsigned long V_86 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_197 * V_201 ;
struct V_1 * V_216 ;
V_201 = F_23 ( V_209 , V_39 ) ;
if ( ! V_201 )
return NULL ;
V_216 = F_85 ( V_4 ) ;
if ( F_86 ( V_216 ) ) {
F_27 ( V_209 , V_201 ) ;
return NULL ;
}
V_216 -> V_12 |= V_217 ;
F_205 ( V_201 , V_86 , V_65 , V_216 ) ;
return V_201 ;
}
static int F_207 ( struct V_198 * V_199 , unsigned long V_86 ,
unsigned long V_65 , struct V_197 * V_54 )
{
struct V_197 * V_201 ;
struct V_197 * V_218 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_219:
F_197 ( & V_199 -> V_208 ) ;
V_201 = F_190 ( V_199 , V_86 , V_65 ) ;
while ( V_201 && V_201 -> V_86 < V_65 ) {
struct V_200 * V_80 = F_208 ( & V_201 -> V_171 ) ;
if ( V_201 -> V_86 >= V_86 ) {
if ( V_201 -> V_65 <= V_65 )
F_203 ( V_199 , V_201 ) ;
else
V_201 -> V_86 = V_65 ;
} else {
if ( V_201 -> V_65 > V_65 ) {
if ( ! V_218 )
goto V_220;
* F_19 = * V_201 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_205 ( V_218 , V_65 , V_201 -> V_65 , F_19 ) ;
V_201 -> V_65 = V_86 ;
F_193 ( V_199 , V_218 ) ;
V_218 = NULL ;
F_19 = NULL ;
break;
} else
V_201 -> V_65 = V_86 ;
}
if ( ! V_80 )
break;
V_201 = F_191 ( V_80 , struct V_197 , V_171 ) ;
}
if ( V_54 )
F_193 ( V_199 , V_54 ) ;
F_60 ( & V_199 -> V_208 ) ;
V_14 = 0 ;
V_102:
if ( F_19 )
F_88 ( F_19 ) ;
if ( V_218 )
F_27 ( V_209 , V_218 ) ;
return V_14 ;
V_220:
F_60 ( & V_199 -> V_208 ) ;
V_14 = - V_40 ;
V_218 = F_23 ( V_209 , V_39 ) ;
if ( ! V_218 )
goto V_102;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_102;
goto V_219;
}
void F_209 ( struct V_198 * V_199 , struct V_1 * V_185 )
{
int V_14 ;
V_199 -> V_202 = V_221 ;
F_210 ( & V_199 -> V_208 ) ;
if ( V_185 ) {
struct V_57 V_222 ;
struct V_1 * V_54 ;
F_97 ( V_113 ) ;
if ( ! V_113 )
goto V_223;
V_54 = F_19 ( V_185 -> V_8 , V_185 -> V_12 , & V_185 -> V_30 . V_31 ) ;
if ( F_86 ( V_54 ) )
goto V_224;
F_98 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_185 -> V_30 . V_31 , V_113 ) ;
F_99 ( V_47 ) ;
if ( V_14 )
goto V_225;
memset ( & V_222 , 0 , sizeof( struct V_57 ) ) ;
V_222 . V_93 = V_226 ;
F_211 ( V_199 , & V_222 , V_54 ) ;
V_225:
F_88 ( V_54 ) ;
V_224:
F_100 ( V_113 ) ;
V_223:
F_88 ( V_185 ) ;
}
}
int F_211 ( struct V_198 * V_227 ,
struct V_57 * V_58 , struct V_1 * V_228 )
{
int V_87 ;
struct V_197 * V_54 = NULL ;
unsigned long V_229 = F_212 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_98 ,
V_229 , V_228 ? V_228 -> V_8 : - 1 ,
V_228 ? V_228 -> V_12 : - 1 ,
V_228 ? F_21 ( V_228 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_228 ) {
V_54 = F_206 ( V_58 -> V_98 , V_58 -> V_98 + V_229 , V_228 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_87 = F_207 ( V_227 , V_58 -> V_98 , V_58 -> V_98 + V_229 , V_54 ) ;
if ( V_87 && V_54 )
F_198 ( V_54 ) ;
return V_87 ;
}
void F_213 ( struct V_198 * V_3 )
{
struct V_197 * V_201 ;
struct V_200 * V_80 ;
if ( ! V_3 -> V_202 . V_200 )
return;
F_197 ( & V_3 -> V_208 ) ;
V_80 = F_214 ( & V_3 -> V_202 ) ;
while ( V_80 ) {
V_201 = F_191 ( V_80 , struct V_197 , V_171 ) ;
V_80 = F_208 ( & V_201 -> V_171 ) ;
F_203 ( V_3 , V_201 ) ;
}
F_60 ( & V_3 -> V_208 ) ;
}
static void T_10 F_215 ( void )
{
bool V_230 = false ;
if ( F_216 ( V_231 ) )
V_230 = true ;
if ( V_232 )
F_217 ( V_232 == 1 ) ;
if ( V_233 > 1 && ! V_232 ) {
F_218 ( L_7
L_8
L_9 ,
V_230 ? L_10 : L_11 ) ;
F_217 ( V_230 ) ;
}
}
static int T_10 F_219 ( char * V_234 )
{
int V_14 = 0 ;
if ( ! V_234 )
goto V_112;
if ( ! strcmp ( V_234 , L_12 ) ) {
V_232 = 1 ;
V_14 = 1 ;
} else if ( ! strcmp ( V_234 , L_13 ) ) {
V_232 = - 1 ;
V_14 = 1 ;
}
V_112:
if ( ! V_14 )
F_220 ( L_14 ) ;
return V_14 ;
}
static inline void T_10 F_215 ( void )
{
}
void T_10 F_221 ( void )
{
T_1 F_159 ;
unsigned long V_235 = 0 ;
int V_72 , V_236 = 0 ;
V_38 = F_222 ( L_15 ,
sizeof( struct V_1 ) ,
0 , V_237 , NULL ) ;
V_209 = F_222 ( L_16 ,
sizeof( struct V_197 ) ,
0 , V_237 , NULL ) ;
F_223 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_224 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_147 | V_215 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_102 ( F_159 ) ;
F_225 (nid, N_MEMORY) {
unsigned long V_238 = F_226 ( V_72 ) ;
if ( V_235 < V_238 ) {
V_235 = V_238 ;
V_236 = V_72 ;
}
if ( ( V_238 << V_108 ) >= ( 16 << 20 ) )
F_103 ( V_72 , F_159 ) ;
}
if ( F_154 ( F_11 ( F_159 ) ) )
F_103 ( V_236 , F_159 ) ;
if ( F_96 ( V_114 , 0 , & F_159 ) )
F_227 ( L_17 ) ;
F_215 () ;
}
void F_228 ( void )
{
F_96 ( V_35 , 0 , NULL ) ;
}
int F_229 ( char * V_234 , struct V_1 * * V_185 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_143 ;
T_1 V_18 ;
char * V_239 = strchr ( V_234 , ':' ) ;
char * V_12 = strchr ( V_234 , '=' ) ;
int V_87 = 1 ;
if ( V_239 ) {
* V_239 ++ = '\0' ;
if ( F_230 ( V_239 , V_18 ) )
goto V_112;
if ( ! F_231 ( V_18 , V_10 [ V_11 ] ) )
goto V_112;
} else
F_102 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_240 ; V_8 ++ ) {
if ( ! strcmp ( V_234 , V_241 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_240 )
goto V_112;
switch ( V_8 ) {
case V_27 :
if ( V_239 ) {
char * V_242 = V_239 ;
while ( isdigit ( * V_242 ) )
V_242 ++ ;
if ( * V_242 )
goto V_112;
}
break;
case V_114 :
if ( ! V_239 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_239 )
goto V_112;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_239 )
V_87 = 0 ;
goto V_112;
case V_116 :
if ( ! V_239 )
goto V_112;
}
V_143 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_18 ) )
V_143 |= V_36 ;
else if ( ! strcmp ( V_12 , L_19 ) )
V_143 |= V_28 ;
else
goto V_112;
}
V_54 = F_19 ( V_8 , V_143 , & V_18 ) ;
if ( F_86 ( V_54 ) )
goto V_112;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_239 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_87 = 0 ;
V_112:
if ( V_239 )
* -- V_239 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_87 )
* V_185 = V_54 ;
return V_87 ;
}
void F_232 ( char * V_243 , int V_244 , struct V_1 * V_4 )
{
char * V_3 = V_243 ;
T_1 V_18 = V_245 ;
unsigned short V_8 = V_35 ;
unsigned short V_12 = 0 ;
if ( V_4 && V_4 != & V_115 && ! ( V_4 -> V_12 & V_215 ) ) {
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
case V_116 :
case V_114 :
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
V_3 += F_233 ( V_3 , V_243 + V_244 - V_3 , V_18 ) ;
}
}
