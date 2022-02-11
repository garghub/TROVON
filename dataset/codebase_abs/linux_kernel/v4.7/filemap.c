static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! F_3 ( V_3 ) ) ;
V_6 = F_4 ( & V_2 -> V_7 , V_3 -> V_8 ,
V_4 ) ;
if ( V_4 ) {
V_2 -> V_9 ++ ;
F_5 () ;
}
V_2 -> V_10 -- ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
if ( V_4 )
F_7 ( V_6 ) ;
else
if ( F_8 ( & V_2 -> V_7 , V_6 ) )
return;
if ( ! F_9 ( V_2 ) && ! F_10 ( V_6 ) &&
F_11 ( & V_6 -> V_11 ) ) {
V_6 -> V_12 = V_2 ;
F_12 ( & V_13 , & V_6 -> V_11 ) ;
}
}
void F_13 ( struct V_3 * V_3 , void * V_4 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
F_14 ( V_3 ) ;
if ( F_15 ( V_3 ) && F_16 ( V_3 ) )
F_17 ( V_3 ) ;
else
F_18 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_3 ) , V_3 ) ;
if ( ! F_21 ( V_14 ) && F_22 ( F_20 ( V_3 ) ) ) {
int V_15 ;
F_23 ( L_1 ,
V_16 -> V_17 , F_24 ( V_3 ) ) ;
F_25 ( V_3 , L_2 ) ;
F_26 () ;
F_27 ( V_18 , V_19 ) ;
V_15 = F_28 ( V_3 ) ;
if ( F_29 ( V_2 ) &&
F_30 ( V_3 ) >= V_15 + 2 ) {
F_31 ( V_3 ) ;
F_32 ( V_3 , V_15 ) ;
}
}
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_33 ( V_3 ) )
F_34 ( V_3 , V_20 ) ;
if ( F_35 ( V_3 ) )
F_34 ( V_3 , V_21 ) ;
if ( F_36 ( F_37 ( V_3 ) ) )
F_38 ( V_3 , V_2 , F_39 ( V_2 -> V_22 ) ) ;
}
void F_40 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
unsigned long V_23 ;
void (* F_41)( struct V_3 * );
F_42 ( ! F_3 ( V_3 ) ) ;
F_41 = V_2 -> V_24 -> F_41 ;
F_43 ( & V_2 -> V_25 , V_23 ) ;
F_13 ( V_3 , NULL ) ;
F_44 ( & V_2 -> V_25 , V_23 ) ;
if ( F_41 )
F_41 ( V_3 ) ;
F_45 ( V_3 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
if ( F_47 ( V_27 , & V_2 -> V_23 ) &&
F_48 ( V_27 , & V_2 -> V_23 ) )
V_26 = - V_28 ;
if ( F_47 ( V_29 , & V_2 -> V_23 ) &&
F_48 ( V_29 , & V_2 -> V_23 ) )
V_26 = - V_30 ;
return V_26 ;
}
int F_49 ( struct V_1 * V_2 , T_1 V_31 ,
T_1 V_32 , int V_33 )
{
int V_26 ;
struct V_34 V_35 = {
. V_33 = V_33 ,
. V_36 = V_37 ,
. V_38 = V_31 ,
. V_39 = V_32 ,
} ;
if ( ! F_50 ( V_2 ) )
return 0 ;
F_51 ( & V_35 , V_2 -> V_22 ) ;
V_26 = F_52 ( V_2 , & V_35 ) ;
F_53 ( & V_35 ) ;
return V_26 ;
}
static inline int F_54 ( struct V_1 * V_2 ,
int V_33 )
{
return F_49 ( V_2 , 0 , V_40 , V_33 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
return F_54 ( V_2 , V_41 ) ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_31 ,
T_1 V_32 )
{
return F_49 ( V_2 , V_31 , V_32 , V_41 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
return F_54 ( V_2 , V_42 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
T_1 V_43 , T_1 V_44 )
{
T_2 V_8 = V_43 >> V_45 ;
T_2 V_32 = V_44 >> V_45 ;
struct V_46 V_47 ;
int V_48 ;
int V_26 = 0 ;
if ( V_44 < V_43 )
goto V_49;
F_59 ( & V_47 , 0 ) ;
while ( ( V_8 <= V_32 ) &&
( V_48 = F_60 ( & V_47 , V_2 , & V_8 ,
V_50 ,
F_61 ( V_32 - V_8 , ( T_2 ) V_51 - 1 ) + 1 ) ) != 0 ) {
unsigned V_52 ;
for ( V_52 = 0 ; V_52 < V_48 ; V_52 ++ ) {
struct V_3 * V_3 = V_47 . V_53 [ V_52 ] ;
if ( V_3 -> V_8 > V_32 )
continue;
F_62 ( V_3 ) ;
if ( F_63 ( V_3 ) )
V_26 = - V_30 ;
}
F_64 ( & V_47 ) ;
F_65 () ;
}
V_49:
return V_26 ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_43 ,
T_1 V_44 )
{
int V_26 , V_54 ;
V_26 = F_58 ( V_2 , V_43 , V_44 ) ;
V_54 = F_46 ( V_2 ) ;
if ( ! V_26 )
V_26 = V_54 ;
return V_26 ;
}
void F_67 ( struct V_1 * V_2 )
{
T_1 V_55 = F_68 ( V_2 -> V_22 ) ;
if ( V_55 == 0 )
return;
F_58 ( V_2 , 0 , V_55 - 1 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
T_1 V_55 = F_68 ( V_2 -> V_22 ) ;
if ( V_55 == 0 )
return 0 ;
return F_66 ( V_2 , 0 , V_55 - 1 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
if ( ( ! F_9 ( V_2 ) && V_2 -> V_10 ) ||
( F_9 ( V_2 ) && V_2 -> V_9 ) ) {
V_56 = F_55 ( V_2 ) ;
if ( V_56 != - V_30 ) {
int V_57 = F_69 ( V_2 ) ;
if ( ! V_56 )
V_56 = V_57 ;
}
} else {
V_56 = F_46 ( V_2 ) ;
}
return V_56 ;
}
int F_71 ( struct V_1 * V_2 ,
T_1 V_58 , T_1 V_59 )
{
int V_56 = 0 ;
if ( ( ! F_9 ( V_2 ) && V_2 -> V_10 ) ||
( F_9 ( V_2 ) && V_2 -> V_9 ) ) {
V_56 = F_49 ( V_2 , V_58 , V_59 ,
V_41 ) ;
if ( V_56 != - V_30 ) {
int V_57 = F_66 ( V_2 ,
V_58 , V_59 ) ;
if ( ! V_56 )
V_56 = V_57 ;
}
} else {
V_56 = F_46 ( V_2 ) ;
}
return V_56 ;
}
int F_72 ( struct V_3 * V_60 , struct V_3 * V_61 , T_3 V_62 )
{
int error ;
F_19 ( ! F_3 ( V_60 ) , V_60 ) ;
F_19 ( ! F_3 ( V_61 ) , V_61 ) ;
F_19 ( V_61 -> V_2 , V_61 ) ;
error = F_73 ( V_62 & ~ V_63 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_60 -> V_2 ;
void (* F_41)( struct V_3 * );
unsigned long V_23 ;
T_2 V_64 = V_60 -> V_8 ;
F_41 = V_2 -> V_24 -> F_41 ;
F_74 ( V_61 ) ;
V_61 -> V_2 = V_2 ;
V_61 -> V_8 = V_64 ;
F_43 ( & V_2 -> V_25 , V_23 ) ;
F_13 ( V_60 , NULL ) ;
error = F_75 ( & V_2 -> V_7 , V_64 , V_61 ) ;
F_42 ( error ) ;
V_2 -> V_10 ++ ;
if ( ! F_33 ( V_61 ) )
F_76 ( V_61 , V_20 ) ;
if ( F_35 ( V_61 ) )
F_76 ( V_61 , V_21 ) ;
F_44 ( & V_2 -> V_25 , V_23 ) ;
F_77 ( V_60 , V_61 ) ;
F_78 () ;
if ( F_41 )
F_41 ( V_60 ) ;
F_45 ( V_60 ) ;
}
return error ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_65 )
{
struct V_5 * V_6 ;
void * * V_66 ;
int error ;
error = F_80 ( & V_2 -> V_7 , V_3 -> V_8 , 0 ,
& V_6 , & V_66 ) ;
if ( error )
return error ;
if ( * V_66 ) {
void * V_67 ;
V_67 = F_81 ( V_66 , & V_2 -> V_25 ) ;
if ( ! F_82 ( V_67 ) )
return - V_68 ;
V_2 -> V_9 -- ;
if ( ! F_9 ( V_2 ) ) {
if ( V_65 )
* V_65 = V_67 ;
if ( V_6 )
F_83 ( V_6 ) ;
} else {
F_36 ( V_67 !=
( void * ) ( V_69 |
V_70 ) ) ;
if ( V_6 )
F_6 ( V_6 ) ;
F_84 ( V_2 , V_3 -> V_8 ,
false ) ;
}
}
F_85 ( V_66 , V_3 ) ;
V_2 -> V_10 ++ ;
if ( V_6 ) {
F_86 ( V_6 ) ;
if ( ! F_11 ( & V_6 -> V_11 ) )
F_87 ( & V_13 ,
& V_6 -> V_11 ) ;
}
return 0 ;
}
static int F_88 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_64 , T_3 V_62 ,
void * * V_65 )
{
int V_71 = F_33 ( V_3 ) ;
struct V_72 * V_73 ;
int error ;
F_19 ( ! F_3 ( V_3 ) , V_3 ) ;
F_19 ( F_35 ( V_3 ) , V_3 ) ;
if ( ! V_71 ) {
error = F_89 ( V_3 , V_16 -> V_74 ,
V_62 , & V_73 , false ) ;
if ( error )
return error ;
}
error = F_90 ( V_62 & ~ V_63 ) ;
if ( error ) {
if ( ! V_71 )
F_91 ( V_3 , V_73 , false ) ;
return error ;
}
F_74 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_8 = V_64 ;
F_92 ( & V_2 -> V_25 ) ;
error = F_79 ( V_2 , V_3 , V_65 ) ;
F_78 () ;
if ( F_22 ( error ) )
goto V_75;
if ( ! V_71 )
F_76 ( V_3 , V_20 ) ;
F_93 ( & V_2 -> V_25 ) ;
if ( ! V_71 )
F_94 ( V_3 , V_73 , false , false ) ;
F_95 ( V_3 ) ;
return 0 ;
V_75:
V_3 -> V_2 = NULL ;
F_93 ( & V_2 -> V_25 ) ;
if ( ! V_71 )
F_91 ( V_3 , V_73 , false ) ;
F_45 ( V_3 ) ;
return error ;
}
int F_96 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_64 , T_3 V_62 )
{
return F_88 ( V_3 , V_2 , V_64 ,
V_62 , NULL ) ;
}
int F_97 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_64 , T_3 V_62 )
{
void * V_4 = NULL ;
int V_26 ;
F_98 ( V_3 ) ;
V_26 = F_88 ( V_3 , V_2 , V_64 ,
V_62 , & V_4 ) ;
if ( F_22 ( V_26 ) )
F_99 ( V_3 ) ;
else {
if ( ! ( V_62 & V_76 ) &&
V_4 && F_100 ( V_4 ) ) {
F_101 ( V_3 ) ;
F_102 ( V_3 ) ;
} else
F_103 ( V_3 ) ;
F_104 ( V_3 ) ;
}
return V_26 ;
}
struct V_3 * F_105 ( T_3 V_77 )
{
int V_78 ;
struct V_3 * V_3 ;
if ( F_106 () ) {
unsigned int V_79 ;
do {
V_79 = F_107 () ;
V_78 = F_108 () ;
V_3 = F_109 ( V_78 , V_77 , 0 ) ;
} while ( ! V_3 && F_110 ( V_79 ) );
return V_3 ;
}
return F_111 ( V_77 , 0 ) ;
}
T_4 * F_112 ( struct V_3 * V_3 )
{
const struct V_80 * V_80 = F_113 ( V_3 ) ;
return & V_80 -> V_81 [ F_114 ( V_3 , V_80 -> V_82 ) ] ;
}
void F_115 ( struct V_3 * V_3 , int V_83 )
{
F_116 ( V_84 , & V_3 -> V_23 , V_83 ) ;
if ( F_47 ( V_83 , & V_3 -> V_23 ) )
F_117 ( F_112 ( V_3 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_118 ( struct V_3 * V_3 , int V_83 )
{
F_116 ( V_84 , & V_3 -> V_23 , V_83 ) ;
if ( ! F_47 ( V_83 , & V_3 -> V_23 ) )
return 0 ;
return F_117 ( F_112 ( V_3 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_119 ( struct V_3 * V_3 ,
int V_83 , unsigned long V_88 )
{
F_116 ( V_84 , & V_3 -> V_23 , V_83 ) ;
V_84 . V_89 . V_88 = V_90 + V_88 ;
if ( ! F_47 ( V_83 , & V_3 -> V_23 ) )
return 0 ;
return F_117 ( F_112 ( V_3 ) , & V_84 ,
V_91 , V_87 ) ;
}
void F_120 ( struct V_3 * V_3 , T_5 * V_92 )
{
T_4 * V_93 = F_112 ( V_3 ) ;
unsigned long V_23 ;
F_43 ( & V_93 -> V_94 , V_23 ) ;
F_121 ( V_93 , V_92 ) ;
F_44 ( & V_93 -> V_94 , V_23 ) ;
}
void F_122 ( struct V_3 * V_3 )
{
V_3 = F_123 ( V_3 ) ;
F_19 ( ! F_3 ( V_3 ) , V_3 ) ;
F_124 ( V_95 , & V_3 -> V_23 ) ;
F_125 () ;
F_126 ( V_3 , V_95 ) ;
}
void F_127 ( struct V_3 * V_3 )
{
if ( F_128 ( V_3 ) ) {
F_129 ( V_3 ) ;
F_130 ( V_3 ) ;
}
if ( ! F_131 ( V_3 ) )
F_132 () ;
F_125 () ;
F_126 ( V_3 , V_96 ) ;
}
void F_133 ( struct V_3 * V_3 , int V_97 , int V_56 )
{
if ( V_97 == V_98 ) {
if ( ! V_56 ) {
F_134 ( V_3 ) ;
} else {
F_135 ( V_3 ) ;
F_136 ( V_3 ) ;
}
F_122 ( V_3 ) ;
} else {
if ( V_56 ) {
F_136 ( V_3 ) ;
if ( V_3 -> V_2 )
F_137 ( V_3 -> V_2 , V_56 ) ;
}
F_127 ( V_3 ) ;
}
}
void F_138 ( struct V_3 * V_3 )
{
struct V_3 * V_99 = F_123 ( V_3 ) ;
F_116 ( V_84 , & V_99 -> V_23 , V_95 ) ;
F_139 ( F_112 ( V_99 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_140 ( struct V_3 * V_3 )
{
struct V_3 * V_99 = F_123 ( V_3 ) ;
F_116 ( V_84 , & V_99 -> V_23 , V_95 ) ;
return F_139 ( F_112 ( V_99 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_141 ( struct V_3 * V_3 , struct V_100 * V_74 ,
unsigned int V_23 )
{
if ( V_23 & V_101 ) {
if ( V_23 & V_102 )
return 0 ;
F_142 ( & V_74 -> V_103 ) ;
if ( V_23 & V_104 )
F_143 ( V_3 ) ;
else
F_144 ( V_3 ) ;
return 0 ;
} else {
if ( V_23 & V_104 ) {
int V_26 ;
V_26 = F_140 ( V_3 ) ;
if ( V_26 ) {
F_142 ( & V_74 -> V_103 ) ;
return 0 ;
}
} else
F_138 ( V_3 ) ;
return 1 ;
}
}
T_2 F_145 ( struct V_1 * V_2 ,
T_2 V_8 , unsigned long V_105 )
{
unsigned long V_52 ;
for ( V_52 = 0 ; V_52 < V_105 ; V_52 ++ ) {
struct V_3 * V_3 ;
V_3 = F_146 ( & V_2 -> V_7 , V_8 ) ;
if ( ! V_3 || F_82 ( V_3 ) )
break;
V_8 ++ ;
if ( V_8 == 0 )
break;
}
return V_8 ;
}
T_2 F_147 ( struct V_1 * V_2 ,
T_2 V_8 , unsigned long V_105 )
{
unsigned long V_52 ;
for ( V_52 = 0 ; V_52 < V_105 ; V_52 ++ ) {
struct V_3 * V_3 ;
V_3 = F_146 ( & V_2 -> V_7 , V_8 ) ;
if ( ! V_3 || F_82 ( V_3 ) )
break;
V_8 -- ;
if ( V_8 == V_106 )
break;
}
return V_8 ;
}
struct V_3 * F_148 ( struct V_1 * V_2 , T_2 V_64 )
{
void * * V_107 ;
struct V_3 * V_3 ;
F_149 () ;
V_108:
V_3 = NULL ;
V_107 = F_150 ( & V_2 -> V_7 , V_64 ) ;
if ( V_107 ) {
V_3 = F_151 ( V_107 ) ;
if ( F_22 ( ! V_3 ) )
goto V_49;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) )
goto V_108;
goto V_49;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_107 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
}
V_49:
F_155 () ;
return V_3 ;
}
struct V_3 * F_156 ( struct V_1 * V_2 , T_2 V_64 )
{
struct V_3 * V_3 ;
V_108:
V_3 = F_148 ( V_2 , V_64 ) ;
if ( V_3 && ! F_152 ( V_3 ) ) {
F_157 ( V_3 ) ;
if ( F_22 ( V_3 -> V_2 != V_2 ) ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
goto V_108;
}
F_19 ( V_3 -> V_8 != V_64 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_158 ( struct V_1 * V_2 , T_2 V_64 ,
int V_109 , T_3 V_62 )
{
struct V_3 * V_3 ;
V_108:
V_3 = F_148 ( V_2 , V_64 ) ;
if ( F_82 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_110;
if ( V_109 & V_111 ) {
if ( V_109 & V_112 ) {
if ( ! F_159 ( V_3 ) ) {
F_45 ( V_3 ) ;
return NULL ;
}
} else {
F_157 ( V_3 ) ;
}
if ( F_22 ( V_3 -> V_2 != V_2 ) ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
goto V_108;
}
F_19 ( V_3 -> V_8 != V_64 , V_3 ) ;
}
if ( V_3 && ( V_109 & V_113 ) )
F_160 ( V_3 ) ;
V_110:
if ( ! V_3 && ( V_109 & V_114 ) ) {
int V_56 ;
if ( ( V_109 & V_115 ) && F_161 ( V_2 ) )
V_62 |= V_76 ;
if ( V_109 & V_116 )
V_62 &= ~ V_117 ;
V_3 = F_105 ( V_62 ) ;
if ( ! V_3 )
return NULL ;
if ( F_36 ( ! ( V_109 & V_111 ) ) )
V_109 |= V_111 ;
if ( V_109 & V_113 )
F_162 ( V_3 ) ;
V_56 = F_97 ( V_3 , V_2 , V_64 ,
V_62 & V_118 ) ;
if ( F_22 ( V_56 ) ) {
F_45 ( V_3 ) ;
V_3 = NULL ;
if ( V_56 == - V_68 )
goto V_108;
}
}
return V_3 ;
}
unsigned F_163 ( struct V_1 * V_2 ,
T_2 V_31 , unsigned int V_119 ,
struct V_3 * * V_120 , T_2 * V_121 )
{
void * * V_66 ;
unsigned int V_26 = 0 ;
struct V_122 V_123 ;
if ( ! V_119 )
return 0 ;
F_149 () ;
F_164 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
continue;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
goto V_124;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
V_124:
V_121 [ V_26 ] = V_123 . V_8 ;
V_120 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_119 )
break;
}
F_155 () ;
return V_26 ;
}
unsigned F_166 ( struct V_1 * V_2 , T_2 V_31 ,
unsigned int V_48 , struct V_3 * * V_53 )
{
struct V_122 V_123 ;
void * * V_66 ;
unsigned V_26 = 0 ;
if ( F_22 ( ! V_48 ) )
return 0 ;
F_149 () ;
F_164 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
continue;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
continue;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
V_53 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_48 )
break;
}
F_155 () ;
return V_26 ;
}
unsigned F_167 ( struct V_1 * V_2 , T_2 V_8 ,
unsigned int V_48 , struct V_3 * * V_53 )
{
struct V_122 V_123 ;
void * * V_66 ;
unsigned int V_26 = 0 ;
if ( F_22 ( ! V_48 ) )
return 0 ;
F_149 () ;
F_168 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
break;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
break;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_8 != V_123 . V_8 ) {
F_45 ( V_3 ) ;
break;
}
V_53 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_48 )
break;
}
F_155 () ;
return V_26 ;
}
unsigned F_169 ( struct V_1 * V_2 , T_2 * V_8 ,
int V_125 , unsigned int V_48 , struct V_3 * * V_53 )
{
struct V_122 V_123 ;
void * * V_66 ;
unsigned V_26 = 0 ;
if ( F_22 ( ! V_48 ) )
return 0 ;
F_149 () ;
F_170 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
continue;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
continue;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
V_53 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_48 )
break;
}
F_155 () ;
if ( V_26 )
* V_8 = V_53 [ V_26 - 1 ] -> V_8 + 1 ;
return V_26 ;
}
unsigned F_171 ( struct V_1 * V_2 , T_2 V_31 ,
int V_125 , unsigned int V_119 ,
struct V_3 * * V_120 , T_2 * V_121 )
{
void * * V_66 ;
unsigned int V_26 = 0 ;
struct V_122 V_123 ;
if ( ! V_119 )
return 0 ;
F_149 () ;
F_170 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_3 ;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
continue;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
goto V_124;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
V_124:
V_121 [ V_26 ] = V_123 . V_8 ;
V_120 [ V_26 ] = V_3 ;
if ( ++ V_26 == V_119 )
break;
}
F_155 () ;
return V_26 ;
}
static void F_172 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
V_129 -> V_130 /= 4 ;
}
static T_6 F_173 ( struct V_126 * V_127 , T_1 * V_131 ,
struct V_132 * V_123 , T_6 V_133 )
{
struct V_1 * V_2 = V_127 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_22 ;
struct V_128 * V_129 = & V_127 -> V_136 ;
T_2 V_8 ;
T_2 V_137 ;
T_2 V_138 ;
unsigned long V_64 ;
unsigned int V_139 ;
int error = 0 ;
V_8 = * V_131 >> V_45 ;
V_138 = V_129 -> V_140 >> V_45 ;
V_139 = V_129 -> V_140 & ( V_141 - 1 ) ;
V_137 = ( * V_131 + V_123 -> V_142 + V_141 - 1 ) >> V_45 ;
V_64 = * V_131 & ~ V_143 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_144 ;
T_1 V_145 ;
unsigned long V_146 , V_26 ;
F_65 () ;
V_147:
V_3 = F_174 ( V_2 , V_8 ) ;
if ( ! V_3 ) {
F_175 ( V_2 ,
V_129 , V_127 ,
V_8 , V_137 - V_8 ) ;
V_3 = F_174 ( V_2 , V_8 ) ;
if ( F_22 ( V_3 == NULL ) )
goto V_148;
}
if ( F_176 ( V_3 ) ) {
F_177 ( V_2 ,
V_129 , V_127 , V_3 ,
V_8 , V_137 - V_8 ) ;
}
if ( ! F_15 ( V_3 ) ) {
F_143 ( V_3 ) ;
if ( F_15 ( V_3 ) )
goto V_149;
if ( V_135 -> V_150 == V_45 ||
! V_2 -> V_24 -> V_151 )
goto V_152;
if ( ! F_159 ( V_3 ) )
goto V_152;
if ( ! V_3 -> V_2 )
goto V_153;
if ( ! V_2 -> V_24 -> V_151 ( V_3 ,
V_64 , V_123 -> V_142 ) )
goto V_153;
F_122 ( V_3 ) ;
}
V_149:
V_145 = F_68 ( V_135 ) ;
V_144 = ( V_145 - 1 ) >> V_45 ;
if ( F_22 ( ! V_145 || V_8 > V_144 ) ) {
F_45 ( V_3 ) ;
goto V_49;
}
V_146 = V_141 ;
if ( V_8 == V_144 ) {
V_146 = ( ( V_145 - 1 ) & ~ V_143 ) + 1 ;
if ( V_146 <= V_64 ) {
F_45 ( V_3 ) ;
goto V_49;
}
}
V_146 = V_146 - V_64 ;
if ( F_178 ( V_2 ) )
F_179 ( V_3 ) ;
if ( V_138 != V_8 || V_64 != V_139 )
F_160 ( V_3 ) ;
V_138 = V_8 ;
V_26 = F_180 ( V_3 , V_64 , V_146 , V_123 ) ;
V_64 += V_26 ;
V_8 += V_64 >> V_45 ;
V_64 &= ~ V_143 ;
V_139 = V_64 ;
F_45 ( V_3 ) ;
V_133 += V_26 ;
if ( ! F_181 ( V_123 ) )
goto V_49;
if ( V_26 < V_146 ) {
error = - V_154 ;
goto V_49;
}
continue;
V_152:
error = F_182 ( V_3 ) ;
if ( F_22 ( error ) )
goto V_155;
V_153:
if ( ! V_3 -> V_2 ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
continue;
}
if ( F_15 ( V_3 ) ) {
F_122 ( V_3 ) ;
goto V_149;
}
V_156:
F_183 ( V_3 ) ;
error = V_2 -> V_24 -> V_156 ( V_127 , V_3 ) ;
if ( F_22 ( error ) ) {
if ( error == V_157 ) {
F_45 ( V_3 ) ;
error = 0 ;
goto V_147;
}
goto V_155;
}
if ( ! F_15 ( V_3 ) ) {
error = F_182 ( V_3 ) ;
if ( F_22 ( error ) )
goto V_155;
if ( ! F_15 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
goto V_147;
}
F_122 ( V_3 ) ;
F_172 ( V_127 , V_129 ) ;
error = - V_30 ;
goto V_155;
}
F_122 ( V_3 ) ;
}
goto V_149;
V_155:
F_45 ( V_3 ) ;
goto V_49;
V_148:
V_3 = F_184 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_158 ;
goto V_49;
}
error = F_97 ( V_3 , V_2 , V_8 ,
F_185 ( V_2 , V_159 ) ) ;
if ( error ) {
F_45 ( V_3 ) ;
if ( error == - V_68 ) {
error = 0 ;
goto V_147;
}
goto V_49;
}
goto V_156;
}
V_49:
V_129 -> V_140 = V_138 ;
V_129 -> V_140 <<= V_45 ;
V_129 -> V_140 |= V_139 ;
* V_131 = ( ( T_1 ) V_8 << V_45 ) + V_64 ;
F_186 ( V_127 ) ;
return V_133 ? V_133 : error ;
}
T_6
F_187 ( struct V_160 * V_161 , struct V_132 * V_123 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
T_6 V_163 = 0 ;
T_7 V_142 = F_181 ( V_123 ) ;
if ( ! V_142 )
goto V_49;
if ( V_161 -> V_164 & V_165 ) {
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_22 ;
T_1 V_166 ;
V_166 = F_68 ( V_135 ) ;
V_163 = F_71 ( V_2 , V_161 -> V_167 ,
V_161 -> V_167 + V_142 - 1 ) ;
if ( ! V_163 ) {
struct V_132 V_168 = * V_123 ;
V_163 = V_2 -> V_24 -> V_169 ( V_161 , & V_168 ) ;
}
if ( V_163 > 0 ) {
V_161 -> V_167 += V_163 ;
F_188 ( V_123 , V_163 ) ;
}
if ( V_163 < 0 || ! F_181 ( V_123 ) || V_161 -> V_167 >= V_166 ||
F_189 ( V_135 ) ) {
F_186 ( V_126 ) ;
goto V_49;
}
}
V_163 = F_173 ( V_126 , & V_161 -> V_167 , V_123 , V_163 ) ;
V_49:
return V_163 ;
}
static int F_190 ( struct V_126 * V_126 , T_2 V_64 , T_3 V_62 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_3 * V_3 ;
int V_26 ;
do {
V_3 = F_105 ( V_62 | V_170 ) ;
if ( ! V_3 )
return - V_158 ;
V_26 = F_97 ( V_3 , V_2 , V_64 , V_62 & V_159 ) ;
if ( V_26 == 0 )
V_26 = V_2 -> V_24 -> V_156 ( V_126 , V_3 ) ;
else if ( V_26 == - V_68 )
V_26 = 0 ;
F_45 ( V_3 ) ;
} while ( V_26 == V_157 );
return V_26 ;
}
static void F_191 ( struct V_171 * V_172 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
T_2 V_64 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_172 -> V_173 & V_174 )
return;
if ( ! V_129 -> V_130 )
return;
if ( V_172 -> V_173 & V_175 ) {
F_175 ( V_2 , V_129 , V_126 , V_64 ,
V_129 -> V_130 ) ;
return;
}
if ( V_129 -> V_176 < V_177 * 10 )
V_129 -> V_176 ++ ;
if ( V_129 -> V_176 > V_177 )
return;
V_129 -> V_31 = F_192 ( long , 0 , V_64 - V_129 -> V_130 / 2 ) ;
V_129 -> V_166 = V_129 -> V_130 ;
V_129 -> V_178 = V_129 -> V_130 / 4 ;
F_193 ( V_129 , V_2 , V_126 ) ;
}
static void F_194 ( struct V_171 * V_172 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
struct V_3 * V_3 ,
T_2 V_64 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_172 -> V_173 & V_174 )
return;
if ( V_129 -> V_176 > 0 )
V_129 -> V_176 -- ;
if ( F_176 ( V_3 ) )
F_177 ( V_2 , V_129 , V_126 ,
V_3 , V_64 , V_129 -> V_130 ) ;
}
int F_195 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
int error ;
struct V_126 * V_126 = V_172 -> V_181 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_128 * V_129 = & V_126 -> V_136 ;
struct V_135 * V_135 = V_2 -> V_22 ;
T_2 V_64 = V_180 -> V_182 ;
struct V_3 * V_3 ;
T_1 V_166 ;
int V_26 = 0 ;
V_166 = F_196 ( F_68 ( V_135 ) , V_141 ) ;
if ( V_64 >= V_166 >> V_45 )
return V_183 ;
V_3 = F_174 ( V_2 , V_64 ) ;
if ( F_197 ( V_3 ) && ! ( V_180 -> V_23 & V_184 ) ) {
F_194 ( V_172 , V_129 , V_126 , V_3 , V_64 ) ;
} else if ( ! V_3 ) {
F_191 ( V_172 , V_129 , V_126 , V_64 ) ;
F_198 ( V_185 ) ;
F_199 ( V_172 -> V_186 , V_185 ) ;
V_26 = V_187 ;
V_188:
V_3 = F_174 ( V_2 , V_64 ) ;
if ( ! V_3 )
goto V_148;
}
if ( ! F_200 ( V_3 , V_172 -> V_186 , V_180 -> V_23 ) ) {
F_45 ( V_3 ) ;
return V_26 | V_189 ;
}
if ( F_22 ( V_3 -> V_2 != V_2 ) ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
goto V_188;
}
F_19 ( V_3 -> V_8 != V_64 , V_3 ) ;
if ( F_22 ( ! F_15 ( V_3 ) ) )
goto V_190;
V_166 = F_196 ( F_68 ( V_135 ) , V_141 ) ;
if ( F_22 ( V_64 >= V_166 >> V_45 ) ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
return V_183 ;
}
V_180 -> V_3 = V_3 ;
return V_26 | V_191 ;
V_148:
error = F_190 ( V_126 , V_64 , V_180 -> V_62 ) ;
if ( error >= 0 )
goto V_188;
if ( error == - V_158 )
return V_192 ;
return V_183 ;
V_190:
F_183 ( V_3 ) ;
error = V_2 -> V_24 -> V_156 ( V_126 , V_3 ) ;
if ( ! error ) {
F_144 ( V_3 ) ;
if ( ! F_15 ( V_3 ) )
error = - V_30 ;
}
F_45 ( V_3 ) ;
if ( ! error || error == V_157 )
goto V_188;
F_172 ( V_126 , V_129 ) ;
return V_183 ;
}
void F_201 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
struct V_122 V_123 ;
void * * V_66 ;
struct V_126 * V_126 = V_172 -> V_181 ;
struct V_1 * V_2 = V_126 -> V_134 ;
T_1 V_166 ;
struct V_3 * V_3 ;
unsigned long V_193 = ( unsigned long ) V_180 -> V_194 ;
unsigned long V_195 ;
T_8 * V_196 ;
F_149 () ;
F_164 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_123 . V_8 > V_180 -> V_197 )
break;
V_108:
V_3 = F_151 ( V_66 ) ;
if ( F_22 ( ! V_3 ) )
goto V_198;
if ( F_152 ( V_3 ) ) {
if ( F_153 ( V_3 ) ) {
V_66 = F_165 ( & V_123 ) ;
continue;
}
goto V_198;
}
if ( ! F_154 ( V_3 ) )
goto V_108;
if ( F_22 ( V_3 != * V_66 ) ) {
F_45 ( V_3 ) ;
goto V_108;
}
if ( ! F_15 ( V_3 ) ||
F_176 ( V_3 ) ||
F_202 ( V_3 ) )
goto V_199;
if ( ! F_159 ( V_3 ) )
goto V_199;
if ( V_3 -> V_2 != V_2 || ! F_15 ( V_3 ) )
goto V_200;
V_166 = F_196 ( F_68 ( V_2 -> V_22 ) , V_141 ) ;
if ( V_3 -> V_8 >= V_166 >> V_45 )
goto V_200;
V_196 = V_180 -> V_196 + V_3 -> V_8 - V_180 -> V_182 ;
if ( ! F_203 ( * V_196 ) )
goto V_200;
if ( V_126 -> V_136 . V_176 > 0 )
V_126 -> V_136 . V_176 -- ;
V_195 = V_193 + ( V_3 -> V_8 - V_180 -> V_182 ) * V_141 ;
F_204 ( V_172 , V_195 , V_3 , V_196 , false , false ) ;
F_122 ( V_3 ) ;
goto V_198;
V_200:
F_122 ( V_3 ) ;
V_199:
F_45 ( V_3 ) ;
V_198:
if ( V_123 . V_8 == V_180 -> V_197 )
break;
}
F_155 () ;
}
int F_205 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
struct V_3 * V_3 = V_180 -> V_3 ;
struct V_135 * V_135 = F_206 ( V_172 -> V_181 ) ;
int V_26 = V_191 ;
F_207 ( V_135 -> V_201 ) ;
F_208 ( V_172 -> V_181 ) ;
F_157 ( V_3 ) ;
if ( V_3 -> V_2 != V_135 -> V_202 ) {
F_122 ( V_3 ) ;
V_26 = V_203 ;
goto V_49;
}
F_209 ( V_3 ) ;
F_210 ( V_3 ) ;
V_49:
F_211 ( V_135 -> V_201 ) ;
return V_26 ;
}
int F_212 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( ! V_2 -> V_24 -> V_156 )
return - V_204 ;
F_186 ( V_126 ) ;
V_172 -> V_205 = & V_206 ;
return 0 ;
}
int F_213 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
if ( ( V_172 -> V_173 & V_207 ) && ( V_172 -> V_173 & V_208 ) )
return - V_209 ;
return F_212 ( V_126 , V_172 ) ;
}
int F_212 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
return - V_210 ;
}
int F_213 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
return - V_210 ;
}
static struct V_3 * F_214 ( struct V_3 * V_3 )
{
if ( ! F_215 ( V_3 ) ) {
F_144 ( V_3 ) ;
if ( ! F_15 ( V_3 ) ) {
F_45 ( V_3 ) ;
V_3 = F_216 ( - V_30 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_217 ( struct V_1 * V_2 ,
T_2 V_8 ,
int (* F_218)( void * , struct V_3 * ) ,
void * V_168 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_56 ;
V_108:
V_3 = F_174 ( V_2 , V_8 ) ;
if ( ! V_3 ) {
V_3 = F_105 ( V_77 | V_170 ) ;
if ( ! V_3 )
return F_216 ( - V_158 ) ;
V_56 = F_97 ( V_3 , V_2 , V_8 , V_77 ) ;
if ( F_22 ( V_56 ) ) {
F_45 ( V_3 ) ;
if ( V_56 == - V_68 )
goto V_108;
return F_216 ( V_56 ) ;
}
F_218:
V_56 = F_218 ( V_168 , V_3 ) ;
if ( V_56 < 0 ) {
F_45 ( V_3 ) ;
return F_216 ( V_56 ) ;
}
V_3 = F_214 ( V_3 ) ;
if ( F_215 ( V_3 ) )
return V_3 ;
goto V_49;
}
if ( F_15 ( V_3 ) )
goto V_49;
F_144 ( V_3 ) ;
if ( F_15 ( V_3 ) )
goto V_49;
F_157 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_122 ( V_3 ) ;
F_45 ( V_3 ) ;
goto V_108;
}
if ( F_15 ( V_3 ) ) {
F_122 ( V_3 ) ;
goto V_49;
}
goto F_218;
V_49:
F_160 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_219 ( struct V_1 * V_2 ,
T_2 V_8 ,
int (* F_218)( void * , struct V_3 * ) ,
void * V_168 )
{
return F_217 ( V_2 , V_8 , F_218 , V_168 , F_220 ( V_2 ) ) ;
}
struct V_3 * F_221 ( struct V_1 * V_2 ,
T_2 V_8 ,
T_3 V_77 )
{
T_9 * F_218 = ( T_9 * ) V_2 -> V_24 -> V_156 ;
return F_217 ( V_2 , V_8 , F_218 , NULL , V_77 ) ;
}
inline T_6 F_222 ( struct V_160 * V_161 , struct V_132 * V_211 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_135 * V_135 = V_126 -> V_134 -> V_22 ;
unsigned long V_212 = F_223 ( V_213 ) ;
T_1 V_214 ;
if ( ! F_181 ( V_211 ) )
return 0 ;
if ( V_161 -> V_164 & V_215 )
V_161 -> V_167 = F_68 ( V_135 ) ;
V_214 = V_161 -> V_167 ;
if ( V_212 != V_216 ) {
if ( V_161 -> V_167 >= V_212 ) {
F_224 ( V_217 , V_16 , 0 ) ;
return - V_218 ;
}
F_225 ( V_211 , V_212 - ( unsigned long ) V_214 ) ;
}
if ( F_22 ( V_214 + F_181 ( V_211 ) > V_219 &&
! ( V_126 -> V_220 & V_221 ) ) ) {
if ( V_214 >= V_219 )
return - V_218 ;
F_225 ( V_211 , V_219 - ( unsigned long ) V_214 ) ;
}
if ( F_22 ( V_214 >= V_135 -> V_201 -> V_222 ) )
return - V_218 ;
F_225 ( V_211 , V_135 -> V_201 -> V_222 - V_214 ) ;
return F_181 ( V_211 ) ;
}
int F_226 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_214 , unsigned V_223 , unsigned V_23 ,
struct V_3 * * V_107 , void * * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_24 ;
return V_226 -> V_227 ( V_126 , V_2 , V_214 , V_223 , V_23 ,
V_107 , V_224 ) ;
}
int F_227 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_214 , unsigned V_223 , unsigned V_228 ,
struct V_3 * V_3 , void * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_24 ;
return V_226 -> V_229 ( V_126 , V_2 , V_214 , V_223 , V_228 , V_3 , V_224 ) ;
}
T_6
F_228 ( struct V_160 * V_161 , struct V_132 * V_211 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_22 ;
T_1 V_214 = V_161 -> V_167 ;
T_6 V_133 ;
T_7 V_230 ;
T_2 V_32 ;
struct V_132 V_168 ;
V_230 = F_181 ( V_211 ) ;
V_32 = ( V_214 + V_230 - 1 ) >> V_45 ;
V_133 = F_71 ( V_2 , V_214 , V_214 + V_230 - 1 ) ;
if ( V_133 )
goto V_49;
if ( V_2 -> V_10 ) {
V_133 = F_229 ( V_2 ,
V_214 >> V_45 , V_32 ) ;
if ( V_133 ) {
if ( V_133 == - V_231 )
return 0 ;
goto V_49;
}
}
V_168 = * V_211 ;
V_133 = V_2 -> V_24 -> V_169 ( V_161 , & V_168 ) ;
if ( V_2 -> V_10 ) {
F_229 ( V_2 ,
V_214 >> V_45 , V_32 ) ;
}
if ( V_133 > 0 ) {
V_214 += V_133 ;
F_188 ( V_211 , V_133 ) ;
if ( V_214 > F_68 ( V_135 ) && ! F_230 ( V_135 -> V_232 ) ) {
F_231 ( V_135 , V_214 ) ;
F_232 ( V_135 ) ;
}
V_161 -> V_167 = V_214 ;
}
V_49:
return V_133 ;
}
struct V_3 * F_233 ( struct V_1 * V_2 ,
T_2 V_8 , unsigned V_23 )
{
struct V_3 * V_3 ;
int V_109 = V_111 | V_115 | V_114 ;
if ( V_23 & V_233 )
V_109 |= V_116 ;
V_3 = F_158 ( V_2 , V_8 , V_109 ,
F_220 ( V_2 ) ) ;
if ( V_3 )
F_210 ( V_3 ) ;
return V_3 ;
}
T_6 F_234 ( struct V_126 * V_126 ,
struct V_132 * V_52 , T_1 V_214 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
const struct V_225 * V_24 = V_2 -> V_24 ;
long V_234 = 0 ;
T_6 V_133 = 0 ;
unsigned int V_23 = 0 ;
if ( ! F_235 ( V_52 ) )
V_23 |= V_235 ;
do {
struct V_3 * V_3 ;
unsigned long V_64 ;
unsigned long V_236 ;
T_7 V_228 ;
void * V_224 ;
V_64 = ( V_214 & ( V_141 - 1 ) ) ;
V_236 = F_236 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_237:
if ( F_22 ( F_237 ( V_52 , V_236 ) ) ) {
V_234 = - V_154 ;
break;
}
if ( F_238 ( V_16 ) ) {
V_234 = - V_238 ;
break;
}
V_234 = V_24 -> V_227 ( V_126 , V_2 , V_214 , V_236 , V_23 ,
& V_3 , & V_224 ) ;
if ( F_22 ( V_234 < 0 ) )
break;
if ( F_178 ( V_2 ) )
F_179 ( V_3 ) ;
V_228 = F_239 ( V_3 , V_52 , V_64 , V_236 ) ;
F_179 ( V_3 ) ;
V_234 = V_24 -> V_229 ( V_126 , V_2 , V_214 , V_236 , V_228 ,
V_3 , V_224 ) ;
if ( F_22 ( V_234 < 0 ) )
break;
V_228 = V_234 ;
F_65 () ;
F_188 ( V_52 , V_228 ) ;
if ( F_22 ( V_228 == 0 ) ) {
V_236 = F_236 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_237;
}
V_214 += V_228 ;
V_133 += V_228 ;
F_240 ( V_2 ) ;
} while ( F_181 ( V_52 ) );
return V_133 ? V_133 : V_234 ;
}
T_6 F_241 ( struct V_160 * V_161 , struct V_132 * V_211 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_22 ;
T_6 V_133 = 0 ;
T_6 V_56 ;
T_6 V_234 ;
V_16 -> V_239 = F_242 ( V_135 ) ;
V_56 = F_243 ( V_126 ) ;
if ( V_56 )
goto V_49;
V_56 = F_208 ( V_126 ) ;
if ( V_56 )
goto V_49;
if ( V_161 -> V_164 & V_165 ) {
T_1 V_214 , V_240 ;
V_133 = F_228 ( V_161 , V_211 ) ;
if ( V_133 < 0 || ! F_181 ( V_211 ) || F_189 ( V_135 ) )
goto V_49;
V_234 = F_234 ( V_126 , V_211 , V_214 = V_161 -> V_167 ) ;
if ( F_22 ( V_234 < 0 ) ) {
V_56 = V_234 ;
goto V_49;
}
V_240 = V_214 + V_234 - 1 ;
V_56 = F_71 ( V_2 , V_214 , V_240 ) ;
if ( V_56 == 0 ) {
V_161 -> V_167 = V_240 + 1 ;
V_133 += V_234 ;
F_244 ( V_2 ,
V_214 >> V_45 ,
V_240 >> V_45 ) ;
} else {
}
} else {
V_133 = F_234 ( V_126 , V_211 , V_161 -> V_167 ) ;
if ( F_197 ( V_133 > 0 ) )
V_161 -> V_167 += V_133 ;
}
V_49:
V_16 -> V_239 = NULL ;
return V_133 ? V_133 : V_56 ;
}
T_6 F_245 ( struct V_160 * V_161 , struct V_132 * V_211 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_135 * V_135 = V_126 -> V_134 -> V_22 ;
T_6 V_26 ;
F_246 ( V_135 ) ;
V_26 = F_222 ( V_161 , V_211 ) ;
if ( V_26 > 0 )
V_26 = F_241 ( V_161 , V_211 ) ;
F_247 ( V_135 ) ;
if ( V_26 > 0 )
V_26 = F_248 ( V_161 , V_26 ) ;
return V_26 ;
}
int F_249 ( struct V_3 * V_3 , T_3 V_62 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_42 ( ! F_3 ( V_3 ) ) ;
if ( F_250 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_24 -> V_241 )
return V_2 -> V_24 -> V_241 ( V_3 , V_62 ) ;
return F_251 ( V_3 ) ;
}
