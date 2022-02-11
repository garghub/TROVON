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
F_6 ( V_3 -> V_9 ) , NULL , NULL , NULL ) ;
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
static inline bool F_16 ( struct V_3 * V_3 , long V_21 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
if ( F_14 ( V_24 -> V_14 , V_21 ) )
return false ;
if ( V_25 -> V_27 ) {
if ( F_18 ( & V_25 -> V_28 ,
V_25 -> V_27 - V_21 ) > 0 )
goto V_29;
F_19 ( & V_25 -> V_28 , V_21 ) ;
}
return true ;
V_29:
F_15 ( V_24 -> V_14 , V_21 ) ;
return false ;
}
static inline void F_20 ( struct V_3 * V_3 , long V_21 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
if ( V_25 -> V_27 )
F_21 ( & V_25 -> V_28 , V_21 ) ;
F_15 ( V_24 -> V_14 , V_21 ) ;
}
bool F_22 ( struct V_30 * V_31 )
{
return V_31 -> V_32 == & V_33 ;
}
static int F_23 ( struct V_11 * V_12 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
if ( V_25 -> V_34 ) {
F_24 ( & V_25 -> V_35 ) ;
if ( ! V_25 -> V_36 ) {
F_25 ( & V_25 -> V_35 ) ;
return - V_37 ;
}
V_25 -> V_36 -- ;
F_25 ( & V_25 -> V_35 ) ;
}
return 0 ;
}
static void F_26 ( struct V_11 * V_12 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
if ( V_25 -> V_34 ) {
F_24 ( & V_25 -> V_35 ) ;
V_25 -> V_36 ++ ;
F_25 ( & V_25 -> V_35 ) ;
}
}
static void F_27 ( struct V_3 * V_3 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
long V_38 ;
V_38 = V_24 -> V_39 - V_24 -> V_40 - V_3 -> V_9 -> V_41 ;
if ( V_38 > 0 ) {
V_24 -> V_39 -= V_38 ;
V_3 -> V_42 -= V_38 * V_43 ;
F_20 ( V_3 , V_38 ) ;
}
}
bool F_28 ( struct V_3 * V_3 , long V_21 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
unsigned long V_14 ;
if ( ! F_16 ( V_3 , V_21 ) )
return false ;
F_29 ( & V_24 -> V_44 , V_14 ) ;
V_24 -> V_39 += V_21 ;
V_3 -> V_42 += V_21 * V_43 ;
F_27 ( V_3 ) ;
F_30 ( & V_24 -> V_44 , V_14 ) ;
V_3 -> V_9 -> V_41 += V_21 ;
return true ;
}
void F_31 ( struct V_3 * V_3 , long V_21 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
unsigned long V_14 ;
F_29 ( & V_24 -> V_44 , V_14 ) ;
V_24 -> V_39 -= V_21 ;
V_3 -> V_42 -= V_21 * V_43 ;
F_27 ( V_3 ) ;
F_30 ( & V_24 -> V_44 , V_14 ) ;
F_20 ( V_3 , V_21 ) ;
}
static int F_32 ( struct V_45 * V_46 ,
T_1 V_4 , void * V_47 , void * V_48 )
{
struct V_49 * V_50 ;
void * * V_51 ;
void * V_52 ;
F_33 ( ! V_47 ) ;
F_33 ( ! V_48 ) ;
V_52 = F_34 ( & V_46 -> V_53 , V_4 , & V_50 , & V_51 ) ;
if ( ! V_52 )
return - V_54 ;
if ( V_52 != V_47 )
return - V_54 ;
F_35 ( & V_46 -> V_53 , V_50 , V_51 ,
V_48 , NULL , NULL ) ;
return 0 ;
}
static bool F_36 ( struct V_45 * V_46 ,
T_1 V_4 , T_3 V_55 )
{
void * V_52 ;
F_37 () ;
V_52 = F_38 ( & V_46 -> V_53 , V_4 ) ;
F_39 () ;
return V_52 == F_40 ( V_55 ) ;
}
static int F_41 ( const char * V_56 )
{
if ( ! strcmp ( V_56 , L_1 ) )
return V_57 ;
if ( ! strcmp ( V_56 , L_2 ) )
return V_58 ;
if ( ! strcmp ( V_56 , L_3 ) )
return V_59 ;
if ( ! strcmp ( V_56 , L_4 ) )
return V_60 ;
if ( ! strcmp ( V_56 , L_5 ) )
return V_61 ;
if ( ! strcmp ( V_56 , L_6 ) )
return V_62 ;
return - V_63 ;
}
static const char * F_42 ( int V_64 )
{
switch ( V_64 ) {
case V_57 :
return L_1 ;
case V_58 :
return L_2 ;
case V_59 :
return L_3 ;
case V_60 :
return L_4 ;
case V_61 :
return L_5 ;
case V_62 :
return L_6 ;
default:
F_33 ( 1 ) ;
return L_7 ;
}
}
static unsigned long F_43 ( struct V_10 * V_25 ,
struct V_65 * V_66 , unsigned long V_67 )
{
F_44 ( V_68 ) , * V_69 , * V_70 ;
F_44 ( V_71 ) ;
struct V_3 * V_3 ;
struct V_23 * V_24 ;
struct V_5 * V_5 ;
unsigned long V_72 = V_66 ? V_66 -> V_73 : 128 ;
int V_74 = 0 , V_75 = 0 ;
if ( F_45 ( & V_25 -> V_76 ) )
return V_77 ;
F_24 ( & V_25 -> V_78 ) ;
F_46 (pos, next, &sbinfo->shrinklist) {
V_24 = F_47 ( V_69 , struct V_23 , V_76 ) ;
V_3 = F_48 ( & V_24 -> V_79 ) ;
if ( ! V_3 ) {
F_49 ( & V_24 -> V_76 ) ;
V_74 ++ ;
goto V_70;
}
if ( F_50 ( V_3 -> V_80 , V_22 ) ==
F_50 ( V_3 -> V_80 , V_81 ) ) {
F_51 ( & V_24 -> V_76 , & V_71 ) ;
V_74 ++ ;
goto V_70;
}
F_51 ( & V_24 -> V_76 , & V_68 ) ;
V_70:
if ( ! -- V_72 )
break;
}
F_25 ( & V_25 -> V_78 ) ;
F_46 (pos, next, &to_remove) {
V_24 = F_47 ( V_69 , struct V_23 , V_76 ) ;
V_3 = & V_24 -> V_79 ;
F_49 ( & V_24 -> V_76 ) ;
F_52 ( V_3 ) ;
}
F_46 (pos, next, &list) {
int V_82 ;
V_24 = F_47 ( V_69 , struct V_23 , V_76 ) ;
V_3 = & V_24 -> V_79 ;
if ( V_67 && V_75 >= V_67 ) {
F_52 ( V_3 ) ;
continue;
}
V_5 = F_53 ( V_3 -> V_9 ,
( V_3 -> V_80 & V_83 ) >> V_84 ) ;
if ( ! V_5 )
goto V_85;
if ( ! F_54 ( V_5 ) ) {
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
goto V_85;
}
V_82 = F_57 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
if ( V_82 ) {
F_52 ( V_3 ) ;
continue;
}
V_75 ++ ;
V_85:
F_49 ( & V_24 -> V_76 ) ;
V_74 ++ ;
F_52 ( V_3 ) ;
}
F_24 ( & V_25 -> V_78 ) ;
F_58 ( & V_68 , & V_25 -> V_76 ) ;
V_25 -> V_86 -= V_74 ;
F_25 ( & V_25 -> V_78 ) ;
return V_75 ;
}
static long F_59 ( struct V_11 * V_12 ,
struct V_65 * V_66 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
if ( ! F_60 ( V_25 -> V_86 ) )
return V_77 ;
return F_43 ( V_25 , V_66 , 0 ) ;
}
static long F_61 ( struct V_11 * V_12 ,
struct V_65 * V_66 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
return F_60 ( V_25 -> V_86 ) ;
}
static unsigned long F_43 ( struct V_10 * V_25 ,
struct V_65 * V_66 , unsigned long V_67 )
{
return 0 ;
}
static int F_62 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_1 V_4 , void * V_47 )
{
int error , V_87 = F_63 ( V_5 ) ;
F_64 ( F_65 ( V_5 ) , V_5 ) ;
F_64 ( V_4 != F_66 ( V_4 , V_87 ) , V_5 ) ;
F_64 ( ! F_67 ( V_5 ) , V_5 ) ;
F_64 ( ! F_68 ( V_5 ) , V_5 ) ;
F_33 ( V_47 && F_54 ( V_5 ) ) ;
F_69 ( V_5 , V_87 ) ;
V_5 -> V_46 = V_46 ;
V_5 -> V_4 = V_4 ;
F_70 ( & V_46 -> V_88 ) ;
if ( F_54 ( V_5 ) ) {
void T_4 * * V_89 ;
T_1 V_90 ;
int V_91 ;
error = 0 ;
if ( F_71 ( & V_46 -> V_53 ,
& V_89 , & V_90 , V_4 , 1 ) &&
V_90 < V_4 + V_92 ) {
error = - V_93 ;
}
if ( ! error ) {
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
error = F_72 ( & V_46 -> V_53 ,
V_4 + V_91 , V_5 + V_91 ) ;
F_33 ( error ) ;
}
F_73 ( V_94 ) ;
}
} else if ( ! V_47 ) {
error = F_72 ( & V_46 -> V_53 , V_4 , V_5 ) ;
} else {
error = F_32 ( V_46 , V_4 , V_47 ,
V_5 ) ;
}
if ( ! error ) {
V_46 -> V_41 += V_87 ;
if ( F_54 ( V_5 ) )
F_74 ( V_5 , V_95 ) ;
F_75 ( F_76 ( V_5 ) , V_96 , V_87 ) ;
F_75 ( F_76 ( V_5 ) , V_97 , V_87 ) ;
F_77 ( & V_46 -> V_88 ) ;
} else {
V_5 -> V_46 = NULL ;
F_77 ( & V_46 -> V_88 ) ;
F_78 ( V_5 , V_87 ) ;
}
return error ;
}
static void F_79 ( struct V_5 * V_5 , void * V_98 )
{
struct V_45 * V_46 = V_5 -> V_46 ;
int error ;
F_64 ( F_80 ( V_5 ) , V_5 ) ;
F_70 ( & V_46 -> V_88 ) ;
error = F_32 ( V_46 , V_5 -> V_4 , V_5 , V_98 ) ;
V_5 -> V_46 = NULL ;
V_46 -> V_41 -- ;
F_81 ( V_5 , V_96 ) ;
F_81 ( V_5 , V_97 ) ;
F_77 ( & V_46 -> V_88 ) ;
F_56 ( V_5 ) ;
F_82 ( error ) ;
}
static int F_83 ( struct V_45 * V_46 ,
T_1 V_4 , void * V_98 )
{
void * V_99 ;
F_70 ( & V_46 -> V_88 ) ;
V_99 = F_84 ( & V_46 -> V_53 , V_4 , V_98 ) ;
F_77 ( & V_46 -> V_88 ) ;
if ( V_99 != V_98 )
return - V_54 ;
F_85 ( F_86 ( V_98 ) ) ;
return 0 ;
}
unsigned long F_87 ( struct V_45 * V_46 ,
T_1 V_100 , T_1 V_101 )
{
struct V_102 V_103 ;
void * * V_104 ;
struct V_5 * V_5 ;
unsigned long V_40 = 0 ;
F_37 () ;
F_88 (slot, &mapping->page_tree, &iter, start) {
if ( V_103 . V_4 >= V_101 )
break;
V_5 = F_89 ( V_104 ) ;
if ( F_90 ( V_5 ) ) {
V_104 = F_91 ( & V_103 ) ;
continue;
}
if ( F_92 ( V_5 ) )
V_40 ++ ;
if ( F_93 () ) {
V_104 = F_94 ( V_104 , & V_103 ) ;
F_95 () ;
}
}
F_39 () ;
return V_40 << V_84 ;
}
unsigned long F_96 ( struct V_30 * V_31 )
{
struct V_3 * V_3 = F_97 ( V_31 -> V_105 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_45 * V_46 = V_3 -> V_9 ;
unsigned long V_40 ;
V_40 = F_60 ( V_24 -> V_40 ) ;
if ( ! V_40 )
return 0 ;
if ( ! V_31 -> V_106 && V_31 -> V_107 - V_31 -> V_108 >= V_3 -> V_80 )
return V_40 << V_84 ;
return F_87 ( V_46 ,
F_98 ( V_31 , V_31 -> V_108 ) ,
F_98 ( V_31 , V_31 -> V_107 ) ) ;
}
void F_99 ( struct V_45 * V_46 )
{
struct V_109 V_110 ;
T_1 V_111 [ V_112 ] ;
T_1 V_4 = 0 ;
F_100 ( & V_110 , 0 ) ;
while ( ! F_101 ( V_46 ) ) {
V_110 . V_87 = F_102 ( V_46 , V_4 ,
V_112 , V_110 . V_21 , V_111 ) ;
if ( ! V_110 . V_87 )
break;
V_4 = V_111 [ V_110 . V_87 - 1 ] + 1 ;
F_103 ( & V_110 ) ;
F_104 ( V_110 . V_21 , V_110 . V_87 ) ;
F_105 ( & V_110 ) ;
F_106 () ;
}
}
static void F_107 ( struct V_3 * V_3 , T_2 V_113 , T_2 V_114 ,
bool V_115 )
{
struct V_45 * V_46 = V_3 -> V_9 ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
T_1 V_100 = ( V_113 + V_22 - 1 ) >> V_84 ;
T_1 V_101 = ( V_114 + 1 ) >> V_84 ;
unsigned int V_116 = V_113 & ( V_22 - 1 ) ;
unsigned int V_117 = ( V_114 + 1 ) & ( V_22 - 1 ) ;
struct V_109 V_110 ;
T_1 V_111 [ V_112 ] ;
long V_118 = 0 ;
T_1 V_4 ;
int V_91 ;
if ( V_114 == - 1 )
V_101 = - 1 ;
F_100 ( & V_110 , 0 ) ;
V_4 = V_100 ;
while ( V_4 < V_101 ) {
V_110 . V_87 = F_102 ( V_46 , V_4 ,
F_3 ( V_101 - V_4 , ( T_1 ) V_112 ) ,
V_110 . V_21 , V_111 ) ;
if ( ! V_110 . V_87 )
break;
for ( V_91 = 0 ; V_91 < F_108 ( & V_110 ) ; V_91 ++ ) {
struct V_5 * V_5 = V_110 . V_21 [ V_91 ] ;
V_4 = V_111 [ V_91 ] ;
if ( V_4 >= V_101 )
break;
if ( F_92 ( V_5 ) ) {
if ( V_115 )
continue;
V_118 += ! F_83 ( V_46 ,
V_4 , V_5 ) ;
continue;
}
F_64 ( F_109 ( V_5 ) != V_4 , V_5 ) ;
if ( ! F_110 ( V_5 ) )
continue;
if ( F_111 ( V_5 ) ) {
F_112 ( V_5 ) ;
F_55 ( V_5 ) ;
continue;
} else if ( F_54 ( V_5 ) ) {
if ( V_4 == F_66 ( V_101 , V_92 ) ) {
F_112 ( V_5 ) ;
F_55 ( V_5 ) ;
continue;
}
V_4 += V_92 - 1 ;
V_91 += V_92 - 1 ;
}
if ( ! V_115 || ! F_113 ( V_5 ) ) {
F_64 ( F_65 ( V_5 ) , V_5 ) ;
if ( F_114 ( V_5 ) == V_46 ) {
F_64 ( F_115 ( V_5 ) , V_5 ) ;
F_116 ( V_46 , V_5 ) ;
}
}
F_55 ( V_5 ) ;
}
F_103 ( & V_110 ) ;
F_105 ( & V_110 ) ;
F_106 () ;
V_4 ++ ;
}
if ( V_116 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_100 - 1 , & V_5 , V_119 ) ;
if ( V_5 ) {
unsigned int V_120 = V_22 ;
if ( V_100 > V_101 ) {
V_120 = V_117 ;
V_117 = 0 ;
}
F_117 ( V_5 , V_116 , V_120 ) ;
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
}
}
if ( V_117 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_101 , & V_5 , V_119 ) ;
if ( V_5 ) {
F_117 ( V_5 , 0 , V_117 ) ;
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
}
}
if ( V_100 >= V_101 )
return;
V_4 = V_100 ;
while ( V_4 < V_101 ) {
F_106 () ;
V_110 . V_87 = F_102 ( V_46 , V_4 ,
F_3 ( V_101 - V_4 , ( T_1 ) V_112 ) ,
V_110 . V_21 , V_111 ) ;
if ( ! V_110 . V_87 ) {
if ( V_4 == V_100 || V_101 != - 1 )
break;
V_4 = V_100 ;
continue;
}
for ( V_91 = 0 ; V_91 < F_108 ( & V_110 ) ; V_91 ++ ) {
struct V_5 * V_5 = V_110 . V_21 [ V_91 ] ;
V_4 = V_111 [ V_91 ] ;
if ( V_4 >= V_101 )
break;
if ( F_92 ( V_5 ) ) {
if ( V_115 )
continue;
if ( F_83 ( V_46 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_118 ++ ;
continue;
}
F_119 ( V_5 ) ;
if ( F_111 ( V_5 ) ) {
F_112 ( V_5 ) ;
F_55 ( V_5 ) ;
if ( V_4 != F_66 ( V_101 , V_92 ) )
V_100 ++ ;
continue;
} else if ( F_54 ( V_5 ) ) {
if ( V_4 == F_66 ( V_101 , V_92 ) ) {
F_112 ( V_5 ) ;
F_55 ( V_5 ) ;
continue;
}
V_4 += V_92 - 1 ;
V_91 += V_92 - 1 ;
}
if ( ! V_115 || ! F_113 ( V_5 ) ) {
F_64 ( F_65 ( V_5 ) , V_5 ) ;
if ( F_114 ( V_5 ) == V_46 ) {
F_64 ( F_115 ( V_5 ) , V_5 ) ;
F_116 ( V_46 , V_5 ) ;
} else {
F_55 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_55 ( V_5 ) ;
}
F_103 ( & V_110 ) ;
F_105 ( & V_110 ) ;
V_4 ++ ;
}
F_70 ( & V_24 -> V_44 ) ;
V_24 -> V_40 -= V_118 ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
}
void F_120 ( struct V_3 * V_3 , T_2 V_113 , T_2 V_114 )
{
F_107 ( V_3 , V_113 , V_114 , false ) ;
V_3 -> V_121 = V_3 -> V_122 = F_121 ( V_3 ) ;
}
static int F_122 ( const struct V_123 * V_123 , struct V_124 * V_125 ,
T_5 V_126 , unsigned int V_127 )
{
struct V_3 * V_3 = V_123 -> V_128 -> V_129 ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
if ( V_24 -> V_39 - V_24 -> V_40 != V_3 -> V_9 -> V_41 ) {
F_70 ( & V_24 -> V_44 ) ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
}
F_123 ( V_3 , V_125 ) ;
return 0 ;
}
static int F_124 ( struct V_128 * V_128 , struct V_130 * V_131 )
{
struct V_3 * V_3 = V_129 ( V_128 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
int error ;
error = F_125 ( V_128 , V_131 ) ;
if ( error )
return error ;
if ( F_126 ( V_3 -> V_132 ) && ( V_131 -> V_133 & V_134 ) ) {
T_2 V_19 = V_3 -> V_80 ;
T_2 V_20 = V_131 -> V_135 ;
if ( ( V_20 < V_19 && ( V_24 -> V_136 & V_137 ) ) ||
( V_20 > V_19 && ( V_24 -> V_136 & V_138 ) ) )
return - V_139 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_17 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_127 ( V_3 , V_20 ) ;
V_3 -> V_121 = V_3 -> V_122 = F_121 ( V_3 ) ;
}
if ( V_20 <= V_19 ) {
T_2 V_140 = F_50 ( V_20 , V_22 ) ;
if ( V_19 > V_140 )
F_128 ( V_3 -> V_9 ,
V_140 , 0 , 1 ) ;
if ( V_24 -> V_39 )
F_120 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_140 )
F_128 ( V_3 -> V_9 ,
V_140 , 0 , 1 ) ;
if ( F_129 ( V_141 ) ) {
F_24 ( & V_25 -> V_78 ) ;
if ( F_130 ( & V_24 -> V_76 ) ) {
F_131 ( & V_24 -> V_76 ,
& V_25 -> V_76 ) ;
V_25 -> V_86 ++ ;
}
F_25 ( & V_25 -> V_78 ) ;
}
}
}
F_132 ( V_3 , V_131 ) ;
if ( V_131 -> V_133 & V_142 )
error = F_133 ( V_3 , V_3 -> V_132 ) ;
return error ;
}
static void F_134 ( struct V_3 * V_3 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
if ( V_3 -> V_9 -> V_143 == & V_144 ) {
F_11 ( V_24 -> V_14 , V_3 -> V_80 ) ;
V_3 -> V_80 = 0 ;
F_120 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_45 ( & V_24 -> V_76 ) ) {
F_24 ( & V_25 -> V_78 ) ;
if ( ! F_45 ( & V_24 -> V_76 ) ) {
F_49 ( & V_24 -> V_76 ) ;
V_25 -> V_86 -- ;
}
F_25 ( & V_25 -> V_78 ) ;
}
if ( ! F_45 ( & V_24 -> V_145 ) ) {
F_135 ( & V_146 ) ;
F_49 ( & V_24 -> V_145 ) ;
F_136 ( & V_146 ) ;
}
}
F_137 ( & V_24 -> V_147 ) ;
F_138 ( V_3 -> V_42 ) ;
F_26 ( V_3 -> V_26 ) ;
F_139 ( V_3 ) ;
}
static unsigned long F_140 ( struct V_148 * V_149 , void * V_52 )
{
struct V_102 V_103 ;
void * * V_104 ;
unsigned long V_150 = - 1 ;
unsigned int V_151 = 0 ;
F_37 () ;
F_88 (slot, root, &iter, 0 ) {
if ( * V_104 == V_52 ) {
V_150 = V_103 . V_4 ;
break;
}
V_151 ++ ;
if ( ( V_151 % 4096 ) != 0 )
continue;
V_104 = F_94 ( V_104 , & V_103 ) ;
F_95 () ;
}
F_39 () ;
return V_150 ;
}
static int F_141 ( struct V_23 * V_24 ,
T_3 V_55 , struct V_5 * * V_6 )
{
struct V_45 * V_46 = V_24 -> V_79 . V_9 ;
void * V_98 ;
T_1 V_4 ;
T_6 V_152 ;
int error = 0 ;
V_98 = F_40 ( V_55 ) ;
V_4 = F_140 ( & V_46 -> V_53 , V_98 ) ;
if ( V_4 == - 1 )
return - V_153 ;
if ( V_154 . V_70 != & V_24 -> V_145 )
F_142 ( & V_154 , & V_24 -> V_145 ) ;
V_152 = F_6 ( V_46 ) ;
if ( F_143 ( * V_6 , V_152 ) ) {
F_136 ( & V_146 ) ;
error = F_144 ( V_6 , V_152 , V_24 , V_4 ) ;
F_135 ( & V_146 ) ;
if ( ! F_145 ( * V_6 ) )
error = - V_54 ;
}
if ( ! error )
error = F_62 ( * V_6 , V_46 , V_4 ,
V_98 ) ;
if ( error != - V_155 ) {
F_146 ( * V_6 ) ;
F_118 ( * V_6 ) ;
if ( ! error ) {
F_70 ( & V_24 -> V_44 ) ;
V_24 -> V_40 -- ;
F_77 ( & V_24 -> V_44 ) ;
F_147 ( V_55 ) ;
}
}
return error ;
}
int F_148 ( T_3 V_55 , struct V_5 * V_5 )
{
struct V_156 * V_157 , * V_70 ;
struct V_23 * V_24 ;
struct V_158 * V_159 ;
int error = 0 ;
if ( F_149 ( ! F_150 ( V_5 ) || F_151 ( V_5 ) != V_55 . V_160 ) )
goto V_161;
error = F_152 ( V_5 , V_17 -> V_18 , V_162 , & V_159 ,
false ) ;
if ( error )
goto V_161;
error = - V_153 ;
F_135 ( & V_146 ) ;
F_46 (this, next, &shmem_swaplist) {
V_24 = F_47 ( V_157 , struct V_23 , V_145 ) ;
if ( V_24 -> V_40 )
error = F_141 ( V_24 , V_55 , & V_5 ) ;
else
F_49 ( & V_24 -> V_145 ) ;
F_106 () ;
if ( error != - V_153 )
break;
}
F_136 ( & V_146 ) ;
if ( error ) {
if ( error != - V_155 )
error = 0 ;
F_153 ( V_5 , V_159 , false ) ;
} else
F_154 ( V_5 , V_159 , true , false ) ;
V_161:
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
return error ;
}
static int F_155 ( struct V_5 * V_5 , struct V_163 * V_164 )
{
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_3 * V_3 ;
T_3 V_55 ;
T_1 V_4 ;
F_64 ( F_80 ( V_5 ) , V_5 ) ;
F_82 ( ! F_67 ( V_5 ) ) ;
V_46 = V_5 -> V_46 ;
V_4 = V_5 -> V_4 ;
V_3 = V_46 -> V_165 ;
V_24 = F_17 ( V_3 ) ;
if ( V_24 -> V_14 & V_166 )
goto V_167;
if ( ! V_168 )
goto V_167;
if ( ! V_164 -> V_169 ) {
F_156 ( 1 ) ;
goto V_167;
}
if ( ! F_113 ( V_5 ) ) {
if ( V_3 -> V_170 ) {
struct V_171 * V_171 ;
F_24 ( & V_3 -> V_172 ) ;
V_171 = V_3 -> V_170 ;
if ( V_171 &&
! V_171 -> V_173 &&
V_4 >= V_171 -> V_100 &&
V_4 < V_171 -> V_70 )
V_171 -> V_174 ++ ;
else
V_171 = NULL ;
F_25 ( & V_3 -> V_172 ) ;
if ( V_171 )
goto V_167;
}
F_112 ( V_5 ) ;
F_157 ( V_5 ) ;
F_158 ( V_5 ) ;
}
V_55 = F_159 ( V_5 ) ;
if ( ! V_55 . V_160 )
goto V_167;
if ( F_160 ( V_5 , V_55 ) )
goto V_175;
F_135 ( & V_146 ) ;
if ( F_45 ( & V_24 -> V_145 ) )
F_131 ( & V_24 -> V_145 , & V_154 ) ;
if ( F_161 ( V_5 , V_55 , V_176 ) == 0 ) {
F_70 ( & V_24 -> V_44 ) ;
F_27 ( V_3 ) ;
V_24 -> V_40 ++ ;
F_77 ( & V_24 -> V_44 ) ;
F_162 ( V_55 ) ;
F_79 ( V_5 , F_40 ( V_55 ) ) ;
F_136 ( & V_146 ) ;
F_82 ( F_163 ( V_5 ) ) ;
F_164 ( V_5 , V_164 ) ;
return 0 ;
}
F_136 ( & V_146 ) ;
V_175:
F_165 ( V_5 , V_55 ) ;
V_167:
F_118 ( V_5 ) ;
if ( V_164 -> V_169 )
return V_177 ;
F_55 ( V_5 ) ;
return 0 ;
}
static void F_166 ( struct V_178 * V_179 , struct V_180 * V_181 )
{
char V_182 [ 64 ] ;
if ( ! V_181 || V_181 -> V_183 == V_184 )
return;
F_167 ( V_182 , sizeof( V_182 ) , V_181 ) ;
F_168 ( V_179 , L_8 , V_182 ) ;
}
static struct V_180 * F_169 ( struct V_10 * V_25 )
{
struct V_180 * V_181 = NULL ;
if ( V_25 -> V_181 ) {
F_24 ( & V_25 -> V_35 ) ;
V_181 = V_25 -> V_181 ;
F_170 ( V_181 ) ;
F_25 ( & V_25 -> V_35 ) ;
}
return V_181 ;
}
static inline void F_166 ( struct V_178 * V_179 , struct V_180 * V_181 )
{
}
static inline struct V_180 * F_169 ( struct V_10 * V_25 )
{
return NULL ;
}
static void F_171 ( struct V_30 * V_31 ,
struct V_23 * V_24 , T_1 V_4 )
{
V_31 -> V_108 = 0 ;
V_31 -> V_106 = V_4 + V_24 -> V_79 . V_185 ;
V_31 -> V_32 = NULL ;
V_31 -> V_186 = F_172 ( & V_24 -> V_187 , V_4 ) ;
}
static void F_173 ( struct V_30 * V_31 )
{
F_174 ( V_31 -> V_186 ) ;
}
static struct V_5 * F_175 ( T_3 V_55 , T_6 V_152 ,
struct V_23 * V_24 , T_1 V_4 )
{
struct V_30 V_188 ;
struct V_5 * V_5 ;
F_171 ( & V_188 , V_24 , V_4 ) ;
V_5 = F_176 ( V_55 , V_152 , & V_188 , 0 ) ;
F_173 ( & V_188 ) ;
return V_5 ;
}
static struct V_5 * F_177 ( T_6 V_152 ,
struct V_23 * V_24 , T_1 V_4 )
{
struct V_30 V_188 ;
struct V_3 * V_3 = & V_24 -> V_79 ;
struct V_45 * V_46 = V_3 -> V_9 ;
T_1 V_90 , V_189 ;
void T_4 * * V_89 ;
struct V_5 * V_5 ;
if ( ! F_129 ( V_141 ) )
return NULL ;
V_189 = F_66 ( V_4 , V_92 ) ;
F_37 () ;
if ( F_71 ( & V_46 -> V_53 , & V_89 , & V_90 ,
V_189 , 1 ) && V_90 < V_189 + V_92 ) {
F_39 () ;
return NULL ;
}
F_39 () ;
F_171 ( & V_188 , V_24 , V_189 ) ;
V_5 = F_178 ( V_152 | V_190 | V_191 | V_192 ,
V_193 , & V_188 , 0 , F_179 () , true ) ;
F_173 ( & V_188 ) ;
if ( V_5 )
F_180 ( V_5 ) ;
return V_5 ;
}
static struct V_5 * F_181 ( T_6 V_152 ,
struct V_23 * V_24 , T_1 V_4 )
{
struct V_30 V_188 ;
struct V_5 * V_5 ;
F_171 ( & V_188 , V_24 , V_4 ) ;
V_5 = F_182 ( V_152 , & V_188 , 0 ) ;
F_173 ( & V_188 ) ;
return V_5 ;
}
static struct V_5 * F_183 ( T_6 V_152 ,
struct V_3 * V_3 ,
T_1 V_4 , bool V_64 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_5 * V_5 ;
int V_87 ;
int V_194 = - V_37 ;
if ( ! F_129 ( V_141 ) )
V_64 = false ;
V_87 = V_64 ? V_92 : 1 ;
if ( ! F_16 ( V_3 , V_87 ) )
goto V_195;
if ( V_64 )
V_5 = F_177 ( V_152 , V_24 , V_4 ) ;
else
V_5 = F_181 ( V_152 , V_24 , V_4 ) ;
if ( V_5 ) {
F_184 ( V_5 ) ;
F_185 ( V_5 ) ;
return V_5 ;
}
V_194 = - V_155 ;
F_20 ( V_3 , V_87 ) ;
V_195:
return F_186 ( V_194 ) ;
}
static bool F_143 ( struct V_5 * V_5 , T_6 V_152 )
{
return F_187 ( V_5 ) > F_188 ( V_152 ) ;
}
static int F_144 ( struct V_5 * * V_6 , T_6 V_152 ,
struct V_23 * V_24 , T_1 V_4 )
{
struct V_5 * V_196 , * V_197 ;
struct V_45 * V_198 ;
T_1 V_199 ;
int error ;
V_196 = * V_6 ;
V_199 = F_151 ( V_196 ) ;
V_198 = F_114 ( V_196 ) ;
V_152 &= ~ V_200 ;
V_197 = F_181 ( V_152 , V_24 , V_4 ) ;
if ( ! V_197 )
return - V_155 ;
F_189 ( V_197 ) ;
F_190 ( V_197 , V_196 ) ;
F_157 ( V_197 ) ;
F_184 ( V_197 ) ;
F_185 ( V_197 ) ;
F_158 ( V_197 ) ;
F_191 ( V_197 , V_199 ) ;
F_192 ( V_197 ) ;
F_70 ( & V_198 -> V_88 ) ;
error = F_32 ( V_198 , V_199 , V_196 ,
V_197 ) ;
if ( ! error ) {
F_74 ( V_197 , V_96 ) ;
F_81 ( V_196 , V_96 ) ;
}
F_77 ( & V_198 -> V_88 ) ;
if ( F_149 ( error ) ) {
V_196 = V_197 ;
} else {
F_193 ( V_196 , V_197 ) ;
F_194 ( V_197 ) ;
* V_6 = V_197 ;
}
F_195 ( V_196 ) ;
F_191 ( V_196 , 0 ) ;
F_55 ( V_196 ) ;
F_56 ( V_196 ) ;
F_56 ( V_196 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_6 V_152 ,
struct V_30 * V_31 , struct V_201 * V_202 , int * V_203 )
{
struct V_45 * V_46 = V_3 -> V_9 ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_10 * V_25 ;
struct V_204 * V_205 ;
struct V_158 * V_159 ;
struct V_5 * V_5 ;
T_3 V_55 ;
enum V_7 V_206 = V_8 ;
T_1 V_189 = V_4 ;
int error ;
int V_207 = 0 ;
int V_39 = 0 ;
if ( V_4 > ( V_208 >> V_84 ) )
return - V_209 ;
if ( V_8 == V_210 || V_8 == V_211 )
V_8 = V_212 ;
V_213:
V_55 . V_160 = 0 ;
V_5 = F_196 ( V_46 , V_4 ) ;
if ( F_92 ( V_5 ) ) {
V_55 = F_86 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_212 &&
( ( T_2 ) V_4 << V_84 ) >= F_197 ( V_3 ) ) {
error = - V_63 ;
goto V_214;
}
if ( V_5 && V_8 == V_215 )
F_198 ( V_5 ) ;
if ( V_5 && ! F_113 ( V_5 ) ) {
if ( V_8 != V_119 )
goto V_216;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_119 && ! V_55 . V_160 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_25 = F_7 ( V_3 -> V_26 ) ;
V_205 = V_31 ? V_31 -> V_217 : V_17 -> V_18 ;
if ( V_55 . V_160 ) {
V_5 = F_199 ( V_55 , NULL , 0 ) ;
if ( ! V_5 ) {
if ( V_203 ) {
* V_203 |= V_218 ;
F_73 ( V_219 ) ;
F_200 ( V_205 , V_219 ) ;
}
V_5 = F_175 ( V_55 , V_152 , V_24 , V_4 ) ;
if ( ! V_5 ) {
error = - V_155 ;
goto V_195;
}
}
F_119 ( V_5 ) ;
if ( ! F_150 ( V_5 ) || F_151 ( V_5 ) != V_55 . V_160 ||
! F_36 ( V_46 , V_4 , V_55 ) ) {
error = - V_93 ;
goto V_214;
}
if ( ! F_113 ( V_5 ) ) {
error = - V_220 ;
goto V_195;
}
F_201 ( V_5 ) ;
if ( F_143 ( V_5 , V_152 ) ) {
error = F_144 ( & V_5 , V_152 , V_24 , V_4 ) ;
if ( error )
goto V_195;
}
error = F_152 ( V_5 , V_205 , V_152 , & V_159 ,
false ) ;
if ( ! error ) {
error = F_62 ( V_5 , V_46 , V_4 ,
F_40 ( V_55 ) ) ;
if ( error ) {
F_153 ( V_5 , V_159 , false ) ;
F_146 ( V_5 ) ;
}
}
if ( error )
goto V_195;
F_154 ( V_5 , V_159 , true , false ) ;
F_70 ( & V_24 -> V_44 ) ;
V_24 -> V_40 -- ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
if ( V_8 == V_215 )
F_198 ( V_5 ) ;
F_146 ( V_5 ) ;
F_118 ( V_5 ) ;
F_147 ( V_55 ) ;
} else {
if ( V_31 && F_202 ( V_31 ) ) {
* V_203 = F_203 ( V_202 , V_221 ) ;
return 0 ;
}
if ( V_46 -> V_143 != & V_144 )
goto V_222;
if ( V_223 == V_61 || V_206 == V_210 )
goto V_222;
if ( V_223 == V_62 )
goto V_224;
switch ( V_25 -> V_64 ) {
T_2 V_80 ;
T_1 V_225 ;
case V_57 :
goto V_222;
case V_59 :
V_225 = F_50 ( V_4 , V_92 ) ;
V_80 = F_50 ( F_197 ( V_3 ) , V_22 ) ;
if ( V_80 >= V_81 &&
V_80 >> V_84 >= V_225 )
goto V_224;
case V_60 :
if ( V_206 == V_211 )
goto V_224;
goto V_222;
}
V_224:
V_5 = F_183 ( V_152 , V_3 , V_4 , true ) ;
if ( F_204 ( V_5 ) ) {
V_222: V_5 = F_183 ( V_152 , V_3 ,
V_4 , false ) ;
}
if ( F_204 ( V_5 ) ) {
int V_226 = 5 ;
error = F_205 ( V_5 ) ;
V_5 = NULL ;
if ( error != - V_37 )
goto V_195;
while ( V_226 -- ) {
int V_82 ;
V_82 = F_43 ( V_25 , NULL , 1 ) ;
if ( V_82 == V_77 )
break;
if ( V_82 )
goto V_222;
}
goto V_195;
}
if ( F_54 ( V_5 ) )
V_189 = F_66 ( V_4 , V_92 ) ;
else
V_189 = V_4 ;
if ( V_8 == V_215 )
F_206 ( V_5 ) ;
error = F_152 ( V_5 , V_205 , V_152 , & V_159 ,
F_54 ( V_5 ) ) ;
if ( error )
goto V_29;
error = F_207 ( V_152 & V_227 ,
F_208 ( V_5 ) ) ;
if ( ! error ) {
error = F_62 ( V_5 , V_46 , V_189 ,
NULL ) ;
F_209 () ;
}
if ( error ) {
F_153 ( V_5 , V_159 ,
F_54 ( V_5 ) ) ;
goto V_29;
}
F_154 ( V_5 , V_159 , false ,
F_54 ( V_5 ) ) ;
F_194 ( V_5 ) ;
F_70 ( & V_24 -> V_44 ) ;
V_24 -> V_39 += 1 << F_208 ( V_5 ) ;
V_3 -> V_42 += V_43 << F_208 ( V_5 ) ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
V_39 = true ;
if ( F_54 ( V_5 ) &&
F_210 ( F_197 ( V_3 ) , V_22 ) <
V_189 + V_92 - 1 ) {
F_24 ( & V_25 -> V_78 ) ;
if ( F_130 ( & V_24 -> V_76 ) ) {
F_131 ( & V_24 -> V_76 ,
& V_25 -> V_76 ) ;
V_25 -> V_86 ++ ;
}
F_25 ( & V_25 -> V_78 ) ;
}
if ( V_8 == V_228 )
V_8 = V_215 ;
V_216:
if ( V_8 != V_215 && ! F_113 ( V_5 ) ) {
struct V_5 * V_229 = F_211 ( V_5 ) ;
int V_91 ;
for ( V_91 = 0 ; V_91 < ( 1 << F_208 ( V_229 ) ) ; V_91 ++ ) {
F_112 ( V_229 + V_91 ) ;
F_157 ( V_229 + V_91 ) ;
}
F_158 ( V_229 ) ;
}
}
if ( V_8 <= V_212 &&
( ( T_2 ) V_4 << V_84 ) >= F_197 ( V_3 ) ) {
if ( V_39 ) {
F_212 ( V_5 ) ;
F_213 ( V_5 ) ;
F_70 ( & V_24 -> V_44 ) ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
}
error = - V_63 ;
goto V_214;
}
* V_6 = V_5 + V_4 - V_189 ;
return 0 ;
V_29:
F_20 ( V_3 , 1 << F_208 ( V_5 ) ) ;
if ( F_54 ( V_5 ) ) {
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
goto V_222;
}
V_195:
if ( V_55 . V_160 && ! F_36 ( V_46 , V_4 , V_55 ) )
error = - V_93 ;
V_214:
if ( V_5 ) {
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
}
if ( error == - V_37 && ! V_207 ++ ) {
F_70 ( & V_24 -> V_44 ) ;
F_27 ( V_3 ) ;
F_77 ( & V_24 -> V_44 ) ;
goto V_213;
}
if ( error == - V_93 )
goto V_213;
return error ;
}
static int F_214 ( T_7 * V_230 , unsigned V_183 , int V_231 , void * V_232 )
{
int V_82 = F_215 ( V_230 , V_183 , V_231 , V_232 ) ;
F_49 ( & V_230 -> V_233 ) ;
return V_82 ;
}
static int F_216 ( struct V_201 * V_202 )
{
struct V_30 * V_31 = V_202 -> V_31 ;
struct V_3 * V_3 = F_97 ( V_31 -> V_105 ) ;
T_6 V_152 = F_6 ( V_3 -> V_9 ) ;
enum V_7 V_8 ;
int error ;
int V_82 = V_234 ;
if ( F_149 ( V_3 -> V_170 ) ) {
struct V_171 * V_171 ;
F_24 ( & V_3 -> V_172 ) ;
V_171 = V_3 -> V_170 ;
if ( V_171 &&
V_171 -> V_173 &&
V_202 -> V_235 >= V_171 -> V_100 &&
V_202 -> V_235 < V_171 -> V_70 ) {
T_8 * V_236 ;
F_217 ( V_237 , F_214 ) ;
V_82 = V_238 ;
if ( ( V_202 -> V_14 & V_239 ) &&
! ( V_202 -> V_14 & V_240 ) ) {
F_218 ( & V_31 -> V_217 -> V_241 ) ;
V_82 = V_242 ;
}
V_236 = V_171 -> V_173 ;
F_219 ( V_236 , & V_237 ,
V_243 ) ;
F_25 ( & V_3 -> V_172 ) ;
F_220 () ;
F_24 ( & V_3 -> V_172 ) ;
F_221 ( V_236 , & V_237 ) ;
F_25 ( & V_3 -> V_172 ) ;
return V_82 ;
}
F_25 ( & V_3 -> V_172 ) ;
}
V_8 = V_212 ;
if ( ( V_31 -> V_244 & V_245 ) ||
F_222 ( V_246 , & V_31 -> V_217 -> V_14 ) )
V_8 = V_210 ;
else if ( V_31 -> V_244 & V_247 )
V_8 = V_211 ;
error = F_5 ( V_3 , V_202 -> V_235 , & V_202 -> V_5 , V_8 ,
V_152 , V_31 , V_202 , & V_82 ) ;
if ( error )
return ( ( error == - V_155 ) ? V_248 : V_249 ) ;
return V_82 ;
}
unsigned long F_223 ( struct V_250 * V_250 ,
unsigned long V_251 , unsigned long V_252 ,
unsigned long V_235 , unsigned long V_14 )
{
unsigned long ( * V_253 ) ( struct V_250 * ,
unsigned long , unsigned long , unsigned long , unsigned long ) ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_257 ;
unsigned long V_258 ;
if ( V_252 > V_259 )
return - V_155 ;
V_253 = V_17 -> V_18 -> V_260 ;
V_254 = V_253 ( V_250 , V_251 , V_252 , V_235 , V_14 ) ;
if ( ! F_129 ( V_141 ) )
return V_254 ;
if ( F_224 ( V_254 ) )
return V_254 ;
if ( V_254 & ~ V_261 )
return V_254 ;
if ( V_254 > V_259 - V_252 )
return V_254 ;
if ( V_223 == V_61 )
return V_254 ;
if ( V_252 < V_81 )
return V_254 ;
if ( V_14 & V_262 )
return V_254 ;
if ( V_251 )
return V_254 ;
if ( V_223 != V_62 ) {
struct V_11 * V_12 ;
if ( V_250 ) {
F_33 ( V_250 -> V_263 != & V_264 ) ;
V_12 = F_97 ( V_250 ) -> V_26 ;
} else {
if ( F_204 ( V_265 ) )
return V_254 ;
V_12 = V_265 -> V_266 ;
}
if ( F_7 ( V_12 ) -> V_64 == V_57 )
return V_254 ;
}
V_255 = ( V_235 << V_84 ) & ( V_81 - 1 ) ;
if ( V_255 && V_255 + V_252 < 2 * V_81 )
return V_254 ;
if ( ( V_254 & ( V_81 - 1 ) ) == V_255 )
return V_254 ;
V_256 = V_252 + V_81 - V_22 ;
if ( V_256 > V_259 )
return V_254 ;
if ( V_256 < V_252 )
return V_254 ;
V_257 = V_253 ( NULL , 0 , V_256 , 0 , V_14 ) ;
if ( F_224 ( V_257 ) )
return V_254 ;
if ( V_257 & ~ V_261 )
return V_254 ;
V_258 = V_257 & ( V_81 - 1 ) ;
V_257 += V_255 - V_258 ;
if ( V_258 > V_255 )
V_257 += V_81 ;
if ( V_257 > V_259 - V_252 )
return V_254 ;
return V_257 ;
}
static int F_225 ( struct V_30 * V_31 , struct V_180 * V_181 )
{
struct V_3 * V_3 = F_97 ( V_31 -> V_105 ) ;
return F_226 ( & F_17 ( V_3 ) -> V_187 , V_31 , V_181 ) ;
}
static struct V_180 * F_227 ( struct V_30 * V_31 ,
unsigned long V_254 )
{
struct V_3 * V_3 = F_97 ( V_31 -> V_105 ) ;
T_1 V_4 ;
V_4 = ( ( V_254 - V_31 -> V_108 ) >> V_84 ) + V_31 -> V_106 ;
return F_172 ( & F_17 ( V_3 ) -> V_187 , V_4 ) ;
}
int F_228 ( struct V_250 * V_250 , int V_44 , struct V_267 * V_268 )
{
struct V_3 * V_3 = F_97 ( V_250 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
int V_269 = - V_155 ;
F_70 ( & V_24 -> V_44 ) ;
if ( V_44 && ! ( V_24 -> V_14 & V_166 ) ) {
if ( ! F_229 ( V_3 -> V_80 , V_268 ) )
goto V_270;
V_24 -> V_14 |= V_166 ;
F_230 ( V_250 -> V_271 ) ;
}
if ( ! V_44 && ( V_24 -> V_14 & V_166 ) && V_268 ) {
F_231 ( V_3 -> V_80 , V_268 ) ;
V_24 -> V_14 &= ~ V_166 ;
F_232 ( V_250 -> V_271 ) ;
}
V_269 = 0 ;
V_270:
F_77 ( & V_24 -> V_44 ) ;
return V_269 ;
}
static int F_233 ( struct V_250 * V_250 , struct V_30 * V_31 )
{
F_234 ( V_250 ) ;
V_31 -> V_32 = & V_33 ;
if ( F_129 ( V_141 ) &&
( ( V_31 -> V_108 + ~ V_83 ) & V_83 ) <
( V_31 -> V_107 & V_83 ) ) {
F_235 ( V_31 , V_31 -> V_244 ) ;
}
return 0 ;
}
static struct V_3 * F_236 ( struct V_11 * V_12 , const struct V_3 * V_272 ,
T_9 V_183 , T_10 V_273 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_23 * V_24 ;
struct V_10 * V_25 = F_7 ( V_12 ) ;
if ( F_23 ( V_12 ) )
return NULL ;
V_3 = F_237 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_185 = F_238 () ;
F_239 ( V_3 , V_272 , V_183 ) ;
V_3 -> V_42 = 0 ;
V_3 -> V_274 = V_3 -> V_122 = V_3 -> V_121 = F_121 ( V_3 ) ;
V_3 -> V_275 = F_240 () ;
V_24 = F_17 ( V_3 ) ;
memset ( V_24 , 0 , ( char * ) V_3 - ( char * ) V_24 ) ;
F_241 ( & V_24 -> V_44 ) ;
V_24 -> V_136 = V_276 ;
V_24 -> V_14 = V_14 & V_16 ;
F_242 ( & V_24 -> V_76 ) ;
F_242 ( & V_24 -> V_145 ) ;
F_243 ( & V_24 -> V_147 ) ;
F_244 ( V_3 ) ;
switch ( V_183 & V_277 ) {
default:
V_3 -> V_278 = & V_279 ;
F_245 ( V_3 , V_183 , V_273 ) ;
break;
case V_280 :
V_3 -> V_9 -> V_143 = & V_144 ;
V_3 -> V_278 = & V_281 ;
V_3 -> V_282 = & V_264 ;
F_246 ( & V_24 -> V_187 ,
F_169 ( V_25 ) ) ;
break;
case V_283 :
F_247 ( V_3 ) ;
V_3 -> V_80 = 2 * V_284 ;
V_3 -> V_278 = & V_285 ;
V_3 -> V_282 = & V_286 ;
break;
case V_287 :
F_246 ( & V_24 -> V_187 , NULL ) ;
break;
}
} else
F_26 ( V_12 ) ;
return V_3 ;
}
bool F_248 ( struct V_45 * V_46 )
{
return V_46 -> V_143 == & V_144 ;
}
static int F_249 ( struct V_204 * V_288 ,
T_11 * V_289 ,
struct V_30 * V_290 ,
unsigned long V_291 ,
unsigned long V_292 ,
bool V_293 ,
struct V_5 * * V_6 )
{
struct V_3 * V_3 = F_97 ( V_290 -> V_105 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_45 * V_46 = V_3 -> V_9 ;
T_6 V_152 = F_6 ( V_46 ) ;
T_1 V_235 = F_98 ( V_290 , V_291 ) ;
struct V_158 * V_159 ;
T_12 * V_294 ;
void * V_295 ;
struct V_5 * V_5 ;
T_13 V_296 , * V_297 ;
int V_82 ;
V_82 = - V_155 ;
if ( ! F_16 ( V_3 , 1 ) )
goto V_161;
if ( ! * V_6 ) {
V_5 = F_181 ( V_152 , V_24 , V_235 ) ;
if ( ! V_5 )
goto V_298;
if ( ! V_293 ) {
V_295 = F_250 ( V_5 ) ;
V_82 = F_251 ( V_295 ,
( const void V_299 * ) V_292 ,
V_22 ) ;
F_252 ( V_295 ) ;
if ( F_149 ( V_82 ) ) {
* V_6 = V_5 ;
F_20 ( V_3 , 1 ) ;
return - V_300 ;
}
} else {
F_112 ( V_5 ) ;
}
} else {
V_5 = * V_6 ;
* V_6 = NULL ;
}
F_33 ( F_67 ( V_5 ) || F_68 ( V_5 ) ) ;
F_184 ( V_5 ) ;
F_185 ( V_5 ) ;
F_253 ( V_5 ) ;
V_82 = F_152 ( V_5 , V_288 , V_152 , & V_159 , false ) ;
if ( V_82 )
goto V_301;
V_82 = F_254 ( V_152 & V_227 ) ;
if ( ! V_82 ) {
V_82 = F_62 ( V_5 , V_46 , V_235 , NULL ) ;
F_209 () ;
}
if ( V_82 )
goto V_302;
F_154 ( V_5 , V_159 , false , false ) ;
V_296 = F_255 ( V_5 , V_290 -> V_303 ) ;
if ( V_290 -> V_244 & V_304 )
V_296 = F_256 ( F_257 ( V_296 ) ) ;
V_82 = - V_93 ;
V_297 = F_258 ( V_288 , V_289 , V_291 , & V_294 ) ;
if ( ! F_259 ( * V_297 ) )
goto V_305;
F_194 ( V_5 ) ;
F_24 ( & V_24 -> V_44 ) ;
V_24 -> V_39 ++ ;
V_3 -> V_42 += V_43 ;
F_27 ( V_3 ) ;
F_25 ( & V_24 -> V_44 ) ;
F_260 ( V_288 , F_261 ( V_5 ) ) ;
F_262 ( V_5 , false ) ;
F_263 ( V_288 , V_291 , V_297 , V_296 ) ;
F_264 ( V_290 , V_291 , V_297 ) ;
F_55 ( V_5 ) ;
F_265 ( V_297 , V_294 ) ;
V_82 = 0 ;
V_161:
return V_82 ;
V_305:
F_265 ( V_297 , V_294 ) ;
V_302:
F_153 ( V_5 , V_159 , false ) ;
V_301:
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
V_298:
F_20 ( V_3 , 1 ) ;
goto V_161;
}
int F_266 ( struct V_204 * V_288 ,
T_11 * V_289 ,
struct V_30 * V_290 ,
unsigned long V_291 ,
unsigned long V_292 ,
struct V_5 * * V_6 )
{
return F_249 ( V_288 , V_289 , V_290 ,
V_291 , V_292 , false , V_6 ) ;
}
int F_267 ( struct V_204 * V_288 ,
T_11 * V_289 ,
struct V_30 * V_290 ,
unsigned long V_291 )
{
struct V_5 * V_5 = NULL ;
return F_249 ( V_288 , V_289 , V_290 ,
V_291 , 0 , true , & V_5 ) ;
}
static int
F_268 ( struct V_250 * V_250 , struct V_45 * V_46 ,
T_2 V_69 , unsigned V_252 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_306 )
{
struct V_3 * V_3 = V_46 -> V_165 ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
T_1 V_4 = V_69 >> V_84 ;
if ( F_149 ( V_24 -> V_136 & ( V_307 | V_138 ) ) ) {
if ( V_24 -> V_136 & V_307 )
return - V_139 ;
if ( ( V_24 -> V_136 & V_138 ) && V_69 + V_252 > V_3 -> V_80 )
return - V_139 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_215 ) ;
}
static int
F_269 ( struct V_250 * V_250 , struct V_45 * V_46 ,
T_2 V_69 , unsigned V_252 , unsigned V_308 ,
struct V_5 * V_5 , void * V_306 )
{
struct V_3 * V_3 = V_46 -> V_165 ;
if ( V_69 + V_308 > V_3 -> V_80 )
F_127 ( V_3 , V_69 + V_308 ) ;
if ( ! F_113 ( V_5 ) ) {
struct V_5 * V_229 = F_211 ( V_5 ) ;
if ( F_270 ( V_5 ) ) {
int V_91 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
if ( V_229 + V_91 == V_5 )
continue;
F_112 ( V_229 + V_91 ) ;
F_157 ( V_229 + V_91 ) ;
}
}
if ( V_308 < V_22 ) {
unsigned V_309 = V_69 & ( V_22 - 1 ) ;
F_271 ( V_5 , 0 , V_309 ,
V_309 + V_308 , V_22 ) ;
}
F_158 ( V_229 ) ;
}
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
return V_308 ;
}
static T_14 F_272 ( struct V_310 * V_311 , struct V_312 * V_313 )
{
struct V_250 * V_250 = V_311 -> V_314 ;
struct V_3 * V_3 = F_97 ( V_250 ) ;
struct V_45 * V_46 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_255 ;
enum V_7 V_8 = V_119 ;
int error = 0 ;
T_14 V_269 = 0 ;
T_2 * V_315 = & V_311 -> V_316 ;
if ( ! F_273 ( V_313 ) )
V_8 = V_212 ;
V_4 = * V_315 >> V_84 ;
V_255 = * V_315 & ~ V_261 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_317 ;
unsigned long V_87 , V_82 ;
T_2 V_80 = F_197 ( V_3 ) ;
V_317 = V_80 >> V_84 ;
if ( V_4 > V_317 )
break;
if ( V_4 == V_317 ) {
V_87 = V_80 & ~ V_261 ;
if ( V_87 <= V_255 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_63 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_212 )
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
}
V_87 = V_22 ;
V_80 = F_197 ( V_3 ) ;
V_317 = V_80 >> V_84 ;
if ( V_4 == V_317 ) {
V_87 = V_80 & ~ V_261 ;
if ( V_87 <= V_255 ) {
if ( V_5 )
F_56 ( V_5 ) ;
break;
}
}
V_87 -= V_255 ;
if ( V_5 ) {
if ( F_274 ( V_46 ) )
F_157 ( V_5 ) ;
if ( ! V_255 )
F_198 ( V_5 ) ;
} else {
V_5 = F_275 ( 0 ) ;
F_189 ( V_5 ) ;
}
V_82 = F_276 ( V_5 , V_255 , V_87 , V_313 ) ;
V_269 += V_82 ;
V_255 += V_82 ;
V_4 += V_255 >> V_84 ;
V_255 &= ~ V_261 ;
F_56 ( V_5 ) ;
if ( ! F_277 ( V_313 ) )
break;
if ( V_82 < V_87 ) {
error = - V_300 ;
break;
}
F_106 () ;
}
* V_315 = ( ( T_2 ) V_4 << V_84 ) + V_255 ;
F_234 ( V_250 ) ;
return V_269 ? V_269 : error ;
}
static T_1 F_278 ( struct V_45 * V_46 ,
T_1 V_4 , T_1 V_101 , int V_318 )
{
struct V_5 * V_5 ;
struct V_109 V_110 ;
T_1 V_111 [ V_112 ] ;
bool V_319 = false ;
int V_91 ;
F_100 ( & V_110 , 0 ) ;
V_110 . V_87 = 1 ;
while ( ! V_319 ) {
V_110 . V_87 = F_102 ( V_46 , V_4 ,
V_110 . V_87 , V_110 . V_21 , V_111 ) ;
if ( ! V_110 . V_87 ) {
if ( V_318 == V_320 )
V_4 = V_101 ;
break;
}
for ( V_91 = 0 ; V_91 < V_110 . V_87 ; V_91 ++ , V_4 ++ ) {
if ( V_4 < V_111 [ V_91 ] ) {
if ( V_318 == V_321 ) {
V_319 = true ;
break;
}
V_4 = V_111 [ V_91 ] ;
}
V_5 = V_110 . V_21 [ V_91 ] ;
if ( V_5 && ! F_92 ( V_5 ) ) {
if ( ! F_113 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_101 ||
( V_5 && V_318 == V_320 ) ||
( ! V_5 && V_318 == V_321 ) ) {
V_319 = true ;
break;
}
}
F_103 ( & V_110 ) ;
F_105 ( & V_110 ) ;
V_110 . V_87 = V_112 ;
F_106 () ;
}
return V_4 ;
}
static T_2 F_279 ( struct V_250 * V_250 , T_2 V_255 , int V_318 )
{
struct V_45 * V_46 = V_250 -> V_271 ;
struct V_3 * V_3 = V_46 -> V_165 ;
T_1 V_100 , V_101 ;
T_2 V_322 ;
if ( V_318 != V_320 && V_318 != V_321 )
return F_280 ( V_250 , V_255 , V_318 ,
V_208 , F_197 ( V_3 ) ) ;
F_281 ( V_3 ) ;
if ( V_255 < 0 )
V_255 = - V_63 ;
else if ( V_255 >= V_3 -> V_80 )
V_255 = - V_323 ;
else {
V_100 = V_255 >> V_84 ;
V_101 = ( V_3 -> V_80 + V_22 - 1 ) >> V_84 ;
V_322 = F_278 ( V_46 , V_100 , V_101 , V_318 ) ;
V_322 <<= V_84 ;
if ( V_322 > V_255 ) {
if ( V_322 < V_3 -> V_80 )
V_255 = V_322 ;
else if ( V_318 == V_320 )
V_255 = - V_323 ;
else
V_255 = V_3 -> V_80 ;
}
}
if ( V_255 >= 0 )
V_255 = F_282 ( V_250 , V_255 , V_208 ) ;
F_283 ( V_3 ) ;
return V_255 ;
}
static void F_284 ( struct V_45 * V_46 )
{
struct V_102 V_103 ;
void * * V_104 ;
T_1 V_100 ;
struct V_5 * V_5 ;
F_285 () ;
V_100 = 0 ;
F_37 () ;
F_88 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_89 ( V_104 ) ;
if ( ! V_5 || F_286 ( V_5 ) ) {
if ( F_90 ( V_5 ) ) {
V_104 = F_91 ( & V_103 ) ;
continue;
}
} else if ( F_287 ( V_5 ) - F_288 ( V_5 ) > 1 ) {
F_70 ( & V_46 -> V_88 ) ;
F_289 ( & V_46 -> V_53 , V_103 . V_4 ,
V_324 ) ;
F_77 ( & V_46 -> V_88 ) ;
}
if ( F_93 () ) {
V_104 = F_94 ( V_104 , & V_103 ) ;
F_95 () ;
}
}
F_39 () ;
}
static int F_290 ( struct V_45 * V_46 )
{
struct V_102 V_103 ;
void * * V_104 ;
T_1 V_100 ;
struct V_5 * V_5 ;
int error , V_325 ;
F_284 ( V_46 ) ;
error = 0 ;
for ( V_325 = 0 ; V_325 <= V_326 ; V_325 ++ ) {
if ( ! F_291 ( & V_46 -> V_53 , V_324 ) )
break;
if ( ! V_325 )
F_292 () ;
else if ( F_293 ( ( V_327 << V_325 ) / 200 ) )
V_325 = V_326 ;
V_100 = 0 ;
F_37 () ;
F_294 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_89 ( V_104 ) ;
if ( F_286 ( V_5 ) ) {
if ( F_90 ( V_5 ) ) {
V_104 = F_91 ( & V_103 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_287 ( V_5 ) - F_288 ( V_5 ) != 1 ) {
if ( V_325 < V_326 )
goto V_328;
error = - V_329 ;
}
F_70 ( & V_46 -> V_88 ) ;
F_295 ( & V_46 -> V_53 ,
V_103 . V_4 , V_324 ) ;
F_77 ( & V_46 -> V_88 ) ;
V_328:
if ( F_93 () ) {
V_104 = F_94 ( V_104 , & V_103 ) ;
F_95 () ;
}
}
F_39 () ;
}
return error ;
}
int F_296 ( struct V_250 * V_250 , unsigned int V_136 )
{
struct V_3 * V_3 = F_97 ( V_250 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
int error ;
if ( V_250 -> V_263 != & V_264 )
return - V_63 ;
if ( ! ( V_250 -> V_330 & V_331 ) )
return - V_139 ;
if ( V_136 & ~ ( unsigned int ) V_332 )
return - V_63 ;
F_281 ( V_3 ) ;
if ( V_24 -> V_136 & V_276 ) {
error = - V_139 ;
goto V_214;
}
if ( ( V_136 & V_307 ) && ! ( V_24 -> V_136 & V_307 ) ) {
error = F_297 ( V_250 -> V_271 ) ;
if ( error )
goto V_214;
error = F_290 ( V_250 -> V_271 ) ;
if ( error ) {
F_298 ( V_250 -> V_271 ) ;
goto V_214;
}
}
V_24 -> V_136 |= V_136 ;
error = 0 ;
V_214:
F_283 ( V_3 ) ;
return error ;
}
int F_299 ( struct V_250 * V_250 )
{
if ( V_250 -> V_263 != & V_264 )
return - V_63 ;
return F_17 ( F_97 ( V_250 ) ) -> V_136 ;
}
long F_300 ( struct V_250 * V_250 , unsigned int V_333 , unsigned long V_334 )
{
long error ;
switch ( V_333 ) {
case V_335 :
if ( V_334 > V_336 )
return - V_63 ;
error = F_296 ( V_250 , V_334 ) ;
break;
case V_337 :
error = F_299 ( V_250 ) ;
break;
default:
error = - V_63 ;
break;
}
return error ;
}
static long F_301 ( struct V_250 * V_250 , int V_183 , T_2 V_255 ,
T_2 V_252 )
{
struct V_3 * V_3 = F_97 ( V_250 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
struct V_23 * V_24 = F_17 ( V_3 ) ;
struct V_171 V_171 ;
T_1 V_100 , V_4 , V_101 ;
int error ;
if ( V_183 & ~ ( V_338 | V_339 ) )
return - V_340 ;
F_281 ( V_3 ) ;
if ( V_183 & V_339 ) {
struct V_45 * V_46 = V_250 -> V_271 ;
T_2 V_341 = F_50 ( V_255 , V_22 ) ;
T_2 V_342 = F_66 ( V_255 + V_252 , V_22 ) - 1 ;
F_302 ( V_236 ) ;
if ( V_24 -> V_136 & V_307 ) {
error = - V_139 ;
goto V_161;
}
V_171 . V_173 = & V_236 ;
V_171 . V_100 = V_341 >> V_84 ;
V_171 . V_70 = ( V_342 + 1 ) >> V_84 ;
F_24 ( & V_3 -> V_172 ) ;
V_3 -> V_170 = & V_171 ;
F_25 ( & V_3 -> V_172 ) ;
if ( ( V_343 ) V_342 > ( V_343 ) V_341 )
F_128 ( V_46 , V_341 ,
1 + V_342 - V_341 , 0 ) ;
F_120 ( V_3 , V_255 , V_255 + V_252 - 1 ) ;
F_24 ( & V_3 -> V_172 ) ;
V_3 -> V_170 = NULL ;
F_303 ( & V_236 ) ;
F_156 ( ! F_45 ( & V_236 . V_229 ) ) ;
F_25 ( & V_3 -> V_172 ) ;
error = 0 ;
goto V_161;
}
error = F_304 ( V_3 , V_255 + V_252 ) ;
if ( error )
goto V_161;
if ( ( V_24 -> V_136 & V_138 ) && V_255 + V_252 > V_3 -> V_80 ) {
error = - V_139 ;
goto V_161;
}
V_100 = V_255 >> V_84 ;
V_101 = ( V_255 + V_252 + V_22 - 1 ) >> V_84 ;
if ( V_25 -> V_27 && V_101 - V_100 > V_25 -> V_27 ) {
error = - V_37 ;
goto V_161;
}
V_171 . V_173 = NULL ;
V_171 . V_100 = V_100 ;
V_171 . V_70 = V_100 ;
V_171 . V_344 = 0 ;
V_171 . V_174 = 0 ;
F_24 ( & V_3 -> V_172 ) ;
V_3 -> V_170 = & V_171 ;
F_25 ( & V_3 -> V_172 ) ;
for ( V_4 = V_100 ; V_4 < V_101 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_305 ( V_17 ) )
error = - V_345 ;
else if ( V_171 . V_174 > V_171 . V_344 )
error = - V_155 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_228 ) ;
if ( error ) {
if ( V_4 > V_100 ) {
F_107 ( V_3 ,
( T_2 ) V_100 << V_84 ,
( ( T_2 ) V_4 << V_84 ) - 1 , true ) ;
}
goto V_346;
}
V_171 . V_70 ++ ;
if ( ! F_113 ( V_5 ) )
V_171 . V_344 ++ ;
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
F_106 () ;
}
if ( ! ( V_183 & V_338 ) && V_255 + V_252 > V_3 -> V_80 )
F_127 ( V_3 , V_255 + V_252 ) ;
V_3 -> V_121 = F_121 ( V_3 ) ;
V_346:
F_24 ( & V_3 -> V_172 ) ;
V_3 -> V_170 = NULL ;
F_25 ( & V_3 -> V_172 ) ;
V_161:
F_283 ( V_3 ) ;
return error ;
}
static int F_306 ( struct V_128 * V_128 , struct V_347 * V_348 )
{
struct V_10 * V_25 = F_7 ( V_128 -> V_349 ) ;
V_348 -> V_350 = V_351 ;
V_348 -> V_352 = V_22 ;
V_348 -> V_353 = V_354 ;
if ( V_25 -> V_27 ) {
V_348 -> V_355 = V_25 -> V_27 ;
V_348 -> V_356 =
V_348 -> V_357 = V_25 -> V_27 -
F_307 ( & V_25 -> V_28 ) ;
}
if ( V_25 -> V_34 ) {
V_348 -> V_358 = V_25 -> V_34 ;
V_348 -> V_359 = V_25 -> V_36 ;
}
return 0 ;
}
static int
F_308 ( struct V_3 * V_272 , struct V_128 * V_128 , T_9 V_183 , T_10 V_273 )
{
struct V_3 * V_3 ;
int error = - V_37 ;
V_3 = F_236 ( V_272 -> V_26 , V_272 , V_183 , V_273 , V_16 ) ;
if ( V_3 ) {
error = F_309 ( V_272 , V_3 ) ;
if ( error )
goto V_360;
error = F_310 ( V_3 , V_272 ,
& V_128 -> V_361 ,
V_362 , NULL ) ;
if ( error && error != - V_340 )
goto V_360;
error = 0 ;
V_272 -> V_80 += V_284 ;
V_272 -> V_121 = V_272 -> V_122 = F_121 ( V_272 ) ;
F_311 ( V_128 , V_3 ) ;
F_312 ( V_128 ) ;
}
return error ;
V_360:
F_52 ( V_3 ) ;
return error ;
}
static int
F_313 ( struct V_3 * V_272 , struct V_128 * V_128 , T_9 V_183 )
{
struct V_3 * V_3 ;
int error = - V_37 ;
V_3 = F_236 ( V_272 -> V_26 , V_272 , V_183 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_310 ( V_3 , V_272 ,
NULL ,
V_362 , NULL ) ;
if ( error && error != - V_340 )
goto V_360;
error = F_309 ( V_272 , V_3 ) ;
if ( error )
goto V_360;
F_314 ( V_128 , V_3 ) ;
}
return error ;
V_360:
F_52 ( V_3 ) ;
return error ;
}
static int F_315 ( struct V_3 * V_272 , struct V_128 * V_128 , T_9 V_183 )
{
int error ;
if ( ( error = F_308 ( V_272 , V_128 , V_183 | V_283 , 0 ) ) )
return error ;
F_247 ( V_272 ) ;
return 0 ;
}
static int F_316 ( struct V_3 * V_272 , struct V_128 * V_128 , T_9 V_183 ,
bool V_363 )
{
return F_308 ( V_272 , V_128 , V_183 | V_280 , 0 ) ;
}
static int F_317 ( struct V_128 * V_364 , struct V_3 * V_272 , struct V_128 * V_128 )
{
struct V_3 * V_3 = V_129 ( V_364 ) ;
int V_82 ;
V_82 = F_23 ( V_3 -> V_26 ) ;
if ( V_82 )
goto V_161;
V_272 -> V_80 += V_284 ;
V_3 -> V_121 = V_272 -> V_121 = V_272 -> V_122 = F_121 ( V_3 ) ;
F_247 ( V_3 ) ;
F_318 ( V_3 ) ;
F_312 ( V_128 ) ;
F_311 ( V_128 , V_3 ) ;
V_161:
return V_82 ;
}
static int F_319 ( struct V_3 * V_272 , struct V_128 * V_128 )
{
struct V_3 * V_3 = V_129 ( V_128 ) ;
if ( V_3 -> V_365 > 1 && ! F_320 ( V_3 -> V_132 ) )
F_26 ( V_3 -> V_26 ) ;
V_272 -> V_80 -= V_284 ;
V_3 -> V_121 = V_272 -> V_121 = V_272 -> V_122 = F_121 ( V_3 ) ;
F_321 ( V_3 ) ;
F_322 ( V_128 ) ;
return 0 ;
}
static int F_323 ( struct V_3 * V_272 , struct V_128 * V_128 )
{
if ( ! F_324 ( V_128 ) )
return - V_366 ;
F_321 ( V_129 ( V_128 ) ) ;
F_321 ( V_272 ) ;
return F_319 ( V_272 , V_128 ) ;
}
static int F_325 ( struct V_3 * V_367 , struct V_128 * V_364 , struct V_3 * V_368 , struct V_128 * V_369 )
{
bool V_370 = F_326 ( V_364 ) ;
bool V_371 = F_326 ( V_369 ) ;
if ( V_367 != V_368 && V_370 != V_371 ) {
if ( V_370 ) {
F_321 ( V_367 ) ;
F_247 ( V_368 ) ;
} else {
F_321 ( V_368 ) ;
F_247 ( V_367 ) ;
}
}
V_367 -> V_121 = V_367 -> V_122 =
V_368 -> V_121 = V_368 -> V_122 =
V_129 ( V_364 ) -> V_121 =
V_129 ( V_369 ) -> V_121 = F_121 ( V_367 ) ;
return 0 ;
}
static int F_327 ( struct V_3 * V_367 , struct V_128 * V_364 )
{
struct V_128 * V_372 ;
int error ;
V_372 = F_328 ( V_364 -> V_373 , & V_364 -> V_361 ) ;
if ( ! V_372 )
return - V_155 ;
error = F_308 ( V_367 , V_372 ,
V_374 | V_375 , V_376 ) ;
F_322 ( V_372 ) ;
if ( error )
return error ;
F_329 ( V_372 ) ;
return 0 ;
}
static int F_330 ( struct V_3 * V_367 , struct V_128 * V_364 , struct V_3 * V_368 , struct V_128 * V_369 , unsigned int V_14 )
{
struct V_3 * V_3 = V_129 ( V_364 ) ;
int V_377 = F_320 ( V_3 -> V_132 ) ;
if ( V_14 & ~ ( V_378 | V_379 | V_380 ) )
return - V_63 ;
if ( V_14 & V_379 )
return F_325 ( V_367 , V_364 , V_368 , V_369 ) ;
if ( ! F_324 ( V_369 ) )
return - V_366 ;
if ( V_14 & V_380 ) {
int error ;
error = F_327 ( V_367 , V_364 ) ;
if ( error )
return error ;
}
if ( F_331 ( V_369 ) ) {
( void ) F_319 ( V_368 , V_369 ) ;
if ( V_377 ) {
F_321 ( V_129 ( V_369 ) ) ;
F_321 ( V_367 ) ;
}
} else if ( V_377 ) {
F_321 ( V_367 ) ;
F_247 ( V_368 ) ;
}
V_367 -> V_80 -= V_284 ;
V_368 -> V_80 += V_284 ;
V_367 -> V_121 = V_367 -> V_122 =
V_368 -> V_121 = V_368 -> V_122 =
V_3 -> V_121 = F_121 ( V_367 ) ;
return 0 ;
}
static int F_332 ( struct V_3 * V_272 , struct V_128 * V_128 , const char * V_381 )
{
int error ;
int V_252 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_23 * V_24 ;
V_252 = strlen ( V_381 ) + 1 ;
if ( V_252 > V_22 )
return - V_382 ;
V_3 = F_236 ( V_272 -> V_26 , V_272 , V_287 | V_383 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_37 ;
error = F_310 ( V_3 , V_272 , & V_128 -> V_361 ,
V_362 , NULL ) ;
if ( error ) {
if ( error != - V_340 ) {
F_52 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_24 = F_17 ( V_3 ) ;
V_3 -> V_80 = V_252 - 1 ;
if ( V_252 <= V_384 ) {
V_3 -> V_385 = F_333 ( V_381 , V_252 , V_162 ) ;
if ( ! V_3 -> V_385 ) {
F_52 ( V_3 ) ;
return - V_155 ;
}
V_3 -> V_278 = & V_386 ;
} else {
F_334 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_215 ) ;
if ( error ) {
F_52 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_143 = & V_144 ;
V_3 -> V_278 = & V_387 ;
memcpy ( F_335 ( V_5 ) , V_381 , V_252 ) ;
F_158 ( V_5 ) ;
F_118 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
}
V_272 -> V_80 += V_284 ;
V_272 -> V_121 = V_272 -> V_122 = F_121 ( V_272 ) ;
F_311 ( V_128 , V_3 ) ;
F_312 ( V_128 ) ;
return 0 ;
}
static void F_336 ( void * V_334 )
{
F_198 ( V_334 ) ;
F_56 ( V_334 ) ;
}
static const char * F_337 ( struct V_128 * V_128 ,
struct V_3 * V_3 ,
struct V_388 * V_319 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_128 ) {
V_5 = F_338 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_186 ( - V_389 ) ;
if ( ! F_113 ( V_5 ) ) {
F_56 ( V_5 ) ;
return F_186 ( - V_389 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_119 ) ;
if ( error )
return F_186 ( error ) ;
F_55 ( V_5 ) ;
}
F_339 ( V_319 , F_336 , V_5 ) ;
return F_335 ( V_5 ) ;
}
static int V_362 ( struct V_3 * V_3 ,
const struct V_390 * V_391 ,
void * V_392 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
const struct V_390 * V_390 ;
struct V_393 * V_394 ;
T_15 V_252 ;
for ( V_390 = V_391 ; V_390 -> V_395 != NULL ; V_390 ++ ) {
V_394 = F_340 ( V_390 -> V_396 , V_390 -> V_397 ) ;
if ( ! V_394 )
return - V_155 ;
V_252 = strlen ( V_390 -> V_395 ) + 1 ;
V_394 -> V_395 = F_341 ( V_398 + V_252 ,
V_162 ) ;
if ( ! V_394 -> V_395 ) {
F_342 ( V_394 ) ;
return - V_155 ;
}
memcpy ( V_394 -> V_395 , V_399 ,
V_398 ) ;
memcpy ( V_394 -> V_395 + V_398 ,
V_390 -> V_395 , V_252 ) ;
F_343 ( & V_24 -> V_147 , V_394 ) ;
}
return 0 ;
}
static int F_344 ( const struct V_400 * V_401 ,
struct V_128 * V_402 , struct V_3 * V_3 ,
const char * V_395 , void * V_182 , T_15 V_15 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
V_395 = F_345 ( V_401 , V_395 ) ;
return F_346 ( & V_24 -> V_147 , V_395 , V_182 , V_15 ) ;
}
static int F_347 ( const struct V_400 * V_401 ,
struct V_128 * V_402 , struct V_3 * V_3 ,
const char * V_395 , const void * V_396 ,
T_15 V_15 , int V_14 )
{
struct V_23 * V_24 = F_17 ( V_3 ) ;
V_395 = F_345 ( V_401 , V_395 ) ;
return F_348 ( & V_24 -> V_147 , V_395 , V_396 , V_15 , V_14 ) ;
}
static T_14 F_349 ( struct V_128 * V_128 , char * V_182 , T_15 V_15 )
{
struct V_23 * V_24 = F_17 ( V_129 ( V_128 ) ) ;
return F_350 ( V_129 ( V_128 ) , & V_24 -> V_147 , V_182 , V_15 ) ;
}
static struct V_128 * F_351 ( struct V_128 * V_403 )
{
return F_186 ( - V_404 ) ;
}
static int F_352 ( struct V_3 * V_405 , void * V_406 )
{
T_16 * V_407 = V_406 ;
T_17 V_408 = V_407 [ 2 ] ;
V_408 = ( V_408 << 32 ) | V_407 [ 1 ] ;
return V_405 -> V_185 == V_408 && V_407 [ 0 ] == V_405 -> V_275 ;
}
static struct V_128 * F_353 ( struct V_11 * V_12 ,
struct V_409 * V_409 , int V_410 , int V_411 )
{
struct V_3 * V_3 ;
struct V_128 * V_128 = NULL ;
V_343 V_408 ;
if ( V_410 < 3 )
return NULL ;
V_408 = V_409 -> V_412 [ 2 ] ;
V_408 = ( V_408 << 32 ) | V_409 -> V_412 [ 1 ] ;
V_3 = F_354 ( V_12 , ( unsigned long ) ( V_408 + V_409 -> V_412 [ 0 ] ) ,
F_352 , V_409 -> V_412 ) ;
if ( V_3 ) {
V_128 = F_355 ( V_3 ) ;
F_52 ( V_3 ) ;
}
return V_128 ;
}
static int F_356 ( struct V_3 * V_3 , T_16 * V_407 , int * V_252 ,
struct V_3 * V_413 )
{
if ( * V_252 < 3 ) {
* V_252 = 3 ;
return V_414 ;
}
if ( F_357 ( V_3 ) ) {
static F_358 ( V_44 ) ;
F_24 ( & V_44 ) ;
if ( F_357 ( V_3 ) )
F_359 ( V_3 ,
V_3 -> V_185 + V_3 -> V_275 ) ;
F_25 ( & V_44 ) ;
}
V_407 [ 0 ] = V_3 -> V_275 ;
V_407 [ 1 ] = V_3 -> V_185 ;
V_407 [ 2 ] = ( ( T_17 ) V_3 -> V_185 ) >> 32 ;
* V_252 = 3 ;
return 1 ;
}
static int F_360 ( char * V_415 , struct V_10 * V_25 ,
bool V_416 )
{
char * V_417 , * V_396 , * V_418 ;
struct V_180 * V_181 = NULL ;
T_18 V_419 ;
T_19 V_420 ;
while ( V_415 != NULL ) {
V_417 = V_415 ;
for (; ; ) {
V_415 = strchr ( V_415 , ',' ) ;
if ( V_415 == NULL )
break;
V_415 ++ ;
if ( ! isdigit ( * V_415 ) ) {
V_415 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_417 )
continue;
if ( ( V_396 = strchr ( V_417 , '=' ) ) != NULL ) {
* V_396 ++ = 0 ;
} else {
F_361 ( L_9 ,
V_417 ) ;
goto error;
}
if ( ! strcmp ( V_417 , L_10 ) ) {
unsigned long long V_15 ;
V_15 = F_362 ( V_396 , & V_418 ) ;
if ( * V_418 == '%' ) {
V_15 <<= V_84 ;
V_15 *= V_1 ;
F_363 ( V_15 , 100 ) ;
V_418 ++ ;
}
if ( * V_418 )
goto V_421;
V_25 -> V_27 =
F_210 ( V_15 , V_22 ) ;
} else if ( ! strcmp ( V_417 , L_11 ) ) {
V_25 -> V_27 = F_362 ( V_396 , & V_418 ) ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_12 ) ) {
V_25 -> V_34 = F_362 ( V_396 , & V_418 ) ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_13 ) ) {
if ( V_416 )
continue;
V_25 -> V_183 = F_364 ( V_396 , & V_418 , 8 ) & 07777 ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_14 ) ) {
if ( V_416 )
continue;
V_419 = F_364 ( V_396 , & V_418 , 0 ) ;
if ( * V_418 )
goto V_421;
V_25 -> V_419 = F_365 ( F_366 () , V_419 ) ;
if ( ! F_367 ( V_25 -> V_419 ) )
goto V_421;
} else if ( ! strcmp ( V_417 , L_15 ) ) {
if ( V_416 )
continue;
V_420 = F_364 ( V_396 , & V_418 , 0 ) ;
if ( * V_418 )
goto V_421;
V_25 -> V_420 = F_368 ( F_366 () , V_420 ) ;
if ( ! F_369 ( V_25 -> V_420 ) )
goto V_421;
#ifdef V_141
} else if ( ! strcmp ( V_417 , L_16 ) ) {
int V_64 ;
V_64 = F_41 ( V_396 ) ;
if ( V_64 < 0 )
goto V_421;
if ( ! F_370 () &&
V_64 != V_57 )
goto V_421;
V_25 -> V_64 = V_64 ;
#endif
#ifdef F_371
} else if ( ! strcmp ( V_417 , L_17 ) ) {
F_372 ( V_181 ) ;
V_181 = NULL ;
if ( F_373 ( V_396 , & V_181 ) )
goto V_421;
#endif
} else {
F_361 ( L_18 , V_417 ) ;
goto error;
}
}
V_25 -> V_181 = V_181 ;
return 0 ;
V_421:
F_361 ( L_19 ,
V_396 , V_417 ) ;
error:
F_372 ( V_181 ) ;
return 1 ;
}
static int F_374 ( struct V_11 * V_12 , int * V_14 , char * V_422 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
struct V_10 V_423 = * V_25 ;
unsigned long V_424 ;
int error = - V_63 ;
V_423 . V_181 = NULL ;
if ( F_360 ( V_422 , & V_423 , true ) )
return error ;
F_24 ( & V_25 -> V_35 ) ;
V_424 = V_25 -> V_34 - V_25 -> V_36 ;
if ( F_18 ( & V_25 -> V_28 , V_423 . V_27 ) > 0 )
goto V_161;
if ( V_423 . V_34 < V_424 )
goto V_161;
if ( V_423 . V_27 && ! V_25 -> V_27 )
goto V_161;
if ( V_423 . V_34 && ! V_25 -> V_34 )
goto V_161;
error = 0 ;
V_25 -> V_64 = V_423 . V_64 ;
V_25 -> V_27 = V_423 . V_27 ;
V_25 -> V_34 = V_423 . V_34 ;
V_25 -> V_36 = V_423 . V_34 - V_424 ;
if ( V_423 . V_181 ) {
F_372 ( V_25 -> V_181 ) ;
V_25 -> V_181 = V_423 . V_181 ;
}
V_161:
F_25 ( & V_25 -> V_35 ) ;
return error ;
}
static int F_375 ( struct V_178 * V_179 , struct V_128 * V_149 )
{
struct V_10 * V_25 = F_7 ( V_149 -> V_349 ) ;
if ( V_25 -> V_27 != F_1 () )
F_168 ( V_179 , L_20 ,
V_25 -> V_27 << ( V_84 - 10 ) ) ;
if ( V_25 -> V_34 != F_2 () )
F_168 ( V_179 , L_21 , V_25 -> V_34 ) ;
if ( V_25 -> V_183 != ( V_383 | V_425 ) )
F_168 ( V_179 , L_22 , V_25 -> V_183 ) ;
if ( ! F_376 ( V_25 -> V_419 , V_426 ) )
F_168 ( V_179 , L_23 ,
F_377 ( & V_427 , V_25 -> V_419 ) ) ;
if ( ! F_378 ( V_25 -> V_420 , V_428 ) )
F_168 ( V_179 , L_24 ,
F_379 ( & V_427 , V_25 -> V_420 ) ) ;
#ifdef V_141
if ( V_25 -> V_64 )
F_168 ( V_179 , L_25 , F_42 ( V_25 -> V_64 ) ) ;
#endif
F_166 ( V_179 , V_25 -> V_181 ) ;
return 0 ;
}
static void F_380 ( struct V_11 * V_12 )
{
struct V_10 * V_25 = F_7 ( V_12 ) ;
F_381 ( & V_25 -> V_28 ) ;
F_372 ( V_25 -> V_181 ) ;
F_342 ( V_25 ) ;
V_12 -> V_13 = NULL ;
}
int F_382 ( struct V_11 * V_12 , void * V_422 , int V_429 )
{
struct V_3 * V_3 ;
struct V_10 * V_25 ;
int V_194 = - V_155 ;
V_25 = F_383 ( F_384 ( ( int ) sizeof( struct V_10 ) ,
V_430 ) , V_162 ) ;
if ( ! V_25 )
return - V_155 ;
V_25 -> V_183 = V_383 | V_425 ;
V_25 -> V_419 = F_385 () ;
V_25 -> V_420 = F_386 () ;
V_12 -> V_13 = V_25 ;
#ifdef F_387
if ( ! ( V_12 -> V_431 & V_432 ) ) {
V_25 -> V_27 = F_1 () ;
V_25 -> V_34 = F_2 () ;
if ( F_360 ( V_422 , V_25 , false ) ) {
V_194 = - V_63 ;
goto V_195;
}
} else {
V_12 -> V_431 |= V_433 ;
}
V_12 -> V_434 = & V_435 ;
V_12 -> V_431 |= V_436 ;
#else
V_12 -> V_431 |= V_433 ;
#endif
F_241 ( & V_25 -> V_35 ) ;
if ( F_388 ( & V_25 -> V_28 , 0 , V_162 ) )
goto V_195;
V_25 -> V_36 = V_25 -> V_34 ;
F_241 ( & V_25 -> V_78 ) ;
F_242 ( & V_25 -> V_76 ) ;
V_12 -> V_437 = V_208 ;
V_12 -> V_438 = V_22 ;
V_12 -> V_439 = V_84 ;
V_12 -> V_440 = V_351 ;
V_12 -> V_441 = & V_442 ;
V_12 -> V_443 = 1 ;
#ifdef F_389
V_12 -> V_444 = V_445 ;
#endif
#ifdef F_390
V_12 -> V_431 |= V_446 ;
#endif
F_391 ( & V_12 -> V_447 ) ;
V_3 = F_236 ( V_12 , NULL , V_283 | V_25 -> V_183 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_195;
V_3 -> V_448 = V_25 -> V_419 ;
V_3 -> V_449 = V_25 -> V_420 ;
V_12 -> V_450 = F_392 ( V_3 ) ;
if ( ! V_12 -> V_450 )
goto V_195;
return 0 ;
V_195:
F_380 ( V_12 ) ;
return V_194 ;
}
static struct V_3 * F_393 ( struct V_11 * V_12 )
{
struct V_23 * V_24 ;
V_24 = F_394 ( V_451 , V_162 ) ;
if ( ! V_24 )
return NULL ;
return & V_24 -> V_79 ;
}
static void F_395 ( struct V_452 * V_229 )
{
struct V_3 * V_3 = F_396 ( V_229 , struct V_3 , V_453 ) ;
if ( F_397 ( V_3 -> V_132 ) )
F_342 ( V_3 -> V_385 ) ;
F_398 ( V_451 , F_17 ( V_3 ) ) ;
}
static void F_399 ( struct V_3 * V_3 )
{
if ( F_126 ( V_3 -> V_132 ) )
F_400 ( & F_17 ( V_3 ) -> V_187 ) ;
F_401 ( & V_3 -> V_453 , F_395 ) ;
}
static void F_402 ( void * V_454 )
{
struct V_23 * V_24 = V_454 ;
F_403 ( & V_24 -> V_79 ) ;
}
static int F_404 ( void )
{
V_451 = F_405 ( L_26 ,
sizeof( struct V_23 ) ,
0 , V_455 | V_456 , F_402 ) ;
return 0 ;
}
static void F_406 ( void )
{
F_407 ( V_451 ) ;
}
static struct V_128 * F_408 ( struct V_457 * V_458 ,
int V_14 , const char * V_459 , void * V_422 )
{
return F_409 ( V_458 , V_14 , V_422 , F_382 ) ;
}
int T_20 F_410 ( void )
{
int error ;
if ( V_451 )
return 0 ;
error = F_404 () ;
if ( error )
goto V_460;
error = F_411 ( & V_461 ) ;
if ( error ) {
F_361 ( L_27 ) ;
goto V_462;
}
V_265 = F_412 ( & V_461 ) ;
if ( F_204 ( V_265 ) ) {
error = F_205 ( V_265 ) ;
F_361 ( L_28 ) ;
goto V_463;
}
#ifdef V_141
if ( F_370 () && V_223 > V_61 )
F_7 ( V_265 -> V_266 ) -> V_64 = V_223 ;
else
V_223 = 0 ;
#endif
return 0 ;
V_463:
F_413 ( & V_461 ) ;
V_462:
F_406 () ;
V_460:
V_265 = F_186 ( error ) ;
return error ;
}
static T_14 F_414 ( struct V_464 * V_465 ,
struct V_466 * V_131 , char * V_348 )
{
int V_467 [] = {
V_58 ,
V_59 ,
V_60 ,
V_57 ,
V_61 ,
V_62 ,
} ;
int V_91 , V_468 ;
for ( V_91 = 0 , V_468 = 0 ; V_91 < F_415 ( V_467 ) ; V_91 ++ ) {
const char * V_469 = V_223 == V_467 [ V_91 ] ? L_29 : L_30 ;
V_468 += sprintf ( V_348 + V_468 , V_469 ,
F_42 ( V_467 [ V_91 ] ) ) ;
}
V_348 [ V_468 - 1 ] = '\n' ;
return V_468 ;
}
static T_14 F_416 ( struct V_464 * V_465 ,
struct V_466 * V_131 , const char * V_348 , T_15 V_468 )
{
char V_470 [ 16 ] ;
int V_64 ;
if ( V_468 + 1 > sizeof( V_470 ) )
return - V_63 ;
memcpy ( V_470 , V_348 , V_468 ) ;
V_470 [ V_468 ] = '\0' ;
if ( V_468 && V_470 [ V_468 - 1 ] == '\n' )
V_470 [ V_468 - 1 ] = '\0' ;
V_64 = F_41 ( V_470 ) ;
if ( V_64 == - V_63 )
return - V_63 ;
if ( ! F_370 () &&
V_64 != V_57 && V_64 != V_61 )
return - V_63 ;
V_223 = V_64 ;
if ( V_223 > V_61 )
F_7 ( V_265 -> V_266 ) -> V_64 = V_223 ;
return V_468 ;
}
bool F_417 ( struct V_30 * V_31 )
{
struct V_3 * V_3 = F_97 ( V_31 -> V_105 ) ;
struct V_10 * V_25 = F_7 ( V_3 -> V_26 ) ;
T_2 V_80 ;
T_1 V_225 ;
if ( V_223 == V_62 )
return true ;
if ( V_223 == V_61 )
return false ;
switch ( V_25 -> V_64 ) {
case V_57 :
return false ;
case V_58 :
return true ;
case V_59 :
V_225 = F_50 ( V_31 -> V_106 , V_92 ) ;
V_80 = F_50 ( F_197 ( V_3 ) , V_22 ) ;
if ( V_80 >= V_81 &&
V_80 >> V_84 >= V_225 )
return true ;
case V_60 :
return ( V_31 -> V_244 & V_247 ) ;
default:
F_33 ( 1 ) ;
return false ;
}
}
int T_20 F_410 ( void )
{
F_82 ( F_411 ( & V_461 ) != 0 ) ;
V_265 = F_412 ( & V_461 ) ;
F_82 ( F_204 ( V_265 ) ) ;
return 0 ;
}
int F_148 ( T_3 V_55 , struct V_5 * V_5 )
{
return 0 ;
}
int F_228 ( struct V_250 * V_250 , int V_44 , struct V_267 * V_268 )
{
return 0 ;
}
void F_99 ( struct V_45 * V_46 )
{
}
unsigned long F_223 ( struct V_250 * V_250 ,
unsigned long V_254 , unsigned long V_252 ,
unsigned long V_235 , unsigned long V_14 )
{
return V_17 -> V_18 -> V_260 ( V_250 , V_254 , V_252 , V_235 , V_14 ) ;
}
void F_120 ( struct V_3 * V_3 , T_2 V_113 , T_2 V_114 )
{
F_418 ( V_3 -> V_9 , V_113 , V_114 ) ;
}
static struct V_250 * F_419 ( const char * V_395 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_471 )
{
struct V_250 * V_472 ;
struct V_3 * V_3 ;
struct V_123 V_123 ;
struct V_11 * V_12 ;
struct V_473 V_157 ;
if ( F_204 ( V_265 ) )
return F_420 ( V_265 ) ;
if ( V_15 < 0 || V_15 > V_208 )
return F_186 ( - V_63 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_186 ( - V_155 ) ;
V_472 = F_186 ( - V_155 ) ;
V_157 . V_395 = V_395 ;
V_157 . V_252 = strlen ( V_395 ) ;
V_157 . V_474 = 0 ;
V_12 = V_265 -> V_266 ;
V_123 . V_475 = F_421 ( V_265 ) ;
V_123 . V_128 = F_422 ( V_12 , & V_157 ) ;
if ( ! V_123 . V_128 )
goto V_476;
F_423 ( V_123 . V_128 , & V_477 ) ;
V_472 = F_186 ( - V_37 ) ;
V_3 = F_236 ( V_12 , NULL , V_280 | V_383 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_476;
V_3 -> V_471 |= V_471 ;
F_311 ( V_123 . V_128 , V_3 ) ;
V_3 -> V_80 = V_15 ;
F_424 ( V_3 ) ;
V_472 = F_186 ( F_425 ( V_3 , V_15 ) ) ;
if ( F_204 ( V_472 ) )
goto V_478;
V_472 = F_426 ( & V_123 , V_331 | V_479 ,
& V_264 ) ;
if ( F_204 ( V_472 ) )
goto V_478;
return V_472 ;
V_476:
F_11 ( V_14 , V_15 ) ;
V_478:
F_427 ( & V_123 ) ;
return V_472 ;
}
struct V_250 * F_428 ( const char * V_395 , T_2 V_15 , unsigned long V_14 )
{
return F_419 ( V_395 , V_15 , V_14 , V_480 ) ;
}
struct V_250 * F_429 ( const char * V_395 , T_2 V_15 , unsigned long V_14 )
{
return F_419 ( V_395 , V_15 , V_14 , 0 ) ;
}
int F_430 ( struct V_30 * V_31 )
{
struct V_250 * V_250 ;
T_2 V_15 = V_31 -> V_107 - V_31 -> V_108 ;
V_250 = F_419 ( L_31 , V_15 , V_31 -> V_244 , V_480 ) ;
if ( F_204 ( V_250 ) )
return F_205 ( V_250 ) ;
if ( V_31 -> V_105 )
F_431 ( V_31 -> V_105 ) ;
V_31 -> V_105 = V_250 ;
V_31 -> V_32 = & V_33 ;
if ( F_129 ( V_141 ) &&
( ( V_31 -> V_108 + ~ V_83 ) & V_83 ) <
( V_31 -> V_107 & V_83 ) ) {
F_235 ( V_31 , V_31 -> V_244 ) ;
}
return 0 ;
}
struct V_5 * F_432 ( struct V_45 * V_46 ,
T_1 V_4 , T_6 V_152 )
{
#ifdef F_433
struct V_3 * V_3 = V_46 -> V_165 ;
struct V_5 * V_5 ;
int error ;
F_82 ( V_46 -> V_143 != & V_144 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_212 ,
V_152 , NULL , NULL , NULL ) ;
if ( error )
V_5 = F_186 ( error ) ;
else
F_55 ( V_5 ) ;
return V_5 ;
#else
return F_434 ( V_46 , V_4 , V_152 ) ;
#endif
}
