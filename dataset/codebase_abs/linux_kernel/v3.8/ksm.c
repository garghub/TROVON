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
unsigned long V_86 ;
unsigned long V_87 ;
V_27 = F_71 ( V_28 , V_26 ) ;
if ( V_27 == - V_85 )
goto V_3;
F_53 ( F_36 ( V_28 ) ) ;
V_86 = V_27 ;
V_87 = V_27 + V_65 ;
F_72 ( V_13 , V_86 , V_87 ) ;
V_82 = F_73 ( V_28 , V_13 , V_27 , & V_83 , 0 ) ;
if ( ! V_82 )
goto V_88;
if ( F_74 ( * V_82 ) || F_75 ( * V_82 ) ) {
T_3 V_89 ;
V_84 = F_76 ( V_28 ) ;
F_77 ( V_26 , V_27 , F_78 ( V_28 ) ) ;
V_89 = F_79 ( V_26 , V_27 , V_82 ) ;
if ( F_80 ( V_28 ) + 1 + V_84 != F_81 ( V_28 ) ) {
F_82 ( V_13 , V_27 , V_82 , V_89 ) ;
goto V_90;
}
if ( F_75 ( V_89 ) )
F_83 ( V_28 ) ;
V_89 = F_84 ( F_85 ( V_89 ) ) ;
F_86 ( V_13 , V_27 , V_82 , V_89 ) ;
}
* V_81 = * V_82 ;
V_64 = 0 ;
V_90:
F_87 ( V_82 , V_83 ) ;
V_88:
F_88 ( V_13 , V_86 , V_87 ) ;
V_3:
return V_64 ;
}
static int F_89 ( struct V_25 * V_26 , struct V_28 * V_28 ,
struct V_28 * V_91 , T_3 V_81 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
T_5 * V_92 ;
T_3 * V_82 ;
T_4 * V_83 ;
unsigned long V_27 ;
int V_64 = - V_85 ;
unsigned long V_86 ;
unsigned long V_87 ;
V_27 = F_71 ( V_28 , V_26 ) ;
if ( V_27 == - V_85 )
goto V_3;
V_92 = F_90 ( V_13 , V_27 ) ;
if ( ! V_92 )
goto V_3;
F_53 ( F_91 ( * V_92 ) ) ;
V_86 = V_27 ;
V_87 = V_27 + V_65 ;
F_72 ( V_13 , V_86 , V_87 ) ;
V_82 = F_92 ( V_13 , V_92 , V_27 , & V_83 ) ;
if ( ! F_93 ( * V_82 , V_81 ) ) {
F_87 ( V_82 , V_83 ) ;
goto V_88;
}
F_94 ( V_91 ) ;
F_95 ( V_91 , V_26 , V_27 ) ;
F_77 ( V_26 , V_27 , F_96 ( * V_82 ) ) ;
F_79 ( V_26 , V_27 , V_82 ) ;
F_86 ( V_13 , V_27 , V_82 , F_97 ( V_91 , V_26 -> V_93 ) ) ;
F_98 ( V_28 ) ;
if ( ! F_99 ( V_28 ) )
F_100 ( V_28 ) ;
F_28 ( V_28 ) ;
F_87 ( V_82 , V_83 ) ;
V_64 = 0 ;
V_88:
F_88 ( V_13 , V_86 , V_87 ) ;
V_3:
return V_64 ;
}
static int F_101 ( struct V_28 * V_28 )
{
int V_29 = 0 ;
struct V_28 * V_94 = F_35 ( V_28 ) ;
if ( V_94 ) {
if ( F_47 ( V_94 ) ) {
if ( F_38 ( V_94 ) )
V_29 = F_102 ( V_94 ) ;
else
V_29 = 1 ;
F_28 ( V_94 ) ;
} else
V_29 = 1 ;
}
return V_29 ;
}
static int F_103 ( struct V_25 * V_26 ,
struct V_28 * V_28 , struct V_28 * V_91 )
{
T_3 V_81 = F_104 ( 0 ) ;
int V_64 = - V_85 ;
if ( V_28 == V_91 )
return 0 ;
if ( ! ( V_26 -> V_37 & V_38 ) )
goto V_3;
if ( F_36 ( V_28 ) && F_101 ( V_28 ) )
goto V_3;
F_53 ( F_36 ( V_28 ) ) ;
if ( ! F_38 ( V_28 ) )
goto V_3;
if ( ! F_105 ( V_28 ) )
goto V_3;
if ( F_70 ( V_26 , V_28 , & V_81 ) == 0 ) {
if ( ! V_91 ) {
F_106 ( V_28 , NULL ) ;
F_107 ( V_28 ) ;
V_64 = 0 ;
} else if ( F_69 ( V_28 , V_91 ) )
V_64 = F_89 ( V_26 , V_28 , V_91 , V_81 ) ;
}
if ( ( V_26 -> V_37 & V_95 ) && V_91 && ! V_64 ) {
F_108 ( V_28 ) ;
if ( ! F_109 ( V_91 ) ) {
F_52 ( V_28 ) ;
F_50 ( V_91 ) ;
F_110 ( V_91 ) ;
V_28 = V_91 ;
}
}
F_52 ( V_28 ) ;
V_3:
return V_64 ;
}
static int F_111 ( struct V_2 * V_2 ,
struct V_28 * V_28 , struct V_28 * V_91 )
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
V_64 = F_103 ( V_26 , V_28 , V_91 ) ;
if ( V_64 )
goto V_3;
V_2 -> V_39 = V_26 -> V_39 ;
F_112 ( V_26 -> V_39 ) ;
V_3:
F_34 ( & V_13 -> V_40 ) ;
return V_64 ;
}
static struct V_28 * F_113 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_2 * V_96 ,
struct V_28 * V_97 )
{
int V_64 ;
V_64 = F_111 ( V_2 , V_28 , NULL ) ;
if ( ! V_64 ) {
V_64 = F_111 ( V_96 ,
V_97 , V_28 ) ;
if ( V_64 )
F_31 ( V_2 ) ;
}
return V_64 ? NULL : V_28 ;
}
static struct V_28 * F_114 ( struct V_28 * V_28 )
{
struct V_98 * V_18 = V_47 . V_98 ;
struct V_5 * V_5 ;
V_5 = F_115 ( V_28 ) ;
if ( V_5 ) {
F_94 ( V_28 ) ;
return V_28 ;
}
while ( V_18 ) {
struct V_28 * V_97 ;
int V_29 ;
F_23 () ;
V_5 = F_116 ( V_18 , struct V_5 , V_18 ) ;
V_97 = F_44 ( V_5 ) ;
if ( ! V_97 )
return NULL ;
V_29 = F_68 ( V_28 , V_97 ) ;
if ( V_29 < 0 ) {
F_28 ( V_97 ) ;
V_18 = V_18 -> V_99 ;
} else if ( V_29 > 0 ) {
F_28 ( V_97 ) ;
V_18 = V_18 -> V_100 ;
} else
return V_97 ;
}
return NULL ;
}
static struct V_5 * F_117 ( struct V_28 * V_91 )
{
struct V_98 * * V_101 = & V_47 . V_98 ;
struct V_98 * V_102 = NULL ;
struct V_5 * V_5 ;
while ( * V_101 ) {
struct V_28 * V_97 ;
int V_29 ;
F_23 () ;
V_5 = F_116 ( * V_101 , struct V_5 , V_18 ) ;
V_97 = F_44 ( V_5 ) ;
if ( ! V_97 )
return NULL ;
V_29 = F_68 ( V_91 , V_97 ) ;
F_28 ( V_97 ) ;
V_102 = * V_101 ;
if ( V_29 < 0 )
V_101 = & V_102 -> V_99 ;
else if ( V_29 > 0 )
V_101 = & V_102 -> V_100 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_118 ( & V_5 -> V_18 , V_102 , V_101 ) ;
F_119 ( & V_5 -> V_18 , & V_47 ) ;
F_120 ( & V_5 -> V_42 ) ;
V_5 -> V_49 = F_78 ( V_91 ) ;
F_106 ( V_91 , V_5 ) ;
return V_5 ;
}
static
struct V_2 * F_121 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_28 * * V_103 )
{
struct V_98 * * V_101 = & V_59 . V_98 ;
struct V_98 * V_102 = NULL ;
while ( * V_101 ) {
struct V_2 * V_96 ;
struct V_28 * V_97 ;
int V_29 ;
F_23 () ;
V_96 = F_116 ( * V_101 , struct V_2 , V_18 ) ;
V_97 = F_39 ( V_96 ) ;
if ( F_25 ( V_97 ) )
return NULL ;
if ( V_28 == V_97 ) {
F_28 ( V_97 ) ;
return NULL ;
}
V_29 = F_68 ( V_28 , V_97 ) ;
V_102 = * V_101 ;
if ( V_29 < 0 ) {
F_28 ( V_97 ) ;
V_101 = & V_102 -> V_99 ;
} else if ( V_29 > 0 ) {
F_28 ( V_97 ) ;
V_101 = & V_102 -> V_100 ;
} else {
* V_103 = V_97 ;
return V_96 ;
}
}
V_2 -> V_22 |= V_55 ;
V_2 -> V_22 |= ( V_57 . V_58 & V_104 ) ;
F_118 ( & V_2 -> V_18 , V_102 , V_101 ) ;
F_119 ( & V_2 -> V_18 , & V_59 ) ;
V_60 ++ ;
return NULL ;
}
static void F_122 ( struct V_2 * V_2 ,
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
static void F_123 ( struct V_28 * V_28 , struct V_2 * V_2 )
{
struct V_2 * V_96 ;
struct V_28 * V_97 = NULL ;
struct V_5 * V_5 ;
struct V_28 * V_91 ;
unsigned int V_76 ;
int V_64 ;
F_49 ( V_2 ) ;
V_91 = F_114 ( V_28 ) ;
if ( V_91 ) {
V_64 = F_111 ( V_2 , V_28 , V_91 ) ;
if ( ! V_64 ) {
F_50 ( V_91 ) ;
F_122 ( V_2 , F_115 ( V_91 ) ) ;
F_52 ( V_91 ) ;
}
F_28 ( V_91 ) ;
return;
}
V_76 = F_64 ( V_28 ) ;
if ( V_2 -> V_105 != V_76 ) {
V_2 -> V_105 = V_76 ;
return;
}
V_96 =
F_121 ( V_2 , V_28 , & V_97 ) ;
if ( V_96 ) {
V_91 = F_113 ( V_2 , V_28 ,
V_96 , V_97 ) ;
F_28 ( V_97 ) ;
if ( V_91 ) {
F_49 ( V_96 ) ;
F_50 ( V_91 ) ;
V_5 = F_117 ( V_91 ) ;
if ( V_5 ) {
F_122 ( V_96 , V_5 ) ;
F_122 ( V_2 , V_5 ) ;
}
F_52 ( V_91 ) ;
if ( ! V_5 ) {
F_31 ( V_96 ) ;
F_31 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_124 ( struct V_8 * V_8 ,
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
static struct V_2 * F_125 ( struct V_28 * * V_28 )
{
struct V_14 * V_13 ;
struct V_8 * V_106 ;
struct V_25 * V_26 ;
struct V_2 * V_2 ;
if ( F_126 ( & V_69 . V_70 ) )
return NULL ;
V_106 = V_57 . V_8 ;
if ( V_106 == & V_69 ) {
F_127 () ;
V_59 = V_107 ;
F_58 ( & V_68 ) ;
V_106 = F_59 ( V_106 -> V_70 . V_43 , struct V_8 , V_70 ) ;
V_57 . V_8 = V_106 ;
F_60 ( & V_68 ) ;
if ( V_106 == & V_69 )
return NULL ;
V_108:
V_57 . V_22 = 0 ;
V_57 . V_61 = & V_106 -> V_61 ;
}
V_13 = V_106 -> V_13 ;
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
V_2 = F_124 ( V_106 ,
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
V_57 . V_61 = & V_106 -> V_61 ;
}
F_54 ( V_106 , V_57 . V_61 ) ;
F_58 ( & V_68 ) ;
V_57 . V_8 = F_59 ( V_106 -> V_70 . V_43 ,
struct V_8 , V_70 ) ;
if ( V_57 . V_22 == 0 ) {
F_51 ( & V_106 -> V_21 ) ;
F_61 ( & V_106 -> V_70 ) ;
F_60 ( & V_68 ) ;
F_13 ( V_106 ) ;
F_62 ( V_74 , & V_13 -> V_75 ) ;
F_34 ( & V_13 -> V_40 ) ;
F_63 ( V_13 ) ;
} else {
F_60 ( & V_68 ) ;
F_34 ( & V_13 -> V_40 ) ;
}
V_106 = V_57 . V_8 ;
if ( V_106 != & V_69 )
goto V_108;
V_57 . V_58 ++ ;
return NULL ;
}
static void F_128 ( unsigned int V_109 )
{
struct V_2 * V_2 ;
struct V_28 * V_110 ( V_28 ) ;
while ( V_109 -- && F_129 ( ! F_130 ( V_66 ) ) ) {
F_23 () ;
V_2 = F_125 ( & V_28 ) ;
if ( ! V_2 )
return;
if ( ! F_26 ( V_28 ) || ! F_19 ( V_2 ) )
F_123 ( V_28 , V_2 ) ;
F_28 ( V_28 ) ;
}
}
static int F_131 ( void )
{
return ( V_111 & V_112 ) && ! F_126 ( & V_69 . V_70 ) ;
}
static int F_132 ( void * V_113 )
{
F_133 () ;
F_134 ( V_66 , 5 ) ;
while ( ! F_135 () ) {
F_136 ( & V_114 ) ;
if ( F_131 () )
F_128 ( V_115 ) ;
F_137 ( & V_114 ) ;
F_138 () ;
if ( F_131 () ) {
F_139 (
F_140 ( V_116 ) ) ;
} else {
F_141 ( V_117 ,
F_131 () || F_135 () ) ;
}
}
return 0 ;
}
int F_142 ( struct V_25 * V_26 , unsigned long V_62 ,
unsigned long V_63 , int V_118 , unsigned long * V_37 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
int V_64 ;
switch ( V_118 ) {
case V_119 :
if ( * V_37 & ( V_38 | V_120 | V_121 |
V_122 | V_123 | V_124 |
V_125 | V_126 | V_127 ) )
return 0 ;
#ifdef F_143
if ( * V_37 & F_143 )
return 0 ;
#endif
if ( ! F_144 ( V_74 , & V_13 -> V_75 ) ) {
V_64 = F_145 ( V_13 ) ;
if ( V_64 )
return V_64 ;
}
* V_37 |= V_38 ;
break;
case V_128 :
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
int F_145 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_129 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_129 = F_126 ( & V_69 . V_70 ) ;
F_58 ( & V_68 ) ;
F_17 ( V_13 , V_8 ) ;
F_146 ( & V_8 -> V_70 , & V_57 . V_8 -> V_70 ) ;
F_60 ( & V_68 ) ;
F_147 ( V_74 , & V_13 -> V_75 ) ;
F_148 ( & V_13 -> V_130 ) ;
if ( V_129 )
F_149 ( & V_117 ) ;
return 0 ;
}
void F_150 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_131 = 0 ;
F_58 ( & V_68 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_57 . V_8 != V_8 ) {
if ( ! V_8 -> V_61 ) {
F_51 ( & V_8 -> V_21 ) ;
F_61 ( & V_8 -> V_70 ) ;
V_131 = 1 ;
} else {
F_151 ( & V_8 -> V_70 ,
& V_57 . V_8 -> V_70 ) ;
}
}
F_60 ( & V_68 ) ;
if ( V_131 ) {
F_13 ( V_8 ) ;
F_62 ( V_74 , & V_13 -> V_75 ) ;
F_63 ( V_13 ) ;
} else if ( V_8 ) {
F_152 ( & V_13 -> V_40 ) ;
F_153 ( & V_13 -> V_40 ) ;
}
}
struct V_28 * F_154 ( struct V_28 * V_28 ,
struct V_25 * V_26 , unsigned long V_22 )
{
struct V_28 * V_132 ;
V_132 = F_155 ( V_133 , V_26 , V_22 ) ;
if ( V_132 ) {
F_156 ( V_132 , V_28 , V_22 , V_26 ) ;
F_157 ( V_132 ) ;
F_158 ( V_132 ) ;
F_159 ( V_132 ) ;
F_160 ( V_132 ) ;
if ( ! F_161 ( V_26 , V_132 ) )
F_162 ( V_132 , V_134 ) ;
else
F_163 ( V_132 ) ;
}
return V_132 ;
}
int F_164 ( struct V_28 * V_28 , struct V_135 * V_136 ,
unsigned long * V_37 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
struct V_17 * V_42 ;
unsigned int V_137 = F_80 ( V_28 ) ;
int V_138 = 0 ;
int V_139 = 0 ;
F_165 ( ! F_26 ( V_28 ) ) ;
F_165 ( ! F_166 ( V_28 ) ) ;
V_5 = F_115 ( V_28 ) ;
if ( ! V_5 )
return 0 ;
V_140:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_141 * V_142 ;
struct V_25 * V_26 ;
F_167 ( V_39 ) ;
F_168 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
V_26 = V_142 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_139 )
continue;
if ( V_136 && ! F_169 ( V_26 -> V_31 , V_136 ) )
continue;
V_138 += F_170 ( V_28 , V_26 ,
V_2 -> V_22 , & V_137 , V_37 ) ;
if ( ! V_139 || ! V_137 )
break;
}
F_171 ( V_39 ) ;
if ( ! V_137 )
goto V_3;
}
if ( ! V_139 ++ )
goto V_140;
V_3:
return V_138 ;
}
int F_172 ( struct V_28 * V_28 , enum V_143 V_75 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_144 ;
int V_139 = 0 ;
F_165 ( ! F_26 ( V_28 ) ) ;
F_165 ( ! F_166 ( V_28 ) ) ;
V_5 = F_115 ( V_28 ) ;
if ( ! V_5 )
return V_145 ;
V_140:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_141 * V_142 ;
struct V_25 * V_26 ;
F_167 ( V_39 ) ;
F_168 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
V_26 = V_142 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_139 )
continue;
V_29 = F_173 ( V_28 , V_26 ,
V_2 -> V_22 , V_75 ) ;
if ( V_29 != V_144 || ! F_99 ( V_28 ) ) {
F_171 ( V_39 ) ;
goto V_3;
}
}
F_171 ( V_39 ) ;
}
if ( ! V_139 ++ )
goto V_140;
V_3:
return V_29 ;
}
int F_174 ( struct V_28 * V_28 , int (* F_175)( struct V_28 * ,
struct V_25 * , unsigned long , void * ) , void * V_146 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_144 ;
int V_139 = 0 ;
F_165 ( ! F_26 ( V_28 ) ) ;
F_165 ( ! F_166 ( V_28 ) ) ;
V_5 = F_115 ( V_28 ) ;
if ( ! V_5 )
return V_29 ;
V_140:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_39 * V_39 = V_2 -> V_39 ;
struct V_141 * V_142 ;
struct V_25 * V_26 ;
F_167 ( V_39 ) ;
F_168 (vmac, &anon_vma->rb_root,
0 , ULONG_MAX) {
V_26 = V_142 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_36 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_139 )
continue;
V_29 = F_175 ( V_28 , V_26 , V_2 -> V_22 , V_146 ) ;
if ( V_29 != V_144 ) {
F_171 ( V_39 ) ;
goto V_3;
}
}
F_171 ( V_39 ) ;
}
if ( ! V_139 ++ )
goto V_140;
V_3:
return V_29 ;
}
void F_176 ( struct V_28 * V_147 , struct V_28 * V_148 )
{
struct V_5 * V_5 ;
F_165 ( ! F_166 ( V_148 ) ) ;
F_165 ( ! F_166 ( V_147 ) ) ;
F_165 ( V_147 -> V_52 != V_148 -> V_52 ) ;
V_5 = F_115 ( V_147 ) ;
if ( V_5 ) {
F_165 ( V_5 -> V_49 != F_78 ( V_148 ) ) ;
V_5 -> V_49 = F_78 ( V_147 ) ;
}
}
static struct V_5 * F_177 ( unsigned long V_149 ,
unsigned long V_150 )
{
struct V_98 * V_18 ;
for ( V_18 = F_178 ( & V_47 ) ; V_18 ; V_18 = F_179 ( V_18 ) ) {
struct V_5 * V_5 ;
V_5 = F_116 ( V_18 , struct V_5 , V_18 ) ;
if ( V_5 -> V_49 >= V_149 &&
V_5 -> V_49 < V_150 )
return V_5 ;
}
return NULL ;
}
static int F_180 ( struct V_151 * V_152 ,
unsigned long V_153 , void * V_146 )
{
struct V_154 * V_155 = V_146 ;
struct V_5 * V_5 ;
switch ( V_153 ) {
case V_156 :
F_181 ( & V_114 , V_157 ) ;
break;
case V_158 :
while ( ( V_5 = F_177 ( V_155 -> V_149 ,
V_155 -> V_149 + V_155 -> V_159 ) ) != NULL )
F_42 ( V_5 ) ;
case V_160 :
F_137 ( & V_114 ) ;
break;
}
return V_161 ;
}
static T_6 F_182 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_1 , V_116 ) ;
}
static T_6 F_183 ( struct V_162 * V_163 ,
struct V_164 * V_165 ,
const char * V_166 , T_7 V_167 )
{
unsigned long V_168 ;
int V_64 ;
V_64 = F_184 ( V_166 , 10 , & V_168 ) ;
if ( V_64 || V_168 > V_169 )
return - V_170 ;
V_116 = V_168 ;
return V_167 ;
}
static T_6 F_185 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_1 , V_115 ) ;
}
static T_6 F_186 ( struct V_162 * V_163 ,
struct V_164 * V_165 ,
const char * V_166 , T_7 V_167 )
{
int V_64 ;
unsigned long V_159 ;
V_64 = F_184 ( V_166 , 10 , & V_159 ) ;
if ( V_64 || V_159 > V_169 )
return - V_170 ;
V_115 = V_159 ;
return V_167 ;
}
static T_6 F_187 ( struct V_162 * V_163 , struct V_164 * V_165 ,
char * V_166 )
{
return sprintf ( V_166 , L_1 , V_111 ) ;
}
static T_6 F_188 ( struct V_162 * V_163 , struct V_164 * V_165 ,
const char * V_166 , T_7 V_167 )
{
int V_64 ;
unsigned long V_75 ;
V_64 = F_184 ( V_166 , 10 , & V_75 ) ;
if ( V_64 || V_75 > V_169 )
return - V_170 ;
if ( V_75 > V_171 )
return - V_170 ;
F_136 ( & V_114 ) ;
if ( V_111 != V_75 ) {
V_111 = V_75 ;
if ( V_75 & V_171 ) {
F_189 () ;
V_64 = F_57 () ;
F_190 () ;
if ( V_64 ) {
V_111 = V_172 ;
V_167 = V_64 ;
}
}
}
F_137 ( & V_114 ) ;
if ( V_75 & V_112 )
F_149 ( & V_117 ) ;
return V_167 ;
}
static T_6 F_191 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_2 , V_45 ) ;
}
static T_6 F_192 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_2 , V_44 ) ;
}
static T_6 F_193 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_2 , V_60 ) ;
}
static T_6 F_194 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
long V_173 ;
V_173 = V_12 - V_45
- V_44 - V_60 ;
if ( V_173 < 0 )
V_173 = 0 ;
return sprintf ( V_166 , L_3 , V_173 ) ;
}
static T_6 F_195 ( struct V_162 * V_163 ,
struct V_164 * V_165 , char * V_166 )
{
return sprintf ( V_166 , L_2 , V_57 . V_58 ) ;
}
static int T_1 F_196 ( void )
{
struct V_174 * V_175 ;
int V_64 ;
V_64 = F_1 () ;
if ( V_64 )
goto V_3;
V_175 = F_197 ( F_132 , NULL , L_4 ) ;
if ( F_198 ( V_175 ) ) {
F_199 ( V_176 L_5 ) ;
V_64 = F_200 ( V_175 ) ;
goto V_177;
}
#ifdef F_201
V_64 = F_202 ( V_178 , & V_179 ) ;
if ( V_64 ) {
F_199 ( V_176 L_6 ) ;
F_203 ( V_175 ) ;
goto V_177;
}
#else
V_111 = V_112 ;
#endif
#ifdef F_204
F_205 ( F_180 , 100 ) ;
#endif
return 0 ;
V_177:
F_4 () ;
V_3:
return V_64 ;
}
