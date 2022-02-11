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
static void F_29 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_27 = V_2 -> V_22 ;
struct V_25 * V_26 ;
F_30 ( V_2 -> V_36 ) ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_20 ( V_13 ) )
goto V_3;
V_26 = F_32 ( V_13 , V_27 ) ;
if ( ! V_26 || V_26 -> V_38 > V_27 )
goto V_3;
if ( ! ( V_26 -> V_39 & V_40 ) || ! V_26 -> V_36 )
goto V_3;
F_22 ( V_26 , V_27 ) ;
V_3:
F_33 ( & V_13 -> V_37 ) ;
}
static struct V_28 * F_34 ( struct V_28 * V_28 )
{
if ( F_35 ( V_28 ) ) {
struct V_28 * V_41 = F_36 ( V_28 ) ;
if ( F_37 ( V_41 ) )
return V_41 ;
}
return NULL ;
}
static struct V_28 * F_38 ( struct V_2 * V_2 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
unsigned long V_27 = V_2 -> V_22 ;
struct V_25 * V_26 ;
struct V_28 * V_28 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_20 ( V_13 ) )
goto V_3;
V_26 = F_32 ( V_13 , V_27 ) ;
if ( ! V_26 || V_26 -> V_38 > V_27 )
goto V_3;
if ( ! ( V_26 -> V_39 & V_40 ) || ! V_26 -> V_36 )
goto V_3;
V_28 = F_24 ( V_26 , V_27 , V_30 ) ;
if ( F_25 ( V_28 ) )
goto V_3;
if ( F_37 ( V_28 ) || F_34 ( V_28 ) ) {
F_39 ( V_26 , V_28 , V_27 ) ;
F_40 ( V_28 ) ;
} else {
F_28 ( V_28 ) ;
V_3: V_28 = NULL ;
}
F_33 ( & V_13 -> V_37 ) ;
return V_28 ;
}
static void F_41 ( struct V_5 * V_5 )
{
struct V_2 * V_2 ;
struct V_17 * V_42 ;
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
if ( V_2 -> V_42 . V_43 )
V_44 -- ;
else
V_45 -- ;
F_30 ( V_2 -> V_36 ) ;
V_2 -> V_22 &= V_46 ;
F_23 () ;
}
F_42 ( & V_5 -> V_18 , & V_47 ) ;
F_11 ( V_5 ) ;
}
static struct V_28 * F_43 ( struct V_5 * V_5 )
{
struct V_28 * V_28 ;
void * V_48 ;
V_28 = F_44 ( V_5 -> V_49 ) ;
V_48 = ( void * ) V_5 +
( V_50 | V_51 ) ;
F_45 () ;
if ( V_28 -> V_52 != V_48 )
goto V_53;
if ( ! F_46 ( V_28 ) )
goto V_53;
if ( V_28 -> V_52 != V_48 ) {
F_28 ( V_28 ) ;
goto V_53;
}
F_47 () ;
return V_28 ;
V_53:
F_47 () ;
F_41 ( V_5 ) ;
return NULL ;
}
static void F_48 ( struct V_2 * V_2 )
{
if ( V_2 -> V_22 & V_23 ) {
struct V_5 * V_5 ;
struct V_28 * V_28 ;
V_5 = V_2 -> V_41 ;
V_28 = F_43 ( V_5 ) ;
if ( ! V_28 )
goto V_3;
F_49 ( V_28 ) ;
F_50 ( & V_2 -> V_42 ) ;
F_51 ( V_28 ) ;
F_28 ( V_28 ) ;
if ( V_5 -> V_42 . V_54 )
V_44 -- ;
else
V_45 -- ;
F_30 ( V_2 -> V_36 ) ;
V_2 -> V_22 &= V_46 ;
} else if ( V_2 -> V_22 & V_55 ) {
unsigned char V_56 ;
V_56 = ( unsigned char ) ( V_57 . V_58 - V_2 -> V_22 ) ;
F_52 ( V_56 > 1 ) ;
if ( ! V_56 )
F_42 ( & V_2 -> V_18 , & V_59 ) ;
V_60 -- ;
V_2 -> V_22 &= V_46 ;
}
V_3:
F_23 () ;
}
static void F_53 ( struct V_8 * V_8 ,
struct V_2 * * V_61 )
{
while ( * V_61 ) {
struct V_2 * V_2 = * V_61 ;
* V_61 = V_2 -> V_61 ;
F_48 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static int F_54 ( struct V_25 * V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
unsigned long V_27 ;
int V_64 = 0 ;
for ( V_27 = V_62 ; V_27 < V_63 && ! V_64 ; V_27 += V_65 ) {
if ( F_20 ( V_26 -> V_31 ) )
break;
if ( F_55 ( V_66 ) )
V_64 = - V_67 ;
else
V_64 = F_22 ( V_26 , V_27 ) ;
}
return V_64 ;
}
static int F_56 ( void )
{
struct V_8 * V_8 ;
struct V_14 * V_13 ;
struct V_25 * V_26 ;
int V_64 = 0 ;
F_57 ( & V_68 ) ;
V_57 . V_8 = F_58 ( V_69 . V_70 . V_43 ,
struct V_8 , V_70 ) ;
F_59 ( & V_68 ) ;
for ( V_8 = V_57 . V_8 ;
V_8 != & V_69 ; V_8 = V_57 . V_8 ) {
V_13 = V_8 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
for ( V_26 = V_13 -> V_71 ; V_26 ; V_26 = V_26 -> V_72 ) {
if ( F_20 ( V_13 ) )
break;
if ( ! ( V_26 -> V_39 & V_40 ) || ! V_26 -> V_36 )
continue;
V_64 = F_54 ( V_26 ,
V_26 -> V_38 , V_26 -> V_73 ) ;
if ( V_64 )
goto error;
}
F_53 ( V_8 , & V_8 -> V_61 ) ;
F_57 ( & V_68 ) ;
V_57 . V_8 = F_58 ( V_8 -> V_70 . V_43 ,
struct V_8 , V_70 ) ;
if ( F_20 ( V_13 ) ) {
F_50 ( & V_8 -> V_21 ) ;
F_60 ( & V_8 -> V_70 ) ;
F_59 ( & V_68 ) ;
F_13 ( V_8 ) ;
F_61 ( V_74 , & V_13 -> V_75 ) ;
F_33 ( & V_13 -> V_37 ) ;
F_62 ( V_13 ) ;
} else {
F_59 ( & V_68 ) ;
F_33 ( & V_13 -> V_37 ) ;
}
}
V_57 . V_58 = 0 ;
return 0 ;
error:
F_33 ( & V_13 -> V_37 ) ;
F_57 ( & V_68 ) ;
V_57 . V_8 = & V_69 ;
F_59 ( & V_68 ) ;
return V_64 ;
}
static T_2 F_63 ( struct V_28 * V_28 )
{
T_2 V_76 ;
void * V_27 = F_64 ( V_28 , V_77 ) ;
V_76 = F_65 ( V_27 , V_65 / 4 , 17 ) ;
F_66 ( V_27 , V_77 ) ;
return V_76 ;
}
static int F_67 ( struct V_28 * V_78 , struct V_28 * V_79 )
{
char * V_80 , * V_81 ;
int V_29 ;
V_80 = F_64 ( V_78 , V_77 ) ;
V_81 = F_64 ( V_79 , V_82 ) ;
V_29 = memcmp ( V_80 , V_81 , V_65 ) ;
F_66 ( V_81 , V_82 ) ;
F_66 ( V_80 , V_77 ) ;
return V_29 ;
}
static inline int F_68 ( struct V_28 * V_78 , struct V_28 * V_79 )
{
return ! F_67 ( V_78 , V_79 ) ;
}
static int F_69 ( struct V_25 * V_26 , struct V_28 * V_28 ,
T_3 * V_83 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
unsigned long V_27 ;
T_3 * V_84 ;
T_4 * V_85 ;
int V_86 ;
int V_64 = - V_87 ;
V_27 = F_70 ( V_28 , V_26 ) ;
if ( V_27 == - V_87 )
goto V_3;
F_52 ( F_35 ( V_28 ) ) ;
V_84 = F_71 ( V_28 , V_13 , V_27 , & V_85 , 0 ) ;
if ( ! V_84 )
goto V_3;
if ( F_72 ( * V_84 ) || F_73 ( * V_84 ) ) {
T_3 V_88 ;
V_86 = F_74 ( V_28 ) ;
F_75 ( V_26 , V_27 , F_76 ( V_28 ) ) ;
V_88 = F_77 ( V_26 , V_27 , V_84 ) ;
if ( F_78 ( V_28 ) + 1 + V_86 != F_79 ( V_28 ) ) {
F_80 ( V_13 , V_27 , V_84 , V_88 ) ;
goto V_89;
}
if ( F_73 ( V_88 ) )
F_81 ( V_28 ) ;
V_88 = F_82 ( F_83 ( V_88 ) ) ;
F_84 ( V_13 , V_27 , V_84 , V_88 ) ;
}
* V_83 = * V_84 ;
V_64 = 0 ;
V_89:
F_85 ( V_84 , V_85 ) ;
V_3:
return V_64 ;
}
static int F_86 ( struct V_25 * V_26 , struct V_28 * V_28 ,
struct V_28 * V_90 , T_3 V_83 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
T_5 * V_91 ;
T_6 * V_92 ;
T_7 * V_93 ;
T_3 * V_84 ;
T_4 * V_85 ;
unsigned long V_27 ;
int V_64 = - V_87 ;
V_27 = F_70 ( V_28 , V_26 ) ;
if ( V_27 == - V_87 )
goto V_3;
V_91 = F_87 ( V_13 , V_27 ) ;
if ( ! F_88 ( * V_91 ) )
goto V_3;
V_92 = F_89 ( V_91 , V_27 ) ;
if ( ! F_90 ( * V_92 ) )
goto V_3;
V_93 = F_91 ( V_92 , V_27 ) ;
F_52 ( F_92 ( * V_93 ) ) ;
if ( ! F_93 ( * V_93 ) )
goto V_3;
V_84 = F_94 ( V_13 , V_93 , V_27 , & V_85 ) ;
if ( ! F_95 ( * V_84 , V_83 ) ) {
F_85 ( V_84 , V_85 ) ;
goto V_3;
}
F_96 ( V_90 ) ;
F_97 ( V_90 , V_26 , V_27 ) ;
F_75 ( V_26 , V_27 , F_98 ( * V_84 ) ) ;
F_77 ( V_26 , V_27 , V_84 ) ;
F_84 ( V_13 , V_27 , V_84 , F_99 ( V_90 , V_26 -> V_94 ) ) ;
F_100 ( V_28 ) ;
if ( ! F_101 ( V_28 ) )
F_102 ( V_28 ) ;
F_28 ( V_28 ) ;
F_85 ( V_84 , V_85 ) ;
V_64 = 0 ;
V_3:
return V_64 ;
}
static int F_103 ( struct V_28 * V_28 )
{
int V_29 = 0 ;
struct V_28 * V_95 = F_34 ( V_28 ) ;
if ( V_95 ) {
if ( F_46 ( V_95 ) ) {
if ( F_37 ( V_95 ) )
V_29 = F_104 ( V_95 ) ;
else
V_29 = 1 ;
F_28 ( V_95 ) ;
} else
V_29 = 1 ;
}
return V_29 ;
}
static int F_105 ( struct V_25 * V_26 ,
struct V_28 * V_28 , struct V_28 * V_90 )
{
T_3 V_83 = F_106 ( 0 ) ;
int V_64 = - V_87 ;
if ( V_28 == V_90 )
return 0 ;
if ( ! ( V_26 -> V_39 & V_40 ) )
goto V_3;
if ( F_35 ( V_28 ) && F_103 ( V_28 ) )
goto V_3;
F_52 ( F_35 ( V_28 ) ) ;
if ( ! F_37 ( V_28 ) )
goto V_3;
if ( ! F_107 ( V_28 ) )
goto V_3;
if ( F_69 ( V_26 , V_28 , & V_83 ) == 0 ) {
if ( ! V_90 ) {
F_108 ( V_28 , NULL ) ;
F_109 ( V_28 ) ;
V_64 = 0 ;
} else if ( F_68 ( V_28 , V_90 ) )
V_64 = F_86 ( V_26 , V_28 , V_90 , V_83 ) ;
}
if ( ( V_26 -> V_39 & V_96 ) && V_90 && ! V_64 ) {
F_110 ( V_28 ) ;
if ( ! F_111 ( V_90 ) ) {
F_51 ( V_28 ) ;
F_49 ( V_90 ) ;
F_112 ( V_90 ) ;
V_28 = V_90 ;
}
}
F_51 ( V_28 ) ;
V_3:
return V_64 ;
}
static int F_113 ( struct V_2 * V_2 ,
struct V_28 * V_28 , struct V_28 * V_90 )
{
struct V_14 * V_13 = V_2 -> V_13 ;
struct V_25 * V_26 ;
int V_64 = - V_87 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_20 ( V_13 ) )
goto V_3;
V_26 = F_32 ( V_13 , V_2 -> V_22 ) ;
if ( ! V_26 || V_26 -> V_38 > V_2 -> V_22 )
goto V_3;
V_64 = F_105 ( V_26 , V_28 , V_90 ) ;
if ( V_64 )
goto V_3;
V_2 -> V_36 = V_26 -> V_36 ;
F_114 ( V_26 -> V_36 ) ;
V_3:
F_33 ( & V_13 -> V_37 ) ;
return V_64 ;
}
static struct V_28 * F_115 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_2 * V_97 ,
struct V_28 * V_98 )
{
int V_64 ;
V_64 = F_113 ( V_2 , V_28 , NULL ) ;
if ( ! V_64 ) {
V_64 = F_113 ( V_97 ,
V_98 , V_28 ) ;
if ( V_64 )
F_29 ( V_2 ) ;
}
return V_64 ? NULL : V_28 ;
}
static struct V_28 * F_116 ( struct V_28 * V_28 )
{
struct V_99 * V_18 = V_47 . V_99 ;
struct V_5 * V_5 ;
V_5 = F_117 ( V_28 ) ;
if ( V_5 ) {
F_96 ( V_28 ) ;
return V_28 ;
}
while ( V_18 ) {
struct V_28 * V_98 ;
int V_29 ;
F_23 () ;
V_5 = F_118 ( V_18 , struct V_5 , V_18 ) ;
V_98 = F_43 ( V_5 ) ;
if ( ! V_98 )
return NULL ;
V_29 = F_67 ( V_28 , V_98 ) ;
if ( V_29 < 0 ) {
F_28 ( V_98 ) ;
V_18 = V_18 -> V_100 ;
} else if ( V_29 > 0 ) {
F_28 ( V_98 ) ;
V_18 = V_18 -> V_101 ;
} else
return V_98 ;
}
return NULL ;
}
static struct V_5 * F_119 ( struct V_28 * V_90 )
{
struct V_99 * * V_102 = & V_47 . V_99 ;
struct V_99 * V_103 = NULL ;
struct V_5 * V_5 ;
while ( * V_102 ) {
struct V_28 * V_98 ;
int V_29 ;
F_23 () ;
V_5 = F_118 ( * V_102 , struct V_5 , V_18 ) ;
V_98 = F_43 ( V_5 ) ;
if ( ! V_98 )
return NULL ;
V_29 = F_67 ( V_90 , V_98 ) ;
F_28 ( V_98 ) ;
V_103 = * V_102 ;
if ( V_29 < 0 )
V_102 = & V_103 -> V_100 ;
else if ( V_29 > 0 )
V_102 = & V_103 -> V_101 ;
else {
return NULL ;
}
}
V_5 = F_9 () ;
if ( ! V_5 )
return NULL ;
F_120 ( & V_5 -> V_18 , V_103 , V_102 ) ;
F_121 ( & V_5 -> V_18 , & V_47 ) ;
F_122 ( & V_5 -> V_42 ) ;
V_5 -> V_49 = F_76 ( V_90 ) ;
F_108 ( V_90 , V_5 ) ;
return V_5 ;
}
static
struct V_2 * F_123 ( struct V_2 * V_2 ,
struct V_28 * V_28 ,
struct V_28 * * V_104 )
{
struct V_99 * * V_102 = & V_59 . V_99 ;
struct V_99 * V_103 = NULL ;
while ( * V_102 ) {
struct V_2 * V_97 ;
struct V_28 * V_98 ;
int V_29 ;
F_23 () ;
V_97 = F_118 ( * V_102 , struct V_2 , V_18 ) ;
V_98 = F_38 ( V_97 ) ;
if ( F_25 ( V_98 ) )
return NULL ;
if ( V_28 == V_98 ) {
F_28 ( V_98 ) ;
return NULL ;
}
V_29 = F_67 ( V_28 , V_98 ) ;
V_103 = * V_102 ;
if ( V_29 < 0 ) {
F_28 ( V_98 ) ;
V_102 = & V_103 -> V_100 ;
} else if ( V_29 > 0 ) {
F_28 ( V_98 ) ;
V_102 = & V_103 -> V_101 ;
} else {
* V_104 = V_98 ;
return V_97 ;
}
}
V_2 -> V_22 |= V_55 ;
V_2 -> V_22 |= ( V_57 . V_58 & V_105 ) ;
F_120 ( & V_2 -> V_18 , V_103 , V_102 ) ;
F_121 ( & V_2 -> V_18 , & V_59 ) ;
V_60 ++ ;
return NULL ;
}
static void F_124 ( struct V_2 * V_2 ,
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
static void F_125 ( struct V_28 * V_28 , struct V_2 * V_2 )
{
struct V_2 * V_97 ;
struct V_28 * V_98 = NULL ;
struct V_5 * V_5 ;
struct V_28 * V_90 ;
unsigned int V_76 ;
int V_64 ;
F_48 ( V_2 ) ;
V_90 = F_116 ( V_28 ) ;
if ( V_90 ) {
V_64 = F_113 ( V_2 , V_28 , V_90 ) ;
if ( ! V_64 ) {
F_49 ( V_90 ) ;
F_124 ( V_2 , F_117 ( V_90 ) ) ;
F_51 ( V_90 ) ;
}
F_28 ( V_90 ) ;
return;
}
V_76 = F_63 ( V_28 ) ;
if ( V_2 -> V_106 != V_76 ) {
V_2 -> V_106 = V_76 ;
return;
}
V_97 =
F_123 ( V_2 , V_28 , & V_98 ) ;
if ( V_97 ) {
V_90 = F_115 ( V_2 , V_28 ,
V_97 , V_98 ) ;
F_28 ( V_98 ) ;
if ( V_90 ) {
F_48 ( V_97 ) ;
F_49 ( V_90 ) ;
V_5 = F_119 ( V_90 ) ;
if ( V_5 ) {
F_124 ( V_97 , V_5 ) ;
F_124 ( V_2 , V_5 ) ;
}
F_51 ( V_90 ) ;
if ( ! V_5 ) {
F_29 ( V_97 ) ;
F_29 ( V_2 ) ;
}
}
}
}
static struct V_2 * F_126 ( struct V_8 * V_8 ,
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
F_48 ( V_2 ) ;
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
static struct V_2 * F_127 ( struct V_28 * * V_28 )
{
struct V_14 * V_13 ;
struct V_8 * V_107 ;
struct V_25 * V_26 ;
struct V_2 * V_2 ;
if ( F_128 ( & V_69 . V_70 ) )
return NULL ;
V_107 = V_57 . V_8 ;
if ( V_107 == & V_69 ) {
F_129 () ;
V_59 = V_108 ;
F_57 ( & V_68 ) ;
V_107 = F_58 ( V_107 -> V_70 . V_43 , struct V_8 , V_70 ) ;
V_57 . V_8 = V_107 ;
F_59 ( & V_68 ) ;
if ( V_107 == & V_69 )
return NULL ;
V_109:
V_57 . V_22 = 0 ;
V_57 . V_61 = & V_107 -> V_61 ;
}
V_13 = V_107 -> V_13 ;
F_31 ( & V_13 -> V_37 ) ;
if ( F_20 ( V_13 ) )
V_26 = NULL ;
else
V_26 = F_32 ( V_13 , V_57 . V_22 ) ;
for (; V_26 ; V_26 = V_26 -> V_72 ) {
if ( ! ( V_26 -> V_39 & V_40 ) )
continue;
if ( V_57 . V_22 < V_26 -> V_38 )
V_57 . V_22 = V_26 -> V_38 ;
if ( ! V_26 -> V_36 )
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
if ( F_37 ( * V_28 ) ||
F_34 ( * V_28 ) ) {
F_39 ( V_26 , * V_28 , V_57 . V_22 ) ;
F_40 ( * V_28 ) ;
V_2 = F_126 ( V_107 ,
V_57 . V_61 , V_57 . V_22 ) ;
if ( V_2 ) {
V_57 . V_61 =
& V_2 -> V_61 ;
V_57 . V_22 += V_65 ;
} else
F_28 ( * V_28 ) ;
F_33 ( & V_13 -> V_37 ) ;
return V_2 ;
}
F_28 ( * V_28 ) ;
V_57 . V_22 += V_65 ;
F_23 () ;
}
}
if ( F_20 ( V_13 ) ) {
V_57 . V_22 = 0 ;
V_57 . V_61 = & V_107 -> V_61 ;
}
F_53 ( V_107 , V_57 . V_61 ) ;
F_57 ( & V_68 ) ;
V_57 . V_8 = F_58 ( V_107 -> V_70 . V_43 ,
struct V_8 , V_70 ) ;
if ( V_57 . V_22 == 0 ) {
F_50 ( & V_107 -> V_21 ) ;
F_60 ( & V_107 -> V_70 ) ;
F_59 ( & V_68 ) ;
F_13 ( V_107 ) ;
F_61 ( V_74 , & V_13 -> V_75 ) ;
F_33 ( & V_13 -> V_37 ) ;
F_62 ( V_13 ) ;
} else {
F_59 ( & V_68 ) ;
F_33 ( & V_13 -> V_37 ) ;
}
V_107 = V_57 . V_8 ;
if ( V_107 != & V_69 )
goto V_109;
V_57 . V_58 ++ ;
return NULL ;
}
static void F_130 ( unsigned int V_110 )
{
struct V_2 * V_2 ;
struct V_28 * V_111 ( V_28 ) ;
while ( V_110 -- && F_131 ( ! F_132 ( V_66 ) ) ) {
F_23 () ;
V_2 = F_127 ( & V_28 ) ;
if ( ! V_2 )
return;
if ( ! F_26 ( V_28 ) || ! F_19 ( V_2 ) )
F_125 ( V_28 , V_2 ) ;
F_28 ( V_28 ) ;
}
}
static int F_133 ( void )
{
return ( V_112 & V_113 ) && ! F_128 ( & V_69 . V_70 ) ;
}
static int F_134 ( void * V_114 )
{
F_135 () ;
F_136 ( V_66 , 5 ) ;
while ( ! F_137 () ) {
F_138 ( & V_115 ) ;
if ( F_133 () )
F_130 ( V_116 ) ;
F_139 ( & V_115 ) ;
F_140 () ;
if ( F_133 () ) {
F_141 (
F_142 ( V_117 ) ) ;
} else {
F_143 ( V_118 ,
F_133 () || F_137 () ) ;
}
}
return 0 ;
}
int F_144 ( struct V_25 * V_26 , unsigned long V_62 ,
unsigned long V_63 , int V_119 , unsigned long * V_39 )
{
struct V_14 * V_13 = V_26 -> V_31 ;
int V_64 ;
switch ( V_119 ) {
case V_120 :
if ( * V_39 & ( V_40 | V_121 | V_122 |
V_123 | V_124 | V_125 |
V_126 | V_127 | V_128 |
V_129 | V_130 | V_131 ) )
return 0 ;
if ( ! F_145 ( V_74 , & V_13 -> V_75 ) ) {
V_64 = F_146 ( V_13 ) ;
if ( V_64 )
return V_64 ;
}
* V_39 |= V_40 ;
break;
case V_132 :
if ( ! ( * V_39 & V_40 ) )
return 0 ;
if ( V_26 -> V_36 ) {
V_64 = F_54 ( V_26 , V_62 , V_63 ) ;
if ( V_64 )
return V_64 ;
}
* V_39 &= ~ V_40 ;
break;
}
return 0 ;
}
int F_146 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_133 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_10 ;
V_133 = F_128 ( & V_69 . V_70 ) ;
F_57 ( & V_68 ) ;
F_17 ( V_13 , V_8 ) ;
F_147 ( & V_8 -> V_70 , & V_57 . V_8 -> V_70 ) ;
F_59 ( & V_68 ) ;
F_148 ( V_74 , & V_13 -> V_75 ) ;
F_149 ( & V_13 -> V_134 ) ;
if ( V_133 )
F_150 ( & V_118 ) ;
return 0 ;
}
void F_151 ( struct V_14 * V_13 )
{
struct V_8 * V_8 ;
int V_135 = 0 ;
F_57 ( & V_68 ) ;
V_8 = F_14 ( V_13 ) ;
if ( V_8 && V_57 . V_8 != V_8 ) {
if ( ! V_8 -> V_61 ) {
F_50 ( & V_8 -> V_21 ) ;
F_60 ( & V_8 -> V_70 ) ;
V_135 = 1 ;
} else {
F_152 ( & V_8 -> V_70 ,
& V_57 . V_8 -> V_70 ) ;
}
}
F_59 ( & V_68 ) ;
if ( V_135 ) {
F_13 ( V_8 ) ;
F_61 ( V_74 , & V_13 -> V_75 ) ;
F_62 ( V_13 ) ;
} else if ( V_8 ) {
F_153 ( & V_13 -> V_37 ) ;
F_154 ( & V_13 -> V_37 ) ;
}
}
struct V_28 * F_155 ( struct V_28 * V_28 ,
struct V_25 * V_26 , unsigned long V_22 )
{
struct V_28 * V_136 ;
V_136 = F_156 ( V_137 , V_26 , V_22 ) ;
if ( V_136 ) {
F_157 ( V_136 , V_28 , V_22 , V_26 ) ;
F_158 ( V_136 ) ;
F_159 ( V_136 ) ;
F_160 ( V_136 ) ;
F_161 ( V_136 ) ;
if ( F_162 ( V_136 , V_26 ) )
F_163 ( V_136 , V_138 ) ;
else
F_164 ( V_136 ) ;
}
return V_136 ;
}
int F_165 ( struct V_28 * V_28 , struct V_139 * V_140 ,
unsigned long * V_39 )
{
struct V_5 * V_5 ;
struct V_2 * V_2 ;
struct V_17 * V_42 ;
unsigned int V_141 = F_78 ( V_28 ) ;
int V_142 = 0 ;
int V_143 = 0 ;
F_166 ( ! F_26 ( V_28 ) ) ;
F_166 ( ! F_167 ( V_28 ) ) ;
V_5 = F_117 ( V_28 ) ;
if ( ! V_5 )
return 0 ;
V_144:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_36 * V_36 = V_2 -> V_36 ;
struct V_145 * V_146 ;
struct V_25 * V_26 ;
F_168 ( V_36 ) ;
F_169 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_146 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_38 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_143 )
continue;
if ( V_140 && ! F_170 ( V_26 -> V_31 , V_140 ) )
continue;
V_142 += F_171 ( V_28 , V_26 ,
V_2 -> V_22 , & V_141 , V_39 ) ;
if ( ! V_143 || ! V_141 )
break;
}
F_172 ( V_36 ) ;
if ( ! V_141 )
goto V_3;
}
if ( ! V_143 ++ )
goto V_144;
V_3:
return V_142 ;
}
int F_173 ( struct V_28 * V_28 , enum V_147 V_75 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_148 ;
int V_143 = 0 ;
F_166 ( ! F_26 ( V_28 ) ) ;
F_166 ( ! F_167 ( V_28 ) ) ;
V_5 = F_117 ( V_28 ) ;
if ( ! V_5 )
return V_149 ;
V_144:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_36 * V_36 = V_2 -> V_36 ;
struct V_145 * V_146 ;
struct V_25 * V_26 ;
F_168 ( V_36 ) ;
F_169 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_146 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_38 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_143 )
continue;
V_29 = F_174 ( V_28 , V_26 ,
V_2 -> V_22 , V_75 ) ;
if ( V_29 != V_148 || ! F_101 ( V_28 ) ) {
F_172 ( V_36 ) ;
goto V_3;
}
}
F_172 ( V_36 ) ;
}
if ( ! V_143 ++ )
goto V_144;
V_3:
return V_29 ;
}
int F_175 ( struct V_28 * V_28 , int (* F_176)( struct V_28 * ,
struct V_25 * , unsigned long , void * ) , void * V_150 )
{
struct V_5 * V_5 ;
struct V_17 * V_42 ;
struct V_2 * V_2 ;
int V_29 = V_148 ;
int V_143 = 0 ;
F_166 ( ! F_26 ( V_28 ) ) ;
F_166 ( ! F_167 ( V_28 ) ) ;
V_5 = F_117 ( V_28 ) ;
if ( ! V_5 )
return V_29 ;
V_144:
F_16 (rmap_item, hlist, &stable_node->hlist, hlist) {
struct V_36 * V_36 = V_2 -> V_36 ;
struct V_145 * V_146 ;
struct V_25 * V_26 ;
F_168 ( V_36 ) ;
F_169 (vmac, &anon_vma->head, same_anon_vma) {
V_26 = V_146 -> V_26 ;
if ( V_2 -> V_22 < V_26 -> V_38 ||
V_2 -> V_22 >= V_26 -> V_73 )
continue;
if ( ( V_2 -> V_13 == V_26 -> V_31 ) == V_143 )
continue;
V_29 = F_176 ( V_28 , V_26 , V_2 -> V_22 , V_150 ) ;
if ( V_29 != V_148 ) {
F_172 ( V_36 ) ;
goto V_3;
}
}
F_172 ( V_36 ) ;
}
if ( ! V_143 ++ )
goto V_144;
V_3:
return V_29 ;
}
void F_177 ( struct V_28 * V_151 , struct V_28 * V_152 )
{
struct V_5 * V_5 ;
F_166 ( ! F_167 ( V_152 ) ) ;
F_166 ( ! F_167 ( V_151 ) ) ;
F_166 ( V_151 -> V_52 != V_152 -> V_52 ) ;
V_5 = F_117 ( V_151 ) ;
if ( V_5 ) {
F_166 ( V_5 -> V_49 != F_76 ( V_152 ) ) ;
V_5 -> V_49 = F_76 ( V_151 ) ;
}
}
static struct V_5 * F_178 ( unsigned long V_153 ,
unsigned long V_154 )
{
struct V_99 * V_18 ;
for ( V_18 = F_179 ( & V_47 ) ; V_18 ; V_18 = F_180 ( V_18 ) ) {
struct V_5 * V_5 ;
V_5 = F_118 ( V_18 , struct V_5 , V_18 ) ;
if ( V_5 -> V_49 >= V_153 &&
V_5 -> V_49 < V_154 )
return V_5 ;
}
return NULL ;
}
static int F_181 ( struct V_155 * V_156 ,
unsigned long V_157 , void * V_150 )
{
struct V_158 * V_159 = V_150 ;
struct V_5 * V_5 ;
switch ( V_157 ) {
case V_160 :
F_182 ( & V_115 , V_161 ) ;
break;
case V_162 :
while ( ( V_5 = F_178 ( V_159 -> V_153 ,
V_159 -> V_153 + V_159 -> V_163 ) ) != NULL )
F_41 ( V_5 ) ;
case V_164 :
F_139 ( & V_115 ) ;
break;
}
return V_165 ;
}
static T_8 F_183 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_1 , V_117 ) ;
}
static T_8 F_184 ( struct V_166 * V_167 ,
struct V_168 * V_169 ,
const char * V_170 , T_9 V_171 )
{
unsigned long V_172 ;
int V_64 ;
V_64 = F_185 ( V_170 , 10 , & V_172 ) ;
if ( V_64 || V_172 > V_173 )
return - V_174 ;
V_117 = V_172 ;
return V_171 ;
}
static T_8 F_186 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_1 , V_116 ) ;
}
static T_8 F_187 ( struct V_166 * V_167 ,
struct V_168 * V_169 ,
const char * V_170 , T_9 V_171 )
{
int V_64 ;
unsigned long V_163 ;
V_64 = F_185 ( V_170 , 10 , & V_163 ) ;
if ( V_64 || V_163 > V_173 )
return - V_174 ;
V_116 = V_163 ;
return V_171 ;
}
static T_8 F_188 ( struct V_166 * V_167 , struct V_168 * V_169 ,
char * V_170 )
{
return sprintf ( V_170 , L_1 , V_112 ) ;
}
static T_8 F_189 ( struct V_166 * V_167 , struct V_168 * V_169 ,
const char * V_170 , T_9 V_171 )
{
int V_64 ;
unsigned long V_75 ;
V_64 = F_185 ( V_170 , 10 , & V_75 ) ;
if ( V_64 || V_75 > V_173 )
return - V_174 ;
if ( V_75 > V_175 )
return - V_174 ;
F_138 ( & V_115 ) ;
if ( V_112 != V_75 ) {
V_112 = V_75 ;
if ( V_75 & V_175 ) {
int V_176 ;
V_176 = F_190 ( V_177 ) ;
V_64 = F_56 () ;
F_190 ( V_176 ) ;
if ( V_64 ) {
V_112 = V_178 ;
V_171 = V_64 ;
}
}
}
F_139 ( & V_115 ) ;
if ( V_75 & V_113 )
F_150 ( & V_118 ) ;
return V_171 ;
}
static T_8 F_191 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_2 , V_45 ) ;
}
static T_8 F_192 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_2 , V_44 ) ;
}
static T_8 F_193 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_2 , V_60 ) ;
}
static T_8 F_194 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
long V_179 ;
V_179 = V_12 - V_45
- V_44 - V_60 ;
if ( V_179 < 0 )
V_179 = 0 ;
return sprintf ( V_170 , L_3 , V_179 ) ;
}
static T_8 F_195 ( struct V_166 * V_167 ,
struct V_168 * V_169 , char * V_170 )
{
return sprintf ( V_170 , L_2 , V_57 . V_58 ) ;
}
static int T_1 F_196 ( void )
{
struct V_180 * V_181 ;
int V_64 ;
V_64 = F_1 () ;
if ( V_64 )
goto V_3;
V_181 = F_197 ( F_134 , NULL , L_4 ) ;
if ( F_198 ( V_181 ) ) {
F_199 ( V_182 L_5 ) ;
V_64 = F_200 ( V_181 ) ;
goto V_183;
}
#ifdef F_201
V_64 = F_202 ( V_184 , & V_185 ) ;
if ( V_64 ) {
F_199 ( V_182 L_6 ) ;
F_203 ( V_181 ) ;
goto V_183;
}
#else
V_112 = V_113 ;
#endif
#ifdef F_204
F_205 ( F_181 , 100 ) ;
#endif
return 0 ;
V_183:
F_4 () ;
V_3:
return V_64 ;
}
