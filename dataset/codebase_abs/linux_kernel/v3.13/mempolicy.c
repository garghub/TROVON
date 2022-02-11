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
F_79 ( V_83 != V_84 ) ;
V_82 = F_80 ( V_58 , V_64 , V_65 , V_58 -> V_85 , 0 , 1 ) ;
if ( V_82 )
F_81 ( V_86 , V_82 ) ;
return V_82 ;
}
static unsigned long F_78 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static struct V_57 *
F_82 ( struct V_55 * V_56 , unsigned long V_87 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_88 ;
struct V_57 * V_89 , * V_58 , * V_90 ;
V_89 = F_83 ( V_56 , V_87 ) ;
if ( ! V_89 )
return F_22 ( - V_91 ) ;
V_90 = NULL ;
for ( V_58 = V_89 ; V_58 && V_58 -> V_92 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_93 = V_58 -> V_94 ;
if ( V_93 > V_65 )
V_93 = V_65 ;
if ( V_58 -> V_92 > V_87 )
V_87 = V_58 -> V_92 ;
if ( ! ( V_12 & V_95 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_94 < V_65 )
return F_22 ( - V_91 ) ;
if ( V_90 && V_90 -> V_94 < V_58 -> V_92 )
return F_22 ( - V_91 ) ;
}
if ( V_12 & V_96 ) {
F_78 ( V_58 , V_87 , V_93 ) ;
goto V_79;
}
if ( ( V_12 & V_97 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_84 ( V_58 ) ) ) {
V_88 = F_74 ( V_58 , V_87 , V_93 , V_18 ,
V_12 , V_66 ) ;
if ( V_88 ) {
V_89 = F_22 ( V_88 ) ;
break;
}
}
V_79:
V_90 = V_58 ;
}
return V_89 ;
}
static int F_85 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_88 ;
struct V_1 * V_98 ;
struct V_1 * V_54 ;
F_20 ( L_2 ,
V_58 -> V_92 , V_58 -> V_94 , V_58 -> V_99 ,
V_58 -> V_100 , V_58 -> V_101 ,
V_58 -> V_100 ? V_58 -> V_100 -> V_102 : NULL ) ;
V_54 = F_86 ( V_4 ) ;
if ( F_87 ( V_54 ) )
return F_88 ( V_54 ) ;
if ( V_58 -> V_100 && V_58 -> V_100 -> V_102 ) {
V_88 = V_58 -> V_100 -> V_102 ( V_58 , V_54 ) ;
if ( V_88 )
goto V_103;
}
V_98 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_89 ( V_98 ) ;
return 0 ;
V_103:
F_89 ( V_54 ) ;
return V_88 ;
}
static int F_90 ( struct V_55 * V_56 , unsigned long V_87 ,
unsigned long V_65 , struct V_1 * V_104 )
{
struct V_57 * V_79 ;
struct V_57 * V_90 ;
struct V_57 * V_58 ;
int V_88 = 0 ;
T_7 V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
V_58 = F_83 ( V_56 , V_87 ) ;
if ( ! V_58 || V_58 -> V_92 > V_87 )
return - V_91 ;
V_90 = V_58 -> V_108 ;
if ( V_87 > V_58 -> V_92 )
V_90 = V_58 ;
for (; V_58 && V_58 -> V_92 < V_65 ; V_90 = V_58 , V_58 = V_79 ) {
V_79 = V_58 -> V_61 ;
V_106 = F_91 ( V_87 , V_58 -> V_92 ) ;
V_107 = F_92 ( V_65 , V_58 -> V_94 ) ;
if ( F_93 ( F_94 ( V_58 ) , V_104 ) )
continue;
V_105 = V_58 -> V_99 +
( ( V_106 - V_58 -> V_92 ) >> V_109 ) ;
V_90 = F_95 ( V_56 , V_90 , V_106 , V_107 , V_58 -> V_110 ,
V_58 -> V_111 , V_58 -> V_101 , V_105 ,
V_104 ) ;
if ( V_90 ) {
V_58 = V_90 ;
V_79 = V_58 -> V_61 ;
if ( F_93 ( F_94 ( V_58 ) , V_104 ) )
continue;
goto V_112;
}
if ( V_58 -> V_92 != V_106 ) {
V_88 = F_96 ( V_58 -> V_70 , V_58 , V_106 , 1 ) ;
if ( V_88 )
goto V_113;
}
if ( V_58 -> V_94 != V_107 ) {
V_88 = F_96 ( V_58 -> V_70 , V_58 , V_107 , 0 ) ;
if ( V_88 )
goto V_113;
}
V_112:
V_88 = F_85 ( V_58 , V_104 ) ;
if ( V_88 )
goto V_113;
}
V_113:
return V_88 ;
}
void F_97 ( struct V_2 * V_3 )
{
if ( V_3 -> V_1 )
V_3 -> V_12 |= V_114 ;
else
V_3 -> V_12 &= ~ V_114 ;
}
static void F_98 ( void )
{
F_97 ( V_47 ) ;
}
static long F_99 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_98 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_100 ( V_115 ) ;
int V_14 ;
if ( ! V_115 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_87 ( V_54 ) ) {
V_14 = F_88 ( V_54 ) ;
goto V_113;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_101 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_115 ) ;
if ( V_14 ) {
F_102 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_89 ( V_54 ) ;
goto V_113;
}
V_98 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
F_98 () ;
if ( V_54 && V_54 -> V_8 == V_116 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_102 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_89 ( V_98 ) ;
V_14 = 0 ;
V_113:
F_103 ( V_115 ) ;
return V_14 ;
}
static void F_104 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_105 ( * V_18 ) ;
if ( V_3 == & V_117 )
return;
switch ( V_3 -> V_8 ) {
case V_118 :
case V_116 :
* V_18 = V_3 -> V_20 . V_18 ;
break;
case V_27 :
if ( ! ( V_3 -> V_12 & V_21 ) )
F_106 ( V_3 -> V_20 . V_22 , * V_18 ) ;
break;
default:
F_31 () ;
}
}
static int F_107 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_71 * V_3 ;
int V_88 ;
V_88 = F_108 ( V_47 , V_56 , V_64 & V_119 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_88 >= 0 ) {
V_88 = F_49 ( V_3 ) ;
F_109 ( V_3 ) ;
}
return V_88 ;
}
static long F_110 ( int * V_34 , T_1 * V_120 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_88 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_12 &
~ ( unsigned long ) ( V_121 | V_122 | V_123 ) )
return - V_19 ;
if ( V_12 & V_123 ) {
if ( V_12 & ( V_121 | V_122 ) )
return - V_19 ;
* V_34 = 0 ;
F_101 ( V_47 ) ;
* V_120 = V_26 ;
F_102 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_122 ) {
F_111 ( & V_56 -> V_59 ) ;
V_58 = F_112 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_113 ( & V_56 -> V_59 ) ;
return - V_91 ;
}
if ( V_58 -> V_100 && V_58 -> V_100 -> V_124 )
V_4 = V_58 -> V_100 -> V_124 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_117 ;
if ( V_12 & V_121 ) {
if ( V_12 & V_122 ) {
V_88 = F_107 ( V_56 , V_64 ) ;
if ( V_88 < 0 )
goto V_113;
* V_34 = V_88 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_116 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_88 = - V_19 ;
goto V_113;
}
} else {
* V_34 = V_4 == & V_117 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_113 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_88 = 0 ;
if ( V_120 ) {
if ( F_5 ( V_4 ) ) {
* V_120 = V_4 -> V_30 . V_31 ;
} else {
F_101 ( V_47 ) ;
F_104 ( V_4 , V_120 ) ;
F_102 ( V_47 ) ;
}
}
V_113:
F_114 ( V_4 ) ;
if ( V_58 )
F_113 ( & V_47 -> V_56 -> V_59 ) ;
return V_88 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_125 * V_126 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_58 ( V_71 ) == 1 ) {
if ( ! F_115 ( V_71 ) ) {
F_116 ( & V_71 -> V_127 , V_126 ) ;
F_117 ( V_71 , V_128 +
F_118 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_119 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_129 )
{
if ( F_120 ( V_71 ) )
return F_121 ( F_122 ( F_123 ( V_71 ) ) ,
V_5 ) ;
else
return F_124 ( V_5 , V_130 , 0 ) ;
}
static int F_125 ( struct V_55 * V_56 , int V_131 , int V_132 ,
int V_12 )
{
T_1 V_120 ;
F_126 ( V_126 ) ;
int V_88 = 0 ;
F_105 ( V_120 ) ;
F_106 ( V_131 , V_120 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_82 ( V_56 , V_56 -> V_60 -> V_92 , V_56 -> V_133 , & V_120 ,
V_12 | V_95 , & V_126 ) ;
if ( ! F_127 ( & V_126 ) ) {
V_88 = F_128 ( & V_126 , F_119 , V_132 ,
V_134 , V_135 ) ;
if ( V_88 )
F_129 ( & V_126 ) ;
}
return V_88 ;
}
int F_130 ( struct V_55 * V_56 , const T_1 * V_136 ,
const T_1 * V_137 , int V_12 )
{
int V_138 = 0 ;
int V_88 ;
T_1 V_17 ;
V_88 = F_131 () ;
if ( V_88 )
return V_88 ;
F_111 ( & V_56 -> V_59 ) ;
V_88 = F_132 ( V_56 , V_136 , V_137 , V_12 ) ;
if ( V_88 )
goto V_113;
V_17 = * V_136 ;
while ( ! F_11 ( V_17 ) ) {
int V_139 , V_140 ;
int V_131 = V_6 ;
int V_132 = 0 ;
F_133 (s, tmp) {
if ( ( F_8 ( * V_136 ) != F_8 ( * V_137 ) ) &&
( F_33 ( V_139 , * V_137 ) ) )
continue;
V_140 = F_36 ( V_139 , * V_136 , * V_137 ) ;
if ( V_139 == V_140 )
continue;
V_131 = V_139 ;
V_132 = V_140 ;
if ( ! F_33 ( V_132 , V_17 ) )
break;
}
if ( V_131 == V_6 )
break;
F_134 ( V_131 , V_17 ) ;
V_88 = F_125 ( V_56 , V_131 , V_132 , V_12 ) ;
if ( V_88 > 0 )
V_138 += V_88 ;
if ( V_88 < 0 )
break;
}
V_113:
F_113 ( & V_56 -> V_59 ) ;
if ( V_88 < 0 )
return V_88 ;
return V_138 ;
}
static struct V_71 * F_135 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_129 )
{
struct V_57 * V_58 = (struct V_57 * ) V_66 ;
unsigned long V_141 ( V_142 ) ;
while ( V_58 ) {
V_142 = F_136 ( V_71 , V_58 ) ;
if ( V_142 != - V_91 )
break;
V_58 = V_58 -> V_61 ;
}
if ( F_120 ( V_71 ) ) {
if ( V_58 )
return F_137 ( V_58 , V_142 , 1 ) ;
else
return NULL ;
}
return F_138 ( V_130 , V_58 , V_142 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_125 * V_126 ,
unsigned long V_12 )
{
}
int F_130 ( struct V_55 * V_56 , const T_1 * V_136 ,
const T_1 * V_137 , int V_12 )
{
return - V_143 ;
}
static struct V_71 * F_135 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_129 )
{
return NULL ;
}
static long F_139 ( unsigned long V_87 , unsigned long V_144 ,
unsigned short V_8 , unsigned short V_145 ,
T_1 * V_120 , unsigned long V_12 )
{
struct V_57 * V_58 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_88 ;
F_126 ( V_126 ) ;
if ( V_12 & ~ ( unsigned long ) V_146 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_140 ( V_147 ) )
return - V_148 ;
if ( V_87 & ~ V_119 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_97 ;
V_144 = ( V_144 + V_76 - 1 ) & V_119 ;
V_65 = V_87 + V_144 ;
if ( V_65 < V_87 )
return - V_19 ;
if ( V_65 == V_87 )
return 0 ;
V_54 = F_19 ( V_8 , V_145 , V_120 ) ;
if ( F_87 ( V_54 ) )
return F_88 ( V_54 ) ;
if ( V_12 & V_96 )
V_54 -> V_12 |= V_149 ;
if ( ! V_54 )
V_12 |= V_95 ;
F_20 ( L_3 ,
V_87 , V_87 + V_144 , V_8 , V_145 ,
V_120 ? F_21 ( * V_120 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_88 = F_131 () ;
if ( V_88 )
goto V_150;
}
{
F_100 ( V_115 ) ;
if ( V_115 ) {
F_42 ( & V_56 -> V_59 ) ;
F_101 ( V_47 ) ;
V_88 = F_15 ( V_54 , V_120 , V_115 ) ;
F_102 ( V_47 ) ;
if ( V_88 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_88 = - V_40 ;
F_103 ( V_115 ) ;
}
if ( V_88 )
goto V_150;
V_58 = F_82 ( V_56 , V_87 , V_65 , V_120 ,
V_12 | V_73 , & V_126 ) ;
V_88 = F_88 ( V_58 ) ;
if ( ! F_87 ( V_58 ) )
V_88 = F_90 ( V_56 , V_87 , V_65 , V_54 ) ;
if ( ! V_88 ) {
int V_151 = 0 ;
if ( ! F_127 ( & V_126 ) ) {
F_141 ( V_12 & V_96 ) ;
V_151 = F_128 ( & V_126 , F_135 ,
( unsigned long ) V_58 ,
V_134 , V_152 ) ;
if ( V_151 )
F_129 ( & V_126 ) ;
}
if ( V_151 && ( V_12 & V_97 ) )
V_88 = - V_80 ;
} else
F_129 ( & V_126 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_150:
F_89 ( V_54 ) ;
return V_88 ;
}
static int F_142 ( T_1 * V_18 , const unsigned long T_8 * V_120 ,
unsigned long V_153 )
{
unsigned long V_154 ;
unsigned long V_155 ;
unsigned long V_156 ;
-- V_153 ;
F_105 ( * V_18 ) ;
if ( V_153 == 0 || ! V_120 )
return 0 ;
if ( V_153 > V_76 * V_157 )
return - V_19 ;
V_155 = F_143 ( V_153 ) ;
if ( ( V_153 % V_158 ) == 0 )
V_156 = ~ 0UL ;
else
V_156 = ( 1UL << ( V_153 % V_158 ) ) - 1 ;
if ( V_155 > F_143 ( V_49 ) ) {
if ( V_155 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_154 = F_143 ( V_49 ) ; V_154 < V_155 ; V_154 ++ ) {
unsigned long V_159 ;
if ( F_144 ( V_159 , V_120 + V_154 ) )
return - V_91 ;
if ( V_154 == V_155 - 1 ) {
if ( V_159 & V_156 )
return - V_19 ;
} else if ( V_159 )
return - V_19 ;
}
V_155 = F_143 ( V_49 ) ;
V_156 = ~ 0UL ;
}
if ( F_145 ( F_21 ( * V_18 ) , V_120 , V_155 *sizeof( unsigned long ) ) )
return - V_91 ;
F_21 ( * V_18 ) [ V_155 - 1 ] &= V_156 ;
return 0 ;
}
static int F_146 ( unsigned long T_8 * V_160 , unsigned long V_153 ,
T_1 * V_18 )
{
unsigned long V_161 = F_147 ( V_153 - 1 , 64 ) / 8 ;
const int V_162 = F_143 ( V_49 ) * sizeof( long ) ;
if ( V_161 > V_162 ) {
if ( V_161 > V_76 )
return - V_19 ;
if ( F_148 ( ( char T_8 * ) V_160 + V_162 , V_161 - V_162 ) )
return - V_91 ;
V_161 = V_162 ;
}
return F_149 ( V_160 , F_21 ( * V_18 ) , V_161 ) ? - V_91 : 0 ;
}
T_9 long F_150 ( int T_8 * V_34 ,
T_10 T_8 * V_120 ,
T_10 V_153 ,
T_10 V_64 , T_10 V_12 )
{
long V_88 ;
unsigned long T_8 * V_163 = NULL ;
unsigned long V_164 , V_165 ;
F_151 ( V_166 , V_49 ) ;
V_164 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_165 = F_147 ( V_164 , V_158 ) / 8 ;
if ( V_120 )
V_163 = F_153 ( V_165 ) ;
V_88 = F_154 ( V_34 , V_163 , V_164 + 1 , V_64 , V_12 ) ;
if ( ! V_88 && V_120 ) {
unsigned long V_167 ;
V_167 = F_152 (unsigned long, sizeof(bm), alloc_size) ;
V_88 = F_145 ( V_166 , V_163 , V_167 ) ;
V_88 |= F_148 ( V_120 , F_147 ( V_153 - 1 , 8 ) / 8 ) ;
V_88 |= F_155 ( V_120 , V_166 , V_164 ) ;
}
return V_88 ;
}
T_9 long F_156 ( int V_8 , T_10 T_8 * V_120 ,
T_10 V_153 )
{
long V_88 = 0 ;
unsigned long T_8 * V_163 = NULL ;
unsigned long V_164 , V_165 ;
F_151 ( V_166 , V_49 ) ;
V_164 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_165 = F_147 ( V_164 , V_158 ) / 8 ;
if ( V_120 ) {
V_88 = F_157 ( V_166 , V_120 , V_164 ) ;
V_163 = F_153 ( V_165 ) ;
V_88 |= F_149 ( V_163 , V_166 , V_165 ) ;
}
if ( V_88 )
return - V_91 ;
return F_158 ( V_8 , V_163 , V_164 + 1 ) ;
}
T_9 long F_159 ( T_10 V_87 , T_10 V_144 ,
T_10 V_8 , T_10 T_8 * V_120 ,
T_10 V_153 , T_10 V_12 )
{
long V_88 = 0 ;
unsigned long T_8 * V_163 = NULL ;
unsigned long V_164 , V_165 ;
T_1 V_166 ;
V_164 = F_152 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_165 = F_147 ( V_164 , V_158 ) / 8 ;
if ( V_120 ) {
V_88 = F_157 ( F_21 ( V_166 ) , V_120 , V_164 ) ;
V_163 = F_153 ( V_165 ) ;
V_88 |= F_149 ( V_163 , F_21 ( V_166 ) , V_165 ) ;
}
if ( V_88 )
return - V_91 ;
return F_160 ( V_87 , V_144 , V_8 , V_163 , V_164 + 1 , V_12 ) ;
}
struct V_1 * F_161 ( struct V_2 * V_168 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_168 ) ;
if ( V_58 ) {
if ( V_58 -> V_100 && V_58 -> V_100 -> V_124 ) {
struct V_1 * V_169 = V_58 -> V_100 -> V_124 ( V_58 ,
V_64 ) ;
if ( V_169 )
V_4 = V_169 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_162 ( V_4 ) )
F_163 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_117 ;
return V_4 ;
}
bool F_164 ( struct V_2 * V_168 , struct V_57 * V_58 )
{
struct V_1 * V_4 = F_1 ( V_168 ) ;
if ( V_58 ) {
if ( V_58 -> V_100 && V_58 -> V_100 -> V_124 ) {
bool V_14 = false ;
V_4 = V_58 -> V_100 -> V_124 ( V_58 , V_58 -> V_92 ) ;
if ( V_4 && ( V_4 -> V_12 & V_149 ) )
V_14 = true ;
F_114 ( V_4 ) ;
return V_14 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
}
}
if ( ! V_4 )
return V_117 . V_12 & V_149 ;
return V_4 -> V_12 & V_149 ;
}
static int F_165 ( struct V_1 * V_34 , enum V_170 V_171 )
{
enum V_170 V_172 = V_173 ;
F_166 ( V_172 == V_174 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_175 ] ) )
V_172 = V_174 ;
return V_171 >= V_172 ;
}
static T_1 * F_167 ( T_11 V_176 , struct V_1 * V_34 )
{
if ( F_168 ( V_34 -> V_8 == V_118 ) &&
F_165 ( V_34 , F_169 ( V_176 ) ) &&
F_170 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_177 * F_171 ( T_11 V_176 , struct V_1 * V_34 ,
int V_178 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_178 = V_34 -> V_20 . V_22 ;
break;
case V_118 :
if ( F_168 ( V_176 & V_179 ) &&
F_168 ( ! F_33 ( V_178 , V_34 -> V_20 . V_18 ) ) )
V_178 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_172 ( V_178 , V_176 ) ;
}
static unsigned F_173 ( struct V_1 * V_34 )
{
unsigned V_72 , V_79 ;
struct V_2 * V_180 = V_47 ;
V_72 = V_180 -> V_48 ;
V_79 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_79 >= V_49 )
V_79 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_79 < V_49 )
V_180 -> V_48 = V_79 ;
return V_72 ;
}
unsigned F_174 ( void )
{
struct V_1 * V_34 ;
if ( F_175 () )
return F_2 () ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_12 & V_21 )
return F_2 () ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_20 . V_22 ;
case V_116 :
return F_173 ( V_34 ) ;
case V_118 : {
struct V_177 * V_177 ;
struct V_171 * V_171 ;
enum V_170 V_181 = F_169 ( V_39 ) ;
V_177 = & F_176 ( F_2 () ) -> V_182 [ 0 ] ;
( void ) F_177 ( V_177 , V_181 ,
& V_34 -> V_20 . V_18 ,
& V_171 ) ;
return V_171 ? V_171 -> V_5 : F_2 () ;
}
default:
F_31 () ;
}
}
static unsigned F_178 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_183 )
{
unsigned V_184 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_185 ;
int V_186 ;
int V_72 = V_6 ;
if ( ! V_184 )
return F_2 () ;
V_185 = ( unsigned int ) V_183 % V_184 ;
V_186 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_186 ++ ;
} while ( V_186 <= V_185 );
return V_72 ;
}
static inline unsigned F_179 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_187 )
{
if ( V_58 ) {
unsigned long V_183 ;
F_166 ( V_187 < V_109 ) ;
V_183 = V_58 -> V_99 >> ( V_187 - V_109 ) ;
V_183 += ( V_64 - V_58 -> V_92 ) >> V_187 ;
return F_178 ( V_4 , V_58 , V_183 ) ;
} else
return F_173 ( V_4 ) ;
}
int F_180 ( const T_1 * V_188 )
{
int V_30 , V_189 = V_6 ;
V_30 = F_8 ( * V_188 ) ;
if ( V_30 )
V_189 = F_181 ( V_188 -> V_190 ,
F_182 () % V_30 , V_49 ) ;
return V_189 ;
}
struct V_177 * F_183 ( struct V_57 * V_58 , unsigned long V_64 ,
T_11 V_191 , struct V_1 * * V_192 ,
T_1 * * V_9 )
{
struct V_177 * V_193 ;
* V_192 = F_161 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_168 ( ( * V_192 ) -> V_8 == V_116 ) ) {
V_193 = F_172 ( F_179 ( * V_192 , V_58 , V_64 ,
F_184 ( F_55 ( V_58 ) ) ) , V_191 ) ;
} else {
V_193 = F_171 ( V_191 , * V_192 , F_2 () ) ;
if ( ( * V_192 ) -> V_8 == V_118 )
* V_9 = & ( * V_192 ) -> V_20 . V_18 ;
}
return V_193 ;
}
bool F_185 ( T_1 * V_160 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_160 && V_47 -> V_1 ) )
return false ;
F_101 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_186 ( V_160 , V_72 ) ;
break;
case V_118 :
case V_116 :
* V_160 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_102 ( V_47 ) ;
return true ;
}
bool F_187 ( struct V_2 * V_53 ,
const T_1 * V_160 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_160 )
return V_14 ;
F_101 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_113;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_118 :
case V_116 :
V_14 = F_4 ( V_1 -> V_20 . V_18 , * V_160 ) ;
break;
default:
F_31 () ;
}
V_113:
F_102 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_188 ( T_11 V_176 , unsigned V_194 ,
unsigned V_72 )
{
struct V_177 * V_193 ;
struct V_71 * V_71 ;
V_193 = F_172 ( V_72 , V_176 ) ;
V_71 = F_189 ( V_176 , V_194 , V_193 ) ;
if ( V_71 && F_190 ( V_71 ) == F_191 ( & V_193 -> V_195 [ 0 ] ) )
F_117 ( V_71 , V_196 ) ;
return V_71 ;
}
struct V_71 *
F_192 ( T_11 V_176 , int V_194 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_197 ;
V_198:
V_4 = F_161 ( V_47 , V_58 , V_64 ) ;
V_197 = F_193 () ;
if ( F_168 ( V_4 -> V_8 == V_116 ) ) {
unsigned V_72 ;
V_72 = F_179 ( V_4 , V_58 , V_64 , V_109 + V_194 ) ;
F_114 ( V_4 ) ;
V_71 = F_188 ( V_176 , V_194 , V_72 ) ;
if ( F_168 ( ! F_194 ( V_197 ) && ! V_71 ) )
goto V_198;
return V_71 ;
}
V_71 = F_195 ( V_176 , V_194 ,
F_171 ( V_176 , V_4 , V_5 ) ,
F_167 ( V_176 , V_4 ) ) ;
if ( F_168 ( F_162 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_168 ( ! F_194 ( V_197 ) && ! V_71 ) )
goto V_198;
return V_71 ;
}
struct V_71 * F_196 ( T_11 V_176 , unsigned V_194 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_197 ;
if ( ! V_4 || F_175 () || ( V_176 & V_179 ) )
V_4 = & V_117 ;
V_198:
V_197 = F_193 () ;
if ( V_4 -> V_8 == V_116 )
V_71 = F_188 ( V_176 , V_194 , F_173 ( V_4 ) ) ;
else
V_71 = F_195 ( V_176 , V_194 ,
F_171 ( V_176 , V_4 , F_2 () ) ,
F_167 ( V_176 , V_4 ) ) ;
if ( F_168 ( ! F_194 ( V_197 ) && ! V_71 ) )
goto V_198;
return V_71 ;
}
int F_197 ( struct V_57 * V_199 , struct V_57 * V_200 )
{
struct V_1 * V_4 = F_86 ( F_94 ( V_199 ) ) ;
if ( F_87 ( V_4 ) )
return F_88 ( V_4 ) ;
V_200 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_198 ( struct V_1 * V_98 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_98 == V_47 -> V_1 ) {
F_101 ( V_47 ) ;
* V_54 = * V_98 ;
F_102 ( V_47 ) ;
} else
* V_54 = * V_98 ;
F_199 () ;
if ( F_200 () ) {
T_1 V_201 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_201 , V_46 ) ;
else
F_37 ( V_54 , & V_201 , V_44 ) ;
}
F_201 () ;
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_202 ( struct V_1 * V_202 , struct V_1 * V_203 )
{
if ( ! V_202 || ! V_203 )
return false ;
if ( V_202 -> V_8 != V_203 -> V_8 )
return false ;
if ( V_202 -> V_12 != V_203 -> V_12 )
return false ;
if ( F_5 ( V_202 ) )
if ( ! F_38 ( V_202 -> V_30 . V_31 , V_203 -> V_30 . V_31 ) )
return false ;
switch ( V_202 -> V_8 ) {
case V_118 :
case V_116 :
return ! ! F_38 ( V_202 -> V_20 . V_18 , V_203 -> V_20 . V_18 ) ;
case V_27 :
return V_202 -> V_20 . V_22 == V_203 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_204 *
F_203 ( struct V_205 * V_206 , unsigned long V_87 , unsigned long V_65 )
{
struct V_207 * V_208 = V_206 -> V_209 . V_207 ;
while ( V_208 ) {
struct V_204 * V_3 = F_204 ( V_208 , struct V_204 , V_178 ) ;
if ( V_87 >= V_3 -> V_65 )
V_208 = V_208 -> V_210 ;
else if ( V_65 <= V_3 -> V_87 )
V_208 = V_208 -> V_211 ;
else
break;
}
if ( ! V_208 )
return NULL ;
for (; ; ) {
struct V_204 * V_30 = NULL ;
struct V_207 * V_90 = F_205 ( V_208 ) ;
if ( ! V_90 )
break;
V_30 = F_204 ( V_90 , struct V_204 , V_178 ) ;
if ( V_30 -> V_65 <= V_87 )
break;
V_208 = V_90 ;
}
return F_204 ( V_208 , struct V_204 , V_178 ) ;
}
static void F_206 ( struct V_205 * V_206 , struct V_204 * V_54 )
{
struct V_207 * * V_3 = & V_206 -> V_209 . V_207 ;
struct V_207 * V_212 = NULL ;
struct V_204 * V_178 ;
while ( * V_3 ) {
V_212 = * V_3 ;
V_178 = F_204 ( V_212 , struct V_204 , V_178 ) ;
if ( V_54 -> V_87 < V_178 -> V_87 )
V_3 = & ( * V_3 ) -> V_211 ;
else if ( V_54 -> V_65 > V_178 -> V_65 )
V_3 = & ( * V_3 ) -> V_210 ;
else
F_31 () ;
}
F_207 ( & V_54 -> V_178 , V_212 , V_3 ) ;
F_208 ( & V_54 -> V_178 , & V_206 -> V_209 ) ;
F_20 ( L_4 , V_54 -> V_87 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_209 ( struct V_205 * V_206 , unsigned long V_213 )
{
struct V_1 * V_4 = NULL ;
struct V_204 * V_214 ;
if ( ! V_206 -> V_209 . V_207 )
return NULL ;
F_210 ( & V_206 -> V_215 ) ;
V_214 = F_203 ( V_206 , V_213 , V_213 + 1 ) ;
if ( V_214 ) {
F_163 ( V_214 -> V_34 ) ;
V_4 = V_214 -> V_34 ;
}
F_60 ( & V_206 -> V_215 ) ;
return V_4 ;
}
static void F_211 ( struct V_204 * V_208 )
{
F_89 ( V_208 -> V_34 ) ;
F_27 ( V_216 , V_208 ) ;
}
static bool F_212 ( struct V_2 * V_3 , int V_217 )
{
if ( F_213 ( V_3 , V_217 ) )
return false ;
if ( V_3 -> F_212 ) {
V_3 -> F_212 -- ;
return true ;
}
return false ;
}
static inline void F_214 ( struct V_2 * V_3 )
{
V_3 -> F_212 = V_218 ;
}
static inline bool F_212 ( struct V_2 * V_3 , int V_217 )
{
return false ;
}
static inline void F_214 ( struct V_2 * V_3 )
{
}
int F_215 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_171 * V_171 ;
int V_219 = F_49 ( V_71 ) ;
unsigned long V_105 ;
int V_220 = F_216 () ;
int V_221 = F_217 ( V_220 ) ;
int V_222 = - 1 ;
int V_14 = - 1 ;
F_166 ( ! V_58 ) ;
V_4 = F_161 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_149 ) )
goto V_113;
switch ( V_4 -> V_8 ) {
case V_116 :
F_166 ( V_64 >= V_58 -> V_94 ) ;
F_166 ( V_64 < V_58 -> V_92 ) ;
V_105 = V_58 -> V_99 ;
V_105 += ( V_64 - V_58 -> V_92 ) >> V_109 ;
V_222 = F_178 ( V_4 , V_58 , V_105 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_222 = F_2 () ;
else
V_222 = V_4 -> V_20 . V_22 ;
break;
case V_118 :
if ( F_33 ( V_219 , V_4 -> V_20 . V_18 ) )
goto V_113;
( void ) F_177 (
F_172 ( F_2 () , V_223 ) ,
F_169 ( V_223 ) ,
& V_4 -> V_20 . V_18 , & V_171 ) ;
V_222 = V_171 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_224 ) {
int V_217 ;
int V_225 ;
V_222 = V_221 ;
V_225 = F_218 ( V_220 , V_47 -> V_226 ) ;
V_217 = F_219 ( V_71 , V_225 ) ;
if ( ! F_220 ( V_217 ) && F_221 ( V_217 ) != V_221 ) {
if ( ! F_213 ( V_47 , V_217 ) )
F_214 ( V_47 ) ;
goto V_113;
}
if ( F_212 ( V_47 , V_217 ) )
goto V_113;
}
if ( V_219 != V_222 )
V_14 = V_222 ;
V_113:
F_114 ( V_4 ) ;
return V_14 ;
}
static void F_222 ( struct V_205 * V_206 , struct V_204 * V_208 )
{
F_20 ( L_5 , V_208 -> V_87 , V_208 -> V_65 ) ;
F_223 ( & V_208 -> V_178 , & V_206 -> V_209 ) ;
F_211 ( V_208 ) ;
}
static void F_224 ( struct V_204 * V_5 , unsigned long V_87 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_87 = V_87 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_204 * F_225 ( unsigned long V_87 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_204 * V_208 ;
struct V_1 * V_227 ;
V_208 = F_23 ( V_216 , V_39 ) ;
if ( ! V_208 )
return NULL ;
V_227 = F_86 ( V_4 ) ;
if ( F_87 ( V_227 ) ) {
F_27 ( V_216 , V_208 ) ;
return NULL ;
}
V_227 -> V_12 |= V_228 ;
F_224 ( V_208 , V_87 , V_65 , V_227 ) ;
return V_208 ;
}
static int F_226 ( struct V_205 * V_206 , unsigned long V_87 ,
unsigned long V_65 , struct V_204 * V_54 )
{
struct V_204 * V_208 ;
struct V_204 * V_229 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_230:
F_210 ( & V_206 -> V_215 ) ;
V_208 = F_203 ( V_206 , V_87 , V_65 ) ;
while ( V_208 && V_208 -> V_87 < V_65 ) {
struct V_207 * V_79 = F_227 ( & V_208 -> V_178 ) ;
if ( V_208 -> V_87 >= V_87 ) {
if ( V_208 -> V_65 <= V_65 )
F_222 ( V_206 , V_208 ) ;
else
V_208 -> V_87 = V_65 ;
} else {
if ( V_208 -> V_65 > V_65 ) {
if ( ! V_229 )
goto V_231;
* F_19 = * V_208 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_224 ( V_229 , V_65 , V_208 -> V_65 , F_19 ) ;
V_208 -> V_65 = V_87 ;
F_206 ( V_206 , V_229 ) ;
V_229 = NULL ;
F_19 = NULL ;
break;
} else
V_208 -> V_65 = V_87 ;
}
if ( ! V_79 )
break;
V_208 = F_204 ( V_79 , struct V_204 , V_178 ) ;
}
if ( V_54 )
F_206 ( V_206 , V_54 ) ;
F_60 ( & V_206 -> V_215 ) ;
V_14 = 0 ;
V_103:
if ( F_19 )
F_89 ( F_19 ) ;
if ( V_229 )
F_27 ( V_216 , V_229 ) ;
return V_14 ;
V_231:
F_60 ( & V_206 -> V_215 ) ;
V_14 = - V_40 ;
V_229 = F_23 ( V_216 , V_39 ) ;
if ( ! V_229 )
goto V_103;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_103;
goto V_230;
}
void F_228 ( struct V_205 * V_206 , struct V_1 * V_192 )
{
int V_14 ;
V_206 -> V_209 = V_232 ;
F_229 ( & V_206 -> V_215 ) ;
if ( V_192 ) {
struct V_57 V_233 ;
struct V_1 * V_54 ;
F_100 ( V_115 ) ;
if ( ! V_115 )
goto V_234;
V_54 = F_19 ( V_192 -> V_8 , V_192 -> V_12 , & V_192 -> V_30 . V_31 ) ;
if ( F_87 ( V_54 ) )
goto V_235;
F_101 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_192 -> V_30 . V_31 , V_115 ) ;
F_102 ( V_47 ) ;
if ( V_14 )
goto V_236;
memset ( & V_233 , 0 , sizeof( struct V_57 ) ) ;
V_233 . V_94 = V_237 ;
F_230 ( V_206 , & V_233 , V_54 ) ;
V_236:
F_89 ( V_54 ) ;
V_235:
F_103 ( V_115 ) ;
V_234:
F_89 ( V_192 ) ;
}
}
int F_230 ( struct V_205 * V_238 ,
struct V_57 * V_58 , struct V_1 * V_239 )
{
int V_88 ;
struct V_204 * V_54 = NULL ;
unsigned long V_240 = F_231 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_99 ,
V_240 , V_239 ? V_239 -> V_8 : - 1 ,
V_239 ? V_239 -> V_12 : - 1 ,
V_239 ? F_21 ( V_239 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_239 ) {
V_54 = F_225 ( V_58 -> V_99 , V_58 -> V_99 + V_240 , V_239 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_88 = F_226 ( V_238 , V_58 -> V_99 , V_58 -> V_99 + V_240 , V_54 ) ;
if ( V_88 && V_54 )
F_211 ( V_54 ) ;
return V_88 ;
}
void F_232 ( struct V_205 * V_3 )
{
struct V_204 * V_208 ;
struct V_207 * V_79 ;
if ( ! V_3 -> V_209 . V_207 )
return;
F_210 ( & V_3 -> V_215 ) ;
V_79 = F_233 ( & V_3 -> V_209 ) ;
while ( V_79 ) {
V_208 = F_204 ( V_79 , struct V_204 , V_178 ) ;
V_79 = F_227 ( & V_208 -> V_178 ) ;
F_222 ( V_3 , V_208 ) ;
}
F_60 ( & V_3 -> V_215 ) ;
}
static void T_12 F_234 ( void )
{
bool V_241 = false ;
if ( F_235 ( V_242 ) )
V_241 = true ;
if ( V_243 > 1 && ! V_244 ) {
F_236 ( V_245 L_7
L_8 ) ;
F_237 ( V_241 ) ;
}
}
static int T_12 F_238 ( char * V_246 )
{
int V_14 = 0 ;
if ( ! V_246 )
goto V_113;
V_244 = true ;
if ( ! strcmp ( V_246 , L_9 ) ) {
F_237 ( true ) ;
V_14 = 1 ;
} else if ( ! strcmp ( V_246 , L_10 ) ) {
F_237 ( false ) ;
V_14 = 1 ;
}
V_113:
if ( ! V_14 )
F_236 ( V_247 L_11 ) ;
return V_14 ;
}
static inline void T_12 F_234 ( void )
{
}
void T_12 F_239 ( void )
{
T_1 F_173 ;
unsigned long V_248 = 0 ;
int V_72 , V_249 = 0 ;
V_38 = F_240 ( L_12 ,
sizeof( struct V_1 ) ,
0 , V_250 , NULL ) ;
V_216 = F_240 ( L_13 ,
sizeof( struct V_204 ) ,
0 , V_250 , NULL ) ;
F_241 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_242 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_149 | V_224 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_105 ( F_173 ) ;
F_243 (nid, N_MEMORY) {
unsigned long V_251 = F_244 ( V_72 ) ;
if ( V_248 < V_251 ) {
V_248 = V_251 ;
V_249 = V_72 ;
}
if ( ( V_251 << V_109 ) >= ( 16 << 20 ) )
F_106 ( V_72 , F_173 ) ;
}
if ( F_168 ( F_11 ( F_173 ) ) )
F_106 ( V_249 , F_173 ) ;
if ( F_99 ( V_116 , 0 , & F_173 ) )
F_236 ( L_14 ) ;
F_234 () ;
}
void F_245 ( void )
{
F_99 ( V_35 , 0 , NULL ) ;
}
int F_246 ( char * V_246 , struct V_1 * * V_192 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_145 ;
T_1 V_18 ;
char * V_252 = strchr ( V_246 , ':' ) ;
char * V_12 = strchr ( V_246 , '=' ) ;
int V_88 = 1 ;
if ( V_252 ) {
* V_252 ++ = '\0' ;
if ( F_247 ( V_252 , V_18 ) )
goto V_113;
if ( ! F_248 ( V_18 , V_10 [ V_11 ] ) )
goto V_113;
} else
F_105 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_253 ; V_8 ++ ) {
if ( ! strcmp ( V_246 , V_254 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_253 )
goto V_113;
switch ( V_8 ) {
case V_27 :
if ( V_252 ) {
char * V_255 = V_252 ;
while ( isdigit ( * V_255 ) )
V_255 ++ ;
if ( * V_255 )
goto V_113;
}
break;
case V_116 :
if ( ! V_252 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_252 )
goto V_113;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_252 )
V_88 = 0 ;
goto V_113;
case V_118 :
if ( ! V_252 )
goto V_113;
}
V_145 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_15 ) )
V_145 |= V_36 ;
else if ( ! strcmp ( V_12 , L_16 ) )
V_145 |= V_28 ;
else
goto V_113;
}
V_54 = F_19 ( V_8 , V_145 , & V_18 ) ;
if ( F_87 ( V_54 ) )
goto V_113;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_252 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_88 = 0 ;
V_113:
if ( V_252 )
* -- V_252 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_88 )
* V_192 = V_54 ;
return V_88 ;
}
void F_249 ( char * V_256 , int V_257 , struct V_1 * V_4 )
{
char * V_3 = V_256 ;
T_1 V_18 = V_258 ;
unsigned short V_8 = V_35 ;
unsigned short V_12 = 0 ;
if ( V_4 && V_4 != & V_117 ) {
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
F_106 ( V_4 -> V_20 . V_22 , V_18 ) ;
break;
case V_118 :
case V_116 :
V_18 = V_4 -> V_20 . V_18 ;
break;
default:
F_141 ( 1 ) ;
snprintf ( V_3 , V_257 , L_17 ) ;
return;
}
V_3 += snprintf ( V_3 , V_257 , L_18 , V_254 [ V_8 ] ) ;
if ( V_12 & V_13 ) {
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_19 ) ;
if ( V_12 & V_36 )
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_15 ) ;
else if ( V_12 & V_28 )
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_16 ) ;
}
if ( ! F_11 ( V_18 ) ) {
V_3 += snprintf ( V_3 , V_256 + V_257 - V_3 , L_20 ) ;
V_3 += F_250 ( V_3 , V_256 + V_257 - V_3 , V_18 ) ;
}
}
