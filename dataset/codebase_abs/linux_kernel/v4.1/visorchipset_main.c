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
V_7 ) , & V_7 , sizeof( T_2 ) ) ;
return F_5 ( V_6 , V_10 , L_2 , V_7 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_2 V_7 ;
int V_12 ;
if ( F_7 ( V_6 , 10 , & V_7 ) != 0 )
return - V_13 ;
V_12 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_7 ) ,
& V_7 , sizeof( T_2 ) ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
struct V_14 V_14 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_15 ) , & V_14 ,
sizeof( struct V_14 ) ) ;
return F_5 ( V_6 , V_10 , L_2 ,
V_14 . V_16 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
int V_17 , V_12 ;
struct V_14 V_14 ;
if ( F_11 ( V_6 , 10 , & V_17 ) != 0 )
return - V_13 ;
V_14 . V_16 = V_17 ;
V_12 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_15 ) , & ( V_14 ) ,
sizeof( struct V_14 ) ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_4 error ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_18 ) ,
& error , sizeof( T_4 ) ) ;
return F_5 ( V_6 , V_10 , L_3 , error ) ;
}
static T_1 F_13 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_4 error ;
int V_12 ;
if ( F_14 ( V_6 , 10 , & error ) != 0 )
return - V_13 ;
V_12 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_18 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_4 V_19 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_20 ) ,
& V_19 , sizeof( T_4 ) ) ;
return F_5 ( V_6 , V_10 , L_3 , V_19 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_4 V_19 ;
int V_12 ;
if ( F_14 ( V_6 , 10 , & V_19 ) != 0 )
return - V_13 ;
V_12 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_20 ) ,
& V_19 , sizeof( T_4 ) ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 )
{
T_5 V_21 ;
F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_22 ) ,
& V_21 , sizeof( T_5 ) ) ;
return F_5 ( V_6 , V_10 , L_4 , V_21 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_5 V_21 ;
int V_12 ;
if ( F_19 ( V_6 , 10 , & V_21 ) != 0 )
return - V_13 ;
V_12 = F_8 ( V_8 ,
F_4 ( struct V_9 ,
V_22 ) ,
& V_21 , sizeof( T_5 ) ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static void
F_20 ( void * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) ( V_23 ) ;
F_21 ( V_25 -> V_26 ) ;
V_25 -> V_26 = NULL ;
F_21 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
V_25 -> V_28 . V_29 = 0 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
}
static void
F_22 ( void * V_23 )
{
struct V_30 * V_25 =
(struct V_30 * ) ( V_23 ) ;
V_25 -> V_28 . V_29 = 0 ;
memset ( V_25 , 0 , sizeof( struct V_30 ) ) ;
}
static T_2
F_23 ( void )
{
int V_31 ;
T_2 V_32 = 1 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
V_32 &= V_34 [ V_31 ] ;
return V_32 ;
}
static void
F_24 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
V_34 [ V_31 ] = 0 ;
}
void
F_25 (
struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_26 ( & V_41 ) ;
if ( ! V_36 ) {
memset ( & V_42 , 0 ,
sizeof( V_42 ) ) ;
V_43 = 0 ;
} else {
V_42 = * V_36 ;
V_43 = 1 ;
}
if ( V_38 )
* V_38 = V_44 ;
if ( V_40 )
F_27 ( V_40 , L_5 , L_6 ,
V_45 , NULL ) ;
F_28 ( & V_41 ) ;
}
void
F_29 (
struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_26 ( & V_41 ) ;
if ( ! V_36 ) {
memset ( & V_46 , 0 ,
sizeof( V_46 ) ) ;
V_47 = 0 ;
} else {
V_46 = * V_36 ;
V_47 = 1 ;
}
if ( V_38 )
* V_38 = V_44 ;
if ( V_40 )
F_27 ( V_40 , L_7 ,
L_6 , V_45 , NULL ) ;
F_28 ( & V_41 ) ;
}
static void
F_30 ( void )
{
struct V_24 * V_48 , * V_49 ;
struct V_30 * V_50 , * V_51 ;
F_31 (bi, tmp_bi, &bus_info_list, entry) {
F_20 ( V_48 ) ;
F_32 ( & V_48 -> V_52 ) ;
F_21 ( V_48 ) ;
}
F_31 (di, tmp_di, &dev_info_list, entry) {
F_22 ( V_50 ) ;
F_32 ( & V_50 -> V_52 ) ;
F_21 ( V_50 ) ;
}
}
static void
F_33 ( struct V_53 * V_54 )
{
static int V_55 ;
enum V_56 V_57 = 0 ;
int V_58 = V_59 ;
F_34 ( V_60 , V_61 ) ;
if ( V_55 ) {
V_58 = - V_62 ;
goto V_63;
}
V_55 = 1 ;
F_34 ( V_64 , V_61 ) ;
V_57 =
V_54 -> V_65 . V_66 .
V_57 & V_67 ;
V_57 |= V_68 ;
V_63:
if ( V_58 < 0 )
F_30 () ;
if ( V_54 -> V_69 . V_70 . V_71 )
F_35 ( & V_54 -> V_69 , V_58 , V_57 ) ;
}
static void
F_36 ( struct V_53 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
memset ( V_72 , 0 , sizeof( struct V_53 ) ) ;
memcpy ( & V_72 -> V_69 , V_74 , sizeof( struct V_73 ) ) ;
V_72 -> V_69 . V_76 = 0 ;
V_72 -> V_69 . V_77 = 0 ;
V_72 -> V_69 . V_78 = 0 ;
if ( V_75 < 0 ) {
V_72 -> V_69 . V_70 . V_79 = 1 ;
V_72 -> V_69 . V_80 = ( T_4 ) ( - V_75 ) ;
}
}
static void
F_37 ( struct V_73 * V_74 , int V_75 )
{
struct V_53 V_81 ;
F_36 ( & V_81 , V_74 , V_75 ) ;
if ( V_74 -> V_82 == V_83 &&
V_84 . V_85 . V_86 ==
V_87 &&
V_84 . V_85 . V_88 ==
V_89 )
V_81 . V_65 = V_84 ;
if ( V_81 . V_69 . V_70 . V_90 == 1 )
return;
if ( ! F_38 ( V_8 ,
V_91 , & V_81 ) ) {
return;
}
}
static void
F_35 ( struct V_73 * V_74 ,
int V_75 ,
enum V_56 V_57 )
{
struct V_53 V_81 ;
F_36 ( & V_81 , V_74 , V_75 ) ;
V_81 . V_65 . V_66 . V_57 = V_57 ;
if ( ! F_38 ( V_8 ,
V_91 , & V_81 ) ) {
return;
}
}
static void F_39 (
struct V_73 * V_74 , int V_75 ,
struct V_92 V_28 )
{
struct V_53 V_81 ;
F_36 ( & V_81 , V_74 , V_75 ) ;
V_81 . V_65 . V_85 . V_28 = V_28 ;
V_81 . V_65 . V_85 . V_70 . V_93 = 1 ;
if ( ! F_38 ( V_8 ,
V_91 , & V_81 ) ) {
return;
}
}
void
F_40 ( struct V_53 * V_72 ,
enum V_94 type )
{
T_4 V_95 ;
T_5 V_96 ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_97 ) ,
& V_96 , sizeof( T_5 ) ) < 0 ) {
F_34 ( V_98 ,
V_99 ) ;
return;
}
if ( V_96 != V_100 ) {
F_41 ( V_101 ,
V_96 ,
V_99 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_102 ) ,
& V_95 , sizeof( T_4 ) ) < 0 ) {
F_34 ( V_98 ,
V_99 ) ;
return;
}
if ( type == V_103 ) {
if ( F_8 ( V_8 ,
V_95 ,
V_72 ,
sizeof( struct V_53 ) ) < 0 ) {
F_34 ( V_104 ,
V_99 ) ;
return;
}
} else {
if ( F_8 ( V_8 ,
V_95 +
sizeof( struct V_53 ) , V_72 ,
sizeof( struct V_53 ) ) < 0 ) {
F_34 ( V_105 ,
V_99 ) ;
return;
}
}
}
static void
F_42 ( enum V_106 V_107 , T_6 V_86 , int V_75 )
{
struct V_24 * V_25 = NULL ;
BOOL V_108 = FALSE ;
V_25 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_25 )
return;
if ( V_75 < 0 ) {
if ( ( V_107 == V_110 ) &&
( V_75 != ( - V_62 ) ) )
F_44 ( & V_111 , V_86 ) ;
} else {
if ( V_107 == V_110 )
V_25 -> V_28 . V_29 = 1 ;
if ( V_107 == V_112 )
V_108 = TRUE ;
}
if ( V_25 -> V_113 . V_82 == V_114 )
return;
if ( V_25 -> V_113 . V_82 != ( T_4 ) V_107 )
return;
F_37 ( & V_25 -> V_113 , V_75 ) ;
V_25 -> V_113 . V_82 = V_114 ;
if ( V_108 ) {
F_20 ( V_25 ) ;
F_44 ( & V_111 , V_86 ) ;
}
}
static void
F_45 ( enum V_106 V_107 ,
T_6 V_86 , T_6 V_88 , int V_75 ,
struct V_92 V_115 )
{
struct V_30 * V_25 = NULL ;
struct V_53 V_81 ;
V_25 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_25 )
return;
if ( V_25 -> V_113 . V_82 == V_114 )
return;
if ( V_25 -> V_113 . V_82 != V_107 )
return;
F_36 ( & V_81 , & V_25 -> V_113 , V_75 ) ;
V_81 . V_65 . V_85 . V_86 = V_86 ;
V_81 . V_65 . V_85 . V_88 = V_88 ;
V_81 . V_65 . V_85 . V_28 = V_115 ;
if ( ! F_38 ( V_8 ,
V_91 , & V_81 ) )
return;
V_25 -> V_113 . V_82 = V_114 ;
}
static void
F_47 ( enum V_106 V_107 , T_6 V_86 , T_6 V_88 ,
int V_75 )
{
struct V_30 * V_25 = NULL ;
BOOL V_108 = FALSE ;
V_25 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_25 )
return;
if ( V_75 >= 0 ) {
if ( V_107 == V_116 )
V_25 -> V_28 . V_29 = 1 ;
if ( V_107 == V_117 )
V_108 = TRUE ;
}
if ( V_25 -> V_113 . V_82 == V_114 )
return;
if ( V_25 -> V_113 . V_82 != ( T_4 ) V_107 )
return;
F_37 ( & V_25 -> V_113 , V_75 ) ;
V_25 -> V_113 . V_82 = V_114 ;
if ( V_108 )
F_22 ( V_25 ) ;
}
static void
F_48 ( T_4 V_86 ,
T_4 V_65 , struct V_73 * V_74 ,
int V_75 , BOOL V_118 )
{
BOOL V_119 = FALSE ;
struct V_24 * V_120 = F_43 ( & V_109 ,
V_86 ) ;
if ( ! V_120 )
return;
if ( V_118 ) {
memcpy ( & V_120 -> V_113 , V_74 ,
sizeof( struct V_73 ) ) ;
} else {
V_120 -> V_113 . V_82 = V_114 ;
}
F_26 ( & V_41 ) ;
if ( V_75 == V_59 ) {
switch ( V_65 ) {
case V_110 :
if ( V_42 . V_121 ) {
(* V_42 . V_121 ) ( V_86 ) ;
V_119 = TRUE ;
}
if ( ( ! V_120 -> V_70 . V_122 ) &&
V_46 . V_121 ) {
(* V_46 . V_121 ) ( V_86 ) ;
V_119 = TRUE ;
}
break;
case V_112 :
if ( V_42 . V_123 ) {
(* V_42 . V_123 ) ( V_86 ) ;
V_119 = TRUE ;
}
if ( ( ! V_120 -> V_70 . V_122 ) &&
V_46 . V_123 ) {
(* V_46 . V_123 ) ( V_86 ) ;
V_119 = TRUE ;
}
break;
}
}
if ( V_119 )
;
else
F_42 ( V_65 , V_86 , V_75 ) ;
F_28 ( & V_41 ) ;
}
static void
F_49 ( T_4 V_86 , T_4 V_88 , struct V_92 V_28 , T_4 V_65 ,
struct V_73 * V_74 , int V_75 ,
BOOL V_118 , BOOL V_124 )
{
struct V_35 * V_36 = NULL ;
BOOL V_119 = FALSE ;
struct V_30 * V_125 =
F_46 ( & V_111 , V_86 , V_88 ) ;
char * V_126 [] = {
L_8 ,
NULL
} ;
if ( ! V_125 )
return;
if ( V_124 )
V_36 = & V_42 ;
else
V_36 = & V_46 ;
if ( V_118 ) {
memcpy ( & V_125 -> V_113 , V_74 ,
sizeof( struct V_73 ) ) ;
} else {
V_125 -> V_113 . V_82 = V_114 ;
}
F_26 ( & V_41 ) ;
if ( V_75 >= 0 ) {
switch ( V_65 ) {
case V_116 :
if ( V_36 -> V_127 ) {
(* V_36 -> V_127 ) ( V_86 , V_88 ) ;
V_119 = TRUE ;
}
break;
case V_83 :
if ( V_28 . V_128 == V_129 . V_128 &&
V_28 . V_130 ==
V_129 . V_130 ) {
if ( V_36 -> V_131 ) {
(* V_36 -> V_131 ) ( V_86 ,
V_88 ) ;
V_119 = TRUE ;
}
}
else if ( V_28 . V_128 == V_132 . V_128 &&
V_28 . V_130 ==
V_132 . V_130 ) {
if ( V_36 -> V_133 ) {
(* V_36 -> V_133 ) ( V_86 ,
V_88 ) ;
V_119 = TRUE ;
}
} else if ( V_28 . V_128 == V_134 . V_128 &&
V_28 . V_130 ==
V_134 . V_130 ) {
if ( V_86 == V_87 &&
V_88 == V_89 ) {
F_50
( & V_135 . V_3 .
V_136 , V_137 , V_126 ) ;
}
}
break;
case V_117 :
if ( V_36 -> V_138 ) {
(* V_36 -> V_138 ) ( V_86 , V_88 ) ;
V_119 = TRUE ;
}
break;
}
}
if ( V_119 )
;
else
F_47 ( V_65 , V_86 , V_88 , V_75 ) ;
F_28 ( & V_41 ) ;
}
static void
V_121 ( struct V_53 * V_54 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_140 . V_86 ;
int V_58 = V_59 ;
struct V_24 * V_120 = NULL ;
V_120 = F_43 ( & V_109 , V_86 ) ;
if ( V_120 && ( V_120 -> V_28 . V_29 == 1 ) ) {
F_41 ( V_141 , V_86 ,
V_99 ) ;
V_58 = - V_62 ;
goto V_63;
}
V_120 = F_51 ( sizeof( * V_120 ) , V_142 ) ;
if ( ! V_120 ) {
F_41 ( V_141 , V_86 ,
V_99 ) ;
V_58 = - V_143 ;
goto V_63;
}
F_52 ( & V_120 -> V_52 ) ;
V_120 -> V_86 = V_86 ;
V_120 -> V_88 = V_65 -> V_140 . V_144 ;
F_41 ( V_145 , V_86 , V_61 ) ;
if ( V_54 -> V_69 . V_70 . V_90 == 1 )
V_120 -> V_146 . V_147 = V_148 ;
else
V_120 -> V_146 . V_147 = V_149 ;
V_120 -> V_70 . V_122 = V_54 -> V_69 . V_70 . V_122 ;
V_120 -> V_146 . V_150 = V_65 -> V_140 . V_150 ;
V_120 -> V_146 . V_151 = V_65 -> V_140 . V_152 ;
V_120 -> V_146 . V_153 =
V_65 -> V_140 . V_154 ;
V_120 -> V_146 . V_155 = V_65 -> V_140 . V_156 ;
F_53 ( & V_120 -> V_52 , & V_109 ) ;
F_41 ( V_157 , V_86 , V_61 ) ;
V_63:
F_48 ( V_86 , V_110 , & V_54 -> V_69 ,
V_58 , V_54 -> V_69 . V_70 . V_71 == 1 ) ;
}
static void
V_123 ( struct V_53 * V_54 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_158 . V_86 ;
struct V_24 * V_120 ;
int V_58 = V_59 ;
V_120 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_120 )
V_58 = - V_159 ;
else if ( V_120 -> V_28 . V_29 == 0 )
V_58 = - V_62 ;
F_48 ( V_86 , V_112 , & V_54 -> V_69 ,
V_58 , V_54 -> V_69 . V_70 . V_71 == 1 ) ;
}
static void
F_54 ( struct V_53 * V_54 ,
struct V_160 * V_161 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_162 . V_86 ;
struct V_24 * V_120 = NULL ;
int V_58 = V_59 ;
char V_1 [ 99 ] ;
V_86 = V_65 -> V_162 . V_86 ;
F_41 ( V_163 , V_86 ,
V_61 ) ;
V_120 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_120 ) {
F_41 ( V_164 , V_86 ,
V_99 ) ;
V_58 = - V_159 ;
} else if ( V_120 -> V_28 . V_29 == 0 ) {
F_41 ( V_164 , V_86 ,
V_99 ) ;
V_58 = - V_159 ;
} else if ( V_120 -> V_113 . V_82 != V_114 ) {
F_41 ( V_164 , V_86 ,
V_99 ) ;
V_58 = - V_165 ;
} else {
V_120 -> V_166 = V_65 -> V_162 . V_167 ;
V_120 -> V_168 = F_55 ( V_161 ) ;
F_56 ( V_161 , V_169 ) ;
V_120 -> V_26 = F_57 ( V_161 ) ;
F_58 ( & V_120 -> V_168 , V_1 ) ;
F_41 ( V_170 , V_86 ,
V_61 ) ;
}
F_48 ( V_86 , V_171 , & V_54 -> V_69 ,
V_58 , V_54 -> V_69 . V_70 . V_71 == 1 ) ;
}
static void
F_59 ( struct V_53 * V_54 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_172 . V_86 ;
T_6 V_88 = V_65 -> V_172 . V_88 ;
struct V_30 * V_125 = NULL ;
struct V_24 * V_120 = NULL ;
int V_58 = V_59 ;
V_125 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( V_125 && ( V_125 -> V_28 . V_29 == 1 ) ) {
F_60 ( V_173 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_62 ;
goto V_63;
}
V_120 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_120 ) {
F_60 ( V_173 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_159 ;
goto V_63;
}
if ( V_120 -> V_28 . V_29 == 0 ) {
F_60 ( V_173 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_159 ;
goto V_63;
}
V_125 = F_51 ( sizeof( * V_125 ) , V_142 ) ;
if ( ! V_125 ) {
F_60 ( V_173 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_143 ;
goto V_63;
}
F_52 ( & V_125 -> V_52 ) ;
V_125 -> V_86 = V_86 ;
V_125 -> V_88 = V_88 ;
V_125 -> V_174 = V_65 -> V_172 . V_174 ;
F_60 ( V_175 , V_88 , V_86 ,
V_61 ) ;
if ( V_54 -> V_69 . V_70 . V_90 == 1 )
V_125 -> V_146 . V_147 = V_148 ;
else
V_125 -> V_146 . V_147 = V_149 ;
V_125 -> V_146 . V_150 = V_65 -> V_172 . V_150 ;
V_125 -> V_146 . V_151 = V_65 -> V_172 . V_152 ;
V_125 -> V_146 . V_153 =
V_65 -> V_172 . V_176 ;
V_125 -> V_146 . V_177 = V_65 -> V_172 . V_177 ;
F_53 ( & V_125 -> V_52 , & V_111 ) ;
F_60 ( V_178 , V_88 , V_86 ,
V_61 ) ;
V_63:
if ( V_125 &&
F_61 ( V_125 -> V_146 . V_153 ) ) {
V_87 = V_86 ;
V_89 = V_88 ;
}
F_49 ( V_86 , V_88 , V_129 ,
V_116 , & V_54 -> V_69 , V_58 ,
V_54 -> V_69 . V_70 . V_71 == 1 ,
F_62 ( V_125 -> V_146 . V_153 ) ) ;
}
static void
F_63 ( struct V_53 * V_54 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_85 . V_86 ;
T_6 V_88 = V_65 -> V_85 . V_88 ;
struct V_92 V_28 = V_65 -> V_85 . V_28 ;
struct V_30 * V_125 = NULL ;
int V_58 = V_59 ;
V_125 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_125 ) {
F_60 ( V_179 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_180 ;
} else if ( V_125 -> V_28 . V_29 == 0 ) {
F_60 ( V_179 , V_88 , V_86 ,
V_99 ) ;
V_58 = - V_180 ;
}
if ( ( V_58 >= V_59 ) && V_125 )
F_49 ( V_86 , V_88 , V_28 ,
V_83 , & V_54 -> V_69 , V_58 ,
V_54 -> V_69 . V_70 . V_71 == 1 ,
F_62 (
V_125 -> V_146 . V_153 ) ) ;
}
static void
F_64 ( struct V_53 * V_54 )
{
struct V_139 * V_65 = & V_54 -> V_65 ;
T_6 V_86 = V_65 -> V_181 . V_86 ;
T_6 V_88 = V_65 -> V_181 . V_88 ;
struct V_30 * V_125 = NULL ;
int V_58 = V_59 ;
V_125 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_125 )
V_58 = - V_180 ;
else if ( V_125 -> V_28 . V_29 == 0 )
V_58 = - V_62 ;
if ( ( V_58 >= V_59 ) && V_125 )
F_49 ( V_86 , V_88 , V_129 ,
V_117 , & V_54 -> V_69 , V_58 ,
V_54 -> V_69 . V_70 . V_71 == 1 ,
F_62 (
V_125 -> V_146 . V_153 ) ) ;
}
static int
F_65 ( T_7 V_182 , T_8 V_183 , T_4 V_184 ,
struct V_185 * V_186 )
{
T_2 T_9 * V_187 = NULL ;
int V_58 = V_59 ;
if ( ! V_186 ) {
V_58 = - V_188 ;
goto V_63;
}
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
if ( ( V_183 == 0 ) || ( V_184 == 0 ) ) {
V_58 = - V_188 ;
goto V_63;
}
V_187 = F_66 ( V_182 + V_183 , V_184 ) ;
if ( ! V_187 ) {
V_58 = - V_189 ;
goto V_63;
}
V_186 -> V_183 = V_183 ;
V_186 -> V_184 = V_184 ;
V_186 -> V_190 = V_187 ;
V_63:
if ( V_58 < 0 ) {
if ( V_187 ) {
F_67 ( V_187 ) ;
V_187 = NULL ;
}
}
return V_58 ;
}
static void
F_68 ( struct V_185 * V_186 )
{
if ( V_186 -> V_190 ) {
F_67 ( V_186 -> V_190 ) ;
V_186 -> V_190 = NULL ;
}
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
}
static void
F_69 ( void )
{
T_7 V_182 = F_70 ( V_8 ) ;
T_8 V_191 = 0 ;
T_4 V_76 = 0 ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_192 ) ,
& V_191 , sizeof( V_191 ) ) < 0 ) {
F_34 ( V_193 ,
V_99 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_194 ) ,
& V_76 , sizeof( V_76 ) ) < 0 ) {
F_34 ( V_193 ,
V_99 ) ;
return;
}
F_65 ( V_182 ,
V_191 , V_76 ,
& V_185 ) ;
}
int
F_71 ( void )
{
F_72 ( & V_135 . V_3 . V_136 , V_137 ) ;
return V_59 ;
}
int
F_73 ( void )
{
char V_195 [ 20 ] ;
char * V_126 [] = { V_195 , NULL } ;
sprintf ( V_195 , L_9 , 1 ) ;
F_50 ( & V_135 . V_3 . V_136 , V_196 ,
V_126 ) ;
return V_59 ;
}
int
F_74 ( void )
{
F_72 ( & V_135 . V_3 . V_136 , V_197 ) ;
return V_59 ;
}
static void
F_75 ( struct V_73 * V_74 )
{
int V_58 = F_71 () ;
if ( V_58 != V_59 )
V_58 = - V_58 ;
if ( V_74 -> V_70 . V_71 && ! V_198 )
F_37 ( V_74 , V_58 ) ;
if ( V_74 -> V_70 . V_71 && V_198 ) {
V_199 = * V_74 ;
}
}
static void
F_76 ( struct V_73 * V_74 )
{
int V_58 = F_73 () ;
if ( V_58 != V_59 )
V_58 = - V_58 ;
if ( V_74 -> V_70 . V_71 )
F_37 ( V_74 , V_58 ) ;
}
static void
F_77 ( struct V_73 * V_74 )
{
int V_58 = F_74 () ;
if ( V_58 != V_59 )
V_58 = - V_58 ;
if ( V_74 -> V_70 . V_71 )
F_37 ( V_74 , V_58 ) ;
}
static BOOL
F_78 ( struct V_53 * V_72 )
{
if ( F_79 ( V_8 ,
V_200 , V_72 ) ) {
if ( V_72 -> V_69 . V_70 . V_90 == 1 )
return FALSE ;
return TRUE ;
}
return FALSE ;
}
static int
F_80 ( void )
{
static T_10 V_82 = F_81 ( 0 ) ;
return F_82 ( & V_82 ) ;
}
static unsigned long
F_83 ( void )
{
return V_201 + F_84 ( V_202 ) ;
}
static struct V_203 *
F_85 ( struct V_53 * V_72 )
{
struct V_203 * V_204 ;
V_204 = F_86 ( sizeof( * V_204 ) , V_142 | V_205 ) ;
if ( ! V_204 )
return NULL ;
V_204 -> V_82 = F_80 () ;
V_204 -> V_206 = F_83 () ;
V_204 -> V_72 = * V_72 ;
return V_204 ;
}
static void
F_87 ( struct V_203 * V_204 )
{
F_21 ( V_204 ) ;
}
static void
F_88 ( struct V_203 * V_204 )
{
struct V_139 * V_65 = & V_204 -> V_72 . V_65 ;
char V_207 [ 40 ] , V_208 [ 40 ] , V_209 [ 40 ] , V_210 [ 40 ] , V_211 [ 40 ] ,
V_212 [ 40 ] ;
char * V_126 [] = {
V_207 , V_208 , V_209 , V_210 , V_211 , V_212 , NULL
} ;
sprintf ( V_207 , L_10 ) ;
sprintf ( V_208 , L_11 , V_204 -> V_82 ) ;
sprintf ( V_209 , L_12 ,
V_65 -> V_85 . V_28 . V_213 ) ;
sprintf ( V_210 , L_13 ,
V_65 -> V_85 . V_86 ) ;
sprintf ( V_211 , L_14 ,
V_65 -> V_85 . V_88 >> 3 ) ;
sprintf ( V_212 , L_15 ,
V_65 -> V_85 . V_88 & 0x7 ) ;
F_50 ( & V_135 . V_3 . V_136 , V_196 ,
V_126 ) ;
}
static void
F_89 ( void )
{
struct V_214 * V_215 = NULL ;
struct V_214 * V_216 = NULL ;
F_90 ( & V_217 ) ;
F_91 (pos, tmp, &parahotplug_request_list) {
struct V_203 * V_204 =
F_92 ( V_215 , struct V_203 , V_218 ) ;
if ( ! F_93 ( V_201 , V_204 -> V_206 ) )
continue;
F_32 ( V_215 ) ;
if ( V_204 -> V_72 . V_69 . V_70 . V_71 )
F_39 (
& V_204 -> V_72 . V_69 ,
V_219 ,
V_204 -> V_72 . V_65 . V_85 . V_28 ) ;
F_87 ( V_204 ) ;
}
F_94 ( & V_217 ) ;
}
static int
F_95 ( int V_82 , T_5 V_213 )
{
struct V_214 * V_215 = NULL ;
struct V_214 * V_216 = NULL ;
F_90 ( & V_217 ) ;
F_91 (pos, tmp, &parahotplug_request_list) {
struct V_203 * V_204 =
F_92 ( V_215 , struct V_203 , V_218 ) ;
if ( V_204 -> V_82 == V_82 ) {
F_32 ( V_215 ) ;
F_94 ( & V_217 ) ;
V_204 -> V_72 . V_65 . V_85 . V_28 . V_213 = V_213 ;
if ( V_204 -> V_72 . V_69 . V_70 . V_71 )
F_39 (
& V_204 -> V_72 . V_69 , V_59 ,
V_204 -> V_72 . V_65 . V_85 . V_28 ) ;
F_87 ( V_204 ) ;
return 0 ;
}
}
F_94 ( & V_217 ) ;
return - 1 ;
}
static void
F_96 ( struct V_53 * V_54 )
{
struct V_203 * V_204 ;
V_204 = F_85 ( V_54 ) ;
if ( ! V_204 )
return;
if ( V_54 -> V_65 . V_85 . V_28 . V_213 ) {
F_88 ( V_204 ) ;
F_39 ( & V_54 -> V_69 ,
V_59 ,
V_54 -> V_65 . V_85 . V_28 ) ;
F_87 ( V_204 ) ;
} else {
F_90 ( & V_217 ) ;
F_97 ( & V_204 -> V_218 , & V_220 ) ;
F_94 ( & V_217 ) ;
F_88 ( V_204 ) ;
}
}
static BOOL
F_98 ( struct V_53 V_54 , T_7 V_150 )
{
struct V_139 * V_65 = & V_54 . V_65 ;
T_8 V_221 = 0 ;
T_4 V_222 = 0 ;
struct V_160 * V_161 = NULL ;
bool V_223 = false ;
struct V_53 V_224 ;
V_223 = ( V_54 . V_69 . V_70 . V_90 == 1 ) ;
if ( V_150 == 0 )
return TRUE ;
V_221 = V_150 + V_54 . V_69 . V_77 ;
V_222 = V_54 . V_69 . V_76 ;
if ( V_221 != 0 && V_222 != 0 ) {
BOOL V_225 = FALSE ;
V_161 =
F_99 ( V_221 , V_222 ,
V_223 , & V_225 ) ;
if ( ! V_161 && V_225 )
return FALSE ;
}
if ( ! V_223 ) {
F_36 ( & V_224 , & V_54 . V_69 ,
V_59 ) ;
if ( V_8 )
F_38 ( V_8 ,
V_226 ,
& V_224 ) ;
}
switch ( V_54 . V_69 . V_82 ) {
case V_227 :
F_33 ( & V_54 ) ;
break;
case V_110 :
V_121 ( & V_54 ) ;
break;
case V_112 :
V_123 ( & V_54 ) ;
break;
case V_171 :
F_54 ( & V_54 , V_161 ) ;
break;
case V_116 :
F_59 ( & V_54 ) ;
break;
case V_83 :
if ( V_65 -> V_85 . V_70 . V_93 ) {
F_96 ( & V_54 ) ;
} else {
F_63 ( & V_54 ) ;
V_228 = V_54 . V_69 ;
V_84 = V_54 . V_65 ;
break;
}
break;
case V_117 :
F_64 ( & V_54 ) ;
break;
case V_229 :
if ( V_54 . V_69 . V_70 . V_71 )
F_37 ( & V_54 . V_69 , V_59 ) ;
break;
case V_230 :
F_75 ( & V_54 . V_69 ) ;
break;
case V_231 :
F_76 ( & V_54 . V_69 ) ;
break;
case V_232 :
F_77 ( & V_54 . V_69 ) ;
break;
default:
if ( V_54 . V_69 . V_70 . V_71 )
F_37 ( & V_54 . V_69 ,
- V_233 ) ;
break;
}
if ( V_161 ) {
F_100 ( V_161 ) ;
V_161 = NULL ;
}
return TRUE ;
}
static T_7 F_101 ( void )
{
T_8 V_234 = 0 ;
T_4 V_235 = 0 ;
if ( ! F_102 ( F_103 ( & V_234 , & V_235 ) ) )
return 0 ;
return V_234 ;
}
static void
F_104 ( struct V_236 * V_237 )
{
struct V_53 V_54 ;
BOOL V_238 = FALSE ;
BOOL V_239 = FALSE ;
static T_8 V_240 ;
if ( V_241 && ! V_43 )
goto V_63;
if ( V_242 && ! V_47 )
goto V_63;
V_240 ++ ;
if ( V_240 >= 250 )
;
else
goto V_63;
if ( V_198 &&
( V_199 . V_82 != V_114 ) ) {
if ( F_23 () == 1 ) {
F_37 ( & V_199 , 0 ) ;
F_24 () ;
memset ( & V_199 , 0 ,
sizeof( struct V_73 ) ) ;
}
}
while ( F_79 ( V_8 ,
V_243 ,
& V_54 ) )
;
if ( ! V_238 ) {
if ( V_244 ) {
V_54 = V_245 ;
V_244 = FALSE ;
V_238 = true ;
} else {
V_238 = F_78 ( & V_54 ) ;
}
}
V_239 = FALSE ;
while ( V_238 && ( ! V_239 ) ) {
V_246 = V_201 ;
if ( F_98 ( V_54 ,
F_70
( V_8 ) ) )
V_238 = F_78 ( & V_54 ) ;
else {
V_239 = TRUE ;
V_245 = V_54 ;
V_244 = TRUE ;
}
}
F_89 () ;
V_63:
if ( F_105 ( V_201 ,
V_246 + ( V_247 * V_248 ) ) ) {
if ( V_249 != V_250 )
V_249 = V_250 ;
} else {
if ( V_249 != V_251 )
V_249 = V_251 ;
}
F_106 ( V_252 ,
& V_253 , V_249 ) ;
}
static void
F_107 ( struct V_236 * V_237 )
{
struct V_53 V_254 ;
struct V_53 V_255 ;
struct V_53 V_72 ;
T_4 V_256 ;
T_5 V_257 ;
if ( V_241 && ! V_43 )
goto V_63;
if ( V_242 && ! V_47 )
goto V_63;
F_34 ( V_258 , V_61 ) ;
V_72 . V_69 . V_82 = V_227 ;
V_72 . V_65 . V_66 . V_259 = 23 ;
V_72 . V_65 . V_66 . V_260 = 0 ;
F_33 ( & V_72 ) ;
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_97 ) ,
& V_257 , sizeof( T_5 ) ) < 0 ) {
F_34 ( V_98 ,
V_99 ) ;
return;
}
if ( V_257 != V_100 ) {
F_41 ( V_101 ,
V_257 ,
V_99 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( struct V_9 ,
V_102 ) ,
& V_256 , sizeof( T_4 ) ) < 0 ) {
F_34 ( V_98 ,
V_99 ) ;
return;
}
if ( F_3 ( V_8 ,
V_256 ,
& V_254 ,
sizeof( struct V_53 ) ) < 0 ) {
F_34 ( V_261 ,
V_99 ) ;
return;
}
if ( F_3 ( V_8 ,
V_256 +
sizeof( struct V_53 ) ,
& V_255 ,
sizeof( struct V_53 ) ) < 0 ) {
F_34 ( V_262 ,
V_99 ) ;
return;
}
if ( V_254 . V_65 . V_140 . V_150 != 0 ) {
V_121 ( & V_254 ) ;
} else {
F_34 ( V_263 ,
V_99 ) ;
return;
}
if ( V_255 . V_65 . V_172 . V_150 != 0 ) {
F_59 ( & V_255 ) ;
} else {
F_34 ( V_264 ,
V_99 ) ;
return;
}
F_34 ( V_265 , V_61 ) ;
return;
V_63:
V_249 = V_250 ;
F_106 ( V_252 ,
& V_253 , V_249 ) ;
}
static void
F_108 ( T_6 V_86 , int V_75 )
{
F_42 ( V_110 , V_86 , V_75 ) ;
}
static void
F_109 ( T_6 V_86 , int V_75 )
{
F_42 ( V_112 , V_86 , V_75 ) ;
}
static void
F_110 ( T_6 V_86 , T_6 V_88 , int V_75 )
{
F_47 ( V_116 , V_86 , V_88 , V_75 ) ;
}
static void
F_111 ( T_6 V_86 , T_6 V_88 , int V_75 )
{
F_47 ( V_117 , V_86 , V_88 , V_75 ) ;
}
void
F_112 ( T_6 V_86 , T_6 V_88 , int V_75 )
{
F_45 ( V_83 ,
V_86 , V_88 , V_75 ,
V_132 ) ;
}
static void
F_113 ( T_6 V_86 , T_6 V_88 , int V_75 )
{
F_45 ( V_83 ,
V_86 , V_88 , V_75 ,
V_129 ) ;
}
BOOL
F_114 ( T_6 V_86 , struct V_24 * V_120 )
{
void * V_25 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_25 )
return FALSE ;
memcpy ( V_120 , V_25 , sizeof( struct V_24 ) ) ;
return TRUE ;
}
BOOL
F_115 ( T_6 V_86 , void * V_266 )
{
struct V_24 * V_25 = F_43 ( & V_109 , V_86 ) ;
if ( ! V_25 )
return FALSE ;
V_25 -> V_267 = V_266 ;
return TRUE ;
}
BOOL
F_116 ( T_6 V_86 , T_6 V_88 ,
struct V_30 * V_125 )
{
void * V_25 = F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_25 )
return FALSE ;
memcpy ( V_125 , V_25 , sizeof( struct V_30 ) ) ;
return TRUE ;
}
BOOL
F_117 ( T_6 V_86 , T_6 V_88 , void * V_266 )
{
struct V_30 * V_25 =
F_46 ( & V_111 , V_86 , V_88 ) ;
if ( ! V_25 )
return FALSE ;
V_25 -> V_267 = V_266 ;
return TRUE ;
}
void *
F_118 ( struct V_268 * V_269 , BOOL V_270 ,
char * V_271 , int V_272 )
{
T_11 V_273 ;
void * V_25 ;
if ( V_270 )
V_273 = V_142 ;
else
V_273 = V_274 ;
V_273 |= V_205 ;
V_25 = F_119 ( V_269 , V_273 ) ;
if ( ! V_25 )
return NULL ;
F_120 ( & V_275 ) ;
return V_25 ;
}
void
F_121 ( struct V_268 * V_269 , void * V_25 , char * V_271 , int V_272 )
{
if ( ! V_25 )
return;
F_122 ( & V_275 ) ;
F_123 ( V_269 , V_25 ) ;
}
static T_1 F_124 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
char V_276 [ 64 ] ;
if ( sscanf ( V_6 , L_16 , V_276 ) != 1 )
return - V_13 ;
if ( strcmp ( V_276 , L_17 ) == 0 ) {
V_34 [ 0 ] = 1 ;
return V_11 ;
} else if ( strcmp ( V_276 , L_18 ) == 0 ) {
V_34 [ 1 ] = 1 ;
return V_11 ;
}
return - V_13 ;
}
static T_1 F_125 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_12 V_82 ;
if ( F_126 ( V_6 , 10 , & V_82 ) != 0 )
return - V_13 ;
F_95 ( V_82 , 0 ) ;
return V_11 ;
}
static T_1 F_127 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_11 )
{
T_12 V_82 ;
if ( F_126 ( V_6 , 10 , & V_82 ) != 0 )
return - V_13 ;
F_95 ( V_82 , 1 ) ;
return V_11 ;
}
static int T_13
F_128 ( void )
{
int V_58 = 0 , V_277 = 0 ;
T_7 V_234 ;
if ( ! V_278 )
return - V_279 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
F_129 ( & V_280 . V_281 , 0 ) ;
if ( V_282 ) {
F_41 ( V_283 , V_277 , V_284 ) ;
V_58 = V_277 ;
goto V_63;
}
V_234 = F_101 () ;
if ( V_234 != 0 ) {
V_8 =
F_130
( V_234 ,
sizeof( struct V_9 ) ,
V_285 ) ;
if ( F_131 (
F_132 ( V_8 ) ) ) {
F_69 () ;
} else {
F_133 ( V_8 ) ;
V_8 = NULL ;
return - V_279 ;
}
} else {
return - V_279 ;
}
V_286 = F_134 ( V_287 , 0 ) ;
V_58 = F_135 ( V_286 , & V_8 ) ;
if ( V_58 < 0 ) {
F_34 ( V_283 , V_284 ) ;
goto V_63;
}
memset ( & V_228 , 0 , sizeof( struct V_73 ) ) ;
memset ( & V_199 , 0 , sizeof( struct V_73 ) ) ;
memset ( & V_288 , 0 , sizeof( struct V_73 ) ) ;
V_289 =
F_136 ( V_290 ,
sizeof( struct V_291 ) ,
0 , V_292 , NULL ) ;
if ( ! V_289 ) {
F_34 ( V_283 , V_284 ) ;
V_58 = - 1 ;
goto V_63;
}
if ( ! V_293 ) {
if ( V_294 )
F_137 ( & V_253 ,
F_107 ) ;
else
F_137 ( & V_253 ,
F_104 ) ;
V_252 =
F_138 ( L_19 ) ;
if ( ! V_252 ) {
F_34 ( V_295 ,
V_284 ) ;
V_58 = - V_296 ;
goto V_63;
}
V_246 = V_201 ;
V_249 = V_251 ;
V_58 = F_106 ( V_252 ,
& V_253 , V_249 ) ;
if ( V_58 < 0 ) {
F_34 ( V_297 ,
V_284 ) ;
goto V_63;
}
}
V_135 . V_3 . V_298 = V_286 ;
if ( F_139 ( & V_135 ) < 0 ) {
F_34 ( V_299 , V_284 ) ;
V_58 = - 1 ;
goto V_63;
}
F_34 ( V_300 , V_61 ) ;
V_58 = 0 ;
V_63:
if ( V_58 ) {
F_41 ( V_283 , V_58 ,
V_99 ) ;
}
return V_58 ;
}
static void
F_140 ( void )
{
F_34 ( V_301 , V_61 ) ;
if ( V_293 ) {
;
} else {
F_141 ( & V_253 ) ;
F_142 ( V_252 ) ;
F_143 ( V_252 ) ;
V_252 = NULL ;
F_68 ( & V_185 ) ;
}
if ( V_289 ) {
F_144 ( V_289 ) ;
V_289 = NULL ;
}
F_30 () ;
memset ( & V_228 , 0 , sizeof( struct V_73 ) ) ;
memset ( & V_199 , 0 , sizeof( struct V_73 ) ) ;
memset ( & V_288 , 0 , sizeof( struct V_73 ) ) ;
F_133 ( V_8 ) ;
F_145 ( V_135 . V_3 . V_298 ) ;
F_34 ( V_301 , V_61 ) ;
}
