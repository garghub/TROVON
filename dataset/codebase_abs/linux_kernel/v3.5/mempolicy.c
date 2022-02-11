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
static int F_70 ( struct V_59 * V_60 , unsigned long V_85 ,
unsigned long V_69 , struct V_9 * V_95 )
{
struct V_61 * V_82 ;
struct V_61 * V_88 ;
struct V_61 * V_62 ;
int V_86 = 0 ;
T_7 V_96 ;
unsigned long V_97 ;
unsigned long V_98 ;
V_62 = F_67 ( V_60 , V_85 ) ;
if ( ! V_62 || V_62 -> V_90 > V_85 )
return - V_89 ;
V_88 = V_62 -> V_99 ;
if ( V_85 > V_62 -> V_90 )
V_88 = V_62 ;
for (; V_62 && V_62 -> V_90 < V_69 ; V_88 = V_62 , V_62 = V_82 ) {
V_82 = V_62 -> V_65 ;
V_97 = F_71 ( V_85 , V_62 -> V_90 ) ;
V_98 = F_72 ( V_69 , V_62 -> V_92 ) ;
if ( F_73 ( F_74 ( V_62 ) , V_95 ) )
continue;
V_96 = V_62 -> V_100 +
( ( V_97 - V_62 -> V_90 ) >> V_101 ) ;
V_88 = F_75 ( V_60 , V_88 , V_97 , V_98 , V_62 -> V_102 ,
V_62 -> V_103 , V_62 -> V_104 , V_96 ,
V_95 ) ;
if ( V_88 ) {
V_62 = V_88 ;
V_82 = V_62 -> V_65 ;
continue;
}
if ( V_62 -> V_90 != V_97 ) {
V_86 = F_76 ( V_62 -> V_74 , V_62 , V_97 , 1 ) ;
if ( V_86 )
goto V_105;
}
if ( V_62 -> V_92 != V_98 ) {
V_86 = F_76 ( V_62 -> V_74 , V_62 , V_98 , 0 ) ;
if ( V_86 )
goto V_105;
}
F_19 ( L_2 ,
V_62 -> V_90 , V_62 -> V_92 , V_62 -> V_100 ,
V_62 -> V_106 , V_62 -> V_104 ,
V_62 -> V_106 ? V_62 -> V_106 -> V_107 : NULL ) ;
if ( V_62 -> V_106 && V_62 -> V_106 -> V_107 ) {
V_86 = V_62 -> V_106 -> V_107 ( V_62 , V_95 ) ;
if ( V_86 )
goto V_105;
}
}
V_105:
return V_86 ;
}
void F_77 ( struct V_56 * V_43 )
{
if ( V_43 -> V_9 )
V_43 -> V_11 |= V_108 ;
else
V_43 -> V_11 &= ~ V_108 ;
}
static void F_78 ( void )
{
F_77 ( V_49 ) ;
}
static long F_79 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_58 , * V_109 ;
struct V_59 * V_60 = V_49 -> V_60 ;
F_80 ( V_110 ) ;
int V_13 ;
if ( ! V_110 )
return - V_41 ;
V_58 = F_18 ( V_28 , V_11 , V_17 ) ;
if ( F_81 ( V_58 ) ) {
V_13 = F_82 ( V_58 ) ;
goto V_105;
}
if ( V_60 )
F_42 ( & V_60 -> V_63 ) ;
F_83 ( V_49 ) ;
V_13 = F_14 ( V_58 , V_17 , V_110 ) ;
if ( V_13 ) {
F_84 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_85 ( V_58 ) ;
goto V_105;
}
V_109 = V_49 -> V_9 ;
V_49 -> V_9 = V_58 ;
F_78 () ;
if ( V_58 && V_58 -> V_28 == V_111 &&
F_7 ( V_58 -> V_19 . V_17 ) )
V_49 -> V_50 = F_12 ( V_58 -> V_19 . V_17 ) ;
F_84 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_85 ( V_109 ) ;
V_13 = 0 ;
V_105:
F_86 ( V_110 ) ;
return V_13 ;
}
static void F_87 ( struct V_9 * V_43 , T_1 * V_17 )
{
F_88 ( * V_17 ) ;
if ( V_43 == & V_112 )
return;
switch ( V_43 -> V_28 ) {
case V_113 :
case V_111 :
* V_17 = V_43 -> V_19 . V_17 ;
break;
case V_29 :
if ( ! ( V_43 -> V_11 & V_20 ) )
F_89 ( V_43 -> V_19 . V_21 , * V_17 ) ;
break;
default:
F_30 () ;
}
}
static int F_90 ( struct V_59 * V_60 , unsigned long V_68 )
{
struct V_75 * V_43 ;
int V_86 ;
V_86 = F_91 ( V_49 , V_60 , V_68 & V_114 , 1 , 0 , 0 , & V_43 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_50 ( V_43 ) ;
F_92 ( V_43 ) ;
}
return V_86 ;
}
static long F_93 ( int * V_36 , T_1 * V_115 ,
unsigned long V_68 , unsigned long V_11 )
{
int V_86 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_61 * V_62 = NULL ;
struct V_9 * V_10 = V_49 -> V_9 ;
if ( V_11 &
~ ( unsigned long ) ( V_116 | V_117 | V_118 ) )
return - V_18 ;
if ( V_11 & V_118 ) {
if ( V_11 & ( V_116 | V_117 ) )
return - V_18 ;
* V_36 = 0 ;
F_83 ( V_49 ) ;
* V_115 = V_25 ;
F_84 ( V_49 ) ;
return 0 ;
}
if ( V_11 & V_117 ) {
F_94 ( & V_60 -> V_63 ) ;
V_62 = F_95 ( V_60 , V_68 , V_68 + 1 ) ;
if ( ! V_62 ) {
F_96 ( & V_60 -> V_63 ) ;
return - V_89 ;
}
if ( V_62 -> V_106 && V_62 -> V_106 -> V_119 )
V_10 = V_62 -> V_106 -> V_119 ( V_62 , V_68 ) ;
else
V_10 = V_62 -> V_66 ;
} else if ( V_68 )
return - V_18 ;
if ( ! V_10 )
V_10 = & V_112 ;
if ( V_11 & V_116 ) {
if ( V_11 & V_117 ) {
V_86 = F_90 ( V_60 , V_68 ) ;
if ( V_86 < 0 )
goto V_105;
* V_36 = V_86 ;
} else if ( V_10 == V_49 -> V_9 &&
V_10 -> V_28 == V_111 ) {
* V_36 = V_49 -> V_50 ;
} else {
V_86 = - V_18 ;
goto V_105;
}
} else {
* V_36 = V_10 == & V_112 ? V_37 :
V_10 -> V_28 ;
* V_36 |= ( V_10 -> V_11 & V_12 ) ;
}
if ( V_62 ) {
F_96 ( & V_49 -> V_60 -> V_63 ) ;
V_62 = NULL ;
}
V_86 = 0 ;
if ( V_115 ) {
if ( F_4 ( V_10 ) ) {
* V_115 = V_10 -> V_32 . V_33 ;
} else {
F_83 ( V_49 ) ;
F_87 ( V_10 , V_115 ) ;
F_84 ( V_49 ) ;
}
}
V_105:
F_97 ( V_10 ) ;
if ( V_62 )
F_96 ( & V_49 -> V_60 -> V_63 ) ;
return V_86 ;
}
static void F_51 ( struct V_75 * V_75 , struct V_120 * V_121 ,
unsigned long V_11 )
{
if ( ( V_11 & V_79 ) || F_98 ( V_75 ) == 1 ) {
if ( ! F_99 ( V_75 ) ) {
F_100 ( & V_75 -> V_122 , V_121 ) ;
F_101 ( V_75 , V_123 +
F_102 ( V_75 ) ) ;
}
}
}
static struct V_75 * F_103 ( struct V_75 * V_75 , unsigned long V_52 , int * * V_124 )
{
return F_104 ( V_52 , V_125 , 0 ) ;
}
static int F_105 ( struct V_59 * V_60 , int V_126 , int V_127 ,
int V_11 )
{
T_1 V_115 ;
F_106 ( V_121 ) ;
int V_86 = 0 ;
struct V_61 * V_62 ;
F_88 ( V_115 ) ;
F_89 ( V_126 , V_115 ) ;
V_62 = F_66 ( V_60 , V_60 -> V_64 -> V_90 , V_60 -> V_128 , & V_115 ,
V_11 | V_91 , & V_121 ) ;
if ( F_81 ( V_62 ) )
return F_82 ( V_62 ) ;
if ( ! F_107 ( & V_121 ) ) {
V_86 = F_108 ( & V_121 , F_103 , V_127 ,
false , V_129 ) ;
if ( V_86 )
F_109 ( & V_121 ) ;
}
return V_86 ;
}
int F_110 ( struct V_59 * V_60 , const T_1 * V_130 ,
const T_1 * V_131 , int V_11 )
{
int V_132 = 0 ;
int V_86 ;
T_1 V_16 ;
V_86 = F_111 () ;
if ( V_86 )
return V_86 ;
F_94 ( & V_60 -> V_63 ) ;
V_86 = F_112 ( V_60 , V_130 , V_131 , V_11 ) ;
if ( V_86 )
goto V_105;
V_16 = * V_130 ;
while ( ! F_10 ( V_16 ) ) {
int V_133 , V_134 ;
int V_126 = - 1 ;
int V_127 = 0 ;
F_2 (s, tmp) {
if ( ( F_7 ( * V_130 ) != F_7 ( * V_131 ) ) &&
( F_32 ( V_133 , * V_131 ) ) )
continue;
V_134 = F_36 ( V_133 , * V_130 , * V_131 ) ;
if ( V_133 == V_134 )
continue;
V_126 = V_133 ;
V_127 = V_134 ;
if ( ! F_32 ( V_127 , V_16 ) )
break;
}
if ( V_126 == - 1 )
break;
F_113 ( V_126 , V_16 ) ;
V_86 = F_105 ( V_60 , V_126 , V_127 , V_11 ) ;
if ( V_86 > 0 )
V_132 += V_86 ;
if ( V_86 < 0 )
break;
}
V_105:
F_96 ( & V_60 -> V_63 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_132 ;
}
static struct V_75 * F_114 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_124 )
{
struct V_61 * V_62 = (struct V_61 * ) V_70 ;
unsigned long V_135 ( V_136 ) ;
while ( V_62 ) {
V_136 = F_115 ( V_75 , V_62 ) ;
if ( V_136 != - V_89 )
break;
V_62 = V_62 -> V_65 ;
}
return F_116 ( V_125 , V_62 , V_136 ) ;
}
static void F_51 ( struct V_75 * V_75 , struct V_120 * V_121 ,
unsigned long V_11 )
{
}
int F_110 ( struct V_59 * V_60 , const T_1 * V_130 ,
const T_1 * V_131 , int V_11 )
{
return - V_137 ;
}
static struct V_75 * F_114 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_124 )
{
return NULL ;
}
static long F_117 ( unsigned long V_85 , unsigned long V_138 ,
unsigned short V_28 , unsigned short V_139 ,
T_1 * V_115 , unsigned long V_11 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_9 * V_58 ;
unsigned long V_69 ;
int V_86 ;
F_106 ( V_121 ) ;
if ( V_11 & ~ ( unsigned long ) ( V_93 |
V_78 | V_79 ) )
return - V_18 ;
if ( ( V_11 & V_79 ) && ! F_118 ( V_140 ) )
return - V_141 ;
if ( V_85 & ~ V_114 )
return - V_18 ;
if ( V_28 == V_37 )
V_11 &= ~ V_93 ;
V_138 = ( V_138 + V_80 - 1 ) & V_114 ;
V_69 = V_85 + V_138 ;
if ( V_69 < V_85 )
return - V_18 ;
if ( V_69 == V_85 )
return 0 ;
V_58 = F_18 ( V_28 , V_139 , V_115 ) ;
if ( F_81 ( V_58 ) )
return F_82 ( V_58 ) ;
if ( ! V_58 )
V_11 |= V_91 ;
F_19 ( L_3 ,
V_85 , V_85 + V_138 , V_28 , V_139 ,
V_115 ? F_20 ( * V_115 ) [ 0 ] : - 1 ) ;
if ( V_11 & ( V_78 | V_79 ) ) {
V_86 = F_111 () ;
if ( V_86 )
goto V_142;
}
{
F_80 ( V_110 ) ;
if ( V_110 ) {
F_42 ( & V_60 -> V_63 ) ;
F_83 ( V_49 ) ;
V_86 = F_14 ( V_58 , V_115 , V_110 ) ;
F_84 ( V_49 ) ;
if ( V_86 )
F_43 ( & V_60 -> V_63 ) ;
} else
V_86 = - V_41 ;
F_86 ( V_110 ) ;
}
if ( V_86 )
goto V_142;
V_62 = F_66 ( V_60 , V_85 , V_69 , V_115 ,
V_11 | V_77 , & V_121 ) ;
V_86 = F_82 ( V_62 ) ;
if ( ! F_81 ( V_62 ) ) {
int V_143 = 0 ;
V_86 = F_70 ( V_60 , V_85 , V_69 , V_58 ) ;
if ( ! F_107 ( & V_121 ) ) {
V_143 = F_108 ( & V_121 , F_114 ,
( unsigned long ) V_62 ,
false , V_129 ) ;
if ( V_143 )
F_109 ( & V_121 ) ;
}
if ( ! V_86 && V_143 && ( V_11 & V_93 ) )
V_86 = - V_83 ;
} else
F_109 ( & V_121 ) ;
F_43 ( & V_60 -> V_63 ) ;
V_142:
F_85 ( V_58 ) ;
return V_86 ;
}
static int F_119 ( T_1 * V_17 , const unsigned long T_8 * V_115 ,
unsigned long V_144 )
{
unsigned long V_3 ;
unsigned long V_145 ;
unsigned long V_146 ;
-- V_144 ;
F_88 ( * V_17 ) ;
if ( V_144 == 0 || ! V_115 )
return 0 ;
if ( V_144 > V_80 * V_147 )
return - V_18 ;
V_145 = F_120 ( V_144 ) ;
if ( ( V_144 % V_148 ) == 0 )
V_146 = ~ 0UL ;
else
V_146 = ( 1UL << ( V_144 % V_148 ) ) - 1 ;
if ( V_145 > F_120 ( V_51 ) ) {
if ( V_145 > V_80 / sizeof( long ) )
return - V_18 ;
for ( V_3 = F_120 ( V_51 ) ; V_3 < V_145 ; V_3 ++ ) {
unsigned long V_149 ;
if ( F_121 ( V_149 , V_115 + V_3 ) )
return - V_89 ;
if ( V_3 == V_145 - 1 ) {
if ( V_149 & V_146 )
return - V_18 ;
} else if ( V_149 )
return - V_18 ;
}
V_145 = F_120 ( V_51 ) ;
V_146 = ~ 0UL ;
}
if ( F_122 ( F_20 ( * V_17 ) , V_115 , V_145 *sizeof( unsigned long ) ) )
return - V_89 ;
F_20 ( * V_17 ) [ V_145 - 1 ] &= V_146 ;
return 0 ;
}
static int F_123 ( unsigned long T_8 * V_150 , unsigned long V_144 ,
T_1 * V_17 )
{
unsigned long V_151 = F_124 ( V_144 - 1 , 64 ) / 8 ;
const int V_152 = F_120 ( V_51 ) * sizeof( long ) ;
if ( V_151 > V_152 ) {
if ( V_151 > V_80 )
return - V_18 ;
if ( F_125 ( ( char T_8 * ) V_150 + V_152 , V_151 - V_152 ) )
return - V_89 ;
V_151 = V_152 ;
}
return F_126 ( V_150 , F_20 ( * V_17 ) , V_151 ) ? - V_89 : 0 ;
}
T_9 long F_127 ( int T_8 * V_36 ,
T_10 T_8 * V_115 ,
T_10 V_144 ,
T_10 V_68 , T_10 V_11 )
{
long V_86 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
F_128 ( V_156 , V_51 ) ;
V_154 = F_129 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_124 ( V_154 , V_148 ) / 8 ;
if ( V_115 )
V_153 = F_130 ( V_155 ) ;
V_86 = F_131 ( V_36 , V_153 , V_154 + 1 , V_68 , V_11 ) ;
if ( ! V_86 && V_115 ) {
unsigned long V_157 ;
V_157 = F_129 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_122 ( V_156 , V_153 , V_157 ) ;
V_86 |= F_125 ( V_115 , F_124 ( V_144 - 1 , 8 ) / 8 ) ;
V_86 |= F_132 ( V_115 , V_156 , V_154 ) ;
}
return V_86 ;
}
T_9 long F_133 ( int V_28 , T_10 T_8 * V_115 ,
T_10 V_144 )
{
long V_86 = 0 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
F_128 ( V_156 , V_51 ) ;
V_154 = F_129 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_124 ( V_154 , V_148 ) / 8 ;
if ( V_115 ) {
V_86 = F_134 ( V_156 , V_115 , V_154 ) ;
V_153 = F_130 ( V_155 ) ;
V_86 |= F_126 ( V_153 , V_156 , V_155 ) ;
}
if ( V_86 )
return - V_89 ;
return F_135 ( V_28 , V_153 , V_154 + 1 ) ;
}
T_9 long F_136 ( T_10 V_85 , T_10 V_138 ,
T_10 V_28 , T_10 T_8 * V_115 ,
T_10 V_144 , T_10 V_11 )
{
long V_86 = 0 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
T_1 V_156 ;
V_154 = F_129 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_124 ( V_154 , V_148 ) / 8 ;
if ( V_115 ) {
V_86 = F_134 ( F_20 ( V_156 ) , V_115 , V_154 ) ;
V_153 = F_130 ( V_155 ) ;
V_86 |= F_126 ( V_153 , F_20 ( V_156 ) , V_155 ) ;
}
if ( V_86 )
return - V_89 ;
return F_137 ( V_85 , V_138 , V_28 , V_153 , V_154 + 1 , V_11 ) ;
}
struct V_9 * F_138 ( struct V_56 * V_158 ,
struct V_61 * V_62 , unsigned long V_68 )
{
struct V_9 * V_10 = V_158 -> V_9 ;
if ( V_62 ) {
if ( V_62 -> V_106 && V_62 -> V_106 -> V_119 ) {
struct V_9 * V_159 = V_62 -> V_106 -> V_119 ( V_62 ,
V_68 ) ;
if ( V_159 )
V_10 = V_159 ;
} else if ( V_62 -> V_66 )
V_10 = V_62 -> V_66 ;
}
if ( ! V_10 )
V_10 = & V_112 ;
return V_10 ;
}
static T_1 * F_139 ( T_11 V_160 , struct V_9 * V_36 )
{
if ( F_140 ( V_36 -> V_28 == V_113 ) &&
F_141 ( V_160 ) >= V_6 &&
F_142 ( & V_36 -> V_19 . V_17 ) )
return & V_36 -> V_19 . V_17 ;
return NULL ;
}
static struct V_161 * F_143 ( T_11 V_160 , struct V_9 * V_36 ,
int V_2 )
{
switch ( V_36 -> V_28 ) {
case V_29 :
if ( ! ( V_36 -> V_11 & V_20 ) )
V_2 = V_36 -> V_19 . V_21 ;
break;
case V_113 :
if ( F_140 ( V_160 & V_162 ) &&
F_140 ( ! F_32 ( V_2 , V_36 -> V_19 . V_17 ) ) )
V_2 = F_12 ( V_36 -> V_19 . V_17 ) ;
break;
default:
F_30 () ;
}
return F_144 ( V_2 , V_160 ) ;
}
static unsigned F_145 ( struct V_9 * V_36 )
{
unsigned V_76 , V_82 ;
struct V_56 * V_163 = V_49 ;
V_76 = V_163 -> V_50 ;
V_82 = F_33 ( V_76 , V_36 -> V_19 . V_17 ) ;
if ( V_82 >= V_51 )
V_82 = F_12 ( V_36 -> V_19 . V_17 ) ;
if ( V_82 < V_51 )
V_163 -> V_50 = V_82 ;
return V_76 ;
}
unsigned F_146 ( struct V_9 * V_36 )
{
if ( ! V_36 || V_36 -> V_11 & V_20 )
return F_34 () ;
switch ( V_36 -> V_28 ) {
case V_29 :
return V_36 -> V_19 . V_21 ;
case V_111 :
return F_145 ( V_36 ) ;
case V_113 : {
struct V_161 * V_161 ;
struct V_4 * V_4 ;
enum V_164 V_165 = F_141 ( V_40 ) ;
V_161 = & F_3 ( F_34 () ) -> V_166 [ 0 ] ;
( void ) F_147 ( V_161 , V_165 ,
& V_36 -> V_19 . V_17 ,
& V_4 ) ;
return V_4 ? V_4 -> V_52 : F_34 () ;
}
default:
F_30 () ;
}
}
static unsigned F_148 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_167 )
{
unsigned V_168 = F_7 ( V_10 -> V_19 . V_17 ) ;
unsigned V_169 ;
int V_170 ;
int V_76 = - 1 ;
if ( ! V_168 )
return F_34 () ;
V_169 = ( unsigned int ) V_167 % V_168 ;
V_170 = 0 ;
do {
V_76 = F_33 ( V_76 , V_10 -> V_19 . V_17 ) ;
V_170 ++ ;
} while ( V_170 <= V_169 );
return V_76 ;
}
static inline unsigned F_149 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_68 , int V_171 )
{
if ( V_62 ) {
unsigned long V_167 ;
F_150 ( V_171 < V_101 ) ;
V_167 = V_62 -> V_100 >> ( V_171 - V_101 ) ;
V_167 += ( V_68 - V_62 -> V_90 ) >> V_171 ;
return F_148 ( V_10 , V_62 , V_167 ) ;
} else
return F_145 ( V_10 ) ;
}
int F_151 ( const T_1 * V_172 )
{
int V_32 , V_173 = - 1 ;
V_32 = F_7 ( * V_172 ) ;
if ( V_32 )
V_173 = F_152 ( V_172 -> V_174 ,
F_153 () % V_32 , V_51 ) ;
return V_173 ;
}
struct V_161 * F_154 ( struct V_61 * V_62 , unsigned long V_68 ,
T_11 V_175 , struct V_9 * * V_176 ,
T_1 * * V_1 )
{
struct V_161 * V_177 ;
* V_176 = F_138 ( V_49 , V_62 , V_68 ) ;
* V_1 = NULL ;
if ( F_140 ( ( * V_176 ) -> V_28 == V_111 ) ) {
V_177 = F_144 ( F_149 ( * V_176 , V_62 , V_68 ,
F_155 ( F_156 ( V_62 ) ) ) , V_175 ) ;
} else {
V_177 = F_143 ( V_175 , * V_176 , F_34 () ) ;
if ( ( * V_176 ) -> V_28 == V_113 )
* V_1 = & ( * V_176 ) -> V_19 . V_17 ;
}
return V_177 ;
}
bool F_157 ( T_1 * V_150 )
{
struct V_9 * V_9 ;
int V_76 ;
if ( ! ( V_150 && V_49 -> V_9 ) )
return false ;
F_83 ( V_49 ) ;
V_9 = V_49 -> V_9 ;
switch ( V_9 -> V_28 ) {
case V_29 :
if ( V_9 -> V_11 & V_20 )
V_76 = F_34 () ;
else
V_76 = V_9 -> V_19 . V_21 ;
F_158 ( V_150 , V_76 ) ;
break;
case V_113 :
case V_111 :
* V_150 = V_9 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
F_84 ( V_49 ) ;
return true ;
}
bool F_159 ( struct V_56 * V_57 ,
const T_1 * V_150 )
{
struct V_9 * V_9 ;
bool V_13 = true ;
if ( ! V_150 )
return V_13 ;
F_83 ( V_57 ) ;
V_9 = V_57 -> V_9 ;
if ( ! V_9 )
goto V_105;
switch ( V_9 -> V_28 ) {
case V_29 :
break;
case V_113 :
case V_111 :
V_13 = F_160 ( V_9 -> V_19 . V_17 , * V_150 ) ;
break;
default:
F_30 () ;
}
V_105:
F_84 ( V_57 ) ;
return V_13 ;
}
static struct V_75 * F_161 ( T_11 V_160 , unsigned V_178 ,
unsigned V_76 )
{
struct V_161 * V_177 ;
struct V_75 * V_75 ;
V_177 = F_144 ( V_76 , V_160 ) ;
V_75 = F_162 ( V_160 , V_178 , V_177 ) ;
if ( V_75 && F_163 ( V_75 ) == F_164 ( & V_177 -> V_179 [ 0 ] ) )
F_101 ( V_75 , V_180 ) ;
return V_75 ;
}
struct V_75 *
F_165 ( T_11 V_160 , int V_178 , struct V_61 * V_62 ,
unsigned long V_68 , int V_52 )
{
struct V_9 * V_10 ;
struct V_161 * V_177 ;
struct V_75 * V_75 ;
unsigned int V_181 ;
V_182:
V_10 = F_138 ( V_49 , V_62 , V_68 ) ;
V_181 = F_166 () ;
if ( F_140 ( V_10 -> V_28 == V_111 ) ) {
unsigned V_76 ;
V_76 = F_149 ( V_10 , V_62 , V_68 , V_101 + V_178 ) ;
F_97 ( V_10 ) ;
V_75 = F_161 ( V_160 , V_178 , V_76 ) ;
if ( F_140 ( ! F_167 ( V_181 ) && ! V_75 ) )
goto V_182;
return V_75 ;
}
V_177 = F_143 ( V_160 , V_10 , V_52 ) ;
if ( F_140 ( F_168 ( V_10 ) ) ) {
struct V_75 * V_75 = F_169 ( V_160 , V_178 ,
V_177 , F_139 ( V_160 , V_10 ) ) ;
F_24 ( V_10 ) ;
if ( F_140 ( ! F_167 ( V_181 ) && ! V_75 ) )
goto V_182;
return V_75 ;
}
V_75 = F_169 ( V_160 , V_178 , V_177 ,
F_139 ( V_160 , V_10 ) ) ;
if ( F_140 ( ! F_167 ( V_181 ) && ! V_75 ) )
goto V_182;
return V_75 ;
}
struct V_75 * F_170 ( T_11 V_160 , unsigned V_178 )
{
struct V_9 * V_10 = V_49 -> V_9 ;
struct V_75 * V_75 ;
unsigned int V_181 ;
if ( ! V_10 || F_171 () || ( V_160 & V_162 ) )
V_10 = & V_112 ;
V_182:
V_181 = F_166 () ;
if ( V_10 -> V_28 == V_111 )
V_75 = F_161 ( V_160 , V_178 , F_145 ( V_10 ) ) ;
else
V_75 = F_169 ( V_160 , V_178 ,
F_143 ( V_160 , V_10 , F_34 () ) ,
F_139 ( V_160 , V_10 ) ) ;
if ( F_140 ( ! F_167 ( V_181 ) && ! V_75 ) )
goto V_182;
return V_75 ;
}
struct V_9 * F_172 ( struct V_9 * V_109 )
{
struct V_9 * V_58 = F_22 ( V_39 , V_40 ) ;
if ( ! V_58 )
return F_21 ( - V_41 ) ;
if ( V_109 == V_49 -> V_9 ) {
F_83 ( V_49 ) ;
* V_58 = * V_109 ;
F_84 ( V_49 ) ;
} else
* V_58 = * V_109 ;
F_173 () ;
if ( F_174 () ) {
T_1 V_183 = V_34 ( V_49 ) ;
if ( V_58 -> V_11 & V_54 )
F_37 ( V_58 , & V_183 , V_48 ) ;
else
F_37 ( V_58 , & V_183 , V_46 ) ;
}
F_175 () ;
F_23 ( & V_58 -> V_42 , 1 ) ;
return V_58 ;
}
struct V_9 * F_176 ( struct V_9 * V_184 ,
struct V_9 * V_185 )
{
if ( ! F_168 ( V_185 ) )
return V_185 ;
* V_184 = * V_185 ;
V_184 -> V_11 &= ~ V_186 ;
F_24 ( V_185 ) ;
return V_184 ;
}
bool F_177 ( struct V_9 * V_187 , struct V_9 * V_188 )
{
if ( ! V_187 || ! V_188 )
return false ;
if ( V_187 -> V_28 != V_188 -> V_28 )
return false ;
if ( V_187 -> V_11 != V_188 -> V_11 )
return false ;
if ( F_4 ( V_187 ) )
if ( ! F_38 ( V_187 -> V_32 . V_33 , V_188 -> V_32 . V_33 ) )
return false ;
switch ( V_187 -> V_28 ) {
case V_113 :
case V_111 :
return ! ! F_38 ( V_187 -> V_19 . V_17 , V_188 -> V_19 . V_17 ) ;
case V_29 :
return V_187 -> V_19 . V_21 == V_188 -> V_19 . V_21 ;
default:
F_30 () ;
return false ;
}
}
static struct V_189 *
F_178 ( struct V_190 * V_191 , unsigned long V_85 , unsigned long V_69 )
{
struct V_192 * V_193 = V_191 -> V_194 . V_192 ;
while ( V_193 ) {
struct V_189 * V_43 = F_179 ( V_193 , struct V_189 , V_2 ) ;
if ( V_85 >= V_43 -> V_69 )
V_193 = V_193 -> V_195 ;
else if ( V_69 <= V_43 -> V_85 )
V_193 = V_193 -> V_196 ;
else
break;
}
if ( ! V_193 )
return NULL ;
for (; ; ) {
struct V_189 * V_32 = NULL ;
struct V_192 * V_88 = F_180 ( V_193 ) ;
if ( ! V_88 )
break;
V_32 = F_179 ( V_88 , struct V_189 , V_2 ) ;
if ( V_32 -> V_69 <= V_85 )
break;
V_193 = V_88 ;
}
return F_179 ( V_193 , struct V_189 , V_2 ) ;
}
static void F_181 ( struct V_190 * V_191 , struct V_189 * V_58 )
{
struct V_192 * * V_43 = & V_191 -> V_194 . V_192 ;
struct V_192 * V_197 = NULL ;
struct V_189 * V_2 ;
while ( * V_43 ) {
V_197 = * V_43 ;
V_2 = F_179 ( V_197 , struct V_189 , V_2 ) ;
if ( V_58 -> V_85 < V_2 -> V_85 )
V_43 = & ( * V_43 ) -> V_196 ;
else if ( V_58 -> V_69 > V_2 -> V_69 )
V_43 = & ( * V_43 ) -> V_195 ;
else
F_30 () ;
}
F_182 ( & V_58 -> V_2 , V_197 , V_43 ) ;
F_183 ( & V_58 -> V_2 , & V_191 -> V_194 ) ;
F_19 ( L_4 , V_58 -> V_85 , V_58 -> V_69 ,
V_58 -> V_36 ? V_58 -> V_36 -> V_28 : 0 ) ;
}
struct V_9 *
F_184 ( struct V_190 * V_191 , unsigned long V_198 )
{
struct V_9 * V_10 = NULL ;
struct V_189 * V_199 ;
if ( ! V_191 -> V_194 . V_192 )
return NULL ;
F_185 ( & V_191 -> V_200 ) ;
V_199 = F_178 ( V_191 , V_198 , V_198 + 1 ) ;
if ( V_199 ) {
F_186 ( V_199 -> V_36 ) ;
V_10 = V_199 -> V_36 ;
}
F_187 ( & V_191 -> V_200 ) ;
return V_10 ;
}
static void F_188 ( struct V_190 * V_191 , struct V_189 * V_193 )
{
F_19 ( L_5 , V_193 -> V_85 , V_193 -> V_69 ) ;
F_189 ( & V_193 -> V_2 , & V_191 -> V_194 ) ;
F_85 ( V_193 -> V_36 ) ;
F_26 ( V_201 , V_193 ) ;
}
static struct V_189 * F_190 ( unsigned long V_85 , unsigned long V_69 ,
struct V_9 * V_10 )
{
struct V_189 * V_193 = F_22 ( V_201 , V_40 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_85 = V_85 ;
V_193 -> V_69 = V_69 ;
F_186 ( V_10 ) ;
V_10 -> V_11 |= V_186 ;
V_193 -> V_36 = V_10 ;
return V_193 ;
}
static int F_191 ( struct V_190 * V_191 , unsigned long V_85 ,
unsigned long V_69 , struct V_189 * V_58 )
{
struct V_189 * V_193 , * V_202 = NULL ;
V_203:
F_185 ( & V_191 -> V_200 ) ;
V_193 = F_178 ( V_191 , V_85 , V_69 ) ;
while ( V_193 && V_193 -> V_85 < V_69 ) {
struct V_192 * V_82 = F_192 ( & V_193 -> V_2 ) ;
if ( V_193 -> V_85 >= V_85 ) {
if ( V_193 -> V_69 <= V_69 )
F_188 ( V_191 , V_193 ) ;
else
V_193 -> V_85 = V_69 ;
} else {
if ( V_193 -> V_69 > V_69 ) {
if ( ! V_202 ) {
F_187 ( & V_191 -> V_200 ) ;
V_202 = F_190 ( V_69 , V_193 -> V_69 , V_193 -> V_36 ) ;
if ( ! V_202 )
return - V_41 ;
goto V_203;
}
V_193 -> V_69 = V_85 ;
F_181 ( V_191 , V_202 ) ;
V_202 = NULL ;
break;
} else
V_193 -> V_69 = V_85 ;
}
if ( ! V_82 )
break;
V_193 = F_179 ( V_82 , struct V_189 , V_2 ) ;
}
if ( V_58 )
F_181 ( V_191 , V_58 ) ;
F_187 ( & V_191 -> V_200 ) ;
if ( V_202 ) {
F_85 ( V_202 -> V_36 ) ;
F_26 ( V_201 , V_202 ) ;
}
return 0 ;
}
void F_193 ( struct V_190 * V_191 , struct V_9 * V_176 )
{
int V_13 ;
V_191 -> V_194 = V_204 ;
F_194 ( & V_191 -> V_200 ) ;
if ( V_176 ) {
struct V_61 V_205 ;
struct V_9 * V_58 ;
F_80 ( V_110 ) ;
if ( ! V_110 )
goto V_206;
V_58 = F_18 ( V_176 -> V_28 , V_176 -> V_11 , & V_176 -> V_32 . V_33 ) ;
if ( F_81 ( V_58 ) )
goto V_207;
F_83 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_176 -> V_32 . V_33 , V_110 ) ;
F_84 ( V_49 ) ;
if ( V_13 )
goto V_208;
memset ( & V_205 , 0 , sizeof( struct V_61 ) ) ;
V_205 . V_92 = V_209 ;
F_195 ( V_191 , & V_205 , V_58 ) ;
V_208:
F_85 ( V_58 ) ;
V_207:
F_86 ( V_110 ) ;
V_206:
F_85 ( V_176 ) ;
}
}
int F_195 ( struct V_190 * V_210 ,
struct V_61 * V_62 , struct V_9 * V_211 )
{
int V_86 ;
struct V_189 * V_58 = NULL ;
unsigned long V_212 = F_196 ( V_62 ) ;
F_19 ( L_6 ,
V_62 -> V_100 ,
V_212 , V_211 ? V_211 -> V_28 : - 1 ,
V_211 ? V_211 -> V_11 : - 1 ,
V_211 ? F_20 ( V_211 -> V_19 . V_17 ) [ 0 ] : - 1 ) ;
if ( V_211 ) {
V_58 = F_190 ( V_62 -> V_100 , V_62 -> V_100 + V_212 , V_211 ) ;
if ( ! V_58 )
return - V_41 ;
}
V_86 = F_191 ( V_210 , V_62 -> V_100 , V_62 -> V_100 + V_212 , V_58 ) ;
if ( V_86 && V_58 )
F_26 ( V_201 , V_58 ) ;
return V_86 ;
}
void F_197 ( struct V_190 * V_43 )
{
struct V_189 * V_193 ;
struct V_192 * V_82 ;
if ( ! V_43 -> V_194 . V_192 )
return;
F_185 ( & V_43 -> V_200 ) ;
V_82 = F_198 ( & V_43 -> V_194 ) ;
while ( V_82 ) {
V_193 = F_179 ( V_82 , struct V_189 , V_2 ) ;
V_82 = F_192 ( & V_193 -> V_2 ) ;
F_189 ( & V_193 -> V_2 , & V_43 -> V_194 ) ;
F_85 ( V_193 -> V_36 ) ;
F_26 ( V_201 , V_193 ) ;
}
F_187 ( & V_43 -> V_200 ) ;
}
void T_12 F_199 ( void )
{
T_1 F_145 ;
unsigned long V_213 = 0 ;
int V_76 , V_214 = 0 ;
V_39 = F_200 ( L_7 ,
sizeof( struct V_9 ) ,
0 , V_215 , NULL ) ;
V_201 = F_200 ( L_8 ,
sizeof( struct V_189 ) ,
0 , V_215 , NULL ) ;
F_88 ( F_145 ) ;
F_201 (nid, N_HIGH_MEMORY) {
unsigned long V_216 = F_202 ( V_76 ) ;
if ( V_213 < V_216 ) {
V_213 = V_216 ;
V_214 = V_76 ;
}
if ( ( V_216 << V_101 ) >= ( 16 << 20 ) )
F_89 ( V_76 , F_145 ) ;
}
if ( F_140 ( F_10 ( F_145 ) ) )
F_89 ( V_214 , F_145 ) ;
if ( F_79 ( V_111 , 0 , & F_145 ) )
F_203 ( L_9 ) ;
}
void F_204 ( void )
{
F_79 ( V_37 , 0 , NULL ) ;
}
int F_205 ( char * V_217 , struct V_9 * * V_176 , int V_218 )
{
struct V_9 * V_58 = NULL ;
unsigned short V_28 ;
unsigned short V_135 ( V_139 ) ;
T_1 V_17 ;
char * V_219 = strchr ( V_217 , ':' ) ;
char * V_11 = strchr ( V_217 , '=' ) ;
int V_86 = 1 ;
if ( V_219 ) {
* V_219 ++ = '\0' ;
if ( F_206 ( V_219 , V_17 ) )
goto V_105;
if ( ! F_207 ( V_17 , V_26 [ V_27 ] ) )
goto V_105;
} else
F_88 ( V_17 ) ;
if ( V_11 )
* V_11 ++ = '\0' ;
for ( V_28 = 0 ; V_28 <= V_220 ; V_28 ++ ) {
if ( ! strcmp ( V_217 , V_221 [ V_28 ] ) ) {
break;
}
}
if ( V_28 > V_220 )
goto V_105;
switch ( V_28 ) {
case V_29 :
if ( V_219 ) {
char * V_222 = V_219 ;
while ( isdigit ( * V_222 ) )
V_222 ++ ;
if ( * V_222 )
goto V_105;
}
break;
case V_111 :
if ( ! V_219 )
V_17 = V_26 [ V_27 ] ;
break;
case V_220 :
if ( V_219 )
goto V_105;
V_28 = V_29 ;
break;
case V_37 :
if ( ! V_219 )
V_86 = 0 ;
goto V_105;
case V_113 :
if ( ! V_219 )
goto V_105;
}
V_139 = 0 ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_10 ) )
V_139 |= V_38 ;
else if ( ! strcmp ( V_11 , L_11 ) )
V_139 |= V_30 ;
else
goto V_105;
}
V_58 = F_18 ( V_28 , V_139 , & V_17 ) ;
if ( F_81 ( V_58 ) )
goto V_105;
if ( V_218 ) {
V_58 -> V_32 . V_33 = V_17 ;
} else {
int V_13 ;
F_80 ( V_110 ) ;
if ( V_110 ) {
F_83 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_17 , V_110 ) ;
F_84 ( V_49 ) ;
} else
V_13 = - V_41 ;
F_86 ( V_110 ) ;
if ( V_13 ) {
F_85 ( V_58 ) ;
goto V_105;
}
}
V_86 = 0 ;
V_105:
if ( V_219 )
* -- V_219 = ':' ;
if ( V_11 )
* -- V_11 = '=' ;
if ( ! V_86 )
* V_176 = V_58 ;
return V_86 ;
}
int F_208 ( char * V_223 , int V_224 , struct V_9 * V_10 , int V_218 )
{
char * V_43 = V_223 ;
int V_225 ;
T_1 V_17 ;
unsigned short V_28 ;
unsigned short V_11 = V_10 ? V_10 -> V_11 : 0 ;
F_16 ( V_224 < strlen ( L_12 ) + strlen ( L_11 ) + 16 ) ;
if ( ! V_10 || V_10 == & V_112 )
V_28 = V_37 ;
else
V_28 = V_10 -> V_28 ;
switch ( V_28 ) {
case V_37 :
F_88 ( V_17 ) ;
break;
case V_29 :
F_88 ( V_17 ) ;
if ( V_11 & V_20 )
V_28 = V_220 ;
else
F_89 ( V_10 -> V_19 . V_21 , V_17 ) ;
break;
case V_113 :
case V_111 :
if ( V_218 )
V_17 = V_10 -> V_32 . V_33 ;
else
V_17 = V_10 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
V_225 = strlen ( V_221 [ V_28 ] ) ;
if ( V_223 + V_224 < V_43 + V_225 + 1 )
return - V_226 ;
strcpy ( V_43 , V_221 [ V_28 ] ) ;
V_43 += V_225 ;
if ( V_11 & V_12 ) {
if ( V_223 + V_224 < V_43 + 2 )
return - V_226 ;
* V_43 ++ = '=' ;
if ( V_11 & V_38 )
V_43 += snprintf ( V_43 , V_223 + V_224 - V_43 , L_10 ) ;
else if ( V_11 & V_30 )
V_43 += snprintf ( V_43 , V_223 + V_224 - V_43 , L_11 ) ;
}
if ( ! F_10 ( V_17 ) ) {
if ( V_223 + V_224 < V_43 + 2 )
return - V_226 ;
* V_43 ++ = ':' ;
V_43 += F_209 ( V_43 , V_223 + V_224 - V_43 , V_17 ) ;
}
return V_43 - V_223 ;
}
