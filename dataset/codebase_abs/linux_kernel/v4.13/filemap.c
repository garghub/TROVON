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
if ( F_11 ( V_3 ) )
return;
F_38 ( F_39 ( V_3 ) , V_26 , - V_19 ) ;
if ( F_40 ( V_3 ) ) {
F_38 ( F_39 ( V_3 ) , V_27 , - V_19 ) ;
if ( F_41 ( V_3 ) )
F_42 ( V_3 , V_28 ) ;
} else {
F_13 ( F_41 ( V_3 ) , V_3 ) ;
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
static int F_56 ( struct V_1 * V_2 )
{
if ( F_54 ( V_36 , & V_2 -> V_30 ) )
return - V_37 ;
if ( F_54 ( V_34 , & V_2 -> V_30 ) )
return - V_35 ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 , int V_40 )
{
int V_33 ;
struct V_41 V_42 = {
. V_40 = V_40 ,
. V_43 = V_44 ,
. V_45 = V_38 ,
. V_46 = V_39 ,
} ;
if ( ! F_58 ( V_2 ) )
return 0 ;
F_59 ( & V_42 , V_2 -> V_29 ) ;
V_33 = F_60 ( V_2 , & V_42 ) ;
F_61 ( & V_42 ) ;
return V_33 ;
}
static inline int F_62 ( struct V_1 * V_2 ,
int V_40 )
{
return F_57 ( V_2 , 0 , V_47 , V_40 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
return F_62 ( V_2 , V_48 ) ;
}
int F_64 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 )
{
return F_57 ( V_2 , V_38 , V_39 , V_48 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
return F_62 ( V_2 , V_49 ) ;
}
bool F_66 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_51 )
{
T_2 V_9 = V_50 >> V_52 ;
T_2 V_39 = V_51 >> V_52 ;
struct V_53 V_54 ;
bool V_33 ;
if ( V_51 < V_50 )
return false ;
if ( V_2 -> V_16 == 0 )
return false ;
F_67 ( & V_54 , 0 ) ;
if ( ! F_68 ( & V_54 , V_2 , V_9 , 1 ) )
return false ;
V_33 = ( V_54 . V_55 [ 0 ] -> V_9 <= V_39 ) ;
F_69 ( & V_54 ) ;
return V_33 ;
}
static void F_70 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_51 )
{
T_2 V_9 = V_50 >> V_52 ;
T_2 V_39 = V_51 >> V_52 ;
struct V_53 V_54 ;
int V_56 ;
if ( V_51 < V_50 )
return;
F_67 ( & V_54 , 0 ) ;
while ( ( V_9 <= V_39 ) &&
( V_56 = F_71 ( & V_54 , V_2 , & V_9 ,
V_57 ,
F_72 ( V_39 - V_9 , ( T_2 ) V_58 - 1 ) + 1 ) ) != 0 ) {
unsigned V_18 ;
for ( V_18 = 0 ; V_18 < V_56 ; V_18 ++ ) {
struct V_3 * V_3 = V_54 . V_55 [ V_18 ] ;
if ( V_3 -> V_9 > V_39 )
continue;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
}
F_69 ( & V_54 ) ;
F_75 () ;
}
}
int F_76 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 )
{
F_70 ( V_2 , V_50 , V_51 ) ;
return F_53 ( V_2 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
T_1 V_59 = F_78 ( V_2 -> V_29 ) ;
if ( V_59 == 0 )
return 0 ;
F_70 ( V_2 , 0 , V_59 - 1 ) ;
return F_56 ( V_2 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
T_1 V_59 = F_78 ( V_2 -> V_29 ) ;
if ( V_59 == 0 )
return 0 ;
return F_76 ( V_2 , 0 , V_59 - 1 ) ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_60 = F_63 ( V_2 ) ;
if ( V_60 != - V_37 ) {
int V_61 = F_79 ( V_2 ) ;
if ( ! V_60 )
V_60 = V_61 ;
} else {
F_53 ( V_2 ) ;
}
} else {
V_60 = F_53 ( V_2 ) ;
}
return V_60 ;
}
int F_81 ( struct V_1 * V_2 ,
T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_60 = F_57 ( V_2 , V_62 , V_63 ,
V_48 ) ;
if ( V_60 != - V_37 ) {
int V_61 = F_76 ( V_2 ,
V_62 , V_63 ) ;
if ( ! V_60 )
V_60 = V_61 ;
} else {
F_53 ( V_2 ) ;
}
} else {
V_60 = F_53 ( V_2 ) ;
}
return V_60 ;
}
void F_82 ( struct V_1 * V_2 , int V_60 )
{
T_3 V_64 = F_83 ( & V_2 -> V_65 , V_60 ) ;
F_84 ( V_2 , V_64 ) ;
}
int F_85 ( struct V_66 * V_66 )
{
int V_60 = 0 ;
T_3 V_67 = F_86 ( V_66 -> V_68 ) ;
struct V_1 * V_2 = V_66 -> V_69 ;
if ( F_87 ( & V_2 -> V_65 , V_67 ) ) {
F_88 ( & V_66 -> V_70 ) ;
V_67 = V_66 -> V_68 ;
V_60 = F_89 ( & V_2 -> V_65 ,
& V_66 -> V_68 ) ;
F_90 ( V_66 , V_67 ) ;
F_91 ( & V_66 -> V_70 ) ;
}
return V_60 ;
}
int F_92 ( struct V_66 * V_66 , T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 , V_61 ;
struct V_1 * V_2 = V_66 -> V_69 ;
if ( ( ! F_5 ( V_2 ) && V_2 -> V_16 ) ||
( F_5 ( V_2 ) && V_2 -> V_13 ) ) {
V_60 = F_57 ( V_2 , V_62 , V_63 ,
V_48 ) ;
if ( V_60 != - V_37 )
F_70 ( V_2 , V_62 , V_63 ) ;
}
V_61 = F_85 ( V_66 ) ;
if ( ! V_60 )
V_60 = V_61 ;
return V_60 ;
}
int F_93 ( struct V_3 * V_67 , struct V_3 * V_71 , T_4 V_72 )
{
int error ;
F_13 ( ! F_14 ( V_67 ) , V_67 ) ;
F_13 ( ! F_14 ( V_71 ) , V_71 ) ;
F_13 ( V_71 -> V_2 , V_71 ) ;
error = F_94 ( V_72 & ~ V_73 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_67 -> V_2 ;
void (* F_48)( struct V_3 * );
unsigned long V_30 ;
T_2 V_74 = V_67 -> V_9 ;
F_48 = V_2 -> V_31 -> F_48 ;
F_95 ( V_71 ) ;
V_71 -> V_2 = V_2 ;
V_71 -> V_9 = V_74 ;
F_50 ( & V_2 -> V_11 , V_30 ) ;
F_19 ( V_67 , NULL ) ;
error = F_1 ( V_2 , V_71 , NULL ) ;
F_49 ( error ) ;
if ( ! F_11 ( V_71 ) )
F_96 ( V_71 , V_26 ) ;
if ( F_40 ( V_71 ) )
F_96 ( V_71 , V_27 ) ;
F_51 ( & V_2 -> V_11 , V_30 ) ;
F_97 ( V_67 , V_71 ) ;
F_98 () ;
if ( F_48 )
F_48 ( V_67 ) ;
F_52 ( V_67 ) ;
}
return error ;
}
static int F_99 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_74 , T_4 V_72 ,
void * * V_4 )
{
int V_75 = F_11 ( V_3 ) ;
struct V_76 * V_77 ;
int error ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
F_13 ( F_40 ( V_3 ) , V_3 ) ;
if ( ! V_75 ) {
error = F_100 ( V_3 , V_22 -> V_78 ,
V_72 , & V_77 , false ) ;
if ( error )
return error ;
}
error = F_101 ( V_72 & ~ V_73 ) ;
if ( error ) {
if ( ! V_75 )
F_102 ( V_3 , V_77 , false ) ;
return error ;
}
F_95 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = V_74 ;
F_103 ( & V_2 -> V_11 ) ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
F_98 () ;
if ( F_27 ( error ) )
goto V_79;
if ( ! V_75 )
F_96 ( V_3 , V_26 ) ;
F_104 ( & V_2 -> V_11 ) ;
if ( ! V_75 )
F_105 ( V_3 , V_77 , false , false ) ;
F_106 ( V_3 ) ;
return 0 ;
V_79:
V_3 -> V_2 = NULL ;
F_104 ( & V_2 -> V_11 ) ;
if ( ! V_75 )
F_102 ( V_3 , V_77 , false ) ;
F_52 ( V_3 ) ;
return error ;
}
int F_107 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_74 , T_4 V_72 )
{
return F_99 ( V_3 , V_2 , V_74 ,
V_72 , NULL ) ;
}
int F_108 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_74 , T_4 V_72 )
{
void * V_17 = NULL ;
int V_33 ;
F_109 ( V_3 ) ;
V_33 = F_99 ( V_3 , V_2 , V_74 ,
V_72 , & V_17 ) ;
if ( F_27 ( V_33 ) )
F_110 ( V_3 ) ;
else {
if ( ! ( V_72 & V_80 ) &&
V_17 && F_111 ( V_17 ) ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
} else
F_114 ( V_3 ) ;
F_115 ( V_3 ) ;
}
return V_33 ;
}
struct V_3 * F_116 ( T_4 V_81 )
{
int V_82 ;
struct V_3 * V_3 ;
if ( F_117 () ) {
unsigned int V_83 ;
do {
V_83 = F_118 () ;
V_82 = F_119 () ;
V_3 = F_120 ( V_82 , V_81 , 0 ) ;
} while ( ! V_3 && F_121 ( V_83 ) );
return V_3 ;
}
return F_122 ( V_81 , 0 ) ;
}
static T_5 * F_123 ( struct V_3 * V_3 )
{
return & V_84 [ F_124 ( V_3 , V_85 ) ] ;
}
void T_6 F_125 ( void )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_86 ; V_18 ++ )
F_126 ( & V_84 [ V_18 ] ) ;
F_127 () ;
}
static int F_128 ( T_7 * V_87 , unsigned V_88 , int V_89 , void * V_90 )
{
struct V_91 * V_92 = V_90 ;
struct V_93 * V_94
= F_129 ( V_87 , struct V_93 , V_87 ) ;
if ( V_94 -> V_3 != V_92 -> V_3 )
return 0 ;
V_92 -> V_95 = 1 ;
if ( V_94 -> V_96 != V_92 -> V_96 )
return 0 ;
if ( F_54 ( V_92 -> V_96 , & V_92 -> V_3 -> V_30 ) )
return - 1 ;
return F_130 ( V_87 , V_88 , V_89 , V_92 ) ;
}
static void F_131 ( struct V_3 * V_3 , int V_96 )
{
T_5 * V_97 = F_123 ( V_3 ) ;
struct V_91 V_92 ;
unsigned long V_30 ;
V_92 . V_3 = V_3 ;
V_92 . V_96 = V_96 ;
V_92 . V_95 = 0 ;
F_50 ( & V_97 -> V_98 , V_30 ) ;
F_132 ( V_97 , V_99 , & V_92 ) ;
if ( ! F_133 ( V_97 ) || ! V_92 . V_95 ) {
F_134 ( V_3 ) ;
}
F_51 ( & V_97 -> V_98 , V_30 ) ;
}
static void F_135 ( struct V_3 * V_3 , int V_100 )
{
if ( ! F_136 ( V_3 ) )
return;
F_131 ( V_3 , V_100 ) ;
}
static inline int F_137 ( T_5 * V_97 ,
struct V_3 * V_3 , int V_96 , int V_101 , bool V_98 )
{
struct V_93 V_94 ;
T_7 * V_87 = & V_94 . V_87 ;
int V_33 = 0 ;
F_138 ( V_87 ) ;
V_87 -> V_30 = V_98 ? V_102 : 0 ;
V_87 -> V_103 = F_128 ;
V_94 . V_3 = V_3 ;
V_94 . V_96 = V_96 ;
for (; ; ) {
F_103 ( & V_97 -> V_98 ) ;
if ( F_139 ( F_140 ( & V_87 -> V_104 ) ) ) {
F_141 ( V_97 , V_87 ) ;
F_142 ( V_3 ) ;
}
F_143 ( V_101 ) ;
F_104 ( & V_97 -> V_98 ) ;
if ( F_139 ( F_54 ( V_96 , & V_3 -> V_30 ) ) ) {
F_144 () ;
}
if ( V_98 ) {
if ( ! F_145 ( V_96 , & V_3 -> V_30 ) )
break;
} else {
if ( ! F_54 ( V_96 , & V_3 -> V_30 ) )
break;
}
if ( F_27 ( F_146 ( V_101 , V_22 ) ) ) {
V_33 = - V_105 ;
break;
}
}
F_147 ( V_97 , V_87 ) ;
return V_33 ;
}
void F_148 ( struct V_3 * V_3 , int V_96 )
{
T_5 * V_97 = F_123 ( V_3 ) ;
F_137 ( V_97 , V_3 , V_96 , V_106 , false ) ;
}
int F_149 ( struct V_3 * V_3 , int V_96 )
{
T_5 * V_97 = F_123 ( V_3 ) ;
return F_137 ( V_97 , V_3 , V_96 , V_107 , false ) ;
}
void F_150 ( struct V_3 * V_3 , T_7 * V_108 )
{
T_5 * V_97 = F_123 ( V_3 ) ;
unsigned long V_30 ;
F_50 ( & V_97 -> V_98 , V_30 ) ;
F_141 ( V_97 , V_108 ) ;
F_142 ( V_3 ) ;
F_51 ( & V_97 -> V_98 , V_30 ) ;
}
static inline bool F_151 ( long V_19 , volatile void * V_109 )
{
F_152 ( V_19 , V_109 ) ;
return F_54 ( V_110 , V_109 ) ;
}
void F_153 ( struct V_3 * V_3 )
{
F_154 ( V_110 != 7 ) ;
V_3 = F_155 ( V_3 ) ;
F_13 ( ! F_14 ( V_3 ) , V_3 ) ;
if ( F_151 ( V_111 , & V_3 -> V_30 ) )
F_131 ( V_3 , V_111 ) ;
}
void F_156 ( struct V_3 * V_3 )
{
if ( F_157 ( V_3 ) ) {
F_158 ( V_3 ) ;
F_159 ( V_3 ) ;
}
if ( ! F_160 ( V_3 ) )
F_161 () ;
F_162 () ;
F_135 ( V_3 , V_112 ) ;
}
void F_163 ( struct V_3 * V_3 , bool V_113 , int V_60 )
{
if ( ! V_113 ) {
if ( ! V_60 ) {
F_164 ( V_3 ) ;
} else {
F_165 ( V_3 ) ;
F_166 ( V_3 ) ;
}
F_153 ( V_3 ) ;
} else {
if ( V_60 ) {
struct V_1 * V_2 ;
F_166 ( V_3 ) ;
V_2 = F_47 ( V_3 ) ;
if ( V_2 )
F_167 ( V_2 , V_60 ) ;
}
F_156 ( V_3 ) ;
}
}
void F_168 ( struct V_3 * V_114 )
{
struct V_3 * V_3 = F_155 ( V_114 ) ;
T_5 * V_97 = F_123 ( V_3 ) ;
F_137 ( V_97 , V_3 , V_111 , V_106 , true ) ;
}
int F_169 ( struct V_3 * V_114 )
{
struct V_3 * V_3 = F_155 ( V_114 ) ;
T_5 * V_97 = F_123 ( V_3 ) ;
return F_137 ( V_97 , V_3 , V_111 , V_107 , true ) ;
}
int F_170 ( struct V_3 * V_3 , struct V_115 * V_78 ,
unsigned int V_30 )
{
if ( V_30 & V_116 ) {
if ( V_30 & V_117 )
return 0 ;
F_171 ( & V_78 -> V_118 ) ;
if ( V_30 & V_119 )
F_172 ( V_3 ) ;
else
F_173 ( V_3 ) ;
return 0 ;
} else {
if ( V_30 & V_119 ) {
int V_33 ;
V_33 = F_169 ( V_3 ) ;
if ( V_33 ) {
F_171 ( & V_78 -> V_118 ) ;
return 0 ;
}
} else
F_168 ( V_3 ) ;
return 1 ;
}
}
T_2 F_174 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_120 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_175 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 ++ ;
if ( V_9 == 0 )
break;
}
return V_9 ;
}
T_2 F_176 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_120 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
struct V_3 * V_3 ;
V_3 = F_175 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_121 )
break;
}
return V_9 ;
}
struct V_3 * F_177 ( struct V_1 * V_2 , T_2 V_74 )
{
void * * V_122 ;
struct V_3 * V_123 , * V_3 ;
F_178 () ;
V_124:
V_3 = NULL ;
V_122 = F_179 ( & V_2 -> V_8 , V_74 ) ;
if ( V_122 ) {
V_3 = F_180 ( V_122 ) ;
if ( F_27 ( ! V_3 ) )
goto V_125;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) )
goto V_124;
goto V_125;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_122 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
}
V_125:
F_184 () ;
return V_3 ;
}
struct V_3 * F_185 ( struct V_1 * V_2 , T_2 V_74 )
{
struct V_3 * V_3 ;
V_124:
V_3 = F_177 ( V_2 , V_74 ) ;
if ( V_3 && ! F_181 ( V_3 ) ) {
F_186 ( V_3 ) ;
if ( F_27 ( F_47 ( V_3 ) != V_2 ) ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_124;
}
F_13 ( F_187 ( V_3 ) != V_74 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_188 ( struct V_1 * V_2 , T_2 V_74 ,
int V_126 , T_4 V_72 )
{
struct V_3 * V_3 ;
V_124:
V_3 = F_177 ( V_2 , V_74 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_127;
if ( V_126 & V_128 ) {
if ( V_126 & V_129 ) {
if ( ! F_189 ( V_3 ) ) {
F_52 ( V_3 ) ;
return NULL ;
}
} else {
F_186 ( V_3 ) ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_124;
}
F_13 ( V_3 -> V_9 != V_74 , V_3 ) ;
}
if ( V_3 && ( V_126 & V_130 ) )
F_190 ( V_3 ) ;
V_127:
if ( ! V_3 && ( V_126 & V_131 ) ) {
int V_60 ;
if ( ( V_126 & V_132 ) && F_191 ( V_2 ) )
V_72 |= V_80 ;
if ( V_126 & V_133 )
V_72 &= ~ V_134 ;
V_3 = F_116 ( V_72 ) ;
if ( ! V_3 )
return NULL ;
if ( F_6 ( ! ( V_126 & V_128 ) ) )
V_126 |= V_128 ;
if ( V_126 & V_130 )
F_192 ( V_3 ) ;
V_60 = F_108 ( V_3 , V_2 , V_74 ,
V_72 & V_135 ) ;
if ( F_27 ( V_60 ) ) {
F_52 ( V_3 ) ;
V_3 = NULL ;
if ( V_60 == - V_12 )
goto V_124;
}
}
return V_3 ;
}
unsigned F_193 ( struct V_1 * V_2 ,
T_2 V_38 , unsigned int V_136 ,
struct V_3 * * V_137 , T_2 * V_138 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_139 V_140 ;
if ( ! V_136 )
return 0 ;
F_178 () ;
F_194 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_123 , * V_3 ;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
goto V_141;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
V_141:
V_138 [ V_33 ] = V_140 . V_9 ;
V_137 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_136 )
break;
}
F_184 () ;
return V_33 ;
}
unsigned F_196 ( struct V_1 * V_2 , T_2 V_38 ,
unsigned int V_56 , struct V_3 * * V_55 )
{
struct V_139 V_140 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_56 ) )
return 0 ;
F_178 () ;
F_194 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_123 , * V_3 ;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
continue;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
V_55 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_56 )
break;
}
F_184 () ;
return V_33 ;
}
unsigned F_197 ( struct V_1 * V_2 , T_2 V_9 ,
unsigned int V_56 , struct V_3 * * V_55 )
{
struct V_139 V_140 ;
void * * V_7 ;
unsigned int V_33 = 0 ;
if ( F_27 ( ! V_56 ) )
return 0 ;
F_178 () ;
F_198 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_123 , * V_3 ;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
break;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
break;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( V_3 -> V_2 == NULL || F_187 ( V_3 ) != V_140 . V_9 ) {
F_52 ( V_3 ) ;
break;
}
V_55 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_56 )
break;
}
F_184 () ;
return V_33 ;
}
unsigned F_199 ( struct V_1 * V_2 , T_2 * V_9 ,
int V_142 , unsigned int V_56 , struct V_3 * * V_55 )
{
struct V_139 V_140 ;
void * * V_7 ;
unsigned V_33 = 0 ;
if ( F_27 ( ! V_56 ) )
return 0 ;
F_178 () ;
F_200 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_123 , * V_3 ;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
continue;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
V_55 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_56 )
break;
}
F_184 () ;
if ( V_33 )
* V_9 = V_55 [ V_33 - 1 ] -> V_9 + 1 ;
return V_33 ;
}
unsigned F_201 ( struct V_1 * V_2 , T_2 V_38 ,
int V_142 , unsigned int V_136 ,
struct V_3 * * V_137 , T_2 * V_138 )
{
void * * V_7 ;
unsigned int V_33 = 0 ;
struct V_139 V_140 ;
if ( ! V_136 )
return 0 ;
F_178 () ;
F_200 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_123 , * V_3 ;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
continue;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
goto V_141;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
V_141:
V_138 [ V_33 ] = V_140 . V_9 ;
V_137 [ V_33 ] = V_3 ;
if ( ++ V_33 == V_136 )
break;
}
F_184 () ;
return V_33 ;
}
static void F_202 ( struct V_66 * V_143 ,
struct V_144 * V_145 )
{
V_145 -> V_146 /= 4 ;
}
static T_8 F_203 ( struct V_66 * V_143 , T_1 * V_147 ,
struct V_148 * V_140 , T_8 V_149 )
{
struct V_1 * V_2 = V_143 -> V_69 ;
struct V_150 * V_150 = V_2 -> V_29 ;
struct V_144 * V_145 = & V_143 -> V_151 ;
T_2 V_9 ;
T_2 V_152 ;
T_2 V_153 ;
unsigned long V_74 ;
unsigned int V_154 ;
int error = 0 ;
if ( F_27 ( * V_147 >= V_150 -> V_155 -> V_156 ) )
return 0 ;
F_204 ( V_140 , V_150 -> V_155 -> V_156 ) ;
V_9 = * V_147 >> V_52 ;
V_153 = V_145 -> V_157 >> V_52 ;
V_154 = V_145 -> V_157 & ( V_158 - 1 ) ;
V_152 = ( * V_147 + V_140 -> V_159 + V_158 - 1 ) >> V_52 ;
V_74 = * V_147 & ~ V_160 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_161 ;
T_1 V_162 ;
unsigned long V_19 , V_33 ;
F_75 () ;
V_163:
if ( F_205 ( V_22 ) ) {
error = - V_105 ;
goto V_125;
}
V_3 = F_206 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
F_207 ( V_2 ,
V_145 , V_143 ,
V_9 , V_152 - V_9 ) ;
V_3 = F_206 ( V_2 , V_9 ) ;
if ( F_27 ( V_3 == NULL ) )
goto V_164;
}
if ( F_208 ( V_3 ) ) {
F_209 ( V_2 ,
V_145 , V_143 , V_3 ,
V_9 , V_152 - V_9 ) ;
}
if ( ! F_21 ( V_3 ) ) {
error = F_172 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_165;
if ( F_21 ( V_3 ) )
goto V_166;
if ( V_150 -> V_167 == V_52 ||
! V_2 -> V_31 -> V_168 )
goto V_169;
if ( F_27 ( V_140 -> type & V_170 ) )
goto V_169;
if ( ! F_189 ( V_3 ) )
goto V_169;
if ( ! V_3 -> V_2 )
goto V_171;
if ( ! V_2 -> V_31 -> V_168 ( V_3 ,
V_74 , V_140 -> V_159 ) )
goto V_171;
F_153 ( V_3 ) ;
}
V_166:
V_162 = F_78 ( V_150 ) ;
V_161 = ( V_162 - 1 ) >> V_52 ;
if ( F_27 ( ! V_162 || V_9 > V_161 ) ) {
F_52 ( V_3 ) ;
goto V_125;
}
V_19 = V_158 ;
if ( V_9 == V_161 ) {
V_19 = ( ( V_162 - 1 ) & ~ V_160 ) + 1 ;
if ( V_19 <= V_74 ) {
F_52 ( V_3 ) ;
goto V_125;
}
}
V_19 = V_19 - V_74 ;
if ( F_210 ( V_2 ) )
F_211 ( V_3 ) ;
if ( V_153 != V_9 || V_74 != V_154 )
F_190 ( V_3 ) ;
V_153 = V_9 ;
V_33 = F_212 ( V_3 , V_74 , V_19 , V_140 ) ;
V_74 += V_33 ;
V_9 += V_74 >> V_52 ;
V_74 &= ~ V_160 ;
V_154 = V_74 ;
F_52 ( V_3 ) ;
V_149 += V_33 ;
if ( ! F_213 ( V_140 ) )
goto V_125;
if ( V_33 < V_19 ) {
error = - V_172 ;
goto V_125;
}
continue;
V_169:
error = F_214 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_165;
V_171:
if ( ! V_3 -> V_2 ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
continue;
}
if ( F_21 ( V_3 ) ) {
F_153 ( V_3 ) ;
goto V_166;
}
V_173:
F_74 ( V_3 ) ;
error = V_2 -> V_31 -> V_173 ( V_143 , V_3 ) ;
if ( F_27 ( error ) ) {
if ( error == V_174 ) {
F_52 ( V_3 ) ;
error = 0 ;
goto V_163;
}
goto V_165;
}
if ( ! F_21 ( V_3 ) ) {
error = F_214 ( V_3 ) ;
if ( F_27 ( error ) )
goto V_165;
if ( ! F_21 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_163;
}
F_153 ( V_3 ) ;
F_202 ( V_143 , V_145 ) ;
error = - V_37 ;
goto V_165;
}
F_153 ( V_3 ) ;
}
goto V_166;
V_165:
F_52 ( V_3 ) ;
goto V_125;
V_164:
V_3 = F_215 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_175 ;
goto V_125;
}
error = F_108 ( V_3 , V_2 , V_9 ,
F_216 ( V_2 , V_176 ) ) ;
if ( error ) {
F_52 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_163;
}
goto V_125;
}
goto V_173;
}
V_125:
V_145 -> V_157 = V_153 ;
V_145 -> V_157 <<= V_52 ;
V_145 -> V_157 |= V_154 ;
* V_147 = ( ( T_1 ) V_9 << V_52 ) + V_74 ;
F_217 ( V_143 ) ;
return V_149 ? V_149 : error ;
}
T_8
F_218 ( struct V_177 * V_178 , struct V_148 * V_140 )
{
struct V_66 * V_66 = V_178 -> V_179 ;
T_8 V_180 = 0 ;
T_9 V_159 = F_213 ( V_140 ) ;
if ( ! V_159 )
goto V_125;
if ( V_178 -> V_181 & V_182 ) {
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_150 * V_150 = V_2 -> V_29 ;
T_1 V_183 ;
V_183 = F_78 ( V_150 ) ;
if ( V_178 -> V_181 & V_184 ) {
if ( F_66 ( V_2 , V_178 -> V_185 ,
V_178 -> V_185 + V_159 - 1 ) )
return - V_186 ;
} else {
V_180 = F_81 ( V_2 ,
V_178 -> V_185 ,
V_178 -> V_185 + V_159 - 1 ) ;
if ( V_180 < 0 )
goto V_125;
}
F_217 ( V_66 ) ;
V_180 = V_2 -> V_31 -> V_187 ( V_178 , V_140 ) ;
if ( V_180 >= 0 ) {
V_178 -> V_185 += V_180 ;
V_159 -= V_180 ;
}
F_219 ( V_140 , V_159 - F_213 ( V_140 ) ) ;
if ( V_180 < 0 || ! V_159 || V_178 -> V_185 >= V_183 ||
F_220 ( V_150 ) )
goto V_125;
}
V_180 = F_203 ( V_66 , & V_178 -> V_185 , V_140 , V_180 ) ;
V_125:
return V_180 ;
}
static int F_221 ( struct V_66 * V_66 , T_2 V_74 , T_4 V_72 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_3 * V_3 ;
int V_33 ;
do {
V_3 = F_116 ( V_72 | V_188 ) ;
if ( ! V_3 )
return - V_175 ;
V_33 = F_108 ( V_3 , V_2 , V_74 , V_72 & V_176 ) ;
if ( V_33 == 0 )
V_33 = V_2 -> V_31 -> V_173 ( V_66 , V_3 ) ;
else if ( V_33 == - V_12 )
V_33 = 0 ;
F_52 ( V_3 ) ;
} while ( V_33 == V_174 );
return V_33 ;
}
static void F_222 ( struct V_189 * V_190 ,
struct V_144 * V_145 ,
struct V_66 * V_66 ,
T_2 V_74 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
if ( V_190 -> V_191 & V_192 )
return;
if ( ! V_145 -> V_146 )
return;
if ( V_190 -> V_191 & V_193 ) {
F_207 ( V_2 , V_145 , V_66 , V_74 ,
V_145 -> V_146 ) ;
return;
}
if ( V_145 -> V_194 < V_195 * 10 )
V_145 -> V_194 ++ ;
if ( V_145 -> V_194 > V_195 )
return;
V_145 -> V_38 = F_223 ( long , 0 , V_74 - V_145 -> V_146 / 2 ) ;
V_145 -> V_183 = V_145 -> V_146 ;
V_145 -> V_196 = V_145 -> V_146 / 4 ;
F_224 ( V_145 , V_2 , V_66 ) ;
}
static void F_225 ( struct V_189 * V_190 ,
struct V_144 * V_145 ,
struct V_66 * V_66 ,
struct V_3 * V_3 ,
T_2 V_74 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
if ( V_190 -> V_191 & V_192 )
return;
if ( V_145 -> V_194 > 0 )
V_145 -> V_194 -- ;
if ( F_208 ( V_3 ) )
F_209 ( V_2 , V_145 , V_66 ,
V_3 , V_74 , V_145 -> V_146 ) ;
}
int F_226 ( struct V_197 * V_198 )
{
int error ;
struct V_66 * V_66 = V_198 -> V_190 -> V_199 ;
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_144 * V_145 = & V_66 -> V_151 ;
struct V_150 * V_150 = V_2 -> V_29 ;
T_2 V_74 = V_198 -> V_200 ;
T_2 V_201 ;
struct V_3 * V_3 ;
int V_33 = 0 ;
V_201 = F_227 ( F_78 ( V_150 ) , V_158 ) ;
if ( F_27 ( V_74 >= V_201 ) )
return V_202 ;
V_3 = F_206 ( V_2 , V_74 ) ;
if ( F_139 ( V_3 ) && ! ( V_198 -> V_30 & V_203 ) ) {
F_225 ( V_198 -> V_190 , V_145 , V_66 , V_3 , V_74 ) ;
} else if ( ! V_3 ) {
F_222 ( V_198 -> V_190 , V_145 , V_66 , V_74 ) ;
F_228 ( V_204 ) ;
F_229 ( V_198 -> V_190 -> V_205 , V_204 ) ;
V_33 = V_206 ;
V_207:
V_3 = F_206 ( V_2 , V_74 ) ;
if ( ! V_3 )
goto V_164;
}
if ( ! F_230 ( V_3 , V_198 -> V_190 -> V_205 , V_198 -> V_30 ) ) {
F_52 ( V_3 ) ;
return V_33 | V_208 ;
}
if ( F_27 ( V_3 -> V_2 != V_2 ) ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_207;
}
F_13 ( V_3 -> V_9 != V_74 , V_3 ) ;
if ( F_27 ( ! F_21 ( V_3 ) ) )
goto V_209;
V_201 = F_227 ( F_78 ( V_150 ) , V_158 ) ;
if ( F_27 ( V_74 >= V_201 ) ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
return V_202 ;
}
V_198 -> V_3 = V_3 ;
return V_33 | V_210 ;
V_164:
error = F_221 ( V_66 , V_74 , V_198 -> V_72 ) ;
if ( error >= 0 )
goto V_207;
if ( error == - V_175 )
return V_211 ;
return V_202 ;
V_209:
F_74 ( V_3 ) ;
error = V_2 -> V_31 -> V_173 ( V_66 , V_3 ) ;
if ( ! error ) {
F_173 ( V_3 ) ;
if ( ! F_21 ( V_3 ) )
error = - V_37 ;
}
F_52 ( V_3 ) ;
if ( ! error || error == V_174 )
goto V_207;
F_202 ( V_66 , V_145 ) ;
return V_202 ;
}
void F_231 ( struct V_197 * V_198 ,
T_2 V_212 , T_2 V_213 )
{
struct V_139 V_140 ;
void * * V_7 ;
struct V_66 * V_66 = V_198 -> V_190 -> V_199 ;
struct V_1 * V_2 = V_66 -> V_69 ;
T_2 V_214 = V_212 ;
unsigned long V_215 ;
struct V_3 * V_123 , * V_3 ;
F_178 () ;
F_194 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_140 . V_9 > V_213 )
break;
V_124:
V_3 = F_180 ( V_7 ) ;
if ( F_27 ( ! V_3 ) )
goto V_216;
if ( F_181 ( V_3 ) ) {
if ( F_182 ( V_3 ) ) {
V_7 = F_195 ( & V_140 ) ;
continue;
}
goto V_216;
}
V_123 = F_155 ( V_3 ) ;
if ( ! F_183 ( V_123 ) )
goto V_124;
if ( F_155 ( V_3 ) != V_123 ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( F_27 ( V_3 != * V_7 ) ) {
F_52 ( V_123 ) ;
goto V_124;
}
if ( ! F_21 ( V_3 ) ||
F_208 ( V_3 ) ||
F_232 ( V_3 ) )
goto V_217;
if ( ! F_189 ( V_3 ) )
goto V_217;
if ( V_3 -> V_2 != V_2 || ! F_21 ( V_3 ) )
goto V_218;
V_215 = F_227 ( F_78 ( V_2 -> V_29 ) , V_158 ) ;
if ( V_3 -> V_9 >= V_215 )
goto V_218;
if ( V_66 -> V_151 . V_194 > 0 )
V_66 -> V_151 . V_194 -- ;
V_198 -> V_219 += ( V_140 . V_9 - V_214 ) << V_52 ;
if ( V_198 -> V_220 )
V_198 -> V_220 += V_140 . V_9 - V_214 ;
V_214 = V_140 . V_9 ;
if ( F_233 ( V_198 , NULL , V_3 ) )
goto V_218;
F_153 ( V_3 ) ;
goto V_216;
V_218:
F_153 ( V_3 ) ;
V_217:
F_52 ( V_3 ) ;
V_216:
if ( F_234 ( * V_198 -> V_221 ) )
break;
if ( V_140 . V_9 == V_213 )
break;
}
F_184 () ;
}
int F_235 ( struct V_197 * V_198 )
{
struct V_3 * V_3 = V_198 -> V_3 ;
struct V_150 * V_150 = F_236 ( V_198 -> V_190 -> V_199 ) ;
int V_33 = V_210 ;
F_237 ( V_150 -> V_155 ) ;
F_238 ( V_198 -> V_190 -> V_199 ) ;
F_186 ( V_3 ) ;
if ( V_3 -> V_2 != V_150 -> V_222 ) {
F_153 ( V_3 ) ;
V_33 = V_223 ;
goto V_125;
}
F_239 ( V_3 ) ;
F_240 ( V_3 ) ;
V_125:
F_241 ( V_150 -> V_155 ) ;
return V_33 ;
}
int F_242 ( struct V_66 * V_66 , struct V_189 * V_190 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
if ( ! V_2 -> V_31 -> V_173 )
return - V_224 ;
F_217 ( V_66 ) ;
V_190 -> V_225 = & V_226 ;
return 0 ;
}
int F_243 ( struct V_66 * V_66 , struct V_189 * V_190 )
{
if ( ( V_190 -> V_191 & V_227 ) && ( V_190 -> V_191 & V_228 ) )
return - V_229 ;
return F_242 ( V_66 , V_190 ) ;
}
int F_242 ( struct V_66 * V_66 , struct V_189 * V_190 )
{
return - V_230 ;
}
int F_243 ( struct V_66 * V_66 , struct V_189 * V_190 )
{
return - V_230 ;
}
static struct V_3 * F_244 ( struct V_3 * V_3 )
{
if ( ! F_245 ( V_3 ) ) {
F_173 ( V_3 ) ;
if ( ! F_21 ( V_3 ) ) {
F_52 ( V_3 ) ;
V_3 = F_246 ( - V_37 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_247 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_248)( void * , struct V_3 * ) ,
void * V_231 ,
T_4 V_81 )
{
struct V_3 * V_3 ;
int V_60 ;
V_124:
V_3 = F_206 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_116 ( V_81 | V_188 ) ;
if ( ! V_3 )
return F_246 ( - V_175 ) ;
V_60 = F_108 ( V_3 , V_2 , V_9 , V_81 ) ;
if ( F_27 ( V_60 ) ) {
F_52 ( V_3 ) ;
if ( V_60 == - V_12 )
goto V_124;
return F_246 ( V_60 ) ;
}
F_248:
V_60 = F_248 ( V_231 , V_3 ) ;
if ( V_60 < 0 ) {
F_52 ( V_3 ) ;
return F_246 ( V_60 ) ;
}
V_3 = F_244 ( V_3 ) ;
if ( F_245 ( V_3 ) )
return V_3 ;
goto V_125;
}
if ( F_21 ( V_3 ) )
goto V_125;
F_173 ( V_3 ) ;
if ( F_21 ( V_3 ) )
goto V_125;
F_186 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_153 ( V_3 ) ;
F_52 ( V_3 ) ;
goto V_124;
}
if ( F_21 ( V_3 ) ) {
F_153 ( V_3 ) ;
goto V_125;
}
goto F_248;
V_125:
F_190 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_249 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_248)( void * , struct V_3 * ) ,
void * V_231 )
{
return F_247 ( V_2 , V_9 , F_248 , V_231 , F_250 ( V_2 ) ) ;
}
struct V_3 * F_251 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_4 V_81 )
{
T_10 * F_248 = ( T_10 * ) V_2 -> V_31 -> V_173 ;
return F_247 ( V_2 , V_9 , F_248 , NULL , V_81 ) ;
}
inline T_8 F_252 ( struct V_177 * V_178 , struct V_148 * V_232 )
{
struct V_66 * V_66 = V_178 -> V_179 ;
struct V_150 * V_150 = V_66 -> V_69 -> V_29 ;
unsigned long V_233 = F_253 ( V_234 ) ;
T_1 V_235 ;
if ( ! F_213 ( V_232 ) )
return 0 ;
if ( V_178 -> V_181 & V_236 )
V_178 -> V_185 = F_78 ( V_150 ) ;
V_235 = V_178 -> V_185 ;
if ( ( V_178 -> V_181 & V_184 ) && ! ( V_178 -> V_181 & V_182 ) )
return - V_229 ;
if ( V_233 != V_237 ) {
if ( V_178 -> V_185 >= V_233 ) {
F_254 ( V_238 , V_22 , 0 ) ;
return - V_239 ;
}
F_204 ( V_232 , V_233 - ( unsigned long ) V_235 ) ;
}
if ( F_27 ( V_235 + F_213 ( V_232 ) > V_240 &&
! ( V_66 -> V_241 & V_242 ) ) ) {
if ( V_235 >= V_240 )
return - V_239 ;
F_204 ( V_232 , V_240 - ( unsigned long ) V_235 ) ;
}
if ( F_27 ( V_235 >= V_150 -> V_155 -> V_156 ) )
return - V_239 ;
F_204 ( V_232 , V_150 -> V_155 -> V_156 - V_235 ) ;
return F_213 ( V_232 ) ;
}
int F_255 ( struct V_66 * V_66 , struct V_1 * V_2 ,
T_1 V_235 , unsigned V_243 , unsigned V_30 ,
struct V_3 * * V_122 , void * * V_244 )
{
const struct V_245 * V_246 = V_2 -> V_31 ;
return V_246 -> V_247 ( V_66 , V_2 , V_235 , V_243 , V_30 ,
V_122 , V_244 ) ;
}
int F_256 ( struct V_66 * V_66 , struct V_1 * V_2 ,
T_1 V_235 , unsigned V_243 , unsigned V_248 ,
struct V_3 * V_3 , void * V_244 )
{
const struct V_245 * V_246 = V_2 -> V_31 ;
return V_246 -> V_249 ( V_66 , V_2 , V_235 , V_243 , V_248 , V_3 , V_244 ) ;
}
T_8
F_257 ( struct V_177 * V_178 , struct V_148 * V_232 )
{
struct V_66 * V_66 = V_178 -> V_179 ;
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_150 * V_150 = V_2 -> V_29 ;
T_1 V_235 = V_178 -> V_185 ;
T_8 V_149 ;
T_9 V_250 ;
T_2 V_39 ;
V_250 = F_213 ( V_232 ) ;
V_39 = ( V_235 + V_250 - 1 ) >> V_52 ;
if ( V_178 -> V_181 & V_184 ) {
if ( F_66 ( V_150 -> V_222 , V_235 ,
V_235 + F_213 ( V_232 ) ) )
return - V_186 ;
} else {
V_149 = F_81 ( V_2 , V_235 ,
V_235 + V_250 - 1 ) ;
if ( V_149 )
goto V_125;
}
V_149 = F_258 ( V_2 ,
V_235 >> V_52 , V_39 ) ;
if ( V_149 ) {
if ( V_149 == - V_251 )
return 0 ;
goto V_125;
}
V_149 = V_2 -> V_31 -> V_187 ( V_178 , V_232 ) ;
F_258 ( V_2 ,
V_235 >> V_52 , V_39 ) ;
if ( V_149 > 0 ) {
V_235 += V_149 ;
V_250 -= V_149 ;
if ( V_235 > F_78 ( V_150 ) && ! F_259 ( V_150 -> V_252 ) ) {
F_260 ( V_150 , V_235 ) ;
F_261 ( V_150 ) ;
}
V_178 -> V_185 = V_235 ;
}
F_219 ( V_232 , V_250 - F_213 ( V_232 ) ) ;
V_125:
return V_149 ;
}
struct V_3 * F_262 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_30 )
{
struct V_3 * V_3 ;
int V_126 = V_128 | V_132 | V_131 ;
if ( V_30 & V_253 )
V_126 |= V_133 ;
V_3 = F_188 ( V_2 , V_9 , V_126 ,
F_250 ( V_2 ) ) ;
if ( V_3 )
F_240 ( V_3 ) ;
return V_3 ;
}
T_8 F_263 ( struct V_66 * V_66 ,
struct V_148 * V_18 , T_1 V_235 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
const struct V_245 * V_31 = V_2 -> V_31 ;
long V_254 = 0 ;
T_8 V_149 = 0 ;
unsigned int V_30 = 0 ;
do {
struct V_3 * V_3 ;
unsigned long V_74 ;
unsigned long V_255 ;
T_9 V_248 ;
void * V_244 ;
V_74 = ( V_235 & ( V_158 - 1 ) ) ;
V_255 = F_264 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_256:
if ( F_27 ( F_265 ( V_18 , V_255 ) ) ) {
V_254 = - V_172 ;
break;
}
if ( F_205 ( V_22 ) ) {
V_254 = - V_105 ;
break;
}
V_254 = V_31 -> V_247 ( V_66 , V_2 , V_235 , V_255 , V_30 ,
& V_3 , & V_244 ) ;
if ( F_27 ( V_254 < 0 ) )
break;
if ( F_210 ( V_2 ) )
F_211 ( V_3 ) ;
V_248 = F_266 ( V_3 , V_18 , V_74 , V_255 ) ;
F_211 ( V_3 ) ;
V_254 = V_31 -> V_249 ( V_66 , V_2 , V_235 , V_255 , V_248 ,
V_3 , V_244 ) ;
if ( F_27 ( V_254 < 0 ) )
break;
V_248 = V_254 ;
F_75 () ;
F_267 ( V_18 , V_248 ) ;
if ( F_27 ( V_248 == 0 ) ) {
V_255 = F_264 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_256;
}
V_235 += V_248 ;
V_149 += V_248 ;
F_268 ( V_2 ) ;
} while ( F_213 ( V_18 ) );
return V_149 ? V_149 : V_254 ;
}
T_8 F_269 ( struct V_177 * V_178 , struct V_148 * V_232 )
{
struct V_66 * V_66 = V_178 -> V_179 ;
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_150 * V_150 = V_2 -> V_29 ;
T_8 V_149 = 0 ;
T_8 V_60 ;
T_8 V_254 ;
V_22 -> V_257 = F_270 ( V_150 ) ;
V_60 = F_271 ( V_66 ) ;
if ( V_60 )
goto V_125;
V_60 = F_238 ( V_66 ) ;
if ( V_60 )
goto V_125;
if ( V_178 -> V_181 & V_182 ) {
T_1 V_235 , V_258 ;
V_149 = F_257 ( V_178 , V_232 ) ;
if ( V_149 < 0 || ! F_213 ( V_232 ) || F_220 ( V_150 ) )
goto V_125;
V_254 = F_263 ( V_66 , V_232 , V_235 = V_178 -> V_185 ) ;
if ( F_27 ( V_254 < 0 ) ) {
V_60 = V_254 ;
goto V_125;
}
V_258 = V_235 + V_254 - 1 ;
V_60 = F_81 ( V_2 , V_235 , V_258 ) ;
if ( V_60 == 0 ) {
V_178 -> V_185 = V_258 + 1 ;
V_149 += V_254 ;
F_272 ( V_2 ,
V_235 >> V_52 ,
V_258 >> V_52 ) ;
} else {
}
} else {
V_149 = F_263 ( V_66 , V_232 , V_178 -> V_185 ) ;
if ( F_139 ( V_149 > 0 ) )
V_178 -> V_185 += V_149 ;
}
V_125:
V_22 -> V_257 = NULL ;
return V_149 ? V_149 : V_60 ;
}
T_8 F_273 ( struct V_177 * V_178 , struct V_148 * V_232 )
{
struct V_66 * V_66 = V_178 -> V_179 ;
struct V_150 * V_150 = V_66 -> V_69 -> V_29 ;
T_8 V_33 ;
F_274 ( V_150 ) ;
V_33 = F_252 ( V_178 , V_232 ) ;
if ( V_33 > 0 )
V_33 = F_269 ( V_178 , V_232 ) ;
F_275 ( V_150 ) ;
if ( V_33 > 0 )
V_33 = F_276 ( V_178 , V_33 ) ;
return V_33 ;
}
int F_277 ( struct V_3 * V_3 , T_4 V_72 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_49 ( ! F_14 ( V_3 ) ) ;
if ( F_278 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_31 -> V_259 )
return V_2 -> V_31 -> V_259 ( V_3 , V_72 ) ;
return F_279 ( V_3 ) ;
}
