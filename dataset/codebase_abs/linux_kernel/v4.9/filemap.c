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
int V_20 , V_21 = F_15 ( V_3 ) ? 1 : F_16 ( V_3 ) ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_17 ( F_19 ( V_3 ) , V_3 ) ;
F_17 ( V_21 != 1 && V_19 , V_3 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_5 * V_6 ;
void * * V_7 ;
F_20 ( & V_2 -> V_8 , V_3 -> V_9 + V_20 ,
& V_6 , & V_7 ) ;
F_21 ( & V_2 -> V_8 , V_6 , V_7 ) ;
if ( ! V_6 ) {
F_17 ( V_21 != 1 , V_3 ) ;
V_19 = NULL ;
}
F_10 ( V_7 , V_19 ) ;
if ( ! V_6 )
break;
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
if ( V_19 ) {
V_2 -> V_13 += V_21 ;
F_26 () ;
}
V_2 -> V_16 -= V_21 ;
}
void F_27 ( struct V_3 * V_3 , void * V_19 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_21 = F_16 ( V_3 ) ;
F_28 ( V_3 ) ;
if ( F_29 ( V_3 ) && F_30 ( V_3 ) )
F_31 ( V_3 ) ;
else
F_32 ( V_2 , V_3 ) ;
F_17 ( F_19 ( V_3 ) , V_3 ) ;
F_17 ( F_33 ( V_3 ) , V_3 ) ;
if ( ! F_34 ( V_23 ) && F_35 ( F_33 ( V_3 ) ) ) {
int V_24 ;
F_36 ( L_1 ,
V_25 -> V_26 , F_37 ( V_3 ) ) ;
F_38 ( V_3 , L_2 ) ;
F_39 () ;
F_40 ( V_27 , V_28 ) ;
V_24 = F_41 ( V_3 ) ;
if ( F_42 ( V_2 ) &&
F_43 ( V_3 ) >= V_24 + 2 ) {
F_44 ( V_3 ) ;
F_45 ( V_3 , V_24 ) ;
}
}
F_14 ( V_2 , V_3 , V_19 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_15 ( V_3 ) )
F_46 ( F_47 ( V_3 ) , V_29 , - V_21 ) ;
if ( F_48 ( V_3 ) ) {
F_46 ( F_47 ( V_3 ) , V_30 , - V_21 ) ;
if ( F_49 ( V_3 ) )
F_50 ( V_3 , V_31 ) ;
} else {
F_17 ( F_49 ( V_3 ) && ! F_15 ( V_3 ) , V_3 ) ;
}
if ( F_7 ( F_51 ( V_3 ) ) )
F_52 ( V_3 , V_2 , F_53 ( V_2 -> V_32 ) ) ;
}
void F_54 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_55 ( V_3 ) ;
unsigned long V_33 ;
void (* F_56)( struct V_3 * );
F_57 ( ! F_18 ( V_3 ) ) ;
F_56 = V_2 -> V_34 -> F_56 ;
F_58 ( & V_2 -> V_11 , V_33 ) ;
F_27 ( V_3 , NULL ) ;
F_59 ( & V_2 -> V_11 , V_33 ) ;
if ( F_56 )
F_56 ( V_3 ) ;
if ( F_49 ( V_3 ) && ! F_15 ( V_3 ) ) {
F_45 ( V_3 , V_35 ) ;
F_17 ( F_43 ( V_3 ) <= 0 , V_3 ) ;
} else {
F_60 ( V_3 ) ;
}
}
int F_61 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
if ( F_62 ( V_37 , & V_2 -> V_33 ) &&
F_63 ( V_37 , & V_2 -> V_33 ) )
V_36 = - V_38 ;
if ( F_62 ( V_39 , & V_2 -> V_33 ) &&
F_63 ( V_39 , & V_2 -> V_33 ) )
V_36 = - V_40 ;
return V_36 ;
}
int F_64 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_42 , int V_43 )
{
int V_36 ;
struct V_44 V_45 = {
. V_43 = V_43 ,
. V_46 = V_47 ,
. V_48 = V_41 ,
. V_49 = V_42 ,
} ;
if ( ! F_65 ( V_2 ) )
return 0 ;
F_66 ( & V_45 , V_2 -> V_32 ) ;
V_36 = F_67 ( V_2 , & V_45 ) ;
F_68 ( & V_45 ) ;
return V_36 ;
}
static inline int F_69 ( struct V_1 * V_2 ,
int V_43 )
{
return F_64 ( V_2 , 0 , V_50 , V_43 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , V_51 ) ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_42 )
{
return F_64 ( V_2 , V_41 , V_42 , V_51 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , V_52 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
T_1 V_53 , T_1 V_54 )
{
T_2 V_9 = V_53 >> V_55 ;
T_2 V_42 = V_54 >> V_55 ;
struct V_56 V_57 ;
int V_58 ;
int V_36 = 0 ;
if ( V_54 < V_53 )
goto V_59;
F_74 ( & V_57 , 0 ) ;
while ( ( V_9 <= V_42 ) &&
( V_58 = F_75 ( & V_57 , V_2 , & V_9 ,
V_60 ,
F_76 ( V_42 - V_9 , ( T_2 ) V_61 - 1 ) + 1 ) ) != 0 ) {
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
struct V_3 * V_3 = V_57 . V_62 [ V_20 ] ;
if ( V_3 -> V_9 > V_42 )
continue;
F_77 ( V_3 ) ;
if ( F_78 ( V_3 ) )
V_36 = - V_40 ;
}
F_79 ( & V_57 ) ;
F_80 () ;
}
V_59:
return V_36 ;
}
int F_81 ( struct V_1 * V_2 , T_1 V_53 ,
T_1 V_54 )
{
int V_36 , V_63 ;
V_36 = F_73 ( V_2 , V_53 , V_54 ) ;
V_63 = F_61 ( V_2 ) ;
if ( ! V_36 )
V_36 = V_63 ;
return V_36 ;
}
void F_82 ( struct V_1 * V_2 )
{
T_1 V_64 = F_83 ( V_2 -> V_32 ) ;
if ( V_64 == 0 )
return;
F_73 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
T_1 V_64 = F_83 ( V_2 -> V_32 ) ;
if ( V_64 == 0 )
return 0 ;
return F_81 ( V_2 , 0 , V_64 - 1 ) ;
}
int F_85 ( struct V_1 * V_2 )
{
int V_65 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_65 = F_70 ( V_2 ) ;
if ( V_65 != - V_40 ) {
int V_66 = F_84 ( V_2 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_61 ( V_2 ) ;
}
return V_65 ;
}
int F_86 ( struct V_1 * V_2 ,
T_1 V_67 , T_1 V_68 )
{
int V_65 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_65 = F_64 ( V_2 , V_67 , V_68 ,
V_51 ) ;
if ( V_65 != - V_40 ) {
int V_66 = F_81 ( V_2 ,
V_67 , V_68 ) ;
if ( ! V_65 )
V_65 = V_66 ;
}
} else {
V_65 = F_61 ( V_2 ) ;
}
return V_65 ;
}
int F_87 ( struct V_3 * V_69 , struct V_3 * V_70 , T_3 V_71 )
{
int error ;
F_17 ( ! F_18 ( V_69 ) , V_69 ) ;
F_17 ( ! F_18 ( V_70 ) , V_70 ) ;
F_17 ( V_70 -> V_2 , V_70 ) ;
error = F_88 ( V_71 & ~ V_72 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_69 -> V_2 ;
void (* F_56)( struct V_3 * );
unsigned long V_33 ;
T_2 V_73 = V_69 -> V_9 ;
F_56 = V_2 -> V_34 -> F_56 ;
F_89 ( V_70 ) ;
V_70 -> V_2 = V_2 ;
V_70 -> V_9 = V_73 ;
F_58 ( & V_2 -> V_11 , V_33 ) ;
F_27 ( V_69 , NULL ) ;
error = F_1 ( V_2 , V_70 , NULL ) ;
F_57 ( error ) ;
if ( ! F_15 ( V_70 ) )
F_90 ( V_70 , V_29 ) ;
if ( F_48 ( V_70 ) )
F_90 ( V_70 , V_30 ) ;
F_59 ( & V_2 -> V_11 , V_33 ) ;
F_91 ( V_69 , V_70 ) ;
F_92 () ;
if ( F_56 )
F_56 ( V_69 ) ;
F_60 ( V_69 ) ;
}
return error ;
}
static int F_93 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 ,
void * * V_4 )
{
int V_74 = F_15 ( V_3 ) ;
struct V_75 * V_76 ;
int error ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_17 ( F_48 ( V_3 ) , V_3 ) ;
if ( ! V_74 ) {
error = F_94 ( V_3 , V_25 -> V_77 ,
V_71 , & V_76 , false ) ;
if ( error )
return error ;
}
error = F_95 ( V_71 & ~ V_72 ) ;
if ( error ) {
if ( ! V_74 )
F_96 ( V_3 , V_76 , false ) ;
return error ;
}
F_89 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = V_73 ;
F_97 ( & V_2 -> V_11 ) ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
F_92 () ;
if ( F_35 ( error ) )
goto V_78;
if ( ! V_74 )
F_90 ( V_3 , V_29 ) ;
F_98 ( & V_2 -> V_11 ) ;
if ( ! V_74 )
F_99 ( V_3 , V_76 , false , false ) ;
F_100 ( V_3 ) ;
return 0 ;
V_78:
V_3 -> V_2 = NULL ;
F_98 ( & V_2 -> V_11 ) ;
if ( ! V_74 )
F_96 ( V_3 , V_76 , false ) ;
F_60 ( V_3 ) ;
return error ;
}
int F_101 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 )
{
return F_93 ( V_3 , V_2 , V_73 ,
V_71 , NULL ) ;
}
int F_102 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_73 , T_3 V_71 )
{
void * V_19 = NULL ;
int V_36 ;
F_103 ( V_3 ) ;
V_36 = F_93 ( V_3 , V_2 , V_73 ,
V_71 , & V_19 ) ;
if ( F_35 ( V_36 ) )
F_104 ( V_3 ) ;
else {
if ( ! ( V_71 & V_79 ) &&
V_19 && F_105 ( V_19 ) ) {
F_106 ( V_3 ) ;
F_107 ( V_3 ) ;
} else
F_108 ( V_3 ) ;
F_109 ( V_3 ) ;
}
return V_36 ;
}
struct V_3 * F_110 ( T_3 V_80 )
{
int V_81 ;
struct V_3 * V_3 ;
if ( F_111 () ) {
unsigned int V_82 ;
do {
V_82 = F_112 () ;
V_81 = F_113 () ;
V_3 = F_114 ( V_81 , V_80 , 0 ) ;
} while ( ! V_3 && F_115 ( V_82 ) );
return V_3 ;
}
return F_116 ( V_80 , 0 ) ;
}
T_4 * F_117 ( struct V_3 * V_3 )
{
return F_118 ( V_3 , 0 ) ;
}
void F_119 ( struct V_3 * V_3 , int V_83 )
{
F_120 ( V_84 , & V_3 -> V_33 , V_83 ) ;
if ( F_62 ( V_83 , & V_3 -> V_33 ) )
F_121 ( F_117 ( V_3 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_122 ( struct V_3 * V_3 , int V_83 )
{
F_120 ( V_84 , & V_3 -> V_33 , V_83 ) ;
if ( ! F_62 ( V_83 , & V_3 -> V_33 ) )
return 0 ;
return F_121 ( F_117 ( V_3 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_123 ( struct V_3 * V_3 ,
int V_83 , unsigned long V_88 )
{
F_120 ( V_84 , & V_3 -> V_33 , V_83 ) ;
V_84 . V_89 . V_88 = V_90 + V_88 ;
if ( ! F_62 ( V_83 , & V_3 -> V_33 ) )
return 0 ;
return F_121 ( F_117 ( V_3 ) , & V_84 ,
V_91 , V_87 ) ;
}
void F_124 ( struct V_3 * V_3 , T_5 * V_92 )
{
T_4 * V_93 = F_117 ( V_3 ) ;
unsigned long V_33 ;
F_58 ( & V_93 -> V_94 , V_33 ) ;
F_125 ( V_93 , V_92 ) ;
F_59 ( & V_93 -> V_94 , V_33 ) ;
}
void F_126 ( struct V_3 * V_3 )
{
V_3 = F_127 ( V_3 ) ;
F_17 ( ! F_18 ( V_3 ) , V_3 ) ;
F_128 ( V_95 , & V_3 -> V_33 ) ;
F_129 () ;
F_130 ( V_3 , V_95 ) ;
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
F_130 ( V_3 , V_96 ) ;
}
void F_137 ( struct V_3 * V_3 , bool V_97 , int V_65 )
{
if ( ! V_97 ) {
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
struct V_3 * V_98 = F_127 ( V_3 ) ;
F_120 ( V_84 , & V_98 -> V_33 , V_95 ) ;
F_143 ( F_117 ( V_98 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_144 ( struct V_3 * V_3 )
{
struct V_3 * V_98 = F_127 ( V_3 ) ;
F_120 ( V_84 , & V_98 -> V_33 , V_95 ) ;
return F_143 ( F_117 ( V_98 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_145 ( struct V_3 * V_3 , struct V_99 * V_77 ,
unsigned int V_33 )
{
if ( V_33 & V_100 ) {
if ( V_33 & V_101 )
return 0 ;
F_146 ( & V_77 -> V_102 ) ;
if ( V_33 & V_103 )
F_147 ( V_3 ) ;
else
F_148 ( V_3 ) ;
return 0 ;
} else {
if ( V_33 & V_103 ) {
int V_36 ;
V_36 = F_144 ( V_3 ) ;
if ( V_36 ) {
F_146 ( & V_77 -> V_102 ) ;
return 0 ;
}
} else
F_142 ( V_3 ) ;
return 1 ;
}
}
T_2 F_149 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_104 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_104 ; V_20 ++ ) {
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
T_2 V_9 , unsigned long V_104 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_104 ; V_20 ++ ) {
struct V_3 * V_3 ;
V_3 = F_150 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_105 )
break;
}
return V_9 ;
}
struct V_3 * F_152 ( struct V_1 * V_2 , T_2 V_73 )
{
void * * V_106 ;
struct V_3 * V_107 , * V_3 ;
F_153 () ;
V_108:
V_3 = NULL ;
V_106 = F_154 ( & V_2 -> V_8 , V_73 ) ;
if ( V_106 ) {
V_3 = F_155 ( V_106 ) ;
if ( F_35 ( ! V_3 ) )
goto V_59;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) )
goto V_108;
goto V_59;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_106 ) ) {
F_60 ( V_107 ) ;
goto V_108;
}
}
V_59:
F_159 () ;
return V_3 ;
}
struct V_3 * F_160 ( struct V_1 * V_2 , T_2 V_73 )
{
struct V_3 * V_3 ;
V_108:
V_3 = F_152 ( V_2 , V_73 ) ;
if ( V_3 && ! F_156 ( V_3 ) ) {
F_161 ( V_3 ) ;
if ( F_35 ( F_55 ( V_3 ) != V_2 ) ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
goto V_108;
}
F_17 ( F_162 ( V_3 ) != V_73 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_163 ( struct V_1 * V_2 , T_2 V_73 ,
int V_109 , T_3 V_71 )
{
struct V_3 * V_3 ;
V_108:
V_3 = F_152 ( V_2 , V_73 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_110;
if ( V_109 & V_111 ) {
if ( V_109 & V_112 ) {
if ( ! F_164 ( V_3 ) ) {
F_60 ( V_3 ) ;
return NULL ;
}
} else {
F_161 ( V_3 ) ;
}
if ( F_35 ( V_3 -> V_2 != V_2 ) ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
goto V_108;
}
F_17 ( V_3 -> V_9 != V_73 , V_3 ) ;
}
if ( V_3 && ( V_109 & V_113 ) )
F_165 ( V_3 ) ;
V_110:
if ( ! V_3 && ( V_109 & V_114 ) ) {
int V_65 ;
if ( ( V_109 & V_115 ) && F_166 ( V_2 ) )
V_71 |= V_79 ;
if ( V_109 & V_116 )
V_71 &= ~ V_117 ;
V_3 = F_110 ( V_71 ) ;
if ( ! V_3 )
return NULL ;
if ( F_7 ( ! ( V_109 & V_111 ) ) )
V_109 |= V_111 ;
if ( V_109 & V_113 )
F_167 ( V_3 ) ;
V_65 = F_102 ( V_3 , V_2 , V_73 ,
V_71 & V_118 ) ;
if ( F_35 ( V_65 ) ) {
F_60 ( V_3 ) ;
V_3 = NULL ;
if ( V_65 == - V_12 )
goto V_108;
}
}
return V_3 ;
}
unsigned F_168 ( struct V_1 * V_2 ,
T_2 V_41 , unsigned int V_119 ,
struct V_3 * * V_120 , T_2 * V_121 )
{
void * * V_7 ;
unsigned int V_36 = 0 ;
struct V_122 V_123 ;
if ( ! V_119 )
return 0 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_107 , * V_3 ;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
goto V_124;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
}
V_124:
V_121 [ V_36 ] = V_123 . V_9 ;
V_120 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_119 )
break;
}
F_159 () ;
return V_36 ;
}
unsigned F_171 ( struct V_1 * V_2 , T_2 V_41 ,
unsigned int V_58 , struct V_3 * * V_62 )
{
struct V_122 V_123 ;
void * * V_7 ;
unsigned V_36 = 0 ;
if ( F_35 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_107 , * V_3 ;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
continue;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
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
struct V_122 V_123 ;
void * * V_7 ;
unsigned int V_36 = 0 ;
if ( F_35 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_173 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_107 , * V_3 ;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
break;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
break;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( V_3 -> V_2 == NULL || F_162 ( V_3 ) != V_123 . V_9 ) {
F_60 ( V_3 ) ;
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
int V_125 , unsigned int V_58 , struct V_3 * * V_62 )
{
struct V_122 V_123 ;
void * * V_7 ;
unsigned V_36 = 0 ;
if ( F_35 ( ! V_58 ) )
return 0 ;
F_153 () ;
F_175 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_107 , * V_3 ;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
continue;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
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
int V_125 , unsigned int V_119 ,
struct V_3 * * V_120 , T_2 * V_121 )
{
void * * V_7 ;
unsigned int V_36 = 0 ;
struct V_122 V_123 ;
if ( ! V_119 )
return 0 ;
F_153 () ;
F_175 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_107 , * V_3 ;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
continue;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
goto V_124;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
}
V_124:
V_121 [ V_36 ] = V_123 . V_9 ;
V_120 [ V_36 ] = V_3 ;
if ( ++ V_36 == V_119 )
break;
}
F_159 () ;
return V_36 ;
}
static void F_177 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
V_129 -> V_130 /= 4 ;
}
static T_6 F_178 ( struct V_126 * V_127 , T_1 * V_131 ,
struct V_132 * V_123 , T_6 V_133 )
{
struct V_1 * V_2 = V_127 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_32 ;
struct V_128 * V_129 = & V_127 -> V_136 ;
T_2 V_9 ;
T_2 V_137 ;
T_2 V_138 ;
unsigned long V_73 ;
unsigned int V_139 ;
int error = 0 ;
if ( F_35 ( * V_131 >= V_135 -> V_140 -> V_141 ) )
return - V_142 ;
F_179 ( V_123 , V_135 -> V_140 -> V_141 ) ;
V_9 = * V_131 >> V_55 ;
V_138 = V_129 -> V_143 >> V_55 ;
V_139 = V_129 -> V_143 & ( V_144 - 1 ) ;
V_137 = ( * V_131 + V_123 -> V_145 + V_144 - 1 ) >> V_55 ;
V_73 = * V_131 & ~ V_146 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_147 ;
T_1 V_148 ;
unsigned long V_21 , V_36 ;
F_80 () ;
V_149:
V_3 = F_180 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
F_181 ( V_2 ,
V_129 , V_127 ,
V_9 , V_137 - V_9 ) ;
V_3 = F_180 ( V_2 , V_9 ) ;
if ( F_35 ( V_3 == NULL ) )
goto V_150;
}
if ( F_182 ( V_3 ) ) {
F_183 ( V_2 ,
V_129 , V_127 , V_3 ,
V_9 , V_137 - V_9 ) ;
}
if ( ! F_29 ( V_3 ) ) {
error = F_147 ( V_3 ) ;
if ( F_35 ( error ) )
goto V_151;
if ( F_29 ( V_3 ) )
goto V_152;
if ( V_135 -> V_153 == V_55 ||
! V_2 -> V_34 -> V_154 )
goto V_155;
if ( F_35 ( V_123 -> type & V_156 ) )
goto V_155;
if ( ! F_164 ( V_3 ) )
goto V_155;
if ( ! V_3 -> V_2 )
goto V_157;
if ( ! V_2 -> V_34 -> V_154 ( V_3 ,
V_73 , V_123 -> V_145 ) )
goto V_157;
F_126 ( V_3 ) ;
}
V_152:
V_148 = F_83 ( V_135 ) ;
V_147 = ( V_148 - 1 ) >> V_55 ;
if ( F_35 ( ! V_148 || V_9 > V_147 ) ) {
F_60 ( V_3 ) ;
goto V_59;
}
V_21 = V_144 ;
if ( V_9 == V_147 ) {
V_21 = ( ( V_148 - 1 ) & ~ V_146 ) + 1 ;
if ( V_21 <= V_73 ) {
F_60 ( V_3 ) ;
goto V_59;
}
}
V_21 = V_21 - V_73 ;
if ( F_184 ( V_2 ) )
F_185 ( V_3 ) ;
if ( V_138 != V_9 || V_73 != V_139 )
F_165 ( V_3 ) ;
V_138 = V_9 ;
V_36 = F_186 ( V_3 , V_73 , V_21 , V_123 ) ;
V_73 += V_36 ;
V_9 += V_73 >> V_55 ;
V_73 &= ~ V_146 ;
V_139 = V_73 ;
F_60 ( V_3 ) ;
V_133 += V_36 ;
if ( ! F_187 ( V_123 ) )
goto V_59;
if ( V_36 < V_21 ) {
error = - V_158 ;
goto V_59;
}
continue;
V_155:
error = F_188 ( V_3 ) ;
if ( F_35 ( error ) )
goto V_151;
V_157:
if ( ! V_3 -> V_2 ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
continue;
}
if ( F_29 ( V_3 ) ) {
F_126 ( V_3 ) ;
goto V_152;
}
V_159:
F_189 ( V_3 ) ;
error = V_2 -> V_34 -> V_159 ( V_127 , V_3 ) ;
if ( F_35 ( error ) ) {
if ( error == V_160 ) {
F_60 ( V_3 ) ;
error = 0 ;
goto V_149;
}
goto V_151;
}
if ( ! F_29 ( V_3 ) ) {
error = F_188 ( V_3 ) ;
if ( F_35 ( error ) )
goto V_151;
if ( ! F_29 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
goto V_149;
}
F_126 ( V_3 ) ;
F_177 ( V_127 , V_129 ) ;
error = - V_40 ;
goto V_151;
}
F_126 ( V_3 ) ;
}
goto V_152;
V_151:
F_60 ( V_3 ) ;
goto V_59;
V_150:
V_3 = F_190 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_161 ;
goto V_59;
}
error = F_102 ( V_3 , V_2 , V_9 ,
F_191 ( V_2 , V_162 ) ) ;
if ( error ) {
F_60 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_149;
}
goto V_59;
}
goto V_159;
}
V_59:
V_129 -> V_143 = V_138 ;
V_129 -> V_143 <<= V_55 ;
V_129 -> V_143 |= V_139 ;
* V_131 = ( ( T_1 ) V_9 << V_55 ) + V_73 ;
F_192 ( V_127 ) ;
return V_133 ? V_133 : error ;
}
T_6
F_193 ( struct V_163 * V_164 , struct V_132 * V_123 )
{
struct V_126 * V_126 = V_164 -> V_165 ;
T_6 V_166 = 0 ;
T_7 V_145 = F_187 ( V_123 ) ;
if ( ! V_145 )
goto V_59;
if ( V_164 -> V_167 & V_168 ) {
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_32 ;
struct V_132 V_169 = * V_123 ;
T_1 V_170 ;
V_170 = F_83 ( V_135 ) ;
V_166 = F_86 ( V_2 , V_164 -> V_171 ,
V_164 -> V_171 + V_145 - 1 ) ;
if ( V_166 < 0 )
goto V_59;
F_192 ( V_126 ) ;
V_166 = V_2 -> V_34 -> V_172 ( V_164 , & V_169 ) ;
if ( V_166 >= 0 ) {
V_164 -> V_171 += V_166 ;
F_194 ( V_123 , V_166 ) ;
}
if ( V_166 < 0 || ! F_187 ( V_123 ) || V_164 -> V_171 >= V_170 ||
F_195 ( V_135 ) )
goto V_59;
}
V_166 = F_178 ( V_126 , & V_164 -> V_171 , V_123 , V_166 ) ;
V_59:
return V_166 ;
}
static int F_196 ( struct V_126 * V_126 , T_2 V_73 , T_3 V_71 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_3 * V_3 ;
int V_36 ;
do {
V_3 = F_110 ( V_71 | V_173 ) ;
if ( ! V_3 )
return - V_161 ;
V_36 = F_102 ( V_3 , V_2 , V_73 , V_71 & V_162 ) ;
if ( V_36 == 0 )
V_36 = V_2 -> V_34 -> V_159 ( V_126 , V_3 ) ;
else if ( V_36 == - V_12 )
V_36 = 0 ;
F_60 ( V_3 ) ;
} while ( V_36 == V_160 );
return V_36 ;
}
static void F_197 ( struct V_174 * V_175 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
T_2 V_73 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_175 -> V_176 & V_177 )
return;
if ( ! V_129 -> V_130 )
return;
if ( V_175 -> V_176 & V_178 ) {
F_181 ( V_2 , V_129 , V_126 , V_73 ,
V_129 -> V_130 ) ;
return;
}
if ( V_129 -> V_179 < V_180 * 10 )
V_129 -> V_179 ++ ;
if ( V_129 -> V_179 > V_180 )
return;
V_129 -> V_41 = F_198 ( long , 0 , V_73 - V_129 -> V_130 / 2 ) ;
V_129 -> V_170 = V_129 -> V_130 ;
V_129 -> V_181 = V_129 -> V_130 / 4 ;
F_199 ( V_129 , V_2 , V_126 ) ;
}
static void F_200 ( struct V_174 * V_175 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
struct V_3 * V_3 ,
T_2 V_73 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_175 -> V_176 & V_177 )
return;
if ( V_129 -> V_179 > 0 )
V_129 -> V_179 -- ;
if ( F_182 ( V_3 ) )
F_183 ( V_2 , V_129 , V_126 ,
V_3 , V_73 , V_129 -> V_130 ) ;
}
int F_201 ( struct V_174 * V_175 , struct V_182 * V_183 )
{
int error ;
struct V_126 * V_126 = V_175 -> V_184 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_128 * V_129 = & V_126 -> V_136 ;
struct V_135 * V_135 = V_2 -> V_32 ;
T_2 V_73 = V_183 -> V_185 ;
struct V_3 * V_3 ;
T_1 V_170 ;
int V_36 = 0 ;
V_170 = F_202 ( F_83 ( V_135 ) , V_144 ) ;
if ( V_73 >= V_170 >> V_55 )
return V_186 ;
V_3 = F_180 ( V_2 , V_73 ) ;
if ( F_203 ( V_3 ) && ! ( V_183 -> V_33 & V_187 ) ) {
F_200 ( V_175 , V_129 , V_126 , V_3 , V_73 ) ;
} else if ( ! V_3 ) {
F_197 ( V_175 , V_129 , V_126 , V_73 ) ;
F_204 ( V_188 ) ;
F_205 ( V_175 -> V_189 , V_188 ) ;
V_36 = V_190 ;
V_191:
V_3 = F_180 ( V_2 , V_73 ) ;
if ( ! V_3 )
goto V_150;
}
if ( ! F_206 ( V_3 , V_175 -> V_189 , V_183 -> V_33 ) ) {
F_60 ( V_3 ) ;
return V_36 | V_192 ;
}
if ( F_35 ( V_3 -> V_2 != V_2 ) ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
goto V_191;
}
F_17 ( V_3 -> V_9 != V_73 , V_3 ) ;
if ( F_35 ( ! F_29 ( V_3 ) ) )
goto V_193;
V_170 = F_202 ( F_83 ( V_135 ) , V_144 ) ;
if ( F_35 ( V_73 >= V_170 >> V_55 ) ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
return V_186 ;
}
V_183 -> V_3 = V_3 ;
return V_36 | V_194 ;
V_150:
error = F_196 ( V_126 , V_73 , V_183 -> V_71 ) ;
if ( error >= 0 )
goto V_191;
if ( error == - V_161 )
return V_195 ;
return V_186 ;
V_193:
F_189 ( V_3 ) ;
error = V_2 -> V_34 -> V_159 ( V_126 , V_3 ) ;
if ( ! error ) {
F_148 ( V_3 ) ;
if ( ! F_29 ( V_3 ) )
error = - V_40 ;
}
F_60 ( V_3 ) ;
if ( ! error || error == V_160 )
goto V_191;
F_177 ( V_126 , V_129 ) ;
return V_186 ;
}
void F_207 ( struct V_196 * V_197 ,
T_2 V_198 , T_2 V_199 )
{
struct V_122 V_123 ;
void * * V_7 ;
struct V_126 * V_126 = V_197 -> V_175 -> V_184 ;
struct V_1 * V_2 = V_126 -> V_134 ;
T_2 V_200 = V_198 ;
T_1 V_170 ;
struct V_3 * V_107 , * V_3 ;
F_153 () ;
F_169 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_123 . V_9 > V_199 )
break;
V_108:
V_3 = F_155 ( V_7 ) ;
if ( F_35 ( ! V_3 ) )
goto V_201;
if ( F_156 ( V_3 ) ) {
if ( F_157 ( V_3 ) ) {
V_7 = F_170 ( & V_123 ) ;
continue;
}
goto V_201;
}
V_107 = F_127 ( V_3 ) ;
if ( ! F_158 ( V_107 ) )
goto V_108;
if ( F_127 ( V_3 ) != V_107 ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( F_35 ( V_3 != * V_7 ) ) {
F_60 ( V_107 ) ;
goto V_108;
}
if ( ! F_29 ( V_3 ) ||
F_182 ( V_3 ) ||
F_208 ( V_3 ) )
goto V_202;
if ( ! F_164 ( V_3 ) )
goto V_202;
if ( V_3 -> V_2 != V_2 || ! F_29 ( V_3 ) )
goto V_203;
V_170 = F_202 ( F_83 ( V_2 -> V_32 ) , V_144 ) ;
if ( V_3 -> V_9 >= V_170 >> V_55 )
goto V_203;
if ( V_126 -> V_136 . V_179 > 0 )
V_126 -> V_136 . V_179 -- ;
V_197 -> V_204 += ( V_123 . V_9 - V_200 ) << V_55 ;
if ( V_197 -> V_205 )
V_197 -> V_205 += V_123 . V_9 - V_200 ;
V_200 = V_123 . V_9 ;
if ( F_209 ( V_197 , NULL , V_3 ) )
goto V_203;
F_126 ( V_3 ) ;
goto V_201;
V_203:
F_126 ( V_3 ) ;
V_202:
F_60 ( V_3 ) ;
V_201:
if ( F_210 ( * V_197 -> V_206 ) )
break;
if ( V_123 . V_9 == V_199 )
break;
}
F_159 () ;
}
int F_211 ( struct V_174 * V_175 , struct V_182 * V_183 )
{
struct V_3 * V_3 = V_183 -> V_3 ;
struct V_135 * V_135 = F_212 ( V_175 -> V_184 ) ;
int V_36 = V_194 ;
F_213 ( V_135 -> V_140 ) ;
F_214 ( V_175 -> V_184 ) ;
F_161 ( V_3 ) ;
if ( V_3 -> V_2 != V_135 -> V_207 ) {
F_126 ( V_3 ) ;
V_36 = V_208 ;
goto V_59;
}
F_215 ( V_3 ) ;
F_216 ( V_3 ) ;
V_59:
F_217 ( V_135 -> V_140 ) ;
return V_36 ;
}
int F_218 ( struct V_126 * V_126 , struct V_174 * V_175 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( ! V_2 -> V_34 -> V_159 )
return - V_209 ;
F_192 ( V_126 ) ;
V_175 -> V_210 = & V_211 ;
return 0 ;
}
int F_219 ( struct V_126 * V_126 , struct V_174 * V_175 )
{
if ( ( V_175 -> V_176 & V_212 ) && ( V_175 -> V_176 & V_213 ) )
return - V_142 ;
return F_218 ( V_126 , V_175 ) ;
}
int F_218 ( struct V_126 * V_126 , struct V_174 * V_175 )
{
return - V_214 ;
}
int F_219 ( struct V_126 * V_126 , struct V_174 * V_175 )
{
return - V_214 ;
}
static struct V_3 * F_220 ( struct V_3 * V_3 )
{
if ( ! F_221 ( V_3 ) ) {
F_148 ( V_3 ) ;
if ( ! F_29 ( V_3 ) ) {
F_60 ( V_3 ) ;
V_3 = F_222 ( - V_40 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_223 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_224)( void * , struct V_3 * ) ,
void * V_169 ,
T_3 V_80 )
{
struct V_3 * V_3 ;
int V_65 ;
V_108:
V_3 = F_180 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_110 ( V_80 | V_173 ) ;
if ( ! V_3 )
return F_222 ( - V_161 ) ;
V_65 = F_102 ( V_3 , V_2 , V_9 , V_80 ) ;
if ( F_35 ( V_65 ) ) {
F_60 ( V_3 ) ;
if ( V_65 == - V_12 )
goto V_108;
return F_222 ( V_65 ) ;
}
F_224:
V_65 = F_224 ( V_169 , V_3 ) ;
if ( V_65 < 0 ) {
F_60 ( V_3 ) ;
return F_222 ( V_65 ) ;
}
V_3 = F_220 ( V_3 ) ;
if ( F_221 ( V_3 ) )
return V_3 ;
goto V_59;
}
if ( F_29 ( V_3 ) )
goto V_59;
F_148 ( V_3 ) ;
if ( F_29 ( V_3 ) )
goto V_59;
F_161 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_126 ( V_3 ) ;
F_60 ( V_3 ) ;
goto V_108;
}
if ( F_29 ( V_3 ) ) {
F_126 ( V_3 ) ;
goto V_59;
}
goto F_224;
V_59:
F_165 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_225 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_224)( void * , struct V_3 * ) ,
void * V_169 )
{
return F_223 ( V_2 , V_9 , F_224 , V_169 , F_226 ( V_2 ) ) ;
}
struct V_3 * F_227 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_3 V_80 )
{
T_8 * F_224 = ( T_8 * ) V_2 -> V_34 -> V_159 ;
return F_223 ( V_2 , V_9 , F_224 , NULL , V_80 ) ;
}
inline T_6 F_228 ( struct V_163 * V_164 , struct V_132 * V_215 )
{
struct V_126 * V_126 = V_164 -> V_165 ;
struct V_135 * V_135 = V_126 -> V_134 -> V_32 ;
unsigned long V_216 = F_229 ( V_217 ) ;
T_1 V_218 ;
if ( ! F_187 ( V_215 ) )
return 0 ;
if ( V_164 -> V_167 & V_219 )
V_164 -> V_171 = F_83 ( V_135 ) ;
V_218 = V_164 -> V_171 ;
if ( V_216 != V_220 ) {
if ( V_164 -> V_171 >= V_216 ) {
F_230 ( V_221 , V_25 , 0 ) ;
return - V_222 ;
}
F_179 ( V_215 , V_216 - ( unsigned long ) V_218 ) ;
}
if ( F_35 ( V_218 + F_187 ( V_215 ) > V_223 &&
! ( V_126 -> V_224 & V_225 ) ) ) {
if ( V_218 >= V_223 )
return - V_222 ;
F_179 ( V_215 , V_223 - ( unsigned long ) V_218 ) ;
}
if ( F_35 ( V_218 >= V_135 -> V_140 -> V_141 ) )
return - V_222 ;
F_179 ( V_215 , V_135 -> V_140 -> V_141 - V_218 ) ;
return F_187 ( V_215 ) ;
}
int F_231 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_218 , unsigned V_226 , unsigned V_33 ,
struct V_3 * * V_106 , void * * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_34 ;
return V_229 -> V_230 ( V_126 , V_2 , V_218 , V_226 , V_33 ,
V_106 , V_227 ) ;
}
int F_232 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_218 , unsigned V_226 , unsigned V_231 ,
struct V_3 * V_3 , void * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_34 ;
return V_229 -> V_232 ( V_126 , V_2 , V_218 , V_226 , V_231 , V_3 , V_227 ) ;
}
T_6
F_233 ( struct V_163 * V_164 , struct V_132 * V_215 )
{
struct V_126 * V_126 = V_164 -> V_165 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_32 ;
T_1 V_218 = V_164 -> V_171 ;
T_6 V_133 ;
T_7 V_233 ;
T_2 V_42 ;
struct V_132 V_169 ;
V_233 = F_187 ( V_215 ) ;
V_42 = ( V_218 + V_233 - 1 ) >> V_55 ;
V_133 = F_86 ( V_2 , V_218 , V_218 + V_233 - 1 ) ;
if ( V_133 )
goto V_59;
if ( V_2 -> V_16 ) {
V_133 = F_234 ( V_2 ,
V_218 >> V_55 , V_42 ) ;
if ( V_133 ) {
if ( V_133 == - V_234 )
return 0 ;
goto V_59;
}
}
V_169 = * V_215 ;
V_133 = V_2 -> V_34 -> V_172 ( V_164 , & V_169 ) ;
if ( V_2 -> V_16 ) {
F_234 ( V_2 ,
V_218 >> V_55 , V_42 ) ;
}
if ( V_133 > 0 ) {
V_218 += V_133 ;
F_194 ( V_215 , V_133 ) ;
if ( V_218 > F_83 ( V_135 ) && ! F_235 ( V_135 -> V_235 ) ) {
F_236 ( V_135 , V_218 ) ;
F_237 ( V_135 ) ;
}
V_164 -> V_171 = V_218 ;
}
V_59:
return V_133 ;
}
struct V_3 * F_238 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_33 )
{
struct V_3 * V_3 ;
int V_109 = V_111 | V_115 | V_114 ;
if ( V_33 & V_236 )
V_109 |= V_116 ;
V_3 = F_163 ( V_2 , V_9 , V_109 ,
F_226 ( V_2 ) ) ;
if ( V_3 )
F_216 ( V_3 ) ;
return V_3 ;
}
T_6 F_239 ( struct V_126 * V_126 ,
struct V_132 * V_20 , T_1 V_218 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
const struct V_228 * V_34 = V_2 -> V_34 ;
long V_237 = 0 ;
T_6 V_133 = 0 ;
unsigned int V_33 = 0 ;
if ( ! F_240 ( V_20 ) )
V_33 |= V_238 ;
do {
struct V_3 * V_3 ;
unsigned long V_73 ;
unsigned long V_239 ;
T_7 V_231 ;
void * V_227 ;
V_73 = ( V_218 & ( V_144 - 1 ) ) ;
V_239 = F_241 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_240:
if ( F_35 ( F_242 ( V_20 , V_239 ) ) ) {
V_237 = - V_158 ;
break;
}
if ( F_243 ( V_25 ) ) {
V_237 = - V_241 ;
break;
}
V_237 = V_34 -> V_230 ( V_126 , V_2 , V_218 , V_239 , V_33 ,
& V_3 , & V_227 ) ;
if ( F_35 ( V_237 < 0 ) )
break;
if ( F_184 ( V_2 ) )
F_185 ( V_3 ) ;
V_231 = F_244 ( V_3 , V_20 , V_73 , V_239 ) ;
F_185 ( V_3 ) ;
V_237 = V_34 -> V_232 ( V_126 , V_2 , V_218 , V_239 , V_231 ,
V_3 , V_227 ) ;
if ( F_35 ( V_237 < 0 ) )
break;
V_231 = V_237 ;
F_80 () ;
F_194 ( V_20 , V_231 ) ;
if ( F_35 ( V_231 == 0 ) ) {
V_239 = F_241 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_240;
}
V_218 += V_231 ;
V_133 += V_231 ;
F_245 ( V_2 ) ;
} while ( F_187 ( V_20 ) );
return V_133 ? V_133 : V_237 ;
}
T_6 F_246 ( struct V_163 * V_164 , struct V_132 * V_215 )
{
struct V_126 * V_126 = V_164 -> V_165 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_32 ;
T_6 V_133 = 0 ;
T_6 V_65 ;
T_6 V_237 ;
V_25 -> V_242 = F_247 ( V_135 ) ;
V_65 = F_248 ( V_126 ) ;
if ( V_65 )
goto V_59;
V_65 = F_214 ( V_126 ) ;
if ( V_65 )
goto V_59;
if ( V_164 -> V_167 & V_168 ) {
T_1 V_218 , V_243 ;
V_133 = F_233 ( V_164 , V_215 ) ;
if ( V_133 < 0 || ! F_187 ( V_215 ) || F_195 ( V_135 ) )
goto V_59;
V_237 = F_239 ( V_126 , V_215 , V_218 = V_164 -> V_171 ) ;
if ( F_35 ( V_237 < 0 ) ) {
V_65 = V_237 ;
goto V_59;
}
V_243 = V_218 + V_237 - 1 ;
V_65 = F_86 ( V_2 , V_218 , V_243 ) ;
if ( V_65 == 0 ) {
V_164 -> V_171 = V_243 + 1 ;
V_133 += V_237 ;
F_249 ( V_2 ,
V_218 >> V_55 ,
V_243 >> V_55 ) ;
} else {
}
} else {
V_133 = F_239 ( V_126 , V_215 , V_164 -> V_171 ) ;
if ( F_203 ( V_133 > 0 ) )
V_164 -> V_171 += V_133 ;
}
V_59:
V_25 -> V_242 = NULL ;
return V_133 ? V_133 : V_65 ;
}
T_6 F_250 ( struct V_163 * V_164 , struct V_132 * V_215 )
{
struct V_126 * V_126 = V_164 -> V_165 ;
struct V_135 * V_135 = V_126 -> V_134 -> V_32 ;
T_6 V_36 ;
F_251 ( V_135 ) ;
V_36 = F_228 ( V_164 , V_215 ) ;
if ( V_36 > 0 )
V_36 = F_246 ( V_164 , V_215 ) ;
F_252 ( V_135 ) ;
if ( V_36 > 0 )
V_36 = F_253 ( V_164 , V_36 ) ;
return V_36 ;
}
int F_254 ( struct V_3 * V_3 , T_3 V_71 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_57 ( ! F_18 ( V_3 ) ) ;
if ( F_255 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_34 -> V_244 )
return V_2 -> V_34 -> V_244 ( V_3 , V_71 ) ;
return F_256 ( V_3 ) ;
}
