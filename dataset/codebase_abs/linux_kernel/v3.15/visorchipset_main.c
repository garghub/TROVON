static inline char *
F_1 ( char * V_1 )
{
if ( V_1 )
return V_1 ;
else
return L_1 ;
}
static void
F_2 ( void )
{
char * * V_2 = V_3 ;
V_2 [ V_4 ] = L_1 ;
V_2 [ V_5 ] = L_2 ;
V_2 [ V_6 ] = L_3 ;
V_2 [ V_7 ] = L_4 ;
V_2 [ V_8 ] = L_5 ;
V_2 [ V_9 ] = NULL ;
}
static void
F_3 ( void )
{
char * * V_2 = V_10 ;
V_2 [ V_11 ] = L_1 ;
V_2 [ V_12 ] = L_6 ;
V_2 [ V_13 ] = L_7 ;
V_2 [ V_14 ] = L_8 ;
V_2 [ V_15 ] = L_9 ;
V_2 [ V_16 ] = L_10 ;
V_2 [ V_17 ] = L_11 ;
V_2 [ V_18 ] = L_12 ;
V_2 [ V_19 ] = NULL ;
}
static void
F_4 ( struct V_20 * V_21 , void * V_22 , int V_23 )
{
T_1 * V_24 = ( T_1 * ) ( V_22 ) ;
switch ( V_23 ) {
case V_5 :
F_5 ( V_21 , L_13 , F_1 ( V_24 -> V_25 ) ) ;
break;
case V_6 :
F_5 ( V_21 , L_13 , F_1 ( V_24 -> V_26 ) ) ;
break;
case V_7 :
F_5 ( V_21 , L_14 , V_24 -> V_27 ) ;
break;
case V_8 :
F_5 ( V_21 , L_15 , V_24 -> V_28 ) ;
break;
default:
F_5 ( V_21 , L_16 , V_23 ) ;
break;
}
}
static void
F_6 ( struct V_20 * V_21 , void * V_22 , int V_23 )
{
switch ( V_23 ) {
case V_12 :
if ( V_29 == NULL )
F_7 ( V_21 , L_17 ) ;
else
F_5 ( V_21 , L_14 ,
F_8
( V_29 ) ) ;
break;
case V_13 :
if ( V_29 == NULL )
F_7 ( V_21 , L_17 ) ;
else {
T_2 V_30 = 0 ;
F_9 ( V_29 ,
F_10
( V_31 ,
V_32 ) , & V_30 ,
sizeof( V_30 ) ) ;
F_5 ( V_21 , L_14 , ( V_33 ) ( V_30 ) ) ;
}
break;
case V_14 :
if ( V_29 == NULL )
F_7 ( V_21 , L_17 ) ;
else {
T_3 V_34 = 0 ;
F_9 ( V_29 ,
F_10
( V_31 ,
V_35 ) , & V_34 ,
sizeof( V_34 ) ) ;
F_5 ( V_21 , L_18 , ( V_36 ) ( V_34 ) ) ;
}
break;
case V_15 :
F_7 ( V_21 , L_19 ) ;
break;
case V_16 :
F_7 ( V_21 , L_20 ) ;
break;
case V_17 :
F_5 ( V_21 , L_18 , V_37 . V_38 ) ;
break;
case V_18 :
F_5 ( V_21 , L_18 , ( V_36 ) V_37 . V_39 ) ;
break;
default:
F_5 ( V_21 , L_16 , V_23 ) ;
break;
}
}
static void
F_11 ( void )
{
if ( V_40 == NULL ) {
V_40 = F_12 ( V_41 , NULL ) ;
if ( V_40 == NULL ) {
F_13 ( L_21 ,
V_41 ) ;
F_14 ( V_42 ,
V_43 ) ;
}
}
}
static void
F_15 ( void )
{
if ( V_40 != NULL )
F_16 ( V_41 , NULL ) ;
V_40 = NULL ;
}
static void
F_17 ( void * V_44 )
{
T_1 * V_2 = ( T_1 * ) ( V_44 ) ;
if ( V_2 -> V_45 ) {
F_18 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
}
F_19 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
F_19 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
V_2 -> V_46 . V_47 = 0 ;
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
}
static void
F_20 ( void * V_44 )
{
T_4 * V_2 = ( T_4 * ) ( V_44 ) ;
V_2 -> V_46 . V_47 = 0 ;
memset ( V_2 , 0 , sizeof( T_4 ) ) ;
}
static T_5
F_21 ( void )
{
int V_48 ;
T_5 V_49 = 1 ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ )
V_49 &= V_51 [ V_48 ] ;
return V_49 ;
}
static void
F_22 ( void )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ )
V_51 [ V_48 ] = 0 ;
}
void
F_23 ( T_6 * V_52 ,
T_7 * V_53 ,
T_8 * V_54 )
{
F_24 ( & V_55 ) ;
if ( V_52 == NULL ) {
memset ( & V_56 , 0 ,
sizeof( V_56 ) ) ;
V_57 = 0 ;
} else {
V_56 = * V_52 ;
V_57 = 1 ;
}
if ( V_53 )
* V_53 = V_58 ;
if ( V_54 )
F_25 ( V_54 , L_22 , L_23 ,
V_59 , NULL , __DATE__ , __TIME__ ) ;
F_26 ( & V_55 ) ;
}
void
F_27 ( T_6 * V_52 ,
T_7 * V_53 ,
T_8 * V_54 )
{
F_24 ( & V_55 ) ;
if ( V_52 == NULL ) {
memset ( & V_60 , 0 ,
sizeof( V_60 ) ) ;
V_61 = 0 ;
} else {
V_60 = * V_52 ;
V_61 = 1 ;
}
if ( V_53 )
* V_53 = V_58 ;
if ( V_54 )
F_25 ( V_54 , L_24 , L_23 ,
V_59 , NULL , __DATE__ , __TIME__ ) ;
F_26 ( & V_55 ) ;
}
static void
F_28 ( void )
{
T_1 * V_62 , * V_63 ;
T_4 * V_64 , * V_65 ;
F_29 (bi, tmp_bi, &BusInfoList, entry) {
F_17 ( V_62 ) ;
F_30 ( & V_62 -> V_66 ) ;
F_19 ( V_62 ) ;
}
F_29 (di, tmp_di, &DevInfoList, entry) {
F_20 ( V_64 ) ;
F_30 ( & V_64 -> V_66 ) ;
F_19 ( V_64 ) ;
}
}
static void
F_31 ( T_9 * V_67 )
{
static int V_68 ;
T_10 V_69 = 0 ;
int V_70 = V_71 ;
F_14 ( V_72 , V_73 ) ;
if ( V_68 ) {
F_13 ( L_25 ) ;
V_70 = - V_74 ;
goto V_75;
}
V_68 = 1 ;
F_14 ( V_76 , V_73 ) ;
V_69 =
V_67 -> V_77 . V_78 .
V_69 & V_79 ;
V_69 |= V_80 ;
V_75:
if ( V_70 < 0 )
F_28 () ;
if ( V_67 -> V_81 . V_82 . V_83 )
F_32 ( & V_67 -> V_81 , V_70 , V_69 ) ;
}
static void
F_33 ( T_9 * V_84 ,
T_11 * V_85 , int V_86 )
{
memset ( V_84 , 0 , sizeof( T_9 ) ) ;
memcpy ( & V_84 -> V_81 , V_85 , sizeof( T_11 ) ) ;
V_84 -> V_81 . V_87 = 0 ;
V_84 -> V_81 . V_88 = 0 ;
V_84 -> V_81 . V_89 = 0 ;
if ( V_86 < 0 ) {
V_84 -> V_81 . V_82 . V_90 = 1 ;
V_84 -> V_81 . V_91 = ( T_3 ) ( - V_86 ) ;
}
}
static void
F_34 ( T_11 * V_85 , int V_86 )
{
T_9 V_92 ;
if ( ! V_29 )
return;
F_33 ( & V_92 , V_85 , V_86 ) ;
if ( V_85 -> V_93 == V_94
&& V_95 . V_96 . V_28 ==
V_97
&& V_95 . V_96 . V_98 ==
V_99 )
V_92 . V_77 = V_95 ;
if ( V_92 . V_81 . V_82 . V_100 == 1 ) {
F_35 ( L_26 ,
V_101 , V_92 . V_81 . V_93 , V_86 ) ;
return;
}
if ( ! F_36 ( V_29 ,
V_102 , & V_92 ) ) {
F_13 ( L_27 ) ;
return;
}
}
static void
F_32 ( T_11 * V_85 , int V_86 ,
T_10 V_69 )
{
T_9 V_92 ;
if ( ! V_29 )
return;
F_33 ( & V_92 , V_85 , V_86 ) ;
V_92 . V_77 . V_78 . V_69 = V_69 ;
if ( ! F_36 ( V_29 ,
V_102 , & V_92 ) ) {
F_13 ( L_27 ) ;
return;
}
}
static void
F_37 ( T_11 * V_85 ,
int V_86 , T_12 V_46 )
{
T_9 V_92 ;
if ( ! V_29 )
return;
F_33 ( & V_92 , V_85 , V_86 ) ;
V_92 . V_77 . V_96 . V_46 = V_46 ;
V_92 . V_77 . V_96 . V_103 . V_104 = 1 ;
if ( ! F_36 ( V_29 ,
V_102 , & V_92 ) ) {
F_13 ( L_27 ) ;
return;
}
}
void
F_38 ( T_9 * V_84 , T_13 type )
{
T_3 V_105 ;
T_14 V_106 ;
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_107 ) ,
& V_106 , sizeof( T_14 ) ) < 0 ) {
F_13 ( L_28 ) ;
F_14 ( V_108 ,
V_43 ) ;
return;
}
if ( V_106 != V_109 ) {
F_13 ( L_29 ,
V_106 ) ;
F_39 ( V_110 ,
V_106 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_111 ) ,
& V_105 , sizeof( T_3 ) ) < 0 ) {
F_13 ( L_30 ) ;
F_14 ( V_108 ,
V_43 ) ;
return;
}
if ( type == V_112 ) {
if ( F_40 ( V_29 ,
V_105 ,
V_84 , sizeof( T_9 ) ) < 0 ) {
F_13 ( L_31 ) ;
F_14 ( V_113 ,
V_43 ) ;
return;
}
} else {
if ( F_40 ( V_29 ,
V_105 +
sizeof( T_9 ) , V_84 ,
sizeof( T_9 ) ) < 0 ) {
F_13 ( L_32 ) ;
F_14 ( V_114 ,
V_43 ) ;
return;
}
}
}
static void
F_41 ( T_15 V_115 , V_36 V_28 , int V_86 )
{
T_1 * V_2 = NULL ;
BOOL V_116 = FALSE ;
V_2 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_2 ) {
F_13 ( L_33 , V_28 ) ;
return;
}
if ( V_86 < 0 ) {
if ( ( V_115 == V_118 ) &&
( V_86 != ( - V_74 ) ) )
F_43 ( & V_119 , V_28 ) ;
} else {
if ( V_115 == V_118 )
V_2 -> V_46 . V_47 = 1 ;
if ( V_115 == V_120 )
V_116 = TRUE ;
}
if ( V_2 -> V_121 . V_93 == V_122 ) {
F_13 ( L_34 ) ;
return;
}
if ( V_2 -> V_121 . V_93 != ( T_3 ) V_115 ) {
F_13 ( L_35 , V_115 , V_2 -> V_121 . V_93 ) ;
return;
}
F_34 ( & V_2 -> V_121 , V_86 ) ;
V_2 -> V_121 . V_93 = V_122 ;
if ( V_116 ) {
F_17 ( V_2 ) ;
F_43 ( & V_119 , V_28 ) ;
}
}
static void
F_44 ( T_15 V_115 ,
V_36 V_28 , V_36 V_98 , int V_86 ,
T_12 V_123 )
{
T_4 * V_2 = NULL ;
T_9 V_92 ;
if ( ! V_29 )
return;
V_2 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_2 ) {
F_13 ( L_36 , V_28 , V_98 ) ;
return;
}
if ( V_2 -> V_121 . V_93 == V_122 ) {
F_13 ( L_37 ) ;
return;
}
if ( V_2 -> V_121 . V_93 != V_115 ) {
F_13 ( L_35 , V_115 , V_2 -> V_121 . V_93 ) ;
return;
}
F_33 ( & V_92 , & V_2 -> V_121 , V_86 ) ;
V_92 . V_77 . V_96 . V_28 = V_28 ;
V_92 . V_77 . V_96 . V_98 = V_98 ;
V_92 . V_77 . V_96 . V_46 = V_123 ;
if ( ! F_36 ( V_29 ,
V_102 , & V_92 ) ) {
F_13 ( L_27 ) ;
return;
}
V_2 -> V_121 . V_93 = V_122 ;
}
static void
F_46 ( T_15 V_115 , V_36 V_28 , V_36 V_98 , int V_86 )
{
T_4 * V_2 = NULL ;
BOOL V_116 = FALSE ;
V_2 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_2 ) {
F_13 ( L_36 , V_28 , V_98 ) ;
return;
}
if ( V_86 >= 0 ) {
if ( V_115 == V_124 )
V_2 -> V_46 . V_47 = 1 ;
if ( V_115 == V_125 )
V_116 = TRUE ;
}
if ( V_2 -> V_121 . V_93 == V_122 ) {
F_13 ( L_37 ) ;
return;
}
if ( V_2 -> V_121 . V_93 != ( T_3 ) V_115 ) {
F_13 ( L_35 , V_115 , V_2 -> V_121 . V_93 ) ;
return;
}
F_34 ( & V_2 -> V_121 , V_86 ) ;
V_2 -> V_121 . V_93 = V_122 ;
if ( V_116 )
F_20 ( V_2 ) ;
}
static void
F_47 ( T_3 V_28 ,
T_3 V_77 , T_11 * V_85 ,
int V_86 , BOOL V_126 )
{
BOOL V_127 = FALSE ;
T_1 * V_128 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_128 ) {
F_13 ( L_38 , V_28 ) ;
return;
}
if ( V_126 ) {
memcpy ( & V_128 -> V_121 , V_85 ,
sizeof( T_11 ) ) ;
} else
V_128 -> V_121 . V_93 = V_122 ;
F_24 ( & V_55 ) ;
if ( V_86 == V_71 ) {
switch ( V_77 ) {
case V_118 :
if ( V_56 . V_129 ) {
(* V_56 . V_129 ) ( V_28 ) ;
V_127 = TRUE ;
}
if ( ( ! V_128 -> V_103 . V_130 ) &&
V_60 . V_129 ) {
(* V_60 . V_129 ) ( V_28 ) ;
V_127 = TRUE ;
}
break;
case V_120 :
if ( V_56 . V_131 ) {
(* V_56 . V_131 ) ( V_28 ) ;
V_127 = TRUE ;
}
if ( ( ! V_128 -> V_103 . V_130 ) &&
V_60 . V_131 ) {
(* V_60 . V_131 ) ( V_28 ) ;
V_127 = TRUE ;
}
break;
}
}
if ( V_127 )
;
else
F_41 ( V_77 , V_28 , V_86 ) ;
F_26 ( & V_55 ) ;
}
static void
F_48 ( T_3 V_28 , T_3 V_98 , T_12 V_46 , T_3 V_77 ,
T_11 * V_85 , int V_86 ,
BOOL V_126 , BOOL V_132 )
{
T_6 * V_52 = NULL ;
BOOL V_127 = FALSE ;
T_4 * V_133 =
F_45 ( & V_119 , V_28 , V_98 ) ;
char * V_134 [] = {
L_39 ,
NULL
} ;
if ( ! V_133 ) {
F_13 ( L_40 , V_28 , V_98 ) ;
return;
}
if ( V_132 )
V_52 = & V_56 ;
else
V_52 = & V_60 ;
if ( V_126 ) {
memcpy ( & V_133 -> V_121 , V_85 ,
sizeof( T_11 ) ) ;
} else
V_133 -> V_121 . V_93 = V_122 ;
F_24 ( & V_55 ) ;
if ( V_86 >= 0 ) {
switch ( V_77 ) {
case V_124 :
if ( V_52 -> V_135 ) {
(* V_52 -> V_135 ) ( V_28 , V_98 ) ;
V_127 = TRUE ;
}
break;
case V_94 :
if ( V_46 . V_136 == V_137 . V_136 &&
V_46 . V_138 == V_137 . V_138 ) {
if ( V_52 -> V_139 ) {
(* V_52 -> V_139 ) ( V_28 ,
V_98 ) ;
V_127 = TRUE ;
}
}
else if ( V_46 . V_136 == V_140 . V_136 &&
V_46 . V_138 ==
V_140 . V_138 ) {
if ( V_52 -> V_141 ) {
(* V_52 -> V_141 ) ( V_28 ,
V_98 ) ;
V_127 = TRUE ;
}
} else if ( V_46 . V_136 == V_142 . V_136 &&
V_46 . V_138 ==
V_142 . V_138 ) {
if ( V_28 == V_97
&& V_98 == V_99 ) {
F_35 ( L_41 ,
V_28 , V_98 ) ;
F_49
( & V_143 . V_144 .
V_145 , V_146 , V_134 ) ;
}
}
break;
case V_125 :
if ( V_52 -> V_147 ) {
(* V_52 -> V_147 ) ( V_28 , V_98 ) ;
V_127 = TRUE ;
}
break;
}
}
if ( V_127 )
;
else
F_46 ( V_77 , V_28 , V_98 , V_86 ) ;
F_26 ( & V_55 ) ;
}
static void
V_129 ( T_9 * V_67 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_148 . V_28 ;
int V_70 = V_71 ;
T_1 * V_128 = NULL ;
V_128 = F_42 ( & V_117 , V_28 ) ;
if ( V_128 && ( V_128 -> V_46 . V_47 == 1 ) ) {
F_13 ( L_42 ,
V_28 ) ;
F_39 ( V_149 , V_28 ,
V_43 ) ;
V_70 = - V_74 ;
goto V_75;
}
V_128 = F_50 ( sizeof( T_1 ) , V_150 ) ;
if ( V_128 == NULL ) {
F_13 ( L_43 ,
V_28 ) ;
F_39 ( V_149 , V_28 ,
V_43 ) ;
V_70 = - V_151 ;
goto V_75;
}
F_51 ( & V_128 -> V_66 ) ;
V_128 -> V_28 = V_28 ;
V_128 -> V_98 = V_77 -> V_148 . V_152 ;
F_39 ( V_153 , V_28 , V_73 ) ;
if ( V_67 -> V_81 . V_82 . V_100 == 1 )
V_128 -> V_154 . V_155 = V_156 ;
else
V_128 -> V_154 . V_155 = V_157 ;
V_128 -> V_103 . V_130 = V_67 -> V_81 . V_82 . V_130 ;
V_128 -> V_154 . V_158 = V_77 -> V_148 . V_158 ;
V_128 -> V_154 . V_159 = V_77 -> V_148 . V_160 ;
V_128 -> V_154 . V_161 = V_77 -> V_148 . V_162 ;
V_128 -> V_154 . V_163 = V_77 -> V_148 . V_164 ;
F_52 ( & V_128 -> V_66 , & V_117 ) ;
F_39 ( V_165 , V_28 , V_73 ) ;
V_75:
F_47 ( V_28 , V_118 , & V_67 -> V_81 ,
V_70 , V_67 -> V_81 . V_82 . V_83 == 1 ) ;
}
static void
V_131 ( T_9 * V_67 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_166 . V_28 ;
T_1 * V_128 ;
int V_70 = V_71 ;
V_128 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_128 ) {
F_13 ( L_44 , V_28 ) ;
V_70 = - V_167 ;
goto V_75;
}
if ( V_128 -> V_46 . V_47 == 0 ) {
F_13 ( L_45 ,
V_28 ) ;
V_70 = - V_74 ;
goto V_75;
}
V_75:
F_47 ( V_28 , V_120 , & V_67 -> V_81 ,
V_70 , V_67 -> V_81 . V_82 . V_83 == 1 ) ;
}
static void
F_53 ( T_9 * V_67 , T_17 * V_168 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_169 . V_28 ;
T_1 * V_128 = NULL ;
int V_70 = V_71 ;
char V_1 [ 99 ] ;
V_28 = V_77 -> V_169 . V_28 ;
F_39 ( V_170 , V_28 , V_73 ) ;
V_128 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_128 ) {
F_13 ( L_46 ,
V_28 ) ;
F_39 ( V_171 , V_28 ,
V_43 ) ;
V_70 = - V_167 ;
goto V_75;
}
if ( V_128 -> V_46 . V_47 == 0 ) {
F_13 ( L_47 ,
V_28 ) ;
F_39 ( V_171 , V_28 ,
V_43 ) ;
V_70 = - V_167 ;
goto V_75;
}
if ( V_128 -> V_121 . V_93 != V_122 ) {
F_13 ( L_48 ,
V_28 , ( V_172 ) V_128 -> V_121 . V_93 ) ;
F_39 ( V_171 , V_28 ,
V_43 ) ;
V_70 = - V_173 ;
goto V_75;
}
V_128 -> V_27 = V_77 -> V_169 . V_174 ;
V_128 -> V_175 = F_54 ( V_168 ) ;
F_55 ( V_168 , V_176 ) ;
V_128 -> V_25 = F_56 ( V_168 ) ;
F_57 ( & V_128 -> V_175 , V_1 ) ;
V_128 -> V_45 =
F_58 ( V_177 , V_1 , ( void * ) ( V_128 ) ) ;
if ( V_128 -> V_45 == NULL ) {
F_13 ( L_49 ,
V_28 ) ;
F_39 ( V_171 , V_28 ,
V_43 ) ;
V_70 = - V_151 ;
goto V_75;
}
F_39 ( V_178 , V_28 , V_73 ) ;
V_75:
F_47 ( V_28 , V_179 , & V_67 -> V_81 ,
V_70 , V_67 -> V_81 . V_82 . V_83 == 1 ) ;
}
static void
F_59 ( T_9 * V_67 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_180 . V_28 ;
V_36 V_98 = V_77 -> V_180 . V_98 ;
T_4 * V_133 = NULL ;
T_1 * V_128 = NULL ;
int V_70 = V_71 ;
V_133 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( V_133 && ( V_133 -> V_46 . V_47 == 1 ) ) {
F_13 ( L_50 ,
V_28 , V_98 ) ;
F_60 ( V_181 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_74 ;
goto V_75;
}
V_128 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_128 ) {
F_13 ( L_51 ,
V_28 ) ;
F_60 ( V_181 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_167 ;
goto V_75;
}
if ( V_128 -> V_46 . V_47 == 0 ) {
F_13 ( L_52 ,
V_28 ) ;
F_60 ( V_181 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_167 ;
goto V_75;
}
V_133 = F_50 ( sizeof( T_4 ) , V_150 ) ;
if ( V_133 == NULL ) {
F_13 ( L_53 ,
V_28 , V_98 ) ;
F_60 ( V_181 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_151 ;
goto V_75;
}
F_51 ( & V_133 -> V_66 ) ;
V_133 -> V_28 = V_28 ;
V_133 -> V_98 = V_98 ;
V_133 -> V_182 = V_77 -> V_180 . V_182 ;
F_60 ( V_183 , V_98 , V_28 ,
V_73 ) ;
if ( V_67 -> V_81 . V_82 . V_100 == 1 )
V_133 -> V_154 . V_155 = V_156 ;
else
V_133 -> V_154 . V_155 = V_157 ;
V_133 -> V_154 . V_158 = V_77 -> V_180 . V_158 ;
V_133 -> V_154 . V_159 = V_77 -> V_180 . V_160 ;
V_133 -> V_154 . V_161 = V_77 -> V_180 . V_184 ;
V_133 -> V_154 . V_185 = V_77 -> V_180 . V_185 ;
F_52 ( & V_133 -> V_66 , & V_119 ) ;
F_60 ( V_186 , V_98 , V_28 ,
V_73 ) ;
V_75:
if ( F_61 ( V_133 -> V_154 . V_161 ) ) {
V_97 = V_28 ;
V_99 = V_98 ;
F_35 ( L_54 ,
V_97 , V_99 ) ;
}
F_48 ( V_28 , V_98 , V_137 ,
V_124 , & V_67 -> V_81 , V_70 ,
V_67 -> V_81 . V_82 . V_83 == 1 ,
F_62 ( V_133 -> V_154 . V_161 ) ) ;
}
static void
F_63 ( T_9 * V_67 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_96 . V_28 ;
V_36 V_98 = V_77 -> V_96 . V_98 ;
T_12 V_46 = V_77 -> V_96 . V_46 ;
T_4 * V_133 = NULL ;
int V_70 = V_71 ;
V_133 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_133 ) {
F_13 ( L_55 ,
V_28 , V_98 ) ;
F_60 ( V_187 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_188 ;
goto V_75;
}
if ( V_133 -> V_46 . V_47 == 0 ) {
F_13 ( L_56 ,
V_28 , V_98 ) ;
F_60 ( V_187 , V_98 , V_28 ,
V_43 ) ;
V_70 = - V_188 ;
}
V_75:
if ( ( V_70 >= V_71 ) && V_133 )
F_48 ( V_28 , V_98 , V_46 , V_94 ,
& V_67 -> V_81 , V_70 ,
V_67 -> V_81 . V_82 . V_83 == 1 ,
F_62 ( V_133 -> V_154 . V_161 ) ) ;
}
static void
F_64 ( T_9 * V_67 )
{
T_16 * V_77 = & V_67 -> V_77 ;
V_36 V_28 = V_77 -> V_189 . V_28 ;
V_36 V_98 = V_77 -> V_189 . V_98 ;
T_4 * V_133 = NULL ;
int V_70 = V_71 ;
V_133 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_133 ) {
F_13 ( L_57 ,
V_28 , V_98 ) ;
V_70 = - V_188 ;
goto V_75;
}
if ( V_133 -> V_46 . V_47 == 0 ) {
F_13 ( L_58 ,
V_28 , V_98 ) ;
V_70 = - V_74 ;
}
V_75:
if ( ( V_70 >= V_71 ) && V_133 )
F_48 ( V_28 , V_98 , V_137 ,
V_125 , & V_67 -> V_81 , V_70 ,
V_67 -> V_81 . V_82 . V_83 == 1 ,
F_62 ( V_133 -> V_154 . V_161 ) ) ;
}
static int
F_65 ( T_18 V_190 , T_19 V_191 , T_3 V_34 ,
T_20 * V_24 )
{
T_5 T_21 * V_192 = NULL ;
int V_70 = V_71 ;
if ( V_24 == NULL ) {
F_13 ( L_59 ,
__FILE__ , __LINE__ ) ;
V_70 = - V_193 ;
goto V_75;
}
memset ( V_24 , 0 , sizeof( T_20 ) ) ;
if ( ( V_191 == 0 ) || ( V_34 == 0 ) ) {
F_13 ( L_60 ,
( V_33 ) V_191 , ( V_33 ) V_34 ) ;
V_70 = - V_193 ;
goto V_75;
}
V_192 = F_66 ( V_190 + V_191 , V_34 ) ;
if ( V_192 == NULL ) {
F_13 ( L_61 ,
( V_33 ) V_191 , ( V_33 ) V_34 ) ;
V_70 = - V_194 ;
goto V_75;
}
V_24 -> V_191 = V_191 ;
V_24 -> V_34 = V_34 ;
V_24 -> V_195 = V_192 ;
F_35 ( L_62 ,
( V_33 ) ( V_24 -> V_191 ) , ( V_36 ) ( V_24 -> V_34 ) , V_24 -> V_195 ) ;
V_75:
if ( V_70 < 0 ) {
if ( V_192 != NULL ) {
F_67 ( V_192 ) ;
V_192 = NULL ;
}
}
return V_70 ;
}
static void
F_68 ( T_20 * V_24 )
{
if ( V_24 -> V_195 != NULL ) {
F_67 ( V_24 -> V_195 ) ;
V_24 -> V_195 = NULL ;
}
memset ( V_24 , 0 , sizeof( T_20 ) ) ;
}
static void
F_69 ( void )
{
T_18 V_190 = F_8 ( V_29 ) ;
T_19 V_196 = 0 ;
T_3 V_197 = 0 ;
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_198 ) ,
& V_196 , sizeof( V_196 ) ) < 0 ) {
F_13 ( L_63 ) ;
F_14 ( V_199 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_200 ) ,
& V_197 , sizeof( V_197 ) ) < 0 ) {
F_13 ( L_63 ) ;
F_14 ( V_199 ,
V_43 ) ;
return;
}
F_65 ( V_190 ,
V_196 , V_197 ,
& V_201 ) ;
}
int
F_70 ( void )
{
F_71 ( & V_143 . V_144 . V_145 , V_146 ) ;
return V_71 ;
}
int
F_72 ( void )
{
char V_202 [ 20 ] ;
char * V_134 [] = { V_202 , NULL } ;
sprintf ( V_202 , L_64 , 1 ) ;
F_49 ( & V_143 . V_144 . V_145 , V_203 ,
V_134 ) ;
return V_71 ;
}
int
F_73 ( void )
{
F_71 ( & V_143 . V_144 . V_145 , V_204 ) ;
return V_71 ;
}
static void
F_74 ( T_11 * V_85 )
{
int V_70 = F_70 () ;
if ( V_70 != V_71 )
V_70 = - V_70 ;
if ( V_85 -> V_82 . V_83 && ! V_205 )
F_34 ( V_85 , V_70 ) ;
if ( V_85 -> V_82 . V_83 && V_205 ) {
V_206 = * V_85 ;
F_35 ( L_65 ) ;
}
}
static void
F_75 ( T_11 * V_85 )
{
int V_70 = F_72 () ;
if ( V_70 != V_71 )
V_70 = - V_70 ;
if ( V_85 -> V_82 . V_83 )
F_34 ( V_85 , V_70 ) ;
}
static void
F_76 ( T_11 * V_85 )
{
int V_70 = F_73 () ;
if ( V_70 != V_71 )
V_70 = - V_70 ;
if ( V_85 -> V_82 . V_83 )
F_34 ( V_85 , V_70 ) ;
}
static BOOL
F_77 ( T_9 * V_84 )
{
if ( F_78 ( V_29 ,
V_207 , V_84 ) ) {
if ( V_84 -> V_81 . V_82 . V_100 == 1 ) {
F_13 ( L_66 , V_84 -> V_81 . V_93 ) ;
return FALSE ;
} else
return TRUE ;
}
return FALSE ;
}
static int
F_79 ( void )
{
static T_22 V_208 = F_80 ( 0 ) ;
return F_81 ( & V_208 ) ;
}
static unsigned long
F_82 ( void )
{
return V_209 + V_210 * V_211 / 1000 ;
}
static struct V_212 *
F_83 ( T_9 * V_84 )
{
struct V_212 * V_213 =
F_84 ( sizeof( struct V_212 ) ,
V_150 | V_214 ) ;
if ( V_213 == NULL )
return NULL ;
V_213 -> V_208 = F_79 () ;
V_213 -> V_215 = F_82 () ;
V_213 -> V_84 = * V_84 ;
return V_213 ;
}
static void
F_85 ( struct V_212 * V_213 )
{
F_19 ( V_213 ) ;
}
static void
F_86 ( struct V_212 * V_213 )
{
T_16 * V_77 = & V_213 -> V_84 . V_77 ;
char V_216 [ 40 ] , V_217 [ 40 ] , V_218 [ 40 ] , V_219 [ 40 ] , V_220 [ 40 ] ,
V_221 [ 40 ] ;
char * V_134 [] = {
V_216 , V_217 , V_218 , V_219 , V_220 , V_221 , NULL
} ;
sprintf ( V_216 , L_67 ) ;
sprintf ( V_217 , L_68 , V_213 -> V_208 ) ;
sprintf ( V_218 , L_69 ,
V_77 -> V_96 . V_46 . V_222 ) ;
sprintf ( V_219 , L_70 ,
V_77 -> V_96 . V_28 ) ;
sprintf ( V_220 , L_71 ,
V_77 -> V_96 . V_98 >> 3 ) ;
sprintf ( V_221 , L_72 ,
V_77 -> V_96 . V_98 & 0x7 ) ;
F_35 ( L_73 ,
V_77 -> V_96 . V_46 . V_222 ,
V_77 -> V_96 . V_28 , V_77 -> V_96 . V_98 >> 3 ,
V_77 -> V_96 . V_98 & 7 , V_213 -> V_208 ) ;
F_49 ( & V_143 . V_144 . V_145 , V_203 ,
V_134 ) ;
}
static void
F_87 ( void )
{
struct V_223 * V_224 = NULL ;
struct V_223 * V_225 = NULL ;
F_88 ( & V_226 ) ;
F_89 (pos, tmp, &Parahotplug_request_list) {
struct V_212 * V_213 =
F_90 ( V_224 , struct V_212 , V_227 ) ;
if ( F_91 ( V_209 , V_213 -> V_215 ) ) {
F_30 ( V_224 ) ;
if ( V_213 -> V_84 . V_81 . V_82 . V_83 )
F_37 (
& V_213 -> V_84 . V_81 ,
V_228 ,
V_213 -> V_84 . V_77 . V_96 . V_46 ) ;
F_85 ( V_213 ) ;
}
}
F_92 ( & V_226 ) ;
}
static int
F_93 ( int V_208 , T_14 V_229 )
{
struct V_223 * V_224 = NULL ;
struct V_223 * V_225 = NULL ;
F_88 ( & V_226 ) ;
F_89 (pos, tmp, &Parahotplug_request_list) {
struct V_212 * V_213 =
F_90 ( V_224 , struct V_212 , V_227 ) ;
if ( V_213 -> V_208 == V_208 ) {
F_30 ( V_224 ) ;
F_92 ( & V_226 ) ;
V_213 -> V_84 . V_77 . V_96 . V_46 . V_222 = V_229 ;
if ( V_213 -> V_84 . V_81 . V_82 . V_83 )
F_37 (
& V_213 -> V_84 . V_81 , V_71 ,
V_213 -> V_84 . V_77 . V_96 . V_46 ) ;
F_85 ( V_213 ) ;
return 0 ;
}
}
F_92 ( & V_226 ) ;
return - 1 ;
}
static void
F_94 ( T_9 * V_67 )
{
struct V_212 * V_213 ;
V_213 = F_83 ( V_67 ) ;
if ( V_213 == NULL ) {
F_13 ( L_74 ) ;
return;
}
if ( V_67 -> V_77 . V_96 . V_46 . V_222 ) {
F_86 ( V_213 ) ;
F_37 ( & V_67 -> V_81 ,
V_71 ,
V_67 -> V_77 .
V_96 . V_46 ) ;
F_85 ( V_213 ) ;
} else {
F_88 ( & V_226 ) ;
F_95 ( & ( V_213 -> V_227 ) , & V_230 ) ;
F_92 ( & V_226 ) ;
F_86 ( V_213 ) ;
}
}
static T_23
F_96 ( struct V_231 * V_231 , const char T_24 * V_232 ,
T_25 V_233 , T_26 * V_234 )
{
char V_235 [ 64 ] ;
V_172 V_208 ;
T_27 V_229 ;
if ( V_233 > sizeof( V_235 ) - 1 ) {
F_13 ( L_75 ,
( int ) V_233 , ( int ) sizeof( V_235 ) ) ;
return - V_236 ;
}
if ( F_97 ( V_235 , V_232 , V_233 ) ) {
F_13 ( L_76 ) ;
return - V_237 ;
}
V_235 [ V_233 ] = '\0' ;
if ( sscanf ( V_235 , L_77 , & V_208 , & V_229 ) != 2 ) {
V_208 = 0 ;
V_229 = 0 ;
}
if ( V_229 != 1 && V_229 != 0 ) {
F_13 ( L_78 ) ;
return - V_236 ;
}
F_93 ( ( int ) V_208 , ( T_14 ) V_229 ) ;
return V_233 ;
}
static BOOL
F_98 ( T_9 V_67 , T_18 V_238 )
{
T_16 * V_77 = & V_67 . V_77 ;
T_19 V_239 = 0 ;
T_3 V_240 = 0 ;
T_17 * V_168 = NULL ;
BOOL V_241 = FALSE ;
T_9 V_242 ;
V_241 = ( V_67 . V_81 . V_82 . V_100 == 1 ) ;
if ( V_238 == 0 ) {
F_13 ( L_79 ) ;
return TRUE ;
}
V_239 = V_238 + V_67 . V_81 . V_88 ;
V_240 = V_67 . V_81 . V_87 ;
if ( V_239 != 0 && V_240 != 0 ) {
BOOL V_243 = FALSE ;
V_168 =
F_99 ( V_239 , V_240 ,
V_241 , & V_243 ) ;
if ( ! V_168 ) {
if ( V_243 ) {
F_100 ( L_80 ) ;
return FALSE ;
}
F_100 ( L_81 ) ;
F_100 ( L_82 , ( V_36 ) V_67 . V_81 . V_93 ) ;
F_100 ( L_83 , ( V_33 ) V_239 ) ;
F_100 ( L_84 , ( V_36 ) V_240 ) ;
F_100 ( L_85 , V_241 ) ;
}
}
if ( ! V_241 ) {
F_33 ( & V_242 , & V_67 . V_81 ,
V_71 ) ;
if ( ( V_29 )
&&
( ! F_36
( V_29 , V_244 , & V_242 ) ) )
F_100 ( L_86 ) ;
}
switch ( V_67 . V_81 . V_93 ) {
case V_245 :
F_35 ( L_87 ,
( V_36 ) V_67 . V_77 . V_78 . V_246 ,
( V_36 ) V_67 . V_77 . V_78 . V_247 ) ;
F_31 ( & V_67 ) ;
break;
case V_118 :
F_35 ( L_88 ,
( V_36 ) V_77 -> V_148 . V_28 ,
( V_36 ) V_77 -> V_148 . V_152 ) ;
V_129 ( & V_67 ) ;
break;
case V_120 :
F_35 ( L_89 , ( V_36 ) V_77 -> V_166 . V_28 ) ;
V_131 ( & V_67 ) ;
break;
case V_179 :
F_35 ( L_90 , ( V_36 ) V_77 -> V_169 . V_28 ) ;
F_53 ( & V_67 , V_168 ) ;
break;
case V_124 :
F_35 ( L_91 ,
( V_36 ) V_77 -> V_180 . V_28 ,
( V_36 ) V_77 -> V_180 . V_98 ) ;
F_59 ( & V_67 ) ;
break;
case V_94 :
if ( V_77 -> V_96 . V_103 . V_104 ) {
F_35 ( L_92 ,
( V_36 ) V_77 -> V_96 . V_28 ,
( V_36 ) V_77 -> V_96 . V_98 ,
( V_36 ) V_77 -> V_96 . V_46 . V_222 ) ;
F_94 ( & V_67 ) ;
} else {
F_35 ( L_93 ,
( V_36 ) V_77 -> V_96 . V_28 ,
( V_36 ) V_77 -> V_96 . V_98 ,
( V_36 ) V_77 -> V_96 . V_46 . V_136 ) ;
F_63 ( & V_67 ) ;
V_248 = V_67 . V_81 ;
V_95 = V_67 . V_77 ;
break;
}
break;
case V_125 :
F_35 ( L_94 ,
( V_36 ) V_77 -> V_189 . V_28 ,
( V_36 ) V_77 -> V_189 . V_98 ) ;
F_64 ( & V_67 ) ;
break;
case V_249 :
F_35 ( L_95 ,
( V_36 ) V_77 -> V_250 . V_28 ,
( V_36 ) V_77 -> V_250 . V_98 ) ;
if ( V_67 . V_81 . V_82 . V_83 )
F_34 ( & V_67 . V_81 , V_71 ) ;
break;
case V_251 :
F_35 ( L_96 ) ;
F_74 ( & V_67 . V_81 ) ;
break;
case V_252 :
F_35 ( L_97 ) ;
F_75 ( & V_67 . V_81 ) ;
break;
case V_253 :
F_35 ( L_98 ) ;
F_76 ( & V_67 . V_81 ) ;
break;
default:
F_13 ( L_99 , ( int ) V_67 . V_81 . V_93 ) ;
if ( V_67 . V_81 . V_82 . V_83 )
F_34 ( & V_67 . V_81 ,
- V_254 ) ;
break;
}
if ( V_168 != NULL ) {
F_101 ( V_168 ) ;
V_168 = NULL ;
}
return TRUE ;
}
static void
F_102 ( struct V_255 * V_256 )
{
T_28 V_154 ;
T_9 V_67 ;
char V_1 [ 99 ] ;
BOOL V_257 = FALSE ;
BOOL V_258 = FALSE ;
static T_19 V_259 ;
if ( V_260 && ! V_57 )
goto V_75;
if ( V_261 && ! V_61 )
goto V_75;
memset ( & V_154 , 0 , sizeof( T_28 ) ) ;
if ( ! V_29 ) {
T_18 V_30 = F_103 () ;
if ( V_30 != 0 ) {
V_29 =
F_104
( V_30 ,
sizeof( V_31 ) ,
V_262 ) ;
if ( V_29 == NULL )
F_13 ( L_100 ) ;
else if ( F_105
( F_106 ( V_29 ) ,
NULL ) ) {
F_35 ( L_101 ,
F_107 ( V_29 , V_1 ) ) ;
F_69 () ;
} else {
F_13 ( L_102 ) ;
F_108 ( V_29 ) ;
V_29 = NULL ;
}
}
}
V_259 ++ ;
if ( ( V_29 != NULL ) || ( V_259 >= 250 ) )
;
else
goto V_75;
if ( V_205
&& ( V_206 . V_93 != V_122 ) ) {
if ( F_21 () == 1 ) {
F_35 ( L_103 ) ;
F_34 ( & V_206 , 0 ) ;
F_22 () ;
memset ( & V_206 , 0 ,
sizeof( T_11 ) ) ;
}
}
if ( V_29 ) {
while ( F_78 ( V_29 ,
V_263 ,
& V_67 ) ) {
if ( V_67 . V_81 . V_89 != 0 ) {
F_13 ( L_104 ,
( V_36 ) V_67 . V_81 . V_89 ,
( V_36 ) V_67 . V_81 . V_88 ,
V_67 . V_81 . V_93 ) ;
}
}
if ( ! V_257 ) {
if ( V_264 ) {
V_67 = V_265 ;
V_264 = FALSE ;
V_257 = TRUE ;
} else
V_257 = F_77 ( & V_67 ) ;
}
}
V_258 = FALSE ;
while ( V_257 && ( ! V_258 ) ) {
V_266 = V_209 ;
if ( V_29 ) {
if ( F_98 ( V_67 ,
F_8
( V_29 ) ) )
V_257 = F_77 ( & V_67 ) ;
else {
V_258 = TRUE ;
V_265 = V_67 ;
V_264 = TRUE ;
}
} else {
F_98 ( V_67 , 0 ) ;
V_257 = FALSE ;
}
}
F_87 () ;
V_75:
if ( F_109 ( V_209 ,
V_266 + ( V_211 * V_267 ) ) ) {
if ( V_268 != V_269 ) {
F_35 ( L_105 ) ;
V_268 = V_269 ;
}
} else {
if ( V_268 != V_270 ) {
V_268 = V_270 ;
F_35 ( L_106 ) ;
}
}
F_110 ( V_271 ,
& V_272 , V_268 ) ;
}
static void
F_111 ( struct V_255 * V_256 )
{
T_9 V_273 ;
T_9 V_274 ;
T_9 V_84 ;
T_18 V_275 ;
T_3 V_105 ;
T_14 V_106 ;
if ( V_260 && ! V_57 )
goto V_75;
if ( V_261 && ! V_61 )
goto V_75;
F_14 ( V_276 , V_73 ) ;
V_84 . V_81 . V_93 = V_245 ;
V_84 . V_77 . V_78 . V_246 = 23 ;
V_84 . V_77 . V_78 . V_247 = 0 ;
F_31 ( & V_84 ) ;
V_275 = F_103 () ;
if ( ! V_275 ) {
F_13 ( L_107 ) ;
F_14 ( V_277 , V_43 ) ;
return;
}
V_29 =
F_104
( V_275 ,
sizeof( V_31 ) ,
V_262 ) ;
if ( V_29 == NULL ) {
F_13 ( L_100 ) ;
F_14 ( V_278 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_107 ) ,
& V_106 , sizeof( T_14 ) ) < 0 ) {
F_13 ( L_28 ) ;
F_14 ( V_108 ,
V_43 ) ;
return;
}
if ( V_106 != V_109 ) {
F_13 ( L_29 ,
V_106 ) ;
F_39 ( V_110 ,
V_106 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
F_10 ( V_31 ,
V_111 ) ,
& V_105 , sizeof( T_3 ) ) < 0 ) {
F_13 ( L_30 ) ;
F_14 ( V_108 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
V_105 ,
& V_273 ,
sizeof( T_9 ) ) < 0 ) {
F_13 ( L_108 ) ;
F_14 ( V_279 ,
V_43 ) ;
return;
}
if ( F_9 ( V_29 ,
V_105 +
sizeof( T_9 ) ,
& V_274 ,
sizeof( T_9 ) ) < 0 ) {
F_13 ( L_109 ) ;
F_14 ( V_280 ,
V_43 ) ;
return;
}
if ( V_273 . V_77 . V_148 . V_158 != 0 )
V_129 ( & V_273 ) ;
else {
F_13 ( L_110 ) ;
F_14 ( V_281 ,
V_43 ) ;
return;
}
if ( V_274 . V_77 . V_180 . V_158 != 0 )
F_59 ( & V_274 ) ;
else {
F_13 ( L_111 ) ;
F_14 ( V_282 ,
V_43 ) ;
return;
}
F_35 ( L_112 ) ;
F_14 ( V_283 , V_73 ) ;
return;
V_75:
V_268 = V_269 ;
F_110 ( V_271 ,
& V_272 , V_268 ) ;
}
static void
F_112 ( V_36 V_28 , int V_86 )
{
F_41 ( V_118 , V_28 , V_86 ) ;
}
static void
F_113 ( V_36 V_28 , int V_86 )
{
F_41 ( V_120 , V_28 , V_86 ) ;
}
static void
F_114 ( V_36 V_28 , V_36 V_98 , int V_86 )
{
F_46 ( V_124 , V_28 , V_98 , V_86 ) ;
}
static void
F_115 ( V_36 V_28 , V_36 V_98 , int V_86 )
{
F_46 ( V_125 , V_28 , V_98 , V_86 ) ;
}
void
F_116 ( V_36 V_28 , V_36 V_98 , int V_86 )
{
F_44 ( V_94 ,
V_28 , V_98 , V_86 ,
V_140 ) ;
}
static void
F_117 ( V_36 V_28 , V_36 V_98 , int V_86 )
{
F_44 ( V_94 ,
V_28 , V_98 , V_86 ,
V_137 ) ;
}
BOOL
F_118 ( V_36 V_28 , T_1 * V_284 )
{
void * V_2 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_2 ) {
F_13 ( L_113 , V_28 ) ;
return FALSE ;
}
memcpy ( V_284 , V_2 , sizeof( T_1 ) ) ;
return TRUE ;
}
BOOL
F_119 ( V_36 V_28 , void * V_285 )
{
T_1 * V_2 = F_42 ( & V_117 , V_28 ) ;
if ( ! V_2 ) {
F_13 ( L_113 , V_28 ) ;
return FALSE ;
}
V_2 -> V_286 = V_285 ;
return TRUE ;
}
BOOL
F_120 ( V_36 V_28 , V_36 V_98 ,
T_4 * V_287 )
{
void * V_2 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_2 ) {
F_13 ( L_114 , V_28 , V_98 ) ;
return FALSE ;
}
memcpy ( V_287 , V_2 , sizeof( T_4 ) ) ;
return TRUE ;
}
BOOL
F_121 ( V_36 V_28 , V_36 V_98 , void * V_285 )
{
T_4 * V_2 = F_45 ( & V_119 , V_28 , V_98 ) ;
if ( ! V_2 ) {
F_13 ( L_114 , V_28 , V_98 ) ;
return FALSE ;
}
V_2 -> V_286 = V_285 ;
return TRUE ;
}
void *
F_122 ( struct V_288 * V_289 , BOOL V_290 ,
char * V_291 , int V_292 )
{
T_29 V_293 ;
void * V_2 ;
if ( V_290 )
V_293 = V_150 ;
else
V_293 = V_294 ;
V_293 |= V_214 ;
V_2 = F_123 ( V_289 , V_293 ) ;
if ( ! V_2 ) {
F_13 ( L_115 , V_291 , V_292 ) ;
return NULL ;
}
F_124 ( & V_295 ) ;
return V_2 ;
}
void
F_125 ( struct V_288 * V_289 , void * V_2 , char * V_291 , int V_292 )
{
if ( ! V_2 ) {
F_13 ( L_116 , V_291 , V_292 ) ;
return;
}
F_126 ( & V_295 ) ;
F_127 ( V_289 , V_2 ) ;
}
static T_23
F_128 ( struct V_231 * V_231 , const char T_24 * V_232 ,
T_25 V_233 , T_26 * V_234 )
{
char V_235 [ 512 ] ;
char * V_296 , * V_2 ;
if ( V_233 > sizeof( V_235 ) - 1 ) {
F_13 ( L_117 ,
( int ) V_233 , ( int ) sizeof( V_232 ) ) ;
return - V_236 ;
}
if ( F_97 ( V_235 , V_232 , V_233 ) ) {
F_13 ( L_118 ) ;
return - V_237 ;
}
V_235 [ V_233 ] = '\0' ;
V_2 = V_235 ;
V_296 = F_129 ( & V_2 ) ;
if ( strcmp ( V_296 , L_119 ) == 0 ) {
V_296 = F_129 ( & V_2 ) ;
if ( strcmp ( V_296 , L_120 ) == 0 )
V_51 [ 0 ] = 1 ;
} else if ( strcmp ( V_296 , L_121 ) == 0 ) {
V_296 = F_129 ( & V_2 ) ;
if ( strcmp ( V_296 , L_120 ) == 0 )
V_51 [ 1 ] = 1 ;
} else if ( V_296 == NULL ) {
F_13 ( L_122 ) ;
return - 1 ;
} else {
F_13 ( L_123 , V_296 ) ;
return - 1 ;
}
return V_233 ;
}
static T_23
F_130 ( struct V_231 * V_231 , char T_24 * V_235 ,
T_25 V_297 , T_26 * V_191 )
{
return 0 ;
}
static T_23
F_131 ( struct V_231 * V_231 , char T_24 * V_235 ,
T_25 V_297 , T_26 * V_191 )
{
int V_38 = 0 ;
T_14 V_298 ;
T_3 error , V_299 ;
char * V_300 ;
T_26 V_224 = * V_191 ;
if ( ! V_29 )
return - V_301 ;
if ( V_224 < 0 )
return - V_236 ;
if ( V_224 > 0 || ! V_297 )
return 0 ;
V_300 = F_50 ( V_297 , V_150 ) ;
if ( ! V_300 )
return - V_302 ;
F_9 ( V_29 ,
F_10 ( V_31 ,
V_303 ) , & V_298 ,
sizeof( T_14 ) ) ;
F_9 ( V_29 ,
F_10 ( V_31 ,
V_304 ) , & error , sizeof( T_3 ) ) ;
F_9 ( V_29 ,
F_10 ( V_31 ,
V_305 ) , & V_299 , sizeof( T_3 ) ) ;
V_38 = sprintf ( V_300 , L_124 , V_298 , error , V_299 ) ;
if ( F_132 ( V_235 , V_300 , V_38 ) ) {
F_19 ( V_300 ) ;
return - V_237 ;
}
F_19 ( V_300 ) ;
* V_191 += V_38 ;
return V_38 ;
}
static T_23
F_133 ( struct V_231 * V_231 ,
const char T_24 * V_232 , T_25 V_233 , T_26 * V_234 )
{
char V_235 [ 32 ] ;
T_14 V_298 ;
T_3 error , V_299 ;
if ( ! V_29 )
return - V_301 ;
if ( V_233 > ( sizeof( V_235 ) - 1 ) )
return - V_236 ;
if ( F_97 ( V_235 , V_232 , V_233 ) ) {
F_134 ( 1 , L_125 ) ;
return - V_237 ;
}
if ( sscanf ( V_235 , L_126 , & V_298 , & error , & V_299 ) != 3 ) {
V_298 = V_306 ;
error = V_307 ;
V_299 = V_307 ;
}
if ( V_298 != V_306 ) {
if ( F_40
( V_29 ,
F_10 ( V_31 ,
V_303 ) , & V_298 ,
sizeof( T_14 ) ) < 0 )
F_134 ( 1 , L_127 ,
V_298 ) ;
}
if ( error != V_307 ) {
if ( F_40
( V_29 ,
F_10 ( V_31 ,
V_304 ) , & error , sizeof( T_3 ) ) < 0 )
F_134 ( 1 , L_128 ,
error ) ;
}
if ( V_299 != V_307 ) {
if ( F_40
( V_29 ,
F_10 ( V_31 ,
V_305 ) , & V_299 , sizeof( T_3 ) ) < 0 )
F_134 ( 1 , L_129 ,
V_299 ) ;
}
return V_233 ;
}
static T_23
F_135 ( struct V_231 * V_231 , char T_24 * V_235 ,
T_25 V_297 , T_26 * V_191 )
{
int V_38 = 0 ;
T_5 V_308 ;
char * V_300 ;
T_26 V_224 = * V_191 ;
if ( ! V_29 )
return - V_301 ;
if ( V_224 < 0 )
return - V_236 ;
if ( V_224 > 0 || ! V_297 )
return 0 ;
V_300 = F_50 ( V_297 , V_150 ) ;
if ( ! V_300 )
return - V_302 ;
F_9 ( V_29 ,
F_10 ( V_31 ,
V_309 ) , & V_308 , sizeof( T_5 ) ) ;
V_38 = sprintf ( V_300 , L_130 , V_308 ) ;
if ( F_132 ( V_235 , V_300 , V_38 ) ) {
F_19 ( V_300 ) ;
return - V_237 ;
}
F_19 ( V_300 ) ;
* V_191 += V_38 ;
return V_38 ;
}
static T_23
F_136 ( struct V_231 * V_231 ,
const char T_24 * V_232 , T_25 V_233 , T_26 * V_234 )
{
char V_235 [ 3 ] ;
T_5 V_308 ;
if ( ! V_29 )
return - V_301 ;
if ( V_233 > ( sizeof( V_235 ) - 1 ) )
return - V_236 ;
if ( F_97 ( V_235 , V_232 , V_233 ) ) {
F_134 ( 1 , L_125 ) ;
return - V_237 ;
}
if ( sscanf ( V_235 , L_131 , & V_308 ) != 1 )
V_308 = V_310 ;
if ( V_308 != V_310 ) {
if ( F_40
( V_29 ,
F_10 ( V_31 , V_309 ) ,
& V_308 , sizeof( T_5 ) ) < 0 )
F_134 ( 1 , L_132 ,
V_308 ) ;
}
return V_233 ;
}
static T_23
F_137 ( struct V_231 * V_231 , char T_24 * V_235 ,
T_25 V_297 , T_26 * V_191 )
{
int V_38 = 0 ;
T_30 V_311 ;
char * V_300 ;
T_26 V_224 = * V_191 ;
if ( ! V_29 )
return - V_301 ;
if ( V_224 < 0 )
return - V_236 ;
if ( V_224 > 0 || ! V_297 )
return 0 ;
V_300 = F_50 ( V_297 , V_150 ) ;
if ( ! V_300 )
return - V_302 ;
F_9 ( V_29 ,
F_10 ( V_31 ,
V_312 ) , & V_311 ,
sizeof( T_30 ) ) ;
V_38 = sprintf ( V_300 , L_15 , ( int ) V_311 . V_313 ) ;
if ( F_132 ( V_235 , V_300 , V_38 ) ) {
F_19 ( V_300 ) ;
return - V_237 ;
}
F_19 ( V_300 ) ;
* V_191 += V_38 ;
return V_38 ;
}
static T_23
F_138 ( struct V_231 * V_231 ,
const char T_24 * V_232 , T_25 V_233 , T_26 * V_234 )
{
char V_235 [ 3 ] ;
int V_314 ;
T_30 V_311 ;
if ( ! V_29 )
return - V_301 ;
if ( V_233 > ( sizeof( V_235 ) - 1 ) )
return - V_236 ;
if ( F_97 ( V_235 , V_232 , V_233 ) ) {
F_134 ( 1 , L_125 ) ;
return - V_237 ;
}
if ( sscanf ( V_235 , L_133 , & V_314 ) != 1 )
V_314 = 0 ;
V_311 . V_313 = ( V_314 == 1 ? 1 : 0 ) ;
if ( F_40
( V_29 ,
F_10 ( V_31 , V_312 ) ,
& V_311 , sizeof( T_30 ) ) < 0 )
F_139
( L_134 ,
( int ) V_311 . V_313 ) ;
return V_233 ;
}
static int T_31
F_140 ( void )
{
int V_70 = 0 , V_315 = 0 ;
struct V_316 * V_317 ;
struct V_316 * V_318 ;
struct V_316 * V_319 ;
F_35 ( L_135 , V_59 ) ;
F_14 ( V_320 , V_73 ) ;
F_35 ( L_136 , V_321 ) ;
F_35 ( L_137 , V_322 ) ;
F_35 ( L_138 , V_323 ) ;
F_35 ( L_139 , V_324 ) ;
F_35 ( L_140 , V_325 ) ;
F_35 ( L_141 , V_260 ) ;
F_35 ( L_142 , V_261 ) ;
F_35 ( L_143 , V_205 ) ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
F_141 ( & V_37 . V_326 , 0 ) ;
if ( V_321 ) {
F_142 ( L_144 ,
V_315 ) ;
F_39 ( V_42 , V_315 , V_327 ) ;
V_70 = V_315 ;
goto V_75;
}
F_143 () ;
V_328 = F_144 ( V_325 , 0 ) ;
V_70 = F_145 ( V_328 , & V_29 ) ;
if ( V_70 < 0 ) {
F_142 ( L_145 , V_70 ) ;
F_14 ( V_42 , V_327 ) ;
goto V_75;
}
F_11 () ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
F_2 () ;
F_3 () ;
V_177 = F_146 ( V_40 , V_329 ,
( const char * * )
V_3 ,
& F_4 ) ;
V_330 =
F_146 ( V_40 , V_331 ,
( const char * * ) V_10 ,
& F_6 ) ;
V_332 = F_58 ( V_330 , NULL , NULL ) ;
V_317 = F_147 ( L_146 , 0644 , V_40 ,
& V_333 ) ;
V_318 = F_147 ( L_147 , 0644 , V_40 ,
& V_334 ) ;
V_319 = F_147 ( L_148 , 0644 , V_40 ,
& V_335 ) ;
memset ( & V_248 , 0 , sizeof( T_11 ) ) ;
V_336 = F_147 ( V_337 ,
0644 , V_40 , & V_338 ) ;
memset ( & V_206 , 0 , sizeof( T_11 ) ) ;
V_339 =
F_147 ( V_340 , 0200 ,
V_40 , & V_341 ) ;
memset ( & V_342 , 0 , sizeof( T_11 ) ) ;
if ( F_148 ( sizeof( struct V_343 ) ) < 0 ) {
F_142 ( L_149 ) ;
F_14 ( V_42 , V_327 ) ;
V_70 = - 1 ;
goto V_75;
}
V_344 =
F_149 ( V_345 ,
sizeof( struct V_346 ) ,
0 , V_347 , NULL ) ;
if ( ! V_344 ) {
F_142 ( L_150 ) ;
F_14 ( V_42 , V_327 ) ;
V_70 = - 1 ;
goto V_75;
}
if ( V_348 ) {
F_35 ( L_151 ) ;
} else {
if ( V_349 )
F_150 ( & V_272 ,
F_111 ) ;
else
F_150 ( & V_272 ,
F_102 ) ;
V_271 =
F_151 ( L_152 ) ;
if ( V_271 == NULL ) {
F_142 ( L_153 ,
- V_302 ) ;
F_14 ( V_350 ,
V_327 ) ;
V_70 = - V_302 ;
goto V_75;
}
V_266 = V_209 ;
V_268 = V_270 ;
V_70 = F_110 ( V_271 ,
& V_272 , V_268 ) ;
if ( V_70 < 0 ) {
F_142 ( L_154 , V_70 ) ;
F_14 ( V_351 ,
V_327 ) ;
goto V_75;
}
}
V_143 . V_144 . V_352 = V_328 ;
if ( F_152 ( & V_143 ) < 0 ) {
F_142 ( L_155 ) ;
F_14 ( V_353 , V_327 ) ;
V_70 = - 1 ;
goto V_75;
}
F_35 ( L_156 ) ;
F_14 ( V_354 , V_73 ) ;
V_70 = 0 ;
V_75:
if ( V_70 ) {
F_13 ( L_157 ) ;
F_39 ( V_42 , V_70 ,
V_43 ) ;
}
return V_70 ;
}
static void
F_153 ( void )
{
char V_1 [ 99 ] ;
F_14 ( V_355 , V_73 ) ;
if ( V_348 ) {
;
} else {
F_154 ( & V_272 ) ;
F_155 ( V_271 ) ;
F_156 ( V_271 ) ;
V_271 = NULL ;
F_68 ( & V_201 ) ;
}
V_356 = NULL ;
if ( V_344 ) {
F_157 ( V_344 ) ;
V_344 = NULL ;
}
F_158 () ;
if ( V_332 ) {
F_18 ( V_332 ) ;
V_332 = NULL ;
}
F_28 () ;
if ( V_330 ) {
F_159 ( V_330 ) ;
V_330 = NULL ;
}
if ( V_177 ) {
F_159 ( V_177 ) ;
V_177 = NULL ;
}
if ( V_357 ) {
F_16 ( V_358 , V_40 ) ;
V_357 = NULL ;
}
memset ( & V_248 , 0 , sizeof( T_11 ) ) ;
if ( V_336 ) {
F_16 ( V_337 , V_40 ) ;
V_336 = NULL ;
}
memset ( & V_206 , 0 , sizeof( T_11 ) ) ;
if ( V_339 ) {
F_16 ( V_340 ,
V_40 ) ;
V_339 = NULL ;
}
memset ( & V_342 , 0 , sizeof( T_11 ) ) ;
F_15 () ;
if ( V_29 != NULL ) {
F_35 ( L_158 ,
F_107 ( V_29 , V_1 ) ) ;
F_108 ( V_29 ) ;
V_29 = NULL ;
}
F_160 () ;
F_161 () ;
F_14 ( V_355 , V_73 ) ;
F_35 ( L_159 ) ;
}
