static void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 ;
T_1 V_7 ;
if ( ! V_2 -> V_8 || ! V_2 -> remove )
F_2 ( V_9 L_1
L_2 , V_2 -> V_10 ) ;
while ( V_4 && V_4 -> V_11 ) {
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( ! V_4 -> V_12 [ V_6 ] )
continue;
V_7 = F_3 ( 0 , V_4 -> V_12 [ V_6 ] , strlen ( V_4 -> V_12 [ V_6 ] ) ) ;
if ( V_7 == V_4 -> V_13 [ V_6 ] )
continue;
F_2 ( V_9 L_3
L_4
L_5 , V_2 -> V_10 , V_4 -> V_12 [ V_6 ] ,
V_4 -> V_13 [ V_6 ] , V_7 ) ;
F_2 ( V_9 L_6
L_7
L_8 ) ;
}
V_4 ++ ;
}
return;
}
static T_2
F_4 ( struct V_14 * V_15 , const char * V_16 , T_3 V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_20 = F_5 ( V_15 ) ;
T_4 V_11 , V_21 , V_22 ;
T_5 V_23 , V_24 , V_25 ;
T_6 V_13 [ 4 ] = { 0 , 0 , 0 , 0 } ;
int V_26 = 0 ;
int V_27 = 0 ;
V_26 = sscanf ( V_16 , L_9 ,
& V_11 , & V_21 , & V_22 , & V_23 , & V_24 , & V_25 ,
& V_13 [ 0 ] , & V_13 [ 1 ] , & V_13 [ 2 ] , & V_13 [ 3 ] ) ;
if ( V_26 < 6 )
return - V_28 ;
V_19 = F_6 ( sizeof( struct V_18 ) , V_29 ) ;
if ( ! V_19 )
return - V_30 ;
V_19 -> V_31 . V_11 = V_11 ;
V_19 -> V_31 . V_21 = V_21 ;
V_19 -> V_31 . V_22 = V_22 ;
V_19 -> V_31 . V_23 = V_23 ;
V_19 -> V_31 . V_24 = V_24 ;
V_19 -> V_31 . V_25 = V_25 ;
memcpy ( V_19 -> V_31 . V_13 , V_13 , sizeof( T_6 ) * 4 ) ;
F_7 ( & V_20 -> V_32 . V_33 ) ;
F_8 ( & V_19 -> V_34 , & V_20 -> V_32 . V_35 ) ;
F_9 ( & V_20 -> V_32 . V_33 ) ;
V_27 = F_10 ( & V_20 -> V_36 ) ;
if ( V_27 )
return V_27 ;
return V_17 ;
}
static void
F_11 ( struct V_1 * V_36 )
{
struct V_18 * V_19 , * V_37 ;
F_7 ( & V_36 -> V_32 . V_33 ) ;
F_12 (dynid, n, &drv->dynids.list, node) {
F_13 ( & V_19 -> V_34 ) ;
F_14 ( V_19 ) ;
}
F_9 ( & V_36 -> V_32 . V_33 ) ;
}
static int
F_15 ( struct V_1 * V_36 )
{
int error = 0 ;
if ( V_36 -> V_8 != NULL )
error = F_16 ( & V_36 -> V_36 , & V_38 ) ;
return error ;
}
static void
F_17 ( struct V_1 * V_36 )
{
F_18 ( & V_36 -> V_36 , & V_38 ) ;
}
int F_19 ( struct V_1 * V_15 )
{
int error ;
if ( ! V_15 )
return - V_28 ;
F_1 ( V_15 ) ;
V_15 -> V_36 . V_39 = & V_40 ;
V_15 -> V_36 . V_41 = V_15 -> V_41 ;
V_15 -> V_36 . V_10 = V_15 -> V_10 ;
F_20 ( & V_15 -> V_32 . V_33 ) ;
F_21 ( & V_15 -> V_32 . V_35 ) ;
F_22 ( L_10 , V_15 -> V_10 ) ;
error = F_23 ( & V_15 -> V_36 ) ;
if ( error < 0 )
return error ;
error = F_15 ( V_15 ) ;
if ( error )
F_24 ( & V_15 -> V_36 ) ;
return error ;
}
void F_25 ( struct V_1 * V_15 )
{
F_22 ( L_11 , V_15 -> V_10 ) ;
F_17 ( V_15 ) ;
F_24 ( & V_15 -> V_36 ) ;
F_11 ( V_15 ) ;
}
static struct V_42 * F_26 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
V_45 = F_27 ( & V_43 -> V_46 ) ;
if ( ! V_45 )
return NULL ;
return F_28 ( V_45 ) ;
}
static void F_29 ( struct V_42 * V_43 )
{
if ( V_43 )
F_30 ( & V_43 -> V_46 ) ;
}
static void F_31 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_32 ( V_48 , struct V_49 , V_48 ) ;
F_22 ( L_12 ) ;
F_14 ( V_50 ) ;
}
static void F_33 ( struct V_44 * V_46 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
int V_6 ;
F_34 ( V_46 , L_13 ) ;
F_35 ( V_43 -> V_51 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
F_14 ( V_43 -> V_12 [ V_6 ] ) ;
F_14 ( V_43 -> V_52 ) ;
F_36 ( & V_43 -> V_53 -> V_48 , F_31 ) ;
F_14 ( V_43 ) ;
}
static int F_37 ( struct V_44 * V_46 )
{
struct V_42 * V_43 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
T_7 V_56 ;
int V_57 = 0 ;
V_46 = F_27 ( V_46 ) ;
if ( ! V_46 )
return - V_58 ;
V_43 = F_28 ( V_46 ) ;
V_2 = F_5 ( V_46 -> V_15 ) ;
V_55 = V_43 -> V_51 ;
F_34 ( V_46 , L_14 , V_2 -> V_10 ) ;
if ( ( ! V_2 -> V_8 ) || ( ! V_43 -> V_53 ) ||
( ! F_38 ( V_2 -> V_41 ) ) ) {
V_57 = - V_28 ;
goto V_59;
}
V_57 = F_39 ( V_43 -> V_51 , V_43 -> V_60 , V_61 ,
& V_56 ) ;
if ( ! V_57 ) {
V_43 -> V_62 = V_56 . V_63 ;
V_43 -> V_64 = V_56 . V_65 [ 0 ] ;
F_34 ( V_46 , L_15 , V_43 -> V_62 ,
V_43 -> V_64 ) ;
} else {
F_40 ( V_66 , V_46 ,
L_16 ) ;
V_43 -> V_62 = 0 ;
V_43 -> V_64 = 0 ;
}
V_57 = V_2 -> V_8 ( V_43 ) ;
if ( V_57 ) {
F_34 ( V_46 , L_17 ,
V_2 -> V_10 , V_57 ) ;
goto V_67;
}
F_34 ( V_46 , L_18 , V_2 -> V_10 ,
V_43 -> V_68 / 10 , V_43 -> V_68 % 10 , V_43 -> V_69 , V_43 -> V_70 ) ;
F_34 ( V_46 , L_19 ,
V_43 -> V_71 [ 0 ] , V_43 -> V_71 [ 1 ] , V_43 -> V_71 [ 2 ] ,
V_43 -> V_71 [ 3 ] , V_43 -> V_71 [ 4 ] ) ;
F_7 ( & V_55 -> V_72 ) ;
if ( ( V_55 -> V_73 ) &&
( V_43 -> V_51 -> V_74 == 1 ) && ( V_43 -> V_25 == 0 ) )
F_41 ( V_55 , V_75 ) ;
F_9 ( & V_55 -> V_72 ) ;
V_67:
if ( V_57 )
F_42 ( V_2 -> V_41 ) ;
V_59:
if ( V_57 )
F_30 ( V_46 ) ;
return V_57 ;
}
static void F_43 ( struct V_54 * V_55 , struct V_42 * V_76 )
{
struct V_42 * V_43 ;
struct V_42 * V_77 ;
F_34 ( V_76 ? & V_76 -> V_46 : & V_55 -> V_46 ,
L_20 , V_55 -> V_78 ,
V_76 ? V_76 -> V_52 : L_21 ) ;
F_7 ( & V_55 -> V_72 ) ;
if ( ! V_76 )
V_55 -> V_74 = 0 ;
else
V_55 -> V_74 = 1 ;
F_9 ( & V_55 -> V_72 ) ;
F_12 (p_dev, tmp, &s->devices_list, socket_device_list) {
if ( V_43 == V_76 )
continue;
F_7 ( & V_55 -> V_72 ) ;
F_13 ( & V_43 -> V_79 ) ;
F_9 ( & V_55 -> V_72 ) ;
F_34 ( & V_43 -> V_46 , L_22 ) ;
F_44 ( & V_43 -> V_46 ) ;
}
return;
}
static int F_45 ( struct V_44 * V_46 )
{
struct V_42 * V_43 ;
struct V_1 * V_2 ;
int V_6 ;
V_43 = F_28 ( V_46 ) ;
V_2 = F_5 ( V_46 -> V_15 ) ;
F_34 ( V_46 , L_23 ) ;
if ( ( V_43 -> V_51 -> V_73 ) &&
( V_43 -> V_51 -> V_74 > 0 ) &&
( V_43 -> V_25 == 0 ) )
F_43 ( V_43 -> V_51 , V_43 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> remove )
V_2 -> remove ( V_43 ) ;
if ( V_43 -> V_80 || V_43 -> V_81 || V_43 -> V_82 )
F_40 ( V_66 , V_46 ,
L_24 ,
V_2 -> V_10 ) ;
for ( V_6 = 0 ; V_6 < V_83 ; V_6 ++ )
if ( V_43 -> V_84 & F_46 ( V_6 ) )
F_40 ( V_66 , V_46 ,
L_25 ,
V_2 -> V_10 ) ;
F_29 ( V_43 ) ;
F_42 ( V_2 -> V_41 ) ;
return 0 ;
}
static int F_47 ( struct V_42 * V_43 )
{
T_8 V_21 ;
T_9 V_23 ;
T_10 * V_85 ;
unsigned int V_6 ;
V_85 = F_48 ( sizeof( * V_85 ) , V_29 ) ;
if ( ! V_85 )
return - V_30 ;
if ( ! F_39 ( V_43 -> V_51 , V_86 ,
V_87 , & V_21 ) ) {
F_7 ( & V_43 -> V_51 -> V_72 ) ;
V_43 -> V_21 = V_21 . V_88 ;
V_43 -> V_22 = V_21 . V_89 ;
V_43 -> V_90 = 1 ;
V_43 -> V_91 = 1 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
}
if ( ! F_39 ( V_43 -> V_51 , V_43 -> V_60 ,
V_92 , & V_23 ) ) {
F_7 ( & V_43 -> V_51 -> V_72 ) ;
V_43 -> V_23 = V_23 . V_60 ;
V_43 -> V_93 = 1 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
} else {
T_11 * V_94 ;
V_94 = F_48 ( sizeof( * V_94 ) , V_29 ) ;
if ( ! V_94 ) {
F_14 ( V_85 ) ;
return - V_30 ;
}
if ( ! F_39 ( V_43 -> V_51 , V_43 -> V_60 ,
V_95 , V_94 ) ) {
F_34 ( & V_43 -> V_46 ,
L_26
L_27 ) ;
F_7 ( & V_43 -> V_51 -> V_72 ) ;
V_43 -> V_23 = V_96 ;
V_43 -> V_93 = 1 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
}
F_14 ( V_94 ) ;
}
if ( ! F_39 ( V_43 -> V_51 , V_86 , V_97 ,
V_85 ) ) {
F_7 ( & V_43 -> V_51 -> V_72 ) ;
for ( V_6 = 0 ; V_6 < F_49 (unsigned int, 4 , vers1->ns) ; V_6 ++ ) {
char * V_77 ;
unsigned int V_98 ;
char * V_99 ;
V_77 = V_85 -> V_100 + V_85 -> V_101 [ V_6 ] ;
V_98 = strlen ( V_77 ) + 1 ;
if ( ( V_98 < 2 ) || ( V_98 > 255 ) )
continue;
V_99 = F_48 ( sizeof( char ) * V_98 , V_29 ) ;
if ( ! V_99 )
continue;
V_99 = strncpy ( V_99 , V_77 , V_98 ) ;
V_77 = V_43 -> V_12 [ V_6 ] ;
V_43 -> V_12 [ V_6 ] = V_99 ;
F_14 ( V_77 ) ;
}
F_9 ( & V_43 -> V_51 -> V_72 ) ;
}
F_14 ( V_85 ) ;
return 0 ;
}
static struct V_42 * F_50 ( struct V_54 * V_55 ,
unsigned int V_24 )
{
struct V_42 * V_43 , * V_45 ;
int V_6 ;
V_55 = F_51 ( V_55 ) ;
if ( ! V_55 )
return NULL ;
F_22 ( L_28 , V_55 -> V_78 , V_24 ) ;
V_43 = F_6 ( sizeof( struct V_42 ) , V_29 ) ;
if ( ! V_43 )
goto V_102;
F_7 ( & V_55 -> V_72 ) ;
V_43 -> V_25 = ( V_55 -> V_74 ++ ) ;
F_9 ( & V_55 -> V_72 ) ;
if ( ( V_43 -> V_25 >= 2 ) && ( V_24 == 0 ) )
goto V_103;
if ( V_43 -> V_25 >= 4 )
goto V_103;
V_43 -> V_51 = V_55 ;
V_43 -> V_60 = V_24 ;
V_43 -> V_46 . V_39 = & V_40 ;
V_43 -> V_46 . V_104 = V_55 -> V_46 . V_104 ;
V_43 -> V_46 . V_105 = F_33 ;
V_43 -> V_106 = V_107 ;
V_43 -> V_46 . V_106 = & V_43 -> V_106 ;
F_52 ( & V_43 -> V_46 , L_29 , V_43 -> V_51 -> V_78 , V_43 -> V_25 ) ;
if ( ! F_53 ( & V_43 -> V_46 ) )
goto V_103;
V_43 -> V_52 = F_54 ( V_29 , L_30 , F_53 ( & V_43 -> V_46 ) ) ;
if ( ! V_43 -> V_52 )
goto V_103;
F_34 ( & V_43 -> V_46 , L_31 , V_43 -> V_52 ) ;
F_7 ( & V_55 -> V_72 ) ;
F_55 (tmp_dev, &s->devices_list, socket_device_list)
if ( V_43 -> V_60 == V_45 -> V_60 ) {
V_43 -> V_53 = V_45 -> V_53 ;
V_43 -> V_70 = V_45 -> V_70 ;
F_56 ( & V_43 -> V_53 -> V_48 ) ;
}
F_57 ( & V_43 -> V_79 , & V_55 -> V_108 ) ;
if ( F_58 ( V_43 ) )
F_59 ( & V_43 -> V_46 ,
L_32 ) ;
if ( ! V_43 -> V_53 ) {
V_49 * V_50 ;
F_34 ( & V_43 -> V_46 , L_33 ) ;
V_50 = F_6 ( sizeof( struct V_49 ) , V_29 ) ;
if ( ! V_50 ) {
F_9 ( & V_55 -> V_72 ) ;
goto V_109;
}
V_43 -> V_53 = V_50 ;
F_60 ( & V_50 -> V_48 ) ;
for ( V_6 = 0 ; V_6 < V_110 ; V_6 ++ ) {
V_50 -> V_111 [ V_6 ] . V_10 = V_43 -> V_52 ;
V_50 -> V_111 [ V_6 ] . V_112 = V_113 ;
}
for ( V_6 = 0 ; V_6 < V_83 ; V_6 ++ ) {
V_50 -> V_114 [ V_6 ] . V_10 = V_43 -> V_52 ;
V_50 -> V_114 [ V_6 ] . V_112 = V_115 ;
}
}
for ( V_6 = 0 ; V_6 < V_110 ; V_6 ++ )
V_43 -> V_71 [ V_6 ] = & V_43 -> V_53 -> V_111 [ V_6 ] ;
for (; V_6 < ( V_110 + V_83 ) ; V_6 ++ )
V_43 -> V_71 [ V_6 ] = & V_43 -> V_53 -> V_114 [ V_6 - V_110 ] ;
F_9 ( & V_55 -> V_72 ) ;
F_40 ( V_116 , & V_43 -> V_46 ,
L_34 ,
V_43 -> V_52 , V_43 -> V_70 ) ;
F_47 ( V_43 ) ;
if ( F_61 ( & V_43 -> V_46 ) )
goto V_109;
return V_43 ;
V_109:
F_7 ( & V_55 -> V_72 ) ;
F_13 ( & V_43 -> V_79 ) ;
F_9 ( & V_55 -> V_72 ) ;
V_103:
F_7 ( & V_55 -> V_72 ) ;
V_55 -> V_74 -- ;
F_9 ( & V_55 -> V_72 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
F_14 ( V_43 -> V_12 [ V_6 ] ) ;
F_14 ( V_43 -> V_52 ) ;
F_14 ( V_43 ) ;
V_102:
F_35 ( V_55 ) ;
return NULL ;
}
static int F_62 ( struct V_54 * V_55 )
{
T_12 V_117 ;
unsigned int V_118 , V_6 , V_119 ;
int V_57 = - V_120 ;
F_7 ( & V_55 -> V_72 ) ;
if ( ! ( V_55 -> V_121 ) ) {
F_34 ( & V_55 -> V_46 ,
L_35 ) ;
F_9 ( & V_55 -> V_72 ) ;
return - V_120 ;
}
if ( F_63 ( V_55 ) ) {
F_34 ( & V_55 -> V_46 , L_36
L_37 ) ;
F_9 ( & V_55 -> V_72 ) ;
return - V_120 ;
}
F_9 ( & V_55 -> V_72 ) ;
V_57 = F_64 ( V_55 , & V_119 ) ;
if ( V_57 || ! V_119 ) {
F_34 ( & V_55 -> V_46 , L_38 ) ;
return - V_58 ;
}
if ( ! F_39 ( V_55 , V_86 , V_122 , & V_117 ) )
V_118 = V_117 . V_123 ;
else
V_118 = 1 ;
V_55 -> V_124 = V_118 ;
for ( V_6 = 0 ; V_6 < V_118 ; V_6 ++ )
F_50 ( V_55 , V_6 ) ;
return V_57 ;
}
static int F_65 ( struct V_44 * V_46 , void * V_125 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
if ( ! V_43 -> V_46 . V_15 ) {
F_34 ( V_46 , L_39 ) ;
F_47 ( V_43 ) ;
}
return 0 ;
}
static void F_66 ( struct V_54 * V_55 )
{
int V_126 ;
if ( V_55 -> V_124 == 0 ) {
F_62 ( V_55 ) ;
return;
}
F_67 ( & V_40 , NULL , NULL , F_65 ) ;
if ( V_55 -> V_127 ) {
int V_128 , V_129 ;
T_12 V_117 ;
V_128 = V_55 -> V_124 ;
if ( ! F_39 ( V_55 , V_86 , V_122 ,
& V_117 ) )
V_129 = V_117 . V_123 ;
else
V_129 = 1 ;
if ( V_128 != V_129 ) {
F_43 ( V_55 , NULL ) ;
V_55 -> V_124 = 0 ;
F_62 ( V_55 ) ;
}
}
F_7 ( & V_55 -> V_72 ) ;
V_126 = V_55 -> V_73 ;
F_9 ( & V_55 -> V_72 ) ;
if ( V_126 )
F_50 ( V_55 , 0 ) ;
if ( F_68 ( & V_40 ) )
F_59 ( & V_55 -> V_46 , L_40 ) ;
}
static int F_69 ( struct V_42 * V_46 , char * V_130 )
{
struct V_54 * V_55 = V_46 -> V_51 ;
const struct V_131 * V_132 ;
int V_57 = - V_30 ;
T_12 V_117 ;
int V_128 , V_129 = 1 ;
if ( ! V_130 )
return - V_28 ;
F_34 ( & V_46 -> V_46 , L_41 , V_130 ) ;
if ( F_70 ( & V_132 , V_130 , & V_46 -> V_46 ) == 0 ) {
if ( V_132 -> V_133 >= V_134 ) {
V_57 = - V_28 ;
F_40 ( V_135 , & V_46 -> V_46 ,
L_42 ) ;
goto V_105;
}
if ( ! F_71 ( V_55 , V_132 -> V_136 , V_132 -> V_133 ) )
V_57 = 0 ;
else {
F_40 ( V_135 , & V_46 -> V_46 ,
L_43 ) ;
goto V_105;
}
V_128 = V_55 -> V_124 ;
if ( ! F_39 ( V_55 , V_86 , V_122 ,
& V_117 ) )
V_129 = V_117 . V_123 ;
if ( V_128 != V_129 )
V_57 = - V_137 ;
F_47 ( V_46 ) ;
F_41 ( V_55 , V_75 ) ;
}
V_105:
F_72 ( V_132 ) ;
return V_57 ;
}
static inline int F_69 ( struct V_42 * V_46 , char * V_130 )
{
return - V_58 ;
}
static inline int F_73 ( struct V_42 * V_46 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_11 & V_138 ) {
if ( ( ! V_46 -> V_90 ) || ( V_46 -> V_21 != V_4 -> V_21 ) )
return 0 ;
}
if ( V_4 -> V_11 & V_139 ) {
if ( ( ! V_46 -> V_91 ) || ( V_46 -> V_22 != V_4 -> V_22 ) )
return 0 ;
}
if ( V_4 -> V_11 & V_140 ) {
if ( V_46 -> V_60 != V_4 -> V_24 )
return 0 ;
}
if ( V_4 -> V_11 & V_141 ) {
if ( ! V_46 -> V_12 [ 0 ] )
return 0 ;
if ( strcmp ( V_4 -> V_12 [ 0 ] , V_46 -> V_12 [ 0 ] ) )
return 0 ;
}
if ( V_4 -> V_11 & V_142 ) {
if ( ! V_46 -> V_12 [ 1 ] )
return 0 ;
if ( strcmp ( V_4 -> V_12 [ 1 ] , V_46 -> V_12 [ 1 ] ) )
return 0 ;
}
if ( V_4 -> V_11 & V_143 ) {
if ( ! V_46 -> V_12 [ 2 ] )
return 0 ;
if ( strcmp ( V_4 -> V_12 [ 2 ] , V_46 -> V_12 [ 2 ] ) )
return 0 ;
}
if ( V_4 -> V_11 & V_144 ) {
if ( ! V_46 -> V_12 [ 3 ] )
return 0 ;
if ( strcmp ( V_4 -> V_12 [ 3 ] , V_46 -> V_12 [ 3 ] ) )
return 0 ;
}
if ( V_4 -> V_11 & V_145 ) {
F_34 ( & V_46 -> V_46 , L_44 ) ;
F_7 ( & V_46 -> V_51 -> V_72 ) ;
V_46 -> V_51 -> V_73 = 1 ;
F_9 ( & V_46 -> V_51 -> V_72 ) ;
if ( V_46 -> V_25 != V_4 -> V_25 )
return 0 ;
}
if ( V_4 -> V_11 & V_146 ) {
int V_57 ;
if ( ( ! V_46 -> V_93 ) || ( V_46 -> V_23 != V_4 -> V_23 ) )
return 0 ;
if ( V_46 -> V_51 -> V_73 )
return 0 ;
if ( V_46 -> V_25 )
return 0 ;
F_7 ( & V_46 -> V_51 -> V_72 ) ;
V_57 = V_46 -> V_147 ;
F_9 ( & V_46 -> V_51 -> V_72 ) ;
if ( ! V_57 ) {
F_34 ( & V_46 -> V_46 ,
L_45 ) ;
return 0 ;
}
}
if ( V_4 -> V_11 & V_148 ) {
F_34 ( & V_46 -> V_46 , L_46 ) ;
if ( ! V_46 -> V_51 -> V_127 )
if ( F_69 ( V_46 , V_4 -> V_149 ) )
return 0 ;
}
if ( V_4 -> V_11 & V_150 ) {
int V_6 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
if ( V_46 -> V_12 [ V_6 ] )
return 0 ;
if ( V_46 -> V_90 || V_46 -> V_91 || V_46 -> V_93 )
return 0 ;
}
return 1 ;
}
static int F_74 ( struct V_44 * V_46 , struct V_14 * V_36 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
struct V_1 * V_2 = F_5 ( V_36 ) ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_19 ;
F_7 ( & V_2 -> V_32 . V_33 ) ;
F_55 (dynid, &p_drv->dynids.list, node) {
F_34 ( V_46 , L_47 , V_36 -> V_10 ) ;
if ( F_73 ( V_43 , & V_19 -> V_31 ) ) {
F_34 ( V_46 , L_48 , V_36 -> V_10 ) ;
F_9 ( & V_2 -> V_32 . V_33 ) ;
return 1 ;
}
}
F_9 ( & V_2 -> V_32 . V_33 ) ;
while ( V_4 && V_4 -> V_11 ) {
F_34 ( V_46 , L_47 , V_36 -> V_10 ) ;
if ( F_73 ( V_43 , V_4 ) ) {
F_34 ( V_46 , L_48 , V_36 -> V_10 ) ;
return 1 ;
}
V_4 ++ ;
}
return 0 ;
}
static int F_75 ( struct V_44 * V_46 , struct V_151 * V_152 )
{
struct V_42 * V_43 ;
int V_6 ;
T_1 V_7 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ! V_46 )
return - V_58 ;
V_43 = F_28 ( V_46 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( ! V_43 -> V_12 [ V_6 ] )
continue;
V_7 [ V_6 ] = F_3 ( 0 , V_43 -> V_12 [ V_6 ] , strlen ( V_43 -> V_12 [ V_6 ] ) ) ;
}
if ( F_76 ( V_152 , L_49 , V_43 -> V_51 -> V_78 ) )
return - V_30 ;
if ( F_76 ( V_152 , L_50 , V_43 -> V_25 ) )
return - V_30 ;
if ( F_76 ( V_152 , L_51
L_52 ,
V_43 -> V_90 ? V_43 -> V_21 : 0 ,
V_43 -> V_91 ? V_43 -> V_22 : 0 ,
V_43 -> V_93 ? V_43 -> V_23 : 0 ,
V_43 -> V_60 ,
V_43 -> V_25 ,
V_7 [ 0 ] ,
V_7 [ 1 ] ,
V_7 [ 2 ] ,
V_7 [ 3 ] ) )
return - V_30 ;
return 0 ;
}
static int F_77 ( struct V_44 * V_46 )
{
int V_153 ;
F_78 ( V_46 ) ;
V_153 = F_79 ( V_46 , V_154 ) ;
F_80 ( V_46 ) ;
return V_153 ;
}
static int F_81 ( struct V_44 * V_46 )
{
int V_153 ;
F_78 ( V_46 ) ;
V_153 = F_82 ( V_46 ) ;
F_80 ( V_46 ) ;
return V_153 ;
}
static T_2 F_83 ( struct V_44 * V_46 ,
struct V_155 * V_156 , char * V_16 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
char * V_100 = V_16 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_157 ; V_6 ++ )
V_100 += sprintf ( V_100 , L_53 , V_43 -> V_71 [ V_6 ] ) ;
return V_100 - V_16 ;
}
static T_2 F_84 ( struct V_44 * V_46 , struct V_155 * V_156 , char * V_16 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
if ( V_43 -> V_158 )
return sprintf ( V_16 , L_54 ) ;
else
return sprintf ( V_16 , L_55 ) ;
}
static T_2 F_85 ( struct V_44 * V_46 , struct V_155 * V_156 ,
const char * V_16 , T_3 V_17 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
int V_57 = 0 ;
if ( ! V_17 )
return - V_28 ;
if ( ( ! V_43 -> V_158 ) && ! strncmp ( V_16 , L_56 , 3 ) )
V_57 = F_77 ( V_46 ) ;
else if ( V_43 -> V_158 && ! strncmp ( V_16 , L_57 , 2 ) )
V_57 = F_81 ( V_46 ) ;
return V_57 ? V_57 : V_17 ;
}
static T_2 F_86 ( struct V_44 * V_46 , struct V_155 * V_156 , char * V_16 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
int V_6 ;
T_1 V_7 [ 4 ] = { 0 , 0 , 0 , 0 } ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( ! V_43 -> V_12 [ V_6 ] )
continue;
V_7 [ V_6 ] = F_3 ( 0 , V_43 -> V_12 [ V_6 ] ,
strlen ( V_43 -> V_12 [ V_6 ] ) ) ;
}
return sprintf ( V_16 , L_58
L_59 ,
V_43 -> V_90 ? V_43 -> V_21 : 0 ,
V_43 -> V_91 ? V_43 -> V_22 : 0 ,
V_43 -> V_93 ? V_43 -> V_23 : 0 ,
V_43 -> V_60 , V_43 -> V_25 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
}
static T_2 F_87 ( struct V_44 * V_46 ,
struct V_155 * V_156 , const char * V_16 , T_3 V_17 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
if ( ! V_17 )
return - V_28 ;
F_7 ( & V_43 -> V_51 -> V_72 ) ;
V_43 -> V_147 = 1 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
F_41 ( V_43 -> V_51 , V_75 ) ;
return V_17 ;
}
static int F_79 ( struct V_44 * V_46 , T_13 V_159 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
struct V_1 * V_2 = NULL ;
int V_57 = 0 ;
F_7 ( & V_43 -> V_51 -> V_72 ) ;
if ( V_43 -> V_158 ) {
F_9 ( & V_43 -> V_51 -> V_72 ) ;
return 0 ;
}
V_43 -> V_158 = 1 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
F_34 ( V_46 , L_60 ) ;
if ( V_46 -> V_15 )
V_2 = F_5 ( V_46 -> V_15 ) ;
if ( ! V_2 )
goto V_160;
if ( V_2 -> V_161 ) {
V_57 = V_2 -> V_161 ( V_43 ) ;
if ( V_57 ) {
F_40 ( V_135 , V_46 ,
L_61
L_62 ,
V_43 -> V_52 , V_2 -> V_10 , V_57 ) ;
F_7 ( & V_43 -> V_51 -> V_72 ) ;
V_43 -> V_158 = 0 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
goto V_160;
}
}
if ( V_43 -> V_25 == V_43 -> V_60 ) {
F_34 ( V_46 , L_63 ) ;
F_88 ( V_43 ) ;
}
V_160:
return V_57 ;
}
static int F_82 ( struct V_44 * V_46 )
{
struct V_42 * V_43 = F_28 ( V_46 ) ;
struct V_1 * V_2 = NULL ;
int V_57 = 0 ;
F_7 ( & V_43 -> V_51 -> V_72 ) ;
if ( ! V_43 -> V_158 ) {
F_9 ( & V_43 -> V_51 -> V_72 ) ;
return 0 ;
}
V_43 -> V_158 = 0 ;
F_9 ( & V_43 -> V_51 -> V_72 ) ;
F_34 ( V_46 , L_64 ) ;
if ( V_46 -> V_15 )
V_2 = F_5 ( V_46 -> V_15 ) ;
if ( ! V_2 )
goto V_160;
if ( V_43 -> V_25 == V_43 -> V_60 ) {
F_34 ( V_46 , L_65 ) ;
V_57 = F_89 ( V_43 ) ;
if ( V_57 )
goto V_160;
}
if ( V_2 -> V_162 )
V_57 = V_2 -> V_162 ( V_43 ) ;
V_160:
return V_57 ;
}
static int F_90 ( struct V_44 * V_46 , void * V_125 )
{
struct V_54 * V_163 = V_125 ;
struct V_42 * V_43 = F_28 ( V_46 ) ;
if ( V_43 -> V_51 != V_163 || V_43 -> V_158 )
return 0 ;
return F_77 ( V_46 ) ;
}
static int F_91 ( struct V_44 * V_46 , void * V_125 )
{
struct V_54 * V_163 = V_125 ;
struct V_42 * V_43 = F_28 ( V_46 ) ;
if ( V_43 -> V_51 != V_163 || ! V_43 -> V_158 )
return 0 ;
F_81 ( V_46 ) ;
return 0 ;
}
static int F_92 ( struct V_54 * V_163 )
{
F_34 ( & V_163 -> V_46 , L_66 , V_163 -> V_78 ) ;
F_67 ( & V_40 , NULL , V_163 , F_91 ) ;
return 0 ;
}
static int F_93 ( struct V_54 * V_163 )
{
F_34 ( & V_163 -> V_46 , L_67 , V_163 -> V_78 ) ;
if ( F_67 ( & V_40 , NULL , V_163 ,
F_90 ) ) {
F_92 ( V_163 ) ;
return - V_164 ;
}
return 0 ;
}
static int F_94 ( struct V_54 * V_163 )
{
F_95 ( & V_163 -> V_165 , 0 ) ;
F_43 ( V_163 , NULL ) ;
F_7 ( & V_163 -> V_72 ) ;
F_96 ( V_163 ) ;
F_97 ( V_163 ) ;
F_9 ( & V_163 -> V_72 ) ;
return 0 ;
}
static int F_98 ( struct V_54 * V_163 )
{
F_95 ( & V_163 -> V_165 , 1 ) ;
F_7 ( & V_163 -> V_72 ) ;
V_163 -> V_73 = 0 ;
F_96 ( V_163 ) ;
F_9 ( & V_163 -> V_72 ) ;
F_62 ( V_163 ) ;
return 0 ;
}
static int F_99 ( struct V_54 * V_163 )
{
if ( ! F_100 ( V_163 ) )
return 0 ;
F_34 ( & V_163 -> V_46 , L_68 ) ;
F_94 ( V_163 ) ;
F_7 ( & V_163 -> V_72 ) ;
F_96 ( V_163 ) ;
F_14 ( V_163 -> V_127 ) ;
V_163 -> V_127 = NULL ;
V_163 -> V_124 = 0 ;
F_9 ( & V_163 -> V_72 ) ;
F_98 ( V_163 ) ;
return 0 ;
}
struct V_42 * F_101 ( struct V_42 * V_166 )
{
struct V_42 * V_43 ;
struct V_42 * V_57 = NULL ;
V_43 = F_26 ( V_166 ) ;
if ( ! V_43 )
return NULL ;
if ( F_102 ( & V_43 -> V_51 -> V_165 ) != 0 )
V_57 = V_43 ;
F_29 ( V_43 ) ;
return V_57 ;
}
static int F_103 ( struct V_44 * V_46 ,
struct V_167 * V_168 )
{
struct V_54 * V_51 = F_104 ( V_46 ) ;
int V_57 ;
V_51 = F_51 ( V_51 ) ;
if ( ! V_51 ) {
F_40 ( V_135 , V_46 ,
L_69 ) ;
return - V_58 ;
}
V_57 = F_105 ( & V_46 -> V_169 , & V_170 ) ;
if ( V_57 ) {
F_40 ( V_135 , V_46 , L_70 ) ;
F_35 ( V_51 ) ;
return V_57 ;
}
F_21 ( & V_51 -> V_108 ) ;
V_51 -> V_73 = 0 ;
V_51 -> V_74 = 0 ;
F_95 ( & V_51 -> V_165 , 0 ) ;
V_57 = F_106 ( V_51 , & V_171 ) ;
if ( V_57 ) {
F_40 ( V_135 , V_46 , L_70 ) ;
F_35 ( V_51 ) ;
return V_57 ;
}
return 0 ;
}
static void F_107 ( struct V_44 * V_46 ,
struct V_167 * V_168 )
{
struct V_54 * V_51 = F_104 ( V_46 ) ;
if ( ! V_51 )
return;
F_106 ( V_51 , NULL ) ;
F_7 ( & V_51 -> V_172 ) ;
F_43 ( V_51 , NULL ) ;
F_108 ( V_51 ) ;
F_9 ( & V_51 -> V_172 ) ;
F_109 ( & V_46 -> V_169 , & V_170 ) ;
F_35 ( V_51 ) ;
return;
}
static int T_14 F_110 ( void )
{
int V_57 ;
V_57 = F_111 ( & V_40 ) ;
if ( V_57 < 0 ) {
F_2 ( V_173 L_71 , V_57 ) ;
return V_57 ;
}
V_57 = F_112 ( & V_174 ) ;
if ( V_57 < 0 ) {
F_2 ( V_173
L_72 , V_57 ) ;
F_113 ( & V_40 ) ;
return V_57 ;
}
return 0 ;
}
static void T_15 F_114 ( void )
{
F_115 ( & V_174 ) ;
F_113 ( & V_40 ) ;
}
