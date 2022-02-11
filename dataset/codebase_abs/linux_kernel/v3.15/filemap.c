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
if ( F_113 ( V_3 ) )
F_114 ( V_3 ) ;
if ( ! F_115 ( V_3 ) )
F_116 () ;
F_111 () ;
F_99 ( V_3 , V_92 ) ;
}
void F_117 ( struct V_3 * V_3 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_91 ) ;
F_118 ( F_96 ( V_3 ) , & V_85 , F_35 ,
V_86 ) ;
}
int F_119 ( struct V_3 * V_3 )
{
F_102 ( V_85 , & V_3 -> V_34 , V_91 ) ;
return F_118 ( F_96 ( V_3 ) , & V_85 ,
F_37 , V_87 ) ;
}
int F_120 ( struct V_3 * V_3 , struct V_93 * V_74 ,
unsigned int V_34 )
{
if ( V_34 & V_94 ) {
if ( V_34 & V_95 )
return 0 ;
F_121 ( & V_74 -> V_96 ) ;
if ( V_34 & V_97 )
F_122 ( V_3 ) ;
else
F_123 ( V_3 ) ;
return 0 ;
} else {
if ( V_34 & V_97 ) {
int V_32 ;
V_32 = F_119 ( V_3 ) ;
if ( V_32 ) {
F_121 ( & V_74 -> V_96 ) ;
return 0 ;
}
} else
F_117 ( V_3 ) ;
return 1 ;
}
}
T_2 F_124 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_98 )
{
unsigned long V_60 ;
for ( V_60 = 0 ; V_60 < V_98 ; V_60 ++ ) {
struct V_3 * V_3 ;
V_3 = F_125 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_71 ( V_3 ) )
break;
V_7 ++ ;
if ( V_7 == 0 )
break;
}
return V_7 ;
}
T_2 F_126 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned long V_98 )
{
unsigned long V_60 ;
for ( V_60 = 0 ; V_60 < V_98 ; V_60 ++ ) {
struct V_3 * V_3 ;
V_3 = F_125 ( & V_2 -> V_11 , V_7 ) ;
if ( ! V_3 || F_71 ( V_3 ) )
break;
V_7 -- ;
if ( V_7 == V_99 )
break;
}
return V_7 ;
}
struct V_3 * F_127 ( struct V_1 * V_2 , T_2 V_8 )
{
void * * V_100 ;
struct V_3 * V_3 ;
F_128 () ;
V_101:
V_3 = NULL ;
V_100 = F_129 ( & V_2 -> V_11 , V_8 ) ;
if ( V_100 ) {
V_3 = F_130 ( V_100 ) ;
if ( F_78 ( ! V_3 ) )
goto V_57;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) )
goto V_101;
goto V_57;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_100 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
}
V_57:
F_134 () ;
return V_3 ;
}
struct V_3 * F_135 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 = F_127 ( V_2 , V_8 ) ;
if ( F_71 ( V_3 ) )
V_3 = NULL ;
return V_3 ;
}
struct V_3 * F_136 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 ;
V_101:
V_3 = F_127 ( V_2 , V_8 ) ;
if ( V_3 && ! F_131 ( V_3 ) ) {
F_137 ( V_3 ) ;
if ( F_78 ( V_3 -> V_2 != V_2 ) ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_101;
}
F_61 ( V_3 -> V_7 != V_8 , V_3 ) ;
}
return V_3 ;
}
struct V_3 * F_138 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_3 * V_3 = F_136 ( V_2 , V_8 ) ;
if ( F_71 ( V_3 ) )
V_3 = NULL ;
return V_3 ;
}
struct V_3 * F_139 ( struct V_1 * V_2 ,
T_2 V_7 , T_3 V_14 )
{
struct V_3 * V_3 ;
int V_64 ;
V_101:
V_3 = F_138 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_89 ( V_14 ) ;
if ( ! V_3 )
return NULL ;
V_64 = F_81 ( V_3 , V_2 , V_7 ,
( V_14 & V_75 ) ) ;
if ( F_78 ( V_64 ) ) {
F_34 ( V_3 ) ;
V_3 = NULL ;
if ( V_64 == - V_73 )
goto V_101;
}
}
return V_3 ;
}
unsigned F_140 ( struct V_1 * V_2 ,
T_2 V_38 , unsigned int V_102 ,
struct V_3 * * V_103 , T_2 * V_104 )
{
void * * V_10 ;
unsigned int V_32 = 0 ;
struct V_105 V_106 ;
if ( ! V_102 )
return 0 ;
F_128 () ;
V_107:
F_141 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_101:
V_3 = F_130 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) )
goto V_107;
goto V_108;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
V_108:
V_104 [ V_32 ] = V_106 . V_7 ;
V_103 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_102 )
break;
}
F_134 () ;
return V_32 ;
}
unsigned F_142 ( struct V_1 * V_2 , T_2 V_38 ,
unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_105 V_106 ;
void * * V_10 ;
unsigned V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_128 () ;
V_107:
F_141 (slot, &mapping->page_tree, &iter, start) {
struct V_3 * V_3 ;
V_101:
V_3 = F_130 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) ) {
F_143 ( V_106 . V_7 ) ;
goto V_107;
}
continue;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_134 () ;
return V_32 ;
}
unsigned F_144 ( struct V_1 * V_2 , T_2 V_7 ,
unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_105 V_106 ;
void * * V_10 ;
unsigned int V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_128 () ;
V_107:
F_145 (slot, &mapping->page_tree, &iter, index) {
struct V_3 * V_3 ;
V_101:
V_3 = F_130 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
break;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) ) {
goto V_107;
}
break;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
if ( V_3 -> V_2 == NULL || V_3 -> V_7 != V_106 . V_7 ) {
F_34 ( V_3 ) ;
break;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_134 () ;
return V_32 ;
}
unsigned F_146 ( struct V_1 * V_2 , T_2 * V_7 ,
int V_9 , unsigned int V_55 , struct V_3 * * V_61 )
{
struct V_105 V_106 ;
void * * V_10 ;
unsigned V_32 = 0 ;
if ( F_78 ( ! V_55 ) )
return 0 ;
F_128 () ;
V_107:
F_147 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_3 * V_3 ;
V_101:
V_3 = F_130 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
continue;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) ) {
goto V_107;
}
continue;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
V_61 [ V_32 ] = V_3 ;
if ( ++ V_32 == V_55 )
break;
}
F_134 () ;
if ( V_32 )
* V_7 = V_61 [ V_32 - 1 ] -> V_7 + 1 ;
return V_32 ;
}
struct V_3 *
F_148 ( struct V_1 * V_2 , T_2 V_7 )
{
struct V_3 * V_3 = F_135 ( V_2 , V_7 ) ;
if ( V_3 ) {
if ( F_149 ( V_3 ) )
return V_3 ;
F_34 ( V_3 ) ;
return NULL ;
}
V_3 = F_89 ( F_150 ( V_2 ) & ~ V_109 ) ;
if ( V_3 && F_81 ( V_3 , V_2 , V_7 , V_110 ) ) {
F_34 ( V_3 ) ;
V_3 = NULL ;
}
return V_3 ;
}
static void F_151 ( struct V_111 * V_112 ,
struct V_113 * V_114 )
{
V_114 -> V_115 /= 4 ;
}
static T_6 F_152 ( struct V_111 * V_112 , T_1 * V_116 ,
struct V_117 * V_106 , T_6 V_118 )
{
struct V_1 * V_2 = V_112 -> V_119 ;
struct V_120 * V_120 = V_2 -> V_63 ;
struct V_113 * V_114 = & V_112 -> V_121 ;
T_2 V_7 ;
T_2 V_122 ;
T_2 V_123 ;
unsigned long V_8 ;
unsigned int V_124 ;
int error = 0 ;
V_7 = * V_116 >> V_52 ;
V_123 = V_114 -> V_125 >> V_52 ;
V_124 = V_114 -> V_125 & ( V_126 - 1 ) ;
V_122 = ( * V_116 + V_106 -> V_127 + V_126 - 1 ) >> V_52 ;
V_8 = * V_116 & ~ V_128 ;
for (; ; ) {
struct V_3 * V_3 ;
T_2 V_129 ;
T_1 V_130 ;
unsigned long V_131 , V_32 ;
F_55 () ;
V_132:
V_3 = F_135 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
F_153 ( V_2 ,
V_114 , V_112 ,
V_7 , V_122 - V_7 ) ;
V_3 = F_135 ( V_2 , V_7 ) ;
if ( F_78 ( V_3 == NULL ) )
goto V_133;
}
if ( F_154 ( V_3 ) ) {
F_155 ( V_2 ,
V_114 , V_112 , V_3 ,
V_7 , V_122 - V_7 ) ;
}
if ( ! F_17 ( V_3 ) ) {
if ( V_120 -> V_134 == V_52 ||
! V_2 -> V_27 -> V_135 )
goto V_136;
if ( ! F_149 ( V_3 ) )
goto V_136;
if ( ! V_3 -> V_2 )
goto V_137;
if ( ! V_2 -> V_27 -> V_135 ( V_3 ,
V_8 , V_106 -> V_127 ) )
goto V_137;
F_109 ( V_3 ) ;
}
V_138:
V_130 = F_57 ( V_120 ) ;
V_129 = ( V_130 - 1 ) >> V_52 ;
if ( F_78 ( ! V_130 || V_7 > V_129 ) ) {
F_34 ( V_3 ) ;
goto V_57;
}
V_131 = V_126 ;
if ( V_7 == V_129 ) {
V_131 = ( ( V_130 - 1 ) & ~ V_128 ) + 1 ;
if ( V_131 <= V_8 ) {
F_34 ( V_3 ) ;
goto V_57;
}
}
V_131 = V_131 - V_8 ;
if ( F_156 ( V_2 ) )
F_157 ( V_3 ) ;
if ( V_123 != V_7 || V_8 != V_124 )
F_158 ( V_3 ) ;
V_123 = V_7 ;
V_32 = F_159 ( V_3 , V_8 , V_131 , V_106 ) ;
V_8 += V_32 ;
V_7 += V_8 >> V_52 ;
V_8 &= ~ V_128 ;
V_124 = V_8 ;
F_34 ( V_3 ) ;
V_118 += V_32 ;
if ( ! F_160 ( V_106 ) )
goto V_57;
if ( V_32 < V_131 ) {
error = - V_139 ;
goto V_57;
}
continue;
V_136:
error = F_161 ( V_3 ) ;
if ( F_78 ( error ) )
goto V_140;
V_137:
if ( ! V_3 -> V_2 ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
continue;
}
if ( F_17 ( V_3 ) ) {
F_109 ( V_3 ) ;
goto V_138;
}
V_141:
F_162 ( V_3 ) ;
error = V_2 -> V_27 -> V_141 ( V_112 , V_3 ) ;
if ( F_78 ( error ) ) {
if ( error == V_142 ) {
F_34 ( V_3 ) ;
error = 0 ;
goto V_132;
}
goto V_140;
}
if ( ! F_17 ( V_3 ) ) {
error = F_161 ( V_3 ) ;
if ( F_78 ( error ) )
goto V_140;
if ( ! F_17 ( V_3 ) ) {
if ( V_3 -> V_2 == NULL ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_132;
}
F_109 ( V_3 ) ;
F_151 ( V_112 , V_114 ) ;
error = - V_37 ;
goto V_140;
}
F_109 ( V_3 ) ;
}
goto V_138;
V_140:
F_34 ( V_3 ) ;
goto V_57;
V_133:
V_3 = F_163 ( V_2 ) ;
if ( ! V_3 ) {
error = - V_143 ;
goto V_57;
}
error = F_81 ( V_3 , V_2 ,
V_7 , V_144 ) ;
if ( error ) {
F_34 ( V_3 ) ;
if ( error == - V_73 ) {
error = 0 ;
goto V_132;
}
goto V_57;
}
goto V_141;
}
V_57:
V_114 -> V_125 = V_123 ;
V_114 -> V_125 <<= V_52 ;
V_114 -> V_125 |= V_124 ;
* V_116 = ( ( T_1 ) V_7 << V_52 ) + V_8 ;
F_164 ( V_112 ) ;
return V_118 ? V_118 : error ;
}
int F_165 ( const struct V_145 * V_146 ,
unsigned long * V_147 , T_7 * V_127 , int V_148 )
{
unsigned long V_149 ;
T_7 V_150 = 0 ;
for ( V_149 = 0 ; V_149 < * V_147 ; V_149 ++ ) {
const struct V_145 * V_151 = & V_146 [ V_149 ] ;
V_150 += V_151 -> V_152 ;
if ( F_78 ( ( T_6 ) ( V_150 | V_151 -> V_152 ) < 0 ) )
return - V_153 ;
if ( F_166 ( V_148 , V_151 -> V_154 , V_151 -> V_152 ) )
continue;
if ( V_149 == 0 )
return - V_139 ;
* V_147 = V_149 ;
V_150 -= V_151 -> V_152 ;
break;
}
* V_127 = V_150 ;
return 0 ;
}
T_6
F_167 ( struct V_155 * V_156 , const struct V_145 * V_146 ,
unsigned long V_147 , T_1 V_157 )
{
struct V_111 * V_112 = V_156 -> V_158 ;
T_6 V_159 ;
T_7 V_127 ;
T_1 * V_116 = & V_156 -> V_160 ;
struct V_117 V_60 ;
V_127 = 0 ;
V_159 = F_165 ( V_146 , & V_147 , & V_127 , V_161 ) ;
if ( V_159 )
return V_159 ;
F_168 ( & V_60 , V_146 , V_147 , V_127 , 0 ) ;
if ( V_112 -> V_162 & V_163 ) {
T_1 V_164 ;
struct V_1 * V_2 ;
struct V_120 * V_120 ;
V_2 = V_112 -> V_119 ;
V_120 = V_2 -> V_63 ;
if ( ! V_127 )
goto V_57;
V_164 = F_57 ( V_120 ) ;
V_159 = F_59 ( V_2 , V_157 ,
V_157 + F_169 ( V_146 , V_147 ) - 1 ) ;
if ( ! V_159 ) {
V_159 = V_2 -> V_27 -> V_165 ( V_166 , V_156 ,
V_146 , V_157 , V_147 ) ;
}
if ( V_159 > 0 ) {
* V_116 = V_157 + V_159 ;
V_127 -= V_159 ;
F_170 ( & V_60 , V_159 ) ;
}
if ( V_159 < 0 || ! V_127 || * V_116 >= V_164 ) {
F_164 ( V_112 ) ;
goto V_57;
}
}
V_159 = F_152 ( V_112 , V_116 , & V_60 , V_159 ) ;
V_57:
return V_159 ;
}
static int F_171 ( struct V_111 * V_111 , T_2 V_8 )
{
struct V_1 * V_2 = V_111 -> V_119 ;
struct V_3 * V_3 ;
int V_32 ;
do {
V_3 = F_163 ( V_2 ) ;
if ( ! V_3 )
return - V_143 ;
V_32 = F_81 ( V_3 , V_2 , V_8 , V_144 ) ;
if ( V_32 == 0 )
V_32 = V_2 -> V_27 -> V_141 ( V_111 , V_3 ) ;
else if ( V_32 == - V_73 )
V_32 = 0 ;
F_34 ( V_3 ) ;
} while ( V_32 == V_142 );
return V_32 ;
}
static void F_172 ( struct V_167 * V_168 ,
struct V_113 * V_114 ,
struct V_111 * V_111 ,
T_2 V_8 )
{
unsigned long V_115 ;
struct V_1 * V_2 = V_111 -> V_119 ;
if ( V_168 -> V_169 & V_170 )
return;
if ( ! V_114 -> V_115 )
return;
if ( V_168 -> V_169 & V_171 ) {
F_153 ( V_2 , V_114 , V_111 , V_8 ,
V_114 -> V_115 ) ;
return;
}
if ( V_114 -> V_172 < V_173 * 10 )
V_114 -> V_172 ++ ;
if ( V_114 -> V_172 > V_173 )
return;
V_115 = F_173 ( V_114 -> V_115 ) ;
V_114 -> V_38 = F_174 ( long , 0 , V_8 - V_115 / 2 ) ;
V_114 -> V_164 = V_115 ;
V_114 -> V_174 = V_115 / 4 ;
F_175 ( V_114 , V_2 , V_111 ) ;
}
static void F_176 ( struct V_167 * V_168 ,
struct V_113 * V_114 ,
struct V_111 * V_111 ,
struct V_3 * V_3 ,
T_2 V_8 )
{
struct V_1 * V_2 = V_111 -> V_119 ;
if ( V_168 -> V_169 & V_170 )
return;
if ( V_114 -> V_172 > 0 )
V_114 -> V_172 -- ;
if ( F_154 ( V_3 ) )
F_155 ( V_2 , V_114 , V_111 ,
V_3 , V_8 , V_114 -> V_115 ) ;
}
int F_177 ( struct V_167 * V_168 , struct V_175 * V_176 )
{
int error ;
struct V_111 * V_111 = V_168 -> V_177 ;
struct V_1 * V_2 = V_111 -> V_119 ;
struct V_113 * V_114 = & V_111 -> V_121 ;
struct V_120 * V_120 = V_2 -> V_63 ;
T_2 V_8 = V_176 -> V_178 ;
struct V_3 * V_3 ;
T_1 V_164 ;
int V_32 = 0 ;
V_164 = F_178 ( F_57 ( V_120 ) , V_126 ) ;
if ( V_8 >= V_164 >> V_52 )
return V_179 ;
V_3 = F_135 ( V_2 , V_8 ) ;
if ( F_179 ( V_3 ) && ! ( V_176 -> V_34 & V_180 ) ) {
F_176 ( V_168 , V_114 , V_111 , V_3 , V_8 ) ;
} else if ( ! V_3 ) {
F_172 ( V_168 , V_114 , V_111 , V_8 ) ;
F_180 ( V_181 ) ;
F_181 ( V_168 -> V_182 , V_181 ) ;
V_32 = V_183 ;
V_184:
V_3 = F_135 ( V_2 , V_8 ) ;
if ( ! V_3 )
goto V_133;
}
if ( ! F_182 ( V_3 , V_168 -> V_182 , V_176 -> V_34 ) ) {
F_34 ( V_3 ) ;
return V_32 | V_185 ;
}
if ( F_78 ( V_3 -> V_2 != V_2 ) ) {
F_109 ( V_3 ) ;
F_183 ( V_3 ) ;
goto V_184;
}
F_61 ( V_3 -> V_7 != V_8 , V_3 ) ;
if ( F_78 ( ! F_17 ( V_3 ) ) )
goto V_186;
V_164 = F_178 ( F_57 ( V_120 ) , V_126 ) ;
if ( F_78 ( V_8 >= V_164 >> V_52 ) ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_179 ;
}
V_176 -> V_3 = V_3 ;
return V_32 | V_187 ;
V_133:
error = F_171 ( V_111 , V_8 ) ;
if ( error >= 0 )
goto V_184;
if ( error == - V_143 )
return V_188 ;
return V_179 ;
V_186:
F_162 ( V_3 ) ;
error = V_2 -> V_27 -> V_141 ( V_111 , V_3 ) ;
if ( ! error ) {
F_123 ( V_3 ) ;
if ( ! F_17 ( V_3 ) )
error = - V_37 ;
}
F_34 ( V_3 ) ;
if ( ! error || error == V_142 )
goto V_184;
F_151 ( V_111 , V_114 ) ;
return V_179 ;
}
void F_184 ( struct V_167 * V_168 , struct V_175 * V_176 )
{
struct V_105 V_106 ;
void * * V_10 ;
struct V_111 * V_111 = V_168 -> V_177 ;
struct V_1 * V_2 = V_111 -> V_119 ;
T_1 V_164 ;
struct V_3 * V_3 ;
unsigned long V_189 = ( unsigned long ) V_176 -> V_190 ;
unsigned long V_191 ;
T_8 * V_192 ;
F_128 () ;
F_141 (slot, &mapping->page_tree, &iter, vmf->pgoff) {
if ( V_106 . V_7 > V_176 -> V_193 )
break;
V_101:
V_3 = F_130 ( V_10 ) ;
if ( F_78 ( ! V_3 ) )
goto V_194;
if ( F_131 ( V_3 ) ) {
if ( F_132 ( V_3 ) )
break;
else
goto V_194;
}
if ( ! F_133 ( V_3 ) )
goto V_101;
if ( F_78 ( V_3 != * V_10 ) ) {
F_34 ( V_3 ) ;
goto V_101;
}
if ( ! F_17 ( V_3 ) ||
F_154 ( V_3 ) ||
F_185 ( V_3 ) )
goto V_195;
if ( ! F_149 ( V_3 ) )
goto V_195;
if ( V_3 -> V_2 != V_2 || ! F_17 ( V_3 ) )
goto V_196;
V_164 = F_178 ( F_57 ( V_2 -> V_63 ) , V_126 ) ;
if ( V_3 -> V_7 >= V_164 >> V_52 )
goto V_196;
V_192 = V_176 -> V_192 + V_3 -> V_7 - V_176 -> V_178 ;
if ( ! F_186 ( * V_192 ) )
goto V_196;
if ( V_111 -> V_121 . V_172 > 0 )
V_111 -> V_121 . V_172 -- ;
V_191 = V_189 + ( V_3 -> V_7 - V_176 -> V_178 ) * V_197 ;
F_187 ( V_168 , V_191 , V_3 , V_192 , false , false ) ;
F_109 ( V_3 ) ;
goto V_194;
V_196:
F_109 ( V_3 ) ;
V_195:
F_34 ( V_3 ) ;
V_194:
if ( V_106 . V_7 == V_176 -> V_193 )
break;
}
F_134 () ;
}
int F_188 ( struct V_167 * V_168 , struct V_175 * V_176 )
{
struct V_3 * V_3 = V_176 -> V_3 ;
struct V_120 * V_120 = F_189 ( V_168 -> V_177 ) ;
int V_32 = V_187 ;
F_190 ( V_120 -> V_198 ) ;
F_191 ( V_168 -> V_177 ) ;
F_137 ( V_3 ) ;
if ( V_3 -> V_2 != V_120 -> V_199 ) {
F_109 ( V_3 ) ;
V_32 = V_200 ;
goto V_57;
}
F_192 ( V_3 ) ;
F_193 ( V_3 ) ;
V_57:
F_194 ( V_120 -> V_198 ) ;
return V_32 ;
}
int F_195 ( struct V_111 * V_111 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_111 -> V_119 ;
if ( ! V_2 -> V_27 -> V_141 )
return - V_201 ;
F_164 ( V_111 ) ;
V_168 -> V_202 = & V_203 ;
return 0 ;
}
int F_196 ( struct V_111 * V_111 , struct V_167 * V_168 )
{
if ( ( V_168 -> V_169 & V_204 ) && ( V_168 -> V_169 & V_205 ) )
return - V_153 ;
return F_195 ( V_111 , V_168 ) ;
}
int F_195 ( struct V_111 * V_111 , struct V_167 * V_168 )
{
return - V_206 ;
}
int F_196 ( struct V_111 * V_111 , struct V_167 * V_168 )
{
return - V_206 ;
}
static struct V_3 * F_197 ( struct V_3 * V_3 )
{
if ( ! F_198 ( V_3 ) ) {
F_123 ( V_3 ) ;
if ( ! F_17 ( V_3 ) ) {
F_34 ( V_3 ) ;
V_3 = F_199 ( - V_37 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_200 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_201)( void * , struct V_3 * ) ,
void * V_207 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_64 ;
V_101:
V_3 = F_135 ( V_2 , V_7 ) ;
if ( ! V_3 ) {
V_3 = F_89 ( V_77 | V_208 ) ;
if ( ! V_3 )
return F_199 ( - V_143 ) ;
V_64 = F_81 ( V_3 , V_2 , V_7 , V_77 ) ;
if ( F_78 ( V_64 ) ) {
F_34 ( V_3 ) ;
if ( V_64 == - V_73 )
goto V_101;
return F_199 ( V_64 ) ;
}
V_64 = F_201 ( V_207 , V_3 ) ;
if ( V_64 < 0 ) {
F_34 ( V_3 ) ;
V_3 = F_199 ( V_64 ) ;
} else {
V_3 = F_197 ( V_3 ) ;
}
}
return V_3 ;
}
static struct V_3 * F_202 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_201)( void * , struct V_3 * ) ,
void * V_207 ,
T_3 V_77 )
{
struct V_3 * V_3 ;
int V_64 ;
V_209:
V_3 = F_200 ( V_2 , V_7 , F_201 , V_207 , V_77 ) ;
if ( F_198 ( V_3 ) )
return V_3 ;
if ( F_17 ( V_3 ) )
goto V_57;
F_137 ( V_3 ) ;
if ( ! V_3 -> V_2 ) {
F_109 ( V_3 ) ;
F_34 ( V_3 ) ;
goto V_209;
}
if ( F_17 ( V_3 ) ) {
F_109 ( V_3 ) ;
goto V_57;
}
V_64 = F_201 ( V_207 , V_3 ) ;
if ( V_64 < 0 ) {
F_34 ( V_3 ) ;
return F_199 ( V_64 ) ;
} else {
V_3 = F_197 ( V_3 ) ;
if ( F_198 ( V_3 ) )
return V_3 ;
}
V_57:
F_158 ( V_3 ) ;
return V_3 ;
}
struct V_3 * F_203 ( struct V_1 * V_2 ,
T_2 V_7 ,
int (* F_201)( void * , struct V_3 * ) ,
void * V_207 )
{
return F_202 ( V_2 , V_7 , F_201 , V_207 , F_150 ( V_2 ) ) ;
}
struct V_3 * F_204 ( struct V_1 * V_2 ,
T_2 V_7 ,
T_3 V_77 )
{
T_9 * F_201 = ( T_9 * ) V_2 -> V_27 -> V_141 ;
return F_202 ( V_2 , V_7 , F_201 , NULL , V_77 ) ;
}
inline int F_205 ( struct V_111 * V_111 , T_1 * V_157 , T_7 * V_127 , int V_210 )
{
struct V_120 * V_120 = V_111 -> V_119 -> V_63 ;
unsigned long V_211 = F_206 ( V_212 ) ;
if ( F_78 ( * V_157 < 0 ) )
return - V_153 ;
if ( ! V_210 ) {
if ( V_111 -> V_162 & V_213 )
* V_157 = F_57 ( V_120 ) ;
if ( V_211 != V_214 ) {
if ( * V_157 >= V_211 ) {
F_207 ( V_215 , V_30 , 0 ) ;
return - V_216 ;
}
if ( * V_127 > V_211 - ( F_208 ( V_211 ) ) * V_157 ) {
* V_127 = V_211 - ( F_208 ( V_211 ) ) * V_157 ;
}
}
}
if ( F_78 ( * V_157 + * V_127 > V_217 &&
! ( V_111 -> V_162 & V_218 ) ) ) {
if ( * V_157 >= V_217 ) {
return - V_216 ;
}
if ( * V_127 > V_217 - ( unsigned long ) * V_157 ) {
* V_127 = V_217 - ( unsigned long ) * V_157 ;
}
}
if ( F_179 ( ! V_210 ) ) {
if ( F_78 ( * V_157 >= V_120 -> V_198 -> V_219 ) ) {
if ( * V_127 || * V_157 > V_120 -> V_198 -> V_219 ) {
return - V_216 ;
}
}
if ( F_78 ( * V_157 + * V_127 > V_120 -> V_198 -> V_219 ) )
* V_127 = V_120 -> V_198 -> V_219 - * V_157 ;
} else {
#ifdef F_209
T_1 V_130 ;
if ( F_210 ( F_211 ( V_120 ) ) )
return - V_220 ;
V_130 = F_57 ( V_120 ) ;
if ( * V_157 >= V_130 ) {
if ( * V_127 || * V_157 > V_130 )
return - V_35 ;
}
if ( * V_157 + * V_127 > V_130 )
* V_127 = V_130 - * V_157 ;
#else
return - V_220 ;
#endif
}
return 0 ;
}
int F_212 ( struct V_111 * V_111 , struct V_1 * V_2 ,
T_1 V_157 , unsigned V_221 , unsigned V_34 ,
struct V_3 * * V_100 , void * * V_222 )
{
const struct V_223 * V_224 = V_2 -> V_27 ;
return V_224 -> V_225 ( V_111 , V_2 , V_157 , V_221 , V_34 ,
V_100 , V_222 ) ;
}
int F_213 ( struct V_111 * V_111 , struct V_1 * V_2 ,
T_1 V_157 , unsigned V_221 , unsigned V_226 ,
struct V_3 * V_3 , void * V_222 )
{
const struct V_223 * V_224 = V_2 -> V_27 ;
F_158 ( V_3 ) ;
return V_224 -> V_227 ( V_111 , V_2 , V_157 , V_221 , V_226 , V_3 , V_222 ) ;
}
T_6
F_214 ( struct V_155 * V_156 , const struct V_145 * V_146 ,
unsigned long * V_147 , T_1 V_157 ,
T_7 V_127 , T_7 V_228 )
{
struct V_111 * V_111 = V_156 -> V_158 ;
struct V_1 * V_2 = V_111 -> V_119 ;
struct V_120 * V_120 = V_2 -> V_63 ;
T_6 V_118 ;
T_7 V_229 ;
T_2 V_39 ;
if ( V_127 != V_228 )
* V_147 = F_215 ( (struct V_145 * ) V_146 , * V_147 , V_127 ) ;
V_229 = F_169 ( V_146 , * V_147 ) ;
V_39 = ( V_157 + V_229 - 1 ) >> V_52 ;
V_118 = F_59 ( V_2 , V_157 , V_157 + V_229 - 1 ) ;
if ( V_118 )
goto V_57;
if ( V_2 -> V_13 ) {
V_118 = F_216 ( V_2 ,
V_157 >> V_52 , V_39 ) ;
if ( V_118 ) {
if ( V_118 == - V_230 )
return 0 ;
goto V_57;
}
}
V_118 = V_2 -> V_27 -> V_165 ( V_231 , V_156 , V_146 , V_157 , * V_147 ) ;
if ( V_2 -> V_13 ) {
F_216 ( V_2 ,
V_157 >> V_52 , V_39 ) ;
}
if ( V_118 > 0 ) {
V_157 += V_118 ;
if ( V_157 > F_57 ( V_120 ) && ! F_217 ( V_120 -> V_232 ) ) {
F_218 ( V_120 , V_157 ) ;
F_219 ( V_120 ) ;
}
V_156 -> V_160 = V_157 ;
}
V_57:
return V_118 ;
}
struct V_3 * F_220 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned V_34 )
{
int V_233 ;
T_3 V_14 ;
struct V_3 * V_3 ;
T_3 V_234 = 0 ;
V_14 = F_150 ( V_2 ) ;
if ( F_26 ( V_2 ) )
V_14 |= V_235 ;
if ( V_34 & V_236 )
V_234 = V_109 ;
V_101:
V_3 = F_138 ( V_2 , V_7 ) ;
if ( V_3 )
goto V_237;
V_3 = F_89 ( V_14 & ~ V_234 ) ;
if ( ! V_3 )
return NULL ;
V_233 = F_81 ( V_3 , V_2 , V_7 ,
V_144 & ~ V_234 ) ;
if ( F_78 ( V_233 ) ) {
F_34 ( V_3 ) ;
if ( V_233 == - V_73 )
goto V_101;
return NULL ;
}
V_237:
F_193 ( V_3 ) ;
return V_3 ;
}
T_6 F_221 ( struct V_111 * V_111 ,
struct V_117 * V_60 , T_1 V_157 )
{
struct V_1 * V_2 = V_111 -> V_119 ;
const struct V_223 * V_27 = V_2 -> V_27 ;
long V_233 = 0 ;
T_6 V_118 = 0 ;
unsigned int V_34 = 0 ;
if ( F_222 ( F_223 () , V_238 ) )
V_34 |= V_239 ;
do {
struct V_3 * V_3 ;
unsigned long V_8 ;
unsigned long V_240 ;
T_7 V_226 ;
void * V_222 ;
V_8 = ( V_157 & ( V_126 - 1 ) ) ;
V_240 = F_224 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_241:
if ( F_78 ( F_225 ( V_60 , V_240 ) ) ) {
V_233 = - V_139 ;
break;
}
V_233 = V_27 -> V_225 ( V_111 , V_2 , V_157 , V_240 , V_34 ,
& V_3 , & V_222 ) ;
if ( F_78 ( V_233 ) )
break;
if ( F_156 ( V_2 ) )
F_157 ( V_3 ) ;
V_226 = F_226 ( V_3 , V_60 , V_8 , V_240 ) ;
F_157 ( V_3 ) ;
F_158 ( V_3 ) ;
V_233 = V_27 -> V_227 ( V_111 , V_2 , V_157 , V_240 , V_226 ,
V_3 , V_222 ) ;
if ( F_78 ( V_233 < 0 ) )
break;
V_226 = V_233 ;
F_55 () ;
F_170 ( V_60 , V_226 ) ;
if ( F_78 ( V_226 == 0 ) ) {
V_240 = F_224 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_241;
}
V_157 += V_226 ;
V_118 += V_226 ;
F_227 ( V_2 ) ;
if ( F_38 ( V_30 ) ) {
V_233 = - V_31 ;
break;
}
} while ( F_160 ( V_60 ) );
return V_118 ? V_118 : V_233 ;
}
T_6 F_228 ( struct V_155 * V_156 , const struct V_145 * V_146 ,
unsigned long V_147 )
{
struct V_111 * V_111 = V_156 -> V_158 ;
struct V_1 * V_2 = V_111 -> V_119 ;
T_7 V_228 ;
T_7 V_127 ;
struct V_120 * V_120 = V_2 -> V_63 ;
T_1 V_157 = V_156 -> V_160 ;
T_6 V_118 = 0 ;
T_6 V_64 ;
T_6 V_233 ;
struct V_117 V_242 ;
V_228 = 0 ;
V_64 = F_165 ( V_146 , & V_147 , & V_228 , V_243 ) ;
if ( V_64 )
return V_64 ;
V_127 = V_228 ;
V_30 -> V_25 = V_2 -> V_25 ;
V_64 = F_205 ( V_111 , & V_157 , & V_127 , F_217 ( V_120 -> V_232 ) ) ;
if ( V_64 )
goto V_57;
if ( V_127 == 0 )
goto V_57;
V_64 = F_229 ( V_111 ) ;
if ( V_64 )
goto V_57;
V_64 = F_191 ( V_111 ) ;
if ( V_64 )
goto V_57;
F_168 ( & V_242 , V_146 , V_147 , V_127 , 0 ) ;
if ( F_78 ( V_111 -> V_162 & V_163 ) ) {
T_1 V_244 ;
V_118 = F_214 ( V_156 , V_146 , & V_242 . V_147 , V_157 ,
V_127 , V_228 ) ;
if ( V_118 < 0 || V_118 == V_127 )
goto V_57;
F_170 ( & V_242 , V_118 ) ;
V_157 += V_118 ;
V_127 -= V_118 ;
V_233 = F_221 ( V_111 , & V_242 , V_157 ) ;
if ( F_78 ( V_233 < 0 ) && ! V_118 ) {
V_64 = V_233 ;
goto V_57;
}
V_156 -> V_160 = V_157 + V_233 ;
V_244 = V_157 + V_233 - 1 ;
V_64 = F_59 ( V_111 -> V_119 , V_157 , V_244 ) ;
if ( V_64 == 0 ) {
V_118 += V_233 ;
F_230 ( V_2 ,
V_157 >> V_52 ,
V_244 >> V_52 ) ;
} else {
}
} else {
V_118 = F_221 ( V_111 , & V_242 , V_157 ) ;
if ( F_179 ( V_118 >= 0 ) )
V_156 -> V_160 = V_157 + V_118 ;
}
V_57:
V_30 -> V_25 = NULL ;
return V_118 ? V_118 : V_64 ;
}
T_6 F_231 ( struct V_155 * V_156 , const struct V_145 * V_146 ,
unsigned long V_147 , T_1 V_157 )
{
struct V_111 * V_111 = V_156 -> V_158 ;
struct V_120 * V_120 = V_111 -> V_119 -> V_63 ;
T_6 V_32 ;
F_23 ( V_156 -> V_160 != V_157 ) ;
F_232 ( & V_120 -> V_245 ) ;
V_32 = F_228 ( V_156 , V_146 , V_147 ) ;
F_233 ( & V_120 -> V_245 ) ;
if ( V_32 > 0 ) {
T_6 V_64 ;
V_64 = F_234 ( V_111 , V_156 -> V_160 - V_32 , V_32 ) ;
if ( V_64 < 0 )
V_32 = V_64 ;
}
return V_32 ;
}
int F_235 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_1 * const V_2 = V_3 -> V_2 ;
F_23 ( ! F_3 ( V_3 ) ) ;
if ( F_236 ( V_3 ) )
return 0 ;
if ( V_2 && V_2 -> V_27 -> V_246 )
return V_2 -> V_27 -> V_246 ( V_3 , V_14 ) ;
return F_237 ( V_3 ) ;
}
