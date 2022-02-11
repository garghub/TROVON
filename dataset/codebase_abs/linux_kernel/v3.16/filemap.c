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
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 -> V_2 = NULL ;
F_21 ( V_3 , V_22 ) ;
if ( F_22 ( V_3 ) )
F_21 ( V_3 , V_23 ) ;
F_23 ( F_24 ( V_3 ) ) ;
if ( F_25 ( V_3 ) && F_26 ( V_2 ) ) {
F_27 ( V_3 , V_24 ) ;
F_28 ( V_2 -> V_25 , V_26 ) ;
}
}
void F_29 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
void (* F_30)( struct V_3 * );
F_23 ( ! F_3 ( V_3 ) ) ;
F_30 = V_2 -> V_27 -> F_30 ;
F_31 ( & V_2 -> V_28 ) ;
F_15 ( V_3 , NULL ) ;
F_32 ( & V_2 -> V_28 ) ;
F_33 ( V_3 ) ;
if ( F_30 )
F_30 ( V_3 ) ;
F_34 ( V_3 ) ;
}
static int F_35 ( void * V_29 )
{
F_36 () ;
return 0 ;
}
static int F_37 ( void * V_29 )
{
F_35 ( V_29 ) ;
return F_38 ( V_30 ) ? - V_31 : 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
if ( F_7 ( V_33 , & V_2 -> V_34 ) &&
F_40 ( V_33 , & V_2 -> V_34 ) )
V_32 = - V_35 ;
if ( F_7 ( V_36 , & V_2 -> V_34 ) &&
F_40 ( V_36 , & V_2 -> V_34 ) )
V_32 = - V_37 ;
return V_32 ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 , int V_40 )
{
int V_32 ;
struct V_41 V_42 = {
. V_40 = V_40 ,
. V_43 = V_44 ,
. V_45 = V_38 ,
. V_46 = V_39 ,
} ;
if ( ! F_42 ( V_2 ) )
return 0 ;
V_32 = F_43 ( V_2 , & V_42 ) ;
return V_32 ;
}
static inline int F_44 ( struct V_1 * V_2 ,
int V_40 )
{
return F_41 ( V_2 , 0 , V_47 , V_40 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_48 ) ;
}
int F_46 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 )
{
return F_41 ( V_2 , V_38 , V_39 , V_48 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_49 ) ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 )
{
T_2 V_7 = V_50 >> V_52 ;
T_2 V_39 = V_51 >> V_52 ;
struct V_53 V_54 ;
int V_55 ;
int V_56 , V_32 = 0 ;
if ( V_51 < V_50 )
goto V_57;
F_49 ( & V_54 , 0 ) ;
while ( ( V_7 <= V_39 ) &&
( V_55 = F_50 ( & V_54 , V_2 , & V_7 ,
V_58 ,
F_51 ( V_39 - V_7 , ( T_2 ) V_59 - 1 ) + 1 ) ) != 0 ) {
unsigned V_60 ;
for ( V_60 = 0 ; V_60 < V_55 ; V_60 ++ ) {
struct V_3 * V_3 = V_54 . V_61 [ V_60 ] ;
if ( V_3 -> V_7 > V_39 )
continue;
F_52 ( V_3 ) ;
if ( F_53 ( V_3 ) )
V_32 = - V_37 ;
}
F_54 ( & V_54 ) ;
F_55 () ;
}
V_57:
V_56 = F_39 ( V_2 ) ;
if ( ! V_32 )
V_32 = V_56 ;
return V_32 ;
}
int F_56 ( struct V_1 * V_2 )
{
T_1 V_62 = F_57 ( V_2 -> V_63 ) ;
if ( V_62 == 0 )
return 0 ;
return F_48 ( V_2 , 0 , V_62 - 1 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_64 = 0 ;
if ( V_2 -> V_13 ) {
V_64 = F_45 ( V_2 ) ;
if ( V_64 != - V_37 ) {
int V_65 = F_56 ( V_2 ) ;
if ( ! V_64 )
V_64 = V_65 ;
}
} else {
V_64 = F_39 ( V_2 ) ;
}
return V_64 ;
}
int F_59 ( struct V_1 * V_2 ,
T_1 V_66 , T_1 V_67 )
{
int V_64 = 0 ;
if ( V_2 -> V_13 ) {
V_64 = F_41 ( V_2 , V_66 , V_67 ,
V_48 ) ;
if ( V_64 != - V_37 ) {
int V_65 = F_48 ( V_2 ,
V_66 , V_67 ) ;
if ( ! V_64 )
V_64 = V_65 ;
}
} else {
V_64 = F_39 ( V_2 ) ;
}
return V_64 ;
}
int F_60 ( struct V_3 * V_68 , struct V_3 * V_69 , T_3 V_14 )
{
int error ;
F_61 ( ! F_3 ( V_68 ) , V_68 ) ;
F_61 ( ! F_3 ( V_69 ) , V_69 ) ;
F_61 ( V_69 -> V_2 , V_69 ) ;
error = F_62 ( V_14 & ~ V_70 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_68 -> V_2 ;
void (* F_30)( struct V_3 * );
T_2 V_8 = V_68 -> V_7 ;
F_30 = V_2 -> V_27 -> F_30 ;
F_63 ( V_69 ) ;
V_69 -> V_2 = V_2 ;
V_69 -> V_7 = V_8 ;
F_31 ( & V_2 -> V_28 ) ;
F_15 ( V_68 , NULL ) ;
error = F_64 ( & V_2 -> V_11 , V_8 , V_69 ) ;
F_23 ( error ) ;
V_2 -> V_13 ++ ;
F_65 ( V_69 , V_22 ) ;
if ( F_22 ( V_69 ) )
F_65 ( V_69 , V_23 ) ;
F_32 ( & V_2 -> V_28 ) ;
F_66 ( V_68 , V_69 ) ;
F_67 () ;
if ( F_30 )
F_30 ( V_68 ) ;
F_34 ( V_68 ) ;
}
return error ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_71 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_69 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_72 ;
V_72 = F_70 ( V_10 , & V_2 -> V_28 ) ;
if ( ! F_71 ( V_72 ) )
return - V_73 ;
if ( V_71 )
* V_71 = V_72 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_72 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_73 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_74 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_75 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_71 )
{
int error ;
F_61 ( ! F_3 ( V_3 ) , V_3 ) ;
F_61 ( F_22 ( V_3 ) , V_3 ) ;
error = F_76 ( V_3 , V_30 -> V_74 ,
V_14 & V_75 ) ;
if ( error )
return error ;
error = F_77 ( V_14 & ~ V_70 ) ;
if ( error ) {
F_33 ( V_3 ) ;
return error ;
}
F_63 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_31 ( & V_2 -> V_28 ) ;
error = F_68 ( V_2 , V_3 , V_71 ) ;
F_67 () ;
if ( F_78 ( error ) )
goto V_76;
F_65 ( V_3 , V_22 ) ;
F_32 ( & V_2 -> V_28 ) ;
F_79 ( V_3 ) ;
return 0 ;
V_76:
V_3 -> V_2 = NULL ;
F_32 ( & V_2 -> V_28 ) ;
F_33 ( V_3 ) ;
F_34 ( V_3 ) ;
return error ;
}
int F_80 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_75 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_81 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_32 ;
F_82 ( V_3 ) ;
V_32 = F_75 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_78 ( V_32 ) )
F_83 ( V_3 ) ;
else {
if ( V_4 && F_84 ( V_4 ) ) {
F_85 ( V_3 ) ;
F_86 ( V_3 ) ;
} else
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
}
return V_32 ;
}
struct V_3 * F_89 ( T_3 V_77 )
{
int V_78 ;
struct V_3 * V_3 ;
if ( F_90 () ) {
unsigned int V_79 ;
do {
V_79 = F_91 () ;
V_78 = F_92 () ;
V_3 = F_93 ( V_78 , V_77 , 0 ) ;
} while ( ! V_3 && F_94 ( V_79 ) );
return V_3 ;
}
return F_95 ( V_77 , 0 ) ;
}
static T_4 * F_96 ( struct V_3 * V_3 )
{
const struct V_80 * V_80 = F_97 ( V_3 ) ;
return & V_80 -> V_81 [ F_98 ( V_3 , V_80 -> V_82 ) ] ;
}
static inline void F_99 ( struct V_3 * V_3 , int V_83 )
{
F_100 ( F_96 ( V_3 ) , & V_3 -> V_34 , V_83 ) ;
}
void F_101 ( struct V_3 * V_3 , int V_84 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_84 ) ;
if ( F_7 ( V_84 , & V_3 -> V_34 ) )
F_103 ( F_96 ( V_3 ) , & V_85 , F_35 ,
V_86 ) ;
}
int F_104 ( struct V_3 * V_3 , int V_84 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_84 ) ;
if ( ! F_7 ( V_84 , & V_3 -> V_34 ) )
return 0 ;
return F_103 ( F_96 ( V_3 ) , & V_85 ,
F_37 , V_87 ) ;
}
void F_105 ( struct V_3 * V_3 , T_5 * V_88 )
{
T_4 * V_89 = F_96 ( V_3 ) ;
unsigned long V_34 ;
F_106 ( & V_89 -> V_90 , V_34 ) ;
F_107 ( V_89 , V_88 ) ;
F_108 ( & V_89 -> V_90 , V_34 ) ;
}
void F_109 ( struct V_3 * V_3 )
{
F_61 ( ! F_3 ( V_3 ) , V_3 ) ;
F_110 ( V_91 , & V_3 -> V_34 ) ;
F_111 () ;
F_99 ( V_3 , V_91 ) ;
}
void F_112 ( struct V_3 * V_3 )
{
if ( F_113 ( V_3 ) ) {
F_114 ( V_3 ) ;
F_115 ( V_3 ) ;
}
if ( ! F_116 ( V_3 ) )
F_117 () ;
F_111 () ;
F_99 ( V_3 , V_92 ) ;
}
void F_118 ( struct V_3 * V_3 , int V_93 , int V_64 )
{
if ( V_93 == V_94 ) {
if ( ! V_64 ) {
F_119 ( V_3 ) ;
} else {
F_120 ( V_3 ) ;
F_121 ( V_3 ) ;
}
F_109 ( V_3 ) ;
} else {
if ( V_64 ) {
F_121 ( V_3 ) ;
if ( V_3 -> V_2 )
F_122 ( V_3 -> V_2 , V_64 ) ;
}
F_112 ( V_3 ) ;
}
}
void F_123 ( struct V_3 * V_3 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_91 ) ;
F_124 ( F_96 ( V_3 ) , & V_85 , F_35 ,
V_86 ) ;
}
int F_125 ( struct V_3 * V_3 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_91 ) ;
return F_124 ( F_96 ( V_3 ) , & V_85 ,
F_37 , V_87 ) ;
}
int F_126 ( struct V_3 * V_3 , struct V_95 * V_74 ,
unsigned int V_34 )
{
if ( V_34 & V_96 ) {
if ( V_34 & V_97 )
return 0 ;
F_127 ( & V_74 -> V_98 ) ;
if ( V_34 & V_99 )
F_128 ( V_3 ) ;
else
F_129 ( V_3 ) ;
return 0 ;
} else {
if ( V_34 & V_99 ) {
int V_32 ;
V_32 = F_125 ( V_3 ) ;
if ( V_32 ) {
F_127 ( & V_74 -> V_98 ) ;
return 0 ;
}
} else
F_123 ( V_3 ) ;
return 1 ;
}
}
T_2 F_130 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_100 )
{
unsigned long V_60 ;
for ( V_60 = 0 ; V_60 < V_100 ; V_60 ++ ) {
struct V_3 * V_3 ;
V_3 = F_131 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_71 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_132 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_100 )
{
unsigned long V_60 ;
for ( V_60 = 0 ; V_60 < V_100 ; V_60 ++ ) {
struct V_3 * V_3 ;
V_3 = F_131 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_71 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_101 )
break;
}
return V_7 ;
}
struct V_3 * F_133 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_102 ;
struct V_3 * V_3 ;
F_134 () ;
V_103:
V_3 = NULL ;
V_102 = F_135 ( & V_2 -> V_11 , V_8 ) ;
if ( V_102 ) {
V_3 = F_136 ( V_102 ) ;
if ( F_78 ( ! V_3 ) )
goto V_57;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) )
goto V_103;
goto V_57;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_102 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
}
V_57:
F_140 () ;
return V_3 ;
}
struct V_3 * F_141 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_103:
V_3 = F_133 ( V_2 , V_8 ) ;
if ( V_3 && ! F_137 ( V_3 ) ) {
F_142 ( V_3 ) ;
if ( F_78 ( V_3 -> V_2 != V_2 ) ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_103;
}
F_61 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_143 ( struct V_1 * V_2 , T_2 V_8 ,
int V_104 , T_3 V_105 , T_3 V_106 )
{
struct V_3 * V_3 ;
V_103:
V_3 = F_133 ( V_2 , V_8 ) ;
if ( F_71 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_107;
if ( V_104 & V_108 ) {
if ( V_104 & V_109 ) {
if ( ! F_144 ( V_3 ) ) {
F_34 ( V_3 ) ;
return NULL ;
}
} else {
F_142 ( V_3 ) ;
}
if ( F_78 ( V_3 -> V_2 != V_2 ) ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_103;
}
F_61 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_104 & V_110 ) )
F_145 ( V_3 ) ;
V_107:
if ( ! V_3 && ( V_104 & V_111 ) ) {
int V_64 ;
if ( ( V_104 & V_112 ) && F_26 ( V_2 ) )
V_105 |= V_113 ;
if ( V_104 & V_114 ) {
V_105 &= ~ V_115 ;
V_106 &= ~ V_115 ;
}
V_3 = F_89 ( V_105 ) ;
if ( ! V_3 )
return NULL ;
if ( F_146 ( ! ( V_104 & V_108 ) ) )
V_104 |= V_108 ;
if ( V_104 & V_110 )
F_147 ( V_3 ) ;
V_64 = F_81 ( V_3 , V_2 , V_8 , V_106 ) ;
if ( F_78 ( V_64 ) ) {
F_34 ( V_3 ) ;
V_3 = NULL ;
if ( V_64 == - V_73 )
goto V_103;
}
}
return V_3 ;
}
unsigned F_148 ( struct V_1 * V_2 ,
T_2 V_38 , unsigned int V_116 ,
struct V_3 * * V_117 , T_2 * V_118 )
{
void * * V_10 ;
unsigned int V_32 = 0 ;
struct V_119 V_120 ;
if ( ! V_116 )
return 0 ;
F_134 () ;
V_121:
F_149 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_103:
V_3 = F_136 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) )
goto V_121;
goto V_122;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
V_122:
V_118 [ V_32 ] = V_120 . V_7 ;
V_117 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_116 )
break;
}
F_140 () ;
return V_32 ;
}
unsigned F_150 ( struct V_1 * V_2 , T_2 V_38 ,
unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_134 () ;
V_121:
F_149 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_103:
V_3 = F_136 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) ) {
F_151 ( V_120 . V_7 ) ;
goto V_121;
}
continue;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_140 () ;
return V_32 ;
}
unsigned F_152 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned int V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_134 () ;
V_121:
F_153 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_103:
V_3 = F_136 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
break;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) ) {
goto V_121;
}
break;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_120 . V_7 ) {
F_34 ( V_3 ) ;
break;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_140 () ;
return V_32 ;
}
unsigned F_154 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_119 V_120 ;
void * * V_10 ;
unsigned V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_134 () ;
V_121:
F_155 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_103:
V_3 = F_136 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) ) {
goto V_121;
}
continue;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_140 () ;
if ( V_32 )
* V_7 = V_61 [ V_32 - 1 ] -> V_7 + 1 ;
return V_32 ;
}
static void F_156 ( struct V_123 * V_124 ,
struct V_125 * V_126 )
{
V_126 -> V_127 /= 4 ;
}
static T_6 F_157 ( struct V_123 * V_124 , T_1 * V_128 ,
struct V_129 * V_120 , T_6 V_130 )
{
struct V_1 * V_2 = V_124 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_63 ;
struct V_125 * V_126 = & V_124 -> V_133 ;
T_2 V_7 ;
T_2 V_134 ;
T_2 V_135 ;
unsigned long V_8 ;
unsigned int V_136 ;
int error = 0 ;
V_7 = * V_128 >> V_52 ;
V_135 = V_126 -> V_137 >> V_52 ;
V_136 = V_126 -> V_137 & ( V_138 - 1 ) ;
V_134 = ( * V_128 + V_120 -> V_139 + V_138 - 1 ) >> V_52 ;
V_8 = * V_128 & ~ V_140 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_141 ;
T_1 V_142 ;
unsigned long V_143 , V_32 ;
F_55 () ;
V_144:
V_3 = F_158 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_159 ( V_2 ,
V_126 , V_124 ,
V_7 , V_134 - V_7 ) ;
V_3 = F_158 ( V_2 , V_7 ) ;
if ( F_78 ( V_3 == NULL ) )
goto V_145;
}
if ( F_160 ( V_3 ) ) {
F_161 ( V_2 ,
V_126 , V_124 , V_3 ,
V_7 , V_134 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_132 -> V_146 == V_52 ||
! V_2 -> V_27 -> V_147 )
goto V_148;
if ( ! F_144 ( V_3 ) )
goto V_148;
if ( ! V_3 -> V_2 )
goto V_149;
if ( ! V_2 -> V_27 -> V_147 ( V_3 ,
V_8 , V_120 -> V_139 ) )
goto V_149;
F_109 ( V_3 ) ;
}
V_150:
V_142 = F_57 ( V_132 ) ;
V_141 = ( V_142 - 1 ) >> V_52 ;
if ( F_78 ( ! V_142 || V_7 > V_141 ) ) {
F_34 ( V_3 ) ;
goto V_57;
}
V_143 = V_138 ;
if ( V_7 == V_141 ) {
V_143 = ( ( V_142 - 1 ) & ~ V_140 ) + 1 ;
if ( V_143 <= V_8 ) {
F_34 ( V_3 ) ;
goto V_57;
}
}
V_143 = V_143 - V_8 ;
if ( F_162 ( V_2 ) )
F_163 ( V_3 ) ;
if ( V_135 != V_7 || V_8 != V_136 )
F_145 ( V_3 ) ;
V_135 = V_7 ;
V_32 = F_164 ( V_3 , V_8 , V_143 , V_120 ) ;
V_8 += V_32 ;
V_7 += V_8 >> V_52 ;
V_8 &= ~ V_140 ;
V_136 = V_8 ;
F_34 ( V_3 ) ;
V_130 += V_32 ;
if ( ! F_165 ( V_120 ) )
goto V_57;
if ( V_32 < V_143 ) {
error = - V_151 ;
goto V_57;
}
continue;
V_148:
error = F_166 ( V_3 ) ;
if ( F_78 ( error ) )
goto V_152;
V_149:
if ( ! V_3 -> V_2 ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_109 ( V_3 ) ;
goto V_150;
}
V_153:
F_167 ( V_3 ) ;
error = V_2 -> V_27 -> V_153 ( V_124 , V_3 ) ;
if ( F_78 ( error ) ) {
if ( error == V_154 ) {
F_34 ( V_3 ) ;
error = 0 ;
goto V_144;
}
goto V_152;
}
if ( ! F_17 ( V_3 ) ) {
error = F_166 ( V_3 ) ;
if ( F_78 ( error ) )
goto V_152;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_144;
}
F_109 ( V_3 ) ;
F_156 ( V_124 , V_126 ) ;
error = - V_37 ;
goto V_152;
}
F_109 ( V_3 ) ;
}
goto V_150;
V_152:
F_34 ( V_3 ) ;
goto V_57;
V_145:
V_3 = F_168 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_155 ;
goto V_57;
}
error = F_81 ( V_3 , V_2 ,
V_7 , V_156 ) ;
if ( error ) {
F_34 ( V_3 ) ;
if ( error == - V_73 ) {
error = 0 ;
goto V_144;
}
goto V_57;
}
goto V_153;
}
V_57:
V_126 -> V_137 = V_135 ;
V_126 -> V_137 <<= V_52 ;
V_126 -> V_137 |= V_136 ;
* V_128 = ( ( T_1 ) V_7 << V_52 ) + V_8 ;
F_169 ( V_124 ) ;
return V_130 ? V_130 : error ;
}
T_6
F_170 ( struct V_157 * V_158 , struct V_129 * V_120 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
T_6 V_160 = 0 ;
T_1 * V_128 = & V_158 -> V_161 ;
T_1 V_162 = * V_128 ;
if ( V_123 -> V_163 & V_164 ) {
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_63 ;
T_7 V_139 = F_165 ( V_120 ) ;
T_1 V_165 ;
if ( ! V_139 )
goto V_57;
V_165 = F_57 ( V_132 ) ;
V_160 = F_59 ( V_2 , V_162 ,
V_162 + V_139 - 1 ) ;
if ( ! V_160 ) {
struct V_129 V_166 = * V_120 ;
V_160 = V_2 -> V_27 -> V_167 ( V_94 , V_158 , & V_166 , V_162 ) ;
}
if ( V_160 > 0 ) {
* V_128 = V_162 + V_160 ;
F_171 ( V_120 , V_160 ) ;
}
if ( V_160 < 0 || ! F_165 ( V_120 ) || * V_128 >= V_165 ) {
F_169 ( V_123 ) ;
goto V_57;
}
}
V_160 = F_157 ( V_123 , V_128 , V_120 , V_160 ) ;
V_57:
return V_160 ;
}
static int F_172 ( struct V_123 * V_123 , T_2 V_8 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_3 * V_3 ;
int V_32 ;
do {
V_3 = F_168 ( V_2 ) ;
if ( ! V_3 )
return - V_155 ;
V_32 = F_81 ( V_3 , V_2 , V_8 , V_156 ) ;
if ( V_32 == 0 )
V_32 = V_2 -> V_27 -> V_153 ( V_123 , V_3 ) ;
else if ( V_32 == - V_73 )
V_32 = 0 ;
F_34 ( V_3 ) ;
} while ( V_32 == V_154 );
return V_32 ;
}
static void F_173 ( struct V_168 * V_169 ,
struct V_125 * V_126 ,
struct V_123 * V_123 ,
T_2 V_8 )
{
unsigned long V_127 ;
struct V_1 * V_2 = V_123 -> V_131 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( ! V_126 -> V_127 )
return;
if ( V_169 -> V_170 & V_172 ) {
F_159 ( V_2 , V_126 , V_123 , V_8 ,
V_126 -> V_127 ) ;
return;
}
if ( V_126 -> V_173 < V_174 * 10 )
V_126 -> V_173 ++ ;
if ( V_126 -> V_173 > V_174 )
return;
V_127 = F_174 ( V_126 -> V_127 ) ;
V_126 -> V_38 = F_175 ( long , 0 , V_8 - V_127 / 2 ) ;
V_126 -> V_165 = V_127 ;
V_126 -> V_175 = V_127 / 4 ;
F_176 ( V_126 , V_2 , V_123 ) ;
}
static void F_177 ( struct V_168 * V_169 ,
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
if ( F_160 ( V_3 ) )
F_161 ( V_2 , V_126 , V_123 ,
V_3 , V_8 , V_126 -> V_127 ) ;
}
int F_178 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
int error ;
struct V_123 * V_123 = V_169 -> V_178 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_125 * V_126 = & V_123 -> V_133 ;
struct V_132 * V_132 = V_2 -> V_63 ;
T_2 V_8 = V_177 -> V_179 ;
struct V_3 * V_3 ;
T_1 V_165 ;
int V_32 = 0 ;
V_165 = F_179 ( F_57 ( V_132 ) , V_138 ) ;
if ( V_8 >= V_165 >> V_52 )
return V_180 ;
V_3 = F_158 ( V_2 , V_8 ) ;
if ( F_180 ( V_3 ) && ! ( V_177 -> V_34 & V_181 ) ) {
F_177 ( V_169 , V_126 , V_123 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_173 ( V_169 , V_126 , V_123 , V_8 ) ;
F_181 ( V_182 ) ;
F_182 ( V_169 -> V_183 , V_182 ) ;
V_32 = V_184 ;
V_185:
V_3 = F_158 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_145;
}
if ( ! F_183 ( V_3 , V_169 -> V_183 , V_177 -> V_34 ) ) {
F_34 ( V_3 ) ;
return V_32 | V_186 ;
}
if ( F_78 ( V_3 -> V_2 != V_2 ) ) {
F_109 ( V_3 ) ;
F_184 ( V_3 ) ;
goto V_185;
}
F_61 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_78 ( ! F_17 ( V_3 ) ) )
goto V_187;
V_165 = F_179 ( F_57 ( V_132 ) , V_138 ) ;
if ( F_78 ( V_8 >= V_165 >> V_52 ) ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_180 ;
}
V_177 -> V_3 = V_3 ;
return V_32 | V_188 ;
V_145:
error = F_172 ( V_123 , V_8 ) ;
if ( error >= 0 )
goto V_185;
if ( error == - V_155 )
return V_189 ;
return V_180 ;
V_187:
F_167 ( V_3 ) ;
error = V_2 -> V_27 -> V_153 ( V_123 , V_3 ) ;
if ( ! error ) {
F_129 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_37 ;
}
F_34 ( V_3 ) ;
if ( ! error || error == V_154 )
goto V_185;
F_156 ( V_123 , V_126 ) ;
return V_180 ;
}
void F_185 ( struct V_168 * V_169 , struct V_176 * V_177 )
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
F_134 () ;
F_149 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_120 . V_7 > V_177 -> V_194 )
break;
V_103:
V_3 = F_136 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
goto V_195;
if ( F_137 ( V_3 ) ) {
if ( F_138 ( V_3 ) )
break;
else
goto V_195;
}
if ( ! F_139 ( V_3 ) )
goto V_103;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_103;
}
if ( ! F_17 ( V_3 ) ||
F_160 ( V_3 ) ||
F_186 ( V_3 ) )
goto V_196;
if ( ! F_144 ( V_3 ) )
goto V_196;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_197;
V_165 = F_179 ( F_57 ( V_2 -> V_63 ) , V_138 ) ;
if ( V_3 -> V_7 >= V_165 >> V_52 )
goto V_197;
V_193 = V_177 -> V_193 + V_3 -> V_7 - V_177 -> V_179 ;
if ( ! F_187 ( * V_193 ) )
goto V_197;
if ( V_123 -> V_133 . V_173 > 0 )
V_123 -> V_133 . V_173 -- ;
V_192 = V_190 + ( V_3 -> V_7 - V_177 -> V_179 ) * V_198 ;
F_188 ( V_169 , V_192 , V_3 , V_193 , false , false ) ;
F_109 ( V_3 ) ;
goto V_195;
V_197:
F_109 ( V_3 ) ;
V_196:
F_34 ( V_3 ) ;
V_195:
if ( V_120 . V_7 == V_177 -> V_194 )
break;
}
F_140 () ;
}
int F_189 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_3 * V_3 = V_177 -> V_3 ;
struct V_132 * V_132 = F_190 ( V_169 -> V_178 ) ;
int V_32 = V_188 ;
F_191 ( V_132 -> V_199 ) ;
F_192 ( V_169 -> V_178 ) ;
F_142 ( V_3 ) ;
if ( V_3 -> V_2 != V_132 -> V_200 ) {
F_109 ( V_3 ) ;
V_32 = V_201 ;
goto V_57;
}
F_193 ( V_3 ) ;
F_194 ( V_3 ) ;
V_57:
F_195 ( V_132 -> V_199 ) ;
return V_32 ;
}
int F_196 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
if ( ! V_2 -> V_27 -> V_153 )
return - V_202 ;
F_169 ( V_123 ) ;
V_169 -> V_203 = & V_204 ;
return 0 ;
}
int F_197 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 & V_205 ) && ( V_169 -> V_170 & V_206 ) )
return - V_207 ;
return F_196 ( V_123 , V_169 ) ;
}
int F_196 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
int F_197 ( struct V_123 * V_123 , struct V_168 * V_169 )
{
return - V_208 ;
}
static struct V_3 * F_198 ( struct V_3 * V_3 )
{
if ( ! F_199 ( V_3 ) ) {
F_129 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_34 ( V_3 ) ;
V_3 = F_200 ( - V_37 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_201 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_202)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_64 ;
V_103:
V_3 = F_158 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_89 ( V_77 | V_209 ) ;
if ( ! V_3 )
return F_200 ( - V_155 ) ;
V_64 = F_81 ( V_3 , V_2 , V_7 , V_77 ) ;
if ( F_78 ( V_64 ) ) {
F_34 ( V_3 ) ;
if ( V_64 == - V_73 )
goto V_103;
return F_200 ( V_64 ) ;
}
V_64 = F_202 ( V_166 , V_3 ) ;
if ( V_64 < 0 ) {
F_34 ( V_3 ) ;
V_3 = F_200 ( V_64 ) ;
} else {
V_3 = F_198 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_203 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_202)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_64 ;
V_210:
V_3 = F_201 ( V_2 , V_7 , F_202 , V_166 , V_77 ) ;
if ( F_199 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_57;
F_142 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_210;
}
if ( F_17 ( V_3 ) ) {
F_109 ( V_3 ) ;
goto V_57;
}
V_64 = F_202 ( V_166 , V_3 ) ;
if ( V_64 < 0 ) {
F_34 ( V_3 ) ;
return F_200 ( V_64 ) ;
} else {
V_3 = F_198 ( V_3 ) ;
if ( F_199 ( V_3 ) )
return V_3 ;
}
V_57:
F_145 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_202)( void * , struct V_3 * ) ,
void * V_166 )
{
return F_203 ( V_2 , V_7 , F_202 , V_166 , F_205 ( V_2 ) ) ;
}
struct V_3 * F_206 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_77 )
{
T_9 * F_202 = ( T_9 * ) V_2 -> V_27 -> V_153 ;
return F_203 ( V_2 , V_7 , F_202 , NULL , V_77 ) ;
}
inline int F_207 ( struct V_123 * V_123 , T_1 * V_162 , T_7 * V_139 , int V_211 )
{
struct V_132 * V_132 = V_123 -> V_131 -> V_63 ;
unsigned long V_212 = F_208 ( V_213 ) ;
if ( F_78 ( * V_162 < 0 ) )
return - V_207 ;
if ( ! V_211 ) {
if ( V_123 -> V_163 & V_214 )
* V_162 = F_57 ( V_132 ) ;
if ( V_212 != V_215 ) {
if ( * V_162 >= V_212 ) {
F_209 ( V_216 , V_30 , 0 ) ;
return - V_217 ;
}
if ( * V_139 > V_212 - ( F_210 ( V_212 ) ) * V_162 ) {
* V_139 = V_212 - ( F_210 ( V_212 ) ) * V_162 ;
}
}
}
if ( F_78 ( * V_162 + * V_139 > V_218 &&
! ( V_123 -> V_163 & V_219 ) ) ) {
if ( * V_162 >= V_218 ) {
return - V_217 ;
}
if ( * V_139 > V_218 - ( unsigned long ) * V_162 ) {
* V_139 = V_218 - ( unsigned long ) * V_162 ;
}
}
if ( F_180 ( ! V_211 ) ) {
if ( F_78 ( * V_162 >= V_132 -> V_199 -> V_220 ) ) {
if ( * V_139 || * V_162 > V_132 -> V_199 -> V_220 ) {
return - V_217 ;
}
}
if ( F_78 ( * V_162 + * V_139 > V_132 -> V_199 -> V_220 ) )
* V_139 = V_132 -> V_199 -> V_220 - * V_162 ;
} else {
#ifdef F_211
T_1 V_142 ;
if ( F_212 ( F_213 ( V_132 ) ) )
return - V_221 ;
V_142 = F_57 ( V_132 ) ;
if ( * V_162 >= V_142 ) {
if ( * V_139 || * V_162 > V_142 )
return - V_35 ;
}
if ( * V_162 + * V_139 > V_142 )
* V_139 = V_142 - * V_162 ;
#else
return - V_221 ;
#endif
}
return 0 ;
}
int F_214 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_34 ,
struct V_3 * * V_102 , void * * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_27 ;
return V_225 -> V_226 ( V_123 , V_2 , V_162 , V_222 , V_34 ,
V_102 , V_223 ) ;
}
int F_215 ( struct V_123 * V_123 , struct V_1 * V_2 ,
T_1 V_162 , unsigned V_222 , unsigned V_227 ,
struct V_3 * V_3 , void * V_223 )
{
const struct V_224 * V_225 = V_2 -> V_27 ;
return V_225 -> V_228 ( V_123 , V_2 , V_162 , V_222 , V_227 , V_3 , V_223 ) ;
}
T_6
F_216 ( struct V_157 * V_158 , struct V_129 * V_229 , T_1 V_162 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_63 ;
T_6 V_130 ;
T_7 V_230 ;
T_2 V_39 ;
struct V_129 V_166 ;
V_230 = F_165 ( V_229 ) ;
V_39 = ( V_162 + V_230 - 1 ) >> V_52 ;
V_130 = F_59 ( V_2 , V_162 , V_162 + V_230 - 1 ) ;
if ( V_130 )
goto V_57;
if ( V_2 -> V_13 ) {
V_130 = F_217 ( V_2 ,
V_162 >> V_52 , V_39 ) ;
if ( V_130 ) {
if ( V_130 == - V_231 )
return 0 ;
goto V_57;
}
}
V_166 = * V_229 ;
V_130 = V_2 -> V_27 -> V_167 ( V_232 , V_158 , & V_166 , V_162 ) ;
if ( V_2 -> V_13 ) {
F_217 ( V_2 ,
V_162 >> V_52 , V_39 ) ;
}
if ( V_130 > 0 ) {
V_162 += V_130 ;
F_171 ( V_229 , V_130 ) ;
if ( V_162 > F_57 ( V_132 ) && ! F_218 ( V_132 -> V_233 ) ) {
F_219 ( V_132 , V_162 ) ;
F_220 ( V_132 ) ;
}
V_158 -> V_161 = V_162 ;
}
V_57:
return V_130 ;
}
struct V_3 * F_221 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_34 )
{
struct V_3 * V_3 ;
int V_104 = V_108 | V_110 | V_112 | V_111 ;
if ( V_34 & V_234 )
V_104 |= V_114 ;
V_3 = F_143 ( V_2 , V_7 , V_104 ,
F_205 ( V_2 ) ,
V_156 ) ;
if ( V_3 )
F_194 ( V_3 ) ;
return V_3 ;
}
T_6 F_222 ( struct V_123 * V_123 ,
struct V_129 * V_60 , T_1 V_162 )
{
struct V_1 * V_2 = V_123 -> V_131 ;
const struct V_224 * V_27 = V_2 -> V_27 ;
long V_235 = 0 ;
T_6 V_130 = 0 ;
unsigned int V_34 = 0 ;
if ( F_223 ( F_224 () , V_236 ) )
V_34 |= V_237 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_238 ;
T_7 V_227 ;
void * V_223 ;
V_8 = ( V_162 & ( V_138 - 1 ) ) ;
V_238 = F_225 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_239:
if ( F_78 ( F_226 ( V_60 , V_238 ) ) ) {
V_235 = - V_151 ;
break;
}
V_235 = V_27 -> V_226 ( V_123 , V_2 , V_162 , V_238 , V_34 ,
& V_3 , & V_223 ) ;
if ( F_78 ( V_235 < 0 ) )
break;
if ( F_162 ( V_2 ) )
F_163 ( V_3 ) ;
V_227 = F_227 ( V_3 , V_60 , V_8 , V_238 ) ;
F_163 ( V_3 ) ;
V_235 = V_27 -> V_228 ( V_123 , V_2 , V_162 , V_238 , V_227 ,
V_3 , V_223 ) ;
if ( F_78 ( V_235 < 0 ) )
break;
V_227 = V_235 ;
F_55 () ;
F_171 ( V_60 , V_227 ) ;
if ( F_78 ( V_227 == 0 ) ) {
V_238 = F_225 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_239;
}
V_162 += V_227 ;
V_130 += V_227 ;
F_228 ( V_2 ) ;
if ( F_38 ( V_30 ) ) {
V_235 = - V_31 ;
break;
}
} while ( F_165 ( V_60 ) );
return V_130 ? V_130 : V_235 ;
}
T_6 F_229 ( struct V_157 * V_158 , struct V_129 * V_229 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_1 * V_2 = V_123 -> V_131 ;
struct V_132 * V_132 = V_2 -> V_63 ;
T_1 V_162 = V_158 -> V_161 ;
T_6 V_130 = 0 ;
T_6 V_64 ;
T_6 V_235 ;
T_7 V_139 = F_165 ( V_229 ) ;
V_30 -> V_25 = V_2 -> V_25 ;
V_64 = F_207 ( V_123 , & V_162 , & V_139 , F_218 ( V_132 -> V_233 ) ) ;
if ( V_64 )
goto V_57;
if ( V_139 == 0 )
goto V_57;
F_230 ( V_229 , V_139 ) ;
V_64 = F_231 ( V_123 ) ;
if ( V_64 )
goto V_57;
V_64 = F_192 ( V_123 ) ;
if ( V_64 )
goto V_57;
if ( F_78 ( V_123 -> V_163 & V_164 ) ) {
T_1 V_240 ;
V_130 = F_216 ( V_158 , V_229 , V_162 ) ;
if ( V_130 < 0 || V_130 == V_139 )
goto V_57;
V_162 += V_130 ;
V_139 -= V_130 ;
V_235 = F_222 ( V_123 , V_229 , V_162 ) ;
if ( F_78 ( V_235 < 0 ) && ! V_130 ) {
V_64 = V_235 ;
goto V_57;
}
V_158 -> V_161 = V_162 + V_235 ;
V_240 = V_162 + V_235 - 1 ;
V_64 = F_59 ( V_123 -> V_131 , V_162 , V_240 ) ;
if ( V_64 == 0 ) {
V_130 += V_235 ;
F_232 ( V_2 ,
V_162 >> V_52 ,
V_240 >> V_52 ) ;
} else {
}
} else {
V_130 = F_222 ( V_123 , V_229 , V_162 ) ;
if ( F_180 ( V_130 >= 0 ) )
V_158 -> V_161 = V_162 + V_130 ;
}
V_57:
V_30 -> V_25 = NULL ;
return V_130 ? V_130 : V_64 ;
}
T_6 F_233 ( struct V_157 * V_158 , struct V_129 * V_229 )
{
struct V_123 * V_123 = V_158 -> V_159 ;
struct V_132 * V_132 = V_123 -> V_131 -> V_63 ;
T_6 V_32 ;
F_234 ( & V_132 -> V_241 ) ;
V_32 = F_229 ( V_158 , V_229 ) ;
F_235 ( & V_132 -> V_241 ) ;
if ( V_32 > 0 ) {
T_6 V_64 ;
V_64 = F_236 ( V_123 , V_158 -> V_161 - V_32 , V_32 ) ;
if ( V_64 < 0 )
V_32 = V_64 ;
}
return V_32 ;
}
int F_237 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_238 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_27 -> V_242 )
return V_2 -> V_27 -> V_242 ( V_3 , V_14 ) ;
return F_239 ( V_3 ) ;
}
