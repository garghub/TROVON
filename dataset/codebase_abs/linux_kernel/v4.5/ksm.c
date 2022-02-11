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
V_22 = F_22 ( V_20 , V_21 , V_24 | V_25 ) ;
if ( F_23 ( V_22 ) )
break;
if ( F_24 ( V_22 ) )
V_23 = F_25 ( V_20 -> V_26 , V_20 , V_21 ,
V_27 ) ;
else
V_23 = V_28 ;
F_26 ( V_22 ) ;
} while ( ! ( V_23 & ( V_28 | V_29 | V_30 | V_31 ) ) );
return ( V_23 & V_31 ) ? - V_10 : 0 ;
}
static struct V_19 * F_27 ( struct V_14 * V_13 ,
unsigned long V_21 )
{
struct V_19 * V_20 ;
if ( F_18 ( V_13 ) )
return NULL ;
V_20 = F_28 ( V_13 , V_21 ) ;
if ( ! V_20 || V_20 -> V_32 > V_21 )
return NULL ;
if ( ! ( V_20 -> V_33 & V_34 ) || ! V_20 -> V_35 )
return NULL ;
return V_20 ;
}
static void F_29 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_36 ;
struct V_19 * V_20 ;
F_30 ( V_2 -> V_35 ) ;
F_31 ( & V_13 -> V_37 ) ;
V_20 = F_27 ( V_13 , V_21 ) ;
if ( V_20 )
F_20 ( V_20 , V_21 ) ;
F_32 ( & V_13 -> V_37 ) ;
}
static struct V_22 * F_33 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_36 ;
struct V_19 * V_20 ;
struct V_22 * V_22 ;
F_31 ( & V_13 -> V_37 ) ;
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
F_32 ( & V_13 -> V_37 ) ;
return V_22 ;
}
static inline int F_37 ( unsigned long V_38 )
{
return V_39 ? 0 : F_38 ( F_39 ( V_38 ) ) ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_41 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_40 . V_41 )
V_42 -- ;
else
V_43 -- ;
F_30 ( V_2 -> V_35 ) ;
V_2 -> V_36 &= V_44 ;
F_21 () ;
}
if ( V_5 -> V_45 == & V_46 )
F_42 ( & V_5 -> V_47 ) ;
else
F_43 ( & V_5 -> V_48 ,
V_49 + F_38 ( V_5 -> V_50 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_22 * F_44 ( struct V_5 * V_5 , bool V_51 )
{
struct V_22 * V_22 ;
void * V_52 ;
unsigned long V_38 ;
V_52 = ( void * ) V_5 +
( V_53 | V_54 ) ;
V_55:
V_38 = F_45 ( V_5 -> V_38 ) ;
V_22 = F_46 ( V_38 ) ;
F_47 () ;
if ( F_45 ( V_22 -> V_56 ) != V_52 )
goto V_57;
while ( ! F_48 ( V_22 ) ) {
if ( ! F_49 ( V_22 ) )
goto V_57;
F_50 () ;
}
if ( F_45 ( V_22 -> V_56 ) != V_52 ) {
F_26 ( V_22 ) ;
goto V_57;
}
if ( V_51 ) {
F_51 ( V_22 ) ;
if ( F_45 ( V_22 -> V_56 ) != V_52 ) {
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
goto V_57;
}
}
return V_22 ;
V_57:
F_53 () ;
if ( F_45 ( V_5 -> V_38 ) != V_38 )
goto V_55;
F_40 ( V_5 ) ;
return NULL ;
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_36 & V_58 ) {
struct V_5 * V_5 ;
struct V_22 * V_22 ;
V_5 = V_2 -> V_45 ;
V_22 = F_44 ( V_5 , true ) ;
if ( ! V_22 )
goto V_3;
F_55 ( & V_2 -> V_40 ) ;
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
if ( ! F_56 ( & V_5 -> V_40 ) )
V_42 -- ;
else
V_43 -- ;
F_30 ( V_2 -> V_35 ) ;
V_2 -> V_36 &= V_44 ;
} else if ( V_2 -> V_36 & V_59 ) {
unsigned char V_60 ;
V_60 = ( unsigned char ) ( V_61 . V_62 - V_2 -> V_36 ) ;
F_57 ( V_60 > 1 ) ;
if ( ! V_60 )
F_43 ( & V_2 -> V_48 ,
V_63 + F_38 ( V_2 -> V_50 ) ) ;
V_64 -- ;
V_2 -> V_36 &= V_44 ;
}
V_3:
F_21 () ;
}
static void F_58 ( struct V_8 * V_8 ,
struct V_2 * * V_65 )
{
while ( * V_65 ) {
struct V_2 * V_2 = * V_65 ;
* V_65 = V_2 -> V_65 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_59 ( struct V_19 * V_20 ,
unsigned long V_66 , unsigned long V_67 )
{
unsigned long V_21 ;
int V_68 = 0 ;
for ( V_21 = V_66 ; V_21 < V_67 && ! V_68 ; V_21 += V_69 ) {
if ( F_18 ( V_20 -> V_26 ) )
break;
if ( F_60 ( V_70 ) )
V_68 = - V_71 ;
else
V_68 = F_20 ( V_20 , V_21 ) ;
}
return V_68 ;
}
static int F_61 ( struct V_5 * V_5 )
{
struct V_22 * V_22 ;
int V_68 ;
V_22 = F_44 ( V_5 , true ) ;
if ( ! V_22 ) {
return 0 ;
}
if ( F_62 ( F_63 ( V_22 ) ) ) {
V_68 = - V_72 ;
} else {
F_64 ( V_22 , NULL ) ;
F_40 ( V_5 ) ;
V_68 = 0 ;
}
F_52 ( V_22 ) ;
F_26 ( V_22 ) ;
return V_68 ;
}
static int F_65 ( void )
{
struct V_5 * V_5 , * V_41 ;
int V_50 ;
int V_68 = 0 ;
for ( V_50 = 0 ; V_50 < V_73 ; V_50 ++ ) {
while ( V_49 [ V_50 ] . V_74 ) {
V_5 = F_66 ( V_49 [ V_50 ] . V_74 ,
struct V_5 , V_48 ) ;
if ( F_61 ( V_5 ) ) {
V_68 = - V_72 ;
break;
}
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( F_61 ( V_5 ) )
V_68 = - V_72 ;
F_21 () ;
}
return V_68 ;
}
static int F_68 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_19 * V_20 ;
int V_68 = 0 ;
F_69 ( & V_75 ) ;
V_61 . V_8 = F_70 ( V_76 . V_77 . V_41 ,
struct V_8 , V_77 ) ;
F_71 ( & V_75 ) ;
for ( V_8 = V_61 . V_8 ;
V_8 != & V_76 ; V_8 = V_61 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
for ( V_20 = V_13 -> V_78 ; V_20 ; V_20 = V_20 -> V_79 ) {
if ( F_18 ( V_13 ) )
break;
if ( ! ( V_20 -> V_33 & V_34 ) || ! V_20 -> V_35 )
continue;
V_68 = F_59 ( V_20 ,
V_20 -> V_32 , V_20 -> V_80 ) ;
if ( V_68 )
goto error;
}
F_58 ( V_8 , & V_8 -> V_65 ) ;
F_69 ( & V_75 ) ;
V_61 . V_8 = F_70 ( V_8 -> V_77 . V_41 ,
struct V_8 , V_77 ) ;
if ( F_18 ( V_13 ) ) {
F_72 ( & V_8 -> V_17 ) ;
F_42 ( & V_8 -> V_77 ) ;
F_71 ( & V_75 ) ;
F_13 ( V_8 ) ;
F_73 ( V_81 , & V_13 -> V_82 ) ;
F_32 ( & V_13 -> V_37 ) ;
F_74 ( V_13 ) ;
} else {
F_71 ( & V_75 ) ;
F_32 ( & V_13 -> V_37 ) ;
}
}
F_65 () ;
V_61 . V_62 = 0 ;
return 0 ;
error:
F_32 ( & V_13 -> V_37 ) ;
F_69 ( & V_75 ) ;
V_61 . V_8 = & V_76 ;
F_71 ( & V_75 ) ;
return V_68 ;
}
static T_2 F_75 ( struct V_22 * V_22 )
{
T_2 V_83 ;
void * V_21 = F_76 ( V_22 ) ;
V_83 = F_77 ( V_21 , V_69 / 4 , 17 ) ;
F_78 ( V_21 ) ;
return V_83 ;
}
static int F_79 ( struct V_22 * V_84 , struct V_22 * V_85 )
{
char * V_86 , * V_87 ;
int V_23 ;
V_86 = F_76 ( V_84 ) ;
V_87 = F_76 ( V_85 ) ;
V_23 = memcmp ( V_86 , V_87 , V_69 ) ;
F_78 ( V_87 ) ;
F_78 ( V_86 ) ;
return V_23 ;
}
static inline int F_80 ( struct V_22 * V_84 , struct V_22 * V_85 )
{
return ! F_79 ( V_84 , V_85 ) ;
}
static int F_81 ( struct V_19 * V_20 , struct V_22 * V_22 ,
T_3 * V_88 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
unsigned long V_21 ;
T_3 * V_89 ;
T_4 * V_90 ;
int V_91 ;
int V_68 = - V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
V_21 = F_82 ( V_22 , V_20 ) ;
if ( V_21 == - V_92 )
goto V_3;
F_57 ( F_83 ( V_22 ) ) ;
V_93 = V_21 ;
V_94 = V_21 + V_69 ;
F_84 ( V_13 , V_93 , V_94 ) ;
V_89 = F_85 ( V_22 , V_13 , V_21 , & V_90 , 0 ) ;
if ( ! V_89 )
goto V_95;
if ( F_86 ( * V_89 ) || F_87 ( * V_89 ) ) {
T_3 V_96 ;
V_91 = F_49 ( V_22 ) ;
F_88 ( V_20 , V_21 , F_89 ( V_22 ) ) ;
V_96 = F_90 ( V_20 , V_21 , V_89 ) ;
if ( F_91 ( V_22 ) + 1 + V_91 != F_92 ( V_22 ) ) {
F_93 ( V_13 , V_21 , V_89 , V_96 ) ;
goto V_97;
}
if ( F_87 ( V_96 ) )
F_94 ( V_22 ) ;
V_96 = F_95 ( F_96 ( V_96 ) ) ;
F_97 ( V_13 , V_21 , V_89 , V_96 ) ;
}
* V_88 = * V_89 ;
V_68 = 0 ;
V_97:
F_98 ( V_89 , V_90 ) ;
V_95:
F_99 ( V_13 , V_93 , V_94 ) ;
V_3:
return V_68 ;
}
static int F_100 ( struct V_19 * V_20 , struct V_22 * V_22 ,
struct V_22 * V_98 , T_3 V_88 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
T_5 * V_99 ;
T_3 * V_89 ;
T_4 * V_90 ;
unsigned long V_21 ;
int V_68 = - V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
V_21 = F_82 ( V_22 , V_20 ) ;
if ( V_21 == - V_92 )
goto V_3;
V_99 = F_101 ( V_13 , V_21 ) ;
if ( ! V_99 )
goto V_3;
V_93 = V_21 ;
V_94 = V_21 + V_69 ;
F_84 ( V_13 , V_93 , V_94 ) ;
V_89 = F_102 ( V_13 , V_99 , V_21 , & V_90 ) ;
if ( ! F_103 ( * V_89 , V_88 ) ) {
F_98 ( V_89 , V_90 ) ;
goto V_95;
}
F_104 ( V_98 ) ;
F_105 ( V_98 , V_20 , V_21 , false ) ;
F_88 ( V_20 , V_21 , F_106 ( * V_89 ) ) ;
F_90 ( V_20 , V_21 , V_89 ) ;
F_97 ( V_13 , V_21 , V_89 , F_107 ( V_98 , V_20 -> V_100 ) ) ;
F_108 ( V_22 , false ) ;
if ( ! F_63 ( V_22 ) )
F_109 ( V_22 ) ;
F_26 ( V_22 ) ;
F_98 ( V_89 , V_90 ) ;
V_68 = 0 ;
V_95:
F_99 ( V_13 , V_93 , V_94 ) ;
V_3:
return V_68 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_22 * V_22 , struct V_22 * V_98 )
{
T_3 V_88 = F_111 ( 0 ) ;
int V_68 = - V_92 ;
if ( V_22 == V_98 )
return 0 ;
if ( ! F_34 ( V_22 ) )
goto V_3;
if ( ! F_112 ( V_22 ) )
goto V_3;
if ( F_83 ( V_22 ) ) {
V_68 = F_113 ( V_22 ) ;
if ( V_68 )
goto V_97;
}
if ( F_81 ( V_20 , V_22 , & V_88 ) == 0 ) {
if ( ! V_98 ) {
F_64 ( V_22 , NULL ) ;
F_114 ( V_22 ) ;
if ( ! F_115 ( V_22 ) )
F_116 ( V_22 ) ;
V_68 = 0 ;
} else if ( F_80 ( V_22 , V_98 ) )
V_68 = F_100 ( V_20 , V_22 , V_98 , V_88 ) ;
}
if ( ( V_20 -> V_33 & V_101 ) && V_98 && ! V_68 ) {
F_117 ( V_22 ) ;
if ( ! F_118 ( V_98 ) ) {
F_52 ( V_22 ) ;
F_51 ( V_98 ) ;
F_119 ( V_98 ) ;
V_22 = V_98 ;
}
}
V_97:
F_52 ( V_22 ) ;
V_3:
return V_68 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_22 * V_22 , struct V_22 * V_98 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_19 * V_20 ;
int V_68 = - V_92 ;
F_31 ( & V_13 -> V_37 ) ;
V_20 = F_27 ( V_13 , V_2 -> V_36 ) ;
if ( ! V_20 )
goto V_3;
V_68 = F_110 ( V_20 , V_22 , V_98 ) ;
if ( V_68 )
goto V_3;
F_54 ( V_2 ) ;
V_2 -> V_35 = V_20 -> V_35 ;
F_121 ( V_20 -> V_35 ) ;
V_3:
F_32 ( & V_13 -> V_37 ) ;
return V_68 ;
}
static struct V_22 * F_122 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_2 * V_102 ,
struct V_22 * V_103 )
{
int V_68 ;
V_68 = F_120 ( V_2 , V_22 , NULL ) ;
if ( ! V_68 ) {
V_68 = F_120 ( V_102 ,
V_103 , V_22 ) ;
if ( V_68 )
F_29 ( V_2 ) ;
}
return V_68 ? NULL : V_22 ;
}
static struct V_22 * F_123 ( struct V_22 * V_22 )
{
int V_50 ;
struct V_104 * V_105 ;
struct V_74 * * V_106 ;
struct V_74 * V_107 ;
struct V_5 * V_5 ;
struct V_5 * V_108 ;
V_108 = F_124 ( V_22 ) ;
if ( V_108 && V_108 -> V_45 != & V_46 ) {
F_104 ( V_22 ) ;
return V_22 ;
}
V_50 = F_37 ( F_89 ( V_22 ) ) ;
V_105 = V_49 + V_50 ;
V_55:
V_106 = & V_105 -> V_74 ;
V_107 = NULL ;
while ( * V_106 ) {
struct V_22 * V_103 ;
int V_23 ;
F_21 () ;
V_5 = F_66 ( * V_106 , struct V_5 , V_48 ) ;
V_103 = F_44 ( V_5 , false ) ;
if ( ! V_103 ) {
goto V_55;
}
V_23 = F_79 ( V_22 , V_103 ) ;
F_26 ( V_103 ) ;
V_107 = * V_106 ;
if ( V_23 < 0 )
V_106 = & V_107 -> V_109 ;
else if ( V_23 > 0 )
V_106 = & V_107 -> V_110 ;
else {
V_103 = F_44 ( V_5 , true ) ;
if ( V_103 ) {
F_52 ( V_103 ) ;
if ( F_37 ( V_5 -> V_38 ) !=
F_38 ( V_5 -> V_50 ) ) {
F_26 ( V_103 ) ;
goto V_111;
}
return V_103 ;
}
if ( V_108 )
goto V_55;
return NULL ;
}
}
if ( ! V_108 )
return NULL ;
F_42 ( & V_108 -> V_47 ) ;
F_125 ( V_108 -> V_50 = V_50 ) ;
F_126 ( & V_108 -> V_48 , V_107 , V_106 ) ;
F_127 ( & V_108 -> V_48 , V_105 ) ;
F_104 ( V_22 ) ;
return V_22 ;
V_111:
if ( V_108 ) {
F_42 ( & V_108 -> V_47 ) ;
F_125 ( V_108 -> V_50 = V_50 ) ;
F_128 ( & V_5 -> V_48 , & V_108 -> V_48 , V_105 ) ;
F_104 ( V_22 ) ;
} else {
F_43 ( & V_5 -> V_48 , V_105 ) ;
V_22 = NULL ;
}
V_5 -> V_45 = & V_46 ;
F_129 ( & V_5 -> V_47 , V_5 -> V_45 ) ;
return V_22 ;
}
static struct V_5 * F_130 ( struct V_22 * V_98 )
{
int V_50 ;
unsigned long V_38 ;
struct V_104 * V_105 ;
struct V_74 * * V_106 ;
struct V_74 * V_107 ;
struct V_5 * V_5 ;
V_38 = F_89 ( V_98 ) ;
V_50 = F_37 ( V_38 ) ;
V_105 = V_49 + V_50 ;
V_55:
V_107 = NULL ;
V_106 = & V_105 -> V_74 ;
while ( * V_106 ) {
struct V_22 * V_103 ;
int V_23 ;
F_21 () ;
V_5 = F_66 ( * V_106 , struct V_5 , V_48 ) ;
V_103 = F_44 ( V_5 , false ) ;
if ( ! V_103 ) {
goto V_55;
}
V_23 = F_79 ( V_98 , V_103 ) ;
F_26 ( V_103 ) ;
V_107 = * V_106 ;
if ( V_23 < 0 )
V_106 = & V_107 -> V_109 ;
else if ( V_23 > 0 )
V_106 = & V_107 -> V_110 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_40 ) ;
V_5 -> V_38 = V_38 ;
F_64 ( V_98 , V_5 ) ;
F_125 ( V_5 -> V_50 = V_50 ) ;
F_126 ( & V_5 -> V_48 , V_107 , V_106 ) ;
F_127 ( & V_5 -> V_48 , V_105 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_22 * * V_112 )
{
struct V_74 * * V_106 ;
struct V_104 * V_105 ;
struct V_74 * V_107 = NULL ;
int V_50 ;
V_50 = F_37 ( F_89 ( V_22 ) ) ;
V_105 = V_63 + V_50 ;
V_106 = & V_105 -> V_74 ;
while ( * V_106 ) {
struct V_2 * V_102 ;
struct V_22 * V_103 ;
int V_23 ;
F_21 () ;
V_102 = F_66 ( * V_106 , struct V_2 , V_48 ) ;
V_103 = F_33 ( V_102 ) ;
if ( ! V_103 )
return NULL ;
if ( V_22 == V_103 ) {
F_26 ( V_103 ) ;
return NULL ;
}
V_23 = F_79 ( V_22 , V_103 ) ;
V_107 = * V_106 ;
if ( V_23 < 0 ) {
F_26 ( V_103 ) ;
V_106 = & V_107 -> V_109 ;
} else if ( V_23 > 0 ) {
F_26 ( V_103 ) ;
V_106 = & V_107 -> V_110 ;
} else if ( ! V_39 &&
F_133 ( V_103 ) != V_50 ) {
F_26 ( V_103 ) ;
return NULL ;
} else {
* V_112 = V_103 ;
return V_102 ;
}
}
V_2 -> V_36 |= V_59 ;
V_2 -> V_36 |= ( V_61 . V_62 & V_113 ) ;
F_125 ( V_2 -> V_50 = V_50 ) ;
F_126 ( & V_2 -> V_48 , V_107 , V_106 ) ;
F_127 ( & V_2 -> V_48 , V_105 ) ;
V_64 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_45 = V_5 ;
V_2 -> V_36 |= V_58 ;
F_135 ( & V_2 -> V_40 , & V_5 -> V_40 ) ;
if ( V_2 -> V_40 . V_41 )
V_42 ++ ;
else
V_43 ++ ;
}
static void F_136 ( struct V_22 * V_22 , struct V_2 * V_2 )
{
struct V_2 * V_102 ;
struct V_22 * V_103 = NULL ;
struct V_5 * V_5 ;
struct V_22 * V_98 ;
unsigned int V_83 ;
int V_68 ;
V_5 = F_124 ( V_22 ) ;
if ( V_5 ) {
if ( V_5 -> V_45 != & V_46 &&
F_37 ( V_5 -> V_38 ) != F_38 ( V_5 -> V_50 ) ) {
F_43 ( & V_5 -> V_48 ,
V_49 + F_38 ( V_5 -> V_50 ) ) ;
V_5 -> V_45 = & V_46 ;
F_129 ( & V_5 -> V_47 , V_5 -> V_45 ) ;
}
if ( V_5 -> V_45 != & V_46 &&
V_2 -> V_45 == V_5 )
return;
}
V_98 = F_123 ( V_22 ) ;
if ( V_98 == V_22 && V_2 -> V_45 == V_5 ) {
F_26 ( V_98 ) ;
return;
}
F_54 ( V_2 ) ;
if ( V_98 ) {
V_68 = F_120 ( V_2 , V_22 , V_98 ) ;
if ( ! V_68 ) {
F_51 ( V_98 ) ;
F_134 ( V_2 , F_124 ( V_98 ) ) ;
F_52 ( V_98 ) ;
}
F_26 ( V_98 ) ;
return;
}
V_83 = F_75 ( V_22 ) ;
if ( V_2 -> V_114 != V_83 ) {
V_2 -> V_114 = V_83 ;
return;
}
V_102 =
F_132 ( V_2 , V_22 , & V_103 ) ;
if ( V_102 ) {
V_98 = F_122 ( V_2 , V_22 ,
V_102 , V_103 ) ;
F_26 ( V_103 ) ;
if ( V_98 ) {
F_51 ( V_98 ) ;
V_5 = F_130 ( V_98 ) ;
if ( V_5 ) {
F_134 ( V_102 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_52 ( V_98 ) ;
if ( ! V_5 ) {
F_29 ( V_102 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_137 ( struct V_8 * V_8 ,
struct V_2 * * V_65 ,
unsigned long V_21 )
{
struct V_2 * V_2 ;
while ( * V_65 ) {
V_2 = * V_65 ;
if ( ( V_2 -> V_36 & V_44 ) == V_21 )
return V_2 ;
if ( V_2 -> V_36 > V_21 )
break;
* V_65 = V_2 -> V_65 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_36 = V_21 ;
V_2 -> V_65 = * V_65 ;
* V_65 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_138 ( struct V_22 * * V_22 )
{
struct V_14 * V_13 ;
struct V_8 * V_15 ;
struct V_19 * V_20 ;
struct V_2 * V_2 ;
int V_50 ;
if ( F_139 ( & V_76 . V_77 ) )
return NULL ;
V_15 = V_61 . V_8 ;
if ( V_15 == & V_76 ) {
F_140 () ;
if ( ! V_39 ) {
struct V_5 * V_5 , * V_41 ;
struct V_22 * V_22 ;
F_67 (stable_node, next,
&migrate_nodes, list) {
V_22 = F_44 ( V_5 , false ) ;
if ( V_22 )
F_26 ( V_22 ) ;
F_21 () ;
}
}
for ( V_50 = 0 ; V_50 < V_73 ; V_50 ++ )
V_63 [ V_50 ] = V_115 ;
F_69 ( & V_75 ) ;
V_15 = F_70 ( V_15 -> V_77 . V_41 , struct V_8 , V_77 ) ;
V_61 . V_8 = V_15 ;
F_71 ( & V_75 ) ;
if ( V_15 == & V_76 )
return NULL ;
V_116:
V_61 . V_36 = 0 ;
V_61 . V_65 = & V_15 -> V_65 ;
}
V_13 = V_15 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_18 ( V_13 ) )
V_20 = NULL ;
else
V_20 = F_28 ( V_13 , V_61 . V_36 ) ;
for (; V_20 ; V_20 = V_20 -> V_79 ) {
if ( ! ( V_20 -> V_33 & V_34 ) )
continue;
if ( V_61 . V_36 < V_20 -> V_32 )
V_61 . V_36 = V_20 -> V_32 ;
if ( ! V_20 -> V_35 )
V_61 . V_36 = V_20 -> V_80 ;
while ( V_61 . V_36 < V_20 -> V_80 ) {
if ( F_18 ( V_13 ) )
break;
* V_22 = F_22 ( V_20 , V_61 . V_36 , V_24 ) ;
if ( F_23 ( * V_22 ) ) {
V_61 . V_36 += V_69 ;
F_21 () ;
continue;
}
if ( F_34 ( * V_22 ) ) {
F_35 ( V_20 , * V_22 , V_61 . V_36 ) ;
F_36 ( * V_22 ) ;
V_2 = F_137 ( V_15 ,
V_61 . V_65 , V_61 . V_36 ) ;
if ( V_2 ) {
V_61 . V_65 =
& V_2 -> V_65 ;
V_61 . V_36 += V_69 ;
} else
F_26 ( * V_22 ) ;
F_32 ( & V_13 -> V_37 ) ;
return V_2 ;
}
F_26 ( * V_22 ) ;
V_61 . V_36 += V_69 ;
F_21 () ;
}
}
if ( F_18 ( V_13 ) ) {
V_61 . V_36 = 0 ;
V_61 . V_65 = & V_15 -> V_65 ;
}
F_58 ( V_15 , V_61 . V_65 ) ;
F_69 ( & V_75 ) ;
V_61 . V_8 = F_70 ( V_15 -> V_77 . V_41 ,
struct V_8 , V_77 ) ;
if ( V_61 . V_36 == 0 ) {
F_72 ( & V_15 -> V_17 ) ;
F_42 ( & V_15 -> V_77 ) ;
F_71 ( & V_75 ) ;
F_13 ( V_15 ) ;
F_73 ( V_81 , & V_13 -> V_82 ) ;
F_32 ( & V_13 -> V_37 ) ;
F_74 ( V_13 ) ;
} else {
F_71 ( & V_75 ) ;
F_32 ( & V_13 -> V_37 ) ;
}
V_15 = V_61 . V_8 ;
if ( V_15 != & V_76 )
goto V_116;
V_61 . V_62 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_117 )
{
struct V_2 * V_2 ;
struct V_22 * V_118 ( V_22 ) ;
while ( V_117 -- && F_142 ( ! F_143 ( V_70 ) ) ) {
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
return ( V_119 & V_120 ) && ! F_139 ( & V_76 . V_77 ) ;
}
static int F_145 ( void * V_121 )
{
F_146 () ;
F_147 ( V_70 , 5 ) ;
while ( ! F_148 () ) {
F_149 ( & V_122 ) ;
F_150 () ;
if ( F_144 () )
F_141 ( V_123 ) ;
F_151 ( & V_122 ) ;
F_152 () ;
if ( F_144 () ) {
F_153 (
F_154 ( V_124 ) ) ;
} else {
F_155 ( V_125 ,
F_144 () || F_148 () ) ;
}
}
return 0 ;
}
int F_156 ( struct V_19 * V_20 , unsigned long V_66 ,
unsigned long V_67 , int V_126 , unsigned long * V_33 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
int V_68 ;
switch ( V_126 ) {
case V_127 :
if ( * V_33 & ( V_34 | V_128 | V_129 |
V_130 | V_131 | V_132 |
V_133 | V_134 ) )
return 0 ;
#ifdef F_157
if ( * V_33 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_81 , & V_13 -> V_82 ) ) {
V_68 = F_159 ( V_13 ) ;
if ( V_68 )
return V_68 ;
}
* V_33 |= V_34 ;
break;
case V_135 :
if ( ! ( * V_33 & V_34 ) )
return 0 ;
if ( V_20 -> V_35 ) {
V_68 = F_59 ( V_20 , V_66 , V_67 ) ;
if ( V_68 )
return V_68 ;
}
* V_33 &= ~ V_34 ;
break;
}
return 0 ;
}
int F_159 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_136 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_136 = F_139 ( & V_76 . V_77 ) ;
F_69 ( & V_75 ) ;
F_16 ( V_13 , V_8 ) ;
if ( V_119 & V_137 )
F_160 ( & V_8 -> V_77 , & V_76 . V_77 ) ;
else
F_160 ( & V_8 -> V_77 , & V_61 . V_8 -> V_77 ) ;
F_71 ( & V_75 ) ;
F_161 ( V_81 , & V_13 -> V_82 ) ;
F_162 ( & V_13 -> V_138 ) ;
if ( V_136 )
F_163 ( & V_125 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_139 = 0 ;
F_69 ( & V_75 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_61 . V_8 != V_8 ) {
if ( ! V_8 -> V_65 ) {
F_72 ( & V_8 -> V_17 ) ;
F_42 ( & V_8 -> V_77 ) ;
V_139 = 1 ;
} else {
F_165 ( & V_8 -> V_77 ,
& V_61 . V_8 -> V_77 ) ;
}
}
F_71 ( & V_75 ) ;
if ( V_139 ) {
F_13 ( V_8 ) ;
F_73 ( V_81 , & V_13 -> V_82 ) ;
F_74 ( V_13 ) ;
} else if ( V_8 ) {
F_166 ( & V_13 -> V_37 ) ;
F_167 ( & V_13 -> V_37 ) ;
}
}
struct V_22 * F_168 ( struct V_22 * V_22 ,
struct V_19 * V_20 , unsigned long V_36 )
{
struct V_35 * V_35 = F_169 ( V_22 ) ;
struct V_22 * V_140 ;
if ( F_24 ( V_22 ) ) {
if ( F_124 ( V_22 ) &&
! ( V_119 & V_137 ) )
return V_22 ;
} else if ( ! V_35 ) {
return V_22 ;
} else if ( V_35 -> V_105 == V_20 -> V_35 -> V_105 &&
V_22 -> V_141 == F_170 ( V_20 , V_36 ) ) {
return V_22 ;
}
if ( ! F_171 ( V_22 ) )
return V_22 ;
V_140 = F_172 ( V_142 , V_20 , V_36 ) ;
if ( V_140 ) {
F_173 ( V_140 , V_22 , V_36 , V_20 ) ;
F_116 ( V_140 ) ;
F_174 ( V_140 ) ;
F_175 ( V_140 ) ;
}
return V_140 ;
}
int F_176 ( struct V_22 * V_22 , struct V_143 * V_144 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_23 = V_145 ;
int V_146 = 0 ;
F_177 ( ! F_24 ( V_22 ) , V_22 ) ;
F_177 ( ! F_178 ( V_22 ) , V_22 ) ;
V_5 = F_124 ( V_22 ) ;
if ( ! V_5 )
return V_23 ;
V_55:
F_41 (rmap_item, &stable_node->hlist, hlist) {
struct V_35 * V_35 = V_2 -> V_35 ;
struct V_147 * V_148 ;
struct V_19 * V_20 ;
F_21 () ;
F_179 ( V_35 ) ;
F_180 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
F_21 () ;
V_20 = V_148 -> V_20 ;
if ( V_2 -> V_36 < V_20 -> V_32 ||
V_2 -> V_36 >= V_20 -> V_80 )
continue;
if ( ( V_2 -> V_13 == V_20 -> V_26 ) == V_146 )
continue;
if ( V_144 -> V_149 && V_144 -> V_149 ( V_20 , V_144 -> V_150 ) )
continue;
V_23 = V_144 -> V_151 ( V_22 , V_20 ,
V_2 -> V_36 , V_144 -> V_150 ) ;
if ( V_23 != V_145 ) {
F_181 ( V_35 ) ;
goto V_3;
}
if ( V_144 -> V_152 && V_144 -> V_152 ( V_22 ) ) {
F_181 ( V_35 ) ;
goto V_3;
}
}
F_181 ( V_35 ) ;
}
if ( ! V_146 ++ )
goto V_55;
V_3:
return V_23 ;
}
void F_182 ( struct V_22 * V_153 , struct V_22 * V_154 )
{
struct V_5 * V_5 ;
F_177 ( ! F_178 ( V_154 ) , V_154 ) ;
F_177 ( ! F_178 ( V_153 ) , V_153 ) ;
F_177 ( V_153 -> V_56 != V_154 -> V_56 , V_153 ) ;
V_5 = F_124 ( V_153 ) ;
if ( V_5 ) {
F_177 ( V_5 -> V_38 != F_89 ( V_154 ) , V_154 ) ;
V_5 -> V_38 = F_89 ( V_153 ) ;
F_183 () ;
F_64 ( V_154 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_119 & V_155 ) {
F_151 ( & V_122 ) ;
F_184 ( & V_119 , F_185 ( V_155 ) ,
V_156 ) ;
F_149 ( & V_122 ) ;
}
}
static void F_186 ( unsigned long V_157 ,
unsigned long V_158 )
{
struct V_5 * V_5 , * V_41 ;
struct V_74 * V_48 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_73 ; V_50 ++ ) {
V_48 = F_187 ( V_49 + V_50 ) ;
while ( V_48 ) {
V_5 = F_66 ( V_48 , struct V_5 , V_48 ) ;
if ( V_5 -> V_38 >= V_157 &&
V_5 -> V_38 < V_158 ) {
F_40 ( V_5 ) ;
V_48 = F_187 ( V_49 + V_50 ) ;
} else
V_48 = F_188 ( V_48 ) ;
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( V_5 -> V_38 >= V_157 &&
V_5 -> V_38 < V_158 )
F_40 ( V_5 ) ;
F_21 () ;
}
}
static int F_189 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_150 )
{
struct V_162 * V_163 = V_150 ;
switch ( V_161 ) {
case V_164 :
F_149 ( & V_122 ) ;
V_119 |= V_155 ;
F_151 ( & V_122 ) ;
break;
case V_165 :
F_186 ( V_163 -> V_157 ,
V_163 -> V_157 + V_163 -> V_166 ) ;
case V_167 :
F_149 ( & V_122 ) ;
V_119 &= ~ V_155 ;
F_151 ( & V_122 ) ;
F_190 () ;
F_191 ( & V_119 , F_185 ( V_155 ) ) ;
break;
}
return V_168 ;
}
static void F_150 ( void )
{
}
static T_6 F_192 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_1 , V_124 ) ;
}
static T_6 F_193 ( struct V_169 * V_170 ,
struct V_171 * V_172 ,
const char * V_173 , T_7 V_174 )
{
unsigned long V_175 ;
int V_68 ;
V_68 = F_194 ( V_173 , 10 , & V_175 ) ;
if ( V_68 || V_175 > V_176 )
return - V_177 ;
V_124 = V_175 ;
return V_174 ;
}
static T_6 F_195 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_1 , V_123 ) ;
}
static T_6 F_196 ( struct V_169 * V_170 ,
struct V_171 * V_172 ,
const char * V_173 , T_7 V_174 )
{
int V_68 ;
unsigned long V_166 ;
V_68 = F_194 ( V_173 , 10 , & V_166 ) ;
if ( V_68 || V_166 > V_176 )
return - V_177 ;
V_123 = V_166 ;
return V_174 ;
}
static T_6 F_197 ( struct V_169 * V_170 , struct V_171 * V_172 ,
char * V_173 )
{
return sprintf ( V_173 , L_2 , V_119 ) ;
}
static T_6 F_198 ( struct V_169 * V_170 , struct V_171 * V_172 ,
const char * V_173 , T_7 V_174 )
{
int V_68 ;
unsigned long V_82 ;
V_68 = F_194 ( V_173 , 10 , & V_82 ) ;
if ( V_68 || V_82 > V_176 )
return - V_177 ;
if ( V_82 > V_137 )
return - V_177 ;
F_149 ( & V_122 ) ;
F_150 () ;
if ( V_119 != V_82 ) {
V_119 = V_82 ;
if ( V_82 & V_137 ) {
F_199 () ;
V_68 = F_68 () ;
F_200 () ;
if ( V_68 ) {
V_119 = V_178 ;
V_174 = V_68 ;
}
}
}
F_151 ( & V_122 ) ;
if ( V_82 & V_120 )
F_163 ( & V_125 ) ;
return V_174 ;
}
static T_6 F_201 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_1 , V_39 ) ;
}
static T_6 F_202 ( struct V_169 * V_170 ,
struct V_171 * V_172 ,
const char * V_173 , T_7 V_174 )
{
int V_68 ;
unsigned long V_179 ;
V_68 = F_194 ( V_173 , 10 , & V_179 ) ;
if ( V_68 )
return V_68 ;
if ( V_179 > 1 )
return - V_177 ;
F_149 ( & V_122 ) ;
F_150 () ;
if ( V_39 != V_179 ) {
if ( V_43 || F_65 () )
V_68 = - V_72 ;
else if ( V_49 == V_180 ) {
struct V_104 * V_173 ;
V_173 = F_203 ( V_181 + V_181 , sizeof( * V_173 ) ,
V_11 ) ;
if ( ! V_173 )
V_68 = - V_10 ;
else {
V_49 = V_173 ;
V_63 = V_173 + V_181 ;
V_63 [ 0 ] = V_182 [ 0 ] ;
}
}
if ( ! V_68 ) {
V_39 = V_179 ;
V_73 = V_179 ? 1 : V_181 ;
}
}
F_151 ( & V_122 ) ;
return V_68 ? V_68 : V_174 ;
}
static T_6 F_204 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_2 , V_43 ) ;
}
static T_6 F_205 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_2 , V_42 ) ;
}
static T_6 F_206 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_2 , V_64 ) ;
}
static T_6 F_207 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
long V_183 ;
V_183 = V_12 - V_43
- V_42 - V_64 ;
if ( V_183 < 0 )
V_183 = 0 ;
return sprintf ( V_173 , L_3 , V_183 ) ;
}
static T_6 F_208 ( struct V_169 * V_170 ,
struct V_171 * V_172 , char * V_173 )
{
return sprintf ( V_173 , L_2 , V_61 . V_62 ) ;
}
static int T_1 F_209 ( void )
{
struct V_184 * V_185 ;
int V_68 ;
V_68 = F_1 () ;
if ( V_68 )
goto V_3;
V_185 = F_210 ( F_145 , NULL , L_4 ) ;
if ( F_211 ( V_185 ) ) {
F_212 ( L_5 ) ;
V_68 = F_213 ( V_185 ) ;
goto V_186;
}
#ifdef F_214
V_68 = F_215 ( V_187 , & V_188 ) ;
if ( V_68 ) {
F_212 ( L_6 ) ;
F_216 ( V_185 ) ;
goto V_186;
}
#else
V_119 = V_120 ;
#endif
#ifdef F_217
F_218 ( F_189 , 100 ) ;
#endif
return 0 ;
V_186:
F_4 () ;
V_3:
return V_68 ;
}
