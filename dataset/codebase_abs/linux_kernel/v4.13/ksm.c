static int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 , 0 ) ;
if ( ! V_1 )
goto V_3;
V_4 = F_2 ( V_5 , 0 ) ;
if ( ! V_4 )
goto V_6;
V_7 = F_2 ( V_8 , 0 ) ;
if ( ! V_7 )
goto V_9;
return 0 ;
V_9:
F_3 ( V_4 ) ;
V_6:
F_3 ( V_1 ) ;
V_3:
return - V_10 ;
}
static void T_1 F_4 ( void )
{
F_3 ( V_7 ) ;
F_3 ( V_4 ) ;
F_3 ( V_1 ) ;
V_7 = NULL ;
}
static T_2 bool F_5 ( struct V_5 * V_11 )
{
return V_11 -> V_12 == V_13 ;
}
static T_2 bool F_6 ( struct V_5 * V_14 )
{
return V_14 -> V_15 == V_16 ;
}
static inline void F_7 ( struct V_5 * V_14 ,
struct V_5 * V_11 )
{
F_8 ( F_6 ( V_14 ) ) ;
V_14 -> V_15 = V_16 ;
F_8 ( ! F_5 ( V_11 ) ) ;
F_9 ( & V_14 -> V_17 , & V_11 -> V_18 ) ;
V_19 ++ ;
}
static inline void F_10 ( struct V_5 * V_14 )
{
F_8 ( ! F_6 ( V_14 ) ) ;
F_11 ( & V_14 -> V_17 ) ;
V_19 -- ;
}
static inline void F_12 ( struct V_5 * V_14 )
{
F_8 ( F_5 ( V_14 ) ) ;
if ( F_6 ( V_14 ) )
F_10 ( V_14 ) ;
else
F_13 ( & V_14 -> V_20 , V_21 + F_14 ( V_14 -> V_22 ) ) ;
#ifdef F_15
V_14 -> V_15 = NULL ;
#endif
}
static inline struct V_2 * F_16 ( void )
{
struct V_2 * V_2 ;
V_2 = F_17 ( V_1 , V_23 |
V_24 | V_25 ) ;
if ( V_2 )
V_26 ++ ;
return V_2 ;
}
static inline void F_18 ( struct V_2 * V_2 )
{
V_26 -- ;
V_2 -> V_27 = NULL ;
F_19 ( V_1 , V_2 ) ;
}
static inline struct V_5 * F_20 ( void )
{
return F_21 ( V_4 , V_23 | V_28 ) ;
}
static inline void F_22 ( struct V_5 * V_5 )
{
F_8 ( V_5 -> V_12 &&
! F_5 ( V_5 ) ) ;
F_19 ( V_4 , V_5 ) ;
}
static inline struct V_8 * F_23 ( void )
{
if ( ! V_7 )
return NULL ;
return F_17 ( V_7 , V_23 ) ;
}
static inline void F_24 ( struct V_8 * V_8 )
{
F_19 ( V_7 , V_8 ) ;
}
static struct V_8 * F_25 ( struct V_29 * V_27 )
{
struct V_8 * V_30 ;
F_26 (mm_slots_hash, slot, link, (unsigned long)mm)
if ( V_30 -> V_27 == V_27 )
return V_30 ;
return NULL ;
}
static void F_27 ( struct V_29 * V_27 ,
struct V_8 * V_8 )
{
V_8 -> V_27 = V_27 ;
F_28 ( V_31 , & V_8 -> V_32 , ( unsigned long ) V_27 ) ;
}
static inline bool F_29 ( struct V_29 * V_27 )
{
return F_30 ( & V_27 -> V_33 ) == 0 ;
}
static int F_31 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_37 * V_37 ;
int V_38 = 0 ;
do {
F_32 () ;
V_37 = F_33 ( V_35 , V_36 ,
V_39 | V_40 | V_41 ) ;
if ( F_34 ( V_37 ) )
break;
if ( F_35 ( V_37 ) )
V_38 = F_36 ( V_35 , V_36 ,
V_42 | V_43 ) ;
else
V_38 = V_44 ;
F_37 ( V_37 ) ;
} while ( ! ( V_38 & ( V_44 | V_45 | V_46 | V_47 ) ) );
return ( V_38 & V_47 ) ? - V_10 : 0 ;
}
static struct V_34 * F_38 ( struct V_29 * V_27 ,
unsigned long V_36 )
{
struct V_34 * V_35 ;
if ( F_29 ( V_27 ) )
return NULL ;
V_35 = F_39 ( V_27 , V_36 ) ;
if ( ! V_35 || V_35 -> V_48 > V_36 )
return NULL ;
if ( ! ( V_35 -> V_49 & V_50 ) || ! V_35 -> V_51 )
return NULL ;
return V_35 ;
}
static void F_40 ( struct V_2 * V_2 )
{
struct V_29 * V_27 = V_2 -> V_27 ;
unsigned long V_36 = V_2 -> V_52 ;
struct V_34 * V_35 ;
F_41 ( V_2 -> V_51 ) ;
F_42 ( & V_27 -> V_53 ) ;
V_35 = F_38 ( V_27 , V_36 ) ;
if ( V_35 )
F_31 ( V_35 , V_36 ) ;
F_43 ( & V_27 -> V_53 ) ;
}
static struct V_37 * F_44 ( struct V_2 * V_2 )
{
struct V_29 * V_27 = V_2 -> V_27 ;
unsigned long V_36 = V_2 -> V_52 ;
struct V_34 * V_35 ;
struct V_37 * V_37 ;
F_42 ( & V_27 -> V_53 ) ;
V_35 = F_38 ( V_27 , V_36 ) ;
if ( ! V_35 )
goto V_3;
V_37 = F_33 ( V_35 , V_36 , V_39 ) ;
if ( F_34 ( V_37 ) )
goto V_3;
if ( F_45 ( V_37 ) ) {
F_46 ( V_35 , V_37 , V_36 ) ;
F_47 ( V_37 ) ;
} else {
F_37 ( V_37 ) ;
V_3:
V_37 = NULL ;
}
F_43 ( & V_27 -> V_53 ) ;
return V_37 ;
}
static inline int F_48 ( unsigned long V_54 )
{
return V_55 ? 0 : F_14 ( F_49 ( V_54 ) ) ;
}
static struct V_5 * F_50 ( struct V_5 * V_14 ,
struct V_56 * V_57 )
{
struct V_5 * V_11 = F_20 () ;
F_8 ( F_5 ( V_14 ) ) ;
if ( F_51 ( V_11 ) ) {
F_52 ( & V_11 -> V_18 ) ;
V_11 -> V_58 = V_59 ;
V_11 -> V_12 = V_13 ;
#if F_53 ( F_15 ) && F_53 ( V_60 )
V_11 -> V_22 = - 1 ;
#endif
V_61 ++ ;
F_54 ( & V_14 -> V_20 , & V_11 -> V_20 , V_57 ) ;
F_7 ( V_14 , V_11 ) ;
}
return V_11 ;
}
static inline void F_55 ( struct V_5 * V_11 ,
struct V_56 * V_57 )
{
F_13 ( & V_11 -> V_20 , V_57 ) ;
F_22 ( V_11 ) ;
V_61 -- ;
}
static void F_56 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_57 ( V_5 -> V_12 < 0 ) ;
F_58 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_18 . V_62 )
V_63 -- ;
else
V_64 -- ;
F_8 ( V_5 -> V_12 <= 0 ) ;
V_5 -> V_12 -- ;
F_41 ( V_2 -> V_51 ) ;
V_2 -> V_52 &= V_65 ;
F_32 () ;
}
#if V_66 >= 40903
F_59 ( V_16 <= & V_67 ) ;
F_59 ( V_16 >= & V_67 + 1 ) ;
#endif
if ( V_5 -> V_15 == & V_67 )
F_60 ( & V_5 -> V_68 ) ;
else
F_12 ( V_5 ) ;
F_22 ( V_5 ) ;
}
static struct V_37 * F_61 ( struct V_5 * V_5 , bool V_69 )
{
struct V_37 * V_37 ;
void * V_70 ;
unsigned long V_54 ;
V_70 = ( void * ) ( ( unsigned long ) V_5 |
V_71 ) ;
V_72:
V_54 = F_62 ( V_5 -> V_54 ) ;
V_37 = F_63 ( V_54 ) ;
F_64 () ;
if ( F_62 ( V_37 -> V_73 ) != V_70 )
goto V_74;
while ( ! F_65 ( V_37 ) ) {
if ( ! F_66 ( V_37 ) )
goto V_74;
F_67 () ;
}
if ( F_62 ( V_37 -> V_73 ) != V_70 ) {
F_37 ( V_37 ) ;
goto V_74;
}
if ( V_69 ) {
F_68 ( V_37 ) ;
if ( F_62 ( V_37 -> V_73 ) != V_70 ) {
F_69 ( V_37 ) ;
F_37 ( V_37 ) ;
goto V_74;
}
}
return V_37 ;
V_74:
F_70 () ;
if ( F_62 ( V_5 -> V_54 ) != V_54 )
goto V_72;
F_56 ( V_5 ) ;
return NULL ;
}
static void F_71 ( struct V_2 * V_2 )
{
if ( V_2 -> V_52 & V_75 ) {
struct V_5 * V_5 ;
struct V_37 * V_37 ;
V_5 = V_2 -> V_15 ;
V_37 = F_61 ( V_5 , true ) ;
if ( ! V_37 )
goto V_3;
F_11 ( & V_2 -> V_18 ) ;
F_69 ( V_37 ) ;
F_37 ( V_37 ) ;
if ( ! F_72 ( & V_5 -> V_18 ) )
V_63 -- ;
else
V_64 -- ;
F_8 ( V_5 -> V_12 <= 0 ) ;
V_5 -> V_12 -- ;
F_41 ( V_2 -> V_51 ) ;
V_2 -> V_52 &= V_65 ;
} else if ( V_2 -> V_52 & V_76 ) {
unsigned char V_77 ;
V_77 = ( unsigned char ) ( V_78 . V_79 - V_2 -> V_52 ) ;
F_57 ( V_77 > 1 ) ;
if ( ! V_77 )
F_13 ( & V_2 -> V_20 ,
V_80 + F_14 ( V_2 -> V_22 ) ) ;
V_81 -- ;
V_2 -> V_52 &= V_65 ;
}
V_3:
F_32 () ;
}
static void F_73 ( struct V_8 * V_8 ,
struct V_2 * * V_82 )
{
while ( * V_82 ) {
struct V_2 * V_2 = * V_82 ;
* V_82 = V_2 -> V_82 ;
F_71 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
static int F_74 ( struct V_34 * V_35 ,
unsigned long V_83 , unsigned long V_84 )
{
unsigned long V_36 ;
int V_85 = 0 ;
for ( V_36 = V_83 ; V_36 < V_84 && ! V_85 ; V_36 += V_86 ) {
if ( F_29 ( V_35 -> V_87 ) )
break;
if ( F_75 ( V_88 ) )
V_85 = - V_89 ;
else
V_85 = F_31 ( V_35 , V_36 ) ;
}
return V_85 ;
}
static int F_76 ( struct V_5 * V_5 )
{
struct V_37 * V_37 ;
int V_85 ;
V_37 = F_61 ( V_5 , true ) ;
if ( ! V_37 ) {
return 0 ;
}
if ( F_77 ( F_78 ( V_37 ) ) ) {
V_85 = - V_90 ;
} else {
F_79 ( V_37 , NULL ) ;
F_56 ( V_5 ) ;
V_85 = 0 ;
}
F_69 ( V_37 ) ;
F_37 ( V_37 ) ;
return V_85 ;
}
static int F_80 ( struct V_5 * V_5 ,
struct V_56 * V_57 )
{
struct V_5 * V_14 ;
struct V_91 * V_92 ;
if ( ! F_5 ( V_5 ) ) {
F_8 ( F_6 ( V_5 ) ) ;
if ( F_76 ( V_5 ) )
return true ;
else
return false ;
}
F_81 (dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
F_8 ( ! F_6 ( V_14 ) ) ;
if ( F_76 ( V_14 ) )
return true ;
}
F_57 ( ! F_72 ( & V_5 -> V_18 ) ) ;
F_55 ( V_5 , V_57 ) ;
return false ;
}
static int F_82 ( void )
{
struct V_5 * V_5 , * V_62 ;
int V_22 ;
int V_85 = 0 ;
for ( V_22 = 0 ; V_22 < V_93 ; V_22 ++ ) {
while ( V_21 [ V_22 ] . V_94 ) {
V_5 = F_83 ( V_21 [ V_22 ] . V_94 ,
struct V_5 , V_20 ) ;
if ( F_80 ( V_5 ,
V_21 + V_22 ) ) {
V_85 = - V_90 ;
break;
}
F_32 () ;
}
}
F_84 (stable_node, next, &migrate_nodes, list) {
if ( F_76 ( V_5 ) )
V_85 = - V_90 ;
F_32 () ;
}
return V_85 ;
}
static int F_85 ( void )
{
struct V_8 * V_8 ;
struct V_29 * V_27 ;
struct V_34 * V_35 ;
int V_85 = 0 ;
F_86 ( & V_95 ) ;
V_78 . V_8 = F_87 ( V_96 . V_97 . V_62 ,
struct V_8 , V_97 ) ;
F_88 ( & V_95 ) ;
for ( V_8 = V_78 . V_8 ;
V_8 != & V_96 ; V_8 = V_78 . V_8 ) {
V_27 = V_8 -> V_27 ;
F_42 ( & V_27 -> V_53 ) ;
for ( V_35 = V_27 -> V_98 ; V_35 ; V_35 = V_35 -> V_99 ) {
if ( F_29 ( V_27 ) )
break;
if ( ! ( V_35 -> V_49 & V_50 ) || ! V_35 -> V_51 )
continue;
V_85 = F_74 ( V_35 ,
V_35 -> V_48 , V_35 -> V_100 ) ;
if ( V_85 )
goto error;
}
F_73 ( V_8 , & V_8 -> V_82 ) ;
F_43 ( & V_27 -> V_53 ) ;
F_86 ( & V_95 ) ;
V_78 . V_8 = F_87 ( V_8 -> V_97 . V_62 ,
struct V_8 , V_97 ) ;
if ( F_29 ( V_27 ) ) {
F_89 ( & V_8 -> V_32 ) ;
F_60 ( & V_8 -> V_97 ) ;
F_88 ( & V_95 ) ;
F_24 ( V_8 ) ;
F_90 ( V_101 , & V_27 -> V_102 ) ;
F_91 ( V_27 ) ;
} else
F_88 ( & V_95 ) ;
}
F_82 () ;
V_78 . V_79 = 0 ;
return 0 ;
error:
F_43 ( & V_27 -> V_53 ) ;
F_86 ( & V_95 ) ;
V_78 . V_8 = & V_96 ;
F_88 ( & V_95 ) ;
return V_85 ;
}
static T_3 F_92 ( struct V_37 * V_37 )
{
T_3 V_103 ;
void * V_36 = F_93 ( V_37 ) ;
V_103 = F_94 ( V_36 , V_86 / 4 , 17 ) ;
F_95 ( V_36 ) ;
return V_103 ;
}
static int F_96 ( struct V_37 * V_104 , struct V_37 * V_105 )
{
char * V_106 , * V_107 ;
int V_38 ;
V_106 = F_93 ( V_104 ) ;
V_107 = F_93 ( V_105 ) ;
V_38 = memcmp ( V_106 , V_107 , V_86 ) ;
F_95 ( V_107 ) ;
F_95 ( V_106 ) ;
return V_38 ;
}
static inline int F_97 ( struct V_37 * V_104 , struct V_37 * V_105 )
{
return ! F_96 ( V_104 , V_105 ) ;
}
static int F_98 ( struct V_34 * V_35 , struct V_37 * V_37 ,
T_4 * V_108 )
{
struct V_29 * V_27 = V_35 -> V_87 ;
struct V_109 V_110 = {
. V_37 = V_37 ,
. V_35 = V_35 ,
} ;
int V_111 ;
int V_85 = - V_112 ;
unsigned long V_113 ;
unsigned long V_114 ;
V_110 . V_52 = F_99 ( V_37 , V_35 ) ;
if ( V_110 . V_52 == - V_112 )
goto V_3;
F_57 ( F_100 ( V_37 ) ) ;
V_113 = V_110 . V_52 ;
V_114 = V_110 . V_52 + V_86 ;
F_101 ( V_27 , V_113 , V_114 ) ;
if ( ! V_109 ( & V_110 ) )
goto V_115;
if ( F_102 ( ! V_110 . V_116 , L_1 ) )
goto V_117;
if ( F_103 ( * V_110 . V_116 ) || F_104 ( * V_110 . V_116 ) ||
( F_105 ( * V_110 . V_116 ) && F_106 ( * V_110 . V_116 ) ) ||
F_107 ( V_27 ) ) {
T_4 V_118 ;
V_111 = F_66 ( V_37 ) ;
F_108 ( V_35 , V_110 . V_52 , F_109 ( V_37 ) ) ;
V_118 = F_110 ( V_35 , V_110 . V_52 , V_110 . V_116 ) ;
if ( F_111 ( V_37 ) + 1 + V_111 != F_112 ( V_37 ) ) {
F_113 ( V_27 , V_110 . V_52 , V_110 . V_116 , V_118 ) ;
goto V_117;
}
if ( F_104 ( V_118 ) )
F_114 ( V_37 ) ;
if ( F_105 ( V_118 ) )
V_118 = F_115 ( F_116 ( V_118 ) ) ;
else
V_118 = F_115 ( F_117 ( V_118 ) ) ;
F_118 ( V_27 , V_110 . V_52 , V_110 . V_116 , V_118 ) ;
}
* V_108 = * V_110 . V_116 ;
V_85 = 0 ;
V_117:
F_119 ( & V_110 ) ;
V_115:
F_120 ( V_27 , V_113 , V_114 ) ;
V_3:
return V_85 ;
}
static int F_121 ( struct V_34 * V_35 , struct V_37 * V_37 ,
struct V_37 * V_119 , T_4 V_108 )
{
struct V_29 * V_27 = V_35 -> V_87 ;
T_5 * V_120 ;
T_4 * V_121 ;
T_4 V_122 ;
T_6 * V_123 ;
unsigned long V_36 ;
int V_85 = - V_112 ;
unsigned long V_113 ;
unsigned long V_114 ;
V_36 = F_99 ( V_37 , V_35 ) ;
if ( V_36 == - V_112 )
goto V_3;
V_120 = F_122 ( V_27 , V_36 ) ;
if ( ! V_120 )
goto V_3;
V_113 = V_36 ;
V_114 = V_36 + V_86 ;
F_101 ( V_27 , V_113 , V_114 ) ;
V_121 = F_123 ( V_27 , V_120 , V_36 , & V_123 ) ;
if ( ! F_124 ( * V_121 , V_108 ) ) {
F_125 ( V_121 , V_123 ) ;
goto V_115;
}
if ( ! F_126 ( F_109 ( V_119 ) ) ) {
F_127 ( V_119 ) ;
F_128 ( V_119 , V_35 , V_36 , false ) ;
V_122 = F_129 ( V_119 , V_35 -> V_124 ) ;
} else {
V_122 = F_130 ( F_131 ( F_109 ( V_119 ) ,
V_35 -> V_124 ) ) ;
}
F_108 ( V_35 , V_36 , F_132 ( * V_121 ) ) ;
F_110 ( V_35 , V_36 , V_121 ) ;
F_118 ( V_27 , V_36 , V_121 , V_122 ) ;
F_133 ( V_37 , false ) ;
if ( ! F_78 ( V_37 ) )
F_134 ( V_37 ) ;
F_37 ( V_37 ) ;
F_125 ( V_121 , V_123 ) ;
V_85 = 0 ;
V_115:
F_120 ( V_27 , V_113 , V_114 ) ;
V_3:
return V_85 ;
}
static int F_135 ( struct V_34 * V_35 ,
struct V_37 * V_37 , struct V_37 * V_119 )
{
T_4 V_108 = F_136 ( 0 ) ;
int V_85 = - V_112 ;
if ( V_37 == V_119 )
return 0 ;
if ( ! F_45 ( V_37 ) )
goto V_3;
if ( ! F_137 ( V_37 ) )
goto V_3;
if ( F_100 ( V_37 ) ) {
if ( F_138 ( V_37 ) )
goto V_117;
}
if ( F_98 ( V_35 , V_37 , & V_108 ) == 0 ) {
if ( ! V_119 ) {
F_79 ( V_37 , NULL ) ;
F_139 ( V_37 ) ;
if ( ! F_140 ( V_37 ) )
F_141 ( V_37 ) ;
V_85 = 0 ;
} else if ( F_97 ( V_37 , V_119 ) )
V_85 = F_121 ( V_35 , V_37 , V_119 , V_108 ) ;
}
if ( ( V_35 -> V_49 & V_125 ) && V_119 && ! V_85 ) {
F_142 ( V_37 ) ;
if ( ! F_143 ( V_119 ) ) {
F_69 ( V_37 ) ;
F_68 ( V_119 ) ;
F_144 ( V_119 ) ;
V_37 = V_119 ;
}
}
V_117:
F_69 ( V_37 ) ;
V_3:
return V_85 ;
}
static int F_145 ( struct V_2 * V_2 ,
struct V_37 * V_37 , struct V_37 * V_119 )
{
struct V_29 * V_27 = V_2 -> V_27 ;
struct V_34 * V_35 ;
int V_85 = - V_112 ;
F_42 ( & V_27 -> V_53 ) ;
V_35 = F_38 ( V_27 , V_2 -> V_52 ) ;
if ( ! V_35 )
goto V_3;
V_85 = F_135 ( V_35 , V_37 , V_119 ) ;
if ( V_85 )
goto V_3;
F_71 ( V_2 ) ;
V_2 -> V_51 = V_35 -> V_51 ;
F_146 ( V_35 -> V_51 ) ;
V_3:
F_43 ( & V_27 -> V_53 ) ;
return V_85 ;
}
static struct V_37 * F_147 ( struct V_2 * V_2 ,
struct V_37 * V_37 ,
struct V_2 * V_126 ,
struct V_37 * V_127 )
{
int V_85 ;
V_85 = F_145 ( V_2 , V_37 , NULL ) ;
if ( ! V_85 ) {
V_85 = F_145 ( V_126 ,
V_127 , V_37 ) ;
if ( V_85 )
F_40 ( V_2 ) ;
}
return V_85 ? NULL : V_37 ;
}
static T_2
bool F_148 ( struct V_5 * V_5 , int V_128 )
{
F_8 ( V_5 -> V_12 < 0 ) ;
return V_5 -> V_12 &&
V_5 -> V_12 + V_128 < V_129 ;
}
static T_2
bool F_149 ( struct V_5 * V_5 )
{
return F_148 ( V_5 , 0 ) ;
}
struct V_37 * F_150 ( struct V_5 * * V_130 ,
struct V_5 * * V_131 ,
struct V_56 * V_57 ,
bool V_132 )
{
struct V_5 * V_14 , * V_133 = NULL , * V_5 = * V_131 ;
struct V_91 * V_92 ;
struct V_37 * V_134 , * V_127 = NULL ;
int V_135 = 0 ;
int V_136 ;
if ( ! V_132 ||
F_151 ( V_59 , V_5 -> V_58 +
F_152 (
V_137 ) ) )
V_132 = false ;
else
V_5 -> V_58 = V_59 ;
F_81 (dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
F_32 () ;
V_134 = F_61 ( V_14 , false ) ;
if ( ! V_134 )
continue;
V_135 += 1 ;
if ( F_149 ( V_14 ) ) {
if ( ! V_133 ||
V_14 -> V_12 > V_136 ) {
if ( V_133 )
F_37 ( V_127 ) ;
V_133 = V_14 ;
V_136 = V_133 -> V_12 ;
V_127 = V_134 ;
if ( ! V_132 )
break;
continue;
}
}
F_37 ( V_134 ) ;
}
if ( V_133 ) {
if ( V_132 && V_135 == 1 ) {
F_57 ( V_5 -> V_18 . V_138 -> V_62 ) ;
F_54 ( & V_5 -> V_20 , & V_133 -> V_20 ,
V_57 ) ;
F_22 ( V_5 ) ;
V_61 -- ;
V_19 -- ;
* V_131 = V_133 ;
V_5 = NULL ;
} else if ( V_5 -> V_18 . V_138 != & V_133 -> V_17 &&
F_148 ( V_133 , 1 ) ) {
F_11 ( & V_133 -> V_17 ) ;
F_9 ( & V_133 -> V_17 ,
& V_5 -> V_18 ) ;
}
}
* V_130 = V_133 ;
return V_127 ;
}
static struct V_5 * F_153 ( struct V_5 * V_5 ,
struct V_56 * V_57 )
{
if ( ! F_5 ( V_5 ) )
return V_5 ;
if ( F_72 ( & V_5 -> V_18 ) ) {
F_55 ( V_5 , V_57 ) ;
return NULL ;
}
return F_154 ( V_5 -> V_18 . V_138 ,
F_155 ( * V_5 ) , V_17 ) ;
}
static struct V_37 * F_156 ( struct V_5 * * V_130 ,
struct V_5 * * V_131 ,
struct V_56 * V_57 ,
bool V_132 )
{
struct V_5 * V_5 = * V_131 ;
if ( ! F_5 ( V_5 ) ) {
if ( F_149 ( V_5 ) ) {
* V_130 = V_5 ;
return F_61 ( V_5 , false ) ;
}
* V_130 = NULL ;
return NULL ;
}
return F_150 ( V_130 , V_131 , V_57 ,
V_132 ) ;
}
static struct V_37 * F_157 ( struct V_37 * V_37 )
{
int V_22 ;
struct V_56 * V_57 ;
struct V_94 * * V_139 ;
struct V_94 * V_140 ;
struct V_5 * V_5 , * F_150 , * V_141 ;
struct V_5 * V_142 ;
V_142 = F_158 ( V_37 ) ;
if ( V_142 && V_142 -> V_15 != & V_67 ) {
F_127 ( V_37 ) ;
return V_37 ;
}
V_22 = F_48 ( F_109 ( V_37 ) ) ;
V_57 = V_21 + V_22 ;
V_72:
V_139 = & V_57 -> V_94 ;
V_140 = NULL ;
while ( * V_139 ) {
struct V_37 * V_127 ;
int V_38 ;
F_32 () ;
V_5 = F_83 ( * V_139 , struct V_5 , V_20 ) ;
V_141 = NULL ;
V_127 = F_159 ( & F_150 , & V_5 , V_57 ) ;
if ( ! F_150 ) {
V_141 = F_153 ( V_5 ,
V_57 ) ;
if ( ! V_141 ) {
goto V_72;
}
V_127 = F_61 ( V_141 , false ) ;
}
F_8 ( ! F_150 ^ ! ! V_141 ) ;
if ( ! V_127 ) {
goto V_72;
}
V_38 = F_96 ( V_37 , V_127 ) ;
F_37 ( V_127 ) ;
V_140 = * V_139 ;
if ( V_38 < 0 )
V_139 = & V_140 -> V_143 ;
else if ( V_38 > 0 )
V_139 = & V_140 -> V_144 ;
else {
if ( V_142 ) {
F_8 ( V_142 -> V_15 != & V_67 ) ;
if ( F_111 ( V_37 ) > 1 )
goto V_145;
}
if ( ! F_150 ) {
return NULL ;
}
V_127 = F_61 ( F_150 , true ) ;
if ( F_160 ( ! V_127 ) )
goto V_72;
F_69 ( V_127 ) ;
if ( F_48 ( F_150 -> V_54 ) !=
F_14 ( F_150 -> V_22 ) ) {
F_37 ( V_127 ) ;
goto V_146;
}
return V_127 ;
}
}
if ( ! V_142 )
return NULL ;
F_60 ( & V_142 -> V_68 ) ;
F_161 ( V_142 -> V_22 = V_22 ) ;
F_162 ( & V_142 -> V_20 , V_140 , V_139 ) ;
F_163 ( & V_142 -> V_20 , V_57 ) ;
V_3:
if ( F_149 ( V_142 ) ) {
F_127 ( V_37 ) ;
return V_37 ;
} else
return NULL ;
V_146:
if ( F_150 == V_5 ) {
F_8 ( F_5 ( F_150 ) ) ;
F_8 ( F_6 ( F_150 ) ) ;
if ( V_142 ) {
F_8 ( V_142 -> V_15 != & V_67 ) ;
F_60 ( & V_142 -> V_68 ) ;
F_161 ( V_142 -> V_22 = V_22 ) ;
F_54 ( & F_150 -> V_20 ,
& V_142 -> V_20 ,
V_57 ) ;
if ( F_149 ( V_142 ) )
F_127 ( V_37 ) ;
else
V_37 = NULL ;
} else {
F_13 ( & F_150 -> V_20 , V_57 ) ;
V_37 = NULL ;
}
} else {
F_8 ( ! F_5 ( V_5 ) ) ;
F_10 ( F_150 ) ;
if ( V_142 ) {
F_8 ( V_142 -> V_15 != & V_67 ) ;
F_60 ( & V_142 -> V_68 ) ;
F_161 ( V_142 -> V_22 = V_22 ) ;
F_7 ( V_142 , V_5 ) ;
if ( F_149 ( V_142 ) )
F_127 ( V_37 ) ;
else
V_37 = NULL ;
} else {
V_37 = NULL ;
}
}
F_150 -> V_15 = & V_67 ;
F_164 ( & F_150 -> V_68 , F_150 -> V_15 ) ;
return V_37 ;
V_145:
if ( ! F_150 )
F_150 = V_141 ;
if ( F_150 == V_5 ) {
F_8 ( F_5 ( F_150 ) ) ;
F_8 ( F_6 ( F_150 ) ) ;
V_5 = F_50 ( F_150 ,
V_57 ) ;
if ( ! V_5 )
return NULL ;
}
F_8 ( ! F_5 ( V_5 ) ) ;
F_8 ( ! F_6 ( F_150 ) ) ;
F_8 ( V_142 -> V_15 != & V_67 ) ;
F_60 ( & V_142 -> V_68 ) ;
F_161 ( V_142 -> V_22 = V_22 ) ;
F_7 ( V_142 , V_5 ) ;
goto V_3;
}
static struct V_5 * F_165 ( struct V_37 * V_119 )
{
int V_22 ;
unsigned long V_54 ;
struct V_56 * V_57 ;
struct V_94 * * V_139 ;
struct V_94 * V_140 ;
struct V_5 * V_5 , * F_150 , * V_141 ;
bool V_147 = false ;
V_54 = F_109 ( V_119 ) ;
V_22 = F_48 ( V_54 ) ;
V_57 = V_21 + V_22 ;
V_72:
V_140 = NULL ;
V_139 = & V_57 -> V_94 ;
while ( * V_139 ) {
struct V_37 * V_127 ;
int V_38 ;
F_32 () ;
V_5 = F_83 ( * V_139 , struct V_5 , V_20 ) ;
V_141 = NULL ;
V_127 = V_11 ( & F_150 , V_5 , V_57 ) ;
if ( ! F_150 ) {
V_141 = F_153 ( V_5 ,
V_57 ) ;
if ( ! V_141 ) {
goto V_72;
}
V_127 = F_61 ( V_141 , false ) ;
}
F_8 ( ! F_150 ^ ! ! V_141 ) ;
if ( ! V_127 ) {
goto V_72;
}
V_38 = F_96 ( V_119 , V_127 ) ;
F_37 ( V_127 ) ;
V_140 = * V_139 ;
if ( V_38 < 0 )
V_139 = & V_140 -> V_143 ;
else if ( V_38 > 0 )
V_139 = & V_140 -> V_144 ;
else {
V_147 = true ;
break;
}
}
F_150 = F_20 () ;
if ( ! F_150 )
return NULL ;
F_52 ( & F_150 -> V_18 ) ;
F_150 -> V_54 = V_54 ;
F_79 ( V_119 , F_150 ) ;
F_150 -> V_12 = 0 ;
F_161 ( F_150 -> V_22 = V_22 ) ;
if ( ! V_147 ) {
F_162 ( & F_150 -> V_20 , V_140 , V_139 ) ;
F_163 ( & F_150 -> V_20 , V_57 ) ;
} else {
if ( ! F_5 ( V_5 ) ) {
struct V_5 * V_148 = V_5 ;
V_5 = F_50 ( V_148 , V_57 ) ;
if ( ! V_5 ) {
F_22 ( F_150 ) ;
return NULL ;
}
}
F_7 ( F_150 , V_5 ) ;
}
return F_150 ;
}
static
struct V_2 * F_166 ( struct V_2 * V_2 ,
struct V_37 * V_37 ,
struct V_37 * * V_149 )
{
struct V_94 * * V_139 ;
struct V_56 * V_57 ;
struct V_94 * V_140 = NULL ;
int V_22 ;
V_22 = F_48 ( F_109 ( V_37 ) ) ;
V_57 = V_80 + V_22 ;
V_139 = & V_57 -> V_94 ;
while ( * V_139 ) {
struct V_2 * V_126 ;
struct V_37 * V_127 ;
int V_38 ;
F_32 () ;
V_126 = F_83 ( * V_139 , struct V_2 , V_20 ) ;
V_127 = F_44 ( V_126 ) ;
if ( ! V_127 )
return NULL ;
if ( V_37 == V_127 ) {
F_37 ( V_127 ) ;
return NULL ;
}
V_38 = F_96 ( V_37 , V_127 ) ;
V_140 = * V_139 ;
if ( V_38 < 0 ) {
F_37 ( V_127 ) ;
V_139 = & V_140 -> V_143 ;
} else if ( V_38 > 0 ) {
F_37 ( V_127 ) ;
V_139 = & V_140 -> V_144 ;
} else if ( ! V_55 &&
F_167 ( V_127 ) != V_22 ) {
F_37 ( V_127 ) ;
return NULL ;
} else {
* V_149 = V_127 ;
return V_126 ;
}
}
V_2 -> V_52 |= V_76 ;
V_2 -> V_52 |= ( V_78 . V_79 & V_150 ) ;
F_161 ( V_2 -> V_22 = V_22 ) ;
F_162 ( & V_2 -> V_20 , V_140 , V_139 ) ;
F_163 ( & V_2 -> V_20 , V_57 ) ;
V_81 ++ ;
return NULL ;
}
static void F_168 ( struct V_2 * V_2 ,
struct V_5 * V_5 ,
bool V_151 )
{
F_57 ( V_5 -> V_12 < 0 ) ;
V_5 -> V_12 ++ ;
if ( ! V_151 )
F_77 ( V_5 -> V_12 >
V_129 ) ;
V_2 -> V_15 = V_5 ;
V_2 -> V_52 |= V_75 ;
F_9 ( & V_2 -> V_18 , & V_5 -> V_18 ) ;
if ( V_2 -> V_18 . V_62 )
V_63 ++ ;
else
V_64 ++ ;
}
static void F_169 ( struct V_37 * V_37 , struct V_2 * V_2 )
{
struct V_2 * V_126 ;
struct V_37 * V_127 = NULL ;
struct V_5 * V_5 ;
struct V_37 * V_119 ;
unsigned int V_103 ;
int V_85 ;
bool V_151 = false ;
V_5 = F_158 ( V_37 ) ;
if ( V_5 ) {
if ( V_5 -> V_15 != & V_67 &&
F_48 ( F_62 ( V_5 -> V_54 ) ) !=
F_14 ( V_5 -> V_22 ) ) {
F_12 ( V_5 ) ;
V_5 -> V_15 = & V_67 ;
F_164 ( & V_5 -> V_68 , V_5 -> V_15 ) ;
}
if ( V_5 -> V_15 != & V_67 &&
V_2 -> V_15 == V_5 )
return;
if ( ! F_149 ( V_5 ) )
V_151 = true ;
}
V_119 = F_157 ( V_37 ) ;
if ( V_119 == V_37 && V_2 -> V_15 == V_5 ) {
F_37 ( V_119 ) ;
return;
}
F_71 ( V_2 ) ;
if ( V_119 ) {
V_85 = F_145 ( V_2 , V_37 , V_119 ) ;
if ( ! V_85 ) {
F_68 ( V_119 ) ;
F_168 ( V_2 , F_158 ( V_119 ) ,
V_151 ) ;
F_69 ( V_119 ) ;
}
F_37 ( V_119 ) ;
return;
}
V_103 = F_92 ( V_37 ) ;
if ( V_2 -> V_152 != V_103 ) {
V_2 -> V_152 = V_103 ;
return;
}
if ( V_153 && ( V_103 == V_154 ) ) {
struct V_34 * V_35 ;
V_35 = F_38 ( V_2 -> V_27 , V_2 -> V_52 ) ;
V_85 = F_135 ( V_35 , V_37 ,
F_170 ( V_2 -> V_52 ) ) ;
if ( ! V_85 )
return;
}
V_126 =
F_166 ( V_2 , V_37 , & V_127 ) ;
if ( V_126 ) {
V_119 = F_147 ( V_2 , V_37 ,
V_126 , V_127 ) ;
F_37 ( V_127 ) ;
if ( V_119 ) {
F_68 ( V_119 ) ;
V_5 = F_165 ( V_119 ) ;
if ( V_5 ) {
F_168 ( V_126 , V_5 ,
false ) ;
F_168 ( V_2 , V_5 ,
false ) ;
}
F_69 ( V_119 ) ;
if ( ! V_5 ) {
F_40 ( V_126 ) ;
F_40 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_171 ( struct V_8 * V_8 ,
struct V_2 * * V_82 ,
unsigned long V_36 )
{
struct V_2 * V_2 ;
while ( * V_82 ) {
V_2 = * V_82 ;
if ( ( V_2 -> V_52 & V_65 ) == V_36 )
return V_2 ;
if ( V_2 -> V_52 > V_36 )
break;
* V_82 = V_2 -> V_82 ;
F_71 ( V_2 ) ;
F_18 ( V_2 ) ;
}
V_2 = F_16 () ;
if ( V_2 ) {
V_2 -> V_27 = V_8 -> V_27 ;
V_2 -> V_52 = V_36 ;
V_2 -> V_82 = * V_82 ;
* V_82 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_172 ( struct V_37 * * V_37 )
{
struct V_29 * V_27 ;
struct V_8 * V_30 ;
struct V_34 * V_35 ;
struct V_2 * V_2 ;
int V_22 ;
if ( F_173 ( & V_96 . V_97 ) )
return NULL ;
V_30 = V_78 . V_8 ;
if ( V_30 == & V_96 ) {
F_174 () ;
if ( ! V_55 ) {
struct V_5 * V_5 , * V_62 ;
struct V_37 * V_37 ;
F_84 (stable_node, next,
&migrate_nodes, list) {
V_37 = F_61 ( V_5 , false ) ;
if ( V_37 )
F_37 ( V_37 ) ;
F_32 () ;
}
}
for ( V_22 = 0 ; V_22 < V_93 ; V_22 ++ )
V_80 [ V_22 ] = V_155 ;
F_86 ( & V_95 ) ;
V_30 = F_87 ( V_30 -> V_97 . V_62 , struct V_8 , V_97 ) ;
V_78 . V_8 = V_30 ;
F_88 ( & V_95 ) ;
if ( V_30 == & V_96 )
return NULL ;
V_156:
V_78 . V_52 = 0 ;
V_78 . V_82 = & V_30 -> V_82 ;
}
V_27 = V_30 -> V_27 ;
F_42 ( & V_27 -> V_53 ) ;
if ( F_29 ( V_27 ) )
V_35 = NULL ;
else
V_35 = F_39 ( V_27 , V_78 . V_52 ) ;
for (; V_35 ; V_35 = V_35 -> V_99 ) {
if ( ! ( V_35 -> V_49 & V_50 ) )
continue;
if ( V_78 . V_52 < V_35 -> V_48 )
V_78 . V_52 = V_35 -> V_48 ;
if ( ! V_35 -> V_51 )
V_78 . V_52 = V_35 -> V_100 ;
while ( V_78 . V_52 < V_35 -> V_100 ) {
if ( F_29 ( V_27 ) )
break;
* V_37 = F_33 ( V_35 , V_78 . V_52 , V_39 ) ;
if ( F_34 ( * V_37 ) ) {
V_78 . V_52 += V_86 ;
F_32 () ;
continue;
}
if ( F_45 ( * V_37 ) ) {
F_46 ( V_35 , * V_37 , V_78 . V_52 ) ;
F_47 ( * V_37 ) ;
V_2 = F_171 ( V_30 ,
V_78 . V_82 , V_78 . V_52 ) ;
if ( V_2 ) {
V_78 . V_82 =
& V_2 -> V_82 ;
V_78 . V_52 += V_86 ;
} else
F_37 ( * V_37 ) ;
F_43 ( & V_27 -> V_53 ) ;
return V_2 ;
}
F_37 ( * V_37 ) ;
V_78 . V_52 += V_86 ;
F_32 () ;
}
}
if ( F_29 ( V_27 ) ) {
V_78 . V_52 = 0 ;
V_78 . V_82 = & V_30 -> V_82 ;
}
F_73 ( V_30 , V_78 . V_82 ) ;
F_86 ( & V_95 ) ;
V_78 . V_8 = F_87 ( V_30 -> V_97 . V_62 ,
struct V_8 , V_97 ) ;
if ( V_78 . V_52 == 0 ) {
F_89 ( & V_30 -> V_32 ) ;
F_60 ( & V_30 -> V_97 ) ;
F_88 ( & V_95 ) ;
F_24 ( V_30 ) ;
F_90 ( V_101 , & V_27 -> V_102 ) ;
F_43 ( & V_27 -> V_53 ) ;
F_91 ( V_27 ) ;
} else {
F_43 ( & V_27 -> V_53 ) ;
F_88 ( & V_95 ) ;
}
V_30 = V_78 . V_8 ;
if ( V_30 != & V_96 )
goto V_156;
V_78 . V_79 ++ ;
return NULL ;
}
static void F_175 ( unsigned int V_157 )
{
struct V_2 * V_2 ;
struct V_37 * V_158 ( V_37 ) ;
while ( V_157 -- && F_51 ( ! F_176 ( V_88 ) ) ) {
F_32 () ;
V_2 = F_172 ( & V_37 ) ;
if ( ! V_2 )
return;
F_169 ( V_37 , V_2 ) ;
F_37 ( V_37 ) ;
}
}
static int F_177 ( void )
{
return ( V_159 & V_160 ) && ! F_173 ( & V_96 . V_97 ) ;
}
static int F_178 ( void * V_161 )
{
F_179 () ;
F_180 ( V_88 , 5 ) ;
while ( ! F_181 () ) {
F_182 ( & V_162 ) ;
F_183 () ;
if ( F_177 () )
F_175 ( V_163 ) ;
F_184 ( & V_162 ) ;
F_185 () ;
if ( F_177 () ) {
F_186 (
F_152 ( V_164 ) ) ;
} else {
F_187 ( V_165 ,
F_177 () || F_181 () ) ;
}
}
return 0 ;
}
int F_188 ( struct V_34 * V_35 , unsigned long V_83 ,
unsigned long V_84 , int V_166 , unsigned long * V_49 )
{
struct V_29 * V_27 = V_35 -> V_87 ;
int V_85 ;
switch ( V_166 ) {
case V_167 :
if ( * V_49 & ( V_50 | V_168 | V_169 |
V_170 | V_171 | V_172 |
V_173 | V_174 ) )
return 0 ;
#ifdef F_189
if ( * V_49 & F_189 )
return 0 ;
#endif
if ( ! F_190 ( V_101 , & V_27 -> V_102 ) ) {
V_85 = F_191 ( V_27 ) ;
if ( V_85 )
return V_85 ;
}
* V_49 |= V_50 ;
break;
case V_175 :
if ( ! ( * V_49 & V_50 ) )
return 0 ;
if ( V_35 -> V_51 ) {
V_85 = F_74 ( V_35 , V_83 , V_84 ) ;
if ( V_85 )
return V_85 ;
}
* V_49 &= ~ V_50 ;
break;
}
return 0 ;
}
int F_191 ( struct V_29 * V_27 )
{
struct V_8 * V_8 ;
int V_176 ;
V_8 = F_23 () ;
if ( ! V_8 )
return - V_10 ;
V_176 = F_173 ( & V_96 . V_97 ) ;
F_86 ( & V_95 ) ;
F_27 ( V_27 , V_8 ) ;
if ( V_159 & V_177 )
F_192 ( & V_8 -> V_97 , & V_96 . V_97 ) ;
else
F_192 ( & V_8 -> V_97 , & V_78 . V_8 -> V_97 ) ;
F_88 ( & V_95 ) ;
F_193 ( V_101 , & V_27 -> V_102 ) ;
F_194 ( V_27 ) ;
if ( V_176 )
F_195 ( & V_165 ) ;
return 0 ;
}
void F_196 ( struct V_29 * V_27 )
{
struct V_8 * V_8 ;
int V_178 = 0 ;
F_86 ( & V_95 ) ;
V_8 = F_25 ( V_27 ) ;
if ( V_8 && V_78 . V_8 != V_8 ) {
if ( ! V_8 -> V_82 ) {
F_89 ( & V_8 -> V_32 ) ;
F_60 ( & V_8 -> V_97 ) ;
V_178 = 1 ;
} else {
F_197 ( & V_8 -> V_97 ,
& V_78 . V_8 -> V_97 ) ;
}
}
F_88 ( & V_95 ) ;
if ( V_178 ) {
F_24 ( V_8 ) ;
F_90 ( V_101 , & V_27 -> V_102 ) ;
F_91 ( V_27 ) ;
} else if ( V_8 ) {
F_198 ( & V_27 -> V_53 ) ;
F_199 ( & V_27 -> V_53 ) ;
}
}
struct V_37 * F_200 ( struct V_37 * V_37 ,
struct V_34 * V_35 , unsigned long V_52 )
{
struct V_51 * V_51 = F_201 ( V_37 ) ;
struct V_37 * V_179 ;
if ( F_35 ( V_37 ) ) {
if ( F_158 ( V_37 ) &&
! ( V_159 & V_177 ) )
return V_37 ;
} else if ( ! V_51 ) {
return V_37 ;
} else if ( V_51 -> V_57 == V_35 -> V_51 -> V_57 &&
V_37 -> V_180 == F_202 ( V_35 , V_52 ) ) {
return V_37 ;
}
if ( ! F_203 ( V_37 ) )
return V_37 ;
V_179 = F_204 ( V_181 , V_35 , V_52 ) ;
if ( V_179 ) {
F_205 ( V_179 , V_37 , V_52 , V_35 ) ;
F_141 ( V_179 ) ;
F_206 ( V_179 ) ;
F_207 ( V_179 ) ;
}
return V_179 ;
}
void F_208 ( struct V_37 * V_37 , struct V_182 * V_183 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_184 = 0 ;
F_209 ( ! F_35 ( V_37 ) , V_37 ) ;
F_209 ( ! F_210 ( V_37 ) , V_37 ) ;
V_5 = F_158 ( V_37 ) ;
if ( ! V_5 )
return;
V_72:
F_58 (rmap_item, &stable_node->hlist, hlist) {
struct V_51 * V_51 = V_2 -> V_51 ;
struct V_185 * V_186 ;
struct V_34 * V_35 ;
F_32 () ;
F_211 ( V_51 ) ;
F_212 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
F_32 () ;
V_35 = V_186 -> V_35 ;
if ( V_2 -> V_52 < V_35 -> V_48 ||
V_2 -> V_52 >= V_35 -> V_100 )
continue;
if ( ( V_2 -> V_27 == V_35 -> V_87 ) == V_184 )
continue;
if ( V_183 -> V_187 && V_183 -> V_187 ( V_35 , V_183 -> V_188 ) )
continue;
if ( ! V_183 -> V_189 ( V_37 , V_35 ,
V_2 -> V_52 , V_183 -> V_188 ) ) {
F_213 ( V_51 ) ;
return;
}
if ( V_183 -> V_190 && V_183 -> V_190 ( V_37 ) ) {
F_213 ( V_51 ) ;
return;
}
}
F_213 ( V_51 ) ;
}
if ( ! V_184 ++ )
goto V_72;
}
void F_214 ( struct V_37 * V_191 , struct V_37 * V_192 )
{
struct V_5 * V_5 ;
F_209 ( ! F_210 ( V_192 ) , V_192 ) ;
F_209 ( ! F_210 ( V_191 ) , V_191 ) ;
F_209 ( V_191 -> V_73 != V_192 -> V_73 , V_191 ) ;
V_5 = F_158 ( V_191 ) ;
if ( V_5 ) {
F_209 ( V_5 -> V_54 != F_109 ( V_192 ) , V_192 ) ;
V_5 -> V_54 = F_109 ( V_191 ) ;
F_215 () ;
F_79 ( V_192 , NULL ) ;
}
}
static void F_183 ( void )
{
while ( V_159 & V_193 ) {
F_184 ( & V_162 ) ;
F_216 ( & V_159 , F_217 ( V_193 ) ,
V_194 ) ;
F_182 ( & V_162 ) ;
}
}
static bool F_218 ( struct V_5 * V_5 ,
unsigned long V_195 ,
unsigned long V_196 )
{
if ( V_5 -> V_54 >= V_195 &&
V_5 -> V_54 < V_196 ) {
F_56 ( V_5 ) ;
return true ;
}
return false ;
}
static bool F_219 ( struct V_5 * V_5 ,
unsigned long V_195 ,
unsigned long V_196 ,
struct V_56 * V_57 )
{
struct V_5 * V_14 ;
struct V_91 * V_92 ;
if ( ! F_5 ( V_5 ) ) {
F_8 ( F_6 ( V_5 ) ) ;
return F_218 ( V_5 , V_195 ,
V_196 ) ;
}
F_81 (dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
F_8 ( ! F_6 ( V_14 ) ) ;
F_218 ( V_14 , V_195 , V_196 ) ;
}
if ( F_72 ( & V_5 -> V_18 ) ) {
F_55 ( V_5 , V_57 ) ;
return true ;
} else
return false ;
}
static void F_220 ( unsigned long V_195 ,
unsigned long V_196 )
{
struct V_5 * V_5 , * V_62 ;
struct V_94 * V_20 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_93 ; V_22 ++ ) {
V_20 = F_221 ( V_21 + V_22 ) ;
while ( V_20 ) {
V_5 = F_83 ( V_20 , struct V_5 , V_20 ) ;
if ( F_219 ( V_5 ,
V_195 , V_196 ,
V_21 +
V_22 ) )
V_20 = F_221 ( V_21 + V_22 ) ;
else
V_20 = F_222 ( V_20 ) ;
F_32 () ;
}
}
F_84 (stable_node, next, &migrate_nodes, list) {
if ( V_5 -> V_54 >= V_195 &&
V_5 -> V_54 < V_196 )
F_56 ( V_5 ) ;
F_32 () ;
}
}
static int F_223 ( struct V_197 * V_198 ,
unsigned long V_199 , void * V_188 )
{
struct V_200 * V_201 = V_188 ;
switch ( V_199 ) {
case V_202 :
F_182 ( & V_162 ) ;
V_159 |= V_193 ;
F_184 ( & V_162 ) ;
break;
case V_203 :
F_220 ( V_201 -> V_195 ,
V_201 -> V_195 + V_201 -> V_204 ) ;
case V_205 :
F_182 ( & V_162 ) ;
V_159 &= ~ V_193 ;
F_184 ( & V_162 ) ;
F_224 () ;
F_225 ( & V_159 , F_217 ( V_193 ) ) ;
break;
}
return V_206 ;
}
static void F_183 ( void )
{
}
static T_7 F_226 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_2 , V_164 ) ;
}
static T_7 F_227 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
unsigned long V_213 ;
int V_85 ;
V_85 = F_228 ( V_211 , 10 , & V_213 ) ;
if ( V_85 || V_213 > V_214 )
return - V_215 ;
V_164 = V_213 ;
return V_212 ;
}
static T_7 F_229 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_2 , V_163 ) ;
}
static T_7 F_230 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
int V_85 ;
unsigned long V_204 ;
V_85 = F_228 ( V_211 , 10 , & V_204 ) ;
if ( V_85 || V_204 > V_214 )
return - V_215 ;
V_163 = V_204 ;
return V_212 ;
}
static T_7 F_231 ( struct V_207 * V_208 , struct V_209 * V_210 ,
char * V_211 )
{
return sprintf ( V_211 , L_3 , V_159 ) ;
}
static T_7 F_232 ( struct V_207 * V_208 , struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
int V_85 ;
unsigned long V_102 ;
V_85 = F_228 ( V_211 , 10 , & V_102 ) ;
if ( V_85 || V_102 > V_214 )
return - V_215 ;
if ( V_102 > V_177 )
return - V_215 ;
F_182 ( & V_162 ) ;
F_183 () ;
if ( V_159 != V_102 ) {
V_159 = V_102 ;
if ( V_102 & V_177 ) {
F_233 () ;
V_85 = F_85 () ;
F_234 () ;
if ( V_85 ) {
V_159 = V_216 ;
V_212 = V_85 ;
}
}
}
F_184 ( & V_162 ) ;
if ( V_102 & V_160 )
F_195 ( & V_165 ) ;
return V_212 ;
}
static T_7 F_235 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_2 , V_55 ) ;
}
static T_7 F_236 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
int V_85 ;
unsigned long V_217 ;
V_85 = F_228 ( V_211 , 10 , & V_217 ) ;
if ( V_85 )
return V_85 ;
if ( V_217 > 1 )
return - V_215 ;
F_182 ( & V_162 ) ;
F_183 () ;
if ( V_55 != V_217 ) {
if ( V_64 || F_82 () )
V_85 = - V_90 ;
else if ( V_21 == V_218 ) {
struct V_56 * V_211 ;
V_211 = F_237 ( V_219 + V_219 , sizeof( * V_211 ) ,
V_23 ) ;
if ( ! V_211 )
V_85 = - V_10 ;
else {
V_21 = V_211 ;
V_80 = V_211 + V_219 ;
V_80 [ 0 ] = V_220 [ 0 ] ;
}
}
if ( ! V_85 ) {
V_55 = V_217 ;
V_93 = V_217 ? 1 : V_219 ;
}
}
F_184 ( & V_162 ) ;
return V_85 ? V_85 : V_212 ;
}
static T_7 F_238 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_2 , V_153 ) ;
}
static T_7 F_239 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
int V_85 ;
bool V_221 ;
V_85 = F_240 ( V_211 , & V_221 ) ;
if ( V_85 )
return - V_215 ;
V_153 = V_221 ;
return V_212 ;
}
static T_7 F_241 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_2 , V_129 ) ;
}
static T_7 F_242 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
int V_85 ;
int V_217 ;
V_85 = F_243 ( V_211 , 10 , & V_217 ) ;
if ( V_85 )
return V_85 ;
if ( V_217 < 2 )
return - V_215 ;
if ( F_62 ( V_129 ) == V_217 )
return V_212 ;
F_182 ( & V_162 ) ;
F_183 () ;
if ( V_129 != V_217 ) {
if ( V_64 || F_82 () )
V_85 = - V_90 ;
else
V_129 = V_217 ;
}
F_184 ( & V_162 ) ;
return V_85 ? V_85 : V_212 ;
}
static T_7 F_244 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_64 ) ;
}
static T_7 F_245 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_63 ) ;
}
static T_7 F_246 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_81 ) ;
}
static T_7 F_247 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
long V_222 ;
V_222 = V_26 - V_64
- V_63 - V_81 ;
if ( V_222 < 0 )
V_222 = 0 ;
return sprintf ( V_211 , L_4 , V_222 ) ;
}
static T_7 F_248 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_19 ) ;
}
static T_7 F_249 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_61 ) ;
}
static T_7
F_250 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
char * V_211 )
{
return sprintf ( V_211 , L_2 , V_137 ) ;
}
static T_7
F_251 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
const char * V_211 , T_8 V_212 )
{
unsigned long V_213 ;
int V_85 ;
V_85 = F_228 ( V_211 , 10 , & V_213 ) ;
if ( V_85 || V_213 > V_214 )
return - V_215 ;
V_137 = V_213 ;
return V_212 ;
}
static T_7 F_252 ( struct V_207 * V_208 ,
struct V_209 * V_210 , char * V_211 )
{
return sprintf ( V_211 , L_3 , V_78 . V_79 ) ;
}
static int T_1 F_253 ( void )
{
struct V_223 * V_224 ;
int V_85 ;
V_154 = F_92 ( F_170 ( 0 ) ) ;
V_153 = false ;
V_85 = F_1 () ;
if ( V_85 )
goto V_3;
V_224 = F_254 ( F_178 , NULL , L_5 ) ;
if ( F_255 ( V_224 ) ) {
F_256 ( L_6 ) ;
V_85 = F_257 ( V_224 ) ;
goto V_225;
}
#ifdef F_258
V_85 = F_259 ( V_226 , & V_227 ) ;
if ( V_85 ) {
F_256 ( L_7 ) ;
F_260 ( V_224 ) ;
goto V_225;
}
#else
V_159 = V_160 ;
#endif
#ifdef F_261
F_262 ( F_223 , 100 ) ;
#endif
return 0 ;
V_225:
F_4 () ;
V_3:
return V_85 ;
}
