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
F_21 ( F_22 ( V_3 ) , V_3 ) ;
if ( ! F_23 ( V_24 ) && F_24 ( F_22 ( V_3 ) ) ) {
int V_25 ;
F_25 ( L_1 ,
V_26 -> V_27 , F_26 ( V_3 ) ) ;
F_27 ( V_3 , L_2 ) ;
F_28 () ;
F_29 ( V_28 , V_29 ) ;
V_25 = F_30 ( V_3 ) ;
if ( F_31 ( V_2 ) &&
F_32 ( V_3 ) >= V_25 + 2 ) {
F_33 ( V_3 ) ;
F_34 ( V_25 , & V_3 -> V_30 ) ;
}
}
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_35 ( V_3 ) )
F_36 ( V_3 , V_31 ) ;
if ( F_37 ( V_3 ) )
F_36 ( V_3 , V_32 ) ;
if ( F_38 ( F_39 ( V_3 ) ) )
F_40 ( V_3 , V_2 , V_23 ,
F_41 ( V_2 -> V_33 ) ) ;
}
void F_42 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
struct V_22 * V_23 ;
unsigned long V_34 ;
void (* F_43)( struct V_3 * );
F_44 ( ! F_3 ( V_3 ) ) ;
F_43 = V_2 -> V_35 -> F_43 ;
V_23 = F_45 ( V_3 ) ;
F_46 ( & V_2 -> V_36 , V_34 ) ;
F_15 ( V_3 , NULL , V_23 ) ;
F_47 ( & V_2 -> V_36 , V_34 ) ;
F_48 ( V_23 ) ;
if ( F_43 )
F_43 ( V_3 ) ;
F_49 ( V_3 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
if ( F_7 ( V_38 , & V_2 -> V_34 ) &&
F_51 ( V_38 , & V_2 -> V_34 ) )
V_37 = - V_39 ;
if ( F_7 ( V_40 , & V_2 -> V_34 ) &&
F_51 ( V_40 , & V_2 -> V_34 ) )
V_37 = - V_41 ;
return V_37 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_42 ,
T_1 V_43 , int V_44 )
{
int V_37 ;
struct V_45 V_46 = {
. V_44 = V_44 ,
. V_47 = V_48 ,
. V_49 = V_42 ,
. V_50 = V_43 ,
} ;
if ( ! F_53 ( V_2 ) )
return 0 ;
F_54 ( & V_46 , V_2 -> V_33 ) ;
V_37 = F_55 ( V_2 , & V_46 ) ;
F_56 ( & V_46 ) ;
return V_37 ;
}
static inline int F_57 ( struct V_1 * V_2 ,
int V_44 )
{
return F_52 ( V_2 , 0 , V_51 , V_44 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_52 ) ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_42 ,
T_1 V_43 )
{
return F_52 ( V_2 , V_42 , V_43 , V_52 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_53 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
T_1 V_54 , T_1 V_55 )
{
T_2 V_7 = V_54 >> V_56 ;
T_2 V_43 = V_55 >> V_56 ;
struct V_57 V_58 ;
int V_59 ;
int V_37 = 0 ;
if ( V_55 < V_54 )
goto V_60;
F_62 ( & V_58 , 0 ) ;
while ( ( V_7 <= V_43 ) &&
( V_59 = F_63 ( & V_58 , V_2 , & V_7 ,
V_61 ,
F_64 ( V_43 - V_7 , ( T_2 ) V_62 - 1 ) + 1 ) ) != 0 ) {
unsigned V_63 ;
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
struct V_3 * V_3 = V_58 . V_64 [ V_63 ] ;
if ( V_3 -> V_7 > V_43 )
continue;
F_65 ( V_3 ) ;
if ( F_66 ( V_3 ) )
V_37 = - V_41 ;
}
F_67 ( & V_58 ) ;
F_68 () ;
}
V_60:
return V_37 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_54 ,
T_1 V_55 )
{
int V_37 , V_65 ;
V_37 = F_61 ( V_2 , V_54 , V_55 ) ;
V_65 = F_50 ( V_2 ) ;
if ( ! V_37 )
V_37 = V_65 ;
return V_37 ;
}
void F_70 ( struct V_1 * V_2 )
{
T_1 V_66 = F_71 ( V_2 -> V_33 ) ;
if ( V_66 == 0 )
return;
F_61 ( V_2 , 0 , V_66 - 1 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
T_1 V_66 = F_71 ( V_2 -> V_33 ) ;
if ( V_66 == 0 )
return 0 ;
return F_69 ( V_2 , 0 , V_66 - 1 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
if ( ( ! F_74 ( V_2 ) && V_2 -> V_13 ) ||
( F_74 ( V_2 ) && V_2 -> V_12 ) ) {
V_67 = F_58 ( V_2 ) ;
if ( V_67 != - V_41 ) {
int V_68 = F_72 ( V_2 ) ;
if ( ! V_67 )
V_67 = V_68 ;
}
} else {
V_67 = F_50 ( V_2 ) ;
}
return V_67 ;
}
int F_75 ( struct V_1 * V_2 ,
T_1 V_69 , T_1 V_70 )
{
int V_67 = 0 ;
if ( ( ! F_74 ( V_2 ) && V_2 -> V_13 ) ||
( F_74 ( V_2 ) && V_2 -> V_12 ) ) {
V_67 = F_52 ( V_2 , V_69 , V_70 ,
V_52 ) ;
if ( V_67 != - V_41 ) {
int V_68 = F_69 ( V_2 ,
V_69 , V_70 ) ;
if ( ! V_67 )
V_67 = V_68 ;
}
} else {
V_67 = F_50 ( V_2 ) ;
}
return V_67 ;
}
int F_76 ( struct V_3 * V_71 , struct V_3 * V_72 , T_3 V_14 )
{
int error ;
F_21 ( ! F_3 ( V_71 ) , V_71 ) ;
F_21 ( ! F_3 ( V_72 ) , V_72 ) ;
F_21 ( V_72 -> V_2 , V_72 ) ;
error = F_77 ( V_14 & ~ V_73 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_71 -> V_2 ;
void (* F_43)( struct V_3 * );
struct V_22 * V_23 ;
unsigned long V_34 ;
T_2 V_8 = V_71 -> V_7 ;
F_43 = V_2 -> V_35 -> F_43 ;
F_78 ( V_72 ) ;
V_72 -> V_2 = V_2 ;
V_72 -> V_7 = V_8 ;
V_23 = F_45 ( V_71 ) ;
F_46 ( & V_2 -> V_36 , V_34 ) ;
F_15 ( V_71 , NULL , V_23 ) ;
error = F_79 ( & V_2 -> V_11 , V_8 , V_72 ) ;
F_44 ( error ) ;
V_2 -> V_13 ++ ;
if ( ! F_35 ( V_72 ) )
F_80 ( V_72 , V_31 ) ;
if ( F_37 ( V_72 ) )
F_80 ( V_72 , V_32 ) ;
F_47 ( & V_2 -> V_36 , V_34 ) ;
F_48 ( V_23 ) ;
F_81 ( V_71 , V_72 ) ;
F_82 () ;
if ( F_43 )
F_43 ( V_71 ) ;
F_49 ( V_71 ) ;
}
return error ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_74 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_84 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_75 ;
V_75 = F_85 ( V_10 , & V_2 -> V_36 ) ;
if ( ! F_86 ( V_75 ) )
return - V_76 ;
if ( F_87 ( F_74 ( V_2 ) ) )
return - V_77 ;
if ( V_74 )
* V_74 = V_75 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_88 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_89 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_90 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_91 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_74 )
{
int V_78 = F_35 ( V_3 ) ;
struct V_22 * V_23 ;
int error ;
F_21 ( ! F_3 ( V_3 ) , V_3 ) ;
F_21 ( F_37 ( V_3 ) , V_3 ) ;
if ( ! V_78 ) {
error = F_92 ( V_3 , V_26 -> V_79 ,
V_14 , & V_23 , false ) ;
if ( error )
return error ;
}
error = F_93 ( V_14 & ~ V_73 ) ;
if ( error ) {
if ( ! V_78 )
F_94 ( V_3 , V_23 , false ) ;
return error ;
}
F_78 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_95 ( & V_2 -> V_36 ) ;
error = F_83 ( V_2 , V_3 , V_74 ) ;
F_82 () ;
if ( F_24 ( error ) )
goto V_80;
if ( ! V_78 )
F_80 ( V_3 , V_31 ) ;
F_96 ( & V_2 -> V_36 ) ;
if ( ! V_78 )
F_97 ( V_3 , V_23 , false , false ) ;
F_98 ( V_3 ) ;
return 0 ;
V_80:
V_3 -> V_2 = NULL ;
F_96 ( & V_2 -> V_36 ) ;
if ( ! V_78 )
F_94 ( V_3 , V_23 , false ) ;
F_49 ( V_3 ) ;
return error ;
}
int F_99 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_91 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_100 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_37 ;
F_101 ( V_3 ) ;
V_37 = F_91 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_24 ( V_37 ) )
F_102 ( V_3 ) ;
else {
if ( V_4 && F_103 ( V_4 ) ) {
F_104 ( V_3 ) ;
F_105 ( V_3 ) ;
} else
F_106 ( V_3 ) ;
F_107 ( V_3 ) ;
}
return V_37 ;
}
struct V_3 * F_108 ( T_3 V_81 )
{
int V_82 ;
struct V_3 * V_3 ;
if ( F_109 () ) {
unsigned int V_83 ;
do {
V_83 = F_110 () ;
V_82 = F_111 () ;
V_3 = F_112 ( V_82 , V_81 , 0 ) ;
} while ( ! V_3 && F_113 ( V_83 ) );
return V_3 ;
}
return F_114 ( V_81 , 0 ) ;
}
T_4 * F_115 ( struct V_3 * V_3 )
{
const struct V_84 * V_84 = F_116 ( V_3 ) ;
return & V_84 -> V_85 [ F_117 ( V_3 , V_84 -> V_86 ) ] ;
}
void F_118 ( struct V_3 * V_3 , int V_87 )
{
F_119 ( V_88 , & V_3 -> V_34 , V_87 ) ;
if ( F_7 ( V_87 , & V_3 -> V_34 ) )
F_120 ( F_115 ( V_3 ) , & V_88 , V_89 ,
V_90 ) ;
}
int F_121 ( struct V_3 * V_3 , int V_87 )
{
F_119 ( V_88 , & V_3 -> V_34 , V_87 ) ;
if ( ! F_7 ( V_87 , & V_3 -> V_34 ) )
return 0 ;
return F_120 ( F_115 ( V_3 ) , & V_88 ,
V_89 , V_91 ) ;
}
int F_122 ( struct V_3 * V_3 ,
int V_87 , unsigned long V_92 )
{
F_119 ( V_88 , & V_3 -> V_34 , V_87 ) ;
V_88 . V_93 . V_92 = V_94 + V_92 ;
if ( ! F_7 ( V_87 , & V_3 -> V_34 ) )
return 0 ;
return F_120 ( F_115 ( V_3 ) , & V_88 ,
V_95 , V_91 ) ;
}
void F_123 ( struct V_3 * V_3 , T_5 * V_96 )
{
T_4 * V_97 = F_115 ( V_3 ) ;
unsigned long V_34 ;
F_46 ( & V_97 -> V_98 , V_34 ) ;
F_124 ( V_97 , V_96 ) ;
F_47 ( & V_97 -> V_98 , V_34 ) ;
}
void F_125 ( struct V_3 * V_3 )
{
V_3 = F_126 ( V_3 ) ;
F_21 ( ! F_3 ( V_3 ) , V_3 ) ;
F_127 ( V_99 , & V_3 -> V_34 ) ;
F_128 () ;
F_129 ( V_3 , V_99 ) ;
}
void F_130 ( struct V_3 * V_3 )
{
if ( F_131 ( V_3 ) ) {
F_132 ( V_3 ) ;
F_133 ( V_3 ) ;
}
if ( ! F_134 ( V_3 ) )
F_135 () ;
F_128 () ;
F_129 ( V_3 , V_100 ) ;
}
void F_136 ( struct V_3 * V_3 , int V_101 , int V_67 )
{
if ( V_101 == V_102 ) {
if ( ! V_67 ) {
F_137 ( V_3 ) ;
} else {
F_138 ( V_3 ) ;
F_139 ( V_3 ) ;
}
F_125 ( V_3 ) ;
} else {
if ( V_67 ) {
F_139 ( V_3 ) ;
if ( V_3 -> V_2 )
F_140 ( V_3 -> V_2 , V_67 ) ;
}
F_130 ( V_3 ) ;
}
}
void F_141 ( struct V_3 * V_3 )
{
struct V_3 * V_103 = F_126 ( V_3 ) ;
F_119 ( V_88 , & V_103 -> V_34 , V_99 ) ;
F_142 ( F_115 ( V_103 ) , & V_88 , V_89 ,
V_90 ) ;
}
int F_143 ( struct V_3 * V_3 )
{
struct V_3 * V_103 = F_126 ( V_3 ) ;
F_119 ( V_88 , & V_103 -> V_34 , V_99 ) ;
return F_142 ( F_115 ( V_103 ) , & V_88 ,
V_89 , V_91 ) ;
}
int F_144 ( struct V_3 * V_3 , struct V_104 * V_79 ,
unsigned int V_34 )
{
if ( V_34 & V_105 ) {
if ( V_34 & V_106 )
return 0 ;
F_145 ( & V_79 -> V_107 ) ;
if ( V_34 & V_108 )
F_146 ( V_3 ) ;
else
F_147 ( V_3 ) ;
return 0 ;
} else {
if ( V_34 & V_108 ) {
int V_37 ;
V_37 = F_143 ( V_3 ) ;
if ( V_37 ) {
F_145 ( & V_79 -> V_107 ) ;
return 0 ;
}
} else
F_141 ( V_3 ) ;
return 1 ;
}
}
T_2 F_148 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_109 )
{
unsigned long V_63 ;
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
struct V_3 * V_3 ;
V_3 = F_149 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_86 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_150 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_109 )
{
unsigned long V_63 ;
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
struct V_3 * V_3 ;
V_3 = F_149 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_86 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_110 )
break;
}
return V_7 ;
}
struct V_3 * F_151 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_111 ;
struct V_3 * V_3 ;
F_152 () ;
V_112:
V_3 = NULL ;
V_111 = F_153 ( & V_2 -> V_11 , V_8 ) ;
if ( V_111 ) {
V_3 = F_154 ( V_111 ) ;
if ( F_24 ( ! V_3 ) )
goto V_60;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) )
goto V_112;
goto V_60;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_111 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
}
V_60:
F_158 () ;
return V_3 ;
}
struct V_3 * F_159 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_112:
V_3 = F_151 ( V_2 , V_8 ) ;
if ( V_3 && ! F_155 ( V_3 ) ) {
F_160 ( V_3 ) ;
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_112;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_161 ( struct V_1 * V_2 , T_2 V_8 ,
int V_113 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_112:
V_3 = F_151 ( V_2 , V_8 ) ;
if ( F_86 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_114;
if ( V_113 & V_115 ) {
if ( V_113 & V_116 ) {
if ( ! F_162 ( V_3 ) ) {
F_49 ( V_3 ) ;
return NULL ;
}
} else {
F_160 ( V_3 ) ;
}
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_112;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_113 & V_117 ) )
F_163 ( V_3 ) ;
V_114:
if ( ! V_3 && ( V_113 & V_118 ) ) {
int V_67 ;
if ( ( V_113 & V_119 ) && F_164 ( V_2 ) )
V_14 |= V_120 ;
if ( V_113 & V_121 )
V_14 &= ~ V_122 ;
V_3 = F_108 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_38 ( ! ( V_113 & V_115 ) ) )
V_113 |= V_115 ;
if ( V_113 & V_117 )
F_165 ( V_3 ) ;
V_67 = F_100 ( V_3 , V_2 , V_8 ,
V_14 & V_123 ) ;
if ( F_24 ( V_67 ) ) {
F_49 ( V_3 ) ;
V_3 = NULL ;
if ( V_67 == - V_76 )
goto V_112;
}
}
return V_3 ;
}
unsigned F_166 ( struct V_1 * V_2 ,
T_2 V_42 , unsigned int V_124 ,
struct V_3 * * V_125 , T_2 * V_126 )
{
void * * V_10 ;
unsigned int V_37 = 0 ;
struct V_127 V_128 ;
if ( ! V_124 )
return 0 ;
F_152 () ;
V_129:
F_167 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) )
goto V_129;
goto V_130;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
V_130:
V_126 [ V_37 ] = V_128 . V_7 ;
V_125 [ V_37 ] = V_3 ;
if ( ++ V_37 == V_124 )
break;
}
F_158 () ;
return V_37 ;
}
unsigned F_168 ( struct V_1 * V_2 , T_2 V_42 ,
unsigned int V_59 , struct V_3 * * V_64 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned V_37 = 0 ;
if ( F_24 ( ! V_59 ) )
return 0 ;
F_152 () ;
V_129:
F_167 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) ) {
F_87 ( V_128 . V_7 ) ;
goto V_129;
}
continue;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
V_64 [ V_37 ] = V_3 ;
if ( ++ V_37 == V_59 )
break;
}
F_158 () ;
return V_37 ;
}
unsigned F_169 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_59 , struct V_3 * * V_64 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned int V_37 = 0 ;
if ( F_24 ( ! V_59 ) )
return 0 ;
F_152 () ;
V_129:
F_170 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
break;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) ) {
goto V_129;
}
break;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_128 . V_7 ) {
F_49 ( V_3 ) ;
break;
}
V_64 [ V_37 ] = V_3 ;
if ( ++ V_37 == V_59 )
break;
}
F_158 () ;
return V_37 ;
}
unsigned F_171 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_59 , struct V_3 * * V_64 )
{
struct V_127 V_128 ;
void * * V_10 ;
unsigned V_37 = 0 ;
if ( F_24 ( ! V_59 ) )
return 0 ;
F_152 () ;
V_129:
F_172 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) ) {
goto V_129;
}
continue;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
V_64 [ V_37 ] = V_3 ;
if ( ++ V_37 == V_59 )
break;
}
F_158 () ;
if ( V_37 )
* V_7 = V_64 [ V_37 - 1 ] -> V_7 + 1 ;
return V_37 ;
}
unsigned F_173 ( struct V_1 * V_2 , T_2 V_42 ,
int V_9 , unsigned int V_124 ,
struct V_3 * * V_125 , T_2 * V_126 )
{
void * * V_10 ;
unsigned int V_37 = 0 ;
struct V_127 V_128 ;
if ( ! V_124 )
return 0 ;
F_152 () ;
V_129:
F_172 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_3 ;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
continue;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) ) {
goto V_129;
}
goto V_130;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
V_130:
V_126 [ V_37 ] = V_128 . V_7 ;
V_125 [ V_37 ] = V_3 ;
if ( ++ V_37 == V_124 )
break;
}
F_158 () ;
return V_37 ;
}
static void F_174 ( struct V_131 * V_132 ,
struct V_133 * V_134 )
{
V_134 -> V_135 /= 4 ;
}
static T_6 F_175 ( struct V_131 * V_132 , T_1 * V_136 ,
struct V_137 * V_128 , T_6 V_138 )
{
struct V_1 * V_2 = V_132 -> V_139 ;
struct V_140 * V_140 = V_2 -> V_33 ;
struct V_133 * V_134 = & V_132 -> V_141 ;
T_2 V_7 ;
T_2 V_142 ;
T_2 V_143 ;
unsigned long V_8 ;
unsigned int V_144 ;
int error = 0 ;
V_7 = * V_136 >> V_56 ;
V_143 = V_134 -> V_145 >> V_56 ;
V_144 = V_134 -> V_145 & ( V_146 - 1 ) ;
V_142 = ( * V_136 + V_128 -> V_147 + V_146 - 1 ) >> V_56 ;
V_8 = * V_136 & ~ V_148 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_149 ;
T_1 V_150 ;
unsigned long V_151 , V_37 ;
F_68 () ;
V_152:
V_3 = F_176 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_177 ( V_2 ,
V_134 , V_132 ,
V_7 , V_142 - V_7 ) ;
V_3 = F_176 ( V_2 , V_7 ) ;
if ( F_24 ( V_3 == NULL ) )
goto V_153;
}
if ( F_178 ( V_3 ) ) {
F_179 ( V_2 ,
V_134 , V_132 , V_3 ,
V_7 , V_142 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_140 -> V_154 == V_56 ||
! V_2 -> V_35 -> V_155 )
goto V_156;
if ( ! F_162 ( V_3 ) )
goto V_156;
if ( ! V_3 -> V_2 )
goto V_157;
if ( ! V_2 -> V_35 -> V_155 ( V_3 ,
V_8 , V_128 -> V_147 ) )
goto V_157;
F_125 ( V_3 ) ;
}
V_158:
V_150 = F_71 ( V_140 ) ;
V_149 = ( V_150 - 1 ) >> V_56 ;
if ( F_24 ( ! V_150 || V_7 > V_149 ) ) {
F_49 ( V_3 ) ;
goto V_60;
}
V_151 = V_146 ;
if ( V_7 == V_149 ) {
V_151 = ( ( V_150 - 1 ) & ~ V_148 ) + 1 ;
if ( V_151 <= V_8 ) {
F_49 ( V_3 ) ;
goto V_60;
}
}
V_151 = V_151 - V_8 ;
if ( F_180 ( V_2 ) )
F_181 ( V_3 ) ;
if ( V_143 != V_7 || V_8 != V_144 )
F_163 ( V_3 ) ;
V_143 = V_7 ;
V_37 = F_182 ( V_3 , V_8 , V_151 , V_128 ) ;
V_8 += V_37 ;
V_7 += V_8 >> V_56 ;
V_8 &= ~ V_148 ;
V_144 = V_8 ;
F_49 ( V_3 ) ;
V_138 += V_37 ;
if ( ! F_183 ( V_128 ) )
goto V_60;
if ( V_37 < V_151 ) {
error = - V_159 ;
goto V_60;
}
continue;
V_156:
error = F_184 ( V_3 ) ;
if ( F_24 ( error ) )
goto V_160;
V_157:
if ( ! V_3 -> V_2 ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_125 ( V_3 ) ;
goto V_158;
}
V_161:
F_185 ( V_3 ) ;
error = V_2 -> V_35 -> V_161 ( V_132 , V_3 ) ;
if ( F_24 ( error ) ) {
if ( error == V_162 ) {
F_49 ( V_3 ) ;
error = 0 ;
goto V_152;
}
goto V_160;
}
if ( ! F_17 ( V_3 ) ) {
error = F_184 ( V_3 ) ;
if ( F_24 ( error ) )
goto V_160;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_152;
}
F_125 ( V_3 ) ;
F_174 ( V_132 , V_134 ) ;
error = - V_41 ;
goto V_160;
}
F_125 ( V_3 ) ;
}
goto V_158;
V_160:
F_49 ( V_3 ) ;
goto V_60;
V_153:
V_3 = F_186 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_163 ;
goto V_60;
}
error = F_100 ( V_3 , V_2 , V_7 ,
F_187 ( V_2 , V_164 ) ) ;
if ( error ) {
F_49 ( V_3 ) ;
if ( error == - V_76 ) {
error = 0 ;
goto V_152;
}
goto V_60;
}
goto V_161;
}
V_60:
V_134 -> V_145 = V_143 ;
V_134 -> V_145 <<= V_56 ;
V_134 -> V_145 |= V_144 ;
* V_136 = ( ( T_1 ) V_7 << V_56 ) + V_8 ;
F_188 ( V_132 ) ;
return V_138 ? V_138 : error ;
}
T_6
F_189 ( struct V_165 * V_166 , struct V_137 * V_128 )
{
struct V_131 * V_131 = V_166 -> V_167 ;
T_6 V_168 = 0 ;
T_1 * V_136 = & V_166 -> V_169 ;
T_1 V_170 = * V_136 ;
if ( V_166 -> V_171 & V_172 ) {
struct V_1 * V_2 = V_131 -> V_139 ;
struct V_140 * V_140 = V_2 -> V_33 ;
T_7 V_147 = F_183 ( V_128 ) ;
T_1 V_173 ;
if ( ! V_147 )
goto V_60;
V_173 = F_71 ( V_140 ) ;
V_168 = F_75 ( V_2 , V_170 ,
V_170 + V_147 - 1 ) ;
if ( ! V_168 ) {
struct V_137 V_174 = * V_128 ;
V_168 = V_2 -> V_35 -> V_175 ( V_166 , & V_174 , V_170 ) ;
}
if ( V_168 > 0 ) {
* V_136 = V_170 + V_168 ;
F_190 ( V_128 , V_168 ) ;
}
if ( V_168 < 0 || ! F_183 ( V_128 ) || * V_136 >= V_173 ||
F_191 ( V_140 ) ) {
F_188 ( V_131 ) ;
goto V_60;
}
}
V_168 = F_175 ( V_131 , V_136 , V_128 , V_168 ) ;
V_60:
return V_168 ;
}
static int F_192 ( struct V_131 * V_131 , T_2 V_8 , T_3 V_14 )
{
struct V_1 * V_2 = V_131 -> V_139 ;
struct V_3 * V_3 ;
int V_37 ;
do {
V_3 = F_108 ( V_14 | V_176 ) ;
if ( ! V_3 )
return - V_163 ;
V_37 = F_100 ( V_3 , V_2 , V_8 , V_14 & V_164 ) ;
if ( V_37 == 0 )
V_37 = V_2 -> V_35 -> V_161 ( V_131 , V_3 ) ;
else if ( V_37 == - V_76 )
V_37 = 0 ;
F_49 ( V_3 ) ;
} while ( V_37 == V_162 );
return V_37 ;
}
static void F_193 ( struct V_177 * V_178 ,
struct V_133 * V_134 ,
struct V_131 * V_131 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_131 -> V_139 ;
if ( V_178 -> V_179 & V_180 )
return;
if ( ! V_134 -> V_135 )
return;
if ( V_178 -> V_179 & V_181 ) {
F_177 ( V_2 , V_134 , V_131 , V_8 ,
V_134 -> V_135 ) ;
return;
}
if ( V_134 -> V_182 < V_183 * 10 )
V_134 -> V_182 ++ ;
if ( V_134 -> V_182 > V_183 )
return;
V_134 -> V_42 = F_194 ( long , 0 , V_8 - V_134 -> V_135 / 2 ) ;
V_134 -> V_173 = V_134 -> V_135 ;
V_134 -> V_184 = V_134 -> V_135 / 4 ;
F_195 ( V_134 , V_2 , V_131 ) ;
}
static void F_196 ( struct V_177 * V_178 ,
struct V_133 * V_134 ,
struct V_131 * V_131 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_131 -> V_139 ;
if ( V_178 -> V_179 & V_180 )
return;
if ( V_134 -> V_182 > 0 )
V_134 -> V_182 -- ;
if ( F_178 ( V_3 ) )
F_179 ( V_2 , V_134 , V_131 ,
V_3 , V_8 , V_134 -> V_135 ) ;
}
int F_197 ( struct V_177 * V_178 , struct V_185 * V_186 )
{
int error ;
struct V_131 * V_131 = V_178 -> V_187 ;
struct V_1 * V_2 = V_131 -> V_139 ;
struct V_133 * V_134 = & V_131 -> V_141 ;
struct V_140 * V_140 = V_2 -> V_33 ;
T_2 V_8 = V_186 -> V_188 ;
struct V_3 * V_3 ;
T_1 V_173 ;
int V_37 = 0 ;
V_173 = F_198 ( F_71 ( V_140 ) , V_146 ) ;
if ( V_8 >= V_173 >> V_56 )
return V_189 ;
V_3 = F_176 ( V_2 , V_8 ) ;
if ( F_199 ( V_3 ) && ! ( V_186 -> V_34 & V_190 ) ) {
F_196 ( V_178 , V_134 , V_131 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_193 ( V_178 , V_134 , V_131 , V_8 ) ;
F_200 ( V_191 ) ;
F_201 ( V_178 -> V_192 , V_191 ) ;
V_37 = V_193 ;
V_194:
V_3 = F_176 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_153;
}
if ( ! F_202 ( V_3 , V_178 -> V_192 , V_186 -> V_34 ) ) {
F_49 ( V_3 ) ;
return V_37 | V_195 ;
}
if ( F_24 ( V_3 -> V_2 != V_2 ) ) {
F_125 ( V_3 ) ;
F_203 ( V_3 ) ;
goto V_194;
}
F_21 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_24 ( ! F_17 ( V_3 ) ) )
goto V_196;
V_173 = F_198 ( F_71 ( V_140 ) , V_146 ) ;
if ( F_24 ( V_8 >= V_173 >> V_56 ) ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
return V_189 ;
}
V_186 -> V_3 = V_3 ;
return V_37 | V_197 ;
V_153:
error = F_192 ( V_131 , V_8 , V_186 -> V_14 ) ;
if ( error >= 0 )
goto V_194;
if ( error == - V_163 )
return V_198 ;
return V_189 ;
V_196:
F_185 ( V_3 ) ;
error = V_2 -> V_35 -> V_161 ( V_131 , V_3 ) ;
if ( ! error ) {
F_147 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_41 ;
}
F_49 ( V_3 ) ;
if ( ! error || error == V_162 )
goto V_194;
F_174 ( V_131 , V_134 ) ;
return V_189 ;
}
void F_204 ( struct V_177 * V_178 , struct V_185 * V_186 )
{
struct V_127 V_128 ;
void * * V_10 ;
struct V_131 * V_131 = V_178 -> V_187 ;
struct V_1 * V_2 = V_131 -> V_139 ;
T_1 V_173 ;
struct V_3 * V_3 ;
unsigned long V_199 = ( unsigned long ) V_186 -> V_200 ;
unsigned long V_201 ;
T_8 * V_202 ;
F_152 () ;
F_167 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_128 . V_7 > V_186 -> V_203 )
break;
V_112:
V_3 = F_154 ( V_10 ) ;
if ( F_24 ( ! V_3 ) )
goto V_204;
if ( F_155 ( V_3 ) ) {
if ( F_156 ( V_3 ) )
break;
else
goto V_204;
}
if ( ! F_157 ( V_3 ) )
goto V_112;
if ( F_24 ( V_3 != * V_10 ) ) {
F_49 ( V_3 ) ;
goto V_112;
}
if ( ! F_17 ( V_3 ) ||
F_178 ( V_3 ) ||
F_205 ( V_3 ) )
goto V_205;
if ( ! F_162 ( V_3 ) )
goto V_205;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_206;
V_173 = F_198 ( F_71 ( V_2 -> V_33 ) , V_146 ) ;
if ( V_3 -> V_7 >= V_173 >> V_56 )
goto V_206;
V_202 = V_186 -> V_202 + V_3 -> V_7 - V_186 -> V_188 ;
if ( ! F_206 ( * V_202 ) )
goto V_206;
if ( V_131 -> V_141 . V_182 > 0 )
V_131 -> V_141 . V_182 -- ;
V_201 = V_199 + ( V_3 -> V_7 - V_186 -> V_188 ) * V_207 ;
F_207 ( V_178 , V_201 , V_3 , V_202 , false , false ) ;
F_125 ( V_3 ) ;
goto V_204;
V_206:
F_125 ( V_3 ) ;
V_205:
F_49 ( V_3 ) ;
V_204:
if ( V_128 . V_7 == V_186 -> V_203 )
break;
}
F_158 () ;
}
int F_208 ( struct V_177 * V_178 , struct V_185 * V_186 )
{
struct V_3 * V_3 = V_186 -> V_3 ;
struct V_140 * V_140 = F_209 ( V_178 -> V_187 ) ;
int V_37 = V_197 ;
F_210 ( V_140 -> V_208 ) ;
F_211 ( V_178 -> V_187 ) ;
F_160 ( V_3 ) ;
if ( V_3 -> V_2 != V_140 -> V_209 ) {
F_125 ( V_3 ) ;
V_37 = V_210 ;
goto V_60;
}
F_212 ( V_3 ) ;
F_213 ( V_3 ) ;
V_60:
F_214 ( V_140 -> V_208 ) ;
return V_37 ;
}
int F_215 ( struct V_131 * V_131 , struct V_177 * V_178 )
{
struct V_1 * V_2 = V_131 -> V_139 ;
if ( ! V_2 -> V_35 -> V_161 )
return - V_211 ;
F_188 ( V_131 ) ;
V_178 -> V_212 = & V_213 ;
return 0 ;
}
int F_216 ( struct V_131 * V_131 , struct V_177 * V_178 )
{
if ( ( V_178 -> V_179 & V_214 ) && ( V_178 -> V_179 & V_215 ) )
return - V_77 ;
return F_215 ( V_131 , V_178 ) ;
}
int F_215 ( struct V_131 * V_131 , struct V_177 * V_178 )
{
return - V_216 ;
}
int F_216 ( struct V_131 * V_131 , struct V_177 * V_178 )
{
return - V_216 ;
}
static struct V_3 * F_217 ( struct V_3 * V_3 )
{
if ( ! F_218 ( V_3 ) ) {
F_147 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_49 ( V_3 ) ;
V_3 = F_219 ( - V_41 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_220 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_221)( void * , struct V_3 * ) ,
void * V_174 ,
T_3 V_81 )
{
struct V_3 * V_3 ;
int V_67 ;
V_112:
V_3 = F_176 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_108 ( V_81 | V_176 ) ;
if ( ! V_3 )
return F_219 ( - V_163 ) ;
V_67 = F_100 ( V_3 , V_2 , V_7 , V_81 ) ;
if ( F_24 ( V_67 ) ) {
F_49 ( V_3 ) ;
if ( V_67 == - V_76 )
goto V_112;
return F_219 ( V_67 ) ;
}
V_67 = F_221 ( V_174 , V_3 ) ;
if ( V_67 < 0 ) {
F_49 ( V_3 ) ;
V_3 = F_219 ( V_67 ) ;
} else {
V_3 = F_217 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_222 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_221)( void * , struct V_3 * ) ,
void * V_174 ,
T_3 V_81 )
{
struct V_3 * V_3 ;
int V_67 ;
V_217:
V_3 = F_220 ( V_2 , V_7 , F_221 , V_174 , V_81 ) ;
if ( F_218 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_60;
F_160 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_125 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_217;
}
if ( F_17 ( V_3 ) ) {
F_125 ( V_3 ) ;
goto V_60;
}
V_67 = F_221 ( V_174 , V_3 ) ;
if ( V_67 < 0 ) {
F_49 ( V_3 ) ;
return F_219 ( V_67 ) ;
} else {
V_3 = F_217 ( V_3 ) ;
if ( F_218 ( V_3 ) )
return V_3 ;
}
V_60:
F_163 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_223 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_221)( void * , struct V_3 * ) ,
void * V_174 )
{
return F_222 ( V_2 , V_7 , F_221 , V_174 , F_224 ( V_2 ) ) ;
}
struct V_3 * F_225 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_81 )
{
T_9 * F_221 = ( T_9 * ) V_2 -> V_35 -> V_161 ;
return F_222 ( V_2 , V_7 , F_221 , NULL , V_81 ) ;
}
inline T_6 F_226 ( struct V_165 * V_166 , struct V_137 * V_218 )
{
struct V_131 * V_131 = V_166 -> V_167 ;
struct V_140 * V_140 = V_131 -> V_139 -> V_33 ;
unsigned long V_219 = F_227 ( V_220 ) ;
T_1 V_170 ;
if ( ! F_183 ( V_218 ) )
return 0 ;
if ( V_166 -> V_171 & V_221 )
V_166 -> V_169 = F_71 ( V_140 ) ;
V_170 = V_166 -> V_169 ;
if ( V_219 != V_222 ) {
if ( V_166 -> V_169 >= V_219 ) {
F_228 ( V_223 , V_26 , 0 ) ;
return - V_224 ;
}
F_229 ( V_218 , V_219 - ( unsigned long ) V_170 ) ;
}
if ( F_24 ( V_170 + F_183 ( V_218 ) > V_225 &&
! ( V_131 -> V_226 & V_227 ) ) ) {
if ( V_170 >= V_225 )
return - V_224 ;
F_229 ( V_218 , V_225 - ( unsigned long ) V_170 ) ;
}
if ( F_24 ( V_170 >= V_140 -> V_208 -> V_228 ) )
return - V_224 ;
F_229 ( V_218 , V_140 -> V_208 -> V_228 - V_170 ) ;
return F_183 ( V_218 ) ;
}
int F_230 ( struct V_131 * V_131 , struct V_1 * V_2 ,
T_1 V_170 , unsigned V_229 , unsigned V_34 ,
struct V_3 * * V_111 , void * * V_230 )
{
const struct V_231 * V_232 = V_2 -> V_35 ;
return V_232 -> V_233 ( V_131 , V_2 , V_170 , V_229 , V_34 ,
V_111 , V_230 ) ;
}
int F_231 ( struct V_131 * V_131 , struct V_1 * V_2 ,
T_1 V_170 , unsigned V_229 , unsigned V_234 ,
struct V_3 * V_3 , void * V_230 )
{
const struct V_231 * V_232 = V_2 -> V_35 ;
return V_232 -> V_235 ( V_131 , V_2 , V_170 , V_229 , V_234 , V_3 , V_230 ) ;
}
T_6
F_232 ( struct V_165 * V_166 , struct V_137 * V_218 , T_1 V_170 )
{
struct V_131 * V_131 = V_166 -> V_167 ;
struct V_1 * V_2 = V_131 -> V_139 ;
struct V_140 * V_140 = V_2 -> V_33 ;
T_6 V_138 ;
T_7 V_236 ;
T_2 V_43 ;
struct V_137 V_174 ;
V_236 = F_183 ( V_218 ) ;
V_43 = ( V_170 + V_236 - 1 ) >> V_56 ;
V_138 = F_75 ( V_2 , V_170 , V_170 + V_236 - 1 ) ;
if ( V_138 )
goto V_60;
if ( V_2 -> V_13 ) {
V_138 = F_233 ( V_2 ,
V_170 >> V_56 , V_43 ) ;
if ( V_138 ) {
if ( V_138 == - V_237 )
return 0 ;
goto V_60;
}
}
V_174 = * V_218 ;
V_138 = V_2 -> V_35 -> V_175 ( V_166 , & V_174 , V_170 ) ;
if ( V_2 -> V_13 ) {
F_233 ( V_2 ,
V_170 >> V_56 , V_43 ) ;
}
if ( V_138 > 0 ) {
V_170 += V_138 ;
F_190 ( V_218 , V_138 ) ;
if ( V_170 > F_71 ( V_140 ) && ! F_234 ( V_140 -> V_238 ) ) {
F_235 ( V_140 , V_170 ) ;
F_236 ( V_140 ) ;
}
V_166 -> V_169 = V_170 ;
}
V_60:
return V_138 ;
}
struct V_3 * F_237 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_34 )
{
struct V_3 * V_3 ;
int V_113 = V_115 | V_117 | V_119 | V_118 ;
if ( V_34 & V_239 )
V_113 |= V_121 ;
V_3 = F_161 ( V_2 , V_7 , V_113 ,
F_224 ( V_2 ) ) ;
if ( V_3 )
F_213 ( V_3 ) ;
return V_3 ;
}
T_6 F_238 ( struct V_131 * V_131 ,
struct V_137 * V_63 , T_1 V_170 )
{
struct V_1 * V_2 = V_131 -> V_139 ;
const struct V_231 * V_35 = V_2 -> V_35 ;
long V_240 = 0 ;
T_6 V_138 = 0 ;
unsigned int V_34 = 0 ;
if ( ! F_239 ( V_63 ) )
V_34 |= V_241 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_242 ;
T_7 V_234 ;
void * V_230 ;
V_8 = ( V_170 & ( V_146 - 1 ) ) ;
V_242 = F_240 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_243:
if ( F_24 ( F_241 ( V_63 , V_242 ) ) ) {
V_240 = - V_159 ;
break;
}
if ( F_242 ( V_26 ) ) {
V_240 = - V_244 ;
break;
}
V_240 = V_35 -> V_233 ( V_131 , V_2 , V_170 , V_242 , V_34 ,
& V_3 , & V_230 ) ;
if ( F_24 ( V_240 < 0 ) )
break;
if ( F_180 ( V_2 ) )
F_181 ( V_3 ) ;
V_234 = F_243 ( V_3 , V_63 , V_8 , V_242 ) ;
F_181 ( V_3 ) ;
V_240 = V_35 -> V_235 ( V_131 , V_2 , V_170 , V_242 , V_234 ,
V_3 , V_230 ) ;
if ( F_24 ( V_240 < 0 ) )
break;
V_234 = V_240 ;
F_68 () ;
F_190 ( V_63 , V_234 ) ;
if ( F_24 ( V_234 == 0 ) ) {
V_242 = F_240 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_243;
}
V_170 += V_234 ;
V_138 += V_234 ;
F_244 ( V_2 ) ;
} while ( F_183 ( V_63 ) );
return V_138 ? V_138 : V_240 ;
}
T_6 F_245 ( struct V_165 * V_166 , struct V_137 * V_218 )
{
struct V_131 * V_131 = V_166 -> V_167 ;
struct V_1 * V_2 = V_131 -> V_139 ;
struct V_140 * V_140 = V_2 -> V_33 ;
T_6 V_138 = 0 ;
T_6 V_67 ;
T_6 V_240 ;
V_26 -> V_245 = F_246 ( V_140 ) ;
V_67 = F_247 ( V_131 ) ;
if ( V_67 )
goto V_60;
V_67 = F_211 ( V_131 ) ;
if ( V_67 )
goto V_60;
if ( V_166 -> V_171 & V_172 ) {
T_1 V_170 , V_246 ;
V_138 = F_232 ( V_166 , V_218 , V_166 -> V_169 ) ;
if ( V_138 < 0 || ! F_183 ( V_218 ) || F_191 ( V_140 ) )
goto V_60;
V_240 = F_238 ( V_131 , V_218 , V_170 = V_166 -> V_169 ) ;
if ( F_24 ( V_240 < 0 ) ) {
V_67 = V_240 ;
goto V_60;
}
V_246 = V_170 + V_240 - 1 ;
V_67 = F_75 ( V_2 , V_170 , V_246 ) ;
if ( V_67 == 0 ) {
V_166 -> V_169 = V_246 + 1 ;
V_138 += V_240 ;
F_248 ( V_2 ,
V_170 >> V_56 ,
V_246 >> V_56 ) ;
} else {
}
} else {
V_138 = F_238 ( V_131 , V_218 , V_166 -> V_169 ) ;
if ( F_199 ( V_138 > 0 ) )
V_166 -> V_169 += V_138 ;
}
V_60:
V_26 -> V_245 = NULL ;
return V_138 ? V_138 : V_67 ;
}
T_6 F_249 ( struct V_165 * V_166 , struct V_137 * V_218 )
{
struct V_131 * V_131 = V_166 -> V_167 ;
struct V_140 * V_140 = V_131 -> V_139 -> V_33 ;
T_6 V_37 ;
F_250 ( V_140 ) ;
V_37 = F_226 ( V_166 , V_218 ) ;
if ( V_37 > 0 )
V_37 = F_245 ( V_166 , V_218 ) ;
F_251 ( V_140 ) ;
if ( V_37 > 0 ) {
T_6 V_67 ;
V_67 = F_252 ( V_131 , V_166 -> V_169 - V_37 , V_37 ) ;
if ( V_67 < 0 )
V_37 = V_67 ;
}
return V_37 ;
}
int F_253 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_44 ( ! F_3 ( V_3 ) ) ;
if ( F_254 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_35 -> V_247 )
return V_2 -> V_35 -> V_247 ( V_3 , V_14 ) ;
return F_255 ( V_3 ) ;
}
