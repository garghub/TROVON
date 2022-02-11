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
T_4 * F_94 ( struct V_3 * V_3 )
{
const struct V_80 * V_80 = F_95 ( V_3 ) ;
return & V_80 -> V_81 [ F_96 ( V_3 , V_80 -> V_82 ) ] ;
}
void F_97 ( struct V_3 * V_3 , int V_83 )
{
F_98 ( V_84 , & V_3 -> V_31 , V_83 ) ;
if ( F_7 ( V_83 , & V_3 -> V_31 ) )
F_99 ( F_94 ( V_3 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_100 ( struct V_3 * V_3 , int V_83 )
{
F_98 ( V_84 , & V_3 -> V_31 , V_83 ) ;
if ( ! F_7 ( V_83 , & V_3 -> V_31 ) )
return 0 ;
return F_99 ( F_94 ( V_3 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_101 ( struct V_3 * V_3 ,
int V_83 , unsigned long V_88 )
{
F_98 ( V_84 , & V_3 -> V_31 , V_83 ) ;
V_84 . V_89 . V_88 = V_90 + V_88 ;
if ( ! F_7 ( V_83 , & V_3 -> V_31 ) )
return 0 ;
return F_99 ( F_94 ( V_3 ) , & V_84 ,
V_91 , V_87 ) ;
}
void F_102 ( struct V_3 * V_3 , T_5 * V_92 )
{
T_4 * V_93 = F_94 ( V_3 ) ;
unsigned long V_31 ;
F_103 ( & V_93 -> V_94 , V_31 ) ;
F_104 ( V_93 , V_92 ) ;
F_105 ( & V_93 -> V_94 , V_31 ) ;
}
void F_106 ( struct V_3 * V_3 )
{
F_56 ( ! F_3 ( V_3 ) , V_3 ) ;
F_107 ( V_95 , & V_3 -> V_31 ) ;
F_108 () ;
F_109 ( V_3 , V_95 ) ;
}
void F_110 ( struct V_3 * V_3 )
{
if ( F_111 ( V_3 ) ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
}
if ( ! F_114 ( V_3 ) )
F_115 () ;
F_108 () ;
F_109 ( V_3 , V_96 ) ;
}
void F_116 ( struct V_3 * V_3 , int V_97 , int V_61 )
{
if ( V_97 == V_98 ) {
if ( ! V_61 ) {
F_117 ( V_3 ) ;
} else {
F_118 ( V_3 ) ;
F_119 ( V_3 ) ;
}
F_106 ( V_3 ) ;
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
F_98 ( V_84 , & V_3 -> V_31 , V_95 ) ;
F_122 ( F_94 ( V_3 ) , & V_84 , V_85 ,
V_86 ) ;
}
int F_123 ( struct V_3 * V_3 )
{
F_98 ( V_84 , & V_3 -> V_31 , V_95 ) ;
return F_122 ( F_94 ( V_3 ) , & V_84 ,
V_85 , V_87 ) ;
}
int F_124 ( struct V_3 * V_3 , struct V_99 * V_75 ,
unsigned int V_31 )
{
if ( V_31 & V_100 ) {
if ( V_31 & V_101 )
return 0 ;
F_125 ( & V_75 -> V_102 ) ;
if ( V_31 & V_103 )
F_126 ( V_3 ) ;
else
F_127 ( V_3 ) ;
return 0 ;
} else {
if ( V_31 & V_103 ) {
int V_29 ;
V_29 = F_123 ( V_3 ) ;
if ( V_29 ) {
F_125 ( & V_75 -> V_102 ) ;
return 0 ;
}
} else
F_121 ( V_3 ) ;
return 1 ;
}
}
T_2 F_128 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_104 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_104 ; V_57 ++ ) {
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
T_2 V_7 , unsigned long V_104 )
{
unsigned long V_57 ;
for ( V_57 = 0 ; V_57 < V_104 ; V_57 ++ ) {
struct V_3 * V_3 ;
V_3 = F_129 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_66 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_105 )
break;
}
return V_7 ;
}
struct V_3 * F_131 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_106 ;
struct V_3 * V_3 ;
F_132 () ;
V_107:
V_3 = NULL ;
V_106 = F_133 ( & V_2 -> V_11 , V_8 ) ;
if ( V_106 ) {
V_3 = F_134 ( V_106 ) ;
if ( F_75 ( ! V_3 ) )
goto V_54;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
goto V_107;
goto V_54;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_106 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
}
V_54:
F_138 () ;
return V_3 ;
}
struct V_3 * F_139 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_107:
V_3 = F_131 ( V_2 , V_8 ) ;
if ( V_3 && ! F_135 ( V_3 ) ) {
F_140 ( V_3 ) ;
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_107;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_141 ( struct V_1 * V_2 , T_2 V_8 ,
int V_108 , T_3 V_109 , T_3 V_110 )
{
struct V_3 * V_3 ;
V_107:
V_3 = F_131 ( V_2 , V_8 ) ;
if ( F_66 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_111;
if ( V_108 & V_112 ) {
if ( V_108 & V_113 ) {
if ( ! F_142 ( V_3 ) ) {
F_33 ( V_3 ) ;
return NULL ;
}
} else {
F_140 ( V_3 ) ;
}
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_107;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
if ( V_3 && ( V_108 & V_114 ) )
F_143 ( V_3 ) ;
V_111:
if ( ! V_3 && ( V_108 & V_115 ) ) {
int V_61 ;
if ( ( V_108 & V_116 ) && F_26 ( V_2 ) )
V_109 |= V_117 ;
if ( V_108 & V_118 ) {
V_109 &= ~ V_119 ;
V_110 &= ~ V_119 ;
}
V_3 = F_87 ( V_109 ) ;
if ( ! V_3 )
return NULL ;
if ( F_144 ( ! ( V_108 & V_112 ) ) )
V_108 |= V_112 ;
if ( V_108 & V_114 )
F_145 ( V_3 ) ;
V_61 = F_79 ( V_3 , V_2 , V_8 , V_110 ) ;
if ( F_75 ( V_61 ) ) {
F_33 ( V_3 ) ;
V_3 = NULL ;
if ( V_61 == - V_70 )
goto V_107;
}
}
return V_3 ;
}
unsigned F_146 ( struct V_1 * V_2 ,
T_2 V_35 , unsigned int V_120 ,
struct V_3 * * V_121 , T_2 * V_122 )
{
void * * V_10 ;
unsigned int V_29 = 0 ;
struct V_123 V_124 ;
if ( ! V_120 )
return 0 ;
F_132 () ;
V_125:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
goto V_125;
goto V_126;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
V_126:
V_122 [ V_29 ] = V_124 . V_7 ;
V_121 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_120 )
break;
}
F_138 () ;
return V_29 ;
}
unsigned F_148 ( struct V_1 * V_2 , T_2 V_35 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_123 V_124 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_125:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
F_149 ( V_124 . V_7 ) ;
goto V_125;
}
continue;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
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
struct V_123 V_124 ;
void * * V_10 ;
unsigned int V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_125:
F_151 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
break;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_125;
}
break;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_124 . V_7 ) {
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
struct V_123 V_124 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_125:
F_153 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_125;
}
continue;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
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
static void F_154 ( struct V_127 * V_128 ,
struct V_129 * V_130 )
{
V_130 -> V_131 /= 4 ;
}
static T_6 F_155 ( struct V_127 * V_128 , T_1 * V_132 ,
struct V_133 * V_124 , T_6 V_134 )
{
struct V_1 * V_2 = V_128 -> V_135 ;
struct V_136 * V_136 = V_2 -> V_60 ;
struct V_129 * V_130 = & V_128 -> V_137 ;
T_2 V_7 ;
T_2 V_138 ;
T_2 V_139 ;
unsigned long V_8 ;
unsigned int V_140 ;
int error = 0 ;
V_7 = * V_132 >> V_49 ;
V_139 = V_130 -> V_141 >> V_49 ;
V_140 = V_130 -> V_141 & ( V_142 - 1 ) ;
V_138 = ( * V_132 + V_124 -> V_143 + V_142 - 1 ) >> V_49 ;
V_8 = * V_132 & ~ V_144 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_145 ;
T_1 V_146 ;
unsigned long V_147 , V_29 ;
F_50 () ;
V_148:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_157 ( V_2 ,
V_130 , V_128 ,
V_7 , V_138 - V_7 ) ;
V_3 = F_156 ( V_2 , V_7 ) ;
if ( F_75 ( V_3 == NULL ) )
goto V_149;
}
if ( F_158 ( V_3 ) ) {
F_159 ( V_2 ,
V_130 , V_128 , V_3 ,
V_7 , V_138 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_136 -> V_150 == V_49 ||
! V_2 -> V_27 -> V_151 )
goto V_152;
if ( ! F_142 ( V_3 ) )
goto V_152;
if ( ! V_3 -> V_2 )
goto V_153;
if ( ! V_2 -> V_27 -> V_151 ( V_3 ,
V_8 , V_124 -> V_143 ) )
goto V_153;
F_106 ( V_3 ) ;
}
V_154:
V_146 = F_52 ( V_136 ) ;
V_145 = ( V_146 - 1 ) >> V_49 ;
if ( F_75 ( ! V_146 || V_7 > V_145 ) ) {
F_33 ( V_3 ) ;
goto V_54;
}
V_147 = V_142 ;
if ( V_7 == V_145 ) {
V_147 = ( ( V_146 - 1 ) & ~ V_144 ) + 1 ;
if ( V_147 <= V_8 ) {
F_33 ( V_3 ) ;
goto V_54;
}
}
V_147 = V_147 - V_8 ;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
if ( V_139 != V_7 || V_8 != V_140 )
F_143 ( V_3 ) ;
V_139 = V_7 ;
V_29 = F_162 ( V_3 , V_8 , V_147 , V_124 ) ;
V_8 += V_29 ;
V_7 += V_8 >> V_49 ;
V_8 &= ~ V_144 ;
V_140 = V_8 ;
F_33 ( V_3 ) ;
V_134 += V_29 ;
if ( ! F_163 ( V_124 ) )
goto V_54;
if ( V_29 < V_147 ) {
error = - V_155 ;
goto V_54;
}
continue;
V_152:
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_156;
V_153:
if ( ! V_3 -> V_2 ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_106 ( V_3 ) ;
goto V_154;
}
V_157:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_157 ( V_128 , V_3 ) ;
if ( F_75 ( error ) ) {
if ( error == V_158 ) {
F_33 ( V_3 ) ;
error = 0 ;
goto V_148;
}
goto V_156;
}
if ( ! F_17 ( V_3 ) ) {
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_156;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_148;
}
F_106 ( V_3 ) ;
F_154 ( V_128 , V_130 ) ;
error = - V_34 ;
goto V_156;
}
F_106 ( V_3 ) ;
}
goto V_154;
V_156:
F_33 ( V_3 ) ;
goto V_54;
V_149:
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_159 ;
goto V_54;
}
error = F_79 ( V_3 , V_2 ,
V_7 , V_160 ) ;
if ( error ) {
F_33 ( V_3 ) ;
if ( error == - V_70 ) {
error = 0 ;
goto V_148;
}
goto V_54;
}
goto V_157;
}
V_54:
V_130 -> V_141 = V_139 ;
V_130 -> V_141 <<= V_49 ;
V_130 -> V_141 |= V_140 ;
* V_132 = ( ( T_1 ) V_7 << V_49 ) + V_8 ;
F_167 ( V_128 ) ;
return V_134 ? V_134 : error ;
}
T_6
F_168 ( struct V_161 * V_162 , struct V_133 * V_124 )
{
struct V_127 * V_127 = V_162 -> V_163 ;
T_6 V_164 = 0 ;
T_1 * V_132 = & V_162 -> V_165 ;
T_1 V_166 = * V_132 ;
if ( V_127 -> V_167 & V_168 ) {
struct V_1 * V_2 = V_127 -> V_135 ;
struct V_136 * V_136 = V_2 -> V_60 ;
T_7 V_143 = F_163 ( V_124 ) ;
T_1 V_169 ;
if ( ! V_143 )
goto V_54;
V_169 = F_52 ( V_136 ) ;
V_164 = F_54 ( V_2 , V_166 ,
V_166 + V_143 - 1 ) ;
if ( ! V_164 ) {
struct V_133 V_170 = * V_124 ;
V_164 = V_2 -> V_27 -> V_171 ( V_98 , V_162 , & V_170 , V_166 ) ;
}
if ( V_164 > 0 ) {
* V_132 = V_166 + V_164 ;
F_169 ( V_124 , V_164 ) ;
}
if ( V_164 < 0 || ! F_163 ( V_124 ) || * V_132 >= V_169 ) {
F_167 ( V_127 ) ;
goto V_54;
}
}
V_164 = F_155 ( V_127 , V_132 , V_124 , V_164 ) ;
V_54:
return V_164 ;
}
static int F_170 ( struct V_127 * V_127 , T_2 V_8 )
{
struct V_1 * V_2 = V_127 -> V_135 ;
struct V_3 * V_3 ;
int V_29 ;
do {
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 )
return - V_159 ;
V_29 = F_79 ( V_3 , V_2 , V_8 , V_160 ) ;
if ( V_29 == 0 )
V_29 = V_2 -> V_27 -> V_157 ( V_127 , V_3 ) ;
else if ( V_29 == - V_70 )
V_29 = 0 ;
F_33 ( V_3 ) ;
} while ( V_29 == V_158 );
return V_29 ;
}
static void F_171 ( struct V_172 * V_173 ,
struct V_129 * V_130 ,
struct V_127 * V_127 ,
T_2 V_8 )
{
unsigned long V_131 ;
struct V_1 * V_2 = V_127 -> V_135 ;
if ( V_173 -> V_174 & V_175 )
return;
if ( ! V_130 -> V_131 )
return;
if ( V_173 -> V_174 & V_176 ) {
F_157 ( V_2 , V_130 , V_127 , V_8 ,
V_130 -> V_131 ) ;
return;
}
if ( V_130 -> V_177 < V_178 * 10 )
V_130 -> V_177 ++ ;
if ( V_130 -> V_177 > V_178 )
return;
V_131 = F_172 ( V_130 -> V_131 ) ;
V_130 -> V_35 = F_173 ( long , 0 , V_8 - V_131 / 2 ) ;
V_130 -> V_169 = V_131 ;
V_130 -> V_179 = V_131 / 4 ;
F_174 ( V_130 , V_2 , V_127 ) ;
}
static void F_175 ( struct V_172 * V_173 ,
struct V_129 * V_130 ,
struct V_127 * V_127 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_127 -> V_135 ;
if ( V_173 -> V_174 & V_175 )
return;
if ( V_130 -> V_177 > 0 )
V_130 -> V_177 -- ;
if ( F_158 ( V_3 ) )
F_159 ( V_2 , V_130 , V_127 ,
V_3 , V_8 , V_130 -> V_131 ) ;
}
int F_176 ( struct V_172 * V_173 , struct V_180 * V_181 )
{
int error ;
struct V_127 * V_127 = V_173 -> V_182 ;
struct V_1 * V_2 = V_127 -> V_135 ;
struct V_129 * V_130 = & V_127 -> V_137 ;
struct V_136 * V_136 = V_2 -> V_60 ;
T_2 V_8 = V_181 -> V_183 ;
struct V_3 * V_3 ;
T_1 V_169 ;
int V_29 = 0 ;
V_169 = F_177 ( F_52 ( V_136 ) , V_142 ) ;
if ( V_8 >= V_169 >> V_49 )
return V_184 ;
V_3 = F_156 ( V_2 , V_8 ) ;
if ( F_178 ( V_3 ) && ! ( V_181 -> V_31 & V_185 ) ) {
F_175 ( V_173 , V_130 , V_127 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_171 ( V_173 , V_130 , V_127 , V_8 ) ;
F_179 ( V_186 ) ;
F_180 ( V_173 -> V_187 , V_186 ) ;
V_29 = V_188 ;
V_189:
V_3 = F_156 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_149;
}
if ( ! F_181 ( V_3 , V_173 -> V_187 , V_181 -> V_31 ) ) {
F_33 ( V_3 ) ;
return V_29 | V_190 ;
}
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_106 ( V_3 ) ;
F_182 ( V_3 ) ;
goto V_189;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_75 ( ! F_17 ( V_3 ) ) )
goto V_191;
V_169 = F_177 ( F_52 ( V_136 ) , V_142 ) ;
if ( F_75 ( V_8 >= V_169 >> V_49 ) ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
return V_184 ;
}
V_181 -> V_3 = V_3 ;
return V_29 | V_192 ;
V_149:
error = F_170 ( V_127 , V_8 ) ;
if ( error >= 0 )
goto V_189;
if ( error == - V_159 )
return V_193 ;
return V_184 ;
V_191:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_157 ( V_127 , V_3 ) ;
if ( ! error ) {
F_127 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_34 ;
}
F_33 ( V_3 ) ;
if ( ! error || error == V_158 )
goto V_189;
F_154 ( V_127 , V_130 ) ;
return V_184 ;
}
void F_183 ( struct V_172 * V_173 , struct V_180 * V_181 )
{
struct V_123 V_124 ;
void * * V_10 ;
struct V_127 * V_127 = V_173 -> V_182 ;
struct V_1 * V_2 = V_127 -> V_135 ;
T_1 V_169 ;
struct V_3 * V_3 ;
unsigned long V_194 = ( unsigned long ) V_181 -> V_195 ;
unsigned long V_196 ;
T_8 * V_197 ;
F_132 () ;
F_147 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_124 . V_7 > V_181 -> V_198 )
break;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
goto V_199;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
break;
else
goto V_199;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
if ( ! F_17 ( V_3 ) ||
F_158 ( V_3 ) ||
F_184 ( V_3 ) )
goto V_200;
if ( ! F_142 ( V_3 ) )
goto V_200;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_201;
V_169 = F_177 ( F_52 ( V_2 -> V_60 ) , V_142 ) ;
if ( V_3 -> V_7 >= V_169 >> V_49 )
goto V_201;
V_197 = V_181 -> V_197 + V_3 -> V_7 - V_181 -> V_183 ;
if ( ! F_185 ( * V_197 ) )
goto V_201;
if ( V_127 -> V_137 . V_177 > 0 )
V_127 -> V_137 . V_177 -- ;
V_196 = V_194 + ( V_3 -> V_7 - V_181 -> V_183 ) * V_202 ;
F_186 ( V_173 , V_196 , V_3 , V_197 , false , false ) ;
F_106 ( V_3 ) ;
goto V_199;
V_201:
F_106 ( V_3 ) ;
V_200:
F_33 ( V_3 ) ;
V_199:
if ( V_124 . V_7 == V_181 -> V_198 )
break;
}
F_138 () ;
}
int F_187 ( struct V_172 * V_173 , struct V_180 * V_181 )
{
struct V_3 * V_3 = V_181 -> V_3 ;
struct V_136 * V_136 = F_188 ( V_173 -> V_182 ) ;
int V_29 = V_192 ;
F_189 ( V_136 -> V_203 ) ;
F_190 ( V_173 -> V_182 ) ;
F_140 ( V_3 ) ;
if ( V_3 -> V_2 != V_136 -> V_204 ) {
F_106 ( V_3 ) ;
V_29 = V_205 ;
goto V_54;
}
F_191 ( V_3 ) ;
F_192 ( V_3 ) ;
V_54:
F_193 ( V_136 -> V_203 ) ;
return V_29 ;
}
int F_194 ( struct V_127 * V_127 , struct V_172 * V_173 )
{
struct V_1 * V_2 = V_127 -> V_135 ;
if ( ! V_2 -> V_27 -> V_157 )
return - V_206 ;
F_167 ( V_127 ) ;
V_173 -> V_207 = & V_208 ;
return 0 ;
}
int F_195 ( struct V_127 * V_127 , struct V_172 * V_173 )
{
if ( ( V_173 -> V_174 & V_209 ) && ( V_173 -> V_174 & V_210 ) )
return - V_211 ;
return F_194 ( V_127 , V_173 ) ;
}
int F_194 ( struct V_127 * V_127 , struct V_172 * V_173 )
{
return - V_212 ;
}
int F_195 ( struct V_127 * V_127 , struct V_172 * V_173 )
{
return - V_212 ;
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
void * V_170 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_107:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_87 ( V_77 | V_213 ) ;
if ( ! V_3 )
return F_198 ( - V_159 ) ;
V_61 = F_79 ( V_3 , V_2 , V_7 , V_77 ) ;
if ( F_75 ( V_61 ) ) {
F_33 ( V_3 ) ;
if ( V_61 == - V_70 )
goto V_107;
return F_198 ( V_61 ) ;
}
V_61 = F_200 ( V_170 , V_3 ) ;
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
void * V_170 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_214:
V_3 = F_199 ( V_2 , V_7 , F_200 , V_170 , V_77 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_54;
F_140 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_214;
}
if ( F_17 ( V_3 ) ) {
F_106 ( V_3 ) ;
goto V_54;
}
V_61 = F_200 ( V_170 , V_3 ) ;
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
void * V_170 )
{
return F_201 ( V_2 , V_7 , F_200 , V_170 , F_203 ( V_2 ) ) ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_77 )
{
T_9 * F_200 = ( T_9 * ) V_2 -> V_27 -> V_157 ;
return F_201 ( V_2 , V_7 , F_200 , NULL , V_77 ) ;
}
inline int F_205 ( struct V_127 * V_127 , T_1 * V_166 , T_7 * V_143 , int V_215 )
{
struct V_136 * V_136 = V_127 -> V_135 -> V_60 ;
unsigned long V_216 = F_206 ( V_217 ) ;
if ( F_75 ( * V_166 < 0 ) )
return - V_211 ;
if ( ! V_215 ) {
if ( V_127 -> V_167 & V_218 )
* V_166 = F_52 ( V_136 ) ;
if ( V_216 != V_219 ) {
if ( * V_166 >= V_216 ) {
F_207 ( V_220 , V_74 , 0 ) ;
return - V_221 ;
}
if ( * V_143 > V_216 - ( F_208 ( V_216 ) ) * V_166 ) {
* V_143 = V_216 - ( F_208 ( V_216 ) ) * V_166 ;
}
}
}
if ( F_75 ( * V_166 + * V_143 > V_222 &&
! ( V_127 -> V_167 & V_223 ) ) ) {
if ( * V_166 >= V_222 ) {
return - V_221 ;
}
if ( * V_143 > V_222 - ( unsigned long ) * V_166 ) {
* V_143 = V_222 - ( unsigned long ) * V_166 ;
}
}
if ( F_178 ( ! V_215 ) ) {
if ( F_75 ( * V_166 >= V_136 -> V_203 -> V_224 ) ) {
if ( * V_143 || * V_166 > V_136 -> V_203 -> V_224 ) {
return - V_221 ;
}
}
if ( F_75 ( * V_166 + * V_143 > V_136 -> V_203 -> V_224 ) )
* V_143 = V_136 -> V_203 -> V_224 - * V_166 ;
} else {
#ifdef F_209
T_1 V_146 ;
if ( F_210 ( F_211 ( V_136 ) ) )
return - V_225 ;
V_146 = F_52 ( V_136 ) ;
if ( * V_166 >= V_146 ) {
if ( * V_143 || * V_166 > V_146 )
return - V_32 ;
}
if ( * V_166 + * V_143 > V_146 )
* V_143 = V_146 - * V_166 ;
#else
return - V_225 ;
#endif
}
return 0 ;
}
int F_212 ( struct V_127 * V_127 , struct V_1 * V_2 ,
T_1 V_166 , unsigned V_226 , unsigned V_31 ,
struct V_3 * * V_106 , void * * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_27 ;
return V_229 -> V_230 ( V_127 , V_2 , V_166 , V_226 , V_31 ,
V_106 , V_227 ) ;
}
int F_213 ( struct V_127 * V_127 , struct V_1 * V_2 ,
T_1 V_166 , unsigned V_226 , unsigned V_231 ,
struct V_3 * V_3 , void * V_227 )
{
const struct V_228 * V_229 = V_2 -> V_27 ;
return V_229 -> V_232 ( V_127 , V_2 , V_166 , V_226 , V_231 , V_3 , V_227 ) ;
}
T_6
F_214 ( struct V_161 * V_162 , struct V_133 * V_233 , T_1 V_166 )
{
struct V_127 * V_127 = V_162 -> V_163 ;
struct V_1 * V_2 = V_127 -> V_135 ;
struct V_136 * V_136 = V_2 -> V_60 ;
T_6 V_134 ;
T_7 V_234 ;
T_2 V_36 ;
struct V_133 V_170 ;
V_234 = F_163 ( V_233 ) ;
V_36 = ( V_166 + V_234 - 1 ) >> V_49 ;
V_134 = F_54 ( V_2 , V_166 , V_166 + V_234 - 1 ) ;
if ( V_134 )
goto V_54;
if ( V_2 -> V_13 ) {
V_134 = F_215 ( V_2 ,
V_166 >> V_49 , V_36 ) ;
if ( V_134 ) {
if ( V_134 == - V_235 )
return 0 ;
goto V_54;
}
}
V_170 = * V_233 ;
V_134 = V_2 -> V_27 -> V_171 ( V_236 , V_162 , & V_170 , V_166 ) ;
if ( V_2 -> V_13 ) {
F_215 ( V_2 ,
V_166 >> V_49 , V_36 ) ;
}
if ( V_134 > 0 ) {
V_166 += V_134 ;
F_169 ( V_233 , V_134 ) ;
if ( V_166 > F_52 ( V_136 ) && ! F_216 ( V_136 -> V_237 ) ) {
F_217 ( V_136 , V_166 ) ;
F_218 ( V_136 ) ;
}
V_162 -> V_165 = V_166 ;
}
V_54:
return V_134 ;
}
struct V_3 * F_219 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_31 )
{
struct V_3 * V_3 ;
int V_108 = V_112 | V_114 | V_116 | V_115 ;
if ( V_31 & V_238 )
V_108 |= V_118 ;
V_3 = F_141 ( V_2 , V_7 , V_108 ,
F_203 ( V_2 ) ,
V_160 ) ;
if ( V_3 )
F_192 ( V_3 ) ;
return V_3 ;
}
T_6 F_220 ( struct V_127 * V_127 ,
struct V_133 * V_57 , T_1 V_166 )
{
struct V_1 * V_2 = V_127 -> V_135 ;
const struct V_228 * V_27 = V_2 -> V_27 ;
long V_239 = 0 ;
T_6 V_134 = 0 ;
unsigned int V_31 = 0 ;
if ( F_221 ( F_222 () , V_240 ) )
V_31 |= V_241 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_242 ;
T_7 V_231 ;
void * V_227 ;
V_8 = ( V_166 & ( V_142 - 1 ) ) ;
V_242 = F_223 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_243:
if ( F_75 ( F_224 ( V_57 , V_242 ) ) ) {
V_239 = - V_155 ;
break;
}
V_239 = V_27 -> V_230 ( V_127 , V_2 , V_166 , V_242 , V_31 ,
& V_3 , & V_227 ) ;
if ( F_75 ( V_239 < 0 ) )
break;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
V_231 = F_225 ( V_3 , V_57 , V_8 , V_242 ) ;
F_161 ( V_3 ) ;
V_239 = V_27 -> V_232 ( V_127 , V_2 , V_166 , V_242 , V_231 ,
V_3 , V_227 ) ;
if ( F_75 ( V_239 < 0 ) )
break;
V_231 = V_239 ;
F_50 () ;
F_169 ( V_57 , V_231 ) ;
if ( F_75 ( V_231 == 0 ) ) {
V_242 = F_223 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_243;
}
V_166 += V_231 ;
V_134 += V_231 ;
F_226 ( V_2 ) ;
if ( F_227 ( V_74 ) ) {
V_239 = - V_244 ;
break;
}
} while ( F_163 ( V_57 ) );
return V_134 ? V_134 : V_239 ;
}
T_6 F_228 ( struct V_161 * V_162 , struct V_133 * V_233 )
{
struct V_127 * V_127 = V_162 -> V_163 ;
struct V_1 * V_2 = V_127 -> V_135 ;
struct V_136 * V_136 = V_2 -> V_60 ;
T_1 V_166 = V_162 -> V_165 ;
T_6 V_134 = 0 ;
T_6 V_61 ;
T_6 V_239 ;
T_7 V_143 = F_163 ( V_233 ) ;
V_74 -> V_25 = V_2 -> V_25 ;
V_61 = F_205 ( V_127 , & V_166 , & V_143 , F_216 ( V_136 -> V_237 ) ) ;
if ( V_61 )
goto V_54;
if ( V_143 == 0 )
goto V_54;
F_229 ( V_233 , V_143 ) ;
V_61 = F_230 ( V_127 ) ;
if ( V_61 )
goto V_54;
V_61 = F_190 ( V_127 ) ;
if ( V_61 )
goto V_54;
if ( F_75 ( V_127 -> V_167 & V_168 ) ) {
T_1 V_245 ;
V_134 = F_214 ( V_162 , V_233 , V_166 ) ;
if ( V_134 < 0 || V_134 == V_143 )
goto V_54;
V_166 += V_134 ;
V_143 -= V_134 ;
V_239 = F_220 ( V_127 , V_233 , V_166 ) ;
if ( F_75 ( V_239 < 0 ) ) {
V_61 = V_239 ;
goto V_54;
}
V_162 -> V_165 = V_166 + V_239 ;
V_245 = V_166 + V_239 - 1 ;
V_61 = F_54 ( V_127 -> V_135 , V_166 , V_245 ) ;
if ( V_61 == 0 ) {
V_134 += V_239 ;
F_231 ( V_2 ,
V_166 >> V_49 ,
V_245 >> V_49 ) ;
} else {
}
} else {
V_134 = F_220 ( V_127 , V_233 , V_166 ) ;
if ( F_178 ( V_134 >= 0 ) )
V_162 -> V_165 = V_166 + V_134 ;
}
V_54:
V_74 -> V_25 = NULL ;
return V_134 ? V_134 : V_61 ;
}
T_6 F_232 ( struct V_161 * V_162 , struct V_133 * V_233 )
{
struct V_127 * V_127 = V_162 -> V_163 ;
struct V_136 * V_136 = V_127 -> V_135 -> V_60 ;
T_6 V_29 ;
F_233 ( & V_136 -> V_246 ) ;
V_29 = F_228 ( V_162 , V_233 ) ;
F_234 ( & V_136 -> V_246 ) ;
if ( V_29 > 0 ) {
T_6 V_61 ;
V_61 = F_235 ( V_127 , V_162 -> V_165 - V_29 , V_29 ) ;
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
if ( V_2 && V_2 -> V_27 -> V_247 )
return V_2 -> V_27 -> V_247 ( V_3 , V_14 ) ;
return F_238 ( V_3 ) ;
}
