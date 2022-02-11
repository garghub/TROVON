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
F_28 ( F_29 ( V_2 -> V_25 ) , V_26 ) ;
}
}
void F_30 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_2 ;
void (* F_31)( struct V_3 * );
F_23 ( ! F_3 ( V_3 ) ) ;
F_31 = V_2 -> V_27 -> F_31 ;
F_32 ( & V_2 -> V_28 ) ;
F_15 ( V_3 , NULL ) ;
F_33 ( & V_2 -> V_28 ) ;
if ( F_31 )
F_31 ( V_3 ) ;
F_34 ( V_3 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
if ( F_7 ( V_30 , & V_2 -> V_31 ) &&
F_36 ( V_30 , & V_2 -> V_31 ) )
V_29 = - V_32 ;
if ( F_7 ( V_33 , & V_2 -> V_31 ) &&
F_36 ( V_33 , & V_2 -> V_31 ) )
V_29 = - V_34 ;
return V_29 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 , int V_37 )
{
int V_29 ;
struct V_38 V_39 = {
. V_37 = V_37 ,
. V_40 = V_41 ,
. V_42 = V_35 ,
. V_43 = V_36 ,
} ;
if ( ! F_38 ( V_2 ) )
return 0 ;
V_29 = F_39 ( V_2 , & V_39 ) ;
return V_29 ;
}
static inline int F_40 ( struct V_1 * V_2 ,
int V_37 )
{
return F_37 ( V_2 , 0 , V_44 , V_37 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_45 ) ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 )
{
return F_37 ( V_2 , V_35 , V_36 , V_45 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_46 ) ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_47 ,
T_1 V_48 )
{
T_2 V_7 = V_47 >> V_49 ;
T_2 V_36 = V_48 >> V_49 ;
struct V_50 V_51 ;
int V_52 ;
int V_53 , V_29 = 0 ;
if ( V_48 < V_47 )
goto V_54;
F_45 ( & V_51 , 0 ) ;
while ( ( V_7 <= V_36 ) &&
( V_52 = F_46 ( & V_51 , V_2 , & V_7 ,
V_55 ,
F_47 ( V_36 - V_7 , ( T_2 ) V_56 - 1 ) + 1 ) ) != 0 ) {
unsigned V_57 ;
for ( V_57 = 0 ; V_57 < V_52 ; V_57 ++ ) {
struct V_3 * V_3 = V_51 . V_58 [ V_57 ] ;
if ( V_3 -> V_7 > V_36 )
continue;
F_48 ( V_3 ) ;
if ( F_49 ( V_3 ) )
V_29 = - V_34 ;
}
F_50 ( & V_51 ) ;
F_51 () ;
}
V_54:
V_53 = F_35 ( V_2 ) ;
if ( ! V_29 )
V_29 = V_53 ;
return V_29 ;
}
int F_52 ( struct V_1 * V_2 )
{
T_1 V_59 = F_53 ( V_2 -> V_25 ) ;
if ( V_59 == 0 )
return 0 ;
return F_44 ( V_2 , 0 , V_59 - 1 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
if ( V_2 -> V_13 ) {
V_60 = F_41 ( V_2 ) ;
if ( V_60 != - V_34 ) {
int V_61 = F_52 ( V_2 ) ;
if ( ! V_60 )
V_60 = V_61 ;
}
} else {
V_60 = F_35 ( V_2 ) ;
}
return V_60 ;
}
int F_55 ( struct V_1 * V_2 ,
T_1 V_62 , T_1 V_63 )
{
int V_60 = 0 ;
if ( V_2 -> V_13 ) {
V_60 = F_37 ( V_2 , V_62 , V_63 ,
V_45 ) ;
if ( V_60 != - V_34 ) {
int V_61 = F_44 ( V_2 ,
V_62 , V_63 ) ;
if ( ! V_60 )
V_60 = V_61 ;
}
} else {
V_60 = F_35 ( V_2 ) ;
}
return V_60 ;
}
int F_56 ( struct V_3 * V_64 , struct V_3 * V_65 , T_3 V_14 )
{
int error ;
F_57 ( ! F_3 ( V_64 ) , V_64 ) ;
F_57 ( ! F_3 ( V_65 ) , V_65 ) ;
F_57 ( V_65 -> V_2 , V_65 ) ;
error = F_58 ( V_14 & ~ V_66 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_64 -> V_2 ;
void (* F_31)( struct V_3 * );
T_2 V_8 = V_64 -> V_7 ;
F_31 = V_2 -> V_27 -> F_31 ;
F_59 ( V_65 ) ;
V_65 -> V_2 = V_2 ;
V_65 -> V_7 = V_8 ;
F_32 ( & V_2 -> V_28 ) ;
F_15 ( V_64 , NULL ) ;
error = F_60 ( & V_2 -> V_11 , V_8 , V_65 ) ;
F_23 ( error ) ;
V_2 -> V_13 ++ ;
F_61 ( V_65 , V_22 ) ;
if ( F_22 ( V_65 ) )
F_61 ( V_65 , V_23 ) ;
F_33 ( & V_2 -> V_28 ) ;
F_62 ( V_64 , V_65 , true ) ;
F_63 () ;
if ( F_31 )
F_31 ( V_64 ) ;
F_34 ( V_64 ) ;
}
return error ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_67 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_65 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_68 ;
V_68 = F_66 ( V_10 , & V_2 -> V_28 ) ;
if ( ! F_67 ( V_68 ) )
return - V_69 ;
if ( V_67 )
* V_67 = V_68 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_68 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_69 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_70 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_71 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_67 )
{
int V_70 = F_72 ( V_3 ) ;
struct V_71 * V_72 ;
int error ;
F_57 ( ! F_3 ( V_3 ) , V_3 ) ;
F_57 ( F_22 ( V_3 ) , V_3 ) ;
if ( ! V_70 ) {
error = F_73 ( V_3 , V_73 -> V_74 ,
V_14 , & V_72 ) ;
if ( error )
return error ;
}
error = F_74 ( V_14 & ~ V_66 ) ;
if ( error ) {
if ( ! V_70 )
F_75 ( V_3 , V_72 ) ;
return error ;
}
F_59 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_32 ( & V_2 -> V_28 ) ;
error = F_64 ( V_2 , V_3 , V_67 ) ;
F_63 () ;
if ( F_76 ( error ) )
goto V_75;
F_61 ( V_3 , V_22 ) ;
F_33 ( & V_2 -> V_28 ) ;
if ( ! V_70 )
F_77 ( V_3 , V_72 , false ) ;
F_78 ( V_3 ) ;
return 0 ;
V_75:
V_3 -> V_2 = NULL ;
F_33 ( & V_2 -> V_28 ) ;
if ( ! V_70 )
F_75 ( V_3 , V_72 ) ;
F_34 ( V_3 ) ;
return error ;
}
int F_79 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_71 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_80 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_29 ;
F_81 ( V_3 ) ;
V_29 = F_71 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_76 ( V_29 ) )
F_82 ( V_3 ) ;
else {
if ( V_4 && F_83 ( V_4 ) ) {
F_84 ( V_3 ) ;
F_85 ( V_3 ) ;
} else
F_86 ( V_3 ) ;
F_87 ( V_3 ) ;
}
return V_29 ;
}
struct V_3 * F_88 ( T_3 V_76 )
{
int V_77 ;
struct V_3 * V_3 ;
if ( F_89 () ) {
unsigned int V_78 ;
do {
V_78 = F_90 () ;
V_77 = F_91 () ;
V_3 = F_92 ( V_77 , V_76 , 0 ) ;
} while ( ! V_3 && F_93 ( V_78 ) );
return V_3 ;
}
return F_94 ( V_76 , 0 ) ;
}
T_4 * F_95 ( struct V_3 * V_3 )
{
const struct V_79 * V_79 = F_96 ( V_3 ) ;
return & V_79 -> V_80 [ F_97 ( V_3 , V_79 -> V_81 ) ] ;
}
void F_98 ( struct V_3 * V_3 , int V_82 )
{
F_99 ( V_83 , & V_3 -> V_31 , V_82 ) ;
if ( F_7 ( V_82 , & V_3 -> V_31 ) )
F_100 ( F_95 ( V_3 ) , & V_83 , V_84 ,
V_85 ) ;
}
int F_101 ( struct V_3 * V_3 , int V_82 )
{
F_99 ( V_83 , & V_3 -> V_31 , V_82 ) ;
if ( ! F_7 ( V_82 , & V_3 -> V_31 ) )
return 0 ;
return F_100 ( F_95 ( V_3 ) , & V_83 ,
V_84 , V_86 ) ;
}
int F_102 ( struct V_3 * V_3 ,
int V_82 , unsigned long V_87 )
{
F_99 ( V_83 , & V_3 -> V_31 , V_82 ) ;
V_83 . V_88 . V_87 = V_89 + V_87 ;
if ( ! F_7 ( V_82 , & V_3 -> V_31 ) )
return 0 ;
return F_100 ( F_95 ( V_3 ) , & V_83 ,
V_90 , V_86 ) ;
}
void F_103 ( struct V_3 * V_3 , T_5 * V_91 )
{
T_4 * V_92 = F_95 ( V_3 ) ;
unsigned long V_31 ;
F_104 ( & V_92 -> V_93 , V_31 ) ;
F_105 ( V_92 , V_91 ) ;
F_106 ( & V_92 -> V_93 , V_31 ) ;
}
void F_107 ( struct V_3 * V_3 )
{
F_57 ( ! F_3 ( V_3 ) , V_3 ) ;
F_108 ( V_94 , & V_3 -> V_31 ) ;
F_109 () ;
F_110 ( V_3 , V_94 ) ;
}
void F_111 ( struct V_3 * V_3 )
{
if ( F_112 ( V_3 ) ) {
F_113 ( V_3 ) ;
F_114 ( V_3 ) ;
}
if ( ! F_115 ( V_3 ) )
F_116 () ;
F_109 () ;
F_110 ( V_3 , V_95 ) ;
}
void F_117 ( struct V_3 * V_3 , int V_96 , int V_60 )
{
if ( V_96 == V_97 ) {
if ( ! V_60 ) {
F_118 ( V_3 ) ;
} else {
F_119 ( V_3 ) ;
F_120 ( V_3 ) ;
}
F_107 ( V_3 ) ;
} else {
if ( V_60 ) {
F_120 ( V_3 ) ;
if ( V_3 -> V_2 )
F_121 ( V_3 -> V_2 , V_60 ) ;
}
F_111 ( V_3 ) ;
}
}
void F_122 ( struct V_3 * V_3 )
{
F_99 ( V_83 , & V_3 -> V_31 , V_94 ) ;
F_123 ( F_95 ( V_3 ) , & V_83 , V_84 ,
V_85 ) ;
}
int F_124 ( struct V_3 * V_3 )
{
F_99 ( V_83 , & V_3 -> V_31 , V_94 ) ;
return F_123 ( F_95 ( V_3 ) , & V_83 ,
V_84 , V_86 ) ;
}
int F_125 ( struct V_3 * V_3 , struct V_98 * V_74 ,
unsigned int V_31 )
{
if ( V_31 & V_99 ) {
if ( V_31 & V_100 )
return 0 ;
F_126 ( & V_74 -> V_101 ) ;
if ( V_31 & V_102 )
F_127 ( V_3 ) ;
else
F_128 ( V_3 ) ;
return 0 ;
} else {
if ( V_31 & V_102 ) {
int V_29 ;
V_29 = F_124 ( V_3 ) ;
if ( V_29 ) {
F_126 ( & V_74 -> V_101 ) ;
return 0 ;
}
} else
F_122 ( V_3 ) ;
return 1 ;
}
}
T_2 F_129 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_103 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_103 ; V_57 ++ ) {
struct V_3 * V_3 ;
V_3 = F_130 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_67 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_131 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_103 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_103 ; V_57 ++ ) {
struct V_3 * V_3 ;
V_3 = F_130 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_67 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_104 )
break;
}
return V_7 ;
}
struct V_3 * F_132 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_105 ;
struct V_3 * V_3 ;
F_133 () ;
V_106:
V_3 = NULL ;
V_105 = F_134 ( & V_2 -> V_11 , V_8 ) ;
if ( V_105 ) {
V_3 = F_135 ( V_105 ) ;
if ( F_76 ( ! V_3 ) )
goto V_54;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) )
goto V_106;
goto V_54;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_105 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
}
V_54:
F_139 () ;
return V_3 ;
}
struct V_3 * F_140 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_106:
V_3 = F_132 ( V_2 , V_8 ) ;
if ( V_3 && ! F_136 ( V_3 ) ) {
F_141 ( V_3 ) ;
if ( F_76 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_106;
}
F_57 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_142 ( struct V_1 * V_2 , T_2 V_8 ,
int V_107 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_106:
V_3 = F_132 ( V_2 , V_8 ) ;
if ( F_67 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_108;
if ( V_107 & V_109 ) {
if ( V_107 & V_110 ) {
if ( ! F_143 ( V_3 ) ) {
F_34 ( V_3 ) ;
return NULL ;
}
} else {
F_141 ( V_3 ) ;
}
if ( F_76 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_106;
}
F_57 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_107 & V_111 ) )
F_144 ( V_3 ) ;
V_108:
if ( ! V_3 && ( V_107 & V_112 ) ) {
int V_60 ;
if ( ( V_107 & V_113 ) && F_26 ( V_2 ) )
V_14 |= V_114 ;
if ( V_107 & V_115 )
V_14 &= ~ V_116 ;
V_3 = F_88 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_145 ( ! ( V_107 & V_109 ) ) )
V_107 |= V_109 ;
if ( V_107 & V_111 )
F_146 ( V_3 ) ;
V_60 = F_80 ( V_3 , V_2 , V_8 ,
V_14 & V_117 ) ;
if ( F_76 ( V_60 ) ) {
F_34 ( V_3 ) ;
V_3 = NULL ;
if ( V_60 == - V_69 )
goto V_106;
}
}
return V_3 ;
}
unsigned F_147 ( struct V_1 * V_2 ,
T_2 V_35 , unsigned int V_118 ,
struct V_3 * * V_119 , T_2 * V_120 )
{
void * * V_10 ;
unsigned int V_29 = 0 ;
struct V_121 V_122 ;
if ( ! V_118 )
return 0 ;
F_133 () ;
V_123:
F_148 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_106:
V_3 = F_135 ( V_10 ) ;
if ( F_76 ( ! V_3 ) )
continue;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) )
goto V_123;
goto V_124;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
V_124:
V_120 [ V_29 ] = V_122 . V_7 ;
V_119 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_118 )
break;
}
F_139 () ;
return V_29 ;
}
unsigned F_149 ( struct V_1 * V_2 , T_2 V_35 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_121 V_122 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_76 ( ! V_52 ) )
return 0 ;
F_133 () ;
V_123:
F_148 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_106:
V_3 = F_135 ( V_10 ) ;
if ( F_76 ( ! V_3 ) )
continue;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) ) {
F_150 ( V_122 . V_7 ) ;
goto V_123;
}
continue;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_139 () ;
return V_29 ;
}
unsigned F_151 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_121 V_122 ;
void * * V_10 ;
unsigned int V_29 = 0 ;
if ( F_76 ( ! V_52 ) )
return 0 ;
F_133 () ;
V_123:
F_152 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_106:
V_3 = F_135 ( V_10 ) ;
if ( F_76 ( ! V_3 ) )
break;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) ) {
goto V_123;
}
break;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_122 . V_7 ) {
F_34 ( V_3 ) ;
break;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_139 () ;
return V_29 ;
}
unsigned F_153 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_121 V_122 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_76 ( ! V_52 ) )
return 0 ;
F_133 () ;
V_123:
F_154 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_106:
V_3 = F_135 ( V_10 ) ;
if ( F_76 ( ! V_3 ) )
continue;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) ) {
goto V_123;
}
continue;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_139 () ;
if ( V_29 )
* V_7 = V_58 [ V_29 - 1 ] -> V_7 + 1 ;
return V_29 ;
}
static void F_155 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
V_128 -> V_129 /= 4 ;
}
static T_6 F_156 ( struct V_125 * V_126 , T_1 * V_130 ,
struct V_131 * V_122 , T_6 V_132 )
{
struct V_1 * V_2 = V_126 -> V_133 ;
struct V_134 * V_134 = V_2 -> V_25 ;
struct V_127 * V_128 = & V_126 -> V_135 ;
T_2 V_7 ;
T_2 V_136 ;
T_2 V_137 ;
unsigned long V_8 ;
unsigned int V_138 ;
int error = 0 ;
V_7 = * V_130 >> V_49 ;
V_137 = V_128 -> V_139 >> V_49 ;
V_138 = V_128 -> V_139 & ( V_140 - 1 ) ;
V_136 = ( * V_130 + V_122 -> V_141 + V_140 - 1 ) >> V_49 ;
V_8 = * V_130 & ~ V_142 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_143 ;
T_1 V_144 ;
unsigned long V_145 , V_29 ;
F_51 () ;
V_146:
V_3 = F_157 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_158 ( V_2 ,
V_128 , V_126 ,
V_7 , V_136 - V_7 ) ;
V_3 = F_157 ( V_2 , V_7 ) ;
if ( F_76 ( V_3 == NULL ) )
goto V_147;
}
if ( F_159 ( V_3 ) ) {
F_160 ( V_2 ,
V_128 , V_126 , V_3 ,
V_7 , V_136 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_134 -> V_148 == V_49 ||
! V_2 -> V_27 -> V_149 )
goto V_150;
if ( ! F_143 ( V_3 ) )
goto V_150;
if ( ! V_3 -> V_2 )
goto V_151;
if ( ! V_2 -> V_27 -> V_149 ( V_3 ,
V_8 , V_122 -> V_141 ) )
goto V_151;
F_107 ( V_3 ) ;
}
V_152:
V_144 = F_53 ( V_134 ) ;
V_143 = ( V_144 - 1 ) >> V_49 ;
if ( F_76 ( ! V_144 || V_7 > V_143 ) ) {
F_34 ( V_3 ) ;
goto V_54;
}
V_145 = V_140 ;
if ( V_7 == V_143 ) {
V_145 = ( ( V_144 - 1 ) & ~ V_142 ) + 1 ;
if ( V_145 <= V_8 ) {
F_34 ( V_3 ) ;
goto V_54;
}
}
V_145 = V_145 - V_8 ;
if ( F_161 ( V_2 ) )
F_162 ( V_3 ) ;
if ( V_137 != V_7 || V_8 != V_138 )
F_144 ( V_3 ) ;
V_137 = V_7 ;
V_29 = F_163 ( V_3 , V_8 , V_145 , V_122 ) ;
V_8 += V_29 ;
V_7 += V_8 >> V_49 ;
V_8 &= ~ V_142 ;
V_138 = V_8 ;
F_34 ( V_3 ) ;
V_132 += V_29 ;
if ( ! F_164 ( V_122 ) )
goto V_54;
if ( V_29 < V_145 ) {
error = - V_153 ;
goto V_54;
}
continue;
V_150:
error = F_165 ( V_3 ) ;
if ( F_76 ( error ) )
goto V_154;
V_151:
if ( ! V_3 -> V_2 ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_107 ( V_3 ) ;
goto V_152;
}
V_155:
F_166 ( V_3 ) ;
error = V_2 -> V_27 -> V_155 ( V_126 , V_3 ) ;
if ( F_76 ( error ) ) {
if ( error == V_156 ) {
F_34 ( V_3 ) ;
error = 0 ;
goto V_146;
}
goto V_154;
}
if ( ! F_17 ( V_3 ) ) {
error = F_165 ( V_3 ) ;
if ( F_76 ( error ) )
goto V_154;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_146;
}
F_107 ( V_3 ) ;
F_155 ( V_126 , V_128 ) ;
error = - V_34 ;
goto V_154;
}
F_107 ( V_3 ) ;
}
goto V_152;
V_154:
F_34 ( V_3 ) ;
goto V_54;
V_147:
V_3 = F_167 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_157 ;
goto V_54;
}
error = F_80 ( V_3 , V_2 ,
V_7 , V_158 ) ;
if ( error ) {
F_34 ( V_3 ) ;
if ( error == - V_69 ) {
error = 0 ;
goto V_146;
}
goto V_54;
}
goto V_155;
}
V_54:
V_128 -> V_139 = V_137 ;
V_128 -> V_139 <<= V_49 ;
V_128 -> V_139 |= V_138 ;
* V_130 = ( ( T_1 ) V_7 << V_49 ) + V_8 ;
F_168 ( V_126 ) ;
return V_132 ? V_132 : error ;
}
T_6
F_169 ( struct V_159 * V_160 , struct V_131 * V_122 )
{
struct V_125 * V_125 = V_160 -> V_161 ;
T_6 V_162 = 0 ;
T_1 * V_130 = & V_160 -> V_163 ;
T_1 V_164 = * V_130 ;
if ( F_170 ( V_125 ) ) {
struct V_1 * V_2 = V_125 -> V_133 ;
struct V_134 * V_134 = V_2 -> V_25 ;
T_7 V_141 = F_164 ( V_122 ) ;
T_1 V_165 ;
if ( ! V_141 )
goto V_54;
V_165 = F_53 ( V_134 ) ;
V_162 = F_55 ( V_2 , V_164 ,
V_164 + V_141 - 1 ) ;
if ( ! V_162 ) {
struct V_131 V_166 = * V_122 ;
V_162 = V_2 -> V_27 -> V_167 ( V_97 , V_160 , & V_166 , V_164 ) ;
}
if ( V_162 > 0 ) {
* V_130 = V_164 + V_162 ;
F_171 ( V_122 , V_162 ) ;
}
if ( V_162 < 0 || ! F_164 ( V_122 ) || * V_130 >= V_165 ||
F_172 ( V_134 ) ) {
F_168 ( V_125 ) ;
goto V_54;
}
}
V_162 = F_156 ( V_125 , V_130 , V_122 , V_162 ) ;
V_54:
return V_162 ;
}
static int F_173 ( struct V_125 * V_125 , T_2 V_8 )
{
struct V_1 * V_2 = V_125 -> V_133 ;
struct V_3 * V_3 ;
int V_29 ;
do {
V_3 = F_167 ( V_2 ) ;
if ( ! V_3 )
return - V_157 ;
V_29 = F_80 ( V_3 , V_2 , V_8 , V_158 ) ;
if ( V_29 == 0 )
V_29 = V_2 -> V_27 -> V_155 ( V_125 , V_3 ) ;
else if ( V_29 == - V_69 )
V_29 = 0 ;
F_34 ( V_3 ) ;
} while ( V_29 == V_156 );
return V_29 ;
}
static void F_174 ( struct V_168 * V_169 ,
struct V_127 * V_128 ,
struct V_125 * V_125 ,
T_2 V_8 )
{
unsigned long V_129 ;
struct V_1 * V_2 = V_125 -> V_133 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( ! V_128 -> V_129 )
return;
if ( V_169 -> V_170 & V_172 ) {
F_158 ( V_2 , V_128 , V_125 , V_8 ,
V_128 -> V_129 ) ;
return;
}
if ( V_128 -> V_173 < V_174 * 10 )
V_128 -> V_173 ++ ;
if ( V_128 -> V_173 > V_174 )
return;
V_129 = F_175 ( V_128 -> V_129 ) ;
V_128 -> V_35 = F_176 ( long , 0 , V_8 - V_129 / 2 ) ;
V_128 -> V_165 = V_129 ;
V_128 -> V_175 = V_129 / 4 ;
F_177 ( V_128 , V_2 , V_125 ) ;
}
static void F_178 ( struct V_168 * V_169 ,
struct V_127 * V_128 ,
struct V_125 * V_125 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_125 -> V_133 ;
if ( V_169 -> V_170 & V_171 )
return;
if ( V_128 -> V_173 > 0 )
V_128 -> V_173 -- ;
if ( F_159 ( V_3 ) )
F_160 ( V_2 , V_128 , V_125 ,
V_3 , V_8 , V_128 -> V_129 ) ;
}
int F_179 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
int error ;
struct V_125 * V_125 = V_169 -> V_178 ;
struct V_1 * V_2 = V_125 -> V_133 ;
struct V_127 * V_128 = & V_125 -> V_135 ;
struct V_134 * V_134 = V_2 -> V_25 ;
T_2 V_8 = V_177 -> V_179 ;
struct V_3 * V_3 ;
T_1 V_165 ;
int V_29 = 0 ;
V_165 = F_180 ( F_53 ( V_134 ) , V_140 ) ;
if ( V_8 >= V_165 >> V_49 )
return V_180 ;
V_3 = F_157 ( V_2 , V_8 ) ;
if ( F_181 ( V_3 ) && ! ( V_177 -> V_31 & V_181 ) ) {
F_178 ( V_169 , V_128 , V_125 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_174 ( V_169 , V_128 , V_125 , V_8 ) ;
F_182 ( V_182 ) ;
F_183 ( V_169 -> V_183 , V_182 ) ;
V_29 = V_184 ;
V_185:
V_3 = F_157 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_147;
}
if ( ! F_184 ( V_3 , V_169 -> V_183 , V_177 -> V_31 ) ) {
F_34 ( V_3 ) ;
return V_29 | V_186 ;
}
if ( F_76 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_185 ( V_3 ) ;
goto V_185;
}
F_57 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_76 ( ! F_17 ( V_3 ) ) )
goto V_187;
V_165 = F_180 ( F_53 ( V_134 ) , V_140 ) ;
if ( F_76 ( V_8 >= V_165 >> V_49 ) ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_180 ;
}
V_177 -> V_3 = V_3 ;
return V_29 | V_188 ;
V_147:
error = F_173 ( V_125 , V_8 ) ;
if ( error >= 0 )
goto V_185;
if ( error == - V_157 )
return V_189 ;
return V_180 ;
V_187:
F_166 ( V_3 ) ;
error = V_2 -> V_27 -> V_155 ( V_125 , V_3 ) ;
if ( ! error ) {
F_128 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_34 ;
}
F_34 ( V_3 ) ;
if ( ! error || error == V_156 )
goto V_185;
F_155 ( V_125 , V_128 ) ;
return V_180 ;
}
void F_186 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_121 V_122 ;
void * * V_10 ;
struct V_125 * V_125 = V_169 -> V_178 ;
struct V_1 * V_2 = V_125 -> V_133 ;
T_1 V_165 ;
struct V_3 * V_3 ;
unsigned long V_190 = ( unsigned long ) V_177 -> V_191 ;
unsigned long V_192 ;
T_8 * V_193 ;
F_133 () ;
F_148 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_122 . V_7 > V_177 -> V_194 )
break;
V_106:
V_3 = F_135 ( V_10 ) ;
if ( F_76 ( ! V_3 ) )
goto V_195;
if ( F_136 ( V_3 ) ) {
if ( F_137 ( V_3 ) )
break;
else
goto V_195;
}
if ( ! F_138 ( V_3 ) )
goto V_106;
if ( F_76 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_106;
}
if ( ! F_17 ( V_3 ) ||
F_159 ( V_3 ) ||
F_187 ( V_3 ) )
goto V_196;
if ( ! F_143 ( V_3 ) )
goto V_196;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_197;
V_165 = F_180 ( F_53 ( V_2 -> V_25 ) , V_140 ) ;
if ( V_3 -> V_7 >= V_165 >> V_49 )
goto V_197;
V_193 = V_177 -> V_193 + V_3 -> V_7 - V_177 -> V_179 ;
if ( ! F_188 ( * V_193 ) )
goto V_197;
if ( V_125 -> V_135 . V_173 > 0 )
V_125 -> V_135 . V_173 -- ;
V_192 = V_190 + ( V_3 -> V_7 - V_177 -> V_179 ) * V_198 ;
F_189 ( V_169 , V_192 , V_3 , V_193 , false , false ) ;
F_107 ( V_3 ) ;
goto V_195;
V_197:
F_107 ( V_3 ) ;
V_196:
F_34 ( V_3 ) ;
V_195:
if ( V_122 . V_7 == V_177 -> V_194 )
break;
}
F_139 () ;
}
int F_190 ( struct V_168 * V_169 , struct V_176 * V_177 )
{
struct V_3 * V_3 = V_177 -> V_3 ;
struct V_134 * V_134 = F_191 ( V_169 -> V_178 ) ;
int V_29 = V_188 ;
F_192 ( V_134 -> V_199 ) ;
F_193 ( V_169 -> V_178 ) ;
F_141 ( V_3 ) ;
if ( V_3 -> V_2 != V_134 -> V_200 ) {
F_107 ( V_3 ) ;
V_29 = V_201 ;
goto V_54;
}
F_194 ( V_3 ) ;
F_195 ( V_3 ) ;
V_54:
F_196 ( V_134 -> V_199 ) ;
return V_29 ;
}
int F_197 ( struct V_125 * V_125 , struct V_168 * V_169 )
{
struct V_1 * V_2 = V_125 -> V_133 ;
if ( ! V_2 -> V_27 -> V_155 )
return - V_202 ;
F_168 ( V_125 ) ;
V_169 -> V_203 = & V_204 ;
return 0 ;
}
int F_198 ( struct V_125 * V_125 , struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 & V_205 ) && ( V_169 -> V_170 & V_206 ) )
return - V_207 ;
return F_197 ( V_125 , V_169 ) ;
}
int F_197 ( struct V_125 * V_125 , struct V_168 * V_169 )
{
return - V_208 ;
}
int F_198 ( struct V_125 * V_125 , struct V_168 * V_169 )
{
return - V_208 ;
}
static struct V_3 * F_199 ( struct V_3 * V_3 )
{
if ( ! F_200 ( V_3 ) ) {
F_128 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_34 ( V_3 ) ;
V_3 = F_201 ( - V_34 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_202 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_203)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_76 )
{
struct V_3 * V_3 ;
int V_60 ;
V_106:
V_3 = F_157 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_88 ( V_76 | V_209 ) ;
if ( ! V_3 )
return F_201 ( - V_157 ) ;
V_60 = F_80 ( V_3 , V_2 , V_7 , V_76 ) ;
if ( F_76 ( V_60 ) ) {
F_34 ( V_3 ) ;
if ( V_60 == - V_69 )
goto V_106;
return F_201 ( V_60 ) ;
}
V_60 = F_203 ( V_166 , V_3 ) ;
if ( V_60 < 0 ) {
F_34 ( V_3 ) ;
V_3 = F_201 ( V_60 ) ;
} else {
V_3 = F_199 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_203)( void * , struct V_3 * ) ,
void * V_166 ,
T_3 V_76 )
{
struct V_3 * V_3 ;
int V_60 ;
V_210:
V_3 = F_202 ( V_2 , V_7 , F_203 , V_166 , V_76 ) ;
if ( F_200 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_54;
F_141 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_107 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_210;
}
if ( F_17 ( V_3 ) ) {
F_107 ( V_3 ) ;
goto V_54;
}
V_60 = F_203 ( V_166 , V_3 ) ;
if ( V_60 < 0 ) {
F_34 ( V_3 ) ;
return F_201 ( V_60 ) ;
} else {
V_3 = F_199 ( V_3 ) ;
if ( F_200 ( V_3 ) )
return V_3 ;
}
V_54:
F_144 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_205 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_203)( void * , struct V_3 * ) ,
void * V_166 )
{
return F_204 ( V_2 , V_7 , F_203 , V_166 , F_206 ( V_2 ) ) ;
}
struct V_3 * F_207 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_76 )
{
T_9 * F_203 = ( T_9 * ) V_2 -> V_27 -> V_155 ;
return F_204 ( V_2 , V_7 , F_203 , NULL , V_76 ) ;
}
inline int F_208 ( struct V_125 * V_125 , T_1 * V_164 , T_7 * V_141 , int V_211 )
{
struct V_134 * V_134 = V_125 -> V_133 -> V_25 ;
unsigned long V_212 = F_209 ( V_213 ) ;
if ( F_76 ( * V_164 < 0 ) )
return - V_207 ;
if ( ! V_211 ) {
if ( V_125 -> V_214 & V_215 )
* V_164 = F_53 ( V_134 ) ;
if ( V_212 != V_216 ) {
if ( * V_164 >= V_212 ) {
F_210 ( V_217 , V_73 , 0 ) ;
return - V_218 ;
}
if ( * V_141 > V_212 - ( F_211 ( V_212 ) ) * V_164 ) {
* V_141 = V_212 - ( F_211 ( V_212 ) ) * V_164 ;
}
}
}
if ( F_76 ( * V_164 + * V_141 > V_219 &&
! ( V_125 -> V_214 & V_220 ) ) ) {
if ( * V_164 >= V_219 ) {
return - V_218 ;
}
if ( * V_141 > V_219 - ( unsigned long ) * V_164 ) {
* V_141 = V_219 - ( unsigned long ) * V_164 ;
}
}
if ( F_181 ( ! V_211 ) ) {
if ( F_76 ( * V_164 >= V_134 -> V_199 -> V_221 ) ) {
if ( * V_141 || * V_164 > V_134 -> V_199 -> V_221 ) {
return - V_218 ;
}
}
if ( F_76 ( * V_164 + * V_141 > V_134 -> V_199 -> V_221 ) )
* V_141 = V_134 -> V_199 -> V_221 - * V_164 ;
} else {
#ifdef F_212
T_1 V_144 ;
if ( F_213 ( F_214 ( V_134 ) ) )
return - V_222 ;
V_144 = F_53 ( V_134 ) ;
if ( * V_164 >= V_144 ) {
if ( * V_141 || * V_164 > V_144 )
return - V_32 ;
}
if ( * V_164 + * V_141 > V_144 )
* V_141 = V_144 - * V_164 ;
#else
return - V_222 ;
#endif
}
return 0 ;
}
int F_215 ( struct V_125 * V_125 , struct V_1 * V_2 ,
T_1 V_164 , unsigned V_223 , unsigned V_31 ,
struct V_3 * * V_105 , void * * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_27 ;
return V_226 -> V_227 ( V_125 , V_2 , V_164 , V_223 , V_31 ,
V_105 , V_224 ) ;
}
int F_216 ( struct V_125 * V_125 , struct V_1 * V_2 ,
T_1 V_164 , unsigned V_223 , unsigned V_228 ,
struct V_3 * V_3 , void * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_27 ;
return V_226 -> V_229 ( V_125 , V_2 , V_164 , V_223 , V_228 , V_3 , V_224 ) ;
}
T_6
F_217 ( struct V_159 * V_160 , struct V_131 * V_230 , T_1 V_164 )
{
struct V_125 * V_125 = V_160 -> V_161 ;
struct V_1 * V_2 = V_125 -> V_133 ;
struct V_134 * V_134 = V_2 -> V_25 ;
T_6 V_132 ;
T_7 V_231 ;
T_2 V_36 ;
struct V_131 V_166 ;
V_231 = F_164 ( V_230 ) ;
V_36 = ( V_164 + V_231 - 1 ) >> V_49 ;
V_132 = F_55 ( V_2 , V_164 , V_164 + V_231 - 1 ) ;
if ( V_132 )
goto V_54;
if ( V_2 -> V_13 ) {
V_132 = F_218 ( V_2 ,
V_164 >> V_49 , V_36 ) ;
if ( V_132 ) {
if ( V_132 == - V_232 )
return 0 ;
goto V_54;
}
}
V_166 = * V_230 ;
V_132 = V_2 -> V_27 -> V_167 ( V_233 , V_160 , & V_166 , V_164 ) ;
if ( V_2 -> V_13 ) {
F_218 ( V_2 ,
V_164 >> V_49 , V_36 ) ;
}
if ( V_132 > 0 ) {
V_164 += V_132 ;
F_171 ( V_230 , V_132 ) ;
if ( V_164 > F_53 ( V_134 ) && ! F_219 ( V_134 -> V_234 ) ) {
F_220 ( V_134 , V_164 ) ;
F_221 ( V_134 ) ;
}
V_160 -> V_163 = V_164 ;
}
V_54:
return V_132 ;
}
struct V_3 * F_222 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_31 )
{
struct V_3 * V_3 ;
int V_107 = V_109 | V_111 | V_113 | V_112 ;
if ( V_31 & V_235 )
V_107 |= V_115 ;
V_3 = F_142 ( V_2 , V_7 , V_107 ,
F_206 ( V_2 ) ) ;
if ( V_3 )
F_195 ( V_3 ) ;
return V_3 ;
}
T_6 F_223 ( struct V_125 * V_125 ,
struct V_131 * V_57 , T_1 V_164 )
{
struct V_1 * V_2 = V_125 -> V_133 ;
const struct V_225 * V_27 = V_2 -> V_27 ;
long V_236 = 0 ;
T_6 V_132 = 0 ;
unsigned int V_31 = 0 ;
if ( ! F_224 ( V_57 ) )
V_31 |= V_237 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_238 ;
T_7 V_228 ;
void * V_224 ;
V_8 = ( V_164 & ( V_140 - 1 ) ) ;
V_238 = F_225 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_239:
if ( F_76 ( F_226 ( V_57 , V_238 ) ) ) {
V_236 = - V_153 ;
break;
}
V_236 = V_27 -> V_227 ( V_125 , V_2 , V_164 , V_238 , V_31 ,
& V_3 , & V_224 ) ;
if ( F_76 ( V_236 < 0 ) )
break;
if ( F_161 ( V_2 ) )
F_162 ( V_3 ) ;
V_228 = F_227 ( V_3 , V_57 , V_8 , V_238 ) ;
F_162 ( V_3 ) ;
V_236 = V_27 -> V_229 ( V_125 , V_2 , V_164 , V_238 , V_228 ,
V_3 , V_224 ) ;
if ( F_76 ( V_236 < 0 ) )
break;
V_228 = V_236 ;
F_51 () ;
F_171 ( V_57 , V_228 ) ;
if ( F_76 ( V_228 == 0 ) ) {
V_238 = F_225 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_239;
}
V_164 += V_228 ;
V_132 += V_228 ;
F_228 ( V_2 ) ;
if ( F_229 ( V_73 ) ) {
V_236 = - V_240 ;
break;
}
} while ( F_164 ( V_57 ) );
return V_132 ? V_132 : V_236 ;
}
T_6 F_230 ( struct V_159 * V_160 , struct V_131 * V_230 )
{
struct V_125 * V_125 = V_160 -> V_161 ;
struct V_1 * V_2 = V_125 -> V_133 ;
struct V_134 * V_134 = V_2 -> V_25 ;
T_1 V_164 = V_160 -> V_163 ;
T_6 V_132 = 0 ;
T_6 V_60 ;
T_6 V_236 ;
T_7 V_141 = F_164 ( V_230 ) ;
V_73 -> V_241 = F_29 ( V_134 ) ;
V_60 = F_208 ( V_125 , & V_164 , & V_141 , F_219 ( V_134 -> V_234 ) ) ;
if ( V_60 )
goto V_54;
if ( V_141 == 0 )
goto V_54;
F_231 ( V_230 , V_141 ) ;
V_60 = F_232 ( V_125 ) ;
if ( V_60 )
goto V_54;
V_60 = F_193 ( V_125 ) ;
if ( V_60 )
goto V_54;
if ( F_170 ( V_125 ) ) {
T_1 V_242 ;
V_132 = F_217 ( V_160 , V_230 , V_164 ) ;
if ( V_132 < 0 || V_132 == V_141 || F_172 ( V_134 ) )
goto V_54;
V_164 += V_132 ;
V_141 -= V_132 ;
V_236 = F_223 ( V_125 , V_230 , V_164 ) ;
if ( F_76 ( V_236 < 0 ) ) {
V_60 = V_236 ;
goto V_54;
}
V_160 -> V_163 = V_164 + V_236 ;
V_242 = V_164 + V_236 - 1 ;
V_60 = F_55 ( V_125 -> V_133 , V_164 , V_242 ) ;
if ( V_60 == 0 ) {
V_132 += V_236 ;
F_233 ( V_2 ,
V_164 >> V_49 ,
V_242 >> V_49 ) ;
} else {
}
} else {
V_132 = F_223 ( V_125 , V_230 , V_164 ) ;
if ( F_181 ( V_132 >= 0 ) )
V_160 -> V_163 = V_164 + V_132 ;
}
V_54:
V_73 -> V_241 = NULL ;
return V_132 ? V_132 : V_60 ;
}
T_6 F_234 ( struct V_159 * V_160 , struct V_131 * V_230 )
{
struct V_125 * V_125 = V_160 -> V_161 ;
struct V_134 * V_134 = V_125 -> V_133 -> V_25 ;
T_6 V_29 ;
F_235 ( & V_134 -> V_243 ) ;
V_29 = F_230 ( V_160 , V_230 ) ;
F_236 ( & V_134 -> V_243 ) ;
if ( V_29 > 0 ) {
T_6 V_60 ;
V_60 = F_237 ( V_125 , V_160 -> V_163 - V_29 , V_29 ) ;
if ( V_60 < 0 )
V_29 = V_60 ;
}
return V_29 ;
}
int F_238 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_239 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_27 -> V_244 )
return V_2 -> V_27 -> V_244 ( V_3 , V_14 ) ;
return F_240 ( V_3 ) ;
}
