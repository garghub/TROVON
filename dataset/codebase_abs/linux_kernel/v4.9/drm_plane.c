static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
struct V_4 * V_5 ;
F_2 (tmp, dev) {
V_3 ++ ;
}
return V_3 ;
}
int F_3 ( struct V_1 * V_2 , struct V_4 * V_6 ,
unsigned long V_7 ,
const struct V_8 * V_9 ,
const T_1 * V_10 , unsigned int V_11 ,
enum V_12 type ,
const char * V_13 , ... )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
int V_17 ;
V_17 = F_4 ( V_2 , & V_6 -> V_18 , V_19 ) ;
if ( V_17 )
return V_17 ;
F_5 ( & V_6 -> V_20 ) ;
V_6 -> V_18 . V_21 = & V_6 -> V_21 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_22 = F_6 ( V_11 , sizeof( T_1 ) ,
V_23 ) ;
if ( ! V_6 -> V_22 ) {
F_7 ( L_1 ) ;
F_8 ( V_2 , & V_6 -> V_18 ) ;
return - V_24 ;
}
if ( V_13 ) {
T_2 V_25 ;
va_start ( V_25 , V_13 ) ;
V_6 -> V_13 = F_9 ( V_23 , V_13 , V_25 ) ;
va_end ( V_25 ) ;
} else {
V_6 -> V_13 = F_10 ( V_23 , L_2 ,
F_1 ( V_2 ) ) ;
}
if ( ! V_6 -> V_13 ) {
F_11 ( V_6 -> V_22 ) ;
F_8 ( V_2 , & V_6 -> V_18 ) ;
return - V_24 ;
}
memcpy ( V_6 -> V_22 , V_10 , V_11 * sizeof( T_1 ) ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_7 = V_7 ;
V_6 -> type = type ;
F_12 ( & V_6 -> V_26 , & V_15 -> V_27 ) ;
V_6 -> V_28 = V_15 -> V_29 ++ ;
if ( V_6 -> type == V_30 )
V_15 -> V_31 ++ ;
F_13 ( & V_6 -> V_18 ,
V_15 -> V_32 ,
V_6 -> type ) ;
if ( F_14 ( V_2 , V_33 ) ) {
F_13 ( & V_6 -> V_18 , V_15 -> V_34 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_35 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_36 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_37 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_38 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_39 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_40 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_41 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_42 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_43 , 0 ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
int V_17 = 0 ;
F_2 (plane, dev) {
if ( V_6 -> V_9 -> V_44 )
V_17 = V_6 -> V_9 -> V_44 ( V_6 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
F_2 (plane, dev) {
if ( V_6 -> V_9 -> V_45 )
V_6 -> V_9 -> V_45 ( V_6 ) ;
}
}
int F_17 ( struct V_1 * V_2 , struct V_4 * V_6 ,
unsigned long V_7 ,
const struct V_8 * V_9 ,
const T_1 * V_10 , unsigned int V_11 ,
bool V_46 )
{
enum V_12 type ;
type = V_46 ? V_47 : V_30 ;
return F_3 ( V_2 , V_6 , V_7 , V_9 ,
V_10 , V_11 , type , NULL ) ;
}
void F_18 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_19 ( V_2 ) ;
F_11 ( V_6 -> V_22 ) ;
F_8 ( V_2 , & V_6 -> V_18 ) ;
F_20 ( F_21 ( & V_6 -> V_26 ) ) ;
F_22 ( & V_6 -> V_26 ) ;
V_2 -> V_16 . V_29 -- ;
if ( V_6 -> type == V_30 )
V_2 -> V_16 . V_31 -- ;
F_23 ( V_2 ) ;
F_24 ( V_6 -> V_48 && ! V_6 -> V_9 -> V_49 ) ;
if ( V_6 -> V_48 && V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_6 -> V_48 ) ;
F_11 ( V_6 -> V_13 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
}
struct V_4 *
F_25 ( struct V_1 * V_2 , int V_50 )
{
struct V_4 * V_6 ;
F_2 (plane, dev)
if ( V_50 == V_6 -> V_28 )
return V_6 ;
return NULL ;
}
void F_26 ( struct V_4 * V_6 )
{
int V_17 ;
if ( ! V_6 -> V_51 )
return;
V_6 -> V_52 = V_6 -> V_51 ;
V_17 = V_6 -> V_9 -> V_53 ( V_6 ) ;
if ( V_17 ) {
F_27 ( L_3 ) ;
V_6 -> V_52 = NULL ;
return;
}
F_28 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
V_6 -> V_51 = NULL ;
V_6 -> V_54 = NULL ;
}
int F_29 ( struct V_4 * V_6 ,
struct V_55 * V_56 ,
T_3 V_57 )
{
int V_17 = - V_58 ;
struct V_59 * V_60 = & V_6 -> V_18 ;
if ( V_6 -> V_9 -> V_61 )
V_17 = V_6 -> V_9 -> V_61 ( V_6 , V_56 , V_57 ) ;
if ( ! V_17 )
F_30 ( V_60 , V_56 , V_57 ) ;
return V_17 ;
}
int F_31 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = V_62 ;
struct V_14 * V_15 ;
struct V_4 * V_6 ;
T_1 T_4 * V_67 ;
int V_68 = 0 ;
unsigned V_69 ;
if ( ! F_14 ( V_2 , V_70 ) )
return - V_58 ;
V_15 = & V_2 -> V_16 ;
if ( V_64 -> V_71 )
V_69 = V_15 -> V_29 ;
else
V_69 = V_15 -> V_31 ;
if ( V_69 &&
( V_66 -> V_72 >= V_69 ) ) {
V_67 = ( T_1 T_4 * ) ( unsigned long ) V_66 -> V_73 ;
F_2 (plane, dev) {
if ( V_6 -> type != V_30 &&
! V_64 -> V_71 )
continue;
if ( F_32 ( V_6 -> V_18 . V_74 , V_67 + V_68 ) )
return - V_75 ;
V_68 ++ ;
}
}
V_66 -> V_72 = V_69 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_76 * V_66 = V_62 ;
struct V_4 * V_6 ;
T_1 T_4 * V_77 ;
if ( ! F_14 ( V_2 , V_70 ) )
return - V_58 ;
V_6 = F_34 ( V_2 , V_66 -> V_78 ) ;
if ( ! V_6 )
return - V_79 ;
F_35 ( & V_6 -> V_20 , NULL ) ;
if ( V_6 -> V_54 )
V_66 -> V_80 = V_6 -> V_54 -> V_18 . V_74 ;
else
V_66 -> V_80 = 0 ;
if ( V_6 -> V_51 )
V_66 -> V_81 = V_6 -> V_51 -> V_18 . V_74 ;
else
V_66 -> V_81 = 0 ;
F_36 ( & V_6 -> V_20 ) ;
V_66 -> V_78 = V_6 -> V_18 . V_74 ;
V_66 -> V_7 = V_6 -> V_7 ;
V_66 -> V_82 = 0 ;
if ( V_6 -> V_11 &&
( V_66 -> V_83 >= V_6 -> V_11 ) ) {
V_77 = ( T_1 T_4 * ) ( unsigned long ) V_66 -> V_84 ;
if ( F_37 ( V_77 ,
V_6 -> V_22 ,
sizeof( T_1 ) * V_6 -> V_11 ) ) {
return - V_75 ;
}
}
V_66 -> V_83 = V_6 -> V_11 ;
return 0 ;
}
int F_38 ( const struct V_4 * V_6 , T_5 V_85 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_6 -> V_11 ; V_86 ++ ) {
if ( V_85 == V_6 -> V_22 [ V_86 ] )
return 0 ;
}
return - V_58 ;
}
static int F_39 ( struct V_4 * V_6 ,
struct V_87 * V_54 ,
struct V_88 * V_51 ,
T_6 V_89 , T_6 V_90 ,
T_1 V_91 , T_1 V_92 ,
T_1 V_93 , T_1 V_94 ,
T_1 V_95 , T_1 V_96 )
{
int V_17 = 0 ;
if ( ! V_51 ) {
V_6 -> V_52 = V_6 -> V_51 ;
V_17 = V_6 -> V_9 -> V_53 ( V_6 ) ;
if ( ! V_17 ) {
V_6 -> V_54 = NULL ;
V_6 -> V_51 = NULL ;
} else {
V_6 -> V_52 = NULL ;
}
goto V_97;
}
if ( ! ( V_6 -> V_7 & F_40 ( V_54 ) ) ) {
F_7 ( L_4 ) ;
V_17 = - V_58 ;
goto V_97;
}
V_17 = F_38 ( V_6 , V_51 -> V_98 ) ;
if ( V_17 ) {
char * V_99 = F_41 ( V_51 -> V_98 ) ;
F_7 ( L_5 , V_99 ) ;
F_11 ( V_99 ) ;
goto V_97;
}
if ( V_91 > V_100 ||
V_89 > V_100 - ( T_6 ) V_91 ||
V_92 > V_100 ||
V_90 > V_100 - ( T_6 ) V_92 ) {
F_7 ( L_6 ,
V_91 , V_92 , V_89 , V_90 ) ;
V_17 = - V_101 ;
goto V_97;
}
V_17 = F_42 ( V_93 , V_94 , V_95 , V_96 , V_51 ) ;
if ( V_17 )
goto V_97;
V_6 -> V_52 = V_6 -> V_51 ;
V_17 = V_6 -> V_9 -> V_102 ( V_6 , V_54 , V_51 ,
V_89 , V_90 , V_91 , V_92 ,
V_93 , V_94 , V_95 , V_96 ) ;
if ( ! V_17 ) {
V_6 -> V_54 = V_54 ;
V_6 -> V_51 = V_51 ;
V_51 = NULL ;
} else {
V_6 -> V_52 = NULL ;
}
V_97:
if ( V_51 )
F_28 ( V_51 ) ;
if ( V_6 -> V_52 )
F_28 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
return V_17 ;
}
static int F_43 ( struct V_4 * V_6 ,
struct V_87 * V_54 ,
struct V_88 * V_51 ,
T_6 V_89 , T_6 V_90 ,
T_1 V_91 , T_1 V_92 ,
T_1 V_93 , T_1 V_94 ,
T_1 V_95 , T_1 V_96 )
{
int V_17 ;
F_19 ( V_6 -> V_2 ) ;
V_17 = F_39 ( V_6 , V_54 , V_51 ,
V_89 , V_90 , V_91 , V_92 ,
V_93 , V_94 , V_95 , V_96 ) ;
F_23 ( V_6 -> V_2 ) ;
return V_17 ;
}
int F_44 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_103 * V_104 = V_62 ;
struct V_4 * V_6 ;
struct V_87 * V_54 = NULL ;
struct V_88 * V_51 = NULL ;
if ( ! F_14 ( V_2 , V_70 ) )
return - V_58 ;
V_6 = F_34 ( V_2 , V_104 -> V_78 ) ;
if ( ! V_6 ) {
F_7 ( L_7 ,
V_104 -> V_78 ) ;
return - V_79 ;
}
if ( V_104 -> V_81 ) {
V_51 = F_45 ( V_2 , V_104 -> V_81 ) ;
if ( ! V_51 ) {
F_7 ( L_8 ,
V_104 -> V_81 ) ;
return - V_79 ;
}
V_54 = F_46 ( V_2 , V_104 -> V_80 ) ;
if ( ! V_54 ) {
F_7 ( L_9 ,
V_104 -> V_80 ) ;
return - V_79 ;
}
}
return F_43 ( V_6 , V_54 , V_51 ,
V_104 -> V_89 , V_104 -> V_90 ,
V_104 -> V_91 , V_104 -> V_92 ,
V_104 -> V_93 , V_104 -> V_94 ,
V_104 -> V_95 , V_104 -> V_96 ) ;
}
static int F_47 ( struct V_87 * V_54 ,
struct V_105 * V_106 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_88 * V_51 = NULL ;
struct V_107 V_108 = {
. V_109 = V_106 -> V_109 ,
. V_110 = V_106 -> V_110 ,
. V_98 = V_111 ,
. V_112 = { V_106 -> V_109 * 4 } ,
. V_113 = { V_106 -> V_114 } ,
} ;
T_6 V_89 , V_90 ;
T_1 V_91 = 0 , V_92 = 0 ;
T_1 V_95 = 0 , V_96 = 0 ;
int V_17 = 0 ;
F_20 ( ! V_54 -> V_115 ) ;
F_24 ( V_54 -> V_115 -> V_54 != V_54 && V_54 -> V_115 -> V_54 != NULL ) ;
if ( V_106 -> V_116 & V_117 ) {
if ( V_106 -> V_114 ) {
V_51 = F_48 ( V_2 , & V_108 , V_64 ) ;
if ( F_49 ( V_51 ) ) {
F_7 ( L_10 ) ;
return F_50 ( V_51 ) ;
}
V_51 -> V_118 = V_106 -> V_118 ;
V_51 -> V_119 = V_106 -> V_119 ;
} else {
V_51 = NULL ;
}
} else {
V_51 = V_54 -> V_115 -> V_51 ;
if ( V_51 )
F_51 ( V_51 ) ;
}
if ( V_106 -> V_116 & V_120 ) {
V_89 = V_106 -> V_121 ;
V_90 = V_106 -> V_122 ;
} else {
V_89 = V_54 -> V_123 ;
V_90 = V_54 -> V_124 ;
}
if ( V_51 ) {
V_91 = V_51 -> V_109 ;
V_92 = V_51 -> V_110 ;
V_95 = V_51 -> V_109 << 16 ;
V_96 = V_51 -> V_110 << 16 ;
}
V_17 = F_39 ( V_54 -> V_115 , V_54 , V_51 ,
V_89 , V_90 , V_91 , V_92 ,
0 , 0 , V_95 , V_96 ) ;
if ( V_17 == 0 && V_106 -> V_116 & V_120 ) {
V_54 -> V_123 = V_106 -> V_121 ;
V_54 -> V_124 = V_106 -> V_122 ;
}
return V_17 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_63 * V_64 )
{
struct V_87 * V_54 ;
int V_17 = 0 ;
if ( ! F_14 ( V_2 , V_70 ) )
return - V_58 ;
if ( ! V_106 -> V_116 || ( ~ V_125 & V_106 -> V_116 ) )
return - V_58 ;
V_54 = F_46 ( V_2 , V_106 -> V_80 ) ;
if ( ! V_54 ) {
F_7 ( L_11 , V_106 -> V_80 ) ;
return - V_79 ;
}
F_53 ( V_54 , V_54 -> V_115 ) ;
if ( V_54 -> V_115 ) {
V_17 = F_47 ( V_54 , V_106 , V_64 ) ;
goto V_97;
}
if ( V_106 -> V_116 & V_117 ) {
if ( ! V_54 -> V_9 -> V_126 && ! V_54 -> V_9 -> V_127 ) {
V_17 = - V_128 ;
goto V_97;
}
if ( V_54 -> V_9 -> V_127 )
V_17 = V_54 -> V_9 -> V_127 ( V_54 , V_64 , V_106 -> V_114 ,
V_106 -> V_109 , V_106 -> V_110 , V_106 -> V_118 , V_106 -> V_119 ) ;
else
V_17 = V_54 -> V_9 -> V_126 ( V_54 , V_64 , V_106 -> V_114 ,
V_106 -> V_109 , V_106 -> V_110 ) ;
}
if ( V_106 -> V_116 & V_120 ) {
if ( V_54 -> V_9 -> V_129 ) {
V_17 = V_54 -> V_9 -> V_129 ( V_54 , V_106 -> V_121 , V_106 -> V_122 ) ;
} else {
V_17 = - V_75 ;
goto V_97;
}
}
V_97:
F_54 ( V_54 ) ;
return V_17 ;
}
int F_55 ( struct V_1 * V_2 ,
void * V_62 , struct V_63 * V_64 )
{
struct V_130 * V_106 = V_62 ;
struct V_105 V_131 ;
memcpy ( & V_131 , V_106 , sizeof( struct V_130 ) ) ;
V_131 . V_118 = V_131 . V_119 = 0 ;
return F_52 ( V_2 , & V_131 , V_64 ) ;
}
int F_56 ( struct V_1 * V_2 ,
void * V_62 , struct V_63 * V_64 )
{
struct V_105 * V_106 = V_62 ;
return F_52 ( V_2 , V_106 , V_64 ) ;
}
int F_57 ( struct V_1 * V_2 ,
void * V_62 , struct V_63 * V_64 )
{
struct V_132 * V_133 = V_62 ;
struct V_87 * V_54 ;
struct V_88 * V_51 = NULL ;
struct V_134 * V_135 = NULL ;
T_5 V_136 = V_133 -> V_137 ;
int V_17 = - V_58 ;
if ( ! F_14 ( V_2 , V_70 ) )
return - V_58 ;
if ( V_133 -> V_116 & ~ V_138 )
return - V_58 ;
if ( V_133 -> V_137 != 0 && ! ( V_133 -> V_116 & V_139 ) )
return - V_58 ;
if ( ( V_133 -> V_116 & V_139 ) == V_139 )
return - V_58 ;
if ( ( V_133 -> V_116 & V_140 ) && ! V_2 -> V_16 . V_141 )
return - V_58 ;
V_54 = F_46 ( V_2 , V_133 -> V_80 ) ;
if ( ! V_54 )
return - V_79 ;
if ( V_54 -> V_9 -> V_142 ) {
T_5 V_143 ;
int V_144 ;
V_144 = F_58 ( V_54 ) ;
if ( V_144 )
return V_144 ;
V_143 = F_59 ( V_54 ) ;
switch ( V_133 -> V_116 & V_139 ) {
case V_145 :
if ( ( int ) ( V_136 - V_143 ) > 1 ) {
F_60 ( L_12
L_13 , V_136 ,
V_143 + 1 ) ;
F_61 ( V_54 ) ;
return - V_58 ;
}
break;
case V_146 :
if ( V_136 != 0 && V_136 != 1 ) {
F_60 ( L_14
L_15 , V_136 ) ;
F_61 ( V_54 ) ;
return - V_58 ;
}
V_136 += V_143 ;
break;
default:
V_136 = V_143 +
! ( V_133 -> V_116 & V_140 ) ;
break;
}
} else if ( V_54 -> V_9 -> V_133 == NULL ||
( V_133 -> V_116 & V_139 ) ) {
return - V_58 ;
}
F_53 ( V_54 , V_54 -> V_147 ) ;
if ( V_54 -> V_147 -> V_51 == NULL ) {
V_17 = - V_148 ;
goto V_97;
}
V_51 = F_45 ( V_2 , V_133 -> V_81 ) ;
if ( ! V_51 ) {
V_17 = - V_79 ;
goto V_97;
}
if ( V_54 -> V_48 ) {
const struct V_149 * V_48 = V_54 -> V_147 -> V_48 ;
V_17 = F_42 ( V_48 -> V_93 ,
V_48 -> V_94 ,
V_48 -> V_95 ,
V_48 -> V_96 ,
V_51 ) ;
} else {
V_17 = F_62 ( V_54 , V_54 -> V_121 , V_54 -> V_122 , & V_54 -> V_150 , V_51 ) ;
}
if ( V_17 )
goto V_97;
if ( V_54 -> V_147 -> V_51 -> V_98 != V_51 -> V_98 ) {
F_7 ( L_16 ) ;
V_17 = - V_58 ;
goto V_97;
}
if ( V_133 -> V_116 & V_151 ) {
V_135 = F_63 ( sizeof *V_135 , V_23 ) ;
if ( ! V_135 ) {
V_17 = - V_24 ;
goto V_97;
}
V_135 -> V_152 . V_18 . type = V_153 ;
V_135 -> V_152 . V_18 . V_154 = sizeof( V_135 -> V_152 ) ;
V_135 -> V_152 . V_155 = V_133 -> V_155 ;
V_17 = F_64 ( V_2 , V_64 , & V_135 -> V_18 , & V_135 -> V_152 . V_18 ) ;
if ( V_17 ) {
F_11 ( V_135 ) ;
goto V_97;
}
}
V_54 -> V_147 -> V_52 = V_54 -> V_147 -> V_51 ;
if ( V_54 -> V_9 -> V_142 )
V_17 = V_54 -> V_9 -> V_142 ( V_54 , V_51 , V_135 ,
V_133 -> V_116 ,
V_136 ) ;
else
V_17 = V_54 -> V_9 -> V_133 ( V_54 , V_51 , V_135 , V_133 -> V_116 ) ;
if ( V_17 ) {
if ( V_133 -> V_116 & V_151 )
F_65 ( V_2 , & V_135 -> V_18 ) ;
V_54 -> V_147 -> V_52 = NULL ;
} else {
V_54 -> V_147 -> V_51 = V_51 ;
V_51 = NULL ;
}
V_97:
if ( V_17 && V_54 -> V_9 -> V_142 )
F_61 ( V_54 ) ;
if ( V_51 )
F_28 ( V_51 ) ;
if ( V_54 -> V_147 -> V_52 )
F_28 ( V_54 -> V_147 -> V_52 ) ;
V_54 -> V_147 -> V_52 = NULL ;
F_54 ( V_54 ) ;
return V_17 ;
}
