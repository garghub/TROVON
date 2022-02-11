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
static struct V_8 * F_14 ( struct V_16 * V_15 )
{
struct V_8 * V_17 ;
F_15 (mm_slots_hash, slot, link, (unsigned long)mm)
if ( V_17 -> V_15 == V_15 )
return V_17 ;
return NULL ;
}
static void F_16 ( struct V_16 * V_15 ,
struct V_8 * V_8 )
{
V_8 -> V_15 = V_15 ;
F_17 ( V_18 , & V_8 -> V_19 , ( unsigned long ) V_15 ) ;
}
static inline bool F_18 ( struct V_16 * V_15 )
{
return F_19 ( & V_15 -> V_20 ) == 0 ;
}
static int F_20 ( struct V_21 * V_22 , unsigned long V_23 )
{
struct V_24 * V_24 ;
int V_25 = 0 ;
do {
F_21 () ;
V_24 = F_22 ( V_22 , V_23 ,
V_26 | V_27 | V_28 ) ;
if ( F_23 ( V_24 ) )
break;
if ( F_24 ( V_24 ) )
V_25 = F_25 ( V_22 , V_23 ,
V_29 | V_30 ) ;
else
V_25 = V_31 ;
F_26 ( V_24 ) ;
} while ( ! ( V_25 & ( V_31 | V_32 | V_33 | V_34 ) ) );
return ( V_25 & V_34 ) ? - V_10 : 0 ;
}
static struct V_21 * F_27 ( struct V_16 * V_15 ,
unsigned long V_23 )
{
struct V_21 * V_22 ;
if ( F_18 ( V_15 ) )
return NULL ;
V_22 = F_28 ( V_15 , V_23 ) ;
if ( ! V_22 || V_22 -> V_35 > V_23 )
return NULL ;
if ( ! ( V_22 -> V_36 & V_37 ) || ! V_22 -> V_38 )
return NULL ;
return V_22 ;
}
static void F_29 ( struct V_2 * V_2 )
{
struct V_16 * V_15 = V_2 -> V_15 ;
unsigned long V_23 = V_2 -> V_39 ;
struct V_21 * V_22 ;
F_30 ( V_2 -> V_38 ) ;
F_31 ( & V_15 -> V_40 ) ;
V_22 = F_27 ( V_15 , V_23 ) ;
if ( V_22 )
F_20 ( V_22 , V_23 ) ;
F_32 ( & V_15 -> V_40 ) ;
}
static struct V_24 * F_33 ( struct V_2 * V_2 )
{
struct V_16 * V_15 = V_2 -> V_15 ;
unsigned long V_23 = V_2 -> V_39 ;
struct V_21 * V_22 ;
struct V_24 * V_24 ;
F_31 ( & V_15 -> V_40 ) ;
V_22 = F_27 ( V_15 , V_23 ) ;
if ( ! V_22 )
goto V_3;
V_24 = F_22 ( V_22 , V_23 , V_26 ) ;
if ( F_23 ( V_24 ) )
goto V_3;
if ( F_34 ( V_24 ) ) {
F_35 ( V_22 , V_24 , V_23 ) ;
F_36 ( V_24 ) ;
} else {
F_26 ( V_24 ) ;
V_3:
V_24 = NULL ;
}
F_32 ( & V_15 -> V_40 ) ;
return V_24 ;
}
static inline int F_37 ( unsigned long V_41 )
{
return V_42 ? 0 : F_38 ( F_39 ( V_41 ) ) ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_41 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_43 . V_44 )
V_45 -- ;
else
V_46 -- ;
F_30 ( V_2 -> V_38 ) ;
V_2 -> V_39 &= V_47 ;
F_21 () ;
}
if ( V_5 -> V_48 == & V_49 )
F_42 ( & V_5 -> V_50 ) ;
else
F_43 ( & V_5 -> V_51 ,
V_52 + F_38 ( V_5 -> V_53 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_24 * F_44 ( struct V_5 * V_5 , bool V_54 )
{
struct V_24 * V_24 ;
void * V_55 ;
unsigned long V_41 ;
V_55 = ( void * ) ( ( unsigned long ) V_5 |
V_56 ) ;
V_57:
V_41 = F_45 ( V_5 -> V_41 ) ;
V_24 = F_46 ( V_41 ) ;
F_47 () ;
if ( F_45 ( V_24 -> V_58 ) != V_55 )
goto V_59;
while ( ! F_48 ( V_24 ) ) {
if ( ! F_49 ( V_24 ) )
goto V_59;
F_50 () ;
}
if ( F_45 ( V_24 -> V_58 ) != V_55 ) {
F_26 ( V_24 ) ;
goto V_59;
}
if ( V_54 ) {
F_51 ( V_24 ) ;
if ( F_45 ( V_24 -> V_58 ) != V_55 ) {
F_52 ( V_24 ) ;
F_26 ( V_24 ) ;
goto V_59;
}
}
return V_24 ;
V_59:
F_53 () ;
if ( F_45 ( V_5 -> V_41 ) != V_41 )
goto V_57;
F_40 ( V_5 ) ;
return NULL ;
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_39 & V_60 ) {
struct V_5 * V_5 ;
struct V_24 * V_24 ;
V_5 = V_2 -> V_48 ;
V_24 = F_44 ( V_5 , true ) ;
if ( ! V_24 )
goto V_3;
F_55 ( & V_2 -> V_43 ) ;
F_52 ( V_24 ) ;
F_26 ( V_24 ) ;
if ( ! F_56 ( & V_5 -> V_43 ) )
V_45 -- ;
else
V_46 -- ;
F_30 ( V_2 -> V_38 ) ;
V_2 -> V_39 &= V_47 ;
} else if ( V_2 -> V_39 & V_61 ) {
unsigned char V_62 ;
V_62 = ( unsigned char ) ( V_63 . V_64 - V_2 -> V_39 ) ;
F_57 ( V_62 > 1 ) ;
if ( ! V_62 )
F_43 ( & V_2 -> V_51 ,
V_65 + F_38 ( V_2 -> V_53 ) ) ;
V_66 -- ;
V_2 -> V_39 &= V_47 ;
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
static int F_59 ( struct V_21 * V_22 ,
unsigned long V_68 , unsigned long V_69 )
{
unsigned long V_23 ;
int V_70 = 0 ;
for ( V_23 = V_68 ; V_23 < V_69 && ! V_70 ; V_23 += V_71 ) {
if ( F_18 ( V_22 -> V_72 ) )
break;
if ( F_60 ( V_73 ) )
V_70 = - V_74 ;
else
V_70 = F_20 ( V_22 , V_23 ) ;
}
return V_70 ;
}
static int F_61 ( struct V_5 * V_5 )
{
struct V_24 * V_24 ;
int V_70 ;
V_24 = F_44 ( V_5 , true ) ;
if ( ! V_24 ) {
return 0 ;
}
if ( F_62 ( F_63 ( V_24 ) ) ) {
V_70 = - V_75 ;
} else {
F_64 ( V_24 , NULL ) ;
F_40 ( V_5 ) ;
V_70 = 0 ;
}
F_52 ( V_24 ) ;
F_26 ( V_24 ) ;
return V_70 ;
}
static int F_65 ( void )
{
struct V_5 * V_5 , * V_44 ;
int V_53 ;
int V_70 = 0 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
while ( V_52 [ V_53 ] . V_77 ) {
V_5 = F_66 ( V_52 [ V_53 ] . V_77 ,
struct V_5 , V_51 ) ;
if ( F_61 ( V_5 ) ) {
V_70 = - V_75 ;
break;
}
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( F_61 ( V_5 ) )
V_70 = - V_75 ;
F_21 () ;
}
return V_70 ;
}
static int F_68 ( void )
{
struct V_8 * V_8 ;
struct V_16 * V_15 ;
struct V_21 * V_22 ;
int V_70 = 0 ;
F_69 ( & V_78 ) ;
V_63 . V_8 = F_70 ( V_79 . V_80 . V_44 ,
struct V_8 , V_80 ) ;
F_71 ( & V_78 ) ;
for ( V_8 = V_63 . V_8 ;
V_8 != & V_79 ; V_8 = V_63 . V_8 ) {
V_15 = V_8 -> V_15 ;
F_31 ( & V_15 -> V_40 ) ;
for ( V_22 = V_15 -> V_81 ; V_22 ; V_22 = V_22 -> V_82 ) {
if ( F_18 ( V_15 ) )
break;
if ( ! ( V_22 -> V_36 & V_37 ) || ! V_22 -> V_38 )
continue;
V_70 = F_59 ( V_22 ,
V_22 -> V_35 , V_22 -> V_83 ) ;
if ( V_70 )
goto error;
}
F_58 ( V_8 , & V_8 -> V_67 ) ;
F_32 ( & V_15 -> V_40 ) ;
F_69 ( & V_78 ) ;
V_63 . V_8 = F_70 ( V_8 -> V_80 . V_44 ,
struct V_8 , V_80 ) ;
if ( F_18 ( V_15 ) ) {
F_72 ( & V_8 -> V_19 ) ;
F_42 ( & V_8 -> V_80 ) ;
F_71 ( & V_78 ) ;
F_13 ( V_8 ) ;
F_73 ( V_84 , & V_15 -> V_85 ) ;
F_74 ( V_15 ) ;
} else
F_71 ( & V_78 ) ;
}
F_65 () ;
V_63 . V_64 = 0 ;
return 0 ;
error:
F_32 ( & V_15 -> V_40 ) ;
F_69 ( & V_78 ) ;
V_63 . V_8 = & V_79 ;
F_71 ( & V_78 ) ;
return V_70 ;
}
static T_2 F_75 ( struct V_24 * V_24 )
{
T_2 V_86 ;
void * V_23 = F_76 ( V_24 ) ;
V_86 = F_77 ( V_23 , V_71 / 4 , 17 ) ;
F_78 ( V_23 ) ;
return V_86 ;
}
static int F_79 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
char * V_89 , * V_90 ;
int V_25 ;
V_89 = F_76 ( V_87 ) ;
V_90 = F_76 ( V_88 ) ;
V_25 = memcmp ( V_89 , V_90 , V_71 ) ;
F_78 ( V_90 ) ;
F_78 ( V_89 ) ;
return V_25 ;
}
static inline int F_80 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
return ! F_79 ( V_87 , V_88 ) ;
}
static int F_81 ( struct V_21 * V_22 , struct V_24 * V_24 ,
T_3 * V_91 )
{
struct V_16 * V_15 = V_22 -> V_72 ;
unsigned long V_23 ;
T_3 * V_92 ;
T_4 * V_93 ;
int V_94 ;
int V_70 = - V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
V_23 = F_82 ( V_24 , V_22 ) ;
if ( V_23 == - V_95 )
goto V_3;
F_57 ( F_83 ( V_24 ) ) ;
V_96 = V_23 ;
V_97 = V_23 + V_71 ;
F_84 ( V_15 , V_96 , V_97 ) ;
V_92 = F_85 ( V_24 , V_15 , V_23 , & V_93 , 0 ) ;
if ( ! V_92 )
goto V_98;
if ( F_86 ( * V_92 ) || F_87 ( * V_92 ) ) {
T_3 V_99 ;
V_94 = F_49 ( V_24 ) ;
F_88 ( V_22 , V_23 , F_89 ( V_24 ) ) ;
V_99 = F_90 ( V_22 , V_23 , V_92 ) ;
if ( F_91 ( V_24 ) + 1 + V_94 != F_92 ( V_24 ) ) {
F_93 ( V_15 , V_23 , V_92 , V_99 ) ;
goto V_100;
}
if ( F_87 ( V_99 ) )
F_94 ( V_24 ) ;
V_99 = F_95 ( F_96 ( V_99 ) ) ;
F_97 ( V_15 , V_23 , V_92 , V_99 ) ;
}
* V_91 = * V_92 ;
V_70 = 0 ;
V_100:
F_98 ( V_92 , V_93 ) ;
V_98:
F_99 ( V_15 , V_96 , V_97 ) ;
V_3:
return V_70 ;
}
static int F_100 ( struct V_21 * V_22 , struct V_24 * V_24 ,
struct V_24 * V_101 , T_3 V_91 )
{
struct V_16 * V_15 = V_22 -> V_72 ;
T_5 * V_102 ;
T_3 * V_92 ;
T_4 * V_93 ;
unsigned long V_23 ;
int V_70 = - V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
V_23 = F_82 ( V_24 , V_22 ) ;
if ( V_23 == - V_95 )
goto V_3;
V_102 = F_101 ( V_15 , V_23 ) ;
if ( ! V_102 )
goto V_3;
V_96 = V_23 ;
V_97 = V_23 + V_71 ;
F_84 ( V_15 , V_96 , V_97 ) ;
V_92 = F_102 ( V_15 , V_102 , V_23 , & V_93 ) ;
if ( ! F_103 ( * V_92 , V_91 ) ) {
F_98 ( V_92 , V_93 ) ;
goto V_98;
}
F_104 ( V_101 ) ;
F_105 ( V_101 , V_22 , V_23 , false ) ;
F_88 ( V_22 , V_23 , F_106 ( * V_92 ) ) ;
F_90 ( V_22 , V_23 , V_92 ) ;
F_97 ( V_15 , V_23 , V_92 , F_107 ( V_101 , V_22 -> V_103 ) ) ;
F_108 ( V_24 , false ) ;
if ( ! F_63 ( V_24 ) )
F_109 ( V_24 ) ;
F_26 ( V_24 ) ;
F_98 ( V_92 , V_93 ) ;
V_70 = 0 ;
V_98:
F_99 ( V_15 , V_96 , V_97 ) ;
V_3:
return V_70 ;
}
static int F_110 ( struct V_21 * V_22 ,
struct V_24 * V_24 , struct V_24 * V_101 )
{
T_3 V_91 = F_111 ( 0 ) ;
int V_70 = - V_95 ;
if ( V_24 == V_101 )
return 0 ;
if ( ! F_34 ( V_24 ) )
goto V_3;
if ( ! F_112 ( V_24 ) )
goto V_3;
if ( F_83 ( V_24 ) ) {
V_70 = F_113 ( V_24 ) ;
if ( V_70 )
goto V_100;
}
if ( F_81 ( V_22 , V_24 , & V_91 ) == 0 ) {
if ( ! V_101 ) {
F_64 ( V_24 , NULL ) ;
F_114 ( V_24 ) ;
if ( ! F_115 ( V_24 ) )
F_116 ( V_24 ) ;
V_70 = 0 ;
} else if ( F_80 ( V_24 , V_101 ) )
V_70 = F_100 ( V_22 , V_24 , V_101 , V_91 ) ;
}
if ( ( V_22 -> V_36 & V_104 ) && V_101 && ! V_70 ) {
F_117 ( V_24 ) ;
if ( ! F_118 ( V_101 ) ) {
F_52 ( V_24 ) ;
F_51 ( V_101 ) ;
F_119 ( V_101 ) ;
V_24 = V_101 ;
}
}
V_100:
F_52 ( V_24 ) ;
V_3:
return V_70 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_24 * V_24 , struct V_24 * V_101 )
{
struct V_16 * V_15 = V_2 -> V_15 ;
struct V_21 * V_22 ;
int V_70 = - V_95 ;
F_31 ( & V_15 -> V_40 ) ;
V_22 = F_27 ( V_15 , V_2 -> V_39 ) ;
if ( ! V_22 )
goto V_3;
V_70 = F_110 ( V_22 , V_24 , V_101 ) ;
if ( V_70 )
goto V_3;
F_54 ( V_2 ) ;
V_2 -> V_38 = V_22 -> V_38 ;
F_121 ( V_22 -> V_38 ) ;
V_3:
F_32 ( & V_15 -> V_40 ) ;
return V_70 ;
}
static struct V_24 * F_122 ( struct V_2 * V_2 ,
struct V_24 * V_24 ,
struct V_2 * V_105 ,
struct V_24 * V_106 )
{
int V_70 ;
V_70 = F_120 ( V_2 , V_24 , NULL ) ;
if ( ! V_70 ) {
V_70 = F_120 ( V_105 ,
V_106 , V_24 ) ;
if ( V_70 )
F_29 ( V_2 ) ;
}
return V_70 ? NULL : V_24 ;
}
static struct V_24 * F_123 ( struct V_24 * V_24 )
{
int V_53 ;
struct V_107 * V_108 ;
struct V_77 * * V_109 ;
struct V_77 * V_110 ;
struct V_5 * V_5 ;
struct V_5 * V_111 ;
V_111 = F_124 ( V_24 ) ;
if ( V_111 && V_111 -> V_48 != & V_49 ) {
F_104 ( V_24 ) ;
return V_24 ;
}
V_53 = F_37 ( F_89 ( V_24 ) ) ;
V_108 = V_52 + V_53 ;
V_57:
V_109 = & V_108 -> V_77 ;
V_110 = NULL ;
while ( * V_109 ) {
struct V_24 * V_106 ;
int V_25 ;
F_21 () ;
V_5 = F_66 ( * V_109 , struct V_5 , V_51 ) ;
V_106 = F_44 ( V_5 , false ) ;
if ( ! V_106 ) {
goto V_57;
}
V_25 = F_79 ( V_24 , V_106 ) ;
F_26 ( V_106 ) ;
V_110 = * V_109 ;
if ( V_25 < 0 )
V_109 = & V_110 -> V_112 ;
else if ( V_25 > 0 )
V_109 = & V_110 -> V_113 ;
else {
V_106 = F_44 ( V_5 , true ) ;
if ( V_106 ) {
F_52 ( V_106 ) ;
if ( F_37 ( V_5 -> V_41 ) !=
F_38 ( V_5 -> V_53 ) ) {
F_26 ( V_106 ) ;
goto V_114;
}
return V_106 ;
}
if ( V_111 )
goto V_57;
return NULL ;
}
}
if ( ! V_111 )
return NULL ;
F_42 ( & V_111 -> V_50 ) ;
F_125 ( V_111 -> V_53 = V_53 ) ;
F_126 ( & V_111 -> V_51 , V_110 , V_109 ) ;
F_127 ( & V_111 -> V_51 , V_108 ) ;
F_104 ( V_24 ) ;
return V_24 ;
V_114:
if ( V_111 ) {
F_42 ( & V_111 -> V_50 ) ;
F_125 ( V_111 -> V_53 = V_53 ) ;
F_128 ( & V_5 -> V_51 , & V_111 -> V_51 , V_108 ) ;
F_104 ( V_24 ) ;
} else {
F_43 ( & V_5 -> V_51 , V_108 ) ;
V_24 = NULL ;
}
V_5 -> V_48 = & V_49 ;
F_129 ( & V_5 -> V_50 , V_5 -> V_48 ) ;
return V_24 ;
}
static struct V_5 * F_130 ( struct V_24 * V_101 )
{
int V_53 ;
unsigned long V_41 ;
struct V_107 * V_108 ;
struct V_77 * * V_109 ;
struct V_77 * V_110 ;
struct V_5 * V_5 ;
V_41 = F_89 ( V_101 ) ;
V_53 = F_37 ( V_41 ) ;
V_108 = V_52 + V_53 ;
V_57:
V_110 = NULL ;
V_109 = & V_108 -> V_77 ;
while ( * V_109 ) {
struct V_24 * V_106 ;
int V_25 ;
F_21 () ;
V_5 = F_66 ( * V_109 , struct V_5 , V_51 ) ;
V_106 = F_44 ( V_5 , false ) ;
if ( ! V_106 ) {
goto V_57;
}
V_25 = F_79 ( V_101 , V_106 ) ;
F_26 ( V_106 ) ;
V_110 = * V_109 ;
if ( V_25 < 0 )
V_109 = & V_110 -> V_112 ;
else if ( V_25 > 0 )
V_109 = & V_110 -> V_113 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_43 ) ;
V_5 -> V_41 = V_41 ;
F_64 ( V_101 , V_5 ) ;
F_125 ( V_5 -> V_53 = V_53 ) ;
F_126 ( & V_5 -> V_51 , V_110 , V_109 ) ;
F_127 ( & V_5 -> V_51 , V_108 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_24 * V_24 ,
struct V_24 * * V_115 )
{
struct V_77 * * V_109 ;
struct V_107 * V_108 ;
struct V_77 * V_110 = NULL ;
int V_53 ;
V_53 = F_37 ( F_89 ( V_24 ) ) ;
V_108 = V_65 + V_53 ;
V_109 = & V_108 -> V_77 ;
while ( * V_109 ) {
struct V_2 * V_105 ;
struct V_24 * V_106 ;
int V_25 ;
F_21 () ;
V_105 = F_66 ( * V_109 , struct V_2 , V_51 ) ;
V_106 = F_33 ( V_105 ) ;
if ( ! V_106 )
return NULL ;
if ( V_24 == V_106 ) {
F_26 ( V_106 ) ;
return NULL ;
}
V_25 = F_79 ( V_24 , V_106 ) ;
V_110 = * V_109 ;
if ( V_25 < 0 ) {
F_26 ( V_106 ) ;
V_109 = & V_110 -> V_112 ;
} else if ( V_25 > 0 ) {
F_26 ( V_106 ) ;
V_109 = & V_110 -> V_113 ;
} else if ( ! V_42 &&
F_133 ( V_106 ) != V_53 ) {
F_26 ( V_106 ) ;
return NULL ;
} else {
* V_115 = V_106 ;
return V_105 ;
}
}
V_2 -> V_39 |= V_61 ;
V_2 -> V_39 |= ( V_63 . V_64 & V_116 ) ;
F_125 ( V_2 -> V_53 = V_53 ) ;
F_126 ( & V_2 -> V_51 , V_110 , V_109 ) ;
F_127 ( & V_2 -> V_51 , V_108 ) ;
V_66 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_48 = V_5 ;
V_2 -> V_39 |= V_60 ;
F_135 ( & V_2 -> V_43 , & V_5 -> V_43 ) ;
if ( V_2 -> V_43 . V_44 )
V_45 ++ ;
else
V_46 ++ ;
}
static void F_136 ( struct V_24 * V_24 , struct V_2 * V_2 )
{
struct V_2 * V_105 ;
struct V_24 * V_106 = NULL ;
struct V_5 * V_5 ;
struct V_24 * V_101 ;
unsigned int V_86 ;
int V_70 ;
V_5 = F_124 ( V_24 ) ;
if ( V_5 ) {
if ( V_5 -> V_48 != & V_49 &&
F_37 ( V_5 -> V_41 ) != F_38 ( V_5 -> V_53 ) ) {
F_43 ( & V_5 -> V_51 ,
V_52 + F_38 ( V_5 -> V_53 ) ) ;
V_5 -> V_48 = & V_49 ;
F_129 ( & V_5 -> V_50 , V_5 -> V_48 ) ;
}
if ( V_5 -> V_48 != & V_49 &&
V_2 -> V_48 == V_5 )
return;
}
V_101 = F_123 ( V_24 ) ;
if ( V_101 == V_24 && V_2 -> V_48 == V_5 ) {
F_26 ( V_101 ) ;
return;
}
F_54 ( V_2 ) ;
if ( V_101 ) {
V_70 = F_120 ( V_2 , V_24 , V_101 ) ;
if ( ! V_70 ) {
F_51 ( V_101 ) ;
F_134 ( V_2 , F_124 ( V_101 ) ) ;
F_52 ( V_101 ) ;
}
F_26 ( V_101 ) ;
return;
}
V_86 = F_75 ( V_24 ) ;
if ( V_2 -> V_117 != V_86 ) {
V_2 -> V_117 = V_86 ;
return;
}
V_105 =
F_132 ( V_2 , V_24 , & V_106 ) ;
if ( V_105 ) {
V_101 = F_122 ( V_2 , V_24 ,
V_105 , V_106 ) ;
F_26 ( V_106 ) ;
if ( V_101 ) {
F_51 ( V_101 ) ;
V_5 = F_130 ( V_101 ) ;
if ( V_5 ) {
F_134 ( V_105 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_52 ( V_101 ) ;
if ( ! V_5 ) {
F_29 ( V_105 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_137 ( struct V_8 * V_8 ,
struct V_2 * * V_67 ,
unsigned long V_23 )
{
struct V_2 * V_2 ;
while ( * V_67 ) {
V_2 = * V_67 ;
if ( ( V_2 -> V_39 & V_47 ) == V_23 )
return V_2 ;
if ( V_2 -> V_39 > V_23 )
break;
* V_67 = V_2 -> V_67 ;
F_54 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_15 = V_8 -> V_15 ;
V_2 -> V_39 = V_23 ;
V_2 -> V_67 = * V_67 ;
* V_67 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_138 ( struct V_24 * * V_24 )
{
struct V_16 * V_15 ;
struct V_8 * V_17 ;
struct V_21 * V_22 ;
struct V_2 * V_2 ;
int V_53 ;
if ( F_139 ( & V_79 . V_80 ) )
return NULL ;
V_17 = V_63 . V_8 ;
if ( V_17 == & V_79 ) {
F_140 () ;
if ( ! V_42 ) {
struct V_5 * V_5 , * V_44 ;
struct V_24 * V_24 ;
F_67 (stable_node, next,
&migrate_nodes, list) {
V_24 = F_44 ( V_5 , false ) ;
if ( V_24 )
F_26 ( V_24 ) ;
F_21 () ;
}
}
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ )
V_65 [ V_53 ] = V_118 ;
F_69 ( & V_78 ) ;
V_17 = F_70 ( V_17 -> V_80 . V_44 , struct V_8 , V_80 ) ;
V_63 . V_8 = V_17 ;
F_71 ( & V_78 ) ;
if ( V_17 == & V_79 )
return NULL ;
V_119:
V_63 . V_39 = 0 ;
V_63 . V_67 = & V_17 -> V_67 ;
}
V_15 = V_17 -> V_15 ;
F_31 ( & V_15 -> V_40 ) ;
if ( F_18 ( V_15 ) )
V_22 = NULL ;
else
V_22 = F_28 ( V_15 , V_63 . V_39 ) ;
for (; V_22 ; V_22 = V_22 -> V_82 ) {
if ( ! ( V_22 -> V_36 & V_37 ) )
continue;
if ( V_63 . V_39 < V_22 -> V_35 )
V_63 . V_39 = V_22 -> V_35 ;
if ( ! V_22 -> V_38 )
V_63 . V_39 = V_22 -> V_83 ;
while ( V_63 . V_39 < V_22 -> V_83 ) {
if ( F_18 ( V_15 ) )
break;
* V_24 = F_22 ( V_22 , V_63 . V_39 , V_26 ) ;
if ( F_23 ( * V_24 ) ) {
V_63 . V_39 += V_71 ;
F_21 () ;
continue;
}
if ( F_34 ( * V_24 ) ) {
F_35 ( V_22 , * V_24 , V_63 . V_39 ) ;
F_36 ( * V_24 ) ;
V_2 = F_137 ( V_17 ,
V_63 . V_67 , V_63 . V_39 ) ;
if ( V_2 ) {
V_63 . V_67 =
& V_2 -> V_67 ;
V_63 . V_39 += V_71 ;
} else
F_26 ( * V_24 ) ;
F_32 ( & V_15 -> V_40 ) ;
return V_2 ;
}
F_26 ( * V_24 ) ;
V_63 . V_39 += V_71 ;
F_21 () ;
}
}
if ( F_18 ( V_15 ) ) {
V_63 . V_39 = 0 ;
V_63 . V_67 = & V_17 -> V_67 ;
}
F_58 ( V_17 , V_63 . V_67 ) ;
F_69 ( & V_78 ) ;
V_63 . V_8 = F_70 ( V_17 -> V_80 . V_44 ,
struct V_8 , V_80 ) ;
if ( V_63 . V_39 == 0 ) {
F_72 ( & V_17 -> V_19 ) ;
F_42 ( & V_17 -> V_80 ) ;
F_71 ( & V_78 ) ;
F_13 ( V_17 ) ;
F_73 ( V_84 , & V_15 -> V_85 ) ;
F_32 ( & V_15 -> V_40 ) ;
F_74 ( V_15 ) ;
} else {
F_32 ( & V_15 -> V_40 ) ;
F_71 ( & V_78 ) ;
}
V_17 = V_63 . V_8 ;
if ( V_17 != & V_79 )
goto V_119;
V_63 . V_64 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_120 )
{
struct V_2 * V_2 ;
struct V_24 * V_121 ( V_24 ) ;
while ( V_120 -- && F_142 ( ! F_143 ( V_73 ) ) ) {
F_21 () ;
V_2 = F_138 ( & V_24 ) ;
if ( ! V_2 )
return;
F_136 ( V_24 , V_2 ) ;
F_26 ( V_24 ) ;
}
}
static int F_144 ( void )
{
return ( V_122 & V_123 ) && ! F_139 ( & V_79 . V_80 ) ;
}
static int F_145 ( void * V_124 )
{
F_146 () ;
F_147 ( V_73 , 5 ) ;
while ( ! F_148 () ) {
F_149 ( & V_125 ) ;
F_150 () ;
if ( F_144 () )
F_141 ( V_126 ) ;
F_151 ( & V_125 ) ;
F_152 () ;
if ( F_144 () ) {
F_153 (
F_154 ( V_127 ) ) ;
} else {
F_155 ( V_128 ,
F_144 () || F_148 () ) ;
}
}
return 0 ;
}
int F_156 ( struct V_21 * V_22 , unsigned long V_68 ,
unsigned long V_69 , int V_129 , unsigned long * V_36 )
{
struct V_16 * V_15 = V_22 -> V_72 ;
int V_70 ;
switch ( V_129 ) {
case V_130 :
if ( * V_36 & ( V_37 | V_131 | V_132 |
V_133 | V_134 | V_135 |
V_136 | V_137 ) )
return 0 ;
#ifdef F_157
if ( * V_36 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_84 , & V_15 -> V_85 ) ) {
V_70 = F_159 ( V_15 ) ;
if ( V_70 )
return V_70 ;
}
* V_36 |= V_37 ;
break;
case V_138 :
if ( ! ( * V_36 & V_37 ) )
return 0 ;
if ( V_22 -> V_38 ) {
V_70 = F_59 ( V_22 , V_68 , V_69 ) ;
if ( V_70 )
return V_70 ;
}
* V_36 &= ~ V_37 ;
break;
}
return 0 ;
}
int F_159 ( struct V_16 * V_15 )
{
struct V_8 * V_8 ;
int V_139 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_139 = F_139 ( & V_79 . V_80 ) ;
F_69 ( & V_78 ) ;
F_16 ( V_15 , V_8 ) ;
if ( V_122 & V_140 )
F_160 ( & V_8 -> V_80 , & V_79 . V_80 ) ;
else
F_160 ( & V_8 -> V_80 , & V_63 . V_8 -> V_80 ) ;
F_71 ( & V_78 ) ;
F_161 ( V_84 , & V_15 -> V_85 ) ;
F_162 ( & V_15 -> V_141 ) ;
if ( V_139 )
F_163 ( & V_128 ) ;
return 0 ;
}
void F_164 ( struct V_16 * V_15 )
{
struct V_8 * V_8 ;
int V_142 = 0 ;
F_69 ( & V_78 ) ;
V_8 = F_14 ( V_15 ) ;
if ( V_8 && V_63 . V_8 != V_8 ) {
if ( ! V_8 -> V_67 ) {
F_72 ( & V_8 -> V_19 ) ;
F_42 ( & V_8 -> V_80 ) ;
V_142 = 1 ;
} else {
F_165 ( & V_8 -> V_80 ,
& V_63 . V_8 -> V_80 ) ;
}
}
F_71 ( & V_78 ) ;
if ( V_142 ) {
F_13 ( V_8 ) ;
F_73 ( V_84 , & V_15 -> V_85 ) ;
F_74 ( V_15 ) ;
} else if ( V_8 ) {
F_166 ( & V_15 -> V_40 ) ;
F_167 ( & V_15 -> V_40 ) ;
}
}
struct V_24 * F_168 ( struct V_24 * V_24 ,
struct V_21 * V_22 , unsigned long V_39 )
{
struct V_38 * V_38 = F_169 ( V_24 ) ;
struct V_24 * V_143 ;
if ( F_24 ( V_24 ) ) {
if ( F_124 ( V_24 ) &&
! ( V_122 & V_140 ) )
return V_24 ;
} else if ( ! V_38 ) {
return V_24 ;
} else if ( V_38 -> V_108 == V_22 -> V_38 -> V_108 &&
V_24 -> V_144 == F_170 ( V_22 , V_39 ) ) {
return V_24 ;
}
if ( ! F_171 ( V_24 ) )
return V_24 ;
V_143 = F_172 ( V_145 , V_22 , V_39 ) ;
if ( V_143 ) {
F_173 ( V_143 , V_24 , V_39 , V_22 ) ;
F_116 ( V_143 ) ;
F_174 ( V_143 ) ;
F_175 ( V_143 ) ;
}
return V_143 ;
}
int F_176 ( struct V_24 * V_24 , struct V_146 * V_147 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_25 = V_148 ;
int V_149 = 0 ;
F_177 ( ! F_24 ( V_24 ) , V_24 ) ;
F_177 ( ! F_178 ( V_24 ) , V_24 ) ;
V_5 = F_124 ( V_24 ) ;
if ( ! V_5 )
return V_25 ;
V_57:
F_41 (rmap_item, &stable_node->hlist, hlist) {
struct V_38 * V_38 = V_2 -> V_38 ;
struct V_150 * V_151 ;
struct V_21 * V_22 ;
F_21 () ;
F_179 ( V_38 ) ;
F_180 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
F_21 () ;
V_22 = V_151 -> V_22 ;
if ( V_2 -> V_39 < V_22 -> V_35 ||
V_2 -> V_39 >= V_22 -> V_83 )
continue;
if ( ( V_2 -> V_15 == V_22 -> V_72 ) == V_149 )
continue;
if ( V_147 -> V_152 && V_147 -> V_152 ( V_22 , V_147 -> V_153 ) )
continue;
V_25 = V_147 -> V_154 ( V_24 , V_22 ,
V_2 -> V_39 , V_147 -> V_153 ) ;
if ( V_25 != V_148 ) {
F_181 ( V_38 ) ;
goto V_3;
}
if ( V_147 -> V_155 && V_147 -> V_155 ( V_24 ) ) {
F_181 ( V_38 ) ;
goto V_3;
}
}
F_181 ( V_38 ) ;
}
if ( ! V_149 ++ )
goto V_57;
V_3:
return V_25 ;
}
void F_182 ( struct V_24 * V_156 , struct V_24 * V_157 )
{
struct V_5 * V_5 ;
F_177 ( ! F_178 ( V_157 ) , V_157 ) ;
F_177 ( ! F_178 ( V_156 ) , V_156 ) ;
F_177 ( V_156 -> V_58 != V_157 -> V_58 , V_156 ) ;
V_5 = F_124 ( V_156 ) ;
if ( V_5 ) {
F_177 ( V_5 -> V_41 != F_89 ( V_157 ) , V_157 ) ;
V_5 -> V_41 = F_89 ( V_156 ) ;
F_183 () ;
F_64 ( V_157 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_122 & V_158 ) {
F_151 ( & V_125 ) ;
F_184 ( & V_122 , F_185 ( V_158 ) ,
V_159 ) ;
F_149 ( & V_125 ) ;
}
}
static void F_186 ( unsigned long V_160 ,
unsigned long V_161 )
{
struct V_5 * V_5 , * V_44 ;
struct V_77 * V_51 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
V_51 = F_187 ( V_52 + V_53 ) ;
while ( V_51 ) {
V_5 = F_66 ( V_51 , struct V_5 , V_51 ) ;
if ( V_5 -> V_41 >= V_160 &&
V_5 -> V_41 < V_161 ) {
F_40 ( V_5 ) ;
V_51 = F_187 ( V_52 + V_53 ) ;
} else
V_51 = F_188 ( V_51 ) ;
F_21 () ;
}
}
F_67 (stable_node, next, &migrate_nodes, list) {
if ( V_5 -> V_41 >= V_160 &&
V_5 -> V_41 < V_161 )
F_40 ( V_5 ) ;
F_21 () ;
}
}
static int F_189 ( struct V_162 * V_163 ,
unsigned long V_164 , void * V_153 )
{
struct V_165 * V_166 = V_153 ;
switch ( V_164 ) {
case V_167 :
F_149 ( & V_125 ) ;
V_122 |= V_158 ;
F_151 ( & V_125 ) ;
break;
case V_168 :
F_186 ( V_166 -> V_160 ,
V_166 -> V_160 + V_166 -> V_169 ) ;
case V_170 :
F_149 ( & V_125 ) ;
V_122 &= ~ V_158 ;
F_151 ( & V_125 ) ;
F_190 () ;
F_191 ( & V_122 , F_185 ( V_158 ) ) ;
break;
}
return V_171 ;
}
static void F_150 ( void )
{
}
static T_6 F_192 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_1 , V_127 ) ;
}
static T_6 F_193 ( struct V_172 * V_173 ,
struct V_174 * V_175 ,
const char * V_176 , T_7 V_177 )
{
unsigned long V_178 ;
int V_70 ;
V_70 = F_194 ( V_176 , 10 , & V_178 ) ;
if ( V_70 || V_178 > V_179 )
return - V_180 ;
V_127 = V_178 ;
return V_177 ;
}
static T_6 F_195 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_1 , V_126 ) ;
}
static T_6 F_196 ( struct V_172 * V_173 ,
struct V_174 * V_175 ,
const char * V_176 , T_7 V_177 )
{
int V_70 ;
unsigned long V_169 ;
V_70 = F_194 ( V_176 , 10 , & V_169 ) ;
if ( V_70 || V_169 > V_179 )
return - V_180 ;
V_126 = V_169 ;
return V_177 ;
}
static T_6 F_197 ( struct V_172 * V_173 , struct V_174 * V_175 ,
char * V_176 )
{
return sprintf ( V_176 , L_2 , V_122 ) ;
}
static T_6 F_198 ( struct V_172 * V_173 , struct V_174 * V_175 ,
const char * V_176 , T_7 V_177 )
{
int V_70 ;
unsigned long V_85 ;
V_70 = F_194 ( V_176 , 10 , & V_85 ) ;
if ( V_70 || V_85 > V_179 )
return - V_180 ;
if ( V_85 > V_140 )
return - V_180 ;
F_149 ( & V_125 ) ;
F_150 () ;
if ( V_122 != V_85 ) {
V_122 = V_85 ;
if ( V_85 & V_140 ) {
F_199 () ;
V_70 = F_68 () ;
F_200 () ;
if ( V_70 ) {
V_122 = V_181 ;
V_177 = V_70 ;
}
}
}
F_151 ( & V_125 ) ;
if ( V_85 & V_123 )
F_163 ( & V_128 ) ;
return V_177 ;
}
static T_6 F_201 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_1 , V_42 ) ;
}
static T_6 F_202 ( struct V_172 * V_173 ,
struct V_174 * V_175 ,
const char * V_176 , T_7 V_177 )
{
int V_70 ;
unsigned long V_182 ;
V_70 = F_194 ( V_176 , 10 , & V_182 ) ;
if ( V_70 )
return V_70 ;
if ( V_182 > 1 )
return - V_180 ;
F_149 ( & V_125 ) ;
F_150 () ;
if ( V_42 != V_182 ) {
if ( V_46 || F_65 () )
V_70 = - V_75 ;
else if ( V_52 == V_183 ) {
struct V_107 * V_176 ;
V_176 = F_203 ( V_184 + V_184 , sizeof( * V_176 ) ,
V_11 ) ;
if ( ! V_176 )
V_70 = - V_10 ;
else {
V_52 = V_176 ;
V_65 = V_176 + V_184 ;
V_65 [ 0 ] = V_185 [ 0 ] ;
}
}
if ( ! V_70 ) {
V_42 = V_182 ;
V_76 = V_182 ? 1 : V_184 ;
}
}
F_151 ( & V_125 ) ;
return V_70 ? V_70 : V_177 ;
}
static T_6 F_204 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_2 , V_46 ) ;
}
static T_6 F_205 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_2 , V_45 ) ;
}
static T_6 F_206 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_2 , V_66 ) ;
}
static T_6 F_207 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
long V_186 ;
V_186 = V_14 - V_46
- V_45 - V_66 ;
if ( V_186 < 0 )
V_186 = 0 ;
return sprintf ( V_176 , L_3 , V_186 ) ;
}
static T_6 F_208 ( struct V_172 * V_173 ,
struct V_174 * V_175 , char * V_176 )
{
return sprintf ( V_176 , L_2 , V_63 . V_64 ) ;
}
static int T_1 F_209 ( void )
{
struct V_187 * V_188 ;
int V_70 ;
V_70 = F_1 () ;
if ( V_70 )
goto V_3;
V_188 = F_210 ( F_145 , NULL , L_4 ) ;
if ( F_211 ( V_188 ) ) {
F_212 ( L_5 ) ;
V_70 = F_213 ( V_188 ) ;
goto V_189;
}
#ifdef F_214
V_70 = F_215 ( V_190 , & V_191 ) ;
if ( V_70 ) {
F_212 ( L_6 ) ;
F_216 ( V_188 ) ;
goto V_189;
}
#else
V_122 = V_123 ;
#endif
#ifdef F_217
F_218 ( F_189 , 100 ) ;
#endif
return 0 ;
V_189:
F_4 () ;
V_3:
return V_70 ;
}
