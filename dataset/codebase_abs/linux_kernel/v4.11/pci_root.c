static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
int F_3 ( T_1 V_3 )
{
int V_4 ;
struct V_1 * V_5 ;
V_4 = F_4 ( V_3 , & V_5 ) ;
if ( V_4 )
return 0 ;
V_4 = F_5 ( V_5 , V_6 ) ;
if ( V_4 )
return 0 ;
else
return 1 ;
}
static T_2
F_6 ( struct V_7 * V_8 , void * V_9 )
{
struct V_8 * V_10 = V_9 ;
struct V_11 V_12 ;
T_2 V_13 ;
V_13 = F_7 ( V_8 , & V_12 ) ;
if ( F_8 ( V_13 ) )
return V_14 ;
if ( ( V_12 . V_12 . V_15 > 0 ) &&
( V_12 . V_16 == V_17 ) ) {
V_10 -> V_18 = V_12 . V_12 . V_19 ;
V_10 -> V_20 = V_12 . V_12 . V_19 + V_12 . V_12 . V_15 - 1 ;
}
return V_14 ;
}
static T_2 F_9 ( T_1 V_3 ,
struct V_8 * V_10 )
{
T_2 V_13 ;
V_10 -> V_18 = - 1 ;
V_13 =
F_10 ( V_3 , V_21 ,
F_6 , V_10 ) ;
if ( F_8 ( V_13 ) )
return V_13 ;
if ( V_10 -> V_18 == - 1 )
return V_22 ;
return V_14 ;
}
static void F_11 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 ,
struct V_27 * V_28 , int V_29 )
{
char V_30 [ 80 ] ;
int V_31 , V_32 = 0 ;
struct V_27 * V_33 ;
V_30 [ 0 ] = '\0' ;
for ( V_31 = 0 , V_33 = V_28 ; V_31 < V_29 ; V_31 ++ , V_33 ++ )
if ( V_26 & V_33 -> V_34 )
V_32 += snprintf ( V_30 + V_32 , sizeof( V_30 ) - V_32 , L_1 ,
V_32 ? L_2 : L_3 , V_33 -> V_35 ) ;
F_12 ( & V_24 -> V_5 -> V_36 , L_4 , V_25 , V_30 ) ;
}
static void F_13 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 )
{
F_11 ( V_24 , V_25 , V_26 , V_37 ,
F_14 ( V_37 ) ) ;
}
static void F_15 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 )
{
F_11 ( V_24 , V_25 , V_26 , V_38 ,
F_14 ( V_38 ) ) ;
}
static T_2 F_16 ( T_1 V_3 ,
const T_3 * V_39 , T_3 * V_40 )
{
struct V_41 V_42 = {
. V_43 = V_44 ,
. V_45 = 1 ,
. V_46 . V_47 = 12 ,
. V_46 . V_48 = ( void * ) V_39 ,
} ;
T_2 V_13 ;
V_13 = F_17 ( V_3 , & V_42 ) ;
if ( F_18 ( V_13 ) ) {
* V_40 = * ( ( T_3 * ) ( V_42 . V_4 . V_48 + 8 ) ) ;
F_19 ( V_42 . V_4 . V_48 ) ;
}
return V_13 ;
}
static T_2 F_20 ( struct V_23 * V_24 ,
T_3 V_49 ,
T_3 * V_50 )
{
T_2 V_13 ;
T_3 V_51 , V_39 [ 3 ] ;
V_49 &= V_52 ;
V_49 |= V_24 -> V_53 ;
V_39 [ V_54 ] = V_55 ;
V_39 [ V_56 ] = V_49 ;
if ( V_50 ) {
* V_50 &= V_57 ;
V_39 [ V_58 ] = * V_50 | V_24 -> V_59 ;
} else {
V_39 [ V_58 ] = V_24 -> V_59 ;
}
V_13 = F_16 ( V_24 -> V_5 -> V_3 , V_39 , & V_51 ) ;
if ( F_18 ( V_13 ) ) {
V_24 -> V_53 = V_49 ;
if ( V_50 )
* V_50 = V_51 ;
}
return V_13 ;
}
static T_2 F_21 ( struct V_23 * V_24 , T_3 V_60 )
{
T_2 V_13 ;
F_22 ( & V_61 ) ;
V_13 = F_20 ( V_24 , V_60 , NULL ) ;
F_23 ( & V_61 ) ;
return V_13 ;
}
struct V_23 * F_24 ( T_1 V_3 )
{
struct V_23 * V_24 ;
struct V_1 * V_5 ;
if ( F_4 ( V_3 , & V_5 ) ||
F_5 ( V_5 , V_6 ) )
return NULL ;
V_24 = F_25 ( V_5 ) ;
return V_24 ;
}
struct V_62 * F_26 ( T_1 V_3 )
{
int V_36 , V_63 ;
unsigned long long V_64 ;
T_2 V_13 ;
T_1 V_65 ;
struct V_66 * V_67 ;
struct V_62 * V_68 = NULL ;
struct V_69 * V_70 , * V_71 ;
struct V_23 * V_24 ;
F_27 ( V_72 ) ;
V_65 = V_3 ;
while ( ! F_3 ( V_65 ) ) {
V_70 = F_28 ( sizeof( struct V_69 ) , V_73 ) ;
if ( ! V_70 )
goto V_74;
F_29 ( & V_70 -> V_70 ) ;
V_70 -> V_3 = V_65 ;
F_30 ( & V_70 -> V_70 , & V_72 ) ;
V_13 = F_31 ( V_65 , & V_65 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
}
V_24 = F_24 ( V_65 ) ;
if ( ! V_24 )
goto V_74;
V_67 = V_24 -> V_75 ;
F_32 (node, &device_list, node) {
T_1 V_76 = V_70 -> V_3 ;
V_13 = F_33 ( V_76 , L_5 , NULL , & V_64 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
V_36 = ( V_64 >> 16 ) & 0xffff ;
V_63 = V_64 & 0xffff ;
V_68 = F_34 ( V_67 , F_35 ( V_36 , V_63 ) ) ;
if ( ! V_68 || V_76 == V_3 )
break;
V_67 = V_68 -> V_77 ;
F_36 ( V_68 ) ;
if ( ! V_67 ) {
F_37 ( & V_68 -> V_36 , L_6 ) ;
V_68 = NULL ;
break;
}
}
V_74:
F_38 (node, tmp, &device_list, node)
F_19 ( V_70 ) ;
return V_68 ;
}
T_2 F_39 ( T_1 V_3 , T_3 * V_78 , T_3 V_79 )
{
struct V_23 * V_24 ;
T_2 V_13 = V_14 ;
T_3 V_80 , V_39 [ 3 ] ;
if ( ! V_78 )
return V_81 ;
V_80 = * V_78 & V_57 ;
if ( ( V_80 & V_79 ) != V_79 )
return V_82 ;
V_24 = F_24 ( V_3 ) ;
if ( ! V_24 )
return V_83 ;
F_22 ( & V_61 ) ;
* V_78 = V_80 | V_24 -> V_59 ;
if ( ( V_24 -> V_59 & V_80 ) == V_80 )
goto V_74;
while ( * V_78 ) {
V_13 = F_20 ( V_24 , V_24 -> V_53 , V_78 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
if ( V_80 == * V_78 )
break;
F_15 ( V_24 , L_7 ,
V_80 & ~ ( * V_78 ) ) ;
V_80 = * V_78 ;
}
if ( ( V_80 & V_79 ) != V_79 ) {
F_15 ( V_24 , L_8 ,
V_79 & ~ ( V_80 ) ) ;
V_13 = V_84 ;
goto V_74;
}
V_39 [ V_54 ] = 0 ;
V_39 [ V_56 ] = V_24 -> V_53 ;
V_39 [ V_58 ] = V_80 ;
V_13 = F_16 ( V_3 , V_39 , V_78 ) ;
if ( F_18 ( V_13 ) )
V_24 -> V_59 = * V_78 ;
V_74:
F_23 ( & V_61 ) ;
return V_13 ;
}
static void F_40 ( struct V_23 * V_24 , int * V_85 )
{
T_3 V_49 , V_50 , V_86 ;
T_2 V_13 ;
struct V_1 * V_5 = V_24 -> V_5 ;
T_1 V_3 = V_5 -> V_3 ;
if ( F_41 ( V_87 , L_9 ) ) {
V_24 -> V_59 = ~ V_88 ;
F_15 ( V_24 , L_10 ,
V_24 -> V_59 ) ;
return;
}
V_49 = V_89 ;
if ( F_42 () )
V_49 |= V_90 ;
if ( F_43 () )
V_49 |= V_91 | V_92 ;
if ( F_44 () )
V_49 |= V_93 ;
F_13 ( V_24 , L_11 , V_49 ) ;
V_13 = F_21 ( V_24 , V_49 ) ;
if ( F_8 ( V_13 ) ) {
F_12 ( & V_5 -> V_36 , L_12 ,
F_45 ( V_13 ) ) ;
* V_85 = 1 ;
return;
}
if ( V_94 ) {
F_12 ( & V_5 -> V_36 , L_13 ) ;
return;
}
if ( ( V_49 & V_95 ) != V_95 ) {
F_13 ( V_24 , L_14 ,
V_95 ) ;
return;
}
V_50 = V_96
| V_97
| V_88 ;
if ( F_46 () ) {
if ( F_47 () )
F_12 ( & V_5 -> V_36 ,
L_15 ) ;
else
V_50 |= V_98 ;
}
V_86 = V_50 ;
V_13 = F_39 ( V_3 , & V_50 ,
V_96 ) ;
if ( F_18 ( V_13 ) ) {
F_15 ( V_24 , L_16 , V_50 ) ;
if ( V_99 . V_100 & V_101 ) {
F_12 ( & V_5 -> V_36 , L_17 ) ;
* V_85 = 1 ;
}
} else {
F_15 ( V_24 , L_18 , V_86 ) ;
F_15 ( V_24 , L_19 , V_50 ) ;
F_12 ( & V_5 -> V_36 , L_12 ,
F_45 ( V_13 ) ) ;
* V_85 = 1 ;
}
}
static int F_48 ( struct V_1 * V_5 ,
const struct V_102 * V_103 )
{
unsigned long long V_104 , V_75 ;
T_2 V_13 ;
int V_51 ;
struct V_23 * V_24 ;
T_1 V_3 = V_5 -> V_3 ;
int V_85 = 0 ;
bool V_105 = V_106 != V_107 ;
V_24 = F_28 ( sizeof( struct V_23 ) , V_73 ) ;
if ( ! V_24 )
return - V_108 ;
V_104 = 0 ;
V_13 = F_33 ( V_3 , V_109 , NULL ,
& V_104 ) ;
if ( F_8 ( V_13 ) && V_13 != V_110 ) {
F_49 ( & V_5 -> V_36 , L_20 ) ;
V_51 = - V_111 ;
goto V_20;
}
V_24 -> V_112 . V_60 = V_113 ;
V_13 = F_9 ( V_3 , & V_24 -> V_112 ) ;
if ( F_8 ( V_13 ) ) {
V_24 -> V_112 . V_20 = 0xFF ;
F_50 ( & V_5 -> V_36 ,
V_114 L_21 ) ;
V_13 = F_33 ( V_3 , V_115 ,
NULL , & V_75 ) ;
if ( F_18 ( V_13 ) )
V_24 -> V_112 . V_18 = V_75 ;
else if ( V_13 == V_110 )
V_24 -> V_112 . V_18 = 0 ;
else {
F_49 ( & V_5 -> V_36 , L_22 ) ;
V_51 = - V_111 ;
goto V_20;
}
}
V_24 -> V_5 = V_5 ;
V_24 -> V_104 = V_104 & 0xFFFF ;
strcpy ( F_51 ( V_5 ) , V_116 ) ;
strcpy ( F_52 ( V_5 ) , V_117 ) ;
V_5 -> V_118 = V_24 ;
if ( V_105 && F_53 ( V_3 ) ) {
V_51 = - V_119 ;
goto V_20;
}
F_54 ( V_120 L_23 ,
F_51 ( V_5 ) , F_55 ( V_5 ) ,
V_24 -> V_104 , & V_24 -> V_112 ) ;
V_24 -> V_121 = F_56 ( V_3 ) ;
F_40 ( V_24 , & V_85 ) ;
V_24 -> V_75 = F_57 ( V_24 ) ;
if ( ! V_24 -> V_75 ) {
F_49 ( & V_5 -> V_36 ,
L_24 ,
V_24 -> V_104 , ( unsigned int ) V_24 -> V_112 . V_18 ) ;
V_5 -> V_118 = NULL ;
V_51 = - V_111 ;
goto V_122;
}
if ( V_85 )
F_58 () ;
F_59 ( V_5 ) ;
if ( V_5 -> V_123 . V_60 . V_124 )
F_60 ( V_24 -> V_75 -> V_125 , true ) ;
if ( V_105 ) {
F_61 ( V_24 -> V_75 ) ;
F_62 ( V_24 -> V_75 ) ;
F_63 ( V_24 -> V_5 -> V_3 ) ;
}
F_64 () ;
F_65 ( V_24 -> V_75 ) ;
F_66 () ;
return 1 ;
V_122:
if ( V_105 )
F_67 ( V_3 ) ;
V_20:
F_19 ( V_24 ) ;
return V_51 ;
}
static void F_68 ( struct V_1 * V_5 )
{
struct V_23 * V_24 = F_25 ( V_5 ) ;
F_64 () ;
F_69 ( V_24 -> V_75 ) ;
F_70 ( V_24 ) ;
F_60 ( V_24 -> V_75 -> V_125 , false ) ;
F_71 ( V_5 ) ;
F_72 ( V_24 -> V_75 ) ;
F_73 ( F_74 ( V_24 ) ) ;
F_67 ( V_5 -> V_3 ) ;
F_66 () ;
F_19 ( V_24 ) ;
}
static void F_75 ( struct V_5 * V_36 ,
struct V_126 * V_127 ,
unsigned long type )
{
F_27 ( V_128 ) ;
struct V_8 * V_129 , * V_130 , * V_24 = NULL ;
struct V_131 * V_71 , * V_33 , * V_132 ;
F_76 ( ( type & ( V_133 | V_134 ) ) == 0 ) ;
V_24 = ( type & V_133 ) ? & V_135 : & V_136 ;
F_77 ( V_127 , & V_128 ) ;
F_78 (entry, tmp, &list) {
bool free = false ;
T_4 V_20 ;
V_129 = V_33 -> V_10 ;
if ( ! ( V_129 -> V_60 & type ) )
goto V_137;
V_20 = F_79 ( V_129 -> V_20 , V_24 -> V_20 ) ;
if ( V_20 <= V_129 -> V_18 ) {
F_12 ( V_36 , L_25 ,
V_129 ) ;
free = true ;
goto V_137;
} else if ( V_129 -> V_20 != V_20 ) {
F_12 ( V_36 , L_26 ,
V_129 , ( unsigned long long ) V_20 + 1 ,
( unsigned long long ) V_129 -> V_20 ) ;
V_129 -> V_20 = V_20 ;
}
F_80 (entry2, resources) {
V_130 = V_132 -> V_10 ;
if ( ! ( V_130 -> V_60 & type ) )
continue;
if ( F_81 ( V_129 , V_130 ) ) {
V_130 -> V_18 = F_79 ( V_129 -> V_18 , V_130 -> V_18 ) ;
V_130 -> V_20 = F_82 ( V_129 -> V_20 , V_130 -> V_20 ) ;
F_12 ( V_36 , L_27 ,
V_130 , V_129 ) ;
free = true ;
goto V_137;
}
}
V_137:
F_83 ( V_33 ) ;
if ( free )
F_84 ( V_33 ) ;
else
F_85 ( V_33 , V_127 ) ;
}
}
static void F_86 ( struct V_131 * V_33 )
{
#ifdef F_87
struct V_8 * V_10 = V_33 -> V_10 ;
T_4 V_138 = V_10 -> V_18 ;
T_4 V_139 = V_138 - V_33 -> V_140 ;
T_4 V_47 = F_88 ( V_10 ) ;
unsigned long V_141 ;
if ( F_89 ( V_138 , V_47 ) )
goto V_142;
V_141 = F_90 ( V_138 ) ;
if ( V_141 == ( unsigned long ) - 1 )
goto V_142;
V_10 -> V_18 = V_141 ;
V_10 -> V_20 = V_141 + V_47 - 1 ;
V_33 -> V_140 = V_141 - V_139 ;
if ( F_91 ( V_10 , V_138 ) < 0 )
goto V_142;
F_54 ( L_28 , & V_138 , V_10 ) ;
return;
V_142:
V_10 -> V_60 |= V_143 ;
#endif
}
int F_92 ( struct V_144 * V_145 )
{
int V_4 ;
struct V_126 * V_128 = & V_145 -> V_127 ;
struct V_1 * V_5 = V_145 -> V_125 ;
struct V_131 * V_33 , * V_71 ;
unsigned long V_60 ;
V_60 = V_134 | V_133 | V_146 ;
V_4 = F_93 ( V_5 , V_128 ,
V_147 ,
( void * ) V_60 ) ;
if ( V_4 < 0 )
F_50 ( & V_5 -> V_36 ,
L_29 , V_4 ) ;
else if ( V_4 == 0 )
F_37 ( & V_5 -> V_36 ,
L_30 ) ;
else {
F_78 (entry, tmp, list) {
if ( V_33 -> V_10 -> V_60 & V_134 )
F_86 ( V_33 ) ;
if ( V_33 -> V_10 -> V_60 & V_143 )
F_94 ( V_33 ) ;
else
V_33 -> V_10 -> V_148 = V_145 -> V_148 ;
}
F_75 ( & V_5 -> V_36 , V_128 ,
V_133 ) ;
F_75 ( & V_5 -> V_36 , V_128 ,
V_134 ) ;
}
return V_4 ;
}
static void F_95 ( struct V_144 * V_145 )
{
struct V_131 * V_33 , * V_71 ;
struct V_8 * V_10 , * V_149 , * V_24 = NULL ;
F_78 (entry, tmp, &info->resources) {
V_10 = V_33 -> V_10 ;
if ( V_10 -> V_60 & V_133 )
V_24 = & V_135 ;
else if ( V_10 -> V_60 & V_134 )
V_24 = & V_136 ;
else
continue;
if ( V_10 == V_24 )
continue;
V_149 = F_96 ( V_24 , V_10 ) ;
if ( V_149 ) {
F_12 ( & V_145 -> V_125 -> V_36 ,
L_31 ,
V_10 , V_149 -> V_148 , V_149 ) ;
F_94 ( V_33 ) ;
}
}
}
static void F_97 ( struct V_144 * V_145 )
{
struct V_8 * V_10 ;
struct V_131 * V_33 , * V_71 ;
if ( ! V_145 )
return;
F_78 (entry, tmp, &info->resources) {
V_10 = V_33 -> V_10 ;
if ( V_10 -> V_150 &&
( V_10 -> V_60 & ( V_133 | V_134 ) ) )
F_98 ( V_10 ) ;
F_94 ( V_33 ) ;
}
V_145 -> V_151 -> V_152 ( V_145 ) ;
}
static void F_99 ( struct V_153 * V_125 )
{
struct V_8 * V_10 ;
struct V_131 * V_33 ;
F_80 (entry, &bridge->windows) {
V_10 = V_33 -> V_10 ;
if ( V_10 -> V_60 & V_134 )
F_100 ( V_10 ) ;
if ( V_10 -> V_150 &&
( V_10 -> V_60 & ( V_133 | V_134 ) ) )
F_98 ( V_10 ) ;
}
F_97 ( V_125 -> V_154 ) ;
}
struct V_66 * F_101 ( struct V_23 * V_24 ,
struct V_155 * V_151 ,
struct V_144 * V_145 ,
void * V_156 )
{
int V_4 , V_157 = V_24 -> V_112 . V_18 ;
struct V_1 * V_5 = V_24 -> V_5 ;
int V_70 = F_102 ( V_5 -> V_3 ) ;
struct V_66 * V_75 ;
V_145 -> V_24 = V_24 ;
V_145 -> V_125 = V_5 ;
V_145 -> V_151 = V_151 ;
F_29 ( & V_145 -> V_127 ) ;
snprintf ( V_145 -> V_148 , sizeof( V_145 -> V_148 ) , L_32 ,
V_24 -> V_104 , V_157 ) ;
if ( V_151 -> V_158 && V_151 -> V_158 ( V_145 ) )
goto V_159;
if ( V_151 -> V_160 )
V_4 = V_151 -> V_160 ( V_145 ) ;
else
V_4 = F_92 ( V_145 ) ;
if ( V_4 < 0 )
goto V_159;
F_95 ( V_145 ) ;
F_103 ( & V_145 -> V_127 , & V_24 -> V_112 ) ;
V_75 = F_104 ( NULL , V_157 , V_151 -> V_161 ,
V_156 , & V_145 -> V_127 ) ;
if ( ! V_75 )
goto V_159;
F_105 ( V_75 ) ;
F_106 ( F_107 ( V_75 -> V_125 ) ,
F_99 , V_145 ) ;
if ( V_70 != V_162 )
F_108 ( V_163 , & V_75 -> V_36 , L_33 , V_70 ) ;
return V_75 ;
V_159:
F_97 ( V_145 ) ;
return NULL ;
}
void T_5 F_109 ( void )
{
F_110 () ;
if ( V_164 )
return;
F_111 () ;
F_112 ( & V_165 , L_34 ) ;
}
