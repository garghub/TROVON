struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_1 ;
int V_5 ;
if ( V_4 )
return V_4 ;
V_5 = F_2 () ;
if ( V_5 != V_6 ) {
V_4 = & V_7 [ V_5 ] ;
if ( V_4 -> V_8 )
return V_4 ;
}
return & V_9 ;
}
static inline int F_3 ( const struct V_1 * V_4 )
{
return V_4 -> V_10 & V_11 ;
}
static void F_4 ( T_1 * V_12 , const T_1 * V_13 ,
const T_1 * V_14 )
{
T_1 V_15 ;
F_5 ( V_15 , * V_13 , F_6 ( * V_14 ) ) ;
F_7 ( * V_12 , V_15 , * V_14 ) ;
}
static int F_8 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( F_9 ( * V_16 ) )
return - V_17 ;
V_4 -> V_18 . V_16 = * V_16 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( ! V_16 )
V_4 -> V_10 |= V_19 ;
else if ( F_9 ( * V_16 ) )
return - V_17 ;
else
V_4 -> V_18 . V_20 = F_11 ( * V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , const T_1 * V_16 )
{
if ( F_9 ( * V_16 ) )
return - V_17 ;
V_4 -> V_18 . V_16 = * V_16 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_4 ,
const T_1 * V_16 , struct V_21 * V_22 )
{
int V_12 ;
if ( V_4 == NULL )
return 0 ;
F_14 ( V_22 -> V_23 ,
V_24 , V_25 [ V_26 ] ) ;
F_15 ( ! V_16 ) ;
if ( V_4 -> V_8 == V_27 && F_9 ( * V_16 ) )
V_16 = NULL ;
else {
if ( V_4 -> V_10 & V_28 )
F_4 ( & V_22 -> V_29 , V_16 , & V_22 -> V_23 ) ;
else
F_14 ( V_22 -> V_29 , * V_16 , V_22 -> V_23 ) ;
if ( F_3 ( V_4 ) )
V_4 -> V_30 . V_31 = * V_16 ;
else
V_4 -> V_30 . V_32 =
V_24 ;
}
if ( V_16 )
V_12 = V_33 [ V_4 -> V_8 ] . F_16 ( V_4 , & V_22 -> V_29 ) ;
else
V_12 = V_33 [ V_4 -> V_8 ] . F_16 ( V_4 , NULL ) ;
return V_12 ;
}
static struct V_1 * F_17 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_34 ;
F_18 ( L_1 ,
V_8 , V_10 , V_16 ? F_19 ( * V_16 ) [ 0 ] : V_6 ) ;
if ( V_8 == V_35 ) {
if ( V_16 && ! F_9 ( * V_16 ) )
return F_20 ( - V_17 ) ;
return NULL ;
}
F_15 ( ! V_16 ) ;
if ( V_8 == V_27 ) {
if ( F_9 ( * V_16 ) ) {
if ( ( ( V_10 & V_36 ) ||
( V_10 & V_28 ) ) )
return F_20 ( - V_17 ) ;
}
} else if ( V_8 == V_37 ) {
if ( ! F_9 ( * V_16 ) ||
( V_10 & V_36 ) ||
( V_10 & V_28 ) )
return F_20 ( - V_17 ) ;
V_8 = V_27 ;
} else if ( F_9 ( * V_16 ) )
return F_20 ( - V_17 ) ;
V_34 = F_21 ( V_38 , V_39 ) ;
if ( ! V_34 )
return F_20 ( - V_40 ) ;
F_22 ( & V_34 -> V_41 , 1 ) ;
V_34 -> V_8 = V_8 ;
V_34 -> V_10 = V_10 ;
return V_34 ;
}
void F_23 ( struct V_1 * V_3 )
{
if ( ! F_24 ( & V_3 -> V_41 ) )
return;
F_25 ( V_38 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_4 , const T_1 * V_16 )
{
}
static void F_27 ( struct V_1 * V_4 , const T_1 * V_16 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 )
F_14 ( V_15 , V_4 -> V_30 . V_31 , * V_16 ) ;
else if ( V_4 -> V_10 & V_28 )
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
else {
F_28 ( V_15 , V_4 -> V_18 . V_16 , V_4 -> V_30 . V_32 ,
* V_16 ) ;
V_4 -> V_30 . V_32 = V_15 ;
}
if ( F_9 ( V_15 ) )
V_15 = * V_16 ;
V_4 -> V_18 . V_16 = V_15 ;
}
static void F_29 ( struct V_1 * V_4 ,
const T_1 * V_16 )
{
T_1 V_15 ;
if ( V_4 -> V_10 & V_36 ) {
int V_5 = F_11 ( V_4 -> V_30 . V_31 ) ;
if ( F_30 ( V_5 , * V_16 ) ) {
V_4 -> V_18 . V_20 = V_5 ;
V_4 -> V_10 &= ~ V_19 ;
} else
V_4 -> V_10 |= V_19 ;
} else if ( V_4 -> V_10 & V_28 ) {
F_4 ( & V_15 , & V_4 -> V_30 . V_31 , V_16 ) ;
V_4 -> V_18 . V_20 = F_11 ( V_15 ) ;
} else if ( ! ( V_4 -> V_10 & V_19 ) ) {
V_4 -> V_18 . V_20 = F_31 ( V_4 -> V_18 . V_20 ,
V_4 -> V_30 . V_32 ,
* V_16 ) ;
V_4 -> V_30 . V_32 = * V_16 ;
}
}
static void F_32 ( struct V_1 * V_4 , const T_1 * V_42 )
{
if ( ! V_4 )
return;
if ( ! F_3 ( V_4 ) &&
F_33 ( V_4 -> V_30 . V_32 , * V_42 ) )
return;
V_33 [ V_4 -> V_8 ] . F_34 ( V_4 , V_42 ) ;
}
void F_35 ( struct V_2 * V_43 , const T_1 * V_44 )
{
F_32 ( V_43 -> V_1 , V_44 ) ;
}
void F_36 ( struct V_45 * V_46 , T_1 * V_44 )
{
struct V_47 * V_48 ;
F_37 ( & V_46 -> V_49 ) ;
for ( V_48 = V_46 -> V_50 ; V_48 ; V_48 = V_48 -> V_51 )
F_32 ( V_48 -> V_52 , V_44 ) ;
F_38 ( & V_46 -> V_49 ) ;
}
static int F_39 ( T_2 * V_53 , unsigned long V_54 ,
unsigned long V_55 , struct V_56 * V_57 )
{
struct V_47 * V_48 = V_57 -> V_48 ;
struct V_58 * V_58 ;
struct V_59 * V_60 = V_57 -> V_61 ;
unsigned long V_10 = V_60 -> V_10 ;
int V_62 , V_12 ;
T_3 * V_63 ;
T_4 * V_64 ;
if ( F_40 ( * V_53 ) ) {
V_64 = F_41 ( V_57 -> V_46 , V_53 ) ;
if ( F_40 ( * V_53 ) ) {
V_58 = F_42 ( * V_53 ) ;
if ( F_43 ( V_58 ) ) {
F_44 ( V_64 ) ;
F_45 ( V_48 , V_53 , V_54 , false , NULL ) ;
} else {
F_46 ( V_58 ) ;
F_44 ( V_64 ) ;
F_47 ( V_58 ) ;
V_12 = F_48 ( V_58 ) ;
F_49 ( V_58 ) ;
F_50 ( V_58 ) ;
if ( V_12 )
return 0 ;
}
} else {
F_44 ( V_64 ) ;
}
}
if ( F_51 ( V_53 ) )
return 0 ;
V_65:
V_63 = F_52 ( V_57 -> V_46 , V_53 , V_54 , & V_64 ) ;
for (; V_54 != V_55 ; V_63 ++ , V_54 += V_66 ) {
if ( ! F_53 ( * V_63 ) )
continue;
V_58 = F_54 ( V_48 , V_54 , * V_63 ) ;
if ( ! V_58 )
continue;
if ( F_55 ( V_58 ) )
continue;
V_62 = F_56 ( V_58 ) ;
if ( F_30 ( V_62 , * V_60 -> V_67 ) == ! ! ( V_10 & V_68 ) )
continue;
if ( F_57 ( V_58 ) ) {
F_46 ( V_58 ) ;
F_58 ( V_63 , V_64 ) ;
F_47 ( V_58 ) ;
V_12 = F_48 ( V_58 ) ;
F_49 ( V_58 ) ;
F_50 ( V_58 ) ;
if ( V_12 ) {
V_63 = F_52 ( V_57 -> V_46 , V_53 ,
V_54 , & V_64 ) ;
continue;
}
goto V_65;
}
F_59 ( V_58 , V_60 -> V_69 , V_10 ) ;
}
F_58 ( V_63 - 1 , V_64 ) ;
F_60 () ;
return 0 ;
}
static int F_61 ( T_3 * V_63 , unsigned long V_70 ,
unsigned long V_54 , unsigned long V_55 ,
struct V_56 * V_57 )
{
#ifdef F_62
struct V_59 * V_60 = V_57 -> V_61 ;
unsigned long V_10 = V_60 -> V_10 ;
int V_62 ;
struct V_58 * V_58 ;
T_4 * V_64 ;
T_3 V_71 ;
V_64 = F_63 ( F_64 ( V_57 -> V_48 ) , V_57 -> V_46 , V_63 ) ;
V_71 = F_65 ( V_63 ) ;
if ( ! F_53 ( V_71 ) )
goto V_72;
V_58 = F_66 ( V_71 ) ;
V_62 = F_56 ( V_58 ) ;
if ( F_30 ( V_62 , * V_60 -> V_67 ) == ! ! ( V_10 & V_68 ) )
goto V_72;
if ( V_10 & ( V_73 ) ||
( V_10 & V_74 && F_67 ( V_58 ) == 1 ) )
F_68 ( V_58 , V_60 -> V_69 ) ;
V_72:
F_44 ( V_64 ) ;
#else
F_69 () ;
#endif
return 0 ;
}
unsigned long F_70 ( struct V_47 * V_48 ,
unsigned long V_54 , unsigned long V_55 )
{
int V_75 ;
V_75 = F_71 ( V_48 , V_54 , V_55 , V_76 , 0 , 1 ) ;
if ( V_75 )
F_72 ( V_77 , V_75 ) ;
return V_75 ;
}
static unsigned long F_70 ( struct V_47 * V_48 ,
unsigned long V_54 , unsigned long V_55 )
{
return 0 ;
}
static int F_73 ( unsigned long V_78 , unsigned long V_55 ,
struct V_56 * V_57 )
{
struct V_47 * V_48 = V_57 -> V_48 ;
struct V_59 * V_60 = V_57 -> V_61 ;
unsigned long V_79 = V_48 -> V_80 ;
unsigned long V_10 = V_60 -> V_10 ;
if ( ! F_74 ( V_48 ) )
return 1 ;
if ( V_79 > V_55 )
V_79 = V_55 ;
if ( V_48 -> V_81 > V_78 )
V_78 = V_48 -> V_81 ;
if ( ! ( V_10 & V_82 ) ) {
if ( ! V_48 -> V_51 && V_48 -> V_80 < V_55 )
return - V_83 ;
if ( V_60 -> V_84 && V_60 -> V_84 -> V_80 < V_48 -> V_81 )
return - V_83 ;
}
V_60 -> V_84 = V_48 ;
if ( V_10 & V_85 ) {
if ( ! F_75 ( V_48 ) &&
( V_48 -> V_86 & ( V_87 | V_88 | V_89 ) ) &&
! ( V_48 -> V_86 & V_90 ) )
F_70 ( V_48 , V_78 , V_79 ) ;
return 1 ;
}
if ( V_10 & ( V_74 | V_73 ) )
return 0 ;
return 1 ;
}
static int
F_76 ( struct V_45 * V_46 , unsigned long V_78 , unsigned long V_55 ,
T_1 * V_16 , unsigned long V_10 ,
struct V_91 * V_69 )
{
struct V_59 V_60 = {
. V_69 = V_69 ,
. V_10 = V_10 ,
. V_67 = V_16 ,
. V_84 = NULL ,
} ;
struct V_56 V_92 = {
. V_93 = F_61 ,
. V_94 = F_39 ,
. V_95 = F_73 ,
. V_46 = V_46 ,
. V_61 = & V_60 ,
} ;
return F_77 ( V_78 , V_55 , & V_92 ) ;
}
static int F_78 ( struct V_47 * V_48 ,
struct V_1 * V_4 )
{
int V_96 ;
struct V_1 * V_97 ;
struct V_1 * V_44 ;
F_18 ( L_2 ,
V_48 -> V_81 , V_48 -> V_80 , V_48 -> V_98 ,
V_48 -> V_99 , V_48 -> V_100 ,
V_48 -> V_99 ? V_48 -> V_99 -> V_101 : NULL ) ;
V_44 = F_79 ( V_4 ) ;
if ( F_80 ( V_44 ) )
return F_81 ( V_44 ) ;
if ( V_48 -> V_99 && V_48 -> V_99 -> V_101 ) {
V_96 = V_48 -> V_99 -> V_101 ( V_48 , V_44 ) ;
if ( V_96 )
goto V_102;
}
V_97 = V_48 -> V_52 ;
V_48 -> V_52 = V_44 ;
F_82 ( V_97 ) ;
return 0 ;
V_102:
F_82 ( V_44 ) ;
return V_96 ;
}
static int F_83 ( struct V_45 * V_46 , unsigned long V_78 ,
unsigned long V_55 , struct V_1 * V_103 )
{
struct V_47 * V_104 ;
struct V_47 * V_84 ;
struct V_47 * V_48 ;
int V_96 = 0 ;
T_5 V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
V_48 = F_84 ( V_46 , V_78 ) ;
if ( ! V_48 || V_48 -> V_81 > V_78 )
return - V_83 ;
V_84 = V_48 -> V_108 ;
if ( V_78 > V_48 -> V_81 )
V_84 = V_48 ;
for (; V_48 && V_48 -> V_81 < V_55 ; V_84 = V_48 , V_48 = V_104 ) {
V_104 = V_48 -> V_51 ;
V_106 = F_85 ( V_78 , V_48 -> V_81 ) ;
V_107 = F_86 ( V_55 , V_48 -> V_80 ) ;
if ( F_87 ( F_88 ( V_48 ) , V_103 ) )
continue;
V_105 = V_48 -> V_98 +
( ( V_106 - V_48 -> V_81 ) >> V_109 ) ;
V_84 = F_89 ( V_46 , V_84 , V_106 , V_107 , V_48 -> V_86 ,
V_48 -> V_110 , V_48 -> V_100 , V_105 ,
V_103 , V_48 -> V_111 ) ;
if ( V_84 ) {
V_48 = V_84 ;
V_104 = V_48 -> V_51 ;
if ( F_87 ( F_88 ( V_48 ) , V_103 ) )
continue;
goto V_112;
}
if ( V_48 -> V_81 != V_106 ) {
V_96 = F_90 ( V_48 -> V_113 , V_48 , V_106 , 1 ) ;
if ( V_96 )
goto V_114;
}
if ( V_48 -> V_80 != V_107 ) {
V_96 = F_90 ( V_48 -> V_113 , V_48 , V_107 , 0 ) ;
if ( V_96 )
goto V_114;
}
V_112:
V_96 = F_78 ( V_48 , V_103 ) ;
if ( V_96 )
goto V_114;
}
V_114:
return V_96 ;
}
static long F_91 ( unsigned short V_8 , unsigned short V_10 ,
T_1 * V_16 )
{
struct V_1 * V_44 , * V_97 ;
F_92 ( V_115 ) ;
int V_12 ;
if ( ! V_115 )
return - V_40 ;
V_44 = F_17 ( V_8 , V_10 , V_16 ) ;
if ( F_80 ( V_44 ) ) {
V_12 = F_81 ( V_44 ) ;
goto V_114;
}
F_93 ( V_116 ) ;
V_12 = F_13 ( V_44 , V_16 , V_115 ) ;
if ( V_12 ) {
F_94 ( V_116 ) ;
F_82 ( V_44 ) ;
goto V_114;
}
V_97 = V_116 -> V_1 ;
V_116 -> V_1 = V_44 ;
if ( V_44 && V_44 -> V_8 == V_117 )
V_116 -> V_118 = V_119 - 1 ;
F_94 ( V_116 ) ;
F_82 ( V_97 ) ;
V_12 = 0 ;
V_114:
F_95 ( V_115 ) ;
return V_12 ;
}
static void F_96 ( struct V_1 * V_3 , T_1 * V_16 )
{
F_97 ( * V_16 ) ;
if ( V_3 == & V_9 )
return;
switch ( V_3 -> V_8 ) {
case V_120 :
case V_117 :
* V_16 = V_3 -> V_18 . V_16 ;
break;
case V_27 :
if ( ! ( V_3 -> V_10 & V_19 ) )
F_98 ( V_3 -> V_18 . V_20 , * V_16 ) ;
break;
default:
F_69 () ;
}
}
static int F_99 ( unsigned long V_54 )
{
struct V_58 * V_3 ;
int V_96 ;
V_96 = F_100 ( V_54 & V_121 , 1 , 0 , & V_3 , NULL ) ;
if ( V_96 >= 0 ) {
V_96 = F_56 ( V_3 ) ;
F_50 ( V_3 ) ;
}
return V_96 ;
}
static long F_101 ( int * V_34 , T_1 * V_67 ,
unsigned long V_54 , unsigned long V_10 )
{
int V_96 ;
struct V_45 * V_46 = V_116 -> V_46 ;
struct V_47 * V_48 = NULL ;
struct V_1 * V_4 = V_116 -> V_1 ;
if ( V_10 &
~ ( unsigned long ) ( V_122 | V_123 | V_124 ) )
return - V_17 ;
if ( V_10 & V_124 ) {
if ( V_10 & ( V_122 | V_123 ) )
return - V_17 ;
* V_34 = 0 ;
F_93 ( V_116 ) ;
* V_67 = V_24 ;
F_94 ( V_116 ) ;
return 0 ;
}
if ( V_10 & V_123 ) {
F_102 ( & V_46 -> V_49 ) ;
V_48 = F_103 ( V_46 , V_54 , V_54 + 1 ) ;
if ( ! V_48 ) {
F_104 ( & V_46 -> V_49 ) ;
return - V_83 ;
}
if ( V_48 -> V_99 && V_48 -> V_99 -> V_125 )
V_4 = V_48 -> V_99 -> V_125 ( V_48 , V_54 ) ;
else
V_4 = V_48 -> V_52 ;
} else if ( V_54 )
return - V_17 ;
if ( ! V_4 )
V_4 = & V_9 ;
if ( V_10 & V_122 ) {
if ( V_10 & V_123 ) {
V_96 = F_99 ( V_54 ) ;
if ( V_96 < 0 )
goto V_114;
* V_34 = V_96 ;
} else if ( V_4 == V_116 -> V_1 &&
V_4 -> V_8 == V_117 ) {
* V_34 = F_105 ( V_116 -> V_118 , V_4 -> V_18 . V_16 ) ;
} else {
V_96 = - V_17 ;
goto V_114;
}
} else {
* V_34 = V_4 == & V_9 ? V_35 :
V_4 -> V_8 ;
* V_34 |= ( V_4 -> V_10 & V_11 ) ;
}
V_96 = 0 ;
if ( V_67 ) {
if ( F_3 ( V_4 ) ) {
* V_67 = V_4 -> V_30 . V_31 ;
} else {
F_93 ( V_116 ) ;
F_96 ( V_4 , V_67 ) ;
F_94 ( V_116 ) ;
}
}
V_114:
F_106 ( V_4 ) ;
if ( V_48 )
F_104 ( & V_116 -> V_46 -> V_49 ) ;
return V_96 ;
}
static void F_59 ( struct V_58 * V_58 , struct V_91 * V_69 ,
unsigned long V_10 )
{
if ( ( V_10 & V_73 ) || F_67 ( V_58 ) == 1 ) {
if ( ! F_107 ( V_58 ) ) {
F_108 ( & V_58 -> V_126 , V_69 ) ;
F_109 ( V_58 , V_127 +
F_110 ( V_58 ) ) ;
}
}
}
static struct V_58 * F_111 ( struct V_58 * V_58 , unsigned long V_5 , int * * V_128 )
{
if ( F_112 ( V_58 ) )
return F_113 ( F_114 ( F_115 ( V_58 ) ) ,
V_5 ) ;
else
return F_116 ( V_5 , V_129 |
V_130 , 0 ) ;
}
static int F_117 ( struct V_45 * V_46 , int V_131 , int V_132 ,
int V_10 )
{
T_1 V_67 ;
F_118 ( V_69 ) ;
int V_96 = 0 ;
F_97 ( V_67 ) ;
F_98 ( V_131 , V_67 ) ;
F_15 ( ! ( V_10 & ( V_74 | V_73 ) ) ) ;
F_76 ( V_46 , V_46 -> V_50 -> V_81 , V_46 -> V_133 , & V_67 ,
V_10 | V_82 , & V_69 ) ;
if ( ! F_119 ( & V_69 ) ) {
V_96 = F_120 ( & V_69 , F_111 , NULL , V_132 ,
V_134 , V_135 ) ;
if ( V_96 )
F_121 ( & V_69 ) ;
}
return V_96 ;
}
int F_122 ( struct V_45 * V_46 , const T_1 * V_136 ,
const T_1 * V_137 , int V_10 )
{
int V_138 = 0 ;
int V_96 ;
T_1 V_15 ;
V_96 = F_123 () ;
if ( V_96 )
return V_96 ;
F_102 ( & V_46 -> V_49 ) ;
V_15 = * V_136 ;
while ( ! F_9 ( V_15 ) ) {
int V_139 , V_140 ;
int V_131 = V_6 ;
int V_132 = 0 ;
F_124 (s, tmp) {
if ( ( F_6 ( * V_136 ) != F_6 ( * V_137 ) ) &&
( F_30 ( V_139 , * V_137 ) ) )
continue;
V_140 = F_31 ( V_139 , * V_136 , * V_137 ) ;
if ( V_139 == V_140 )
continue;
V_131 = V_139 ;
V_132 = V_140 ;
if ( ! F_30 ( V_132 , V_15 ) )
break;
}
if ( V_131 == V_6 )
break;
F_125 ( V_131 , V_15 ) ;
V_96 = F_117 ( V_46 , V_131 , V_132 , V_10 ) ;
if ( V_96 > 0 )
V_138 += V_96 ;
if ( V_96 < 0 )
break;
}
F_104 ( & V_46 -> V_49 ) ;
if ( V_96 < 0 )
return V_96 ;
return V_138 ;
}
static struct V_58 * F_126 ( struct V_58 * V_58 , unsigned long V_78 , int * * V_128 )
{
struct V_47 * V_48 ;
unsigned long V_141 ( V_142 ) ;
V_48 = F_84 ( V_116 -> V_46 , V_78 ) ;
while ( V_48 ) {
V_142 = F_127 ( V_58 , V_48 ) ;
if ( V_142 != - V_83 )
break;
V_48 = V_48 -> V_51 ;
}
if ( F_112 ( V_58 ) ) {
F_128 ( ! V_48 ) ;
return F_129 ( V_48 , V_142 , 1 ) ;
}
return F_130 ( V_129 | V_143 ,
V_48 , V_142 ) ;
}
static void F_59 ( struct V_58 * V_58 , struct V_91 * V_69 ,
unsigned long V_10 )
{
}
int F_122 ( struct V_45 * V_46 , const T_1 * V_136 ,
const T_1 * V_137 , int V_10 )
{
return - V_144 ;
}
static struct V_58 * F_126 ( struct V_58 * V_58 , unsigned long V_78 , int * * V_128 )
{
return NULL ;
}
static long F_131 ( unsigned long V_78 , unsigned long V_145 ,
unsigned short V_8 , unsigned short V_146 ,
T_1 * V_67 , unsigned long V_10 )
{
struct V_45 * V_46 = V_116 -> V_46 ;
struct V_1 * V_44 ;
unsigned long V_55 ;
int V_96 ;
F_118 ( V_69 ) ;
if ( V_10 & ~ ( unsigned long ) V_147 )
return - V_17 ;
if ( ( V_10 & V_73 ) && ! F_132 ( V_148 ) )
return - V_149 ;
if ( V_78 & ~ V_121 )
return - V_17 ;
if ( V_8 == V_35 )
V_10 &= ~ V_150 ;
V_145 = ( V_145 + V_66 - 1 ) & V_121 ;
V_55 = V_78 + V_145 ;
if ( V_55 < V_78 )
return - V_17 ;
if ( V_55 == V_78 )
return 0 ;
V_44 = F_17 ( V_8 , V_146 , V_67 ) ;
if ( F_80 ( V_44 ) )
return F_81 ( V_44 ) ;
if ( V_10 & V_85 )
V_44 -> V_10 |= V_151 ;
if ( ! V_44 )
V_10 |= V_82 ;
F_18 ( L_3 ,
V_78 , V_78 + V_145 , V_8 , V_146 ,
V_67 ? F_19 ( * V_67 ) [ 0 ] : V_6 ) ;
if ( V_10 & ( V_74 | V_73 ) ) {
V_96 = F_123 () ;
if ( V_96 )
goto V_152;
}
{
F_92 ( V_115 ) ;
if ( V_115 ) {
F_37 ( & V_46 -> V_49 ) ;
F_93 ( V_116 ) ;
V_96 = F_13 ( V_44 , V_67 , V_115 ) ;
F_94 ( V_116 ) ;
if ( V_96 )
F_38 ( & V_46 -> V_49 ) ;
} else
V_96 = - V_40 ;
F_95 ( V_115 ) ;
}
if ( V_96 )
goto V_152;
V_96 = F_76 ( V_46 , V_78 , V_55 , V_67 ,
V_10 | V_68 , & V_69 ) ;
if ( ! V_96 )
V_96 = F_83 ( V_46 , V_78 , V_55 , V_44 ) ;
if ( ! V_96 ) {
int V_153 = 0 ;
if ( ! F_119 ( & V_69 ) ) {
F_133 ( V_10 & V_85 ) ;
V_153 = F_120 ( & V_69 , F_126 , NULL ,
V_78 , V_134 , V_154 ) ;
if ( V_153 )
F_121 ( & V_69 ) ;
}
if ( V_153 && ( V_10 & V_150 ) )
V_96 = - V_155 ;
} else
F_121 ( & V_69 ) ;
F_38 ( & V_46 -> V_49 ) ;
V_152:
F_82 ( V_44 ) ;
return V_96 ;
}
static int F_134 ( T_1 * V_16 , const unsigned long T_6 * V_67 ,
unsigned long V_156 )
{
unsigned long V_157 ;
unsigned long V_158 ;
unsigned long V_159 ;
-- V_156 ;
F_97 ( * V_16 ) ;
if ( V_156 == 0 || ! V_67 )
return 0 ;
if ( V_156 > V_66 * V_160 )
return - V_17 ;
V_158 = F_135 ( V_156 ) ;
if ( ( V_156 % V_161 ) == 0 )
V_159 = ~ 0UL ;
else
V_159 = ( 1UL << ( V_156 % V_161 ) ) - 1 ;
if ( V_158 > F_135 ( V_119 ) ) {
if ( V_158 > V_66 / sizeof( long ) )
return - V_17 ;
for ( V_157 = F_135 ( V_119 ) ; V_157 < V_158 ; V_157 ++ ) {
unsigned long V_162 ;
if ( F_136 ( V_162 , V_67 + V_157 ) )
return - V_83 ;
if ( V_157 == V_158 - 1 ) {
if ( V_162 & V_159 )
return - V_17 ;
} else if ( V_162 )
return - V_17 ;
}
V_158 = F_135 ( V_119 ) ;
V_159 = ~ 0UL ;
}
if ( F_137 ( F_19 ( * V_16 ) , V_67 , V_158 *sizeof( unsigned long ) ) )
return - V_83 ;
F_19 ( * V_16 ) [ V_158 - 1 ] &= V_159 ;
return 0 ;
}
static int F_138 ( unsigned long T_6 * V_163 , unsigned long V_156 ,
T_1 * V_16 )
{
unsigned long V_164 = F_139 ( V_156 - 1 , 64 ) / 8 ;
const int V_165 = F_135 ( V_119 ) * sizeof( long ) ;
if ( V_164 > V_165 ) {
if ( V_164 > V_66 )
return - V_17 ;
if ( F_140 ( ( char T_6 * ) V_163 + V_165 , V_164 - V_165 ) )
return - V_83 ;
V_164 = V_165 ;
}
return F_141 ( V_163 , F_19 ( * V_16 ) , V_164 ) ? - V_83 : 0 ;
}
struct V_1 * F_142 ( struct V_47 * V_48 ,
unsigned long V_54 )
{
struct V_1 * V_4 = NULL ;
if ( V_48 ) {
if ( V_48 -> V_99 && V_48 -> V_99 -> V_125 ) {
V_4 = V_48 -> V_99 -> V_125 ( V_48 , V_54 ) ;
} else if ( V_48 -> V_52 ) {
V_4 = V_48 -> V_52 ;
if ( F_143 ( V_4 ) )
F_144 ( V_4 ) ;
}
}
return V_4 ;
}
static struct V_1 * F_145 ( struct V_47 * V_48 ,
unsigned long V_54 )
{
struct V_1 * V_4 = F_142 ( V_48 , V_54 ) ;
if ( ! V_4 )
V_4 = F_1 ( V_116 ) ;
return V_4 ;
}
bool F_146 ( struct V_47 * V_48 )
{
struct V_1 * V_4 ;
if ( V_48 -> V_99 && V_48 -> V_99 -> V_125 ) {
bool V_12 = false ;
V_4 = V_48 -> V_99 -> V_125 ( V_48 , V_48 -> V_81 ) ;
if ( V_4 && ( V_4 -> V_10 & V_151 ) )
V_12 = true ;
F_106 ( V_4 ) ;
return V_12 ;
}
V_4 = V_48 -> V_52 ;
if ( ! V_4 )
V_4 = F_1 ( V_116 ) ;
return V_4 -> V_10 & V_151 ;
}
static int F_147 ( struct V_1 * V_34 , enum V_166 V_167 )
{
enum V_166 V_168 = V_169 ;
F_128 ( V_168 == V_170 ) ;
if ( ! F_148 ( V_34 -> V_18 . V_16 , V_25 [ V_171 ] ) )
V_168 = V_170 ;
return V_167 >= V_168 ;
}
static T_1 * F_149 ( T_7 V_172 , struct V_1 * V_34 )
{
if ( F_150 ( V_34 -> V_8 == V_120 ) &&
F_147 ( V_34 , F_151 ( V_172 ) ) &&
F_152 ( & V_34 -> V_18 . V_16 ) )
return & V_34 -> V_18 . V_16 ;
return NULL ;
}
static int F_153 ( T_7 V_172 , struct V_1 * V_34 ,
int V_173 )
{
if ( V_34 -> V_8 == V_27 && ! ( V_34 -> V_10 & V_19 ) )
V_173 = V_34 -> V_18 . V_20 ;
else {
F_133 ( V_34 -> V_8 == V_120 && ( V_172 & V_130 ) ) ;
}
return V_173 ;
}
static unsigned F_154 ( struct V_1 * V_34 )
{
unsigned V_104 ;
struct V_2 * V_174 = V_116 ;
V_104 = F_105 ( V_174 -> V_118 , V_34 -> V_18 . V_16 ) ;
if ( V_104 < V_119 )
V_174 -> V_118 = V_104 ;
return V_104 ;
}
unsigned int F_155 ( void )
{
struct V_1 * V_34 ;
int V_5 = F_156 () ;
if ( F_157 () )
return V_5 ;
V_34 = V_116 -> V_1 ;
if ( ! V_34 || V_34 -> V_10 & V_19 )
return V_5 ;
switch ( V_34 -> V_8 ) {
case V_27 :
return V_34 -> V_18 . V_20 ;
case V_117 :
return F_154 ( V_34 ) ;
case V_120 : {
struct V_175 * V_176 ;
struct V_177 * V_177 ;
enum V_166 V_178 = F_151 ( V_39 ) ;
V_177 = & F_158 ( V_5 ) -> V_179 [ V_180 ] ;
V_176 = F_159 ( V_177 , V_178 ,
& V_34 -> V_18 . V_16 ) ;
return V_176 -> V_167 ? V_176 -> V_167 -> V_5 : V_5 ;
}
default:
F_69 () ;
}
}
static unsigned F_160 ( struct V_1 * V_4 ,
struct V_47 * V_48 , unsigned long V_181 )
{
unsigned V_182 = F_6 ( V_4 -> V_18 . V_16 ) ;
unsigned V_183 ;
int V_184 ;
int V_62 ;
if ( ! V_182 )
return F_2 () ;
V_183 = ( unsigned int ) V_181 % V_182 ;
V_62 = F_11 ( V_4 -> V_18 . V_16 ) ;
for ( V_184 = 0 ; V_184 < V_183 ; V_184 ++ )
V_62 = F_161 ( V_62 , V_4 -> V_18 . V_16 ) ;
return V_62 ;
}
static inline unsigned F_162 ( struct V_1 * V_4 ,
struct V_47 * V_48 , unsigned long V_54 , int V_185 )
{
if ( V_48 ) {
unsigned long V_186 ;
F_128 ( V_185 < V_109 ) ;
V_186 = V_48 -> V_98 >> ( V_185 - V_109 ) ;
V_186 += ( V_54 - V_48 -> V_81 ) >> V_185 ;
return F_160 ( V_4 , V_48 , V_186 ) ;
} else
return F_154 ( V_4 ) ;
}
int F_163 ( struct V_47 * V_48 , unsigned long V_54 , T_7 V_187 ,
struct V_1 * * V_188 , T_1 * * V_189 )
{
int V_62 ;
* V_188 = F_145 ( V_48 , V_54 ) ;
* V_189 = NULL ;
if ( F_150 ( ( * V_188 ) -> V_8 == V_117 ) ) {
V_62 = F_162 ( * V_188 , V_48 , V_54 ,
F_164 ( F_64 ( V_48 ) ) ) ;
} else {
V_62 = F_153 ( V_187 , * V_188 , F_2 () ) ;
if ( ( * V_188 ) -> V_8 == V_120 )
* V_189 = & ( * V_188 ) -> V_18 . V_16 ;
}
return V_62 ;
}
bool F_165 ( T_1 * V_163 )
{
struct V_1 * V_1 ;
int V_62 ;
if ( ! ( V_163 && V_116 -> V_1 ) )
return false ;
F_93 ( V_116 ) ;
V_1 = V_116 -> V_1 ;
switch ( V_1 -> V_8 ) {
case V_27 :
if ( V_1 -> V_10 & V_19 )
V_62 = F_2 () ;
else
V_62 = V_1 -> V_18 . V_20 ;
F_166 ( V_163 , V_62 ) ;
break;
case V_120 :
case V_117 :
* V_163 = V_1 -> V_18 . V_16 ;
break;
default:
F_69 () ;
}
F_94 ( V_116 ) ;
return true ;
}
bool F_167 ( struct V_2 * V_43 ,
const T_1 * V_163 )
{
struct V_1 * V_1 ;
bool V_12 = true ;
if ( ! V_163 )
return V_12 ;
F_93 ( V_43 ) ;
V_1 = V_43 -> V_1 ;
if ( ! V_1 )
goto V_114;
switch ( V_1 -> V_8 ) {
case V_27 :
break;
case V_120 :
case V_117 :
V_12 = F_148 ( V_1 -> V_18 . V_16 , * V_163 ) ;
break;
default:
F_69 () ;
}
V_114:
F_94 ( V_43 ) ;
return V_12 ;
}
static struct V_58 * F_168 ( T_7 V_172 , unsigned V_190 ,
unsigned V_62 )
{
struct V_58 * V_58 ;
V_58 = F_169 ( V_172 , V_190 , V_62 ) ;
if ( V_58 && F_56 ( V_58 ) == V_62 )
F_170 ( V_58 , V_191 ) ;
return V_58 ;
}
struct V_58 *
F_171 ( T_7 V_172 , int V_190 , struct V_47 * V_48 ,
unsigned long V_54 , int V_5 , bool V_192 )
{
struct V_1 * V_4 ;
struct V_58 * V_58 ;
int V_193 ;
T_1 * V_67 ;
V_4 = F_145 ( V_48 , V_54 ) ;
if ( V_4 -> V_8 == V_117 ) {
unsigned V_62 ;
V_62 = F_162 ( V_4 , V_48 , V_54 , V_109 + V_190 ) ;
F_106 ( V_4 ) ;
V_58 = F_168 ( V_172 , V_190 , V_62 ) ;
goto V_114;
}
if ( F_150 ( F_172 ( V_194 ) && V_192 ) ) {
int V_195 = V_5 ;
if ( V_4 -> V_8 == V_27 &&
! ( V_4 -> V_10 & V_19 ) )
V_195 = V_4 -> V_18 . V_20 ;
V_67 = F_149 ( V_172 , V_4 ) ;
if ( ! V_67 || F_30 ( V_195 , * V_67 ) ) {
F_106 ( V_4 ) ;
V_58 = F_116 ( V_195 ,
V_172 | V_130 , V_190 ) ;
goto V_114;
}
}
V_67 = F_149 ( V_172 , V_4 ) ;
V_193 = F_153 ( V_172 , V_4 , V_5 ) ;
V_58 = F_173 ( V_172 , V_190 , V_193 , V_67 ) ;
F_106 ( V_4 ) ;
V_114:
return V_58 ;
}
struct V_58 * F_174 ( T_7 V_172 , unsigned V_190 )
{
struct V_1 * V_4 = & V_9 ;
struct V_58 * V_58 ;
if ( ! F_157 () && ! ( V_172 & V_130 ) )
V_4 = F_1 ( V_116 ) ;
if ( V_4 -> V_8 == V_117 )
V_58 = F_168 ( V_172 , V_190 , F_154 ( V_4 ) ) ;
else
V_58 = F_173 ( V_172 , V_190 ,
F_153 ( V_172 , V_4 , F_2 () ) ,
F_149 ( V_172 , V_4 ) ) ;
return V_58 ;
}
int F_175 ( struct V_47 * V_196 , struct V_47 * V_197 )
{
struct V_1 * V_4 = F_79 ( F_88 ( V_196 ) ) ;
if ( F_80 ( V_4 ) )
return F_81 ( V_4 ) ;
V_197 -> V_52 = V_4 ;
return 0 ;
}
struct V_1 * F_176 ( struct V_1 * V_97 )
{
struct V_1 * V_44 = F_21 ( V_38 , V_39 ) ;
if ( ! V_44 )
return F_20 ( - V_40 ) ;
if ( V_97 == V_116 -> V_1 ) {
F_93 ( V_116 ) ;
* V_44 = * V_97 ;
F_94 ( V_116 ) ;
} else
* V_44 = * V_97 ;
if ( F_177 () ) {
T_1 V_198 = V_32 ( V_116 ) ;
F_32 ( V_44 , & V_198 ) ;
}
F_22 ( & V_44 -> V_41 , 1 ) ;
return V_44 ;
}
bool F_178 ( struct V_1 * V_199 , struct V_1 * V_200 )
{
if ( ! V_199 || ! V_200 )
return false ;
if ( V_199 -> V_8 != V_200 -> V_8 )
return false ;
if ( V_199 -> V_10 != V_200 -> V_10 )
return false ;
if ( F_3 ( V_199 ) )
if ( ! F_33 ( V_199 -> V_30 . V_31 , V_200 -> V_30 . V_31 ) )
return false ;
switch ( V_199 -> V_8 ) {
case V_120 :
case V_117 :
return ! ! F_33 ( V_199 -> V_18 . V_16 , V_200 -> V_18 . V_16 ) ;
case V_27 :
return V_199 -> V_18 . V_20 == V_200 -> V_18 . V_20 ;
default:
F_69 () ;
return false ;
}
}
static struct V_201 *
F_179 ( struct V_202 * V_203 , unsigned long V_78 , unsigned long V_55 )
{
struct V_204 * V_181 = V_203 -> V_205 . V_204 ;
while ( V_181 ) {
struct V_201 * V_3 = F_180 ( V_181 , struct V_201 , V_173 ) ;
if ( V_78 >= V_3 -> V_55 )
V_181 = V_181 -> V_206 ;
else if ( V_55 <= V_3 -> V_78 )
V_181 = V_181 -> V_207 ;
else
break;
}
if ( ! V_181 )
return NULL ;
for (; ; ) {
struct V_201 * V_30 = NULL ;
struct V_204 * V_84 = F_181 ( V_181 ) ;
if ( ! V_84 )
break;
V_30 = F_180 ( V_84 , struct V_201 , V_173 ) ;
if ( V_30 -> V_55 <= V_78 )
break;
V_181 = V_84 ;
}
return F_180 ( V_181 , struct V_201 , V_173 ) ;
}
static void F_182 ( struct V_202 * V_203 , struct V_201 * V_44 )
{
struct V_204 * * V_3 = & V_203 -> V_205 . V_204 ;
struct V_204 * V_208 = NULL ;
struct V_201 * V_173 ;
while ( * V_3 ) {
V_208 = * V_3 ;
V_173 = F_180 ( V_208 , struct V_201 , V_173 ) ;
if ( V_44 -> V_78 < V_173 -> V_78 )
V_3 = & ( * V_3 ) -> V_207 ;
else if ( V_44 -> V_55 > V_173 -> V_55 )
V_3 = & ( * V_3 ) -> V_206 ;
else
F_69 () ;
}
F_183 ( & V_44 -> V_173 , V_208 , V_3 ) ;
F_184 ( & V_44 -> V_173 , & V_203 -> V_205 ) ;
F_18 ( L_4 , V_44 -> V_78 , V_44 -> V_55 ,
V_44 -> V_34 ? V_44 -> V_34 -> V_8 : 0 ) ;
}
struct V_1 *
F_185 ( struct V_202 * V_203 , unsigned long V_209 )
{
struct V_1 * V_4 = NULL ;
struct V_201 * V_210 ;
if ( ! V_203 -> V_205 . V_204 )
return NULL ;
F_186 ( & V_203 -> V_211 ) ;
V_210 = F_179 ( V_203 , V_209 , V_209 + 1 ) ;
if ( V_210 ) {
F_144 ( V_210 -> V_34 ) ;
V_4 = V_210 -> V_34 ;
}
F_187 ( & V_203 -> V_211 ) ;
return V_4 ;
}
static void F_188 ( struct V_201 * V_181 )
{
F_82 ( V_181 -> V_34 ) ;
F_25 ( V_212 , V_181 ) ;
}
int F_189 ( struct V_58 * V_58 , struct V_47 * V_48 , unsigned long V_54 )
{
struct V_1 * V_4 ;
struct V_175 * V_176 ;
int V_213 = F_56 ( V_58 ) ;
unsigned long V_105 ;
int V_214 = F_190 () ;
int V_215 = F_191 ( V_214 ) ;
int V_216 = - 1 ;
int V_12 = - 1 ;
F_128 ( ! V_48 ) ;
V_4 = F_145 ( V_48 , V_54 ) ;
if ( ! ( V_4 -> V_10 & V_151 ) )
goto V_114;
switch ( V_4 -> V_8 ) {
case V_117 :
F_128 ( V_54 >= V_48 -> V_80 ) ;
F_128 ( V_54 < V_48 -> V_81 ) ;
V_105 = V_48 -> V_98 ;
V_105 += ( V_54 - V_48 -> V_81 ) >> V_109 ;
V_216 = F_160 ( V_4 , V_48 , V_105 ) ;
break;
case V_27 :
if ( V_4 -> V_10 & V_19 )
V_216 = F_2 () ;
else
V_216 = V_4 -> V_18 . V_20 ;
break;
case V_120 :
if ( F_30 ( V_213 , V_4 -> V_18 . V_16 ) )
goto V_114;
V_176 = F_159 (
F_192 ( F_2 () , V_217 ) ,
F_151 ( V_217 ) ,
& V_4 -> V_18 . V_16 ) ;
V_216 = V_176 -> V_167 -> V_5 ;
break;
default:
F_69 () ;
}
if ( V_4 -> V_10 & V_218 ) {
V_216 = V_215 ;
if ( ! F_193 ( V_116 , V_58 , V_213 , V_214 ) )
goto V_114;
}
if ( V_213 != V_216 )
V_12 = V_216 ;
V_114:
F_106 ( V_4 ) ;
return V_12 ;
}
void F_194 ( struct V_2 * V_219 )
{
struct V_1 * V_4 ;
F_93 ( V_219 ) ;
V_4 = V_219 -> V_1 ;
V_219 -> V_1 = NULL ;
F_94 ( V_219 ) ;
F_82 ( V_4 ) ;
}
static void F_195 ( struct V_202 * V_203 , struct V_201 * V_181 )
{
F_18 ( L_5 , V_181 -> V_78 , V_181 -> V_55 ) ;
F_196 ( & V_181 -> V_173 , & V_203 -> V_205 ) ;
F_188 ( V_181 ) ;
}
static void F_197 ( struct V_201 * V_5 , unsigned long V_78 ,
unsigned long V_55 , struct V_1 * V_4 )
{
V_5 -> V_78 = V_78 ;
V_5 -> V_55 = V_55 ;
V_5 -> V_34 = V_4 ;
}
static struct V_201 * F_198 ( unsigned long V_78 , unsigned long V_55 ,
struct V_1 * V_4 )
{
struct V_201 * V_181 ;
struct V_1 * V_220 ;
V_181 = F_21 ( V_212 , V_39 ) ;
if ( ! V_181 )
return NULL ;
V_220 = F_79 ( V_4 ) ;
if ( F_80 ( V_220 ) ) {
F_25 ( V_212 , V_181 ) ;
return NULL ;
}
V_220 -> V_10 |= V_221 ;
F_197 ( V_181 , V_78 , V_55 , V_220 ) ;
return V_181 ;
}
static int F_199 ( struct V_202 * V_203 , unsigned long V_78 ,
unsigned long V_55 , struct V_201 * V_44 )
{
struct V_201 * V_181 ;
struct V_201 * V_222 = NULL ;
struct V_1 * F_17 = NULL ;
int V_12 = 0 ;
V_223:
F_200 ( & V_203 -> V_211 ) ;
V_181 = F_179 ( V_203 , V_78 , V_55 ) ;
while ( V_181 && V_181 -> V_78 < V_55 ) {
struct V_204 * V_104 = F_201 ( & V_181 -> V_173 ) ;
if ( V_181 -> V_78 >= V_78 ) {
if ( V_181 -> V_55 <= V_55 )
F_195 ( V_203 , V_181 ) ;
else
V_181 -> V_78 = V_55 ;
} else {
if ( V_181 -> V_55 > V_55 ) {
if ( ! V_222 )
goto V_224;
* F_17 = * V_181 -> V_34 ;
F_22 ( & F_17 -> V_41 , 1 ) ;
F_197 ( V_222 , V_55 , V_181 -> V_55 , F_17 ) ;
V_181 -> V_55 = V_78 ;
F_182 ( V_203 , V_222 ) ;
V_222 = NULL ;
F_17 = NULL ;
break;
} else
V_181 -> V_55 = V_78 ;
}
if ( ! V_104 )
break;
V_181 = F_180 ( V_104 , struct V_201 , V_173 ) ;
}
if ( V_44 )
F_182 ( V_203 , V_44 ) ;
F_202 ( & V_203 -> V_211 ) ;
V_12 = 0 ;
V_102:
if ( F_17 )
F_82 ( F_17 ) ;
if ( V_222 )
F_25 ( V_212 , V_222 ) ;
return V_12 ;
V_224:
F_202 ( & V_203 -> V_211 ) ;
V_12 = - V_40 ;
V_222 = F_21 ( V_212 , V_39 ) ;
if ( ! V_222 )
goto V_102;
F_17 = F_21 ( V_38 , V_39 ) ;
if ( ! F_17 )
goto V_102;
goto V_223;
}
void F_203 ( struct V_202 * V_203 , struct V_1 * V_188 )
{
int V_12 ;
V_203 -> V_205 = V_225 ;
F_204 ( & V_203 -> V_211 ) ;
if ( V_188 ) {
struct V_47 V_226 ;
struct V_1 * V_44 ;
F_92 ( V_115 ) ;
if ( ! V_115 )
goto V_227;
V_44 = F_17 ( V_188 -> V_8 , V_188 -> V_10 , & V_188 -> V_30 . V_31 ) ;
if ( F_80 ( V_44 ) )
goto V_228;
F_93 ( V_116 ) ;
V_12 = F_13 ( V_44 , & V_188 -> V_30 . V_31 , V_115 ) ;
F_94 ( V_116 ) ;
if ( V_12 )
goto V_229;
memset ( & V_226 , 0 , sizeof( struct V_47 ) ) ;
V_226 . V_80 = V_230 ;
F_205 ( V_203 , & V_226 , V_44 ) ;
V_229:
F_82 ( V_44 ) ;
V_228:
F_95 ( V_115 ) ;
V_227:
F_82 ( V_188 ) ;
}
}
int F_205 ( struct V_202 * V_231 ,
struct V_47 * V_48 , struct V_1 * V_232 )
{
int V_96 ;
struct V_201 * V_44 = NULL ;
unsigned long V_233 = F_206 ( V_48 ) ;
F_18 ( L_6 ,
V_48 -> V_98 ,
V_233 , V_232 ? V_232 -> V_8 : - 1 ,
V_232 ? V_232 -> V_10 : - 1 ,
V_232 ? F_19 ( V_232 -> V_18 . V_16 ) [ 0 ] : V_6 ) ;
if ( V_232 ) {
V_44 = F_198 ( V_48 -> V_98 , V_48 -> V_98 + V_233 , V_232 ) ;
if ( ! V_44 )
return - V_40 ;
}
V_96 = F_199 ( V_231 , V_48 -> V_98 , V_48 -> V_98 + V_233 , V_44 ) ;
if ( V_96 && V_44 )
F_188 ( V_44 ) ;
return V_96 ;
}
void F_207 ( struct V_202 * V_3 )
{
struct V_201 * V_181 ;
struct V_204 * V_104 ;
if ( ! V_3 -> V_205 . V_204 )
return;
F_200 ( & V_3 -> V_211 ) ;
V_104 = F_208 ( & V_3 -> V_205 ) ;
while ( V_104 ) {
V_181 = F_180 ( V_104 , struct V_201 , V_173 ) ;
V_104 = F_201 ( & V_181 -> V_173 ) ;
F_195 ( V_3 , V_181 ) ;
}
F_202 ( & V_3 -> V_211 ) ;
}
static void T_8 F_209 ( void )
{
bool V_234 = false ;
if ( F_172 ( V_235 ) )
V_234 = true ;
if ( V_236 )
F_210 ( V_236 == 1 ) ;
if ( F_211 () > 1 && ! V_236 ) {
F_212 ( L_7 ,
V_234 ? L_8 : L_9 ) ;
F_210 ( V_234 ) ;
}
}
static int T_8 F_213 ( char * V_237 )
{
int V_12 = 0 ;
if ( ! V_237 )
goto V_114;
if ( ! strcmp ( V_237 , L_10 ) ) {
V_236 = 1 ;
V_12 = 1 ;
} else if ( ! strcmp ( V_237 , L_11 ) ) {
V_236 = - 1 ;
V_12 = 1 ;
}
V_114:
if ( ! V_12 )
F_214 ( L_12 ) ;
return V_12 ;
}
static inline void T_8 F_209 ( void )
{
}
void T_8 F_215 ( void )
{
T_1 F_154 ;
unsigned long V_238 = 0 ;
int V_62 , V_239 = 0 ;
V_38 = F_216 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_240 , NULL ) ;
V_212 = F_216 ( L_14 ,
sizeof( struct V_201 ) ,
0 , V_240 , NULL ) ;
F_217 (nid) {
V_7 [ V_62 ] = (struct V_1 ) {
. V_41 = F_218 ( 1 ) ,
. V_8 = V_27 ,
. V_10 = V_151 | V_218 ,
. V_18 = { . V_20 = V_62 , } ,
} ;
}
F_97 ( F_154 ) ;
F_219 (nid, N_MEMORY) {
unsigned long V_241 = F_220 ( V_62 ) ;
if ( V_238 < V_241 ) {
V_238 = V_241 ;
V_239 = V_62 ;
}
if ( ( V_241 << V_109 ) >= ( 16 << 20 ) )
F_98 ( V_62 , F_154 ) ;
}
if ( F_150 ( F_9 ( F_154 ) ) )
F_98 ( V_239 , F_154 ) ;
if ( F_91 ( V_117 , 0 , & F_154 ) )
F_221 ( L_15 , V_242 ) ;
F_209 () ;
}
void F_222 ( void )
{
F_91 ( V_35 , 0 , NULL ) ;
}
int F_223 ( char * V_237 , struct V_1 * * V_188 )
{
struct V_1 * V_44 = NULL ;
unsigned short V_8 ;
unsigned short V_146 ;
T_1 V_16 ;
char * V_243 = strchr ( V_237 , ':' ) ;
char * V_10 = strchr ( V_237 , '=' ) ;
int V_96 = 1 ;
if ( V_243 ) {
* V_243 ++ = '\0' ;
if ( F_224 ( V_243 , V_16 ) )
goto V_114;
if ( ! F_225 ( V_16 , V_25 [ V_26 ] ) )
goto V_114;
} else
F_97 ( V_16 ) ;
if ( V_10 )
* V_10 ++ = '\0' ;
for ( V_8 = 0 ; V_8 < V_244 ; V_8 ++ ) {
if ( ! strcmp ( V_237 , V_245 [ V_8 ] ) ) {
break;
}
}
if ( V_8 >= V_244 )
goto V_114;
switch ( V_8 ) {
case V_27 :
if ( V_243 ) {
char * V_246 = V_243 ;
while ( isdigit ( * V_246 ) )
V_246 ++ ;
if ( * V_246 )
goto V_114;
}
break;
case V_117 :
if ( ! V_243 )
V_16 = V_25 [ V_26 ] ;
break;
case V_37 :
if ( V_243 )
goto V_114;
V_8 = V_27 ;
break;
case V_35 :
if ( ! V_243 )
V_96 = 0 ;
goto V_114;
case V_120 :
if ( ! V_243 )
goto V_114;
}
V_146 = 0 ;
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_16 ) )
V_146 |= V_36 ;
else if ( ! strcmp ( V_10 , L_17 ) )
V_146 |= V_28 ;
else
goto V_114;
}
V_44 = F_17 ( V_8 , V_146 , & V_16 ) ;
if ( F_80 ( V_44 ) )
goto V_114;
if ( V_8 != V_27 )
V_44 -> V_18 . V_16 = V_16 ;
else if ( V_243 )
V_44 -> V_18 . V_20 = F_11 ( V_16 ) ;
else
V_44 -> V_10 |= V_19 ;
V_44 -> V_30 . V_31 = V_16 ;
V_96 = 0 ;
V_114:
if ( V_243 )
* -- V_243 = ':' ;
if ( V_10 )
* -- V_10 = '=' ;
if ( ! V_96 )
* V_188 = V_44 ;
return V_96 ;
}
void F_226 ( char * V_247 , int V_248 , struct V_1 * V_4 )
{
char * V_3 = V_247 ;
T_1 V_16 = V_249 ;
unsigned short V_8 = V_35 ;
unsigned short V_10 = 0 ;
if ( V_4 && V_4 != & V_9 && ! ( V_4 -> V_10 & V_218 ) ) {
V_8 = V_4 -> V_8 ;
V_10 = V_4 -> V_10 ;
}
switch ( V_8 ) {
case V_35 :
break;
case V_27 :
if ( V_10 & V_19 )
V_8 = V_37 ;
else
F_98 ( V_4 -> V_18 . V_20 , V_16 ) ;
break;
case V_120 :
case V_117 :
V_16 = V_4 -> V_18 . V_16 ;
break;
default:
F_133 ( 1 ) ;
snprintf ( V_3 , V_248 , L_18 ) ;
return;
}
V_3 += snprintf ( V_3 , V_248 , L_19 , V_245 [ V_8 ] ) ;
if ( V_10 & V_11 ) {
V_3 += snprintf ( V_3 , V_247 + V_248 - V_3 , L_20 ) ;
if ( V_10 & V_36 )
V_3 += snprintf ( V_3 , V_247 + V_248 - V_3 , L_16 ) ;
else if ( V_10 & V_28 )
V_3 += snprintf ( V_3 , V_247 + V_248 - V_3 , L_17 ) ;
}
if ( ! F_9 ( V_16 ) )
V_3 += F_227 ( V_3 , V_247 + V_248 - V_3 , L_21 ,
F_228 ( & V_16 ) ) ;
}
