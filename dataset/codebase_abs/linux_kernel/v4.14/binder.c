static int F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_5 < 2 )
F_3 ( & V_6 ) ;
return V_4 ;
}
static inline void F_4 ( enum V_7 type )
{
F_5 ( & V_8 . V_9 [ type ] ) ;
}
static inline void F_6 ( enum V_7 type )
{
F_5 ( & V_8 . V_10 [ type ] ) ;
}
static struct V_11 * F_7 (
struct V_12 * log )
{
struct V_11 * V_13 ;
unsigned int V_14 = F_8 ( & log -> V_14 ) ;
if ( V_14 >= F_9 ( log -> V_15 ) )
log -> V_16 = 1 ;
V_13 = & log -> V_15 [ V_14 % F_9 ( log -> V_15 ) ] ;
F_10 ( V_13 -> V_17 , 0 ) ;
F_11 () ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
return V_13 ;
}
static void
F_12 ( struct V_18 * V_19 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_14 ( & V_19 -> V_22 ) ;
}
static void
F_15 ( struct V_18 * V_19 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_16 ( & V_19 -> V_22 ) ;
}
static void
F_17 ( struct V_18 * V_19 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_14 ( & V_19 -> V_23 ) ;
}
static void
F_18 ( struct V_18 * V_19 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_16 ( & V_19 -> V_23 ) ;
}
static void
F_19 ( struct V_24 * V_25 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_14 ( & V_25 -> V_26 ) ;
}
static void
F_20 ( struct V_24 * V_25 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_16 ( & V_25 -> V_26 ) ;
}
static void
F_21 ( struct V_24 * V_25 , int line )
{
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
F_14 ( & V_25 -> V_26 ) ;
if ( V_25 -> V_19 )
F_22 ( V_25 -> V_19 ) ;
}
static void
F_23 ( struct V_24 * V_25 , int line )
{
struct V_18 * V_19 = V_25 -> V_19 ;
F_13 ( V_20 ,
L_1 , V_21 , line ) ;
if ( V_19 )
F_24 ( V_19 ) ;
F_16 ( & V_25 -> V_26 ) ;
}
static bool F_25 ( struct V_27 * V_28 )
{
return F_26 ( V_28 ) ;
}
static bool F_27 ( struct V_18 * V_19 ,
struct V_27 * V_28 )
{
bool V_4 ;
F_22 ( V_19 ) ;
V_4 = F_25 ( V_28 ) ;
F_24 ( V_19 ) ;
return V_4 ;
}
static void
F_28 ( struct V_29 * V_30 ,
struct V_27 * V_31 )
{
F_29 ( V_31 == NULL ) ;
F_29 ( V_30 -> V_15 . V_32 && ! F_26 ( & V_30 -> V_15 ) ) ;
F_30 ( & V_30 -> V_15 , V_31 ) ;
}
static void
F_31 ( struct V_18 * V_19 ,
struct V_29 * V_30 ,
struct V_27 * V_31 )
{
F_22 ( V_19 ) ;
F_28 ( V_30 , V_31 ) ;
F_24 ( V_19 ) ;
}
static void
F_32 ( struct V_29 * V_30 )
{
F_33 ( & V_30 -> V_15 ) ;
}
static void
F_34 ( struct V_18 * V_19 , struct V_29 * V_30 )
{
F_22 ( V_19 ) ;
F_32 ( V_30 ) ;
F_24 ( V_19 ) ;
}
static struct V_29 * F_35 (
struct V_27 * V_28 )
{
struct V_29 * V_33 ;
V_33 = F_36 ( V_28 , struct V_29 , V_15 ) ;
if ( V_33 )
F_33 ( & V_33 -> V_15 ) ;
return V_33 ;
}
static struct V_29 * F_37 (
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
struct V_29 * V_33 ;
F_22 ( V_19 ) ;
V_33 = F_35 ( V_28 ) ;
F_24 ( V_19 ) ;
return V_33 ;
}
static int F_38 ( struct V_18 * V_19 , int V_34 )
{
struct V_35 * V_36 = V_19 -> V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
if ( V_36 == NULL )
return - V_39 ;
if ( ! F_39 ( V_19 -> V_40 , & V_38 ) )
return - V_41 ;
V_37 = F_40 ( V_19 -> V_40 , V_42 ) ;
F_41 ( V_19 -> V_40 , & V_38 ) ;
return F_42 ( V_36 , 0 , V_37 , V_34 ) ;
}
static void F_43 (
struct V_18 * V_19 , unsigned int V_43 , struct V_44 * V_44 )
{
if ( V_19 -> V_36 )
F_44 ( V_19 -> V_36 , V_43 , V_44 ) ;
}
static long F_45 ( struct V_18 * V_19 , unsigned int V_43 )
{
int V_45 ;
if ( V_19 -> V_36 == NULL )
return - V_39 ;
V_45 = F_46 ( V_19 -> V_36 , V_43 ) ;
if ( F_47 ( V_45 == - V_46 ||
V_45 == - V_47 ||
V_45 == - V_48 ||
V_45 == - V_49 ) )
V_45 = - V_50 ;
return V_45 ;
}
static bool F_48 ( struct V_51 * V_52 ,
bool V_53 )
{
return ! F_25 ( & V_52 -> V_54 ) ||
V_52 -> V_55 ||
( V_53 &&
! F_25 ( & V_52 -> V_19 -> V_54 ) ) ;
}
static bool F_49 ( struct V_51 * V_52 , bool V_53 )
{
bool V_56 ;
F_22 ( V_52 -> V_19 ) ;
V_56 = F_48 ( V_52 , V_53 ) ;
F_24 ( V_52 -> V_19 ) ;
return V_56 ;
}
static bool F_50 ( struct V_51 * V_52 )
{
return ! V_52 -> V_57 &&
F_25 ( & V_52 -> V_54 ) &&
( V_52 -> V_58 & ( V_59 |
V_60 ) ) ;
}
static void F_51 ( struct V_18 * V_19 ,
bool V_61 )
{
struct V_62 * V_63 ;
struct V_51 * V_52 ;
for ( V_63 = F_52 ( & V_19 -> V_64 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
V_52 = F_54 ( V_63 , struct V_51 , V_62 ) ;
if ( V_52 -> V_58 & V_65 &&
F_50 ( V_52 ) ) {
if ( V_61 )
F_55 ( & V_52 -> V_66 ) ;
else
F_56 ( & V_52 -> V_66 ) ;
}
}
}
static struct V_51 *
F_57 ( struct V_18 * V_19 )
{
struct V_51 * V_52 ;
F_58 ( & V_19 -> V_23 ) ;
V_52 = F_36 ( & V_19 -> V_67 ,
struct V_51 ,
V_68 ) ;
if ( V_52 )
F_33 ( & V_52 -> V_68 ) ;
return V_52 ;
}
static void F_59 ( struct V_18 * V_19 ,
struct V_51 * V_52 ,
bool V_61 )
{
F_58 ( & V_19 -> V_23 ) ;
if ( V_52 ) {
if ( V_61 )
F_55 ( & V_52 -> V_66 ) ;
else
F_56 ( & V_52 -> V_66 ) ;
return;
}
F_51 ( V_19 , V_61 ) ;
}
static void F_60 ( struct V_18 * V_19 )
{
struct V_51 * V_52 = F_57 ( V_19 ) ;
F_59 ( V_19 , V_52 , false ) ;
}
static void F_61 ( long V_69 )
{
long V_70 ;
if ( F_62 ( V_71 , V_69 ) ) {
F_63 ( V_71 , V_69 ) ;
return;
}
V_70 = F_64 ( F_65 ( V_72 ) ) ;
F_13 ( V_73 ,
L_2 ,
V_71 -> V_74 , V_69 , V_70 ) ;
F_63 ( V_71 , V_70 ) ;
if ( V_70 <= V_75 )
return;
F_66 ( L_3 , V_71 -> V_74 ) ;
}
static struct V_24 * F_67 ( struct V_18 * V_19 ,
T_1 V_76 )
{
struct V_62 * V_63 = V_19 -> V_77 . V_62 ;
struct V_24 * V_25 ;
F_58 ( & V_19 -> V_23 ) ;
while ( V_63 ) {
V_25 = F_54 ( V_63 , struct V_24 , V_62 ) ;
if ( V_76 < V_25 -> V_76 )
V_63 = V_63 -> V_78 ;
else if ( V_76 > V_25 -> V_76 )
V_63 = V_63 -> V_79 ;
else {
F_68 ( V_25 ) ;
return V_25 ;
}
}
return NULL ;
}
static struct V_24 * F_69 ( struct V_18 * V_19 ,
T_1 V_76 )
{
struct V_24 * V_25 ;
F_22 ( V_19 ) ;
V_25 = F_67 ( V_19 , V_76 ) ;
F_24 ( V_19 ) ;
return V_25 ;
}
static struct V_24 * F_70 (
struct V_18 * V_19 ,
struct V_24 * V_80 ,
struct V_81 * V_82 )
{
struct V_62 * * V_83 = & V_19 -> V_77 . V_62 ;
struct V_62 * V_84 = NULL ;
struct V_24 * V_25 ;
T_1 V_76 = V_82 ? V_82 -> V_85 : 0 ;
T_1 V_86 = V_82 ? V_82 -> V_86 : 0 ;
T_2 V_34 = V_82 ? V_82 -> V_34 : 0 ;
F_58 ( & V_19 -> V_23 ) ;
while ( * V_83 ) {
V_84 = * V_83 ;
V_25 = F_54 ( V_84 , struct V_24 , V_62 ) ;
if ( V_76 < V_25 -> V_76 )
V_83 = & ( * V_83 ) -> V_78 ;
else if ( V_76 > V_25 -> V_76 )
V_83 = & ( * V_83 ) -> V_79 ;
else {
F_68 ( V_25 ) ;
return V_25 ;
}
}
V_25 = V_80 ;
F_6 ( V_87 ) ;
V_25 -> V_88 ++ ;
F_71 ( & V_25 -> V_62 , V_84 , V_83 ) ;
F_72 ( & V_25 -> V_62 , & V_19 -> V_77 ) ;
V_25 -> V_89 = F_8 ( & V_90 ) ;
V_25 -> V_19 = V_19 ;
V_25 -> V_76 = V_76 ;
V_25 -> V_86 = V_86 ;
V_25 -> V_30 . type = V_91 ;
V_25 -> V_92 = V_34 & V_93 ;
V_25 -> V_94 = ! ! ( V_34 & V_95 ) ;
F_73 ( & V_25 -> V_26 ) ;
F_74 ( & V_25 -> V_30 . V_15 ) ;
F_74 ( & V_25 -> V_96 ) ;
F_13 ( V_97 ,
L_4 ,
V_19 -> V_74 , V_71 -> V_74 , V_25 -> V_89 ,
( V_98 ) V_25 -> V_76 , ( V_98 ) V_25 -> V_86 ) ;
return V_25 ;
}
static struct V_24 * F_75 ( struct V_18 * V_19 ,
struct V_81 * V_82 )
{
struct V_24 * V_25 ;
struct V_24 * V_80 = F_76 ( sizeof( * V_25 ) , V_99 ) ;
if ( ! V_80 )
return NULL ;
F_22 ( V_19 ) ;
V_25 = F_70 ( V_19 , V_80 , V_82 ) ;
F_24 ( V_19 ) ;
if ( V_25 != V_80 )
F_77 ( V_80 ) ;
return V_25 ;
}
static void F_78 ( struct V_24 * V_25 )
{
F_77 ( V_25 ) ;
F_4 ( V_87 ) ;
}
static int F_79 ( struct V_24 * V_25 , int V_100 ,
int V_101 ,
struct V_27 * V_31 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
F_58 ( & V_25 -> V_26 ) ;
if ( V_19 )
F_58 ( & V_19 -> V_23 ) ;
if ( V_100 ) {
if ( V_101 ) {
if ( V_31 == NULL &&
V_25 -> V_102 == 0 &&
! ( V_25 -> V_19 &&
V_25 == V_25 -> V_19 -> V_103 -> V_104 &&
V_25 -> V_105 ) ) {
F_80 ( L_5 ,
V_25 -> V_89 ) ;
return - V_106 ;
}
V_25 -> V_102 ++ ;
} else
V_25 -> V_107 ++ ;
if ( ! V_25 -> V_105 && V_31 ) {
F_32 ( & V_25 -> V_30 ) ;
F_28 ( & V_25 -> V_30 , V_31 ) ;
}
} else {
if ( ! V_101 )
V_25 -> V_108 ++ ;
if ( ! V_25 -> V_109 && F_26 ( & V_25 -> V_30 . V_15 ) ) {
if ( V_31 == NULL ) {
F_80 ( L_6 ,
V_25 -> V_89 ) ;
return - V_106 ;
}
F_28 ( & V_25 -> V_30 , V_31 ) ;
}
}
return 0 ;
}
static int F_81 ( struct V_24 * V_25 , int V_100 , int V_101 ,
struct V_27 * V_31 )
{
int V_4 ;
F_82 ( V_25 ) ;
V_4 = F_79 ( V_25 , V_100 , V_101 , V_31 ) ;
F_83 ( V_25 ) ;
return V_4 ;
}
static bool F_84 ( struct V_24 * V_25 ,
int V_100 , int V_101 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
F_58 ( & V_25 -> V_26 ) ;
if ( V_19 )
F_58 ( & V_19 -> V_23 ) ;
if ( V_100 ) {
if ( V_101 )
V_25 -> V_102 -- ;
else
V_25 -> V_107 -- ;
if ( V_25 -> V_107 || V_25 -> V_102 )
return false ;
} else {
if ( ! V_101 )
V_25 -> V_108 -- ;
if ( V_25 -> V_108 || V_25 -> V_88 ||
! F_85 ( & V_25 -> V_110 ) )
return false ;
}
if ( V_19 && ( V_25 -> V_105 || V_25 -> V_109 ) ) {
if ( F_26 ( & V_25 -> V_30 . V_15 ) ) {
F_28 ( & V_25 -> V_30 , & V_19 -> V_54 ) ;
F_60 ( V_19 ) ;
}
} else {
if ( F_85 ( & V_25 -> V_110 ) && ! V_25 -> V_107 &&
! V_25 -> V_108 && ! V_25 -> V_88 ) {
if ( V_19 ) {
F_32 ( & V_25 -> V_30 ) ;
F_86 ( & V_25 -> V_62 , & V_19 -> V_77 ) ;
F_13 ( V_97 ,
L_7 ,
V_25 -> V_89 ) ;
} else {
F_29 ( ! F_26 ( & V_25 -> V_30 . V_15 ) ) ;
F_14 ( & V_111 ) ;
if ( V_25 -> V_88 ) {
F_16 ( & V_111 ) ;
return false ;
}
F_87 ( & V_25 -> V_112 ) ;
F_16 ( & V_111 ) ;
F_13 ( V_97 ,
L_8 ,
V_25 -> V_89 ) ;
}
return true ;
}
}
return false ;
}
static void F_88 ( struct V_24 * V_25 , int V_100 , int V_101 )
{
bool V_113 ;
F_82 ( V_25 ) ;
V_113 = F_84 ( V_25 , V_100 , V_101 ) ;
F_83 ( V_25 ) ;
if ( V_113 )
F_78 ( V_25 ) ;
}
static void F_68 ( struct V_24 * V_25 )
{
V_25 -> V_88 ++ ;
}
static void F_89 ( struct V_24 * V_25 )
{
F_90 ( V_25 ) ;
if ( V_25 -> V_19 )
F_22 ( V_25 -> V_19 ) ;
else
F_14 ( & V_111 ) ;
F_68 ( V_25 ) ;
if ( V_25 -> V_19 )
F_24 ( V_25 -> V_19 ) ;
else
F_16 ( & V_111 ) ;
F_91 ( V_25 ) ;
}
static void F_92 ( struct V_24 * V_25 )
{
bool V_113 ;
F_82 ( V_25 ) ;
if ( ! V_25 -> V_19 )
F_14 ( & V_111 ) ;
V_25 -> V_88 -- ;
F_29 ( V_25 -> V_88 < 0 ) ;
if ( ! V_25 -> V_19 )
F_16 ( & V_111 ) ;
V_113 = F_84 ( V_25 , 0 , 1 ) ;
F_83 ( V_25 ) ;
if ( V_113 )
F_78 ( V_25 ) ;
}
static void F_93 ( struct V_24 * V_25 )
{
F_92 ( V_25 ) ;
}
static struct V_114 * F_94 ( struct V_18 * V_19 ,
T_3 V_115 , bool V_116 )
{
struct V_62 * V_63 = V_19 -> V_117 . V_62 ;
struct V_114 * V_118 ;
while ( V_63 ) {
V_118 = F_54 ( V_63 , struct V_114 , V_119 ) ;
if ( V_115 < V_118 -> V_120 . V_115 ) {
V_63 = V_63 -> V_78 ;
} else if ( V_115 > V_118 -> V_120 . V_115 ) {
V_63 = V_63 -> V_79 ;
} else if ( V_116 && ! V_118 -> V_120 . V_100 ) {
F_66 ( L_9 ) ;
return NULL ;
} else {
return V_118 ;
}
}
return NULL ;
}
static struct V_114 * F_95 (
struct V_18 * V_19 ,
struct V_24 * V_25 ,
struct V_114 * V_121 )
{
struct V_122 * V_103 = V_19 -> V_103 ;
struct V_62 * * V_83 = & V_19 -> V_123 . V_62 ;
struct V_62 * V_84 = NULL ;
struct V_114 * V_118 ;
struct V_62 * V_63 ;
while ( * V_83 ) {
V_84 = * V_83 ;
V_118 = F_54 ( V_84 , struct V_114 , V_124 ) ;
if ( V_25 < V_118 -> V_25 )
V_83 = & ( * V_83 ) -> V_78 ;
else if ( V_25 > V_118 -> V_25 )
V_83 = & ( * V_83 ) -> V_79 ;
else
return V_118 ;
}
if ( ! V_121 )
return NULL ;
F_6 ( V_125 ) ;
V_121 -> V_120 . V_89 = F_8 ( & V_90 ) ;
V_121 -> V_19 = V_19 ;
V_121 -> V_25 = V_25 ;
F_71 ( & V_121 -> V_124 , V_84 , V_83 ) ;
F_72 ( & V_121 -> V_124 , & V_19 -> V_123 ) ;
V_121 -> V_120 . V_115 = ( V_25 == V_103 -> V_104 ) ? 0 : 1 ;
for ( V_63 = F_52 ( & V_19 -> V_117 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
V_118 = F_54 ( V_63 , struct V_114 , V_119 ) ;
if ( V_118 -> V_120 . V_115 > V_121 -> V_120 . V_115 )
break;
V_121 -> V_120 . V_115 = V_118 -> V_120 . V_115 + 1 ;
}
V_83 = & V_19 -> V_117 . V_62 ;
while ( * V_83 ) {
V_84 = * V_83 ;
V_118 = F_54 ( V_84 , struct V_114 , V_119 ) ;
if ( V_121 -> V_120 . V_115 < V_118 -> V_120 . V_115 )
V_83 = & ( * V_83 ) -> V_78 ;
else if ( V_121 -> V_120 . V_115 > V_118 -> V_120 . V_115 )
V_83 = & ( * V_83 ) -> V_79 ;
else
F_96 () ;
}
F_71 ( & V_121 -> V_119 , V_84 , V_83 ) ;
F_72 ( & V_121 -> V_119 , & V_19 -> V_117 ) ;
F_90 ( V_25 ) ;
F_97 ( & V_121 -> V_126 , & V_25 -> V_110 ) ;
F_13 ( V_97 ,
L_10 ,
V_19 -> V_74 , V_121 -> V_120 . V_89 , V_121 -> V_120 . V_115 ,
V_25 -> V_89 ) ;
F_91 ( V_25 ) ;
return V_121 ;
}
static void F_98 ( struct V_114 * V_118 )
{
bool V_127 = false ;
F_13 ( V_97 ,
L_11 ,
V_118 -> V_19 -> V_74 , V_118 -> V_120 . V_89 , V_118 -> V_120 . V_115 ,
V_118 -> V_25 -> V_89 ) ;
F_86 ( & V_118 -> V_119 , & V_118 -> V_19 -> V_117 ) ;
F_86 ( & V_118 -> V_124 , & V_118 -> V_19 -> V_123 ) ;
F_82 ( V_118 -> V_25 ) ;
if ( V_118 -> V_120 . V_100 )
F_84 ( V_118 -> V_25 , 1 , 1 ) ;
F_87 ( & V_118 -> V_126 ) ;
V_127 = F_84 ( V_118 -> V_25 , 0 , 1 ) ;
F_83 ( V_118 -> V_25 ) ;
if ( ! V_127 ) {
V_118 -> V_25 = NULL ;
}
if ( V_118 -> V_128 ) {
F_13 ( V_129 ,
L_12 ,
V_118 -> V_19 -> V_74 , V_118 -> V_120 . V_89 ,
V_118 -> V_120 . V_115 ) ;
F_34 ( V_118 -> V_19 , & V_118 -> V_128 -> V_30 ) ;
F_4 ( V_130 ) ;
}
F_4 ( V_125 ) ;
}
static int F_99 ( struct V_114 * V_118 , int V_100 ,
struct V_27 * V_31 )
{
int V_4 ;
if ( V_100 ) {
if ( V_118 -> V_120 . V_100 == 0 ) {
V_4 = F_81 ( V_118 -> V_25 , 1 , 1 , V_31 ) ;
if ( V_4 )
return V_4 ;
}
V_118 -> V_120 . V_100 ++ ;
} else {
if ( V_118 -> V_120 . V_131 == 0 ) {
V_4 = F_81 ( V_118 -> V_25 , 0 , 1 , V_31 ) ;
if ( V_4 )
return V_4 ;
}
V_118 -> V_120 . V_131 ++ ;
}
return 0 ;
}
static bool F_100 ( struct V_114 * V_118 , int V_100 )
{
if ( V_100 ) {
if ( V_118 -> V_120 . V_100 == 0 ) {
F_66 ( L_13 ,
V_118 -> V_19 -> V_74 , V_118 -> V_120 . V_89 ,
V_118 -> V_120 . V_115 , V_118 -> V_120 . V_100 ,
V_118 -> V_120 . V_131 ) ;
return false ;
}
V_118 -> V_120 . V_100 -- ;
if ( V_118 -> V_120 . V_100 == 0 )
F_88 ( V_118 -> V_25 , V_100 , 1 ) ;
} else {
if ( V_118 -> V_120 . V_131 == 0 ) {
F_66 ( L_14 ,
V_118 -> V_19 -> V_74 , V_118 -> V_120 . V_89 ,
V_118 -> V_120 . V_115 , V_118 -> V_120 . V_100 ,
V_118 -> V_120 . V_131 ) ;
return false ;
}
V_118 -> V_120 . V_131 -- ;
}
if ( V_118 -> V_120 . V_100 == 0 && V_118 -> V_120 . V_131 == 0 ) {
F_98 ( V_118 ) ;
return true ;
}
return false ;
}
static struct V_24 * F_101 (
struct V_18 * V_19 ,
T_3 V_115 , bool V_116 ,
struct V_132 * V_133 )
{
struct V_24 * V_25 ;
struct V_114 * V_118 ;
F_102 ( V_19 ) ;
V_118 = F_94 ( V_19 , V_115 , V_116 ) ;
if ( ! V_118 )
goto V_134;
V_25 = V_118 -> V_25 ;
F_89 ( V_25 ) ;
if ( V_133 )
* V_133 = V_118 -> V_120 ;
F_103 ( V_19 ) ;
return V_25 ;
V_134:
F_103 ( V_19 ) ;
return NULL ;
}
static void F_104 ( struct V_114 * V_118 )
{
if ( V_118 -> V_25 )
F_78 ( V_118 -> V_25 ) ;
F_77 ( V_118 -> V_128 ) ;
F_77 ( V_118 ) ;
}
static int F_105 ( struct V_18 * V_19 ,
T_4 V_115 , bool V_135 , bool V_100 ,
struct V_132 * V_133 )
{
int V_4 = 0 ;
struct V_114 * V_118 ;
bool V_136 = false ;
F_102 ( V_19 ) ;
V_118 = F_94 ( V_19 , V_115 , V_100 ) ;
if ( ! V_118 ) {
V_4 = - V_106 ;
goto V_134;
}
if ( V_135 )
V_4 = F_99 ( V_118 , V_100 , NULL ) ;
else
V_136 = F_100 ( V_118 , V_100 ) ;
if ( V_133 )
* V_133 = V_118 -> V_120 ;
F_103 ( V_19 ) ;
if ( V_136 )
F_104 ( V_118 ) ;
return V_4 ;
V_134:
F_103 ( V_19 ) ;
return V_4 ;
}
static int F_106 ( struct V_18 * V_19 ,
T_4 V_115 , bool V_100 , struct V_132 * V_133 )
{
return F_105 ( V_19 , V_115 , false , V_100 , V_133 ) ;
}
static int F_107 ( struct V_18 * V_19 ,
struct V_24 * V_25 ,
bool V_100 ,
struct V_27 * V_31 ,
struct V_132 * V_133 )
{
struct V_114 * V_118 ;
struct V_114 * V_121 = NULL ;
int V_4 = 0 ;
F_102 ( V_19 ) ;
V_118 = F_95 ( V_19 , V_25 , NULL ) ;
if ( ! V_118 ) {
F_103 ( V_19 ) ;
V_121 = F_76 ( sizeof( * V_118 ) , V_99 ) ;
if ( ! V_121 )
return - V_137 ;
F_102 ( V_19 ) ;
V_118 = F_95 ( V_19 , V_25 , V_121 ) ;
}
V_4 = F_99 ( V_118 , V_100 , V_31 ) ;
* V_133 = V_118 -> V_120 ;
F_103 ( V_19 ) ;
if ( V_121 && V_118 != V_121 )
F_77 ( V_121 ) ;
return V_4 ;
}
static void F_108 ( struct V_51 * V_138 ,
struct V_139 * V_140 )
{
F_29 ( ! V_138 ) ;
F_58 ( & V_138 -> V_19 -> V_23 ) ;
F_29 ( V_138 -> V_57 != V_140 ) ;
F_29 ( V_138 -> V_57 -> V_141 != V_138 ) ;
V_138 -> V_57 =
V_138 -> V_57 -> V_142 ;
V_140 -> V_141 = NULL ;
}
static void F_109 ( struct V_51 * V_52 )
{
F_22 ( V_52 -> V_19 ) ;
F_110 ( & V_52 -> V_143 ) ;
if ( V_52 -> V_144 && ! F_111 ( & V_52 -> V_143 ) ) {
F_24 ( V_52 -> V_19 ) ;
F_112 ( V_52 ) ;
return;
}
F_24 ( V_52 -> V_19 ) ;
}
static void F_113 ( struct V_18 * V_19 )
{
F_22 ( V_19 ) ;
V_19 -> V_143 -- ;
if ( V_19 -> V_144 && F_114 ( & V_19 -> V_64 ) &&
! V_19 -> V_143 ) {
F_24 ( V_19 ) ;
F_115 ( V_19 ) ;
return;
}
F_24 ( V_19 ) ;
}
static struct V_51 * F_116 (
struct V_139 * V_140 )
{
struct V_51 * V_141 ;
F_14 ( & V_140 -> V_26 ) ;
V_141 = V_140 -> V_141 ;
if ( V_141 )
F_5 ( & V_141 -> V_143 ) ;
F_16 ( & V_140 -> V_26 ) ;
return V_141 ;
}
static struct V_51 * F_117 (
struct V_139 * V_140 )
{
struct V_51 * V_141 ;
V_141 = F_116 ( V_140 ) ;
if ( ! V_141 )
return NULL ;
F_22 ( V_141 -> V_19 ) ;
if ( V_140 -> V_141 ) {
F_29 ( V_141 != V_140 -> V_141 ) ;
return V_141 ;
}
F_24 ( V_141 -> V_19 ) ;
F_109 ( V_141 ) ;
return NULL ;
}
static void F_118 ( struct V_139 * V_140 )
{
if ( V_140 -> V_145 )
V_140 -> V_145 -> V_146 = NULL ;
F_77 ( V_140 ) ;
F_4 ( V_147 ) ;
}
static void F_119 ( struct V_139 * V_140 ,
T_4 V_148 )
{
struct V_51 * V_138 ;
struct V_139 * V_32 ;
F_29 ( V_140 -> V_34 & V_149 ) ;
while ( 1 ) {
V_138 = F_117 ( V_140 ) ;
if ( V_138 ) {
F_13 ( V_150 ,
L_15 ,
V_140 -> V_89 ,
V_138 -> V_19 -> V_74 ,
V_138 -> V_74 ) ;
F_108 ( V_138 , V_140 ) ;
if ( V_138 -> V_151 . V_152 == V_153 ) {
V_138 -> V_151 . V_152 = V_148 ;
F_28 (
& V_138 -> V_151 . V_30 ,
& V_138 -> V_54 ) ;
F_56 ( & V_138 -> V_66 ) ;
} else {
F_120 ( 1 , L_16 ,
V_138 -> V_151 . V_152 ) ;
}
F_24 ( V_138 -> V_19 ) ;
F_109 ( V_138 ) ;
F_118 ( V_140 ) ;
return;
}
V_32 = V_140 -> V_142 ;
F_13 ( V_150 ,
L_17 ,
V_140 -> V_89 ) ;
F_118 ( V_140 ) ;
if ( V_32 == NULL ) {
F_13 ( V_129 ,
L_18 ) ;
return;
}
V_140 = V_32 ;
F_13 ( V_129 ,
L_19 ,
V_140 -> V_89 ) ;
}
}
static T_5 F_121 ( struct V_154 * V_145 , V_98 V_155 )
{
struct V_156 * V_157 ;
T_5 V_158 = 0 ;
if ( V_155 > V_145 -> V_159 - sizeof( * V_157 ) ||
V_145 -> V_159 < sizeof( * V_157 ) ||
! F_122 ( V_155 , sizeof( T_3 ) ) )
return 0 ;
V_157 = (struct V_156 * ) ( V_145 -> V_120 + V_155 ) ;
switch ( V_157 -> type ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
V_158 = sizeof( struct V_81 ) ;
break;
case V_164 :
V_158 = sizeof( struct V_165 ) ;
break;
case V_166 :
V_158 = sizeof( struct V_167 ) ;
break;
case V_168 :
V_158 = sizeof( struct V_169 ) ;
break;
default:
return 0 ;
}
if ( V_155 <= V_145 -> V_159 - V_158 &&
V_145 -> V_159 >= V_158 )
return V_158 ;
else
return 0 ;
}
static struct V_167 * F_123 ( struct V_154 * V_170 ,
T_6 V_171 ,
T_6 * V_172 ,
T_6 V_173 )
{
struct V_167 * V_174 ;
T_6 * V_175 ;
if ( V_171 >= V_173 )
return NULL ;
V_175 = V_172 + V_171 ;
V_174 = (struct V_167 * ) ( V_170 -> V_120 + * V_175 ) ;
if ( V_174 -> V_157 . type != V_166 )
return NULL ;
return V_174 ;
}
static bool F_124 ( struct V_154 * V_170 ,
T_6 * V_176 ,
struct V_167 * V_145 ,
T_6 V_177 ,
struct V_167 * V_178 ,
T_6 V_179 )
{
if ( ! V_178 ) {
return false ;
}
while ( V_178 != V_145 ) {
if ( ( V_178 -> V_34 & V_180 ) == 0 )
return false ;
V_179 = V_178 -> V_181 + sizeof( V_182 ) ;
V_178 = (struct V_167 * )
( V_170 -> V_120 + * ( V_176 + V_178 -> V_84 ) ) ;
}
return ( V_177 >= V_179 ) ;
}
static void F_125 ( struct V_18 * V_19 ,
struct V_154 * V_145 ,
T_6 * V_183 )
{
T_6 * V_175 , * V_184 , * V_185 ;
int V_89 = V_145 -> V_89 ;
F_13 ( V_186 ,
L_20 ,
V_19 -> V_74 , V_145 -> V_89 ,
V_145 -> V_159 , V_145 -> V_187 , V_183 ) ;
if ( V_145 -> V_188 )
F_88 ( V_145 -> V_188 , 1 , 0 ) ;
V_184 = ( T_6 * ) ( V_145 -> V_120 +
F_126 ( V_145 -> V_159 , sizeof( void * ) ) ) ;
if ( V_183 )
V_185 = V_183 ;
else
V_185 = ( void * ) V_184 + V_145 -> V_187 ;
for ( V_175 = V_184 ; V_175 < V_185 ; V_175 ++ ) {
struct V_156 * V_157 ;
T_5 V_158 = F_121 ( V_145 , * V_175 ) ;
if ( V_158 == 0 ) {
F_80 ( L_21 ,
V_89 , ( V_98 ) * V_175 , V_145 -> V_159 ) ;
continue;
}
V_157 = (struct V_156 * ) ( V_145 -> V_120 + * V_175 ) ;
switch ( V_157 -> type ) {
case V_160 :
case V_161 : {
struct V_81 * V_82 ;
struct V_24 * V_25 ;
V_82 = F_127 ( V_157 ) ;
V_25 = F_69 ( V_19 , V_82 -> V_85 ) ;
if ( V_25 == NULL ) {
F_80 ( L_22 ,
V_89 , ( V_98 ) V_82 -> V_85 ) ;
break;
}
F_13 ( V_186 ,
L_23 ,
V_25 -> V_89 , ( V_98 ) V_25 -> V_76 ) ;
F_88 ( V_25 , V_157 -> type == V_160 ,
0 ) ;
F_93 ( V_25 ) ;
} break;
case V_162 :
case V_163 : {
struct V_81 * V_82 ;
struct V_132 V_133 ;
int V_4 ;
V_82 = F_127 ( V_157 ) ;
V_4 = F_106 ( V_19 , V_82 -> V_189 ,
V_157 -> type == V_162 , & V_133 ) ;
if ( V_4 ) {
F_80 ( L_24 ,
V_89 , V_82 -> V_189 , V_4 ) ;
break;
}
F_13 ( V_186 ,
L_25 ,
V_133 . V_89 , V_133 . V_115 ) ;
} break;
case V_164 : {
struct V_165 * V_82 = F_128 ( V_157 ) ;
F_13 ( V_186 ,
L_26 , V_82 -> V_43 ) ;
if ( V_183 )
F_45 ( V_19 , V_82 -> V_43 ) ;
} break;
case V_166 :
break;
case V_168 : {
struct V_169 * V_190 ;
struct V_167 * V_84 ;
V_182 V_191 ;
T_3 * V_192 ;
T_5 V_193 ;
T_6 V_194 ;
V_190 = F_129 ( V_157 ) ;
V_84 = F_123 ( V_145 , V_190 -> V_84 ,
V_184 ,
V_175 - V_184 ) ;
if ( ! V_84 ) {
F_80 ( L_27 ,
V_89 ) ;
continue;
}
V_191 = V_84 -> V_145 -
F_130 (
& V_19 -> V_195 ) ;
V_194 = sizeof( T_3 ) * V_190 -> V_196 ;
if ( V_190 -> V_196 >= V_197 / sizeof( T_3 ) ) {
F_80 ( L_28 ,
V_89 , ( V_98 ) V_190 -> V_196 ) ;
continue;
}
if ( V_194 > V_84 -> V_198 ||
V_190 -> V_181 > V_84 -> V_198 - V_194 ) {
F_80 ( L_29 ,
V_89 , ( V_98 ) V_190 -> V_196 ) ;
continue;
}
V_192 = ( T_3 * ) ( V_191 + ( V_182 ) V_190 -> V_181 ) ;
for ( V_193 = 0 ; V_193 < V_190 -> V_196 ; V_193 ++ )
F_45 ( V_19 , V_192 [ V_193 ] ) ;
} break;
default:
F_80 ( L_30 ,
V_89 , V_157 -> type ) ;
break;
}
}
}
static int F_131 ( struct V_81 * V_82 ,
struct V_139 * V_140 ,
struct V_51 * V_52 )
{
struct V_24 * V_25 ;
struct V_18 * V_19 = V_52 -> V_19 ;
struct V_18 * V_199 = V_140 -> V_200 ;
struct V_132 V_133 ;
int V_4 = 0 ;
V_25 = F_69 ( V_19 , V_82 -> V_85 ) ;
if ( ! V_25 ) {
V_25 = F_75 ( V_19 , V_82 ) ;
if ( ! V_25 )
return - V_137 ;
}
if ( V_82 -> V_86 != V_25 -> V_86 ) {
F_66 ( L_31 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_82 -> V_85 ,
V_25 -> V_89 , ( V_98 ) V_82 -> V_86 ,
( V_98 ) V_25 -> V_86 ) ;
V_4 = - V_106 ;
goto V_201;
}
if ( F_132 ( V_19 -> V_40 , V_199 -> V_40 ) ) {
V_4 = - V_202 ;
goto V_201;
}
V_4 = F_107 ( V_199 , V_25 ,
V_82 -> V_157 . type == V_160 ,
& V_52 -> V_54 , & V_133 ) ;
if ( V_4 )
goto V_201;
if ( V_82 -> V_157 . type == V_160 )
V_82 -> V_157 . type = V_162 ;
else
V_82 -> V_157 . type = V_163 ;
V_82 -> V_85 = 0 ;
V_82 -> V_189 = V_133 . V_115 ;
V_82 -> V_86 = 0 ;
F_133 ( V_140 , V_25 , & V_133 ) ;
F_13 ( V_186 ,
L_32 ,
V_25 -> V_89 , ( V_98 ) V_25 -> V_76 ,
V_133 . V_89 , V_133 . V_115 ) ;
V_201:
F_93 ( V_25 ) ;
return V_4 ;
}
static int F_134 ( struct V_81 * V_82 ,
struct V_139 * V_140 ,
struct V_51 * V_52 )
{
struct V_18 * V_19 = V_52 -> V_19 ;
struct V_18 * V_199 = V_140 -> V_200 ;
struct V_24 * V_25 ;
struct V_132 V_203 ;
int V_4 = 0 ;
V_25 = F_101 ( V_19 , V_82 -> V_189 ,
V_82 -> V_157 . type == V_162 , & V_203 ) ;
if ( ! V_25 ) {
F_66 ( L_33 ,
V_19 -> V_74 , V_52 -> V_74 , V_82 -> V_189 ) ;
return - V_106 ;
}
if ( F_132 ( V_19 -> V_40 , V_199 -> V_40 ) ) {
V_4 = - V_202 ;
goto V_201;
}
F_90 ( V_25 ) ;
if ( V_25 -> V_19 == V_199 ) {
if ( V_82 -> V_157 . type == V_162 )
V_82 -> V_157 . type = V_160 ;
else
V_82 -> V_157 . type = V_161 ;
V_82 -> V_85 = V_25 -> V_76 ;
V_82 -> V_86 = V_25 -> V_86 ;
if ( V_25 -> V_19 )
F_22 ( V_25 -> V_19 ) ;
F_79 ( V_25 ,
V_82 -> V_157 . type == V_160 ,
0 , NULL ) ;
if ( V_25 -> V_19 )
F_24 ( V_25 -> V_19 ) ;
F_135 ( V_140 , V_25 , & V_203 ) ;
F_13 ( V_186 ,
L_34 ,
V_203 . V_89 , V_203 . V_115 , V_25 -> V_89 ,
( V_98 ) V_25 -> V_76 ) ;
F_91 ( V_25 ) ;
} else {
struct V_132 V_204 ;
F_91 ( V_25 ) ;
V_4 = F_107 ( V_199 , V_25 ,
V_82 -> V_157 . type == V_162 ,
NULL , & V_204 ) ;
if ( V_4 )
goto V_201;
V_82 -> V_85 = 0 ;
V_82 -> V_189 = V_204 . V_115 ;
V_82 -> V_86 = 0 ;
F_136 ( V_140 , V_25 , & V_203 ,
& V_204 ) ;
F_13 ( V_186 ,
L_35 ,
V_203 . V_89 , V_203 . V_115 ,
V_204 . V_89 , V_204 . V_115 ,
V_25 -> V_89 ) ;
}
V_201:
F_93 ( V_25 ) ;
return V_4 ;
}
static int F_137 ( int V_43 ,
struct V_139 * V_140 ,
struct V_51 * V_52 ,
struct V_139 * V_205 )
{
struct V_18 * V_19 = V_52 -> V_19 ;
struct V_18 * V_199 = V_140 -> V_200 ;
int V_206 ;
struct V_44 * V_44 ;
int V_4 ;
bool V_207 ;
if ( V_205 )
V_207 = ! ! ( V_205 -> V_34 & V_208 ) ;
else
V_207 = V_140 -> V_145 -> V_188 -> V_94 ;
if ( ! V_207 ) {
F_66 ( L_36 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_205 ? L_37 : L_38 ,
V_43 ) ;
V_4 = - V_202 ;
goto V_209;
}
V_44 = F_138 ( V_43 ) ;
if ( ! V_44 ) {
F_66 ( L_39 ,
V_19 -> V_74 , V_52 -> V_74 , V_43 ) ;
V_4 = - V_210 ;
goto V_211;
}
V_4 = F_139 ( V_19 -> V_40 , V_199 -> V_40 , V_44 ) ;
if ( V_4 < 0 ) {
V_4 = - V_202 ;
goto V_212;
}
V_206 = F_38 ( V_199 , V_213 ) ;
if ( V_206 < 0 ) {
V_4 = - V_137 ;
goto V_214;
}
F_43 ( V_199 , V_206 , V_44 ) ;
F_140 ( V_140 , V_43 , V_206 ) ;
F_13 ( V_186 , L_40 ,
V_43 , V_206 ) ;
return V_206 ;
V_214:
V_212:
F_141 ( V_44 ) ;
V_211:
V_209:
return V_4 ;
}
static int F_142 ( struct V_169 * V_190 ,
struct V_167 * V_84 ,
struct V_139 * V_140 ,
struct V_51 * V_52 ,
struct V_139 * V_205 )
{
T_6 V_215 , V_194 , V_216 ;
int V_206 ;
V_182 V_191 ;
T_3 * V_192 ;
struct V_18 * V_19 = V_52 -> V_19 ;
struct V_18 * V_199 = V_140 -> V_200 ;
V_194 = sizeof( T_3 ) * V_190 -> V_196 ;
if ( V_190 -> V_196 >= V_197 / sizeof( T_3 ) ) {
F_66 ( L_41 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_190 -> V_196 ) ;
return - V_106 ;
}
if ( V_194 > V_84 -> V_198 ||
V_190 -> V_181 > V_84 -> V_198 - V_194 ) {
F_66 ( L_42 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_190 -> V_196 ) ;
return - V_106 ;
}
V_191 = V_84 -> V_145 -
F_130 ( & V_199 -> V_195 ) ;
V_192 = ( T_3 * ) ( V_191 + ( V_182 ) V_190 -> V_181 ) ;
if ( ! F_122 ( ( unsigned long ) V_192 , sizeof( T_3 ) ) ) {
F_66 ( L_43 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
return - V_106 ;
}
for ( V_215 = 0 ; V_215 < V_190 -> V_196 ; V_215 ++ ) {
V_206 = F_137 ( V_192 [ V_215 ] , V_140 , V_52 ,
V_205 ) ;
if ( V_206 < 0 )
goto V_217;
V_192 [ V_215 ] = V_206 ;
}
return 0 ;
V_217:
V_216 = V_215 ;
for ( V_215 = 0 ; V_215 < V_216 ; V_215 ++ )
F_45 ( V_199 , V_192 [ V_215 ] ) ;
return V_206 ;
}
static int F_143 ( struct V_139 * V_140 ,
struct V_51 * V_52 ,
struct V_167 * V_218 ,
T_6 * V_184 ,
T_6 V_173 ,
struct V_167 * V_219 ,
T_6 V_220 )
{
struct V_167 * V_84 ;
T_7 * V_191 ;
struct V_154 * V_170 = V_140 -> V_145 ;
struct V_18 * V_19 = V_52 -> V_19 ;
struct V_18 * V_199 = V_140 -> V_200 ;
if ( ! ( V_218 -> V_34 & V_180 ) )
return 0 ;
V_84 = F_123 ( V_170 , V_218 -> V_84 , V_184 , V_173 ) ;
if ( ! V_84 ) {
F_66 ( L_44 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
return - V_106 ;
}
if ( ! F_124 ( V_170 , V_184 ,
V_84 , V_218 -> V_181 ,
V_219 ,
V_220 ) ) {
F_66 ( L_45 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
return - V_106 ;
}
if ( V_84 -> V_198 < sizeof( T_1 ) ||
V_218 -> V_181 > V_84 -> V_198 - sizeof( T_1 ) ) {
F_66 ( L_46 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
return - V_106 ;
}
V_191 = ( T_7 * ) ( ( V_182 ) V_84 -> V_145 -
F_130 (
& V_199 -> V_195 ) ) ;
* ( T_1 * ) ( V_191 + V_218 -> V_181 ) = V_218 -> V_145 ;
return 0 ;
}
static bool F_144 ( struct V_139 * V_140 ,
struct V_18 * V_19 ,
struct V_51 * V_52 )
{
struct V_27 * V_31 = NULL ;
struct V_24 * V_25 = V_140 -> V_145 -> V_188 ;
bool V_221 = ! ! ( V_140 -> V_34 & V_149 ) ;
bool V_222 = true ;
F_29 ( ! V_25 ) ;
F_90 ( V_25 ) ;
if ( V_221 ) {
F_29 ( V_52 ) ;
if ( V_25 -> V_223 ) {
V_31 = & V_25 -> V_96 ;
V_222 = false ;
} else {
V_25 -> V_223 = 1 ;
}
}
F_22 ( V_19 ) ;
if ( V_19 -> V_144 || ( V_52 && V_52 -> V_144 ) ) {
F_24 ( V_19 ) ;
F_91 ( V_25 ) ;
return false ;
}
if ( ! V_52 && ! V_31 )
V_52 = F_57 ( V_19 ) ;
if ( V_52 )
V_31 = & V_52 -> V_54 ;
else if ( ! V_31 )
V_31 = & V_19 -> V_54 ;
else
F_29 ( V_31 != & V_25 -> V_96 ) ;
F_28 ( & V_140 -> V_30 , V_31 ) ;
if ( V_222 )
F_59 ( V_19 , V_52 , ! V_221 ) ;
F_24 ( V_19 ) ;
F_91 ( V_25 ) ;
return true ;
}
static struct V_24 * F_145 (
struct V_24 * V_25 ,
struct V_18 * * V_224 ,
T_4 * error )
{
struct V_24 * V_188 = NULL ;
F_82 ( V_25 ) ;
if ( V_25 -> V_19 ) {
V_188 = V_25 ;
F_79 ( V_25 , 1 , 0 , NULL ) ;
F_68 ( V_25 ) ;
V_25 -> V_19 -> V_143 ++ ;
* V_224 = V_25 -> V_19 ;
} else
* error = V_225 ;
F_83 ( V_25 ) ;
return V_188 ;
}
static void V_139 ( struct V_18 * V_19 ,
struct V_51 * V_52 ,
struct V_226 * V_227 , int V_228 ,
T_6 V_229 )
{
int V_4 ;
struct V_139 * V_140 ;
struct V_29 * V_230 ;
T_6 * V_175 , * V_185 , * V_184 ;
T_6 V_231 ;
T_7 * V_232 , * V_233 ;
struct V_18 * V_199 = NULL ;
struct V_51 * V_138 = NULL ;
struct V_24 * V_188 = NULL ;
struct V_139 * V_205 = NULL ;
struct V_11 * V_13 ;
T_4 V_234 = 0 ;
T_4 V_235 = 0 ;
T_4 V_236 = 0 ;
struct V_167 * V_219 = NULL ;
T_6 V_220 = 0 ;
struct V_122 * V_103 = V_19 -> V_103 ;
int V_237 = F_8 ( & V_90 ) ;
V_13 = F_7 ( & V_12 ) ;
V_13 -> V_89 = V_237 ;
V_13 -> V_238 = V_228 ? 2 : ! ! ( V_227 -> V_34 & V_149 ) ;
V_13 -> V_239 = V_19 -> V_74 ;
V_13 -> V_240 = V_52 -> V_74 ;
V_13 -> V_241 = V_227 -> V_242 . V_189 ;
V_13 -> V_159 = V_227 -> V_159 ;
V_13 -> V_187 = V_227 -> V_187 ;
V_13 -> V_243 = V_19 -> V_103 -> V_244 ;
if ( V_228 ) {
F_22 ( V_19 ) ;
V_205 = V_52 -> V_57 ;
if ( V_205 == NULL ) {
F_24 ( V_19 ) ;
F_66 ( L_47 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_246 ;
V_236 = __LINE__ ;
goto V_247;
}
if ( V_205 -> V_248 != V_52 ) {
F_14 ( & V_205 -> V_26 ) ;
F_66 ( L_48 ,
V_19 -> V_74 , V_52 -> V_74 , V_205 -> V_89 ,
V_205 -> V_200 ?
V_205 -> V_200 -> V_74 : 0 ,
V_205 -> V_248 ?
V_205 -> V_248 -> V_74 : 0 ) ;
F_16 ( & V_205 -> V_26 ) ;
F_24 ( V_19 ) ;
V_234 = V_245 ;
V_235 = - V_246 ;
V_236 = __LINE__ ;
V_205 = NULL ;
goto V_249;
}
V_52 -> V_57 = V_205 -> V_250 ;
F_24 ( V_19 ) ;
F_61 ( V_205 -> V_251 ) ;
V_138 = F_117 ( V_205 ) ;
if ( V_138 == NULL ) {
V_234 = V_225 ;
V_236 = __LINE__ ;
goto V_252;
}
if ( V_138 -> V_57 != V_205 ) {
F_66 ( L_49 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_138 -> V_57 ?
V_138 -> V_57 -> V_89 : 0 ,
V_205 -> V_89 ) ;
F_24 ( V_138 -> V_19 ) ;
V_234 = V_245 ;
V_235 = - V_246 ;
V_236 = __LINE__ ;
V_205 = NULL ;
V_138 = NULL ;
goto V_252;
}
V_199 = V_138 -> V_19 ;
V_199 -> V_143 ++ ;
F_24 ( V_138 -> V_19 ) ;
} else {
if ( V_227 -> V_242 . V_189 ) {
struct V_114 * V_118 ;
F_102 ( V_19 ) ;
V_118 = F_94 ( V_19 , V_227 -> V_242 . V_189 ,
true ) ;
if ( V_118 ) {
V_188 = F_145 (
V_118 -> V_25 , & V_199 ,
& V_234 ) ;
} else {
F_66 ( L_50 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
}
F_103 ( V_19 ) ;
} else {
F_146 ( & V_103 -> V_253 ) ;
V_188 = V_103 -> V_104 ;
if ( V_188 )
V_188 = F_145 (
V_188 , & V_199 ,
& V_234 ) ;
else
V_234 = V_225 ;
F_147 ( & V_103 -> V_253 ) ;
}
if ( ! V_188 ) {
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_252;
}
V_13 -> V_254 = V_188 -> V_89 ;
if ( F_148 ( V_19 -> V_40 ,
V_199 -> V_40 ) < 0 ) {
V_234 = V_245 ;
V_235 = - V_202 ;
V_236 = __LINE__ ;
goto V_255;
}
F_22 ( V_19 ) ;
if ( ! ( V_227 -> V_34 & V_149 ) && V_52 -> V_57 ) {
struct V_139 * V_256 ;
V_256 = V_52 -> V_57 ;
if ( V_256 -> V_248 != V_52 ) {
F_14 ( & V_256 -> V_26 ) ;
F_66 ( L_51 ,
V_19 -> V_74 , V_52 -> V_74 , V_256 -> V_89 ,
V_256 -> V_200 ? V_256 -> V_200 -> V_74 : 0 ,
V_256 -> V_248 ?
V_256 -> V_248 -> V_74 : 0 ) ;
F_16 ( & V_256 -> V_26 ) ;
F_24 ( V_19 ) ;
V_234 = V_245 ;
V_235 = - V_246 ;
V_236 = __LINE__ ;
goto V_249;
}
while ( V_256 ) {
struct V_51 * V_141 ;
F_14 ( & V_256 -> V_26 ) ;
V_141 = V_256 -> V_141 ;
if ( V_141 && V_141 -> V_19 == V_199 ) {
F_5 ( & V_141 -> V_143 ) ;
V_138 = V_141 ;
F_16 ( & V_256 -> V_26 ) ;
break;
}
F_16 ( & V_256 -> V_26 ) ;
V_256 = V_256 -> V_142 ;
}
}
F_24 ( V_19 ) ;
}
if ( V_138 )
V_13 -> V_248 = V_138 -> V_74 ;
V_13 -> V_200 = V_199 -> V_74 ;
V_140 = F_76 ( sizeof( * V_140 ) , V_99 ) ;
if ( V_140 == NULL ) {
V_234 = V_245 ;
V_235 = - V_137 ;
V_236 = __LINE__ ;
goto V_257;
}
F_6 ( V_147 ) ;
F_73 ( & V_140 -> V_26 ) ;
V_230 = F_76 ( sizeof( * V_230 ) , V_99 ) ;
if ( V_230 == NULL ) {
V_234 = V_245 ;
V_235 = - V_137 ;
V_236 = __LINE__ ;
goto V_258;
}
F_6 ( V_259 ) ;
V_140 -> V_89 = V_237 ;
if ( V_228 )
F_13 ( V_186 ,
L_52 ,
V_19 -> V_74 , V_52 -> V_74 , V_140 -> V_89 ,
V_199 -> V_74 , V_138 -> V_74 ,
( V_98 ) V_227 -> V_120 . V_76 . V_145 ,
( V_98 ) V_227 -> V_120 . V_76 . V_260 ,
( V_98 ) V_227 -> V_159 , ( V_98 ) V_227 -> V_187 ,
( V_98 ) V_229 ) ;
else
F_13 ( V_186 ,
L_53 ,
V_19 -> V_74 , V_52 -> V_74 , V_140 -> V_89 ,
V_199 -> V_74 , V_188 -> V_89 ,
( V_98 ) V_227 -> V_120 . V_76 . V_145 ,
( V_98 ) V_227 -> V_120 . V_76 . V_260 ,
( V_98 ) V_227 -> V_159 , ( V_98 ) V_227 -> V_187 ,
( V_98 ) V_229 ) ;
if ( ! V_228 && ! ( V_227 -> V_34 & V_149 ) )
V_140 -> V_141 = V_52 ;
else
V_140 -> V_141 = NULL ;
V_140 -> V_261 = F_149 ( V_19 -> V_40 ) ;
V_140 -> V_200 = V_199 ;
V_140 -> V_248 = V_138 ;
V_140 -> V_262 = V_227 -> V_262 ;
V_140 -> V_34 = V_227 -> V_34 ;
V_140 -> V_263 = F_150 ( V_71 ) ;
F_151 ( V_228 , V_140 , V_188 ) ;
V_140 -> V_145 = F_152 ( & V_199 -> V_195 , V_227 -> V_159 ,
V_227 -> V_187 , V_229 ,
! V_228 && ( V_140 -> V_34 & V_149 ) ) ;
if ( F_153 ( V_140 -> V_145 ) ) {
V_235 = F_154 ( V_140 -> V_145 ) ;
V_234 = V_235 == - V_39 ?
V_225 : V_245 ;
V_236 = __LINE__ ;
V_140 -> V_145 = NULL ;
goto V_264;
}
V_140 -> V_145 -> V_265 = 0 ;
V_140 -> V_145 -> V_89 = V_140 -> V_89 ;
V_140 -> V_145 -> V_146 = V_140 ;
V_140 -> V_145 -> V_188 = V_188 ;
F_155 ( V_140 -> V_145 ) ;
V_184 = ( T_6 * ) ( V_140 -> V_145 -> V_120 +
F_126 ( V_227 -> V_159 , sizeof( void * ) ) ) ;
V_175 = V_184 ;
if ( F_156 ( V_140 -> V_145 -> V_120 , ( const void V_266 * ) ( V_182 )
V_227 -> V_120 . V_76 . V_145 , V_227 -> V_159 ) ) {
F_66 ( L_54 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_267 ;
V_236 = __LINE__ ;
goto V_268;
}
if ( F_156 ( V_175 , ( const void V_266 * ) ( V_182 )
V_227 -> V_120 . V_76 . V_260 , V_227 -> V_187 ) ) {
F_66 ( L_55 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_267 ;
V_236 = __LINE__ ;
goto V_268;
}
if ( ! F_122 ( V_227 -> V_187 , sizeof( T_6 ) ) ) {
F_66 ( L_56 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_227 -> V_187 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_269;
}
if ( ! F_122 ( V_229 , sizeof( V_98 ) ) ) {
F_66 ( L_57 ,
V_19 -> V_74 , V_52 -> V_74 ,
( V_98 ) V_229 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_269;
}
V_185 = ( void * ) V_184 + V_227 -> V_187 ;
V_232 = ( T_7 * ) ( F_157 ( V_185 , sizeof( void * ) ) ) ;
V_233 = V_232 + V_229 ;
V_231 = 0 ;
for (; V_175 < V_185 ; V_175 ++ ) {
struct V_156 * V_157 ;
T_5 V_158 = F_121 ( V_140 -> V_145 , * V_175 ) ;
if ( V_158 == 0 || * V_175 < V_231 ) {
F_66 ( L_58 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) * V_175 ,
( V_98 ) V_231 ,
( V_98 ) V_140 -> V_145 -> V_159 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_269;
}
V_157 = (struct V_156 * ) ( V_140 -> V_145 -> V_120 + * V_175 ) ;
V_231 = * V_175 + V_158 ;
switch ( V_157 -> type ) {
case V_160 :
case V_161 : {
struct V_81 * V_82 ;
V_82 = F_127 ( V_157 ) ;
V_4 = F_131 ( V_82 , V_140 , V_52 ) ;
if ( V_4 < 0 ) {
V_234 = V_245 ;
V_235 = V_4 ;
V_236 = __LINE__ ;
goto V_270;
}
} break;
case V_162 :
case V_163 : {
struct V_81 * V_82 ;
V_82 = F_127 ( V_157 ) ;
V_4 = F_134 ( V_82 , V_140 , V_52 ) ;
if ( V_4 < 0 ) {
V_234 = V_245 ;
V_235 = V_4 ;
V_236 = __LINE__ ;
goto V_270;
}
} break;
case V_164 : {
struct V_165 * V_82 = F_128 ( V_157 ) ;
int V_206 = F_137 ( V_82 -> V_43 , V_140 , V_52 ,
V_205 ) ;
if ( V_206 < 0 ) {
V_234 = V_245 ;
V_235 = V_206 ;
V_236 = __LINE__ ;
goto V_270;
}
V_82 -> V_271 = 0 ;
V_82 -> V_43 = V_206 ;
} break;
case V_168 : {
struct V_169 * V_190 =
F_129 ( V_157 ) ;
struct V_167 * V_84 =
F_123 ( V_140 -> V_145 , V_190 -> V_84 ,
V_184 ,
V_175 - V_184 ) ;
if ( ! V_84 ) {
F_66 ( L_44 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_272;
}
if ( ! F_124 ( V_140 -> V_145 , V_184 ,
V_84 , V_190 -> V_181 ,
V_219 ,
V_220 ) ) {
F_66 ( L_45 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_272;
}
V_4 = F_142 ( V_190 , V_84 , V_140 , V_52 ,
V_205 ) ;
if ( V_4 < 0 ) {
V_234 = V_245 ;
V_235 = V_4 ;
V_236 = __LINE__ ;
goto V_270;
}
V_219 = V_84 ;
V_220 =
V_190 -> V_181 + sizeof( T_3 ) * V_190 -> V_196 ;
} break;
case V_166 : {
struct V_167 * V_218 =
F_158 ( V_157 ) ;
T_5 V_273 = V_233 - V_232 ;
if ( V_218 -> V_198 > V_273 ) {
F_66 ( L_59 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_269;
}
if ( F_156 ( V_232 ,
( const void V_266 * ) ( V_182 )
V_218 -> V_145 , V_218 -> V_198 ) ) {
F_66 ( L_55 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_235 = - V_267 ;
V_234 = V_245 ;
V_236 = __LINE__ ;
goto V_268;
}
V_218 -> V_145 = ( V_182 ) V_232 +
F_130 (
& V_199 -> V_195 ) ;
V_232 += F_126 ( V_218 -> V_198 , sizeof( V_98 ) ) ;
V_4 = F_143 ( V_140 , V_52 , V_218 , V_184 ,
V_175 - V_184 ,
V_219 ,
V_220 ) ;
if ( V_4 < 0 ) {
V_234 = V_245 ;
V_235 = V_4 ;
V_236 = __LINE__ ;
goto V_270;
}
V_219 = V_218 ;
V_220 = 0 ;
} break;
default:
F_66 ( L_60 ,
V_19 -> V_74 , V_52 -> V_74 , V_157 -> type ) ;
V_234 = V_245 ;
V_235 = - V_106 ;
V_236 = __LINE__ ;
goto V_274;
}
}
V_230 -> type = V_275 ;
F_31 ( V_19 , V_230 , & V_52 -> V_54 ) ;
V_140 -> V_30 . type = V_276 ;
if ( V_228 ) {
F_22 ( V_199 ) ;
if ( V_138 -> V_144 ) {
F_24 ( V_199 ) ;
goto V_277;
}
F_29 ( V_140 -> V_145 -> V_278 != 0 ) ;
F_108 ( V_138 , V_205 ) ;
F_28 ( & V_140 -> V_30 , & V_138 -> V_54 ) ;
F_24 ( V_199 ) ;
F_55 ( & V_138 -> V_66 ) ;
F_118 ( V_205 ) ;
} else if ( ! ( V_140 -> V_34 & V_149 ) ) {
F_29 ( V_140 -> V_145 -> V_278 != 0 ) ;
F_22 ( V_19 ) ;
V_140 -> V_279 = 1 ;
V_140 -> V_142 = V_52 -> V_57 ;
V_52 -> V_57 = V_140 ;
F_24 ( V_19 ) ;
if ( ! F_144 ( V_140 , V_199 , V_138 ) ) {
F_22 ( V_19 ) ;
F_108 ( V_52 , V_140 ) ;
F_24 ( V_19 ) ;
goto V_277;
}
} else {
F_29 ( V_188 == NULL ) ;
F_29 ( V_140 -> V_145 -> V_278 != 1 ) ;
if ( ! F_144 ( V_140 , V_199 , NULL ) )
goto V_277;
}
if ( V_138 )
F_109 ( V_138 ) ;
F_113 ( V_199 ) ;
if ( V_188 )
F_92 ( V_188 ) ;
F_11 () ;
F_10 ( V_13 -> V_17 , V_237 ) ;
return;
V_277:
V_234 = V_225 ;
V_236 = __LINE__ ;
F_34 ( V_19 , V_230 ) ;
V_270:
V_274:
V_269:
V_272:
V_268:
F_159 ( V_140 -> V_145 ) ;
F_125 ( V_199 , V_140 -> V_145 , V_175 ) ;
if ( V_188 )
F_92 ( V_188 ) ;
V_188 = NULL ;
V_140 -> V_145 -> V_146 = NULL ;
F_160 ( & V_199 -> V_195 , V_140 -> V_145 ) ;
V_264:
F_77 ( V_230 ) ;
F_4 ( V_259 ) ;
V_258:
F_77 ( V_140 ) ;
F_4 ( V_147 ) ;
V_257:
V_249:
V_247:
V_252:
V_255:
if ( V_138 )
F_109 ( V_138 ) ;
if ( V_199 )
F_113 ( V_199 ) ;
if ( V_188 ) {
F_88 ( V_188 , 1 , 0 ) ;
F_92 ( V_188 ) ;
}
F_13 ( V_150 ,
L_61 ,
V_19 -> V_74 , V_52 -> V_74 , V_234 , V_235 ,
( V_98 ) V_227 -> V_159 , ( V_98 ) V_227 -> V_187 ,
V_236 ) ;
{
struct V_11 * V_280 ;
V_13 -> V_234 = V_234 ;
V_13 -> V_235 = V_235 ;
V_13 -> V_236 = V_236 ;
V_280 = F_7 ( & V_281 ) ;
* V_280 = * V_13 ;
F_11 () ;
F_10 ( V_13 -> V_17 , V_237 ) ;
F_10 ( V_280 -> V_17 , V_237 ) ;
}
F_29 ( V_52 -> V_234 . V_152 != V_153 ) ;
if ( V_205 ) {
V_52 -> V_234 . V_152 = V_282 ;
F_31 ( V_52 -> V_19 ,
& V_52 -> V_234 . V_30 ,
& V_52 -> V_54 ) ;
F_119 ( V_205 , V_234 ) ;
} else {
V_52 -> V_234 . V_152 = V_234 ;
F_31 ( V_52 -> V_19 ,
& V_52 -> V_234 . V_30 ,
& V_52 -> V_54 ) ;
}
}
static int F_161 ( struct V_18 * V_19 ,
struct V_51 * V_52 ,
T_1 V_154 , T_5 V_283 ,
T_6 * V_284 )
{
T_4 V_152 ;
struct V_122 * V_103 = V_19 -> V_103 ;
void V_266 * V_145 = ( void V_266 * ) ( V_182 ) V_154 ;
void V_266 * V_76 = V_145 + * V_284 ;
void V_266 * V_285 = V_145 + V_283 ;
while ( V_76 < V_285 && V_52 -> V_234 . V_152 == V_153 ) {
int V_4 ;
if ( F_162 ( V_152 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
F_163 ( V_152 ) ;
if ( F_164 ( V_152 ) < F_9 ( V_8 . V_286 ) ) {
F_5 ( & V_8 . V_286 [ F_164 ( V_152 ) ] ) ;
F_5 ( & V_19 -> V_287 . V_286 [ F_164 ( V_152 ) ] ) ;
F_5 ( & V_52 -> V_287 . V_286 [ F_164 ( V_152 ) ] ) ;
}
switch ( V_152 ) {
case V_288 :
case V_289 :
case V_290 :
case V_291 : {
T_4 V_242 ;
const char * V_292 ;
bool V_100 = V_152 == V_289 || V_152 == V_290 ;
bool V_135 = V_152 == V_288 || V_152 == V_289 ;
struct V_132 V_133 ;
if ( F_162 ( V_242 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
V_4 = - 1 ;
if ( V_135 && ! V_242 ) {
struct V_24 * V_293 ;
F_146 ( & V_103 -> V_253 ) ;
V_293 = V_103 -> V_104 ;
if ( V_293 )
V_4 = F_107 (
V_19 , V_293 ,
V_100 , NULL , & V_133 ) ;
F_147 ( & V_103 -> V_253 ) ;
}
if ( V_4 )
V_4 = F_105 (
V_19 , V_242 , V_135 , V_100 ,
& V_133 ) ;
if ( ! V_4 && V_133 . V_115 != V_242 ) {
F_66 ( L_62 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_242 , V_133 . V_115 ) ;
}
switch ( V_152 ) {
case V_288 :
V_292 = L_63 ;
break;
case V_289 :
V_292 = L_64 ;
break;
case V_290 :
V_292 = L_65 ;
break;
case V_291 :
default:
V_292 = L_66 ;
break;
}
if ( V_4 ) {
F_66 ( L_67 ,
V_19 -> V_74 , V_52 -> V_74 , V_292 ,
V_100 , V_242 , V_4 ) ;
break;
}
F_13 ( V_294 ,
L_68 ,
V_19 -> V_74 , V_52 -> V_74 , V_292 ,
V_133 . V_89 , V_133 . V_115 , V_133 . V_100 ,
V_133 . V_131 ) ;
break;
}
case V_295 :
case V_296 : {
T_1 V_297 ;
T_1 V_86 ;
struct V_24 * V_25 ;
bool V_113 ;
if ( F_162 ( V_297 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
if ( F_162 ( V_86 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
V_25 = F_69 ( V_19 , V_297 ) ;
if ( V_25 == NULL ) {
F_66 ( L_69 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_295 ?
L_70 :
L_71 ,
( V_98 ) V_297 ) ;
break;
}
if ( V_86 != V_25 -> V_86 ) {
F_66 ( L_72 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_295 ?
L_70 : L_71 ,
( V_98 ) V_297 , V_25 -> V_89 ,
( V_98 ) V_86 , ( V_98 ) V_25 -> V_86 ) ;
F_93 ( V_25 ) ;
break;
}
F_82 ( V_25 ) ;
if ( V_152 == V_296 ) {
if ( V_25 -> V_298 == 0 ) {
F_66 ( L_73 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_25 -> V_89 ) ;
F_83 ( V_25 ) ;
F_93 ( V_25 ) ;
break;
}
V_25 -> V_298 = 0 ;
} else {
if ( V_25 -> V_299 == 0 ) {
F_66 ( L_74 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_25 -> V_89 ) ;
F_83 ( V_25 ) ;
F_93 ( V_25 ) ;
break;
}
V_25 -> V_299 = 0 ;
}
V_113 = F_84 ( V_25 ,
V_152 == V_296 , 0 ) ;
F_165 ( V_113 ) ;
F_13 ( V_294 ,
L_75 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_295 ? L_70 : L_71 ,
V_25 -> V_89 , V_25 -> V_107 ,
V_25 -> V_108 , V_25 -> V_88 ) ;
F_83 ( V_25 ) ;
F_93 ( V_25 ) ;
break;
}
case V_300 :
F_80 ( L_76 ) ;
return - V_106 ;
case V_301 :
F_80 ( L_77 ) ;
return - V_106 ;
case V_302 : {
T_1 V_303 ;
struct V_154 * V_145 ;
if ( F_162 ( V_303 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
V_145 = F_166 ( & V_19 -> V_195 ,
V_303 ) ;
if ( V_145 == NULL ) {
F_66 ( L_78 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_303 ) ;
break;
}
if ( ! V_145 -> V_265 ) {
F_66 ( L_79 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_303 ) ;
break;
}
F_13 ( V_304 ,
L_80 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_303 ,
V_145 -> V_89 ,
V_145 -> V_146 ? L_81 : L_82 ) ;
if ( V_145 -> V_146 ) {
V_145 -> V_146 -> V_145 = NULL ;
V_145 -> V_146 = NULL ;
}
if ( V_145 -> V_278 && V_145 -> V_188 ) {
struct V_24 * V_305 ;
struct V_29 * V_33 ;
V_305 = V_145 -> V_188 ;
F_82 ( V_305 ) ;
F_29 ( ! V_305 -> V_223 ) ;
F_29 ( V_305 -> V_19 != V_19 ) ;
V_33 = F_35 (
& V_305 -> V_96 ) ;
if ( ! V_33 ) {
V_305 -> V_223 = 0 ;
} else {
F_28 (
V_33 , & V_19 -> V_54 ) ;
F_60 ( V_19 ) ;
}
F_83 ( V_305 ) ;
}
F_167 ( V_145 ) ;
F_125 ( V_19 , V_145 , NULL ) ;
F_160 ( & V_19 -> V_195 , V_145 ) ;
break;
}
case V_306 :
case V_307 : {
struct V_308 V_227 ;
if ( F_156 ( & V_227 , V_76 , sizeof( V_227 ) ) )
return - V_267 ;
V_76 += sizeof( V_227 ) ;
V_139 ( V_19 , V_52 , & V_227 . V_309 ,
V_152 == V_307 , V_227 . V_310 ) ;
break;
}
case V_311 :
case V_312 : {
struct V_226 V_227 ;
if ( F_156 ( & V_227 , V_76 , sizeof( V_227 ) ) )
return - V_267 ;
V_76 += sizeof( V_227 ) ;
V_139 ( V_19 , V_52 , & V_227 ,
V_152 == V_312 , 0 ) ;
break;
}
case V_313 :
F_13 ( V_314 ,
L_83 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
F_22 ( V_19 ) ;
if ( V_52 -> V_58 & V_59 ) {
V_52 -> V_58 |= V_315 ;
F_66 ( L_84 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
} else if ( V_19 -> V_316 == 0 ) {
V_52 -> V_58 |= V_315 ;
F_66 ( L_85 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
} else {
V_19 -> V_316 -- ;
V_19 -> V_317 ++ ;
}
V_52 -> V_58 |= V_60 ;
F_24 ( V_19 ) ;
break;
case V_318 :
F_13 ( V_314 ,
L_86 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
if ( V_52 -> V_58 & V_60 ) {
V_52 -> V_58 |= V_315 ;
F_66 ( L_87 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
}
V_52 -> V_58 |= V_59 ;
break;
case V_319 :
F_13 ( V_314 ,
L_88 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
V_52 -> V_58 |= V_320 ;
break;
case V_321 :
case V_322 : {
T_4 V_242 ;
T_1 V_86 ;
struct V_114 * V_118 ;
struct V_323 * V_128 = NULL ;
if ( F_162 ( V_242 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
if ( F_162 ( V_86 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
if ( V_152 == V_321 ) {
V_128 = F_76 ( sizeof( * V_128 ) , V_99 ) ;
if ( V_128 == NULL ) {
F_165 ( V_52 -> V_234 . V_152 !=
V_153 ) ;
V_52 -> V_234 . V_152 = V_324 ;
F_31 (
V_52 -> V_19 ,
& V_52 -> V_234 . V_30 ,
& V_52 -> V_54 ) ;
F_13 (
V_150 ,
L_89 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
break;
}
}
F_102 ( V_19 ) ;
V_118 = F_94 ( V_19 , V_242 , false ) ;
if ( V_118 == NULL ) {
F_66 ( L_90 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_321 ?
L_91 :
L_92 ,
V_242 ) ;
F_103 ( V_19 ) ;
F_77 ( V_128 ) ;
break;
}
F_13 ( V_325 ,
L_93 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_321 ?
L_91 :
L_92 ,
( V_98 ) V_86 , V_118 -> V_120 . V_89 ,
V_118 -> V_120 . V_115 , V_118 -> V_120 . V_100 ,
V_118 -> V_120 . V_131 , V_118 -> V_25 -> V_89 ) ;
F_90 ( V_118 -> V_25 ) ;
if ( V_152 == V_321 ) {
if ( V_118 -> V_128 ) {
F_66 ( L_94 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
F_91 ( V_118 -> V_25 ) ;
F_103 ( V_19 ) ;
F_77 ( V_128 ) ;
break;
}
F_6 ( V_130 ) ;
F_74 ( & V_128 -> V_30 . V_15 ) ;
V_128 -> V_86 = V_86 ;
V_118 -> V_128 = V_128 ;
if ( V_118 -> V_25 -> V_19 == NULL ) {
V_118 -> V_128 -> V_30 . type = V_326 ;
F_22 ( V_19 ) ;
F_28 (
& V_118 -> V_128 -> V_30 , & V_19 -> V_54 ) ;
F_60 ( V_19 ) ;
F_24 ( V_19 ) ;
}
} else {
if ( V_118 -> V_128 == NULL ) {
F_66 ( L_95 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
F_91 ( V_118 -> V_25 ) ;
F_103 ( V_19 ) ;
break;
}
V_128 = V_118 -> V_128 ;
if ( V_128 -> V_86 != V_86 ) {
F_66 ( L_96 ,
V_19 -> V_74 , V_52 -> V_74 ,
( V_98 ) V_128 -> V_86 ,
( V_98 ) V_86 ) ;
F_91 ( V_118 -> V_25 ) ;
F_103 ( V_19 ) ;
break;
}
V_118 -> V_128 = NULL ;
F_22 ( V_19 ) ;
if ( F_26 ( & V_128 -> V_30 . V_15 ) ) {
V_128 -> V_30 . type = V_327 ;
if ( V_52 -> V_58 &
( V_60 |
V_59 ) )
F_28 (
& V_128 -> V_30 ,
& V_52 -> V_54 ) ;
else {
F_28 (
& V_128 -> V_30 ,
& V_19 -> V_54 ) ;
F_60 (
V_19 ) ;
}
} else {
F_29 ( V_128 -> V_30 . type != V_326 ) ;
V_128 -> V_30 . type = V_328 ;
}
F_24 ( V_19 ) ;
}
F_91 ( V_118 -> V_25 ) ;
F_103 ( V_19 ) ;
} break;
case V_329 : {
struct V_29 * V_33 ;
T_1 V_86 ;
struct V_323 * V_128 = NULL ;
if ( F_162 ( V_86 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( V_86 ) ;
F_22 ( V_19 ) ;
F_168 (w, &proc->delivered_death,
entry) {
struct V_323 * V_330 =
F_169 ( V_33 ,
struct V_323 ,
V_30 ) ;
if ( V_330 -> V_86 == V_86 ) {
V_128 = V_330 ;
break;
}
}
F_13 ( V_129 ,
L_97 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_86 ,
V_128 ) ;
if ( V_128 == NULL ) {
F_66 ( L_98 ,
V_19 -> V_74 , V_52 -> V_74 , ( V_98 ) V_86 ) ;
F_24 ( V_19 ) ;
break;
}
F_32 ( & V_128 -> V_30 ) ;
if ( V_128 -> V_30 . type == V_328 ) {
V_128 -> V_30 . type = V_327 ;
if ( V_52 -> V_58 &
( V_60 |
V_59 ) )
F_28 (
& V_128 -> V_30 , & V_52 -> V_54 ) ;
else {
F_28 (
& V_128 -> V_30 ,
& V_19 -> V_54 ) ;
F_60 ( V_19 ) ;
}
}
F_24 ( V_19 ) ;
} break;
default:
F_80 ( L_99 ,
V_19 -> V_74 , V_52 -> V_74 , V_152 ) ;
return - V_106 ;
}
* V_284 = V_76 - V_145 ;
}
return 0 ;
}
static void F_170 ( struct V_18 * V_19 ,
struct V_51 * V_52 , T_4 V_152 )
{
F_171 ( V_152 ) ;
if ( F_164 ( V_152 ) < F_9 ( V_8 . V_331 ) ) {
F_5 ( & V_8 . V_331 [ F_164 ( V_152 ) ] ) ;
F_5 ( & V_19 -> V_287 . V_331 [ F_164 ( V_152 ) ] ) ;
F_5 ( & V_52 -> V_287 . V_331 [ F_164 ( V_152 ) ] ) ;
}
}
static int F_172 ( struct V_18 * V_19 ,
struct V_51 * V_52 ,
void V_266 * * V_332 ,
T_1 V_297 ,
T_1 V_333 ,
int V_334 ,
T_4 V_152 , const char * V_335 )
{
void V_266 * V_76 = * V_332 ;
if ( F_173 ( V_152 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
if ( F_173 ( V_297 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
if ( F_173 ( V_333 , ( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
F_170 ( V_19 , V_52 , V_152 ) ;
F_13 ( V_294 , L_100 ,
V_19 -> V_74 , V_52 -> V_74 , V_335 , V_334 ,
( V_98 ) V_297 , ( V_98 ) V_333 ) ;
* V_332 = V_76 ;
return 0 ;
}
static int F_174 ( struct V_51 * V_52 ,
bool V_53 )
{
F_175 ( V_66 ) ;
struct V_18 * V_19 = V_52 -> V_19 ;
int V_4 = 0 ;
F_176 () ;
F_22 ( V_19 ) ;
for (; ; ) {
F_177 ( & V_52 -> V_66 , & V_66 , V_336 ) ;
if ( F_48 ( V_52 , V_53 ) )
break;
if ( V_53 )
F_178 ( & V_52 -> V_68 ,
& V_19 -> V_67 ) ;
F_24 ( V_19 ) ;
F_179 () ;
F_22 ( V_19 ) ;
F_33 ( & V_52 -> V_68 ) ;
if ( F_180 ( V_71 ) ) {
V_4 = - V_46 ;
break;
}
}
F_181 ( & V_52 -> V_66 , & V_66 ) ;
F_24 ( V_19 ) ;
F_182 () ;
return V_4 ;
}
static int F_183 ( struct V_18 * V_19 ,
struct V_51 * V_52 ,
T_1 V_154 , T_5 V_283 ,
T_6 * V_284 , int V_337 )
{
void V_266 * V_145 = ( void V_266 * ) ( V_182 ) V_154 ;
void V_266 * V_76 = V_145 + * V_284 ;
void V_266 * V_285 = V_145 + V_283 ;
int V_4 = 0 ;
int V_338 ;
if ( * V_284 == 0 ) {
if ( F_173 ( V_339 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
}
V_340:
F_22 ( V_19 ) ;
V_338 = F_50 ( V_52 ) ;
F_24 ( V_19 ) ;
V_52 -> V_58 |= V_341 ;
F_184 ( V_338 ,
! ! V_52 -> V_57 ,
! F_27 ( V_19 , & V_52 -> V_54 ) ) ;
if ( V_338 ) {
if ( ! ( V_52 -> V_58 & ( V_60 |
V_59 ) ) ) {
F_66 ( L_101 ,
V_19 -> V_74 , V_52 -> V_74 , V_52 -> V_58 ) ;
F_185 ( V_6 ,
V_5 < 2 ) ;
}
F_61 ( V_19 -> V_342 ) ;
}
if ( V_337 ) {
if ( ! F_49 ( V_52 , V_338 ) )
V_4 = - V_343 ;
} else {
V_4 = F_174 ( V_52 , V_338 ) ;
}
V_52 -> V_58 &= ~ V_341 ;
if ( V_4 )
return V_4 ;
while ( 1 ) {
T_4 V_152 ;
struct V_226 V_227 ;
struct V_29 * V_33 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_139 * V_140 = NULL ;
struct V_51 * V_344 ;
F_22 ( V_19 ) ;
if ( ! F_25 ( & V_52 -> V_54 ) )
V_28 = & V_52 -> V_54 ;
else if ( ! F_25 ( & V_19 -> V_54 ) &&
V_338 )
V_28 = & V_19 -> V_54 ;
else {
F_24 ( V_19 ) ;
if ( V_76 - V_145 == 4 && ! V_52 -> V_55 )
goto V_340;
break;
}
if ( V_285 - V_76 < sizeof( V_227 ) + 4 ) {
F_24 ( V_19 ) ;
break;
}
V_33 = F_35 ( V_28 ) ;
switch ( V_33 -> type ) {
case V_276 : {
F_24 ( V_19 ) ;
V_140 = F_169 ( V_33 , struct V_139 , V_30 ) ;
} break;
case V_345 : {
struct V_346 * V_13 = F_169 (
V_33 , struct V_346 , V_30 ) ;
F_165 ( V_13 -> V_152 == V_153 ) ;
F_24 ( V_19 ) ;
if ( F_173 ( V_13 -> V_152 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_13 -> V_152 = V_153 ;
V_76 += sizeof( T_4 ) ;
F_170 ( V_19 , V_52 , V_13 -> V_152 ) ;
} break;
case V_275 : {
F_24 ( V_19 ) ;
V_152 = V_282 ;
if ( F_173 ( V_152 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
F_170 ( V_19 , V_52 , V_152 ) ;
F_13 ( V_347 ,
L_102 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
F_77 ( V_33 ) ;
F_4 ( V_259 ) ;
} break;
case V_91 : {
struct V_24 * V_25 = F_169 ( V_33 , struct V_24 , V_30 ) ;
int V_100 , V_131 ;
T_1 V_297 = V_25 -> V_76 ;
T_1 V_333 = V_25 -> V_86 ;
int V_334 = V_25 -> V_89 ;
int V_109 ;
int V_105 ;
void V_266 * V_348 = V_76 ;
F_29 ( V_19 != V_25 -> V_19 ) ;
V_100 = V_25 -> V_102 ||
V_25 -> V_107 ;
V_131 = ! F_85 ( & V_25 -> V_110 ) ||
V_25 -> V_108 ||
V_25 -> V_88 || V_100 ;
V_105 = V_25 -> V_105 ;
V_109 = V_25 -> V_109 ;
if ( V_131 && ! V_109 ) {
V_25 -> V_109 = 1 ;
V_25 -> V_299 = 1 ;
V_25 -> V_108 ++ ;
}
if ( V_100 && ! V_105 ) {
V_25 -> V_105 = 1 ;
V_25 -> V_298 = 1 ;
V_25 -> V_107 ++ ;
}
if ( ! V_100 && V_105 )
V_25 -> V_105 = 0 ;
if ( ! V_131 && V_109 )
V_25 -> V_109 = 0 ;
if ( ! V_131 && ! V_100 ) {
F_13 ( V_97 ,
L_103 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_334 ,
( V_98 ) V_297 ,
( V_98 ) V_333 ) ;
F_86 ( & V_25 -> V_62 , & V_19 -> V_77 ) ;
F_24 ( V_19 ) ;
F_90 ( V_25 ) ;
F_91 ( V_25 ) ;
F_78 ( V_25 ) ;
} else
F_24 ( V_19 ) ;
if ( V_131 && ! V_109 )
V_4 = F_172 (
V_19 , V_52 , & V_76 , V_297 ,
V_333 , V_334 ,
V_349 , L_104 ) ;
if ( ! V_4 && V_100 && ! V_105 )
V_4 = F_172 (
V_19 , V_52 , & V_76 , V_297 ,
V_333 , V_334 ,
V_350 , L_105 ) ;
if ( ! V_4 && ! V_100 && V_105 )
V_4 = F_172 (
V_19 , V_52 , & V_76 , V_297 ,
V_333 , V_334 ,
V_351 , L_106 ) ;
if ( ! V_4 && ! V_131 && V_109 )
V_4 = F_172 (
V_19 , V_52 , & V_76 , V_297 ,
V_333 , V_334 ,
V_352 , L_107 ) ;
if ( V_348 == V_76 )
F_13 ( V_97 ,
L_108 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_334 ,
( V_98 ) V_297 ,
( V_98 ) V_333 ) ;
if ( V_4 )
return V_4 ;
} break;
case V_326 :
case V_328 :
case V_327 : {
struct V_323 * V_128 ;
T_4 V_152 ;
T_1 V_86 ;
V_128 = F_169 ( V_33 , struct V_323 , V_30 ) ;
if ( V_33 -> type == V_327 )
V_152 = V_353 ;
else
V_152 = V_354 ;
V_86 = V_128 -> V_86 ;
F_13 ( V_325 ,
L_109 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_152 == V_354 ?
L_110 :
L_111 ,
( V_98 ) V_86 ) ;
if ( V_33 -> type == V_327 ) {
F_24 ( V_19 ) ;
F_77 ( V_128 ) ;
F_4 ( V_130 ) ;
} else {
F_28 (
V_33 , & V_19 -> V_355 ) ;
F_24 ( V_19 ) ;
}
if ( F_173 ( V_152 , ( T_4 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_4 ) ;
if ( F_173 ( V_86 ,
( T_1 V_266 * ) V_76 ) )
return - V_267 ;
V_76 += sizeof( T_1 ) ;
F_170 ( V_19 , V_52 , V_152 ) ;
if ( V_152 == V_354 )
goto V_201;
} break;
}
if ( ! V_140 )
continue;
F_29 ( V_140 -> V_145 == NULL ) ;
if ( V_140 -> V_145 -> V_188 ) {
struct V_24 * V_188 = V_140 -> V_145 -> V_188 ;
V_227 . V_242 . V_76 = V_188 -> V_76 ;
V_227 . V_86 = V_188 -> V_86 ;
V_140 -> V_251 = F_150 ( V_71 ) ;
if ( V_140 -> V_263 < V_188 -> V_92 &&
! ( V_140 -> V_34 & V_149 ) )
F_61 ( V_140 -> V_263 ) ;
else if ( ! ( V_140 -> V_34 & V_149 ) ||
V_140 -> V_251 > V_188 -> V_92 )
F_61 ( V_188 -> V_92 ) ;
V_152 = V_356 ;
} else {
V_227 . V_242 . V_76 = 0 ;
V_227 . V_86 = 0 ;
V_152 = V_357 ;
}
V_227 . V_262 = V_140 -> V_262 ;
V_227 . V_34 = V_140 -> V_34 ;
V_227 . V_261 = F_186 ( F_187 () , V_140 -> V_261 ) ;
V_344 = F_116 ( V_140 ) ;
if ( V_344 ) {
struct V_358 * V_359 = V_344 -> V_19 -> V_40 ;
V_227 . V_360 = F_188 ( V_359 ,
F_189 ( V_71 ) ) ;
} else {
V_227 . V_360 = 0 ;
}
V_227 . V_159 = V_140 -> V_145 -> V_159 ;
V_227 . V_187 = V_140 -> V_145 -> V_187 ;
V_227 . V_120 . V_76 . V_145 = ( T_1 )
( ( V_182 ) V_140 -> V_145 -> V_120 +
F_130 ( & V_19 -> V_195 ) ) ;
V_227 . V_120 . V_76 . V_260 = V_227 . V_120 . V_76 . V_145 +
F_126 ( V_140 -> V_145 -> V_159 ,
sizeof( void * ) ) ;
if ( F_173 ( V_152 , ( T_4 V_266 * ) V_76 ) ) {
if ( V_344 )
F_109 ( V_344 ) ;
return - V_267 ;
}
V_76 += sizeof( T_4 ) ;
if ( F_190 ( V_76 , & V_227 , sizeof( V_227 ) ) ) {
if ( V_344 )
F_109 ( V_344 ) ;
return - V_267 ;
}
V_76 += sizeof( V_227 ) ;
F_191 ( V_140 ) ;
F_170 ( V_19 , V_52 , V_152 ) ;
F_13 ( V_186 ,
L_112 ,
V_19 -> V_74 , V_52 -> V_74 ,
( V_152 == V_356 ) ? L_113 :
L_114 ,
V_140 -> V_89 , V_344 ? V_344 -> V_19 -> V_74 : 0 ,
V_344 ? V_344 -> V_74 : 0 , V_152 ,
V_140 -> V_145 -> V_159 , V_140 -> V_145 -> V_187 ,
( V_98 ) V_227 . V_120 . V_76 . V_145 , ( V_98 ) V_227 . V_120 . V_76 . V_260 ) ;
if ( V_344 )
F_109 ( V_344 ) ;
V_140 -> V_145 -> V_265 = 1 ;
if ( V_152 == V_356 && ! ( V_140 -> V_34 & V_149 ) ) {
F_22 ( V_52 -> V_19 ) ;
V_140 -> V_250 = V_52 -> V_57 ;
V_140 -> V_248 = V_52 ;
V_52 -> V_57 = V_140 ;
F_24 ( V_52 -> V_19 ) ;
} else {
F_118 ( V_140 ) ;
}
break;
}
V_201:
* V_284 = V_76 - V_145 ;
F_22 ( V_19 ) ;
if ( V_19 -> V_316 == 0 &&
F_26 ( & V_52 -> V_19 -> V_67 ) &&
V_19 -> V_317 < V_19 -> V_361 &&
( V_52 -> V_58 & ( V_60 |
V_59 ) )
) {
V_19 -> V_316 ++ ;
F_24 ( V_19 ) ;
F_13 ( V_314 ,
L_115 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
if ( F_173 ( V_362 , ( T_4 V_266 * ) V_145 ) )
return - V_267 ;
F_170 ( V_19 , V_52 , V_362 ) ;
} else
F_24 ( V_19 ) ;
return 0 ;
}
static void F_192 ( struct V_18 * V_19 ,
struct V_27 * V_28 )
{
struct V_29 * V_33 ;
while ( 1 ) {
V_33 = F_37 ( V_19 , V_28 ) ;
if ( ! V_33 )
return;
switch ( V_33 -> type ) {
case V_276 : {
struct V_139 * V_140 ;
V_140 = F_169 ( V_33 , struct V_139 , V_30 ) ;
if ( V_140 -> V_145 -> V_188 &&
! ( V_140 -> V_34 & V_149 ) ) {
F_119 ( V_140 , V_225 ) ;
} else {
F_13 ( V_363 ,
L_116 ,
V_140 -> V_89 ) ;
F_118 ( V_140 ) ;
}
} break;
case V_345 : {
struct V_346 * V_13 = F_169 (
V_33 , struct V_346 , V_30 ) ;
F_13 ( V_363 ,
L_117 ,
V_13 -> V_152 ) ;
} break;
case V_275 : {
F_13 ( V_363 ,
L_118 ) ;
F_77 ( V_33 ) ;
F_4 ( V_259 ) ;
} break;
case V_328 :
case V_327 : {
struct V_323 * V_128 ;
V_128 = F_169 ( V_33 , struct V_323 , V_30 ) ;
F_13 ( V_363 ,
L_119 ,
( V_98 ) V_128 -> V_86 ) ;
F_77 ( V_128 ) ;
F_4 ( V_130 ) ;
} break;
default:
F_80 ( L_120 ,
V_33 -> type ) ;
break;
}
}
}
static struct V_51 * F_193 (
struct V_18 * V_19 , struct V_51 * V_364 )
{
struct V_51 * V_52 = NULL ;
struct V_62 * V_84 = NULL ;
struct V_62 * * V_83 = & V_19 -> V_64 . V_62 ;
while ( * V_83 ) {
V_84 = * V_83 ;
V_52 = F_54 ( V_84 , struct V_51 , V_62 ) ;
if ( V_71 -> V_74 < V_52 -> V_74 )
V_83 = & ( * V_83 ) -> V_78 ;
else if ( V_71 -> V_74 > V_52 -> V_74 )
V_83 = & ( * V_83 ) -> V_79 ;
else
return V_52 ;
}
if ( ! V_364 )
return NULL ;
V_52 = V_364 ;
F_6 ( V_365 ) ;
V_52 -> V_19 = V_19 ;
V_52 -> V_74 = V_71 -> V_74 ;
F_194 ( & V_52 -> V_143 , 0 ) ;
F_195 ( & V_52 -> V_66 ) ;
F_74 ( & V_52 -> V_54 ) ;
F_71 ( & V_52 -> V_62 , V_84 , V_83 ) ;
F_72 ( & V_52 -> V_62 , & V_19 -> V_64 ) ;
V_52 -> V_55 = true ;
V_52 -> V_234 . V_30 . type = V_345 ;
V_52 -> V_234 . V_152 = V_153 ;
V_52 -> V_151 . V_30 . type = V_345 ;
V_52 -> V_151 . V_152 = V_153 ;
F_74 ( & V_364 -> V_68 ) ;
return V_52 ;
}
static struct V_51 * F_196 ( struct V_18 * V_19 )
{
struct V_51 * V_52 ;
struct V_51 * V_364 ;
F_22 ( V_19 ) ;
V_52 = F_193 ( V_19 , NULL ) ;
F_24 ( V_19 ) ;
if ( ! V_52 ) {
V_364 = F_76 ( sizeof( * V_52 ) , V_99 ) ;
if ( V_364 == NULL )
return NULL ;
F_22 ( V_19 ) ;
V_52 = F_193 ( V_19 , V_364 ) ;
F_24 ( V_19 ) ;
if ( V_52 != V_364 )
F_77 ( V_364 ) ;
}
return V_52 ;
}
static void F_115 ( struct V_18 * V_19 )
{
F_29 ( ! F_26 ( & V_19 -> V_54 ) ) ;
F_29 ( ! F_26 ( & V_19 -> V_355 ) ) ;
F_197 ( & V_19 -> V_195 ) ;
F_198 ( V_19 -> V_40 ) ;
F_4 ( V_366 ) ;
F_77 ( V_19 ) ;
}
static void F_112 ( struct V_51 * V_52 )
{
F_29 ( ! F_26 ( & V_52 -> V_54 ) ) ;
F_4 ( V_365 ) ;
F_113 ( V_52 -> V_19 ) ;
F_77 ( V_52 ) ;
}
static int F_199 ( struct V_18 * V_19 ,
struct V_51 * V_52 )
{
struct V_139 * V_140 ;
struct V_139 * V_367 = NULL ;
int V_368 = 0 ;
struct V_139 * V_369 = NULL ;
F_22 ( V_52 -> V_19 ) ;
V_19 -> V_143 ++ ;
F_5 ( & V_52 -> V_143 ) ;
F_86 ( & V_52 -> V_62 , & V_19 -> V_64 ) ;
V_140 = V_52 -> V_57 ;
if ( V_140 ) {
F_14 ( & V_140 -> V_26 ) ;
if ( V_140 -> V_248 == V_52 )
V_367 = V_140 ;
}
V_52 -> V_144 = true ;
while ( V_140 ) {
V_369 = V_140 ;
V_368 ++ ;
F_13 ( V_363 ,
L_121 ,
V_19 -> V_74 , V_52 -> V_74 ,
V_140 -> V_89 ,
( V_140 -> V_248 == V_52 ) ? L_122 : L_123 ) ;
if ( V_140 -> V_248 == V_52 ) {
V_140 -> V_200 = NULL ;
V_140 -> V_248 = NULL ;
if ( V_140 -> V_145 ) {
V_140 -> V_145 -> V_146 = NULL ;
V_140 -> V_145 = NULL ;
}
V_140 = V_140 -> V_250 ;
} else if ( V_140 -> V_141 == V_52 ) {
V_140 -> V_141 = NULL ;
V_140 = V_140 -> V_142 ;
} else
F_96 () ;
F_16 ( & V_369 -> V_26 ) ;
if ( V_140 )
F_14 ( & V_140 -> V_26 ) ;
}
F_24 ( V_52 -> V_19 ) ;
if ( V_367 )
F_119 ( V_367 , V_225 ) ;
F_192 ( V_19 , & V_52 -> V_54 ) ;
F_109 ( V_52 ) ;
return V_368 ;
}
static unsigned int F_200 ( struct V_44 * V_370 ,
struct V_371 * V_66 )
{
struct V_18 * V_19 = V_370 -> V_372 ;
struct V_51 * V_52 = NULL ;
bool V_338 ;
V_52 = F_196 ( V_19 ) ;
F_22 ( V_52 -> V_19 ) ;
V_52 -> V_58 |= V_65 ;
V_338 = F_50 ( V_52 ) ;
F_24 ( V_52 -> V_19 ) ;
F_201 ( V_370 , & V_52 -> V_66 , V_66 ) ;
if ( F_49 ( V_52 , V_338 ) )
return V_373 ;
return 0 ;
}
static int F_202 ( struct V_44 * V_370 ,
unsigned int V_152 , unsigned long V_374 ,
struct V_51 * V_52 )
{
int V_4 = 0 ;
struct V_18 * V_19 = V_370 -> V_372 ;
unsigned int V_283 = F_203 ( V_152 ) ;
void V_266 * V_375 = ( void V_266 * ) V_374 ;
struct V_376 V_377 ;
if ( V_283 != sizeof( struct V_376 ) ) {
V_4 = - V_106 ;
goto V_378;
}
if ( F_156 ( & V_377 , V_375 , sizeof( V_377 ) ) ) {
V_4 = - V_267 ;
goto V_378;
}
F_13 ( V_379 ,
L_124 ,
V_19 -> V_74 , V_52 -> V_74 ,
( V_98 ) V_377 . V_380 , ( V_98 ) V_377 . V_381 ,
( V_98 ) V_377 . V_382 , ( V_98 ) V_377 . V_383 ) ;
if ( V_377 . V_380 > 0 ) {
V_4 = F_161 ( V_19 , V_52 ,
V_377 . V_381 ,
V_377 . V_380 ,
& V_377 . V_384 ) ;
F_204 ( V_4 ) ;
if ( V_4 < 0 ) {
V_377 . V_385 = 0 ;
if ( F_190 ( V_375 , & V_377 , sizeof( V_377 ) ) )
V_4 = - V_267 ;
goto V_378;
}
}
if ( V_377 . V_382 > 0 ) {
V_4 = F_183 ( V_19 , V_52 , V_377 . V_383 ,
V_377 . V_382 ,
& V_377 . V_385 ,
V_370 -> V_386 & V_387 ) ;
F_205 ( V_4 ) ;
F_22 ( V_19 ) ;
if ( ! F_25 ( & V_19 -> V_54 ) )
F_60 ( V_19 ) ;
F_24 ( V_19 ) ;
if ( V_4 < 0 ) {
if ( F_190 ( V_375 , & V_377 , sizeof( V_377 ) ) )
V_4 = - V_267 ;
goto V_378;
}
}
F_13 ( V_379 ,
L_125 ,
V_19 -> V_74 , V_52 -> V_74 ,
( V_98 ) V_377 . V_384 , ( V_98 ) V_377 . V_380 ,
( V_98 ) V_377 . V_385 , ( V_98 ) V_377 . V_382 ) ;
if ( F_190 ( V_375 , & V_377 , sizeof( V_377 ) ) ) {
V_4 = - V_267 ;
goto V_378;
}
V_378:
return V_4 ;
}
static int F_206 ( struct V_44 * V_370 )
{
int V_4 = 0 ;
struct V_18 * V_19 = V_370 -> V_372 ;
struct V_122 * V_103 = V_19 -> V_103 ;
struct V_24 * V_80 ;
T_8 V_388 = F_207 () ;
F_146 ( & V_103 -> V_253 ) ;
if ( V_103 -> V_104 ) {
F_80 ( L_126 ) ;
V_4 = - V_389 ;
goto V_378;
}
V_4 = F_208 ( V_19 -> V_40 ) ;
if ( V_4 < 0 )
goto V_378;
if ( F_209 ( V_103 -> V_390 ) ) {
if ( ! F_210 ( V_103 -> V_390 , V_388 ) ) {
F_80 ( L_127 ,
F_186 ( & V_391 , V_388 ) ,
F_186 ( & V_391 ,
V_103 -> V_390 ) ) ;
V_4 = - V_202 ;
goto V_378;
}
} else {
V_103 -> V_390 = V_388 ;
}
V_80 = F_75 ( V_19 , NULL ) ;
if ( ! V_80 ) {
V_4 = - V_137 ;
goto V_378;
}
F_90 ( V_80 ) ;
V_80 -> V_108 ++ ;
V_80 -> V_107 ++ ;
V_80 -> V_105 = 1 ;
V_80 -> V_109 = 1 ;
V_103 -> V_104 = V_80 ;
F_91 ( V_80 ) ;
F_93 ( V_80 ) ;
V_378:
F_147 ( & V_103 -> V_253 ) ;
return V_4 ;
}
static int F_211 ( struct V_18 * V_19 ,
struct V_392 * V_393 )
{
struct V_62 * V_63 ;
T_1 V_76 = V_393 -> V_76 ;
memset ( V_393 , 0 , sizeof( * V_393 ) ) ;
F_22 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_77 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
struct V_24 * V_25 = F_54 ( V_63 , struct V_24 ,
V_62 ) ;
if ( V_25 -> V_76 > V_76 ) {
V_393 -> V_76 = V_25 -> V_76 ;
V_393 -> V_86 = V_25 -> V_86 ;
V_393 -> V_105 = V_25 -> V_105 ;
V_393 -> V_109 = V_25 -> V_109 ;
break;
}
}
F_24 ( V_19 ) ;
return 0 ;
}
static long F_212 ( struct V_44 * V_370 , unsigned int V_152 , unsigned long V_374 )
{
int V_4 ;
struct V_18 * V_19 = V_370 -> V_372 ;
struct V_51 * V_52 ;
unsigned int V_283 = F_203 ( V_152 ) ;
void V_266 * V_375 = ( void V_266 * ) V_374 ;
F_213 ( & V_19 -> V_195 ) ;
F_214 ( V_152 , V_374 ) ;
V_4 = F_185 ( V_6 , V_5 < 2 ) ;
if ( V_4 )
goto V_394;
V_52 = F_196 ( V_19 ) ;
if ( V_52 == NULL ) {
V_4 = - V_137 ;
goto V_395;
}
switch ( V_152 ) {
case V_396 :
V_4 = F_202 ( V_370 , V_152 , V_374 , V_52 ) ;
if ( V_4 )
goto V_395;
break;
case V_397 : {
int V_361 ;
if ( F_156 ( & V_361 , V_375 ,
sizeof( V_361 ) ) ) {
V_4 = - V_106 ;
goto V_395;
}
F_22 ( V_19 ) ;
V_19 -> V_361 = V_361 ;
F_24 ( V_19 ) ;
break;
}
case V_398 :
V_4 = F_206 ( V_370 ) ;
if ( V_4 )
goto V_395;
break;
case V_399 :
F_13 ( V_314 , L_128 ,
V_19 -> V_74 , V_52 -> V_74 ) ;
F_199 ( V_19 , V_52 ) ;
V_52 = NULL ;
break;
case V_400 : {
struct V_401 V_266 * V_402 = V_375 ;
if ( V_283 != sizeof( struct V_401 ) ) {
V_4 = - V_106 ;
goto V_395;
}
if ( F_173 ( V_403 ,
& V_402 -> V_404 ) ) {
V_4 = - V_106 ;
goto V_395;
}
break;
}
case V_405 : {
struct V_392 V_393 ;
if ( F_156 ( & V_393 , V_375 , sizeof( V_393 ) ) ) {
V_4 = - V_267 ;
goto V_395;
}
V_4 = F_211 ( V_19 , & V_393 ) ;
if ( V_4 < 0 )
goto V_395;
if ( F_190 ( V_375 , & V_393 , sizeof( V_393 ) ) ) {
V_4 = - V_267 ;
goto V_395;
}
break;
}
default:
V_4 = - V_106 ;
goto V_395;
}
V_4 = 0 ;
V_395:
if ( V_52 )
V_52 -> V_55 = false ;
F_185 ( V_6 , V_5 < 2 ) ;
if ( V_4 && V_4 != - V_46 )
F_215 ( L_129 , V_19 -> V_74 , V_71 -> V_74 , V_152 , V_374 , V_4 ) ;
V_394:
F_216 ( V_4 ) ;
return V_4 ;
}
static void F_217 ( struct V_406 * V_407 )
{
struct V_18 * V_19 = V_407 -> V_408 ;
F_13 ( V_409 ,
L_130 ,
V_19 -> V_74 , V_407 -> V_410 , V_407 -> V_411 ,
( V_407 -> V_411 - V_407 -> V_410 ) / V_412 , V_407 -> V_413 ,
( unsigned long ) F_218 ( V_407 -> V_414 ) ) ;
}
static void F_219 ( struct V_406 * V_407 )
{
struct V_18 * V_19 = V_407 -> V_408 ;
F_13 ( V_409 ,
L_131 ,
V_19 -> V_74 , V_407 -> V_410 , V_407 -> V_411 ,
( V_407 -> V_411 - V_407 -> V_410 ) / V_412 , V_407 -> V_413 ,
( unsigned long ) F_218 ( V_407 -> V_414 ) ) ;
F_220 ( & V_19 -> V_195 ) ;
F_221 ( V_19 , V_415 ) ;
}
static int F_222 ( struct V_416 * V_417 )
{
return V_418 ;
}
static int F_223 ( struct V_44 * V_370 , struct V_406 * V_407 )
{
int V_4 ;
struct V_18 * V_19 = V_370 -> V_372 ;
const char * V_419 ;
if ( V_19 -> V_40 != V_71 -> V_420 )
return - V_106 ;
if ( ( V_407 -> V_411 - V_407 -> V_410 ) > V_421 )
V_407 -> V_411 = V_407 -> V_410 + V_421 ;
F_13 ( V_409 ,
L_132 ,
V_21 , V_19 -> V_74 , V_407 -> V_410 , V_407 -> V_411 ,
( V_407 -> V_411 - V_407 -> V_410 ) / V_412 , V_407 -> V_413 ,
( unsigned long ) F_218 ( V_407 -> V_414 ) ) ;
if ( V_407 -> V_413 & V_422 ) {
V_4 = - V_202 ;
V_419 = L_133 ;
goto V_423;
}
V_407 -> V_413 = ( V_407 -> V_413 | V_424 ) & ~ V_425 ;
V_407 -> V_426 = & V_427 ;
V_407 -> V_408 = V_19 ;
V_4 = F_224 ( & V_19 -> V_195 , V_407 ) ;
if ( V_4 )
return V_4 ;
V_19 -> V_36 = F_225 ( V_71 ) ;
return 0 ;
V_423:
F_80 ( L_134 ,
V_19 -> V_74 , V_407 -> V_410 , V_407 -> V_411 , V_419 , V_4 ) ;
return V_4 ;
}
static int F_226 ( struct V_428 * V_429 , struct V_44 * V_370 )
{
struct V_18 * V_19 ;
struct V_430 * V_431 ;
F_13 ( V_409 , L_135 ,
V_71 -> V_420 -> V_74 , V_71 -> V_74 ) ;
V_19 = F_76 ( sizeof( * V_19 ) , V_99 ) ;
if ( V_19 == NULL )
return - V_137 ;
F_73 ( & V_19 -> V_23 ) ;
F_73 ( & V_19 -> V_22 ) ;
F_227 ( V_71 -> V_420 ) ;
V_19 -> V_40 = V_71 -> V_420 ;
F_74 ( & V_19 -> V_54 ) ;
V_19 -> V_342 = F_150 ( V_71 ) ;
V_431 = F_169 ( V_370 -> V_372 , struct V_430 ,
V_432 ) ;
V_19 -> V_103 = & V_431 -> V_103 ;
F_228 ( & V_19 -> V_195 ) ;
F_6 ( V_366 ) ;
V_19 -> V_74 = V_71 -> V_420 -> V_74 ;
F_74 ( & V_19 -> V_355 ) ;
F_74 ( & V_19 -> V_67 ) ;
V_370 -> V_372 = V_19 ;
F_146 ( & V_433 ) ;
F_97 ( & V_19 -> V_434 , & V_435 ) ;
F_147 ( & V_433 ) ;
if ( V_436 ) {
char V_437 [ 11 ] ;
snprintf ( V_437 , sizeof( V_437 ) , L_136 , V_19 -> V_74 ) ;
V_19 -> V_438 = F_229 ( V_437 , V_439 ,
V_436 ,
( void * ) ( unsigned long ) V_19 -> V_74 ,
& V_440 ) ;
}
return 0 ;
}
static int F_230 ( struct V_44 * V_370 , T_9 V_441 )
{
struct V_18 * V_19 = V_370 -> V_372 ;
F_221 ( V_19 , V_442 ) ;
return 0 ;
}
static void F_231 ( struct V_18 * V_19 )
{
struct V_62 * V_63 ;
int V_443 = 0 ;
F_22 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_64 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
struct V_51 * V_52 = F_54 ( V_63 , struct V_51 , V_62 ) ;
V_52 -> V_55 = true ;
if ( V_52 -> V_58 & V_341 ) {
F_56 ( & V_52 -> V_66 ) ;
V_443 ++ ;
}
}
F_24 ( V_19 ) ;
F_13 ( V_409 ,
L_137 , V_19 -> V_74 ,
V_443 ) ;
}
static int F_232 ( struct V_428 * V_429 , struct V_44 * V_370 )
{
struct V_18 * V_19 = V_370 -> V_372 ;
F_233 ( V_19 -> V_438 ) ;
F_221 ( V_19 , V_444 ) ;
return 0 ;
}
static int F_234 ( struct V_24 * V_25 , int V_110 )
{
struct V_114 * V_118 ;
int V_128 = 0 ;
struct V_18 * V_19 = V_25 -> V_19 ;
F_192 ( V_19 , & V_25 -> V_96 ) ;
F_90 ( V_25 ) ;
F_22 ( V_19 ) ;
F_32 ( & V_25 -> V_30 ) ;
F_29 ( ! V_25 -> V_88 ) ;
if ( F_85 ( & V_25 -> V_110 ) && V_25 -> V_88 == 1 ) {
F_24 ( V_19 ) ;
F_91 ( V_25 ) ;
F_78 ( V_25 ) ;
return V_110 ;
}
V_25 -> V_19 = NULL ;
V_25 -> V_107 = 0 ;
V_25 -> V_108 = 0 ;
F_24 ( V_19 ) ;
F_14 ( & V_111 ) ;
F_97 ( & V_25 -> V_112 , & V_445 ) ;
F_16 ( & V_111 ) ;
F_235 (ref, &node->refs, node_entry) {
V_110 ++ ;
F_22 ( V_118 -> V_19 ) ;
if ( ! V_118 -> V_128 ) {
F_24 ( V_118 -> V_19 ) ;
continue;
}
V_128 ++ ;
F_29 ( ! F_26 ( & V_118 -> V_128 -> V_30 . V_15 ) ) ;
V_118 -> V_128 -> V_30 . type = V_326 ;
F_28 ( & V_118 -> V_128 -> V_30 ,
& V_118 -> V_19 -> V_54 ) ;
F_60 ( V_118 -> V_19 ) ;
F_24 ( V_118 -> V_19 ) ;
}
F_13 ( V_129 ,
L_138 ,
V_25 -> V_89 , V_110 , V_128 ) ;
F_91 ( V_25 ) ;
F_93 ( V_25 ) ;
return V_110 ;
}
static void F_236 ( struct V_18 * V_19 )
{
struct V_122 * V_103 = V_19 -> V_103 ;
struct V_62 * V_63 ;
int V_64 , V_77 , V_446 , V_447 , V_368 ;
F_29 ( V_19 -> V_36 ) ;
F_146 ( & V_433 ) ;
F_87 ( & V_19 -> V_434 ) ;
F_147 ( & V_433 ) ;
F_146 ( & V_103 -> V_253 ) ;
if ( V_103 -> V_104 &&
V_103 -> V_104 -> V_19 == V_19 ) {
F_13 ( V_129 ,
L_139 ,
V_21 , V_19 -> V_74 ) ;
V_103 -> V_104 = NULL ;
}
F_147 ( & V_103 -> V_253 ) ;
F_22 ( V_19 ) ;
V_19 -> V_143 ++ ;
V_19 -> V_144 = true ;
V_64 = 0 ;
V_368 = 0 ;
while ( ( V_63 = F_52 ( & V_19 -> V_64 ) ) ) {
struct V_51 * V_52 ;
V_52 = F_54 ( V_63 , struct V_51 , V_62 ) ;
F_24 ( V_19 ) ;
V_64 ++ ;
V_368 += F_199 ( V_19 , V_52 ) ;
F_22 ( V_19 ) ;
}
V_77 = 0 ;
V_446 = 0 ;
while ( ( V_63 = F_52 ( & V_19 -> V_77 ) ) ) {
struct V_24 * V_25 ;
V_25 = F_54 ( V_63 , struct V_24 , V_62 ) ;
V_77 ++ ;
F_68 ( V_25 ) ;
F_86 ( & V_25 -> V_62 , & V_19 -> V_77 ) ;
F_24 ( V_19 ) ;
V_446 = F_234 ( V_25 , V_446 ) ;
F_22 ( V_19 ) ;
}
F_24 ( V_19 ) ;
V_447 = 0 ;
F_102 ( V_19 ) ;
while ( ( V_63 = F_52 ( & V_19 -> V_117 ) ) ) {
struct V_114 * V_118 ;
V_118 = F_54 ( V_63 , struct V_114 , V_119 ) ;
V_447 ++ ;
F_98 ( V_118 ) ;
F_103 ( V_19 ) ;
F_104 ( V_118 ) ;
F_102 ( V_19 ) ;
}
F_103 ( V_19 ) ;
F_192 ( V_19 , & V_19 -> V_54 ) ;
F_192 ( V_19 , & V_19 -> V_355 ) ;
F_13 ( V_409 ,
L_140 ,
V_21 , V_19 -> V_74 , V_64 , V_77 , V_446 ,
V_447 , V_368 ) ;
F_113 ( V_19 ) ;
}
static void F_237 ( struct V_448 * V_30 )
{
struct V_18 * V_19 ;
struct V_35 * V_36 ;
int V_449 ;
do {
F_146 ( & V_450 ) ;
if ( ! F_85 ( & V_451 ) ) {
V_19 = F_238 ( V_451 . V_452 ,
struct V_18 , V_453 ) ;
F_239 ( & V_19 -> V_453 ) ;
V_449 = V_19 -> V_454 ;
V_19 -> V_454 = 0 ;
} else {
V_19 = NULL ;
V_449 = 0 ;
}
F_147 ( & V_450 ) ;
V_36 = NULL ;
if ( V_449 & V_415 ) {
V_36 = V_19 -> V_36 ;
if ( V_36 )
V_19 -> V_36 = NULL ;
}
if ( V_449 & V_442 )
F_231 ( V_19 ) ;
if ( V_449 & V_444 )
F_236 ( V_19 ) ;
if ( V_36 )
F_240 ( V_36 ) ;
} while ( V_19 );
}
static void
F_221 ( struct V_18 * V_19 , enum V_455 V_449 )
{
F_146 ( & V_450 ) ;
V_19 -> V_454 |= V_449 ;
if ( F_241 ( & V_19 -> V_453 ) ) {
F_97 ( & V_19 -> V_453 ,
& V_451 ) ;
F_242 ( & V_456 ) ;
}
F_147 ( & V_450 ) ;
}
static void F_243 ( struct V_457 * V_458 ,
struct V_18 * V_19 ,
const char * V_459 ,
struct V_139 * V_140 )
{
struct V_18 * V_200 ;
struct V_154 * V_145 = V_140 -> V_145 ;
F_14 ( & V_140 -> V_26 ) ;
V_200 = V_140 -> V_200 ;
F_244 ( V_458 ,
L_141 ,
V_459 , V_140 -> V_89 , V_140 ,
V_140 -> V_141 ? V_140 -> V_141 -> V_19 -> V_74 : 0 ,
V_140 -> V_141 ? V_140 -> V_141 -> V_74 : 0 ,
V_200 ? V_200 -> V_74 : 0 ,
V_140 -> V_248 ? V_140 -> V_248 -> V_74 : 0 ,
V_140 -> V_262 , V_140 -> V_34 , V_140 -> V_263 , V_140 -> V_279 ) ;
F_16 ( & V_140 -> V_26 ) ;
if ( V_19 != V_200 ) {
F_245 ( V_458 , L_142 ) ;
return;
}
if ( V_145 == NULL ) {
F_245 ( V_458 , L_143 ) ;
return;
}
if ( V_145 -> V_188 )
F_244 ( V_458 , L_144 , V_145 -> V_188 -> V_89 ) ;
F_244 ( V_458 , L_145 ,
V_145 -> V_159 , V_145 -> V_187 ,
V_145 -> V_120 ) ;
}
static void F_246 ( struct V_457 * V_458 ,
struct V_18 * V_19 ,
const char * V_459 ,
const char * V_460 ,
struct V_29 * V_33 )
{
struct V_24 * V_25 ;
struct V_139 * V_140 ;
switch ( V_33 -> type ) {
case V_276 :
V_140 = F_169 ( V_33 , struct V_139 , V_30 ) ;
F_243 (
V_458 , V_19 , V_460 , V_140 ) ;
break;
case V_345 : {
struct V_346 * V_13 = F_169 (
V_33 , struct V_346 , V_30 ) ;
F_244 ( V_458 , L_146 ,
V_459 , V_13 -> V_152 ) ;
} break;
case V_275 :
F_244 ( V_458 , L_147 , V_459 ) ;
break;
case V_91 :
V_25 = F_169 ( V_33 , struct V_24 , V_30 ) ;
F_244 ( V_458 , L_148 ,
V_459 , V_25 -> V_89 ,
( V_98 ) V_25 -> V_76 , ( V_98 ) V_25 -> V_86 ) ;
break;
case V_326 :
F_244 ( V_458 , L_149 , V_459 ) ;
break;
case V_328 :
F_244 ( V_458 , L_150 , V_459 ) ;
break;
case V_327 :
F_244 ( V_458 , L_151 , V_459 ) ;
break;
default:
F_244 ( V_458 , L_152 , V_459 , V_33 -> type ) ;
break;
}
}
static void F_247 ( struct V_457 * V_458 ,
struct V_51 * V_52 ,
int V_461 )
{
struct V_139 * V_140 ;
struct V_29 * V_33 ;
T_5 V_462 = V_458 -> V_463 ;
T_5 V_464 ;
F_244 ( V_458 , L_153 ,
V_52 -> V_74 , V_52 -> V_58 ,
V_52 -> V_55 ,
F_111 ( & V_52 -> V_143 ) ) ;
V_464 = V_458 -> V_463 ;
V_140 = V_52 -> V_57 ;
while ( V_140 ) {
if ( V_140 -> V_141 == V_52 ) {
F_243 ( V_458 , V_52 -> V_19 ,
L_154 , V_140 ) ;
V_140 = V_140 -> V_142 ;
} else if ( V_140 -> V_248 == V_52 ) {
F_243 ( V_458 , V_52 -> V_19 ,
L_155 , V_140 ) ;
V_140 = V_140 -> V_250 ;
} else {
F_243 ( V_458 , V_52 -> V_19 ,
L_156 , V_140 ) ;
V_140 = NULL ;
}
}
F_168 (w, &thread->todo, entry) {
F_246 ( V_458 , V_52 -> V_19 , L_157 ,
L_158 , V_33 ) ;
}
if ( ! V_461 && V_458 -> V_463 == V_464 )
V_458 -> V_463 = V_462 ;
}
static void F_248 ( struct V_457 * V_458 ,
struct V_24 * V_25 )
{
struct V_114 * V_118 ;
struct V_29 * V_33 ;
int V_463 ;
V_463 = 0 ;
F_235 (ref, &node->refs, node_entry)
V_463 ++ ;
F_244 ( V_458 , L_159 ,
V_25 -> V_89 , ( V_98 ) V_25 -> V_76 , ( V_98 ) V_25 -> V_86 ,
V_25 -> V_105 , V_25 -> V_109 ,
V_25 -> V_107 , V_25 -> V_108 ,
V_25 -> V_102 , V_463 , V_25 -> V_88 ) ;
if ( V_463 ) {
F_245 ( V_458 , L_160 ) ;
F_235 (ref, &node->refs, node_entry)
F_244 ( V_458 , L_161 , V_118 -> V_19 -> V_74 ) ;
}
F_245 ( V_458 , L_142 ) ;
if ( V_25 -> V_19 ) {
F_168 (w, &node->async_todo, entry)
F_246 ( V_458 , V_25 -> V_19 , L_157 ,
L_162 , V_33 ) ;
}
}
static void F_249 ( struct V_457 * V_458 ,
struct V_114 * V_118 )
{
F_90 ( V_118 -> V_25 ) ;
F_244 ( V_458 , L_163 ,
V_118 -> V_120 . V_89 , V_118 -> V_120 . V_115 ,
V_118 -> V_25 -> V_19 ? L_164 : L_165 ,
V_118 -> V_25 -> V_89 , V_118 -> V_120 . V_100 ,
V_118 -> V_120 . V_131 , V_118 -> V_128 ) ;
F_91 ( V_118 -> V_25 ) ;
}
static void F_250 ( struct V_457 * V_458 ,
struct V_18 * V_19 , int V_465 )
{
struct V_29 * V_33 ;
struct V_62 * V_63 ;
T_5 V_462 = V_458 -> V_463 ;
T_5 V_464 ;
struct V_24 * V_466 = NULL ;
F_244 ( V_458 , L_166 , V_19 -> V_74 ) ;
F_244 ( V_458 , L_167 , V_19 -> V_103 -> V_244 ) ;
V_464 = V_458 -> V_463 ;
F_22 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_64 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) )
F_247 ( V_458 , F_54 ( V_63 , struct V_51 ,
V_62 ) , V_465 ) ;
for ( V_63 = F_52 ( & V_19 -> V_77 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
struct V_24 * V_25 = F_54 ( V_63 , struct V_24 ,
V_62 ) ;
F_68 ( V_25 ) ;
F_24 ( V_19 ) ;
if ( V_466 )
F_93 ( V_466 ) ;
F_82 ( V_25 ) ;
F_248 ( V_458 , V_25 ) ;
F_83 ( V_25 ) ;
V_466 = V_25 ;
F_22 ( V_19 ) ;
}
F_24 ( V_19 ) ;
if ( V_466 )
F_93 ( V_466 ) ;
if ( V_465 ) {
F_102 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_117 ) ;
V_63 != NULL ;
V_63 = F_53 ( V_63 ) )
F_249 ( V_458 , F_54 ( V_63 ,
struct V_114 ,
V_119 ) ) ;
F_103 ( V_19 ) ;
}
F_251 ( V_458 , & V_19 -> V_195 ) ;
F_22 ( V_19 ) ;
F_168 (w, &proc->todo, entry)
F_246 ( V_458 , V_19 , L_168 ,
L_169 , V_33 ) ;
F_168 (w, &proc->delivered_death, entry) {
F_245 ( V_458 , L_170 ) ;
break;
}
F_24 ( V_19 ) ;
if ( ! V_465 && V_458 -> V_463 == V_464 )
V_458 -> V_463 = V_462 ;
}
static void F_252 ( struct V_457 * V_458 , const char * V_459 ,
struct V_8 * V_287 )
{
int V_467 ;
F_253 ( F_9 ( V_287 -> V_286 ) !=
F_9 ( V_468 ) ) ;
for ( V_467 = 0 ; V_467 < F_9 ( V_287 -> V_286 ) ; V_467 ++ ) {
int V_469 = F_111 ( & V_287 -> V_286 [ V_467 ] ) ;
if ( V_469 )
F_244 ( V_458 , L_171 , V_459 ,
V_468 [ V_467 ] , V_469 ) ;
}
F_253 ( F_9 ( V_287 -> V_331 ) !=
F_9 ( V_470 ) ) ;
for ( V_467 = 0 ; V_467 < F_9 ( V_287 -> V_331 ) ; V_467 ++ ) {
int V_469 = F_111 ( & V_287 -> V_331 [ V_467 ] ) ;
if ( V_469 )
F_244 ( V_458 , L_171 , V_459 ,
V_470 [ V_467 ] , V_469 ) ;
}
F_253 ( F_9 ( V_287 -> V_10 ) !=
F_9 ( V_471 ) ) ;
F_253 ( F_9 ( V_287 -> V_10 ) !=
F_9 ( V_287 -> V_9 ) ) ;
for ( V_467 = 0 ; V_467 < F_9 ( V_287 -> V_10 ) ; V_467 ++ ) {
int V_472 = F_111 ( & V_287 -> V_10 [ V_467 ] ) ;
int V_473 = F_111 ( & V_287 -> V_9 [ V_467 ] ) ;
if ( V_472 || V_473 )
F_244 ( V_458 , L_172 ,
V_459 ,
V_471 [ V_467 ] ,
V_472 - V_473 ,
V_472 ) ;
}
}
static void F_254 ( struct V_457 * V_458 ,
struct V_18 * V_19 )
{
struct V_29 * V_33 ;
struct V_51 * V_52 ;
struct V_62 * V_63 ;
int V_463 , V_100 , V_131 , V_474 ;
T_5 V_475 =
F_255 ( & V_19 -> V_195 ) ;
F_244 ( V_458 , L_166 , V_19 -> V_74 ) ;
F_244 ( V_458 , L_167 , V_19 -> V_103 -> V_244 ) ;
V_463 = 0 ;
V_474 = 0 ;
F_22 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_64 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) )
V_463 ++ ;
F_168 (thread, &proc->waiting_threads, waiting_thread_node)
V_474 ++ ;
F_244 ( V_458 , L_173 , V_463 ) ;
F_244 ( V_458 , L_174
L_175
L_176 , V_19 -> V_316 ,
V_19 -> V_317 , V_19 -> V_361 ,
V_474 ,
V_475 ) ;
V_463 = 0 ;
for ( V_63 = F_52 ( & V_19 -> V_77 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) )
V_463 ++ ;
F_24 ( V_19 ) ;
F_244 ( V_458 , L_177 , V_463 ) ;
V_463 = 0 ;
V_100 = 0 ;
V_131 = 0 ;
F_102 ( V_19 ) ;
for ( V_63 = F_52 ( & V_19 -> V_117 ) ; V_63 != NULL ; V_63 = F_53 ( V_63 ) ) {
struct V_114 * V_118 = F_54 ( V_63 , struct V_114 ,
V_119 ) ;
V_463 ++ ;
V_100 += V_118 -> V_120 . V_100 ;
V_131 += V_118 -> V_120 . V_131 ;
}
F_103 ( V_19 ) ;
F_244 ( V_458 , L_178 , V_463 , V_100 , V_131 ) ;
V_463 = F_256 ( & V_19 -> V_195 ) ;
F_244 ( V_458 , L_179 , V_463 ) ;
F_257 ( V_458 , & V_19 -> V_195 ) ;
V_463 = 0 ;
F_22 ( V_19 ) ;
F_168 (w, &proc->todo, entry) {
if ( V_33 -> type == V_276 )
V_463 ++ ;
}
F_24 ( V_19 ) ;
F_244 ( V_458 , L_180 , V_463 ) ;
F_252 ( V_458 , L_168 , & V_19 -> V_287 ) ;
}
static int F_258 ( struct V_457 * V_458 , void * V_476 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
struct V_24 * V_466 = NULL ;
F_245 ( V_458 , L_181 ) ;
F_14 ( & V_111 ) ;
if ( ! F_85 ( & V_445 ) )
F_245 ( V_458 , L_182 ) ;
F_235 (node, &binder_dead_nodes, dead_node) {
V_25 -> V_88 ++ ;
F_16 ( & V_111 ) ;
if ( V_466 )
F_93 ( V_466 ) ;
F_90 ( V_25 ) ;
F_248 ( V_458 , V_25 ) ;
F_91 ( V_25 ) ;
V_466 = V_25 ;
F_14 ( & V_111 ) ;
}
F_16 ( & V_111 ) ;
if ( V_466 )
F_93 ( V_466 ) ;
F_146 ( & V_433 ) ;
F_235 (proc, &binder_procs, proc_node)
F_250 ( V_458 , V_19 , 1 ) ;
F_147 ( & V_433 ) ;
return 0 ;
}
static int F_259 ( struct V_457 * V_458 , void * V_476 )
{
struct V_18 * V_19 ;
F_245 ( V_458 , L_183 ) ;
F_252 ( V_458 , L_164 , & V_8 ) ;
F_146 ( & V_433 ) ;
F_235 (proc, &binder_procs, proc_node)
F_254 ( V_458 , V_19 ) ;
F_147 ( & V_433 ) ;
return 0 ;
}
static int F_260 ( struct V_457 * V_458 , void * V_476 )
{
struct V_18 * V_19 ;
F_245 ( V_458 , L_184 ) ;
F_146 ( & V_433 ) ;
F_235 (proc, &binder_procs, proc_node)
F_250 ( V_458 , V_19 , 0 ) ;
F_147 ( & V_433 ) ;
return 0 ;
}
static int F_261 ( struct V_457 * V_458 , void * V_476 )
{
struct V_18 * V_477 ;
int V_74 = ( unsigned long ) V_458 -> V_478 ;
F_146 ( & V_433 ) ;
F_235 (itr, &binder_procs, proc_node) {
if ( V_477 -> V_74 == V_74 ) {
F_245 ( V_458 , L_185 ) ;
F_250 ( V_458 , V_477 , 1 ) ;
}
}
F_147 ( & V_433 ) ;
return 0 ;
}
static void F_262 ( struct V_457 * V_458 ,
struct V_11 * V_13 )
{
int V_89 = F_263 ( V_13 -> V_17 ) ;
F_264 () ;
F_244 ( V_458 ,
L_186 ,
V_13 -> V_89 , ( V_13 -> V_238 == 2 ) ? L_37 :
( ( V_13 -> V_238 == 1 ) ? L_187 : L_188 ) , V_13 -> V_239 ,
V_13 -> V_240 , V_13 -> V_200 , V_13 -> V_248 , V_13 -> V_243 ,
V_13 -> V_254 , V_13 -> V_241 , V_13 -> V_159 , V_13 -> V_187 ,
V_13 -> V_234 , V_13 -> V_235 ,
V_13 -> V_236 ) ;
F_264 () ;
F_244 ( V_458 , V_89 && V_89 == F_263 ( V_13 -> V_17 ) ?
L_142 : L_189 ) ;
}
static int F_265 ( struct V_457 * V_458 , void * V_476 )
{
struct V_12 * log = V_458 -> V_478 ;
unsigned int V_479 = F_111 ( & log -> V_14 ) ;
unsigned int V_463 ;
unsigned int V_14 ;
int V_467 ;
V_463 = V_479 + 1 ;
V_14 = V_463 < F_9 ( log -> V_15 ) && ! log -> V_16 ?
0 : V_463 % F_9 ( log -> V_15 ) ;
if ( V_463 > F_9 ( log -> V_15 ) || log -> V_16 )
V_463 = F_9 ( log -> V_15 ) ;
for ( V_467 = 0 ; V_467 < V_463 ; V_467 ++ ) {
unsigned int V_171 = V_14 ++ % F_9 ( log -> V_15 ) ;
F_262 ( V_458 , & log -> V_15 [ V_171 ] ) ;
}
return 0 ;
}
static int T_10 F_266 ( const char * V_244 )
{
int V_4 ;
struct V_430 * V_430 ;
V_430 = F_76 ( sizeof( * V_430 ) , V_99 ) ;
if ( ! V_430 )
return - V_137 ;
V_430 -> V_432 . V_480 = & V_481 ;
V_430 -> V_432 . V_482 = V_483 ;
V_430 -> V_432 . V_244 = V_244 ;
V_430 -> V_103 . V_390 = V_484 ;
V_430 -> V_103 . V_244 = V_244 ;
F_267 ( & V_430 -> V_103 . V_253 ) ;
V_4 = F_268 ( & V_430 -> V_432 ) ;
if ( V_4 < 0 ) {
F_77 ( V_430 ) ;
return V_4 ;
}
F_97 ( & V_430 -> V_485 , & V_486 ) ;
return V_4 ;
}
static int T_10 F_269 ( void )
{
int V_4 ;
char * V_487 , * V_488 , * V_489 ;
struct V_430 * V_490 ;
struct V_491 * V_256 ;
F_270 () ;
F_194 ( & V_12 . V_14 , ~ 0U ) ;
F_194 ( & V_281 . V_14 , ~ 0U ) ;
V_492 = F_271 ( L_190 , NULL ) ;
if ( V_492 )
V_436 = F_271 ( L_191 ,
V_492 ) ;
if ( V_492 ) {
F_229 ( L_192 ,
V_439 ,
V_492 ,
NULL ,
& V_493 ) ;
F_229 ( L_193 ,
V_439 ,
V_492 ,
NULL ,
& V_494 ) ;
F_229 ( L_194 ,
V_439 ,
V_492 ,
NULL ,
& V_495 ) ;
F_229 ( L_195 ,
V_439 ,
V_492 ,
& V_12 ,
& V_496 ) ;
F_229 ( L_196 ,
V_439 ,
V_492 ,
& V_281 ,
& V_496 ) ;
}
V_488 = F_76 ( strlen ( V_497 ) + 1 , V_99 ) ;
if ( ! V_488 ) {
V_4 = - V_137 ;
goto V_498;
}
strcpy ( V_488 , V_497 ) ;
V_489 = V_488 ;
while ( ( V_487 = F_272 ( & V_489 , L_197 ) ) ) {
V_4 = F_266 ( V_487 ) ;
if ( V_4 )
goto V_499;
}
return V_4 ;
V_499:
F_273 (device, tmp, &binder_devices, hlist) {
F_274 ( & V_490 -> V_432 ) ;
F_87 ( & V_490 -> V_485 ) ;
F_77 ( V_490 ) ;
}
F_77 ( V_488 ) ;
V_498:
F_275 ( V_492 ) ;
return V_4 ;
}
