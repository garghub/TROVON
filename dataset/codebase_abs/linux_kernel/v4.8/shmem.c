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
void * * V_44 ;
void * V_45 ;
F_30 ( ! V_42 ) ;
F_30 ( ! V_43 ) ;
V_44 = F_31 ( & V_41 -> V_46 , V_4 ) ;
if ( ! V_44 )
return - V_47 ;
V_45 = F_32 ( V_44 , & V_41 -> V_48 ) ;
if ( V_45 != V_42 )
return - V_47 ;
F_33 ( V_44 , V_43 ) ;
return 0 ;
}
static bool F_34 ( struct V_40 * V_41 ,
T_1 V_4 , T_3 V_49 )
{
void * V_45 ;
F_35 () ;
V_45 = F_36 ( & V_41 -> V_46 , V_4 ) ;
F_37 () ;
return V_45 == F_38 ( V_49 ) ;
}
static int F_39 ( const char * V_50 )
{
if ( ! strcmp ( V_50 , L_1 ) )
return V_51 ;
if ( ! strcmp ( V_50 , L_2 ) )
return V_52 ;
if ( ! strcmp ( V_50 , L_3 ) )
return V_53 ;
if ( ! strcmp ( V_50 , L_4 ) )
return V_54 ;
if ( ! strcmp ( V_50 , L_5 ) )
return V_55 ;
if ( ! strcmp ( V_50 , L_6 ) )
return V_56 ;
return - V_57 ;
}
static const char * F_40 ( int V_58 )
{
switch ( V_58 ) {
case V_51 :
return L_1 ;
case V_52 :
return L_2 ;
case V_53 :
return L_3 ;
case V_54 :
return L_4 ;
case V_55 :
return L_5 ;
case V_56 :
return L_6 ;
default:
F_30 ( 1 ) ;
return L_7 ;
}
}
static unsigned long F_41 ( struct V_10 * V_23 ,
struct V_59 * V_60 , unsigned long V_61 )
{
F_42 ( V_62 ) , * V_63 , * V_64 ;
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_5 * V_5 ;
unsigned long V_65 = V_60 ? V_60 -> V_66 : 128 ;
int V_67 = 0 , V_68 = 0 ;
if ( F_43 ( & V_23 -> V_69 ) )
return V_70 ;
F_17 ( & V_23 -> V_71 ) ;
F_44 (pos, next, &sbinfo->shrinklist) {
V_29 = F_45 ( V_63 , struct V_28 , V_69 ) ;
V_3 = F_46 ( & V_29 -> V_72 ) ;
if ( ! V_3 ) {
F_47 ( & V_29 -> V_69 ) ;
V_67 ++ ;
goto V_64;
}
if ( F_48 ( V_3 -> V_73 , V_22 ) ==
F_48 ( V_3 -> V_73 , V_74 ) ) {
F_47 ( & V_29 -> V_69 ) ;
V_67 ++ ;
F_49 ( V_3 ) ;
goto V_64;
}
F_50 ( & V_29 -> V_69 , & V_62 ) ;
V_64:
if ( ! -- V_65 )
break;
}
F_18 ( & V_23 -> V_71 ) ;
F_44 (pos, next, &list) {
int V_75 ;
V_29 = F_45 ( V_63 , struct V_28 , V_69 ) ;
V_3 = & V_29 -> V_72 ;
if ( V_61 && V_68 >= V_61 ) {
F_49 ( V_3 ) ;
continue;
}
V_5 = F_51 ( V_3 -> V_9 ,
( V_3 -> V_73 & V_76 ) >> V_77 ) ;
if ( ! V_5 )
goto V_78;
if ( ! F_52 ( V_5 ) ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
goto V_78;
}
V_75 = F_55 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
if ( V_75 ) {
F_49 ( V_3 ) ;
continue;
}
V_68 ++ ;
V_78:
F_47 ( & V_29 -> V_69 ) ;
V_67 ++ ;
F_49 ( V_3 ) ;
}
F_17 ( & V_23 -> V_71 ) ;
F_56 ( & V_62 , & V_23 -> V_69 ) ;
V_23 -> V_79 -= V_67 ;
F_18 ( & V_23 -> V_71 ) ;
return V_68 ;
}
static long F_57 ( struct V_11 * V_12 ,
struct V_59 * V_60 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( ! F_58 ( V_23 -> V_79 ) )
return V_70 ;
return F_41 ( V_23 , V_60 , 0 ) ;
}
static long F_59 ( struct V_11 * V_12 ,
struct V_59 * V_60 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
return F_58 ( V_23 -> V_79 ) ;
}
static unsigned long F_41 ( struct V_10 * V_23 ,
struct V_59 * V_60 , unsigned long V_61 )
{
return 0 ;
}
static int F_60 ( struct V_5 * V_5 ,
struct V_40 * V_41 ,
T_1 V_4 , void * V_42 )
{
int error , V_80 = F_61 ( V_5 ) ;
F_62 ( F_63 ( V_5 ) , V_5 ) ;
F_62 ( V_4 != F_64 ( V_4 , V_80 ) , V_5 ) ;
F_62 ( ! F_65 ( V_5 ) , V_5 ) ;
F_62 ( ! F_66 ( V_5 ) , V_5 ) ;
F_30 ( V_42 && F_52 ( V_5 ) ) ;
F_67 ( V_5 , V_80 ) ;
V_5 -> V_41 = V_41 ;
V_5 -> V_4 = V_4 ;
F_68 ( & V_41 -> V_48 ) ;
if ( F_52 ( V_5 ) ) {
void T_4 * * V_81 ;
T_1 V_82 ;
int V_83 ;
error = 0 ;
if ( F_69 ( & V_41 -> V_46 ,
& V_81 , & V_82 , V_4 , 1 ) &&
V_82 < V_4 + V_84 ) {
error = - V_85 ;
}
if ( ! error ) {
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
error = F_70 ( & V_41 -> V_46 ,
V_4 + V_83 , V_5 + V_83 ) ;
F_30 ( error ) ;
}
F_71 ( V_86 ) ;
}
} else if ( ! V_42 ) {
error = F_70 ( & V_41 -> V_46 , V_4 , V_5 ) ;
} else {
error = F_29 ( V_41 , V_4 , V_42 ,
V_5 ) ;
}
if ( ! error ) {
V_41 -> V_33 += V_80 ;
if ( F_52 ( V_5 ) )
F_72 ( V_5 , V_87 ) ;
F_73 ( F_74 ( V_5 ) , V_88 , V_80 ) ;
F_73 ( F_74 ( V_5 ) , V_89 , V_80 ) ;
F_75 ( & V_41 -> V_48 ) ;
} else {
V_5 -> V_41 = NULL ;
F_75 ( & V_41 -> V_48 ) ;
F_76 ( V_5 , V_80 ) ;
}
return error ;
}
static void F_77 ( struct V_5 * V_5 , void * V_90 )
{
struct V_40 * V_41 = V_5 -> V_41 ;
int error ;
F_62 ( F_78 ( V_5 ) , V_5 ) ;
F_68 ( & V_41 -> V_48 ) ;
error = F_29 ( V_41 , V_5 -> V_4 , V_5 , V_90 ) ;
V_5 -> V_41 = NULL ;
V_41 -> V_33 -- ;
F_79 ( V_5 , V_88 ) ;
F_79 ( V_5 , V_89 ) ;
F_75 ( & V_41 -> V_48 ) ;
F_54 ( V_5 ) ;
F_80 ( error ) ;
}
static int F_81 ( struct V_40 * V_41 ,
T_1 V_4 , void * V_90 )
{
void * V_91 ;
F_68 ( & V_41 -> V_48 ) ;
V_91 = F_82 ( & V_41 -> V_46 , V_4 , V_90 ) ;
F_75 ( & V_41 -> V_48 ) ;
if ( V_91 != V_90 )
return - V_47 ;
F_83 ( F_84 ( V_90 ) ) ;
return 0 ;
}
unsigned long F_85 ( struct V_40 * V_41 ,
T_1 V_92 , T_1 V_93 )
{
struct V_94 V_95 ;
void * * V_96 ;
struct V_5 * V_5 ;
unsigned long V_32 = 0 ;
F_35 () ;
F_86 (slot, &mapping->page_tree, &iter, start) {
if ( V_95 . V_4 >= V_93 )
break;
V_5 = F_87 ( V_96 ) ;
if ( F_88 ( V_5 ) ) {
V_96 = F_89 ( & V_95 ) ;
continue;
}
if ( F_90 ( V_5 ) )
V_32 ++ ;
if ( F_91 () ) {
F_92 () ;
V_96 = F_93 ( & V_95 ) ;
}
}
F_37 () ;
return V_32 << V_77 ;
}
unsigned long F_94 ( struct V_97 * V_98 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_40 * V_41 = V_3 -> V_9 ;
unsigned long V_32 ;
V_32 = F_58 ( V_29 -> V_32 ) ;
if ( ! V_32 )
return 0 ;
if ( ! V_98 -> V_100 && V_98 -> V_101 - V_98 -> V_102 >= V_3 -> V_73 )
return V_32 << V_77 ;
return F_85 ( V_41 ,
F_96 ( V_98 , V_98 -> V_102 ) ,
F_96 ( V_98 , V_98 -> V_101 ) ) ;
}
void F_97 ( struct V_40 * V_41 )
{
struct V_103 V_104 ;
T_1 V_105 [ V_106 ] ;
T_1 V_4 = 0 ;
F_98 ( & V_104 , 0 ) ;
while ( ! F_99 ( V_41 ) ) {
V_104 . V_80 = F_100 ( V_41 , V_4 ,
V_106 , V_104 . V_21 , V_105 ) ;
if ( ! V_104 . V_80 )
break;
V_4 = V_105 [ V_104 . V_80 - 1 ] + 1 ;
F_101 ( & V_104 ) ;
F_102 ( V_104 . V_21 , V_104 . V_80 ) ;
F_103 ( & V_104 ) ;
F_104 () ;
}
}
static void F_105 ( struct V_3 * V_3 , T_2 V_107 , T_2 V_108 ,
bool V_109 )
{
struct V_40 * V_41 = V_3 -> V_9 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_92 = ( V_107 + V_22 - 1 ) >> V_77 ;
T_1 V_93 = ( V_108 + 1 ) >> V_77 ;
unsigned int V_110 = V_107 & ( V_22 - 1 ) ;
unsigned int V_111 = ( V_108 + 1 ) & ( V_22 - 1 ) ;
struct V_103 V_104 ;
T_1 V_105 [ V_106 ] ;
long V_112 = 0 ;
T_1 V_4 ;
int V_83 ;
if ( V_108 == - 1 )
V_93 = - 1 ;
F_98 ( & V_104 , 0 ) ;
V_4 = V_92 ;
while ( V_4 < V_93 ) {
V_104 . V_80 = F_100 ( V_41 , V_4 ,
F_3 ( V_93 - V_4 , ( T_1 ) V_106 ) ,
V_104 . V_21 , V_105 ) ;
if ( ! V_104 . V_80 )
break;
for ( V_83 = 0 ; V_83 < F_106 ( & V_104 ) ; V_83 ++ ) {
struct V_5 * V_5 = V_104 . V_21 [ V_83 ] ;
V_4 = V_105 [ V_83 ] ;
if ( V_4 >= V_93 )
break;
if ( F_90 ( V_5 ) ) {
if ( V_109 )
continue;
V_112 += ! F_81 ( V_41 ,
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
if ( V_4 == F_64 ( V_93 , V_84 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
continue;
}
V_4 += V_84 - 1 ;
V_83 += V_84 - 1 ;
}
if ( ! V_109 || ! F_111 ( V_5 ) ) {
F_62 ( F_63 ( V_5 ) , V_5 ) ;
if ( F_112 ( V_5 ) == V_41 ) {
F_62 ( F_113 ( V_5 ) , V_5 ) ;
F_114 ( V_41 , V_5 ) ;
}
}
F_53 ( V_5 ) ;
}
F_101 ( & V_104 ) ;
F_103 ( & V_104 ) ;
F_104 () ;
V_4 ++ ;
}
if ( V_110 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_92 - 1 , & V_5 , V_113 ) ;
if ( V_5 ) {
unsigned int V_114 = V_22 ;
if ( V_92 > V_93 ) {
V_114 = V_111 ;
V_111 = 0 ;
}
F_115 ( V_5 , V_110 , V_114 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
}
if ( V_111 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_93 , & V_5 , V_113 ) ;
if ( V_5 ) {
F_115 ( V_5 , 0 , V_111 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
}
if ( V_92 >= V_93 )
return;
V_4 = V_92 ;
while ( V_4 < V_93 ) {
F_104 () ;
V_104 . V_80 = F_100 ( V_41 , V_4 ,
F_3 ( V_93 - V_4 , ( T_1 ) V_106 ) ,
V_104 . V_21 , V_105 ) ;
if ( ! V_104 . V_80 ) {
if ( V_4 == V_92 || V_93 != - 1 )
break;
V_4 = V_92 ;
continue;
}
for ( V_83 = 0 ; V_83 < F_106 ( & V_104 ) ; V_83 ++ ) {
struct V_5 * V_5 = V_104 . V_21 [ V_83 ] ;
V_4 = V_105 [ V_83 ] ;
if ( V_4 >= V_93 )
break;
if ( F_90 ( V_5 ) ) {
if ( V_109 )
continue;
if ( F_81 ( V_41 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_112 ++ ;
continue;
}
F_117 ( V_5 ) ;
if ( F_109 ( V_5 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
if ( V_4 != F_64 ( V_93 , V_84 ) )
V_92 ++ ;
continue;
} else if ( F_52 ( V_5 ) ) {
if ( V_4 == F_64 ( V_93 , V_84 ) ) {
F_110 ( V_5 ) ;
F_53 ( V_5 ) ;
continue;
}
V_4 += V_84 - 1 ;
V_83 += V_84 - 1 ;
}
if ( ! V_109 || ! F_111 ( V_5 ) ) {
F_62 ( F_63 ( V_5 ) , V_5 ) ;
if ( F_112 ( V_5 ) == V_41 ) {
F_62 ( F_113 ( V_5 ) , V_5 ) ;
F_114 ( V_41 , V_5 ) ;
} else {
F_53 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_53 ( V_5 ) ;
}
F_101 ( & V_104 ) ;
F_103 ( & V_104 ) ;
V_4 ++ ;
}
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -= V_112 ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
}
void F_118 ( struct V_3 * V_3 , T_2 V_107 , T_2 V_108 )
{
F_105 ( V_3 , V_107 , V_108 , false ) ;
V_3 -> V_115 = V_3 -> V_116 = V_117 ;
}
static int F_119 ( struct V_118 * V_119 , struct V_120 * V_120 ,
struct V_121 * V_122 )
{
struct V_3 * V_3 = V_120 -> V_123 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 != V_3 -> V_9 -> V_33 ) {
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
}
F_120 ( V_3 , V_122 ) ;
return 0 ;
}
static int F_121 ( struct V_120 * V_120 , struct V_124 * V_125 )
{
struct V_3 * V_3 = V_123 ( V_120 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
int error ;
error = F_122 ( V_3 , V_125 ) ;
if ( error )
return error ;
if ( F_123 ( V_3 -> V_126 ) && ( V_125 -> V_127 & V_128 ) ) {
T_2 V_19 = V_3 -> V_73 ;
T_2 V_20 = V_125 -> V_129 ;
if ( ( V_20 < V_19 && ( V_29 -> V_130 & V_131 ) ) ||
( V_20 > V_19 && ( V_29 -> V_130 & V_132 ) ) )
return - V_133 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_21 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_124 ( V_3 , V_20 ) ;
V_3 -> V_115 = V_3 -> V_116 = V_117 ;
}
if ( V_20 <= V_19 ) {
T_2 V_134 = F_48 ( V_20 , V_22 ) ;
if ( V_19 > V_134 )
F_125 ( V_3 -> V_9 ,
V_134 , 0 , 1 ) ;
if ( V_29 -> V_31 )
F_118 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_134 )
F_125 ( V_3 -> V_9 ,
V_134 , 0 , 1 ) ;
if ( F_126 ( V_135 ) ) {
F_17 ( & V_23 -> V_71 ) ;
if ( F_43 ( & V_29 -> V_69 ) ) {
F_127 ( & V_29 -> V_69 ,
& V_23 -> V_69 ) ;
V_23 -> V_79 ++ ;
}
F_18 ( & V_23 -> V_71 ) ;
}
}
}
F_128 ( V_3 , V_125 ) ;
if ( V_125 -> V_127 & V_136 )
error = F_129 ( V_3 , V_3 -> V_126 ) ;
return error ;
}
static void F_130 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
if ( V_3 -> V_9 -> V_137 == & V_138 ) {
F_11 ( V_29 -> V_14 , V_3 -> V_73 ) ;
V_3 -> V_73 = 0 ;
F_118 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_43 ( & V_29 -> V_69 ) ) {
F_17 ( & V_23 -> V_71 ) ;
if ( ! F_43 ( & V_29 -> V_69 ) ) {
F_47 ( & V_29 -> V_69 ) ;
V_23 -> V_79 -- ;
}
F_18 ( & V_23 -> V_71 ) ;
}
if ( ! F_43 ( & V_29 -> V_139 ) ) {
F_131 ( & V_140 ) ;
F_47 ( & V_29 -> V_139 ) ;
F_132 ( & V_140 ) ;
}
}
F_133 ( & V_29 -> V_141 ) ;
F_134 ( V_3 -> V_37 ) ;
F_19 ( V_3 -> V_34 ) ;
F_135 ( V_3 ) ;
}
static int F_136 ( struct V_28 * V_29 ,
T_3 V_49 , struct V_5 * * V_6 )
{
struct V_40 * V_41 = V_29 -> V_72 . V_9 ;
void * V_90 ;
T_1 V_4 ;
T_5 V_142 ;
int error = 0 ;
V_90 = F_38 ( V_49 ) ;
V_4 = F_137 ( & V_41 -> V_46 , V_90 ) ;
if ( V_4 == - 1 )
return - V_143 ;
if ( V_144 . V_64 != & V_29 -> V_139 )
F_138 ( & V_144 , & V_29 -> V_139 ) ;
V_142 = F_6 ( V_41 ) ;
if ( F_139 ( * V_6 , V_142 ) ) {
F_132 ( & V_140 ) ;
error = F_140 ( V_6 , V_142 , V_29 , V_4 ) ;
F_131 ( & V_140 ) ;
if ( ! F_141 ( * V_6 ) )
error = - V_47 ;
}
if ( ! error )
error = F_60 ( * V_6 , V_41 , V_4 ,
V_90 ) ;
if ( error != - V_145 ) {
F_142 ( * V_6 ) ;
F_116 ( * V_6 ) ;
if ( ! error ) {
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_75 ( & V_29 -> V_39 ) ;
F_143 ( V_49 ) ;
}
}
return error ;
}
int F_144 ( T_3 V_49 , struct V_5 * V_5 )
{
struct V_146 * V_147 , * V_64 ;
struct V_28 * V_29 ;
struct V_148 * V_149 ;
int error = 0 ;
if ( F_145 ( ! F_146 ( V_5 ) || F_147 ( V_5 ) != V_49 . V_150 ) )
goto V_151;
error = F_148 ( V_5 , V_17 -> V_18 , V_152 , & V_149 ,
false ) ;
if ( error )
goto V_151;
error = - V_143 ;
F_131 ( & V_140 ) ;
F_44 (this, next, &shmem_swaplist) {
V_29 = F_45 ( V_147 , struct V_28 , V_139 ) ;
if ( V_29 -> V_32 )
error = F_136 ( V_29 , V_49 , & V_5 ) ;
else
F_47 ( & V_29 -> V_139 ) ;
F_104 () ;
if ( error != - V_143 )
break;
}
F_132 ( & V_140 ) ;
if ( error ) {
if ( error != - V_145 )
error = 0 ;
F_149 ( V_5 , V_149 , false ) ;
} else
F_150 ( V_5 , V_149 , true , false ) ;
V_151:
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return error ;
}
static int F_151 ( struct V_5 * V_5 , struct V_153 * V_154 )
{
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_3 * V_3 ;
T_3 V_49 ;
T_1 V_4 ;
F_62 ( F_78 ( V_5 ) , V_5 ) ;
F_80 ( ! F_65 ( V_5 ) ) ;
V_41 = V_5 -> V_41 ;
V_4 = V_5 -> V_4 ;
V_3 = V_41 -> V_155 ;
V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_14 & V_156 )
goto V_157;
if ( ! V_158 )
goto V_157;
if ( ! V_154 -> V_159 ) {
F_152 ( 1 ) ;
goto V_157;
}
if ( ! F_111 ( V_5 ) ) {
if ( V_3 -> V_160 ) {
struct V_161 * V_161 ;
F_17 ( & V_3 -> V_162 ) ;
V_161 = V_3 -> V_160 ;
if ( V_161 &&
! V_161 -> V_163 &&
V_4 >= V_161 -> V_92 &&
V_4 < V_161 -> V_64 )
V_161 -> V_164 ++ ;
else
V_161 = NULL ;
F_18 ( & V_3 -> V_162 ) ;
if ( V_161 )
goto V_157;
}
F_110 ( V_5 ) ;
F_153 ( V_5 ) ;
F_154 ( V_5 ) ;
}
V_49 = F_155 () ;
if ( ! V_49 . V_150 )
goto V_157;
if ( F_156 ( V_5 , V_49 ) )
goto V_165;
F_131 ( & V_140 ) ;
if ( F_43 ( & V_29 -> V_139 ) )
F_127 ( & V_29 -> V_139 , & V_144 ) ;
if ( F_157 ( V_5 , V_49 , V_166 ) == 0 ) {
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
V_29 -> V_32 ++ ;
F_75 ( & V_29 -> V_39 ) ;
F_158 ( V_49 ) ;
F_77 ( V_5 , F_38 ( V_49 ) ) ;
F_132 ( & V_140 ) ;
F_80 ( F_159 ( V_5 ) ) ;
F_160 ( V_5 , V_154 ) ;
return 0 ;
}
F_132 ( & V_140 ) ;
V_165:
F_161 ( V_49 ) ;
V_157:
F_116 ( V_5 ) ;
if ( V_154 -> V_159 )
return V_167 ;
F_53 ( V_5 ) ;
return 0 ;
}
static void F_162 ( struct V_168 * V_169 , struct V_170 * V_171 )
{
char V_172 [ 64 ] ;
if ( ! V_171 || V_171 -> V_173 == V_174 )
return;
F_163 ( V_172 , sizeof( V_172 ) , V_171 ) ;
F_164 ( V_169 , L_8 , V_172 ) ;
}
static struct V_170 * F_165 ( struct V_10 * V_23 )
{
struct V_170 * V_171 = NULL ;
if ( V_23 -> V_171 ) {
F_17 ( & V_23 -> V_25 ) ;
V_171 = V_23 -> V_171 ;
F_166 ( V_171 ) ;
F_18 ( & V_23 -> V_25 ) ;
}
return V_171 ;
}
static inline void F_162 ( struct V_168 * V_169 , struct V_170 * V_171 )
{
}
static inline struct V_170 * F_165 ( struct V_10 * V_23 )
{
return NULL ;
}
static void F_167 ( struct V_97 * V_98 ,
struct V_28 * V_29 , T_1 V_4 )
{
V_98 -> V_102 = 0 ;
V_98 -> V_100 = V_4 + V_29 -> V_72 . V_175 ;
V_98 -> V_176 = NULL ;
V_98 -> V_177 = F_168 ( & V_29 -> V_178 , V_4 ) ;
}
static void F_169 ( struct V_97 * V_98 )
{
F_170 ( V_98 -> V_177 ) ;
}
static struct V_5 * F_171 ( T_3 V_49 , T_5 V_142 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_179 ;
struct V_5 * V_5 ;
F_167 ( & V_179 , V_29 , V_4 ) ;
V_5 = F_172 ( V_49 , V_142 , & V_179 , 0 ) ;
F_169 ( & V_179 ) ;
return V_5 ;
}
static struct V_5 * F_173 ( T_5 V_142 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_179 ;
struct V_3 * V_3 = & V_29 -> V_72 ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_82 , V_180 ;
void T_4 * * V_81 ;
struct V_5 * V_5 ;
if ( ! F_126 ( V_135 ) )
return NULL ;
V_180 = F_64 ( V_4 , V_84 ) ;
F_35 () ;
if ( F_69 ( & V_41 -> V_46 , & V_81 , & V_82 ,
V_180 , 1 ) && V_82 < V_180 + V_84 ) {
F_37 () ;
return NULL ;
}
F_37 () ;
F_167 ( & V_179 , V_29 , V_180 ) ;
V_5 = F_174 ( V_142 | V_181 | V_182 | V_183 ,
V_184 , & V_179 , 0 , F_175 () , true ) ;
F_169 ( & V_179 ) ;
if ( V_5 )
F_176 ( V_5 ) ;
return V_5 ;
}
static struct V_5 * F_177 ( T_5 V_142 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_179 ;
struct V_5 * V_5 ;
F_167 ( & V_179 , V_29 , V_4 ) ;
V_5 = F_178 ( V_142 , & V_179 , 0 ) ;
F_169 ( & V_179 ) ;
return V_5 ;
}
static struct V_5 * F_179 ( T_5 V_142 ,
struct V_28 * V_29 , struct V_10 * V_23 ,
T_1 V_4 , bool V_58 )
{
struct V_5 * V_5 ;
int V_80 ;
int V_185 = - V_27 ;
if ( ! F_126 ( V_135 ) )
V_58 = false ;
V_80 = V_58 ? V_84 : 1 ;
if ( F_14 ( V_29 -> V_14 , V_80 ) )
goto V_186;
if ( V_23 -> V_35 ) {
if ( F_26 ( & V_23 -> V_36 ,
V_23 -> V_35 - V_80 ) > 0 )
goto V_187;
F_22 ( & V_23 -> V_36 , V_80 ) ;
}
if ( V_58 )
V_5 = F_173 ( V_142 , V_29 , V_4 ) ;
else
V_5 = F_177 ( V_142 , V_29 , V_4 ) ;
if ( V_5 ) {
F_180 ( V_5 ) ;
F_181 ( V_5 ) ;
return V_5 ;
}
V_185 = - V_145 ;
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - V_80 ) ;
V_187:
F_15 ( V_29 -> V_14 , V_80 ) ;
V_186:
return F_182 ( V_185 ) ;
}
static bool F_139 ( struct V_5 * V_5 , T_5 V_142 )
{
return F_183 ( V_5 ) > F_184 ( V_142 ) ;
}
static int F_140 ( struct V_5 * * V_6 , T_5 V_142 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_5 * V_188 , * V_189 ;
struct V_40 * V_190 ;
T_1 V_191 ;
int error ;
V_188 = * V_6 ;
V_191 = F_147 ( V_188 ) ;
V_190 = F_112 ( V_188 ) ;
V_142 &= ~ V_192 ;
V_189 = F_177 ( V_142 , V_29 , V_4 ) ;
if ( ! V_189 )
return - V_145 ;
F_185 ( V_189 ) ;
F_186 ( V_189 , V_188 ) ;
F_153 ( V_189 ) ;
F_154 ( V_189 ) ;
F_187 ( V_189 , V_191 ) ;
F_188 ( V_189 ) ;
F_68 ( & V_190 -> V_48 ) ;
error = F_29 ( V_190 , V_191 , V_188 ,
V_189 ) ;
if ( ! error ) {
F_72 ( V_189 , V_88 ) ;
F_79 ( V_188 , V_88 ) ;
}
F_75 ( & V_190 -> V_48 ) ;
if ( F_145 ( error ) ) {
V_188 = V_189 ;
} else {
F_189 ( V_188 , V_189 ) ;
F_190 ( V_189 ) ;
* V_6 = V_189 ;
}
F_191 ( V_188 ) ;
F_187 ( V_188 , 0 ) ;
F_53 ( V_188 ) ;
F_54 ( V_188 ) ;
F_54 ( V_188 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_5 V_142 ,
struct V_193 * V_194 , int * V_195 )
{
struct V_40 * V_41 = V_3 -> V_9 ;
struct V_28 * V_29 ;
struct V_10 * V_23 ;
struct V_193 * V_196 ;
struct V_148 * V_149 ;
struct V_5 * V_5 ;
T_3 V_49 ;
enum V_7 V_197 = V_8 ;
T_1 V_180 = V_4 ;
int error ;
int V_198 = 0 ;
int V_31 = 0 ;
if ( V_4 > ( V_199 >> V_77 ) )
return - V_200 ;
if ( V_8 == V_201 || V_8 == V_202 )
V_8 = V_203 ;
V_204:
V_49 . V_150 = 0 ;
V_5 = F_192 ( V_41 , V_4 ) ;
if ( F_90 ( V_5 ) ) {
V_49 = F_84 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_203 &&
( ( T_2 ) V_4 << V_77 ) >= F_193 ( V_3 ) ) {
error = - V_57 ;
goto V_205;
}
if ( V_5 && V_8 == V_206 )
F_194 ( V_5 ) ;
if ( V_5 && ! F_111 ( V_5 ) ) {
if ( V_8 != V_113 )
goto V_207;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_113 && ! V_49 . V_150 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_23 = F_7 ( V_3 -> V_34 ) ;
V_196 = V_194 ? : V_17 -> V_18 ;
if ( V_49 . V_150 ) {
V_5 = F_195 ( V_49 ) ;
if ( ! V_5 ) {
if ( V_195 ) {
* V_195 |= V_208 ;
F_71 ( V_209 ) ;
F_196 ( V_194 , V_209 ) ;
}
V_5 = F_171 ( V_49 , V_142 , V_29 , V_4 ) ;
if ( ! V_5 ) {
error = - V_145 ;
goto V_186;
}
}
F_117 ( V_5 ) ;
if ( ! F_146 ( V_5 ) || F_147 ( V_5 ) != V_49 . V_150 ||
! F_34 ( V_41 , V_4 , V_49 ) ) {
error = - V_85 ;
goto V_205;
}
if ( ! F_111 ( V_5 ) ) {
error = - V_210 ;
goto V_186;
}
F_197 ( V_5 ) ;
if ( F_139 ( V_5 , V_142 ) ) {
error = F_140 ( & V_5 , V_142 , V_29 , V_4 ) ;
if ( error )
goto V_186;
}
error = F_148 ( V_5 , V_196 , V_142 , & V_149 ,
false ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_41 , V_4 ,
F_38 ( V_49 ) ) ;
if ( error ) {
F_149 ( V_5 , V_149 , false ) ;
F_142 ( V_5 ) ;
}
}
if ( error )
goto V_186;
F_150 ( V_5 , V_149 , true , false ) ;
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
if ( V_8 == V_206 )
F_194 ( V_5 ) ;
F_142 ( V_5 ) ;
F_116 ( V_5 ) ;
F_143 ( V_49 ) ;
} else {
if ( V_41 -> V_137 != & V_138 )
goto V_211;
if ( V_212 == V_55 || V_197 == V_201 )
goto V_211;
if ( V_212 == V_56 )
goto V_213;
switch ( V_23 -> V_58 ) {
T_2 V_73 ;
T_1 V_214 ;
case V_51 :
goto V_211;
case V_53 :
V_214 = F_48 ( V_4 , V_84 ) ;
V_73 = F_48 ( F_193 ( V_3 ) , V_22 ) ;
if ( V_73 >= V_74 &&
V_73 >> V_77 >= V_214 )
goto V_213;
case V_54 :
if ( V_197 == V_202 )
goto V_213;
goto V_211;
}
V_213:
V_5 = F_179 ( V_142 , V_29 , V_23 ,
V_4 , true ) ;
if ( F_198 ( V_5 ) ) {
V_211: V_5 = F_179 ( V_142 , V_29 , V_23 ,
V_4 , false ) ;
}
if ( F_198 ( V_5 ) ) {
int V_215 = 5 ;
error = F_199 ( V_5 ) ;
V_5 = NULL ;
if ( error != - V_27 )
goto V_186;
while ( V_215 -- ) {
int V_75 ;
V_75 = F_41 ( V_23 , NULL , 1 ) ;
if ( V_75 == V_70 )
break;
if ( V_75 )
goto V_211;
}
goto V_186;
}
if ( F_52 ( V_5 ) )
V_180 = F_64 ( V_4 , V_84 ) ;
else
V_180 = V_4 ;
if ( V_8 == V_206 )
F_200 ( V_5 ) ;
error = F_148 ( V_5 , V_196 , V_142 , & V_149 ,
F_52 ( V_5 ) ) ;
if ( error )
goto V_187;
error = F_201 ( V_142 & V_216 ,
F_202 ( V_5 ) ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_41 , V_180 ,
NULL ) ;
F_203 () ;
}
if ( error ) {
F_149 ( V_5 , V_149 ,
F_52 ( V_5 ) ) ;
goto V_187;
}
F_150 ( V_5 , V_149 , false ,
F_52 ( V_5 ) ) ;
F_190 ( V_5 ) ;
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_31 += 1 << F_202 ( V_5 ) ;
V_3 -> V_37 += V_38 << F_202 ( V_5 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
V_31 = true ;
if ( F_52 ( V_5 ) &&
F_204 ( F_193 ( V_3 ) , V_22 ) <
V_180 + V_84 - 1 ) {
F_17 ( & V_23 -> V_71 ) ;
if ( F_43 ( & V_29 -> V_69 ) ) {
F_127 ( & V_29 -> V_69 ,
& V_23 -> V_69 ) ;
V_23 -> V_79 ++ ;
}
F_18 ( & V_23 -> V_71 ) ;
}
if ( V_8 == V_217 )
V_8 = V_206 ;
V_207:
if ( V_8 != V_206 && ! F_111 ( V_5 ) ) {
struct V_5 * V_218 = F_205 ( V_5 ) ;
int V_83 ;
for ( V_83 = 0 ; V_83 < ( 1 << F_202 ( V_218 ) ) ; V_83 ++ ) {
F_110 ( V_218 + V_83 ) ;
F_153 ( V_218 + V_83 ) ;
}
F_154 ( V_218 ) ;
}
}
if ( V_8 <= V_203 &&
( ( T_2 ) V_4 << V_77 ) >= F_193 ( V_3 ) ) {
if ( V_31 ) {
F_206 ( V_5 ) ;
F_207 ( V_5 ) ;
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
}
error = - V_57 ;
goto V_205;
}
* V_6 = V_5 + V_4 - V_180 ;
return 0 ;
V_187:
if ( V_23 -> V_35 )
F_28 ( & V_23 -> V_36 ,
1 << F_202 ( V_5 ) ) ;
F_15 ( V_29 -> V_14 , 1 << F_202 ( V_5 ) ) ;
if ( F_52 ( V_5 ) ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
goto V_211;
}
V_186:
if ( V_49 . V_150 && ! F_34 ( V_41 , V_4 , V_49 ) )
error = - V_85 ;
V_205:
if ( V_5 ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
if ( error == - V_27 && ! V_198 ++ ) {
V_29 = F_21 ( V_3 ) ;
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
goto V_204;
}
if ( error == - V_85 )
goto V_204;
return error ;
}
static int F_208 ( struct V_97 * V_98 , struct V_219 * V_220 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
T_5 V_142 = F_6 ( V_3 -> V_9 ) ;
enum V_7 V_8 ;
int error ;
int V_75 = V_221 ;
if ( F_145 ( V_3 -> V_160 ) ) {
struct V_161 * V_161 ;
F_17 ( & V_3 -> V_162 ) ;
V_161 = V_3 -> V_160 ;
if ( V_161 &&
V_161 -> V_163 &&
V_220 -> V_222 >= V_161 -> V_92 &&
V_220 -> V_222 < V_161 -> V_64 ) {
T_6 * V_223 ;
F_209 ( V_224 ) ;
V_75 = V_225 ;
if ( ( V_220 -> V_14 & V_226 ) &&
! ( V_220 -> V_14 & V_227 ) ) {
F_210 ( & V_98 -> V_228 -> V_229 ) ;
V_75 = V_230 ;
}
V_223 = V_161 -> V_163 ;
F_211 ( V_223 , & V_224 ,
V_231 ) ;
F_18 ( & V_3 -> V_162 ) ;
F_212 () ;
F_17 ( & V_3 -> V_162 ) ;
F_213 ( V_223 , & V_224 ) ;
F_18 ( & V_3 -> V_162 ) ;
return V_75 ;
}
F_18 ( & V_3 -> V_162 ) ;
}
V_8 = V_203 ;
if ( V_98 -> V_232 & V_233 )
V_8 = V_202 ;
else if ( V_98 -> V_232 & V_234 )
V_8 = V_201 ;
error = F_5 ( V_3 , V_220 -> V_222 , & V_220 -> V_5 , V_8 ,
V_142 , V_98 -> V_228 , & V_75 ) ;
if ( error )
return ( ( error == - V_145 ) ? V_235 : V_236 ) ;
return V_75 ;
}
unsigned long F_214 ( struct V_237 * V_237 ,
unsigned long V_238 , unsigned long V_239 ,
unsigned long V_222 , unsigned long V_14 )
{
unsigned long ( * V_240 ) ( struct V_237 * ,
unsigned long , unsigned long , unsigned long , unsigned long ) ;
unsigned long V_241 ;
unsigned long V_242 ;
unsigned long V_243 ;
unsigned long V_244 ;
unsigned long V_245 ;
if ( V_239 > V_246 )
return - V_145 ;
V_240 = V_17 -> V_18 -> V_247 ;
V_241 = V_240 ( V_237 , V_238 , V_239 , V_222 , V_14 ) ;
if ( ! F_126 ( V_135 ) )
return V_241 ;
if ( F_215 ( V_241 ) )
return V_241 ;
if ( V_241 & ~ V_248 )
return V_241 ;
if ( V_241 > V_246 - V_239 )
return V_241 ;
if ( V_212 == V_55 )
return V_241 ;
if ( V_239 < V_74 )
return V_241 ;
if ( V_14 & V_249 )
return V_241 ;
if ( V_238 )
return V_241 ;
if ( V_212 != V_56 ) {
struct V_11 * V_12 ;
if ( V_237 ) {
F_30 ( V_237 -> V_250 != & V_251 ) ;
V_12 = F_95 ( V_237 ) -> V_34 ;
} else {
if ( F_198 ( V_252 ) )
return V_241 ;
V_12 = V_252 -> V_253 ;
}
if ( F_7 ( V_12 ) -> V_58 == V_51 )
return V_241 ;
}
V_242 = ( V_222 << V_77 ) & ( V_74 - 1 ) ;
if ( V_242 && V_242 + V_239 < 2 * V_74 )
return V_241 ;
if ( ( V_241 & ( V_74 - 1 ) ) == V_242 )
return V_241 ;
V_243 = V_239 + V_74 - V_22 ;
if ( V_243 > V_246 )
return V_241 ;
if ( V_243 < V_239 )
return V_241 ;
V_244 = V_240 ( NULL , 0 , V_243 , 0 , V_14 ) ;
if ( F_215 ( V_244 ) )
return V_241 ;
if ( V_244 & ~ V_248 )
return V_241 ;
V_245 = V_244 & ( V_74 - 1 ) ;
V_244 += V_242 - V_245 ;
if ( V_245 > V_242 )
V_244 += V_74 ;
if ( V_244 > V_246 - V_239 )
return V_241 ;
return V_244 ;
}
static int F_216 ( struct V_97 * V_98 , struct V_170 * V_171 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
return F_217 ( & F_21 ( V_3 ) -> V_178 , V_98 , V_171 ) ;
}
static struct V_170 * F_218 ( struct V_97 * V_98 ,
unsigned long V_241 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
T_1 V_4 ;
V_4 = ( ( V_241 - V_98 -> V_102 ) >> V_77 ) + V_98 -> V_100 ;
return F_168 ( & F_21 ( V_3 ) -> V_178 , V_4 ) ;
}
int F_219 ( struct V_237 * V_237 , int V_39 , struct V_254 * V_255 )
{
struct V_3 * V_3 = F_95 ( V_237 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int V_256 = - V_145 ;
F_68 ( & V_29 -> V_39 ) ;
if ( V_39 && ! ( V_29 -> V_14 & V_156 ) ) {
if ( ! F_220 ( V_3 -> V_73 , V_255 ) )
goto V_257;
V_29 -> V_14 |= V_156 ;
F_221 ( V_237 -> V_258 ) ;
}
if ( ! V_39 && ( V_29 -> V_14 & V_156 ) && V_255 ) {
F_222 ( V_3 -> V_73 , V_255 ) ;
V_29 -> V_14 &= ~ V_156 ;
F_223 ( V_237 -> V_258 ) ;
}
V_256 = 0 ;
V_257:
F_75 ( & V_29 -> V_39 ) ;
return V_256 ;
}
static int F_224 ( struct V_237 * V_237 , struct V_97 * V_98 )
{
F_225 ( V_237 ) ;
V_98 -> V_176 = & V_259 ;
if ( F_126 ( V_135 ) &&
( ( V_98 -> V_102 + ~ V_76 ) & V_76 ) <
( V_98 -> V_101 & V_76 ) ) {
F_226 ( V_98 , V_98 -> V_232 ) ;
}
return 0 ;
}
static struct V_3 * F_227 ( struct V_11 * V_12 , const struct V_3 * V_260 ,
T_7 V_173 , T_8 V_261 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( F_16 ( V_12 ) )
return NULL ;
V_3 = F_228 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_175 = F_229 () ;
F_230 ( V_3 , V_260 , V_173 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_262 = V_3 -> V_116 = V_3 -> V_115 = V_117 ;
V_3 -> V_263 = F_231 () ;
V_29 = F_21 ( V_3 ) ;
memset ( V_29 , 0 , ( char * ) V_3 - ( char * ) V_29 ) ;
F_232 ( & V_29 -> V_39 ) ;
V_29 -> V_130 = V_264 ;
V_29 -> V_14 = V_14 & V_16 ;
F_233 ( & V_29 -> V_69 ) ;
F_233 ( & V_29 -> V_139 ) ;
F_234 ( & V_29 -> V_141 ) ;
F_235 ( V_3 ) ;
switch ( V_173 & V_265 ) {
default:
V_3 -> V_266 = & V_267 ;
F_236 ( V_3 , V_173 , V_261 ) ;
break;
case V_268 :
V_3 -> V_9 -> V_137 = & V_138 ;
V_3 -> V_266 = & V_269 ;
V_3 -> V_270 = & V_251 ;
F_237 ( & V_29 -> V_178 ,
F_165 ( V_23 ) ) ;
break;
case V_271 :
F_238 ( V_3 ) ;
V_3 -> V_73 = 2 * V_272 ;
V_3 -> V_266 = & V_273 ;
V_3 -> V_270 = & V_274 ;
break;
case V_275 :
F_237 ( & V_29 -> V_178 , NULL ) ;
break;
}
} else
F_19 ( V_12 ) ;
return V_3 ;
}
bool F_239 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_155 )
return false ;
return V_41 -> V_155 -> V_34 -> V_276 == & V_277 ;
}
static int
F_240 ( struct V_237 * V_237 , struct V_40 * V_41 ,
T_2 V_63 , unsigned V_239 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_278 )
{
struct V_3 * V_3 = V_41 -> V_155 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_4 = V_63 >> V_77 ;
if ( F_145 ( V_29 -> V_130 ) ) {
if ( V_29 -> V_130 & V_279 )
return - V_133 ;
if ( ( V_29 -> V_130 & V_132 ) && V_63 + V_239 > V_3 -> V_73 )
return - V_133 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_206 ) ;
}
static int
F_241 ( struct V_237 * V_237 , struct V_40 * V_41 ,
T_2 V_63 , unsigned V_239 , unsigned V_280 ,
struct V_5 * V_5 , void * V_278 )
{
struct V_3 * V_3 = V_41 -> V_155 ;
if ( V_63 + V_280 > V_3 -> V_73 )
F_124 ( V_3 , V_63 + V_280 ) ;
if ( ! F_111 ( V_5 ) ) {
struct V_5 * V_218 = F_205 ( V_5 ) ;
if ( F_242 ( V_5 ) ) {
int V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
if ( V_218 + V_83 == V_5 )
continue;
F_110 ( V_218 + V_83 ) ;
F_153 ( V_218 + V_83 ) ;
}
}
if ( V_280 < V_22 ) {
unsigned V_281 = V_63 & ( V_22 - 1 ) ;
F_243 ( V_5 , 0 , V_281 ,
V_281 + V_280 , V_22 ) ;
}
F_154 ( V_218 ) ;
}
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return V_280 ;
}
static T_9 F_244 ( struct V_282 * V_283 , struct V_284 * V_285 )
{
struct V_237 * V_237 = V_283 -> V_286 ;
struct V_3 * V_3 = F_95 ( V_237 ) ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_242 ;
enum V_7 V_8 = V_113 ;
int error = 0 ;
T_9 V_256 = 0 ;
T_2 * V_287 = & V_283 -> V_288 ;
if ( ! F_245 ( V_285 ) )
V_8 = V_203 ;
V_4 = * V_287 >> V_77 ;
V_242 = * V_287 & ~ V_248 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_289 ;
unsigned long V_80 , V_75 ;
T_2 V_73 = F_193 ( V_3 ) ;
V_289 = V_73 >> V_77 ;
if ( V_4 > V_289 )
break;
if ( V_4 == V_289 ) {
V_80 = V_73 & ~ V_248 ;
if ( V_80 <= V_242 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_57 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_203 )
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
}
V_80 = V_22 ;
V_73 = F_193 ( V_3 ) ;
V_289 = V_73 >> V_77 ;
if ( V_4 == V_289 ) {
V_80 = V_73 & ~ V_248 ;
if ( V_80 <= V_242 ) {
if ( V_5 )
F_54 ( V_5 ) ;
break;
}
}
V_80 -= V_242 ;
if ( V_5 ) {
if ( F_246 ( V_41 ) )
F_153 ( V_5 ) ;
if ( ! V_242 )
F_194 ( V_5 ) ;
} else {
V_5 = F_247 ( 0 ) ;
F_185 ( V_5 ) ;
}
V_75 = F_248 ( V_5 , V_242 , V_80 , V_285 ) ;
V_256 += V_75 ;
V_242 += V_75 ;
V_4 += V_242 >> V_77 ;
V_242 &= ~ V_248 ;
F_54 ( V_5 ) ;
if ( ! F_249 ( V_285 ) )
break;
if ( V_75 < V_80 ) {
error = - V_290 ;
break;
}
F_104 () ;
}
* V_287 = ( ( T_2 ) V_4 << V_77 ) + V_242 ;
F_225 ( V_237 ) ;
return V_256 ? V_256 : error ;
}
static T_9 F_250 ( struct V_237 * V_291 , T_2 * V_287 ,
struct V_292 * V_293 , T_10 V_239 ,
unsigned int V_14 )
{
struct V_40 * V_41 = V_291 -> V_258 ;
struct V_3 * V_3 = V_41 -> V_155 ;
unsigned int V_294 , V_295 , V_296 ;
struct V_5 * V_21 [ V_297 ] ;
struct V_298 V_299 [ V_297 ] ;
struct V_5 * V_5 ;
T_1 V_4 , V_289 ;
T_2 V_300 , V_301 ;
int error , V_302 ;
struct V_303 V_304 = {
. V_21 = V_21 ,
. V_299 = V_299 ,
. V_305 = V_297 ,
. V_14 = V_14 ,
. V_306 = & V_307 ,
. V_308 = V_309 ,
} ;
V_300 = F_193 ( V_3 ) ;
if ( F_145 ( * V_287 >= V_300 ) )
return 0 ;
V_301 = V_300 - * V_287 ;
if ( F_145 ( V_301 < V_239 ) )
V_239 = V_301 ;
if ( F_251 ( V_293 , & V_304 ) )
return - V_145 ;
V_4 = * V_287 >> V_77 ;
V_294 = * V_287 & ~ V_248 ;
V_296 = ( V_239 + V_294 + V_22 - 1 ) >> V_77 ;
V_295 = F_3 ( V_296 , V_304 . V_305 ) ;
V_304 . V_295 = F_252 ( V_41 , V_4 ,
V_295 , V_304 . V_21 ) ;
V_4 += V_304 . V_295 ;
error = 0 ;
while ( V_304 . V_295 < V_295 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_203 ) ;
if ( error )
break;
F_53 ( V_5 ) ;
V_304 . V_21 [ V_304 . V_295 ++ ] = V_5 ;
V_4 ++ ;
}
V_4 = * V_287 >> V_77 ;
V_295 = V_304 . V_295 ;
V_304 . V_295 = 0 ;
for ( V_302 = 0 ; V_302 < V_295 ; V_302 ++ ) {
unsigned int V_310 ;
if ( ! V_239 )
break;
V_310 = F_253 (unsigned long, len, PAGE_SIZE - loff) ;
V_5 = V_304 . V_21 [ V_302 ] ;
if ( ! F_111 ( V_5 ) || V_5 -> V_41 != V_41 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_203 ) ;
if ( error )
break;
F_53 ( V_5 ) ;
F_54 ( V_304 . V_21 [ V_302 ] ) ;
V_304 . V_21 [ V_302 ] = V_5 ;
}
V_300 = F_193 ( V_3 ) ;
V_289 = ( V_300 - 1 ) >> V_77 ;
if ( F_145 ( ! V_300 || V_4 > V_289 ) )
break;
if ( V_289 == V_4 ) {
unsigned int V_311 ;
V_311 = ( ( V_300 - 1 ) & ~ V_248 ) + 1 ;
if ( V_311 <= V_294 )
break;
V_310 = F_3 ( V_310 , V_311 - V_294 ) ;
V_239 = V_310 ;
}
V_304 . V_299 [ V_302 ] . V_242 = V_294 ;
V_304 . V_299 [ V_302 ] . V_239 = V_310 ;
V_239 -= V_310 ;
V_294 = 0 ;
V_304 . V_295 ++ ;
V_4 ++ ;
}
while ( V_302 < V_295 )
F_54 ( V_304 . V_21 [ V_302 ++ ] ) ;
if ( V_304 . V_295 )
error = F_254 ( V_293 , & V_304 ) ;
F_255 ( & V_304 ) ;
if ( error > 0 ) {
* V_287 += error ;
F_225 ( V_291 ) ;
}
return error ;
}
static T_1 F_256 ( struct V_40 * V_41 ,
T_1 V_4 , T_1 V_93 , int V_312 )
{
struct V_5 * V_5 ;
struct V_103 V_104 ;
T_1 V_105 [ V_106 ] ;
bool V_313 = false ;
int V_83 ;
F_98 ( & V_104 , 0 ) ;
V_104 . V_80 = 1 ;
while ( ! V_313 ) {
V_104 . V_80 = F_100 ( V_41 , V_4 ,
V_104 . V_80 , V_104 . V_21 , V_105 ) ;
if ( ! V_104 . V_80 ) {
if ( V_312 == V_314 )
V_4 = V_93 ;
break;
}
for ( V_83 = 0 ; V_83 < V_104 . V_80 ; V_83 ++ , V_4 ++ ) {
if ( V_4 < V_105 [ V_83 ] ) {
if ( V_312 == V_315 ) {
V_313 = true ;
break;
}
V_4 = V_105 [ V_83 ] ;
}
V_5 = V_104 . V_21 [ V_83 ] ;
if ( V_5 && ! F_90 ( V_5 ) ) {
if ( ! F_111 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_93 ||
( V_5 && V_312 == V_314 ) ||
( ! V_5 && V_312 == V_315 ) ) {
V_313 = true ;
break;
}
}
F_101 ( & V_104 ) ;
F_103 ( & V_104 ) ;
V_104 . V_80 = V_106 ;
F_104 () ;
}
return V_4 ;
}
static T_2 F_257 ( struct V_237 * V_237 , T_2 V_242 , int V_312 )
{
struct V_40 * V_41 = V_237 -> V_258 ;
struct V_3 * V_3 = V_41 -> V_155 ;
T_1 V_92 , V_93 ;
T_2 V_316 ;
if ( V_312 != V_314 && V_312 != V_315 )
return F_258 ( V_237 , V_242 , V_312 ,
V_199 , F_193 ( V_3 ) ) ;
F_259 ( V_3 ) ;
if ( V_242 < 0 )
V_242 = - V_57 ;
else if ( V_242 >= V_3 -> V_73 )
V_242 = - V_317 ;
else {
V_92 = V_242 >> V_77 ;
V_93 = ( V_3 -> V_73 + V_22 - 1 ) >> V_77 ;
V_316 = F_256 ( V_41 , V_92 , V_93 , V_312 ) ;
V_316 <<= V_77 ;
if ( V_316 > V_242 ) {
if ( V_316 < V_3 -> V_73 )
V_242 = V_316 ;
else if ( V_312 == V_314 )
V_242 = - V_317 ;
else
V_242 = V_3 -> V_73 ;
}
}
if ( V_242 >= 0 )
V_242 = F_260 ( V_237 , V_242 , V_199 ) ;
F_261 ( V_3 ) ;
return V_242 ;
}
static void F_262 ( struct V_40 * V_41 )
{
struct V_94 V_95 ;
void * * V_96 ;
T_1 V_92 ;
struct V_5 * V_5 ;
F_263 () ;
V_92 = 0 ;
F_35 () ;
F_86 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_87 ( V_96 ) ;
if ( ! V_5 || F_264 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_96 = F_89 ( & V_95 ) ;
continue;
}
} else if ( F_265 ( V_5 ) - F_266 ( V_5 ) > 1 ) {
F_68 ( & V_41 -> V_48 ) ;
F_267 ( & V_41 -> V_46 , V_95 . V_4 ,
V_318 ) ;
F_75 ( & V_41 -> V_48 ) ;
}
if ( F_91 () ) {
F_92 () ;
V_96 = F_93 ( & V_95 ) ;
}
}
F_37 () ;
}
static int F_268 ( struct V_40 * V_41 )
{
struct V_94 V_95 ;
void * * V_96 ;
T_1 V_92 ;
struct V_5 * V_5 ;
int error , V_319 ;
F_262 ( V_41 ) ;
error = 0 ;
for ( V_319 = 0 ; V_319 <= V_320 ; V_319 ++ ) {
if ( ! F_269 ( & V_41 -> V_46 , V_318 ) )
break;
if ( ! V_319 )
F_270 () ;
else if ( F_271 ( ( V_321 << V_319 ) / 200 ) )
V_319 = V_320 ;
V_92 = 0 ;
F_35 () ;
F_272 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_87 ( V_96 ) ;
if ( F_264 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_96 = F_89 ( & V_95 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_265 ( V_5 ) - F_266 ( V_5 ) != 1 ) {
if ( V_319 < V_320 )
goto V_322;
error = - V_323 ;
}
F_68 ( & V_41 -> V_48 ) ;
F_273 ( & V_41 -> V_46 ,
V_95 . V_4 , V_318 ) ;
F_75 ( & V_41 -> V_48 ) ;
V_322:
if ( F_91 () ) {
F_92 () ;
V_96 = F_93 ( & V_95 ) ;
}
}
F_37 () ;
}
return error ;
}
int F_274 ( struct V_237 * V_237 , unsigned int V_130 )
{
struct V_3 * V_3 = F_95 ( V_237 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int error ;
if ( V_237 -> V_250 != & V_251 )
return - V_57 ;
if ( ! ( V_237 -> V_324 & V_325 ) )
return - V_133 ;
if ( V_130 & ~ ( unsigned int ) V_326 )
return - V_57 ;
F_259 ( V_3 ) ;
if ( V_29 -> V_130 & V_264 ) {
error = - V_133 ;
goto V_205;
}
if ( ( V_130 & V_279 ) && ! ( V_29 -> V_130 & V_279 ) ) {
error = F_275 ( V_237 -> V_258 ) ;
if ( error )
goto V_205;
error = F_268 ( V_237 -> V_258 ) ;
if ( error ) {
F_276 ( V_237 -> V_258 ) ;
goto V_205;
}
}
V_29 -> V_130 |= V_130 ;
error = 0 ;
V_205:
F_261 ( V_3 ) ;
return error ;
}
int F_277 ( struct V_237 * V_237 )
{
if ( V_237 -> V_250 != & V_251 )
return - V_57 ;
return F_21 ( F_95 ( V_237 ) ) -> V_130 ;
}
long F_278 ( struct V_237 * V_237 , unsigned int V_327 , unsigned long V_328 )
{
long error ;
switch ( V_327 ) {
case V_329 :
if ( V_328 > V_330 )
return - V_57 ;
error = F_274 ( V_237 , V_328 ) ;
break;
case V_331 :
error = F_277 ( V_237 ) ;
break;
default:
error = - V_57 ;
break;
}
return error ;
}
static long F_279 ( struct V_237 * V_237 , int V_173 , T_2 V_242 ,
T_2 V_239 )
{
struct V_3 * V_3 = F_95 ( V_237 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_161 V_161 ;
T_1 V_92 , V_4 , V_93 ;
int error ;
if ( V_173 & ~ ( V_332 | V_333 ) )
return - V_334 ;
F_259 ( V_3 ) ;
if ( V_173 & V_333 ) {
struct V_40 * V_41 = V_237 -> V_258 ;
T_2 V_335 = F_48 ( V_242 , V_22 ) ;
T_2 V_336 = F_64 ( V_242 + V_239 , V_22 ) - 1 ;
F_280 ( V_223 ) ;
if ( V_29 -> V_130 & V_279 ) {
error = - V_133 ;
goto V_151;
}
V_161 . V_163 = & V_223 ;
V_161 . V_92 = V_335 >> V_77 ;
V_161 . V_64 = ( V_336 + 1 ) >> V_77 ;
F_17 ( & V_3 -> V_162 ) ;
V_3 -> V_160 = & V_161 ;
F_18 ( & V_3 -> V_162 ) ;
if ( ( V_337 ) V_336 > ( V_337 ) V_335 )
F_125 ( V_41 , V_335 ,
1 + V_336 - V_335 , 0 ) ;
F_118 ( V_3 , V_242 , V_242 + V_239 - 1 ) ;
F_17 ( & V_3 -> V_162 ) ;
V_3 -> V_160 = NULL ;
F_281 ( & V_223 ) ;
F_18 ( & V_3 -> V_162 ) ;
error = 0 ;
goto V_151;
}
error = F_282 ( V_3 , V_242 + V_239 ) ;
if ( error )
goto V_151;
if ( ( V_29 -> V_130 & V_132 ) && V_242 + V_239 > V_3 -> V_73 ) {
error = - V_133 ;
goto V_151;
}
V_92 = V_242 >> V_77 ;
V_93 = ( V_242 + V_239 + V_22 - 1 ) >> V_77 ;
if ( V_23 -> V_35 && V_93 - V_92 > V_23 -> V_35 ) {
error = - V_27 ;
goto V_151;
}
V_161 . V_163 = NULL ;
V_161 . V_92 = V_92 ;
V_161 . V_64 = V_92 ;
V_161 . V_338 = 0 ;
V_161 . V_164 = 0 ;
F_17 ( & V_3 -> V_162 ) ;
V_3 -> V_160 = & V_161 ;
F_18 ( & V_3 -> V_162 ) ;
for ( V_4 = V_92 ; V_4 < V_93 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_283 ( V_17 ) )
error = - V_339 ;
else if ( V_161 . V_164 > V_161 . V_338 )
error = - V_145 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_217 ) ;
if ( error ) {
if ( V_4 > V_92 ) {
F_105 ( V_3 ,
( T_2 ) V_92 << V_77 ,
( ( T_2 ) V_4 << V_77 ) - 1 , true ) ;
}
goto V_340;
}
V_161 . V_64 ++ ;
if ( ! F_111 ( V_5 ) )
V_161 . V_338 ++ ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
F_104 () ;
}
if ( ! ( V_173 & V_332 ) && V_242 + V_239 > V_3 -> V_73 )
F_124 ( V_3 , V_242 + V_239 ) ;
V_3 -> V_115 = V_117 ;
V_340:
F_17 ( & V_3 -> V_162 ) ;
V_3 -> V_160 = NULL ;
F_18 ( & V_3 -> V_162 ) ;
V_151:
F_261 ( V_3 ) ;
return error ;
}
static int F_284 ( struct V_120 * V_120 , struct V_341 * V_342 )
{
struct V_10 * V_23 = F_7 ( V_120 -> V_343 ) ;
V_342 -> V_344 = V_345 ;
V_342 -> V_346 = V_22 ;
V_342 -> V_347 = V_348 ;
if ( V_23 -> V_35 ) {
V_342 -> V_349 = V_23 -> V_35 ;
V_342 -> V_350 =
V_342 -> V_351 = V_23 -> V_35 -
F_285 ( & V_23 -> V_36 ) ;
}
if ( V_23 -> V_24 ) {
V_342 -> V_352 = V_23 -> V_24 ;
V_342 -> V_353 = V_23 -> V_26 ;
}
return 0 ;
}
static int
F_286 ( struct V_3 * V_260 , struct V_120 * V_120 , T_7 V_173 , T_8 V_261 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_227 ( V_260 -> V_34 , V_260 , V_173 , V_261 , V_16 ) ;
if ( V_3 ) {
error = F_287 ( V_260 , V_3 ) ;
if ( error )
goto V_354;
error = F_288 ( V_3 , V_260 ,
& V_120 -> V_355 ,
V_356 , NULL ) ;
if ( error && error != - V_334 )
goto V_354;
error = 0 ;
V_260 -> V_73 += V_272 ;
V_260 -> V_115 = V_260 -> V_116 = V_117 ;
F_289 ( V_120 , V_3 ) ;
F_290 ( V_120 ) ;
}
return error ;
V_354:
F_49 ( V_3 ) ;
return error ;
}
static int
F_291 ( struct V_3 * V_260 , struct V_120 * V_120 , T_7 V_173 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_227 ( V_260 -> V_34 , V_260 , V_173 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_288 ( V_3 , V_260 ,
NULL ,
V_356 , NULL ) ;
if ( error && error != - V_334 )
goto V_354;
error = F_287 ( V_260 , V_3 ) ;
if ( error )
goto V_354;
F_292 ( V_120 , V_3 ) ;
}
return error ;
V_354:
F_49 ( V_3 ) ;
return error ;
}
static int F_293 ( struct V_3 * V_260 , struct V_120 * V_120 , T_7 V_173 )
{
int error ;
if ( ( error = F_286 ( V_260 , V_120 , V_173 | V_271 , 0 ) ) )
return error ;
F_238 ( V_260 ) ;
return 0 ;
}
static int F_294 ( struct V_3 * V_260 , struct V_120 * V_120 , T_7 V_173 ,
bool V_357 )
{
return F_286 ( V_260 , V_120 , V_173 | V_268 , 0 ) ;
}
static int F_295 ( struct V_120 * V_358 , struct V_3 * V_260 , struct V_120 * V_120 )
{
struct V_3 * V_3 = V_123 ( V_358 ) ;
int V_75 ;
V_75 = F_16 ( V_3 -> V_34 ) ;
if ( V_75 )
goto V_151;
V_260 -> V_73 += V_272 ;
V_3 -> V_115 = V_260 -> V_115 = V_260 -> V_116 = V_117 ;
F_238 ( V_3 ) ;
F_296 ( V_3 ) ;
F_290 ( V_120 ) ;
F_289 ( V_120 , V_3 ) ;
V_151:
return V_75 ;
}
static int F_297 ( struct V_3 * V_260 , struct V_120 * V_120 )
{
struct V_3 * V_3 = V_123 ( V_120 ) ;
if ( V_3 -> V_359 > 1 && ! F_298 ( V_3 -> V_126 ) )
F_19 ( V_3 -> V_34 ) ;
V_260 -> V_73 -= V_272 ;
V_3 -> V_115 = V_260 -> V_115 = V_260 -> V_116 = V_117 ;
F_299 ( V_3 ) ;
F_300 ( V_120 ) ;
return 0 ;
}
static int F_301 ( struct V_3 * V_260 , struct V_120 * V_120 )
{
if ( ! F_302 ( V_120 ) )
return - V_360 ;
F_299 ( V_123 ( V_120 ) ) ;
F_299 ( V_260 ) ;
return F_297 ( V_260 , V_120 ) ;
}
static int F_303 ( struct V_3 * V_361 , struct V_120 * V_358 , struct V_3 * V_362 , struct V_120 * V_363 )
{
bool V_364 = F_304 ( V_358 ) ;
bool V_365 = F_304 ( V_363 ) ;
if ( V_361 != V_362 && V_364 != V_365 ) {
if ( V_364 ) {
F_299 ( V_361 ) ;
F_238 ( V_362 ) ;
} else {
F_299 ( V_362 ) ;
F_238 ( V_361 ) ;
}
}
V_361 -> V_115 = V_361 -> V_116 =
V_362 -> V_115 = V_362 -> V_116 =
V_123 ( V_358 ) -> V_115 =
V_123 ( V_363 ) -> V_115 = V_117 ;
return 0 ;
}
static int F_305 ( struct V_3 * V_361 , struct V_120 * V_358 )
{
struct V_120 * V_366 ;
int error ;
V_366 = F_306 ( V_358 -> V_367 , & V_358 -> V_355 ) ;
if ( ! V_366 )
return - V_145 ;
error = F_286 ( V_361 , V_366 ,
V_368 | V_369 , V_370 ) ;
F_300 ( V_366 ) ;
if ( error )
return error ;
F_307 ( V_366 ) ;
return 0 ;
}
static int F_308 ( struct V_3 * V_361 , struct V_120 * V_358 , struct V_3 * V_362 , struct V_120 * V_363 , unsigned int V_14 )
{
struct V_3 * V_3 = V_123 ( V_358 ) ;
int V_371 = F_298 ( V_3 -> V_126 ) ;
if ( V_14 & ~ ( V_372 | V_373 | V_374 ) )
return - V_57 ;
if ( V_14 & V_373 )
return F_303 ( V_361 , V_358 , V_362 , V_363 ) ;
if ( ! F_302 ( V_363 ) )
return - V_360 ;
if ( V_14 & V_374 ) {
int error ;
error = F_305 ( V_361 , V_358 ) ;
if ( error )
return error ;
}
if ( F_309 ( V_363 ) ) {
( void ) F_297 ( V_362 , V_363 ) ;
if ( V_371 ) {
F_299 ( V_123 ( V_363 ) ) ;
F_299 ( V_361 ) ;
}
} else if ( V_371 ) {
F_299 ( V_361 ) ;
F_238 ( V_362 ) ;
}
V_361 -> V_73 -= V_272 ;
V_362 -> V_73 += V_272 ;
V_361 -> V_115 = V_361 -> V_116 =
V_362 -> V_115 = V_362 -> V_116 =
V_3 -> V_115 = V_117 ;
return 0 ;
}
static int F_310 ( struct V_3 * V_260 , struct V_120 * V_120 , const char * V_375 )
{
int error ;
int V_239 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_28 * V_29 ;
V_239 = strlen ( V_375 ) + 1 ;
if ( V_239 > V_22 )
return - V_376 ;
V_3 = F_227 ( V_260 -> V_34 , V_260 , V_275 | V_377 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_27 ;
error = F_288 ( V_3 , V_260 , & V_120 -> V_355 ,
V_356 , NULL ) ;
if ( error ) {
if ( error != - V_334 ) {
F_49 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_3 -> V_73 = V_239 - 1 ;
if ( V_239 <= V_378 ) {
V_3 -> V_379 = F_311 ( V_375 , V_239 , V_152 ) ;
if ( ! V_3 -> V_379 ) {
F_49 ( V_3 ) ;
return - V_145 ;
}
V_3 -> V_266 = & V_380 ;
} else {
F_312 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_206 ) ;
if ( error ) {
F_49 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_137 = & V_138 ;
V_3 -> V_266 = & V_381 ;
memcpy ( F_313 ( V_5 ) , V_375 , V_239 ) ;
F_154 ( V_5 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
V_260 -> V_73 += V_272 ;
V_260 -> V_115 = V_260 -> V_116 = V_117 ;
F_289 ( V_120 , V_3 ) ;
F_290 ( V_120 ) ;
return 0 ;
}
static void F_314 ( void * V_328 )
{
F_194 ( V_328 ) ;
F_54 ( V_328 ) ;
}
static const char * F_315 ( struct V_120 * V_120 ,
struct V_3 * V_3 ,
struct V_382 * V_313 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_120 ) {
V_5 = F_316 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_182 ( - V_383 ) ;
if ( ! F_111 ( V_5 ) ) {
F_54 ( V_5 ) ;
return F_182 ( - V_383 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_113 ) ;
if ( error )
return F_182 ( error ) ;
F_53 ( V_5 ) ;
}
F_317 ( V_313 , F_314 , V_5 ) ;
return F_313 ( V_5 ) ;
}
static int V_356 ( struct V_3 * V_3 ,
const struct V_384 * V_385 ,
void * V_386 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
const struct V_384 * V_384 ;
struct V_387 * V_388 ;
T_10 V_239 ;
for ( V_384 = V_385 ; V_384 -> V_389 != NULL ; V_384 ++ ) {
V_388 = F_318 ( V_384 -> V_390 , V_384 -> V_391 ) ;
if ( ! V_388 )
return - V_145 ;
V_239 = strlen ( V_384 -> V_389 ) + 1 ;
V_388 -> V_389 = F_319 ( V_392 + V_239 ,
V_152 ) ;
if ( ! V_388 -> V_389 ) {
F_320 ( V_388 ) ;
return - V_145 ;
}
memcpy ( V_388 -> V_389 , V_393 ,
V_392 ) ;
memcpy ( V_388 -> V_389 + V_392 ,
V_384 -> V_389 , V_239 ) ;
F_321 ( & V_29 -> V_141 , V_388 ) ;
}
return 0 ;
}
static int F_322 ( const struct V_394 * V_395 ,
struct V_120 * V_396 , struct V_3 * V_3 ,
const char * V_389 , void * V_172 , T_10 V_15 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_389 = F_323 ( V_395 , V_389 ) ;
return F_324 ( & V_29 -> V_141 , V_389 , V_172 , V_15 ) ;
}
static int F_325 ( const struct V_394 * V_395 ,
struct V_120 * V_396 , struct V_3 * V_3 ,
const char * V_389 , const void * V_390 ,
T_10 V_15 , int V_14 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_389 = F_323 ( V_395 , V_389 ) ;
return F_326 ( & V_29 -> V_141 , V_389 , V_390 , V_15 , V_14 ) ;
}
static T_9 F_327 ( struct V_120 * V_120 , char * V_172 , T_10 V_15 )
{
struct V_28 * V_29 = F_21 ( V_123 ( V_120 ) ) ;
return F_328 ( V_123 ( V_120 ) , & V_29 -> V_141 , V_172 , V_15 ) ;
}
static struct V_120 * F_329 ( struct V_120 * V_397 )
{
return F_182 ( - V_398 ) ;
}
static int F_330 ( struct V_3 * V_399 , void * V_400 )
{
T_11 * V_401 = V_400 ;
T_12 V_402 = V_401 [ 2 ] ;
V_402 = ( V_402 << 32 ) | V_401 [ 1 ] ;
return V_399 -> V_175 == V_402 && V_401 [ 0 ] == V_399 -> V_263 ;
}
static struct V_120 * F_331 ( struct V_11 * V_12 ,
struct V_403 * V_403 , int V_404 , int V_405 )
{
struct V_3 * V_3 ;
struct V_120 * V_120 = NULL ;
V_337 V_402 ;
if ( V_404 < 3 )
return NULL ;
V_402 = V_403 -> V_406 [ 2 ] ;
V_402 = ( V_402 << 32 ) | V_403 -> V_406 [ 1 ] ;
V_3 = F_332 ( V_12 , ( unsigned long ) ( V_402 + V_403 -> V_406 [ 0 ] ) ,
F_330 , V_403 -> V_406 ) ;
if ( V_3 ) {
V_120 = F_333 ( V_3 ) ;
F_49 ( V_3 ) ;
}
return V_120 ;
}
static int F_334 ( struct V_3 * V_3 , T_11 * V_401 , int * V_239 ,
struct V_3 * V_407 )
{
if ( * V_239 < 3 ) {
* V_239 = 3 ;
return V_408 ;
}
if ( F_335 ( V_3 ) ) {
static F_336 ( V_39 ) ;
F_17 ( & V_39 ) ;
if ( F_335 ( V_3 ) )
F_337 ( V_3 ,
V_3 -> V_175 + V_3 -> V_263 ) ;
F_18 ( & V_39 ) ;
}
V_401 [ 0 ] = V_3 -> V_263 ;
V_401 [ 1 ] = V_3 -> V_175 ;
V_401 [ 2 ] = ( ( T_12 ) V_3 -> V_175 ) >> 32 ;
* V_239 = 3 ;
return 1 ;
}
static int F_338 ( char * V_409 , struct V_10 * V_23 ,
bool V_410 )
{
char * V_411 , * V_390 , * V_412 ;
struct V_170 * V_171 = NULL ;
T_13 V_413 ;
T_14 V_414 ;
while ( V_409 != NULL ) {
V_411 = V_409 ;
for (; ; ) {
V_409 = strchr ( V_409 , ',' ) ;
if ( V_409 == NULL )
break;
V_409 ++ ;
if ( ! isdigit ( * V_409 ) ) {
V_409 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_411 )
continue;
if ( ( V_390 = strchr ( V_411 , '=' ) ) != NULL ) {
* V_390 ++ = 0 ;
} else {
F_339 ( L_9 ,
V_411 ) ;
goto error;
}
if ( ! strcmp ( V_411 , L_10 ) ) {
unsigned long long V_15 ;
V_15 = F_340 ( V_390 , & V_412 ) ;
if ( * V_412 == '%' ) {
V_15 <<= V_77 ;
V_15 *= V_1 ;
F_341 ( V_15 , 100 ) ;
V_412 ++ ;
}
if ( * V_412 )
goto V_415;
V_23 -> V_35 =
F_204 ( V_15 , V_22 ) ;
} else if ( ! strcmp ( V_411 , L_11 ) ) {
V_23 -> V_35 = F_340 ( V_390 , & V_412 ) ;
if ( * V_412 )
goto V_415;
} else if ( ! strcmp ( V_411 , L_12 ) ) {
V_23 -> V_24 = F_340 ( V_390 , & V_412 ) ;
if ( * V_412 )
goto V_415;
} else if ( ! strcmp ( V_411 , L_13 ) ) {
if ( V_410 )
continue;
V_23 -> V_173 = F_342 ( V_390 , & V_412 , 8 ) & 07777 ;
if ( * V_412 )
goto V_415;
} else if ( ! strcmp ( V_411 , L_14 ) ) {
if ( V_410 )
continue;
V_413 = F_342 ( V_390 , & V_412 , 0 ) ;
if ( * V_412 )
goto V_415;
V_23 -> V_413 = F_343 ( F_344 () , V_413 ) ;
if ( ! F_345 ( V_23 -> V_413 ) )
goto V_415;
} else if ( ! strcmp ( V_411 , L_15 ) ) {
if ( V_410 )
continue;
V_414 = F_342 ( V_390 , & V_412 , 0 ) ;
if ( * V_412 )
goto V_415;
V_23 -> V_414 = F_346 ( F_344 () , V_414 ) ;
if ( ! F_347 ( V_23 -> V_414 ) )
goto V_415;
#ifdef V_135
} else if ( ! strcmp ( V_411 , L_16 ) ) {
int V_58 ;
V_58 = F_39 ( V_390 ) ;
if ( V_58 < 0 )
goto V_415;
if ( ! F_348 () &&
V_58 != V_51 )
goto V_415;
V_23 -> V_58 = V_58 ;
#endif
#ifdef F_349
} else if ( ! strcmp ( V_411 , L_17 ) ) {
F_350 ( V_171 ) ;
V_171 = NULL ;
if ( F_351 ( V_390 , & V_171 ) )
goto V_415;
#endif
} else {
F_339 ( L_18 , V_411 ) ;
goto error;
}
}
V_23 -> V_171 = V_171 ;
return 0 ;
V_415:
F_339 ( L_19 ,
V_390 , V_411 ) ;
error:
F_350 ( V_171 ) ;
return 1 ;
}
static int F_352 ( struct V_11 * V_12 , int * V_14 , char * V_416 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
struct V_10 V_417 = * V_23 ;
unsigned long V_418 ;
int error = - V_57 ;
V_417 . V_171 = NULL ;
if ( F_338 ( V_416 , & V_417 , true ) )
return error ;
F_17 ( & V_23 -> V_25 ) ;
V_418 = V_23 -> V_24 - V_23 -> V_26 ;
if ( F_26 ( & V_23 -> V_36 , V_417 . V_35 ) > 0 )
goto V_151;
if ( V_417 . V_24 < V_418 )
goto V_151;
if ( V_417 . V_35 && ! V_23 -> V_35 )
goto V_151;
if ( V_417 . V_24 && ! V_23 -> V_24 )
goto V_151;
error = 0 ;
V_23 -> V_58 = V_417 . V_58 ;
V_23 -> V_35 = V_417 . V_35 ;
V_23 -> V_24 = V_417 . V_24 ;
V_23 -> V_26 = V_417 . V_24 - V_418 ;
if ( V_417 . V_171 ) {
F_350 ( V_23 -> V_171 ) ;
V_23 -> V_171 = V_417 . V_171 ;
}
V_151:
F_18 ( & V_23 -> V_25 ) ;
return error ;
}
static int F_353 ( struct V_168 * V_169 , struct V_120 * V_419 )
{
struct V_10 * V_23 = F_7 ( V_419 -> V_343 ) ;
if ( V_23 -> V_35 != F_1 () )
F_164 ( V_169 , L_20 ,
V_23 -> V_35 << ( V_77 - 10 ) ) ;
if ( V_23 -> V_24 != F_2 () )
F_164 ( V_169 , L_21 , V_23 -> V_24 ) ;
if ( V_23 -> V_173 != ( V_377 | V_420 ) )
F_164 ( V_169 , L_22 , V_23 -> V_173 ) ;
if ( ! F_354 ( V_23 -> V_413 , V_421 ) )
F_164 ( V_169 , L_23 ,
F_355 ( & V_422 , V_23 -> V_413 ) ) ;
if ( ! F_356 ( V_23 -> V_414 , V_423 ) )
F_164 ( V_169 , L_24 ,
F_357 ( & V_422 , V_23 -> V_414 ) ) ;
#ifdef V_135
if ( V_23 -> V_58 )
F_164 ( V_169 , L_25 , F_40 ( V_23 -> V_58 ) ) ;
#endif
F_162 ( V_169 , V_23 -> V_171 ) ;
return 0 ;
}
static void F_358 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
F_359 ( & V_23 -> V_36 ) ;
F_350 ( V_23 -> V_171 ) ;
F_320 ( V_23 ) ;
V_12 -> V_13 = NULL ;
}
int F_360 ( struct V_11 * V_12 , void * V_416 , int V_424 )
{
struct V_3 * V_3 ;
struct V_10 * V_23 ;
int V_185 = - V_145 ;
V_23 = F_361 ( F_362 ( ( int ) sizeof( struct V_10 ) ,
V_425 ) , V_152 ) ;
if ( ! V_23 )
return - V_145 ;
V_23 -> V_173 = V_377 | V_420 ;
V_23 -> V_413 = F_363 () ;
V_23 -> V_414 = F_364 () ;
V_12 -> V_13 = V_23 ;
#ifdef F_365
if ( ! ( V_12 -> V_426 & V_427 ) ) {
V_23 -> V_35 = F_1 () ;
V_23 -> V_24 = F_2 () ;
if ( F_338 ( V_416 , V_23 , false ) ) {
V_185 = - V_57 ;
goto V_186;
}
} else {
V_12 -> V_426 |= V_428 ;
}
V_12 -> V_429 = & V_430 ;
V_12 -> V_426 |= V_431 ;
#else
V_12 -> V_426 |= V_428 ;
#endif
F_232 ( & V_23 -> V_25 ) ;
if ( F_366 ( & V_23 -> V_36 , 0 , V_152 ) )
goto V_186;
V_23 -> V_26 = V_23 -> V_24 ;
F_232 ( & V_23 -> V_71 ) ;
F_233 ( & V_23 -> V_69 ) ;
V_12 -> V_432 = V_199 ;
V_12 -> V_433 = V_22 ;
V_12 -> V_434 = V_77 ;
V_12 -> V_435 = V_345 ;
V_12 -> V_276 = & V_277 ;
V_12 -> V_436 = 1 ;
#ifdef F_367
V_12 -> V_437 = V_438 ;
#endif
#ifdef F_368
V_12 -> V_426 |= V_439 ;
#endif
V_3 = F_227 ( V_12 , NULL , V_271 | V_23 -> V_173 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_186;
V_3 -> V_440 = V_23 -> V_413 ;
V_3 -> V_441 = V_23 -> V_414 ;
V_12 -> V_442 = F_369 ( V_3 ) ;
if ( ! V_12 -> V_442 )
goto V_186;
return 0 ;
V_186:
F_358 ( V_12 ) ;
return V_185 ;
}
static struct V_3 * F_370 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
V_29 = F_371 ( V_443 , V_152 ) ;
if ( ! V_29 )
return NULL ;
return & V_29 -> V_72 ;
}
static void F_372 ( struct V_444 * V_218 )
{
struct V_3 * V_3 = F_373 ( V_218 , struct V_3 , V_445 ) ;
if ( F_374 ( V_3 -> V_126 ) )
F_320 ( V_3 -> V_379 ) ;
F_375 ( V_443 , F_21 ( V_3 ) ) ;
}
static void F_376 ( struct V_3 * V_3 )
{
if ( F_123 ( V_3 -> V_126 ) )
F_377 ( & F_21 ( V_3 ) -> V_178 ) ;
F_378 ( & V_3 -> V_445 , F_372 ) ;
}
static void F_379 ( void * V_446 )
{
struct V_28 * V_29 = V_446 ;
F_380 ( & V_29 -> V_72 ) ;
}
static int F_381 ( void )
{
V_443 = F_382 ( L_26 ,
sizeof( struct V_28 ) ,
0 , V_447 | V_448 , F_379 ) ;
return 0 ;
}
static void F_383 ( void )
{
F_384 ( V_443 ) ;
}
static struct V_120 * F_385 ( struct V_449 * V_450 ,
int V_14 , const char * V_451 , void * V_416 )
{
return F_386 ( V_450 , V_14 , V_416 , F_360 ) ;
}
int T_15 F_387 ( void )
{
int error ;
if ( V_443 )
return 0 ;
error = F_381 () ;
if ( error )
goto V_452;
error = F_388 ( & V_453 ) ;
if ( error ) {
F_339 ( L_27 ) ;
goto V_454;
}
V_252 = F_389 ( & V_453 ) ;
if ( F_198 ( V_252 ) ) {
error = F_199 ( V_252 ) ;
F_339 ( L_28 ) ;
goto V_455;
}
#ifdef V_135
if ( F_348 () && V_212 < V_55 )
F_7 ( V_252 -> V_253 ) -> V_58 = V_212 ;
else
V_212 = 0 ;
#endif
return 0 ;
V_455:
F_390 ( & V_453 ) ;
V_454:
F_383 () ;
V_452:
V_252 = F_182 ( error ) ;
return error ;
}
static T_9 F_391 ( struct V_456 * V_457 ,
struct V_458 * V_125 , char * V_342 )
{
int V_459 [] = {
V_52 ,
V_53 ,
V_54 ,
V_51 ,
V_55 ,
V_56 ,
} ;
int V_83 , V_460 ;
for ( V_83 = 0 , V_460 = 0 ; V_83 < F_392 ( V_459 ) ; V_83 ++ ) {
const char * V_461 = V_212 == V_459 [ V_83 ] ? L_29 : L_30 ;
V_460 += sprintf ( V_342 + V_460 , V_461 ,
F_40 ( V_459 [ V_83 ] ) ) ;
}
V_342 [ V_460 - 1 ] = '\n' ;
return V_460 ;
}
static T_9 F_393 ( struct V_456 * V_457 ,
struct V_458 * V_125 , const char * V_342 , T_10 V_460 )
{
char V_462 [ 16 ] ;
int V_58 ;
if ( V_460 + 1 > sizeof( V_462 ) )
return - V_57 ;
memcpy ( V_462 , V_342 , V_460 ) ;
V_462 [ V_460 ] = '\0' ;
if ( V_460 && V_462 [ V_460 - 1 ] == '\n' )
V_462 [ V_460 - 1 ] = '\0' ;
V_58 = F_39 ( V_462 ) ;
if ( V_58 == - V_57 )
return - V_57 ;
if ( ! F_348 () &&
V_58 != V_51 && V_58 != V_55 )
return - V_57 ;
V_212 = V_58 ;
if ( V_212 < V_55 )
F_7 ( V_252 -> V_253 ) -> V_58 = V_212 ;
return V_460 ;
}
bool F_394 ( struct V_97 * V_98 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
T_2 V_73 ;
T_1 V_214 ;
if ( V_212 == V_56 )
return true ;
if ( V_212 == V_55 )
return false ;
switch ( V_23 -> V_58 ) {
case V_51 :
return false ;
case V_52 :
return true ;
case V_53 :
V_214 = F_48 ( V_98 -> V_100 , V_84 ) ;
V_73 = F_48 ( F_193 ( V_3 ) , V_22 ) ;
if ( V_73 >= V_74 &&
V_73 >> V_77 >= V_214 )
return true ;
case V_54 :
return ( V_98 -> V_232 & V_233 ) ;
default:
F_30 ( 1 ) ;
return false ;
}
}
int T_15 F_387 ( void )
{
F_80 ( F_388 ( & V_453 ) != 0 ) ;
V_252 = F_389 ( & V_453 ) ;
F_80 ( F_198 ( V_252 ) ) ;
return 0 ;
}
int F_144 ( T_3 V_49 , struct V_5 * V_5 )
{
return 0 ;
}
int F_219 ( struct V_237 * V_237 , int V_39 , struct V_254 * V_255 )
{
return 0 ;
}
void F_97 ( struct V_40 * V_41 )
{
}
unsigned long F_214 ( struct V_237 * V_237 ,
unsigned long V_241 , unsigned long V_239 ,
unsigned long V_222 , unsigned long V_14 )
{
return V_17 -> V_18 -> V_247 ( V_237 , V_241 , V_239 , V_222 , V_14 ) ;
}
void F_118 ( struct V_3 * V_3 , T_2 V_107 , T_2 V_108 )
{
F_395 ( V_3 -> V_9 , V_107 , V_108 ) ;
}
static struct V_237 * F_396 ( const char * V_389 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_463 )
{
struct V_237 * V_464 ;
struct V_3 * V_3 ;
struct V_465 V_465 ;
struct V_11 * V_12 ;
struct V_466 V_147 ;
if ( F_198 ( V_252 ) )
return F_397 ( V_252 ) ;
if ( V_15 < 0 || V_15 > V_199 )
return F_182 ( - V_57 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_182 ( - V_145 ) ;
V_464 = F_182 ( - V_145 ) ;
V_147 . V_389 = V_389 ;
V_147 . V_239 = strlen ( V_389 ) ;
V_147 . V_467 = 0 ;
V_12 = V_252 -> V_253 ;
V_465 . V_119 = F_398 ( V_252 ) ;
V_465 . V_120 = F_399 ( V_12 , & V_147 ) ;
if ( ! V_465 . V_120 )
goto V_468;
F_400 ( V_465 . V_120 , & V_469 ) ;
V_464 = F_182 ( - V_27 ) ;
V_3 = F_227 ( V_12 , NULL , V_268 | V_377 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_468;
V_3 -> V_463 |= V_463 ;
F_289 ( V_465 . V_120 , V_3 ) ;
V_3 -> V_73 = V_15 ;
F_401 ( V_3 ) ;
V_464 = F_182 ( F_402 ( V_3 , V_15 ) ) ;
if ( F_198 ( V_464 ) )
goto V_470;
V_464 = F_403 ( & V_465 , V_325 | V_471 ,
& V_251 ) ;
if ( F_198 ( V_464 ) )
goto V_470;
return V_464 ;
V_468:
F_11 ( V_14 , V_15 ) ;
V_470:
F_404 ( & V_465 ) ;
return V_464 ;
}
struct V_237 * F_405 ( const char * V_389 , T_2 V_15 , unsigned long V_14 )
{
return F_396 ( V_389 , V_15 , V_14 , V_472 ) ;
}
struct V_237 * F_406 ( const char * V_389 , T_2 V_15 , unsigned long V_14 )
{
return F_396 ( V_389 , V_15 , V_14 , 0 ) ;
}
int F_407 ( struct V_97 * V_98 )
{
struct V_237 * V_237 ;
T_2 V_15 = V_98 -> V_101 - V_98 -> V_102 ;
V_237 = F_396 ( L_31 , V_15 , V_98 -> V_232 , V_472 ) ;
if ( F_198 ( V_237 ) )
return F_199 ( V_237 ) ;
if ( V_98 -> V_99 )
F_408 ( V_98 -> V_99 ) ;
V_98 -> V_99 = V_237 ;
V_98 -> V_176 = & V_259 ;
if ( F_126 ( V_135 ) &&
( ( V_98 -> V_102 + ~ V_76 ) & V_76 ) <
( V_98 -> V_101 & V_76 ) ) {
F_226 ( V_98 , V_98 -> V_232 ) ;
}
return 0 ;
}
struct V_5 * F_409 ( struct V_40 * V_41 ,
T_1 V_4 , T_5 V_142 )
{
#ifdef F_410
struct V_3 * V_3 = V_41 -> V_155 ;
struct V_5 * V_5 ;
int error ;
F_80 ( V_41 -> V_137 != & V_138 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_203 ,
V_142 , NULL , NULL ) ;
if ( error )
V_5 = F_182 ( error ) ;
else
F_53 ( V_5 ) ;
return V_5 ;
#else
return F_411 ( V_41 , V_4 , V_142 ) ;
#endif
}
