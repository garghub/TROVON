static inline char *
F_1 ( char * V_1 )
{
if ( V_1 )
return V_1 ;
return L_1 ;
}
static T_1 F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
T_2 V_7 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_10 ) , & V_7 , sizeof( T_2 ) ) ;
return F_5 ( V_6 , V_11 , L_2 , V_7 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
T_2 V_7 ;
int V_13 ;
if ( F_7 ( V_6 , 10 , & V_7 ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( struct V_9 , V_10 ) ,
& V_7 , sizeof( T_2 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
struct V_15 V_16 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_17 ) , & V_16 ,
sizeof( struct V_15 ) ) ;
return F_5 ( V_6 , V_11 , L_2 ,
V_16 . V_18 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
int V_19 , V_13 ;
struct V_15 V_16 ;
if ( F_11 ( V_6 , 10 , & V_19 ) != 0 )
return - V_14 ;
V_16 . V_18 = V_19 ;
V_13 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_17 ) ,
& ( V_16 ) ,
sizeof( struct V_15 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_4 error ;
F_3 ( V_8 , F_4 (
struct V_9 , V_20 ) ,
& error , sizeof( T_4 ) ) ;
return F_5 ( V_6 , V_11 , L_3 , error ) ;
}
static T_1 F_13 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
T_4 error ;
int V_13 ;
if ( F_14 ( V_6 , 10 , & error ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_20 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_4 V_21 ;
F_3 ( V_8 , F_4 (
struct V_9 , V_22 ) ,
& V_21 , sizeof( T_4 ) ) ;
return F_5 ( V_6 , V_11 , L_3 , V_21 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
T_4 V_21 ;
int V_13 ;
if ( F_14 ( V_6 , 10 , & V_21 ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_22 ) ,
& V_21 , sizeof( T_4 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 )
{
T_5 V_23 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_24 ) ,
& V_23 ,
sizeof( T_5 ) ) ;
return F_5 ( V_6 , V_11 , L_4 , V_23 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
T_5 V_23 ;
int V_13 ;
if ( F_19 ( V_6 , 10 , & V_23 ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_24 ) ,
& V_23 , sizeof( T_5 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static void
F_20 ( void * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) ( V_25 ) ;
if ( V_27 -> V_28 ) {
F_21 ( V_27 -> V_28 ) ;
V_27 -> V_28 = NULL ;
}
F_22 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
F_22 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
V_27 -> V_31 . V_32 = 0 ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
}
static void
F_23 ( void * V_25 )
{
struct V_33 * V_27 =
(struct V_33 * ) ( V_25 ) ;
V_27 -> V_31 . V_32 = 0 ;
memset ( V_27 , 0 , sizeof( struct V_33 ) ) ;
}
static T_2
F_24 ( void )
{
int V_34 ;
T_2 V_35 = 1 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ )
V_35 &= V_37 [ V_34 ] ;
return V_35 ;
}
static void
F_25 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ )
V_37 [ V_34 ] = 0 ;
}
void
F_26 (
struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
F_27 ( & V_44 ) ;
if ( V_39 == NULL ) {
memset ( & V_45 , 0 ,
sizeof( V_45 ) ) ;
V_46 = 0 ;
} else {
V_45 = * V_39 ;
V_46 = 1 ;
}
if ( V_41 )
* V_41 = V_47 ;
if ( V_43 )
F_28 ( V_43 , L_5 , L_6 ,
V_48 , NULL ) ;
F_29 ( & V_44 ) ;
}
void
F_30 (
struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
F_27 ( & V_44 ) ;
if ( V_39 == NULL ) {
memset ( & V_49 , 0 ,
sizeof( V_49 ) ) ;
V_50 = 0 ;
} else {
V_49 = * V_39 ;
V_50 = 1 ;
}
if ( V_41 )
* V_41 = V_47 ;
if ( V_43 )
F_28 ( V_43 , L_7 ,
L_6 , V_48 , NULL ) ;
F_29 ( & V_44 ) ;
}
static void
F_31 ( void )
{
struct V_26 * V_51 , * V_52 ;
struct V_33 * V_53 , * V_54 ;
F_32 (bi, tmp_bi, &BusInfoList, entry) {
F_20 ( V_51 ) ;
F_33 ( & V_51 -> V_55 ) ;
F_22 ( V_51 ) ;
}
F_32 (di, tmp_di, &DevInfoList, entry) {
F_23 ( V_53 ) ;
F_33 ( & V_53 -> V_55 ) ;
F_22 ( V_53 ) ;
}
}
static void
F_34 ( struct V_56 * V_57 )
{
static int V_58 ;
enum V_59 V_60 = 0 ;
int V_61 = V_62 ;
F_35 ( V_63 , V_64 ) ;
if ( V_58 ) {
F_36 ( L_8 ) ;
V_61 = - V_65 ;
goto V_66;
}
V_58 = 1 ;
F_35 ( V_67 , V_64 ) ;
V_60 =
V_57 -> V_68 . V_69 .
V_60 & V_70 ;
V_60 |= V_71 ;
V_66:
if ( V_61 < 0 )
F_31 () ;
if ( V_57 -> V_72 . V_73 . V_74 )
F_37 ( & V_57 -> V_72 , V_61 , V_60 ) ;
}
static void
F_38 ( struct V_56 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
memset ( V_75 , 0 , sizeof( struct V_56 ) ) ;
memcpy ( & V_75 -> V_72 , V_77 , sizeof( struct V_76 ) ) ;
V_75 -> V_72 . V_79 = 0 ;
V_75 -> V_72 . V_80 = 0 ;
V_75 -> V_72 . V_81 = 0 ;
if ( V_78 < 0 ) {
V_75 -> V_72 . V_73 . V_82 = 1 ;
V_75 -> V_72 . V_83 = ( T_4 ) ( - V_78 ) ;
}
}
static void
F_39 ( struct V_76 * V_77 , int V_78 )
{
struct V_56 V_84 ;
F_38 ( & V_84 , V_77 , V_78 ) ;
if ( V_77 -> V_85 == V_86
&& V_87 . V_88 . V_89 ==
V_90
&& V_87 . V_88 . V_91 ==
V_92 )
V_84 . V_68 = V_87 ;
if ( V_84 . V_72 . V_73 . V_93 == 1 ) {
F_40 ( L_9 ,
V_94 , V_84 . V_72 . V_85 , V_78 ) ;
return;
}
if ( ! F_41 ( V_8 ,
V_95 , & V_84 ) ) {
F_36 ( L_10 ) ;
return;
}
}
static void
F_37 ( struct V_76 * V_77 ,
int V_78 ,
enum V_59 V_60 )
{
struct V_56 V_84 ;
F_38 ( & V_84 , V_77 , V_78 ) ;
V_84 . V_68 . V_69 . V_60 = V_60 ;
if ( ! F_41 ( V_8 ,
V_95 , & V_84 ) ) {
F_36 ( L_10 ) ;
return;
}
}
static void F_42 (
struct V_76 * V_77 , int V_78 ,
struct V_96 V_31 )
{
struct V_56 V_84 ;
F_38 ( & V_84 , V_77 , V_78 ) ;
V_84 . V_68 . V_88 . V_31 = V_31 ;
V_84 . V_68 . V_88 . V_73 . V_97 = 1 ;
if ( ! F_41 ( V_8 ,
V_95 , & V_84 ) ) {
F_36 ( L_10 ) ;
return;
}
}
void
F_43 ( struct V_56 * V_75 ,
enum V_98 type )
{
T_4 V_99 ;
T_5 V_100 ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_101 ) ,
& V_100 , sizeof( T_5 ) ) < 0 ) {
F_36 ( L_11 ) ;
F_35 ( V_102 ,
V_103 ) ;
return;
}
if ( V_100 != V_104 ) {
F_36 ( L_12 ,
V_100 ) ;
F_44 ( V_105 ,
V_100 ,
V_103 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_106 ) ,
& V_99 , sizeof( T_4 ) ) < 0 ) {
F_36 ( L_13 ) ;
F_35 ( V_102 ,
V_103 ) ;
return;
}
if ( type == V_107 ) {
if ( F_8 ( V_8 ,
V_99 ,
V_75 ,
sizeof( struct V_56 ) ) < 0 ) {
F_36 ( L_14 ) ;
F_35 ( V_108 ,
V_103 ) ;
return;
}
} else {
if ( F_8 ( V_8 ,
V_99 +
sizeof( struct V_56 ) , V_75 ,
sizeof( struct V_56 ) ) < 0 ) {
F_36 ( L_15 ) ;
F_35 ( V_109 ,
V_103 ) ;
return;
}
}
}
static void
F_45 ( enum V_110 V_111 , T_6 V_112 , int V_78 )
{
struct V_26 * V_27 = NULL ;
BOOL V_113 = FALSE ;
V_27 = F_46 ( & V_114 , V_112 ) ;
if ( ! V_27 ) {
F_36 ( L_16 , V_112 ) ;
return;
}
if ( V_78 < 0 ) {
if ( ( V_111 == V_115 ) &&
( V_78 != ( - V_65 ) ) )
F_47 ( & V_116 , V_112 ) ;
} else {
if ( V_111 == V_115 )
V_27 -> V_31 . V_32 = 1 ;
if ( V_111 == V_117 )
V_113 = TRUE ;
}
if ( V_27 -> V_118 . V_85 == V_119 ) {
F_36 ( L_17 ) ;
return;
}
if ( V_27 -> V_118 . V_85 != ( T_4 ) V_111 ) {
F_36 ( L_18 , V_111 , V_27 -> V_118 . V_85 ) ;
return;
}
F_39 ( & V_27 -> V_118 , V_78 ) ;
V_27 -> V_118 . V_85 = V_119 ;
if ( V_113 ) {
F_20 ( V_27 ) ;
F_47 ( & V_116 , V_112 ) ;
}
}
static void
F_48 ( enum V_110 V_111 ,
T_6 V_112 , T_6 V_120 , int V_78 ,
struct V_96 V_121 )
{
struct V_33 * V_27 = NULL ;
struct V_56 V_84 ;
V_27 = F_49 ( & V_116 , V_112 , V_120 ) ;
if ( ! V_27 ) {
F_36 ( L_19 , V_112 , V_120 ) ;
return;
}
if ( V_27 -> V_118 . V_85 == V_119 ) {
F_36 ( L_20 ) ;
return;
}
if ( V_27 -> V_118 . V_85 != V_111 ) {
F_36 ( L_18 , V_111 , V_27 -> V_118 . V_85 ) ;
return;
}
F_38 ( & V_84 , & V_27 -> V_118 , V_78 ) ;
V_84 . V_68 . V_88 . V_89 = V_112 ;
V_84 . V_68 . V_88 . V_91 = V_120 ;
V_84 . V_68 . V_88 . V_31 = V_121 ;
if ( ! F_41 ( V_8 ,
V_95 , & V_84 ) ) {
F_36 ( L_10 ) ;
return;
}
V_27 -> V_118 . V_85 = V_119 ;
}
static void
F_50 ( enum V_110 V_111 , T_6 V_112 , T_6 V_120 ,
int V_78 )
{
struct V_33 * V_27 = NULL ;
BOOL V_113 = FALSE ;
V_27 = F_49 ( & V_116 , V_112 , V_120 ) ;
if ( ! V_27 ) {
F_36 ( L_19 , V_112 , V_120 ) ;
return;
}
if ( V_78 >= 0 ) {
if ( V_111 == V_122 )
V_27 -> V_31 . V_32 = 1 ;
if ( V_111 == V_123 )
V_113 = TRUE ;
}
if ( V_27 -> V_118 . V_85 == V_119 ) {
F_36 ( L_20 ) ;
return;
}
if ( V_27 -> V_118 . V_85 != ( T_4 ) V_111 ) {
F_36 ( L_18 , V_111 , V_27 -> V_118 . V_85 ) ;
return;
}
F_39 ( & V_27 -> V_118 , V_78 ) ;
V_27 -> V_118 . V_85 = V_119 ;
if ( V_113 )
F_23 ( V_27 ) ;
}
static void
F_51 ( T_4 V_112 ,
T_4 V_68 , struct V_76 * V_77 ,
int V_78 , BOOL V_124 )
{
BOOL V_125 = FALSE ;
struct V_26 * V_126 = F_46 ( & V_114 , V_112 ) ;
if ( ! V_126 ) {
F_36 ( L_21 , V_112 ) ;
return;
}
if ( V_124 ) {
memcpy ( & V_126 -> V_118 , V_77 ,
sizeof( struct V_76 ) ) ;
} else
V_126 -> V_118 . V_85 = V_119 ;
F_27 ( & V_44 ) ;
if ( V_78 == V_62 ) {
switch ( V_68 ) {
case V_115 :
if ( V_45 . V_127 ) {
(* V_45 . V_127 ) ( V_112 ) ;
V_125 = TRUE ;
}
if ( ( ! V_126 -> V_73 . V_128 ) &&
V_49 . V_127 ) {
(* V_49 . V_127 ) ( V_112 ) ;
V_125 = TRUE ;
}
break;
case V_117 :
if ( V_45 . V_129 ) {
(* V_45 . V_129 ) ( V_112 ) ;
V_125 = TRUE ;
}
if ( ( ! V_126 -> V_73 . V_128 ) &&
V_49 . V_129 ) {
(* V_49 . V_129 ) ( V_112 ) ;
V_125 = TRUE ;
}
break;
}
}
if ( V_125 )
;
else
F_45 ( V_68 , V_112 , V_78 ) ;
F_29 ( & V_44 ) ;
}
static void
F_52 ( T_4 V_112 , T_4 V_120 , struct V_96 V_31 , T_4 V_68 ,
struct V_76 * V_77 , int V_78 ,
BOOL V_124 , BOOL V_130 )
{
struct V_38 * V_39 = NULL ;
BOOL V_125 = FALSE ;
struct V_33 * V_131 =
F_49 ( & V_116 , V_112 , V_120 ) ;
char * V_132 [] = {
L_22 ,
NULL
} ;
if ( ! V_131 ) {
F_36 ( L_23 , V_112 , V_120 ) ;
return;
}
if ( V_130 )
V_39 = & V_45 ;
else
V_39 = & V_49 ;
if ( V_124 ) {
memcpy ( & V_131 -> V_118 , V_77 ,
sizeof( struct V_76 ) ) ;
} else
V_131 -> V_118 . V_85 = V_119 ;
F_27 ( & V_44 ) ;
if ( V_78 >= 0 ) {
switch ( V_68 ) {
case V_122 :
if ( V_39 -> V_133 ) {
(* V_39 -> V_133 ) ( V_112 , V_120 ) ;
V_125 = TRUE ;
}
break;
case V_86 :
if ( V_31 . V_134 == V_135 . V_134 &&
V_31 . V_136 ==
V_135 . V_136 ) {
if ( V_39 -> V_137 ) {
(* V_39 -> V_137 ) ( V_112 ,
V_120 ) ;
V_125 = TRUE ;
}
}
else if ( V_31 . V_134 == V_138 . V_134 &&
V_31 . V_136 ==
V_138 . V_136 ) {
if ( V_39 -> V_139 ) {
(* V_39 -> V_139 ) ( V_112 ,
V_120 ) ;
V_125 = TRUE ;
}
} else if ( V_31 . V_134 == V_140 . V_134 &&
V_31 . V_136 ==
V_140 . V_136 ) {
if ( V_112 == V_90
&& V_120 == V_92 ) {
F_40 ( L_24 ,
V_112 , V_120 ) ;
F_53
( & V_141 . V_3 .
V_142 , V_143 , V_132 ) ;
}
}
break;
case V_123 :
if ( V_39 -> V_144 ) {
(* V_39 -> V_144 ) ( V_112 , V_120 ) ;
V_125 = TRUE ;
}
break;
}
}
if ( V_125 )
;
else
F_50 ( V_68 , V_112 , V_120 , V_78 ) ;
F_29 ( & V_44 ) ;
}
static void
V_127 ( struct V_56 * V_57 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_146 . V_89 ;
int V_61 = V_62 ;
struct V_26 * V_126 = NULL ;
V_126 = F_46 ( & V_114 , V_112 ) ;
if ( V_126 && ( V_126 -> V_31 . V_32 == 1 ) ) {
F_36 ( L_25 ,
V_112 ) ;
F_44 ( V_147 , V_112 ,
V_103 ) ;
V_61 = - V_65 ;
goto V_66;
}
V_126 = F_54 ( sizeof( struct V_26 ) , V_148 ) ;
if ( V_126 == NULL ) {
F_36 ( L_26 ,
V_112 ) ;
F_44 ( V_147 , V_112 ,
V_103 ) ;
V_61 = - V_149 ;
goto V_66;
}
F_55 ( & V_126 -> V_55 ) ;
V_126 -> V_89 = V_112 ;
V_126 -> V_91 = V_68 -> V_146 . V_150 ;
F_44 ( V_151 , V_112 , V_64 ) ;
if ( V_57 -> V_72 . V_73 . V_93 == 1 )
V_126 -> V_152 . V_153 = V_154 ;
else
V_126 -> V_152 . V_153 = V_155 ;
V_126 -> V_73 . V_128 = V_57 -> V_72 . V_73 . V_128 ;
V_126 -> V_152 . V_156 = V_68 -> V_146 . V_156 ;
V_126 -> V_152 . V_157 = V_68 -> V_146 . V_158 ;
V_126 -> V_152 . V_159 =
V_68 -> V_146 . V_160 ;
V_126 -> V_152 . V_161 = V_68 -> V_146 . V_162 ;
F_56 ( & V_126 -> V_55 , & V_114 ) ;
F_44 ( V_163 , V_112 , V_64 ) ;
V_66:
F_51 ( V_112 , V_115 , & V_57 -> V_72 ,
V_61 , V_57 -> V_72 . V_73 . V_74 == 1 ) ;
}
static void
V_129 ( struct V_56 * V_57 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_164 . V_89 ;
struct V_26 * V_126 ;
int V_61 = V_62 ;
V_126 = F_46 ( & V_114 , V_112 ) ;
if ( ! V_126 ) {
F_36 ( L_27 , V_112 ) ;
V_61 = - V_165 ;
goto V_66;
}
if ( V_126 -> V_31 . V_32 == 0 ) {
F_36 ( L_28 ,
V_112 ) ;
V_61 = - V_65 ;
goto V_66;
}
V_66:
F_51 ( V_112 , V_117 , & V_57 -> V_72 ,
V_61 , V_57 -> V_72 . V_73 . V_74 == 1 ) ;
}
static void
F_57 ( struct V_56 * V_57 , T_7 * V_166 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_167 . V_89 ;
struct V_26 * V_126 = NULL ;
int V_61 = V_62 ;
char V_1 [ 99 ] ;
V_112 = V_68 -> V_167 . V_89 ;
F_44 ( V_168 , V_112 , V_64 ) ;
V_126 = F_46 ( & V_114 , V_112 ) ;
if ( ! V_126 ) {
F_36 ( L_29 ,
V_112 ) ;
F_44 ( V_169 , V_112 ,
V_103 ) ;
V_61 = - V_165 ;
goto V_66;
}
if ( V_126 -> V_31 . V_32 == 0 ) {
F_36 ( L_30 ,
V_112 ) ;
F_44 ( V_169 , V_112 ,
V_103 ) ;
V_61 = - V_165 ;
goto V_66;
}
if ( V_126 -> V_118 . V_85 != V_119 ) {
F_36 ( L_31 ,
V_112 , ( V_170 ) V_126 -> V_118 . V_85 ) ;
F_44 ( V_169 , V_112 ,
V_103 ) ;
V_61 = - V_171 ;
goto V_66;
}
V_126 -> V_172 = V_68 -> V_167 . V_173 ;
V_126 -> V_174 = F_58 ( V_166 ) ;
F_59 ( V_166 , V_175 ) ;
V_126 -> V_29 = F_60 ( V_166 ) ;
F_61 ( & V_126 -> V_174 , V_1 ) ;
F_44 ( V_176 , V_112 , V_64 ) ;
V_66:
F_51 ( V_112 , V_177 , & V_57 -> V_72 ,
V_61 , V_57 -> V_72 . V_73 . V_74 == 1 ) ;
}
static void
F_62 ( struct V_56 * V_57 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_178 . V_89 ;
T_6 V_120 = V_68 -> V_178 . V_91 ;
struct V_33 * V_131 = NULL ;
struct V_26 * V_126 = NULL ;
int V_61 = V_62 ;
V_131 = F_49 ( & V_116 , V_112 , V_120 ) ;
if ( V_131 && ( V_131 -> V_31 . V_32 == 1 ) ) {
F_36 ( L_32 ,
V_112 , V_120 ) ;
F_63 ( V_179 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_65 ;
goto V_66;
}
V_126 = F_46 ( & V_114 , V_112 ) ;
if ( ! V_126 ) {
F_36 ( L_33 ,
V_112 ) ;
F_63 ( V_179 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_165 ;
goto V_66;
}
if ( V_126 -> V_31 . V_32 == 0 ) {
F_36 ( L_34 ,
V_112 ) ;
F_63 ( V_179 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_165 ;
goto V_66;
}
V_131 = F_54 ( sizeof( struct V_33 ) , V_148 ) ;
if ( V_131 == NULL ) {
F_36 ( L_35 ,
V_112 , V_120 ) ;
F_63 ( V_179 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_149 ;
goto V_66;
}
F_55 ( & V_131 -> V_55 ) ;
V_131 -> V_89 = V_112 ;
V_131 -> V_91 = V_120 ;
V_131 -> V_180 = V_68 -> V_178 . V_180 ;
F_63 ( V_181 , V_120 , V_112 ,
V_64 ) ;
if ( V_57 -> V_72 . V_73 . V_93 == 1 )
V_131 -> V_152 . V_153 = V_154 ;
else
V_131 -> V_152 . V_153 = V_155 ;
V_131 -> V_152 . V_156 = V_68 -> V_178 . V_156 ;
V_131 -> V_152 . V_157 = V_68 -> V_178 . V_158 ;
V_131 -> V_152 . V_159 =
V_68 -> V_178 . V_182 ;
V_131 -> V_152 . V_183 = V_68 -> V_178 . V_183 ;
F_56 ( & V_131 -> V_55 , & V_116 ) ;
F_63 ( V_184 , V_120 , V_112 ,
V_64 ) ;
V_66:
if ( V_131 &&
F_64 ( V_131 -> V_152 . V_159 ) ) {
V_90 = V_112 ;
V_92 = V_120 ;
F_40 ( L_36 ,
V_90 , V_92 ) ;
}
F_52 ( V_112 , V_120 , V_135 ,
V_122 , & V_57 -> V_72 , V_61 ,
V_57 -> V_72 . V_73 . V_74 == 1 ,
F_65 ( V_131 -> V_152 . V_159 ) ) ;
}
static void
F_66 ( struct V_56 * V_57 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_88 . V_89 ;
T_6 V_120 = V_68 -> V_88 . V_91 ;
struct V_96 V_31 = V_68 -> V_88 . V_31 ;
struct V_33 * V_131 = NULL ;
int V_61 = V_62 ;
V_131 = F_49 ( & V_116 , V_112 , V_120 ) ;
if ( ! V_131 ) {
F_36 ( L_37 ,
V_112 , V_120 ) ;
F_63 ( V_185 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_186 ;
goto V_66;
}
if ( V_131 -> V_31 . V_32 == 0 ) {
F_36 ( L_38 ,
V_112 , V_120 ) ;
F_63 ( V_185 , V_120 , V_112 ,
V_103 ) ;
V_61 = - V_186 ;
}
V_66:
if ( ( V_61 >= V_62 ) && V_131 )
F_52 ( V_112 , V_120 , V_31 , V_86 ,
& V_57 -> V_72 , V_61 ,
V_57 -> V_72 . V_73 . V_74 == 1 ,
F_65 (
V_131 -> V_152 . V_159 ) ) ;
}
static void
F_67 ( struct V_56 * V_57 )
{
struct V_145 * V_68 = & V_57 -> V_68 ;
T_6 V_112 = V_68 -> V_187 . V_89 ;
T_6 V_120 = V_68 -> V_187 . V_91 ;
struct V_33 * V_131 = NULL ;
int V_61 = V_62 ;
V_131 = F_49 ( & V_116 , V_112 , V_120 ) ;
if ( ! V_131 ) {
F_36 ( L_39 ,
V_112 , V_120 ) ;
V_61 = - V_186 ;
goto V_66;
}
if ( V_131 -> V_31 . V_32 == 0 ) {
F_36 ( L_40 ,
V_112 , V_120 ) ;
V_61 = - V_65 ;
}
V_66:
if ( ( V_61 >= V_62 ) && V_131 )
F_52 ( V_112 , V_120 , V_135 ,
V_123 , & V_57 -> V_72 , V_61 ,
V_57 -> V_72 . V_73 . V_74 == 1 ,
F_65 (
V_131 -> V_152 . V_159 ) ) ;
}
static int
F_68 ( T_8 V_188 , T_9 V_189 , T_4 V_190 ,
T_10 * V_191 )
{
T_2 T_11 * V_192 = NULL ;
int V_61 = V_62 ;
if ( V_191 == NULL ) {
F_36 ( L_41 ,
__FILE__ , __LINE__ ) ;
V_61 = - V_193 ;
goto V_66;
}
memset ( V_191 , 0 , sizeof( T_10 ) ) ;
if ( ( V_189 == 0 ) || ( V_190 == 0 ) ) {
F_36 ( L_42 ,
( T_9 ) V_189 , ( T_9 ) V_190 ) ;
V_61 = - V_193 ;
goto V_66;
}
V_192 = F_69 ( V_188 + V_189 , V_190 ) ;
if ( V_192 == NULL ) {
F_36 ( L_43 ,
( T_9 ) V_189 , ( T_9 ) V_190 ) ;
V_61 = - V_194 ;
goto V_66;
}
V_191 -> V_189 = V_189 ;
V_191 -> V_190 = V_190 ;
V_191 -> V_195 = V_192 ;
F_40 ( L_44 ,
( T_9 ) ( V_191 -> V_189 ) , ( T_6 ) ( V_191 -> V_190 ) , V_191 -> V_195 ) ;
V_66:
if ( V_61 < 0 ) {
if ( V_192 != NULL ) {
F_70 ( V_192 ) ;
V_192 = NULL ;
}
}
return V_61 ;
}
static void
F_71 ( T_10 * V_191 )
{
if ( V_191 -> V_195 != NULL ) {
F_70 ( V_191 -> V_195 ) ;
V_191 -> V_195 = NULL ;
}
memset ( V_191 , 0 , sizeof( T_10 ) ) ;
}
static void
F_72 ( void )
{
T_8 V_188 = F_73 ( V_8 ) ;
T_9 V_196 = 0 ;
T_4 V_197 = 0 ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_198 ) ,
& V_196 , sizeof( V_196 ) ) < 0 ) {
F_36 ( L_45 ) ;
F_35 ( V_199 ,
V_103 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_200 ) ,
& V_197 , sizeof( V_197 ) ) < 0 ) {
F_36 ( L_45 ) ;
F_35 ( V_199 ,
V_103 ) ;
return;
}
F_68 ( V_188 ,
V_196 , V_197 ,
& V_201 ) ;
}
int
F_74 ( void )
{
F_75 ( & V_141 . V_3 . V_142 , V_143 ) ;
return V_62 ;
}
int
F_76 ( void )
{
char V_202 [ 20 ] ;
char * V_132 [] = { V_202 , NULL } ;
sprintf ( V_202 , L_46 , 1 ) ;
F_53 ( & V_141 . V_3 . V_142 , V_203 ,
V_132 ) ;
return V_62 ;
}
int
F_77 ( void )
{
F_75 ( & V_141 . V_3 . V_142 , V_204 ) ;
return V_62 ;
}
static void
F_78 ( struct V_76 * V_77 )
{
int V_61 = F_74 () ;
if ( V_61 != V_62 )
V_61 = - V_61 ;
if ( V_77 -> V_73 . V_74 && ! V_205 )
F_39 ( V_77 , V_61 ) ;
if ( V_77 -> V_73 . V_74 && V_205 ) {
V_206 = * V_77 ;
F_40 ( L_47 ) ;
}
}
static void
F_79 ( struct V_76 * V_77 )
{
int V_61 = F_76 () ;
if ( V_61 != V_62 )
V_61 = - V_61 ;
if ( V_77 -> V_73 . V_74 )
F_39 ( V_77 , V_61 ) ;
}
static void
F_80 ( struct V_76 * V_77 )
{
int V_61 = F_77 () ;
if ( V_61 != V_62 )
V_61 = - V_61 ;
if ( V_77 -> V_73 . V_74 )
F_39 ( V_77 , V_61 ) ;
}
static BOOL
F_81 ( struct V_56 * V_75 )
{
if ( F_82 ( V_8 ,
V_207 , V_75 ) ) {
if ( V_75 -> V_72 . V_73 . V_93 == 1 ) {
F_36 ( L_48 ,
V_75 -> V_72 . V_85 ) ;
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
static int
F_83 ( void )
{
static T_12 V_85 = F_84 ( 0 ) ;
return F_85 ( & V_85 ) ;
}
static unsigned long
F_86 ( void )
{
return V_208 + V_209 * V_210 / 1000 ;
}
static struct V_211 *
F_87 ( struct V_56 * V_75 )
{
struct V_211 * V_212 =
F_88 ( sizeof( struct V_211 ) ,
V_148 | V_213 ) ;
if ( V_212 == NULL )
return NULL ;
V_212 -> V_85 = F_83 () ;
V_212 -> V_214 = F_86 () ;
V_212 -> V_75 = * V_75 ;
return V_212 ;
}
static void
F_89 ( struct V_211 * V_212 )
{
F_22 ( V_212 ) ;
}
static void
F_90 ( struct V_211 * V_212 )
{
struct V_145 * V_68 = & V_212 -> V_75 . V_68 ;
char V_215 [ 40 ] , V_216 [ 40 ] , V_217 [ 40 ] , V_218 [ 40 ] , V_219 [ 40 ] ,
V_220 [ 40 ] ;
char * V_132 [] = {
V_215 , V_216 , V_217 , V_218 , V_219 , V_220 , NULL
} ;
sprintf ( V_215 , L_49 ) ;
sprintf ( V_216 , L_50 , V_212 -> V_85 ) ;
sprintf ( V_217 , L_51 ,
V_68 -> V_88 . V_31 . V_221 ) ;
sprintf ( V_218 , L_52 ,
V_68 -> V_88 . V_89 ) ;
sprintf ( V_219 , L_53 ,
V_68 -> V_88 . V_91 >> 3 ) ;
sprintf ( V_220 , L_54 ,
V_68 -> V_88 . V_91 & 0x7 ) ;
F_40 ( L_55 ,
V_68 -> V_88 . V_31 . V_221 ,
V_68 -> V_88 . V_89 ,
V_68 -> V_88 . V_91 >> 3 ,
V_68 -> V_88 . V_91 & 7 , V_212 -> V_85 ) ;
F_53 ( & V_141 . V_3 . V_142 , V_203 ,
V_132 ) ;
}
static void
F_91 ( void )
{
struct V_222 * V_223 = NULL ;
struct V_222 * V_224 = NULL ;
F_92 ( & V_225 ) ;
F_93 (pos, tmp, &Parahotplug_request_list) {
struct V_211 * V_212 =
F_94 ( V_223 , struct V_211 , V_226 ) ;
if ( F_95 ( V_208 , V_212 -> V_214 ) ) {
F_33 ( V_223 ) ;
if ( V_212 -> V_75 . V_72 . V_73 . V_74 )
F_42 (
& V_212 -> V_75 . V_72 ,
V_227 ,
V_212 -> V_75 . V_68 . V_88 . V_31 ) ;
F_89 ( V_212 ) ;
}
}
F_96 ( & V_225 ) ;
}
static int
F_97 ( int V_85 , T_5 V_221 )
{
struct V_222 * V_223 = NULL ;
struct V_222 * V_224 = NULL ;
F_92 ( & V_225 ) ;
F_93 (pos, tmp, &Parahotplug_request_list) {
struct V_211 * V_212 =
F_94 ( V_223 , struct V_211 , V_226 ) ;
if ( V_212 -> V_85 == V_85 ) {
F_33 ( V_223 ) ;
F_96 ( & V_225 ) ;
V_212 -> V_75 . V_68 . V_88 . V_31 . V_221 = V_221 ;
if ( V_212 -> V_75 . V_72 . V_73 . V_74 )
F_42 (
& V_212 -> V_75 . V_72 , V_62 ,
V_212 -> V_75 . V_68 . V_88 . V_31 ) ;
F_89 ( V_212 ) ;
return 0 ;
}
}
F_96 ( & V_225 ) ;
return - 1 ;
}
static void
F_98 ( struct V_56 * V_57 )
{
struct V_211 * V_212 ;
V_212 = F_87 ( V_57 ) ;
if ( V_212 == NULL ) {
F_36 ( L_56 ) ;
return;
}
if ( V_57 -> V_68 . V_88 . V_31 . V_221 ) {
F_90 ( V_212 ) ;
F_42 ( & V_57 -> V_72 ,
V_62 , V_57 -> V_68 .
V_88 . V_31 ) ;
F_89 ( V_212 ) ;
} else {
F_92 ( & V_225 ) ;
F_99 ( & ( V_212 -> V_226 ) , & V_228 ) ;
F_96 ( & V_225 ) ;
F_90 ( V_212 ) ;
}
}
static BOOL
F_100 ( struct V_56 V_57 , T_8 V_156 )
{
struct V_145 * V_68 = & V_57 . V_68 ;
T_9 V_229 = 0 ;
T_4 V_230 = 0 ;
T_7 * V_166 = NULL ;
BOOL V_231 = FALSE ;
struct V_56 V_232 ;
V_231 = ( V_57 . V_72 . V_73 . V_93 == 1 ) ;
if ( V_156 == 0 ) {
F_36 ( L_57 ) ;
return TRUE ;
}
V_229 = V_156 + V_57 . V_72 . V_80 ;
V_230 = V_57 . V_72 . V_79 ;
if ( V_229 != 0 && V_230 != 0 ) {
BOOL V_233 = FALSE ;
V_166 =
F_101 ( V_229 , V_230 ,
V_231 , & V_233 ) ;
if ( ! V_166 ) {
if ( V_233 ) {
F_102 ( L_58 ) ;
return FALSE ;
}
F_102 ( L_59 ) ;
F_102 ( L_60 , ( T_6 ) V_57 . V_72 . V_85 ) ;
F_102 ( L_61 , ( T_9 ) V_229 ) ;
F_102 ( L_62 , ( T_6 ) V_230 ) ;
F_102 ( L_63 , V_231 ) ;
}
}
if ( ! V_231 ) {
F_38 ( & V_232 , & V_57 . V_72 ,
V_62 ) ;
if ( ( V_8 )
&&
( ! F_41
( V_8 , V_234 , & V_232 ) ) )
F_102 ( L_64 ) ;
}
switch ( V_57 . V_72 . V_85 ) {
case V_235 :
F_40 ( L_65 ,
( T_6 ) V_57 . V_68 . V_69 . V_236 ,
( T_6 ) V_57 . V_68 . V_69 . V_237 ) ;
F_34 ( & V_57 ) ;
break;
case V_115 :
F_40 ( L_66 ,
( T_6 ) V_68 -> V_146 . V_89 ,
( T_6 ) V_68 -> V_146 . V_150 ) ;
V_127 ( & V_57 ) ;
break;
case V_117 :
F_40 ( L_67 , ( T_6 ) V_68 -> V_164 . V_89 ) ;
V_129 ( & V_57 ) ;
break;
case V_177 :
F_40 ( L_68 , ( T_6 ) V_68 -> V_167 . V_89 ) ;
F_57 ( & V_57 , V_166 ) ;
break;
case V_122 :
F_40 ( L_69 ,
( T_6 ) V_68 -> V_178 . V_89 ,
( T_6 ) V_68 -> V_178 . V_91 ) ;
F_62 ( & V_57 ) ;
break;
case V_86 :
if ( V_68 -> V_88 . V_73 . V_97 ) {
F_40 ( L_70 ,
( T_6 ) V_68 -> V_88 . V_89 ,
( T_6 ) V_68 -> V_88 . V_91 ,
( T_6 ) V_68 -> V_88 . V_31 . V_221 ) ;
F_98 ( & V_57 ) ;
} else {
F_40 ( L_71 ,
( T_6 ) V_68 -> V_88 . V_89 ,
( T_6 ) V_68 -> V_88 . V_91 ,
( T_6 ) V_68 -> V_88 . V_31 . V_134 ) ;
F_66 ( & V_57 ) ;
V_238 = V_57 . V_72 ;
V_87 = V_57 . V_68 ;
break;
}
break;
case V_123 :
F_40 ( L_72 ,
( T_6 ) V_68 -> V_187 . V_89 ,
( T_6 ) V_68 -> V_187 . V_91 ) ;
F_67 ( & V_57 ) ;
break;
case V_239 :
F_40 ( L_73 ,
( T_6 ) V_68 -> V_240 . V_89 ,
( T_6 ) V_68 -> V_240 . V_91 ) ;
if ( V_57 . V_72 . V_73 . V_74 )
F_39 ( & V_57 . V_72 , V_62 ) ;
break;
case V_241 :
F_40 ( L_74 ) ;
F_78 ( & V_57 . V_72 ) ;
break;
case V_242 :
F_40 ( L_75 ) ;
F_79 ( & V_57 . V_72 ) ;
break;
case V_243 :
F_40 ( L_76 ) ;
F_80 ( & V_57 . V_72 ) ;
break;
default:
F_36 ( L_77 , ( int ) V_57 . V_72 . V_85 ) ;
if ( V_57 . V_72 . V_73 . V_74 )
F_39 ( & V_57 . V_72 ,
- V_244 ) ;
break;
}
if ( V_166 != NULL ) {
F_103 ( V_166 ) ;
V_166 = NULL ;
}
return TRUE ;
}
static T_8 F_104 ( void )
{
T_9 V_245 = 0 ;
T_4 V_246 = 0 ;
if ( ! F_105 ( F_106 ( & V_245 , & V_246 ) ) ) {
F_107 ( L_78 ,
V_94 ) ;
return 0 ;
}
F_108 ( L_79 , V_245 ) ;
return V_245 ;
}
static void
F_109 ( struct V_247 * V_248 )
{
struct V_56 V_57 ;
BOOL V_249 = FALSE ;
BOOL V_250 = FALSE ;
static T_9 V_251 ;
if ( V_252 && ! V_46 )
goto V_66;
if ( V_253 && ! V_50 )
goto V_66;
V_251 ++ ;
if ( V_251 >= 250 )
;
else
goto V_66;
if ( V_205
&& ( V_206 . V_85 != V_119 ) ) {
if ( F_24 () == 1 ) {
F_40 ( L_80 ) ;
F_39 ( & V_206 , 0 ) ;
F_25 () ;
memset ( & V_206 , 0 ,
sizeof( struct V_76 ) ) ;
}
}
while ( F_82 ( V_8 ,
V_254 ,
& V_57 ) ) {
if ( V_57 . V_72 . V_81 != 0 ) {
F_36 ( L_81 ,
( T_6 ) V_57 . V_72 . V_81 ,
( T_6 ) V_57 . V_72 . V_80 ,
V_57 . V_72 . V_85 ) ;
}
}
if ( ! V_249 ) {
if ( V_255 ) {
V_57 = V_256 ;
V_255 = FALSE ;
V_249 = TRUE ;
} else
V_249 = F_81 ( & V_57 ) ;
}
V_250 = FALSE ;
while ( V_249 && ( ! V_250 ) ) {
V_257 = V_208 ;
if ( F_100 ( V_57 ,
F_73
( V_8 ) ) )
V_249 = F_81 ( & V_57 ) ;
else {
V_250 = TRUE ;
V_256 = V_57 ;
V_255 = TRUE ;
}
}
F_91 () ;
V_66:
if ( F_110 ( V_208 ,
V_257 + ( V_210 * V_258 ) ) ) {
if ( V_259 != V_260 ) {
F_40 ( L_82 ) ;
V_259 = V_260 ;
}
} else {
if ( V_259 != V_261 ) {
V_259 = V_261 ;
F_40 ( L_83 ) ;
}
}
F_111 ( V_262 ,
& V_263 , V_259 ) ;
}
static void
F_112 ( struct V_247 * V_248 )
{
struct V_56 V_264 ;
struct V_56 V_265 ;
struct V_56 V_75 ;
T_4 V_99 ;
T_5 V_100 ;
if ( V_252 && ! V_46 )
goto V_66;
if ( V_253 && ! V_50 )
goto V_66;
F_35 ( V_266 , V_64 ) ;
V_75 . V_72 . V_85 = V_235 ;
V_75 . V_68 . V_69 . V_236 = 23 ;
V_75 . V_68 . V_69 . V_237 = 0 ;
F_34 ( & V_75 ) ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_101 ) ,
& V_100 , sizeof( T_5 ) ) < 0 ) {
F_36 ( L_11 ) ;
F_35 ( V_102 ,
V_103 ) ;
return;
}
if ( V_100 != V_104 ) {
F_36 ( L_12 ,
V_100 ) ;
F_44 ( V_105 ,
V_100 ,
V_103 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_106 ) ,
& V_99 , sizeof( T_4 ) ) < 0 ) {
F_36 ( L_13 ) ;
F_35 ( V_102 ,
V_103 ) ;
return;
}
if ( F_3 ( V_8 ,
V_99 ,
& V_264 ,
sizeof( struct V_56 ) ) < 0 ) {
F_36 ( L_84 ) ;
F_35 ( V_267 ,
V_103 ) ;
return;
}
if ( F_3 ( V_8 ,
V_99 +
sizeof( struct V_56 ) ,
& V_265 ,
sizeof( struct V_56 ) ) < 0 ) {
F_36 ( L_85 ) ;
F_35 ( V_268 ,
V_103 ) ;
return;
}
if ( V_264 . V_68 . V_146 . V_156 != 0 )
V_127 ( & V_264 ) ;
else {
F_36 ( L_86 ) ;
F_35 ( V_269 ,
V_103 ) ;
return;
}
if ( V_265 . V_68 . V_178 . V_156 != 0 )
F_62 ( & V_265 ) ;
else {
F_36 ( L_87 ) ;
F_35 ( V_270 ,
V_103 ) ;
return;
}
F_40 ( L_88 ) ;
F_35 ( V_271 , V_64 ) ;
return;
V_66:
V_259 = V_260 ;
F_111 ( V_262 ,
& V_263 , V_259 ) ;
}
static void
F_113 ( T_6 V_112 , int V_78 )
{
F_45 ( V_115 , V_112 , V_78 ) ;
}
static void
F_114 ( T_6 V_112 , int V_78 )
{
F_45 ( V_117 , V_112 , V_78 ) ;
}
static void
F_115 ( T_6 V_112 , T_6 V_120 , int V_78 )
{
F_50 ( V_122 , V_112 , V_120 , V_78 ) ;
}
static void
F_116 ( T_6 V_112 , T_6 V_120 , int V_78 )
{
F_50 ( V_123 , V_112 , V_120 , V_78 ) ;
}
void
F_117 ( T_6 V_89 , T_6 V_91 , int V_78 )
{
F_48 ( V_86 ,
V_89 , V_91 , V_78 ,
V_138 ) ;
}
static void
F_118 ( T_6 V_112 , T_6 V_120 , int V_78 )
{
F_48 ( V_86 ,
V_112 , V_120 , V_78 ,
V_135 ) ;
}
BOOL
F_119 ( T_6 V_89 , struct V_26 * V_272 )
{
void * V_27 = F_46 ( & V_114 , V_89 ) ;
if ( ! V_27 ) {
F_36 ( L_89 , V_89 ) ;
return FALSE ;
}
memcpy ( V_272 , V_27 , sizeof( struct V_26 ) ) ;
return TRUE ;
}
BOOL
F_120 ( T_6 V_89 , void * V_273 )
{
struct V_26 * V_27 = F_46 ( & V_114 , V_89 ) ;
if ( ! V_27 ) {
F_36 ( L_89 , V_89 ) ;
return FALSE ;
}
V_27 -> V_274 = V_273 ;
return TRUE ;
}
BOOL
F_121 ( T_6 V_89 , T_6 V_91 ,
struct V_33 * V_275 )
{
void * V_27 = F_49 ( & V_116 , V_89 , V_91 ) ;
if ( ! V_27 ) {
F_36 ( L_90 , V_89 , V_91 ) ;
return FALSE ;
}
memcpy ( V_275 , V_27 , sizeof( struct V_33 ) ) ;
return TRUE ;
}
BOOL
F_122 ( T_6 V_89 , T_6 V_91 , void * V_273 )
{
struct V_33 * V_27 =
F_49 ( & V_116 , V_89 , V_91 ) ;
if ( ! V_27 ) {
F_36 ( L_90 , V_89 , V_91 ) ;
return FALSE ;
}
V_27 -> V_274 = V_273 ;
return TRUE ;
}
void *
F_123 ( struct V_276 * V_277 , BOOL V_278 ,
char * V_279 , int V_280 )
{
T_13 V_281 ;
void * V_27 ;
if ( V_278 )
V_281 = V_148 ;
else
V_281 = V_282 ;
V_281 |= V_213 ;
V_27 = F_124 ( V_277 , V_281 ) ;
if ( ! V_27 ) {
F_36 ( L_91 , V_279 , V_280 ) ;
return NULL ;
}
F_125 ( & V_283 ) ;
return V_27 ;
}
void
F_126 ( struct V_276 * V_277 , void * V_27 , char * V_279 , int V_280 )
{
if ( ! V_27 ) {
F_36 ( L_92 , V_279 , V_280 ) ;
return;
}
F_127 ( & V_283 ) ;
F_128 ( V_277 , V_27 ) ;
}
static T_1 F_129 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
char V_284 [ 64 ] ;
if ( sscanf ( V_6 , L_93 , V_284 ) != 1 )
return - V_14 ;
if ( strcmp ( V_284 , L_94 ) == 0 ) {
V_37 [ 0 ] = 1 ;
return V_12 ;
} else if ( strcmp ( V_284 , L_95 ) == 0 ) {
V_37 [ 1 ] = 1 ;
return V_12 ;
}
return - V_14 ;
}
static T_1 F_130 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
V_170 V_85 ;
if ( F_131 ( V_6 , 10 , & V_85 ) != 0 )
return - V_14 ;
F_97 ( V_85 , 0 ) ;
return V_12 ;
}
static T_1 F_132 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
V_170 V_85 ;
if ( F_131 ( V_6 , 10 , & V_85 ) != 0 )
return - V_14 ;
F_97 ( V_85 , 1 ) ;
return V_12 ;
}
static int T_14
F_133 ( void )
{
int V_61 = 0 , V_285 = 0 ;
char V_1 [ 64 ] ;
T_8 V_245 ;
if ( ! V_286 )
return - V_287 ;
F_40 ( L_96 , V_48 ) ;
F_35 ( V_288 , V_64 ) ;
F_40 ( L_97 , V_289 ) ;
F_40 ( L_98 , V_290 ) ;
F_40 ( L_99 , V_291 ) ;
F_40 ( L_100 , V_292 ) ;
F_40 ( L_101 , V_293 ) ;
F_40 ( L_102 , V_252 ) ;
F_40 ( L_103 , V_253 ) ;
F_40 ( L_104 , V_205 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
F_134 ( & V_294 . V_295 , 0 ) ;
if ( V_289 ) {
F_107 ( L_105 ,
V_285 ) ;
F_44 ( V_296 , V_285 , V_297 ) ;
V_61 = V_285 ;
goto V_66;
}
V_245 = F_104 () ;
if ( V_245 != 0 ) {
V_8 =
F_135
( V_245 ,
sizeof( struct V_9 ) ,
V_298 ) ;
if ( F_136 (
F_137 ( V_8 ) ) ) {
F_40 ( L_106 ,
F_138 ( V_8 , V_1 ) ) ;
F_72 () ;
} else {
F_36 ( L_107 ) ;
F_139 ( V_8 ) ;
V_8 = NULL ;
return - V_287 ;
}
} else {
F_36 ( L_108 ) ;
return - V_287 ;
}
V_299 = F_140 ( V_293 , 0 ) ;
V_61 = F_141 ( V_299 , & V_8 ) ;
if ( V_61 < 0 ) {
F_107 ( L_109 , V_61 ) ;
F_35 ( V_296 , V_297 ) ;
goto V_66;
}
memset ( & V_238 , 0 , sizeof( struct V_76 ) ) ;
memset ( & V_206 , 0 , sizeof( struct V_76 ) ) ;
memset ( & V_300 , 0 , sizeof( struct V_76 ) ) ;
V_301 =
F_142 ( V_302 ,
sizeof( struct V_303 ) ,
0 , V_304 , NULL ) ;
if ( ! V_301 ) {
F_107 ( L_110 ) ;
F_35 ( V_296 , V_297 ) ;
V_61 = - 1 ;
goto V_66;
}
if ( V_305 ) {
F_40 ( L_111 ) ;
} else {
if ( V_306 )
F_143 ( & V_263 ,
F_112 ) ;
else
F_143 ( & V_263 ,
F_109 ) ;
V_262 =
F_144 ( L_112 ) ;
if ( V_262 == NULL ) {
F_107 ( L_113 ,
- V_307 ) ;
F_35 ( V_308 ,
V_297 ) ;
V_61 = - V_307 ;
goto V_66;
}
V_257 = V_208 ;
V_259 = V_261 ;
V_61 = F_111 ( V_262 ,
& V_263 , V_259 ) ;
if ( V_61 < 0 ) {
F_107 ( L_114 , V_61 ) ;
F_35 ( V_309 ,
V_297 ) ;
goto V_66;
}
}
V_141 . V_3 . V_310 = V_299 ;
if ( F_145 ( & V_141 ) < 0 ) {
F_107 ( L_115 ) ;
F_35 ( V_311 , V_297 ) ;
V_61 = - 1 ;
goto V_66;
}
F_40 ( L_116 ) ;
F_35 ( V_312 , V_64 ) ;
V_61 = 0 ;
V_66:
if ( V_61 ) {
F_36 ( L_117 ) ;
F_44 ( V_296 , V_61 ,
V_103 ) ;
}
return V_61 ;
}
static void
F_146 ( void )
{
char V_1 [ 99 ] ;
F_35 ( V_313 , V_64 ) ;
if ( V_305 ) {
;
} else {
F_147 ( & V_263 ) ;
F_148 ( V_262 ) ;
F_149 ( V_262 ) ;
V_262 = NULL ;
F_71 ( & V_201 ) ;
}
V_314 = NULL ;
if ( V_301 ) {
F_150 ( V_301 ) ;
V_301 = NULL ;
}
F_31 () ;
memset ( & V_238 , 0 , sizeof( struct V_76 ) ) ;
memset ( & V_206 , 0 , sizeof( struct V_76 ) ) ;
memset ( & V_300 , 0 , sizeof( struct V_76 ) ) ;
F_40 ( L_118 ,
F_138 ( V_8 , V_1 ) ) ;
F_139 ( V_8 ) ;
F_151 () ;
F_35 ( V_313 , V_64 ) ;
F_40 ( L_119 ) ;
}
