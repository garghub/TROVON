static unsigned long F_1 ( void )
{
return V_1 / 2 ;
}
static unsigned long F_2 ( void )
{
return F_3 ( V_1 - V_2 , V_1 / 2 ) ;
}
int F_4 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 )
{
return F_5 ( V_3 , V_4 , V_6 , V_8 ,
F_6 ( V_3 -> V_9 ) , NULL , NULL ) ;
}
static inline struct V_10 * F_7 ( struct V_11 * V_12 )
{
return V_12 -> V_13 ;
}
static inline int F_8 ( unsigned long V_14 , T_2 V_15 )
{
return ( V_14 & V_16 ) ?
0 : F_9 ( V_17 -> V_18 , F_10 ( V_15 ) ) ;
}
static inline void F_11 ( unsigned long V_14 , T_2 V_15 )
{
if ( ! ( V_14 & V_16 ) )
F_12 ( F_10 ( V_15 ) ) ;
}
static inline int F_13 ( unsigned long V_14 ,
T_2 V_19 , T_2 V_20 )
{
if ( ! ( V_14 & V_16 ) ) {
if ( F_10 ( V_20 ) > F_10 ( V_19 ) )
return F_9 ( V_17 -> V_18 ,
F_10 ( V_20 ) - F_10 ( V_19 ) ) ;
else if ( F_10 ( V_20 ) < F_10 ( V_19 ) )
F_12 ( F_10 ( V_19 ) - F_10 ( V_20 ) ) ;
}
return 0 ;
}
static inline int F_14 ( unsigned long V_14 , long V_21 )
{
if ( ! ( V_14 & V_16 ) )
return 0 ;
return F_9 ( V_17 -> V_18 ,
V_21 * F_10 ( V_22 ) ) ;
}
static inline void F_15 ( unsigned long V_14 , long V_21 )
{
if ( V_14 & V_16 )
F_12 ( V_21 * F_10 ( V_22 ) ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( V_23 -> V_24 ) {
F_17 ( & V_23 -> V_25 ) ;
if ( ! V_23 -> V_26 ) {
F_18 ( & V_23 -> V_25 ) ;
return - V_27 ;
}
V_23 -> V_26 -- ;
F_18 ( & V_23 -> V_25 ) ;
}
return 0 ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( V_23 -> V_24 ) {
F_17 ( & V_23 -> V_25 ) ;
V_23 -> V_26 ++ ;
F_18 ( & V_23 -> V_25 ) ;
}
}
static void F_20 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
long V_30 ;
V_30 = V_29 -> V_31 - V_29 -> V_32 - V_3 -> V_9 -> V_33 ;
if ( V_30 > 0 ) {
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - V_30 ) ;
V_29 -> V_31 -= V_30 ;
V_3 -> V_37 -= V_30 * V_38 ;
F_15 ( V_29 -> V_14 , V_30 ) ;
}
}
bool F_23 ( struct V_3 * V_3 , long V_21 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
unsigned long V_14 ;
if ( F_14 ( V_29 -> V_14 , V_21 ) )
return false ;
F_24 ( & V_29 -> V_39 , V_14 ) ;
V_29 -> V_31 += V_21 ;
V_3 -> V_37 += V_21 * V_38 ;
F_20 ( V_3 ) ;
F_25 ( & V_29 -> V_39 , V_14 ) ;
V_3 -> V_9 -> V_33 += V_21 ;
if ( ! V_23 -> V_35 )
return true ;
if ( F_26 ( & V_23 -> V_36 ,
V_23 -> V_35 - V_21 ) > 0 ) {
V_3 -> V_9 -> V_33 -= V_21 ;
F_24 ( & V_29 -> V_39 , V_14 ) ;
V_29 -> V_31 -= V_21 ;
F_20 ( V_3 ) ;
F_25 ( & V_29 -> V_39 , V_14 ) ;
F_15 ( V_29 -> V_14 , V_21 ) ;
return false ;
}
F_22 ( & V_23 -> V_36 , V_21 ) ;
return true ;
}
void F_27 ( struct V_3 * V_3 , long V_21 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
unsigned long V_14 ;
F_24 ( & V_29 -> V_39 , V_14 ) ;
V_29 -> V_31 -= V_21 ;
V_3 -> V_37 -= V_21 * V_38 ;
F_20 ( V_3 ) ;
F_25 ( & V_29 -> V_39 , V_14 ) ;
if ( V_23 -> V_35 )
F_28 ( & V_23 -> V_36 , V_21 ) ;
F_15 ( V_29 -> V_14 , V_21 ) ;
}
static int F_29 ( struct V_40 * V_41 ,
T_1 V_4 , void * V_42 , void * V_43 )
{
struct V_44 * V_45 ;
void * * V_46 ;
void * V_47 ;
F_30 ( ! V_42 ) ;
F_30 ( ! V_43 ) ;
V_47 = F_31 ( & V_41 -> V_48 , V_4 , & V_45 , & V_46 ) ;
if ( ! V_47 )
return - V_49 ;
if ( V_47 != V_42 )
return - V_49 ;
F_32 ( & V_41 -> V_48 , V_45 , V_46 ,
V_43 , NULL , NULL ) ;
return 0 ;
}
static bool F_33 ( struct V_40 * V_41 ,
T_1 V_4 , T_3 V_50 )
{
void * V_47 ;
F_34 () ;
V_47 = F_35 ( & V_41 -> V_48 , V_4 ) ;
F_36 () ;
return V_47 == F_37 ( V_50 ) ;
}
static int F_38 ( const char * V_51 )
{
if ( ! strcmp ( V_51 , L_1 ) )
return V_52 ;
if ( ! strcmp ( V_51 , L_2 ) )
return V_53 ;
if ( ! strcmp ( V_51 , L_3 ) )
return V_54 ;
if ( ! strcmp ( V_51 , L_4 ) )
return V_55 ;
if ( ! strcmp ( V_51 , L_5 ) )
return V_56 ;
if ( ! strcmp ( V_51 , L_6 ) )
return V_57 ;
return - V_58 ;
}
static const char * F_39 ( int V_59 )
{
switch ( V_59 ) {
case V_52 :
return L_1 ;
case V_53 :
return L_2 ;
case V_54 :
return L_3 ;
case V_55 :
return L_4 ;
case V_56 :
return L_5 ;
case V_57 :
return L_6 ;
default:
F_30 ( 1 ) ;
return L_7 ;
}
}
static unsigned long F_40 ( struct V_10 * V_23 ,
struct V_60 * V_61 , unsigned long V_62 )
{
F_41 ( V_63 ) , * V_64 , * V_65 ;
F_41 ( V_66 ) ;
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_5 * V_5 ;
unsigned long V_67 = V_61 ? V_61 -> V_68 : 128 ;
int V_69 = 0 , V_70 = 0 ;
if ( F_42 ( & V_23 -> V_71 ) )
return V_72 ;
F_17 ( & V_23 -> V_73 ) ;
F_43 (pos, next, &sbinfo->shrinklist) {
V_29 = F_44 ( V_64 , struct V_28 , V_71 ) ;
V_3 = F_45 ( & V_29 -> V_74 ) ;
if ( ! V_3 ) {
F_46 ( & V_29 -> V_71 ) ;
V_69 ++ ;
goto V_65;
}
if ( F_47 ( V_3 -> V_75 , V_22 ) ==
F_47 ( V_3 -> V_75 , V_76 ) ) {
F_48 ( & V_29 -> V_71 , & V_66 ) ;
V_69 ++ ;
goto V_65;
}
F_48 ( & V_29 -> V_71 , & V_63 ) ;
V_65:
if ( ! -- V_67 )
break;
}
F_18 ( & V_23 -> V_73 ) ;
F_43 (pos, next, &to_remove) {
V_29 = F_44 ( V_64 , struct V_28 , V_71 ) ;
V_3 = & V_29 -> V_74 ;
F_46 ( & V_29 -> V_71 ) ;
F_49 ( V_3 ) ;
}
F_43 (pos, next, &list) {
int V_77 ;
V_29 = F_44 ( V_64 , struct V_28 , V_71 ) ;
V_3 = & V_29 -> V_74 ;
if ( V_62 && V_70 >= V_62 ) {
F_49 ( V_3 ) ;
continue;
}
V_5 = F_50 ( V_3 -> V_9 ,
( V_3 -> V_75 & V_78 ) >> V_79 ) ;
if ( ! V_5 )
goto V_80;
if ( ! F_51 ( V_5 ) ) {
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
goto V_80;
}
V_77 = F_54 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
if ( V_77 ) {
F_49 ( V_3 ) ;
continue;
}
V_70 ++ ;
V_80:
F_46 ( & V_29 -> V_71 ) ;
V_69 ++ ;
F_49 ( V_3 ) ;
}
F_17 ( & V_23 -> V_73 ) ;
F_55 ( & V_63 , & V_23 -> V_71 ) ;
V_23 -> V_81 -= V_69 ;
F_18 ( & V_23 -> V_73 ) ;
return V_70 ;
}
static long F_56 ( struct V_11 * V_12 ,
struct V_60 * V_61 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( ! F_57 ( V_23 -> V_81 ) )
return V_72 ;
return F_40 ( V_23 , V_61 , 0 ) ;
}
static long F_58 ( struct V_11 * V_12 ,
struct V_60 * V_61 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
return F_57 ( V_23 -> V_81 ) ;
}
static unsigned long F_40 ( struct V_10 * V_23 ,
struct V_60 * V_61 , unsigned long V_62 )
{
return 0 ;
}
static int F_59 ( struct V_5 * V_5 ,
struct V_40 * V_41 ,
T_1 V_4 , void * V_42 )
{
int error , V_82 = F_60 ( V_5 ) ;
F_61 ( F_62 ( V_5 ) , V_5 ) ;
F_61 ( V_4 != F_63 ( V_4 , V_82 ) , V_5 ) ;
F_61 ( ! F_64 ( V_5 ) , V_5 ) ;
F_61 ( ! F_65 ( V_5 ) , V_5 ) ;
F_30 ( V_42 && F_51 ( V_5 ) ) ;
F_66 ( V_5 , V_82 ) ;
V_5 -> V_41 = V_41 ;
V_5 -> V_4 = V_4 ;
F_67 ( & V_41 -> V_83 ) ;
if ( F_51 ( V_5 ) ) {
void T_4 * * V_84 ;
T_1 V_85 ;
int V_86 ;
error = 0 ;
if ( F_68 ( & V_41 -> V_48 ,
& V_84 , & V_85 , V_4 , 1 ) &&
V_85 < V_4 + V_87 ) {
error = - V_88 ;
}
if ( ! error ) {
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
error = F_69 ( & V_41 -> V_48 ,
V_4 + V_86 , V_5 + V_86 ) ;
F_30 ( error ) ;
}
F_70 ( V_89 ) ;
}
} else if ( ! V_42 ) {
error = F_69 ( & V_41 -> V_48 , V_4 , V_5 ) ;
} else {
error = F_29 ( V_41 , V_4 , V_42 ,
V_5 ) ;
}
if ( ! error ) {
V_41 -> V_33 += V_82 ;
if ( F_51 ( V_5 ) )
F_71 ( V_5 , V_90 ) ;
F_72 ( F_73 ( V_5 ) , V_91 , V_82 ) ;
F_72 ( F_73 ( V_5 ) , V_92 , V_82 ) ;
F_74 ( & V_41 -> V_83 ) ;
} else {
V_5 -> V_41 = NULL ;
F_74 ( & V_41 -> V_83 ) ;
F_75 ( V_5 , V_82 ) ;
}
return error ;
}
static void F_76 ( struct V_5 * V_5 , void * V_93 )
{
struct V_40 * V_41 = V_5 -> V_41 ;
int error ;
F_61 ( F_77 ( V_5 ) , V_5 ) ;
F_67 ( & V_41 -> V_83 ) ;
error = F_29 ( V_41 , V_5 -> V_4 , V_5 , V_93 ) ;
V_5 -> V_41 = NULL ;
V_41 -> V_33 -- ;
F_78 ( V_5 , V_91 ) ;
F_78 ( V_5 , V_92 ) ;
F_74 ( & V_41 -> V_83 ) ;
F_53 ( V_5 ) ;
F_79 ( error ) ;
}
static int F_80 ( struct V_40 * V_41 ,
T_1 V_4 , void * V_93 )
{
void * V_94 ;
F_67 ( & V_41 -> V_83 ) ;
V_94 = F_81 ( & V_41 -> V_48 , V_4 , V_93 ) ;
F_74 ( & V_41 -> V_83 ) ;
if ( V_94 != V_93 )
return - V_49 ;
F_82 ( F_83 ( V_93 ) ) ;
return 0 ;
}
unsigned long F_84 ( struct V_40 * V_41 ,
T_1 V_95 , T_1 V_96 )
{
struct V_97 V_98 ;
void * * V_99 ;
struct V_5 * V_5 ;
unsigned long V_32 = 0 ;
F_34 () ;
F_85 (slot, &mapping->page_tree, &iter, start) {
if ( V_98 . V_4 >= V_96 )
break;
V_5 = F_86 ( V_99 ) ;
if ( F_87 ( V_5 ) ) {
V_99 = F_88 ( & V_98 ) ;
continue;
}
if ( F_89 ( V_5 ) )
V_32 ++ ;
if ( F_90 () ) {
V_99 = F_91 ( V_99 , & V_98 ) ;
F_92 () ;
}
}
F_36 () ;
return V_32 << V_79 ;
}
unsigned long F_93 ( struct V_100 * V_101 )
{
struct V_3 * V_3 = F_94 ( V_101 -> V_102 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_40 * V_41 = V_3 -> V_9 ;
unsigned long V_32 ;
V_32 = F_57 ( V_29 -> V_32 ) ;
if ( ! V_32 )
return 0 ;
if ( ! V_101 -> V_103 && V_101 -> V_104 - V_101 -> V_105 >= V_3 -> V_75 )
return V_32 << V_79 ;
return F_84 ( V_41 ,
F_95 ( V_101 , V_101 -> V_105 ) ,
F_95 ( V_101 , V_101 -> V_104 ) ) ;
}
void F_96 ( struct V_40 * V_41 )
{
struct V_106 V_107 ;
T_1 V_108 [ V_109 ] ;
T_1 V_4 = 0 ;
F_97 ( & V_107 , 0 ) ;
while ( ! F_98 ( V_41 ) ) {
V_107 . V_82 = F_99 ( V_41 , V_4 ,
V_109 , V_107 . V_21 , V_108 ) ;
if ( ! V_107 . V_82 )
break;
V_4 = V_108 [ V_107 . V_82 - 1 ] + 1 ;
F_100 ( & V_107 ) ;
F_101 ( V_107 . V_21 , V_107 . V_82 ) ;
F_102 ( & V_107 ) ;
F_103 () ;
}
}
static void F_104 ( struct V_3 * V_3 , T_2 V_110 , T_2 V_111 ,
bool V_112 )
{
struct V_40 * V_41 = V_3 -> V_9 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_95 = ( V_110 + V_22 - 1 ) >> V_79 ;
T_1 V_96 = ( V_111 + 1 ) >> V_79 ;
unsigned int V_113 = V_110 & ( V_22 - 1 ) ;
unsigned int V_114 = ( V_111 + 1 ) & ( V_22 - 1 ) ;
struct V_106 V_107 ;
T_1 V_108 [ V_109 ] ;
long V_115 = 0 ;
T_1 V_4 ;
int V_86 ;
if ( V_111 == - 1 )
V_96 = - 1 ;
F_97 ( & V_107 , 0 ) ;
V_4 = V_95 ;
while ( V_4 < V_96 ) {
V_107 . V_82 = F_99 ( V_41 , V_4 ,
F_3 ( V_96 - V_4 , ( T_1 ) V_109 ) ,
V_107 . V_21 , V_108 ) ;
if ( ! V_107 . V_82 )
break;
for ( V_86 = 0 ; V_86 < F_105 ( & V_107 ) ; V_86 ++ ) {
struct V_5 * V_5 = V_107 . V_21 [ V_86 ] ;
V_4 = V_108 [ V_86 ] ;
if ( V_4 >= V_96 )
break;
if ( F_89 ( V_5 ) ) {
if ( V_112 )
continue;
V_115 += ! F_80 ( V_41 ,
V_4 , V_5 ) ;
continue;
}
F_61 ( F_106 ( V_5 ) != V_4 , V_5 ) ;
if ( ! F_107 ( V_5 ) )
continue;
if ( F_108 ( V_5 ) ) {
F_109 ( V_5 ) ;
F_52 ( V_5 ) ;
continue;
} else if ( F_51 ( V_5 ) ) {
if ( V_4 == F_63 ( V_96 , V_87 ) ) {
F_109 ( V_5 ) ;
F_52 ( V_5 ) ;
continue;
}
V_4 += V_87 - 1 ;
V_86 += V_87 - 1 ;
}
if ( ! V_112 || ! F_110 ( V_5 ) ) {
F_61 ( F_62 ( V_5 ) , V_5 ) ;
if ( F_111 ( V_5 ) == V_41 ) {
F_61 ( F_112 ( V_5 ) , V_5 ) ;
F_113 ( V_41 , V_5 ) ;
}
}
F_52 ( V_5 ) ;
}
F_100 ( & V_107 ) ;
F_102 ( & V_107 ) ;
F_103 () ;
V_4 ++ ;
}
if ( V_113 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_95 - 1 , & V_5 , V_116 ) ;
if ( V_5 ) {
unsigned int V_117 = V_22 ;
if ( V_95 > V_96 ) {
V_117 = V_114 ;
V_114 = 0 ;
}
F_114 ( V_5 , V_113 , V_117 ) ;
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
}
}
if ( V_114 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_96 , & V_5 , V_116 ) ;
if ( V_5 ) {
F_114 ( V_5 , 0 , V_114 ) ;
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
}
}
if ( V_95 >= V_96 )
return;
V_4 = V_95 ;
while ( V_4 < V_96 ) {
F_103 () ;
V_107 . V_82 = F_99 ( V_41 , V_4 ,
F_3 ( V_96 - V_4 , ( T_1 ) V_109 ) ,
V_107 . V_21 , V_108 ) ;
if ( ! V_107 . V_82 ) {
if ( V_4 == V_95 || V_96 != - 1 )
break;
V_4 = V_95 ;
continue;
}
for ( V_86 = 0 ; V_86 < F_105 ( & V_107 ) ; V_86 ++ ) {
struct V_5 * V_5 = V_107 . V_21 [ V_86 ] ;
V_4 = V_108 [ V_86 ] ;
if ( V_4 >= V_96 )
break;
if ( F_89 ( V_5 ) ) {
if ( V_112 )
continue;
if ( F_80 ( V_41 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_115 ++ ;
continue;
}
F_116 ( V_5 ) ;
if ( F_108 ( V_5 ) ) {
F_109 ( V_5 ) ;
F_52 ( V_5 ) ;
if ( V_4 != F_63 ( V_96 , V_87 ) )
V_95 ++ ;
continue;
} else if ( F_51 ( V_5 ) ) {
if ( V_4 == F_63 ( V_96 , V_87 ) ) {
F_109 ( V_5 ) ;
F_52 ( V_5 ) ;
continue;
}
V_4 += V_87 - 1 ;
V_86 += V_87 - 1 ;
}
if ( ! V_112 || ! F_110 ( V_5 ) ) {
F_61 ( F_62 ( V_5 ) , V_5 ) ;
if ( F_111 ( V_5 ) == V_41 ) {
F_61 ( F_112 ( V_5 ) , V_5 ) ;
F_113 ( V_41 , V_5 ) ;
} else {
F_52 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_52 ( V_5 ) ;
}
F_100 ( & V_107 ) ;
F_102 ( & V_107 ) ;
V_4 ++ ;
}
F_67 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -= V_115 ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
}
void F_117 ( struct V_3 * V_3 , T_2 V_110 , T_2 V_111 )
{
F_104 ( V_3 , V_110 , V_111 , false ) ;
V_3 -> V_118 = V_3 -> V_119 = F_118 ( V_3 ) ;
}
static int F_119 ( struct V_120 * V_121 , struct V_122 * V_122 ,
struct V_123 * V_124 )
{
struct V_3 * V_3 = V_122 -> V_125 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 != V_3 -> V_9 -> V_33 ) {
F_67 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
}
F_120 ( V_3 , V_124 ) ;
return 0 ;
}
static int F_121 ( struct V_122 * V_122 , struct V_126 * V_127 )
{
struct V_3 * V_3 = V_125 ( V_122 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
int error ;
error = F_122 ( V_122 , V_127 ) ;
if ( error )
return error ;
if ( F_123 ( V_3 -> V_128 ) && ( V_127 -> V_129 & V_130 ) ) {
T_2 V_19 = V_3 -> V_75 ;
T_2 V_20 = V_127 -> V_131 ;
if ( ( V_20 < V_19 && ( V_29 -> V_132 & V_133 ) ) ||
( V_20 > V_19 && ( V_29 -> V_132 & V_134 ) ) )
return - V_135 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_21 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_124 ( V_3 , V_20 ) ;
V_3 -> V_118 = V_3 -> V_119 = F_118 ( V_3 ) ;
}
if ( V_20 <= V_19 ) {
T_2 V_136 = F_47 ( V_20 , V_22 ) ;
if ( V_19 > V_136 )
F_125 ( V_3 -> V_9 ,
V_136 , 0 , 1 ) ;
if ( V_29 -> V_31 )
F_117 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_136 )
F_125 ( V_3 -> V_9 ,
V_136 , 0 , 1 ) ;
if ( F_126 ( V_137 ) ) {
F_17 ( & V_23 -> V_73 ) ;
if ( F_42 ( & V_29 -> V_71 ) ) {
F_127 ( & V_29 -> V_71 ,
& V_23 -> V_71 ) ;
V_23 -> V_81 ++ ;
}
F_18 ( & V_23 -> V_73 ) ;
}
}
}
F_128 ( V_3 , V_127 ) ;
if ( V_127 -> V_129 & V_138 )
error = F_129 ( V_3 , V_3 -> V_128 ) ;
return error ;
}
static void F_130 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
if ( V_3 -> V_9 -> V_139 == & V_140 ) {
F_11 ( V_29 -> V_14 , V_3 -> V_75 ) ;
V_3 -> V_75 = 0 ;
F_117 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_42 ( & V_29 -> V_71 ) ) {
F_17 ( & V_23 -> V_73 ) ;
if ( ! F_42 ( & V_29 -> V_71 ) ) {
F_46 ( & V_29 -> V_71 ) ;
V_23 -> V_81 -- ;
}
F_18 ( & V_23 -> V_73 ) ;
}
if ( ! F_42 ( & V_29 -> V_141 ) ) {
F_131 ( & V_142 ) ;
F_46 ( & V_29 -> V_141 ) ;
F_132 ( & V_142 ) ;
}
}
F_133 ( & V_29 -> V_143 ) ;
F_134 ( V_3 -> V_37 ) ;
F_19 ( V_3 -> V_34 ) ;
F_135 ( V_3 ) ;
}
static unsigned long F_136 ( struct V_144 * V_145 , void * V_47 )
{
struct V_97 V_98 ;
void * * V_99 ;
unsigned long V_146 = - 1 ;
unsigned int V_147 = 0 ;
F_34 () ;
F_85 (slot, root, &iter, 0 ) {
if ( * V_99 == V_47 ) {
V_146 = V_98 . V_4 ;
break;
}
V_147 ++ ;
if ( ( V_147 % 4096 ) != 0 )
continue;
V_99 = F_91 ( V_99 , & V_98 ) ;
F_92 () ;
}
F_36 () ;
return V_146 ;
}
static int F_137 ( struct V_28 * V_29 ,
T_3 V_50 , struct V_5 * * V_6 )
{
struct V_40 * V_41 = V_29 -> V_74 . V_9 ;
void * V_93 ;
T_1 V_4 ;
T_5 V_148 ;
int error = 0 ;
V_93 = F_37 ( V_50 ) ;
V_4 = F_136 ( & V_41 -> V_48 , V_93 ) ;
if ( V_4 == - 1 )
return - V_149 ;
if ( V_150 . V_65 != & V_29 -> V_141 )
F_138 ( & V_150 , & V_29 -> V_141 ) ;
V_148 = F_6 ( V_41 ) ;
if ( F_139 ( * V_6 , V_148 ) ) {
F_132 ( & V_142 ) ;
error = F_140 ( V_6 , V_148 , V_29 , V_4 ) ;
F_131 ( & V_142 ) ;
if ( ! F_141 ( * V_6 ) )
error = - V_49 ;
}
if ( ! error )
error = F_59 ( * V_6 , V_41 , V_4 ,
V_93 ) ;
if ( error != - V_151 ) {
F_142 ( * V_6 ) ;
F_115 ( * V_6 ) ;
if ( ! error ) {
F_67 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_74 ( & V_29 -> V_39 ) ;
F_143 ( V_50 ) ;
}
}
return error ;
}
int F_144 ( T_3 V_50 , struct V_5 * V_5 )
{
struct V_152 * V_153 , * V_65 ;
struct V_28 * V_29 ;
struct V_154 * V_155 ;
int error = 0 ;
if ( F_145 ( ! F_146 ( V_5 ) || F_147 ( V_5 ) != V_50 . V_156 ) )
goto V_157;
error = F_148 ( V_5 , V_17 -> V_18 , V_158 , & V_155 ,
false ) ;
if ( error )
goto V_157;
error = - V_149 ;
F_131 ( & V_142 ) ;
F_43 (this, next, &shmem_swaplist) {
V_29 = F_44 ( V_153 , struct V_28 , V_141 ) ;
if ( V_29 -> V_32 )
error = F_137 ( V_29 , V_50 , & V_5 ) ;
else
F_46 ( & V_29 -> V_141 ) ;
F_103 () ;
if ( error != - V_149 )
break;
}
F_132 ( & V_142 ) ;
if ( error ) {
if ( error != - V_151 )
error = 0 ;
F_149 ( V_5 , V_155 , false ) ;
} else
F_150 ( V_5 , V_155 , true , false ) ;
V_157:
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
return error ;
}
static int F_151 ( struct V_5 * V_5 , struct V_159 * V_160 )
{
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_3 * V_3 ;
T_3 V_50 ;
T_1 V_4 ;
F_61 ( F_77 ( V_5 ) , V_5 ) ;
F_79 ( ! F_64 ( V_5 ) ) ;
V_41 = V_5 -> V_41 ;
V_4 = V_5 -> V_4 ;
V_3 = V_41 -> V_161 ;
V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_14 & V_162 )
goto V_163;
if ( ! V_164 )
goto V_163;
if ( ! V_160 -> V_165 ) {
F_152 ( 1 ) ;
goto V_163;
}
if ( ! F_110 ( V_5 ) ) {
if ( V_3 -> V_166 ) {
struct V_167 * V_167 ;
F_17 ( & V_3 -> V_168 ) ;
V_167 = V_3 -> V_166 ;
if ( V_167 &&
! V_167 -> V_169 &&
V_4 >= V_167 -> V_95 &&
V_4 < V_167 -> V_65 )
V_167 -> V_170 ++ ;
else
V_167 = NULL ;
F_18 ( & V_3 -> V_168 ) ;
if ( V_167 )
goto V_163;
}
F_109 ( V_5 ) ;
F_153 ( V_5 ) ;
F_154 ( V_5 ) ;
}
V_50 = F_155 () ;
if ( ! V_50 . V_156 )
goto V_163;
if ( F_156 ( V_5 , V_50 ) )
goto V_171;
F_131 ( & V_142 ) ;
if ( F_42 ( & V_29 -> V_141 ) )
F_127 ( & V_29 -> V_141 , & V_150 ) ;
if ( F_157 ( V_5 , V_50 , V_172 ) == 0 ) {
F_67 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
V_29 -> V_32 ++ ;
F_74 ( & V_29 -> V_39 ) ;
F_158 ( V_50 ) ;
F_76 ( V_5 , F_37 ( V_50 ) ) ;
F_132 ( & V_142 ) ;
F_79 ( F_159 ( V_5 ) ) ;
F_160 ( V_5 , V_160 ) ;
return 0 ;
}
F_132 ( & V_142 ) ;
V_171:
F_161 ( V_50 ) ;
V_163:
F_115 ( V_5 ) ;
if ( V_160 -> V_165 )
return V_173 ;
F_52 ( V_5 ) ;
return 0 ;
}
static void F_162 ( struct V_174 * V_175 , struct V_176 * V_177 )
{
char V_178 [ 64 ] ;
if ( ! V_177 || V_177 -> V_179 == V_180 )
return;
F_163 ( V_178 , sizeof( V_178 ) , V_177 ) ;
F_164 ( V_175 , L_8 , V_178 ) ;
}
static struct V_176 * F_165 ( struct V_10 * V_23 )
{
struct V_176 * V_177 = NULL ;
if ( V_23 -> V_177 ) {
F_17 ( & V_23 -> V_25 ) ;
V_177 = V_23 -> V_177 ;
F_166 ( V_177 ) ;
F_18 ( & V_23 -> V_25 ) ;
}
return V_177 ;
}
static inline void F_162 ( struct V_174 * V_175 , struct V_176 * V_177 )
{
}
static inline struct V_176 * F_165 ( struct V_10 * V_23 )
{
return NULL ;
}
static void F_167 ( struct V_100 * V_101 ,
struct V_28 * V_29 , T_1 V_4 )
{
V_101 -> V_105 = 0 ;
V_101 -> V_103 = V_4 + V_29 -> V_74 . V_181 ;
V_101 -> V_182 = NULL ;
V_101 -> V_183 = F_168 ( & V_29 -> V_184 , V_4 ) ;
}
static void F_169 ( struct V_100 * V_101 )
{
F_170 ( V_101 -> V_183 ) ;
}
static struct V_5 * F_171 ( T_3 V_50 , T_5 V_148 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_100 V_185 ;
struct V_5 * V_5 ;
F_167 ( & V_185 , V_29 , V_4 ) ;
V_5 = F_172 ( V_50 , V_148 , & V_185 , 0 ) ;
F_169 ( & V_185 ) ;
return V_5 ;
}
static struct V_5 * F_173 ( T_5 V_148 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_100 V_185 ;
struct V_3 * V_3 = & V_29 -> V_74 ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_85 , V_186 ;
void T_4 * * V_84 ;
struct V_5 * V_5 ;
if ( ! F_126 ( V_137 ) )
return NULL ;
V_186 = F_63 ( V_4 , V_87 ) ;
F_34 () ;
if ( F_68 ( & V_41 -> V_48 , & V_84 , & V_85 ,
V_186 , 1 ) && V_85 < V_186 + V_87 ) {
F_36 () ;
return NULL ;
}
F_36 () ;
F_167 ( & V_185 , V_29 , V_186 ) ;
V_5 = F_174 ( V_148 | V_187 | V_188 | V_189 ,
V_190 , & V_185 , 0 , F_175 () , true ) ;
F_169 ( & V_185 ) ;
if ( V_5 )
F_176 ( V_5 ) ;
return V_5 ;
}
static struct V_5 * F_177 ( T_5 V_148 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_100 V_185 ;
struct V_5 * V_5 ;
F_167 ( & V_185 , V_29 , V_4 ) ;
V_5 = F_178 ( V_148 , & V_185 , 0 ) ;
F_169 ( & V_185 ) ;
return V_5 ;
}
static struct V_5 * F_179 ( T_5 V_148 ,
struct V_28 * V_29 , struct V_10 * V_23 ,
T_1 V_4 , bool V_59 )
{
struct V_5 * V_5 ;
int V_82 ;
int V_191 = - V_27 ;
if ( ! F_126 ( V_137 ) )
V_59 = false ;
V_82 = V_59 ? V_87 : 1 ;
if ( F_14 ( V_29 -> V_14 , V_82 ) )
goto V_192;
if ( V_23 -> V_35 ) {
if ( F_26 ( & V_23 -> V_36 ,
V_23 -> V_35 - V_82 ) > 0 )
goto V_193;
F_22 ( & V_23 -> V_36 , V_82 ) ;
}
if ( V_59 )
V_5 = F_173 ( V_148 , V_29 , V_4 ) ;
else
V_5 = F_177 ( V_148 , V_29 , V_4 ) ;
if ( V_5 ) {
F_180 ( V_5 ) ;
F_181 ( V_5 ) ;
return V_5 ;
}
V_191 = - V_151 ;
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - V_82 ) ;
V_193:
F_15 ( V_29 -> V_14 , V_82 ) ;
V_192:
return F_182 ( V_191 ) ;
}
static bool F_139 ( struct V_5 * V_5 , T_5 V_148 )
{
return F_183 ( V_5 ) > F_184 ( V_148 ) ;
}
static int F_140 ( struct V_5 * * V_6 , T_5 V_148 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_5 * V_194 , * V_195 ;
struct V_40 * V_196 ;
T_1 V_197 ;
int error ;
V_194 = * V_6 ;
V_197 = F_147 ( V_194 ) ;
V_196 = F_111 ( V_194 ) ;
V_148 &= ~ V_198 ;
V_195 = F_177 ( V_148 , V_29 , V_4 ) ;
if ( ! V_195 )
return - V_151 ;
F_185 ( V_195 ) ;
F_186 ( V_195 , V_194 ) ;
F_153 ( V_195 ) ;
F_180 ( V_195 ) ;
F_181 ( V_195 ) ;
F_154 ( V_195 ) ;
F_187 ( V_195 , V_197 ) ;
F_188 ( V_195 ) ;
F_67 ( & V_196 -> V_83 ) ;
error = F_29 ( V_196 , V_197 , V_194 ,
V_195 ) ;
if ( ! error ) {
F_71 ( V_195 , V_91 ) ;
F_78 ( V_194 , V_91 ) ;
}
F_74 ( & V_196 -> V_83 ) ;
if ( F_145 ( error ) ) {
V_194 = V_195 ;
} else {
F_189 ( V_194 , V_195 ) ;
F_190 ( V_195 ) ;
* V_6 = V_195 ;
}
F_191 ( V_194 ) ;
F_187 ( V_194 , 0 ) ;
F_52 ( V_194 ) ;
F_53 ( V_194 ) ;
F_53 ( V_194 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_5 V_148 ,
struct V_199 * V_200 , int * V_201 )
{
struct V_40 * V_41 = V_3 -> V_9 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 ;
struct V_199 * V_202 ;
struct V_154 * V_155 ;
struct V_5 * V_5 ;
T_3 V_50 ;
enum V_7 V_203 = V_8 ;
T_1 V_186 = V_4 ;
int error ;
int V_204 = 0 ;
int V_31 = 0 ;
if ( V_4 > ( V_205 >> V_79 ) )
return - V_206 ;
if ( V_8 == V_207 || V_8 == V_208 )
V_8 = V_209 ;
V_210:
V_50 . V_156 = 0 ;
V_5 = F_192 ( V_41 , V_4 ) ;
if ( F_89 ( V_5 ) ) {
V_50 = F_83 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_209 &&
( ( T_2 ) V_4 << V_79 ) >= F_193 ( V_3 ) ) {
error = - V_58 ;
goto V_211;
}
if ( V_5 && V_8 == V_212 )
F_194 ( V_5 ) ;
if ( V_5 && ! F_110 ( V_5 ) ) {
if ( V_8 != V_116 )
goto V_213;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_116 && ! V_50 . V_156 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_23 = F_7 ( V_3 -> V_34 ) ;
V_202 = V_200 ? : V_17 -> V_18 ;
if ( V_50 . V_156 ) {
V_5 = F_195 ( V_50 ) ;
if ( ! V_5 ) {
if ( V_201 ) {
* V_201 |= V_214 ;
F_70 ( V_215 ) ;
F_196 ( V_200 , V_215 ) ;
}
V_5 = F_171 ( V_50 , V_148 , V_29 , V_4 ) ;
if ( ! V_5 ) {
error = - V_151 ;
goto V_192;
}
}
F_116 ( V_5 ) ;
if ( ! F_146 ( V_5 ) || F_147 ( V_5 ) != V_50 . V_156 ||
! F_33 ( V_41 , V_4 , V_50 ) ) {
error = - V_88 ;
goto V_211;
}
if ( ! F_110 ( V_5 ) ) {
error = - V_216 ;
goto V_192;
}
F_197 ( V_5 ) ;
if ( F_139 ( V_5 , V_148 ) ) {
error = F_140 ( & V_5 , V_148 , V_29 , V_4 ) ;
if ( error )
goto V_192;
}
error = F_148 ( V_5 , V_202 , V_148 , & V_155 ,
false ) ;
if ( ! error ) {
error = F_59 ( V_5 , V_41 , V_4 ,
F_37 ( V_50 ) ) ;
if ( error ) {
F_149 ( V_5 , V_155 , false ) ;
F_142 ( V_5 ) ;
}
}
if ( error )
goto V_192;
F_150 ( V_5 , V_155 , true , false ) ;
F_67 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
if ( V_8 == V_212 )
F_194 ( V_5 ) ;
F_142 ( V_5 ) ;
F_115 ( V_5 ) ;
F_143 ( V_50 ) ;
} else {
if ( V_41 -> V_139 != & V_140 )
goto V_217;
if ( V_218 == V_56 || V_203 == V_207 )
goto V_217;
if ( V_218 == V_57 )
goto V_219;
switch ( V_23 -> V_59 ) {
T_2 V_75 ;
T_1 V_220 ;
case V_52 :
goto V_217;
case V_54 :
V_220 = F_47 ( V_4 , V_87 ) ;
V_75 = F_47 ( F_193 ( V_3 ) , V_22 ) ;
if ( V_75 >= V_76 &&
V_75 >> V_79 >= V_220 )
goto V_219;
case V_55 :
if ( V_203 == V_208 )
goto V_219;
goto V_217;
}
V_219:
V_5 = F_179 ( V_148 , V_29 , V_23 ,
V_4 , true ) ;
if ( F_198 ( V_5 ) ) {
V_217: V_5 = F_179 ( V_148 , V_29 , V_23 ,
V_4 , false ) ;
}
if ( F_198 ( V_5 ) ) {
int V_221 = 5 ;
error = F_199 ( V_5 ) ;
V_5 = NULL ;
if ( error != - V_27 )
goto V_192;
while ( V_221 -- ) {
int V_77 ;
V_77 = F_40 ( V_23 , NULL , 1 ) ;
if ( V_77 == V_72 )
break;
if ( V_77 )
goto V_217;
}
goto V_192;
}
if ( F_51 ( V_5 ) )
V_186 = F_63 ( V_4 , V_87 ) ;
else
V_186 = V_4 ;
if ( V_8 == V_212 )
F_200 ( V_5 ) ;
error = F_148 ( V_5 , V_202 , V_148 , & V_155 ,
F_51 ( V_5 ) ) ;
if ( error )
goto V_193;
error = F_201 ( V_148 & V_222 ,
F_202 ( V_5 ) ) ;
if ( ! error ) {
error = F_59 ( V_5 , V_41 , V_186 ,
NULL ) ;
F_203 () ;
}
if ( error ) {
F_149 ( V_5 , V_155 ,
F_51 ( V_5 ) ) ;
goto V_193;
}
F_150 ( V_5 , V_155 , false ,
F_51 ( V_5 ) ) ;
F_190 ( V_5 ) ;
F_67 ( & V_29 -> V_39 ) ;
V_29 -> V_31 += 1 << F_202 ( V_5 ) ;
V_3 -> V_37 += V_38 << F_202 ( V_5 ) ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
V_31 = true ;
if ( F_51 ( V_5 ) &&
F_204 ( F_193 ( V_3 ) , V_22 ) <
V_186 + V_87 - 1 ) {
F_17 ( & V_23 -> V_73 ) ;
if ( F_42 ( & V_29 -> V_71 ) ) {
F_127 ( & V_29 -> V_71 ,
& V_23 -> V_71 ) ;
V_23 -> V_81 ++ ;
}
F_18 ( & V_23 -> V_73 ) ;
}
if ( V_8 == V_223 )
V_8 = V_212 ;
V_213:
if ( V_8 != V_212 && ! F_110 ( V_5 ) ) {
struct V_5 * V_224 = F_205 ( V_5 ) ;
int V_86 ;
for ( V_86 = 0 ; V_86 < ( 1 << F_202 ( V_224 ) ) ; V_86 ++ ) {
F_109 ( V_224 + V_86 ) ;
F_153 ( V_224 + V_86 ) ;
}
F_154 ( V_224 ) ;
}
}
if ( V_8 <= V_209 &&
( ( T_2 ) V_4 << V_79 ) >= F_193 ( V_3 ) ) {
if ( V_31 ) {
F_206 ( V_5 ) ;
F_207 ( V_5 ) ;
F_67 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
}
error = - V_58 ;
goto V_211;
}
* V_6 = V_5 + V_4 - V_186 ;
return 0 ;
V_193:
if ( V_23 -> V_35 )
F_28 ( & V_23 -> V_36 ,
1 << F_202 ( V_5 ) ) ;
F_15 ( V_29 -> V_14 , 1 << F_202 ( V_5 ) ) ;
if ( F_51 ( V_5 ) ) {
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
goto V_217;
}
V_192:
if ( V_50 . V_156 && ! F_33 ( V_41 , V_4 , V_50 ) )
error = - V_88 ;
V_211:
if ( V_5 ) {
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
}
if ( error == - V_27 && ! V_204 ++ ) {
F_67 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_74 ( & V_29 -> V_39 ) ;
goto V_210;
}
if ( error == - V_88 )
goto V_210;
return error ;
}
static int F_208 ( T_6 * V_225 , unsigned V_179 , int V_226 , void * V_227 )
{
int V_77 = F_209 ( V_225 , V_179 , V_226 , V_227 ) ;
F_46 ( & V_225 -> V_228 ) ;
return V_77 ;
}
static int F_210 ( struct V_100 * V_101 , struct V_229 * V_230 )
{
struct V_3 * V_3 = F_94 ( V_101 -> V_102 ) ;
T_5 V_148 = F_6 ( V_3 -> V_9 ) ;
enum V_7 V_8 ;
int error ;
int V_77 = V_231 ;
if ( F_145 ( V_3 -> V_166 ) ) {
struct V_167 * V_167 ;
F_17 ( & V_3 -> V_168 ) ;
V_167 = V_3 -> V_166 ;
if ( V_167 &&
V_167 -> V_169 &&
V_230 -> V_232 >= V_167 -> V_95 &&
V_230 -> V_232 < V_167 -> V_65 ) {
T_7 * V_233 ;
F_211 ( V_234 , F_208 ) ;
V_77 = V_235 ;
if ( ( V_230 -> V_14 & V_236 ) &&
! ( V_230 -> V_14 & V_237 ) ) {
F_212 ( & V_101 -> V_238 -> V_239 ) ;
V_77 = V_240 ;
}
V_233 = V_167 -> V_169 ;
F_213 ( V_233 , & V_234 ,
V_241 ) ;
F_18 ( & V_3 -> V_168 ) ;
F_214 () ;
F_17 ( & V_3 -> V_168 ) ;
F_215 ( V_233 , & V_234 ) ;
F_18 ( & V_3 -> V_168 ) ;
return V_77 ;
}
F_18 ( & V_3 -> V_168 ) ;
}
V_8 = V_209 ;
if ( V_101 -> V_242 & V_243 )
V_8 = V_208 ;
else if ( V_101 -> V_242 & V_244 )
V_8 = V_207 ;
error = F_5 ( V_3 , V_230 -> V_232 , & V_230 -> V_5 , V_8 ,
V_148 , V_101 -> V_238 , & V_77 ) ;
if ( error )
return ( ( error == - V_151 ) ? V_245 : V_246 ) ;
return V_77 ;
}
unsigned long F_216 ( struct V_247 * V_247 ,
unsigned long V_248 , unsigned long V_249 ,
unsigned long V_232 , unsigned long V_14 )
{
unsigned long ( * V_250 ) ( struct V_247 * ,
unsigned long , unsigned long , unsigned long , unsigned long ) ;
unsigned long V_251 ;
unsigned long V_252 ;
unsigned long V_253 ;
unsigned long V_254 ;
unsigned long V_255 ;
if ( V_249 > V_256 )
return - V_151 ;
V_250 = V_17 -> V_18 -> V_257 ;
V_251 = V_250 ( V_247 , V_248 , V_249 , V_232 , V_14 ) ;
if ( ! F_126 ( V_137 ) )
return V_251 ;
if ( F_217 ( V_251 ) )
return V_251 ;
if ( V_251 & ~ V_258 )
return V_251 ;
if ( V_251 > V_256 - V_249 )
return V_251 ;
if ( V_218 == V_56 )
return V_251 ;
if ( V_249 < V_76 )
return V_251 ;
if ( V_14 & V_259 )
return V_251 ;
if ( V_248 )
return V_251 ;
if ( V_218 != V_57 ) {
struct V_11 * V_12 ;
if ( V_247 ) {
F_30 ( V_247 -> V_260 != & V_261 ) ;
V_12 = F_94 ( V_247 ) -> V_34 ;
} else {
if ( F_198 ( V_262 ) )
return V_251 ;
V_12 = V_262 -> V_263 ;
}
if ( F_7 ( V_12 ) -> V_59 == V_52 )
return V_251 ;
}
V_252 = ( V_232 << V_79 ) & ( V_76 - 1 ) ;
if ( V_252 && V_252 + V_249 < 2 * V_76 )
return V_251 ;
if ( ( V_251 & ( V_76 - 1 ) ) == V_252 )
return V_251 ;
V_253 = V_249 + V_76 - V_22 ;
if ( V_253 > V_256 )
return V_251 ;
if ( V_253 < V_249 )
return V_251 ;
V_254 = V_250 ( NULL , 0 , V_253 , 0 , V_14 ) ;
if ( F_217 ( V_254 ) )
return V_251 ;
if ( V_254 & ~ V_258 )
return V_251 ;
V_255 = V_254 & ( V_76 - 1 ) ;
V_254 += V_252 - V_255 ;
if ( V_255 > V_252 )
V_254 += V_76 ;
if ( V_254 > V_256 - V_249 )
return V_251 ;
return V_254 ;
}
static int F_218 ( struct V_100 * V_101 , struct V_176 * V_177 )
{
struct V_3 * V_3 = F_94 ( V_101 -> V_102 ) ;
return F_219 ( & F_21 ( V_3 ) -> V_184 , V_101 , V_177 ) ;
}
static struct V_176 * F_220 ( struct V_100 * V_101 ,
unsigned long V_251 )
{
struct V_3 * V_3 = F_94 ( V_101 -> V_102 ) ;
T_1 V_4 ;
V_4 = ( ( V_251 - V_101 -> V_105 ) >> V_79 ) + V_101 -> V_103 ;
return F_168 ( & F_21 ( V_3 ) -> V_184 , V_4 ) ;
}
int F_221 ( struct V_247 * V_247 , int V_39 , struct V_264 * V_265 )
{
struct V_3 * V_3 = F_94 ( V_247 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int V_266 = - V_151 ;
F_67 ( & V_29 -> V_39 ) ;
if ( V_39 && ! ( V_29 -> V_14 & V_162 ) ) {
if ( ! F_222 ( V_3 -> V_75 , V_265 ) )
goto V_267;
V_29 -> V_14 |= V_162 ;
F_223 ( V_247 -> V_268 ) ;
}
if ( ! V_39 && ( V_29 -> V_14 & V_162 ) && V_265 ) {
F_224 ( V_3 -> V_75 , V_265 ) ;
V_29 -> V_14 &= ~ V_162 ;
F_225 ( V_247 -> V_268 ) ;
}
V_266 = 0 ;
V_267:
F_74 ( & V_29 -> V_39 ) ;
return V_266 ;
}
static int F_226 ( struct V_247 * V_247 , struct V_100 * V_101 )
{
F_227 ( V_247 ) ;
V_101 -> V_182 = & V_269 ;
if ( F_126 ( V_137 ) &&
( ( V_101 -> V_105 + ~ V_78 ) & V_78 ) <
( V_101 -> V_104 & V_78 ) ) {
F_228 ( V_101 , V_101 -> V_242 ) ;
}
return 0 ;
}
static struct V_3 * F_229 ( struct V_11 * V_12 , const struct V_3 * V_270 ,
T_8 V_179 , T_9 V_271 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( F_16 ( V_12 ) )
return NULL ;
V_3 = F_230 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_181 = F_231 () ;
F_232 ( V_3 , V_270 , V_179 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_272 = V_3 -> V_119 = V_3 -> V_118 = F_118 ( V_3 ) ;
V_3 -> V_273 = F_233 () ;
V_29 = F_21 ( V_3 ) ;
memset ( V_29 , 0 , ( char * ) V_3 - ( char * ) V_29 ) ;
F_234 ( & V_29 -> V_39 ) ;
V_29 -> V_132 = V_274 ;
V_29 -> V_14 = V_14 & V_16 ;
F_235 ( & V_29 -> V_71 ) ;
F_235 ( & V_29 -> V_141 ) ;
F_236 ( & V_29 -> V_143 ) ;
F_237 ( V_3 ) ;
switch ( V_179 & V_275 ) {
default:
V_3 -> V_276 = & V_277 ;
F_238 ( V_3 , V_179 , V_271 ) ;
break;
case V_278 :
V_3 -> V_9 -> V_139 = & V_140 ;
V_3 -> V_276 = & V_279 ;
V_3 -> V_280 = & V_261 ;
F_239 ( & V_29 -> V_184 ,
F_165 ( V_23 ) ) ;
break;
case V_281 :
F_240 ( V_3 ) ;
V_3 -> V_75 = 2 * V_282 ;
V_3 -> V_276 = & V_283 ;
V_3 -> V_280 = & V_284 ;
break;
case V_285 :
F_239 ( & V_29 -> V_184 , NULL ) ;
break;
}
} else
F_19 ( V_12 ) ;
return V_3 ;
}
bool F_241 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_161 )
return false ;
return V_41 -> V_161 -> V_34 -> V_286 == & V_287 ;
}
static int
F_242 ( struct V_247 * V_247 , struct V_40 * V_41 ,
T_2 V_64 , unsigned V_249 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_288 )
{
struct V_3 * V_3 = V_41 -> V_161 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_4 = V_64 >> V_79 ;
if ( F_145 ( V_29 -> V_132 ) ) {
if ( V_29 -> V_132 & V_289 )
return - V_135 ;
if ( ( V_29 -> V_132 & V_134 ) && V_64 + V_249 > V_3 -> V_75 )
return - V_135 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_212 ) ;
}
static int
F_243 ( struct V_247 * V_247 , struct V_40 * V_41 ,
T_2 V_64 , unsigned V_249 , unsigned V_290 ,
struct V_5 * V_5 , void * V_288 )
{
struct V_3 * V_3 = V_41 -> V_161 ;
if ( V_64 + V_290 > V_3 -> V_75 )
F_124 ( V_3 , V_64 + V_290 ) ;
if ( ! F_110 ( V_5 ) ) {
struct V_5 * V_224 = F_205 ( V_5 ) ;
if ( F_244 ( V_5 ) ) {
int V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
if ( V_224 + V_86 == V_5 )
continue;
F_109 ( V_224 + V_86 ) ;
F_153 ( V_224 + V_86 ) ;
}
}
if ( V_290 < V_22 ) {
unsigned V_291 = V_64 & ( V_22 - 1 ) ;
F_245 ( V_5 , 0 , V_291 ,
V_291 + V_290 , V_22 ) ;
}
F_154 ( V_224 ) ;
}
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
return V_290 ;
}
static T_10 F_246 ( struct V_292 * V_293 , struct V_294 * V_295 )
{
struct V_247 * V_247 = V_293 -> V_296 ;
struct V_3 * V_3 = F_94 ( V_247 ) ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_252 ;
enum V_7 V_8 = V_116 ;
int error = 0 ;
T_10 V_266 = 0 ;
T_2 * V_297 = & V_293 -> V_298 ;
if ( ! F_247 ( V_295 ) )
V_8 = V_209 ;
V_4 = * V_297 >> V_79 ;
V_252 = * V_297 & ~ V_258 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_299 ;
unsigned long V_82 , V_77 ;
T_2 V_75 = F_193 ( V_3 ) ;
V_299 = V_75 >> V_79 ;
if ( V_4 > V_299 )
break;
if ( V_4 == V_299 ) {
V_82 = V_75 & ~ V_258 ;
if ( V_82 <= V_252 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_58 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_209 )
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
}
V_82 = V_22 ;
V_75 = F_193 ( V_3 ) ;
V_299 = V_75 >> V_79 ;
if ( V_4 == V_299 ) {
V_82 = V_75 & ~ V_258 ;
if ( V_82 <= V_252 ) {
if ( V_5 )
F_53 ( V_5 ) ;
break;
}
}
V_82 -= V_252 ;
if ( V_5 ) {
if ( F_248 ( V_41 ) )
F_153 ( V_5 ) ;
if ( ! V_252 )
F_194 ( V_5 ) ;
} else {
V_5 = F_249 ( 0 ) ;
F_185 ( V_5 ) ;
}
V_77 = F_250 ( V_5 , V_252 , V_82 , V_295 ) ;
V_266 += V_77 ;
V_252 += V_77 ;
V_4 += V_252 >> V_79 ;
V_252 &= ~ V_258 ;
F_53 ( V_5 ) ;
if ( ! F_251 ( V_295 ) )
break;
if ( V_77 < V_82 ) {
error = - V_300 ;
break;
}
F_103 () ;
}
* V_297 = ( ( T_2 ) V_4 << V_79 ) + V_252 ;
F_227 ( V_247 ) ;
return V_266 ? V_266 : error ;
}
static T_1 F_252 ( struct V_40 * V_41 ,
T_1 V_4 , T_1 V_96 , int V_301 )
{
struct V_5 * V_5 ;
struct V_106 V_107 ;
T_1 V_108 [ V_109 ] ;
bool V_302 = false ;
int V_86 ;
F_97 ( & V_107 , 0 ) ;
V_107 . V_82 = 1 ;
while ( ! V_302 ) {
V_107 . V_82 = F_99 ( V_41 , V_4 ,
V_107 . V_82 , V_107 . V_21 , V_108 ) ;
if ( ! V_107 . V_82 ) {
if ( V_301 == V_303 )
V_4 = V_96 ;
break;
}
for ( V_86 = 0 ; V_86 < V_107 . V_82 ; V_86 ++ , V_4 ++ ) {
if ( V_4 < V_108 [ V_86 ] ) {
if ( V_301 == V_304 ) {
V_302 = true ;
break;
}
V_4 = V_108 [ V_86 ] ;
}
V_5 = V_107 . V_21 [ V_86 ] ;
if ( V_5 && ! F_89 ( V_5 ) ) {
if ( ! F_110 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_96 ||
( V_5 && V_301 == V_303 ) ||
( ! V_5 && V_301 == V_304 ) ) {
V_302 = true ;
break;
}
}
F_100 ( & V_107 ) ;
F_102 ( & V_107 ) ;
V_107 . V_82 = V_109 ;
F_103 () ;
}
return V_4 ;
}
static T_2 F_253 ( struct V_247 * V_247 , T_2 V_252 , int V_301 )
{
struct V_40 * V_41 = V_247 -> V_268 ;
struct V_3 * V_3 = V_41 -> V_161 ;
T_1 V_95 , V_96 ;
T_2 V_305 ;
if ( V_301 != V_303 && V_301 != V_304 )
return F_254 ( V_247 , V_252 , V_301 ,
V_205 , F_193 ( V_3 ) ) ;
F_255 ( V_3 ) ;
if ( V_252 < 0 )
V_252 = - V_58 ;
else if ( V_252 >= V_3 -> V_75 )
V_252 = - V_306 ;
else {
V_95 = V_252 >> V_79 ;
V_96 = ( V_3 -> V_75 + V_22 - 1 ) >> V_79 ;
V_305 = F_252 ( V_41 , V_95 , V_96 , V_301 ) ;
V_305 <<= V_79 ;
if ( V_305 > V_252 ) {
if ( V_305 < V_3 -> V_75 )
V_252 = V_305 ;
else if ( V_301 == V_303 )
V_252 = - V_306 ;
else
V_252 = V_3 -> V_75 ;
}
}
if ( V_252 >= 0 )
V_252 = F_256 ( V_247 , V_252 , V_205 ) ;
F_257 ( V_3 ) ;
return V_252 ;
}
static void F_258 ( struct V_40 * V_41 )
{
struct V_97 V_98 ;
void * * V_99 ;
T_1 V_95 ;
struct V_5 * V_5 ;
F_259 () ;
V_95 = 0 ;
F_34 () ;
F_85 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_86 ( V_99 ) ;
if ( ! V_5 || F_260 ( V_5 ) ) {
if ( F_87 ( V_5 ) ) {
V_99 = F_88 ( & V_98 ) ;
continue;
}
} else if ( F_261 ( V_5 ) - F_262 ( V_5 ) > 1 ) {
F_67 ( & V_41 -> V_83 ) ;
F_263 ( & V_41 -> V_48 , V_98 . V_4 ,
V_307 ) ;
F_74 ( & V_41 -> V_83 ) ;
}
if ( F_90 () ) {
V_99 = F_91 ( V_99 , & V_98 ) ;
F_92 () ;
}
}
F_36 () ;
}
static int F_264 ( struct V_40 * V_41 )
{
struct V_97 V_98 ;
void * * V_99 ;
T_1 V_95 ;
struct V_5 * V_5 ;
int error , V_308 ;
F_258 ( V_41 ) ;
error = 0 ;
for ( V_308 = 0 ; V_308 <= V_309 ; V_308 ++ ) {
if ( ! F_265 ( & V_41 -> V_48 , V_307 ) )
break;
if ( ! V_308 )
F_266 () ;
else if ( F_267 ( ( V_310 << V_308 ) / 200 ) )
V_308 = V_309 ;
V_95 = 0 ;
F_34 () ;
F_268 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_86 ( V_99 ) ;
if ( F_260 ( V_5 ) ) {
if ( F_87 ( V_5 ) ) {
V_99 = F_88 ( & V_98 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_261 ( V_5 ) - F_262 ( V_5 ) != 1 ) {
if ( V_308 < V_309 )
goto V_311;
error = - V_312 ;
}
F_67 ( & V_41 -> V_83 ) ;
F_269 ( & V_41 -> V_48 ,
V_98 . V_4 , V_307 ) ;
F_74 ( & V_41 -> V_83 ) ;
V_311:
if ( F_90 () ) {
V_99 = F_91 ( V_99 , & V_98 ) ;
F_92 () ;
}
}
F_36 () ;
}
return error ;
}
int F_270 ( struct V_247 * V_247 , unsigned int V_132 )
{
struct V_3 * V_3 = F_94 ( V_247 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int error ;
if ( V_247 -> V_260 != & V_261 )
return - V_58 ;
if ( ! ( V_247 -> V_313 & V_314 ) )
return - V_135 ;
if ( V_132 & ~ ( unsigned int ) V_315 )
return - V_58 ;
F_255 ( V_3 ) ;
if ( V_29 -> V_132 & V_274 ) {
error = - V_135 ;
goto V_211;
}
if ( ( V_132 & V_289 ) && ! ( V_29 -> V_132 & V_289 ) ) {
error = F_271 ( V_247 -> V_268 ) ;
if ( error )
goto V_211;
error = F_264 ( V_247 -> V_268 ) ;
if ( error ) {
F_272 ( V_247 -> V_268 ) ;
goto V_211;
}
}
V_29 -> V_132 |= V_132 ;
error = 0 ;
V_211:
F_257 ( V_3 ) ;
return error ;
}
int F_273 ( struct V_247 * V_247 )
{
if ( V_247 -> V_260 != & V_261 )
return - V_58 ;
return F_21 ( F_94 ( V_247 ) ) -> V_132 ;
}
long F_274 ( struct V_247 * V_247 , unsigned int V_316 , unsigned long V_317 )
{
long error ;
switch ( V_316 ) {
case V_318 :
if ( V_317 > V_319 )
return - V_58 ;
error = F_270 ( V_247 , V_317 ) ;
break;
case V_320 :
error = F_273 ( V_247 ) ;
break;
default:
error = - V_58 ;
break;
}
return error ;
}
static long F_275 ( struct V_247 * V_247 , int V_179 , T_2 V_252 ,
T_2 V_249 )
{
struct V_3 * V_3 = F_94 ( V_247 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_167 V_167 ;
T_1 V_95 , V_4 , V_96 ;
int error ;
if ( V_179 & ~ ( V_321 | V_322 ) )
return - V_323 ;
F_255 ( V_3 ) ;
if ( V_179 & V_322 ) {
struct V_40 * V_41 = V_247 -> V_268 ;
T_2 V_324 = F_47 ( V_252 , V_22 ) ;
T_2 V_325 = F_63 ( V_252 + V_249 , V_22 ) - 1 ;
F_276 ( V_233 ) ;
if ( V_29 -> V_132 & V_289 ) {
error = - V_135 ;
goto V_157;
}
V_167 . V_169 = & V_233 ;
V_167 . V_95 = V_324 >> V_79 ;
V_167 . V_65 = ( V_325 + 1 ) >> V_79 ;
F_17 ( & V_3 -> V_168 ) ;
V_3 -> V_166 = & V_167 ;
F_18 ( & V_3 -> V_168 ) ;
if ( ( V_326 ) V_325 > ( V_326 ) V_324 )
F_125 ( V_41 , V_324 ,
1 + V_325 - V_324 , 0 ) ;
F_117 ( V_3 , V_252 , V_252 + V_249 - 1 ) ;
F_17 ( & V_3 -> V_168 ) ;
V_3 -> V_166 = NULL ;
F_277 ( & V_233 ) ;
F_152 ( ! F_42 ( & V_233 . V_228 ) ) ;
F_18 ( & V_3 -> V_168 ) ;
error = 0 ;
goto V_157;
}
error = F_278 ( V_3 , V_252 + V_249 ) ;
if ( error )
goto V_157;
if ( ( V_29 -> V_132 & V_134 ) && V_252 + V_249 > V_3 -> V_75 ) {
error = - V_135 ;
goto V_157;
}
V_95 = V_252 >> V_79 ;
V_96 = ( V_252 + V_249 + V_22 - 1 ) >> V_79 ;
if ( V_23 -> V_35 && V_96 - V_95 > V_23 -> V_35 ) {
error = - V_27 ;
goto V_157;
}
V_167 . V_169 = NULL ;
V_167 . V_95 = V_95 ;
V_167 . V_65 = V_95 ;
V_167 . V_327 = 0 ;
V_167 . V_170 = 0 ;
F_17 ( & V_3 -> V_168 ) ;
V_3 -> V_166 = & V_167 ;
F_18 ( & V_3 -> V_168 ) ;
for ( V_4 = V_95 ; V_4 < V_96 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_279 ( V_17 ) )
error = - V_328 ;
else if ( V_167 . V_170 > V_167 . V_327 )
error = - V_151 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_223 ) ;
if ( error ) {
if ( V_4 > V_95 ) {
F_104 ( V_3 ,
( T_2 ) V_95 << V_79 ,
( ( T_2 ) V_4 << V_79 ) - 1 , true ) ;
}
goto V_329;
}
V_167 . V_65 ++ ;
if ( ! F_110 ( V_5 ) )
V_167 . V_327 ++ ;
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
F_103 () ;
}
if ( ! ( V_179 & V_321 ) && V_252 + V_249 > V_3 -> V_75 )
F_124 ( V_3 , V_252 + V_249 ) ;
V_3 -> V_118 = F_118 ( V_3 ) ;
V_329:
F_17 ( & V_3 -> V_168 ) ;
V_3 -> V_166 = NULL ;
F_18 ( & V_3 -> V_168 ) ;
V_157:
F_257 ( V_3 ) ;
return error ;
}
static int F_280 ( struct V_122 * V_122 , struct V_330 * V_331 )
{
struct V_10 * V_23 = F_7 ( V_122 -> V_332 ) ;
V_331 -> V_333 = V_334 ;
V_331 -> V_335 = V_22 ;
V_331 -> V_336 = V_337 ;
if ( V_23 -> V_35 ) {
V_331 -> V_338 = V_23 -> V_35 ;
V_331 -> V_339 =
V_331 -> V_340 = V_23 -> V_35 -
F_281 ( & V_23 -> V_36 ) ;
}
if ( V_23 -> V_24 ) {
V_331 -> V_341 = V_23 -> V_24 ;
V_331 -> V_342 = V_23 -> V_26 ;
}
return 0 ;
}
static int
F_282 ( struct V_3 * V_270 , struct V_122 * V_122 , T_8 V_179 , T_9 V_271 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_229 ( V_270 -> V_34 , V_270 , V_179 , V_271 , V_16 ) ;
if ( V_3 ) {
error = F_283 ( V_270 , V_3 ) ;
if ( error )
goto V_343;
error = F_284 ( V_3 , V_270 ,
& V_122 -> V_344 ,
V_345 , NULL ) ;
if ( error && error != - V_323 )
goto V_343;
error = 0 ;
V_270 -> V_75 += V_282 ;
V_270 -> V_118 = V_270 -> V_119 = F_118 ( V_270 ) ;
F_285 ( V_122 , V_3 ) ;
F_286 ( V_122 ) ;
}
return error ;
V_343:
F_49 ( V_3 ) ;
return error ;
}
static int
F_287 ( struct V_3 * V_270 , struct V_122 * V_122 , T_8 V_179 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_229 ( V_270 -> V_34 , V_270 , V_179 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_284 ( V_3 , V_270 ,
NULL ,
V_345 , NULL ) ;
if ( error && error != - V_323 )
goto V_343;
error = F_283 ( V_270 , V_3 ) ;
if ( error )
goto V_343;
F_288 ( V_122 , V_3 ) ;
}
return error ;
V_343:
F_49 ( V_3 ) ;
return error ;
}
static int F_289 ( struct V_3 * V_270 , struct V_122 * V_122 , T_8 V_179 )
{
int error ;
if ( ( error = F_282 ( V_270 , V_122 , V_179 | V_281 , 0 ) ) )
return error ;
F_240 ( V_270 ) ;
return 0 ;
}
static int F_290 ( struct V_3 * V_270 , struct V_122 * V_122 , T_8 V_179 ,
bool V_346 )
{
return F_282 ( V_270 , V_122 , V_179 | V_278 , 0 ) ;
}
static int F_291 ( struct V_122 * V_347 , struct V_3 * V_270 , struct V_122 * V_122 )
{
struct V_3 * V_3 = V_125 ( V_347 ) ;
int V_77 ;
V_77 = F_16 ( V_3 -> V_34 ) ;
if ( V_77 )
goto V_157;
V_270 -> V_75 += V_282 ;
V_3 -> V_118 = V_270 -> V_118 = V_270 -> V_119 = F_118 ( V_3 ) ;
F_240 ( V_3 ) ;
F_292 ( V_3 ) ;
F_286 ( V_122 ) ;
F_285 ( V_122 , V_3 ) ;
V_157:
return V_77 ;
}
static int F_293 ( struct V_3 * V_270 , struct V_122 * V_122 )
{
struct V_3 * V_3 = V_125 ( V_122 ) ;
if ( V_3 -> V_348 > 1 && ! F_294 ( V_3 -> V_128 ) )
F_19 ( V_3 -> V_34 ) ;
V_270 -> V_75 -= V_282 ;
V_3 -> V_118 = V_270 -> V_118 = V_270 -> V_119 = F_118 ( V_3 ) ;
F_295 ( V_3 ) ;
F_296 ( V_122 ) ;
return 0 ;
}
static int F_297 ( struct V_3 * V_270 , struct V_122 * V_122 )
{
if ( ! F_298 ( V_122 ) )
return - V_349 ;
F_295 ( V_125 ( V_122 ) ) ;
F_295 ( V_270 ) ;
return F_293 ( V_270 , V_122 ) ;
}
static int F_299 ( struct V_3 * V_350 , struct V_122 * V_347 , struct V_3 * V_351 , struct V_122 * V_352 )
{
bool V_353 = F_300 ( V_347 ) ;
bool V_354 = F_300 ( V_352 ) ;
if ( V_350 != V_351 && V_353 != V_354 ) {
if ( V_353 ) {
F_295 ( V_350 ) ;
F_240 ( V_351 ) ;
} else {
F_295 ( V_351 ) ;
F_240 ( V_350 ) ;
}
}
V_350 -> V_118 = V_350 -> V_119 =
V_351 -> V_118 = V_351 -> V_119 =
V_125 ( V_347 ) -> V_118 =
V_125 ( V_352 ) -> V_118 = F_118 ( V_350 ) ;
return 0 ;
}
static int F_301 ( struct V_3 * V_350 , struct V_122 * V_347 )
{
struct V_122 * V_355 ;
int error ;
V_355 = F_302 ( V_347 -> V_356 , & V_347 -> V_344 ) ;
if ( ! V_355 )
return - V_151 ;
error = F_282 ( V_350 , V_355 ,
V_357 | V_358 , V_359 ) ;
F_296 ( V_355 ) ;
if ( error )
return error ;
F_303 ( V_355 ) ;
return 0 ;
}
static int F_304 ( struct V_3 * V_350 , struct V_122 * V_347 , struct V_3 * V_351 , struct V_122 * V_352 , unsigned int V_14 )
{
struct V_3 * V_3 = V_125 ( V_347 ) ;
int V_360 = F_294 ( V_3 -> V_128 ) ;
if ( V_14 & ~ ( V_361 | V_362 | V_363 ) )
return - V_58 ;
if ( V_14 & V_362 )
return F_299 ( V_350 , V_347 , V_351 , V_352 ) ;
if ( ! F_298 ( V_352 ) )
return - V_349 ;
if ( V_14 & V_363 ) {
int error ;
error = F_301 ( V_350 , V_347 ) ;
if ( error )
return error ;
}
if ( F_305 ( V_352 ) ) {
( void ) F_293 ( V_351 , V_352 ) ;
if ( V_360 ) {
F_295 ( V_125 ( V_352 ) ) ;
F_295 ( V_350 ) ;
}
} else if ( V_360 ) {
F_295 ( V_350 ) ;
F_240 ( V_351 ) ;
}
V_350 -> V_75 -= V_282 ;
V_351 -> V_75 += V_282 ;
V_350 -> V_118 = V_350 -> V_119 =
V_351 -> V_118 = V_351 -> V_119 =
V_3 -> V_118 = F_118 ( V_350 ) ;
return 0 ;
}
static int F_306 ( struct V_3 * V_270 , struct V_122 * V_122 , const char * V_364 )
{
int error ;
int V_249 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_28 * V_29 ;
V_249 = strlen ( V_364 ) + 1 ;
if ( V_249 > V_22 )
return - V_365 ;
V_3 = F_229 ( V_270 -> V_34 , V_270 , V_285 | V_366 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_27 ;
error = F_284 ( V_3 , V_270 , & V_122 -> V_344 ,
V_345 , NULL ) ;
if ( error ) {
if ( error != - V_323 ) {
F_49 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_3 -> V_75 = V_249 - 1 ;
if ( V_249 <= V_367 ) {
V_3 -> V_368 = F_307 ( V_364 , V_249 , V_158 ) ;
if ( ! V_3 -> V_368 ) {
F_49 ( V_3 ) ;
return - V_151 ;
}
V_3 -> V_276 = & V_369 ;
} else {
F_308 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_212 ) ;
if ( error ) {
F_49 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_139 = & V_140 ;
V_3 -> V_276 = & V_370 ;
memcpy ( F_309 ( V_5 ) , V_364 , V_249 ) ;
F_154 ( V_5 ) ;
F_115 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
}
V_270 -> V_75 += V_282 ;
V_270 -> V_118 = V_270 -> V_119 = F_118 ( V_270 ) ;
F_285 ( V_122 , V_3 ) ;
F_286 ( V_122 ) ;
return 0 ;
}
static void F_310 ( void * V_317 )
{
F_194 ( V_317 ) ;
F_53 ( V_317 ) ;
}
static const char * F_311 ( struct V_122 * V_122 ,
struct V_3 * V_3 ,
struct V_371 * V_302 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_122 ) {
V_5 = F_312 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_182 ( - V_372 ) ;
if ( ! F_110 ( V_5 ) ) {
F_53 ( V_5 ) ;
return F_182 ( - V_372 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_116 ) ;
if ( error )
return F_182 ( error ) ;
F_52 ( V_5 ) ;
}
F_313 ( V_302 , F_310 , V_5 ) ;
return F_309 ( V_5 ) ;
}
static int V_345 ( struct V_3 * V_3 ,
const struct V_373 * V_374 ,
void * V_375 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
const struct V_373 * V_373 ;
struct V_376 * V_377 ;
T_11 V_249 ;
for ( V_373 = V_374 ; V_373 -> V_378 != NULL ; V_373 ++ ) {
V_377 = F_314 ( V_373 -> V_379 , V_373 -> V_380 ) ;
if ( ! V_377 )
return - V_151 ;
V_249 = strlen ( V_373 -> V_378 ) + 1 ;
V_377 -> V_378 = F_315 ( V_381 + V_249 ,
V_158 ) ;
if ( ! V_377 -> V_378 ) {
F_316 ( V_377 ) ;
return - V_151 ;
}
memcpy ( V_377 -> V_378 , V_382 ,
V_381 ) ;
memcpy ( V_377 -> V_378 + V_381 ,
V_373 -> V_378 , V_249 ) ;
F_317 ( & V_29 -> V_143 , V_377 ) ;
}
return 0 ;
}
static int F_318 ( const struct V_383 * V_384 ,
struct V_122 * V_385 , struct V_3 * V_3 ,
const char * V_378 , void * V_178 , T_11 V_15 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_378 = F_319 ( V_384 , V_378 ) ;
return F_320 ( & V_29 -> V_143 , V_378 , V_178 , V_15 ) ;
}
static int F_321 ( const struct V_383 * V_384 ,
struct V_122 * V_385 , struct V_3 * V_3 ,
const char * V_378 , const void * V_379 ,
T_11 V_15 , int V_14 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_378 = F_319 ( V_384 , V_378 ) ;
return F_322 ( & V_29 -> V_143 , V_378 , V_379 , V_15 , V_14 ) ;
}
static T_10 F_323 ( struct V_122 * V_122 , char * V_178 , T_11 V_15 )
{
struct V_28 * V_29 = F_21 ( V_125 ( V_122 ) ) ;
return F_324 ( V_125 ( V_122 ) , & V_29 -> V_143 , V_178 , V_15 ) ;
}
static struct V_122 * F_325 ( struct V_122 * V_386 )
{
return F_182 ( - V_387 ) ;
}
static int F_326 ( struct V_3 * V_388 , void * V_389 )
{
T_12 * V_390 = V_389 ;
T_13 V_391 = V_390 [ 2 ] ;
V_391 = ( V_391 << 32 ) | V_390 [ 1 ] ;
return V_388 -> V_181 == V_391 && V_390 [ 0 ] == V_388 -> V_273 ;
}
static struct V_122 * F_327 ( struct V_11 * V_12 ,
struct V_392 * V_392 , int V_393 , int V_394 )
{
struct V_3 * V_3 ;
struct V_122 * V_122 = NULL ;
V_326 V_391 ;
if ( V_393 < 3 )
return NULL ;
V_391 = V_392 -> V_395 [ 2 ] ;
V_391 = ( V_391 << 32 ) | V_392 -> V_395 [ 1 ] ;
V_3 = F_328 ( V_12 , ( unsigned long ) ( V_391 + V_392 -> V_395 [ 0 ] ) ,
F_326 , V_392 -> V_395 ) ;
if ( V_3 ) {
V_122 = F_329 ( V_3 ) ;
F_49 ( V_3 ) ;
}
return V_122 ;
}
static int F_330 ( struct V_3 * V_3 , T_12 * V_390 , int * V_249 ,
struct V_3 * V_396 )
{
if ( * V_249 < 3 ) {
* V_249 = 3 ;
return V_397 ;
}
if ( F_331 ( V_3 ) ) {
static F_332 ( V_39 ) ;
F_17 ( & V_39 ) ;
if ( F_331 ( V_3 ) )
F_333 ( V_3 ,
V_3 -> V_181 + V_3 -> V_273 ) ;
F_18 ( & V_39 ) ;
}
V_390 [ 0 ] = V_3 -> V_273 ;
V_390 [ 1 ] = V_3 -> V_181 ;
V_390 [ 2 ] = ( ( T_13 ) V_3 -> V_181 ) >> 32 ;
* V_249 = 3 ;
return 1 ;
}
static int F_334 ( char * V_398 , struct V_10 * V_23 ,
bool V_399 )
{
char * V_400 , * V_379 , * V_401 ;
struct V_176 * V_177 = NULL ;
T_14 V_402 ;
T_15 V_403 ;
while ( V_398 != NULL ) {
V_400 = V_398 ;
for (; ; ) {
V_398 = strchr ( V_398 , ',' ) ;
if ( V_398 == NULL )
break;
V_398 ++ ;
if ( ! isdigit ( * V_398 ) ) {
V_398 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_400 )
continue;
if ( ( V_379 = strchr ( V_400 , '=' ) ) != NULL ) {
* V_379 ++ = 0 ;
} else {
F_335 ( L_9 ,
V_400 ) ;
goto error;
}
if ( ! strcmp ( V_400 , L_10 ) ) {
unsigned long long V_15 ;
V_15 = F_336 ( V_379 , & V_401 ) ;
if ( * V_401 == '%' ) {
V_15 <<= V_79 ;
V_15 *= V_1 ;
F_337 ( V_15 , 100 ) ;
V_401 ++ ;
}
if ( * V_401 )
goto V_404;
V_23 -> V_35 =
F_204 ( V_15 , V_22 ) ;
} else if ( ! strcmp ( V_400 , L_11 ) ) {
V_23 -> V_35 = F_336 ( V_379 , & V_401 ) ;
if ( * V_401 )
goto V_404;
} else if ( ! strcmp ( V_400 , L_12 ) ) {
V_23 -> V_24 = F_336 ( V_379 , & V_401 ) ;
if ( * V_401 )
goto V_404;
} else if ( ! strcmp ( V_400 , L_13 ) ) {
if ( V_399 )
continue;
V_23 -> V_179 = F_338 ( V_379 , & V_401 , 8 ) & 07777 ;
if ( * V_401 )
goto V_404;
} else if ( ! strcmp ( V_400 , L_14 ) ) {
if ( V_399 )
continue;
V_402 = F_338 ( V_379 , & V_401 , 0 ) ;
if ( * V_401 )
goto V_404;
V_23 -> V_402 = F_339 ( F_340 () , V_402 ) ;
if ( ! F_341 ( V_23 -> V_402 ) )
goto V_404;
} else if ( ! strcmp ( V_400 , L_15 ) ) {
if ( V_399 )
continue;
V_403 = F_338 ( V_379 , & V_401 , 0 ) ;
if ( * V_401 )
goto V_404;
V_23 -> V_403 = F_342 ( F_340 () , V_403 ) ;
if ( ! F_343 ( V_23 -> V_403 ) )
goto V_404;
#ifdef V_137
} else if ( ! strcmp ( V_400 , L_16 ) ) {
int V_59 ;
V_59 = F_38 ( V_379 ) ;
if ( V_59 < 0 )
goto V_404;
if ( ! F_344 () &&
V_59 != V_52 )
goto V_404;
V_23 -> V_59 = V_59 ;
#endif
#ifdef F_345
} else if ( ! strcmp ( V_400 , L_17 ) ) {
F_346 ( V_177 ) ;
V_177 = NULL ;
if ( F_347 ( V_379 , & V_177 ) )
goto V_404;
#endif
} else {
F_335 ( L_18 , V_400 ) ;
goto error;
}
}
V_23 -> V_177 = V_177 ;
return 0 ;
V_404:
F_335 ( L_19 ,
V_379 , V_400 ) ;
error:
F_346 ( V_177 ) ;
return 1 ;
}
static int F_348 ( struct V_11 * V_12 , int * V_14 , char * V_405 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
struct V_10 V_406 = * V_23 ;
unsigned long V_407 ;
int error = - V_58 ;
V_406 . V_177 = NULL ;
if ( F_334 ( V_405 , & V_406 , true ) )
return error ;
F_17 ( & V_23 -> V_25 ) ;
V_407 = V_23 -> V_24 - V_23 -> V_26 ;
if ( F_26 ( & V_23 -> V_36 , V_406 . V_35 ) > 0 )
goto V_157;
if ( V_406 . V_24 < V_407 )
goto V_157;
if ( V_406 . V_35 && ! V_23 -> V_35 )
goto V_157;
if ( V_406 . V_24 && ! V_23 -> V_24 )
goto V_157;
error = 0 ;
V_23 -> V_59 = V_406 . V_59 ;
V_23 -> V_35 = V_406 . V_35 ;
V_23 -> V_24 = V_406 . V_24 ;
V_23 -> V_26 = V_406 . V_24 - V_407 ;
if ( V_406 . V_177 ) {
F_346 ( V_23 -> V_177 ) ;
V_23 -> V_177 = V_406 . V_177 ;
}
V_157:
F_18 ( & V_23 -> V_25 ) ;
return error ;
}
static int F_349 ( struct V_174 * V_175 , struct V_122 * V_145 )
{
struct V_10 * V_23 = F_7 ( V_145 -> V_332 ) ;
if ( V_23 -> V_35 != F_1 () )
F_164 ( V_175 , L_20 ,
V_23 -> V_35 << ( V_79 - 10 ) ) ;
if ( V_23 -> V_24 != F_2 () )
F_164 ( V_175 , L_21 , V_23 -> V_24 ) ;
if ( V_23 -> V_179 != ( V_366 | V_408 ) )
F_164 ( V_175 , L_22 , V_23 -> V_179 ) ;
if ( ! F_350 ( V_23 -> V_402 , V_409 ) )
F_164 ( V_175 , L_23 ,
F_351 ( & V_410 , V_23 -> V_402 ) ) ;
if ( ! F_352 ( V_23 -> V_403 , V_411 ) )
F_164 ( V_175 , L_24 ,
F_353 ( & V_410 , V_23 -> V_403 ) ) ;
#ifdef V_137
if ( V_23 -> V_59 )
F_164 ( V_175 , L_25 , F_39 ( V_23 -> V_59 ) ) ;
#endif
F_162 ( V_175 , V_23 -> V_177 ) ;
return 0 ;
}
static void F_354 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
F_355 ( & V_23 -> V_36 ) ;
F_346 ( V_23 -> V_177 ) ;
F_316 ( V_23 ) ;
V_12 -> V_13 = NULL ;
}
int F_356 ( struct V_11 * V_12 , void * V_405 , int V_412 )
{
struct V_3 * V_3 ;
struct V_10 * V_23 ;
int V_191 = - V_151 ;
V_23 = F_357 ( F_358 ( ( int ) sizeof( struct V_10 ) ,
V_413 ) , V_158 ) ;
if ( ! V_23 )
return - V_151 ;
V_23 -> V_179 = V_366 | V_408 ;
V_23 -> V_402 = F_359 () ;
V_23 -> V_403 = F_360 () ;
V_12 -> V_13 = V_23 ;
#ifdef F_361
if ( ! ( V_12 -> V_414 & V_415 ) ) {
V_23 -> V_35 = F_1 () ;
V_23 -> V_24 = F_2 () ;
if ( F_334 ( V_405 , V_23 , false ) ) {
V_191 = - V_58 ;
goto V_192;
}
} else {
V_12 -> V_414 |= V_416 ;
}
V_12 -> V_417 = & V_418 ;
V_12 -> V_414 |= V_419 ;
#else
V_12 -> V_414 |= V_416 ;
#endif
F_234 ( & V_23 -> V_25 ) ;
if ( F_362 ( & V_23 -> V_36 , 0 , V_158 ) )
goto V_192;
V_23 -> V_26 = V_23 -> V_24 ;
F_234 ( & V_23 -> V_73 ) ;
F_235 ( & V_23 -> V_71 ) ;
V_12 -> V_420 = V_205 ;
V_12 -> V_421 = V_22 ;
V_12 -> V_422 = V_79 ;
V_12 -> V_423 = V_334 ;
V_12 -> V_286 = & V_287 ;
V_12 -> V_424 = 1 ;
#ifdef F_363
V_12 -> V_425 = V_426 ;
#endif
#ifdef F_364
V_12 -> V_414 |= V_427 ;
#endif
V_3 = F_229 ( V_12 , NULL , V_281 | V_23 -> V_179 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_192;
V_3 -> V_428 = V_23 -> V_402 ;
V_3 -> V_429 = V_23 -> V_403 ;
V_12 -> V_430 = F_365 ( V_3 ) ;
if ( ! V_12 -> V_430 )
goto V_192;
return 0 ;
V_192:
F_354 ( V_12 ) ;
return V_191 ;
}
static struct V_3 * F_366 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
V_29 = F_367 ( V_431 , V_158 ) ;
if ( ! V_29 )
return NULL ;
return & V_29 -> V_74 ;
}
static void F_368 ( struct V_432 * V_224 )
{
struct V_3 * V_3 = F_369 ( V_224 , struct V_3 , V_433 ) ;
if ( F_370 ( V_3 -> V_128 ) )
F_316 ( V_3 -> V_368 ) ;
F_371 ( V_431 , F_21 ( V_3 ) ) ;
}
static void F_372 ( struct V_3 * V_3 )
{
if ( F_123 ( V_3 -> V_128 ) )
F_373 ( & F_21 ( V_3 ) -> V_184 ) ;
F_374 ( & V_3 -> V_433 , F_368 ) ;
}
static void F_375 ( void * V_434 )
{
struct V_28 * V_29 = V_434 ;
F_376 ( & V_29 -> V_74 ) ;
}
static int F_377 ( void )
{
V_431 = F_378 ( L_26 ,
sizeof( struct V_28 ) ,
0 , V_435 | V_436 , F_375 ) ;
return 0 ;
}
static void F_379 ( void )
{
F_380 ( V_431 ) ;
}
static struct V_122 * F_381 ( struct V_437 * V_438 ,
int V_14 , const char * V_439 , void * V_405 )
{
return F_382 ( V_438 , V_14 , V_405 , F_356 ) ;
}
int T_16 F_383 ( void )
{
int error ;
if ( V_431 )
return 0 ;
error = F_377 () ;
if ( error )
goto V_440;
error = F_384 ( & V_441 ) ;
if ( error ) {
F_335 ( L_27 ) ;
goto V_442;
}
V_262 = F_385 ( & V_441 ) ;
if ( F_198 ( V_262 ) ) {
error = F_199 ( V_262 ) ;
F_335 ( L_28 ) ;
goto V_443;
}
#ifdef V_137
if ( F_344 () && V_218 < V_56 )
F_7 ( V_262 -> V_263 ) -> V_59 = V_218 ;
else
V_218 = 0 ;
#endif
return 0 ;
V_443:
F_386 ( & V_441 ) ;
V_442:
F_379 () ;
V_440:
V_262 = F_182 ( error ) ;
return error ;
}
static T_10 F_387 ( struct V_444 * V_445 ,
struct V_446 * V_127 , char * V_331 )
{
int V_447 [] = {
V_53 ,
V_54 ,
V_55 ,
V_52 ,
V_56 ,
V_57 ,
} ;
int V_86 , V_448 ;
for ( V_86 = 0 , V_448 = 0 ; V_86 < F_388 ( V_447 ) ; V_86 ++ ) {
const char * V_449 = V_218 == V_447 [ V_86 ] ? L_29 : L_30 ;
V_448 += sprintf ( V_331 + V_448 , V_449 ,
F_39 ( V_447 [ V_86 ] ) ) ;
}
V_331 [ V_448 - 1 ] = '\n' ;
return V_448 ;
}
static T_10 F_389 ( struct V_444 * V_445 ,
struct V_446 * V_127 , const char * V_331 , T_11 V_448 )
{
char V_450 [ 16 ] ;
int V_59 ;
if ( V_448 + 1 > sizeof( V_450 ) )
return - V_58 ;
memcpy ( V_450 , V_331 , V_448 ) ;
V_450 [ V_448 ] = '\0' ;
if ( V_448 && V_450 [ V_448 - 1 ] == '\n' )
V_450 [ V_448 - 1 ] = '\0' ;
V_59 = F_38 ( V_450 ) ;
if ( V_59 == - V_58 )
return - V_58 ;
if ( ! F_344 () &&
V_59 != V_52 && V_59 != V_56 )
return - V_58 ;
V_218 = V_59 ;
if ( V_218 < V_56 )
F_7 ( V_262 -> V_263 ) -> V_59 = V_218 ;
return V_448 ;
}
bool F_390 ( struct V_100 * V_101 )
{
struct V_3 * V_3 = F_94 ( V_101 -> V_102 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
T_2 V_75 ;
T_1 V_220 ;
if ( V_218 == V_57 )
return true ;
if ( V_218 == V_56 )
return false ;
switch ( V_23 -> V_59 ) {
case V_52 :
return false ;
case V_53 :
return true ;
case V_54 :
V_220 = F_47 ( V_101 -> V_103 , V_87 ) ;
V_75 = F_47 ( F_193 ( V_3 ) , V_22 ) ;
if ( V_75 >= V_76 &&
V_75 >> V_79 >= V_220 )
return true ;
case V_55 :
return ( V_101 -> V_242 & V_243 ) ;
default:
F_30 ( 1 ) ;
return false ;
}
}
int T_16 F_383 ( void )
{
F_79 ( F_384 ( & V_441 ) != 0 ) ;
V_262 = F_385 ( & V_441 ) ;
F_79 ( F_198 ( V_262 ) ) ;
return 0 ;
}
int F_144 ( T_3 V_50 , struct V_5 * V_5 )
{
return 0 ;
}
int F_221 ( struct V_247 * V_247 , int V_39 , struct V_264 * V_265 )
{
return 0 ;
}
void F_96 ( struct V_40 * V_41 )
{
}
unsigned long F_216 ( struct V_247 * V_247 ,
unsigned long V_251 , unsigned long V_249 ,
unsigned long V_232 , unsigned long V_14 )
{
return V_17 -> V_18 -> V_257 ( V_247 , V_251 , V_249 , V_232 , V_14 ) ;
}
void F_117 ( struct V_3 * V_3 , T_2 V_110 , T_2 V_111 )
{
F_391 ( V_3 -> V_9 , V_110 , V_111 ) ;
}
static struct V_247 * F_392 ( const char * V_378 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_451 )
{
struct V_247 * V_452 ;
struct V_3 * V_3 ;
struct V_453 V_453 ;
struct V_11 * V_12 ;
struct V_454 V_153 ;
if ( F_198 ( V_262 ) )
return F_393 ( V_262 ) ;
if ( V_15 < 0 || V_15 > V_205 )
return F_182 ( - V_58 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_182 ( - V_151 ) ;
V_452 = F_182 ( - V_151 ) ;
V_153 . V_378 = V_378 ;
V_153 . V_249 = strlen ( V_378 ) ;
V_153 . V_455 = 0 ;
V_12 = V_262 -> V_263 ;
V_453 . V_121 = F_394 ( V_262 ) ;
V_453 . V_122 = F_395 ( V_12 , & V_153 ) ;
if ( ! V_453 . V_122 )
goto V_456;
F_396 ( V_453 . V_122 , & V_457 ) ;
V_452 = F_182 ( - V_27 ) ;
V_3 = F_229 ( V_12 , NULL , V_278 | V_366 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_456;
V_3 -> V_451 |= V_451 ;
F_285 ( V_453 . V_122 , V_3 ) ;
V_3 -> V_75 = V_15 ;
F_397 ( V_3 ) ;
V_452 = F_182 ( F_398 ( V_3 , V_15 ) ) ;
if ( F_198 ( V_452 ) )
goto V_458;
V_452 = F_399 ( & V_453 , V_314 | V_459 ,
& V_261 ) ;
if ( F_198 ( V_452 ) )
goto V_458;
return V_452 ;
V_456:
F_11 ( V_14 , V_15 ) ;
V_458:
F_400 ( & V_453 ) ;
return V_452 ;
}
struct V_247 * F_401 ( const char * V_378 , T_2 V_15 , unsigned long V_14 )
{
return F_392 ( V_378 , V_15 , V_14 , V_460 ) ;
}
struct V_247 * F_402 ( const char * V_378 , T_2 V_15 , unsigned long V_14 )
{
return F_392 ( V_378 , V_15 , V_14 , 0 ) ;
}
int F_403 ( struct V_100 * V_101 )
{
struct V_247 * V_247 ;
T_2 V_15 = V_101 -> V_104 - V_101 -> V_105 ;
V_247 = F_392 ( L_31 , V_15 , V_101 -> V_242 , V_460 ) ;
if ( F_198 ( V_247 ) )
return F_199 ( V_247 ) ;
if ( V_101 -> V_102 )
F_404 ( V_101 -> V_102 ) ;
V_101 -> V_102 = V_247 ;
V_101 -> V_182 = & V_269 ;
if ( F_126 ( V_137 ) &&
( ( V_101 -> V_105 + ~ V_78 ) & V_78 ) <
( V_101 -> V_104 & V_78 ) ) {
F_228 ( V_101 , V_101 -> V_242 ) ;
}
return 0 ;
}
struct V_5 * F_405 ( struct V_40 * V_41 ,
T_1 V_4 , T_5 V_148 )
{
#ifdef F_406
struct V_3 * V_3 = V_41 -> V_161 ;
struct V_5 * V_5 ;
int error ;
F_79 ( V_41 -> V_139 != & V_140 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_209 ,
V_148 , NULL , NULL ) ;
if ( error )
V_5 = F_182 ( error ) ;
else
F_52 ( V_5 ) ;
return V_5 ;
#else
return F_407 ( V_41 , V_4 , V_148 ) ;
#endif
}
