static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_4 )
{
struct V_5 * V_6 ;
void * * V_7 ;
int error ;
error = F_2 ( & V_2 -> V_8 , V_3 -> V_9 , 0 ,
& V_6 , & V_7 ) ;
if ( error )
return error ;
if ( * V_7 ) {
void * V_10 ;
V_10 = F_3 ( V_7 , & V_2 -> V_11 ) ;
if ( ! F_4 ( V_10 ) )
return - V_12 ;
V_2 -> V_13 -- ;
if ( ! F_5 ( V_2 ) ) {
if ( V_4 )
* V_4 = V_10 ;
if ( V_6 )
F_6 ( V_6 ) ;
} else {
F_7 ( V_10 !=
( void * ) ( V_14 |
V_15 ) ) ;
if ( V_6 )
F_8 ( V_6 ) ;
F_9 ( V_2 , V_3 -> V_9 ,
false ) ;
}
}
F_10 ( V_7 , V_3 ) ;
V_2 -> V_16 ++ ;
if ( V_6 ) {
F_11 ( V_6 ) ;
if ( ! F_12 ( & V_6 -> V_17 ) )
F_13 ( & V_18 ,
& V_6 -> V_17 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * V_19 )
{
struct V_5 * V_6 ;
int V_20 , V_21 = F_15 ( V_3 ) ? 1 : F_16 ( V_3 ) ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_17 ( F_19 ( V_3 ) , V_3 ) ;
F_17 ( V_21 != 1 && V_19 , V_3 ) ;
if ( V_19 ) {
V_2 -> V_13 += V_21 ;
F_20 () ;
}
V_2 -> V_16 -= V_21 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_6 = F_21 ( & V_2 -> V_8 ,
V_3 -> V_9 + V_20 , V_19 ) ;
if ( ! V_6 ) {
F_17 ( V_21 != 1 , V_3 ) ;
return;
}
F_8 ( V_6 ) ;
if ( V_19 )
F_22 ( V_6 ) ;
else
if ( F_23 ( & V_2 -> V_8 , V_6 ) )
continue;
if ( ! F_5 ( V_2 ) && ! F_24 ( V_6 ) &&
F_12 ( & V_6 -> V_17 ) ) {
V_6 -> V_22 = V_2 ;
F_25 ( & V_18 ,
& V_6 -> V_17 ) ;
}
}
}
void F_26 ( struct V_3 * V_3 , void * V_19 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_21 = F_16 ( V_3 ) ;
F_27 ( V_3 ) ;
if ( F_28 ( V_3 ) && F_29 ( V_3 ) )
F_30 ( V_3 ) ;
else
F_31 ( V_2 , V_3 ) ;
F_17 ( F_19 ( V_3 ) , V_3 ) ;
F_17 ( F_32 ( V_3 ) , V_3 ) ;
if ( ! F_33 ( V_23 ) && F_34 ( F_32 ( V_3 ) ) ) {
int V_24 ;
F_35 ( L_1 ,
V_25 -> V_26 , F_36 ( V_3 ) ) ;
F_37 ( V_3 , L_2 ) ;
F_38 () ;
F_39 ( V_27 , V_28 ) ;
V_24 = F_40 ( V_3 ) ;
if ( F_41 ( V_2 ) &&
F_42 ( V_3 ) >= V_24 + 2 ) {
F_43 ( V_3 ) ;
F_44 ( V_3 , V_24 ) ;
}
}
F_14 ( V_2 , V_3 , V_19 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_15 ( V_3 ) )
F_45 ( F_46 ( V_3 ) , V_29 , - V_21 ) ;
if ( F_47 ( V_3 ) ) {
F_45 ( F_46 ( V_3 ) , V_30 , - V_21 ) ;
if ( F_48 ( V_3 ) )
F_49 ( V_3 , V_31 ) ;
} else {
F_17 ( F_48 ( V_3 ) && ! F_15 ( V_3 ) , V_3 ) ;
}
if ( F_7 ( F_50 ( V_3 ) ) )
F_51 ( V_3 , V_2 , F_52 ( V_2 -> V_32 ) ) ;
}
void F_53 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_54 ( V_3 ) ;
unsigned long V_33 ;
void (* F_55)( struct V_3 * );
F_56 ( ! F_18 ( V_3 ) ) ;
F_55 = V_2 -> V_34 -> F_55 ;
F_57 ( & V_2 -> V_11 , V_33 ) ;
F_26 ( V_3 , NULL ) ;
F_58 ( & V_2 -> V_11 , V_33 ) ;
if ( F_55 )
F_55 ( V_3 ) ;
if ( F_48 ( V_3 ) && ! F_15 ( V_3 ) ) {
F_44 ( V_3 , V_35 ) ;
F_17 ( F_42 ( V_3 ) <= 0 , V_3 ) ;
} else {
F_59 ( V_3 ) ;
}
}
int F_60 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
if ( F_61 ( V_37 , & V_2 -> V_33 ) &&
F_62 ( V_37 , & V_2 -> V_33 ) )
V_36 = - V_38 ;
if ( F_61 ( V_39 , & V_2 -> V_33 ) &&
F_62 ( V_39 , & V_2 -> V_33 ) )
V_36 = - V_40 ;
return V_36 ;
}
int F_63 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_42 , int V_43 )
{
int V_36 ;
struct V_44 V_45 = {
. V_43 = V_43 ,
. V_46 = V_47 ,
. V_48 = V_41 ,
. V_49 = V_42 ,
} ;
if ( ! F_64 ( V_2 ) )
return 0 ;
F_65 ( & V_45 , V_2 -> V_32 ) ;
V_36 = F_66 ( V_2 , & V_45 ) ;
F_67 ( & V_45 ) ;
return V_36 ;
}
static inline int F_68 ( struct V_1 * V_2 ,
int V_43 )
{
return F_63 ( V_2 , 0 , V_50 , V_43 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
return F_68 ( V_2 , V_51 ) ;
}
int F_70 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_42 )
{
return F_63 ( V_2 , V_41 , V_42 , V_51 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
return F_68 ( V_2 , V_52 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
T_1 V_53 , T_1 V_54 )
{
T_2 V_9 = V_53 >> V_55 ;
T_2 V_42 = V_54 >> V_55 ;
struct V_56 V_57 ;
int V_58 ;
int V_36 = 0 ;
if ( V_54 < V_53 )
goto V_59;
F_73 ( & V_57 , 0 ) ;
while ( ( V_9 <= V_42 ) &&
( V_58 = F_74 ( & V_57 , V_2 , & V_9 ,
V_60 ,
F_75 ( V_42 - V_9 , ( T_2 ) V_61 - 1 ) + 1 ) ) != 0 ) {
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
struct V_3 * V_3 = V_57 . V_62 [ V_20 ] ;
if ( V_3 -> V_9 > V_42 )
continue;
F_76 ( V_3 ) ;
if ( F_77 ( V_3 ) )
V_36 = - V_40 ;
}
F_78 ( & V_57 ) ;
F_79 () ;
}
V_59:
return V_36 ;
}
int F_80 ( struct V_1 * V_2 , T_1 V_53 ,
T_1 V_54 )
{
int V_36 , V_63 ;
V_36 = F_72 ( V_2 , V_53 , V_54 ) ;
V_63 = F_60 ( V_2 ) ;
if ( ! V_36 )
V_36 = V_63 ;
return V_36 ;
}
void F_81 ( struct V_1 * V_2 )
{
T_1 V_64 = F_82 ( V_2 -> V_32 ) ;
if ( V_64 == 0 )
return;
F_72 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_83 ( struct V_1 * V_2 )
{
T_1 V_64 = F_82 ( V_2 -> V_32 ) ;
if ( V_64 == 0 )
return 0 ;
return F_80 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_65 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_65 = F_69 ( V_2 ) ;
if ( V_65 != - V_40 ) {
int V_66 = F_83 ( V_2 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_60 ( V_2 ) ;
}
return V_65 ;
}
int F_85 ( struct V_1 * V_2 ,
T_1 V_67 , T_1 V_68 )
{
int V_65 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_65 = F_63 ( V_2 , V_67 , V_68 ,
V_51 ) ;
if ( V_65 != - V_40 ) {
int V_66 = F_80 ( V_2 ,
V_67 , V_68 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_60 ( V_2 ) ;
}
return V_65 ;
}
int F_86 ( struct V_3 * V_69 , struct V_3 * V_70 , T_3 V_71 )
{
int error ;
F_17 ( ! F_18 ( V_69 ) , V_69 ) ;
F_17 ( ! F_18 ( V_70 ) , V_70 ) ;
F_17 ( V_70 -> V_2 , V_70 ) ;
error = F_87 ( V_71 & ~ V_72 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_69 -> V_2 ;
void (* F_55)( struct V_3 * );
unsigned long V_33 ;
T_2 V_73 = V_69 -> V_9 ;
F_55 = V_2 -> V_34 -> F_55 ;
F_88 ( V_70 ) ;
V_70 -> V_2 = V_2 ;
V_70 -> V_9 = V_73 ;
F_57 ( & V_2 -> V_11 , V_33 ) ;
F_26 ( V_69 , NULL ) ;
error = F_1 ( V_2 , V_70 , NULL ) ;
F_56 ( error ) ;
V_2 -> V_16 ++ ;
if ( ! F_15 ( V_70 ) )
F_89 ( V_70 , V_29 ) ;
if ( F_47 ( V_70 ) )
F_89 ( V_70 , V_30 ) ;
F_58 ( & V_2 -> V_11 , V_33 ) ;
F_90 ( V_69 , V_70 ) ;
F_91 () ;
if ( F_55 )
F_55 ( V_69 ) ;
F_59 ( V_69 ) ;
}
return error ;
}
static int F_92 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 ,
void * * V_4 )
{
int V_74 = F_15 ( V_3 ) ;
struct V_75 * V_76 ;
int error ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_17 ( F_47 ( V_3 ) , V_3 ) ;
if ( ! V_74 ) {
error = F_93 ( V_3 , V_25 -> V_77 ,
V_71 , & V_76 , false ) ;
if ( error )
return error ;
}
error = F_94 ( V_71 & ~ V_72 ) ;
if ( error ) {
if ( ! V_74 )
F_95 ( V_3 , V_76 , false ) ;
return error ;
}
F_88 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = V_73 ;
F_96 ( & V_2 -> V_11 ) ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
F_91 () ;
if ( F_34 ( error ) )
goto V_78;
if ( ! V_74 )
F_89 ( V_3 , V_29 ) ;
F_97 ( & V_2 -> V_11 ) ;
if ( ! V_74 )
F_98 ( V_3 , V_76 , false , false ) ;
F_99 ( V_3 ) ;
return 0 ;
V_78:
V_3 -> V_2 = NULL ;
F_97 ( & V_2 -> V_11 ) ;
if ( ! V_74 )
F_95 ( V_3 , V_76 , false ) ;
F_59 ( V_3 ) ;
return error ;
}
int F_100 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 )
{
return F_92 ( V_3 , V_2 , V_73 ,
V_71 , NULL ) ;
}
int F_101 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 )
{
void * V_19 = NULL ;
int V_36 ;
F_102 ( V_3 ) ;
V_36 = F_92 ( V_3 , V_2 , V_73 ,
V_71 , & V_19 ) ;
if ( F_34 ( V_36 ) )
F_103 ( V_3 ) ;
else {
if ( ! ( V_71 & V_79 ) &&
V_19 && F_104 ( V_19 ) ) {
F_105 ( V_3 ) ;
F_106 ( V_3 ) ;
} else
F_107 ( V_3 ) ;
F_108 ( V_3 ) ;
}
return V_36 ;
}
struct V_3 * F_109 ( T_3 V_80 )
{
int V_81 ;
struct V_3 * V_3 ;
if ( F_110 () ) {
unsigned int V_82 ;
do {
V_82 = F_111 () ;
V_81 = F_112 () ;
V_3 = F_113 ( V_81 , V_80 , 0 ) ;
} while ( ! V_3 && F_114 ( V_82 ) );
return V_3 ;
}
return F_115 ( V_80 , 0 ) ;
}
T_4 * F_116 ( struct V_3 * V_3 )
{
const struct V_83 * V_83 = F_117 ( V_3 ) ;
return & V_83 -> V_84 [ F_118 ( V_3 , V_83 -> V_85 ) ] ;
}
void F_119 ( struct V_3 * V_3 , int V_86 )
{
F_120 ( V_87 , & V_3 -> V_33 , V_86 ) ;
if ( F_61 ( V_86 , & V_3 -> V_33 ) )
F_121 ( F_116 ( V_3 ) , & V_87 , V_88 ,
V_89 ) ;
}
int F_122 ( struct V_3 * V_3 , int V_86 )
{
F_120 ( V_87 , & V_3 -> V_33 , V_86 ) ;
if ( ! F_61 ( V_86 , & V_3 -> V_33 ) )
return 0 ;
return F_121 ( F_116 ( V_3 ) , & V_87 ,
V_88 , V_90 ) ;
}
int F_123 ( struct V_3 * V_3 ,
int V_86 , unsigned long V_91 )
{
F_120 ( V_87 , & V_3 -> V_33 , V_86 ) ;
V_87 . V_92 . V_91 = V_93 + V_91 ;
if ( ! F_61 ( V_86 , & V_3 -> V_33 ) )
return 0 ;
return F_121 ( F_116 ( V_3 ) , & V_87 ,
V_94 , V_90 ) ;
}
void F_124 ( struct V_3 * V_3 , T_5 * V_95 )
{
T_4 * V_96 = F_116 ( V_3 ) ;
unsigned long V_33 ;
F_57 ( & V_96 -> V_97 , V_33 ) ;
F_125 ( V_96 , V_95 ) ;
F_58 ( & V_96 -> V_97 , V_33 ) ;
}
void F_126 ( struct V_3 * V_3 )
{
V_3 = F_127 ( V_3 ) ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_128 ( V_98 , & V_3 -> V_33 ) ;
F_129 () ;
F_130 ( V_3 , V_98 ) ;
}
void F_131 ( struct V_3 * V_3 )
{
if ( F_132 ( V_3 ) ) {
F_133 ( V_3 ) ;
F_134 ( V_3 ) ;
}
if ( ! F_135 ( V_3 ) )
F_136 () ;
F_129 () ;
F_130 ( V_3 , V_99 ) ;
}
void F_137 ( struct V_3 * V_3 , bool V_100 , int V_65 )
{
if ( ! V_100 ) {
if ( ! V_65 ) {
F_138 ( V_3 ) ;
} else {
F_139 ( V_3 ) ;
F_140 ( V_3 ) ;
}
F_126 ( V_3 ) ;
} else {
if ( V_65 ) {
F_140 ( V_3 ) ;
if ( V_3 -> V_2 )
F_141 ( V_3 -> V_2 , V_65 ) ;
}
F_131 ( V_3 ) ;
}
}
void F_142 ( struct V_3 * V_3 )
{
struct V_3 * V_101 = F_127 ( V_3 ) ;
F_120 ( V_87 , & V_101 -> V_33 , V_98 ) ;
F_143 ( F_116 ( V_101 ) , & V_87 , V_88 ,
V_89 ) ;
}
int F_144 ( struct V_3 * V_3 )
{
struct V_3 * V_101 = F_127 ( V_3 ) ;
F_120 ( V_87 , & V_101 -> V_33 , V_98 ) ;
return F_143 ( F_116 ( V_101 ) , & V_87 ,
V_88 , V_90 ) ;
}
int F_145 ( struct V_3 * V_3 , struct V_102 * V_77 ,
unsigned int V_33 )
{
if ( V_33 & V_103 ) {
if ( V_33 & V_104 )
return 0 ;
F_146 ( & V_77 -> V_105 ) ;
if ( V_33 & V_106 )
F_147 ( V_3 ) ;
else
F_148 ( V_3 ) ;
return 0 ;
} else {
if ( V_33 & V_106 ) {
int V_36 ;
V_36 = F_144 ( V_3 ) ;
if ( V_36 ) {
F_146 ( & V_77 -> V_105 ) ;
return 0 ;
}
} else
F_142 ( V_3 ) ;
return 1 ;
}
}
T_2 F_149 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_107 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
struct V_3 * V_3 ;
V_3 = F_150 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 ++ ;
if ( V_9 == 0 )
break;
}
return V_9 ;
}
T_2 F_151 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_107 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
struct V_3 * V_3 ;
V_3 = F_150 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_108 )
break;
}
return V_9 ;
}
struct V_3 * F_152 ( struct V_1 * V_2 , T_2 V_73 )
{
void * * V_109 ;
struct V_3 * V_110 , * V_3 ;
F_153 () ;
V_111:
V_3 = NULL ;
V_109 = F_154 ( & V_2 -> V_8 , V_73 ) ;
if ( V_109 ) {
V_3 = F_155 ( V_109 ) ;
if ( F_34 ( ! V_3 ) )
goto V_59;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) )
goto V_111;
goto V_59;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_109 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
}
V_59:
F_159 () ;
return V_3 ;
}
struct V_3 * F_160 ( struct V_1 * V_2 , T_2 V_73 )
{
struct V_3 * V_3 ;
V_111:
V_3 = F_152 ( V_2 , V_73 ) ;
if ( V_3 && ! F_156 ( V_3 ) ) {
F_161 ( V_3 ) ;
if ( F_34 ( F_54 ( V_3 ) != V_2 ) ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
goto V_111;
}
F_17 ( F_162 ( V_3 ) != V_73 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_163 ( struct V_1 * V_2 , T_2 V_73 ,
int V_112 , T_3 V_71 )
{
struct V_3 * V_3 ;
V_111:
V_3 = F_152 ( V_2 , V_73 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_113;
if ( V_112 & V_114 ) {
if ( V_112 & V_115 ) {
if ( ! F_164 ( V_3 ) ) {
F_59 ( V_3 ) ;
return NULL ;
}
} else {
F_161 ( V_3 ) ;
}
if ( F_34 ( V_3 -> V_2 != V_2 ) ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
goto V_111;
}
F_17 ( V_3 -> V_9 != V_73 , V_3 ) ;
}
if ( V_3 && ( V_112 & V_116 ) )
F_165 ( V_3 ) ;
V_113:
if ( ! V_3 && ( V_112 & V_117 ) ) {
int V_65 ;
if ( ( V_112 & V_118 ) && F_166 ( V_2 ) )
V_71 |= V_79 ;
if ( V_112 & V_119 )
V_71 &= ~ V_120 ;
V_3 = F_109 ( V_71 ) ;
if ( ! V_3 )
return NULL ;
if ( F_7 ( ! ( V_112 & V_114 ) ) )
V_112 |= V_114 ;
if ( V_112 & V_116 )
F_167 ( V_3 ) ;
V_65 = F_101 ( V_3 , V_2 , V_73 ,
V_71 & V_121 ) ;
if ( F_34 ( V_65 ) ) {
F_59 ( V_3 ) ;
V_3 = NULL ;
if ( V_65 == - V_12 )
goto V_111;
}
}
return V_3 ;
}
unsigned F_168 ( struct V_1 * V_2 ,
T_2 V_41 , unsigned int V_122 ,
struct V_3 * * V_123 , T_2 * V_124 )
{
void * * V_7 ;
unsigned int V_36 = 0 ;
struct V_125 V_126 ;
if ( ! V_122 )
return 0 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_110 , * V_3 ;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
goto V_127;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
V_127:
V_124 [ V_36 ] = V_126 . V_9 ;
V_123 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_122 )
break;
}
F_159 () ;
return V_36 ;
}
unsigned F_171 ( struct V_1 * V_2 , T_2 V_41 ,
unsigned int V_58 , struct V_3 * * V_62 )
{
struct V_125 V_126 ;
void * * V_7 ;
unsigned V_36 = 0 ;
if ( F_34 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_110 , * V_3 ;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
continue;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
V_62 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_58 )
break;
}
F_159 () ;
return V_36 ;
}
unsigned F_172 ( struct V_1 * V_2 , T_2 V_9 ,
unsigned int V_58 , struct V_3 * * V_62 )
{
struct V_125 V_126 ;
void * * V_7 ;
unsigned int V_36 = 0 ;
if ( F_34 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_173 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_110 , * V_3 ;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
break;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
break;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( V_3 -> V_2 == NULL || F_162 ( V_3 ) != V_126 . V_9 ) {
F_59 ( V_3 ) ;
break;
}
V_62 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_58 )
break;
}
F_159 () ;
return V_36 ;
}
unsigned F_174 ( struct V_1 * V_2 , T_2 * V_9 ,
int V_128 , unsigned int V_58 , struct V_3 * * V_62 )
{
struct V_125 V_126 ;
void * * V_7 ;
unsigned V_36 = 0 ;
if ( F_34 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_175 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_110 , * V_3 ;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
continue;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
V_62 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_58 )
break;
}
F_159 () ;
if ( V_36 )
* V_9 = V_62 [ V_36 - 1 ] -> V_9 + 1 ;
return V_36 ;
}
unsigned F_176 ( struct V_1 * V_2 , T_2 V_41 ,
int V_128 , unsigned int V_122 ,
struct V_3 * * V_123 , T_2 * V_124 )
{
void * * V_7 ;
unsigned int V_36 = 0 ;
struct V_125 V_126 ;
if ( ! V_122 )
return 0 ;
F_153 () ;
F_175 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_110 , * V_3 ;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
goto V_127;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
V_127:
V_124 [ V_36 ] = V_126 . V_9 ;
V_123 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_122 )
break;
}
F_159 () ;
return V_36 ;
}
static void F_177 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
V_132 -> V_133 /= 4 ;
}
static T_6 F_178 ( struct V_129 * V_130 , T_1 * V_134 ,
struct V_135 * V_126 , T_6 V_136 )
{
struct V_1 * V_2 = V_130 -> V_137 ;
struct V_138 * V_138 = V_2 -> V_32 ;
struct V_131 * V_132 = & V_130 -> V_139 ;
T_2 V_9 ;
T_2 V_140 ;
T_2 V_141 ;
unsigned long V_73 ;
unsigned int V_142 ;
int error = 0 ;
V_9 = * V_134 >> V_55 ;
V_141 = V_132 -> V_143 >> V_55 ;
V_142 = V_132 -> V_143 & ( V_144 - 1 ) ;
V_140 = ( * V_134 + V_126 -> V_145 + V_144 - 1 ) >> V_55 ;
V_73 = * V_134 & ~ V_146 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_147 ;
T_1 V_148 ;
unsigned long V_21 , V_36 ;
F_79 () ;
V_149:
V_3 = F_179 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
F_180 ( V_2 ,
V_132 , V_130 ,
V_9 , V_140 - V_9 ) ;
V_3 = F_179 ( V_2 , V_9 ) ;
if ( F_34 ( V_3 == NULL ) )
goto V_150;
}
if ( F_181 ( V_3 ) ) {
F_182 ( V_2 ,
V_132 , V_130 , V_3 ,
V_9 , V_140 - V_9 ) ;
}
if ( ! F_28 ( V_3 ) ) {
F_147 ( V_3 ) ;
if ( F_28 ( V_3 ) )
goto V_151;
if ( V_138 -> V_152 == V_55 ||
! V_2 -> V_34 -> V_153 )
goto V_154;
if ( ! F_164 ( V_3 ) )
goto V_154;
if ( ! V_3 -> V_2 )
goto V_155;
if ( ! V_2 -> V_34 -> V_153 ( V_3 ,
V_73 , V_126 -> V_145 ) )
goto V_155;
F_126 ( V_3 ) ;
}
V_151:
V_148 = F_82 ( V_138 ) ;
V_147 = ( V_148 - 1 ) >> V_55 ;
if ( F_34 ( ! V_148 || V_9 > V_147 ) ) {
F_59 ( V_3 ) ;
goto V_59;
}
V_21 = V_144 ;
if ( V_9 == V_147 ) {
V_21 = ( ( V_148 - 1 ) & ~ V_146 ) + 1 ;
if ( V_21 <= V_73 ) {
F_59 ( V_3 ) ;
goto V_59;
}
}
V_21 = V_21 - V_73 ;
if ( F_183 ( V_2 ) )
F_184 ( V_3 ) ;
if ( V_141 != V_9 || V_73 != V_142 )
F_165 ( V_3 ) ;
V_141 = V_9 ;
V_36 = F_185 ( V_3 , V_73 , V_21 , V_126 ) ;
V_73 += V_36 ;
V_9 += V_73 >> V_55 ;
V_73 &= ~ V_146 ;
V_142 = V_73 ;
F_59 ( V_3 ) ;
V_136 += V_36 ;
if ( ! F_186 ( V_126 ) )
goto V_59;
if ( V_36 < V_21 ) {
error = - V_156 ;
goto V_59;
}
continue;
V_154:
error = F_187 ( V_3 ) ;
if ( F_34 ( error ) )
goto V_157;
V_155:
if ( ! V_3 -> V_2 ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
continue;
}
if ( F_28 ( V_3 ) ) {
F_126 ( V_3 ) ;
goto V_151;
}
V_158:
F_188 ( V_3 ) ;
error = V_2 -> V_34 -> V_158 ( V_130 , V_3 ) ;
if ( F_34 ( error ) ) {
if ( error == V_159 ) {
F_59 ( V_3 ) ;
error = 0 ;
goto V_149;
}
goto V_157;
}
if ( ! F_28 ( V_3 ) ) {
error = F_187 ( V_3 ) ;
if ( F_34 ( error ) )
goto V_157;
if ( ! F_28 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
goto V_149;
}
F_126 ( V_3 ) ;
F_177 ( V_130 , V_132 ) ;
error = - V_40 ;
goto V_157;
}
F_126 ( V_3 ) ;
}
goto V_151;
V_157:
F_59 ( V_3 ) ;
goto V_59;
V_150:
V_3 = F_189 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_160 ;
goto V_59;
}
error = F_101 ( V_3 , V_2 , V_9 ,
F_190 ( V_2 , V_161 ) ) ;
if ( error ) {
F_59 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_149;
}
goto V_59;
}
goto V_158;
}
V_59:
V_132 -> V_143 = V_141 ;
V_132 -> V_143 <<= V_55 ;
V_132 -> V_143 |= V_142 ;
* V_134 = ( ( T_1 ) V_9 << V_55 ) + V_73 ;
F_191 ( V_130 ) ;
return V_136 ? V_136 : error ;
}
T_6
F_192 ( struct V_162 * V_163 , struct V_135 * V_126 )
{
struct V_129 * V_129 = V_163 -> V_164 ;
T_6 V_165 = 0 ;
T_7 V_145 = F_186 ( V_126 ) ;
if ( ! V_145 )
goto V_59;
if ( V_163 -> V_166 & V_167 ) {
struct V_1 * V_2 = V_129 -> V_137 ;
struct V_138 * V_138 = V_2 -> V_32 ;
T_1 V_168 ;
V_168 = F_82 ( V_138 ) ;
V_165 = F_85 ( V_2 , V_163 -> V_169 ,
V_163 -> V_169 + V_145 - 1 ) ;
if ( ! V_165 ) {
struct V_135 V_170 = * V_126 ;
V_165 = V_2 -> V_34 -> V_171 ( V_163 , & V_170 ) ;
}
if ( V_165 > 0 ) {
V_163 -> V_169 += V_165 ;
F_193 ( V_126 , V_165 ) ;
}
if ( V_165 < 0 || ! F_186 ( V_126 ) || V_163 -> V_169 >= V_168 ||
F_194 ( V_138 ) ) {
F_191 ( V_129 ) ;
goto V_59;
}
}
V_165 = F_178 ( V_129 , & V_163 -> V_169 , V_126 , V_165 ) ;
V_59:
return V_165 ;
}
static int F_195 ( struct V_129 * V_129 , T_2 V_73 , T_3 V_71 )
{
struct V_1 * V_2 = V_129 -> V_137 ;
struct V_3 * V_3 ;
int V_36 ;
do {
V_3 = F_109 ( V_71 | V_172 ) ;
if ( ! V_3 )
return - V_160 ;
V_36 = F_101 ( V_3 , V_2 , V_73 , V_71 & V_161 ) ;
if ( V_36 == 0 )
V_36 = V_2 -> V_34 -> V_158 ( V_129 , V_3 ) ;
else if ( V_36 == - V_12 )
V_36 = 0 ;
F_59 ( V_3 ) ;
} while ( V_36 == V_159 );
return V_36 ;
}
static void F_196 ( struct V_173 * V_174 ,
struct V_131 * V_132 ,
struct V_129 * V_129 ,
T_2 V_73 )
{
struct V_1 * V_2 = V_129 -> V_137 ;
if ( V_174 -> V_175 & V_176 )
return;
if ( ! V_132 -> V_133 )
return;
if ( V_174 -> V_175 & V_177 ) {
F_180 ( V_2 , V_132 , V_129 , V_73 ,
V_132 -> V_133 ) ;
return;
}
if ( V_132 -> V_178 < V_179 * 10 )
V_132 -> V_178 ++ ;
if ( V_132 -> V_178 > V_179 )
return;
V_132 -> V_41 = F_197 ( long , 0 , V_73 - V_132 -> V_133 / 2 ) ;
V_132 -> V_168 = V_132 -> V_133 ;
V_132 -> V_180 = V_132 -> V_133 / 4 ;
F_198 ( V_132 , V_2 , V_129 ) ;
}
static void F_199 ( struct V_173 * V_174 ,
struct V_131 * V_132 ,
struct V_129 * V_129 ,
struct V_3 * V_3 ,
T_2 V_73 )
{
struct V_1 * V_2 = V_129 -> V_137 ;
if ( V_174 -> V_175 & V_176 )
return;
if ( V_132 -> V_178 > 0 )
V_132 -> V_178 -- ;
if ( F_181 ( V_3 ) )
F_182 ( V_2 , V_132 , V_129 ,
V_3 , V_73 , V_132 -> V_133 ) ;
}
int F_200 ( struct V_173 * V_174 , struct V_181 * V_182 )
{
int error ;
struct V_129 * V_129 = V_174 -> V_183 ;
struct V_1 * V_2 = V_129 -> V_137 ;
struct V_131 * V_132 = & V_129 -> V_139 ;
struct V_138 * V_138 = V_2 -> V_32 ;
T_2 V_73 = V_182 -> V_184 ;
struct V_3 * V_3 ;
T_1 V_168 ;
int V_36 = 0 ;
V_168 = F_201 ( F_82 ( V_138 ) , V_144 ) ;
if ( V_73 >= V_168 >> V_55 )
return V_185 ;
V_3 = F_179 ( V_2 , V_73 ) ;
if ( F_202 ( V_3 ) && ! ( V_182 -> V_33 & V_186 ) ) {
F_199 ( V_174 , V_132 , V_129 , V_3 , V_73 ) ;
} else if ( ! V_3 ) {
F_196 ( V_174 , V_132 , V_129 , V_73 ) ;
F_203 ( V_187 ) ;
F_204 ( V_174 -> V_188 , V_187 ) ;
V_36 = V_189 ;
V_190:
V_3 = F_179 ( V_2 , V_73 ) ;
if ( ! V_3 )
goto V_150;
}
if ( ! F_205 ( V_3 , V_174 -> V_188 , V_182 -> V_33 ) ) {
F_59 ( V_3 ) ;
return V_36 | V_191 ;
}
if ( F_34 ( V_3 -> V_2 != V_2 ) ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
goto V_190;
}
F_17 ( V_3 -> V_9 != V_73 , V_3 ) ;
if ( F_34 ( ! F_28 ( V_3 ) ) )
goto V_192;
V_168 = F_201 ( F_82 ( V_138 ) , V_144 ) ;
if ( F_34 ( V_73 >= V_168 >> V_55 ) ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
return V_185 ;
}
V_182 -> V_3 = V_3 ;
return V_36 | V_193 ;
V_150:
error = F_195 ( V_129 , V_73 , V_182 -> V_71 ) ;
if ( error >= 0 )
goto V_190;
if ( error == - V_160 )
return V_194 ;
return V_185 ;
V_192:
F_188 ( V_3 ) ;
error = V_2 -> V_34 -> V_158 ( V_129 , V_3 ) ;
if ( ! error ) {
F_148 ( V_3 ) ;
if ( ! F_28 ( V_3 ) )
error = - V_40 ;
}
F_59 ( V_3 ) ;
if ( ! error || error == V_159 )
goto V_190;
F_177 ( V_129 , V_132 ) ;
return V_185 ;
}
void F_206 ( struct V_195 * V_196 ,
T_2 V_197 , T_2 V_198 )
{
struct V_125 V_126 ;
void * * V_7 ;
struct V_129 * V_129 = V_196 -> V_174 -> V_183 ;
struct V_1 * V_2 = V_129 -> V_137 ;
T_2 V_199 = V_197 ;
T_1 V_168 ;
struct V_3 * V_110 , * V_3 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_126 . V_9 > V_198 )
break;
V_111:
V_3 = F_155 ( V_7 ) ;
if ( F_34 ( ! V_3 ) )
goto V_200;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_126 ) ;
continue;
}
goto V_200;
}
V_110 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_110 ) )
goto V_111;
if ( F_127 ( V_3 ) != V_110 ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( F_34 ( V_3 != * V_7 ) ) {
F_59 ( V_110 ) ;
goto V_111;
}
if ( ! F_28 ( V_3 ) ||
F_181 ( V_3 ) ||
F_207 ( V_3 ) )
goto V_201;
if ( ! F_164 ( V_3 ) )
goto V_201;
if ( V_3 -> V_2 != V_2 || ! F_28 ( V_3 ) )
goto V_202;
V_168 = F_201 ( F_82 ( V_2 -> V_32 ) , V_144 ) ;
if ( V_3 -> V_9 >= V_168 >> V_55 )
goto V_202;
if ( V_129 -> V_139 . V_178 > 0 )
V_129 -> V_139 . V_178 -- ;
V_196 -> V_203 += ( V_126 . V_9 - V_199 ) << V_55 ;
if ( V_196 -> V_204 )
V_196 -> V_204 += V_126 . V_9 - V_199 ;
V_199 = V_126 . V_9 ;
if ( F_208 ( V_196 , NULL , V_3 ) )
goto V_202;
F_126 ( V_3 ) ;
goto V_200;
V_202:
F_126 ( V_3 ) ;
V_201:
F_59 ( V_3 ) ;
V_200:
if ( F_209 ( * V_196 -> V_205 ) )
break;
if ( V_126 . V_9 == V_198 )
break;
}
F_159 () ;
}
int F_210 ( struct V_173 * V_174 , struct V_181 * V_182 )
{
struct V_3 * V_3 = V_182 -> V_3 ;
struct V_138 * V_138 = F_211 ( V_174 -> V_183 ) ;
int V_36 = V_193 ;
F_212 ( V_138 -> V_206 ) ;
F_213 ( V_174 -> V_183 ) ;
F_161 ( V_3 ) ;
if ( V_3 -> V_2 != V_138 -> V_207 ) {
F_126 ( V_3 ) ;
V_36 = V_208 ;
goto V_59;
}
F_214 ( V_3 ) ;
F_215 ( V_3 ) ;
V_59:
F_216 ( V_138 -> V_206 ) ;
return V_36 ;
}
int F_217 ( struct V_129 * V_129 , struct V_173 * V_174 )
{
struct V_1 * V_2 = V_129 -> V_137 ;
if ( ! V_2 -> V_34 -> V_158 )
return - V_209 ;
F_191 ( V_129 ) ;
V_174 -> V_210 = & V_211 ;
return 0 ;
}
int F_218 ( struct V_129 * V_129 , struct V_173 * V_174 )
{
if ( ( V_174 -> V_175 & V_212 ) && ( V_174 -> V_175 & V_213 ) )
return - V_214 ;
return F_217 ( V_129 , V_174 ) ;
}
int F_217 ( struct V_129 * V_129 , struct V_173 * V_174 )
{
return - V_215 ;
}
int F_218 ( struct V_129 * V_129 , struct V_173 * V_174 )
{
return - V_215 ;
}
static struct V_3 * F_219 ( struct V_3 * V_3 )
{
if ( ! F_220 ( V_3 ) ) {
F_148 ( V_3 ) ;
if ( ! F_28 ( V_3 ) ) {
F_59 ( V_3 ) ;
V_3 = F_221 ( - V_40 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_222 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_223)( void * , struct V_3 * ) ,
void * V_170 ,
T_3 V_80 )
{
struct V_3 * V_3 ;
int V_65 ;
V_111:
V_3 = F_179 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_109 ( V_80 | V_172 ) ;
if ( ! V_3 )
return F_221 ( - V_160 ) ;
V_65 = F_101 ( V_3 , V_2 , V_9 , V_80 ) ;
if ( F_34 ( V_65 ) ) {
F_59 ( V_3 ) ;
if ( V_65 == - V_12 )
goto V_111;
return F_221 ( V_65 ) ;
}
F_223:
V_65 = F_223 ( V_170 , V_3 ) ;
if ( V_65 < 0 ) {
F_59 ( V_3 ) ;
return F_221 ( V_65 ) ;
}
V_3 = F_219 ( V_3 ) ;
if ( F_220 ( V_3 ) )
return V_3 ;
goto V_59;
}
if ( F_28 ( V_3 ) )
goto V_59;
F_148 ( V_3 ) ;
if ( F_28 ( V_3 ) )
goto V_59;
F_161 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_126 ( V_3 ) ;
F_59 ( V_3 ) ;
goto V_111;
}
if ( F_28 ( V_3 ) ) {
F_126 ( V_3 ) ;
goto V_59;
}
goto F_223;
V_59:
F_165 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_224 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_223)( void * , struct V_3 * ) ,
void * V_170 )
{
return F_222 ( V_2 , V_9 , F_223 , V_170 , F_225 ( V_2 ) ) ;
}
struct V_3 * F_226 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_3 V_80 )
{
T_8 * F_223 = ( T_8 * ) V_2 -> V_34 -> V_158 ;
return F_222 ( V_2 , V_9 , F_223 , NULL , V_80 ) ;
}
inline T_6 F_227 ( struct V_162 * V_163 , struct V_135 * V_216 )
{
struct V_129 * V_129 = V_163 -> V_164 ;
struct V_138 * V_138 = V_129 -> V_137 -> V_32 ;
unsigned long V_217 = F_228 ( V_218 ) ;
T_1 V_219 ;
if ( ! F_186 ( V_216 ) )
return 0 ;
if ( V_163 -> V_166 & V_220 )
V_163 -> V_169 = F_82 ( V_138 ) ;
V_219 = V_163 -> V_169 ;
if ( V_217 != V_221 ) {
if ( V_163 -> V_169 >= V_217 ) {
F_229 ( V_222 , V_25 , 0 ) ;
return - V_223 ;
}
F_230 ( V_216 , V_217 - ( unsigned long ) V_219 ) ;
}
if ( F_34 ( V_219 + F_186 ( V_216 ) > V_224 &&
! ( V_129 -> V_225 & V_226 ) ) ) {
if ( V_219 >= V_224 )
return - V_223 ;
F_230 ( V_216 , V_224 - ( unsigned long ) V_219 ) ;
}
if ( F_34 ( V_219 >= V_138 -> V_206 -> V_227 ) )
return - V_223 ;
F_230 ( V_216 , V_138 -> V_206 -> V_227 - V_219 ) ;
return F_186 ( V_216 ) ;
}
int F_231 ( struct V_129 * V_129 , struct V_1 * V_2 ,
T_1 V_219 , unsigned V_228 , unsigned V_33 ,
struct V_3 * * V_109 , void * * V_229 )
{
const struct V_230 * V_231 = V_2 -> V_34 ;
return V_231 -> V_232 ( V_129 , V_2 , V_219 , V_228 , V_33 ,
V_109 , V_229 ) ;
}
int F_232 ( struct V_129 * V_129 , struct V_1 * V_2 ,
T_1 V_219 , unsigned V_228 , unsigned V_233 ,
struct V_3 * V_3 , void * V_229 )
{
const struct V_230 * V_231 = V_2 -> V_34 ;
return V_231 -> V_234 ( V_129 , V_2 , V_219 , V_228 , V_233 , V_3 , V_229 ) ;
}
T_6
F_233 ( struct V_162 * V_163 , struct V_135 * V_216 )
{
struct V_129 * V_129 = V_163 -> V_164 ;
struct V_1 * V_2 = V_129 -> V_137 ;
struct V_138 * V_138 = V_2 -> V_32 ;
T_1 V_219 = V_163 -> V_169 ;
T_6 V_136 ;
T_7 V_235 ;
T_2 V_42 ;
struct V_135 V_170 ;
V_235 = F_186 ( V_216 ) ;
V_42 = ( V_219 + V_235 - 1 ) >> V_55 ;
V_136 = F_85 ( V_2 , V_219 , V_219 + V_235 - 1 ) ;
if ( V_136 )
goto V_59;
if ( V_2 -> V_16 ) {
V_136 = F_234 ( V_2 ,
V_219 >> V_55 , V_42 ) ;
if ( V_136 ) {
if ( V_136 == - V_236 )
return 0 ;
goto V_59;
}
}
V_170 = * V_216 ;
V_136 = V_2 -> V_34 -> V_171 ( V_163 , & V_170 ) ;
if ( V_2 -> V_16 ) {
F_234 ( V_2 ,
V_219 >> V_55 , V_42 ) ;
}
if ( V_136 > 0 ) {
V_219 += V_136 ;
F_193 ( V_216 , V_136 ) ;
if ( V_219 > F_82 ( V_138 ) && ! F_235 ( V_138 -> V_237 ) ) {
F_236 ( V_138 , V_219 ) ;
F_237 ( V_138 ) ;
}
V_163 -> V_169 = V_219 ;
}
V_59:
return V_136 ;
}
struct V_3 * F_238 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_33 )
{
struct V_3 * V_3 ;
int V_112 = V_114 | V_118 | V_117 ;
if ( V_33 & V_238 )
V_112 |= V_119 ;
V_3 = F_163 ( V_2 , V_9 , V_112 ,
F_225 ( V_2 ) ) ;
if ( V_3 )
F_215 ( V_3 ) ;
return V_3 ;
}
T_6 F_239 ( struct V_129 * V_129 ,
struct V_135 * V_20 , T_1 V_219 )
{
struct V_1 * V_2 = V_129 -> V_137 ;
const struct V_230 * V_34 = V_2 -> V_34 ;
long V_239 = 0 ;
T_6 V_136 = 0 ;
unsigned int V_33 = 0 ;
if ( ! F_240 ( V_20 ) )
V_33 |= V_240 ;
do {
struct V_3 * V_3 ;
unsigned long V_73 ;
unsigned long V_241 ;
T_7 V_233 ;
void * V_229 ;
V_73 = ( V_219 & ( V_144 - 1 ) ) ;
V_241 = F_241 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_242:
if ( F_34 ( F_242 ( V_20 , V_241 ) ) ) {
V_239 = - V_156 ;
break;
}
if ( F_243 ( V_25 ) ) {
V_239 = - V_243 ;
break;
}
V_239 = V_34 -> V_232 ( V_129 , V_2 , V_219 , V_241 , V_33 ,
& V_3 , & V_229 ) ;
if ( F_34 ( V_239 < 0 ) )
break;
if ( F_183 ( V_2 ) )
F_184 ( V_3 ) ;
V_233 = F_244 ( V_3 , V_20 , V_73 , V_241 ) ;
F_184 ( V_3 ) ;
V_239 = V_34 -> V_234 ( V_129 , V_2 , V_219 , V_241 , V_233 ,
V_3 , V_229 ) ;
if ( F_34 ( V_239 < 0 ) )
break;
V_233 = V_239 ;
F_79 () ;
F_193 ( V_20 , V_233 ) ;
if ( F_34 ( V_233 == 0 ) ) {
V_241 = F_241 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_242;
}
V_219 += V_233 ;
V_136 += V_233 ;
F_245 ( V_2 ) ;
} while ( F_186 ( V_20 ) );
return V_136 ? V_136 : V_239 ;
}
T_6 F_246 ( struct V_162 * V_163 , struct V_135 * V_216 )
{
struct V_129 * V_129 = V_163 -> V_164 ;
struct V_1 * V_2 = V_129 -> V_137 ;
struct V_138 * V_138 = V_2 -> V_32 ;
T_6 V_136 = 0 ;
T_6 V_65 ;
T_6 V_239 ;
V_25 -> V_244 = F_247 ( V_138 ) ;
V_65 = F_248 ( V_129 ) ;
if ( V_65 )
goto V_59;
V_65 = F_213 ( V_129 ) ;
if ( V_65 )
goto V_59;
if ( V_163 -> V_166 & V_167 ) {
T_1 V_219 , V_245 ;
V_136 = F_233 ( V_163 , V_216 ) ;
if ( V_136 < 0 || ! F_186 ( V_216 ) || F_194 ( V_138 ) )
goto V_59;
V_239 = F_239 ( V_129 , V_216 , V_219 = V_163 -> V_169 ) ;
if ( F_34 ( V_239 < 0 ) ) {
V_65 = V_239 ;
goto V_59;
}
V_245 = V_219 + V_239 - 1 ;
V_65 = F_85 ( V_2 , V_219 , V_245 ) ;
if ( V_65 == 0 ) {
V_163 -> V_169 = V_245 + 1 ;
V_136 += V_239 ;
F_249 ( V_2 ,
V_219 >> V_55 ,
V_245 >> V_55 ) ;
} else {
}
} else {
V_136 = F_239 ( V_129 , V_216 , V_163 -> V_169 ) ;
if ( F_202 ( V_136 > 0 ) )
V_163 -> V_169 += V_136 ;
}
V_59:
V_25 -> V_244 = NULL ;
return V_136 ? V_136 : V_65 ;
}
T_6 F_250 ( struct V_162 * V_163 , struct V_135 * V_216 )
{
struct V_129 * V_129 = V_163 -> V_164 ;
struct V_138 * V_138 = V_129 -> V_137 -> V_32 ;
T_6 V_36 ;
F_251 ( V_138 ) ;
V_36 = F_227 ( V_163 , V_216 ) ;
if ( V_36 > 0 )
V_36 = F_246 ( V_163 , V_216 ) ;
F_252 ( V_138 ) ;
if ( V_36 > 0 )
V_36 = F_253 ( V_163 , V_36 ) ;
return V_36 ;
}
int F_254 ( struct V_3 * V_3 , T_3 V_71 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_56 ( ! F_18 ( V_3 ) ) ;
if ( F_255 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_34 -> V_246 )
return V_2 -> V_34 -> V_246 ( V_3 , V_71 ) ;
return F_256 ( V_3 ) ;
}
