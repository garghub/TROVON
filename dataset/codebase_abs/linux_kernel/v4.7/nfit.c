const T_1 * F_1 ( enum V_1 V_2 )
{
return V_3 [ V_2 ] ;
}
static struct V_4 * F_2 (
struct V_5 * V_6 )
{
return F_3 ( V_6 , struct V_4 , V_6 ) ;
}
static struct V_7 * F_4 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
if ( ! V_6 -> V_9
|| strcmp ( V_6 -> V_9 , L_1 ) != 0 )
return NULL ;
return F_5 ( V_8 -> V_10 ) ;
}
static int F_6 ( void * V_11 , unsigned int V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
T_2 V_21 ;
switch ( V_12 ) {
case V_22 :
V_20 = V_11 ;
if ( ( V_20 -> V_23 & 0xffff ) == V_24 )
return - V_25 ;
if ( V_20 -> V_23 & 0xffff )
return - V_26 ;
V_21 = V_27 | V_28 ;
if ( ( V_20 -> V_23 >> 16 & V_21 ) == 0 )
return - V_25 ;
break;
case V_29 :
V_18 = V_11 ;
if ( ( V_18 -> V_23 & 0xffff ) == V_30 )
return - V_31 ;
if ( V_18 -> V_23 & 0xffff )
return - V_26 ;
break;
case V_32 :
V_16 = V_11 ;
if ( V_16 -> V_23 & 0xffff )
return - V_26 ;
if ( V_16 -> V_23 == V_33 )
return 0 ;
if ( V_16 -> V_23 == V_34 )
return - V_31 ;
if ( V_16 -> V_23 == V_35 )
return - V_36 ;
if ( V_16 -> V_23 == V_37 ) {
if ( V_16 -> V_21 & V_38 )
return - V_39 ;
return 0 ;
}
if ( V_16 -> V_23 >> 16 )
return - V_26 ;
break;
case V_40 :
V_14 = V_11 ;
if ( V_14 -> V_23 & 0xffff )
return - V_26 ;
if ( ! V_14 -> V_41 )
return - V_26 ;
if ( V_14 -> V_42 > V_14 -> V_41 )
return V_14 -> V_41 ;
break;
default:
break;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_43 * V_43 , unsigned int V_12 , void * V_11 ,
unsigned int V_44 , int * V_45 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
union V_46 V_47 , V_48 , * V_49 ;
const struct V_50 * V_51 = NULL ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_53 * V_54 = NULL ;
const char * V_55 , * V_56 ;
unsigned long V_57 , V_58 ;
T_3 V_59 ;
unsigned int V_60 ;
const T_1 * V_61 ;
T_4 V_62 ;
int V_63 , V_64 ;
V_60 = V_12 ;
if ( V_12 == V_65 ) {
V_54 = V_11 ;
V_60 = V_54 -> V_66 ;
}
if ( V_43 ) {
struct V_67 * V_67 = F_8 ( V_43 ) ;
struct V_7 * V_68 = V_67 -> V_68 ;
if ( ! V_68 )
return - V_25 ;
if ( V_54 && V_67 -> V_69 != V_54 -> V_70 )
return - V_25 ;
V_56 = F_9 ( V_43 ) ;
V_55 = F_10 ( V_12 ) ;
V_57 = F_11 ( V_43 ) ;
V_58 = V_67 -> V_58 ;
V_51 = F_12 ( V_12 ) ;
V_61 = F_1 ( V_67 -> V_69 ) ;
V_59 = V_68 -> V_59 ;
} else {
struct V_7 * V_68 = F_4 ( V_8 ) ;
V_55 = F_13 ( V_12 ) ;
V_57 = V_6 -> V_57 ;
V_58 = V_57 ;
V_51 = F_14 ( V_12 ) ;
V_61 = F_1 ( V_71 ) ;
V_59 = V_68 -> V_59 ;
V_56 = L_2 ;
}
if ( ! V_51 || ( V_12 && ( V_51 -> V_72 + V_51 -> V_73 == 0 ) ) )
return - V_25 ;
if ( ! F_15 ( V_12 , & V_57 ) || ! F_15 ( V_60 , & V_58 ) )
return - V_25 ;
V_47 . type = V_74 ;
V_47 . V_75 . V_76 = 1 ;
V_47 . V_75 . V_77 = & V_48 ;
V_48 . type = V_78 ;
V_48 . V_79 . V_80 = V_11 ;
V_48 . V_79 . V_42 = 0 ;
for ( V_64 = 0 ; V_64 < V_51 -> V_73 ; V_64 ++ )
V_48 . V_79 . V_42 += F_16 ( V_43 , V_12 , V_51 ,
V_64 , V_11 ) ;
if ( V_54 ) {
V_48 . V_79 . V_80 = ( void * ) & V_54 -> V_81 ;
V_48 . V_79 . V_42 = V_54 -> V_82 ;
}
if ( F_17 ( V_83 ) ) {
F_18 ( V_10 , L_3 ,
V_84 , V_56 , V_12 , V_60 ,
V_48 . V_79 . V_42 ) ;
F_19 ( L_4 , V_85 , 4 , 4 ,
V_48 . V_79 . V_80 ,
F_20 ( T_4 , 256 , V_48 . V_79 . V_42 ) , true ) ;
}
V_49 = F_21 ( V_59 , V_61 , 1 , V_60 , & V_47 ) ;
if ( ! V_49 ) {
F_18 ( V_10 , L_5 , V_84 , V_56 ,
V_55 ) ;
return - V_86 ;
}
if ( V_54 ) {
V_54 -> V_87 = V_49 -> V_79 . V_42 ;
memcpy ( V_54 -> V_81 + V_54 -> V_82 ,
V_49 -> V_79 . V_80 ,
F_22 ( V_54 -> V_87 , V_54 -> V_88 ) ) ;
F_23 ( V_49 ) ;
return 0 ;
}
if ( V_49 -> V_75 . type != V_78 ) {
F_18 ( V_10 , L_6 ,
V_84 , V_56 , V_55 , V_49 -> type ) ;
V_63 = - V_86 ;
goto V_89;
}
if ( F_17 ( V_83 ) ) {
F_18 ( V_10 , L_7 , V_84 ,
V_56 , V_55 , V_49 -> V_79 . V_42 ) ;
F_19 ( V_55 , V_85 , 4 ,
4 , V_49 -> V_79 . V_80 , F_20 ( T_4 , 128 ,
V_49 -> V_79 . V_42 ) , true ) ;
}
for ( V_64 = 0 , V_62 = 0 ; V_64 < V_51 -> V_72 ; V_64 ++ ) {
T_4 V_90 = F_24 ( V_43 , V_12 , V_51 , V_64 , V_11 ,
( T_4 * ) V_49 -> V_79 . V_80 ) ;
if ( V_62 + V_90 > V_49 -> V_79 . V_42 ) {
F_18 ( V_10 , L_8 ,
V_84 , V_56 , V_55 , V_64 ) ;
break;
}
if ( V_48 . V_79 . V_42 + V_62 + V_90 > V_44 ) {
F_18 ( V_10 , L_9 ,
V_84 , V_56 , V_55 , V_64 ) ;
V_63 = - V_91 ;
goto V_89;
}
memcpy ( V_11 + V_48 . V_79 . V_42 + V_62 ,
V_49 -> V_79 . V_80 + V_62 , V_90 ) ;
V_62 += V_90 ;
}
if ( V_62 + V_48 . V_79 . V_42 < V_44 ) {
if ( V_64 >= 1 ) {
V_63 = V_44 - V_62 - V_48 . V_79 . V_42 ;
if ( V_45 )
* V_45 = F_6 ( V_11 , V_12 ) ;
} else {
F_25 ( V_10 , L_10 ,
V_84 , V_56 , V_55 , V_44 ,
V_62 ) ;
V_63 = - V_91 ;
}
} else {
V_63 = 0 ;
if ( V_45 )
* V_45 = F_6 ( V_11 , V_12 ) ;
}
V_89:
F_23 ( V_49 ) ;
return V_63 ;
}
static const char * F_26 ( T_2 type )
{
static const char * V_92 [] = {
[ V_93 ] = L_11 ,
[ V_94 ] = L_12 ,
[ V_95 ] = L_13 ,
[ V_96 ] = L_14 ,
[ V_97 ] = L_15 ,
[ V_98 ] = L_16 ,
[ V_99 ] = L_17 ,
[ V_100 ] = L_18 ,
} ;
if ( type > V_100 )
return L_19 ;
return V_92 [ type ] ;
}
static int F_27 ( struct V_101 * V_102 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_103 ; V_64 ++ )
if ( memcmp ( F_1 ( V_64 ) , V_102 -> V_104 , 16 ) == 0 )
return V_64 ;
return - 1 ;
}
static bool F_28 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_101 * V_102 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_102 ) , V_102 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_108 * V_108 ;
F_29 (nfit_spa, &prev->spas, list) {
if ( memcmp ( V_108 -> V_102 , V_102 , V_42 ) == 0 ) {
F_30 ( & V_108 -> V_109 , & V_8 -> V_110 ) ;
return true ;
}
}
V_108 = F_31 ( V_10 , sizeof( * V_108 ) , V_111 ) ;
if ( ! V_108 )
return false ;
F_32 ( & V_108 -> V_109 ) ;
V_108 -> V_102 = V_102 ;
F_33 ( & V_108 -> V_109 , & V_8 -> V_110 ) ;
F_18 ( V_10 , L_20 , V_84 ,
V_102 -> V_112 ,
F_26 ( F_27 ( V_102 ) ) ) ;
return true ;
}
static bool F_34 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_113 * V_114 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_114 ) , V_114 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_115 * V_115 ;
F_29 (nfit_memdev, &prev->memdevs, list)
if ( memcmp ( V_115 -> V_114 , V_114 , V_42 ) == 0 ) {
F_30 ( & V_115 -> V_109 , & V_8 -> V_116 ) ;
return true ;
}
V_115 = F_31 ( V_10 , sizeof( * V_115 ) , V_111 ) ;
if ( ! V_115 )
return false ;
F_32 ( & V_115 -> V_109 ) ;
V_115 -> V_114 = V_114 ;
F_33 ( & V_115 -> V_109 , & V_8 -> V_116 ) ;
F_18 ( V_10 , L_21 ,
V_84 , V_114 -> V_117 , V_114 -> V_112 ,
V_114 -> V_118 ) ;
return true ;
}
static bool F_35 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_119 * V_120 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_120 ) , V_120 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_121 * V_121 ;
F_29 (nfit_dcr, &prev->dcrs, list)
if ( memcmp ( V_121 -> V_120 , V_120 , V_42 ) == 0 ) {
F_30 ( & V_121 -> V_109 , & V_8 -> V_122 ) ;
return true ;
}
V_121 = F_31 ( V_10 , sizeof( * V_121 ) , V_111 ) ;
if ( ! V_121 )
return false ;
F_32 ( & V_121 -> V_109 ) ;
V_121 -> V_120 = V_120 ;
F_33 ( & V_121 -> V_109 , & V_8 -> V_122 ) ;
F_18 ( V_10 , L_22 , V_84 ,
V_120 -> V_118 , V_120 -> V_123 ) ;
return true ;
}
static bool F_36 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_124 * V_125 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_125 ) , V_125 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_126 * V_126 ;
F_29 (nfit_bdw, &prev->bdws, list)
if ( memcmp ( V_126 -> V_125 , V_125 , V_42 ) == 0 ) {
F_30 ( & V_126 -> V_109 , & V_8 -> V_127 ) ;
return true ;
}
V_126 = F_31 ( V_10 , sizeof( * V_126 ) , V_111 ) ;
if ( ! V_126 )
return false ;
F_32 ( & V_126 -> V_109 ) ;
V_126 -> V_125 = V_125 ;
F_33 ( & V_126 -> V_109 , & V_8 -> V_127 ) ;
F_18 ( V_10 , L_23 , V_84 ,
V_125 -> V_118 , V_125 -> V_123 ) ;
return true ;
}
static bool F_37 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_128 * V_129 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_129 ) , V_129 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_130 * V_130 ;
F_29 (nfit_idt, &prev->idts, list)
if ( memcmp ( V_130 -> V_129 , V_129 , V_42 ) == 0 ) {
F_30 ( & V_130 -> V_109 , & V_8 -> V_131 ) ;
return true ;
}
V_130 = F_31 ( V_10 , sizeof( * V_130 ) , V_111 ) ;
if ( ! V_130 )
return false ;
F_32 ( & V_130 -> V_109 ) ;
V_130 -> V_129 = V_129 ;
F_33 ( & V_130 -> V_109 , & V_8 -> V_131 ) ;
F_18 ( V_10 , L_24 , V_84 ,
V_129 -> V_132 , V_129 -> V_133 ) ;
return true ;
}
static bool F_38 ( struct V_4 * V_8 ,
struct V_105 * V_106 ,
struct V_134 * V_135 )
{
T_5 V_42 = F_20 ( T_5 , sizeof( * V_135 ) , V_135 -> V_107 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_136 * V_136 ;
F_29 (nfit_flush, &prev->flushes, list)
if ( memcmp ( V_136 -> V_135 , V_135 , V_42 ) == 0 ) {
F_30 ( & V_136 -> V_109 , & V_8 -> V_137 ) ;
return true ;
}
V_136 = F_31 ( V_10 , sizeof( * V_136 ) , V_111 ) ;
if ( ! V_136 )
return false ;
F_32 ( & V_136 -> V_109 ) ;
V_136 -> V_135 = V_135 ;
F_33 ( & V_136 -> V_109 , & V_8 -> V_137 ) ;
F_18 ( V_10 , L_25 , V_84 ,
V_135 -> V_117 , V_135 -> V_138 ) ;
return true ;
}
static void * F_39 ( struct V_4 * V_8 ,
struct V_105 * V_106 , void * V_139 , const void * V_140 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_141 * V_142 ;
void * V_143 = F_40 ( - V_144 ) ;
if ( V_139 >= V_140 )
return NULL ;
V_142 = V_139 ;
if ( ! V_142 -> V_42 ) {
F_41 ( V_10 , L_26 ,
V_142 -> type ) ;
return NULL ;
}
switch ( V_142 -> type ) {
case V_145 :
if ( ! F_28 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_146 :
if ( ! F_34 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_147 :
if ( ! F_35 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_148 :
if ( ! F_36 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_149 :
if ( ! F_37 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_150 :
if ( ! F_38 ( V_8 , V_106 , V_139 ) )
return V_143 ;
break;
case V_151 :
F_18 ( V_10 , L_27 , V_84 ) ;
break;
default:
F_25 ( V_10 , L_28 , V_142 -> type ) ;
break;
}
return V_139 + V_142 -> V_42 ;
}
static void F_42 ( struct V_4 * V_8 ,
struct V_67 * V_67 )
{
T_4 V_117 = F_43 ( V_67 ) -> V_117 ;
T_2 V_120 = V_67 -> V_120 -> V_118 ;
struct V_108 * V_108 ;
F_29 (nfit_spa, &acpi_desc->spas, list) {
T_2 V_112 = V_108 -> V_102 -> V_112 ;
int type = F_27 ( V_108 -> V_102 ) ;
struct V_115 * V_115 ;
if ( type != V_96 )
continue;
F_29 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_115 -> V_114 -> V_112 != V_112 )
continue;
if ( V_115 -> V_114 -> V_117 != V_117 )
continue;
if ( V_115 -> V_114 -> V_118 != V_120 )
continue;
V_67 -> V_152 = V_108 -> V_102 ;
return;
}
}
F_18 ( V_8 -> V_10 , L_29 ,
V_67 -> V_153 -> V_112 ) ;
V_67 -> V_125 = NULL ;
}
static void F_44 ( struct V_4 * V_8 ,
struct V_67 * V_67 , struct V_101 * V_102 )
{
T_2 V_120 = F_43 ( V_67 ) -> V_118 ;
struct V_115 * V_115 ;
struct V_136 * V_136 ;
struct V_126 * V_126 ;
struct V_130 * V_130 ;
T_2 V_154 , V_112 ;
F_29 (nfit_bdw, &acpi_desc->bdws, list) {
if ( V_126 -> V_125 -> V_118 != V_120 )
continue;
V_67 -> V_125 = V_126 -> V_125 ;
break;
}
if ( ! V_67 -> V_125 )
return;
F_42 ( V_8 , V_67 ) ;
if ( ! V_67 -> V_152 )
return;
V_112 = V_67 -> V_152 -> V_112 ;
F_29 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_115 -> V_114 -> V_112 != V_112 ||
V_115 -> V_114 -> V_118 != V_120 )
continue;
V_67 -> V_155 = V_115 -> V_114 ;
V_154 = V_115 -> V_114 -> V_132 ;
F_29 (nfit_idt, &acpi_desc->idts, list) {
if ( V_130 -> V_129 -> V_132 != V_154 )
continue;
V_67 -> V_156 = V_130 -> V_129 ;
break;
}
F_29 (nfit_flush, &acpi_desc->flushes, list) {
if ( V_136 -> V_135 -> V_117 !=
V_115 -> V_114 -> V_117 )
continue;
V_67 -> V_136 = V_136 ;
break;
}
break;
}
}
static int F_45 ( struct V_4 * V_8 ,
struct V_101 * V_102 )
{
struct V_67 * V_67 , * V_157 ;
struct V_115 * V_115 ;
int type = F_27 ( V_102 ) ;
switch ( type ) {
case V_95 :
case V_94 :
break;
default:
return 0 ;
}
F_29 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_121 * V_121 ;
T_4 V_117 ;
T_2 V_120 ;
if ( V_115 -> V_114 -> V_112 != V_102 -> V_112 )
continue;
V_157 = NULL ;
V_120 = V_115 -> V_114 -> V_118 ;
V_117 = V_115 -> V_114 -> V_117 ;
F_29 (nfit_mem, &acpi_desc->dimms, list)
if ( F_43 ( V_67 ) -> V_117
== V_117 ) {
V_157 = V_67 ;
break;
}
if ( V_157 )
V_67 = V_157 ;
else {
V_67 = F_31 ( V_8 -> V_10 ,
sizeof( * V_67 ) , V_111 ) ;
if ( ! V_67 )
return - V_144 ;
F_32 ( & V_67 -> V_109 ) ;
V_67 -> V_8 = V_8 ;
F_46 ( & V_67 -> V_109 , & V_8 -> V_158 ) ;
}
F_29 (nfit_dcr, &acpi_desc->dcrs, list) {
if ( V_121 -> V_120 -> V_118 != V_120 )
continue;
if ( ! V_67 -> V_120 )
V_67 -> V_120 = V_121 -> V_120 ;
else if ( V_67 -> V_120 -> V_123 == 0
&& V_121 -> V_120 -> V_123 )
V_67 -> V_120 = V_121 -> V_120 ;
break;
}
if ( V_120 && ! V_67 -> V_120 ) {
F_25 ( V_8 -> V_10 , L_30 ,
V_102 -> V_112 , V_120 ) ;
return - V_159 ;
}
if ( type == V_95 ) {
struct V_130 * V_130 ;
T_2 V_154 ;
V_67 -> V_153 = V_102 ;
V_67 -> V_160 = V_115 -> V_114 ;
V_154 = V_115 -> V_114 -> V_132 ;
F_29 (nfit_idt, &acpi_desc->idts, list) {
if ( V_130 -> V_129 -> V_132 != V_154 )
continue;
V_67 -> V_161 = V_130 -> V_129 ;
break;
}
F_44 ( V_8 , V_67 , V_102 ) ;
} else {
V_67 -> V_162 = V_115 -> V_114 ;
}
}
return 0 ;
}
static int F_47 ( void * V_163 , struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_67 * V_167 = F_3 ( V_165 , F_48 ( * V_167 ) , V_109 ) ;
struct V_67 * V_168 = F_3 ( V_166 , F_48 ( * V_168 ) , V_109 ) ;
T_4 V_169 , V_170 ;
V_169 = F_43 ( V_167 ) -> V_117 ;
V_170 = F_43 ( V_168 ) -> V_117 ;
if ( V_169 < V_170 )
return - 1 ;
else if ( V_169 > V_170 )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_8 )
{
struct V_108 * V_108 ;
F_29 (nfit_spa, &acpi_desc->spas, list) {
int V_63 ;
V_63 = F_45 ( V_8 , V_108 -> V_102 ) ;
if ( V_63 )
return V_63 ;
}
F_50 ( NULL , & V_8 -> V_158 , F_47 ) ;
return 0 ;
}
static T_6 F_51 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_173 * V_173 = F_52 ( V_10 ) ;
struct V_5 * V_6 = F_53 ( V_173 ) ;
struct V_4 * V_8 = F_54 ( V_6 ) ;
return sprintf ( V_11 , L_31 , V_8 -> V_174 . V_175 ) ;
}
static struct V_113 * F_55 ( struct V_52 * V_10 )
{
struct V_43 * V_43 = F_56 ( V_10 ) ;
struct V_67 * V_67 = F_8 ( V_43 ) ;
return F_43 ( V_67 ) ;
}
static struct V_119 * F_57 ( struct V_52 * V_10 )
{
struct V_43 * V_43 = F_56 ( V_10 ) ;
struct V_67 * V_67 = F_8 ( V_43 ) ;
return V_67 -> V_120 ;
}
static T_6 F_58 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_113 * V_114 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_32 , V_114 -> V_117 ) ;
}
static T_6 F_59 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_113 * V_114 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_32 , V_114 -> V_176 ) ;
}
static T_6 F_60 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_61 ( V_120 -> V_177 ) ) ;
}
static T_6 F_62 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_61 ( V_120 -> V_178 ) ) ;
}
static T_6 F_63 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_61 ( V_120 -> V_179 ) ) ;
}
static T_6 F_64 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_61 ( V_120 -> V_180 ) ) ;
}
static T_6 F_65 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 ,
F_61 ( V_120 -> V_181 ) ) ;
}
static T_6 F_66 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_61 ( V_120 -> V_182 ) ) ;
}
static int F_67 ( struct V_43 * V_43 )
{
struct V_67 * V_67 = F_8 ( V_43 ) ;
int V_183 = 0 ;
if ( V_67 -> V_162 )
V_183 ++ ;
if ( V_67 -> V_155 )
V_183 ++ ;
return V_183 ;
}
static T_6 F_68 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_33 , F_69 ( V_120 -> V_184 ) ) ;
}
static T_6 F_70 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
T_4 V_59 ;
T_6 V_63 = - V_91 ;
struct V_67 * V_67 ;
struct V_115 * V_115 ;
struct V_4 * V_8 ;
struct V_43 * V_43 = F_56 ( V_10 ) ;
struct V_119 * V_120 = F_57 ( V_10 ) ;
V_67 = F_8 ( V_43 ) ;
V_8 = V_67 -> V_8 ;
V_59 = F_55 ( V_10 ) -> V_117 ;
F_71 ( & V_8 -> V_185 ) ;
F_29 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_113 * V_114 = V_115 -> V_114 ;
struct V_121 * V_121 ;
if ( V_114 -> V_117 != V_59 )
continue;
F_29 (nfit_dcr, &acpi_desc->dcrs, list) {
if ( V_121 -> V_120 -> V_118 != V_114 -> V_118 )
continue;
if ( V_121 -> V_120 -> V_184 == V_120 -> V_184 )
continue;
V_63 = sprintf ( V_11 , L_33 ,
F_69 ( V_121 -> V_120 -> V_184 ) ) ;
break;
}
if ( V_63 != V_91 )
break;
}
F_72 ( & V_8 -> V_185 ) ;
return V_63 ;
}
static T_6 F_73 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_43 * V_43 = F_56 ( V_10 ) ;
return sprintf ( V_11 , L_31 , F_67 ( V_43 ) ) ;
}
static T_6 F_74 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
return sprintf ( V_11 , L_34 , F_75 ( V_120 -> V_186 ) ) ;
}
static T_6 F_76 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_43 * V_43 = F_56 ( V_10 ) ;
struct V_67 * V_67 = F_8 ( V_43 ) ;
if ( V_67 -> V_69 < 0 )
return - V_91 ;
return sprintf ( V_11 , L_31 , V_67 -> V_69 ) ;
}
static T_6 F_77 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_43 * V_43 = F_56 ( V_10 ) ;
struct V_67 * V_67 = F_8 ( V_43 ) ;
if ( V_67 -> V_69 < 0 )
return - V_91 ;
return sprintf ( V_11 , L_35 , V_67 -> V_58 ) ;
}
static T_6 F_78 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
T_2 V_21 = F_55 ( V_10 ) -> V_21 ;
return sprintf ( V_11 , L_36 ,
V_21 & V_187 ? L_37 : L_38 ,
V_21 & V_188 ? L_39 : L_38 ,
V_21 & V_189 ? L_40 : L_38 ,
V_21 & V_190 ? L_41 : L_38 ,
V_21 & V_191 ? L_42 : L_38 ) ;
}
static T_6 F_79 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_119 * V_120 = F_57 ( V_10 ) ;
if ( V_120 -> V_192 & V_193 )
return sprintf ( V_11 , L_43 ,
F_61 ( V_120 -> V_177 ) ,
V_120 -> V_194 ,
F_61 ( V_120 -> V_195 ) ,
F_75 ( V_120 -> V_186 ) ) ;
else
return sprintf ( V_11 , L_44 ,
F_61 ( V_120 -> V_177 ) ,
F_75 ( V_120 -> V_186 ) ) ;
}
static T_7 F_80 ( struct V_196 * V_197 ,
struct V_198 * V_167 , int V_199 )
{
struct V_52 * V_10 = F_3 ( V_197 , struct V_52 , V_197 ) ;
struct V_43 * V_43 = F_56 ( V_10 ) ;
if ( ! F_57 ( V_10 ) )
return 0 ;
if ( V_167 == & V_200 . V_172 && F_67 ( V_43 ) <= 1 )
return 0 ;
return V_167 -> V_201 ;
}
static struct V_43 * F_81 ( struct V_4 * V_8 ,
T_4 V_117 )
{
struct V_67 * V_67 ;
F_29 (nfit_mem, &acpi_desc->dimms, list)
if ( F_43 ( V_67 ) -> V_117 == V_117 )
return V_67 -> V_43 ;
return NULL ;
}
static int F_82 ( struct V_4 * V_8 ,
struct V_67 * V_67 , T_4 V_117 )
{
struct V_7 * V_68 , * V_202 ;
struct V_52 * V_10 = V_8 -> V_10 ;
unsigned long V_58 ;
const T_1 * V_61 ;
int V_64 ;
V_67 -> V_58 = V_8 -> V_203 ;
V_67 -> V_69 = V_204 ;
V_68 = F_4 ( V_8 ) ;
if ( ! V_68 )
return 0 ;
V_202 = F_83 ( V_68 , V_117 , false ) ;
V_67 -> V_68 = V_202 ;
if ( ! V_202 ) {
F_25 ( V_10 , L_45 ,
V_117 ) ;
return V_205 ? 0 : - V_159 ;
}
for ( V_64 = V_204 ; V_64 <= V_206 ; V_64 ++ )
if ( F_84 ( V_202 -> V_59 , F_1 ( V_64 ) , 1 , 1 ) )
break;
V_67 -> V_69 = V_64 ;
if ( V_67 -> V_69 == V_204 ) {
V_58 = 0x3fe ;
if ( V_207 )
V_58 &= ~ ( 1 << V_208 ) ;
} else if ( V_67 -> V_69 == V_209 )
V_58 = 0x1c3c76 ;
else if ( V_67 -> V_69 == V_206 ) {
V_58 = 0x1fe ;
if ( V_207 )
V_58 &= ~ ( 1 << 8 ) ;
} else {
F_18 ( V_10 , L_46 ) ;
V_67 -> V_69 = - 1 ;
return 0 ;
}
V_61 = F_1 ( V_67 -> V_69 ) ;
F_85 (i, &dsm_mask, BITS_PER_LONG)
if ( F_84 ( V_202 -> V_59 , V_61 , 1 , 1ULL << V_64 ) )
F_86 ( V_64 , & V_67 -> V_58 ) ;
return 0 ;
}
static int F_87 ( struct V_4 * V_8 )
{
struct V_67 * V_67 ;
int V_210 = 0 ;
F_29 (nfit_mem, &acpi_desc->dimms, list) {
unsigned long V_21 = 0 , V_57 ;
struct V_43 * V_43 ;
T_4 V_117 ;
T_2 V_211 ;
int V_63 ;
V_117 = F_43 ( V_67 ) -> V_117 ;
V_43 = F_81 ( V_8 , V_117 ) ;
if ( V_43 ) {
V_210 ++ ;
continue;
}
if ( V_67 -> V_125 && V_67 -> V_162 )
V_21 |= V_212 ;
V_211 = F_43 ( V_67 ) -> V_21 ;
if ( V_211 & V_190 )
V_21 |= V_213 ;
V_63 = F_82 ( V_8 , V_67 , V_117 ) ;
if ( V_63 )
continue;
V_57 = 1UL << V_65 ;
if ( V_67 -> V_69 == V_204 )
V_57 |= V_67 -> V_58 ;
V_43 = F_88 ( V_8 -> V_173 , V_67 ,
V_214 ,
V_21 , V_57 ) ;
if ( ! V_43 )
return - V_144 ;
V_67 -> V_43 = V_43 ;
V_210 ++ ;
if ( ( V_211 & V_215 ) == 0 )
continue;
F_89 ( V_8 -> V_10 , L_47 ,
F_9 ( V_43 ) ,
V_211 & V_187 ? L_48 : L_38 ,
V_211 & V_188 ? L_49 : L_38 ,
V_211 & V_189 ? L_50 : L_38 ,
V_211 & V_190 ? L_51 : L_38 ) ;
}
return F_90 ( V_8 -> V_173 , V_210 ) ;
}
static void F_91 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
const T_1 * V_61 = F_1 ( V_71 ) ;
struct V_7 * V_68 ;
int V_64 ;
V_6 -> V_57 = V_8 -> V_216 ;
V_68 = F_4 ( V_8 ) ;
if ( ! V_68 )
return;
for ( V_64 = V_22 ; V_64 <= V_40 ; V_64 ++ )
if ( F_84 ( V_68 -> V_59 , V_61 , 1 , 1ULL << V_64 ) )
F_86 ( V_64 , & V_6 -> V_57 ) ;
}
static T_6 F_92 ( struct V_52 * V_10 ,
struct V_171 * V_172 , char * V_11 )
{
struct V_217 * V_217 = F_93 ( V_10 ) ;
struct V_108 * V_108 = F_94 ( V_217 ) ;
return sprintf ( V_11 , L_31 , V_108 -> V_102 -> V_112 ) ;
}
static T_5 F_95 ( int V_218 )
{
return sizeof( struct V_219 )
+ V_218 * sizeof( struct V_220 ) ;
}
static int F_96 ( const void * V_221 , const void * V_222 )
{
const struct V_220 * V_223 = V_221 ;
const struct V_220 * V_224 = V_222 ;
return memcmp ( & V_223 -> V_225 , & V_224 -> V_225 ,
sizeof( V_226 ) ) ;
}
static struct V_113 * F_97 (
struct V_4 * V_8 , T_2 V_112 , int V_199 )
{
struct V_115 * V_115 ;
F_29 (nfit_memdev, &acpi_desc->memdevs, list)
if ( V_115 -> V_114 -> V_112 == V_112 )
if ( V_199 -- == 0 )
return V_115 -> V_114 ;
return NULL ;
}
static int F_98 ( struct V_4 * V_8 ,
struct V_227 * V_228 ,
struct V_101 * V_102 )
{
int V_64 , V_229 = F_27 ( V_102 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_230 * V_231 ;
T_2 V_232 = V_228 -> V_218 ;
struct V_219 * V_233 ;
if ( V_229 == V_94 || V_229 == V_93 )
;
else
return 0 ;
V_231 = F_31 ( V_10 , sizeof( * V_231 ) , V_111 ) ;
if ( ! V_231 )
return - V_144 ;
V_233 = F_31 ( V_10 , F_95 ( V_232 ) , V_111 ) ;
if ( ! V_233 )
return - V_144 ;
for ( V_64 = 0 ; V_64 < V_232 ; V_64 ++ ) {
struct V_234 * V_234 = & V_228 -> V_234 [ V_64 ] ;
struct V_220 * V_235 = & V_233 -> V_236 [ V_64 ] ;
struct V_43 * V_43 = V_234 -> V_43 ;
struct V_67 * V_67 = F_8 ( V_43 ) ;
struct V_113 * V_114 = F_97 ( V_8 ,
V_102 -> V_112 , V_64 ) ;
if ( ! V_114 || ! V_67 -> V_120 ) {
F_25 ( V_10 , L_52 , V_84 ) ;
return - V_159 ;
}
V_235 -> V_225 = V_114 -> V_225 ;
V_235 -> V_186 = V_67 -> V_120 -> V_186 ;
}
F_99 ( & V_233 -> V_236 [ 0 ] , V_232 , sizeof( struct V_220 ) ,
F_96 , NULL ) ;
V_231 -> V_237 = F_100 ( V_233 , F_95 ( V_232 ) , 0 ) ;
V_228 -> V_231 = V_231 ;
F_101 ( V_10 , V_233 ) ;
return 0 ;
}
static V_226 F_102 ( V_226 V_62 , struct V_238 * V_239 )
{
struct V_128 * V_129 = V_239 -> V_129 ;
T_4 V_240 , V_241 , V_242 ;
V_226 V_243 , V_244 , V_245 ;
V_243 = F_103 ( V_62 , V_239 -> V_246 , & V_240 ) ;
V_244 = F_103 ( V_243 , V_239 -> V_247 , & V_241 ) ;
V_242 = V_129 -> V_242 [ V_241 ]
* V_239 -> V_246 ;
V_245 = V_244 * V_239 -> V_248 ;
return V_239 -> V_249 + V_242 + V_245 + V_240 ;
}
static void F_104 ( struct V_250 * V_250 )
{
if ( V_250 -> V_251 ) {
F_105 () ;
F_106 ( 1 , V_250 -> V_251 ) ;
F_105 () ;
} else
F_107 () ;
}
static T_4 F_108 ( struct V_250 * V_250 , unsigned int V_252 )
{
struct V_238 * V_239 = & V_250 -> V_239 [ V_253 ] ;
V_226 V_62 = V_250 -> V_254 + V_239 -> V_255 * V_252 ;
if ( V_239 -> V_247 )
V_62 = F_102 ( V_62 , V_239 ) ;
return F_109 ( V_239 -> V_256 . V_257 + V_62 ) ;
}
static void F_110 ( struct V_250 * V_250 , unsigned int V_252 ,
T_8 V_258 , unsigned int V_259 , unsigned int V_260 )
{
V_226 V_12 , V_62 ;
struct V_238 * V_239 = & V_250 -> V_239 [ V_253 ] ;
enum {
V_261 = ( 1ULL << 48 ) - 1 ,
V_262 = 48 ,
V_263 = ( 1ULL << 8 ) - 1 ,
V_264 = 56 ,
};
V_12 = ( V_258 >> V_265 ) & V_261 ;
V_259 = V_259 >> V_265 ;
V_12 |= ( ( V_226 ) V_259 & V_263 ) << V_262 ;
V_12 |= ( ( V_226 ) V_260 ) << V_264 ;
V_62 = V_250 -> V_266 + V_239 -> V_255 * V_252 ;
if ( V_239 -> V_247 )
V_62 = F_102 ( V_62 , V_239 ) ;
F_106 ( V_12 , V_239 -> V_256 . V_257 + V_62 ) ;
F_104 ( V_250 ) ;
if ( V_250 -> V_267 & V_268 )
F_111 ( V_239 -> V_256 . V_257 + V_62 ) ;
}
static int F_112 ( struct V_250 * V_250 ,
T_8 V_258 , void * V_269 , T_5 V_259 , int V_270 ,
unsigned int V_271 )
{
struct V_238 * V_239 = & V_250 -> V_239 [ V_272 ] ;
unsigned int V_273 = 0 ;
V_226 V_249 ;
int V_63 ;
V_249 = V_250 -> V_274 + V_258 % V_275
+ V_271 * V_239 -> V_255 ;
F_110 ( V_250 , V_271 , V_258 , V_259 , V_270 ) ;
while ( V_259 ) {
unsigned int V_276 ;
V_226 V_62 ;
if ( V_239 -> V_247 ) {
T_4 V_242 ;
V_62 = F_102 ( V_249 + V_273 ,
V_239 ) ;
F_103 ( V_62 , V_239 -> V_246 , & V_242 ) ;
V_276 = F_20 ( T_5 , V_259 , V_239 -> V_246 - V_242 ) ;
} else {
V_62 = V_249 + V_250 -> V_274 ;
V_276 = V_259 ;
}
if ( V_270 )
F_113 ( V_239 -> V_256 . V_277 + V_62 ,
V_269 + V_273 , V_276 ) ;
else {
if ( V_250 -> V_267 & V_278 )
F_114 ( ( void V_279 * )
V_239 -> V_256 . V_277 + V_62 , V_276 ) ;
F_115 ( V_269 + V_273 ,
V_239 -> V_256 . V_277 + V_62 , V_276 ) ;
}
V_273 += V_276 ;
V_259 -= V_276 ;
}
if ( V_270 )
F_104 ( V_250 ) ;
V_63 = F_108 ( V_250 , V_271 ) ? - V_26 : 0 ;
return V_63 ;
}
static int F_116 ( struct V_280 * V_281 ,
T_8 V_258 , void * V_269 , V_226 V_259 , int V_270 )
{
struct V_250 * V_250 = F_117 ( V_281 ) ;
struct V_238 * V_239 = & V_250 -> V_239 [ V_272 ] ;
struct V_217 * V_217 = V_250 -> V_217 ;
unsigned int V_271 , V_273 = 0 ;
int V_63 = 0 ;
V_271 = F_118 ( V_217 ) ;
while ( V_259 ) {
V_226 V_276 = F_22 ( V_259 , V_239 -> V_255 ) ;
V_63 = F_112 ( V_250 , V_258 + V_273 ,
V_269 + V_273 , V_276 , V_270 , V_271 ) ;
if ( V_63 )
break;
V_273 += V_276 ;
V_259 -= V_276 ;
}
F_119 ( V_217 , V_271 ) ;
return V_63 ;
}
static void F_120 ( struct V_282 * V_282 )
{
struct V_283 * V_284 = F_121 ( V_282 ) ;
struct V_101 * V_102 = V_284 -> V_102 ;
struct V_4 * V_8 = V_284 -> V_8 ;
F_122 ( ! F_123 ( & V_8 -> V_285 ) ) ;
F_18 ( V_8 -> V_10 , L_53 , V_84 , V_102 -> V_112 ) ;
if ( V_284 -> type == V_286 )
F_124 ( ( void V_279 * ) V_284 -> V_256 . V_277 ) ;
else
F_125 ( V_284 -> V_256 . V_257 ) ;
F_126 ( V_102 -> V_287 , V_102 -> V_42 ) ;
F_127 ( & V_284 -> V_109 ) ;
F_128 ( V_284 ) ;
}
static struct V_283 * F_129 (
struct V_4 * V_8 ,
struct V_101 * V_102 )
{
struct V_283 * V_284 ;
F_122 ( ! F_123 ( & V_8 -> V_285 ) ) ;
F_29 (spa_map, &acpi_desc->spa_maps, list)
if ( V_284 -> V_102 == V_102 )
return V_284 ;
return NULL ;
}
static void F_130 ( struct V_4 * V_8 ,
struct V_101 * V_102 )
{
struct V_283 * V_284 ;
F_71 ( & V_8 -> V_285 ) ;
V_284 = F_129 ( V_8 , V_102 ) ;
if ( V_284 )
F_131 ( & V_284 -> V_282 , F_120 ) ;
F_72 ( & V_8 -> V_285 ) ;
}
static void T_9 * F_132 ( struct V_4 * V_8 ,
struct V_101 * V_102 , enum V_288 type )
{
T_8 V_289 = V_102 -> V_287 ;
T_8 V_199 = V_102 -> V_42 ;
struct V_283 * V_284 ;
struct V_290 * V_291 ;
F_122 ( ! F_123 ( & V_8 -> V_285 ) ) ;
V_284 = F_129 ( V_8 , V_102 ) ;
if ( V_284 ) {
F_133 ( & V_284 -> V_282 ) ;
return V_284 -> V_256 . V_257 ;
}
V_284 = F_134 ( sizeof( * V_284 ) , V_111 ) ;
if ( ! V_284 )
return NULL ;
F_32 ( & V_284 -> V_109 ) ;
V_284 -> V_102 = V_102 ;
F_135 ( & V_284 -> V_282 ) ;
V_284 -> V_8 = V_8 ;
V_291 = F_136 ( V_289 , V_199 , F_137 ( V_8 -> V_10 ) ) ;
if ( ! V_291 )
goto V_292;
V_284 -> type = type ;
if ( type == V_286 )
V_284 -> V_256 . V_277 = ( void V_293 * ) F_138 ( V_289 , V_199 ,
V_294 ) ;
else
V_284 -> V_256 . V_257 = F_139 ( V_289 , V_199 ) ;
if ( ! V_284 -> V_256 . V_257 )
goto V_295;
F_33 ( & V_284 -> V_109 , & V_8 -> V_296 ) ;
return V_284 -> V_256 . V_257 ;
V_295:
F_126 ( V_289 , V_199 ) ;
V_292:
F_128 ( V_284 ) ;
return NULL ;
}
static void T_9 * F_140 ( struct V_4 * V_8 ,
struct V_101 * V_102 , enum V_288 type )
{
void T_9 * V_297 ;
F_71 ( & V_8 -> V_285 ) ;
V_297 = F_132 ( V_8 , V_102 , type ) ;
F_72 ( & V_8 -> V_285 ) ;
return V_297 ;
}
static int F_141 ( struct V_238 * V_239 ,
struct V_128 * V_129 , T_2 V_298 )
{
if ( V_129 ) {
V_239 -> V_247 = V_129 -> V_133 ;
V_239 -> V_246 = V_129 -> V_246 ;
if ( V_298 == 0 )
return - V_91 ;
V_239 -> V_248 = V_239 -> V_247 * V_298
* V_239 -> V_246 ;
}
return 0 ;
}
static int F_142 ( struct V_5 * V_6 ,
struct V_43 * V_43 , struct V_250 * V_250 )
{
struct V_299 V_21 ;
int V_63 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_63 = V_6 -> V_300 ( V_6 , V_43 , V_301 , & V_21 ,
sizeof( V_21 ) , NULL ) ;
if ( V_63 >= 0 && V_21 . V_23 == 0 )
V_250 -> V_267 = V_21 . V_21 ;
else if ( V_63 == - V_25 ) {
V_250 -> V_267 = V_268 | V_278 ;
V_63 = 0 ;
} else
V_63 = - V_91 ;
return V_63 ;
}
static int F_143 ( struct V_173 * V_173 ,
struct V_52 * V_10 )
{
struct V_5 * V_6 = F_53 ( V_173 ) ;
struct V_4 * V_8 = F_54 ( V_6 ) ;
struct V_280 * V_281 = F_144 ( V_10 ) ;
struct V_136 * V_136 ;
struct V_238 * V_239 ;
struct V_250 * V_250 ;
struct V_67 * V_67 ;
struct V_43 * V_43 ;
int V_63 ;
V_43 = F_145 ( V_281 ) ;
V_67 = F_8 ( V_43 ) ;
if ( ! V_67 || ! V_67 -> V_120 || ! V_67 -> V_125 ) {
F_18 ( V_10 , L_54 , V_84 ,
V_67 ? L_38 : L_55 ,
( V_67 && V_67 -> V_120 ) ? L_38 : L_56 ,
( V_67 && V_67 -> V_125 ) ? L_38 : L_57 ) ;
return - V_91 ;
}
V_250 = F_31 ( V_10 , sizeof( * V_250 ) , V_111 ) ;
if ( ! V_250 )
return - V_144 ;
F_146 ( V_281 , V_250 ) ;
V_250 -> V_217 = F_93 ( V_10 ) ;
V_250 -> V_274 = V_67 -> V_125 -> V_62 ;
V_239 = & V_250 -> V_239 [ V_272 ] ;
V_239 -> V_256 . V_257 = F_140 ( V_8 , V_67 -> V_152 ,
V_286 ) ;
if ( ! V_239 -> V_256 . V_257 ) {
F_18 ( V_10 , L_58 , V_84 ,
F_9 ( V_43 ) ) ;
return - V_144 ;
}
V_239 -> V_255 = V_67 -> V_125 -> V_255 ;
V_239 -> V_249 = V_67 -> V_155 -> V_225 ;
V_239 -> V_129 = V_67 -> V_156 ;
V_239 -> V_102 = V_67 -> V_152 ;
V_63 = F_141 ( V_239 , V_67 -> V_156 ,
V_67 -> V_155 -> V_298 ) ;
if ( V_63 ) {
F_18 ( V_10 , L_59 ,
V_84 , F_9 ( V_43 ) ) ;
return V_63 ;
}
V_250 -> V_266 = V_67 -> V_120 -> V_302 ;
V_250 -> V_254 = V_67 -> V_120 -> V_303 ;
V_239 = & V_250 -> V_239 [ V_253 ] ;
V_239 -> V_256 . V_257 = F_140 ( V_8 , V_67 -> V_153 ,
V_304 ) ;
if ( ! V_239 -> V_256 . V_257 ) {
F_18 ( V_10 , L_60 , V_84 ,
F_9 ( V_43 ) ) ;
return - V_144 ;
}
V_239 -> V_255 = V_67 -> V_120 -> V_305 ;
V_239 -> V_249 = V_67 -> V_160 -> V_225 ;
V_239 -> V_129 = V_67 -> V_161 ;
V_239 -> V_102 = V_67 -> V_153 ;
V_63 = F_141 ( V_239 , V_67 -> V_161 ,
V_67 -> V_160 -> V_298 ) ;
if ( V_63 ) {
F_18 ( V_10 , L_61 ,
V_84 , F_9 ( V_43 ) ) ;
return V_63 ;
}
V_63 = F_142 ( V_6 , V_43 , V_250 ) ;
if ( V_63 < 0 ) {
F_18 ( V_10 , L_62 ,
V_84 , F_9 ( V_43 ) ) ;
return V_63 ;
}
V_136 = V_67 -> V_136 ;
if ( V_136 && V_136 -> V_135 -> V_138 != 0 ) {
V_250 -> V_251 = F_147 ( V_10 ,
V_136 -> V_135 -> V_306 [ 0 ] , 8 ) ;
if ( ! V_250 -> V_251 )
return - V_144 ;
}
if ( ! F_148 () && ! V_250 -> V_251 )
F_41 ( V_10 , L_63 ) ;
if ( V_239 -> V_246 == 0 )
return 0 ;
if ( ( T_4 ) V_250 -> V_266 % V_239 -> V_246
+ 8 > V_239 -> V_246 ) {
F_18 ( V_10 , L_64 ) ;
return - V_91 ;
} else if ( ( T_4 ) V_250 -> V_254 % V_239 -> V_246
+ 8 > V_239 -> V_246 ) {
F_18 ( V_10 , L_65 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_149 ( struct V_173 * V_173 ,
struct V_52 * V_10 )
{
struct V_5 * V_6 = F_53 ( V_173 ) ;
struct V_4 * V_8 = F_54 ( V_6 ) ;
struct V_280 * V_281 = F_144 ( V_10 ) ;
struct V_250 * V_250 = F_117 ( V_281 ) ;
int V_64 ;
if ( ! V_250 )
return;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
struct V_238 * V_239 = & V_250 -> V_239 [ V_64 ] ;
if ( V_239 -> V_256 . V_257 )
F_130 ( V_8 , V_239 -> V_102 ) ;
}
F_146 ( V_281 , NULL ) ;
}
static int F_150 ( struct V_4 * V_8 ,
struct V_19 * V_12 , struct V_108 * V_108 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_101 * V_102 = V_108 -> V_102 ;
int V_45 , V_63 ;
V_12 -> V_287 = V_102 -> V_287 ;
V_12 -> V_42 = V_102 -> V_42 ;
V_63 = V_6 -> V_300 ( V_6 , NULL , V_22 , V_12 ,
sizeof( * V_12 ) , & V_45 ) ;
if ( V_63 < 0 )
return V_63 ;
return V_45 ;
}
static int V_18 ( struct V_4 * V_8 , struct V_108 * V_108 )
{
int V_63 ;
int V_45 ;
struct V_17 V_18 ;
struct V_101 * V_102 = V_108 -> V_102 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_287 = V_102 -> V_287 ;
V_18 . V_42 = V_102 -> V_42 ;
if ( F_27 ( V_102 ) == V_94 )
V_18 . type = V_27 ;
else if ( F_27 ( V_102 ) == V_93 )
V_18 . type = V_28 ;
else
return - V_25 ;
V_63 = V_6 -> V_300 ( V_6 , NULL , V_29 , & V_18 ,
sizeof( V_18 ) , & V_45 ) ;
if ( V_63 < 0 )
return V_63 ;
return V_45 ;
}
static int F_151 ( struct V_4 * V_8 )
{
int V_63 , V_45 ;
struct V_17 V_18 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_15 * V_16 = V_8 -> V_16 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_287 = V_16 -> V_307 ;
V_18 . V_42 = V_16 -> V_308 ;
V_18 . type = V_16 -> type ;
V_63 = V_6 -> V_300 ( V_6 , NULL , V_29 , & V_18 ,
sizeof( V_18 ) , & V_45 ) ;
if ( V_63 < 0 )
return V_63 ;
return V_45 ;
}
static int F_152 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_15 * V_16 = V_8 -> V_16 ;
int V_63 , V_45 ;
V_63 = V_6 -> V_300 ( V_6 , NULL , V_32 , V_16 ,
V_8 -> V_309 , & V_45 ) ;
if ( V_63 < 0 )
return V_63 ;
return V_45 ;
}
static int F_153 ( struct V_173 * V_173 ,
struct V_15 * V_16 )
{
int V_63 ;
T_4 V_64 ;
for ( V_64 = 0 ; V_64 < V_16 -> V_310 ; V_64 ++ ) {
V_63 = F_154 ( V_173 ,
V_16 -> V_311 [ V_64 ] . V_312 ,
V_16 -> V_311 [ V_64 ] . V_42 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static void F_155 ( void * V_313 )
{
struct V_290 * V_291 = V_313 ;
F_156 ( V_291 ) ;
}
static int F_157 ( struct V_4 * V_8 ,
struct V_227 * V_228 )
{
struct V_290 * V_291 , * V_314 = V_228 -> V_291 ;
int V_315 , V_316 ;
V_315 = F_158 ( V_314 -> V_289 , F_159 ( V_314 ) ,
V_317 , V_318 ) ;
if ( V_315 == V_319 )
return 0 ;
V_291 = F_31 ( V_8 -> V_10 , sizeof( * V_291 ) , V_111 ) ;
if ( ! V_291 )
return - V_144 ;
V_291 -> V_320 = L_66 ;
V_291 -> V_289 = V_314 -> V_289 ;
V_291 -> V_140 = V_314 -> V_140 ;
V_291 -> V_21 = V_317 ;
V_291 -> V_51 = V_318 ;
V_316 = F_160 ( & V_321 , V_291 ) ;
if ( V_316 )
return V_316 ;
V_316 = F_161 ( V_8 -> V_10 , F_155 , V_291 ) ;
if ( V_316 ) {
F_156 ( V_291 ) ;
return V_316 ;
}
return 0 ;
}
static int F_162 ( struct V_4 * V_8 ,
struct V_234 * V_234 , struct V_227 * V_228 ,
struct V_113 * V_114 ,
struct V_108 * V_108 )
{
struct V_43 * V_43 = F_81 ( V_8 ,
V_114 -> V_117 ) ;
struct V_101 * V_102 = V_108 -> V_102 ;
struct V_322 * V_323 ;
struct V_67 * V_67 ;
int V_324 = 0 ;
if ( ! V_43 ) {
F_25 ( V_8 -> V_10 , L_67 ,
V_102 -> V_112 , V_114 -> V_117 ) ;
return - V_159 ;
}
V_234 -> V_43 = V_43 ;
switch ( F_27 ( V_102 ) ) {
case V_94 :
case V_93 :
V_234 -> V_289 = V_114 -> V_287 ;
V_234 -> V_255 = V_114 -> V_325 ;
break;
case V_95 :
V_67 = F_8 ( V_43 ) ;
if ( ! V_67 || ! V_67 -> V_125 ) {
F_18 ( V_8 -> V_10 , L_68 ,
V_102 -> V_112 , F_9 ( V_43 ) ) ;
} else {
V_234 -> V_255 = V_67 -> V_125 -> V_326 ;
V_234 -> V_289 = V_67 -> V_125 -> V_327 ;
V_228 -> V_328 = V_67 -> V_125 -> V_123 ;
V_324 = 1 ;
}
V_228 -> V_234 = V_234 ;
V_228 -> V_218 = V_324 ;
V_323 = F_163 ( V_228 ) ;
V_323 -> V_329 = F_143 ;
V_323 -> V_330 = F_149 ;
V_323 -> V_331 = V_8 -> V_332 ;
V_108 -> V_217 = F_164 ( V_8 -> V_173 ,
V_228 ) ;
if ( ! V_108 -> V_217 )
return - V_144 ;
break;
}
return 0 ;
}
static int F_165 ( struct V_4 * V_8 ,
struct V_108 * V_108 )
{
static struct V_234 V_333 [ V_334 ] ;
struct V_101 * V_102 = V_108 -> V_102 ;
struct V_322 V_323 ;
struct V_227 * V_228 ;
struct V_115 * V_115 ;
struct V_173 * V_173 ;
struct V_290 V_291 ;
int V_76 = 0 , V_63 ;
if ( V_108 -> V_217 )
return 0 ;
if ( V_102 -> V_112 == 0 ) {
F_18 ( V_8 -> V_10 , L_69 ,
V_84 ) ;
return 0 ;
}
memset ( & V_291 , 0 , sizeof( V_291 ) ) ;
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
V_291 . V_289 = V_102 -> V_287 ;
V_291 . V_140 = V_291 . V_289 + V_102 -> V_42 - 1 ;
V_228 = & V_323 . V_228 ;
V_228 -> V_291 = & V_291 ;
V_228 -> V_335 = V_108 ;
V_228 -> V_336 = V_337 ;
if ( V_102 -> V_21 & V_338 )
V_228 -> V_339 = F_166 (
V_102 -> V_340 ) ;
else
V_228 -> V_339 = V_341 ;
F_29 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_113 * V_114 = V_115 -> V_114 ;
struct V_234 * V_234 ;
if ( V_114 -> V_112 != V_102 -> V_112 )
continue;
if ( V_76 >= V_334 ) {
F_25 ( V_8 -> V_10 , L_70 ,
V_102 -> V_112 , V_334 ) ;
return - V_91 ;
}
V_234 = & V_333 [ V_76 ++ ] ;
V_63 = F_162 ( V_8 , V_234 , V_228 ,
V_114 , V_108 ) ;
if ( V_63 )
goto V_89;
}
V_228 -> V_234 = V_333 ;
V_228 -> V_218 = V_76 ;
V_63 = F_98 ( V_8 , V_228 , V_102 ) ;
if ( V_63 )
goto V_89;
V_173 = V_8 -> V_173 ;
if ( F_27 ( V_102 ) == V_94 ) {
V_63 = F_157 ( V_8 , V_228 ) ;
if ( V_63 ) {
F_41 ( V_8 -> V_10 ,
L_71 ,
V_63 ) ;
goto V_89;
}
V_108 -> V_217 = F_167 ( V_173 ,
V_228 ) ;
if ( ! V_108 -> V_217 )
V_63 = - V_144 ;
} else if ( F_27 ( V_102 ) == V_93 ) {
V_108 -> V_217 = F_168 ( V_173 ,
V_228 ) ;
if ( ! V_108 -> V_217 )
V_63 = - V_144 ;
}
V_89:
if ( V_63 )
F_25 ( V_8 -> V_10 , L_72 ,
V_108 -> V_102 -> V_112 ) ;
return V_63 ;
}
static int F_169 ( struct V_4 * V_8 ,
T_4 V_342 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_15 * V_16 ;
if ( V_8 -> V_16 && V_8 -> V_309 >= V_342 ) {
memset ( V_8 -> V_16 , 0 , V_8 -> V_309 ) ;
return 0 ;
}
if ( V_8 -> V_16 )
F_101 ( V_10 , V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
V_16 = F_31 ( V_10 , V_342 , V_111 ) ;
if ( ! V_16 )
return - V_144 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_309 = V_342 ;
return 0 ;
}
static int F_170 ( struct V_4 * V_8 ,
struct V_108 * V_108 )
{
struct V_101 * V_102 = V_108 -> V_102 ;
int V_63 ;
if ( ! V_108 -> V_342 ) {
struct V_19 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_63 = F_150 ( V_8 , & V_20 , V_108 ) ;
if ( V_63 < 0 )
return V_63 ;
V_108 -> V_342 = V_20 . V_343 ;
V_108 -> V_344 = V_20 . V_344 ;
if ( F_27 ( V_102 ) == V_93 &&
( ( V_20 . V_23 >> 16 ) & V_28 ) == 0 )
return - V_25 ;
else if ( F_27 ( V_102 ) == V_94 &&
( ( V_20 . V_23 >> 16 ) & V_27 ) == 0 )
return - V_25 ;
}
if ( F_169 ( V_8 , V_108 -> V_342 ) )
return - V_144 ;
V_63 = F_152 ( V_8 ) ;
if ( V_63 < 0 && V_63 != - V_39 )
return V_63 ;
if ( F_153 ( V_8 -> V_173 ,
V_8 -> V_16 ) )
return - V_144 ;
return 0 ;
}
static void F_171 ( struct V_4 * V_8 ,
struct V_108 * V_108 )
{
struct V_101 * V_102 = V_108 -> V_102 ;
unsigned int V_345 = V_346 ;
V_226 V_347 = 0 , V_348 = 0 ;
struct V_52 * V_10 = V_8 -> V_10 ;
unsigned int V_349 = V_350 ;
int V_63 ;
if ( V_108 -> V_351 || ! V_108 -> V_217 )
return;
V_63 = V_18 ( V_8 , V_108 ) ;
if ( V_63 < 0 && V_63 != - V_31 )
return;
do {
V_226 V_18 , V_352 ;
if ( V_8 -> V_353 )
break;
V_63 = F_170 ( V_8 , V_108 ) ;
if ( V_63 == - V_25 )
break;
if ( V_63 == - V_31 && ! V_349 ) {
F_41 ( V_10 , L_73 ,
V_102 -> V_112 ) ;
break;
}
if ( V_63 == - V_31 ) {
F_72 ( & V_8 -> V_185 ) ;
F_172 ( 1 ) ;
V_349 -- ;
F_71 ( & V_8 -> V_185 ) ;
continue;
}
if ( V_63 == - V_39 && V_345 -- ) {
if ( ! V_348 ) {
V_348 = V_8 -> V_16 -> V_42 ;
V_347 = V_8 -> V_16 -> V_287 ;
}
V_63 = F_151 ( V_8 ) ;
}
if ( V_63 < 0 ) {
F_41 ( V_10 , L_74 ,
V_102 -> V_112 ) ;
break;
}
if ( V_348 ) {
V_18 = V_347 ;
V_352 = V_348 ;
} else {
V_18 = V_8 -> V_16 -> V_287 ;
V_352 = V_8 -> V_16 -> V_42 ;
}
F_18 ( V_10 , L_75 ,
V_102 -> V_112 , V_18 , V_352 ) ;
F_173 ( V_108 -> V_217 ,
V_354 ) ;
break;
} while ( 1 );
}
static void F_174 ( struct V_355 * V_356 )
{
struct V_52 * V_10 ;
V_226 V_357 = 0 ;
struct V_108 * V_108 ;
V_226 V_358 = 0 ;
bool V_359 = false ;
struct V_4 * V_8 ;
unsigned int V_349 = V_350 ;
unsigned int V_345 = V_346 ;
V_8 = F_3 ( V_356 , F_48 ( * V_8 ) , V_356 ) ;
V_10 = V_8 -> V_10 ;
V_360:
F_71 ( & V_8 -> V_185 ) ;
F_29 (nfit_spa, &acpi_desc->spas, list) {
struct V_15 * V_16 ;
struct V_101 * V_102 ;
V_226 V_18 , V_352 ;
int V_63 ;
if ( V_8 -> V_353 )
break;
if ( V_108 -> V_217 )
continue;
if ( V_359 ) {
V_63 = 0 ;
} else
V_63 = F_170 ( V_8 , V_108 ) ;
if ( V_63 == - V_25 ) {
F_165 ( V_8 , V_108 ) ;
continue;
}
if ( V_63 == - V_31 && ! V_349 ) {
F_41 ( V_10 , L_76 ) ;
break;
} else if ( V_63 == - V_31 ) {
F_72 ( & V_8 -> V_185 ) ;
F_172 ( 1 ) ;
V_349 -- ;
goto V_360;
}
if ( V_63 == - V_39 && V_345 -- ) {
V_16 = V_8 -> V_16 ;
if ( ! V_357 ) {
V_357 = V_16 -> V_42 ;
V_358 = V_16 -> V_287 ;
}
V_63 = F_151 ( V_8 ) ;
if ( V_63 == 0 ) {
F_72 ( & V_8 -> V_185 ) ;
goto V_360;
}
}
if ( V_63 < 0 ) {
break;
}
V_16 = V_8 -> V_16 ;
if ( V_357 ) {
V_18 = V_358 ;
V_352 = V_18 + V_357 ;
} else {
V_18 = V_16 -> V_287 ;
V_352 = V_16 -> V_42 ;
}
V_102 = V_108 -> V_102 ;
if ( ! V_359 ) {
V_359 = true ;
F_18 ( V_10 , L_77 ,
V_18 , V_352 ) ;
}
if ( V_18 <= V_102 -> V_287 && V_18 + V_352
>= V_102 -> V_287 + V_102 -> V_42 )
F_165 ( V_8 , V_108 ) ;
}
F_29 (nfit_spa, &acpi_desc->spas, list) {
if ( V_108 -> V_217 )
V_108 -> V_351 = 1 ;
else
F_165 ( V_8 , V_108 ) ;
}
F_29 (nfit_spa, &acpi_desc->spas, list)
F_171 ( V_8 , V_108 ) ;
F_72 ( & V_8 -> V_185 ) ;
}
static int F_175 ( struct V_4 * V_8 )
{
struct V_108 * V_108 ;
int V_63 ;
F_29 (nfit_spa, &acpi_desc->spas, list)
if ( F_27 ( V_108 -> V_102 ) == V_95 ) {
V_63 = F_165 ( V_8 , V_108 ) ;
if ( V_63 )
return V_63 ;
}
F_176 ( V_361 , & V_8 -> V_356 ) ;
return 0 ;
}
static int F_177 ( struct V_4 * V_8 ,
struct V_105 * V_106 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
if ( ! F_178 ( & V_106 -> V_110 ) ||
! F_178 ( & V_106 -> V_116 ) ||
! F_178 ( & V_106 -> V_122 ) ||
! F_178 ( & V_106 -> V_127 ) ||
! F_178 ( & V_106 -> V_131 ) ||
! F_178 ( & V_106 -> V_137 ) ) {
F_25 ( V_10 , L_78 ) ;
return - V_91 ;
}
return 0 ;
}
int F_179 ( struct V_4 * V_8 , T_10 V_362 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_105 V_106 ;
const void * V_140 ;
T_1 * V_313 ;
int V_63 ;
F_71 ( & V_8 -> V_185 ) ;
F_32 ( & V_106 . V_110 ) ;
F_32 ( & V_106 . V_116 ) ;
F_32 ( & V_106 . V_122 ) ;
F_32 ( & V_106 . V_127 ) ;
F_32 ( & V_106 . V_131 ) ;
F_32 ( & V_106 . V_137 ) ;
F_180 ( & V_106 . V_110 , & V_8 -> V_110 ,
V_8 -> V_110 . V_106 ) ;
F_180 ( & V_106 . V_116 , & V_8 -> V_116 ,
V_8 -> V_116 . V_106 ) ;
F_180 ( & V_106 . V_122 , & V_8 -> V_122 ,
V_8 -> V_122 . V_106 ) ;
F_180 ( & V_106 . V_127 , & V_8 -> V_127 ,
V_8 -> V_127 . V_106 ) ;
F_180 ( & V_106 . V_131 , & V_8 -> V_131 ,
V_8 -> V_131 . V_106 ) ;
F_180 ( & V_106 . V_137 , & V_8 -> V_137 ,
V_8 -> V_137 . V_106 ) ;
V_313 = ( T_1 * ) V_8 -> V_363 ;
V_140 = V_313 + V_362 ;
while ( ! F_181 ( V_313 ) )
V_313 = F_39 ( V_8 , & V_106 , V_313 , V_140 ) ;
if ( F_182 ( V_313 ) ) {
F_18 ( V_10 , L_79 , V_84 ,
F_183 ( V_313 ) ) ;
V_63 = F_183 ( V_313 ) ;
goto V_364;
}
V_63 = F_177 ( V_8 , & V_106 ) ;
if ( V_63 )
goto V_364;
if ( F_49 ( V_8 ) != 0 ) {
V_63 = - V_144 ;
goto V_364;
}
F_91 ( V_8 ) ;
V_63 = F_87 ( V_8 ) ;
if ( V_63 )
goto V_364;
V_63 = F_175 ( V_8 ) ;
V_364:
F_72 ( & V_8 -> V_185 ) ;
return V_63 ;
}
static void F_184 ( struct V_355 * V_356 )
{
struct V_365 * V_135 ;
V_135 = F_3 ( V_356 , F_48 ( * V_135 ) , V_356 ) ;
F_185 ( & V_135 -> V_366 ) ;
}
static int F_186 ( struct V_5 * V_6 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_365 V_135 ;
F_187 ( V_10 ) ;
F_188 ( V_10 ) ;
F_189 ( & V_135 . V_356 , F_184 ) ;
F_190 ( V_135 . V_366 ) ;
F_176 ( V_361 , & V_135 . V_356 ) ;
return F_191 ( & V_135 . V_366 ) ;
}
static int F_192 ( struct V_5 * V_6 ,
struct V_43 * V_43 , unsigned int V_12 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
if ( V_43 )
return 0 ;
if ( V_12 != V_29 )
return 0 ;
if ( F_193 ( & V_8 -> V_356 ) )
return - V_31 ;
return 0 ;
}
void F_194 ( struct V_4 * V_8 , struct V_52 * V_10 )
{
struct V_5 * V_6 ;
F_195 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_332 = F_116 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_9 = L_1 ;
V_6 -> V_300 = F_7 ;
V_6 -> F_184 = F_186 ;
V_6 -> V_367 = F_192 ;
V_6 -> V_336 = V_368 ;
F_32 ( & V_8 -> V_296 ) ;
F_32 ( & V_8 -> V_110 ) ;
F_32 ( & V_8 -> V_122 ) ;
F_32 ( & V_8 -> V_127 ) ;
F_32 ( & V_8 -> V_131 ) ;
F_32 ( & V_8 -> V_137 ) ;
F_32 ( & V_8 -> V_116 ) ;
F_32 ( & V_8 -> V_158 ) ;
F_196 ( & V_8 -> V_285 ) ;
F_196 ( & V_8 -> V_185 ) ;
F_197 ( & V_8 -> V_356 , F_174 ) ;
}
static int F_198 ( struct V_7 * V_68 )
{
struct V_369 V_11 = { V_370 , NULL } ;
struct V_4 * V_8 ;
struct V_52 * V_10 = & V_68 -> V_10 ;
struct V_371 * V_372 ;
T_11 V_23 = V_373 ;
T_10 V_362 ;
int V_63 ;
V_23 = F_199 ( V_374 , 0 , & V_372 , & V_362 ) ;
if ( F_200 ( V_23 ) ) {
F_18 ( V_10 , L_80 ) ;
return 0 ;
}
V_8 = F_31 ( V_10 , sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_144 ;
F_194 ( V_8 , & V_68 -> V_10 ) ;
V_8 -> V_173 = F_201 ( V_10 , & V_8 -> V_6 ) ;
if ( ! V_8 -> V_173 )
return - V_144 ;
V_8 -> V_174 = * V_372 ;
V_8 -> V_363 = ( void * ) V_372 + sizeof( struct V_375 ) ;
V_362 -= sizeof( struct V_375 ) ;
V_23 = F_202 ( V_68 -> V_59 , L_81 , NULL , & V_11 ) ;
if ( F_203 ( V_23 ) && V_11 . V_42 > 0 ) {
union V_46 * V_376 ;
V_376 = V_11 . V_80 ;
if ( V_376 -> type == V_78 ) {
V_8 -> V_363 =
(struct V_141 * ) V_376 -> V_79 . V_80 ;
V_362 = V_376 -> V_79 . V_42 ;
} else
F_18 ( V_10 , L_82 ,
V_84 , ( int ) V_376 -> type ) ;
}
V_63 = F_179 ( V_8 , V_362 ) ;
if ( V_63 ) {
F_204 ( V_8 -> V_173 ) ;
return V_63 ;
}
return 0 ;
}
static int F_205 ( struct V_7 * V_68 )
{
struct V_4 * V_8 = F_206 ( & V_68 -> V_10 ) ;
V_8 -> V_353 = 1 ;
F_207 ( V_361 ) ;
F_204 ( V_8 -> V_173 ) ;
return 0 ;
}
static void F_208 ( struct V_7 * V_68 , T_4 V_377 )
{
struct V_4 * V_8 = F_206 ( & V_68 -> V_10 ) ;
struct V_369 V_11 = { V_370 , NULL } ;
struct V_141 * V_378 ;
union V_46 * V_376 ;
struct V_52 * V_10 = & V_68 -> V_10 ;
T_11 V_23 ;
int V_316 ;
F_18 ( V_10 , L_83 , V_84 , V_377 ) ;
F_187 ( V_10 ) ;
if ( ! V_10 -> V_379 ) {
F_18 ( V_10 , L_84 , V_84 ) ;
goto V_364;
}
if ( ! V_8 ) {
V_8 = F_31 ( V_10 , sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
goto V_364;
F_194 ( V_8 , & V_68 -> V_10 ) ;
V_8 -> V_173 = F_201 ( V_10 , & V_8 -> V_6 ) ;
if ( ! V_8 -> V_173 )
goto V_364;
} else {
F_207 ( V_361 ) ;
}
V_23 = F_202 ( V_68 -> V_59 , L_81 , NULL , & V_11 ) ;
if ( F_200 ( V_23 ) ) {
F_25 ( V_10 , L_85 ) ;
goto V_364;
}
V_378 = V_8 -> V_363 ;
V_376 = V_11 . V_80 ;
if ( V_376 -> type == V_78 ) {
V_8 -> V_363 =
(struct V_141 * ) V_376 -> V_79 . V_80 ;
V_316 = F_179 ( V_8 , V_376 -> V_79 . V_42 ) ;
if ( V_316 ) {
V_8 -> V_363 = V_378 ;
F_25 ( V_10 , L_86 ) ;
}
} else {
F_25 ( V_10 , L_87 ) ;
}
F_128 ( V_11 . V_80 ) ;
V_364:
F_188 ( V_10 ) ;
}
static T_12 int F_209 ( void )
{
F_210 ( sizeof( struct V_375 ) != 40 ) ;
F_210 ( sizeof( struct V_101 ) != 56 ) ;
F_210 ( sizeof( struct V_113 ) != 48 ) ;
F_210 ( sizeof( struct V_128 ) != 20 ) ;
F_210 ( sizeof( struct V_380 ) != 9 ) ;
F_210 ( sizeof( struct V_119 ) != 80 ) ;
F_210 ( sizeof( struct V_124 ) != 40 ) ;
F_211 ( V_381 , V_3 [ V_93 ] ) ;
F_211 ( V_382 , V_3 [ V_94 ] ) ;
F_211 ( V_383 , V_3 [ V_95 ] ) ;
F_211 ( V_384 , V_3 [ V_96 ] ) ;
F_211 ( V_385 , V_3 [ V_97 ] ) ;
F_211 ( V_386 , V_3 [ V_98 ] ) ;
F_211 ( V_387 , V_3 [ V_99 ] ) ;
F_211 ( V_388 , V_3 [ V_100 ] ) ;
F_211 ( V_389 , V_3 [ V_71 ] ) ;
F_211 ( V_390 , V_3 [ V_391 ] ) ;
F_211 ( V_392 , V_3 [ V_393 ] ) ;
F_211 ( V_394 , V_3 [ V_395 ] ) ;
V_361 = F_212 ( L_88 ) ;
if ( ! V_361 )
return - V_144 ;
return F_213 ( & V_396 ) ;
}
static T_13 void F_214 ( void )
{
F_215 ( & V_396 ) ;
F_216 ( V_361 ) ;
}
