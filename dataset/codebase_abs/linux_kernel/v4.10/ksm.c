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
static inline struct V_2 * F_5 ( void )
{
struct V_2 * V_2 ;
V_2 = F_6 ( V_1 , V_11 |
V_12 | V_13 ) ;
if ( V_2 )
V_14 ++ ;
return V_2 ;
}
static inline void F_7 ( struct V_2 * V_2 )
{
V_14 -- ;
V_2 -> V_15 = NULL ;
F_8 ( V_1 , V_2 ) ;
}
static inline struct V_5 * F_9 ( void )
{
return F_10 ( V_4 , V_11 | V_16 ) ;
}
static inline void F_11 ( struct V_5 * V_5 )
{
F_8 ( V_4 , V_5 ) ;
}
static inline struct V_8 * F_12 ( void )
{
if ( ! V_7 )
return NULL ;
return F_6 ( V_7 , V_11 ) ;
}
static inline void F_13 ( struct V_8 * V_8 )
{
F_8 ( V_7 , V_8 ) ;
}
static struct V_8 * F_14 ( struct V_17 * V_15 )
{
struct V_8 * V_18 ;
F_15 (mm_slots_hash, slot, link, (unsigned long)mm)
if ( V_18 -> V_15 == V_15 )
return V_18 ;
return NULL ;
}
static void F_16 ( struct V_17 * V_15 ,
struct V_8 * V_8 )
{
V_8 -> V_15 = V_15 ;
F_17 ( V_19 , & V_8 -> V_20 , ( unsigned long ) V_15 ) ;
}
static inline bool F_18 ( struct V_17 * V_15 )
{
return F_19 ( & V_15 -> V_21 ) == 0 ;
}
static int F_20 ( struct V_22 * V_23 , unsigned long V_24 )
{
struct V_25 * V_25 ;
int V_26 = 0 ;
do {
F_21 () ;
V_25 = F_22 ( V_23 , V_24 ,
V_27 | V_28 | V_29 ) ;
if ( F_23 ( V_25 ) )
break;
if ( F_24 ( V_25 ) )
V_26 = F_25 ( V_23 , V_24 ,
V_30 | V_31 ) ;
else
V_26 = V_32 ;
F_26 ( V_25 ) ;
} while ( ! ( V_26 & ( V_32 | V_33 | V_34 | V_35 ) ) );
return ( V_26 & V_35 ) ? - V_10 : 0 ;
}
static struct V_22 * F_27 ( struct V_17 * V_15 ,
unsigned long V_24 )
{
struct V_22 * V_23 ;
if ( F_18 ( V_15 ) )
return NULL ;
V_23 = F_28 ( V_15 , V_24 ) ;
if ( ! V_23 || V_23 -> V_36 > V_24 )
return NULL ;
if ( ! ( V_23 -> V_37 & V_38 ) || ! V_23 -> V_39 )
return NULL ;
return V_23 ;
}
static void F_29 ( struct V_2 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_24 = V_2 -> V_40 ;
struct V_22 * V_23 ;
F_30 ( V_2 -> V_39 ) ;
F_31 ( & V_15 -> V_41 ) ;
V_23 = F_27 ( V_15 , V_24 ) ;
if ( V_23 )
F_20 ( V_23 , V_24 ) ;
F_32 ( & V_15 -> V_41 ) ;
}
static struct V_25 * F_33 ( struct V_2 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_24 = V_2 -> V_40 ;
struct V_22 * V_23 ;
struct V_25 * V_25 ;
F_31 ( & V_15 -> V_41 ) ;
V_23 = F_27 ( V_15 , V_24 ) ;
if ( ! V_23 )
goto V_3;
V_25 = F_22 ( V_23 , V_24 , V_27 ) ;
if ( F_23 ( V_25 ) )
goto V_3;
if ( F_34 ( V_25 ) ) {
F_35 ( V_23 , V_25 , V_24 ) ;
F_36 ( V_25 ) ;
} else {
F_26 ( V_25 ) ;
V_3:
V_25 = NULL ;
}
F_32 ( & V_15 -> V_41 ) ;
return V_25 ;
}
static inline int F_37 ( unsigned long V_42 )
{
return V_43 ? 0 : F_38 ( F_39 ( V_42 ) ) ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_41 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_44 . V_45 )
V_46 -- ;
else
V_47 -- ;
F_30 ( V_2 -> V_39 ) ;
V_2 -> V_40 &= V_48 ;
F_21 () ;
}
if ( V_5 -> V_49 == & V_50 )
F_42 ( & V_5 -> V_51 ) ;
else
F_43 ( & V_5 -> V_52 ,
V_53 + F_38 ( V_5 -> V_54 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_25 * F_44 ( struct V_5 * V_5 , bool V_55 )
{
struct V_25 * V_25 ;
void * V_56 ;
unsigned long V_42 ;
V_56 = ( void * ) ( ( unsigned long ) V_5 |
V_57 ) ;
V_58:
V_42 = F_45 ( V_5 -> V_42 ) ;
V_25 = F_46 ( V_42 ) ;
F_47 () ;
if ( F_45 ( V_25 -> V_59 ) != V_56 )
goto V_60;
while ( ! F_48 ( V_25 ) ) {
if ( ! F_49 ( V_25 ) )
goto V_60;
F_50 () ;
}
if ( F_45 ( V_25 -> V_59 ) != V_56 ) {
F_26 ( V_25 ) ;
goto V_60;
}
if ( V_55 ) {
F_51 ( V_25 ) ;
if ( F_45 ( V_25 -> V_59 ) != V_56 ) {
F_52 ( V_25 ) ;
F_26 ( V_25 ) ;
goto V_60;
}
}
return V_25 ;
V_60:
F_53 () ;
if ( F_45 ( V_5 -> V_42 ) != V_42 )
goto V_58;
F_40 ( V_5 ) ;
return NULL ;
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_40 & V_61 ) {
struct V_5 * V_5 ;
struct V_25 * V_25 ;
V_5 = V_2 -> V_49 ;
V_25 = F_44 ( V_5 , true ) ;
if ( ! V_25 )
goto V_3;
F_55 ( & V_2 -> V_44 ) ;
F_52 ( V_25 ) ;
F_26 ( V_25 ) ;
if ( ! F_56 ( & V_5 -> V_44 ) )
V_46 -- ;
else
V_47 -- ;
F_30 ( V_2 -> V_39 ) ;
V_2 -> V_40 &= V_48 ;
} else if ( V_2 -> V_40 & V_62 ) {
unsigned char V_63 ;
V_63 = ( unsigned char ) ( V_64 . V_65 - V_2 -> V_40 ) ;
F_57 ( V_63 > 1 ) ;
if ( ! V_63 )
F_43 ( & V_2 -> V_52 ,
V_66 + F_38 ( V_2 -> V_54 ) ) ;
V_67 -- ;
V_2 -> V_40 &= V_48 ;
}
V_3:
F_21 () ;
}
static void F_58 ( struct V_8 * V_8 ,
struct V_2 * * V_68 )
{
while ( * V_68 ) {
struct V_2 * V_2 = * V_68 ;
* V_68 = V_2 -> V_68 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_59 ( struct V_22 * V_23 ,
unsigned long V_69 , unsigned long V_70 )
{
unsigned long V_24 ;
int V_71 = 0 ;
for ( V_24 = V_69 ; V_24 < V_70 && ! V_71 ; V_24 += V_72 ) {
if ( F_18 ( V_23 -> V_73 ) )
break;
if ( F_60 ( V_74 ) )
V_71 = - V_75 ;
else
V_71 = F_20 ( V_23 , V_24 ) ;
}
return V_71 ;
}
static int F_61 ( struct V_5 * V_5 )
{
struct V_25 * V_25 ;
int V_71 ;
V_25 = F_44 ( V_5 , true ) ;
if ( ! V_25 ) {
return 0 ;
}
if ( F_62 ( F_63 ( V_25 ) ) ) {
V_71 = - V_76 ;
} else {
F_64 ( V_25 , NULL ) ;
F_40 ( V_5 ) ;
V_71 = 0 ;
}
F_52 ( V_25 ) ;
F_26 ( V_25 ) ;
return V_71 ;
}
static int F_65 ( void )
{
struct V_5 * V_5 , * V_45 ;
int V_54 ;
int V_71 = 0 ;
for ( V_54 = 0 ; V_54 < V_77 ; V_54 ++ ) {
while ( V_53 [ V_54 ] . V_78 ) {
V_5 = F_66 ( V_53 [ V_54 ] . V_78 ,
struct V_5 , V_52 ) ;
if ( F_61 ( V_5 ) ) {
V_71 = - V_76 ;
break;
}
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( F_61 ( V_5 ) )
V_71 = - V_76 ;
F_21 () ;
}
return V_71 ;
}
static int F_68 ( void )
{
struct V_8 * V_8 ;
struct V_17 * V_15 ;
struct V_22 * V_23 ;
int V_71 = 0 ;
F_69 ( & V_79 ) ;
V_64 . V_8 = F_70 ( V_80 . V_81 . V_45 ,
struct V_8 , V_81 ) ;
F_71 ( & V_79 ) ;
for ( V_8 = V_64 . V_8 ;
V_8 != & V_80 ; V_8 = V_64 . V_8 ) {
V_15 = V_8 -> V_15 ;
F_31 ( & V_15 -> V_41 ) ;
for ( V_23 = V_15 -> V_82 ; V_23 ; V_23 = V_23 -> V_83 ) {
if ( F_18 ( V_15 ) )
break;
if ( ! ( V_23 -> V_37 & V_38 ) || ! V_23 -> V_39 )
continue;
V_71 = F_59 ( V_23 ,
V_23 -> V_36 , V_23 -> V_84 ) ;
if ( V_71 )
goto error;
}
F_58 ( V_8 , & V_8 -> V_68 ) ;
F_32 ( & V_15 -> V_41 ) ;
F_69 ( & V_79 ) ;
V_64 . V_8 = F_70 ( V_8 -> V_81 . V_45 ,
struct V_8 , V_81 ) ;
if ( F_18 ( V_15 ) ) {
F_72 ( & V_8 -> V_20 ) ;
F_42 ( & V_8 -> V_81 ) ;
F_71 ( & V_79 ) ;
F_13 ( V_8 ) ;
F_73 ( V_85 , & V_15 -> V_86 ) ;
F_74 ( V_15 ) ;
} else
F_71 ( & V_79 ) ;
}
F_65 () ;
V_64 . V_65 = 0 ;
return 0 ;
error:
F_32 ( & V_15 -> V_41 ) ;
F_69 ( & V_79 ) ;
V_64 . V_8 = & V_80 ;
F_71 ( & V_79 ) ;
return V_71 ;
}
static T_2 F_75 ( struct V_25 * V_25 )
{
T_2 V_87 ;
void * V_24 = F_76 ( V_25 ) ;
V_87 = F_77 ( V_24 , V_72 / 4 , 17 ) ;
F_78 ( V_24 ) ;
return V_87 ;
}
static int F_79 ( struct V_25 * V_88 , struct V_25 * V_89 )
{
char * V_90 , * V_91 ;
int V_26 ;
V_90 = F_76 ( V_88 ) ;
V_91 = F_76 ( V_89 ) ;
V_26 = memcmp ( V_90 , V_91 , V_72 ) ;
F_78 ( V_91 ) ;
F_78 ( V_90 ) ;
return V_26 ;
}
static inline int F_80 ( struct V_25 * V_88 , struct V_25 * V_89 )
{
return ! F_79 ( V_88 , V_89 ) ;
}
static int F_81 ( struct V_22 * V_23 , struct V_25 * V_25 ,
T_3 * V_92 )
{
struct V_17 * V_15 = V_23 -> V_73 ;
unsigned long V_24 ;
T_3 * V_93 ;
T_4 * V_94 ;
int V_95 ;
int V_71 = - V_96 ;
unsigned long V_97 ;
unsigned long V_98 ;
V_24 = F_82 ( V_25 , V_23 ) ;
if ( V_24 == - V_96 )
goto V_3;
F_57 ( F_83 ( V_25 ) ) ;
V_97 = V_24 ;
V_98 = V_24 + V_72 ;
F_84 ( V_15 , V_97 , V_98 ) ;
V_93 = F_85 ( V_25 , V_15 , V_24 , & V_94 , 0 ) ;
if ( ! V_93 )
goto V_99;
if ( F_86 ( * V_93 ) || F_87 ( * V_93 ) ) {
T_3 V_100 ;
V_95 = F_49 ( V_25 ) ;
F_88 ( V_23 , V_24 , F_89 ( V_25 ) ) ;
V_100 = F_90 ( V_23 , V_24 , V_93 ) ;
if ( F_91 ( V_25 ) + 1 + V_95 != F_92 ( V_25 ) ) {
F_93 ( V_15 , V_24 , V_93 , V_100 ) ;
goto V_101;
}
if ( F_87 ( V_100 ) )
F_94 ( V_25 ) ;
V_100 = F_95 ( F_96 ( V_100 ) ) ;
F_97 ( V_15 , V_24 , V_93 , V_100 ) ;
}
* V_92 = * V_93 ;
V_71 = 0 ;
V_101:
F_98 ( V_93 , V_94 ) ;
V_99:
F_99 ( V_15 , V_97 , V_98 ) ;
V_3:
return V_71 ;
}
static int F_100 ( struct V_22 * V_23 , struct V_25 * V_25 ,
struct V_25 * V_102 , T_3 V_92 )
{
struct V_17 * V_15 = V_23 -> V_73 ;
T_5 * V_103 ;
T_3 * V_93 ;
T_4 * V_94 ;
unsigned long V_24 ;
int V_71 = - V_96 ;
unsigned long V_97 ;
unsigned long V_98 ;
V_24 = F_82 ( V_25 , V_23 ) ;
if ( V_24 == - V_96 )
goto V_3;
V_103 = F_101 ( V_15 , V_24 ) ;
if ( ! V_103 )
goto V_3;
V_97 = V_24 ;
V_98 = V_24 + V_72 ;
F_84 ( V_15 , V_97 , V_98 ) ;
V_93 = F_102 ( V_15 , V_103 , V_24 , & V_94 ) ;
if ( ! F_103 ( * V_93 , V_92 ) ) {
F_98 ( V_93 , V_94 ) ;
goto V_99;
}
F_104 ( V_102 ) ;
F_105 ( V_102 , V_23 , V_24 , false ) ;
F_88 ( V_23 , V_24 , F_106 ( * V_93 ) ) ;
F_90 ( V_23 , V_24 , V_93 ) ;
F_97 ( V_15 , V_24 , V_93 , F_107 ( V_102 , V_23 -> V_104 ) ) ;
F_108 ( V_25 , false ) ;
if ( ! F_63 ( V_25 ) )
F_109 ( V_25 ) ;
F_26 ( V_25 ) ;
F_98 ( V_93 , V_94 ) ;
V_71 = 0 ;
V_99:
F_99 ( V_15 , V_97 , V_98 ) ;
V_3:
return V_71 ;
}
static int F_110 ( struct V_22 * V_23 ,
struct V_25 * V_25 , struct V_25 * V_102 )
{
T_3 V_92 = F_111 ( 0 ) ;
int V_71 = - V_96 ;
if ( V_25 == V_102 )
return 0 ;
if ( ! F_34 ( V_25 ) )
goto V_3;
if ( ! F_112 ( V_25 ) )
goto V_3;
if ( F_83 ( V_25 ) ) {
V_71 = F_113 ( V_25 ) ;
if ( V_71 )
goto V_101;
}
if ( F_81 ( V_23 , V_25 , & V_92 ) == 0 ) {
if ( ! V_102 ) {
F_64 ( V_25 , NULL ) ;
F_114 ( V_25 ) ;
if ( ! F_115 ( V_25 ) )
F_116 ( V_25 ) ;
V_71 = 0 ;
} else if ( F_80 ( V_25 , V_102 ) )
V_71 = F_100 ( V_23 , V_25 , V_102 , V_92 ) ;
}
if ( ( V_23 -> V_37 & V_105 ) && V_102 && ! V_71 ) {
F_117 ( V_25 ) ;
if ( ! F_118 ( V_102 ) ) {
F_52 ( V_25 ) ;
F_51 ( V_102 ) ;
F_119 ( V_102 ) ;
V_25 = V_102 ;
}
}
V_101:
F_52 ( V_25 ) ;
V_3:
return V_71 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_25 * V_25 , struct V_25 * V_102 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_22 * V_23 ;
int V_71 = - V_96 ;
F_31 ( & V_15 -> V_41 ) ;
V_23 = F_27 ( V_15 , V_2 -> V_40 ) ;
if ( ! V_23 )
goto V_3;
V_71 = F_110 ( V_23 , V_25 , V_102 ) ;
if ( V_71 )
goto V_3;
F_54 ( V_2 ) ;
V_2 -> V_39 = V_23 -> V_39 ;
F_121 ( V_23 -> V_39 ) ;
V_3:
F_32 ( & V_15 -> V_41 ) ;
return V_71 ;
}
static struct V_25 * F_122 ( struct V_2 * V_2 ,
struct V_25 * V_25 ,
struct V_2 * V_106 ,
struct V_25 * V_107 )
{
int V_71 ;
V_71 = F_120 ( V_2 , V_25 , NULL ) ;
if ( ! V_71 ) {
V_71 = F_120 ( V_106 ,
V_107 , V_25 ) ;
if ( V_71 )
F_29 ( V_2 ) ;
}
return V_71 ? NULL : V_25 ;
}
static struct V_25 * F_123 ( struct V_25 * V_25 )
{
int V_54 ;
struct V_108 * V_109 ;
struct V_78 * * V_110 ;
struct V_78 * V_111 ;
struct V_5 * V_5 ;
struct V_5 * V_112 ;
V_112 = F_124 ( V_25 ) ;
if ( V_112 && V_112 -> V_49 != & V_50 ) {
F_104 ( V_25 ) ;
return V_25 ;
}
V_54 = F_37 ( F_89 ( V_25 ) ) ;
V_109 = V_53 + V_54 ;
V_58:
V_110 = & V_109 -> V_78 ;
V_111 = NULL ;
while ( * V_110 ) {
struct V_25 * V_107 ;
int V_26 ;
F_21 () ;
V_5 = F_66 ( * V_110 , struct V_5 , V_52 ) ;
V_107 = F_44 ( V_5 , false ) ;
if ( ! V_107 ) {
goto V_58;
}
V_26 = F_79 ( V_25 , V_107 ) ;
F_26 ( V_107 ) ;
V_111 = * V_110 ;
if ( V_26 < 0 )
V_110 = & V_111 -> V_113 ;
else if ( V_26 > 0 )
V_110 = & V_111 -> V_114 ;
else {
V_107 = F_44 ( V_5 , true ) ;
if ( V_107 ) {
F_52 ( V_107 ) ;
if ( F_37 ( V_5 -> V_42 ) !=
F_38 ( V_5 -> V_54 ) ) {
F_26 ( V_107 ) ;
goto V_115;
}
return V_107 ;
}
if ( V_112 )
goto V_58;
return NULL ;
}
}
if ( ! V_112 )
return NULL ;
F_42 ( & V_112 -> V_51 ) ;
F_125 ( V_112 -> V_54 = V_54 ) ;
F_126 ( & V_112 -> V_52 , V_111 , V_110 ) ;
F_127 ( & V_112 -> V_52 , V_109 ) ;
F_104 ( V_25 ) ;
return V_25 ;
V_115:
if ( V_112 ) {
F_42 ( & V_112 -> V_51 ) ;
F_125 ( V_112 -> V_54 = V_54 ) ;
F_128 ( & V_5 -> V_52 , & V_112 -> V_52 , V_109 ) ;
F_104 ( V_25 ) ;
} else {
F_43 ( & V_5 -> V_52 , V_109 ) ;
V_25 = NULL ;
}
V_5 -> V_49 = & V_50 ;
F_129 ( & V_5 -> V_51 , V_5 -> V_49 ) ;
return V_25 ;
}
static struct V_5 * F_130 ( struct V_25 * V_102 )
{
int V_54 ;
unsigned long V_42 ;
struct V_108 * V_109 ;
struct V_78 * * V_110 ;
struct V_78 * V_111 ;
struct V_5 * V_5 ;
V_42 = F_89 ( V_102 ) ;
V_54 = F_37 ( V_42 ) ;
V_109 = V_53 + V_54 ;
V_58:
V_111 = NULL ;
V_110 = & V_109 -> V_78 ;
while ( * V_110 ) {
struct V_25 * V_107 ;
int V_26 ;
F_21 () ;
V_5 = F_66 ( * V_110 , struct V_5 , V_52 ) ;
V_107 = F_44 ( V_5 , false ) ;
if ( ! V_107 ) {
goto V_58;
}
V_26 = F_79 ( V_102 , V_107 ) ;
F_26 ( V_107 ) ;
V_111 = * V_110 ;
if ( V_26 < 0 )
V_110 = & V_111 -> V_113 ;
else if ( V_26 > 0 )
V_110 = & V_111 -> V_114 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_44 ) ;
V_5 -> V_42 = V_42 ;
F_64 ( V_102 , V_5 ) ;
F_125 ( V_5 -> V_54 = V_54 ) ;
F_126 ( & V_5 -> V_52 , V_111 , V_110 ) ;
F_127 ( & V_5 -> V_52 , V_109 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_25 * V_25 ,
struct V_25 * * V_116 )
{
struct V_78 * * V_110 ;
struct V_108 * V_109 ;
struct V_78 * V_111 = NULL ;
int V_54 ;
V_54 = F_37 ( F_89 ( V_25 ) ) ;
V_109 = V_66 + V_54 ;
V_110 = & V_109 -> V_78 ;
while ( * V_110 ) {
struct V_2 * V_106 ;
struct V_25 * V_107 ;
int V_26 ;
F_21 () ;
V_106 = F_66 ( * V_110 , struct V_2 , V_52 ) ;
V_107 = F_33 ( V_106 ) ;
if ( ! V_107 )
return NULL ;
if ( V_25 == V_107 ) {
F_26 ( V_107 ) ;
return NULL ;
}
V_26 = F_79 ( V_25 , V_107 ) ;
V_111 = * V_110 ;
if ( V_26 < 0 ) {
F_26 ( V_107 ) ;
V_110 = & V_111 -> V_113 ;
} else if ( V_26 > 0 ) {
F_26 ( V_107 ) ;
V_110 = & V_111 -> V_114 ;
} else if ( ! V_43 &&
F_133 ( V_107 ) != V_54 ) {
F_26 ( V_107 ) ;
return NULL ;
} else {
* V_116 = V_107 ;
return V_106 ;
}
}
V_2 -> V_40 |= V_62 ;
V_2 -> V_40 |= ( V_64 . V_65 & V_117 ) ;
F_125 ( V_2 -> V_54 = V_54 ) ;
F_126 ( & V_2 -> V_52 , V_111 , V_110 ) ;
F_127 ( & V_2 -> V_52 , V_109 ) ;
V_67 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_49 = V_5 ;
V_2 -> V_40 |= V_61 ;
F_135 ( & V_2 -> V_44 , & V_5 -> V_44 ) ;
if ( V_2 -> V_44 . V_45 )
V_46 ++ ;
else
V_47 ++ ;
}
static void F_136 ( struct V_25 * V_25 , struct V_2 * V_2 )
{
struct V_2 * V_106 ;
struct V_25 * V_107 = NULL ;
struct V_5 * V_5 ;
struct V_25 * V_102 ;
unsigned int V_87 ;
int V_71 ;
V_5 = F_124 ( V_25 ) ;
if ( V_5 ) {
if ( V_5 -> V_49 != & V_50 &&
F_37 ( V_5 -> V_42 ) != F_38 ( V_5 -> V_54 ) ) {
F_43 ( & V_5 -> V_52 ,
V_53 + F_38 ( V_5 -> V_54 ) ) ;
V_5 -> V_49 = & V_50 ;
F_129 ( & V_5 -> V_51 , V_5 -> V_49 ) ;
}
if ( V_5 -> V_49 != & V_50 &&
V_2 -> V_49 == V_5 )
return;
}
V_102 = F_123 ( V_25 ) ;
if ( V_102 == V_25 && V_2 -> V_49 == V_5 ) {
F_26 ( V_102 ) ;
return;
}
F_54 ( V_2 ) ;
if ( V_102 ) {
V_71 = F_120 ( V_2 , V_25 , V_102 ) ;
if ( ! V_71 ) {
F_51 ( V_102 ) ;
F_134 ( V_2 , F_124 ( V_102 ) ) ;
F_52 ( V_102 ) ;
}
F_26 ( V_102 ) ;
return;
}
V_87 = F_75 ( V_25 ) ;
if ( V_2 -> V_118 != V_87 ) {
V_2 -> V_118 = V_87 ;
return;
}
V_106 =
F_132 ( V_2 , V_25 , & V_107 ) ;
if ( V_106 ) {
V_102 = F_122 ( V_2 , V_25 ,
V_106 , V_107 ) ;
F_26 ( V_107 ) ;
if ( V_102 ) {
F_51 ( V_102 ) ;
V_5 = F_130 ( V_102 ) ;
if ( V_5 ) {
F_134 ( V_106 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_52 ( V_102 ) ;
if ( ! V_5 ) {
F_29 ( V_106 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_137 ( struct V_8 * V_8 ,
struct V_2 * * V_68 ,
unsigned long V_24 )
{
struct V_2 * V_2 ;
while ( * V_68 ) {
V_2 = * V_68 ;
if ( ( V_2 -> V_40 & V_48 ) == V_24 )
return V_2 ;
if ( V_2 -> V_40 > V_24 )
break;
* V_68 = V_2 -> V_68 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_15 = V_8 -> V_15 ;
V_2 -> V_40 = V_24 ;
V_2 -> V_68 = * V_68 ;
* V_68 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_138 ( struct V_25 * * V_25 )
{
struct V_17 * V_15 ;
struct V_8 * V_18 ;
struct V_22 * V_23 ;
struct V_2 * V_2 ;
int V_54 ;
if ( F_139 ( & V_80 . V_81 ) )
return NULL ;
V_18 = V_64 . V_8 ;
if ( V_18 == & V_80 ) {
F_140 () ;
if ( ! V_43 ) {
struct V_5 * V_5 , * V_45 ;
struct V_25 * V_25 ;
F_67 (stable_node, next,
&migrate_nodes, list) {
V_25 = F_44 ( V_5 , false ) ;
if ( V_25 )
F_26 ( V_25 ) ;
F_21 () ;
}
}
for ( V_54 = 0 ; V_54 < V_77 ; V_54 ++ )
V_66 [ V_54 ] = V_119 ;
F_69 ( & V_79 ) ;
V_18 = F_70 ( V_18 -> V_81 . V_45 , struct V_8 , V_81 ) ;
V_64 . V_8 = V_18 ;
F_71 ( & V_79 ) ;
if ( V_18 == & V_80 )
return NULL ;
V_120:
V_64 . V_40 = 0 ;
V_64 . V_68 = & V_18 -> V_68 ;
}
V_15 = V_18 -> V_15 ;
F_31 ( & V_15 -> V_41 ) ;
if ( F_18 ( V_15 ) )
V_23 = NULL ;
else
V_23 = F_28 ( V_15 , V_64 . V_40 ) ;
for (; V_23 ; V_23 = V_23 -> V_83 ) {
if ( ! ( V_23 -> V_37 & V_38 ) )
continue;
if ( V_64 . V_40 < V_23 -> V_36 )
V_64 . V_40 = V_23 -> V_36 ;
if ( ! V_23 -> V_39 )
V_64 . V_40 = V_23 -> V_84 ;
while ( V_64 . V_40 < V_23 -> V_84 ) {
if ( F_18 ( V_15 ) )
break;
* V_25 = F_22 ( V_23 , V_64 . V_40 , V_27 ) ;
if ( F_23 ( * V_25 ) ) {
V_64 . V_40 += V_72 ;
F_21 () ;
continue;
}
if ( F_34 ( * V_25 ) ) {
F_35 ( V_23 , * V_25 , V_64 . V_40 ) ;
F_36 ( * V_25 ) ;
V_2 = F_137 ( V_18 ,
V_64 . V_68 , V_64 . V_40 ) ;
if ( V_2 ) {
V_64 . V_68 =
& V_2 -> V_68 ;
V_64 . V_40 += V_72 ;
} else
F_26 ( * V_25 ) ;
F_32 ( & V_15 -> V_41 ) ;
return V_2 ;
}
F_26 ( * V_25 ) ;
V_64 . V_40 += V_72 ;
F_21 () ;
}
}
if ( F_18 ( V_15 ) ) {
V_64 . V_40 = 0 ;
V_64 . V_68 = & V_18 -> V_68 ;
}
F_58 ( V_18 , V_64 . V_68 ) ;
F_69 ( & V_79 ) ;
V_64 . V_8 = F_70 ( V_18 -> V_81 . V_45 ,
struct V_8 , V_81 ) ;
if ( V_64 . V_40 == 0 ) {
F_72 ( & V_18 -> V_20 ) ;
F_42 ( & V_18 -> V_81 ) ;
F_71 ( & V_79 ) ;
F_13 ( V_18 ) ;
F_73 ( V_85 , & V_15 -> V_86 ) ;
F_32 ( & V_15 -> V_41 ) ;
F_74 ( V_15 ) ;
} else {
F_32 ( & V_15 -> V_41 ) ;
F_71 ( & V_79 ) ;
}
V_18 = V_64 . V_8 ;
if ( V_18 != & V_80 )
goto V_120;
V_64 . V_65 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_121 )
{
struct V_2 * V_2 ;
struct V_25 * V_122 ( V_25 ) ;
while ( V_121 -- && F_142 ( ! F_143 ( V_74 ) ) ) {
F_21 () ;
V_2 = F_138 ( & V_25 ) ;
if ( ! V_2 )
return;
F_136 ( V_25 , V_2 ) ;
F_26 ( V_25 ) ;
}
}
static int F_144 ( void )
{
return ( V_123 & V_124 ) && ! F_139 ( & V_80 . V_81 ) ;
}
static int F_145 ( void * V_125 )
{
F_146 () ;
F_147 ( V_74 , 5 ) ;
while ( ! F_148 () ) {
F_149 ( & V_126 ) ;
F_150 () ;
if ( F_144 () )
F_141 ( V_127 ) ;
F_151 ( & V_126 ) ;
F_152 () ;
if ( F_144 () ) {
F_153 (
F_154 ( V_128 ) ) ;
} else {
F_155 ( V_129 ,
F_144 () || F_148 () ) ;
}
}
return 0 ;
}
int F_156 ( struct V_22 * V_23 , unsigned long V_69 ,
unsigned long V_70 , int V_130 , unsigned long * V_37 )
{
struct V_17 * V_15 = V_23 -> V_73 ;
int V_71 ;
switch ( V_130 ) {
case V_131 :
if ( * V_37 & ( V_38 | V_132 | V_133 |
V_134 | V_135 | V_136 |
V_137 | V_138 ) )
return 0 ;
#ifdef F_157
if ( * V_37 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_85 , & V_15 -> V_86 ) ) {
V_71 = F_159 ( V_15 ) ;
if ( V_71 )
return V_71 ;
}
* V_37 |= V_38 ;
break;
case V_139 :
if ( ! ( * V_37 & V_38 ) )
return 0 ;
if ( V_23 -> V_39 ) {
V_71 = F_59 ( V_23 , V_69 , V_70 ) ;
if ( V_71 )
return V_71 ;
}
* V_37 &= ~ V_38 ;
break;
}
return 0 ;
}
int F_159 ( struct V_17 * V_15 )
{
struct V_8 * V_8 ;
int V_140 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_140 = F_139 ( & V_80 . V_81 ) ;
F_69 ( & V_79 ) ;
F_16 ( V_15 , V_8 ) ;
if ( V_123 & V_141 )
F_160 ( & V_8 -> V_81 , & V_80 . V_81 ) ;
else
F_160 ( & V_8 -> V_81 , & V_64 . V_8 -> V_81 ) ;
F_71 ( & V_79 ) ;
F_161 ( V_85 , & V_15 -> V_86 ) ;
F_162 ( & V_15 -> V_142 ) ;
if ( V_140 )
F_163 ( & V_129 ) ;
return 0 ;
}
void F_164 ( struct V_17 * V_15 )
{
struct V_8 * V_8 ;
int V_143 = 0 ;
F_69 ( & V_79 ) ;
V_8 = F_14 ( V_15 ) ;
if ( V_8 && V_64 . V_8 != V_8 ) {
if ( ! V_8 -> V_68 ) {
F_72 ( & V_8 -> V_20 ) ;
F_42 ( & V_8 -> V_81 ) ;
V_143 = 1 ;
} else {
F_165 ( & V_8 -> V_81 ,
& V_64 . V_8 -> V_81 ) ;
}
}
F_71 ( & V_79 ) ;
if ( V_143 ) {
F_13 ( V_8 ) ;
F_73 ( V_85 , & V_15 -> V_86 ) ;
F_74 ( V_15 ) ;
} else if ( V_8 ) {
F_166 ( & V_15 -> V_41 ) ;
F_167 ( & V_15 -> V_41 ) ;
}
}
struct V_25 * F_168 ( struct V_25 * V_25 ,
struct V_22 * V_23 , unsigned long V_40 )
{
struct V_39 * V_39 = F_169 ( V_25 ) ;
struct V_25 * V_144 ;
if ( F_24 ( V_25 ) ) {
if ( F_124 ( V_25 ) &&
! ( V_123 & V_141 ) )
return V_25 ;
} else if ( ! V_39 ) {
return V_25 ;
} else if ( V_39 -> V_109 == V_23 -> V_39 -> V_109 &&
V_25 -> V_145 == F_170 ( V_23 , V_40 ) ) {
return V_25 ;
}
if ( ! F_171 ( V_25 ) )
return V_25 ;
V_144 = F_172 ( V_146 , V_23 , V_40 ) ;
if ( V_144 ) {
F_173 ( V_144 , V_25 , V_40 , V_23 ) ;
F_116 ( V_144 ) ;
F_174 ( V_144 ) ;
F_175 ( V_144 ) ;
}
return V_144 ;
}
int F_176 ( struct V_25 * V_25 , struct V_147 * V_148 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_26 = V_149 ;
int V_150 = 0 ;
F_177 ( ! F_24 ( V_25 ) , V_25 ) ;
F_177 ( ! F_178 ( V_25 ) , V_25 ) ;
V_5 = F_124 ( V_25 ) ;
if ( ! V_5 )
return V_26 ;
V_58:
F_41 (rmap_item, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_151 * V_152 ;
struct V_22 * V_23 ;
F_21 () ;
F_179 ( V_39 ) ;
F_180 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
F_21 () ;
V_23 = V_152 -> V_23 ;
if ( V_2 -> V_40 < V_23 -> V_36 ||
V_2 -> V_40 >= V_23 -> V_84 )
continue;
if ( ( V_2 -> V_15 == V_23 -> V_73 ) == V_150 )
continue;
if ( V_148 -> V_153 && V_148 -> V_153 ( V_23 , V_148 -> V_154 ) )
continue;
V_26 = V_148 -> V_155 ( V_25 , V_23 ,
V_2 -> V_40 , V_148 -> V_154 ) ;
if ( V_26 != V_149 ) {
F_181 ( V_39 ) ;
goto V_3;
}
if ( V_148 -> V_156 && V_148 -> V_156 ( V_25 ) ) {
F_181 ( V_39 ) ;
goto V_3;
}
}
F_181 ( V_39 ) ;
}
if ( ! V_150 ++ )
goto V_58;
V_3:
return V_26 ;
}
void F_182 ( struct V_25 * V_157 , struct V_25 * V_158 )
{
struct V_5 * V_5 ;
F_177 ( ! F_178 ( V_158 ) , V_158 ) ;
F_177 ( ! F_178 ( V_157 ) , V_157 ) ;
F_177 ( V_157 -> V_59 != V_158 -> V_59 , V_157 ) ;
V_5 = F_124 ( V_157 ) ;
if ( V_5 ) {
F_177 ( V_5 -> V_42 != F_89 ( V_158 ) , V_158 ) ;
V_5 -> V_42 = F_89 ( V_157 ) ;
F_183 () ;
F_64 ( V_158 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_123 & V_159 ) {
F_151 ( & V_126 ) ;
F_184 ( & V_123 , F_185 ( V_159 ) ,
V_160 ) ;
F_149 ( & V_126 ) ;
}
}
static void F_186 ( unsigned long V_161 ,
unsigned long V_162 )
{
struct V_5 * V_5 , * V_45 ;
struct V_78 * V_52 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_77 ; V_54 ++ ) {
V_52 = F_187 ( V_53 + V_54 ) ;
while ( V_52 ) {
V_5 = F_66 ( V_52 , struct V_5 , V_52 ) ;
if ( V_5 -> V_42 >= V_161 &&
V_5 -> V_42 < V_162 ) {
F_40 ( V_5 ) ;
V_52 = F_187 ( V_53 + V_54 ) ;
} else
V_52 = F_188 ( V_52 ) ;
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( V_5 -> V_42 >= V_161 &&
V_5 -> V_42 < V_162 )
F_40 ( V_5 ) ;
F_21 () ;
}
}
static int F_189 ( struct V_163 * V_164 ,
unsigned long V_165 , void * V_154 )
{
struct V_166 * V_167 = V_154 ;
switch ( V_165 ) {
case V_168 :
F_149 ( & V_126 ) ;
V_123 |= V_159 ;
F_151 ( & V_126 ) ;
break;
case V_169 :
F_186 ( V_167 -> V_161 ,
V_167 -> V_161 + V_167 -> V_170 ) ;
case V_171 :
F_149 ( & V_126 ) ;
V_123 &= ~ V_159 ;
F_151 ( & V_126 ) ;
F_190 () ;
F_191 ( & V_123 , F_185 ( V_159 ) ) ;
break;
}
return V_172 ;
}
static void F_150 ( void )
{
}
static T_6 F_192 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_128 ) ;
}
static T_6 F_193 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
unsigned long V_179 ;
int V_71 ;
V_71 = F_194 ( V_177 , 10 , & V_179 ) ;
if ( V_71 || V_179 > V_180 )
return - V_181 ;
V_128 = V_179 ;
return V_178 ;
}
static T_6 F_195 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_127 ) ;
}
static T_6 F_196 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_71 ;
unsigned long V_170 ;
V_71 = F_194 ( V_177 , 10 , & V_170 ) ;
if ( V_71 || V_170 > V_180 )
return - V_181 ;
V_127 = V_170 ;
return V_178 ;
}
static T_6 F_197 ( struct V_173 * V_174 , struct V_175 * V_176 ,
char * V_177 )
{
return sprintf ( V_177 , L_2 , V_123 ) ;
}
static T_6 F_198 ( struct V_173 * V_174 , struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_71 ;
unsigned long V_86 ;
V_71 = F_194 ( V_177 , 10 , & V_86 ) ;
if ( V_71 || V_86 > V_180 )
return - V_181 ;
if ( V_86 > V_141 )
return - V_181 ;
F_149 ( & V_126 ) ;
F_150 () ;
if ( V_123 != V_86 ) {
V_123 = V_86 ;
if ( V_86 & V_141 ) {
F_199 () ;
V_71 = F_68 () ;
F_200 () ;
if ( V_71 ) {
V_123 = V_182 ;
V_178 = V_71 ;
}
}
}
F_151 ( & V_126 ) ;
if ( V_86 & V_124 )
F_163 ( & V_129 ) ;
return V_178 ;
}
static T_6 F_201 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_43 ) ;
}
static T_6 F_202 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_71 ;
unsigned long V_183 ;
V_71 = F_194 ( V_177 , 10 , & V_183 ) ;
if ( V_71 )
return V_71 ;
if ( V_183 > 1 )
return - V_181 ;
F_149 ( & V_126 ) ;
F_150 () ;
if ( V_43 != V_183 ) {
if ( V_47 || F_65 () )
V_71 = - V_76 ;
else if ( V_53 == V_184 ) {
struct V_108 * V_177 ;
V_177 = F_203 ( V_185 + V_185 , sizeof( * V_177 ) ,
V_11 ) ;
if ( ! V_177 )
V_71 = - V_10 ;
else {
V_53 = V_177 ;
V_66 = V_177 + V_185 ;
V_66 [ 0 ] = V_186 [ 0 ] ;
}
}
if ( ! V_71 ) {
V_43 = V_183 ;
V_77 = V_183 ? 1 : V_185 ;
}
}
F_151 ( & V_126 ) ;
return V_71 ? V_71 : V_178 ;
}
static T_6 F_204 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_47 ) ;
}
static T_6 F_205 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_46 ) ;
}
static T_6 F_206 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_67 ) ;
}
static T_6 F_207 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
long V_187 ;
V_187 = V_14 - V_47
- V_46 - V_67 ;
if ( V_187 < 0 )
V_187 = 0 ;
return sprintf ( V_177 , L_3 , V_187 ) ;
}
static T_6 F_208 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_64 . V_65 ) ;
}
static int T_1 F_209 ( void )
{
struct V_188 * V_189 ;
int V_71 ;
V_71 = F_1 () ;
if ( V_71 )
goto V_3;
V_189 = F_210 ( F_145 , NULL , L_4 ) ;
if ( F_211 ( V_189 ) ) {
F_212 ( L_5 ) ;
V_71 = F_213 ( V_189 ) ;
goto V_190;
}
#ifdef F_214
V_71 = F_215 ( V_191 , & V_192 ) ;
if ( V_71 ) {
F_212 ( L_6 ) ;
F_216 ( V_189 ) ;
goto V_190;
}
#else
V_123 = V_124 ;
#endif
#ifdef F_217
F_218 ( F_189 , 100 ) ;
#endif
return 0 ;
V_190:
F_4 () ;
V_3:
return V_71 ;
}
