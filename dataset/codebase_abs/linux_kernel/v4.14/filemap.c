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
if ( V_4 )
* V_4 = V_10 ;
}
F_5 ( & V_2 -> V_8 , V_6 , V_7 , V_3 ,
V_14 , V_2 ) ;
V_2 -> V_15 ++ ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * V_16 )
{
int V_17 , V_18 ;
V_18 = F_7 ( V_3 ) ? 1 : F_8 ( V_3 ) ;
F_9 ( ! F_10 ( V_3 ) , V_3 ) ;
F_9 ( F_11 ( V_3 ) , V_3 ) ;
F_9 ( V_18 != 1 && V_16 , V_3 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
struct V_5 * V_6 ;
void * * V_7 ;
F_12 ( & V_2 -> V_8 , V_3 -> V_9 + V_17 ,
& V_6 , & V_7 ) ;
F_9 ( ! V_6 && V_18 != 1 , V_3 ) ;
F_13 ( & V_2 -> V_8 , V_6 , V_7 ) ;
F_5 ( & V_2 -> V_8 , V_6 , V_7 , V_16 ,
V_14 , V_2 ) ;
}
if ( V_16 ) {
V_2 -> V_13 += V_18 ;
F_14 () ;
}
V_2 -> V_15 -= V_18 ;
}
void F_15 ( struct V_3 * V_3 , void * V_16 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_18 = F_8 ( V_3 ) ;
F_16 ( V_3 ) ;
if ( F_17 ( V_3 ) && F_18 ( V_3 ) )
F_19 ( V_3 ) ;
else
F_20 ( V_2 , V_3 ) ;
F_9 ( F_11 ( V_3 ) , V_3 ) ;
F_9 ( F_21 ( V_3 ) , V_3 ) ;
if ( ! F_22 ( V_19 ) && F_23 ( F_21 ( V_3 ) ) ) {
int V_20 ;
F_24 ( L_1 ,
V_21 -> V_22 , F_25 ( V_3 ) ) ;
F_26 ( V_3 , L_2 ) ;
F_27 () ;
F_28 ( V_23 , V_24 ) ;
V_20 = F_29 ( V_3 ) ;
if ( F_30 ( V_2 ) &&
F_31 ( V_3 ) >= V_20 + 2 ) {
F_32 ( V_3 ) ;
F_33 ( V_3 , V_20 ) ;
}
}
F_6 ( V_2 , V_3 , V_16 ) ;
V_3 -> V_2 = NULL ;
if ( F_7 ( V_3 ) )
return;
F_34 ( F_35 ( V_3 ) , V_25 , - V_18 ) ;
if ( F_36 ( V_3 ) ) {
F_34 ( F_35 ( V_3 ) , V_26 , - V_18 ) ;
if ( F_37 ( V_3 ) )
F_38 ( V_3 , V_27 ) ;
} else {
F_9 ( F_37 ( V_3 ) , V_3 ) ;
}
if ( F_39 ( F_40 ( V_3 ) ) )
F_41 ( V_3 , V_2 , F_42 ( V_2 -> V_28 ) ) ;
}
void F_43 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_44 ( V_3 ) ;
unsigned long V_29 ;
void (* F_45)( struct V_3 * );
F_46 ( ! F_10 ( V_3 ) ) ;
F_45 = V_2 -> V_30 -> F_45 ;
F_47 ( & V_2 -> V_11 , V_29 ) ;
F_15 ( V_3 , NULL ) ;
F_48 ( & V_2 -> V_11 , V_29 ) ;
if ( F_45 )
F_45 ( V_3 ) ;
if ( F_37 ( V_3 ) && ! F_7 ( V_3 ) ) {
F_33 ( V_3 , V_31 ) ;
F_9 ( F_31 ( V_3 ) <= 0 , V_3 ) ;
} else {
F_49 ( V_3 ) ;
}
}
int F_50 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
if ( F_51 ( V_33 , & V_2 -> V_29 ) &&
F_52 ( V_33 , & V_2 -> V_29 ) )
V_32 = - V_34 ;
if ( F_51 ( V_35 , & V_2 -> V_29 ) &&
F_52 ( V_35 , & V_2 -> V_29 ) )
V_32 = - V_36 ;
return V_32 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( F_51 ( V_35 , & V_2 -> V_29 ) )
return - V_36 ;
if ( F_51 ( V_33 , & V_2 -> V_29 ) )
return - V_34 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_37 ,
T_1 V_38 , int V_39 )
{
int V_32 ;
struct V_40 V_41 = {
. V_39 = V_39 ,
. V_42 = V_43 ,
. V_44 = V_37 ,
. V_45 = V_38 ,
} ;
if ( ! F_55 ( V_2 ) )
return 0 ;
F_56 ( & V_41 , V_2 -> V_28 ) ;
V_32 = F_57 ( V_2 , & V_41 ) ;
F_58 ( & V_41 ) ;
return V_32 ;
}
static inline int F_59 ( struct V_1 * V_2 ,
int V_39 )
{
return F_54 ( V_2 , 0 , V_46 , V_39 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , V_47 ) ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_37 ,
T_1 V_38 )
{
return F_54 ( V_2 , V_37 , V_38 , V_47 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , V_48 ) ;
}
bool F_63 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_50 )
{
T_2 V_9 = V_49 >> V_51 ;
T_2 V_38 = V_50 >> V_51 ;
struct V_3 * V_3 ;
if ( V_50 < V_49 )
return false ;
if ( V_2 -> V_15 == 0 )
return false ;
if ( ! F_64 ( V_2 , & V_9 , V_38 , 1 , & V_3 ) )
return false ;
F_49 ( V_3 ) ;
return true ;
}
static void F_65 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_50 )
{
T_2 V_9 = V_49 >> V_51 ;
T_2 V_38 = V_50 >> V_51 ;
struct V_52 V_53 ;
int V_54 ;
if ( V_50 < V_49 )
return;
F_66 ( & V_53 , 0 ) ;
while ( ( V_9 <= V_38 ) &&
( V_54 = F_67 ( & V_53 , V_2 , & V_9 ,
V_55 ,
F_68 ( V_38 - V_9 , ( T_2 ) V_56 - 1 ) + 1 ) ) != 0 ) {
unsigned V_17 ;
for ( V_17 = 0 ; V_17 < V_54 ; V_17 ++ ) {
struct V_3 * V_3 = V_53 . V_57 [ V_17 ] ;
if ( V_3 -> V_9 > V_38 )
continue;
F_69 ( V_3 ) ;
F_70 ( V_3 ) ;
}
F_71 ( & V_53 ) ;
F_72 () ;
}
}
int F_73 ( struct V_1 * V_2 , T_1 V_49 ,
T_1 V_50 )
{
F_65 ( V_2 , V_49 , V_50 ) ;
return F_50 ( V_2 ) ;
}
int F_74 ( struct V_58 * V_58 , T_1 V_49 , T_1 V_50 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_65 ( V_2 , V_49 , V_50 ) ;
return F_75 ( V_58 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
F_65 ( V_2 , 0 , V_46 ) ;
return F_53 ( V_2 ) ;
}
static bool F_77 ( struct V_1 * V_2 )
{
return ( ! F_78 ( V_2 ) && V_2 -> V_15 ) ||
( F_78 ( V_2 ) && V_2 -> V_13 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
if ( F_77 ( V_2 ) ) {
V_60 = F_60 ( V_2 ) ;
if ( V_60 != - V_36 ) {
int V_61 = F_80 ( V_2 ) ;
if ( ! V_60 )
V_60 = V_61 ;
} else {
F_50 ( V_2 ) ;
}
} else {
V_60 = F_50 ( V_2 ) ;
}
return V_60 ;
}
int F_81 ( struct V_1 * V_2 ,
T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 ;
if ( F_77 ( V_2 ) ) {
V_60 = F_54 ( V_2 , V_62 , V_63 ,
V_47 ) ;
if ( V_60 != - V_36 ) {
int V_61 = F_73 ( V_2 ,
V_62 , V_63 ) ;
if ( ! V_60 )
V_60 = V_61 ;
} else {
F_50 ( V_2 ) ;
}
} else {
V_60 = F_50 ( V_2 ) ;
}
return V_60 ;
}
void F_82 ( struct V_1 * V_2 , int V_60 )
{
T_3 V_64 = F_83 ( & V_2 -> V_65 , V_60 ) ;
F_84 ( V_2 , V_64 ) ;
}
int F_75 ( struct V_58 * V_58 )
{
int V_60 = 0 ;
T_3 V_66 = F_85 ( V_58 -> V_67 ) ;
struct V_1 * V_2 = V_58 -> V_59 ;
if ( F_86 ( & V_2 -> V_65 , V_66 ) ) {
F_87 ( & V_58 -> V_68 ) ;
V_66 = V_58 -> V_67 ;
V_60 = F_88 ( & V_2 -> V_65 ,
& V_58 -> V_67 ) ;
F_89 ( V_58 , V_66 ) ;
F_90 ( & V_58 -> V_68 ) ;
}
F_91 ( V_35 , & V_2 -> V_29 ) ;
F_91 ( V_33 , & V_2 -> V_29 ) ;
return V_60 ;
}
int F_92 ( struct V_58 * V_58 , T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 , V_61 ;
struct V_1 * V_2 = V_58 -> V_59 ;
if ( F_77 ( V_2 ) ) {
V_60 = F_54 ( V_2 , V_62 , V_63 ,
V_47 ) ;
if ( V_60 != - V_36 )
F_65 ( V_2 , V_62 , V_63 ) ;
}
V_61 = F_75 ( V_58 ) ;
if ( ! V_60 )
V_60 = V_61 ;
return V_60 ;
}
int F_93 ( struct V_3 * V_66 , struct V_3 * V_69 , T_4 V_70 )
{
int error ;
F_9 ( ! F_10 ( V_66 ) , V_66 ) ;
F_9 ( ! F_10 ( V_69 ) , V_69 ) ;
F_9 ( V_69 -> V_2 , V_69 ) ;
error = F_94 ( V_70 & ~ V_71 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_66 -> V_2 ;
void (* F_45)( struct V_3 * );
unsigned long V_29 ;
T_2 V_72 = V_66 -> V_9 ;
F_45 = V_2 -> V_30 -> F_45 ;
F_95 ( V_69 ) ;
V_69 -> V_2 = V_2 ;
V_69 -> V_9 = V_72 ;
F_47 ( & V_2 -> V_11 , V_29 ) ;
F_15 ( V_66 , NULL ) ;
error = F_1 ( V_2 , V_69 , NULL ) ;
F_46 ( error ) ;
if ( ! F_7 ( V_69 ) )
F_96 ( V_69 , V_25 ) ;
if ( F_36 ( V_69 ) )
F_96 ( V_69 , V_26 ) ;
F_48 ( & V_2 -> V_11 , V_29 ) ;
F_97 ( V_66 , V_69 ) ;
F_98 () ;
if ( F_45 )
F_45 ( V_66 ) ;
F_49 ( V_66 ) ;
}
return error ;
}
static int F_99 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_72 , T_4 V_70 ,
void * * V_4 )
{
int V_73 = F_7 ( V_3 ) ;
struct V_74 * V_75 ;
int error ;
F_9 ( ! F_10 ( V_3 ) , V_3 ) ;
F_9 ( F_36 ( V_3 ) , V_3 ) ;
if ( ! V_73 ) {
error = F_100 ( V_3 , V_21 -> V_76 ,
V_70 , & V_75 , false ) ;
if ( error )
return error ;
}
error = F_101 ( V_70 & ~ V_71 ) ;
if ( error ) {
if ( ! V_73 )
F_102 ( V_3 , V_75 , false ) ;
return error ;
}
F_95 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = V_72 ;
F_103 ( & V_2 -> V_11 ) ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
F_98 () ;
if ( F_23 ( error ) )
goto V_77;
if ( ! V_73 )
F_96 ( V_3 , V_25 ) ;
F_104 ( & V_2 -> V_11 ) ;
if ( ! V_73 )
F_105 ( V_3 , V_75 , false , false ) ;
F_106 ( V_3 ) ;
return 0 ;
V_77:
V_3 -> V_2 = NULL ;
F_104 ( & V_2 -> V_11 ) ;
if ( ! V_73 )
F_102 ( V_3 , V_75 , false ) ;
F_49 ( V_3 ) ;
return error ;
}
int F_107 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_72 , T_4 V_70 )
{
return F_99 ( V_3 , V_2 , V_72 ,
V_70 , NULL ) ;
}
int F_108 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_72 , T_4 V_70 )
{
void * V_16 = NULL ;
int V_32 ;
F_109 ( V_3 ) ;
V_32 = F_99 ( V_3 , V_2 , V_72 ,
V_70 , & V_16 ) ;
if ( F_23 ( V_32 ) )
F_110 ( V_3 ) ;
else {
if ( ! ( V_70 & V_78 ) &&
V_16 && F_111 ( V_16 ) ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
} else
F_114 ( V_3 ) ;
F_115 ( V_3 ) ;
}
return V_32 ;
}
struct V_3 * F_116 ( T_4 V_79 )
{
int V_80 ;
struct V_3 * V_3 ;
if ( F_117 () ) {
unsigned int V_81 ;
do {
V_81 = F_118 () ;
V_80 = F_119 () ;
V_3 = F_120 ( V_80 , V_79 , 0 ) ;
} while ( ! V_3 && F_121 ( V_81 ) );
return V_3 ;
}
return F_122 ( V_79 , 0 ) ;
}
static T_5 * F_123 ( struct V_3 * V_3 )
{
return & V_82 [ F_124 ( V_3 , V_83 ) ] ;
}
void T_6 F_125 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_84 ; V_17 ++ )
F_126 ( & V_82 [ V_17 ] ) ;
F_127 () ;
}
static int F_128 ( T_7 * V_85 , unsigned V_86 , int V_87 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
struct V_91 * V_92
= F_129 ( V_85 , struct V_91 , V_85 ) ;
if ( V_92 -> V_3 != V_90 -> V_3 )
return 0 ;
V_90 -> V_93 = 1 ;
if ( V_92 -> V_94 != V_90 -> V_94 )
return 0 ;
if ( F_51 ( V_90 -> V_94 , & V_90 -> V_3 -> V_29 ) )
return - 1 ;
return F_130 ( V_85 , V_86 , V_87 , V_90 ) ;
}
static void F_131 ( struct V_3 * V_3 , int V_94 )
{
T_5 * V_95 = F_123 ( V_3 ) ;
struct V_89 V_90 ;
unsigned long V_29 ;
T_7 V_96 ;
V_90 . V_3 = V_3 ;
V_90 . V_94 = V_94 ;
V_90 . V_93 = 0 ;
V_96 . V_29 = 0 ;
V_96 . V_97 = NULL ;
V_96 . V_98 = NULL ;
F_132 ( & V_96 . V_99 ) ;
F_47 ( & V_95 -> V_100 , V_29 ) ;
F_133 ( V_95 , V_101 , & V_90 , & V_96 ) ;
while ( V_96 . V_29 & V_102 ) {
F_48 ( & V_95 -> V_100 , V_29 ) ;
F_134 () ;
F_47 ( & V_95 -> V_100 , V_29 ) ;
F_133 ( V_95 , V_101 , & V_90 , & V_96 ) ;
}
if ( ! F_135 ( V_95 ) || ! V_90 . V_93 ) {
F_136 ( V_3 ) ;
}
F_48 ( & V_95 -> V_100 , V_29 ) ;
}
static void F_137 ( struct V_3 * V_3 , int V_103 )
{
if ( ! F_138 ( V_3 ) )
return;
F_131 ( V_3 , V_103 ) ;
}
static inline int F_139 ( T_5 * V_95 ,
struct V_3 * V_3 , int V_94 , int V_104 , bool V_100 )
{
struct V_91 V_92 ;
T_7 * V_85 = & V_92 . V_85 ;
int V_32 = 0 ;
F_140 ( V_85 ) ;
V_85 -> V_29 = V_100 ? V_105 : 0 ;
V_85 -> V_98 = F_128 ;
V_92 . V_3 = V_3 ;
V_92 . V_94 = V_94 ;
for (; ; ) {
F_103 ( & V_95 -> V_100 ) ;
if ( F_141 ( F_142 ( & V_85 -> V_99 ) ) ) {
F_143 ( V_95 , V_85 ) ;
F_144 ( V_3 ) ;
}
F_145 ( V_104 ) ;
F_104 ( & V_95 -> V_100 ) ;
if ( F_141 ( F_51 ( V_94 , & V_3 -> V_29 ) ) ) {
F_146 () ;
}
if ( V_100 ) {
if ( ! F_147 ( V_94 , & V_3 -> V_29 ) )
break;
} else {
if ( ! F_51 ( V_94 , & V_3 -> V_29 ) )
break;
}
if ( F_23 ( F_148 ( V_104 , V_21 ) ) ) {
V_32 = - V_106 ;
break;
}
}
F_149 ( V_95 , V_85 ) ;
return V_32 ;
}
void F_150 ( struct V_3 * V_3 , int V_94 )
{
T_5 * V_95 = F_123 ( V_3 ) ;
F_139 ( V_95 , V_3 , V_94 , V_107 , false ) ;
}
int F_151 ( struct V_3 * V_3 , int V_94 )
{
T_5 * V_95 = F_123 ( V_3 ) ;
return F_139 ( V_95 , V_3 , V_94 , V_108 , false ) ;
}
void F_152 ( struct V_3 * V_3 , T_7 * V_109 )
{
T_5 * V_95 = F_123 ( V_3 ) ;
unsigned long V_29 ;
F_47 ( & V_95 -> V_100 , V_29 ) ;
F_143 ( V_95 , V_109 ) ;
F_144 ( V_3 ) ;
F_48 ( & V_95 -> V_100 , V_29 ) ;
}
static inline bool F_153 ( long V_18 , volatile void * V_110 )
{
F_154 ( V_18 , V_110 ) ;
return F_51 ( V_111 , V_110 ) ;
}
void F_155 ( struct V_3 * V_3 )
{
F_156 ( V_111 != 7 ) ;
V_3 = F_157 ( V_3 ) ;
F_9 ( ! F_10 ( V_3 ) , V_3 ) ;
if ( F_153 ( V_112 , & V_3 -> V_29 ) )
F_131 ( V_3 , V_112 ) ;
}
void F_158 ( struct V_3 * V_3 )
{
if ( F_159 ( V_3 ) ) {
F_160 ( V_3 ) ;
F_161 ( V_3 ) ;
}
if ( ! F_162 ( V_3 ) )
F_163 () ;
F_164 () ;
F_137 ( V_3 , V_113 ) ;
}
void F_165 ( struct V_3 * V_3 , bool V_114 , int V_60 )
{
if ( ! V_114 ) {
if ( ! V_60 ) {
F_166 ( V_3 ) ;
} else {
F_167 ( V_3 ) ;
F_168 ( V_3 ) ;
}
F_155 ( V_3 ) ;
} else {
if ( V_60 ) {
struct V_1 * V_2 ;
F_168 ( V_3 ) ;
V_2 = F_44 ( V_3 ) ;
if ( V_2 )
F_169 ( V_2 , V_60 ) ;
}
F_158 ( V_3 ) ;
}
}
void F_170 ( struct V_3 * V_115 )
{
struct V_3 * V_3 = F_157 ( V_115 ) ;
T_5 * V_95 = F_123 ( V_3 ) ;
F_139 ( V_95 , V_3 , V_112 , V_107 , true ) ;
}
int F_171 ( struct V_3 * V_115 )
{
struct V_3 * V_3 = F_157 ( V_115 ) ;
T_5 * V_95 = F_123 ( V_3 ) ;
return F_139 ( V_95 , V_3 , V_112 , V_108 , true ) ;
}
int F_172 ( struct V_3 * V_3 , struct V_116 * V_76 ,
unsigned int V_29 )
{
if ( V_29 & V_117 ) {
if ( V_29 & V_118 )
return 0 ;
F_173 ( & V_76 -> V_119 ) ;
if ( V_29 & V_120 )
F_174 ( V_3 ) ;
else
F_175 ( V_3 ) ;
return 0 ;
} else {
if ( V_29 & V_120 ) {
int V_32 ;
V_32 = F_171 ( V_3 ) ;
if ( V_32 ) {
F_173 ( & V_76 -> V_119 ) ;
return 0 ;
}
} else
F_170 ( V_3 ) ;
return 1 ;
}
}
T_2 F_176 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_121 )
{
unsigned long V_17 ;
for ( V_17 = 0 ; V_17 < V_121 ; V_17 ++ ) {
struct V_3 * V_3 ;
V_3 = F_177 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 ++ ;
if ( V_9 == 0 )
break;
}
return V_9 ;
}
T_2 F_178 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned long V_121 )
{
unsigned long V_17 ;
for ( V_17 = 0 ; V_17 < V_121 ; V_17 ++ ) {
struct V_3 * V_3 ;
V_3 = F_177 ( & V_2 -> V_8 , V_9 ) ;
if ( ! V_3 || F_4 ( V_3 ) )
break;
V_9 -- ;
if ( V_9 == V_122 )
break;
}
return V_9 ;
}
struct V_3 * F_179 ( struct V_1 * V_2 , T_2 V_72 )
{
void * * V_123 ;
struct V_3 * V_124 , * V_3 ;
F_180 () ;
V_125:
V_3 = NULL ;
V_123 = F_181 ( & V_2 -> V_8 , V_72 ) ;
if ( V_123 ) {
V_3 = F_182 ( V_123 ) ;
if ( F_23 ( ! V_3 ) )
goto V_126;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) )
goto V_125;
goto V_126;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_123 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
}
V_126:
F_186 () ;
return V_3 ;
}
struct V_3 * F_187 ( struct V_1 * V_2 , T_2 V_72 )
{
struct V_3 * V_3 ;
V_125:
V_3 = F_179 ( V_2 , V_72 ) ;
if ( V_3 && ! F_183 ( V_3 ) ) {
F_188 ( V_3 ) ;
if ( F_23 ( F_44 ( V_3 ) != V_2 ) ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_125;
}
F_9 ( F_189 ( V_3 ) != V_72 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_190 ( struct V_1 * V_2 , T_2 V_72 ,
int V_127 , T_4 V_70 )
{
struct V_3 * V_3 ;
V_125:
V_3 = F_179 ( V_2 , V_72 ) ;
if ( F_4 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_128;
if ( V_127 & V_129 ) {
if ( V_127 & V_130 ) {
if ( ! F_191 ( V_3 ) ) {
F_49 ( V_3 ) ;
return NULL ;
}
} else {
F_188 ( V_3 ) ;
}
if ( F_23 ( V_3 -> V_2 != V_2 ) ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_125;
}
F_9 ( V_3 -> V_9 != V_72 , V_3 ) ;
}
if ( V_3 && ( V_127 & V_131 ) )
F_192 ( V_3 ) ;
V_128:
if ( ! V_3 && ( V_127 & V_132 ) ) {
int V_60 ;
if ( ( V_127 & V_133 ) && F_193 ( V_2 ) )
V_70 |= V_78 ;
if ( V_127 & V_134 )
V_70 &= ~ V_135 ;
V_3 = F_116 ( V_70 ) ;
if ( ! V_3 )
return NULL ;
if ( F_39 ( ! ( V_127 & V_129 ) ) )
V_127 |= V_129 ;
if ( V_127 & V_131 )
F_194 ( V_3 ) ;
V_60 = F_108 ( V_3 , V_2 , V_72 ,
V_70 & V_136 ) ;
if ( F_23 ( V_60 ) ) {
F_49 ( V_3 ) ;
V_3 = NULL ;
if ( V_60 == - V_12 )
goto V_125;
}
}
return V_3 ;
}
unsigned F_195 ( struct V_1 * V_2 ,
T_2 V_37 , unsigned int V_137 ,
struct V_3 * * V_138 , T_2 * V_139 )
{
void * * V_7 ;
unsigned int V_32 = 0 ;
struct V_140 V_141 ;
if ( ! V_137 )
return 0 ;
F_180 () ;
F_196 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_124 , * V_3 ;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
continue;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
goto V_142;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
V_142:
V_139 [ V_32 ] = V_141 . V_9 ;
V_138 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_137 )
break;
}
F_186 () ;
return V_32 ;
}
unsigned F_64 ( struct V_1 * V_2 , T_2 * V_37 ,
T_2 V_38 , unsigned int V_54 ,
struct V_3 * * V_57 )
{
struct V_140 V_141 ;
void * * V_7 ;
unsigned V_32 = 0 ;
if ( F_23 ( ! V_54 ) )
return 0 ;
F_180 () ;
F_196 (slot, &mapping->page_tree, &iter, *start) {
struct V_3 * V_124 , * V_3 ;
if ( V_141 . V_9 > V_38 )
break;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
continue;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
continue;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
V_57 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_54 ) {
* V_37 = V_57 [ V_32 - 1 ] -> V_9 + 1 ;
goto V_126;
}
}
if ( V_38 == ( T_2 ) - 1 )
* V_37 = ( T_2 ) - 1 ;
else
* V_37 = V_38 + 1 ;
V_126:
F_186 () ;
return V_32 ;
}
unsigned F_198 ( struct V_1 * V_2 , T_2 V_9 ,
unsigned int V_54 , struct V_3 * * V_57 )
{
struct V_140 V_141 ;
void * * V_7 ;
unsigned int V_32 = 0 ;
if ( F_23 ( ! V_54 ) )
return 0 ;
F_180 () ;
F_199 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_124 , * V_3 ;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
break;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
break;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( V_3 -> V_2 == NULL || F_189 ( V_3 ) != V_141 . V_9 ) {
F_49 ( V_3 ) ;
break;
}
V_57 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_54 )
break;
}
F_186 () ;
return V_32 ;
}
unsigned F_200 ( struct V_1 * V_2 , T_2 * V_9 ,
int V_143 , unsigned int V_54 , struct V_3 * * V_57 )
{
struct V_140 V_141 ;
void * * V_7 ;
unsigned V_32 = 0 ;
if ( F_23 ( ! V_54 ) )
return 0 ;
F_180 () ;
F_201 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_124 , * V_3 ;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
continue;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
continue;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
V_57 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_54 )
break;
}
F_186 () ;
if ( V_32 )
* V_9 = V_57 [ V_32 - 1 ] -> V_9 + 1 ;
return V_32 ;
}
unsigned F_202 ( struct V_1 * V_2 , T_2 V_37 ,
int V_143 , unsigned int V_137 ,
struct V_3 * * V_138 , T_2 * V_139 )
{
void * * V_7 ;
unsigned int V_32 = 0 ;
struct V_140 V_141 ;
if ( ! V_137 )
return 0 ;
F_180 () ;
F_201 (slot, &mapping->page_tree,
&iter, start, tag) {
struct V_3 * V_124 , * V_3 ;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
continue;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
goto V_142;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
V_142:
V_139 [ V_32 ] = V_141 . V_9 ;
V_138 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_137 )
break;
}
F_186 () ;
return V_32 ;
}
static void F_203 ( struct V_58 * V_144 ,
struct V_145 * V_146 )
{
V_146 -> V_147 /= 4 ;
}
static T_8 F_204 ( struct V_148 * V_149 ,
struct V_150 * V_141 , T_8 V_151 )
{
struct V_58 * V_144 = V_149 -> V_152 ;
struct V_1 * V_2 = V_144 -> V_59 ;
struct V_153 * V_153 = V_2 -> V_28 ;
struct V_145 * V_146 = & V_144 -> V_154 ;
T_1 * V_155 = & V_149 -> V_156 ;
T_2 V_9 ;
T_2 V_157 ;
T_2 V_158 ;
unsigned long V_72 ;
unsigned int V_159 ;
int error = 0 ;
if ( F_23 ( * V_155 >= V_153 -> V_160 -> V_161 ) )
return 0 ;
F_205 ( V_141 , V_153 -> V_160 -> V_161 ) ;
V_9 = * V_155 >> V_51 ;
V_158 = V_146 -> V_162 >> V_51 ;
V_159 = V_146 -> V_162 & ( V_163 - 1 ) ;
V_157 = ( * V_155 + V_141 -> V_164 + V_163 - 1 ) >> V_51 ;
V_72 = * V_155 & ~ V_165 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_166 ;
T_1 V_167 ;
unsigned long V_18 , V_32 ;
F_72 () ;
V_168:
if ( F_206 ( V_21 ) ) {
error = - V_106 ;
goto V_126;
}
V_3 = F_207 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
if ( V_149 -> V_169 & V_170 )
goto V_171;
F_208 ( V_2 ,
V_146 , V_144 ,
V_9 , V_157 - V_9 ) ;
V_3 = F_207 ( V_2 , V_9 ) ;
if ( F_23 ( V_3 == NULL ) )
goto V_172;
}
if ( F_209 ( V_3 ) ) {
F_210 ( V_2 ,
V_146 , V_144 , V_3 ,
V_9 , V_157 - V_9 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_149 -> V_169 & V_170 ) {
F_49 ( V_3 ) ;
goto V_171;
}
error = F_174 ( V_3 ) ;
if ( F_23 ( error ) )
goto V_173;
if ( F_17 ( V_3 ) )
goto V_174;
if ( V_153 -> V_175 == V_51 ||
! V_2 -> V_30 -> V_176 )
goto V_177;
if ( F_23 ( V_141 -> type & V_178 ) )
goto V_177;
if ( ! F_191 ( V_3 ) )
goto V_177;
if ( ! V_3 -> V_2 )
goto V_179;
if ( ! V_2 -> V_30 -> V_176 ( V_3 ,
V_72 , V_141 -> V_164 ) )
goto V_179;
F_155 ( V_3 ) ;
}
V_174:
V_167 = F_211 ( V_153 ) ;
V_166 = ( V_167 - 1 ) >> V_51 ;
if ( F_23 ( ! V_167 || V_9 > V_166 ) ) {
F_49 ( V_3 ) ;
goto V_126;
}
V_18 = V_163 ;
if ( V_9 == V_166 ) {
V_18 = ( ( V_167 - 1 ) & ~ V_165 ) + 1 ;
if ( V_18 <= V_72 ) {
F_49 ( V_3 ) ;
goto V_126;
}
}
V_18 = V_18 - V_72 ;
if ( F_212 ( V_2 ) )
F_213 ( V_3 ) ;
if ( V_158 != V_9 || V_72 != V_159 )
F_192 ( V_3 ) ;
V_158 = V_9 ;
V_32 = F_214 ( V_3 , V_72 , V_18 , V_141 ) ;
V_72 += V_32 ;
V_9 += V_72 >> V_51 ;
V_72 &= ~ V_165 ;
V_159 = V_72 ;
F_49 ( V_3 ) ;
V_151 += V_32 ;
if ( ! F_215 ( V_141 ) )
goto V_126;
if ( V_32 < V_18 ) {
error = - V_180 ;
goto V_126;
}
continue;
V_177:
error = F_216 ( V_3 ) ;
if ( F_23 ( error ) )
goto V_173;
V_179:
if ( ! V_3 -> V_2 ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_155 ( V_3 ) ;
goto V_174;
}
V_181:
F_70 ( V_3 ) ;
error = V_2 -> V_30 -> V_181 ( V_144 , V_3 ) ;
if ( F_23 ( error ) ) {
if ( error == V_182 ) {
F_49 ( V_3 ) ;
error = 0 ;
goto V_168;
}
goto V_173;
}
if ( ! F_17 ( V_3 ) ) {
error = F_216 ( V_3 ) ;
if ( F_23 ( error ) )
goto V_173;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_168;
}
F_155 ( V_3 ) ;
F_203 ( V_144 , V_146 ) ;
error = - V_36 ;
goto V_173;
}
F_155 ( V_3 ) ;
}
goto V_174;
V_173:
F_49 ( V_3 ) ;
goto V_126;
V_172:
V_3 = F_217 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_183 ;
goto V_126;
}
error = F_108 ( V_3 , V_2 , V_9 ,
F_218 ( V_2 , V_184 ) ) ;
if ( error ) {
F_49 ( V_3 ) ;
if ( error == - V_12 ) {
error = 0 ;
goto V_168;
}
goto V_126;
}
goto V_181;
}
V_171:
error = - V_185 ;
V_126:
V_146 -> V_162 = V_158 ;
V_146 -> V_162 <<= V_51 ;
V_146 -> V_162 |= V_159 ;
* V_155 = ( ( T_1 ) V_9 << V_51 ) + V_72 ;
F_219 ( V_144 ) ;
return V_151 ? V_151 : error ;
}
T_8
F_220 ( struct V_148 * V_149 , struct V_150 * V_141 )
{
T_9 V_164 = F_215 ( V_141 ) ;
T_8 V_186 = 0 ;
if ( ! V_164 )
goto V_126;
if ( V_149 -> V_169 & V_187 ) {
struct V_58 * V_58 = V_149 -> V_152 ;
struct V_1 * V_2 = V_58 -> V_59 ;
struct V_153 * V_153 = V_2 -> V_28 ;
T_1 V_188 ;
V_188 = F_211 ( V_153 ) ;
if ( V_149 -> V_169 & V_170 ) {
if ( F_63 ( V_2 , V_149 -> V_156 ,
V_149 -> V_156 + V_164 - 1 ) )
return - V_185 ;
} else {
V_186 = F_81 ( V_2 ,
V_149 -> V_156 ,
V_149 -> V_156 + V_164 - 1 ) ;
if ( V_186 < 0 )
goto V_126;
}
F_219 ( V_58 ) ;
V_186 = V_2 -> V_30 -> V_189 ( V_149 , V_141 ) ;
if ( V_186 >= 0 ) {
V_149 -> V_156 += V_186 ;
V_164 -= V_186 ;
}
F_221 ( V_141 , V_164 - F_215 ( V_141 ) ) ;
if ( V_186 < 0 || ! V_164 || V_149 -> V_156 >= V_188 ||
F_222 ( V_153 ) )
goto V_126;
}
V_186 = F_204 ( V_149 , V_141 , V_186 ) ;
V_126:
return V_186 ;
}
static int F_223 ( struct V_58 * V_58 , T_2 V_72 , T_4 V_70 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
struct V_3 * V_3 ;
int V_32 ;
do {
V_3 = F_116 ( V_70 | V_190 ) ;
if ( ! V_3 )
return - V_183 ;
V_32 = F_108 ( V_3 , V_2 , V_72 , V_70 & V_184 ) ;
if ( V_32 == 0 )
V_32 = V_2 -> V_30 -> V_181 ( V_58 , V_3 ) ;
else if ( V_32 == - V_12 )
V_32 = 0 ;
F_49 ( V_3 ) ;
} while ( V_32 == V_182 );
return V_32 ;
}
static void F_224 ( struct V_191 * V_192 ,
struct V_145 * V_146 ,
struct V_58 * V_58 ,
T_2 V_72 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
if ( V_192 -> V_193 & V_194 )
return;
if ( ! V_146 -> V_147 )
return;
if ( V_192 -> V_193 & V_195 ) {
F_208 ( V_2 , V_146 , V_58 , V_72 ,
V_146 -> V_147 ) ;
return;
}
if ( V_146 -> V_196 < V_197 * 10 )
V_146 -> V_196 ++ ;
if ( V_146 -> V_196 > V_197 )
return;
V_146 -> V_37 = F_225 ( long , 0 , V_72 - V_146 -> V_147 / 2 ) ;
V_146 -> V_188 = V_146 -> V_147 ;
V_146 -> V_198 = V_146 -> V_147 / 4 ;
F_226 ( V_146 , V_2 , V_58 ) ;
}
static void F_227 ( struct V_191 * V_192 ,
struct V_145 * V_146 ,
struct V_58 * V_58 ,
struct V_3 * V_3 ,
T_2 V_72 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
if ( V_192 -> V_193 & V_194 )
return;
if ( V_146 -> V_196 > 0 )
V_146 -> V_196 -- ;
if ( F_209 ( V_3 ) )
F_210 ( V_2 , V_146 , V_58 ,
V_3 , V_72 , V_146 -> V_147 ) ;
}
int F_228 ( struct V_199 * V_200 )
{
int error ;
struct V_58 * V_58 = V_200 -> V_192 -> V_201 ;
struct V_1 * V_2 = V_58 -> V_59 ;
struct V_145 * V_146 = & V_58 -> V_154 ;
struct V_153 * V_153 = V_2 -> V_28 ;
T_2 V_72 = V_200 -> V_202 ;
T_2 V_203 ;
struct V_3 * V_3 ;
int V_32 = 0 ;
V_203 = F_229 ( F_211 ( V_153 ) , V_163 ) ;
if ( F_23 ( V_72 >= V_203 ) )
return V_204 ;
V_3 = F_207 ( V_2 , V_72 ) ;
if ( F_141 ( V_3 ) && ! ( V_200 -> V_29 & V_205 ) ) {
F_227 ( V_200 -> V_192 , V_146 , V_58 , V_3 , V_72 ) ;
} else if ( ! V_3 ) {
F_224 ( V_200 -> V_192 , V_146 , V_58 , V_72 ) ;
F_230 ( V_206 ) ;
F_231 ( V_200 -> V_192 -> V_207 , V_206 ) ;
V_32 = V_208 ;
V_209:
V_3 = F_207 ( V_2 , V_72 ) ;
if ( ! V_3 )
goto V_172;
}
if ( ! F_232 ( V_3 , V_200 -> V_192 -> V_207 , V_200 -> V_29 ) ) {
F_49 ( V_3 ) ;
return V_32 | V_210 ;
}
if ( F_23 ( V_3 -> V_2 != V_2 ) ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_209;
}
F_9 ( V_3 -> V_9 != V_72 , V_3 ) ;
if ( F_23 ( ! F_17 ( V_3 ) ) )
goto V_211;
V_203 = F_229 ( F_211 ( V_153 ) , V_163 ) ;
if ( F_23 ( V_72 >= V_203 ) ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
return V_204 ;
}
V_200 -> V_3 = V_3 ;
return V_32 | V_212 ;
V_172:
error = F_223 ( V_58 , V_72 , V_200 -> V_70 ) ;
if ( error >= 0 )
goto V_209;
if ( error == - V_183 )
return V_213 ;
return V_204 ;
V_211:
F_70 ( V_3 ) ;
error = V_2 -> V_30 -> V_181 ( V_58 , V_3 ) ;
if ( ! error ) {
F_175 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_36 ;
}
F_49 ( V_3 ) ;
if ( ! error || error == V_182 )
goto V_209;
F_203 ( V_58 , V_146 ) ;
return V_204 ;
}
void F_233 ( struct V_199 * V_200 ,
T_2 V_214 , T_2 V_215 )
{
struct V_140 V_141 ;
void * * V_7 ;
struct V_58 * V_58 = V_200 -> V_192 -> V_201 ;
struct V_1 * V_2 = V_58 -> V_59 ;
T_2 V_216 = V_214 ;
unsigned long V_217 ;
struct V_3 * V_124 , * V_3 ;
F_180 () ;
F_196 (slot, &mapping->page_tree, &iter,
start_pgoff) {
if ( V_141 . V_9 > V_215 )
break;
V_125:
V_3 = F_182 ( V_7 ) ;
if ( F_23 ( ! V_3 ) )
goto V_218;
if ( F_183 ( V_3 ) ) {
if ( F_184 ( V_3 ) ) {
V_7 = F_197 ( & V_141 ) ;
continue;
}
goto V_218;
}
V_124 = F_157 ( V_3 ) ;
if ( ! F_185 ( V_124 ) )
goto V_125;
if ( F_157 ( V_3 ) != V_124 ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( F_23 ( V_3 != * V_7 ) ) {
F_49 ( V_124 ) ;
goto V_125;
}
if ( ! F_17 ( V_3 ) ||
F_209 ( V_3 ) ||
F_234 ( V_3 ) )
goto V_219;
if ( ! F_191 ( V_3 ) )
goto V_219;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_220;
V_217 = F_229 ( F_211 ( V_2 -> V_28 ) , V_163 ) ;
if ( V_3 -> V_9 >= V_217 )
goto V_220;
if ( V_58 -> V_154 . V_196 > 0 )
V_58 -> V_154 . V_196 -- ;
V_200 -> V_221 += ( V_141 . V_9 - V_216 ) << V_51 ;
if ( V_200 -> V_222 )
V_200 -> V_222 += V_141 . V_9 - V_216 ;
V_216 = V_141 . V_9 ;
if ( F_235 ( V_200 , NULL , V_3 ) )
goto V_220;
F_155 ( V_3 ) ;
goto V_218;
V_220:
F_155 ( V_3 ) ;
V_219:
F_49 ( V_3 ) ;
V_218:
if ( F_236 ( * V_200 -> V_223 ) )
break;
if ( V_141 . V_9 == V_215 )
break;
}
F_186 () ;
}
int F_237 ( struct V_199 * V_200 )
{
struct V_3 * V_3 = V_200 -> V_3 ;
struct V_153 * V_153 = F_238 ( V_200 -> V_192 -> V_201 ) ;
int V_32 = V_212 ;
F_239 ( V_153 -> V_160 ) ;
F_240 ( V_200 -> V_192 -> V_201 ) ;
F_188 ( V_3 ) ;
if ( V_3 -> V_2 != V_153 -> V_224 ) {
F_155 ( V_3 ) ;
V_32 = V_225 ;
goto V_126;
}
F_241 ( V_3 ) ;
F_242 ( V_3 ) ;
V_126:
F_243 ( V_153 -> V_160 ) ;
return V_32 ;
}
int F_244 ( struct V_58 * V_58 , struct V_191 * V_192 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
if ( ! V_2 -> V_30 -> V_181 )
return - V_226 ;
F_219 ( V_58 ) ;
V_192 -> V_227 = & V_228 ;
return 0 ;
}
int F_245 ( struct V_58 * V_58 , struct V_191 * V_192 )
{
if ( ( V_192 -> V_193 & V_229 ) && ( V_192 -> V_193 & V_230 ) )
return - V_231 ;
return F_244 ( V_58 , V_192 ) ;
}
int F_244 ( struct V_58 * V_58 , struct V_191 * V_192 )
{
return - V_232 ;
}
int F_245 ( struct V_58 * V_58 , struct V_191 * V_192 )
{
return - V_232 ;
}
static struct V_3 * F_246 ( struct V_3 * V_3 )
{
if ( ! F_247 ( V_3 ) ) {
F_175 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_49 ( V_3 ) ;
V_3 = F_248 ( - V_36 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_249 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_250)( void * , struct V_3 * ) ,
void * V_233 ,
T_4 V_79 )
{
struct V_3 * V_3 ;
int V_60 ;
V_125:
V_3 = F_207 ( V_2 , V_9 ) ;
if ( ! V_3 ) {
V_3 = F_116 ( V_79 | V_190 ) ;
if ( ! V_3 )
return F_248 ( - V_183 ) ;
V_60 = F_108 ( V_3 , V_2 , V_9 , V_79 ) ;
if ( F_23 ( V_60 ) ) {
F_49 ( V_3 ) ;
if ( V_60 == - V_12 )
goto V_125;
return F_248 ( V_60 ) ;
}
F_250:
V_60 = F_250 ( V_233 , V_3 ) ;
if ( V_60 < 0 ) {
F_49 ( V_3 ) ;
return F_248 ( V_60 ) ;
}
V_3 = F_246 ( V_3 ) ;
if ( F_247 ( V_3 ) )
return V_3 ;
goto V_126;
}
if ( F_17 ( V_3 ) )
goto V_126;
F_175 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_126;
F_188 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_155 ( V_3 ) ;
F_49 ( V_3 ) ;
goto V_125;
}
if ( F_17 ( V_3 ) ) {
F_155 ( V_3 ) ;
goto V_126;
}
goto F_250;
V_126:
F_192 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_251 ( struct V_1 * V_2 ,
T_2 V_9 ,
int (* F_250)( void * , struct V_3 * ) ,
void * V_233 )
{
return F_249 ( V_2 , V_9 , F_250 , V_233 , F_252 ( V_2 ) ) ;
}
struct V_3 * F_253 ( struct V_1 * V_2 ,
T_2 V_9 ,
T_4 V_79 )
{
T_10 * F_250 = ( T_10 * ) V_2 -> V_30 -> V_181 ;
return F_249 ( V_2 , V_9 , F_250 , NULL , V_79 ) ;
}
inline T_8 F_254 ( struct V_148 * V_149 , struct V_150 * V_234 )
{
struct V_58 * V_58 = V_149 -> V_152 ;
struct V_153 * V_153 = V_58 -> V_59 -> V_28 ;
unsigned long V_235 = F_255 ( V_236 ) ;
T_1 V_237 ;
if ( ! F_215 ( V_234 ) )
return 0 ;
if ( V_149 -> V_169 & V_238 )
V_149 -> V_156 = F_211 ( V_153 ) ;
V_237 = V_149 -> V_156 ;
if ( ( V_149 -> V_169 & V_170 ) && ! ( V_149 -> V_169 & V_187 ) )
return - V_231 ;
if ( V_235 != V_239 ) {
if ( V_149 -> V_156 >= V_235 ) {
F_256 ( V_240 , V_21 , 0 ) ;
return - V_241 ;
}
F_205 ( V_234 , V_235 - ( unsigned long ) V_237 ) ;
}
if ( F_23 ( V_237 + F_215 ( V_234 ) > V_242 &&
! ( V_58 -> V_243 & V_244 ) ) ) {
if ( V_237 >= V_242 )
return - V_241 ;
F_205 ( V_234 , V_242 - ( unsigned long ) V_237 ) ;
}
if ( F_23 ( V_237 >= V_153 -> V_160 -> V_161 ) )
return - V_241 ;
F_205 ( V_234 , V_153 -> V_160 -> V_161 - V_237 ) ;
return F_215 ( V_234 ) ;
}
int F_257 ( struct V_58 * V_58 , struct V_1 * V_2 ,
T_1 V_237 , unsigned V_245 , unsigned V_29 ,
struct V_3 * * V_123 , void * * V_246 )
{
const struct V_247 * V_248 = V_2 -> V_30 ;
return V_248 -> V_249 ( V_58 , V_2 , V_237 , V_245 , V_29 ,
V_123 , V_246 ) ;
}
int F_258 ( struct V_58 * V_58 , struct V_1 * V_2 ,
T_1 V_237 , unsigned V_245 , unsigned V_250 ,
struct V_3 * V_3 , void * V_246 )
{
const struct V_247 * V_248 = V_2 -> V_30 ;
return V_248 -> V_251 ( V_58 , V_2 , V_237 , V_245 , V_250 , V_3 , V_246 ) ;
}
T_8
F_259 ( struct V_148 * V_149 , struct V_150 * V_234 )
{
struct V_58 * V_58 = V_149 -> V_152 ;
struct V_1 * V_2 = V_58 -> V_59 ;
struct V_153 * V_153 = V_2 -> V_28 ;
T_1 V_237 = V_149 -> V_156 ;
T_8 V_151 ;
T_9 V_252 ;
T_2 V_38 ;
V_252 = F_215 ( V_234 ) ;
V_38 = ( V_237 + V_252 - 1 ) >> V_51 ;
if ( V_149 -> V_169 & V_170 ) {
if ( F_63 ( V_153 -> V_224 , V_237 ,
V_237 + F_215 ( V_234 ) ) )
return - V_185 ;
} else {
V_151 = F_81 ( V_2 , V_237 ,
V_237 + V_252 - 1 ) ;
if ( V_151 )
goto V_126;
}
V_151 = F_260 ( V_2 ,
V_237 >> V_51 , V_38 ) ;
if ( V_151 ) {
if ( V_151 == - V_253 )
return 0 ;
goto V_126;
}
V_151 = V_2 -> V_30 -> V_189 ( V_149 , V_234 ) ;
if ( V_2 -> V_15 )
F_260 ( V_2 ,
V_237 >> V_51 , V_38 ) ;
if ( V_151 > 0 ) {
V_237 += V_151 ;
V_252 -= V_151 ;
if ( V_237 > F_211 ( V_153 ) && ! F_261 ( V_153 -> V_254 ) ) {
F_262 ( V_153 , V_237 ) ;
F_263 ( V_153 ) ;
}
V_149 -> V_156 = V_237 ;
}
F_221 ( V_234 , V_252 - F_215 ( V_234 ) ) ;
V_126:
return V_151 ;
}
struct V_3 * F_264 ( struct V_1 * V_2 ,
T_2 V_9 , unsigned V_29 )
{
struct V_3 * V_3 ;
int V_127 = V_129 | V_133 | V_132 ;
if ( V_29 & V_255 )
V_127 |= V_134 ;
V_3 = F_190 ( V_2 , V_9 , V_127 ,
F_252 ( V_2 ) ) ;
if ( V_3 )
F_242 ( V_3 ) ;
return V_3 ;
}
T_8 F_265 ( struct V_58 * V_58 ,
struct V_150 * V_17 , T_1 V_237 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
const struct V_247 * V_30 = V_2 -> V_30 ;
long V_256 = 0 ;
T_8 V_151 = 0 ;
unsigned int V_29 = 0 ;
do {
struct V_3 * V_3 ;
unsigned long V_72 ;
unsigned long V_257 ;
T_9 V_250 ;
void * V_246 ;
V_72 = ( V_237 & ( V_163 - 1 ) ) ;
V_257 = F_266 (unsigned long, PAGE_SIZE - offset,
iov_iter_count(i)) ;
V_258:
if ( F_23 ( F_267 ( V_17 , V_257 ) ) ) {
V_256 = - V_180 ;
break;
}
if ( F_206 ( V_21 ) ) {
V_256 = - V_106 ;
break;
}
V_256 = V_30 -> V_249 ( V_58 , V_2 , V_237 , V_257 , V_29 ,
& V_3 , & V_246 ) ;
if ( F_23 ( V_256 < 0 ) )
break;
if ( F_212 ( V_2 ) )
F_213 ( V_3 ) ;
V_250 = F_268 ( V_3 , V_17 , V_72 , V_257 ) ;
F_213 ( V_3 ) ;
V_256 = V_30 -> V_251 ( V_58 , V_2 , V_237 , V_257 , V_250 ,
V_3 , V_246 ) ;
if ( F_23 ( V_256 < 0 ) )
break;
V_250 = V_256 ;
F_72 () ;
F_269 ( V_17 , V_250 ) ;
if ( F_23 ( V_250 == 0 ) ) {
V_257 = F_266 (unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_258;
}
V_237 += V_250 ;
V_151 += V_250 ;
F_270 ( V_2 ) ;
} while ( F_215 ( V_17 ) );
return V_151 ? V_151 : V_256 ;
}
T_8 F_271 ( struct V_148 * V_149 , struct V_150 * V_234 )
{
struct V_58 * V_58 = V_149 -> V_152 ;
struct V_1 * V_2 = V_58 -> V_59 ;
struct V_153 * V_153 = V_2 -> V_28 ;
T_8 V_151 = 0 ;
T_8 V_60 ;
T_8 V_256 ;
V_21 -> V_259 = F_272 ( V_153 ) ;
V_60 = F_273 ( V_58 ) ;
if ( V_60 )
goto V_126;
V_60 = F_240 ( V_58 ) ;
if ( V_60 )
goto V_126;
if ( V_149 -> V_169 & V_187 ) {
T_1 V_237 , V_260 ;
V_151 = F_259 ( V_149 , V_234 ) ;
if ( V_151 < 0 || ! F_215 ( V_234 ) || F_222 ( V_153 ) )
goto V_126;
V_256 = F_265 ( V_58 , V_234 , V_237 = V_149 -> V_156 ) ;
if ( F_23 ( V_256 < 0 ) ) {
V_60 = V_256 ;
goto V_126;
}
V_260 = V_237 + V_256 - 1 ;
V_60 = F_81 ( V_2 , V_237 , V_260 ) ;
if ( V_60 == 0 ) {
V_149 -> V_156 = V_260 + 1 ;
V_151 += V_256 ;
F_274 ( V_2 ,
V_237 >> V_51 ,
V_260 >> V_51 ) ;
} else {
}
} else {
V_151 = F_265 ( V_58 , V_234 , V_149 -> V_156 ) ;
if ( F_141 ( V_151 > 0 ) )
V_149 -> V_156 += V_151 ;
}
V_126:
V_21 -> V_259 = NULL ;
return V_151 ? V_151 : V_60 ;
}
T_8 F_275 ( struct V_148 * V_149 , struct V_150 * V_234 )
{
struct V_58 * V_58 = V_149 -> V_152 ;
struct V_153 * V_153 = V_58 -> V_59 -> V_28 ;
T_8 V_32 ;
F_276 ( V_153 ) ;
V_32 = F_254 ( V_149 , V_234 ) ;
if ( V_32 > 0 )
V_32 = F_271 ( V_149 , V_234 ) ;
F_277 ( V_153 ) ;
if ( V_32 > 0 )
V_32 = F_278 ( V_149 , V_32 ) ;
return V_32 ;
}
int F_279 ( struct V_3 * V_3 , T_4 V_70 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_46 ( ! F_10 ( V_3 ) ) ;
if ( F_280 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_30 -> V_261 )
return V_2 -> V_30 -> V_261 ( V_3 , V_70 ) ;
return F_281 ( V_3 ) ;
}
