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
const struct V_46 * V_47 = NULL ;
union V_48 V_49 , V_50 , * V_51 ;
struct V_52 * V_10 = V_8 -> V_10 ;
const char * V_53 , * V_54 ;
unsigned long V_55 ;
T_3 V_56 ;
const T_1 * V_57 ;
T_4 V_58 ;
int V_59 , V_60 ;
if ( V_43 ) {
struct V_61 * V_61 = F_8 ( V_43 ) ;
struct V_7 * V_62 = V_61 -> V_62 ;
if ( ! V_62 )
return - V_25 ;
V_54 = F_9 ( V_43 ) ;
V_53 = F_10 ( V_12 ) ;
V_55 = V_61 -> V_55 ;
V_47 = F_11 ( V_12 ) ;
V_57 = F_1 ( V_63 ) ;
V_56 = V_62 -> V_56 ;
} else {
struct V_7 * V_62 = F_4 ( V_8 ) ;
V_53 = F_12 ( V_12 ) ;
V_55 = V_6 -> V_55 ;
V_47 = F_13 ( V_12 ) ;
V_57 = F_1 ( V_64 ) ;
V_56 = V_62 -> V_56 ;
V_54 = L_2 ;
}
if ( ! V_47 || ( V_12 && ( V_47 -> V_65 + V_47 -> V_66 == 0 ) ) )
return - V_25 ;
if ( ! F_14 ( V_12 , & V_55 ) )
return - V_25 ;
V_49 . type = V_67 ;
V_49 . V_68 . V_69 = 1 ;
V_49 . V_68 . V_70 = & V_50 ;
V_50 . type = V_71 ;
V_50 . V_72 . V_73 = V_11 ;
V_50 . V_72 . V_42 = 0 ;
for ( V_60 = 0 ; V_60 < V_47 -> V_66 ; V_60 ++ )
V_50 . V_72 . V_42 += F_15 ( V_43 , V_12 , V_47 ,
V_60 , V_11 ) ;
if ( F_16 ( V_74 ) ) {
F_17 ( V_10 , L_3 , V_75 ,
V_54 , V_53 , V_50 . V_72 . V_42 ) ;
F_18 ( V_53 , V_76 , 4 ,
4 , V_50 . V_72 . V_73 , F_19 ( T_4 , 128 ,
V_50 . V_72 . V_42 ) , true ) ;
}
V_51 = F_20 ( V_56 , V_57 , 1 , V_12 , & V_49 ) ;
if ( ! V_51 ) {
F_17 ( V_10 , L_4 , V_75 , V_54 ,
V_53 ) ;
return - V_77 ;
}
if ( V_51 -> V_68 . type != V_71 ) {
F_17 ( V_10 , L_5 ,
V_75 , V_54 , V_53 , V_51 -> type ) ;
V_59 = - V_77 ;
goto V_78;
}
if ( F_16 ( V_74 ) ) {
F_17 ( V_10 , L_6 , V_75 ,
V_54 , V_53 , V_51 -> V_72 . V_42 ) ;
F_18 ( V_53 , V_76 , 4 ,
4 , V_51 -> V_72 . V_73 , F_19 ( T_4 , 128 ,
V_51 -> V_72 . V_42 ) , true ) ;
}
for ( V_60 = 0 , V_58 = 0 ; V_60 < V_47 -> V_65 ; V_60 ++ ) {
T_4 V_79 = F_21 ( V_43 , V_12 , V_47 , V_60 , V_11 ,
( T_4 * ) V_51 -> V_72 . V_73 ) ;
if ( V_58 + V_79 > V_51 -> V_72 . V_42 ) {
F_17 ( V_10 , L_7 ,
V_75 , V_54 , V_53 , V_60 ) ;
break;
}
if ( V_50 . V_72 . V_42 + V_58 + V_79 > V_44 ) {
F_17 ( V_10 , L_8 ,
V_75 , V_54 , V_53 , V_60 ) ;
V_59 = - V_80 ;
goto V_78;
}
memcpy ( V_11 + V_50 . V_72 . V_42 + V_58 ,
V_51 -> V_72 . V_73 + V_58 , V_79 ) ;
V_58 += V_79 ;
}
if ( V_58 + V_50 . V_72 . V_42 < V_44 ) {
if ( V_60 >= 1 ) {
V_59 = V_44 - V_58 - V_50 . V_72 . V_42 ;
if ( V_45 )
* V_45 = F_6 ( V_11 , V_12 ) ;
} else {
F_22 ( V_10 , L_9 ,
V_75 , V_54 , V_53 , V_44 ,
V_58 ) ;
V_59 = - V_80 ;
}
} else {
V_59 = 0 ;
if ( V_45 )
* V_45 = F_6 ( V_11 , V_12 ) ;
}
V_78:
F_23 ( V_51 ) ;
return V_59 ;
}
static const char * F_24 ( T_2 type )
{
static const char * V_81 [] = {
[ V_82 ] = L_10 ,
[ V_83 ] = L_11 ,
[ V_84 ] = L_12 ,
[ V_85 ] = L_13 ,
[ V_86 ] = L_14 ,
[ V_87 ] = L_15 ,
[ V_88 ] = L_16 ,
[ V_89 ] = L_17 ,
} ;
if ( type > V_89 )
return L_18 ;
return V_81 [ type ] ;
}
static int F_25 ( struct V_90 * V_91 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_92 ; V_60 ++ )
if ( memcmp ( F_1 ( V_60 ) , V_91 -> V_93 , 16 ) == 0 )
return V_60 ;
return - 1 ;
}
static bool F_26 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_90 * V_91 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_91 ) , V_91 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_97 * V_97 ;
F_27 (nfit_spa, &prev->spas, list) {
if ( memcmp ( V_97 -> V_91 , V_91 , V_42 ) == 0 ) {
F_28 ( & V_97 -> V_98 , & V_8 -> V_99 ) ;
return true ;
}
}
V_97 = F_29 ( V_10 , sizeof( * V_97 ) , V_100 ) ;
if ( ! V_97 )
return false ;
F_30 ( & V_97 -> V_98 ) ;
V_97 -> V_91 = V_91 ;
F_31 ( & V_97 -> V_98 , & V_8 -> V_99 ) ;
F_17 ( V_10 , L_19 , V_75 ,
V_91 -> V_101 ,
F_24 ( F_25 ( V_91 ) ) ) ;
return true ;
}
static bool F_32 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_102 * V_103 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_103 ) , V_103 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_104 * V_104 ;
F_27 (nfit_memdev, &prev->memdevs, list)
if ( memcmp ( V_104 -> V_103 , V_103 , V_42 ) == 0 ) {
F_28 ( & V_104 -> V_98 , & V_8 -> V_105 ) ;
return true ;
}
V_104 = F_29 ( V_10 , sizeof( * V_104 ) , V_100 ) ;
if ( ! V_104 )
return false ;
F_30 ( & V_104 -> V_98 ) ;
V_104 -> V_103 = V_103 ;
F_31 ( & V_104 -> V_98 , & V_8 -> V_105 ) ;
F_17 ( V_10 , L_20 ,
V_75 , V_103 -> V_106 , V_103 -> V_101 ,
V_103 -> V_107 ) ;
return true ;
}
static bool F_33 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_108 * V_109 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_109 ) , V_109 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_110 * V_110 ;
F_27 (nfit_dcr, &prev->dcrs, list)
if ( memcmp ( V_110 -> V_109 , V_109 , V_42 ) == 0 ) {
F_28 ( & V_110 -> V_98 , & V_8 -> V_111 ) ;
return true ;
}
V_110 = F_29 ( V_10 , sizeof( * V_110 ) , V_100 ) ;
if ( ! V_110 )
return false ;
F_30 ( & V_110 -> V_98 ) ;
V_110 -> V_109 = V_109 ;
F_31 ( & V_110 -> V_98 , & V_8 -> V_111 ) ;
F_17 ( V_10 , L_21 , V_75 ,
V_109 -> V_107 , V_109 -> V_112 ) ;
return true ;
}
static bool F_34 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_113 * V_114 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_114 ) , V_114 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_115 * V_115 ;
F_27 (nfit_bdw, &prev->bdws, list)
if ( memcmp ( V_115 -> V_114 , V_114 , V_42 ) == 0 ) {
F_28 ( & V_115 -> V_98 , & V_8 -> V_116 ) ;
return true ;
}
V_115 = F_29 ( V_10 , sizeof( * V_115 ) , V_100 ) ;
if ( ! V_115 )
return false ;
F_30 ( & V_115 -> V_98 ) ;
V_115 -> V_114 = V_114 ;
F_31 ( & V_115 -> V_98 , & V_8 -> V_116 ) ;
F_17 ( V_10 , L_22 , V_75 ,
V_114 -> V_107 , V_114 -> V_112 ) ;
return true ;
}
static bool F_35 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_117 * V_118 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_118 ) , V_118 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_119 * V_119 ;
F_27 (nfit_idt, &prev->idts, list)
if ( memcmp ( V_119 -> V_118 , V_118 , V_42 ) == 0 ) {
F_28 ( & V_119 -> V_98 , & V_8 -> V_120 ) ;
return true ;
}
V_119 = F_29 ( V_10 , sizeof( * V_119 ) , V_100 ) ;
if ( ! V_119 )
return false ;
F_30 ( & V_119 -> V_98 ) ;
V_119 -> V_118 = V_118 ;
F_31 ( & V_119 -> V_98 , & V_8 -> V_120 ) ;
F_17 ( V_10 , L_23 , V_75 ,
V_118 -> V_121 , V_118 -> V_122 ) ;
return true ;
}
static bool F_36 ( struct V_4 * V_8 ,
struct V_94 * V_95 ,
struct V_123 * V_124 )
{
T_5 V_42 = F_19 ( T_5 , sizeof( * V_124 ) , V_124 -> V_96 . V_42 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_125 * V_125 ;
F_27 (nfit_flush, &prev->flushes, list)
if ( memcmp ( V_125 -> V_124 , V_124 , V_42 ) == 0 ) {
F_28 ( & V_125 -> V_98 , & V_8 -> V_126 ) ;
return true ;
}
V_125 = F_29 ( V_10 , sizeof( * V_125 ) , V_100 ) ;
if ( ! V_125 )
return false ;
F_30 ( & V_125 -> V_98 ) ;
V_125 -> V_124 = V_124 ;
F_31 ( & V_125 -> V_98 , & V_8 -> V_126 ) ;
F_17 ( V_10 , L_24 , V_75 ,
V_124 -> V_106 , V_124 -> V_127 ) ;
return true ;
}
static void * F_37 ( struct V_4 * V_8 ,
struct V_94 * V_95 , void * V_128 , const void * V_129 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_130 * V_131 ;
void * V_132 = F_38 ( - V_133 ) ;
if ( V_128 >= V_129 )
return NULL ;
V_131 = V_128 ;
if ( ! V_131 -> V_42 ) {
F_39 ( V_10 , L_25 ,
V_131 -> type ) ;
return NULL ;
}
switch ( V_131 -> type ) {
case V_134 :
if ( ! F_26 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_135 :
if ( ! F_32 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_136 :
if ( ! F_33 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_137 :
if ( ! F_34 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_138 :
if ( ! F_35 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_139 :
if ( ! F_36 ( V_8 , V_95 , V_128 ) )
return V_132 ;
break;
case V_140 :
F_17 ( V_10 , L_26 , V_75 ) ;
break;
default:
F_22 ( V_10 , L_27 , V_131 -> type ) ;
break;
}
return V_128 + V_131 -> V_42 ;
}
static void F_40 ( struct V_4 * V_8 ,
struct V_61 * V_61 )
{
T_4 V_106 = F_41 ( V_61 ) -> V_106 ;
T_2 V_109 = V_61 -> V_109 -> V_107 ;
struct V_97 * V_97 ;
F_27 (nfit_spa, &acpi_desc->spas, list) {
T_2 V_101 = V_97 -> V_91 -> V_101 ;
int type = F_25 ( V_97 -> V_91 ) ;
struct V_104 * V_104 ;
if ( type != V_85 )
continue;
F_27 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_104 -> V_103 -> V_101 != V_101 )
continue;
if ( V_104 -> V_103 -> V_106 != V_106 )
continue;
if ( V_104 -> V_103 -> V_107 != V_109 )
continue;
V_61 -> V_141 = V_97 -> V_91 ;
return;
}
}
F_17 ( V_8 -> V_10 , L_28 ,
V_61 -> V_142 -> V_101 ) ;
V_61 -> V_114 = NULL ;
}
static void F_42 ( struct V_4 * V_8 ,
struct V_61 * V_61 , struct V_90 * V_91 )
{
T_2 V_109 = F_41 ( V_61 ) -> V_107 ;
struct V_104 * V_104 ;
struct V_125 * V_125 ;
struct V_115 * V_115 ;
struct V_119 * V_119 ;
T_2 V_143 , V_101 ;
F_27 (nfit_bdw, &acpi_desc->bdws, list) {
if ( V_115 -> V_114 -> V_107 != V_109 )
continue;
V_61 -> V_114 = V_115 -> V_114 ;
break;
}
if ( ! V_61 -> V_114 )
return;
F_40 ( V_8 , V_61 ) ;
if ( ! V_61 -> V_141 )
return;
V_101 = V_61 -> V_141 -> V_101 ;
F_27 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_104 -> V_103 -> V_101 != V_101 ||
V_104 -> V_103 -> V_107 != V_109 )
continue;
V_61 -> V_144 = V_104 -> V_103 ;
V_143 = V_104 -> V_103 -> V_121 ;
F_27 (nfit_idt, &acpi_desc->idts, list) {
if ( V_119 -> V_118 -> V_121 != V_143 )
continue;
V_61 -> V_145 = V_119 -> V_118 ;
break;
}
F_27 (nfit_flush, &acpi_desc->flushes, list) {
if ( V_125 -> V_124 -> V_106 !=
V_104 -> V_103 -> V_106 )
continue;
V_61 -> V_125 = V_125 ;
break;
}
break;
}
}
static int F_43 ( struct V_4 * V_8 ,
struct V_90 * V_91 )
{
struct V_61 * V_61 , * V_146 ;
struct V_104 * V_104 ;
int type = F_25 ( V_91 ) ;
switch ( type ) {
case V_84 :
case V_83 :
break;
default:
return 0 ;
}
F_27 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_110 * V_110 ;
T_4 V_106 ;
T_2 V_109 ;
if ( V_104 -> V_103 -> V_101 != V_91 -> V_101 )
continue;
V_146 = NULL ;
V_109 = V_104 -> V_103 -> V_107 ;
V_106 = V_104 -> V_103 -> V_106 ;
F_27 (nfit_mem, &acpi_desc->dimms, list)
if ( F_41 ( V_61 ) -> V_106
== V_106 ) {
V_146 = V_61 ;
break;
}
if ( V_146 )
V_61 = V_146 ;
else {
V_61 = F_29 ( V_8 -> V_10 ,
sizeof( * V_61 ) , V_100 ) ;
if ( ! V_61 )
return - V_133 ;
F_30 ( & V_61 -> V_98 ) ;
F_44 ( & V_61 -> V_98 , & V_8 -> V_147 ) ;
}
F_27 (nfit_dcr, &acpi_desc->dcrs, list) {
if ( V_110 -> V_109 -> V_107 != V_109 )
continue;
if ( ! V_61 -> V_109 )
V_61 -> V_109 = V_110 -> V_109 ;
else if ( V_61 -> V_109 -> V_112 == 0
&& V_110 -> V_109 -> V_112 )
V_61 -> V_109 = V_110 -> V_109 ;
break;
}
if ( V_109 && ! V_61 -> V_109 ) {
F_22 ( V_8 -> V_10 , L_29 ,
V_91 -> V_101 , V_109 ) ;
return - V_148 ;
}
if ( type == V_84 ) {
struct V_119 * V_119 ;
T_2 V_143 ;
V_61 -> V_142 = V_91 ;
V_61 -> V_149 = V_104 -> V_103 ;
V_143 = V_104 -> V_103 -> V_121 ;
F_27 (nfit_idt, &acpi_desc->idts, list) {
if ( V_119 -> V_118 -> V_121 != V_143 )
continue;
V_61 -> V_150 = V_119 -> V_118 ;
break;
}
F_42 ( V_8 , V_61 , V_91 ) ;
} else {
V_61 -> V_151 = V_104 -> V_103 ;
}
}
return 0 ;
}
static int F_45 ( void * V_152 , struct V_153 * V_154 , struct V_153 * V_155 )
{
struct V_61 * V_156 = F_3 ( V_154 , F_46 ( * V_156 ) , V_98 ) ;
struct V_61 * V_157 = F_3 ( V_155 , F_46 ( * V_157 ) , V_98 ) ;
T_4 V_158 , V_159 ;
V_158 = F_41 ( V_156 ) -> V_106 ;
V_159 = F_41 ( V_157 ) -> V_106 ;
if ( V_158 < V_159 )
return - 1 ;
else if ( V_158 > V_159 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_8 )
{
struct V_97 * V_97 ;
F_27 (nfit_spa, &acpi_desc->spas, list) {
int V_59 ;
V_59 = F_43 ( V_8 , V_97 -> V_91 ) ;
if ( V_59 )
return V_59 ;
}
F_48 ( NULL , & V_8 -> V_147 , F_45 ) ;
return 0 ;
}
static T_6 F_49 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_162 * V_162 = F_50 ( V_10 ) ;
struct V_5 * V_6 = F_51 ( V_162 ) ;
struct V_4 * V_8 = F_52 ( V_6 ) ;
return sprintf ( V_11 , L_30 , V_8 -> V_163 . V_164 ) ;
}
static struct V_102 * F_53 ( struct V_52 * V_10 )
{
struct V_43 * V_43 = F_54 ( V_10 ) ;
struct V_61 * V_61 = F_8 ( V_43 ) ;
return F_41 ( V_61 ) ;
}
static struct V_108 * F_55 ( struct V_52 * V_10 )
{
struct V_43 * V_43 = F_54 ( V_10 ) ;
struct V_61 * V_61 = F_8 ( V_43 ) ;
return V_61 -> V_109 ;
}
static T_6 F_56 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_102 * V_103 = F_53 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_103 -> V_106 ) ;
}
static T_6 F_57 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_102 * V_103 = F_53 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_103 -> V_165 ) ;
}
static T_6 F_58 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_108 * V_109 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_109 -> V_166 ) ;
}
static T_6 F_59 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_108 * V_109 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_109 -> V_167 ) ;
}
static T_6 F_60 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_108 * V_109 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_109 -> V_168 ) ;
}
static T_6 F_61 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_108 * V_109 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_109 -> V_169 ) ;
}
static T_6 F_62 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_108 * V_109 = F_55 ( V_10 ) ;
return sprintf ( V_11 , L_31 , V_109 -> V_170 ) ;
}
static T_6 F_63 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
T_2 V_21 = F_53 ( V_10 ) -> V_21 ;
return sprintf ( V_11 , L_32 ,
V_21 & V_171 ? L_33 : L_34 ,
V_21 & V_172 ? L_35 : L_34 ,
V_21 & V_173 ? L_36 : L_34 ,
V_21 & V_174 ? L_37 : L_34 ,
V_21 & V_175 ? L_38 : L_34 ) ;
}
static T_7 F_64 ( struct V_176 * V_177 ,
struct V_178 * V_156 , int V_179 )
{
struct V_52 * V_10 = F_3 ( V_177 , struct V_52 , V_177 ) ;
if ( F_55 ( V_10 ) )
return V_156 -> V_180 ;
else
return 0 ;
}
static struct V_43 * F_65 ( struct V_4 * V_8 ,
T_4 V_106 )
{
struct V_61 * V_61 ;
F_27 (nfit_mem, &acpi_desc->dimms, list)
if ( F_41 ( V_61 ) -> V_106 == V_106 )
return V_61 -> V_43 ;
return NULL ;
}
static int F_66 ( struct V_4 * V_8 ,
struct V_61 * V_61 , T_4 V_106 )
{
struct V_7 * V_62 , * V_181 ;
struct V_52 * V_10 = V_8 -> V_10 ;
const T_1 * V_57 = F_1 ( V_63 ) ;
int V_60 ;
V_61 -> V_55 = V_8 -> V_182 ;
V_62 = F_4 ( V_8 ) ;
if ( ! V_62 )
return 0 ;
V_181 = F_67 ( V_62 , V_106 , false ) ;
V_61 -> V_62 = V_181 ;
if ( ! V_181 ) {
F_22 ( V_10 , L_39 ,
V_106 ) ;
return V_183 ? 0 : - V_148 ;
}
for ( V_60 = V_184 ; V_60 <= V_185 ; V_60 ++ )
if ( F_68 ( V_181 -> V_56 , V_57 , 1 , 1ULL << V_60 ) )
F_69 ( V_60 , & V_61 -> V_55 ) ;
return 0 ;
}
static int F_70 ( struct V_4 * V_8 )
{
struct V_61 * V_61 ;
int V_186 = 0 ;
F_27 (nfit_mem, &acpi_desc->dimms, list) {
struct V_43 * V_43 ;
unsigned long V_21 = 0 ;
T_4 V_106 ;
T_2 V_187 ;
int V_59 ;
V_106 = F_41 ( V_61 ) -> V_106 ;
V_43 = F_65 ( V_8 , V_106 ) ;
if ( V_43 ) {
V_186 ++ ;
continue;
}
if ( V_61 -> V_114 && V_61 -> V_151 )
V_21 |= V_188 ;
V_187 = F_41 ( V_61 ) -> V_21 ;
if ( V_187 & V_174 )
V_21 |= V_189 ;
V_59 = F_66 ( V_8 , V_61 , V_106 ) ;
if ( V_59 )
continue;
V_43 = F_71 ( V_8 -> V_162 , V_61 ,
V_190 ,
V_21 , & V_61 -> V_55 ) ;
if ( ! V_43 )
return - V_133 ;
V_61 -> V_43 = V_43 ;
V_186 ++ ;
if ( ( V_187 & V_191 ) == 0 )
continue;
F_72 ( V_8 -> V_10 , L_40 ,
F_9 ( V_43 ) ,
V_187 & V_171 ? L_41 : L_34 ,
V_187 & V_172 ? L_42 : L_34 ,
V_187 & V_173 ? L_43 : L_34 ,
V_187 & V_174 ? L_44 : L_34 ) ;
}
return F_73 ( V_8 -> V_162 , V_186 ) ;
}
static void F_74 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
const T_1 * V_57 = F_1 ( V_64 ) ;
struct V_7 * V_62 ;
int V_60 ;
V_6 -> V_55 = V_8 -> V_192 ;
V_62 = F_4 ( V_8 ) ;
if ( ! V_62 )
return;
for ( V_60 = V_22 ; V_60 <= V_40 ; V_60 ++ )
if ( F_68 ( V_62 -> V_56 , V_57 , 1 , 1ULL << V_60 ) )
F_69 ( V_60 , & V_6 -> V_55 ) ;
}
static T_6 F_75 ( struct V_52 * V_10 ,
struct V_160 * V_161 , char * V_11 )
{
struct V_193 * V_193 = F_76 ( V_10 ) ;
struct V_97 * V_97 = F_77 ( V_193 ) ;
return sprintf ( V_11 , L_30 , V_97 -> V_91 -> V_101 ) ;
}
static T_5 F_78 ( int V_194 )
{
return sizeof( struct V_195 )
+ V_194 * sizeof( struct V_196 ) ;
}
static int F_79 ( const void * V_197 , const void * V_198 )
{
const struct V_196 * V_199 = V_197 ;
const struct V_196 * V_200 = V_198 ;
return memcmp ( & V_199 -> V_201 , & V_200 -> V_201 ,
sizeof( V_202 ) ) ;
}
static struct V_102 * F_80 (
struct V_4 * V_8 , T_2 V_101 , int V_179 )
{
struct V_104 * V_104 ;
F_27 (nfit_memdev, &acpi_desc->memdevs, list)
if ( V_104 -> V_103 -> V_101 == V_101 )
if ( V_179 -- == 0 )
return V_104 -> V_103 ;
return NULL ;
}
static int F_81 ( struct V_4 * V_8 ,
struct V_203 * V_204 ,
struct V_90 * V_91 )
{
int V_60 , V_205 = F_25 ( V_91 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_206 * V_207 ;
T_2 V_208 = V_204 -> V_194 ;
struct V_195 * V_209 ;
if ( V_205 == V_83 || V_205 == V_82 )
;
else
return 0 ;
V_207 = F_29 ( V_10 , sizeof( * V_207 ) , V_100 ) ;
if ( ! V_207 )
return - V_133 ;
V_209 = F_29 ( V_10 , F_78 ( V_208 ) , V_100 ) ;
if ( ! V_209 )
return - V_133 ;
for ( V_60 = 0 ; V_60 < V_208 ; V_60 ++ ) {
struct V_210 * V_210 = & V_204 -> V_210 [ V_60 ] ;
struct V_196 * V_211 = & V_209 -> V_212 [ V_60 ] ;
struct V_43 * V_43 = V_210 -> V_43 ;
struct V_61 * V_61 = F_8 ( V_43 ) ;
struct V_102 * V_103 = F_80 ( V_8 ,
V_91 -> V_101 , V_60 ) ;
if ( ! V_103 || ! V_61 -> V_109 ) {
F_22 ( V_10 , L_45 , V_75 ) ;
return - V_148 ;
}
V_211 -> V_201 = V_103 -> V_201 ;
V_211 -> V_170 = V_61 -> V_109 -> V_170 ;
}
F_82 ( & V_209 -> V_212 [ 0 ] , V_208 , sizeof( struct V_196 ) ,
F_79 , NULL ) ;
V_207 -> V_213 = F_83 ( V_209 , F_78 ( V_208 ) , 0 ) ;
V_204 -> V_207 = V_207 ;
F_84 ( V_10 , V_209 ) ;
return 0 ;
}
static V_202 F_85 ( V_202 V_58 , struct V_214 * V_215 )
{
struct V_117 * V_118 = V_215 -> V_118 ;
T_4 V_216 , V_217 , V_218 ;
V_202 V_219 , V_220 , V_221 ;
V_219 = F_86 ( V_58 , V_215 -> V_222 , & V_216 ) ;
V_220 = F_86 ( V_219 , V_215 -> V_223 , & V_217 ) ;
V_218 = V_118 -> V_218 [ V_217 ]
* V_215 -> V_222 ;
V_221 = V_220 * V_215 -> V_224 ;
return V_215 -> V_225 + V_218 + V_221 + V_216 ;
}
static void F_87 ( struct V_226 * V_226 )
{
if ( V_226 -> V_227 ) {
F_88 () ;
F_89 ( 1 , V_226 -> V_227 ) ;
F_88 () ;
} else
F_90 () ;
}
static T_4 F_91 ( struct V_226 * V_226 , unsigned int V_228 )
{
struct V_214 * V_215 = & V_226 -> V_215 [ V_229 ] ;
V_202 V_58 = V_226 -> V_230 + V_215 -> V_231 * V_228 ;
if ( V_215 -> V_223 )
V_58 = F_85 ( V_58 , V_215 ) ;
return F_92 ( V_215 -> V_232 . V_233 + V_58 ) ;
}
static void F_93 ( struct V_226 * V_226 , unsigned int V_228 ,
T_8 V_234 , unsigned int V_235 , unsigned int V_236 )
{
V_202 V_12 , V_58 ;
struct V_214 * V_215 = & V_226 -> V_215 [ V_229 ] ;
enum {
V_237 = ( 1ULL << 48 ) - 1 ,
V_238 = 48 ,
V_239 = ( 1ULL << 8 ) - 1 ,
V_240 = 56 ,
};
V_12 = ( V_234 >> V_241 ) & V_237 ;
V_235 = V_235 >> V_241 ;
V_12 |= ( ( V_202 ) V_235 & V_239 ) << V_238 ;
V_12 |= ( ( V_202 ) V_236 ) << V_240 ;
V_58 = V_226 -> V_242 + V_215 -> V_231 * V_228 ;
if ( V_215 -> V_223 )
V_58 = F_85 ( V_58 , V_215 ) ;
F_89 ( V_12 , V_215 -> V_232 . V_233 + V_58 ) ;
F_87 ( V_226 ) ;
if ( V_226 -> V_243 & V_244 )
F_94 ( V_215 -> V_232 . V_233 + V_58 ) ;
}
static int F_95 ( struct V_226 * V_226 ,
T_8 V_234 , void * V_245 , T_5 V_235 , int V_246 ,
unsigned int V_247 )
{
struct V_214 * V_215 = & V_226 -> V_215 [ V_248 ] ;
unsigned int V_249 = 0 ;
V_202 V_225 ;
int V_59 ;
V_225 = V_226 -> V_250 + V_234 % V_251
+ V_247 * V_215 -> V_231 ;
F_93 ( V_226 , V_247 , V_234 , V_235 , V_246 ) ;
while ( V_235 ) {
unsigned int V_252 ;
V_202 V_58 ;
if ( V_215 -> V_223 ) {
T_4 V_218 ;
V_58 = F_85 ( V_225 + V_249 ,
V_215 ) ;
F_86 ( V_58 , V_215 -> V_222 , & V_218 ) ;
V_252 = F_19 ( T_5 , V_235 , V_215 -> V_222 - V_218 ) ;
} else {
V_58 = V_225 + V_226 -> V_250 ;
V_252 = V_235 ;
}
if ( V_246 )
F_96 ( V_215 -> V_232 . V_253 + V_58 ,
V_245 + V_249 , V_252 ) ;
else {
if ( V_226 -> V_243 & V_254 )
F_97 ( ( void V_255 * )
V_215 -> V_232 . V_253 + V_58 , V_252 ) ;
F_98 ( V_245 + V_249 ,
V_215 -> V_232 . V_253 + V_58 , V_252 ) ;
}
V_249 += V_252 ;
V_235 -= V_252 ;
}
if ( V_246 )
F_87 ( V_226 ) ;
V_59 = F_91 ( V_226 , V_247 ) ? - V_26 : 0 ;
return V_59 ;
}
static int F_99 ( struct V_256 * V_257 ,
T_8 V_234 , void * V_245 , V_202 V_235 , int V_246 )
{
struct V_226 * V_226 = F_100 ( V_257 ) ;
struct V_214 * V_215 = & V_226 -> V_215 [ V_248 ] ;
struct V_193 * V_193 = V_226 -> V_193 ;
unsigned int V_247 , V_249 = 0 ;
int V_59 = 0 ;
V_247 = F_101 ( V_193 ) ;
while ( V_235 ) {
V_202 V_252 = F_102 ( V_235 , V_215 -> V_231 ) ;
V_59 = F_95 ( V_226 , V_234 + V_249 ,
V_245 + V_249 , V_252 , V_246 , V_247 ) ;
if ( V_59 )
break;
V_249 += V_252 ;
V_235 -= V_252 ;
}
F_103 ( V_193 , V_247 ) ;
return V_59 ;
}
static void F_104 ( struct V_258 * V_258 )
{
struct V_259 * V_260 = F_105 ( V_258 ) ;
struct V_90 * V_91 = V_260 -> V_91 ;
struct V_4 * V_8 = V_260 -> V_8 ;
F_106 ( ! F_107 ( & V_8 -> V_261 ) ) ;
F_17 ( V_8 -> V_10 , L_46 , V_75 , V_91 -> V_101 ) ;
if ( V_260 -> type == V_262 )
F_108 ( ( void V_255 * ) V_260 -> V_232 . V_253 ) ;
else
F_109 ( V_260 -> V_232 . V_233 ) ;
F_110 ( V_91 -> V_263 , V_91 -> V_42 ) ;
F_111 ( & V_260 -> V_98 ) ;
F_112 ( V_260 ) ;
}
static struct V_259 * F_113 (
struct V_4 * V_8 ,
struct V_90 * V_91 )
{
struct V_259 * V_260 ;
F_106 ( ! F_107 ( & V_8 -> V_261 ) ) ;
F_27 (spa_map, &acpi_desc->spa_maps, list)
if ( V_260 -> V_91 == V_91 )
return V_260 ;
return NULL ;
}
static void F_114 ( struct V_4 * V_8 ,
struct V_90 * V_91 )
{
struct V_259 * V_260 ;
F_115 ( & V_8 -> V_261 ) ;
V_260 = F_113 ( V_8 , V_91 ) ;
if ( V_260 )
F_116 ( & V_260 -> V_258 , F_104 ) ;
F_117 ( & V_8 -> V_261 ) ;
}
static void T_9 * F_118 ( struct V_4 * V_8 ,
struct V_90 * V_91 , enum V_264 type )
{
T_8 V_265 = V_91 -> V_263 ;
T_8 V_179 = V_91 -> V_42 ;
struct V_259 * V_260 ;
struct V_266 * V_267 ;
F_106 ( ! F_107 ( & V_8 -> V_261 ) ) ;
V_260 = F_113 ( V_8 , V_91 ) ;
if ( V_260 ) {
F_119 ( & V_260 -> V_258 ) ;
return V_260 -> V_232 . V_233 ;
}
V_260 = F_120 ( sizeof( * V_260 ) , V_100 ) ;
if ( ! V_260 )
return NULL ;
F_30 ( & V_260 -> V_98 ) ;
V_260 -> V_91 = V_91 ;
F_121 ( & V_260 -> V_258 ) ;
V_260 -> V_8 = V_8 ;
V_267 = F_122 ( V_265 , V_179 , F_123 ( V_8 -> V_10 ) ) ;
if ( ! V_267 )
goto V_268;
V_260 -> type = type ;
if ( type == V_262 )
V_260 -> V_232 . V_253 = ( void V_269 * ) F_124 ( V_265 , V_179 ,
V_270 ) ;
else
V_260 -> V_232 . V_233 = F_125 ( V_265 , V_179 ) ;
if ( ! V_260 -> V_232 . V_233 )
goto V_271;
F_31 ( & V_260 -> V_98 , & V_8 -> V_272 ) ;
return V_260 -> V_232 . V_233 ;
V_271:
F_110 ( V_265 , V_179 ) ;
V_268:
F_112 ( V_260 ) ;
return NULL ;
}
static void T_9 * F_126 ( struct V_4 * V_8 ,
struct V_90 * V_91 , enum V_264 type )
{
void T_9 * V_273 ;
F_115 ( & V_8 -> V_261 ) ;
V_273 = F_118 ( V_8 , V_91 , type ) ;
F_117 ( & V_8 -> V_261 ) ;
return V_273 ;
}
static int F_127 ( struct V_214 * V_215 ,
struct V_117 * V_118 , T_2 V_274 )
{
if ( V_118 ) {
V_215 -> V_223 = V_118 -> V_122 ;
V_215 -> V_222 = V_118 -> V_222 ;
if ( V_274 == 0 )
return - V_80 ;
V_215 -> V_224 = V_215 -> V_223 * V_274
* V_215 -> V_222 ;
}
return 0 ;
}
static int F_128 ( struct V_5 * V_6 ,
struct V_43 * V_43 , struct V_226 * V_226 )
{
struct V_275 V_21 ;
int V_59 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_59 = V_6 -> V_276 ( V_6 , V_43 , V_277 , & V_21 ,
sizeof( V_21 ) , NULL ) ;
if ( V_59 >= 0 && V_21 . V_23 == 0 )
V_226 -> V_243 = V_21 . V_21 ;
else if ( V_59 == - V_25 ) {
V_226 -> V_243 = V_244 | V_254 ;
V_59 = 0 ;
} else
V_59 = - V_80 ;
return V_59 ;
}
static int F_129 ( struct V_162 * V_162 ,
struct V_52 * V_10 )
{
struct V_5 * V_6 = F_51 ( V_162 ) ;
struct V_4 * V_8 = F_52 ( V_6 ) ;
struct V_256 * V_257 = F_130 ( V_10 ) ;
struct V_125 * V_125 ;
struct V_214 * V_215 ;
struct V_226 * V_226 ;
struct V_61 * V_61 ;
struct V_43 * V_43 ;
int V_59 ;
V_43 = F_131 ( V_257 ) ;
V_61 = F_8 ( V_43 ) ;
if ( ! V_61 || ! V_61 -> V_109 || ! V_61 -> V_114 ) {
F_17 ( V_10 , L_47 , V_75 ,
V_61 ? L_34 : L_48 ,
( V_61 && V_61 -> V_109 ) ? L_34 : L_49 ,
( V_61 && V_61 -> V_114 ) ? L_34 : L_50 ) ;
return - V_80 ;
}
V_226 = F_29 ( V_10 , sizeof( * V_226 ) , V_100 ) ;
if ( ! V_226 )
return - V_133 ;
F_132 ( V_257 , V_226 ) ;
V_226 -> V_193 = F_76 ( V_10 ) ;
V_226 -> V_250 = V_61 -> V_114 -> V_58 ;
V_215 = & V_226 -> V_215 [ V_248 ] ;
V_215 -> V_232 . V_233 = F_126 ( V_8 , V_61 -> V_141 ,
V_262 ) ;
if ( ! V_215 -> V_232 . V_233 ) {
F_17 ( V_10 , L_51 , V_75 ,
F_9 ( V_43 ) ) ;
return - V_133 ;
}
V_215 -> V_231 = V_61 -> V_114 -> V_231 ;
V_215 -> V_225 = V_61 -> V_144 -> V_201 ;
V_215 -> V_118 = V_61 -> V_145 ;
V_215 -> V_91 = V_61 -> V_141 ;
V_59 = F_127 ( V_215 , V_61 -> V_145 ,
V_61 -> V_144 -> V_274 ) ;
if ( V_59 ) {
F_17 ( V_10 , L_52 ,
V_75 , F_9 ( V_43 ) ) ;
return V_59 ;
}
V_226 -> V_242 = V_61 -> V_109 -> V_278 ;
V_226 -> V_230 = V_61 -> V_109 -> V_279 ;
V_215 = & V_226 -> V_215 [ V_229 ] ;
V_215 -> V_232 . V_233 = F_126 ( V_8 , V_61 -> V_142 ,
V_280 ) ;
if ( ! V_215 -> V_232 . V_233 ) {
F_17 ( V_10 , L_53 , V_75 ,
F_9 ( V_43 ) ) ;
return - V_133 ;
}
V_215 -> V_231 = V_61 -> V_109 -> V_281 ;
V_215 -> V_225 = V_61 -> V_149 -> V_201 ;
V_215 -> V_118 = V_61 -> V_150 ;
V_215 -> V_91 = V_61 -> V_142 ;
V_59 = F_127 ( V_215 , V_61 -> V_150 ,
V_61 -> V_149 -> V_274 ) ;
if ( V_59 ) {
F_17 ( V_10 , L_54 ,
V_75 , F_9 ( V_43 ) ) ;
return V_59 ;
}
V_59 = F_128 ( V_6 , V_43 , V_226 ) ;
if ( V_59 < 0 ) {
F_17 ( V_10 , L_55 ,
V_75 , F_9 ( V_43 ) ) ;
return V_59 ;
}
V_125 = V_61 -> V_125 ;
if ( V_125 && V_125 -> V_124 -> V_127 != 0 ) {
V_226 -> V_227 = F_133 ( V_10 ,
V_125 -> V_124 -> V_282 [ 0 ] , 8 ) ;
if ( ! V_226 -> V_227 )
return - V_133 ;
}
if ( ! F_134 () && ! V_226 -> V_227 )
F_39 ( V_10 , L_56 ) ;
if ( V_215 -> V_222 == 0 )
return 0 ;
if ( ( T_4 ) V_226 -> V_242 % V_215 -> V_222
+ 8 > V_215 -> V_222 ) {
F_17 ( V_10 , L_57 ) ;
return - V_80 ;
} else if ( ( T_4 ) V_226 -> V_230 % V_215 -> V_222
+ 8 > V_215 -> V_222 ) {
F_17 ( V_10 , L_58 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_135 ( struct V_162 * V_162 ,
struct V_52 * V_10 )
{
struct V_5 * V_6 = F_51 ( V_162 ) ;
struct V_4 * V_8 = F_52 ( V_6 ) ;
struct V_256 * V_257 = F_130 ( V_10 ) ;
struct V_226 * V_226 = F_100 ( V_257 ) ;
int V_60 ;
if ( ! V_226 )
return;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
struct V_214 * V_215 = & V_226 -> V_215 [ V_60 ] ;
if ( V_215 -> V_232 . V_233 )
F_114 ( V_8 , V_215 -> V_91 ) ;
}
F_132 ( V_257 , NULL ) ;
}
static int F_136 ( struct V_4 * V_8 ,
struct V_19 * V_12 , struct V_97 * V_97 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_90 * V_91 = V_97 -> V_91 ;
int V_45 , V_59 ;
V_12 -> V_263 = V_91 -> V_263 ;
V_12 -> V_42 = V_91 -> V_42 ;
V_59 = V_6 -> V_276 ( V_6 , NULL , V_22 , V_12 ,
sizeof( * V_12 ) , & V_45 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_45 ;
}
static int V_18 ( struct V_4 * V_8 , struct V_97 * V_97 )
{
int V_59 ;
int V_45 ;
struct V_17 V_18 ;
struct V_90 * V_91 = V_97 -> V_91 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_263 = V_91 -> V_263 ;
V_18 . V_42 = V_91 -> V_42 ;
if ( F_25 ( V_91 ) == V_83 )
V_18 . type = V_27 ;
else if ( F_25 ( V_91 ) == V_82 )
V_18 . type = V_28 ;
else
return - V_25 ;
V_59 = V_6 -> V_276 ( V_6 , NULL , V_29 , & V_18 ,
sizeof( V_18 ) , & V_45 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_45 ;
}
static int F_137 ( struct V_4 * V_8 )
{
int V_59 , V_45 ;
struct V_17 V_18 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_15 * V_16 = V_8 -> V_16 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_263 = V_16 -> V_283 ;
V_18 . V_42 = V_16 -> V_284 ;
V_18 . type = V_16 -> type ;
V_59 = V_6 -> V_276 ( V_6 , NULL , V_29 , & V_18 ,
sizeof( V_18 ) , & V_45 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_45 ;
}
static int F_138 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_15 * V_16 = V_8 -> V_16 ;
int V_59 , V_45 ;
V_59 = V_6 -> V_276 ( V_6 , NULL , V_32 , V_16 ,
V_8 -> V_285 , & V_45 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_45 ;
}
static int F_139 ( struct V_162 * V_162 ,
struct V_15 * V_16 )
{
int V_59 ;
T_4 V_60 ;
for ( V_60 = 0 ; V_60 < V_16 -> V_286 ; V_60 ++ ) {
V_59 = F_140 ( V_162 ,
V_16 -> V_287 [ V_60 ] . V_288 ,
V_16 -> V_287 [ V_60 ] . V_42 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static void F_141 ( void * V_289 )
{
struct V_266 * V_267 = V_289 ;
F_142 ( V_267 ) ;
}
static int F_143 ( struct V_4 * V_8 ,
struct V_203 * V_204 )
{
struct V_266 * V_267 , * V_290 = V_204 -> V_267 ;
int V_291 , V_292 ;
V_291 = F_144 ( V_290 -> V_265 , F_145 ( V_290 ) ,
V_293 , V_294 ) ;
if ( V_291 == V_295 )
return 0 ;
V_267 = F_29 ( V_8 -> V_10 , sizeof( * V_267 ) , V_100 ) ;
if ( ! V_267 )
return - V_133 ;
V_267 -> V_296 = L_59 ;
V_267 -> V_265 = V_290 -> V_265 ;
V_267 -> V_129 = V_290 -> V_129 ;
V_267 -> V_21 = V_293 ;
V_267 -> V_47 = V_294 ;
V_292 = F_146 ( & V_297 , V_267 ) ;
if ( V_292 )
return V_292 ;
V_292 = F_147 ( V_8 -> V_10 , F_141 , V_267 ) ;
if ( V_292 ) {
F_142 ( V_267 ) ;
return V_292 ;
}
return 0 ;
}
static int F_148 ( struct V_4 * V_8 ,
struct V_210 * V_210 , struct V_203 * V_204 ,
struct V_102 * V_103 ,
struct V_97 * V_97 )
{
struct V_43 * V_43 = F_65 ( V_8 ,
V_103 -> V_106 ) ;
struct V_90 * V_91 = V_97 -> V_91 ;
struct V_298 * V_299 ;
struct V_61 * V_61 ;
int V_300 = 0 ;
if ( ! V_43 ) {
F_22 ( V_8 -> V_10 , L_60 ,
V_91 -> V_101 , V_103 -> V_106 ) ;
return - V_148 ;
}
V_210 -> V_43 = V_43 ;
switch ( F_25 ( V_91 ) ) {
case V_83 :
case V_82 :
V_210 -> V_265 = V_103 -> V_263 ;
V_210 -> V_231 = V_103 -> V_301 ;
break;
case V_84 :
V_61 = F_8 ( V_43 ) ;
if ( ! V_61 || ! V_61 -> V_114 ) {
F_17 ( V_8 -> V_10 , L_61 ,
V_91 -> V_101 , F_9 ( V_43 ) ) ;
} else {
V_210 -> V_231 = V_61 -> V_114 -> V_302 ;
V_210 -> V_265 = V_61 -> V_114 -> V_303 ;
V_204 -> V_304 = V_61 -> V_114 -> V_112 ;
V_300 = 1 ;
}
V_204 -> V_210 = V_210 ;
V_204 -> V_194 = V_300 ;
V_299 = F_149 ( V_204 ) ;
V_299 -> V_305 = F_129 ;
V_299 -> V_306 = F_135 ;
V_299 -> V_307 = V_8 -> V_308 ;
V_97 -> V_193 = F_150 ( V_8 -> V_162 ,
V_204 ) ;
if ( ! V_97 -> V_193 )
return - V_133 ;
break;
}
return 0 ;
}
static int F_151 ( struct V_4 * V_8 ,
struct V_97 * V_97 )
{
static struct V_210 V_309 [ V_310 ] ;
struct V_90 * V_91 = V_97 -> V_91 ;
struct V_298 V_299 ;
struct V_203 * V_204 ;
struct V_104 * V_104 ;
struct V_162 * V_162 ;
struct V_266 V_267 ;
int V_69 = 0 , V_59 ;
if ( V_97 -> V_193 )
return 0 ;
if ( V_91 -> V_101 == 0 ) {
F_17 ( V_8 -> V_10 , L_62 ,
V_75 ) ;
return 0 ;
}
memset ( & V_267 , 0 , sizeof( V_267 ) ) ;
memset ( & V_309 , 0 , sizeof( V_309 ) ) ;
memset ( & V_299 , 0 , sizeof( V_299 ) ) ;
V_267 . V_265 = V_91 -> V_263 ;
V_267 . V_129 = V_267 . V_265 + V_91 -> V_42 - 1 ;
V_204 = & V_299 . V_204 ;
V_204 -> V_267 = & V_267 ;
V_204 -> V_311 = V_97 ;
V_204 -> V_312 = V_313 ;
if ( V_91 -> V_21 & V_314 )
V_204 -> V_315 = F_152 (
V_91 -> V_316 ) ;
else
V_204 -> V_315 = V_317 ;
F_27 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_102 * V_103 = V_104 -> V_103 ;
struct V_210 * V_210 ;
if ( V_103 -> V_101 != V_91 -> V_101 )
continue;
if ( V_69 >= V_310 ) {
F_22 ( V_8 -> V_10 , L_63 ,
V_91 -> V_101 , V_310 ) ;
return - V_80 ;
}
V_210 = & V_309 [ V_69 ++ ] ;
V_59 = F_148 ( V_8 , V_210 , V_204 ,
V_103 , V_97 ) ;
if ( V_59 )
goto V_78;
}
V_204 -> V_210 = V_309 ;
V_204 -> V_194 = V_69 ;
V_59 = F_81 ( V_8 , V_204 , V_91 ) ;
if ( V_59 )
goto V_78;
V_162 = V_8 -> V_162 ;
if ( F_25 ( V_91 ) == V_83 ) {
V_59 = F_143 ( V_8 , V_204 ) ;
if ( V_59 ) {
F_39 ( V_8 -> V_10 ,
L_64 ,
V_59 ) ;
goto V_78;
}
V_97 -> V_193 = F_153 ( V_162 ,
V_204 ) ;
if ( ! V_97 -> V_193 )
V_59 = - V_133 ;
} else if ( F_25 ( V_91 ) == V_82 ) {
V_97 -> V_193 = F_154 ( V_162 ,
V_204 ) ;
if ( ! V_97 -> V_193 )
V_59 = - V_133 ;
}
V_78:
if ( V_59 )
F_22 ( V_8 -> V_10 , L_65 ,
V_97 -> V_91 -> V_101 ) ;
return V_59 ;
}
static int F_155 ( struct V_4 * V_8 ,
T_4 V_318 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_15 * V_16 ;
if ( V_8 -> V_16 && V_8 -> V_285 >= V_318 ) {
memset ( V_8 -> V_16 , 0 , V_8 -> V_285 ) ;
return 0 ;
}
if ( V_8 -> V_16 )
F_84 ( V_10 , V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
V_16 = F_29 ( V_10 , V_318 , V_100 ) ;
if ( ! V_16 )
return - V_133 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_285 = V_318 ;
return 0 ;
}
static int F_156 ( struct V_4 * V_8 ,
struct V_97 * V_97 )
{
struct V_90 * V_91 = V_97 -> V_91 ;
int V_59 ;
if ( ! V_97 -> V_318 ) {
struct V_19 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_59 = F_136 ( V_8 , & V_20 , V_97 ) ;
if ( V_59 < 0 )
return V_59 ;
V_97 -> V_318 = V_20 . V_319 ;
V_97 -> V_320 = V_20 . V_320 ;
if ( F_25 ( V_91 ) == V_82 &&
( ( V_20 . V_23 >> 16 ) & V_28 ) == 0 )
return - V_25 ;
else if ( F_25 ( V_91 ) == V_83 &&
( ( V_20 . V_23 >> 16 ) & V_27 ) == 0 )
return - V_25 ;
}
if ( F_155 ( V_8 , V_97 -> V_318 ) )
return - V_133 ;
V_59 = F_138 ( V_8 ) ;
if ( V_59 < 0 && V_59 != - V_39 )
return V_59 ;
if ( F_139 ( V_8 -> V_162 ,
V_8 -> V_16 ) )
return - V_133 ;
return 0 ;
}
static void F_157 ( struct V_4 * V_8 ,
struct V_97 * V_97 )
{
struct V_90 * V_91 = V_97 -> V_91 ;
unsigned int V_321 = V_322 ;
V_202 V_323 = 0 , V_324 = 0 ;
struct V_52 * V_10 = V_8 -> V_10 ;
unsigned int V_325 = V_326 ;
int V_59 ;
if ( V_97 -> V_327 || ! V_97 -> V_193 )
return;
V_59 = V_18 ( V_8 , V_97 ) ;
if ( V_59 < 0 && V_59 != - V_31 )
return;
do {
V_202 V_18 , V_328 ;
if ( V_8 -> V_329 )
break;
V_59 = F_156 ( V_8 , V_97 ) ;
if ( V_59 == - V_25 )
break;
if ( V_59 == - V_31 && ! V_325 ) {
F_39 ( V_10 , L_66 ,
V_91 -> V_101 ) ;
break;
}
if ( V_59 == - V_31 ) {
F_117 ( & V_8 -> V_330 ) ;
F_158 ( 1 ) ;
V_325 -- ;
F_115 ( & V_8 -> V_330 ) ;
continue;
}
if ( V_59 == - V_39 && V_321 -- ) {
if ( ! V_324 ) {
V_324 = V_8 -> V_16 -> V_42 ;
V_323 = V_8 -> V_16 -> V_263 ;
}
V_59 = F_137 ( V_8 ) ;
}
if ( V_59 < 0 ) {
F_39 ( V_10 , L_67 ,
V_91 -> V_101 ) ;
break;
}
if ( V_324 ) {
V_18 = V_323 ;
V_328 = V_324 ;
} else {
V_18 = V_8 -> V_16 -> V_263 ;
V_328 = V_8 -> V_16 -> V_42 ;
}
F_17 ( V_10 , L_68 ,
V_91 -> V_101 , V_18 , V_328 ) ;
F_159 ( V_97 -> V_193 ,
V_331 ) ;
break;
} while ( 1 );
}
static void F_160 ( struct V_332 * V_333 )
{
struct V_52 * V_10 ;
V_202 V_334 = 0 ;
struct V_97 * V_97 ;
V_202 V_335 = 0 ;
bool V_336 = false ;
struct V_4 * V_8 ;
unsigned int V_325 = V_326 ;
unsigned int V_321 = V_322 ;
V_8 = F_3 ( V_333 , F_46 ( * V_8 ) , V_333 ) ;
V_10 = V_8 -> V_10 ;
V_337:
F_115 ( & V_8 -> V_330 ) ;
F_27 (nfit_spa, &acpi_desc->spas, list) {
struct V_15 * V_16 ;
struct V_90 * V_91 ;
V_202 V_18 , V_328 ;
int V_59 ;
if ( V_8 -> V_329 )
break;
if ( V_97 -> V_193 )
continue;
if ( V_336 ) {
V_59 = 0 ;
} else
V_59 = F_156 ( V_8 , V_97 ) ;
if ( V_59 == - V_25 ) {
F_151 ( V_8 , V_97 ) ;
continue;
}
if ( V_59 == - V_31 && ! V_325 ) {
F_39 ( V_10 , L_69 ) ;
break;
} else if ( V_59 == - V_31 ) {
F_117 ( & V_8 -> V_330 ) ;
F_158 ( 1 ) ;
V_325 -- ;
goto V_337;
}
if ( V_59 == - V_39 && V_321 -- ) {
V_16 = V_8 -> V_16 ;
if ( ! V_334 ) {
V_334 = V_16 -> V_42 ;
V_335 = V_16 -> V_263 ;
}
V_59 = F_137 ( V_8 ) ;
if ( V_59 == 0 ) {
F_117 ( & V_8 -> V_330 ) ;
goto V_337;
}
}
if ( V_59 < 0 ) {
break;
}
V_16 = V_8 -> V_16 ;
if ( V_334 ) {
V_18 = V_335 ;
V_328 = V_18 + V_334 ;
} else {
V_18 = V_16 -> V_263 ;
V_328 = V_16 -> V_42 ;
}
V_91 = V_97 -> V_91 ;
if ( ! V_336 ) {
V_336 = true ;
F_17 ( V_10 , L_70 ,
V_18 , V_328 ) ;
}
if ( V_18 <= V_91 -> V_263 && V_18 + V_328
>= V_91 -> V_263 + V_91 -> V_42 )
F_151 ( V_8 , V_97 ) ;
}
F_27 (nfit_spa, &acpi_desc->spas, list) {
if ( V_97 -> V_193 )
V_97 -> V_327 = 1 ;
else
F_151 ( V_8 , V_97 ) ;
}
F_27 (nfit_spa, &acpi_desc->spas, list)
F_157 ( V_8 , V_97 ) ;
F_117 ( & V_8 -> V_330 ) ;
}
static int F_161 ( struct V_4 * V_8 )
{
struct V_97 * V_97 ;
int V_59 ;
F_27 (nfit_spa, &acpi_desc->spas, list)
if ( F_25 ( V_97 -> V_91 ) == V_84 ) {
V_59 = F_151 ( V_8 , V_97 ) ;
if ( V_59 )
return V_59 ;
}
F_162 ( V_338 , & V_8 -> V_333 ) ;
return 0 ;
}
static int F_163 ( struct V_4 * V_8 ,
struct V_94 * V_95 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
if ( ! F_164 ( & V_95 -> V_99 ) ||
! F_164 ( & V_95 -> V_105 ) ||
! F_164 ( & V_95 -> V_111 ) ||
! F_164 ( & V_95 -> V_116 ) ||
! F_164 ( & V_95 -> V_120 ) ||
! F_164 ( & V_95 -> V_126 ) ) {
F_22 ( V_10 , L_71 ) ;
return - V_80 ;
}
return 0 ;
}
int F_165 ( struct V_4 * V_8 , T_10 V_339 )
{
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_94 V_95 ;
const void * V_129 ;
T_1 * V_289 ;
int V_59 ;
F_115 ( & V_8 -> V_330 ) ;
F_30 ( & V_95 . V_99 ) ;
F_30 ( & V_95 . V_105 ) ;
F_30 ( & V_95 . V_111 ) ;
F_30 ( & V_95 . V_116 ) ;
F_30 ( & V_95 . V_120 ) ;
F_30 ( & V_95 . V_126 ) ;
F_166 ( & V_95 . V_99 , & V_8 -> V_99 ,
V_8 -> V_99 . V_95 ) ;
F_166 ( & V_95 . V_105 , & V_8 -> V_105 ,
V_8 -> V_105 . V_95 ) ;
F_166 ( & V_95 . V_111 , & V_8 -> V_111 ,
V_8 -> V_111 . V_95 ) ;
F_166 ( & V_95 . V_116 , & V_8 -> V_116 ,
V_8 -> V_116 . V_95 ) ;
F_166 ( & V_95 . V_120 , & V_8 -> V_120 ,
V_8 -> V_120 . V_95 ) ;
F_166 ( & V_95 . V_126 , & V_8 -> V_126 ,
V_8 -> V_126 . V_95 ) ;
V_289 = ( T_1 * ) V_8 -> V_340 ;
V_129 = V_289 + V_339 ;
while ( ! F_167 ( V_289 ) )
V_289 = F_37 ( V_8 , & V_95 , V_289 , V_129 ) ;
if ( F_168 ( V_289 ) ) {
F_17 ( V_10 , L_72 , V_75 ,
F_169 ( V_289 ) ) ;
V_59 = F_169 ( V_289 ) ;
goto V_341;
}
V_59 = F_163 ( V_8 , & V_95 ) ;
if ( V_59 )
goto V_341;
if ( F_47 ( V_8 ) != 0 ) {
V_59 = - V_133 ;
goto V_341;
}
F_74 ( V_8 ) ;
V_59 = F_70 ( V_8 ) ;
if ( V_59 )
goto V_341;
V_59 = F_161 ( V_8 ) ;
V_341:
F_117 ( & V_8 -> V_330 ) ;
return V_59 ;
}
static void F_170 ( struct V_332 * V_333 )
{
struct V_342 * V_124 ;
V_124 = F_3 ( V_333 , F_46 ( * V_124 ) , V_333 ) ;
F_171 ( & V_124 -> V_343 ) ;
}
static int F_172 ( struct V_5 * V_6 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
struct V_52 * V_10 = V_8 -> V_10 ;
struct V_342 V_124 ;
F_173 ( V_10 ) ;
F_174 ( V_10 ) ;
F_175 ( & V_124 . V_333 , F_170 ) ;
F_176 ( V_124 . V_343 ) ;
F_162 ( V_338 , & V_124 . V_333 ) ;
return F_177 ( & V_124 . V_343 ) ;
}
static int F_178 ( struct V_5 * V_6 ,
struct V_43 * V_43 , unsigned int V_12 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
if ( V_43 )
return 0 ;
if ( V_12 != V_29 )
return 0 ;
if ( F_179 ( & V_8 -> V_333 ) )
return - V_31 ;
return 0 ;
}
void F_180 ( struct V_4 * V_8 , struct V_52 * V_10 )
{
struct V_5 * V_6 ;
F_181 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_308 = F_99 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_9 = L_1 ;
V_6 -> V_276 = F_7 ;
V_6 -> F_170 = F_172 ;
V_6 -> V_344 = F_178 ;
V_6 -> V_312 = V_345 ;
F_30 ( & V_8 -> V_272 ) ;
F_30 ( & V_8 -> V_99 ) ;
F_30 ( & V_8 -> V_111 ) ;
F_30 ( & V_8 -> V_116 ) ;
F_30 ( & V_8 -> V_120 ) ;
F_30 ( & V_8 -> V_126 ) ;
F_30 ( & V_8 -> V_105 ) ;
F_30 ( & V_8 -> V_147 ) ;
F_182 ( & V_8 -> V_261 ) ;
F_182 ( & V_8 -> V_330 ) ;
F_183 ( & V_8 -> V_333 , F_160 ) ;
}
static int F_184 ( struct V_7 * V_62 )
{
struct V_346 V_11 = { V_347 , NULL } ;
struct V_4 * V_8 ;
struct V_52 * V_10 = & V_62 -> V_10 ;
struct V_348 * V_349 ;
T_11 V_23 = V_350 ;
T_10 V_339 ;
int V_59 ;
V_23 = F_185 ( L_73 , 0 , & V_349 , & V_339 ) ;
if ( F_186 ( V_23 ) ) {
F_17 ( V_10 , L_74 ) ;
return 0 ;
}
V_8 = F_29 ( V_10 , sizeof( * V_8 ) , V_100 ) ;
if ( ! V_8 )
return - V_133 ;
F_180 ( V_8 , & V_62 -> V_10 ) ;
V_8 -> V_162 = F_187 ( V_10 , & V_8 -> V_6 ) ;
if ( ! V_8 -> V_162 )
return - V_133 ;
V_8 -> V_163 = * V_349 ;
V_8 -> V_340 = ( void * ) V_349 + sizeof( struct V_351 ) ;
V_339 -= sizeof( struct V_351 ) ;
V_23 = F_188 ( V_62 -> V_56 , L_75 , NULL , & V_11 ) ;
if ( F_189 ( V_23 ) && V_11 . V_42 > 0 ) {
union V_48 * V_352 ;
V_352 = V_11 . V_73 ;
if ( V_352 -> type == V_71 ) {
V_8 -> V_340 =
(struct V_130 * ) V_352 -> V_72 . V_73 ;
V_339 = V_352 -> V_72 . V_42 ;
} else
F_17 ( V_10 , L_76 ,
V_75 , ( int ) V_352 -> type ) ;
}
V_59 = F_165 ( V_8 , V_339 ) ;
if ( V_59 ) {
F_190 ( V_8 -> V_162 ) ;
return V_59 ;
}
return 0 ;
}
static int F_191 ( struct V_7 * V_62 )
{
struct V_4 * V_8 = F_192 ( & V_62 -> V_10 ) ;
V_8 -> V_329 = 1 ;
F_193 ( V_338 ) ;
F_190 ( V_8 -> V_162 ) ;
return 0 ;
}
static void F_194 ( struct V_7 * V_62 , T_4 V_353 )
{
struct V_4 * V_8 = F_192 ( & V_62 -> V_10 ) ;
struct V_346 V_11 = { V_347 , NULL } ;
struct V_130 * V_354 ;
union V_48 * V_352 ;
struct V_52 * V_10 = & V_62 -> V_10 ;
T_11 V_23 ;
int V_292 ;
F_17 ( V_10 , L_77 , V_75 , V_353 ) ;
F_173 ( V_10 ) ;
if ( ! V_10 -> V_355 ) {
F_17 ( V_10 , L_78 , V_75 ) ;
goto V_341;
}
if ( ! V_8 ) {
V_8 = F_29 ( V_10 , sizeof( * V_8 ) , V_100 ) ;
if ( ! V_8 )
goto V_341;
F_180 ( V_8 , & V_62 -> V_10 ) ;
V_8 -> V_162 = F_187 ( V_10 , & V_8 -> V_6 ) ;
if ( ! V_8 -> V_162 )
goto V_341;
} else {
F_193 ( V_338 ) ;
}
V_23 = F_188 ( V_62 -> V_56 , L_75 , NULL , & V_11 ) ;
if ( F_186 ( V_23 ) ) {
F_22 ( V_10 , L_79 ) ;
goto V_341;
}
V_354 = V_8 -> V_340 ;
V_352 = V_11 . V_73 ;
if ( V_352 -> type == V_71 ) {
V_8 -> V_340 =
(struct V_130 * ) V_352 -> V_72 . V_73 ;
V_292 = F_165 ( V_8 , V_352 -> V_72 . V_42 ) ;
if ( V_292 ) {
V_8 -> V_340 = V_354 ;
F_22 ( V_10 , L_80 ) ;
}
} else {
F_22 ( V_10 , L_81 ) ;
}
F_112 ( V_11 . V_73 ) ;
V_341:
F_174 ( V_10 ) ;
}
static T_12 int F_195 ( void )
{
F_196 ( sizeof( struct V_351 ) != 40 ) ;
F_196 ( sizeof( struct V_90 ) != 56 ) ;
F_196 ( sizeof( struct V_102 ) != 48 ) ;
F_196 ( sizeof( struct V_117 ) != 20 ) ;
F_196 ( sizeof( struct V_356 ) != 9 ) ;
F_196 ( sizeof( struct V_108 ) != 80 ) ;
F_196 ( sizeof( struct V_113 ) != 40 ) ;
F_197 ( V_357 , V_3 [ V_82 ] ) ;
F_197 ( V_358 , V_3 [ V_83 ] ) ;
F_197 ( V_359 , V_3 [ V_84 ] ) ;
F_197 ( V_360 , V_3 [ V_85 ] ) ;
F_197 ( V_361 , V_3 [ V_86 ] ) ;
F_197 ( V_362 , V_3 [ V_87 ] ) ;
F_197 ( V_363 , V_3 [ V_88 ] ) ;
F_197 ( V_364 , V_3 [ V_89 ] ) ;
F_197 ( V_365 , V_3 [ V_64 ] ) ;
F_197 ( V_366 , V_3 [ V_63 ] ) ;
V_338 = F_198 ( L_82 ) ;
if ( ! V_338 )
return - V_133 ;
return F_199 ( & V_367 ) ;
}
static T_13 void F_200 ( void )
{
F_201 ( & V_367 ) ;
F_202 ( V_338 ) ;
}
