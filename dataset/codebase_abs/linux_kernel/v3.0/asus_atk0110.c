static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_2 V_8 ;
int V_9 ;
V_9 = F_3 ( V_7 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> type == V_10 )
V_8 *= 100 ;
return sprintf ( V_5 , L_1 , V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_5 ( V_4 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_11 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_7 ( V_4 ) ;
T_2 V_8 = V_7 -> V_12 ;
if ( V_7 -> type == V_10 )
V_8 *= 100 ;
return sprintf ( V_5 , L_3 , V_8 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_9 ( V_4 ) ;
T_2 V_8 = V_7 -> V_13 ;
if ( V_7 -> type == V_10 )
V_8 *= 100 ;
return sprintf ( V_5 , L_3 , V_8 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_4 ) ;
}
static void F_11 ( struct V_3 * V_4 , char * V_14 ,
T_3 V_15 )
{
F_12 ( & V_4 -> V_4 ) ;
V_4 -> V_4 . V_14 = V_14 ;
V_4 -> V_4 . V_16 = 0444 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_17 = NULL ;
}
static union V_18 * F_13 ( struct V_19 * V_20 ,
union V_18 * V_21 ,
enum V_22 V_23 )
{
bool V_24 = V_20 -> V_25 ;
int V_26 ;
switch ( V_23 ) {
case V_27 :
V_26 = V_24 ? V_28 : V_29 ;
break;
case V_30 :
V_26 = V_24 ? V_31 : V_32 ;
break;
case V_33 :
V_26 = V_24 ? V_34 :
V_35 ;
break;
case V_36 :
V_26 = V_24 ? V_37 :
V_38 ;
break;
case V_39 :
V_26 = V_24 ? V_40 :
V_41 ;
break;
default:
return NULL ;
}
return & V_21 -> V_42 . V_43 [ V_26 ] ;
}
static int F_14 ( struct V_19 * V_20 , union V_18 * V_44 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_46 ;
bool V_24 = V_20 -> V_25 ;
int const V_47 = V_24 ? V_48 :
V_49 ;
if ( V_44 -> type != V_50 ) {
F_15 ( V_2 , L_5 , V_44 -> type ) ;
return - V_51 ;
}
if ( V_44 -> V_42 . V_52 != V_47 ) {
F_15 ( V_2 , L_6 ,
V_44 -> V_42 . V_52 , V_47 ) ;
return - V_51 ;
}
V_46 = F_13 ( V_20 , V_44 , V_27 ) ;
if ( V_46 -> type != V_53 ) {
F_15 ( V_2 , L_7 , V_46 -> type ) ;
return - V_51 ;
}
V_46 = F_13 ( V_20 , V_44 , V_30 ) ;
if ( V_46 -> type != V_54 ) {
F_15 ( V_2 , L_8 , V_46 -> type ) ;
return - V_51 ;
}
#if 0
tmp = &obj->package.elements[HWMON_PACK_UNK1];
if (tmp->type != ACPI_TYPE_INTEGER) {
dev_warn(dev, "Invalid type (unk1): %d\n", tmp->type);
return -EINVAL;
}
tmp = &obj->package.elements[HWMON_PACK_UNK2];
if (tmp->type != ACPI_TYPE_INTEGER) {
dev_warn(dev, "Invalid type (unk2): %d\n", tmp->type);
return -EINVAL;
}
#endif
V_46 = F_13 ( V_20 , V_44 , V_33 ) ;
if ( V_46 -> type != V_53 ) {
F_15 ( V_2 , L_9 , V_46 -> type ) ;
return - V_51 ;
}
V_46 = F_13 ( V_20 , V_44 , V_36 ) ;
if ( V_46 -> type != V_53 ) {
F_15 ( V_2 , L_10 , V_46 -> type ) ;
return - V_51 ;
}
V_46 = F_13 ( V_20 , V_44 , V_39 ) ;
if ( V_46 -> type != V_53 ) {
F_15 ( V_2 , L_11 , V_46 -> type ) ;
return - V_51 ;
}
F_16 ( V_20 , V_44 ) ;
return 0 ;
}
static char const * F_17 ( union V_18 * V_55 )
{
T_2 type = V_55 -> integer . V_8 & V_56 ;
char const * V_57 ;
switch ( type ) {
case V_58 :
V_57 = L_12 ;
break;
case V_10 :
V_57 = L_13 ;
break;
case V_59 :
V_57 = L_14 ;
break;
default:
V_57 = L_15 ;
break;
}
return V_57 ;
}
static void F_16 ( struct V_19 * V_20 , union V_18 * V_44 )
{
#ifdef F_18
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_55 ;
union V_18 * V_14 ;
union V_18 * V_12 ;
union V_18 * V_13 ;
union V_18 * V_60 ;
char const * V_57 ;
V_55 = F_13 ( V_20 , V_44 , V_27 ) ;
V_14 = F_13 ( V_20 , V_44 , V_30 ) ;
V_12 = F_13 ( V_20 , V_44 , V_33 ) ;
V_13 = F_13 ( V_20 , V_44 , V_36 ) ;
V_60 = F_13 ( V_20 , V_44 , V_39 ) ;
V_57 = F_17 ( V_55 ) ;
F_19 ( V_2 , L_16 , V_57 ,
V_55 -> integer . V_8 ,
V_14 -> string . V_61 ,
V_12 -> integer . V_8 , V_13 -> integer . V_8 ,
V_60 -> integer . V_8 ? L_17 : L_18 ) ;
#endif
}
static int F_20 ( struct V_6 * V_62 , T_2 * V_8 )
{
struct V_19 * V_20 = V_62 -> V_20 ;
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
struct V_63 V_64 ;
union V_18 V_65 ;
T_4 V_66 ;
T_5 V_67 ;
switch ( V_62 -> type ) {
case V_58 :
V_67 = V_20 -> V_68 ;
break;
case V_10 :
V_67 = V_20 -> V_69 ;
break;
case V_59 :
V_67 = V_20 -> V_70 ;
break;
default:
return - V_51 ;
}
V_65 . type = V_53 ;
V_65 . integer . V_8 = V_62 -> V_65 ;
V_64 . V_52 = 1 ;
V_64 . V_61 = & V_65 ;
V_66 = F_21 ( V_67 , NULL , & V_64 , V_8 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , L_19 , V_72 ,
F_22 ( V_66 ) ) ;
return - V_73 ;
}
return 0 ;
}
static union V_18 * F_23 ( struct V_19 * V_20 , T_6 V_74 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
struct V_75 V_5 ;
T_4 V_76 ;
struct V_63 V_64 ;
union V_18 V_65 ;
union V_18 * V_21 ;
V_65 . type = V_53 ;
V_65 . integer . V_8 = V_74 ;
V_64 . V_52 = 1 ;
V_64 . V_61 = & V_65 ;
V_5 . V_77 = V_78 ;
V_76 = F_24 ( V_20 -> V_79 , NULL , & V_64 , & V_5 ) ;
if ( V_76 != V_71 ) {
F_25 ( V_2 , L_20 , V_74 ,
F_22 ( V_76 ) ) ;
return F_26 ( - V_73 ) ;
}
V_21 = V_5 . V_61 ;
if ( V_21 -> type != V_50 ) {
F_27 ( V_21 ) ;
return F_26 ( - V_80 ) ;
}
if ( V_21 -> V_42 . V_52 < 1 ) {
F_25 ( V_2 , L_21 , V_74 ) ;
F_27 ( V_21 ) ;
return F_26 ( - V_73 ) ;
}
return V_21 ;
}
static union V_18 * F_28 ( struct V_19 * V_20 , T_2 V_65 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
struct V_81 V_5 ;
union V_18 V_46 ;
struct V_63 V_64 ;
struct V_75 V_76 ;
union V_18 * V_44 ;
T_4 V_66 ;
V_5 . V_65 = V_65 ;
V_5 . V_82 = 0 ;
V_5 . V_83 = 0 ;
V_46 . type = V_84 ;
V_46 . V_85 . V_61 = ( V_86 * ) & V_5 ;
V_46 . V_85 . V_77 = sizeof( V_5 ) ;
V_64 . V_52 = 1 ;
V_64 . V_61 = ( void * ) & V_46 ;
V_76 . V_77 = V_78 ;
V_66 = F_29 ( V_20 -> V_87 , NULL , & V_64 ,
& V_76 , V_84 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , L_22 , V_65 ,
F_22 ( V_66 ) ) ;
return F_26 ( - V_73 ) ;
}
V_44 = V_76 . V_61 ;
if ( V_44 -> V_85 . V_77 < 8 ) {
F_15 ( V_2 , L_23 ,
V_44 -> V_85 . V_77 ) ;
F_27 ( V_44 ) ;
return F_26 ( - V_73 ) ;
}
return V_44 ;
}
static union V_18 * F_30 ( struct V_19 * V_20 ,
struct V_81 * V_5 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
struct V_63 V_64 ;
union V_18 V_46 ;
struct V_75 V_76 ;
union V_18 * V_44 ;
T_4 V_66 ;
V_46 . type = V_84 ;
V_46 . V_85 . V_61 = ( V_86 * ) V_5 ;
V_46 . V_85 . V_77 = sizeof( * V_5 ) ;
V_64 . V_52 = 1 ;
V_64 . V_61 = & V_46 ;
V_76 . V_77 = V_78 ;
V_66 = F_29 ( V_20 -> V_88 , NULL , & V_64 ,
& V_76 , V_84 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , L_24 , V_5 -> V_65 ,
F_22 ( V_66 ) ) ;
return F_26 ( - V_73 ) ;
}
V_44 = V_76 . V_61 ;
if ( V_44 -> V_85 . V_77 < 8 ) {
F_15 ( V_2 , L_23 ,
V_44 -> V_85 . V_77 ) ;
F_27 ( V_44 ) ;
return F_26 ( - V_73 ) ;
}
return V_44 ;
}
static int F_31 ( struct V_6 * V_62 , T_2 * V_8 )
{
struct V_19 * V_20 = V_62 -> V_20 ;
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_44 ;
struct V_89 * V_5 ;
int V_9 = 0 ;
V_44 = F_28 ( V_20 , V_62 -> V_65 ) ;
if ( F_32 ( V_44 ) )
return F_33 ( V_44 ) ;
V_5 = (struct V_89 * ) V_44 -> V_85 . V_61 ;
if ( V_5 -> V_55 == 0 ) {
F_15 ( V_2 , L_25 , V_62 -> V_65 ) ;
V_9 = - V_73 ;
goto V_90;
}
* V_8 = V_5 -> V_8 ;
V_90:
F_27 ( V_44 ) ;
return V_9 ;
}
static int F_3 ( struct V_6 * V_62 , T_2 * V_8 )
{
int V_9 ;
if ( ! V_62 -> V_91 ||
F_34 ( V_92 , V_62 -> V_93 + V_94 ) ) {
if ( V_62 -> V_20 -> V_25 )
V_9 = F_20 ( V_62 , V_8 ) ;
else
V_9 = F_31 ( V_62 , V_8 ) ;
V_62 -> V_91 = true ;
V_62 -> V_93 = V_92 ;
V_62 -> V_95 = * V_8 ;
} else {
* V_8 = V_62 -> V_95 ;
V_9 = 0 ;
}
return V_9 ;
}
static int F_35 ( void * V_96 , T_2 * V_97 )
{
struct V_19 * V_20 = V_96 ;
union V_18 * V_76 ;
struct V_89 * V_5 ;
int V_9 = 0 ;
if ( ! V_20 -> V_87 )
return - V_98 ;
if ( ! V_20 -> V_99 . V_65 )
return - V_51 ;
V_76 = F_28 ( V_20 , V_20 -> V_99 . V_65 ) ;
if ( F_32 ( V_76 ) )
return F_33 ( V_76 ) ;
V_5 = (struct V_89 * ) V_76 -> V_85 . V_61 ;
if ( V_5 -> V_55 )
* V_97 = V_5 -> V_8 ;
else
V_9 = - V_73 ;
F_27 ( V_76 ) ;
return V_9 ;
}
static int F_36 ( char * V_5 , T_7 V_100 , union V_18 * V_44 )
{
int V_76 = 0 ;
switch ( V_44 -> type ) {
case V_53 :
V_76 = snprintf ( V_5 , V_100 , L_26 , V_44 -> integer . V_8 ) ;
break;
case V_54 :
V_76 = snprintf ( V_5 , V_100 , L_2 , V_44 -> string . V_61 ) ;
break;
}
return V_76 ;
}
static void F_37 ( char * V_5 , T_7 V_100 , union V_18 * V_21 )
{
int V_76 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
V_76 = F_36 ( V_5 , V_100 , V_44 ) ;
if ( V_76 >= V_100 )
break;
V_5 += V_76 ;
V_100 -= V_76 ;
}
}
static int F_38 ( struct V_102 * V_102 , struct V_103 * V_103 )
{
struct V_19 * V_20 = V_102 -> V_104 ;
char * V_5 = NULL ;
union V_18 * V_76 ;
V_86 V_105 ;
int V_101 ;
if ( ! V_20 -> V_79 )
return - V_98 ;
if ( ! V_20 -> V_99 . V_65 )
return - V_51 ;
V_105 = ( V_20 -> V_99 . V_65 & 0xff000000 ) >> 24 ;
V_76 = F_23 ( V_20 , V_105 ) ;
if ( F_32 ( V_76 ) )
return F_33 ( V_76 ) ;
for ( V_101 = 0 ; V_101 < V_76 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_21 = & V_76 -> V_42 . V_43 [ V_101 ] ;
union V_18 * V_65 ;
if ( V_21 -> type != V_50 )
continue;
if ( ! V_21 -> V_42 . V_52 )
continue;
V_65 = & V_21 -> V_42 . V_43 [ 0 ] ;
if ( V_65 -> integer . V_8 == V_20 -> V_99 . V_65 ) {
V_5 = F_39 ( 512 , V_106 ) ;
if ( ! V_5 ) {
F_27 ( V_76 ) ;
return - V_107 ;
}
F_37 ( V_5 , 512 , V_21 ) ;
break;
}
}
F_27 ( V_76 ) ;
if ( ! V_5 )
return - V_51 ;
V_103 -> V_108 = V_5 ;
return F_40 ( V_102 , V_103 ) ;
}
static T_1 F_41 ( struct V_103 * V_103 , char T_8 * V_5 ,
T_7 V_52 , T_9 * V_109 )
{
char * V_110 = V_103 -> V_108 ;
T_7 V_111 = strlen ( V_110 ) ;
return F_42 ( V_5 , V_52 , V_109 , V_110 , V_111 ) ;
}
static int F_43 ( struct V_102 * V_102 , struct V_103 * V_103 )
{
F_44 ( V_103 -> V_108 ) ;
return 0 ;
}
static void F_45 ( struct V_19 * V_20 )
{
struct V_112 * V_113 ;
struct V_112 * V_114 ;
V_20 -> V_99 . V_65 = 0 ;
V_113 = F_46 ( L_27 , NULL ) ;
if ( ! V_113 || F_32 ( V_113 ) )
return;
V_114 = F_47 ( L_28 , V_115 | V_116 , V_113 , & V_20 -> V_99 . V_65 ) ;
if ( ! V_114 || F_32 ( V_114 ) )
goto V_117;
V_114 = F_48 ( L_29 , V_115 , V_113 , V_20 ,
& V_118 ) ;
if ( ! V_114 || F_32 ( V_114 ) )
goto V_117;
V_114 = F_48 ( L_30 , V_115 , V_113 , V_20 ,
& V_119 ) ;
if ( ! V_114 || F_32 ( V_114 ) )
goto V_117;
V_20 -> V_99 . V_120 = V_113 ;
return;
V_117:
F_49 ( V_113 ) ;
}
static void F_50 ( struct V_19 * V_20 )
{
F_49 ( V_20 -> V_99 . V_120 ) ;
}
static void F_45 ( struct V_19 * V_20 )
{
}
static void F_50 ( struct V_19 * V_20 )
{
}
static int F_51 ( struct V_19 * V_20 , union V_18 * V_44 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_55 ;
union V_18 * V_14 ;
union V_18 * V_12 ;
union V_18 * V_13 ;
union V_18 * V_60 ;
struct V_6 * V_62 ;
char const * V_121 ;
char const * V_122 ;
char const * V_123 ;
T_2 type ;
int V_9 ;
int * V_124 ;
int V_125 ;
if ( V_44 -> type != V_50 ) {
F_15 ( V_2 , L_31 ,
V_44 -> type ) ;
return - V_51 ;
}
V_9 = F_14 ( V_20 , V_44 ) ;
if ( V_9 )
return V_9 ;
type = F_13 ( V_20 , V_44 , V_27 ) -> integer . V_8
& V_56 ;
switch ( type ) {
case V_58 :
V_121 = L_32 ;
V_122 = L_33 ;
V_123 = L_34 ;
V_124 = & V_20 -> V_126 ;
V_125 = 0 ;
break;
case V_10 :
V_121 = L_35 ;
V_122 = L_34 ;
V_123 = L_36 ;
V_124 = & V_20 -> V_127 ;
V_125 = 1 ;
break;
case V_59 :
V_121 = L_14 ;
V_122 = L_33 ;
V_123 = L_34 ;
V_124 = & V_20 -> V_128 ;
V_125 = 1 ;
break;
default:
F_15 ( V_2 , L_37 , type ) ;
return - V_51 ;
}
V_60 = F_13 ( V_20 , V_44 , V_39 ) ;
if ( ! V_60 -> integer . V_8 )
return 0 ;
V_55 = F_13 ( V_20 , V_44 , V_27 ) ;
V_14 = F_13 ( V_20 , V_44 , V_30 ) ;
V_12 = F_13 ( V_20 , V_44 , V_33 ) ;
V_13 = F_13 ( V_20 , V_44 , V_36 ) ;
V_62 = F_39 ( sizeof( * V_62 ) , V_106 ) ;
if ( ! V_62 )
return - V_107 ;
V_62 -> V_11 = F_52 ( V_14 -> string . V_61 , V_106 ) ;
if ( ! V_62 -> V_11 ) {
V_9 = - V_107 ;
goto V_90;
}
F_53 ( & V_62 -> V_129 ) ;
V_62 -> type = type ;
V_62 -> V_20 = V_20 ;
V_62 -> V_65 = V_55 -> integer . V_8 ;
V_62 -> V_12 = V_12 -> integer . V_8 ;
if ( V_20 -> V_25 )
V_62 -> V_13 = V_13 -> integer . V_8 ;
else
V_62 -> V_13 = V_62 -> V_12 + V_13 -> integer . V_8 ;
snprintf ( V_62 -> V_130 , V_131 ,
L_38 , V_121 , V_125 + * V_124 ) ;
F_11 ( & V_62 -> V_132 ,
V_62 -> V_130 ,
F_1 ) ;
snprintf ( V_62 -> V_133 , V_131 ,
L_39 , V_121 , V_125 + * V_124 ) ;
F_11 ( & V_62 -> V_134 ,
V_62 -> V_133 ,
F_4 ) ;
snprintf ( V_62 -> V_135 , V_131 ,
L_40 , V_121 , V_125 + * V_124 , V_122 ) ;
F_11 ( & V_62 -> V_136 ,
V_62 -> V_135 ,
F_6 ) ;
snprintf ( V_62 -> V_137 , V_131 ,
L_40 , V_121 , V_125 + * V_124 , V_123 ) ;
F_11 ( & V_62 -> V_138 ,
V_62 -> V_137 ,
F_8 ) ;
F_54 ( & V_62 -> V_129 , & V_20 -> V_139 ) ;
( * V_124 ) ++ ;
return 1 ;
V_90:
F_44 ( V_62 -> V_11 ) ;
F_44 ( V_62 ) ;
return V_9 ;
}
static int F_55 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
struct V_75 V_5 ;
union V_18 * V_21 ;
T_4 V_66 ;
int V_101 , V_76 ;
int V_52 = 0 ;
V_5 . V_77 = V_78 ;
V_66 = F_29 ( V_20 -> V_140 ,
V_141 , NULL , & V_5 , V_50 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , V_141 L_41 ,
F_22 ( V_66 ) ) ;
return - V_98 ;
}
V_21 = V_5 . V_61 ;
for ( V_101 = 1 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
V_76 = F_51 ( V_20 , V_44 ) ;
if ( V_76 > 0 )
V_52 ++ ;
}
F_27 ( V_5 . V_61 ) ;
V_5 . V_77 = V_78 ;
V_66 = F_29 ( V_20 -> V_140 ,
V_142 , NULL , & V_5 , V_50 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , V_142 L_41 ,
F_22 ( V_66 ) ) ;
V_76 = - V_98 ;
goto V_117;
}
V_21 = V_5 . V_61 ;
for ( V_101 = 1 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
V_76 = F_51 ( V_20 , V_44 ) ;
if ( V_76 > 0 )
V_52 ++ ;
}
F_27 ( V_5 . V_61 ) ;
V_5 . V_77 = V_78 ;
V_66 = F_29 ( V_20 -> V_140 ,
V_143 , NULL , & V_5 , V_50 ) ;
if ( V_66 != V_71 ) {
F_15 ( V_2 , V_143 L_41 ,
F_22 ( V_66 ) ) ;
V_76 = - V_98 ;
goto V_117;
}
V_21 = V_5 . V_61 ;
for ( V_101 = 1 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
V_76 = F_51 ( V_20 , V_44 ) ;
if ( V_76 > 0 )
V_52 ++ ;
}
F_27 ( V_5 . V_61 ) ;
return V_52 ;
V_117:
F_56 ( V_20 ) ;
return V_76 ;
}
static int F_57 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_21 ;
union V_18 * V_144 ;
int V_76 ;
int V_101 ;
V_21 = F_23 ( V_20 , V_145 ) ;
if ( F_32 ( V_21 ) ) {
if ( F_33 ( V_21 ) == - V_80 ) {
F_19 ( V_2 , L_42 , V_145 ) ;
return 0 ;
}
return F_33 ( V_21 ) ;
}
V_144 = NULL ;
for ( V_101 = 0 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
union V_18 * V_65 ;
if ( V_44 -> type != V_50 )
continue;
V_65 = & V_44 -> V_42 . V_43 [ 0 ] ;
if ( V_65 -> type != V_53 )
continue;
if ( V_65 -> integer . V_8 == V_146 ) {
V_144 = V_44 ;
break;
}
}
V_76 = ( V_144 != NULL ) ;
if ( ! V_76 )
F_19 ( V_2 , L_43 ) ;
F_27 ( V_21 ) ;
return V_76 ;
}
static int F_58 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_44 ;
struct V_89 * V_5 ;
int V_9 ;
V_44 = F_28 ( V_20 , V_146 ) ;
if ( F_32 ( V_44 ) ) {
F_25 ( V_2 , L_44 ) ;
return F_33 ( V_44 ) ;
}
V_5 = (struct V_89 * ) V_44 -> V_85 . V_61 ;
if ( V_5 -> V_55 == 0 ) {
F_25 ( V_2 , L_44 ) ;
V_9 = - V_73 ;
} else {
V_9 = ( V_5 -> V_8 != 0 ) ;
F_19 ( V_2 , L_45 ,
V_9 ? L_46 : L_47 ) ;
}
F_27 ( V_44 ) ;
return V_9 ;
}
static int F_59 ( struct V_19 * V_20 , int V_60 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_44 ;
struct V_81 V_147 ;
struct V_89 * V_148 ;
int V_9 = 0 ;
V_147 . V_65 = V_146 ;
V_147 . V_82 = V_60 ;
V_147 . V_83 = 0 ;
V_44 = F_30 ( V_20 , & V_147 ) ;
if ( F_32 ( V_44 ) ) {
F_25 ( V_2 , L_48 ,
V_60 ? L_46 : L_47 ) ;
return F_33 ( V_44 ) ;
}
V_148 = (struct V_89 * ) V_44 -> V_85 . V_61 ;
if ( V_148 -> V_55 == 0 ) {
F_25 ( V_2 , L_48 ,
V_60 ? L_46 : L_47 ) ;
V_9 = - V_73 ;
} else {
F_60 ( V_2 , L_49 ,
V_60 ? L_46 : L_47 ) ;
}
F_27 ( V_44 ) ;
return V_9 ;
}
static int F_61 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
union V_18 * V_21 ;
int V_9 ;
int V_101 ;
V_9 = F_57 ( V_20 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 ) {
V_9 = F_58 ( V_20 ) ;
if ( V_9 < 0 )
return V_9 ;
V_20 -> V_149 = V_9 ;
V_9 = F_59 ( V_20 , 1 ) ;
if ( V_9 ) {
V_20 -> V_149 = false ;
return V_9 ;
}
}
F_19 ( V_2 , L_50 ) ;
V_21 = F_23 ( V_20 , V_150 ) ;
if ( F_32 ( V_21 ) )
return F_33 ( V_21 ) ;
for ( V_101 = 0 ; V_101 < V_21 -> V_42 . V_52 ; V_101 ++ ) {
union V_18 * V_44 = & V_21 -> V_42 . V_43 [ V_101 ] ;
F_51 ( V_20 , V_44 ) ;
}
V_9 = V_20 -> V_126 + V_20 -> V_127 + V_20 -> V_128 ;
F_27 ( V_21 ) ;
return V_9 ;
}
static int F_62 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
int V_9 ;
F_63 (s, &data->sensor_list, list) {
V_9 = F_64 ( V_20 -> V_151 , & V_7 -> V_132 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_64 ( V_20 -> V_151 , & V_7 -> V_134 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_64 ( V_20 -> V_151 , & V_7 -> V_136 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_64 ( V_20 -> V_151 , & V_7 -> V_138 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_64 ( V_20 -> V_151 , & V_152 ) ;
return V_9 ;
}
static void F_65 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
F_63 (s, &data->sensor_list, list) {
F_66 ( V_20 -> V_151 , & V_7 -> V_132 ) ;
F_66 ( V_20 -> V_151 , & V_7 -> V_134 ) ;
F_66 ( V_20 -> V_151 , & V_7 -> V_136 ) ;
F_66 ( V_20 -> V_151 , & V_7 -> V_138 ) ;
}
F_66 ( V_20 -> V_151 , & V_152 ) ;
}
static void F_56 ( struct V_19 * V_20 )
{
struct V_153 * V_154 = & V_20 -> V_139 ;
struct V_6 * V_7 , * V_46 ;
F_67 (s, tmp, head, list) {
F_44 ( V_7 -> V_11 ) ;
F_44 ( V_7 ) ;
}
}
static int F_68 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
int V_9 ;
F_19 ( V_2 , L_51 ) ;
V_20 -> V_151 = F_69 ( V_2 ) ;
if ( F_32 ( V_20 -> V_151 ) )
return F_33 ( V_20 -> V_151 ) ;
F_19 ( V_2 , L_52 ) ;
V_9 = F_62 ( V_20 ) ;
if ( V_9 )
goto remove;
return 0 ;
remove:
F_65 ( V_20 ) ;
F_70 ( V_20 -> V_151 ) ;
return V_9 ;
}
static int F_71 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_45 -> V_2 ;
T_5 V_76 ;
T_4 V_66 ;
int V_9 = 0 ;
V_66 = F_72 ( V_20 -> V_140 , V_155 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_69 = V_76 ;
else
F_19 ( V_2 , L_53 V_155 L_54 ,
F_22 ( V_66 ) ) ;
V_66 = F_72 ( V_20 -> V_140 , V_156 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_68 = V_76 ;
else
F_19 ( V_2 , L_53 V_156 L_54 ,
F_22 ( V_66 ) ) ;
V_66 = F_72 ( V_20 -> V_140 , V_157 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_70 = V_76 ;
else
F_19 ( V_2 , L_53 V_157 L_54 ,
F_22 ( V_66 ) ) ;
V_66 = F_72 ( V_20 -> V_140 , V_158 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_79 = V_76 ;
else
F_19 ( V_2 , L_53 V_158 L_54 ,
F_22 ( V_66 ) ) ;
V_66 = F_72 ( V_20 -> V_140 , V_159 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_87 = V_76 ;
else
F_19 ( V_2 , L_53 V_159 L_54 ,
F_22 ( V_66 ) ) ;
V_66 = F_72 ( V_20 -> V_140 , V_160 , & V_76 ) ;
if ( F_73 ( V_66 ) )
V_20 -> V_88 = V_76 ;
else
F_19 ( V_2 , L_53 V_160 L_54 ,
F_22 ( V_66 ) ) ;
if ( V_161 )
F_60 ( V_2 , L_55 ) ;
if ( V_20 -> V_69 && V_20 -> V_68 && V_20 -> V_70 && ! V_161 )
V_20 -> V_25 = true ;
else if ( V_20 -> V_79 && V_20 -> V_87 &&
V_20 -> V_88 )
V_20 -> V_25 = false ;
else
V_9 = - V_98 ;
return V_9 ;
}
static int F_74 ( struct V_162 * V_1 )
{
T_4 V_76 ;
int V_9 ;
struct V_75 V_5 ;
union V_18 * V_44 ;
struct V_19 * V_20 ;
F_19 ( & V_1 -> V_2 , L_56 ) ;
V_20 = F_39 ( sizeof( * V_20 ) , V_106 ) ;
if ( ! V_20 )
return - V_107 ;
V_20 -> V_45 = V_1 ;
V_20 -> V_140 = V_1 -> V_163 ;
F_53 ( & V_20 -> V_139 ) ;
V_20 -> V_149 = false ;
V_5 . V_77 = V_78 ;
V_76 = F_29 ( V_20 -> V_140 , V_164 , NULL ,
& V_5 , V_50 ) ;
if ( V_76 != V_71 ) {
F_19 ( & V_1 -> V_2 , L_57 ) ;
} else {
V_44 = V_5 . V_61 ;
if ( V_44 -> V_42 . V_52 >= 2 ) {
union V_18 * V_65 = & V_44 -> V_42 . V_43 [ 1 ] ;
if ( V_65 -> type == V_54 )
F_19 ( & V_1 -> V_2 , L_58 ,
V_65 -> string . V_61 ) ;
}
F_27 ( V_5 . V_61 ) ;
}
V_9 = F_71 ( V_20 ) ;
if ( V_9 ) {
F_25 ( & V_1 -> V_2 , L_59 ) ;
goto V_90;
}
if ( V_20 -> V_25 ) {
F_19 ( & V_1 -> V_2 , L_60 ) ;
V_9 = F_55 ( V_20 ) ;
} else {
F_19 ( & V_1 -> V_2 , L_61 ) ;
V_9 = F_61 ( V_20 ) ;
}
if ( V_9 < 0 )
goto V_90;
if ( V_9 == 0 ) {
F_60 ( & V_1 -> V_2 ,
L_62 ) ;
V_9 = - V_98 ;
goto V_90;
}
V_9 = F_68 ( V_20 ) ;
if ( V_9 )
goto V_117;
F_45 ( V_20 ) ;
V_1 -> V_165 = V_20 ;
return 0 ;
V_117:
F_56 ( V_20 ) ;
V_90:
if ( V_20 -> V_149 )
F_59 ( V_20 , 0 ) ;
F_44 ( V_20 ) ;
return V_9 ;
}
static int F_75 ( struct V_162 * V_1 , int type )
{
struct V_19 * V_20 = V_1 -> V_165 ;
F_19 ( & V_1 -> V_2 , L_63 ) ;
V_1 -> V_165 = NULL ;
F_50 ( V_20 ) ;
F_65 ( V_20 ) ;
F_56 ( V_20 ) ;
F_70 ( V_20 -> V_151 ) ;
if ( V_20 -> V_149 ) {
if ( F_59 ( V_20 , 0 ) )
F_25 ( & V_1 -> V_2 , L_64 ) ;
}
F_44 ( V_20 ) ;
return 0 ;
}
static int T_10 F_76 ( void )
{
int V_76 ;
if ( ! F_77 () ) {
F_78 ( L_65 ) ;
return - V_166 ;
}
if ( F_79 ( V_167 ) )
V_161 = true ;
V_76 = F_80 ( & V_168 ) ;
if ( V_76 )
F_81 ( L_66 , V_76 ) ;
return V_76 ;
}
static void T_11 F_82 ( void )
{
F_83 ( & V_168 ) ;
}
