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
F_4 ( V_9 ,
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
F_4 ( V_9 , V_10 ) ,
& V_7 , sizeof( T_2 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
T_4 V_15 ;
F_3 ( V_8 ,
F_4 ( V_9 ,
V_16 ) , & V_15 ,
sizeof( T_4 ) ) ;
return F_5 ( V_6 , V_11 , L_2 ,
V_15 . V_17 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
int V_18 , V_13 ;
T_4 V_15 ;
if ( F_11 ( V_6 , 10 , & V_18 ) != 0 )
return - V_14 ;
V_15 . V_17 = V_18 ;
V_13 = F_8 ( V_8 ,
F_4 ( V_9 ,
V_16 ) ,
& ( V_15 ) ,
sizeof( T_4 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_5 error ;
F_3 ( V_8 , F_4 (
V_9 , V_19 ) ,
& error , sizeof( T_5 ) ) ;
return F_5 ( V_6 , V_11 , L_3 , error ) ;
}
static T_1 F_13 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
T_5 error ;
int V_13 ;
if ( F_14 ( V_6 , 10 , & error ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( V_9 ,
V_19 ) ,
& error , sizeof( T_5 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
T_5 V_20 ;
F_3 ( V_8 , F_4 (
V_9 , V_21 ) ,
& V_20 , sizeof( T_5 ) ) ;
return F_5 ( V_6 , V_11 , L_3 , V_20 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_3 V_12 )
{
T_5 V_20 ;
int V_13 ;
if ( F_14 ( V_6 , 10 , & V_20 ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( V_9 ,
V_21 ) ,
& V_20 , sizeof( T_5 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 )
{
T_6 V_22 ;
F_3 ( V_8 ,
F_4 ( V_9 ,
V_23 ) ,
& V_22 ,
sizeof( T_6 ) ) ;
return F_5 ( V_6 , V_11 , L_4 , V_22 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
T_6 V_22 ;
int V_13 ;
if ( F_19 ( V_6 , 10 , & V_22 ) != 0 )
return - V_14 ;
V_13 = F_8 ( V_8 ,
F_4 ( V_9 ,
V_23 ) ,
& V_22 , sizeof( T_6 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static void
F_20 ( void * V_24 )
{
T_7 * V_25 = ( T_7 * ) ( V_24 ) ;
if ( V_25 -> V_26 ) {
F_21 ( V_25 -> V_26 ) ;
V_25 -> V_26 = NULL ;
}
F_22 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
F_22 ( V_25 -> V_28 ) ;
V_25 -> V_28 = NULL ;
V_25 -> V_29 . V_30 = 0 ;
memset ( V_25 , 0 , sizeof( T_7 ) ) ;
}
static void
F_23 ( void * V_24 )
{
T_8 * V_25 = ( T_8 * ) ( V_24 ) ;
V_25 -> V_29 . V_30 = 0 ;
memset ( V_25 , 0 , sizeof( T_8 ) ) ;
}
static T_2
F_24 ( void )
{
int V_31 ;
T_2 V_32 = 1 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
V_32 &= V_34 [ V_31 ] ;
return V_32 ;
}
static void
F_25 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
V_34 [ V_31 ] = 0 ;
}
void
F_26 ( T_9 * V_35 ,
T_10 * V_36 ,
T_11 * V_37 )
{
F_27 ( & V_38 ) ;
if ( V_35 == NULL ) {
memset ( & V_39 , 0 ,
sizeof( V_39 ) ) ;
V_40 = 0 ;
} else {
V_39 = * V_35 ;
V_40 = 1 ;
}
if ( V_36 )
* V_36 = V_41 ;
if ( V_37 )
F_28 ( V_37 , L_5 , L_6 ,
V_42 , NULL ) ;
F_29 ( & V_38 ) ;
}
void
F_30 ( T_9 * V_35 ,
T_10 * V_36 ,
T_11 * V_37 )
{
F_27 ( & V_38 ) ;
if ( V_35 == NULL ) {
memset ( & V_43 , 0 ,
sizeof( V_43 ) ) ;
V_44 = 0 ;
} else {
V_43 = * V_35 ;
V_44 = 1 ;
}
if ( V_36 )
* V_36 = V_41 ;
if ( V_37 )
F_28 ( V_37 , L_7 , L_6 ,
V_42 , NULL ) ;
F_29 ( & V_38 ) ;
}
static void
F_31 ( void )
{
T_7 * V_45 , * V_46 ;
T_8 * V_47 , * V_48 ;
F_32 (bi, tmp_bi, &BusInfoList, entry) {
F_20 ( V_45 ) ;
F_33 ( & V_45 -> V_49 ) ;
F_22 ( V_45 ) ;
}
F_32 (di, tmp_di, &DevInfoList, entry) {
F_23 ( V_47 ) ;
F_33 ( & V_47 -> V_49 ) ;
F_22 ( V_47 ) ;
}
}
static void
F_34 ( T_12 * V_50 )
{
static int V_51 ;
T_13 V_52 = 0 ;
int V_53 = V_54 ;
F_35 ( V_55 , V_56 ) ;
if ( V_51 ) {
F_36 ( L_8 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_51 = 1 ;
F_35 ( V_59 , V_56 ) ;
V_52 =
V_50 -> V_60 . V_61 .
V_52 & V_62 ;
V_52 |= V_63 ;
V_58:
if ( V_53 < 0 )
F_31 () ;
if ( V_50 -> V_64 . V_65 . V_66 )
F_37 ( & V_50 -> V_64 , V_53 , V_52 ) ;
}
static void
F_38 ( T_12 * V_67 ,
T_14 * V_68 , int V_69 )
{
memset ( V_67 , 0 , sizeof( T_12 ) ) ;
memcpy ( & V_67 -> V_64 , V_68 , sizeof( T_14 ) ) ;
V_67 -> V_64 . V_70 = 0 ;
V_67 -> V_64 . V_71 = 0 ;
V_67 -> V_64 . V_72 = 0 ;
if ( V_69 < 0 ) {
V_67 -> V_64 . V_65 . V_73 = 1 ;
V_67 -> V_64 . V_74 = ( T_5 ) ( - V_69 ) ;
}
}
static void
F_39 ( T_14 * V_68 , int V_69 )
{
T_12 V_75 ;
F_38 ( & V_75 , V_68 , V_69 ) ;
if ( V_68 -> V_76 == V_77
&& V_78 . V_79 . V_80 ==
V_81
&& V_78 . V_79 . V_82 ==
V_83 )
V_75 . V_60 = V_78 ;
if ( V_75 . V_64 . V_65 . V_84 == 1 ) {
F_40 ( L_9 ,
V_85 , V_75 . V_64 . V_76 , V_69 ) ;
return;
}
if ( ! F_41 ( V_8 ,
V_86 , & V_75 ) ) {
F_36 ( L_10 ) ;
return;
}
}
static void
F_37 ( T_14 * V_68 , int V_69 ,
T_13 V_52 )
{
T_12 V_75 ;
F_38 ( & V_75 , V_68 , V_69 ) ;
V_75 . V_60 . V_61 . V_52 = V_52 ;
if ( ! F_41 ( V_8 ,
V_86 , & V_75 ) ) {
F_36 ( L_10 ) ;
return;
}
}
static void
F_42 ( T_14 * V_68 ,
int V_69 , T_15 V_29 )
{
T_12 V_75 ;
F_38 ( & V_75 , V_68 , V_69 ) ;
V_75 . V_60 . V_79 . V_29 = V_29 ;
V_75 . V_60 . V_79 . V_87 . V_88 = 1 ;
if ( ! F_41 ( V_8 ,
V_86 , & V_75 ) ) {
F_36 ( L_10 ) ;
return;
}
}
void
F_43 ( T_12 * V_67 , T_16 type )
{
T_5 V_89 ;
T_6 V_90 ;
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_91 ) ,
& V_90 , sizeof( T_6 ) ) < 0 ) {
F_36 ( L_11 ) ;
F_35 ( V_92 ,
V_93 ) ;
return;
}
if ( V_90 != V_94 ) {
F_36 ( L_12 ,
V_90 ) ;
F_44 ( V_95 ,
V_90 ,
V_93 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_96 ) ,
& V_89 , sizeof( T_5 ) ) < 0 ) {
F_36 ( L_13 ) ;
F_35 ( V_92 ,
V_93 ) ;
return;
}
if ( type == V_97 ) {
if ( F_8 ( V_8 ,
V_89 ,
V_67 , sizeof( T_12 ) ) < 0 ) {
F_36 ( L_14 ) ;
F_35 ( V_98 ,
V_93 ) ;
return;
}
} else {
if ( F_8 ( V_8 ,
V_89 +
sizeof( T_12 ) , V_67 ,
sizeof( T_12 ) ) < 0 ) {
F_36 ( L_15 ) ;
F_35 ( V_99 ,
V_93 ) ;
return;
}
}
}
static void
F_45 ( T_17 V_100 , T_18 V_80 , int V_69 )
{
T_7 * V_25 = NULL ;
BOOL V_101 = FALSE ;
V_25 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_25 ) {
F_36 ( L_16 , V_80 ) ;
return;
}
if ( V_69 < 0 ) {
if ( ( V_100 == V_103 ) &&
( V_69 != ( - V_57 ) ) )
F_47 ( & V_104 , V_80 ) ;
} else {
if ( V_100 == V_103 )
V_25 -> V_29 . V_30 = 1 ;
if ( V_100 == V_105 )
V_101 = TRUE ;
}
if ( V_25 -> V_106 . V_76 == V_107 ) {
F_36 ( L_17 ) ;
return;
}
if ( V_25 -> V_106 . V_76 != ( T_5 ) V_100 ) {
F_36 ( L_18 , V_100 , V_25 -> V_106 . V_76 ) ;
return;
}
F_39 ( & V_25 -> V_106 , V_69 ) ;
V_25 -> V_106 . V_76 = V_107 ;
if ( V_101 ) {
F_20 ( V_25 ) ;
F_47 ( & V_104 , V_80 ) ;
}
}
static void
F_48 ( T_17 V_100 ,
T_18 V_80 , T_18 V_82 , int V_69 ,
T_15 V_108 )
{
T_8 * V_25 = NULL ;
T_12 V_75 ;
V_25 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_25 ) {
F_36 ( L_19 , V_80 , V_82 ) ;
return;
}
if ( V_25 -> V_106 . V_76 == V_107 ) {
F_36 ( L_20 ) ;
return;
}
if ( V_25 -> V_106 . V_76 != V_100 ) {
F_36 ( L_18 , V_100 , V_25 -> V_106 . V_76 ) ;
return;
}
F_38 ( & V_75 , & V_25 -> V_106 , V_69 ) ;
V_75 . V_60 . V_79 . V_80 = V_80 ;
V_75 . V_60 . V_79 . V_82 = V_82 ;
V_75 . V_60 . V_79 . V_29 = V_108 ;
if ( ! F_41 ( V_8 ,
V_86 , & V_75 ) ) {
F_36 ( L_10 ) ;
return;
}
V_25 -> V_106 . V_76 = V_107 ;
}
static void
F_50 ( T_17 V_100 , T_18 V_80 , T_18 V_82 , int V_69 )
{
T_8 * V_25 = NULL ;
BOOL V_101 = FALSE ;
V_25 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_25 ) {
F_36 ( L_19 , V_80 , V_82 ) ;
return;
}
if ( V_69 >= 0 ) {
if ( V_100 == V_109 )
V_25 -> V_29 . V_30 = 1 ;
if ( V_100 == V_110 )
V_101 = TRUE ;
}
if ( V_25 -> V_106 . V_76 == V_107 ) {
F_36 ( L_20 ) ;
return;
}
if ( V_25 -> V_106 . V_76 != ( T_5 ) V_100 ) {
F_36 ( L_18 , V_100 , V_25 -> V_106 . V_76 ) ;
return;
}
F_39 ( & V_25 -> V_106 , V_69 ) ;
V_25 -> V_106 . V_76 = V_107 ;
if ( V_101 )
F_23 ( V_25 ) ;
}
static void
F_51 ( T_5 V_80 ,
T_5 V_60 , T_14 * V_68 ,
int V_69 , BOOL V_111 )
{
BOOL V_112 = FALSE ;
T_7 * V_113 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_113 ) {
F_36 ( L_21 , V_80 ) ;
return;
}
if ( V_111 ) {
memcpy ( & V_113 -> V_106 , V_68 ,
sizeof( T_14 ) ) ;
} else
V_113 -> V_106 . V_76 = V_107 ;
F_27 ( & V_38 ) ;
if ( V_69 == V_54 ) {
switch ( V_60 ) {
case V_103 :
if ( V_39 . V_114 ) {
(* V_39 . V_114 ) ( V_80 ) ;
V_112 = TRUE ;
}
if ( ( ! V_113 -> V_87 . V_115 ) &&
V_43 . V_114 ) {
(* V_43 . V_114 ) ( V_80 ) ;
V_112 = TRUE ;
}
break;
case V_105 :
if ( V_39 . V_116 ) {
(* V_39 . V_116 ) ( V_80 ) ;
V_112 = TRUE ;
}
if ( ( ! V_113 -> V_87 . V_115 ) &&
V_43 . V_116 ) {
(* V_43 . V_116 ) ( V_80 ) ;
V_112 = TRUE ;
}
break;
}
}
if ( V_112 )
;
else
F_45 ( V_60 , V_80 , V_69 ) ;
F_29 ( & V_38 ) ;
}
static void
F_52 ( T_5 V_80 , T_5 V_82 , T_15 V_29 , T_5 V_60 ,
T_14 * V_68 , int V_69 ,
BOOL V_111 , BOOL V_117 )
{
T_9 * V_35 = NULL ;
BOOL V_112 = FALSE ;
T_8 * V_118 =
F_49 ( & V_104 , V_80 , V_82 ) ;
char * V_119 [] = {
L_22 ,
NULL
} ;
if ( ! V_118 ) {
F_36 ( L_23 , V_80 , V_82 ) ;
return;
}
if ( V_117 )
V_35 = & V_39 ;
else
V_35 = & V_43 ;
if ( V_111 ) {
memcpy ( & V_118 -> V_106 , V_68 ,
sizeof( T_14 ) ) ;
} else
V_118 -> V_106 . V_76 = V_107 ;
F_27 ( & V_38 ) ;
if ( V_69 >= 0 ) {
switch ( V_60 ) {
case V_109 :
if ( V_35 -> V_120 ) {
(* V_35 -> V_120 ) ( V_80 , V_82 ) ;
V_112 = TRUE ;
}
break;
case V_77 :
if ( V_29 . V_121 == V_122 . V_121 &&
V_29 . V_123 == V_122 . V_123 ) {
if ( V_35 -> V_124 ) {
(* V_35 -> V_124 ) ( V_80 ,
V_82 ) ;
V_112 = TRUE ;
}
}
else if ( V_29 . V_121 == V_125 . V_121 &&
V_29 . V_123 ==
V_125 . V_123 ) {
if ( V_35 -> V_126 ) {
(* V_35 -> V_126 ) ( V_80 ,
V_82 ) ;
V_112 = TRUE ;
}
} else if ( V_29 . V_121 == V_127 . V_121 &&
V_29 . V_123 ==
V_127 . V_123 ) {
if ( V_80 == V_81
&& V_82 == V_83 ) {
F_40 ( L_24 ,
V_80 , V_82 ) ;
F_53
( & V_128 . V_3 .
V_129 , V_130 , V_119 ) ;
}
}
break;
case V_110 :
if ( V_35 -> V_131 ) {
(* V_35 -> V_131 ) ( V_80 , V_82 ) ;
V_112 = TRUE ;
}
break;
}
}
if ( V_112 )
;
else
F_50 ( V_60 , V_80 , V_82 , V_69 ) ;
F_29 ( & V_38 ) ;
}
static void
V_114 ( T_12 * V_50 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_132 . V_80 ;
int V_53 = V_54 ;
T_7 * V_113 = NULL ;
V_113 = F_46 ( & V_102 , V_80 ) ;
if ( V_113 && ( V_113 -> V_29 . V_30 == 1 ) ) {
F_36 ( L_25 ,
V_80 ) ;
F_44 ( V_133 , V_80 ,
V_93 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_113 = F_54 ( sizeof( T_7 ) , V_134 ) ;
if ( V_113 == NULL ) {
F_36 ( L_26 ,
V_80 ) ;
F_44 ( V_133 , V_80 ,
V_93 ) ;
V_53 = - V_135 ;
goto V_58;
}
F_55 ( & V_113 -> V_49 ) ;
V_113 -> V_80 = V_80 ;
V_113 -> V_82 = V_60 -> V_132 . V_136 ;
F_44 ( V_137 , V_80 , V_56 ) ;
if ( V_50 -> V_64 . V_65 . V_84 == 1 )
V_113 -> V_138 . V_139 = V_140 ;
else
V_113 -> V_138 . V_139 = V_141 ;
V_113 -> V_87 . V_115 = V_50 -> V_64 . V_65 . V_115 ;
V_113 -> V_138 . V_142 = V_60 -> V_132 . V_142 ;
V_113 -> V_138 . V_143 = V_60 -> V_132 . V_144 ;
V_113 -> V_138 . V_145 = V_60 -> V_132 . V_146 ;
V_113 -> V_138 . V_147 = V_60 -> V_132 . V_148 ;
F_56 ( & V_113 -> V_49 , & V_102 ) ;
F_44 ( V_149 , V_80 , V_56 ) ;
V_58:
F_51 ( V_80 , V_103 , & V_50 -> V_64 ,
V_53 , V_50 -> V_64 . V_65 . V_66 == 1 ) ;
}
static void
V_116 ( T_12 * V_50 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_150 . V_80 ;
T_7 * V_113 ;
int V_53 = V_54 ;
V_113 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_113 ) {
F_36 ( L_27 , V_80 ) ;
V_53 = - V_151 ;
goto V_58;
}
if ( V_113 -> V_29 . V_30 == 0 ) {
F_36 ( L_28 ,
V_80 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_58:
F_51 ( V_80 , V_105 , & V_50 -> V_64 ,
V_53 , V_50 -> V_64 . V_65 . V_66 == 1 ) ;
}
static void
F_57 ( T_12 * V_50 , T_20 * V_152 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_153 . V_80 ;
T_7 * V_113 = NULL ;
int V_53 = V_54 ;
char V_1 [ 99 ] ;
V_80 = V_60 -> V_153 . V_80 ;
F_44 ( V_154 , V_80 , V_56 ) ;
V_113 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_113 ) {
F_36 ( L_29 ,
V_80 ) ;
F_44 ( V_155 , V_80 ,
V_93 ) ;
V_53 = - V_151 ;
goto V_58;
}
if ( V_113 -> V_29 . V_30 == 0 ) {
F_36 ( L_30 ,
V_80 ) ;
F_44 ( V_155 , V_80 ,
V_93 ) ;
V_53 = - V_151 ;
goto V_58;
}
if ( V_113 -> V_106 . V_76 != V_107 ) {
F_36 ( L_31 ,
V_80 , ( V_156 ) V_113 -> V_106 . V_76 ) ;
F_44 ( V_155 , V_80 ,
V_93 ) ;
V_53 = - V_157 ;
goto V_58;
}
V_113 -> V_158 = V_60 -> V_153 . V_159 ;
V_113 -> V_160 = F_58 ( V_152 ) ;
F_59 ( V_152 , V_161 ) ;
V_113 -> V_27 = F_60 ( V_152 ) ;
F_61 ( & V_113 -> V_160 , V_1 ) ;
F_44 ( V_162 , V_80 , V_56 ) ;
V_58:
F_51 ( V_80 , V_163 , & V_50 -> V_64 ,
V_53 , V_50 -> V_64 . V_65 . V_66 == 1 ) ;
}
static void
F_62 ( T_12 * V_50 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_164 . V_80 ;
T_18 V_82 = V_60 -> V_164 . V_82 ;
T_8 * V_118 = NULL ;
T_7 * V_113 = NULL ;
int V_53 = V_54 ;
V_118 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( V_118 && ( V_118 -> V_29 . V_30 == 1 ) ) {
F_36 ( L_32 ,
V_80 , V_82 ) ;
F_63 ( V_165 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_113 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_113 ) {
F_36 ( L_33 ,
V_80 ) ;
F_63 ( V_165 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_151 ;
goto V_58;
}
if ( V_113 -> V_29 . V_30 == 0 ) {
F_36 ( L_34 ,
V_80 ) ;
F_63 ( V_165 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_151 ;
goto V_58;
}
V_118 = F_54 ( sizeof( T_8 ) , V_134 ) ;
if ( V_118 == NULL ) {
F_36 ( L_35 ,
V_80 , V_82 ) ;
F_63 ( V_165 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_135 ;
goto V_58;
}
F_55 ( & V_118 -> V_49 ) ;
V_118 -> V_80 = V_80 ;
V_118 -> V_82 = V_82 ;
V_118 -> V_166 = V_60 -> V_164 . V_166 ;
F_63 ( V_167 , V_82 , V_80 ,
V_56 ) ;
if ( V_50 -> V_64 . V_65 . V_84 == 1 )
V_118 -> V_138 . V_139 = V_140 ;
else
V_118 -> V_138 . V_139 = V_141 ;
V_118 -> V_138 . V_142 = V_60 -> V_164 . V_142 ;
V_118 -> V_138 . V_143 = V_60 -> V_164 . V_144 ;
V_118 -> V_138 . V_145 = V_60 -> V_164 . V_168 ;
V_118 -> V_138 . V_169 = V_60 -> V_164 . V_169 ;
F_56 ( & V_118 -> V_49 , & V_104 ) ;
F_63 ( V_170 , V_82 , V_80 ,
V_56 ) ;
V_58:
if ( F_64 ( V_118 -> V_138 . V_145 ) ) {
V_81 = V_80 ;
V_83 = V_82 ;
F_40 ( L_36 ,
V_81 , V_83 ) ;
}
F_52 ( V_80 , V_82 , V_122 ,
V_109 , & V_50 -> V_64 , V_53 ,
V_50 -> V_64 . V_65 . V_66 == 1 ,
F_65 ( V_118 -> V_138 . V_145 ) ) ;
}
static void
F_66 ( T_12 * V_50 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_79 . V_80 ;
T_18 V_82 = V_60 -> V_79 . V_82 ;
T_15 V_29 = V_60 -> V_79 . V_29 ;
T_8 * V_118 = NULL ;
int V_53 = V_54 ;
V_118 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_118 ) {
F_36 ( L_37 ,
V_80 , V_82 ) ;
F_63 ( V_171 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_172 ;
goto V_58;
}
if ( V_118 -> V_29 . V_30 == 0 ) {
F_36 ( L_38 ,
V_80 , V_82 ) ;
F_63 ( V_171 , V_82 , V_80 ,
V_93 ) ;
V_53 = - V_172 ;
}
V_58:
if ( ( V_53 >= V_54 ) && V_118 )
F_52 ( V_80 , V_82 , V_29 , V_77 ,
& V_50 -> V_64 , V_53 ,
V_50 -> V_64 . V_65 . V_66 == 1 ,
F_65 ( V_118 -> V_138 . V_145 ) ) ;
}
static void
F_67 ( T_12 * V_50 )
{
T_19 * V_60 = & V_50 -> V_60 ;
T_18 V_80 = V_60 -> V_173 . V_80 ;
T_18 V_82 = V_60 -> V_173 . V_82 ;
T_8 * V_118 = NULL ;
int V_53 = V_54 ;
V_118 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_118 ) {
F_36 ( L_39 ,
V_80 , V_82 ) ;
V_53 = - V_172 ;
goto V_58;
}
if ( V_118 -> V_29 . V_30 == 0 ) {
F_36 ( L_40 ,
V_80 , V_82 ) ;
V_53 = - V_57 ;
}
V_58:
if ( ( V_53 >= V_54 ) && V_118 )
F_52 ( V_80 , V_82 , V_122 ,
V_110 , & V_50 -> V_64 , V_53 ,
V_50 -> V_64 . V_65 . V_66 == 1 ,
F_65 ( V_118 -> V_138 . V_145 ) ) ;
}
static int
F_68 ( T_21 V_174 , T_22 V_175 , T_5 V_176 ,
T_23 * V_177 )
{
T_2 T_24 * V_178 = NULL ;
int V_53 = V_54 ;
if ( V_177 == NULL ) {
F_36 ( L_41 ,
__FILE__ , __LINE__ ) ;
V_53 = - V_179 ;
goto V_58;
}
memset ( V_177 , 0 , sizeof( T_23 ) ) ;
if ( ( V_175 == 0 ) || ( V_176 == 0 ) ) {
F_36 ( L_42 ,
( T_22 ) V_175 , ( T_22 ) V_176 ) ;
V_53 = - V_179 ;
goto V_58;
}
V_178 = F_69 ( V_174 + V_175 , V_176 ) ;
if ( V_178 == NULL ) {
F_36 ( L_43 ,
( T_22 ) V_175 , ( T_22 ) V_176 ) ;
V_53 = - V_180 ;
goto V_58;
}
V_177 -> V_175 = V_175 ;
V_177 -> V_176 = V_176 ;
V_177 -> V_181 = V_178 ;
F_40 ( L_44 ,
( T_22 ) ( V_177 -> V_175 ) , ( T_18 ) ( V_177 -> V_176 ) , V_177 -> V_181 ) ;
V_58:
if ( V_53 < 0 ) {
if ( V_178 != NULL ) {
F_70 ( V_178 ) ;
V_178 = NULL ;
}
}
return V_53 ;
}
static void
F_71 ( T_23 * V_177 )
{
if ( V_177 -> V_181 != NULL ) {
F_70 ( V_177 -> V_181 ) ;
V_177 -> V_181 = NULL ;
}
memset ( V_177 , 0 , sizeof( T_23 ) ) ;
}
static void
F_72 ( void )
{
T_21 V_174 = F_73 ( V_8 ) ;
T_22 V_182 = 0 ;
T_5 V_183 = 0 ;
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_184 ) ,
& V_182 , sizeof( V_182 ) ) < 0 ) {
F_36 ( L_45 ) ;
F_35 ( V_185 ,
V_93 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_186 ) ,
& V_183 , sizeof( V_183 ) ) < 0 ) {
F_36 ( L_45 ) ;
F_35 ( V_185 ,
V_93 ) ;
return;
}
F_68 ( V_174 ,
V_182 , V_183 ,
& V_187 ) ;
}
int
F_74 ( void )
{
F_75 ( & V_128 . V_3 . V_129 , V_130 ) ;
return V_54 ;
}
int
F_76 ( void )
{
char V_188 [ 20 ] ;
char * V_119 [] = { V_188 , NULL } ;
sprintf ( V_188 , L_46 , 1 ) ;
F_53 ( & V_128 . V_3 . V_129 , V_189 ,
V_119 ) ;
return V_54 ;
}
int
F_77 ( void )
{
F_75 ( & V_128 . V_3 . V_129 , V_190 ) ;
return V_54 ;
}
static void
F_78 ( T_14 * V_68 )
{
int V_53 = F_74 () ;
if ( V_53 != V_54 )
V_53 = - V_53 ;
if ( V_68 -> V_65 . V_66 && ! V_191 )
F_39 ( V_68 , V_53 ) ;
if ( V_68 -> V_65 . V_66 && V_191 ) {
V_192 = * V_68 ;
F_40 ( L_47 ) ;
}
}
static void
F_79 ( T_14 * V_68 )
{
int V_53 = F_76 () ;
if ( V_53 != V_54 )
V_53 = - V_53 ;
if ( V_68 -> V_65 . V_66 )
F_39 ( V_68 , V_53 ) ;
}
static void
F_80 ( T_14 * V_68 )
{
int V_53 = F_77 () ;
if ( V_53 != V_54 )
V_53 = - V_53 ;
if ( V_68 -> V_65 . V_66 )
F_39 ( V_68 , V_53 ) ;
}
static BOOL
F_81 ( T_12 * V_67 )
{
if ( F_82 ( V_8 ,
V_193 , V_67 ) ) {
if ( V_67 -> V_64 . V_65 . V_84 == 1 ) {
F_36 ( L_48 , V_67 -> V_64 . V_76 ) ;
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
static int
F_83 ( void )
{
static T_25 V_194 = F_84 ( 0 ) ;
return F_85 ( & V_194 ) ;
}
static unsigned long
F_86 ( void )
{
return V_195 + V_196 * V_197 / 1000 ;
}
static struct V_198 *
F_87 ( T_12 * V_67 )
{
struct V_198 * V_199 =
F_88 ( sizeof( struct V_198 ) ,
V_134 | V_200 ) ;
if ( V_199 == NULL )
return NULL ;
V_199 -> V_194 = F_83 () ;
V_199 -> V_201 = F_86 () ;
V_199 -> V_67 = * V_67 ;
return V_199 ;
}
static void
F_89 ( struct V_198 * V_199 )
{
F_22 ( V_199 ) ;
}
static void
F_90 ( struct V_198 * V_199 )
{
T_19 * V_60 = & V_199 -> V_67 . V_60 ;
char V_202 [ 40 ] , V_203 [ 40 ] , V_204 [ 40 ] , V_205 [ 40 ] , V_206 [ 40 ] ,
V_207 [ 40 ] ;
char * V_119 [] = {
V_202 , V_203 , V_204 , V_205 , V_206 , V_207 , NULL
} ;
sprintf ( V_202 , L_49 ) ;
sprintf ( V_203 , L_50 , V_199 -> V_194 ) ;
sprintf ( V_204 , L_51 ,
V_60 -> V_79 . V_29 . V_208 ) ;
sprintf ( V_205 , L_52 ,
V_60 -> V_79 . V_80 ) ;
sprintf ( V_206 , L_53 ,
V_60 -> V_79 . V_82 >> 3 ) ;
sprintf ( V_207 , L_54 ,
V_60 -> V_79 . V_82 & 0x7 ) ;
F_40 ( L_55 ,
V_60 -> V_79 . V_29 . V_208 ,
V_60 -> V_79 . V_80 , V_60 -> V_79 . V_82 >> 3 ,
V_60 -> V_79 . V_82 & 7 , V_199 -> V_194 ) ;
F_53 ( & V_128 . V_3 . V_129 , V_189 ,
V_119 ) ;
}
static void
F_91 ( void )
{
struct V_209 * V_210 = NULL ;
struct V_209 * V_211 = NULL ;
F_92 ( & V_212 ) ;
F_93 (pos, tmp, &Parahotplug_request_list) {
struct V_198 * V_199 =
F_94 ( V_210 , struct V_198 , V_213 ) ;
if ( F_95 ( V_195 , V_199 -> V_201 ) ) {
F_33 ( V_210 ) ;
if ( V_199 -> V_67 . V_64 . V_65 . V_66 )
F_42 (
& V_199 -> V_67 . V_64 ,
V_214 ,
V_199 -> V_67 . V_60 . V_79 . V_29 ) ;
F_89 ( V_199 ) ;
}
}
F_96 ( & V_212 ) ;
}
static int
F_97 ( int V_194 , T_6 V_215 )
{
struct V_209 * V_210 = NULL ;
struct V_209 * V_211 = NULL ;
F_92 ( & V_212 ) ;
F_93 (pos, tmp, &Parahotplug_request_list) {
struct V_198 * V_199 =
F_94 ( V_210 , struct V_198 , V_213 ) ;
if ( V_199 -> V_194 == V_194 ) {
F_33 ( V_210 ) ;
F_96 ( & V_212 ) ;
V_199 -> V_67 . V_60 . V_79 . V_29 . V_208 = V_215 ;
if ( V_199 -> V_67 . V_64 . V_65 . V_66 )
F_42 (
& V_199 -> V_67 . V_64 , V_54 ,
V_199 -> V_67 . V_60 . V_79 . V_29 ) ;
F_89 ( V_199 ) ;
return 0 ;
}
}
F_96 ( & V_212 ) ;
return - 1 ;
}
static void
F_98 ( T_12 * V_50 )
{
struct V_198 * V_199 ;
V_199 = F_87 ( V_50 ) ;
if ( V_199 == NULL ) {
F_36 ( L_56 ) ;
return;
}
if ( V_50 -> V_60 . V_79 . V_29 . V_208 ) {
F_90 ( V_199 ) ;
F_42 ( & V_50 -> V_64 ,
V_54 ,
V_50 -> V_60 .
V_79 . V_29 ) ;
F_89 ( V_199 ) ;
} else {
F_92 ( & V_212 ) ;
F_99 ( & ( V_199 -> V_213 ) , & V_216 ) ;
F_96 ( & V_212 ) ;
F_90 ( V_199 ) ;
}
}
static BOOL
F_100 ( T_12 V_50 , T_21 V_217 )
{
T_19 * V_60 = & V_50 . V_60 ;
T_22 V_218 = 0 ;
T_5 V_219 = 0 ;
T_20 * V_152 = NULL ;
BOOL V_220 = FALSE ;
T_12 V_221 ;
V_220 = ( V_50 . V_64 . V_65 . V_84 == 1 ) ;
if ( V_217 == 0 ) {
F_36 ( L_57 ) ;
return TRUE ;
}
V_218 = V_217 + V_50 . V_64 . V_71 ;
V_219 = V_50 . V_64 . V_70 ;
if ( V_218 != 0 && V_219 != 0 ) {
BOOL V_222 = FALSE ;
V_152 =
F_101 ( V_218 , V_219 ,
V_220 , & V_222 ) ;
if ( ! V_152 ) {
if ( V_222 ) {
F_102 ( L_58 ) ;
return FALSE ;
}
F_102 ( L_59 ) ;
F_102 ( L_60 , ( T_18 ) V_50 . V_64 . V_76 ) ;
F_102 ( L_61 , ( T_22 ) V_218 ) ;
F_102 ( L_62 , ( T_18 ) V_219 ) ;
F_102 ( L_63 , V_220 ) ;
}
}
if ( ! V_220 ) {
F_38 ( & V_221 , & V_50 . V_64 ,
V_54 ) ;
if ( ( V_8 )
&&
( ! F_41
( V_8 , V_223 , & V_221 ) ) )
F_102 ( L_64 ) ;
}
switch ( V_50 . V_64 . V_76 ) {
case V_224 :
F_40 ( L_65 ,
( T_18 ) V_50 . V_60 . V_61 . V_225 ,
( T_18 ) V_50 . V_60 . V_61 . V_226 ) ;
F_34 ( & V_50 ) ;
break;
case V_103 :
F_40 ( L_66 ,
( T_18 ) V_60 -> V_132 . V_80 ,
( T_18 ) V_60 -> V_132 . V_136 ) ;
V_114 ( & V_50 ) ;
break;
case V_105 :
F_40 ( L_67 , ( T_18 ) V_60 -> V_150 . V_80 ) ;
V_116 ( & V_50 ) ;
break;
case V_163 :
F_40 ( L_68 , ( T_18 ) V_60 -> V_153 . V_80 ) ;
F_57 ( & V_50 , V_152 ) ;
break;
case V_109 :
F_40 ( L_69 ,
( T_18 ) V_60 -> V_164 . V_80 ,
( T_18 ) V_60 -> V_164 . V_82 ) ;
F_62 ( & V_50 ) ;
break;
case V_77 :
if ( V_60 -> V_79 . V_87 . V_88 ) {
F_40 ( L_70 ,
( T_18 ) V_60 -> V_79 . V_80 ,
( T_18 ) V_60 -> V_79 . V_82 ,
( T_18 ) V_60 -> V_79 . V_29 . V_208 ) ;
F_98 ( & V_50 ) ;
} else {
F_40 ( L_71 ,
( T_18 ) V_60 -> V_79 . V_80 ,
( T_18 ) V_60 -> V_79 . V_82 ,
( T_18 ) V_60 -> V_79 . V_29 . V_121 ) ;
F_66 ( & V_50 ) ;
V_227 = V_50 . V_64 ;
V_78 = V_50 . V_60 ;
break;
}
break;
case V_110 :
F_40 ( L_72 ,
( T_18 ) V_60 -> V_173 . V_80 ,
( T_18 ) V_60 -> V_173 . V_82 ) ;
F_67 ( & V_50 ) ;
break;
case V_228 :
F_40 ( L_73 ,
( T_18 ) V_60 -> V_229 . V_80 ,
( T_18 ) V_60 -> V_229 . V_82 ) ;
if ( V_50 . V_64 . V_65 . V_66 )
F_39 ( & V_50 . V_64 , V_54 ) ;
break;
case V_230 :
F_40 ( L_74 ) ;
F_78 ( & V_50 . V_64 ) ;
break;
case V_231 :
F_40 ( L_75 ) ;
F_79 ( & V_50 . V_64 ) ;
break;
case V_232 :
F_40 ( L_76 ) ;
F_80 ( & V_50 . V_64 ) ;
break;
default:
F_36 ( L_77 , ( int ) V_50 . V_64 . V_76 ) ;
if ( V_50 . V_64 . V_65 . V_66 )
F_39 ( & V_50 . V_64 ,
- V_233 ) ;
break;
}
if ( V_152 != NULL ) {
F_103 ( V_152 ) ;
V_152 = NULL ;
}
return TRUE ;
}
static T_21 F_104 ( void )
{
T_22 V_234 = 0 ;
T_5 V_235 = 0 ;
if ( ! F_105 ( F_106 ( & V_234 , & V_235 ) ) ) {
F_107 ( L_78 ,
V_85 ) ;
return 0 ;
}
F_108 ( L_79 , V_234 ) ;
return V_234 ;
}
static void
F_109 ( struct V_236 * V_237 )
{
T_26 V_138 ;
T_12 V_50 ;
BOOL V_238 = FALSE ;
BOOL V_239 = FALSE ;
static T_22 V_240 ;
if ( V_241 && ! V_40 )
goto V_58;
if ( V_242 && ! V_44 )
goto V_58;
memset ( & V_138 , 0 , sizeof( T_26 ) ) ;
V_240 ++ ;
if ( V_240 >= 250 )
;
else
goto V_58;
if ( V_191
&& ( V_192 . V_76 != V_107 ) ) {
if ( F_24 () == 1 ) {
F_40 ( L_80 ) ;
F_39 ( & V_192 , 0 ) ;
F_25 () ;
memset ( & V_192 , 0 ,
sizeof( T_14 ) ) ;
}
}
while ( F_82 ( V_8 ,
V_243 ,
& V_50 ) ) {
if ( V_50 . V_64 . V_72 != 0 ) {
F_36 ( L_81 ,
( T_18 ) V_50 . V_64 . V_72 ,
( T_18 ) V_50 . V_64 . V_71 ,
V_50 . V_64 . V_76 ) ;
}
}
if ( ! V_238 ) {
if ( V_244 ) {
V_50 = V_245 ;
V_244 = FALSE ;
V_238 = TRUE ;
} else
V_238 = F_81 ( & V_50 ) ;
}
V_239 = FALSE ;
while ( V_238 && ( ! V_239 ) ) {
V_246 = V_195 ;
if ( F_100 ( V_50 ,
F_73
( V_8 ) ) )
V_238 = F_81 ( & V_50 ) ;
else {
V_239 = TRUE ;
V_245 = V_50 ;
V_244 = TRUE ;
}
}
F_91 () ;
V_58:
if ( F_110 ( V_195 ,
V_246 + ( V_197 * V_247 ) ) ) {
if ( V_248 != V_249 ) {
F_40 ( L_82 ) ;
V_248 = V_249 ;
}
} else {
if ( V_248 != V_250 ) {
V_248 = V_250 ;
F_40 ( L_83 ) ;
}
}
F_111 ( V_251 ,
& V_252 , V_248 ) ;
}
static void
F_112 ( struct V_236 * V_237 )
{
T_12 V_253 ;
T_12 V_254 ;
T_12 V_67 ;
T_5 V_89 ;
T_6 V_90 ;
if ( V_241 && ! V_40 )
goto V_58;
if ( V_242 && ! V_44 )
goto V_58;
F_35 ( V_255 , V_56 ) ;
V_67 . V_64 . V_76 = V_224 ;
V_67 . V_60 . V_61 . V_225 = 23 ;
V_67 . V_60 . V_61 . V_226 = 0 ;
F_34 ( & V_67 ) ;
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_91 ) ,
& V_90 , sizeof( T_6 ) ) < 0 ) {
F_36 ( L_11 ) ;
F_35 ( V_92 ,
V_93 ) ;
return;
}
if ( V_90 != V_94 ) {
F_36 ( L_12 ,
V_90 ) ;
F_44 ( V_95 ,
V_90 ,
V_93 ) ;
return;
}
if ( F_3 ( V_8 ,
F_4 ( V_9 ,
V_96 ) ,
& V_89 , sizeof( T_5 ) ) < 0 ) {
F_36 ( L_13 ) ;
F_35 ( V_92 ,
V_93 ) ;
return;
}
if ( F_3 ( V_8 ,
V_89 ,
& V_253 ,
sizeof( T_12 ) ) < 0 ) {
F_36 ( L_84 ) ;
F_35 ( V_256 ,
V_93 ) ;
return;
}
if ( F_3 ( V_8 ,
V_89 +
sizeof( T_12 ) ,
& V_254 ,
sizeof( T_12 ) ) < 0 ) {
F_36 ( L_85 ) ;
F_35 ( V_257 ,
V_93 ) ;
return;
}
if ( V_253 . V_60 . V_132 . V_142 != 0 )
V_114 ( & V_253 ) ;
else {
F_36 ( L_86 ) ;
F_35 ( V_258 ,
V_93 ) ;
return;
}
if ( V_254 . V_60 . V_164 . V_142 != 0 )
F_62 ( & V_254 ) ;
else {
F_36 ( L_87 ) ;
F_35 ( V_259 ,
V_93 ) ;
return;
}
F_40 ( L_88 ) ;
F_35 ( V_260 , V_56 ) ;
return;
V_58:
V_248 = V_249 ;
F_111 ( V_251 ,
& V_252 , V_248 ) ;
}
static void
F_113 ( T_18 V_80 , int V_69 )
{
F_45 ( V_103 , V_80 , V_69 ) ;
}
static void
F_114 ( T_18 V_80 , int V_69 )
{
F_45 ( V_105 , V_80 , V_69 ) ;
}
static void
F_115 ( T_18 V_80 , T_18 V_82 , int V_69 )
{
F_50 ( V_109 , V_80 , V_82 , V_69 ) ;
}
static void
F_116 ( T_18 V_80 , T_18 V_82 , int V_69 )
{
F_50 ( V_110 , V_80 , V_82 , V_69 ) ;
}
void
F_117 ( T_18 V_80 , T_18 V_82 , int V_69 )
{
F_48 ( V_77 ,
V_80 , V_82 , V_69 ,
V_125 ) ;
}
static void
F_118 ( T_18 V_80 , T_18 V_82 , int V_69 )
{
F_48 ( V_77 ,
V_80 , V_82 , V_69 ,
V_122 ) ;
}
BOOL
F_119 ( T_18 V_80 , T_7 * V_261 )
{
void * V_25 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_25 ) {
F_36 ( L_89 , V_80 ) ;
return FALSE ;
}
memcpy ( V_261 , V_25 , sizeof( T_7 ) ) ;
return TRUE ;
}
BOOL
F_120 ( T_18 V_80 , void * V_262 )
{
T_7 * V_25 = F_46 ( & V_102 , V_80 ) ;
if ( ! V_25 ) {
F_36 ( L_89 , V_80 ) ;
return FALSE ;
}
V_25 -> V_263 = V_262 ;
return TRUE ;
}
BOOL
F_121 ( T_18 V_80 , T_18 V_82 ,
T_8 * V_264 )
{
void * V_25 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_25 ) {
F_36 ( L_90 , V_80 , V_82 ) ;
return FALSE ;
}
memcpy ( V_264 , V_25 , sizeof( T_8 ) ) ;
return TRUE ;
}
BOOL
F_122 ( T_18 V_80 , T_18 V_82 , void * V_262 )
{
T_8 * V_25 = F_49 ( & V_104 , V_80 , V_82 ) ;
if ( ! V_25 ) {
F_36 ( L_90 , V_80 , V_82 ) ;
return FALSE ;
}
V_25 -> V_263 = V_262 ;
return TRUE ;
}
void *
F_123 ( struct V_265 * V_266 , BOOL V_267 ,
char * V_268 , int V_269 )
{
T_27 V_270 ;
void * V_25 ;
if ( V_267 )
V_270 = V_134 ;
else
V_270 = V_271 ;
V_270 |= V_200 ;
V_25 = F_124 ( V_266 , V_270 ) ;
if ( ! V_25 ) {
F_36 ( L_91 , V_268 , V_269 ) ;
return NULL ;
}
F_125 ( & V_272 ) ;
return V_25 ;
}
void
F_126 ( struct V_265 * V_266 , void * V_25 , char * V_268 , int V_269 )
{
if ( ! V_25 ) {
F_36 ( L_92 , V_268 , V_269 ) ;
return;
}
F_127 ( & V_272 ) ;
F_128 ( V_266 , V_25 ) ;
}
static T_1 F_129 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
char V_273 [ 64 ] ;
if ( sscanf ( V_6 , L_93 , V_273 ) != 1 )
return - V_14 ;
if ( strcmp ( V_273 , L_94 ) == 0 ) {
V_34 [ 0 ] = 1 ;
return V_12 ;
} else if ( strcmp ( V_273 , L_95 ) == 0 ) {
V_34 [ 1 ] = 1 ;
return V_12 ;
}
return - V_14 ;
}
static T_1 F_130 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
V_156 V_194 ;
if ( F_131 ( V_6 , 10 , & V_194 ) != 0 )
return - V_14 ;
F_97 ( V_194 , 0 ) ;
return V_12 ;
}
static T_1 F_132 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 , T_3 V_12 )
{
V_156 V_194 ;
if ( F_131 ( V_6 , 10 , & V_194 ) != 0 )
return - V_14 ;
F_97 ( V_194 , 1 ) ;
return V_12 ;
}
static int T_28
F_133 ( void )
{
int V_53 = 0 , V_274 = 0 ;
char V_1 [ 64 ] ;
T_21 V_234 ;
if ( ! V_275 )
return - V_276 ;
F_40 ( L_96 , V_42 ) ;
F_35 ( V_277 , V_56 ) ;
F_40 ( L_97 , V_278 ) ;
F_40 ( L_98 , V_279 ) ;
F_40 ( L_99 , V_280 ) ;
F_40 ( L_100 , V_281 ) ;
F_40 ( L_101 , V_282 ) ;
F_40 ( L_102 , V_241 ) ;
F_40 ( L_103 , V_242 ) ;
F_40 ( L_104 , V_191 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
memset ( & V_187 , 0 , sizeof( V_187 ) ) ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
F_134 ( & V_283 . V_284 , 0 ) ;
if ( V_278 ) {
F_107 ( L_105 ,
V_274 ) ;
F_44 ( V_285 , V_274 , V_286 ) ;
V_53 = V_274 ;
goto V_58;
}
V_234 = F_104 () ;
if ( V_234 != 0 ) {
V_8 =
F_135
( V_234 ,
sizeof( V_9 ) ,
V_287 ) ;
if ( F_136
( F_137 ( V_8 ) ,
NULL ) ) {
F_40 ( L_106 ,
F_138 ( V_8 , V_1 ) ) ;
F_72 () ;
} else {
F_36 ( L_107 ) ;
F_139 ( V_8 ) ;
V_8 = NULL ;
return - V_276 ;
}
} else {
F_36 ( L_108 ) ;
return - V_276 ;
}
V_288 = F_140 ( V_282 , 0 ) ;
V_53 = F_141 ( V_288 , & V_8 ) ;
if ( V_53 < 0 ) {
F_107 ( L_109 , V_53 ) ;
F_35 ( V_285 , V_286 ) ;
goto V_58;
}
memset ( & V_227 , 0 , sizeof( T_14 ) ) ;
memset ( & V_192 , 0 , sizeof( T_14 ) ) ;
memset ( & V_289 , 0 , sizeof( T_14 ) ) ;
V_290 =
F_142 ( V_291 ,
sizeof( struct V_292 ) ,
0 , V_293 , NULL ) ;
if ( ! V_290 ) {
F_107 ( L_110 ) ;
F_35 ( V_285 , V_286 ) ;
V_53 = - 1 ;
goto V_58;
}
if ( V_294 ) {
F_40 ( L_111 ) ;
} else {
if ( V_295 )
F_143 ( & V_252 ,
F_112 ) ;
else
F_143 ( & V_252 ,
F_109 ) ;
V_251 =
F_144 ( L_112 ) ;
if ( V_251 == NULL ) {
F_107 ( L_113 ,
- V_296 ) ;
F_35 ( V_297 ,
V_286 ) ;
V_53 = - V_296 ;
goto V_58;
}
V_246 = V_195 ;
V_248 = V_250 ;
V_53 = F_111 ( V_251 ,
& V_252 , V_248 ) ;
if ( V_53 < 0 ) {
F_107 ( L_114 , V_53 ) ;
F_35 ( V_298 ,
V_286 ) ;
goto V_58;
}
}
V_128 . V_3 . V_299 = V_288 ;
if ( F_145 ( & V_128 ) < 0 ) {
F_107 ( L_115 ) ;
F_35 ( V_300 , V_286 ) ;
V_53 = - 1 ;
goto V_58;
}
F_40 ( L_116 ) ;
F_35 ( V_301 , V_56 ) ;
V_53 = 0 ;
V_58:
if ( V_53 ) {
F_36 ( L_117 ) ;
F_44 ( V_285 , V_53 ,
V_93 ) ;
}
return V_53 ;
}
static void
F_146 ( void )
{
char V_1 [ 99 ] ;
F_35 ( V_302 , V_56 ) ;
if ( V_294 ) {
;
} else {
F_147 ( & V_252 ) ;
F_148 ( V_251 ) ;
F_149 ( V_251 ) ;
V_251 = NULL ;
F_71 ( & V_187 ) ;
}
V_303 = NULL ;
if ( V_290 ) {
F_150 ( V_290 ) ;
V_290 = NULL ;
}
F_31 () ;
memset ( & V_227 , 0 , sizeof( T_14 ) ) ;
memset ( & V_192 , 0 , sizeof( T_14 ) ) ;
memset ( & V_289 , 0 , sizeof( T_14 ) ) ;
F_40 ( L_118 ,
F_138 ( V_8 , V_1 ) ) ;
F_139 ( V_8 ) ;
F_151 () ;
F_35 ( V_302 , V_56 ) ;
F_40 ( L_119 ) ;
}
