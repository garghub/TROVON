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
bool F_16 ( struct V_23 * V_24 )
{
return V_24 -> V_25 == & V_26 ;
}
static int F_17 ( struct V_11 * V_12 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
if ( V_27 -> V_28 ) {
F_18 ( & V_27 -> V_29 ) ;
if ( ! V_27 -> V_30 ) {
F_19 ( & V_27 -> V_29 ) ;
return - V_31 ;
}
V_27 -> V_30 -- ;
F_19 ( & V_27 -> V_29 ) ;
}
return 0 ;
}
static void F_20 ( struct V_11 * V_12 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
if ( V_27 -> V_28 ) {
F_18 ( & V_27 -> V_29 ) ;
V_27 -> V_30 ++ ;
F_19 ( & V_27 -> V_29 ) ;
}
}
static void F_21 ( struct V_3 * V_3 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
long V_34 ;
V_34 = V_33 -> V_35 - V_33 -> V_36 - V_3 -> V_9 -> V_37 ;
if ( V_34 > 0 ) {
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
if ( V_27 -> V_39 )
F_23 ( & V_27 -> V_40 , - V_34 ) ;
V_33 -> V_35 -= V_34 ;
V_3 -> V_41 -= V_34 * V_42 ;
F_15 ( V_33 -> V_14 , V_34 ) ;
}
}
bool F_24 ( struct V_3 * V_3 , long V_21 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
unsigned long V_14 ;
if ( F_14 ( V_33 -> V_14 , V_21 ) )
return false ;
F_25 ( & V_33 -> V_43 , V_14 ) ;
V_33 -> V_35 += V_21 ;
V_3 -> V_41 += V_21 * V_42 ;
F_21 ( V_3 ) ;
F_26 ( & V_33 -> V_43 , V_14 ) ;
V_3 -> V_9 -> V_37 += V_21 ;
if ( ! V_27 -> V_39 )
return true ;
if ( F_27 ( & V_27 -> V_40 ,
V_27 -> V_39 - V_21 ) > 0 ) {
V_3 -> V_9 -> V_37 -= V_21 ;
F_25 ( & V_33 -> V_43 , V_14 ) ;
V_33 -> V_35 -= V_21 ;
F_21 ( V_3 ) ;
F_26 ( & V_33 -> V_43 , V_14 ) ;
F_15 ( V_33 -> V_14 , V_21 ) ;
return false ;
}
F_23 ( & V_27 -> V_40 , V_21 ) ;
return true ;
}
void F_28 ( struct V_3 * V_3 , long V_21 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
unsigned long V_14 ;
F_25 ( & V_33 -> V_43 , V_14 ) ;
V_33 -> V_35 -= V_21 ;
V_3 -> V_41 -= V_21 * V_42 ;
F_21 ( V_3 ) ;
F_26 ( & V_33 -> V_43 , V_14 ) ;
if ( V_27 -> V_39 )
F_29 ( & V_27 -> V_40 , V_21 ) ;
F_15 ( V_33 -> V_14 , V_21 ) ;
}
static int F_30 ( struct V_44 * V_45 ,
T_1 V_4 , void * V_46 , void * V_47 )
{
struct V_48 * V_49 ;
void * * V_50 ;
void * V_51 ;
F_31 ( ! V_46 ) ;
F_31 ( ! V_47 ) ;
V_51 = F_32 ( & V_45 -> V_52 , V_4 , & V_49 , & V_50 ) ;
if ( ! V_51 )
return - V_53 ;
if ( V_51 != V_46 )
return - V_53 ;
F_33 ( & V_45 -> V_52 , V_49 , V_50 ,
V_47 , NULL , NULL ) ;
return 0 ;
}
static bool F_34 ( struct V_44 * V_45 ,
T_1 V_4 , T_3 V_54 )
{
void * V_51 ;
F_35 () ;
V_51 = F_36 ( & V_45 -> V_52 , V_4 ) ;
F_37 () ;
return V_51 == F_38 ( V_54 ) ;
}
static int F_39 ( const char * V_55 )
{
if ( ! strcmp ( V_55 , L_1 ) )
return V_56 ;
if ( ! strcmp ( V_55 , L_2 ) )
return V_57 ;
if ( ! strcmp ( V_55 , L_3 ) )
return V_58 ;
if ( ! strcmp ( V_55 , L_4 ) )
return V_59 ;
if ( ! strcmp ( V_55 , L_5 ) )
return V_60 ;
if ( ! strcmp ( V_55 , L_6 ) )
return V_61 ;
return - V_62 ;
}
static const char * F_40 ( int V_63 )
{
switch ( V_63 ) {
case V_56 :
return L_1 ;
case V_57 :
return L_2 ;
case V_58 :
return L_3 ;
case V_59 :
return L_4 ;
case V_60 :
return L_5 ;
case V_61 :
return L_6 ;
default:
F_31 ( 1 ) ;
return L_7 ;
}
}
static unsigned long F_41 ( struct V_10 * V_27 ,
struct V_64 * V_65 , unsigned long V_66 )
{
F_42 ( V_67 ) , * V_68 , * V_69 ;
F_42 ( V_70 ) ;
struct V_3 * V_3 ;
struct V_32 * V_33 ;
struct V_5 * V_5 ;
unsigned long V_71 = V_65 ? V_65 -> V_72 : 128 ;
int V_73 = 0 , V_74 = 0 ;
if ( F_43 ( & V_27 -> V_75 ) )
return V_76 ;
F_18 ( & V_27 -> V_77 ) ;
F_44 (pos, next, &sbinfo->shrinklist) {
V_33 = F_45 ( V_68 , struct V_32 , V_75 ) ;
V_3 = F_46 ( & V_33 -> V_78 ) ;
if ( ! V_3 ) {
F_47 ( & V_33 -> V_75 ) ;
V_73 ++ ;
goto V_69;
}
if ( F_48 ( V_3 -> V_79 , V_22 ) ==
F_48 ( V_3 -> V_79 , V_80 ) ) {
F_49 ( & V_33 -> V_75 , & V_70 ) ;
V_73 ++ ;
goto V_69;
}
F_49 ( & V_33 -> V_75 , & V_67 ) ;
V_69:
if ( ! -- V_71 )
break;
}
F_19 ( & V_27 -> V_77 ) ;
F_44 (pos, next, &to_remove) {
V_33 = F_45 ( V_68 , struct V_32 , V_75 ) ;
V_3 = & V_33 -> V_78 ;
F_47 ( & V_33 -> V_75 ) ;
F_50 ( V_3 ) ;
}
F_44 (pos, next, &list) {
int V_81 ;
V_33 = F_45 ( V_68 , struct V_32 , V_75 ) ;
V_3 = & V_33 -> V_78 ;
if ( V_66 && V_74 >= V_66 ) {
F_50 ( V_3 ) ;
continue;
}
V_5 = F_51 ( V_3 -> V_9 ,
( V_3 -> V_79 & V_82 ) >> V_83 ) ;
if ( ! V_5 )
goto V_84;
if ( ! F_52 ( V_5 ) ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
goto V_84;
}
V_81 = F_55 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
if ( V_81 ) {
F_50 ( V_3 ) ;
continue;
}
V_74 ++ ;
V_84:
F_47 ( & V_33 -> V_75 ) ;
V_73 ++ ;
F_50 ( V_3 ) ;
}
F_18 ( & V_27 -> V_77 ) ;
F_56 ( & V_67 , & V_27 -> V_75 ) ;
V_27 -> V_85 -= V_73 ;
F_19 ( & V_27 -> V_77 ) ;
return V_74 ;
}
static long F_57 ( struct V_11 * V_12 ,
struct V_64 * V_65 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
if ( ! F_58 ( V_27 -> V_85 ) )
return V_76 ;
return F_41 ( V_27 , V_65 , 0 ) ;
}
static long F_59 ( struct V_11 * V_12 ,
struct V_64 * V_65 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
return F_58 ( V_27 -> V_85 ) ;
}
static unsigned long F_41 ( struct V_10 * V_27 ,
struct V_64 * V_65 , unsigned long V_66 )
{
return 0 ;
}
static int F_60 ( struct V_5 * V_5 ,
struct V_44 * V_45 ,
T_1 V_4 , void * V_46 )
{
int error , V_86 = F_61 ( V_5 ) ;
F_62 ( F_63 ( V_5 ) , V_5 ) ;
F_62 ( V_4 != F_64 ( V_4 , V_86 ) , V_5 ) ;
F_62 ( ! F_65 ( V_5 ) , V_5 ) ;
F_62 ( ! F_66 ( V_5 ) , V_5 ) ;
F_31 ( V_46 && F_52 ( V_5 ) ) ;
F_67 ( V_5 , V_86 ) ;
V_5 -> V_45 = V_45 ;
V_5 -> V_4 = V_4 ;
F_68 ( & V_45 -> V_87 ) ;
if ( F_52 ( V_5 ) ) {
void T_4 * * V_88 ;
T_1 V_89 ;
int V_90 ;
error = 0 ;
if ( F_69 ( & V_45 -> V_52 ,
& V_88 , & V_89 , V_4 , 1 ) &&
V_89 < V_4 + V_91 ) {
error = - V_92 ;
}
if ( ! error ) {
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
error = F_70 ( & V_45 -> V_52 ,
V_4 + V_90 , V_5 + V_90 ) ;
F_31 ( error ) ;
}
F_71 ( V_93 ) ;
}
} else if ( ! V_46 ) {
error = F_70 ( & V_45 -> V_52 , V_4 , V_5 ) ;
} else {
error = F_30 ( V_45 , V_4 , V_46 ,
V_5 ) ;
}
if ( ! error ) {
V_45 -> V_37 += V_86 ;
if ( F_52 ( V_5 ) )
F_72 ( V_5 , V_94 ) ;
F_73 ( F_74 ( V_5 ) , V_95 , V_86 ) ;
F_73 ( F_74 ( V_5 ) , V_96 , V_86 ) ;
F_75 ( & V_45 -> V_87 ) ;
} else {
V_5 -> V_45 = NULL ;
F_75 ( & V_45 -> V_87 ) ;
F_76 ( V_5 , V_86 ) ;
}
return error ;
}
static void F_77 ( struct V_5 * V_5 , void * V_97 )
{
struct V_44 * V_45 = V_5 -> V_45 ;
int error ;
F_62 ( F_78 ( V_5 ) , V_5 ) ;
F_68 ( & V_45 -> V_87 ) ;
error = F_30 ( V_45 , V_5 -> V_4 , V_5 , V_97 ) ;
V_5 -> V_45 = NULL ;
V_45 -> V_37 -- ;
F_79 ( V_5 , V_95 ) ;
F_79 ( V_5 , V_96 ) ;
F_75 ( & V_45 -> V_87 ) ;
F_54 ( V_5 ) ;
F_80 ( error ) ;
}
static int F_81 ( struct V_44 * V_45 ,
T_1 V_4 , void * V_97 )
{
void * V_98 ;
F_68 ( & V_45 -> V_87 ) ;
V_98 = F_82 ( & V_45 -> V_52 , V_4 , V_97 ) ;
F_75 ( & V_45 -> V_87 ) ;
if ( V_98 != V_97 )
return - V_53 ;
F_83 ( F_84 ( V_97 ) ) ;
return 0 ;
}
unsigned long F_85 ( struct V_44 * V_45 ,
T_1 V_99 , T_1 V_100 )
{
struct V_101 V_102 ;
void * * V_103 ;
struct V_5 * V_5 ;
unsigned long V_36 = 0 ;
F_35 () ;
F_86 (slot, &mapping->page_tree, &iter, start) {
if ( V_102 . V_4 >= V_100 )
break;
V_5 = F_87 ( V_103 ) ;
if ( F_88 ( V_5 ) ) {
V_103 = F_89 ( & V_102 ) ;
continue;
}
if ( F_90 ( V_5 ) )
V_36 ++ ;
if ( F_91 () ) {
V_103 = F_92 ( V_103 , & V_102 ) ;
F_93 () ;
}
}
F_37 () ;
return V_36 << V_83 ;
}
unsigned long F_94 ( struct V_23 * V_24 )
{
struct V_3 * V_3 = F_95 ( V_24 -> V_104 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_44 * V_45 = V_3 -> V_9 ;
unsigned long V_36 ;
V_36 = F_58 ( V_33 -> V_36 ) ;
if ( ! V_36 )
return 0 ;
if ( ! V_24 -> V_105 && V_24 -> V_106 - V_24 -> V_107 >= V_3 -> V_79 )
return V_36 << V_83 ;
return F_85 ( V_45 ,
F_96 ( V_24 , V_24 -> V_107 ) ,
F_96 ( V_24 , V_24 -> V_106 ) ) ;
}
void F_97 ( struct V_44 * V_45 )
{
struct V_108 V_109 ;
T_1 V_110 [ V_111 ] ;
T_1 V_4 = 0 ;
F_98 ( & V_109 , 0 ) ;
while ( ! F_99 ( V_45 ) ) {
V_109 . V_86 = F_100 ( V_45 , V_4 ,
V_111 , V_109 . V_21 , V_110 ) ;
if ( ! V_109 . V_86 )
break;
V_4 = V_110 [ V_109 . V_86 - 1 ] + 1 ;
F_101 ( & V_109 ) ;
F_102 ( V_109 . V_21 , V_109 . V_86 ) ;
F_103 ( & V_109 ) ;
F_104 () ;
}
}
static void F_105 ( struct V_3 * V_3 , T_2 V_112 , T_2 V_113 ,
bool V_114 )
{
struct V_44 * V_45 = V_3 -> V_9 ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
T_1 V_99 = ( V_112 + V_22 - 1 ) >> V_83 ;
T_1 V_100 = ( V_113 + 1 ) >> V_83 ;
unsigned int V_115 = V_112 & ( V_22 - 1 ) ;
unsigned int V_116 = ( V_113 + 1 ) & ( V_22 - 1 ) ;
struct V_108 V_109 ;
T_1 V_110 [ V_111 ] ;
long V_117 = 0 ;
T_1 V_4 ;
int V_90 ;
if ( V_113 == - 1 )
V_100 = - 1 ;
F_98 ( & V_109 , 0 ) ;
V_4 = V_99 ;
while ( V_4 < V_100 ) {
V_109 . V_86 = F_100 ( V_45 , V_4 ,
F_3 ( V_100 - V_4 , ( T_1 ) V_111 ) ,
V_109 . V_21 , V_110 ) ;
if ( ! V_109 . V_86 )
break;
for ( V_90 = 0 ; V_90 < F_106 ( & V_109 ) ; V_90 ++ ) {
struct V_5 * V_5 = V_109 . V_21 [ V_90 ] ;
V_4 = V_110 [ V_90 ] ;
if ( V_4 >= V_100 )
break;
if ( F_90 ( V_5 ) ) {
if ( V_114 )
continue;
V_117 += ! F_81 ( V_45 ,
V_4 , V_5 ) ;
continue;
}
F_62 ( F_107 ( V_5 ) != V_4 , V_5 ) ;
if ( ! F_108 ( V_5 ) )
continue;
if ( F_109 ( V_5 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
continue;
} else if ( F_52 ( V_5 ) ) {
if ( V_4 == F_64 ( V_100 , V_91 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
continue;
}
V_4 += V_91 - 1 ;
V_90 += V_91 - 1 ;
}
if ( ! V_114 || ! F_111 ( V_5 ) ) {
F_62 ( F_63 ( V_5 ) , V_5 ) ;
if ( F_112 ( V_5 ) == V_45 ) {
F_62 ( F_113 ( V_5 ) , V_5 ) ;
F_114 ( V_45 , V_5 ) ;
}
}
F_53 ( V_5 ) ;
}
F_101 ( & V_109 ) ;
F_103 ( & V_109 ) ;
F_104 () ;
V_4 ++ ;
}
if ( V_115 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_99 - 1 , & V_5 , V_118 ) ;
if ( V_5 ) {
unsigned int V_119 = V_22 ;
if ( V_99 > V_100 ) {
V_119 = V_116 ;
V_116 = 0 ;
}
F_115 ( V_5 , V_115 , V_119 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
}
if ( V_116 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_100 , & V_5 , V_118 ) ;
if ( V_5 ) {
F_115 ( V_5 , 0 , V_116 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
}
if ( V_99 >= V_100 )
return;
V_4 = V_99 ;
while ( V_4 < V_100 ) {
F_104 () ;
V_109 . V_86 = F_100 ( V_45 , V_4 ,
F_3 ( V_100 - V_4 , ( T_1 ) V_111 ) ,
V_109 . V_21 , V_110 ) ;
if ( ! V_109 . V_86 ) {
if ( V_4 == V_99 || V_100 != - 1 )
break;
V_4 = V_99 ;
continue;
}
for ( V_90 = 0 ; V_90 < F_106 ( & V_109 ) ; V_90 ++ ) {
struct V_5 * V_5 = V_109 . V_21 [ V_90 ] ;
V_4 = V_110 [ V_90 ] ;
if ( V_4 >= V_100 )
break;
if ( F_90 ( V_5 ) ) {
if ( V_114 )
continue;
if ( F_81 ( V_45 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_117 ++ ;
continue;
}
F_117 ( V_5 ) ;
if ( F_109 ( V_5 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
if ( V_4 != F_64 ( V_100 , V_91 ) )
V_99 ++ ;
continue;
} else if ( F_52 ( V_5 ) ) {
if ( V_4 == F_64 ( V_100 , V_91 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
continue;
}
V_4 += V_91 - 1 ;
V_90 += V_91 - 1 ;
}
if ( ! V_114 || ! F_111 ( V_5 ) ) {
F_62 ( F_63 ( V_5 ) , V_5 ) ;
if ( F_112 ( V_5 ) == V_45 ) {
F_62 ( F_113 ( V_5 ) , V_5 ) ;
F_114 ( V_45 , V_5 ) ;
} else {
F_53 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_53 ( V_5 ) ;
}
F_101 ( & V_109 ) ;
F_103 ( & V_109 ) ;
V_4 ++ ;
}
F_68 ( & V_33 -> V_43 ) ;
V_33 -> V_36 -= V_117 ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
}
void F_118 ( struct V_3 * V_3 , T_2 V_112 , T_2 V_113 )
{
F_105 ( V_3 , V_112 , V_113 , false ) ;
V_3 -> V_120 = V_3 -> V_121 = F_119 ( V_3 ) ;
}
static int F_120 ( const struct V_122 * V_122 , struct V_123 * V_124 ,
T_5 V_125 , unsigned int V_126 )
{
struct V_3 * V_3 = V_122 -> V_127 -> V_128 ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
if ( V_33 -> V_35 - V_33 -> V_36 != V_3 -> V_9 -> V_37 ) {
F_68 ( & V_33 -> V_43 ) ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
}
F_121 ( V_3 , V_124 ) ;
return 0 ;
}
static int F_122 ( struct V_127 * V_127 , struct V_129 * V_130 )
{
struct V_3 * V_3 = V_128 ( V_127 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
int error ;
error = F_123 ( V_127 , V_130 ) ;
if ( error )
return error ;
if ( F_124 ( V_3 -> V_131 ) && ( V_130 -> V_132 & V_133 ) ) {
T_2 V_19 = V_3 -> V_79 ;
T_2 V_20 = V_130 -> V_134 ;
if ( ( V_20 < V_19 && ( V_33 -> V_135 & V_136 ) ) ||
( V_20 > V_19 && ( V_33 -> V_135 & V_137 ) ) )
return - V_138 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_22 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_125 ( V_3 , V_20 ) ;
V_3 -> V_120 = V_3 -> V_121 = F_119 ( V_3 ) ;
}
if ( V_20 <= V_19 ) {
T_2 V_139 = F_48 ( V_20 , V_22 ) ;
if ( V_19 > V_139 )
F_126 ( V_3 -> V_9 ,
V_139 , 0 , 1 ) ;
if ( V_33 -> V_35 )
F_118 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_139 )
F_126 ( V_3 -> V_9 ,
V_139 , 0 , 1 ) ;
if ( F_127 ( V_140 ) ) {
F_18 ( & V_27 -> V_77 ) ;
if ( F_128 ( & V_33 -> V_75 ) ) {
F_129 ( & V_33 -> V_75 ,
& V_27 -> V_75 ) ;
V_27 -> V_85 ++ ;
}
F_19 ( & V_27 -> V_77 ) ;
}
}
}
F_130 ( V_3 , V_130 ) ;
if ( V_130 -> V_132 & V_141 )
error = F_131 ( V_3 , V_3 -> V_131 ) ;
return error ;
}
static void F_132 ( struct V_3 * V_3 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
if ( V_3 -> V_9 -> V_142 == & V_143 ) {
F_11 ( V_33 -> V_14 , V_3 -> V_79 ) ;
V_3 -> V_79 = 0 ;
F_118 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_43 ( & V_33 -> V_75 ) ) {
F_18 ( & V_27 -> V_77 ) ;
if ( ! F_43 ( & V_33 -> V_75 ) ) {
F_47 ( & V_33 -> V_75 ) ;
V_27 -> V_85 -- ;
}
F_19 ( & V_27 -> V_77 ) ;
}
if ( ! F_43 ( & V_33 -> V_144 ) ) {
F_133 ( & V_145 ) ;
F_47 ( & V_33 -> V_144 ) ;
F_134 ( & V_145 ) ;
}
}
F_135 ( & V_33 -> V_146 ) ;
F_136 ( V_3 -> V_41 ) ;
F_20 ( V_3 -> V_38 ) ;
F_137 ( V_3 ) ;
}
static unsigned long F_138 ( struct V_147 * V_148 , void * V_51 )
{
struct V_101 V_102 ;
void * * V_103 ;
unsigned long V_149 = - 1 ;
unsigned int V_150 = 0 ;
F_35 () ;
F_86 (slot, root, &iter, 0 ) {
if ( * V_103 == V_51 ) {
V_149 = V_102 . V_4 ;
break;
}
V_150 ++ ;
if ( ( V_150 % 4096 ) != 0 )
continue;
V_103 = F_92 ( V_103 , & V_102 ) ;
F_93 () ;
}
F_37 () ;
return V_149 ;
}
static int F_139 ( struct V_32 * V_33 ,
T_3 V_54 , struct V_5 * * V_6 )
{
struct V_44 * V_45 = V_33 -> V_78 . V_9 ;
void * V_97 ;
T_1 V_4 ;
T_6 V_151 ;
int error = 0 ;
V_97 = F_38 ( V_54 ) ;
V_4 = F_138 ( & V_45 -> V_52 , V_97 ) ;
if ( V_4 == - 1 )
return - V_152 ;
if ( V_153 . V_69 != & V_33 -> V_144 )
F_140 ( & V_153 , & V_33 -> V_144 ) ;
V_151 = F_6 ( V_45 ) ;
if ( F_141 ( * V_6 , V_151 ) ) {
F_134 ( & V_145 ) ;
error = F_142 ( V_6 , V_151 , V_33 , V_4 ) ;
F_133 ( & V_145 ) ;
if ( ! F_143 ( * V_6 ) )
error = - V_53 ;
}
if ( ! error )
error = F_60 ( * V_6 , V_45 , V_4 ,
V_97 ) ;
if ( error != - V_154 ) {
F_144 ( * V_6 ) ;
F_116 ( * V_6 ) ;
if ( ! error ) {
F_68 ( & V_33 -> V_43 ) ;
V_33 -> V_36 -- ;
F_75 ( & V_33 -> V_43 ) ;
F_145 ( V_54 ) ;
}
}
return error ;
}
int F_146 ( T_3 V_54 , struct V_5 * V_5 )
{
struct V_155 * V_156 , * V_69 ;
struct V_32 * V_33 ;
struct V_157 * V_158 ;
int error = 0 ;
if ( F_147 ( ! F_148 ( V_5 ) || F_149 ( V_5 ) != V_54 . V_159 ) )
goto V_160;
error = F_150 ( V_5 , V_17 -> V_18 , V_161 , & V_158 ,
false ) ;
if ( error )
goto V_160;
error = - V_152 ;
F_133 ( & V_145 ) ;
F_44 (this, next, &shmem_swaplist) {
V_33 = F_45 ( V_156 , struct V_32 , V_144 ) ;
if ( V_33 -> V_36 )
error = F_139 ( V_33 , V_54 , & V_5 ) ;
else
F_47 ( & V_33 -> V_144 ) ;
F_104 () ;
if ( error != - V_152 )
break;
}
F_134 ( & V_145 ) ;
if ( error ) {
if ( error != - V_154 )
error = 0 ;
F_151 ( V_5 , V_158 , false ) ;
} else
F_152 ( V_5 , V_158 , true , false ) ;
V_160:
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return error ;
}
static int F_153 ( struct V_5 * V_5 , struct V_162 * V_163 )
{
struct V_32 * V_33 ;
struct V_44 * V_45 ;
struct V_3 * V_3 ;
T_3 V_54 ;
T_1 V_4 ;
F_62 ( F_78 ( V_5 ) , V_5 ) ;
F_80 ( ! F_65 ( V_5 ) ) ;
V_45 = V_5 -> V_45 ;
V_4 = V_5 -> V_4 ;
V_3 = V_45 -> V_164 ;
V_33 = F_22 ( V_3 ) ;
if ( V_33 -> V_14 & V_165 )
goto V_166;
if ( ! V_167 )
goto V_166;
if ( ! V_163 -> V_168 ) {
F_154 ( 1 ) ;
goto V_166;
}
if ( ! F_111 ( V_5 ) ) {
if ( V_3 -> V_169 ) {
struct V_170 * V_170 ;
F_18 ( & V_3 -> V_171 ) ;
V_170 = V_3 -> V_169 ;
if ( V_170 &&
! V_170 -> V_172 &&
V_4 >= V_170 -> V_99 &&
V_4 < V_170 -> V_69 )
V_170 -> V_173 ++ ;
else
V_170 = NULL ;
F_19 ( & V_3 -> V_171 ) ;
if ( V_170 )
goto V_166;
}
F_110 ( V_5 ) ;
F_155 ( V_5 ) ;
F_156 ( V_5 ) ;
}
V_54 = F_157 ( V_5 ) ;
if ( ! V_54 . V_159 )
goto V_166;
if ( F_158 ( V_5 , V_54 ) )
goto V_174;
F_133 ( & V_145 ) ;
if ( F_43 ( & V_33 -> V_144 ) )
F_129 ( & V_33 -> V_144 , & V_153 ) ;
if ( F_159 ( V_5 , V_54 , V_175 ) == 0 ) {
F_68 ( & V_33 -> V_43 ) ;
F_21 ( V_3 ) ;
V_33 -> V_36 ++ ;
F_75 ( & V_33 -> V_43 ) ;
F_160 ( V_54 ) ;
F_77 ( V_5 , F_38 ( V_54 ) ) ;
F_134 ( & V_145 ) ;
F_80 ( F_161 ( V_5 ) ) ;
F_162 ( V_5 , V_163 ) ;
return 0 ;
}
F_134 ( & V_145 ) ;
V_174:
F_163 ( V_5 , V_54 ) ;
V_166:
F_116 ( V_5 ) ;
if ( V_163 -> V_168 )
return V_176 ;
F_53 ( V_5 ) ;
return 0 ;
}
static void F_164 ( struct V_177 * V_178 , struct V_179 * V_180 )
{
char V_181 [ 64 ] ;
if ( ! V_180 || V_180 -> V_182 == V_183 )
return;
F_165 ( V_181 , sizeof( V_181 ) , V_180 ) ;
F_166 ( V_178 , L_8 , V_181 ) ;
}
static struct V_179 * F_167 ( struct V_10 * V_27 )
{
struct V_179 * V_180 = NULL ;
if ( V_27 -> V_180 ) {
F_18 ( & V_27 -> V_29 ) ;
V_180 = V_27 -> V_180 ;
F_168 ( V_180 ) ;
F_19 ( & V_27 -> V_29 ) ;
}
return V_180 ;
}
static inline void F_164 ( struct V_177 * V_178 , struct V_179 * V_180 )
{
}
static inline struct V_179 * F_167 ( struct V_10 * V_27 )
{
return NULL ;
}
static void F_169 ( struct V_23 * V_24 ,
struct V_32 * V_33 , T_1 V_4 )
{
V_24 -> V_107 = 0 ;
V_24 -> V_105 = V_4 + V_33 -> V_78 . V_184 ;
V_24 -> V_25 = NULL ;
V_24 -> V_185 = F_170 ( & V_33 -> V_186 , V_4 ) ;
}
static void F_171 ( struct V_23 * V_24 )
{
F_172 ( V_24 -> V_185 ) ;
}
static struct V_5 * F_173 ( T_3 V_54 , T_6 V_151 ,
struct V_32 * V_33 , T_1 V_4 )
{
struct V_23 V_187 ;
struct V_5 * V_5 ;
F_169 ( & V_187 , V_33 , V_4 ) ;
V_5 = F_174 ( V_54 , V_151 , & V_187 , 0 ) ;
F_171 ( & V_187 ) ;
return V_5 ;
}
static struct V_5 * F_175 ( T_6 V_151 ,
struct V_32 * V_33 , T_1 V_4 )
{
struct V_23 V_187 ;
struct V_3 * V_3 = & V_33 -> V_78 ;
struct V_44 * V_45 = V_3 -> V_9 ;
T_1 V_89 , V_188 ;
void T_4 * * V_88 ;
struct V_5 * V_5 ;
if ( ! F_127 ( V_140 ) )
return NULL ;
V_188 = F_64 ( V_4 , V_91 ) ;
F_35 () ;
if ( F_69 ( & V_45 -> V_52 , & V_88 , & V_89 ,
V_188 , 1 ) && V_89 < V_188 + V_91 ) {
F_37 () ;
return NULL ;
}
F_37 () ;
F_169 ( & V_187 , V_33 , V_188 ) ;
V_5 = F_176 ( V_151 | V_189 | V_190 | V_191 ,
V_192 , & V_187 , 0 , F_177 () , true ) ;
F_171 ( & V_187 ) ;
if ( V_5 )
F_178 ( V_5 ) ;
return V_5 ;
}
static struct V_5 * F_179 ( T_6 V_151 ,
struct V_32 * V_33 , T_1 V_4 )
{
struct V_23 V_187 ;
struct V_5 * V_5 ;
F_169 ( & V_187 , V_33 , V_4 ) ;
V_5 = F_180 ( V_151 , & V_187 , 0 ) ;
F_171 ( & V_187 ) ;
return V_5 ;
}
static struct V_5 * F_181 ( T_6 V_151 ,
struct V_32 * V_33 , struct V_10 * V_27 ,
T_1 V_4 , bool V_63 )
{
struct V_5 * V_5 ;
int V_86 ;
int V_193 = - V_31 ;
if ( ! F_127 ( V_140 ) )
V_63 = false ;
V_86 = V_63 ? V_91 : 1 ;
if ( F_14 ( V_33 -> V_14 , V_86 ) )
goto V_194;
if ( V_27 -> V_39 ) {
if ( F_27 ( & V_27 -> V_40 ,
V_27 -> V_39 - V_86 ) > 0 )
goto V_195;
F_23 ( & V_27 -> V_40 , V_86 ) ;
}
if ( V_63 )
V_5 = F_175 ( V_151 , V_33 , V_4 ) ;
else
V_5 = F_179 ( V_151 , V_33 , V_4 ) ;
if ( V_5 ) {
F_182 ( V_5 ) ;
F_183 ( V_5 ) ;
return V_5 ;
}
V_193 = - V_154 ;
if ( V_27 -> V_39 )
F_23 ( & V_27 -> V_40 , - V_86 ) ;
V_195:
F_15 ( V_33 -> V_14 , V_86 ) ;
V_194:
return F_184 ( V_193 ) ;
}
static bool F_141 ( struct V_5 * V_5 , T_6 V_151 )
{
return F_185 ( V_5 ) > F_186 ( V_151 ) ;
}
static int F_142 ( struct V_5 * * V_6 , T_6 V_151 ,
struct V_32 * V_33 , T_1 V_4 )
{
struct V_5 * V_196 , * V_197 ;
struct V_44 * V_198 ;
T_1 V_199 ;
int error ;
V_196 = * V_6 ;
V_199 = F_149 ( V_196 ) ;
V_198 = F_112 ( V_196 ) ;
V_151 &= ~ V_200 ;
V_197 = F_179 ( V_151 , V_33 , V_4 ) ;
if ( ! V_197 )
return - V_154 ;
F_187 ( V_197 ) ;
F_188 ( V_197 , V_196 ) ;
F_155 ( V_197 ) ;
F_182 ( V_197 ) ;
F_183 ( V_197 ) ;
F_156 ( V_197 ) ;
F_189 ( V_197 , V_199 ) ;
F_190 ( V_197 ) ;
F_68 ( & V_198 -> V_87 ) ;
error = F_30 ( V_198 , V_199 , V_196 ,
V_197 ) ;
if ( ! error ) {
F_72 ( V_197 , V_95 ) ;
F_79 ( V_196 , V_95 ) ;
}
F_75 ( & V_198 -> V_87 ) ;
if ( F_147 ( error ) ) {
V_196 = V_197 ;
} else {
F_191 ( V_196 , V_197 ) ;
F_192 ( V_197 ) ;
* V_6 = V_197 ;
}
F_193 ( V_196 ) ;
F_189 ( V_196 , 0 ) ;
F_53 ( V_196 ) ;
F_54 ( V_196 ) ;
F_54 ( V_196 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_6 V_151 ,
struct V_23 * V_24 , struct V_201 * V_202 , int * V_203 )
{
struct V_44 * V_45 = V_3 -> V_9 ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 ;
struct V_204 * V_205 ;
struct V_157 * V_158 ;
struct V_5 * V_5 ;
T_3 V_54 ;
enum V_7 V_206 = V_8 ;
T_1 V_188 = V_4 ;
int error ;
int V_207 = 0 ;
int V_35 = 0 ;
if ( V_4 > ( V_208 >> V_83 ) )
return - V_209 ;
if ( V_8 == V_210 || V_8 == V_211 )
V_8 = V_212 ;
V_213:
V_54 . V_159 = 0 ;
V_5 = F_194 ( V_45 , V_4 ) ;
if ( F_90 ( V_5 ) ) {
V_54 = F_84 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_212 &&
( ( T_2 ) V_4 << V_83 ) >= F_195 ( V_3 ) ) {
error = - V_62 ;
goto V_214;
}
if ( V_5 && V_8 == V_215 )
F_196 ( V_5 ) ;
if ( V_5 && ! F_111 ( V_5 ) ) {
if ( V_8 != V_118 )
goto V_216;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_118 && ! V_54 . V_159 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_27 = F_7 ( V_3 -> V_38 ) ;
V_205 = V_24 ? V_24 -> V_217 : V_17 -> V_18 ;
if ( V_54 . V_159 ) {
V_5 = F_197 ( V_54 ) ;
if ( ! V_5 ) {
if ( V_203 ) {
* V_203 |= V_218 ;
F_71 ( V_219 ) ;
F_198 ( V_205 , V_219 ) ;
}
V_5 = F_173 ( V_54 , V_151 , V_33 , V_4 ) ;
if ( ! V_5 ) {
error = - V_154 ;
goto V_194;
}
}
F_117 ( V_5 ) ;
if ( ! F_148 ( V_5 ) || F_149 ( V_5 ) != V_54 . V_159 ||
! F_34 ( V_45 , V_4 , V_54 ) ) {
error = - V_92 ;
goto V_214;
}
if ( ! F_111 ( V_5 ) ) {
error = - V_220 ;
goto V_194;
}
F_199 ( V_5 ) ;
if ( F_141 ( V_5 , V_151 ) ) {
error = F_142 ( & V_5 , V_151 , V_33 , V_4 ) ;
if ( error )
goto V_194;
}
error = F_150 ( V_5 , V_205 , V_151 , & V_158 ,
false ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_45 , V_4 ,
F_38 ( V_54 ) ) ;
if ( error ) {
F_151 ( V_5 , V_158 , false ) ;
F_144 ( V_5 ) ;
}
}
if ( error )
goto V_194;
F_152 ( V_5 , V_158 , true , false ) ;
F_68 ( & V_33 -> V_43 ) ;
V_33 -> V_36 -- ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
if ( V_8 == V_215 )
F_196 ( V_5 ) ;
F_144 ( V_5 ) ;
F_116 ( V_5 ) ;
F_145 ( V_54 ) ;
} else {
if ( V_24 && F_200 ( V_24 ) ) {
* V_203 = F_201 ( V_202 , V_221 ) ;
return 0 ;
}
if ( V_45 -> V_142 != & V_143 )
goto V_222;
if ( V_223 == V_60 || V_206 == V_210 )
goto V_222;
if ( V_223 == V_61 )
goto V_224;
switch ( V_27 -> V_63 ) {
T_2 V_79 ;
T_1 V_225 ;
case V_56 :
goto V_222;
case V_58 :
V_225 = F_48 ( V_4 , V_91 ) ;
V_79 = F_48 ( F_195 ( V_3 ) , V_22 ) ;
if ( V_79 >= V_80 &&
V_79 >> V_83 >= V_225 )
goto V_224;
case V_59 :
if ( V_206 == V_211 )
goto V_224;
goto V_222;
}
V_224:
V_5 = F_181 ( V_151 , V_33 , V_27 ,
V_4 , true ) ;
if ( F_202 ( V_5 ) ) {
V_222: V_5 = F_181 ( V_151 , V_33 , V_27 ,
V_4 , false ) ;
}
if ( F_202 ( V_5 ) ) {
int V_226 = 5 ;
error = F_203 ( V_5 ) ;
V_5 = NULL ;
if ( error != - V_31 )
goto V_194;
while ( V_226 -- ) {
int V_81 ;
V_81 = F_41 ( V_27 , NULL , 1 ) ;
if ( V_81 == V_76 )
break;
if ( V_81 )
goto V_222;
}
goto V_194;
}
if ( F_52 ( V_5 ) )
V_188 = F_64 ( V_4 , V_91 ) ;
else
V_188 = V_4 ;
if ( V_8 == V_215 )
F_204 ( V_5 ) ;
error = F_150 ( V_5 , V_205 , V_151 , & V_158 ,
F_52 ( V_5 ) ) ;
if ( error )
goto V_195;
error = F_205 ( V_151 & V_227 ,
F_206 ( V_5 ) ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_45 , V_188 ,
NULL ) ;
F_207 () ;
}
if ( error ) {
F_151 ( V_5 , V_158 ,
F_52 ( V_5 ) ) ;
goto V_195;
}
F_152 ( V_5 , V_158 , false ,
F_52 ( V_5 ) ) ;
F_192 ( V_5 ) ;
F_68 ( & V_33 -> V_43 ) ;
V_33 -> V_35 += 1 << F_206 ( V_5 ) ;
V_3 -> V_41 += V_42 << F_206 ( V_5 ) ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
V_35 = true ;
if ( F_52 ( V_5 ) &&
F_208 ( F_195 ( V_3 ) , V_22 ) <
V_188 + V_91 - 1 ) {
F_18 ( & V_27 -> V_77 ) ;
if ( F_128 ( & V_33 -> V_75 ) ) {
F_129 ( & V_33 -> V_75 ,
& V_27 -> V_75 ) ;
V_27 -> V_85 ++ ;
}
F_19 ( & V_27 -> V_77 ) ;
}
if ( V_8 == V_228 )
V_8 = V_215 ;
V_216:
if ( V_8 != V_215 && ! F_111 ( V_5 ) ) {
struct V_5 * V_229 = F_209 ( V_5 ) ;
int V_90 ;
for ( V_90 = 0 ; V_90 < ( 1 << F_206 ( V_229 ) ) ; V_90 ++ ) {
F_110 ( V_229 + V_90 ) ;
F_155 ( V_229 + V_90 ) ;
}
F_156 ( V_229 ) ;
}
}
if ( V_8 <= V_212 &&
( ( T_2 ) V_4 << V_83 ) >= F_195 ( V_3 ) ) {
if ( V_35 ) {
F_210 ( V_5 ) ;
F_211 ( V_5 ) ;
F_68 ( & V_33 -> V_43 ) ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
}
error = - V_62 ;
goto V_214;
}
* V_6 = V_5 + V_4 - V_188 ;
return 0 ;
V_195:
if ( V_27 -> V_39 )
F_29 ( & V_27 -> V_40 ,
1 << F_206 ( V_5 ) ) ;
F_15 ( V_33 -> V_14 , 1 << F_206 ( V_5 ) ) ;
if ( F_52 ( V_5 ) ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
goto V_222;
}
V_194:
if ( V_54 . V_159 && ! F_34 ( V_45 , V_4 , V_54 ) )
error = - V_92 ;
V_214:
if ( V_5 ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
if ( error == - V_31 && ! V_207 ++ ) {
F_68 ( & V_33 -> V_43 ) ;
F_21 ( V_3 ) ;
F_75 ( & V_33 -> V_43 ) ;
goto V_213;
}
if ( error == - V_92 )
goto V_213;
return error ;
}
static int F_212 ( T_7 * V_230 , unsigned V_182 , int V_231 , void * V_232 )
{
int V_81 = F_213 ( V_230 , V_182 , V_231 , V_232 ) ;
F_47 ( & V_230 -> V_233 ) ;
return V_81 ;
}
static int F_214 ( struct V_201 * V_202 )
{
struct V_23 * V_24 = V_202 -> V_24 ;
struct V_3 * V_3 = F_95 ( V_24 -> V_104 ) ;
T_6 V_151 = F_6 ( V_3 -> V_9 ) ;
enum V_7 V_8 ;
int error ;
int V_81 = V_234 ;
if ( F_147 ( V_3 -> V_169 ) ) {
struct V_170 * V_170 ;
F_18 ( & V_3 -> V_171 ) ;
V_170 = V_3 -> V_169 ;
if ( V_170 &&
V_170 -> V_172 &&
V_202 -> V_235 >= V_170 -> V_99 &&
V_202 -> V_235 < V_170 -> V_69 ) {
T_8 * V_236 ;
F_215 ( V_237 , F_212 ) ;
V_81 = V_238 ;
if ( ( V_202 -> V_14 & V_239 ) &&
! ( V_202 -> V_14 & V_240 ) ) {
F_216 ( & V_24 -> V_217 -> V_241 ) ;
V_81 = V_242 ;
}
V_236 = V_170 -> V_172 ;
F_217 ( V_236 , & V_237 ,
V_243 ) ;
F_19 ( & V_3 -> V_171 ) ;
F_218 () ;
F_18 ( & V_3 -> V_171 ) ;
F_219 ( V_236 , & V_237 ) ;
F_19 ( & V_3 -> V_171 ) ;
return V_81 ;
}
F_19 ( & V_3 -> V_171 ) ;
}
V_8 = V_212 ;
if ( ( V_24 -> V_244 & V_245 ) ||
F_220 ( V_246 , & V_24 -> V_217 -> V_14 ) )
V_8 = V_210 ;
else if ( V_24 -> V_244 & V_247 )
V_8 = V_211 ;
error = F_5 ( V_3 , V_202 -> V_235 , & V_202 -> V_5 , V_8 ,
V_151 , V_24 , V_202 , & V_81 ) ;
if ( error )
return ( ( error == - V_154 ) ? V_248 : V_249 ) ;
return V_81 ;
}
unsigned long F_221 ( struct V_250 * V_250 ,
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
return - V_154 ;
V_253 = V_17 -> V_18 -> V_260 ;
V_254 = V_253 ( V_250 , V_251 , V_252 , V_235 , V_14 ) ;
if ( ! F_127 ( V_140 ) )
return V_254 ;
if ( F_222 ( V_254 ) )
return V_254 ;
if ( V_254 & ~ V_261 )
return V_254 ;
if ( V_254 > V_259 - V_252 )
return V_254 ;
if ( V_223 == V_60 )
return V_254 ;
if ( V_252 < V_80 )
return V_254 ;
if ( V_14 & V_262 )
return V_254 ;
if ( V_251 )
return V_254 ;
if ( V_223 != V_61 ) {
struct V_11 * V_12 ;
if ( V_250 ) {
F_31 ( V_250 -> V_263 != & V_264 ) ;
V_12 = F_95 ( V_250 ) -> V_38 ;
} else {
if ( F_202 ( V_265 ) )
return V_254 ;
V_12 = V_265 -> V_266 ;
}
if ( F_7 ( V_12 ) -> V_63 == V_56 )
return V_254 ;
}
V_255 = ( V_235 << V_83 ) & ( V_80 - 1 ) ;
if ( V_255 && V_255 + V_252 < 2 * V_80 )
return V_254 ;
if ( ( V_254 & ( V_80 - 1 ) ) == V_255 )
return V_254 ;
V_256 = V_252 + V_80 - V_22 ;
if ( V_256 > V_259 )
return V_254 ;
if ( V_256 < V_252 )
return V_254 ;
V_257 = V_253 ( NULL , 0 , V_256 , 0 , V_14 ) ;
if ( F_222 ( V_257 ) )
return V_254 ;
if ( V_257 & ~ V_261 )
return V_254 ;
V_258 = V_257 & ( V_80 - 1 ) ;
V_257 += V_255 - V_258 ;
if ( V_258 > V_255 )
V_257 += V_80 ;
if ( V_257 > V_259 - V_252 )
return V_254 ;
return V_257 ;
}
static int F_223 ( struct V_23 * V_24 , struct V_179 * V_180 )
{
struct V_3 * V_3 = F_95 ( V_24 -> V_104 ) ;
return F_224 ( & F_22 ( V_3 ) -> V_186 , V_24 , V_180 ) ;
}
static struct V_179 * F_225 ( struct V_23 * V_24 ,
unsigned long V_254 )
{
struct V_3 * V_3 = F_95 ( V_24 -> V_104 ) ;
T_1 V_4 ;
V_4 = ( ( V_254 - V_24 -> V_107 ) >> V_83 ) + V_24 -> V_105 ;
return F_170 ( & F_22 ( V_3 ) -> V_186 , V_4 ) ;
}
int F_226 ( struct V_250 * V_250 , int V_43 , struct V_267 * V_268 )
{
struct V_3 * V_3 = F_95 ( V_250 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
int V_269 = - V_154 ;
F_68 ( & V_33 -> V_43 ) ;
if ( V_43 && ! ( V_33 -> V_14 & V_165 ) ) {
if ( ! F_227 ( V_3 -> V_79 , V_268 ) )
goto V_270;
V_33 -> V_14 |= V_165 ;
F_228 ( V_250 -> V_271 ) ;
}
if ( ! V_43 && ( V_33 -> V_14 & V_165 ) && V_268 ) {
F_229 ( V_3 -> V_79 , V_268 ) ;
V_33 -> V_14 &= ~ V_165 ;
F_230 ( V_250 -> V_271 ) ;
}
V_269 = 0 ;
V_270:
F_75 ( & V_33 -> V_43 ) ;
return V_269 ;
}
static int F_231 ( struct V_250 * V_250 , struct V_23 * V_24 )
{
F_232 ( V_250 ) ;
V_24 -> V_25 = & V_26 ;
if ( F_127 ( V_140 ) &&
( ( V_24 -> V_107 + ~ V_82 ) & V_82 ) <
( V_24 -> V_106 & V_82 ) ) {
F_233 ( V_24 , V_24 -> V_244 ) ;
}
return 0 ;
}
static struct V_3 * F_234 ( struct V_11 * V_12 , const struct V_3 * V_272 ,
T_9 V_182 , T_10 V_273 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_32 * V_33 ;
struct V_10 * V_27 = F_7 ( V_12 ) ;
if ( F_17 ( V_12 ) )
return NULL ;
V_3 = F_235 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_184 = F_236 () ;
F_237 ( V_3 , V_272 , V_182 ) ;
V_3 -> V_41 = 0 ;
V_3 -> V_274 = V_3 -> V_121 = V_3 -> V_120 = F_119 ( V_3 ) ;
V_3 -> V_275 = F_238 () ;
V_33 = F_22 ( V_3 ) ;
memset ( V_33 , 0 , ( char * ) V_3 - ( char * ) V_33 ) ;
F_239 ( & V_33 -> V_43 ) ;
V_33 -> V_135 = V_276 ;
V_33 -> V_14 = V_14 & V_16 ;
F_240 ( & V_33 -> V_75 ) ;
F_240 ( & V_33 -> V_144 ) ;
F_241 ( & V_33 -> V_146 ) ;
F_242 ( V_3 ) ;
switch ( V_182 & V_277 ) {
default:
V_3 -> V_278 = & V_279 ;
F_243 ( V_3 , V_182 , V_273 ) ;
break;
case V_280 :
V_3 -> V_9 -> V_142 = & V_143 ;
V_3 -> V_278 = & V_281 ;
V_3 -> V_282 = & V_264 ;
F_244 ( & V_33 -> V_186 ,
F_167 ( V_27 ) ) ;
break;
case V_283 :
F_245 ( V_3 ) ;
V_3 -> V_79 = 2 * V_284 ;
V_3 -> V_278 = & V_285 ;
V_3 -> V_282 = & V_286 ;
break;
case V_287 :
F_244 ( & V_33 -> V_186 , NULL ) ;
break;
}
} else
F_20 ( V_12 ) ;
return V_3 ;
}
bool F_246 ( struct V_44 * V_45 )
{
return V_45 -> V_142 == & V_143 ;
}
int F_247 ( struct V_204 * V_288 ,
T_11 * V_289 ,
struct V_23 * V_290 ,
unsigned long V_291 ,
unsigned long V_292 ,
struct V_5 * * V_6 )
{
struct V_3 * V_3 = F_95 ( V_290 -> V_104 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
struct V_44 * V_45 = V_3 -> V_9 ;
T_6 V_151 = F_6 ( V_45 ) ;
T_1 V_235 = F_96 ( V_290 , V_291 ) ;
struct V_157 * V_158 ;
T_12 * V_293 ;
void * V_294 ;
struct V_5 * V_5 ;
T_13 V_295 , * V_296 ;
int V_81 ;
V_81 = - V_154 ;
if ( F_14 ( V_33 -> V_14 , 1 ) )
goto V_160;
if ( V_27 -> V_39 ) {
if ( F_27 ( & V_27 -> V_40 ,
V_27 -> V_39 ) >= 0 )
goto V_297;
F_248 ( & V_27 -> V_40 ) ;
}
if ( ! * V_6 ) {
V_5 = F_179 ( V_151 , V_33 , V_235 ) ;
if ( ! V_5 )
goto V_298;
V_294 = F_249 ( V_5 ) ;
V_81 = F_250 ( V_294 , ( const void V_299 * ) V_292 ,
V_22 ) ;
F_251 ( V_294 ) ;
if ( F_147 ( V_81 ) ) {
* V_6 = V_5 ;
if ( V_27 -> V_39 )
F_23 ( & V_27 -> V_40 , - 1 ) ;
F_15 ( V_33 -> V_14 , 1 ) ;
return - V_300 ;
}
} else {
V_5 = * V_6 ;
* V_6 = NULL ;
}
F_31 ( F_65 ( V_5 ) || F_66 ( V_5 ) ) ;
F_182 ( V_5 ) ;
F_183 ( V_5 ) ;
F_252 ( V_5 ) ;
V_81 = F_150 ( V_5 , V_288 , V_151 , & V_158 , false ) ;
if ( V_81 )
goto V_301;
V_81 = F_253 ( V_151 & V_227 ) ;
if ( ! V_81 ) {
V_81 = F_60 ( V_5 , V_45 , V_235 , NULL ) ;
F_207 () ;
}
if ( V_81 )
goto V_302;
F_152 ( V_5 , V_158 , false , false ) ;
V_295 = F_254 ( V_5 , V_290 -> V_303 ) ;
if ( V_290 -> V_244 & V_304 )
V_295 = F_255 ( F_256 ( V_295 ) ) ;
V_81 = - V_92 ;
V_296 = F_257 ( V_288 , V_289 , V_291 , & V_293 ) ;
if ( ! F_258 ( * V_296 ) )
goto V_305;
F_192 ( V_5 ) ;
F_18 ( & V_33 -> V_43 ) ;
V_33 -> V_35 ++ ;
V_3 -> V_41 += V_42 ;
F_21 ( V_3 ) ;
F_19 ( & V_33 -> V_43 ) ;
F_259 ( V_288 , F_260 ( V_5 ) ) ;
F_261 ( V_5 , false ) ;
F_262 ( V_288 , V_291 , V_296 , V_295 ) ;
F_263 ( V_290 , V_291 , V_296 ) ;
F_53 ( V_5 ) ;
F_264 ( V_296 , V_293 ) ;
V_81 = 0 ;
V_160:
return V_81 ;
V_305:
F_264 ( V_296 , V_293 ) ;
V_302:
F_151 ( V_5 , V_158 , false ) ;
V_301:
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
V_298:
if ( V_27 -> V_39 )
F_23 ( & V_27 -> V_40 , - 1 ) ;
V_297:
F_15 ( V_33 -> V_14 , 1 ) ;
goto V_160;
}
static int
F_265 ( struct V_250 * V_250 , struct V_44 * V_45 ,
T_2 V_68 , unsigned V_252 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_306 )
{
struct V_3 * V_3 = V_45 -> V_164 ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
T_1 V_4 = V_68 >> V_83 ;
if ( F_147 ( V_33 -> V_135 & ( V_307 | V_137 ) ) ) {
if ( V_33 -> V_135 & V_307 )
return - V_138 ;
if ( ( V_33 -> V_135 & V_137 ) && V_68 + V_252 > V_3 -> V_79 )
return - V_138 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_215 ) ;
}
static int
F_266 ( struct V_250 * V_250 , struct V_44 * V_45 ,
T_2 V_68 , unsigned V_252 , unsigned V_308 ,
struct V_5 * V_5 , void * V_306 )
{
struct V_3 * V_3 = V_45 -> V_164 ;
if ( V_68 + V_308 > V_3 -> V_79 )
F_125 ( V_3 , V_68 + V_308 ) ;
if ( ! F_111 ( V_5 ) ) {
struct V_5 * V_229 = F_209 ( V_5 ) ;
if ( F_267 ( V_5 ) ) {
int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
if ( V_229 + V_90 == V_5 )
continue;
F_110 ( V_229 + V_90 ) ;
F_155 ( V_229 + V_90 ) ;
}
}
if ( V_308 < V_22 ) {
unsigned V_309 = V_68 & ( V_22 - 1 ) ;
F_268 ( V_5 , 0 , V_309 ,
V_309 + V_308 , V_22 ) ;
}
F_156 ( V_229 ) ;
}
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return V_308 ;
}
static T_14 F_269 ( struct V_310 * V_311 , struct V_312 * V_313 )
{
struct V_250 * V_250 = V_311 -> V_314 ;
struct V_3 * V_3 = F_95 ( V_250 ) ;
struct V_44 * V_45 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_255 ;
enum V_7 V_8 = V_118 ;
int error = 0 ;
T_14 V_269 = 0 ;
T_2 * V_315 = & V_311 -> V_316 ;
if ( ! F_270 ( V_313 ) )
V_8 = V_212 ;
V_4 = * V_315 >> V_83 ;
V_255 = * V_315 & ~ V_261 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_317 ;
unsigned long V_86 , V_81 ;
T_2 V_79 = F_195 ( V_3 ) ;
V_317 = V_79 >> V_83 ;
if ( V_4 > V_317 )
break;
if ( V_4 == V_317 ) {
V_86 = V_79 & ~ V_261 ;
if ( V_86 <= V_255 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_62 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_212 )
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
}
V_86 = V_22 ;
V_79 = F_195 ( V_3 ) ;
V_317 = V_79 >> V_83 ;
if ( V_4 == V_317 ) {
V_86 = V_79 & ~ V_261 ;
if ( V_86 <= V_255 ) {
if ( V_5 )
F_54 ( V_5 ) ;
break;
}
}
V_86 -= V_255 ;
if ( V_5 ) {
if ( F_271 ( V_45 ) )
F_155 ( V_5 ) ;
if ( ! V_255 )
F_196 ( V_5 ) ;
} else {
V_5 = F_272 ( 0 ) ;
F_187 ( V_5 ) ;
}
V_81 = F_273 ( V_5 , V_255 , V_86 , V_313 ) ;
V_269 += V_81 ;
V_255 += V_81 ;
V_4 += V_255 >> V_83 ;
V_255 &= ~ V_261 ;
F_54 ( V_5 ) ;
if ( ! F_274 ( V_313 ) )
break;
if ( V_81 < V_86 ) {
error = - V_300 ;
break;
}
F_104 () ;
}
* V_315 = ( ( T_2 ) V_4 << V_83 ) + V_255 ;
F_232 ( V_250 ) ;
return V_269 ? V_269 : error ;
}
static T_1 F_275 ( struct V_44 * V_45 ,
T_1 V_4 , T_1 V_100 , int V_318 )
{
struct V_5 * V_5 ;
struct V_108 V_109 ;
T_1 V_110 [ V_111 ] ;
bool V_319 = false ;
int V_90 ;
F_98 ( & V_109 , 0 ) ;
V_109 . V_86 = 1 ;
while ( ! V_319 ) {
V_109 . V_86 = F_100 ( V_45 , V_4 ,
V_109 . V_86 , V_109 . V_21 , V_110 ) ;
if ( ! V_109 . V_86 ) {
if ( V_318 == V_320 )
V_4 = V_100 ;
break;
}
for ( V_90 = 0 ; V_90 < V_109 . V_86 ; V_90 ++ , V_4 ++ ) {
if ( V_4 < V_110 [ V_90 ] ) {
if ( V_318 == V_321 ) {
V_319 = true ;
break;
}
V_4 = V_110 [ V_90 ] ;
}
V_5 = V_109 . V_21 [ V_90 ] ;
if ( V_5 && ! F_90 ( V_5 ) ) {
if ( ! F_111 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_100 ||
( V_5 && V_318 == V_320 ) ||
( ! V_5 && V_318 == V_321 ) ) {
V_319 = true ;
break;
}
}
F_101 ( & V_109 ) ;
F_103 ( & V_109 ) ;
V_109 . V_86 = V_111 ;
F_104 () ;
}
return V_4 ;
}
static T_2 F_276 ( struct V_250 * V_250 , T_2 V_255 , int V_318 )
{
struct V_44 * V_45 = V_250 -> V_271 ;
struct V_3 * V_3 = V_45 -> V_164 ;
T_1 V_99 , V_100 ;
T_2 V_322 ;
if ( V_318 != V_320 && V_318 != V_321 )
return F_277 ( V_250 , V_255 , V_318 ,
V_208 , F_195 ( V_3 ) ) ;
F_278 ( V_3 ) ;
if ( V_255 < 0 )
V_255 = - V_62 ;
else if ( V_255 >= V_3 -> V_79 )
V_255 = - V_323 ;
else {
V_99 = V_255 >> V_83 ;
V_100 = ( V_3 -> V_79 + V_22 - 1 ) >> V_83 ;
V_322 = F_275 ( V_45 , V_99 , V_100 , V_318 ) ;
V_322 <<= V_83 ;
if ( V_322 > V_255 ) {
if ( V_322 < V_3 -> V_79 )
V_255 = V_322 ;
else if ( V_318 == V_320 )
V_255 = - V_323 ;
else
V_255 = V_3 -> V_79 ;
}
}
if ( V_255 >= 0 )
V_255 = F_279 ( V_250 , V_255 , V_208 ) ;
F_280 ( V_3 ) ;
return V_255 ;
}
static void F_281 ( struct V_44 * V_45 )
{
struct V_101 V_102 ;
void * * V_103 ;
T_1 V_99 ;
struct V_5 * V_5 ;
F_282 () ;
V_99 = 0 ;
F_35 () ;
F_86 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_87 ( V_103 ) ;
if ( ! V_5 || F_283 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_103 = F_89 ( & V_102 ) ;
continue;
}
} else if ( F_284 ( V_5 ) - F_285 ( V_5 ) > 1 ) {
F_68 ( & V_45 -> V_87 ) ;
F_286 ( & V_45 -> V_52 , V_102 . V_4 ,
V_324 ) ;
F_75 ( & V_45 -> V_87 ) ;
}
if ( F_91 () ) {
V_103 = F_92 ( V_103 , & V_102 ) ;
F_93 () ;
}
}
F_37 () ;
}
static int F_287 ( struct V_44 * V_45 )
{
struct V_101 V_102 ;
void * * V_103 ;
T_1 V_99 ;
struct V_5 * V_5 ;
int error , V_325 ;
F_281 ( V_45 ) ;
error = 0 ;
for ( V_325 = 0 ; V_325 <= V_326 ; V_325 ++ ) {
if ( ! F_288 ( & V_45 -> V_52 , V_324 ) )
break;
if ( ! V_325 )
F_289 () ;
else if ( F_290 ( ( V_327 << V_325 ) / 200 ) )
V_325 = V_326 ;
V_99 = 0 ;
F_35 () ;
F_291 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_87 ( V_103 ) ;
if ( F_283 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_103 = F_89 ( & V_102 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_284 ( V_5 ) - F_285 ( V_5 ) != 1 ) {
if ( V_325 < V_326 )
goto V_328;
error = - V_329 ;
}
F_68 ( & V_45 -> V_87 ) ;
F_292 ( & V_45 -> V_52 ,
V_102 . V_4 , V_324 ) ;
F_75 ( & V_45 -> V_87 ) ;
V_328:
if ( F_91 () ) {
V_103 = F_92 ( V_103 , & V_102 ) ;
F_93 () ;
}
}
F_37 () ;
}
return error ;
}
int F_293 ( struct V_250 * V_250 , unsigned int V_135 )
{
struct V_3 * V_3 = F_95 ( V_250 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
int error ;
if ( V_250 -> V_263 != & V_264 )
return - V_62 ;
if ( ! ( V_250 -> V_330 & V_331 ) )
return - V_138 ;
if ( V_135 & ~ ( unsigned int ) V_332 )
return - V_62 ;
F_278 ( V_3 ) ;
if ( V_33 -> V_135 & V_276 ) {
error = - V_138 ;
goto V_214;
}
if ( ( V_135 & V_307 ) && ! ( V_33 -> V_135 & V_307 ) ) {
error = F_294 ( V_250 -> V_271 ) ;
if ( error )
goto V_214;
error = F_287 ( V_250 -> V_271 ) ;
if ( error ) {
F_295 ( V_250 -> V_271 ) ;
goto V_214;
}
}
V_33 -> V_135 |= V_135 ;
error = 0 ;
V_214:
F_280 ( V_3 ) ;
return error ;
}
int F_296 ( struct V_250 * V_250 )
{
if ( V_250 -> V_263 != & V_264 )
return - V_62 ;
return F_22 ( F_95 ( V_250 ) ) -> V_135 ;
}
long F_297 ( struct V_250 * V_250 , unsigned int V_333 , unsigned long V_334 )
{
long error ;
switch ( V_333 ) {
case V_335 :
if ( V_334 > V_336 )
return - V_62 ;
error = F_293 ( V_250 , V_334 ) ;
break;
case V_337 :
error = F_296 ( V_250 ) ;
break;
default:
error = - V_62 ;
break;
}
return error ;
}
static long F_298 ( struct V_250 * V_250 , int V_182 , T_2 V_255 ,
T_2 V_252 )
{
struct V_3 * V_3 = F_95 ( V_250 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
struct V_32 * V_33 = F_22 ( V_3 ) ;
struct V_170 V_170 ;
T_1 V_99 , V_4 , V_100 ;
int error ;
if ( V_182 & ~ ( V_338 | V_339 ) )
return - V_340 ;
F_278 ( V_3 ) ;
if ( V_182 & V_339 ) {
struct V_44 * V_45 = V_250 -> V_271 ;
T_2 V_341 = F_48 ( V_255 , V_22 ) ;
T_2 V_342 = F_64 ( V_255 + V_252 , V_22 ) - 1 ;
F_299 ( V_236 ) ;
if ( V_33 -> V_135 & V_307 ) {
error = - V_138 ;
goto V_160;
}
V_170 . V_172 = & V_236 ;
V_170 . V_99 = V_341 >> V_83 ;
V_170 . V_69 = ( V_342 + 1 ) >> V_83 ;
F_18 ( & V_3 -> V_171 ) ;
V_3 -> V_169 = & V_170 ;
F_19 ( & V_3 -> V_171 ) ;
if ( ( V_343 ) V_342 > ( V_343 ) V_341 )
F_126 ( V_45 , V_341 ,
1 + V_342 - V_341 , 0 ) ;
F_118 ( V_3 , V_255 , V_255 + V_252 - 1 ) ;
F_18 ( & V_3 -> V_171 ) ;
V_3 -> V_169 = NULL ;
F_300 ( & V_236 ) ;
F_154 ( ! F_43 ( & V_236 . V_229 ) ) ;
F_19 ( & V_3 -> V_171 ) ;
error = 0 ;
goto V_160;
}
error = F_301 ( V_3 , V_255 + V_252 ) ;
if ( error )
goto V_160;
if ( ( V_33 -> V_135 & V_137 ) && V_255 + V_252 > V_3 -> V_79 ) {
error = - V_138 ;
goto V_160;
}
V_99 = V_255 >> V_83 ;
V_100 = ( V_255 + V_252 + V_22 - 1 ) >> V_83 ;
if ( V_27 -> V_39 && V_100 - V_99 > V_27 -> V_39 ) {
error = - V_31 ;
goto V_160;
}
V_170 . V_172 = NULL ;
V_170 . V_99 = V_99 ;
V_170 . V_69 = V_99 ;
V_170 . V_344 = 0 ;
V_170 . V_173 = 0 ;
F_18 ( & V_3 -> V_171 ) ;
V_3 -> V_169 = & V_170 ;
F_19 ( & V_3 -> V_171 ) ;
for ( V_4 = V_99 ; V_4 < V_100 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_302 ( V_17 ) )
error = - V_345 ;
else if ( V_170 . V_173 > V_170 . V_344 )
error = - V_154 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_228 ) ;
if ( error ) {
if ( V_4 > V_99 ) {
F_105 ( V_3 ,
( T_2 ) V_99 << V_83 ,
( ( T_2 ) V_4 << V_83 ) - 1 , true ) ;
}
goto V_346;
}
V_170 . V_69 ++ ;
if ( ! F_111 ( V_5 ) )
V_170 . V_344 ++ ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
F_104 () ;
}
if ( ! ( V_182 & V_338 ) && V_255 + V_252 > V_3 -> V_79 )
F_125 ( V_3 , V_255 + V_252 ) ;
V_3 -> V_120 = F_119 ( V_3 ) ;
V_346:
F_18 ( & V_3 -> V_171 ) ;
V_3 -> V_169 = NULL ;
F_19 ( & V_3 -> V_171 ) ;
V_160:
F_280 ( V_3 ) ;
return error ;
}
static int F_303 ( struct V_127 * V_127 , struct V_347 * V_348 )
{
struct V_10 * V_27 = F_7 ( V_127 -> V_349 ) ;
V_348 -> V_350 = V_351 ;
V_348 -> V_352 = V_22 ;
V_348 -> V_353 = V_354 ;
if ( V_27 -> V_39 ) {
V_348 -> V_355 = V_27 -> V_39 ;
V_348 -> V_356 =
V_348 -> V_357 = V_27 -> V_39 -
F_304 ( & V_27 -> V_40 ) ;
}
if ( V_27 -> V_28 ) {
V_348 -> V_358 = V_27 -> V_28 ;
V_348 -> V_359 = V_27 -> V_30 ;
}
return 0 ;
}
static int
F_305 ( struct V_3 * V_272 , struct V_127 * V_127 , T_9 V_182 , T_10 V_273 )
{
struct V_3 * V_3 ;
int error = - V_31 ;
V_3 = F_234 ( V_272 -> V_38 , V_272 , V_182 , V_273 , V_16 ) ;
if ( V_3 ) {
error = F_306 ( V_272 , V_3 ) ;
if ( error )
goto V_360;
error = F_307 ( V_3 , V_272 ,
& V_127 -> V_361 ,
V_362 , NULL ) ;
if ( error && error != - V_340 )
goto V_360;
error = 0 ;
V_272 -> V_79 += V_284 ;
V_272 -> V_120 = V_272 -> V_121 = F_119 ( V_272 ) ;
F_308 ( V_127 , V_3 ) ;
F_309 ( V_127 ) ;
}
return error ;
V_360:
F_50 ( V_3 ) ;
return error ;
}
static int
F_310 ( struct V_3 * V_272 , struct V_127 * V_127 , T_9 V_182 )
{
struct V_3 * V_3 ;
int error = - V_31 ;
V_3 = F_234 ( V_272 -> V_38 , V_272 , V_182 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_307 ( V_3 , V_272 ,
NULL ,
V_362 , NULL ) ;
if ( error && error != - V_340 )
goto V_360;
error = F_306 ( V_272 , V_3 ) ;
if ( error )
goto V_360;
F_311 ( V_127 , V_3 ) ;
}
return error ;
V_360:
F_50 ( V_3 ) ;
return error ;
}
static int F_312 ( struct V_3 * V_272 , struct V_127 * V_127 , T_9 V_182 )
{
int error ;
if ( ( error = F_305 ( V_272 , V_127 , V_182 | V_283 , 0 ) ) )
return error ;
F_245 ( V_272 ) ;
return 0 ;
}
static int F_313 ( struct V_3 * V_272 , struct V_127 * V_127 , T_9 V_182 ,
bool V_363 )
{
return F_305 ( V_272 , V_127 , V_182 | V_280 , 0 ) ;
}
static int F_314 ( struct V_127 * V_364 , struct V_3 * V_272 , struct V_127 * V_127 )
{
struct V_3 * V_3 = V_128 ( V_364 ) ;
int V_81 ;
V_81 = F_17 ( V_3 -> V_38 ) ;
if ( V_81 )
goto V_160;
V_272 -> V_79 += V_284 ;
V_3 -> V_120 = V_272 -> V_120 = V_272 -> V_121 = F_119 ( V_3 ) ;
F_245 ( V_3 ) ;
F_315 ( V_3 ) ;
F_309 ( V_127 ) ;
F_308 ( V_127 , V_3 ) ;
V_160:
return V_81 ;
}
static int F_316 ( struct V_3 * V_272 , struct V_127 * V_127 )
{
struct V_3 * V_3 = V_128 ( V_127 ) ;
if ( V_3 -> V_365 > 1 && ! F_317 ( V_3 -> V_131 ) )
F_20 ( V_3 -> V_38 ) ;
V_272 -> V_79 -= V_284 ;
V_3 -> V_120 = V_272 -> V_120 = V_272 -> V_121 = F_119 ( V_3 ) ;
F_318 ( V_3 ) ;
F_319 ( V_127 ) ;
return 0 ;
}
static int F_320 ( struct V_3 * V_272 , struct V_127 * V_127 )
{
if ( ! F_321 ( V_127 ) )
return - V_366 ;
F_318 ( V_128 ( V_127 ) ) ;
F_318 ( V_272 ) ;
return F_316 ( V_272 , V_127 ) ;
}
static int F_322 ( struct V_3 * V_367 , struct V_127 * V_364 , struct V_3 * V_368 , struct V_127 * V_369 )
{
bool V_370 = F_323 ( V_364 ) ;
bool V_371 = F_323 ( V_369 ) ;
if ( V_367 != V_368 && V_370 != V_371 ) {
if ( V_370 ) {
F_318 ( V_367 ) ;
F_245 ( V_368 ) ;
} else {
F_318 ( V_368 ) ;
F_245 ( V_367 ) ;
}
}
V_367 -> V_120 = V_367 -> V_121 =
V_368 -> V_120 = V_368 -> V_121 =
V_128 ( V_364 ) -> V_120 =
V_128 ( V_369 ) -> V_120 = F_119 ( V_367 ) ;
return 0 ;
}
static int F_324 ( struct V_3 * V_367 , struct V_127 * V_364 )
{
struct V_127 * V_372 ;
int error ;
V_372 = F_325 ( V_364 -> V_373 , & V_364 -> V_361 ) ;
if ( ! V_372 )
return - V_154 ;
error = F_305 ( V_367 , V_372 ,
V_374 | V_375 , V_376 ) ;
F_319 ( V_372 ) ;
if ( error )
return error ;
F_326 ( V_372 ) ;
return 0 ;
}
static int F_327 ( struct V_3 * V_367 , struct V_127 * V_364 , struct V_3 * V_368 , struct V_127 * V_369 , unsigned int V_14 )
{
struct V_3 * V_3 = V_128 ( V_364 ) ;
int V_377 = F_317 ( V_3 -> V_131 ) ;
if ( V_14 & ~ ( V_378 | V_379 | V_380 ) )
return - V_62 ;
if ( V_14 & V_379 )
return F_322 ( V_367 , V_364 , V_368 , V_369 ) ;
if ( ! F_321 ( V_369 ) )
return - V_366 ;
if ( V_14 & V_380 ) {
int error ;
error = F_324 ( V_367 , V_364 ) ;
if ( error )
return error ;
}
if ( F_328 ( V_369 ) ) {
( void ) F_316 ( V_368 , V_369 ) ;
if ( V_377 ) {
F_318 ( V_128 ( V_369 ) ) ;
F_318 ( V_367 ) ;
}
} else if ( V_377 ) {
F_318 ( V_367 ) ;
F_245 ( V_368 ) ;
}
V_367 -> V_79 -= V_284 ;
V_368 -> V_79 += V_284 ;
V_367 -> V_120 = V_367 -> V_121 =
V_368 -> V_120 = V_368 -> V_121 =
V_3 -> V_120 = F_119 ( V_367 ) ;
return 0 ;
}
static int F_329 ( struct V_3 * V_272 , struct V_127 * V_127 , const char * V_381 )
{
int error ;
int V_252 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_32 * V_33 ;
V_252 = strlen ( V_381 ) + 1 ;
if ( V_252 > V_22 )
return - V_382 ;
V_3 = F_234 ( V_272 -> V_38 , V_272 , V_287 | V_383 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_31 ;
error = F_307 ( V_3 , V_272 , & V_127 -> V_361 ,
V_362 , NULL ) ;
if ( error ) {
if ( error != - V_340 ) {
F_50 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_33 = F_22 ( V_3 ) ;
V_3 -> V_79 = V_252 - 1 ;
if ( V_252 <= V_384 ) {
V_3 -> V_385 = F_330 ( V_381 , V_252 , V_161 ) ;
if ( ! V_3 -> V_385 ) {
F_50 ( V_3 ) ;
return - V_154 ;
}
V_3 -> V_278 = & V_386 ;
} else {
F_331 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_215 ) ;
if ( error ) {
F_50 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_142 = & V_143 ;
V_3 -> V_278 = & V_387 ;
memcpy ( F_332 ( V_5 ) , V_381 , V_252 ) ;
F_156 ( V_5 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
V_272 -> V_79 += V_284 ;
V_272 -> V_120 = V_272 -> V_121 = F_119 ( V_272 ) ;
F_308 ( V_127 , V_3 ) ;
F_309 ( V_127 ) ;
return 0 ;
}
static void F_333 ( void * V_334 )
{
F_196 ( V_334 ) ;
F_54 ( V_334 ) ;
}
static const char * F_334 ( struct V_127 * V_127 ,
struct V_3 * V_3 ,
struct V_388 * V_319 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_127 ) {
V_5 = F_335 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_184 ( - V_389 ) ;
if ( ! F_111 ( V_5 ) ) {
F_54 ( V_5 ) ;
return F_184 ( - V_389 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_118 ) ;
if ( error )
return F_184 ( error ) ;
F_53 ( V_5 ) ;
}
F_336 ( V_319 , F_333 , V_5 ) ;
return F_332 ( V_5 ) ;
}
static int V_362 ( struct V_3 * V_3 ,
const struct V_390 * V_391 ,
void * V_392 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
const struct V_390 * V_390 ;
struct V_393 * V_394 ;
T_15 V_252 ;
for ( V_390 = V_391 ; V_390 -> V_395 != NULL ; V_390 ++ ) {
V_394 = F_337 ( V_390 -> V_396 , V_390 -> V_397 ) ;
if ( ! V_394 )
return - V_154 ;
V_252 = strlen ( V_390 -> V_395 ) + 1 ;
V_394 -> V_395 = F_338 ( V_398 + V_252 ,
V_161 ) ;
if ( ! V_394 -> V_395 ) {
F_339 ( V_394 ) ;
return - V_154 ;
}
memcpy ( V_394 -> V_395 , V_399 ,
V_398 ) ;
memcpy ( V_394 -> V_395 + V_398 ,
V_390 -> V_395 , V_252 ) ;
F_340 ( & V_33 -> V_146 , V_394 ) ;
}
return 0 ;
}
static int F_341 ( const struct V_400 * V_401 ,
struct V_127 * V_402 , struct V_3 * V_3 ,
const char * V_395 , void * V_181 , T_15 V_15 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
V_395 = F_342 ( V_401 , V_395 ) ;
return F_343 ( & V_33 -> V_146 , V_395 , V_181 , V_15 ) ;
}
static int F_344 ( const struct V_400 * V_401 ,
struct V_127 * V_402 , struct V_3 * V_3 ,
const char * V_395 , const void * V_396 ,
T_15 V_15 , int V_14 )
{
struct V_32 * V_33 = F_22 ( V_3 ) ;
V_395 = F_342 ( V_401 , V_395 ) ;
return F_345 ( & V_33 -> V_146 , V_395 , V_396 , V_15 , V_14 ) ;
}
static T_14 F_346 ( struct V_127 * V_127 , char * V_181 , T_15 V_15 )
{
struct V_32 * V_33 = F_22 ( V_128 ( V_127 ) ) ;
return F_347 ( V_128 ( V_127 ) , & V_33 -> V_146 , V_181 , V_15 ) ;
}
static struct V_127 * F_348 ( struct V_127 * V_403 )
{
return F_184 ( - V_404 ) ;
}
static int F_349 ( struct V_3 * V_405 , void * V_406 )
{
T_16 * V_407 = V_406 ;
T_17 V_408 = V_407 [ 2 ] ;
V_408 = ( V_408 << 32 ) | V_407 [ 1 ] ;
return V_405 -> V_184 == V_408 && V_407 [ 0 ] == V_405 -> V_275 ;
}
static struct V_127 * F_350 ( struct V_11 * V_12 ,
struct V_409 * V_409 , int V_410 , int V_411 )
{
struct V_3 * V_3 ;
struct V_127 * V_127 = NULL ;
V_343 V_408 ;
if ( V_410 < 3 )
return NULL ;
V_408 = V_409 -> V_412 [ 2 ] ;
V_408 = ( V_408 << 32 ) | V_409 -> V_412 [ 1 ] ;
V_3 = F_351 ( V_12 , ( unsigned long ) ( V_408 + V_409 -> V_412 [ 0 ] ) ,
F_349 , V_409 -> V_412 ) ;
if ( V_3 ) {
V_127 = F_352 ( V_3 ) ;
F_50 ( V_3 ) ;
}
return V_127 ;
}
static int F_353 ( struct V_3 * V_3 , T_16 * V_407 , int * V_252 ,
struct V_3 * V_413 )
{
if ( * V_252 < 3 ) {
* V_252 = 3 ;
return V_414 ;
}
if ( F_354 ( V_3 ) ) {
static F_355 ( V_43 ) ;
F_18 ( & V_43 ) ;
if ( F_354 ( V_3 ) )
F_356 ( V_3 ,
V_3 -> V_184 + V_3 -> V_275 ) ;
F_19 ( & V_43 ) ;
}
V_407 [ 0 ] = V_3 -> V_275 ;
V_407 [ 1 ] = V_3 -> V_184 ;
V_407 [ 2 ] = ( ( T_17 ) V_3 -> V_184 ) >> 32 ;
* V_252 = 3 ;
return 1 ;
}
static int F_357 ( char * V_415 , struct V_10 * V_27 ,
bool V_416 )
{
char * V_417 , * V_396 , * V_418 ;
struct V_179 * V_180 = NULL ;
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
F_358 ( L_9 ,
V_417 ) ;
goto error;
}
if ( ! strcmp ( V_417 , L_10 ) ) {
unsigned long long V_15 ;
V_15 = F_359 ( V_396 , & V_418 ) ;
if ( * V_418 == '%' ) {
V_15 <<= V_83 ;
V_15 *= V_1 ;
F_360 ( V_15 , 100 ) ;
V_418 ++ ;
}
if ( * V_418 )
goto V_421;
V_27 -> V_39 =
F_208 ( V_15 , V_22 ) ;
} else if ( ! strcmp ( V_417 , L_11 ) ) {
V_27 -> V_39 = F_359 ( V_396 , & V_418 ) ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_12 ) ) {
V_27 -> V_28 = F_359 ( V_396 , & V_418 ) ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_13 ) ) {
if ( V_416 )
continue;
V_27 -> V_182 = F_361 ( V_396 , & V_418 , 8 ) & 07777 ;
if ( * V_418 )
goto V_421;
} else if ( ! strcmp ( V_417 , L_14 ) ) {
if ( V_416 )
continue;
V_419 = F_361 ( V_396 , & V_418 , 0 ) ;
if ( * V_418 )
goto V_421;
V_27 -> V_419 = F_362 ( F_363 () , V_419 ) ;
if ( ! F_364 ( V_27 -> V_419 ) )
goto V_421;
} else if ( ! strcmp ( V_417 , L_15 ) ) {
if ( V_416 )
continue;
V_420 = F_361 ( V_396 , & V_418 , 0 ) ;
if ( * V_418 )
goto V_421;
V_27 -> V_420 = F_365 ( F_363 () , V_420 ) ;
if ( ! F_366 ( V_27 -> V_420 ) )
goto V_421;
#ifdef V_140
} else if ( ! strcmp ( V_417 , L_16 ) ) {
int V_63 ;
V_63 = F_39 ( V_396 ) ;
if ( V_63 < 0 )
goto V_421;
if ( ! F_367 () &&
V_63 != V_56 )
goto V_421;
V_27 -> V_63 = V_63 ;
#endif
#ifdef F_368
} else if ( ! strcmp ( V_417 , L_17 ) ) {
F_369 ( V_180 ) ;
V_180 = NULL ;
if ( F_370 ( V_396 , & V_180 ) )
goto V_421;
#endif
} else {
F_358 ( L_18 , V_417 ) ;
goto error;
}
}
V_27 -> V_180 = V_180 ;
return 0 ;
V_421:
F_358 ( L_19 ,
V_396 , V_417 ) ;
error:
F_369 ( V_180 ) ;
return 1 ;
}
static int F_371 ( struct V_11 * V_12 , int * V_14 , char * V_422 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
struct V_10 V_423 = * V_27 ;
unsigned long V_424 ;
int error = - V_62 ;
V_423 . V_180 = NULL ;
if ( F_357 ( V_422 , & V_423 , true ) )
return error ;
F_18 ( & V_27 -> V_29 ) ;
V_424 = V_27 -> V_28 - V_27 -> V_30 ;
if ( F_27 ( & V_27 -> V_40 , V_423 . V_39 ) > 0 )
goto V_160;
if ( V_423 . V_28 < V_424 )
goto V_160;
if ( V_423 . V_39 && ! V_27 -> V_39 )
goto V_160;
if ( V_423 . V_28 && ! V_27 -> V_28 )
goto V_160;
error = 0 ;
V_27 -> V_63 = V_423 . V_63 ;
V_27 -> V_39 = V_423 . V_39 ;
V_27 -> V_28 = V_423 . V_28 ;
V_27 -> V_30 = V_423 . V_28 - V_424 ;
if ( V_423 . V_180 ) {
F_369 ( V_27 -> V_180 ) ;
V_27 -> V_180 = V_423 . V_180 ;
}
V_160:
F_19 ( & V_27 -> V_29 ) ;
return error ;
}
static int F_372 ( struct V_177 * V_178 , struct V_127 * V_148 )
{
struct V_10 * V_27 = F_7 ( V_148 -> V_349 ) ;
if ( V_27 -> V_39 != F_1 () )
F_166 ( V_178 , L_20 ,
V_27 -> V_39 << ( V_83 - 10 ) ) ;
if ( V_27 -> V_28 != F_2 () )
F_166 ( V_178 , L_21 , V_27 -> V_28 ) ;
if ( V_27 -> V_182 != ( V_383 | V_425 ) )
F_166 ( V_178 , L_22 , V_27 -> V_182 ) ;
if ( ! F_373 ( V_27 -> V_419 , V_426 ) )
F_166 ( V_178 , L_23 ,
F_374 ( & V_427 , V_27 -> V_419 ) ) ;
if ( ! F_375 ( V_27 -> V_420 , V_428 ) )
F_166 ( V_178 , L_24 ,
F_376 ( & V_427 , V_27 -> V_420 ) ) ;
#ifdef V_140
if ( V_27 -> V_63 )
F_166 ( V_178 , L_25 , F_40 ( V_27 -> V_63 ) ) ;
#endif
F_164 ( V_178 , V_27 -> V_180 ) ;
return 0 ;
}
static void F_377 ( struct V_11 * V_12 )
{
struct V_10 * V_27 = F_7 ( V_12 ) ;
F_378 ( & V_27 -> V_40 ) ;
F_369 ( V_27 -> V_180 ) ;
F_339 ( V_27 ) ;
V_12 -> V_13 = NULL ;
}
int F_379 ( struct V_11 * V_12 , void * V_422 , int V_429 )
{
struct V_3 * V_3 ;
struct V_10 * V_27 ;
int V_193 = - V_154 ;
V_27 = F_380 ( F_381 ( ( int ) sizeof( struct V_10 ) ,
V_430 ) , V_161 ) ;
if ( ! V_27 )
return - V_154 ;
V_27 -> V_182 = V_383 | V_425 ;
V_27 -> V_419 = F_382 () ;
V_27 -> V_420 = F_383 () ;
V_12 -> V_13 = V_27 ;
#ifdef F_384
if ( ! ( V_12 -> V_431 & V_432 ) ) {
V_27 -> V_39 = F_1 () ;
V_27 -> V_28 = F_2 () ;
if ( F_357 ( V_422 , V_27 , false ) ) {
V_193 = - V_62 ;
goto V_194;
}
} else {
V_12 -> V_431 |= V_433 ;
}
V_12 -> V_434 = & V_435 ;
V_12 -> V_431 |= V_436 ;
#else
V_12 -> V_431 |= V_433 ;
#endif
F_239 ( & V_27 -> V_29 ) ;
if ( F_385 ( & V_27 -> V_40 , 0 , V_161 ) )
goto V_194;
V_27 -> V_30 = V_27 -> V_28 ;
F_239 ( & V_27 -> V_77 ) ;
F_240 ( & V_27 -> V_75 ) ;
V_12 -> V_437 = V_208 ;
V_12 -> V_438 = V_22 ;
V_12 -> V_439 = V_83 ;
V_12 -> V_440 = V_351 ;
V_12 -> V_441 = & V_442 ;
V_12 -> V_443 = 1 ;
#ifdef F_386
V_12 -> V_444 = V_445 ;
#endif
#ifdef F_387
V_12 -> V_431 |= V_446 ;
#endif
F_388 ( & V_12 -> V_447 ) ;
V_3 = F_234 ( V_12 , NULL , V_283 | V_27 -> V_182 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_194;
V_3 -> V_448 = V_27 -> V_419 ;
V_3 -> V_449 = V_27 -> V_420 ;
V_12 -> V_450 = F_389 ( V_3 ) ;
if ( ! V_12 -> V_450 )
goto V_194;
return 0 ;
V_194:
F_377 ( V_12 ) ;
return V_193 ;
}
static struct V_3 * F_390 ( struct V_11 * V_12 )
{
struct V_32 * V_33 ;
V_33 = F_391 ( V_451 , V_161 ) ;
if ( ! V_33 )
return NULL ;
return & V_33 -> V_78 ;
}
static void F_392 ( struct V_452 * V_229 )
{
struct V_3 * V_3 = F_393 ( V_229 , struct V_3 , V_453 ) ;
if ( F_394 ( V_3 -> V_131 ) )
F_339 ( V_3 -> V_385 ) ;
F_395 ( V_451 , F_22 ( V_3 ) ) ;
}
static void F_396 ( struct V_3 * V_3 )
{
if ( F_124 ( V_3 -> V_131 ) )
F_397 ( & F_22 ( V_3 ) -> V_186 ) ;
F_398 ( & V_3 -> V_453 , F_392 ) ;
}
static void F_399 ( void * V_454 )
{
struct V_32 * V_33 = V_454 ;
F_400 ( & V_33 -> V_78 ) ;
}
static int F_401 ( void )
{
V_451 = F_402 ( L_26 ,
sizeof( struct V_32 ) ,
0 , V_455 | V_456 , F_399 ) ;
return 0 ;
}
static void F_403 ( void )
{
F_404 ( V_451 ) ;
}
static struct V_127 * F_405 ( struct V_457 * V_458 ,
int V_14 , const char * V_459 , void * V_422 )
{
return F_406 ( V_458 , V_14 , V_422 , F_379 ) ;
}
int T_20 F_407 ( void )
{
int error ;
if ( V_451 )
return 0 ;
error = F_401 () ;
if ( error )
goto V_460;
error = F_408 ( & V_461 ) ;
if ( error ) {
F_358 ( L_27 ) ;
goto V_462;
}
V_265 = F_409 ( & V_461 ) ;
if ( F_202 ( V_265 ) ) {
error = F_203 ( V_265 ) ;
F_358 ( L_28 ) ;
goto V_463;
}
#ifdef V_140
if ( F_367 () && V_223 > V_60 )
F_7 ( V_265 -> V_266 ) -> V_63 = V_223 ;
else
V_223 = 0 ;
#endif
return 0 ;
V_463:
F_410 ( & V_461 ) ;
V_462:
F_403 () ;
V_460:
V_265 = F_184 ( error ) ;
return error ;
}
static T_14 F_411 ( struct V_464 * V_465 ,
struct V_466 * V_130 , char * V_348 )
{
int V_467 [] = {
V_57 ,
V_58 ,
V_59 ,
V_56 ,
V_60 ,
V_61 ,
} ;
int V_90 , V_468 ;
for ( V_90 = 0 , V_468 = 0 ; V_90 < F_412 ( V_467 ) ; V_90 ++ ) {
const char * V_469 = V_223 == V_467 [ V_90 ] ? L_29 : L_30 ;
V_468 += sprintf ( V_348 + V_468 , V_469 ,
F_40 ( V_467 [ V_90 ] ) ) ;
}
V_348 [ V_468 - 1 ] = '\n' ;
return V_468 ;
}
static T_14 F_413 ( struct V_464 * V_465 ,
struct V_466 * V_130 , const char * V_348 , T_15 V_468 )
{
char V_470 [ 16 ] ;
int V_63 ;
if ( V_468 + 1 > sizeof( V_470 ) )
return - V_62 ;
memcpy ( V_470 , V_348 , V_468 ) ;
V_470 [ V_468 ] = '\0' ;
if ( V_468 && V_470 [ V_468 - 1 ] == '\n' )
V_470 [ V_468 - 1 ] = '\0' ;
V_63 = F_39 ( V_470 ) ;
if ( V_63 == - V_62 )
return - V_62 ;
if ( ! F_367 () &&
V_63 != V_56 && V_63 != V_60 )
return - V_62 ;
V_223 = V_63 ;
if ( V_223 > V_60 )
F_7 ( V_265 -> V_266 ) -> V_63 = V_223 ;
return V_468 ;
}
bool F_414 ( struct V_23 * V_24 )
{
struct V_3 * V_3 = F_95 ( V_24 -> V_104 ) ;
struct V_10 * V_27 = F_7 ( V_3 -> V_38 ) ;
T_2 V_79 ;
T_1 V_225 ;
if ( V_223 == V_61 )
return true ;
if ( V_223 == V_60 )
return false ;
switch ( V_27 -> V_63 ) {
case V_56 :
return false ;
case V_57 :
return true ;
case V_58 :
V_225 = F_48 ( V_24 -> V_105 , V_91 ) ;
V_79 = F_48 ( F_195 ( V_3 ) , V_22 ) ;
if ( V_79 >= V_80 &&
V_79 >> V_83 >= V_225 )
return true ;
case V_59 :
return ( V_24 -> V_244 & V_247 ) ;
default:
F_31 ( 1 ) ;
return false ;
}
}
int T_20 F_407 ( void )
{
F_80 ( F_408 ( & V_461 ) != 0 ) ;
V_265 = F_409 ( & V_461 ) ;
F_80 ( F_202 ( V_265 ) ) ;
return 0 ;
}
int F_146 ( T_3 V_54 , struct V_5 * V_5 )
{
return 0 ;
}
int F_226 ( struct V_250 * V_250 , int V_43 , struct V_267 * V_268 )
{
return 0 ;
}
void F_97 ( struct V_44 * V_45 )
{
}
unsigned long F_221 ( struct V_250 * V_250 ,
unsigned long V_254 , unsigned long V_252 ,
unsigned long V_235 , unsigned long V_14 )
{
return V_17 -> V_18 -> V_260 ( V_250 , V_254 , V_252 , V_235 , V_14 ) ;
}
void F_118 ( struct V_3 * V_3 , T_2 V_112 , T_2 V_113 )
{
F_415 ( V_3 -> V_9 , V_112 , V_113 ) ;
}
static struct V_250 * F_416 ( const char * V_395 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_471 )
{
struct V_250 * V_472 ;
struct V_3 * V_3 ;
struct V_122 V_122 ;
struct V_11 * V_12 ;
struct V_473 V_156 ;
if ( F_202 ( V_265 ) )
return F_417 ( V_265 ) ;
if ( V_15 < 0 || V_15 > V_208 )
return F_184 ( - V_62 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_184 ( - V_154 ) ;
V_472 = F_184 ( - V_154 ) ;
V_156 . V_395 = V_395 ;
V_156 . V_252 = strlen ( V_395 ) ;
V_156 . V_474 = 0 ;
V_12 = V_265 -> V_266 ;
V_122 . V_475 = F_418 ( V_265 ) ;
V_122 . V_127 = F_419 ( V_12 , & V_156 ) ;
if ( ! V_122 . V_127 )
goto V_476;
F_420 ( V_122 . V_127 , & V_477 ) ;
V_472 = F_184 ( - V_31 ) ;
V_3 = F_234 ( V_12 , NULL , V_280 | V_383 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_476;
V_3 -> V_471 |= V_471 ;
F_308 ( V_122 . V_127 , V_3 ) ;
V_3 -> V_79 = V_15 ;
F_421 ( V_3 ) ;
V_472 = F_184 ( F_422 ( V_3 , V_15 ) ) ;
if ( F_202 ( V_472 ) )
goto V_478;
V_472 = F_423 ( & V_122 , V_331 | V_479 ,
& V_264 ) ;
if ( F_202 ( V_472 ) )
goto V_478;
return V_472 ;
V_476:
F_11 ( V_14 , V_15 ) ;
V_478:
F_424 ( & V_122 ) ;
return V_472 ;
}
struct V_250 * F_425 ( const char * V_395 , T_2 V_15 , unsigned long V_14 )
{
return F_416 ( V_395 , V_15 , V_14 , V_480 ) ;
}
struct V_250 * F_426 ( const char * V_395 , T_2 V_15 , unsigned long V_14 )
{
return F_416 ( V_395 , V_15 , V_14 , 0 ) ;
}
int F_427 ( struct V_23 * V_24 )
{
struct V_250 * V_250 ;
T_2 V_15 = V_24 -> V_106 - V_24 -> V_107 ;
V_250 = F_416 ( L_31 , V_15 , V_24 -> V_244 , V_480 ) ;
if ( F_202 ( V_250 ) )
return F_203 ( V_250 ) ;
if ( V_24 -> V_104 )
F_428 ( V_24 -> V_104 ) ;
V_24 -> V_104 = V_250 ;
V_24 -> V_25 = & V_26 ;
if ( F_127 ( V_140 ) &&
( ( V_24 -> V_107 + ~ V_82 ) & V_82 ) <
( V_24 -> V_106 & V_82 ) ) {
F_233 ( V_24 , V_24 -> V_244 ) ;
}
return 0 ;
}
struct V_5 * F_429 ( struct V_44 * V_45 ,
T_1 V_4 , T_6 V_151 )
{
#ifdef F_430
struct V_3 * V_3 = V_45 -> V_164 ;
struct V_5 * V_5 ;
int error ;
F_80 ( V_45 -> V_142 != & V_143 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_212 ,
V_151 , NULL , NULL , NULL ) ;
if ( error )
V_5 = F_184 ( error ) ;
else
F_53 ( V_5 ) ;
return V_5 ;
#else
return F_431 ( V_45 , V_4 , V_151 ) ;
#endif
}
