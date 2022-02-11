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
static int F_93 ( const struct V_7 * V_7 ,
int V_249 , int V_250 )
{
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_255 V_256 ;
T_4 V_28 ;
T_2 V_14 = F_9 ( V_7 ) ;
T_2 V_257 = F_94 ( V_249 ) ;
int V_47 ;
F_95 ( & V_252 , V_258 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_248 = V_8 ;
V_252 . V_259 . V_249 = V_249 ;
switch ( F_96 ( V_249 ) ) {
case 0 :
V_28 = V_260 ;
break;
case 1 :
V_28 = V_261 ;
break;
default:
F_38 ( V_73
L_29 , V_249 ) ;
F_66 () ;
return - V_86 ;
}
V_47 = F_97 ( V_14 , V_14 , V_28 , V_257 , 0 , & V_256 ) ;
if ( V_250 == V_262 ) {
int V_263 = F_98 ( V_14 , V_14 , V_28 , V_257 , & V_256 , V_47 , & V_252 , 0 ) ;
if ( V_263 )
return V_263 ;
}
return V_47 ;
}
static int F_99 ( struct V_17 * V_248 ,
T_2 V_238 )
{
T_2 V_14 = F_10 ( V_248 ) ;
return F_35 ( V_14 , V_15 ,
V_264 , V_238 , NULL ) ;
}
static int F_100 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_238 ,
struct V_251 * V_265 ,
unsigned V_69 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_103 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , V_265 , V_69 ) ;
}
static int F_104 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_238 ,
unsigned V_69 )
{
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
F_95 ( & V_252 , V_266 ) ;
V_252 . V_259 . V_19 = V_19 ;
V_252 . V_253 = & V_254 ;
return F_100 ( V_7 , V_19 , V_238 , & V_252 , V_69 ) ;
}
static inline int F_105 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_257 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_259 . V_52 = V_52 ;
V_252 . V_253 = & V_254 ;
return F_100 ( V_7 , V_19 , V_257 , & V_252 , 0 ) ;
}
static inline int F_106 ( const struct V_7 * V_7 ,
struct V_215 * V_215 ,
T_2 V_257 )
{
struct V_19 * V_19 = V_215 -> V_52 -> V_56 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
F_95 ( & V_252 , V_268 ) ;
V_252 . V_259 . V_215 = * V_215 ;
V_252 . V_253 = & V_254 ;
return F_100 ( V_7 , V_19 , V_257 , & V_252 , 0 ) ;
}
static int F_107 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_257 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = V_36 -> V_269 . V_52 -> V_56 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_9 ( V_7 ) ;
int V_47 ;
F_95 ( & V_252 , V_268 ) ;
V_252 . V_259 . V_215 = V_36 -> V_269 ;
V_252 . V_253 = & V_254 ;
if ( V_14 != V_38 -> V_14 ) {
V_47 = F_35 ( V_14 , V_38 -> V_14 ,
V_270 ,
V_271 ,
& V_252 ) ;
if ( V_47 )
goto V_66;
}
V_47 = 0 ;
if ( V_257 )
V_47 = F_100 ( V_7 , V_19 , V_257 , & V_252 , 0 ) ;
V_66:
return V_47 ;
}
static int F_108 ( struct V_19 * V_272 ,
struct V_52 * V_52 ,
T_4 V_213 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_273 ;
struct V_31 * V_32 ;
T_2 V_14 , V_274 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
int V_47 ;
V_273 = V_272 -> V_30 ;
V_32 = V_272 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_274 = V_11 -> V_275 ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_259 . V_52 = V_52 ;
V_252 . V_253 = & V_254 ;
V_47 = F_35 ( V_14 , V_273 -> V_14 , V_161 ,
V_276 | V_277 ,
& V_252 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_274 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_273 -> V_14 , V_213 ,
& V_52 -> V_278 , & V_274 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_35 ( V_14 , V_274 , V_213 , V_279 , & V_252 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_274 , V_32 -> V_14 ,
V_48 ,
V_51 , & V_252 ) ;
}
static int F_109 ( T_2 V_280 ,
struct V_17 * V_281 )
{
T_2 V_14 = F_10 ( V_281 ) ;
return F_35 ( V_14 , V_280 , V_282 , V_283 , NULL ) ;
}
static int F_110 ( struct V_19 * V_272 ,
struct V_52 * V_52 ,
int V_284 )
{
struct V_20 * V_273 , * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
T_2 V_257 ;
int V_47 ;
V_273 = V_272 -> V_30 ;
V_21 = V_52 -> V_56 -> V_30 ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_259 . V_52 = V_52 ;
V_252 . V_253 = & V_254 ;
V_257 = V_277 ;
V_257 |= ( V_284 ? V_285 : V_276 ) ;
V_47 = F_35 ( V_14 , V_273 -> V_14 , V_161 , V_257 , & V_252 ) ;
if ( V_47 )
return V_47 ;
switch ( V_284 ) {
case V_286 :
V_257 = V_287 ;
break;
case V_288 :
V_257 = V_289 ;
break;
case V_290 :
V_257 = V_291 ;
break;
default:
F_38 ( V_61 L_30 ,
V_113 , V_284 ) ;
return 0 ;
}
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_257 , & V_252 ) ;
return V_47 ;
}
static inline int F_111 ( struct V_19 * V_292 ,
struct V_52 * V_293 ,
struct V_19 * V_294 ,
struct V_52 * V_295 )
{
struct V_20 * V_296 , * V_297 , * V_298 , * V_299 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
T_2 V_257 ;
int V_300 , V_301 ;
int V_47 ;
V_296 = V_292 -> V_30 ;
V_298 = V_293 -> V_56 -> V_30 ;
V_300 = F_112 ( V_293 -> V_56 -> V_226 ) ;
V_297 = V_294 -> V_30 ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_52 = V_293 ;
V_47 = F_35 ( V_14 , V_296 -> V_14 , V_161 ,
V_285 | V_277 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_298 -> V_14 ,
V_298 -> V_28 , V_302 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_300 && V_294 != V_292 ) {
V_47 = F_35 ( V_14 , V_298 -> V_14 ,
V_298 -> V_28 , V_303 , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . V_259 . V_52 = V_295 ;
V_257 = V_276 | V_277 ;
if ( V_295 -> V_56 )
V_257 |= V_285 ;
V_47 = F_35 ( V_14 , V_297 -> V_14 , V_161 , V_257 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_295 -> V_56 ) {
V_299 = V_295 -> V_56 -> V_30 ;
V_301 = F_112 ( V_295 -> V_56 -> V_226 ) ;
V_47 = F_35 ( V_14 , V_299 -> V_14 ,
V_299 -> V_28 ,
( V_301 ? V_291 : V_289 ) , & V_252 ) ;
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
static inline T_2 F_114 ( int V_151 , int V_304 )
{
T_2 V_257 = 0 ;
if ( ! F_112 ( V_151 ) ) {
if ( V_304 & V_305 )
V_257 |= V_306 ;
if ( V_304 & V_307 )
V_257 |= V_308 ;
if ( V_304 & V_309 )
V_257 |= V_310 ;
else if ( V_304 & V_311 )
V_257 |= V_312 ;
} else {
if ( V_304 & V_305 )
V_257 |= V_277 ;
if ( V_304 & V_311 )
V_257 |= V_313 ;
if ( V_304 & V_307 )
V_257 |= V_314 ;
}
return V_257 ;
}
static inline T_2 F_115 ( struct V_36 * V_36 )
{
T_2 V_257 = 0 ;
if ( V_36 -> V_315 & V_316 )
V_257 |= V_308 ;
if ( V_36 -> V_315 & V_317 ) {
if ( V_36 -> V_318 & V_319 )
V_257 |= V_310 ;
else
V_257 |= V_312 ;
}
if ( ! V_257 ) {
V_257 = V_320 ;
}
return V_257 ;
}
static inline T_2 F_116 ( struct V_36 * V_36 )
{
T_2 V_257 = F_115 ( V_36 ) ;
if ( V_321 )
V_257 |= V_322 ;
return V_257 ;
}
static int F_117 ( struct V_17 * V_323 ,
unsigned int V_151 )
{
int V_47 ;
V_47 = F_118 ( V_323 , V_151 ) ;
if ( V_47 )
return V_47 ;
if ( V_151 & V_324 ) {
T_2 V_14 = F_14 () ;
T_2 V_325 = F_10 ( V_323 ) ;
return F_35 ( V_14 , V_325 , V_29 , V_308 , NULL ) ;
}
return F_92 ( V_323 , V_326 ) ;
}
static int F_119 ( struct V_17 * V_327 )
{
int V_47 ;
V_47 = F_120 ( V_327 ) ;
if ( V_47 )
return V_47 ;
return F_91 ( V_327 , V_8 , V_326 ) ;
}
static int F_121 ( struct V_17 * V_237 , T_6 * V_328 ,
T_6 * V_329 , T_6 * V_330 )
{
int error ;
error = F_92 ( V_237 , V_331 ) ;
if ( error )
return error ;
return F_122 ( V_237 , V_328 , V_329 , V_330 ) ;
}
static int F_123 ( struct V_7 * V_332 , const struct V_7 * V_333 ,
const T_6 * V_328 ,
const T_6 * V_329 ,
const T_6 * V_330 )
{
int error ;
error = F_124 ( V_332 , V_333 ,
V_328 , V_329 , V_330 ) ;
if ( error )
return error ;
return F_90 ( V_333 , V_332 , V_334 ) ;
}
static int F_125 ( const struct V_7 * V_7 , struct V_335 * V_336 ,
int V_249 , int V_250 )
{
int V_47 ;
V_47 = F_126 ( V_7 , V_336 , V_249 , V_250 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_7 , V_249 , V_250 ) ;
}
static int F_127 ( int V_337 , int type , int V_338 , struct V_41 * V_42 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( ! V_42 )
return 0 ;
switch ( V_337 ) {
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
V_47 = F_113 ( V_7 , V_42 , V_344 , NULL ) ;
break;
case V_345 :
case V_346 :
case V_347 :
V_47 = F_113 ( V_7 , V_42 , V_348 , NULL ) ;
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
return F_105 ( V_7 , V_52 , V_349 ) ;
}
static int F_129 ( int type )
{
int V_47 ;
switch ( type ) {
case V_350 :
case V_351 :
V_47 = F_99 ( V_8 , V_352 ) ;
break;
case V_353 :
case V_354 :
case V_355 :
V_47 = F_99 ( V_8 , V_356 ) ;
break;
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
default:
V_47 = F_99 ( V_8 , V_362 ) ;
break;
}
return V_47 ;
}
static int F_130 ( struct V_363 * V_364 , long V_365 )
{
int V_47 , V_366 = 0 ;
V_47 = F_125 ( F_52 () , & V_367 , V_368 ,
V_369 ) ;
if ( V_47 == 0 )
V_366 = 1 ;
return F_131 ( V_364 , V_365 , V_366 ) ;
}
static int F_132 ( struct V_370 * V_371 )
{
const struct V_10 * V_372 ;
struct V_10 * V_373 ;
struct V_20 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_19 * V_19 = V_371 -> V_36 -> V_269 . V_52 -> V_56 ;
int V_47 ;
V_47 = F_133 ( V_371 ) ;
if ( V_47 )
return V_47 ;
if ( V_371 -> V_374 )
return 0 ;
V_372 = F_15 () ;
V_373 = V_371 -> V_7 -> V_16 ;
V_21 = V_19 -> V_30 ;
V_373 -> V_14 = V_372 -> V_14 ;
V_373 -> V_13 = V_372 -> V_14 ;
V_373 -> V_275 = 0 ;
V_373 -> V_375 = 0 ;
V_373 -> V_376 = 0 ;
if ( V_372 -> V_377 ) {
V_373 -> V_14 = V_372 -> V_377 ;
V_373 -> V_377 = 0 ;
} else {
V_47 = F_87 ( V_372 -> V_14 , V_21 -> V_14 ,
V_241 , NULL ,
& V_373 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
F_95 ( & V_252 , V_268 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_215 = V_371 -> V_36 -> V_269 ;
if ( V_371 -> V_36 -> V_269 . V_378 -> V_101 & V_379 )
V_373 -> V_14 = V_372 -> V_14 ;
if ( V_373 -> V_14 == V_372 -> V_14 ) {
V_47 = F_35 ( V_372 -> V_14 , V_21 -> V_14 ,
V_29 , V_380 , & V_252 ) ;
if ( V_47 )
return V_47 ;
} else {
V_47 = F_35 ( V_372 -> V_14 , V_373 -> V_14 ,
V_241 , V_381 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_373 -> V_14 , V_21 -> V_14 ,
V_29 , V_382 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_371 -> V_383 & V_384 ) {
V_47 = F_35 ( V_372 -> V_14 , V_373 -> V_14 ,
V_241 , V_385 ,
NULL ) ;
if ( V_47 )
return - V_386 ;
}
if ( V_371 -> V_383 &
( V_387 | V_388 ) ) {
struct V_17 * V_389 ;
struct V_10 * V_390 ;
T_2 V_391 = 0 ;
F_11 () ;
V_389 = F_134 ( V_8 ) ;
if ( F_135 ( V_389 != NULL ) ) {
V_390 = F_12 ( V_389 ) -> V_16 ;
V_391 = V_390 -> V_14 ;
}
F_13 () ;
if ( V_391 != 0 ) {
V_47 = F_35 ( V_391 , V_373 -> V_14 ,
V_241 ,
V_326 , NULL ) ;
if ( V_47 )
return - V_386 ;
}
}
V_371 -> V_392 |= V_393 ;
}
return 0 ;
}
static int F_136 ( struct V_370 * V_371 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_14 , V_13 ;
int V_394 = 0 ;
V_14 = V_11 -> V_14 ;
V_13 = V_11 -> V_13 ;
if ( V_13 != V_14 ) {
V_394 = F_35 ( V_13 , V_14 ,
V_241 ,
V_395 , NULL ) ;
}
return ( V_394 || F_137 ( V_371 ) ) ;
}
static inline void F_138 ( const struct V_7 * V_7 ,
struct V_396 * V_397 )
{
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_36 * V_36 , * V_398 = NULL ;
struct V_399 * V_400 ;
struct V_401 * V_402 ;
long V_403 = - 1 ;
int V_404 = 0 ;
V_400 = F_139 () ;
if ( V_400 ) {
F_21 ( & V_405 ) ;
if ( ! F_22 ( & V_400 -> V_406 ) ) {
struct V_407 * V_408 ;
struct V_19 * V_19 ;
V_408 = F_140 ( & V_400 -> V_406 ,
struct V_407 , V_26 ) ;
V_36 = V_408 -> V_36 ;
V_19 = V_36 -> V_269 . V_52 -> V_56 ;
if ( F_104 ( V_7 , V_19 ,
V_308 | V_312 , 0 ) ) {
V_404 = 1 ;
}
}
F_24 ( & V_405 ) ;
F_141 ( V_400 ) ;
}
if ( V_404 )
F_142 () ;
F_95 ( & V_252 , V_266 ) ;
V_252 . V_253 = & V_254 ;
F_21 ( & V_397 -> V_409 ) ;
for (; ; ) {
unsigned long V_410 , V_82 ;
int V_411 ;
V_403 ++ ;
V_82 = V_403 * V_412 ;
V_402 = F_143 ( V_397 ) ;
if ( V_82 >= V_402 -> V_413 )
break;
V_410 = V_402 -> V_414 [ V_403 ] ;
if ( ! V_410 )
continue;
F_24 ( & V_397 -> V_409 ) ;
for ( ; V_410 ; V_82 ++ , V_410 >>= 1 ) {
if ( V_410 & 1 ) {
V_36 = F_144 ( V_82 ) ;
if ( ! V_36 )
continue;
if ( F_107 ( V_7 ,
V_36 ,
F_115 ( V_36 ) ) ) {
F_145 ( V_82 ) ;
V_411 = F_146 () ;
if ( V_411 != V_82 ) {
if ( V_411 >= 0 )
F_147 ( V_411 ) ;
F_148 ( V_36 ) ;
continue;
}
if ( V_398 ) {
F_149 ( V_398 ) ;
} else {
V_398 = F_150 (
F_81 ( V_415 ) ,
F_151 ( V_416 ) ,
V_417 , V_7 ) ;
if ( F_75 ( V_398 ) ) {
V_398 = NULL ;
F_147 ( V_411 ) ;
F_148 ( V_36 ) ;
continue;
}
}
F_152 ( V_411 , V_398 ) ;
}
F_148 ( V_36 ) ;
}
}
F_21 ( & V_397 -> V_409 ) ;
}
F_24 ( & V_397 -> V_409 ) ;
}
static void F_153 ( struct V_370 * V_371 )
{
struct V_10 * V_373 ;
struct V_418 * V_419 , * V_420 ;
int V_47 , V_82 ;
V_373 = V_371 -> V_7 -> V_16 ;
if ( V_373 -> V_14 == V_373 -> V_13 )
return;
F_138 ( V_371 -> V_7 , V_8 -> V_397 ) ;
V_8 -> V_421 = 0 ;
V_47 = F_35 ( V_373 -> V_13 , V_373 -> V_14 , V_241 ,
V_422 , NULL ) ;
if ( V_47 ) {
F_154 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_423 ; V_82 ++ ) {
V_419 = V_8 -> signal -> V_419 + V_82 ;
V_420 = V_424 . signal -> V_419 + V_82 ;
V_419 -> V_425 = F_155 ( V_419 -> V_426 , V_420 -> V_425 ) ;
}
F_156 ( V_8 ) ;
F_157 ( V_8 , V_418 ( V_427 ) ) ;
}
}
static void F_158 ( struct V_370 * V_371 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_428 V_429 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_241 , V_430 , NULL ) ;
if ( V_47 ) {
memset ( & V_429 , 0 , sizeof V_429 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_159 ( V_82 , & V_429 , NULL ) ;
F_160 ( & V_8 -> V_431 -> V_432 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_433 ) ) {
F_161 ( V_8 ) ;
F_162 ( V_8 , 1 ) ;
F_163 ( & V_8 -> V_434 ) ;
}
F_164 ( & V_8 -> V_431 -> V_432 ) ;
}
F_165 ( & V_435 ) ;
F_166 ( V_8 , V_8 -> V_436 ) ;
F_167 ( & V_435 ) ;
}
static int F_168 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_169 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_170 ( char * V_144 , int V_437 , char * V_438 , int V_439 )
{
if ( V_437 > V_439 )
return 0 ;
return ! memcmp ( V_144 , V_438 , V_437 ) ;
}
static inline int F_171 ( char * V_438 , int V_84 )
{
return ( F_170 ( V_146 , sizeof( V_146 ) - 1 , V_438 , V_84 ) ||
F_170 ( V_147 , sizeof( V_147 ) - 1 , V_438 , V_84 ) ||
F_170 ( V_149 , sizeof( V_149 ) - 1 , V_438 , V_84 ) ||
F_170 ( V_148 , sizeof( V_148 ) - 1 , V_438 , V_84 ) ||
F_170 ( V_150 , sizeof( V_150 ) - 1 , V_438 , V_84 ) ) ;
}
static inline void F_172 ( char * * V_440 , char * V_441 , int * V_442 , int V_84 )
{
if ( ! * V_442 ) {
* * V_440 = ',' ;
* V_440 += 1 ;
} else
* V_442 = 0 ;
memcpy ( * V_440 , V_441 , V_84 ) ;
* V_440 += V_84 ;
}
static inline void F_173 ( char * * V_440 , char * V_441 , int * V_442 ,
int V_84 )
{
int V_443 = 0 ;
if ( ! * V_442 ) {
* * V_440 = '|' ;
* V_440 += 1 ;
} else
* V_442 = 0 ;
while ( V_443 < V_84 ) {
if ( * V_441 != '"' ) {
* * V_440 = * V_441 ;
* V_440 += 1 ;
}
V_441 += 1 ;
V_443 += 1 ;
}
}
static int F_174 ( char * V_444 , char * V_445 )
{
int V_446 , V_38 , V_47 = 0 ;
char * V_447 , * V_448 , * V_449 ;
char * V_450 , * V_451 , * V_452 ;
int V_453 = 0 ;
V_448 = V_444 ;
V_450 = V_445 ;
V_452 = ( char * ) F_175 ( V_12 ) ;
if ( ! V_452 ) {
V_47 = - V_24 ;
goto V_66;
}
V_451 = V_452 ;
V_446 = V_38 = 1 ;
V_447 = V_449 = V_444 ;
do {
if ( * V_449 == '"' )
V_453 = ! V_453 ;
if ( ( * V_449 == ',' && V_453 == 0 ) ||
* V_449 == '\0' ) {
int V_84 = V_449 - V_448 ;
if ( F_171 ( V_448 , V_84 ) )
F_173 ( & V_450 , V_448 , & V_38 , V_84 ) ;
else
F_172 ( & V_452 , V_448 , & V_446 , V_84 ) ;
V_448 = V_449 + 1 ;
}
} while ( * V_449 ++ );
strcpy ( V_447 , V_451 ) ;
F_78 ( ( unsigned long ) V_451 ) ;
V_66:
return V_47 ;
}
static int F_176 ( struct V_41 * V_42 , void * V_141 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_454 , * * V_107 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_141 )
return 0 ;
if ( V_42 -> V_63 -> V_109 & V_110 )
return 0 ;
F_45 ( & V_81 ) ;
V_454 = F_177 () ;
if ( ! V_454 )
return - V_24 ;
V_47 = F_174 ( V_141 , V_454 ) ;
if ( V_47 )
goto V_455;
V_47 = F_58 ( V_454 , & V_81 ) ;
if ( V_47 )
goto V_455;
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
goto V_456;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_457;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_457;
break;
case V_97 : {
struct V_20 * V_102 ;
V_102 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 , V_14 ) )
goto V_457;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_457;
break;
default:
goto V_456;
}
}
V_47 = 0 ;
V_456:
F_49 ( & V_81 ) ;
V_455:
F_178 ( V_454 ) ;
return V_47 ;
V_457:
F_38 ( V_61 L_31
L_32 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_456;
}
static int F_179 ( struct V_41 * V_42 , int V_69 , void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
int V_47 ;
V_47 = F_62 ( V_42 , V_141 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_458 )
return 0 ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_52 = V_42 -> V_54 ;
return F_113 ( V_7 , V_42 , V_459 , & V_252 ) ;
}
static int F_180 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_52 = V_52 -> V_460 -> V_54 ;
return F_113 ( V_7 , V_52 -> V_460 , V_461 , & V_252 ) ;
}
static int F_181 ( char * V_462 ,
struct V_215 * V_215 ,
char * type ,
unsigned long V_69 ,
void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_463 )
return F_113 ( V_7 , V_215 -> V_52 -> V_460 ,
V_464 , NULL ) ;
else
return F_106 ( V_7 , V_215 , V_465 ) ;
}
static int F_182 ( struct V_466 * V_378 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_113 ( V_7 , V_378 -> V_467 ,
V_468 , NULL ) ;
}
static int F_183 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_184 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_185 ( struct V_19 * V_19 , struct V_19 * V_272 ,
const struct V_469 * V_469 , char * * V_64 ,
void * * V_470 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_273 ;
struct V_31 * V_32 ;
T_2 V_14 , V_274 , V_471 ;
int V_47 ;
char * V_472 = NULL , * V_83 ;
V_273 = V_272 -> V_30 ;
V_32 = V_272 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_274 = V_11 -> V_275 ;
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_57 == V_76 ) )
V_274 = V_32 -> V_46 ;
else if ( ! V_274 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_273 -> V_14 ,
F_68 ( V_19 -> V_226 ) ,
V_469 , & V_274 ) ;
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
V_21 -> V_14 = V_274 ;
V_21 -> V_114 = 1 ;
}
if ( ! V_87 || ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( V_64 ) {
V_472 = F_186 ( V_473 , V_23 ) ;
if ( ! V_472 )
return - V_24 ;
* V_64 = V_472 ;
}
if ( V_470 && V_84 ) {
V_47 = F_187 ( V_274 , & V_83 , & V_471 ) ;
if ( V_47 ) {
F_28 ( V_472 ) ;
return V_47 ;
}
* V_470 = V_83 ;
* V_84 = V_471 ;
}
return 0 ;
}
static int F_188 ( struct V_19 * V_272 , struct V_52 * V_52 , T_5 V_151 )
{
return F_108 ( V_272 , V_52 , V_29 ) ;
}
static int F_189 ( struct V_52 * V_293 , struct V_19 * V_272 , struct V_52 * V_295 )
{
return F_110 ( V_272 , V_293 , V_286 ) ;
}
static int F_190 ( struct V_19 * V_272 , struct V_52 * V_52 )
{
return F_110 ( V_272 , V_52 , V_288 ) ;
}
static int F_191 ( struct V_19 * V_272 , struct V_52 * V_52 , const char * V_64 )
{
return F_108 ( V_272 , V_52 , V_156 ) ;
}
static int F_192 ( struct V_19 * V_272 , struct V_52 * V_52 , T_5 V_304 )
{
return F_108 ( V_272 , V_52 , V_161 ) ;
}
static int F_193 ( struct V_19 * V_272 , struct V_52 * V_52 )
{
return F_110 ( V_272 , V_52 , V_290 ) ;
}
static int F_194 ( struct V_19 * V_272 , struct V_52 * V_52 , T_5 V_151 , T_8 V_221 )
{
return F_108 ( V_272 , V_52 , F_68 ( V_151 ) ) ;
}
static int F_195 ( struct V_19 * V_474 , struct V_52 * V_293 ,
struct V_19 * V_475 , struct V_52 * V_295 )
{
return F_111 ( V_474 , V_293 , V_475 , V_295 ) ;
}
static int F_196 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_308 ) ;
}
static int F_197 ( struct V_52 * V_52 , struct V_476 * V_476 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_52 , V_308 ) ;
}
static int F_198 ( struct V_19 * V_19 , int V_304 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_238 ;
bool V_477 ;
unsigned V_69 = V_304 & V_478 ;
V_477 = V_304 & V_479 ;
V_304 &= ( V_307 | V_311 | V_305 | V_309 ) ;
if ( ! V_304 )
return 0 ;
F_95 ( & V_252 , V_266 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_19 = V_19 ;
if ( V_477 )
V_252 . V_253 -> V_480 |= V_481 ;
V_238 = F_114 ( V_19 -> V_226 , V_304 ) ;
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
return F_105 ( V_7 , V_52 , V_312 ) ;
}
static int F_200 ( struct V_466 * V_378 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_215 V_215 ;
V_215 . V_52 = V_52 ;
V_215 . V_378 = V_378 ;
return F_106 ( V_7 , & V_215 , V_494 ) ;
}
static int F_201 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_495 ,
sizeof V_495 - 1 ) ) {
if ( ! strcmp ( V_64 , V_496 ) ) {
if ( ! F_202 ( V_497 ) )
return - V_386 ;
} else if ( ! F_202 ( V_368 ) ) {
return - V_386 ;
}
}
return F_105 ( V_7 , V_52 , V_493 ) ;
}
static int F_203 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_470 , T_7 V_498 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_274 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_201 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_204 ( V_19 ) )
return - V_386 ;
F_95 ( & V_252 , V_267 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_499 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_470 , V_498 , & V_274 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_202 ( V_500 ) )
return V_47 ;
V_47 = F_205 ( V_470 , V_498 , & V_274 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_274 , V_21 -> V_28 ,
V_501 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_206 ( V_21 -> V_14 , V_274 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_274 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_252 ) ;
}
static void F_207 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_470 , T_7 V_498 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_274 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_205 ( V_470 , V_498 , & V_274 ) ;
if ( V_47 ) {
F_38 ( V_73 L_36
L_37 ,
V_19 -> V_33 -> V_62 , V_19 -> V_220 , - V_47 ) ;
return;
}
V_21 -> V_14 = V_274 ;
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
if ( strcmp ( V_64 , V_473 ) )
return - V_65 ;
error = F_125 ( F_52 () , & V_367 , V_500 ,
V_369 ) ;
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
const void * V_470 , T_7 V_498 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_274 ;
int V_47 ;
if ( strcmp ( V_64 , V_473 ) )
return - V_65 ;
if ( ! V_470 || ! V_498 )
return - V_502 ;
V_47 = F_54 ( ( void * ) V_470 , V_498 , & V_274 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_14 = V_274 ;
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
static int F_215 ( struct V_36 * V_36 , int V_304 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = V_36 -> V_269 . V_52 -> V_56 ;
if ( ( V_36 -> V_318 & V_319 ) && ( V_304 & V_311 ) )
V_304 |= V_309 ;
return F_107 ( V_7 , V_36 ,
F_114 ( V_19 -> V_226 , V_304 ) ) ;
}
static int F_216 ( struct V_36 * V_36 , int V_304 )
{
struct V_19 * V_19 = V_36 -> V_269 . V_52 -> V_56 ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_304 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_507 == V_21 -> V_14 &&
V_38 -> V_508 == F_217 () )
return 0 ;
return F_215 ( V_36 , V_304 ) ;
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
error = F_93 ( V_7 , V_522 ,
V_262 ) ;
break;
default:
error = F_107 ( V_7 , V_36 , V_320 ) ;
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
T_2 V_257 = V_308 ;
if ( V_524 && ( V_523 & V_527 ) )
V_257 |= V_312 ;
if ( V_523 & V_526 )
V_257 |= V_306 ;
return F_107 ( V_7 , V_36 , V_257 ) ;
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
if ( ! V_36 -> V_269 . V_52 || ! V_36 -> V_269 . V_52 -> V_56 ) {
V_555 = - V_86 ;
break;
}
if ( ( V_36 -> V_318 & V_319 ) && ! ( V_510 & V_319 ) ) {
V_555 = F_107 ( V_7 , V_36 , V_312 ) ;
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
if ( ! V_36 -> V_269 . V_52 || ! V_36 -> V_269 . V_52 -> V_56 ) {
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
V_19 = V_36 -> V_269 . V_52 -> V_56 ;
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
static int F_235 ( struct V_7 * V_332 , const struct V_7 * V_333 ,
T_9 V_576 )
{
const struct V_10 * V_372 ;
struct V_10 * V_11 ;
V_372 = V_333 -> V_16 ;
V_11 = F_236 ( V_372 , sizeof( struct V_10 ) , V_576 ) ;
if ( ! V_11 )
return - V_24 ;
V_332 -> V_16 = V_11 ;
return 0 ;
}
static void F_237 ( struct V_7 * V_332 , const struct V_7 * V_333 )
{
const struct V_10 * V_372 = V_333 -> V_16 ;
struct V_10 * V_11 = V_332 -> V_16 ;
* V_11 = * V_372 ;
}
static int F_238 ( struct V_7 * V_332 , T_2 V_506 )
{
struct V_10 * V_11 = V_332 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_577 ;
V_577 = F_35 ( V_14 , V_506 ,
V_578 ,
V_579 ,
NULL ) ;
if ( V_577 == 0 ) {
V_11 -> V_14 = V_506 ;
V_11 -> V_275 = 0 ;
V_11 -> V_375 = 0 ;
V_11 -> V_376 = 0 ;
}
return V_577 ;
}
static int F_239 ( struct V_7 * V_332 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_332 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_577 ;
V_577 = F_35 ( V_14 , V_21 -> V_14 ,
V_578 ,
V_580 ,
NULL ) ;
if ( V_577 == 0 )
V_11 -> V_275 = V_21 -> V_14 ;
return V_577 ;
}
static int F_240 ( char * V_581 )
{
T_2 V_14 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
V_14 = F_10 ( V_8 ) ;
F_95 ( & V_252 , V_582 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_581 = V_581 ;
return F_35 ( V_14 , V_15 , V_264 ,
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
struct V_418 * V_593 )
{
struct V_418 * V_594 = V_127 -> signal -> V_419 + V_592 ;
if ( V_594 -> V_426 != V_593 -> V_426 )
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
V_252 -> V_259 . V_608 -> V_609 . V_610 = V_606 -> V_610 ;
V_252 -> V_259 . V_608 -> V_609 . V_611 = V_606 -> V_611 ;
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
V_252 -> V_259 . V_608 -> V_617 = V_614 -> V_618 ;
V_252 -> V_259 . V_608 -> V_619 = V_614 -> V_620 ;
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
V_252 -> V_259 . V_608 -> V_617 = V_623 -> V_618 ;
V_252 -> V_259 . V_608 -> V_619 = V_623 -> V_620 ;
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
V_252 -> V_259 . V_608 -> V_617 = V_627 -> V_628 ;
V_252 -> V_259 . V_608 -> V_619 = V_627 -> V_629 ;
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
T_12 V_615 ;
V_602 = F_259 ( V_600 ) ;
V_633 = F_260 ( V_600 , V_602 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
goto V_66;
V_252 -> V_259 . V_608 -> V_634 . V_610 = V_633 -> V_610 ;
V_252 -> V_259 . V_608 -> V_634 . V_611 = V_633 -> V_611 ;
V_577 = 0 ;
V_630 = V_633 -> V_630 ;
V_602 += sizeof( V_632 ) ;
V_602 = F_263 ( V_600 , V_602 , & V_630 , & V_615 ) ;
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
V_252 -> V_259 . V_608 -> V_617 = V_614 -> V_618 ;
V_252 -> V_259 . V_608 -> V_619 = V_614 -> V_620 ;
break;
}
case V_169 : {
struct V_621 V_622 , * V_623 ;
V_623 = F_260 ( V_600 , V_602 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
break;
V_252 -> V_259 . V_608 -> V_617 = V_623 -> V_618 ;
V_252 -> V_259 . V_608 -> V_619 = V_623 -> V_620 ;
break;
}
case V_624 : {
struct V_625 V_626 , * V_627 ;
V_627 = F_260 ( V_600 , V_602 , sizeof( V_626 ) , & V_626 ) ;
if ( V_627 == NULL )
break;
V_252 -> V_259 . V_608 -> V_617 = V_627 -> V_628 ;
V_252 -> V_259 . V_608 -> V_619 = V_627 -> V_629 ;
break;
}
default:
break;
}
V_66:
return V_577 ;
}
static int F_264 ( struct V_599 * V_600 , struct V_251 * V_252 ,
char * * V_635 , int V_636 , T_11 * V_601 )
{
char * V_637 ;
int V_577 ;
switch ( V_252 -> V_259 . V_608 -> V_170 ) {
case V_177 :
V_577 = F_258 ( V_600 , V_252 , V_601 ) ;
if ( V_577 )
goto V_638;
V_637 = ( char * ) ( V_636 ? & V_252 -> V_259 . V_608 -> V_609 . V_610 :
& V_252 -> V_259 . V_608 -> V_609 . V_611 ) ;
goto V_639;
#if F_265 ( V_640 ) || F_265 ( V_641 )
case V_178 :
V_577 = F_262 ( V_600 , V_252 , V_601 ) ;
if ( V_577 )
goto V_638;
V_637 = ( char * ) ( V_636 ? & V_252 -> V_259 . V_608 -> V_634 . V_610 :
& V_252 -> V_259 . V_608 -> V_634 . V_611 ) ;
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
static int F_266 ( struct V_599 * V_600 , T_4 V_170 , T_2 * V_14 )
{
int V_555 ;
T_2 V_642 ;
T_2 V_643 ;
T_2 V_644 ;
F_267 ( V_600 , & V_642 ) ;
F_268 ( V_600 , V_170 , & V_644 , & V_643 ) ;
V_555 = F_269 ( V_643 , V_644 , V_642 , V_14 ) ;
if ( F_102 ( V_555 ) ) {
F_38 ( V_61
L_40
L_41 ) ;
return - V_502 ;
}
return 0 ;
}
static int F_270 ( const struct V_10 * V_11 ,
T_4 V_645 , T_2 * V_646 )
{
if ( V_11 -> V_376 > V_647 ) {
* V_646 = V_11 -> V_376 ;
return 0 ;
}
return F_87 ( V_11 -> V_14 , V_11 -> V_14 , V_645 , NULL ,
V_646 ) ;
}
static int F_271 ( struct V_17 * V_18 , struct V_648 * V_649 , T_2 V_238 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
T_2 V_240 = F_10 ( V_18 ) ;
if ( V_651 -> V_14 == V_15 )
return 0 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_649 = V_649 ;
return F_35 ( V_240 , V_651 -> V_14 , V_651 -> V_28 , V_238 , & V_252 ) ;
}
static int F_272 ( int V_170 , int type ,
int V_166 , int V_655 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_274 ;
T_4 V_645 ;
int V_47 ;
if ( V_655 )
return 0 ;
V_645 = F_71 ( V_170 , type , V_166 ) ;
V_47 = F_270 ( V_11 , V_645 , & V_274 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_274 , V_645 , V_656 , NULL ) ;
}
static int F_273 ( struct V_657 * V_648 , int V_170 ,
int type , int V_166 , int V_655 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_274 ( V_648 ) -> V_30 ;
struct V_650 * V_651 ;
int V_555 = 0 ;
V_21 -> V_28 = F_71 ( V_170 , type , V_166 ) ;
if ( V_655 )
V_21 -> V_14 = V_15 ;
else {
V_555 = F_270 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_555 )
return V_555 ;
}
V_21 -> V_114 = 1 ;
if ( V_648 -> V_649 ) {
V_651 = V_648 -> V_649 -> V_652 ;
V_651 -> V_14 = V_21 -> V_14 ;
V_651 -> V_28 = V_21 -> V_28 ;
V_555 = F_275 ( V_648 -> V_649 , V_170 ) ;
}
return V_555 ;
}
static int F_276 ( struct V_657 * V_648 , struct V_658 * V_659 , int V_660 )
{
struct V_648 * V_649 = V_648 -> V_649 ;
T_4 V_170 ;
int V_555 ;
V_555 = F_271 ( V_8 , V_649 , V_661 ) ;
if ( V_555 )
goto V_66;
V_170 = V_649 -> V_662 ;
if ( V_170 == V_177 || V_170 == V_178 ) {
char * V_637 ;
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
struct V_663 * V_664 = NULL ;
struct V_665 * V_666 = NULL ;
unsigned short V_667 ;
T_2 V_14 , V_668 ;
if ( V_170 == V_177 ) {
V_664 = (struct V_663 * ) V_659 ;
V_667 = F_261 ( V_664 -> V_669 ) ;
V_637 = ( char * ) & V_664 -> V_670 . V_671 ;
} else {
V_666 = (struct V_665 * ) V_659 ;
V_667 = F_261 ( V_666 -> V_672 ) ;
V_637 = ( char * ) & V_666 -> V_673 . V_674 ;
}
if ( V_667 ) {
int V_675 , V_676 ;
F_277 ( & V_675 , & V_676 ) ;
if ( V_667 < V_677 ( V_678, V_675 ) || V_667 > V_676 ) {
V_555 = F_278 ( V_649 -> V_679 ,
V_667 , & V_14 ) ;
if ( V_555 )
goto V_66;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_617 = F_279 ( V_667 ) ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
V_555 = F_35 ( V_651 -> V_14 , V_14 ,
V_651 -> V_28 ,
V_680 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
}
switch ( V_651 -> V_28 ) {
case V_179 :
V_668 = V_681 ;
break;
case V_181 :
V_668 = V_682 ;
break;
case V_183 :
V_668 = V_683 ;
break;
default:
V_668 = V_684 ;
break;
}
V_555 = F_280 ( V_637 , V_170 , & V_14 ) ;
if ( V_555 )
goto V_66;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_617 = F_279 ( V_667 ) ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
if ( V_170 == V_177 )
V_252 . V_259 . V_608 -> V_609 . V_610 = V_664 -> V_670 . V_671 ;
else
V_252 . V_259 . V_608 -> V_634 . V_610 = V_666 -> V_673 ;
V_555 = F_35 ( V_651 -> V_14 , V_14 ,
V_651 -> V_28 , V_668 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
V_66:
return V_555 ;
}
static int F_281 ( struct V_657 * V_648 , struct V_658 * V_659 , int V_660 )
{
struct V_648 * V_649 = V_648 -> V_649 ;
struct V_650 * V_651 = V_649 -> V_652 ;
int V_555 ;
V_555 = F_271 ( V_8 , V_649 , V_685 ) ;
if ( V_555 )
return V_555 ;
if ( V_651 -> V_28 == V_179 ||
V_651 -> V_28 == V_183 ) {
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
struct V_663 * V_664 = NULL ;
struct V_665 * V_666 = NULL ;
unsigned short V_667 ;
T_2 V_14 , V_228 ;
if ( V_649 -> V_662 == V_177 ) {
V_664 = (struct V_663 * ) V_659 ;
if ( V_660 < sizeof( struct V_663 ) )
return - V_86 ;
V_667 = F_261 ( V_664 -> V_669 ) ;
} else {
V_666 = (struct V_665 * ) V_659 ;
if ( V_660 < V_686 )
return - V_86 ;
V_667 = F_261 ( V_666 -> V_672 ) ;
}
V_555 = F_278 ( V_649 -> V_679 , V_667 , & V_14 ) ;
if ( V_555 )
goto V_66;
V_228 = ( V_651 -> V_28 == V_179 ) ?
V_687 : V_688 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_619 = F_279 ( V_667 ) ;
V_252 . V_259 . V_608 -> V_170 = V_649 -> V_662 ;
V_555 = F_35 ( V_651 -> V_14 , V_14 , V_651 -> V_28 , V_228 , & V_252 ) ;
if ( V_555 )
goto V_66;
}
V_555 = F_282 ( V_649 , V_659 ) ;
V_66:
return V_555 ;
}
static int F_283 ( struct V_657 * V_648 , int V_689 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_690 ) ;
}
static int F_284 ( struct V_657 * V_648 , struct V_657 * V_691 )
{
int V_555 ;
struct V_20 * V_21 ;
struct V_20 * V_123 ;
V_555 = F_271 ( V_8 , V_648 -> V_649 , V_692 ) ;
if ( V_555 )
return V_555 ;
V_123 = F_274 ( V_691 ) -> V_30 ;
V_21 = F_274 ( V_648 ) -> V_30 ;
V_123 -> V_28 = V_21 -> V_28 ;
V_123 -> V_14 = V_21 -> V_14 ;
V_123 -> V_114 = 1 ;
return 0 ;
}
static int F_285 ( struct V_657 * V_648 , struct V_693 * V_694 ,
int V_498 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_695 ) ;
}
static int F_286 ( struct V_657 * V_648 , struct V_693 * V_694 ,
int V_498 , int V_69 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_696 ) ;
}
static int F_287 ( struct V_657 * V_648 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_697 ) ;
}
static int F_288 ( struct V_657 * V_648 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_697 ) ;
}
static int F_289 ( struct V_657 * V_648 , int V_698 , int V_699 )
{
int V_555 ;
V_555 = F_271 ( V_8 , V_648 -> V_649 , V_700 ) ;
if ( V_555 )
return V_555 ;
return F_290 ( V_648 , V_698 , V_699 ) ;
}
static int F_291 ( struct V_657 * V_648 , int V_698 ,
int V_699 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_701 ) ;
}
static int F_292 ( struct V_657 * V_648 , int V_702 )
{
return F_271 ( V_8 , V_648 -> V_649 , V_703 ) ;
}
static int F_293 ( struct V_648 * V_648 ,
struct V_648 * V_704 ,
struct V_648 * V_705 )
{
struct V_650 * V_706 = V_648 -> V_652 ;
struct V_650 * V_707 = V_704 -> V_652 ;
struct V_650 * V_708 = V_705 -> V_652 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
int V_555 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_649 = V_704 ;
V_555 = F_35 ( V_706 -> V_14 , V_707 -> V_14 ,
V_707 -> V_28 ,
V_709 , & V_252 ) ;
if ( V_555 )
return V_555 ;
V_708 -> V_710 = V_706 -> V_14 ;
V_555 = F_294 ( V_707 -> V_14 , V_706 -> V_14 ,
& V_708 -> V_14 ) ;
if ( V_555 )
return V_555 ;
V_706 -> V_710 = V_708 -> V_14 ;
return 0 ;
}
static int F_295 ( struct V_657 * V_648 ,
struct V_657 * V_704 )
{
struct V_650 * V_711 = V_648 -> V_649 -> V_652 ;
struct V_650 * V_712 = V_704 -> V_649 -> V_652 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_649 = V_704 -> V_649 ;
return F_35 ( V_711 -> V_14 , V_712 -> V_14 , V_712 -> V_28 , V_713 ,
& V_252 ) ;
}
static int F_296 ( int V_714 , char * V_637 , T_4 V_170 ,
T_2 V_710 ,
struct V_251 * V_252 )
{
int V_555 ;
T_2 V_715 ;
T_2 V_716 ;
V_555 = F_297 ( V_714 , & V_715 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_35 ( V_710 , V_715 ,
V_717 , V_718 , V_252 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_280 ( V_637 , V_170 , & V_716 ) ;
if ( V_555 )
return V_555 ;
return F_35 ( V_710 , V_716 ,
V_719 , V_720 , V_252 ) ;
}
static int F_298 ( struct V_648 * V_649 , struct V_599 * V_600 ,
T_4 V_170 )
{
int V_555 = 0 ;
struct V_650 * V_651 = V_649 -> V_652 ;
T_2 V_721 = V_651 -> V_14 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
char * V_637 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_722 = V_600 -> V_723 ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
V_555 = F_264 ( V_600 , & V_252 , & V_637 , 1 , NULL ) ;
if ( V_555 )
return V_555 ;
if ( F_4 () ) {
V_555 = F_35 ( V_721 , V_600 -> V_724 , V_725 ,
V_726 , & V_252 ) ;
if ( V_555 )
return V_555 ;
}
V_555 = F_299 ( V_651 , V_600 , V_170 , & V_252 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_300 ( V_651 -> V_14 , V_600 , & V_252 ) ;
return V_555 ;
}
static int F_301 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 ;
struct V_650 * V_651 = V_649 -> V_652 ;
T_4 V_170 = V_649 -> V_662 ;
T_2 V_721 = V_651 -> V_14 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
char * V_637 ;
T_11 V_727 ;
T_11 V_728 ;
if ( V_170 != V_177 && V_170 != V_178 )
return 0 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_279 ( V_729 ) )
V_170 = V_177 ;
if ( ! V_730 )
return F_298 ( V_649 , V_600 , V_170 ) ;
V_727 = F_4 () ;
V_728 = F_302 () || F_303 () ;
if ( ! V_727 && ! V_728 )
return 0 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_722 = V_600 -> V_723 ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
V_555 = F_264 ( V_600 , & V_252 , & V_637 , 1 , NULL ) ;
if ( V_555 )
return V_555 ;
if ( V_728 ) {
T_2 V_710 ;
V_555 = F_266 ( V_600 , V_170 , & V_710 ) ;
if ( V_555 )
return V_555 ;
V_555 = F_296 ( V_600 -> V_723 , V_637 , V_170 ,
V_710 , & V_252 ) ;
if ( V_555 ) {
F_304 ( V_600 , V_555 , 0 ) ;
return V_555 ;
}
V_555 = F_35 ( V_721 , V_710 , V_731 ,
V_732 , & V_252 ) ;
if ( V_555 )
F_304 ( V_600 , V_555 , 0 ) ;
}
if ( V_727 ) {
V_555 = F_35 ( V_721 , V_600 -> V_724 , V_725 ,
V_726 , & V_252 ) ;
if ( V_555 )
return V_555 ;
}
return V_555 ;
}
static int F_305 ( struct V_657 * V_648 , char T_13 * V_733 ,
int T_13 * V_734 , unsigned V_84 )
{
int V_555 = 0 ;
char * V_735 ;
T_2 V_736 ;
struct V_650 * V_651 = V_648 -> V_649 -> V_652 ;
T_2 V_710 = V_647 ;
if ( V_651 -> V_28 == V_174 ||
V_651 -> V_28 == V_179 )
V_710 = V_651 -> V_710 ;
if ( V_710 == V_647 )
return - V_737 ;
V_555 = F_47 ( V_710 , & V_735 , & V_736 ) ;
if ( V_555 )
return V_555 ;
if ( V_736 > V_84 ) {
V_555 = - V_219 ;
goto V_738;
}
if ( F_306 ( V_733 , V_735 , V_736 ) )
V_555 = - V_739 ;
V_738:
if ( F_307 ( V_736 , V_734 ) )
V_555 = - V_739 ;
F_28 ( V_735 ) ;
return V_555 ;
}
static int F_308 ( struct V_657 * V_648 , struct V_599 * V_600 , T_2 * V_506 )
{
T_2 V_740 = V_647 ;
T_4 V_170 ;
if ( V_600 && V_600 -> V_166 == F_279 ( V_729 ) )
V_170 = V_177 ;
else if ( V_600 && V_600 -> V_166 == F_279 ( V_741 ) )
V_170 = V_178 ;
else if ( V_648 )
V_170 = V_648 -> V_649 -> V_662 ;
else
goto V_66;
if ( V_648 && V_170 == V_171 )
F_214 ( F_274 ( V_648 ) , & V_740 ) ;
else if ( V_600 )
F_266 ( V_600 , V_170 , & V_740 ) ;
V_66:
* V_506 = V_740 ;
if ( V_740 == V_647 )
return - V_86 ;
return 0 ;
}
static int F_309 ( struct V_648 * V_649 , int V_170 , T_9 V_742 )
{
struct V_650 * V_651 ;
V_651 = F_7 ( sizeof( * V_651 ) , V_742 ) ;
if ( ! V_651 )
return - V_24 ;
V_651 -> V_710 = V_27 ;
V_651 -> V_14 = V_27 ;
F_310 ( V_651 ) ;
V_649 -> V_652 = V_651 ;
return 0 ;
}
static void F_311 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
V_649 -> V_652 = NULL ;
F_312 ( V_651 ) ;
F_28 ( V_651 ) ;
}
static void F_313 ( const struct V_648 * V_649 , struct V_648 * V_705 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
struct V_650 * V_743 = V_705 -> V_652 ;
V_743 -> V_14 = V_651 -> V_14 ;
V_743 -> V_710 = V_651 -> V_710 ;
V_743 -> V_28 = V_651 -> V_28 ;
F_310 ( V_743 ) ;
}
static void F_314 ( struct V_648 * V_649 , T_2 * V_506 )
{
if ( ! V_649 )
* V_506 = V_744 ;
else {
struct V_650 * V_651 = V_649 -> V_652 ;
* V_506 = V_651 -> V_14 ;
}
}
static void F_315 ( struct V_648 * V_649 , struct V_657 * V_327 )
{
struct V_20 * V_21 = F_274 ( V_327 ) -> V_30 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_649 -> V_662 == V_177 || V_649 -> V_662 == V_178 ||
V_649 -> V_662 == V_171 )
V_21 -> V_14 = V_651 -> V_14 ;
V_651 -> V_28 = V_21 -> V_28 ;
}
static int F_316 ( struct V_648 * V_649 , struct V_599 * V_600 ,
struct V_745 * V_746 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
int V_555 ;
T_4 V_170 = V_649 -> V_662 ;
T_2 V_274 ;
T_2 V_747 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_279 ( V_729 ) )
V_170 = V_177 ;
V_555 = F_266 ( V_600 , V_170 , & V_747 ) ;
if ( V_555 )
return V_555 ;
if ( V_747 == V_647 ) {
V_746 -> V_506 = V_651 -> V_14 ;
V_746 -> V_740 = V_647 ;
} else {
V_555 = F_294 ( V_651 -> V_14 , V_747 , & V_274 ) ;
if ( V_555 )
return V_555 ;
V_746 -> V_506 = V_274 ;
V_746 -> V_740 = V_747 ;
}
return F_317 ( V_746 , V_170 ) ;
}
static void F_318 ( struct V_648 * V_705 ,
const struct V_745 * V_746 )
{
struct V_650 * V_743 = V_705 -> V_652 ;
V_743 -> V_14 = V_746 -> V_506 ;
V_743 -> V_710 = V_746 -> V_740 ;
F_319 ( V_705 , V_746 -> V_748 -> V_170 ) ;
}
static void F_320 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
T_4 V_170 = V_649 -> V_662 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_170 == V_178 && V_600 -> V_166 == F_279 ( V_729 ) )
V_170 = V_177 ;
F_266 ( V_600 , V_170 , & V_651 -> V_710 ) ;
}
static int F_321 ( T_2 V_14 )
{
const struct V_10 * V_749 ;
T_2 V_240 ;
V_749 = F_15 () ;
V_240 = V_749 -> V_14 ;
return F_35 ( V_240 , V_14 , V_725 , V_750 , NULL ) ;
}
static void F_322 ( void )
{
F_323 ( & V_6 ) ;
}
static void F_324 ( void )
{
F_325 ( & V_6 ) ;
}
static void F_326 ( const struct V_745 * V_746 ,
struct V_751 * V_752 )
{
V_752 -> V_753 = V_746 -> V_506 ;
}
static int F_327 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_754 , V_755 ,
NULL ) ;
}
static void F_328 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
V_651 -> V_14 = F_14 () ;
V_651 -> V_28 = V_754 ;
}
static int F_329 ( struct V_648 * V_649 )
{
struct V_650 * V_651 = V_649 -> V_652 ;
T_2 V_14 = F_14 () ;
int V_555 ;
V_555 = F_35 ( V_14 , V_651 -> V_14 , V_754 ,
V_756 , NULL ) ;
if ( V_555 )
return V_555 ;
V_555 = F_35 ( V_14 , V_14 , V_754 ,
V_757 , NULL ) ;
if ( V_555 )
return V_555 ;
V_651 -> V_14 = V_14 ;
return 0 ;
}
static int F_330 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 = 0 ;
T_2 V_228 ;
struct V_758 * V_759 ;
struct V_650 * V_651 = V_649 -> V_652 ;
if ( V_600 -> V_84 < F_331 ( 0 ) ) {
V_555 = - V_86 ;
goto V_66;
}
V_759 = F_332 ( V_600 ) ;
V_555 = F_333 ( V_651 -> V_28 , V_759 -> V_760 , & V_228 ) ;
if ( V_555 ) {
if ( V_555 == - V_86 ) {
F_334 ( V_8 -> V_761 , V_12 , V_762 ,
L_42
L_43 ,
V_759 -> V_760 , V_651 -> V_28 ) ;
if ( ! V_3 || F_335 () )
V_555 = 0 ;
}
if ( V_555 == - V_763 )
V_555 = 0 ;
goto V_66;
}
V_555 = F_271 ( V_8 , V_649 , V_228 ) ;
V_66:
return V_555 ;
}
static unsigned int F_336 ( struct V_599 * V_600 , int V_714 ,
T_4 V_170 )
{
int V_555 ;
char * V_637 ;
T_2 V_710 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
T_11 V_727 ;
T_11 V_764 ;
T_11 V_728 ;
if ( ! V_730 )
return V_765 ;
V_727 = F_4 () ;
V_764 = F_302 () ;
V_728 = V_764 || F_303 () ;
if ( ! V_727 && ! V_728 )
return V_765 ;
if ( F_266 ( V_600 , V_170 , & V_710 ) != 0 )
return V_766 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_722 = V_714 ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
if ( F_264 ( V_600 , & V_252 , & V_637 , 1 , NULL ) != 0 )
return V_766 ;
if ( V_728 ) {
V_555 = F_296 ( V_714 , V_637 , V_170 ,
V_710 , & V_252 ) ;
if ( V_555 ) {
F_304 ( V_600 , V_555 , 1 ) ;
return V_766 ;
}
}
if ( V_727 )
if ( F_35 ( V_710 , V_600 -> V_724 ,
V_725 , V_767 , & V_252 ) )
return V_766 ;
if ( V_764 )
if ( F_337 ( V_600 , V_170 , V_710 ) != 0 )
return V_766 ;
return V_765 ;
}
static unsigned int F_338 ( unsigned int V_768 ,
struct V_599 * V_600 ,
const struct V_769 * V_770 ,
const struct V_769 * V_66 ,
int (* F_339)( struct V_599 * ) )
{
return F_336 ( V_600 , V_770 -> V_714 , V_177 ) ;
}
static unsigned int F_340 ( unsigned int V_768 ,
struct V_599 * V_600 ,
const struct V_769 * V_770 ,
const struct V_769 * V_66 ,
int (* F_339)( struct V_599 * ) )
{
return F_336 ( V_600 , V_770 -> V_714 , V_178 ) ;
}
static unsigned int F_341 ( struct V_599 * V_600 ,
T_4 V_170 )
{
T_2 V_14 ;
if ( ! F_302 () )
return V_765 ;
if ( V_600 -> V_649 ) {
struct V_650 * V_651 = V_600 -> V_649 -> V_652 ;
V_14 = V_651 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_337 ( V_600 , V_170 , V_14 ) != 0 )
return V_766 ;
return V_765 ;
}
static unsigned int F_342 ( unsigned int V_768 ,
struct V_599 * V_600 ,
const struct V_769 * V_770 ,
const struct V_769 * V_66 ,
int (* F_339)( struct V_599 * ) )
{
return F_341 ( V_600 , V_177 ) ;
}
static unsigned int F_343 ( struct V_599 * V_600 ,
int V_714 ,
T_4 V_170 )
{
struct V_648 * V_649 = V_600 -> V_649 ;
struct V_650 * V_651 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
char * V_637 ;
T_11 V_601 ;
if ( V_649 == NULL )
return V_765 ;
V_651 = V_649 -> V_652 ;
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_722 = V_714 ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
if ( F_264 ( V_600 , & V_252 , & V_637 , 0 , & V_601 ) )
return V_766 ;
if ( F_4 () )
if ( F_35 ( V_651 -> V_14 , V_600 -> V_724 ,
V_725 , V_771 , & V_252 ) )
return F_344 ( - V_772 ) ;
if ( F_345 ( V_651 -> V_14 , V_600 , & V_252 , V_601 ) )
return F_344 ( - V_772 ) ;
return V_765 ;
}
static unsigned int F_346 ( struct V_599 * V_600 , int V_714 ,
T_4 V_170 )
{
T_2 V_773 ;
T_2 V_710 ;
struct V_648 * V_649 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
struct V_653 V_608 = { 0 ,} ;
char * V_637 ;
T_11 V_727 ;
T_11 V_728 ;
if ( ! V_730 )
return F_343 ( V_600 , V_714 , V_170 ) ;
#ifdef F_347
if ( F_348 ( V_600 ) != NULL && F_348 ( V_600 ) -> V_774 != NULL )
return V_765 ;
#endif
V_727 = F_4 () ;
V_728 = F_302 () || F_303 () ;
if ( ! V_727 && ! V_728 )
return V_765 ;
V_649 = V_600 -> V_649 ;
if ( V_649 == NULL ) {
if ( V_600 -> V_723 ) {
V_773 = V_775 ;
if ( F_266 ( V_600 , V_170 , & V_710 ) )
return V_766 ;
} else {
V_773 = V_771 ;
V_710 = V_15 ;
}
} else {
struct V_650 * V_651 = V_649 -> V_652 ;
V_710 = V_651 -> V_14 ;
V_773 = V_771 ;
}
F_95 ( & V_252 , V_654 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_608 = & V_608 ;
V_252 . V_259 . V_608 -> V_722 = V_714 ;
V_252 . V_259 . V_608 -> V_170 = V_170 ;
if ( F_264 ( V_600 , & V_252 , & V_637 , 0 , NULL ) )
return V_766 ;
if ( V_727 )
if ( F_35 ( V_710 , V_600 -> V_724 ,
V_725 , V_773 , & V_252 ) )
return F_344 ( - V_772 ) ;
if ( V_728 ) {
T_2 V_715 ;
T_2 V_716 ;
if ( F_297 ( V_714 , & V_715 ) )
return V_766 ;
if ( F_35 ( V_710 , V_715 ,
V_717 , V_776 , & V_252 ) )
return F_344 ( - V_772 ) ;
if ( F_280 ( V_637 , V_170 , & V_716 ) )
return V_766 ;
if ( F_35 ( V_710 , V_716 ,
V_719 , V_777 , & V_252 ) )
return F_344 ( - V_772 ) ;
}
return V_765 ;
}
static unsigned int F_349 ( unsigned int V_768 ,
struct V_599 * V_600 ,
const struct V_769 * V_770 ,
const struct V_769 * V_66 ,
int (* F_339)( struct V_599 * ) )
{
return F_346 ( V_600 , V_66 -> V_714 , V_177 ) ;
}
static unsigned int F_350 ( unsigned int V_768 ,
struct V_599 * V_600 ,
const struct V_769 * V_770 ,
const struct V_769 * V_66 ,
int (* F_339)( struct V_599 * ) )
{
return F_346 ( V_600 , V_66 -> V_714 , V_178 ) ;
}
static int F_351 ( struct V_648 * V_649 , struct V_599 * V_600 )
{
int V_555 ;
V_555 = F_352 ( V_649 , V_600 ) ;
if ( V_555 )
return V_555 ;
return F_330 ( V_649 , V_600 ) ;
}
static int F_353 ( struct V_17 * V_18 ,
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
static void F_354 ( struct V_778 * V_228 )
{
struct V_779 * V_21 = V_228 -> V_16 ;
V_228 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_355 ( struct V_780 * V_694 )
{
struct V_781 * V_782 ;
V_782 = F_7 ( sizeof( struct V_781 ) , V_12 ) ;
if ( ! V_782 )
return - V_24 ;
V_782 -> V_14 = V_27 ;
V_694 -> V_16 = V_782 ;
return 0 ;
}
static void F_356 ( struct V_780 * V_694 )
{
struct V_781 * V_782 = V_694 -> V_16 ;
V_694 -> V_16 = NULL ;
F_28 ( V_782 ) ;
}
static int F_357 ( struct V_778 * V_783 ,
T_2 V_238 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
V_21 = V_783 -> V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_783 -> V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , & V_252 ) ;
}
static int F_358 ( struct V_780 * V_694 )
{
return F_355 ( V_694 ) ;
}
static void F_359 ( struct V_780 * V_694 )
{
F_356 ( V_694 ) ;
}
static int F_360 ( struct V_787 * V_788 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_353 ( V_8 , & V_788 -> V_789 , V_790 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_788 -> V_789 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_790 ,
V_791 , & V_252 ) ;
if ( V_47 ) {
F_354 ( & V_788 -> V_789 ) ;
return V_47 ;
}
return 0 ;
}
static void F_361 ( struct V_787 * V_788 )
{
F_354 ( & V_788 -> V_789 ) ;
}
static int F_362 ( struct V_787 * V_788 , int V_792 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
V_21 = V_788 -> V_789 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_788 -> V_789 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_790 ,
V_793 , & V_252 ) ;
}
static int F_363 ( struct V_787 * V_788 , int V_509 )
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
V_555 = F_357 ( & V_788 -> V_789 , V_238 ) ;
return V_555 ;
}
static int F_364 ( struct V_787 * V_788 , struct V_780 * V_694 , int V_792 )
{
struct V_779 * V_21 ;
struct V_781 * V_782 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
V_782 = V_694 -> V_16 ;
if ( V_782 -> V_14 == V_27 ) {
V_47 = F_87 ( V_14 , V_21 -> V_14 , V_804 ,
NULL , & V_782 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_788 -> V_789 . V_786 ;
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
static int F_365 ( struct V_787 * V_788 , struct V_780 * V_694 ,
struct V_17 * V_237 ,
long type , int V_151 )
{
struct V_779 * V_21 ;
struct V_781 * V_782 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_10 ( V_237 ) ;
int V_47 ;
V_21 = V_788 -> V_789 . V_16 ;
V_782 = V_694 -> V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_788 -> V_789 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_790 , V_808 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_782 -> V_14 ,
V_804 , V_809 , & V_252 ) ;
return V_47 ;
}
static int F_366 ( struct V_810 * V_811 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_353 ( V_8 , & V_811 -> V_812 , V_813 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_811 -> V_812 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_811 -> V_812 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_813 ,
V_814 , & V_252 ) ;
if ( V_47 ) {
F_354 ( & V_811 -> V_812 ) ;
return V_47 ;
}
return 0 ;
}
static void F_367 ( struct V_810 * V_811 )
{
F_354 ( & V_811 -> V_812 ) ;
}
static int F_368 ( struct V_810 * V_811 , int V_815 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
V_21 = V_811 -> V_812 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_811 -> V_812 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_813 ,
V_816 , & V_252 ) ;
}
static int F_369 ( struct V_810 * V_811 , int V_509 )
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
V_555 = F_357 ( & V_811 -> V_812 , V_238 ) ;
return V_555 ;
}
static int F_370 ( struct V_810 * V_811 ,
char T_13 * V_825 , int V_815 )
{
T_2 V_238 ;
if ( V_815 & V_826 )
V_238 = V_827 ;
else
V_238 = V_827 | V_828 ;
return F_357 ( & V_811 -> V_812 , V_238 ) ;
}
static int F_371 ( struct V_829 * V_830 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_353 ( V_8 , & V_830 -> V_831 , V_832 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_830 -> V_831 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_830 -> V_831 . V_786 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_832 ,
V_833 , & V_252 ) ;
if ( V_47 ) {
F_354 ( & V_830 -> V_831 ) ;
return V_47 ;
}
return 0 ;
}
static void F_372 ( struct V_829 * V_830 )
{
F_354 ( & V_830 -> V_831 ) ;
}
static int F_373 ( struct V_829 * V_830 , int V_834 )
{
struct V_779 * V_21 ;
struct V_251 V_252 ;
struct V_253 V_254 = { 0 ,} ;
T_2 V_14 = F_14 () ;
V_21 = V_830 -> V_831 . V_16 ;
F_95 ( & V_252 , V_784 ) ;
V_252 . V_253 = & V_254 ;
V_252 . V_259 . V_785 = V_830 -> V_831 . V_786 ;
return F_35 ( V_14 , V_21 -> V_14 , V_832 ,
V_835 , & V_252 ) ;
}
static int F_374 ( struct V_829 * V_830 , int V_509 )
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
V_555 = F_357 ( & V_830 -> V_831 , V_238 ) ;
return V_555 ;
}
static int F_375 ( struct V_829 * V_830 ,
struct V_850 * V_851 , unsigned V_852 , int V_853 )
{
T_2 V_238 ;
if ( V_853 )
V_238 = V_843 | V_846 ;
else
V_238 = V_843 ;
return F_357 ( & V_830 -> V_831 , V_238 ) ;
}
static int F_376 ( struct V_778 * V_854 , short V_98 )
{
T_2 V_257 = 0 ;
V_257 = 0 ;
if ( V_98 & V_855 )
V_257 |= V_856 ;
if ( V_98 & V_857 )
V_257 |= V_858 ;
if ( V_257 == 0 )
return 0 ;
return F_357 ( V_854 , V_257 ) ;
}
static void F_377 ( struct V_778 * V_854 , T_2 * V_506 )
{
struct V_779 * V_21 = V_854 -> V_16 ;
* V_506 = V_21 -> V_14 ;
}
static void F_378 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_379 ( struct V_17 * V_127 ,
char * V_64 , char * * V_470 )
{
const struct V_10 * V_749 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_127 ) {
error = F_92 ( V_127 , V_859 ) ;
if ( error )
return error ;
}
F_11 () ;
V_749 = F_12 ( V_127 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_44 ) )
V_14 = V_749 -> V_14 ;
else if ( ! strcmp ( V_64 , L_45 ) )
V_14 = V_749 -> V_13 ;
else if ( ! strcmp ( V_64 , L_46 ) )
V_14 = V_749 -> V_377 ;
else if ( ! strcmp ( V_64 , L_47 ) )
V_14 = V_749 -> V_275 ;
else if ( ! strcmp ( V_64 , L_48 ) )
V_14 = V_749 -> V_375 ;
else if ( ! strcmp ( V_64 , L_49 ) )
V_14 = V_749 -> V_376 ;
else
goto V_860;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_470 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_860:
F_13 () ;
return - V_86 ;
}
static int F_380 ( struct V_17 * V_127 ,
char * V_64 , void * V_470 , T_7 V_498 )
{
struct V_10 * V_11 ;
struct V_17 * V_389 ;
struct V_7 * V_332 ;
T_2 V_14 = 0 , V_391 ;
int error ;
char * V_1 = V_470 ;
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
error = F_54 ( V_470 , V_498 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_47 ) ) {
if ( ! F_202 ( V_500 ) )
return error ;
error = F_205 ( V_470 , V_498 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_332 = F_381 () ;
if ( ! V_332 )
return - V_24 ;
V_11 = V_332 -> V_16 ;
if ( ! strcmp ( V_64 , L_46 ) ) {
V_11 -> V_377 = V_14 ;
} else if ( ! strcmp ( V_64 , L_47 ) ) {
V_11 -> V_275 = V_14 ;
} else if ( ! strcmp ( V_64 , L_48 ) ) {
error = F_109 ( V_14 , V_127 ) ;
if ( error )
goto V_866;
V_11 -> V_375 = V_14 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
V_11 -> V_376 = V_14 ;
} else if ( ! strcmp ( V_64 , L_44 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_866;
error = - V_386 ;
if ( ! F_382 () ) {
error = F_383 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_866;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_241 ,
V_867 , NULL ) ;
if ( error )
goto V_866;
V_391 = 0 ;
F_154 ( V_127 ) ;
V_389 = F_134 ( V_127 ) ;
if ( V_389 )
V_391 = F_10 ( V_389 ) ;
F_156 ( V_127 ) ;
if ( V_389 ) {
error = F_35 ( V_391 , V_14 , V_241 ,
V_326 , NULL ) ;
if ( error )
goto V_866;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_866;
}
F_384 ( V_332 ) ;
return V_498 ;
V_866:
F_385 ( V_332 ) ;
return error ;
}
static int F_386 ( T_2 V_506 , char * * V_454 , T_2 * V_868 )
{
return F_47 ( V_506 , V_454 , V_868 ) ;
}
static int F_387 ( const char * V_454 , T_2 V_868 , T_2 * V_506 )
{
return F_54 ( V_454 , V_868 , V_506 ) ;
}
static void F_388 ( char * V_454 , T_2 V_868 )
{
F_28 ( V_454 ) ;
}
static int F_389 ( struct V_19 * V_19 , void * V_281 , T_2 V_869 )
{
return F_212 ( V_19 , V_473 , V_281 , V_869 , 0 ) ;
}
static int F_390 ( struct V_52 * V_52 , void * V_281 , T_2 V_869 )
{
return F_391 ( V_52 , V_67 , V_281 , V_869 , 0 ) ;
}
static int F_392 ( struct V_19 * V_19 , void * * V_281 , T_2 * V_869 )
{
int V_84 = 0 ;
V_84 = F_211 ( V_19 , V_473 ,
V_281 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_869 = V_84 ;
return 0 ;
}
static int F_393 ( struct V_786 * V_870 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_871 * V_872 ;
V_872 = F_7 ( sizeof( struct V_871 ) , V_12 ) ;
if ( ! V_872 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_375 )
V_872 -> V_14 = V_11 -> V_375 ;
else
V_872 -> V_14 = V_11 -> V_14 ;
V_870 -> V_16 = V_872 ;
return 0 ;
}
static void F_394 ( struct V_786 * V_870 )
{
struct V_871 * V_872 = V_870 -> V_16 ;
V_870 -> V_16 = NULL ;
F_28 ( V_872 ) ;
}
static int F_395 ( T_14 V_873 ,
const struct V_7 * V_7 ,
T_15 V_228 )
{
struct V_786 * V_786 ;
struct V_871 * V_872 ;
T_2 V_14 ;
if ( V_228 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_786 = F_396 ( V_873 ) ;
V_872 = V_786 -> V_16 ;
return F_35 ( V_14 , V_872 -> V_14 , V_282 , V_228 , NULL ) ;
}
static int F_397 ( struct V_786 * V_786 , char * * V_874 )
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
static T_1 int F_398 ( void )
{
if ( ! F_399 ( & V_875 ) ) {
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
V_22 = F_400 ( L_52 ,
sizeof( struct V_20 ) ,
0 , V_878 , NULL ) ;
F_401 () ;
if ( F_402 ( & V_875 ) )
F_8 ( L_53 ) ;
if ( V_3 )
F_38 ( V_74 L_54 ) ;
else
F_38 ( V_74 L_55 ) ;
return 0 ;
}
static void F_403 ( struct V_41 * V_42 , void * V_879 )
{
F_62 ( V_42 , NULL ) ;
}
void F_404 ( void )
{
F_38 ( V_74 L_56 ) ;
F_38 ( V_74 L_57 ) ;
F_405 ( F_403 , NULL ) ;
}
static int T_1 F_406 ( void )
{
int V_555 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_58 ) ;
V_555 = F_407 ( V_880 , F_39 ( V_880 ) ) ;
if ( V_555 )
F_8 ( L_59 , V_555 ) ;
#if F_265 ( V_640 ) || F_265 ( V_641 )
V_555 = F_407 ( V_881 , F_39 ( V_881 ) ) ;
if ( V_555 )
F_8 ( L_60 , V_555 ) ;
#endif
V_66:
return V_555 ;
}
static void F_408 ( void )
{
F_38 ( V_74 L_61 ) ;
F_409 ( V_880 , F_39 ( V_880 ) ) ;
#if F_265 ( V_640 ) || F_265 ( V_641 )
F_409 ( V_881 , F_39 ( V_881 ) ) ;
#endif
}
int F_410 ( void )
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
F_411 () ;
F_412 () ;
F_408 () ;
F_413 () ;
return 0 ;
}
