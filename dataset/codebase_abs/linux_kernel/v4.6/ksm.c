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
V_2 = F_6 ( V_1 , V_11 ) ;
if ( V_2 )
V_12 ++ ;
return V_2 ;
}
static inline void F_7 ( struct V_2 * V_2 )
{
V_12 -- ;
V_2 -> V_13 = NULL ;
F_8 ( V_1 , V_2 ) ;
}
static inline struct V_5 * F_9 ( void )
{
return F_10 ( V_4 , V_11 ) ;
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
static struct V_8 * F_14 ( struct V_14 * V_13 )
{
struct V_8 * V_15 ;
F_15 (mm_slots_hash, slot, link, (unsigned long)mm)
if ( V_15 -> V_13 == V_13 )
return V_15 ;
return NULL ;
}
static void F_16 ( struct V_14 * V_13 ,
struct V_8 * V_8 )
{
V_8 -> V_13 = V_13 ;
F_17 ( V_16 , & V_8 -> V_17 , ( unsigned long ) V_13 ) ;
}
static inline bool F_18 ( struct V_14 * V_13 )
{
return F_19 ( & V_13 -> V_18 ) == 0 ;
}
static int F_20 ( struct V_19 * V_20 , unsigned long V_21 )
{
struct V_22 * V_22 ;
int V_23 = 0 ;
do {
F_21 () ;
V_22 = F_22 ( V_20 , V_21 ,
V_24 | V_25 | V_26 ) ;
if ( F_23 ( V_22 ) )
break;
if ( F_24 ( V_22 ) )
V_23 = F_25 ( V_20 -> V_27 , V_20 , V_21 ,
V_28 |
V_29 ) ;
else
V_23 = V_30 ;
F_26 ( V_22 ) ;
} while ( ! ( V_23 & ( V_30 | V_31 | V_32 | V_33 ) ) );
return ( V_23 & V_33 ) ? - V_10 : 0 ;
}
static struct V_19 * F_27 ( struct V_14 * V_13 ,
unsigned long V_21 )
{
struct V_19 * V_20 ;
if ( F_18 ( V_13 ) )
return NULL ;
V_20 = F_28 ( V_13 , V_21 ) ;
if ( ! V_20 || V_20 -> V_34 > V_21 )
return NULL ;
if ( ! ( V_20 -> V_35 & V_36 ) || ! V_20 -> V_37 )
return NULL ;
return V_20 ;
}
static void F_29 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_38 ;
struct V_19 * V_20 ;
F_30 ( V_2 -> V_37 ) ;
F_31 ( & V_13 -> V_39 ) ;
V_20 = F_27 ( V_13 , V_21 ) ;
if ( V_20 )
F_20 ( V_20 , V_21 ) ;
F_32 ( & V_13 -> V_39 ) ;
}
static struct V_22 * F_33 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_38 ;
struct V_19 * V_20 ;
struct V_22 * V_22 ;
F_31 ( & V_13 -> V_39 ) ;
V_20 = F_27 ( V_13 , V_21 ) ;
if ( ! V_20 )
goto V_3;
V_22 = F_22 ( V_20 , V_21 , V_24 ) ;
if ( F_23 ( V_22 ) )
goto V_3;
if ( F_34 ( V_22 ) ) {
F_35 ( V_20 , V_22 , V_21 ) ;
F_36 ( V_22 ) ;
} else {
F_26 ( V_22 ) ;
V_3:
V_22 = NULL ;
}
F_32 ( & V_13 -> V_39 ) ;
return V_22 ;
}
static inline int F_37 ( unsigned long V_40 )
{
return V_41 ? 0 : F_38 ( F_39 ( V_40 ) ) ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_41 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_42 . V_43 )
V_44 -- ;
else
V_45 -- ;
F_30 ( V_2 -> V_37 ) ;
V_2 -> V_38 &= V_46 ;
F_21 () ;
}
if ( V_5 -> V_47 == & V_48 )
F_42 ( & V_5 -> V_49 ) ;
else
F_43 ( & V_5 -> V_50 ,
V_51 + F_38 ( V_5 -> V_52 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_22 * F_44 ( struct V_5 * V_5 , bool V_53 )
{
struct V_22 * V_22 ;
void * V_54 ;
unsigned long V_40 ;
V_54 = ( void * ) V_5 +
( V_55 | V_56 ) ;
V_57:
V_40 = F_45 ( V_5 -> V_40 ) ;
V_22 = F_46 ( V_40 ) ;
F_47 () ;
if ( F_45 ( V_22 -> V_58 ) != V_54 )
goto V_59;
while ( ! F_48 ( V_22 ) ) {
if ( ! F_49 ( V_22 ) )
goto V_59;
F_50 () ;
}
if ( F_45 ( V_22 -> V_58 ) != V_54 ) {
F_26 ( V_22 ) ;
goto V_59;
}
if ( V_53 ) {
F_51 ( V_22 ) ;
if ( F_45 ( V_22 -> V_58 ) != V_54 ) {
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
goto V_59;
}
}
return V_22 ;
V_59:
F_53 () ;
if ( F_45 ( V_5 -> V_40 ) != V_40 )
goto V_57;
F_40 ( V_5 ) ;
return NULL ;
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_38 & V_60 ) {
struct V_5 * V_5 ;
struct V_22 * V_22 ;
V_5 = V_2 -> V_47 ;
V_22 = F_44 ( V_5 , true ) ;
if ( ! V_22 )
goto V_3;
F_55 ( & V_2 -> V_42 ) ;
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
if ( ! F_56 ( & V_5 -> V_42 ) )
V_44 -- ;
else
V_45 -- ;
F_30 ( V_2 -> V_37 ) ;
V_2 -> V_38 &= V_46 ;
} else if ( V_2 -> V_38 & V_61 ) {
unsigned char V_62 ;
V_62 = ( unsigned char ) ( V_63 . V_64 - V_2 -> V_38 ) ;
F_57 ( V_62 > 1 ) ;
if ( ! V_62 )
F_43 ( & V_2 -> V_50 ,
V_65 + F_38 ( V_2 -> V_52 ) ) ;
V_66 -- ;
V_2 -> V_38 &= V_46 ;
}
V_3:
F_21 () ;
}
static void F_58 ( struct V_8 * V_8 ,
struct V_2 * * V_67 )
{
while ( * V_67 ) {
struct V_2 * V_2 = * V_67 ;
* V_67 = V_2 -> V_67 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_59 ( struct V_19 * V_20 ,
unsigned long V_68 , unsigned long V_69 )
{
unsigned long V_21 ;
int V_70 = 0 ;
for ( V_21 = V_68 ; V_21 < V_69 && ! V_70 ; V_21 += V_71 ) {
if ( F_18 ( V_20 -> V_27 ) )
break;
if ( F_60 ( V_72 ) )
V_70 = - V_73 ;
else
V_70 = F_20 ( V_20 , V_21 ) ;
}
return V_70 ;
}
static int F_61 ( struct V_5 * V_5 )
{
struct V_22 * V_22 ;
int V_70 ;
V_22 = F_44 ( V_5 , true ) ;
if ( ! V_22 ) {
return 0 ;
}
if ( F_62 ( F_63 ( V_22 ) ) ) {
V_70 = - V_74 ;
} else {
F_64 ( V_22 , NULL ) ;
F_40 ( V_5 ) ;
V_70 = 0 ;
}
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
return V_70 ;
}
static int F_65 ( void )
{
struct V_5 * V_5 , * V_43 ;
int V_52 ;
int V_70 = 0 ;
for ( V_52 = 0 ; V_52 < V_75 ; V_52 ++ ) {
while ( V_51 [ V_52 ] . V_76 ) {
V_5 = F_66 ( V_51 [ V_52 ] . V_76 ,
struct V_5 , V_50 ) ;
if ( F_61 ( V_5 ) ) {
V_70 = - V_74 ;
break;
}
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( F_61 ( V_5 ) )
V_70 = - V_74 ;
F_21 () ;
}
return V_70 ;
}
static int F_68 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_19 * V_20 ;
int V_70 = 0 ;
F_69 ( & V_77 ) ;
V_63 . V_8 = F_70 ( V_78 . V_79 . V_43 ,
struct V_8 , V_79 ) ;
F_71 ( & V_77 ) ;
for ( V_8 = V_63 . V_8 ;
V_8 != & V_78 ; V_8 = V_63 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_31 ( & V_13 -> V_39 ) ;
for ( V_20 = V_13 -> V_80 ; V_20 ; V_20 = V_20 -> V_81 ) {
if ( F_18 ( V_13 ) )
break;
if ( ! ( V_20 -> V_35 & V_36 ) || ! V_20 -> V_37 )
continue;
V_70 = F_59 ( V_20 ,
V_20 -> V_34 , V_20 -> V_82 ) ;
if ( V_70 )
goto error;
}
F_58 ( V_8 , & V_8 -> V_67 ) ;
F_32 ( & V_13 -> V_39 ) ;
F_69 ( & V_77 ) ;
V_63 . V_8 = F_70 ( V_8 -> V_79 . V_43 ,
struct V_8 , V_79 ) ;
if ( F_18 ( V_13 ) ) {
F_72 ( & V_8 -> V_17 ) ;
F_42 ( & V_8 -> V_79 ) ;
F_71 ( & V_77 ) ;
F_13 ( V_8 ) ;
F_73 ( V_83 , & V_13 -> V_84 ) ;
F_74 ( V_13 ) ;
} else
F_71 ( & V_77 ) ;
}
F_65 () ;
V_63 . V_64 = 0 ;
return 0 ;
error:
F_32 ( & V_13 -> V_39 ) ;
F_69 ( & V_77 ) ;
V_63 . V_8 = & V_78 ;
F_71 ( & V_77 ) ;
return V_70 ;
}
static T_2 F_75 ( struct V_22 * V_22 )
{
T_2 V_85 ;
void * V_21 = F_76 ( V_22 ) ;
V_85 = F_77 ( V_21 , V_71 / 4 , 17 ) ;
F_78 ( V_21 ) ;
return V_85 ;
}
static int F_79 ( struct V_22 * V_86 , struct V_22 * V_87 )
{
char * V_88 , * V_89 ;
int V_23 ;
V_88 = F_76 ( V_86 ) ;
V_89 = F_76 ( V_87 ) ;
V_23 = memcmp ( V_88 , V_89 , V_71 ) ;
F_78 ( V_89 ) ;
F_78 ( V_88 ) ;
return V_23 ;
}
static inline int F_80 ( struct V_22 * V_86 , struct V_22 * V_87 )
{
return ! F_79 ( V_86 , V_87 ) ;
}
static int F_81 ( struct V_19 * V_20 , struct V_22 * V_22 ,
T_3 * V_90 )
{
struct V_14 * V_13 = V_20 -> V_27 ;
unsigned long V_21 ;
T_3 * V_91 ;
T_4 * V_92 ;
int V_93 ;
int V_70 = - V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
V_21 = F_82 ( V_22 , V_20 ) ;
if ( V_21 == - V_94 )
goto V_3;
F_57 ( F_83 ( V_22 ) ) ;
V_95 = V_21 ;
V_96 = V_21 + V_71 ;
F_84 ( V_13 , V_95 , V_96 ) ;
V_91 = F_85 ( V_22 , V_13 , V_21 , & V_92 , 0 ) ;
if ( ! V_91 )
goto V_97;
if ( F_86 ( * V_91 ) || F_87 ( * V_91 ) ) {
T_3 V_98 ;
V_93 = F_49 ( V_22 ) ;
F_88 ( V_20 , V_21 , F_89 ( V_22 ) ) ;
V_98 = F_90 ( V_20 , V_21 , V_91 ) ;
if ( F_91 ( V_22 ) + 1 + V_93 != F_92 ( V_22 ) ) {
F_93 ( V_13 , V_21 , V_91 , V_98 ) ;
goto V_99;
}
if ( F_87 ( V_98 ) )
F_94 ( V_22 ) ;
V_98 = F_95 ( F_96 ( V_98 ) ) ;
F_97 ( V_13 , V_21 , V_91 , V_98 ) ;
}
* V_90 = * V_91 ;
V_70 = 0 ;
V_99:
F_98 ( V_91 , V_92 ) ;
V_97:
F_99 ( V_13 , V_95 , V_96 ) ;
V_3:
return V_70 ;
}
static int F_100 ( struct V_19 * V_20 , struct V_22 * V_22 ,
struct V_22 * V_100 , T_3 V_90 )
{
struct V_14 * V_13 = V_20 -> V_27 ;
T_5 * V_101 ;
T_3 * V_91 ;
T_4 * V_92 ;
unsigned long V_21 ;
int V_70 = - V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
V_21 = F_82 ( V_22 , V_20 ) ;
if ( V_21 == - V_94 )
goto V_3;
V_101 = F_101 ( V_13 , V_21 ) ;
if ( ! V_101 )
goto V_3;
V_95 = V_21 ;
V_96 = V_21 + V_71 ;
F_84 ( V_13 , V_95 , V_96 ) ;
V_91 = F_102 ( V_13 , V_101 , V_21 , & V_92 ) ;
if ( ! F_103 ( * V_91 , V_90 ) ) {
F_98 ( V_91 , V_92 ) ;
goto V_97;
}
F_104 ( V_100 ) ;
F_105 ( V_100 , V_20 , V_21 , false ) ;
F_88 ( V_20 , V_21 , F_106 ( * V_91 ) ) ;
F_90 ( V_20 , V_21 , V_91 ) ;
F_97 ( V_13 , V_21 , V_91 , F_107 ( V_100 , V_20 -> V_102 ) ) ;
F_108 ( V_22 , false ) ;
if ( ! F_63 ( V_22 ) )
F_109 ( V_22 ) ;
F_26 ( V_22 ) ;
F_98 ( V_91 , V_92 ) ;
V_70 = 0 ;
V_97:
F_99 ( V_13 , V_95 , V_96 ) ;
V_3:
return V_70 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_22 * V_22 , struct V_22 * V_100 )
{
T_3 V_90 = F_111 ( 0 ) ;
int V_70 = - V_94 ;
if ( V_22 == V_100 )
return 0 ;
if ( ! F_34 ( V_22 ) )
goto V_3;
if ( ! F_112 ( V_22 ) )
goto V_3;
if ( F_83 ( V_22 ) ) {
V_70 = F_113 ( V_22 ) ;
if ( V_70 )
goto V_99;
}
if ( F_81 ( V_20 , V_22 , & V_90 ) == 0 ) {
if ( ! V_100 ) {
F_64 ( V_22 , NULL ) ;
F_114 ( V_22 ) ;
if ( ! F_115 ( V_22 ) )
F_116 ( V_22 ) ;
V_70 = 0 ;
} else if ( F_80 ( V_22 , V_100 ) )
V_70 = F_100 ( V_20 , V_22 , V_100 , V_90 ) ;
}
if ( ( V_20 -> V_35 & V_103 ) && V_100 && ! V_70 ) {
F_117 ( V_22 ) ;
if ( ! F_118 ( V_100 ) ) {
F_52 ( V_22 ) ;
F_51 ( V_100 ) ;
F_119 ( V_100 ) ;
V_22 = V_100 ;
}
}
V_99:
F_52 ( V_22 ) ;
V_3:
return V_70 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_22 * V_22 , struct V_22 * V_100 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_19 * V_20 ;
int V_70 = - V_94 ;
F_31 ( & V_13 -> V_39 ) ;
V_20 = F_27 ( V_13 , V_2 -> V_38 ) ;
if ( ! V_20 )
goto V_3;
V_70 = F_110 ( V_20 , V_22 , V_100 ) ;
if ( V_70 )
goto V_3;
F_54 ( V_2 ) ;
V_2 -> V_37 = V_20 -> V_37 ;
F_121 ( V_20 -> V_37 ) ;
V_3:
F_32 ( & V_13 -> V_39 ) ;
return V_70 ;
}
static struct V_22 * F_122 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_2 * V_104 ,
struct V_22 * V_105 )
{
int V_70 ;
V_70 = F_120 ( V_2 , V_22 , NULL ) ;
if ( ! V_70 ) {
V_70 = F_120 ( V_104 ,
V_105 , V_22 ) ;
if ( V_70 )
F_29 ( V_2 ) ;
}
return V_70 ? NULL : V_22 ;
}
static struct V_22 * F_123 ( struct V_22 * V_22 )
{
int V_52 ;
struct V_106 * V_107 ;
struct V_76 * * V_108 ;
struct V_76 * V_109 ;
struct V_5 * V_5 ;
struct V_5 * V_110 ;
V_110 = F_124 ( V_22 ) ;
if ( V_110 && V_110 -> V_47 != & V_48 ) {
F_104 ( V_22 ) ;
return V_22 ;
}
V_52 = F_37 ( F_89 ( V_22 ) ) ;
V_107 = V_51 + V_52 ;
V_57:
V_108 = & V_107 -> V_76 ;
V_109 = NULL ;
while ( * V_108 ) {
struct V_22 * V_105 ;
int V_23 ;
F_21 () ;
V_5 = F_66 ( * V_108 , struct V_5 , V_50 ) ;
V_105 = F_44 ( V_5 , false ) ;
if ( ! V_105 ) {
goto V_57;
}
V_23 = F_79 ( V_22 , V_105 ) ;
F_26 ( V_105 ) ;
V_109 = * V_108 ;
if ( V_23 < 0 )
V_108 = & V_109 -> V_111 ;
else if ( V_23 > 0 )
V_108 = & V_109 -> V_112 ;
else {
V_105 = F_44 ( V_5 , true ) ;
if ( V_105 ) {
F_52 ( V_105 ) ;
if ( F_37 ( V_5 -> V_40 ) !=
F_38 ( V_5 -> V_52 ) ) {
F_26 ( V_105 ) ;
goto V_113;
}
return V_105 ;
}
if ( V_110 )
goto V_57;
return NULL ;
}
}
if ( ! V_110 )
return NULL ;
F_42 ( & V_110 -> V_49 ) ;
F_125 ( V_110 -> V_52 = V_52 ) ;
F_126 ( & V_110 -> V_50 , V_109 , V_108 ) ;
F_127 ( & V_110 -> V_50 , V_107 ) ;
F_104 ( V_22 ) ;
return V_22 ;
V_113:
if ( V_110 ) {
F_42 ( & V_110 -> V_49 ) ;
F_125 ( V_110 -> V_52 = V_52 ) ;
F_128 ( & V_5 -> V_50 , & V_110 -> V_50 , V_107 ) ;
F_104 ( V_22 ) ;
} else {
F_43 ( & V_5 -> V_50 , V_107 ) ;
V_22 = NULL ;
}
V_5 -> V_47 = & V_48 ;
F_129 ( & V_5 -> V_49 , V_5 -> V_47 ) ;
return V_22 ;
}
static struct V_5 * F_130 ( struct V_22 * V_100 )
{
int V_52 ;
unsigned long V_40 ;
struct V_106 * V_107 ;
struct V_76 * * V_108 ;
struct V_76 * V_109 ;
struct V_5 * V_5 ;
V_40 = F_89 ( V_100 ) ;
V_52 = F_37 ( V_40 ) ;
V_107 = V_51 + V_52 ;
V_57:
V_109 = NULL ;
V_108 = & V_107 -> V_76 ;
while ( * V_108 ) {
struct V_22 * V_105 ;
int V_23 ;
F_21 () ;
V_5 = F_66 ( * V_108 , struct V_5 , V_50 ) ;
V_105 = F_44 ( V_5 , false ) ;
if ( ! V_105 ) {
goto V_57;
}
V_23 = F_79 ( V_100 , V_105 ) ;
F_26 ( V_105 ) ;
V_109 = * V_108 ;
if ( V_23 < 0 )
V_108 = & V_109 -> V_111 ;
else if ( V_23 > 0 )
V_108 = & V_109 -> V_112 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_42 ) ;
V_5 -> V_40 = V_40 ;
F_64 ( V_100 , V_5 ) ;
F_125 ( V_5 -> V_52 = V_52 ) ;
F_126 ( & V_5 -> V_50 , V_109 , V_108 ) ;
F_127 ( & V_5 -> V_50 , V_107 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_22 * * V_114 )
{
struct V_76 * * V_108 ;
struct V_106 * V_107 ;
struct V_76 * V_109 = NULL ;
int V_52 ;
V_52 = F_37 ( F_89 ( V_22 ) ) ;
V_107 = V_65 + V_52 ;
V_108 = & V_107 -> V_76 ;
while ( * V_108 ) {
struct V_2 * V_104 ;
struct V_22 * V_105 ;
int V_23 ;
F_21 () ;
V_104 = F_66 ( * V_108 , struct V_2 , V_50 ) ;
V_105 = F_33 ( V_104 ) ;
if ( ! V_105 )
return NULL ;
if ( V_22 == V_105 ) {
F_26 ( V_105 ) ;
return NULL ;
}
V_23 = F_79 ( V_22 , V_105 ) ;
V_109 = * V_108 ;
if ( V_23 < 0 ) {
F_26 ( V_105 ) ;
V_108 = & V_109 -> V_111 ;
} else if ( V_23 > 0 ) {
F_26 ( V_105 ) ;
V_108 = & V_109 -> V_112 ;
} else if ( ! V_41 &&
F_133 ( V_105 ) != V_52 ) {
F_26 ( V_105 ) ;
return NULL ;
} else {
* V_114 = V_105 ;
return V_104 ;
}
}
V_2 -> V_38 |= V_61 ;
V_2 -> V_38 |= ( V_63 . V_64 & V_115 ) ;
F_125 ( V_2 -> V_52 = V_52 ) ;
F_126 ( & V_2 -> V_50 , V_109 , V_108 ) ;
F_127 ( & V_2 -> V_50 , V_107 ) ;
V_66 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_47 = V_5 ;
V_2 -> V_38 |= V_60 ;
F_135 ( & V_2 -> V_42 , & V_5 -> V_42 ) ;
if ( V_2 -> V_42 . V_43 )
V_44 ++ ;
else
V_45 ++ ;
}
static void F_136 ( struct V_22 * V_22 , struct V_2 * V_2 )
{
struct V_2 * V_104 ;
struct V_22 * V_105 = NULL ;
struct V_5 * V_5 ;
struct V_22 * V_100 ;
unsigned int V_85 ;
int V_70 ;
V_5 = F_124 ( V_22 ) ;
if ( V_5 ) {
if ( V_5 -> V_47 != & V_48 &&
F_37 ( V_5 -> V_40 ) != F_38 ( V_5 -> V_52 ) ) {
F_43 ( & V_5 -> V_50 ,
V_51 + F_38 ( V_5 -> V_52 ) ) ;
V_5 -> V_47 = & V_48 ;
F_129 ( & V_5 -> V_49 , V_5 -> V_47 ) ;
}
if ( V_5 -> V_47 != & V_48 &&
V_2 -> V_47 == V_5 )
return;
}
V_100 = F_123 ( V_22 ) ;
if ( V_100 == V_22 && V_2 -> V_47 == V_5 ) {
F_26 ( V_100 ) ;
return;
}
F_54 ( V_2 ) ;
if ( V_100 ) {
V_70 = F_120 ( V_2 , V_22 , V_100 ) ;
if ( ! V_70 ) {
F_51 ( V_100 ) ;
F_134 ( V_2 , F_124 ( V_100 ) ) ;
F_52 ( V_100 ) ;
}
F_26 ( V_100 ) ;
return;
}
V_85 = F_75 ( V_22 ) ;
if ( V_2 -> V_116 != V_85 ) {
V_2 -> V_116 = V_85 ;
return;
}
V_104 =
F_132 ( V_2 , V_22 , & V_105 ) ;
if ( V_104 ) {
V_100 = F_122 ( V_2 , V_22 ,
V_104 , V_105 ) ;
F_26 ( V_105 ) ;
if ( V_100 ) {
F_51 ( V_100 ) ;
V_5 = F_130 ( V_100 ) ;
if ( V_5 ) {
F_134 ( V_104 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_52 ( V_100 ) ;
if ( ! V_5 ) {
F_29 ( V_104 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_137 ( struct V_8 * V_8 ,
struct V_2 * * V_67 ,
unsigned long V_21 )
{
struct V_2 * V_2 ;
while ( * V_67 ) {
V_2 = * V_67 ;
if ( ( V_2 -> V_38 & V_46 ) == V_21 )
return V_2 ;
if ( V_2 -> V_38 > V_21 )
break;
* V_67 = V_2 -> V_67 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_38 = V_21 ;
V_2 -> V_67 = * V_67 ;
* V_67 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_138 ( struct V_22 * * V_22 )
{
struct V_14 * V_13 ;
struct V_8 * V_15 ;
struct V_19 * V_20 ;
struct V_2 * V_2 ;
int V_52 ;
if ( F_139 ( & V_78 . V_79 ) )
return NULL ;
V_15 = V_63 . V_8 ;
if ( V_15 == & V_78 ) {
F_140 () ;
if ( ! V_41 ) {
struct V_5 * V_5 , * V_43 ;
struct V_22 * V_22 ;
F_67 (stable_node, next,
&migrate_nodes, list) {
V_22 = F_44 ( V_5 , false ) ;
if ( V_22 )
F_26 ( V_22 ) ;
F_21 () ;
}
}
for ( V_52 = 0 ; V_52 < V_75 ; V_52 ++ )
V_65 [ V_52 ] = V_117 ;
F_69 ( & V_77 ) ;
V_15 = F_70 ( V_15 -> V_79 . V_43 , struct V_8 , V_79 ) ;
V_63 . V_8 = V_15 ;
F_71 ( & V_77 ) ;
if ( V_15 == & V_78 )
return NULL ;
V_118:
V_63 . V_38 = 0 ;
V_63 . V_67 = & V_15 -> V_67 ;
}
V_13 = V_15 -> V_13 ;
F_31 ( & V_13 -> V_39 ) ;
if ( F_18 ( V_13 ) )
V_20 = NULL ;
else
V_20 = F_28 ( V_13 , V_63 . V_38 ) ;
for (; V_20 ; V_20 = V_20 -> V_81 ) {
if ( ! ( V_20 -> V_35 & V_36 ) )
continue;
if ( V_63 . V_38 < V_20 -> V_34 )
V_63 . V_38 = V_20 -> V_34 ;
if ( ! V_20 -> V_37 )
V_63 . V_38 = V_20 -> V_82 ;
while ( V_63 . V_38 < V_20 -> V_82 ) {
if ( F_18 ( V_13 ) )
break;
* V_22 = F_22 ( V_20 , V_63 . V_38 , V_24 ) ;
if ( F_23 ( * V_22 ) ) {
V_63 . V_38 += V_71 ;
F_21 () ;
continue;
}
if ( F_34 ( * V_22 ) ) {
F_35 ( V_20 , * V_22 , V_63 . V_38 ) ;
F_36 ( * V_22 ) ;
V_2 = F_137 ( V_15 ,
V_63 . V_67 , V_63 . V_38 ) ;
if ( V_2 ) {
V_63 . V_67 =
& V_2 -> V_67 ;
V_63 . V_38 += V_71 ;
} else
F_26 ( * V_22 ) ;
F_32 ( & V_13 -> V_39 ) ;
return V_2 ;
}
F_26 ( * V_22 ) ;
V_63 . V_38 += V_71 ;
F_21 () ;
}
}
if ( F_18 ( V_13 ) ) {
V_63 . V_38 = 0 ;
V_63 . V_67 = & V_15 -> V_67 ;
}
F_58 ( V_15 , V_63 . V_67 ) ;
F_69 ( & V_77 ) ;
V_63 . V_8 = F_70 ( V_15 -> V_79 . V_43 ,
struct V_8 , V_79 ) ;
if ( V_63 . V_38 == 0 ) {
F_72 ( & V_15 -> V_17 ) ;
F_42 ( & V_15 -> V_79 ) ;
F_71 ( & V_77 ) ;
F_13 ( V_15 ) ;
F_73 ( V_83 , & V_13 -> V_84 ) ;
F_32 ( & V_13 -> V_39 ) ;
F_74 ( V_13 ) ;
} else {
F_32 ( & V_13 -> V_39 ) ;
F_71 ( & V_77 ) ;
}
V_15 = V_63 . V_8 ;
if ( V_15 != & V_78 )
goto V_118;
V_63 . V_64 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_119 )
{
struct V_2 * V_2 ;
struct V_22 * V_120 ( V_22 ) ;
while ( V_119 -- && F_142 ( ! F_143 ( V_72 ) ) ) {
F_21 () ;
V_2 = F_138 ( & V_22 ) ;
if ( ! V_2 )
return;
F_136 ( V_22 , V_2 ) ;
F_26 ( V_22 ) ;
}
}
static int F_144 ( void )
{
return ( V_121 & V_122 ) && ! F_139 ( & V_78 . V_79 ) ;
}
static int F_145 ( void * V_123 )
{
F_146 () ;
F_147 ( V_72 , 5 ) ;
while ( ! F_148 () ) {
F_149 ( & V_124 ) ;
F_150 () ;
if ( F_144 () )
F_141 ( V_125 ) ;
F_151 ( & V_124 ) ;
F_152 () ;
if ( F_144 () ) {
F_153 (
F_154 ( V_126 ) ) ;
} else {
F_155 ( V_127 ,
F_144 () || F_148 () ) ;
}
}
return 0 ;
}
int F_156 ( struct V_19 * V_20 , unsigned long V_68 ,
unsigned long V_69 , int V_128 , unsigned long * V_35 )
{
struct V_14 * V_13 = V_20 -> V_27 ;
int V_70 ;
switch ( V_128 ) {
case V_129 :
if ( * V_35 & ( V_36 | V_130 | V_131 |
V_132 | V_133 | V_134 |
V_135 | V_136 ) )
return 0 ;
#ifdef F_157
if ( * V_35 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_83 , & V_13 -> V_84 ) ) {
V_70 = F_159 ( V_13 ) ;
if ( V_70 )
return V_70 ;
}
* V_35 |= V_36 ;
break;
case V_137 :
if ( ! ( * V_35 & V_36 ) )
return 0 ;
if ( V_20 -> V_37 ) {
V_70 = F_59 ( V_20 , V_68 , V_69 ) ;
if ( V_70 )
return V_70 ;
}
* V_35 &= ~ V_36 ;
break;
}
return 0 ;
}
int F_159 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_138 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_138 = F_139 ( & V_78 . V_79 ) ;
F_69 ( & V_77 ) ;
F_16 ( V_13 , V_8 ) ;
if ( V_121 & V_139 )
F_160 ( & V_8 -> V_79 , & V_78 . V_79 ) ;
else
F_160 ( & V_8 -> V_79 , & V_63 . V_8 -> V_79 ) ;
F_71 ( & V_77 ) ;
F_161 ( V_83 , & V_13 -> V_84 ) ;
F_162 ( & V_13 -> V_140 ) ;
if ( V_138 )
F_163 ( & V_127 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_141 = 0 ;
F_69 ( & V_77 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_63 . V_8 != V_8 ) {
if ( ! V_8 -> V_67 ) {
F_72 ( & V_8 -> V_17 ) ;
F_42 ( & V_8 -> V_79 ) ;
V_141 = 1 ;
} else {
F_165 ( & V_8 -> V_79 ,
& V_63 . V_8 -> V_79 ) ;
}
}
F_71 ( & V_77 ) ;
if ( V_141 ) {
F_13 ( V_8 ) ;
F_73 ( V_83 , & V_13 -> V_84 ) ;
F_74 ( V_13 ) ;
} else if ( V_8 ) {
F_166 ( & V_13 -> V_39 ) ;
F_167 ( & V_13 -> V_39 ) ;
}
}
struct V_22 * F_168 ( struct V_22 * V_22 ,
struct V_19 * V_20 , unsigned long V_38 )
{
struct V_37 * V_37 = F_169 ( V_22 ) ;
struct V_22 * V_142 ;
if ( F_24 ( V_22 ) ) {
if ( F_124 ( V_22 ) &&
! ( V_121 & V_139 ) )
return V_22 ;
} else if ( ! V_37 ) {
return V_22 ;
} else if ( V_37 -> V_107 == V_20 -> V_37 -> V_107 &&
V_22 -> V_143 == F_170 ( V_20 , V_38 ) ) {
return V_22 ;
}
if ( ! F_171 ( V_22 ) )
return V_22 ;
V_142 = F_172 ( V_144 , V_20 , V_38 ) ;
if ( V_142 ) {
F_173 ( V_142 , V_22 , V_38 , V_20 ) ;
F_116 ( V_142 ) ;
F_174 ( V_142 ) ;
F_175 ( V_142 ) ;
}
return V_142 ;
}
int F_176 ( struct V_22 * V_22 , struct V_145 * V_146 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_23 = V_147 ;
int V_148 = 0 ;
F_177 ( ! F_24 ( V_22 ) , V_22 ) ;
F_177 ( ! F_178 ( V_22 ) , V_22 ) ;
V_5 = F_124 ( V_22 ) ;
if ( ! V_5 )
return V_23 ;
V_57:
F_41 (rmap_item, &stable_node->hlist, hlist) {
struct V_37 * V_37 = V_2 -> V_37 ;
struct V_149 * V_150 ;
struct V_19 * V_20 ;
F_21 () ;
F_179 ( V_37 ) ;
F_180 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
F_21 () ;
V_20 = V_150 -> V_20 ;
if ( V_2 -> V_38 < V_20 -> V_34 ||
V_2 -> V_38 >= V_20 -> V_82 )
continue;
if ( ( V_2 -> V_13 == V_20 -> V_27 ) == V_148 )
continue;
if ( V_146 -> V_151 && V_146 -> V_151 ( V_20 , V_146 -> V_152 ) )
continue;
V_23 = V_146 -> V_153 ( V_22 , V_20 ,
V_2 -> V_38 , V_146 -> V_152 ) ;
if ( V_23 != V_147 ) {
F_181 ( V_37 ) ;
goto V_3;
}
if ( V_146 -> V_154 && V_146 -> V_154 ( V_22 ) ) {
F_181 ( V_37 ) ;
goto V_3;
}
}
F_181 ( V_37 ) ;
}
if ( ! V_148 ++ )
goto V_57;
V_3:
return V_23 ;
}
void F_182 ( struct V_22 * V_155 , struct V_22 * V_156 )
{
struct V_5 * V_5 ;
F_177 ( ! F_178 ( V_156 ) , V_156 ) ;
F_177 ( ! F_178 ( V_155 ) , V_155 ) ;
F_177 ( V_155 -> V_58 != V_156 -> V_58 , V_155 ) ;
V_5 = F_124 ( V_155 ) ;
if ( V_5 ) {
F_177 ( V_5 -> V_40 != F_89 ( V_156 ) , V_156 ) ;
V_5 -> V_40 = F_89 ( V_155 ) ;
F_183 () ;
F_64 ( V_156 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_121 & V_157 ) {
F_151 ( & V_124 ) ;
F_184 ( & V_121 , F_185 ( V_157 ) ,
V_158 ) ;
F_149 ( & V_124 ) ;
}
}
static void F_186 ( unsigned long V_159 ,
unsigned long V_160 )
{
struct V_5 * V_5 , * V_43 ;
struct V_76 * V_50 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_75 ; V_52 ++ ) {
V_50 = F_187 ( V_51 + V_52 ) ;
while ( V_50 ) {
V_5 = F_66 ( V_50 , struct V_5 , V_50 ) ;
if ( V_5 -> V_40 >= V_159 &&
V_5 -> V_40 < V_160 ) {
F_40 ( V_5 ) ;
V_50 = F_187 ( V_51 + V_52 ) ;
} else
V_50 = F_188 ( V_50 ) ;
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( V_5 -> V_40 >= V_159 &&
V_5 -> V_40 < V_160 )
F_40 ( V_5 ) ;
F_21 () ;
}
}
static int F_189 ( struct V_161 * V_162 ,
unsigned long V_163 , void * V_152 )
{
struct V_164 * V_165 = V_152 ;
switch ( V_163 ) {
case V_166 :
F_149 ( & V_124 ) ;
V_121 |= V_157 ;
F_151 ( & V_124 ) ;
break;
case V_167 :
F_186 ( V_165 -> V_159 ,
V_165 -> V_159 + V_165 -> V_168 ) ;
case V_169 :
F_149 ( & V_124 ) ;
V_121 &= ~ V_157 ;
F_151 ( & V_124 ) ;
F_190 () ;
F_191 ( & V_121 , F_185 ( V_157 ) ) ;
break;
}
return V_170 ;
}
static void F_150 ( void )
{
}
static T_6 F_192 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_1 , V_126 ) ;
}
static T_6 F_193 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
unsigned long V_177 ;
int V_70 ;
V_70 = F_194 ( V_175 , 10 , & V_177 ) ;
if ( V_70 || V_177 > V_178 )
return - V_179 ;
V_126 = V_177 ;
return V_176 ;
}
static T_6 F_195 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_1 , V_125 ) ;
}
static T_6 F_196 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
int V_70 ;
unsigned long V_168 ;
V_70 = F_194 ( V_175 , 10 , & V_168 ) ;
if ( V_70 || V_168 > V_178 )
return - V_179 ;
V_125 = V_168 ;
return V_176 ;
}
static T_6 F_197 ( struct V_171 * V_172 , struct V_173 * V_174 ,
char * V_175 )
{
return sprintf ( V_175 , L_2 , V_121 ) ;
}
static T_6 F_198 ( struct V_171 * V_172 , struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
int V_70 ;
unsigned long V_84 ;
V_70 = F_194 ( V_175 , 10 , & V_84 ) ;
if ( V_70 || V_84 > V_178 )
return - V_179 ;
if ( V_84 > V_139 )
return - V_179 ;
F_149 ( & V_124 ) ;
F_150 () ;
if ( V_121 != V_84 ) {
V_121 = V_84 ;
if ( V_84 & V_139 ) {
F_199 () ;
V_70 = F_68 () ;
F_200 () ;
if ( V_70 ) {
V_121 = V_180 ;
V_176 = V_70 ;
}
}
}
F_151 ( & V_124 ) ;
if ( V_84 & V_122 )
F_163 ( & V_127 ) ;
return V_176 ;
}
static T_6 F_201 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_1 , V_41 ) ;
}
static T_6 F_202 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
const char * V_175 , T_7 V_176 )
{
int V_70 ;
unsigned long V_181 ;
V_70 = F_194 ( V_175 , 10 , & V_181 ) ;
if ( V_70 )
return V_70 ;
if ( V_181 > 1 )
return - V_179 ;
F_149 ( & V_124 ) ;
F_150 () ;
if ( V_41 != V_181 ) {
if ( V_45 || F_65 () )
V_70 = - V_74 ;
else if ( V_51 == V_182 ) {
struct V_106 * V_175 ;
V_175 = F_203 ( V_183 + V_183 , sizeof( * V_175 ) ,
V_11 ) ;
if ( ! V_175 )
V_70 = - V_10 ;
else {
V_51 = V_175 ;
V_65 = V_175 + V_183 ;
V_65 [ 0 ] = V_184 [ 0 ] ;
}
}
if ( ! V_70 ) {
V_41 = V_181 ;
V_75 = V_181 ? 1 : V_183 ;
}
}
F_151 ( & V_124 ) ;
return V_70 ? V_70 : V_176 ;
}
static T_6 F_204 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_2 , V_45 ) ;
}
static T_6 F_205 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_2 , V_44 ) ;
}
static T_6 F_206 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_2 , V_66 ) ;
}
static T_6 F_207 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
long V_185 ;
V_185 = V_12 - V_45
- V_44 - V_66 ;
if ( V_185 < 0 )
V_185 = 0 ;
return sprintf ( V_175 , L_3 , V_185 ) ;
}
static T_6 F_208 ( struct V_171 * V_172 ,
struct V_173 * V_174 , char * V_175 )
{
return sprintf ( V_175 , L_2 , V_63 . V_64 ) ;
}
static int T_1 F_209 ( void )
{
struct V_186 * V_187 ;
int V_70 ;
V_70 = F_1 () ;
if ( V_70 )
goto V_3;
V_187 = F_210 ( F_145 , NULL , L_4 ) ;
if ( F_211 ( V_187 ) ) {
F_212 ( L_5 ) ;
V_70 = F_213 ( V_187 ) ;
goto V_188;
}
#ifdef F_214
V_70 = F_215 ( V_189 , & V_190 ) ;
if ( V_70 ) {
F_212 ( L_6 ) ;
F_216 ( V_187 ) ;
goto V_188;
}
#else
V_121 = V_122 ;
#endif
#ifdef F_217
F_218 ( F_189 , 100 ) ;
#endif
return 0 ;
V_188:
F_4 () ;
V_3:
return V_70 ;
}
