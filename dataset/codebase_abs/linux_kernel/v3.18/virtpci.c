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
F_17 ( V_16 -> V_43 ) ;
F_13 ( L_9 ,
V_40 . V_44 . V_45 , V_40 . V_44 . V_46 ,
V_40 . V_47 . V_48 , V_40 . V_47 . V_49 , V_40 . V_47 . V_50 ,
V_40 . V_47 . V_51 , V_16 -> V_1 ) ;
V_38 = F_18 ( V_19 , V_52 , V_16 , & V_40 , NULL ) ;
if ( V_38 ) {
F_13 ( L_10 , V_40 . V_44 . V_45 ,
V_40 . V_44 . V_46 , V_16 -> V_1 ) ;
F_19 ( V_36 , V_38 ,
V_22 ) ;
}
return V_38 ;
}
static int
F_20 ( struct V_37 * V_16 )
{
int V_38 ;
struct V_53 V_54 ;
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
F_17 ( V_16 -> V_43 ) ;
F_13 ( L_12 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] , V_54 . V_55 [ 3 ] ,
V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] , V_54 . V_56 , V_54 . V_57 ,
V_16 -> V_1 , & V_54 . V_58 ) ;
V_38 = F_18 ( V_19 , V_59 , V_16 , NULL , & V_54 ) ;
if ( V_38 ) {
F_13 ( L_13 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
F_19 ( V_36 , V_38 ,
V_22 ) ;
return 1 ;
}
return 0 ;
}
static int
F_22 ( struct V_60 * V_61 )
{
struct V_18 * V_19 ;
unsigned char V_41 [ V_42 ] ;
F_17 ( V_61 -> V_43 ) ;
F_13 ( L_14 , F_14 ( V_19 ) ) ;
if ( F_23 ( V_19 , NULL ) )
return 0 ;
F_13 ( L_15 , V_61 -> V_43 ) ;
return 1 ;
}
static int
F_23 ( struct V_18 * V_19 , void * V_62 )
{
int V_63 = ( V_62 != NULL ) ;
struct V_18 * V_64 = & V_27 ;
if ( ( V_63 ) && F_24 ( V_19 , ( void * ) F_14 ( V_64 ) ) ) {
F_13 ( L_16 ) ;
return 0 ;
}
F_13 ( L_17 , F_14 ( V_19 ) ) ;
F_25 ( V_19 ) ;
F_26 ( V_19 ) ;
F_13 ( L_18 ) ;
return 0 ;
}
static int F_27 ( struct V_65 * V_66 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_66 -> V_1 ) ;
F_13 ( L_19 , V_40 . V_44 . V_45 , V_40 . V_44 . V_46 ) ;
V_38 = F_28 ( NULL , V_52 ,
& V_40 . V_44 , NULL ) ;
if ( V_38 )
F_13 ( L_20 , V_40 . V_44 . V_45 ,
V_40 . V_44 . V_46 ) ;
return V_38 ;
}
static int F_29 ( struct V_65 * V_66 )
{
int V_38 ;
struct V_53 V_54 ;
F_21 ( V_66 -> V_1 ) ;
F_13 ( L_21 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
V_38 = F_28 ( NULL , V_59 ,
NULL , V_54 . V_55 ) ;
if ( V_38 ) {
F_13 ( L_22 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
}
return V_38 ;
}
static int F_30 ( struct V_67 * V_68 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_68 -> V_1 ) ;
F_13 ( L_23 , V_40 . V_44 . V_45 , V_40 . V_44 . V_46 ) ;
V_38 = F_31 ( NULL , V_52 ,
& V_40 . V_44 , NULL ) ;
if ( V_38 )
F_13 ( L_24 , V_40 . V_44 . V_45 ,
V_40 . V_44 . V_46 ) ;
return V_38 ;
}
static int
F_32 ( struct V_67 * V_68 )
{
int V_38 ;
struct V_53 V_54 ;
F_21 ( V_68 -> V_1 ) ;
F_13 ( L_25 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
V_38 = F_31 ( NULL , V_59 ,
NULL , V_54 . V_55 ) ;
if ( V_38 ) {
F_13 ( L_26 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
}
return V_38 ;
}
static int F_33 ( struct V_69 * V_61 )
{
int V_38 ;
struct V_39 V_40 ;
F_16 ( V_61 -> V_1 ) ;
F_13 ( L_27 , V_40 . V_44 . V_45 , V_40 . V_44 . V_46 ) ;
V_38 = F_34 ( NULL , V_52 ,
& V_40 . V_44 , NULL ) ;
if ( V_38 ) {
F_13 ( L_28 , V_40 . V_44 . V_45 ,
V_40 . V_44 . V_46 ) ;
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_69 * V_61 )
{
int V_38 ;
struct V_53 V_54 ;
F_21 ( V_61 -> V_1 ) ;
F_13 ( L_29 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
V_38 = F_34 ( NULL , V_59 , NULL ,
V_54 . V_55 ) ;
if ( V_38 ) {
F_13 ( L_30 ,
V_54 . V_55 [ 0 ] , V_54 . V_55 [ 1 ] , V_54 . V_55 [ 2 ] ,
V_54 . V_55 [ 3 ] , V_54 . V_55 [ 4 ] , V_54 . V_55 [ 5 ] ) ;
}
return V_38 ;
}
static void F_36 ( void )
{
int V_2 = 0 ;
unsigned long V_70 ;
struct V_71 * V_72 , * V_73 ;
F_37 ( & V_74 , V_70 ) ;
V_72 = V_75 ;
V_75 = NULL ;
F_38 ( & V_74 , V_70 ) ;
while ( V_72 ) {
V_73 = V_72 -> V_76 ;
F_39 ( V_72 ) ;
V_72 = V_73 ;
V_2 ++ ;
}
F_13 ( L_31 , V_2 ) ;
if ( F_40
( & V_29 , NULL , ( void * ) 1 , F_23 ) )
F_5 ( L_32 ) ;
}
static int F_41 ( T_5 V_77 , struct V_60 * V_61 )
{
int V_38 ;
unsigned char V_41 [ V_42 ] ;
struct V_18 * V_19 ;
F_17 ( V_61 -> V_43 ) ;
if ( ( V_77 != V_52 ) && ( V_77 != V_59 ) ) {
F_5 ( L_33 ,
V_77 , V_52 , V_59 ) ;
return 0 ;
}
F_13 ( L_34 ,
V_77 == V_52 ? L_35 : L_36 , V_41 ) ;
V_38 = F_34 ( V_19 , V_77 , NULL , NULL ) ;
if ( V_38 > 0 )
F_13 ( L_37 , V_38 ,
V_77 == V_52 ? L_35 : L_36 ) ;
return 1 ;
}
static int F_42 ( struct V_78 * V_79 )
{
switch ( V_79 -> V_80 ) {
case V_81 :
return F_8 ( & V_79 -> F_8 ) ;
case V_82 :
return F_15 ( & V_79 -> F_15 ) ;
case V_83 :
return F_20 ( & V_79 -> F_20 ) ;
case V_84 :
return F_22 ( & V_79 -> V_85 ) ;
case V_86 :
return F_33 ( & V_79 -> V_87 ) ;
case V_88 :
return F_35 ( & V_79 -> V_87 ) ;
case V_89 :
return F_41 ( V_52 , & V_79 -> V_90 ) ;
case V_91 :
return F_41 ( V_59 , & V_79 -> V_92 ) ;
case V_93 :
F_36 () ;
return 1 ;
case V_94 :
return F_27 ( & V_79 -> F_27 ) ;
case V_95 :
return F_29 ( & V_79 -> F_29 ) ;
case V_96 :
return F_30 ( & V_79 -> F_30 ) ;
case V_97 :
return F_32 ( & V_79 -> F_32 ) ;
default:
F_5 ( L_38 , V_79 -> V_80 ) ;
return 0 ;
}
}
static int F_24 ( struct V_18 * V_98 , void * V_62 )
{
const char * V_99 = V_62 ;
if ( strcmp ( V_99 , F_14 ( V_98 ) ) == 0 )
return 1 ;
return 0 ;
}
static const struct V_100 *
F_43 ( const struct V_100 * V_101 ,
const struct V_71 * V_98 )
{
while ( V_101 -> V_102 || V_101 -> V_103 || V_101 -> V_104 ) {
F_44 ( L_39 ,
V_101 -> V_102 , V_98 -> V_102 , V_101 -> V_18 , V_98 -> V_18 ) ;
if ( ( V_101 -> V_102 == V_98 -> V_102 )
&& ( V_101 -> V_18 == V_98 -> V_18 ) )
return V_101 ;
V_101 ++ ;
}
return NULL ;
}
static int F_45 ( struct V_18 * V_98 , struct V_105 * V_106 )
{
struct V_71 * V_107 = F_46 ( V_98 ) ;
struct V_108 * V_109 = F_47 ( V_106 ) ;
int V_110 = 0 ;
F_44 ( L_40 ,
V_98 -> V_111 , V_106 -> V_99 ) ;
if ( F_43 ( V_109 -> V_112 , V_107 ) )
V_110 = 1 ;
F_44 ( L_41 , V_110 ) ;
return V_110 ;
}
static int F_48 ( struct V_18 * V_98 , struct V_113 * V_114 )
{
F_44 ( L_42 ) ;
if ( F_49 ( V_114 , L_43 , V_115 ) )
return - V_116 ;
return 0 ;
}
static int F_50 ( struct V_18 * V_98 , T_6 V_117 )
{
F_44 ( L_44 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_98 )
{
F_44 ( L_45 ) ;
return 0 ;
}
static void F_52 ( struct V_18 * V_98 , int V_118 , int V_119 ,
struct V_108 * V_109 )
{
struct V_18 * V_19 ;
void * V_120 ;
T_4 V_121 ;
const char * V_122 ;
if ( ! V_98 ) {
F_5 ( L_46 , V_123 ) ;
return;
}
if ( ! V_109 ) {
F_5 ( L_47 , V_123 ) ;
return;
}
V_19 = V_98 -> V_26 ;
if ( ! V_19 ) {
F_5 ( L_48 , V_123 ) ;
return;
}
V_120 = V_19 -> V_30 ;
if ( ! V_120 ) {
F_5 ( L_49 , V_123 ) ;
return;
}
switch ( V_119 ) {
case V_124 :
V_122 = L_50 ;
break;
case V_125 :
V_122 = L_51 ;
break;
default:
V_122 = L_52 ;
break;
}
F_53 ( & V_121 , V_122 ,
V_109 -> V_99 ,
V_109 -> V_126 ,
V_109 -> V_127 ) ;
F_7 ( V_120 , & V_121 , V_118 ) ;
F_4 ( V_120 , & V_34 ) ;
F_6 ( V_120 , & V_35 ) ;
}
static int F_54 ( struct V_18 * V_98 )
{
struct V_71 * V_107 = F_46 ( V_98 ) ;
struct V_108 * V_109 =
F_47 ( V_98 -> V_128 ) ;
const struct V_100 * V_129 ;
int error = 0 ;
F_13 ( L_53 ,
V_98 , V_107 , V_109 ) ;
F_10 ( V_130 , V_22 ) ;
if ( ! V_109 -> V_112 )
return - V_131 ;
V_129 = F_43 ( V_109 -> V_112 , V_107 ) ;
if ( ! V_129 )
return - V_131 ;
F_55 ( V_98 ) ;
if ( ! V_107 -> V_132 && V_109 -> V_133 ) {
error = V_109 -> V_133 ( V_107 , V_129 ) ;
if ( ! error ) {
F_52 ( V_98 , V_107 -> V_134 ,
V_107 -> V_18 , V_109 ) ;
V_107 -> V_132 = V_109 ;
F_10 ( V_135 ,
V_22 ) ;
} else
F_56 ( V_98 ) ;
}
F_10 ( V_136 , V_33 ) ;
return error ;
}
static int F_57 ( struct V_18 * V_137 )
{
struct V_71 * V_107 = F_46 ( V_137 ) ;
struct V_108 * V_109 = V_107 -> V_132 ;
F_13 ( L_54 ,
F_14 ( V_137 ) , V_137 , V_107 , V_137 -> V_128 ,
V_137 -> V_128 -> V_99 ) ;
if ( V_109 ) {
if ( V_109 -> remove )
V_109 -> remove ( V_107 ) ;
V_107 -> V_132 = NULL ;
}
F_44 ( L_55 ) ;
F_56 ( V_137 ) ;
F_44 ( L_56 ) ;
return 0 ;
}
static void V_25 ( struct V_18 * V_98 )
{
F_44 ( L_57 ) ;
}
static int F_18 ( struct V_18 * V_138 , int V_77 ,
struct V_37 * V_16 ,
struct V_39 * V_40 ,
struct V_53 * V_54 )
{
struct V_71 * V_107 = NULL ;
struct V_71 * V_72 = NULL , * V_139 ;
unsigned long V_70 ;
int V_17 ;
T_1 T_2 * V_140 = NULL ;
struct V_18 * V_64 ;
F_13 ( L_58 , V_138 ,
V_16 -> V_1 ) ;
F_10 ( V_21 , V_22 ) ;
if ( ( V_77 != V_52 ) && ( V_77 != V_59 ) ) {
F_5 ( L_59 ,
V_77 , V_52 , V_59 ) ;
F_19 ( V_32 , V_77 ,
V_33 ) ;
return 0 ;
}
V_107 = F_9 ( sizeof( struct V_71 ) , V_20 ) ;
if ( V_107 == NULL ) {
F_5 ( L_60 ) ;
F_10 ( V_141 , V_33 ) ;
return 0 ;
}
V_107 -> V_77 = V_77 ;
if ( V_77 == V_52 ) {
V_107 -> V_18 = V_124 ;
V_107 -> V_40 = * V_40 ;
} else {
V_107 -> V_18 = V_125 ;
V_107 -> V_54 = * V_54 ;
}
V_107 -> V_102 = V_142 ;
V_107 -> V_23 = V_16 -> V_43 ;
V_107 -> V_134 = V_16 -> V_143 ;
V_107 -> V_144 . V_4 = V_16 -> V_1 ;
V_107 -> V_144 . V_145 = NULL ;
V_140 = ( T_1 T_2 * )
V_107 -> V_144 . V_4 ;
V_107 -> V_146 = V_16 -> V_146 ;
V_107 -> V_147 . V_28 = & V_29 ;
V_107 -> V_147 . V_26 = V_138 ;
V_107 -> V_147 . V_24 = V_148 ;
F_11 ( & V_107 -> V_147 , L_61 ,
V_16 -> V_43 , V_16 -> V_143 ) ;
F_37 ( & V_74 , V_70 ) ;
for ( V_72 = V_75 ; V_72 ;
V_72 = V_72 -> V_76 ) {
if ( V_77 == V_52 ) {
if ( ( V_72 -> V_40 . V_44 . V_45 == V_40 -> V_44 . V_45 ) &&
( V_72 -> V_40 . V_44 . V_46 == V_40 -> V_44 . V_46 ) ) {
break;
}
} else
if ( memcmp
( V_72 -> V_54 . V_55 , V_54 -> V_55 ,
V_149 ) == 0 ) {
break;
}
}
if ( V_72 ) {
F_38 ( & V_74 , V_70 ) ;
F_26 ( V_107 ) ;
F_5 ( L_62 ) ;
F_10 ( V_32 , V_33 ) ;
return 0 ;
}
if ( ! V_75 )
V_75 = V_107 ;
else {
V_107 -> V_76 = V_75 ;
V_75 = V_107 ;
}
F_38 ( & V_74 , V_70 ) ;
V_64 = & V_107 -> V_147 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_64 ) ,
V_150 , NULL ) ;
F_44 ( L_63 ,
& V_107 -> V_147 , V_107 -> V_147 . V_111 ) ;
V_17 = F_12 ( & V_107 -> V_147 ) ;
if ( V_17 ) {
F_5 ( L_64 , V_17 ) ;
V_64 = & V_107 -> V_147 ;
F_58 ( V_16 -> V_1 ,
F_14 ( V_64 ) ,
V_151 , NULL ) ;
F_37 ( & V_74 , V_70 ) ;
for ( V_72 = V_75 , V_139 = NULL ;
V_72 ;
V_139 = V_72 , V_72 = V_72 -> V_76 ) {
if ( V_72 == V_107 ) {
if ( V_139 )
V_139 -> V_76 = V_72 -> V_76 ;
else
V_75 = V_72 -> V_76 ;
break;
}
}
F_38 ( & V_74 , V_70 ) ;
F_26 ( V_107 ) ;
return 0 ;
}
F_13 ( L_65 ,
( V_77 == V_52 ) ? L_66 : L_67 ,
V_16 -> V_43 , V_16 -> V_143 ,
& V_107 -> V_147 ) ;
F_10 ( V_36 , V_22 ) ;
return 1 ;
}
static int F_28 ( struct V_18 * V_138 ,
int V_77 ,
struct V_152 * V_44 ,
unsigned char V_153 [] )
{
int V_154 = 0 ;
bool V_155 = false ;
struct V_71 * V_72 , * V_156 ;
struct V_108 * V_157 ;
unsigned long V_70 ;
int V_158 = 0 ;
if ( ( V_77 != V_52 ) && ( V_77 != V_59 ) ) {
F_5 ( L_68 ,
V_77 , V_52 , V_59 ) ;
return 0 ;
}
F_37 ( & V_74 , V_70 ) ;
for ( V_72 = V_75 , V_156 = NULL ;
( V_72 && ! V_155 ) ;
V_156 = V_72 , V_72 = V_72 -> V_76 ) {
if ( V_72 -> V_77 != V_77 )
continue;
if ( V_77 == V_52 ) {
V_154 =
( ( V_72 -> V_40 . V_44 . V_45 == V_44 -> V_45 ) &&
( V_72 -> V_40 . V_44 . V_46 == V_44 -> V_46 ) ) ;
} else {
V_154 =
memcmp ( V_72 -> V_54 . V_55 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_154 )
continue;
V_155 = true ;
V_157 = V_72 -> V_132 ;
V_158 = V_157 -> V_159 ( V_72 , 0 ) ;
}
F_38 ( & V_74 , V_70 ) ;
if ( ! V_155 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_158 ;
}
static int F_31 ( struct V_18 * V_138 ,
int V_77 ,
struct V_152 * V_44 ,
unsigned char V_153 [] )
{
int V_160 = 0 ;
bool V_155 = false ;
struct V_71 * V_72 , * V_156 ;
struct V_108 * V_157 ;
unsigned long V_70 ;
int V_158 = 0 ;
if ( ( V_77 != V_52 ) && ( V_77 != V_59 ) ) {
F_5 ( L_70 ,
V_77 , V_52 , V_59 ) ;
return 0 ;
}
F_37 ( & V_74 , V_70 ) ;
for ( V_72 = V_75 , V_156 = NULL ;
( V_72 && ! V_155 ) ;
V_156 = V_72 , V_72 = V_72 -> V_76 ) {
if ( V_72 -> V_77 != V_77 )
continue;
if ( V_77 == V_52 ) {
V_160 =
( ( V_72 -> V_40 . V_44 . V_45 == V_44 -> V_45 ) &&
( V_72 -> V_40 . V_44 . V_46 == V_44 -> V_46 ) ) ;
} else {
V_160 =
memcmp ( V_72 -> V_54 . V_55 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_160 )
continue;
V_155 = true ;
V_157 = V_72 -> V_132 ;
F_52 ( & V_72 -> V_147 , V_72 -> V_134 ,
V_72 -> V_18 , V_157 ) ;
V_158 = V_157 -> V_161 ( V_72 ) ;
}
F_38 ( & V_74 , V_70 ) ;
if ( ! V_155 ) {
F_5 ( L_69 ) ;
return 0 ;
}
return V_158 ;
}
static int F_34 ( struct V_18 * V_138 ,
int V_77 , struct V_152 * V_44 ,
unsigned char V_153 [] )
{
int V_2 = 0 , V_162 = 0 , V_163 ;
struct V_71 * V_72 , * V_156 , * V_164 = NULL ;
unsigned long V_70 ;
#define F_59 { \
prevvpcidev = tmpvpcidev;\
tmpvpcidev = tmpvpcidev->next;\
continue; \
}
if ( ( V_77 != V_52 ) && ( V_77 != V_59 ) ) {
F_5 ( L_71 ,
V_77 , V_52 , V_59 ) ;
return 0 ;
}
V_162 = ( ( V_77 == V_52 ) && ( V_44 == NULL ) ) ||
( ( V_77 == V_59 ) && ( V_153 == NULL ) ) ;
F_37 ( & V_74 , V_70 ) ;
for ( V_72 = V_75 , V_156 = NULL ; V_72 ; ) {
if ( V_72 -> V_77 != V_77 )
F_59 ;
if ( V_162 ) {
V_163 =
( V_72 -> V_147 . V_26 == V_138 ) ;
} else if ( V_77 == V_52 ) {
V_163 =
( ( V_72 -> V_40 . V_44 . V_45 == V_44 -> V_45 ) &&
( V_72 -> V_40 . V_44 . V_46 == V_44 -> V_46 ) ) ;
} else {
V_163 =
memcmp ( V_72 -> V_54 . V_55 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_163 )
F_59 ;
if ( V_156 )
V_156 -> V_76 = V_72 -> V_76 ;
else
V_75 = V_72 -> V_76 ;
V_72 -> V_76 = V_164 ;
V_164 = V_72 ;
V_2 ++ ;
if ( ! V_162 )
break;
if ( V_156 )
V_72 = V_156 -> V_76 ;
else
V_72 = V_75 ;
}
F_38 ( & V_74 , V_70 ) ;
if ( ! V_162 && ( V_2 == 0 ) ) {
F_5 ( L_69 ) ;
return 0 ;
}
while ( V_164 ) {
V_72 = V_164 -> V_76 ;
F_39 ( V_164 ) ;
V_164 = V_72 ;
}
return V_2 ;
}
static void V_148 ( struct V_18 * V_137 )
{
F_13 ( L_72 , V_137 ) ;
}
static T_7 F_60 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
char * V_169 )
{
struct V_170 * V_171 = F_61 ( V_168 ) ;
T_7 V_17 = 0 ;
struct V_172 * V_173 = F_62 ( V_166 ) ;
struct V_105 * V_128 ;
if ( V_173 != NULL )
V_128 = V_173 -> V_128 ;
else
V_128 = NULL ;
F_44 ( L_73 , V_128 -> V_99 ) ;
if ( V_128 ) {
if ( V_171 -> V_174 )
V_17 = V_171 -> V_174 ( V_128 , V_169 ) ;
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
struct V_105 * V_128 ;
if ( V_173 != NULL )
V_128 = V_173 -> V_128 ;
else
V_128 = NULL ;
F_44 ( L_74 , V_128 -> V_99 ) ;
if ( V_128 ) {
if ( V_171 -> V_175 )
V_17 = V_171 -> V_175 ( V_128 , V_169 , V_2 ) ;
}
return V_17 ;
}
int F_64 ( struct V_108 * V_106 )
{
int V_176 = 0 ;
F_44 ( L_75 ) ;
if ( V_106 -> V_112 == NULL ) {
F_5 ( L_76 ) ;
return 1 ;
}
V_106 -> V_177 . V_99 = V_106 -> V_99 ;
V_106 -> V_177 . V_28 = & V_29 ;
V_106 -> V_177 . V_133 = F_54 ;
V_106 -> V_177 . remove = F_57 ;
V_176 = F_65 ( & V_106 -> V_177 ) ;
if ( V_176 )
return V_176 ;
V_106 -> V_177 . V_178 -> V_166 . V_179 = & V_180 ;
return 0 ;
}
void F_66 ( struct V_108 * V_106 )
{
F_44 ( L_77 , V_106 ) ;
F_67 ( & V_106 -> V_177 ) ;
F_44 ( L_56 ) ;
}
static int F_68 ( struct V_18 * V_19 , void * V_62 )
{
struct V_181 * V_178 = (struct V_181 * ) V_62 ;
* V_178 -> V_182 += F_69 ( V_178 -> V_169 + * V_178 -> V_182 , * V_178 -> V_183 - * V_178 -> V_182 ,
L_78 , F_70 ( V_19 ) ) ;
return 0 ;
}
static T_7 F_71 ( struct V_184 * V_184 , char T_9 * V_169 ,
T_8 V_183 , T_10 * V_185 )
{
T_7 V_186 = 0 ;
int V_182 = 0 ;
struct V_71 * V_72 ;
unsigned long V_70 ;
struct V_181 V_187 ;
char * V_188 ;
if ( V_183 > V_189 )
V_183 = V_189 ;
V_188 = F_9 ( V_183 , V_190 ) ;
if ( ! V_188 )
return - V_116 ;
V_182 += F_69 ( V_188 + V_182 , V_183 - V_182 ,
L_79 ) ;
V_187 . V_182 = & V_182 ;
V_187 . V_169 = V_188 ;
V_187 . V_183 = & V_183 ;
if ( F_40 ( & V_29 , NULL ,
( void * ) & V_187 , F_68 ) )
F_5 ( L_80 ) ;
V_182 += F_69 ( V_188 + V_182 , V_183 - V_182 ,
L_81 ) ;
F_72 ( & V_74 , V_70 ) ;
V_72 = V_75 ;
while ( V_72 ) {
if ( V_72 -> V_77 == V_52 ) {
V_182 += F_69 ( V_188 + V_182 , V_183 - V_182 ,
L_82 ,
V_72 -> V_23 , V_72 -> V_134 ,
V_72 -> V_40 . V_44 . V_45 ,
V_72 -> V_40 . V_44 . V_46 ,
V_72 -> V_40 . V_47 . V_48 ,
V_72 -> V_40 . V_47 . V_49 ,
V_72 -> V_40 . V_47 . V_50 ,
V_72 -> V_40 . V_47 . V_51 ) ;
} else {
V_182 += F_69 ( V_188 + V_182 , V_183 - V_182 ,
L_83 ,
V_72 -> V_23 , V_72 -> V_134 ,
V_72 -> V_54 . V_55 [ 0 ] ,
V_72 -> V_54 . V_55 [ 1 ] ,
V_72 -> V_54 . V_55 [ 2 ] ,
V_72 -> V_54 . V_55 [ 3 ] ,
V_72 -> V_54 . V_55 [ 4 ] ,
V_72 -> V_54 . V_55 [ 5 ] ,
V_72 -> V_54 . V_56 ,
V_72 -> V_54 . V_57 ) ;
}
V_182 += F_69 ( V_188 + V_182 ,
V_183 - V_182 , L_84 ,
V_72 -> V_144 . V_4 ) ;
V_72 = V_72 -> V_76 ;
}
F_73 ( & V_74 , V_70 ) ;
V_182 += F_69 ( V_188 + V_182 , V_183 - V_182 , L_85 ) ;
V_186 = F_74 ( V_169 , V_183 , V_185 , V_188 , V_182 ) ;
F_26 ( V_188 ) ;
return V_186 ;
}
static int T_11 F_75 ( void )
{
int V_17 ;
if ( ! V_191 )
return - V_131 ;
F_10 ( V_21 , V_22 ) ;
V_17 = F_76 ( & V_29 ) ;
if ( V_17 ) {
F_5 ( L_86 , V_17 ) ;
F_19 ( V_32 , V_17 ,
V_33 ) ;
return V_17 ;
}
F_44 ( L_87 ) ;
F_53 ( & V_35 , L_88 , L_89 ,
V_192 , NULL ) ;
V_17 = F_12 ( & V_27 ) ;
if ( V_17 ) {
F_5 ( L_6 , V_17 ) ;
F_77 ( & V_29 ) ;
F_19 ( V_32 , V_17 ,
V_33 ) ;
return V_17 ;
}
F_44 ( L_90 , V_17 ) ;
if ( ! F_78 ( 2 , ( void * ) & F_42 ,
& V_34 ) ) {
F_5 ( L_91 ) ;
F_10 ( V_32 , V_33 ) ;
F_25 ( & V_27 ) ;
F_77 ( & V_29 ) ;
return - 1 ;
}
F_13 ( L_92 ,
( void * ) & F_42 ) ;
V_193 = F_79 ( L_89 , NULL ) ;
F_80 ( L_93 , V_194 , V_193 ,
NULL , & V_195 ) ;
F_13 ( L_56 ) ;
F_10 ( V_36 , V_22 ) ;
return 0 ;
}
static void T_12 F_81 ( void )
{
F_13 ( L_94 ) ;
if ( ! F_78 ( 2 , NULL , NULL ) )
F_5 ( L_91 ) ;
F_25 ( & V_27 ) ;
F_77 ( & V_29 ) ;
F_82 ( V_193 ) ;
F_13 ( L_56 ) ;
}
