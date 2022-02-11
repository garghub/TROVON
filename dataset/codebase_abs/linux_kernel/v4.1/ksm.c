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
static struct V_22 * F_33 ( struct V_22 * V_22 )
{
if ( F_34 ( V_22 ) ) {
struct V_22 * V_38 = F_35 ( V_22 ) ;
if ( F_36 ( V_38 ) )
return V_38 ;
}
return NULL ;
}
static struct V_22 * F_37 ( struct V_2 * V_2 )
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
if ( F_36 ( V_22 ) || F_33 ( V_22 ) ) {
F_38 ( V_20 , V_22 , V_21 ) ;
F_39 ( V_22 ) ;
} else {
F_26 ( V_22 ) ;
V_3: V_22 = NULL ;
}
F_32 ( & V_13 -> V_37 ) ;
return V_22 ;
}
static inline int F_40 ( unsigned long V_39 )
{
return V_40 ? 0 : F_41 ( F_42 ( V_39 ) ) ;
}
static void F_43 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
F_44 (rmap_item, &stable_node->hlist, hlist) {
if ( V_2 -> V_41 . V_42 )
V_43 -- ;
else
V_44 -- ;
F_30 ( V_2 -> V_35 ) ;
V_2 -> V_36 &= V_45 ;
F_21 () ;
}
if ( V_5 -> V_38 == & V_46 )
F_45 ( & V_5 -> V_47 ) ;
else
F_46 ( & V_5 -> V_48 ,
V_49 + F_41 ( V_5 -> V_50 ) ) ;
F_11 ( V_5 ) ;
}
static struct V_22 * F_47 ( struct V_5 * V_5 , bool V_51 )
{
struct V_22 * V_22 ;
void * V_52 ;
unsigned long V_39 ;
V_52 = ( void * ) V_5 +
( V_53 | V_54 ) ;
V_55:
V_39 = F_48 ( V_5 -> V_39 ) ;
V_22 = F_49 ( V_39 ) ;
F_50 () ;
if ( F_48 ( V_22 -> V_56 ) != V_52 )
goto V_57;
while ( ! F_51 ( V_22 ) ) {
if ( ! F_52 ( V_22 ) )
goto V_57;
F_53 () ;
}
if ( F_48 ( V_22 -> V_56 ) != V_52 ) {
F_26 ( V_22 ) ;
goto V_57;
}
if ( V_51 ) {
F_54 ( V_22 ) ;
if ( F_48 ( V_22 -> V_56 ) != V_52 ) {
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
goto V_57;
}
}
return V_22 ;
V_57:
F_56 () ;
if ( F_48 ( V_5 -> V_39 ) != V_39 )
goto V_55;
F_43 ( V_5 ) ;
return NULL ;
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_36 & V_58 ) {
struct V_5 * V_5 ;
struct V_22 * V_22 ;
V_5 = V_2 -> V_38 ;
V_22 = F_47 ( V_5 , true ) ;
if ( ! V_22 )
goto V_3;
F_58 ( & V_2 -> V_41 ) ;
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
if ( V_5 -> V_41 . V_59 )
V_43 -- ;
else
V_44 -- ;
F_30 ( V_2 -> V_35 ) ;
V_2 -> V_36 &= V_45 ;
} else if ( V_2 -> V_36 & V_60 ) {
unsigned char V_61 ;
V_61 = ( unsigned char ) ( V_62 . V_63 - V_2 -> V_36 ) ;
F_59 ( V_61 > 1 ) ;
if ( ! V_61 )
F_46 ( & V_2 -> V_48 ,
V_64 + F_41 ( V_2 -> V_50 ) ) ;
V_65 -- ;
V_2 -> V_36 &= V_45 ;
}
V_3:
F_21 () ;
}
static void F_60 ( struct V_8 * V_8 ,
struct V_2 * * V_66 )
{
while ( * V_66 ) {
struct V_2 * V_2 = * V_66 ;
* V_66 = V_2 -> V_66 ;
F_57 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_61 ( struct V_19 * V_20 ,
unsigned long V_67 , unsigned long V_68 )
{
unsigned long V_21 ;
int V_69 = 0 ;
for ( V_21 = V_67 ; V_21 < V_68 && ! V_69 ; V_21 += V_70 ) {
if ( F_18 ( V_20 -> V_26 ) )
break;
if ( F_62 ( V_71 ) )
V_69 = - V_72 ;
else
V_69 = F_20 ( V_20 , V_21 ) ;
}
return V_69 ;
}
static int F_63 ( struct V_5 * V_5 )
{
struct V_22 * V_22 ;
int V_69 ;
V_22 = F_47 ( V_5 , true ) ;
if ( ! V_22 ) {
return 0 ;
}
if ( F_64 ( F_65 ( V_22 ) ) ) {
V_69 = - V_73 ;
} else {
F_66 ( V_22 , NULL ) ;
F_43 ( V_5 ) ;
V_69 = 0 ;
}
F_55 ( V_22 ) ;
F_26 ( V_22 ) ;
return V_69 ;
}
static int F_67 ( void )
{
struct V_5 * V_5 ;
struct V_74 * V_75 , * V_42 ;
int V_50 ;
int V_69 = 0 ;
for ( V_50 = 0 ; V_50 < V_76 ; V_50 ++ ) {
while ( V_49 [ V_50 ] . V_77 ) {
V_5 = F_68 ( V_49 [ V_50 ] . V_77 ,
struct V_5 , V_48 ) ;
if ( F_63 ( V_5 ) ) {
V_69 = - V_73 ;
break;
}
F_21 () ;
}
}
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_75 , struct V_5 , V_47 ) ;
if ( F_63 ( V_5 ) )
V_69 = - V_73 ;
F_21 () ;
}
return V_69 ;
}
static int F_71 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_19 * V_20 ;
int V_69 = 0 ;
F_72 ( & V_78 ) ;
V_62 . V_8 = F_70 ( V_79 . V_80 . V_42 ,
struct V_8 , V_80 ) ;
F_73 ( & V_78 ) ;
for ( V_8 = V_62 . V_8 ;
V_8 != & V_79 ; V_8 = V_62 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
for ( V_20 = V_13 -> V_81 ; V_20 ; V_20 = V_20 -> V_82 ) {
if ( F_18 ( V_13 ) )
break;
if ( ! ( V_20 -> V_33 & V_34 ) || ! V_20 -> V_35 )
continue;
V_69 = F_61 ( V_20 ,
V_20 -> V_32 , V_20 -> V_83 ) ;
if ( V_69 )
goto error;
}
F_60 ( V_8 , & V_8 -> V_66 ) ;
F_72 ( & V_78 ) ;
V_62 . V_8 = F_70 ( V_8 -> V_80 . V_42 ,
struct V_8 , V_80 ) ;
if ( F_18 ( V_13 ) ) {
F_74 ( & V_8 -> V_17 ) ;
F_45 ( & V_8 -> V_80 ) ;
F_73 ( & V_78 ) ;
F_13 ( V_8 ) ;
F_75 ( V_84 , & V_13 -> V_85 ) ;
F_32 ( & V_13 -> V_37 ) ;
F_76 ( V_13 ) ;
} else {
F_73 ( & V_78 ) ;
F_32 ( & V_13 -> V_37 ) ;
}
}
F_67 () ;
V_62 . V_63 = 0 ;
return 0 ;
error:
F_32 ( & V_13 -> V_37 ) ;
F_72 ( & V_78 ) ;
V_62 . V_8 = & V_79 ;
F_73 ( & V_78 ) ;
return V_69 ;
}
static T_2 F_77 ( struct V_22 * V_22 )
{
T_2 V_86 ;
void * V_21 = F_78 ( V_22 ) ;
V_86 = F_79 ( V_21 , V_70 / 4 , 17 ) ;
F_80 ( V_21 ) ;
return V_86 ;
}
static int F_81 ( struct V_22 * V_87 , struct V_22 * V_88 )
{
char * V_89 , * V_90 ;
int V_23 ;
V_89 = F_78 ( V_87 ) ;
V_90 = F_78 ( V_88 ) ;
V_23 = memcmp ( V_89 , V_90 , V_70 ) ;
F_80 ( V_90 ) ;
F_80 ( V_89 ) ;
return V_23 ;
}
static inline int F_82 ( struct V_22 * V_87 , struct V_22 * V_88 )
{
return ! F_81 ( V_87 , V_88 ) ;
}
static int F_83 ( struct V_19 * V_20 , struct V_22 * V_22 ,
T_3 * V_91 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
unsigned long V_21 ;
T_3 * V_92 ;
T_4 * V_93 ;
int V_94 ;
int V_69 = - V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
V_21 = F_84 ( V_22 , V_20 ) ;
if ( V_21 == - V_95 )
goto V_3;
F_59 ( F_34 ( V_22 ) ) ;
V_96 = V_21 ;
V_97 = V_21 + V_70 ;
F_85 ( V_13 , V_96 , V_97 ) ;
V_92 = F_86 ( V_22 , V_13 , V_21 , & V_93 , 0 ) ;
if ( ! V_92 )
goto V_98;
if ( F_87 ( * V_92 ) || F_88 ( * V_92 ) ) {
T_3 V_99 ;
V_94 = F_52 ( V_22 ) ;
F_89 ( V_20 , V_21 , F_90 ( V_22 ) ) ;
V_99 = F_91 ( V_20 , V_21 , V_92 ) ;
if ( F_92 ( V_22 ) + 1 + V_94 != F_93 ( V_22 ) ) {
F_94 ( V_13 , V_21 , V_92 , V_99 ) ;
goto V_100;
}
if ( F_88 ( V_99 ) )
F_95 ( V_22 ) ;
V_99 = F_96 ( F_97 ( V_99 ) ) ;
F_98 ( V_13 , V_21 , V_92 , V_99 ) ;
}
* V_91 = * V_92 ;
V_69 = 0 ;
V_100:
F_99 ( V_92 , V_93 ) ;
V_98:
F_100 ( V_13 , V_96 , V_97 ) ;
V_3:
return V_69 ;
}
static int F_101 ( struct V_19 * V_20 , struct V_22 * V_22 ,
struct V_22 * V_101 , T_3 V_91 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
T_5 * V_102 ;
T_3 * V_92 ;
T_4 * V_93 ;
unsigned long V_21 ;
int V_69 = - V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
V_21 = F_84 ( V_22 , V_20 ) ;
if ( V_21 == - V_95 )
goto V_3;
V_102 = F_102 ( V_13 , V_21 ) ;
if ( ! V_102 )
goto V_3;
V_96 = V_21 ;
V_97 = V_21 + V_70 ;
F_85 ( V_13 , V_96 , V_97 ) ;
V_92 = F_103 ( V_13 , V_102 , V_21 , & V_93 ) ;
if ( ! F_104 ( * V_92 , V_91 ) ) {
F_99 ( V_92 , V_93 ) ;
goto V_98;
}
F_105 ( V_101 ) ;
F_106 ( V_101 , V_20 , V_21 ) ;
F_89 ( V_20 , V_21 , F_107 ( * V_92 ) ) ;
F_91 ( V_20 , V_21 , V_92 ) ;
F_98 ( V_13 , V_21 , V_92 , F_108 ( V_101 , V_20 -> V_103 ) ) ;
F_109 ( V_22 ) ;
if ( ! F_65 ( V_22 ) )
F_110 ( V_22 ) ;
F_26 ( V_22 ) ;
F_99 ( V_92 , V_93 ) ;
V_69 = 0 ;
V_98:
F_100 ( V_13 , V_96 , V_97 ) ;
V_3:
return V_69 ;
}
static int F_111 ( struct V_22 * V_22 )
{
int V_23 = 0 ;
struct V_22 * V_104 = F_33 ( V_22 ) ;
if ( V_104 ) {
if ( F_51 ( V_104 ) ) {
if ( F_36 ( V_104 ) )
V_23 = F_112 ( V_104 ) ;
else
V_23 = 1 ;
F_26 ( V_104 ) ;
} else
V_23 = 1 ;
}
return V_23 ;
}
static int F_113 ( struct V_19 * V_20 ,
struct V_22 * V_22 , struct V_22 * V_101 )
{
T_3 V_91 = F_114 ( 0 ) ;
int V_69 = - V_95 ;
if ( V_22 == V_101 )
return 0 ;
if ( ! ( V_20 -> V_33 & V_34 ) )
goto V_3;
if ( F_34 ( V_22 ) && F_111 ( V_22 ) )
goto V_3;
F_59 ( F_34 ( V_22 ) ) ;
if ( ! F_36 ( V_22 ) )
goto V_3;
if ( ! F_115 ( V_22 ) )
goto V_3;
if ( F_83 ( V_20 , V_22 , & V_91 ) == 0 ) {
if ( ! V_101 ) {
F_66 ( V_22 , NULL ) ;
F_116 ( V_22 ) ;
V_69 = 0 ;
} else if ( F_82 ( V_22 , V_101 ) )
V_69 = F_101 ( V_20 , V_22 , V_101 , V_91 ) ;
}
if ( ( V_20 -> V_33 & V_105 ) && V_101 && ! V_69 ) {
F_117 ( V_22 ) ;
if ( ! F_118 ( V_101 ) ) {
F_55 ( V_22 ) ;
F_54 ( V_101 ) ;
F_119 ( V_101 ) ;
V_22 = V_101 ;
}
}
F_55 ( V_22 ) ;
V_3:
return V_69 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_22 * V_22 , struct V_22 * V_101 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_19 * V_20 ;
int V_69 = - V_95 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_18 ( V_13 ) )
goto V_3;
V_20 = F_28 ( V_13 , V_2 -> V_36 ) ;
if ( ! V_20 || V_20 -> V_32 > V_2 -> V_36 )
goto V_3;
V_69 = F_113 ( V_20 , V_22 , V_101 ) ;
if ( V_69 )
goto V_3;
F_57 ( V_2 ) ;
V_2 -> V_35 = V_20 -> V_35 ;
F_121 ( V_20 -> V_35 ) ;
V_3:
F_32 ( & V_13 -> V_37 ) ;
return V_69 ;
}
static struct V_22 * F_122 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_2 * V_106 ,
struct V_22 * V_107 )
{
int V_69 ;
V_69 = F_120 ( V_2 , V_22 , NULL ) ;
if ( ! V_69 ) {
V_69 = F_120 ( V_106 ,
V_107 , V_22 ) ;
if ( V_69 )
F_29 ( V_2 ) ;
}
return V_69 ? NULL : V_22 ;
}
static struct V_22 * F_123 ( struct V_22 * V_22 )
{
int V_50 ;
struct V_108 * V_109 ;
struct V_77 * * V_110 ;
struct V_77 * V_111 ;
struct V_5 * V_5 ;
struct V_5 * V_112 ;
V_112 = F_124 ( V_22 ) ;
if ( V_112 && V_112 -> V_38 != & V_46 ) {
F_105 ( V_22 ) ;
return V_22 ;
}
V_50 = F_40 ( F_90 ( V_22 ) ) ;
V_109 = V_49 + V_50 ;
V_55:
V_110 = & V_109 -> V_77 ;
V_111 = NULL ;
while ( * V_110 ) {
struct V_22 * V_107 ;
int V_23 ;
F_21 () ;
V_5 = F_68 ( * V_110 , struct V_5 , V_48 ) ;
V_107 = F_47 ( V_5 , false ) ;
if ( ! V_107 )
return NULL ;
V_23 = F_81 ( V_22 , V_107 ) ;
F_26 ( V_107 ) ;
V_111 = * V_110 ;
if ( V_23 < 0 )
V_110 = & V_111 -> V_113 ;
else if ( V_23 > 0 )
V_110 = & V_111 -> V_114 ;
else {
V_107 = F_47 ( V_5 , true ) ;
if ( V_107 ) {
F_55 ( V_107 ) ;
if ( F_40 ( V_5 -> V_39 ) !=
F_41 ( V_5 -> V_50 ) ) {
F_26 ( V_107 ) ;
goto V_115;
}
return V_107 ;
}
if ( V_112 )
goto V_55;
return NULL ;
}
}
if ( ! V_112 )
return NULL ;
F_45 ( & V_112 -> V_47 ) ;
F_125 ( V_112 -> V_50 = V_50 ) ;
F_126 ( & V_112 -> V_48 , V_111 , V_110 ) ;
F_127 ( & V_112 -> V_48 , V_109 ) ;
F_105 ( V_22 ) ;
return V_22 ;
V_115:
if ( V_112 ) {
F_45 ( & V_112 -> V_47 ) ;
F_125 ( V_112 -> V_50 = V_50 ) ;
F_128 ( & V_5 -> V_48 , & V_112 -> V_48 , V_109 ) ;
F_105 ( V_22 ) ;
} else {
F_46 ( & V_5 -> V_48 , V_109 ) ;
V_22 = NULL ;
}
V_5 -> V_38 = & V_46 ;
F_129 ( & V_5 -> V_47 , V_5 -> V_38 ) ;
return V_22 ;
}
static struct V_5 * F_130 ( struct V_22 * V_101 )
{
int V_50 ;
unsigned long V_39 ;
struct V_108 * V_109 ;
struct V_77 * * V_110 ;
struct V_77 * V_111 = NULL ;
struct V_5 * V_5 ;
V_39 = F_90 ( V_101 ) ;
V_50 = F_40 ( V_39 ) ;
V_109 = V_49 + V_50 ;
V_110 = & V_109 -> V_77 ;
while ( * V_110 ) {
struct V_22 * V_107 ;
int V_23 ;
F_21 () ;
V_5 = F_68 ( * V_110 , struct V_5 , V_48 ) ;
V_107 = F_47 ( V_5 , false ) ;
if ( ! V_107 )
return NULL ;
V_23 = F_81 ( V_101 , V_107 ) ;
F_26 ( V_107 ) ;
V_111 = * V_110 ;
if ( V_23 < 0 )
V_110 = & V_111 -> V_113 ;
else if ( V_23 > 0 )
V_110 = & V_111 -> V_114 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_131 ( & V_5 -> V_41 ) ;
V_5 -> V_39 = V_39 ;
F_66 ( V_101 , V_5 ) ;
F_125 ( V_5 -> V_50 = V_50 ) ;
F_126 ( & V_5 -> V_48 , V_111 , V_110 ) ;
F_127 ( & V_5 -> V_48 , V_109 ) ;
return V_5 ;
}
static
struct V_2 * F_132 ( struct V_2 * V_2 ,
struct V_22 * V_22 ,
struct V_22 * * V_116 )
{
struct V_77 * * V_110 ;
struct V_108 * V_109 ;
struct V_77 * V_111 = NULL ;
int V_50 ;
V_50 = F_40 ( F_90 ( V_22 ) ) ;
V_109 = V_64 + V_50 ;
V_110 = & V_109 -> V_77 ;
while ( * V_110 ) {
struct V_2 * V_106 ;
struct V_22 * V_107 ;
int V_23 ;
F_21 () ;
V_106 = F_68 ( * V_110 , struct V_2 , V_48 ) ;
V_107 = F_37 ( V_106 ) ;
if ( F_23 ( V_107 ) )
return NULL ;
if ( V_22 == V_107 ) {
F_26 ( V_107 ) ;
return NULL ;
}
V_23 = F_81 ( V_22 , V_107 ) ;
V_111 = * V_110 ;
if ( V_23 < 0 ) {
F_26 ( V_107 ) ;
V_110 = & V_111 -> V_113 ;
} else if ( V_23 > 0 ) {
F_26 ( V_107 ) ;
V_110 = & V_111 -> V_114 ;
} else if ( ! V_40 &&
F_133 ( V_107 ) != V_50 ) {
F_26 ( V_107 ) ;
return NULL ;
} else {
* V_116 = V_107 ;
return V_106 ;
}
}
V_2 -> V_36 |= V_60 ;
V_2 -> V_36 |= ( V_62 . V_63 & V_117 ) ;
F_125 ( V_2 -> V_50 = V_50 ) ;
F_126 ( & V_2 -> V_48 , V_111 , V_110 ) ;
F_127 ( & V_2 -> V_48 , V_109 ) ;
V_65 ++ ;
return NULL ;
}
static void F_134 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_38 = V_5 ;
V_2 -> V_36 |= V_58 ;
F_135 ( & V_2 -> V_41 , & V_5 -> V_41 ) ;
if ( V_2 -> V_41 . V_42 )
V_43 ++ ;
else
V_44 ++ ;
}
static void F_136 ( struct V_22 * V_22 , struct V_2 * V_2 )
{
struct V_2 * V_106 ;
struct V_22 * V_107 = NULL ;
struct V_5 * V_5 ;
struct V_22 * V_101 ;
unsigned int V_86 ;
int V_69 ;
V_5 = F_124 ( V_22 ) ;
if ( V_5 ) {
if ( V_5 -> V_38 != & V_46 &&
F_40 ( V_5 -> V_39 ) != F_41 ( V_5 -> V_50 ) ) {
F_46 ( & V_5 -> V_48 ,
V_49 + F_41 ( V_5 -> V_50 ) ) ;
V_5 -> V_38 = & V_46 ;
F_129 ( & V_5 -> V_47 , V_5 -> V_38 ) ;
}
if ( V_5 -> V_38 != & V_46 &&
V_2 -> V_38 == V_5 )
return;
}
V_101 = F_123 ( V_22 ) ;
if ( V_101 == V_22 && V_2 -> V_38 == V_5 ) {
F_26 ( V_101 ) ;
return;
}
F_57 ( V_2 ) ;
if ( V_101 ) {
V_69 = F_120 ( V_2 , V_22 , V_101 ) ;
if ( ! V_69 ) {
F_54 ( V_101 ) ;
F_134 ( V_2 , F_124 ( V_101 ) ) ;
F_55 ( V_101 ) ;
}
F_26 ( V_101 ) ;
return;
}
V_86 = F_77 ( V_22 ) ;
if ( V_2 -> V_118 != V_86 ) {
V_2 -> V_118 = V_86 ;
return;
}
V_106 =
F_132 ( V_2 , V_22 , & V_107 ) ;
if ( V_106 ) {
V_101 = F_122 ( V_2 , V_22 ,
V_106 , V_107 ) ;
F_26 ( V_107 ) ;
if ( V_101 ) {
F_54 ( V_101 ) ;
V_5 = F_130 ( V_101 ) ;
if ( V_5 ) {
F_134 ( V_106 , V_5 ) ;
F_134 ( V_2 , V_5 ) ;
}
F_55 ( V_101 ) ;
if ( ! V_5 ) {
F_29 ( V_106 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_137 ( struct V_8 * V_8 ,
struct V_2 * * V_66 ,
unsigned long V_21 )
{
struct V_2 * V_2 ;
while ( * V_66 ) {
V_2 = * V_66 ;
if ( ( V_2 -> V_36 & V_45 ) == V_21 )
return V_2 ;
if ( V_2 -> V_36 > V_21 )
break;
* V_66 = V_2 -> V_66 ;
F_57 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_36 = V_21 ;
V_2 -> V_66 = * V_66 ;
* V_66 = V_2 ;
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
if ( F_139 ( & V_79 . V_80 ) )
return NULL ;
V_15 = V_62 . V_8 ;
if ( V_15 == & V_79 ) {
F_140 () ;
if ( ! V_40 ) {
struct V_5 * V_5 ;
struct V_74 * V_75 , * V_42 ;
struct V_22 * V_22 ;
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_75 ,
struct V_5 , V_47 ) ;
V_22 = F_47 ( V_5 , false ) ;
if ( V_22 )
F_26 ( V_22 ) ;
F_21 () ;
}
}
for ( V_50 = 0 ; V_50 < V_76 ; V_50 ++ )
V_64 [ V_50 ] = V_119 ;
F_72 ( & V_78 ) ;
V_15 = F_70 ( V_15 -> V_80 . V_42 , struct V_8 , V_80 ) ;
V_62 . V_8 = V_15 ;
F_73 ( & V_78 ) ;
if ( V_15 == & V_79 )
return NULL ;
V_120:
V_62 . V_36 = 0 ;
V_62 . V_66 = & V_15 -> V_66 ;
}
V_13 = V_15 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_18 ( V_13 ) )
V_20 = NULL ;
else
V_20 = F_28 ( V_13 , V_62 . V_36 ) ;
for (; V_20 ; V_20 = V_20 -> V_82 ) {
if ( ! ( V_20 -> V_33 & V_34 ) )
continue;
if ( V_62 . V_36 < V_20 -> V_32 )
V_62 . V_36 = V_20 -> V_32 ;
if ( ! V_20 -> V_35 )
V_62 . V_36 = V_20 -> V_83 ;
while ( V_62 . V_36 < V_20 -> V_83 ) {
if ( F_18 ( V_13 ) )
break;
* V_22 = F_22 ( V_20 , V_62 . V_36 , V_24 ) ;
if ( F_23 ( * V_22 ) ) {
V_62 . V_36 += V_70 ;
F_21 () ;
continue;
}
if ( F_36 ( * V_22 ) ||
F_33 ( * V_22 ) ) {
F_38 ( V_20 , * V_22 , V_62 . V_36 ) ;
F_39 ( * V_22 ) ;
V_2 = F_137 ( V_15 ,
V_62 . V_66 , V_62 . V_36 ) ;
if ( V_2 ) {
V_62 . V_66 =
& V_2 -> V_66 ;
V_62 . V_36 += V_70 ;
} else
F_26 ( * V_22 ) ;
F_32 ( & V_13 -> V_37 ) ;
return V_2 ;
}
F_26 ( * V_22 ) ;
V_62 . V_36 += V_70 ;
F_21 () ;
}
}
if ( F_18 ( V_13 ) ) {
V_62 . V_36 = 0 ;
V_62 . V_66 = & V_15 -> V_66 ;
}
F_60 ( V_15 , V_62 . V_66 ) ;
F_72 ( & V_78 ) ;
V_62 . V_8 = F_70 ( V_15 -> V_80 . V_42 ,
struct V_8 , V_80 ) ;
if ( V_62 . V_36 == 0 ) {
F_74 ( & V_15 -> V_17 ) ;
F_45 ( & V_15 -> V_80 ) ;
F_73 ( & V_78 ) ;
F_13 ( V_15 ) ;
F_75 ( V_84 , & V_13 -> V_85 ) ;
F_32 ( & V_13 -> V_37 ) ;
F_76 ( V_13 ) ;
} else {
F_73 ( & V_78 ) ;
F_32 ( & V_13 -> V_37 ) ;
}
V_15 = V_62 . V_8 ;
if ( V_15 != & V_79 )
goto V_120;
V_62 . V_63 ++ ;
return NULL ;
}
static void F_141 ( unsigned int V_121 )
{
struct V_2 * V_2 ;
struct V_22 * V_122 ( V_22 ) ;
while ( V_121 -- && F_142 ( ! F_143 ( V_71 ) ) ) {
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
return ( V_123 & V_124 ) && ! F_139 ( & V_79 . V_80 ) ;
}
static int F_145 ( void * V_125 )
{
F_146 () ;
F_147 ( V_71 , 5 ) ;
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
int F_156 ( struct V_19 * V_20 , unsigned long V_67 ,
unsigned long V_68 , int V_130 , unsigned long * V_33 )
{
struct V_14 * V_13 = V_20 -> V_26 ;
int V_69 ;
switch ( V_130 ) {
case V_131 :
if ( * V_33 & ( V_34 | V_132 | V_133 |
V_134 | V_135 | V_136 |
V_137 | V_138 ) )
return 0 ;
#ifdef F_157
if ( * V_33 & F_157 )
return 0 ;
#endif
if ( ! F_158 ( V_84 , & V_13 -> V_85 ) ) {
V_69 = F_159 ( V_13 ) ;
if ( V_69 )
return V_69 ;
}
* V_33 |= V_34 ;
break;
case V_139 :
if ( ! ( * V_33 & V_34 ) )
return 0 ;
if ( V_20 -> V_35 ) {
V_69 = F_61 ( V_20 , V_67 , V_68 ) ;
if ( V_69 )
return V_69 ;
}
* V_33 &= ~ V_34 ;
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
V_140 = F_139 ( & V_79 . V_80 ) ;
F_72 ( & V_78 ) ;
F_16 ( V_13 , V_8 ) ;
if ( V_123 & V_141 )
F_160 ( & V_8 -> V_80 , & V_79 . V_80 ) ;
else
F_160 ( & V_8 -> V_80 , & V_62 . V_8 -> V_80 ) ;
F_73 ( & V_78 ) ;
F_161 ( V_84 , & V_13 -> V_85 ) ;
F_162 ( & V_13 -> V_142 ) ;
if ( V_140 )
F_163 ( & V_129 ) ;
return 0 ;
}
void F_164 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_143 = 0 ;
F_72 ( & V_78 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_62 . V_8 != V_8 ) {
if ( ! V_8 -> V_66 ) {
F_74 ( & V_8 -> V_17 ) ;
F_45 ( & V_8 -> V_80 ) ;
V_143 = 1 ;
} else {
F_165 ( & V_8 -> V_80 ,
& V_62 . V_8 -> V_80 ) ;
}
}
F_73 ( & V_78 ) ;
if ( V_143 ) {
F_13 ( V_8 ) ;
F_75 ( V_84 , & V_13 -> V_85 ) ;
F_76 ( V_13 ) ;
} else if ( V_8 ) {
F_166 ( & V_13 -> V_37 ) ;
F_167 ( & V_13 -> V_37 ) ;
}
}
struct V_22 * F_168 ( struct V_22 * V_22 ,
struct V_19 * V_20 , unsigned long V_36 )
{
struct V_35 * V_35 = F_169 ( V_22 ) ;
struct V_22 * V_144 ;
if ( F_24 ( V_22 ) ) {
if ( F_124 ( V_22 ) &&
! ( V_123 & V_141 ) )
return V_22 ;
} else if ( ! V_35 ) {
return V_22 ;
} else if ( V_35 -> V_109 == V_20 -> V_35 -> V_109 &&
V_22 -> V_145 == F_170 ( V_20 , V_36 ) ) {
return V_22 ;
}
if ( ! F_171 ( V_22 ) )
return V_22 ;
V_144 = F_172 ( V_146 , V_20 , V_36 ) ;
if ( V_144 ) {
F_173 ( V_144 , V_22 , V_36 , V_20 ) ;
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
V_55:
F_44 (rmap_item, &stable_node->hlist, hlist) {
struct V_35 * V_35 = V_2 -> V_35 ;
struct V_151 * V_152 ;
struct V_19 * V_20 ;
F_180 ( V_35 ) ;
F_181 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
V_20 = V_152 -> V_20 ;
if ( V_2 -> V_36 < V_20 -> V_32 ||
V_2 -> V_36 >= V_20 -> V_83 )
continue;
if ( ( V_2 -> V_13 == V_20 -> V_26 ) == V_150 )
continue;
if ( V_148 -> V_153 && V_148 -> V_153 ( V_20 , V_148 -> V_154 ) )
continue;
V_23 = V_148 -> V_155 ( V_22 , V_20 ,
V_2 -> V_36 , V_148 -> V_154 ) ;
if ( V_23 != V_149 ) {
F_182 ( V_35 ) ;
goto V_3;
}
if ( V_148 -> V_156 && V_148 -> V_156 ( V_22 ) ) {
F_182 ( V_35 ) ;
goto V_3;
}
}
F_182 ( V_35 ) ;
}
if ( ! V_150 ++ )
goto V_55;
V_3:
return V_23 ;
}
void F_183 ( struct V_22 * V_157 , struct V_22 * V_158 )
{
struct V_5 * V_5 ;
F_178 ( ! F_179 ( V_158 ) , V_158 ) ;
F_178 ( ! F_179 ( V_157 ) , V_157 ) ;
F_178 ( V_157 -> V_56 != V_158 -> V_56 , V_157 ) ;
V_5 = F_124 ( V_157 ) ;
if ( V_5 ) {
F_178 ( V_5 -> V_39 != F_90 ( V_158 ) , V_158 ) ;
V_5 -> V_39 = F_90 ( V_157 ) ;
F_184 () ;
F_66 ( V_158 , NULL ) ;
}
}
static void F_150 ( void )
{
while ( V_123 & V_159 ) {
F_151 ( & V_126 ) ;
F_185 ( & V_123 , F_186 ( V_159 ) ,
V_160 ) ;
F_149 ( & V_126 ) ;
}
}
static void F_187 ( unsigned long V_161 ,
unsigned long V_162 )
{
struct V_5 * V_5 ;
struct V_74 * V_75 , * V_42 ;
struct V_77 * V_48 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_76 ; V_50 ++ ) {
V_48 = F_188 ( V_49 + V_50 ) ;
while ( V_48 ) {
V_5 = F_68 ( V_48 , struct V_5 , V_48 ) ;
if ( V_5 -> V_39 >= V_161 &&
V_5 -> V_39 < V_162 ) {
F_43 ( V_5 ) ;
V_48 = F_188 ( V_49 + V_50 ) ;
} else
V_48 = F_189 ( V_48 ) ;
F_21 () ;
}
}
F_69 (this, next, &migrate_nodes) {
V_5 = F_70 ( V_75 , struct V_5 , V_47 ) ;
if ( V_5 -> V_39 >= V_161 &&
V_5 -> V_39 < V_162 )
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
F_149 ( & V_126 ) ;
V_123 |= V_159 ;
F_151 ( & V_126 ) ;
break;
case V_169 :
F_187 ( V_167 -> V_161 ,
V_167 -> V_161 + V_167 -> V_170 ) ;
case V_171 :
F_149 ( & V_126 ) ;
V_123 &= ~ V_159 ;
F_151 ( & V_126 ) ;
F_191 () ;
F_192 ( & V_123 , F_186 ( V_159 ) ) ;
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
return sprintf ( V_177 , L_1 , V_128 ) ;
}
static T_6 F_194 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
unsigned long V_179 ;
int V_69 ;
V_69 = F_195 ( V_177 , 10 , & V_179 ) ;
if ( V_69 || V_179 > V_180 )
return - V_181 ;
V_128 = V_179 ;
return V_178 ;
}
static T_6 F_196 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_127 ) ;
}
static T_6 F_197 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_69 ;
unsigned long V_170 ;
V_69 = F_195 ( V_177 , 10 , & V_170 ) ;
if ( V_69 || V_170 > V_180 )
return - V_181 ;
V_127 = V_170 ;
return V_178 ;
}
static T_6 F_198 ( struct V_173 * V_174 , struct V_175 * V_176 ,
char * V_177 )
{
return sprintf ( V_177 , L_2 , V_123 ) ;
}
static T_6 F_199 ( struct V_173 * V_174 , struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_69 ;
unsigned long V_85 ;
V_69 = F_195 ( V_177 , 10 , & V_85 ) ;
if ( V_69 || V_85 > V_180 )
return - V_181 ;
if ( V_85 > V_141 )
return - V_181 ;
F_149 ( & V_126 ) ;
F_150 () ;
if ( V_123 != V_85 ) {
V_123 = V_85 ;
if ( V_85 & V_141 ) {
F_200 () ;
V_69 = F_71 () ;
F_201 () ;
if ( V_69 ) {
V_123 = V_182 ;
V_178 = V_69 ;
}
}
}
F_151 ( & V_126 ) ;
if ( V_85 & V_124 )
F_163 ( & V_129 ) ;
return V_178 ;
}
static T_6 F_202 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_1 , V_40 ) ;
}
static T_6 F_203 ( struct V_173 * V_174 ,
struct V_175 * V_176 ,
const char * V_177 , T_7 V_178 )
{
int V_69 ;
unsigned long V_183 ;
V_69 = F_195 ( V_177 , 10 , & V_183 ) ;
if ( V_69 )
return V_69 ;
if ( V_183 > 1 )
return - V_181 ;
F_149 ( & V_126 ) ;
F_150 () ;
if ( V_40 != V_183 ) {
if ( V_44 || F_67 () )
V_69 = - V_73 ;
else if ( V_49 == V_184 ) {
struct V_108 * V_177 ;
V_177 = F_204 ( V_185 + V_185 , sizeof( * V_177 ) ,
V_11 ) ;
if ( ! V_177 )
V_69 = - V_10 ;
else {
V_49 = V_177 ;
V_64 = V_177 + V_185 ;
V_64 [ 0 ] = V_186 [ 0 ] ;
}
}
if ( ! V_69 ) {
V_40 = V_183 ;
V_76 = V_183 ? 1 : V_185 ;
}
}
F_151 ( & V_126 ) ;
return V_69 ? V_69 : V_178 ;
}
static T_6 F_205 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_44 ) ;
}
static T_6 F_206 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_43 ) ;
}
static T_6 F_207 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_65 ) ;
}
static T_6 F_208 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
long V_187 ;
V_187 = V_12 - V_44
- V_43 - V_65 ;
if ( V_187 < 0 )
V_187 = 0 ;
return sprintf ( V_177 , L_3 , V_187 ) ;
}
static T_6 F_209 ( struct V_173 * V_174 ,
struct V_175 * V_176 , char * V_177 )
{
return sprintf ( V_177 , L_2 , V_62 . V_63 ) ;
}
static int T_1 F_210 ( void )
{
struct V_188 * V_189 ;
int V_69 ;
V_69 = F_1 () ;
if ( V_69 )
goto V_3;
V_189 = F_211 ( F_145 , NULL , L_4 ) ;
if ( F_212 ( V_189 ) ) {
F_213 ( L_5 ) ;
V_69 = F_214 ( V_189 ) ;
goto V_190;
}
#ifdef F_215
V_69 = F_216 ( V_191 , & V_192 ) ;
if ( V_69 ) {
F_213 ( L_6 ) ;
F_217 ( V_189 ) ;
goto V_190;
}
#else
V_123 = V_124 ;
#endif
#ifdef F_218
F_219 ( F_190 , 100 ) ;
#endif
return 0 ;
V_190:
F_4 () ;
V_3:
return V_69 ;
}
