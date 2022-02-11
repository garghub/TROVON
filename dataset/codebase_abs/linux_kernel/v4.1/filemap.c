static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
void * * V_10 ;
F_2 ( ! F_3 ( V_3 ) ) ;
F_4 ( & V_2 -> V_11 , V_3 -> V_7 , & V_6 , & V_10 ) ;
if ( V_4 ) {
V_2 -> V_12 ++ ;
F_5 () ;
}
V_2 -> V_13 -- ;
if ( ! V_6 ) {
V_2 -> V_11 . V_14 &= V_15 ;
F_6 ( V_10 , V_4 ) ;
return;
}
V_7 = V_3 -> V_7 ;
V_8 = V_7 & V_16 ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( F_7 ( V_8 , V_6 -> V_18 [ V_9 ] ) )
F_8 ( & V_2 -> V_11 , V_7 , V_9 ) ;
}
F_6 ( V_10 , V_4 ) ;
F_9 ( V_6 ) ;
if ( V_4 )
F_10 ( V_6 ) ;
else
if ( F_11 ( & V_2 -> V_11 , V_6 ) )
return;
if ( ! F_12 ( V_6 ) &&
F_13 ( & V_6 -> V_19 ) ) {
V_6 -> V_20 = V_2 ;
F_14 ( & V_21 , & V_6 -> V_19 ) ;
}
}
void F_15 ( struct V_3 * V_3 , void * V_4 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
F_16 ( V_3 ) ;
if ( F_17 ( V_3 ) && F_18 ( V_3 ) )
F_19 ( V_3 ) ;
else
F_20 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
F_21 ( V_3 , V_22 ) ;
if ( F_22 ( V_3 ) )
F_21 ( V_3 , V_23 ) ;
F_23 ( F_24 ( V_3 ) ) ;
if ( F_25 ( F_26 ( V_3 ) ) )
F_27 ( V_3 , V_2 ) ;
}
void F_28 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
void (* F_29)( struct V_3 * );
F_23 ( ! F_3 ( V_3 ) ) ;
F_29 = V_2 -> V_24 -> F_29 ;
F_30 ( & V_2 -> V_25 ) ;
F_15 ( V_3 , NULL ) ;
F_31 ( & V_2 -> V_25 ) ;
if ( F_29 )
F_29 ( V_3 ) ;
F_32 ( V_3 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
if ( F_7 ( V_27 , & V_2 -> V_28 ) &&
F_34 ( V_27 , & V_2 -> V_28 ) )
V_26 = - V_29 ;
if ( F_7 ( V_30 , & V_2 -> V_28 ) &&
F_34 ( V_30 , & V_2 -> V_28 ) )
V_26 = - V_31 ;
return V_26 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_32 ,
T_1 V_33 , int V_34 )
{
int V_26 ;
struct V_35 V_36 = {
. V_34 = V_34 ,
. V_37 = V_38 ,
. V_39 = V_32 ,
. V_40 = V_33 ,
} ;
if ( ! F_36 ( V_2 ) )
return 0 ;
V_26 = F_37 ( V_2 , & V_36 ) ;
return V_26 ;
}
static inline int F_38 ( struct V_1 * V_2 ,
int V_34 )
{
return F_35 ( V_2 , 0 , V_41 , V_34 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , V_42 ) ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_32 ,
T_1 V_33 )
{
return F_35 ( V_2 , V_32 , V_33 , V_42 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , V_43 ) ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_44 ,
T_1 V_45 )
{
T_2 V_7 = V_44 >> V_46 ;
T_2 V_33 = V_45 >> V_46 ;
struct V_47 V_48 ;
int V_49 ;
int V_50 , V_26 = 0 ;
if ( V_45 < V_44 )
goto V_51;
F_43 ( & V_48 , 0 ) ;
while ( ( V_7 <= V_33 ) &&
( V_49 = F_44 ( & V_48 , V_2 , & V_7 ,
V_52 ,
F_45 ( V_33 - V_7 , ( T_2 ) V_53 - 1 ) + 1 ) ) != 0 ) {
unsigned V_54 ;
for ( V_54 = 0 ; V_54 < V_49 ; V_54 ++ ) {
struct V_3 * V_3 = V_48 . V_55 [ V_54 ] ;
if ( V_3 -> V_7 > V_33 )
continue;
F_46 ( V_3 ) ;
if ( F_47 ( V_3 ) )
V_26 = - V_31 ;
}
F_48 ( & V_48 ) ;
F_49 () ;
}
V_51:
V_50 = F_33 ( V_2 ) ;
if ( ! V_26 )
V_26 = V_50 ;
return V_26 ;
}
int F_50 ( struct V_1 * V_2 )
{
T_1 V_56 = F_51 ( V_2 -> V_57 ) ;
if ( V_56 == 0 )
return 0 ;
return F_42 ( V_2 , 0 , V_56 - 1 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_58 = 0 ;
if ( V_2 -> V_13 ) {
V_58 = F_39 ( V_2 ) ;
if ( V_58 != - V_31 ) {
int V_59 = F_50 ( V_2 ) ;
if ( ! V_58 )
V_58 = V_59 ;
}
} else {
V_58 = F_33 ( V_2 ) ;
}
return V_58 ;
}
int F_53 ( struct V_1 * V_2 ,
T_1 V_60 , T_1 V_61 )
{
int V_58 = 0 ;
if ( V_2 -> V_13 ) {
V_58 = F_35 ( V_2 , V_60 , V_61 ,
V_42 ) ;
if ( V_58 != - V_31 ) {
int V_59 = F_42 ( V_2 ,
V_60 , V_61 ) ;
if ( ! V_58 )
V_58 = V_59 ;
}
} else {
V_58 = F_33 ( V_2 ) ;
}
return V_58 ;
}
int F_54 ( struct V_3 * V_62 , struct V_3 * V_63 , T_3 V_14 )
{
int error ;
F_55 ( ! F_3 ( V_62 ) , V_62 ) ;
F_55 ( ! F_3 ( V_63 ) , V_63 ) ;
F_55 ( V_63 -> V_2 , V_63 ) ;
error = F_56 ( V_14 & ~ V_64 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_62 -> V_2 ;
void (* F_29)( struct V_3 * );
T_2 V_8 = V_62 -> V_7 ;
F_29 = V_2 -> V_24 -> F_29 ;
F_57 ( V_63 ) ;
V_63 -> V_2 = V_2 ;
V_63 -> V_7 = V_8 ;
F_30 ( & V_2 -> V_25 ) ;
F_15 ( V_62 , NULL ) ;
error = F_58 ( & V_2 -> V_11 , V_8 , V_63 ) ;
F_23 ( error ) ;
V_2 -> V_13 ++ ;
F_59 ( V_63 , V_22 ) ;
if ( F_22 ( V_63 ) )
F_59 ( V_63 , V_23 ) ;
F_31 ( & V_2 -> V_25 ) ;
F_60 ( V_62 , V_63 , true ) ;
F_61 () ;
if ( F_29 )
F_29 ( V_62 ) ;
F_32 ( V_62 ) ;
}
return error ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_65 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_63 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_66 ;
V_66 = F_64 ( V_10 , & V_2 -> V_25 ) ;
if ( ! F_65 ( V_66 ) )
return - V_67 ;
if ( V_65 )
* V_65 = V_66 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_66 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_67 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_68 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_69 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_65 )
{
int V_68 = F_70 ( V_3 ) ;
struct V_69 * V_70 ;
int error ;
F_55 ( ! F_3 ( V_3 ) , V_3 ) ;
F_55 ( F_22 ( V_3 ) , V_3 ) ;
if ( ! V_68 ) {
error = F_71 ( V_3 , V_71 -> V_72 ,
V_14 , & V_70 ) ;
if ( error )
return error ;
}
error = F_72 ( V_14 & ~ V_64 ) ;
if ( error ) {
if ( ! V_68 )
F_73 ( V_3 , V_70 ) ;
return error ;
}
F_57 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_30 ( & V_2 -> V_25 ) ;
error = F_62 ( V_2 , V_3 , V_65 ) ;
F_61 () ;
if ( F_74 ( error ) )
goto V_73;
F_59 ( V_3 , V_22 ) ;
F_31 ( & V_2 -> V_25 ) ;
if ( ! V_68 )
F_75 ( V_3 , V_70 , false ) ;
F_76 ( V_3 ) ;
return 0 ;
V_73:
V_3 -> V_2 = NULL ;
F_31 ( & V_2 -> V_25 ) ;
if ( ! V_68 )
F_73 ( V_3 , V_70 ) ;
F_32 ( V_3 ) ;
return error ;
}
int F_77 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_69 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_78 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_26 ;
F_79 ( V_3 ) ;
V_26 = F_69 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_74 ( V_26 ) )
F_80 ( V_3 ) ;
else {
if ( V_4 && F_81 ( V_4 ) ) {
F_82 ( V_3 ) ;
F_83 ( V_3 ) ;
} else
F_84 ( V_3 ) ;
F_85 ( V_3 ) ;
}
return V_26 ;
}
struct V_3 * F_86 ( T_3 V_74 )
{
int V_75 ;
struct V_3 * V_3 ;
if ( F_87 () ) {
unsigned int V_76 ;
do {
V_76 = F_88 () ;
V_75 = F_89 () ;
V_3 = F_90 ( V_75 , V_74 , 0 ) ;
} while ( ! V_3 && F_91 ( V_76 ) );
return V_3 ;
}
return F_92 ( V_74 , 0 ) ;
}
T_4 * F_93 ( struct V_3 * V_3 )
{
const struct V_77 * V_77 = F_94 ( V_3 ) ;
return & V_77 -> V_78 [ F_95 ( V_3 , V_77 -> V_79 ) ] ;
}
void F_96 ( struct V_3 * V_3 , int V_80 )
{
F_97 ( V_81 , & V_3 -> V_28 , V_80 ) ;
if ( F_7 ( V_80 , & V_3 -> V_28 ) )
F_98 ( F_93 ( V_3 ) , & V_81 , V_82 ,
V_83 ) ;
}
int F_99 ( struct V_3 * V_3 , int V_80 )
{
F_97 ( V_81 , & V_3 -> V_28 , V_80 ) ;
if ( ! F_7 ( V_80 , & V_3 -> V_28 ) )
return 0 ;
return F_98 ( F_93 ( V_3 ) , & V_81 ,
V_82 , V_84 ) ;
}
int F_100 ( struct V_3 * V_3 ,
int V_80 , unsigned long V_85 )
{
F_97 ( V_81 , & V_3 -> V_28 , V_80 ) ;
V_81 . V_86 . V_85 = V_87 + V_85 ;
if ( ! F_7 ( V_80 , & V_3 -> V_28 ) )
return 0 ;
return F_98 ( F_93 ( V_3 ) , & V_81 ,
V_88 , V_84 ) ;
}
void F_101 ( struct V_3 * V_3 , T_5 * V_89 )
{
T_4 * V_90 = F_93 ( V_3 ) ;
unsigned long V_28 ;
F_102 ( & V_90 -> V_91 , V_28 ) ;
F_103 ( V_90 , V_89 ) ;
F_104 ( & V_90 -> V_91 , V_28 ) ;
}
void F_105 ( struct V_3 * V_3 )
{
F_55 ( ! F_3 ( V_3 ) , V_3 ) ;
F_106 ( V_92 , & V_3 -> V_28 ) ;
F_107 () ;
F_108 ( V_3 , V_92 ) ;
}
void F_109 ( struct V_3 * V_3 )
{
if ( F_110 ( V_3 ) ) {
F_111 ( V_3 ) ;
F_112 ( V_3 ) ;
}
if ( ! F_113 ( V_3 ) )
F_114 () ;
F_107 () ;
F_108 ( V_3 , V_93 ) ;
}
void F_115 ( struct V_3 * V_3 , int V_94 , int V_58 )
{
if ( V_94 == V_95 ) {
if ( ! V_58 ) {
F_116 ( V_3 ) ;
} else {
F_117 ( V_3 ) ;
F_118 ( V_3 ) ;
}
F_105 ( V_3 ) ;
} else {
if ( V_58 ) {
F_118 ( V_3 ) ;
if ( V_3 -> V_2 )
F_119 ( V_3 -> V_2 , V_58 ) ;
}
F_109 ( V_3 ) ;
}
}
void F_120 ( struct V_3 * V_3 )
{
F_97 ( V_81 , & V_3 -> V_28 , V_92 ) ;
F_121 ( F_93 ( V_3 ) , & V_81 , V_82 ,
V_83 ) ;
}
int F_122 ( struct V_3 * V_3 )
{
F_97 ( V_81 , & V_3 -> V_28 , V_92 ) ;
return F_121 ( F_93 ( V_3 ) , & V_81 ,
V_82 , V_84 ) ;
}
int F_123 ( struct V_3 * V_3 , struct V_96 * V_72 ,
unsigned int V_28 )
{
if ( V_28 & V_97 ) {
if ( V_28 & V_98 )
return 0 ;
F_124 ( & V_72 -> V_99 ) ;
if ( V_28 & V_100 )
F_125 ( V_3 ) ;
else
F_126 ( V_3 ) ;
return 0 ;
} else {
if ( V_28 & V_100 ) {
int V_26 ;
V_26 = F_122 ( V_3 ) ;
if ( V_26 ) {
F_124 ( & V_72 -> V_99 ) ;
return 0 ;
}
} else
F_120 ( V_3 ) ;
return 1 ;
}
}
T_2 F_127 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_54 ;
for ( V_54 = 0 ; V_54 < V_101 ; V_54 ++ ) {
struct V_3 * V_3 ;
V_3 = F_128 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_65 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_129 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_54 ;
for ( V_54 = 0 ; V_54 < V_101 ; V_54 ++ ) {
struct V_3 * V_3 ;
V_3 = F_128 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_65 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_102 )
break;
}
return V_7 ;
}
struct V_3 * F_130 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_103 ;
struct V_3 * V_3 ;
F_131 () ;
V_104:
V_3 = NULL ;
V_103 = F_132 ( & V_2 -> V_11 , V_8 ) ;
if ( V_103 ) {
V_3 = F_133 ( V_103 ) ;
if ( F_74 ( ! V_3 ) )
goto V_51;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) )
goto V_104;
goto V_51;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_103 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
}
V_51:
F_137 () ;
return V_3 ;
}
struct V_3 * F_138 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_130 ( V_2 , V_8 ) ;
if ( V_3 && ! F_134 ( V_3 ) ) {
F_139 ( V_3 ) ;
if ( F_74 ( V_3 -> V_2 != V_2 ) ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
goto V_104;
}
F_55 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_140 ( struct V_1 * V_2 , T_2 V_8 ,
int V_105 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_130 ( V_2 , V_8 ) ;
if ( F_65 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_106;
if ( V_105 & V_107 ) {
if ( V_105 & V_108 ) {
if ( ! F_141 ( V_3 ) ) {
F_32 ( V_3 ) ;
return NULL ;
}
} else {
F_139 ( V_3 ) ;
}
if ( F_74 ( V_3 -> V_2 != V_2 ) ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
goto V_104;
}
F_55 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_105 & V_109 ) )
F_142 ( V_3 ) ;
V_106:
if ( ! V_3 && ( V_105 & V_110 ) ) {
int V_58 ;
if ( ( V_105 & V_111 ) && F_143 ( V_2 ) )
V_14 |= V_112 ;
if ( V_105 & V_113 )
V_14 &= ~ V_114 ;
V_3 = F_86 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_25 ( ! ( V_105 & V_107 ) ) )
V_105 |= V_107 ;
if ( V_105 & V_109 )
F_144 ( V_3 ) ;
V_58 = F_78 ( V_3 , V_2 , V_8 ,
V_14 & V_115 ) ;
if ( F_74 ( V_58 ) ) {
F_32 ( V_3 ) ;
V_3 = NULL ;
if ( V_58 == - V_67 )
goto V_104;
}
}
return V_3 ;
}
unsigned F_145 ( struct V_1 * V_2 ,
T_2 V_32 , unsigned int V_116 ,
struct V_3 * * V_117 , T_2 * V_118 )
{
void * * V_10 ;
unsigned int V_26 = 0 ;
struct V_119 V_120 ;
if ( ! V_116 )
return 0 ;
F_131 () ;
V_121:
F_146 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_133 ( V_10 ) ;
if ( F_74 ( ! V_3 ) )
continue;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) )
goto V_121;
goto V_122;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_10 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
V_122:
V_118 [ V_26 ] = V_120 . V_7 ;
V_117 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_116 )
break;
}
F_137 () ;
return V_26 ;
}
unsigned F_147 ( struct V_1 * V_2 , T_2 V_32 ,
unsigned int V_49 , struct V_3 * * V_55 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_26 = 0 ;
if ( F_74 ( ! V_49 ) )
return 0 ;
F_131 () ;
V_121:
F_146 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_133 ( V_10 ) ;
if ( F_74 ( ! V_3 ) )
continue;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) ) {
F_148 ( V_120 . V_7 ) ;
goto V_121;
}
continue;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_10 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
V_55 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_49 )
break;
}
F_137 () ;
return V_26 ;
}
unsigned F_149 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_49 , struct V_3 * * V_55 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned int V_26 = 0 ;
if ( F_74 ( ! V_49 ) )
return 0 ;
F_131 () ;
V_121:
F_150 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_104:
V_3 = F_133 ( V_10 ) ;
if ( F_74 ( ! V_3 ) )
break;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) ) {
goto V_121;
}
break;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_10 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_120 . V_7 ) {
F_32 ( V_3 ) ;
break;
}
V_55 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_49 )
break;
}
F_137 () ;
return V_26 ;
}
unsigned F_151 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_49 , struct V_3 * * V_55 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_26 = 0 ;
if ( F_74 ( ! V_49 ) )
return 0 ;
F_131 () ;
V_121:
F_152 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_104:
V_3 = F_133 ( V_10 ) ;
if ( F_74 ( ! V_3 ) )
continue;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) ) {
goto V_121;
}
continue;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_10 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
V_55 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_49 )
break;
}
F_137 () ;
if ( V_26 )
* V_7 = V_55 [ V_26 - 1 ] -> V_7 + 1 ;
return V_26 ;
}
static void F_153 ( struct V_123 * V_124 ,
struct V_125 * V_126 )
{
V_126 -> V_127 /= 4 ;
}
static T_6 F_154 ( struct V_123 * V_124 , T_1 * V_128 ,
struct V_129 * V_120 , T_6 V_130 )
{
struct V_1 * V_2 = V_124 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_57 ;
struct V_125 * V_126 = & V_124 -> V_133 ;
T_2 V_7 ;
T_2 V_134 ;
T_2 V_135 ;
unsigned long V_8 ;
unsigned int V_136 ;
int error = 0 ;
V_7 = * V_128 >> V_46 ;
V_135 = V_126 -> V_137 >> V_46 ;
V_136 = V_126 -> V_137 & ( V_138 - 1 ) ;
V_134 = ( * V_128 + V_120 -> V_139 + V_138 - 1 ) >> V_46 ;
V_8 = * V_128 & ~ V_140 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_141 ;
T_1 V_142 ;
unsigned long V_143 , V_26 ;
F_49 () ;
V_144:
V_3 = F_155 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_156 ( V_2 ,
V_126 , V_124 ,
V_7 , V_134 - V_7 ) ;
V_3 = F_155 ( V_2 , V_7 ) ;
if ( F_74 ( V_3 == NULL ) )
goto V_145;
}
if ( F_157 ( V_3 ) ) {
F_158 ( V_2 ,
V_126 , V_124 , V_3 ,
V_7 , V_134 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_132 -> V_146 == V_46 ||
! V_2 -> V_24 -> V_147 )
goto V_148;
if ( ! F_141 ( V_3 ) )
goto V_148;
if ( ! V_3 -> V_2 )
goto V_149;
if ( ! V_2 -> V_24 -> V_147 ( V_3 ,
V_8 , V_120 -> V_139 ) )
goto V_149;
F_105 ( V_3 ) ;
}
V_150:
V_142 = F_51 ( V_132 ) ;
V_141 = ( V_142 - 1 ) >> V_46 ;
if ( F_74 ( ! V_142 || V_7 > V_141 ) ) {
F_32 ( V_3 ) ;
goto V_51;
}
V_143 = V_138 ;
if ( V_7 == V_141 ) {
V_143 = ( ( V_142 - 1 ) & ~ V_140 ) + 1 ;
if ( V_143 <= V_8 ) {
F_32 ( V_3 ) ;
goto V_51;
}
}
V_143 = V_143 - V_8 ;
if ( F_159 ( V_2 ) )
F_160 ( V_3 ) ;
if ( V_135 != V_7 || V_8 != V_136 )
F_142 ( V_3 ) ;
V_135 = V_7 ;
V_26 = F_161 ( V_3 , V_8 , V_143 , V_120 ) ;
V_8 += V_26 ;
V_7 += V_8 >> V_46 ;
V_8 &= ~ V_140 ;
V_136 = V_8 ;
F_32 ( V_3 ) ;
V_130 += V_26 ;
if ( ! F_162 ( V_120 ) )
goto V_51;
if ( V_26 < V_143 ) {
error = - V_151 ;
goto V_51;
}
continue;
V_148:
error = F_163 ( V_3 ) ;
if ( F_74 ( error ) )
goto V_152;
V_149:
if ( ! V_3 -> V_2 ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_105 ( V_3 ) ;
goto V_150;
}
V_153:
F_164 ( V_3 ) ;
error = V_2 -> V_24 -> V_153 ( V_124 , V_3 ) ;
if ( F_74 ( error ) ) {
if ( error == V_154 ) {
F_32 ( V_3 ) ;
error = 0 ;
goto V_144;
}
goto V_152;
}
if ( ! F_17 ( V_3 ) ) {
error = F_163 ( V_3 ) ;
if ( F_74 ( error ) )
goto V_152;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
goto V_144;
}
F_105 ( V_3 ) ;
F_153 ( V_124 , V_126 ) ;
error = - V_31 ;
goto V_152;
}
F_105 ( V_3 ) ;
}
goto V_150;
V_152:
F_32 ( V_3 ) ;
goto V_51;
V_145:
V_3 = F_165 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_155 ;
goto V_51;
}
error = F_78 ( V_3 , V_2 ,
V_7 , V_156 ) ;
if ( error ) {
F_32 ( V_3 ) ;
if ( error == - V_67 ) {
error = 0 ;
goto V_144;
}
goto V_51;
}
goto V_153;
}
V_51:
V_126 -> V_137 = V_135 ;
V_126 -> V_137 <<= V_46 ;
V_126 -> V_137 |= V_136 ;
* V_128 = ( ( T_1 ) V_7 << V_46 ) + V_8 ;
F_166 ( V_124 ) ;
return V_130 ? V_130 : error ;
}
T_6
F_167 ( struct V_157 * V_158 , struct V_129 * V_120 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
T_6 V_160 = 0 ;
T_1 * V_128 = & V_158 -> V_161 ;
T_1 V_162 = * V_128 ;
if ( V_158 -> V_163 & V_164 ) {
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_57 ;
T_7 V_139 = F_162 ( V_120 ) ;
T_1 V_165 ;
if ( ! V_139 )
goto V_51;
V_165 = F_51 ( V_132 ) ;
V_160 = F_53 ( V_2 , V_162 ,
V_162 + V_139 - 1 ) ;
if ( ! V_160 ) {
struct V_129 V_166 = * V_120 ;
V_160 = V_2 -> V_24 -> V_167 ( V_158 , & V_166 , V_162 ) ;
}
if ( V_160 > 0 ) {
* V_128 = V_162 + V_160 ;
F_168 ( V_120 , V_160 ) ;
}
if ( V_160 < 0 || ! F_162 ( V_120 ) || * V_128 >= V_165 ||
F_169 ( V_132 ) ) {
F_166 ( V_123 ) ;
goto V_51;
}
}
V_160 = F_154 ( V_123 , V_128 , V_120 , V_160 ) ;
V_51:
return V_160 ;
}
static int F_170 ( struct V_123 * V_123 , T_2 V_8 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_3 * V_3 ;
int V_26 ;
do {
V_3 = F_165 ( V_2 ) ;
if ( ! V_3 )
return - V_155 ;
V_26 = F_78 ( V_3 , V_2 , V_8 , V_156 ) ;
if ( V_26 == 0 )
V_26 = V_2 -> V_24 -> V_153 ( V_123 , V_3 ) ;
else if ( V_26 == - V_67 )
V_26 = 0 ;
F_32 ( V_3 ) ;
} while ( V_26 == V_154 );
return V_26 ;
}
static void F_171 ( struct V_168 * V_169 ,
struct V_125 * V_126 ,
struct V_123 * V_123 ,
T_2 V_8 )
{
unsigned long V_127 ;
struct V_1 * V_2 = V_123 -> V_131 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( ! V_126 -> V_127 )
return;
if ( V_169 -> V_170 & V_172 ) {
F_156 ( V_2 , V_126 , V_123 , V_8 ,
V_126 -> V_127 ) ;
return;
}
if ( V_126 -> V_173 < V_174 * 10 )
V_126 -> V_173 ++ ;
if ( V_126 -> V_173 > V_174 )
return;
V_127 = F_172 ( V_126 -> V_127 ) ;
V_126 -> V_32 = F_173 ( long , 0 , V_8 - V_127 / 2 ) ;
V_126 -> V_165 = V_127 ;
V_126 -> V_175 = V_127 / 4 ;
F_174 ( V_126 , V_2 , V_123 ) ;
}
static void F_175 ( struct V_168 * V_169 ,
struct V_125 * V_126 ,
struct V_123 * V_123 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( V_126 -> V_173 > 0 )
V_126 -> V_173 -- ;
if ( F_157 ( V_3 ) )
F_158 ( V_2 , V_126 , V_123 ,
V_3 , V_8 , V_126 -> V_127 ) ;
}
int F_176 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
int error ;
struct V_123 * V_123 = V_169 -> V_178 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_125 * V_126 = & V_123 -> V_133 ;
struct V_132 * V_132 = V_2 -> V_57 ;
T_2 V_8 = V_177 -> V_179 ;
struct V_3 * V_3 ;
T_1 V_165 ;
int V_26 = 0 ;
V_165 = F_177 ( F_51 ( V_132 ) , V_138 ) ;
if ( V_8 >= V_165 >> V_46 )
return V_180 ;
V_3 = F_155 ( V_2 , V_8 ) ;
if ( F_178 ( V_3 ) && ! ( V_177 -> V_28 & V_181 ) ) {
F_175 ( V_169 , V_126 , V_123 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_171 ( V_169 , V_126 , V_123 , V_8 ) ;
F_179 ( V_182 ) ;
F_180 ( V_169 -> V_183 , V_182 ) ;
V_26 = V_184 ;
V_185:
V_3 = F_155 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_145;
}
if ( ! F_181 ( V_3 , V_169 -> V_183 , V_177 -> V_28 ) ) {
F_32 ( V_3 ) ;
return V_26 | V_186 ;
}
if ( F_74 ( V_3 -> V_2 != V_2 ) ) {
F_105 ( V_3 ) ;
F_182 ( V_3 ) ;
goto V_185;
}
F_55 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_74 ( ! F_17 ( V_3 ) ) )
goto V_187;
V_165 = F_177 ( F_51 ( V_132 ) , V_138 ) ;
if ( F_74 ( V_8 >= V_165 >> V_46 ) ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
return V_180 ;
}
V_177 -> V_3 = V_3 ;
return V_26 | V_188 ;
V_145:
error = F_170 ( V_123 , V_8 ) ;
if ( error >= 0 )
goto V_185;
if ( error == - V_155 )
return V_189 ;
return V_180 ;
V_187:
F_164 ( V_3 ) ;
error = V_2 -> V_24 -> V_153 ( V_123 , V_3 ) ;
if ( ! error ) {
F_126 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_31 ;
}
F_32 ( V_3 ) ;
if ( ! error || error == V_154 )
goto V_185;
F_153 ( V_123 , V_126 ) ;
return V_180 ;
}
void F_183 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_119 V_120 ;
void * * V_10 ;
struct V_123 * V_123 = V_169 -> V_178 ;
struct V_1 * V_2 = V_123 -> V_131 ;
T_1 V_165 ;
struct V_3 * V_3 ;
unsigned long V_190 = ( unsigned long ) V_177 -> V_191 ;
unsigned long V_192 ;
T_8 * V_193 ;
F_131 () ;
F_146 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_120 . V_7 > V_177 -> V_194 )
break;
V_104:
V_3 = F_133 ( V_10 ) ;
if ( F_74 ( ! V_3 ) )
goto V_195;
if ( F_134 ( V_3 ) ) {
if ( F_135 ( V_3 ) )
break;
else
goto V_195;
}
if ( ! F_136 ( V_3 ) )
goto V_104;
if ( F_74 ( V_3 != * V_10 ) ) {
F_32 ( V_3 ) ;
goto V_104;
}
if ( ! F_17 ( V_3 ) ||
F_157 ( V_3 ) ||
F_184 ( V_3 ) )
goto V_196;
if ( ! F_141 ( V_3 ) )
goto V_196;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_197;
V_165 = F_177 ( F_51 ( V_2 -> V_57 ) , V_138 ) ;
if ( V_3 -> V_7 >= V_165 >> V_46 )
goto V_197;
V_193 = V_177 -> V_193 + V_3 -> V_7 - V_177 -> V_179 ;
if ( ! F_185 ( * V_193 ) )
goto V_197;
if ( V_123 -> V_133 . V_173 > 0 )
V_123 -> V_133 . V_173 -- ;
V_192 = V_190 + ( V_3 -> V_7 - V_177 -> V_179 ) * V_198 ;
F_186 ( V_169 , V_192 , V_3 , V_193 , false , false ) ;
F_105 ( V_3 ) ;
goto V_195;
V_197:
F_105 ( V_3 ) ;
V_196:
F_32 ( V_3 ) ;
V_195:
if ( V_120 . V_7 == V_177 -> V_194 )
break;
}
F_137 () ;
}
int F_187 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_3 * V_3 = V_177 -> V_3 ;
struct V_132 * V_132 = F_188 ( V_169 -> V_178 ) ;
int V_26 = V_188 ;
F_189 ( V_132 -> V_199 ) ;
F_190 ( V_169 -> V_178 ) ;
F_139 ( V_3 ) ;
if ( V_3 -> V_2 != V_132 -> V_200 ) {
F_105 ( V_3 ) ;
V_26 = V_201 ;
goto V_51;
}
F_191 ( V_3 ) ;
F_192 ( V_3 ) ;
V_51:
F_193 ( V_132 -> V_199 ) ;
return V_26 ;
}
int F_194 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
if ( ! V_2 -> V_24 -> V_153 )
return - V_202 ;
F_166 ( V_123 ) ;
V_169 -> V_203 = & V_204 ;
return 0 ;
}
int F_195 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 & V_205 ) && ( V_169 -> V_170 & V_206 ) )
return - V_207 ;
return F_194 ( V_123 , V_169 ) ;
}
int F_194 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
int F_195 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
static struct V_3 * F_196 ( struct V_3 * V_3 )
{
if ( ! F_197 ( V_3 ) ) {
F_126 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_32 ( V_3 ) ;
V_3 = F_198 ( - V_31 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_199 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_74 )
{
struct V_3 * V_3 ;
int V_58 ;
V_104:
V_3 = F_155 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_86 ( V_74 | V_209 ) ;
if ( ! V_3 )
return F_198 ( - V_155 ) ;
V_58 = F_78 ( V_3 , V_2 , V_7 , V_74 ) ;
if ( F_74 ( V_58 ) ) {
F_32 ( V_3 ) ;
if ( V_58 == - V_67 )
goto V_104;
return F_198 ( V_58 ) ;
}
V_58 = F_200 ( V_166 , V_3 ) ;
if ( V_58 < 0 ) {
F_32 ( V_3 ) ;
V_3 = F_198 ( V_58 ) ;
} else {
V_3 = F_196 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_201 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_74 )
{
struct V_3 * V_3 ;
int V_58 ;
V_210:
V_3 = F_199 ( V_2 , V_7 , F_200 , V_166 , V_74 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_51;
F_139 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_105 ( V_3 ) ;
F_32 ( V_3 ) ;
goto V_210;
}
if ( F_17 ( V_3 ) ) {
F_105 ( V_3 ) ;
goto V_51;
}
V_58 = F_200 ( V_166 , V_3 ) ;
if ( V_58 < 0 ) {
F_32 ( V_3 ) ;
return F_198 ( V_58 ) ;
} else {
V_3 = F_196 ( V_3 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
}
V_51:
F_142 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_202 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_166 )
{
return F_201 ( V_2 , V_7 , F_200 , V_166 , F_203 ( V_2 ) ) ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_74 )
{
T_9 * F_200 = ( T_9 * ) V_2 -> V_24 -> V_153 ;
return F_201 ( V_2 , V_7 , F_200 , NULL , V_74 ) ;
}
inline T_6 F_205 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_132 * V_132 = V_123 -> V_131 -> V_57 ;
unsigned long V_212 = F_206 ( V_213 ) ;
T_1 V_162 ;
if ( ! F_162 ( V_211 ) )
return 0 ;
if ( V_158 -> V_163 & V_214 )
V_158 -> V_161 = F_51 ( V_132 ) ;
V_162 = V_158 -> V_161 ;
if ( V_212 != V_215 ) {
if ( V_158 -> V_161 >= V_212 ) {
F_207 ( V_216 , V_71 , 0 ) ;
return - V_217 ;
}
F_208 ( V_211 , V_212 - ( unsigned long ) V_162 ) ;
}
if ( F_74 ( V_162 + F_162 ( V_211 ) > V_218 &&
! ( V_123 -> V_219 & V_220 ) ) ) {
if ( V_162 >= V_218 )
return - V_217 ;
F_208 ( V_211 , V_218 - ( unsigned long ) V_162 ) ;
}
if ( F_74 ( V_162 >= V_132 -> V_199 -> V_221 ) )
return - V_217 ;
F_208 ( V_211 , V_132 -> V_199 -> V_221 - V_162 ) ;
return F_162 ( V_211 ) ;
}
int F_209 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_28 ,
struct V_3 * * V_103 , void * * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_24 ;
return V_225 -> V_226 ( V_123 , V_2 , V_162 , V_222 , V_28 ,
V_103 , V_223 ) ;
}
int F_210 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_227 ,
struct V_3 * V_3 , void * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_24 ;
return V_225 -> V_228 ( V_123 , V_2 , V_162 , V_222 , V_227 , V_3 , V_223 ) ;
}
T_6
F_211 ( struct V_157 * V_158 , struct V_129 * V_211 , T_1 V_162 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_57 ;
T_6 V_130 ;
T_7 V_229 ;
T_2 V_33 ;
struct V_129 V_166 ;
V_229 = F_162 ( V_211 ) ;
V_33 = ( V_162 + V_229 - 1 ) >> V_46 ;
V_130 = F_53 ( V_2 , V_162 , V_162 + V_229 - 1 ) ;
if ( V_130 )
goto V_51;
if ( V_2 -> V_13 ) {
V_130 = F_212 ( V_2 ,
V_162 >> V_46 , V_33 ) ;
if ( V_130 ) {
if ( V_130 == - V_230 )
return 0 ;
goto V_51;
}
}
V_166 = * V_211 ;
V_130 = V_2 -> V_24 -> V_167 ( V_158 , & V_166 , V_162 ) ;
if ( V_2 -> V_13 ) {
F_212 ( V_2 ,
V_162 >> V_46 , V_33 ) ;
}
if ( V_130 > 0 ) {
V_162 += V_130 ;
F_168 ( V_211 , V_130 ) ;
if ( V_162 > F_51 ( V_132 ) && ! F_213 ( V_132 -> V_231 ) ) {
F_214 ( V_132 , V_162 ) ;
F_215 ( V_132 ) ;
}
V_158 -> V_161 = V_162 ;
}
V_51:
return V_130 ;
}
struct V_3 * F_216 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_28 )
{
struct V_3 * V_3 ;
int V_105 = V_107 | V_109 | V_111 | V_110 ;
if ( V_28 & V_232 )
V_105 |= V_113 ;
V_3 = F_140 ( V_2 , V_7 , V_105 ,
F_203 ( V_2 ) ) ;
if ( V_3 )
F_192 ( V_3 ) ;
return V_3 ;
}
T_6 F_217 ( struct V_123 * V_123 ,
struct V_129 * V_54 , T_1 V_162 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
const struct V_224 * V_24 = V_2 -> V_24 ;
long V_233 = 0 ;
T_6 V_130 = 0 ;
unsigned int V_28 = 0 ;
if ( ! F_218 ( V_54 ) )
V_28 |= V_234 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_235 ;
T_7 V_227 ;
void * V_223 ;
V_8 = ( V_162 & ( V_138 - 1 ) ) ;
V_235 = F_219 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_236:
if ( F_74 ( F_220 ( V_54 , V_235 ) ) ) {
V_233 = - V_151 ;
break;
}
V_233 = V_24 -> V_226 ( V_123 , V_2 , V_162 , V_235 , V_28 ,
& V_3 , & V_223 ) ;
if ( F_74 ( V_233 < 0 ) )
break;
if ( F_159 ( V_2 ) )
F_160 ( V_3 ) ;
V_227 = F_221 ( V_3 , V_54 , V_8 , V_235 ) ;
F_160 ( V_3 ) ;
V_233 = V_24 -> V_228 ( V_123 , V_2 , V_162 , V_235 , V_227 ,
V_3 , V_223 ) ;
if ( F_74 ( V_233 < 0 ) )
break;
V_227 = V_233 ;
F_49 () ;
F_168 ( V_54 , V_227 ) ;
if ( F_74 ( V_227 == 0 ) ) {
V_235 = F_219 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_236;
}
V_162 += V_227 ;
V_130 += V_227 ;
F_222 ( V_2 ) ;
if ( F_223 ( V_71 ) ) {
V_233 = - V_237 ;
break;
}
} while ( F_162 ( V_54 ) );
return V_130 ? V_130 : V_233 ;
}
T_6 F_224 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_57 ;
T_6 V_130 = 0 ;
T_6 V_58 ;
T_6 V_233 ;
V_71 -> V_238 = F_225 ( V_132 ) ;
V_58 = F_226 ( V_123 ) ;
if ( V_58 )
goto V_51;
V_58 = F_190 ( V_123 ) ;
if ( V_58 )
goto V_51;
if ( V_158 -> V_163 & V_164 ) {
T_1 V_162 , V_239 ;
V_130 = F_211 ( V_158 , V_211 , V_158 -> V_161 ) ;
if ( V_130 < 0 || ! F_162 ( V_211 ) || F_169 ( V_132 ) )
goto V_51;
V_233 = F_217 ( V_123 , V_211 , V_162 = V_158 -> V_161 ) ;
if ( F_74 ( V_233 < 0 ) ) {
V_58 = V_233 ;
goto V_51;
}
V_239 = V_162 + V_233 - 1 ;
V_58 = F_53 ( V_2 , V_162 , V_239 ) ;
if ( V_58 == 0 ) {
V_158 -> V_161 = V_239 + 1 ;
V_130 += V_233 ;
F_227 ( V_2 ,
V_162 >> V_46 ,
V_239 >> V_46 ) ;
} else {
}
} else {
V_130 = F_217 ( V_123 , V_211 , V_158 -> V_161 ) ;
if ( F_178 ( V_130 > 0 ) )
V_158 -> V_161 += V_130 ;
}
V_51:
V_71 -> V_238 = NULL ;
return V_130 ? V_130 : V_58 ;
}
T_6 F_228 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_132 * V_132 = V_123 -> V_131 -> V_57 ;
T_6 V_26 ;
F_229 ( & V_132 -> V_240 ) ;
V_26 = F_205 ( V_158 , V_211 ) ;
if ( V_26 > 0 )
V_26 = F_224 ( V_158 , V_211 ) ;
F_230 ( & V_132 -> V_240 ) ;
if ( V_26 > 0 ) {
T_6 V_58 ;
V_58 = F_231 ( V_123 , V_158 -> V_161 - V_26 , V_26 ) ;
if ( V_58 < 0 )
V_26 = V_58 ;
}
return V_26 ;
}
int F_232 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_233 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_24 -> V_241 )
return V_2 -> V_24 -> V_241 ( V_3 , V_14 ) ;
return F_234 ( V_3 ) ;
}
