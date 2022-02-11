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
void F_15 ( struct V_3 * V_3 , void * V_4 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
F_16 ( V_3 ) ;
if ( F_17 ( V_3 ) && F_18 ( V_3 ) )
F_19 ( V_3 ) ;
else
F_20 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_21 ( V_3 ) )
F_22 ( V_3 , V_24 ) ;
if ( F_23 ( V_3 ) )
F_22 ( V_3 , V_25 ) ;
F_24 ( F_25 ( V_3 ) ) ;
if ( F_26 ( F_27 ( V_3 ) ) )
F_28 ( V_3 , V_2 , V_23 ,
F_29 ( V_2 -> V_26 ) ) ;
}
void F_30 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
struct V_22 * V_23 ;
unsigned long V_27 ;
void (* F_31)( struct V_3 * );
F_24 ( ! F_3 ( V_3 ) ) ;
F_31 = V_2 -> V_28 -> F_31 ;
V_23 = F_32 ( V_3 ) ;
F_33 ( & V_2 -> V_29 , V_27 ) ;
F_15 ( V_3 , NULL , V_23 ) ;
F_34 ( & V_2 -> V_29 , V_27 ) ;
F_35 ( V_23 ) ;
if ( F_31 )
F_31 ( V_3 ) ;
F_36 ( V_3 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( F_7 ( V_31 , & V_2 -> V_27 ) &&
F_38 ( V_31 , & V_2 -> V_27 ) )
V_30 = - V_32 ;
if ( F_7 ( V_33 , & V_2 -> V_27 ) &&
F_38 ( V_33 , & V_2 -> V_27 ) )
V_30 = - V_34 ;
return V_30 ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 , int V_37 )
{
int V_30 ;
struct V_38 V_39 = {
. V_37 = V_37 ,
. V_40 = V_41 ,
. V_42 = V_35 ,
. V_43 = V_36 ,
} ;
if ( ! F_40 ( V_2 ) )
return 0 ;
F_41 ( & V_39 , V_2 -> V_26 ) ;
V_30 = F_42 ( V_2 , & V_39 ) ;
F_43 ( & V_39 ) ;
return V_30 ;
}
static inline int F_44 ( struct V_1 * V_2 ,
int V_37 )
{
return F_39 ( V_2 , 0 , V_44 , V_37 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_45 ) ;
}
int F_46 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 )
{
return F_39 ( V_2 , V_35 , V_36 , V_45 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_46 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
T_1 V_47 , T_1 V_48 )
{
T_2 V_7 = V_47 >> V_49 ;
T_2 V_36 = V_48 >> V_49 ;
struct V_50 V_51 ;
int V_52 ;
int V_30 = 0 ;
if ( V_48 < V_47 )
goto V_53;
F_49 ( & V_51 , 0 ) ;
while ( ( V_7 <= V_36 ) &&
( V_52 = F_50 ( & V_51 , V_2 , & V_7 ,
V_54 ,
F_51 ( V_36 - V_7 , ( T_2 ) V_55 - 1 ) + 1 ) ) != 0 ) {
unsigned V_56 ;
for ( V_56 = 0 ; V_56 < V_52 ; V_56 ++ ) {
struct V_3 * V_3 = V_51 . V_57 [ V_56 ] ;
if ( V_3 -> V_7 > V_36 )
continue;
F_52 ( V_3 ) ;
if ( F_53 ( V_3 ) )
V_30 = - V_34 ;
}
F_54 ( & V_51 ) ;
F_55 () ;
}
V_53:
return V_30 ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_47 ,
T_1 V_48 )
{
int V_30 , V_58 ;
V_30 = F_48 ( V_2 , V_47 , V_48 ) ;
V_58 = F_37 ( V_2 ) ;
if ( ! V_30 )
V_30 = V_58 ;
return V_30 ;
}
void F_57 ( struct V_1 * V_2 )
{
T_1 V_59 = F_58 ( V_2 -> V_26 ) ;
if ( V_59 == 0 )
return;
F_48 ( V_2 , 0 , V_59 - 1 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
T_1 V_59 = F_58 ( V_2 -> V_26 ) ;
if ( V_59 == 0 )
return 0 ;
return F_56 ( V_2 , 0 , V_59 - 1 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
if ( V_2 -> V_13 ) {
V_60 = F_45 ( V_2 ) ;
if ( V_60 != - V_34 ) {
int V_61 = F_59 ( V_2 ) ;
if ( ! V_60 )
V_60 = V_61 ;
}
} else {
V_60 = F_37 ( V_2 ) ;
}
return V_60 ;
}
int F_61 ( struct V_1 * V_2 ,
T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 ;
if ( V_2 -> V_13 ) {
V_60 = F_39 ( V_2 , V_62 , V_63 ,
V_45 ) ;
if ( V_60 != - V_34 ) {
int V_61 = F_56 ( V_2 ,
V_62 , V_63 ) ;
if ( ! V_60 )
V_60 = V_61 ;
}
} else {
V_60 = F_37 ( V_2 ) ;
}
return V_60 ;
}
int F_62 ( struct V_3 * V_64 , struct V_3 * V_65 , T_3 V_14 )
{
int error ;
F_63 ( ! F_3 ( V_64 ) , V_64 ) ;
F_63 ( ! F_3 ( V_65 ) , V_65 ) ;
F_63 ( V_65 -> V_2 , V_65 ) ;
error = F_64 ( V_14 & ~ V_66 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_64 -> V_2 ;
void (* F_31)( struct V_3 * );
struct V_22 * V_23 ;
unsigned long V_27 ;
T_2 V_8 = V_64 -> V_7 ;
F_31 = V_2 -> V_28 -> F_31 ;
F_65 ( V_65 ) ;
V_65 -> V_2 = V_2 ;
V_65 -> V_7 = V_8 ;
V_23 = F_32 ( V_64 ) ;
F_33 ( & V_2 -> V_29 , V_27 ) ;
F_15 ( V_64 , NULL , V_23 ) ;
error = F_66 ( & V_2 -> V_11 , V_8 , V_65 ) ;
F_24 ( error ) ;
V_2 -> V_13 ++ ;
if ( ! F_21 ( V_65 ) )
F_67 ( V_65 , V_24 ) ;
if ( F_23 ( V_65 ) )
F_67 ( V_65 , V_25 ) ;
F_34 ( & V_2 -> V_29 , V_27 ) ;
F_35 ( V_23 ) ;
F_68 ( V_64 , V_65 ) ;
F_69 () ;
if ( F_31 )
F_31 ( V_64 ) ;
F_36 ( V_64 ) ;
}
return error ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_67 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_71 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_68 ;
V_68 = F_72 ( V_10 , & V_2 -> V_29 ) ;
if ( ! F_73 ( V_68 ) )
return - V_69 ;
if ( V_67 )
* V_67 = V_68 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_74 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_75 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_76 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_77 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_67 )
{
int V_70 = F_21 ( V_3 ) ;
struct V_22 * V_23 ;
int error ;
F_63 ( ! F_3 ( V_3 ) , V_3 ) ;
F_63 ( F_23 ( V_3 ) , V_3 ) ;
if ( ! V_70 ) {
error = F_78 ( V_3 , V_71 -> V_72 ,
V_14 , & V_23 ) ;
if ( error )
return error ;
}
error = F_79 ( V_14 & ~ V_66 ) ;
if ( error ) {
if ( ! V_70 )
F_80 ( V_3 , V_23 ) ;
return error ;
}
F_65 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_81 ( & V_2 -> V_29 ) ;
error = F_70 ( V_2 , V_3 , V_67 ) ;
F_69 () ;
if ( F_82 ( error ) )
goto V_73;
if ( ! V_70 )
F_67 ( V_3 , V_24 ) ;
F_83 ( & V_2 -> V_29 ) ;
if ( ! V_70 )
F_84 ( V_3 , V_23 , false ) ;
F_85 ( V_3 ) ;
return 0 ;
V_73:
V_3 -> V_2 = NULL ;
F_83 ( & V_2 -> V_29 ) ;
if ( ! V_70 )
F_80 ( V_3 , V_23 ) ;
F_36 ( V_3 ) ;
return error ;
}
int F_86 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_77 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_87 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_30 ;
F_88 ( V_3 ) ;
V_30 = F_77 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_82 ( V_30 ) )
F_89 ( V_3 ) ;
else {
if ( V_4 && F_90 ( V_4 ) ) {
F_91 ( V_3 ) ;
F_92 ( V_3 ) ;
} else
F_93 ( V_3 ) ;
F_94 ( V_3 ) ;
}
return V_30 ;
}
struct V_3 * F_95 ( T_3 V_74 )
{
int V_75 ;
struct V_3 * V_3 ;
if ( F_96 () ) {
unsigned int V_76 ;
do {
V_76 = F_97 () ;
V_75 = F_98 () ;
V_3 = F_99 ( V_75 , V_74 , 0 ) ;
} while ( ! V_3 && F_100 ( V_76 ) );
return V_3 ;
}
return F_101 ( V_74 , 0 ) ;
}
T_4 * F_102 ( struct V_3 * V_3 )
{
const struct V_77 * V_77 = F_103 ( V_3 ) ;
return & V_77 -> V_78 [ F_104 ( V_3 , V_77 -> V_79 ) ] ;
}
void F_105 ( struct V_3 * V_3 , int V_80 )
{
F_106 ( V_81 , & V_3 -> V_27 , V_80 ) ;
if ( F_7 ( V_80 , & V_3 -> V_27 ) )
F_107 ( F_102 ( V_3 ) , & V_81 , V_82 ,
V_83 ) ;
}
int F_108 ( struct V_3 * V_3 , int V_80 )
{
F_106 ( V_81 , & V_3 -> V_27 , V_80 ) ;
if ( ! F_7 ( V_80 , & V_3 -> V_27 ) )
return 0 ;
return F_107 ( F_102 ( V_3 ) , & V_81 ,
V_82 , V_84 ) ;
}
int F_109 ( struct V_3 * V_3 ,
int V_80 , unsigned long V_85 )
{
F_106 ( V_81 , & V_3 -> V_27 , V_80 ) ;
V_81 . V_86 . V_85 = V_87 + V_85 ;
if ( ! F_7 ( V_80 , & V_3 -> V_27 ) )
return 0 ;
return F_107 ( F_102 ( V_3 ) , & V_81 ,
V_88 , V_84 ) ;
}
void F_110 ( struct V_3 * V_3 , T_5 * V_89 )
{
T_4 * V_90 = F_102 ( V_3 ) ;
unsigned long V_27 ;
F_33 ( & V_90 -> V_91 , V_27 ) ;
F_111 ( V_90 , V_89 ) ;
F_34 ( & V_90 -> V_91 , V_27 ) ;
}
void F_112 ( struct V_3 * V_3 )
{
F_63 ( ! F_3 ( V_3 ) , V_3 ) ;
F_113 ( V_92 , & V_3 -> V_27 ) ;
F_114 () ;
F_115 ( V_3 , V_92 ) ;
}
void F_116 ( struct V_3 * V_3 )
{
if ( F_117 ( V_3 ) ) {
F_118 ( V_3 ) ;
F_119 ( V_3 ) ;
}
if ( ! F_120 ( V_3 ) )
F_121 () ;
F_114 () ;
F_115 ( V_3 , V_93 ) ;
}
void F_122 ( struct V_3 * V_3 , int V_94 , int V_60 )
{
if ( V_94 == V_95 ) {
if ( ! V_60 ) {
F_123 ( V_3 ) ;
} else {
F_124 ( V_3 ) ;
F_125 ( V_3 ) ;
}
F_112 ( V_3 ) ;
} else {
if ( V_60 ) {
F_125 ( V_3 ) ;
if ( V_3 -> V_2 )
F_126 ( V_3 -> V_2 , V_60 ) ;
}
F_116 ( V_3 ) ;
}
}
void F_127 ( struct V_3 * V_3 )
{
F_106 ( V_81 , & V_3 -> V_27 , V_92 ) ;
F_128 ( F_102 ( V_3 ) , & V_81 , V_82 ,
V_83 ) ;
}
int F_129 ( struct V_3 * V_3 )
{
F_106 ( V_81 , & V_3 -> V_27 , V_92 ) ;
return F_128 ( F_102 ( V_3 ) , & V_81 ,
V_82 , V_84 ) ;
}
int F_130 ( struct V_3 * V_3 , struct V_96 * V_72 ,
unsigned int V_27 )
{
if ( V_27 & V_97 ) {
if ( V_27 & V_98 )
return 0 ;
F_131 ( & V_72 -> V_99 ) ;
if ( V_27 & V_100 )
F_132 ( V_3 ) ;
else
F_133 ( V_3 ) ;
return 0 ;
} else {
if ( V_27 & V_100 ) {
int V_30 ;
V_30 = F_129 ( V_3 ) ;
if ( V_30 ) {
F_131 ( & V_72 -> V_99 ) ;
return 0 ;
}
} else
F_127 ( V_3 ) ;
return 1 ;
}
}
T_2 F_134 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_56 ;
for ( V_56 = 0 ; V_56 < V_101 ; V_56 ++ ) {
struct V_3 * V_3 ;
V_3 = F_135 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_73 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_136 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_56 ;
for ( V_56 = 0 ; V_56 < V_101 ; V_56 ++ ) {
struct V_3 * V_3 ;
V_3 = F_135 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_73 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_102 )
break;
}
return V_7 ;
}
struct V_3 * F_137 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_103 ;
struct V_3 * V_3 ;
F_138 () ;
V_104:
V_3 = NULL ;
V_103 = F_139 ( & V_2 -> V_11 , V_8 ) ;
if ( V_103 ) {
V_3 = F_140 ( V_103 ) ;
if ( F_82 ( ! V_3 ) )
goto V_53;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) )
goto V_104;
goto V_53;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_103 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
}
V_53:
F_144 () ;
return V_3 ;
}
struct V_3 * F_145 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_137 ( V_2 , V_8 ) ;
if ( V_3 && ! F_141 ( V_3 ) ) {
F_146 ( V_3 ) ;
if ( F_82 ( V_3 -> V_2 != V_2 ) ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
goto V_104;
}
F_63 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_147 ( struct V_1 * V_2 , T_2 V_8 ,
int V_105 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_137 ( V_2 , V_8 ) ;
if ( F_73 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_106;
if ( V_105 & V_107 ) {
if ( V_105 & V_108 ) {
if ( ! F_148 ( V_3 ) ) {
F_36 ( V_3 ) ;
return NULL ;
}
} else {
F_146 ( V_3 ) ;
}
if ( F_82 ( V_3 -> V_2 != V_2 ) ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
goto V_104;
}
F_63 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_105 & V_109 ) )
F_149 ( V_3 ) ;
V_106:
if ( ! V_3 && ( V_105 & V_110 ) ) {
int V_60 ;
if ( ( V_105 & V_111 ) && F_150 ( V_2 ) )
V_14 |= V_112 ;
if ( V_105 & V_113 )
V_14 &= ~ V_114 ;
V_3 = F_95 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_26 ( ! ( V_105 & V_107 ) ) )
V_105 |= V_107 ;
if ( V_105 & V_109 )
F_151 ( V_3 ) ;
V_60 = F_87 ( V_3 , V_2 , V_8 ,
V_14 & V_115 ) ;
if ( F_82 ( V_60 ) ) {
F_36 ( V_3 ) ;
V_3 = NULL ;
if ( V_60 == - V_69 )
goto V_104;
}
}
return V_3 ;
}
unsigned F_152 ( struct V_1 * V_2 ,
T_2 V_35 , unsigned int V_116 ,
struct V_3 * * V_117 , T_2 * V_118 )
{
void * * V_10 ;
unsigned int V_30 = 0 ;
struct V_119 V_120 ;
if ( ! V_116 )
return 0 ;
F_138 () ;
V_121:
F_153 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_140 ( V_10 ) ;
if ( F_82 ( ! V_3 ) )
continue;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) )
goto V_121;
goto V_122;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_10 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
V_122:
V_118 [ V_30 ] = V_120 . V_7 ;
V_117 [ V_30 ] = V_3 ;
if ( ++ V_30 == V_116 )
break;
}
F_144 () ;
return V_30 ;
}
unsigned F_154 ( struct V_1 * V_2 , T_2 V_35 ,
unsigned int V_52 , struct V_3 * * V_57 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_30 = 0 ;
if ( F_82 ( ! V_52 ) )
return 0 ;
F_138 () ;
V_121:
F_153 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_140 ( V_10 ) ;
if ( F_82 ( ! V_3 ) )
continue;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) ) {
F_155 ( V_120 . V_7 ) ;
goto V_121;
}
continue;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_10 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
V_57 [ V_30 ] = V_3 ;
if ( ++ V_30 == V_52 )
break;
}
F_144 () ;
return V_30 ;
}
unsigned F_156 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_52 , struct V_3 * * V_57 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned int V_30 = 0 ;
if ( F_82 ( ! V_52 ) )
return 0 ;
F_138 () ;
V_121:
F_157 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_104:
V_3 = F_140 ( V_10 ) ;
if ( F_82 ( ! V_3 ) )
break;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) ) {
goto V_121;
}
break;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_10 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_120 . V_7 ) {
F_36 ( V_3 ) ;
break;
}
V_57 [ V_30 ] = V_3 ;
if ( ++ V_30 == V_52 )
break;
}
F_144 () ;
return V_30 ;
}
unsigned F_158 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_52 , struct V_3 * * V_57 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_30 = 0 ;
if ( F_82 ( ! V_52 ) )
return 0 ;
F_138 () ;
V_121:
F_159 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_104:
V_3 = F_140 ( V_10 ) ;
if ( F_82 ( ! V_3 ) )
continue;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) ) {
goto V_121;
}
continue;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_10 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
V_57 [ V_30 ] = V_3 ;
if ( ++ V_30 == V_52 )
break;
}
F_144 () ;
if ( V_30 )
* V_7 = V_57 [ V_30 - 1 ] -> V_7 + 1 ;
return V_30 ;
}
static void F_160 ( struct V_123 * V_124 ,
struct V_125 * V_126 )
{
V_126 -> V_127 /= 4 ;
}
static T_6 F_161 ( struct V_123 * V_124 , T_1 * V_128 ,
struct V_129 * V_120 , T_6 V_130 )
{
struct V_1 * V_2 = V_124 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_26 ;
struct V_125 * V_126 = & V_124 -> V_133 ;
T_2 V_7 ;
T_2 V_134 ;
T_2 V_135 ;
unsigned long V_8 ;
unsigned int V_136 ;
int error = 0 ;
V_7 = * V_128 >> V_49 ;
V_135 = V_126 -> V_137 >> V_49 ;
V_136 = V_126 -> V_137 & ( V_138 - 1 ) ;
V_134 = ( * V_128 + V_120 -> V_139 + V_138 - 1 ) >> V_49 ;
V_8 = * V_128 & ~ V_140 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_141 ;
T_1 V_142 ;
unsigned long V_143 , V_30 ;
F_55 () ;
V_144:
V_3 = F_162 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_163 ( V_2 ,
V_126 , V_124 ,
V_7 , V_134 - V_7 ) ;
V_3 = F_162 ( V_2 , V_7 ) ;
if ( F_82 ( V_3 == NULL ) )
goto V_145;
}
if ( F_164 ( V_3 ) ) {
F_165 ( V_2 ,
V_126 , V_124 , V_3 ,
V_7 , V_134 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_132 -> V_146 == V_49 ||
! V_2 -> V_28 -> V_147 )
goto V_148;
if ( ! F_148 ( V_3 ) )
goto V_148;
if ( ! V_3 -> V_2 )
goto V_149;
if ( ! V_2 -> V_28 -> V_147 ( V_3 ,
V_8 , V_120 -> V_139 ) )
goto V_149;
F_112 ( V_3 ) ;
}
V_150:
V_142 = F_58 ( V_132 ) ;
V_141 = ( V_142 - 1 ) >> V_49 ;
if ( F_82 ( ! V_142 || V_7 > V_141 ) ) {
F_36 ( V_3 ) ;
goto V_53;
}
V_143 = V_138 ;
if ( V_7 == V_141 ) {
V_143 = ( ( V_142 - 1 ) & ~ V_140 ) + 1 ;
if ( V_143 <= V_8 ) {
F_36 ( V_3 ) ;
goto V_53;
}
}
V_143 = V_143 - V_8 ;
if ( F_166 ( V_2 ) )
F_167 ( V_3 ) ;
if ( V_135 != V_7 || V_8 != V_136 )
F_149 ( V_3 ) ;
V_135 = V_7 ;
V_30 = F_168 ( V_3 , V_8 , V_143 , V_120 ) ;
V_8 += V_30 ;
V_7 += V_8 >> V_49 ;
V_8 &= ~ V_140 ;
V_136 = V_8 ;
F_36 ( V_3 ) ;
V_130 += V_30 ;
if ( ! F_169 ( V_120 ) )
goto V_53;
if ( V_30 < V_143 ) {
error = - V_151 ;
goto V_53;
}
continue;
V_148:
error = F_170 ( V_3 ) ;
if ( F_82 ( error ) )
goto V_152;
V_149:
if ( ! V_3 -> V_2 ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_112 ( V_3 ) ;
goto V_150;
}
V_153:
F_171 ( V_3 ) ;
error = V_2 -> V_28 -> V_153 ( V_124 , V_3 ) ;
if ( F_82 ( error ) ) {
if ( error == V_154 ) {
F_36 ( V_3 ) ;
error = 0 ;
goto V_144;
}
goto V_152;
}
if ( ! F_17 ( V_3 ) ) {
error = F_170 ( V_3 ) ;
if ( F_82 ( error ) )
goto V_152;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
goto V_144;
}
F_112 ( V_3 ) ;
F_160 ( V_124 , V_126 ) ;
error = - V_34 ;
goto V_152;
}
F_112 ( V_3 ) ;
}
goto V_150;
V_152:
F_36 ( V_3 ) ;
goto V_53;
V_145:
V_3 = F_172 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_155 ;
goto V_53;
}
error = F_87 ( V_3 , V_2 , V_7 ,
F_173 ( V_2 , V_156 ) ) ;
if ( error ) {
F_36 ( V_3 ) ;
if ( error == - V_69 ) {
error = 0 ;
goto V_144;
}
goto V_53;
}
goto V_153;
}
V_53:
V_126 -> V_137 = V_135 ;
V_126 -> V_137 <<= V_49 ;
V_126 -> V_137 |= V_136 ;
* V_128 = ( ( T_1 ) V_7 << V_49 ) + V_8 ;
F_174 ( V_124 ) ;
return V_130 ? V_130 : error ;
}
T_6
F_175 ( struct V_157 * V_158 , struct V_129 * V_120 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
T_6 V_160 = 0 ;
T_1 * V_128 = & V_158 -> V_161 ;
T_1 V_162 = * V_128 ;
if ( V_158 -> V_163 & V_164 ) {
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_26 ;
T_7 V_139 = F_169 ( V_120 ) ;
T_1 V_165 ;
if ( ! V_139 )
goto V_53;
V_165 = F_58 ( V_132 ) ;
V_160 = F_61 ( V_2 , V_162 ,
V_162 + V_139 - 1 ) ;
if ( ! V_160 ) {
struct V_129 V_166 = * V_120 ;
V_160 = V_2 -> V_28 -> V_167 ( V_158 , & V_166 , V_162 ) ;
}
if ( V_160 > 0 ) {
* V_128 = V_162 + V_160 ;
F_176 ( V_120 , V_160 ) ;
}
if ( V_160 < 0 || ! F_169 ( V_120 ) || * V_128 >= V_165 ||
F_177 ( V_132 ) ) {
F_174 ( V_123 ) ;
goto V_53;
}
}
V_160 = F_161 ( V_123 , V_128 , V_120 , V_160 ) ;
V_53:
return V_160 ;
}
static int F_178 ( struct V_123 * V_123 , T_2 V_8 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_3 * V_3 ;
int V_30 ;
do {
V_3 = F_172 ( V_2 ) ;
if ( ! V_3 )
return - V_155 ;
V_30 = F_87 ( V_3 , V_2 , V_8 ,
F_173 ( V_2 , V_156 ) ) ;
if ( V_30 == 0 )
V_30 = V_2 -> V_28 -> V_153 ( V_123 , V_3 ) ;
else if ( V_30 == - V_69 )
V_30 = 0 ;
F_36 ( V_3 ) ;
} while ( V_30 == V_154 );
return V_30 ;
}
static void F_179 ( struct V_168 * V_169 ,
struct V_125 * V_126 ,
struct V_123 * V_123 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( ! V_126 -> V_127 )
return;
if ( V_169 -> V_170 & V_172 ) {
F_163 ( V_2 , V_126 , V_123 , V_8 ,
V_126 -> V_127 ) ;
return;
}
if ( V_126 -> V_173 < V_174 * 10 )
V_126 -> V_173 ++ ;
if ( V_126 -> V_173 > V_174 )
return;
V_126 -> V_35 = F_180 ( long , 0 , V_8 - V_126 -> V_127 / 2 ) ;
V_126 -> V_165 = V_126 -> V_127 ;
V_126 -> V_175 = V_126 -> V_127 / 4 ;
F_181 ( V_126 , V_2 , V_123 ) ;
}
static void F_182 ( struct V_168 * V_169 ,
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
if ( F_164 ( V_3 ) )
F_165 ( V_2 , V_126 , V_123 ,
V_3 , V_8 , V_126 -> V_127 ) ;
}
int F_183 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
int error ;
struct V_123 * V_123 = V_169 -> V_178 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_125 * V_126 = & V_123 -> V_133 ;
struct V_132 * V_132 = V_2 -> V_26 ;
T_2 V_8 = V_177 -> V_179 ;
struct V_3 * V_3 ;
T_1 V_165 ;
int V_30 = 0 ;
V_165 = F_184 ( F_58 ( V_132 ) , V_138 ) ;
if ( V_8 >= V_165 >> V_49 )
return V_180 ;
V_3 = F_162 ( V_2 , V_8 ) ;
if ( F_185 ( V_3 ) && ! ( V_177 -> V_27 & V_181 ) ) {
F_182 ( V_169 , V_126 , V_123 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_179 ( V_169 , V_126 , V_123 , V_8 ) ;
F_186 ( V_182 ) ;
F_187 ( V_169 -> V_183 , V_182 ) ;
V_30 = V_184 ;
V_185:
V_3 = F_162 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_145;
}
if ( ! F_188 ( V_3 , V_169 -> V_183 , V_177 -> V_27 ) ) {
F_36 ( V_3 ) ;
return V_30 | V_186 ;
}
if ( F_82 ( V_3 -> V_2 != V_2 ) ) {
F_112 ( V_3 ) ;
F_189 ( V_3 ) ;
goto V_185;
}
F_63 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_82 ( ! F_17 ( V_3 ) ) )
goto V_187;
V_165 = F_184 ( F_58 ( V_132 ) , V_138 ) ;
if ( F_82 ( V_8 >= V_165 >> V_49 ) ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
return V_180 ;
}
V_177 -> V_3 = V_3 ;
return V_30 | V_188 ;
V_145:
error = F_178 ( V_123 , V_8 ) ;
if ( error >= 0 )
goto V_185;
if ( error == - V_155 )
return V_189 ;
return V_180 ;
V_187:
F_171 ( V_3 ) ;
error = V_2 -> V_28 -> V_153 ( V_123 , V_3 ) ;
if ( ! error ) {
F_133 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_34 ;
}
F_36 ( V_3 ) ;
if ( ! error || error == V_154 )
goto V_185;
F_160 ( V_123 , V_126 ) ;
return V_180 ;
}
void F_190 ( struct V_168 * V_169 , struct V_176 * V_177 )
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
F_138 () ;
F_153 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_120 . V_7 > V_177 -> V_194 )
break;
V_104:
V_3 = F_140 ( V_10 ) ;
if ( F_82 ( ! V_3 ) )
goto V_195;
if ( F_141 ( V_3 ) ) {
if ( F_142 ( V_3 ) )
break;
else
goto V_195;
}
if ( ! F_143 ( V_3 ) )
goto V_104;
if ( F_82 ( V_3 != * V_10 ) ) {
F_36 ( V_3 ) ;
goto V_104;
}
if ( ! F_17 ( V_3 ) ||
F_164 ( V_3 ) ||
F_191 ( V_3 ) )
goto V_196;
if ( ! F_148 ( V_3 ) )
goto V_196;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_197;
V_165 = F_184 ( F_58 ( V_2 -> V_26 ) , V_138 ) ;
if ( V_3 -> V_7 >= V_165 >> V_49 )
goto V_197;
V_193 = V_177 -> V_193 + V_3 -> V_7 - V_177 -> V_179 ;
if ( ! F_192 ( * V_193 ) )
goto V_197;
if ( V_123 -> V_133 . V_173 > 0 )
V_123 -> V_133 . V_173 -- ;
V_192 = V_190 + ( V_3 -> V_7 - V_177 -> V_179 ) * V_198 ;
F_193 ( V_169 , V_192 , V_3 , V_193 , false , false ) ;
F_112 ( V_3 ) ;
goto V_195;
V_197:
F_112 ( V_3 ) ;
V_196:
F_36 ( V_3 ) ;
V_195:
if ( V_120 . V_7 == V_177 -> V_194 )
break;
}
F_144 () ;
}
int F_194 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_3 * V_3 = V_177 -> V_3 ;
struct V_132 * V_132 = F_195 ( V_169 -> V_178 ) ;
int V_30 = V_188 ;
F_196 ( V_132 -> V_199 ) ;
F_197 ( V_169 -> V_178 ) ;
F_146 ( V_3 ) ;
if ( V_3 -> V_2 != V_132 -> V_200 ) {
F_112 ( V_3 ) ;
V_30 = V_201 ;
goto V_53;
}
F_198 ( V_3 ) ;
F_199 ( V_3 ) ;
V_53:
F_200 ( V_132 -> V_199 ) ;
return V_30 ;
}
int F_201 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
if ( ! V_2 -> V_28 -> V_153 )
return - V_202 ;
F_174 ( V_123 ) ;
V_169 -> V_203 = & V_204 ;
return 0 ;
}
int F_202 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 & V_205 ) && ( V_169 -> V_170 & V_206 ) )
return - V_207 ;
return F_201 ( V_123 , V_169 ) ;
}
int F_201 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
int F_202 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
static struct V_3 * F_203 ( struct V_3 * V_3 )
{
if ( ! F_204 ( V_3 ) ) {
F_133 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_36 ( V_3 ) ;
V_3 = F_205 ( - V_34 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_206 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_207)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_74 )
{
struct V_3 * V_3 ;
int V_60 ;
V_104:
V_3 = F_162 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_95 ( V_74 | V_209 ) ;
if ( ! V_3 )
return F_205 ( - V_155 ) ;
V_60 = F_87 ( V_3 , V_2 , V_7 , V_74 ) ;
if ( F_82 ( V_60 ) ) {
F_36 ( V_3 ) ;
if ( V_60 == - V_69 )
goto V_104;
return F_205 ( V_60 ) ;
}
V_60 = F_207 ( V_166 , V_3 ) ;
if ( V_60 < 0 ) {
F_36 ( V_3 ) ;
V_3 = F_205 ( V_60 ) ;
} else {
V_3 = F_203 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_208 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_207)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_74 )
{
struct V_3 * V_3 ;
int V_60 ;
V_210:
V_3 = F_206 ( V_2 , V_7 , F_207 , V_166 , V_74 ) ;
if ( F_204 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_53;
F_146 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_112 ( V_3 ) ;
F_36 ( V_3 ) ;
goto V_210;
}
if ( F_17 ( V_3 ) ) {
F_112 ( V_3 ) ;
goto V_53;
}
V_60 = F_207 ( V_166 , V_3 ) ;
if ( V_60 < 0 ) {
F_36 ( V_3 ) ;
return F_205 ( V_60 ) ;
} else {
V_3 = F_203 ( V_3 ) ;
if ( F_204 ( V_3 ) )
return V_3 ;
}
V_53:
F_149 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_209 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_207)( void * , struct V_3 * ) ,
void * V_166 )
{
return F_208 ( V_2 , V_7 , F_207 , V_166 , F_210 ( V_2 ) ) ;
}
struct V_3 * F_211 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_74 )
{
T_9 * F_207 = ( T_9 * ) V_2 -> V_28 -> V_153 ;
return F_208 ( V_2 , V_7 , F_207 , NULL , V_74 ) ;
}
inline T_6 F_212 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_132 * V_132 = V_123 -> V_131 -> V_26 ;
unsigned long V_212 = F_213 ( V_213 ) ;
T_1 V_162 ;
if ( ! F_169 ( V_211 ) )
return 0 ;
if ( V_158 -> V_163 & V_214 )
V_158 -> V_161 = F_58 ( V_132 ) ;
V_162 = V_158 -> V_161 ;
if ( V_212 != V_215 ) {
if ( V_158 -> V_161 >= V_212 ) {
F_214 ( V_216 , V_71 , 0 ) ;
return - V_217 ;
}
F_215 ( V_211 , V_212 - ( unsigned long ) V_162 ) ;
}
if ( F_82 ( V_162 + F_169 ( V_211 ) > V_218 &&
! ( V_123 -> V_219 & V_220 ) ) ) {
if ( V_162 >= V_218 )
return - V_217 ;
F_215 ( V_211 , V_218 - ( unsigned long ) V_162 ) ;
}
if ( F_82 ( V_162 >= V_132 -> V_199 -> V_221 ) )
return - V_217 ;
F_215 ( V_211 , V_132 -> V_199 -> V_221 - V_162 ) ;
return F_169 ( V_211 ) ;
}
int F_216 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_27 ,
struct V_3 * * V_103 , void * * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_28 ;
return V_225 -> V_226 ( V_123 , V_2 , V_162 , V_222 , V_27 ,
V_103 , V_223 ) ;
}
int F_217 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_227 ,
struct V_3 * V_3 , void * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_28 ;
return V_225 -> V_228 ( V_123 , V_2 , V_162 , V_222 , V_227 , V_3 , V_223 ) ;
}
T_6
F_218 ( struct V_157 * V_158 , struct V_129 * V_211 , T_1 V_162 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_26 ;
T_6 V_130 ;
T_7 V_229 ;
T_2 V_36 ;
struct V_129 V_166 ;
V_229 = F_169 ( V_211 ) ;
V_36 = ( V_162 + V_229 - 1 ) >> V_49 ;
V_130 = F_61 ( V_2 , V_162 , V_162 + V_229 - 1 ) ;
if ( V_130 )
goto V_53;
if ( V_2 -> V_13 ) {
V_130 = F_219 ( V_2 ,
V_162 >> V_49 , V_36 ) ;
if ( V_130 ) {
if ( V_130 == - V_230 )
return 0 ;
goto V_53;
}
}
V_166 = * V_211 ;
V_130 = V_2 -> V_28 -> V_167 ( V_158 , & V_166 , V_162 ) ;
if ( V_2 -> V_13 ) {
F_219 ( V_2 ,
V_162 >> V_49 , V_36 ) ;
}
if ( V_130 > 0 ) {
V_162 += V_130 ;
F_176 ( V_211 , V_130 ) ;
if ( V_162 > F_58 ( V_132 ) && ! F_220 ( V_132 -> V_231 ) ) {
F_221 ( V_132 , V_162 ) ;
F_222 ( V_132 ) ;
}
V_158 -> V_161 = V_162 ;
}
V_53:
return V_130 ;
}
struct V_3 * F_223 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_27 )
{
struct V_3 * V_3 ;
int V_105 = V_107 | V_109 | V_111 | V_110 ;
if ( V_27 & V_232 )
V_105 |= V_113 ;
V_3 = F_147 ( V_2 , V_7 , V_105 ,
F_210 ( V_2 ) ) ;
if ( V_3 )
F_199 ( V_3 ) ;
return V_3 ;
}
T_6 F_224 ( struct V_123 * V_123 ,
struct V_129 * V_56 , T_1 V_162 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
const struct V_224 * V_28 = V_2 -> V_28 ;
long V_233 = 0 ;
T_6 V_130 = 0 ;
unsigned int V_27 = 0 ;
if ( ! F_225 ( V_56 ) )
V_27 |= V_234 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_235 ;
T_7 V_227 ;
void * V_223 ;
V_8 = ( V_162 & ( V_138 - 1 ) ) ;
V_235 = F_226 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_236:
if ( F_82 ( F_227 ( V_56 , V_235 ) ) ) {
V_233 = - V_151 ;
break;
}
if ( F_228 ( V_71 ) ) {
V_233 = - V_237 ;
break;
}
V_233 = V_28 -> V_226 ( V_123 , V_2 , V_162 , V_235 , V_27 ,
& V_3 , & V_223 ) ;
if ( F_82 ( V_233 < 0 ) )
break;
if ( F_166 ( V_2 ) )
F_167 ( V_3 ) ;
V_227 = F_229 ( V_3 , V_56 , V_8 , V_235 ) ;
F_167 ( V_3 ) ;
V_233 = V_28 -> V_228 ( V_123 , V_2 , V_162 , V_235 , V_227 ,
V_3 , V_223 ) ;
if ( F_82 ( V_233 < 0 ) )
break;
V_227 = V_233 ;
F_55 () ;
F_176 ( V_56 , V_227 ) ;
if ( F_82 ( V_227 == 0 ) ) {
V_235 = F_226 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_236;
}
V_162 += V_227 ;
V_130 += V_227 ;
F_230 ( V_2 ) ;
} while ( F_169 ( V_56 ) );
return V_130 ? V_130 : V_233 ;
}
T_6 F_231 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_26 ;
T_6 V_130 = 0 ;
T_6 V_60 ;
T_6 V_233 ;
V_71 -> V_238 = F_232 ( V_132 ) ;
V_60 = F_233 ( V_123 ) ;
if ( V_60 )
goto V_53;
V_60 = F_197 ( V_123 ) ;
if ( V_60 )
goto V_53;
if ( V_158 -> V_163 & V_164 ) {
T_1 V_162 , V_239 ;
V_130 = F_218 ( V_158 , V_211 , V_158 -> V_161 ) ;
if ( V_130 < 0 || ! F_169 ( V_211 ) || F_177 ( V_132 ) )
goto V_53;
V_233 = F_224 ( V_123 , V_211 , V_162 = V_158 -> V_161 ) ;
if ( F_82 ( V_233 < 0 ) ) {
V_60 = V_233 ;
goto V_53;
}
V_239 = V_162 + V_233 - 1 ;
V_60 = F_61 ( V_2 , V_162 , V_239 ) ;
if ( V_60 == 0 ) {
V_158 -> V_161 = V_239 + 1 ;
V_130 += V_233 ;
F_234 ( V_2 ,
V_162 >> V_49 ,
V_239 >> V_49 ) ;
} else {
}
} else {
V_130 = F_224 ( V_123 , V_211 , V_158 -> V_161 ) ;
if ( F_185 ( V_130 > 0 ) )
V_158 -> V_161 += V_130 ;
}
V_53:
V_71 -> V_238 = NULL ;
return V_130 ? V_130 : V_60 ;
}
T_6 F_235 ( struct V_157 * V_158 , struct V_129 * V_211 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_132 * V_132 = V_123 -> V_131 -> V_26 ;
T_6 V_30 ;
F_236 ( & V_132 -> V_240 ) ;
V_30 = F_212 ( V_158 , V_211 ) ;
if ( V_30 > 0 )
V_30 = F_231 ( V_158 , V_211 ) ;
F_237 ( & V_132 -> V_240 ) ;
if ( V_30 > 0 ) {
T_6 V_60 ;
V_60 = F_238 ( V_123 , V_158 -> V_161 - V_30 , V_30 ) ;
if ( V_60 < 0 )
V_30 = V_60 ;
}
return V_30 ;
}
int F_239 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_24 ( ! F_3 ( V_3 ) ) ;
if ( F_240 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_28 -> V_241 )
return V_2 -> V_28 -> V_241 ( V_3 , V_14 ) ;
return F_241 ( V_3 ) ;
}
