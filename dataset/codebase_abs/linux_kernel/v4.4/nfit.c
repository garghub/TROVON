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
struct V_65 * V_66 ,
struct V_61 * V_62 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_62 ) , V_62 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_68 * V_68 ;
F_26 (nfit_spa, &prev->spas, list) {
if ( memcmp ( V_68 -> V_62 , V_62 , V_44 ) == 0 ) {
F_27 ( & V_68 -> V_69 , & V_8 -> V_70 ) ;
return true ;
}
}
V_68 = F_28 ( V_10 , sizeof( * V_68 ) , V_71 ) ;
if ( ! V_68 )
return false ;
F_29 ( & V_68 -> V_69 ) ;
V_68 -> V_62 = V_62 ;
F_30 ( & V_68 -> V_69 , & V_8 -> V_70 ) ;
F_16 ( V_10 , L_19 , V_46 ,
V_62 -> V_72 ,
F_23 ( F_24 ( V_62 ) ) ) ;
return true ;
}
static bool F_31 ( struct V_4 * V_8 ,
struct V_65 * V_66 ,
struct V_73 * V_74 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_74 ) , V_74 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_75 * V_75 ;
F_26 (nfit_memdev, &prev->memdevs, list)
if ( memcmp ( V_75 -> V_74 , V_74 , V_44 ) == 0 ) {
F_27 ( & V_75 -> V_69 , & V_8 -> V_76 ) ;
return true ;
}
V_75 = F_28 ( V_10 , sizeof( * V_75 ) , V_71 ) ;
if ( ! V_75 )
return false ;
F_29 ( & V_75 -> V_69 ) ;
V_75 -> V_74 = V_74 ;
F_30 ( & V_75 -> V_69 , & V_8 -> V_76 ) ;
F_16 ( V_10 , L_20 ,
V_46 , V_74 -> V_77 , V_74 -> V_72 ,
V_74 -> V_78 ) ;
return true ;
}
static bool F_32 ( struct V_4 * V_8 ,
struct V_65 * V_66 ,
struct V_79 * V_80 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_80 ) , V_80 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_81 * V_81 ;
F_26 (nfit_dcr, &prev->dcrs, list)
if ( memcmp ( V_81 -> V_80 , V_80 , V_44 ) == 0 ) {
F_27 ( & V_81 -> V_69 , & V_8 -> V_82 ) ;
return true ;
}
V_81 = F_28 ( V_10 , sizeof( * V_81 ) , V_71 ) ;
if ( ! V_81 )
return false ;
F_29 ( & V_81 -> V_69 ) ;
V_81 -> V_80 = V_80 ;
F_30 ( & V_81 -> V_69 , & V_8 -> V_82 ) ;
F_16 ( V_10 , L_21 , V_46 ,
V_80 -> V_78 , V_80 -> V_83 ) ;
return true ;
}
static bool F_33 ( struct V_4 * V_8 ,
struct V_65 * V_66 ,
struct V_84 * V_85 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_85 ) , V_85 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_86 * V_86 ;
F_26 (nfit_bdw, &prev->bdws, list)
if ( memcmp ( V_86 -> V_85 , V_85 , V_44 ) == 0 ) {
F_27 ( & V_86 -> V_69 , & V_8 -> V_87 ) ;
return true ;
}
V_86 = F_28 ( V_10 , sizeof( * V_86 ) , V_71 ) ;
if ( ! V_86 )
return false ;
F_29 ( & V_86 -> V_69 ) ;
V_86 -> V_85 = V_85 ;
F_30 ( & V_86 -> V_69 , & V_8 -> V_87 ) ;
F_16 ( V_10 , L_22 , V_46 ,
V_85 -> V_78 , V_85 -> V_83 ) ;
return true ;
}
static bool F_34 ( struct V_4 * V_8 ,
struct V_65 * V_66 ,
struct V_88 * V_89 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_89 ) , V_89 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_90 * V_90 ;
F_26 (nfit_idt, &prev->idts, list)
if ( memcmp ( V_90 -> V_89 , V_89 , V_44 ) == 0 ) {
F_27 ( & V_90 -> V_69 , & V_8 -> V_91 ) ;
return true ;
}
V_90 = F_28 ( V_10 , sizeof( * V_90 ) , V_71 ) ;
if ( ! V_90 )
return false ;
F_29 ( & V_90 -> V_69 ) ;
V_90 -> V_89 = V_89 ;
F_30 ( & V_90 -> V_69 , & V_8 -> V_91 ) ;
F_16 ( V_10 , L_23 , V_46 ,
V_89 -> V_92 , V_89 -> V_93 ) ;
return true ;
}
static bool F_35 ( struct V_4 * V_8 ,
struct V_65 * V_66 ,
struct V_94 * V_95 )
{
T_5 V_44 = F_18 ( T_5 , sizeof( * V_95 ) , V_95 -> V_67 . V_44 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_96 * V_96 ;
F_26 (nfit_flush, &prev->flushes, list)
if ( memcmp ( V_96 -> V_95 , V_95 , V_44 ) == 0 ) {
F_27 ( & V_96 -> V_69 , & V_8 -> V_97 ) ;
return true ;
}
V_96 = F_28 ( V_10 , sizeof( * V_96 ) , V_71 ) ;
if ( ! V_96 )
return false ;
F_29 ( & V_96 -> V_69 ) ;
V_96 -> V_95 = V_95 ;
F_30 ( & V_96 -> V_69 , & V_8 -> V_97 ) ;
F_16 ( V_10 , L_24 , V_46 ,
V_95 -> V_77 , V_95 -> V_98 ) ;
return true ;
}
static void * F_36 ( struct V_4 * V_8 ,
struct V_65 * V_66 , void * V_99 , const void * V_100 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_101 * V_102 ;
void * V_103 = F_37 ( - V_104 ) ;
if ( V_99 >= V_100 )
return NULL ;
V_102 = V_99 ;
if ( ! V_102 -> V_44 ) {
F_38 ( V_10 , L_25 ,
V_102 -> type ) ;
return NULL ;
}
switch ( V_102 -> type ) {
case V_105 :
if ( ! F_25 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_106 :
if ( ! F_31 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_107 :
if ( ! F_32 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_108 :
if ( ! F_33 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_109 :
if ( ! F_34 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_110 :
if ( ! F_35 ( V_8 , V_66 , V_99 ) )
return V_103 ;
break;
case V_111 :
F_16 ( V_10 , L_26 , V_46 ) ;
break;
default:
F_21 ( V_10 , L_27 , V_102 -> type ) ;
break;
}
return V_99 + V_102 -> V_44 ;
}
static void F_39 ( struct V_4 * V_8 ,
struct V_30 * V_30 )
{
T_3 V_77 = F_40 ( V_30 ) -> V_77 ;
T_4 V_80 = V_30 -> V_80 -> V_78 ;
struct V_68 * V_68 ;
F_26 (nfit_spa, &acpi_desc->spas, list) {
T_4 V_72 = V_68 -> V_62 -> V_72 ;
int type = F_24 ( V_68 -> V_62 ) ;
struct V_75 * V_75 ;
if ( type != V_56 )
continue;
F_26 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_75 -> V_74 -> V_72 != V_72 )
continue;
if ( V_75 -> V_74 -> V_77 != V_77 )
continue;
if ( V_75 -> V_74 -> V_78 != V_80 )
continue;
V_30 -> V_112 = V_68 -> V_62 ;
return;
}
}
F_16 ( V_8 -> V_10 , L_28 ,
V_30 -> V_113 -> V_72 ) ;
V_30 -> V_85 = NULL ;
}
static int F_41 ( struct V_4 * V_8 ,
struct V_30 * V_30 , struct V_61 * V_62 )
{
T_4 V_80 = F_40 ( V_30 ) -> V_78 ;
struct V_75 * V_75 ;
struct V_96 * V_96 ;
struct V_81 * V_81 ;
struct V_86 * V_86 ;
struct V_90 * V_90 ;
T_4 V_114 , V_72 ;
F_26 (nfit_dcr, &acpi_desc->dcrs, list) {
if ( V_81 -> V_80 -> V_78 != V_80 )
continue;
V_30 -> V_80 = V_81 -> V_80 ;
break;
}
if ( ! V_30 -> V_80 ) {
F_16 ( V_8 -> V_10 , L_29 ,
V_62 -> V_72 , F_40 ( V_30 )
? L_30 : L_31 , V_30 -> V_80 ? L_30 : L_32 ) ;
return - V_115 ;
}
F_42 ( & V_30 -> V_69 , & V_8 -> V_116 ) ;
F_26 (nfit_bdw, &acpi_desc->bdws, list) {
if ( V_86 -> V_85 -> V_78 != V_80 )
continue;
V_30 -> V_85 = V_86 -> V_85 ;
break;
}
if ( ! V_30 -> V_85 )
return 0 ;
F_39 ( V_8 , V_30 ) ;
if ( ! V_30 -> V_112 )
return 0 ;
V_72 = V_30 -> V_112 -> V_72 ;
F_26 (nfit_memdev, &acpi_desc->memdevs, list) {
if ( V_75 -> V_74 -> V_72 != V_72 ||
V_75 -> V_74 -> V_78 != V_80 )
continue;
V_30 -> V_117 = V_75 -> V_74 ;
V_114 = V_75 -> V_74 -> V_92 ;
F_26 (nfit_idt, &acpi_desc->idts, list) {
if ( V_90 -> V_89 -> V_92 != V_114 )
continue;
V_30 -> V_118 = V_90 -> V_89 ;
break;
}
F_26 (nfit_flush, &acpi_desc->flushes, list) {
if ( V_96 -> V_95 -> V_77 !=
V_75 -> V_74 -> V_77 )
continue;
V_30 -> V_96 = V_96 ;
break;
}
break;
}
return 0 ;
}
static int F_43 ( struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_30 * V_30 , * V_119 ;
struct V_75 * V_75 ;
int type = F_24 ( V_62 ) ;
T_4 V_80 ;
switch ( type ) {
case V_55 :
case V_54 :
break;
default:
return 0 ;
}
F_26 (nfit_memdev, &acpi_desc->memdevs, list) {
int V_28 ;
if ( V_75 -> V_74 -> V_72 != V_62 -> V_72 )
continue;
V_119 = NULL ;
V_80 = V_75 -> V_74 -> V_78 ;
F_26 (nfit_mem, &acpi_desc->dimms, list)
if ( F_40 ( V_30 ) -> V_78 == V_80 ) {
V_119 = V_30 ;
break;
}
if ( V_119 )
V_30 = V_119 ;
else {
V_30 = F_28 ( V_8 -> V_10 ,
sizeof( * V_30 ) , V_71 ) ;
if ( ! V_30 )
return - V_104 ;
F_29 ( & V_30 -> V_69 ) ;
}
if ( type == V_55 ) {
struct V_90 * V_90 ;
T_4 V_114 ;
V_30 -> V_113 = V_62 ;
V_30 -> V_120 = V_75 -> V_74 ;
V_114 = V_75 -> V_74 -> V_92 ;
F_26 (nfit_idt, &acpi_desc->idts, list) {
if ( V_90 -> V_89 -> V_92 != V_114 )
continue;
V_30 -> V_121 = V_90 -> V_89 ;
break;
}
} else {
V_30 -> V_122 = V_75 -> V_74 ;
}
if ( V_119 )
continue;
V_28 = F_41 ( V_8 , V_30 , V_62 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_44 ( void * V_123 , struct V_124 * V_125 , struct V_124 * V_126 )
{
struct V_30 * V_127 = F_3 ( V_125 , F_45 ( * V_127 ) , V_69 ) ;
struct V_30 * V_128 = F_3 ( V_126 , F_45 ( * V_128 ) , V_69 ) ;
T_3 V_129 , V_130 ;
V_129 = F_40 ( V_127 ) -> V_77 ;
V_130 = F_40 ( V_128 ) -> V_77 ;
if ( V_129 < V_130 )
return - 1 ;
else if ( V_129 > V_130 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_4 * V_8 )
{
struct V_68 * V_68 ;
F_26 (nfit_spa, &acpi_desc->spas, list) {
int V_28 ;
V_28 = F_43 ( V_8 , V_68 -> V_62 ) ;
if ( V_28 )
return V_28 ;
}
F_47 ( NULL , & V_8 -> V_116 , F_44 ) ;
return 0 ;
}
static T_6 F_48 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_133 * V_133 = F_49 ( V_10 ) ;
struct V_5 * V_6 = F_50 ( V_133 ) ;
struct V_4 * V_8 = F_51 ( V_6 ) ;
return sprintf ( V_13 , L_33 , V_8 -> V_134 . V_135 ) ;
}
static struct V_73 * F_52 ( struct V_21 * V_10 )
{
struct V_11 * V_11 = F_53 ( V_10 ) ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
return F_40 ( V_30 ) ;
}
static struct V_79 * F_54 ( struct V_21 * V_10 )
{
struct V_11 * V_11 = F_53 ( V_10 ) ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
return V_30 -> V_80 ;
}
static T_6 F_55 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_73 * V_74 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_74 -> V_77 ) ;
}
static T_6 F_56 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_73 * V_74 = F_52 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_74 -> V_136 ) ;
}
static T_6 F_57 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_79 * V_80 = F_54 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_80 -> V_137 ) ;
}
static T_6 F_58 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_79 * V_80 = F_54 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_80 -> V_138 ) ;
}
static T_6 F_59 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_79 * V_80 = F_54 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_80 -> V_139 ) ;
}
static T_6 F_60 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_79 * V_80 = F_54 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_80 -> V_140 ) ;
}
static T_6 F_61 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_79 * V_80 = F_54 ( V_10 ) ;
return sprintf ( V_13 , L_34 , V_80 -> V_141 ) ;
}
static T_6 F_62 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
T_4 V_142 = F_52 ( V_10 ) -> V_142 ;
return sprintf ( V_13 , L_35 ,
V_142 & V_143 ? L_36 : L_30 ,
V_142 & V_144 ? L_37 : L_30 ,
V_142 & V_145 ? L_38 : L_30 ,
V_142 & V_146 ? L_39 : L_30 ,
V_142 & V_147 ? L_40 : L_30 ) ;
}
static T_7 F_63 ( struct V_148 * V_149 ,
struct V_150 * V_127 , int V_151 )
{
struct V_21 * V_10 = F_3 ( V_149 , struct V_21 , V_149 ) ;
if ( F_54 ( V_10 ) )
return V_127 -> V_152 ;
else
return 0 ;
}
static struct V_11 * F_64 ( struct V_4 * V_8 ,
T_3 V_77 )
{
struct V_30 * V_30 ;
F_26 (nfit_mem, &acpi_desc->dimms, list)
if ( F_40 ( V_30 ) -> V_77 == V_77 )
return V_30 -> V_11 ;
return NULL ;
}
static int F_65 ( struct V_4 * V_8 ,
struct V_30 * V_30 , T_3 V_77 )
{
struct V_7 * V_31 , * V_153 ;
struct V_21 * V_10 = V_8 -> V_10 ;
const T_1 * V_26 = F_1 ( V_33 ) ;
int V_29 ;
V_30 -> V_24 = V_8 -> V_154 ;
V_31 = F_4 ( V_8 ) ;
if ( ! V_31 )
return 0 ;
V_153 = F_66 ( V_31 , V_77 , false ) ;
V_30 -> V_31 = V_153 ;
if ( ! V_153 ) {
F_21 ( V_10 , L_41 ,
V_77 ) ;
return V_155 ? 0 : - V_115 ;
}
for ( V_29 = V_156 ; V_29 <= V_157 ; V_29 ++ )
if ( F_67 ( V_153 -> V_25 , V_26 , 1 , 1ULL << V_29 ) )
F_68 ( V_29 , & V_30 -> V_24 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_8 )
{
struct V_30 * V_30 ;
int V_158 = 0 ;
F_26 (nfit_mem, &acpi_desc->dimms, list) {
struct V_11 * V_11 ;
unsigned long V_142 = 0 ;
T_3 V_77 ;
T_4 V_159 ;
int V_28 ;
V_77 = F_40 ( V_30 ) -> V_77 ;
V_11 = F_64 ( V_8 , V_77 ) ;
if ( V_11 ) {
V_158 ++ ;
continue;
}
if ( V_30 -> V_85 && V_30 -> V_122 )
V_142 |= V_160 ;
V_159 = F_40 ( V_30 ) -> V_142 ;
if ( V_159 & V_146 )
V_142 |= V_161 ;
V_28 = F_65 ( V_8 , V_30 , V_77 ) ;
if ( V_28 )
continue;
V_11 = F_70 ( V_8 -> V_133 , V_30 ,
V_162 ,
V_142 , & V_30 -> V_24 ) ;
if ( ! V_11 )
return - V_104 ;
V_30 -> V_11 = V_11 ;
V_158 ++ ;
if ( ( V_159 & V_163 ) == 0 )
continue;
F_71 ( V_8 -> V_10 , L_42 ,
F_8 ( V_11 ) ,
V_159 & V_143 ? L_43 : L_30 ,
V_159 & V_144 ? L_44 : L_30 ,
V_159 & V_145 ? L_45 : L_30 ,
V_159 & V_146 ? L_46 : L_30 ) ;
}
return F_72 ( V_8 -> V_133 , V_158 ) ;
}
static void F_73 ( struct V_4 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
const T_1 * V_26 = F_1 ( V_34 ) ;
struct V_7 * V_31 ;
int V_29 ;
V_6 -> V_24 = V_8 -> V_164 ;
V_31 = F_4 ( V_8 ) ;
if ( ! V_31 )
return;
for ( V_29 = V_165 ; V_29 <= V_166 ; V_29 ++ )
if ( F_67 ( V_31 -> V_25 , V_26 , 1 , 1ULL << V_29 ) )
F_68 ( V_29 , & V_6 -> V_24 ) ;
}
static T_6 F_74 ( struct V_21 * V_10 ,
struct V_131 * V_132 , char * V_13 )
{
struct V_167 * V_167 = F_75 ( V_10 ) ;
struct V_68 * V_68 = F_76 ( V_167 ) ;
return sprintf ( V_13 , L_33 , V_68 -> V_62 -> V_72 ) ;
}
static T_5 F_77 ( int V_168 )
{
return sizeof( struct V_169 )
+ V_168 * sizeof( struct V_170 ) ;
}
static int F_78 ( const void * V_171 , const void * V_172 )
{
const struct V_170 * V_173 = V_171 ;
const struct V_170 * V_174 = V_172 ;
return memcmp ( & V_173 -> V_175 , & V_174 -> V_175 ,
sizeof( V_176 ) ) ;
}
static struct V_73 * F_79 (
struct V_4 * V_8 , T_4 V_72 , int V_151 )
{
struct V_75 * V_75 ;
F_26 (nfit_memdev, &acpi_desc->memdevs, list)
if ( V_75 -> V_74 -> V_72 == V_72 )
if ( V_151 -- == 0 )
return V_75 -> V_74 ;
return NULL ;
}
static int F_80 ( struct V_4 * V_8 ,
struct V_177 * V_178 ,
struct V_61 * V_62 )
{
int V_29 , V_179 = F_24 ( V_62 ) ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_180 * V_181 ;
T_4 V_182 = V_178 -> V_168 ;
struct V_169 * V_183 ;
if ( V_179 == V_54 || V_179 == V_53 )
;
else
return 0 ;
V_181 = F_28 ( V_10 , sizeof( * V_181 ) , V_71 ) ;
if ( ! V_181 )
return - V_104 ;
V_183 = F_28 ( V_10 , F_77 ( V_182 ) , V_71 ) ;
if ( ! V_183 )
return - V_104 ;
for ( V_29 = 0 ; V_29 < V_182 ; V_29 ++ ) {
struct V_184 * V_184 = & V_178 -> V_184 [ V_29 ] ;
struct V_170 * V_185 = & V_183 -> V_186 [ V_29 ] ;
struct V_11 * V_11 = V_184 -> V_11 ;
struct V_30 * V_30 = F_7 ( V_11 ) ;
struct V_73 * V_74 = F_79 ( V_8 ,
V_62 -> V_72 , V_29 ) ;
if ( ! V_74 || ! V_30 -> V_80 ) {
F_21 ( V_10 , L_47 , V_46 ) ;
return - V_115 ;
}
V_185 -> V_175 = V_74 -> V_175 ;
V_185 -> V_141 = V_30 -> V_80 -> V_141 ;
}
F_81 ( & V_183 -> V_186 [ 0 ] , V_182 , sizeof( struct V_170 ) ,
F_78 , NULL ) ;
V_181 -> V_187 = F_82 ( V_183 , F_77 ( V_182 ) , 0 ) ;
V_178 -> V_181 = V_181 ;
F_83 ( V_10 , V_183 ) ;
return 0 ;
}
static V_176 F_84 ( V_176 V_27 , struct V_188 * V_189 )
{
struct V_88 * V_89 = V_189 -> V_89 ;
T_3 V_190 , V_191 , V_192 ;
V_176 V_193 , V_194 , V_195 ;
V_193 = F_85 ( V_27 , V_189 -> V_196 , & V_190 ) ;
V_194 = F_85 ( V_193 , V_189 -> V_197 , & V_191 ) ;
V_192 = V_89 -> V_192 [ V_191 ]
* V_189 -> V_196 ;
V_195 = V_194 * V_189 -> V_198 ;
return V_189 -> V_199 + V_192 + V_195 + V_190 ;
}
static void F_86 ( struct V_200 * V_200 )
{
if ( V_200 -> V_201 ) {
F_87 () ;
F_88 ( 1 , V_200 -> V_201 ) ;
F_87 () ;
} else
F_89 () ;
}
static T_3 F_90 ( struct V_200 * V_200 , unsigned int V_202 )
{
struct V_188 * V_189 = & V_200 -> V_189 [ V_203 ] ;
V_176 V_27 = V_200 -> V_204 + V_189 -> V_205 * V_202 ;
if ( V_189 -> V_197 )
V_27 = F_84 ( V_27 , V_189 ) ;
return F_91 ( V_189 -> V_206 . V_207 + V_27 ) ;
}
static void F_92 ( struct V_200 * V_200 , unsigned int V_202 ,
T_8 V_208 , unsigned int V_209 , unsigned int V_210 )
{
V_176 V_12 , V_27 ;
struct V_188 * V_189 = & V_200 -> V_189 [ V_203 ] ;
enum {
V_211 = ( 1ULL << 48 ) - 1 ,
V_212 = 48 ,
V_213 = ( 1ULL << 8 ) - 1 ,
V_214 = 56 ,
};
V_12 = ( V_208 >> V_215 ) & V_211 ;
V_209 = V_209 >> V_215 ;
V_12 |= ( ( V_176 ) V_209 & V_213 ) << V_212 ;
V_12 |= ( ( V_176 ) V_210 ) << V_214 ;
V_27 = V_200 -> V_216 + V_189 -> V_205 * V_202 ;
if ( V_189 -> V_197 )
V_27 = F_84 ( V_27 , V_189 ) ;
F_88 ( V_12 , V_189 -> V_206 . V_207 + V_27 ) ;
F_86 ( V_200 ) ;
if ( V_200 -> V_217 & V_218 )
F_93 ( V_189 -> V_206 . V_207 + V_27 ) ;
}
static int F_94 ( struct V_200 * V_200 ,
T_8 V_208 , void * V_219 , T_5 V_209 , int V_220 ,
unsigned int V_221 )
{
struct V_188 * V_189 = & V_200 -> V_189 [ V_222 ] ;
unsigned int V_223 = 0 ;
V_176 V_199 ;
int V_28 ;
V_199 = V_200 -> V_224 + V_208 % V_225
+ V_221 * V_189 -> V_205 ;
F_92 ( V_200 , V_221 , V_208 , V_209 , V_220 ) ;
while ( V_209 ) {
unsigned int V_226 ;
V_176 V_27 ;
if ( V_189 -> V_197 ) {
T_3 V_192 ;
V_27 = F_84 ( V_199 + V_223 ,
V_189 ) ;
F_85 ( V_27 , V_189 -> V_196 , & V_192 ) ;
V_226 = F_18 ( T_5 , V_209 , V_189 -> V_196 - V_192 ) ;
} else {
V_27 = V_199 + V_200 -> V_224 ;
V_226 = V_209 ;
}
if ( V_220 )
F_95 ( V_189 -> V_206 . V_227 + V_27 ,
V_219 + V_223 , V_226 ) ;
else {
if ( V_200 -> V_217 & V_228 )
F_96 ( ( void V_229 * )
V_189 -> V_206 . V_227 + V_27 , V_226 ) ;
F_97 ( V_219 + V_223 ,
V_189 -> V_206 . V_227 + V_27 , V_226 ) ;
}
V_223 += V_226 ;
V_209 -= V_226 ;
}
if ( V_220 )
F_86 ( V_200 ) ;
V_28 = F_90 ( V_200 , V_221 ) ? - V_230 : 0 ;
return V_28 ;
}
static int F_98 ( struct V_231 * V_232 ,
T_8 V_208 , void * V_219 , V_176 V_209 , int V_220 )
{
struct V_200 * V_200 = F_99 ( V_232 ) ;
struct V_188 * V_189 = & V_200 -> V_189 [ V_222 ] ;
struct V_167 * V_167 = V_200 -> V_167 ;
unsigned int V_221 , V_223 = 0 ;
int V_28 = 0 ;
V_221 = F_100 ( V_167 ) ;
while ( V_209 ) {
V_176 V_226 = F_101 ( V_209 , V_189 -> V_205 ) ;
V_28 = F_94 ( V_200 , V_208 + V_223 ,
V_219 + V_223 , V_226 , V_220 , V_221 ) ;
if ( V_28 )
break;
V_223 += V_226 ;
V_209 -= V_226 ;
}
F_102 ( V_167 , V_221 ) ;
return V_28 ;
}
static void F_103 ( struct V_233 * V_233 )
{
struct V_234 * V_235 = F_104 ( V_233 ) ;
struct V_61 * V_62 = V_235 -> V_62 ;
struct V_4 * V_8 = V_235 -> V_8 ;
F_105 ( ! F_106 ( & V_8 -> V_236 ) ) ;
F_16 ( V_8 -> V_10 , L_48 , V_46 , V_62 -> V_72 ) ;
if ( V_235 -> type == V_237 )
F_107 ( ( void V_229 * ) V_235 -> V_206 . V_227 ) ;
else
F_108 ( V_235 -> V_206 . V_207 ) ;
F_109 ( V_62 -> V_238 , V_62 -> V_44 ) ;
F_110 ( & V_235 -> V_69 ) ;
F_111 ( V_235 ) ;
}
static struct V_234 * F_112 (
struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_234 * V_235 ;
F_105 ( ! F_106 ( & V_8 -> V_236 ) ) ;
F_26 (spa_map, &acpi_desc->spa_maps, list)
if ( V_235 -> V_62 == V_62 )
return V_235 ;
return NULL ;
}
static void F_113 ( struct V_4 * V_8 ,
struct V_61 * V_62 )
{
struct V_234 * V_235 ;
F_114 ( & V_8 -> V_236 ) ;
V_235 = F_112 ( V_8 , V_62 ) ;
if ( V_235 )
F_115 ( & V_235 -> V_233 , F_103 ) ;
F_116 ( & V_8 -> V_236 ) ;
}
static void T_9 * F_117 ( struct V_4 * V_8 ,
struct V_61 * V_62 , enum V_239 type )
{
T_8 V_240 = V_62 -> V_238 ;
T_8 V_151 = V_62 -> V_44 ;
struct V_234 * V_235 ;
struct V_241 * V_242 ;
F_105 ( ! F_106 ( & V_8 -> V_236 ) ) ;
V_235 = F_112 ( V_8 , V_62 ) ;
if ( V_235 ) {
F_118 ( & V_235 -> V_233 ) ;
return V_235 -> V_206 . V_207 ;
}
V_235 = F_119 ( sizeof( * V_235 ) , V_71 ) ;
if ( ! V_235 )
return NULL ;
F_29 ( & V_235 -> V_69 ) ;
V_235 -> V_62 = V_62 ;
F_120 ( & V_235 -> V_233 ) ;
V_235 -> V_8 = V_8 ;
V_242 = F_121 ( V_240 , V_151 , F_122 ( V_8 -> V_10 ) ) ;
if ( ! V_242 )
goto V_243;
V_235 -> type = type ;
if ( type == V_237 )
V_235 -> V_206 . V_227 = ( void V_244 * ) F_123 ( V_240 , V_151 ,
V_245 ) ;
else
V_235 -> V_206 . V_207 = F_124 ( V_240 , V_151 ) ;
if ( ! V_235 -> V_206 . V_207 )
goto V_246;
F_30 ( & V_235 -> V_69 , & V_8 -> V_247 ) ;
return V_235 -> V_206 . V_207 ;
V_246:
F_109 ( V_240 , V_151 ) ;
V_243:
F_111 ( V_235 ) ;
return NULL ;
}
static void T_9 * F_125 ( struct V_4 * V_8 ,
struct V_61 * V_62 , enum V_239 type )
{
void T_9 * V_248 ;
F_114 ( & V_8 -> V_236 ) ;
V_248 = F_117 ( V_8 , V_62 , type ) ;
F_116 ( & V_8 -> V_236 ) ;
return V_248 ;
}
static int F_126 ( struct V_188 * V_189 ,
struct V_88 * V_89 , T_4 V_249 )
{
if ( V_89 ) {
V_189 -> V_197 = V_89 -> V_93 ;
V_189 -> V_196 = V_89 -> V_196 ;
if ( V_249 == 0 )
return - V_51 ;
V_189 -> V_198 = V_189 -> V_197 * V_249
* V_189 -> V_196 ;
}
return 0 ;
}
static int F_127 ( struct V_5 * V_6 ,
struct V_11 * V_11 , struct V_200 * V_200 )
{
struct V_250 V_142 ;
int V_28 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_28 = V_6 -> V_251 ( V_6 , V_11 , V_252 , & V_142 ,
sizeof( V_142 ) ) ;
if ( V_28 >= 0 && V_142 . V_253 == 0 )
V_200 -> V_217 = V_142 . V_142 ;
else if ( V_28 == - V_32 ) {
V_200 -> V_217 = V_218 | V_228 ;
V_28 = 0 ;
} else
V_28 = - V_51 ;
return V_28 ;
}
static int F_128 ( struct V_133 * V_133 ,
struct V_21 * V_10 )
{
struct V_5 * V_6 = F_50 ( V_133 ) ;
struct V_4 * V_8 = F_51 ( V_6 ) ;
struct V_231 * V_232 = F_129 ( V_10 ) ;
struct V_96 * V_96 ;
struct V_188 * V_189 ;
struct V_200 * V_200 ;
struct V_30 * V_30 ;
struct V_11 * V_11 ;
int V_28 ;
V_11 = F_130 ( V_232 ) ;
V_30 = F_7 ( V_11 ) ;
if ( ! V_30 || ! V_30 -> V_80 || ! V_30 -> V_85 ) {
F_16 ( V_10 , L_49 , V_46 ,
V_30 ? L_30 : L_50 ,
( V_30 && V_30 -> V_80 ) ? L_30 : L_51 ,
( V_30 && V_30 -> V_85 ) ? L_30 : L_52 ) ;
return - V_51 ;
}
V_200 = F_28 ( V_10 , sizeof( * V_200 ) , V_71 ) ;
if ( ! V_200 )
return - V_104 ;
F_131 ( V_232 , V_200 ) ;
V_200 -> V_167 = F_75 ( V_10 ) ;
V_200 -> V_224 = V_30 -> V_85 -> V_27 ;
V_189 = & V_200 -> V_189 [ V_222 ] ;
V_189 -> V_206 . V_207 = F_125 ( V_8 , V_30 -> V_112 ,
V_237 ) ;
if ( ! V_189 -> V_206 . V_207 ) {
F_16 ( V_10 , L_53 , V_46 ,
F_8 ( V_11 ) ) ;
return - V_104 ;
}
V_189 -> V_205 = V_30 -> V_85 -> V_205 ;
V_189 -> V_199 = V_30 -> V_117 -> V_175 ;
V_189 -> V_89 = V_30 -> V_118 ;
V_189 -> V_62 = V_30 -> V_112 ;
V_28 = F_126 ( V_189 , V_30 -> V_118 ,
V_30 -> V_117 -> V_249 ) ;
if ( V_28 ) {
F_16 ( V_10 , L_54 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_200 -> V_216 = V_30 -> V_80 -> V_254 ;
V_200 -> V_204 = V_30 -> V_80 -> V_255 ;
V_189 = & V_200 -> V_189 [ V_203 ] ;
V_189 -> V_206 . V_207 = F_125 ( V_8 , V_30 -> V_113 ,
V_256 ) ;
if ( ! V_189 -> V_206 . V_207 ) {
F_16 ( V_10 , L_55 , V_46 ,
F_8 ( V_11 ) ) ;
return - V_104 ;
}
V_189 -> V_205 = V_30 -> V_80 -> V_257 ;
V_189 -> V_199 = V_30 -> V_120 -> V_175 ;
V_189 -> V_89 = V_30 -> V_121 ;
V_189 -> V_62 = V_30 -> V_113 ;
V_28 = F_126 ( V_189 , V_30 -> V_121 ,
V_30 -> V_120 -> V_249 ) ;
if ( V_28 ) {
F_16 ( V_10 , L_56 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_28 = F_127 ( V_6 , V_11 , V_200 ) ;
if ( V_28 < 0 ) {
F_16 ( V_10 , L_57 ,
V_46 , F_8 ( V_11 ) ) ;
return V_28 ;
}
V_96 = V_30 -> V_96 ;
if ( V_96 && V_96 -> V_95 -> V_98 != 0 ) {
V_200 -> V_201 = F_132 ( V_10 ,
V_96 -> V_95 -> V_258 [ 0 ] , 8 ) ;
if ( ! V_200 -> V_201 )
return - V_104 ;
}
if ( ! F_133 () && ! V_200 -> V_201 )
F_38 ( V_10 , L_58 ) ;
if ( V_189 -> V_196 == 0 )
return 0 ;
if ( ( T_3 ) V_200 -> V_216 % V_189 -> V_196
+ 8 > V_189 -> V_196 ) {
F_16 ( V_10 , L_59 ) ;
return - V_51 ;
} else if ( ( T_3 ) V_200 -> V_204 % V_189 -> V_196
+ 8 > V_189 -> V_196 ) {
F_16 ( V_10 , L_60 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_134 ( struct V_133 * V_133 ,
struct V_21 * V_10 )
{
struct V_5 * V_6 = F_50 ( V_133 ) ;
struct V_4 * V_8 = F_51 ( V_6 ) ;
struct V_231 * V_232 = F_129 ( V_10 ) ;
struct V_200 * V_200 = F_99 ( V_232 ) ;
int V_29 ;
if ( ! V_200 )
return;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_188 * V_189 = & V_200 -> V_189 [ V_29 ] ;
if ( V_189 -> V_206 . V_207 )
F_113 ( V_8 , V_189 -> V_62 ) ;
}
F_131 ( V_232 , NULL ) ;
}
static int F_135 ( struct V_4 * V_8 ,
struct V_184 * V_184 , struct V_177 * V_178 ,
struct V_73 * V_74 ,
struct V_61 * V_62 )
{
struct V_11 * V_11 = F_64 ( V_8 ,
V_74 -> V_77 ) ;
struct V_259 * V_260 ;
struct V_30 * V_30 ;
int V_261 = 0 ;
if ( ! V_11 ) {
F_21 ( V_8 -> V_10 , L_61 ,
V_62 -> V_72 , V_74 -> V_77 ) ;
return - V_115 ;
}
V_184 -> V_11 = V_11 ;
switch ( F_24 ( V_62 ) ) {
case V_54 :
case V_53 :
V_184 -> V_240 = V_74 -> V_238 ;
V_184 -> V_205 = V_74 -> V_262 ;
break;
case V_55 :
V_30 = F_7 ( V_11 ) ;
if ( ! V_30 || ! V_30 -> V_85 ) {
F_16 ( V_8 -> V_10 , L_62 ,
V_62 -> V_72 , F_8 ( V_11 ) ) ;
} else {
V_184 -> V_205 = V_30 -> V_85 -> V_263 ;
V_184 -> V_240 = V_30 -> V_85 -> V_264 ;
V_178 -> V_265 = V_30 -> V_85 -> V_83 ;
V_261 = 1 ;
}
V_178 -> V_184 = V_184 ;
V_178 -> V_168 = V_261 ;
V_260 = F_136 ( V_178 ) ;
V_260 -> V_266 = F_128 ;
V_260 -> V_267 = F_134 ;
V_260 -> V_268 = V_8 -> V_269 ;
if ( ! F_137 ( V_8 -> V_133 , V_178 ) )
return - V_104 ;
break;
}
return 0 ;
}
static int F_138 ( struct V_4 * V_8 ,
struct V_68 * V_68 )
{
static struct V_184 V_270 [ V_271 ] ;
struct V_61 * V_62 = V_68 -> V_62 ;
struct V_259 V_260 ;
struct V_177 * V_178 ;
struct V_75 * V_75 ;
struct V_133 * V_133 ;
struct V_241 V_242 ;
int V_39 = 0 , V_28 ;
if ( V_68 -> V_272 )
return 0 ;
if ( V_62 -> V_72 == 0 ) {
F_16 ( V_8 -> V_10 , L_63 ,
V_46 ) ;
return 0 ;
}
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
memset ( & V_260 , 0 , sizeof( V_260 ) ) ;
V_242 . V_240 = V_62 -> V_238 ;
V_242 . V_100 = V_242 . V_240 + V_62 -> V_44 - 1 ;
V_178 = & V_260 . V_178 ;
V_178 -> V_242 = & V_242 ;
V_178 -> V_273 = V_68 ;
V_178 -> V_274 = V_275 ;
if ( V_62 -> V_142 & V_276 )
V_178 -> V_277 = F_139 (
V_62 -> V_278 ) ;
else
V_178 -> V_277 = V_279 ;
F_26 (nfit_memdev, &acpi_desc->memdevs, list) {
struct V_73 * V_74 = V_75 -> V_74 ;
struct V_184 * V_184 ;
if ( V_74 -> V_72 != V_62 -> V_72 )
continue;
if ( V_39 >= V_271 ) {
F_21 ( V_8 -> V_10 , L_64 ,
V_62 -> V_72 , V_271 ) ;
return - V_51 ;
}
V_184 = & V_270 [ V_39 ++ ] ;
V_28 = F_135 ( V_8 , V_184 , V_178 ,
V_74 , V_62 ) ;
if ( V_28 )
return V_28 ;
}
V_178 -> V_184 = V_270 ;
V_178 -> V_168 = V_39 ;
V_28 = F_80 ( V_8 , V_178 , V_62 ) ;
if ( V_28 )
return V_28 ;
V_133 = V_8 -> V_133 ;
if ( F_24 ( V_62 ) == V_54 ) {
if ( ! F_140 ( V_133 , V_178 ) )
return - V_104 ;
} else if ( F_24 ( V_62 ) == V_53 ) {
if ( ! F_141 ( V_133 , V_178 ) )
return - V_104 ;
}
V_68 -> V_272 = 1 ;
return 0 ;
}
static int F_142 ( struct V_4 * V_8 )
{
struct V_68 * V_68 ;
F_26 (nfit_spa, &acpi_desc->spas, list) {
int V_28 = F_138 ( V_8 , V_68 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_143 ( struct V_4 * V_8 ,
struct V_65 * V_66 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
if ( ! F_144 ( & V_66 -> V_70 ) ||
! F_144 ( & V_66 -> V_76 ) ||
! F_144 ( & V_66 -> V_82 ) ||
! F_144 ( & V_66 -> V_87 ) ||
! F_144 ( & V_66 -> V_91 ) ||
! F_144 ( & V_66 -> V_97 ) ) {
F_21 ( V_10 , L_65 ) ;
return - V_51 ;
}
return 0 ;
}
int F_145 ( struct V_4 * V_8 , T_10 V_280 )
{
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_65 V_66 ;
const void * V_100 ;
T_1 * V_281 ;
int V_28 ;
F_114 ( & V_8 -> V_282 ) ;
F_29 ( & V_66 . V_70 ) ;
F_29 ( & V_66 . V_76 ) ;
F_29 ( & V_66 . V_82 ) ;
F_29 ( & V_66 . V_87 ) ;
F_29 ( & V_66 . V_91 ) ;
F_29 ( & V_66 . V_97 ) ;
F_146 ( & V_66 . V_70 , & V_8 -> V_70 ,
V_8 -> V_70 . V_66 ) ;
F_146 ( & V_66 . V_76 , & V_8 -> V_76 ,
V_8 -> V_76 . V_66 ) ;
F_146 ( & V_66 . V_82 , & V_8 -> V_82 ,
V_8 -> V_82 . V_66 ) ;
F_146 ( & V_66 . V_87 , & V_8 -> V_87 ,
V_8 -> V_87 . V_66 ) ;
F_146 ( & V_66 . V_91 , & V_8 -> V_91 ,
V_8 -> V_91 . V_66 ) ;
F_146 ( & V_66 . V_97 , & V_8 -> V_97 ,
V_8 -> V_97 . V_66 ) ;
V_281 = ( T_1 * ) V_8 -> V_283 ;
V_100 = V_281 + V_280 ;
while ( ! F_147 ( V_281 ) )
V_281 = F_36 ( V_8 , & V_66 , V_281 , V_100 ) ;
if ( F_148 ( V_281 ) ) {
F_16 ( V_10 , L_66 , V_46 ,
F_149 ( V_281 ) ) ;
V_28 = F_149 ( V_281 ) ;
goto V_284;
}
V_28 = F_143 ( V_8 , & V_66 ) ;
if ( V_28 )
goto V_284;
if ( F_46 ( V_8 ) != 0 ) {
V_28 = - V_104 ;
goto V_284;
}
F_73 ( V_8 ) ;
V_28 = F_69 ( V_8 ) ;
if ( V_28 )
goto V_284;
V_28 = F_142 ( V_8 ) ;
V_284:
F_116 ( & V_8 -> V_282 ) ;
return V_28 ;
}
static struct V_4 * F_150 ( struct V_7 * V_31 )
{
struct V_5 * V_6 ;
struct V_4 * V_8 ;
struct V_21 * V_10 = & V_31 -> V_10 ;
V_8 = F_28 ( V_10 , sizeof( * V_8 ) , V_71 ) ;
if ( ! V_8 )
return F_37 ( - V_104 ) ;
F_151 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_269 = F_98 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_9 = L_1 ;
V_6 -> V_251 = F_6 ;
V_6 -> V_274 = V_285 ;
V_8 -> V_133 = F_152 ( V_10 , V_6 ) ;
if ( ! V_8 -> V_133 ) {
F_83 ( V_10 , V_8 ) ;
return F_37 ( - V_51 ) ;
}
F_29 ( & V_8 -> V_247 ) ;
F_29 ( & V_8 -> V_70 ) ;
F_29 ( & V_8 -> V_82 ) ;
F_29 ( & V_8 -> V_87 ) ;
F_29 ( & V_8 -> V_91 ) ;
F_29 ( & V_8 -> V_97 ) ;
F_29 ( & V_8 -> V_76 ) ;
F_29 ( & V_8 -> V_116 ) ;
F_153 ( & V_8 -> V_236 ) ;
F_153 ( & V_8 -> V_282 ) ;
return V_8 ;
}
static int F_154 ( struct V_7 * V_31 )
{
struct V_286 V_13 = { V_287 , NULL } ;
struct V_4 * V_8 ;
struct V_21 * V_10 = & V_31 -> V_10 ;
struct V_288 * V_289 ;
T_11 V_253 = V_290 ;
T_10 V_280 ;
int V_28 ;
V_253 = F_155 ( L_67 , 0 , & V_289 , & V_280 ) ;
if ( F_156 ( V_253 ) ) {
F_16 ( V_10 , L_68 ) ;
return 0 ;
}
V_8 = F_150 ( V_31 ) ;
if ( F_148 ( V_8 ) ) {
F_21 ( V_10 , L_69 ,
V_46 , F_149 ( V_8 ) ) ;
return F_149 ( V_8 ) ;
}
V_8 -> V_134 = * V_289 ;
V_8 -> V_283 = ( void * ) V_289 + sizeof( struct V_291 ) ;
V_280 -= sizeof( struct V_291 ) ;
V_253 = F_157 ( V_31 -> V_25 , L_70 , NULL , & V_13 ) ;
if ( F_158 ( V_253 ) && V_13 . V_44 > 0 ) {
union V_17 * V_292 ;
V_292 = V_13 . V_43 ;
if ( V_292 -> type == V_41 ) {
V_8 -> V_283 =
(struct V_101 * ) V_292 -> V_42 . V_43 ;
V_280 = V_292 -> V_42 . V_44 ;
} else
F_16 ( V_10 , L_71 ,
V_46 , ( int ) V_292 -> type ) ;
}
V_28 = F_145 ( V_8 , V_280 ) ;
if ( V_28 ) {
F_159 ( V_8 -> V_133 ) ;
return V_28 ;
}
return 0 ;
}
static int F_160 ( struct V_7 * V_31 )
{
struct V_4 * V_8 = F_161 ( & V_31 -> V_10 ) ;
F_159 ( V_8 -> V_133 ) ;
return 0 ;
}
static void F_162 ( struct V_7 * V_31 , T_3 V_293 )
{
struct V_4 * V_8 = F_161 ( & V_31 -> V_10 ) ;
struct V_286 V_13 = { V_287 , NULL } ;
struct V_101 * V_294 ;
union V_17 * V_292 ;
struct V_21 * V_10 = & V_31 -> V_10 ;
T_11 V_253 ;
int V_295 ;
F_16 ( V_10 , L_72 , V_46 , V_293 ) ;
F_163 ( V_10 ) ;
if ( ! V_10 -> V_296 ) {
F_16 ( V_10 , L_73 , V_46 ) ;
goto V_284;
}
if ( ! V_8 ) {
V_8 = F_150 ( V_31 ) ;
if ( F_148 ( V_8 ) ) {
F_21 ( V_10 , L_69 ,
V_46 , F_149 ( V_8 ) ) ;
goto V_284;
}
}
V_253 = F_157 ( V_31 -> V_25 , L_70 , NULL , & V_13 ) ;
if ( F_156 ( V_253 ) ) {
F_21 ( V_10 , L_74 ) ;
goto V_284;
}
V_294 = V_8 -> V_283 ;
V_292 = V_13 . V_43 ;
if ( V_292 -> type == V_41 ) {
V_8 -> V_283 =
(struct V_101 * ) V_292 -> V_42 . V_43 ;
V_295 = F_145 ( V_8 , V_292 -> V_42 . V_44 ) ;
if ( V_295 ) {
V_8 -> V_283 = V_294 ;
F_21 ( V_10 , L_75 ) ;
}
} else {
F_21 ( V_10 , L_76 ) ;
}
F_111 ( V_13 . V_43 ) ;
V_284:
F_164 ( V_10 ) ;
}
static T_12 int F_165 ( void )
{
F_166 ( sizeof( struct V_291 ) != 40 ) ;
F_166 ( sizeof( struct V_61 ) != 56 ) ;
F_166 ( sizeof( struct V_73 ) != 48 ) ;
F_166 ( sizeof( struct V_88 ) != 20 ) ;
F_166 ( sizeof( struct V_297 ) != 9 ) ;
F_166 ( sizeof( struct V_79 ) != 80 ) ;
F_166 ( sizeof( struct V_84 ) != 40 ) ;
F_167 ( V_298 , V_3 [ V_53 ] ) ;
F_167 ( V_299 , V_3 [ V_54 ] ) ;
F_167 ( V_300 , V_3 [ V_55 ] ) ;
F_167 ( V_301 , V_3 [ V_56 ] ) ;
F_167 ( V_302 , V_3 [ V_57 ] ) ;
F_167 ( V_303 , V_3 [ V_58 ] ) ;
F_167 ( V_304 , V_3 [ V_59 ] ) ;
F_167 ( V_305 , V_3 [ V_60 ] ) ;
F_167 ( V_306 , V_3 [ V_34 ] ) ;
F_167 ( V_307 , V_3 [ V_33 ] ) ;
return F_168 ( & V_308 ) ;
}
static T_13 void F_169 ( void )
{
F_170 ( & V_308 ) ;
}
