static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
unsigned long V_4 ;
if ( ! F_2 ( V_1 , 0 , & V_4 ) )
V_5 = V_4 ? 1 : 0 ;
return 1 ;
}
static int F_4 ( void )
{
return ( F_5 ( & V_6 ) > 0 ) ;
}
static void F_6 ( void )
{
struct V_7 * V_7 = (struct V_7 * ) V_8 -> V_9 ;
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
F_8 ( L_1 ) ;
V_11 -> V_13 = V_11 -> V_14 = V_15 ;
V_7 -> V_16 = V_11 ;
}
static inline T_2 F_9 ( const struct V_7 * V_7 )
{
const struct V_10 * V_11 ;
V_11 = V_7 -> V_16 ;
return V_11 -> V_14 ;
}
static inline T_2 F_10 ( const struct V_17 * V_18 )
{
T_2 V_14 ;
F_11 () ;
V_14 = F_9 ( F_12 ( V_18 ) ) ;
F_13 () ;
return V_14 ;
}
static inline T_2 F_14 ( void )
{
const struct V_10 * V_11 = F_15 () ;
return V_11 -> V_14 ;
}
static int F_16 ( struct V_19 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_14 = F_14 () ;
V_21 = F_17 ( V_22 , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
F_18 ( & V_21 -> V_25 ) ;
F_19 ( & V_21 -> V_26 ) ;
V_21 -> V_19 = V_19 ;
V_21 -> V_14 = V_27 ;
V_21 -> V_28 = V_29 ;
V_21 -> F_10 = V_14 ;
V_19 -> V_30 = V_21 ;
return 0 ;
}
static void F_20 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 = V_19 -> V_33 -> V_34 ;
F_21 ( & V_32 -> V_35 ) ;
if ( ! F_22 ( & V_21 -> V_26 ) )
F_23 ( & V_21 -> V_26 ) ;
F_24 ( & V_32 -> V_35 ) ;
V_19 -> V_30 = NULL ;
F_25 ( V_22 , V_21 ) ;
}
static int F_26 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
T_2 V_14 = F_14 () ;
V_38 = F_7 ( sizeof( struct V_37 ) , V_12 ) ;
if ( ! V_38 )
return - V_24 ;
V_38 -> V_14 = V_14 ;
V_38 -> V_39 = V_14 ;
V_36 -> V_40 = V_38 ;
return 0 ;
}
static void F_27 ( struct V_36 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
V_36 -> V_40 = NULL ;
F_28 ( V_38 ) ;
}
static int F_29 ( struct V_41 * V_42 )
{
struct V_31 * V_32 ;
V_32 = F_7 ( sizeof( struct V_31 ) , V_12 ) ;
if ( ! V_32 )
return - V_24 ;
F_18 ( & V_32 -> V_25 ) ;
F_19 ( & V_32 -> V_43 ) ;
F_30 ( & V_32 -> V_35 ) ;
V_32 -> V_42 = V_42 ;
V_32 -> V_14 = V_27 ;
V_32 -> V_44 = V_45 ;
V_32 -> V_46 = V_27 ;
V_42 -> V_34 = V_32 ;
return 0 ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_31 * V_32 = V_42 -> V_34 ;
V_42 -> V_34 = NULL ;
F_28 ( V_32 ) ;
}
static inline int F_32 ( struct V_19 * V_19 )
{
return F_33 ( V_19 , NULL ) ;
}
static int F_34 ( T_2 V_14 ,
struct V_31 * V_32 ,
const struct V_7 * V_7 )
{
const struct V_10 * V_11 = V_7 -> V_16 ;
int V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_32 -> V_14 , V_48 ,
V_49 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_14 , V_48 ,
V_50 , NULL ) ;
return V_47 ;
}
static int F_36 ( T_2 V_14 ,
struct V_31 * V_32 ,
const struct V_7 * V_7 )
{
const struct V_10 * V_11 = V_7 -> V_16 ;
int V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_32 -> V_14 , V_48 ,
V_49 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_32 -> V_14 , V_48 ,
V_51 , NULL ) ;
return V_47 ;
}
static int F_37 ( struct V_41 * V_42 )
{
struct V_31 * V_32 = V_42 -> V_34 ;
struct V_52 * V_53 = V_42 -> V_54 ;
struct V_19 * V_55 = V_53 -> V_56 ;
int V_47 = 0 ;
if ( V_32 -> V_57 == V_58 ) {
if ( ! V_55 -> V_59 -> V_60 ) {
F_38 ( V_61 L_2
L_3 , V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
V_47 = - V_65 ;
goto V_66;
}
V_47 = V_55 -> V_59 -> V_60 ( V_53 , V_67 , NULL , 0 ) ;
if ( V_47 < 0 && V_47 != - V_68 ) {
if ( V_47 == - V_65 )
F_38 ( V_61 L_4
L_5 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
else
F_38 ( V_61 L_4
L_6 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 , - V_47 ) ;
goto V_66;
}
}
V_32 -> V_69 |= ( V_70 | V_71 ) ;
if ( V_32 -> V_57 > F_39 ( V_72 ) )
F_38 ( V_73 L_7 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
else
F_38 ( V_74 L_8 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ,
V_72 [ V_32 -> V_57 - 1 ] ) ;
if ( V_32 -> V_57 == V_75 ||
V_32 -> V_57 == V_76 ||
V_32 -> V_57 == V_77 ||
V_32 -> V_57 > F_39 ( V_72 ) )
V_32 -> V_69 &= ~ V_71 ;
if ( strncmp ( V_42 -> V_63 -> V_64 , L_9 , sizeof( L_9 ) ) == 0 )
V_32 -> V_69 |= V_71 ;
V_47 = F_33 ( V_55 , V_53 ) ;
F_21 ( & V_32 -> V_35 ) ;
V_78:
if ( ! F_22 ( & V_32 -> V_43 ) ) {
struct V_20 * V_21 =
F_40 ( V_32 -> V_43 . V_79 ,
struct V_20 , V_26 ) ;
struct V_19 * V_19 = V_21 -> V_19 ;
F_24 ( & V_32 -> V_35 ) ;
V_19 = F_41 ( V_19 ) ;
if ( V_19 ) {
if ( ! F_42 ( V_19 ) )
F_32 ( V_19 ) ;
F_43 ( V_19 ) ;
}
F_21 ( & V_32 -> V_35 ) ;
F_23 ( & V_21 -> V_26 ) ;
goto V_78;
}
F_24 ( & V_32 -> V_35 ) ;
V_66:
return V_47 ;
}
static int F_44 ( const struct V_41 * V_42 ,
struct V_80 * V_81 )
{
int V_47 = 0 , V_82 ;
struct V_31 * V_32 = V_42 -> V_34 ;
char * V_83 = NULL ;
T_2 V_84 ;
char V_85 ;
F_45 ( V_81 ) ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return - V_86 ;
if ( ! V_87 )
return - V_86 ;
V_85 = V_32 -> V_69 & V_88 ;
for ( V_82 = 0 ; V_82 < 8 ; V_82 ++ ) {
if ( V_85 & 0x01 )
V_81 -> V_89 ++ ;
V_85 >>= 1 ;
}
if ( V_32 -> V_69 & V_71 )
V_81 -> V_89 ++ ;
V_81 -> V_90 = F_46 ( V_81 -> V_89 , sizeof( char * ) , V_91 ) ;
if ( ! V_81 -> V_90 ) {
V_47 = - V_24 ;
goto V_92;
}
V_81 -> V_93 = F_46 ( V_81 -> V_89 , sizeof( int ) , V_91 ) ;
if ( ! V_81 -> V_93 ) {
V_47 = - V_24 ;
goto V_92;
}
V_82 = 0 ;
if ( V_32 -> V_69 & V_94 ) {
V_47 = F_47 ( V_32 -> V_14 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_94 ;
}
if ( V_32 -> V_69 & V_95 ) {
V_47 = F_47 ( V_32 -> V_46 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_95 ;
}
if ( V_32 -> V_69 & V_96 ) {
V_47 = F_47 ( V_32 -> V_44 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_96 ;
}
if ( V_32 -> V_69 & V_97 ) {
struct V_19 * V_53 = V_32 -> V_42 -> V_54 -> V_56 ;
struct V_20 * V_21 = V_53 -> V_30 ;
V_47 = F_47 ( V_21 -> V_14 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_97 ;
}
if ( V_32 -> V_69 & V_71 ) {
V_81 -> V_90 [ V_82 ] = NULL ;
V_81 -> V_93 [ V_82 ++ ] = V_71 ;
}
F_48 ( V_82 != V_81 -> V_89 ) ;
return 0 ;
V_92:
F_49 ( V_81 ) ;
return V_47 ;
}
static int F_50 ( struct V_31 * V_32 , char V_98 ,
T_2 V_99 , T_2 V_100 )
{
char V_101 = V_32 -> V_69 & V_88 ;
if ( V_32 -> V_69 & V_70 )
if ( ! ( V_32 -> V_69 & V_98 ) ||
( V_99 != V_100 ) )
return 1 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
if ( V_101 & V_98 )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_41 * V_42 ,
struct V_80 * V_81 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 , V_82 ;
struct V_31 * V_32 = V_42 -> V_34 ;
const char * V_64 = V_42 -> V_63 -> V_64 ;
struct V_19 * V_19 = V_32 -> V_42 -> V_54 -> V_56 ;
struct V_20 * V_102 = V_19 -> V_30 ;
T_2 V_103 = 0 , V_104 = 0 , V_105 = 0 ;
T_2 V_106 = 0 ;
char * * V_107 = V_81 -> V_90 ;
int * V_69 = V_81 -> V_93 ;
int V_108 = V_81 -> V_89 ;
F_53 ( & V_32 -> V_25 ) ;
if ( ! V_87 ) {
if ( ! V_108 ) {
goto V_66;
}
V_47 = - V_86 ;
F_38 ( V_61 L_10
L_11 ) ;
goto V_66;
}
if ( ( V_32 -> V_69 & V_70 ) && ( V_42 -> V_63 -> V_109 & V_110 )
&& ( V_108 == 0 ) )
goto V_66;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
T_2 V_14 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_47 = F_54 ( V_107 [ V_82 ] ,
strlen ( V_107 [ V_82 ] ) , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_107 [ V_82 ] , V_42 -> V_62 , V_64 , V_47 ) ;
goto V_66;
}
switch ( V_69 [ V_82 ] ) {
case V_94 :
V_103 = V_14 ;
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 ,
V_103 ) )
goto V_111;
V_32 -> V_69 |= V_94 ;
break;
case V_95 :
V_104 = V_14 ;
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 ,
V_104 ) )
goto V_111;
V_32 -> V_69 |= V_95 ;
break;
case V_97 :
V_105 = V_14 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 ,
V_105 ) )
goto V_111;
V_32 -> V_69 |= V_97 ;
break;
case V_96 :
V_106 = V_14 ;
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 ,
V_106 ) )
goto V_111;
V_32 -> V_69 |= V_96 ;
break;
default:
V_47 = - V_86 ;
goto V_66;
}
}
if ( V_32 -> V_69 & V_70 ) {
if ( ( V_32 -> V_69 & V_88 ) && ! V_108 )
goto V_111;
V_47 = 0 ;
goto V_66;
}
if ( strcmp ( V_42 -> V_63 -> V_64 , L_14 ) == 0 )
V_32 -> V_69 |= V_112 ;
V_47 = F_55 ( ( V_32 -> V_69 & V_112 ) ? L_14 : V_42 -> V_63 -> V_64 , & V_32 -> V_57 , & V_32 -> V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_15 ,
V_113 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_66;
}
if ( V_103 ) {
V_47 = F_34 ( V_103 , V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_103 ;
}
if ( V_104 ) {
if ( ! V_103 ) {
V_47 = F_34 ( V_104 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_104 ;
} else {
V_47 = F_36 ( V_104 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
}
if ( ! V_105 )
V_105 = V_104 ;
V_32 -> V_46 = V_104 ;
V_32 -> V_57 = V_76 ;
}
if ( V_105 ) {
V_47 = F_36 ( V_105 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_102 -> V_14 = V_105 ;
V_102 -> V_114 = 1 ;
}
if ( V_106 ) {
if ( V_32 -> V_57 != V_58 ) {
V_47 = - V_86 ;
F_38 ( V_61 L_16
L_17 ) ;
goto V_66;
}
if ( V_106 != V_32 -> V_44 ) {
V_47 = F_36 ( V_106 ,
V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
}
V_32 -> V_44 = V_106 ;
}
V_47 = F_37 ( V_42 ) ;
V_66:
F_56 ( & V_32 -> V_25 ) ;
return V_47 ;
V_111:
V_47 = - V_86 ;
F_38 ( V_61 L_18
L_19 , V_42 -> V_62 , V_64 ) ;
goto V_66;
}
static void F_57 ( const struct V_41 * V_115 ,
struct V_41 * V_116 )
{
const struct V_31 * V_117 = V_115 -> V_34 ;
struct V_31 * V_118 = V_116 -> V_34 ;
int V_119 = ( V_117 -> V_69 & V_94 ) ;
int V_120 = ( V_117 -> V_69 & V_95 ) ;
int V_121 = ( V_117 -> V_69 & V_97 ) ;
if ( ! V_87 )
return;
F_48 ( ! ( V_117 -> V_69 & V_70 ) ) ;
if ( V_118 -> V_69 & V_70 )
return;
F_53 ( & V_118 -> V_25 ) ;
V_118 -> V_69 = V_117 -> V_69 ;
V_118 -> V_14 = V_117 -> V_14 ;
V_118 -> V_44 = V_117 -> V_44 ;
V_118 -> V_57 = V_117 -> V_57 ;
if ( V_120 ) {
T_2 V_14 = V_117 -> V_46 ;
if ( ! V_119 )
V_118 -> V_14 = V_14 ;
if ( ! V_121 ) {
struct V_19 * V_122 = V_116 -> V_54 -> V_56 ;
struct V_20 * V_123 = V_122 -> V_30 ;
V_123 -> V_14 = V_14 ;
}
V_118 -> V_46 = V_14 ;
}
if ( V_121 ) {
const struct V_19 * V_124 = V_115 -> V_54 -> V_56 ;
const struct V_20 * V_125 = V_124 -> V_30 ;
struct V_19 * V_122 = V_116 -> V_54 -> V_56 ;
struct V_20 * V_123 = V_122 -> V_30 ;
V_123 -> V_14 = V_125 -> V_14 ;
}
F_37 ( V_116 ) ;
F_56 ( & V_118 -> V_25 ) ;
}
static int F_58 ( char * V_126 ,
struct V_80 * V_81 )
{
char * V_127 ;
char * V_83 = NULL , * V_128 = NULL ;
char * V_129 = NULL , * V_130 = NULL ;
int V_47 , V_89 = 0 ;
V_81 -> V_89 = 0 ;
while ( ( V_127 = F_59 ( & V_126 , L_20 ) ) != NULL ) {
int V_131 ;
T_3 args [ V_132 ] ;
if ( ! * V_127 )
continue;
V_131 = F_60 ( V_127 , V_133 , args ) ;
switch ( V_131 ) {
case V_134 :
if ( V_83 || V_128 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_135;
}
V_83 = F_61 ( & args [ 0 ] ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
goto V_135;
}
break;
case V_136 :
if ( V_129 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_135;
}
V_129 = F_61 ( & args [ 0 ] ) ;
if ( ! V_129 ) {
V_47 = - V_24 ;
goto V_135;
}
break;
case V_137 :
if ( V_130 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_135;
}
V_130 = F_61 ( & args [ 0 ] ) ;
if ( ! V_130 ) {
V_47 = - V_24 ;
goto V_135;
}
break;
case V_138 :
if ( V_83 || V_128 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_135;
}
V_128 = F_61 ( & args [ 0 ] ) ;
if ( ! V_128 ) {
V_47 = - V_24 ;
goto V_135;
}
break;
case V_139 :
break;
default:
V_47 = - V_86 ;
F_38 ( V_61 L_21 ) ;
goto V_135;
}
}
V_47 = - V_24 ;
V_81 -> V_90 = F_46 ( V_140 , sizeof( char * ) , V_91 ) ;
if ( ! V_81 -> V_90 )
goto V_135;
V_81 -> V_93 = F_46 ( V_140 , sizeof( int ) , V_91 ) ;
if ( ! V_81 -> V_93 ) {
F_28 ( V_81 -> V_90 ) ;
goto V_135;
}
if ( V_129 ) {
V_81 -> V_90 [ V_89 ] = V_129 ;
V_81 -> V_93 [ V_89 ++ ] = V_94 ;
}
if ( V_83 ) {
V_81 -> V_90 [ V_89 ] = V_83 ;
V_81 -> V_93 [ V_89 ++ ] = V_95 ;
}
if ( V_130 ) {
V_81 -> V_90 [ V_89 ] = V_130 ;
V_81 -> V_93 [ V_89 ++ ] = V_97 ;
}
if ( V_128 ) {
V_81 -> V_90 [ V_89 ] = V_128 ;
V_81 -> V_93 [ V_89 ++ ] = V_96 ;
}
V_81 -> V_89 = V_89 ;
return 0 ;
V_135:
F_28 ( V_83 ) ;
F_28 ( V_128 ) ;
F_28 ( V_129 ) ;
F_28 ( V_130 ) ;
return V_47 ;
}
static int F_62 ( struct V_41 * V_42 , void * V_141 )
{
int V_47 = 0 ;
char * V_126 = V_141 ;
struct V_80 V_81 ;
F_45 ( & V_81 ) ;
if ( ! V_141 )
goto V_66;
F_48 ( V_42 -> V_63 -> V_109 & V_110 ) ;
V_47 = F_58 ( V_126 , & V_81 ) ;
if ( V_47 )
goto V_135;
V_66:
V_47 = F_51 ( V_42 , & V_81 ) ;
V_135:
F_49 ( & V_81 ) ;
return V_47 ;
}
static void F_63 ( struct V_142 * V_143 ,
struct V_80 * V_81 )
{
int V_82 ;
char * V_144 ;
for ( V_82 = 0 ; V_82 < V_81 -> V_89 ; V_82 ++ ) {
char * V_145 ;
if ( V_81 -> V_90 [ V_82 ] )
V_145 = strchr ( V_81 -> V_90 [ V_82 ] , ',' ) ;
else
V_145 = NULL ;
switch ( V_81 -> V_93 [ V_82 ] ) {
case V_95 :
V_144 = V_146 ;
break;
case V_94 :
V_144 = V_147 ;
break;
case V_97 :
V_144 = V_148 ;
break;
case V_96 :
V_144 = V_149 ;
break;
case V_71 :
F_64 ( V_143 , ',' ) ;
F_65 ( V_143 , V_150 ) ;
continue;
default:
F_66 () ;
return;
} ;
F_64 ( V_143 , ',' ) ;
F_65 ( V_143 , V_144 ) ;
if ( V_145 )
F_64 ( V_143 , '\"' ) ;
F_65 ( V_143 , V_81 -> V_90 [ V_82 ] ) ;
if ( V_145 )
F_64 ( V_143 , '\"' ) ;
}
}
static int F_67 ( struct V_142 * V_143 , struct V_41 * V_42 )
{
struct V_80 V_81 ;
int V_47 ;
V_47 = F_44 ( V_42 , & V_81 ) ;
if ( V_47 ) {
if ( V_47 == - V_86 )
V_47 = 0 ;
return V_47 ;
}
F_63 ( V_143 , & V_81 ) ;
F_49 ( & V_81 ) ;
return V_47 ;
}
static inline T_4 F_68 ( T_5 V_151 )
{
switch ( V_151 & V_152 ) {
case V_153 :
return V_154 ;
case V_155 :
return V_156 ;
case V_157 :
return V_29 ;
case V_158 :
return V_159 ;
case V_160 :
return V_161 ;
case V_162 :
return V_163 ;
case V_164 :
return V_165 ;
}
return V_29 ;
}
static inline int F_69 ( int V_166 )
{
return ( V_166 == V_167 || V_166 == V_168 ) ;
}
static inline int F_70 ( int V_166 )
{
return ( V_166 == V_167 || V_166 == V_169 ) ;
}
static inline T_4 F_71 ( int V_170 , int type , int V_166 )
{
switch ( V_170 ) {
case V_171 :
switch ( type ) {
case V_172 :
case V_173 :
return V_174 ;
case V_175 :
return V_176 ;
}
break;
case V_177 :
case V_178 :
switch ( type ) {
case V_172 :
if ( F_69 ( V_166 ) )
return V_179 ;
else
return V_180 ;
case V_175 :
if ( F_70 ( V_166 ) )
return V_181 ;
else
return V_180 ;
case V_182 :
return V_183 ;
default:
return V_180 ;
}
break;
case V_184 :
switch ( V_166 ) {
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
case V_191 :
return V_192 ;
case V_193 :
return V_194 ;
case V_195 :
return V_196 ;
case V_197 :
return V_198 ;
case V_199 :
return V_200 ;
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
default:
return V_205 ;
}
case V_206 :
return V_207 ;
case V_208 :
return V_209 ;
case V_210 :
return V_211 ;
}
return V_212 ;
}
static int F_72 ( struct V_52 * V_52 ,
T_4 V_213 ,
T_2 * V_14 )
{
int V_47 ;
char * V_214 , * V_215 ;
V_214 = ( char * ) F_73 ( V_12 ) ;
if ( ! V_214 )
return - V_24 ;
V_215 = F_74 ( V_52 , V_214 , V_216 ) ;
if ( F_75 ( V_215 ) )
V_47 = F_76 ( V_215 ) ;
else {
while ( V_215 [ 1 ] >= '0' && V_215 [ 1 ] <= '9' ) {
V_215 [ 1 ] = '/' ;
V_215 ++ ;
}
V_47 = F_77 ( L_14 , V_215 , V_213 , V_14 ) ;
}
F_78 ( ( unsigned long ) V_214 ) ;
return V_47 ;
}
static int F_72 ( struct V_52 * V_52 ,
T_4 V_213 ,
T_2 * V_14 )
{
return - V_86 ;
}
static int F_33 ( struct V_19 * V_19 , struct V_52 * V_217 )
{
struct V_31 * V_32 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 ;
struct V_52 * V_52 ;
#define F_79 255
char * V_83 = NULL ;
unsigned V_84 = 0 ;
int V_47 = 0 ;
if ( V_21 -> V_114 )
goto V_66;
F_53 ( & V_21 -> V_25 ) ;
if ( V_21 -> V_114 )
goto V_218;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) ) {
F_21 ( & V_32 -> V_35 ) ;
if ( F_22 ( & V_21 -> V_26 ) )
F_80 ( & V_21 -> V_26 , & V_32 -> V_43 ) ;
F_24 ( & V_32 -> V_35 ) ;
goto V_218;
}
switch ( V_32 -> V_57 ) {
case V_58 :
if ( ! V_19 -> V_59 -> V_60 ) {
V_21 -> V_14 = V_32 -> V_44 ;
break;
}
if ( V_217 ) {
V_52 = F_81 ( V_217 ) ;
} else {
V_52 = F_82 ( V_19 ) ;
}
if ( ! V_52 ) {
goto V_218;
}
V_84 = F_79 ;
V_83 = F_83 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_84 ( V_52 ) ;
goto V_218;
}
V_83 [ V_84 ] = '\0' ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
V_83 , V_84 ) ;
if ( V_47 == - V_219 ) {
F_28 ( V_83 ) ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
NULL , 0 ) ;
if ( V_47 < 0 ) {
F_84 ( V_52 ) ;
goto V_218;
}
V_84 = V_47 ;
V_83 = F_83 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_84 ( V_52 ) ;
goto V_218;
}
V_83 [ V_84 ] = '\0' ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 ,
V_67 ,
V_83 , V_84 ) ;
}
F_84 ( V_52 ) ;
if ( V_47 < 0 ) {
if ( V_47 != - V_68 ) {
F_38 ( V_61 L_22
L_23 , V_113 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_220 ) ;
F_28 ( V_83 ) ;
goto V_218;
}
V_14 = V_32 -> V_44 ;
V_47 = 0 ;
} else {
V_47 = F_85 ( V_83 , V_47 , & V_14 ,
V_32 -> V_44 ,
V_23 ) ;
if ( V_47 ) {
char * V_221 = V_19 -> V_33 -> V_62 ;
unsigned long V_222 = V_19 -> V_220 ;
if ( V_47 == - V_86 ) {
if ( F_86 () )
F_38 ( V_223 L_24
L_25
L_26 , V_222 , V_221 , V_83 ) ;
} else {
F_38 ( V_61 L_27
L_28 ,
V_113 , V_83 , - V_47 , V_221 , V_222 ) ;
}
F_28 ( V_83 ) ;
V_47 = 0 ;
break;
}
}
F_28 ( V_83 ) ;
V_21 -> V_14 = V_14 ;
break;
case V_224 :
V_21 -> V_14 = V_21 -> F_10 ;
break;
case V_225 :
V_21 -> V_14 = V_32 -> V_14 ;
V_21 -> V_28 = F_68 ( V_19 -> V_226 ) ;
V_47 = F_87 ( V_21 -> F_10 , V_32 -> V_14 ,
V_21 -> V_28 , NULL , & V_14 ) ;
if ( V_47 )
goto V_218;
V_21 -> V_14 = V_14 ;
break;
case V_76 :
V_21 -> V_14 = V_32 -> V_46 ;
break;
default:
V_21 -> V_14 = V_32 -> V_14 ;
if ( ( V_32 -> V_69 & V_112 ) && ! F_88 ( V_19 -> V_226 ) ) {
if ( V_217 ) {
V_21 -> V_28 = F_68 ( V_19 -> V_226 ) ;
V_47 = F_72 ( V_217 ,
V_21 -> V_28 ,
& V_14 ) ;
if ( V_47 )
goto V_218;
V_21 -> V_14 = V_14 ;
}
}
break;
}
V_21 -> V_114 = 1 ;
V_218:
F_56 ( & V_21 -> V_25 ) ;
V_66:
if ( V_21 -> V_28 == V_29 )
V_21 -> V_28 = F_68 ( V_19 -> V_226 ) ;
return V_47 ;
}
static inline T_2 F_89 ( int V_227 )
{
T_2 V_228 = 0 ;
switch ( V_227 ) {
case V_229 :
V_228 = V_230 ;
break;
case V_231 :
V_228 = V_232 ;
break;
case V_233 :
V_228 = V_234 ;
break;
default:
V_228 = V_235 ;
break;
}
return V_228 ;
}
static int F_90 ( const struct V_7 * V_236 ,
const struct V_7 * V_237 ,
T_2 V_238 )
{
T_2 V_239 = F_9 ( V_236 ) , V_240 = F_9 ( V_237 ) ;
return F_35 ( V_239 , V_240 , V_241 , V_238 , NULL ) ;
}
static int F_91 ( const struct V_17 * V_242 ,
const struct V_17 * V_243 ,
T_2 V_238 )
{
const struct V_10 * V_244 , * V_245 ;
T_2 V_246 , V_247 ;
F_11 () ;
V_244 = F_12 ( V_242 ) -> V_16 ; V_246 = V_244 -> V_14 ;
V_245 = F_12 ( V_243 ) -> V_16 ; V_247 = V_245 -> V_14 ;
F_13 () ;
return F_35 ( V_246 , V_247 , V_241 , V_238 , NULL ) ;
}
static int F_92 ( const struct V_17 * V_248 ,
T_2 V_238 )
{
T_2 V_14 , V_240 ;
V_14 = F_14 () ;
V_240 = F_10 ( V_248 ) ;
return F_35 ( V_14 , V_240 , V_241 , V_238 , NULL ) ;
}
static int F_93 ( struct V_17 * V_248 ,
const struct V_7 * V_7 ,
int V_249 , int V_250 )
{
struct V_251 V_252 ;
struct V_253 V_254 ;
T_4 V_28 ;
T_2 V_14 = F_9 ( V_7 ) ;
T_2 V_255 = F_94 ( V_249 ) ;
int V_47 ;
F_95 ( & V_252 , V_256 ) ;
V_252 . V_248 = V_248 ;
V_252 . V_257 . V_249 = V_249 ;
switch ( F_96 ( V_249 ) ) {
case 0 :
V_28 = V_258 ;
break;
case 1 :
V_28 = V_259 ;
break;
default:
F_38 ( V_73
L_29 , V_249 ) ;
F_66 () ;
return - V_86 ;
}
V_47 = F_97 ( V_14 , V_14 , V_28 , V_255 , 0 , & V_254 ) ;
if ( V_250 == V_260 ) {
int V_261 = F_98 ( V_14 , V_14 , V_28 , V_255 , & V_254 , V_47 , & V_252 , 0 ) ;
if ( V_261 )
return V_261 ;
}
return V_47 ;
}
static int F_99 ( struct V_17 * V_248 ,
T_2 V_238 )
{
T_2 V_14 = F_10 ( V_248 ) ;
return F_35 ( V_14 , V_15 ,
V_262 , V_238 , NULL ) ;
}
static int F_100 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_238 ,
struct V_251 * V_263 ,
unsigned V_69 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_103 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , V_263 , V_69 ) ;
}
static int F_104 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_238 ,
unsigned V_69 )
{
struct V_251 V_252 ;
F_95 ( & V_252 , V_264 ) ;
V_252 . V_257 . V_19 = V_19 ;
return F_100 ( V_7 , V_19 , V_238 , & V_252 , V_69 ) ;
}
static inline int F_105 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_255 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_251 V_252 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_52 ;
return F_100 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
}
static inline int F_106 ( const struct V_7 * V_7 ,
struct V_215 * V_215 ,
T_2 V_255 )
{
struct V_19 * V_19 = V_215 -> V_52 -> V_56 ;
struct V_251 V_252 ;
F_95 ( & V_252 , V_266 ) ;
V_252 . V_257 . V_215 = * V_215 ;
return F_100 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
}
static int F_107 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_255 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = V_36 -> V_267 . V_52 -> V_56 ;
struct V_251 V_252 ;
T_2 V_14 = F_9 ( V_7 ) ;
int V_47 ;
F_95 ( & V_252 , V_266 ) ;
V_252 . V_257 . V_215 = V_36 -> V_267 ;
if ( V_14 != V_38 -> V_14 ) {
V_47 = F_35 ( V_14 , V_38 -> V_14 ,
V_268 ,
V_269 ,
& V_252 ) ;
if ( V_47 )
goto V_66;
}
V_47 = 0 ;
if ( V_255 )
V_47 = F_100 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
V_66:
return V_47 ;
}
static int F_108 ( struct V_19 * V_270 ,
struct V_52 * V_52 ,
T_4 V_213 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_271 ;
struct V_31 * V_32 ;
T_2 V_14 , V_272 ;
struct V_251 V_252 ;
int V_47 ;
V_271 = V_270 -> V_30 ;
V_32 = V_270 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_272 = V_11 -> V_273 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_271 -> V_14 , V_161 ,
V_274 | V_275 ,
& V_252 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_272 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_271 -> V_14 , V_213 ,
& V_52 -> V_276 , & V_272 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_35 ( V_14 , V_272 , V_213 , V_277 , & V_252 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_272 , V_32 -> V_14 ,
V_48 ,
V_51 , & V_252 ) ;
}
static int F_109 ( T_2 V_278 ,
struct V_17 * V_279 )
{
T_2 V_14 = F_10 ( V_279 ) ;
return F_35 ( V_14 , V_278 , V_280 , V_281 , NULL ) ;
}
static int F_110 ( struct V_19 * V_270 ,
struct V_52 * V_52 ,
int V_282 )
{
struct V_20 * V_271 , * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
T_2 V_255 ;
int V_47 ;
V_271 = V_270 -> V_30 ;
V_21 = V_52 -> V_56 -> V_30 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_52 ;
V_255 = V_275 ;
V_255 |= ( V_282 ? V_283 : V_274 ) ;
V_47 = F_35 ( V_14 , V_271 -> V_14 , V_161 , V_255 , & V_252 ) ;
if ( V_47 )
return V_47 ;
switch ( V_282 ) {
case V_284 :
V_255 = V_285 ;
break;
case V_286 :
V_255 = V_287 ;
break;
case V_288 :
V_255 = V_289 ;
break;
default:
F_38 ( V_61 L_30 ,
V_113 , V_282 ) ;
return 0 ;
}
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_255 , & V_252 ) ;
return V_47 ;
}
static inline int F_111 ( struct V_19 * V_290 ,
struct V_52 * V_291 ,
struct V_19 * V_292 ,
struct V_52 * V_293 )
{
struct V_20 * V_294 , * V_295 , * V_296 , * V_297 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
T_2 V_255 ;
int V_298 , V_299 ;
int V_47 ;
V_294 = V_290 -> V_30 ;
V_296 = V_291 -> V_56 -> V_30 ;
V_298 = F_112 ( V_291 -> V_56 -> V_226 ) ;
V_295 = V_292 -> V_30 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_291 ;
V_47 = F_35 ( V_14 , V_294 -> V_14 , V_161 ,
V_283 | V_275 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_296 -> V_14 ,
V_296 -> V_28 , V_300 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_298 && V_292 != V_290 ) {
V_47 = F_35 ( V_14 , V_296 -> V_14 ,
V_296 -> V_28 , V_301 , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . V_257 . V_52 = V_293 ;
V_255 = V_274 | V_275 ;
if ( V_293 -> V_56 )
V_255 |= V_283 ;
V_47 = F_35 ( V_14 , V_295 -> V_14 , V_161 , V_255 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_293 -> V_56 ) {
V_297 = V_293 -> V_56 -> V_30 ;
V_299 = F_112 ( V_293 -> V_56 -> V_226 ) ;
V_47 = F_35 ( V_14 , V_297 -> V_14 ,
V_297 -> V_28 ,
( V_299 ? V_289 : V_287 ) , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_113 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_238 ,
struct V_251 * V_252 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_238 , V_252 ) ;
}
static inline T_2 F_114 ( int V_151 , int V_302 )
{
T_2 V_255 = 0 ;
if ( ( V_151 & V_152 ) != V_160 ) {
if ( V_302 & V_303 )
V_255 |= V_304 ;
if ( V_302 & V_305 )
V_255 |= V_306 ;
if ( V_302 & V_307 )
V_255 |= V_308 ;
else if ( V_302 & V_309 )
V_255 |= V_310 ;
} else {
if ( V_302 & V_303 )
V_255 |= V_275 ;
if ( V_302 & V_309 )
V_255 |= V_311 ;
if ( V_302 & V_305 )
V_255 |= V_312 ;
}
return V_255 ;
}
static inline T_2 F_115 ( struct V_36 * V_36 )
{
T_2 V_255 = 0 ;
if ( V_36 -> V_313 & V_314 )
V_255 |= V_306 ;
if ( V_36 -> V_313 & V_315 ) {
if ( V_36 -> V_316 & V_317 )
V_255 |= V_308 ;
else
V_255 |= V_310 ;
}
if ( ! V_255 ) {
V_255 = V_318 ;
}
return V_255 ;
}
static inline T_2 F_116 ( struct V_36 * V_36 )
{
T_2 V_255 = F_115 ( V_36 ) ;
if ( V_319 )
V_255 |= V_320 ;
return V_255 ;
}
static int F_117 ( struct V_17 * V_321 ,
unsigned int V_151 )
{
int V_47 ;
V_47 = F_118 ( V_321 , V_151 ) ;
if ( V_47 )
return V_47 ;
if ( V_151 == V_322 ) {
T_2 V_14 = F_14 () ;
T_2 V_323 = F_10 ( V_321 ) ;
return F_35 ( V_14 , V_323 , V_29 , V_306 , NULL ) ;
}
return F_92 ( V_321 , V_324 ) ;
}
static int F_119 ( struct V_17 * V_325 )
{
int V_47 ;
V_47 = F_120 ( V_325 ) ;
if ( V_47 )
return V_47 ;
return F_91 ( V_325 , V_8 , V_324 ) ;
}
static int F_121 ( struct V_17 * V_237 , T_6 * V_326 ,
T_6 * V_327 , T_6 * V_328 )
{
int error ;
error = F_92 ( V_237 , V_329 ) ;
if ( error )
return error ;
return F_122 ( V_237 , V_326 , V_327 , V_328 ) ;
}
static int F_123 ( struct V_7 * V_330 , const struct V_7 * V_331 ,
const T_6 * V_326 ,
const T_6 * V_327 ,
const T_6 * V_328 )
{
int error ;
error = F_124 ( V_330 , V_331 ,
V_326 , V_327 , V_328 ) ;
if ( error )
return error ;
return F_90 ( V_331 , V_330 , V_332 ) ;
}
static int F_125 ( struct V_17 * V_248 , const struct V_7 * V_7 ,
struct V_333 * V_334 , int V_249 , int V_250 )
{
int V_47 ;
V_47 = F_126 ( V_248 , V_7 , V_334 , V_249 , V_250 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_248 , V_7 , V_249 , V_250 ) ;
}
static int F_127 ( int V_335 , int type , int V_336 , struct V_41 * V_42 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( ! V_42 )
return 0 ;
switch ( V_335 ) {
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
V_47 = F_113 ( V_7 , V_42 , V_342 , NULL ) ;
break;
case V_343 :
case V_344 :
case V_345 :
V_47 = F_113 ( V_7 , V_42 , V_346 , NULL ) ;
break;
default:
V_47 = 0 ;
break;
}
return V_47 ;
}
static int F_128 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_347 ) ;
}
static int F_129 ( int type )
{
int V_47 ;
switch ( type ) {
case V_348 :
case V_349 :
V_47 = F_99 ( V_8 , V_350 ) ;
break;
case V_351 :
case V_352 :
case V_353 :
V_47 = F_99 ( V_8 , V_354 ) ;
break;
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
default:
V_47 = F_99 ( V_8 , V_360 ) ;
break;
}
return V_47 ;
}
static int F_130 ( struct V_361 * V_362 , long V_363 )
{
int V_47 , V_364 = 0 ;
V_47 = F_125 ( V_8 , F_52 () ,
& V_365 , V_366 ,
V_367 ) ;
if ( V_47 == 0 )
V_364 = 1 ;
return F_131 ( V_362 , V_363 , V_364 ) ;
}
static int F_132 ( struct V_368 * V_369 )
{
const struct V_10 * V_370 ;
struct V_10 * V_371 ;
struct V_20 * V_21 ;
struct V_251 V_252 ;
struct V_19 * V_19 = V_369 -> V_36 -> V_267 . V_52 -> V_56 ;
int V_47 ;
V_47 = F_133 ( V_369 ) ;
if ( V_47 )
return V_47 ;
if ( V_369 -> V_372 )
return 0 ;
V_370 = F_15 () ;
V_371 = V_369 -> V_7 -> V_16 ;
V_21 = V_19 -> V_30 ;
V_371 -> V_14 = V_370 -> V_14 ;
V_371 -> V_13 = V_370 -> V_14 ;
V_371 -> V_273 = 0 ;
V_371 -> V_373 = 0 ;
V_371 -> V_374 = 0 ;
if ( V_370 -> V_375 ) {
V_371 -> V_14 = V_370 -> V_375 ;
V_371 -> V_375 = 0 ;
} else {
V_47 = F_87 ( V_370 -> V_14 , V_21 -> V_14 ,
V_241 , NULL ,
& V_371 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
F_95 ( & V_252 , V_266 ) ;
V_252 . V_257 . V_215 = V_369 -> V_36 -> V_267 ;
if ( V_369 -> V_36 -> V_267 . V_376 -> V_101 & V_377 )
V_371 -> V_14 = V_370 -> V_14 ;
if ( V_371 -> V_14 == V_370 -> V_14 ) {
V_47 = F_35 ( V_370 -> V_14 , V_21 -> V_14 ,
V_29 , V_378 , & V_252 ) ;
if ( V_47 )
return V_47 ;
} else {
V_47 = F_35 ( V_370 -> V_14 , V_371 -> V_14 ,
V_241 , V_379 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_371 -> V_14 , V_21 -> V_14 ,
V_29 , V_380 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_369 -> V_381 & V_382 ) {
V_47 = F_35 ( V_370 -> V_14 , V_371 -> V_14 ,
V_241 , V_383 ,
NULL ) ;
if ( V_47 )
return - V_384 ;
}
if ( V_369 -> V_381 &
( V_385 | V_386 ) ) {
struct V_17 * V_387 ;
struct V_10 * V_388 ;
T_2 V_389 = 0 ;
F_11 () ;
V_387 = F_134 ( V_8 ) ;
if ( F_135 ( V_387 != NULL ) ) {
V_388 = F_12 ( V_387 ) -> V_16 ;
V_389 = V_388 -> V_14 ;
}
F_13 () ;
if ( V_389 != 0 ) {
V_47 = F_35 ( V_389 , V_371 -> V_14 ,
V_241 ,
V_324 , NULL ) ;
if ( V_47 )
return - V_384 ;
}
}
V_369 -> V_390 |= V_391 ;
}
return 0 ;
}
static int F_136 ( struct V_368 * V_369 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_14 , V_13 ;
int V_392 = 0 ;
V_14 = V_11 -> V_14 ;
V_13 = V_11 -> V_13 ;
if ( V_13 != V_14 ) {
V_392 = F_35 ( V_13 , V_14 ,
V_241 ,
V_393 , NULL ) ;
}
return ( V_392 || F_137 ( V_369 ) ) ;
}
static inline void F_138 ( const struct V_7 * V_7 ,
struct V_394 * V_395 )
{
struct V_251 V_252 ;
struct V_36 * V_36 , * V_396 = NULL ;
struct V_397 * V_398 ;
struct V_399 * V_400 ;
long V_401 = - 1 ;
int V_402 = 0 ;
V_398 = F_139 () ;
if ( V_398 ) {
F_21 ( & V_403 ) ;
if ( ! F_22 ( & V_398 -> V_404 ) ) {
struct V_405 * V_406 ;
struct V_19 * V_19 ;
V_406 = F_140 ( & V_398 -> V_404 ,
struct V_405 , V_26 ) ;
V_36 = V_406 -> V_36 ;
V_19 = V_36 -> V_267 . V_52 -> V_56 ;
if ( F_104 ( V_7 , V_19 ,
V_306 | V_310 , 0 ) ) {
V_402 = 1 ;
}
}
F_24 ( & V_403 ) ;
F_141 ( V_398 ) ;
}
if ( V_402 )
F_142 () ;
F_95 ( & V_252 , V_264 ) ;
F_21 ( & V_395 -> V_407 ) ;
for (; ; ) {
unsigned long V_408 , V_82 ;
int V_409 ;
V_401 ++ ;
V_82 = V_401 * V_410 ;
V_400 = F_143 ( V_395 ) ;
if ( V_82 >= V_400 -> V_411 )
break;
V_408 = V_400 -> V_412 -> V_413 [ V_401 ] ;
if ( ! V_408 )
continue;
F_24 ( & V_395 -> V_407 ) ;
for ( ; V_408 ; V_82 ++ , V_408 >>= 1 ) {
if ( V_408 & 1 ) {
V_36 = F_144 ( V_82 ) ;
if ( ! V_36 )
continue;
if ( F_107 ( V_7 ,
V_36 ,
F_115 ( V_36 ) ) ) {
F_145 ( V_82 ) ;
V_409 = F_146 () ;
if ( V_409 != V_82 ) {
if ( V_409 >= 0 )
F_147 ( V_409 ) ;
F_148 ( V_36 ) ;
continue;
}
if ( V_396 ) {
F_149 ( V_396 ) ;
} else {
V_396 = F_150 (
F_81 ( V_414 ) ,
F_151 ( V_415 ) ,
V_416 , V_7 ) ;
if ( F_75 ( V_396 ) ) {
V_396 = NULL ;
F_147 ( V_409 ) ;
F_148 ( V_36 ) ;
continue;
}
}
F_152 ( V_409 , V_396 ) ;
}
F_148 ( V_36 ) ;
}
}
F_21 ( & V_395 -> V_407 ) ;
}
F_24 ( & V_395 -> V_407 ) ;
}
static void F_153 ( struct V_368 * V_369 )
{
struct V_10 * V_371 ;
struct V_417 * V_418 , * V_419 ;
int V_47 , V_82 ;
V_371 = V_369 -> V_7 -> V_16 ;
if ( V_371 -> V_14 == V_371 -> V_13 )
return;
F_138 ( V_369 -> V_7 , V_8 -> V_395 ) ;
V_8 -> V_420 = 0 ;
V_47 = F_35 ( V_371 -> V_13 , V_371 -> V_14 , V_241 ,
V_421 , NULL ) ;
if ( V_47 ) {
F_154 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_422 ; V_82 ++ ) {
V_418 = V_8 -> signal -> V_418 + V_82 ;
V_419 = V_423 . signal -> V_418 + V_82 ;
V_418 -> V_424 = F_155 ( V_418 -> V_425 , V_419 -> V_424 ) ;
}
F_156 ( V_8 ) ;
F_157 ( V_8 , V_417 ( V_426 ) ) ;
}
}
static void F_158 ( struct V_368 * V_369 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_427 V_428 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_241 , V_429 , NULL ) ;
if ( V_47 ) {
memset ( & V_428 , 0 , sizeof V_428 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_159 ( V_82 , & V_428 , NULL ) ;
F_160 ( & V_8 -> V_430 -> V_431 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_432 ) ) {
F_161 ( V_8 ) ;
F_162 ( V_8 , 1 ) ;
F_163 ( & V_8 -> V_433 ) ;
}
F_164 ( & V_8 -> V_430 -> V_431 ) ;
}
F_165 ( & V_434 ) ;
F_166 ( V_8 , V_8 -> V_435 ) ;
F_167 ( & V_434 ) ;
}
static int F_168 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_169 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_170 ( char * V_144 , int V_436 , char * V_437 , int V_438 )
{
if ( V_436 > V_438 )
return 0 ;
return ! memcmp ( V_144 , V_437 , V_436 ) ;
}
static inline int F_171 ( char * V_437 , int V_84 )
{
return ( F_170 ( V_146 , sizeof( V_146 ) - 1 , V_437 , V_84 ) ||
F_170 ( V_147 , sizeof( V_147 ) - 1 , V_437 , V_84 ) ||
F_170 ( V_149 , sizeof( V_149 ) - 1 , V_437 , V_84 ) ||
F_170 ( V_148 , sizeof( V_148 ) - 1 , V_437 , V_84 ) ||
F_170 ( V_150 , sizeof( V_150 ) - 1 , V_437 , V_84 ) ) ;
}
static inline void F_172 ( char * * V_439 , char * V_440 , int * V_441 , int V_84 )
{
if ( ! * V_441 ) {
* * V_439 = ',' ;
* V_439 += 1 ;
} else
* V_441 = 0 ;
memcpy ( * V_439 , V_440 , V_84 ) ;
* V_439 += V_84 ;
}
static inline void F_173 ( char * * V_439 , char * V_440 , int * V_441 ,
int V_84 )
{
int V_442 = 0 ;
if ( ! * V_441 ) {
* * V_439 = '|' ;
* V_439 += 1 ;
} else
* V_441 = 0 ;
while ( V_442 < V_84 ) {
if ( * V_440 != '"' ) {
* * V_439 = * V_440 ;
* V_439 += 1 ;
}
V_440 += 1 ;
V_442 += 1 ;
}
}
static int F_174 ( char * V_443 , char * V_444 )
{
int V_445 , V_38 , V_47 = 0 ;
char * V_446 , * V_447 , * V_448 ;
char * V_449 , * V_450 , * V_451 ;
int V_452 = 0 ;
V_447 = V_443 ;
V_449 = V_444 ;
V_451 = ( char * ) F_175 ( V_12 ) ;
if ( ! V_451 ) {
V_47 = - V_24 ;
goto V_66;
}
V_450 = V_451 ;
V_445 = V_38 = 1 ;
V_446 = V_448 = V_443 ;
do {
if ( * V_448 == '"' )
V_452 = ! V_452 ;
if ( ( * V_448 == ',' && V_452 == 0 ) ||
* V_448 == '\0' ) {
int V_84 = V_448 - V_447 ;
if ( F_171 ( V_447 , V_84 ) )
F_173 ( & V_449 , V_447 , & V_38 , V_84 ) ;
else
F_172 ( & V_451 , V_447 , & V_445 , V_84 ) ;
V_447 = V_448 + 1 ;
}
} while ( * V_448 ++ );
strcpy ( V_446 , V_450 ) ;
F_78 ( ( unsigned long ) V_450 ) ;
V_66:
return V_47 ;
}
static int F_176 ( struct V_41 * V_42 , void * V_141 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_453 , * * V_107 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_141 )
return 0 ;
if ( V_42 -> V_63 -> V_109 & V_110 )
return 0 ;
F_45 ( & V_81 ) ;
V_453 = F_177 () ;
if ( ! V_453 )
return - V_24 ;
V_47 = F_174 ( V_141 , V_453 ) ;
if ( V_47 )
goto V_454;
V_47 = F_58 ( V_453 , & V_81 ) ;
if ( V_47 )
goto V_454;
V_107 = V_81 . V_90 ;
V_69 = V_81 . V_93 ;
for ( V_82 = 0 ; V_82 < V_81 . V_89 ; V_82 ++ ) {
T_2 V_14 ;
T_7 V_84 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_84 = strlen ( V_107 [ V_82 ] ) ;
V_47 = F_54 ( V_107 [ V_82 ] , V_84 , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_107 [ V_82 ] , V_42 -> V_62 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_455;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_456;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_456;
break;
case V_97 : {
struct V_20 * V_102 ;
V_102 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 , V_14 ) )
goto V_456;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_456;
break;
default:
goto V_455;
}
}
V_47 = 0 ;
V_455:
F_49 ( & V_81 ) ;
V_454:
F_178 ( V_453 ) ;
return V_47 ;
V_456:
F_38 ( V_61 L_31
L_32 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_455;
}
static int F_179 ( struct V_41 * V_42 , int V_69 , void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
int V_47 ;
V_47 = F_62 ( V_42 , V_141 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_457 )
return 0 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_42 -> V_54 ;
return F_113 ( V_7 , V_42 , V_458 , & V_252 ) ;
}
static int F_180 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_52 -> V_459 -> V_54 ;
return F_113 ( V_7 , V_52 -> V_459 , V_460 , & V_252 ) ;
}
static int F_181 ( char * V_461 ,
struct V_215 * V_215 ,
char * type ,
unsigned long V_69 ,
void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_462 )
return F_113 ( V_7 , V_215 -> V_376 -> V_463 ,
V_464 , NULL ) ;
else
return F_106 ( V_7 , V_215 , V_465 ) ;
}
static int F_182 ( struct V_466 * V_376 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_113 ( V_7 , V_376 -> V_463 ,
V_467 , NULL ) ;
}
static int F_183 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_184 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_185 ( struct V_19 * V_19 , struct V_19 * V_270 ,
const struct V_468 * V_468 , char * * V_64 ,
void * * V_469 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_271 ;
struct V_31 * V_32 ;
T_2 V_14 , V_272 , V_470 ;
int V_47 ;
char * V_471 = NULL , * V_83 ;
V_271 = V_270 -> V_30 ;
V_32 = V_270 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_272 = V_11 -> V_273 ;
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_57 == V_76 ) )
V_272 = V_32 -> V_46 ;
else if ( ! V_272 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_271 -> V_14 ,
F_68 ( V_19 -> V_226 ) ,
V_468 , & V_272 ) ;
if ( V_47 ) {
F_38 ( V_61 L_33
L_34
L_35 ,
V_113 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_220 ) ;
return V_47 ;
}
}
if ( V_32 -> V_69 & V_70 ) {
struct V_20 * V_21 = V_19 -> V_30 ;
V_21 -> V_28 = F_68 ( V_19 -> V_226 ) ;
V_21 -> V_14 = V_272 ;
V_21 -> V_114 = 1 ;
}
if ( ! V_87 || ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( V_64 ) {
V_471 = F_186 ( V_472 , V_23 ) ;
if ( ! V_471 )
return - V_24 ;
* V_64 = V_471 ;
}
if ( V_469 && V_84 ) {
V_47 = F_187 ( V_272 , & V_83 , & V_470 ) ;
if ( V_47 ) {
F_28 ( V_471 ) ;
return V_47 ;
}
* V_469 = V_83 ;
* V_84 = V_470 ;
}
return 0 ;
}
static int F_188 ( struct V_19 * V_270 , struct V_52 * V_52 , int V_302 )
{
return F_108 ( V_270 , V_52 , V_29 ) ;
}
static int F_189 ( struct V_52 * V_291 , struct V_19 * V_270 , struct V_52 * V_293 )
{
return F_110 ( V_270 , V_291 , V_284 ) ;
}
static int F_190 ( struct V_19 * V_270 , struct V_52 * V_52 )
{
return F_110 ( V_270 , V_52 , V_286 ) ;
}
static int F_191 ( struct V_19 * V_270 , struct V_52 * V_52 , const char * V_64 )
{
return F_108 ( V_270 , V_52 , V_156 ) ;
}
static int F_192 ( struct V_19 * V_270 , struct V_52 * V_52 , int V_302 )
{
return F_108 ( V_270 , V_52 , V_161 ) ;
}
static int F_193 ( struct V_19 * V_270 , struct V_52 * V_52 )
{
return F_110 ( V_270 , V_52 , V_288 ) ;
}
static int F_194 ( struct V_19 * V_270 , struct V_52 * V_52 , int V_151 , T_8 V_221 )
{
return F_108 ( V_270 , V_52 , F_68 ( V_151 ) ) ;
}
static int F_195 ( struct V_19 * V_473 , struct V_52 * V_291 ,
struct V_19 * V_474 , struct V_52 * V_293 )
{
return F_111 ( V_473 , V_291 , V_474 , V_293 ) ;
}
static int F_196 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_306 ) ;
}
static int F_197 ( struct V_52 * V_52 , struct V_475 * V_475 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_306 ) ;
}
static int F_198 ( struct V_19 * V_19 , int V_302 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
T_2 V_238 ;
bool V_476 ;
unsigned V_69 = V_302 & V_477 ;
V_476 = V_302 & V_478 ;
V_302 &= ( V_305 | V_309 | V_303 | V_307 ) ;
if ( ! V_302 )
return 0 ;
F_95 ( & V_252 , V_264 ) ;
V_252 . V_257 . V_19 = V_19 ;
if ( V_476 )
V_252 . V_479 . V_480 |= V_481 ;
V_238 = F_114 ( V_19 -> V_226 , V_302 ) ;
return F_100 ( V_7 , V_19 , V_238 , & V_252 , V_69 ) ;
}
static int F_199 ( struct V_52 * V_52 , struct V_482 * V_482 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_483 = V_482 -> V_483 ;
if ( V_483 & V_484 ) {
V_483 &= ~ ( V_485 | V_486 | V_487 |
V_484 ) ;
if ( ! V_483 )
return 0 ;
}
if ( V_483 & ( V_487 | V_488 | V_489 |
V_490 | V_491 | V_492 ) )
return F_105 ( V_7 , V_52 , V_493 ) ;
return F_105 ( V_7 , V_52 , V_310 ) ;
}
static int F_200 ( struct V_466 * V_376 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_215 V_215 ;
V_215 . V_52 = V_52 ;
V_215 . V_376 = V_376 ;
return F_106 ( V_7 , & V_215 , V_494 ) ;
}
static int F_201 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_495 ,
sizeof V_495 - 1 ) ) {
if ( ! strcmp ( V_64 , V_496 ) ) {
if ( ! F_202 ( V_497 ) )
return - V_384 ;
} else if ( ! F_202 ( V_366 ) ) {
return - V_384 ;
}
}
return F_105 ( V_7 , V_52 , V_493 ) ;
}
static int F_203 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_469 , T_7 V_498 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_251 V_252 ;
T_2 V_272 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_201 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_204 ( V_19 ) )
return - V_384 ;
F_95 ( & V_252 , V_265 ) ;
V_252 . V_257 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_499 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_469 , V_498 , & V_272 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_202 ( V_500 ) )
return V_47 ;
V_47 = F_205 ( V_469 , V_498 , & V_272 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_272 , V_21 -> V_28 ,
V_501 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_206 ( V_21 -> V_14 , V_272 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_272 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_252 ) ;
}
static void F_207 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_469 , T_7 V_498 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_272 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_205 ( V_469 , V_498 , & V_272 ) ;
if ( V_47 ) {
F_38 ( V_73 L_36
L_37 ,
V_19 -> V_33 -> V_62 , V_19 -> V_220 , - V_47 ) ;
return;
}
V_21 -> V_14 = V_272 ;
return;
}
static int F_208 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_494 ) ;
}
static int F_209 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_494 ) ;
}
static int F_210 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_201 ( V_52 , V_64 ) ;
return - V_502 ;
}
static int F_211 ( const struct V_19 * V_19 , const char * V_64 , void * * V_214 , bool V_503 )
{
T_2 V_498 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_472 ) )
return - V_65 ;
error = F_125 ( V_8 , F_52 () ,
& V_365 , V_500 ,
V_367 ) ;
if ( ! error )
error = F_187 ( V_21 -> V_14 , & V_83 ,
& V_498 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_498 ) ;
if ( error )
return error ;
error = V_498 ;
if ( V_503 ) {
* V_214 = V_83 ;
goto V_504;
}
F_28 ( V_83 ) ;
V_504:
return error ;
}
static int F_212 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_469 , T_7 V_498 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_272 ;
int V_47 ;
if ( strcmp ( V_64 , V_472 ) )
return - V_65 ;
if ( ! V_469 || ! V_498 )
return - V_502 ;
V_47 = F_54 ( ( void * ) V_469 , V_498 , & V_272 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_14 = V_272 ;
V_21 -> V_114 = 1 ;
return 0 ;
}
static int F_213 ( struct V_19 * V_19 , char * V_214 , T_7 V_505 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_214 && V_84 <= V_505 )
memcpy ( V_214 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_214 ( const struct V_19 * V_19 , T_2 * V_506 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_506 = V_21 -> V_14 ;
}
static int F_215 ( struct V_36 * V_36 , int V_302 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = V_36 -> V_267 . V_52 -> V_56 ;
if ( ( V_36 -> V_316 & V_317 ) && ( V_302 & V_309 ) )
V_302 |= V_307 ;
return F_107 ( V_7 , V_36 ,
F_114 ( V_19 -> V_226 , V_302 ) ) ;
}
static int F_216 ( struct V_36 * V_36 , int V_302 )
{
struct V_19 * V_19 = V_36 -> V_267 . V_52 -> V_56 ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_302 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_507 == V_21 -> V_14 &&
V_38 -> V_508 == F_217 () )
return 0 ;
return F_215 ( V_36 , V_302 ) ;
}
static int F_218 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_219 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_220 ( struct V_36 * V_36 , unsigned int V_509 ,
unsigned long V_510 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_509 ) {
case V_511 :
case V_512 :
case V_513 :
case V_514 :
case V_515 :
error = F_107 ( V_7 , V_36 , V_494 ) ;
break;
case V_516 :
case V_517 :
error = F_107 ( V_7 , V_36 , V_493 ) ;
break;
case V_518 :
case V_519 :
error = F_107 ( V_7 , V_36 , 0 ) ;
break;
case V_520 :
case V_521 :
error = F_93 ( V_8 , V_7 , V_522 ,
V_260 ) ;
break;
default:
error = F_107 ( V_7 , V_36 , V_318 ) ;
}
return error ;
}
static int F_221 ( struct V_36 * V_36 , unsigned long V_523 , int V_524 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_525 &&
( V_523 & V_526 ) && ( ! V_36 || ( ! V_524 && ( V_523 & V_527 ) ) ) ) {
V_47 = F_90 ( V_7 , V_7 , V_528 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_255 = V_306 ;
if ( V_524 && ( V_523 & V_527 ) )
V_255 |= V_310 ;
if ( V_523 & V_526 )
V_255 |= V_304 ;
return F_107 ( V_7 , V_36 , V_255 ) ;
}
error:
return V_47 ;
}
static int F_222 ( struct V_36 * V_36 , unsigned long V_529 ,
unsigned long V_523 , unsigned long V_69 ,
unsigned long V_530 , unsigned long V_531 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_530 < V_532 ) {
V_47 = F_35 ( V_14 , V_14 , V_533 ,
V_534 , NULL ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_223 ( V_36 , V_529 , V_523 , V_69 , V_530 , V_531 ) ;
if ( V_47 || V_531 )
return V_47 ;
if ( V_535 )
V_523 = V_529 ;
return F_221 ( V_36 , V_523 ,
( V_69 & V_536 ) == V_537 ) ;
}
static int F_224 ( struct V_538 * V_539 ,
unsigned long V_529 ,
unsigned long V_523 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_535 )
V_523 = V_529 ;
if ( V_525 &&
( V_523 & V_526 ) && ! ( V_539 -> V_540 & V_541 ) ) {
int V_47 = 0 ;
if ( V_539 -> V_542 >= V_539 -> V_543 -> V_544 &&
V_539 -> V_545 <= V_539 -> V_543 -> V_546 ) {
V_47 = F_90 ( V_7 , V_7 , V_547 ) ;
} else if ( ! V_539 -> V_548 &&
V_539 -> V_542 <= V_539 -> V_543 -> V_549 &&
V_539 -> V_545 >= V_539 -> V_543 -> V_549 ) {
V_47 = F_92 ( V_8 , V_550 ) ;
} else if ( V_539 -> V_548 && V_539 -> V_551 ) {
V_47 = F_107 ( V_7 , V_539 -> V_548 , V_552 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_221 ( V_539 -> V_548 , V_523 , V_539 -> V_540 & V_553 ) ;
}
static int F_225 ( struct V_36 * V_36 , unsigned int V_509 )
{
const struct V_7 * V_7 = F_52 () ;
return F_107 ( V_7 , V_36 , V_554 ) ;
}
static int F_226 ( struct V_36 * V_36 , unsigned int V_509 ,
unsigned long V_510 )
{
const struct V_7 * V_7 = F_52 () ;
int V_555 = 0 ;
switch ( V_509 ) {
case V_556 :
if ( ! V_36 -> V_267 . V_52 || ! V_36 -> V_267 . V_52 -> V_56 ) {
V_555 = - V_86 ;
break;
}
if ( ( V_36 -> V_316 & V_317 ) && ! ( V_510 & V_317 ) ) {
V_555 = F_107 ( V_7 , V_36 , V_310 ) ;
break;
}
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
V_555 = F_107 ( V_7 , V_36 , 0 ) ;
break;
case V_562 :
case V_563 :
case V_564 :
#if V_565 == 32
case V_566 :
case V_567 :
case V_568 :
#endif
if ( ! V_36 -> V_267 . V_52 || ! V_36 -> V_267 . V_52 -> V_56 ) {
V_555 = - V_86 ;
break;
}
V_555 = F_107 ( V_7 , V_36 , V_554 ) ;
break;
}
return V_555 ;
}
static int F_227 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_228 ( struct V_17 * V_248 ,
struct V_569 * V_570 , int V_571 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_248 ) ;
T_2 V_228 ;
struct V_37 * V_38 ;
V_36 = F_229 ( V_570 , struct V_36 , V_572 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_571 )
V_228 = F_89 ( V_573 ) ;
else
V_228 = F_89 ( V_571 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_241 , V_228 , NULL ) ;
}
static int F_230 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_107 ( V_7 , V_36 , F_115 ( V_36 ) ) ;
}
static int F_231 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_19 * V_19 ;
struct V_20 * V_21 ;
V_19 = V_36 -> V_267 . V_52 -> V_56 ;
V_38 = V_36 -> V_40 ;
V_21 = V_19 -> V_30 ;
V_38 -> V_507 = V_21 -> V_14 ;
V_38 -> V_508 = F_217 () ;
return F_104 ( V_7 , V_19 , F_116 ( V_36 ) , 0 ) ;
}
static int F_232 ( unsigned long V_574 )
{
return F_92 ( V_8 , V_575 ) ;
}
static int F_233 ( struct V_7 * V_7 , T_9 V_576 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_576 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_234 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_216 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_235 ( struct V_7 * V_330 , const struct V_7 * V_331 ,
T_9 V_576 )
{
const struct V_10 * V_370 ;
struct V_10 * V_11 ;
V_370 = V_331 -> V_16 ;
V_11 = F_236 ( V_370 , sizeof( struct V_10 ) , V_576 ) ;
if ( ! V_11 )
return - V_24 ;
V_330 -> V_16 = V_11 ;
return 0 ;
}
static void F_237 ( struct V_7 * V_330 , const struct V_7 * V_331 )
{
const struct V_10 * V_370 = V_331 -> V_16 ;
struct V_10 * V_11 = V_330 -> V_16 ;
* V_11 = * V_370 ;
}
static int F_238 ( struct V_7 * V_330 , T_2 V_506 )
{
struct V_10 * V_11 = V_330 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_577 ;
V_577 = F_35 ( V_14 , V_506 ,
V_578 ,
V_579 ,
NULL ) ;
if ( V_577 == 0 ) {
V_11 -> V_14 = V_506 ;
V_11 -> V_273 = 0 ;
V_11 -> V_373 = 0 ;
V_11 -> V_374 = 0 ;
}
return V_577 ;
}
static int F_239 ( struct V_7 * V_330 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_330 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_577 ;
V_577 = F_35 ( V_14 , V_21 -> V_14 ,
V_578 ,
V_580 ,
NULL ) ;
if ( V_577 == 0 )
V_11 -> V_273 = V_21 -> V_14 ;
return V_577 ;
}
static int F_240 ( char * V_581 )
{
T_2 V_14 ;
struct V_251 V_252 ;
V_14 = F_10 ( V_8 ) ;
F_95 ( & V_252 , V_582 ) ;
V_252 . V_257 . V_581 = V_581 ;
return F_35 ( V_14 , V_15 , V_262 ,
V_583 , & V_252 ) ;
}
static int F_241 ( struct V_17 * V_127 , T_10 V_584 )
{
return F_92 ( V_127 , V_585 ) ;
}
static int F_242 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_586 ) ;
}
static int F_243 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_587 ) ;
}
static void F_244 ( struct V_17 * V_127 , T_2 * V_506 )
{
* V_506 = F_10 ( V_127 ) ;
}
static int F_245 ( struct V_17 * V_127 , int V_588 )
{
int V_47 ;
V_47 = F_246 ( V_127 , V_588 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_589 ) ;
}
static int F_247 ( struct V_17 * V_127 , int V_590 )
{
int V_47 ;
V_47 = F_248 ( V_127 , V_590 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_589 ) ;
}
static int F_249 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_591 ) ;
}
static int F_250 ( struct V_17 * V_127 , unsigned int V_592 ,
struct V_417 * V_593 )
{
struct V_417 * V_594 = V_127 -> signal -> V_418 + V_592 ;
if ( V_594 -> V_425 != V_593 -> V_425 )
return F_92 ( V_127 , V_595 ) ;
return 0 ;
}
static int F_251 ( struct V_17 * V_127 )
{
int V_47 ;
V_47 = F_252 ( V_127 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_589 ) ;
}
static int F_253 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_591 ) ;
}
static int F_254 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_589 ) ;
}
static int F_255 ( struct V_17 * V_127 , struct V_596 * V_597 ,
int V_227 , T_2 V_506 )
{
T_2 V_228 ;
int V_47 ;
if ( ! V_227 )
V_228 = V_598 ;
else
V_228 = F_89 ( V_227 ) ;
if ( V_506 )
V_47 = F_35 ( V_506 , F_10 ( V_127 ) ,
V_241 , V_228 , NULL ) ;
else
V_47 = F_92 ( V_127 , V_228 ) ;
return V_47 ;
}
static int F_256 ( struct V_17 * V_127 )
{
return F_91 ( V_127 , V_8 , V_230 ) ;
}
static void F_257 ( struct V_17 * V_127 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_127 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_114 = 1 ;
}
static int F_258 ( struct V_599 * V_600 ,
struct V_251 * V_252 , T_11 * V_601 )
{
int V_602 , V_603 , V_577 = - V_86 ;
struct V_604 V_605 , * V_606 ;
V_602 = F_259 ( V_600 ) ;
V_606 = F_260 ( V_600 , V_602 , sizeof( V_605 ) , & V_605 ) ;
if ( V_606 == NULL )
goto V_66;
V_603 = V_606 -> V_607 * 4 ;
if ( V_603 < sizeof( V_605 ) )
goto V_66;
V_252 -> V_257 . V_608 . V_609 . V_610 = V_606 -> V_610 ;
V_252 -> V_257 . V_608 . V_609 . V_611 = V_606 -> V_611 ;
V_577 = 0 ;
if ( V_601 )
* V_601 = V_606 -> V_166 ;
switch ( V_606 -> V_166 ) {
case V_168 : {
struct V_612 V_613 , * V_614 ;
if ( F_261 ( V_606 -> V_615 ) & V_616 )
break;
V_602 += V_603 ;
V_614 = F_260 ( V_600 , V_602 , sizeof( V_613 ) , & V_613 ) ;
if ( V_614 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_614 -> V_618 ;
V_252 -> V_257 . V_608 . V_619 = V_614 -> V_620 ;
break;
}
case V_169 : {
struct V_621 V_622 , * V_623 ;
if ( F_261 ( V_606 -> V_615 ) & V_616 )
break;
V_602 += V_603 ;
V_623 = F_260 ( V_600 , V_602 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_623 -> V_618 ;
V_252 -> V_257 . V_608 . V_619 = V_623 -> V_620 ;
break;
}
case V_624 : {
struct V_625 V_626 , * V_627 ;
if ( F_261 ( V_606 -> V_615 ) & V_616 )
break;
V_602 += V_603 ;
V_627 = F_260 ( V_600 , V_602 , sizeof( V_626 ) , & V_626 ) ;
if ( V_627 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_627 -> V_628 ;
V_252 -> V_257 . V_608 . V_619 = V_627 -> V_629 ;
break;
}
default:
break;
}
V_66:
return V_577 ;
}
static int F_262 ( struct V_599 * V_600 ,
struct V_251 * V_252 , T_11 * V_601 )
{
T_11 V_630 ;
int V_577 = - V_86 , V_602 ;
struct V_631 V_632 , * V_633 ;
V_602 = F_259 ( V_600 ) ;
V_633 = F_260 ( V_600 , V_602 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
goto V_66;
F_263 ( & V_252 -> V_257 . V_608 . V_634 . V_610 , & V_633 -> V_610 ) ;
F_263 ( & V_252 -> V_257 . V_608 . V_634 . V_611 , & V_633 -> V_611 ) ;
V_577 = 0 ;
V_630 = V_633 -> V_630 ;
V_602 += sizeof( V_632 ) ;
V_602 = F_264 ( V_600 , V_602 , & V_630 ) ;
if ( V_602 < 0 )
goto V_66;
if ( V_601 )
* V_601 = V_630 ;
switch ( V_630 ) {
case V_168 : {
struct V_612 V_613 , * V_614 ;
V_614 = F_260 ( V_600 , V_602 , sizeof( V_613 ) , & V_613 ) ;
if ( V_614 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_614 -> V_618 ;
V_252 -> V_257 . V_608 . V_619 = V_614 -> V_620 ;
break;
}
case V_169 : {
struct V_621 V_622 , * V_623 ;
V_623 = F_260 ( V_600 , V_602 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_623 -> V_618 ;
V_252 -> V_257 . V_608 . V_619 = V_623 -> V_620 ;
break;
}
case V_624 : {
struct V_625 V_626 , * V_627 ;
V_627 = F_260 ( V_600 , V_602 , sizeof( V_626 ) , & V_626 ) ;
if ( V_627 == NULL )
break;
V_252 -> V_257 . V_608 . V_617 = V_627 -> V_628 ;
V_252 -> V_257 . V_608 . V_619 = V_627 -> V_629 ;
break;
}
default:
break;
}
V_66:
return V_577 ;
}
static int F_265 ( struct V_599 * V_600 , struct V_251 * V_252 ,
char * * V_635 , int V_636 , T_11 * V_601 )
{
char * V_637 ;
int V_577 ;
switch ( V_252 -> V_257 . V_608 . V_170 ) {
case V_177 :
V_577 = F_258 ( V_600 , V_252 , V_601 ) ;
if ( V_577 )
goto V_638;
V_637 = ( char * ) ( V_636 ? & V_252 -> V_257 . V_608 . V_609 . V_610 :
& V_252 -> V_257 . V_608 . V_609 . V_611 ) ;
goto V_639;
#if F_266 ( V_640 ) || F_266 ( V_641 )
case V_178 :
V_577 = F_262 ( V_600 , V_252 , V_601 ) ;
if ( V_577 )
goto V_638;
V_637 = ( char * ) ( V_636 ? & V_252 -> V_257 . V_608 . V_634 . V_610 :
& V_252 -> V_257 . V_608 . V_634 . V_611 ) ;
goto V_639;
#endif
default:
V_637 = NULL ;
goto V_639;
}
V_638:
F_38 ( V_61
L_38
L_39 ) ;
return V_577 ;
V_639:
if ( V_635 )
* V_635 = V_637 ;
return 0 ;
}
static int F_267 ( struct V_599 * V_600 , T_4 V_170 , T_2 * V_14 )
{
int V_555 ;
T_2 V_642 ;
T_2 V_643 ;
T_2 V_644 ;
F_268 ( V_600 , & V_642 ) ;
F_269 ( V_600 , V_170 , & V_644 , & V_643 ) ;
V_555 = F_270 ( V_643 , V_644 , V_642 , V_14 ) ;
if ( F_102 ( V_555 ) ) {
F_38 ( V_61
L_40
L_41 ) ;
return - V_502 ;
}
return 0 ;
}
static int F_271 ( const struct V_10 * V_11 ,
T_4 V_645 , T_2 * V_646 )
{
if ( V_11 -> V_374 > V_647 ) {
* V_646 = V_11 -> V_374 ;
return 0 ;
}
return F_87 ( V_11 -> V_14 , V_11 -> V_14 , V_645 , NULL ,
V_646 ) ;
}
static int F_272 ( struct V_17 * V_18 , struct V_648 * V_649 , T_2 V_238 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_251 V_252 ;
T_2 V_240 = F_10 ( V_18 ) ;
if ( V_651 -> V_14 == V_15 )
return 0 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_649 = V_649 ;
return F_35 ( V_240 , V_651 -> V_14 , V_651 -> V_28 , V_238 , & V_252 ) ;
}
static int F_273 ( int V_170 , int type ,
int V_166 , int V_654 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_272 ;
T_4 V_645 ;
int V_47 ;
if ( V_654 )
return 0 ;
V_645 = F_71 ( V_170 , type , V_166 ) ;
V_47 = F_271 ( V_11 , V_645 , & V_272 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_272 , V_645 , V_655 , NULL ) ;
}
static int F_274 ( struct V_656 * V_648 , int V_170 ,
int type , int V_166 , int V_654 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_275 ( V_648 ) -> V_30 ;
struct V_650 * V_651 ;
int V_555 = 0 ;
V_21 -> V_28 = F_71 ( V_170 , type , V_166 ) ;
if ( V_654 )
V_21 -> V_14 = V_15 ;
else {
V_555 = F_271 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_555 )
return V_555 ;
}
V_21 -> V_114 = 1 ;
if ( V_648 -> V_649 ) {
V_651 = V_648 -> V_649 -> V_652 ;
V_651 -> V_14 = V_21 -> V_14 ;
V_651 -> V_28 = V_21 -> V_28 ;
V_555 = F_276 ( V_648 -> V_649 , V_170 ) ;
}
return V_555 ;
}
static int F_277 ( struct V_656 * V_648 , struct V_657 * V_658 , int V_659 )
{
struct V_648 * V_649 = V_648 -> V_649 ;
T_4 V_170 ;
int V_555 ;
V_555 = F_272 ( V_8 , V_649 , V_660 ) ;
if ( V_555 )
goto V_66;
V_170 = V_649 -> V_661 ;
if ( V_170 == V_177 || V_170 == V_178 ) {
char * V_637 ;
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_251 V_252 ;
struct V_662 * V_663 = NULL ;
struct V_664 * V_665 = NULL ;
unsigned short V_666 ;
T_2 V_14 , V_667 ;
if ( V_170 == V_177 ) {
V_663 = (struct V_662 * ) V_658 ;
V_666 = F_261 ( V_663 -> V_668 ) ;
V_637 = ( char * ) & V_663 -> V_669 . V_670 ;
} else {
V_665 = (struct V_664 * ) V_658 ;
V_666 = F_261 ( V_665 -> V_671 ) ;
V_637 = ( char * ) & V_665 -> V_672 . V_673 ;
}
if ( V_666 ) {
int V_674 , V_675 ;
F_278 ( & V_674 , & V_675 ) ;
if ( V_666 < V_676 ( V_677, V_674 ) || V_666 > V_675 ) {
V_555 = F_279 ( V_649 -> V_678 ,
V_666 , & V_14 ) ;
if ( V_555 )
goto V_66;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_617 = F_280 ( V_666 ) ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
V_555 = F_35 ( V_651 -> V_14 , V_14 ,
V_651 -> V_28 ,
V_679 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
}
switch ( V_651 -> V_28 ) {
case V_179 :
V_667 = V_680 ;
break;
case V_181 :
V_667 = V_681 ;
break;
case V_183 :
V_667 = V_682 ;
break;
default:
V_667 = V_683 ;
break;
}
V_555 = F_281 ( V_637 , V_170 , & V_14 ) ;
if ( V_555 )
goto V_66;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_617 = F_280 ( V_666 ) ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
if ( V_170 == V_177 )
V_252 . V_257 . V_608 . V_609 . V_610 = V_663 -> V_669 . V_670 ;
else
F_263 ( & V_252 . V_257 . V_608 . V_634 . V_610 , & V_665 -> V_672 ) ;
V_555 = F_35 ( V_651 -> V_14 , V_14 ,
V_651 -> V_28 , V_667 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
V_66:
return V_555 ;
}
static int F_282 ( struct V_656 * V_648 , struct V_657 * V_658 , int V_659 )
{
struct V_648 * V_649 = V_648 -> V_649 ;
struct V_650 * V_651 = V_649 -> V_652 ;
int V_555 ;
V_555 = F_272 ( V_8 , V_649 , V_684 ) ;
if ( V_555 )
return V_555 ;
if ( V_651 -> V_28 == V_179 ||
V_651 -> V_28 == V_183 ) {
struct V_251 V_252 ;
struct V_662 * V_663 = NULL ;
struct V_664 * V_665 = NULL ;
unsigned short V_666 ;
T_2 V_14 , V_228 ;
if ( V_649 -> V_661 == V_177 ) {
V_663 = (struct V_662 * ) V_658 ;
if ( V_659 < sizeof( struct V_662 ) )
return - V_86 ;
V_666 = F_261 ( V_663 -> V_668 ) ;
} else {
V_665 = (struct V_664 * ) V_658 ;
if ( V_659 < V_685 )
return - V_86 ;
V_666 = F_261 ( V_665 -> V_671 ) ;
}
V_555 = F_279 ( V_649 -> V_678 , V_666 , & V_14 ) ;
if ( V_555 )
goto V_66;
V_228 = ( V_651 -> V_28 == V_179 ) ?
V_686 : V_687 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_619 = F_280 ( V_666 ) ;
V_252 . V_257 . V_608 . V_170 = V_649 -> V_661 ;
V_555 = F_35 ( V_651 -> V_14 , V_14 , V_651 -> V_28 , V_228 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
V_555 = F_283 ( V_649 , V_658 ) ;
V_66:
return V_555 ;
}
static int F_284 ( struct V_656 * V_648 , int V_688 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_689 ) ;
}
static int F_285 ( struct V_656 * V_648 , struct V_656 * V_690 )
{
int V_555 ;
struct V_20 * V_21 ;
struct V_20 * V_123 ;
V_555 = F_272 ( V_8 , V_648 -> V_649 , V_691 ) ;
if ( V_555 )
return V_555 ;
V_123 = F_275 ( V_690 ) -> V_30 ;
V_21 = F_275 ( V_648 ) -> V_30 ;
V_123 -> V_28 = V_21 -> V_28 ;
V_123 -> V_14 = V_21 -> V_14 ;
V_123 -> V_114 = 1 ;
return 0 ;
}
static int F_286 ( struct V_656 * V_648 , struct V_692 * V_693 ,
int V_498 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_694 ) ;
}
static int F_287 ( struct V_656 * V_648 , struct V_692 * V_693 ,
int V_498 , int V_69 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_695 ) ;
}
static int F_288 ( struct V_656 * V_648 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_696 ) ;
}
static int F_289 ( struct V_656 * V_648 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_696 ) ;
}
static int F_290 ( struct V_656 * V_648 , int V_697 , int V_698 )
{
int V_555 ;
V_555 = F_272 ( V_8 , V_648 -> V_649 , V_699 ) ;
if ( V_555 )
return V_555 ;
return F_291 ( V_648 , V_697 , V_698 ) ;
}
static int F_292 ( struct V_656 * V_648 , int V_697 ,
int V_698 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_700 ) ;
}
static int F_293 ( struct V_656 * V_648 , int V_701 )
{
return F_272 ( V_8 , V_648 -> V_649 , V_702 ) ;
}
static int F_294 ( struct V_648 * V_648 ,
struct V_648 * V_703 ,
struct V_648 * V_704 )
{
struct V_650 * V_705 = V_648 -> V_652 ;
struct V_650 * V_706 = V_703 -> V_652 ;
struct V_650 * V_707 = V_704 -> V_652 ;
struct V_251 V_252 ;
int V_555 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_649 = V_703 ;
V_555 = F_35 ( V_705 -> V_14 , V_706 -> V_14 ,
V_706 -> V_28 ,
V_708 , & V_252 ) ;
if ( V_555 )
return V_555 ;
V_707 -> V_709 = V_705 -> V_14 ;
V_555 = F_295 ( V_706 -> V_14 , V_705 -> V_14 ,
& V_707 -> V_14 ) ;
if ( V_555 )
return V_555 ;
V_705 -> V_709 = V_707 -> V_14 ;
return 0 ;
}
static int F_296 ( struct V_656 * V_648 ,
struct V_656 * V_703 )
{
struct V_650 * V_710 = V_648 -> V_649 -> V_652 ;
struct V_650 * V_711 = V_703 -> V_649 -> V_652 ;
struct V_251 V_252 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_649 = V_703 -> V_649 ;
return F_35 ( V_710 -> V_14 , V_711 -> V_14 , V_711 -> V_28 , V_712 ,
& V_252 ) ;
}
static int F_297 ( int V_713 , char * V_637 , T_4 V_170 ,
T_2 V_709 ,
struct V_251 * V_252 )
{
int V_555 ;
T_2 V_714 ;
T_2 V_715 ;
V_555 = F_298 ( V_713 , & V_714 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_35 ( V_709 , V_714 ,
V_716 , V_717 , V_252 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_281 ( V_637 , V_170 , & V_715 ) ;
if ( V_555 )
return V_555 ;
return F_35 ( V_709 , V_715 ,
V_718 , V_719 , V_252 ) ;
}
static int F_299 ( struct V_648 * V_649 , struct V_599 * V_600 ,
T_4 V_170 )
{
int V_555 = 0 ;
struct V_650 * V_651 = V_649 -> V_652 ;
T_2 V_720 = V_651 -> V_14 ;
struct V_251 V_252 ;
char * V_637 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_721 = V_600 -> V_722 ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
V_555 = F_265 ( V_600 , & V_252 , & V_637 , 1 , NULL ) ;
if ( V_555 )
return V_555 ;
if ( F_4 () ) {
V_555 = F_35 ( V_720 , V_600 -> V_723 , V_724 ,
V_725 , & V_252 ) ;
if ( V_555 )
return V_555 ;
}
V_555 = F_300 ( V_651 , V_600 , V_170 , & V_252 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_301 ( V_651 -> V_14 , V_600 , & V_252 ) ;
return V_555 ;
}
static int F_302 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 ;
struct V_650 * V_651 = V_649 -> V_652 ;
T_4 V_170 = V_649 -> V_661 ;
T_2 V_720 = V_651 -> V_14 ;
struct V_251 V_252 ;
char * V_637 ;
T_11 V_726 ;
T_11 V_727 ;
if ( V_170 != V_177 && V_170 != V_178 )
return 0 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_280 ( V_728 ) )
V_170 = V_177 ;
if ( ! V_729 )
return F_299 ( V_649 , V_600 , V_170 ) ;
V_726 = F_4 () ;
V_727 = F_303 () || F_304 () ;
if ( ! V_726 && ! V_727 )
return 0 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_721 = V_600 -> V_722 ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
V_555 = F_265 ( V_600 , & V_252 , & V_637 , 1 , NULL ) ;
if ( V_555 )
return V_555 ;
if ( V_727 ) {
T_2 V_709 ;
V_555 = F_267 ( V_600 , V_170 , & V_709 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_297 ( V_600 -> V_722 , V_637 , V_170 ,
V_709 , & V_252 ) ;
if ( V_555 ) {
F_305 ( V_600 , V_555 , 0 ) ;
return V_555 ;
}
V_555 = F_35 ( V_720 , V_709 , V_730 ,
V_731 , & V_252 ) ;
if ( V_555 )
F_305 ( V_600 , V_555 , 0 ) ;
}
if ( V_726 ) {
V_555 = F_35 ( V_720 , V_600 -> V_723 , V_724 ,
V_725 , & V_252 ) ;
if ( V_555 )
return V_555 ;
}
return V_555 ;
}
static int F_306 ( struct V_656 * V_648 , char T_12 * V_732 ,
int T_12 * V_733 , unsigned V_84 )
{
int V_555 = 0 ;
char * V_734 ;
T_2 V_735 ;
struct V_650 * V_651 = V_648 -> V_649 -> V_652 ;
T_2 V_709 = V_647 ;
if ( V_651 -> V_28 == V_174 ||
V_651 -> V_28 == V_179 )
V_709 = V_651 -> V_709 ;
if ( V_709 == V_647 )
return - V_736 ;
V_555 = F_47 ( V_709 , & V_734 , & V_735 ) ;
if ( V_555 )
return V_555 ;
if ( V_735 > V_84 ) {
V_555 = - V_219 ;
goto V_737;
}
if ( F_307 ( V_732 , V_734 , V_735 ) )
V_555 = - V_738 ;
V_737:
if ( F_308 ( V_735 , V_733 ) )
V_555 = - V_738 ;
F_28 ( V_734 ) ;
return V_555 ;
}
static int F_309 ( struct V_656 * V_648 , struct V_599 * V_600 , T_2 * V_506 )
{
T_2 V_739 = V_647 ;
T_4 V_170 ;
if ( V_600 && V_600 -> V_166 == F_280 ( V_728 ) )
V_170 = V_177 ;
else if ( V_600 && V_600 -> V_166 == F_280 ( V_740 ) )
V_170 = V_178 ;
else if ( V_648 )
V_170 = V_648 -> V_649 -> V_661 ;
else
goto V_66;
if ( V_648 && V_170 == V_171 )
F_214 ( F_275 ( V_648 ) , & V_739 ) ;
else if ( V_600 )
F_267 ( V_600 , V_170 , & V_739 ) ;
V_66:
* V_506 = V_739 ;
if ( V_739 == V_647 )
return - V_86 ;
return 0 ;
}
static int F_310 ( struct V_648 * V_649 , int V_170 , T_9 V_741 )
{
struct V_650 * V_651 ;
V_651 = F_7 ( sizeof( * V_651 ) , V_741 ) ;
if ( ! V_651 )
return - V_24 ;
V_651 -> V_709 = V_27 ;
V_651 -> V_14 = V_27 ;
F_311 ( V_651 ) ;
V_649 -> V_652 = V_651 ;
return 0 ;
}
static void F_312 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
V_649 -> V_652 = NULL ;
F_313 ( V_651 ) ;
F_28 ( V_651 ) ;
}
static void F_314 ( const struct V_648 * V_649 , struct V_648 * V_704 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_650 * V_742 = V_704 -> V_652 ;
V_742 -> V_14 = V_651 -> V_14 ;
V_742 -> V_709 = V_651 -> V_709 ;
V_742 -> V_28 = V_651 -> V_28 ;
F_311 ( V_742 ) ;
}
static void F_315 ( struct V_648 * V_649 , T_2 * V_506 )
{
if ( ! V_649 )
* V_506 = V_743 ;
else {
struct V_650 * V_651 = V_649 -> V_652 ;
* V_506 = V_651 -> V_14 ;
}
}
static void F_316 ( struct V_648 * V_649 , struct V_656 * V_325 )
{
struct V_20 * V_21 = F_275 ( V_325 ) -> V_30 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_649 -> V_661 == V_177 || V_649 -> V_661 == V_178 ||
V_649 -> V_661 == V_171 )
V_21 -> V_14 = V_651 -> V_14 ;
V_651 -> V_28 = V_21 -> V_28 ;
}
static int F_317 ( struct V_648 * V_649 , struct V_599 * V_600 ,
struct V_744 * V_745 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
int V_555 ;
T_4 V_170 = V_649 -> V_661 ;
T_2 V_272 ;
T_2 V_746 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_280 ( V_728 ) )
V_170 = V_177 ;
V_555 = F_267 ( V_600 , V_170 , & V_746 ) ;
if ( V_555 )
return V_555 ;
if ( V_746 == V_647 ) {
V_745 -> V_506 = V_651 -> V_14 ;
V_745 -> V_739 = V_647 ;
} else {
V_555 = F_295 ( V_651 -> V_14 , V_746 , & V_272 ) ;
if ( V_555 )
return V_555 ;
V_745 -> V_506 = V_272 ;
V_745 -> V_739 = V_746 ;
}
return F_318 ( V_745 , V_170 ) ;
}
static void F_319 ( struct V_648 * V_704 ,
const struct V_744 * V_745 )
{
struct V_650 * V_742 = V_704 -> V_652 ;
V_742 -> V_14 = V_745 -> V_506 ;
V_742 -> V_709 = V_745 -> V_739 ;
F_320 ( V_704 , V_745 -> V_747 -> V_170 ) ;
}
static void F_321 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
T_4 V_170 = V_649 -> V_661 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_280 ( V_728 ) )
V_170 = V_177 ;
F_267 ( V_600 , V_170 , & V_651 -> V_709 ) ;
}
static int F_322 ( T_2 V_14 )
{
const struct V_10 * V_748 ;
T_2 V_240 ;
V_748 = F_15 () ;
V_240 = V_748 -> V_14 ;
return F_35 ( V_240 , V_14 , V_724 , V_749 , NULL ) ;
}
static void F_323 ( void )
{
F_324 ( & V_6 ) ;
}
static void F_325 ( void )
{
F_326 ( & V_6 ) ;
}
static void F_327 ( const struct V_744 * V_745 ,
struct V_750 * V_751 )
{
V_751 -> V_752 = V_745 -> V_506 ;
}
static int F_328 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_753 , V_754 ,
NULL ) ;
}
static void F_329 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
V_651 -> V_14 = F_14 () ;
V_651 -> V_28 = V_753 ;
}
static int F_330 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
T_2 V_14 = F_14 () ;
int V_555 ;
V_555 = F_35 ( V_14 , V_651 -> V_14 , V_753 ,
V_755 , NULL ) ;
if ( V_555 )
return V_555 ;
V_555 = F_35 ( V_14 , V_14 , V_753 ,
V_756 , NULL ) ;
if ( V_555 )
return V_555 ;
V_651 -> V_14 = V_14 ;
return 0 ;
}
static int F_331 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 = 0 ;
T_2 V_228 ;
struct V_757 * V_758 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_600 -> V_84 < F_332 ( 0 ) ) {
V_555 = - V_86 ;
goto V_66;
}
V_758 = F_333 ( V_600 ) ;
V_555 = F_334 ( V_651 -> V_28 , V_758 -> V_759 , & V_228 ) ;
if ( V_555 ) {
if ( V_555 == - V_86 ) {
F_335 ( V_8 -> V_760 , V_12 , V_761 ,
L_42
L_43 ,
V_758 -> V_759 , V_651 -> V_28 ) ;
if ( ! V_3 || F_336 () )
V_555 = 0 ;
}
if ( V_555 == - V_762 )
V_555 = 0 ;
goto V_66;
}
V_555 = F_272 ( V_8 , V_649 , V_228 ) ;
V_66:
return V_555 ;
}
static unsigned int F_337 ( struct V_599 * V_600 , int V_713 ,
T_4 V_170 )
{
int V_555 ;
char * V_637 ;
T_2 V_709 ;
struct V_251 V_252 ;
T_11 V_726 ;
T_11 V_763 ;
T_11 V_727 ;
if ( ! V_729 )
return V_764 ;
V_726 = F_4 () ;
V_763 = F_303 () ;
V_727 = V_763 || F_304 () ;
if ( ! V_726 && ! V_727 )
return V_764 ;
if ( F_267 ( V_600 , V_170 , & V_709 ) != 0 )
return V_765 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_721 = V_713 ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
if ( F_265 ( V_600 , & V_252 , & V_637 , 1 , NULL ) != 0 )
return V_765 ;
if ( V_727 ) {
V_555 = F_297 ( V_713 , V_637 , V_170 ,
V_709 , & V_252 ) ;
if ( V_555 ) {
F_305 ( V_600 , V_555 , 1 ) ;
return V_765 ;
}
}
if ( V_726 )
if ( F_35 ( V_709 , V_600 -> V_723 ,
V_724 , V_766 , & V_252 ) )
return V_765 ;
if ( V_763 )
if ( F_338 ( V_600 , V_170 , V_709 ) != 0 )
return V_765 ;
return V_764 ;
}
static unsigned int F_339 ( unsigned int V_767 ,
struct V_599 * V_600 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_340)( struct V_599 * ) )
{
return F_337 ( V_600 , V_769 -> V_713 , V_177 ) ;
}
static unsigned int F_341 ( unsigned int V_767 ,
struct V_599 * V_600 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_340)( struct V_599 * ) )
{
return F_337 ( V_600 , V_769 -> V_713 , V_178 ) ;
}
static unsigned int F_342 ( struct V_599 * V_600 ,
T_4 V_170 )
{
T_2 V_14 ;
if ( ! F_303 () )
return V_764 ;
if ( V_600 -> V_649 ) {
struct V_650 * V_651 = V_600 -> V_649 -> V_652 ;
V_14 = V_651 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_338 ( V_600 , V_170 , V_14 ) != 0 )
return V_765 ;
return V_764 ;
}
static unsigned int F_343 ( unsigned int V_767 ,
struct V_599 * V_600 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_340)( struct V_599 * ) )
{
return F_342 ( V_600 , V_177 ) ;
}
static unsigned int F_344 ( struct V_599 * V_600 ,
int V_713 ,
T_4 V_170 )
{
struct V_648 * V_649 = V_600 -> V_649 ;
struct V_650 * V_651 ;
struct V_251 V_252 ;
char * V_637 ;
T_11 V_601 ;
if ( V_649 == NULL )
return V_764 ;
V_651 = V_649 -> V_652 ;
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_721 = V_713 ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
if ( F_265 ( V_600 , & V_252 , & V_637 , 0 , & V_601 ) )
return V_765 ;
if ( F_4 () )
if ( F_35 ( V_651 -> V_14 , V_600 -> V_723 ,
V_724 , V_770 , & V_252 ) )
return F_345 ( - V_771 ) ;
if ( F_346 ( V_651 -> V_14 , V_600 , & V_252 , V_601 ) )
return F_345 ( - V_771 ) ;
return V_764 ;
}
static unsigned int F_347 ( struct V_599 * V_600 , int V_713 ,
T_4 V_170 )
{
T_2 V_772 ;
T_2 V_709 ;
struct V_648 * V_649 ;
struct V_251 V_252 ;
char * V_637 ;
T_11 V_726 ;
T_11 V_727 ;
if ( ! V_729 )
return F_344 ( V_600 , V_713 , V_170 ) ;
#ifdef F_348
if ( F_349 ( V_600 ) != NULL && F_349 ( V_600 ) -> V_773 != NULL )
return V_764 ;
#endif
V_726 = F_4 () ;
V_727 = F_303 () || F_304 () ;
if ( ! V_726 && ! V_727 )
return V_764 ;
V_649 = V_600 -> V_649 ;
if ( V_649 == NULL ) {
if ( V_600 -> V_722 ) {
V_772 = V_774 ;
if ( F_267 ( V_600 , V_170 , & V_709 ) )
return V_765 ;
} else {
V_772 = V_770 ;
V_709 = V_15 ;
}
} else {
struct V_650 * V_651 = V_649 -> V_652 ;
V_709 = V_651 -> V_14 ;
V_772 = V_770 ;
}
F_95 ( & V_252 , V_653 ) ;
V_252 . V_257 . V_608 . V_721 = V_713 ;
V_252 . V_257 . V_608 . V_170 = V_170 ;
if ( F_265 ( V_600 , & V_252 , & V_637 , 0 , NULL ) )
return V_765 ;
if ( V_726 )
if ( F_35 ( V_709 , V_600 -> V_723 ,
V_724 , V_772 , & V_252 ) )
return F_345 ( - V_771 ) ;
if ( V_727 ) {
T_2 V_714 ;
T_2 V_715 ;
if ( F_298 ( V_713 , & V_714 ) )
return V_765 ;
if ( F_35 ( V_709 , V_714 ,
V_716 , V_775 , & V_252 ) )
return F_345 ( - V_771 ) ;
if ( F_281 ( V_637 , V_170 , & V_715 ) )
return V_765 ;
if ( F_35 ( V_709 , V_715 ,
V_718 , V_776 , & V_252 ) )
return F_345 ( - V_771 ) ;
}
return V_764 ;
}
static unsigned int F_350 ( unsigned int V_767 ,
struct V_599 * V_600 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_340)( struct V_599 * ) )
{
return F_347 ( V_600 , V_66 -> V_713 , V_177 ) ;
}
static unsigned int F_351 ( unsigned int V_767 ,
struct V_599 * V_600 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_340)( struct V_599 * ) )
{
return F_347 ( V_600 , V_66 -> V_713 , V_178 ) ;
}
static int F_352 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 ;
V_555 = F_353 ( V_649 , V_600 ) ;
if ( V_555 )
return V_555 ;
return F_331 ( V_649 , V_600 ) ;
}
static int F_354 ( struct V_599 * V_600 , int V_777 )
{
int V_555 ;
struct V_251 V_252 ;
T_2 V_14 ;
V_555 = F_355 ( V_600 , V_777 ) ;
if ( V_555 )
return V_555 ;
F_95 ( & V_252 , V_256 ) ;
V_252 . V_257 . V_249 = V_777 ;
F_356 ( V_8 , & V_14 ) ;
return F_35 ( V_14 , V_14 , V_258 ,
F_94 ( V_777 ) , & V_252 ) ;
}
static int F_357 ( struct V_17 * V_18 ,
struct V_778 * V_228 ,
T_4 V_28 )
{
struct V_779 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_779 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_228 -> V_16 = V_21 ;
return 0 ;
}
static void F_358 ( struct V_778 * V_228 )
{
struct V_779 * V_21 = V_228 -> V_16 ;
V_228 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_359 ( struct V_780 * V_693 )
{
struct V_781 * V_782 ;
V_782 = F_7 ( sizeof( struct V_781 ) , V_12 ) ;
if ( ! V_782 )
return - V_24 ;
V_782 -> V_14 = V_27 ;
V_693 -> V_16 = V_782 ;
return 0 ;
}
static void F_360 ( struct V_780 * V_693 )
{
struct V_781 * V_782 = V_693 -> V_16 ;
V_693 -> V_16 = NULL ;
F_28 ( V_782 ) ;
}
static int F_361 ( struct V_778 * V_783 ,
T_2 V_238 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_783 -> V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_783 -> V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , & V_252 ) ;
}
static int F_362 ( struct V_780 * V_693 )
{
return F_359 ( V_693 ) ;
}
static void F_363 ( struct V_780 * V_693 )
{
F_360 ( V_693 ) ;
}
static int F_364 ( struct V_787 * V_788 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_357 ( V_8 , & V_788 -> V_789 , V_790 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_788 -> V_789 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_790 ,
V_791 , & V_252 ) ;
if ( V_47 ) {
F_358 ( & V_788 -> V_789 ) ;
return V_47 ;
}
return 0 ;
}
static void F_365 ( struct V_787 * V_788 )
{
F_358 ( & V_788 -> V_789 ) ;
}
static int F_366 ( struct V_787 * V_788 , int V_792 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_788 -> V_789 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_788 -> V_789 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_790 ,
V_793 , & V_252 ) ;
}
static int F_367 ( struct V_787 * V_788 , int V_509 )
{
int V_555 ;
int V_238 ;
switch ( V_509 ) {
case V_794 :
case V_795 :
return F_99 ( V_8 , V_796 ) ;
case V_797 :
case V_798 :
V_238 = V_799 | V_793 ;
break;
case V_800 :
V_238 = V_801 ;
break;
case V_802 :
V_238 = V_803 ;
break;
default:
return 0 ;
}
V_555 = F_361 ( & V_788 -> V_789 , V_238 ) ;
return V_555 ;
}
static int F_368 ( struct V_787 * V_788 , struct V_780 * V_693 , int V_792 )
{
struct V_779 * V_21 ;
struct V_781 * V_782 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
V_782 = V_693 -> V_16 ;
if ( V_782 -> V_14 == V_27 ) {
V_47 = F_87 ( V_14 , V_21 -> V_14 , V_804 ,
NULL , & V_782 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_788 -> V_789 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_790 ,
V_805 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_782 -> V_14 , V_804 ,
V_806 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_782 -> V_14 , V_21 -> V_14 , V_790 ,
V_807 , & V_252 ) ;
return V_47 ;
}
static int F_369 ( struct V_787 * V_788 , struct V_780 * V_693 ,
struct V_17 * V_237 ,
long type , int V_151 )
{
struct V_779 * V_21 ;
struct V_781 * V_782 ;
struct V_251 V_252 ;
T_2 V_14 = F_10 ( V_237 ) ;
int V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
V_782 = V_693 -> V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_788 -> V_789 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_790 , V_808 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_782 -> V_14 ,
V_804 , V_809 , & V_252 ) ;
return V_47 ;
}
static int F_370 ( struct V_810 * V_811 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_357 ( V_8 , & V_811 -> V_812 , V_813 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_811 -> V_812 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_811 -> V_812 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_813 ,
V_814 , & V_252 ) ;
if ( V_47 ) {
F_358 ( & V_811 -> V_812 ) ;
return V_47 ;
}
return 0 ;
}
static void F_371 ( struct V_810 * V_811 )
{
F_358 ( & V_811 -> V_812 ) ;
}
static int F_372 ( struct V_810 * V_811 , int V_815 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_811 -> V_812 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_811 -> V_812 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_813 ,
V_816 , & V_252 ) ;
}
static int F_373 ( struct V_810 * V_811 , int V_509 )
{
int V_238 ;
int V_555 ;
switch ( V_509 ) {
case V_794 :
case V_817 :
return F_99 ( V_8 , V_796 ) ;
case V_797 :
case V_818 :
V_238 = V_819 | V_816 ;
break;
case V_800 :
V_238 = V_820 ;
break;
case V_821 :
case V_822 :
V_238 = V_823 ;
break;
case V_802 :
V_238 = V_824 ;
break;
default:
return 0 ;
}
V_555 = F_361 ( & V_811 -> V_812 , V_238 ) ;
return V_555 ;
}
static int F_374 ( struct V_810 * V_811 ,
char T_12 * V_825 , int V_815 )
{
T_2 V_238 ;
if ( V_815 & V_826 )
V_238 = V_827 ;
else
V_238 = V_827 | V_828 ;
return F_361 ( & V_811 -> V_812 , V_238 ) ;
}
static int F_375 ( struct V_829 * V_830 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_357 ( V_8 , & V_830 -> V_831 , V_832 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_830 -> V_831 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_830 -> V_831 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_832 ,
V_833 , & V_252 ) ;
if ( V_47 ) {
F_358 ( & V_830 -> V_831 ) ;
return V_47 ;
}
return 0 ;
}
static void F_376 ( struct V_829 * V_830 )
{
F_358 ( & V_830 -> V_831 ) ;
}
static int F_377 ( struct V_829 * V_830 , int V_834 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_830 -> V_831 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_257 . V_785 = V_830 -> V_831 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_832 ,
V_835 , & V_252 ) ;
}
static int F_378 ( struct V_829 * V_830 , int V_509 )
{
int V_555 ;
T_2 V_238 ;
switch ( V_509 ) {
case V_794 :
case V_836 :
return F_99 ( V_8 , V_796 ) ;
case V_837 :
case V_838 :
case V_839 :
V_238 = V_840 ;
break;
case V_841 :
case V_842 :
V_238 = V_843 ;
break;
case V_844 :
case V_845 :
V_238 = V_846 ;
break;
case V_802 :
V_238 = V_847 ;
break;
case V_800 :
V_238 = V_848 ;
break;
case V_797 :
case V_849 :
V_238 = V_840 | V_835 ;
break;
default:
return 0 ;
}
V_555 = F_361 ( & V_830 -> V_831 , V_238 ) ;
return V_555 ;
}
static int F_379 ( struct V_829 * V_830 ,
struct V_850 * V_851 , unsigned V_852 , int V_853 )
{
T_2 V_238 ;
if ( V_853 )
V_238 = V_843 | V_846 ;
else
V_238 = V_843 ;
return F_361 ( & V_830 -> V_831 , V_238 ) ;
}
static int F_380 ( struct V_778 * V_854 , short V_98 )
{
T_2 V_255 = 0 ;
V_255 = 0 ;
if ( V_98 & V_855 )
V_255 |= V_856 ;
if ( V_98 & V_857 )
V_255 |= V_858 ;
if ( V_255 == 0 )
return 0 ;
return F_361 ( V_854 , V_255 ) ;
}
static void F_381 ( struct V_778 * V_854 , T_2 * V_506 )
{
struct V_779 * V_21 = V_854 -> V_16 ;
* V_506 = V_21 -> V_14 ;
}
static void F_382 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_383 ( struct V_17 * V_127 ,
char * V_64 , char * * V_469 )
{
const struct V_10 * V_748 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_127 ) {
error = F_92 ( V_127 , V_859 ) ;
if ( error )
return error ;
}
F_11 () ;
V_748 = F_12 ( V_127 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_44 ) )
V_14 = V_748 -> V_14 ;
else if ( ! strcmp ( V_64 , L_45 ) )
V_14 = V_748 -> V_13 ;
else if ( ! strcmp ( V_64 , L_46 ) )
V_14 = V_748 -> V_375 ;
else if ( ! strcmp ( V_64 , L_47 ) )
V_14 = V_748 -> V_273 ;
else if ( ! strcmp ( V_64 , L_48 ) )
V_14 = V_748 -> V_373 ;
else if ( ! strcmp ( V_64 , L_49 ) )
V_14 = V_748 -> V_374 ;
else
goto V_860;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_469 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_860:
F_13 () ;
return - V_86 ;
}
static int F_384 ( struct V_17 * V_127 ,
char * V_64 , void * V_469 , T_7 V_498 )
{
struct V_10 * V_11 ;
struct V_17 * V_387 ;
struct V_7 * V_330 ;
T_2 V_14 = 0 , V_389 ;
int error ;
char * V_1 = V_469 ;
if ( V_8 != V_127 ) {
return - V_502 ;
}
if ( ! strcmp ( V_64 , L_46 ) )
error = F_92 ( V_127 , V_861 ) ;
else if ( ! strcmp ( V_64 , L_47 ) )
error = F_92 ( V_127 , V_862 ) ;
else if ( ! strcmp ( V_64 , L_48 ) )
error = F_92 ( V_127 , V_863 ) ;
else if ( ! strcmp ( V_64 , L_49 ) )
error = F_92 ( V_127 , V_864 ) ;
else if ( ! strcmp ( V_64 , L_44 ) )
error = F_92 ( V_127 , V_865 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_498 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_498 - 1 ] == '\n' ) {
V_1 [ V_498 - 1 ] = 0 ;
V_498 -- ;
}
error = F_54 ( V_469 , V_498 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_47 ) ) {
if ( ! F_202 ( V_500 ) )
return error ;
error = F_205 ( V_469 , V_498 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_330 = F_385 () ;
if ( ! V_330 )
return - V_24 ;
V_11 = V_330 -> V_16 ;
if ( ! strcmp ( V_64 , L_46 ) ) {
V_11 -> V_375 = V_14 ;
} else if ( ! strcmp ( V_64 , L_47 ) ) {
V_11 -> V_273 = V_14 ;
} else if ( ! strcmp ( V_64 , L_48 ) ) {
error = F_109 ( V_14 , V_127 ) ;
if ( error )
goto V_866;
V_11 -> V_373 = V_14 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
V_11 -> V_374 = V_14 ;
} else if ( ! strcmp ( V_64 , L_44 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_866;
error = - V_384 ;
if ( ! F_386 () ) {
error = F_387 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_866;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_241 ,
V_867 , NULL ) ;
if ( error )
goto V_866;
V_389 = 0 ;
F_154 ( V_127 ) ;
V_387 = F_134 ( V_127 ) ;
if ( V_387 )
V_389 = F_10 ( V_387 ) ;
F_156 ( V_127 ) ;
if ( V_387 ) {
error = F_35 ( V_389 , V_14 , V_241 ,
V_324 , NULL ) ;
if ( error )
goto V_866;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_866;
}
F_388 ( V_330 ) ;
return V_498 ;
V_866:
F_389 ( V_330 ) ;
return error ;
}
static int F_390 ( T_2 V_506 , char * * V_453 , T_2 * V_868 )
{
return F_47 ( V_506 , V_453 , V_868 ) ;
}
static int F_391 ( const char * V_453 , T_2 V_868 , T_2 * V_506 )
{
return F_54 ( V_453 , V_868 , V_506 ) ;
}
static void F_392 ( char * V_453 , T_2 V_868 )
{
F_28 ( V_453 ) ;
}
static int F_393 ( struct V_19 * V_19 , void * V_279 , T_2 V_869 )
{
return F_212 ( V_19 , V_472 , V_279 , V_869 , 0 ) ;
}
static int F_394 ( struct V_52 * V_52 , void * V_279 , T_2 V_869 )
{
return F_395 ( V_52 , V_67 , V_279 , V_869 , 0 ) ;
}
static int F_396 ( struct V_19 * V_19 , void * * V_279 , T_2 * V_869 )
{
int V_84 = 0 ;
V_84 = F_211 ( V_19 , V_472 ,
V_279 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_869 = V_84 ;
return 0 ;
}
static int F_397 ( struct V_786 * V_870 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_871 * V_872 ;
V_872 = F_7 ( sizeof( struct V_871 ) , V_12 ) ;
if ( ! V_872 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_373 )
V_872 -> V_14 = V_11 -> V_373 ;
else
V_872 -> V_14 = V_11 -> V_14 ;
V_870 -> V_16 = V_872 ;
return 0 ;
}
static void F_398 ( struct V_786 * V_870 )
{
struct V_871 * V_872 = V_870 -> V_16 ;
V_870 -> V_16 = NULL ;
F_28 ( V_872 ) ;
}
static int F_399 ( T_13 V_873 ,
const struct V_7 * V_7 ,
T_14 V_228 )
{
struct V_786 * V_786 ;
struct V_871 * V_872 ;
T_2 V_14 ;
if ( V_228 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_786 = F_400 ( V_873 ) ;
V_872 = V_786 -> V_16 ;
return F_35 ( V_14 , V_872 -> V_14 , V_280 , V_228 , NULL ) ;
}
static int F_401 ( struct V_786 * V_786 , char * * V_874 )
{
struct V_871 * V_872 = V_786 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_872 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_874 = V_83 ;
return V_47 ;
}
static T_1 int F_402 ( void )
{
if ( ! F_403 ( & V_875 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_876 L_50 ) ;
return 0 ;
}
F_38 ( V_876 L_51 ) ;
F_6 () ;
V_525 = ! ( V_877 & V_541 ) ;
V_22 = F_404 ( L_52 ,
sizeof( struct V_20 ) ,
0 , V_878 , NULL ) ;
F_405 () ;
if ( F_406 ( & V_875 ) )
F_8 ( L_53 ) ;
if ( V_3 )
F_38 ( V_74 L_54 ) ;
else
F_38 ( V_74 L_55 ) ;
return 0 ;
}
static void F_407 ( struct V_41 * V_42 , void * V_879 )
{
F_62 ( V_42 , NULL ) ;
}
void F_408 ( void )
{
F_38 ( V_74 L_56 ) ;
F_38 ( V_74 L_57 ) ;
F_409 ( F_407 , NULL ) ;
}
static int T_1 F_410 ( void )
{
int V_555 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_58 ) ;
V_555 = F_411 ( V_880 , F_39 ( V_880 ) ) ;
if ( V_555 )
F_8 ( L_59 , V_555 ) ;
#if F_266 ( V_640 ) || F_266 ( V_641 )
V_555 = F_411 ( V_881 , F_39 ( V_881 ) ) ;
if ( V_555 )
F_8 ( L_60 , V_555 ) ;
#endif
V_66:
return V_555 ;
}
static void F_412 ( void )
{
F_38 ( V_74 L_61 ) ;
F_413 ( V_880 , F_39 ( V_880 ) ) ;
#if F_266 ( V_640 ) || F_266 ( V_641 )
F_413 ( V_881 , F_39 ( V_881 ) ) ;
#endif
}
int F_414 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_882 ) {
return - V_86 ;
}
F_38 ( V_876 L_62 ) ;
V_882 = 1 ;
V_5 = 0 ;
F_415 () ;
F_416 () ;
F_412 () ;
F_417 () ;
return 0 ;
}
