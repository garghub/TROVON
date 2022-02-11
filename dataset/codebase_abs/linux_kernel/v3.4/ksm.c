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
struct V_8 * V_8 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = & V_19 [ F_15 ( V_13 , V_20 ) ] ;
F_16 (mm_slot, node, bucket, link) {
if ( V_13 == V_8 -> V_13 )
return V_8 ;
}
return NULL ;
}
static void F_17 ( struct V_14 * V_13 ,
struct V_8 * V_8 )
{
struct V_15 * V_16 ;
V_16 = & V_19 [ F_15 ( V_13 , V_20 ) ] ;
V_8 -> V_13 = V_13 ;
F_18 ( & V_8 -> V_21 , V_16 ) ;
}
static inline int F_19 ( struct V_2 * V_2 )
{
return V_2 -> V_22 & V_23 ;
}
static inline bool F_20 ( struct V_14 * V_13 )
{
return F_21 ( & V_13 -> V_24 ) == 0 ;
}
static int F_22 ( struct V_25 * V_26 , unsigned long V_27 )
{
struct V_28 * V_28 ;
int V_29 = 0 ;
do {
F_23 () ;
V_28 = F_24 ( V_26 , V_27 , V_30 ) ;
if ( F_25 ( V_28 ) )
break;
if ( F_26 ( V_28 ) )
V_29 = F_27 ( V_26 -> V_31 , V_26 , V_27 ,
V_32 ) ;
else
V_29 = V_33 ;
F_28 ( V_28 ) ;
} while ( ! ( V_29 & ( V_33 | V_34 | V_35 ) ) );
return ( V_29 & V_35 ) ? - V_10 : 0 ;
}
static struct V_25 * F_29 ( struct V_14 * V_13 ,
unsigned long V_27 )
{
struct V_25 * V_26 ;
if ( F_20 ( V_13 ) )
return NULL ;
V_26 = F_30 ( V_13 , V_27 ) ;
if ( ! V_26 || V_26 -> V_36 > V_27 )
return NULL ;
if ( ! ( V_26 -> V_37 & V_38 ) || ! V_26 -> V_39 )
return NULL ;
return V_26 ;
}
static void F_31 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_27 = V_2 -> V_22 ;
struct V_25 * V_26 ;
F_32 ( V_2 -> V_39 ) ;
F_33 ( & V_13 -> V_40 ) ;
V_26 = F_29 ( V_13 , V_27 ) ;
if ( V_26 )
F_22 ( V_26 , V_27 ) ;
F_34 ( & V_13 -> V_40 ) ;
}
static struct V_28 * F_35 ( struct V_28 * V_28 )
{
if ( F_36 ( V_28 ) ) {
struct V_28 * V_41 = F_37 ( V_28 ) ;
if ( F_38 ( V_41 ) )
return V_41 ;
}
return NULL ;
}
static struct V_28 * F_39 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_27 = V_2 -> V_22 ;
struct V_25 * V_26 ;
struct V_28 * V_28 ;
F_33 ( & V_13 -> V_40 ) ;
V_26 = F_29 ( V_13 , V_27 ) ;
if ( ! V_26 )
goto V_3;
V_28 = F_24 ( V_26 , V_27 , V_30 ) ;
if ( F_25 ( V_28 ) )
goto V_3;
if ( F_38 ( V_28 ) || F_35 ( V_28 ) ) {
F_40 ( V_26 , V_28 , V_27 ) ;
F_41 ( V_28 ) ;
} else {
F_28 ( V_28 ) ;
V_3: V_28 = NULL ;
}
F_34 ( & V_13 -> V_40 ) ;
return V_28 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
struct V_17 * V_42 ;
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
if ( V_2 -> V_42 . V_43 )
V_44 -- ;
else
V_45 -- ;
F_32 ( V_2 -> V_39 ) ;
V_2 -> V_22 &= V_46 ;
F_23 () ;
}
F_43 ( & V_5 -> V_18 , & V_47 ) ;
F_11 ( V_5 ) ;
}
static struct V_28 * F_44 ( struct V_5 * V_5 )
{
struct V_28 * V_28 ;
void * V_48 ;
V_28 = F_45 ( V_5 -> V_49 ) ;
V_48 = ( void * ) V_5 +
( V_50 | V_51 ) ;
F_46 () ;
if ( V_28 -> V_52 != V_48 )
goto V_53;
if ( ! F_47 ( V_28 ) )
goto V_53;
if ( V_28 -> V_52 != V_48 ) {
F_28 ( V_28 ) ;
goto V_53;
}
F_48 () ;
return V_28 ;
V_53:
F_48 () ;
F_42 ( V_5 ) ;
return NULL ;
}
static void F_49 ( struct V_2 * V_2 )
{
if ( V_2 -> V_22 & V_23 ) {
struct V_5 * V_5 ;
struct V_28 * V_28 ;
V_5 = V_2 -> V_41 ;
V_28 = F_44 ( V_5 ) ;
if ( ! V_28 )
goto V_3;
F_50 ( V_28 ) ;
F_51 ( & V_2 -> V_42 ) ;
F_52 ( V_28 ) ;
F_28 ( V_28 ) ;
if ( V_5 -> V_42 . V_54 )
V_44 -- ;
else
V_45 -- ;
F_32 ( V_2 -> V_39 ) ;
V_2 -> V_22 &= V_46 ;
} else if ( V_2 -> V_22 & V_55 ) {
unsigned char V_56 ;
V_56 = ( unsigned char ) ( V_57 . V_58 - V_2 -> V_22 ) ;
F_53 ( V_56 > 1 ) ;
if ( ! V_56 )
F_43 ( & V_2 -> V_18 , & V_59 ) ;
V_60 -- ;
V_2 -> V_22 &= V_46 ;
}
V_3:
F_23 () ;
}
static void F_54 ( struct V_8 * V_8 ,
struct V_2 * * V_61 )
{
while ( * V_61 ) {
struct V_2 * V_2 = * V_61 ;
* V_61 = V_2 -> V_61 ;
F_49 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_55 ( struct V_25 * V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
unsigned long V_27 ;
int V_64 = 0 ;
for ( V_27 = V_62 ; V_27 < V_63 && ! V_64 ; V_27 += V_65 ) {
if ( F_20 ( V_26 -> V_31 ) )
break;
if ( F_56 ( V_66 ) )
V_64 = - V_67 ;
else
V_64 = F_22 ( V_26 , V_27 ) ;
}
return V_64 ;
}
static int F_57 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_25 * V_26 ;
int V_64 = 0 ;
F_58 ( & V_68 ) ;
V_57 . V_8 = F_59 ( V_69 . V_70 . V_43 ,
struct V_8 , V_70 ) ;
F_60 ( & V_68 ) ;
for ( V_8 = V_57 . V_8 ;
V_8 != & V_69 ; V_8 = V_57 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_33 ( & V_13 -> V_40 ) ;
for ( V_26 = V_13 -> V_71 ; V_26 ; V_26 = V_26 -> V_72 ) {
if ( F_20 ( V_13 ) )
break;
if ( ! ( V_26 -> V_37 & V_38 ) || ! V_26 -> V_39 )
continue;
V_64 = F_55 ( V_26 ,
V_26 -> V_36 , V_26 -> V_73 ) ;
if ( V_64 )
goto error;
}
F_54 ( V_8 , & V_8 -> V_61 ) ;
F_58 ( & V_68 ) ;
V_57 . V_8 = F_59 ( V_8 -> V_70 . V_43 ,
struct V_8 , V_70 ) ;
if ( F_20 ( V_13 ) ) {
F_51 ( & V_8 -> V_21 ) ;
F_61 ( & V_8 -> V_70 ) ;
F_60 ( & V_68 ) ;
F_13 ( V_8 ) ;
F_62 ( V_74 , & V_13 -> V_75 ) ;
F_34 ( & V_13 -> V_40 ) ;
F_63 ( V_13 ) ;
} else {
F_60 ( & V_68 ) ;
F_34 ( & V_13 -> V_40 ) ;
}
}
V_57 . V_58 = 0 ;
return 0 ;
error:
F_34 ( & V_13 -> V_40 ) ;
F_58 ( & V_68 ) ;
V_57 . V_8 = & V_69 ;
F_60 ( & V_68 ) ;
return V_64 ;
}
static T_2 F_64 ( struct V_28 * V_28 )
{
T_2 V_76 ;
void * V_27 = F_65 ( V_28 ) ;
V_76 = F_66 ( V_27 , V_65 / 4 , 17 ) ;
F_67 ( V_27 ) ;
return V_76 ;
}
static int F_68 ( struct V_28 * V_77 , struct V_28 * V_78 )
{
char * V_79 , * V_80 ;
int V_29 ;
V_79 = F_65 ( V_77 ) ;
V_80 = F_65 ( V_78 ) ;
V_29 = memcmp ( V_79 , V_80 , V_65 ) ;
F_67 ( V_80 ) ;
F_67 ( V_79 ) ;
return V_29 ;
}
static inline int F_69 ( struct V_28 * V_77 , struct V_28 * V_78 )
{
return ! F_68 ( V_77 , V_78 ) ;
}
static int F_70 ( struct V_25 * V_26 , struct V_28 * V_28 ,
T_3 * V_81 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
unsigned long V_27 ;
T_3 * V_82 ;
T_4 * V_83 ;
int V_84 ;
int V_64 = - V_85 ;
V_27 = F_71 ( V_28 , V_26 ) ;
if ( V_27 == - V_85 )
goto V_3;
F_53 ( F_36 ( V_28 ) ) ;
V_82 = F_72 ( V_28 , V_13 , V_27 , & V_83 , 0 ) ;
if ( ! V_82 )
goto V_3;
if ( F_73 ( * V_82 ) || F_74 ( * V_82 ) ) {
T_3 V_86 ;
V_84 = F_75 ( V_28 ) ;
F_76 ( V_26 , V_27 , F_77 ( V_28 ) ) ;
V_86 = F_78 ( V_26 , V_27 , V_82 ) ;
if ( F_79 ( V_28 ) + 1 + V_84 != F_80 ( V_28 ) ) {
F_81 ( V_13 , V_27 , V_82 , V_86 ) ;
goto V_87;
}
if ( F_74 ( V_86 ) )
F_82 ( V_28 ) ;
V_86 = F_83 ( F_84 ( V_86 ) ) ;
F_85 ( V_13 , V_27 , V_82 , V_86 ) ;
}
* V_81 = * V_82 ;
V_64 = 0 ;
V_87:
F_86 ( V_82 , V_83 ) ;
V_3:
return V_64 ;
}
static int F_87 ( struct V_25 * V_26 , struct V_28 * V_28 ,
struct V_28 * V_88 , T_3 V_81 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
T_5 * V_89 ;
T_6 * V_90 ;
T_7 * V_91 ;
T_3 * V_82 ;
T_4 * V_83 ;
unsigned long V_27 ;
int V_64 = - V_85 ;
V_27 = F_71 ( V_28 , V_26 ) ;
if ( V_27 == - V_85 )
goto V_3;
V_89 = F_88 ( V_13 , V_27 ) ;
if ( ! F_89 ( * V_89 ) )
goto V_3;
V_90 = F_90 ( V_89 , V_27 ) ;
if ( ! F_91 ( * V_90 ) )
goto V_3;
V_91 = F_92 ( V_90 , V_27 ) ;
F_53 ( F_93 ( * V_91 ) ) ;
if ( ! F_94 ( * V_91 ) )
goto V_3;
V_82 = F_95 ( V_13 , V_91 , V_27 , & V_83 ) ;
if ( ! F_96 ( * V_82 , V_81 ) ) {
F_86 ( V_82 , V_83 ) ;
goto V_3;
}
F_97 ( V_88 ) ;
F_98 ( V_88 , V_26 , V_27 ) ;
F_76 ( V_26 , V_27 , F_99 ( * V_82 ) ) ;
F_78 ( V_26 , V_27 , V_82 ) ;
F_85 ( V_13 , V_27 , V_82 , F_100 ( V_88 , V_26 -> V_92 ) ) ;
F_101 ( V_28 ) ;
if ( ! F_102 ( V_28 ) )
F_103 ( V_28 ) ;
F_28 ( V_28 ) ;
F_86 ( V_82 , V_83 ) ;
V_64 = 0 ;
V_3:
return V_64 ;
}
static int F_104 ( struct V_28 * V_28 )
{
int V_29 = 0 ;
struct V_28 * V_93 = F_35 ( V_28 ) ;
if ( V_93 ) {
if ( F_47 ( V_93 ) ) {
if ( F_38 ( V_93 ) )
V_29 = F_105 ( V_93 ) ;
else
V_29 = 1 ;
F_28 ( V_93 ) ;
} else
V_29 = 1 ;
}
return V_29 ;
}
static int F_106 ( struct V_25 * V_26 ,
struct V_28 * V_28 , struct V_28 * V_88 )
{
T_3 V_81 = F_107 ( 0 ) ;
int V_64 = - V_85 ;
if ( V_28 == V_88 )
return 0 ;
if ( ! ( V_26 -> V_37 & V_38 ) )
goto V_3;
if ( F_36 ( V_28 ) && F_104 ( V_28 ) )
goto V_3;
F_53 ( F_36 ( V_28 ) ) ;
if ( ! F_38 ( V_28 ) )
goto V_3;
if ( ! F_108 ( V_28 ) )
goto V_3;
if ( F_70 ( V_26 , V_28 , & V_81 ) == 0 ) {
if ( ! V_88 ) {
F_109 ( V_28 , NULL ) ;
F_110 ( V_28 ) ;
V_64 = 0 ;
} else if ( F_69 ( V_28 , V_88 ) )
V_64 = F_87 ( V_26 , V_28 , V_88 , V_81 ) ;
}
if ( ( V_26 -> V_37 & V_94 ) && V_88 && ! V_64 ) {
F_111 ( V_28 ) ;
if ( ! F_112 ( V_88 ) ) {
F_52 ( V_28 ) ;
F_50 ( V_88 ) ;
F_113 ( V_88 ) ;
V_28 = V_88 ;
}
}
F_52 ( V_28 ) ;
V_3:
return V_64 ;
}
static int F_114 ( struct V_2 * V_2 ,
struct V_28 * V_28 , struct V_28 * V_88 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_25 * V_26 ;
int V_64 = - V_85 ;
F_33 ( & V_13 -> V_40 ) ;
if ( F_20 ( V_13 ) )
goto V_3;
V_26 = F_30 ( V_13 , V_2 -> V_22 ) ;
if ( ! V_26 || V_26 -> V_36 > V_2 -> V_22 )
goto V_3;
V_64 = F_106 ( V_26 , V_28 , V_88 ) ;
if ( V_64 )
goto V_3;
V_2 -> V_39 = V_26 -> V_39 ;
F_115 ( V_26 -> V_39 ) ;
V_3:
F_34 ( & V_13 -> V_40 ) ;
return V_64 ;
}
static struct V_28 * F_116 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_2 * V_95 ,
struct V_28 * V_96 )
{
int V_64 ;
V_64 = F_114 ( V_2 , V_28 , NULL ) ;
if ( ! V_64 ) {
V_64 = F_114 ( V_95 ,
V_96 , V_28 ) ;
if ( V_64 )
F_31 ( V_2 ) ;
}
return V_64 ? NULL : V_28 ;
}
static struct V_28 * F_117 ( struct V_28 * V_28 )
{
struct V_97 * V_18 = V_47 . V_97 ;
struct V_5 * V_5 ;
V_5 = F_118 ( V_28 ) ;
if ( V_5 ) {
F_97 ( V_28 ) ;
return V_28 ;
}
while ( V_18 ) {
struct V_28 * V_96 ;
int V_29 ;
F_23 () ;
V_5 = F_119 ( V_18 , struct V_5 , V_18 ) ;
V_96 = F_44 ( V_5 ) ;
if ( ! V_96 )
return NULL ;
V_29 = F_68 ( V_28 , V_96 ) ;
if ( V_29 < 0 ) {
F_28 ( V_96 ) ;
V_18 = V_18 -> V_98 ;
} else if ( V_29 > 0 ) {
F_28 ( V_96 ) ;
V_18 = V_18 -> V_99 ;
} else
return V_96 ;
}
return NULL ;
}
static struct V_5 * F_120 ( struct V_28 * V_88 )
{
struct V_97 * * V_100 = & V_47 . V_97 ;
struct V_97 * V_101 = NULL ;
struct V_5 * V_5 ;
while ( * V_100 ) {
struct V_28 * V_96 ;
int V_29 ;
F_23 () ;
V_5 = F_119 ( * V_100 , struct V_5 , V_18 ) ;
V_96 = F_44 ( V_5 ) ;
if ( ! V_96 )
return NULL ;
V_29 = F_68 ( V_88 , V_96 ) ;
F_28 ( V_96 ) ;
V_101 = * V_100 ;
if ( V_29 < 0 )
V_100 = & V_101 -> V_98 ;
else if ( V_29 > 0 )
V_100 = & V_101 -> V_99 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_121 ( & V_5 -> V_18 , V_101 , V_100 ) ;
F_122 ( & V_5 -> V_18 , & V_47 ) ;
F_123 ( & V_5 -> V_42 ) ;
V_5 -> V_49 = F_77 ( V_88 ) ;
F_109 ( V_88 , V_5 ) ;
return V_5 ;
}
static
struct V_2 * F_124 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_28 * * V_102 )
{
struct V_97 * * V_100 = & V_59 . V_97 ;
struct V_97 * V_101 = NULL ;
while ( * V_100 ) {
struct V_2 * V_95 ;
struct V_28 * V_96 ;
int V_29 ;
F_23 () ;
V_95 = F_119 ( * V_100 , struct V_2 , V_18 ) ;
V_96 = F_39 ( V_95 ) ;
if ( F_25 ( V_96 ) )
return NULL ;
if ( V_28 == V_96 ) {
F_28 ( V_96 ) ;
return NULL ;
}
V_29 = F_68 ( V_28 , V_96 ) ;
V_101 = * V_100 ;
if ( V_29 < 0 ) {
F_28 ( V_96 ) ;
V_100 = & V_101 -> V_98 ;
} else if ( V_29 > 0 ) {
F_28 ( V_96 ) ;
V_100 = & V_101 -> V_99 ;
} else {
* V_102 = V_96 ;
return V_95 ;
}
}
V_2 -> V_22 |= V_55 ;
V_2 -> V_22 |= ( V_57 . V_58 & V_103 ) ;
F_121 ( & V_2 -> V_18 , V_101 , V_100 ) ;
F_122 ( & V_2 -> V_18 , & V_59 ) ;
V_60 ++ ;
return NULL ;
}
static void F_125 ( struct V_2 * V_2 ,
struct V_5 * V_5 )
{
V_2 -> V_41 = V_5 ;
V_2 -> V_22 |= V_23 ;
F_18 ( & V_2 -> V_42 , & V_5 -> V_42 ) ;
if ( V_2 -> V_42 . V_43 )
V_44 ++ ;
else
V_45 ++ ;
}
static void F_126 ( struct V_28 * V_28 , struct V_2 * V_2 )
{
struct V_2 * V_95 ;
struct V_28 * V_96 = NULL ;
struct V_5 * V_5 ;
struct V_28 * V_88 ;
unsigned int V_76 ;
int V_64 ;
F_49 ( V_2 ) ;
V_88 = F_117 ( V_28 ) ;
if ( V_88 ) {
V_64 = F_114 ( V_2 , V_28 , V_88 ) ;
if ( ! V_64 ) {
F_50 ( V_88 ) ;
F_125 ( V_2 , F_118 ( V_88 ) ) ;
F_52 ( V_88 ) ;
}
F_28 ( V_88 ) ;
return;
}
V_76 = F_64 ( V_28 ) ;
if ( V_2 -> V_104 != V_76 ) {
V_2 -> V_104 = V_76 ;
return;
}
V_95 =
F_124 ( V_2 , V_28 , & V_96 ) ;
if ( V_95 ) {
V_88 = F_116 ( V_2 , V_28 ,
V_95 , V_96 ) ;
F_28 ( V_96 ) ;
if ( V_88 ) {
F_49 ( V_95 ) ;
F_50 ( V_88 ) ;
V_5 = F_120 ( V_88 ) ;
if ( V_5 ) {
F_125 ( V_95 , V_5 ) ;
F_125 ( V_2 , V_5 ) ;
}
F_52 ( V_88 ) ;
if ( ! V_5 ) {
F_31 ( V_95 ) ;
F_31 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_127 ( struct V_8 * V_8 ,
struct V_2 * * V_61 ,
unsigned long V_27 )
{
struct V_2 * V_2 ;
while ( * V_61 ) {
V_2 = * V_61 ;
if ( ( V_2 -> V_22 & V_46 ) == V_27 )
return V_2 ;
if ( V_2 -> V_22 > V_27 )
break;
* V_61 = V_2 -> V_61 ;
F_49 ( V_2 ) ;
F_7 ( V_2 ) ;
}
V_2 = F_5 () ;
if ( V_2 ) {
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_22 = V_27 ;
V_2 -> V_61 = * V_61 ;
* V_61 = V_2 ;
}
return V_2 ;
}
static struct V_2 * F_128 ( struct V_28 * * V_28 )
{
struct V_14 * V_13 ;
struct V_8 * V_105 ;
struct V_25 * V_26 ;
struct V_2 * V_2 ;
if ( F_129 ( & V_69 . V_70 ) )
return NULL ;
V_105 = V_57 . V_8 ;
if ( V_105 == & V_69 ) {
F_130 () ;
V_59 = V_106 ;
F_58 ( & V_68 ) ;
V_105 = F_59 ( V_105 -> V_70 . V_43 , struct V_8 , V_70 ) ;
V_57 . V_8 = V_105 ;
F_60 ( & V_68 ) ;
if ( V_105 == & V_69 )
return NULL ;
V_107:
V_57 . V_22 = 0 ;
V_57 . V_61 = & V_105 -> V_61 ;
}
V_13 = V_105 -> V_13 ;
F_33 ( & V_13 -> V_40 ) ;
if ( F_20 ( V_13 ) )
V_26 = NULL ;
else
V_26 = F_30 ( V_13 , V_57 . V_22 ) ;
for (; V_26 ; V_26 = V_26 -> V_72 ) {
if ( ! ( V_26 -> V_37 & V_38 ) )
continue;
if ( V_57 . V_22 < V_26 -> V_36 )
V_57 . V_22 = V_26 -> V_36 ;
if ( ! V_26 -> V_39 )
V_57 . V_22 = V_26 -> V_73 ;
while ( V_57 . V_22 < V_26 -> V_73 ) {
if ( F_20 ( V_13 ) )
break;
* V_28 = F_24 ( V_26 , V_57 . V_22 , V_30 ) ;
if ( F_25 ( * V_28 ) ) {
V_57 . V_22 += V_65 ;
F_23 () ;
continue;
}
if ( F_38 ( * V_28 ) ||
F_35 ( * V_28 ) ) {
F_40 ( V_26 , * V_28 , V_57 . V_22 ) ;
F_41 ( * V_28 ) ;
V_2 = F_127 ( V_105 ,
V_57 . V_61 , V_57 . V_22 ) ;
if ( V_2 ) {
V_57 . V_61 =
& V_2 -> V_61 ;
V_57 . V_22 += V_65 ;
} else
F_28 ( * V_28 ) ;
F_34 ( & V_13 -> V_40 ) ;
return V_2 ;
}
F_28 ( * V_28 ) ;
V_57 . V_22 += V_65 ;
F_23 () ;
}
}
if ( F_20 ( V_13 ) ) {
V_57 . V_22 = 0 ;
V_57 . V_61 = & V_105 -> V_61 ;
}
F_54 ( V_105 , V_57 . V_61 ) ;
F_58 ( & V_68 ) ;
V_57 . V_8 = F_59 ( V_105 -> V_70 . V_43 ,
struct V_8 , V_70 ) ;
if ( V_57 . V_22 == 0 ) {
F_51 ( & V_105 -> V_21 ) ;
F_61 ( & V_105 -> V_70 ) ;
F_60 ( & V_68 ) ;
F_13 ( V_105 ) ;
F_62 ( V_74 , & V_13 -> V_75 ) ;
F_34 ( & V_13 -> V_40 ) ;
F_63 ( V_13 ) ;
} else {
F_60 ( & V_68 ) ;
F_34 ( & V_13 -> V_40 ) ;
}
V_105 = V_57 . V_8 ;
if ( V_105 != & V_69 )
goto V_107;
V_57 . V_58 ++ ;
return NULL ;
}
static void F_131 ( unsigned int V_108 )
{
struct V_2 * V_2 ;
struct V_28 * V_109 ( V_28 ) ;
while ( V_108 -- && F_132 ( ! F_133 ( V_66 ) ) ) {
F_23 () ;
V_2 = F_128 ( & V_28 ) ;
if ( ! V_2 )
return;
if ( ! F_26 ( V_28 ) || ! F_19 ( V_2 ) )
F_126 ( V_28 , V_2 ) ;
F_28 ( V_28 ) ;
}
}
static int F_134 ( void )
{
return ( V_110 & V_111 ) && ! F_129 ( & V_69 . V_70 ) ;
}
static int F_135 ( void * V_112 )
{
F_136 () ;
F_137 ( V_66 , 5 ) ;
while ( ! F_138 () ) {
F_139 ( & V_113 ) ;
if ( F_134 () )
F_131 ( V_114 ) ;
F_140 ( & V_113 ) ;
F_141 () ;
if ( F_134 () ) {
F_142 (
F_143 ( V_115 ) ) ;
} else {
F_144 ( V_116 ,
F_134 () || F_138 () ) ;
}
}
return 0 ;
}
int F_145 ( struct V_25 * V_26 , unsigned long V_62 ,
unsigned long V_63 , int V_117 , unsigned long * V_37 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
int V_64 ;
switch ( V_117 ) {
case V_118 :
if ( * V_37 & ( V_38 | V_119 | V_120 |
V_121 | V_122 | V_123 |
V_124 | V_125 | V_126 |
V_127 | V_128 | V_129 ) )
return 0 ;
if ( ! F_146 ( V_74 , & V_13 -> V_75 ) ) {
V_64 = F_147 ( V_13 ) ;
if ( V_64 )
return V_64 ;
}
* V_37 |= V_38 ;
break;
case V_130 :
if ( ! ( * V_37 & V_38 ) )
return 0 ;
if ( V_26 -> V_39 ) {
V_64 = F_55 ( V_26 , V_62 , V_63 ) ;
if ( V_64 )
return V_64 ;
}
* V_37 &= ~ V_38 ;
break;
}
return 0 ;
}
int F_147 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_131 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_131 = F_129 ( & V_69 . V_70 ) ;
F_58 ( & V_68 ) ;
F_17 ( V_13 , V_8 ) ;
F_148 ( & V_8 -> V_70 , & V_57 . V_8 -> V_70 ) ;
F_60 ( & V_68 ) ;
F_149 ( V_74 , & V_13 -> V_75 ) ;
F_150 ( & V_13 -> V_132 ) ;
if ( V_131 )
F_151 ( & V_116 ) ;
return 0 ;
}
void F_152 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_133 = 0 ;
F_58 ( & V_68 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_57 . V_8 != V_8 ) {
if ( ! V_8 -> V_61 ) {
F_51 ( & V_8 -> V_21 ) ;
F_61 ( & V_8 -> V_70 ) ;
V_133 = 1 ;
} else {
F_153 ( & V_8 -> V_70 ,
& V_57 . V_8 -> V_70 ) ;
}
}
F_60 ( & V_68 ) ;
if ( V_133 ) {
F_13 ( V_8 ) ;
F_62 ( V_74 , & V_13 -> V_75 ) ;
F_63 ( V_13 ) ;
} else if ( V_8 ) {
F_154 ( & V_13 -> V_40 ) ;
F_155 ( & V_13 -> V_40 ) ;
}
}
struct V_28 * F_156 ( struct V_28 * V_28 ,
struct V_25 * V_26 , unsigned long V_22 )
{
struct V_28 * V_134 ;
V_134 = F_157 ( V_135 , V_26 , V_22 ) ;
if ( V_134 ) {
F_158 ( V_134 , V_28 , V_22 , V_26 ) ;
F_159 ( V_134 ) ;
F_160 ( V_134 ) ;
F_161 ( V_134 ) ;
F_162 ( V_134 ) ;
if ( F_163 ( V_134 , V_26 ) )
F_164 ( V_134 , V_136 ) ;
else
F_165 ( V_134 ) ;
}
return V_134 ;
}
int F_166 ( struct V_28 * V_28 , struct V_137 * V_138 ,
unsigned long * V_37 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
struct V_17 * V_42 ;
unsigned int V_139 = F_79 ( V_28 ) ;
int V_140 = 0 ;
int V_141 = 0 ;
F_167 ( ! F_26 ( V_28 ) ) ;
F_167 ( ! F_168 ( V_28 ) ) ;
V_5 = F_118 ( V_28 ) ;
if ( ! V_5 )
return 0 ;
V_142:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_143 * V_144 ;
struct V_25 * V_26 ;
F_169 ( V_39 ) ;
F_170 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_144 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_141 )
continue;
if ( V_138 && ! F_171 ( V_26 -> V_31 , V_138 ) )
continue;
V_140 += F_172 ( V_28 , V_26 ,
V_2 -> V_22 , & V_139 , V_37 ) ;
if ( ! V_141 || ! V_139 )
break;
}
F_173 ( V_39 ) ;
if ( ! V_139 )
goto V_3;
}
if ( ! V_141 ++ )
goto V_142;
V_3:
return V_140 ;
}
int F_174 ( struct V_28 * V_28 , enum V_145 V_75 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_146 ;
int V_141 = 0 ;
F_167 ( ! F_26 ( V_28 ) ) ;
F_167 ( ! F_168 ( V_28 ) ) ;
V_5 = F_118 ( V_28 ) ;
if ( ! V_5 )
return V_147 ;
V_142:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_143 * V_144 ;
struct V_25 * V_26 ;
F_169 ( V_39 ) ;
F_170 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_144 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_141 )
continue;
V_29 = F_175 ( V_28 , V_26 ,
V_2 -> V_22 , V_75 ) ;
if ( V_29 != V_146 || ! F_102 ( V_28 ) ) {
F_173 ( V_39 ) ;
goto V_3;
}
}
F_173 ( V_39 ) ;
}
if ( ! V_141 ++ )
goto V_142;
V_3:
return V_29 ;
}
int F_176 ( struct V_28 * V_28 , int (* F_177)( struct V_28 * ,
struct V_25 * , unsigned long , void * ) , void * V_148 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_146 ;
int V_141 = 0 ;
F_167 ( ! F_26 ( V_28 ) ) ;
F_167 ( ! F_168 ( V_28 ) ) ;
V_5 = F_118 ( V_28 ) ;
if ( ! V_5 )
return V_29 ;
V_142:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_143 * V_144 ;
struct V_25 * V_26 ;
F_169 ( V_39 ) ;
F_170 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_144 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_141 )
continue;
V_29 = F_177 ( V_28 , V_26 , V_2 -> V_22 , V_148 ) ;
if ( V_29 != V_146 ) {
F_173 ( V_39 ) ;
goto V_3;
}
}
F_173 ( V_39 ) ;
}
if ( ! V_141 ++ )
goto V_142;
V_3:
return V_29 ;
}
void F_178 ( struct V_28 * V_149 , struct V_28 * V_150 )
{
struct V_5 * V_5 ;
F_167 ( ! F_168 ( V_150 ) ) ;
F_167 ( ! F_168 ( V_149 ) ) ;
F_167 ( V_149 -> V_52 != V_150 -> V_52 ) ;
V_5 = F_118 ( V_149 ) ;
if ( V_5 ) {
F_167 ( V_5 -> V_49 != F_77 ( V_150 ) ) ;
V_5 -> V_49 = F_77 ( V_149 ) ;
}
}
static struct V_5 * F_179 ( unsigned long V_151 ,
unsigned long V_152 )
{
struct V_97 * V_18 ;
for ( V_18 = F_180 ( & V_47 ) ; V_18 ; V_18 = F_181 ( V_18 ) ) {
struct V_5 * V_5 ;
V_5 = F_119 ( V_18 , struct V_5 , V_18 ) ;
if ( V_5 -> V_49 >= V_151 &&
V_5 -> V_49 < V_152 )
return V_5 ;
}
return NULL ;
}
static int F_182 ( struct V_153 * V_154 ,
unsigned long V_155 , void * V_148 )
{
struct V_156 * V_157 = V_148 ;
struct V_5 * V_5 ;
switch ( V_155 ) {
case V_158 :
F_183 ( & V_113 , V_159 ) ;
break;
case V_160 :
while ( ( V_5 = F_179 ( V_157 -> V_151 ,
V_157 -> V_151 + V_157 -> V_161 ) ) != NULL )
F_42 ( V_5 ) ;
case V_162 :
F_140 ( & V_113 ) ;
break;
}
return V_163 ;
}
static T_8 F_184 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_1 , V_115 ) ;
}
static T_8 F_185 ( struct V_164 * V_165 ,
struct V_166 * V_167 ,
const char * V_168 , T_9 V_169 )
{
unsigned long V_170 ;
int V_64 ;
V_64 = F_186 ( V_168 , 10 , & V_170 ) ;
if ( V_64 || V_170 > V_171 )
return - V_172 ;
V_115 = V_170 ;
return V_169 ;
}
static T_8 F_187 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_1 , V_114 ) ;
}
static T_8 F_188 ( struct V_164 * V_165 ,
struct V_166 * V_167 ,
const char * V_168 , T_9 V_169 )
{
int V_64 ;
unsigned long V_161 ;
V_64 = F_186 ( V_168 , 10 , & V_161 ) ;
if ( V_64 || V_161 > V_171 )
return - V_172 ;
V_114 = V_161 ;
return V_169 ;
}
static T_8 F_189 ( struct V_164 * V_165 , struct V_166 * V_167 ,
char * V_168 )
{
return sprintf ( V_168 , L_1 , V_110 ) ;
}
static T_8 F_190 ( struct V_164 * V_165 , struct V_166 * V_167 ,
const char * V_168 , T_9 V_169 )
{
int V_64 ;
unsigned long V_75 ;
V_64 = F_186 ( V_168 , 10 , & V_75 ) ;
if ( V_64 || V_75 > V_171 )
return - V_172 ;
if ( V_75 > V_173 )
return - V_172 ;
F_139 ( & V_113 ) ;
if ( V_110 != V_75 ) {
V_110 = V_75 ;
if ( V_75 & V_173 ) {
int V_174 ;
V_174 = F_191 ( V_175 ) ;
V_64 = F_57 () ;
F_192 ( V_175 ,
V_174 ) ;
if ( V_64 ) {
V_110 = V_176 ;
V_169 = V_64 ;
}
}
}
F_140 ( & V_113 ) ;
if ( V_75 & V_111 )
F_151 ( & V_116 ) ;
return V_169 ;
}
static T_8 F_193 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_2 , V_45 ) ;
}
static T_8 F_194 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_2 , V_44 ) ;
}
static T_8 F_195 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_2 , V_60 ) ;
}
static T_8 F_196 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
long V_177 ;
V_177 = V_12 - V_45
- V_44 - V_60 ;
if ( V_177 < 0 )
V_177 = 0 ;
return sprintf ( V_168 , L_3 , V_177 ) ;
}
static T_8 F_197 ( struct V_164 * V_165 ,
struct V_166 * V_167 , char * V_168 )
{
return sprintf ( V_168 , L_2 , V_57 . V_58 ) ;
}
static int T_1 F_198 ( void )
{
struct V_178 * V_179 ;
int V_64 ;
V_64 = F_1 () ;
if ( V_64 )
goto V_3;
V_179 = F_199 ( F_135 , NULL , L_4 ) ;
if ( F_200 ( V_179 ) ) {
F_201 ( V_180 L_5 ) ;
V_64 = F_202 ( V_179 ) ;
goto V_181;
}
#ifdef F_203
V_64 = F_204 ( V_182 , & V_183 ) ;
if ( V_64 ) {
F_201 ( V_180 L_6 ) ;
F_205 ( V_179 ) ;
goto V_181;
}
#else
V_110 = V_111 ;
#endif
#ifdef F_206
F_207 ( F_182 , 100 ) ;
#endif
return 0 ;
V_181:
F_4 () ;
V_3:
return V_64 ;
}
