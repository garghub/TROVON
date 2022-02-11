static inline
int F_1 ( T_1 T_2 * V_1 )
{
int V_2 = 120 ;
while ( V_2 > 0 ) {
if ( F_2 ( & V_1 -> V_3 ) )
return 1 ;
F_3 ( 1 ) ;
V_2 -- ;
}
return 0 ;
}
static int F_4 ( T_3 * V_4 ,
T_4 * V_5 )
{
int V_6 ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_6 = sizeof( V_7 ) + V_4 -> V_8 . V_9 ;
if ( V_4 -> V_8 . V_9 == 0 ) {
F_5 ( L_2 ) ;
return - 1 ;
}
memcpy ( ( ( V_10 * ) ( V_4 ) ) + V_6 , V_5 , sizeof( * V_5 ) ) ;
return 0 ;
}
static int F_6 ( T_3 * V_4 ,
T_4 * V_5 )
{
int V_6 ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_6 = sizeof( V_7 ) + V_4 -> V_8 . V_11 ;
if ( V_4 -> V_8 . V_11 == 0 ) {
F_5 ( L_3 ) ;
return - 1 ;
}
memcpy ( ( ( V_10 * ) ( V_4 ) ) + V_6 , V_5 , sizeof( * V_5 ) ) ;
return 0 ;
}
static int
F_7 ( T_3 * V_4 ,
T_4 * V_5 , int V_12 )
{
int V_6 ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_6 =
( sizeof( V_7 ) +
V_4 -> V_8 . V_13 ) +
( V_4 -> V_8 . V_14 * V_12 ) ;
if ( V_4 -> V_8 . V_13 == 0 ) {
F_5 ( L_4 ) ;
return - 1 ;
}
memcpy ( ( ( V_10 * ) ( V_4 ) ) + V_6 , V_5 , sizeof( * V_5 ) ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 )
{
int V_17 ;
struct V_18 * V_19 ;
V_19 = F_9 ( sizeof( struct V_18 ) , V_20 ) ;
F_10 ( V_21 , V_22 ) ;
if ( ! V_19 )
return 0 ;
F_11 ( V_19 , L_5 , V_16 -> V_23 ) ;
V_19 -> V_24 = V_25 ;
V_19 -> V_26 = & V_27 ;
V_19 -> V_28 = & V_29 ;
V_19 -> V_30 = ( V_31 void * ) V_16 -> V_1 ;
V_17 = F_12 ( V_19 ) ;
if ( V_17 ) {
F_5 ( L_6 , V_17 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
F_4 ( V_19 -> V_30 ,
& V_34 ) ;
F_6 ( V_19 -> V_30 , & V_35 ) ;
F_13 ( L_7 ,
V_16 -> V_23 , F_14 ( V_19 ) ) ;
F_10 ( V_36 , V_22 ) ;
return 1 ;
}
static int F_15 ( struct V_37 * V_16 )
{
int V_38 ;
struct V_39 V_40 ;
struct V_18 * V_19 ;
unsigned char V_41 [ V_42 ] ;
F_10 ( V_21 , V_22 ) ;
if ( ! F_1
( ( T_1 T_2 * ) V_16 -> V_1 ) ) {
F_5 ( L_8 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
F_16 ( V_16 -> V_1 ) ;
F_17 ( V_16 -> V_23 ) ;
F_13 ( L_9 ,
V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ,
V_40 . V_46 . V_47 , V_40 . V_46 . V_48 , V_40 . V_46 . V_49 ,
V_40 . V_46 . V_50 , V_16 -> V_1 ) ;
V_38 = F_18 ( V_19 , V_51 , V_16 , & V_40 , NULL ) ;
if ( V_38 ) {
F_13 ( L_10 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 , V_16 -> V_1 ) ;
F_19 ( V_36 , V_38 ,
V_22 ) ;
}
return V_38 ;
}
static int
F_20 ( struct V_37 * V_16 )
{
int V_38 ;
struct V_52 V_53 ;
struct V_18 * V_19 ;
unsigned char V_41 [ V_42 ] ;
F_10 ( V_21 , V_22 ) ;
if ( ! F_1
( ( T_1 T_2 * ) V_16 -> V_1 ) ) {
F_5 ( L_11 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
F_21 ( V_16 -> V_1 ) ;
F_17 ( V_16 -> V_23 ) ;
F_13 ( L_12 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] , V_53 . V_54 [ 3 ] ,
V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] , V_53 . V_55 , V_53 . V_56 ,
V_16 -> V_1 , ( V_57 ) V_53 . V_58 . V_59 , V_53 . V_58 . V_60 ,
V_53 . V_58 . V_61 , V_53 . V_58 . V_62 [ 0 ] , V_53 . V_58 . V_62 [ 1 ] ,
V_53 . V_58 . V_62 [ 2 ] , V_53 . V_58 . V_62 [ 3 ] ,
V_53 . V_58 . V_62 [ 4 ] , V_53 . V_58 . V_62 [ 5 ] ,
V_53 . V_58 . V_62 [ 6 ] , V_53 . V_58 . V_62 [ 7 ] ) ;
V_38 = F_18 ( V_19 , V_63 , V_16 , NULL , & V_53 ) ;
if ( V_38 ) {
F_13 ( L_13 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
F_19 ( V_36 , V_38 ,
V_22 ) ;
return 1 ;
}
return 0 ;
}
static int
F_22 ( struct V_64 * V_65 )
{
struct V_18 * V_19 ;
unsigned char V_41 [ V_42 ] ;
F_17 ( V_65 -> V_23 ) ;
F_13 ( L_14 , F_14 ( V_19 ) ) ;
if ( F_23 ( V_19 , NULL ) )
return 0 ;
F_13 ( L_15 , V_65 -> V_23 ) ;
return 1 ;
}
static int
F_23 ( struct V_18 * V_19 , void * V_66 )
{
int V_67 = ( V_66 != NULL ) ;
struct V_18 * V_68 = & V_27 ;
if ( ( V_67 ) && F_24 ( V_19 , ( void * ) F_14 ( V_68 ) ) ) {
F_13 ( L_16 ) ;
return 0 ;
}
F_13 ( L_17 , F_14 ( V_19 ) ) ;
F_25 ( V_19 ) ;
F_26 ( V_19 ) ;
F_13 ( L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_69 * V_70 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_70 -> V_1 ) ;
F_13 ( L_19 , V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ) ;
V_38 = F_28 ( NULL , V_51 ,
& V_40 . V_43 , NULL ) ;
if ( V_38 )
F_13 ( L_20 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 ) ;
return V_38 ;
}
static int F_29 ( struct V_69 * V_70 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_70 -> V_1 ) ;
F_13 ( L_21 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_28 ( NULL , V_63 ,
NULL , V_53 . V_54 ) ;
if ( V_38 ) {
F_13 ( L_22 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
}
return V_38 ;
}
static int F_30 ( struct V_71 * V_72 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_72 -> V_1 ) ;
F_13 ( L_23 , V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ) ;
V_38 = F_31 ( NULL , V_51 ,
& V_40 . V_43 , NULL ) ;
if ( V_38 )
F_13 ( L_24 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 ) ;
return V_38 ;
}
static int
F_32 ( struct V_71 * V_72 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_72 -> V_1 ) ;
F_13 ( L_25 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_31 ( NULL , V_63 ,
NULL , V_53 . V_54 ) ;
if ( V_38 ) {
F_13 ( L_26 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
}
return V_38 ;
}
static int F_33 ( struct V_73 * V_65 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_65 -> V_1 ) ;
F_13 ( L_27 , V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ) ;
V_38 = F_34 ( NULL , V_51 ,
& V_40 . V_43 , NULL ) ;
if ( V_38 ) {
F_13 ( L_28 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 ) ;
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_73 * V_65 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_65 -> V_1 ) ;
F_13 ( L_29 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_34 ( NULL , V_63 , NULL ,
V_53 . V_54 ) ;
if ( V_38 ) {
F_13 ( L_30 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
}
return V_38 ;
}
static void F_36 ( void )
{
int V_2 = 0 ;
unsigned long V_74 ;
struct V_75 * V_76 , * V_77 ;
F_37 ( & V_78 , V_74 ) ;
V_76 = V_79 ;
V_79 = NULL ;
F_38 ( & V_78 , V_74 ) ;
while ( V_76 ) {
V_77 = V_76 -> V_80 ;
F_39 ( V_76 ) ;
V_76 = V_77 ;
V_2 ++ ;
}
F_13 ( L_31 , V_2 ) ;
if ( F_40
( & V_29 , NULL , ( void * ) 1 , F_23 ) )
F_5 ( L_32 ) ;
}
static int F_41 ( T_5 V_81 , struct V_64 * V_65 )
{
int V_38 ;
unsigned char V_41 [ V_42 ] ;
struct V_18 * V_19 ;
F_17 ( V_65 -> V_23 ) ;
if ( ( V_81 != V_51 ) && ( V_81 != V_63 ) ) {
F_5 ( L_33 ,
V_81 , V_51 , V_63 ) ;
return 0 ;
}
F_13 ( L_34 ,
V_81 == V_51 ? L_35 : L_36 , V_41 ) ;
V_38 = F_34 ( V_19 , V_81 , NULL , NULL ) ;
if ( V_38 > 0 )
F_13 ( L_37 , V_38 ,
V_81 == V_51 ? L_35 : L_36 ) ;
return 1 ;
}
static int F_42 ( struct V_82 * V_83 )
{
switch ( V_83 -> V_84 ) {
case V_85 :
return F_8 ( & V_83 -> F_8 ) ;
case V_86 :
return F_15 ( & V_83 -> F_15 ) ;
case V_87 :
return F_20 ( & V_83 -> F_20 ) ;
case V_88 :
return F_22 ( & V_83 -> V_89 ) ;
case V_90 :
return F_33 ( & V_83 -> V_91 ) ;
case V_92 :
return F_35 ( & V_83 -> V_91 ) ;
case V_93 :
return F_41 ( V_51 , & V_83 -> V_94 ) ;
case V_95 :
return F_41 ( V_63 , & V_83 -> V_96 ) ;
case V_97 :
F_36 () ;
return 1 ;
case V_98 :
return F_27 ( & V_83 -> F_27 ) ;
case V_99 :
return F_29 ( & V_83 -> F_29 ) ;
case V_100 :
return F_30 ( & V_83 -> F_30 ) ;
case V_101 :
return F_32 ( & V_83 -> F_32 ) ;
default:
F_5 ( L_38 , V_83 -> V_84 ) ;
return 0 ;
}
}
static int F_24 ( struct V_18 * V_102 , void * V_66 )
{
const char * V_103 = V_66 ;
if ( strcmp ( V_103 , F_14 ( V_102 ) ) == 0 )
return 1 ;
return 0 ;
}
static const struct V_104 *
F_43 ( const struct V_104 * V_105 ,
const struct V_75 * V_102 )
{
while ( V_105 -> V_106 || V_105 -> V_107 || V_105 -> V_108 ) {
F_44 ( L_39 ,
V_105 -> V_106 , V_102 -> V_106 , V_105 -> V_18 , V_102 -> V_18 ) ;
if ( ( V_105 -> V_106 == V_102 -> V_106 )
&& ( V_105 -> V_18 == V_102 -> V_18 ) )
return V_105 ;
V_105 ++ ;
}
return NULL ;
}
static int F_45 ( struct V_18 * V_102 , struct V_109 * V_110 )
{
struct V_75 * V_111 = F_46 ( V_102 ) ;
struct V_112 * V_113 = F_47 ( V_110 ) ;
int V_114 = 0 ;
F_44 ( L_40 ,
V_102 -> V_115 , V_110 -> V_103 ) ;
if ( F_43 ( V_113 -> V_116 , V_111 ) )
V_114 = 1 ;
F_44 ( L_41 , V_114 ) ;
return V_114 ;
}
static int F_48 ( struct V_18 * V_102 , struct V_117 * V_118 )
{
F_44 ( L_42 ) ;
if ( F_49 ( V_118 , L_43 , V_119 ) )
return - V_120 ;
return 0 ;
}
static int F_50 ( struct V_18 * V_102 , T_6 V_121 )
{
F_44 ( L_44 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_102 )
{
F_44 ( L_45 ) ;
return 0 ;
}
static void F_52 ( struct V_18 * V_102 , int V_122 , int V_123 ,
struct V_112 * V_113 )
{
struct V_18 * V_19 ;
void * V_124 ;
T_4 V_125 ;
const char * V_126 ;
if ( ! V_102 ) {
F_5 ( L_46 , V_127 ) ;
return;
}
if ( ! V_113 ) {
F_5 ( L_47 , V_127 ) ;
return;
}
V_19 = V_102 -> V_26 ;
if ( ! V_19 ) {
F_5 ( L_48 , V_127 ) ;
return;
}
V_124 = V_19 -> V_30 ;
if ( ! V_124 ) {
F_5 ( L_49 , V_127 ) ;
return;
}
switch ( V_123 ) {
case V_128 :
V_126 = L_50 ;
break;
case V_129 :
V_126 = L_51 ;
break;
default:
V_126 = L_52 ;
break;
}
F_53 ( & V_125 , V_126 ,
V_113 -> V_103 ,
V_113 -> V_130 ,
V_113 -> V_131 ,
V_113 -> V_132 , V_113 -> V_133 ) ;
F_7 ( V_124 , & V_125 , V_122 ) ;
F_4 ( V_124 , & V_34 ) ;
F_6 ( V_124 , & V_35 ) ;
}
static int F_54 ( struct V_18 * V_102 )
{
struct V_75 * V_111 = F_46 ( V_102 ) ;
struct V_112 * V_113 =
F_47 ( V_102 -> V_134 ) ;
const struct V_104 * V_135 ;
int error = 0 ;
F_13 ( L_53 ,
V_102 , V_111 , V_113 ) ;
F_10 ( V_136 , V_22 ) ;
if ( ! V_113 -> V_116 )
return - V_137 ;
V_135 = F_43 ( V_113 -> V_116 , V_111 ) ;
if ( ! V_135 )
return - V_137 ;
F_55 ( V_102 ) ;
if ( ! V_111 -> V_138 && V_113 -> V_139 ) {
error = V_113 -> V_139 ( V_111 , V_135 ) ;
if ( ! error ) {
F_52 ( V_102 , V_111 -> V_140 ,
V_111 -> V_18 , V_113 ) ;
V_111 -> V_138 = V_113 ;
F_10 ( V_141 ,
V_22 ) ;
} else
F_56 ( V_102 ) ;
}
F_10 ( V_142 , V_33 ) ;
return error ;
}
static int F_57 ( struct V_18 * V_143 )
{
struct V_75 * V_111 = F_46 ( V_143 ) ;
struct V_112 * V_113 = V_111 -> V_138 ;
F_13 ( L_54 ,
F_14 ( V_143 ) , V_143 , V_111 , V_143 -> V_134 ,
V_143 -> V_134 -> V_103 ) ;
if ( V_113 ) {
if ( V_113 -> remove )
V_113 -> remove ( V_111 ) ;
V_111 -> V_138 = NULL ;
}
F_44 ( L_55 ) ;
F_56 ( V_143 ) ;
F_44 ( L_56 ) ;
return 0 ;
}
static void V_25 ( struct V_18 * V_102 )
{
F_44 ( L_57 ) ;
}
static int F_18 ( struct V_18 * V_144 , int V_81 ,
struct V_37 * V_16 ,
struct V_39 * V_40 ,
struct V_52 * V_53 )
{
struct V_75 * V_111 = NULL ;
struct V_75 * V_76 = NULL , * V_145 ;
unsigned long V_74 ;
int V_17 ;
T_1 T_2 * V_146 = NULL ;
struct V_18 * V_68 ;
F_13 ( L_58 , V_144 ,
V_16 -> V_1 ) ;
F_10 ( V_21 , V_22 ) ;
if ( ( V_81 != V_51 ) && ( V_81 != V_63 ) ) {
F_5 ( L_59 ,
V_81 , V_51 , V_63 ) ;
F_19 ( V_32 , V_81 ,
V_33 ) ;
return 0 ;
}
V_111 = F_9 ( sizeof( struct V_75 ) , V_20 ) ;
if ( V_111 == NULL ) {
F_5 ( L_60 ) ;
F_10 ( V_147 , V_33 ) ;
return 0 ;
}
V_111 -> V_81 = V_81 ;
if ( V_81 == V_51 ) {
V_111 -> V_18 = V_128 ;
V_111 -> V_40 = * V_40 ;
} else {
V_111 -> V_18 = V_129 ;
V_111 -> V_53 = * V_53 ;
}
V_111 -> V_106 = V_148 ;
V_111 -> V_23 = V_16 -> V_23 ;
V_111 -> V_140 = V_16 -> V_140 ;
V_111 -> V_149 . V_4 = V_16 -> V_1 ;
V_111 -> V_149 . V_150 = NULL ;
V_146 = ( T_1 T_2 * )
V_111 -> V_149 . V_4 ;
V_111 -> V_151 = V_16 -> V_151 ;
V_111 -> V_152 . V_28 = & V_29 ;
V_111 -> V_152 . V_26 = V_144 ;
V_111 -> V_152 . V_24 = V_153 ;
F_11 ( & V_111 -> V_152 , L_61 ,
V_16 -> V_23 , V_16 -> V_140 ) ;
F_37 ( & V_78 , V_74 ) ;
for ( V_76 = V_79 ; V_76 ;
V_76 = V_76 -> V_80 ) {
if ( V_81 == V_51 ) {
if ( ( V_76 -> V_40 . V_43 . V_44 == V_40 -> V_43 . V_44 ) &&
( V_76 -> V_40 . V_43 . V_45 == V_40 -> V_43 . V_45 ) ) {
break;
}
} else
if ( memcmp
( V_76 -> V_53 . V_54 , V_53 -> V_54 ,
V_154 ) == 0 ) {
break;
}
}
if ( V_76 ) {
F_38 ( & V_78 , V_74 ) ;
F_26 ( V_111 ) ;
F_5 ( L_62 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
if ( ! V_79 )
V_79 = V_111 ;
else {
V_111 -> V_80 = V_79 ;
V_79 = V_111 ;
}
F_38 ( & V_78 , V_74 ) ;
V_68 = & V_111 -> V_152 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_68 ) ,
V_155 , NULL ) ;
F_44 ( L_63 ,
& V_111 -> V_152 , V_111 -> V_152 . V_115 ) ;
V_17 = F_12 ( & V_111 -> V_152 ) ;
if ( V_17 ) {
F_5 ( L_64 , V_17 ) ;
V_68 = & V_111 -> V_152 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_68 ) ,
V_156 , NULL ) ;
F_37 ( & V_78 , V_74 ) ;
for ( V_76 = V_79 , V_145 = NULL ;
V_76 ;
V_145 = V_76 , V_76 = V_76 -> V_80 ) {
if ( V_76 == V_111 ) {
if ( V_145 )
V_145 -> V_80 = V_76 -> V_80 ;
else
V_79 = V_76 -> V_80 ;
break;
}
}
F_38 ( & V_78 , V_74 ) ;
F_26 ( V_111 ) ;
return 0 ;
}
F_13 ( L_65 ,
( V_81 == V_51 ) ? L_66 : L_67 ,
V_16 -> V_23 , V_16 -> V_140 , & V_111 -> V_152 ) ;
F_10 ( V_36 , V_22 ) ;
return 1 ;
}
static int F_28 ( struct V_18 * V_144 ,
int V_81 ,
struct V_157 * V_43 ,
unsigned char V_158 [] )
{
int V_159 = 0 ;
bool V_160 = false ;
struct V_75 * V_76 , * V_161 ;
struct V_112 * V_162 ;
unsigned long V_74 ;
int V_163 = 0 ;
if ( ( V_81 != V_51 ) && ( V_81 != V_63 ) ) {
F_5 ( L_68 ,
V_81 , V_51 , V_63 ) ;
return 0 ;
}
F_37 ( & V_78 , V_74 ) ;
for ( V_76 = V_79 , V_161 = NULL ;
( V_76 && ! V_160 ) ;
V_161 = V_76 , V_76 = V_76 -> V_80 ) {
if ( V_76 -> V_81 != V_81 )
continue;
if ( V_81 == V_51 ) {
V_159 =
( ( V_76 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_76 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_159 =
memcmp ( V_76 -> V_53 . V_54 , V_158 ,
V_154 ) == 0 ;
}
if ( ! V_159 )
continue;
V_160 = true ;
V_162 = V_76 -> V_138 ;
V_163 = V_162 -> V_164 ( V_76 , 0 ) ;
}
F_38 ( & V_78 , V_74 ) ;
if ( ! V_160 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_163 ;
}
static int F_31 ( struct V_18 * V_144 ,
int V_81 ,
struct V_157 * V_43 ,
unsigned char V_158 [] )
{
int V_165 = 0 ;
bool V_160 = false ;
struct V_75 * V_76 , * V_161 ;
struct V_112 * V_162 ;
unsigned long V_74 ;
int V_163 = 0 ;
if ( ( V_81 != V_51 ) && ( V_81 != V_63 ) ) {
F_5 ( L_70 ,
V_81 , V_51 , V_63 ) ;
return 0 ;
}
F_37 ( & V_78 , V_74 ) ;
for ( V_76 = V_79 , V_161 = NULL ;
( V_76 && ! V_160 ) ;
V_161 = V_76 , V_76 = V_76 -> V_80 ) {
if ( V_76 -> V_81 != V_81 )
continue;
if ( V_81 == V_51 ) {
V_165 =
( ( V_76 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_76 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_165 =
memcmp ( V_76 -> V_53 . V_54 , V_158 ,
V_154 ) == 0 ;
}
if ( ! V_165 )
continue;
V_160 = true ;
V_162 = V_76 -> V_138 ;
F_52 ( & V_76 -> V_152 , V_76 -> V_140 ,
V_76 -> V_18 , V_162 ) ;
V_163 = V_162 -> V_166 ( V_76 ) ;
}
F_38 ( & V_78 , V_74 ) ;
if ( ! V_160 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_163 ;
}
static int F_34 ( struct V_18 * V_144 ,
int V_81 , struct V_157 * V_43 ,
unsigned char V_158 [] )
{
int V_2 = 0 , V_167 = 0 , V_168 ;
struct V_75 * V_76 , * V_161 , * V_169 = NULL ;
unsigned long V_74 ;
#define F_59 { \
prevvpcidev = tmpvpcidev;\
tmpvpcidev = tmpvpcidev->next;\
continue; \
}
if ( ( V_81 != V_51 ) && ( V_81 != V_63 ) ) {
F_5 ( L_71 ,
V_81 , V_51 , V_63 ) ;
return 0 ;
}
V_167 = ( ( V_81 == V_51 ) && ( V_43 == NULL ) ) ||
( ( V_81 == V_63 ) && ( V_158 == NULL ) ) ;
F_37 ( & V_78 , V_74 ) ;
for ( V_76 = V_79 , V_161 = NULL ; V_76 ; ) {
if ( V_76 -> V_81 != V_81 )
F_59 ;
if ( V_167 ) {
V_168 =
( V_76 -> V_152 . V_26 == V_144 ) ;
} else if ( V_81 == V_51 ) {
V_168 =
( ( V_76 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_76 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_168 =
memcmp ( V_76 -> V_53 . V_54 , V_158 ,
V_154 ) == 0 ;
}
if ( ! V_168 )
F_59 ;
if ( V_161 )
V_161 -> V_80 = V_76 -> V_80 ;
else
V_79 = V_76 -> V_80 ;
V_76 -> V_80 = V_169 ;
V_169 = V_76 ;
V_2 ++ ;
if ( ! V_167 )
break;
if ( V_161 )
V_76 = V_161 -> V_80 ;
else
V_76 = V_79 ;
}
F_38 ( & V_78 , V_74 ) ;
if ( ! V_167 && ( V_2 == 0 ) ) {
F_5 ( L_69 ) ;
return 0 ;
}
while ( V_169 ) {
V_76 = V_169 -> V_80 ;
F_39 ( V_169 ) ;
V_169 = V_76 ;
}
return V_2 ;
}
static void V_153 ( struct V_18 * V_143 )
{
F_13 ( L_72 , V_143 ) ;
}
static T_7 F_60 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
char * V_174 )
{
struct V_175 * V_176 = F_61 ( V_173 ) ;
T_7 V_17 = 0 ;
struct V_177 * V_178 = F_62 ( V_171 ) ;
struct V_109 * V_134 ;
if ( V_178 != NULL )
V_134 = V_178 -> V_134 ;
else
V_134 = NULL ;
F_44 ( L_73 , V_134 -> V_103 ) ;
if ( V_134 ) {
if ( V_176 -> V_179 )
V_17 = V_176 -> V_179 ( V_134 , V_174 ) ;
}
return V_17 ;
}
static T_7 F_63 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
const char * V_174 , T_8 V_2 )
{
struct V_175 * V_176 = F_61 ( V_173 ) ;
T_7 V_17 = 0 ;
struct V_177 * V_178 = F_62 ( V_171 ) ;
struct V_109 * V_134 ;
if ( V_178 != NULL )
V_134 = V_178 -> V_134 ;
else
V_134 = NULL ;
F_44 ( L_74 , V_134 -> V_103 ) ;
if ( V_134 ) {
if ( V_176 -> V_180 )
V_17 = V_176 -> V_180 ( V_134 , V_174 , V_2 ) ;
}
return V_17 ;
}
int F_64 ( struct V_112 * V_110 )
{
int V_181 = 0 ;
F_44 ( L_75 ) ;
if ( V_110 -> V_116 == NULL ) {
F_5 ( L_76 ) ;
return 1 ;
}
V_110 -> V_182 . V_103 = V_110 -> V_103 ;
V_110 -> V_182 . V_28 = & V_29 ;
V_110 -> V_182 . V_139 = F_54 ;
V_110 -> V_182 . remove = F_57 ;
V_181 = F_65 ( & V_110 -> V_182 ) ;
if ( V_181 )
return V_181 ;
V_110 -> V_182 . V_183 -> V_171 . V_184 = & V_185 ;
return 0 ;
}
void F_66 ( struct V_112 * V_110 )
{
F_44 ( L_77 , V_110 ) ;
F_67 ( & V_110 -> V_182 ) ;
F_44 ( L_56 ) ;
}
static int F_68 ( struct V_18 * V_19 , void * V_66 )
{
struct V_186 * V_183 = (struct V_186 * ) V_66 ;
int V_187 = * ( V_183 -> V_188 ) ;
* ( V_183 -> V_188 ) = V_187 + sprintf ( V_183 -> V_174 + V_187 , L_78 , F_69 ( V_19 ) ) ;
return 0 ;
}
static T_7 F_70 ( struct V_189 * V_189 , char T_9 * V_174 ,
T_8 V_190 , T_10 * V_191 )
{
int V_188 = 0 ;
struct V_75 * V_76 ;
unsigned long V_74 ;
struct V_186 V_192 ;
char * V_193 ;
T_10 V_194 = * V_191 ;
if ( V_194 < 0 )
return - V_195 ;
if ( V_194 > 0 || ! V_190 )
return 0 ;
V_193 = F_9 ( V_190 , V_196 ) ;
if ( ! V_193 )
return - V_120 ;
V_188 += sprintf ( V_193 + V_188 , L_79 ) ;
V_188 += sprintf ( V_193 + V_188 , L_80 ) ;
V_192 . V_188 = & V_188 ;
V_192 . V_174 = V_193 ;
if ( F_40 ( & V_29 , NULL ,
( void * ) & V_192 , F_68 ) )
F_5 ( L_32 ) ;
V_188 += sprintf ( V_193 + V_188 , L_81 ) ;
F_71 ( & V_78 , V_74 ) ;
V_76 = V_79 ;
while ( V_76 ) {
if ( V_76 -> V_81 == V_51 ) {
V_188 += sprintf ( V_193 + V_188 , L_82 ,
V_76 -> V_23 , V_76 -> V_140 ,
V_76 -> V_40 . V_43 . V_44 ,
V_76 -> V_40 . V_43 . V_45 ,
V_76 -> V_40 . V_46 . V_47 ,
V_76 -> V_40 . V_46 . V_48 ,
V_76 -> V_40 . V_46 . V_49 ,
V_76 -> V_40 . V_46 . V_50 ) ;
} else {
V_188 += sprintf ( V_193 + V_188 , L_83 ,
V_76 -> V_23 , V_76 -> V_140 ,
V_76 -> V_53 . V_54 [ 0 ] ,
V_76 -> V_53 . V_54 [ 1 ] ,
V_76 -> V_53 . V_54 [ 2 ] ,
V_76 -> V_53 . V_54 [ 3 ] ,
V_76 -> V_53 . V_54 [ 4 ] ,
V_76 -> V_53 . V_54 [ 5 ] ,
V_76 -> V_53 . V_55 ,
V_76 -> V_53 . V_56 ) ;
}
V_188 +=
sprintf ( V_193 + V_188 , L_84 ,
V_76 -> V_149 . V_4 ) ;
V_76 = V_76 -> V_80 ;
}
F_72 ( & V_78 , V_74 ) ;
V_188 +=
sprintf ( V_193 + V_188 , L_85 , __DATE__ ,
__TIME__ ) ;
V_188 += sprintf ( V_193 + V_188 , L_86 ) ;
if ( F_73 ( V_174 , V_193 , V_188 ) ) {
F_26 ( V_193 ) ;
return - V_197 ;
}
F_26 ( V_193 ) ;
* V_191 += V_188 ;
return V_188 ;
}
static T_7 F_74 ( struct V_189 * V_189 , const char T_9 * V_198 ,
T_8 V_2 , T_10 * V_199 )
{
char V_174 [ 16 ] ;
int type , V_38 , V_200 = 0xffff ;
unsigned int V_201 , V_202 ;
void T_2 * V_1 ;
struct V_15 V_203 ;
struct V_37 V_16 ;
struct V_64 V_204 ;
struct V_73 V_65 ;
T_11 V_205 = V_206 ;
#ifdef F_75
T_12 V_207 ;
#endif
#define F_76 {\
LOGERR("usage: 0-0-<chanptr> ==> delete vhba\n"); \
LOGERR("usage: 0-1-<chanptr>-<busNo>-<deviceNo> ==> add vhba\n"); \
LOGERR("usage: 0-f-<busNo> ==> delete all vhbas\n"); \
LOGERR("\n"); \
LOGERR("usage: 1-0-<chanptr> ==> delete vnic\n"); \
LOGERR("usage: 1-1-<chanptr>-<busNo>-<deviceNo> ==> add vnic\n"); \
LOGERR("usage: 1-f-<busNo> ==> delete all vnics\n"); \
LOGERR("\n"); \
LOGERR("usage: 6-0-<busNo> ==> delete vbus\n"); \
LOGERR("usage: 6-1-<busNo> ==> add vbus\n"); \
LOGERR("usage: 6-f ==> delete all vbuses\n"); \
LOGERR("usage: 98-<busNo>-<deviceNo> ==> INJECT Client delete vnic\n"); \
LOGERR("usage: 99-<chanptr>-<busNo>-<deviceNo> ==> INJECT Client add vnic\n"); \
return -EINVAL; \
}
if ( V_2 >= F_77 ( V_174 ) )
return - V_195 ;
if ( F_78 ( V_174 , V_198 , V_2 ) ) {
F_5 ( L_87 ) ;
return - V_197 ;
}
V_38 = sscanf ( V_174 , L_88 , & type , & V_200 ) ;
if ( V_38 < 2 )
F_76 ;
if ( type == 0x98 ) {
V_38 = sscanf ( V_174 , L_89 , & type , & V_201 , & V_202 ) ;
if ( V_38 != 3 )
F_76 ;
F_79 ( V_201 , V_202 ) ;
return V_2 ;
} else if ( type == 0x99 ) {
V_38 = sscanf ( V_174 , L_90 , & type , & V_1 , & V_201 ,
& V_202 ) ;
if ( V_38 != 4 )
F_76 ;
if ( ! F_80 ( V_201 , V_202 ,
F_81 ( V_1 ) ,
V_208 ,
1 ,
V_205 ,
NULL ) ) {
F_5 ( L_91 ) ;
return - V_197 ;
}
return V_2 ;
}
if ( ( type != V_51 ) && ( type != V_63 )
&& ( type != V_209 ) )
F_76 ;
if ( type == V_209 ) {
V_38 = sscanf ( V_174 , L_92 , & type , & V_200 , & V_201 ) ;
switch ( V_200 ) {
case 0 :
if ( V_38 != 3 )
break;
V_204 . V_23 = V_201 ;
if ( F_22 ( & V_204 ) )
return V_2 ;
return - V_197 ;
case 1 :
if ( V_38 != 3 )
break;
V_203 . V_1 = NULL ;
V_203 . V_23 = V_201 ;
if ( F_8 ( & V_203 ) )
return V_2 ;
return - V_197 ;
case 0xf :
if ( V_38 != 2 )
break;
F_36 () ;
return V_2 ;
default:
break;
}
F_76 ;
}
switch ( V_200 ) {
case 0 :
V_38 = sscanf ( V_174 , L_93 , & type , & V_200 , & V_1 ) ;
if ( V_38 != 3 )
break;
V_65 . V_1 = V_1 ;
if ( type == V_51 ) {
if ( F_33 ( & V_65 ) )
return V_2 ;
} else {
if ( F_35 ( & V_65 ) )
return V_2 ;
}
return - V_197 ;
case 1 :
V_38 = sscanf ( V_174 , L_94 , & type , & V_200 , & V_1 ,
& V_201 , & V_202 ) ;
if ( V_38 != 5 )
break;
V_16 . V_1 = V_1 ;
V_16 . V_23 = V_201 ;
V_16 . V_140 = V_202 ;
if ( type == V_51 ) {
if ( F_15 ( & V_16 ) )
return V_2 ;
} else {
if ( F_20 ( & V_16 ) )
return V_2 ;
}
return - V_197 ;
#ifdef F_75
case 2 :
V_38 = sscanf ( V_174 , L_95 , & type , & V_200 , & V_201 ,
& V_202 ) ;
if ( V_38 != 4 )
break;
V_207 = F_82 ( 0 ) ;
V_16 . V_1 =
( void * ) F_83 ( V_207 , V_210 ) ;
if ( V_16 . V_1 == NULL ) {
F_5 ( L_96 ) ;
return - V_197 ;
}
V_16 . V_23 = V_201 ;
V_16 . V_140 = V_202 ;
if ( type == V_51 ) {
if ( F_15 ( & V_16 ) )
return V_2 ;
}
return - V_197 ;
#endif
case 0xf :
V_38 = sscanf ( V_174 , L_92 , & type , & V_200 , & V_201 ) ;
if ( V_38 != 3 )
break;
V_204 . V_23 = V_201 ;
F_41 ( type , & V_204 ) ;
return V_2 ;
default:
break;
}
F_76 ;
}
static int T_13 F_84 ( void )
{
int V_17 ;
F_13 ( L_97 , __DATE__ , __TIME__ ) ;
F_10 ( V_21 , V_22 ) ;
V_17 = F_85 ( & V_29 ) ;
if ( V_17 ) {
F_5 ( L_98 , V_17 ) ;
F_19 ( V_32 , V_17 ,
V_33 ) ;
return V_17 ;
}
F_44 ( L_99 ) ;
F_53 ( & V_35 ,
L_100 , L_101 ,
V_211 , NULL , __DATE__ , __TIME__ ) ;
V_17 = F_12 ( & V_27 ) ;
if ( V_17 ) {
F_5 ( L_6 , V_17 ) ;
F_86 ( & V_29 ) ;
F_19 ( V_32 , V_17 ,
V_33 ) ;
return V_17 ;
}
F_44 ( L_102 , V_17 ) ;
if ( ! F_87 ( 2 , ( void * ) & F_42 ,
& V_34 ) ) {
F_5 ( L_103 ) ;
F_10 ( V_32 , V_33 ) ;
F_25 ( & V_27 ) ;
F_86 ( & V_29 ) ;
return - 1 ;
}
F_13 ( L_104 ,
( void * ) & F_42 ) ;
V_212 = F_88 ( V_213 , NULL ) ;
V_214 = F_89 ( V_215 , 0 , V_212 ,
& V_216 ) ;
V_217 = F_89 ( V_218 , 0 , V_212 ,
& V_219 ) ;
F_13 ( L_56 ) ;
F_10 ( V_36 , V_22 ) ;
return 0 ;
}
static void T_14 F_90 ( void )
{
F_13 ( L_105 ) ;
if ( ! F_87 ( 2 , NULL , NULL ) )
F_5 ( L_103 ) ;
F_25 ( & V_27 ) ;
F_86 ( & V_29 ) ;
if ( V_214 )
F_91 ( V_215 , V_212 ) ;
if ( V_217 )
F_91 ( V_218 , V_212 ) ;
if ( V_212 )
F_91 ( V_213 , NULL ) ;
F_13 ( L_56 ) ;
}
