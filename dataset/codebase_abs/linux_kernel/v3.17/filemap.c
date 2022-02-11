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
if ( F_30 )
F_30 ( V_3 ) ;
F_33 ( V_3 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
if ( F_7 ( V_30 , & V_2 -> V_31 ) &&
F_35 ( V_30 , & V_2 -> V_31 ) )
V_29 = - V_32 ;
if ( F_7 ( V_33 , & V_2 -> V_31 ) &&
F_35 ( V_33 , & V_2 -> V_31 ) )
V_29 = - V_34 ;
return V_29 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 , int V_37 )
{
int V_29 ;
struct V_38 V_39 = {
. V_37 = V_37 ,
. V_40 = V_41 ,
. V_42 = V_35 ,
. V_43 = V_36 ,
} ;
if ( ! F_37 ( V_2 ) )
return 0 ;
V_29 = F_38 ( V_2 , & V_39 ) ;
return V_29 ;
}
static inline int F_39 ( struct V_1 * V_2 ,
int V_37 )
{
return F_36 ( V_2 , 0 , V_44 , V_37 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_45 ) ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_36 )
{
return F_36 ( V_2 , V_35 , V_36 , V_45 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_46 ) ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_47 ,
T_1 V_48 )
{
T_2 V_7 = V_47 >> V_49 ;
T_2 V_36 = V_48 >> V_49 ;
struct V_50 V_51 ;
int V_52 ;
int V_53 , V_29 = 0 ;
if ( V_48 < V_47 )
goto V_54;
F_44 ( & V_51 , 0 ) ;
while ( ( V_7 <= V_36 ) &&
( V_52 = F_45 ( & V_51 , V_2 , & V_7 ,
V_55 ,
F_46 ( V_36 - V_7 , ( T_2 ) V_56 - 1 ) + 1 ) ) != 0 ) {
unsigned V_57 ;
for ( V_57 = 0 ; V_57 < V_52 ; V_57 ++ ) {
struct V_3 * V_3 = V_51 . V_58 [ V_57 ] ;
if ( V_3 -> V_7 > V_36 )
continue;
F_47 ( V_3 ) ;
if ( F_48 ( V_3 ) )
V_29 = - V_34 ;
}
F_49 ( & V_51 ) ;
F_50 () ;
}
V_54:
V_53 = F_34 ( V_2 ) ;
if ( ! V_29 )
V_29 = V_53 ;
return V_29 ;
}
int F_51 ( struct V_1 * V_2 )
{
T_1 V_59 = F_52 ( V_2 -> V_60 ) ;
if ( V_59 == 0 )
return 0 ;
return F_43 ( V_2 , 0 , V_59 - 1 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_61 = 0 ;
if ( V_2 -> V_13 ) {
V_61 = F_40 ( V_2 ) ;
if ( V_61 != - V_34 ) {
int V_62 = F_51 ( V_2 ) ;
if ( ! V_61 )
V_61 = V_62 ;
}
} else {
V_61 = F_34 ( V_2 ) ;
}
return V_61 ;
}
int F_54 ( struct V_1 * V_2 ,
T_1 V_63 , T_1 V_64 )
{
int V_61 = 0 ;
if ( V_2 -> V_13 ) {
V_61 = F_36 ( V_2 , V_63 , V_64 ,
V_45 ) ;
if ( V_61 != - V_34 ) {
int V_62 = F_43 ( V_2 ,
V_63 , V_64 ) ;
if ( ! V_61 )
V_61 = V_62 ;
}
} else {
V_61 = F_34 ( V_2 ) ;
}
return V_61 ;
}
int F_55 ( struct V_3 * V_65 , struct V_3 * V_66 , T_3 V_14 )
{
int error ;
F_56 ( ! F_3 ( V_65 ) , V_65 ) ;
F_56 ( ! F_3 ( V_66 ) , V_66 ) ;
F_56 ( V_66 -> V_2 , V_66 ) ;
error = F_57 ( V_14 & ~ V_67 ) ;
if ( ! error ) {
struct V_1 * V_2 = V_65 -> V_2 ;
void (* F_30)( struct V_3 * );
T_2 V_8 = V_65 -> V_7 ;
F_30 = V_2 -> V_27 -> F_30 ;
F_58 ( V_66 ) ;
V_66 -> V_2 = V_2 ;
V_66 -> V_7 = V_8 ;
F_31 ( & V_2 -> V_28 ) ;
F_15 ( V_65 , NULL ) ;
error = F_59 ( & V_2 -> V_11 , V_8 , V_66 ) ;
F_23 ( error ) ;
V_2 -> V_13 ++ ;
F_60 ( V_66 , V_22 ) ;
if ( F_22 ( V_66 ) )
F_60 ( V_66 , V_23 ) ;
F_32 ( & V_2 -> V_28 ) ;
F_61 ( V_65 , V_66 , true ) ;
F_62 () ;
if ( F_30 )
F_30 ( V_65 ) ;
F_33 ( V_65 ) ;
}
return error ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_3 , void * * V_68 )
{
struct V_5 * V_6 ;
void * * V_10 ;
int error ;
error = F_64 ( & V_2 -> V_11 , V_3 -> V_7 ,
& V_6 , & V_10 ) ;
if ( error )
return error ;
if ( * V_10 ) {
void * V_69 ;
V_69 = F_65 ( V_10 , & V_2 -> V_28 ) ;
if ( ! F_66 ( V_69 ) )
return - V_70 ;
if ( V_68 )
* V_68 = V_69 ;
V_2 -> V_12 -- ;
if ( V_6 )
F_67 ( V_6 ) ;
}
F_6 ( V_10 , V_3 ) ;
V_2 -> V_13 ++ ;
if ( V_6 ) {
F_68 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_19 ) )
F_69 ( & V_21 ,
& V_6 -> V_19 ) ;
}
return 0 ;
}
static int F_70 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 ,
void * * V_68 )
{
int V_71 = F_71 ( V_3 ) ;
struct V_72 * V_73 ;
int error ;
F_56 ( ! F_3 ( V_3 ) , V_3 ) ;
F_56 ( F_22 ( V_3 ) , V_3 ) ;
if ( ! V_71 ) {
error = F_72 ( V_3 , V_74 -> V_75 ,
V_14 , & V_73 ) ;
if ( error )
return error ;
}
error = F_73 ( V_14 & ~ V_67 ) ;
if ( error ) {
if ( ! V_71 )
F_74 ( V_3 , V_73 ) ;
return error ;
}
F_58 ( V_3 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_7 = V_8 ;
F_31 ( & V_2 -> V_28 ) ;
error = F_63 ( V_2 , V_3 , V_68 ) ;
F_62 () ;
if ( F_75 ( error ) )
goto V_76;
F_60 ( V_3 , V_22 ) ;
F_32 ( & V_2 -> V_28 ) ;
if ( ! V_71 )
F_76 ( V_3 , V_73 , false ) ;
F_77 ( V_3 ) ;
return 0 ;
V_76:
V_3 -> V_2 = NULL ;
F_32 ( & V_2 -> V_28 ) ;
if ( ! V_71 )
F_74 ( V_3 , V_73 ) ;
F_33 ( V_3 ) ;
return error ;
}
int F_78 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
return F_70 ( V_3 , V_2 , V_8 ,
V_14 , NULL ) ;
}
int F_79 ( struct V_3 * V_3 , struct V_1 * V_2 ,
T_2 V_8 , T_3 V_14 )
{
void * V_4 = NULL ;
int V_29 ;
F_80 ( V_3 ) ;
V_29 = F_70 ( V_3 , V_2 , V_8 ,
V_14 , & V_4 ) ;
if ( F_75 ( V_29 ) )
F_81 ( V_3 ) ;
else {
if ( V_4 && F_82 ( V_4 ) ) {
F_83 ( V_3 ) ;
F_84 ( V_3 ) ;
} else
F_85 ( V_3 ) ;
F_86 ( V_3 ) ;
}
return V_29 ;
}
struct V_3 * F_87 ( T_3 V_77 )
{
int V_78 ;
struct V_3 * V_3 ;
if ( F_88 () ) {
unsigned int V_79 ;
do {
V_79 = F_89 () ;
V_78 = F_90 () ;
V_3 = F_91 ( V_78 , V_77 , 0 ) ;
} while ( ! V_3 && F_92 ( V_79 ) );
return V_3 ;
}
return F_93 ( V_77 , 0 ) ;
}
static T_4 * F_94 ( struct V_3 * V_3 )
{
const struct V_80 * V_80 = F_95 ( V_3 ) ;
return & V_80 -> V_81 [ F_96 ( V_3 , V_80 -> V_82 ) ] ;
}
static inline void F_97 ( struct V_3 * V_3 , int V_83 )
{
F_98 ( F_94 ( V_3 ) , & V_3 -> V_31 , V_83 ) ;
}
void F_99 ( struct V_3 * V_3 , int V_84 )
{
F_100 ( V_85 , & V_3 -> V_31 , V_84 ) ;
if ( F_7 ( V_84 , & V_3 -> V_31 ) )
F_101 ( F_94 ( V_3 ) , & V_85 , V_86 ,
V_87 ) ;
}
int F_102 ( struct V_3 * V_3 , int V_84 )
{
F_100 ( V_85 , & V_3 -> V_31 , V_84 ) ;
if ( ! F_7 ( V_84 , & V_3 -> V_31 ) )
return 0 ;
return F_101 ( F_94 ( V_3 ) , & V_85 ,
V_86 , V_88 ) ;
}
void F_103 ( struct V_3 * V_3 , T_5 * V_89 )
{
T_4 * V_90 = F_94 ( V_3 ) ;
unsigned long V_31 ;
F_104 ( & V_90 -> V_91 , V_31 ) ;
F_105 ( V_90 , V_89 ) ;
F_106 ( & V_90 -> V_91 , V_31 ) ;
}
void F_107 ( struct V_3 * V_3 )
{
F_56 ( ! F_3 ( V_3 ) , V_3 ) ;
F_108 ( V_92 , & V_3 -> V_31 ) ;
F_109 () ;
F_97 ( V_3 , V_92 ) ;
}
void F_110 ( struct V_3 * V_3 )
{
if ( F_111 ( V_3 ) ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
}
if ( ! F_114 ( V_3 ) )
F_115 () ;
F_109 () ;
F_97 ( V_3 , V_93 ) ;
}
void F_116 ( struct V_3 * V_3 , int V_94 , int V_61 )
{
if ( V_94 == V_95 ) {
if ( ! V_61 ) {
F_117 ( V_3 ) ;
} else {
F_118 ( V_3 ) ;
F_119 ( V_3 ) ;
}
F_107 ( V_3 ) ;
} else {
if ( V_61 ) {
F_119 ( V_3 ) ;
if ( V_3 -> V_2 )
F_120 ( V_3 -> V_2 , V_61 ) ;
}
F_110 ( V_3 ) ;
}
}
void F_121 ( struct V_3 * V_3 )
{
F_100 ( V_85 , & V_3 -> V_31 , V_92 ) ;
F_122 ( F_94 ( V_3 ) , & V_85 , V_86 ,
V_87 ) ;
}
int F_123 ( struct V_3 * V_3 )
{
F_100 ( V_85 , & V_3 -> V_31 , V_92 ) ;
return F_122 ( F_94 ( V_3 ) , & V_85 ,
V_86 , V_88 ) ;
}
int F_124 ( struct V_3 * V_3 , struct V_96 * V_75 ,
unsigned int V_31 )
{
if ( V_31 & V_97 ) {
if ( V_31 & V_98 )
return 0 ;
F_125 ( & V_75 -> V_99 ) ;
if ( V_31 & V_100 )
F_126 ( V_3 ) ;
else
F_127 ( V_3 ) ;
return 0 ;
} else {
if ( V_31 & V_100 ) {
int V_29 ;
V_29 = F_123 ( V_3 ) ;
if ( V_29 ) {
F_125 ( & V_75 -> V_99 ) ;
return 0 ;
}
} else
F_121 ( V_3 ) ;
return 1 ;
}
}
T_2 F_128 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_101 ; V_57 ++ ) {
struct V_3 * V_3 ;
V_3 = F_129 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_66 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_130 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_101 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_101 ; V_57 ++ ) {
struct V_3 * V_3 ;
V_3 = F_129 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_66 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_102 )
break;
}
return V_7 ;
}
struct V_3 * F_131 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_103 ;
struct V_3 * V_3 ;
F_132 () ;
V_104:
V_3 = NULL ;
V_103 = F_133 ( & V_2 -> V_11 , V_8 ) ;
if ( V_103 ) {
V_3 = F_134 ( V_103 ) ;
if ( F_75 ( ! V_3 ) )
goto V_54;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
goto V_104;
goto V_54;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_103 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
}
V_54:
F_138 () ;
return V_3 ;
}
struct V_3 * F_139 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_131 ( V_2 , V_8 ) ;
if ( V_3 && ! F_135 ( V_3 ) ) {
F_140 ( V_3 ) ;
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_104;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_141 ( struct V_1 * V_2 , T_2 V_8 ,
int V_105 , T_3 V_106 , T_3 V_107 )
{
struct V_3 * V_3 ;
V_104:
V_3 = F_131 ( V_2 , V_8 ) ;
if ( F_66 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_108;
if ( V_105 & V_109 ) {
if ( V_105 & V_110 ) {
if ( ! F_142 ( V_3 ) ) {
F_33 ( V_3 ) ;
return NULL ;
}
} else {
F_140 ( V_3 ) ;
}
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_104;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_105 & V_111 ) )
F_143 ( V_3 ) ;
V_108:
if ( ! V_3 && ( V_105 & V_112 ) ) {
int V_61 ;
if ( ( V_105 & V_113 ) && F_26 ( V_2 ) )
V_106 |= V_114 ;
if ( V_105 & V_115 ) {
V_106 &= ~ V_116 ;
V_107 &= ~ V_116 ;
}
V_3 = F_87 ( V_106 ) ;
if ( ! V_3 )
return NULL ;
if ( F_144 ( ! ( V_105 & V_109 ) ) )
V_105 |= V_109 ;
if ( V_105 & V_111 )
F_145 ( V_3 ) ;
V_61 = F_79 ( V_3 , V_2 , V_8 , V_107 ) ;
if ( F_75 ( V_61 ) ) {
F_33 ( V_3 ) ;
V_3 = NULL ;
if ( V_61 == - V_70 )
goto V_104;
}
}
return V_3 ;
}
unsigned F_146 ( struct V_1 * V_2 ,
T_2 V_35 , unsigned int V_117 ,
struct V_3 * * V_118 , T_2 * V_119 )
{
void * * V_10 ;
unsigned int V_29 = 0 ;
struct V_120 V_121 ;
if ( ! V_117 )
return 0 ;
F_132 () ;
V_122:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
goto V_122;
goto V_123;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
V_123:
V_119 [ V_29 ] = V_121 . V_7 ;
V_118 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_117 )
break;
}
F_138 () ;
return V_29 ;
}
unsigned F_148 ( struct V_1 * V_2 , T_2 V_35 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_120 V_121 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_122:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_104:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
F_149 ( V_121 . V_7 ) ;
goto V_122;
}
continue;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_138 () ;
return V_29 ;
}
unsigned F_150 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_120 V_121 ;
void * * V_10 ;
unsigned int V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_122:
F_151 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_104:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
break;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_122;
}
break;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_121 . V_7 ) {
F_33 ( V_3 ) ;
break;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_138 () ;
return V_29 ;
}
unsigned F_152 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_120 V_121 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_122:
F_153 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_104:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_122;
}
continue;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
V_58 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_52 )
break;
}
F_138 () ;
if ( V_29 )
* V_7 = V_58 [ V_29 - 1 ] -> V_7 + 1 ;
return V_29 ;
}
static void F_154 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_127 -> V_128 /= 4 ;
}
static T_6 F_155 ( struct V_124 * V_125 , T_1 * V_129 ,
struct V_130 * V_121 , T_6 V_131 )
{
struct V_1 * V_2 = V_125 -> V_132 ;
struct V_133 * V_133 = V_2 -> V_60 ;
struct V_126 * V_127 = & V_125 -> V_134 ;
T_2 V_7 ;
T_2 V_135 ;
T_2 V_136 ;
unsigned long V_8 ;
unsigned int V_137 ;
int error = 0 ;
V_7 = * V_129 >> V_49 ;
V_136 = V_127 -> V_138 >> V_49 ;
V_137 = V_127 -> V_138 & ( V_139 - 1 ) ;
V_135 = ( * V_129 + V_121 -> V_140 + V_139 - 1 ) >> V_49 ;
V_8 = * V_129 & ~ V_141 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_142 ;
T_1 V_143 ;
unsigned long V_144 , V_29 ;
F_50 () ;
V_145:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_157 ( V_2 ,
V_127 , V_125 ,
V_7 , V_135 - V_7 ) ;
V_3 = F_156 ( V_2 , V_7 ) ;
if ( F_75 ( V_3 == NULL ) )
goto V_146;
}
if ( F_158 ( V_3 ) ) {
F_159 ( V_2 ,
V_127 , V_125 , V_3 ,
V_7 , V_135 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_133 -> V_147 == V_49 ||
! V_2 -> V_27 -> V_148 )
goto V_149;
if ( ! F_142 ( V_3 ) )
goto V_149;
if ( ! V_3 -> V_2 )
goto V_150;
if ( ! V_2 -> V_27 -> V_148 ( V_3 ,
V_8 , V_121 -> V_140 ) )
goto V_150;
F_107 ( V_3 ) ;
}
V_151:
V_143 = F_52 ( V_133 ) ;
V_142 = ( V_143 - 1 ) >> V_49 ;
if ( F_75 ( ! V_143 || V_7 > V_142 ) ) {
F_33 ( V_3 ) ;
goto V_54;
}
V_144 = V_139 ;
if ( V_7 == V_142 ) {
V_144 = ( ( V_143 - 1 ) & ~ V_141 ) + 1 ;
if ( V_144 <= V_8 ) {
F_33 ( V_3 ) ;
goto V_54;
}
}
V_144 = V_144 - V_8 ;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
if ( V_136 != V_7 || V_8 != V_137 )
F_143 ( V_3 ) ;
V_136 = V_7 ;
V_29 = F_162 ( V_3 , V_8 , V_144 , V_121 ) ;
V_8 += V_29 ;
V_7 += V_8 >> V_49 ;
V_8 &= ~ V_141 ;
V_137 = V_8 ;
F_33 ( V_3 ) ;
V_131 += V_29 ;
if ( ! F_163 ( V_121 ) )
goto V_54;
if ( V_29 < V_144 ) {
error = - V_152 ;
goto V_54;
}
continue;
V_149:
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_153;
V_150:
if ( ! V_3 -> V_2 ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_107 ( V_3 ) ;
goto V_151;
}
V_154:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_154 ( V_125 , V_3 ) ;
if ( F_75 ( error ) ) {
if ( error == V_155 ) {
F_33 ( V_3 ) ;
error = 0 ;
goto V_145;
}
goto V_153;
}
if ( ! F_17 ( V_3 ) ) {
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_153;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_145;
}
F_107 ( V_3 ) ;
F_154 ( V_125 , V_127 ) ;
error = - V_34 ;
goto V_153;
}
F_107 ( V_3 ) ;
}
goto V_151;
V_153:
F_33 ( V_3 ) ;
goto V_54;
V_146:
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_156 ;
goto V_54;
}
error = F_79 ( V_3 , V_2 ,
V_7 , V_157 ) ;
if ( error ) {
F_33 ( V_3 ) ;
if ( error == - V_70 ) {
error = 0 ;
goto V_145;
}
goto V_54;
}
goto V_154;
}
V_54:
V_127 -> V_138 = V_136 ;
V_127 -> V_138 <<= V_49 ;
V_127 -> V_138 |= V_137 ;
* V_129 = ( ( T_1 ) V_7 << V_49 ) + V_8 ;
F_167 ( V_125 ) ;
return V_131 ? V_131 : error ;
}
T_6
F_168 ( struct V_158 * V_159 , struct V_130 * V_121 )
{
struct V_124 * V_124 = V_159 -> V_160 ;
T_6 V_161 = 0 ;
T_1 * V_129 = & V_159 -> V_162 ;
T_1 V_163 = * V_129 ;
if ( V_124 -> V_164 & V_165 ) {
struct V_1 * V_2 = V_124 -> V_132 ;
struct V_133 * V_133 = V_2 -> V_60 ;
T_7 V_140 = F_163 ( V_121 ) ;
T_1 V_166 ;
if ( ! V_140 )
goto V_54;
V_166 = F_52 ( V_133 ) ;
V_161 = F_54 ( V_2 , V_163 ,
V_163 + V_140 - 1 ) ;
if ( ! V_161 ) {
struct V_130 V_167 = * V_121 ;
V_161 = V_2 -> V_27 -> V_168 ( V_95 , V_159 , & V_167 , V_163 ) ;
}
if ( V_161 > 0 ) {
* V_129 = V_163 + V_161 ;
F_169 ( V_121 , V_161 ) ;
}
if ( V_161 < 0 || ! F_163 ( V_121 ) || * V_129 >= V_166 ) {
F_167 ( V_124 ) ;
goto V_54;
}
}
V_161 = F_155 ( V_124 , V_129 , V_121 , V_161 ) ;
V_54:
return V_161 ;
}
static int F_170 ( struct V_124 * V_124 , T_2 V_8 )
{
struct V_1 * V_2 = V_124 -> V_132 ;
struct V_3 * V_3 ;
int V_29 ;
do {
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 )
return - V_156 ;
V_29 = F_79 ( V_3 , V_2 , V_8 , V_157 ) ;
if ( V_29 == 0 )
V_29 = V_2 -> V_27 -> V_154 ( V_124 , V_3 ) ;
else if ( V_29 == - V_70 )
V_29 = 0 ;
F_33 ( V_3 ) ;
} while ( V_29 == V_155 );
return V_29 ;
}
static void F_171 ( struct V_169 * V_170 ,
struct V_126 * V_127 ,
struct V_124 * V_124 ,
T_2 V_8 )
{
unsigned long V_128 ;
struct V_1 * V_2 = V_124 -> V_132 ;
if ( V_170 -> V_171 & V_172 )
return;
if ( ! V_127 -> V_128 )
return;
if ( V_170 -> V_171 & V_173 ) {
F_157 ( V_2 , V_127 , V_124 , V_8 ,
V_127 -> V_128 ) ;
return;
}
if ( V_127 -> V_174 < V_175 * 10 )
V_127 -> V_174 ++ ;
if ( V_127 -> V_174 > V_175 )
return;
V_128 = F_172 ( V_127 -> V_128 ) ;
V_127 -> V_35 = F_173 ( long , 0 , V_8 - V_128 / 2 ) ;
V_127 -> V_166 = V_128 ;
V_127 -> V_176 = V_128 / 4 ;
F_174 ( V_127 , V_2 , V_124 ) ;
}
static void F_175 ( struct V_169 * V_170 ,
struct V_126 * V_127 ,
struct V_124 * V_124 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_124 -> V_132 ;
if ( V_170 -> V_171 & V_172 )
return;
if ( V_127 -> V_174 > 0 )
V_127 -> V_174 -- ;
if ( F_158 ( V_3 ) )
F_159 ( V_2 , V_127 , V_124 ,
V_3 , V_8 , V_127 -> V_128 ) ;
}
int F_176 ( struct V_169 * V_170 , struct V_177 * V_178 )
{
int error ;
struct V_124 * V_124 = V_170 -> V_179 ;
struct V_1 * V_2 = V_124 -> V_132 ;
struct V_126 * V_127 = & V_124 -> V_134 ;
struct V_133 * V_133 = V_2 -> V_60 ;
T_2 V_8 = V_178 -> V_180 ;
struct V_3 * V_3 ;
T_1 V_166 ;
int V_29 = 0 ;
V_166 = F_177 ( F_52 ( V_133 ) , V_139 ) ;
if ( V_8 >= V_166 >> V_49 )
return V_181 ;
V_3 = F_156 ( V_2 , V_8 ) ;
if ( F_178 ( V_3 ) && ! ( V_178 -> V_31 & V_182 ) ) {
F_175 ( V_170 , V_127 , V_124 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_171 ( V_170 , V_127 , V_124 , V_8 ) ;
F_179 ( V_183 ) ;
F_180 ( V_170 -> V_184 , V_183 ) ;
V_29 = V_185 ;
V_186:
V_3 = F_156 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_146;
}
if ( ! F_181 ( V_3 , V_170 -> V_184 , V_178 -> V_31 ) ) {
F_33 ( V_3 ) ;
return V_29 | V_187 ;
}
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_107 ( V_3 ) ;
F_182 ( V_3 ) ;
goto V_186;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_75 ( ! F_17 ( V_3 ) ) )
goto V_188;
V_166 = F_177 ( F_52 ( V_133 ) , V_139 ) ;
if ( F_75 ( V_8 >= V_166 >> V_49 ) ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
return V_181 ;
}
V_178 -> V_3 = V_3 ;
return V_29 | V_189 ;
V_146:
error = F_170 ( V_124 , V_8 ) ;
if ( error >= 0 )
goto V_186;
if ( error == - V_156 )
return V_190 ;
return V_181 ;
V_188:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_154 ( V_124 , V_3 ) ;
if ( ! error ) {
F_127 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_34 ;
}
F_33 ( V_3 ) ;
if ( ! error || error == V_155 )
goto V_186;
F_154 ( V_124 , V_127 ) ;
return V_181 ;
}
void F_183 ( struct V_169 * V_170 , struct V_177 * V_178 )
{
struct V_120 V_121 ;
void * * V_10 ;
struct V_124 * V_124 = V_170 -> V_179 ;
struct V_1 * V_2 = V_124 -> V_132 ;
T_1 V_166 ;
struct V_3 * V_3 ;
unsigned long V_191 = ( unsigned long ) V_178 -> V_192 ;
unsigned long V_193 ;
T_8 * V_194 ;
F_132 () ;
F_147 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_121 . V_7 > V_178 -> V_195 )
break;
V_104:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
goto V_196;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
break;
else
goto V_196;
}
if ( ! F_137 ( V_3 ) )
goto V_104;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_104;
}
if ( ! F_17 ( V_3 ) ||
F_158 ( V_3 ) ||
F_184 ( V_3 ) )
goto V_197;
if ( ! F_142 ( V_3 ) )
goto V_197;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_198;
V_166 = F_177 ( F_52 ( V_2 -> V_60 ) , V_139 ) ;
if ( V_3 -> V_7 >= V_166 >> V_49 )
goto V_198;
V_194 = V_178 -> V_194 + V_3 -> V_7 - V_178 -> V_180 ;
if ( ! F_185 ( * V_194 ) )
goto V_198;
if ( V_124 -> V_134 . V_174 > 0 )
V_124 -> V_134 . V_174 -- ;
V_193 = V_191 + ( V_3 -> V_7 - V_178 -> V_180 ) * V_199 ;
F_186 ( V_170 , V_193 , V_3 , V_194 , false , false ) ;
F_107 ( V_3 ) ;
goto V_196;
V_198:
F_107 ( V_3 ) ;
V_197:
F_33 ( V_3 ) ;
V_196:
if ( V_121 . V_7 == V_178 -> V_195 )
break;
}
F_138 () ;
}
int F_187 ( struct V_169 * V_170 , struct V_177 * V_178 )
{
struct V_3 * V_3 = V_178 -> V_3 ;
struct V_133 * V_133 = F_188 ( V_170 -> V_179 ) ;
int V_29 = V_189 ;
F_189 ( V_133 -> V_200 ) ;
F_190 ( V_170 -> V_179 ) ;
F_140 ( V_3 ) ;
if ( V_3 -> V_2 != V_133 -> V_201 ) {
F_107 ( V_3 ) ;
V_29 = V_202 ;
goto V_54;
}
F_191 ( V_3 ) ;
F_192 ( V_3 ) ;
V_54:
F_193 ( V_133 -> V_200 ) ;
return V_29 ;
}
int F_194 ( struct V_124 * V_124 , struct V_169 * V_170 )
{
struct V_1 * V_2 = V_124 -> V_132 ;
if ( ! V_2 -> V_27 -> V_154 )
return - V_203 ;
F_167 ( V_124 ) ;
V_170 -> V_204 = & V_205 ;
return 0 ;
}
int F_195 ( struct V_124 * V_124 , struct V_169 * V_170 )
{
if ( ( V_170 -> V_171 & V_206 ) && ( V_170 -> V_171 & V_207 ) )
return - V_208 ;
return F_194 ( V_124 , V_170 ) ;
}
int F_194 ( struct V_124 * V_124 , struct V_169 * V_170 )
{
return - V_209 ;
}
int F_195 ( struct V_124 * V_124 , struct V_169 * V_170 )
{
return - V_209 ;
}
static struct V_3 * F_196 ( struct V_3 * V_3 )
{
if ( ! F_197 ( V_3 ) ) {
F_127 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_33 ( V_3 ) ;
V_3 = F_198 ( - V_34 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_199 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_167 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_104:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_87 ( V_77 | V_210 ) ;
if ( ! V_3 )
return F_198 ( - V_156 ) ;
V_61 = F_79 ( V_3 , V_2 , V_7 , V_77 ) ;
if ( F_75 ( V_61 ) ) {
F_33 ( V_3 ) ;
if ( V_61 == - V_70 )
goto V_104;
return F_198 ( V_61 ) ;
}
V_61 = F_200 ( V_167 , V_3 ) ;
if ( V_61 < 0 ) {
F_33 ( V_3 ) ;
V_3 = F_198 ( V_61 ) ;
} else {
V_3 = F_196 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_201 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_167 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_211:
V_3 = F_199 ( V_2 , V_7 , F_200 , V_167 , V_77 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_54;
F_140 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_107 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_211;
}
if ( F_17 ( V_3 ) ) {
F_107 ( V_3 ) ;
goto V_54;
}
V_61 = F_200 ( V_167 , V_3 ) ;
if ( V_61 < 0 ) {
F_33 ( V_3 ) ;
return F_198 ( V_61 ) ;
} else {
V_3 = F_196 ( V_3 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
}
V_54:
F_143 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_202 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_200)( void * , struct V_3 * ) ,
void * V_167 )
{
return F_201 ( V_2 , V_7 , F_200 , V_167 , F_203 ( V_2 ) ) ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_77 )
{
T_9 * F_200 = ( T_9 * ) V_2 -> V_27 -> V_154 ;
return F_201 ( V_2 , V_7 , F_200 , NULL , V_77 ) ;
}
inline int F_205 ( struct V_124 * V_124 , T_1 * V_163 , T_7 * V_140 , int V_212 )
{
struct V_133 * V_133 = V_124 -> V_132 -> V_60 ;
unsigned long V_213 = F_206 ( V_214 ) ;
if ( F_75 ( * V_163 < 0 ) )
return - V_208 ;
if ( ! V_212 ) {
if ( V_124 -> V_164 & V_215 )
* V_163 = F_52 ( V_133 ) ;
if ( V_213 != V_216 ) {
if ( * V_163 >= V_213 ) {
F_207 ( V_217 , V_74 , 0 ) ;
return - V_218 ;
}
if ( * V_140 > V_213 - ( F_208 ( V_213 ) ) * V_163 ) {
* V_140 = V_213 - ( F_208 ( V_213 ) ) * V_163 ;
}
}
}
if ( F_75 ( * V_163 + * V_140 > V_219 &&
! ( V_124 -> V_164 & V_220 ) ) ) {
if ( * V_163 >= V_219 ) {
return - V_218 ;
}
if ( * V_140 > V_219 - ( unsigned long ) * V_163 ) {
* V_140 = V_219 - ( unsigned long ) * V_163 ;
}
}
if ( F_178 ( ! V_212 ) ) {
if ( F_75 ( * V_163 >= V_133 -> V_200 -> V_221 ) ) {
if ( * V_140 || * V_163 > V_133 -> V_200 -> V_221 ) {
return - V_218 ;
}
}
if ( F_75 ( * V_163 + * V_140 > V_133 -> V_200 -> V_221 ) )
* V_140 = V_133 -> V_200 -> V_221 - * V_163 ;
} else {
#ifdef F_209
T_1 V_143 ;
if ( F_210 ( F_211 ( V_133 ) ) )
return - V_222 ;
V_143 = F_52 ( V_133 ) ;
if ( * V_163 >= V_143 ) {
if ( * V_140 || * V_163 > V_143 )
return - V_32 ;
}
if ( * V_163 + * V_140 > V_143 )
* V_140 = V_143 - * V_163 ;
#else
return - V_222 ;
#endif
}
return 0 ;
}
int F_212 ( struct V_124 * V_124 , struct V_1 * V_2 ,
T_1 V_163 , unsigned V_223 , unsigned V_31 ,
struct V_3 * * V_103 , void * * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_27 ;
return V_226 -> V_227 ( V_124 , V_2 , V_163 , V_223 , V_31 ,
V_103 , V_224 ) ;
}
int F_213 ( struct V_124 * V_124 , struct V_1 * V_2 ,
T_1 V_163 , unsigned V_223 , unsigned V_228 ,
struct V_3 * V_3 , void * V_224 )
{
const struct V_225 * V_226 = V_2 -> V_27 ;
return V_226 -> V_229 ( V_124 , V_2 , V_163 , V_223 , V_228 , V_3 , V_224 ) ;
}
T_6
F_214 ( struct V_158 * V_159 , struct V_130 * V_230 , T_1 V_163 )
{
struct V_124 * V_124 = V_159 -> V_160 ;
struct V_1 * V_2 = V_124 -> V_132 ;
struct V_133 * V_133 = V_2 -> V_60 ;
T_6 V_131 ;
T_7 V_231 ;
T_2 V_36 ;
struct V_130 V_167 ;
V_231 = F_163 ( V_230 ) ;
V_36 = ( V_163 + V_231 - 1 ) >> V_49 ;
V_131 = F_54 ( V_2 , V_163 , V_163 + V_231 - 1 ) ;
if ( V_131 )
goto V_54;
if ( V_2 -> V_13 ) {
V_131 = F_215 ( V_2 ,
V_163 >> V_49 , V_36 ) ;
if ( V_131 ) {
if ( V_131 == - V_232 )
return 0 ;
goto V_54;
}
}
V_167 = * V_230 ;
V_131 = V_2 -> V_27 -> V_168 ( V_233 , V_159 , & V_167 , V_163 ) ;
if ( V_2 -> V_13 ) {
F_215 ( V_2 ,
V_163 >> V_49 , V_36 ) ;
}
if ( V_131 > 0 ) {
V_163 += V_131 ;
F_169 ( V_230 , V_131 ) ;
if ( V_163 > F_52 ( V_133 ) && ! F_216 ( V_133 -> V_234 ) ) {
F_217 ( V_133 , V_163 ) ;
F_218 ( V_133 ) ;
}
V_159 -> V_162 = V_163 ;
}
V_54:
return V_131 ;
}
struct V_3 * F_219 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_31 )
{
struct V_3 * V_3 ;
int V_105 = V_109 | V_111 | V_113 | V_112 ;
if ( V_31 & V_235 )
V_105 |= V_115 ;
V_3 = F_141 ( V_2 , V_7 , V_105 ,
F_203 ( V_2 ) ,
V_157 ) ;
if ( V_3 )
F_192 ( V_3 ) ;
return V_3 ;
}
T_6 F_220 ( struct V_124 * V_124 ,
struct V_130 * V_57 , T_1 V_163 )
{
struct V_1 * V_2 = V_124 -> V_132 ;
const struct V_225 * V_27 = V_2 -> V_27 ;
long V_236 = 0 ;
T_6 V_131 = 0 ;
unsigned int V_31 = 0 ;
if ( F_221 ( F_222 () , V_237 ) )
V_31 |= V_238 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_239 ;
T_7 V_228 ;
void * V_224 ;
V_8 = ( V_163 & ( V_139 - 1 ) ) ;
V_239 = F_223 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_240:
if ( F_75 ( F_224 ( V_57 , V_239 ) ) ) {
V_236 = - V_152 ;
break;
}
V_236 = V_27 -> V_227 ( V_124 , V_2 , V_163 , V_239 , V_31 ,
& V_3 , & V_224 ) ;
if ( F_75 ( V_236 < 0 ) )
break;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
V_228 = F_225 ( V_3 , V_57 , V_8 , V_239 ) ;
F_161 ( V_3 ) ;
V_236 = V_27 -> V_229 ( V_124 , V_2 , V_163 , V_239 , V_228 ,
V_3 , V_224 ) ;
if ( F_75 ( V_236 < 0 ) )
break;
V_228 = V_236 ;
F_50 () ;
F_169 ( V_57 , V_228 ) ;
if ( F_75 ( V_228 == 0 ) ) {
V_239 = F_223 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_240;
}
V_163 += V_228 ;
V_131 += V_228 ;
F_226 ( V_2 ) ;
if ( F_227 ( V_74 ) ) {
V_236 = - V_241 ;
break;
}
} while ( F_163 ( V_57 ) );
return V_131 ? V_131 : V_236 ;
}
T_6 F_228 ( struct V_158 * V_159 , struct V_130 * V_230 )
{
struct V_124 * V_124 = V_159 -> V_160 ;
struct V_1 * V_2 = V_124 -> V_132 ;
struct V_133 * V_133 = V_2 -> V_60 ;
T_1 V_163 = V_159 -> V_162 ;
T_6 V_131 = 0 ;
T_6 V_61 ;
T_6 V_236 ;
T_7 V_140 = F_163 ( V_230 ) ;
V_74 -> V_25 = V_2 -> V_25 ;
V_61 = F_205 ( V_124 , & V_163 , & V_140 , F_216 ( V_133 -> V_234 ) ) ;
if ( V_61 )
goto V_54;
if ( V_140 == 0 )
goto V_54;
F_229 ( V_230 , V_140 ) ;
V_61 = F_230 ( V_124 ) ;
if ( V_61 )
goto V_54;
V_61 = F_190 ( V_124 ) ;
if ( V_61 )
goto V_54;
if ( F_75 ( V_124 -> V_164 & V_165 ) ) {
T_1 V_242 ;
V_131 = F_214 ( V_159 , V_230 , V_163 ) ;
if ( V_131 < 0 || V_131 == V_140 )
goto V_54;
V_163 += V_131 ;
V_140 -= V_131 ;
V_236 = F_220 ( V_124 , V_230 , V_163 ) ;
if ( F_75 ( V_236 < 0 ) ) {
V_61 = V_236 ;
goto V_54;
}
V_159 -> V_162 = V_163 + V_236 ;
V_242 = V_163 + V_236 - 1 ;
V_61 = F_54 ( V_124 -> V_132 , V_163 , V_242 ) ;
if ( V_61 == 0 ) {
V_131 += V_236 ;
F_231 ( V_2 ,
V_163 >> V_49 ,
V_242 >> V_49 ) ;
} else {
}
} else {
V_131 = F_220 ( V_124 , V_230 , V_163 ) ;
if ( F_178 ( V_131 >= 0 ) )
V_159 -> V_162 = V_163 + V_131 ;
}
V_54:
V_74 -> V_25 = NULL ;
return V_131 ? V_131 : V_61 ;
}
T_6 F_232 ( struct V_158 * V_159 , struct V_130 * V_230 )
{
struct V_124 * V_124 = V_159 -> V_160 ;
struct V_133 * V_133 = V_124 -> V_132 -> V_60 ;
T_6 V_29 ;
F_233 ( & V_133 -> V_243 ) ;
V_29 = F_228 ( V_159 , V_230 ) ;
F_234 ( & V_133 -> V_243 ) ;
if ( V_29 > 0 ) {
T_6 V_61 ;
V_61 = F_235 ( V_124 , V_159 -> V_162 - V_29 , V_29 ) ;
if ( V_61 < 0 )
V_29 = V_61 ;
}
return V_29 ;
}
int F_236 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_237 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_27 -> V_244 )
return V_2 -> V_27 -> V_244 ( V_3 , V_14 ) ;
return F_238 ( V_3 ) ;
}
