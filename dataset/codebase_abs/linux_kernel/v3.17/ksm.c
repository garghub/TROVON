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
} while ( ! ( V_23 & ( V_28 | V_29 | V_30 ) ) );
return ( V_23 & V_30 ) ? - V_10 : 0 ;
}
static struct V_19 * F_27 ( struct V_14 * V_13 ,
unsigned long V_21 )
{
struct V_19 * V_20 ;
if ( F_18 ( V_13 ) )
return NULL ;
V_20 = F_28 ( V_13 , V_21 ) ;
if ( ! V_20 || V_20 -> V_31 > V_21 )
return NULL ;
if ( ! ( V_20 -> V_32 & V_33 ) || ! V_20 -> V_34 )
return NULL ;
return V_20 ;
}
static void F_29 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_35 ;
struct V_19 * V_20 ;
F_30 ( V_2 -> V_34 ) ;
F_31 ( & V_13 -> V_36 ) ;
V_20 = F_27 ( V_13 , V_21 ) ;
if ( V_20 )
F_20 ( V_20 , V_21 ) ;
F_32 ( & V_13 -> V_36 ) ;
}
static struct V_22 * F_33 ( struct V_22 * V_22 )
{
if ( F_34 ( V_22 ) ) {
struct V_22 * V_37 = F_35 ( V_22 ) ;
if ( F_36 ( V_37 ) )
return V_37 ;
}
return NULL ;
}
static struct V_22 * F_37 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_21 = V_2 -> V_35 ;
struct V_19 * V_20 ;
struct V_22 * V_22 ;
F_31 ( & V_13 -> V_36 ) ;
V_20 = F_27 ( V_13 , V_21 ) ;
if ( ! V_20 )
goto V_3;
V_22 = F_22 ( V_20 , V_21 , V_24 ) ;
if ( F_23 ( V_22 ) )
goto V_3;
if ( F_36 ( V_22 ) || F_33 ( V_22 ) ) {
F_38 ( V_20 , V_22 , V_21 ) ;
F_39 ( V_22 ) ;
} else {
F_26 ( V_22 ) ;
V_3: V_22 = NULL ;
}
F_32 ( & V_13 -> V_36 ) ;
return V_22 ;
}
static inline int F_40 ( unsigned long V_38 )
{
return V_39 ? 0 : F_41 ( F_42 ( V_38 ) ) ;
}
static void F_43 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_44 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_40 . V_41 )
V_42 -- ;
else
V_43 -- ;
F_30 ( V_2 -> V_34 ) ;
V_2 -> V_35 &= V_44 ;
F_21 () ;
}
if ( V_5 -> V_37 == & V_45 )
F_45 ( & V_5 -> V_46 ) ;
else
F_46 ( & V_5 -> V_47 ,
V_48 + F_41 ( V_5 -> V_49 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_22 * F_47 ( struct V_5 * V_5 , bool V_50 )
{
struct V_22 * V_22 ;
void * V_51 ;
unsigned long V_38 ;
V_51 = ( void * ) V_5 +
( V_52 | V_53 ) ;
V_54:
V_38 = F_48 ( V_5 -> V_38 ) ;
V_22 = F_49 ( V_38 ) ;
F_50 () ;
if ( F_48 ( V_22 -> V_55 ) != V_51 )
goto V_56;
while ( ! F_51 ( V_22 ) ) {
if ( ! F_52 ( V_22 ) )
goto V_56;
F_53 () ;
}
if ( F_48 ( V_22 -> V_55 ) != V_51 ) {
F_26 ( V_22 ) ;
goto V_56;
}
if ( V_50 ) {
F_54 ( V_22 ) ;
if ( F_48 ( V_22 -> V_55 ) != V_51 ) {
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
goto V_56;
}
}
return V_22 ;
V_56:
F_56 () ;
if ( F_48 ( V_5 -> V_38 ) != V_38 )
goto V_54;
F_43 ( V_5 ) ;
return NULL ;
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_35 & V_57 ) {
struct V_5 * V_5 ;
struct V_22 * V_22 ;
V_5 = V_2 -> V_37 ;
V_22 = F_47 ( V_5 , true ) ;
if ( ! V_22 )
goto V_3;
F_58 ( & V_2 -> V_40 ) ;
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
if ( V_5 -> V_40 . V_58 )
V_42 -- ;
else
V_43 -- ;
F_30 ( V_2 -> V_34 ) ;
V_2 -> V_35 &= V_44 ;
} else if ( V_2 -> V_35 & V_59 ) {
unsigned char V_60 ;
V_60 = ( unsigned char ) ( V_61 . V_62 - V_2 -> V_35 ) ;
F_59 ( V_60 > 1 ) ;
if ( ! V_60 )
F_46 ( & V_2 -> V_47 ,
V_63 + F_41 ( V_2 -> V_49 ) ) ;
V_64 -- ;
V_2 -> V_35 &= V_44 ;
}
V_3:
F_21 () ;
}
static void F_60 ( struct V_8 * V_8 ,
struct V_2 * * V_65 )
{
while ( * V_65 ) {
struct V_2 * V_2 = * V_65 ;
* V_65 = V_2 -> V_65 ;
F_57 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_61 ( struct V_19 * V_20 ,
unsigned long V_66 , unsigned long V_67 )
{
unsigned long V_21 ;
int V_68 = 0 ;
for ( V_21 = V_66 ; V_21 < V_67 && ! V_68 ; V_21 += V_69 ) {
if ( F_18 ( V_20 -> V_26 ) )
break;
if ( F_62 ( V_70 ) )
V_68 = - V_71 ;
else
V_68 = F_20 ( V_20 , V_21 ) ;
}
return V_68 ;
}
static int F_63 ( struct V_5 * V_5 )
{
struct V_22 * V_22 ;
int V_68 ;
V_22 = F_47 ( V_5 , true ) ;
if ( ! V_22 ) {
return 0 ;
}
if ( F_64 ( F_65 ( V_22 ) ) ) {
V_68 = - V_72 ;
} else {
F_66 ( V_22 , NULL ) ;
F_43 ( V_5 ) ;
V_68 = 0 ;
}
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
return V_68 ;
}
static int F_67 ( void )
{
struct V_5 * V_5 ;
struct V_73 * V_74 , * V_41 ;
int V_49 ;
int V_68 = 0 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
while ( V_48 [ V_49 ] . V_76 ) {
V_5 = F_68 ( V_48 [ V_49 ] . V_76 ,
struct V_5 , V_47 ) ;
if ( F_63 ( V_5 ) ) {
V_68 = - V_72 ;
break;
}
F_21 () ;
}
}
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_74 , struct V_5 , V_46 ) ;
if ( F_63 ( V_5 ) )
V_68 = - V_72 ;
F_21 () ;
}
return V_68 ;
}
static int F_71 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_19 * V_20 ;
int V_68 = 0 ;
F_72 ( & V_77 ) ;
V_61 . V_8 = F_70 ( V_78 . V_79 . V_41 ,
struct V_8 , V_79 ) ;
F_73 ( & V_77 ) ;
for ( V_8 = V_61 . V_8 ;
V_8 != & V_78 ; V_8 = V_61 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_31 ( & V_13 -> V_36 ) ;
for ( V_20 = V_13 -> V_80 ; V_20 ; V_20 = V_20 -> V_81 ) {
if ( F_18 ( V_13 ) )
break;
if ( ! ( V_20 -> V_32 & V_33 ) || ! V_20 -> V_34 )
continue;
V_68 = F_61 ( V_20 ,
V_20 -> V_31 , V_20 -> V_82 ) ;
if ( V_68 )
goto error;
}
F_60 ( V_8 , & V_8 -> V_65 ) ;
F_72 ( & V_77 ) ;
V_61 . V_8 = F_70 ( V_8 -> V_79 . V_41 ,
struct V_8 , V_79 ) ;
if ( F_18 ( V_13 ) ) {
F_74 ( & V_8 -> V_17 ) ;
F_45 ( & V_8 -> V_79 ) ;
F_73 ( & V_77 ) ;
F_13 ( V_8 ) ;
F_75 ( V_83 , & V_13 -> V_84 ) ;
F_32 ( & V_13 -> V_36 ) ;
F_76 ( V_13 ) ;
} else {
F_73 ( & V_77 ) ;
F_32 ( & V_13 -> V_36 ) ;
}
}
F_67 () ;
V_61 . V_62 = 0 ;
return 0 ;
error:
F_32 ( & V_13 -> V_36 ) ;
F_72 ( & V_77 ) ;
V_61 . V_8 = & V_78 ;
F_73 ( & V_77 ) ;
return V_68 ;
}
static T_2 F_77 ( struct V_22 * V_22 )
{
T_2 V_85 ;
void * V_21 = F_78 ( V_22 ) ;
V_85 = F_79 ( V_21 , V_69 / 4 , 17 ) ;
F_80 ( V_21 ) ;
return V_85 ;
}
static int F_81 ( struct V_22 * V_86 , struct V_22 * V_87 )
{
char * V_88 , * V_89 ;
int V_23 ;
V_88 = F_78 ( V_86 ) ;
V_89 = F_78 ( V_87 ) ;
V_23 = memcmp ( V_88 , V_89 , V_69 ) ;
F_80 ( V_89 ) ;
F_80 ( V_88 ) ;
return V_23 ;
}
static inline int F_82 ( struct V_22 * V_86 , struct V_22 * V_87 )
{
return ! F_81 ( V_86 , V_87 ) ;
}
static int F_83 ( struct V_19 * V_20 , struct V_22 * V_22 ,
T_3 * V_90 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
unsigned long V_21 ;
T_3 * V_91 ;
T_4 * V_92 ;
int V_93 ;
int V_68 = - V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
V_21 = F_84 ( V_22 , V_20 ) ;
if ( V_21 == - V_94 )
goto V_3;
F_59 ( F_34 ( V_22 ) ) ;
V_95 = V_21 ;
V_96 = V_21 + V_69 ;
F_85 ( V_13 , V_95 , V_96 ) ;
V_91 = F_86 ( V_22 , V_13 , V_21 , & V_92 , 0 ) ;
if ( ! V_91 )
goto V_97;
if ( F_87 ( * V_91 ) || F_88 ( * V_91 ) ) {
T_3 V_98 ;
V_93 = F_52 ( V_22 ) ;
F_89 ( V_20 , V_21 , F_90 ( V_22 ) ) ;
V_98 = F_91 ( V_20 , V_21 , V_91 ) ;
if ( F_92 ( V_22 ) + 1 + V_93 != F_93 ( V_22 ) ) {
F_94 ( V_13 , V_21 , V_91 , V_98 ) ;
goto V_99;
}
if ( F_88 ( V_98 ) )
F_95 ( V_22 ) ;
V_98 = F_96 ( F_97 ( V_98 ) ) ;
F_98 ( V_13 , V_21 , V_91 , V_98 ) ;
}
* V_90 = * V_91 ;
V_68 = 0 ;
V_99:
F_99 ( V_91 , V_92 ) ;
V_97:
F_100 ( V_13 , V_95 , V_96 ) ;
V_3:
return V_68 ;
}
static int F_101 ( struct V_19 * V_20 , struct V_22 * V_22 ,
struct V_22 * V_100 , T_3 V_90 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
T_5 * V_101 ;
T_3 * V_91 ;
T_4 * V_92 ;
unsigned long V_21 ;
int V_68 = - V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
V_21 = F_84 ( V_22 , V_20 ) ;
if ( V_21 == - V_94 )
goto V_3;
V_101 = F_102 ( V_13 , V_21 ) ;
if ( ! V_101 )
goto V_3;
V_95 = V_21 ;
V_96 = V_21 + V_69 ;
F_85 ( V_13 , V_95 , V_96 ) ;
V_91 = F_103 ( V_13 , V_101 , V_21 , & V_92 ) ;
if ( ! F_104 ( * V_91 , V_90 ) ) {
F_99 ( V_91 , V_92 ) ;
goto V_97;
}
F_105 ( V_100 ) ;
F_106 ( V_100 , V_20 , V_21 ) ;
F_89 ( V_20 , V_21 , F_107 ( * V_91 ) ) ;
F_91 ( V_20 , V_21 , V_91 ) ;
F_98 ( V_13 , V_21 , V_91 , F_108 ( V_100 , V_20 -> V_102 ) ) ;
F_109 ( V_22 ) ;
if ( ! F_65 ( V_22 ) )
F_110 ( V_22 ) ;
F_26 ( V_22 ) ;
F_99 ( V_91 , V_92 ) ;
V_68 = 0 ;
V_97:
F_100 ( V_13 , V_95 , V_96 ) ;
V_3:
return V_68 ;
}
static int F_111 ( struct V_22 * V_22 )
{
int V_23 = 0 ;
struct V_22 * V_103 = F_33 ( V_22 ) ;
if ( V_103 ) {
if ( F_51 ( V_103 ) ) {
if ( F_36 ( V_103 ) )
V_23 = F_112 ( V_103 ) ;
else
V_23 = 1 ;
F_26 ( V_103 ) ;
} else
V_23 = 1 ;
}
return V_23 ;
}
static int F_113 ( struct V_19 * V_20 ,
struct V_22 * V_22 , struct V_22 * V_100 )
{
T_3 V_90 = F_114 ( 0 ) ;
int V_68 = - V_94 ;
if ( V_22 == V_100 )
return 0 ;
if ( ! ( V_20 -> V_32 & V_33 ) )
goto V_3;
if ( F_34 ( V_22 ) && F_111 ( V_22 ) )
goto V_3;
F_59 ( F_34 ( V_22 ) ) ;
if ( ! F_36 ( V_22 ) )
goto V_3;
if ( ! F_115 ( V_22 ) )
goto V_3;
if ( F_83 ( V_20 , V_22 , & V_90 ) == 0 ) {
if ( ! V_100 ) {
F_66 ( V_22 , NULL ) ;
F_116 ( V_22 ) ;
V_68 = 0 ;
} else if ( F_82 ( V_22 , V_100 ) )
V_68 = F_101 ( V_20 , V_22 , V_100 , V_90 ) ;
}
if ( ( V_20 -> V_32 & V_104 ) && V_100 && ! V_68 ) {
F_117 ( V_22 ) ;
if ( ! F_118 ( V_100 ) ) {
F_55 ( V_22 ) ;
F_54 ( V_100 ) ;
F_119 ( V_100 ) ;
V_22 = V_100 ;
}
}
F_55 ( V_22 ) ;
V_3:
return V_68 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_22 * V_22 , struct V_22 * V_100 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_19 * V_20 ;
int V_68 = - V_94 ;
F_31 ( & V_13 -> V_36 ) ;
if ( F_18 ( V_13 ) )
goto V_3;
V_20 = F_28 ( V_13 , V_2 -> V_35 ) ;
if ( ! V_20 || V_20 -> V_31 > V_2 -> V_35 )
goto V_3;
V_68 = F_113 ( V_20 , V_22 , V_100 ) ;
if ( V_68 )
goto V_3;
F_57 ( V_2 ) ;
V_2 -> V_34 = V_20 -> V_34 ;
F_121 ( V_20 -> V_34 ) ;
V_3:
F_32 ( & V_13 -> V_36 ) ;
return V_68 ;
}
static struct V_22 * F_122 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_2 * V_105 ,
struct V_22 * V_106 )
{
int V_68 ;
V_68 = F_120 ( V_2 , V_22 , NULL ) ;
if ( ! V_68 ) {
V_68 = F_120 ( V_105 ,
V_106 , V_22 ) ;
if ( V_68 )
F_29 ( V_2 ) ;
}
return V_68 ? NULL : V_22 ;
}
static struct V_22 * F_123 ( struct V_22 * V_22 )
{
int V_49 ;
struct V_107 * V_108 ;
struct V_76 * * V_109 ;
struct V_76 * V_110 ;
struct V_5 * V_5 ;
struct V_5 * V_111 ;
V_111 = F_124 ( V_22 ) ;
if ( V_111 && V_111 -> V_37 != & V_45 ) {
F_105 ( V_22 ) ;
return V_22 ;
}
V_49 = F_40 ( F_90 ( V_22 ) ) ;
V_108 = V_48 + V_49 ;
V_54:
V_109 = & V_108 -> V_76 ;
V_110 = NULL ;
while ( * V_109 ) {
struct V_22 * V_106 ;
int V_23 ;
F_21 () ;
V_5 = F_68 ( * V_109 , struct V_5 , V_47 ) ;
V_106 = F_47 ( V_5 , false ) ;
if ( ! V_106 )
return NULL ;
V_23 = F_81 ( V_22 , V_106 ) ;
F_26 ( V_106 ) ;
V_110 = * V_109 ;
if ( V_23 < 0 )
V_109 = & V_110 -> V_112 ;
else if ( V_23 > 0 )
V_109 = & V_110 -> V_113 ;
else {
V_106 = F_47 ( V_5 , true ) ;
if ( V_106 ) {
F_55 ( V_106 ) ;
if ( F_40 ( V_5 -> V_38 ) !=
F_41 ( V_5 -> V_49 ) ) {
F_26 ( V_106 ) ;
goto V_114;
}
return V_106 ;
}
if ( V_111 )
goto V_54;
return NULL ;
}
}
if ( ! V_111 )
return NULL ;
F_45 ( & V_111 -> V_46 ) ;
F_125 ( V_111 -> V_49 = V_49 ) ;
F_126 ( & V_111 -> V_47 , V_110 , V_109 ) ;
F_127 ( & V_111 -> V_47 , V_108 ) ;
F_105 ( V_22 ) ;
return V_22 ;
V_114:
if ( V_111 ) {
F_45 ( & V_111 -> V_46 ) ;
F_125 ( V_111 -> V_49 = V_49 ) ;
F_128 ( & V_5 -> V_47 , & V_111 -> V_47 , V_108 ) ;
F_105 ( V_22 ) ;
} else {
F_46 ( & V_5 -> V_47 , V_108 ) ;
V_22 = NULL ;
}
V_5 -> V_37 = & V_45 ;
F_129 ( & V_5 -> V_46 , V_5 -> V_37 ) ;
return V_22 ;
}
static struct V_5 * F_130 ( struct V_22 * V_100 )
{
int V_49 ;
unsigned long V_38 ;
struct V_107 * V_108 ;
struct V_76 * * V_109 ;
struct V_76 * V_110 = NULL ;
struct V_5 * V_5 ;
V_38 = F_90 ( V_100 ) ;
V_49 = F_40 ( V_38 ) ;
V_108 = V_48 + V_49 ;
V_109 = & V_108 -> V_76 ;
while ( * V_109 ) {
struct V_22 * V_106 ;
int V_23 ;
F_21 () ;
V_5 = F_68 ( * V_109 , struct V_5 , V_47 ) ;
V_106 = F_47 ( V_5 , false ) ;
if ( ! V_106 )
return NULL ;
V_23 = F_81 ( V_100 , V_106 ) ;
F_26 ( V_106 ) ;
V_110 = * V_109 ;
if ( V_23 < 0 )
V_109 = & V_110 -> V_112 ;
else if ( V_23 > 0 )
V_109 = & V_110 -> V_113 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_40 ) ;
V_5 -> V_38 = V_38 ;
F_66 ( V_100 , V_5 ) ;
F_125 ( V_5 -> V_49 = V_49 ) ;
F_126 ( & V_5 -> V_47 , V_110 , V_109 ) ;
F_127 ( & V_5 -> V_47 , V_108 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_22 * * V_115 )
{
struct V_76 * * V_109 ;
struct V_107 * V_108 ;
struct V_76 * V_110 = NULL ;
int V_49 ;
V_49 = F_40 ( F_90 ( V_22 ) ) ;
V_108 = V_63 + V_49 ;
V_109 = & V_108 -> V_76 ;
while ( * V_109 ) {
struct V_2 * V_105 ;
struct V_22 * V_106 ;
int V_23 ;
F_21 () ;
V_105 = F_68 ( * V_109 , struct V_2 , V_47 ) ;
V_106 = F_37 ( V_105 ) ;
if ( F_23 ( V_106 ) )
return NULL ;
if ( V_22 == V_106 ) {
F_26 ( V_106 ) ;
return NULL ;
}
V_23 = F_81 ( V_22 , V_106 ) ;
V_110 = * V_109 ;
if ( V_23 < 0 ) {
F_26 ( V_106 ) ;
V_109 = & V_110 -> V_112 ;
} else if ( V_23 > 0 ) {
F_26 ( V_106 ) ;
V_109 = & V_110 -> V_113 ;
} else if ( ! V_39 &&
F_133 ( V_106 ) != V_49 ) {
F_26 ( V_106 ) ;
return NULL ;
} else {
* V_115 = V_106 ;
return V_105 ;
}
}
V_2 -> V_35 |= V_59 ;
V_2 -> V_35 |= ( V_61 . V_62 & V_116 ) ;
F_125 ( V_2 -> V_49 = V_49 ) ;
F_126 ( & V_2 -> V_47 , V_110 , V_109 ) ;
F_127 ( & V_2 -> V_47 , V_108 ) ;
V_64 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_37 = V_5 ;
V_2 -> V_35 |= V_57 ;
F_135 ( & V_2 -> V_40 , & V_5 -> V_40 ) ;
if ( V_2 -> V_40 . V_41 )
V_42 ++ ;
else
V_43 ++ ;
}
static void F_136 ( struct V_22 * V_22 , struct V_2 * V_2 )
{
struct V_2 * V_105 ;
struct V_22 * V_106 = NULL ;
struct V_5 * V_5 ;
struct V_22 * V_100 ;
unsigned int V_85 ;
int V_68 ;
V_5 = F_124 ( V_22 ) ;
if ( V_5 ) {
if ( V_5 -> V_37 != & V_45 &&
F_40 ( V_5 -> V_38 ) != F_41 ( V_5 -> V_49 ) ) {
F_46 ( & V_5 -> V_47 ,
V_48 + F_41 ( V_5 -> V_49 ) ) ;
V_5 -> V_37 = & V_45 ;
F_129 ( & V_5 -> V_46 , V_5 -> V_37 ) ;
}
if ( V_5 -> V_37 != & V_45 &&
V_2 -> V_37 == V_5 )
return;
}
V_100 = F_123 ( V_22 ) ;
if ( V_100 == V_22 && V_2 -> V_37 == V_5 ) {
F_26 ( V_100 ) ;
return;
}
F_57 ( V_2 ) ;
if ( V_100 ) {
V_68 = F_120 ( V_2 , V_22 , V_100 ) ;
if ( ! V_68 ) {
F_54 ( V_100 ) ;
F_134 ( V_2 , F_124 ( V_100 ) ) ;
F_55 ( V_100 ) ;
}
F_26 ( V_100 ) ;
return;
}
V_85 = F_77 ( V_22 ) ;
if ( V_2 -> V_117 != V_85 ) {
V_2 -> V_117 = V_85 ;
return;
}
V_105 =
F_132 ( V_2 , V_22 , & V_106 ) ;
if ( V_105 ) {
V_100 = F_122 ( V_2 , V_22 ,
V_105 , V_106 ) ;
F_26 ( V_106 ) ;
if ( V_100 ) {
F_54 ( V_100 ) ;
V_5 = F_130 ( V_100 ) ;
if ( V_5 ) {
F_134 ( V_105 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_55 ( V_100 ) ;
if ( ! V_5 ) {
F_29 ( V_105 ) ;
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
if ( ( V_2 -> V_35 & V_44 ) == V_21 )
return V_2 ;
if ( V_2 -> V_35 > V_21 )
break;
* V_65 = V_2 -> V_65 ;
F_57 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_35 = V_21 ;
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
int V_49 ;
if ( F_139 ( & V_78 . V_79 ) )
return NULL ;
V_15 = V_61 . V_8 ;
if ( V_15 == & V_78 ) {
F_140 () ;
if ( ! V_39 ) {
struct V_5 * V_5 ;
struct V_73 * V_74 , * V_41 ;
struct V_22 * V_22 ;
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_74 ,
struct V_5 , V_46 ) ;
V_22 = F_47 ( V_5 , false ) ;
if ( V_22 )
F_26 ( V_22 ) ;
F_21 () ;
}
}
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ )
V_63 [ V_49 ] = V_118 ;
F_72 ( & V_77 ) ;
V_15 = F_70 ( V_15 -> V_79 . V_41 , struct V_8 , V_79 ) ;
V_61 . V_8 = V_15 ;
F_73 ( & V_77 ) ;
if ( V_15 == & V_78 )
return NULL ;
V_119:
V_61 . V_35 = 0 ;
V_61 . V_65 = & V_15 -> V_65 ;
}
V_13 = V_15 -> V_13 ;
F_31 ( & V_13 -> V_36 ) ;
if ( F_18 ( V_13 ) )
V_20 = NULL ;
else
V_20 = F_28 ( V_13 , V_61 . V_35 ) ;
for (; V_20 ; V_20 = V_20 -> V_81 ) {
if ( ! ( V_20 -> V_32 & V_33 ) )
continue;
if ( V_61 . V_35 < V_20 -> V_31 )
V_61 . V_35 = V_20 -> V_31 ;
if ( ! V_20 -> V_34 )
V_61 . V_35 = V_20 -> V_82 ;
while ( V_61 . V_35 < V_20 -> V_82 ) {
if ( F_18 ( V_13 ) )
break;
* V_22 = F_22 ( V_20 , V_61 . V_35 , V_24 ) ;
if ( F_23 ( * V_22 ) ) {
V_61 . V_35 += V_69 ;
F_21 () ;
continue;
}
if ( F_36 ( * V_22 ) ||
F_33 ( * V_22 ) ) {
F_38 ( V_20 , * V_22 , V_61 . V_35 ) ;
F_39 ( * V_22 ) ;
V_2 = F_137 ( V_15 ,
V_61 . V_65 , V_61 . V_35 ) ;
if ( V_2 ) {
V_61 . V_65 =
& V_2 -> V_65 ;
V_61 . V_35 += V_69 ;
} else
F_26 ( * V_22 ) ;
F_32 ( & V_13 -> V_36 ) ;
return V_2 ;
}
F_26 ( * V_22 ) ;
V_61 . V_35 += V_69 ;
F_21 () ;
}
}
if ( F_18 ( V_13 ) ) {
V_61 . V_35 = 0 ;
V_61 . V_65 = & V_15 -> V_65 ;
}
F_60 ( V_15 , V_61 . V_65 ) ;
F_72 ( & V_77 ) ;
V_61 . V_8 = F_70 ( V_15 -> V_79 . V_41 ,
struct V_8 , V_79 ) ;
if ( V_61 . V_35 == 0 ) {
F_74 ( & V_15 -> V_17 ) ;
F_45 ( & V_15 -> V_79 ) ;
F_73 ( & V_77 ) ;
F_13 ( V_15 ) ;
F_75 ( V_83 , & V_13 -> V_84 ) ;
F_32 ( & V_13 -> V_36 ) ;
F_76 ( V_13 ) ;
} else {
F_73 ( & V_77 ) ;
F_32 ( & V_13 -> V_36 ) ;
}
V_15 = V_61 . V_8 ;
if ( V_15 != & V_78 )
goto V_119;
V_61 . V_62 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_120 )
{
struct V_2 * V_2 ;
struct V_22 * V_121 ( V_22 ) ;
while ( V_120 -- && F_142 ( ! F_143 ( V_70 ) ) ) {
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
return ( V_122 & V_123 ) && ! F_139 ( & V_78 . V_79 ) ;
}
static int F_145 ( void * V_124 )
{
F_146 () ;
F_147 ( V_70 , 5 ) ;
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
int F_156 ( struct V_19 * V_20 , unsigned long V_66 ,
unsigned long V_67 , int V_129 , unsigned long * V_32 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
int V_68 ;
switch ( V_129 ) {
case V_130 :
if ( * V_32 & ( V_33 | V_131 | V_132 |
V_133 | V_134 | V_135 |
V_136 | V_137 | V_138 ) )
return 0 ;
#ifdef F_157
if ( * V_32 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_83 , & V_13 -> V_84 ) ) {
V_68 = F_159 ( V_13 ) ;
if ( V_68 )
return V_68 ;
}
* V_32 |= V_33 ;
break;
case V_139 :
if ( ! ( * V_32 & V_33 ) )
return 0 ;
if ( V_20 -> V_34 ) {
V_68 = F_61 ( V_20 , V_66 , V_67 ) ;
if ( V_68 )
return V_68 ;
}
* V_32 &= ~ V_33 ;
break;
}
return 0 ;
}
int F_159 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_140 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_140 = F_139 ( & V_78 . V_79 ) ;
F_72 ( & V_77 ) ;
F_16 ( V_13 , V_8 ) ;
if ( V_122 & V_141 )
F_160 ( & V_8 -> V_79 , & V_78 . V_79 ) ;
else
F_160 ( & V_8 -> V_79 , & V_61 . V_8 -> V_79 ) ;
F_73 ( & V_77 ) ;
F_161 ( V_83 , & V_13 -> V_84 ) ;
F_162 ( & V_13 -> V_142 ) ;
if ( V_140 )
F_163 ( & V_128 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_143 = 0 ;
F_72 ( & V_77 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_61 . V_8 != V_8 ) {
if ( ! V_8 -> V_65 ) {
F_74 ( & V_8 -> V_17 ) ;
F_45 ( & V_8 -> V_79 ) ;
V_143 = 1 ;
} else {
F_165 ( & V_8 -> V_79 ,
& V_61 . V_8 -> V_79 ) ;
}
}
F_73 ( & V_77 ) ;
if ( V_143 ) {
F_13 ( V_8 ) ;
F_75 ( V_83 , & V_13 -> V_84 ) ;
F_76 ( V_13 ) ;
} else if ( V_8 ) {
F_166 ( & V_13 -> V_36 ) ;
F_167 ( & V_13 -> V_36 ) ;
}
}
struct V_22 * F_168 ( struct V_22 * V_22 ,
struct V_19 * V_20 , unsigned long V_35 )
{
struct V_34 * V_34 = F_169 ( V_22 ) ;
struct V_22 * V_144 ;
if ( F_24 ( V_22 ) ) {
if ( F_124 ( V_22 ) &&
! ( V_122 & V_141 ) )
return V_22 ;
} else if ( ! V_34 ) {
return V_22 ;
} else if ( V_34 -> V_108 == V_20 -> V_34 -> V_108 &&
V_22 -> V_145 == F_170 ( V_20 , V_35 ) ) {
return V_22 ;
}
if ( ! F_171 ( V_22 ) )
return V_22 ;
V_144 = F_172 ( V_146 , V_20 , V_35 ) ;
if ( V_144 ) {
F_173 ( V_144 , V_22 , V_35 , V_20 ) ;
F_174 ( V_144 ) ;
F_175 ( V_144 ) ;
F_176 ( V_144 ) ;
}
return V_144 ;
}
int F_177 ( struct V_22 * V_22 , struct V_147 * V_148 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
int V_23 = V_149 ;
int V_150 = 0 ;
F_178 ( ! F_24 ( V_22 ) , V_22 ) ;
F_178 ( ! F_179 ( V_22 ) , V_22 ) ;
V_5 = F_124 ( V_22 ) ;
if ( ! V_5 )
return V_23 ;
V_54:
F_44 (rmap_item, &stable_node->hlist, hlist) {
struct V_34 * V_34 = V_2 -> V_34 ;
struct V_151 * V_152 ;
struct V_19 * V_20 ;
F_180 ( V_34 ) ;
F_181 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
V_20 = V_152 -> V_20 ;
if ( V_2 -> V_35 < V_20 -> V_31 ||
V_2 -> V_35 >= V_20 -> V_82 )
continue;
if ( ( V_2 -> V_13 == V_20 -> V_26 ) == V_150 )
continue;
if ( V_148 -> V_153 && V_148 -> V_153 ( V_20 , V_148 -> V_154 ) )
continue;
V_23 = V_148 -> V_155 ( V_22 , V_20 ,
V_2 -> V_35 , V_148 -> V_154 ) ;
if ( V_23 != V_149 ) {
F_182 ( V_34 ) ;
goto V_3;
}
if ( V_148 -> V_156 && V_148 -> V_156 ( V_22 ) ) {
F_182 ( V_34 ) ;
goto V_3;
}
}
F_182 ( V_34 ) ;
}
if ( ! V_150 ++ )
goto V_54;
V_3:
return V_23 ;
}
void F_183 ( struct V_22 * V_157 , struct V_22 * V_158 )
{
struct V_5 * V_5 ;
F_178 ( ! F_179 ( V_158 ) , V_158 ) ;
F_178 ( ! F_179 ( V_157 ) , V_157 ) ;
F_178 ( V_157 -> V_55 != V_158 -> V_55 , V_157 ) ;
V_5 = F_124 ( V_157 ) ;
if ( V_5 ) {
F_178 ( V_5 -> V_38 != F_90 ( V_158 ) , V_158 ) ;
V_5 -> V_38 = F_90 ( V_157 ) ;
F_184 () ;
F_66 ( V_158 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_122 & V_159 ) {
F_151 ( & V_125 ) ;
F_185 ( & V_122 , F_186 ( V_159 ) ,
V_160 ) ;
F_149 ( & V_125 ) ;
}
}
static void F_187 ( unsigned long V_161 ,
unsigned long V_162 )
{
struct V_5 * V_5 ;
struct V_73 * V_74 , * V_41 ;
struct V_76 * V_47 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
V_47 = F_188 ( V_48 + V_49 ) ;
while ( V_47 ) {
V_5 = F_68 ( V_47 , struct V_5 , V_47 ) ;
if ( V_5 -> V_38 >= V_161 &&
V_5 -> V_38 < V_162 ) {
F_43 ( V_5 ) ;
V_47 = F_188 ( V_48 + V_49 ) ;
} else
V_47 = F_189 ( V_47 ) ;
F_21 () ;
}
}
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_74 , struct V_5 , V_46 ) ;
if ( V_5 -> V_38 >= V_161 &&
V_5 -> V_38 < V_162 )
F_43 ( V_5 ) ;
F_21 () ;
}
}
static int F_190 ( struct V_163 * V_164 ,
unsigned long V_165 , void * V_154 )
{
struct V_166 * V_167 = V_154 ;
switch ( V_165 ) {
case V_168 :
F_149 ( & V_125 ) ;
V_122 |= V_159 ;
F_151 ( & V_125 ) ;
break;
case V_169 :
F_187 ( V_167 -> V_161 ,
V_167 -> V_161 + V_167 -> V_170 ) ;
case V_171 :
F_149 ( & V_125 ) ;
V_122 &= ~ V_159 ;
F_151 ( & V_125 ) ;
F_191 () ;
F_192 ( & V_122 , F_186 ( V_159 ) ) ;
break;
}
return V_172 ;
}
static void F_150 ( void )
{
}
static T_6 F_193 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_127 ) ;
}
static T_6 F_194 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
unsigned long V_179 ;
int V_68 ;
V_68 = F_195 ( V_177 , 10 , & V_179 ) ;
if ( V_68 || V_179 > V_180 )
return - V_181 ;
V_127 = V_179 ;
return V_178 ;
}
static T_6 F_196 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_126 ) ;
}
static T_6 F_197 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_68 ;
unsigned long V_170 ;
V_68 = F_195 ( V_177 , 10 , & V_170 ) ;
if ( V_68 || V_170 > V_180 )
return - V_181 ;
V_126 = V_170 ;
return V_178 ;
}
static T_6 F_198 ( struct V_173 * V_174 , struct V_175 * V_176 ,
char * V_177 )
{
return sprintf ( V_177 , L_2 , V_122 ) ;
}
static T_6 F_199 ( struct V_173 * V_174 , struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_68 ;
unsigned long V_84 ;
V_68 = F_195 ( V_177 , 10 , & V_84 ) ;
if ( V_68 || V_84 > V_180 )
return - V_181 ;
if ( V_84 > V_141 )
return - V_181 ;
F_149 ( & V_125 ) ;
F_150 () ;
if ( V_122 != V_84 ) {
V_122 = V_84 ;
if ( V_84 & V_141 ) {
F_200 () ;
V_68 = F_71 () ;
F_201 () ;
if ( V_68 ) {
V_122 = V_182 ;
V_178 = V_68 ;
}
}
}
F_151 ( & V_125 ) ;
if ( V_84 & V_123 )
F_163 ( & V_128 ) ;
return V_178 ;
}
static T_6 F_202 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_39 ) ;
}
static T_6 F_203 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_68 ;
unsigned long V_183 ;
V_68 = F_195 ( V_177 , 10 , & V_183 ) ;
if ( V_68 )
return V_68 ;
if ( V_183 > 1 )
return - V_181 ;
F_149 ( & V_125 ) ;
F_150 () ;
if ( V_39 != V_183 ) {
if ( V_43 || F_67 () )
V_68 = - V_72 ;
else if ( V_48 == V_184 ) {
struct V_107 * V_177 ;
V_177 = F_204 ( V_185 + V_185 , sizeof( * V_177 ) ,
V_11 ) ;
if ( ! V_177 )
V_68 = - V_10 ;
else {
V_48 = V_177 ;
V_63 = V_177 + V_185 ;
V_63 [ 0 ] = V_186 [ 0 ] ;
}
}
if ( ! V_68 ) {
V_39 = V_183 ;
V_75 = V_183 ? 1 : V_185 ;
}
}
F_151 ( & V_125 ) ;
return V_68 ? V_68 : V_178 ;
}
static T_6 F_205 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_43 ) ;
}
static T_6 F_206 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_42 ) ;
}
static T_6 F_207 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_64 ) ;
}
static T_6 F_208 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
long V_187 ;
V_187 = V_12 - V_43
- V_42 - V_64 ;
if ( V_187 < 0 )
V_187 = 0 ;
return sprintf ( V_177 , L_3 , V_187 ) ;
}
static T_6 F_209 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_61 . V_62 ) ;
}
static int T_1 F_210 ( void )
{
struct V_188 * V_189 ;
int V_68 ;
V_68 = F_1 () ;
if ( V_68 )
goto V_3;
V_189 = F_211 ( F_145 , NULL , L_4 ) ;
if ( F_212 ( V_189 ) ) {
F_213 ( V_190 L_5 ) ;
V_68 = F_214 ( V_189 ) ;
goto V_191;
}
#ifdef F_215
V_68 = F_216 ( V_192 , & V_193 ) ;
if ( V_68 ) {
F_213 ( V_190 L_6 ) ;
F_217 ( V_189 ) ;
goto V_191;
}
#else
V_122 = V_123 ;
#endif
#ifdef F_218
F_219 ( F_190 , 100 ) ;
#endif
return 0 ;
V_191:
F_4 () ;
V_3:
return V_68 ;
}
