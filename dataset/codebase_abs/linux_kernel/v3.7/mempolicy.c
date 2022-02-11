static int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 ;
F_2 (nd, *nodemask) {
struct V_4 * V_5 ;
for ( V_3 = 0 ; V_3 <= V_6 ; V_3 ++ ) {
V_5 = & F_3 ( V_2 ) -> V_7 [ V_3 ] ;
if ( V_5 -> V_8 > 0 )
return 1 ;
}
}
return 0 ;
}
static inline int F_4 ( const struct V_9 * V_10 )
{
return V_10 -> V_11 & V_12 ;
}
static void F_5 ( T_1 * V_13 , const T_1 * V_14 ,
const T_1 * V_15 )
{
T_1 V_16 ;
F_6 ( V_16 , * V_14 , F_7 ( * V_15 ) ) ;
F_8 ( * V_13 , V_16 , * V_15 ) ;
}
static int F_9 ( struct V_9 * V_10 , const T_1 * V_17 )
{
if ( F_10 ( * V_17 ) )
return - V_18 ;
V_10 -> V_19 . V_17 = * V_17 ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , const T_1 * V_17 )
{
if ( ! V_17 )
V_10 -> V_11 |= V_20 ;
else if ( F_10 ( * V_17 ) )
return - V_18 ;
else
V_10 -> V_19 . V_21 = F_12 ( * V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , const T_1 * V_17 )
{
if ( ! F_1 ( V_17 ) )
return - V_18 ;
V_10 -> V_19 . V_17 = * V_17 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
const T_1 * V_17 , struct V_22 * V_23 )
{
int V_13 ;
if ( V_10 == NULL )
return 0 ;
F_15 ( V_23 -> V_24 ,
V_25 , V_26 [ V_27 ] ) ;
F_16 ( ! V_17 ) ;
if ( V_10 -> V_28 == V_29 && F_10 ( * V_17 ) )
V_17 = NULL ;
else {
if ( V_10 -> V_11 & V_30 )
F_5 ( & V_23 -> V_31 , V_17 , & V_23 -> V_24 ) ;
else
F_15 ( V_23 -> V_31 , * V_17 , V_23 -> V_24 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_32 . V_33 = * V_17 ;
else
V_10 -> V_32 . V_34 =
V_25 ;
}
if ( V_17 )
V_13 = V_35 [ V_10 -> V_28 ] . F_17 ( V_10 , & V_23 -> V_31 ) ;
else
V_13 = V_35 [ V_10 -> V_28 ] . F_17 ( V_10 , NULL ) ;
return V_13 ;
}
static struct V_9 * F_18 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_36 ;
F_19 ( L_1 ,
V_28 , V_11 , V_17 ? F_20 ( * V_17 ) [ 0 ] : - 1 ) ;
if ( V_28 == V_37 ) {
if ( V_17 && ! F_10 ( * V_17 ) )
return F_21 ( - V_18 ) ;
return NULL ;
}
F_16 ( ! V_17 ) ;
if ( V_28 == V_29 ) {
if ( F_10 ( * V_17 ) ) {
if ( ( ( V_11 & V_38 ) ||
( V_11 & V_30 ) ) )
return F_21 ( - V_18 ) ;
}
} else if ( F_10 ( * V_17 ) )
return F_21 ( - V_18 ) ;
V_36 = F_22 ( V_39 , V_40 ) ;
if ( ! V_36 )
return F_21 ( - V_41 ) ;
F_23 ( & V_36 -> V_42 , 1 ) ;
V_36 -> V_28 = V_28 ;
V_36 -> V_11 = V_11 ;
return V_36 ;
}
void F_24 ( struct V_9 * V_43 )
{
if ( ! F_25 ( & V_43 -> V_42 ) )
return;
F_26 ( V_39 , V_43 ) ;
}
static void F_27 ( struct V_9 * V_10 , const T_1 * V_17 ,
enum V_44 V_45 )
{
}
static void F_28 ( struct V_9 * V_10 , const T_1 * V_17 ,
enum V_44 V_45 )
{
T_1 V_16 ;
if ( V_10 -> V_11 & V_38 )
F_15 ( V_16 , V_10 -> V_32 . V_33 , * V_17 ) ;
else if ( V_10 -> V_11 & V_30 )
F_5 ( & V_16 , & V_10 -> V_32 . V_33 , V_17 ) ;
else {
if ( V_45 == V_46 || V_45 == V_47 ) {
F_29 ( V_16 , V_10 -> V_19 . V_17 ,
V_10 -> V_32 . V_34 , * V_17 ) ;
V_10 -> V_32 . V_34 = V_45 ? V_16 : * V_17 ;
} else if ( V_45 == V_48 ) {
V_16 = V_10 -> V_32 . V_34 ;
V_10 -> V_32 . V_34 = * V_17 ;
} else
F_30 () ;
}
if ( F_10 ( V_16 ) )
V_16 = * V_17 ;
if ( V_45 == V_47 )
F_31 ( V_10 -> V_19 . V_17 , V_10 -> V_19 . V_17 , V_16 ) ;
else if ( V_45 == V_46 || V_45 == V_48 )
V_10 -> V_19 . V_17 = V_16 ;
else
F_30 () ;
if ( ! F_32 ( V_49 -> V_50 , V_16 ) ) {
V_49 -> V_50 = F_33 ( V_49 -> V_50 , V_16 ) ;
if ( V_49 -> V_50 >= V_51 )
V_49 -> V_50 = F_12 ( V_16 ) ;
if ( V_49 -> V_50 >= V_51 )
V_49 -> V_50 = F_34 () ;
}
}
static void F_35 ( struct V_9 * V_10 ,
const T_1 * V_17 ,
enum V_44 V_45 )
{
T_1 V_16 ;
if ( V_10 -> V_11 & V_38 ) {
int V_52 = F_12 ( V_10 -> V_32 . V_33 ) ;
if ( F_32 ( V_52 , * V_17 ) ) {
V_10 -> V_19 . V_21 = V_52 ;
V_10 -> V_11 &= ~ V_20 ;
} else
V_10 -> V_11 |= V_20 ;
} else if ( V_10 -> V_11 & V_30 ) {
F_5 ( & V_16 , & V_10 -> V_32 . V_33 , V_17 ) ;
V_10 -> V_19 . V_21 = F_12 ( V_16 ) ;
} else if ( ! ( V_10 -> V_11 & V_20 ) ) {
V_10 -> V_19 . V_21 = F_36 ( V_10 -> V_19 . V_21 ,
V_10 -> V_32 . V_34 ,
* V_17 ) ;
V_10 -> V_32 . V_34 = * V_17 ;
}
}
static void F_37 ( struct V_9 * V_10 , const T_1 * V_53 ,
enum V_44 V_45 )
{
if ( ! V_10 )
return;
if ( ! F_4 ( V_10 ) && V_45 == V_46 &&
F_38 ( V_10 -> V_32 . V_34 , * V_53 ) )
return;
if ( V_45 == V_47 && ( V_10 -> V_11 & V_54 ) )
return;
if ( V_45 == V_48 && ! ( V_10 -> V_11 & V_54 ) )
F_30 () ;
if ( V_45 == V_47 )
V_10 -> V_11 |= V_54 ;
else if ( V_45 == V_48 )
V_10 -> V_11 &= ~ V_54 ;
else if ( V_45 >= V_55 )
F_30 () ;
V_35 [ V_10 -> V_28 ] . F_39 ( V_10 , V_53 , V_45 ) ;
}
void F_40 ( struct V_56 * V_57 , const T_1 * V_58 ,
enum V_44 V_45 )
{
F_37 ( V_57 -> V_9 , V_58 , V_45 ) ;
}
void F_41 ( struct V_59 * V_60 , T_1 * V_58 )
{
struct V_61 * V_62 ;
F_42 ( & V_60 -> V_63 ) ;
for ( V_62 = V_60 -> V_64 ; V_62 ; V_62 = V_62 -> V_65 )
F_37 ( V_62 -> V_66 , V_58 , V_46 ) ;
F_43 ( & V_60 -> V_63 ) ;
}
static int F_44 ( struct V_61 * V_62 , T_2 * V_67 ,
unsigned long V_68 , unsigned long V_69 ,
const T_1 * V_17 , unsigned long V_11 ,
void * V_70 )
{
T_3 * V_71 ;
T_3 * V_72 ;
T_4 * V_73 ;
V_71 = V_72 = F_45 ( V_62 -> V_74 , V_67 , V_68 , & V_73 ) ;
do {
struct V_75 * V_75 ;
int V_76 ;
if ( ! F_46 ( * V_72 ) )
continue;
V_75 = F_47 ( V_62 , V_68 , * V_72 ) ;
if ( ! V_75 )
continue;
if ( F_48 ( V_75 ) || F_49 ( V_75 ) )
continue;
V_76 = F_50 ( V_75 ) ;
if ( F_32 ( V_76 , * V_17 ) == ! ! ( V_11 & V_77 ) )
continue;
if ( V_11 & ( V_78 | V_79 ) )
F_51 ( V_75 , V_70 , V_11 ) ;
else
break;
} while ( V_72 ++ , V_68 += V_80 , V_68 != V_69 );
F_52 ( V_71 , V_73 ) ;
return V_68 != V_69 ;
}
static inline int F_53 ( struct V_61 * V_62 , T_5 * V_81 ,
unsigned long V_68 , unsigned long V_69 ,
const T_1 * V_17 , unsigned long V_11 ,
void * V_70 )
{
T_2 * V_67 ;
unsigned long V_82 ;
V_67 = F_54 ( V_81 , V_68 ) ;
do {
V_82 = F_55 ( V_68 , V_69 ) ;
F_56 ( V_62 -> V_74 , V_67 ) ;
if ( F_57 ( V_67 ) )
continue;
if ( F_44 ( V_62 , V_67 , V_68 , V_82 , V_17 ,
V_11 , V_70 ) )
return - V_83 ;
} while ( V_67 ++ , V_68 = V_82 , V_68 != V_69 );
return 0 ;
}
static inline int F_58 ( struct V_61 * V_62 , T_6 * V_84 ,
unsigned long V_68 , unsigned long V_69 ,
const T_1 * V_17 , unsigned long V_11 ,
void * V_70 )
{
T_5 * V_81 ;
unsigned long V_82 ;
V_81 = F_59 ( V_84 , V_68 ) ;
do {
V_82 = F_60 ( V_68 , V_69 ) ;
if ( F_61 ( V_81 ) )
continue;
if ( F_53 ( V_62 , V_81 , V_68 , V_82 , V_17 ,
V_11 , V_70 ) )
return - V_83 ;
} while ( V_81 ++ , V_68 = V_82 , V_68 != V_69 );
return 0 ;
}
static inline int F_62 ( struct V_61 * V_62 ,
unsigned long V_68 , unsigned long V_69 ,
const T_1 * V_17 , unsigned long V_11 ,
void * V_70 )
{
T_6 * V_84 ;
unsigned long V_82 ;
V_84 = F_63 ( V_62 -> V_74 , V_68 ) ;
do {
V_82 = F_64 ( V_68 , V_69 ) ;
if ( F_65 ( V_84 ) )
continue;
if ( F_58 ( V_62 , V_84 , V_68 , V_82 , V_17 ,
V_11 , V_70 ) )
return - V_83 ;
} while ( V_84 ++ , V_68 = V_82 , V_68 != V_69 );
return 0 ;
}
static struct V_61 *
F_66 ( struct V_59 * V_60 , unsigned long V_85 , unsigned long V_69 ,
const T_1 * V_17 , unsigned long V_11 , void * V_70 )
{
int V_86 ;
struct V_61 * V_87 , * V_62 , * V_88 ;
V_87 = F_67 ( V_60 , V_85 ) ;
if ( ! V_87 )
return F_21 ( - V_89 ) ;
V_88 = NULL ;
for ( V_62 = V_87 ; V_62 && V_62 -> V_90 < V_69 ; V_62 = V_62 -> V_65 ) {
if ( ! ( V_11 & V_91 ) ) {
if ( ! V_62 -> V_65 && V_62 -> V_92 < V_69 )
return F_21 ( - V_89 ) ;
if ( V_88 && V_88 -> V_92 < V_62 -> V_90 )
return F_21 ( - V_89 ) ;
}
if ( ! F_68 ( V_62 ) &&
( ( V_11 & V_93 ) ||
( ( V_11 & ( V_78 | V_79 ) ) &&
F_69 ( V_62 ) ) ) ) {
unsigned long V_94 = V_62 -> V_92 ;
if ( V_94 > V_69 )
V_94 = V_69 ;
if ( V_62 -> V_90 > V_85 )
V_85 = V_62 -> V_90 ;
V_86 = F_62 ( V_62 , V_85 , V_94 , V_17 ,
V_11 , V_70 ) ;
if ( V_86 ) {
V_87 = F_21 ( V_86 ) ;
break;
}
}
V_88 = V_62 ;
}
return V_87 ;
}
static int F_70 ( struct V_61 * V_62 ,
struct V_9 * V_10 )
{
int V_86 ;
struct V_9 * V_95 ;
struct V_9 * V_58 ;
F_19 ( L_2 ,
V_62 -> V_90 , V_62 -> V_92 , V_62 -> V_96 ,
V_62 -> V_97 , V_62 -> V_98 ,
V_62 -> V_97 ? V_62 -> V_97 -> V_99 : NULL ) ;
V_58 = F_71 ( V_10 ) ;
if ( F_72 ( V_58 ) )
return F_73 ( V_58 ) ;
if ( V_62 -> V_97 && V_62 -> V_97 -> V_99 ) {
V_86 = V_62 -> V_97 -> V_99 ( V_62 , V_58 ) ;
if ( V_86 )
goto V_100;
}
V_95 = V_62 -> V_66 ;
V_62 -> V_66 = V_58 ;
F_74 ( V_95 ) ;
return 0 ;
V_100:
F_74 ( V_58 ) ;
return V_86 ;
}
static int F_75 ( struct V_59 * V_60 , unsigned long V_85 ,
unsigned long V_69 , struct V_9 * V_101 )
{
struct V_61 * V_82 ;
struct V_61 * V_88 ;
struct V_61 * V_62 ;
int V_86 = 0 ;
T_7 V_102 ;
unsigned long V_103 ;
unsigned long V_104 ;
V_62 = F_67 ( V_60 , V_85 ) ;
if ( ! V_62 || V_62 -> V_90 > V_85 )
return - V_89 ;
V_88 = V_62 -> V_105 ;
if ( V_85 > V_62 -> V_90 )
V_88 = V_62 ;
for (; V_62 && V_62 -> V_90 < V_69 ; V_88 = V_62 , V_62 = V_82 ) {
V_82 = V_62 -> V_65 ;
V_103 = F_76 ( V_85 , V_62 -> V_90 ) ;
V_104 = F_77 ( V_69 , V_62 -> V_92 ) ;
if ( F_78 ( F_79 ( V_62 ) , V_101 ) )
continue;
V_102 = V_62 -> V_96 +
( ( V_103 - V_62 -> V_90 ) >> V_106 ) ;
V_88 = F_80 ( V_60 , V_88 , V_103 , V_104 , V_62 -> V_107 ,
V_62 -> V_108 , V_62 -> V_98 , V_102 ,
V_101 ) ;
if ( V_88 ) {
V_62 = V_88 ;
V_82 = V_62 -> V_65 ;
continue;
}
if ( V_62 -> V_90 != V_103 ) {
V_86 = F_81 ( V_62 -> V_74 , V_62 , V_103 , 1 ) ;
if ( V_86 )
goto V_109;
}
if ( V_62 -> V_92 != V_104 ) {
V_86 = F_81 ( V_62 -> V_74 , V_62 , V_104 , 0 ) ;
if ( V_86 )
goto V_109;
}
V_86 = F_70 ( V_62 , V_101 ) ;
if ( V_86 )
goto V_109;
}
V_109:
return V_86 ;
}
void F_82 ( struct V_56 * V_43 )
{
if ( V_43 -> V_9 )
V_43 -> V_11 |= V_110 ;
else
V_43 -> V_11 &= ~ V_110 ;
}
static void F_83 ( void )
{
F_82 ( V_49 ) ;
}
static long F_84 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_58 , * V_95 ;
struct V_59 * V_60 = V_49 -> V_60 ;
F_85 ( V_111 ) ;
int V_13 ;
if ( ! V_111 )
return - V_41 ;
V_58 = F_18 ( V_28 , V_11 , V_17 ) ;
if ( F_72 ( V_58 ) ) {
V_13 = F_73 ( V_58 ) ;
goto V_109;
}
if ( V_60 )
F_42 ( & V_60 -> V_63 ) ;
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , V_17 , V_111 ) ;
if ( V_13 ) {
F_87 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_74 ( V_58 ) ;
goto V_109;
}
V_95 = V_49 -> V_9 ;
V_49 -> V_9 = V_58 ;
F_83 () ;
if ( V_58 && V_58 -> V_28 == V_112 &&
F_7 ( V_58 -> V_19 . V_17 ) )
V_49 -> V_50 = F_12 ( V_58 -> V_19 . V_17 ) ;
F_87 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_74 ( V_95 ) ;
V_13 = 0 ;
V_109:
F_88 ( V_111 ) ;
return V_13 ;
}
static void F_89 ( struct V_9 * V_43 , T_1 * V_17 )
{
F_90 ( * V_17 ) ;
if ( V_43 == & V_113 )
return;
switch ( V_43 -> V_28 ) {
case V_114 :
case V_112 :
* V_17 = V_43 -> V_19 . V_17 ;
break;
case V_29 :
if ( ! ( V_43 -> V_11 & V_20 ) )
F_91 ( V_43 -> V_19 . V_21 , * V_17 ) ;
break;
default:
F_30 () ;
}
}
static int F_92 ( struct V_59 * V_60 , unsigned long V_68 )
{
struct V_75 * V_43 ;
int V_86 ;
V_86 = F_93 ( V_49 , V_60 , V_68 & V_115 , 1 , 0 , 0 , & V_43 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_50 ( V_43 ) ;
F_94 ( V_43 ) ;
}
return V_86 ;
}
static long F_95 ( int * V_36 , T_1 * V_116 ,
unsigned long V_68 , unsigned long V_11 )
{
int V_86 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_61 * V_62 = NULL ;
struct V_9 * V_10 = V_49 -> V_9 ;
if ( V_11 &
~ ( unsigned long ) ( V_117 | V_118 | V_119 ) )
return - V_18 ;
if ( V_11 & V_119 ) {
if ( V_11 & ( V_117 | V_118 ) )
return - V_18 ;
* V_36 = 0 ;
F_86 ( V_49 ) ;
* V_116 = V_25 ;
F_87 ( V_49 ) ;
return 0 ;
}
if ( V_11 & V_118 ) {
F_96 ( & V_60 -> V_63 ) ;
V_62 = F_97 ( V_60 , V_68 , V_68 + 1 ) ;
if ( ! V_62 ) {
F_98 ( & V_60 -> V_63 ) ;
return - V_89 ;
}
if ( V_62 -> V_97 && V_62 -> V_97 -> V_120 )
V_10 = V_62 -> V_97 -> V_120 ( V_62 , V_68 ) ;
else
V_10 = V_62 -> V_66 ;
} else if ( V_68 )
return - V_18 ;
if ( ! V_10 )
V_10 = & V_113 ;
if ( V_11 & V_117 ) {
if ( V_11 & V_118 ) {
V_86 = F_92 ( V_60 , V_68 ) ;
if ( V_86 < 0 )
goto V_109;
* V_36 = V_86 ;
} else if ( V_10 == V_49 -> V_9 &&
V_10 -> V_28 == V_112 ) {
* V_36 = V_49 -> V_50 ;
} else {
V_86 = - V_18 ;
goto V_109;
}
} else {
* V_36 = V_10 == & V_113 ? V_37 :
V_10 -> V_28 ;
* V_36 |= ( V_10 -> V_11 & V_12 ) ;
}
if ( V_62 ) {
F_98 ( & V_49 -> V_60 -> V_63 ) ;
V_62 = NULL ;
}
V_86 = 0 ;
if ( V_116 ) {
if ( F_4 ( V_10 ) ) {
* V_116 = V_10 -> V_32 . V_33 ;
} else {
F_86 ( V_49 ) ;
F_89 ( V_10 , V_116 ) ;
F_87 ( V_49 ) ;
}
}
V_109:
F_99 ( V_10 ) ;
if ( V_62 )
F_98 ( & V_49 -> V_60 -> V_63 ) ;
return V_86 ;
}
static void F_51 ( struct V_75 * V_75 , struct V_121 * V_122 ,
unsigned long V_11 )
{
if ( ( V_11 & V_79 ) || F_100 ( V_75 ) == 1 ) {
if ( ! F_101 ( V_75 ) ) {
F_102 ( & V_75 -> V_123 , V_122 ) ;
F_103 ( V_75 , V_124 +
F_104 ( V_75 ) ) ;
}
}
}
static struct V_75 * F_105 ( struct V_75 * V_75 , unsigned long V_52 , int * * V_125 )
{
return F_106 ( V_52 , V_126 , 0 ) ;
}
static int F_107 ( struct V_59 * V_60 , int V_127 , int V_128 ,
int V_11 )
{
T_1 V_116 ;
F_108 ( V_122 ) ;
int V_86 = 0 ;
F_90 ( V_116 ) ;
F_91 ( V_127 , V_116 ) ;
F_16 ( ! ( V_11 & ( V_78 | V_79 ) ) ) ;
F_66 ( V_60 , V_60 -> V_64 -> V_90 , V_60 -> V_129 , & V_116 ,
V_11 | V_91 , & V_122 ) ;
if ( ! F_109 ( & V_122 ) ) {
V_86 = F_110 ( & V_122 , F_105 , V_128 ,
false , V_130 ) ;
if ( V_86 )
F_111 ( & V_122 ) ;
}
return V_86 ;
}
int F_112 ( struct V_59 * V_60 , const T_1 * V_131 ,
const T_1 * V_132 , int V_11 )
{
int V_133 = 0 ;
int V_86 ;
T_1 V_16 ;
V_86 = F_113 () ;
if ( V_86 )
return V_86 ;
F_96 ( & V_60 -> V_63 ) ;
V_86 = F_114 ( V_60 , V_131 , V_132 , V_11 ) ;
if ( V_86 )
goto V_109;
V_16 = * V_131 ;
while ( ! F_10 ( V_16 ) ) {
int V_134 , V_135 ;
int V_127 = - 1 ;
int V_128 = 0 ;
F_2 (s, tmp) {
if ( ( F_7 ( * V_131 ) != F_7 ( * V_132 ) ) &&
( F_32 ( V_134 , * V_132 ) ) )
continue;
V_135 = F_36 ( V_134 , * V_131 , * V_132 ) ;
if ( V_134 == V_135 )
continue;
V_127 = V_134 ;
V_128 = V_135 ;
if ( ! F_32 ( V_128 , V_16 ) )
break;
}
if ( V_127 == - 1 )
break;
F_115 ( V_127 , V_16 ) ;
V_86 = F_107 ( V_60 , V_127 , V_128 , V_11 ) ;
if ( V_86 > 0 )
V_133 += V_86 ;
if ( V_86 < 0 )
break;
}
V_109:
F_98 ( & V_60 -> V_63 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_133 ;
}
static struct V_75 * F_116 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_125 )
{
struct V_61 * V_62 = (struct V_61 * ) V_70 ;
unsigned long V_136 ( V_137 ) ;
while ( V_62 ) {
V_137 = F_117 ( V_75 , V_62 ) ;
if ( V_137 != - V_89 )
break;
V_62 = V_62 -> V_65 ;
}
return F_118 ( V_126 , V_62 , V_137 ) ;
}
static void F_51 ( struct V_75 * V_75 , struct V_121 * V_122 ,
unsigned long V_11 )
{
}
int F_112 ( struct V_59 * V_60 , const T_1 * V_131 ,
const T_1 * V_132 , int V_11 )
{
return - V_138 ;
}
static struct V_75 * F_116 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_125 )
{
return NULL ;
}
static long F_119 ( unsigned long V_85 , unsigned long V_139 ,
unsigned short V_28 , unsigned short V_140 ,
T_1 * V_116 , unsigned long V_11 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_9 * V_58 ;
unsigned long V_69 ;
int V_86 ;
F_108 ( V_122 ) ;
if ( V_11 & ~ ( unsigned long ) ( V_93 |
V_78 | V_79 ) )
return - V_18 ;
if ( ( V_11 & V_79 ) && ! F_120 ( V_141 ) )
return - V_142 ;
if ( V_85 & ~ V_115 )
return - V_18 ;
if ( V_28 == V_37 )
V_11 &= ~ V_93 ;
V_139 = ( V_139 + V_80 - 1 ) & V_115 ;
V_69 = V_85 + V_139 ;
if ( V_69 < V_85 )
return - V_18 ;
if ( V_69 == V_85 )
return 0 ;
V_58 = F_18 ( V_28 , V_140 , V_116 ) ;
if ( F_72 ( V_58 ) )
return F_73 ( V_58 ) ;
if ( ! V_58 )
V_11 |= V_91 ;
F_19 ( L_3 ,
V_85 , V_85 + V_139 , V_28 , V_140 ,
V_116 ? F_20 ( * V_116 ) [ 0 ] : - 1 ) ;
if ( V_11 & ( V_78 | V_79 ) ) {
V_86 = F_113 () ;
if ( V_86 )
goto V_143;
}
{
F_85 ( V_111 ) ;
if ( V_111 ) {
F_42 ( & V_60 -> V_63 ) ;
F_86 ( V_49 ) ;
V_86 = F_14 ( V_58 , V_116 , V_111 ) ;
F_87 ( V_49 ) ;
if ( V_86 )
F_43 ( & V_60 -> V_63 ) ;
} else
V_86 = - V_41 ;
F_88 ( V_111 ) ;
}
if ( V_86 )
goto V_143;
V_62 = F_66 ( V_60 , V_85 , V_69 , V_116 ,
V_11 | V_77 , & V_122 ) ;
V_86 = F_73 ( V_62 ) ;
if ( ! F_72 ( V_62 ) ) {
int V_144 = 0 ;
V_86 = F_75 ( V_60 , V_85 , V_69 , V_58 ) ;
if ( ! F_109 ( & V_122 ) ) {
V_144 = F_110 ( & V_122 , F_116 ,
( unsigned long ) V_62 ,
false , V_130 ) ;
if ( V_144 )
F_111 ( & V_122 ) ;
}
if ( ! V_86 && V_144 && ( V_11 & V_93 ) )
V_86 = - V_83 ;
} else
F_111 ( & V_122 ) ;
F_43 ( & V_60 -> V_63 ) ;
V_143:
F_74 ( V_58 ) ;
return V_86 ;
}
static int F_121 ( T_1 * V_17 , const unsigned long T_8 * V_116 ,
unsigned long V_145 )
{
unsigned long V_3 ;
unsigned long V_146 ;
unsigned long V_147 ;
-- V_145 ;
F_90 ( * V_17 ) ;
if ( V_145 == 0 || ! V_116 )
return 0 ;
if ( V_145 > V_80 * V_148 )
return - V_18 ;
V_146 = F_122 ( V_145 ) ;
if ( ( V_145 % V_149 ) == 0 )
V_147 = ~ 0UL ;
else
V_147 = ( 1UL << ( V_145 % V_149 ) ) - 1 ;
if ( V_146 > F_122 ( V_51 ) ) {
if ( V_146 > V_80 / sizeof( long ) )
return - V_18 ;
for ( V_3 = F_122 ( V_51 ) ; V_3 < V_146 ; V_3 ++ ) {
unsigned long V_150 ;
if ( F_123 ( V_150 , V_116 + V_3 ) )
return - V_89 ;
if ( V_3 == V_146 - 1 ) {
if ( V_150 & V_147 )
return - V_18 ;
} else if ( V_150 )
return - V_18 ;
}
V_146 = F_122 ( V_51 ) ;
V_147 = ~ 0UL ;
}
if ( F_124 ( F_20 ( * V_17 ) , V_116 , V_146 *sizeof( unsigned long ) ) )
return - V_89 ;
F_20 ( * V_17 ) [ V_146 - 1 ] &= V_147 ;
return 0 ;
}
static int F_125 ( unsigned long T_8 * V_151 , unsigned long V_145 ,
T_1 * V_17 )
{
unsigned long V_152 = F_126 ( V_145 - 1 , 64 ) / 8 ;
const int V_153 = F_122 ( V_51 ) * sizeof( long ) ;
if ( V_152 > V_153 ) {
if ( V_152 > V_80 )
return - V_18 ;
if ( F_127 ( ( char T_8 * ) V_151 + V_153 , V_152 - V_153 ) )
return - V_89 ;
V_152 = V_153 ;
}
return F_128 ( V_151 , F_20 ( * V_17 ) , V_152 ) ? - V_89 : 0 ;
}
T_9 long F_129 ( int T_8 * V_36 ,
T_10 T_8 * V_116 ,
T_10 V_145 ,
T_10 V_68 , T_10 V_11 )
{
long V_86 ;
unsigned long T_8 * V_154 = NULL ;
unsigned long V_155 , V_156 ;
F_130 ( V_157 , V_51 ) ;
V_155 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_156 = F_126 ( V_155 , V_149 ) / 8 ;
if ( V_116 )
V_154 = F_132 ( V_156 ) ;
V_86 = F_133 ( V_36 , V_154 , V_155 + 1 , V_68 , V_11 ) ;
if ( ! V_86 && V_116 ) {
unsigned long V_158 ;
V_158 = F_131 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_124 ( V_157 , V_154 , V_158 ) ;
V_86 |= F_127 ( V_116 , F_126 ( V_145 - 1 , 8 ) / 8 ) ;
V_86 |= F_134 ( V_116 , V_157 , V_155 ) ;
}
return V_86 ;
}
T_9 long F_135 ( int V_28 , T_10 T_8 * V_116 ,
T_10 V_145 )
{
long V_86 = 0 ;
unsigned long T_8 * V_154 = NULL ;
unsigned long V_155 , V_156 ;
F_130 ( V_157 , V_51 ) ;
V_155 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_156 = F_126 ( V_155 , V_149 ) / 8 ;
if ( V_116 ) {
V_86 = F_136 ( V_157 , V_116 , V_155 ) ;
V_154 = F_132 ( V_156 ) ;
V_86 |= F_128 ( V_154 , V_157 , V_156 ) ;
}
if ( V_86 )
return - V_89 ;
return F_137 ( V_28 , V_154 , V_155 + 1 ) ;
}
T_9 long F_138 ( T_10 V_85 , T_10 V_139 ,
T_10 V_28 , T_10 T_8 * V_116 ,
T_10 V_145 , T_10 V_11 )
{
long V_86 = 0 ;
unsigned long T_8 * V_154 = NULL ;
unsigned long V_155 , V_156 ;
T_1 V_157 ;
V_155 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_156 = F_126 ( V_155 , V_149 ) / 8 ;
if ( V_116 ) {
V_86 = F_136 ( F_20 ( V_157 ) , V_116 , V_155 ) ;
V_154 = F_132 ( V_156 ) ;
V_86 |= F_128 ( V_154 , F_20 ( V_157 ) , V_156 ) ;
}
if ( V_86 )
return - V_89 ;
return F_139 ( V_85 , V_139 , V_28 , V_154 , V_155 + 1 , V_11 ) ;
}
struct V_9 * F_140 ( struct V_56 * V_159 ,
struct V_61 * V_62 , unsigned long V_68 )
{
struct V_9 * V_10 = V_159 -> V_9 ;
if ( V_62 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_120 ) {
struct V_9 * V_160 = V_62 -> V_97 -> V_120 ( V_62 ,
V_68 ) ;
if ( V_160 )
V_10 = V_160 ;
} else if ( V_62 -> V_66 ) {
V_10 = V_62 -> V_66 ;
if ( F_141 ( V_10 ) )
F_142 ( V_10 ) ;
}
}
if ( ! V_10 )
V_10 = & V_113 ;
return V_10 ;
}
static T_1 * F_143 ( T_11 V_161 , struct V_9 * V_36 )
{
if ( F_144 ( V_36 -> V_28 == V_114 ) &&
F_145 ( V_161 ) >= V_6 &&
F_146 ( & V_36 -> V_19 . V_17 ) )
return & V_36 -> V_19 . V_17 ;
return NULL ;
}
static struct V_162 * F_147 ( T_11 V_161 , struct V_9 * V_36 ,
int V_2 )
{
switch ( V_36 -> V_28 ) {
case V_29 :
if ( ! ( V_36 -> V_11 & V_20 ) )
V_2 = V_36 -> V_19 . V_21 ;
break;
case V_114 :
if ( F_144 ( V_161 & V_163 ) &&
F_144 ( ! F_32 ( V_2 , V_36 -> V_19 . V_17 ) ) )
V_2 = F_12 ( V_36 -> V_19 . V_17 ) ;
break;
default:
F_30 () ;
}
return F_148 ( V_2 , V_161 ) ;
}
static unsigned F_149 ( struct V_9 * V_36 )
{
unsigned V_76 , V_82 ;
struct V_56 * V_164 = V_49 ;
V_76 = V_164 -> V_50 ;
V_82 = F_33 ( V_76 , V_36 -> V_19 . V_17 ) ;
if ( V_82 >= V_51 )
V_82 = F_12 ( V_36 -> V_19 . V_17 ) ;
if ( V_82 < V_51 )
V_164 -> V_50 = V_82 ;
return V_76 ;
}
unsigned F_150 ( void )
{
struct V_9 * V_36 ;
if ( F_151 () )
return F_34 () ;
V_36 = V_49 -> V_9 ;
if ( ! V_36 || V_36 -> V_11 & V_20 )
return F_34 () ;
switch ( V_36 -> V_28 ) {
case V_29 :
return V_36 -> V_19 . V_21 ;
case V_112 :
return F_149 ( V_36 ) ;
case V_114 : {
struct V_162 * V_162 ;
struct V_4 * V_4 ;
enum V_165 V_166 = F_145 ( V_40 ) ;
V_162 = & F_3 ( F_34 () ) -> V_167 [ 0 ] ;
( void ) F_152 ( V_162 , V_166 ,
& V_36 -> V_19 . V_17 ,
& V_4 ) ;
return V_4 ? V_4 -> V_52 : F_34 () ;
}
default:
F_30 () ;
}
}
static unsigned F_153 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_168 )
{
unsigned V_169 = F_7 ( V_10 -> V_19 . V_17 ) ;
unsigned V_170 ;
int V_171 ;
int V_76 = - 1 ;
if ( ! V_169 )
return F_34 () ;
V_170 = ( unsigned int ) V_168 % V_169 ;
V_171 = 0 ;
do {
V_76 = F_33 ( V_76 , V_10 -> V_19 . V_17 ) ;
V_171 ++ ;
} while ( V_171 <= V_170 );
return V_76 ;
}
static inline unsigned F_154 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_68 , int V_172 )
{
if ( V_62 ) {
unsigned long V_168 ;
F_155 ( V_172 < V_106 ) ;
V_168 = V_62 -> V_96 >> ( V_172 - V_106 ) ;
V_168 += ( V_68 - V_62 -> V_90 ) >> V_172 ;
return F_153 ( V_10 , V_62 , V_168 ) ;
} else
return F_149 ( V_10 ) ;
}
int F_156 ( const T_1 * V_173 )
{
int V_32 , V_174 = - 1 ;
V_32 = F_7 ( * V_173 ) ;
if ( V_32 )
V_174 = F_157 ( V_173 -> V_175 ,
F_158 () % V_32 , V_51 ) ;
return V_174 ;
}
struct V_162 * F_159 ( struct V_61 * V_62 , unsigned long V_68 ,
T_11 V_176 , struct V_9 * * V_177 ,
T_1 * * V_1 )
{
struct V_162 * V_178 ;
* V_177 = F_140 ( V_49 , V_62 , V_68 ) ;
* V_1 = NULL ;
if ( F_144 ( ( * V_177 ) -> V_28 == V_112 ) ) {
V_178 = F_148 ( F_154 ( * V_177 , V_62 , V_68 ,
F_160 ( F_161 ( V_62 ) ) ) , V_176 ) ;
} else {
V_178 = F_147 ( V_176 , * V_177 , F_34 () ) ;
if ( ( * V_177 ) -> V_28 == V_114 )
* V_1 = & ( * V_177 ) -> V_19 . V_17 ;
}
return V_178 ;
}
bool F_162 ( T_1 * V_151 )
{
struct V_9 * V_9 ;
int V_76 ;
if ( ! ( V_151 && V_49 -> V_9 ) )
return false ;
F_86 ( V_49 ) ;
V_9 = V_49 -> V_9 ;
switch ( V_9 -> V_28 ) {
case V_29 :
if ( V_9 -> V_11 & V_20 )
V_76 = F_34 () ;
else
V_76 = V_9 -> V_19 . V_21 ;
F_163 ( V_151 , V_76 ) ;
break;
case V_114 :
case V_112 :
* V_151 = V_9 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
F_87 ( V_49 ) ;
return true ;
}
bool F_164 ( struct V_56 * V_57 ,
const T_1 * V_151 )
{
struct V_9 * V_9 ;
bool V_13 = true ;
if ( ! V_151 )
return V_13 ;
F_86 ( V_57 ) ;
V_9 = V_57 -> V_9 ;
if ( ! V_9 )
goto V_109;
switch ( V_9 -> V_28 ) {
case V_29 :
break;
case V_114 :
case V_112 :
V_13 = F_165 ( V_9 -> V_19 . V_17 , * V_151 ) ;
break;
default:
F_30 () ;
}
V_109:
F_87 ( V_57 ) ;
return V_13 ;
}
static struct V_75 * F_166 ( T_11 V_161 , unsigned V_179 ,
unsigned V_76 )
{
struct V_162 * V_178 ;
struct V_75 * V_75 ;
V_178 = F_148 ( V_76 , V_161 ) ;
V_75 = F_167 ( V_161 , V_179 , V_178 ) ;
if ( V_75 && F_168 ( V_75 ) == F_169 ( & V_178 -> V_180 [ 0 ] ) )
F_103 ( V_75 , V_181 ) ;
return V_75 ;
}
struct V_75 *
F_170 ( T_11 V_161 , int V_179 , struct V_61 * V_62 ,
unsigned long V_68 , int V_52 )
{
struct V_9 * V_10 ;
struct V_162 * V_178 ;
struct V_75 * V_75 ;
unsigned int V_182 ;
V_183:
V_10 = F_140 ( V_49 , V_62 , V_68 ) ;
V_182 = F_171 () ;
if ( F_144 ( V_10 -> V_28 == V_112 ) ) {
unsigned V_76 ;
V_76 = F_154 ( V_10 , V_62 , V_68 , V_106 + V_179 ) ;
F_99 ( V_10 ) ;
V_75 = F_166 ( V_161 , V_179 , V_76 ) ;
if ( F_144 ( ! F_172 ( V_182 ) && ! V_75 ) )
goto V_183;
return V_75 ;
}
V_178 = F_147 ( V_161 , V_10 , V_52 ) ;
if ( F_144 ( F_141 ( V_10 ) ) ) {
struct V_75 * V_75 = F_173 ( V_161 , V_179 ,
V_178 , F_143 ( V_161 , V_10 ) ) ;
F_24 ( V_10 ) ;
if ( F_144 ( ! F_172 ( V_182 ) && ! V_75 ) )
goto V_183;
return V_75 ;
}
V_75 = F_173 ( V_161 , V_179 , V_178 ,
F_143 ( V_161 , V_10 ) ) ;
if ( F_144 ( ! F_172 ( V_182 ) && ! V_75 ) )
goto V_183;
return V_75 ;
}
struct V_75 * F_174 ( T_11 V_161 , unsigned V_179 )
{
struct V_9 * V_10 = V_49 -> V_9 ;
struct V_75 * V_75 ;
unsigned int V_182 ;
if ( ! V_10 || F_151 () || ( V_161 & V_163 ) )
V_10 = & V_113 ;
V_183:
V_182 = F_171 () ;
if ( V_10 -> V_28 == V_112 )
V_75 = F_166 ( V_161 , V_179 , F_149 ( V_10 ) ) ;
else
V_75 = F_173 ( V_161 , V_179 ,
F_147 ( V_161 , V_10 , F_34 () ) ,
F_143 ( V_161 , V_10 ) ) ;
if ( F_144 ( ! F_172 ( V_182 ) && ! V_75 ) )
goto V_183;
return V_75 ;
}
struct V_9 * F_175 ( struct V_9 * V_95 )
{
struct V_9 * V_58 = F_22 ( V_39 , V_40 ) ;
if ( ! V_58 )
return F_21 ( - V_41 ) ;
if ( V_95 == V_49 -> V_9 ) {
F_86 ( V_49 ) ;
* V_58 = * V_95 ;
F_87 ( V_49 ) ;
} else
* V_58 = * V_95 ;
F_176 () ;
if ( F_177 () ) {
T_1 V_184 = V_34 ( V_49 ) ;
if ( V_58 -> V_11 & V_54 )
F_37 ( V_58 , & V_184 , V_48 ) ;
else
F_37 ( V_58 , & V_184 , V_46 ) ;
}
F_178 () ;
F_23 ( & V_58 -> V_42 , 1 ) ;
return V_58 ;
}
bool F_179 ( struct V_9 * V_185 , struct V_9 * V_186 )
{
if ( ! V_185 || ! V_186 )
return false ;
if ( V_185 -> V_28 != V_186 -> V_28 )
return false ;
if ( V_185 -> V_11 != V_186 -> V_11 )
return false ;
if ( F_4 ( V_185 ) )
if ( ! F_38 ( V_185 -> V_32 . V_33 , V_186 -> V_32 . V_33 ) )
return false ;
switch ( V_185 -> V_28 ) {
case V_114 :
case V_112 :
return ! ! F_38 ( V_185 -> V_19 . V_17 , V_186 -> V_19 . V_17 ) ;
case V_29 :
return V_185 -> V_19 . V_21 == V_186 -> V_19 . V_21 ;
default:
F_30 () ;
return false ;
}
}
static struct V_187 *
F_180 ( struct V_188 * V_189 , unsigned long V_85 , unsigned long V_69 )
{
struct V_190 * V_191 = V_189 -> V_192 . V_190 ;
while ( V_191 ) {
struct V_187 * V_43 = F_181 ( V_191 , struct V_187 , V_2 ) ;
if ( V_85 >= V_43 -> V_69 )
V_191 = V_191 -> V_193 ;
else if ( V_69 <= V_43 -> V_85 )
V_191 = V_191 -> V_194 ;
else
break;
}
if ( ! V_191 )
return NULL ;
for (; ; ) {
struct V_187 * V_32 = NULL ;
struct V_190 * V_88 = F_182 ( V_191 ) ;
if ( ! V_88 )
break;
V_32 = F_181 ( V_88 , struct V_187 , V_2 ) ;
if ( V_32 -> V_69 <= V_85 )
break;
V_191 = V_88 ;
}
return F_181 ( V_191 , struct V_187 , V_2 ) ;
}
static void F_183 ( struct V_188 * V_189 , struct V_187 * V_58 )
{
struct V_190 * * V_43 = & V_189 -> V_192 . V_190 ;
struct V_190 * V_195 = NULL ;
struct V_187 * V_2 ;
while ( * V_43 ) {
V_195 = * V_43 ;
V_2 = F_181 ( V_195 , struct V_187 , V_2 ) ;
if ( V_58 -> V_85 < V_2 -> V_85 )
V_43 = & ( * V_43 ) -> V_194 ;
else if ( V_58 -> V_69 > V_2 -> V_69 )
V_43 = & ( * V_43 ) -> V_193 ;
else
F_30 () ;
}
F_184 ( & V_58 -> V_2 , V_195 , V_43 ) ;
F_185 ( & V_58 -> V_2 , & V_189 -> V_192 ) ;
F_19 ( L_4 , V_58 -> V_85 , V_58 -> V_69 ,
V_58 -> V_36 ? V_58 -> V_36 -> V_28 : 0 ) ;
}
struct V_9 *
F_186 ( struct V_188 * V_189 , unsigned long V_196 )
{
struct V_9 * V_10 = NULL ;
struct V_187 * V_197 ;
if ( ! V_189 -> V_192 . V_190 )
return NULL ;
F_187 ( & V_189 -> V_198 ) ;
V_197 = F_180 ( V_189 , V_196 , V_196 + 1 ) ;
if ( V_197 ) {
F_142 ( V_197 -> V_36 ) ;
V_10 = V_197 -> V_36 ;
}
F_188 ( & V_189 -> V_198 ) ;
return V_10 ;
}
static void F_189 ( struct V_187 * V_191 )
{
F_74 ( V_191 -> V_36 ) ;
F_26 ( V_199 , V_191 ) ;
}
static void F_190 ( struct V_188 * V_189 , struct V_187 * V_191 )
{
F_19 ( L_5 , V_191 -> V_85 , V_191 -> V_69 ) ;
F_191 ( & V_191 -> V_2 , & V_189 -> V_192 ) ;
F_189 ( V_191 ) ;
}
static struct V_187 * F_192 ( unsigned long V_85 , unsigned long V_69 ,
struct V_9 * V_10 )
{
struct V_187 * V_191 ;
struct V_9 * V_200 ;
V_191 = F_22 ( V_199 , V_40 ) ;
if ( ! V_191 )
return NULL ;
V_200 = F_71 ( V_10 ) ;
if ( F_72 ( V_200 ) ) {
F_26 ( V_199 , V_191 ) ;
return NULL ;
}
V_200 -> V_11 |= V_201 ;
V_191 -> V_85 = V_85 ;
V_191 -> V_69 = V_69 ;
V_191 -> V_36 = V_200 ;
return V_191 ;
}
static int F_193 ( struct V_188 * V_189 , unsigned long V_85 ,
unsigned long V_69 , struct V_187 * V_58 )
{
struct V_187 * V_191 ;
int V_13 = 0 ;
F_187 ( & V_189 -> V_198 ) ;
V_191 = F_180 ( V_189 , V_85 , V_69 ) ;
while ( V_191 && V_191 -> V_85 < V_69 ) {
struct V_190 * V_82 = F_194 ( & V_191 -> V_2 ) ;
if ( V_191 -> V_85 >= V_85 ) {
if ( V_191 -> V_69 <= V_69 )
F_190 ( V_189 , V_191 ) ;
else
V_191 -> V_85 = V_69 ;
} else {
if ( V_191 -> V_69 > V_69 ) {
struct V_187 * V_202 ;
V_202 = F_192 ( V_69 , V_191 -> V_69 , V_191 -> V_36 ) ;
if ( ! V_202 ) {
V_13 = - V_41 ;
goto V_109;
}
V_191 -> V_69 = V_85 ;
F_183 ( V_189 , V_202 ) ;
break;
} else
V_191 -> V_69 = V_85 ;
}
if ( ! V_82 )
break;
V_191 = F_181 ( V_82 , struct V_187 , V_2 ) ;
}
if ( V_58 )
F_183 ( V_189 , V_58 ) ;
V_109:
F_188 ( & V_189 -> V_198 ) ;
return V_13 ;
}
void F_195 ( struct V_188 * V_189 , struct V_9 * V_177 )
{
int V_13 ;
V_189 -> V_192 = V_203 ;
F_196 ( & V_189 -> V_198 ) ;
if ( V_177 ) {
struct V_61 V_204 ;
struct V_9 * V_58 ;
F_85 ( V_111 ) ;
if ( ! V_111 )
goto V_205;
V_58 = F_18 ( V_177 -> V_28 , V_177 -> V_11 , & V_177 -> V_32 . V_33 ) ;
if ( F_72 ( V_58 ) )
goto V_206;
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_177 -> V_32 . V_33 , V_111 ) ;
F_87 ( V_49 ) ;
if ( V_13 )
goto V_207;
memset ( & V_204 , 0 , sizeof( struct V_61 ) ) ;
V_204 . V_92 = V_208 ;
F_197 ( V_189 , & V_204 , V_58 ) ;
V_207:
F_74 ( V_58 ) ;
V_206:
F_88 ( V_111 ) ;
V_205:
F_74 ( V_177 ) ;
}
}
int F_197 ( struct V_188 * V_209 ,
struct V_61 * V_62 , struct V_9 * V_210 )
{
int V_86 ;
struct V_187 * V_58 = NULL ;
unsigned long V_211 = F_198 ( V_62 ) ;
F_19 ( L_6 ,
V_62 -> V_96 ,
V_211 , V_210 ? V_210 -> V_28 : - 1 ,
V_210 ? V_210 -> V_11 : - 1 ,
V_210 ? F_20 ( V_210 -> V_19 . V_17 ) [ 0 ] : - 1 ) ;
if ( V_210 ) {
V_58 = F_192 ( V_62 -> V_96 , V_62 -> V_96 + V_211 , V_210 ) ;
if ( ! V_58 )
return - V_41 ;
}
V_86 = F_193 ( V_209 , V_62 -> V_96 , V_62 -> V_96 + V_211 , V_58 ) ;
if ( V_86 && V_58 )
F_189 ( V_58 ) ;
return V_86 ;
}
void F_199 ( struct V_188 * V_43 )
{
struct V_187 * V_191 ;
struct V_190 * V_82 ;
if ( ! V_43 -> V_192 . V_190 )
return;
F_187 ( & V_43 -> V_198 ) ;
V_82 = F_200 ( & V_43 -> V_192 ) ;
while ( V_82 ) {
V_191 = F_181 ( V_82 , struct V_187 , V_2 ) ;
V_82 = F_194 ( & V_191 -> V_2 ) ;
F_190 ( V_43 , V_191 ) ;
}
F_188 ( & V_43 -> V_198 ) ;
}
void T_12 F_201 ( void )
{
T_1 F_149 ;
unsigned long V_212 = 0 ;
int V_76 , V_213 = 0 ;
V_39 = F_202 ( L_7 ,
sizeof( struct V_9 ) ,
0 , V_214 , NULL ) ;
V_199 = F_202 ( L_8 ,
sizeof( struct V_187 ) ,
0 , V_214 , NULL ) ;
F_90 ( F_149 ) ;
F_203 (nid, N_HIGH_MEMORY) {
unsigned long V_215 = F_204 ( V_76 ) ;
if ( V_212 < V_215 ) {
V_212 = V_215 ;
V_213 = V_76 ;
}
if ( ( V_215 << V_106 ) >= ( 16 << 20 ) )
F_91 ( V_76 , F_149 ) ;
}
if ( F_144 ( F_10 ( F_149 ) ) )
F_91 ( V_213 , F_149 ) ;
if ( F_84 ( V_112 , 0 , & F_149 ) )
F_205 ( L_9 ) ;
}
void F_206 ( void )
{
F_84 ( V_37 , 0 , NULL ) ;
}
int F_207 ( char * V_216 , struct V_9 * * V_177 , int V_217 )
{
struct V_9 * V_58 = NULL ;
unsigned short V_28 ;
unsigned short V_136 ( V_140 ) ;
T_1 V_17 ;
char * V_218 = strchr ( V_216 , ':' ) ;
char * V_11 = strchr ( V_216 , '=' ) ;
int V_86 = 1 ;
if ( V_218 ) {
* V_218 ++ = '\0' ;
if ( F_208 ( V_218 , V_17 ) )
goto V_109;
if ( ! F_209 ( V_17 , V_26 [ V_27 ] ) )
goto V_109;
} else
F_90 ( V_17 ) ;
if ( V_11 )
* V_11 ++ = '\0' ;
for ( V_28 = 0 ; V_28 <= V_219 ; V_28 ++ ) {
if ( ! strcmp ( V_216 , V_220 [ V_28 ] ) ) {
break;
}
}
if ( V_28 > V_219 )
goto V_109;
switch ( V_28 ) {
case V_29 :
if ( V_218 ) {
char * V_221 = V_218 ;
while ( isdigit ( * V_221 ) )
V_221 ++ ;
if ( * V_221 )
goto V_109;
}
break;
case V_112 :
if ( ! V_218 )
V_17 = V_26 [ V_27 ] ;
break;
case V_219 :
if ( V_218 )
goto V_109;
V_28 = V_29 ;
break;
case V_37 :
if ( ! V_218 )
V_86 = 0 ;
goto V_109;
case V_114 :
if ( ! V_218 )
goto V_109;
}
V_140 = 0 ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_10 ) )
V_140 |= V_38 ;
else if ( ! strcmp ( V_11 , L_11 ) )
V_140 |= V_30 ;
else
goto V_109;
}
V_58 = F_18 ( V_28 , V_140 , & V_17 ) ;
if ( F_72 ( V_58 ) )
goto V_109;
if ( V_217 ) {
V_58 -> V_32 . V_33 = V_17 ;
} else {
int V_13 ;
F_85 ( V_111 ) ;
if ( V_111 ) {
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_17 , V_111 ) ;
F_87 ( V_49 ) ;
} else
V_13 = - V_41 ;
F_88 ( V_111 ) ;
if ( V_13 ) {
F_74 ( V_58 ) ;
goto V_109;
}
}
V_86 = 0 ;
V_109:
if ( V_218 )
* -- V_218 = ':' ;
if ( V_11 )
* -- V_11 = '=' ;
if ( ! V_86 )
* V_177 = V_58 ;
return V_86 ;
}
int F_210 ( char * V_222 , int V_223 , struct V_9 * V_10 , int V_217 )
{
char * V_43 = V_222 ;
int V_224 ;
T_1 V_17 ;
unsigned short V_28 ;
unsigned short V_11 = V_10 ? V_10 -> V_11 : 0 ;
F_16 ( V_223 < strlen ( L_12 ) + strlen ( L_11 ) + 16 ) ;
if ( ! V_10 || V_10 == & V_113 )
V_28 = V_37 ;
else
V_28 = V_10 -> V_28 ;
switch ( V_28 ) {
case V_37 :
F_90 ( V_17 ) ;
break;
case V_29 :
F_90 ( V_17 ) ;
if ( V_11 & V_20 )
V_28 = V_219 ;
else
F_91 ( V_10 -> V_19 . V_21 , V_17 ) ;
break;
case V_114 :
case V_112 :
if ( V_217 )
V_17 = V_10 -> V_32 . V_33 ;
else
V_17 = V_10 -> V_19 . V_17 ;
break;
default:
return - V_18 ;
}
V_224 = strlen ( V_220 [ V_28 ] ) ;
if ( V_222 + V_223 < V_43 + V_224 + 1 )
return - V_225 ;
strcpy ( V_43 , V_220 [ V_28 ] ) ;
V_43 += V_224 ;
if ( V_11 & V_12 ) {
if ( V_222 + V_223 < V_43 + 2 )
return - V_225 ;
* V_43 ++ = '=' ;
if ( V_11 & V_38 )
V_43 += snprintf ( V_43 , V_222 + V_223 - V_43 , L_10 ) ;
else if ( V_11 & V_30 )
V_43 += snprintf ( V_43 , V_222 + V_223 - V_43 , L_11 ) ;
}
if ( ! F_10 ( V_17 ) ) {
if ( V_222 + V_223 < V_43 + 2 )
return - V_225 ;
* V_43 ++ = ':' ;
V_43 += F_211 ( V_43 , V_222 + V_223 - V_43 , V_17 ) ;
}
return V_43 - V_222 ;
}
