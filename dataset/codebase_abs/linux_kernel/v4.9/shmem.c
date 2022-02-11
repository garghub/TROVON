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
V_3 -> V_115 = V_3 -> V_116 = F_119 ( V_3 ) ;
}
static int F_120 ( struct V_117 * V_118 , struct V_119 * V_119 ,
struct V_120 * V_121 )
{
struct V_3 * V_3 = V_119 -> V_122 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 != V_3 -> V_9 -> V_33 ) {
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
}
F_121 ( V_3 , V_121 ) ;
return 0 ;
}
static int F_122 ( struct V_119 * V_119 , struct V_123 * V_124 )
{
struct V_3 * V_3 = V_122 ( V_119 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
int error ;
error = F_123 ( V_119 , V_124 ) ;
if ( error )
return error ;
if ( F_124 ( V_3 -> V_125 ) && ( V_124 -> V_126 & V_127 ) ) {
T_2 V_19 = V_3 -> V_73 ;
T_2 V_20 = V_124 -> V_128 ;
if ( ( V_20 < V_19 && ( V_29 -> V_129 & V_130 ) ) ||
( V_20 > V_19 && ( V_29 -> V_129 & V_131 ) ) )
return - V_132 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_21 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_125 ( V_3 , V_20 ) ;
V_3 -> V_115 = V_3 -> V_116 = F_119 ( V_3 ) ;
}
if ( V_20 <= V_19 ) {
T_2 V_133 = F_48 ( V_20 , V_22 ) ;
if ( V_19 > V_133 )
F_126 ( V_3 -> V_9 ,
V_133 , 0 , 1 ) ;
if ( V_29 -> V_31 )
F_118 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_133 )
F_126 ( V_3 -> V_9 ,
V_133 , 0 , 1 ) ;
if ( F_127 ( V_134 ) ) {
F_17 ( & V_23 -> V_71 ) ;
if ( F_43 ( & V_29 -> V_69 ) ) {
F_128 ( & V_29 -> V_69 ,
& V_23 -> V_69 ) ;
V_23 -> V_79 ++ ;
}
F_18 ( & V_23 -> V_71 ) ;
}
}
}
F_129 ( V_3 , V_124 ) ;
if ( V_124 -> V_126 & V_135 )
error = F_130 ( V_3 , V_3 -> V_125 ) ;
return error ;
}
static void F_131 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
if ( V_3 -> V_9 -> V_136 == & V_137 ) {
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
if ( ! F_43 ( & V_29 -> V_138 ) ) {
F_132 ( & V_139 ) ;
F_47 ( & V_29 -> V_138 ) ;
F_133 ( & V_139 ) ;
}
}
F_134 ( & V_29 -> V_140 ) ;
F_135 ( V_3 -> V_37 ) ;
F_19 ( V_3 -> V_34 ) ;
F_136 ( V_3 ) ;
}
static int F_137 ( struct V_28 * V_29 ,
T_3 V_49 , struct V_5 * * V_6 )
{
struct V_40 * V_41 = V_29 -> V_72 . V_9 ;
void * V_90 ;
T_1 V_4 ;
T_5 V_141 ;
int error = 0 ;
V_90 = F_38 ( V_49 ) ;
V_4 = F_138 ( & V_41 -> V_46 , V_90 ) ;
if ( V_4 == - 1 )
return - V_142 ;
if ( V_143 . V_64 != & V_29 -> V_138 )
F_139 ( & V_143 , & V_29 -> V_138 ) ;
V_141 = F_6 ( V_41 ) ;
if ( F_140 ( * V_6 , V_141 ) ) {
F_133 ( & V_139 ) ;
error = F_141 ( V_6 , V_141 , V_29 , V_4 ) ;
F_132 ( & V_139 ) ;
if ( ! F_142 ( * V_6 ) )
error = - V_47 ;
}
if ( ! error )
error = F_60 ( * V_6 , V_41 , V_4 ,
V_90 ) ;
if ( error != - V_144 ) {
F_143 ( * V_6 ) ;
F_116 ( * V_6 ) ;
if ( ! error ) {
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_75 ( & V_29 -> V_39 ) ;
F_144 ( V_49 ) ;
}
}
return error ;
}
int F_145 ( T_3 V_49 , struct V_5 * V_5 )
{
struct V_145 * V_146 , * V_64 ;
struct V_28 * V_29 ;
struct V_147 * V_148 ;
int error = 0 ;
if ( F_146 ( ! F_147 ( V_5 ) || F_148 ( V_5 ) != V_49 . V_149 ) )
goto V_150;
error = F_149 ( V_5 , V_17 -> V_18 , V_151 , & V_148 ,
false ) ;
if ( error )
goto V_150;
error = - V_142 ;
F_132 ( & V_139 ) ;
F_44 (this, next, &shmem_swaplist) {
V_29 = F_45 ( V_146 , struct V_28 , V_138 ) ;
if ( V_29 -> V_32 )
error = F_137 ( V_29 , V_49 , & V_5 ) ;
else
F_47 ( & V_29 -> V_138 ) ;
F_104 () ;
if ( error != - V_142 )
break;
}
F_133 ( & V_139 ) ;
if ( error ) {
if ( error != - V_144 )
error = 0 ;
F_150 ( V_5 , V_148 , false ) ;
} else
F_151 ( V_5 , V_148 , true , false ) ;
V_150:
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return error ;
}
static int F_152 ( struct V_5 * V_5 , struct V_152 * V_153 )
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
V_3 = V_41 -> V_154 ;
V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_14 & V_155 )
goto V_156;
if ( ! V_157 )
goto V_156;
if ( ! V_153 -> V_158 ) {
F_153 ( 1 ) ;
goto V_156;
}
if ( ! F_111 ( V_5 ) ) {
if ( V_3 -> V_159 ) {
struct V_160 * V_160 ;
F_17 ( & V_3 -> V_161 ) ;
V_160 = V_3 -> V_159 ;
if ( V_160 &&
! V_160 -> V_162 &&
V_4 >= V_160 -> V_92 &&
V_4 < V_160 -> V_64 )
V_160 -> V_163 ++ ;
else
V_160 = NULL ;
F_18 ( & V_3 -> V_161 ) ;
if ( V_160 )
goto V_156;
}
F_110 ( V_5 ) ;
F_154 ( V_5 ) ;
F_155 ( V_5 ) ;
}
V_49 = F_156 () ;
if ( ! V_49 . V_149 )
goto V_156;
if ( F_157 ( V_5 , V_49 ) )
goto V_164;
F_132 ( & V_139 ) ;
if ( F_43 ( & V_29 -> V_138 ) )
F_128 ( & V_29 -> V_138 , & V_143 ) ;
if ( F_158 ( V_5 , V_49 , V_165 ) == 0 ) {
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
V_29 -> V_32 ++ ;
F_75 ( & V_29 -> V_39 ) ;
F_159 ( V_49 ) ;
F_77 ( V_5 , F_38 ( V_49 ) ) ;
F_133 ( & V_139 ) ;
F_80 ( F_160 ( V_5 ) ) ;
F_161 ( V_5 , V_153 ) ;
return 0 ;
}
F_133 ( & V_139 ) ;
V_164:
F_162 ( V_49 ) ;
V_156:
F_116 ( V_5 ) ;
if ( V_153 -> V_158 )
return V_166 ;
F_53 ( V_5 ) ;
return 0 ;
}
static void F_163 ( struct V_167 * V_168 , struct V_169 * V_170 )
{
char V_171 [ 64 ] ;
if ( ! V_170 || V_170 -> V_172 == V_173 )
return;
F_164 ( V_171 , sizeof( V_171 ) , V_170 ) ;
F_165 ( V_168 , L_8 , V_171 ) ;
}
static struct V_169 * F_166 ( struct V_10 * V_23 )
{
struct V_169 * V_170 = NULL ;
if ( V_23 -> V_170 ) {
F_17 ( & V_23 -> V_25 ) ;
V_170 = V_23 -> V_170 ;
F_167 ( V_170 ) ;
F_18 ( & V_23 -> V_25 ) ;
}
return V_170 ;
}
static inline void F_163 ( struct V_167 * V_168 , struct V_169 * V_170 )
{
}
static inline struct V_169 * F_166 ( struct V_10 * V_23 )
{
return NULL ;
}
static void F_168 ( struct V_97 * V_98 ,
struct V_28 * V_29 , T_1 V_4 )
{
V_98 -> V_102 = 0 ;
V_98 -> V_100 = V_4 + V_29 -> V_72 . V_174 ;
V_98 -> V_175 = NULL ;
V_98 -> V_176 = F_169 ( & V_29 -> V_177 , V_4 ) ;
}
static void F_170 ( struct V_97 * V_98 )
{
F_171 ( V_98 -> V_176 ) ;
}
static struct V_5 * F_172 ( T_3 V_49 , T_5 V_141 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_178 ;
struct V_5 * V_5 ;
F_168 ( & V_178 , V_29 , V_4 ) ;
V_5 = F_173 ( V_49 , V_141 , & V_178 , 0 ) ;
F_170 ( & V_178 ) ;
return V_5 ;
}
static struct V_5 * F_174 ( T_5 V_141 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_178 ;
struct V_3 * V_3 = & V_29 -> V_72 ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_82 , V_179 ;
void T_4 * * V_81 ;
struct V_5 * V_5 ;
if ( ! F_127 ( V_134 ) )
return NULL ;
V_179 = F_64 ( V_4 , V_84 ) ;
F_35 () ;
if ( F_69 ( & V_41 -> V_46 , & V_81 , & V_82 ,
V_179 , 1 ) && V_82 < V_179 + V_84 ) {
F_37 () ;
return NULL ;
}
F_37 () ;
F_168 ( & V_178 , V_29 , V_179 ) ;
V_5 = F_175 ( V_141 | V_180 | V_181 | V_182 ,
V_183 , & V_178 , 0 , F_176 () , true ) ;
F_170 ( & V_178 ) ;
if ( V_5 )
F_177 ( V_5 ) ;
return V_5 ;
}
static struct V_5 * F_178 ( T_5 V_141 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_97 V_178 ;
struct V_5 * V_5 ;
F_168 ( & V_178 , V_29 , V_4 ) ;
V_5 = F_179 ( V_141 , & V_178 , 0 ) ;
F_170 ( & V_178 ) ;
return V_5 ;
}
static struct V_5 * F_180 ( T_5 V_141 ,
struct V_28 * V_29 , struct V_10 * V_23 ,
T_1 V_4 , bool V_58 )
{
struct V_5 * V_5 ;
int V_80 ;
int V_184 = - V_27 ;
if ( ! F_127 ( V_134 ) )
V_58 = false ;
V_80 = V_58 ? V_84 : 1 ;
if ( F_14 ( V_29 -> V_14 , V_80 ) )
goto V_185;
if ( V_23 -> V_35 ) {
if ( F_26 ( & V_23 -> V_36 ,
V_23 -> V_35 - V_80 ) > 0 )
goto V_186;
F_22 ( & V_23 -> V_36 , V_80 ) ;
}
if ( V_58 )
V_5 = F_174 ( V_141 , V_29 , V_4 ) ;
else
V_5 = F_178 ( V_141 , V_29 , V_4 ) ;
if ( V_5 ) {
F_181 ( V_5 ) ;
F_182 ( V_5 ) ;
return V_5 ;
}
V_184 = - V_144 ;
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - V_80 ) ;
V_186:
F_15 ( V_29 -> V_14 , V_80 ) ;
V_185:
return F_183 ( V_184 ) ;
}
static bool F_140 ( struct V_5 * V_5 , T_5 V_141 )
{
return F_184 ( V_5 ) > F_185 ( V_141 ) ;
}
static int F_141 ( struct V_5 * * V_6 , T_5 V_141 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_5 * V_187 , * V_188 ;
struct V_40 * V_189 ;
T_1 V_190 ;
int error ;
V_187 = * V_6 ;
V_190 = F_148 ( V_187 ) ;
V_189 = F_112 ( V_187 ) ;
V_141 &= ~ V_191 ;
V_188 = F_178 ( V_141 , V_29 , V_4 ) ;
if ( ! V_188 )
return - V_144 ;
F_186 ( V_188 ) ;
F_187 ( V_188 , V_187 ) ;
F_154 ( V_188 ) ;
F_181 ( V_188 ) ;
F_182 ( V_188 ) ;
F_155 ( V_188 ) ;
F_188 ( V_188 , V_190 ) ;
F_189 ( V_188 ) ;
F_68 ( & V_189 -> V_48 ) ;
error = F_29 ( V_189 , V_190 , V_187 ,
V_188 ) ;
if ( ! error ) {
F_72 ( V_188 , V_88 ) ;
F_79 ( V_187 , V_88 ) ;
}
F_75 ( & V_189 -> V_48 ) ;
if ( F_146 ( error ) ) {
V_187 = V_188 ;
} else {
F_190 ( V_187 , V_188 ) ;
F_191 ( V_188 ) ;
* V_6 = V_188 ;
}
F_192 ( V_187 ) ;
F_188 ( V_187 , 0 ) ;
F_53 ( V_187 ) ;
F_54 ( V_187 ) ;
F_54 ( V_187 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_5 V_141 ,
struct V_192 * V_193 , int * V_194 )
{
struct V_40 * V_41 = V_3 -> V_9 ;
struct V_28 * V_29 ;
struct V_10 * V_23 ;
struct V_192 * V_195 ;
struct V_147 * V_148 ;
struct V_5 * V_5 ;
T_3 V_49 ;
enum V_7 V_196 = V_8 ;
T_1 V_179 = V_4 ;
int error ;
int V_197 = 0 ;
int V_31 = 0 ;
if ( V_4 > ( V_198 >> V_77 ) )
return - V_199 ;
if ( V_8 == V_200 || V_8 == V_201 )
V_8 = V_202 ;
V_203:
V_49 . V_149 = 0 ;
V_5 = F_193 ( V_41 , V_4 ) ;
if ( F_90 ( V_5 ) ) {
V_49 = F_84 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_202 &&
( ( T_2 ) V_4 << V_77 ) >= F_194 ( V_3 ) ) {
error = - V_57 ;
goto V_204;
}
if ( V_5 && V_8 == V_205 )
F_195 ( V_5 ) ;
if ( V_5 && ! F_111 ( V_5 ) ) {
if ( V_8 != V_113 )
goto V_206;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_113 && ! V_49 . V_149 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_23 = F_7 ( V_3 -> V_34 ) ;
V_195 = V_193 ? : V_17 -> V_18 ;
if ( V_49 . V_149 ) {
V_5 = F_196 ( V_49 ) ;
if ( ! V_5 ) {
if ( V_194 ) {
* V_194 |= V_207 ;
F_71 ( V_208 ) ;
F_197 ( V_193 , V_208 ) ;
}
V_5 = F_172 ( V_49 , V_141 , V_29 , V_4 ) ;
if ( ! V_5 ) {
error = - V_144 ;
goto V_185;
}
}
F_117 ( V_5 ) ;
if ( ! F_147 ( V_5 ) || F_148 ( V_5 ) != V_49 . V_149 ||
! F_34 ( V_41 , V_4 , V_49 ) ) {
error = - V_85 ;
goto V_204;
}
if ( ! F_111 ( V_5 ) ) {
error = - V_209 ;
goto V_185;
}
F_198 ( V_5 ) ;
if ( F_140 ( V_5 , V_141 ) ) {
error = F_141 ( & V_5 , V_141 , V_29 , V_4 ) ;
if ( error )
goto V_185;
}
error = F_149 ( V_5 , V_195 , V_141 , & V_148 ,
false ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_41 , V_4 ,
F_38 ( V_49 ) ) ;
if ( error ) {
F_150 ( V_5 , V_148 , false ) ;
F_143 ( V_5 ) ;
}
}
if ( error )
goto V_185;
F_151 ( V_5 , V_148 , true , false ) ;
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_32 -- ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
if ( V_8 == V_205 )
F_195 ( V_5 ) ;
F_143 ( V_5 ) ;
F_116 ( V_5 ) ;
F_144 ( V_49 ) ;
} else {
if ( V_41 -> V_136 != & V_137 )
goto V_210;
if ( V_211 == V_55 || V_196 == V_200 )
goto V_210;
if ( V_211 == V_56 )
goto V_212;
switch ( V_23 -> V_58 ) {
T_2 V_73 ;
T_1 V_213 ;
case V_51 :
goto V_210;
case V_53 :
V_213 = F_48 ( V_4 , V_84 ) ;
V_73 = F_48 ( F_194 ( V_3 ) , V_22 ) ;
if ( V_73 >= V_74 &&
V_73 >> V_77 >= V_213 )
goto V_212;
case V_54 :
if ( V_196 == V_201 )
goto V_212;
goto V_210;
}
V_212:
V_5 = F_180 ( V_141 , V_29 , V_23 ,
V_4 , true ) ;
if ( F_199 ( V_5 ) ) {
V_210: V_5 = F_180 ( V_141 , V_29 , V_23 ,
V_4 , false ) ;
}
if ( F_199 ( V_5 ) ) {
int V_214 = 5 ;
error = F_200 ( V_5 ) ;
V_5 = NULL ;
if ( error != - V_27 )
goto V_185;
while ( V_214 -- ) {
int V_75 ;
V_75 = F_41 ( V_23 , NULL , 1 ) ;
if ( V_75 == V_70 )
break;
if ( V_75 )
goto V_210;
}
goto V_185;
}
if ( F_52 ( V_5 ) )
V_179 = F_64 ( V_4 , V_84 ) ;
else
V_179 = V_4 ;
if ( V_8 == V_205 )
F_201 ( V_5 ) ;
error = F_149 ( V_5 , V_195 , V_141 , & V_148 ,
F_52 ( V_5 ) ) ;
if ( error )
goto V_186;
error = F_202 ( V_141 & V_215 ,
F_203 ( V_5 ) ) ;
if ( ! error ) {
error = F_60 ( V_5 , V_41 , V_179 ,
NULL ) ;
F_204 () ;
}
if ( error ) {
F_150 ( V_5 , V_148 ,
F_52 ( V_5 ) ) ;
goto V_186;
}
F_151 ( V_5 , V_148 , false ,
F_52 ( V_5 ) ) ;
F_191 ( V_5 ) ;
F_68 ( & V_29 -> V_39 ) ;
V_29 -> V_31 += 1 << F_203 ( V_5 ) ;
V_3 -> V_37 += V_38 << F_203 ( V_5 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
V_31 = true ;
if ( F_52 ( V_5 ) &&
F_205 ( F_194 ( V_3 ) , V_22 ) <
V_179 + V_84 - 1 ) {
F_17 ( & V_23 -> V_71 ) ;
if ( F_43 ( & V_29 -> V_69 ) ) {
F_128 ( & V_29 -> V_69 ,
& V_23 -> V_69 ) ;
V_23 -> V_79 ++ ;
}
F_18 ( & V_23 -> V_71 ) ;
}
if ( V_8 == V_216 )
V_8 = V_205 ;
V_206:
if ( V_8 != V_205 && ! F_111 ( V_5 ) ) {
struct V_5 * V_217 = F_206 ( V_5 ) ;
int V_83 ;
for ( V_83 = 0 ; V_83 < ( 1 << F_203 ( V_217 ) ) ; V_83 ++ ) {
F_110 ( V_217 + V_83 ) ;
F_154 ( V_217 + V_83 ) ;
}
F_155 ( V_217 ) ;
}
}
if ( V_8 <= V_202 &&
( ( T_2 ) V_4 << V_77 ) >= F_194 ( V_3 ) ) {
if ( V_31 ) {
F_207 ( V_5 ) ;
F_208 ( V_5 ) ;
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
}
error = - V_57 ;
goto V_204;
}
* V_6 = V_5 + V_4 - V_179 ;
return 0 ;
V_186:
if ( V_23 -> V_35 )
F_28 ( & V_23 -> V_36 ,
1 << F_203 ( V_5 ) ) ;
F_15 ( V_29 -> V_14 , 1 << F_203 ( V_5 ) ) ;
if ( F_52 ( V_5 ) ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
goto V_210;
}
V_185:
if ( V_49 . V_149 && ! F_34 ( V_41 , V_4 , V_49 ) )
error = - V_85 ;
V_204:
if ( V_5 ) {
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
if ( error == - V_27 && ! V_197 ++ ) {
V_29 = F_21 ( V_3 ) ;
F_68 ( & V_29 -> V_39 ) ;
F_20 ( V_3 ) ;
F_75 ( & V_29 -> V_39 ) ;
goto V_203;
}
if ( error == - V_85 )
goto V_203;
return error ;
}
static int F_209 ( T_6 * V_218 , unsigned V_172 , int V_219 , void * V_220 )
{
int V_75 = F_210 ( V_218 , V_172 , V_219 , V_220 ) ;
F_47 ( & V_218 -> V_221 ) ;
return V_75 ;
}
static int F_211 ( struct V_97 * V_98 , struct V_222 * V_223 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
T_5 V_141 = F_6 ( V_3 -> V_9 ) ;
enum V_7 V_8 ;
int error ;
int V_75 = V_224 ;
if ( F_146 ( V_3 -> V_159 ) ) {
struct V_160 * V_160 ;
F_17 ( & V_3 -> V_161 ) ;
V_160 = V_3 -> V_159 ;
if ( V_160 &&
V_160 -> V_162 &&
V_223 -> V_225 >= V_160 -> V_92 &&
V_223 -> V_225 < V_160 -> V_64 ) {
T_7 * V_226 ;
F_212 ( V_227 , F_209 ) ;
V_75 = V_228 ;
if ( ( V_223 -> V_14 & V_229 ) &&
! ( V_223 -> V_14 & V_230 ) ) {
F_213 ( & V_98 -> V_231 -> V_232 ) ;
V_75 = V_233 ;
}
V_226 = V_160 -> V_162 ;
F_214 ( V_226 , & V_227 ,
V_234 ) ;
F_18 ( & V_3 -> V_161 ) ;
F_215 () ;
F_17 ( & V_3 -> V_161 ) ;
F_216 ( V_226 , & V_227 ) ;
F_18 ( & V_3 -> V_161 ) ;
return V_75 ;
}
F_18 ( & V_3 -> V_161 ) ;
}
V_8 = V_202 ;
if ( V_98 -> V_235 & V_236 )
V_8 = V_201 ;
else if ( V_98 -> V_235 & V_237 )
V_8 = V_200 ;
error = F_5 ( V_3 , V_223 -> V_225 , & V_223 -> V_5 , V_8 ,
V_141 , V_98 -> V_231 , & V_75 ) ;
if ( error )
return ( ( error == - V_144 ) ? V_238 : V_239 ) ;
return V_75 ;
}
unsigned long F_217 ( struct V_240 * V_240 ,
unsigned long V_241 , unsigned long V_242 ,
unsigned long V_225 , unsigned long V_14 )
{
unsigned long ( * V_243 ) ( struct V_240 * ,
unsigned long , unsigned long , unsigned long , unsigned long ) ;
unsigned long V_244 ;
unsigned long V_245 ;
unsigned long V_246 ;
unsigned long V_247 ;
unsigned long V_248 ;
if ( V_242 > V_249 )
return - V_144 ;
V_243 = V_17 -> V_18 -> V_250 ;
V_244 = V_243 ( V_240 , V_241 , V_242 , V_225 , V_14 ) ;
if ( ! F_127 ( V_134 ) )
return V_244 ;
if ( F_218 ( V_244 ) )
return V_244 ;
if ( V_244 & ~ V_251 )
return V_244 ;
if ( V_244 > V_249 - V_242 )
return V_244 ;
if ( V_211 == V_55 )
return V_244 ;
if ( V_242 < V_74 )
return V_244 ;
if ( V_14 & V_252 )
return V_244 ;
if ( V_241 )
return V_244 ;
if ( V_211 != V_56 ) {
struct V_11 * V_12 ;
if ( V_240 ) {
F_30 ( V_240 -> V_253 != & V_254 ) ;
V_12 = F_95 ( V_240 ) -> V_34 ;
} else {
if ( F_199 ( V_255 ) )
return V_244 ;
V_12 = V_255 -> V_256 ;
}
if ( F_7 ( V_12 ) -> V_58 == V_51 )
return V_244 ;
}
V_245 = ( V_225 << V_77 ) & ( V_74 - 1 ) ;
if ( V_245 && V_245 + V_242 < 2 * V_74 )
return V_244 ;
if ( ( V_244 & ( V_74 - 1 ) ) == V_245 )
return V_244 ;
V_246 = V_242 + V_74 - V_22 ;
if ( V_246 > V_249 )
return V_244 ;
if ( V_246 < V_242 )
return V_244 ;
V_247 = V_243 ( NULL , 0 , V_246 , 0 , V_14 ) ;
if ( F_218 ( V_247 ) )
return V_244 ;
if ( V_247 & ~ V_251 )
return V_244 ;
V_248 = V_247 & ( V_74 - 1 ) ;
V_247 += V_245 - V_248 ;
if ( V_248 > V_245 )
V_247 += V_74 ;
if ( V_247 > V_249 - V_242 )
return V_244 ;
return V_247 ;
}
static int F_219 ( struct V_97 * V_98 , struct V_169 * V_170 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
return F_220 ( & F_21 ( V_3 ) -> V_177 , V_98 , V_170 ) ;
}
static struct V_169 * F_221 ( struct V_97 * V_98 ,
unsigned long V_244 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
T_1 V_4 ;
V_4 = ( ( V_244 - V_98 -> V_102 ) >> V_77 ) + V_98 -> V_100 ;
return F_169 ( & F_21 ( V_3 ) -> V_177 , V_4 ) ;
}
int F_222 ( struct V_240 * V_240 , int V_39 , struct V_257 * V_258 )
{
struct V_3 * V_3 = F_95 ( V_240 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int V_259 = - V_144 ;
F_68 ( & V_29 -> V_39 ) ;
if ( V_39 && ! ( V_29 -> V_14 & V_155 ) ) {
if ( ! F_223 ( V_3 -> V_73 , V_258 ) )
goto V_260;
V_29 -> V_14 |= V_155 ;
F_224 ( V_240 -> V_261 ) ;
}
if ( ! V_39 && ( V_29 -> V_14 & V_155 ) && V_258 ) {
F_225 ( V_3 -> V_73 , V_258 ) ;
V_29 -> V_14 &= ~ V_155 ;
F_226 ( V_240 -> V_261 ) ;
}
V_259 = 0 ;
V_260:
F_75 ( & V_29 -> V_39 ) ;
return V_259 ;
}
static int F_227 ( struct V_240 * V_240 , struct V_97 * V_98 )
{
F_228 ( V_240 ) ;
V_98 -> V_175 = & V_262 ;
if ( F_127 ( V_134 ) &&
( ( V_98 -> V_102 + ~ V_76 ) & V_76 ) <
( V_98 -> V_101 & V_76 ) ) {
F_229 ( V_98 , V_98 -> V_235 ) ;
}
return 0 ;
}
static struct V_3 * F_230 ( struct V_11 * V_12 , const struct V_3 * V_263 ,
T_8 V_172 , T_9 V_264 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( F_16 ( V_12 ) )
return NULL ;
V_3 = F_231 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_174 = F_232 () ;
F_233 ( V_3 , V_263 , V_172 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_265 = V_3 -> V_116 = V_3 -> V_115 = F_119 ( V_3 ) ;
V_3 -> V_266 = F_234 () ;
V_29 = F_21 ( V_3 ) ;
memset ( V_29 , 0 , ( char * ) V_3 - ( char * ) V_29 ) ;
F_235 ( & V_29 -> V_39 ) ;
V_29 -> V_129 = V_267 ;
V_29 -> V_14 = V_14 & V_16 ;
F_236 ( & V_29 -> V_69 ) ;
F_236 ( & V_29 -> V_138 ) ;
F_237 ( & V_29 -> V_140 ) ;
F_238 ( V_3 ) ;
switch ( V_172 & V_268 ) {
default:
V_3 -> V_269 = & V_270 ;
F_239 ( V_3 , V_172 , V_264 ) ;
break;
case V_271 :
V_3 -> V_9 -> V_136 = & V_137 ;
V_3 -> V_269 = & V_272 ;
V_3 -> V_273 = & V_254 ;
F_240 ( & V_29 -> V_177 ,
F_166 ( V_23 ) ) ;
break;
case V_274 :
F_241 ( V_3 ) ;
V_3 -> V_73 = 2 * V_275 ;
V_3 -> V_269 = & V_276 ;
V_3 -> V_273 = & V_277 ;
break;
case V_278 :
F_240 ( & V_29 -> V_177 , NULL ) ;
break;
}
} else
F_19 ( V_12 ) ;
return V_3 ;
}
bool F_242 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_154 )
return false ;
return V_41 -> V_154 -> V_34 -> V_279 == & V_280 ;
}
static int
F_243 ( struct V_240 * V_240 , struct V_40 * V_41 ,
T_2 V_63 , unsigned V_242 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_281 )
{
struct V_3 * V_3 = V_41 -> V_154 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_4 = V_63 >> V_77 ;
if ( F_146 ( V_29 -> V_129 ) ) {
if ( V_29 -> V_129 & V_282 )
return - V_132 ;
if ( ( V_29 -> V_129 & V_131 ) && V_63 + V_242 > V_3 -> V_73 )
return - V_132 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_205 ) ;
}
static int
F_244 ( struct V_240 * V_240 , struct V_40 * V_41 ,
T_2 V_63 , unsigned V_242 , unsigned V_283 ,
struct V_5 * V_5 , void * V_281 )
{
struct V_3 * V_3 = V_41 -> V_154 ;
if ( V_63 + V_283 > V_3 -> V_73 )
F_125 ( V_3 , V_63 + V_283 ) ;
if ( ! F_111 ( V_5 ) ) {
struct V_5 * V_217 = F_206 ( V_5 ) ;
if ( F_245 ( V_5 ) ) {
int V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
if ( V_217 + V_83 == V_5 )
continue;
F_110 ( V_217 + V_83 ) ;
F_154 ( V_217 + V_83 ) ;
}
}
if ( V_283 < V_22 ) {
unsigned V_284 = V_63 & ( V_22 - 1 ) ;
F_246 ( V_5 , 0 , V_284 ,
V_284 + V_283 , V_22 ) ;
}
F_155 ( V_217 ) ;
}
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
return V_283 ;
}
static T_10 F_247 ( struct V_285 * V_286 , struct V_287 * V_288 )
{
struct V_240 * V_240 = V_286 -> V_289 ;
struct V_3 * V_3 = F_95 ( V_240 ) ;
struct V_40 * V_41 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_245 ;
enum V_7 V_8 = V_113 ;
int error = 0 ;
T_10 V_259 = 0 ;
T_2 * V_290 = & V_286 -> V_291 ;
if ( ! F_248 ( V_288 ) )
V_8 = V_202 ;
V_4 = * V_290 >> V_77 ;
V_245 = * V_290 & ~ V_251 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_292 ;
unsigned long V_80 , V_75 ;
T_2 V_73 = F_194 ( V_3 ) ;
V_292 = V_73 >> V_77 ;
if ( V_4 > V_292 )
break;
if ( V_4 == V_292 ) {
V_80 = V_73 & ~ V_251 ;
if ( V_80 <= V_245 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_57 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_202 )
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
}
V_80 = V_22 ;
V_73 = F_194 ( V_3 ) ;
V_292 = V_73 >> V_77 ;
if ( V_4 == V_292 ) {
V_80 = V_73 & ~ V_251 ;
if ( V_80 <= V_245 ) {
if ( V_5 )
F_54 ( V_5 ) ;
break;
}
}
V_80 -= V_245 ;
if ( V_5 ) {
if ( F_249 ( V_41 ) )
F_154 ( V_5 ) ;
if ( ! V_245 )
F_195 ( V_5 ) ;
} else {
V_5 = F_250 ( 0 ) ;
F_186 ( V_5 ) ;
}
V_75 = F_251 ( V_5 , V_245 , V_80 , V_288 ) ;
V_259 += V_75 ;
V_245 += V_75 ;
V_4 += V_245 >> V_77 ;
V_245 &= ~ V_251 ;
F_54 ( V_5 ) ;
if ( ! F_252 ( V_288 ) )
break;
if ( V_75 < V_80 ) {
error = - V_293 ;
break;
}
F_104 () ;
}
* V_290 = ( ( T_2 ) V_4 << V_77 ) + V_245 ;
F_228 ( V_240 ) ;
return V_259 ? V_259 : error ;
}
static T_1 F_253 ( struct V_40 * V_41 ,
T_1 V_4 , T_1 V_93 , int V_294 )
{
struct V_5 * V_5 ;
struct V_103 V_104 ;
T_1 V_105 [ V_106 ] ;
bool V_295 = false ;
int V_83 ;
F_98 ( & V_104 , 0 ) ;
V_104 . V_80 = 1 ;
while ( ! V_295 ) {
V_104 . V_80 = F_100 ( V_41 , V_4 ,
V_104 . V_80 , V_104 . V_21 , V_105 ) ;
if ( ! V_104 . V_80 ) {
if ( V_294 == V_296 )
V_4 = V_93 ;
break;
}
for ( V_83 = 0 ; V_83 < V_104 . V_80 ; V_83 ++ , V_4 ++ ) {
if ( V_4 < V_105 [ V_83 ] ) {
if ( V_294 == V_297 ) {
V_295 = true ;
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
( V_5 && V_294 == V_296 ) ||
( ! V_5 && V_294 == V_297 ) ) {
V_295 = true ;
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
static T_2 F_254 ( struct V_240 * V_240 , T_2 V_245 , int V_294 )
{
struct V_40 * V_41 = V_240 -> V_261 ;
struct V_3 * V_3 = V_41 -> V_154 ;
T_1 V_92 , V_93 ;
T_2 V_298 ;
if ( V_294 != V_296 && V_294 != V_297 )
return F_255 ( V_240 , V_245 , V_294 ,
V_198 , F_194 ( V_3 ) ) ;
F_256 ( V_3 ) ;
if ( V_245 < 0 )
V_245 = - V_57 ;
else if ( V_245 >= V_3 -> V_73 )
V_245 = - V_299 ;
else {
V_92 = V_245 >> V_77 ;
V_93 = ( V_3 -> V_73 + V_22 - 1 ) >> V_77 ;
V_298 = F_253 ( V_41 , V_92 , V_93 , V_294 ) ;
V_298 <<= V_77 ;
if ( V_298 > V_245 ) {
if ( V_298 < V_3 -> V_73 )
V_245 = V_298 ;
else if ( V_294 == V_296 )
V_245 = - V_299 ;
else
V_245 = V_3 -> V_73 ;
}
}
if ( V_245 >= 0 )
V_245 = F_257 ( V_240 , V_245 , V_198 ) ;
F_258 ( V_3 ) ;
return V_245 ;
}
static void F_259 ( struct V_40 * V_41 )
{
struct V_94 V_95 ;
void * * V_96 ;
T_1 V_92 ;
struct V_5 * V_5 ;
F_260 () ;
V_92 = 0 ;
F_35 () ;
F_86 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_87 ( V_96 ) ;
if ( ! V_5 || F_261 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_96 = F_89 ( & V_95 ) ;
continue;
}
} else if ( F_262 ( V_5 ) - F_263 ( V_5 ) > 1 ) {
F_68 ( & V_41 -> V_48 ) ;
F_264 ( & V_41 -> V_46 , V_95 . V_4 ,
V_300 ) ;
F_75 ( & V_41 -> V_48 ) ;
}
if ( F_91 () ) {
F_92 () ;
V_96 = F_93 ( & V_95 ) ;
}
}
F_37 () ;
}
static int F_265 ( struct V_40 * V_41 )
{
struct V_94 V_95 ;
void * * V_96 ;
T_1 V_92 ;
struct V_5 * V_5 ;
int error , V_301 ;
F_259 ( V_41 ) ;
error = 0 ;
for ( V_301 = 0 ; V_301 <= V_302 ; V_301 ++ ) {
if ( ! F_266 ( & V_41 -> V_46 , V_300 ) )
break;
if ( ! V_301 )
F_267 () ;
else if ( F_268 ( ( V_303 << V_301 ) / 200 ) )
V_301 = V_302 ;
V_92 = 0 ;
F_35 () ;
F_269 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_87 ( V_96 ) ;
if ( F_261 ( V_5 ) ) {
if ( F_88 ( V_5 ) ) {
V_96 = F_89 ( & V_95 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_262 ( V_5 ) - F_263 ( V_5 ) != 1 ) {
if ( V_301 < V_302 )
goto V_304;
error = - V_305 ;
}
F_68 ( & V_41 -> V_48 ) ;
F_270 ( & V_41 -> V_46 ,
V_95 . V_4 , V_300 ) ;
F_75 ( & V_41 -> V_48 ) ;
V_304:
if ( F_91 () ) {
F_92 () ;
V_96 = F_93 ( & V_95 ) ;
}
}
F_37 () ;
}
return error ;
}
int F_271 ( struct V_240 * V_240 , unsigned int V_129 )
{
struct V_3 * V_3 = F_95 ( V_240 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int error ;
if ( V_240 -> V_253 != & V_254 )
return - V_57 ;
if ( ! ( V_240 -> V_306 & V_307 ) )
return - V_132 ;
if ( V_129 & ~ ( unsigned int ) V_308 )
return - V_57 ;
F_256 ( V_3 ) ;
if ( V_29 -> V_129 & V_267 ) {
error = - V_132 ;
goto V_204;
}
if ( ( V_129 & V_282 ) && ! ( V_29 -> V_129 & V_282 ) ) {
error = F_272 ( V_240 -> V_261 ) ;
if ( error )
goto V_204;
error = F_265 ( V_240 -> V_261 ) ;
if ( error ) {
F_273 ( V_240 -> V_261 ) ;
goto V_204;
}
}
V_29 -> V_129 |= V_129 ;
error = 0 ;
V_204:
F_258 ( V_3 ) ;
return error ;
}
int F_274 ( struct V_240 * V_240 )
{
if ( V_240 -> V_253 != & V_254 )
return - V_57 ;
return F_21 ( F_95 ( V_240 ) ) -> V_129 ;
}
long F_275 ( struct V_240 * V_240 , unsigned int V_309 , unsigned long V_310 )
{
long error ;
switch ( V_309 ) {
case V_311 :
if ( V_310 > V_312 )
return - V_57 ;
error = F_271 ( V_240 , V_310 ) ;
break;
case V_313 :
error = F_274 ( V_240 ) ;
break;
default:
error = - V_57 ;
break;
}
return error ;
}
static long F_276 ( struct V_240 * V_240 , int V_172 , T_2 V_245 ,
T_2 V_242 )
{
struct V_3 * V_3 = F_95 ( V_240 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_160 V_160 ;
T_1 V_92 , V_4 , V_93 ;
int error ;
if ( V_172 & ~ ( V_314 | V_315 ) )
return - V_316 ;
F_256 ( V_3 ) ;
if ( V_172 & V_315 ) {
struct V_40 * V_41 = V_240 -> V_261 ;
T_2 V_317 = F_48 ( V_245 , V_22 ) ;
T_2 V_318 = F_64 ( V_245 + V_242 , V_22 ) - 1 ;
F_277 ( V_226 ) ;
if ( V_29 -> V_129 & V_282 ) {
error = - V_132 ;
goto V_150;
}
V_160 . V_162 = & V_226 ;
V_160 . V_92 = V_317 >> V_77 ;
V_160 . V_64 = ( V_318 + 1 ) >> V_77 ;
F_17 ( & V_3 -> V_161 ) ;
V_3 -> V_159 = & V_160 ;
F_18 ( & V_3 -> V_161 ) ;
if ( ( V_319 ) V_318 > ( V_319 ) V_317 )
F_126 ( V_41 , V_317 ,
1 + V_318 - V_317 , 0 ) ;
F_118 ( V_3 , V_245 , V_245 + V_242 - 1 ) ;
F_17 ( & V_3 -> V_161 ) ;
V_3 -> V_159 = NULL ;
F_278 ( & V_226 ) ;
F_153 ( ! F_43 ( & V_226 . V_221 ) ) ;
F_18 ( & V_3 -> V_161 ) ;
error = 0 ;
goto V_150;
}
error = F_279 ( V_3 , V_245 + V_242 ) ;
if ( error )
goto V_150;
if ( ( V_29 -> V_129 & V_131 ) && V_245 + V_242 > V_3 -> V_73 ) {
error = - V_132 ;
goto V_150;
}
V_92 = V_245 >> V_77 ;
V_93 = ( V_245 + V_242 + V_22 - 1 ) >> V_77 ;
if ( V_23 -> V_35 && V_93 - V_92 > V_23 -> V_35 ) {
error = - V_27 ;
goto V_150;
}
V_160 . V_162 = NULL ;
V_160 . V_92 = V_92 ;
V_160 . V_64 = V_92 ;
V_160 . V_320 = 0 ;
V_160 . V_163 = 0 ;
F_17 ( & V_3 -> V_161 ) ;
V_3 -> V_159 = & V_160 ;
F_18 ( & V_3 -> V_161 ) ;
for ( V_4 = V_92 ; V_4 < V_93 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_280 ( V_17 ) )
error = - V_321 ;
else if ( V_160 . V_163 > V_160 . V_320 )
error = - V_144 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_216 ) ;
if ( error ) {
if ( V_4 > V_92 ) {
F_105 ( V_3 ,
( T_2 ) V_92 << V_77 ,
( ( T_2 ) V_4 << V_77 ) - 1 , true ) ;
}
goto V_322;
}
V_160 . V_64 ++ ;
if ( ! F_111 ( V_5 ) )
V_160 . V_320 ++ ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
F_104 () ;
}
if ( ! ( V_172 & V_314 ) && V_245 + V_242 > V_3 -> V_73 )
F_125 ( V_3 , V_245 + V_242 ) ;
V_3 -> V_115 = F_119 ( V_3 ) ;
V_322:
F_17 ( & V_3 -> V_161 ) ;
V_3 -> V_159 = NULL ;
F_18 ( & V_3 -> V_161 ) ;
V_150:
F_258 ( V_3 ) ;
return error ;
}
static int F_281 ( struct V_119 * V_119 , struct V_323 * V_324 )
{
struct V_10 * V_23 = F_7 ( V_119 -> V_325 ) ;
V_324 -> V_326 = V_327 ;
V_324 -> V_328 = V_22 ;
V_324 -> V_329 = V_330 ;
if ( V_23 -> V_35 ) {
V_324 -> V_331 = V_23 -> V_35 ;
V_324 -> V_332 =
V_324 -> V_333 = V_23 -> V_35 -
F_282 ( & V_23 -> V_36 ) ;
}
if ( V_23 -> V_24 ) {
V_324 -> V_334 = V_23 -> V_24 ;
V_324 -> V_335 = V_23 -> V_26 ;
}
return 0 ;
}
static int
F_283 ( struct V_3 * V_263 , struct V_119 * V_119 , T_8 V_172 , T_9 V_264 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_230 ( V_263 -> V_34 , V_263 , V_172 , V_264 , V_16 ) ;
if ( V_3 ) {
error = F_284 ( V_263 , V_3 ) ;
if ( error )
goto V_336;
error = F_285 ( V_3 , V_263 ,
& V_119 -> V_337 ,
V_338 , NULL ) ;
if ( error && error != - V_316 )
goto V_336;
error = 0 ;
V_263 -> V_73 += V_275 ;
V_263 -> V_115 = V_263 -> V_116 = F_119 ( V_263 ) ;
F_286 ( V_119 , V_3 ) ;
F_287 ( V_119 ) ;
}
return error ;
V_336:
F_49 ( V_3 ) ;
return error ;
}
static int
F_288 ( struct V_3 * V_263 , struct V_119 * V_119 , T_8 V_172 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_230 ( V_263 -> V_34 , V_263 , V_172 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_285 ( V_3 , V_263 ,
NULL ,
V_338 , NULL ) ;
if ( error && error != - V_316 )
goto V_336;
error = F_284 ( V_263 , V_3 ) ;
if ( error )
goto V_336;
F_289 ( V_119 , V_3 ) ;
}
return error ;
V_336:
F_49 ( V_3 ) ;
return error ;
}
static int F_290 ( struct V_3 * V_263 , struct V_119 * V_119 , T_8 V_172 )
{
int error ;
if ( ( error = F_283 ( V_263 , V_119 , V_172 | V_274 , 0 ) ) )
return error ;
F_241 ( V_263 ) ;
return 0 ;
}
static int F_291 ( struct V_3 * V_263 , struct V_119 * V_119 , T_8 V_172 ,
bool V_339 )
{
return F_283 ( V_263 , V_119 , V_172 | V_271 , 0 ) ;
}
static int F_292 ( struct V_119 * V_340 , struct V_3 * V_263 , struct V_119 * V_119 )
{
struct V_3 * V_3 = V_122 ( V_340 ) ;
int V_75 ;
V_75 = F_16 ( V_3 -> V_34 ) ;
if ( V_75 )
goto V_150;
V_263 -> V_73 += V_275 ;
V_3 -> V_115 = V_263 -> V_115 = V_263 -> V_116 = F_119 ( V_3 ) ;
F_241 ( V_3 ) ;
F_293 ( V_3 ) ;
F_287 ( V_119 ) ;
F_286 ( V_119 , V_3 ) ;
V_150:
return V_75 ;
}
static int F_294 ( struct V_3 * V_263 , struct V_119 * V_119 )
{
struct V_3 * V_3 = V_122 ( V_119 ) ;
if ( V_3 -> V_341 > 1 && ! F_295 ( V_3 -> V_125 ) )
F_19 ( V_3 -> V_34 ) ;
V_263 -> V_73 -= V_275 ;
V_3 -> V_115 = V_263 -> V_115 = V_263 -> V_116 = F_119 ( V_3 ) ;
F_296 ( V_3 ) ;
F_297 ( V_119 ) ;
return 0 ;
}
static int F_298 ( struct V_3 * V_263 , struct V_119 * V_119 )
{
if ( ! F_299 ( V_119 ) )
return - V_342 ;
F_296 ( V_122 ( V_119 ) ) ;
F_296 ( V_263 ) ;
return F_294 ( V_263 , V_119 ) ;
}
static int F_300 ( struct V_3 * V_343 , struct V_119 * V_340 , struct V_3 * V_344 , struct V_119 * V_345 )
{
bool V_346 = F_301 ( V_340 ) ;
bool V_347 = F_301 ( V_345 ) ;
if ( V_343 != V_344 && V_346 != V_347 ) {
if ( V_346 ) {
F_296 ( V_343 ) ;
F_241 ( V_344 ) ;
} else {
F_296 ( V_344 ) ;
F_241 ( V_343 ) ;
}
}
V_343 -> V_115 = V_343 -> V_116 =
V_344 -> V_115 = V_344 -> V_116 =
V_122 ( V_340 ) -> V_115 =
V_122 ( V_345 ) -> V_115 = F_119 ( V_343 ) ;
return 0 ;
}
static int F_302 ( struct V_3 * V_343 , struct V_119 * V_340 )
{
struct V_119 * V_348 ;
int error ;
V_348 = F_303 ( V_340 -> V_349 , & V_340 -> V_337 ) ;
if ( ! V_348 )
return - V_144 ;
error = F_283 ( V_343 , V_348 ,
V_350 | V_351 , V_352 ) ;
F_297 ( V_348 ) ;
if ( error )
return error ;
F_304 ( V_348 ) ;
return 0 ;
}
static int F_305 ( struct V_3 * V_343 , struct V_119 * V_340 , struct V_3 * V_344 , struct V_119 * V_345 , unsigned int V_14 )
{
struct V_3 * V_3 = V_122 ( V_340 ) ;
int V_353 = F_295 ( V_3 -> V_125 ) ;
if ( V_14 & ~ ( V_354 | V_355 | V_356 ) )
return - V_57 ;
if ( V_14 & V_355 )
return F_300 ( V_343 , V_340 , V_344 , V_345 ) ;
if ( ! F_299 ( V_345 ) )
return - V_342 ;
if ( V_14 & V_356 ) {
int error ;
error = F_302 ( V_343 , V_340 ) ;
if ( error )
return error ;
}
if ( F_306 ( V_345 ) ) {
( void ) F_294 ( V_344 , V_345 ) ;
if ( V_353 ) {
F_296 ( V_122 ( V_345 ) ) ;
F_296 ( V_343 ) ;
}
} else if ( V_353 ) {
F_296 ( V_343 ) ;
F_241 ( V_344 ) ;
}
V_343 -> V_73 -= V_275 ;
V_344 -> V_73 += V_275 ;
V_343 -> V_115 = V_343 -> V_116 =
V_344 -> V_115 = V_344 -> V_116 =
V_3 -> V_115 = F_119 ( V_343 ) ;
return 0 ;
}
static int F_307 ( struct V_3 * V_263 , struct V_119 * V_119 , const char * V_357 )
{
int error ;
int V_242 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_28 * V_29 ;
V_242 = strlen ( V_357 ) + 1 ;
if ( V_242 > V_22 )
return - V_358 ;
V_3 = F_230 ( V_263 -> V_34 , V_263 , V_278 | V_359 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_27 ;
error = F_285 ( V_3 , V_263 , & V_119 -> V_337 ,
V_338 , NULL ) ;
if ( error ) {
if ( error != - V_316 ) {
F_49 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_3 -> V_73 = V_242 - 1 ;
if ( V_242 <= V_360 ) {
V_3 -> V_361 = F_308 ( V_357 , V_242 , V_151 ) ;
if ( ! V_3 -> V_361 ) {
F_49 ( V_3 ) ;
return - V_144 ;
}
V_3 -> V_269 = & V_362 ;
} else {
F_309 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_205 ) ;
if ( error ) {
F_49 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_136 = & V_137 ;
V_3 -> V_269 = & V_363 ;
memcpy ( F_310 ( V_5 ) , V_357 , V_242 ) ;
F_155 ( V_5 ) ;
F_116 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_5 ) ;
}
V_263 -> V_73 += V_275 ;
V_263 -> V_115 = V_263 -> V_116 = F_119 ( V_263 ) ;
F_286 ( V_119 , V_3 ) ;
F_287 ( V_119 ) ;
return 0 ;
}
static void F_311 ( void * V_310 )
{
F_195 ( V_310 ) ;
F_54 ( V_310 ) ;
}
static const char * F_312 ( struct V_119 * V_119 ,
struct V_3 * V_3 ,
struct V_364 * V_295 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_119 ) {
V_5 = F_313 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_183 ( - V_365 ) ;
if ( ! F_111 ( V_5 ) ) {
F_54 ( V_5 ) ;
return F_183 ( - V_365 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_113 ) ;
if ( error )
return F_183 ( error ) ;
F_53 ( V_5 ) ;
}
F_314 ( V_295 , F_311 , V_5 ) ;
return F_310 ( V_5 ) ;
}
static int V_338 ( struct V_3 * V_3 ,
const struct V_366 * V_367 ,
void * V_368 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
const struct V_366 * V_366 ;
struct V_369 * V_370 ;
T_11 V_242 ;
for ( V_366 = V_367 ; V_366 -> V_371 != NULL ; V_366 ++ ) {
V_370 = F_315 ( V_366 -> V_372 , V_366 -> V_373 ) ;
if ( ! V_370 )
return - V_144 ;
V_242 = strlen ( V_366 -> V_371 ) + 1 ;
V_370 -> V_371 = F_316 ( V_374 + V_242 ,
V_151 ) ;
if ( ! V_370 -> V_371 ) {
F_317 ( V_370 ) ;
return - V_144 ;
}
memcpy ( V_370 -> V_371 , V_375 ,
V_374 ) ;
memcpy ( V_370 -> V_371 + V_374 ,
V_366 -> V_371 , V_242 ) ;
F_318 ( & V_29 -> V_140 , V_370 ) ;
}
return 0 ;
}
static int F_319 ( const struct V_376 * V_377 ,
struct V_119 * V_378 , struct V_3 * V_3 ,
const char * V_371 , void * V_171 , T_11 V_15 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_371 = F_320 ( V_377 , V_371 ) ;
return F_321 ( & V_29 -> V_140 , V_371 , V_171 , V_15 ) ;
}
static int F_322 ( const struct V_376 * V_377 ,
struct V_119 * V_378 , struct V_3 * V_3 ,
const char * V_371 , const void * V_372 ,
T_11 V_15 , int V_14 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_371 = F_320 ( V_377 , V_371 ) ;
return F_323 ( & V_29 -> V_140 , V_371 , V_372 , V_15 , V_14 ) ;
}
static T_10 F_324 ( struct V_119 * V_119 , char * V_171 , T_11 V_15 )
{
struct V_28 * V_29 = F_21 ( V_122 ( V_119 ) ) ;
return F_325 ( V_122 ( V_119 ) , & V_29 -> V_140 , V_171 , V_15 ) ;
}
static struct V_119 * F_326 ( struct V_119 * V_379 )
{
return F_183 ( - V_380 ) ;
}
static int F_327 ( struct V_3 * V_381 , void * V_382 )
{
T_12 * V_383 = V_382 ;
T_13 V_384 = V_383 [ 2 ] ;
V_384 = ( V_384 << 32 ) | V_383 [ 1 ] ;
return V_381 -> V_174 == V_384 && V_383 [ 0 ] == V_381 -> V_266 ;
}
static struct V_119 * F_328 ( struct V_11 * V_12 ,
struct V_385 * V_385 , int V_386 , int V_387 )
{
struct V_3 * V_3 ;
struct V_119 * V_119 = NULL ;
V_319 V_384 ;
if ( V_386 < 3 )
return NULL ;
V_384 = V_385 -> V_388 [ 2 ] ;
V_384 = ( V_384 << 32 ) | V_385 -> V_388 [ 1 ] ;
V_3 = F_329 ( V_12 , ( unsigned long ) ( V_384 + V_385 -> V_388 [ 0 ] ) ,
F_327 , V_385 -> V_388 ) ;
if ( V_3 ) {
V_119 = F_330 ( V_3 ) ;
F_49 ( V_3 ) ;
}
return V_119 ;
}
static int F_331 ( struct V_3 * V_3 , T_12 * V_383 , int * V_242 ,
struct V_3 * V_389 )
{
if ( * V_242 < 3 ) {
* V_242 = 3 ;
return V_390 ;
}
if ( F_332 ( V_3 ) ) {
static F_333 ( V_39 ) ;
F_17 ( & V_39 ) ;
if ( F_332 ( V_3 ) )
F_334 ( V_3 ,
V_3 -> V_174 + V_3 -> V_266 ) ;
F_18 ( & V_39 ) ;
}
V_383 [ 0 ] = V_3 -> V_266 ;
V_383 [ 1 ] = V_3 -> V_174 ;
V_383 [ 2 ] = ( ( T_13 ) V_3 -> V_174 ) >> 32 ;
* V_242 = 3 ;
return 1 ;
}
static int F_335 ( char * V_391 , struct V_10 * V_23 ,
bool V_392 )
{
char * V_393 , * V_372 , * V_394 ;
struct V_169 * V_170 = NULL ;
T_14 V_395 ;
T_15 V_396 ;
while ( V_391 != NULL ) {
V_393 = V_391 ;
for (; ; ) {
V_391 = strchr ( V_391 , ',' ) ;
if ( V_391 == NULL )
break;
V_391 ++ ;
if ( ! isdigit ( * V_391 ) ) {
V_391 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_393 )
continue;
if ( ( V_372 = strchr ( V_393 , '=' ) ) != NULL ) {
* V_372 ++ = 0 ;
} else {
F_336 ( L_9 ,
V_393 ) ;
goto error;
}
if ( ! strcmp ( V_393 , L_10 ) ) {
unsigned long long V_15 ;
V_15 = F_337 ( V_372 , & V_394 ) ;
if ( * V_394 == '%' ) {
V_15 <<= V_77 ;
V_15 *= V_1 ;
F_338 ( V_15 , 100 ) ;
V_394 ++ ;
}
if ( * V_394 )
goto V_397;
V_23 -> V_35 =
F_205 ( V_15 , V_22 ) ;
} else if ( ! strcmp ( V_393 , L_11 ) ) {
V_23 -> V_35 = F_337 ( V_372 , & V_394 ) ;
if ( * V_394 )
goto V_397;
} else if ( ! strcmp ( V_393 , L_12 ) ) {
V_23 -> V_24 = F_337 ( V_372 , & V_394 ) ;
if ( * V_394 )
goto V_397;
} else if ( ! strcmp ( V_393 , L_13 ) ) {
if ( V_392 )
continue;
V_23 -> V_172 = F_339 ( V_372 , & V_394 , 8 ) & 07777 ;
if ( * V_394 )
goto V_397;
} else if ( ! strcmp ( V_393 , L_14 ) ) {
if ( V_392 )
continue;
V_395 = F_339 ( V_372 , & V_394 , 0 ) ;
if ( * V_394 )
goto V_397;
V_23 -> V_395 = F_340 ( F_341 () , V_395 ) ;
if ( ! F_342 ( V_23 -> V_395 ) )
goto V_397;
} else if ( ! strcmp ( V_393 , L_15 ) ) {
if ( V_392 )
continue;
V_396 = F_339 ( V_372 , & V_394 , 0 ) ;
if ( * V_394 )
goto V_397;
V_23 -> V_396 = F_343 ( F_341 () , V_396 ) ;
if ( ! F_344 ( V_23 -> V_396 ) )
goto V_397;
#ifdef V_134
} else if ( ! strcmp ( V_393 , L_16 ) ) {
int V_58 ;
V_58 = F_39 ( V_372 ) ;
if ( V_58 < 0 )
goto V_397;
if ( ! F_345 () &&
V_58 != V_51 )
goto V_397;
V_23 -> V_58 = V_58 ;
#endif
#ifdef F_346
} else if ( ! strcmp ( V_393 , L_17 ) ) {
F_347 ( V_170 ) ;
V_170 = NULL ;
if ( F_348 ( V_372 , & V_170 ) )
goto V_397;
#endif
} else {
F_336 ( L_18 , V_393 ) ;
goto error;
}
}
V_23 -> V_170 = V_170 ;
return 0 ;
V_397:
F_336 ( L_19 ,
V_372 , V_393 ) ;
error:
F_347 ( V_170 ) ;
return 1 ;
}
static int F_349 ( struct V_11 * V_12 , int * V_14 , char * V_398 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
struct V_10 V_399 = * V_23 ;
unsigned long V_400 ;
int error = - V_57 ;
V_399 . V_170 = NULL ;
if ( F_335 ( V_398 , & V_399 , true ) )
return error ;
F_17 ( & V_23 -> V_25 ) ;
V_400 = V_23 -> V_24 - V_23 -> V_26 ;
if ( F_26 ( & V_23 -> V_36 , V_399 . V_35 ) > 0 )
goto V_150;
if ( V_399 . V_24 < V_400 )
goto V_150;
if ( V_399 . V_35 && ! V_23 -> V_35 )
goto V_150;
if ( V_399 . V_24 && ! V_23 -> V_24 )
goto V_150;
error = 0 ;
V_23 -> V_58 = V_399 . V_58 ;
V_23 -> V_35 = V_399 . V_35 ;
V_23 -> V_24 = V_399 . V_24 ;
V_23 -> V_26 = V_399 . V_24 - V_400 ;
if ( V_399 . V_170 ) {
F_347 ( V_23 -> V_170 ) ;
V_23 -> V_170 = V_399 . V_170 ;
}
V_150:
F_18 ( & V_23 -> V_25 ) ;
return error ;
}
static int F_350 ( struct V_167 * V_168 , struct V_119 * V_401 )
{
struct V_10 * V_23 = F_7 ( V_401 -> V_325 ) ;
if ( V_23 -> V_35 != F_1 () )
F_165 ( V_168 , L_20 ,
V_23 -> V_35 << ( V_77 - 10 ) ) ;
if ( V_23 -> V_24 != F_2 () )
F_165 ( V_168 , L_21 , V_23 -> V_24 ) ;
if ( V_23 -> V_172 != ( V_359 | V_402 ) )
F_165 ( V_168 , L_22 , V_23 -> V_172 ) ;
if ( ! F_351 ( V_23 -> V_395 , V_403 ) )
F_165 ( V_168 , L_23 ,
F_352 ( & V_404 , V_23 -> V_395 ) ) ;
if ( ! F_353 ( V_23 -> V_396 , V_405 ) )
F_165 ( V_168 , L_24 ,
F_354 ( & V_404 , V_23 -> V_396 ) ) ;
#ifdef V_134
if ( V_23 -> V_58 )
F_165 ( V_168 , L_25 , F_40 ( V_23 -> V_58 ) ) ;
#endif
F_163 ( V_168 , V_23 -> V_170 ) ;
return 0 ;
}
static void F_355 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
F_356 ( & V_23 -> V_36 ) ;
F_347 ( V_23 -> V_170 ) ;
F_317 ( V_23 ) ;
V_12 -> V_13 = NULL ;
}
int F_357 ( struct V_11 * V_12 , void * V_398 , int V_406 )
{
struct V_3 * V_3 ;
struct V_10 * V_23 ;
int V_184 = - V_144 ;
V_23 = F_358 ( F_359 ( ( int ) sizeof( struct V_10 ) ,
V_407 ) , V_151 ) ;
if ( ! V_23 )
return - V_144 ;
V_23 -> V_172 = V_359 | V_402 ;
V_23 -> V_395 = F_360 () ;
V_23 -> V_396 = F_361 () ;
V_12 -> V_13 = V_23 ;
#ifdef F_362
if ( ! ( V_12 -> V_408 & V_409 ) ) {
V_23 -> V_35 = F_1 () ;
V_23 -> V_24 = F_2 () ;
if ( F_335 ( V_398 , V_23 , false ) ) {
V_184 = - V_57 ;
goto V_185;
}
} else {
V_12 -> V_408 |= V_410 ;
}
V_12 -> V_411 = & V_412 ;
V_12 -> V_408 |= V_413 ;
#else
V_12 -> V_408 |= V_410 ;
#endif
F_235 ( & V_23 -> V_25 ) ;
if ( F_363 ( & V_23 -> V_36 , 0 , V_151 ) )
goto V_185;
V_23 -> V_26 = V_23 -> V_24 ;
F_235 ( & V_23 -> V_71 ) ;
F_236 ( & V_23 -> V_69 ) ;
V_12 -> V_414 = V_198 ;
V_12 -> V_415 = V_22 ;
V_12 -> V_416 = V_77 ;
V_12 -> V_417 = V_327 ;
V_12 -> V_279 = & V_280 ;
V_12 -> V_418 = 1 ;
#ifdef F_364
V_12 -> V_419 = V_420 ;
#endif
#ifdef F_365
V_12 -> V_408 |= V_421 ;
#endif
V_3 = F_230 ( V_12 , NULL , V_274 | V_23 -> V_172 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_185;
V_3 -> V_422 = V_23 -> V_395 ;
V_3 -> V_423 = V_23 -> V_396 ;
V_12 -> V_424 = F_366 ( V_3 ) ;
if ( ! V_12 -> V_424 )
goto V_185;
return 0 ;
V_185:
F_355 ( V_12 ) ;
return V_184 ;
}
static struct V_3 * F_367 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
V_29 = F_368 ( V_425 , V_151 ) ;
if ( ! V_29 )
return NULL ;
return & V_29 -> V_72 ;
}
static void F_369 ( struct V_426 * V_217 )
{
struct V_3 * V_3 = F_370 ( V_217 , struct V_3 , V_427 ) ;
if ( F_371 ( V_3 -> V_125 ) )
F_317 ( V_3 -> V_361 ) ;
F_372 ( V_425 , F_21 ( V_3 ) ) ;
}
static void F_373 ( struct V_3 * V_3 )
{
if ( F_124 ( V_3 -> V_125 ) )
F_374 ( & F_21 ( V_3 ) -> V_177 ) ;
F_375 ( & V_3 -> V_427 , F_369 ) ;
}
static void F_376 ( void * V_428 )
{
struct V_28 * V_29 = V_428 ;
F_377 ( & V_29 -> V_72 ) ;
}
static int F_378 ( void )
{
V_425 = F_379 ( L_26 ,
sizeof( struct V_28 ) ,
0 , V_429 | V_430 , F_376 ) ;
return 0 ;
}
static void F_380 ( void )
{
F_381 ( V_425 ) ;
}
static struct V_119 * F_382 ( struct V_431 * V_432 ,
int V_14 , const char * V_433 , void * V_398 )
{
return F_383 ( V_432 , V_14 , V_398 , F_357 ) ;
}
int T_16 F_384 ( void )
{
int error ;
if ( V_425 )
return 0 ;
error = F_378 () ;
if ( error )
goto V_434;
error = F_385 ( & V_435 ) ;
if ( error ) {
F_336 ( L_27 ) ;
goto V_436;
}
V_255 = F_386 ( & V_435 ) ;
if ( F_199 ( V_255 ) ) {
error = F_200 ( V_255 ) ;
F_336 ( L_28 ) ;
goto V_437;
}
#ifdef V_134
if ( F_345 () && V_211 < V_55 )
F_7 ( V_255 -> V_256 ) -> V_58 = V_211 ;
else
V_211 = 0 ;
#endif
return 0 ;
V_437:
F_387 ( & V_435 ) ;
V_436:
F_380 () ;
V_434:
V_255 = F_183 ( error ) ;
return error ;
}
static T_10 F_388 ( struct V_438 * V_439 ,
struct V_440 * V_124 , char * V_324 )
{
int V_441 [] = {
V_52 ,
V_53 ,
V_54 ,
V_51 ,
V_55 ,
V_56 ,
} ;
int V_83 , V_442 ;
for ( V_83 = 0 , V_442 = 0 ; V_83 < F_389 ( V_441 ) ; V_83 ++ ) {
const char * V_443 = V_211 == V_441 [ V_83 ] ? L_29 : L_30 ;
V_442 += sprintf ( V_324 + V_442 , V_443 ,
F_40 ( V_441 [ V_83 ] ) ) ;
}
V_324 [ V_442 - 1 ] = '\n' ;
return V_442 ;
}
static T_10 F_390 ( struct V_438 * V_439 ,
struct V_440 * V_124 , const char * V_324 , T_11 V_442 )
{
char V_444 [ 16 ] ;
int V_58 ;
if ( V_442 + 1 > sizeof( V_444 ) )
return - V_57 ;
memcpy ( V_444 , V_324 , V_442 ) ;
V_444 [ V_442 ] = '\0' ;
if ( V_442 && V_444 [ V_442 - 1 ] == '\n' )
V_444 [ V_442 - 1 ] = '\0' ;
V_58 = F_39 ( V_444 ) ;
if ( V_58 == - V_57 )
return - V_57 ;
if ( ! F_345 () &&
V_58 != V_51 && V_58 != V_55 )
return - V_57 ;
V_211 = V_58 ;
if ( V_211 < V_55 )
F_7 ( V_255 -> V_256 ) -> V_58 = V_211 ;
return V_442 ;
}
bool F_391 ( struct V_97 * V_98 )
{
struct V_3 * V_3 = F_95 ( V_98 -> V_99 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
T_2 V_73 ;
T_1 V_213 ;
if ( V_211 == V_56 )
return true ;
if ( V_211 == V_55 )
return false ;
switch ( V_23 -> V_58 ) {
case V_51 :
return false ;
case V_52 :
return true ;
case V_53 :
V_213 = F_48 ( V_98 -> V_100 , V_84 ) ;
V_73 = F_48 ( F_194 ( V_3 ) , V_22 ) ;
if ( V_73 >= V_74 &&
V_73 >> V_77 >= V_213 )
return true ;
case V_54 :
return ( V_98 -> V_235 & V_236 ) ;
default:
F_30 ( 1 ) ;
return false ;
}
}
int T_16 F_384 ( void )
{
F_80 ( F_385 ( & V_435 ) != 0 ) ;
V_255 = F_386 ( & V_435 ) ;
F_80 ( F_199 ( V_255 ) ) ;
return 0 ;
}
int F_145 ( T_3 V_49 , struct V_5 * V_5 )
{
return 0 ;
}
int F_222 ( struct V_240 * V_240 , int V_39 , struct V_257 * V_258 )
{
return 0 ;
}
void F_97 ( struct V_40 * V_41 )
{
}
unsigned long F_217 ( struct V_240 * V_240 ,
unsigned long V_244 , unsigned long V_242 ,
unsigned long V_225 , unsigned long V_14 )
{
return V_17 -> V_18 -> V_250 ( V_240 , V_244 , V_242 , V_225 , V_14 ) ;
}
void F_118 ( struct V_3 * V_3 , T_2 V_107 , T_2 V_108 )
{
F_392 ( V_3 -> V_9 , V_107 , V_108 ) ;
}
static struct V_240 * F_393 ( const char * V_371 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_445 )
{
struct V_240 * V_446 ;
struct V_3 * V_3 ;
struct V_447 V_447 ;
struct V_11 * V_12 ;
struct V_448 V_146 ;
if ( F_199 ( V_255 ) )
return F_394 ( V_255 ) ;
if ( V_15 < 0 || V_15 > V_198 )
return F_183 ( - V_57 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_183 ( - V_144 ) ;
V_446 = F_183 ( - V_144 ) ;
V_146 . V_371 = V_371 ;
V_146 . V_242 = strlen ( V_371 ) ;
V_146 . V_449 = 0 ;
V_12 = V_255 -> V_256 ;
V_447 . V_118 = F_395 ( V_255 ) ;
V_447 . V_119 = F_396 ( V_12 , & V_146 ) ;
if ( ! V_447 . V_119 )
goto V_450;
F_397 ( V_447 . V_119 , & V_451 ) ;
V_446 = F_183 ( - V_27 ) ;
V_3 = F_230 ( V_12 , NULL , V_271 | V_359 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_450;
V_3 -> V_445 |= V_445 ;
F_286 ( V_447 . V_119 , V_3 ) ;
V_3 -> V_73 = V_15 ;
F_398 ( V_3 ) ;
V_446 = F_183 ( F_399 ( V_3 , V_15 ) ) ;
if ( F_199 ( V_446 ) )
goto V_452;
V_446 = F_400 ( & V_447 , V_307 | V_453 ,
& V_254 ) ;
if ( F_199 ( V_446 ) )
goto V_452;
return V_446 ;
V_450:
F_11 ( V_14 , V_15 ) ;
V_452:
F_401 ( & V_447 ) ;
return V_446 ;
}
struct V_240 * F_402 ( const char * V_371 , T_2 V_15 , unsigned long V_14 )
{
return F_393 ( V_371 , V_15 , V_14 , V_454 ) ;
}
struct V_240 * F_403 ( const char * V_371 , T_2 V_15 , unsigned long V_14 )
{
return F_393 ( V_371 , V_15 , V_14 , 0 ) ;
}
int F_404 ( struct V_97 * V_98 )
{
struct V_240 * V_240 ;
T_2 V_15 = V_98 -> V_101 - V_98 -> V_102 ;
V_240 = F_393 ( L_31 , V_15 , V_98 -> V_235 , V_454 ) ;
if ( F_199 ( V_240 ) )
return F_200 ( V_240 ) ;
if ( V_98 -> V_99 )
F_405 ( V_98 -> V_99 ) ;
V_98 -> V_99 = V_240 ;
V_98 -> V_175 = & V_262 ;
if ( F_127 ( V_134 ) &&
( ( V_98 -> V_102 + ~ V_76 ) & V_76 ) <
( V_98 -> V_101 & V_76 ) ) {
F_229 ( V_98 , V_98 -> V_235 ) ;
}
return 0 ;
}
struct V_5 * F_406 ( struct V_40 * V_41 ,
T_1 V_4 , T_5 V_141 )
{
#ifdef F_407
struct V_3 * V_3 = V_41 -> V_154 ;
struct V_5 * V_5 ;
int error ;
F_80 ( V_41 -> V_136 != & V_137 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_202 ,
V_141 , NULL , NULL ) ;
if ( error )
V_5 = F_183 ( error ) ;
else
F_53 ( V_5 ) ;
return V_5 ;
#else
return F_408 ( V_41 , V_4 , V_141 ) ;
#endif
}
