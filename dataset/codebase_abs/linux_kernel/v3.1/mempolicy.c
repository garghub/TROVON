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
if ( ! F_4 ( V_10 ) && V_45 == 0 &&
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
static int F_70 ( struct V_61 * V_62 , struct V_9 * V_58 )
{
int V_86 = 0 ;
struct V_9 * V_95 = V_62 -> V_66 ;
F_19 ( L_2 ,
V_62 -> V_90 , V_62 -> V_92 , V_62 -> V_96 ,
V_62 -> V_97 , V_62 -> V_98 ,
V_62 -> V_97 ? V_62 -> V_97 -> V_99 : NULL ) ;
if ( V_62 -> V_97 && V_62 -> V_97 -> V_99 )
V_86 = V_62 -> V_97 -> V_99 ( V_62 , V_58 ) ;
if ( ! V_86 ) {
F_71 ( V_58 ) ;
V_62 -> V_66 = V_58 ;
F_72 ( V_95 ) ;
}
return V_86 ;
}
static int F_73 ( struct V_59 * V_60 , unsigned long V_85 ,
unsigned long V_69 , struct V_9 * V_100 )
{
struct V_61 * V_82 ;
struct V_61 * V_88 ;
struct V_61 * V_62 ;
int V_86 = 0 ;
unsigned long V_101 ;
unsigned long V_102 ;
V_62 = F_74 ( V_60 , V_85 , & V_88 ) ;
if ( ! V_62 || V_62 -> V_90 > V_85 )
return - V_89 ;
for (; V_62 && V_62 -> V_90 < V_69 ; V_88 = V_62 , V_62 = V_82 ) {
V_82 = V_62 -> V_65 ;
V_101 = F_75 ( V_85 , V_62 -> V_90 ) ;
V_102 = F_76 ( V_69 , V_62 -> V_92 ) ;
V_88 = F_77 ( V_60 , V_88 , V_101 , V_102 , V_62 -> V_103 ,
V_62 -> V_104 , V_62 -> V_98 , V_62 -> V_96 ,
V_100 ) ;
if ( V_88 ) {
V_62 = V_88 ;
V_82 = V_62 -> V_65 ;
continue;
}
if ( V_62 -> V_90 != V_101 ) {
V_86 = F_78 ( V_62 -> V_74 , V_62 , V_101 , 1 ) ;
if ( V_86 )
goto V_105;
}
if ( V_62 -> V_92 != V_102 ) {
V_86 = F_78 ( V_62 -> V_74 , V_62 , V_102 , 0 ) ;
if ( V_86 )
goto V_105;
}
V_86 = F_70 ( V_62 , V_100 ) ;
if ( V_86 )
goto V_105;
}
V_105:
return V_86 ;
}
void F_79 ( struct V_56 * V_43 )
{
if ( V_43 -> V_9 )
V_43 -> V_11 |= V_106 ;
else
V_43 -> V_11 &= ~ V_106 ;
}
static void F_80 ( void )
{
F_79 ( V_49 ) ;
}
static long F_81 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_58 , * V_95 ;
struct V_59 * V_60 = V_49 -> V_60 ;
F_82 ( V_107 ) ;
int V_13 ;
if ( ! V_107 )
return - V_41 ;
V_58 = F_18 ( V_28 , V_11 , V_17 ) ;
if ( F_83 ( V_58 ) ) {
V_13 = F_84 ( V_58 ) ;
goto V_105;
}
if ( V_60 )
F_42 ( & V_60 -> V_63 ) ;
F_85 ( V_49 ) ;
V_13 = F_14 ( V_58 , V_17 , V_107 ) ;
if ( V_13 ) {
F_86 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_58 ) ;
goto V_105;
}
V_95 = V_49 -> V_9 ;
V_49 -> V_9 = V_58 ;
F_80 () ;
if ( V_58 && V_58 -> V_28 == V_108 &&
F_7 ( V_58 -> V_19 . V_17 ) )
V_49 -> V_50 = F_12 ( V_58 -> V_19 . V_17 ) ;
F_86 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_95 ) ;
V_13 = 0 ;
V_105:
F_87 ( V_107 ) ;
return V_13 ;
}
static void F_88 ( struct V_9 * V_43 , T_1 * V_17 )
{
F_89 ( * V_17 ) ;
if ( V_43 == & V_109 )
return;
switch ( V_43 -> V_28 ) {
case V_110 :
case V_108 :
* V_17 = V_43 -> V_19 . V_17 ;
break;
case V_29 :
if ( ! ( V_43 -> V_11 & V_20 ) )
F_90 ( V_43 -> V_19 . V_21 , * V_17 ) ;
break;
default:
F_30 () ;
}
}
static int F_91 ( struct V_59 * V_60 , unsigned long V_68 )
{
struct V_75 * V_43 ;
int V_86 ;
V_86 = F_92 ( V_49 , V_60 , V_68 & V_111 , 1 , 0 , 0 , & V_43 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_50 ( V_43 ) ;
F_93 ( V_43 ) ;
}
return V_86 ;
}
static long F_94 ( int * V_36 , T_1 * V_112 ,
unsigned long V_68 , unsigned long V_11 )
{
int V_86 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_61 * V_62 = NULL ;
struct V_9 * V_10 = V_49 -> V_9 ;
if ( V_11 &
~ ( unsigned long ) ( V_113 | V_114 | V_115 ) )
return - V_18 ;
if ( V_11 & V_115 ) {
if ( V_11 & ( V_113 | V_114 ) )
return - V_18 ;
* V_36 = 0 ;
F_85 ( V_49 ) ;
* V_112 = V_25 ;
F_86 ( V_49 ) ;
return 0 ;
}
if ( V_11 & V_114 ) {
F_95 ( & V_60 -> V_63 ) ;
V_62 = F_96 ( V_60 , V_68 , V_68 + 1 ) ;
if ( ! V_62 ) {
F_97 ( & V_60 -> V_63 ) ;
return - V_89 ;
}
if ( V_62 -> V_97 && V_62 -> V_97 -> V_116 )
V_10 = V_62 -> V_97 -> V_116 ( V_62 , V_68 ) ;
else
V_10 = V_62 -> V_66 ;
} else if ( V_68 )
return - V_18 ;
if ( ! V_10 )
V_10 = & V_109 ;
if ( V_11 & V_113 ) {
if ( V_11 & V_114 ) {
V_86 = F_91 ( V_60 , V_68 ) ;
if ( V_86 < 0 )
goto V_105;
* V_36 = V_86 ;
} else if ( V_10 == V_49 -> V_9 &&
V_10 -> V_28 == V_108 ) {
* V_36 = V_49 -> V_50 ;
} else {
V_86 = - V_18 ;
goto V_105;
}
} else {
* V_36 = V_10 == & V_109 ? V_37 :
V_10 -> V_28 ;
* V_36 |= ( V_10 -> V_11 & V_12 ) ;
}
if ( V_62 ) {
F_97 ( & V_49 -> V_60 -> V_63 ) ;
V_62 = NULL ;
}
V_86 = 0 ;
if ( V_112 ) {
if ( F_4 ( V_10 ) ) {
* V_112 = V_10 -> V_32 . V_33 ;
} else {
F_85 ( V_49 ) ;
F_88 ( V_10 , V_112 ) ;
F_86 ( V_49 ) ;
}
}
V_105:
F_98 ( V_10 ) ;
if ( V_62 )
F_97 ( & V_49 -> V_60 -> V_63 ) ;
return V_86 ;
}
static void F_51 ( struct V_75 * V_75 , struct V_117 * V_118 ,
unsigned long V_11 )
{
if ( ( V_11 & V_79 ) || F_99 ( V_75 ) == 1 ) {
if ( ! F_100 ( V_75 ) ) {
F_101 ( & V_75 -> V_119 , V_118 ) ;
F_102 ( V_75 , V_120 +
F_103 ( V_75 ) ) ;
}
}
}
static struct V_75 * F_104 ( struct V_75 * V_75 , unsigned long V_52 , int * * V_121 )
{
return F_105 ( V_52 , V_122 , 0 ) ;
}
static int F_106 ( struct V_59 * V_60 , int V_123 , int V_124 ,
int V_11 )
{
T_1 V_112 ;
F_107 ( V_118 ) ;
int V_86 = 0 ;
struct V_61 * V_62 ;
F_89 ( V_112 ) ;
F_90 ( V_123 , V_112 ) ;
V_62 = F_66 ( V_60 , V_60 -> V_64 -> V_90 , V_60 -> V_125 , & V_112 ,
V_11 | V_91 , & V_118 ) ;
if ( F_83 ( V_62 ) )
return F_84 ( V_62 ) ;
if ( ! F_108 ( & V_118 ) ) {
V_86 = F_109 ( & V_118 , F_104 , V_124 ,
false , true ) ;
if ( V_86 )
F_110 ( & V_118 ) ;
}
return V_86 ;
}
int F_111 ( struct V_59 * V_60 ,
const T_1 * V_126 , const T_1 * V_127 , int V_11 )
{
int V_128 = 0 ;
int V_86 ;
T_1 V_16 ;
V_86 = F_112 () ;
if ( V_86 )
return V_86 ;
F_95 ( & V_60 -> V_63 ) ;
V_86 = F_113 ( V_60 , V_126 , V_127 , V_11 ) ;
if ( V_86 )
goto V_105;
V_16 = * V_126 ;
while ( ! F_10 ( V_16 ) ) {
int V_129 , V_130 ;
int V_123 = - 1 ;
int V_124 = 0 ;
F_2 (s, tmp) {
V_130 = F_36 ( V_129 , * V_126 , * V_127 ) ;
if ( V_129 == V_130 )
continue;
V_123 = V_129 ;
V_124 = V_130 ;
if ( ! F_32 ( V_124 , V_16 ) )
break;
}
if ( V_123 == - 1 )
break;
F_114 ( V_123 , V_16 ) ;
V_86 = F_106 ( V_60 , V_123 , V_124 , V_11 ) ;
if ( V_86 > 0 )
V_128 += V_86 ;
if ( V_86 < 0 )
break;
}
V_105:
F_97 ( & V_60 -> V_63 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_128 ;
}
static struct V_75 * F_115 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_121 )
{
struct V_61 * V_62 = (struct V_61 * ) V_70 ;
unsigned long V_131 ( V_132 ) ;
while ( V_62 ) {
V_132 = F_116 ( V_75 , V_62 ) ;
if ( V_132 != - V_89 )
break;
V_62 = V_62 -> V_65 ;
}
return F_117 ( V_122 , V_62 , V_132 ) ;
}
static void F_51 ( struct V_75 * V_75 , struct V_117 * V_118 ,
unsigned long V_11 )
{
}
int F_111 ( struct V_59 * V_60 ,
const T_1 * V_126 , const T_1 * V_127 , int V_11 )
{
return - V_133 ;
}
static struct V_75 * F_115 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_121 )
{
return NULL ;
}
static long F_118 ( unsigned long V_85 , unsigned long V_134 ,
unsigned short V_28 , unsigned short V_135 ,
T_1 * V_112 , unsigned long V_11 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_9 * V_58 ;
unsigned long V_69 ;
int V_86 ;
F_107 ( V_118 ) ;
if ( V_11 & ~ ( unsigned long ) ( V_93 |
V_78 | V_79 ) )
return - V_18 ;
if ( ( V_11 & V_79 ) && ! F_119 ( V_136 ) )
return - V_137 ;
if ( V_85 & ~ V_111 )
return - V_18 ;
if ( V_28 == V_37 )
V_11 &= ~ V_93 ;
V_134 = ( V_134 + V_80 - 1 ) & V_111 ;
V_69 = V_85 + V_134 ;
if ( V_69 < V_85 )
return - V_18 ;
if ( V_69 == V_85 )
return 0 ;
V_58 = F_18 ( V_28 , V_135 , V_112 ) ;
if ( F_83 ( V_58 ) )
return F_84 ( V_58 ) ;
if ( ! V_58 )
V_11 |= V_91 ;
F_19 ( L_3 ,
V_85 , V_85 + V_134 , V_28 , V_135 ,
V_112 ? F_20 ( * V_112 ) [ 0 ] : - 1 ) ;
if ( V_11 & ( V_78 | V_79 ) ) {
V_86 = F_112 () ;
if ( V_86 )
goto V_138;
}
{
F_82 ( V_107 ) ;
if ( V_107 ) {
F_42 ( & V_60 -> V_63 ) ;
F_85 ( V_49 ) ;
V_86 = F_14 ( V_58 , V_112 , V_107 ) ;
F_86 ( V_49 ) ;
if ( V_86 )
F_43 ( & V_60 -> V_63 ) ;
} else
V_86 = - V_41 ;
F_87 ( V_107 ) ;
}
if ( V_86 )
goto V_138;
V_62 = F_66 ( V_60 , V_85 , V_69 , V_112 ,
V_11 | V_77 , & V_118 ) ;
V_86 = F_84 ( V_62 ) ;
if ( ! F_83 ( V_62 ) ) {
int V_139 = 0 ;
V_86 = F_73 ( V_60 , V_85 , V_69 , V_58 ) ;
if ( ! F_108 ( & V_118 ) ) {
V_139 = F_109 ( & V_118 , F_115 ,
( unsigned long ) V_62 ,
false , true ) ;
if ( V_139 )
F_110 ( & V_118 ) ;
}
if ( ! V_86 && V_139 && ( V_11 & V_93 ) )
V_86 = - V_83 ;
} else
F_110 ( & V_118 ) ;
F_43 ( & V_60 -> V_63 ) ;
V_138:
F_72 ( V_58 ) ;
return V_86 ;
}
static int F_120 ( T_1 * V_17 , const unsigned long T_7 * V_112 ,
unsigned long V_140 )
{
unsigned long V_3 ;
unsigned long V_141 ;
unsigned long V_142 ;
-- V_140 ;
F_89 ( * V_17 ) ;
if ( V_140 == 0 || ! V_112 )
return 0 ;
if ( V_140 > V_80 * V_143 )
return - V_18 ;
V_141 = F_121 ( V_140 ) ;
if ( ( V_140 % V_144 ) == 0 )
V_142 = ~ 0UL ;
else
V_142 = ( 1UL << ( V_140 % V_144 ) ) - 1 ;
if ( V_141 > F_121 ( V_51 ) ) {
if ( V_141 > V_80 / sizeof( long ) )
return - V_18 ;
for ( V_3 = F_121 ( V_51 ) ; V_3 < V_141 ; V_3 ++ ) {
unsigned long V_145 ;
if ( F_122 ( V_145 , V_112 + V_3 ) )
return - V_89 ;
if ( V_3 == V_141 - 1 ) {
if ( V_145 & V_142 )
return - V_18 ;
} else if ( V_145 )
return - V_18 ;
}
V_141 = F_121 ( V_51 ) ;
V_142 = ~ 0UL ;
}
if ( F_123 ( F_20 ( * V_17 ) , V_112 , V_141 *sizeof( unsigned long ) ) )
return - V_89 ;
F_20 ( * V_17 ) [ V_141 - 1 ] &= V_142 ;
return 0 ;
}
static int F_124 ( unsigned long T_7 * V_146 , unsigned long V_140 ,
T_1 * V_17 )
{
unsigned long V_147 = F_125 ( V_140 - 1 , 64 ) / 8 ;
const int V_148 = F_121 ( V_51 ) * sizeof( long ) ;
if ( V_147 > V_148 ) {
if ( V_147 > V_80 )
return - V_18 ;
if ( F_126 ( ( char T_7 * ) V_146 + V_148 , V_147 - V_148 ) )
return - V_89 ;
V_147 = V_148 ;
}
return F_127 ( V_146 , F_20 ( * V_17 ) , V_147 ) ? - V_89 : 0 ;
}
T_8 long F_128 ( int T_7 * V_36 ,
T_9 T_7 * V_112 ,
T_9 V_140 ,
T_9 V_68 , T_9 V_11 )
{
long V_86 ;
unsigned long T_7 * V_149 = NULL ;
unsigned long V_150 , V_151 ;
F_129 ( V_152 , V_51 ) ;
V_150 = F_130 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_151 = F_125 ( V_150 , V_144 ) / 8 ;
if ( V_112 )
V_149 = F_131 ( V_151 ) ;
V_86 = F_132 ( V_36 , V_149 , V_150 + 1 , V_68 , V_11 ) ;
if ( ! V_86 && V_112 ) {
unsigned long V_153 ;
V_153 = F_130 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_123 ( V_152 , V_149 , V_153 ) ;
V_86 |= F_126 ( V_112 , F_125 ( V_140 - 1 , 8 ) / 8 ) ;
V_86 |= F_133 ( V_112 , V_152 , V_150 ) ;
}
return V_86 ;
}
T_8 long F_134 ( int V_28 , T_9 T_7 * V_112 ,
T_9 V_140 )
{
long V_86 = 0 ;
unsigned long T_7 * V_149 = NULL ;
unsigned long V_150 , V_151 ;
F_129 ( V_152 , V_51 ) ;
V_150 = F_130 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_151 = F_125 ( V_150 , V_144 ) / 8 ;
if ( V_112 ) {
V_86 = F_135 ( V_152 , V_112 , V_150 ) ;
V_149 = F_131 ( V_151 ) ;
V_86 |= F_127 ( V_149 , V_152 , V_151 ) ;
}
if ( V_86 )
return - V_89 ;
return F_136 ( V_28 , V_149 , V_150 + 1 ) ;
}
T_8 long F_137 ( T_9 V_85 , T_9 V_134 ,
T_9 V_28 , T_9 T_7 * V_112 ,
T_9 V_140 , T_9 V_11 )
{
long V_86 = 0 ;
unsigned long T_7 * V_149 = NULL ;
unsigned long V_150 , V_151 ;
T_1 V_152 ;
V_150 = F_130 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_151 = F_125 ( V_150 , V_144 ) / 8 ;
if ( V_112 ) {
V_86 = F_135 ( F_20 ( V_152 ) , V_112 , V_150 ) ;
V_149 = F_131 ( V_151 ) ;
V_86 |= F_127 ( V_149 , F_20 ( V_152 ) , V_151 ) ;
}
if ( V_86 )
return - V_89 ;
return F_138 ( V_85 , V_134 , V_28 , V_149 , V_150 + 1 , V_11 ) ;
}
struct V_9 * F_139 ( struct V_56 * V_154 ,
struct V_61 * V_62 , unsigned long V_68 )
{
struct V_9 * V_10 = V_154 -> V_9 ;
if ( V_62 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_116 ) {
struct V_9 * V_155 = V_62 -> V_97 -> V_116 ( V_62 ,
V_68 ) ;
if ( V_155 )
V_10 = V_155 ;
} else if ( V_62 -> V_66 )
V_10 = V_62 -> V_66 ;
}
if ( ! V_10 )
V_10 = & V_109 ;
return V_10 ;
}
static T_1 * F_140 ( T_10 V_156 , struct V_9 * V_36 )
{
if ( F_141 ( V_36 -> V_28 == V_110 ) &&
F_142 ( V_156 ) >= V_6 &&
F_143 ( & V_36 -> V_19 . V_17 ) )
return & V_36 -> V_19 . V_17 ;
return NULL ;
}
static struct V_157 * F_144 ( T_10 V_156 , struct V_9 * V_36 ,
int V_2 )
{
switch ( V_36 -> V_28 ) {
case V_29 :
if ( ! ( V_36 -> V_11 & V_20 ) )
V_2 = V_36 -> V_19 . V_21 ;
break;
case V_110 :
if ( F_141 ( V_156 & V_158 ) &&
F_141 ( ! F_32 ( V_2 , V_36 -> V_19 . V_17 ) ) )
V_2 = F_12 ( V_36 -> V_19 . V_17 ) ;
break;
default:
F_30 () ;
}
return F_145 ( V_2 , V_156 ) ;
}
static unsigned F_146 ( struct V_9 * V_36 )
{
unsigned V_76 , V_82 ;
struct V_56 * V_159 = V_49 ;
V_76 = V_159 -> V_50 ;
V_82 = F_33 ( V_76 , V_36 -> V_19 . V_17 ) ;
if ( V_82 >= V_51 )
V_82 = F_12 ( V_36 -> V_19 . V_17 ) ;
if ( V_82 < V_51 )
V_159 -> V_50 = V_82 ;
return V_76 ;
}
unsigned F_147 ( struct V_9 * V_36 )
{
if ( ! V_36 || V_36 -> V_11 & V_20 )
return F_34 () ;
switch ( V_36 -> V_28 ) {
case V_29 :
return V_36 -> V_19 . V_21 ;
case V_108 :
return F_146 ( V_36 ) ;
case V_110 : {
struct V_157 * V_157 ;
struct V_4 * V_4 ;
enum V_160 V_161 = F_142 ( V_40 ) ;
V_157 = & F_3 ( F_34 () ) -> V_162 [ 0 ] ;
( void ) F_148 ( V_157 , V_161 ,
& V_36 -> V_19 . V_17 ,
& V_4 ) ;
return V_4 ? V_4 -> V_52 : F_34 () ;
}
default:
F_30 () ;
}
}
static unsigned F_149 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_163 )
{
unsigned V_164 = F_7 ( V_10 -> V_19 . V_17 ) ;
unsigned V_165 ;
int V_166 ;
int V_76 = - 1 ;
if ( ! V_164 )
return F_34 () ;
V_165 = ( unsigned int ) V_163 % V_164 ;
V_166 = 0 ;
do {
V_76 = F_33 ( V_76 , V_10 -> V_19 . V_17 ) ;
V_166 ++ ;
} while ( V_166 <= V_165 );
return V_76 ;
}
static inline unsigned F_150 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_68 , int V_167 )
{
if ( V_62 ) {
unsigned long V_163 ;
F_151 ( V_167 < V_168 ) ;
V_163 = V_62 -> V_96 >> ( V_167 - V_168 ) ;
V_163 += ( V_68 - V_62 -> V_90 ) >> V_167 ;
return F_149 ( V_10 , V_62 , V_163 ) ;
} else
return F_146 ( V_10 ) ;
}
int F_152 ( const T_1 * V_169 )
{
int V_32 , V_170 = - 1 ;
V_32 = F_7 ( * V_169 ) ;
if ( V_32 )
V_170 = F_153 ( V_169 -> V_171 ,
F_154 () % V_32 , V_51 ) ;
return V_170 ;
}
struct V_157 * F_155 ( struct V_61 * V_62 , unsigned long V_68 ,
T_10 V_172 , struct V_9 * * V_173 ,
T_1 * * V_1 )
{
struct V_157 * V_174 ;
* V_173 = F_139 ( V_49 , V_62 , V_68 ) ;
* V_1 = NULL ;
if ( F_141 ( ( * V_173 ) -> V_28 == V_108 ) ) {
V_174 = F_145 ( F_150 ( * V_173 , V_62 , V_68 ,
F_156 ( F_157 ( V_62 ) ) ) , V_172 ) ;
} else {
V_174 = F_144 ( V_172 , * V_173 , F_34 () ) ;
if ( ( * V_173 ) -> V_28 == V_110 )
* V_1 = & ( * V_173 ) -> V_19 . V_17 ;
}
return V_174 ;
}
bool F_158 ( T_1 * V_146 )
{
struct V_9 * V_9 ;
int V_76 ;
if ( ! ( V_146 && V_49 -> V_9 ) )
return false ;
F_85 ( V_49 ) ;
V_9 = V_49 -> V_9 ;
switch ( V_9 -> V_28 ) {
case V_29 :
if ( V_9 -> V_11 & V_20 )
V_76 = F_34 () ;
else
V_76 = V_9 -> V_19 . V_21 ;
F_159 ( V_146 , V_76 ) ;
break;
case V_110 :
case V_108 :
* V_146 = V_9 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
F_86 ( V_49 ) ;
return true ;
}
bool F_160 ( struct V_56 * V_57 ,
const T_1 * V_146 )
{
struct V_9 * V_9 ;
bool V_13 = true ;
if ( ! V_146 )
return V_13 ;
F_85 ( V_57 ) ;
V_9 = V_57 -> V_9 ;
if ( ! V_9 )
goto V_105;
switch ( V_9 -> V_28 ) {
case V_29 :
break;
case V_110 :
case V_108 :
V_13 = F_161 ( V_9 -> V_19 . V_17 , * V_146 ) ;
break;
default:
F_30 () ;
}
V_105:
F_86 ( V_57 ) ;
return V_13 ;
}
static struct V_75 * F_162 ( T_10 V_156 , unsigned V_175 ,
unsigned V_76 )
{
struct V_157 * V_174 ;
struct V_75 * V_75 ;
V_174 = F_145 ( V_76 , V_156 ) ;
V_75 = F_163 ( V_156 , V_175 , V_174 ) ;
if ( V_75 && F_164 ( V_75 ) == F_165 ( & V_174 -> V_176 [ 0 ] ) )
F_102 ( V_75 , V_177 ) ;
return V_75 ;
}
struct V_75 *
F_166 ( T_10 V_156 , int V_175 , struct V_61 * V_62 ,
unsigned long V_68 , int V_52 )
{
struct V_9 * V_10 = F_139 ( V_49 , V_62 , V_68 ) ;
struct V_157 * V_174 ;
struct V_75 * V_75 ;
F_167 () ;
if ( F_141 ( V_10 -> V_28 == V_108 ) ) {
unsigned V_76 ;
V_76 = F_150 ( V_10 , V_62 , V_68 , V_168 + V_175 ) ;
F_98 ( V_10 ) ;
V_75 = F_162 ( V_156 , V_175 , V_76 ) ;
F_168 () ;
return V_75 ;
}
V_174 = F_144 ( V_156 , V_10 , V_52 ) ;
if ( F_141 ( F_169 ( V_10 ) ) ) {
struct V_75 * V_75 = F_170 ( V_156 , V_175 ,
V_174 , F_140 ( V_156 , V_10 ) ) ;
F_24 ( V_10 ) ;
F_168 () ;
return V_75 ;
}
V_75 = F_170 ( V_156 , V_175 , V_174 ,
F_140 ( V_156 , V_10 ) ) ;
F_168 () ;
return V_75 ;
}
struct V_75 * F_171 ( T_10 V_156 , unsigned V_175 )
{
struct V_9 * V_10 = V_49 -> V_9 ;
struct V_75 * V_75 ;
if ( ! V_10 || F_172 () || ( V_156 & V_158 ) )
V_10 = & V_109 ;
F_167 () ;
if ( V_10 -> V_28 == V_108 )
V_75 = F_162 ( V_156 , V_175 , F_146 ( V_10 ) ) ;
else
V_75 = F_170 ( V_156 , V_175 ,
F_144 ( V_156 , V_10 , F_34 () ) ,
F_140 ( V_156 , V_10 ) ) ;
F_168 () ;
return V_75 ;
}
struct V_9 * F_173 ( struct V_9 * V_95 )
{
struct V_9 * V_58 = F_22 ( V_39 , V_40 ) ;
if ( ! V_58 )
return F_21 ( - V_41 ) ;
if ( V_95 == V_49 -> V_9 ) {
F_85 ( V_49 ) ;
* V_58 = * V_95 ;
F_86 ( V_49 ) ;
} else
* V_58 = * V_95 ;
F_174 () ;
if ( F_175 () ) {
T_1 V_178 = V_34 ( V_49 ) ;
if ( V_58 -> V_11 & V_54 )
F_37 ( V_58 , & V_178 , V_48 ) ;
else
F_37 ( V_58 , & V_178 , V_46 ) ;
}
F_176 () ;
F_23 ( & V_58 -> V_42 , 1 ) ;
return V_58 ;
}
struct V_9 * F_177 ( struct V_9 * V_179 ,
struct V_9 * V_180 )
{
if ( ! F_169 ( V_180 ) )
return V_180 ;
* V_179 = * V_180 ;
V_179 -> V_11 &= ~ V_181 ;
F_24 ( V_180 ) ;
return V_179 ;
}
int F_178 ( struct V_9 * V_182 , struct V_9 * V_183 )
{
if ( ! V_182 || ! V_183 )
return 0 ;
if ( V_182 -> V_28 != V_183 -> V_28 )
return 0 ;
if ( V_182 -> V_11 != V_183 -> V_11 )
return 0 ;
if ( F_4 ( V_182 ) )
if ( ! F_38 ( V_182 -> V_32 . V_33 , V_183 -> V_32 . V_33 ) )
return 0 ;
switch ( V_182 -> V_28 ) {
case V_110 :
case V_108 :
return F_38 ( V_182 -> V_19 . V_17 , V_183 -> V_19 . V_17 ) ;
case V_29 :
return V_182 -> V_19 . V_21 == V_183 -> V_19 . V_21 ;
default:
F_30 () ;
return 0 ;
}
}
static struct V_184 *
F_179 ( struct V_185 * V_186 , unsigned long V_85 , unsigned long V_69 )
{
struct V_187 * V_188 = V_186 -> V_189 . V_187 ;
while ( V_188 ) {
struct V_184 * V_43 = F_180 ( V_188 , struct V_184 , V_2 ) ;
if ( V_85 >= V_43 -> V_69 )
V_188 = V_188 -> V_190 ;
else if ( V_69 <= V_43 -> V_85 )
V_188 = V_188 -> V_191 ;
else
break;
}
if ( ! V_188 )
return NULL ;
for (; ; ) {
struct V_184 * V_32 = NULL ;
struct V_187 * V_88 = F_181 ( V_188 ) ;
if ( ! V_88 )
break;
V_32 = F_180 ( V_88 , struct V_184 , V_2 ) ;
if ( V_32 -> V_69 <= V_85 )
break;
V_188 = V_88 ;
}
return F_180 ( V_188 , struct V_184 , V_2 ) ;
}
static void F_182 ( struct V_185 * V_186 , struct V_184 * V_58 )
{
struct V_187 * * V_43 = & V_186 -> V_189 . V_187 ;
struct V_187 * V_192 = NULL ;
struct V_184 * V_2 ;
while ( * V_43 ) {
V_192 = * V_43 ;
V_2 = F_180 ( V_192 , struct V_184 , V_2 ) ;
if ( V_58 -> V_85 < V_2 -> V_85 )
V_43 = & ( * V_43 ) -> V_191 ;
else if ( V_58 -> V_69 > V_2 -> V_69 )
V_43 = & ( * V_43 ) -> V_190 ;
else
F_30 () ;
}
F_183 ( & V_58 -> V_2 , V_192 , V_43 ) ;
F_184 ( & V_58 -> V_2 , & V_186 -> V_189 ) ;
F_19 ( L_4 , V_58 -> V_85 , V_58 -> V_69 ,
V_58 -> V_36 ? V_58 -> V_36 -> V_28 : 0 ) ;
}
struct V_9 *
F_185 ( struct V_185 * V_186 , unsigned long V_193 )
{
struct V_9 * V_10 = NULL ;
struct V_184 * V_194 ;
if ( ! V_186 -> V_189 . V_187 )
return NULL ;
F_186 ( & V_186 -> V_195 ) ;
V_194 = F_179 ( V_186 , V_193 , V_193 + 1 ) ;
if ( V_194 ) {
F_71 ( V_194 -> V_36 ) ;
V_10 = V_194 -> V_36 ;
}
F_187 ( & V_186 -> V_195 ) ;
return V_10 ;
}
static void F_188 ( struct V_185 * V_186 , struct V_184 * V_188 )
{
F_19 ( L_5 , V_188 -> V_85 , V_188 -> V_69 ) ;
F_189 ( & V_188 -> V_2 , & V_186 -> V_189 ) ;
F_72 ( V_188 -> V_36 ) ;
F_26 ( V_196 , V_188 ) ;
}
static struct V_184 * F_190 ( unsigned long V_85 , unsigned long V_69 ,
struct V_9 * V_10 )
{
struct V_184 * V_188 = F_22 ( V_196 , V_40 ) ;
if ( ! V_188 )
return NULL ;
V_188 -> V_85 = V_85 ;
V_188 -> V_69 = V_69 ;
F_71 ( V_10 ) ;
V_10 -> V_11 |= V_181 ;
V_188 -> V_36 = V_10 ;
return V_188 ;
}
static int F_191 ( struct V_185 * V_186 , unsigned long V_85 ,
unsigned long V_69 , struct V_184 * V_58 )
{
struct V_184 * V_188 , * V_197 = NULL ;
V_198:
F_186 ( & V_186 -> V_195 ) ;
V_188 = F_179 ( V_186 , V_85 , V_69 ) ;
while ( V_188 && V_188 -> V_85 < V_69 ) {
struct V_187 * V_82 = F_192 ( & V_188 -> V_2 ) ;
if ( V_188 -> V_85 >= V_85 ) {
if ( V_188 -> V_69 <= V_69 )
F_188 ( V_186 , V_188 ) ;
else
V_188 -> V_85 = V_69 ;
} else {
if ( V_188 -> V_69 > V_69 ) {
if ( ! V_197 ) {
F_187 ( & V_186 -> V_195 ) ;
V_197 = F_190 ( V_69 , V_188 -> V_69 , V_188 -> V_36 ) ;
if ( ! V_197 )
return - V_41 ;
goto V_198;
}
V_188 -> V_69 = V_85 ;
F_182 ( V_186 , V_197 ) ;
V_197 = NULL ;
break;
} else
V_188 -> V_69 = V_85 ;
}
if ( ! V_82 )
break;
V_188 = F_180 ( V_82 , struct V_184 , V_2 ) ;
}
if ( V_58 )
F_182 ( V_186 , V_58 ) ;
F_187 ( & V_186 -> V_195 ) ;
if ( V_197 ) {
F_72 ( V_197 -> V_36 ) ;
F_26 ( V_196 , V_197 ) ;
}
return 0 ;
}
void F_193 ( struct V_185 * V_186 , struct V_9 * V_173 )
{
int V_13 ;
V_186 -> V_189 = V_199 ;
F_194 ( & V_186 -> V_195 ) ;
if ( V_173 ) {
struct V_61 V_200 ;
struct V_9 * V_58 ;
F_82 ( V_107 ) ;
if ( ! V_107 )
goto V_201;
V_58 = F_18 ( V_173 -> V_28 , V_173 -> V_11 , & V_173 -> V_32 . V_33 ) ;
if ( F_83 ( V_58 ) )
goto V_202;
F_85 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_173 -> V_32 . V_33 , V_107 ) ;
F_86 ( V_49 ) ;
if ( V_13 )
goto V_203;
memset ( & V_200 , 0 , sizeof( struct V_61 ) ) ;
V_200 . V_92 = V_204 ;
F_195 ( V_186 , & V_200 , V_58 ) ;
V_203:
F_72 ( V_58 ) ;
V_202:
F_87 ( V_107 ) ;
V_201:
F_72 ( V_173 ) ;
}
}
int F_195 ( struct V_185 * V_205 ,
struct V_61 * V_62 , struct V_9 * V_206 )
{
int V_86 ;
struct V_184 * V_58 = NULL ;
unsigned long V_207 = F_196 ( V_62 ) ;
F_19 ( L_6 ,
V_62 -> V_96 ,
V_207 , V_206 ? V_206 -> V_28 : - 1 ,
V_206 ? V_206 -> V_11 : - 1 ,
V_206 ? F_20 ( V_206 -> V_19 . V_17 ) [ 0 ] : - 1 ) ;
if ( V_206 ) {
V_58 = F_190 ( V_62 -> V_96 , V_62 -> V_96 + V_207 , V_206 ) ;
if ( ! V_58 )
return - V_41 ;
}
V_86 = F_191 ( V_205 , V_62 -> V_96 , V_62 -> V_96 + V_207 , V_58 ) ;
if ( V_86 && V_58 )
F_26 ( V_196 , V_58 ) ;
return V_86 ;
}
void F_197 ( struct V_185 * V_43 )
{
struct V_184 * V_188 ;
struct V_187 * V_82 ;
if ( ! V_43 -> V_189 . V_187 )
return;
F_186 ( & V_43 -> V_195 ) ;
V_82 = F_198 ( & V_43 -> V_189 ) ;
while ( V_82 ) {
V_188 = F_180 ( V_82 , struct V_184 , V_2 ) ;
V_82 = F_192 ( & V_188 -> V_2 ) ;
F_189 ( & V_188 -> V_2 , & V_43 -> V_189 ) ;
F_72 ( V_188 -> V_36 ) ;
F_26 ( V_196 , V_188 ) ;
}
F_187 ( & V_43 -> V_195 ) ;
}
void T_11 F_199 ( void )
{
T_1 F_146 ;
unsigned long V_208 = 0 ;
int V_76 , V_209 = 0 ;
V_39 = F_200 ( L_7 ,
sizeof( struct V_9 ) ,
0 , V_210 , NULL ) ;
V_196 = F_200 ( L_8 ,
sizeof( struct V_184 ) ,
0 , V_210 , NULL ) ;
F_89 ( F_146 ) ;
F_201 (nid, N_HIGH_MEMORY) {
unsigned long V_211 = F_202 ( V_76 ) ;
if ( V_208 < V_211 ) {
V_208 = V_211 ;
V_209 = V_76 ;
}
if ( ( V_211 << V_168 ) >= ( 16 << 20 ) )
F_90 ( V_76 , F_146 ) ;
}
if ( F_141 ( F_10 ( F_146 ) ) )
F_90 ( V_209 , F_146 ) ;
if ( F_81 ( V_108 , 0 , & F_146 ) )
F_203 ( L_9 ) ;
}
void F_204 ( void )
{
F_81 ( V_37 , 0 , NULL ) ;
}
int F_205 ( char * V_212 , struct V_9 * * V_173 , int V_213 )
{
struct V_9 * V_58 = NULL ;
unsigned short V_28 ;
unsigned short V_131 ( V_135 ) ;
T_1 V_17 ;
char * V_214 = strchr ( V_212 , ':' ) ;
char * V_11 = strchr ( V_212 , '=' ) ;
int V_86 = 1 ;
if ( V_214 ) {
* V_214 ++ = '\0' ;
if ( F_206 ( V_214 , V_17 ) )
goto V_105;
if ( ! F_207 ( V_17 , V_26 [ V_27 ] ) )
goto V_105;
} else
F_89 ( V_17 ) ;
if ( V_11 )
* V_11 ++ = '\0' ;
for ( V_28 = 0 ; V_28 <= V_215 ; V_28 ++ ) {
if ( ! strcmp ( V_212 , V_216 [ V_28 ] ) ) {
break;
}
}
if ( V_28 > V_215 )
goto V_105;
switch ( V_28 ) {
case V_29 :
if ( V_214 ) {
char * V_217 = V_214 ;
while ( isdigit ( * V_217 ) )
V_217 ++ ;
if ( * V_217 )
goto V_105;
}
break;
case V_108 :
if ( ! V_214 )
V_17 = V_26 [ V_27 ] ;
break;
case V_215 :
if ( V_214 )
goto V_105;
V_28 = V_29 ;
break;
case V_37 :
if ( ! V_214 )
V_86 = 0 ;
goto V_105;
case V_110 :
if ( ! V_214 )
goto V_105;
}
V_135 = 0 ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_10 ) )
V_135 |= V_38 ;
else if ( ! strcmp ( V_11 , L_11 ) )
V_135 |= V_30 ;
else
goto V_105;
}
V_58 = F_18 ( V_28 , V_135 , & V_17 ) ;
if ( F_83 ( V_58 ) )
goto V_105;
if ( V_213 ) {
V_58 -> V_32 . V_33 = V_17 ;
} else {
int V_13 ;
F_82 ( V_107 ) ;
if ( V_107 ) {
F_85 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_17 , V_107 ) ;
F_86 ( V_49 ) ;
} else
V_13 = - V_41 ;
F_87 ( V_107 ) ;
if ( V_13 ) {
F_72 ( V_58 ) ;
goto V_105;
}
}
V_86 = 0 ;
V_105:
if ( V_214 )
* -- V_214 = ':' ;
if ( V_11 )
* -- V_11 = '=' ;
if ( ! V_86 )
* V_173 = V_58 ;
return V_86 ;
}
int F_208 ( char * V_218 , int V_219 , struct V_9 * V_10 , int V_213 )
{
char * V_43 = V_218 ;
int V_220 ;
T_1 V_17 ;
unsigned short V_28 ;
unsigned short V_11 = V_10 ? V_10 -> V_11 : 0 ;
F_16 ( V_219 < strlen ( L_12 ) + strlen ( L_11 ) + 16 ) ;
if ( ! V_10 || V_10 == & V_109 )
V_28 = V_37 ;
else
V_28 = V_10 -> V_28 ;
switch ( V_28 ) {
case V_37 :
F_89 ( V_17 ) ;
break;
case V_29 :
F_89 ( V_17 ) ;
if ( V_11 & V_20 )
V_28 = V_215 ;
else
F_90 ( V_10 -> V_19 . V_21 , V_17 ) ;
break;
case V_110 :
case V_108 :
if ( V_213 )
V_17 = V_10 -> V_32 . V_33 ;
else
V_17 = V_10 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
V_220 = strlen ( V_216 [ V_28 ] ) ;
if ( V_218 + V_219 < V_43 + V_220 + 1 )
return - V_221 ;
strcpy ( V_43 , V_216 [ V_28 ] ) ;
V_43 += V_220 ;
if ( V_11 & V_12 ) {
if ( V_218 + V_219 < V_43 + 2 )
return - V_221 ;
* V_43 ++ = '=' ;
if ( V_11 & V_38 )
V_43 += snprintf ( V_43 , V_218 + V_219 - V_43 , L_10 ) ;
else if ( V_11 & V_30 )
V_43 += snprintf ( V_43 , V_218 + V_219 - V_43 , L_11 ) ;
}
if ( ! F_10 ( V_17 ) ) {
if ( V_218 + V_219 < V_43 + 2 )
return - V_221 ;
* V_43 ++ = ':' ;
V_43 += F_209 ( V_43 , V_218 + V_219 - V_43 , V_17 ) ;
}
return V_43 - V_218 ;
}
