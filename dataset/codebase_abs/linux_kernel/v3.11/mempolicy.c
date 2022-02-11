static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_1 ;
int V_5 ;
if ( ! V_4 ) {
V_5 = F_2 () ;
if ( V_5 != V_6 )
V_4 = & V_7 [ V_5 ] ;
if ( ! V_4 -> V_8 )
V_4 = NULL ;
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
static inline int F_52 ( struct V_57 * V_58 , T_5 * V_77 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_2 * V_63 ;
unsigned long V_78 ;
V_63 = F_53 ( V_77 , V_64 ) ;
do {
V_78 = F_54 ( V_64 , V_65 ) ;
F_55 ( V_58 , V_64 , V_63 ) ;
if ( F_56 ( V_63 ) )
continue;
if ( F_44 ( V_58 , V_63 , V_64 , V_78 , V_18 ,
V_12 , V_66 ) )
return - V_79 ;
} while ( V_63 ++ , V_64 = V_78 , V_64 != V_65 );
return 0 ;
}
static inline int F_57 ( struct V_57 * V_58 , T_6 * V_80 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_5 * V_77 ;
unsigned long V_78 ;
V_77 = F_58 ( V_80 , V_64 ) ;
do {
V_78 = F_59 ( V_64 , V_65 ) ;
if ( F_60 ( V_77 ) )
continue;
if ( F_52 ( V_58 , V_77 , V_64 , V_78 , V_18 ,
V_12 , V_66 ) )
return - V_79 ;
} while ( V_77 ++ , V_64 = V_78 , V_64 != V_65 );
return 0 ;
}
static inline int F_61 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 ,
void * V_66 )
{
T_6 * V_80 ;
unsigned long V_78 ;
V_80 = F_62 ( V_58 -> V_70 , V_64 ) ;
do {
V_78 = F_63 ( V_64 , V_65 ) ;
if ( F_64 ( V_80 ) )
continue;
if ( F_57 ( V_58 , V_80 , V_64 , V_78 , V_18 ,
V_12 , V_66 ) )
return - V_79 ;
} while ( V_80 ++ , V_64 = V_78 , V_64 != V_65 );
return 0 ;
}
unsigned long F_65 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
int V_81 ;
F_66 ( V_82 != V_83 ) ;
V_81 = F_67 ( V_58 , V_64 , V_65 , V_58 -> V_84 , 0 , 1 ) ;
if ( V_81 )
F_68 ( V_85 , V_81 ) ;
return V_81 ;
}
static unsigned long F_65 ( struct V_57 * V_58 ,
unsigned long V_64 , unsigned long V_65 )
{
return 0 ;
}
static struct V_57 *
F_69 ( struct V_55 * V_56 , unsigned long V_86 , unsigned long V_65 ,
const T_1 * V_18 , unsigned long V_12 , void * V_66 )
{
int V_87 ;
struct V_57 * V_88 , * V_58 , * V_89 ;
V_88 = F_70 ( V_56 , V_86 ) ;
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
if ( F_71 ( V_58 ) )
goto V_78;
if ( V_12 & V_95 ) {
F_65 ( V_58 , V_86 , V_92 ) ;
goto V_78;
}
if ( ( V_12 & V_96 ) ||
( ( V_12 & ( V_74 | V_75 ) ) &&
F_72 ( V_58 ) ) ) {
V_87 = F_61 ( V_58 , V_86 , V_92 , V_18 ,
V_12 , V_66 ) ;
if ( V_87 ) {
V_88 = F_22 ( V_87 ) ;
break;
}
}
V_78:
V_89 = V_58 ;
}
return V_88 ;
}
static int F_73 ( struct V_57 * V_58 ,
struct V_1 * V_4 )
{
int V_87 ;
struct V_1 * V_97 ;
struct V_1 * V_54 ;
F_20 ( L_2 ,
V_58 -> V_91 , V_58 -> V_93 , V_58 -> V_98 ,
V_58 -> V_99 , V_58 -> V_100 ,
V_58 -> V_99 ? V_58 -> V_99 -> V_101 : NULL ) ;
V_54 = F_74 ( V_4 ) ;
if ( F_75 ( V_54 ) )
return F_76 ( V_54 ) ;
if ( V_58 -> V_99 && V_58 -> V_99 -> V_101 ) {
V_87 = V_58 -> V_99 -> V_101 ( V_58 , V_54 ) ;
if ( V_87 )
goto V_102;
}
V_97 = V_58 -> V_62 ;
V_58 -> V_62 = V_54 ;
F_77 ( V_97 ) ;
return 0 ;
V_102:
F_77 ( V_54 ) ;
return V_87 ;
}
static int F_78 ( struct V_55 * V_56 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_103 )
{
struct V_57 * V_78 ;
struct V_57 * V_89 ;
struct V_57 * V_58 ;
int V_87 = 0 ;
T_7 V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
V_58 = F_70 ( V_56 , V_86 ) ;
if ( ! V_58 || V_58 -> V_91 > V_86 )
return - V_90 ;
V_89 = V_58 -> V_107 ;
if ( V_86 > V_58 -> V_91 )
V_89 = V_58 ;
for (; V_58 && V_58 -> V_91 < V_65 ; V_89 = V_58 , V_58 = V_78 ) {
V_78 = V_58 -> V_61 ;
V_105 = F_79 ( V_86 , V_58 -> V_91 ) ;
V_106 = F_80 ( V_65 , V_58 -> V_93 ) ;
if ( F_81 ( F_82 ( V_58 ) , V_103 ) )
continue;
V_104 = V_58 -> V_98 +
( ( V_105 - V_58 -> V_91 ) >> V_108 ) ;
V_89 = F_83 ( V_56 , V_89 , V_105 , V_106 , V_58 -> V_109 ,
V_58 -> V_110 , V_58 -> V_100 , V_104 ,
V_103 ) ;
if ( V_89 ) {
V_58 = V_89 ;
V_78 = V_58 -> V_61 ;
if ( F_81 ( F_82 ( V_58 ) , V_103 ) )
continue;
goto V_111;
}
if ( V_58 -> V_91 != V_105 ) {
V_87 = F_84 ( V_58 -> V_70 , V_58 , V_105 , 1 ) ;
if ( V_87 )
goto V_112;
}
if ( V_58 -> V_93 != V_106 ) {
V_87 = F_84 ( V_58 -> V_70 , V_58 , V_106 , 0 ) ;
if ( V_87 )
goto V_112;
}
V_111:
V_87 = F_73 ( V_58 , V_103 ) ;
if ( V_87 )
goto V_112;
}
V_112:
return V_87 ;
}
void F_85 ( struct V_2 * V_3 )
{
if ( V_3 -> V_1 )
V_3 -> V_12 |= V_113 ;
else
V_3 -> V_12 &= ~ V_113 ;
}
static void F_86 ( void )
{
F_85 ( V_47 ) ;
}
static long F_87 ( unsigned short V_8 , unsigned short V_12 ,
T_1 * V_18 )
{
struct V_1 * V_54 , * V_97 ;
struct V_55 * V_56 = V_47 -> V_56 ;
F_88 ( V_114 ) ;
int V_14 ;
if ( ! V_114 )
return - V_40 ;
V_54 = F_19 ( V_8 , V_12 , V_18 ) ;
if ( F_75 ( V_54 ) ) {
V_14 = F_76 ( V_54 ) ;
goto V_112;
}
if ( V_56 )
F_42 ( & V_56 -> V_59 ) ;
F_89 ( V_47 ) ;
V_14 = F_15 ( V_54 , V_18 , V_114 ) ;
if ( V_14 ) {
F_90 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_77 ( V_54 ) ;
goto V_112;
}
V_97 = V_47 -> V_1 ;
V_47 -> V_1 = V_54 ;
F_86 () ;
if ( V_54 && V_54 -> V_8 == V_115 &&
F_8 ( V_54 -> V_20 . V_18 ) )
V_47 -> V_48 = F_13 ( V_54 -> V_20 . V_18 ) ;
F_90 ( V_47 ) ;
if ( V_56 )
F_43 ( & V_56 -> V_59 ) ;
F_77 ( V_97 ) ;
V_14 = 0 ;
V_112:
F_91 ( V_114 ) ;
return V_14 ;
}
static void F_92 ( struct V_1 * V_3 , T_1 * V_18 )
{
F_93 ( * V_18 ) ;
if ( V_3 == & V_116 )
return;
switch ( V_3 -> V_8 ) {
case V_117 :
case V_115 :
* V_18 = V_3 -> V_20 . V_18 ;
break;
case V_27 :
if ( ! ( V_3 -> V_12 & V_21 ) )
F_94 ( V_3 -> V_20 . V_22 , * V_18 ) ;
break;
default:
F_31 () ;
}
}
static int F_95 ( struct V_55 * V_56 , unsigned long V_64 )
{
struct V_71 * V_3 ;
int V_87 ;
V_87 = F_96 ( V_47 , V_56 , V_64 & V_118 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_87 >= 0 ) {
V_87 = F_49 ( V_3 ) ;
F_97 ( V_3 ) ;
}
return V_87 ;
}
static long F_98 ( int * V_34 , T_1 * V_119 ,
unsigned long V_64 , unsigned long V_12 )
{
int V_87 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_57 * V_58 = NULL ;
struct V_1 * V_4 = V_47 -> V_1 ;
if ( V_12 &
~ ( unsigned long ) ( V_120 | V_121 | V_122 ) )
return - V_19 ;
if ( V_12 & V_122 ) {
if ( V_12 & ( V_120 | V_121 ) )
return - V_19 ;
* V_34 = 0 ;
F_89 ( V_47 ) ;
* V_119 = V_26 ;
F_90 ( V_47 ) ;
return 0 ;
}
if ( V_12 & V_121 ) {
F_99 ( & V_56 -> V_59 ) ;
V_58 = F_100 ( V_56 , V_64 , V_64 + 1 ) ;
if ( ! V_58 ) {
F_101 ( & V_56 -> V_59 ) ;
return - V_90 ;
}
if ( V_58 -> V_99 && V_58 -> V_99 -> V_123 )
V_4 = V_58 -> V_99 -> V_123 ( V_58 , V_64 ) ;
else
V_4 = V_58 -> V_62 ;
} else if ( V_64 )
return - V_19 ;
if ( ! V_4 )
V_4 = & V_116 ;
if ( V_12 & V_120 ) {
if ( V_12 & V_121 ) {
V_87 = F_95 ( V_56 , V_64 ) ;
if ( V_87 < 0 )
goto V_112;
* V_34 = V_87 ;
} else if ( V_4 == V_47 -> V_1 &&
V_4 -> V_8 == V_115 ) {
* V_34 = V_47 -> V_48 ;
} else {
V_87 = - V_19 ;
goto V_112;
}
} else {
* V_34 = V_4 == & V_116 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_12 & V_13 ) ;
}
if ( V_58 ) {
F_101 ( & V_47 -> V_56 -> V_59 ) ;
V_58 = NULL ;
}
V_87 = 0 ;
if ( V_119 ) {
if ( F_5 ( V_4 ) ) {
* V_119 = V_4 -> V_30 . V_31 ;
} else {
F_89 ( V_47 ) ;
F_92 ( V_4 , V_119 ) ;
F_90 ( V_47 ) ;
}
}
V_112:
F_102 ( V_4 ) ;
if ( V_58 )
F_101 ( & V_47 -> V_56 -> V_59 ) ;
return V_87 ;
}
static void F_50 ( struct V_71 * V_71 , struct V_124 * V_125 ,
unsigned long V_12 )
{
if ( ( V_12 & V_75 ) || F_103 ( V_71 ) == 1 ) {
if ( ! F_104 ( V_71 ) ) {
F_105 ( & V_71 -> V_126 , V_125 ) ;
F_106 ( V_71 , V_127 +
F_107 ( V_71 ) ) ;
}
}
}
static struct V_71 * F_108 ( struct V_71 * V_71 , unsigned long V_5 , int * * V_128 )
{
return F_109 ( V_5 , V_129 , 0 ) ;
}
static int F_110 ( struct V_55 * V_56 , int V_130 , int V_131 ,
int V_12 )
{
T_1 V_119 ;
F_111 ( V_125 ) ;
int V_87 = 0 ;
F_93 ( V_119 ) ;
F_94 ( V_130 , V_119 ) ;
F_17 ( ! ( V_12 & ( V_74 | V_75 ) ) ) ;
F_69 ( V_56 , V_56 -> V_60 -> V_91 , V_56 -> V_132 , & V_119 ,
V_12 | V_94 , & V_125 ) ;
if ( ! F_112 ( & V_125 ) ) {
V_87 = F_113 ( & V_125 , F_108 , V_131 ,
V_133 , V_134 ) ;
if ( V_87 )
F_114 ( & V_125 ) ;
}
return V_87 ;
}
int F_115 ( struct V_55 * V_56 , const T_1 * V_135 ,
const T_1 * V_136 , int V_12 )
{
int V_137 = 0 ;
int V_87 ;
T_1 V_17 ;
V_87 = F_116 () ;
if ( V_87 )
return V_87 ;
F_99 ( & V_56 -> V_59 ) ;
V_87 = F_117 ( V_56 , V_135 , V_136 , V_12 ) ;
if ( V_87 )
goto V_112;
V_17 = * V_135 ;
while ( ! F_11 ( V_17 ) ) {
int V_138 , V_139 ;
int V_130 = - 1 ;
int V_131 = 0 ;
F_118 (s, tmp) {
if ( ( F_8 ( * V_135 ) != F_8 ( * V_136 ) ) &&
( F_33 ( V_138 , * V_136 ) ) )
continue;
V_139 = F_36 ( V_138 , * V_135 , * V_136 ) ;
if ( V_138 == V_139 )
continue;
V_130 = V_138 ;
V_131 = V_139 ;
if ( ! F_33 ( V_131 , V_17 ) )
break;
}
if ( V_130 == - 1 )
break;
F_119 ( V_130 , V_17 ) ;
V_87 = F_110 ( V_56 , V_130 , V_131 , V_12 ) ;
if ( V_87 > 0 )
V_137 += V_87 ;
if ( V_87 < 0 )
break;
}
V_112:
F_101 ( & V_56 -> V_59 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_137 ;
}
static struct V_71 * F_120 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_128 )
{
struct V_57 * V_58 = (struct V_57 * ) V_66 ;
unsigned long V_140 ( V_141 ) ;
while ( V_58 ) {
V_141 = F_121 ( V_71 , V_58 ) ;
if ( V_141 != - V_90 )
break;
V_58 = V_58 -> V_61 ;
}
return F_122 ( V_129 , V_58 , V_141 ) ;
}
static void F_50 ( struct V_71 * V_71 , struct V_124 * V_125 ,
unsigned long V_12 )
{
}
int F_115 ( struct V_55 * V_56 , const T_1 * V_135 ,
const T_1 * V_136 , int V_12 )
{
return - V_142 ;
}
static struct V_71 * F_120 ( struct V_71 * V_71 , unsigned long V_66 , int * * V_128 )
{
return NULL ;
}
static long F_123 ( unsigned long V_86 , unsigned long V_143 ,
unsigned short V_8 , unsigned short V_144 ,
T_1 * V_119 , unsigned long V_12 )
{
struct V_57 * V_58 ;
struct V_55 * V_56 = V_47 -> V_56 ;
struct V_1 * V_54 ;
unsigned long V_65 ;
int V_87 ;
F_111 ( V_125 ) ;
if ( V_12 & ~ ( unsigned long ) V_145 )
return - V_19 ;
if ( ( V_12 & V_75 ) && ! F_124 ( V_146 ) )
return - V_147 ;
if ( V_86 & ~ V_118 )
return - V_19 ;
if ( V_8 == V_35 )
V_12 &= ~ V_96 ;
V_143 = ( V_143 + V_76 - 1 ) & V_118 ;
V_65 = V_86 + V_143 ;
if ( V_65 < V_86 )
return - V_19 ;
if ( V_65 == V_86 )
return 0 ;
V_54 = F_19 ( V_8 , V_144 , V_119 ) ;
if ( F_75 ( V_54 ) )
return F_76 ( V_54 ) ;
if ( V_12 & V_95 )
V_54 -> V_12 |= V_148 ;
if ( ! V_54 )
V_12 |= V_94 ;
F_20 ( L_3 ,
V_86 , V_86 + V_143 , V_8 , V_144 ,
V_119 ? F_21 ( * V_119 ) [ 0 ] : V_6 ) ;
if ( V_12 & ( V_74 | V_75 ) ) {
V_87 = F_116 () ;
if ( V_87 )
goto V_149;
}
{
F_88 ( V_114 ) ;
if ( V_114 ) {
F_42 ( & V_56 -> V_59 ) ;
F_89 ( V_47 ) ;
V_87 = F_15 ( V_54 , V_119 , V_114 ) ;
F_90 ( V_47 ) ;
if ( V_87 )
F_43 ( & V_56 -> V_59 ) ;
} else
V_87 = - V_40 ;
F_91 ( V_114 ) ;
}
if ( V_87 )
goto V_149;
V_58 = F_69 ( V_56 , V_86 , V_65 , V_119 ,
V_12 | V_73 , & V_125 ) ;
V_87 = F_76 ( V_58 ) ;
if ( ! F_75 ( V_58 ) )
V_87 = F_78 ( V_56 , V_86 , V_65 , V_54 ) ;
if ( ! V_87 ) {
int V_150 = 0 ;
if ( ! F_112 ( & V_125 ) ) {
F_125 ( V_12 & V_95 ) ;
V_150 = F_113 ( & V_125 , F_120 ,
( unsigned long ) V_58 ,
V_133 , V_151 ) ;
if ( V_150 )
F_114 ( & V_125 ) ;
}
if ( V_150 && ( V_12 & V_96 ) )
V_87 = - V_79 ;
} else
F_114 ( & V_125 ) ;
F_43 ( & V_56 -> V_59 ) ;
V_149:
F_77 ( V_54 ) ;
return V_87 ;
}
static int F_126 ( T_1 * V_18 , const unsigned long T_8 * V_119 ,
unsigned long V_152 )
{
unsigned long V_153 ;
unsigned long V_154 ;
unsigned long V_155 ;
-- V_152 ;
F_93 ( * V_18 ) ;
if ( V_152 == 0 || ! V_119 )
return 0 ;
if ( V_152 > V_76 * V_156 )
return - V_19 ;
V_154 = F_127 ( V_152 ) ;
if ( ( V_152 % V_157 ) == 0 )
V_155 = ~ 0UL ;
else
V_155 = ( 1UL << ( V_152 % V_157 ) ) - 1 ;
if ( V_154 > F_127 ( V_49 ) ) {
if ( V_154 > V_76 / sizeof( long ) )
return - V_19 ;
for ( V_153 = F_127 ( V_49 ) ; V_153 < V_154 ; V_153 ++ ) {
unsigned long V_158 ;
if ( F_128 ( V_158 , V_119 + V_153 ) )
return - V_90 ;
if ( V_153 == V_154 - 1 ) {
if ( V_158 & V_155 )
return - V_19 ;
} else if ( V_158 )
return - V_19 ;
}
V_154 = F_127 ( V_49 ) ;
V_155 = ~ 0UL ;
}
if ( F_129 ( F_21 ( * V_18 ) , V_119 , V_154 *sizeof( unsigned long ) ) )
return - V_90 ;
F_21 ( * V_18 ) [ V_154 - 1 ] &= V_155 ;
return 0 ;
}
static int F_130 ( unsigned long T_8 * V_159 , unsigned long V_152 ,
T_1 * V_18 )
{
unsigned long V_160 = F_131 ( V_152 - 1 , 64 ) / 8 ;
const int V_161 = F_127 ( V_49 ) * sizeof( long ) ;
if ( V_160 > V_161 ) {
if ( V_160 > V_76 )
return - V_19 ;
if ( F_132 ( ( char T_8 * ) V_159 + V_161 , V_160 - V_161 ) )
return - V_90 ;
V_160 = V_161 ;
}
return F_133 ( V_159 , F_21 ( * V_18 ) , V_160 ) ? - V_90 : 0 ;
}
T_9 long F_134 ( int T_8 * V_34 ,
T_10 T_8 * V_119 ,
T_10 V_152 ,
T_10 V_64 , T_10 V_12 )
{
long V_87 ;
unsigned long T_8 * V_162 = NULL ;
unsigned long V_163 , V_164 ;
F_135 ( V_165 , V_49 ) ;
V_163 = F_136 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_164 = F_131 ( V_163 , V_157 ) / 8 ;
if ( V_119 )
V_162 = F_137 ( V_164 ) ;
V_87 = F_138 ( V_34 , V_162 , V_163 + 1 , V_64 , V_12 ) ;
if ( ! V_87 && V_119 ) {
unsigned long V_166 ;
V_166 = F_136 (unsigned long, sizeof(bm), alloc_size) ;
V_87 = F_129 ( V_165 , V_162 , V_166 ) ;
V_87 |= F_132 ( V_119 , F_131 ( V_152 - 1 , 8 ) / 8 ) ;
V_87 |= F_139 ( V_119 , V_165 , V_163 ) ;
}
return V_87 ;
}
T_9 long F_140 ( int V_8 , T_10 T_8 * V_119 ,
T_10 V_152 )
{
long V_87 = 0 ;
unsigned long T_8 * V_162 = NULL ;
unsigned long V_163 , V_164 ;
F_135 ( V_165 , V_49 ) ;
V_163 = F_136 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_164 = F_131 ( V_163 , V_157 ) / 8 ;
if ( V_119 ) {
V_87 = F_141 ( V_165 , V_119 , V_163 ) ;
V_162 = F_137 ( V_164 ) ;
V_87 |= F_133 ( V_162 , V_165 , V_164 ) ;
}
if ( V_87 )
return - V_90 ;
return F_142 ( V_8 , V_162 , V_163 + 1 ) ;
}
T_9 long F_143 ( T_10 V_86 , T_10 V_143 ,
T_10 V_8 , T_10 T_8 * V_119 ,
T_10 V_152 , T_10 V_12 )
{
long V_87 = 0 ;
unsigned long T_8 * V_162 = NULL ;
unsigned long V_163 , V_164 ;
T_1 V_165 ;
V_163 = F_136 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_164 = F_131 ( V_163 , V_157 ) / 8 ;
if ( V_119 ) {
V_87 = F_141 ( F_21 ( V_165 ) , V_119 , V_163 ) ;
V_162 = F_137 ( V_164 ) ;
V_87 |= F_133 ( V_162 , F_21 ( V_165 ) , V_164 ) ;
}
if ( V_87 )
return - V_90 ;
return F_144 ( V_86 , V_143 , V_8 , V_162 , V_163 + 1 , V_12 ) ;
}
struct V_1 * F_145 ( struct V_2 * V_167 ,
struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 = F_1 ( V_167 ) ;
if ( V_58 ) {
if ( V_58 -> V_99 && V_58 -> V_99 -> V_123 ) {
struct V_1 * V_168 = V_58 -> V_99 -> V_123 ( V_58 ,
V_64 ) ;
if ( V_168 )
V_4 = V_168 ;
} else if ( V_58 -> V_62 ) {
V_4 = V_58 -> V_62 ;
if ( F_146 ( V_4 ) )
F_147 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_116 ;
return V_4 ;
}
static int F_148 ( struct V_1 * V_34 , enum V_169 V_170 )
{
enum V_169 V_171 = V_172 ;
F_149 ( V_171 == V_173 ) ;
if ( ! F_4 ( V_34 -> V_20 . V_18 , V_10 [ V_174 ] ) )
V_171 = V_173 ;
return V_170 >= V_171 ;
}
static T_1 * F_150 ( T_11 V_175 , struct V_1 * V_34 )
{
if ( F_151 ( V_34 -> V_8 == V_117 ) &&
F_148 ( V_34 , F_152 ( V_175 ) ) &&
F_153 ( & V_34 -> V_20 . V_18 ) )
return & V_34 -> V_20 . V_18 ;
return NULL ;
}
static struct V_176 * F_154 ( T_11 V_175 , struct V_1 * V_34 ,
int V_177 )
{
switch ( V_34 -> V_8 ) {
case V_27 :
if ( ! ( V_34 -> V_12 & V_21 ) )
V_177 = V_34 -> V_20 . V_22 ;
break;
case V_117 :
if ( F_151 ( V_175 & V_178 ) &&
F_151 ( ! F_33 ( V_177 , V_34 -> V_20 . V_18 ) ) )
V_177 = F_13 ( V_34 -> V_20 . V_18 ) ;
break;
default:
F_31 () ;
}
return F_155 ( V_177 , V_175 ) ;
}
static unsigned F_156 ( struct V_1 * V_34 )
{
unsigned V_72 , V_78 ;
struct V_2 * V_179 = V_47 ;
V_72 = V_179 -> V_48 ;
V_78 = F_34 ( V_72 , V_34 -> V_20 . V_18 ) ;
if ( V_78 >= V_49 )
V_78 = F_13 ( V_34 -> V_20 . V_18 ) ;
if ( V_78 < V_49 )
V_179 -> V_48 = V_78 ;
return V_72 ;
}
unsigned F_157 ( void )
{
struct V_1 * V_34 ;
if ( F_158 () )
return F_2 () ;
V_34 = V_47 -> V_1 ;
if ( ! V_34 || V_34 -> V_12 & V_21 )
return F_2 () ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_20 . V_22 ;
case V_115 :
return F_156 ( V_34 ) ;
case V_117 : {
struct V_176 * V_176 ;
struct V_170 * V_170 ;
enum V_169 V_180 = F_152 ( V_39 ) ;
V_176 = & F_159 ( F_2 () ) -> V_181 [ 0 ] ;
( void ) F_160 ( V_176 , V_180 ,
& V_34 -> V_20 . V_18 ,
& V_170 ) ;
return V_170 ? V_170 -> V_5 : F_2 () ;
}
default:
F_31 () ;
}
}
static unsigned F_161 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_182 )
{
unsigned V_183 = F_8 ( V_4 -> V_20 . V_18 ) ;
unsigned V_184 ;
int V_185 ;
int V_72 = - 1 ;
if ( ! V_183 )
return F_2 () ;
V_184 = ( unsigned int ) V_182 % V_183 ;
V_185 = 0 ;
do {
V_72 = F_34 ( V_72 , V_4 -> V_20 . V_18 ) ;
V_185 ++ ;
} while ( V_185 <= V_184 );
return V_72 ;
}
static inline unsigned F_162 ( struct V_1 * V_4 ,
struct V_57 * V_58 , unsigned long V_64 , int V_186 )
{
if ( V_58 ) {
unsigned long V_182 ;
F_149 ( V_186 < V_108 ) ;
V_182 = V_58 -> V_98 >> ( V_186 - V_108 ) ;
V_182 += ( V_64 - V_58 -> V_91 ) >> V_186 ;
return F_161 ( V_4 , V_58 , V_182 ) ;
} else
return F_156 ( V_4 ) ;
}
int F_163 ( const T_1 * V_187 )
{
int V_30 , V_188 = - 1 ;
V_30 = F_8 ( * V_187 ) ;
if ( V_30 )
V_188 = F_164 ( V_187 -> V_189 ,
F_165 () % V_30 , V_49 ) ;
return V_188 ;
}
struct V_176 * F_166 ( struct V_57 * V_58 , unsigned long V_64 ,
T_11 V_190 , struct V_1 * * V_191 ,
T_1 * * V_9 )
{
struct V_176 * V_192 ;
* V_191 = F_145 ( V_47 , V_58 , V_64 ) ;
* V_9 = NULL ;
if ( F_151 ( ( * V_191 ) -> V_8 == V_115 ) ) {
V_192 = F_155 ( F_162 ( * V_191 , V_58 , V_64 ,
F_167 ( F_168 ( V_58 ) ) ) , V_190 ) ;
} else {
V_192 = F_154 ( V_190 , * V_191 , F_2 () ) ;
if ( ( * V_191 ) -> V_8 == V_117 )
* V_9 = & ( * V_191 ) -> V_20 . V_18 ;
}
return V_192 ;
}
bool F_169 ( T_1 * V_159 )
{
struct V_1 * V_1 ;
int V_72 ;
if ( ! ( V_159 && V_47 -> V_1 ) )
return false ;
F_89 ( V_47 ) ;
V_1 = V_47 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_12 & V_21 )
V_72 = F_2 () ;
else
V_72 = V_1 -> V_20 . V_22 ;
F_170 ( V_159 , V_72 ) ;
break;
case V_117 :
case V_115 :
* V_159 = V_1 -> V_20 . V_18 ;
break;
default:
F_31 () ;
}
F_90 ( V_47 ) ;
return true ;
}
bool F_171 ( struct V_2 * V_53 ,
const T_1 * V_159 )
{
struct V_1 * V_1 ;
bool V_14 = true ;
if ( ! V_159 )
return V_14 ;
F_89 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
if ( ! V_1 )
goto V_112;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_117 :
case V_115 :
V_14 = F_4 ( V_1 -> V_20 . V_18 , * V_159 ) ;
break;
default:
F_31 () ;
}
V_112:
F_90 ( V_53 ) ;
return V_14 ;
}
static struct V_71 * F_172 ( T_11 V_175 , unsigned V_193 ,
unsigned V_72 )
{
struct V_176 * V_192 ;
struct V_71 * V_71 ;
V_192 = F_155 ( V_72 , V_175 ) ;
V_71 = F_173 ( V_175 , V_193 , V_192 ) ;
if ( V_71 && F_174 ( V_71 ) == F_175 ( & V_192 -> V_194 [ 0 ] ) )
F_106 ( V_71 , V_195 ) ;
return V_71 ;
}
struct V_71 *
F_176 ( T_11 V_175 , int V_193 , struct V_57 * V_58 ,
unsigned long V_64 , int V_5 )
{
struct V_1 * V_4 ;
struct V_71 * V_71 ;
unsigned int V_196 ;
V_197:
V_4 = F_145 ( V_47 , V_58 , V_64 ) ;
V_196 = F_177 () ;
if ( F_151 ( V_4 -> V_8 == V_115 ) ) {
unsigned V_72 ;
V_72 = F_162 ( V_4 , V_58 , V_64 , V_108 + V_193 ) ;
F_102 ( V_4 ) ;
V_71 = F_172 ( V_175 , V_193 , V_72 ) ;
if ( F_151 ( ! F_178 ( V_196 ) && ! V_71 ) )
goto V_197;
return V_71 ;
}
V_71 = F_179 ( V_175 , V_193 ,
F_154 ( V_175 , V_4 , V_5 ) ,
F_150 ( V_175 , V_4 ) ) ;
if ( F_151 ( F_146 ( V_4 ) ) )
F_25 ( V_4 ) ;
if ( F_151 ( ! F_178 ( V_196 ) && ! V_71 ) )
goto V_197;
return V_71 ;
}
struct V_71 * F_180 ( T_11 V_175 , unsigned V_193 )
{
struct V_1 * V_4 = F_1 ( V_47 ) ;
struct V_71 * V_71 ;
unsigned int V_196 ;
if ( ! V_4 || F_158 () || ( V_175 & V_178 ) )
V_4 = & V_116 ;
V_197:
V_196 = F_177 () ;
if ( V_4 -> V_8 == V_115 )
V_71 = F_172 ( V_175 , V_193 , F_156 ( V_4 ) ) ;
else
V_71 = F_179 ( V_175 , V_193 ,
F_154 ( V_175 , V_4 , F_2 () ) ,
F_150 ( V_175 , V_4 ) ) ;
if ( F_151 ( ! F_178 ( V_196 ) && ! V_71 ) )
goto V_197;
return V_71 ;
}
struct V_1 * F_181 ( struct V_1 * V_97 )
{
struct V_1 * V_54 = F_23 ( V_38 , V_39 ) ;
if ( ! V_54 )
return F_22 ( - V_40 ) ;
if ( V_97 == V_47 -> V_1 ) {
F_89 ( V_47 ) ;
* V_54 = * V_97 ;
F_90 ( V_47 ) ;
} else
* V_54 = * V_97 ;
F_182 () ;
if ( F_183 () ) {
T_1 V_198 = V_32 ( V_47 ) ;
if ( V_54 -> V_12 & V_51 )
F_37 ( V_54 , & V_198 , V_46 ) ;
else
F_37 ( V_54 , & V_198 , V_44 ) ;
}
F_184 () ;
F_24 ( & V_54 -> V_41 , 1 ) ;
return V_54 ;
}
bool F_185 ( struct V_1 * V_199 , struct V_1 * V_200 )
{
if ( ! V_199 || ! V_200 )
return false ;
if ( V_199 -> V_8 != V_200 -> V_8 )
return false ;
if ( V_199 -> V_12 != V_200 -> V_12 )
return false ;
if ( F_5 ( V_199 ) )
if ( ! F_38 ( V_199 -> V_30 . V_31 , V_200 -> V_30 . V_31 ) )
return false ;
switch ( V_199 -> V_8 ) {
case V_117 :
case V_115 :
return ! ! F_38 ( V_199 -> V_20 . V_18 , V_200 -> V_20 . V_18 ) ;
case V_27 :
return V_199 -> V_20 . V_22 == V_200 -> V_20 . V_22 ;
default:
F_31 () ;
return false ;
}
}
static struct V_201 *
F_186 ( struct V_202 * V_203 , unsigned long V_86 , unsigned long V_65 )
{
struct V_204 * V_205 = V_203 -> V_206 . V_204 ;
while ( V_205 ) {
struct V_201 * V_3 = F_187 ( V_205 , struct V_201 , V_177 ) ;
if ( V_86 >= V_3 -> V_65 )
V_205 = V_205 -> V_207 ;
else if ( V_65 <= V_3 -> V_86 )
V_205 = V_205 -> V_208 ;
else
break;
}
if ( ! V_205 )
return NULL ;
for (; ; ) {
struct V_201 * V_30 = NULL ;
struct V_204 * V_89 = F_188 ( V_205 ) ;
if ( ! V_89 )
break;
V_30 = F_187 ( V_89 , struct V_201 , V_177 ) ;
if ( V_30 -> V_65 <= V_86 )
break;
V_205 = V_89 ;
}
return F_187 ( V_205 , struct V_201 , V_177 ) ;
}
static void F_189 ( struct V_202 * V_203 , struct V_201 * V_54 )
{
struct V_204 * * V_3 = & V_203 -> V_206 . V_204 ;
struct V_204 * V_209 = NULL ;
struct V_201 * V_177 ;
while ( * V_3 ) {
V_209 = * V_3 ;
V_177 = F_187 ( V_209 , struct V_201 , V_177 ) ;
if ( V_54 -> V_86 < V_177 -> V_86 )
V_3 = & ( * V_3 ) -> V_208 ;
else if ( V_54 -> V_65 > V_177 -> V_65 )
V_3 = & ( * V_3 ) -> V_207 ;
else
F_31 () ;
}
F_190 ( & V_54 -> V_177 , V_209 , V_3 ) ;
F_191 ( & V_54 -> V_177 , & V_203 -> V_206 ) ;
F_20 ( L_4 , V_54 -> V_86 , V_54 -> V_65 ,
V_54 -> V_34 ? V_54 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_192 ( struct V_202 * V_203 , unsigned long V_210 )
{
struct V_1 * V_4 = NULL ;
struct V_201 * V_211 ;
if ( ! V_203 -> V_206 . V_204 )
return NULL ;
F_193 ( & V_203 -> V_212 ) ;
V_211 = F_186 ( V_203 , V_210 , V_210 + 1 ) ;
if ( V_211 ) {
F_147 ( V_211 -> V_34 ) ;
V_4 = V_211 -> V_34 ;
}
F_194 ( & V_203 -> V_212 ) ;
return V_4 ;
}
static void F_195 ( struct V_201 * V_205 )
{
F_77 ( V_205 -> V_34 ) ;
F_27 ( V_213 , V_205 ) ;
}
int F_196 ( struct V_71 * V_71 , struct V_57 * V_58 , unsigned long V_64 )
{
struct V_1 * V_4 ;
struct V_170 * V_170 ;
int V_214 = F_49 ( V_71 ) ;
unsigned long V_104 ;
int V_215 = - 1 ;
int V_14 = - 1 ;
F_149 ( ! V_58 ) ;
V_4 = F_145 ( V_47 , V_58 , V_64 ) ;
if ( ! ( V_4 -> V_12 & V_148 ) )
goto V_112;
switch ( V_4 -> V_8 ) {
case V_115 :
F_149 ( V_64 >= V_58 -> V_93 ) ;
F_149 ( V_64 < V_58 -> V_91 ) ;
V_104 = V_58 -> V_98 ;
V_104 += ( V_64 - V_58 -> V_91 ) >> V_108 ;
V_215 = F_161 ( V_4 , V_58 , V_104 ) ;
break;
case V_27 :
if ( V_4 -> V_12 & V_21 )
V_215 = F_2 () ;
else
V_215 = V_4 -> V_20 . V_22 ;
break;
case V_117 :
if ( F_33 ( V_214 , V_4 -> V_20 . V_18 ) )
goto V_112;
( void ) F_160 (
F_155 ( F_2 () , V_216 ) ,
F_152 ( V_216 ) ,
& V_4 -> V_20 . V_18 , & V_170 ) ;
V_215 = V_170 -> V_5 ;
break;
default:
F_31 () ;
}
if ( V_4 -> V_12 & V_217 ) {
int V_218 ;
V_215 = F_2 () ;
V_218 = F_197 ( V_71 , V_215 ) ;
if ( V_218 != V_215 )
goto V_112;
}
if ( V_214 != V_215 )
V_14 = V_215 ;
V_112:
F_102 ( V_4 ) ;
return V_14 ;
}
static void F_198 ( struct V_202 * V_203 , struct V_201 * V_205 )
{
F_20 ( L_5 , V_205 -> V_86 , V_205 -> V_65 ) ;
F_199 ( & V_205 -> V_177 , & V_203 -> V_206 ) ;
F_195 ( V_205 ) ;
}
static void F_200 ( struct V_201 * V_5 , unsigned long V_86 ,
unsigned long V_65 , struct V_1 * V_4 )
{
V_5 -> V_86 = V_86 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_34 = V_4 ;
}
static struct V_201 * F_201 ( unsigned long V_86 , unsigned long V_65 ,
struct V_1 * V_4 )
{
struct V_201 * V_205 ;
struct V_1 * V_219 ;
V_205 = F_23 ( V_213 , V_39 ) ;
if ( ! V_205 )
return NULL ;
V_219 = F_74 ( V_4 ) ;
if ( F_75 ( V_219 ) ) {
F_27 ( V_213 , V_205 ) ;
return NULL ;
}
V_219 -> V_12 |= V_220 ;
F_200 ( V_205 , V_86 , V_65 , V_219 ) ;
return V_205 ;
}
static int F_202 ( struct V_202 * V_203 , unsigned long V_86 ,
unsigned long V_65 , struct V_201 * V_54 )
{
struct V_201 * V_205 ;
struct V_201 * V_221 = NULL ;
struct V_1 * F_19 = NULL ;
int V_14 = 0 ;
V_222:
F_193 ( & V_203 -> V_212 ) ;
V_205 = F_186 ( V_203 , V_86 , V_65 ) ;
while ( V_205 && V_205 -> V_86 < V_65 ) {
struct V_204 * V_78 = F_203 ( & V_205 -> V_177 ) ;
if ( V_205 -> V_86 >= V_86 ) {
if ( V_205 -> V_65 <= V_65 )
F_198 ( V_203 , V_205 ) ;
else
V_205 -> V_86 = V_65 ;
} else {
if ( V_205 -> V_65 > V_65 ) {
if ( ! V_221 )
goto V_223;
* F_19 = * V_205 -> V_34 ;
F_24 ( & F_19 -> V_41 , 1 ) ;
F_200 ( V_221 , V_65 , V_205 -> V_65 , F_19 ) ;
V_205 -> V_65 = V_86 ;
F_189 ( V_203 , V_221 ) ;
V_221 = NULL ;
F_19 = NULL ;
break;
} else
V_205 -> V_65 = V_86 ;
}
if ( ! V_78 )
break;
V_205 = F_187 ( V_78 , struct V_201 , V_177 ) ;
}
if ( V_54 )
F_189 ( V_203 , V_54 ) ;
F_194 ( & V_203 -> V_212 ) ;
V_14 = 0 ;
V_102:
if ( F_19 )
F_77 ( F_19 ) ;
if ( V_221 )
F_27 ( V_213 , V_221 ) ;
return V_14 ;
V_223:
F_194 ( & V_203 -> V_212 ) ;
V_14 = - V_40 ;
V_221 = F_23 ( V_213 , V_39 ) ;
if ( ! V_221 )
goto V_102;
F_19 = F_23 ( V_38 , V_39 ) ;
if ( ! F_19 )
goto V_102;
goto V_222;
}
void F_204 ( struct V_202 * V_203 , struct V_1 * V_191 )
{
int V_14 ;
V_203 -> V_206 = V_224 ;
F_205 ( & V_203 -> V_212 ) ;
if ( V_191 ) {
struct V_57 V_225 ;
struct V_1 * V_54 ;
F_88 ( V_114 ) ;
if ( ! V_114 )
goto V_226;
V_54 = F_19 ( V_191 -> V_8 , V_191 -> V_12 , & V_191 -> V_30 . V_31 ) ;
if ( F_75 ( V_54 ) )
goto V_227;
F_89 ( V_47 ) ;
V_14 = F_15 ( V_54 , & V_191 -> V_30 . V_31 , V_114 ) ;
F_90 ( V_47 ) ;
if ( V_14 )
goto V_228;
memset ( & V_225 , 0 , sizeof( struct V_57 ) ) ;
V_225 . V_93 = V_229 ;
F_206 ( V_203 , & V_225 , V_54 ) ;
V_228:
F_77 ( V_54 ) ;
V_227:
F_91 ( V_114 ) ;
V_226:
F_77 ( V_191 ) ;
}
}
int F_206 ( struct V_202 * V_230 ,
struct V_57 * V_58 , struct V_1 * V_231 )
{
int V_87 ;
struct V_201 * V_54 = NULL ;
unsigned long V_232 = F_207 ( V_58 ) ;
F_20 ( L_6 ,
V_58 -> V_98 ,
V_232 , V_231 ? V_231 -> V_8 : - 1 ,
V_231 ? V_231 -> V_12 : - 1 ,
V_231 ? F_21 ( V_231 -> V_20 . V_18 ) [ 0 ] : V_6 ) ;
if ( V_231 ) {
V_54 = F_201 ( V_58 -> V_98 , V_58 -> V_98 + V_232 , V_231 ) ;
if ( ! V_54 )
return - V_40 ;
}
V_87 = F_202 ( V_230 , V_58 -> V_98 , V_58 -> V_98 + V_232 , V_54 ) ;
if ( V_87 && V_54 )
F_195 ( V_54 ) ;
return V_87 ;
}
void F_208 ( struct V_202 * V_3 )
{
struct V_201 * V_205 ;
struct V_204 * V_78 ;
if ( ! V_3 -> V_206 . V_204 )
return;
F_193 ( & V_3 -> V_212 ) ;
V_78 = F_209 ( & V_3 -> V_206 ) ;
while ( V_78 ) {
V_205 = F_187 ( V_78 , struct V_201 , V_177 ) ;
V_78 = F_203 ( & V_205 -> V_177 ) ;
F_198 ( V_3 , V_205 ) ;
}
F_194 ( & V_3 -> V_212 ) ;
}
static void T_12 F_210 ( void )
{
bool V_233 = false ;
if ( F_211 ( V_234 ) )
V_233 = true ;
if ( V_235 > 1 && ! V_236 ) {
F_212 ( V_237 L_7
L_8 ) ;
F_213 ( V_233 ) ;
}
}
static int T_12 F_214 ( char * V_238 )
{
int V_14 = 0 ;
if ( ! V_238 )
goto V_112;
V_236 = true ;
if ( ! strcmp ( V_238 , L_9 ) ) {
F_213 ( true ) ;
V_14 = 1 ;
} else if ( ! strcmp ( V_238 , L_10 ) ) {
F_213 ( false ) ;
V_14 = 1 ;
}
V_112:
if ( ! V_14 )
F_212 ( V_239 L_11 ) ;
return V_14 ;
}
static inline void T_12 F_210 ( void )
{
}
void T_12 F_215 ( void )
{
T_1 F_156 ;
unsigned long V_240 = 0 ;
int V_72 , V_241 = 0 ;
V_38 = F_216 ( L_12 ,
sizeof( struct V_1 ) ,
0 , V_242 , NULL ) ;
V_213 = F_216 ( L_13 ,
sizeof( struct V_201 ) ,
0 , V_242 , NULL ) ;
F_217 (nid) {
V_7 [ V_72 ] = (struct V_1 ) {
. V_41 = F_218 ( 1 ) ,
. V_8 = V_27 ,
. V_12 = V_148 | V_217 ,
. V_20 = { . V_22 = V_72 , } ,
} ;
}
F_93 ( F_156 ) ;
F_219 (nid, N_MEMORY) {
unsigned long V_243 = F_220 ( V_72 ) ;
if ( V_240 < V_243 ) {
V_240 = V_243 ;
V_241 = V_72 ;
}
if ( ( V_243 << V_108 ) >= ( 16 << 20 ) )
F_94 ( V_72 , F_156 ) ;
}
if ( F_151 ( F_11 ( F_156 ) ) )
F_94 ( V_241 , F_156 ) ;
if ( F_87 ( V_115 , 0 , & F_156 ) )
F_212 ( L_14 ) ;
F_210 () ;
}
void F_221 ( void )
{
F_87 ( V_35 , 0 , NULL ) ;
}
int F_222 ( char * V_238 , struct V_1 * * V_191 )
{
struct V_1 * V_54 = NULL ;
unsigned short V_8 ;
unsigned short V_144 ;
T_1 V_18 ;
char * V_244 = strchr ( V_238 , ':' ) ;
char * V_12 = strchr ( V_238 , '=' ) ;
int V_87 = 1 ;
if ( V_244 ) {
* V_244 ++ = '\0' ;
if ( F_223 ( V_244 , V_18 ) )
goto V_112;
if ( ! F_224 ( V_18 , V_10 [ V_11 ] ) )
goto V_112;
} else
F_93 ( V_18 ) ;
if ( V_12 )
* V_12 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_245 ; V_8 ++ ) {
if ( ! strcmp ( V_238 , V_246 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_245 )
goto V_112;
switch ( V_8 ) {
case V_27 :
if ( V_244 ) {
char * V_247 = V_244 ;
while ( isdigit ( * V_247 ) )
V_247 ++ ;
if ( * V_247 )
goto V_112;
}
break;
case V_115 :
if ( ! V_244 )
V_18 = V_10 [ V_11 ] ;
break;
case V_37 :
if ( V_244 )
goto V_112;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_244 )
V_87 = 0 ;
goto V_112;
case V_117 :
if ( ! V_244 )
goto V_112;
}
V_144 = 0 ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_15 ) )
V_144 |= V_36 ;
else if ( ! strcmp ( V_12 , L_16 ) )
V_144 |= V_28 ;
else
goto V_112;
}
V_54 = F_19 ( V_8 , V_144 , & V_18 ) ;
if ( F_75 ( V_54 ) )
goto V_112;
if ( V_8 != V_27 )
V_54 -> V_20 . V_18 = V_18 ;
else if ( V_244 )
V_54 -> V_20 . V_22 = F_13 ( V_18 ) ;
else
V_54 -> V_12 |= V_21 ;
V_54 -> V_30 . V_31 = V_18 ;
V_87 = 0 ;
V_112:
if ( V_244 )
* -- V_244 = ':' ;
if ( V_12 )
* -- V_12 = '=' ;
if ( ! V_87 )
* V_191 = V_54 ;
return V_87 ;
}
int F_225 ( char * V_248 , int V_249 , struct V_1 * V_4 )
{
char * V_3 = V_248 ;
int V_250 ;
T_1 V_18 ;
unsigned short V_8 ;
unsigned short V_12 = V_4 ? V_4 -> V_12 : 0 ;
F_17 ( V_249 < strlen ( L_17 ) + strlen ( L_16 ) + 16 ) ;
if ( ! V_4 || V_4 == & V_116 )
V_8 = V_35 ;
else
V_8 = V_4 -> V_8 ;
switch ( V_8 ) {
case V_35 :
F_93 ( V_18 ) ;
break;
case V_27 :
F_93 ( V_18 ) ;
if ( V_12 & V_21 )
V_8 = V_37 ;
else
F_94 ( V_4 -> V_20 . V_22 , V_18 ) ;
break;
case V_117 :
case V_115 :
V_18 = V_4 -> V_20 . V_18 ;
break;
default:
return - V_19 ;
}
V_250 = strlen ( V_246 [ V_8 ] ) ;
if ( V_248 + V_249 < V_3 + V_250 + 1 )
return - V_251 ;
strcpy ( V_3 , V_246 [ V_8 ] ) ;
V_3 += V_250 ;
if ( V_12 & V_13 ) {
if ( V_248 + V_249 < V_3 + 2 )
return - V_251 ;
* V_3 ++ = '=' ;
if ( V_12 & V_36 )
V_3 += snprintf ( V_3 , V_248 + V_249 - V_3 , L_15 ) ;
else if ( V_12 & V_28 )
V_3 += snprintf ( V_3 , V_248 + V_249 - V_3 , L_16 ) ;
}
if ( ! F_11 ( V_18 ) ) {
if ( V_248 + V_249 < V_3 + 2 )
return - V_251 ;
* V_3 ++ = ':' ;
V_3 += F_226 ( V_3 , V_248 + V_249 - V_3 , V_18 ) ;
}
return V_3 - V_248 ;
}
