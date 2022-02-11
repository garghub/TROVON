void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
if ( F_2 ( V_1 ) && F_3 ( V_1 ) )
F_4 ( V_1 ) ;
else
F_5 ( V_3 , V_1 ) ;
F_6 ( & V_3 -> V_4 , V_1 -> V_5 ) ;
V_1 -> V_3 = NULL ;
V_3 -> V_6 -- ;
F_7 ( V_1 , V_7 ) ;
if ( F_8 ( V_1 ) )
F_7 ( V_1 , V_8 ) ;
F_9 ( F_10 ( V_1 ) ) ;
if ( F_11 ( V_1 ) && F_12 ( V_3 ) ) {
F_13 ( V_1 , V_9 ) ;
F_14 ( V_3 -> V_10 , V_11 ) ;
}
}
void F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
void (* F_16)( struct V_1 * );
F_9 ( ! F_17 ( V_1 ) ) ;
F_16 = V_3 -> V_12 -> F_16 ;
F_18 ( & V_3 -> V_13 ) ;
F_1 ( V_1 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_20 ( V_1 ) ;
if ( F_16 )
F_16 ( V_1 ) ;
F_21 ( V_1 ) ;
}
static int F_22 ( void * V_14 )
{
F_23 () ;
return 0 ;
}
static int F_24 ( void * V_14 )
{
F_22 ( V_14 ) ;
return F_25 ( V_15 ) ? - V_16 : 0 ;
}
int F_26 ( struct V_2 * V_3 , T_1 V_17 ,
T_1 V_18 , int V_19 )
{
int V_20 ;
struct V_21 V_22 = {
. V_19 = V_19 ,
. V_23 = V_24 ,
. V_25 = V_17 ,
. V_26 = V_18 ,
} ;
if ( ! F_27 ( V_3 ) )
return 0 ;
V_20 = F_28 ( V_3 , & V_22 ) ;
return V_20 ;
}
static inline int F_29 ( struct V_2 * V_3 ,
int V_19 )
{
return F_26 ( V_3 , 0 , V_27 , V_19 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
return F_29 ( V_3 , V_28 ) ;
}
int F_31 ( struct V_2 * V_3 , T_1 V_17 ,
T_1 V_18 )
{
return F_26 ( V_3 , V_17 , V_18 , V_28 ) ;
}
int F_32 ( struct V_2 * V_3 )
{
return F_29 ( V_3 , V_29 ) ;
}
int F_33 ( struct V_2 * V_3 , T_1 V_30 ,
T_1 V_31 )
{
T_2 V_5 = V_30 >> V_32 ;
T_2 V_18 = V_31 >> V_32 ;
struct V_33 V_34 ;
int V_35 ;
int V_20 = 0 ;
if ( V_31 < V_30 )
return 0 ;
F_34 ( & V_34 , 0 ) ;
while ( ( V_5 <= V_18 ) &&
( V_35 = F_35 ( & V_34 , V_3 , & V_5 ,
V_36 ,
F_36 ( V_18 - V_5 , ( T_2 ) V_37 - 1 ) + 1 ) ) != 0 ) {
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
struct V_1 * V_1 = V_34 . V_39 [ V_38 ] ;
if ( V_1 -> V_5 > V_18 )
continue;
F_37 ( V_1 ) ;
if ( F_38 ( V_1 ) )
V_20 = - V_40 ;
}
F_39 ( & V_34 ) ;
F_40 () ;
}
if ( F_41 ( V_41 , & V_3 -> V_42 ) )
V_20 = - V_43 ;
if ( F_41 ( V_44 , & V_3 -> V_42 ) )
V_20 = - V_40 ;
return V_20 ;
}
int F_42 ( struct V_2 * V_3 )
{
T_1 V_45 = F_43 ( V_3 -> V_46 ) ;
if ( V_45 == 0 )
return 0 ;
return F_33 ( V_3 , 0 , V_45 - 1 ) ;
}
int F_44 ( struct V_2 * V_3 )
{
int V_47 = 0 ;
if ( V_3 -> V_6 ) {
V_47 = F_30 ( V_3 ) ;
if ( V_47 != - V_40 ) {
int V_48 = F_42 ( V_3 ) ;
if ( ! V_47 )
V_47 = V_48 ;
}
}
return V_47 ;
}
int F_45 ( struct V_2 * V_3 ,
T_1 V_49 , T_1 V_50 )
{
int V_47 = 0 ;
if ( V_3 -> V_6 ) {
V_47 = F_26 ( V_3 , V_49 , V_50 ,
V_28 ) ;
if ( V_47 != - V_40 ) {
int V_48 = F_33 ( V_3 ,
V_49 , V_50 ) ;
if ( ! V_47 )
V_47 = V_48 ;
}
}
return V_47 ;
}
int F_46 ( struct V_1 * V_51 , struct V_1 * V_52 , T_3 V_53 )
{
int error ;
F_47 ( ! F_17 ( V_51 ) ) ;
F_47 ( ! F_17 ( V_52 ) ) ;
F_47 ( V_52 -> V_3 ) ;
error = F_48 ( V_53 & ~ V_54 ) ;
if ( ! error ) {
struct V_2 * V_3 = V_51 -> V_3 ;
void (* F_16)( struct V_1 * );
T_2 V_55 = V_51 -> V_5 ;
F_16 = V_3 -> V_12 -> F_16 ;
F_49 ( V_52 ) ;
V_52 -> V_3 = V_3 ;
V_52 -> V_5 = V_55 ;
F_18 ( & V_3 -> V_13 ) ;
F_1 ( V_51 ) ;
error = F_50 ( & V_3 -> V_4 , V_55 , V_52 ) ;
F_9 ( error ) ;
V_3 -> V_6 ++ ;
F_51 ( V_52 , V_7 ) ;
if ( F_8 ( V_52 ) )
F_51 ( V_52 , V_8 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_52 ( V_51 , V_52 ) ;
F_53 () ;
if ( F_16 )
F_16 ( V_51 ) ;
F_21 ( V_51 ) ;
}
return error ;
}
int F_54 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_55 , T_3 V_53 )
{
int error ;
F_47 ( ! F_17 ( V_1 ) ) ;
F_47 ( F_8 ( V_1 ) ) ;
error = F_55 ( V_1 , V_15 -> V_56 ,
V_53 & V_57 ) ;
if ( error )
goto V_58;
error = F_48 ( V_53 & ~ V_54 ) ;
if ( error == 0 ) {
F_49 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_55 ;
F_18 ( & V_3 -> V_13 ) ;
error = F_50 ( & V_3 -> V_4 , V_55 , V_1 ) ;
if ( F_56 ( ! error ) ) {
V_3 -> V_6 ++ ;
F_51 ( V_1 , V_7 ) ;
F_19 ( & V_3 -> V_13 ) ;
} else {
V_1 -> V_3 = NULL ;
F_19 ( & V_3 -> V_13 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
}
F_53 () ;
} else
F_20 ( V_1 ) ;
V_58:
return error ;
}
int F_57 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_55 , T_3 V_53 )
{
int V_20 ;
V_20 = F_58 ( V_1 , V_3 , V_55 , V_53 ) ;
if ( V_20 == 0 )
F_59 ( V_1 ) ;
return V_20 ;
}
struct V_1 * F_60 ( T_3 V_59 )
{
int V_60 ;
struct V_1 * V_1 ;
if ( F_61 () ) {
unsigned int V_61 ;
do {
V_61 = F_62 () ;
V_60 = F_63 () ;
V_1 = F_64 ( V_60 , V_59 , 0 ) ;
} while ( ! F_65 ( V_61 ) && ! V_1 );
return V_1 ;
}
return F_66 ( V_59 , 0 ) ;
}
static T_4 * F_67 ( struct V_1 * V_1 )
{
const struct V_62 * V_62 = F_68 ( V_1 ) ;
return & V_62 -> V_63 [ F_69 ( V_1 , V_62 -> V_64 ) ] ;
}
static inline void F_70 ( struct V_1 * V_1 , int V_65 )
{
F_71 ( F_67 ( V_1 ) , & V_1 -> V_42 , V_65 ) ;
}
void F_72 ( struct V_1 * V_1 , int V_66 )
{
F_73 ( V_67 , & V_1 -> V_42 , V_66 ) ;
if ( F_74 ( V_66 , & V_1 -> V_42 ) )
F_75 ( F_67 ( V_1 ) , & V_67 , F_22 ,
V_68 ) ;
}
int F_76 ( struct V_1 * V_1 , int V_66 )
{
F_73 ( V_67 , & V_1 -> V_42 , V_66 ) ;
if ( ! F_74 ( V_66 , & V_1 -> V_42 ) )
return 0 ;
return F_75 ( F_67 ( V_1 ) , & V_67 ,
F_24 , V_69 ) ;
}
void F_77 ( struct V_1 * V_1 , T_5 * V_70 )
{
T_4 * V_71 = F_67 ( V_1 ) ;
unsigned long V_42 ;
F_78 ( & V_71 -> V_72 , V_42 ) ;
F_79 ( V_71 , V_70 ) ;
F_80 ( & V_71 -> V_72 , V_42 ) ;
}
void F_81 ( struct V_1 * V_1 )
{
F_47 ( ! F_17 ( V_1 ) ) ;
F_82 ( V_73 , & V_1 -> V_42 ) ;
F_83 () ;
F_70 ( V_1 , V_73 ) ;
}
void F_84 ( struct V_1 * V_1 )
{
if ( F_85 ( V_1 ) )
F_86 ( V_1 ) ;
if ( ! F_87 ( V_1 ) )
F_88 () ;
F_83 () ;
F_70 ( V_1 , V_74 ) ;
}
void F_89 ( struct V_1 * V_1 )
{
F_73 ( V_67 , & V_1 -> V_42 , V_73 ) ;
F_90 ( F_67 ( V_1 ) , & V_67 , F_22 ,
V_68 ) ;
}
int F_91 ( struct V_1 * V_1 )
{
F_73 ( V_67 , & V_1 -> V_42 , V_73 ) ;
return F_90 ( F_67 ( V_1 ) , & V_67 ,
F_24 , V_69 ) ;
}
int F_92 ( struct V_1 * V_1 , struct V_75 * V_56 ,
unsigned int V_42 )
{
if ( V_42 & V_76 ) {
if ( V_42 & V_77 )
return 0 ;
F_93 ( & V_56 -> V_78 ) ;
if ( V_42 & V_79 )
F_94 ( V_1 ) ;
else
F_95 ( V_1 ) ;
return 0 ;
} else {
if ( V_42 & V_79 ) {
int V_20 ;
V_20 = F_91 ( V_1 ) ;
if ( V_20 ) {
F_93 ( & V_56 -> V_78 ) ;
return 0 ;
}
} else
F_89 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_96 ( struct V_2 * V_3 , T_2 V_55 )
{
void * * V_80 ;
struct V_1 * V_1 ;
F_97 () ;
V_81:
V_1 = NULL ;
V_80 = F_98 ( & V_3 -> V_4 , V_55 ) ;
if ( V_80 ) {
V_1 = F_99 ( V_80 ) ;
if ( F_100 ( ! V_1 ) )
goto V_58;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) )
goto V_81;
goto V_58;
}
if ( ! F_103 ( V_1 ) )
goto V_81;
if ( F_100 ( V_1 != * V_80 ) ) {
F_21 ( V_1 ) ;
goto V_81;
}
}
V_58:
F_104 () ;
return V_1 ;
}
struct V_1 * F_105 ( struct V_2 * V_3 , T_2 V_55 )
{
struct V_1 * V_1 ;
V_81:
V_1 = F_96 ( V_3 , V_55 ) ;
if ( V_1 && ! F_101 ( V_1 ) ) {
F_106 ( V_1 ) ;
if ( F_100 ( V_1 -> V_3 != V_3 ) ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_81;
}
F_47 ( V_1 -> V_5 != V_55 ) ;
}
return V_1 ;
}
struct V_1 * F_107 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_53 )
{
struct V_1 * V_1 ;
int V_47 ;
V_81:
V_1 = F_105 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_60 ( V_53 ) ;
if ( ! V_1 )
return NULL ;
V_47 = F_57 ( V_1 , V_3 , V_5 ,
( V_53 & V_57 ) ) ;
if ( F_100 ( V_47 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
if ( V_47 == - V_82 )
goto V_81;
}
}
return V_1 ;
}
unsigned F_108 ( struct V_2 * V_3 , T_2 V_17 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
struct V_83 V_84 ;
void * * V_85 ;
unsigned V_20 = 0 ;
if ( F_100 ( ! V_35 ) )
return 0 ;
F_97 () ;
V_86:
F_109 (slot, &mapping->page_tree, &iter, start) {
struct V_1 * V_1 ;
V_81:
V_1 = F_99 ( V_85 ) ;
if ( F_100 ( ! V_1 ) )
continue;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
F_110 ( V_84 . V_5 ) ;
goto V_86;
}
continue;
}
if ( ! F_103 ( V_1 ) )
goto V_81;
if ( F_100 ( V_1 != * V_85 ) ) {
F_21 ( V_1 ) ;
goto V_81;
}
V_39 [ V_20 ] = V_1 ;
if ( ++ V_20 == V_35 )
break;
}
F_104 () ;
return V_20 ;
}
unsigned F_111 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
struct V_83 V_84 ;
void * * V_85 ;
unsigned int V_20 = 0 ;
if ( F_100 ( ! V_35 ) )
return 0 ;
F_97 () ;
V_86:
F_112 (slot, &mapping->page_tree, &iter, index) {
struct V_1 * V_1 ;
V_81:
V_1 = F_99 ( V_85 ) ;
if ( F_100 ( ! V_1 ) )
break;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
goto V_86;
}
break;
}
if ( ! F_103 ( V_1 ) )
goto V_81;
if ( F_100 ( V_1 != * V_85 ) ) {
F_21 ( V_1 ) ;
goto V_81;
}
if ( V_1 -> V_3 == NULL || V_1 -> V_5 != V_84 . V_5 ) {
F_21 ( V_1 ) ;
break;
}
V_39 [ V_20 ] = V_1 ;
if ( ++ V_20 == V_35 )
break;
}
F_104 () ;
return V_20 ;
}
unsigned F_113 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_87 , unsigned int V_35 , struct V_1 * * V_39 )
{
struct V_83 V_84 ;
void * * V_85 ;
unsigned V_20 = 0 ;
if ( F_100 ( ! V_35 ) )
return 0 ;
F_97 () ;
V_86:
F_114 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_1 * V_1 ;
V_81:
V_1 = F_99 ( V_85 ) ;
if ( F_100 ( ! V_1 ) )
continue;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
goto V_86;
}
F_88 () ;
}
if ( ! F_103 ( V_1 ) )
goto V_81;
if ( F_100 ( V_1 != * V_85 ) ) {
F_21 ( V_1 ) ;
goto V_81;
}
V_39 [ V_20 ] = V_1 ;
if ( ++ V_20 == V_35 )
break;
}
F_104 () ;
if ( V_20 )
* V_5 = V_39 [ V_20 - 1 ] -> V_5 + 1 ;
return V_20 ;
}
struct V_1 *
F_115 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_96 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_116 ( V_1 ) )
return V_1 ;
F_21 ( V_1 ) ;
return NULL ;
}
V_1 = F_60 ( F_117 ( V_3 ) & ~ V_88 ) ;
if ( V_1 && F_57 ( V_1 , V_3 , V_5 , V_89 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_118 ( struct V_90 * V_91 ,
struct V_92 * V_93 )
{
V_93 -> V_94 /= 4 ;
}
static void F_119 ( struct V_90 * V_91 , T_1 * V_95 ,
T_6 * V_96 , T_7 V_97 )
{
struct V_2 * V_3 = V_91 -> V_98 ;
struct V_99 * V_99 = V_3 -> V_46 ;
struct V_92 * V_93 = & V_91 -> V_100 ;
T_2 V_5 ;
T_2 V_101 ;
T_2 V_102 ;
unsigned long V_55 ;
unsigned int V_103 ;
int error ;
V_5 = * V_95 >> V_32 ;
V_102 = V_93 -> V_104 >> V_32 ;
V_103 = V_93 -> V_104 & ( V_105 - 1 ) ;
V_101 = ( * V_95 + V_96 -> V_106 + V_105 - 1 ) >> V_32 ;
V_55 = * V_95 & ~ V_107 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_108 ;
T_1 V_109 ;
unsigned long V_110 , V_20 ;
F_40 () ;
V_111:
V_1 = F_96 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_120 ( V_3 ,
V_93 , V_91 ,
V_5 , V_101 - V_5 ) ;
V_1 = F_96 ( V_3 , V_5 ) ;
if ( F_100 ( V_1 == NULL ) )
goto V_112;
}
if ( F_121 ( V_1 ) ) {
F_122 ( V_3 ,
V_93 , V_91 , V_1 ,
V_5 , V_101 - V_5 ) ;
}
if ( ! F_2 ( V_1 ) ) {
if ( V_99 -> V_113 == V_32 ||
! V_3 -> V_12 -> V_114 )
goto V_115;
if ( ! F_116 ( V_1 ) )
goto V_115;
if ( ! V_1 -> V_3 )
goto V_116;
if ( ! V_3 -> V_12 -> V_114 ( V_1 ,
V_96 , V_55 ) )
goto V_116;
F_81 ( V_1 ) ;
}
V_117:
V_109 = F_43 ( V_99 ) ;
V_108 = ( V_109 - 1 ) >> V_32 ;
if ( F_100 ( ! V_109 || V_5 > V_108 ) ) {
F_21 ( V_1 ) ;
goto V_58;
}
V_110 = V_105 ;
if ( V_5 == V_108 ) {
V_110 = ( ( V_109 - 1 ) & ~ V_107 ) + 1 ;
if ( V_110 <= V_55 ) {
F_21 ( V_1 ) ;
goto V_58;
}
}
V_110 = V_110 - V_55 ;
if ( F_123 ( V_3 ) )
F_124 ( V_1 ) ;
if ( V_102 != V_5 || V_55 != V_103 )
F_125 ( V_1 ) ;
V_102 = V_5 ;
V_20 = V_97 ( V_96 , V_1 , V_55 , V_110 ) ;
V_55 += V_20 ;
V_5 += V_55 >> V_32 ;
V_55 &= ~ V_107 ;
V_103 = V_55 ;
F_21 ( V_1 ) ;
if ( V_20 == V_110 && V_96 -> V_106 )
continue;
goto V_58;
V_115:
error = F_126 ( V_1 ) ;
if ( F_100 ( error ) )
goto V_118;
V_116:
if ( ! V_1 -> V_3 ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
continue;
}
if ( F_2 ( V_1 ) ) {
F_81 ( V_1 ) ;
goto V_117;
}
V_119:
F_127 ( V_1 ) ;
error = V_3 -> V_12 -> V_119 ( V_91 , V_1 ) ;
if ( F_100 ( error ) ) {
if ( error == V_120 ) {
F_21 ( V_1 ) ;
goto V_111;
}
goto V_118;
}
if ( ! F_2 ( V_1 ) ) {
error = F_126 ( V_1 ) ;
if ( F_100 ( error ) )
goto V_118;
if ( ! F_2 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_111;
}
F_81 ( V_1 ) ;
F_118 ( V_91 , V_93 ) ;
error = - V_40 ;
goto V_118;
}
F_81 ( V_1 ) ;
}
goto V_117;
V_118:
V_96 -> error = error ;
F_21 ( V_1 ) ;
goto V_58;
V_112:
V_1 = F_128 ( V_3 ) ;
if ( ! V_1 ) {
V_96 -> error = - V_121 ;
goto V_58;
}
error = F_57 ( V_1 , V_3 ,
V_5 , V_122 ) ;
if ( error ) {
F_21 ( V_1 ) ;
if ( error == - V_82 )
goto V_111;
V_96 -> error = error ;
goto V_58;
}
goto V_119;
}
V_58:
V_93 -> V_104 = V_102 ;
V_93 -> V_104 <<= V_32 ;
V_93 -> V_104 |= V_103 ;
* V_95 = ( ( T_1 ) V_5 << V_32 ) + V_55 ;
F_129 ( V_91 ) ;
}
int F_130 ( T_6 * V_96 , struct V_1 * V_1 ,
unsigned long V_55 , unsigned long V_123 )
{
char * V_124 ;
unsigned long V_125 , V_106 = V_96 -> V_106 ;
if ( V_123 > V_106 )
V_123 = V_106 ;
if ( ! F_131 ( V_96 -> V_126 . V_127 , V_123 ) ) {
V_124 = F_132 ( V_1 ) ;
V_125 = F_133 ( V_96 -> V_126 . V_127 ,
V_124 + V_55 , V_123 ) ;
F_134 ( V_124 ) ;
if ( V_125 == 0 )
goto V_128;
}
V_124 = F_135 ( V_1 ) ;
V_125 = F_136 ( V_96 -> V_126 . V_127 , V_124 + V_55 , V_123 ) ;
F_137 ( V_1 ) ;
if ( V_125 ) {
V_123 -= V_125 ;
V_96 -> error = - V_129 ;
}
V_128:
V_96 -> V_106 = V_106 - V_123 ;
V_96 -> V_130 += V_123 ;
V_96 -> V_126 . V_127 += V_123 ;
return V_123 ;
}
int F_138 ( const struct V_131 * V_132 ,
unsigned long * V_133 , T_8 * V_106 , int V_134 )
{
unsigned long V_135 ;
T_8 V_136 = 0 ;
for ( V_135 = 0 ; V_135 < * V_133 ; V_135 ++ ) {
const struct V_131 * V_137 = & V_132 [ V_135 ] ;
V_136 += V_137 -> V_138 ;
if ( F_100 ( ( V_139 ) ( V_136 | V_137 -> V_138 ) < 0 ) )
return - V_140 ;
if ( F_139 ( V_134 , V_137 -> V_141 , V_137 -> V_138 ) )
continue;
if ( V_135 == 0 )
return - V_129 ;
* V_133 = V_135 ;
V_136 -= V_137 -> V_138 ;
break;
}
* V_106 = V_136 ;
return 0 ;
}
V_139
F_140 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 )
{
struct V_90 * V_91 = V_143 -> V_145 ;
V_139 V_146 ;
unsigned long V_135 = 0 ;
T_8 V_106 ;
T_1 * V_95 = & V_143 -> V_147 ;
V_106 = 0 ;
V_146 = F_138 ( V_132 , & V_133 , & V_106 , V_148 ) ;
if ( V_146 )
return V_146 ;
if ( V_91 -> V_149 & V_150 ) {
T_1 V_123 ;
struct V_2 * V_3 ;
struct V_99 * V_99 ;
V_3 = V_91 -> V_98 ;
V_99 = V_3 -> V_46 ;
if ( ! V_106 )
goto V_58;
V_123 = F_43 ( V_99 ) ;
if ( V_144 < V_123 ) {
V_146 = F_45 ( V_3 , V_144 ,
V_144 + F_141 ( V_132 , V_133 ) - 1 ) ;
if ( ! V_146 ) {
V_146 = V_3 -> V_12 -> V_151 ( V_152 , V_143 ,
V_132 , V_144 , V_133 ) ;
}
if ( V_146 > 0 ) {
* V_95 = V_144 + V_146 ;
V_106 -= V_146 ;
}
if ( V_146 < 0 || ! V_106 || * V_95 >= V_123 ) {
F_129 ( V_91 ) ;
goto V_58;
}
}
}
V_106 = V_146 ;
for ( V_135 = 0 ; V_135 < V_133 ; V_135 ++ ) {
T_6 V_96 ;
T_1 V_55 = 0 ;
if ( V_106 ) {
if ( V_106 > V_132 [ V_135 ] . V_138 ) {
V_106 -= V_132 [ V_135 ] . V_138 ;
continue;
}
V_55 = V_106 ;
V_106 = 0 ;
}
V_96 . V_130 = 0 ;
V_96 . V_126 . V_127 = V_132 [ V_135 ] . V_141 + V_55 ;
V_96 . V_106 = V_132 [ V_135 ] . V_138 - V_55 ;
if ( V_96 . V_106 == 0 )
continue;
V_96 . error = 0 ;
F_119 ( V_91 , V_95 , & V_96 , F_130 ) ;
V_146 += V_96 . V_130 ;
if ( V_96 . error ) {
V_146 = V_146 ? : V_96 . error ;
break;
}
if ( V_96 . V_106 > 0 )
break;
}
V_58:
return V_146 ;
}
static int F_142 ( struct V_90 * V_90 , T_2 V_55 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_1 * V_1 ;
int V_20 ;
do {
V_1 = F_128 ( V_3 ) ;
if ( ! V_1 )
return - V_121 ;
V_20 = F_57 ( V_1 , V_3 , V_55 , V_122 ) ;
if ( V_20 == 0 )
V_20 = V_3 -> V_12 -> V_119 ( V_90 , V_1 ) ;
else if ( V_20 == - V_82 )
V_20 = 0 ;
F_21 ( V_1 ) ;
} while ( V_20 == V_120 );
return V_20 ;
}
static void F_143 ( struct V_153 * V_154 ,
struct V_92 * V_93 ,
struct V_90 * V_90 ,
T_2 V_55 )
{
unsigned long V_94 ;
struct V_2 * V_3 = V_90 -> V_98 ;
if ( F_144 ( V_154 ) )
return;
if ( ! V_93 -> V_94 )
return;
if ( F_145 ( V_154 ) ) {
F_120 ( V_3 , V_93 , V_90 , V_55 ,
V_93 -> V_94 ) ;
return;
}
if ( V_93 -> V_155 < V_156 * 10 )
V_93 -> V_155 ++ ;
if ( V_93 -> V_155 > V_156 )
return;
V_94 = F_146 ( V_93 -> V_94 ) ;
V_93 -> V_17 = F_147 ( long , 0 , V_55 - V_94 / 2 ) ;
V_93 -> V_123 = V_94 ;
V_93 -> V_157 = V_94 / 4 ;
F_148 ( V_93 , V_3 , V_90 ) ;
}
static void F_149 ( struct V_153 * V_154 ,
struct V_92 * V_93 ,
struct V_90 * V_90 ,
struct V_1 * V_1 ,
T_2 V_55 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
if ( F_144 ( V_154 ) )
return;
if ( V_93 -> V_155 > 0 )
V_93 -> V_155 -- ;
if ( F_121 ( V_1 ) )
F_122 ( V_3 , V_93 , V_90 ,
V_1 , V_55 , V_93 -> V_94 ) ;
}
int F_150 ( struct V_153 * V_154 , struct V_158 * V_159 )
{
int error ;
struct V_90 * V_90 = V_154 -> V_160 ;
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_92 * V_93 = & V_90 -> V_100 ;
struct V_99 * V_99 = V_3 -> V_46 ;
T_2 V_55 = V_159 -> V_161 ;
struct V_1 * V_1 ;
T_2 V_123 ;
int V_20 = 0 ;
V_123 = ( F_43 ( V_99 ) + V_105 - 1 ) >> V_32 ;
if ( V_55 >= V_123 )
return V_162 ;
V_1 = F_96 ( V_3 , V_55 ) ;
if ( F_56 ( V_1 ) ) {
F_149 ( V_154 , V_93 , V_90 , V_1 , V_55 ) ;
} else {
F_143 ( V_154 , V_93 , V_90 , V_55 ) ;
F_151 ( V_163 ) ;
F_152 ( V_154 -> V_164 , V_163 ) ;
V_20 = V_165 ;
V_166:
V_1 = F_96 ( V_3 , V_55 ) ;
if ( ! V_1 )
goto V_112;
}
if ( ! F_153 ( V_1 , V_154 -> V_164 , V_159 -> V_42 ) ) {
F_21 ( V_1 ) ;
return V_20 | V_167 ;
}
if ( F_100 ( V_1 -> V_3 != V_3 ) ) {
F_81 ( V_1 ) ;
F_154 ( V_1 ) ;
goto V_166;
}
F_47 ( V_1 -> V_5 != V_55 ) ;
if ( F_100 ( ! F_2 ( V_1 ) ) )
goto V_168;
V_123 = ( F_43 ( V_99 ) + V_105 - 1 ) >> V_32 ;
if ( F_100 ( V_55 >= V_123 ) ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
return V_162 ;
}
V_159 -> V_1 = V_1 ;
return V_20 | V_169 ;
V_112:
error = F_142 ( V_90 , V_55 ) ;
if ( error >= 0 )
goto V_166;
if ( error == - V_121 )
return V_170 ;
return V_162 ;
V_168:
F_127 ( V_1 ) ;
error = V_3 -> V_12 -> V_119 ( V_90 , V_1 ) ;
if ( ! error ) {
F_95 ( V_1 ) ;
if ( ! F_2 ( V_1 ) )
error = - V_40 ;
}
F_21 ( V_1 ) ;
if ( ! error || error == V_120 )
goto V_166;
F_118 ( V_90 , V_93 ) ;
return V_162 ;
}
int F_155 ( struct V_153 * V_154 , struct V_158 * V_159 )
{
struct V_1 * V_1 = V_159 -> V_1 ;
struct V_99 * V_99 = V_154 -> V_160 -> V_171 . V_172 -> V_173 ;
int V_20 = V_169 ;
F_156 ( V_99 -> V_174 ) ;
F_157 ( V_154 -> V_160 ) ;
F_106 ( V_1 ) ;
if ( V_1 -> V_3 != V_99 -> V_175 ) {
F_81 ( V_1 ) ;
V_20 = V_176 ;
goto V_58;
}
F_158 ( V_1 ) ;
V_58:
F_159 ( V_99 -> V_174 ) ;
return V_20 ;
}
int F_160 ( struct V_90 * V_90 , struct V_153 * V_154 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
if ( ! V_3 -> V_12 -> V_119 )
return - V_177 ;
F_129 ( V_90 ) ;
V_154 -> V_178 = & V_179 ;
V_154 -> V_180 |= V_181 ;
return 0 ;
}
int F_161 ( struct V_90 * V_90 , struct V_153 * V_154 )
{
if ( ( V_154 -> V_180 & V_182 ) && ( V_154 -> V_180 & V_183 ) )
return - V_140 ;
return F_160 ( V_90 , V_154 ) ;
}
int F_160 ( struct V_90 * V_90 , struct V_153 * V_154 )
{
return - V_184 ;
}
int F_161 ( struct V_90 * V_90 , struct V_153 * V_154 )
{
return - V_184 ;
}
static struct V_1 * F_162 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_163)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_59 )
{
struct V_1 * V_1 ;
int V_47 ;
V_81:
V_1 = F_96 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_60 ( V_59 | V_186 ) ;
if ( ! V_1 )
return F_164 ( - V_121 ) ;
V_47 = F_57 ( V_1 , V_3 , V_5 , V_59 ) ;
if ( F_100 ( V_47 ) ) {
F_21 ( V_1 ) ;
if ( V_47 == - V_82 )
goto V_81;
return F_164 ( V_47 ) ;
}
V_47 = F_163 ( V_185 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
V_1 = F_164 ( V_47 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_165 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_163)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_59 )
{
struct V_1 * V_1 ;
int V_47 ;
V_187:
V_1 = F_162 ( V_3 , V_5 , F_163 , V_185 , V_59 ) ;
if ( F_166 ( V_1 ) )
return V_1 ;
if ( F_2 ( V_1 ) )
goto V_58;
F_106 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_187;
}
if ( F_2 ( V_1 ) ) {
F_81 ( V_1 ) ;
goto V_58;
}
V_47 = F_163 ( V_185 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
return F_164 ( V_47 ) ;
}
V_58:
F_125 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_167 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_163)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_165 ( V_3 , V_5 , F_163 , V_185 , F_117 ( V_3 ) ) ;
}
static struct V_1 * F_168 ( struct V_1 * V_1 )
{
if ( ! F_166 ( V_1 ) ) {
F_95 ( V_1 ) ;
if ( ! F_2 ( V_1 ) ) {
F_21 ( V_1 ) ;
V_1 = F_164 ( - V_40 ) ;
}
}
return V_1 ;
}
struct V_1 * F_169 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_59 )
{
T_9 * F_163 = ( T_9 * ) V_3 -> V_12 -> V_119 ;
return F_168 ( F_165 ( V_3 , V_5 , F_163 , NULL , V_59 ) ) ;
}
struct V_1 * F_170 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_163)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_168 ( F_167 ( V_3 , V_5 , F_163 , V_185 ) ) ;
}
static T_8 F_171 ( char * V_188 ,
const struct V_131 * V_132 , T_8 V_189 , T_8 V_190 )
{
T_8 V_191 = 0 , V_125 = 0 ;
while ( V_190 ) {
char T_10 * V_127 = V_132 -> V_141 + V_189 ;
int V_192 = F_36 ( V_190 , V_132 -> V_138 - V_189 ) ;
V_189 = 0 ;
V_125 = F_172 ( V_188 , V_127 , V_192 ) ;
V_191 += V_192 ;
V_190 -= V_192 ;
V_188 += V_192 ;
V_132 ++ ;
if ( F_100 ( V_125 ) )
break;
}
return V_191 - V_125 ;
}
T_8 F_173 ( struct V_1 * V_1 ,
struct V_193 * V_38 , unsigned long V_55 , T_8 V_190 )
{
char * V_124 ;
T_8 V_191 ;
F_9 ( ! F_174 () ) ;
V_124 = F_132 ( V_1 ) ;
if ( F_56 ( V_38 -> V_133 == 1 ) ) {
int V_125 ;
char T_10 * V_127 = V_38 -> V_132 -> V_141 + V_38 -> V_194 ;
V_125 = F_172 ( V_124 + V_55 , V_127 , V_190 ) ;
V_191 = V_190 - V_125 ;
} else {
V_191 = F_171 ( V_124 + V_55 ,
V_38 -> V_132 , V_38 -> V_194 , V_190 ) ;
}
F_134 ( V_124 ) ;
return V_191 ;
}
T_8 F_175 ( struct V_1 * V_1 ,
struct V_193 * V_38 , unsigned long V_55 , T_8 V_190 )
{
char * V_124 ;
T_8 V_191 ;
V_124 = F_135 ( V_1 ) ;
if ( F_56 ( V_38 -> V_133 == 1 ) ) {
int V_125 ;
char T_10 * V_127 = V_38 -> V_132 -> V_141 + V_38 -> V_194 ;
V_125 = F_176 ( V_124 + V_55 , V_127 , V_190 ) ;
V_191 = V_190 - V_125 ;
} else {
V_191 = F_171 ( V_124 + V_55 ,
V_38 -> V_132 , V_38 -> V_194 , V_190 ) ;
}
F_137 ( V_1 ) ;
return V_191 ;
}
void F_177 ( struct V_193 * V_38 , T_8 V_190 )
{
F_9 ( V_38 -> V_106 < V_190 ) ;
if ( F_56 ( V_38 -> V_133 == 1 ) ) {
V_38 -> V_194 += V_190 ;
V_38 -> V_106 -= V_190 ;
} else {
const struct V_131 * V_132 = V_38 -> V_132 ;
T_8 V_189 = V_38 -> V_194 ;
unsigned long V_133 = V_38 -> V_133 ;
while ( V_190 || F_100 ( V_38 -> V_106 && ! V_132 -> V_138 ) ) {
int V_192 ;
V_192 = F_36 ( V_190 , V_132 -> V_138 - V_189 ) ;
F_9 ( ! V_38 -> V_106 || V_38 -> V_106 < V_192 ) ;
V_38 -> V_106 -= V_192 ;
V_190 -= V_192 ;
V_189 += V_192 ;
if ( V_132 -> V_138 == V_189 ) {
V_132 ++ ;
V_133 -- ;
V_189 = 0 ;
}
}
V_38 -> V_132 = V_132 ;
V_38 -> V_194 = V_189 ;
V_38 -> V_133 = V_133 ;
}
}
int F_178 ( struct V_193 * V_38 , T_8 V_190 )
{
char T_10 * V_127 = V_38 -> V_132 -> V_141 + V_38 -> V_194 ;
V_190 = F_36 ( V_190 , V_38 -> V_132 -> V_138 - V_38 -> V_194 ) ;
return F_179 ( V_127 , V_190 ) ;
}
T_8 F_180 ( struct V_193 * V_38 )
{
const struct V_131 * V_132 = V_38 -> V_132 ;
if ( V_38 -> V_133 == 1 )
return V_38 -> V_106 ;
else
return F_36 ( V_38 -> V_106 , V_132 -> V_138 - V_38 -> V_194 ) ;
}
inline int F_181 ( struct V_90 * V_90 , T_1 * V_144 , T_8 * V_106 , int V_195 )
{
struct V_99 * V_99 = V_90 -> V_98 -> V_46 ;
unsigned long V_196 = F_182 ( V_197 ) ;
if ( F_100 ( * V_144 < 0 ) )
return - V_140 ;
if ( ! V_195 ) {
if ( V_90 -> V_149 & V_198 )
* V_144 = F_43 ( V_99 ) ;
if ( V_196 != V_199 ) {
if ( * V_144 >= V_196 ) {
F_183 ( V_200 , V_15 , 0 ) ;
return - V_201 ;
}
if ( * V_106 > V_196 - ( F_184 ( V_196 ) ) * V_144 ) {
* V_106 = V_196 - ( F_184 ( V_196 ) ) * V_144 ;
}
}
}
if ( F_100 ( * V_144 + * V_106 > V_202 &&
! ( V_90 -> V_149 & V_203 ) ) ) {
if ( * V_144 >= V_202 ) {
return - V_201 ;
}
if ( * V_106 > V_202 - ( unsigned long ) * V_144 ) {
* V_106 = V_202 - ( unsigned long ) * V_144 ;
}
}
if ( F_56 ( ! V_195 ) ) {
if ( F_100 ( * V_144 >= V_99 -> V_174 -> V_204 ) ) {
if ( * V_106 || * V_144 > V_99 -> V_174 -> V_204 ) {
return - V_201 ;
}
}
if ( F_100 ( * V_144 + * V_106 > V_99 -> V_174 -> V_204 ) )
* V_106 = V_99 -> V_174 -> V_204 - * V_144 ;
} else {
#ifdef F_185
T_1 V_109 ;
if ( F_186 ( F_187 ( V_99 ) ) )
return - V_205 ;
V_109 = F_43 ( V_99 ) ;
if ( * V_144 >= V_109 ) {
if ( * V_106 || * V_144 > V_109 )
return - V_43 ;
}
if ( * V_144 + * V_106 > V_109 )
* V_106 = V_109 - * V_144 ;
#else
return - V_205 ;
#endif
}
return 0 ;
}
int F_188 ( struct V_90 * V_90 , struct V_2 * V_3 ,
T_1 V_144 , unsigned V_206 , unsigned V_42 ,
struct V_1 * * V_80 , void * * V_207 )
{
const struct V_208 * V_209 = V_3 -> V_12 ;
return V_209 -> V_210 ( V_90 , V_3 , V_144 , V_206 , V_42 ,
V_80 , V_207 ) ;
}
int F_189 ( struct V_90 * V_90 , struct V_2 * V_3 ,
T_1 V_144 , unsigned V_206 , unsigned V_191 ,
struct V_1 * V_1 , void * V_207 )
{
const struct V_208 * V_209 = V_3 -> V_12 ;
F_125 ( V_1 ) ;
return V_209 -> V_211 ( V_90 , V_3 , V_144 , V_206 , V_191 , V_1 , V_207 ) ;
}
V_139
F_190 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long * V_133 , T_1 V_144 , T_1 * V_95 ,
T_8 V_106 , T_8 V_212 )
{
struct V_90 * V_90 = V_143 -> V_145 ;
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_99 * V_99 = V_3 -> V_46 ;
V_139 V_130 ;
T_8 V_213 ;
T_2 V_18 ;
if ( V_106 != V_212 )
* V_133 = F_191 ( (struct V_131 * ) V_132 , * V_133 , V_106 ) ;
V_213 = F_141 ( V_132 , * V_133 ) ;
V_18 = ( V_144 + V_213 - 1 ) >> V_32 ;
V_130 = F_45 ( V_3 , V_144 , V_144 + V_213 - 1 ) ;
if ( V_130 )
goto V_58;
if ( V_3 -> V_6 ) {
V_130 = F_192 ( V_3 ,
V_144 >> V_32 , V_18 ) ;
if ( V_130 ) {
if ( V_130 == - V_214 )
return 0 ;
goto V_58;
}
}
V_130 = V_3 -> V_12 -> V_151 ( V_215 , V_143 , V_132 , V_144 , * V_133 ) ;
if ( V_3 -> V_6 ) {
F_192 ( V_3 ,
V_144 >> V_32 , V_18 ) ;
}
if ( V_130 > 0 ) {
V_144 += V_130 ;
if ( V_144 > F_43 ( V_99 ) && ! F_193 ( V_99 -> V_216 ) ) {
F_194 ( V_99 , V_144 ) ;
F_195 ( V_99 ) ;
}
* V_95 = V_144 ;
}
V_58:
return V_130 ;
}
struct V_1 * F_196 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_42 )
{
int V_217 ;
T_3 V_53 ;
struct V_1 * V_1 ;
T_3 V_218 = 0 ;
V_53 = F_117 ( V_3 ) ;
if ( F_12 ( V_3 ) )
V_53 |= V_219 ;
if ( V_42 & V_220 )
V_218 = V_88 ;
V_81:
V_1 = F_105 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_221;
V_1 = F_60 ( V_53 & ~ V_218 ) ;
if ( ! V_1 )
return NULL ;
V_217 = F_57 ( V_1 , V_3 , V_5 ,
V_122 & ~ V_218 ) ;
if ( F_100 ( V_217 ) ) {
F_21 ( V_1 ) ;
if ( V_217 == - V_82 )
goto V_81;
return NULL ;
}
V_221:
F_37 ( V_1 ) ;
return V_1 ;
}
static V_139 F_197 ( struct V_90 * V_90 ,
struct V_193 * V_38 , T_1 V_144 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
const struct V_208 * V_12 = V_3 -> V_12 ;
long V_217 = 0 ;
V_139 V_130 = 0 ;
unsigned int V_42 = 0 ;
if ( F_198 ( F_199 () , V_222 ) )
V_42 |= V_223 ;
do {
struct V_1 * V_1 ;
unsigned long V_55 ;
unsigned long V_190 ;
T_8 V_191 ;
void * V_207 ;
V_55 = ( V_144 & ( V_105 - 1 ) ) ;
V_190 = F_200 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_224:
if ( F_100 ( F_178 ( V_38 , V_190 ) ) ) {
V_217 = - V_129 ;
break;
}
V_217 = V_12 -> V_210 ( V_90 , V_3 , V_144 , V_190 , V_42 ,
& V_1 , & V_207 ) ;
if ( F_100 ( V_217 ) )
break;
if ( F_123 ( V_3 ) )
F_124 ( V_1 ) ;
F_201 () ;
V_191 = F_173 ( V_1 , V_38 , V_55 , V_190 ) ;
F_202 () ;
F_124 ( V_1 ) ;
F_125 ( V_1 ) ;
V_217 = V_12 -> V_211 ( V_90 , V_3 , V_144 , V_190 , V_191 ,
V_1 , V_207 ) ;
if ( F_100 ( V_217 < 0 ) )
break;
V_191 = V_217 ;
F_40 () ;
F_177 ( V_38 , V_191 ) ;
if ( F_100 ( V_191 == 0 ) ) {
V_190 = F_200 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_224;
}
V_144 += V_191 ;
V_130 += V_191 ;
F_203 ( V_3 ) ;
if ( F_25 ( V_15 ) ) {
V_217 = - V_16 ;
break;
}
} while ( F_204 ( V_38 ) );
return V_130 ? V_130 : V_217 ;
}
V_139
F_205 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 , T_1 * V_95 ,
T_8 V_106 , V_139 V_130 )
{
struct V_90 * V_90 = V_143 -> V_145 ;
V_139 V_217 ;
struct V_193 V_38 ;
F_206 ( & V_38 , V_132 , V_133 , V_106 , V_130 ) ;
V_217 = F_197 ( V_90 , & V_38 , V_144 ) ;
if ( F_56 ( V_217 >= 0 ) ) {
V_130 += V_217 ;
* V_95 = V_144 + V_217 ;
}
return V_130 ? V_130 : V_217 ;
}
V_139 F_207 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 * V_95 )
{
struct V_90 * V_90 = V_143 -> V_145 ;
struct V_2 * V_3 = V_90 -> V_98 ;
T_8 V_212 ;
T_8 V_106 ;
struct V_99 * V_99 = V_3 -> V_46 ;
T_1 V_144 ;
V_139 V_130 ;
V_139 V_47 ;
V_212 = 0 ;
V_47 = F_138 ( V_132 , & V_133 , & V_212 , V_225 ) ;
if ( V_47 )
return V_47 ;
V_106 = V_212 ;
V_144 = * V_95 ;
V_15 -> V_10 = V_3 -> V_10 ;
V_130 = 0 ;
V_47 = F_181 ( V_90 , & V_144 , & V_106 , F_193 ( V_99 -> V_216 ) ) ;
if ( V_47 )
goto V_58;
if ( V_106 == 0 )
goto V_58;
V_47 = F_208 ( V_90 ) ;
if ( V_47 )
goto V_58;
V_47 = F_157 ( V_90 ) ;
if ( V_47 )
goto V_58;
if ( F_100 ( V_90 -> V_149 & V_150 ) ) {
T_1 V_226 ;
V_139 V_227 ;
V_130 = F_190 ( V_143 , V_132 , & V_133 , V_144 ,
V_95 , V_106 , V_212 ) ;
if ( V_130 < 0 || V_130 == V_106 )
goto V_58;
V_144 += V_130 ;
V_106 -= V_130 ;
V_227 = F_205 ( V_143 , V_132 ,
V_133 , V_144 , V_95 , V_106 ,
V_130 ) ;
if ( V_227 < 0 ) {
V_47 = V_227 ;
goto V_58;
}
V_226 = V_144 + V_227 - V_130 - 1 ;
V_47 = F_45 ( V_90 -> V_98 , V_144 , V_226 ) ;
if ( V_47 == 0 ) {
V_130 = V_227 ;
F_209 ( V_3 ,
V_144 >> V_32 ,
V_226 >> V_32 ) ;
} else {
}
} else {
V_130 = F_205 ( V_143 , V_132 , V_133 ,
V_144 , V_95 , V_106 , V_130 ) ;
}
V_58:
V_15 -> V_10 = NULL ;
return V_130 ? V_130 : V_47 ;
}
V_139 F_210 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 )
{
struct V_90 * V_90 = V_143 -> V_145 ;
struct V_99 * V_99 = V_90 -> V_98 -> V_46 ;
V_139 V_20 ;
F_9 ( V_143 -> V_147 != V_144 ) ;
F_211 ( V_99 -> V_174 ) ;
F_212 ( & V_99 -> V_228 ) ;
V_20 = F_207 ( V_143 , V_132 , V_133 , & V_143 -> V_147 ) ;
F_213 ( & V_99 -> V_228 ) ;
if ( V_20 > 0 || V_20 == - V_229 ) {
V_139 V_47 ;
V_47 = F_214 ( V_90 , V_144 , V_20 ) ;
if ( V_47 < 0 && V_20 > 0 )
V_20 = V_47 ;
}
F_215 ( V_99 -> V_174 ) ;
return V_20 ;
}
int F_216 ( struct V_1 * V_1 , T_3 V_53 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_9 ( ! F_17 ( V_1 ) ) ;
if ( F_217 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_230 )
return V_3 -> V_12 -> V_230 ( V_1 , V_53 ) ;
return F_218 ( V_1 ) ;
}
