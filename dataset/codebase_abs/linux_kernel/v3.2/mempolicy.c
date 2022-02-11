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
T_7 V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
V_62 = F_74 ( V_60 , V_85 , & V_88 ) ;
if ( ! V_62 || V_62 -> V_90 > V_85 )
return - V_89 ;
if ( V_85 > V_62 -> V_90 )
V_88 = V_62 ;
for (; V_62 && V_62 -> V_90 < V_69 ; V_88 = V_62 , V_62 = V_82 ) {
V_82 = V_62 -> V_65 ;
V_102 = F_75 ( V_85 , V_62 -> V_90 ) ;
V_103 = F_76 ( V_69 , V_62 -> V_92 ) ;
if ( F_77 ( F_78 ( V_62 ) , V_100 ) )
continue;
V_101 = V_62 -> V_96 +
( ( V_102 - V_62 -> V_90 ) >> V_104 ) ;
V_88 = F_79 ( V_60 , V_88 , V_102 , V_103 , V_62 -> V_105 ,
V_62 -> V_106 , V_62 -> V_98 , V_101 ,
V_100 ) ;
if ( V_88 ) {
V_62 = V_88 ;
V_82 = V_62 -> V_65 ;
continue;
}
if ( V_62 -> V_90 != V_102 ) {
V_86 = F_80 ( V_62 -> V_74 , V_62 , V_102 , 1 ) ;
if ( V_86 )
goto V_107;
}
if ( V_62 -> V_92 != V_103 ) {
V_86 = F_80 ( V_62 -> V_74 , V_62 , V_103 , 0 ) ;
if ( V_86 )
goto V_107;
}
V_86 = F_70 ( V_62 , V_100 ) ;
if ( V_86 )
goto V_107;
}
V_107:
return V_86 ;
}
void F_81 ( struct V_56 * V_43 )
{
if ( V_43 -> V_9 )
V_43 -> V_11 |= V_108 ;
else
V_43 -> V_11 &= ~ V_108 ;
}
static void F_82 ( void )
{
F_81 ( V_49 ) ;
}
static long F_83 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_58 , * V_95 ;
struct V_59 * V_60 = V_49 -> V_60 ;
F_84 ( V_109 ) ;
int V_13 ;
if ( ! V_109 )
return - V_41 ;
V_58 = F_18 ( V_28 , V_11 , V_17 ) ;
if ( F_85 ( V_58 ) ) {
V_13 = F_86 ( V_58 ) ;
goto V_107;
}
if ( V_60 )
F_42 ( & V_60 -> V_63 ) ;
F_87 ( V_49 ) ;
V_13 = F_14 ( V_58 , V_17 , V_109 ) ;
if ( V_13 ) {
F_88 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_58 ) ;
goto V_107;
}
V_95 = V_49 -> V_9 ;
V_49 -> V_9 = V_58 ;
F_82 () ;
if ( V_58 && V_58 -> V_28 == V_110 &&
F_7 ( V_58 -> V_19 . V_17 ) )
V_49 -> V_50 = F_12 ( V_58 -> V_19 . V_17 ) ;
F_88 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_95 ) ;
V_13 = 0 ;
V_107:
F_89 ( V_109 ) ;
return V_13 ;
}
static void F_90 ( struct V_9 * V_43 , T_1 * V_17 )
{
F_91 ( * V_17 ) ;
if ( V_43 == & V_111 )
return;
switch ( V_43 -> V_28 ) {
case V_112 :
case V_110 :
* V_17 = V_43 -> V_19 . V_17 ;
break;
case V_29 :
if ( ! ( V_43 -> V_11 & V_20 ) )
F_92 ( V_43 -> V_19 . V_21 , * V_17 ) ;
break;
default:
F_30 () ;
}
}
static int F_93 ( struct V_59 * V_60 , unsigned long V_68 )
{
struct V_75 * V_43 ;
int V_86 ;
V_86 = F_94 ( V_49 , V_60 , V_68 & V_113 , 1 , 0 , 0 , & V_43 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_50 ( V_43 ) ;
F_95 ( V_43 ) ;
}
return V_86 ;
}
static long F_96 ( int * V_36 , T_1 * V_114 ,
unsigned long V_68 , unsigned long V_11 )
{
int V_86 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_61 * V_62 = NULL ;
struct V_9 * V_10 = V_49 -> V_9 ;
if ( V_11 &
~ ( unsigned long ) ( V_115 | V_116 | V_117 ) )
return - V_18 ;
if ( V_11 & V_117 ) {
if ( V_11 & ( V_115 | V_116 ) )
return - V_18 ;
* V_36 = 0 ;
F_87 ( V_49 ) ;
* V_114 = V_25 ;
F_88 ( V_49 ) ;
return 0 ;
}
if ( V_11 & V_116 ) {
F_97 ( & V_60 -> V_63 ) ;
V_62 = F_98 ( V_60 , V_68 , V_68 + 1 ) ;
if ( ! V_62 ) {
F_99 ( & V_60 -> V_63 ) ;
return - V_89 ;
}
if ( V_62 -> V_97 && V_62 -> V_97 -> V_118 )
V_10 = V_62 -> V_97 -> V_118 ( V_62 , V_68 ) ;
else
V_10 = V_62 -> V_66 ;
} else if ( V_68 )
return - V_18 ;
if ( ! V_10 )
V_10 = & V_111 ;
if ( V_11 & V_115 ) {
if ( V_11 & V_116 ) {
V_86 = F_93 ( V_60 , V_68 ) ;
if ( V_86 < 0 )
goto V_107;
* V_36 = V_86 ;
} else if ( V_10 == V_49 -> V_9 &&
V_10 -> V_28 == V_110 ) {
* V_36 = V_49 -> V_50 ;
} else {
V_86 = - V_18 ;
goto V_107;
}
} else {
* V_36 = V_10 == & V_111 ? V_37 :
V_10 -> V_28 ;
* V_36 |= ( V_10 -> V_11 & V_12 ) ;
}
if ( V_62 ) {
F_99 ( & V_49 -> V_60 -> V_63 ) ;
V_62 = NULL ;
}
V_86 = 0 ;
if ( V_114 ) {
if ( F_4 ( V_10 ) ) {
* V_114 = V_10 -> V_32 . V_33 ;
} else {
F_87 ( V_49 ) ;
F_90 ( V_10 , V_114 ) ;
F_88 ( V_49 ) ;
}
}
V_107:
F_100 ( V_10 ) ;
if ( V_62 )
F_99 ( & V_49 -> V_60 -> V_63 ) ;
return V_86 ;
}
static void F_51 ( struct V_75 * V_75 , struct V_119 * V_120 ,
unsigned long V_11 )
{
if ( ( V_11 & V_79 ) || F_101 ( V_75 ) == 1 ) {
if ( ! F_102 ( V_75 ) ) {
F_103 ( & V_75 -> V_121 , V_120 ) ;
F_104 ( V_75 , V_122 +
F_105 ( V_75 ) ) ;
}
}
}
static struct V_75 * F_106 ( struct V_75 * V_75 , unsigned long V_52 , int * * V_123 )
{
return F_107 ( V_52 , V_124 , 0 ) ;
}
static int F_108 ( struct V_59 * V_60 , int V_125 , int V_126 ,
int V_11 )
{
T_1 V_114 ;
F_109 ( V_120 ) ;
int V_86 = 0 ;
struct V_61 * V_62 ;
F_91 ( V_114 ) ;
F_92 ( V_125 , V_114 ) ;
V_62 = F_66 ( V_60 , V_60 -> V_64 -> V_90 , V_60 -> V_127 , & V_114 ,
V_11 | V_91 , & V_120 ) ;
if ( F_85 ( V_62 ) )
return F_86 ( V_62 ) ;
if ( ! F_110 ( & V_120 ) ) {
V_86 = F_111 ( & V_120 , F_106 , V_126 ,
false , true ) ;
if ( V_86 )
F_112 ( & V_120 ) ;
}
return V_86 ;
}
int F_113 ( struct V_59 * V_60 ,
const T_1 * V_128 , const T_1 * V_129 , int V_11 )
{
int V_130 = 0 ;
int V_86 ;
T_1 V_16 ;
V_86 = F_114 () ;
if ( V_86 )
return V_86 ;
F_97 ( & V_60 -> V_63 ) ;
V_86 = F_115 ( V_60 , V_128 , V_129 , V_11 ) ;
if ( V_86 )
goto V_107;
V_16 = * V_128 ;
while ( ! F_10 ( V_16 ) ) {
int V_131 , V_132 ;
int V_125 = - 1 ;
int V_126 = 0 ;
F_2 (s, tmp) {
V_132 = F_36 ( V_131 , * V_128 , * V_129 ) ;
if ( V_131 == V_132 )
continue;
V_125 = V_131 ;
V_126 = V_132 ;
if ( ! F_32 ( V_126 , V_16 ) )
break;
}
if ( V_125 == - 1 )
break;
F_116 ( V_125 , V_16 ) ;
V_86 = F_108 ( V_60 , V_125 , V_126 , V_11 ) ;
if ( V_86 > 0 )
V_130 += V_86 ;
if ( V_86 < 0 )
break;
}
V_107:
F_99 ( & V_60 -> V_63 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_130 ;
}
static struct V_75 * F_117 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_123 )
{
struct V_61 * V_62 = (struct V_61 * ) V_70 ;
unsigned long V_133 ( V_134 ) ;
while ( V_62 ) {
V_134 = F_118 ( V_75 , V_62 ) ;
if ( V_134 != - V_89 )
break;
V_62 = V_62 -> V_65 ;
}
return F_119 ( V_124 , V_62 , V_134 ) ;
}
static void F_51 ( struct V_75 * V_75 , struct V_119 * V_120 ,
unsigned long V_11 )
{
}
int F_113 ( struct V_59 * V_60 ,
const T_1 * V_128 , const T_1 * V_129 , int V_11 )
{
return - V_135 ;
}
static struct V_75 * F_117 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_123 )
{
return NULL ;
}
static long F_120 ( unsigned long V_85 , unsigned long V_136 ,
unsigned short V_28 , unsigned short V_137 ,
T_1 * V_114 , unsigned long V_11 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_9 * V_58 ;
unsigned long V_69 ;
int V_86 ;
F_109 ( V_120 ) ;
if ( V_11 & ~ ( unsigned long ) ( V_93 |
V_78 | V_79 ) )
return - V_18 ;
if ( ( V_11 & V_79 ) && ! F_121 ( V_138 ) )
return - V_139 ;
if ( V_85 & ~ V_113 )
return - V_18 ;
if ( V_28 == V_37 )
V_11 &= ~ V_93 ;
V_136 = ( V_136 + V_80 - 1 ) & V_113 ;
V_69 = V_85 + V_136 ;
if ( V_69 < V_85 )
return - V_18 ;
if ( V_69 == V_85 )
return 0 ;
V_58 = F_18 ( V_28 , V_137 , V_114 ) ;
if ( F_85 ( V_58 ) )
return F_86 ( V_58 ) ;
if ( ! V_58 )
V_11 |= V_91 ;
F_19 ( L_3 ,
V_85 , V_85 + V_136 , V_28 , V_137 ,
V_114 ? F_20 ( * V_114 ) [ 0 ] : - 1 ) ;
if ( V_11 & ( V_78 | V_79 ) ) {
V_86 = F_114 () ;
if ( V_86 )
goto V_140;
}
{
F_84 ( V_109 ) ;
if ( V_109 ) {
F_42 ( & V_60 -> V_63 ) ;
F_87 ( V_49 ) ;
V_86 = F_14 ( V_58 , V_114 , V_109 ) ;
F_88 ( V_49 ) ;
if ( V_86 )
F_43 ( & V_60 -> V_63 ) ;
} else
V_86 = - V_41 ;
F_89 ( V_109 ) ;
}
if ( V_86 )
goto V_140;
V_62 = F_66 ( V_60 , V_85 , V_69 , V_114 ,
V_11 | V_77 , & V_120 ) ;
V_86 = F_86 ( V_62 ) ;
if ( ! F_85 ( V_62 ) ) {
int V_141 = 0 ;
V_86 = F_73 ( V_60 , V_85 , V_69 , V_58 ) ;
if ( ! F_110 ( & V_120 ) ) {
V_141 = F_111 ( & V_120 , F_117 ,
( unsigned long ) V_62 ,
false , true ) ;
if ( V_141 )
F_112 ( & V_120 ) ;
}
if ( ! V_86 && V_141 && ( V_11 & V_93 ) )
V_86 = - V_83 ;
} else
F_112 ( & V_120 ) ;
F_43 ( & V_60 -> V_63 ) ;
V_140:
F_72 ( V_58 ) ;
return V_86 ;
}
static int F_122 ( T_1 * V_17 , const unsigned long T_8 * V_114 ,
unsigned long V_142 )
{
unsigned long V_3 ;
unsigned long V_143 ;
unsigned long V_144 ;
-- V_142 ;
F_91 ( * V_17 ) ;
if ( V_142 == 0 || ! V_114 )
return 0 ;
if ( V_142 > V_80 * V_145 )
return - V_18 ;
V_143 = F_123 ( V_142 ) ;
if ( ( V_142 % V_146 ) == 0 )
V_144 = ~ 0UL ;
else
V_144 = ( 1UL << ( V_142 % V_146 ) ) - 1 ;
if ( V_143 > F_123 ( V_51 ) ) {
if ( V_143 > V_80 / sizeof( long ) )
return - V_18 ;
for ( V_3 = F_123 ( V_51 ) ; V_3 < V_143 ; V_3 ++ ) {
unsigned long V_147 ;
if ( F_124 ( V_147 , V_114 + V_3 ) )
return - V_89 ;
if ( V_3 == V_143 - 1 ) {
if ( V_147 & V_144 )
return - V_18 ;
} else if ( V_147 )
return - V_18 ;
}
V_143 = F_123 ( V_51 ) ;
V_144 = ~ 0UL ;
}
if ( F_125 ( F_20 ( * V_17 ) , V_114 , V_143 *sizeof( unsigned long ) ) )
return - V_89 ;
F_20 ( * V_17 ) [ V_143 - 1 ] &= V_144 ;
return 0 ;
}
static int F_126 ( unsigned long T_8 * V_148 , unsigned long V_142 ,
T_1 * V_17 )
{
unsigned long V_149 = F_127 ( V_142 - 1 , 64 ) / 8 ;
const int V_150 = F_123 ( V_51 ) * sizeof( long ) ;
if ( V_149 > V_150 ) {
if ( V_149 > V_80 )
return - V_18 ;
if ( F_128 ( ( char T_8 * ) V_148 + V_150 , V_149 - V_150 ) )
return - V_89 ;
V_149 = V_150 ;
}
return F_129 ( V_148 , F_20 ( * V_17 ) , V_149 ) ? - V_89 : 0 ;
}
T_9 long F_130 ( int T_8 * V_36 ,
T_10 T_8 * V_114 ,
T_10 V_142 ,
T_10 V_68 , T_10 V_11 )
{
long V_86 ;
unsigned long T_8 * V_151 = NULL ;
unsigned long V_152 , V_153 ;
F_131 ( V_154 , V_51 ) ;
V_152 = F_132 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_153 = F_127 ( V_152 , V_146 ) / 8 ;
if ( V_114 )
V_151 = F_133 ( V_153 ) ;
V_86 = F_134 ( V_36 , V_151 , V_152 + 1 , V_68 , V_11 ) ;
if ( ! V_86 && V_114 ) {
unsigned long V_155 ;
V_155 = F_132 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_125 ( V_154 , V_151 , V_155 ) ;
V_86 |= F_128 ( V_114 , F_127 ( V_142 - 1 , 8 ) / 8 ) ;
V_86 |= F_135 ( V_114 , V_154 , V_152 ) ;
}
return V_86 ;
}
T_9 long F_136 ( int V_28 , T_10 T_8 * V_114 ,
T_10 V_142 )
{
long V_86 = 0 ;
unsigned long T_8 * V_151 = NULL ;
unsigned long V_152 , V_153 ;
F_131 ( V_154 , V_51 ) ;
V_152 = F_132 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_153 = F_127 ( V_152 , V_146 ) / 8 ;
if ( V_114 ) {
V_86 = F_137 ( V_154 , V_114 , V_152 ) ;
V_151 = F_133 ( V_153 ) ;
V_86 |= F_129 ( V_151 , V_154 , V_153 ) ;
}
if ( V_86 )
return - V_89 ;
return F_138 ( V_28 , V_151 , V_152 + 1 ) ;
}
T_9 long F_139 ( T_10 V_85 , T_10 V_136 ,
T_10 V_28 , T_10 T_8 * V_114 ,
T_10 V_142 , T_10 V_11 )
{
long V_86 = 0 ;
unsigned long T_8 * V_151 = NULL ;
unsigned long V_152 , V_153 ;
T_1 V_154 ;
V_152 = F_132 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_153 = F_127 ( V_152 , V_146 ) / 8 ;
if ( V_114 ) {
V_86 = F_137 ( F_20 ( V_154 ) , V_114 , V_152 ) ;
V_151 = F_133 ( V_153 ) ;
V_86 |= F_129 ( V_151 , F_20 ( V_154 ) , V_153 ) ;
}
if ( V_86 )
return - V_89 ;
return F_140 ( V_85 , V_136 , V_28 , V_151 , V_152 + 1 , V_11 ) ;
}
struct V_9 * F_141 ( struct V_56 * V_156 ,
struct V_61 * V_62 , unsigned long V_68 )
{
struct V_9 * V_10 = V_156 -> V_9 ;
if ( V_62 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_118 ) {
struct V_9 * V_157 = V_62 -> V_97 -> V_118 ( V_62 ,
V_68 ) ;
if ( V_157 )
V_10 = V_157 ;
} else if ( V_62 -> V_66 )
V_10 = V_62 -> V_66 ;
}
if ( ! V_10 )
V_10 = & V_111 ;
return V_10 ;
}
static T_1 * F_142 ( T_11 V_158 , struct V_9 * V_36 )
{
if ( F_143 ( V_36 -> V_28 == V_112 ) &&
F_144 ( V_158 ) >= V_6 &&
F_145 ( & V_36 -> V_19 . V_17 ) )
return & V_36 -> V_19 . V_17 ;
return NULL ;
}
static struct V_159 * F_146 ( T_11 V_158 , struct V_9 * V_36 ,
int V_2 )
{
switch ( V_36 -> V_28 ) {
case V_29 :
if ( ! ( V_36 -> V_11 & V_20 ) )
V_2 = V_36 -> V_19 . V_21 ;
break;
case V_112 :
if ( F_143 ( V_158 & V_160 ) &&
F_143 ( ! F_32 ( V_2 , V_36 -> V_19 . V_17 ) ) )
V_2 = F_12 ( V_36 -> V_19 . V_17 ) ;
break;
default:
F_30 () ;
}
return F_147 ( V_2 , V_158 ) ;
}
static unsigned F_148 ( struct V_9 * V_36 )
{
unsigned V_76 , V_82 ;
struct V_56 * V_161 = V_49 ;
V_76 = V_161 -> V_50 ;
V_82 = F_33 ( V_76 , V_36 -> V_19 . V_17 ) ;
if ( V_82 >= V_51 )
V_82 = F_12 ( V_36 -> V_19 . V_17 ) ;
if ( V_82 < V_51 )
V_161 -> V_50 = V_82 ;
return V_76 ;
}
unsigned F_149 ( struct V_9 * V_36 )
{
if ( ! V_36 || V_36 -> V_11 & V_20 )
return F_34 () ;
switch ( V_36 -> V_28 ) {
case V_29 :
return V_36 -> V_19 . V_21 ;
case V_110 :
return F_148 ( V_36 ) ;
case V_112 : {
struct V_159 * V_159 ;
struct V_4 * V_4 ;
enum V_162 V_163 = F_144 ( V_40 ) ;
V_159 = & F_3 ( F_34 () ) -> V_164 [ 0 ] ;
( void ) F_150 ( V_159 , V_163 ,
& V_36 -> V_19 . V_17 ,
& V_4 ) ;
return V_4 ? V_4 -> V_52 : F_34 () ;
}
default:
F_30 () ;
}
}
static unsigned F_151 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_165 )
{
unsigned V_166 = F_7 ( V_10 -> V_19 . V_17 ) ;
unsigned V_167 ;
int V_168 ;
int V_76 = - 1 ;
if ( ! V_166 )
return F_34 () ;
V_167 = ( unsigned int ) V_165 % V_166 ;
V_168 = 0 ;
do {
V_76 = F_33 ( V_76 , V_10 -> V_19 . V_17 ) ;
V_168 ++ ;
} while ( V_168 <= V_167 );
return V_76 ;
}
static inline unsigned F_152 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_68 , int V_169 )
{
if ( V_62 ) {
unsigned long V_165 ;
F_153 ( V_169 < V_104 ) ;
V_165 = V_62 -> V_96 >> ( V_169 - V_104 ) ;
V_165 += ( V_68 - V_62 -> V_90 ) >> V_169 ;
return F_151 ( V_10 , V_62 , V_165 ) ;
} else
return F_148 ( V_10 ) ;
}
int F_154 ( const T_1 * V_170 )
{
int V_32 , V_171 = - 1 ;
V_32 = F_7 ( * V_170 ) ;
if ( V_32 )
V_171 = F_155 ( V_170 -> V_172 ,
F_156 () % V_32 , V_51 ) ;
return V_171 ;
}
struct V_159 * F_157 ( struct V_61 * V_62 , unsigned long V_68 ,
T_11 V_173 , struct V_9 * * V_174 ,
T_1 * * V_1 )
{
struct V_159 * V_175 ;
* V_174 = F_141 ( V_49 , V_62 , V_68 ) ;
* V_1 = NULL ;
if ( F_143 ( ( * V_174 ) -> V_28 == V_110 ) ) {
V_175 = F_147 ( F_152 ( * V_174 , V_62 , V_68 ,
F_158 ( F_159 ( V_62 ) ) ) , V_173 ) ;
} else {
V_175 = F_146 ( V_173 , * V_174 , F_34 () ) ;
if ( ( * V_174 ) -> V_28 == V_112 )
* V_1 = & ( * V_174 ) -> V_19 . V_17 ;
}
return V_175 ;
}
bool F_160 ( T_1 * V_148 )
{
struct V_9 * V_9 ;
int V_76 ;
if ( ! ( V_148 && V_49 -> V_9 ) )
return false ;
F_87 ( V_49 ) ;
V_9 = V_49 -> V_9 ;
switch ( V_9 -> V_28 ) {
case V_29 :
if ( V_9 -> V_11 & V_20 )
V_76 = F_34 () ;
else
V_76 = V_9 -> V_19 . V_21 ;
F_161 ( V_148 , V_76 ) ;
break;
case V_112 :
case V_110 :
* V_148 = V_9 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
F_88 ( V_49 ) ;
return true ;
}
bool F_162 ( struct V_56 * V_57 ,
const T_1 * V_148 )
{
struct V_9 * V_9 ;
bool V_13 = true ;
if ( ! V_148 )
return V_13 ;
F_87 ( V_57 ) ;
V_9 = V_57 -> V_9 ;
if ( ! V_9 )
goto V_107;
switch ( V_9 -> V_28 ) {
case V_29 :
break;
case V_112 :
case V_110 :
V_13 = F_163 ( V_9 -> V_19 . V_17 , * V_148 ) ;
break;
default:
F_30 () ;
}
V_107:
F_88 ( V_57 ) ;
return V_13 ;
}
static struct V_75 * F_164 ( T_11 V_158 , unsigned V_176 ,
unsigned V_76 )
{
struct V_159 * V_175 ;
struct V_75 * V_75 ;
V_175 = F_147 ( V_76 , V_158 ) ;
V_75 = F_165 ( V_158 , V_176 , V_175 ) ;
if ( V_75 && F_166 ( V_75 ) == F_167 ( & V_175 -> V_177 [ 0 ] ) )
F_104 ( V_75 , V_178 ) ;
return V_75 ;
}
struct V_75 *
F_168 ( T_11 V_158 , int V_176 , struct V_61 * V_62 ,
unsigned long V_68 , int V_52 )
{
struct V_9 * V_10 = F_141 ( V_49 , V_62 , V_68 ) ;
struct V_159 * V_175 ;
struct V_75 * V_75 ;
F_169 () ;
if ( F_143 ( V_10 -> V_28 == V_110 ) ) {
unsigned V_76 ;
V_76 = F_152 ( V_10 , V_62 , V_68 , V_104 + V_176 ) ;
F_100 ( V_10 ) ;
V_75 = F_164 ( V_158 , V_176 , V_76 ) ;
F_170 () ;
return V_75 ;
}
V_175 = F_146 ( V_158 , V_10 , V_52 ) ;
if ( F_143 ( F_171 ( V_10 ) ) ) {
struct V_75 * V_75 = F_172 ( V_158 , V_176 ,
V_175 , F_142 ( V_158 , V_10 ) ) ;
F_24 ( V_10 ) ;
F_170 () ;
return V_75 ;
}
V_75 = F_172 ( V_158 , V_176 , V_175 ,
F_142 ( V_158 , V_10 ) ) ;
F_170 () ;
return V_75 ;
}
struct V_75 * F_173 ( T_11 V_158 , unsigned V_176 )
{
struct V_9 * V_10 = V_49 -> V_9 ;
struct V_75 * V_75 ;
if ( ! V_10 || F_174 () || ( V_158 & V_160 ) )
V_10 = & V_111 ;
F_169 () ;
if ( V_10 -> V_28 == V_110 )
V_75 = F_164 ( V_158 , V_176 , F_148 ( V_10 ) ) ;
else
V_75 = F_172 ( V_158 , V_176 ,
F_146 ( V_158 , V_10 , F_34 () ) ,
F_142 ( V_158 , V_10 ) ) ;
F_170 () ;
return V_75 ;
}
struct V_9 * F_175 ( struct V_9 * V_95 )
{
struct V_9 * V_58 = F_22 ( V_39 , V_40 ) ;
if ( ! V_58 )
return F_21 ( - V_41 ) ;
if ( V_95 == V_49 -> V_9 ) {
F_87 ( V_49 ) ;
* V_58 = * V_95 ;
F_88 ( V_49 ) ;
} else
* V_58 = * V_95 ;
F_176 () ;
if ( F_177 () ) {
T_1 V_179 = V_34 ( V_49 ) ;
if ( V_58 -> V_11 & V_54 )
F_37 ( V_58 , & V_179 , V_48 ) ;
else
F_37 ( V_58 , & V_179 , V_46 ) ;
}
F_178 () ;
F_23 ( & V_58 -> V_42 , 1 ) ;
return V_58 ;
}
struct V_9 * F_179 ( struct V_9 * V_180 ,
struct V_9 * V_181 )
{
if ( ! F_171 ( V_181 ) )
return V_181 ;
* V_180 = * V_181 ;
V_180 -> V_11 &= ~ V_182 ;
F_24 ( V_181 ) ;
return V_180 ;
}
int F_180 ( struct V_9 * V_183 , struct V_9 * V_184 )
{
if ( ! V_183 || ! V_184 )
return 0 ;
if ( V_183 -> V_28 != V_184 -> V_28 )
return 0 ;
if ( V_183 -> V_11 != V_184 -> V_11 )
return 0 ;
if ( F_4 ( V_183 ) )
if ( ! F_38 ( V_183 -> V_32 . V_33 , V_184 -> V_32 . V_33 ) )
return 0 ;
switch ( V_183 -> V_28 ) {
case V_112 :
case V_110 :
return F_38 ( V_183 -> V_19 . V_17 , V_184 -> V_19 . V_17 ) ;
case V_29 :
return V_183 -> V_19 . V_21 == V_184 -> V_19 . V_21 ;
default:
F_30 () ;
return 0 ;
}
}
static struct V_185 *
F_181 ( struct V_186 * V_187 , unsigned long V_85 , unsigned long V_69 )
{
struct V_188 * V_189 = V_187 -> V_190 . V_188 ;
while ( V_189 ) {
struct V_185 * V_43 = F_182 ( V_189 , struct V_185 , V_2 ) ;
if ( V_85 >= V_43 -> V_69 )
V_189 = V_189 -> V_191 ;
else if ( V_69 <= V_43 -> V_85 )
V_189 = V_189 -> V_192 ;
else
break;
}
if ( ! V_189 )
return NULL ;
for (; ; ) {
struct V_185 * V_32 = NULL ;
struct V_188 * V_88 = F_183 ( V_189 ) ;
if ( ! V_88 )
break;
V_32 = F_182 ( V_88 , struct V_185 , V_2 ) ;
if ( V_32 -> V_69 <= V_85 )
break;
V_189 = V_88 ;
}
return F_182 ( V_189 , struct V_185 , V_2 ) ;
}
static void F_184 ( struct V_186 * V_187 , struct V_185 * V_58 )
{
struct V_188 * * V_43 = & V_187 -> V_190 . V_188 ;
struct V_188 * V_193 = NULL ;
struct V_185 * V_2 ;
while ( * V_43 ) {
V_193 = * V_43 ;
V_2 = F_182 ( V_193 , struct V_185 , V_2 ) ;
if ( V_58 -> V_85 < V_2 -> V_85 )
V_43 = & ( * V_43 ) -> V_192 ;
else if ( V_58 -> V_69 > V_2 -> V_69 )
V_43 = & ( * V_43 ) -> V_191 ;
else
F_30 () ;
}
F_185 ( & V_58 -> V_2 , V_193 , V_43 ) ;
F_186 ( & V_58 -> V_2 , & V_187 -> V_190 ) ;
F_19 ( L_4 , V_58 -> V_85 , V_58 -> V_69 ,
V_58 -> V_36 ? V_58 -> V_36 -> V_28 : 0 ) ;
}
struct V_9 *
F_187 ( struct V_186 * V_187 , unsigned long V_194 )
{
struct V_9 * V_10 = NULL ;
struct V_185 * V_195 ;
if ( ! V_187 -> V_190 . V_188 )
return NULL ;
F_188 ( & V_187 -> V_196 ) ;
V_195 = F_181 ( V_187 , V_194 , V_194 + 1 ) ;
if ( V_195 ) {
F_71 ( V_195 -> V_36 ) ;
V_10 = V_195 -> V_36 ;
}
F_189 ( & V_187 -> V_196 ) ;
return V_10 ;
}
static void F_190 ( struct V_186 * V_187 , struct V_185 * V_189 )
{
F_19 ( L_5 , V_189 -> V_85 , V_189 -> V_69 ) ;
F_191 ( & V_189 -> V_2 , & V_187 -> V_190 ) ;
F_72 ( V_189 -> V_36 ) ;
F_26 ( V_197 , V_189 ) ;
}
static struct V_185 * F_192 ( unsigned long V_85 , unsigned long V_69 ,
struct V_9 * V_10 )
{
struct V_185 * V_189 = F_22 ( V_197 , V_40 ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_85 = V_85 ;
V_189 -> V_69 = V_69 ;
F_71 ( V_10 ) ;
V_10 -> V_11 |= V_182 ;
V_189 -> V_36 = V_10 ;
return V_189 ;
}
static int F_193 ( struct V_186 * V_187 , unsigned long V_85 ,
unsigned long V_69 , struct V_185 * V_58 )
{
struct V_185 * V_189 , * V_198 = NULL ;
V_199:
F_188 ( & V_187 -> V_196 ) ;
V_189 = F_181 ( V_187 , V_85 , V_69 ) ;
while ( V_189 && V_189 -> V_85 < V_69 ) {
struct V_188 * V_82 = F_194 ( & V_189 -> V_2 ) ;
if ( V_189 -> V_85 >= V_85 ) {
if ( V_189 -> V_69 <= V_69 )
F_190 ( V_187 , V_189 ) ;
else
V_189 -> V_85 = V_69 ;
} else {
if ( V_189 -> V_69 > V_69 ) {
if ( ! V_198 ) {
F_189 ( & V_187 -> V_196 ) ;
V_198 = F_192 ( V_69 , V_189 -> V_69 , V_189 -> V_36 ) ;
if ( ! V_198 )
return - V_41 ;
goto V_199;
}
V_189 -> V_69 = V_85 ;
F_184 ( V_187 , V_198 ) ;
V_198 = NULL ;
break;
} else
V_189 -> V_69 = V_85 ;
}
if ( ! V_82 )
break;
V_189 = F_182 ( V_82 , struct V_185 , V_2 ) ;
}
if ( V_58 )
F_184 ( V_187 , V_58 ) ;
F_189 ( & V_187 -> V_196 ) ;
if ( V_198 ) {
F_72 ( V_198 -> V_36 ) ;
F_26 ( V_197 , V_198 ) ;
}
return 0 ;
}
void F_195 ( struct V_186 * V_187 , struct V_9 * V_174 )
{
int V_13 ;
V_187 -> V_190 = V_200 ;
F_196 ( & V_187 -> V_196 ) ;
if ( V_174 ) {
struct V_61 V_201 ;
struct V_9 * V_58 ;
F_84 ( V_109 ) ;
if ( ! V_109 )
goto V_202;
V_58 = F_18 ( V_174 -> V_28 , V_174 -> V_11 , & V_174 -> V_32 . V_33 ) ;
if ( F_85 ( V_58 ) )
goto V_203;
F_87 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_174 -> V_32 . V_33 , V_109 ) ;
F_88 ( V_49 ) ;
if ( V_13 )
goto V_204;
memset ( & V_201 , 0 , sizeof( struct V_61 ) ) ;
V_201 . V_92 = V_205 ;
F_197 ( V_187 , & V_201 , V_58 ) ;
V_204:
F_72 ( V_58 ) ;
V_203:
F_89 ( V_109 ) ;
V_202:
F_72 ( V_174 ) ;
}
}
int F_197 ( struct V_186 * V_206 ,
struct V_61 * V_62 , struct V_9 * V_207 )
{
int V_86 ;
struct V_185 * V_58 = NULL ;
unsigned long V_208 = F_198 ( V_62 ) ;
F_19 ( L_6 ,
V_62 -> V_96 ,
V_208 , V_207 ? V_207 -> V_28 : - 1 ,
V_207 ? V_207 -> V_11 : - 1 ,
V_207 ? F_20 ( V_207 -> V_19 . V_17 ) [ 0 ] : - 1 ) ;
if ( V_207 ) {
V_58 = F_192 ( V_62 -> V_96 , V_62 -> V_96 + V_208 , V_207 ) ;
if ( ! V_58 )
return - V_41 ;
}
V_86 = F_193 ( V_206 , V_62 -> V_96 , V_62 -> V_96 + V_208 , V_58 ) ;
if ( V_86 && V_58 )
F_26 ( V_197 , V_58 ) ;
return V_86 ;
}
void F_199 ( struct V_186 * V_43 )
{
struct V_185 * V_189 ;
struct V_188 * V_82 ;
if ( ! V_43 -> V_190 . V_188 )
return;
F_188 ( & V_43 -> V_196 ) ;
V_82 = F_200 ( & V_43 -> V_190 ) ;
while ( V_82 ) {
V_189 = F_182 ( V_82 , struct V_185 , V_2 ) ;
V_82 = F_194 ( & V_189 -> V_2 ) ;
F_191 ( & V_189 -> V_2 , & V_43 -> V_190 ) ;
F_72 ( V_189 -> V_36 ) ;
F_26 ( V_197 , V_189 ) ;
}
F_189 ( & V_43 -> V_196 ) ;
}
void T_12 F_201 ( void )
{
T_1 F_148 ;
unsigned long V_209 = 0 ;
int V_76 , V_210 = 0 ;
V_39 = F_202 ( L_7 ,
sizeof( struct V_9 ) ,
0 , V_211 , NULL ) ;
V_197 = F_202 ( L_8 ,
sizeof( struct V_185 ) ,
0 , V_211 , NULL ) ;
F_91 ( F_148 ) ;
F_203 (nid, N_HIGH_MEMORY) {
unsigned long V_212 = F_204 ( V_76 ) ;
if ( V_209 < V_212 ) {
V_209 = V_212 ;
V_210 = V_76 ;
}
if ( ( V_212 << V_104 ) >= ( 16 << 20 ) )
F_92 ( V_76 , F_148 ) ;
}
if ( F_143 ( F_10 ( F_148 ) ) )
F_92 ( V_210 , F_148 ) ;
if ( F_83 ( V_110 , 0 , & F_148 ) )
F_205 ( L_9 ) ;
}
void F_206 ( void )
{
F_83 ( V_37 , 0 , NULL ) ;
}
int F_207 ( char * V_213 , struct V_9 * * V_174 , int V_214 )
{
struct V_9 * V_58 = NULL ;
unsigned short V_28 ;
unsigned short V_133 ( V_137 ) ;
T_1 V_17 ;
char * V_215 = strchr ( V_213 , ':' ) ;
char * V_11 = strchr ( V_213 , '=' ) ;
int V_86 = 1 ;
if ( V_215 ) {
* V_215 ++ = '\0' ;
if ( F_208 ( V_215 , V_17 ) )
goto V_107;
if ( ! F_209 ( V_17 , V_26 [ V_27 ] ) )
goto V_107;
} else
F_91 ( V_17 ) ;
if ( V_11 )
* V_11 ++ = '\0' ;
for ( V_28 = 0 ; V_28 <= V_216 ; V_28 ++ ) {
if ( ! strcmp ( V_213 , V_217 [ V_28 ] ) ) {
break;
}
}
if ( V_28 > V_216 )
goto V_107;
switch ( V_28 ) {
case V_29 :
if ( V_215 ) {
char * V_218 = V_215 ;
while ( isdigit ( * V_218 ) )
V_218 ++ ;
if ( * V_218 )
goto V_107;
}
break;
case V_110 :
if ( ! V_215 )
V_17 = V_26 [ V_27 ] ;
break;
case V_216 :
if ( V_215 )
goto V_107;
V_28 = V_29 ;
break;
case V_37 :
if ( ! V_215 )
V_86 = 0 ;
goto V_107;
case V_112 :
if ( ! V_215 )
goto V_107;
}
V_137 = 0 ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_10 ) )
V_137 |= V_38 ;
else if ( ! strcmp ( V_11 , L_11 ) )
V_137 |= V_30 ;
else
goto V_107;
}
V_58 = F_18 ( V_28 , V_137 , & V_17 ) ;
if ( F_85 ( V_58 ) )
goto V_107;
if ( V_214 ) {
V_58 -> V_32 . V_33 = V_17 ;
} else {
int V_13 ;
F_84 ( V_109 ) ;
if ( V_109 ) {
F_87 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_17 , V_109 ) ;
F_88 ( V_49 ) ;
} else
V_13 = - V_41 ;
F_89 ( V_109 ) ;
if ( V_13 ) {
F_72 ( V_58 ) ;
goto V_107;
}
}
V_86 = 0 ;
V_107:
if ( V_215 )
* -- V_215 = ':' ;
if ( V_11 )
* -- V_11 = '=' ;
if ( ! V_86 )
* V_174 = V_58 ;
return V_86 ;
}
int F_210 ( char * V_219 , int V_220 , struct V_9 * V_10 , int V_214 )
{
char * V_43 = V_219 ;
int V_221 ;
T_1 V_17 ;
unsigned short V_28 ;
unsigned short V_11 = V_10 ? V_10 -> V_11 : 0 ;
F_16 ( V_220 < strlen ( L_12 ) + strlen ( L_11 ) + 16 ) ;
if ( ! V_10 || V_10 == & V_111 )
V_28 = V_37 ;
else
V_28 = V_10 -> V_28 ;
switch ( V_28 ) {
case V_37 :
F_91 ( V_17 ) ;
break;
case V_29 :
F_91 ( V_17 ) ;
if ( V_11 & V_20 )
V_28 = V_216 ;
else
F_92 ( V_10 -> V_19 . V_21 , V_17 ) ;
break;
case V_112 :
case V_110 :
if ( V_214 )
V_17 = V_10 -> V_32 . V_33 ;
else
V_17 = V_10 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
V_221 = strlen ( V_217 [ V_28 ] ) ;
if ( V_219 + V_220 < V_43 + V_221 + 1 )
return - V_222 ;
strcpy ( V_43 , V_217 [ V_28 ] ) ;
V_43 += V_221 ;
if ( V_11 & V_12 ) {
if ( V_219 + V_220 < V_43 + 2 )
return - V_222 ;
* V_43 ++ = '=' ;
if ( V_11 & V_38 )
V_43 += snprintf ( V_43 , V_219 + V_220 - V_43 , L_10 ) ;
else if ( V_11 & V_30 )
V_43 += snprintf ( V_43 , V_219 + V_220 - V_43 , L_11 ) ;
}
if ( ! F_10 ( V_17 ) ) {
if ( V_219 + V_220 < V_43 + 2 )
return - V_222 ;
* V_43 ++ = ':' ;
V_43 += F_211 ( V_43 , V_219 + V_220 - V_43 , V_17 ) ;
}
return V_43 - V_219 ;
}
