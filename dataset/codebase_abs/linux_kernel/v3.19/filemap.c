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
int V_108 , T_3 V_14 )
{
struct V_3 * V_3 ;
V_107:
V_3 = F_131 ( V_2 , V_8 ) ;
if ( F_66 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 )
goto V_109;
if ( V_108 & V_110 ) {
if ( V_108 & V_111 ) {
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
if ( V_3 && ( V_108 & V_112 ) )
F_143 ( V_3 ) ;
V_109:
if ( ! V_3 && ( V_108 & V_113 ) ) {
int V_61 ;
if ( ( V_108 & V_114 ) && F_26 ( V_2 ) )
V_14 |= V_115 ;
if ( V_108 & V_116 )
V_14 &= ~ V_117 ;
V_3 = F_87 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
if ( F_144 ( ! ( V_108 & V_110 ) ) )
V_108 |= V_110 ;
if ( V_108 & V_112 )
F_145 ( V_3 ) ;
V_61 = F_79 ( V_3 , V_2 , V_8 ,
V_14 & V_118 ) ;
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
T_2 V_35 , unsigned int V_119 ,
struct V_3 * * V_120 , T_2 * V_121 )
{
void * * V_10 ;
unsigned int V_29 = 0 ;
struct V_122 V_123 ;
if ( ! V_119 )
return 0 ;
F_132 () ;
V_124:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
goto V_124;
goto V_125;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
V_125:
V_121 [ V_29 ] = V_123 . V_7 ;
V_120 [ V_29 ] = V_3 ;
if ( ++ V_29 == V_119 )
break;
}
F_138 () ;
return V_29 ;
}
unsigned F_148 ( struct V_1 * V_2 , T_2 V_35 ,
unsigned int V_52 , struct V_3 * * V_58 )
{
struct V_122 V_123 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_124:
F_147 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
F_149 ( V_123 . V_7 ) ;
goto V_124;
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
struct V_122 V_123 ;
void * * V_10 ;
unsigned int V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_124:
F_151 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
break;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_124;
}
break;
}
if ( ! F_137 ( V_3 ) )
goto V_107;
if ( F_75 ( V_3 != * V_10 ) ) {
F_33 ( V_3 ) ;
goto V_107;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_123 . V_7 ) {
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
struct V_122 V_123 ;
void * * V_10 ;
unsigned V_29 = 0 ;
if ( F_75 ( ! V_52 ) )
return 0 ;
F_132 () ;
V_124:
F_153 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
continue;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) ) {
goto V_124;
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
static void F_154 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
V_129 -> V_130 /= 4 ;
}
static T_6 F_155 ( struct V_126 * V_127 , T_1 * V_131 ,
struct V_132 * V_123 , T_6 V_133 )
{
struct V_1 * V_2 = V_127 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_60 ;
struct V_128 * V_129 = & V_127 -> V_136 ;
T_2 V_7 ;
T_2 V_137 ;
T_2 V_138 ;
unsigned long V_8 ;
unsigned int V_139 ;
int error = 0 ;
V_7 = * V_131 >> V_49 ;
V_138 = V_129 -> V_140 >> V_49 ;
V_139 = V_129 -> V_140 & ( V_141 - 1 ) ;
V_137 = ( * V_131 + V_123 -> V_142 + V_141 - 1 ) >> V_49 ;
V_8 = * V_131 & ~ V_143 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_144 ;
T_1 V_145 ;
unsigned long V_146 , V_29 ;
F_50 () ;
V_147:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_157 ( V_2 ,
V_129 , V_127 ,
V_7 , V_137 - V_7 ) ;
V_3 = F_156 ( V_2 , V_7 ) ;
if ( F_75 ( V_3 == NULL ) )
goto V_148;
}
if ( F_158 ( V_3 ) ) {
F_159 ( V_2 ,
V_129 , V_127 , V_3 ,
V_7 , V_137 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_135 -> V_149 == V_49 ||
! V_2 -> V_27 -> V_150 )
goto V_151;
if ( ! F_142 ( V_3 ) )
goto V_151;
if ( ! V_3 -> V_2 )
goto V_152;
if ( ! V_2 -> V_27 -> V_150 ( V_3 ,
V_8 , V_123 -> V_142 ) )
goto V_152;
F_106 ( V_3 ) ;
}
V_153:
V_145 = F_52 ( V_135 ) ;
V_144 = ( V_145 - 1 ) >> V_49 ;
if ( F_75 ( ! V_145 || V_7 > V_144 ) ) {
F_33 ( V_3 ) ;
goto V_54;
}
V_146 = V_141 ;
if ( V_7 == V_144 ) {
V_146 = ( ( V_145 - 1 ) & ~ V_143 ) + 1 ;
if ( V_146 <= V_8 ) {
F_33 ( V_3 ) ;
goto V_54;
}
}
V_146 = V_146 - V_8 ;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
if ( V_138 != V_7 || V_8 != V_139 )
F_143 ( V_3 ) ;
V_138 = V_7 ;
V_29 = F_162 ( V_3 , V_8 , V_146 , V_123 ) ;
V_8 += V_29 ;
V_7 += V_8 >> V_49 ;
V_8 &= ~ V_143 ;
V_139 = V_8 ;
F_33 ( V_3 ) ;
V_133 += V_29 ;
if ( ! F_163 ( V_123 ) )
goto V_54;
if ( V_29 < V_146 ) {
error = - V_154 ;
goto V_54;
}
continue;
V_151:
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_155;
V_152:
if ( ! V_3 -> V_2 ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_106 ( V_3 ) ;
goto V_153;
}
V_156:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_156 ( V_127 , V_3 ) ;
if ( F_75 ( error ) ) {
if ( error == V_157 ) {
F_33 ( V_3 ) ;
error = 0 ;
goto V_147;
}
goto V_155;
}
if ( ! F_17 ( V_3 ) ) {
error = F_164 ( V_3 ) ;
if ( F_75 ( error ) )
goto V_155;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_147;
}
F_106 ( V_3 ) ;
F_154 ( V_127 , V_129 ) ;
error = - V_34 ;
goto V_155;
}
F_106 ( V_3 ) ;
}
goto V_153;
V_155:
F_33 ( V_3 ) ;
goto V_54;
V_148:
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_158 ;
goto V_54;
}
error = F_79 ( V_3 , V_2 ,
V_7 , V_159 ) ;
if ( error ) {
F_33 ( V_3 ) ;
if ( error == - V_70 ) {
error = 0 ;
goto V_147;
}
goto V_54;
}
goto V_156;
}
V_54:
V_129 -> V_140 = V_138 ;
V_129 -> V_140 <<= V_49 ;
V_129 -> V_140 |= V_139 ;
* V_131 = ( ( T_1 ) V_7 << V_49 ) + V_8 ;
F_167 ( V_127 ) ;
return V_133 ? V_133 : error ;
}
T_6
F_168 ( struct V_160 * V_161 , struct V_132 * V_123 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
T_6 V_163 = 0 ;
T_1 * V_131 = & V_161 -> V_164 ;
T_1 V_165 = * V_131 ;
if ( V_126 -> V_166 & V_167 ) {
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_60 ;
T_7 V_142 = F_163 ( V_123 ) ;
T_1 V_168 ;
if ( ! V_142 )
goto V_54;
V_168 = F_52 ( V_135 ) ;
V_163 = F_54 ( V_2 , V_165 ,
V_165 + V_142 - 1 ) ;
if ( ! V_163 ) {
struct V_132 V_169 = * V_123 ;
V_163 = V_2 -> V_27 -> V_170 ( V_98 , V_161 , & V_169 , V_165 ) ;
}
if ( V_163 > 0 ) {
* V_131 = V_165 + V_163 ;
F_169 ( V_123 , V_163 ) ;
}
if ( V_163 < 0 || ! F_163 ( V_123 ) || * V_131 >= V_168 ) {
F_167 ( V_126 ) ;
goto V_54;
}
}
V_163 = F_155 ( V_126 , V_131 , V_123 , V_163 ) ;
V_54:
return V_163 ;
}
static int F_170 ( struct V_126 * V_126 , T_2 V_8 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_3 * V_3 ;
int V_29 ;
do {
V_3 = F_166 ( V_2 ) ;
if ( ! V_3 )
return - V_158 ;
V_29 = F_79 ( V_3 , V_2 , V_8 , V_159 ) ;
if ( V_29 == 0 )
V_29 = V_2 -> V_27 -> V_156 ( V_126 , V_3 ) ;
else if ( V_29 == - V_70 )
V_29 = 0 ;
F_33 ( V_3 ) ;
} while ( V_29 == V_157 );
return V_29 ;
}
static void F_171 ( struct V_171 * V_172 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
T_2 V_8 )
{
unsigned long V_130 ;
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_172 -> V_173 & V_174 )
return;
if ( ! V_129 -> V_130 )
return;
if ( V_172 -> V_173 & V_175 ) {
F_157 ( V_2 , V_129 , V_126 , V_8 ,
V_129 -> V_130 ) ;
return;
}
if ( V_129 -> V_176 < V_177 * 10 )
V_129 -> V_176 ++ ;
if ( V_129 -> V_176 > V_177 )
return;
V_130 = F_172 ( V_129 -> V_130 ) ;
V_129 -> V_35 = F_173 ( long , 0 , V_8 - V_130 / 2 ) ;
V_129 -> V_168 = V_130 ;
V_129 -> V_178 = V_130 / 4 ;
F_174 ( V_129 , V_2 , V_126 ) ;
}
static void F_175 ( struct V_171 * V_172 ,
struct V_128 * V_129 ,
struct V_126 * V_126 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( V_172 -> V_173 & V_174 )
return;
if ( V_129 -> V_176 > 0 )
V_129 -> V_176 -- ;
if ( F_158 ( V_3 ) )
F_159 ( V_2 , V_129 , V_126 ,
V_3 , V_8 , V_129 -> V_130 ) ;
}
int F_176 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
int error ;
struct V_126 * V_126 = V_172 -> V_181 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_128 * V_129 = & V_126 -> V_136 ;
struct V_135 * V_135 = V_2 -> V_60 ;
T_2 V_8 = V_180 -> V_182 ;
struct V_3 * V_3 ;
T_1 V_168 ;
int V_29 = 0 ;
V_168 = F_177 ( F_52 ( V_135 ) , V_141 ) ;
if ( V_8 >= V_168 >> V_49 )
return V_183 ;
V_3 = F_156 ( V_2 , V_8 ) ;
if ( F_178 ( V_3 ) && ! ( V_180 -> V_31 & V_184 ) ) {
F_175 ( V_172 , V_129 , V_126 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_171 ( V_172 , V_129 , V_126 , V_8 ) ;
F_179 ( V_185 ) ;
F_180 ( V_172 -> V_186 , V_185 ) ;
V_29 = V_187 ;
V_188:
V_3 = F_156 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_148;
}
if ( ! F_181 ( V_3 , V_172 -> V_186 , V_180 -> V_31 ) ) {
F_33 ( V_3 ) ;
return V_29 | V_189 ;
}
if ( F_75 ( V_3 -> V_2 != V_2 ) ) {
F_106 ( V_3 ) ;
F_182 ( V_3 ) ;
goto V_188;
}
F_56 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_75 ( ! F_17 ( V_3 ) ) )
goto V_190;
V_168 = F_177 ( F_52 ( V_135 ) , V_141 ) ;
if ( F_75 ( V_8 >= V_168 >> V_49 ) ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
return V_183 ;
}
V_180 -> V_3 = V_3 ;
return V_29 | V_191 ;
V_148:
error = F_170 ( V_126 , V_8 ) ;
if ( error >= 0 )
goto V_188;
if ( error == - V_158 )
return V_192 ;
return V_183 ;
V_190:
F_165 ( V_3 ) ;
error = V_2 -> V_27 -> V_156 ( V_126 , V_3 ) ;
if ( ! error ) {
F_127 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_34 ;
}
F_33 ( V_3 ) ;
if ( ! error || error == V_157 )
goto V_188;
F_154 ( V_126 , V_129 ) ;
return V_183 ;
}
void F_183 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
struct V_122 V_123 ;
void * * V_10 ;
struct V_126 * V_126 = V_172 -> V_181 ;
struct V_1 * V_2 = V_126 -> V_134 ;
T_1 V_168 ;
struct V_3 * V_3 ;
unsigned long V_193 = ( unsigned long ) V_180 -> V_194 ;
unsigned long V_195 ;
T_8 * V_196 ;
F_132 () ;
F_147 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_123 . V_7 > V_180 -> V_197 )
break;
V_107:
V_3 = F_134 ( V_10 ) ;
if ( F_75 ( ! V_3 ) )
goto V_198;
if ( F_135 ( V_3 ) ) {
if ( F_136 ( V_3 ) )
break;
else
goto V_198;
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
goto V_199;
if ( ! F_142 ( V_3 ) )
goto V_199;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_200;
V_168 = F_177 ( F_52 ( V_2 -> V_60 ) , V_141 ) ;
if ( V_3 -> V_7 >= V_168 >> V_49 )
goto V_200;
V_196 = V_180 -> V_196 + V_3 -> V_7 - V_180 -> V_182 ;
if ( ! F_185 ( * V_196 ) )
goto V_200;
if ( V_126 -> V_136 . V_176 > 0 )
V_126 -> V_136 . V_176 -- ;
V_195 = V_193 + ( V_3 -> V_7 - V_180 -> V_182 ) * V_201 ;
F_186 ( V_172 , V_195 , V_3 , V_196 , false , false ) ;
F_106 ( V_3 ) ;
goto V_198;
V_200:
F_106 ( V_3 ) ;
V_199:
F_33 ( V_3 ) ;
V_198:
if ( V_123 . V_7 == V_180 -> V_197 )
break;
}
F_138 () ;
}
int F_187 ( struct V_171 * V_172 , struct V_179 * V_180 )
{
struct V_3 * V_3 = V_180 -> V_3 ;
struct V_135 * V_135 = F_188 ( V_172 -> V_181 ) ;
int V_29 = V_191 ;
F_189 ( V_135 -> V_202 ) ;
F_190 ( V_172 -> V_181 ) ;
F_140 ( V_3 ) ;
if ( V_3 -> V_2 != V_135 -> V_203 ) {
F_106 ( V_3 ) ;
V_29 = V_204 ;
goto V_54;
}
F_191 ( V_3 ) ;
F_192 ( V_3 ) ;
V_54:
F_193 ( V_135 -> V_202 ) ;
return V_29 ;
}
int F_194 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
if ( ! V_2 -> V_27 -> V_156 )
return - V_205 ;
F_167 ( V_126 ) ;
V_172 -> V_206 = & V_207 ;
return 0 ;
}
int F_195 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
if ( ( V_172 -> V_173 & V_208 ) && ( V_172 -> V_173 & V_209 ) )
return - V_210 ;
return F_194 ( V_126 , V_172 ) ;
}
int F_194 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
return - V_211 ;
}
int F_195 ( struct V_126 * V_126 , struct V_171 * V_172 )
{
return - V_211 ;
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
void * V_169 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_107:
V_3 = F_156 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_87 ( V_77 | V_212 ) ;
if ( ! V_3 )
return F_198 ( - V_158 ) ;
V_61 = F_79 ( V_3 , V_2 , V_7 , V_77 ) ;
if ( F_75 ( V_61 ) ) {
F_33 ( V_3 ) ;
if ( V_61 == - V_70 )
goto V_107;
return F_198 ( V_61 ) ;
}
V_61 = F_200 ( V_169 , V_3 ) ;
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
void * V_169 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_61 ;
V_213:
V_3 = F_199 ( V_2 , V_7 , F_200 , V_169 , V_77 ) ;
if ( F_197 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_54;
F_140 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_106 ( V_3 ) ;
F_33 ( V_3 ) ;
goto V_213;
}
if ( F_17 ( V_3 ) ) {
F_106 ( V_3 ) ;
goto V_54;
}
V_61 = F_200 ( V_169 , V_3 ) ;
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
void * V_169 )
{
return F_201 ( V_2 , V_7 , F_200 , V_169 , F_203 ( V_2 ) ) ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_77 )
{
T_9 * F_200 = ( T_9 * ) V_2 -> V_27 -> V_156 ;
return F_201 ( V_2 , V_7 , F_200 , NULL , V_77 ) ;
}
inline int F_205 ( struct V_126 * V_126 , T_1 * V_165 , T_7 * V_142 , int V_214 )
{
struct V_135 * V_135 = V_126 -> V_134 -> V_60 ;
unsigned long V_215 = F_206 ( V_216 ) ;
if ( F_75 ( * V_165 < 0 ) )
return - V_210 ;
if ( ! V_214 ) {
if ( V_126 -> V_166 & V_217 )
* V_165 = F_52 ( V_135 ) ;
if ( V_215 != V_218 ) {
if ( * V_165 >= V_215 ) {
F_207 ( V_219 , V_74 , 0 ) ;
return - V_220 ;
}
if ( * V_142 > V_215 - ( F_208 ( V_215 ) ) * V_165 ) {
* V_142 = V_215 - ( F_208 ( V_215 ) ) * V_165 ;
}
}
}
if ( F_75 ( * V_165 + * V_142 > V_221 &&
! ( V_126 -> V_166 & V_222 ) ) ) {
if ( * V_165 >= V_221 ) {
return - V_220 ;
}
if ( * V_142 > V_221 - ( unsigned long ) * V_165 ) {
* V_142 = V_221 - ( unsigned long ) * V_165 ;
}
}
if ( F_178 ( ! V_214 ) ) {
if ( F_75 ( * V_165 >= V_135 -> V_202 -> V_223 ) ) {
if ( * V_142 || * V_165 > V_135 -> V_202 -> V_223 ) {
return - V_220 ;
}
}
if ( F_75 ( * V_165 + * V_142 > V_135 -> V_202 -> V_223 ) )
* V_142 = V_135 -> V_202 -> V_223 - * V_165 ;
} else {
#ifdef F_209
T_1 V_145 ;
if ( F_210 ( F_211 ( V_135 ) ) )
return - V_224 ;
V_145 = F_52 ( V_135 ) ;
if ( * V_165 >= V_145 ) {
if ( * V_142 || * V_165 > V_145 )
return - V_32 ;
}
if ( * V_165 + * V_142 > V_145 )
* V_142 = V_145 - * V_165 ;
#else
return - V_224 ;
#endif
}
return 0 ;
}
int F_212 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_165 , unsigned V_225 , unsigned V_31 ,
struct V_3 * * V_106 , void * * V_226 )
{
const struct V_227 * V_228 = V_2 -> V_27 ;
return V_228 -> V_229 ( V_126 , V_2 , V_165 , V_225 , V_31 ,
V_106 , V_226 ) ;
}
int F_213 ( struct V_126 * V_126 , struct V_1 * V_2 ,
T_1 V_165 , unsigned V_225 , unsigned V_230 ,
struct V_3 * V_3 , void * V_226 )
{
const struct V_227 * V_228 = V_2 -> V_27 ;
return V_228 -> V_231 ( V_126 , V_2 , V_165 , V_225 , V_230 , V_3 , V_226 ) ;
}
T_6
F_214 ( struct V_160 * V_161 , struct V_132 * V_232 , T_1 V_165 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_60 ;
T_6 V_133 ;
T_7 V_233 ;
T_2 V_36 ;
struct V_132 V_169 ;
V_233 = F_163 ( V_232 ) ;
V_36 = ( V_165 + V_233 - 1 ) >> V_49 ;
V_133 = F_54 ( V_2 , V_165 , V_165 + V_233 - 1 ) ;
if ( V_133 )
goto V_54;
if ( V_2 -> V_13 ) {
V_133 = F_215 ( V_2 ,
V_165 >> V_49 , V_36 ) ;
if ( V_133 ) {
if ( V_133 == - V_234 )
return 0 ;
goto V_54;
}
}
V_169 = * V_232 ;
V_133 = V_2 -> V_27 -> V_170 ( V_235 , V_161 , & V_169 , V_165 ) ;
if ( V_2 -> V_13 ) {
F_215 ( V_2 ,
V_165 >> V_49 , V_36 ) ;
}
if ( V_133 > 0 ) {
V_165 += V_133 ;
F_169 ( V_232 , V_133 ) ;
if ( V_165 > F_52 ( V_135 ) && ! F_216 ( V_135 -> V_236 ) ) {
F_217 ( V_135 , V_165 ) ;
F_218 ( V_135 ) ;
}
V_161 -> V_164 = V_165 ;
}
V_54:
return V_133 ;
}
struct V_3 * F_219 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_31 )
{
struct V_3 * V_3 ;
int V_108 = V_110 | V_112 | V_114 | V_113 ;
if ( V_31 & V_237 )
V_108 |= V_116 ;
V_3 = F_141 ( V_2 , V_7 , V_108 ,
F_203 ( V_2 ) ) ;
if ( V_3 )
F_192 ( V_3 ) ;
return V_3 ;
}
T_6 F_220 ( struct V_126 * V_126 ,
struct V_132 * V_57 , T_1 V_165 )
{
struct V_1 * V_2 = V_126 -> V_134 ;
const struct V_227 * V_27 = V_2 -> V_27 ;
long V_238 = 0 ;
T_6 V_133 = 0 ;
unsigned int V_31 = 0 ;
if ( ! F_221 ( V_57 ) )
V_31 |= V_239 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_240 ;
T_7 V_230 ;
void * V_226 ;
V_8 = ( V_165 & ( V_141 - 1 ) ) ;
V_240 = F_222 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_241:
if ( F_75 ( F_223 ( V_57 , V_240 ) ) ) {
V_238 = - V_154 ;
break;
}
V_238 = V_27 -> V_229 ( V_126 , V_2 , V_165 , V_240 , V_31 ,
& V_3 , & V_226 ) ;
if ( F_75 ( V_238 < 0 ) )
break;
if ( F_160 ( V_2 ) )
F_161 ( V_3 ) ;
V_230 = F_224 ( V_3 , V_57 , V_8 , V_240 ) ;
F_161 ( V_3 ) ;
V_238 = V_27 -> V_231 ( V_126 , V_2 , V_165 , V_240 , V_230 ,
V_3 , V_226 ) ;
if ( F_75 ( V_238 < 0 ) )
break;
V_230 = V_238 ;
F_50 () ;
F_169 ( V_57 , V_230 ) ;
if ( F_75 ( V_230 == 0 ) ) {
V_240 = F_222 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_241;
}
V_165 += V_230 ;
V_133 += V_230 ;
F_225 ( V_2 ) ;
if ( F_226 ( V_74 ) ) {
V_238 = - V_242 ;
break;
}
} while ( F_163 ( V_57 ) );
return V_133 ? V_133 : V_238 ;
}
T_6 F_227 ( struct V_160 * V_161 , struct V_132 * V_232 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_1 * V_2 = V_126 -> V_134 ;
struct V_135 * V_135 = V_2 -> V_60 ;
T_1 V_165 = V_161 -> V_164 ;
T_6 V_133 = 0 ;
T_6 V_61 ;
T_6 V_238 ;
T_7 V_142 = F_163 ( V_232 ) ;
V_74 -> V_25 = V_2 -> V_25 ;
V_61 = F_205 ( V_126 , & V_165 , & V_142 , F_216 ( V_135 -> V_236 ) ) ;
if ( V_61 )
goto V_54;
if ( V_142 == 0 )
goto V_54;
F_228 ( V_232 , V_142 ) ;
V_61 = F_229 ( V_126 ) ;
if ( V_61 )
goto V_54;
V_61 = F_190 ( V_126 ) ;
if ( V_61 )
goto V_54;
if ( F_75 ( V_126 -> V_166 & V_167 ) ) {
T_1 V_243 ;
V_133 = F_214 ( V_161 , V_232 , V_165 ) ;
if ( V_133 < 0 || V_133 == V_142 )
goto V_54;
V_165 += V_133 ;
V_142 -= V_133 ;
V_238 = F_220 ( V_126 , V_232 , V_165 ) ;
if ( F_75 ( V_238 < 0 ) ) {
V_61 = V_238 ;
goto V_54;
}
V_161 -> V_164 = V_165 + V_238 ;
V_243 = V_165 + V_238 - 1 ;
V_61 = F_54 ( V_126 -> V_134 , V_165 , V_243 ) ;
if ( V_61 == 0 ) {
V_133 += V_238 ;
F_230 ( V_2 ,
V_165 >> V_49 ,
V_243 >> V_49 ) ;
} else {
}
} else {
V_133 = F_220 ( V_126 , V_232 , V_165 ) ;
if ( F_178 ( V_133 >= 0 ) )
V_161 -> V_164 = V_165 + V_133 ;
}
V_54:
V_74 -> V_25 = NULL ;
return V_133 ? V_133 : V_61 ;
}
T_6 F_231 ( struct V_160 * V_161 , struct V_132 * V_232 )
{
struct V_126 * V_126 = V_161 -> V_162 ;
struct V_135 * V_135 = V_126 -> V_134 -> V_60 ;
T_6 V_29 ;
F_232 ( & V_135 -> V_244 ) ;
V_29 = F_227 ( V_161 , V_232 ) ;
F_233 ( & V_135 -> V_244 ) ;
if ( V_29 > 0 ) {
T_6 V_61 ;
V_61 = F_234 ( V_126 , V_161 -> V_164 - V_29 , V_29 ) ;
if ( V_61 < 0 )
V_29 = V_61 ;
}
return V_29 ;
}
int F_235 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_236 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_27 -> V_245 )
return V_2 -> V_27 -> V_245 ( V_3 , V_14 ) ;
return F_237 ( V_3 ) ;
}
