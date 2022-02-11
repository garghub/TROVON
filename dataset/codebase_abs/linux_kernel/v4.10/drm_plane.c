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
T_1 V_7 ,
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
F_13 ( & V_6 -> V_18 , V_15 -> V_35 , - 1 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_36 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_37 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_38 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_39 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_40 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_41 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_42 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_43 , 0 ) ;
F_13 ( & V_6 -> V_18 , V_15 -> V_44 , 0 ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
int V_17 = 0 ;
F_2 (plane, dev) {
if ( V_6 -> V_9 -> V_45 )
V_17 = V_6 -> V_9 -> V_45 ( V_6 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
F_2 (plane, dev) {
if ( V_6 -> V_9 -> V_46 )
V_6 -> V_9 -> V_46 ( V_6 ) ;
}
}
int F_17 ( struct V_1 * V_2 , struct V_4 * V_6 ,
T_1 V_7 ,
const struct V_8 * V_9 ,
const T_1 * V_10 , unsigned int V_11 ,
bool V_47 )
{
enum V_12 type ;
type = V_47 ? V_48 : V_30 ;
return F_3 ( V_2 , V_6 , V_7 , V_9 ,
V_10 , V_11 , type , NULL ) ;
}
void F_18 ( struct V_4 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_19 ( & V_6 -> V_20 ) ;
F_11 ( V_6 -> V_22 ) ;
F_8 ( V_2 , & V_6 -> V_18 ) ;
F_20 ( F_21 ( & V_6 -> V_26 ) ) ;
F_22 ( & V_6 -> V_26 ) ;
V_2 -> V_16 . V_29 -- ;
if ( V_6 -> type == V_30 )
V_2 -> V_16 . V_31 -- ;
F_23 ( V_6 -> V_49 && ! V_6 -> V_9 -> V_50 ) ;
if ( V_6 -> V_49 && V_6 -> V_9 -> V_50 )
V_6 -> V_9 -> V_50 ( V_6 , V_6 -> V_49 ) ;
F_11 ( V_6 -> V_13 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
}
struct V_4 *
F_24 ( struct V_1 * V_2 , int V_51 )
{
struct V_4 * V_6 ;
F_2 (plane, dev)
if ( V_51 == V_6 -> V_28 )
return V_6 ;
return NULL ;
}
void F_25 ( struct V_4 * V_6 )
{
int V_17 ;
if ( ! V_6 -> V_52 )
return;
V_6 -> V_53 = V_6 -> V_52 ;
V_17 = V_6 -> V_9 -> V_54 ( V_6 ) ;
if ( V_17 ) {
F_26 ( L_3 ) ;
V_6 -> V_53 = NULL ;
return;
}
F_27 ( V_6 -> V_53 ) ;
V_6 -> V_53 = NULL ;
V_6 -> V_52 = NULL ;
V_6 -> V_55 = NULL ;
}
int F_28 ( struct V_4 * V_6 ,
struct V_56 * V_57 ,
T_3 V_58 )
{
int V_17 = - V_59 ;
struct V_60 * V_61 = & V_6 -> V_18 ;
if ( V_6 -> V_9 -> V_62 )
V_17 = V_6 -> V_9 -> V_62 ( V_6 , V_57 , V_58 ) ;
if ( ! V_17 )
F_29 ( V_61 , V_57 , V_58 ) ;
return V_17 ;
}
int F_30 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = V_63 ;
struct V_14 * V_15 ;
struct V_4 * V_6 ;
T_1 T_4 * V_68 ;
int V_69 = 0 ;
unsigned V_70 ;
if ( ! F_14 ( V_2 , V_71 ) )
return - V_59 ;
V_15 = & V_2 -> V_16 ;
if ( V_65 -> V_72 )
V_70 = V_15 -> V_29 ;
else
V_70 = V_15 -> V_31 ;
if ( V_70 &&
( V_67 -> V_73 >= V_70 ) ) {
V_68 = ( T_1 T_4 * ) ( unsigned long ) V_67 -> V_74 ;
F_2 (plane, dev) {
if ( V_6 -> type != V_30 &&
! V_65 -> V_72 )
continue;
if ( F_31 ( V_6 -> V_18 . V_75 , V_68 + V_69 ) )
return - V_76 ;
V_69 ++ ;
}
}
V_67 -> V_73 = V_70 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_77 * V_67 = V_63 ;
struct V_4 * V_6 ;
T_1 T_4 * V_78 ;
if ( ! F_14 ( V_2 , V_71 ) )
return - V_59 ;
V_6 = F_33 ( V_2 , V_67 -> V_79 ) ;
if ( ! V_6 )
return - V_80 ;
F_34 ( & V_6 -> V_20 , NULL ) ;
if ( V_6 -> V_55 )
V_67 -> V_81 = V_6 -> V_55 -> V_18 . V_75 ;
else
V_67 -> V_81 = 0 ;
if ( V_6 -> V_52 )
V_67 -> V_82 = V_6 -> V_52 -> V_18 . V_75 ;
else
V_67 -> V_82 = 0 ;
F_35 ( & V_6 -> V_20 ) ;
V_67 -> V_79 = V_6 -> V_18 . V_75 ;
V_67 -> V_7 = V_6 -> V_7 ;
V_67 -> V_83 = 0 ;
if ( V_6 -> V_11 &&
( V_67 -> V_84 >= V_6 -> V_11 ) ) {
V_78 = ( T_1 T_4 * ) ( unsigned long ) V_67 -> V_85 ;
if ( F_36 ( V_78 ,
V_6 -> V_22 ,
sizeof( T_1 ) * V_6 -> V_11 ) ) {
return - V_76 ;
}
}
V_67 -> V_84 = V_6 -> V_11 ;
return 0 ;
}
int F_37 ( const struct V_4 * V_6 , T_5 V_86 )
{
unsigned int V_87 ;
for ( V_87 = 0 ; V_87 < V_6 -> V_11 ; V_87 ++ ) {
if ( V_86 == V_6 -> V_22 [ V_87 ] )
return 0 ;
}
return - V_59 ;
}
static int F_38 ( struct V_4 * V_6 ,
struct V_88 * V_55 ,
struct V_89 * V_52 ,
T_6 V_90 , T_6 V_91 ,
T_1 V_92 , T_1 V_93 ,
T_1 V_94 , T_1 V_95 ,
T_1 V_96 , T_1 V_97 )
{
int V_17 = 0 ;
if ( ! V_52 ) {
V_6 -> V_53 = V_6 -> V_52 ;
V_17 = V_6 -> V_9 -> V_54 ( V_6 ) ;
if ( ! V_17 ) {
V_6 -> V_55 = NULL ;
V_6 -> V_52 = NULL ;
} else {
V_6 -> V_53 = NULL ;
}
goto V_98;
}
if ( ! ( V_6 -> V_7 & F_39 ( V_55 ) ) ) {
F_7 ( L_4 ) ;
V_17 = - V_59 ;
goto V_98;
}
V_17 = F_37 ( V_6 , V_52 -> V_99 ) ;
if ( V_17 ) {
struct V_100 V_101 ;
F_7 ( L_5 ,
F_40 ( V_52 -> V_99 ,
& V_101 ) ) ;
goto V_98;
}
if ( V_92 > V_102 ||
V_90 > V_102 - ( T_6 ) V_92 ||
V_93 > V_102 ||
V_91 > V_102 - ( T_6 ) V_93 ) {
F_7 ( L_6 ,
V_92 , V_93 , V_90 , V_91 ) ;
V_17 = - V_103 ;
goto V_98;
}
V_17 = F_41 ( V_94 , V_95 , V_96 , V_97 , V_52 ) ;
if ( V_17 )
goto V_98;
V_6 -> V_53 = V_6 -> V_52 ;
V_17 = V_6 -> V_9 -> V_104 ( V_6 , V_55 , V_52 ,
V_90 , V_91 , V_92 , V_93 ,
V_94 , V_95 , V_96 , V_97 ) ;
if ( ! V_17 ) {
V_6 -> V_55 = V_55 ;
V_6 -> V_52 = V_52 ;
V_52 = NULL ;
} else {
V_6 -> V_53 = NULL ;
}
V_98:
if ( V_52 )
F_27 ( V_52 ) ;
if ( V_6 -> V_53 )
F_27 ( V_6 -> V_53 ) ;
V_6 -> V_53 = NULL ;
return V_17 ;
}
static int F_42 ( struct V_4 * V_6 ,
struct V_88 * V_55 ,
struct V_89 * V_52 ,
T_6 V_90 , T_6 V_91 ,
T_1 V_92 , T_1 V_93 ,
T_1 V_94 , T_1 V_95 ,
T_1 V_96 , T_1 V_97 )
{
int V_17 ;
F_43 ( V_6 -> V_2 ) ;
V_17 = F_38 ( V_6 , V_55 , V_52 ,
V_90 , V_91 , V_92 , V_93 ,
V_94 , V_95 , V_96 , V_97 ) ;
F_44 ( V_6 -> V_2 ) ;
return V_17 ;
}
int F_45 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_105 * V_106 = V_63 ;
struct V_4 * V_6 ;
struct V_88 * V_55 = NULL ;
struct V_89 * V_52 = NULL ;
if ( ! F_14 ( V_2 , V_71 ) )
return - V_59 ;
V_6 = F_33 ( V_2 , V_106 -> V_79 ) ;
if ( ! V_6 ) {
F_7 ( L_7 ,
V_106 -> V_79 ) ;
return - V_80 ;
}
if ( V_106 -> V_82 ) {
V_52 = F_46 ( V_2 , V_106 -> V_82 ) ;
if ( ! V_52 ) {
F_7 ( L_8 ,
V_106 -> V_82 ) ;
return - V_80 ;
}
V_55 = F_47 ( V_2 , V_106 -> V_81 ) ;
if ( ! V_55 ) {
F_7 ( L_9 ,
V_106 -> V_81 ) ;
return - V_80 ;
}
}
return F_42 ( V_6 , V_55 , V_52 ,
V_106 -> V_90 , V_106 -> V_91 ,
V_106 -> V_92 , V_106 -> V_93 ,
V_106 -> V_94 , V_106 -> V_95 ,
V_106 -> V_96 , V_106 -> V_97 ) ;
}
static int F_48 ( struct V_88 * V_55 ,
struct V_107 * V_108 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_89 * V_52 = NULL ;
struct V_109 V_110 = {
. V_111 = V_108 -> V_111 ,
. V_112 = V_108 -> V_112 ,
. V_99 = V_113 ,
. V_114 = { V_108 -> V_111 * 4 } ,
. V_115 = { V_108 -> V_116 } ,
} ;
T_6 V_90 , V_91 ;
T_1 V_92 = 0 , V_93 = 0 ;
T_1 V_96 = 0 , V_97 = 0 ;
int V_17 = 0 ;
F_20 ( ! V_55 -> V_117 ) ;
F_23 ( V_55 -> V_117 -> V_55 != V_55 && V_55 -> V_117 -> V_55 != NULL ) ;
if ( V_108 -> V_118 & V_119 ) {
if ( V_108 -> V_116 ) {
V_52 = F_49 ( V_2 , & V_110 , V_65 ) ;
if ( F_50 ( V_52 ) ) {
F_7 ( L_10 ) ;
return F_51 ( V_52 ) ;
}
V_52 -> V_120 = V_108 -> V_120 ;
V_52 -> V_121 = V_108 -> V_121 ;
} else {
V_52 = NULL ;
}
} else {
V_52 = V_55 -> V_117 -> V_52 ;
if ( V_52 )
F_52 ( V_52 ) ;
}
if ( V_108 -> V_118 & V_122 ) {
V_90 = V_108 -> V_123 ;
V_91 = V_108 -> V_124 ;
} else {
V_90 = V_55 -> V_125 ;
V_91 = V_55 -> V_126 ;
}
if ( V_52 ) {
V_92 = V_52 -> V_111 ;
V_93 = V_52 -> V_112 ;
V_96 = V_52 -> V_111 << 16 ;
V_97 = V_52 -> V_112 << 16 ;
}
V_17 = F_38 ( V_55 -> V_117 , V_55 , V_52 ,
V_90 , V_91 , V_92 , V_93 ,
0 , 0 , V_96 , V_97 ) ;
if ( V_17 == 0 && V_108 -> V_118 & V_122 ) {
V_55 -> V_125 = V_108 -> V_123 ;
V_55 -> V_126 = V_108 -> V_124 ;
}
return V_17 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
struct V_64 * V_65 )
{
struct V_88 * V_55 ;
int V_17 = 0 ;
if ( ! F_14 ( V_2 , V_71 ) )
return - V_59 ;
if ( ! V_108 -> V_118 || ( ~ V_127 & V_108 -> V_118 ) )
return - V_59 ;
V_55 = F_47 ( V_2 , V_108 -> V_81 ) ;
if ( ! V_55 ) {
F_7 ( L_11 , V_108 -> V_81 ) ;
return - V_80 ;
}
F_54 ( V_55 , V_55 -> V_117 ) ;
if ( V_55 -> V_117 ) {
V_17 = F_48 ( V_55 , V_108 , V_65 ) ;
goto V_98;
}
if ( V_108 -> V_118 & V_119 ) {
if ( ! V_55 -> V_9 -> V_128 && ! V_55 -> V_9 -> V_129 ) {
V_17 = - V_130 ;
goto V_98;
}
if ( V_55 -> V_9 -> V_129 )
V_17 = V_55 -> V_9 -> V_129 ( V_55 , V_65 , V_108 -> V_116 ,
V_108 -> V_111 , V_108 -> V_112 , V_108 -> V_120 , V_108 -> V_121 ) ;
else
V_17 = V_55 -> V_9 -> V_128 ( V_55 , V_65 , V_108 -> V_116 ,
V_108 -> V_111 , V_108 -> V_112 ) ;
}
if ( V_108 -> V_118 & V_122 ) {
if ( V_55 -> V_9 -> V_131 ) {
V_17 = V_55 -> V_9 -> V_131 ( V_55 , V_108 -> V_123 , V_108 -> V_124 ) ;
} else {
V_17 = - V_76 ;
goto V_98;
}
}
V_98:
F_55 ( V_55 ) ;
return V_17 ;
}
int F_56 ( struct V_1 * V_2 ,
void * V_63 , struct V_64 * V_65 )
{
struct V_132 * V_108 = V_63 ;
struct V_107 V_133 ;
memcpy ( & V_133 , V_108 , sizeof( struct V_132 ) ) ;
V_133 . V_120 = V_133 . V_121 = 0 ;
return F_53 ( V_2 , & V_133 , V_65 ) ;
}
int F_57 ( struct V_1 * V_2 ,
void * V_63 , struct V_64 * V_65 )
{
struct V_107 * V_108 = V_63 ;
return F_53 ( V_2 , V_108 , V_65 ) ;
}
int F_58 ( struct V_1 * V_2 ,
void * V_63 , struct V_64 * V_65 )
{
struct V_134 * V_135 = V_63 ;
struct V_88 * V_55 ;
struct V_89 * V_52 = NULL ;
struct V_136 * V_137 = NULL ;
T_5 V_138 = V_135 -> V_139 ;
int V_17 = - V_59 ;
if ( ! F_14 ( V_2 , V_71 ) )
return - V_59 ;
if ( V_135 -> V_118 & ~ V_140 )
return - V_59 ;
if ( V_135 -> V_139 != 0 && ! ( V_135 -> V_118 & V_141 ) )
return - V_59 ;
if ( ( V_135 -> V_118 & V_141 ) == V_141 )
return - V_59 ;
if ( ( V_135 -> V_118 & V_142 ) && ! V_2 -> V_16 . V_143 )
return - V_59 ;
V_55 = F_47 ( V_2 , V_135 -> V_81 ) ;
if ( ! V_55 )
return - V_80 ;
if ( V_55 -> V_9 -> V_144 ) {
T_5 V_145 ;
int V_146 ;
V_146 = F_59 ( V_55 ) ;
if ( V_146 )
return V_146 ;
V_145 = F_60 ( V_55 ) ;
switch ( V_135 -> V_118 & V_141 ) {
case V_147 :
if ( ( int ) ( V_138 - V_145 ) > 1 ) {
F_61 ( L_12
L_13 , V_138 ,
V_145 + 1 ) ;
F_62 ( V_55 ) ;
return - V_59 ;
}
break;
case V_148 :
if ( V_138 != 0 && V_138 != 1 ) {
F_61 ( L_14
L_15 , V_138 ) ;
F_62 ( V_55 ) ;
return - V_59 ;
}
V_138 += V_145 ;
break;
default:
V_138 = V_145 +
! ( V_135 -> V_118 & V_142 ) ;
break;
}
} else if ( V_55 -> V_9 -> V_135 == NULL ||
( V_135 -> V_118 & V_141 ) ) {
return - V_59 ;
}
F_54 ( V_55 , V_55 -> V_149 ) ;
if ( V_55 -> V_149 -> V_52 == NULL ) {
V_17 = - V_150 ;
goto V_98;
}
V_52 = F_46 ( V_2 , V_135 -> V_82 ) ;
if ( ! V_52 ) {
V_17 = - V_80 ;
goto V_98;
}
if ( V_55 -> V_49 ) {
const struct V_151 * V_49 = V_55 -> V_149 -> V_49 ;
V_17 = F_41 ( V_49 -> V_94 ,
V_49 -> V_95 ,
V_49 -> V_96 ,
V_49 -> V_97 ,
V_52 ) ;
} else {
V_17 = F_63 ( V_55 , V_55 -> V_123 , V_55 -> V_124 , & V_55 -> V_152 , V_52 ) ;
}
if ( V_17 )
goto V_98;
if ( V_55 -> V_149 -> V_52 -> V_99 != V_52 -> V_99 ) {
F_7 ( L_16 ) ;
V_17 = - V_59 ;
goto V_98;
}
if ( V_135 -> V_118 & V_153 ) {
V_137 = F_64 ( sizeof *V_137 , V_23 ) ;
if ( ! V_137 ) {
V_17 = - V_24 ;
goto V_98;
}
V_137 -> V_154 . V_18 . type = V_155 ;
V_137 -> V_154 . V_18 . V_156 = sizeof( V_137 -> V_154 ) ;
V_137 -> V_154 . V_157 = V_135 -> V_157 ;
V_17 = F_65 ( V_2 , V_65 , & V_137 -> V_18 , & V_137 -> V_154 . V_18 ) ;
if ( V_17 ) {
F_11 ( V_137 ) ;
goto V_98;
}
}
V_55 -> V_149 -> V_53 = V_55 -> V_149 -> V_52 ;
if ( V_55 -> V_9 -> V_144 )
V_17 = V_55 -> V_9 -> V_144 ( V_55 , V_52 , V_137 ,
V_135 -> V_118 ,
V_138 ) ;
else
V_17 = V_55 -> V_9 -> V_135 ( V_55 , V_52 , V_137 , V_135 -> V_118 ) ;
if ( V_17 ) {
if ( V_135 -> V_118 & V_153 )
F_66 ( V_2 , & V_137 -> V_18 ) ;
V_55 -> V_149 -> V_53 = NULL ;
} else {
V_55 -> V_149 -> V_52 = V_52 ;
V_52 = NULL ;
}
V_98:
if ( V_17 && V_55 -> V_9 -> V_144 )
F_62 ( V_55 ) ;
if ( V_52 )
F_27 ( V_52 ) ;
if ( V_55 -> V_149 -> V_53 )
F_27 ( V_55 -> V_149 -> V_53 ) ;
V_55 -> V_149 -> V_53 = NULL ;
F_55 ( V_55 ) ;
return V_17 ;
}
