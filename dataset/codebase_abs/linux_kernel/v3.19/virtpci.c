static inline
int F_1 ( struct V_1 T_1 * V_2 )
{
int V_3 = 120 ;
while ( V_3 > 0 ) {
if ( F_2 ( & V_2 -> V_4 ) )
return 1 ;
F_3 ( 1 ) ;
V_3 -- ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
if ( ! V_6 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_9 = sizeof( struct V_4 ) + V_6 -> V_10 . V_11 ;
if ( V_6 -> V_10 . V_11 == 0 ) {
F_5 ( L_2 ) ;
return - 1 ;
}
memcpy ( ( ( V_12 * ) ( V_6 ) ) + V_9 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
if ( ! V_6 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_9 = sizeof( struct V_4 ) + V_6 -> V_10 . V_13 ;
if ( V_6 -> V_10 . V_13 == 0 ) {
F_5 ( L_3 ) ;
return - 1 ;
}
memcpy ( ( ( V_12 * ) ( V_6 ) ) + V_9 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int
F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_14 )
{
int V_9 ;
if ( ! V_6 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_9 =
( sizeof( struct V_4 ) +
V_6 -> V_10 . V_15 ) +
( V_6 -> V_10 . V_16 * V_14 ) ;
if ( V_6 -> V_10 . V_15 == 0 ) {
F_5 ( L_4 ) ;
return - 1 ;
}
memcpy ( ( ( V_12 * ) ( V_6 ) ) + V_9 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_20 * V_21 ;
V_21 = F_9 ( sizeof( * V_21 ) , V_22 ) ;
F_10 ( V_23 , V_24 ) ;
if ( ! V_21 )
return 0 ;
F_11 ( V_21 , L_5 , V_18 -> V_25 ) ;
V_21 -> V_26 = V_27 ;
V_21 -> V_28 = & V_29 ;
V_21 -> V_30 = & V_31 ;
V_21 -> V_32 = ( V_33 void * ) V_18 -> V_2 ;
V_19 = F_12 ( V_21 ) ;
if ( V_19 ) {
F_5 ( L_6 , V_19 ) ;
F_10 ( V_34 , V_35 ) ;
return 0 ;
}
F_4 ( V_21 -> V_32 ,
& V_36 ) ;
F_6 ( V_21 -> V_32 ,
& V_37 ) ;
F_13 ( L_7 ,
V_18 -> V_25 , F_14 ( V_21 ) ) ;
F_10 ( V_38 , V_24 ) ;
return 1 ;
}
static int F_15 ( struct V_39 * V_18 )
{
int V_40 ;
struct V_41 V_42 ;
struct V_20 * V_21 ;
unsigned char V_43 [ V_44 ] ;
F_10 ( V_23 , V_24 ) ;
if ( ! F_1
( (struct V_1 T_1 * ) V_18 -> V_2 ) ) {
F_5 ( L_8 ) ;
F_10 ( V_34 , V_35 ) ;
return 0 ;
}
F_16 ( V_18 -> V_2 ) ;
sprintf ( V_43 , L_5 , V_18 -> V_25 ) ;
V_21 = F_17 ( & V_31 , NULL ,
( void * ) V_43 , V_45 ) ;
if ( ! V_21 ) {
F_5 ( L_9 , V_43 ) ;
return 0 ;
}
F_13 ( L_10 ,
V_42 . V_46 . V_47 , V_42 . V_46 . V_48 ,
V_42 . V_49 . V_50 , V_42 . V_49 . V_51 , V_42 . V_49 . V_52 ,
V_42 . V_49 . V_53 , V_18 -> V_2 ) ;
V_40 = F_18 ( V_21 , V_54 , V_18 , & V_42 , NULL ) ;
if ( V_40 ) {
F_13 ( L_11 , V_42 . V_46 . V_47 ,
V_42 . V_46 . V_48 , V_18 -> V_2 ) ;
F_19 ( V_38 , V_40 ,
V_24 ) ;
}
return V_40 ;
}
static int
F_20 ( struct V_39 * V_18 )
{
int V_40 ;
struct V_55 V_56 ;
struct V_20 * V_21 ;
unsigned char V_43 [ V_44 ] ;
F_10 ( V_23 , V_24 ) ;
if ( ! F_1
( (struct V_1 T_1 * ) V_18 -> V_2 ) ) {
F_5 ( L_12 ) ;
F_10 ( V_34 , V_35 ) ;
return 0 ;
}
F_21 ( V_18 -> V_2 ) ;
sprintf ( V_43 , L_5 , V_18 -> V_25 ) ;
V_21 = F_17 ( & V_31 , NULL ,
( void * ) V_43 , V_45 ) ;
if ( ! V_21 ) {
F_5 ( L_9 , V_43 ) ;
return 0 ;
}
F_13 ( L_13 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ,
V_56 . V_58 , V_56 . V_59 , V_18 -> V_2 , & V_56 . V_60 ) ;
V_40 = F_18 ( V_21 , V_61 , V_18 , NULL , & V_56 ) ;
if ( V_40 ) {
F_13 ( L_14 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
F_19 ( V_38 , V_40 ,
V_24 ) ;
return 1 ;
}
return 0 ;
}
static int
F_22 ( struct V_62 * V_63 )
{
struct V_20 * V_21 ;
unsigned char V_43 [ V_44 ] ;
sprintf ( V_43 , L_5 , V_63 -> V_25 ) ;
V_21 = F_17 ( & V_31 , NULL ,
( void * ) V_43 , V_45 ) ;
if ( ! V_21 ) {
F_5 ( L_9 , V_43 ) ;
return 0 ;
}
F_13 ( L_15 , F_14 ( V_21 ) ) ;
if ( F_23 ( V_21 , NULL ) )
return 0 ;
F_13 ( L_16 , V_63 -> V_25 ) ;
return 1 ;
}
static int
F_23 ( struct V_20 * V_21 , void * V_64 )
{
int V_65 = ( V_64 != NULL ) ;
struct V_20 * V_66 = & V_29 ;
if ( ( V_65 ) && V_45 ( V_21 , ( void * ) F_14 ( V_66 ) ) ) {
F_13 ( L_17 ) ;
return 0 ;
}
F_13 ( L_18 , F_14 ( V_21 ) ) ;
F_24 ( V_21 ) ;
F_25 ( V_21 ) ;
F_13 ( L_19 ) ;
return 0 ;
}
static int F_26 ( struct V_67 * V_68 )
{
int V_40 ;
struct V_41 V_42 ;
F_16 ( V_68 -> V_2 ) ;
F_13 ( L_20 , V_42 . V_46 . V_47 , V_42 . V_46 . V_48 ) ;
V_40 = F_27 ( NULL , V_54 ,
& V_42 . V_46 , NULL ) ;
if ( V_40 )
F_13 ( L_21 , V_42 . V_46 . V_47 ,
V_42 . V_46 . V_48 ) ;
return V_40 ;
}
static int F_28 ( struct V_67 * V_68 )
{
int V_40 ;
struct V_55 V_56 ;
F_21 ( V_68 -> V_2 ) ;
F_13 ( L_22 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
V_40 = F_27 ( NULL , V_61 ,
NULL , V_56 . V_57 ) ;
if ( V_40 ) {
F_13 ( L_23 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
}
return V_40 ;
}
static int F_29 ( struct V_69 * V_70 )
{
int V_40 ;
struct V_41 V_42 ;
F_16 ( V_70 -> V_2 ) ;
F_13 ( L_24 , V_42 . V_46 . V_47 , V_42 . V_46 . V_48 ) ;
V_40 = F_30 ( NULL , V_54 ,
& V_42 . V_46 , NULL ) ;
if ( V_40 )
F_13 ( L_25 , V_42 . V_46 . V_47 ,
V_42 . V_46 . V_48 ) ;
return V_40 ;
}
static int
F_31 ( struct V_69 * V_70 )
{
int V_40 ;
struct V_55 V_56 ;
F_21 ( V_70 -> V_2 ) ;
F_13 ( L_26 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
V_40 = F_30 ( NULL , V_61 ,
NULL , V_56 . V_57 ) ;
if ( V_40 ) {
F_13 ( L_27 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
}
return V_40 ;
}
static int F_32 ( struct V_71 * V_63 )
{
int V_40 ;
struct V_41 V_42 ;
F_16 ( V_63 -> V_2 ) ;
F_13 ( L_28 , V_42 . V_46 . V_47 , V_42 . V_46 . V_48 ) ;
V_40 = F_33 ( NULL , V_54 ,
& V_42 . V_46 , NULL ) ;
if ( V_40 ) {
F_13 ( L_29 , V_42 . V_46 . V_47 ,
V_42 . V_46 . V_48 ) ;
return 1 ;
}
return 0 ;
}
static int F_34 ( struct V_71 * V_63 )
{
int V_40 ;
struct V_55 V_56 ;
F_21 ( V_63 -> V_2 ) ;
F_13 ( L_30 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
V_40 = F_33 ( NULL , V_61 , NULL ,
V_56 . V_57 ) ;
if ( V_40 ) {
F_13 ( L_31 ,
V_56 . V_57 [ 0 ] , V_56 . V_57 [ 1 ] , V_56 . V_57 [ 2 ] ,
V_56 . V_57 [ 3 ] , V_56 . V_57 [ 4 ] , V_56 . V_57 [ 5 ] ) ;
}
return V_40 ;
}
static void F_35 ( void )
{
int V_3 = 0 ;
unsigned long V_72 ;
struct V_73 * V_74 , * V_75 ;
F_36 ( & V_76 , V_72 ) ;
V_74 = V_77 ;
V_77 = NULL ;
F_37 ( & V_76 , V_72 ) ;
while ( V_74 ) {
V_75 = V_74 -> V_78 ;
F_38 ( V_74 ) ;
V_74 = V_75 ;
V_3 ++ ;
}
F_13 ( L_32 , V_3 ) ;
if ( F_39
( & V_31 , NULL , ( void * ) 1 , F_23 ) )
F_5 ( L_33 ) ;
}
static int F_40 ( enum V_79 V_80 ,
struct V_62 * V_63 )
{
int V_40 ;
unsigned char V_43 [ V_44 ] ;
struct V_20 * V_21 ;
sprintf ( V_43 , L_5 , V_63 -> V_25 ) ;
V_21 = F_17 ( & V_31 , NULL ,
( void * ) V_43 , V_45 ) ;
if ( ! V_21 ) {
F_5 ( L_9 , V_43 ) ;
return 0 ;
}
if ( ( V_80 != V_54 ) && ( V_80 != V_61 ) ) {
F_5 ( L_34 ,
V_80 , V_54 , V_61 ) ;
return 0 ;
}
F_13 ( L_35 ,
V_80 == V_54 ? L_36 : L_37 , V_43 ) ;
V_40 = F_33 ( V_21 , V_80 , NULL , NULL ) ;
if ( V_40 > 0 )
F_13 ( L_38 , V_40 ,
V_80 == V_54 ? L_36 : L_37 ) ;
return 1 ;
}
static int F_41 ( struct V_81 * V_82 )
{
switch ( V_82 -> V_83 ) {
case V_84 :
return F_8 ( & V_82 -> F_8 ) ;
case V_85 :
return F_15 ( & V_82 -> F_15 ) ;
case V_86 :
return F_20 ( & V_82 -> F_20 ) ;
case V_87 :
return F_22 ( & V_82 -> V_88 ) ;
case V_89 :
return F_32 ( & V_82 -> V_90 ) ;
case V_91 :
return F_34 ( & V_82 -> V_90 ) ;
case V_92 :
return F_40 ( V_54 , & V_82 -> V_93 ) ;
case V_94 :
return F_40 ( V_61 , & V_82 -> V_95 ) ;
case V_96 :
F_35 () ;
return 1 ;
case V_97 :
return F_26 ( & V_82 -> F_26 ) ;
case V_98 :
return F_28 ( & V_82 -> F_28 ) ;
case V_99 :
return F_29 ( & V_82 -> F_29 ) ;
case V_100 :
return F_31 ( & V_82 -> F_31 ) ;
default:
F_5 ( L_39 , V_82 -> V_83 ) ;
return 0 ;
}
}
static int V_45 ( struct V_20 * V_66 , void * V_64 )
{
const char * V_101 = V_64 ;
if ( strcmp ( V_101 , F_14 ( V_66 ) ) == 0 )
return 1 ;
return 0 ;
}
static const struct V_102 *
F_42 ( const struct V_102 * V_103 ,
const struct V_73 * V_66 )
{
while ( V_103 -> V_104 || V_103 -> V_105 || V_103 -> V_106 ) {
F_43 ( L_40 ,
V_103 -> V_104 , V_66 -> V_104 , V_103 -> V_20 , V_66 -> V_20 ) ;
if ( ( V_103 -> V_104 == V_66 -> V_104 ) &&
( V_103 -> V_20 == V_66 -> V_20 ) )
return V_103 ;
V_103 ++ ;
}
return NULL ;
}
static int F_44 ( struct V_20 * V_66 , struct V_107 * V_108 )
{
struct V_73 * V_109 = F_45 ( V_66 ) ;
struct V_110 * V_111 = F_46 ( V_108 ) ;
int V_112 = 0 ;
F_43 ( L_41 ,
V_66 -> V_113 , V_108 -> V_101 ) ;
if ( F_42 ( V_111 -> V_114 , V_109 ) )
V_112 = 1 ;
F_43 ( L_42 , V_112 ) ;
return V_112 ;
}
static int F_47 ( struct V_20 * V_66 , struct V_115 * V_116 )
{
F_43 ( L_43 ) ;
if ( F_48 ( V_116 , L_44 , V_117 ) )
return - V_118 ;
return 0 ;
}
static int F_49 ( struct V_20 * V_66 , T_2 V_119 )
{
F_43 ( L_45 ) ;
return 0 ;
}
static int F_50 ( struct V_20 * V_66 )
{
F_43 ( L_46 ) ;
return 0 ;
}
static void F_51 ( struct V_20 * V_66 , int V_120 , int V_121 ,
struct V_110 * V_111 )
{
struct V_20 * V_21 ;
void * V_6 ;
struct V_7 V_122 ;
const char * V_123 ;
if ( ! V_66 ) {
F_5 ( L_47 , V_124 ) ;
return;
}
if ( ! V_111 ) {
F_5 ( L_48 , V_124 ) ;
return;
}
V_21 = V_66 -> V_28 ;
if ( ! V_21 ) {
F_5 ( L_49 , V_124 ) ;
return;
}
V_6 = V_21 -> V_32 ;
if ( ! V_6 ) {
F_5 ( L_50 , V_124 ) ;
return;
}
switch ( V_121 ) {
case V_125 :
V_123 = L_51 ;
break;
case V_126 :
V_123 = L_52 ;
break;
default:
V_123 = L_53 ;
break;
}
F_52 ( & V_122 , V_123 ,
V_111 -> V_101 ,
V_111 -> V_127 ,
V_111 -> V_128 ) ;
F_7 ( V_6 , & V_122 , V_120 ) ;
F_4 ( V_6 , & V_36 ) ;
F_6 ( V_6 , & V_37 ) ;
}
static int F_53 ( struct V_20 * V_66 )
{
struct V_73 * V_109 = F_45 ( V_66 ) ;
struct V_110 * V_111 =
F_46 ( V_66 -> V_129 ) ;
const struct V_102 * V_130 ;
int error = 0 ;
F_13 ( L_54 ,
V_66 , V_109 , V_111 ) ;
F_10 ( V_131 , V_24 ) ;
if ( ! V_111 -> V_114 )
return - V_132 ;
V_130 = F_42 ( V_111 -> V_114 , V_109 ) ;
if ( ! V_130 )
return - V_132 ;
F_54 ( V_66 ) ;
if ( ! V_109 -> V_133 && V_111 -> V_134 ) {
error = V_111 -> V_134 ( V_109 , V_130 ) ;
if ( ! error ) {
F_51 ( V_66 , V_109 -> V_135 ,
V_109 -> V_20 , V_111 ) ;
V_109 -> V_133 = V_111 ;
F_10 ( V_136 ,
V_24 ) ;
} else {
F_55 ( V_66 ) ;
}
}
F_10 ( V_137 , V_35 ) ;
return error ;
}
static int F_56 ( struct V_20 * V_138 )
{
struct V_73 * V_109 = F_45 ( V_138 ) ;
struct V_110 * V_111 = V_109 -> V_133 ;
F_13 ( L_55 ,
F_14 ( V_138 ) , V_138 , V_109 , V_138 -> V_129 ,
V_138 -> V_129 -> V_101 ) ;
if ( V_111 ) {
if ( V_111 -> remove )
V_111 -> remove ( V_109 ) ;
V_109 -> V_133 = NULL ;
}
F_43 ( L_56 ) ;
F_55 ( V_138 ) ;
F_43 ( L_57 ) ;
return 0 ;
}
static void V_27 ( struct V_20 * V_66 )
{
F_43 ( L_58 ) ;
}
static int F_18 ( struct V_20 * V_139 , int V_80 ,
struct V_39 * V_18 ,
struct V_41 * V_42 ,
struct V_55 * V_56 )
{
struct V_73 * V_109 = NULL ;
struct V_73 * V_74 = NULL , * V_140 ;
unsigned long V_72 ;
int V_19 ;
struct V_1 T_1 * V_141 = NULL ;
struct V_20 * V_66 ;
F_13 ( L_59 , V_139 ,
V_18 -> V_2 ) ;
F_10 ( V_23 , V_24 ) ;
if ( ( V_80 != V_54 ) && ( V_80 != V_61 ) ) {
F_5 ( L_60 ,
V_80 , V_54 , V_61 ) ;
F_19 ( V_34 , V_80 ,
V_35 ) ;
return 0 ;
}
V_109 = F_9 ( sizeof( * V_109 ) , V_22 ) ;
if ( V_109 == NULL ) {
F_5 ( L_61 ) ;
F_10 ( V_142 , V_35 ) ;
return 0 ;
}
V_109 -> V_80 = V_80 ;
if ( V_80 == V_54 ) {
V_109 -> V_20 = V_125 ;
V_109 -> V_42 = * V_42 ;
} else {
V_109 -> V_20 = V_126 ;
V_109 -> V_56 = * V_56 ;
}
V_109 -> V_104 = V_143 ;
V_109 -> V_25 = V_18 -> V_25 ;
V_109 -> V_135 = V_18 -> V_135 ;
V_109 -> V_144 . V_6 = V_18 -> V_2 ;
V_109 -> V_144 . V_145 = NULL ;
V_141 = (struct V_1 T_1 * )
V_109 -> V_144 . V_6 ;
V_109 -> V_146 = V_18 -> V_146 ;
V_109 -> V_147 . V_30 = & V_31 ;
V_109 -> V_147 . V_28 = V_139 ;
V_109 -> V_147 . V_26 = V_148 ;
F_11 ( & V_109 -> V_147 , L_62 ,
V_18 -> V_25 , V_18 -> V_135 ) ;
F_36 ( & V_76 , V_72 ) ;
for ( V_74 = V_77 ; V_74 ;
V_74 = V_74 -> V_78 ) {
if ( V_80 == V_54 ) {
if ( ( V_74 -> V_42 . V_46 . V_47 == V_42 -> V_46 . V_47 ) &&
( V_74 -> V_42 . V_46 . V_48 == V_42 -> V_46 . V_48 ) ) {
break;
}
} else
if ( memcmp
( V_74 -> V_56 . V_57 , V_56 -> V_57 ,
V_149 ) == 0 ) {
break;
}
}
if ( V_74 ) {
F_37 ( & V_76 , V_72 ) ;
F_25 ( V_109 ) ;
F_5 ( L_63 ) ;
F_10 ( V_34 , V_35 ) ;
return 0 ;
}
if ( ! V_77 ) {
V_77 = V_109 ;
} else {
V_109 -> V_78 = V_77 ;
V_77 = V_109 ;
}
F_37 ( & V_76 , V_72 ) ;
V_66 = & V_109 -> V_147 ;
F_57 ( V_18 -> V_2 ,
F_14 ( V_66 ) ,
V_150 , NULL ) ;
F_43 ( L_64 ,
& V_109 -> V_147 , V_109 -> V_147 . V_113 ) ;
V_19 = F_12 ( & V_109 -> V_147 ) ;
if ( V_19 ) {
F_5 ( L_65 , V_19 ) ;
V_66 = & V_109 -> V_147 ;
F_57 ( V_18 -> V_2 ,
F_14 ( V_66 ) ,
V_151 , NULL ) ;
F_36 ( & V_76 , V_72 ) ;
for ( V_74 = V_77 , V_140 = NULL ;
V_74 ;
V_140 = V_74 , V_74 = V_74 -> V_78 ) {
if ( V_74 == V_109 ) {
if ( V_140 )
V_140 -> V_78 = V_74 -> V_78 ;
else
V_77 = V_74 -> V_78 ;
break;
}
}
F_37 ( & V_76 , V_72 ) ;
F_25 ( V_109 ) ;
return 0 ;
}
F_13 ( L_66 ,
( V_80 == V_54 ) ? L_67 : L_68 ,
V_18 -> V_25 , V_18 -> V_135 ,
& V_109 -> V_147 ) ;
F_10 ( V_38 , V_24 ) ;
return 1 ;
}
static int F_27 ( struct V_20 * V_139 ,
int V_80 ,
struct V_152 * V_46 ,
unsigned char V_153 [] )
{
int V_154 = 0 ;
bool V_155 = false ;
struct V_73 * V_74 , * V_156 ;
struct V_110 * V_157 ;
unsigned long V_72 ;
int V_158 = 0 ;
if ( ( V_80 != V_54 ) && ( V_80 != V_61 ) ) {
F_5 ( L_69 ,
V_80 , V_54 , V_61 ) ;
return 0 ;
}
F_36 ( & V_76 , V_72 ) ;
for ( V_74 = V_77 , V_156 = NULL ;
( V_74 && ! V_155 ) ;
V_156 = V_74 , V_74 = V_74 -> V_78 ) {
if ( V_74 -> V_80 != V_80 )
continue;
if ( V_80 == V_54 ) {
V_154 =
( ( V_74 -> V_42 . V_46 . V_47 == V_46 -> V_47 ) &&
( V_74 -> V_42 . V_46 . V_48 == V_46 -> V_48 ) ) ;
} else {
V_154 =
memcmp ( V_74 -> V_56 . V_57 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_154 )
continue;
V_155 = true ;
V_157 = V_74 -> V_133 ;
V_158 = V_157 -> V_159 ( V_74 , 0 ) ;
}
F_37 ( & V_76 , V_72 ) ;
if ( ! V_155 ) {
F_5 ( L_70 ) ;
return 0 ;
}
return V_158 ;
}
static int F_30 ( struct V_20 * V_139 ,
int V_80 ,
struct V_152 * V_46 ,
unsigned char V_153 [] )
{
int V_160 = 0 ;
bool V_155 = false ;
struct V_73 * V_74 , * V_156 ;
struct V_110 * V_157 ;
unsigned long V_72 ;
int V_158 = 0 ;
if ( ( V_80 != V_54 ) && ( V_80 != V_61 ) ) {
F_5 ( L_71 ,
V_80 , V_54 , V_61 ) ;
return 0 ;
}
F_36 ( & V_76 , V_72 ) ;
for ( V_74 = V_77 , V_156 = NULL ;
( V_74 && ! V_155 ) ;
V_156 = V_74 , V_74 = V_74 -> V_78 ) {
if ( V_74 -> V_80 != V_80 )
continue;
if ( V_80 == V_54 ) {
V_160 =
( ( V_74 -> V_42 . V_46 . V_47 == V_46 -> V_47 ) &&
( V_74 -> V_42 . V_46 . V_48 == V_46 -> V_48 ) ) ;
} else {
V_160 =
memcmp ( V_74 -> V_56 . V_57 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_160 )
continue;
V_155 = true ;
V_157 = V_74 -> V_133 ;
F_51 ( & V_74 -> V_147 ,
V_74 -> V_135 ,
V_74 -> V_20 , V_157 ) ;
V_158 = V_157 -> V_161 ( V_74 ) ;
}
F_37 ( & V_76 , V_72 ) ;
if ( ! V_155 ) {
F_5 ( L_70 ) ;
return 0 ;
}
return V_158 ;
}
static int F_33 ( struct V_20 * V_139 ,
int V_80 , struct V_152 * V_46 ,
unsigned char V_153 [] )
{
int V_3 = 0 , V_162 = 0 , V_163 ;
struct V_73 * V_74 , * V_156 , * V_164 = NULL ;
unsigned long V_72 ;
#define F_58 { \
prevvpcidev = tmpvpcidev;\
tmpvpcidev = tmpvpcidev->next;\
continue; \
}
if ( ( V_80 != V_54 ) && ( V_80 != V_61 ) ) {
F_5 ( L_72 ,
V_80 , V_54 , V_61 ) ;
return 0 ;
}
V_162 = ( ( V_80 == V_54 ) && ( V_46 == NULL ) ) ||
( ( V_80 == V_61 ) && ( V_153 == NULL ) ) ;
F_36 ( & V_76 , V_72 ) ;
for ( V_74 = V_77 , V_156 = NULL ; V_74 ; ) {
if ( V_74 -> V_80 != V_80 )
F_58 ;
if ( V_162 ) {
V_163 =
( V_74 -> V_147 . V_28 == V_139 ) ;
} else if ( V_80 == V_54 ) {
V_163 =
( ( V_74 -> V_42 . V_46 . V_47 == V_46 -> V_47 ) &&
( V_74 -> V_42 . V_46 . V_48 == V_46 -> V_48 ) ) ;
} else {
V_163 =
memcmp ( V_74 -> V_56 . V_57 , V_153 ,
V_149 ) == 0 ;
}
if ( ! V_163 )
F_58 ;
if ( V_156 )
V_156 -> V_78 = V_74 -> V_78 ;
else
V_77 = V_74 -> V_78 ;
V_74 -> V_78 = V_164 ;
V_164 = V_74 ;
V_3 ++ ;
if ( ! V_162 )
break;
if ( V_156 )
V_74 = V_156 -> V_78 ;
else
V_74 = V_77 ;
}
F_37 ( & V_76 , V_72 ) ;
if ( ! V_162 && ( V_3 == 0 ) ) {
F_5 ( L_70 ) ;
return 0 ;
}
while ( V_164 ) {
V_74 = V_164 -> V_78 ;
F_38 ( V_164 ) ;
V_164 = V_74 ;
}
return V_3 ;
}
static void V_148 ( struct V_20 * V_138 )
{
F_13 ( L_73 , V_138 ) ;
}
static T_3 F_59 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
char * V_169 )
{
struct V_170 * V_171 = F_60 ( V_168 ) ;
T_3 V_19 = 0 ;
struct V_172 * V_173 = F_61 ( V_166 ) ;
struct V_107 * V_129 ;
if ( V_173 != NULL )
V_129 = V_173 -> V_129 ;
else
V_129 = NULL ;
F_43 ( L_74 , V_129 -> V_101 ) ;
if ( V_129 ) {
if ( V_171 -> V_174 )
V_19 = V_171 -> V_174 ( V_129 , V_169 ) ;
}
return V_19 ;
}
static T_3 F_62 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
const char * V_169 , T_4 V_3 )
{
struct V_170 * V_171 = F_60 ( V_168 ) ;
T_3 V_19 = 0 ;
struct V_172 * V_173 = F_61 ( V_166 ) ;
struct V_107 * V_129 ;
if ( V_173 != NULL )
V_129 = V_173 -> V_129 ;
else
V_129 = NULL ;
F_43 ( L_75 , V_129 -> V_101 ) ;
if ( V_129 ) {
if ( V_171 -> V_175 )
V_19 = V_171 -> V_175 ( V_129 , V_169 , V_3 ) ;
}
return V_19 ;
}
int F_63 ( struct V_110 * V_108 )
{
int V_176 = 0 ;
F_43 ( L_76 ) ;
if ( V_108 -> V_114 == NULL ) {
F_5 ( L_77 ) ;
return 1 ;
}
V_108 -> V_177 . V_101 = V_108 -> V_101 ;
V_108 -> V_177 . V_30 = & V_31 ;
V_108 -> V_177 . V_134 = F_53 ;
V_108 -> V_177 . remove = F_56 ;
V_176 = F_64 ( & V_108 -> V_177 ) ;
if ( V_176 )
return V_176 ;
V_108 -> V_177 . V_178 -> V_166 . V_179 = & V_180 ;
return 0 ;
}
void F_65 ( struct V_110 * V_108 )
{
F_43 ( L_78 , V_108 ) ;
F_66 ( & V_108 -> V_177 ) ;
F_43 ( L_57 ) ;
}
static int F_67 ( struct V_20 * V_21 , void * V_64 )
{
struct V_181 * V_178 = (struct V_181 * ) V_64 ;
* V_178 -> V_182 += F_68 ( V_178 -> V_169 + * V_178 -> V_182 , * V_178 -> V_183 - * V_178 -> V_182 ,
L_79 , F_69 ( V_21 ) ) ;
return 0 ;
}
static T_3 F_70 ( struct V_184 * V_184 , char T_5 * V_169 ,
T_4 V_183 , T_6 * V_185 )
{
T_3 V_186 = 0 ;
int V_182 = 0 ;
struct V_73 * V_74 ;
unsigned long V_72 ;
struct V_181 V_187 ;
char * V_188 ;
if ( V_183 > V_189 )
V_183 = V_189 ;
V_188 = F_9 ( V_183 , V_190 ) ;
if ( ! V_188 )
return - V_118 ;
V_182 += F_68 ( V_188 + V_182 , V_183 - V_182 ,
L_80 ) ;
V_187 . V_182 = & V_182 ;
V_187 . V_169 = V_188 ;
V_187 . V_183 = & V_183 ;
if ( F_39 ( & V_31 , NULL ,
( void * ) & V_187 , F_67 ) )
F_5 ( L_81 ) ;
V_182 += F_68 ( V_188 + V_182 , V_183 - V_182 ,
L_82 ) ;
F_71 ( & V_76 , V_72 ) ;
V_74 = V_77 ;
while ( V_74 ) {
if ( V_74 -> V_80 == V_54 ) {
V_182 += F_68 ( V_188 + V_182 , V_183 - V_182 ,
L_83 ,
V_74 -> V_25 ,
V_74 -> V_135 ,
V_74 -> V_42 . V_46 . V_47 ,
V_74 -> V_42 . V_46 . V_48 ,
V_74 -> V_42 . V_49 . V_50 ,
V_74 -> V_42 . V_49 . V_51 ,
V_74 -> V_42 . V_49 . V_52 ,
V_74 -> V_42 . V_49 . V_53 ) ;
} else {
V_182 += F_68 ( V_188 + V_182 , V_183 - V_182 ,
L_84 ,
V_74 -> V_25 ,
V_74 -> V_135 ,
V_74 -> V_56 . V_57 [ 0 ] ,
V_74 -> V_56 . V_57 [ 1 ] ,
V_74 -> V_56 . V_57 [ 2 ] ,
V_74 -> V_56 . V_57 [ 3 ] ,
V_74 -> V_56 . V_57 [ 4 ] ,
V_74 -> V_56 . V_57 [ 5 ] ,
V_74 -> V_56 . V_58 ,
V_74 -> V_56 . V_59 ) ;
}
V_182 += F_68 ( V_188 + V_182 ,
V_183 - V_182 , L_85 ,
V_74 -> V_144 . V_6 ) ;
V_74 = V_74 -> V_78 ;
}
F_72 ( & V_76 , V_72 ) ;
V_182 += F_68 ( V_188 + V_182 , V_183 - V_182 , L_86 ) ;
V_186 = F_73 ( V_169 , V_183 , V_185 , V_188 , V_182 ) ;
F_25 ( V_188 ) ;
return V_186 ;
}
static int T_7 F_74 ( void )
{
int V_19 ;
if ( ! V_191 )
return - V_132 ;
F_10 ( V_23 , V_24 ) ;
V_19 = F_75 ( & V_31 ) ;
if ( V_19 ) {
F_5 ( L_87 , V_19 ) ;
F_19 ( V_34 , V_19 ,
V_35 ) ;
return V_19 ;
}
F_43 ( L_88 ) ;
F_52 ( & V_37 , L_89 , L_90 ,
V_192 , NULL ) ;
V_19 = F_12 ( & V_29 ) ;
if ( V_19 ) {
F_5 ( L_6 , V_19 ) ;
F_76 ( & V_31 ) ;
F_19 ( V_34 , V_19 ,
V_35 ) ;
return V_19 ;
}
F_43 ( L_91 , V_19 ) ;
if ( ! F_77 ( 2 , ( void * ) & F_41 ,
& V_36 ) ) {
F_5 ( L_92 ) ;
F_10 ( V_34 , V_35 ) ;
F_24 ( & V_29 ) ;
F_76 ( & V_31 ) ;
return - 1 ;
}
F_13 ( L_93 ,
( void * ) & F_41 ) ;
V_193 = F_78 ( L_90 , NULL ) ;
F_79 ( L_94 , V_194 , V_193 ,
NULL , & V_195 ) ;
F_13 ( L_57 ) ;
F_10 ( V_38 , V_24 ) ;
return 0 ;
}
static void T_8 F_80 ( void )
{
F_13 ( L_95 ) ;
if ( ! F_77 ( 2 , NULL , NULL ) )
F_5 ( L_92 ) ;
F_24 ( & V_29 ) ;
F_76 ( & V_31 ) ;
F_81 ( V_193 ) ;
F_13 ( L_57 ) ;
}
