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
void F_117 ( struct V_3 * V_3 , int V_92 )
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
static inline int F_121 ( T_4 * V_93 ,
struct V_3 * V_3 , int V_92 , int V_96 , bool V_94 )
{
struct V_89 V_90 ;
T_6 * V_83 = & V_90 . V_83 ;
int V_33 = 0 ;
F_122 ( V_83 ) ;
V_83 -> V_97 = F_114 ;
V_90 . V_3 = V_3 ;
V_90 . V_92 = V_92 ;
for (; ; ) {
F_89 ( & V_93 -> V_94 ) ;
if ( F_123 ( F_124 ( & V_83 -> V_98 ) ) ) {
if ( V_94 )
F_125 ( V_93 , V_83 ) ;
else
F_126 ( V_93 , V_83 ) ;
F_127 ( V_3 ) ;
}
F_128 ( V_96 ) ;
F_90 ( & V_93 -> V_94 ) ;
if ( F_123 ( F_54 ( V_92 , & V_3 -> V_30 ) ) ) {
F_129 () ;
if ( F_27 ( F_130 ( V_96 , V_22 ) ) ) {
V_33 = - V_99 ;
break;
}
}
if ( V_94 ) {
if ( ! F_131 ( V_92 , & V_3 -> V_30 ) )
break;
} else {
if ( ! F_54 ( V_92 , & V_3 -> V_30 ) )
break;
}
}
F_132 ( V_93 , V_83 ) ;
return V_33 ;
}
void F_133 ( struct V_3 * V_3 , int V_92 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
F_121 ( V_93 , V_3 , V_92 , V_100 , false ) ;
}
int F_134 ( struct V_3 * V_3 , int V_92 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
return F_121 ( V_93 , V_3 , V_92 , V_101 , false ) ;
}
void F_135 ( struct V_3 * V_3 , T_6 * V_102 )
{
T_4 * V_93 = F_109 ( V_3 ) ;
unsigned long V_30 ;
F_50 ( & V_93 -> V_94 , V_30 ) ;
F_126 ( V_93 , V_102 ) ;
F_127 ( V_3 ) ;
F_51 ( & V_93 -> V_94 , V_30 ) ;
}
static inline bool F_136 ( long V_19 , volatile void * V_103 )
{
F_137 ( V_19 , V_103 ) ;
return F_54 ( V_104 , V_103 ) ;
}
void F_138 ( struct V_3 * V_3 )
{
F_139 ( V_104 != 7 ) ;
V_3 = F_140 ( V_3 ) ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
if ( F_136 ( V_105 , & V_3 -> V_30 ) )
F_117 ( V_3 , V_105 ) ;
}
void F_141 ( struct V_3 * V_3 )
{
if ( F_142 ( V_3 ) ) {
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
}
if ( ! F_145 ( V_3 ) )
F_146 () ;
F_147 () ;
F_148 ( V_3 , V_106 ) ;
}
void F_149 ( struct V_3 * V_3 , bool V_107 , int V_62 )
{
if ( ! V_107 ) {
if ( ! V_62 ) {
F_150 ( V_3 ) ;
} else {
F_151 ( V_3 ) ;
F_152 ( V_3 ) ;
}
F_138 ( V_3 ) ;
} else {
if ( V_62 ) {
F_152 ( V_3 ) ;
if ( V_3 -> V_2 )
F_153 ( V_3 -> V_2 , V_62 ) ;
}
F_141 ( V_3 ) ;
}
}
void F_154 ( struct V_3 * V_108 )
{
struct V_3 * V_3 = F_140 ( V_108 ) ;
T_4 * V_93 = F_109 ( V_3 ) ;
F_121 ( V_93 , V_3 , V_105 , V_100 , true ) ;
}
int F_155 ( struct V_3 * V_108 )
{
struct V_3 * V_3 = F_140 ( V_108 ) ;
T_4 * V_93 = F_109 ( V_3 ) ;
return F_121 ( V_93 , V_3 , V_105 , V_101 , true ) ;
}
int F_156 ( struct V_3 * V_3 , struct V_109 * V_74 ,
unsigned int V_30 )
{
if ( V_30 & V_110 ) {
if ( V_30 & V_111 )
return 0 ;
F_157 ( & V_74 -> V_112 ) ;
if ( V_30 & V_113 )
F_158 ( V_3 ) ;
else
F_159 ( V_3 ) ;
return 0 ;
} else {
if ( V_30 & V_113 ) {
int V_33 ;
V_33 = F_155 ( V_3 ) ;
if ( V_33 ) {
F_157 ( & V_74 -> V_112 ) ;
return 0 ;
}
} else
F_154 ( V_3 ) ;
return 1 ;
}
}
T_2 F_160 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_114 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_114 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_161 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 ++ ;
if ( V_9 == 0 )
break;
}
return V_9 ;
}
T_2 F_162 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_114 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_114 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_161 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_115 )
break;
}
return V_9 ;
}
struct V_3 * F_163 ( struct V_1 * V_2 , T_2 V_70 )
{
void * * V_116 ;
struct V_3 * V_117 , * V_3 ;
F_164 () ;
V_118:
V_3 = NULL ;
V_116 = F_165 ( & V_2 -> V_8 , V_70 ) ;
if ( V_116 ) {
V_3 = F_166 ( V_116 ) ;
if ( F_27 ( ! V_3 ) )
goto V_56;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) )
goto V_118;
goto V_56;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_116 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
}
V_56:
F_170 () ;
return V_3 ;
}
struct V_3 * F_171 ( struct V_1 * V_2 , T_2 V_70 )
{
struct V_3 * V_3 ;
V_118:
V_3 = F_163 ( V_2 , V_70 ) ;
if ( V_3 && ! F_167 ( V_3 ) ) {
F_172 ( V_3 ) ;
if ( F_27 ( F_47 ( V_3 ) != V_2 ) ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_118;
}
F_13 ( F_173 ( V_3 ) != V_70 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_174 ( struct V_1 * V_2 , T_2 V_70 ,
int V_119 , T_3 V_68 )
{
struct V_3 * V_3 ;
V_118:
V_3 = F_163 ( V_2 , V_70 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_120;
if ( V_119 & V_121 ) {
if ( V_119 & V_122 ) {
if ( ! F_175 ( V_3 ) ) {
F_52 ( V_3 ) ;
return NULL ;
}
} else {
F_172 ( V_3 ) ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_118;
}
F_13 ( V_3 -> V_9 != V_70 , V_3 ) ;
}
if ( V_3 && ( V_119 & V_123 ) )
F_176 ( V_3 ) ;
V_120:
if ( ! V_3 && ( V_119 & V_124 ) ) {
int V_62 ;
if ( ( V_119 & V_125 ) && F_177 ( V_2 ) )
V_68 |= V_76 ;
if ( V_119 & V_126 )
V_68 &= ~ V_127 ;
V_3 = F_102 ( V_68 ) ;
if ( ! V_3 )
return NULL ;
if ( F_6 ( ! ( V_119 & V_121 ) ) )
V_119 |= V_121 ;
if ( V_119 & V_123 )
F_178 ( V_3 ) ;
V_62 = F_94 ( V_3 , V_2 , V_70 ,
V_68 & V_128 ) ;
if ( F_27 ( V_62 ) ) {
F_52 ( V_3 ) ;
V_3 = NULL ;
if ( V_62 == - V_12 )
goto V_118;
}
}
return V_3 ;
}
unsigned F_179 ( struct V_1 * V_2 ,
T_2 V_38 , unsigned int V_129 ,
struct V_3 * * V_130 , T_2 * V_131 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_132 V_133 ;
if ( ! V_129 )
return 0 ;
F_164 () ;
F_180 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_117 , * V_3 ;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
goto V_134;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
V_134:
V_131 [ V_33 ] = V_133 . V_9 ;
V_130 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_129 )
break;
}
F_170 () ;
return V_33 ;
}
unsigned F_182 ( struct V_1 * V_2 , T_2 V_38 ,
unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_132 V_133 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_164 () ;
F_180 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_117 , * V_3 ;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
continue;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_170 () ;
return V_33 ;
}
unsigned F_183 ( struct V_1 * V_2 , T_2 V_9 ,
unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_132 V_133 ;
void * * V_7 ;
unsigned int V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_164 () ;
F_184 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_117 , * V_3 ;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
break;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
break;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( V_3 -> V_2 == NULL || F_173 ( V_3 ) != V_133 . V_9 ) {
F_52 ( V_3 ) ;
break;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_170 () ;
return V_33 ;
}
unsigned F_185 ( struct V_1 * V_2 , T_2 * V_9 ,
int V_135 , unsigned int V_55 , struct V_3 * * V_59 )
{
struct V_132 V_133 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_55 ) )
return 0 ;
F_164 () ;
F_186 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_117 , * V_3 ;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
continue;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
V_59 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_55 )
break;
}
F_170 () ;
if ( V_33 )
* V_9 = V_59 [ V_33 - 1 ] -> V_9 + 1 ;
return V_33 ;
}
unsigned F_187 ( struct V_1 * V_2 , T_2 V_38 ,
int V_135 , unsigned int V_129 ,
struct V_3 * * V_130 , T_2 * V_131 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_132 V_133 ;
if ( ! V_129 )
return 0 ;
F_164 () ;
F_186 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_117 , * V_3 ;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
goto V_134;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
V_134:
V_131 [ V_33 ] = V_133 . V_9 ;
V_130 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_129 )
break;
}
F_170 () ;
return V_33 ;
}
static void F_188 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
V_139 -> V_140 /= 4 ;
}
static T_7 F_189 ( struct V_136 * V_137 , T_1 * V_141 ,
struct V_142 * V_133 , T_7 V_143 )
{
struct V_1 * V_2 = V_137 -> V_144 ;
struct V_145 * V_145 = V_2 -> V_29 ;
struct V_138 * V_139 = & V_137 -> V_146 ;
T_2 V_9 ;
T_2 V_147 ;
T_2 V_148 ;
unsigned long V_70 ;
unsigned int V_149 ;
int error = 0 ;
if ( F_27 ( * V_141 >= V_145 -> V_150 -> V_151 ) )
return 0 ;
F_190 ( V_133 , V_145 -> V_150 -> V_151 ) ;
V_9 = * V_141 >> V_52 ;
V_148 = V_139 -> V_152 >> V_52 ;
V_149 = V_139 -> V_152 & ( V_153 - 1 ) ;
V_147 = ( * V_141 + V_133 -> V_154 + V_153 - 1 ) >> V_52 ;
V_70 = * V_141 & ~ V_155 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_156 ;
T_1 V_157 ;
unsigned long V_19 , V_33 ;
F_72 () ;
V_158:
if ( F_191 ( V_22 ) ) {
error = - V_99 ;
goto V_56;
}
V_3 = F_192 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
F_193 ( V_2 ,
V_139 , V_137 ,
V_9 , V_147 - V_9 ) ;
V_3 = F_192 ( V_2 , V_9 ) ;
if ( F_27 ( V_3 == NULL ) )
goto V_159;
}
if ( F_194 ( V_3 ) ) {
F_195 ( V_2 ,
V_139 , V_137 , V_3 ,
V_9 , V_147 - V_9 ) ;
}
if ( ! F_21 ( V_3 ) ) {
error = F_158 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_160;
if ( F_21 ( V_3 ) )
goto V_161;
if ( V_145 -> V_162 == V_52 ||
! V_2 -> V_31 -> V_163 )
goto V_164;
if ( F_27 ( V_133 -> type & V_165 ) )
goto V_164;
if ( ! F_175 ( V_3 ) )
goto V_164;
if ( ! V_3 -> V_2 )
goto V_166;
if ( ! V_2 -> V_31 -> V_163 ( V_3 ,
V_70 , V_133 -> V_154 ) )
goto V_166;
F_138 ( V_3 ) ;
}
V_161:
V_157 = F_75 ( V_145 ) ;
V_156 = ( V_157 - 1 ) >> V_52 ;
if ( F_27 ( ! V_157 || V_9 > V_156 ) ) {
F_52 ( V_3 ) ;
goto V_56;
}
V_19 = V_153 ;
if ( V_9 == V_156 ) {
V_19 = ( ( V_157 - 1 ) & ~ V_155 ) + 1 ;
if ( V_19 <= V_70 ) {
F_52 ( V_3 ) ;
goto V_56;
}
}
V_19 = V_19 - V_70 ;
if ( F_196 ( V_2 ) )
F_197 ( V_3 ) ;
if ( V_148 != V_9 || V_70 != V_149 )
F_176 ( V_3 ) ;
V_148 = V_9 ;
V_33 = F_198 ( V_3 , V_70 , V_19 , V_133 ) ;
V_70 += V_33 ;
V_9 += V_70 >> V_52 ;
V_70 &= ~ V_155 ;
V_149 = V_70 ;
F_52 ( V_3 ) ;
V_143 += V_33 ;
if ( ! F_199 ( V_133 ) )
goto V_56;
if ( V_33 < V_19 ) {
error = - V_167 ;
goto V_56;
}
continue;
V_164:
error = F_200 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_160;
V_166:
if ( ! V_3 -> V_2 ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
continue;
}
if ( F_21 ( V_3 ) ) {
F_138 ( V_3 ) ;
goto V_161;
}
V_168:
F_201 ( V_3 ) ;
error = V_2 -> V_31 -> V_168 ( V_137 , V_3 ) ;
if ( F_27 ( error ) ) {
if ( error == V_169 ) {
F_52 ( V_3 ) ;
error = 0 ;
goto V_158;
}
goto V_160;
}
if ( ! F_21 ( V_3 ) ) {
error = F_200 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_160;
if ( ! F_21 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_158;
}
F_138 ( V_3 ) ;
F_188 ( V_137 , V_139 ) ;
error = - V_37 ;
goto V_160;
}
F_138 ( V_3 ) ;
}
goto V_161;
V_160:
F_52 ( V_3 ) ;
goto V_56;
V_159:
V_3 = F_202 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_170 ;
goto V_56;
}
error = F_94 ( V_3 , V_2 , V_9 ,
F_203 ( V_2 , V_171 ) ) ;
if ( error ) {
F_52 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_158;
}
goto V_56;
}
goto V_168;
}
V_56:
V_139 -> V_152 = V_148 ;
V_139 -> V_152 <<= V_52 ;
V_139 -> V_152 |= V_149 ;
* V_141 = ( ( T_1 ) V_9 << V_52 ) + V_70 ;
F_204 ( V_137 ) ;
return V_143 ? V_143 : error ;
}
T_7
F_205 ( struct V_172 * V_173 , struct V_142 * V_133 )
{
struct V_136 * V_136 = V_173 -> V_174 ;
T_7 V_175 = 0 ;
T_8 V_154 = F_199 ( V_133 ) ;
if ( ! V_154 )
goto V_56;
if ( V_173 -> V_176 & V_177 ) {
struct V_1 * V_2 = V_136 -> V_144 ;
struct V_145 * V_145 = V_2 -> V_29 ;
struct V_142 V_178 = * V_133 ;
T_1 V_179 ;
V_179 = F_75 ( V_145 ) ;
V_175 = F_78 ( V_2 , V_173 -> V_180 ,
V_173 -> V_180 + V_154 - 1 ) ;
if ( V_175 < 0 )
goto V_56;
F_204 ( V_136 ) ;
V_175 = V_2 -> V_31 -> V_181 ( V_173 , & V_178 ) ;
if ( V_175 >= 0 ) {
V_173 -> V_180 += V_175 ;
F_206 ( V_133 , V_175 ) ;
}
if ( V_175 < 0 || ! F_199 ( V_133 ) || V_173 -> V_180 >= V_179 ||
F_207 ( V_145 ) )
goto V_56;
}
V_175 = F_189 ( V_136 , & V_173 -> V_180 , V_133 , V_175 ) ;
V_56:
return V_175 ;
}
static int F_208 ( struct V_136 * V_136 , T_2 V_70 , T_3 V_68 )
{
struct V_1 * V_2 = V_136 -> V_144 ;
struct V_3 * V_3 ;
int V_33 ;
do {
V_3 = F_102 ( V_68 | V_182 ) ;
if ( ! V_3 )
return - V_170 ;
V_33 = F_94 ( V_3 , V_2 , V_70 , V_68 & V_171 ) ;
if ( V_33 == 0 )
V_33 = V_2 -> V_31 -> V_168 ( V_136 , V_3 ) ;
else if ( V_33 == - V_12 )
V_33 = 0 ;
F_52 ( V_3 ) ;
} while ( V_33 == V_169 );
return V_33 ;
}
static void F_209 ( struct V_183 * V_184 ,
struct V_138 * V_139 ,
struct V_136 * V_136 ,
T_2 V_70 )
{
struct V_1 * V_2 = V_136 -> V_144 ;
if ( V_184 -> V_185 & V_186 )
return;
if ( ! V_139 -> V_140 )
return;
if ( V_184 -> V_185 & V_187 ) {
F_193 ( V_2 , V_139 , V_136 , V_70 ,
V_139 -> V_140 ) ;
return;
}
if ( V_139 -> V_188 < V_189 * 10 )
V_139 -> V_188 ++ ;
if ( V_139 -> V_188 > V_189 )
return;
V_139 -> V_38 = F_210 ( long , 0 , V_70 - V_139 -> V_140 / 2 ) ;
V_139 -> V_179 = V_139 -> V_140 ;
V_139 -> V_190 = V_139 -> V_140 / 4 ;
F_211 ( V_139 , V_2 , V_136 ) ;
}
static void F_212 ( struct V_183 * V_184 ,
struct V_138 * V_139 ,
struct V_136 * V_136 ,
struct V_3 * V_3 ,
T_2 V_70 )
{
struct V_1 * V_2 = V_136 -> V_144 ;
if ( V_184 -> V_185 & V_186 )
return;
if ( V_139 -> V_188 > 0 )
V_139 -> V_188 -- ;
if ( F_194 ( V_3 ) )
F_195 ( V_2 , V_139 , V_136 ,
V_3 , V_70 , V_139 -> V_140 ) ;
}
int F_213 ( struct V_183 * V_184 , struct V_191 * V_192 )
{
int error ;
struct V_136 * V_136 = V_184 -> V_193 ;
struct V_1 * V_2 = V_136 -> V_144 ;
struct V_138 * V_139 = & V_136 -> V_146 ;
struct V_145 * V_145 = V_2 -> V_29 ;
T_2 V_70 = V_192 -> V_194 ;
struct V_3 * V_3 ;
T_1 V_179 ;
int V_33 = 0 ;
V_179 = F_214 ( F_75 ( V_145 ) , V_153 ) ;
if ( V_70 >= V_179 >> V_52 )
return V_195 ;
V_3 = F_192 ( V_2 , V_70 ) ;
if ( F_123 ( V_3 ) && ! ( V_192 -> V_30 & V_196 ) ) {
F_212 ( V_184 , V_139 , V_136 , V_3 , V_70 ) ;
} else if ( ! V_3 ) {
F_209 ( V_184 , V_139 , V_136 , V_70 ) ;
F_215 ( V_197 ) ;
F_216 ( V_184 -> V_198 , V_197 ) ;
V_33 = V_199 ;
V_200:
V_3 = F_192 ( V_2 , V_70 ) ;
if ( ! V_3 )
goto V_159;
}
if ( ! F_217 ( V_3 , V_184 -> V_198 , V_192 -> V_30 ) ) {
F_52 ( V_3 ) ;
return V_33 | V_201 ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_200;
}
F_13 ( V_3 -> V_9 != V_70 , V_3 ) ;
if ( F_27 ( ! F_21 ( V_3 ) ) )
goto V_202;
V_179 = F_214 ( F_75 ( V_145 ) , V_153 ) ;
if ( F_27 ( V_70 >= V_179 >> V_52 ) ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
return V_195 ;
}
V_192 -> V_3 = V_3 ;
return V_33 | V_203 ;
V_159:
error = F_208 ( V_136 , V_70 , V_192 -> V_68 ) ;
if ( error >= 0 )
goto V_200;
if ( error == - V_170 )
return V_204 ;
return V_195 ;
V_202:
F_201 ( V_3 ) ;
error = V_2 -> V_31 -> V_168 ( V_136 , V_3 ) ;
if ( ! error ) {
F_159 ( V_3 ) ;
if ( ! F_21 ( V_3 ) )
error = - V_37 ;
}
F_52 ( V_3 ) ;
if ( ! error || error == V_169 )
goto V_200;
F_188 ( V_136 , V_139 ) ;
return V_195 ;
}
void F_218 ( struct V_191 * V_192 ,
T_2 V_205 , T_2 V_206 )
{
struct V_132 V_133 ;
void * * V_7 ;
struct V_136 * V_136 = V_192 -> V_184 -> V_193 ;
struct V_1 * V_2 = V_136 -> V_144 ;
T_2 V_207 = V_205 ;
T_1 V_179 ;
struct V_3 * V_117 , * V_3 ;
F_164 () ;
F_180 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_133 . V_9 > V_206 )
break;
V_118:
V_3 = F_166 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
goto V_208;
if ( F_167 ( V_3 ) ) {
if ( F_168 ( V_3 ) ) {
V_7 = F_181 ( & V_133 ) ;
continue;
}
goto V_208;
}
V_117 = F_140 ( V_3 ) ;
if ( ! F_169 ( V_117 ) )
goto V_118;
if ( F_140 ( V_3 ) != V_117 ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_117 ) ;
goto V_118;
}
if ( ! F_21 ( V_3 ) ||
F_194 ( V_3 ) ||
F_219 ( V_3 ) )
goto V_209;
if ( ! F_175 ( V_3 ) )
goto V_209;
if ( V_3 -> V_2 != V_2 || ! F_21 ( V_3 ) )
goto V_210;
V_179 = F_214 ( F_75 ( V_2 -> V_29 ) , V_153 ) ;
if ( V_3 -> V_9 >= V_179 >> V_52 )
goto V_210;
if ( V_136 -> V_146 . V_188 > 0 )
V_136 -> V_146 . V_188 -- ;
V_192 -> V_211 += ( V_133 . V_9 - V_207 ) << V_52 ;
if ( V_192 -> V_212 )
V_192 -> V_212 += V_133 . V_9 - V_207 ;
V_207 = V_133 . V_9 ;
if ( F_220 ( V_192 , NULL , V_3 ) )
goto V_210;
F_138 ( V_3 ) ;
goto V_208;
V_210:
F_138 ( V_3 ) ;
V_209:
F_52 ( V_3 ) ;
V_208:
if ( F_221 ( * V_192 -> V_213 ) )
break;
if ( V_133 . V_9 == V_206 )
break;
}
F_170 () ;
}
int F_222 ( struct V_183 * V_184 , struct V_191 * V_192 )
{
struct V_3 * V_3 = V_192 -> V_3 ;
struct V_145 * V_145 = F_223 ( V_184 -> V_193 ) ;
int V_33 = V_203 ;
F_224 ( V_145 -> V_150 ) ;
F_225 ( V_184 -> V_193 ) ;
F_172 ( V_3 ) ;
if ( V_3 -> V_2 != V_145 -> V_214 ) {
F_138 ( V_3 ) ;
V_33 = V_215 ;
goto V_56;
}
F_226 ( V_3 ) ;
F_227 ( V_3 ) ;
V_56:
F_228 ( V_145 -> V_150 ) ;
return V_33 ;
}
int F_229 ( struct V_136 * V_136 , struct V_183 * V_184 )
{
struct V_1 * V_2 = V_136 -> V_144 ;
if ( ! V_2 -> V_31 -> V_168 )
return - V_216 ;
F_204 ( V_136 ) ;
V_184 -> V_217 = & V_218 ;
return 0 ;
}
int F_230 ( struct V_136 * V_136 , struct V_183 * V_184 )
{
if ( ( V_184 -> V_185 & V_219 ) && ( V_184 -> V_185 & V_220 ) )
return - V_221 ;
return F_229 ( V_136 , V_184 ) ;
}
int F_229 ( struct V_136 * V_136 , struct V_183 * V_184 )
{
return - V_222 ;
}
int F_230 ( struct V_136 * V_136 , struct V_183 * V_184 )
{
return - V_222 ;
}
static struct V_3 * F_231 ( struct V_3 * V_3 )
{
if ( ! F_232 ( V_3 ) ) {
F_159 ( V_3 ) ;
if ( ! F_21 ( V_3 ) ) {
F_52 ( V_3 ) ;
V_3 = F_233 ( - V_37 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_234 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_235)( void * , struct V_3 * ) ,
void * V_178 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_62 ;
V_118:
V_3 = F_192 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_102 ( V_77 | V_182 ) ;
if ( ! V_3 )
return F_233 ( - V_170 ) ;
V_62 = F_94 ( V_3 , V_2 , V_9 , V_77 ) ;
if ( F_27 ( V_62 ) ) {
F_52 ( V_3 ) ;
if ( V_62 == - V_12 )
goto V_118;
return F_233 ( V_62 ) ;
}
F_235:
V_62 = F_235 ( V_178 , V_3 ) ;
if ( V_62 < 0 ) {
F_52 ( V_3 ) ;
return F_233 ( V_62 ) ;
}
V_3 = F_231 ( V_3 ) ;
if ( F_232 ( V_3 ) )
return V_3 ;
goto V_56;
}
if ( F_21 ( V_3 ) )
goto V_56;
F_159 ( V_3 ) ;
if ( F_21 ( V_3 ) )
goto V_56;
F_172 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_138 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_118;
}
if ( F_21 ( V_3 ) ) {
F_138 ( V_3 ) ;
goto V_56;
}
goto F_235;
V_56:
F_176 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_236 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_235)( void * , struct V_3 * ) ,
void * V_178 )
{
return F_234 ( V_2 , V_9 , F_235 , V_178 , F_237 ( V_2 ) ) ;
}
struct V_3 * F_238 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_3 V_77 )
{
T_9 * F_235 = ( T_9 * ) V_2 -> V_31 -> V_168 ;
return F_234 ( V_2 , V_9 , F_235 , NULL , V_77 ) ;
}
inline T_7 F_239 ( struct V_172 * V_173 , struct V_142 * V_223 )
{
struct V_136 * V_136 = V_173 -> V_174 ;
struct V_145 * V_145 = V_136 -> V_144 -> V_29 ;
unsigned long V_224 = F_240 ( V_225 ) ;
T_1 V_226 ;
if ( ! F_199 ( V_223 ) )
return 0 ;
if ( V_173 -> V_176 & V_227 )
V_173 -> V_180 = F_75 ( V_145 ) ;
V_226 = V_173 -> V_180 ;
if ( V_224 != V_228 ) {
if ( V_173 -> V_180 >= V_224 ) {
F_241 ( V_229 , V_22 , 0 ) ;
return - V_230 ;
}
F_190 ( V_223 , V_224 - ( unsigned long ) V_226 ) ;
}
if ( F_27 ( V_226 + F_199 ( V_223 ) > V_231 &&
! ( V_136 -> V_232 & V_233 ) ) ) {
if ( V_226 >= V_231 )
return - V_230 ;
F_190 ( V_223 , V_231 - ( unsigned long ) V_226 ) ;
}
if ( F_27 ( V_226 >= V_145 -> V_150 -> V_151 ) )
return - V_230 ;
F_190 ( V_223 , V_145 -> V_150 -> V_151 - V_226 ) ;
return F_199 ( V_223 ) ;
}
int F_242 ( struct V_136 * V_136 , struct V_1 * V_2 ,
T_1 V_226 , unsigned V_234 , unsigned V_30 ,
struct V_3 * * V_116 , void * * V_235 )
{
const struct V_236 * V_237 = V_2 -> V_31 ;
return V_237 -> V_238 ( V_136 , V_2 , V_226 , V_234 , V_30 ,
V_116 , V_235 ) ;
}
int F_243 ( struct V_136 * V_136 , struct V_1 * V_2 ,
T_1 V_226 , unsigned V_234 , unsigned V_239 ,
struct V_3 * V_3 , void * V_235 )
{
const struct V_236 * V_237 = V_2 -> V_31 ;
return V_237 -> V_240 ( V_136 , V_2 , V_226 , V_234 , V_239 , V_3 , V_235 ) ;
}
T_7
F_244 ( struct V_172 * V_173 , struct V_142 * V_223 )
{
struct V_136 * V_136 = V_173 -> V_174 ;
struct V_1 * V_2 = V_136 -> V_144 ;
struct V_145 * V_145 = V_2 -> V_29 ;
T_1 V_226 = V_173 -> V_180 ;
T_7 V_143 ;
T_8 V_241 ;
T_2 V_39 ;
struct V_142 V_178 ;
V_241 = F_199 ( V_223 ) ;
V_39 = ( V_226 + V_241 - 1 ) >> V_52 ;
V_143 = F_78 ( V_2 , V_226 , V_226 + V_241 - 1 ) ;
if ( V_143 )
goto V_56;
if ( V_2 -> V_16 ) {
V_143 = F_245 ( V_2 ,
V_226 >> V_52 , V_39 ) ;
if ( V_143 ) {
if ( V_143 == - V_242 )
return 0 ;
goto V_56;
}
}
V_178 = * V_223 ;
V_143 = V_2 -> V_31 -> V_181 ( V_173 , & V_178 ) ;
if ( V_2 -> V_16 ) {
F_245 ( V_2 ,
V_226 >> V_52 , V_39 ) ;
}
if ( V_143 > 0 ) {
V_226 += V_143 ;
F_206 ( V_223 , V_143 ) ;
if ( V_226 > F_75 ( V_145 ) && ! F_246 ( V_145 -> V_243 ) ) {
F_247 ( V_145 , V_226 ) ;
F_248 ( V_145 ) ;
}
V_173 -> V_180 = V_226 ;
}
V_56:
return V_143 ;
}
struct V_3 * F_249 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_30 )
{
struct V_3 * V_3 ;
int V_119 = V_121 | V_125 | V_124 ;
if ( V_30 & V_244 )
V_119 |= V_126 ;
V_3 = F_174 ( V_2 , V_9 , V_119 ,
F_237 ( V_2 ) ) ;
if ( V_3 )
F_227 ( V_3 ) ;
return V_3 ;
}
T_7 F_250 ( struct V_136 * V_136 ,
struct V_142 * V_18 , T_1 V_226 )
{
struct V_1 * V_2 = V_136 -> V_144 ;
const struct V_236 * V_31 = V_2 -> V_31 ;
long V_245 = 0 ;
T_7 V_143 = 0 ;
unsigned int V_30 = 0 ;
if ( ! F_251 ( V_18 ) )
V_30 |= V_246 ;
do {
struct V_3 * V_3 ;
unsigned long V_70 ;
unsigned long V_247 ;
T_8 V_239 ;
void * V_235 ;
V_70 = ( V_226 & ( V_153 - 1 ) ) ;
V_247 = F_252 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_248:
if ( F_27 ( F_253 ( V_18 , V_247 ) ) ) {
V_245 = - V_167 ;
break;
}
if ( F_191 ( V_22 ) ) {
V_245 = - V_99 ;
break;
}
V_245 = V_31 -> V_238 ( V_136 , V_2 , V_226 , V_247 , V_30 ,
& V_3 , & V_235 ) ;
if ( F_27 ( V_245 < 0 ) )
break;
if ( F_196 ( V_2 ) )
F_197 ( V_3 ) ;
V_239 = F_254 ( V_3 , V_18 , V_70 , V_247 ) ;
F_197 ( V_3 ) ;
V_245 = V_31 -> V_240 ( V_136 , V_2 , V_226 , V_247 , V_239 ,
V_3 , V_235 ) ;
if ( F_27 ( V_245 < 0 ) )
break;
V_239 = V_245 ;
F_72 () ;
F_206 ( V_18 , V_239 ) ;
if ( F_27 ( V_239 == 0 ) ) {
V_247 = F_252 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_248;
}
V_226 += V_239 ;
V_143 += V_239 ;
F_255 ( V_2 ) ;
} while ( F_199 ( V_18 ) );
return V_143 ? V_143 : V_245 ;
}
T_7 F_256 ( struct V_172 * V_173 , struct V_142 * V_223 )
{
struct V_136 * V_136 = V_173 -> V_174 ;
struct V_1 * V_2 = V_136 -> V_144 ;
struct V_145 * V_145 = V_2 -> V_29 ;
T_7 V_143 = 0 ;
T_7 V_62 ;
T_7 V_245 ;
V_22 -> V_249 = F_257 ( V_145 ) ;
V_62 = F_258 ( V_136 ) ;
if ( V_62 )
goto V_56;
V_62 = F_225 ( V_136 ) ;
if ( V_62 )
goto V_56;
if ( V_173 -> V_176 & V_177 ) {
T_1 V_226 , V_250 ;
V_143 = F_244 ( V_173 , V_223 ) ;
if ( V_143 < 0 || ! F_199 ( V_223 ) || F_207 ( V_145 ) )
goto V_56;
V_245 = F_250 ( V_136 , V_223 , V_226 = V_173 -> V_180 ) ;
if ( F_27 ( V_245 < 0 ) ) {
V_62 = V_245 ;
goto V_56;
}
V_250 = V_226 + V_245 - 1 ;
V_62 = F_78 ( V_2 , V_226 , V_250 ) ;
if ( V_62 == 0 ) {
V_173 -> V_180 = V_250 + 1 ;
V_143 += V_245 ;
F_259 ( V_2 ,
V_226 >> V_52 ,
V_250 >> V_52 ) ;
} else {
}
} else {
V_143 = F_250 ( V_136 , V_223 , V_173 -> V_180 ) ;
if ( F_123 ( V_143 > 0 ) )
V_173 -> V_180 += V_143 ;
}
V_56:
V_22 -> V_249 = NULL ;
return V_143 ? V_143 : V_62 ;
}
T_7 F_260 ( struct V_172 * V_173 , struct V_142 * V_223 )
{
struct V_136 * V_136 = V_173 -> V_174 ;
struct V_145 * V_145 = V_136 -> V_144 -> V_29 ;
T_7 V_33 ;
F_261 ( V_145 ) ;
V_33 = F_239 ( V_173 , V_223 ) ;
if ( V_33 > 0 )
V_33 = F_256 ( V_173 , V_223 ) ;
F_262 ( V_145 ) ;
if ( V_33 > 0 )
V_33 = F_263 ( V_173 , V_33 ) ;
return V_33 ;
}
int F_264 ( struct V_3 * V_3 , T_3 V_68 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_49 ( ! F_14 ( V_3 ) ) ;
if ( F_265 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_31 -> V_251 )
return V_2 -> V_31 -> V_251 ( V_3 , V_68 ) ;
return F_266 ( V_3 ) ;
}
