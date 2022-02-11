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
V_62 = F_67 ( V_60 , V_85 ) ;
if ( ! V_62 || V_62 -> V_90 > V_85 )
return - V_89 ;
V_88 = V_62 -> V_104 ;
if ( V_85 > V_62 -> V_90 )
V_88 = V_62 ;
for (; V_62 && V_62 -> V_90 < V_69 ; V_88 = V_62 , V_62 = V_82 ) {
V_82 = V_62 -> V_65 ;
V_102 = F_74 ( V_85 , V_62 -> V_90 ) ;
V_103 = F_75 ( V_69 , V_62 -> V_92 ) ;
if ( F_76 ( F_77 ( V_62 ) , V_100 ) )
continue;
V_101 = V_62 -> V_96 +
( ( V_102 - V_62 -> V_90 ) >> V_105 ) ;
V_88 = F_78 ( V_60 , V_88 , V_102 , V_103 , V_62 -> V_106 ,
V_62 -> V_107 , V_62 -> V_98 , V_101 ,
V_100 ) ;
if ( V_88 ) {
V_62 = V_88 ;
V_82 = V_62 -> V_65 ;
continue;
}
if ( V_62 -> V_90 != V_102 ) {
V_86 = F_79 ( V_62 -> V_74 , V_62 , V_102 , 1 ) ;
if ( V_86 )
goto V_108;
}
if ( V_62 -> V_92 != V_103 ) {
V_86 = F_79 ( V_62 -> V_74 , V_62 , V_103 , 0 ) ;
if ( V_86 )
goto V_108;
}
V_86 = F_70 ( V_62 , V_100 ) ;
if ( V_86 )
goto V_108;
}
V_108:
return V_86 ;
}
void F_80 ( struct V_56 * V_43 )
{
if ( V_43 -> V_9 )
V_43 -> V_11 |= V_109 ;
else
V_43 -> V_11 &= ~ V_109 ;
}
static void F_81 ( void )
{
F_80 ( V_49 ) ;
}
static long F_82 ( unsigned short V_28 , unsigned short V_11 ,
T_1 * V_17 )
{
struct V_9 * V_58 , * V_95 ;
struct V_59 * V_60 = V_49 -> V_60 ;
F_83 ( V_110 ) ;
int V_13 ;
if ( ! V_110 )
return - V_41 ;
V_58 = F_18 ( V_28 , V_11 , V_17 ) ;
if ( F_84 ( V_58 ) ) {
V_13 = F_85 ( V_58 ) ;
goto V_108;
}
if ( V_60 )
F_42 ( & V_60 -> V_63 ) ;
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , V_17 , V_110 ) ;
if ( V_13 ) {
F_87 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_58 ) ;
goto V_108;
}
V_95 = V_49 -> V_9 ;
V_49 -> V_9 = V_58 ;
F_81 () ;
if ( V_58 && V_58 -> V_28 == V_111 &&
F_7 ( V_58 -> V_19 . V_17 ) )
V_49 -> V_50 = F_12 ( V_58 -> V_19 . V_17 ) ;
F_87 ( V_49 ) ;
if ( V_60 )
F_43 ( & V_60 -> V_63 ) ;
F_72 ( V_95 ) ;
V_13 = 0 ;
V_108:
F_88 ( V_110 ) ;
return V_13 ;
}
static void F_89 ( struct V_9 * V_43 , T_1 * V_17 )
{
F_90 ( * V_17 ) ;
if ( V_43 == & V_112 )
return;
switch ( V_43 -> V_28 ) {
case V_113 :
case V_111 :
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
V_86 = F_93 ( V_49 , V_60 , V_68 & V_114 , 1 , 0 , 0 , & V_43 , NULL ) ;
if ( V_86 >= 0 ) {
V_86 = F_50 ( V_43 ) ;
F_94 ( V_43 ) ;
}
return V_86 ;
}
static long F_95 ( int * V_36 , T_1 * V_115 ,
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
F_86 ( V_49 ) ;
* V_115 = V_25 ;
F_87 ( V_49 ) ;
return 0 ;
}
if ( V_11 & V_117 ) {
F_96 ( & V_60 -> V_63 ) ;
V_62 = F_97 ( V_60 , V_68 , V_68 + 1 ) ;
if ( ! V_62 ) {
F_98 ( & V_60 -> V_63 ) ;
return - V_89 ;
}
if ( V_62 -> V_97 && V_62 -> V_97 -> V_119 )
V_10 = V_62 -> V_97 -> V_119 ( V_62 , V_68 ) ;
else
V_10 = V_62 -> V_66 ;
} else if ( V_68 )
return - V_18 ;
if ( ! V_10 )
V_10 = & V_112 ;
if ( V_11 & V_116 ) {
if ( V_11 & V_117 ) {
V_86 = F_92 ( V_60 , V_68 ) ;
if ( V_86 < 0 )
goto V_108;
* V_36 = V_86 ;
} else if ( V_10 == V_49 -> V_9 &&
V_10 -> V_28 == V_111 ) {
* V_36 = V_49 -> V_50 ;
} else {
V_86 = - V_18 ;
goto V_108;
}
} else {
* V_36 = V_10 == & V_112 ? V_37 :
V_10 -> V_28 ;
* V_36 |= ( V_10 -> V_11 & V_12 ) ;
}
if ( V_62 ) {
F_98 ( & V_49 -> V_60 -> V_63 ) ;
V_62 = NULL ;
}
V_86 = 0 ;
if ( V_115 ) {
if ( F_4 ( V_10 ) ) {
* V_115 = V_10 -> V_32 . V_33 ;
} else {
F_86 ( V_49 ) ;
F_89 ( V_10 , V_115 ) ;
F_87 ( V_49 ) ;
}
}
V_108:
F_99 ( V_10 ) ;
if ( V_62 )
F_98 ( & V_49 -> V_60 -> V_63 ) ;
return V_86 ;
}
static void F_51 ( struct V_75 * V_75 , struct V_120 * V_121 ,
unsigned long V_11 )
{
if ( ( V_11 & V_79 ) || F_100 ( V_75 ) == 1 ) {
if ( ! F_101 ( V_75 ) ) {
F_102 ( & V_75 -> V_122 , V_121 ) ;
F_103 ( V_75 , V_123 +
F_104 ( V_75 ) ) ;
}
}
}
static struct V_75 * F_105 ( struct V_75 * V_75 , unsigned long V_52 , int * * V_124 )
{
return F_106 ( V_52 , V_125 , 0 ) ;
}
static int F_107 ( struct V_59 * V_60 , int V_126 , int V_127 ,
int V_11 )
{
T_1 V_115 ;
F_108 ( V_121 ) ;
int V_86 = 0 ;
struct V_61 * V_62 ;
F_90 ( V_115 ) ;
F_91 ( V_126 , V_115 ) ;
V_62 = F_66 ( V_60 , V_60 -> V_64 -> V_90 , V_60 -> V_128 , & V_115 ,
V_11 | V_91 , & V_121 ) ;
if ( F_84 ( V_62 ) )
return F_85 ( V_62 ) ;
if ( ! F_109 ( & V_121 ) ) {
V_86 = F_110 ( & V_121 , F_105 , V_127 ,
false , V_129 ) ;
if ( V_86 )
F_111 ( & V_121 ) ;
}
return V_86 ;
}
int F_112 ( struct V_59 * V_60 ,
const T_1 * V_130 , const T_1 * V_131 , int V_11 )
{
int V_132 = 0 ;
int V_86 ;
T_1 V_16 ;
V_86 = F_113 () ;
if ( V_86 )
return V_86 ;
F_96 ( & V_60 -> V_63 ) ;
V_86 = F_114 ( V_60 , V_130 , V_131 , V_11 ) ;
if ( V_86 )
goto V_108;
V_16 = * V_130 ;
while ( ! F_10 ( V_16 ) ) {
int V_133 , V_134 ;
int V_126 = - 1 ;
int V_127 = 0 ;
F_2 (s, tmp) {
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
F_115 ( V_126 , V_16 ) ;
V_86 = F_107 ( V_60 , V_126 , V_127 , V_11 ) ;
if ( V_86 > 0 )
V_132 += V_86 ;
if ( V_86 < 0 )
break;
}
V_108:
F_98 ( & V_60 -> V_63 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_132 ;
}
static struct V_75 * F_116 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_124 )
{
struct V_61 * V_62 = (struct V_61 * ) V_70 ;
unsigned long V_135 ( V_136 ) ;
while ( V_62 ) {
V_136 = F_117 ( V_75 , V_62 ) ;
if ( V_136 != - V_89 )
break;
V_62 = V_62 -> V_65 ;
}
return F_118 ( V_125 , V_62 , V_136 ) ;
}
static void F_51 ( struct V_75 * V_75 , struct V_120 * V_121 ,
unsigned long V_11 )
{
}
int F_112 ( struct V_59 * V_60 ,
const T_1 * V_130 , const T_1 * V_131 , int V_11 )
{
return - V_137 ;
}
static struct V_75 * F_116 ( struct V_75 * V_75 , unsigned long V_70 , int * * V_124 )
{
return NULL ;
}
static long F_119 ( unsigned long V_85 , unsigned long V_138 ,
unsigned short V_28 , unsigned short V_139 ,
T_1 * V_115 , unsigned long V_11 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = V_49 -> V_60 ;
struct V_9 * V_58 ;
unsigned long V_69 ;
int V_86 ;
F_108 ( V_121 ) ;
if ( V_11 & ~ ( unsigned long ) ( V_93 |
V_78 | V_79 ) )
return - V_18 ;
if ( ( V_11 & V_79 ) && ! F_120 ( V_140 ) )
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
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
if ( ! V_58 )
V_11 |= V_91 ;
F_19 ( L_3 ,
V_85 , V_85 + V_138 , V_28 , V_139 ,
V_115 ? F_20 ( * V_115 ) [ 0 ] : - 1 ) ;
if ( V_11 & ( V_78 | V_79 ) ) {
V_86 = F_113 () ;
if ( V_86 )
goto V_142;
}
{
F_83 ( V_110 ) ;
if ( V_110 ) {
F_42 ( & V_60 -> V_63 ) ;
F_86 ( V_49 ) ;
V_86 = F_14 ( V_58 , V_115 , V_110 ) ;
F_87 ( V_49 ) ;
if ( V_86 )
F_43 ( & V_60 -> V_63 ) ;
} else
V_86 = - V_41 ;
F_88 ( V_110 ) ;
}
if ( V_86 )
goto V_142;
V_62 = F_66 ( V_60 , V_85 , V_69 , V_115 ,
V_11 | V_77 , & V_121 ) ;
V_86 = F_85 ( V_62 ) ;
if ( ! F_84 ( V_62 ) ) {
int V_143 = 0 ;
V_86 = F_73 ( V_60 , V_85 , V_69 , V_58 ) ;
if ( ! F_109 ( & V_121 ) ) {
V_143 = F_110 ( & V_121 , F_116 ,
( unsigned long ) V_62 ,
false , true ) ;
if ( V_143 )
F_111 ( & V_121 ) ;
}
if ( ! V_86 && V_143 && ( V_11 & V_93 ) )
V_86 = - V_83 ;
} else
F_111 ( & V_121 ) ;
F_43 ( & V_60 -> V_63 ) ;
V_142:
F_72 ( V_58 ) ;
return V_86 ;
}
static int F_121 ( T_1 * V_17 , const unsigned long T_8 * V_115 ,
unsigned long V_144 )
{
unsigned long V_3 ;
unsigned long V_145 ;
unsigned long V_146 ;
-- V_144 ;
F_90 ( * V_17 ) ;
if ( V_144 == 0 || ! V_115 )
return 0 ;
if ( V_144 > V_80 * V_147 )
return - V_18 ;
V_145 = F_122 ( V_144 ) ;
if ( ( V_144 % V_148 ) == 0 )
V_146 = ~ 0UL ;
else
V_146 = ( 1UL << ( V_144 % V_148 ) ) - 1 ;
if ( V_145 > F_122 ( V_51 ) ) {
if ( V_145 > V_80 / sizeof( long ) )
return - V_18 ;
for ( V_3 = F_122 ( V_51 ) ; V_3 < V_145 ; V_3 ++ ) {
unsigned long V_149 ;
if ( F_123 ( V_149 , V_115 + V_3 ) )
return - V_89 ;
if ( V_3 == V_145 - 1 ) {
if ( V_149 & V_146 )
return - V_18 ;
} else if ( V_149 )
return - V_18 ;
}
V_145 = F_122 ( V_51 ) ;
V_146 = ~ 0UL ;
}
if ( F_124 ( F_20 ( * V_17 ) , V_115 , V_145 *sizeof( unsigned long ) ) )
return - V_89 ;
F_20 ( * V_17 ) [ V_145 - 1 ] &= V_146 ;
return 0 ;
}
static int F_125 ( unsigned long T_8 * V_150 , unsigned long V_144 ,
T_1 * V_17 )
{
unsigned long V_151 = F_126 ( V_144 - 1 , 64 ) / 8 ;
const int V_152 = F_122 ( V_51 ) * sizeof( long ) ;
if ( V_151 > V_152 ) {
if ( V_151 > V_80 )
return - V_18 ;
if ( F_127 ( ( char T_8 * ) V_150 + V_152 , V_151 - V_152 ) )
return - V_89 ;
V_151 = V_152 ;
}
return F_128 ( V_150 , F_20 ( * V_17 ) , V_151 ) ? - V_89 : 0 ;
}
T_9 long F_129 ( int T_8 * V_36 ,
T_10 T_8 * V_115 ,
T_10 V_144 ,
T_10 V_68 , T_10 V_11 )
{
long V_86 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
F_130 ( V_156 , V_51 ) ;
V_154 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_126 ( V_154 , V_148 ) / 8 ;
if ( V_115 )
V_153 = F_132 ( V_155 ) ;
V_86 = F_133 ( V_36 , V_153 , V_154 + 1 , V_68 , V_11 ) ;
if ( ! V_86 && V_115 ) {
unsigned long V_157 ;
V_157 = F_131 (unsigned long, sizeof(bm), alloc_size) ;
V_86 = F_124 ( V_156 , V_153 , V_157 ) ;
V_86 |= F_127 ( V_115 , F_126 ( V_144 - 1 , 8 ) / 8 ) ;
V_86 |= F_134 ( V_115 , V_156 , V_154 ) ;
}
return V_86 ;
}
T_9 long F_135 ( int V_28 , T_10 T_8 * V_115 ,
T_10 V_144 )
{
long V_86 = 0 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
F_130 ( V_156 , V_51 ) ;
V_154 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_126 ( V_154 , V_148 ) / 8 ;
if ( V_115 ) {
V_86 = F_136 ( V_156 , V_115 , V_154 ) ;
V_153 = F_132 ( V_155 ) ;
V_86 |= F_128 ( V_153 , V_156 , V_155 ) ;
}
if ( V_86 )
return - V_89 ;
return F_137 ( V_28 , V_153 , V_154 + 1 ) ;
}
T_9 long F_138 ( T_10 V_85 , T_10 V_138 ,
T_10 V_28 , T_10 T_8 * V_115 ,
T_10 V_144 , T_10 V_11 )
{
long V_86 = 0 ;
unsigned long T_8 * V_153 = NULL ;
unsigned long V_154 , V_155 ;
T_1 V_156 ;
V_154 = F_131 (unsigned long, maxnode-1 , MAX_NUMNODES) ;
V_155 = F_126 ( V_154 , V_148 ) / 8 ;
if ( V_115 ) {
V_86 = F_136 ( F_20 ( V_156 ) , V_115 , V_154 ) ;
V_153 = F_132 ( V_155 ) ;
V_86 |= F_128 ( V_153 , F_20 ( V_156 ) , V_155 ) ;
}
if ( V_86 )
return - V_89 ;
return F_139 ( V_85 , V_138 , V_28 , V_153 , V_154 + 1 , V_11 ) ;
}
struct V_9 * F_140 ( struct V_56 * V_158 ,
struct V_61 * V_62 , unsigned long V_68 )
{
struct V_9 * V_10 = V_158 -> V_9 ;
if ( V_62 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_119 ) {
struct V_9 * V_159 = V_62 -> V_97 -> V_119 ( V_62 ,
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
static T_1 * F_141 ( T_11 V_160 , struct V_9 * V_36 )
{
if ( F_142 ( V_36 -> V_28 == V_113 ) &&
F_143 ( V_160 ) >= V_6 &&
F_144 ( & V_36 -> V_19 . V_17 ) )
return & V_36 -> V_19 . V_17 ;
return NULL ;
}
static struct V_161 * F_145 ( T_11 V_160 , struct V_9 * V_36 ,
int V_2 )
{
switch ( V_36 -> V_28 ) {
case V_29 :
if ( ! ( V_36 -> V_11 & V_20 ) )
V_2 = V_36 -> V_19 . V_21 ;
break;
case V_113 :
if ( F_142 ( V_160 & V_162 ) &&
F_142 ( ! F_32 ( V_2 , V_36 -> V_19 . V_17 ) ) )
V_2 = F_12 ( V_36 -> V_19 . V_17 ) ;
break;
default:
F_30 () ;
}
return F_146 ( V_2 , V_160 ) ;
}
static unsigned F_147 ( struct V_9 * V_36 )
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
unsigned F_148 ( struct V_9 * V_36 )
{
if ( ! V_36 || V_36 -> V_11 & V_20 )
return F_34 () ;
switch ( V_36 -> V_28 ) {
case V_29 :
return V_36 -> V_19 . V_21 ;
case V_111 :
return F_147 ( V_36 ) ;
case V_113 : {
struct V_161 * V_161 ;
struct V_4 * V_4 ;
enum V_164 V_165 = F_143 ( V_40 ) ;
V_161 = & F_3 ( F_34 () ) -> V_166 [ 0 ] ;
( void ) F_149 ( V_161 , V_165 ,
& V_36 -> V_19 . V_17 ,
& V_4 ) ;
return V_4 ? V_4 -> V_52 : F_34 () ;
}
default:
F_30 () ;
}
}
static unsigned F_150 ( struct V_9 * V_10 ,
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
static inline unsigned F_151 ( struct V_9 * V_10 ,
struct V_61 * V_62 , unsigned long V_68 , int V_171 )
{
if ( V_62 ) {
unsigned long V_167 ;
F_152 ( V_171 < V_105 ) ;
V_167 = V_62 -> V_96 >> ( V_171 - V_105 ) ;
V_167 += ( V_68 - V_62 -> V_90 ) >> V_171 ;
return F_150 ( V_10 , V_62 , V_167 ) ;
} else
return F_147 ( V_10 ) ;
}
int F_153 ( const T_1 * V_172 )
{
int V_32 , V_173 = - 1 ;
V_32 = F_7 ( * V_172 ) ;
if ( V_32 )
V_173 = F_154 ( V_172 -> V_174 ,
F_155 () % V_32 , V_51 ) ;
return V_173 ;
}
struct V_161 * F_156 ( struct V_61 * V_62 , unsigned long V_68 ,
T_11 V_175 , struct V_9 * * V_176 ,
T_1 * * V_1 )
{
struct V_161 * V_177 ;
* V_176 = F_140 ( V_49 , V_62 , V_68 ) ;
* V_1 = NULL ;
if ( F_142 ( ( * V_176 ) -> V_28 == V_111 ) ) {
V_177 = F_146 ( F_151 ( * V_176 , V_62 , V_68 ,
F_157 ( F_158 ( V_62 ) ) ) , V_175 ) ;
} else {
V_177 = F_145 ( V_175 , * V_176 , F_34 () ) ;
if ( ( * V_176 ) -> V_28 == V_113 )
* V_1 = & ( * V_176 ) -> V_19 . V_17 ;
}
return V_177 ;
}
bool F_159 ( T_1 * V_150 )
{
struct V_9 * V_9 ;
int V_76 ;
if ( ! ( V_150 && V_49 -> V_9 ) )
return false ;
F_86 ( V_49 ) ;
V_9 = V_49 -> V_9 ;
switch ( V_9 -> V_28 ) {
case V_29 :
if ( V_9 -> V_11 & V_20 )
V_76 = F_34 () ;
else
V_76 = V_9 -> V_19 . V_21 ;
F_160 ( V_150 , V_76 ) ;
break;
case V_113 :
case V_111 :
* V_150 = V_9 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
F_87 ( V_49 ) ;
return true ;
}
bool F_161 ( struct V_56 * V_57 ,
const T_1 * V_150 )
{
struct V_9 * V_9 ;
bool V_13 = true ;
if ( ! V_150 )
return V_13 ;
F_86 ( V_57 ) ;
V_9 = V_57 -> V_9 ;
if ( ! V_9 )
goto V_108;
switch ( V_9 -> V_28 ) {
case V_29 :
break;
case V_113 :
case V_111 :
V_13 = F_162 ( V_9 -> V_19 . V_17 , * V_150 ) ;
break;
default:
F_30 () ;
}
V_108:
F_87 ( V_57 ) ;
return V_13 ;
}
static struct V_75 * F_163 ( T_11 V_160 , unsigned V_178 ,
unsigned V_76 )
{
struct V_161 * V_177 ;
struct V_75 * V_75 ;
V_177 = F_146 ( V_76 , V_160 ) ;
V_75 = F_164 ( V_160 , V_178 , V_177 ) ;
if ( V_75 && F_165 ( V_75 ) == F_166 ( & V_177 -> V_179 [ 0 ] ) )
F_103 ( V_75 , V_180 ) ;
return V_75 ;
}
struct V_75 *
F_167 ( T_11 V_160 , int V_178 , struct V_61 * V_62 ,
unsigned long V_68 , int V_52 )
{
struct V_9 * V_10 = F_140 ( V_49 , V_62 , V_68 ) ;
struct V_161 * V_177 ;
struct V_75 * V_75 ;
F_168 () ;
if ( F_142 ( V_10 -> V_28 == V_111 ) ) {
unsigned V_76 ;
V_76 = F_151 ( V_10 , V_62 , V_68 , V_105 + V_178 ) ;
F_99 ( V_10 ) ;
V_75 = F_163 ( V_160 , V_178 , V_76 ) ;
F_169 () ;
return V_75 ;
}
V_177 = F_145 ( V_160 , V_10 , V_52 ) ;
if ( F_142 ( F_170 ( V_10 ) ) ) {
struct V_75 * V_75 = F_171 ( V_160 , V_178 ,
V_177 , F_141 ( V_160 , V_10 ) ) ;
F_24 ( V_10 ) ;
F_169 () ;
return V_75 ;
}
V_75 = F_171 ( V_160 , V_178 , V_177 ,
F_141 ( V_160 , V_10 ) ) ;
F_169 () ;
return V_75 ;
}
struct V_75 * F_172 ( T_11 V_160 , unsigned V_178 )
{
struct V_9 * V_10 = V_49 -> V_9 ;
struct V_75 * V_75 ;
if ( ! V_10 || F_173 () || ( V_160 & V_162 ) )
V_10 = & V_112 ;
F_168 () ;
if ( V_10 -> V_28 == V_111 )
V_75 = F_163 ( V_160 , V_178 , F_147 ( V_10 ) ) ;
else
V_75 = F_171 ( V_160 , V_178 ,
F_145 ( V_160 , V_10 , F_34 () ) ,
F_141 ( V_160 , V_10 ) ) ;
F_169 () ;
return V_75 ;
}
struct V_9 * F_174 ( struct V_9 * V_95 )
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
F_175 () ;
if ( F_176 () ) {
T_1 V_181 = V_34 ( V_49 ) ;
if ( V_58 -> V_11 & V_54 )
F_37 ( V_58 , & V_181 , V_48 ) ;
else
F_37 ( V_58 , & V_181 , V_46 ) ;
}
F_177 () ;
F_23 ( & V_58 -> V_42 , 1 ) ;
return V_58 ;
}
struct V_9 * F_178 ( struct V_9 * V_182 ,
struct V_9 * V_183 )
{
if ( ! F_170 ( V_183 ) )
return V_183 ;
* V_182 = * V_183 ;
V_182 -> V_11 &= ~ V_184 ;
F_24 ( V_183 ) ;
return V_182 ;
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
case V_113 :
case V_111 :
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
F_71 ( V_197 -> V_36 ) ;
V_10 = V_197 -> V_36 ;
}
F_188 ( & V_189 -> V_198 ) ;
return V_10 ;
}
static void F_189 ( struct V_188 * V_189 , struct V_187 * V_191 )
{
F_19 ( L_5 , V_191 -> V_85 , V_191 -> V_69 ) ;
F_190 ( & V_191 -> V_2 , & V_189 -> V_192 ) ;
F_72 ( V_191 -> V_36 ) ;
F_26 ( V_199 , V_191 ) ;
}
static struct V_187 * F_191 ( unsigned long V_85 , unsigned long V_69 ,
struct V_9 * V_10 )
{
struct V_187 * V_191 = F_22 ( V_199 , V_40 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_85 = V_85 ;
V_191 -> V_69 = V_69 ;
F_71 ( V_10 ) ;
V_10 -> V_11 |= V_184 ;
V_191 -> V_36 = V_10 ;
return V_191 ;
}
static int F_192 ( struct V_188 * V_189 , unsigned long V_85 ,
unsigned long V_69 , struct V_187 * V_58 )
{
struct V_187 * V_191 , * V_200 = NULL ;
V_201:
F_187 ( & V_189 -> V_198 ) ;
V_191 = F_180 ( V_189 , V_85 , V_69 ) ;
while ( V_191 && V_191 -> V_85 < V_69 ) {
struct V_190 * V_82 = F_193 ( & V_191 -> V_2 ) ;
if ( V_191 -> V_85 >= V_85 ) {
if ( V_191 -> V_69 <= V_69 )
F_189 ( V_189 , V_191 ) ;
else
V_191 -> V_85 = V_69 ;
} else {
if ( V_191 -> V_69 > V_69 ) {
if ( ! V_200 ) {
F_188 ( & V_189 -> V_198 ) ;
V_200 = F_191 ( V_69 , V_191 -> V_69 , V_191 -> V_36 ) ;
if ( ! V_200 )
return - V_41 ;
goto V_201;
}
V_191 -> V_69 = V_85 ;
F_183 ( V_189 , V_200 ) ;
V_200 = NULL ;
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
F_188 ( & V_189 -> V_198 ) ;
if ( V_200 ) {
F_72 ( V_200 -> V_36 ) ;
F_26 ( V_199 , V_200 ) ;
}
return 0 ;
}
void F_194 ( struct V_188 * V_189 , struct V_9 * V_176 )
{
int V_13 ;
V_189 -> V_192 = V_202 ;
F_195 ( & V_189 -> V_198 ) ;
if ( V_176 ) {
struct V_61 V_203 ;
struct V_9 * V_58 ;
F_83 ( V_110 ) ;
if ( ! V_110 )
goto V_204;
V_58 = F_18 ( V_176 -> V_28 , V_176 -> V_11 , & V_176 -> V_32 . V_33 ) ;
if ( F_84 ( V_58 ) )
goto V_205;
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_176 -> V_32 . V_33 , V_110 ) ;
F_87 ( V_49 ) ;
if ( V_13 )
goto V_206;
memset ( & V_203 , 0 , sizeof( struct V_61 ) ) ;
V_203 . V_92 = V_207 ;
F_196 ( V_189 , & V_203 , V_58 ) ;
V_206:
F_72 ( V_58 ) ;
V_205:
F_88 ( V_110 ) ;
V_204:
F_72 ( V_176 ) ;
}
}
int F_196 ( struct V_188 * V_208 ,
struct V_61 * V_62 , struct V_9 * V_209 )
{
int V_86 ;
struct V_187 * V_58 = NULL ;
unsigned long V_210 = F_197 ( V_62 ) ;
F_19 ( L_6 ,
V_62 -> V_96 ,
V_210 , V_209 ? V_209 -> V_28 : - 1 ,
V_209 ? V_209 -> V_11 : - 1 ,
V_209 ? F_20 ( V_209 -> V_19 . V_17 ) [ 0 ] : - 1 ) ;
if ( V_209 ) {
V_58 = F_191 ( V_62 -> V_96 , V_62 -> V_96 + V_210 , V_209 ) ;
if ( ! V_58 )
return - V_41 ;
}
V_86 = F_192 ( V_208 , V_62 -> V_96 , V_62 -> V_96 + V_210 , V_58 ) ;
if ( V_86 && V_58 )
F_26 ( V_199 , V_58 ) ;
return V_86 ;
}
void F_198 ( struct V_188 * V_43 )
{
struct V_187 * V_191 ;
struct V_190 * V_82 ;
if ( ! V_43 -> V_192 . V_190 )
return;
F_187 ( & V_43 -> V_198 ) ;
V_82 = F_199 ( & V_43 -> V_192 ) ;
while ( V_82 ) {
V_191 = F_181 ( V_82 , struct V_187 , V_2 ) ;
V_82 = F_193 ( & V_191 -> V_2 ) ;
F_190 ( & V_191 -> V_2 , & V_43 -> V_192 ) ;
F_72 ( V_191 -> V_36 ) ;
F_26 ( V_199 , V_191 ) ;
}
F_188 ( & V_43 -> V_198 ) ;
}
void T_12 F_200 ( void )
{
T_1 F_147 ;
unsigned long V_211 = 0 ;
int V_76 , V_212 = 0 ;
V_39 = F_201 ( L_7 ,
sizeof( struct V_9 ) ,
0 , V_213 , NULL ) ;
V_199 = F_201 ( L_8 ,
sizeof( struct V_187 ) ,
0 , V_213 , NULL ) ;
F_90 ( F_147 ) ;
F_202 (nid, N_HIGH_MEMORY) {
unsigned long V_214 = F_203 ( V_76 ) ;
if ( V_211 < V_214 ) {
V_211 = V_214 ;
V_212 = V_76 ;
}
if ( ( V_214 << V_105 ) >= ( 16 << 20 ) )
F_91 ( V_76 , F_147 ) ;
}
if ( F_142 ( F_10 ( F_147 ) ) )
F_91 ( V_212 , F_147 ) ;
if ( F_82 ( V_111 , 0 , & F_147 ) )
F_204 ( L_9 ) ;
}
void F_205 ( void )
{
F_82 ( V_37 , 0 , NULL ) ;
}
int F_206 ( char * V_215 , struct V_9 * * V_176 , int V_216 )
{
struct V_9 * V_58 = NULL ;
unsigned short V_28 ;
unsigned short V_135 ( V_139 ) ;
T_1 V_17 ;
char * V_217 = strchr ( V_215 , ':' ) ;
char * V_11 = strchr ( V_215 , '=' ) ;
int V_86 = 1 ;
if ( V_217 ) {
* V_217 ++ = '\0' ;
if ( F_207 ( V_217 , V_17 ) )
goto V_108;
if ( ! F_208 ( V_17 , V_26 [ V_27 ] ) )
goto V_108;
} else
F_90 ( V_17 ) ;
if ( V_11 )
* V_11 ++ = '\0' ;
for ( V_28 = 0 ; V_28 <= V_218 ; V_28 ++ ) {
if ( ! strcmp ( V_215 , V_219 [ V_28 ] ) ) {
break;
}
}
if ( V_28 > V_218 )
goto V_108;
switch ( V_28 ) {
case V_29 :
if ( V_217 ) {
char * V_220 = V_217 ;
while ( isdigit ( * V_220 ) )
V_220 ++ ;
if ( * V_220 )
goto V_108;
}
break;
case V_111 :
if ( ! V_217 )
V_17 = V_26 [ V_27 ] ;
break;
case V_218 :
if ( V_217 )
goto V_108;
V_28 = V_29 ;
break;
case V_37 :
if ( ! V_217 )
V_86 = 0 ;
goto V_108;
case V_113 :
if ( ! V_217 )
goto V_108;
}
V_139 = 0 ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_10 ) )
V_139 |= V_38 ;
else if ( ! strcmp ( V_11 , L_11 ) )
V_139 |= V_30 ;
else
goto V_108;
}
V_58 = F_18 ( V_28 , V_139 , & V_17 ) ;
if ( F_84 ( V_58 ) )
goto V_108;
if ( V_216 ) {
V_58 -> V_32 . V_33 = V_17 ;
} else {
int V_13 ;
F_83 ( V_110 ) ;
if ( V_110 ) {
F_86 ( V_49 ) ;
V_13 = F_14 ( V_58 , & V_17 , V_110 ) ;
F_87 ( V_49 ) ;
} else
V_13 = - V_41 ;
F_88 ( V_110 ) ;
if ( V_13 ) {
F_72 ( V_58 ) ;
goto V_108;
}
}
V_86 = 0 ;
V_108:
if ( V_217 )
* -- V_217 = ':' ;
if ( V_11 )
* -- V_11 = '=' ;
if ( ! V_86 )
* V_176 = V_58 ;
return V_86 ;
}
int F_209 ( char * V_221 , int V_222 , struct V_9 * V_10 , int V_216 )
{
char * V_43 = V_221 ;
int V_223 ;
T_1 V_17 ;
unsigned short V_28 ;
unsigned short V_11 = V_10 ? V_10 -> V_11 : 0 ;
F_16 ( V_222 < strlen ( L_12 ) + strlen ( L_11 ) + 16 ) ;
if ( ! V_10 || V_10 == & V_112 )
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
V_28 = V_218 ;
else
F_91 ( V_10 -> V_19 . V_21 , V_17 ) ;
break;
case V_113 :
case V_111 :
if ( V_216 )
V_17 = V_10 -> V_32 . V_33 ;
else
V_17 = V_10 -> V_19 . V_17 ;
break;
default:
F_30 () ;
}
V_223 = strlen ( V_219 [ V_28 ] ) ;
if ( V_221 + V_222 < V_43 + V_223 + 1 )
return - V_224 ;
strcpy ( V_43 , V_219 [ V_28 ] ) ;
V_43 += V_223 ;
if ( V_11 & V_12 ) {
if ( V_221 + V_222 < V_43 + 2 )
return - V_224 ;
* V_43 ++ = '=' ;
if ( V_11 & V_38 )
V_43 += snprintf ( V_43 , V_221 + V_222 - V_43 , L_10 ) ;
else if ( V_11 & V_30 )
V_43 += snprintf ( V_43 , V_221 + V_222 - V_43 , L_11 ) ;
}
if ( ! F_10 ( V_17 ) ) {
if ( V_221 + V_222 < V_43 + 2 )
return - V_224 ;
* V_43 ++ = ':' ;
V_43 += F_210 ( V_43 , V_221 + V_222 - V_43 , V_17 ) ;
}
return V_43 - V_221 ;
}
