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
} else {
F_6 ( V_10 !=
F_7 ( 0 , V_14 ) ) ;
F_8 ( V_2 , V_3 -> V_9 , V_10 ,
true ) ;
}
}
F_9 ( & V_2 -> V_8 , V_6 , V_7 , V_3 ,
V_15 , V_2 ) ;
V_2 -> V_16 ++ ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * V_17 )
{
int V_18 , V_19 ;
V_19 = F_11 ( V_3 ) ? 1 : F_12 ( V_3 ) ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
F_13 ( F_15 ( V_3 ) , V_3 ) ;
F_13 ( V_19 != 1 && V_17 , V_3 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_5 * V_6 ;
void * * V_7 ;
F_16 ( & V_2 -> V_8 , V_3 -> V_9 + V_18 ,
& V_6 , & V_7 ) ;
F_13 ( ! V_6 && V_19 != 1 , V_3 ) ;
F_17 ( & V_2 -> V_8 , V_6 , V_7 ) ;
F_9 ( & V_2 -> V_8 , V_6 , V_7 , V_17 ,
V_15 , V_2 ) ;
}
if ( V_17 ) {
V_2 -> V_13 += V_19 ;
F_18 () ;
}
V_2 -> V_16 -= V_19 ;
}
void F_19 ( struct V_3 * V_3 , void * V_17 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_19 = F_12 ( V_3 ) ;
F_20 ( V_3 ) ;
if ( F_21 ( V_3 ) && F_22 ( V_3 ) )
F_23 ( V_3 ) ;
else
F_24 ( V_2 , V_3 ) ;
F_13 ( F_15 ( V_3 ) , V_3 ) ;
F_13 ( F_25 ( V_3 ) , V_3 ) ;
if ( ! F_26 ( V_20 ) && F_27 ( F_25 ( V_3 ) ) ) {
int V_21 ;
F_28 ( L_1 ,
V_22 -> V_23 , F_29 ( V_3 ) ) ;
F_30 ( V_3 , L_2 ) ;
F_31 () ;
F_32 ( V_24 , V_25 ) ;
V_21 = F_33 ( V_3 ) ;
if ( F_34 ( V_2 ) &&
F_35 ( V_3 ) >= V_21 + 2 ) {
F_36 ( V_3 ) ;
F_37 ( V_3 , V_21 ) ;
}
}
F_10 ( V_2 , V_3 , V_17 ) ;
V_3 -> V_2 = NULL ;
if ( ! F_11 ( V_3 ) )
F_38 ( F_39 ( V_3 ) , V_26 , - V_19 ) ;
if ( F_40 ( V_3 ) ) {
F_38 ( F_39 ( V_3 ) , V_27 , - V_19 ) ;
if ( F_41 ( V_3 ) )
F_42 ( V_3 , V_28 ) ;
} else {
F_13 ( F_41 ( V_3 ) && ! F_11 ( V_3 ) , V_3 ) ;
}
if ( F_6 ( F_43 ( V_3 ) ) )
F_44 ( V_3 , V_2 , F_45 ( V_2 -> V_29 ) ) ;
}
void F_46 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_47 ( V_3 ) ;
unsigned long V_30 ;
void (* F_48)( struct V_3 * );
F_49 ( ! F_14 ( V_3 ) ) ;
F_48 = V_2 -> V_31 -> F_48 ;
F_50 ( & V_2 -> V_11 , V_30 ) ;
F_19 ( V_3 , NULL ) ;
F_51 ( & V_2 -> V_11 , V_30 ) ;
if ( F_48 )
F_48 ( V_3 ) ;
if ( F_41 ( V_3 ) && ! F_11 ( V_3 ) ) {
F_37 ( V_3 , V_32 ) ;
F_13 ( F_35 ( V_3 ) <= 0 , V_3 ) ;
} else {
F_52 ( V_3 ) ;
}
}
int F_53 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
if ( F_54 ( V_34 , & V_2 -> V_30 ) &&
F_55 ( V_34 , & V_2 -> V_30 ) )
V_33 = - V_35 ;
if ( F_54 ( V_36 , & V_2 -> V_30 ) &&
F_55 ( V_36 , & V_2 -> V_30 ) )
V_33 = - V_37 ;
return V_33 ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 , int V_40 )
{
int V_33 ;
struct V_41 V_42 = {
. V_40 = V_40 ,
. V_43 = V_44 ,
. V_45 = V_38 ,
. V_46 = V_39 ,
} ;
if ( ! F_57 ( V_2 ) )
return 0 ;
F_58 ( & V_42 , V_2 -> V_29 ) ;
V_33 = F_59 ( V_2 , & V_42 ) ;
F_60 ( & V_42 ) ;
return V_33 ;
}
static inline int F_61 ( struct V_1 * V_2 ,
int V_40 )
{
return F_56 ( V_2 , 0 , V_47 , V_40 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_48 ) ;
}
int F_63 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 )
{
return F_56 ( V_2 , V_38 , V_39 , V_48 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_49 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_51 )
{
T_2 V_9 = V_50 >> V_52 ;
T_2 V_39 = V_51 >> V_52 ;
struct V_53 V_54 ;
int V_55 ;
int V_33 = 0 ;
if ( V_51 < V_50 )
goto V_56;
F_66 ( & V_54 , 0 ) ;
while ( ( V_9 <= V_39 ) &&
( V_55 = F_67 ( & V_54 , V_2 , & V_9 ,
V_57 ,
F_68 ( V_39 - V_9 , ( T_2 ) V_58 - 1 ) + 1 ) ) != 0 ) {
unsigned V_18 ;
for ( V_18 = 0 ; V_18 < V_55 ; V_18 ++ ) {
struct V_3 * V_3 = V_54 . V_59 [ V_18 ] ;
if ( V_3 -> V_9 > V_39 )
continue;
F_69 ( V_3 ) ;
if ( F_70 ( V_3 ) )
V_33 = - V_37 ;
}
F_71 ( & V_54 ) ;
F_72 () ;
}
V_56:
return V_33 ;
}
int F_73 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 )
{
int V_33 , V_60 ;
V_33 = F_65 ( V_2 , V_50 , V_51 ) ;
V_60 = F_53 ( V_2 ) ;
if ( ! V_33 )
V_33 = V_60 ;
return V_33 ;
}
void F_74 ( struct V_1 * V_2 )
{
T_1 V_61 = F_75 ( V_2 -> V_29 ) ;
if ( V_61 == 0 )
return;
F_65 ( V_2 , 0 , V_61 - 1 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
T_1 V_61 = F_75 ( V_2 -> V_29 ) ;
if ( V_61 == 0 )
return 0 ;
return F_73 ( V_2 , 0 , V_61 - 1 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_62 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_62 = F_62 ( V_2 ) ;
if ( V_62 != - V_37 ) {
int V_63 = F_76 ( V_2 ) ;
if ( ! V_62 )
V_62 = V_63 ;
}
} else {
V_62 = F_53 ( V_2 ) ;
}
return V_62 ;
}
int F_78 ( struct V_1 * V_2 ,
T_1 V_64 , T_1 V_65 )
{
int V_62 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_62 = F_56 ( V_2 , V_64 , V_65 ,
V_48 ) ;
if ( V_62 != - V_37 ) {
int V_63 = F_73 ( V_2 ,
V_64 , V_65 ) ;
if ( ! V_62 )
V_62 = V_63 ;
}
} else {
V_62 = F_53 ( V_2 ) ;
}
return V_62 ;
}
int F_79 ( struct V_3 * V_66 , struct V_3 * V_67 , T_3 V_68 )
{
int error ;
F_13 ( ! F_14 ( V_66 ) , V_66 ) ;
F_13 ( ! F_14 ( V_67 ) , V_67 ) ;
F_13 ( V_67 -> V_2 , V_67 ) ;
error = F_80 ( V_68 & ~ V_69 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_66 -> V_2 ;
void (* F_48)( struct V_3 * );
unsigned long V_30 ;
T_2 V_70 = V_66 -> V_9 ;
F_48 = V_2 -> V_31 -> F_48 ;
F_81 ( V_67 ) ;
V_67 -> V_2 = V_2 ;
V_67 -> V_9 = V_70 ;
F_50 ( & V_2 -> V_11 , V_30 ) ;
F_19 ( V_66 , NULL ) ;
error = F_1 ( V_2 , V_67 , NULL ) ;
F_49 ( error ) ;
if ( ! F_11 ( V_67 ) )
F_82 ( V_67 , V_26 ) ;
if ( F_40 ( V_67 ) )
F_82 ( V_67 , V_27 ) ;
F_51 ( & V_2 -> V_11 , V_30 ) ;
F_83 ( V_66 , V_67 ) ;
F_84 () ;
if ( F_48 )
F_48 ( V_66 ) ;
F_52 ( V_66 ) ;
}
return error ;
}
static int F_85 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_70 , T_3 V_68 ,
void * * V_4 )
{
int V_71 = F_11 ( V_3 ) ;
struct V_72 * V_73 ;
int error ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
F_13 ( F_40 ( V_3 ) , V_3 ) ;
if ( ! V_71 ) {
error = F_86 ( V_3 , V_22 -> V_74 ,
V_68 , & V_73 , false ) ;
if ( error )
return error ;
}
error = F_87 ( V_68 & ~ V_69 ) ;
if ( error ) {
if ( ! V_71 )
F_88 ( V_3 , V_73 , false ) ;
return error ;
}
F_81 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = V_70 ;
F_89 ( & V_2 -> V_11 ) ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
F_84 () ;
if ( F_27 ( error ) )
goto V_75;
if ( ! V_71 )
F_82 ( V_3 , V_26 ) ;
F_90 ( & V_2 -> V_11 ) ;
if ( ! V_71 )
F_91 ( V_3 , V_73 , false , false ) ;
F_92 ( V_3 ) ;
return 0 ;
V_75:
V_3 -> V_2 = NULL ;
F_90 ( & V_2 -> V_11 ) ;
if ( ! V_71 )
F_88 ( V_3 , V_73 , false ) ;
F_52 ( V_3 ) ;
return error ;
}
int F_93 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_70 , T_3 V_68 )
{
return F_85 ( V_3 , V_2 , V_70 ,
V_68 , NULL ) ;
}
int F_94 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_70 , T_3 V_68 )
{
void * V_17 = NULL ;
int V_33 ;
F_95 ( V_3 ) ;
V_33 = F_85 ( V_3 , V_2 , V_70 ,
V_68 , & V_17 ) ;
if ( F_27 ( V_33 ) )
F_96 ( V_3 ) ;
else {
if ( ! ( V_68 & V_76 ) &&
V_17 && F_97 ( V_17 ) ) {
F_98 ( V_3 ) ;
F_99 ( V_3 ) ;
} else
F_100 ( V_3 ) ;
F_101 ( V_3 ) ;
}
return V_33 ;
}
struct V_3 * F_102 ( T_3 V_77 )
{
int V_78 ;
struct V_3 * V_3 ;
if ( F_103 () ) {
unsigned int V_79 ;
do {
V_79 = F_104 () ;
V_78 = F_105 () ;
V_3 = F_106 ( V_78 , V_77 , 0 ) ;
} while ( ! V_3 && F_107 ( V_79 ) );
return V_3 ;
}
return F_108 ( V_77 , 0 ) ;
}
static T_4 * F_109 ( struct V_3 * V_3 )
{
return & V_80 [ F_110 ( V_3 , V_81 ) ] ;
}
void T_5 F_111 ( void )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_82 ; V_18 ++ )
F_112 ( & V_80 [ V_18 ] ) ;
F_113 () ;
}
static int F_114 ( T_6 * V_83 , unsigned V_84 , int V_85 , void * V_86 )
{
struct V_87 * V_88 = V_86 ;
struct V_89 * V_90
= F_115 ( V_83 , struct V_89 , V_83 ) ;
if ( V_90 -> V_3 != V_88 -> V_3 )
return 0 ;
V_88 -> V_91 = 1 ;
if ( V_90 -> V_92 != V_88 -> V_92 )
return 0 ;
if ( F_54 ( V_88 -> V_92 , & V_88 -> V_3 -> V_30 ) )
return 0 ;
return F_116 ( V_83 , V_84 , V_85 , V_88 ) ;
}
static void F_117 ( struct V_3 * V_3 , int V_92 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
struct V_87 V_88 ;
unsigned long V_30 ;
V_88 . V_3 = V_3 ;
V_88 . V_92 = V_92 ;
V_88 . V_91 = 0 ;
F_50 ( & V_93 -> V_94 , V_30 ) ;
F_118 ( V_93 , V_95 , & V_88 ) ;
if ( ! F_119 ( V_93 ) || ! V_88 . V_91 ) {
F_120 ( V_3 ) ;
}
F_51 ( & V_93 -> V_94 , V_30 ) ;
}
static void F_121 ( struct V_3 * V_3 , int V_96 )
{
if ( ! F_122 ( V_3 ) )
return;
F_117 ( V_3 , V_96 ) ;
}
static inline int F_123 ( T_4 * V_93 ,
struct V_3 * V_3 , int V_92 , int V_97 , bool V_94 )
{
struct V_89 V_90 ;
T_6 * V_83 = & V_90 . V_83 ;
int V_33 = 0 ;
F_124 ( V_83 ) ;
V_83 -> V_98 = F_114 ;
V_90 . V_3 = V_3 ;
V_90 . V_92 = V_92 ;
for (; ; ) {
F_89 ( & V_93 -> V_94 ) ;
if ( F_125 ( F_126 ( & V_83 -> V_99 ) ) ) {
if ( V_94 )
F_127 ( V_93 , V_83 ) ;
else
F_128 ( V_93 , V_83 ) ;
F_129 ( V_3 ) ;
}
F_130 ( V_97 ) ;
F_90 ( & V_93 -> V_94 ) ;
if ( F_125 ( F_54 ( V_92 , & V_3 -> V_30 ) ) ) {
F_131 () ;
if ( F_27 ( F_132 ( V_97 , V_22 ) ) ) {
V_33 = - V_100 ;
break;
}
}
if ( V_94 ) {
if ( ! F_133 ( V_92 , & V_3 -> V_30 ) )
break;
} else {
if ( ! F_54 ( V_92 , & V_3 -> V_30 ) )
break;
}
}
F_134 ( V_93 , V_83 ) ;
return V_33 ;
}
void F_135 ( struct V_3 * V_3 , int V_92 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
F_123 ( V_93 , V_3 , V_92 , V_101 , false ) ;
}
int F_136 ( struct V_3 * V_3 , int V_92 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
return F_123 ( V_93 , V_3 , V_92 , V_102 , false ) ;
}
void F_137 ( struct V_3 * V_3 , T_6 * V_103 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
unsigned long V_30 ;
F_50 ( & V_93 -> V_94 , V_30 ) ;
F_128 ( V_93 , V_103 ) ;
F_129 ( V_3 ) ;
F_51 ( & V_93 -> V_94 , V_30 ) ;
}
static inline bool F_138 ( long V_19 , volatile void * V_104 )
{
F_139 ( V_19 , V_104 ) ;
return F_54 ( V_105 , V_104 ) ;
}
void F_140 ( struct V_3 * V_3 )
{
F_141 ( V_105 != 7 ) ;
V_3 = F_142 ( V_3 ) ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
if ( F_138 ( V_106 , & V_3 -> V_30 ) )
F_117 ( V_3 , V_106 ) ;
}
void F_143 ( struct V_3 * V_3 )
{
if ( F_144 ( V_3 ) ) {
F_145 ( V_3 ) ;
F_146 ( V_3 ) ;
}
if ( ! F_147 ( V_3 ) )
F_148 () ;
F_149 () ;
F_121 ( V_3 , V_107 ) ;
}
void F_150 ( struct V_3 * V_3 , bool V_108 , int V_62 )
{
if ( ! V_108 ) {
if ( ! V_62 ) {
F_151 ( V_3 ) ;
} else {
F_152 ( V_3 ) ;
F_153 ( V_3 ) ;
}
F_140 ( V_3 ) ;
} else {
if ( V_62 ) {
struct V_1 * V_2 ;
F_153 ( V_3 ) ;
V_2 = F_47 ( V_3 ) ;
if ( V_2 )
F_154 ( V_2 , V_62 ) ;
}
F_143 ( V_3 ) ;
}
}
void F_155 ( struct V_3 * V_109 )
{
struct V_3 * V_3 = F_142 ( V_109 ) ;
T_4 * V_93 = F_109 ( V_3 ) ;
F_123 ( V_93 , V_3 , V_106 , V_101 , true ) ;
}
int F_156 ( struct V_3 * V_109 )
{
struct V_3 * V_3 = F_142 ( V_109 ) ;
T_4 * V_93 = F_109 ( V_3 ) ;
return F_123 ( V_93 , V_3 , V_106 , V_102 , true ) ;
}
int F_157 ( struct V_3 * V_3 , struct V_110 * V_74 ,
unsigned int V_30 )
{
if ( V_30 & V_111 ) {
if ( V_30 & V_112 )
return 0 ;
F_158 ( & V_74 -> V_113 ) ;
if ( V_30 & V_114 )
F_159 ( V_3 ) ;
else
F_160 ( V_3 ) ;
return 0 ;
} else {
if ( V_30 & V_114 ) {
int V_33 ;
V_33 = F_156 ( V_3 ) ;
if ( V_33 ) {
F_158 ( & V_74 -> V_113 ) ;
return 0 ;
}
} else
F_155 ( V_3 ) ;
return 1 ;
}
}
T_2 F_161 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_115 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_115 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_162 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 ++ ;
if ( V_9 == 0 )
break;
}
return V_9 ;
}
T_2 F_163 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_115 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_115 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_162 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_116 )
break;
}
return V_9 ;
}
struct V_3 * F_164 ( struct V_1 * V_2 , T_2 V_70 )
{
void * * V_117 ;
struct V_3 * V_118 , * V_3 ;
F_165 () ;
V_119:
V_3 = NULL ;
V_117 = F_166 ( & V_2 -> V_8 , V_70 ) ;
if ( V_117 ) {
V_3 = F_167 ( V_117 ) ;
if ( F_27 ( ! V_3 ) )
goto V_56;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) )
goto V_119;
goto V_56;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_117 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
}
V_56:
F_171 () ;
return V_3 ;
}
struct V_3 * F_172 ( struct V_1 * V_2 , T_2 V_70 )
{
struct V_3 * V_3 ;
V_119:
V_3 = F_164 ( V_2 , V_70 ) ;
if ( V_3 && ! F_168 ( V_3 ) ) {
F_173 ( V_3 ) ;
if ( F_27 ( F_47 ( V_3 ) != V_2 ) ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_119;
}
F_13 ( F_174 ( V_3 ) != V_70 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_175 ( struct V_1 * V_2 , T_2 V_70 ,
int V_120 , T_3 V_68 )
{
struct V_3 * V_3 ;
V_119:
V_3 = F_164 ( V_2 , V_70 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_121;
if ( V_120 & V_122 ) {
if ( V_120 & V_123 ) {
if ( ! F_176 ( V_3 ) ) {
F_52 ( V_3 ) ;
return NULL ;
}
} else {
F_173 ( V_3 ) ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_119;
}
F_13 ( V_3 -> V_9 != V_70 , V_3 ) ;
}
if ( V_3 && ( V_120 & V_124 ) )
F_177 ( V_3 ) ;
V_121:
if ( ! V_3 && ( V_120 & V_125 ) ) {
int V_62 ;
if ( ( V_120 & V_126 ) && F_178 ( V_2 ) )
V_68 |= V_76 ;
if ( V_120 & V_127 )
V_68 &= ~ V_128 ;
V_3 = F_102 ( V_68 ) ;
if ( ! V_3 )
return NULL ;
if ( F_6 ( ! ( V_120 & V_122 ) ) )
V_120 |= V_122 ;
if ( V_120 & V_124 )
F_179 ( V_3 ) ;
V_62 = F_94 ( V_3 , V_2 , V_70 ,
V_68 & V_129 ) ;
if ( F_27 ( V_62 ) ) {
F_52 ( V_3 ) ;
V_3 = NULL ;
if ( V_62 == - V_12 )
goto V_119;
}
}
return V_3 ;
}
unsigned F_180 ( struct V_1 * V_2 ,
T_2 V_38 , unsigned int V_130 ,
struct V_3 * * V_131 , T_2 * V_132 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_133 V_134 ;
if ( ! V_130 )
return 0 ;
F_165 () ;
F_181 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_118 , * V_3 ;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
goto V_135;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
V_135:
V_132 [ V_33 ] = V_134 . V_9 ;
V_131 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_130 )
break;
}
F_171 () ;
return V_33 ;
}
unsigned F_183 ( struct V_1 * V_2 , T_2 V_38 ,
unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_133 V_134 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_165 () ;
F_181 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_118 , * V_3 ;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
continue;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_171 () ;
return V_33 ;
}
unsigned F_184 ( struct V_1 * V_2 , T_2 V_9 ,
unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_133 V_134 ;
void * * V_7 ;
unsigned int V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_165 () ;
F_185 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_118 , * V_3 ;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
break;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
break;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( V_3 -> V_2 == NULL || F_174 ( V_3 ) != V_134 . V_9 ) {
F_52 ( V_3 ) ;
break;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_171 () ;
return V_33 ;
}
unsigned F_186 ( struct V_1 * V_2 , T_2 * V_9 ,
int V_136 , unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_133 V_134 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_165 () ;
F_187 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_118 , * V_3 ;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
continue;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_171 () ;
if ( V_33 )
* V_9 = V_59 [ V_33 - 1 ] -> V_9 + 1 ;
return V_33 ;
}
unsigned F_188 ( struct V_1 * V_2 , T_2 V_38 ,
int V_136 , unsigned int V_130 ,
struct V_3 * * V_131 , T_2 * V_132 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_133 V_134 ;
if ( ! V_130 )
return 0 ;
F_165 () ;
F_187 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_118 , * V_3 ;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
goto V_135;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
V_135:
V_132 [ V_33 ] = V_134 . V_9 ;
V_131 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_130 )
break;
}
F_171 () ;
return V_33 ;
}
static void F_189 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
V_140 -> V_141 /= 4 ;
}
static T_7 F_190 ( struct V_137 * V_138 , T_1 * V_142 ,
struct V_143 * V_134 , T_7 V_144 )
{
struct V_1 * V_2 = V_138 -> V_145 ;
struct V_146 * V_146 = V_2 -> V_29 ;
struct V_139 * V_140 = & V_138 -> V_147 ;
T_2 V_9 ;
T_2 V_148 ;
T_2 V_149 ;
unsigned long V_70 ;
unsigned int V_150 ;
int error = 0 ;
if ( F_27 ( * V_142 >= V_146 -> V_151 -> V_152 ) )
return 0 ;
F_191 ( V_134 , V_146 -> V_151 -> V_152 ) ;
V_9 = * V_142 >> V_52 ;
V_149 = V_140 -> V_153 >> V_52 ;
V_150 = V_140 -> V_153 & ( V_154 - 1 ) ;
V_148 = ( * V_142 + V_134 -> V_155 + V_154 - 1 ) >> V_52 ;
V_70 = * V_142 & ~ V_156 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_157 ;
T_1 V_158 ;
unsigned long V_19 , V_33 ;
F_72 () ;
V_159:
if ( F_192 ( V_22 ) ) {
error = - V_100 ;
goto V_56;
}
V_3 = F_193 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
F_194 ( V_2 ,
V_140 , V_138 ,
V_9 , V_148 - V_9 ) ;
V_3 = F_193 ( V_2 , V_9 ) ;
if ( F_27 ( V_3 == NULL ) )
goto V_160;
}
if ( F_195 ( V_3 ) ) {
F_196 ( V_2 ,
V_140 , V_138 , V_3 ,
V_9 , V_148 - V_9 ) ;
}
if ( ! F_21 ( V_3 ) ) {
error = F_159 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_161;
if ( F_21 ( V_3 ) )
goto V_162;
if ( V_146 -> V_163 == V_52 ||
! V_2 -> V_31 -> V_164 )
goto V_165;
if ( F_27 ( V_134 -> type & V_166 ) )
goto V_165;
if ( ! F_176 ( V_3 ) )
goto V_165;
if ( ! V_3 -> V_2 )
goto V_167;
if ( ! V_2 -> V_31 -> V_164 ( V_3 ,
V_70 , V_134 -> V_155 ) )
goto V_167;
F_140 ( V_3 ) ;
}
V_162:
V_158 = F_75 ( V_146 ) ;
V_157 = ( V_158 - 1 ) >> V_52 ;
if ( F_27 ( ! V_158 || V_9 > V_157 ) ) {
F_52 ( V_3 ) ;
goto V_56;
}
V_19 = V_154 ;
if ( V_9 == V_157 ) {
V_19 = ( ( V_158 - 1 ) & ~ V_156 ) + 1 ;
if ( V_19 <= V_70 ) {
F_52 ( V_3 ) ;
goto V_56;
}
}
V_19 = V_19 - V_70 ;
if ( F_197 ( V_2 ) )
F_198 ( V_3 ) ;
if ( V_149 != V_9 || V_70 != V_150 )
F_177 ( V_3 ) ;
V_149 = V_9 ;
V_33 = F_199 ( V_3 , V_70 , V_19 , V_134 ) ;
V_70 += V_33 ;
V_9 += V_70 >> V_52 ;
V_70 &= ~ V_156 ;
V_150 = V_70 ;
F_52 ( V_3 ) ;
V_144 += V_33 ;
if ( ! F_200 ( V_134 ) )
goto V_56;
if ( V_33 < V_19 ) {
error = - V_168 ;
goto V_56;
}
continue;
V_165:
error = F_201 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_161;
V_167:
if ( ! V_3 -> V_2 ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
continue;
}
if ( F_21 ( V_3 ) ) {
F_140 ( V_3 ) ;
goto V_162;
}
V_169:
F_202 ( V_3 ) ;
error = V_2 -> V_31 -> V_169 ( V_138 , V_3 ) ;
if ( F_27 ( error ) ) {
if ( error == V_170 ) {
F_52 ( V_3 ) ;
error = 0 ;
goto V_159;
}
goto V_161;
}
if ( ! F_21 ( V_3 ) ) {
error = F_201 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_161;
if ( ! F_21 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_159;
}
F_140 ( V_3 ) ;
F_189 ( V_138 , V_140 ) ;
error = - V_37 ;
goto V_161;
}
F_140 ( V_3 ) ;
}
goto V_162;
V_161:
F_52 ( V_3 ) ;
goto V_56;
V_160:
V_3 = F_203 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_171 ;
goto V_56;
}
error = F_94 ( V_3 , V_2 , V_9 ,
F_204 ( V_2 , V_172 ) ) ;
if ( error ) {
F_52 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_159;
}
goto V_56;
}
goto V_169;
}
V_56:
V_140 -> V_153 = V_149 ;
V_140 -> V_153 <<= V_52 ;
V_140 -> V_153 |= V_150 ;
* V_142 = ( ( T_1 ) V_9 << V_52 ) + V_70 ;
F_205 ( V_138 ) ;
return V_144 ? V_144 : error ;
}
T_7
F_206 ( struct V_173 * V_174 , struct V_143 * V_134 )
{
struct V_137 * V_137 = V_174 -> V_175 ;
T_7 V_176 = 0 ;
T_8 V_155 = F_200 ( V_134 ) ;
if ( ! V_155 )
goto V_56;
if ( V_174 -> V_177 & V_178 ) {
struct V_1 * V_2 = V_137 -> V_145 ;
struct V_146 * V_146 = V_2 -> V_29 ;
struct V_143 V_179 = * V_134 ;
T_1 V_180 ;
V_180 = F_75 ( V_146 ) ;
V_176 = F_78 ( V_2 , V_174 -> V_181 ,
V_174 -> V_181 + V_155 - 1 ) ;
if ( V_176 < 0 )
goto V_56;
F_205 ( V_137 ) ;
V_176 = V_2 -> V_31 -> V_182 ( V_174 , & V_179 ) ;
if ( V_176 >= 0 ) {
V_174 -> V_181 += V_176 ;
F_207 ( V_134 , V_176 ) ;
}
if ( V_176 < 0 || ! F_200 ( V_134 ) || V_174 -> V_181 >= V_180 ||
F_208 ( V_146 ) )
goto V_56;
}
V_176 = F_190 ( V_137 , & V_174 -> V_181 , V_134 , V_176 ) ;
V_56:
return V_176 ;
}
static int F_209 ( struct V_137 * V_137 , T_2 V_70 , T_3 V_68 )
{
struct V_1 * V_2 = V_137 -> V_145 ;
struct V_3 * V_3 ;
int V_33 ;
do {
V_3 = F_102 ( V_68 | V_183 ) ;
if ( ! V_3 )
return - V_171 ;
V_33 = F_94 ( V_3 , V_2 , V_70 , V_68 & V_172 ) ;
if ( V_33 == 0 )
V_33 = V_2 -> V_31 -> V_169 ( V_137 , V_3 ) ;
else if ( V_33 == - V_12 )
V_33 = 0 ;
F_52 ( V_3 ) ;
} while ( V_33 == V_170 );
return V_33 ;
}
static void F_210 ( struct V_184 * V_185 ,
struct V_139 * V_140 ,
struct V_137 * V_137 ,
T_2 V_70 )
{
struct V_1 * V_2 = V_137 -> V_145 ;
if ( V_185 -> V_186 & V_187 )
return;
if ( ! V_140 -> V_141 )
return;
if ( V_185 -> V_186 & V_188 ) {
F_194 ( V_2 , V_140 , V_137 , V_70 ,
V_140 -> V_141 ) ;
return;
}
if ( V_140 -> V_189 < V_190 * 10 )
V_140 -> V_189 ++ ;
if ( V_140 -> V_189 > V_190 )
return;
V_140 -> V_38 = F_211 ( long , 0 , V_70 - V_140 -> V_141 / 2 ) ;
V_140 -> V_180 = V_140 -> V_141 ;
V_140 -> V_191 = V_140 -> V_141 / 4 ;
F_212 ( V_140 , V_2 , V_137 ) ;
}
static void F_213 ( struct V_184 * V_185 ,
struct V_139 * V_140 ,
struct V_137 * V_137 ,
struct V_3 * V_3 ,
T_2 V_70 )
{
struct V_1 * V_2 = V_137 -> V_145 ;
if ( V_185 -> V_186 & V_187 )
return;
if ( V_140 -> V_189 > 0 )
V_140 -> V_189 -- ;
if ( F_195 ( V_3 ) )
F_196 ( V_2 , V_140 , V_137 ,
V_3 , V_70 , V_140 -> V_141 ) ;
}
int F_214 ( struct V_192 * V_193 )
{
int error ;
struct V_137 * V_137 = V_193 -> V_185 -> V_194 ;
struct V_1 * V_2 = V_137 -> V_145 ;
struct V_139 * V_140 = & V_137 -> V_147 ;
struct V_146 * V_146 = V_2 -> V_29 ;
T_2 V_70 = V_193 -> V_195 ;
struct V_3 * V_3 ;
T_1 V_180 ;
int V_33 = 0 ;
V_180 = F_215 ( F_75 ( V_146 ) , V_154 ) ;
if ( V_70 >= V_180 >> V_52 )
return V_196 ;
V_3 = F_193 ( V_2 , V_70 ) ;
if ( F_125 ( V_3 ) && ! ( V_193 -> V_30 & V_197 ) ) {
F_213 ( V_193 -> V_185 , V_140 , V_137 , V_3 , V_70 ) ;
} else if ( ! V_3 ) {
F_210 ( V_193 -> V_185 , V_140 , V_137 , V_70 ) ;
F_216 ( V_198 ) ;
F_217 ( V_193 -> V_185 -> V_199 , V_198 ) ;
V_33 = V_200 ;
V_201:
V_3 = F_193 ( V_2 , V_70 ) ;
if ( ! V_3 )
goto V_160;
}
if ( ! F_218 ( V_3 , V_193 -> V_185 -> V_199 , V_193 -> V_30 ) ) {
F_52 ( V_3 ) ;
return V_33 | V_202 ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_201;
}
F_13 ( V_3 -> V_9 != V_70 , V_3 ) ;
if ( F_27 ( ! F_21 ( V_3 ) ) )
goto V_203;
V_180 = F_215 ( F_75 ( V_146 ) , V_154 ) ;
if ( F_27 ( V_70 >= V_180 >> V_52 ) ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
return V_196 ;
}
V_193 -> V_3 = V_3 ;
return V_33 | V_204 ;
V_160:
error = F_209 ( V_137 , V_70 , V_193 -> V_68 ) ;
if ( error >= 0 )
goto V_201;
if ( error == - V_171 )
return V_205 ;
return V_196 ;
V_203:
F_202 ( V_3 ) ;
error = V_2 -> V_31 -> V_169 ( V_137 , V_3 ) ;
if ( ! error ) {
F_160 ( V_3 ) ;
if ( ! F_21 ( V_3 ) )
error = - V_37 ;
}
F_52 ( V_3 ) ;
if ( ! error || error == V_170 )
goto V_201;
F_189 ( V_137 , V_140 ) ;
return V_196 ;
}
void F_219 ( struct V_192 * V_193 ,
T_2 V_206 , T_2 V_207 )
{
struct V_133 V_134 ;
void * * V_7 ;
struct V_137 * V_137 = V_193 -> V_185 -> V_194 ;
struct V_1 * V_2 = V_137 -> V_145 ;
T_2 V_208 = V_206 ;
T_1 V_180 ;
struct V_3 * V_118 , * V_3 ;
F_165 () ;
F_181 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_134 . V_9 > V_207 )
break;
V_119:
V_3 = F_167 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
goto V_209;
if ( F_168 ( V_3 ) ) {
if ( F_169 ( V_3 ) ) {
V_7 = F_182 ( & V_134 ) ;
continue;
}
goto V_209;
}
V_118 = F_142 ( V_3 ) ;
if ( ! F_170 ( V_118 ) )
goto V_119;
if ( F_142 ( V_3 ) != V_118 ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_118 ) ;
goto V_119;
}
if ( ! F_21 ( V_3 ) ||
F_195 ( V_3 ) ||
F_220 ( V_3 ) )
goto V_210;
if ( ! F_176 ( V_3 ) )
goto V_210;
if ( V_3 -> V_2 != V_2 || ! F_21 ( V_3 ) )
goto V_211;
V_180 = F_215 ( F_75 ( V_2 -> V_29 ) , V_154 ) ;
if ( V_3 -> V_9 >= V_180 >> V_52 )
goto V_211;
if ( V_137 -> V_147 . V_189 > 0 )
V_137 -> V_147 . V_189 -- ;
V_193 -> V_212 += ( V_134 . V_9 - V_208 ) << V_52 ;
if ( V_193 -> V_213 )
V_193 -> V_213 += V_134 . V_9 - V_208 ;
V_208 = V_134 . V_9 ;
if ( F_221 ( V_193 , NULL , V_3 ) )
goto V_211;
F_140 ( V_3 ) ;
goto V_209;
V_211:
F_140 ( V_3 ) ;
V_210:
F_52 ( V_3 ) ;
V_209:
if ( F_222 ( * V_193 -> V_214 ) )
break;
if ( V_134 . V_9 == V_207 )
break;
}
F_171 () ;
}
int F_223 ( struct V_192 * V_193 )
{
struct V_3 * V_3 = V_193 -> V_3 ;
struct V_146 * V_146 = F_224 ( V_193 -> V_185 -> V_194 ) ;
int V_33 = V_204 ;
F_225 ( V_146 -> V_151 ) ;
F_226 ( V_193 -> V_185 -> V_194 ) ;
F_173 ( V_3 ) ;
if ( V_3 -> V_2 != V_146 -> V_215 ) {
F_140 ( V_3 ) ;
V_33 = V_216 ;
goto V_56;
}
F_227 ( V_3 ) ;
F_228 ( V_3 ) ;
V_56:
F_229 ( V_146 -> V_151 ) ;
return V_33 ;
}
int F_230 ( struct V_137 * V_137 , struct V_184 * V_185 )
{
struct V_1 * V_2 = V_137 -> V_145 ;
if ( ! V_2 -> V_31 -> V_169 )
return - V_217 ;
F_205 ( V_137 ) ;
V_185 -> V_218 = & V_219 ;
return 0 ;
}
int F_231 ( struct V_137 * V_137 , struct V_184 * V_185 )
{
if ( ( V_185 -> V_186 & V_220 ) && ( V_185 -> V_186 & V_221 ) )
return - V_222 ;
return F_230 ( V_137 , V_185 ) ;
}
int F_230 ( struct V_137 * V_137 , struct V_184 * V_185 )
{
return - V_223 ;
}
int F_231 ( struct V_137 * V_137 , struct V_184 * V_185 )
{
return - V_223 ;
}
static struct V_3 * F_232 ( struct V_3 * V_3 )
{
if ( ! F_233 ( V_3 ) ) {
F_160 ( V_3 ) ;
if ( ! F_21 ( V_3 ) ) {
F_52 ( V_3 ) ;
V_3 = F_234 ( - V_37 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_235 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_236)( void * , struct V_3 * ) ,
void * V_179 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_62 ;
V_119:
V_3 = F_193 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_102 ( V_77 | V_183 ) ;
if ( ! V_3 )
return F_234 ( - V_171 ) ;
V_62 = F_94 ( V_3 , V_2 , V_9 , V_77 ) ;
if ( F_27 ( V_62 ) ) {
F_52 ( V_3 ) ;
if ( V_62 == - V_12 )
goto V_119;
return F_234 ( V_62 ) ;
}
F_236:
V_62 = F_236 ( V_179 , V_3 ) ;
if ( V_62 < 0 ) {
F_52 ( V_3 ) ;
return F_234 ( V_62 ) ;
}
V_3 = F_232 ( V_3 ) ;
if ( F_233 ( V_3 ) )
return V_3 ;
goto V_56;
}
if ( F_21 ( V_3 ) )
goto V_56;
F_160 ( V_3 ) ;
if ( F_21 ( V_3 ) )
goto V_56;
F_173 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_140 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_119;
}
if ( F_21 ( V_3 ) ) {
F_140 ( V_3 ) ;
goto V_56;
}
goto F_236;
V_56:
F_177 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_237 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_236)( void * , struct V_3 * ) ,
void * V_179 )
{
return F_235 ( V_2 , V_9 , F_236 , V_179 , F_238 ( V_2 ) ) ;
}
struct V_3 * F_239 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_3 V_77 )
{
T_9 * F_236 = ( T_9 * ) V_2 -> V_31 -> V_169 ;
return F_235 ( V_2 , V_9 , F_236 , NULL , V_77 ) ;
}
inline T_7 F_240 ( struct V_173 * V_174 , struct V_143 * V_224 )
{
struct V_137 * V_137 = V_174 -> V_175 ;
struct V_146 * V_146 = V_137 -> V_145 -> V_29 ;
unsigned long V_225 = F_241 ( V_226 ) ;
T_1 V_227 ;
if ( ! F_200 ( V_224 ) )
return 0 ;
if ( V_174 -> V_177 & V_228 )
V_174 -> V_181 = F_75 ( V_146 ) ;
V_227 = V_174 -> V_181 ;
if ( V_225 != V_229 ) {
if ( V_174 -> V_181 >= V_225 ) {
F_242 ( V_230 , V_22 , 0 ) ;
return - V_231 ;
}
F_191 ( V_224 , V_225 - ( unsigned long ) V_227 ) ;
}
if ( F_27 ( V_227 + F_200 ( V_224 ) > V_232 &&
! ( V_137 -> V_233 & V_234 ) ) ) {
if ( V_227 >= V_232 )
return - V_231 ;
F_191 ( V_224 , V_232 - ( unsigned long ) V_227 ) ;
}
if ( F_27 ( V_227 >= V_146 -> V_151 -> V_152 ) )
return - V_231 ;
F_191 ( V_224 , V_146 -> V_151 -> V_152 - V_227 ) ;
return F_200 ( V_224 ) ;
}
int F_243 ( struct V_137 * V_137 , struct V_1 * V_2 ,
T_1 V_227 , unsigned V_235 , unsigned V_30 ,
struct V_3 * * V_117 , void * * V_236 )
{
const struct V_237 * V_238 = V_2 -> V_31 ;
return V_238 -> V_239 ( V_137 , V_2 , V_227 , V_235 , V_30 ,
V_117 , V_236 ) ;
}
int F_244 ( struct V_137 * V_137 , struct V_1 * V_2 ,
T_1 V_227 , unsigned V_235 , unsigned V_240 ,
struct V_3 * V_3 , void * V_236 )
{
const struct V_237 * V_238 = V_2 -> V_31 ;
return V_238 -> V_241 ( V_137 , V_2 , V_227 , V_235 , V_240 , V_3 , V_236 ) ;
}
T_7
F_245 ( struct V_173 * V_174 , struct V_143 * V_224 )
{
struct V_137 * V_137 = V_174 -> V_175 ;
struct V_1 * V_2 = V_137 -> V_145 ;
struct V_146 * V_146 = V_2 -> V_29 ;
T_1 V_227 = V_174 -> V_181 ;
T_7 V_144 ;
T_8 V_242 ;
T_2 V_39 ;
struct V_143 V_179 ;
V_242 = F_200 ( V_224 ) ;
V_39 = ( V_227 + V_242 - 1 ) >> V_52 ;
V_144 = F_78 ( V_2 , V_227 , V_227 + V_242 - 1 ) ;
if ( V_144 )
goto V_56;
if ( V_2 -> V_16 ) {
V_144 = F_246 ( V_2 ,
V_227 >> V_52 , V_39 ) ;
if ( V_144 ) {
if ( V_144 == - V_243 )
return 0 ;
goto V_56;
}
}
V_179 = * V_224 ;
V_144 = V_2 -> V_31 -> V_182 ( V_174 , & V_179 ) ;
if ( V_2 -> V_16 ) {
F_246 ( V_2 ,
V_227 >> V_52 , V_39 ) ;
}
if ( V_144 > 0 ) {
V_227 += V_144 ;
F_207 ( V_224 , V_144 ) ;
if ( V_227 > F_75 ( V_146 ) && ! F_247 ( V_146 -> V_244 ) ) {
F_248 ( V_146 , V_227 ) ;
F_249 ( V_146 ) ;
}
V_174 -> V_181 = V_227 ;
}
V_56:
return V_144 ;
}
struct V_3 * F_250 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_30 )
{
struct V_3 * V_3 ;
int V_120 = V_122 | V_126 | V_125 ;
if ( V_30 & V_245 )
V_120 |= V_127 ;
V_3 = F_175 ( V_2 , V_9 , V_120 ,
F_238 ( V_2 ) ) ;
if ( V_3 )
F_228 ( V_3 ) ;
return V_3 ;
}
T_7 F_251 ( struct V_137 * V_137 ,
struct V_143 * V_18 , T_1 V_227 )
{
struct V_1 * V_2 = V_137 -> V_145 ;
const struct V_237 * V_31 = V_2 -> V_31 ;
long V_246 = 0 ;
T_7 V_144 = 0 ;
unsigned int V_30 = 0 ;
if ( ! F_252 ( V_18 ) )
V_30 |= V_247 ;
do {
struct V_3 * V_3 ;
unsigned long V_70 ;
unsigned long V_248 ;
T_8 V_240 ;
void * V_236 ;
V_70 = ( V_227 & ( V_154 - 1 ) ) ;
V_248 = F_253 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_249:
if ( F_27 ( F_254 ( V_18 , V_248 ) ) ) {
V_246 = - V_168 ;
break;
}
if ( F_192 ( V_22 ) ) {
V_246 = - V_100 ;
break;
}
V_246 = V_31 -> V_239 ( V_137 , V_2 , V_227 , V_248 , V_30 ,
& V_3 , & V_236 ) ;
if ( F_27 ( V_246 < 0 ) )
break;
if ( F_197 ( V_2 ) )
F_198 ( V_3 ) ;
V_240 = F_255 ( V_3 , V_18 , V_70 , V_248 ) ;
F_198 ( V_3 ) ;
V_246 = V_31 -> V_241 ( V_137 , V_2 , V_227 , V_248 , V_240 ,
V_3 , V_236 ) ;
if ( F_27 ( V_246 < 0 ) )
break;
V_240 = V_246 ;
F_72 () ;
F_207 ( V_18 , V_240 ) ;
if ( F_27 ( V_240 == 0 ) ) {
V_248 = F_253 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_249;
}
V_227 += V_240 ;
V_144 += V_240 ;
F_256 ( V_2 ) ;
} while ( F_200 ( V_18 ) );
return V_144 ? V_144 : V_246 ;
}
T_7 F_257 ( struct V_173 * V_174 , struct V_143 * V_224 )
{
struct V_137 * V_137 = V_174 -> V_175 ;
struct V_1 * V_2 = V_137 -> V_145 ;
struct V_146 * V_146 = V_2 -> V_29 ;
T_7 V_144 = 0 ;
T_7 V_62 ;
T_7 V_246 ;
V_22 -> V_250 = F_258 ( V_146 ) ;
V_62 = F_259 ( V_137 ) ;
if ( V_62 )
goto V_56;
V_62 = F_226 ( V_137 ) ;
if ( V_62 )
goto V_56;
if ( V_174 -> V_177 & V_178 ) {
T_1 V_227 , V_251 ;
V_144 = F_245 ( V_174 , V_224 ) ;
if ( V_144 < 0 || ! F_200 ( V_224 ) || F_208 ( V_146 ) )
goto V_56;
V_246 = F_251 ( V_137 , V_224 , V_227 = V_174 -> V_181 ) ;
if ( F_27 ( V_246 < 0 ) ) {
V_62 = V_246 ;
goto V_56;
}
V_251 = V_227 + V_246 - 1 ;
V_62 = F_78 ( V_2 , V_227 , V_251 ) ;
if ( V_62 == 0 ) {
V_174 -> V_181 = V_251 + 1 ;
V_144 += V_246 ;
F_260 ( V_2 ,
V_227 >> V_52 ,
V_251 >> V_52 ) ;
} else {
}
} else {
V_144 = F_251 ( V_137 , V_224 , V_174 -> V_181 ) ;
if ( F_125 ( V_144 > 0 ) )
V_174 -> V_181 += V_144 ;
}
V_56:
V_22 -> V_250 = NULL ;
return V_144 ? V_144 : V_62 ;
}
T_7 F_261 ( struct V_173 * V_174 , struct V_143 * V_224 )
{
struct V_137 * V_137 = V_174 -> V_175 ;
struct V_146 * V_146 = V_137 -> V_145 -> V_29 ;
T_7 V_33 ;
F_262 ( V_146 ) ;
V_33 = F_240 ( V_174 , V_224 ) ;
if ( V_33 > 0 )
V_33 = F_257 ( V_174 , V_224 ) ;
F_263 ( V_146 ) ;
if ( V_33 > 0 )
V_33 = F_264 ( V_174 , V_33 ) ;
return V_33 ;
}
int F_265 ( struct V_3 * V_3 , T_3 V_68 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_49 ( ! F_14 ( V_3 ) ) ;
if ( F_266 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_31 -> V_252 )
return V_2 -> V_31 -> V_252 ( V_3 , V_68 ) ;
return F_267 ( V_3 ) ;
}
