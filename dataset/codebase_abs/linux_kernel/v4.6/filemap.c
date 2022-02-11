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
F_21 ( F_22 ( V_3 ) , V_3 ) ;
if ( ! F_23 ( V_22 ) && F_24 ( F_22 ( V_3 ) ) ) {
int V_23 ;
F_25 ( L_1 ,
V_24 -> V_25 , F_26 ( V_3 ) ) ;
F_27 ( V_3 , L_2 ) ;
F_28 () ;
F_29 ( V_26 , V_27 ) ;
V_23 = F_30 ( V_3 ) ;
if ( F_31 ( V_2 ) &&
F_32 ( V_3 ) >= V_23 + 2 ) {
F_33 ( V_3 ) ;
F_34 ( V_23 , & V_3 -> V_28 ) ;
}
}
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_35 ( V_3 ) )
F_36 ( V_3 , V_29 ) ;
if ( F_37 ( V_3 ) )
F_36 ( V_3 , V_30 ) ;
if ( F_38 ( F_39 ( V_3 ) ) )
F_40 ( V_3 , V_2 , F_41 ( V_2 -> V_31 ) ) ;
}
void F_42 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
unsigned long V_32 ;
void (* F_43)( struct V_3 * );
F_44 ( ! F_3 ( V_3 ) ) ;
F_43 = V_2 -> V_33 -> F_43 ;
F_45 ( & V_2 -> V_34 , V_32 ) ;
F_15 ( V_3 , NULL ) ;
F_46 ( & V_2 -> V_34 , V_32 ) ;
if ( F_43 )
F_43 ( V_3 ) ;
F_47 ( V_3 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( F_7 ( V_36 , & V_2 -> V_32 ) &&
F_49 ( V_36 , & V_2 -> V_32 ) )
V_35 = - V_37 ;
if ( F_7 ( V_38 , & V_2 -> V_32 ) &&
F_49 ( V_38 , & V_2 -> V_32 ) )
V_35 = - V_39 ;
return V_35 ;
}
int F_50 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_41 , int V_42 )
{
int V_35 ;
struct V_43 V_44 = {
. V_42 = V_42 ,
. V_45 = V_46 ,
. V_47 = V_40 ,
. V_48 = V_41 ,
} ;
if ( ! F_51 ( V_2 ) )
return 0 ;
F_52 ( & V_44 , V_2 -> V_31 ) ;
V_35 = F_53 ( V_2 , & V_44 ) ;
F_54 ( & V_44 ) ;
return V_35 ;
}
static inline int F_55 ( struct V_1 * V_2 ,
int V_42 )
{
return F_50 ( V_2 , 0 , V_49 , V_42 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_50 ) ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_41 )
{
return F_50 ( V_2 , V_40 , V_41 , V_50 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_51 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
T_1 V_52 , T_1 V_53 )
{
T_2 V_7 = V_52 >> V_54 ;
T_2 V_41 = V_53 >> V_54 ;
struct V_55 V_56 ;
int V_57 ;
int V_35 = 0 ;
if ( V_53 < V_52 )
goto V_58;
F_60 ( & V_56 , 0 ) ;
while ( ( V_7 <= V_41 ) &&
( V_57 = F_61 ( & V_56 , V_2 , & V_7 ,
V_59 ,
F_62 ( V_41 - V_7 , ( T_2 ) V_60 - 1 ) + 1 ) ) != 0 ) {
unsigned V_61 ;
for ( V_61 = 0 ; V_61 < V_57 ; V_61 ++ ) {
struct V_3 * V_3 = V_56 . V_62 [ V_61 ] ;
if ( V_3 -> V_7 > V_41 )
continue;
F_63 ( V_3 ) ;
if ( F_64 ( V_3 ) )
V_35 = - V_39 ;
}
F_65 ( & V_56 ) ;
F_66 () ;
}
V_58:
return V_35 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_52 ,
T_1 V_53 )
{
int V_35 , V_63 ;
V_35 = F_59 ( V_2 , V_52 , V_53 ) ;
V_63 = F_48 ( V_2 ) ;
if ( ! V_35 )
V_35 = V_63 ;
return V_35 ;
}
void F_68 ( struct V_1 * V_2 )
{
T_1 V_64 = F_69 ( V_2 -> V_31 ) ;
if ( V_64 == 0 )
return;
F_59 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
T_1 V_64 = F_69 ( V_2 -> V_31 ) ;
if ( V_64 == 0 )
return 0 ;
return F_67 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_65 = 0 ;
if ( ( ! F_72 ( V_2 ) && V_2 -> V_13 ) ||
( F_72 ( V_2 ) && V_2 -> V_12 ) ) {
V_65 = F_56 ( V_2 ) ;
if ( V_65 != - V_39 ) {
int V_66 = F_70 ( V_2 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_48 ( V_2 ) ;
}
return V_65 ;
}
int F_73 ( struct V_1 * V_2 ,
T_1 V_67 , T_1 V_68 )
{
int V_65 = 0 ;
if ( ( ! F_72 ( V_2 ) && V_2 -> V_13 ) ||
( F_72 ( V_2 ) && V_2 -> V_12 ) ) {
V_65 = F_50 ( V_2 , V_67 , V_68 ,
V_50 ) ;
if ( V_65 != - V_39 ) {
int V_66 = F_67 ( V_2 ,
V_67 , V_68 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_48 ( V_2 ) ;
}
return V_65 ;
}
int F_74 ( struct V_3 * V_69 , struct V_3 * V_70 , T_3 V_14 )
{
int error ;
F_21 ( ! F_3 ( V_69 ) , V_69 ) ;
F_21 ( ! F_3 ( V_70 ) , V_70 ) ;
F_21 ( V_70 -> V_2 , V_70 ) ;
error = F_75 ( V_14 & ~ V_71 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_69 -> V_2 ;
void (* F_43)( struct V_3 * );
unsigned long V_32 ;
T_2 V_8 = V_69 -> V_7 ;
F_43 = V_2 -> V_33 -> F_43 ;
F_76 ( V_70 ) ;
V_70 -> V_2 = V_2 ;
V_70 -> V_7 = V_8 ;
F_45 ( & V_2 -> V_34 , V_32 ) ;
F_15 ( V_69 , NULL ) ;
error = F_77 ( & V_2 -> V_11 , V_8 , V_70 ) ;
F_44 ( error ) ;
V_2 -> V_13 ++ ;
if ( ! F_35 ( V_70 ) )
F_78 ( V_70 , V_29 ) ;
if ( F_37 ( V_70 ) )
F_78 ( V_70 , V_30 ) ;
F_46 ( & V_2 -> V_34 , V_32 ) ;
F_79 ( V_69 , V_70 ) ;
F_80 () ;
if ( F_43 )
F_43 ( V_69 ) ;
F_47 ( V_69 ) ;
}
return error ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_72 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_82 ( & V_2 -> V_11 , V_3 -> V_7 , 0 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_73 ;
V_73 = F_83 ( V_10 , & V_2 -> V_34 ) ;
if ( ! F_84 ( V_73 ) )
return - V_74 ;
if ( F_85 ( F_72 ( V_2 ) ) )
return - V_75 ;
if ( V_72 )
* V_72 = V_73 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_86 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_87 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_88 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_89 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_72 )
{
int V_76 = F_35 ( V_3 ) ;
struct V_77 * V_78 ;
int error ;
F_21 ( ! F_3 ( V_3 ) , V_3 ) ;
F_21 ( F_37 ( V_3 ) , V_3 ) ;
if ( ! V_76 ) {
error = F_90 ( V_3 , V_24 -> V_79 ,
V_14 , & V_78 , false ) ;
if ( error )
return error ;
}
error = F_91 ( V_14 & ~ V_71 ) ;
if ( error ) {
if ( ! V_76 )
F_92 ( V_3 , V_78 , false ) ;
return error ;
}
F_76 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_93 ( & V_2 -> V_34 ) ;
error = F_81 ( V_2 , V_3 , V_72 ) ;
F_80 () ;
if ( F_24 ( error ) )
goto V_80;
if ( ! V_76 )
F_78 ( V_3 , V_29 ) ;
F_94 ( & V_2 -> V_34 ) ;
if ( ! V_76 )
F_95 ( V_3 , V_78 , false , false ) ;
F_96 ( V_3 ) ;
return 0 ;
V_80:
V_3 -> V_2 = NULL ;
F_94 ( & V_2 -> V_34 ) ;
if ( ! V_76 )
F_92 ( V_3 , V_78 , false ) ;
F_47 ( V_3 ) ;
return error ;
}
int F_97 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_89 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_98 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_35 ;
F_99 ( V_3 ) ;
V_35 = F_89 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_24 ( V_35 ) )
F_100 ( V_3 ) ;
else {
if ( V_4 && F_101 ( V_4 ) ) {
F_102 ( V_3 ) ;
F_103 ( V_3 ) ;
} else
F_104 ( V_3 ) ;
F_105 ( V_3 ) ;
}
return V_35 ;
}
struct V_3 * F_106 ( T_3 V_81 )
{
int V_82 ;
struct V_3 * V_3 ;
if ( F_107 () ) {
unsigned int V_83 ;
do {
V_83 = F_108 () ;
V_82 = F_109 () ;
V_3 = F_110 ( V_82 , V_81 , 0 ) ;
} while ( ! V_3 && F_111 ( V_83 ) );
return V_3 ;
}
return F_112 ( V_81 , 0 ) ;
}
T_4 * F_113 ( struct V_3 * V_3 )
{
const struct V_84 * V_84 = F_114 ( V_3 ) ;
return & V_84 -> V_85 [ F_115 ( V_3 , V_84 -> V_86 ) ] ;
}
void F_116 ( struct V_3 * V_3 , int V_87 )
{
F_117 ( V_88 , & V_3 -> V_32 , V_87 ) ;
if ( F_7 ( V_87 , & V_3 -> V_32 ) )
F_118 ( F_113 ( V_3 ) , & V_88 , V_89 ,
V_90 ) ;
}
int F_119 ( struct V_3 * V_3 , int V_87 )
{
F_117 ( V_88 , & V_3 -> V_32 , V_87 ) ;
if ( ! F_7 ( V_87 , & V_3 -> V_32 ) )
return 0 ;
return F_118 ( F_113 ( V_3 ) , & V_88 ,
V_89 , V_91 ) ;
}
int F_120 ( struct V_3 * V_3 ,
int V_87 , unsigned long V_92 )
{
F_117 ( V_88 , & V_3 -> V_32 , V_87 ) ;
V_88 . V_93 . V_92 = V_94 + V_92 ;
if ( ! F_7 ( V_87 , & V_3 -> V_32 ) )
return 0 ;
return F_118 ( F_113 ( V_3 ) , & V_88 ,
V_95 , V_91 ) ;
}
void F_121 ( struct V_3 * V_3 , T_5 * V_96 )
{
T_4 * V_97 = F_113 ( V_3 ) ;
unsigned long V_32 ;
F_45 ( & V_97 -> V_98 , V_32 ) ;
F_122 ( V_97 , V_96 ) ;
F_46 ( & V_97 -> V_98 , V_32 ) ;
}
void F_123 ( struct V_3 * V_3 )
{
V_3 = F_124 ( V_3 ) ;
F_21 ( ! F_3 ( V_3 ) , V_3 ) ;
F_125 ( V_99 , & V_3 -> V_32 ) ;
F_126 () ;
F_127 ( V_3 , V_99 ) ;
}
void F_128 ( struct V_3 * V_3 )
{
if ( F_129 ( V_3 ) ) {
F_130 ( V_3 ) ;
F_131 ( V_3 ) ;
}
if ( ! F_132 ( V_3 ) )
F_133 () ;
F_126 () ;
F_127 ( V_3 , V_100 ) ;
}
void F_134 ( struct V_3 * V_3 , int V_101 , int V_65 )
{
if ( V_101 == V_102 ) {
if ( ! V_65 ) {
F_135 ( V_3 ) ;
} else {
F_136 ( V_3 ) ;
F_137 ( V_3 ) ;
}
F_123 ( V_3 ) ;
} else {
if ( V_65 ) {
F_137 ( V_3 ) ;
if ( V_3 -> V_2 )
F_138 ( V_3 -> V_2 , V_65 ) ;
}
F_128 ( V_3 ) ;
}
}
void F_139 ( struct V_3 * V_3 )
{
struct V_3 * V_103 = F_124 ( V_3 ) ;
F_117 ( V_88 , & V_103 -> V_32 , V_99 ) ;
F_140 ( F_113 ( V_103 ) , & V_88 , V_89 ,
V_90 ) ;
}
int F_141 ( struct V_3 * V_3 )
{
struct V_3 * V_103 = F_124 ( V_3 ) ;
F_117 ( V_88 , & V_103 -> V_32 , V_99 ) ;
return F_140 ( F_113 ( V_103 ) , & V_88 ,
V_89 , V_91 ) ;
}
int F_142 ( struct V_3 * V_3 , struct V_104 * V_79 ,
unsigned int V_32 )
{
if ( V_32 & V_105 ) {
if ( V_32 & V_106 )
return 0 ;
F_143 ( & V_79 -> V_107 ) ;
if ( V_32 & V_108 )
F_144 ( V_3 ) ;
else
F_145 ( V_3 ) ;
return 0 ;
} else {
if ( V_32 & V_108 ) {
int V_35 ;
V_35 = F_141 ( V_3 ) ;
if ( V_35 ) {
F_143 ( & V_79 -> V_107 ) ;
return 0 ;
}
} else
F_139 ( V_3 ) ;
return 1 ;
}
}
T_2 F_146 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_109 )
{
unsigned long V_61 ;
for ( V_61 = 0 ; V_61 < V_109 ; V_61 ++ ) {
struct V_3 * V_3 ;
V_3 = F_147 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_84 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_148 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_109 )
{
unsigned long V_61 ;
for ( V_61 = 0 ; V_61 < V_109 ; V_61 ++ ) {
struct V_3 * V_3 ;
V_3 = F_147 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_84 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_110 )
break;
}
return V_7 ;
}
struct V_3 * F_149 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_111 ;
struct V_3 * V_3 ;
F_150 () ;
V_112:
V_3 = NULL ;
V_111 = F_151 ( & V_2 -> V_11 , V_8 ) ;
if ( V_111 ) {
V_3 = F_152 ( V_111 ) ;
if ( F_24 ( ! V_3 ) )
goto V_58;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) )
goto V_112;
goto V_58;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_111 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
}
V_58:
F_156 () ;
return V_3 ;
}
struct V_3 * F_157 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_112:
V_3 = F_149 ( V_2 , V_8 ) ;
if ( V_3 && ! F_153 ( V_3 ) ) {
F_158 ( V_3 ) ;
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
goto V_112;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_159 ( struct V_1 * V_2 , T_2 V_8 ,
int V_113 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_112:
V_3 = F_149 ( V_2 , V_8 ) ;
if ( F_84 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_114;
if ( V_113 & V_115 ) {
if ( V_113 & V_116 ) {
if ( ! F_160 ( V_3 ) ) {
F_47 ( V_3 ) ;
return NULL ;
}
} else {
F_158 ( V_3 ) ;
}
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
goto V_112;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_113 & V_117 ) )
F_161 ( V_3 ) ;
V_114:
if ( ! V_3 && ( V_113 & V_118 ) ) {
int V_65 ;
if ( ( V_113 & V_119 ) && F_162 ( V_2 ) )
V_14 |= V_120 ;
if ( V_113 & V_121 )
V_14 &= ~ V_122 ;
V_3 = F_106 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_38 ( ! ( V_113 & V_115 ) ) )
V_113 |= V_115 ;
if ( V_113 & V_117 )
F_163 ( V_3 ) ;
V_65 = F_98 ( V_3 , V_2 , V_8 ,
V_14 & V_123 ) ;
if ( F_24 ( V_65 ) ) {
F_47 ( V_3 ) ;
V_3 = NULL ;
if ( V_65 == - V_74 )
goto V_112;
}
}
return V_3 ;
}
unsigned F_164 ( struct V_1 * V_2 ,
T_2 V_40 , unsigned int V_124 ,
struct V_3 * * V_125 , T_2 * V_126 )
{
void * * V_10 ;
unsigned int V_35 = 0 ;
struct V_127 V_128 ;
if ( ! V_124 )
return 0 ;
F_150 () ;
F_165 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
goto V_129;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
V_129:
V_126 [ V_35 ] = V_128 . V_7 ;
V_125 [ V_35 ] = V_3 ;
if ( ++ V_35 == V_124 )
break;
}
F_156 () ;
return V_35 ;
}
unsigned F_167 ( struct V_1 * V_2 , T_2 V_40 ,
unsigned int V_57 , struct V_3 * * V_62 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned V_35 = 0 ;
if ( F_24 ( ! V_57 ) )
return 0 ;
F_150 () ;
F_165 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
continue;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
V_62 [ V_35 ] = V_3 ;
if ( ++ V_35 == V_57 )
break;
}
F_156 () ;
return V_35 ;
}
unsigned F_168 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_57 , struct V_3 * * V_62 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned int V_35 = 0 ;
if ( F_24 ( ! V_57 ) )
return 0 ;
F_150 () ;
F_169 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
break;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
break;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_128 . V_7 ) {
F_47 ( V_3 ) ;
break;
}
V_62 [ V_35 ] = V_3 ;
if ( ++ V_35 == V_57 )
break;
}
F_156 () ;
return V_35 ;
}
unsigned F_170 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_57 , struct V_3 * * V_62 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned V_35 = 0 ;
if ( F_24 ( ! V_57 ) )
return 0 ;
F_150 () ;
F_171 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
continue;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
V_62 [ V_35 ] = V_3 ;
if ( ++ V_35 == V_57 )
break;
}
F_156 () ;
if ( V_35 )
* V_7 = V_62 [ V_35 - 1 ] -> V_7 + 1 ;
return V_35 ;
}
unsigned F_172 ( struct V_1 * V_2 , T_2 V_40 ,
int V_9 , unsigned int V_124 ,
struct V_3 * * V_125 , T_2 * V_126 )
{
void * * V_10 ;
unsigned int V_35 = 0 ;
struct V_127 V_128 ;
if ( ! V_124 )
return 0 ;
F_150 () ;
F_171 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_3 ;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
goto V_129;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
V_129:
V_126 [ V_35 ] = V_128 . V_7 ;
V_125 [ V_35 ] = V_3 ;
if ( ++ V_35 == V_124 )
break;
}
F_156 () ;
return V_35 ;
}
static void F_173 ( struct V_130 * V_131 ,
struct V_132 * V_133 )
{
V_133 -> V_134 /= 4 ;
}
static T_6 F_174 ( struct V_130 * V_131 , T_1 * V_135 ,
struct V_136 * V_128 , T_6 V_137 )
{
struct V_1 * V_2 = V_131 -> V_138 ;
struct V_139 * V_139 = V_2 -> V_31 ;
struct V_132 * V_133 = & V_131 -> V_140 ;
T_2 V_7 ;
T_2 V_141 ;
T_2 V_142 ;
unsigned long V_8 ;
unsigned int V_143 ;
int error = 0 ;
V_7 = * V_135 >> V_54 ;
V_142 = V_133 -> V_144 >> V_54 ;
V_143 = V_133 -> V_144 & ( V_145 - 1 ) ;
V_141 = ( * V_135 + V_128 -> V_146 + V_145 - 1 ) >> V_54 ;
V_8 = * V_135 & ~ V_147 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_148 ;
T_1 V_149 ;
unsigned long V_150 , V_35 ;
F_66 () ;
V_151:
V_3 = F_175 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_176 ( V_2 ,
V_133 , V_131 ,
V_7 , V_141 - V_7 ) ;
V_3 = F_175 ( V_2 , V_7 ) ;
if ( F_24 ( V_3 == NULL ) )
goto V_152;
}
if ( F_177 ( V_3 ) ) {
F_178 ( V_2 ,
V_133 , V_131 , V_3 ,
V_7 , V_141 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
F_144 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_153;
if ( V_139 -> V_154 == V_54 ||
! V_2 -> V_33 -> V_155 )
goto V_156;
if ( ! F_160 ( V_3 ) )
goto V_156;
if ( ! V_3 -> V_2 )
goto V_157;
if ( ! V_2 -> V_33 -> V_155 ( V_3 ,
V_8 , V_128 -> V_146 ) )
goto V_157;
F_123 ( V_3 ) ;
}
V_153:
V_149 = F_69 ( V_139 ) ;
V_148 = ( V_149 - 1 ) >> V_54 ;
if ( F_24 ( ! V_149 || V_7 > V_148 ) ) {
F_47 ( V_3 ) ;
goto V_58;
}
V_150 = V_145 ;
if ( V_7 == V_148 ) {
V_150 = ( ( V_149 - 1 ) & ~ V_147 ) + 1 ;
if ( V_150 <= V_8 ) {
F_47 ( V_3 ) ;
goto V_58;
}
}
V_150 = V_150 - V_8 ;
if ( F_179 ( V_2 ) )
F_180 ( V_3 ) ;
if ( V_142 != V_7 || V_8 != V_143 )
F_161 ( V_3 ) ;
V_142 = V_7 ;
V_35 = F_181 ( V_3 , V_8 , V_150 , V_128 ) ;
V_8 += V_35 ;
V_7 += V_8 >> V_54 ;
V_8 &= ~ V_147 ;
V_143 = V_8 ;
F_47 ( V_3 ) ;
V_137 += V_35 ;
if ( ! F_182 ( V_128 ) )
goto V_58;
if ( V_35 < V_150 ) {
error = - V_158 ;
goto V_58;
}
continue;
V_156:
error = F_183 ( V_3 ) ;
if ( F_24 ( error ) )
goto V_159;
V_157:
if ( ! V_3 -> V_2 ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_123 ( V_3 ) ;
goto V_153;
}
V_160:
F_184 ( V_3 ) ;
error = V_2 -> V_33 -> V_160 ( V_131 , V_3 ) ;
if ( F_24 ( error ) ) {
if ( error == V_161 ) {
F_47 ( V_3 ) ;
error = 0 ;
goto V_151;
}
goto V_159;
}
if ( ! F_17 ( V_3 ) ) {
error = F_183 ( V_3 ) ;
if ( F_24 ( error ) )
goto V_159;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
goto V_151;
}
F_123 ( V_3 ) ;
F_173 ( V_131 , V_133 ) ;
error = - V_39 ;
goto V_159;
}
F_123 ( V_3 ) ;
}
goto V_153;
V_159:
F_47 ( V_3 ) ;
goto V_58;
V_152:
V_3 = F_185 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_162 ;
goto V_58;
}
error = F_98 ( V_3 , V_2 , V_7 ,
F_186 ( V_2 , V_163 ) ) ;
if ( error ) {
F_47 ( V_3 ) ;
if ( error == - V_74 ) {
error = 0 ;
goto V_151;
}
goto V_58;
}
goto V_160;
}
V_58:
V_133 -> V_144 = V_142 ;
V_133 -> V_144 <<= V_54 ;
V_133 -> V_144 |= V_143 ;
* V_135 = ( ( T_1 ) V_7 << V_54 ) + V_8 ;
F_187 ( V_131 ) ;
return V_137 ? V_137 : error ;
}
T_6
F_188 ( struct V_164 * V_165 , struct V_136 * V_128 )
{
struct V_130 * V_130 = V_165 -> V_166 ;
T_6 V_167 = 0 ;
T_1 * V_135 = & V_165 -> V_168 ;
T_1 V_169 = * V_135 ;
T_7 V_146 = F_182 ( V_128 ) ;
if ( ! V_146 )
goto V_58;
if ( V_165 -> V_170 & V_171 ) {
struct V_1 * V_2 = V_130 -> V_138 ;
struct V_139 * V_139 = V_2 -> V_31 ;
T_1 V_172 ;
V_172 = F_69 ( V_139 ) ;
V_167 = F_73 ( V_2 , V_169 ,
V_169 + V_146 - 1 ) ;
if ( ! V_167 ) {
struct V_136 V_173 = * V_128 ;
V_167 = V_2 -> V_33 -> V_174 ( V_165 , & V_173 , V_169 ) ;
}
if ( V_167 > 0 ) {
* V_135 = V_169 + V_167 ;
F_189 ( V_128 , V_167 ) ;
}
if ( V_167 < 0 || ! F_182 ( V_128 ) || * V_135 >= V_172 ||
F_190 ( V_139 ) ) {
F_187 ( V_130 ) ;
goto V_58;
}
}
V_167 = F_174 ( V_130 , V_135 , V_128 , V_167 ) ;
V_58:
return V_167 ;
}
static int F_191 ( struct V_130 * V_130 , T_2 V_8 , T_3 V_14 )
{
struct V_1 * V_2 = V_130 -> V_138 ;
struct V_3 * V_3 ;
int V_35 ;
do {
V_3 = F_106 ( V_14 | V_175 ) ;
if ( ! V_3 )
return - V_162 ;
V_35 = F_98 ( V_3 , V_2 , V_8 , V_14 & V_163 ) ;
if ( V_35 == 0 )
V_35 = V_2 -> V_33 -> V_160 ( V_130 , V_3 ) ;
else if ( V_35 == - V_74 )
V_35 = 0 ;
F_47 ( V_3 ) ;
} while ( V_35 == V_161 );
return V_35 ;
}
static void F_192 ( struct V_176 * V_177 ,
struct V_132 * V_133 ,
struct V_130 * V_130 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_130 -> V_138 ;
if ( V_177 -> V_178 & V_179 )
return;
if ( ! V_133 -> V_134 )
return;
if ( V_177 -> V_178 & V_180 ) {
F_176 ( V_2 , V_133 , V_130 , V_8 ,
V_133 -> V_134 ) ;
return;
}
if ( V_133 -> V_181 < V_182 * 10 )
V_133 -> V_181 ++ ;
if ( V_133 -> V_181 > V_182 )
return;
V_133 -> V_40 = F_193 ( long , 0 , V_8 - V_133 -> V_134 / 2 ) ;
V_133 -> V_172 = V_133 -> V_134 ;
V_133 -> V_183 = V_133 -> V_134 / 4 ;
F_194 ( V_133 , V_2 , V_130 ) ;
}
static void F_195 ( struct V_176 * V_177 ,
struct V_132 * V_133 ,
struct V_130 * V_130 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_130 -> V_138 ;
if ( V_177 -> V_178 & V_179 )
return;
if ( V_133 -> V_181 > 0 )
V_133 -> V_181 -- ;
if ( F_177 ( V_3 ) )
F_178 ( V_2 , V_133 , V_130 ,
V_3 , V_8 , V_133 -> V_134 ) ;
}
int F_196 ( struct V_176 * V_177 , struct V_184 * V_185 )
{
int error ;
struct V_130 * V_130 = V_177 -> V_186 ;
struct V_1 * V_2 = V_130 -> V_138 ;
struct V_132 * V_133 = & V_130 -> V_140 ;
struct V_139 * V_139 = V_2 -> V_31 ;
T_2 V_8 = V_185 -> V_187 ;
struct V_3 * V_3 ;
T_1 V_172 ;
int V_35 = 0 ;
V_172 = F_197 ( F_69 ( V_139 ) , V_145 ) ;
if ( V_8 >= V_172 >> V_54 )
return V_188 ;
V_3 = F_175 ( V_2 , V_8 ) ;
if ( F_198 ( V_3 ) && ! ( V_185 -> V_32 & V_189 ) ) {
F_195 ( V_177 , V_133 , V_130 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_192 ( V_177 , V_133 , V_130 , V_8 ) ;
F_199 ( V_190 ) ;
F_200 ( V_177 -> V_191 , V_190 ) ;
V_35 = V_192 ;
V_193:
V_3 = F_175 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_152;
}
if ( ! F_201 ( V_3 , V_177 -> V_191 , V_185 -> V_32 ) ) {
F_47 ( V_3 ) ;
return V_35 | V_194 ;
}
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
goto V_193;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_24 ( ! F_17 ( V_3 ) ) )
goto V_195;
V_172 = F_197 ( F_69 ( V_139 ) , V_145 ) ;
if ( F_24 ( V_8 >= V_172 >> V_54 ) ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
return V_188 ;
}
V_185 -> V_3 = V_3 ;
return V_35 | V_196 ;
V_152:
error = F_191 ( V_130 , V_8 , V_185 -> V_14 ) ;
if ( error >= 0 )
goto V_193;
if ( error == - V_162 )
return V_197 ;
return V_188 ;
V_195:
F_184 ( V_3 ) ;
error = V_2 -> V_33 -> V_160 ( V_130 , V_3 ) ;
if ( ! error ) {
F_145 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_39 ;
}
F_47 ( V_3 ) ;
if ( ! error || error == V_161 )
goto V_193;
F_173 ( V_130 , V_133 ) ;
return V_188 ;
}
void F_202 ( struct V_176 * V_177 , struct V_184 * V_185 )
{
struct V_127 V_128 ;
void * * V_10 ;
struct V_130 * V_130 = V_177 -> V_186 ;
struct V_1 * V_2 = V_130 -> V_138 ;
T_1 V_172 ;
struct V_3 * V_3 ;
unsigned long V_198 = ( unsigned long ) V_185 -> V_199 ;
unsigned long V_200 ;
T_8 * V_201 ;
F_150 () ;
F_165 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_128 . V_7 > V_185 -> V_202 )
break;
V_112:
V_3 = F_152 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
goto V_203;
if ( F_153 ( V_3 ) ) {
if ( F_154 ( V_3 ) ) {
V_10 = F_166 ( & V_128 ) ;
continue;
}
goto V_203;
}
if ( ! F_155 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_47 ( V_3 ) ;
goto V_112;
}
if ( ! F_17 ( V_3 ) ||
F_177 ( V_3 ) ||
F_203 ( V_3 ) )
goto V_204;
if ( ! F_160 ( V_3 ) )
goto V_204;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_205;
V_172 = F_197 ( F_69 ( V_2 -> V_31 ) , V_145 ) ;
if ( V_3 -> V_7 >= V_172 >> V_54 )
goto V_205;
V_201 = V_185 -> V_201 + V_3 -> V_7 - V_185 -> V_187 ;
if ( ! F_204 ( * V_201 ) )
goto V_205;
if ( V_130 -> V_140 . V_181 > 0 )
V_130 -> V_140 . V_181 -- ;
V_200 = V_198 + ( V_3 -> V_7 - V_185 -> V_187 ) * V_145 ;
F_205 ( V_177 , V_200 , V_3 , V_201 , false , false ) ;
F_123 ( V_3 ) ;
goto V_203;
V_205:
F_123 ( V_3 ) ;
V_204:
F_47 ( V_3 ) ;
V_203:
if ( V_128 . V_7 == V_185 -> V_202 )
break;
}
F_156 () ;
}
int F_206 ( struct V_176 * V_177 , struct V_184 * V_185 )
{
struct V_3 * V_3 = V_185 -> V_3 ;
struct V_139 * V_139 = F_207 ( V_177 -> V_186 ) ;
int V_35 = V_196 ;
F_208 ( V_139 -> V_206 ) ;
F_209 ( V_177 -> V_186 ) ;
F_158 ( V_3 ) ;
if ( V_3 -> V_2 != V_139 -> V_207 ) {
F_123 ( V_3 ) ;
V_35 = V_208 ;
goto V_58;
}
F_210 ( V_3 ) ;
F_211 ( V_3 ) ;
V_58:
F_212 ( V_139 -> V_206 ) ;
return V_35 ;
}
int F_213 ( struct V_130 * V_130 , struct V_176 * V_177 )
{
struct V_1 * V_2 = V_130 -> V_138 ;
if ( ! V_2 -> V_33 -> V_160 )
return - V_209 ;
F_187 ( V_130 ) ;
V_177 -> V_210 = & V_211 ;
return 0 ;
}
int F_214 ( struct V_130 * V_130 , struct V_176 * V_177 )
{
if ( ( V_177 -> V_178 & V_212 ) && ( V_177 -> V_178 & V_213 ) )
return - V_75 ;
return F_213 ( V_130 , V_177 ) ;
}
int F_213 ( struct V_130 * V_130 , struct V_176 * V_177 )
{
return - V_214 ;
}
int F_214 ( struct V_130 * V_130 , struct V_176 * V_177 )
{
return - V_214 ;
}
static struct V_3 * F_215 ( struct V_3 * V_3 )
{
if ( ! F_216 ( V_3 ) ) {
F_145 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_47 ( V_3 ) ;
V_3 = F_217 ( - V_39 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_218 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_219)( void * , struct V_3 * ) ,
void * V_173 ,
T_3 V_81 )
{
struct V_3 * V_3 ;
int V_65 ;
V_112:
V_3 = F_175 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_106 ( V_81 | V_175 ) ;
if ( ! V_3 )
return F_217 ( - V_162 ) ;
V_65 = F_98 ( V_3 , V_2 , V_7 , V_81 ) ;
if ( F_24 ( V_65 ) ) {
F_47 ( V_3 ) ;
if ( V_65 == - V_74 )
goto V_112;
return F_217 ( V_65 ) ;
}
F_219:
V_65 = F_219 ( V_173 , V_3 ) ;
if ( V_65 < 0 ) {
F_47 ( V_3 ) ;
return F_217 ( V_65 ) ;
}
V_3 = F_215 ( V_3 ) ;
if ( F_216 ( V_3 ) )
return V_3 ;
goto V_58;
}
if ( F_17 ( V_3 ) )
goto V_58;
F_145 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_58;
F_158 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_123 ( V_3 ) ;
F_47 ( V_3 ) ;
goto V_112;
}
if ( F_17 ( V_3 ) ) {
F_123 ( V_3 ) ;
goto V_58;
}
goto F_219;
V_58:
F_161 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_220 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_219)( void * , struct V_3 * ) ,
void * V_173 )
{
return F_218 ( V_2 , V_7 , F_219 , V_173 , F_221 ( V_2 ) ) ;
}
struct V_3 * F_222 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_81 )
{
T_9 * F_219 = ( T_9 * ) V_2 -> V_33 -> V_160 ;
return F_218 ( V_2 , V_7 , F_219 , NULL , V_81 ) ;
}
inline T_6 F_223 ( struct V_164 * V_165 , struct V_136 * V_215 )
{
struct V_130 * V_130 = V_165 -> V_166 ;
struct V_139 * V_139 = V_130 -> V_138 -> V_31 ;
unsigned long V_216 = F_224 ( V_217 ) ;
T_1 V_169 ;
if ( ! F_182 ( V_215 ) )
return 0 ;
if ( V_165 -> V_170 & V_218 )
V_165 -> V_168 = F_69 ( V_139 ) ;
V_169 = V_165 -> V_168 ;
if ( V_216 != V_219 ) {
if ( V_165 -> V_168 >= V_216 ) {
F_225 ( V_220 , V_24 , 0 ) ;
return - V_221 ;
}
F_226 ( V_215 , V_216 - ( unsigned long ) V_169 ) ;
}
if ( F_24 ( V_169 + F_182 ( V_215 ) > V_222 &&
! ( V_130 -> V_223 & V_224 ) ) ) {
if ( V_169 >= V_222 )
return - V_221 ;
F_226 ( V_215 , V_222 - ( unsigned long ) V_169 ) ;
}
if ( F_24 ( V_169 >= V_139 -> V_206 -> V_225 ) )
return - V_221 ;
F_226 ( V_215 , V_139 -> V_206 -> V_225 - V_169 ) ;
return F_182 ( V_215 ) ;
}
int F_227 ( struct V_130 * V_130 , struct V_1 * V_2 ,
T_1 V_169 , unsigned V_226 , unsigned V_32 ,
struct V_3 * * V_111 , void * * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_33 ;
return V_229 -> V_230 ( V_130 , V_2 , V_169 , V_226 , V_32 ,
V_111 , V_227 ) ;
}
int F_228 ( struct V_130 * V_130 , struct V_1 * V_2 ,
T_1 V_169 , unsigned V_226 , unsigned V_231 ,
struct V_3 * V_3 , void * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_33 ;
return V_229 -> V_232 ( V_130 , V_2 , V_169 , V_226 , V_231 , V_3 , V_227 ) ;
}
T_6
F_229 ( struct V_164 * V_165 , struct V_136 * V_215 , T_1 V_169 )
{
struct V_130 * V_130 = V_165 -> V_166 ;
struct V_1 * V_2 = V_130 -> V_138 ;
struct V_139 * V_139 = V_2 -> V_31 ;
T_6 V_137 ;
T_7 V_233 ;
T_2 V_41 ;
struct V_136 V_173 ;
V_233 = F_182 ( V_215 ) ;
V_41 = ( V_169 + V_233 - 1 ) >> V_54 ;
V_137 = F_73 ( V_2 , V_169 , V_169 + V_233 - 1 ) ;
if ( V_137 )
goto V_58;
if ( V_2 -> V_13 ) {
V_137 = F_230 ( V_2 ,
V_169 >> V_54 , V_41 ) ;
if ( V_137 ) {
if ( V_137 == - V_234 )
return 0 ;
goto V_58;
}
}
V_173 = * V_215 ;
V_137 = V_2 -> V_33 -> V_174 ( V_165 , & V_173 , V_169 ) ;
if ( V_2 -> V_13 ) {
F_230 ( V_2 ,
V_169 >> V_54 , V_41 ) ;
}
if ( V_137 > 0 ) {
V_169 += V_137 ;
F_189 ( V_215 , V_137 ) ;
if ( V_169 > F_69 ( V_139 ) && ! F_231 ( V_139 -> V_235 ) ) {
F_232 ( V_139 , V_169 ) ;
F_233 ( V_139 ) ;
}
V_165 -> V_168 = V_169 ;
}
V_58:
return V_137 ;
}
struct V_3 * F_234 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_32 )
{
struct V_3 * V_3 ;
int V_113 = V_115 | V_117 | V_119 | V_118 ;
if ( V_32 & V_236 )
V_113 |= V_121 ;
V_3 = F_159 ( V_2 , V_7 , V_113 ,
F_221 ( V_2 ) ) ;
if ( V_3 )
F_211 ( V_3 ) ;
return V_3 ;
}
T_6 F_235 ( struct V_130 * V_130 ,
struct V_136 * V_61 , T_1 V_169 )
{
struct V_1 * V_2 = V_130 -> V_138 ;
const struct V_228 * V_33 = V_2 -> V_33 ;
long V_237 = 0 ;
T_6 V_137 = 0 ;
unsigned int V_32 = 0 ;
if ( ! F_236 ( V_61 ) )
V_32 |= V_238 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_239 ;
T_7 V_231 ;
void * V_227 ;
V_8 = ( V_169 & ( V_145 - 1 ) ) ;
V_239 = F_237 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_240:
if ( F_24 ( F_238 ( V_61 , V_239 ) ) ) {
V_237 = - V_158 ;
break;
}
if ( F_239 ( V_24 ) ) {
V_237 = - V_241 ;
break;
}
V_237 = V_33 -> V_230 ( V_130 , V_2 , V_169 , V_239 , V_32 ,
& V_3 , & V_227 ) ;
if ( F_24 ( V_237 < 0 ) )
break;
if ( F_179 ( V_2 ) )
F_180 ( V_3 ) ;
V_231 = F_240 ( V_3 , V_61 , V_8 , V_239 ) ;
F_180 ( V_3 ) ;
V_237 = V_33 -> V_232 ( V_130 , V_2 , V_169 , V_239 , V_231 ,
V_3 , V_227 ) ;
if ( F_24 ( V_237 < 0 ) )
break;
V_231 = V_237 ;
F_66 () ;
F_189 ( V_61 , V_231 ) ;
if ( F_24 ( V_231 == 0 ) ) {
V_239 = F_237 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_240;
}
V_169 += V_231 ;
V_137 += V_231 ;
F_241 ( V_2 ) ;
} while ( F_182 ( V_61 ) );
return V_137 ? V_137 : V_237 ;
}
T_6 F_242 ( struct V_164 * V_165 , struct V_136 * V_215 )
{
struct V_130 * V_130 = V_165 -> V_166 ;
struct V_1 * V_2 = V_130 -> V_138 ;
struct V_139 * V_139 = V_2 -> V_31 ;
T_6 V_137 = 0 ;
T_6 V_65 ;
T_6 V_237 ;
V_24 -> V_242 = F_243 ( V_139 ) ;
V_65 = F_244 ( V_130 ) ;
if ( V_65 )
goto V_58;
V_65 = F_209 ( V_130 ) ;
if ( V_65 )
goto V_58;
if ( V_165 -> V_170 & V_171 ) {
T_1 V_169 , V_243 ;
V_137 = F_229 ( V_165 , V_215 , V_165 -> V_168 ) ;
if ( V_137 < 0 || ! F_182 ( V_215 ) || F_190 ( V_139 ) )
goto V_58;
V_237 = F_235 ( V_130 , V_215 , V_169 = V_165 -> V_168 ) ;
if ( F_24 ( V_237 < 0 ) ) {
V_65 = V_237 ;
goto V_58;
}
V_243 = V_169 + V_237 - 1 ;
V_65 = F_73 ( V_2 , V_169 , V_243 ) ;
if ( V_65 == 0 ) {
V_165 -> V_168 = V_243 + 1 ;
V_137 += V_237 ;
F_245 ( V_2 ,
V_169 >> V_54 ,
V_243 >> V_54 ) ;
} else {
}
} else {
V_137 = F_235 ( V_130 , V_215 , V_165 -> V_168 ) ;
if ( F_198 ( V_137 > 0 ) )
V_165 -> V_168 += V_137 ;
}
V_58:
V_24 -> V_242 = NULL ;
return V_137 ? V_137 : V_65 ;
}
T_6 F_246 ( struct V_164 * V_165 , struct V_136 * V_215 )
{
struct V_130 * V_130 = V_165 -> V_166 ;
struct V_139 * V_139 = V_130 -> V_138 -> V_31 ;
T_6 V_35 ;
F_247 ( V_139 ) ;
V_35 = F_223 ( V_165 , V_215 ) ;
if ( V_35 > 0 )
V_35 = F_242 ( V_165 , V_215 ) ;
F_248 ( V_139 ) ;
if ( V_35 > 0 ) {
T_6 V_65 ;
V_65 = F_249 ( V_130 , V_165 -> V_168 - V_35 , V_35 ) ;
if ( V_65 < 0 )
V_35 = V_65 ;
}
return V_35 ;
}
int F_250 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_44 ( ! F_3 ( V_3 ) ) ;
if ( F_251 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_33 -> V_244 )
return V_2 -> V_33 -> V_244 ( V_3 , V_14 ) ;
return F_252 ( V_3 ) ;
}
