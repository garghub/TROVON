static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_1 ;
int V_5 ;
if ( ! V_4 ) {
V_5 = F_2 () ;
if ( V_5 != - 1 )
V_4 = & V_6 [ V_5 ] ;
if ( ! V_4 -> V_7 )
V_4 = NULL ;
}
return V_4 ;
}
static int F_3 ( const T_1 * V_8 )
{
int V_9 , V_10 ;
F_4 (nd, *nodemask) {
struct V_11 * V_12 ;
for ( V_10 = 0 ; V_10 <= V_13 ; V_10 ++ ) {
V_12 = & F_5 ( V_9 ) -> V_14 [ V_10 ] ;
if ( V_12 -> V_15 > 0 )
return 1 ;
}
}
return 0 ;
}
static inline int F_6 ( const struct V_1 * V_4 )
{
return V_4 -> V_16 & V_17 ;
}
static void F_7 ( T_1 * V_18 , const T_1 * V_19 ,
const T_1 * V_20 )
{
T_1 V_21 ;
F_8 ( V_21 , * V_19 , F_9 ( * V_20 ) ) ;
F_10 ( * V_18 , V_21 , * V_20 ) ;
}
static int F_11 ( struct V_1 * V_4 , const T_1 * V_22 )
{
if ( F_12 ( * V_22 ) )
return - V_23 ;
V_4 -> V_24 . V_22 = * V_22 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_4 , const T_1 * V_22 )
{
if ( ! V_22 )
V_4 -> V_16 |= V_25 ;
else if ( F_12 ( * V_22 ) )
return - V_23 ;
else
V_4 -> V_24 . V_26 = F_14 ( * V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_4 , const T_1 * V_22 )
{
if ( ! F_3 ( V_22 ) )
return - V_23 ;
V_4 -> V_24 . V_22 = * V_22 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_4 ,
const T_1 * V_22 , struct V_27 * V_28 )
{
int V_18 ;
if ( V_4 == NULL )
return 0 ;
F_17 ( V_28 -> V_29 ,
V_30 , V_31 [ V_32 ] ) ;
F_18 ( ! V_22 ) ;
if ( V_4 -> V_7 == V_33 && F_12 ( * V_22 ) )
V_22 = NULL ;
else {
if ( V_4 -> V_16 & V_34 )
F_7 ( & V_28 -> V_35 , V_22 , & V_28 -> V_29 ) ;
else
F_17 ( V_28 -> V_35 , * V_22 , V_28 -> V_29 ) ;
if ( F_6 ( V_4 ) )
V_4 -> V_36 . V_37 = * V_22 ;
else
V_4 -> V_36 . V_38 =
V_30 ;
}
if ( V_22 )
V_18 = V_39 [ V_4 -> V_7 ] . F_19 ( V_4 , & V_28 -> V_35 ) ;
else
V_18 = V_39 [ V_4 -> V_7 ] . F_19 ( V_4 , NULL ) ;
return V_18 ;
}
static struct V_1 * F_20 ( unsigned short V_7 , unsigned short V_16 ,
T_1 * V_22 )
{
struct V_1 * V_40 ;
F_21 ( L_1 ,
V_7 , V_16 , V_22 ? F_22 ( * V_22 ) [ 0 ] : - 1 ) ;
if ( V_7 == V_41 ) {
if ( V_22 && ! F_12 ( * V_22 ) )
return F_23 ( - V_23 ) ;
return NULL ;
}
F_18 ( ! V_22 ) ;
if ( V_7 == V_33 ) {
if ( F_12 ( * V_22 ) ) {
if ( ( ( V_16 & V_42 ) ||
( V_16 & V_34 ) ) )
return F_23 ( - V_23 ) ;
}
} else if ( V_7 == V_43 ) {
if ( ! F_12 ( * V_22 ) )
return F_23 ( - V_23 ) ;
V_7 = V_33 ;
} else if ( F_12 ( * V_22 ) )
return F_23 ( - V_23 ) ;
V_40 = F_24 ( V_44 , V_45 ) ;
if ( ! V_40 )
return F_23 ( - V_46 ) ;
F_25 ( & V_40 -> V_47 , 1 ) ;
V_40 -> V_7 = V_7 ;
V_40 -> V_16 = V_16 ;
return V_40 ;
}
void F_26 ( struct V_1 * V_3 )
{
if ( ! F_27 ( & V_3 -> V_47 ) )
return;
F_28 ( V_44 , V_3 ) ;
}
static void F_29 ( struct V_1 * V_4 , const T_1 * V_22 ,
enum V_48 V_49 )
{
}
static void F_30 ( struct V_1 * V_4 , const T_1 * V_22 ,
enum V_48 V_49 )
{
T_1 V_21 ;
if ( V_4 -> V_16 & V_42 )
F_17 ( V_21 , V_4 -> V_36 . V_37 , * V_22 ) ;
else if ( V_4 -> V_16 & V_34 )
F_7 ( & V_21 , & V_4 -> V_36 . V_37 , V_22 ) ;
else {
if ( V_49 == V_50 || V_49 == V_51 ) {
F_31 ( V_21 , V_4 -> V_24 . V_22 ,
V_4 -> V_36 . V_38 , * V_22 ) ;
V_4 -> V_36 . V_38 = V_49 ? V_21 : * V_22 ;
} else if ( V_49 == V_52 ) {
V_21 = V_4 -> V_36 . V_38 ;
V_4 -> V_36 . V_38 = * V_22 ;
} else
F_32 () ;
}
if ( F_12 ( V_21 ) )
V_21 = * V_22 ;
if ( V_49 == V_51 )
F_33 ( V_4 -> V_24 . V_22 , V_4 -> V_24 . V_22 , V_21 ) ;
else if ( V_49 == V_50 || V_49 == V_52 )
V_4 -> V_24 . V_22 = V_21 ;
else
F_32 () ;
if ( ! F_34 ( V_53 -> V_54 , V_21 ) ) {
V_53 -> V_54 = F_35 ( V_53 -> V_54 , V_21 ) ;
if ( V_53 -> V_54 >= V_55 )
V_53 -> V_54 = F_14 ( V_21 ) ;
if ( V_53 -> V_54 >= V_55 )
V_53 -> V_54 = F_2 () ;
}
}
static void F_36 ( struct V_1 * V_4 ,
const T_1 * V_22 ,
enum V_48 V_49 )
{
T_1 V_21 ;
if ( V_4 -> V_16 & V_42 ) {
int V_5 = F_14 ( V_4 -> V_36 . V_37 ) ;
if ( F_34 ( V_5 , * V_22 ) ) {
V_4 -> V_24 . V_26 = V_5 ;
V_4 -> V_16 &= ~ V_25 ;
} else
V_4 -> V_16 |= V_25 ;
} else if ( V_4 -> V_16 & V_34 ) {
F_7 ( & V_21 , & V_4 -> V_36 . V_37 , V_22 ) ;
V_4 -> V_24 . V_26 = F_14 ( V_21 ) ;
} else if ( ! ( V_4 -> V_16 & V_25 ) ) {
V_4 -> V_24 . V_26 = F_37 ( V_4 -> V_24 . V_26 ,
V_4 -> V_36 . V_38 ,
* V_22 ) ;
V_4 -> V_36 . V_38 = * V_22 ;
}
}
static void F_38 ( struct V_1 * V_4 , const T_1 * V_56 ,
enum V_48 V_49 )
{
if ( ! V_4 )
return;
if ( ! F_6 ( V_4 ) && V_49 == V_50 &&
F_39 ( V_4 -> V_36 . V_38 , * V_56 ) )
return;
if ( V_49 == V_51 && ( V_4 -> V_16 & V_57 ) )
return;
if ( V_49 == V_52 && ! ( V_4 -> V_16 & V_57 ) )
F_32 () ;
if ( V_49 == V_51 )
V_4 -> V_16 |= V_57 ;
else if ( V_49 == V_52 )
V_4 -> V_16 &= ~ V_57 ;
else if ( V_49 >= V_58 )
F_32 () ;
V_39 [ V_4 -> V_7 ] . F_40 ( V_4 , V_56 , V_49 ) ;
}
void F_41 ( struct V_2 * V_59 , const T_1 * V_60 ,
enum V_48 V_49 )
{
F_38 ( V_59 -> V_1 , V_60 , V_49 ) ;
}
void F_42 ( struct V_61 * V_62 , T_1 * V_60 )
{
struct V_63 * V_64 ;
F_43 ( & V_62 -> V_65 ) ;
for ( V_64 = V_62 -> V_66 ; V_64 ; V_64 = V_64 -> V_67 )
F_38 ( V_64 -> V_68 , V_60 , V_50 ) ;
F_44 ( & V_62 -> V_65 ) ;
}
static int F_45 ( struct V_63 * V_64 , T_2 * V_69 ,
unsigned long V_70 , unsigned long V_71 ,
const T_1 * V_22 , unsigned long V_16 ,
void * V_72 )
{
T_3 * V_73 ;
T_3 * V_74 ;
T_4 * V_75 ;
V_73 = V_74 = F_46 ( V_64 -> V_76 , V_69 , V_70 , & V_75 ) ;
do {
struct V_77 * V_77 ;
int V_78 ;
if ( ! F_47 ( * V_74 ) )
continue;
V_77 = F_48 ( V_64 , V_70 , * V_74 ) ;
if ( ! V_77 )
continue;
if ( F_49 ( V_77 ) || F_50 ( V_77 ) )
continue;
V_78 = F_51 ( V_77 ) ;
if ( F_34 ( V_78 , * V_22 ) == ! ! ( V_16 & V_79 ) )
continue;
if ( V_16 & ( V_80 | V_81 ) )
F_52 ( V_77 , V_72 , V_16 ) ;
else
break;
} while ( V_74 ++ , V_70 += V_82 , V_70 != V_71 );
F_53 ( V_73 , V_75 ) ;
return V_70 != V_71 ;
}
static inline int F_54 ( struct V_63 * V_64 , T_5 * V_83 ,
unsigned long V_70 , unsigned long V_71 ,
const T_1 * V_22 , unsigned long V_16 ,
void * V_72 )
{
T_2 * V_69 ;
unsigned long V_84 ;
V_69 = F_55 ( V_83 , V_70 ) ;
do {
V_84 = F_56 ( V_70 , V_71 ) ;
F_57 ( V_64 , V_70 , V_69 ) ;
if ( F_58 ( V_69 ) )
continue;
if ( F_45 ( V_64 , V_69 , V_70 , V_84 , V_22 ,
V_16 , V_72 ) )
return - V_85 ;
} while ( V_69 ++ , V_70 = V_84 , V_70 != V_71 );
return 0 ;
}
static inline int F_59 ( struct V_63 * V_64 , T_6 * V_86 ,
unsigned long V_70 , unsigned long V_71 ,
const T_1 * V_22 , unsigned long V_16 ,
void * V_72 )
{
T_5 * V_83 ;
unsigned long V_84 ;
V_83 = F_60 ( V_86 , V_70 ) ;
do {
V_84 = F_61 ( V_70 , V_71 ) ;
if ( F_62 ( V_83 ) )
continue;
if ( F_54 ( V_64 , V_83 , V_70 , V_84 , V_22 ,
V_16 , V_72 ) )
return - V_85 ;
} while ( V_83 ++ , V_70 = V_84 , V_70 != V_71 );
return 0 ;
}
static inline int F_63 ( struct V_63 * V_64 ,
unsigned long V_70 , unsigned long V_71 ,
const T_1 * V_22 , unsigned long V_16 ,
void * V_72 )
{
T_6 * V_86 ;
unsigned long V_84 ;
V_86 = F_64 ( V_64 -> V_76 , V_70 ) ;
do {
V_84 = F_65 ( V_70 , V_71 ) ;
if ( F_66 ( V_86 ) )
continue;
if ( F_59 ( V_64 , V_86 , V_70 , V_84 , V_22 ,
V_16 , V_72 ) )
return - V_85 ;
} while ( V_86 ++ , V_70 = V_84 , V_70 != V_71 );
return 0 ;
}
unsigned long F_67 ( struct V_63 * V_64 ,
unsigned long V_70 , unsigned long V_71 )
{
int V_87 ;
F_68 ( V_88 != V_89 ) ;
V_87 = F_69 ( V_64 , V_70 , V_71 , V_64 -> V_90 , 0 , 1 ) ;
if ( V_87 )
F_70 ( V_91 , V_87 ) ;
return V_87 ;
}
static unsigned long F_67 ( struct V_63 * V_64 ,
unsigned long V_70 , unsigned long V_71 )
{
return 0 ;
}
static struct V_63 *
F_71 ( struct V_61 * V_62 , unsigned long V_92 , unsigned long V_71 ,
const T_1 * V_22 , unsigned long V_16 , void * V_72 )
{
int V_93 ;
struct V_63 * V_94 , * V_64 , * V_95 ;
V_94 = F_72 ( V_62 , V_92 ) ;
if ( ! V_94 )
return F_23 ( - V_96 ) ;
V_95 = NULL ;
for ( V_64 = V_94 ; V_64 && V_64 -> V_97 < V_71 ; V_64 = V_64 -> V_67 ) {
unsigned long V_98 = V_64 -> V_99 ;
if ( V_98 > V_71 )
V_98 = V_71 ;
if ( V_64 -> V_97 > V_92 )
V_92 = V_64 -> V_97 ;
if ( ! ( V_16 & V_100 ) ) {
if ( ! V_64 -> V_67 && V_64 -> V_99 < V_71 )
return F_23 ( - V_96 ) ;
if ( V_95 && V_95 -> V_99 < V_64 -> V_97 )
return F_23 ( - V_96 ) ;
}
if ( F_73 ( V_64 ) )
goto V_84;
if ( V_16 & V_101 ) {
F_67 ( V_64 , V_92 , V_98 ) ;
goto V_84;
}
if ( ( V_16 & V_102 ) ||
( ( V_16 & ( V_80 | V_81 ) ) &&
F_74 ( V_64 ) ) ) {
V_93 = F_63 ( V_64 , V_92 , V_98 , V_22 ,
V_16 , V_72 ) ;
if ( V_93 ) {
V_94 = F_23 ( V_93 ) ;
break;
}
}
V_84:
V_95 = V_64 ;
}
return V_94 ;
}
static int F_75 ( struct V_63 * V_64 ,
struct V_1 * V_4 )
{
int V_93 ;
struct V_1 * V_103 ;
struct V_1 * V_60 ;
F_21 ( L_2 ,
V_64 -> V_97 , V_64 -> V_99 , V_64 -> V_104 ,
V_64 -> V_105 , V_64 -> V_106 ,
V_64 -> V_105 ? V_64 -> V_105 -> V_107 : NULL ) ;
V_60 = F_76 ( V_4 ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_64 -> V_105 && V_64 -> V_105 -> V_107 ) {
V_93 = V_64 -> V_105 -> V_107 ( V_64 , V_60 ) ;
if ( V_93 )
goto V_108;
}
V_103 = V_64 -> V_68 ;
V_64 -> V_68 = V_60 ;
F_79 ( V_103 ) ;
return 0 ;
V_108:
F_79 ( V_60 ) ;
return V_93 ;
}
static int F_80 ( struct V_61 * V_62 , unsigned long V_92 ,
unsigned long V_71 , struct V_1 * V_109 )
{
struct V_63 * V_84 ;
struct V_63 * V_95 ;
struct V_63 * V_64 ;
int V_93 = 0 ;
T_7 V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_64 = F_72 ( V_62 , V_92 ) ;
if ( ! V_64 || V_64 -> V_97 > V_92 )
return - V_96 ;
V_95 = V_64 -> V_113 ;
if ( V_92 > V_64 -> V_97 )
V_95 = V_64 ;
for (; V_64 && V_64 -> V_97 < V_71 ; V_95 = V_64 , V_64 = V_84 ) {
V_84 = V_64 -> V_67 ;
V_111 = F_81 ( V_92 , V_64 -> V_97 ) ;
V_112 = F_82 ( V_71 , V_64 -> V_99 ) ;
if ( F_83 ( F_84 ( V_64 ) , V_109 ) )
continue;
V_110 = V_64 -> V_104 +
( ( V_111 - V_64 -> V_97 ) >> V_114 ) ;
V_95 = F_85 ( V_62 , V_95 , V_111 , V_112 , V_64 -> V_115 ,
V_64 -> V_116 , V_64 -> V_106 , V_110 ,
V_109 ) ;
if ( V_95 ) {
V_64 = V_95 ;
V_84 = V_64 -> V_67 ;
continue;
}
if ( V_64 -> V_97 != V_111 ) {
V_93 = F_86 ( V_64 -> V_76 , V_64 , V_111 , 1 ) ;
if ( V_93 )
goto V_117;
}
if ( V_64 -> V_99 != V_112 ) {
V_93 = F_86 ( V_64 -> V_76 , V_64 , V_112 , 0 ) ;
if ( V_93 )
goto V_117;
}
V_93 = F_75 ( V_64 , V_109 ) ;
if ( V_93 )
goto V_117;
}
V_117:
return V_93 ;
}
void F_87 ( struct V_2 * V_3 )
{
if ( V_3 -> V_1 )
V_3 -> V_16 |= V_118 ;
else
V_3 -> V_16 &= ~ V_118 ;
}
static void F_88 ( void )
{
F_87 ( V_53 ) ;
}
static long F_89 ( unsigned short V_7 , unsigned short V_16 ,
T_1 * V_22 )
{
struct V_1 * V_60 , * V_103 ;
struct V_61 * V_62 = V_53 -> V_62 ;
F_90 ( V_119 ) ;
int V_18 ;
if ( ! V_119 )
return - V_46 ;
V_60 = F_20 ( V_7 , V_16 , V_22 ) ;
if ( F_77 ( V_60 ) ) {
V_18 = F_78 ( V_60 ) ;
goto V_117;
}
if ( V_62 )
F_43 ( & V_62 -> V_65 ) ;
F_91 ( V_53 ) ;
V_18 = F_16 ( V_60 , V_22 , V_119 ) ;
if ( V_18 ) {
F_92 ( V_53 ) ;
if ( V_62 )
F_44 ( & V_62 -> V_65 ) ;
F_79 ( V_60 ) ;
goto V_117;
}
V_103 = V_53 -> V_1 ;
V_53 -> V_1 = V_60 ;
F_88 () ;
if ( V_60 && V_60 -> V_7 == V_120 &&
F_9 ( V_60 -> V_24 . V_22 ) )
V_53 -> V_54 = F_14 ( V_60 -> V_24 . V_22 ) ;
F_92 ( V_53 ) ;
if ( V_62 )
F_44 ( & V_62 -> V_65 ) ;
F_79 ( V_103 ) ;
V_18 = 0 ;
V_117:
F_93 ( V_119 ) ;
return V_18 ;
}
static void F_94 ( struct V_1 * V_3 , T_1 * V_22 )
{
F_95 ( * V_22 ) ;
if ( V_3 == & V_121 )
return;
switch ( V_3 -> V_7 ) {
case V_122 :
case V_120 :
* V_22 = V_3 -> V_24 . V_22 ;
break;
case V_33 :
if ( ! ( V_3 -> V_16 & V_25 ) )
F_96 ( V_3 -> V_24 . V_26 , * V_22 ) ;
break;
default:
F_32 () ;
}
}
static int F_97 ( struct V_61 * V_62 , unsigned long V_70 )
{
struct V_77 * V_3 ;
int V_93 ;
V_93 = F_98 ( V_53 , V_62 , V_70 & V_123 , 1 , 0 , 0 , & V_3 , NULL ) ;
if ( V_93 >= 0 ) {
V_93 = F_51 ( V_3 ) ;
F_99 ( V_3 ) ;
}
return V_93 ;
}
static long F_100 ( int * V_40 , T_1 * V_124 ,
unsigned long V_70 , unsigned long V_16 )
{
int V_93 ;
struct V_61 * V_62 = V_53 -> V_62 ;
struct V_63 * V_64 = NULL ;
struct V_1 * V_4 = V_53 -> V_1 ;
if ( V_16 &
~ ( unsigned long ) ( V_125 | V_126 | V_127 ) )
return - V_23 ;
if ( V_16 & V_127 ) {
if ( V_16 & ( V_125 | V_126 ) )
return - V_23 ;
* V_40 = 0 ;
F_91 ( V_53 ) ;
* V_124 = V_30 ;
F_92 ( V_53 ) ;
return 0 ;
}
if ( V_16 & V_126 ) {
F_101 ( & V_62 -> V_65 ) ;
V_64 = F_102 ( V_62 , V_70 , V_70 + 1 ) ;
if ( ! V_64 ) {
F_103 ( & V_62 -> V_65 ) ;
return - V_96 ;
}
if ( V_64 -> V_105 && V_64 -> V_105 -> V_128 )
V_4 = V_64 -> V_105 -> V_128 ( V_64 , V_70 ) ;
else
V_4 = V_64 -> V_68 ;
} else if ( V_70 )
return - V_23 ;
if ( ! V_4 )
V_4 = & V_121 ;
if ( V_16 & V_125 ) {
if ( V_16 & V_126 ) {
V_93 = F_97 ( V_62 , V_70 ) ;
if ( V_93 < 0 )
goto V_117;
* V_40 = V_93 ;
} else if ( V_4 == V_53 -> V_1 &&
V_4 -> V_7 == V_120 ) {
* V_40 = V_53 -> V_54 ;
} else {
V_93 = - V_23 ;
goto V_117;
}
} else {
* V_40 = V_4 == & V_121 ? V_41 :
V_4 -> V_7 ;
* V_40 |= ( V_4 -> V_16 & V_17 ) ;
}
if ( V_64 ) {
F_103 ( & V_53 -> V_62 -> V_65 ) ;
V_64 = NULL ;
}
V_93 = 0 ;
if ( V_124 ) {
if ( F_6 ( V_4 ) ) {
* V_124 = V_4 -> V_36 . V_37 ;
} else {
F_91 ( V_53 ) ;
F_94 ( V_4 , V_124 ) ;
F_92 ( V_53 ) ;
}
}
V_117:
F_104 ( V_4 ) ;
if ( V_64 )
F_103 ( & V_53 -> V_62 -> V_65 ) ;
return V_93 ;
}
static void F_52 ( struct V_77 * V_77 , struct V_129 * V_130 ,
unsigned long V_16 )
{
if ( ( V_16 & V_81 ) || F_105 ( V_77 ) == 1 ) {
if ( ! F_106 ( V_77 ) ) {
F_107 ( & V_77 -> V_131 , V_130 ) ;
F_108 ( V_77 , V_132 +
F_109 ( V_77 ) ) ;
}
}
}
static struct V_77 * F_110 ( struct V_77 * V_77 , unsigned long V_5 , int * * V_133 )
{
return F_111 ( V_5 , V_134 , 0 ) ;
}
static int F_112 ( struct V_61 * V_62 , int V_135 , int V_136 ,
int V_16 )
{
T_1 V_124 ;
F_113 ( V_130 ) ;
int V_93 = 0 ;
F_95 ( V_124 ) ;
F_96 ( V_135 , V_124 ) ;
F_18 ( ! ( V_16 & ( V_80 | V_81 ) ) ) ;
F_71 ( V_62 , V_62 -> V_66 -> V_97 , V_62 -> V_137 , & V_124 ,
V_16 | V_100 , & V_130 ) ;
if ( ! F_114 ( & V_130 ) ) {
V_93 = F_115 ( & V_130 , F_110 , V_136 ,
false , V_138 ,
V_139 ) ;
if ( V_93 )
F_116 ( & V_130 ) ;
}
return V_93 ;
}
int F_117 ( struct V_61 * V_62 , const T_1 * V_140 ,
const T_1 * V_141 , int V_16 )
{
int V_142 = 0 ;
int V_93 ;
T_1 V_21 ;
V_93 = F_118 () ;
if ( V_93 )
return V_93 ;
F_101 ( & V_62 -> V_65 ) ;
V_93 = F_119 ( V_62 , V_140 , V_141 , V_16 ) ;
if ( V_93 )
goto V_117;
V_21 = * V_140 ;
while ( ! F_12 ( V_21 ) ) {
int V_143 , V_144 ;
int V_135 = - 1 ;
int V_136 = 0 ;
F_4 (s, tmp) {
if ( ( F_9 ( * V_140 ) != F_9 ( * V_141 ) ) &&
( F_34 ( V_143 , * V_141 ) ) )
continue;
V_144 = F_37 ( V_143 , * V_140 , * V_141 ) ;
if ( V_143 == V_144 )
continue;
V_135 = V_143 ;
V_136 = V_144 ;
if ( ! F_34 ( V_136 , V_21 ) )
break;
}
if ( V_135 == - 1 )
break;
F_120 ( V_135 , V_21 ) ;
V_93 = F_112 ( V_62 , V_135 , V_136 , V_16 ) ;
if ( V_93 > 0 )
V_142 += V_93 ;
if ( V_93 < 0 )
break;
}
V_117:
F_103 ( & V_62 -> V_65 ) ;
if ( V_93 < 0 )
return V_93 ;
return V_142 ;
}
static struct V_77 * F_121 ( struct V_77 * V_77 , unsigned long V_72 , int * * V_133 )
{
struct V_63 * V_64 = (struct V_63 * ) V_72 ;
unsigned long V_145 ( V_146 ) ;
while ( V_64 ) {
V_146 = F_122 ( V_77 , V_64 ) ;
if ( V_146 != - V_96 )
break;
V_64 = V_64 -> V_67 ;
}
return F_123 ( V_134 , V_64 , V_146 ) ;
}
static void F_52 ( struct V_77 * V_77 , struct V_129 * V_130 ,
unsigned long V_16 )
{
}
int F_117 ( struct V_61 * V_62 , const T_1 * V_140 ,
const T_1 * V_141 , int V_16 )
{
return - V_147 ;
}
static struct V_77 * F_121 ( struct V_77 * V_77 , unsigned long V_72 , int * * V_133 )
{
return NULL ;
}
static long F_124 ( unsigned long V_92 , unsigned long V_148 ,
unsigned short V_7 , unsigned short V_149 ,
T_1 * V_124 , unsigned long V_16 )
{
struct V_63 * V_64 ;
struct V_61 * V_62 = V_53 -> V_62 ;
struct V_1 * V_60 ;
unsigned long V_71 ;
int V_93 ;
F_113 ( V_130 ) ;
if ( V_16 & ~ ( unsigned long ) V_150 )
return - V_23 ;
if ( ( V_16 & V_81 ) && ! F_125 ( V_151 ) )
return - V_152 ;
if ( V_92 & ~ V_123 )
return - V_23 ;
if ( V_7 == V_41 )
V_16 &= ~ V_102 ;
V_148 = ( V_148 + V_82 - 1 ) & V_123 ;
V_71 = V_92 + V_148 ;
if ( V_71 < V_92 )
return - V_23 ;
if ( V_71 == V_92 )
return 0 ;
V_60 = F_20 ( V_7 , V_149 , V_124 ) ;
if ( F_77 ( V_60 ) )
return F_78 ( V_60 ) ;
if ( V_16 & V_101 )
V_60 -> V_16 |= V_153 ;
if ( ! V_60 )
V_16 |= V_100 ;
F_21 ( L_3 ,
V_92 , V_92 + V_148 , V_7 , V_149 ,
V_124 ? F_22 ( * V_124 ) [ 0 ] : - 1 ) ;
if ( V_16 & ( V_80 | V_81 ) ) {
V_93 = F_118 () ;
if ( V_93 )
goto V_154;
}
{
F_90 ( V_119 ) ;
if ( V_119 ) {
F_43 ( & V_62 -> V_65 ) ;
F_91 ( V_53 ) ;
V_93 = F_16 ( V_60 , V_124 , V_119 ) ;
F_92 ( V_53 ) ;
if ( V_93 )
F_44 ( & V_62 -> V_65 ) ;
} else
V_93 = - V_46 ;
F_93 ( V_119 ) ;
}
if ( V_93 )
goto V_154;
V_64 = F_71 ( V_62 , V_92 , V_71 , V_124 ,
V_16 | V_79 , & V_130 ) ;
V_93 = F_78 ( V_64 ) ;
if ( ! F_77 ( V_64 ) )
V_93 = F_80 ( V_62 , V_92 , V_71 , V_60 ) ;
if ( ! V_93 ) {
int V_155 = 0 ;
if ( ! F_114 ( & V_130 ) ) {
F_126 ( V_16 & V_101 ) ;
V_155 = F_115 ( & V_130 , F_121 ,
( unsigned long ) V_64 ,
false , V_138 ,
V_156 ) ;
if ( V_155 )
F_116 ( & V_130 ) ;
}
if ( V_155 && ( V_16 & V_102 ) )
V_93 = - V_85 ;
} else
F_116 ( & V_130 ) ;
F_44 ( & V_62 -> V_65 ) ;
V_154:
F_79 ( V_60 ) ;
return V_93 ;
}
static int F_127 ( T_1 * V_22 , const unsigned long T_8 * V_124 ,
unsigned long V_157 )
{
unsigned long V_10 ;
unsigned long V_158 ;
unsigned long V_159 ;
-- V_157 ;
F_95 ( * V_22 ) ;
if ( V_157 == 0 || ! V_124 )
return 0 ;
if ( V_157 > V_82 * V_160 )
return - V_23 ;
V_158 = F_128 ( V_157 ) ;
if ( ( V_157 % V_161 ) == 0 )
V_159 = ~ 0UL ;
else
V_159 = ( 1UL << ( V_157 % V_161 ) ) - 1 ;
if ( V_158 > F_128 ( V_55 ) ) {
if ( V_158 > V_82 / sizeof( long ) )
return - V_23 ;
for ( V_10 = F_128 ( V_55 ) ; V_10 < V_158 ; V_10 ++ ) {
unsigned long V_162 ;
if ( F_129 ( V_162 , V_124 + V_10 ) )
return - V_96 ;
if ( V_10 == V_158 - 1 ) {
if ( V_162 & V_159 )
return - V_23 ;
} else if ( V_162 )
return - V_23 ;
}
V_158 = F_128 ( V_55 ) ;
V_159 = ~ 0UL ;
}
if ( F_130 ( F_22 ( * V_22 ) , V_124 , V_158 *sizeof( unsigned long ) ) )
return - V_96 ;
F_22 ( * V_22 ) [ V_158 - 1 ] &= V_159 ;
return 0 ;
}
static int F_131 ( unsigned long T_8 * V_163 , unsigned long V_157 ,
T_1 * V_22 )
{
unsigned long V_164 = F_132 ( V_157 - 1 , 64 ) / 8 ;
const int V_165 = F_128 ( V_55 ) * sizeof( long ) ;
if ( V_164 > V_165 ) {
if ( V_164 > V_82 )
return - V_23 ;
if ( F_133 ( ( char T_8 * ) V_163 + V_165 , V_164 - V_165 ) )
return - V_96 ;
V_164 = V_165 ;
}
return F_134 ( V_163 , F_22 ( * V_22 ) , V_164 ) ? - V_96 : 0 ;
}
T_9 long F_135 ( int T_8 * V_40 ,
T_10 T_8 * V_124 ,
T_10 V_157 ,
T_10 V_70 , T_10 V_16 )
{
long V_93 ;
unsigned long T_8 * V_166 = NULL ;
unsigned long V_167 , V_168 ;
F_136 ( V_169 , V_55 ) ;
V_167 = F_137 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_168 = F_132 ( V_167 , V_161 ) / 8 ;
if ( V_124 )
V_166 = F_138 ( V_168 ) ;
V_93 = F_139 ( V_40 , V_166 , V_167 + 1 , V_70 , V_16 ) ;
if ( ! V_93 && V_124 ) {
unsigned long V_170 ;
V_170 = F_137 (unsigned long, sizeof(bm), alloc_size) ;
V_93 = F_130 ( V_169 , V_166 , V_170 ) ;
V_93 |= F_133 ( V_124 , F_132 ( V_157 - 1 , 8 ) / 8 ) ;
V_93 |= F_140 ( V_124 , V_169 , V_167 ) ;
}
return V_93 ;
}
T_9 long F_141 ( int V_7 , T_10 T_8 * V_124 ,
T_10 V_157 )
{
long V_93 = 0 ;
unsigned long T_8 * V_166 = NULL ;
unsigned long V_167 , V_168 ;
F_136 ( V_169 , V_55 ) ;
V_167 = F_137 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_168 = F_132 ( V_167 , V_161 ) / 8 ;
if ( V_124 ) {
V_93 = F_142 ( V_169 , V_124 , V_167 ) ;
V_166 = F_138 ( V_168 ) ;
V_93 |= F_134 ( V_166 , V_169 , V_168 ) ;
}
if ( V_93 )
return - V_96 ;
return F_143 ( V_7 , V_166 , V_167 + 1 ) ;
}
T_9 long F_144 ( T_10 V_92 , T_10 V_148 ,
T_10 V_7 , T_10 T_8 * V_124 ,
T_10 V_157 , T_10 V_16 )
{
long V_93 = 0 ;
unsigned long T_8 * V_166 = NULL ;
unsigned long V_167 , V_168 ;
T_1 V_169 ;
V_167 = F_137 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_168 = F_132 ( V_167 , V_161 ) / 8 ;
if ( V_124 ) {
V_93 = F_142 ( F_22 ( V_169 ) , V_124 , V_167 ) ;
V_166 = F_138 ( V_168 ) ;
V_93 |= F_134 ( V_166 , F_22 ( V_169 ) , V_168 ) ;
}
if ( V_93 )
return - V_96 ;
return F_145 ( V_92 , V_148 , V_7 , V_166 , V_167 + 1 , V_16 ) ;
}
struct V_1 * F_146 ( struct V_2 * V_171 ,
struct V_63 * V_64 , unsigned long V_70 )
{
struct V_1 * V_4 = F_1 ( V_171 ) ;
if ( V_64 ) {
if ( V_64 -> V_105 && V_64 -> V_105 -> V_128 ) {
struct V_1 * V_172 = V_64 -> V_105 -> V_128 ( V_64 ,
V_70 ) ;
if ( V_172 )
V_4 = V_172 ;
} else if ( V_64 -> V_68 ) {
V_4 = V_64 -> V_68 ;
if ( F_147 ( V_4 ) )
F_148 ( V_4 ) ;
}
}
if ( ! V_4 )
V_4 = & V_121 ;
return V_4 ;
}
static T_1 * F_149 ( T_11 V_173 , struct V_1 * V_40 )
{
if ( F_150 ( V_40 -> V_7 == V_122 ) &&
F_151 ( V_173 ) >= V_13 &&
F_152 ( & V_40 -> V_24 . V_22 ) )
return & V_40 -> V_24 . V_22 ;
return NULL ;
}
static struct V_174 * F_153 ( T_11 V_173 , struct V_1 * V_40 ,
int V_9 )
{
switch ( V_40 -> V_7 ) {
case V_33 :
if ( ! ( V_40 -> V_16 & V_25 ) )
V_9 = V_40 -> V_24 . V_26 ;
break;
case V_122 :
if ( F_150 ( V_173 & V_175 ) &&
F_150 ( ! F_34 ( V_9 , V_40 -> V_24 . V_22 ) ) )
V_9 = F_14 ( V_40 -> V_24 . V_22 ) ;
break;
default:
F_32 () ;
}
return F_154 ( V_9 , V_173 ) ;
}
static unsigned F_155 ( struct V_1 * V_40 )
{
unsigned V_78 , V_84 ;
struct V_2 * V_176 = V_53 ;
V_78 = V_176 -> V_54 ;
V_84 = F_35 ( V_78 , V_40 -> V_24 . V_22 ) ;
if ( V_84 >= V_55 )
V_84 = F_14 ( V_40 -> V_24 . V_22 ) ;
if ( V_84 < V_55 )
V_176 -> V_54 = V_84 ;
return V_78 ;
}
unsigned F_156 ( void )
{
struct V_1 * V_40 ;
if ( F_157 () )
return F_2 () ;
V_40 = V_53 -> V_1 ;
if ( ! V_40 || V_40 -> V_16 & V_25 )
return F_2 () ;
switch ( V_40 -> V_7 ) {
case V_33 :
return V_40 -> V_24 . V_26 ;
case V_120 :
return F_155 ( V_40 ) ;
case V_122 : {
struct V_174 * V_174 ;
struct V_11 * V_11 ;
enum V_177 V_178 = F_151 ( V_45 ) ;
V_174 = & F_5 ( F_2 () ) -> V_179 [ 0 ] ;
( void ) F_158 ( V_174 , V_178 ,
& V_40 -> V_24 . V_22 ,
& V_11 ) ;
return V_11 ? V_11 -> V_5 : F_2 () ;
}
default:
F_32 () ;
}
}
static unsigned F_159 ( struct V_1 * V_4 ,
struct V_63 * V_64 , unsigned long V_180 )
{
unsigned V_181 = F_9 ( V_4 -> V_24 . V_22 ) ;
unsigned V_182 ;
int V_183 ;
int V_78 = - 1 ;
if ( ! V_181 )
return F_2 () ;
V_182 = ( unsigned int ) V_180 % V_181 ;
V_183 = 0 ;
do {
V_78 = F_35 ( V_78 , V_4 -> V_24 . V_22 ) ;
V_183 ++ ;
} while ( V_183 <= V_182 );
return V_78 ;
}
static inline unsigned F_160 ( struct V_1 * V_4 ,
struct V_63 * V_64 , unsigned long V_70 , int V_184 )
{
if ( V_64 ) {
unsigned long V_180 ;
F_161 ( V_184 < V_114 ) ;
V_180 = V_64 -> V_104 >> ( V_184 - V_114 ) ;
V_180 += ( V_70 - V_64 -> V_97 ) >> V_184 ;
return F_159 ( V_4 , V_64 , V_180 ) ;
} else
return F_155 ( V_4 ) ;
}
int F_162 ( const T_1 * V_185 )
{
int V_36 , V_186 = - 1 ;
V_36 = F_9 ( * V_185 ) ;
if ( V_36 )
V_186 = F_163 ( V_185 -> V_187 ,
F_164 () % V_36 , V_55 ) ;
return V_186 ;
}
struct V_174 * F_165 ( struct V_63 * V_64 , unsigned long V_70 ,
T_11 V_188 , struct V_1 * * V_189 ,
T_1 * * V_8 )
{
struct V_174 * V_190 ;
* V_189 = F_146 ( V_53 , V_64 , V_70 ) ;
* V_8 = NULL ;
if ( F_150 ( ( * V_189 ) -> V_7 == V_120 ) ) {
V_190 = F_154 ( F_160 ( * V_189 , V_64 , V_70 ,
F_166 ( F_167 ( V_64 ) ) ) , V_188 ) ;
} else {
V_190 = F_153 ( V_188 , * V_189 , F_2 () ) ;
if ( ( * V_189 ) -> V_7 == V_122 )
* V_8 = & ( * V_189 ) -> V_24 . V_22 ;
}
return V_190 ;
}
bool F_168 ( T_1 * V_163 )
{
struct V_1 * V_1 ;
int V_78 ;
if ( ! ( V_163 && V_53 -> V_1 ) )
return false ;
F_91 ( V_53 ) ;
V_1 = V_53 -> V_1 ;
switch ( V_1 -> V_7 ) {
case V_33 :
if ( V_1 -> V_16 & V_25 )
V_78 = F_2 () ;
else
V_78 = V_1 -> V_24 . V_26 ;
F_169 ( V_163 , V_78 ) ;
break;
case V_122 :
case V_120 :
* V_163 = V_1 -> V_24 . V_22 ;
break;
default:
F_32 () ;
}
F_92 ( V_53 ) ;
return true ;
}
bool F_170 ( struct V_2 * V_59 ,
const T_1 * V_163 )
{
struct V_1 * V_1 ;
bool V_18 = true ;
if ( ! V_163 )
return V_18 ;
F_91 ( V_59 ) ;
V_1 = V_59 -> V_1 ;
if ( ! V_1 )
goto V_117;
switch ( V_1 -> V_7 ) {
case V_33 :
break;
case V_122 :
case V_120 :
V_18 = F_171 ( V_1 -> V_24 . V_22 , * V_163 ) ;
break;
default:
F_32 () ;
}
V_117:
F_92 ( V_59 ) ;
return V_18 ;
}
static struct V_77 * F_172 ( T_11 V_173 , unsigned V_191 ,
unsigned V_78 )
{
struct V_174 * V_190 ;
struct V_77 * V_77 ;
V_190 = F_154 ( V_78 , V_173 ) ;
V_77 = F_173 ( V_173 , V_191 , V_190 ) ;
if ( V_77 && F_174 ( V_77 ) == F_175 ( & V_190 -> V_192 [ 0 ] ) )
F_108 ( V_77 , V_193 ) ;
return V_77 ;
}
struct V_77 *
F_176 ( T_11 V_173 , int V_191 , struct V_63 * V_64 ,
unsigned long V_70 , int V_5 )
{
struct V_1 * V_4 ;
struct V_77 * V_77 ;
unsigned int V_194 ;
V_195:
V_4 = F_146 ( V_53 , V_64 , V_70 ) ;
V_194 = F_177 () ;
if ( F_150 ( V_4 -> V_7 == V_120 ) ) {
unsigned V_78 ;
V_78 = F_160 ( V_4 , V_64 , V_70 , V_114 + V_191 ) ;
F_104 ( V_4 ) ;
V_77 = F_172 ( V_173 , V_191 , V_78 ) ;
if ( F_150 ( ! F_178 ( V_194 ) && ! V_77 ) )
goto V_195;
return V_77 ;
}
V_77 = F_179 ( V_173 , V_191 ,
F_153 ( V_173 , V_4 , V_5 ) ,
F_149 ( V_173 , V_4 ) ) ;
if ( F_150 ( F_147 ( V_4 ) ) )
F_26 ( V_4 ) ;
if ( F_150 ( ! F_178 ( V_194 ) && ! V_77 ) )
goto V_195;
return V_77 ;
}
struct V_77 * F_180 ( T_11 V_173 , unsigned V_191 )
{
struct V_1 * V_4 = F_1 ( V_53 ) ;
struct V_77 * V_77 ;
unsigned int V_194 ;
if ( ! V_4 || F_157 () || ( V_173 & V_175 ) )
V_4 = & V_121 ;
V_195:
V_194 = F_177 () ;
if ( V_4 -> V_7 == V_120 )
V_77 = F_172 ( V_173 , V_191 , F_155 ( V_4 ) ) ;
else
V_77 = F_179 ( V_173 , V_191 ,
F_153 ( V_173 , V_4 , F_2 () ) ,
F_149 ( V_173 , V_4 ) ) ;
if ( F_150 ( ! F_178 ( V_194 ) && ! V_77 ) )
goto V_195;
return V_77 ;
}
struct V_1 * F_181 ( struct V_1 * V_103 )
{
struct V_1 * V_60 = F_24 ( V_44 , V_45 ) ;
if ( ! V_60 )
return F_23 ( - V_46 ) ;
if ( V_103 == V_53 -> V_1 ) {
F_91 ( V_53 ) ;
* V_60 = * V_103 ;
F_92 ( V_53 ) ;
} else
* V_60 = * V_103 ;
F_182 () ;
if ( F_183 () ) {
T_1 V_196 = V_38 ( V_53 ) ;
if ( V_60 -> V_16 & V_57 )
F_38 ( V_60 , & V_196 , V_52 ) ;
else
F_38 ( V_60 , & V_196 , V_50 ) ;
}
F_184 () ;
F_25 ( & V_60 -> V_47 , 1 ) ;
return V_60 ;
}
bool F_185 ( struct V_1 * V_197 , struct V_1 * V_198 )
{
if ( ! V_197 || ! V_198 )
return false ;
if ( V_197 -> V_7 != V_198 -> V_7 )
return false ;
if ( V_197 -> V_16 != V_198 -> V_16 )
return false ;
if ( F_6 ( V_197 ) )
if ( ! F_39 ( V_197 -> V_36 . V_37 , V_198 -> V_36 . V_37 ) )
return false ;
switch ( V_197 -> V_7 ) {
case V_122 :
case V_120 :
return ! ! F_39 ( V_197 -> V_24 . V_22 , V_198 -> V_24 . V_22 ) ;
case V_33 :
return V_197 -> V_24 . V_26 == V_198 -> V_24 . V_26 ;
default:
F_32 () ;
return false ;
}
}
static struct V_199 *
F_186 ( struct V_200 * V_201 , unsigned long V_92 , unsigned long V_71 )
{
struct V_202 * V_203 = V_201 -> V_204 . V_202 ;
while ( V_203 ) {
struct V_199 * V_3 = F_187 ( V_203 , struct V_199 , V_9 ) ;
if ( V_92 >= V_3 -> V_71 )
V_203 = V_203 -> V_205 ;
else if ( V_71 <= V_3 -> V_92 )
V_203 = V_203 -> V_206 ;
else
break;
}
if ( ! V_203 )
return NULL ;
for (; ; ) {
struct V_199 * V_36 = NULL ;
struct V_202 * V_95 = F_188 ( V_203 ) ;
if ( ! V_95 )
break;
V_36 = F_187 ( V_95 , struct V_199 , V_9 ) ;
if ( V_36 -> V_71 <= V_92 )
break;
V_203 = V_95 ;
}
return F_187 ( V_203 , struct V_199 , V_9 ) ;
}
static void F_189 ( struct V_200 * V_201 , struct V_199 * V_60 )
{
struct V_202 * * V_3 = & V_201 -> V_204 . V_202 ;
struct V_202 * V_207 = NULL ;
struct V_199 * V_9 ;
while ( * V_3 ) {
V_207 = * V_3 ;
V_9 = F_187 ( V_207 , struct V_199 , V_9 ) ;
if ( V_60 -> V_92 < V_9 -> V_92 )
V_3 = & ( * V_3 ) -> V_206 ;
else if ( V_60 -> V_71 > V_9 -> V_71 )
V_3 = & ( * V_3 ) -> V_205 ;
else
F_32 () ;
}
F_190 ( & V_60 -> V_9 , V_207 , V_3 ) ;
F_191 ( & V_60 -> V_9 , & V_201 -> V_204 ) ;
F_21 ( L_4 , V_60 -> V_92 , V_60 -> V_71 ,
V_60 -> V_40 ? V_60 -> V_40 -> V_7 : 0 ) ;
}
struct V_1 *
F_192 ( struct V_200 * V_201 , unsigned long V_208 )
{
struct V_1 * V_4 = NULL ;
struct V_199 * V_209 ;
if ( ! V_201 -> V_204 . V_202 )
return NULL ;
F_193 ( & V_201 -> V_210 ) ;
V_209 = F_186 ( V_201 , V_208 , V_208 + 1 ) ;
if ( V_209 ) {
F_148 ( V_209 -> V_40 ) ;
V_4 = V_209 -> V_40 ;
}
F_194 ( & V_201 -> V_210 ) ;
return V_4 ;
}
static void F_195 ( struct V_199 * V_203 )
{
F_79 ( V_203 -> V_40 ) ;
F_28 ( V_211 , V_203 ) ;
}
int F_196 ( struct V_77 * V_77 , struct V_63 * V_64 , unsigned long V_70 )
{
struct V_1 * V_4 ;
struct V_11 * V_11 ;
int V_212 = F_51 ( V_77 ) ;
unsigned long V_110 ;
int V_213 = - 1 ;
int V_18 = - 1 ;
F_161 ( ! V_64 ) ;
V_4 = F_146 ( V_53 , V_64 , V_70 ) ;
if ( ! ( V_4 -> V_16 & V_153 ) )
goto V_117;
switch ( V_4 -> V_7 ) {
case V_120 :
F_161 ( V_70 >= V_64 -> V_99 ) ;
F_161 ( V_70 < V_64 -> V_97 ) ;
V_110 = V_64 -> V_104 ;
V_110 += ( V_70 - V_64 -> V_97 ) >> V_114 ;
V_213 = F_159 ( V_4 , V_64 , V_110 ) ;
break;
case V_33 :
if ( V_4 -> V_16 & V_25 )
V_213 = F_2 () ;
else
V_213 = V_4 -> V_24 . V_26 ;
break;
case V_122 :
if ( F_34 ( V_212 , V_4 -> V_24 . V_22 ) )
goto V_117;
( void ) F_158 (
F_154 ( F_2 () , V_214 ) ,
F_151 ( V_214 ) ,
& V_4 -> V_24 . V_22 , & V_11 ) ;
V_213 = V_11 -> V_5 ;
break;
default:
F_32 () ;
}
if ( V_4 -> V_16 & V_215 ) {
int V_216 ;
V_213 = F_2 () ;
V_216 = F_197 ( V_77 , V_213 ) ;
if ( V_216 != V_213 )
goto V_117;
}
if ( V_212 != V_213 )
V_18 = V_213 ;
V_117:
F_104 ( V_4 ) ;
return V_18 ;
}
static void F_198 ( struct V_200 * V_201 , struct V_199 * V_203 )
{
F_21 ( L_5 , V_203 -> V_92 , V_203 -> V_71 ) ;
F_199 ( & V_203 -> V_9 , & V_201 -> V_204 ) ;
F_195 ( V_203 ) ;
}
static void F_200 ( struct V_199 * V_5 , unsigned long V_92 ,
unsigned long V_71 , struct V_1 * V_4 )
{
V_5 -> V_92 = V_92 ;
V_5 -> V_71 = V_71 ;
V_5 -> V_40 = V_4 ;
}
static struct V_199 * F_201 ( unsigned long V_92 , unsigned long V_71 ,
struct V_1 * V_4 )
{
struct V_199 * V_203 ;
struct V_1 * V_217 ;
V_203 = F_24 ( V_211 , V_45 ) ;
if ( ! V_203 )
return NULL ;
V_217 = F_76 ( V_4 ) ;
if ( F_77 ( V_217 ) ) {
F_28 ( V_211 , V_203 ) ;
return NULL ;
}
V_217 -> V_16 |= V_218 ;
F_200 ( V_203 , V_92 , V_71 , V_217 ) ;
return V_203 ;
}
static int F_202 ( struct V_200 * V_201 , unsigned long V_92 ,
unsigned long V_71 , struct V_199 * V_60 )
{
struct V_199 * V_203 ;
struct V_199 * V_219 = NULL ;
struct V_1 * F_20 = NULL ;
int V_18 = 0 ;
V_220:
F_193 ( & V_201 -> V_210 ) ;
V_203 = F_186 ( V_201 , V_92 , V_71 ) ;
while ( V_203 && V_203 -> V_92 < V_71 ) {
struct V_202 * V_84 = F_203 ( & V_203 -> V_9 ) ;
if ( V_203 -> V_92 >= V_92 ) {
if ( V_203 -> V_71 <= V_71 )
F_198 ( V_201 , V_203 ) ;
else
V_203 -> V_92 = V_71 ;
} else {
if ( V_203 -> V_71 > V_71 ) {
if ( ! V_219 )
goto V_221;
* F_20 = * V_203 -> V_40 ;
F_25 ( & F_20 -> V_47 , 1 ) ;
F_200 ( V_219 , V_203 -> V_71 , V_71 , F_20 ) ;
F_189 ( V_201 , V_219 ) ;
V_203 -> V_71 = V_92 ;
V_219 = NULL ;
F_20 = NULL ;
break;
} else
V_203 -> V_71 = V_92 ;
}
if ( ! V_84 )
break;
V_203 = F_187 ( V_84 , struct V_199 , V_9 ) ;
}
if ( V_60 )
F_189 ( V_201 , V_60 ) ;
F_194 ( & V_201 -> V_210 ) ;
V_18 = 0 ;
V_108:
if ( F_20 )
F_79 ( F_20 ) ;
if ( V_219 )
F_28 ( V_211 , V_219 ) ;
return V_18 ;
V_221:
F_194 ( & V_201 -> V_210 ) ;
V_18 = - V_46 ;
V_219 = F_24 ( V_211 , V_45 ) ;
if ( ! V_219 )
goto V_108;
F_20 = F_24 ( V_44 , V_45 ) ;
if ( ! F_20 )
goto V_108;
goto V_220;
}
void F_204 ( struct V_200 * V_201 , struct V_1 * V_189 )
{
int V_18 ;
V_201 -> V_204 = V_222 ;
F_205 ( & V_201 -> V_210 ) ;
if ( V_189 ) {
struct V_63 V_223 ;
struct V_1 * V_60 ;
F_90 ( V_119 ) ;
if ( ! V_119 )
goto V_224;
V_60 = F_20 ( V_189 -> V_7 , V_189 -> V_16 , & V_189 -> V_36 . V_37 ) ;
if ( F_77 ( V_60 ) )
goto V_225;
F_91 ( V_53 ) ;
V_18 = F_16 ( V_60 , & V_189 -> V_36 . V_37 , V_119 ) ;
F_92 ( V_53 ) ;
if ( V_18 )
goto V_226;
memset ( & V_223 , 0 , sizeof( struct V_63 ) ) ;
V_223 . V_99 = V_227 ;
F_206 ( V_201 , & V_223 , V_60 ) ;
V_226:
F_79 ( V_60 ) ;
V_225:
F_93 ( V_119 ) ;
V_224:
F_79 ( V_189 ) ;
}
}
int F_206 ( struct V_200 * V_228 ,
struct V_63 * V_64 , struct V_1 * V_229 )
{
int V_93 ;
struct V_199 * V_60 = NULL ;
unsigned long V_230 = F_207 ( V_64 ) ;
F_21 ( L_6 ,
V_64 -> V_104 ,
V_230 , V_229 ? V_229 -> V_7 : - 1 ,
V_229 ? V_229 -> V_16 : - 1 ,
V_229 ? F_22 ( V_229 -> V_24 . V_22 ) [ 0 ] : - 1 ) ;
if ( V_229 ) {
V_60 = F_201 ( V_64 -> V_104 , V_64 -> V_104 + V_230 , V_229 ) ;
if ( ! V_60 )
return - V_46 ;
}
V_93 = F_202 ( V_228 , V_64 -> V_104 , V_64 -> V_104 + V_230 , V_60 ) ;
if ( V_93 && V_60 )
F_195 ( V_60 ) ;
return V_93 ;
}
void F_208 ( struct V_200 * V_3 )
{
struct V_199 * V_203 ;
struct V_202 * V_84 ;
if ( ! V_3 -> V_204 . V_202 )
return;
F_193 ( & V_3 -> V_210 ) ;
V_84 = F_209 ( & V_3 -> V_204 ) ;
while ( V_84 ) {
V_203 = F_187 ( V_84 , struct V_199 , V_9 ) ;
V_84 = F_203 ( & V_203 -> V_9 ) ;
F_198 ( V_3 , V_203 ) ;
}
F_194 ( & V_3 -> V_210 ) ;
}
static void T_12 F_210 ( void )
{
bool V_231 = false ;
if ( F_211 ( V_232 ) )
V_231 = true ;
if ( V_233 > 1 && ! V_234 ) {
F_212 ( V_235 L_7
L_8 ) ;
F_213 ( V_231 ) ;
}
}
static int T_12 F_214 ( char * V_236 )
{
int V_18 = 0 ;
if ( ! V_236 )
goto V_117;
V_234 = true ;
if ( ! strcmp ( V_236 , L_9 ) ) {
F_213 ( true ) ;
V_18 = 1 ;
} else if ( ! strcmp ( V_236 , L_10 ) ) {
F_213 ( false ) ;
V_18 = 1 ;
}
V_117:
if ( ! V_18 )
F_212 ( V_237 L_11 ) ;
return V_18 ;
}
static inline void T_12 F_210 ( void )
{
}
void T_12 F_215 ( void )
{
T_1 F_155 ;
unsigned long V_238 = 0 ;
int V_78 , V_239 = 0 ;
V_44 = F_216 ( L_12 ,
sizeof( struct V_1 ) ,
0 , V_240 , NULL ) ;
V_211 = F_216 ( L_13 ,
sizeof( struct V_199 ) ,
0 , V_240 , NULL ) ;
F_217 (nid) {
V_6 [ V_78 ] = (struct V_1 ) {
. V_47 = F_218 ( 1 ) ,
. V_7 = V_33 ,
. V_16 = V_153 | V_215 ,
. V_24 = { . V_26 = V_78 , } ,
} ;
}
F_95 ( F_155 ) ;
F_219 (nid, N_MEMORY) {
unsigned long V_241 = F_220 ( V_78 ) ;
if ( V_238 < V_241 ) {
V_238 = V_241 ;
V_239 = V_78 ;
}
if ( ( V_241 << V_114 ) >= ( 16 << 20 ) )
F_96 ( V_78 , F_155 ) ;
}
if ( F_150 ( F_12 ( F_155 ) ) )
F_96 ( V_239 , F_155 ) ;
if ( F_89 ( V_120 , 0 , & F_155 ) )
F_212 ( L_14 ) ;
F_210 () ;
}
void F_221 ( void )
{
F_89 ( V_41 , 0 , NULL ) ;
}
int F_222 ( char * V_236 , struct V_1 * * V_189 )
{
struct V_1 * V_60 = NULL ;
unsigned short V_7 ;
unsigned short V_149 ;
T_1 V_22 ;
char * V_242 = strchr ( V_236 , ':' ) ;
char * V_16 = strchr ( V_236 , '=' ) ;
int V_93 = 1 ;
if ( V_242 ) {
* V_242 ++ = '\0' ;
if ( F_223 ( V_242 , V_22 ) )
goto V_117;
if ( ! F_224 ( V_22 , V_31 [ V_32 ] ) )
goto V_117;
} else
F_95 ( V_22 ) ;
if ( V_16 )
* V_16 ++ = '\0' ;
for ( V_7 = 0 ; V_7 < V_243 ; V_7 ++ ) {
if ( ! strcmp ( V_236 , V_244 [ V_7 ] ) ) {
break;
}
}
if ( V_7 >= V_243 )
goto V_117;
switch ( V_7 ) {
case V_33 :
if ( V_242 ) {
char * V_245 = V_242 ;
while ( isdigit ( * V_245 ) )
V_245 ++ ;
if ( * V_245 )
goto V_117;
}
break;
case V_120 :
if ( ! V_242 )
V_22 = V_31 [ V_32 ] ;
break;
case V_43 :
if ( V_242 )
goto V_117;
V_7 = V_33 ;
break;
case V_41 :
if ( ! V_242 )
V_93 = 0 ;
goto V_117;
case V_122 :
if ( ! V_242 )
goto V_117;
}
V_149 = 0 ;
if ( V_16 ) {
if ( ! strcmp ( V_16 , L_15 ) )
V_149 |= V_42 ;
else if ( ! strcmp ( V_16 , L_16 ) )
V_149 |= V_34 ;
else
goto V_117;
}
V_60 = F_20 ( V_7 , V_149 , & V_22 ) ;
if ( F_77 ( V_60 ) )
goto V_117;
if ( V_7 != V_33 )
V_60 -> V_24 . V_22 = V_22 ;
else if ( V_242 )
V_60 -> V_24 . V_26 = F_14 ( V_22 ) ;
else
V_60 -> V_16 |= V_25 ;
V_60 -> V_36 . V_37 = V_22 ;
V_93 = 0 ;
V_117:
if ( V_242 )
* -- V_242 = ':' ;
if ( V_16 )
* -- V_16 = '=' ;
if ( ! V_93 )
* V_189 = V_60 ;
return V_93 ;
}
int F_225 ( char * V_246 , int V_247 , struct V_1 * V_4 )
{
char * V_3 = V_246 ;
int V_248 ;
T_1 V_22 ;
unsigned short V_7 ;
unsigned short V_16 = V_4 ? V_4 -> V_16 : 0 ;
F_18 ( V_247 < strlen ( L_17 ) + strlen ( L_16 ) + 16 ) ;
if ( ! V_4 || V_4 == & V_121 )
V_7 = V_41 ;
else
V_7 = V_4 -> V_7 ;
switch ( V_7 ) {
case V_41 :
F_95 ( V_22 ) ;
break;
case V_33 :
F_95 ( V_22 ) ;
if ( V_16 & V_25 )
V_7 = V_43 ;
else
F_96 ( V_4 -> V_24 . V_26 , V_22 ) ;
break;
case V_122 :
case V_120 :
V_22 = V_4 -> V_24 . V_22 ;
break;
default:
return - V_23 ;
}
V_248 = strlen ( V_244 [ V_7 ] ) ;
if ( V_246 + V_247 < V_3 + V_248 + 1 )
return - V_249 ;
strcpy ( V_3 , V_244 [ V_7 ] ) ;
V_3 += V_248 ;
if ( V_16 & V_17 ) {
if ( V_246 + V_247 < V_3 + 2 )
return - V_249 ;
* V_3 ++ = '=' ;
if ( V_16 & V_42 )
V_3 += snprintf ( V_3 , V_246 + V_247 - V_3 , L_15 ) ;
else if ( V_16 & V_34 )
V_3 += snprintf ( V_3 , V_246 + V_247 - V_3 , L_16 ) ;
}
if ( ! F_12 ( V_22 ) ) {
if ( V_246 + V_247 < V_3 + 2 )
return - V_249 ;
* V_3 ++ = ':' ;
V_3 += F_226 ( V_3 , V_246 + V_247 - V_3 , V_22 ) ;
}
return V_3 - V_246 ;
}
