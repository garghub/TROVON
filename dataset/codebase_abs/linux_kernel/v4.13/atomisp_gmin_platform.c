const struct V_1 * F_1 ( void )
{
static const struct V_1 V_2 = {
. V_3 = 1 ,
. V_4 = {
{ . V_5 = 1 , } ,
} ,
} ;
return & V_2 ;
}
const struct V_6 * F_2 ( void )
{
return & V_7 ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
if ( V_12 && V_12 -> V_13 == V_10 )
return 0 ;
V_12 -> V_13 = V_10 ;
if ( V_12 -> V_14 ) {
if ( V_10 )
return F_5 ( V_12 -> V_14 ) ;
else
return F_6 ( V_12 -> V_14 ) ;
}
return 0 ;
}
const struct V_15 * F_7 ( void )
{
static struct V_15 V_16 = {
. V_17 = F_3 ,
} ;
return & V_16 ;
}
int F_8 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
enum V_20 type )
{
int V_21 ;
struct V_22 * V_23 ;
struct V_11 * V_12 ;
struct V_24 * V_25 = F_9 ( V_9 ) ;
struct V_26 * V_27 ;
F_10 ( & V_25 -> V_28 , L_1 , type ) ;
V_27 = F_11 ( & V_25 -> V_28 ) ;
if ( V_27 )
V_27 -> V_29 . V_30 . V_31 = 0 ;
for ( V_21 = 0 ; V_21 < V_32 ; V_21 ++ )
if ( ! V_7 . V_33 [ V_21 ] . type )
break;
if ( V_7 . V_33 [ V_21 ] . type )
return - V_34 ;
V_12 = F_4 ( V_9 ) ;
V_7 . V_33 [ V_21 ] . type = type ;
V_7 . V_33 [ V_21 ] . V_35 = V_12 -> V_36 ;
V_7 . V_33 [ V_21 ] . V_9 = V_9 ;
V_7 . V_33 [ V_21 ] . V_8 . V_37 = V_25 -> V_38 -> V_39 ;
V_23 = & V_7 . V_33 [ V_21 ] . V_8 . V_40 ;
memcpy ( V_23 -> type , V_25 -> V_41 , V_42 ) ;
V_23 -> V_30 = V_25 -> V_30 ;
V_23 -> V_43 = V_25 -> V_43 ;
V_23 -> V_44 = V_25 -> V_44 ;
V_23 -> V_45 = V_19 ;
return 0 ;
}
struct V_8 * F_12 ( struct V_46 * V_38 ,
struct V_22 * V_40 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_32 && V_7 . V_33 [ V_21 ] . type ; V_21 ++ ) {
struct V_47 * V_48 = & V_7 . V_33 [ V_21 ] ;
if ( V_48 -> V_8 . V_37 == V_38 -> V_39 &&
V_48 -> V_8 . V_40 . V_43 == V_40 -> V_43 )
return V_48 -> V_9 ;
}
return NULL ;
}
int F_13 ( struct V_8 * V_48 )
{
int V_21 , V_49 ;
if ( ! V_48 )
return 0 ;
for ( V_21 = 0 ; V_21 < V_32 ; V_21 ++ ) {
if ( V_7 . V_33 [ V_21 ] . V_9 == V_48 ) {
for ( V_49 = V_21 + 1 ; V_49 <= V_32 ; V_49 ++ )
V_7 . V_33 [ V_49 - 1 ] = V_7 . V_33 [ V_49 ] ;
}
if ( V_50 [ V_21 ] . V_9 == V_48 ) {
if ( V_50 [ V_21 ] . V_51 )
F_14 ( V_50 [ V_21 ] . V_51 ) ;
V_50 [ V_21 ] . V_51 = NULL ;
if ( V_50 [ V_21 ] . V_52 )
F_14 ( V_50 [ V_21 ] . V_52 ) ;
V_50 [ V_21 ] . V_52 = NULL ;
if ( V_53 == V_54 ) {
F_15 ( V_50 [ V_21 ] . V_55 ) ;
F_15 ( V_50 [ V_21 ] . V_56 ) ;
F_15 ( V_50 [ V_21 ] . V_57 ) ;
F_15 ( V_50 [ V_21 ] . V_14 ) ;
}
V_50 [ V_21 ] . V_9 = NULL ;
}
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_17 ( void )
{
return 0 ;
}
static struct V_11 * F_18 ( struct V_8 * V_9 )
{
int V_21 , V_58 ;
struct V_59 * V_28 ;
struct V_24 * V_25 = F_9 ( V_9 ) ;
if ( ! V_53 )
V_53 = V_54 ;
if ( ! V_25 )
return NULL ;
V_28 = & V_25 -> V_28 ;
for ( V_21 = 0 ; V_21 < V_32 && V_50 [ V_21 ] . V_9 ; V_21 ++ )
;
if ( V_21 >= V_32 )
return NULL ;
F_10 ( V_28 ,
L_2 ,
V_53 ) ;
V_50 [ V_21 ] . V_9 = V_9 ;
V_50 [ V_21 ] . V_60 = F_19 ( V_28 , L_3 , 0 ) ;
V_50 [ V_21 ] . V_61 = F_19 ( V_28 , L_4 ,
V_62 ) ;
V_50 [ V_21 ] . V_36 = F_19 ( V_28 , L_5 , 0 ) ;
V_50 [ V_21 ] . V_63 = F_19 ( V_28 , L_6 , 1 ) ;
V_50 [ V_21 ] . V_51 = F_20 ( V_28 , NULL , 0 , V_64 ) ;
V_50 [ V_21 ] . V_52 = F_20 ( V_28 , NULL , 1 , V_64 ) ;
if ( ! F_21 ( V_50 [ V_21 ] . V_51 ) ) {
V_58 = F_22 ( V_50 [ V_21 ] . V_51 , 0 ) ;
if ( V_58 )
F_23 ( V_28 , L_7 , V_58 ) ;
} else {
V_50 [ V_21 ] . V_51 = NULL ;
}
if ( ! F_21 ( V_50 [ V_21 ] . V_52 ) ) {
V_58 = F_22 ( V_50 [ V_21 ] . V_52 , 0 ) ;
if ( V_58 )
F_23 ( V_28 , L_8 , V_58 ) ;
} else {
V_50 [ V_21 ] . V_52 = NULL ;
}
if ( V_53 == V_54 ) {
V_50 [ V_21 ] . V_55 = F_24 ( V_28 , L_9 ) ;
V_50 [ V_21 ] . V_56 = F_24 ( V_28 , L_10 ) ;
V_50 [ V_21 ] . V_57 = F_24 ( V_28 , L_11 ) ;
V_50 [ V_21 ] . V_14 = F_24 ( V_28 , L_12 ) ;
}
return & V_50 [ V_21 ] ;
}
static struct V_11 * F_4 ( struct V_8 * V_9 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_32 ; V_21 ++ )
if ( V_50 [ V_21 ] . V_9 == V_9 )
return & V_50 [ V_21 ] ;
return F_18 ( V_9 ) ;
}
static int F_25 ( struct V_8 * V_9 , int V_65 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
if ( V_12 && V_12 -> V_51 ) {
F_26 ( V_12 -> V_51 , V_65 ) ;
return 0 ;
}
return - V_66 ;
}
static int F_27 ( struct V_8 * V_9 , int V_65 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
if ( V_12 && V_12 -> V_52 ) {
F_26 ( V_12 -> V_52 , V_65 ) ;
return 0 ;
}
return - V_66 ;
}
static int F_28 ( struct V_8 * V_9 , int V_65 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
if ( V_12 && V_12 -> V_67 == V_65 )
return 0 ;
V_12 -> V_67 = V_65 ;
if ( V_12 -> V_57 ) {
if ( V_65 )
return F_5 ( V_12 -> V_57 ) ;
else
return F_6 ( V_12 -> V_57 ) ;
}
return - V_66 ;
}
static int F_29 ( struct V_8 * V_9 , int V_65 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
int V_58 ;
if ( V_68 == V_69 ) {
V_68 = F_19 ( NULL , L_13 , V_70 ) ;
if ( V_68 != V_70 ) {
F_30 ( L_14 ,
V_68 ) ;
V_58 = F_31 ( V_68 , L_15 ) ;
if ( ! V_58 )
V_58 = F_32 ( V_68 , 0 ) ;
if ( V_58 )
F_33 ( L_16 ) ;
}
}
if ( V_12 && V_12 -> V_71 == V_65 )
return 0 ;
V_12 -> V_71 = V_65 ;
if ( V_68 >= 0 )
F_34 ( V_68 , V_65 ) ;
if ( V_12 -> V_55 ) {
F_35 ( V_12 -> V_55 , 1800000 , 1800000 ) ;
if ( V_65 )
return F_5 ( V_12 -> V_55 ) ;
else
return F_6 ( V_12 -> V_55 ) ;
}
return - V_66 ;
}
static int F_36 ( struct V_8 * V_9 , int V_65 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
int V_58 ;
if ( V_72 == V_73 ) {
V_72 = F_19 ( NULL , L_17 , V_74 ) ;
if ( V_72 != V_74 ) {
F_30 ( L_18 ,
V_72 ) ;
V_58 = F_31 ( V_72 , L_19 ) ;
if ( ! V_58 )
V_58 = F_32 ( V_72 , 0 ) ;
if ( V_58 )
F_33 ( L_20 ) ;
}
}
if ( V_12 && V_12 -> V_75 == V_65 )
return 0 ;
V_12 -> V_75 = V_65 ;
if ( V_72 >= 0 )
F_34 ( V_72 , V_65 ) ;
if ( V_12 -> V_56 ) {
F_35 ( V_12 -> V_56 , 2900000 , 2900000 ) ;
if ( V_65 )
return F_5 ( V_12 -> V_56 ) ;
else
return F_6 ( V_12 -> V_56 ) ;
}
return - V_66 ;
}
static int F_37 ( struct V_8 * V_9 , int V_65 )
{
int V_58 = 0 ;
struct V_11 * V_12 = F_4 ( V_9 ) ;
if ( V_65 )
V_58 = F_38 ( V_12 -> V_60 , V_12 -> V_61 ) ;
if ( V_58 )
return V_58 ;
return F_39 ( V_12 -> V_60 ,
V_65 ? V_76 : V_77 ) ;
}
static int F_40 ( struct V_8 * V_48 , int V_10 )
{
struct V_24 * V_25 = F_9 ( V_48 ) ;
struct V_11 * V_12 = F_4 ( V_48 ) ;
if ( ! V_25 || ! V_12 )
return - V_78 ;
return F_41 ( V_48 , V_12 -> V_36 , V_12 -> V_63 ,
V_12 -> V_79 , V_12 -> V_80 , V_10 ) ;
}
static struct V_81 * F_42 ( struct V_8 * V_9 ,
char * V_82 )
{
struct V_24 * V_25 = F_9 ( V_9 ) ;
struct V_11 * V_12 = F_4 ( V_9 ) ;
struct V_81 * V_83 ;
if ( V_25 == NULL || V_12 == NULL )
return NULL ;
if ( ! V_82 )
return NULL ;
F_43 ( & V_84 ) ;
F_44 (vcm, &vcm_devices, list) {
if ( ! strcmp ( V_82 , V_83 -> V_82 ) ) {
F_45 ( & V_84 ) ;
return V_83 ;
}
}
F_45 ( & V_84 ) ;
return NULL ;
}
struct V_18 * F_46 (
struct V_8 * V_9 ,
enum V_85 V_86 ,
enum V_87 V_80 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
V_12 -> V_79 = V_86 ;
V_12 -> V_80 = V_80 ;
return & V_88 ;
}
int F_47 ( struct V_81 * V_89 )
{
if ( ! V_89 )
return - V_66 ;
F_43 ( & V_84 ) ;
F_48 ( & V_89 -> V_90 , & V_91 ) ;
F_45 ( & V_84 ) ;
return 0 ;
}
int F_49 ( struct V_59 * V_28 , const char * V_92 , char * V_93 ,
T_1 * V_94 )
{
char V_95 [ V_96 ] ;
T_2 V_97 [ V_96 ] ;
struct V_98 * V_99 ;
int V_21 , V_49 , V_58 ;
if ( V_28 && F_11 ( V_28 ) )
V_28 = & F_11 ( V_28 ) -> V_28 ;
if ( V_28 )
V_58 = snprintf ( V_95 , sizeof( V_95 ) , L_21 , F_50 ( V_28 ) , V_92 ) ;
else
V_58 = snprintf ( V_95 , sizeof( V_95 ) , L_22 , V_92 ) ;
if ( V_58 < 0 || V_58 >= sizeof( V_95 ) - 1 )
return - V_66 ;
for ( V_21 = 0 ; V_21 < F_51 ( V_100 ) ; V_21 ++ ) {
if ( F_52 ( V_101 , V_100 [ V_21 ] . V_102 ) ) {
for ( V_49 = 0 ; V_100 [ V_21 ] . V_103 [ V_49 ] . V_41 ; V_49 ++ ) {
T_1 V_104 ;
const struct V_105 * V_106 ;
V_106 = & V_100 [ V_21 ] . V_103 [ V_49 ] ;
V_104 = strlen ( V_106 -> V_107 ) ;
if ( strcmp ( V_95 , V_106 -> V_41 ) )
continue;
if ( V_104 > * V_94 - 1 )
return - V_108 ;
memcpy ( V_93 , V_106 -> V_107 , F_53 ( * V_94 , V_104 + 1 ) ) ;
V_93 [ * V_94 - 1 ] = 0 ;
* V_94 = V_104 ;
return 0 ;
}
}
}
memset ( V_97 , 0 , sizeof( V_97 ) ) ;
for ( V_21 = 0 ; V_21 < sizeof( V_95 ) && V_95 [ V_21 ] ; V_21 ++ )
V_97 [ V_21 ] = V_95 [ V_21 ] ;
if ( * V_94 > V_109 )
return - V_66 ;
V_99 = F_54 ( sizeof( * V_99 ) , V_110 ) ;
if ( ! V_99 )
return - V_34 ;
memcpy ( & V_99 -> V_92 . V_111 , V_97 , sizeof( V_97 ) ) ;
V_99 -> V_92 . V_112 = V_113 ;
V_99 -> V_92 . V_114 = * V_94 ;
V_58 = F_55 ( V_99 , & V_99 -> V_92 . V_115 ,
& V_99 -> V_92 . V_114 , V_99 -> V_92 . V_116 ) ;
if ( V_58 == 0 ) {
memcpy ( V_93 , V_99 -> V_92 . V_116 , V_99 -> V_92 . V_114 ) ;
* V_94 = V_99 -> V_92 . V_114 ;
} else if ( V_28 ) {
F_56 ( V_28 , L_23 , V_95 ) ;
}
F_57 ( V_99 ) ;
return V_58 ;
}
int F_19 ( struct V_59 * V_28 , const char * V_92 , int V_117 )
{
char V_107 [ V_96 ] ;
T_1 V_118 = sizeof( V_107 ) ;
long V_119 ;
int V_58 ;
V_58 = F_49 ( V_28 , V_92 , V_107 , & V_118 ) ;
if ( ! V_58 ) {
V_107 [ V_118 ] = 0 ;
V_58 = F_58 ( V_107 , 0 , & V_119 ) ;
}
return V_58 ? V_117 : V_119 ;
}
int F_41 ( struct V_8 * V_48 , T_3 V_35 ,
T_3 V_120 , T_3 V_121 , T_3 V_122 , int V_10 )
{
struct V_24 * V_25 = F_9 ( V_48 ) ;
struct V_123 * V_124 = NULL ;
if ( V_10 ) {
V_124 = F_54 ( sizeof( * V_124 ) , V_110 ) ;
if ( ! V_124 ) {
F_23 ( & V_25 -> V_28 , L_24 ) ;
return - V_34 ;
}
V_124 -> V_35 = V_35 ;
V_124 -> V_125 = V_120 ;
V_124 -> V_126 = V_121 ;
V_124 -> V_127 = V_122 ;
F_59 ( V_48 , ( void * ) V_124 ) ;
V_124 -> V_128 = V_129 ;
V_124 -> V_130 = NULL ;
F_10 ( & V_25 -> V_28 ,
L_25 ,
V_35 , V_120 , V_122 ) ;
} else {
V_124 = F_60 ( V_48 ) ;
F_57 ( V_124 ) ;
}
return 0 ;
}
static void F_61 ( struct V_131 * V_28 )
{
F_10 ( & V_28 -> V_28 , L_26 ) ;
V_28 -> V_132 = 0 ;
}
