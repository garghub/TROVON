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
static int F_6 ( struct V_5 * V_6 ,
struct V_11 * V_11 , unsigned int V_12 , void * V_13 ,
unsigned int V_14 )
{
struct V_4 * V_8 = F_2 ( V_6 ) ;
const struct V_15 * V_16 = NULL ;
union V_17 V_18 , V_19 , * V_20 ;
struct V_21 * V_10 = V_8 -> V_10 ;
const char * V_22 , * V_23 ;
unsigned long V_24 ;
T_2 V_25 ;
const T_1 * V_26 ;
T_3 V_27 ;
int V_28 , V_29 ;
if ( V_11 ) {
struct V_30 * V_30 = F_7 ( V_11 ) ;
struct V_7 * V_31 = V_30 -> V_31 ;
if ( ! V_31 )
return - V_32 ;
V_23 = F_8 ( V_11 ) ;
V_22 = F_9 ( V_12 ) ;
V_24 = V_30 -> V_24 ;
V_16 = F_10 ( V_12 ) ;
V_26 = F_1 ( V_33 ) ;
V_25 = V_31 -> V_25 ;
} else {
struct V_7 * V_31 = F_4 ( V_8 ) ;
V_22 = F_11 ( V_12 ) ;
V_24 = V_6 -> V_24 ;
V_16 = F_12 ( V_12 ) ;
V_26 = F_1 ( V_34 ) ;
V_25 = V_31 -> V_25 ;
V_23 = L_2 ;
}
if ( ! V_16 || ( V_12 && ( V_16 -> V_35 + V_16 -> V_36 == 0 ) ) )
return - V_32 ;
if ( ! F_13 ( V_12 , & V_24 ) )
return - V_32 ;
V_18 . type = V_37 ;
V_18 . V_38 . V_39 = 1 ;
V_18 . V_38 . V_40 = & V_19 ;
V_19 . type = V_41 ;
V_19 . V_42 . V_43 = V_13 ;
V_19 . V_42 . V_44 = 0 ;
for ( V_29 = 0 ; V_29 < V_16 -> V_36 ; V_29 ++ )
V_19 . V_42 . V_44 += F_14 ( V_11 , V_12 , V_16 ,
V_29 , V_13 ) ;
if ( F_15 ( V_45 ) ) {
F_16 ( V_10 , L_3 , V_46 ,
V_23 , V_22 , V_19 . V_42 . V_44 ) ;
F_17 ( V_22 , V_47 , 4 ,
4 , V_19 . V_42 . V_43 , F_18 ( T_3 , 128 ,
V_19 . V_42 . V_44 ) , true ) ;
}
V_20 = F_19 ( V_25 , V_26 , 1 , V_12 , & V_18 ) ;
if ( ! V_20 ) {
F_16 ( V_10 , L_4 , V_46 , V_23 ,
V_22 ) ;
return - V_48 ;
}
if ( V_20 -> V_38 . type != V_41 ) {
F_16 ( V_10 , L_5 ,
V_46 , V_23 , V_22 , V_20 -> type ) ;
V_28 = - V_48 ;
goto V_49;
}
if ( F_15 ( V_45 ) ) {
F_16 ( V_10 , L_6 , V_46 ,
V_23 , V_22 , V_20 -> V_42 . V_44 ) ;
F_17 ( V_22 , V_47 , 4 ,
4 , V_20 -> V_42 . V_43 , F_18 ( T_3 , 128 ,
V_20 -> V_42 . V_44 ) , true ) ;
}
for ( V_29 = 0 , V_27 = 0 ; V_29 < V_16 -> V_35 ; V_29 ++ ) {
T_3 V_50 = F_20 ( V_11 , V_12 , V_16 , V_29 , V_13 ,
( T_3 * ) V_20 -> V_42 . V_43 ) ;
if ( V_27 + V_50 > V_20 -> V_42 . V_44 ) {
F_16 ( V_10 , L_7 ,
V_46 , V_23 , V_22 , V_29 ) ;
break;
}
if ( V_19 . V_42 . V_44 + V_27 + V_50 > V_14 ) {
F_16 ( V_10 , L_8 ,
V_46 , V_23 , V_22 , V_29 ) ;
V_28 = - V_51 ;
goto V_49;
}
memcpy ( V_13 + V_19 . V_42 . V_44 + V_27 ,
V_20 -> V_42 . V_43 + V_27 , V_50 ) ;
V_27 += V_50 ;
}
if ( V_27 + V_19 . V_42 . V_44 < V_14 ) {
if ( V_29 >= 1 ) {
V_28 = V_14 - V_27 - V_19 . V_42 . V_44 ;
} else {
F_21 ( V_10 , L_9 ,
V_46 , V_23 , V_22 , V_14 ,
V_27 ) ;
V_28 = - V_51 ;
}
} else
V_28 = 0 ;
V_49:
F_22 ( V_20 ) ;
return V_28 ;
}
static const char * F_23 ( T_4 type )
{
static const char * V_52 [] = {
[ V_53 ] = L_10 ,
[ V_54 ] = L_11 ,
[ V_55 ] = L_12 ,
[ V_56 ] = L_13 ,
[ V_57 ] = L_14 ,
[ V_58 ] = L_15 ,
[ V_59 ] = L_16 ,
[ V_60 ] = L_17 ,
} ;
if ( type > V_60 )
return L_18 ;
return V_52 [ type ] ;
}
static int F_24 ( struct V_61 * V_62 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_63 ; V_29 ++ )
if ( memcmp ( F_1 ( V_29 ) , V_62 -> V_64 , 16 ) == 0 )
return V_29 ;
return - 1 ;
}
static bool F_25 ( struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_65 * V_65 = F_26 ( V_10 , sizeof( * V_65 ) ,
V_66 ) ;
if ( ! V_65 )
return false ;
F_27 ( & V_65 -> V_67 ) ;
V_65 -> V_62 = V_62 ;
F_28 ( & V_65 -> V_67 , & V_8 -> V_68 ) ;
F_16 ( V_10 , L_19 , V_46 ,
V_62 -> V_69 ,
F_23 ( F_24 ( V_62 ) ) ) ;
return true ;
}
static bool F_29 ( struct V_4 * V_8 ,
struct V_70 * V_71 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_72 * V_72 = F_26 ( V_10 ,
sizeof( * V_72 ) , V_66 ) ;
if ( ! V_72 )
return false ;
F_27 ( & V_72 -> V_67 ) ;
V_72 -> V_71 = V_71 ;
F_28 ( & V_72 -> V_67 , & V_8 -> V_73 ) ;
F_16 ( V_10 , L_20 ,
V_46 , V_71 -> V_74 , V_71 -> V_69 ,
V_71 -> V_75 ) ;
return true ;
}
static bool F_30 ( struct V_4 * V_8 ,
struct V_76 * V_77 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_78 * V_78 = F_26 ( V_10 , sizeof( * V_78 ) ,
V_66 ) ;
if ( ! V_78 )
return false ;
F_27 ( & V_78 -> V_67 ) ;
V_78 -> V_77 = V_77 ;
F_28 ( & V_78 -> V_67 , & V_8 -> V_79 ) ;
F_16 ( V_10 , L_21 , V_46 ,
V_77 -> V_75 , V_77 -> V_80 ) ;
return true ;
}
static bool F_31 ( struct V_4 * V_8 ,
struct V_81 * V_82 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_83 * V_83 = F_26 ( V_10 , sizeof( * V_83 ) ,
V_66 ) ;
if ( ! V_83 )
return false ;
F_27 ( & V_83 -> V_67 ) ;
V_83 -> V_82 = V_82 ;
F_28 ( & V_83 -> V_67 , & V_8 -> V_84 ) ;
F_16 ( V_10 , L_22 , V_46 ,
V_82 -> V_75 , V_82 -> V_80 ) ;
return true ;
}
static bool F_32 ( struct V_4 * V_8 ,
struct V_85 * V_86 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_87 * V_87 = F_26 ( V_10 , sizeof( * V_87 ) ,
V_66 ) ;
if ( ! V_87 )
return false ;
F_27 ( & V_87 -> V_67 ) ;
V_87 -> V_86 = V_86 ;
F_28 ( & V_87 -> V_67 , & V_8 -> V_88 ) ;
F_16 ( V_10 , L_23 , V_46 ,
V_86 -> V_89 , V_86 -> V_90 ) ;
return true ;
}
static bool F_33 ( struct V_4 * V_8 ,
struct V_91 * V_92 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_93 * V_93 = F_26 ( V_10 , sizeof( * V_93 ) ,
V_66 ) ;
if ( ! V_93 )
return false ;
F_27 ( & V_93 -> V_67 ) ;
V_93 -> V_92 = V_92 ;
F_28 ( & V_93 -> V_67 , & V_8 -> V_94 ) ;
F_16 ( V_10 , L_24 , V_46 ,
V_92 -> V_74 , V_92 -> V_95 ) ;
return true ;
}
static void * F_34 ( struct V_4 * V_8 , void * V_96 ,
const void * V_97 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_98 * V_99 ;
void * V_100 = F_35 ( - V_101 ) ;
if ( V_96 >= V_97 )
return NULL ;
V_99 = V_96 ;
switch ( V_99 -> type ) {
case V_102 :
if ( ! F_25 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_103 :
if ( ! F_29 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_104 :
if ( ! F_30 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_105 :
if ( ! F_31 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_106 :
if ( ! F_32 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_107 :
if ( ! F_33 ( V_8 , V_96 ) )
return V_100 ;
break;
case V_108 :
F_16 ( V_10 , L_25 , V_46 ) ;
break;
default:
F_21 ( V_10 , L_26 , V_99 -> type ) ;
break;
}
return V_96 + V_99 -> V_44 ;
}
static void F_36 ( struct V_4 * V_8 ,
struct V_30 * V_30 )
{
T_3 V_74 = F_37 ( V_30 ) -> V_74 ;
T_4 V_77 = V_30 -> V_77 -> V_75 ;
struct V_65 * V_65 ;
F_38 (nfit_spa, &acpi_desc->spas, list) {
T_4 V_69 = V_65 -> V_62 -> V_69 ;
int type = F_24 ( V_65 -> V_62 ) ;
struct V_72 * V_72 ;
if ( type != V_56 )
continue;
F_38 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_72 -> V_71 -> V_69 != V_69 )
continue;
if ( V_72 -> V_71 -> V_74 != V_74 )
continue;
if ( V_72 -> V_71 -> V_75 != V_77 )
continue;
V_30 -> V_109 = V_65 -> V_62 ;
return;
}
}
F_16 ( V_8 -> V_10 , L_27 ,
V_30 -> V_110 -> V_69 ) ;
V_30 -> V_82 = NULL ;
}
static int F_39 ( struct V_4 * V_8 ,
struct V_30 * V_30 , struct V_61 * V_62 )
{
T_4 V_77 = F_37 ( V_30 ) -> V_75 ;
struct V_72 * V_72 ;
struct V_93 * V_93 ;
struct V_78 * V_78 ;
struct V_83 * V_83 ;
struct V_87 * V_87 ;
T_4 V_111 , V_69 ;
F_38 (nfit_dcr, &acpi_desc->dcrs, list) {
if ( V_78 -> V_77 -> V_75 != V_77 )
continue;
V_30 -> V_77 = V_78 -> V_77 ;
break;
}
if ( ! V_30 -> V_77 ) {
F_16 ( V_8 -> V_10 , L_28 ,
V_62 -> V_69 , F_37 ( V_30 )
? L_29 : L_30 , V_30 -> V_77 ? L_29 : L_31 ) ;
return - V_112 ;
}
F_40 ( & V_30 -> V_67 , & V_8 -> V_113 ) ;
F_38 (nfit_bdw, &acpi_desc->bdws, list) {
if ( V_83 -> V_82 -> V_75 != V_77 )
continue;
V_30 -> V_82 = V_83 -> V_82 ;
break;
}
if ( ! V_30 -> V_82 )
return 0 ;
F_36 ( V_8 , V_30 ) ;
if ( ! V_30 -> V_109 )
return 0 ;
V_69 = V_30 -> V_109 -> V_69 ;
F_38 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_72 -> V_71 -> V_69 != V_69 ||
V_72 -> V_71 -> V_75 != V_77 )
continue;
V_30 -> V_114 = V_72 -> V_71 ;
V_111 = V_72 -> V_71 -> V_89 ;
F_38 (nfit_idt, &acpi_desc->idts, list) {
if ( V_87 -> V_86 -> V_89 != V_111 )
continue;
V_30 -> V_115 = V_87 -> V_86 ;
break;
}
F_38 (nfit_flush, &acpi_desc->flushes, list) {
if ( V_93 -> V_92 -> V_74 !=
V_72 -> V_71 -> V_74 )
continue;
V_30 -> V_93 = V_93 ;
break;
}
break;
}
return 0 ;
}
static int F_41 ( struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_30 * V_30 , * V_116 ;
struct V_72 * V_72 ;
int type = F_24 ( V_62 ) ;
T_4 V_77 ;
switch ( type ) {
case V_55 :
case V_54 :
break;
default:
return 0 ;
}
F_38 (nfit_memdev, &acpi_desc->memdevs, list) {
int V_28 ;
if ( V_72 -> V_71 -> V_69 != V_62 -> V_69 )
continue;
V_116 = NULL ;
V_77 = V_72 -> V_71 -> V_75 ;
F_38 (nfit_mem, &acpi_desc->dimms, list)
if ( F_37 ( V_30 ) -> V_75 == V_77 ) {
V_116 = V_30 ;
break;
}
if ( V_116 )
V_30 = V_116 ;
else {
V_30 = F_26 ( V_8 -> V_10 ,
sizeof( * V_30 ) , V_66 ) ;
if ( ! V_30 )
return - V_101 ;
F_27 ( & V_30 -> V_67 ) ;
}
if ( type == V_55 ) {
struct V_87 * V_87 ;
T_4 V_111 ;
V_30 -> V_110 = V_62 ;
V_30 -> V_117 = V_72 -> V_71 ;
V_111 = V_72 -> V_71 -> V_89 ;
F_38 (nfit_idt, &acpi_desc->idts, list) {
if ( V_87 -> V_86 -> V_89 != V_111 )
continue;
V_30 -> V_118 = V_87 -> V_86 ;
break;
}
} else {
V_30 -> V_119 = V_72 -> V_71 ;
}
if ( V_116 )
continue;
V_28 = F_39 ( V_8 , V_30 , V_62 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_42 ( void * V_120 , struct V_121 * V_122 , struct V_121 * V_123 )
{
struct V_30 * V_124 = F_3 ( V_122 , F_43 ( * V_124 ) , V_67 ) ;
struct V_30 * V_125 = F_3 ( V_123 , F_43 ( * V_125 ) , V_67 ) ;
T_3 V_126 , V_127 ;
V_126 = F_37 ( V_124 ) -> V_74 ;
V_127 = F_37 ( V_125 ) -> V_74 ;
if ( V_126 < V_127 )
return - 1 ;
else if ( V_126 > V_127 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_4 * V_8 )
{
struct V_65 * V_65 ;
F_38 (nfit_spa, &acpi_desc->spas, list) {
int V_28 ;
V_28 = F_41 ( V_8 , V_65 -> V_62 ) ;
if ( V_28 )
return V_28 ;
}
F_45 ( NULL , & V_8 -> V_113 , F_42 ) ;
return 0 ;
}
static T_5 F_46 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_130 * V_130 = F_47 ( V_10 ) ;
struct V_5 * V_6 = F_48 ( V_130 ) ;
struct V_4 * V_8 = F_49 ( V_6 ) ;
return sprintf ( V_13 , L_32 , V_8 -> V_131 -> V_132 . V_133 ) ;
}
static struct V_70 * F_50 ( struct V_21 * V_10 )
{
struct V_11 * V_11 = F_51 ( V_10 ) ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
return F_37 ( V_30 ) ;
}
static struct V_76 * F_52 ( struct V_21 * V_10 )
{
struct V_11 * V_11 = F_51 ( V_10 ) ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
return V_30 -> V_77 ;
}
static T_5 F_53 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_70 * V_71 = F_50 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_71 -> V_74 ) ;
}
static T_5 F_54 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_70 * V_71 = F_50 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_71 -> V_134 ) ;
}
static T_5 F_55 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_76 * V_77 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_77 -> V_135 ) ;
}
static T_5 F_56 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_76 * V_77 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_77 -> V_136 ) ;
}
static T_5 F_57 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_76 * V_77 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_77 -> V_137 ) ;
}
static T_5 F_58 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_76 * V_77 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_77 -> V_138 ) ;
}
static T_5 F_59 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_76 * V_77 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_33 , V_77 -> V_139 ) ;
}
static T_5 F_60 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
T_4 V_140 = F_50 ( V_10 ) -> V_140 ;
return sprintf ( V_13 , L_34 ,
V_140 & V_141 ? L_35 : L_29 ,
V_140 & V_142 ? L_36 : L_29 ,
V_140 & V_143 ? L_37 : L_29 ,
V_140 & V_144 ? L_38 : L_29 ,
V_140 & V_145 ? L_39 : L_29 ) ;
}
static T_6 F_61 ( struct V_146 * V_147 ,
struct V_148 * V_124 , int V_149 )
{
struct V_21 * V_10 = F_3 ( V_147 , struct V_21 , V_147 ) ;
if ( F_52 ( V_10 ) )
return V_124 -> V_150 ;
else
return 0 ;
}
static struct V_11 * F_62 ( struct V_4 * V_8 ,
T_3 V_74 )
{
struct V_30 * V_30 ;
F_38 (nfit_mem, &acpi_desc->dimms, list)
if ( F_37 ( V_30 ) -> V_74 == V_74 )
return V_30 -> V_11 ;
return NULL ;
}
static int F_63 ( struct V_4 * V_8 ,
struct V_30 * V_30 , T_3 V_74 )
{
struct V_7 * V_31 , * V_151 ;
struct V_21 * V_10 = V_8 -> V_10 ;
const T_1 * V_26 = F_1 ( V_33 ) ;
int V_29 ;
V_30 -> V_24 = V_8 -> V_152 ;
V_31 = F_4 ( V_8 ) ;
if ( ! V_31 )
return 0 ;
V_151 = F_64 ( V_31 , V_74 , false ) ;
V_30 -> V_31 = V_151 ;
if ( ! V_151 ) {
F_21 ( V_10 , L_40 ,
V_74 ) ;
return V_153 ? 0 : - V_112 ;
}
for ( V_29 = V_154 ; V_29 <= V_155 ; V_29 ++ )
if ( F_65 ( V_151 -> V_25 , V_26 , 1 , 1ULL << V_29 ) )
F_66 ( V_29 , & V_30 -> V_24 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_8 )
{
struct V_30 * V_30 ;
int V_156 = 0 ;
F_38 (nfit_mem, &acpi_desc->dimms, list) {
struct V_11 * V_11 ;
unsigned long V_140 = 0 ;
T_3 V_74 ;
T_4 V_157 ;
int V_28 ;
V_74 = F_37 ( V_30 ) -> V_74 ;
V_11 = F_62 ( V_8 , V_74 ) ;
if ( V_11 ) {
F_21 ( V_8 -> V_10 , L_41 ,
F_8 ( V_11 ) ) ;
continue;
}
if ( V_30 -> V_82 && V_30 -> V_119 )
V_140 |= V_158 ;
V_157 = F_37 ( V_30 ) -> V_140 ;
if ( V_157 & V_144 )
V_140 |= V_159 ;
V_28 = F_63 ( V_8 , V_30 , V_74 ) ;
if ( V_28 )
continue;
V_11 = F_68 ( V_8 -> V_130 , V_30 ,
V_160 ,
V_140 , & V_30 -> V_24 ) ;
if ( ! V_11 )
return - V_101 ;
V_30 -> V_11 = V_11 ;
V_156 ++ ;
if ( ( V_157 & V_161 ) == 0 )
continue;
F_69 ( V_8 -> V_10 , L_42 ,
F_8 ( V_11 ) ,
V_157 & V_141 ? L_43 : L_29 ,
V_157 & V_142 ? L_44 : L_29 ,
V_157 & V_143 ? L_45 : L_29 ,
V_157 & V_144 ? L_46 : L_29 ) ;
}
return F_70 ( V_8 -> V_130 , V_156 ) ;
}
static void F_71 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
const T_1 * V_26 = F_1 ( V_34 ) ;
struct V_7 * V_31 ;
int V_29 ;
V_6 -> V_24 = V_8 -> V_162 ;
V_31 = F_4 ( V_8 ) ;
if ( ! V_31 )
return;
for ( V_29 = V_163 ; V_29 <= V_164 ; V_29 ++ )
if ( F_65 ( V_31 -> V_25 , V_26 , 1 , 1ULL << V_29 ) )
F_66 ( V_29 , & V_6 -> V_24 ) ;
}
static T_5 F_72 ( struct V_21 * V_10 ,
struct V_128 * V_129 , char * V_13 )
{
struct V_165 * V_165 = F_73 ( V_10 ) ;
struct V_65 * V_65 = F_74 ( V_165 ) ;
return sprintf ( V_13 , L_32 , V_65 -> V_62 -> V_69 ) ;
}
static T_7 F_75 ( int V_166 )
{
return sizeof( struct V_167 )
+ V_166 * sizeof( struct V_168 ) ;
}
static int F_76 ( const void * V_169 , const void * V_170 )
{
const struct V_168 * V_171 = V_169 ;
const struct V_168 * V_172 = V_170 ;
return memcmp ( & V_171 -> V_173 , & V_172 -> V_173 ,
sizeof( V_174 ) ) ;
}
static struct V_70 * F_77 (
struct V_4 * V_8 , T_4 V_69 , int V_149 )
{
struct V_72 * V_72 ;
F_38 (nfit_memdev, &acpi_desc->memdevs, list)
if ( V_72 -> V_71 -> V_69 == V_69 )
if ( V_149 -- == 0 )
return V_72 -> V_71 ;
return NULL ;
}
static int F_78 ( struct V_4 * V_8 ,
struct V_175 * V_176 ,
struct V_61 * V_62 )
{
int V_29 , V_177 = F_24 ( V_62 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_178 * V_179 ;
T_4 V_180 = V_176 -> V_166 ;
struct V_167 * V_181 ;
if ( V_177 == V_54 || V_177 == V_53 )
;
else
return 0 ;
V_179 = F_26 ( V_10 , sizeof( * V_179 ) , V_66 ) ;
if ( ! V_179 )
return - V_101 ;
V_181 = F_26 ( V_10 , F_75 ( V_180 ) , V_66 ) ;
if ( ! V_181 )
return - V_101 ;
for ( V_29 = 0 ; V_29 < V_180 ; V_29 ++ ) {
struct V_182 * V_182 = & V_176 -> V_182 [ V_29 ] ;
struct V_168 * V_183 = & V_181 -> V_184 [ V_29 ] ;
struct V_11 * V_11 = V_182 -> V_11 ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
struct V_70 * V_71 = F_77 ( V_8 ,
V_62 -> V_69 , V_29 ) ;
if ( ! V_71 || ! V_30 -> V_77 ) {
F_21 ( V_10 , L_47 , V_46 ) ;
return - V_112 ;
}
V_183 -> V_173 = V_71 -> V_173 ;
V_183 -> V_139 = V_30 -> V_77 -> V_139 ;
}
F_79 ( & V_181 -> V_184 [ 0 ] , V_180 , sizeof( struct V_168 ) ,
F_76 , NULL ) ;
V_179 -> V_185 = F_80 ( V_181 , F_75 ( V_180 ) , 0 ) ;
V_176 -> V_179 = V_179 ;
F_81 ( V_10 , V_181 ) ;
return 0 ;
}
static V_174 F_82 ( V_174 V_27 , struct V_186 * V_187 )
{
struct V_85 * V_86 = V_187 -> V_86 ;
T_3 V_188 , V_189 , V_190 ;
V_174 V_191 , V_192 , V_193 ;
V_191 = F_83 ( V_27 , V_187 -> V_194 , & V_188 ) ;
V_192 = F_83 ( V_191 , V_187 -> V_195 , & V_189 ) ;
V_190 = V_86 -> V_190 [ V_189 ]
* V_187 -> V_194 ;
V_193 = V_192 * V_187 -> V_196 ;
return V_187 -> V_197 + V_190 + V_193 + V_188 ;
}
static void F_84 ( struct V_198 * V_198 )
{
if ( V_198 -> V_199 ) {
F_85 () ;
F_86 ( 1 , V_198 -> V_199 ) ;
F_85 () ;
} else
F_87 () ;
}
static T_3 F_88 ( struct V_198 * V_198 , unsigned int V_200 )
{
struct V_186 * V_187 = & V_198 -> V_187 [ V_201 ] ;
V_174 V_27 = V_198 -> V_202 + V_187 -> V_203 * V_200 ;
if ( V_187 -> V_195 )
V_27 = F_82 ( V_27 , V_187 ) ;
return F_89 ( V_187 -> V_204 . V_205 + V_27 ) ;
}
static void F_90 ( struct V_198 * V_198 , unsigned int V_200 ,
T_8 V_206 , unsigned int V_207 , unsigned int V_208 )
{
V_174 V_12 , V_27 ;
struct V_186 * V_187 = & V_198 -> V_187 [ V_201 ] ;
enum {
V_209 = ( 1ULL << 48 ) - 1 ,
V_210 = 48 ,
V_211 = ( 1ULL << 8 ) - 1 ,
V_212 = 56 ,
};
V_12 = ( V_206 >> V_213 ) & V_209 ;
V_207 = V_207 >> V_213 ;
V_12 |= ( ( V_174 ) V_207 & V_211 ) << V_210 ;
V_12 |= ( ( V_174 ) V_208 ) << V_212 ;
V_27 = V_198 -> V_214 + V_187 -> V_203 * V_200 ;
if ( V_187 -> V_195 )
V_27 = F_82 ( V_27 , V_187 ) ;
F_86 ( V_12 , V_187 -> V_204 . V_205 + V_27 ) ;
F_84 ( V_198 ) ;
if ( V_198 -> V_215 & V_216 )
F_91 ( V_187 -> V_204 . V_205 + V_27 ) ;
}
static int F_92 ( struct V_198 * V_198 ,
T_8 V_206 , void * V_217 , T_7 V_207 , int V_218 ,
unsigned int V_219 )
{
struct V_186 * V_187 = & V_198 -> V_187 [ V_220 ] ;
unsigned int V_221 = 0 ;
V_174 V_197 ;
int V_28 ;
V_197 = V_198 -> V_222 + V_206 % V_223
+ V_219 * V_187 -> V_203 ;
F_90 ( V_198 , V_219 , V_206 , V_207 , V_218 ) ;
while ( V_207 ) {
unsigned int V_224 ;
V_174 V_27 ;
if ( V_187 -> V_195 ) {
T_3 V_190 ;
V_27 = F_82 ( V_197 + V_221 ,
V_187 ) ;
F_83 ( V_27 , V_187 -> V_194 , & V_190 ) ;
V_224 = F_18 ( T_7 , V_207 , V_187 -> V_194 - V_190 ) ;
} else {
V_27 = V_197 + V_198 -> V_222 ;
V_224 = V_207 ;
}
if ( V_218 )
F_93 ( V_187 -> V_204 . V_225 + V_27 ,
V_217 + V_221 , V_224 ) ;
else {
if ( V_198 -> V_215 & V_226 )
F_94 ( ( void V_227 * )
V_187 -> V_204 . V_225 + V_27 , V_224 ) ;
F_95 ( V_217 + V_221 ,
V_187 -> V_204 . V_225 + V_27 , V_224 ) ;
}
V_221 += V_224 ;
V_207 -= V_224 ;
}
if ( V_218 )
F_84 ( V_198 ) ;
V_28 = F_88 ( V_198 , V_219 ) ? - V_228 : 0 ;
return V_28 ;
}
static int F_96 ( struct V_229 * V_230 ,
T_8 V_206 , void * V_217 , V_174 V_207 , int V_218 )
{
struct V_198 * V_198 = F_97 ( V_230 ) ;
struct V_186 * V_187 = & V_198 -> V_187 [ V_220 ] ;
struct V_165 * V_165 = V_198 -> V_165 ;
unsigned int V_219 , V_221 = 0 ;
int V_28 = 0 ;
V_219 = F_98 ( V_165 ) ;
while ( V_207 ) {
V_174 V_224 = F_99 ( V_207 , V_187 -> V_203 ) ;
V_28 = F_92 ( V_198 , V_206 + V_221 ,
V_217 + V_221 , V_224 , V_218 , V_219 ) ;
if ( V_28 )
break;
V_221 += V_224 ;
V_207 -= V_224 ;
}
F_100 ( V_165 , V_219 ) ;
return V_28 ;
}
static void F_101 ( struct V_231 * V_231 )
{
struct V_232 * V_233 = F_102 ( V_231 ) ;
struct V_61 * V_62 = V_233 -> V_62 ;
struct V_4 * V_8 = V_233 -> V_8 ;
F_103 ( ! F_104 ( & V_8 -> V_234 ) ) ;
F_16 ( V_8 -> V_10 , L_48 , V_46 , V_62 -> V_69 ) ;
if ( V_233 -> type == V_235 )
F_105 ( ( void V_227 * ) V_233 -> V_204 . V_225 ) ;
else
F_106 ( V_233 -> V_204 . V_205 ) ;
F_107 ( V_62 -> V_236 , V_62 -> V_44 ) ;
F_108 ( & V_233 -> V_67 ) ;
F_109 ( V_233 ) ;
}
static struct V_232 * F_110 (
struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_232 * V_233 ;
F_103 ( ! F_104 ( & V_8 -> V_234 ) ) ;
F_38 (spa_map, &acpi_desc->spa_maps, list)
if ( V_233 -> V_62 == V_62 )
return V_233 ;
return NULL ;
}
static void F_111 ( struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_232 * V_233 ;
F_112 ( & V_8 -> V_234 ) ;
V_233 = F_110 ( V_8 , V_62 ) ;
if ( V_233 )
F_113 ( & V_233 -> V_231 , F_101 ) ;
F_114 ( & V_8 -> V_234 ) ;
}
static void T_9 * F_115 ( struct V_4 * V_8 ,
struct V_61 * V_62 , enum V_237 type )
{
T_8 V_238 = V_62 -> V_236 ;
T_8 V_149 = V_62 -> V_44 ;
struct V_232 * V_233 ;
struct V_239 * V_240 ;
F_103 ( ! F_104 ( & V_8 -> V_234 ) ) ;
V_233 = F_110 ( V_8 , V_62 ) ;
if ( V_233 ) {
F_116 ( & V_233 -> V_231 ) ;
return V_233 -> V_204 . V_205 ;
}
V_233 = F_117 ( sizeof( * V_233 ) , V_66 ) ;
if ( ! V_233 )
return NULL ;
F_27 ( & V_233 -> V_67 ) ;
V_233 -> V_62 = V_62 ;
F_118 ( & V_233 -> V_231 ) ;
V_233 -> V_8 = V_8 ;
V_240 = F_119 ( V_238 , V_149 , F_120 ( V_8 -> V_10 ) ) ;
if ( ! V_240 )
goto V_241;
V_233 -> type = type ;
if ( type == V_235 )
V_233 -> V_204 . V_225 = ( void V_242 * ) F_121 ( V_238 , V_149 ,
V_243 ) ;
else
V_233 -> V_204 . V_205 = F_122 ( V_238 , V_149 ) ;
if ( ! V_233 -> V_204 . V_205 )
goto V_244;
F_28 ( & V_233 -> V_67 , & V_8 -> V_245 ) ;
return V_233 -> V_204 . V_205 ;
V_244:
F_107 ( V_238 , V_149 ) ;
V_241:
F_109 ( V_233 ) ;
return NULL ;
}
static void T_9 * F_123 ( struct V_4 * V_8 ,
struct V_61 * V_62 , enum V_237 type )
{
void T_9 * V_246 ;
F_112 ( & V_8 -> V_234 ) ;
V_246 = F_115 ( V_8 , V_62 , type ) ;
F_114 ( & V_8 -> V_234 ) ;
return V_246 ;
}
static int F_124 ( struct V_186 * V_187 ,
struct V_85 * V_86 , T_4 V_247 )
{
if ( V_86 ) {
V_187 -> V_195 = V_86 -> V_90 ;
V_187 -> V_194 = V_86 -> V_194 ;
if ( V_247 == 0 )
return - V_51 ;
V_187 -> V_196 = V_187 -> V_195 * V_247
* V_187 -> V_194 ;
}
return 0 ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_11 * V_11 , struct V_198 * V_198 )
{
struct V_248 V_140 ;
int V_28 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_28 = V_6 -> V_249 ( V_6 , V_11 , V_250 , & V_140 ,
sizeof( V_140 ) ) ;
if ( V_28 >= 0 && V_140 . V_251 == 0 )
V_198 -> V_215 = V_140 . V_140 ;
else if ( V_28 == - V_32 ) {
V_198 -> V_215 = V_216 | V_226 ;
V_28 = 0 ;
} else
V_28 = - V_51 ;
return V_28 ;
}
static int F_126 ( struct V_130 * V_130 ,
struct V_21 * V_10 )
{
struct V_5 * V_6 = F_48 ( V_130 ) ;
struct V_4 * V_8 = F_49 ( V_6 ) ;
struct V_229 * V_230 = F_127 ( V_10 ) ;
struct V_93 * V_93 ;
struct V_186 * V_187 ;
struct V_198 * V_198 ;
struct V_30 * V_30 ;
struct V_11 * V_11 ;
int V_28 ;
V_11 = F_128 ( V_230 ) ;
V_30 = F_7 ( V_11 ) ;
if ( ! V_30 || ! V_30 -> V_77 || ! V_30 -> V_82 ) {
F_16 ( V_10 , L_49 , V_46 ,
V_30 ? L_29 : L_50 ,
( V_30 && V_30 -> V_77 ) ? L_29 : L_51 ,
( V_30 && V_30 -> V_82 ) ? L_29 : L_52 ) ;
return - V_51 ;
}
V_198 = F_26 ( V_10 , sizeof( * V_198 ) , V_66 ) ;
if ( ! V_198 )
return - V_101 ;
F_129 ( V_230 , V_198 ) ;
V_198 -> V_165 = F_73 ( V_10 ) ;
V_198 -> V_222 = V_30 -> V_82 -> V_27 ;
V_187 = & V_198 -> V_187 [ V_220 ] ;
V_187 -> V_204 . V_205 = F_123 ( V_8 , V_30 -> V_109 ,
V_235 ) ;
if ( ! V_187 -> V_204 . V_205 ) {
F_16 ( V_10 , L_53 , V_46 ,
F_8 ( V_11 ) ) ;
return - V_101 ;
}
V_187 -> V_203 = V_30 -> V_82 -> V_203 ;
V_187 -> V_197 = V_30 -> V_114 -> V_173 ;
V_187 -> V_86 = V_30 -> V_115 ;
V_187 -> V_62 = V_30 -> V_109 ;
V_28 = F_124 ( V_187 , V_30 -> V_115 ,
V_30 -> V_114 -> V_247 ) ;
if ( V_28 ) {
F_16 ( V_10 , L_54 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_198 -> V_214 = V_30 -> V_77 -> V_252 ;
V_198 -> V_202 = V_30 -> V_77 -> V_253 ;
V_187 = & V_198 -> V_187 [ V_201 ] ;
V_187 -> V_204 . V_205 = F_123 ( V_8 , V_30 -> V_110 ,
V_254 ) ;
if ( ! V_187 -> V_204 . V_205 ) {
F_16 ( V_10 , L_55 , V_46 ,
F_8 ( V_11 ) ) ;
return - V_101 ;
}
V_187 -> V_203 = V_30 -> V_77 -> V_255 ;
V_187 -> V_197 = V_30 -> V_117 -> V_173 ;
V_187 -> V_86 = V_30 -> V_118 ;
V_187 -> V_62 = V_30 -> V_110 ;
V_28 = F_124 ( V_187 , V_30 -> V_118 ,
V_30 -> V_117 -> V_247 ) ;
if ( V_28 ) {
F_16 ( V_10 , L_56 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_28 = F_125 ( V_6 , V_11 , V_198 ) ;
if ( V_28 < 0 ) {
F_16 ( V_10 , L_57 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_93 = V_30 -> V_93 ;
if ( V_93 && V_93 -> V_92 -> V_95 != 0 ) {
V_198 -> V_199 = F_130 ( V_10 ,
V_93 -> V_92 -> V_256 [ 0 ] , 8 ) ;
if ( ! V_198 -> V_199 )
return - V_101 ;
}
if ( ! F_131 () && ! V_198 -> V_199 )
F_132 ( V_10 , L_58 ) ;
if ( V_187 -> V_194 == 0 )
return 0 ;
if ( ( T_3 ) V_198 -> V_214 % V_187 -> V_194
+ 8 > V_187 -> V_194 ) {
F_16 ( V_10 , L_59 ) ;
return - V_51 ;
} else if ( ( T_3 ) V_198 -> V_202 % V_187 -> V_194
+ 8 > V_187 -> V_194 ) {
F_16 ( V_10 , L_60 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_133 ( struct V_130 * V_130 ,
struct V_21 * V_10 )
{
struct V_5 * V_6 = F_48 ( V_130 ) ;
struct V_4 * V_8 = F_49 ( V_6 ) ;
struct V_229 * V_230 = F_127 ( V_10 ) ;
struct V_198 * V_198 = F_97 ( V_230 ) ;
int V_29 ;
if ( ! V_198 )
return;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_186 * V_187 = & V_198 -> V_187 [ V_29 ] ;
if ( V_187 -> V_204 . V_205 )
F_111 ( V_8 , V_187 -> V_62 ) ;
}
F_129 ( V_230 , NULL ) ;
}
static int F_134 ( struct V_4 * V_8 ,
struct V_182 * V_182 , struct V_175 * V_176 ,
struct V_70 * V_71 ,
struct V_61 * V_62 )
{
struct V_11 * V_11 = F_62 ( V_8 ,
V_71 -> V_74 ) ;
struct V_257 * V_258 ;
struct V_30 * V_30 ;
int V_259 = 0 ;
if ( ! V_11 ) {
F_21 ( V_8 -> V_10 , L_61 ,
V_62 -> V_69 , V_71 -> V_74 ) ;
return - V_112 ;
}
V_182 -> V_11 = V_11 ;
switch ( F_24 ( V_62 ) ) {
case V_54 :
case V_53 :
V_182 -> V_238 = V_71 -> V_236 ;
V_182 -> V_203 = V_71 -> V_260 ;
break;
case V_55 :
V_30 = F_7 ( V_11 ) ;
if ( ! V_30 || ! V_30 -> V_82 ) {
F_16 ( V_8 -> V_10 , L_62 ,
V_62 -> V_69 , F_8 ( V_11 ) ) ;
} else {
V_182 -> V_203 = V_30 -> V_82 -> V_261 ;
V_182 -> V_238 = V_30 -> V_82 -> V_262 ;
V_176 -> V_263 = V_30 -> V_82 -> V_80 ;
V_259 = 1 ;
}
V_176 -> V_182 = V_182 ;
V_176 -> V_166 = V_259 ;
V_258 = F_135 ( V_176 ) ;
V_258 -> V_264 = F_126 ;
V_258 -> V_265 = F_133 ;
V_258 -> V_266 = V_8 -> V_267 ;
if ( ! F_136 ( V_8 -> V_130 , V_176 ) )
return - V_101 ;
break;
}
return 0 ;
}
static int F_137 ( struct V_4 * V_8 ,
struct V_65 * V_65 )
{
static struct V_182 V_268 [ V_269 ] ;
struct V_61 * V_62 = V_65 -> V_62 ;
struct V_257 V_258 ;
struct V_175 * V_176 ;
struct V_72 * V_72 ;
struct V_130 * V_130 ;
struct V_239 V_240 ;
int V_39 = 0 , V_28 ;
if ( V_62 -> V_69 == 0 ) {
F_16 ( V_8 -> V_10 , L_63 ,
V_46 ) ;
return 0 ;
}
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
memset ( & V_268 , 0 , sizeof( V_268 ) ) ;
memset ( & V_258 , 0 , sizeof( V_258 ) ) ;
V_240 . V_238 = V_62 -> V_236 ;
V_240 . V_97 = V_240 . V_238 + V_62 -> V_44 - 1 ;
V_176 = & V_258 . V_176 ;
V_176 -> V_240 = & V_240 ;
V_176 -> V_270 = V_65 ;
V_176 -> V_271 = V_272 ;
if ( V_62 -> V_140 & V_273 )
V_176 -> V_274 = F_138 (
V_62 -> V_275 ) ;
else
V_176 -> V_274 = V_276 ;
F_38 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_70 * V_71 = V_72 -> V_71 ;
struct V_182 * V_182 ;
if ( V_71 -> V_69 != V_62 -> V_69 )
continue;
if ( V_39 >= V_269 ) {
F_21 ( V_8 -> V_10 , L_64 ,
V_62 -> V_69 , V_269 ) ;
return - V_51 ;
}
V_182 = & V_268 [ V_39 ++ ] ;
V_28 = F_134 ( V_8 , V_182 , V_176 ,
V_71 , V_62 ) ;
if ( V_28 )
return V_28 ;
}
V_176 -> V_182 = V_268 ;
V_176 -> V_166 = V_39 ;
V_28 = F_78 ( V_8 , V_176 , V_62 ) ;
if ( V_28 )
return V_28 ;
V_130 = V_8 -> V_130 ;
if ( F_24 ( V_62 ) == V_54 ) {
if ( ! F_139 ( V_130 , V_176 ) )
return - V_101 ;
} else if ( F_24 ( V_62 ) == V_53 ) {
if ( ! F_140 ( V_130 , V_176 ) )
return - V_101 ;
}
return 0 ;
}
static int F_141 ( struct V_4 * V_8 )
{
struct V_65 * V_65 ;
F_38 (nfit_spa, &acpi_desc->spas, list) {
int V_28 = F_137 ( V_8 , V_65 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
int F_142 ( struct V_4 * V_8 , T_10 V_277 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
const void * V_97 ;
T_1 * V_278 ;
int V_28 ;
F_27 ( & V_8 -> V_245 ) ;
F_27 ( & V_8 -> V_68 ) ;
F_27 ( & V_8 -> V_79 ) ;
F_27 ( & V_8 -> V_84 ) ;
F_27 ( & V_8 -> V_88 ) ;
F_27 ( & V_8 -> V_94 ) ;
F_27 ( & V_8 -> V_73 ) ;
F_27 ( & V_8 -> V_113 ) ;
F_143 ( & V_8 -> V_234 ) ;
V_278 = ( T_1 * ) V_8 -> V_131 ;
V_97 = V_278 + V_277 ;
V_278 += sizeof( struct V_279 ) ;
while ( ! F_144 ( V_278 ) )
V_278 = F_34 ( V_8 , V_278 , V_97 ) ;
if ( F_145 ( V_278 ) ) {
F_16 ( V_10 , L_65 , V_46 ,
F_146 ( V_278 ) ) ;
return F_146 ( V_278 ) ;
}
if ( F_44 ( V_8 ) != 0 )
return - V_101 ;
F_71 ( V_8 ) ;
V_28 = F_67 ( V_8 ) ;
if ( V_28 )
return V_28 ;
return F_141 ( V_8 ) ;
}
static int F_147 ( struct V_7 * V_31 )
{
struct V_5 * V_6 ;
struct V_4 * V_8 ;
struct V_21 * V_10 = & V_31 -> V_10 ;
struct V_280 * V_281 ;
T_11 V_251 = V_282 ;
T_10 V_277 ;
int V_28 ;
V_251 = F_148 ( L_66 , 0 , & V_281 , & V_277 ) ;
if ( F_149 ( V_251 ) ) {
F_21 ( V_10 , L_67 ) ;
return - V_51 ;
}
V_8 = F_26 ( V_10 , sizeof( * V_8 ) , V_66 ) ;
if ( ! V_8 )
return - V_101 ;
F_150 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_131 = (struct V_279 * ) V_281 ;
V_8 -> V_267 = F_96 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_9 = L_1 ;
V_6 -> V_249 = F_6 ;
V_6 -> V_271 = V_283 ;
V_8 -> V_130 = F_151 ( V_10 , V_6 ) ;
if ( ! V_8 -> V_130 )
return - V_51 ;
V_28 = F_142 ( V_8 , V_277 ) ;
if ( V_28 ) {
F_152 ( V_8 -> V_130 ) ;
return V_28 ;
}
return 0 ;
}
static int F_153 ( struct V_7 * V_31 )
{
struct V_4 * V_8 = F_154 ( & V_31 -> V_10 ) ;
F_152 ( V_8 -> V_130 ) ;
return 0 ;
}
static T_12 int F_155 ( void )
{
F_156 ( sizeof( struct V_279 ) != 40 ) ;
F_156 ( sizeof( struct V_61 ) != 56 ) ;
F_156 ( sizeof( struct V_70 ) != 48 ) ;
F_156 ( sizeof( struct V_85 ) != 20 ) ;
F_156 ( sizeof( struct V_284 ) != 9 ) ;
F_156 ( sizeof( struct V_76 ) != 80 ) ;
F_156 ( sizeof( struct V_81 ) != 40 ) ;
F_157 ( V_285 , V_3 [ V_53 ] ) ;
F_157 ( V_286 , V_3 [ V_54 ] ) ;
F_157 ( V_287 , V_3 [ V_55 ] ) ;
F_157 ( V_288 , V_3 [ V_56 ] ) ;
F_157 ( V_289 , V_3 [ V_57 ] ) ;
F_157 ( V_290 , V_3 [ V_58 ] ) ;
F_157 ( V_291 , V_3 [ V_59 ] ) ;
F_157 ( V_292 , V_3 [ V_60 ] ) ;
F_157 ( V_293 , V_3 [ V_34 ] ) ;
F_157 ( V_294 , V_3 [ V_33 ] ) ;
return F_158 ( & V_295 ) ;
}
static T_13 void F_159 ( void )
{
F_160 ( & V_295 ) ;
}
