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
F_54 ( & V_58 -> V_70 -> V_77 ) ;
V_71 = F_55 ( F_56 ( ( T_3 * ) V_63 ) ) ;
V_72 = F_49 ( V_71 ) ;
if ( F_33 ( V_72 , * V_18 ) == ! ! ( V_12 & V_73 ) )
goto V_78;
if ( V_12 & ( V_75 ) ||
( V_12 & V_74 && F_57 ( V_71 ) == 1 ) )
F_58 ( V_71 , V_66 ) ;
V_78:
F_59 ( & V_58 -> V_70 -> V_77 ) ;
#else
F_31 () ;
#endif
}
static inline int F_60 ( struct V_57 * V_58 , T_5 * V_79 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_2 * V_63 ;
unsigned long V_80 ;
V_63 = F_61 ( V_79 , V_64 ) ;
do {
V_80 = F_62 ( V_64 , V_65 ) ;
if ( ! F_63 ( * V_63 ) )
continue;
if ( F_64 ( * V_63 ) && F_65 ( V_58 ) ) {
F_52 ( V_58 , V_63 , V_18 ,
V_12 , V_66 ) ;
continue;
}
F_66 ( V_58 , V_64 , V_63 ) ;
if ( F_67 ( V_63 ) )
continue;
if ( F_44 ( V_58 , V_63 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_63 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_68 ( struct V_57 * V_58 , T_6 * V_82 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_5 * V_79 ;
unsigned long V_80 ;
V_79 = F_69 ( V_82 , V_64 ) ;
do {
V_80 = F_70 ( V_64 , V_65 ) ;
if ( F_71 ( * V_79 ) && F_65 ( V_58 ) )
continue;
if ( F_72 ( V_79 ) )
continue;
if ( F_60 ( V_58 , V_79 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_79 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
static inline int F_73 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_6 * V_82 ;
unsigned long V_80 ;
V_82 = F_74 ( V_58 -> V_70 , V_64 ) ;
do {
V_80 = F_75 ( V_64 , V_65 ) ;
if ( F_76 ( V_82 ) )
continue;
if ( F_68 ( V_58 , V_82 , V_64 , V_80 , V_18 ,
V_12 , V_66 ) )
return - V_81 ;
} while ( V_82 ++ , V_64 = V_80 , V_64 != V_65 );
return 0 ;
}
unsigned long F_77 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_83 ;
F_78 ( V_84 != V_85 ) ;
V_83 = F_79 ( V_58 , V_64 , V_65 , V_58 -> V_86 , 0 , 1 ) ;
if ( V_83 )
F_80 ( V_87 , V_83 ) ;
return V_83 ;
}
static unsigned long F_77 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static struct V_57 *
F_81 ( struct V_55 * V_56 , unsigned long V_88 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_89 ;
struct V_57 * V_90 , * V_58 , * V_91 ;
V_90 = F_82 ( V_56 , V_88 ) ;
if ( ! V_90 )
return F_22 ( - V_92 ) ;
V_91 = NULL ;
for ( V_58 = V_90 ; V_58 && V_58 -> V_93 < V_65 ; V_58 = V_58 -> V_61 ) {
unsigned long V_94 = V_58 -> V_95 ;
if ( V_94 > V_65 )
V_94 = V_65 ;
if ( V_58 -> V_93 > V_88 )
V_88 = V_58 -> V_93 ;
if ( ! ( V_12 & V_96 ) ) {
if ( ! V_58 -> V_61 && V_58 -> V_95 < V_65 )
return F_22 ( - V_92 ) ;
if ( V_91 && V_91 -> V_95 < V_58 -> V_93 )
return F_22 ( - V_92 ) ;
}
if ( V_12 & V_97 ) {
F_77 ( V_58 , V_88 , V_94 ) ;
goto V_80;
}
if ( ( V_12 & V_98 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_83 ( V_58 ) ) ) {
V_89 = F_73 ( V_58 , V_88 , V_94 , V_18 ,
V_12 , V_66 ) ;
if ( V_89 ) {
V_90 = F_22 ( V_89 ) ;
break;
}
}
V_80:
V_91 = V_58 ;
}
return V_90 ;
}
static int F_84 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_89 ;
struct V_1 * V_99 ;
struct V_1 * V_54 ;
F_20 ( L_2 ,
V_58 -> V_93 , V_58 -> V_95 , V_58 -> V_100 ,
V_58 -> V_101 , V_58 -> V_102 ,
V_58 -> V_101 ? V_58 -> V_101 -> V_103 : NULL ) ;
V_54 = F_85 ( V_4 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_58 -> V_101 && V_58 -> V_101 -> V_103 ) {
V_89 = V_58 -> V_101 -> V_103 ( V_58 , V_54 ) ;
if ( V_89 )
goto V_104;
}
V_99 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_88 ( V_99 ) ;
return 0 ;
V_104:
F_88 ( V_54 ) ;
return V_89 ;
}
static int F_89 ( struct V_55 * V_56 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_105 )
{
struct V_57 * V_80 ;
struct V_57 * V_91 ;
struct V_57 * V_58 ;
int V_89 = 0 ;
T_7 V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
V_58 = F_82 ( V_56 , V_88 ) ;
if ( ! V_58 || V_58 -> V_93 > V_88 )
return - V_92 ;
V_91 = V_58 -> V_109 ;
if ( V_88 > V_58 -> V_93 )
V_91 = V_58 ;
for (; V_58 && V_58 -> V_93 < V_65 ; V_91 = V_58 , V_58 = V_80 ) {
V_80 = V_58 -> V_61 ;
V_107 = F_90 ( V_88 , V_58 -> V_93 ) ;
V_108 = F_91 ( V_65 , V_58 -> V_95 ) ;
if ( F_92 ( F_93 ( V_58 ) , V_105 ) )
continue;
V_106 = V_58 -> V_100 +
( ( V_107 - V_58 -> V_93 ) >> V_110 ) ;
V_91 = F_94 ( V_56 , V_91 , V_107 , V_108 , V_58 -> V_111 ,
V_58 -> V_112 , V_58 -> V_102 , V_106 ,
V_105 ) ;
if ( V_91 ) {
V_58 = V_91 ;
V_80 = V_58 -> V_61 ;
if ( F_92 ( F_93 ( V_58 ) , V_105 ) )
continue;
goto V_113;
}
if ( V_58 -> V_93 != V_107 ) {
V_89 = F_95 ( V_58 -> V_70 , V_58 , V_107 , 1 ) ;
if ( V_89 )
goto V_114;
}
if ( V_58 -> V_95 != V_108 ) {
V_89 = F_95 ( V_58 -> V_70 , V_58 , V_108 , 0 ) ;
if ( V_89 )
goto V_114;
}
V_113:
V_89 = F_84 ( V_58 , V_105 ) ;
if ( V_89 )
goto V_114;
}
V_114:
return V_89 ;
}
void F_96 ( struct V_2 * V_3 )
{
if ( V_3 -> V_1 )
V_3 -> V_12 |= V_115 ;
else
V_3 -> V_12 &= ~ V_115 ;
}
static void F_97 ( void )
{
F_96 ( V_47 ) ;
}
static long F_98 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_99 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_99 ( V_116 ) ;
int V_14 ;
if ( ! V_116 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_86 ( V_54 ) ) {
V_14 = F_87 ( V_54 ) ;
goto V_114;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_100 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_116 ) ;
if ( V_14 ) {
F_101 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_54 ) ;
goto V_114;
}
V_99 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
F_97 () ;
if ( V_54 && V_54 -> V_8 == V_117 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_101 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_88 ( V_99 ) ;
V_14 = 0 ;
V_114:
F_102 ( V_116 ) ;
return V_14 ;
}
static void F_103 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_104 ( * V_18 ) ;
if ( V_3 == & V_118 )
return;
switch ( V_3 -> V_8 ) {
case V_119 :
case V_117 :
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
int V_89 ;
V_89 = F_107 ( V_47 , V_56 , V_64 & V_120 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_89 >= 0 ) {
V_89 = F_49 ( V_3 ) ;
F_108 ( V_3 ) ;
}
return V_89 ;
}
static long F_109 ( int * V_34 , T_1 * V_121 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_89 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_12 &
~ ( unsigned long ) ( V_122 | V_123 | V_124 ) )
return - V_19 ;
if ( V_12 & V_124 ) {
if ( V_12 & ( V_122 | V_123 ) )
return - V_19 ;
* V_34 = 0 ;
F_100 ( V_47 ) ;
* V_121 = V_26 ;
F_101 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_123 ) {
F_110 ( & V_56 -> V_59 ) ;
V_58 = F_111 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_112 ( & V_56 -> V_59 ) ;
return - V_92 ;
}
if ( V_58 -> V_101 && V_58 -> V_101 -> V_125 )
V_4 = V_58 -> V_101 -> V_125 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_118 ;
if ( V_12 & V_122 ) {
if ( V_12 & V_123 ) {
V_89 = F_106 ( V_56 , V_64 ) ;
if ( V_89 < 0 )
goto V_114;
* V_34 = V_89 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_117 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_89 = - V_19 ;
goto V_114;
}
} else {
* V_34 = V_4 == & V_118 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_112 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_89 = 0 ;
if ( V_121 ) {
if ( F_5 ( V_4 ) ) {
* V_121 = V_4 -> V_30 . V_31 ;
} else {
F_100 ( V_47 ) ;
F_103 ( V_4 , V_121 ) ;
F_101 ( V_47 ) ;
}
}
V_114:
F_113 ( V_4 ) ;
if ( V_58 )
F_112 ( & V_47 -> V_56 -> V_59 ) ;
return V_89 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_126 * V_127 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_57 ( V_71 ) == 1 ) {
if ( ! F_114 ( V_71 ) ) {
F_115 ( & V_71 -> V_128 , V_127 ) ;
F_116 ( V_71 , V_129 +
F_117 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_118 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_130 )
{
if ( F_119 ( V_71 ) )
return F_120 ( F_121 ( F_122 ( V_71 ) ) ,
V_5 ) ;
else
return F_123 ( V_5 , V_131 , 0 ) ;
}
static int F_124 ( struct V_55 * V_56 , int V_132 , int V_133 ,
int V_12 )
{
T_1 V_121 ;
F_125 ( V_127 ) ;
int V_89 = 0 ;
F_104 ( V_121 ) ;
F_105 ( V_132 , V_121 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_81 ( V_56 , V_56 -> V_60 -> V_93 , V_56 -> V_134 , & V_121 ,
V_12 | V_96 , & V_127 ) ;
if ( ! F_126 ( & V_127 ) ) {
V_89 = F_127 ( & V_127 , F_118 , V_133 ,
V_135 , V_136 ) ;
if ( V_89 )
F_128 ( & V_127 ) ;
}
return V_89 ;
}
int F_129 ( struct V_55 * V_56 , const T_1 * V_137 ,
const T_1 * V_138 , int V_12 )
{
int V_139 = 0 ;
int V_89 ;
T_1 V_17 ;
V_89 = F_130 () ;
if ( V_89 )
return V_89 ;
F_110 ( & V_56 -> V_59 ) ;
V_89 = F_131 ( V_56 , V_137 , V_138 , V_12 ) ;
if ( V_89 )
goto V_114;
V_17 = * V_137 ;
while ( ! F_11 ( V_17 ) ) {
int V_140 , V_141 ;
int V_132 = - 1 ;
int V_133 = 0 ;
F_132 (s, tmp) {
if ( ( F_8 ( * V_137 ) != F_8 ( * V_138 ) ) &&
( F_33 ( V_140 , * V_138 ) ) )
continue;
V_141 = F_36 ( V_140 , * V_137 , * V_138 ) ;
if ( V_140 == V_141 )
continue;
V_132 = V_140 ;
V_133 = V_141 ;
if ( ! F_33 ( V_133 , V_17 ) )
break;
}
if ( V_132 == - 1 )
break;
F_133 ( V_132 , V_17 ) ;
V_89 = F_124 ( V_56 , V_132 , V_133 , V_12 ) ;
if ( V_89 > 0 )
V_139 += V_89 ;
if ( V_89 < 0 )
break;
}
V_114:
F_112 ( & V_56 -> V_59 ) ;
if ( V_89 < 0 )
return V_89 ;
return V_139 ;
}
static struct V_71 * F_134 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_130 )
{
struct V_57 * V_58 = (struct V_57 * ) V_66 ;
unsigned long V_142 ( V_143 ) ;
while ( V_58 ) {
V_143 = F_135 ( V_71 , V_58 ) ;
if ( V_143 != - V_92 )
break;
V_58 = V_58 -> V_61 ;
}
F_136 ( ! V_58 ) ;
if ( F_119 ( V_71 ) )
return F_137 ( V_58 , V_143 , 1 ) ;
return F_138 ( V_131 , V_58 , V_143 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_126 * V_127 ,
unsigned long V_12 )
{
}
int F_129 ( struct V_55 * V_56 , const T_1 * V_137 ,
const T_1 * V_138 , int V_12 )
{
return - V_144 ;
}
static struct V_71 * F_134 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_130 )
{
return NULL ;
}
static long F_139 ( unsigned long V_88 , unsigned long V_145 ,
unsigned short V_8 , unsigned short V_146 ,
T_1 * V_121 , unsigned long V_12 )
{
struct V_57 * V_58 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_89 ;
F_125 ( V_127 ) ;
if ( V_12 & ~ ( unsigned long ) V_147 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_140 ( V_148 ) )
return - V_149 ;
if ( V_88 & ~ V_120 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_98 ;
V_145 = ( V_145 + V_76 - 1 ) & V_120 ;
V_65 = V_88 + V_145 ;
if ( V_65 < V_88 )
return - V_19 ;
if ( V_65 == V_88 )
return 0 ;
V_54 = F_19 ( V_8 , V_146 , V_121 ) ;
if ( F_86 ( V_54 ) )
return F_87 ( V_54 ) ;
if ( V_12 & V_97 )
V_54 -> V_12 |= V_150 ;
if ( ! V_54 )
V_12 |= V_96 ;
F_20 ( L_3 ,
V_88 , V_88 + V_145 , V_8 , V_146 ,
V_121 ? F_21 ( * V_121 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_89 = F_130 () ;
if ( V_89 )
goto V_151;
}
{
F_99 ( V_116 ) ;
if ( V_116 ) {
F_42 ( & V_56 -> V_59 ) ;
F_100 ( V_47 ) ;
V_89 = F_15 ( V_54 , V_121 , V_116 ) ;
F_101 ( V_47 ) ;
if ( V_89 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_89 = - V_40 ;
F_102 ( V_116 ) ;
}
if ( V_89 )
goto V_151;
V_58 = F_81 ( V_56 , V_88 , V_65 , V_121 ,
V_12 | V_73 , & V_127 ) ;
V_89 = F_87 ( V_58 ) ;
if ( ! F_86 ( V_58 ) )
V_89 = F_89 ( V_56 , V_88 , V_65 , V_54 ) ;
if ( ! V_89 ) {
int V_152 = 0 ;
if ( ! F_126 ( & V_127 ) ) {
F_141 ( V_12 & V_97 ) ;
V_152 = F_127 ( & V_127 , F_134 ,
( unsigned long ) V_58 ,
V_135 , V_153 ) ;
if ( V_152 )
F_128 ( & V_127 ) ;
}
if ( V_152 && ( V_12 & V_98 ) )
V_89 = - V_81 ;
} else
F_142 ( & V_127 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_151:
F_88 ( V_54 ) ;
return V_89 ;
}
static int F_143 ( T_1 * V_18 , const unsigned long T_8 * V_121 ,
unsigned long V_154 )
{
unsigned long V_155 ;
unsigned long V_156 ;
unsigned long V_157 ;
-- V_154 ;
F_104 ( * V_18 ) ;
if ( V_154 == 0 || ! V_121 )
return 0 ;
if ( V_154 > V_76 * V_158 )
return - V_19 ;
V_156 = F_144 ( V_154 ) ;
if ( ( V_154 % V_159 ) == 0 )
V_157 = ~ 0UL ;
else
V_157 = ( 1UL << ( V_154 % V_159 ) ) - 1 ;
if ( V_156 > F_144 ( V_49 ) ) {
if ( V_156 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_155 = F_144 ( V_49 ) ; V_155 < V_156 ; V_155 ++ ) {
unsigned long V_160 ;
if ( F_145 ( V_160 , V_121 + V_155 ) )
return - V_92 ;
if ( V_155 == V_156 - 1 ) {
if ( V_160 & V_157 )
return - V_19 ;
} else if ( V_160 )
return - V_19 ;
}
V_156 = F_144 ( V_49 ) ;
V_157 = ~ 0UL ;
}
if ( F_146 ( F_21 ( * V_18 ) , V_121 , V_156 *sizeof( unsigned long ) ) )
return - V_92 ;
F_21 ( * V_18 ) [ V_156 - 1 ] &= V_157 ;
return 0 ;
}
static int F_147 ( unsigned long T_8 * V_161 , unsigned long V_154 ,
T_1 * V_18 )
{
unsigned long V_162 = F_148 ( V_154 - 1 , 64 ) / 8 ;
const int V_163 = F_144 ( V_49 ) * sizeof( long ) ;
if ( V_162 > V_163 ) {
if ( V_162 > V_76 )
return - V_19 ;
if ( F_149 ( ( char T_8 * ) V_161 + V_163 , V_162 - V_163 ) )
return - V_92 ;
V_162 = V_163 ;
}
return F_150 ( V_161 , F_21 ( * V_18 ) , V_162 ) ? - V_92 : 0 ;
}
T_9 long F_151 ( int T_8 * V_34 ,
T_10 T_8 * V_121 ,
T_10 V_154 ,
T_10 V_64 , T_10 V_12 )
{
long V_89 ;
unsigned long T_8 * V_164 = NULL ;
unsigned long V_165 , V_166 ;
F_152 ( V_167 , V_49 ) ;
V_165 = F_153 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_166 = F_148 ( V_165 , V_159 ) / 8 ;
if ( V_121 )
V_164 = F_154 ( V_166 ) ;
V_89 = F_155 ( V_34 , V_164 , V_165 + 1 , V_64 , V_12 ) ;
if ( ! V_89 && V_121 ) {
unsigned long V_168 ;
V_168 = F_153 (unsigned long, sizeof(bm), alloc_size) ;
V_89 = F_146 ( V_167 , V_164 , V_168 ) ;
V_89 |= F_149 ( V_121 , F_148 ( V_154 - 1 , 8 ) / 8 ) ;
V_89 |= F_156 ( V_121 , V_167 , V_165 ) ;
}
return V_89 ;
}
T_9 long F_157 ( int V_8 , T_10 T_8 * V_121 ,
T_10 V_154 )
{
long V_89 = 0 ;
unsigned long T_8 * V_164 = NULL ;
unsigned long V_165 , V_166 ;
F_152 ( V_167 , V_49 ) ;
V_165 = F_153 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_166 = F_148 ( V_165 , V_159 ) / 8 ;
if ( V_121 ) {
V_89 = F_158 ( V_167 , V_121 , V_165 ) ;
V_164 = F_154 ( V_166 ) ;
V_89 |= F_150 ( V_164 , V_167 , V_166 ) ;
}
if ( V_89 )
return - V_92 ;
return F_159 ( V_8 , V_164 , V_165 + 1 ) ;
}
T_9 long F_160 ( T_10 V_88 , T_10 V_145 ,
T_10 V_8 , T_10 T_8 * V_121 ,
T_10 V_154 , T_10 V_12 )
{
long V_89 = 0 ;
unsigned long T_8 * V_164 = NULL ;
unsigned long V_165 , V_166 ;
T_1 V_167 ;
V_165 = F_153 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_166 = F_148 ( V_165 , V_159 ) / 8 ;
if ( V_121 ) {
V_89 = F_158 ( F_21 ( V_167 ) , V_121 , V_165 ) ;
V_164 = F_154 ( V_166 ) ;
V_89 |= F_150 ( V_164 , F_21 ( V_167 ) , V_166 ) ;
}
if ( V_89 )
return - V_92 ;
return F_161 ( V_88 , V_145 , V_8 , V_164 , V_165 + 1 , V_12 ) ;
}
struct V_1 * F_162 ( struct V_2 * V_169 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_169 ) ;
if ( V_58 ) {
if ( V_58 -> V_101 && V_58 -> V_101 -> V_125 ) {
struct V_1 * V_170 = V_58 -> V_101 -> V_125 ( V_58 ,
V_64 ) ;
if ( V_170 )
V_4 = V_170 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_163 ( V_4 ) )
F_164 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_118 ;
return V_4 ;
}
static int F_165 ( struct V_1 * V_34 , enum V_171 V_172 )
{
enum V_171 V_173 = V_174 ;
F_136 ( V_173 == V_175 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_176 ] ) )
V_173 = V_175 ;
return V_172 >= V_173 ;
}
static T_1 * F_166 ( T_11 V_177 , struct V_1 * V_34 )
{
if ( F_167 ( V_34 -> V_8 == V_119 ) &&
F_165 ( V_34 , F_168 ( V_177 ) ) &&
F_169 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_178 * F_170 ( T_11 V_177 , struct V_1 * V_34 ,
int V_179 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_179 = V_34 -> V_20 . V_22 ;
break;
case V_119 :
if ( F_167 ( V_177 & V_180 ) &&
F_167 ( ! F_33 ( V_179 , V_34 -> V_20 . V_18 ) ) )
V_179 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_171 ( V_179 , V_177 ) ;
}
static unsigned F_172 ( struct V_1 * V_34 )
{
unsigned V_72 , V_80 ;
struct V_2 * V_181 = V_47 ;
V_72 = V_181 -> V_48 ;
V_80 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_80 >= V_49 )
V_80 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_80 < V_49 )
V_181 -> V_48 = V_80 ;
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
case V_117 :
return F_172 ( V_34 ) ;
case V_119 : {
struct V_178 * V_178 ;
struct V_172 * V_172 ;
enum V_171 V_182 = F_168 ( V_39 ) ;
V_178 = & F_175 ( F_2 () ) -> V_183 [ 0 ] ;
( void ) F_176 ( V_178 , V_182 ,
& V_34 -> V_20 . V_18 ,
& V_172 ) ;
return V_172 ? V_172 -> V_5 : F_2 () ;
}
default:
F_31 () ;
}
}
static unsigned F_177 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_184 )
{
unsigned V_185 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_186 ;
int V_187 ;
int V_72 = - 1 ;
if ( ! V_185 )
return F_2 () ;
V_186 = ( unsigned int ) V_184 % V_185 ;
V_187 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_187 ++ ;
} while ( V_187 <= V_186 );
return V_72 ;
}
static inline unsigned F_178 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_188 )
{
if ( V_58 ) {
unsigned long V_184 ;
F_136 ( V_188 < V_110 ) ;
V_184 = V_58 -> V_100 >> ( V_188 - V_110 ) ;
V_184 += ( V_64 - V_58 -> V_93 ) >> V_188 ;
return F_177 ( V_4 , V_58 , V_184 ) ;
} else
return F_172 ( V_4 ) ;
}
int F_179 ( const T_1 * V_189 )
{
int V_30 , V_190 = - 1 ;
V_30 = F_8 ( * V_189 ) ;
if ( V_30 )
V_190 = F_180 ( V_189 -> V_191 ,
F_181 () % V_30 , V_49 ) ;
return V_190 ;
}
struct V_178 * F_182 ( struct V_57 * V_58 , unsigned long V_64 ,
T_11 V_192 , struct V_1 * * V_193 ,
T_1 * * V_9 )
{
struct V_178 * V_194 ;
* V_193 = F_162 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_167 ( ( * V_193 ) -> V_8 == V_117 ) ) {
V_194 = F_171 ( F_178 ( * V_193 , V_58 , V_64 ,
F_183 ( F_184 ( V_58 ) ) ) , V_192 ) ;
} else {
V_194 = F_170 ( V_192 , * V_193 , F_2 () ) ;
if ( ( * V_193 ) -> V_8 == V_119 )
* V_9 = & ( * V_193 ) -> V_20 . V_18 ;
}
return V_194 ;
}
bool F_185 ( T_1 * V_161 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_161 && V_47 -> V_1 ) )
return false ;
F_100 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_186 ( V_161 , V_72 ) ;
break;
case V_119 :
case V_117 :
* V_161 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_101 ( V_47 ) ;
return true ;
}
bool F_187 ( struct V_2 * V_53 ,
const T_1 * V_161 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_161 )
return V_14 ;
F_100 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_114;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_119 :
case V_117 :
V_14 = F_4 ( V_1 -> V_20 . V_18 , * V_161 ) ;
break;
default:
F_31 () ;
}
V_114:
F_101 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_188 ( T_11 V_177 , unsigned V_195 ,
unsigned V_72 )
{
struct V_178 * V_194 ;
struct V_71 * V_71 ;
V_194 = F_171 ( V_72 , V_177 ) ;
V_71 = F_189 ( V_177 , V_195 , V_194 ) ;
if ( V_71 && F_190 ( V_71 ) == F_191 ( & V_194 -> V_196 [ 0 ] ) )
F_116 ( V_71 , V_197 ) ;
return V_71 ;
}
struct V_71 *
F_192 ( T_11 V_177 , int V_195 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_198 ;
V_199:
V_4 = F_162 ( V_47 , V_58 , V_64 ) ;
V_198 = F_193 () ;
if ( F_167 ( V_4 -> V_8 == V_117 ) ) {
unsigned V_72 ;
V_72 = F_178 ( V_4 , V_58 , V_64 , V_110 + V_195 ) ;
F_113 ( V_4 ) ;
V_71 = F_188 ( V_177 , V_195 , V_72 ) ;
if ( F_167 ( ! F_194 ( V_198 ) && ! V_71 ) )
goto V_199;
return V_71 ;
}
V_71 = F_195 ( V_177 , V_195 ,
F_170 ( V_177 , V_4 , V_5 ) ,
F_166 ( V_177 , V_4 ) ) ;
if ( F_167 ( F_163 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_167 ( ! F_194 ( V_198 ) && ! V_71 ) )
goto V_199;
return V_71 ;
}
struct V_71 * F_196 ( T_11 V_177 , unsigned V_195 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_198 ;
if ( ! V_4 || F_174 () || ( V_177 & V_180 ) )
V_4 = & V_118 ;
V_199:
V_198 = F_193 () ;
if ( V_4 -> V_8 == V_117 )
V_71 = F_188 ( V_177 , V_195 , F_172 ( V_4 ) ) ;
else
V_71 = F_195 ( V_177 , V_195 ,
F_170 ( V_177 , V_4 , F_2 () ) ,
F_166 ( V_177 , V_4 ) ) ;
if ( F_167 ( ! F_194 ( V_198 ) && ! V_71 ) )
goto V_199;
return V_71 ;
}
int F_197 ( struct V_57 * V_200 , struct V_57 * V_201 )
{
struct V_1 * V_4 = F_85 ( F_93 ( V_200 ) ) ;
if ( F_86 ( V_4 ) )
return F_87 ( V_4 ) ;
V_201 -> V_62 = V_4 ;
return 0 ;
}
struct V_1 * F_198 ( struct V_1 * V_99 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_99 == V_47 -> V_1 ) {
F_100 ( V_47 ) ;
* V_54 = * V_99 ;
F_101 ( V_47 ) ;
} else
* V_54 = * V_99 ;
F_199 () ;
if ( F_200 () ) {
T_1 V_202 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_202 , V_46 ) ;
else
F_37 ( V_54 , & V_202 , V_44 ) ;
}
F_201 () ;
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_202 ( struct V_1 * V_203 , struct V_1 * V_204 )
{
if ( ! V_203 || ! V_204 )
return false ;
if ( V_203 -> V_8 != V_204 -> V_8 )
return false ;
if ( V_203 -> V_12 != V_204 -> V_12 )
return false ;
if ( F_5 ( V_203 ) )
if ( ! F_38 ( V_203 -> V_30 . V_31 , V_204 -> V_30 . V_31 ) )
return false ;
switch ( V_203 -> V_8 ) {
case V_119 :
case V_117 :
return ! ! F_38 ( V_203 -> V_20 . V_18 , V_204 -> V_20 . V_18 ) ;
case V_27 :
return V_203 -> V_20 . V_22 == V_204 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_205 *
F_203 ( struct V_206 * V_207 , unsigned long V_88 , unsigned long V_65 )
{
struct V_208 * V_209 = V_207 -> V_210 . V_208 ;
while ( V_209 ) {
struct V_205 * V_3 = F_204 ( V_209 , struct V_205 , V_179 ) ;
if ( V_88 >= V_3 -> V_65 )
V_209 = V_209 -> V_211 ;
else if ( V_65 <= V_3 -> V_88 )
V_209 = V_209 -> V_212 ;
else
break;
}
if ( ! V_209 )
return NULL ;
for (; ; ) {
struct V_205 * V_30 = NULL ;
struct V_208 * V_91 = F_205 ( V_209 ) ;
if ( ! V_91 )
break;
V_30 = F_204 ( V_91 , struct V_205 , V_179 ) ;
if ( V_30 -> V_65 <= V_88 )
break;
V_209 = V_91 ;
}
return F_204 ( V_209 , struct V_205 , V_179 ) ;
}
static void F_206 ( struct V_206 * V_207 , struct V_205 * V_54 )
{
struct V_208 * * V_3 = & V_207 -> V_210 . V_208 ;
struct V_208 * V_213 = NULL ;
struct V_205 * V_179 ;
while ( * V_3 ) {
V_213 = * V_3 ;
V_179 = F_204 ( V_213 , struct V_205 , V_179 ) ;
if ( V_54 -> V_88 < V_179 -> V_88 )
V_3 = & ( * V_3 ) -> V_212 ;
else if ( V_54 -> V_65 > V_179 -> V_65 )
V_3 = & ( * V_3 ) -> V_211 ;
else
F_31 () ;
}
F_207 ( & V_54 -> V_179 , V_213 , V_3 ) ;
F_208 ( & V_54 -> V_179 , & V_207 -> V_210 ) ;
F_20 ( L_4 , V_54 -> V_88 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_209 ( struct V_206 * V_207 , unsigned long V_214 )
{
struct V_1 * V_4 = NULL ;
struct V_205 * V_215 ;
if ( ! V_207 -> V_210 . V_208 )
return NULL ;
F_54 ( & V_207 -> V_216 ) ;
V_215 = F_203 ( V_207 , V_214 , V_214 + 1 ) ;
if ( V_215 ) {
F_164 ( V_215 -> V_34 ) ;
V_4 = V_215 -> V_34 ;
}
F_59 ( & V_207 -> V_216 ) ;
return V_4 ;
}
static void F_210 ( struct V_205 * V_209 )
{
F_88 ( V_209 -> V_34 ) ;
F_27 ( V_217 , V_209 ) ;
}
int F_211 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_172 * V_172 ;
int V_218 = F_49 ( V_71 ) ;
unsigned long V_106 ;
int V_219 = - 1 ;
int V_14 = - 1 ;
F_136 ( ! V_58 ) ;
V_4 = F_162 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_150 ) )
goto V_114;
switch ( V_4 -> V_8 ) {
case V_117 :
F_136 ( V_64 >= V_58 -> V_95 ) ;
F_136 ( V_64 < V_58 -> V_93 ) ;
V_106 = V_58 -> V_100 ;
V_106 += ( V_64 - V_58 -> V_93 ) >> V_110 ;
V_219 = F_177 ( V_4 , V_58 , V_106 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_219 = F_2 () ;
else
V_219 = V_4 -> V_20 . V_22 ;
break;
case V_119 :
if ( F_33 ( V_218 , V_4 -> V_20 . V_18 ) )
goto V_114;
( void ) F_176 (
F_171 ( F_2 () , V_220 ) ,
F_168 ( V_220 ) ,
& V_4 -> V_20 . V_18 , & V_172 ) ;
V_219 = V_172 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_221 ) {
int V_222 ;
V_219 = F_2 () ;
V_222 = F_212 ( V_71 , V_219 ) ;
if ( V_222 != V_219 )
goto V_114;
}
if ( V_218 != V_219 )
V_14 = V_219 ;
V_114:
F_113 ( V_4 ) ;
return V_14 ;
}
static void F_213 ( struct V_206 * V_207 , struct V_205 * V_209 )
{
F_20 ( L_5 , V_209 -> V_88 , V_209 -> V_65 ) ;
F_214 ( & V_209 -> V_179 , & V_207 -> V_210 ) ;
F_210 ( V_209 ) ;
}
static void F_215 ( struct V_205 * V_5 , unsigned long V_88 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_88 = V_88 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_205 * F_216 ( unsigned long V_88 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_205 * V_209 ;
struct V_1 * V_223 ;
V_209 = F_23 ( V_217 , V_39 ) ;
if ( ! V_209 )
return NULL ;
V_223 = F_85 ( V_4 ) ;
if ( F_86 ( V_223 ) ) {
F_27 ( V_217 , V_209 ) ;
return NULL ;
}
V_223 -> V_12 |= V_224 ;
F_215 ( V_209 , V_88 , V_65 , V_223 ) ;
return V_209 ;
}
static int F_217 ( struct V_206 * V_207 , unsigned long V_88 ,
unsigned long V_65 , struct V_205 * V_54 )
{
struct V_205 * V_209 ;
struct V_205 * V_225 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_226:
F_54 ( & V_207 -> V_216 ) ;
V_209 = F_203 ( V_207 , V_88 , V_65 ) ;
while ( V_209 && V_209 -> V_88 < V_65 ) {
struct V_208 * V_80 = F_218 ( & V_209 -> V_179 ) ;
if ( V_209 -> V_88 >= V_88 ) {
if ( V_209 -> V_65 <= V_65 )
F_213 ( V_207 , V_209 ) ;
else
V_209 -> V_88 = V_65 ;
} else {
if ( V_209 -> V_65 > V_65 ) {
if ( ! V_225 )
goto V_227;
* F_19 = * V_209 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_215 ( V_225 , V_65 , V_209 -> V_65 , F_19 ) ;
V_209 -> V_65 = V_88 ;
F_206 ( V_207 , V_225 ) ;
V_225 = NULL ;
F_19 = NULL ;
break;
} else
V_209 -> V_65 = V_88 ;
}
if ( ! V_80 )
break;
V_209 = F_204 ( V_80 , struct V_205 , V_179 ) ;
}
if ( V_54 )
F_206 ( V_207 , V_54 ) ;
F_59 ( & V_207 -> V_216 ) ;
V_14 = 0 ;
V_104:
if ( F_19 )
F_88 ( F_19 ) ;
if ( V_225 )
F_27 ( V_217 , V_225 ) ;
return V_14 ;
V_227:
F_59 ( & V_207 -> V_216 ) ;
V_14 = - V_40 ;
V_225 = F_23 ( V_217 , V_39 ) ;
if ( ! V_225 )
goto V_104;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_104;
goto V_226;
}
void F_219 ( struct V_206 * V_207 , struct V_1 * V_193 )
{
int V_14 ;
V_207 -> V_210 = V_228 ;
F_220 ( & V_207 -> V_216 ) ;
if ( V_193 ) {
struct V_57 V_229 ;
struct V_1 * V_54 ;
F_99 ( V_116 ) ;
if ( ! V_116 )
goto V_230;
V_54 = F_19 ( V_193 -> V_8 , V_193 -> V_12 , & V_193 -> V_30 . V_31 ) ;
if ( F_86 ( V_54 ) )
goto V_231;
F_100 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_193 -> V_30 . V_31 , V_116 ) ;
F_101 ( V_47 ) ;
if ( V_14 )
goto V_232;
memset ( & V_229 , 0 , sizeof( struct V_57 ) ) ;
V_229 . V_95 = V_233 ;
F_221 ( V_207 , & V_229 , V_54 ) ;
V_232:
F_88 ( V_54 ) ;
V_231:
F_102 ( V_116 ) ;
V_230:
F_88 ( V_193 ) ;
}
}
int F_221 ( struct V_206 * V_234 ,
struct V_57 * V_58 , struct V_1 * V_235 )
{
int V_89 ;
struct V_205 * V_54 = NULL ;
unsigned long V_236 = F_222 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_100 ,
V_236 , V_235 ? V_235 -> V_8 : - 1 ,
V_235 ? V_235 -> V_12 : - 1 ,
V_235 ? F_21 ( V_235 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_235 ) {
V_54 = F_216 ( V_58 -> V_100 , V_58 -> V_100 + V_236 , V_235 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_89 = F_217 ( V_234 , V_58 -> V_100 , V_58 -> V_100 + V_236 , V_54 ) ;
if ( V_89 && V_54 )
F_210 ( V_54 ) ;
return V_89 ;
}
void F_223 ( struct V_206 * V_3 )
{
struct V_205 * V_209 ;
struct V_208 * V_80 ;
if ( ! V_3 -> V_210 . V_208 )
return;
F_54 ( & V_3 -> V_216 ) ;
V_80 = F_224 ( & V_3 -> V_210 ) ;
while ( V_80 ) {
V_209 = F_204 ( V_80 , struct V_205 , V_179 ) ;
V_80 = F_218 ( & V_209 -> V_179 ) ;
F_213 ( V_3 , V_209 ) ;
}
F_59 ( & V_3 -> V_216 ) ;
}
static void T_12 F_225 ( void )
{
bool V_237 = false ;
if ( F_226 ( V_238 ) )
V_237 = true ;
if ( V_239 > 1 && ! V_240 ) {
F_227 ( V_241 L_7
L_8 ) ;
F_228 ( V_237 ) ;
}
}
static int T_12 F_229 ( char * V_242 )
{
int V_14 = 0 ;
if ( ! V_242 )
goto V_114;
V_240 = true ;
if ( ! strcmp ( V_242 , L_9 ) ) {
F_228 ( true ) ;
V_14 = 1 ;
} else if ( ! strcmp ( V_242 , L_10 ) ) {
F_228 ( false ) ;
V_14 = 1 ;
}
V_114:
if ( ! V_14 )
F_227 ( V_243 L_11 ) ;
return V_14 ;
}
static inline void T_12 F_225 ( void )
{
}
void T_12 F_230 ( void )
{
T_1 F_172 ;
unsigned long V_244 = 0 ;
int V_72 , V_245 = 0 ;
V_38 = F_231 ( L_12 ,
sizeof( struct V_1 ) ,
0 , V_246 , NULL ) ;
V_217 = F_231 ( L_13 ,
sizeof( struct V_205 ) ,
0 , V_246 , NULL ) ;
F_232 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_233 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_150 | V_221 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_104 ( F_172 ) ;
F_234 (nid, N_MEMORY) {
unsigned long V_247 = F_235 ( V_72 ) ;
if ( V_244 < V_247 ) {
V_244 = V_247 ;
V_245 = V_72 ;
}
if ( ( V_247 << V_110 ) >= ( 16 << 20 ) )
F_105 ( V_72 , F_172 ) ;
}
if ( F_167 ( F_11 ( F_172 ) ) )
F_105 ( V_245 , F_172 ) ;
if ( F_98 ( V_117 , 0 , & F_172 ) )
F_227 ( L_14 ) ;
F_225 () ;
}
void F_236 ( void )
{
F_98 ( V_35 , 0 , NULL ) ;
}
int F_237 ( char * V_242 , struct V_1 * * V_193 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_146 ;
T_1 V_18 ;
char * V_248 = strchr ( V_242 , ':' ) ;
char * V_12 = strchr ( V_242 , '=' ) ;
int V_89 = 1 ;
if ( V_248 ) {
* V_248 ++ = '\0' ;
if ( F_238 ( V_248 , V_18 ) )
goto V_114;
if ( ! F_239 ( V_18 , V_10 [ V_11 ] ) )
goto V_114;
} else
F_104 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_249 ; V_8 ++ ) {
if ( ! strcmp ( V_242 , V_250 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_249 )
goto V_114;
switch ( V_8 ) {
case V_27 :
if ( V_248 ) {
char * V_251 = V_248 ;
while ( isdigit ( * V_251 ) )
V_251 ++ ;
if ( * V_251 )
goto V_114;
}
break;
case V_117 :
if ( ! V_248 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_248 )
goto V_114;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_248 )
V_89 = 0 ;
goto V_114;
case V_119 :
if ( ! V_248 )
goto V_114;
}
V_146 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_15 ) )
V_146 |= V_36 ;
else if ( ! strcmp ( V_12 , L_16 ) )
V_146 |= V_28 ;
else
goto V_114;
}
V_54 = F_19 ( V_8 , V_146 , & V_18 ) ;
if ( F_86 ( V_54 ) )
goto V_114;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_248 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_89 = 0 ;
V_114:
if ( V_248 )
* -- V_248 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_89 )
* V_193 = V_54 ;
return V_89 ;
}
int F_240 ( char * V_252 , int V_253 , struct V_1 * V_4 )
{
char * V_3 = V_252 ;
int V_254 ;
T_1 V_18 ;
unsigned short V_8 ;
unsigned short V_12 = V_4 ? V_4 -> V_12 : 0 ;
F_17 ( V_253 < strlen ( L_17 ) + strlen ( L_16 ) + 16 ) ;
if ( ! V_4 || V_4 == & V_118 )
V_8 = V_35 ;
else
V_8 = V_4 -> V_8 ;
switch ( V_8 ) {
case V_35 :
F_104 ( V_18 ) ;
break;
case V_27 :
F_104 ( V_18 ) ;
if ( V_12 & V_21 )
V_8 = V_37 ;
else
F_105 ( V_4 -> V_20 . V_22 , V_18 ) ;
break;
case V_119 :
case V_117 :
V_18 = V_4 -> V_20 . V_18 ;
break;
default:
return - V_19 ;
}
V_254 = strlen ( V_250 [ V_8 ] ) ;
if ( V_252 + V_253 < V_3 + V_254 + 1 )
return - V_255 ;
strcpy ( V_3 , V_250 [ V_8 ] ) ;
V_3 += V_254 ;
if ( V_12 & V_13 ) {
if ( V_252 + V_253 < V_3 + 2 )
return - V_255 ;
* V_3 ++ = '=' ;
if ( V_12 & V_36 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_15 ) ;
else if ( V_12 & V_28 )
V_3 += snprintf ( V_3 , V_252 + V_253 - V_3 , L_16 ) ;
}
if ( ! F_11 ( V_18 ) ) {
if ( V_252 + V_253 < V_3 + 2 )
return - V_255 ;
* V_3 ++ = ':' ;
V_3 += F_241 ( V_3 , V_252 + V_253 - V_3 , V_18 ) ;
}
return V_3 - V_252 ;
}
