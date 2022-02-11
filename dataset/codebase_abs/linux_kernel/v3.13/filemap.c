void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
F_2 ( V_1 ) ;
if ( F_3 ( V_1 ) && F_4 ( V_1 ) )
F_5 ( V_1 ) ;
else
F_6 ( V_3 , V_1 ) ;
F_7 ( & V_3 -> V_4 , V_1 -> V_5 ) ;
V_1 -> V_3 = NULL ;
V_3 -> V_6 -- ;
F_8 ( V_1 , V_7 ) ;
if ( F_9 ( V_1 ) )
F_8 ( V_1 , V_8 ) ;
F_10 ( F_11 ( V_1 ) ) ;
if ( F_12 ( V_1 ) && F_13 ( V_3 ) ) {
F_14 ( V_1 , V_9 ) ;
F_15 ( V_3 -> V_10 , V_11 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
void (* F_17)( struct V_1 * );
F_10 ( ! F_18 ( V_1 ) ) ;
F_17 = V_3 -> V_12 -> F_17 ;
F_19 ( & V_3 -> V_13 ) ;
F_1 ( V_1 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_21 ( V_1 ) ;
if ( F_17 )
F_17 ( V_1 ) ;
F_22 ( V_1 ) ;
}
static int F_23 ( void * V_14 )
{
F_24 () ;
return 0 ;
}
static int F_25 ( void * V_14 )
{
F_23 ( V_14 ) ;
return F_26 ( V_15 ) ? - V_16 : 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_17 = 0 ;
if ( F_28 ( V_18 , & V_3 -> V_19 ) )
V_17 = - V_20 ;
if ( F_28 ( V_21 , & V_3 -> V_19 ) )
V_17 = - V_22 ;
return V_17 ;
}
int F_29 ( struct V_2 * V_3 , T_1 V_23 ,
T_1 V_24 , int V_25 )
{
int V_17 ;
struct V_26 V_27 = {
. V_25 = V_25 ,
. V_28 = V_29 ,
. V_30 = V_23 ,
. V_31 = V_24 ,
} ;
if ( ! F_30 ( V_3 ) )
return 0 ;
V_17 = F_31 ( V_3 , & V_27 ) ;
return V_17 ;
}
static inline int F_32 ( struct V_2 * V_3 ,
int V_25 )
{
return F_29 ( V_3 , 0 , V_32 , V_25 ) ;
}
int F_33 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , V_33 ) ;
}
int F_34 ( struct V_2 * V_3 , T_1 V_23 ,
T_1 V_24 )
{
return F_29 ( V_3 , V_23 , V_24 , V_33 ) ;
}
int F_35 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , V_34 ) ;
}
int F_36 ( struct V_2 * V_3 , T_1 V_35 ,
T_1 V_36 )
{
T_2 V_5 = V_35 >> V_37 ;
T_2 V_24 = V_36 >> V_37 ;
struct V_38 V_39 ;
int V_40 ;
int V_41 , V_17 = 0 ;
if ( V_36 < V_35 )
goto V_42;
F_37 ( & V_39 , 0 ) ;
while ( ( V_5 <= V_24 ) &&
( V_40 = F_38 ( & V_39 , V_3 , & V_5 ,
V_43 ,
F_39 ( V_24 - V_5 , ( T_2 ) V_44 - 1 ) + 1 ) ) != 0 ) {
unsigned V_45 ;
for ( V_45 = 0 ; V_45 < V_40 ; V_45 ++ ) {
struct V_1 * V_1 = V_39 . V_46 [ V_45 ] ;
if ( V_1 -> V_5 > V_24 )
continue;
F_40 ( V_1 ) ;
if ( F_41 ( V_1 ) )
V_17 = - V_22 ;
}
F_42 ( & V_39 ) ;
F_43 () ;
}
V_42:
V_41 = F_27 ( V_3 ) ;
if ( ! V_17 )
V_17 = V_41 ;
return V_17 ;
}
int F_44 ( struct V_2 * V_3 )
{
T_1 V_47 = F_45 ( V_3 -> V_48 ) ;
if ( V_47 == 0 )
return 0 ;
return F_36 ( V_3 , 0 , V_47 - 1 ) ;
}
int F_46 ( struct V_2 * V_3 )
{
int V_49 = 0 ;
if ( V_3 -> V_6 ) {
V_49 = F_33 ( V_3 ) ;
if ( V_49 != - V_22 ) {
int V_50 = F_44 ( V_3 ) ;
if ( ! V_49 )
V_49 = V_50 ;
}
} else {
V_49 = F_27 ( V_3 ) ;
}
return V_49 ;
}
int F_47 ( struct V_2 * V_3 ,
T_1 V_51 , T_1 V_52 )
{
int V_49 = 0 ;
if ( V_3 -> V_6 ) {
V_49 = F_29 ( V_3 , V_51 , V_52 ,
V_33 ) ;
if ( V_49 != - V_22 ) {
int V_50 = F_36 ( V_3 ,
V_51 , V_52 ) ;
if ( ! V_49 )
V_49 = V_50 ;
}
} else {
V_49 = F_27 ( V_3 ) ;
}
return V_49 ;
}
int F_48 ( struct V_1 * V_53 , struct V_1 * V_54 , T_3 V_55 )
{
int error ;
F_49 ( ! F_18 ( V_53 ) ) ;
F_49 ( ! F_18 ( V_54 ) ) ;
F_49 ( V_54 -> V_3 ) ;
error = F_50 ( V_55 & ~ V_56 ) ;
if ( ! error ) {
struct V_2 * V_3 = V_53 -> V_3 ;
void (* F_17)( struct V_1 * );
T_2 V_57 = V_53 -> V_5 ;
F_17 = V_3 -> V_12 -> F_17 ;
F_51 ( V_54 ) ;
V_54 -> V_3 = V_3 ;
V_54 -> V_5 = V_57 ;
F_19 ( & V_3 -> V_13 ) ;
F_1 ( V_53 ) ;
error = F_52 ( & V_3 -> V_4 , V_57 , V_54 ) ;
F_10 ( error ) ;
V_3 -> V_6 ++ ;
F_53 ( V_54 , V_7 ) ;
if ( F_9 ( V_54 ) )
F_53 ( V_54 , V_8 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_54 ( V_53 , V_54 ) ;
F_55 () ;
if ( F_17 )
F_17 ( V_53 ) ;
F_22 ( V_53 ) ;
}
return error ;
}
int F_56 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_55 )
{
int error ;
F_49 ( ! F_18 ( V_1 ) ) ;
F_49 ( F_9 ( V_1 ) ) ;
error = F_57 ( V_1 , V_15 -> V_58 ,
V_55 & V_59 ) ;
if ( error )
return error ;
error = F_58 ( V_55 & ~ V_56 ) ;
if ( error ) {
F_21 ( V_1 ) ;
return error ;
}
F_51 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_57 ;
F_19 ( & V_3 -> V_13 ) ;
error = F_52 ( & V_3 -> V_4 , V_57 , V_1 ) ;
F_55 () ;
if ( F_59 ( error ) )
goto V_60;
V_3 -> V_6 ++ ;
F_53 ( V_1 , V_7 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_60 ( V_1 ) ;
return 0 ;
V_60:
V_1 -> V_3 = NULL ;
F_20 ( & V_3 -> V_13 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
return error ;
}
int F_61 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_55 )
{
int V_17 ;
V_17 = F_62 ( V_1 , V_3 , V_57 , V_55 ) ;
if ( V_17 == 0 )
F_63 ( V_1 ) ;
return V_17 ;
}
struct V_1 * F_64 ( T_3 V_61 )
{
int V_62 ;
struct V_1 * V_1 ;
if ( F_65 () ) {
unsigned int V_63 ;
do {
V_63 = F_66 () ;
V_62 = F_67 () ;
V_1 = F_68 ( V_62 , V_61 , 0 ) ;
} while ( ! F_69 ( V_63 ) && ! V_1 );
return V_1 ;
}
return F_70 ( V_61 , 0 ) ;
}
static T_4 * F_71 ( struct V_1 * V_1 )
{
const struct V_64 * V_64 = F_72 ( V_1 ) ;
return & V_64 -> V_65 [ F_73 ( V_1 , V_64 -> V_66 ) ] ;
}
static inline void F_74 ( struct V_1 * V_1 , int V_67 )
{
F_75 ( F_71 ( V_1 ) , & V_1 -> V_19 , V_67 ) ;
}
void F_76 ( struct V_1 * V_1 , int V_68 )
{
F_77 ( V_69 , & V_1 -> V_19 , V_68 ) ;
if ( F_78 ( V_68 , & V_1 -> V_19 ) )
F_79 ( F_71 ( V_1 ) , & V_69 , F_23 ,
V_70 ) ;
}
int F_80 ( struct V_1 * V_1 , int V_68 )
{
F_77 ( V_69 , & V_1 -> V_19 , V_68 ) ;
if ( ! F_78 ( V_68 , & V_1 -> V_19 ) )
return 0 ;
return F_79 ( F_71 ( V_1 ) , & V_69 ,
F_25 , V_71 ) ;
}
void F_81 ( struct V_1 * V_1 , T_5 * V_72 )
{
T_4 * V_73 = F_71 ( V_1 ) ;
unsigned long V_19 ;
F_82 ( & V_73 -> V_74 , V_19 ) ;
F_83 ( V_73 , V_72 ) ;
F_84 ( & V_73 -> V_74 , V_19 ) ;
}
void F_85 ( struct V_1 * V_1 )
{
F_49 ( ! F_18 ( V_1 ) ) ;
F_86 ( V_75 , & V_1 -> V_19 ) ;
F_87 () ;
F_74 ( V_1 , V_75 ) ;
}
void F_88 ( struct V_1 * V_1 )
{
if ( F_89 ( V_1 ) )
F_90 ( V_1 ) ;
if ( ! F_91 ( V_1 ) )
F_92 () ;
F_87 () ;
F_74 ( V_1 , V_76 ) ;
}
void F_93 ( struct V_1 * V_1 )
{
F_77 ( V_69 , & V_1 -> V_19 , V_75 ) ;
F_94 ( F_71 ( V_1 ) , & V_69 , F_23 ,
V_70 ) ;
}
int F_95 ( struct V_1 * V_1 )
{
F_77 ( V_69 , & V_1 -> V_19 , V_75 ) ;
return F_94 ( F_71 ( V_1 ) , & V_69 ,
F_25 , V_71 ) ;
}
int F_96 ( struct V_1 * V_1 , struct V_77 * V_58 ,
unsigned int V_19 )
{
if ( V_19 & V_78 ) {
if ( V_19 & V_79 )
return 0 ;
F_97 ( & V_58 -> V_80 ) ;
if ( V_19 & V_81 )
F_98 ( V_1 ) ;
else
F_99 ( V_1 ) ;
return 0 ;
} else {
if ( V_19 & V_81 ) {
int V_17 ;
V_17 = F_95 ( V_1 ) ;
if ( V_17 ) {
F_97 ( & V_58 -> V_80 ) ;
return 0 ;
}
} else
F_93 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_100 ( struct V_2 * V_3 , T_2 V_57 )
{
void * * V_82 ;
struct V_1 * V_1 ;
F_101 () ;
V_83:
V_1 = NULL ;
V_82 = F_102 ( & V_3 -> V_4 , V_57 ) ;
if ( V_82 ) {
V_1 = F_103 ( V_82 ) ;
if ( F_59 ( ! V_1 ) )
goto V_42;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) )
goto V_83;
goto V_42;
}
if ( ! F_106 ( V_1 ) )
goto V_83;
if ( F_59 ( V_1 != * V_82 ) ) {
F_22 ( V_1 ) ;
goto V_83;
}
}
V_42:
F_107 () ;
return V_1 ;
}
struct V_1 * F_108 ( struct V_2 * V_3 , T_2 V_57 )
{
struct V_1 * V_1 ;
V_83:
V_1 = F_100 ( V_3 , V_57 ) ;
if ( V_1 && ! F_104 ( V_1 ) ) {
F_109 ( V_1 ) ;
if ( F_59 ( V_1 -> V_3 != V_3 ) ) {
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_83;
}
F_49 ( V_1 -> V_5 != V_57 ) ;
}
return V_1 ;
}
struct V_1 * F_110 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_55 )
{
struct V_1 * V_1 ;
int V_49 ;
V_83:
V_1 = F_108 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_64 ( V_55 ) ;
if ( ! V_1 )
return NULL ;
V_49 = F_61 ( V_1 , V_3 , V_5 ,
( V_55 & V_59 ) ) ;
if ( F_59 ( V_49 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
if ( V_49 == - V_84 )
goto V_83;
}
}
return V_1 ;
}
unsigned F_111 ( struct V_2 * V_3 , T_2 V_23 ,
unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_85 V_86 ;
void * * V_87 ;
unsigned V_17 = 0 ;
if ( F_59 ( ! V_40 ) )
return 0 ;
F_101 () ;
V_88:
F_112 (slot, &mapping->page_tree, &iter, start) {
struct V_1 * V_1 ;
V_83:
V_1 = F_103 ( V_87 ) ;
if ( F_59 ( ! V_1 ) )
continue;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
F_113 ( V_86 . V_5 ) ;
goto V_88;
}
continue;
}
if ( ! F_106 ( V_1 ) )
goto V_83;
if ( F_59 ( V_1 != * V_87 ) ) {
F_22 ( V_1 ) ;
goto V_83;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
return V_17 ;
}
unsigned F_114 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_85 V_86 ;
void * * V_87 ;
unsigned int V_17 = 0 ;
if ( F_59 ( ! V_40 ) )
return 0 ;
F_101 () ;
V_88:
F_115 (slot, &mapping->page_tree, &iter, index) {
struct V_1 * V_1 ;
V_83:
V_1 = F_103 ( V_87 ) ;
if ( F_59 ( ! V_1 ) )
break;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
goto V_88;
}
break;
}
if ( ! F_106 ( V_1 ) )
goto V_83;
if ( F_59 ( V_1 != * V_87 ) ) {
F_22 ( V_1 ) ;
goto V_83;
}
if ( V_1 -> V_3 == NULL || V_1 -> V_5 != V_86 . V_5 ) {
F_22 ( V_1 ) ;
break;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
return V_17 ;
}
unsigned F_116 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_89 , unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_85 V_86 ;
void * * V_87 ;
unsigned V_17 = 0 ;
if ( F_59 ( ! V_40 ) )
return 0 ;
F_101 () ;
V_88:
F_117 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_1 * V_1 ;
V_83:
V_1 = F_103 ( V_87 ) ;
if ( F_59 ( ! V_1 ) )
continue;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
goto V_88;
}
F_92 () ;
}
if ( ! F_106 ( V_1 ) )
goto V_83;
if ( F_59 ( V_1 != * V_87 ) ) {
F_22 ( V_1 ) ;
goto V_83;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
if ( V_17 )
* V_5 = V_46 [ V_17 - 1 ] -> V_5 + 1 ;
return V_17 ;
}
struct V_1 *
F_118 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_100 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_119 ( V_1 ) )
return V_1 ;
F_22 ( V_1 ) ;
return NULL ;
}
V_1 = F_64 ( F_120 ( V_3 ) & ~ V_90 ) ;
if ( V_1 && F_61 ( V_1 , V_3 , V_5 , V_91 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_121 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
V_95 -> V_96 /= 4 ;
}
static void F_122 ( struct V_92 * V_93 , T_1 * V_97 ,
T_6 * V_98 )
{
struct V_2 * V_3 = V_93 -> V_99 ;
struct V_100 * V_100 = V_3 -> V_48 ;
struct V_94 * V_95 = & V_93 -> V_101 ;
T_2 V_5 ;
T_2 V_102 ;
T_2 V_103 ;
unsigned long V_57 ;
unsigned int V_104 ;
int error ;
V_5 = * V_97 >> V_37 ;
V_103 = V_95 -> V_105 >> V_37 ;
V_104 = V_95 -> V_105 & ( V_106 - 1 ) ;
V_102 = ( * V_97 + V_98 -> V_107 + V_106 - 1 ) >> V_37 ;
V_57 = * V_97 & ~ V_108 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_109 ;
T_1 V_110 ;
unsigned long V_111 , V_17 ;
F_43 () ;
V_112:
V_1 = F_100 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_123 ( V_3 ,
V_95 , V_93 ,
V_5 , V_102 - V_5 ) ;
V_1 = F_100 ( V_3 , V_5 ) ;
if ( F_59 ( V_1 == NULL ) )
goto V_113;
}
if ( F_124 ( V_1 ) ) {
F_125 ( V_3 ,
V_95 , V_93 , V_1 ,
V_5 , V_102 - V_5 ) ;
}
if ( ! F_3 ( V_1 ) ) {
if ( V_100 -> V_114 == V_37 ||
! V_3 -> V_12 -> V_115 )
goto V_116;
if ( ! F_119 ( V_1 ) )
goto V_116;
if ( ! V_1 -> V_3 )
goto V_117;
if ( ! V_3 -> V_12 -> V_115 ( V_1 ,
V_98 , V_57 ) )
goto V_117;
F_85 ( V_1 ) ;
}
V_118:
V_110 = F_45 ( V_100 ) ;
V_109 = ( V_110 - 1 ) >> V_37 ;
if ( F_59 ( ! V_110 || V_5 > V_109 ) ) {
F_22 ( V_1 ) ;
goto V_42;
}
V_111 = V_106 ;
if ( V_5 == V_109 ) {
V_111 = ( ( V_110 - 1 ) & ~ V_108 ) + 1 ;
if ( V_111 <= V_57 ) {
F_22 ( V_1 ) ;
goto V_42;
}
}
V_111 = V_111 - V_57 ;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
if ( V_103 != V_5 || V_57 != V_104 )
F_128 ( V_1 ) ;
V_103 = V_5 ;
V_17 = F_129 ( V_98 , V_1 , V_57 , V_111 ) ;
V_57 += V_17 ;
V_5 += V_57 >> V_37 ;
V_57 &= ~ V_108 ;
V_104 = V_57 ;
F_22 ( V_1 ) ;
if ( V_17 == V_111 && V_98 -> V_107 )
continue;
goto V_42;
V_116:
error = F_130 ( V_1 ) ;
if ( F_59 ( error ) )
goto V_119;
V_117:
if ( ! V_1 -> V_3 ) {
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
continue;
}
if ( F_3 ( V_1 ) ) {
F_85 ( V_1 ) ;
goto V_118;
}
V_120:
F_131 ( V_1 ) ;
error = V_3 -> V_12 -> V_120 ( V_93 , V_1 ) ;
if ( F_59 ( error ) ) {
if ( error == V_121 ) {
F_22 ( V_1 ) ;
goto V_112;
}
goto V_119;
}
if ( ! F_3 ( V_1 ) ) {
error = F_130 ( V_1 ) ;
if ( F_59 ( error ) )
goto V_119;
if ( ! F_3 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_112;
}
F_85 ( V_1 ) ;
F_121 ( V_93 , V_95 ) ;
error = - V_22 ;
goto V_119;
}
F_85 ( V_1 ) ;
}
goto V_118;
V_119:
V_98 -> error = error ;
F_22 ( V_1 ) ;
goto V_42;
V_113:
V_1 = F_132 ( V_3 ) ;
if ( ! V_1 ) {
V_98 -> error = - V_122 ;
goto V_42;
}
error = F_61 ( V_1 , V_3 ,
V_5 , V_123 ) ;
if ( error ) {
F_22 ( V_1 ) ;
if ( error == - V_84 )
goto V_112;
V_98 -> error = error ;
goto V_42;
}
goto V_120;
}
V_42:
V_95 -> V_105 = V_103 ;
V_95 -> V_105 <<= V_37 ;
V_95 -> V_105 |= V_104 ;
* V_97 = ( ( T_1 ) V_5 << V_37 ) + V_57 ;
F_133 ( V_93 ) ;
}
int F_129 ( T_6 * V_98 , struct V_1 * V_1 ,
unsigned long V_57 , unsigned long V_124 )
{
char * V_125 ;
unsigned long V_126 , V_107 = V_98 -> V_107 ;
if ( V_124 > V_107 )
V_124 = V_107 ;
if ( ! F_134 ( V_98 -> V_127 . V_128 , V_124 ) ) {
V_125 = F_135 ( V_1 ) ;
V_126 = F_136 ( V_98 -> V_127 . V_128 ,
V_125 + V_57 , V_124 ) ;
F_137 ( V_125 ) ;
if ( V_126 == 0 )
goto V_129;
}
V_125 = F_138 ( V_1 ) ;
V_126 = F_139 ( V_98 -> V_127 . V_128 , V_125 + V_57 , V_124 ) ;
F_140 ( V_1 ) ;
if ( V_126 ) {
V_124 -= V_126 ;
V_98 -> error = - V_130 ;
}
V_129:
V_98 -> V_107 = V_107 - V_124 ;
V_98 -> V_131 += V_124 ;
V_98 -> V_127 . V_128 += V_124 ;
return V_124 ;
}
int F_141 ( const struct V_132 * V_133 ,
unsigned long * V_134 , T_7 * V_107 , int V_135 )
{
unsigned long V_136 ;
T_7 V_137 = 0 ;
for ( V_136 = 0 ; V_136 < * V_134 ; V_136 ++ ) {
const struct V_132 * V_138 = & V_133 [ V_136 ] ;
V_137 += V_138 -> V_139 ;
if ( F_59 ( ( V_140 ) ( V_137 | V_138 -> V_139 ) < 0 ) )
return - V_141 ;
if ( F_142 ( V_135 , V_138 -> V_142 , V_138 -> V_139 ) )
continue;
if ( V_136 == 0 )
return - V_130 ;
* V_134 = V_136 ;
V_137 -= V_138 -> V_139 ;
break;
}
* V_107 = V_137 ;
return 0 ;
}
V_140
F_143 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_92 * V_93 = V_144 -> V_146 ;
V_140 V_147 ;
unsigned long V_136 = 0 ;
T_7 V_107 ;
T_1 * V_97 = & V_144 -> V_148 ;
V_107 = 0 ;
V_147 = F_141 ( V_133 , & V_134 , & V_107 , V_149 ) ;
if ( V_147 )
return V_147 ;
if ( V_93 -> V_150 & V_151 ) {
T_1 V_124 ;
struct V_2 * V_3 ;
struct V_100 * V_100 ;
V_3 = V_93 -> V_99 ;
V_100 = V_3 -> V_48 ;
if ( ! V_107 )
goto V_42;
V_124 = F_45 ( V_100 ) ;
if ( V_145 < V_124 ) {
V_147 = F_47 ( V_3 , V_145 ,
V_145 + F_144 ( V_133 , V_134 ) - 1 ) ;
if ( ! V_147 ) {
V_147 = V_3 -> V_12 -> V_152 ( V_153 , V_144 ,
V_133 , V_145 , V_134 ) ;
}
if ( V_147 > 0 ) {
* V_97 = V_145 + V_147 ;
V_107 -= V_147 ;
}
if ( V_147 < 0 || ! V_107 || * V_97 >= V_124 ) {
F_133 ( V_93 ) ;
goto V_42;
}
}
}
V_107 = V_147 ;
for ( V_136 = 0 ; V_136 < V_134 ; V_136 ++ ) {
T_6 V_98 ;
T_1 V_57 = 0 ;
if ( V_107 ) {
if ( V_107 > V_133 [ V_136 ] . V_139 ) {
V_107 -= V_133 [ V_136 ] . V_139 ;
continue;
}
V_57 = V_107 ;
V_107 = 0 ;
}
V_98 . V_131 = 0 ;
V_98 . V_127 . V_128 = V_133 [ V_136 ] . V_142 + V_57 ;
V_98 . V_107 = V_133 [ V_136 ] . V_139 - V_57 ;
if ( V_98 . V_107 == 0 )
continue;
V_98 . error = 0 ;
F_122 ( V_93 , V_97 , & V_98 ) ;
V_147 += V_98 . V_131 ;
if ( V_98 . error ) {
V_147 = V_147 ? : V_98 . error ;
break;
}
if ( V_98 . V_107 > 0 )
break;
}
V_42:
return V_147 ;
}
static int F_145 ( struct V_92 * V_92 , T_2 V_57 )
{
struct V_2 * V_3 = V_92 -> V_99 ;
struct V_1 * V_1 ;
int V_17 ;
do {
V_1 = F_132 ( V_3 ) ;
if ( ! V_1 )
return - V_122 ;
V_17 = F_61 ( V_1 , V_3 , V_57 , V_123 ) ;
if ( V_17 == 0 )
V_17 = V_3 -> V_12 -> V_120 ( V_92 , V_1 ) ;
else if ( V_17 == - V_84 )
V_17 = 0 ;
F_22 ( V_1 ) ;
} while ( V_17 == V_121 );
return V_17 ;
}
static void F_146 ( struct V_154 * V_155 ,
struct V_94 * V_95 ,
struct V_92 * V_92 ,
T_2 V_57 )
{
unsigned long V_96 ;
struct V_2 * V_3 = V_92 -> V_99 ;
if ( V_155 -> V_156 & V_157 )
return;
if ( ! V_95 -> V_96 )
return;
if ( V_155 -> V_156 & V_158 ) {
F_123 ( V_3 , V_95 , V_92 , V_57 ,
V_95 -> V_96 ) ;
return;
}
if ( V_95 -> V_159 < V_160 * 10 )
V_95 -> V_159 ++ ;
if ( V_95 -> V_159 > V_160 )
return;
V_96 = F_147 ( V_95 -> V_96 ) ;
V_95 -> V_23 = F_148 ( long , 0 , V_57 - V_96 / 2 ) ;
V_95 -> V_124 = V_96 ;
V_95 -> V_161 = V_96 / 4 ;
F_149 ( V_95 , V_3 , V_92 ) ;
}
static void F_150 ( struct V_154 * V_155 ,
struct V_94 * V_95 ,
struct V_92 * V_92 ,
struct V_1 * V_1 ,
T_2 V_57 )
{
struct V_2 * V_3 = V_92 -> V_99 ;
if ( V_155 -> V_156 & V_157 )
return;
if ( V_95 -> V_159 > 0 )
V_95 -> V_159 -- ;
if ( F_124 ( V_1 ) )
F_125 ( V_3 , V_95 , V_92 ,
V_1 , V_57 , V_95 -> V_96 ) ;
}
int F_151 ( struct V_154 * V_155 , struct V_162 * V_163 )
{
int error ;
struct V_92 * V_92 = V_155 -> V_164 ;
struct V_2 * V_3 = V_92 -> V_99 ;
struct V_94 * V_95 = & V_92 -> V_101 ;
struct V_100 * V_100 = V_3 -> V_48 ;
T_2 V_57 = V_163 -> V_165 ;
struct V_1 * V_1 ;
T_2 V_124 ;
int V_17 = 0 ;
V_124 = ( F_45 ( V_100 ) + V_106 - 1 ) >> V_37 ;
if ( V_57 >= V_124 )
return V_166 ;
V_1 = F_100 ( V_3 , V_57 ) ;
if ( F_152 ( V_1 ) && ! ( V_163 -> V_19 & V_167 ) ) {
F_150 ( V_155 , V_95 , V_92 , V_1 , V_57 ) ;
} else if ( ! V_1 ) {
F_146 ( V_155 , V_95 , V_92 , V_57 ) ;
F_153 ( V_168 ) ;
F_154 ( V_155 -> V_169 , V_168 ) ;
V_17 = V_170 ;
V_171:
V_1 = F_100 ( V_3 , V_57 ) ;
if ( ! V_1 )
goto V_113;
}
if ( ! F_155 ( V_1 , V_155 -> V_169 , V_163 -> V_19 ) ) {
F_22 ( V_1 ) ;
return V_17 | V_172 ;
}
if ( F_59 ( V_1 -> V_3 != V_3 ) ) {
F_85 ( V_1 ) ;
F_156 ( V_1 ) ;
goto V_171;
}
F_49 ( V_1 -> V_5 != V_57 ) ;
if ( F_59 ( ! F_3 ( V_1 ) ) )
goto V_173;
V_124 = ( F_45 ( V_100 ) + V_106 - 1 ) >> V_37 ;
if ( F_59 ( V_57 >= V_124 ) ) {
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
return V_166 ;
}
V_163 -> V_1 = V_1 ;
return V_17 | V_174 ;
V_113:
error = F_145 ( V_92 , V_57 ) ;
if ( error >= 0 )
goto V_171;
if ( error == - V_122 )
return V_175 ;
return V_166 ;
V_173:
F_131 ( V_1 ) ;
error = V_3 -> V_12 -> V_120 ( V_92 , V_1 ) ;
if ( ! error ) {
F_99 ( V_1 ) ;
if ( ! F_3 ( V_1 ) )
error = - V_22 ;
}
F_22 ( V_1 ) ;
if ( ! error || error == V_121 )
goto V_171;
F_121 ( V_92 , V_95 ) ;
return V_166 ;
}
int F_157 ( struct V_154 * V_155 , struct V_162 * V_163 )
{
struct V_1 * V_1 = V_163 -> V_1 ;
struct V_100 * V_100 = F_158 ( V_155 -> V_164 ) ;
int V_17 = V_174 ;
F_159 ( V_100 -> V_176 ) ;
F_160 ( V_155 -> V_164 ) ;
F_109 ( V_1 ) ;
if ( V_1 -> V_3 != V_100 -> V_177 ) {
F_85 ( V_1 ) ;
V_17 = V_178 ;
goto V_42;
}
F_161 ( V_1 ) ;
F_162 ( V_1 ) ;
V_42:
F_163 ( V_100 -> V_176 ) ;
return V_17 ;
}
int F_164 ( struct V_92 * V_92 , struct V_154 * V_155 )
{
struct V_2 * V_3 = V_92 -> V_99 ;
if ( ! V_3 -> V_12 -> V_120 )
return - V_179 ;
F_133 ( V_92 ) ;
V_155 -> V_180 = & V_181 ;
return 0 ;
}
int F_165 ( struct V_92 * V_92 , struct V_154 * V_155 )
{
if ( ( V_155 -> V_156 & V_182 ) && ( V_155 -> V_156 & V_183 ) )
return - V_141 ;
return F_164 ( V_92 , V_155 ) ;
}
int F_164 ( struct V_92 * V_92 , struct V_154 * V_155 )
{
return - V_184 ;
}
int F_165 ( struct V_92 * V_92 , struct V_154 * V_155 )
{
return - V_184 ;
}
static struct V_1 * F_166 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_49 ;
V_83:
V_1 = F_100 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_64 ( V_61 | V_186 ) ;
if ( ! V_1 )
return F_168 ( - V_122 ) ;
V_49 = F_61 ( V_1 , V_3 , V_5 , V_61 ) ;
if ( F_59 ( V_49 ) ) {
F_22 ( V_1 ) ;
if ( V_49 == - V_84 )
goto V_83;
return F_168 ( V_49 ) ;
}
V_49 = F_167 ( V_185 , V_1 ) ;
if ( V_49 < 0 ) {
F_22 ( V_1 ) ;
V_1 = F_168 ( V_49 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_169 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_49 ;
V_187:
V_1 = F_166 ( V_3 , V_5 , F_167 , V_185 , V_61 ) ;
if ( F_170 ( V_1 ) )
return V_1 ;
if ( F_3 ( V_1 ) )
goto V_42;
F_109 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_187;
}
if ( F_3 ( V_1 ) ) {
F_85 ( V_1 ) ;
goto V_42;
}
V_49 = F_167 ( V_185 , V_1 ) ;
if ( V_49 < 0 ) {
F_22 ( V_1 ) ;
return F_168 ( V_49 ) ;
}
V_42:
F_128 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_171 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_169 ( V_3 , V_5 , F_167 , V_185 , F_120 ( V_3 ) ) ;
}
static struct V_1 * F_172 ( struct V_1 * V_1 )
{
if ( ! F_170 ( V_1 ) ) {
F_99 ( V_1 ) ;
if ( ! F_3 ( V_1 ) ) {
F_22 ( V_1 ) ;
V_1 = F_168 ( - V_22 ) ;
}
}
return V_1 ;
}
struct V_1 * F_173 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_61 )
{
T_8 * F_167 = ( T_8 * ) V_3 -> V_12 -> V_120 ;
return F_172 ( F_169 ( V_3 , V_5 , F_167 , NULL , V_61 ) ) ;
}
struct V_1 * F_174 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_172 ( F_171 ( V_3 , V_5 , F_167 , V_185 ) ) ;
}
static T_7 F_175 ( char * V_188 ,
const struct V_132 * V_133 , T_7 V_189 , T_7 V_190 )
{
T_7 V_191 = 0 , V_126 = 0 ;
while ( V_190 ) {
char T_9 * V_128 = V_133 -> V_142 + V_189 ;
int V_192 = F_39 ( V_190 , V_133 -> V_139 - V_189 ) ;
V_189 = 0 ;
V_126 = F_176 ( V_188 , V_128 , V_192 ) ;
V_191 += V_192 ;
V_190 -= V_192 ;
V_188 += V_192 ;
V_133 ++ ;
if ( F_59 ( V_126 ) )
break;
}
return V_191 - V_126 ;
}
T_7 F_177 ( struct V_1 * V_1 ,
struct V_193 * V_45 , unsigned long V_57 , T_7 V_190 )
{
char * V_125 ;
T_7 V_191 ;
F_10 ( ! F_178 () ) ;
V_125 = F_135 ( V_1 ) ;
if ( F_152 ( V_45 -> V_134 == 1 ) ) {
int V_126 ;
char T_9 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_194 ;
V_126 = F_176 ( V_125 + V_57 , V_128 , V_190 ) ;
V_191 = V_190 - V_126 ;
} else {
V_191 = F_175 ( V_125 + V_57 ,
V_45 -> V_133 , V_45 -> V_194 , V_190 ) ;
}
F_137 ( V_125 ) ;
return V_191 ;
}
T_7 F_179 ( struct V_1 * V_1 ,
struct V_193 * V_45 , unsigned long V_57 , T_7 V_190 )
{
char * V_125 ;
T_7 V_191 ;
V_125 = F_138 ( V_1 ) ;
if ( F_152 ( V_45 -> V_134 == 1 ) ) {
int V_126 ;
char T_9 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_194 ;
V_126 = F_180 ( V_125 + V_57 , V_128 , V_190 ) ;
V_191 = V_190 - V_126 ;
} else {
V_191 = F_175 ( V_125 + V_57 ,
V_45 -> V_133 , V_45 -> V_194 , V_190 ) ;
}
F_140 ( V_1 ) ;
return V_191 ;
}
void F_181 ( struct V_193 * V_45 , T_7 V_190 )
{
F_10 ( V_45 -> V_107 < V_190 ) ;
if ( F_152 ( V_45 -> V_134 == 1 ) ) {
V_45 -> V_194 += V_190 ;
V_45 -> V_107 -= V_190 ;
} else {
const struct V_132 * V_133 = V_45 -> V_133 ;
T_7 V_189 = V_45 -> V_194 ;
unsigned long V_134 = V_45 -> V_134 ;
while ( V_190 || F_59 ( V_45 -> V_107 && ! V_133 -> V_139 ) ) {
int V_192 ;
V_192 = F_39 ( V_190 , V_133 -> V_139 - V_189 ) ;
F_10 ( ! V_45 -> V_107 || V_45 -> V_107 < V_192 ) ;
V_45 -> V_107 -= V_192 ;
V_190 -= V_192 ;
V_189 += V_192 ;
if ( V_133 -> V_139 == V_189 ) {
V_133 ++ ;
V_134 -- ;
V_189 = 0 ;
}
}
V_45 -> V_133 = V_133 ;
V_45 -> V_194 = V_189 ;
V_45 -> V_134 = V_134 ;
}
}
int F_182 ( struct V_193 * V_45 , T_7 V_190 )
{
char T_9 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_194 ;
V_190 = F_39 ( V_190 , V_45 -> V_133 -> V_139 - V_45 -> V_194 ) ;
return F_183 ( V_128 , V_190 ) ;
}
T_7 F_184 ( const struct V_193 * V_45 )
{
const struct V_132 * V_133 = V_45 -> V_133 ;
if ( V_45 -> V_134 == 1 )
return V_45 -> V_107 ;
else
return F_39 ( V_45 -> V_107 , V_133 -> V_139 - V_45 -> V_194 ) ;
}
inline int F_185 ( struct V_92 * V_92 , T_1 * V_145 , T_7 * V_107 , int V_195 )
{
struct V_100 * V_100 = V_92 -> V_99 -> V_48 ;
unsigned long V_196 = F_186 ( V_197 ) ;
if ( F_59 ( * V_145 < 0 ) )
return - V_141 ;
if ( ! V_195 ) {
if ( V_92 -> V_150 & V_198 )
* V_145 = F_45 ( V_100 ) ;
if ( V_196 != V_199 ) {
if ( * V_145 >= V_196 ) {
F_187 ( V_200 , V_15 , 0 ) ;
return - V_201 ;
}
if ( * V_107 > V_196 - ( F_188 ( V_196 ) ) * V_145 ) {
* V_107 = V_196 - ( F_188 ( V_196 ) ) * V_145 ;
}
}
}
if ( F_59 ( * V_145 + * V_107 > V_202 &&
! ( V_92 -> V_150 & V_203 ) ) ) {
if ( * V_145 >= V_202 ) {
return - V_201 ;
}
if ( * V_107 > V_202 - ( unsigned long ) * V_145 ) {
* V_107 = V_202 - ( unsigned long ) * V_145 ;
}
}
if ( F_152 ( ! V_195 ) ) {
if ( F_59 ( * V_145 >= V_100 -> V_176 -> V_204 ) ) {
if ( * V_107 || * V_145 > V_100 -> V_176 -> V_204 ) {
return - V_201 ;
}
}
if ( F_59 ( * V_145 + * V_107 > V_100 -> V_176 -> V_204 ) )
* V_107 = V_100 -> V_176 -> V_204 - * V_145 ;
} else {
#ifdef F_189
T_1 V_110 ;
if ( F_190 ( F_191 ( V_100 ) ) )
return - V_205 ;
V_110 = F_45 ( V_100 ) ;
if ( * V_145 >= V_110 ) {
if ( * V_107 || * V_145 > V_110 )
return - V_20 ;
}
if ( * V_145 + * V_107 > V_110 )
* V_107 = V_110 - * V_145 ;
#else
return - V_205 ;
#endif
}
return 0 ;
}
int F_192 ( struct V_92 * V_92 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_206 , unsigned V_19 ,
struct V_1 * * V_82 , void * * V_207 )
{
const struct V_208 * V_209 = V_3 -> V_12 ;
return V_209 -> V_210 ( V_92 , V_3 , V_145 , V_206 , V_19 ,
V_82 , V_207 ) ;
}
int F_193 ( struct V_92 * V_92 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_206 , unsigned V_191 ,
struct V_1 * V_1 , void * V_207 )
{
const struct V_208 * V_209 = V_3 -> V_12 ;
F_128 ( V_1 ) ;
return V_209 -> V_211 ( V_92 , V_3 , V_145 , V_206 , V_191 , V_1 , V_207 ) ;
}
V_140
F_194 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long * V_134 , T_1 V_145 , T_1 * V_97 ,
T_7 V_107 , T_7 V_212 )
{
struct V_92 * V_92 = V_144 -> V_146 ;
struct V_2 * V_3 = V_92 -> V_99 ;
struct V_100 * V_100 = V_3 -> V_48 ;
V_140 V_131 ;
T_7 V_213 ;
T_2 V_24 ;
if ( V_107 != V_212 )
* V_134 = F_195 ( (struct V_132 * ) V_133 , * V_134 , V_107 ) ;
V_213 = F_144 ( V_133 , * V_134 ) ;
V_24 = ( V_145 + V_213 - 1 ) >> V_37 ;
V_131 = F_47 ( V_3 , V_145 , V_145 + V_213 - 1 ) ;
if ( V_131 )
goto V_42;
if ( V_3 -> V_6 ) {
V_131 = F_196 ( V_3 ,
V_145 >> V_37 , V_24 ) ;
if ( V_131 ) {
if ( V_131 == - V_214 )
return 0 ;
goto V_42;
}
}
V_131 = V_3 -> V_12 -> V_152 ( V_215 , V_144 , V_133 , V_145 , * V_134 ) ;
if ( V_3 -> V_6 ) {
F_196 ( V_3 ,
V_145 >> V_37 , V_24 ) ;
}
if ( V_131 > 0 ) {
V_145 += V_131 ;
if ( V_145 > F_45 ( V_100 ) && ! F_197 ( V_100 -> V_216 ) ) {
F_198 ( V_100 , V_145 ) ;
F_199 ( V_100 ) ;
}
* V_97 = V_145 ;
}
V_42:
return V_131 ;
}
struct V_1 * F_200 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_19 )
{
int V_217 ;
T_3 V_55 ;
struct V_1 * V_1 ;
T_3 V_218 = 0 ;
V_55 = F_120 ( V_3 ) ;
if ( F_13 ( V_3 ) )
V_55 |= V_219 ;
if ( V_19 & V_220 )
V_218 = V_90 ;
V_83:
V_1 = F_108 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_221;
V_1 = F_64 ( V_55 & ~ V_218 ) ;
if ( ! V_1 )
return NULL ;
V_217 = F_61 ( V_1 , V_3 , V_5 ,
V_123 & ~ V_218 ) ;
if ( F_59 ( V_217 ) ) {
F_22 ( V_1 ) ;
if ( V_217 == - V_84 )
goto V_83;
return NULL ;
}
V_221:
F_162 ( V_1 ) ;
return V_1 ;
}
static V_140 F_201 ( struct V_92 * V_92 ,
struct V_193 * V_45 , T_1 V_145 )
{
struct V_2 * V_3 = V_92 -> V_99 ;
const struct V_208 * V_12 = V_3 -> V_12 ;
long V_217 = 0 ;
V_140 V_131 = 0 ;
unsigned int V_19 = 0 ;
if ( F_202 ( F_203 () , V_222 ) )
V_19 |= V_223 ;
do {
struct V_1 * V_1 ;
unsigned long V_57 ;
unsigned long V_190 ;
T_7 V_191 ;
void * V_207 ;
V_57 = ( V_145 & ( V_106 - 1 ) ) ;
V_190 = F_204 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_224:
if ( F_59 ( F_182 ( V_45 , V_190 ) ) ) {
V_217 = - V_130 ;
break;
}
V_217 = V_12 -> V_210 ( V_92 , V_3 , V_145 , V_190 , V_19 ,
& V_1 , & V_207 ) ;
if ( F_59 ( V_217 ) )
break;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
F_205 () ;
V_191 = F_177 ( V_1 , V_45 , V_57 , V_190 ) ;
F_206 () ;
F_127 ( V_1 ) ;
F_128 ( V_1 ) ;
V_217 = V_12 -> V_211 ( V_92 , V_3 , V_145 , V_190 , V_191 ,
V_1 , V_207 ) ;
if ( F_59 ( V_217 < 0 ) )
break;
V_191 = V_217 ;
F_43 () ;
F_181 ( V_45 , V_191 ) ;
if ( F_59 ( V_191 == 0 ) ) {
V_190 = F_204 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_224;
}
V_145 += V_191 ;
V_131 += V_191 ;
F_207 ( V_3 ) ;
if ( F_26 ( V_15 ) ) {
V_217 = - V_16 ;
break;
}
} while ( F_208 ( V_45 ) );
return V_131 ? V_131 : V_217 ;
}
V_140
F_209 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 , T_1 * V_97 ,
T_7 V_107 , V_140 V_131 )
{
struct V_92 * V_92 = V_144 -> V_146 ;
V_140 V_217 ;
struct V_193 V_45 ;
F_210 ( & V_45 , V_133 , V_134 , V_107 , V_131 ) ;
V_217 = F_201 ( V_92 , & V_45 , V_145 ) ;
if ( F_152 ( V_217 >= 0 ) ) {
V_131 += V_217 ;
* V_97 = V_145 + V_217 ;
}
return V_131 ? V_131 : V_217 ;
}
V_140 F_211 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 * V_97 )
{
struct V_92 * V_92 = V_144 -> V_146 ;
struct V_2 * V_3 = V_92 -> V_99 ;
T_7 V_212 ;
T_7 V_107 ;
struct V_100 * V_100 = V_3 -> V_48 ;
T_1 V_145 ;
V_140 V_131 ;
V_140 V_49 ;
V_212 = 0 ;
V_49 = F_141 ( V_133 , & V_134 , & V_212 , V_225 ) ;
if ( V_49 )
return V_49 ;
V_107 = V_212 ;
V_145 = * V_97 ;
V_15 -> V_10 = V_3 -> V_10 ;
V_131 = 0 ;
V_49 = F_185 ( V_92 , & V_145 , & V_107 , F_197 ( V_100 -> V_216 ) ) ;
if ( V_49 )
goto V_42;
if ( V_107 == 0 )
goto V_42;
V_49 = F_212 ( V_92 ) ;
if ( V_49 )
goto V_42;
V_49 = F_160 ( V_92 ) ;
if ( V_49 )
goto V_42;
if ( F_59 ( V_92 -> V_150 & V_151 ) ) {
T_1 V_226 ;
V_140 V_227 ;
V_131 = F_194 ( V_144 , V_133 , & V_134 , V_145 ,
V_97 , V_107 , V_212 ) ;
if ( V_131 < 0 || V_131 == V_107 )
goto V_42;
V_145 += V_131 ;
V_107 -= V_131 ;
V_227 = F_209 ( V_144 , V_133 ,
V_134 , V_145 , V_97 , V_107 ,
V_131 ) ;
if ( V_227 < 0 ) {
V_49 = V_227 ;
goto V_42;
}
V_226 = V_145 + V_227 - V_131 - 1 ;
V_49 = F_47 ( V_92 -> V_99 , V_145 , V_226 ) ;
if ( V_49 == 0 ) {
V_131 = V_227 ;
F_213 ( V_3 ,
V_145 >> V_37 ,
V_226 >> V_37 ) ;
} else {
}
} else {
V_131 = F_209 ( V_144 , V_133 , V_134 ,
V_145 , V_97 , V_107 , V_131 ) ;
}
V_42:
V_15 -> V_10 = NULL ;
return V_131 ? V_131 : V_49 ;
}
V_140 F_214 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_92 * V_92 = V_144 -> V_146 ;
struct V_100 * V_100 = V_92 -> V_99 -> V_48 ;
V_140 V_17 ;
F_10 ( V_144 -> V_148 != V_145 ) ;
F_215 ( & V_100 -> V_228 ) ;
V_17 = F_211 ( V_144 , V_133 , V_134 , & V_144 -> V_148 ) ;
F_216 ( & V_100 -> V_228 ) ;
if ( V_17 > 0 ) {
V_140 V_49 ;
V_49 = F_217 ( V_92 , V_145 , V_17 ) ;
if ( V_49 < 0 && V_17 > 0 )
V_17 = V_49 ;
}
return V_17 ;
}
int F_218 ( struct V_1 * V_1 , T_3 V_55 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_10 ( ! F_18 ( V_1 ) ) ;
if ( F_219 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_229 )
return V_3 -> V_12 -> V_229 ( V_1 , V_55 ) ;
return F_220 ( V_1 ) ;
}
