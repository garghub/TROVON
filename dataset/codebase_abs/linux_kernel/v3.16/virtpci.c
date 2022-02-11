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
V_16 -> V_1 , & V_53 . V_57 ) ;
V_38 = F_18 ( V_19 , V_58 , V_16 , NULL , & V_53 ) ;
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
F_22 ( struct V_59 * V_60 )
{
struct V_18 * V_19 ;
unsigned char V_41 [ V_42 ] ;
F_17 ( V_60 -> V_23 ) ;
F_13 ( L_14 , F_14 ( V_19 ) ) ;
if ( F_23 ( V_19 , NULL ) )
return 0 ;
F_13 ( L_15 , V_60 -> V_23 ) ;
return 1 ;
}
static int
F_23 ( struct V_18 * V_19 , void * V_61 )
{
int V_62 = ( V_61 != NULL ) ;
struct V_18 * V_63 = & V_27 ;
if ( ( V_62 ) && F_24 ( V_19 , ( void * ) F_14 ( V_63 ) ) ) {
F_13 ( L_16 ) ;
return 0 ;
}
F_13 ( L_17 , F_14 ( V_19 ) ) ;
F_25 ( V_19 ) ;
F_26 ( V_19 ) ;
F_13 ( L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_65 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_65 -> V_1 ) ;
F_13 ( L_19 , V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ) ;
V_38 = F_28 ( NULL , V_51 ,
& V_40 . V_43 , NULL ) ;
if ( V_38 )
F_13 ( L_20 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 ) ;
return V_38 ;
}
static int F_29 ( struct V_64 * V_65 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_65 -> V_1 ) ;
F_13 ( L_21 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_28 ( NULL , V_58 ,
NULL , V_53 . V_54 ) ;
if ( V_38 ) {
F_13 ( L_22 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
}
return V_38 ;
}
static int F_30 ( struct V_66 * V_67 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_67 -> V_1 ) ;
F_13 ( L_23 , V_40 . V_43 . V_44 , V_40 . V_43 . V_45 ) ;
V_38 = F_31 ( NULL , V_51 ,
& V_40 . V_43 , NULL ) ;
if ( V_38 )
F_13 ( L_24 , V_40 . V_43 . V_44 ,
V_40 . V_43 . V_45 ) ;
return V_38 ;
}
static int
F_32 ( struct V_66 * V_67 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_67 -> V_1 ) ;
F_13 ( L_25 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_31 ( NULL , V_58 ,
NULL , V_53 . V_54 ) ;
if ( V_38 ) {
F_13 ( L_26 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
}
return V_38 ;
}
static int F_33 ( struct V_68 * V_60 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_60 -> V_1 ) ;
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
static int F_35 ( struct V_68 * V_60 )
{
int V_38 ;
struct V_52 V_53 ;
F_21 ( V_60 -> V_1 ) ;
F_13 ( L_29 ,
V_53 . V_54 [ 0 ] , V_53 . V_54 [ 1 ] , V_53 . V_54 [ 2 ] ,
V_53 . V_54 [ 3 ] , V_53 . V_54 [ 4 ] , V_53 . V_54 [ 5 ] ) ;
V_38 = F_34 ( NULL , V_58 , NULL ,
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
unsigned long V_69 ;
struct V_70 * V_71 , * V_72 ;
F_37 ( & V_73 , V_69 ) ;
V_71 = V_74 ;
V_74 = NULL ;
F_38 ( & V_73 , V_69 ) ;
while ( V_71 ) {
V_72 = V_71 -> V_75 ;
F_39 ( V_71 ) ;
V_71 = V_72 ;
V_2 ++ ;
}
F_13 ( L_31 , V_2 ) ;
if ( F_40
( & V_29 , NULL , ( void * ) 1 , F_23 ) )
F_5 ( L_32 ) ;
}
static int F_41 ( T_5 V_76 , struct V_59 * V_60 )
{
int V_38 ;
unsigned char V_41 [ V_42 ] ;
struct V_18 * V_19 ;
F_17 ( V_60 -> V_23 ) ;
if ( ( V_76 != V_51 ) && ( V_76 != V_58 ) ) {
F_5 ( L_33 ,
V_76 , V_51 , V_58 ) ;
return 0 ;
}
F_13 ( L_34 ,
V_76 == V_51 ? L_35 : L_36 , V_41 ) ;
V_38 = F_34 ( V_19 , V_76 , NULL , NULL ) ;
if ( V_38 > 0 )
F_13 ( L_37 , V_38 ,
V_76 == V_51 ? L_35 : L_36 ) ;
return 1 ;
}
static int F_42 ( struct V_77 * V_78 )
{
switch ( V_78 -> V_79 ) {
case V_80 :
return F_8 ( & V_78 -> F_8 ) ;
case V_81 :
return F_15 ( & V_78 -> F_15 ) ;
case V_82 :
return F_20 ( & V_78 -> F_20 ) ;
case V_83 :
return F_22 ( & V_78 -> V_84 ) ;
case V_85 :
return F_33 ( & V_78 -> V_86 ) ;
case V_87 :
return F_35 ( & V_78 -> V_86 ) ;
case V_88 :
return F_41 ( V_51 , & V_78 -> V_89 ) ;
case V_90 :
return F_41 ( V_58 , & V_78 -> V_91 ) ;
case V_92 :
F_36 () ;
return 1 ;
case V_93 :
return F_27 ( & V_78 -> F_27 ) ;
case V_94 :
return F_29 ( & V_78 -> F_29 ) ;
case V_95 :
return F_30 ( & V_78 -> F_30 ) ;
case V_96 :
return F_32 ( & V_78 -> F_32 ) ;
default:
F_5 ( L_38 , V_78 -> V_79 ) ;
return 0 ;
}
}
static int F_24 ( struct V_18 * V_97 , void * V_61 )
{
const char * V_98 = V_61 ;
if ( strcmp ( V_98 , F_14 ( V_97 ) ) == 0 )
return 1 ;
return 0 ;
}
static const struct V_99 *
F_43 ( const struct V_99 * V_100 ,
const struct V_70 * V_97 )
{
while ( V_100 -> V_101 || V_100 -> V_102 || V_100 -> V_103 ) {
F_44 ( L_39 ,
V_100 -> V_101 , V_97 -> V_101 , V_100 -> V_18 , V_97 -> V_18 ) ;
if ( ( V_100 -> V_101 == V_97 -> V_101 )
&& ( V_100 -> V_18 == V_97 -> V_18 ) )
return V_100 ;
V_100 ++ ;
}
return NULL ;
}
static int F_45 ( struct V_18 * V_97 , struct V_104 * V_105 )
{
struct V_70 * V_106 = F_46 ( V_97 ) ;
struct V_107 * V_108 = F_47 ( V_105 ) ;
int V_109 = 0 ;
F_44 ( L_40 ,
V_97 -> V_110 , V_105 -> V_98 ) ;
if ( F_43 ( V_108 -> V_111 , V_106 ) )
V_109 = 1 ;
F_44 ( L_41 , V_109 ) ;
return V_109 ;
}
static int F_48 ( struct V_18 * V_97 , struct V_112 * V_113 )
{
F_44 ( L_42 ) ;
if ( F_49 ( V_113 , L_43 , V_114 ) )
return - V_115 ;
return 0 ;
}
static int F_50 ( struct V_18 * V_97 , T_6 V_116 )
{
F_44 ( L_44 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_97 )
{
F_44 ( L_45 ) ;
return 0 ;
}
static void F_52 ( struct V_18 * V_97 , int V_117 , int V_118 ,
struct V_107 * V_108 )
{
struct V_18 * V_19 ;
void * V_119 ;
T_4 V_120 ;
const char * V_121 ;
if ( ! V_97 ) {
F_5 ( L_46 , V_122 ) ;
return;
}
if ( ! V_108 ) {
F_5 ( L_47 , V_122 ) ;
return;
}
V_19 = V_97 -> V_26 ;
if ( ! V_19 ) {
F_5 ( L_48 , V_122 ) ;
return;
}
V_119 = V_19 -> V_30 ;
if ( ! V_119 ) {
F_5 ( L_49 , V_122 ) ;
return;
}
switch ( V_118 ) {
case V_123 :
V_121 = L_50 ;
break;
case V_124 :
V_121 = L_51 ;
break;
default:
V_121 = L_52 ;
break;
}
F_53 ( & V_120 , V_121 ,
V_108 -> V_98 ,
V_108 -> V_125 ,
V_108 -> V_126 ,
V_108 -> V_127 , V_108 -> V_128 ) ;
F_7 ( V_119 , & V_120 , V_117 ) ;
F_4 ( V_119 , & V_34 ) ;
F_6 ( V_119 , & V_35 ) ;
}
static int F_54 ( struct V_18 * V_97 )
{
struct V_70 * V_106 = F_46 ( V_97 ) ;
struct V_107 * V_108 =
F_47 ( V_97 -> V_129 ) ;
const struct V_99 * V_130 ;
int error = 0 ;
F_13 ( L_53 ,
V_97 , V_106 , V_108 ) ;
F_10 ( V_131 , V_22 ) ;
if ( ! V_108 -> V_111 )
return - V_132 ;
V_130 = F_43 ( V_108 -> V_111 , V_106 ) ;
if ( ! V_130 )
return - V_132 ;
F_55 ( V_97 ) ;
if ( ! V_106 -> V_133 && V_108 -> V_134 ) {
error = V_108 -> V_134 ( V_106 , V_130 ) ;
if ( ! error ) {
F_52 ( V_97 , V_106 -> V_135 ,
V_106 -> V_18 , V_108 ) ;
V_106 -> V_133 = V_108 ;
F_10 ( V_136 ,
V_22 ) ;
} else
F_56 ( V_97 ) ;
}
F_10 ( V_137 , V_33 ) ;
return error ;
}
static int F_57 ( struct V_18 * V_138 )
{
struct V_70 * V_106 = F_46 ( V_138 ) ;
struct V_107 * V_108 = V_106 -> V_133 ;
F_13 ( L_54 ,
F_14 ( V_138 ) , V_138 , V_106 , V_138 -> V_129 ,
V_138 -> V_129 -> V_98 ) ;
if ( V_108 ) {
if ( V_108 -> remove )
V_108 -> remove ( V_106 ) ;
V_106 -> V_133 = NULL ;
}
F_44 ( L_55 ) ;
F_56 ( V_138 ) ;
F_44 ( L_56 ) ;
return 0 ;
}
static void V_25 ( struct V_18 * V_97 )
{
F_44 ( L_57 ) ;
}
static int F_18 ( struct V_18 * V_139 , int V_76 ,
struct V_37 * V_16 ,
struct V_39 * V_40 ,
struct V_52 * V_53 )
{
struct V_70 * V_106 = NULL ;
struct V_70 * V_71 = NULL , * V_140 ;
unsigned long V_69 ;
int V_17 ;
T_1 T_2 * V_141 = NULL ;
struct V_18 * V_63 ;
F_13 ( L_58 , V_139 ,
V_16 -> V_1 ) ;
F_10 ( V_21 , V_22 ) ;
if ( ( V_76 != V_51 ) && ( V_76 != V_58 ) ) {
F_5 ( L_59 ,
V_76 , V_51 , V_58 ) ;
F_19 ( V_32 , V_76 ,
V_33 ) ;
return 0 ;
}
V_106 = F_9 ( sizeof( struct V_70 ) , V_20 ) ;
if ( V_106 == NULL ) {
F_5 ( L_60 ) ;
F_10 ( V_142 , V_33 ) ;
return 0 ;
}
V_106 -> V_76 = V_76 ;
if ( V_76 == V_51 ) {
V_106 -> V_18 = V_123 ;
V_106 -> V_40 = * V_40 ;
} else {
V_106 -> V_18 = V_124 ;
V_106 -> V_53 = * V_53 ;
}
V_106 -> V_101 = V_143 ;
V_106 -> V_23 = V_16 -> V_23 ;
V_106 -> V_135 = V_16 -> V_135 ;
V_106 -> V_144 . V_4 = V_16 -> V_1 ;
V_106 -> V_144 . V_145 = NULL ;
V_141 = ( T_1 T_2 * )
V_106 -> V_144 . V_4 ;
V_106 -> V_146 = V_16 -> V_146 ;
V_106 -> V_147 . V_28 = & V_29 ;
V_106 -> V_147 . V_26 = V_139 ;
V_106 -> V_147 . V_24 = V_148 ;
F_11 ( & V_106 -> V_147 , L_61 ,
V_16 -> V_23 , V_16 -> V_135 ) ;
F_37 ( & V_73 , V_69 ) ;
for ( V_71 = V_74 ; V_71 ;
V_71 = V_71 -> V_75 ) {
if ( V_76 == V_51 ) {
if ( ( V_71 -> V_40 . V_43 . V_44 == V_40 -> V_43 . V_44 ) &&
( V_71 -> V_40 . V_43 . V_45 == V_40 -> V_43 . V_45 ) ) {
break;
}
} else
if ( memcmp
( V_71 -> V_53 . V_54 , V_53 -> V_54 ,
V_149 ) == 0 ) {
break;
}
}
if ( V_71 ) {
F_38 ( & V_73 , V_69 ) ;
F_26 ( V_106 ) ;
F_5 ( L_62 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
if ( ! V_74 )
V_74 = V_106 ;
else {
V_106 -> V_75 = V_74 ;
V_74 = V_106 ;
}
F_38 ( & V_73 , V_69 ) ;
V_63 = & V_106 -> V_147 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_63 ) ,
V_150 , NULL ) ;
F_44 ( L_63 ,
& V_106 -> V_147 , V_106 -> V_147 . V_110 ) ;
V_17 = F_12 ( & V_106 -> V_147 ) ;
if ( V_17 ) {
F_5 ( L_64 , V_17 ) ;
V_63 = & V_106 -> V_147 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_63 ) ,
V_151 , NULL ) ;
F_37 ( & V_73 , V_69 ) ;
for ( V_71 = V_74 , V_140 = NULL ;
V_71 ;
V_140 = V_71 , V_71 = V_71 -> V_75 ) {
if ( V_71 == V_106 ) {
if ( V_140 )
V_140 -> V_75 = V_71 -> V_75 ;
else
V_74 = V_71 -> V_75 ;
break;
}
}
F_38 ( & V_73 , V_69 ) ;
F_26 ( V_106 ) ;
return 0 ;
}
F_13 ( L_65 ,
( V_76 == V_51 ) ? L_66 : L_67 ,
V_16 -> V_23 , V_16 -> V_135 , & V_106 -> V_147 ) ;
F_10 ( V_36 , V_22 ) ;
return 1 ;
}
static int F_28 ( struct V_18 * V_139 ,
int V_76 ,
struct V_152 * V_43 ,
unsigned char V_153 [] )
{
int V_154 = 0 ;
bool V_155 = false ;
struct V_70 * V_71 , * V_156 ;
struct V_107 * V_157 ;
unsigned long V_69 ;
int V_158 = 0 ;
if ( ( V_76 != V_51 ) && ( V_76 != V_58 ) ) {
F_5 ( L_68 ,
V_76 , V_51 , V_58 ) ;
return 0 ;
}
F_37 ( & V_73 , V_69 ) ;
for ( V_71 = V_74 , V_156 = NULL ;
( V_71 && ! V_155 ) ;
V_156 = V_71 , V_71 = V_71 -> V_75 ) {
if ( V_71 -> V_76 != V_76 )
continue;
if ( V_76 == V_51 ) {
V_154 =
( ( V_71 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_71 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_154 =
memcmp ( V_71 -> V_53 . V_54 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_154 )
continue;
V_155 = true ;
V_157 = V_71 -> V_133 ;
V_158 = V_157 -> V_159 ( V_71 , 0 ) ;
}
F_38 ( & V_73 , V_69 ) ;
if ( ! V_155 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_158 ;
}
static int F_31 ( struct V_18 * V_139 ,
int V_76 ,
struct V_152 * V_43 ,
unsigned char V_153 [] )
{
int V_160 = 0 ;
bool V_155 = false ;
struct V_70 * V_71 , * V_156 ;
struct V_107 * V_157 ;
unsigned long V_69 ;
int V_158 = 0 ;
if ( ( V_76 != V_51 ) && ( V_76 != V_58 ) ) {
F_5 ( L_70 ,
V_76 , V_51 , V_58 ) ;
return 0 ;
}
F_37 ( & V_73 , V_69 ) ;
for ( V_71 = V_74 , V_156 = NULL ;
( V_71 && ! V_155 ) ;
V_156 = V_71 , V_71 = V_71 -> V_75 ) {
if ( V_71 -> V_76 != V_76 )
continue;
if ( V_76 == V_51 ) {
V_160 =
( ( V_71 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_71 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_160 =
memcmp ( V_71 -> V_53 . V_54 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_160 )
continue;
V_155 = true ;
V_157 = V_71 -> V_133 ;
F_52 ( & V_71 -> V_147 , V_71 -> V_135 ,
V_71 -> V_18 , V_157 ) ;
V_158 = V_157 -> V_161 ( V_71 ) ;
}
F_38 ( & V_73 , V_69 ) ;
if ( ! V_155 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_158 ;
}
static int F_34 ( struct V_18 * V_139 ,
int V_76 , struct V_152 * V_43 ,
unsigned char V_153 [] )
{
int V_2 = 0 , V_162 = 0 , V_163 ;
struct V_70 * V_71 , * V_156 , * V_164 = NULL ;
unsigned long V_69 ;
#define F_59 { \
prevvpcidev = tmpvpcidev;\
tmpvpcidev = tmpvpcidev->next;\
continue; \
}
if ( ( V_76 != V_51 ) && ( V_76 != V_58 ) ) {
F_5 ( L_71 ,
V_76 , V_51 , V_58 ) ;
return 0 ;
}
V_162 = ( ( V_76 == V_51 ) && ( V_43 == NULL ) ) ||
( ( V_76 == V_58 ) && ( V_153 == NULL ) ) ;
F_37 ( & V_73 , V_69 ) ;
for ( V_71 = V_74 , V_156 = NULL ; V_71 ; ) {
if ( V_71 -> V_76 != V_76 )
F_59 ;
if ( V_162 ) {
V_163 =
( V_71 -> V_147 . V_26 == V_139 ) ;
} else if ( V_76 == V_51 ) {
V_163 =
( ( V_71 -> V_40 . V_43 . V_44 == V_43 -> V_44 ) &&
( V_71 -> V_40 . V_43 . V_45 == V_43 -> V_45 ) ) ;
} else {
V_163 =
memcmp ( V_71 -> V_53 . V_54 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_163 )
F_59 ;
if ( V_156 )
V_156 -> V_75 = V_71 -> V_75 ;
else
V_74 = V_71 -> V_75 ;
V_71 -> V_75 = V_164 ;
V_164 = V_71 ;
V_2 ++ ;
if ( ! V_162 )
break;
if ( V_156 )
V_71 = V_156 -> V_75 ;
else
V_71 = V_74 ;
}
F_38 ( & V_73 , V_69 ) ;
if ( ! V_162 && ( V_2 == 0 ) ) {
F_5 ( L_69 ) ;
return 0 ;
}
while ( V_164 ) {
V_71 = V_164 -> V_75 ;
F_39 ( V_164 ) ;
V_164 = V_71 ;
}
return V_2 ;
}
static void V_148 ( struct V_18 * V_138 )
{
F_13 ( L_72 , V_138 ) ;
}
static T_7 F_60 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
char * V_169 )
{
struct V_170 * V_171 = F_61 ( V_168 ) ;
T_7 V_17 = 0 ;
struct V_172 * V_173 = F_62 ( V_166 ) ;
struct V_104 * V_129 ;
if ( V_173 != NULL )
V_129 = V_173 -> V_129 ;
else
V_129 = NULL ;
F_44 ( L_73 , V_129 -> V_98 ) ;
if ( V_129 ) {
if ( V_171 -> V_174 )
V_17 = V_171 -> V_174 ( V_129 , V_169 ) ;
}
return V_17 ;
}
static T_7 F_63 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
const char * V_169 , T_8 V_2 )
{
struct V_170 * V_171 = F_61 ( V_168 ) ;
T_7 V_17 = 0 ;
struct V_172 * V_173 = F_62 ( V_166 ) ;
struct V_104 * V_129 ;
if ( V_173 != NULL )
V_129 = V_173 -> V_129 ;
else
V_129 = NULL ;
F_44 ( L_74 , V_129 -> V_98 ) ;
if ( V_129 ) {
if ( V_171 -> V_175 )
V_17 = V_171 -> V_175 ( V_129 , V_169 , V_2 ) ;
}
return V_17 ;
}
int F_64 ( struct V_107 * V_105 )
{
int V_176 = 0 ;
F_44 ( L_75 ) ;
if ( V_105 -> V_111 == NULL ) {
F_5 ( L_76 ) ;
return 1 ;
}
V_105 -> V_177 . V_98 = V_105 -> V_98 ;
V_105 -> V_177 . V_28 = & V_29 ;
V_105 -> V_177 . V_134 = F_54 ;
V_105 -> V_177 . remove = F_57 ;
V_176 = F_65 ( & V_105 -> V_177 ) ;
if ( V_176 )
return V_176 ;
V_105 -> V_177 . V_178 -> V_166 . V_179 = & V_180 ;
return 0 ;
}
void F_66 ( struct V_107 * V_105 )
{
F_44 ( L_77 , V_105 ) ;
F_67 ( & V_105 -> V_177 ) ;
F_44 ( L_56 ) ;
}
static int F_68 ( struct V_18 * V_19 , void * V_61 )
{
struct V_181 * V_178 = (struct V_181 * ) V_61 ;
int V_182 = * ( V_178 -> V_183 ) ;
* ( V_178 -> V_183 ) = V_182 + sprintf ( V_178 -> V_169 + V_182 , L_78 , F_69 ( V_19 ) ) ;
return 0 ;
}
static T_7 F_70 ( struct V_184 * V_184 , char T_9 * V_169 ,
T_8 V_185 , T_10 * V_186 )
{
int V_183 = 0 ;
struct V_70 * V_71 ;
unsigned long V_69 ;
struct V_181 V_187 ;
char * V_188 ;
T_10 V_189 = * V_186 ;
if ( V_189 < 0 )
return - V_190 ;
if ( V_189 > 0 || ! V_185 )
return 0 ;
V_188 = F_9 ( V_185 , V_191 ) ;
if ( ! V_188 )
return - V_115 ;
V_183 += sprintf ( V_188 + V_183 , L_79 ) ;
V_183 += sprintf ( V_188 + V_183 , L_80 ) ;
V_187 . V_183 = & V_183 ;
V_187 . V_169 = V_188 ;
if ( F_40 ( & V_29 , NULL ,
( void * ) & V_187 , F_68 ) )
F_5 ( L_32 ) ;
V_183 += sprintf ( V_188 + V_183 , L_81 ) ;
F_71 ( & V_73 , V_69 ) ;
V_71 = V_74 ;
while ( V_71 ) {
if ( V_71 -> V_76 == V_51 ) {
V_183 += sprintf ( V_188 + V_183 , L_82 ,
V_71 -> V_23 , V_71 -> V_135 ,
V_71 -> V_40 . V_43 . V_44 ,
V_71 -> V_40 . V_43 . V_45 ,
V_71 -> V_40 . V_46 . V_47 ,
V_71 -> V_40 . V_46 . V_48 ,
V_71 -> V_40 . V_46 . V_49 ,
V_71 -> V_40 . V_46 . V_50 ) ;
} else {
V_183 += sprintf ( V_188 + V_183 , L_83 ,
V_71 -> V_23 , V_71 -> V_135 ,
V_71 -> V_53 . V_54 [ 0 ] ,
V_71 -> V_53 . V_54 [ 1 ] ,
V_71 -> V_53 . V_54 [ 2 ] ,
V_71 -> V_53 . V_54 [ 3 ] ,
V_71 -> V_53 . V_54 [ 4 ] ,
V_71 -> V_53 . V_54 [ 5 ] ,
V_71 -> V_53 . V_55 ,
V_71 -> V_53 . V_56 ) ;
}
V_183 +=
sprintf ( V_188 + V_183 , L_84 ,
V_71 -> V_144 . V_4 ) ;
V_71 = V_71 -> V_75 ;
}
F_72 ( & V_73 , V_69 ) ;
V_183 +=
sprintf ( V_188 + V_183 , L_85 , __DATE__ ,
__TIME__ ) ;
V_183 += sprintf ( V_188 + V_183 , L_86 ) ;
if ( F_73 ( V_169 , V_188 , V_183 ) ) {
F_26 ( V_188 ) ;
return - V_192 ;
}
F_26 ( V_188 ) ;
* V_186 += V_183 ;
return V_183 ;
}
static T_7 F_74 ( struct V_184 * V_184 , const char T_9 * V_193 ,
T_8 V_2 , T_10 * V_194 )
{
char V_169 [ 16 ] ;
int type , V_38 , V_195 = 0xffff ;
unsigned int V_196 , V_197 ;
void T_2 * V_1 ;
struct V_15 V_198 ;
struct V_37 V_16 ;
struct V_59 V_199 ;
struct V_68 V_60 ;
#ifdef F_75
T_11 V_200 ;
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
if ( V_2 >= F_77 ( V_169 ) )
return - V_190 ;
if ( F_78 ( V_169 , V_193 , V_2 ) ) {
F_5 ( L_87 ) ;
return - V_192 ;
}
V_38 = sscanf ( V_169 , L_88 , & type , & V_195 ) ;
if ( V_38 < 2 )
F_76 ;
if ( type == 0x98 ) {
V_38 = sscanf ( V_169 , L_89 , & type , & V_196 , & V_197 ) ;
if ( V_38 != 3 )
F_76 ;
F_79 ( V_196 , V_197 ) ;
return V_2 ;
} else if ( type == 0x99 ) {
V_38 = sscanf ( V_169 , L_90 , & type , & V_1 , & V_196 ,
& V_197 ) ;
if ( V_38 != 4 )
F_76 ;
if ( ! F_80 ( V_196 , V_197 ,
F_81 ( V_1 ) ,
V_201 ,
1 ,
V_202 ,
NULL ) ) {
F_5 ( L_91 ) ;
return - V_192 ;
}
return V_2 ;
}
if ( ( type != V_51 ) && ( type != V_58 )
&& ( type != V_203 ) )
F_76 ;
if ( type == V_203 ) {
V_38 = sscanf ( V_169 , L_92 , & type , & V_195 , & V_196 ) ;
switch ( V_195 ) {
case 0 :
if ( V_38 != 3 )
break;
V_199 . V_23 = V_196 ;
if ( F_22 ( & V_199 ) )
return V_2 ;
return - V_192 ;
case 1 :
if ( V_38 != 3 )
break;
V_198 . V_1 = NULL ;
V_198 . V_23 = V_196 ;
if ( F_8 ( & V_198 ) )
return V_2 ;
return - V_192 ;
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
switch ( V_195 ) {
case 0 :
V_38 = sscanf ( V_169 , L_93 , & type , & V_195 , & V_1 ) ;
if ( V_38 != 3 )
break;
V_60 . V_1 = V_1 ;
if ( type == V_51 ) {
if ( F_33 ( & V_60 ) )
return V_2 ;
} else {
if ( F_35 ( & V_60 ) )
return V_2 ;
}
return - V_192 ;
case 1 :
V_38 = sscanf ( V_169 , L_94 , & type , & V_195 , & V_1 ,
& V_196 , & V_197 ) ;
if ( V_38 != 5 )
break;
V_16 . V_1 = V_1 ;
V_16 . V_23 = V_196 ;
V_16 . V_135 = V_197 ;
if ( type == V_51 ) {
if ( F_15 ( & V_16 ) )
return V_2 ;
} else {
if ( F_20 ( & V_16 ) )
return V_2 ;
}
return - V_192 ;
#ifdef F_75
case 2 :
V_38 = sscanf ( V_169 , L_95 , & type , & V_195 , & V_196 ,
& V_197 ) ;
if ( V_38 != 4 )
break;
V_200 = F_82 ( 0 ) ;
V_16 . V_1 =
( void * ) F_83 ( V_200 , V_204 ) ;
if ( V_16 . V_1 == NULL ) {
F_5 ( L_96 ) ;
return - V_192 ;
}
V_16 . V_23 = V_196 ;
V_16 . V_135 = V_197 ;
if ( type == V_51 ) {
if ( F_15 ( & V_16 ) )
return V_2 ;
}
return - V_192 ;
#endif
case 0xf :
V_38 = sscanf ( V_169 , L_92 , & type , & V_195 , & V_196 ) ;
if ( V_38 != 3 )
break;
V_199 . V_23 = V_196 ;
F_41 ( type , & V_199 ) ;
return V_2 ;
default:
break;
}
F_76 ;
}
static int T_12 F_84 ( void )
{
int V_17 ;
if ( ! V_205 )
return - V_132 ;
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
V_206 , NULL , __DATE__ , __TIME__ ) ;
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
V_207 = F_88 ( V_208 , NULL ) ;
V_209 = F_89 ( V_210 , 0 , V_207 ,
& V_211 ) ;
V_212 = F_89 ( V_213 , 0 , V_207 ,
& V_214 ) ;
F_13 ( L_56 ) ;
F_10 ( V_36 , V_22 ) ;
return 0 ;
}
static void T_13 F_90 ( void )
{
F_13 ( L_105 ) ;
if ( ! F_87 ( 2 , NULL , NULL ) )
F_5 ( L_103 ) ;
F_25 ( & V_27 ) ;
F_86 ( & V_29 ) ;
if ( V_209 )
F_91 ( V_210 , V_207 ) ;
if ( V_212 )
F_91 ( V_213 , V_207 ) ;
if ( V_207 )
F_91 ( V_208 , NULL ) ;
F_13 ( L_56 ) ;
}
