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
struct V_253 V_254 ;
T_4 V_28 ;
T_2 V_14 = F_9 ( V_7 ) ;
T_2 V_255 = F_94 ( V_249 ) ;
int V_47 ;
V_252 . type = V_256 ;
V_252 . V_257 . V_249 = V_249 ;
switch ( F_95 ( V_249 ) ) {
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
V_47 = F_96 ( V_14 , V_14 , V_28 , V_255 , 0 , & V_254 ) ;
if ( V_250 == V_260 ) {
int V_261 = F_97 ( V_14 , V_14 , V_28 , V_255 , & V_254 , V_47 , & V_252 , 0 ) ;
if ( V_261 )
return V_261 ;
}
return V_47 ;
}
static int F_98 ( struct V_17 * V_248 ,
T_2 V_238 )
{
T_2 V_14 = F_10 ( V_248 ) ;
return F_35 ( V_14 , V_15 ,
V_262 , V_238 , NULL ) ;
}
static int F_99 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_238 ,
struct V_251 * V_263 ,
unsigned V_69 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_100 ( V_7 ) ;
if ( F_101 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_102 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , V_263 , V_69 ) ;
}
static inline int F_103 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_255 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_251 V_252 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 ;
return F_99 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
}
static inline int F_104 ( const struct V_7 * V_7 ,
struct V_215 * V_215 ,
T_2 V_255 )
{
struct V_19 * V_19 = V_215 -> V_52 -> V_56 ;
struct V_251 V_252 ;
V_252 . type = V_265 ;
V_252 . V_257 . V_215 = * V_215 ;
return F_99 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
}
static int F_105 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_255 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = V_36 -> V_266 . V_52 -> V_56 ;
struct V_251 V_252 ;
T_2 V_14 = F_9 ( V_7 ) ;
int V_47 ;
V_252 . type = V_265 ;
V_252 . V_257 . V_215 = V_36 -> V_266 ;
if ( V_14 != V_38 -> V_14 ) {
V_47 = F_35 ( V_14 , V_38 -> V_14 ,
V_267 ,
V_268 ,
& V_252 ) ;
if ( V_47 )
goto V_66;
}
V_47 = 0 ;
if ( V_255 )
V_47 = F_99 ( V_7 , V_19 , V_255 , & V_252 , 0 ) ;
V_66:
return V_47 ;
}
static int F_106 ( struct V_19 * V_269 ,
struct V_52 * V_52 ,
T_4 V_213 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_270 ;
struct V_31 * V_32 ;
T_2 V_14 , V_271 ;
struct V_251 V_252 ;
int V_47 ;
V_270 = V_269 -> V_30 ;
V_32 = V_269 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_271 = V_11 -> V_272 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_270 -> V_14 , V_161 ,
V_273 | V_274 ,
& V_252 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_271 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_270 -> V_14 , V_213 ,
& V_52 -> V_275 , & V_271 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_35 ( V_14 , V_271 , V_213 , V_276 , & V_252 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_271 , V_32 -> V_14 ,
V_48 ,
V_51 , & V_252 ) ;
}
static int F_107 ( T_2 V_277 ,
struct V_17 * V_278 )
{
T_2 V_14 = F_10 ( V_278 ) ;
return F_35 ( V_14 , V_277 , V_279 , V_280 , NULL ) ;
}
static int F_108 ( struct V_19 * V_269 ,
struct V_52 * V_52 ,
int V_281 )
{
struct V_20 * V_270 , * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
T_2 V_255 ;
int V_47 ;
V_270 = V_269 -> V_30 ;
V_21 = V_52 -> V_56 -> V_30 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 ;
V_255 = V_274 ;
V_255 |= ( V_281 ? V_282 : V_273 ) ;
V_47 = F_35 ( V_14 , V_270 -> V_14 , V_161 , V_255 , & V_252 ) ;
if ( V_47 )
return V_47 ;
switch ( V_281 ) {
case V_283 :
V_255 = V_284 ;
break;
case V_285 :
V_255 = V_286 ;
break;
case V_287 :
V_255 = V_288 ;
break;
default:
F_38 ( V_61 L_30 ,
V_113 , V_281 ) ;
return 0 ;
}
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_255 , & V_252 ) ;
return V_47 ;
}
static inline int F_109 ( struct V_19 * V_289 ,
struct V_52 * V_290 ,
struct V_19 * V_291 ,
struct V_52 * V_292 )
{
struct V_20 * V_293 , * V_294 , * V_295 , * V_296 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
T_2 V_255 ;
int V_297 , V_298 ;
int V_47 ;
V_293 = V_289 -> V_30 ;
V_295 = V_290 -> V_56 -> V_30 ;
V_297 = F_110 ( V_290 -> V_56 -> V_226 ) ;
V_294 = V_291 -> V_30 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_290 ;
V_47 = F_35 ( V_14 , V_293 -> V_14 , V_161 ,
V_282 | V_274 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_295 -> V_14 ,
V_295 -> V_28 , V_299 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_297 && V_291 != V_289 ) {
V_47 = F_35 ( V_14 , V_295 -> V_14 ,
V_295 -> V_28 , V_300 , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . V_257 . V_52 = V_292 ;
V_255 = V_273 | V_274 ;
if ( V_292 -> V_56 )
V_255 |= V_282 ;
V_47 = F_35 ( V_14 , V_294 -> V_14 , V_161 , V_255 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_292 -> V_56 ) {
V_296 = V_292 -> V_56 -> V_30 ;
V_298 = F_110 ( V_292 -> V_56 -> V_226 ) ;
V_47 = F_35 ( V_14 , V_296 -> V_14 ,
V_296 -> V_28 ,
( V_298 ? V_288 : V_286 ) , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_111 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_238 ,
struct V_251 * V_252 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_238 , V_252 ) ;
}
static inline T_2 F_112 ( int V_151 , int V_301 )
{
T_2 V_255 = 0 ;
if ( ! F_110 ( V_151 ) ) {
if ( V_301 & V_302 )
V_255 |= V_303 ;
if ( V_301 & V_304 )
V_255 |= V_305 ;
if ( V_301 & V_306 )
V_255 |= V_307 ;
else if ( V_301 & V_308 )
V_255 |= V_309 ;
} else {
if ( V_301 & V_302 )
V_255 |= V_274 ;
if ( V_301 & V_308 )
V_255 |= V_310 ;
if ( V_301 & V_304 )
V_255 |= V_311 ;
}
return V_255 ;
}
static inline T_2 F_113 ( struct V_36 * V_36 )
{
T_2 V_255 = 0 ;
if ( V_36 -> V_312 & V_313 )
V_255 |= V_305 ;
if ( V_36 -> V_312 & V_314 ) {
if ( V_36 -> V_315 & V_316 )
V_255 |= V_307 ;
else
V_255 |= V_309 ;
}
if ( ! V_255 ) {
V_255 = V_317 ;
}
return V_255 ;
}
static inline T_2 F_114 ( struct V_36 * V_36 )
{
T_2 V_255 = F_113 ( V_36 ) ;
if ( V_318 )
V_255 |= V_319 ;
return V_255 ;
}
static int F_115 ( struct V_17 * V_320 ,
unsigned int V_151 )
{
int V_47 ;
V_47 = F_116 ( V_320 , V_151 ) ;
if ( V_47 )
return V_47 ;
if ( V_151 & V_321 ) {
T_2 V_14 = F_14 () ;
T_2 V_322 = F_10 ( V_320 ) ;
return F_35 ( V_14 , V_322 , V_29 , V_305 , NULL ) ;
}
return F_92 ( V_320 , V_323 ) ;
}
static int F_117 ( struct V_17 * V_324 )
{
int V_47 ;
V_47 = F_118 ( V_324 ) ;
if ( V_47 )
return V_47 ;
return F_91 ( V_324 , V_8 , V_323 ) ;
}
static int F_119 ( struct V_17 * V_237 , T_6 * V_325 ,
T_6 * V_326 , T_6 * V_327 )
{
int error ;
error = F_92 ( V_237 , V_328 ) ;
if ( error )
return error ;
return F_120 ( V_237 , V_325 , V_326 , V_327 ) ;
}
static int F_121 ( struct V_7 * V_329 , const struct V_7 * V_330 ,
const T_6 * V_325 ,
const T_6 * V_326 ,
const T_6 * V_327 )
{
int error ;
error = F_122 ( V_329 , V_330 ,
V_325 , V_326 , V_327 ) ;
if ( error )
return error ;
return F_90 ( V_330 , V_329 , V_331 ) ;
}
static int F_123 ( const struct V_7 * V_7 , struct V_332 * V_333 ,
int V_249 , int V_250 )
{
int V_47 ;
V_47 = F_124 ( V_7 , V_333 , V_249 , V_250 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_7 , V_249 , V_250 ) ;
}
static int F_125 ( int V_334 , int type , int V_335 , struct V_41 * V_42 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( ! V_42 )
return 0 ;
switch ( V_334 ) {
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
V_47 = F_111 ( V_7 , V_42 , V_341 , NULL ) ;
break;
case V_342 :
case V_343 :
case V_344 :
V_47 = F_111 ( V_7 , V_42 , V_345 , NULL ) ;
break;
default:
V_47 = 0 ;
break;
}
return V_47 ;
}
static int F_126 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_346 ) ;
}
static int F_127 ( int type )
{
int V_47 ;
switch ( type ) {
case V_347 :
case V_348 :
V_47 = F_98 ( V_8 , V_349 ) ;
break;
case V_350 :
case V_351 :
case V_352 :
V_47 = F_98 ( V_8 , V_353 ) ;
break;
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
default:
V_47 = F_98 ( V_8 , V_359 ) ;
break;
}
return V_47 ;
}
static int F_128 ( struct V_360 * V_361 , long V_362 )
{
int V_47 , V_363 = 0 ;
V_47 = F_123 ( F_52 () , & V_364 , V_365 ,
V_366 ) ;
if ( V_47 == 0 )
V_363 = 1 ;
return F_129 ( V_361 , V_362 , V_363 ) ;
}
static int F_130 ( struct V_367 * V_368 )
{
const struct V_10 * V_369 ;
struct V_10 * V_370 ;
struct V_20 * V_21 ;
struct V_251 V_252 ;
struct V_19 * V_19 = V_368 -> V_36 -> V_266 . V_52 -> V_56 ;
int V_47 ;
V_47 = F_131 ( V_368 ) ;
if ( V_47 )
return V_47 ;
if ( V_368 -> V_371 )
return 0 ;
V_369 = F_15 () ;
V_370 = V_368 -> V_7 -> V_16 ;
V_21 = V_19 -> V_30 ;
V_370 -> V_14 = V_369 -> V_14 ;
V_370 -> V_13 = V_369 -> V_14 ;
V_370 -> V_272 = 0 ;
V_370 -> V_372 = 0 ;
V_370 -> V_373 = 0 ;
if ( V_369 -> V_374 ) {
V_370 -> V_14 = V_369 -> V_374 ;
V_370 -> V_374 = 0 ;
if ( V_368 -> V_375 & V_376 )
return - V_377 ;
} else {
V_47 = F_87 ( V_369 -> V_14 , V_21 -> V_14 ,
V_241 , NULL ,
& V_370 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . type = V_265 ;
V_252 . V_257 . V_215 = V_368 -> V_36 -> V_266 ;
if ( ( V_368 -> V_36 -> V_266 . V_378 -> V_101 & V_379 ) ||
( V_368 -> V_375 & V_376 ) )
V_370 -> V_14 = V_369 -> V_14 ;
if ( V_370 -> V_14 == V_369 -> V_14 ) {
V_47 = F_35 ( V_369 -> V_14 , V_21 -> V_14 ,
V_29 , V_380 , & V_252 ) ;
if ( V_47 )
return V_47 ;
} else {
V_47 = F_35 ( V_369 -> V_14 , V_370 -> V_14 ,
V_241 , V_381 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_370 -> V_14 , V_21 -> V_14 ,
V_29 , V_382 , & V_252 ) ;
if ( V_47 )
return V_47 ;
if ( V_368 -> V_375 & V_383 ) {
V_47 = F_35 ( V_369 -> V_14 , V_370 -> V_14 ,
V_241 , V_384 ,
NULL ) ;
if ( V_47 )
return - V_377 ;
}
if ( V_368 -> V_375 &
( V_385 | V_386 ) ) {
struct V_17 * V_387 ;
struct V_10 * V_388 ;
T_2 V_389 = 0 ;
F_11 () ;
V_387 = F_132 ( V_8 ) ;
if ( F_133 ( V_387 != NULL ) ) {
V_388 = F_12 ( V_387 ) -> V_16 ;
V_389 = V_388 -> V_14 ;
}
F_13 () ;
if ( V_389 != 0 ) {
V_47 = F_35 ( V_389 , V_370 -> V_14 ,
V_241 ,
V_323 , NULL ) ;
if ( V_47 )
return - V_377 ;
}
}
V_368 -> V_390 |= V_391 ;
}
return 0 ;
}
static int F_134 ( struct V_367 * V_368 )
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
return ( V_392 || F_135 ( V_368 ) ) ;
}
static inline void F_136 ( const struct V_7 * V_7 ,
struct V_394 * V_395 )
{
struct V_36 * V_36 , * V_396 = NULL ;
struct V_397 * V_398 ;
struct V_399 * V_400 ;
long V_401 = - 1 ;
int V_402 = 0 ;
V_398 = F_137 () ;
if ( V_398 ) {
F_21 ( & V_403 ) ;
if ( ! F_22 ( & V_398 -> V_404 ) ) {
struct V_405 * V_406 ;
V_406 = F_138 ( & V_398 -> V_404 ,
struct V_405 , V_26 ) ;
V_36 = V_406 -> V_36 ;
if ( F_104 ( V_7 , & V_36 -> V_266 , V_305 | V_309 ) )
V_402 = 1 ;
}
F_24 ( & V_403 ) ;
F_139 ( V_398 ) ;
}
if ( V_402 )
F_140 () ;
F_21 ( & V_395 -> V_407 ) ;
for (; ; ) {
unsigned long V_408 , V_82 ;
int V_409 ;
V_401 ++ ;
V_82 = V_401 * V_410 ;
V_400 = F_141 ( V_395 ) ;
if ( V_82 >= V_400 -> V_411 )
break;
V_408 = V_400 -> V_412 [ V_401 ] ;
if ( ! V_408 )
continue;
F_24 ( & V_395 -> V_407 ) ;
for ( ; V_408 ; V_82 ++ , V_408 >>= 1 ) {
if ( V_408 & 1 ) {
V_36 = F_142 ( V_82 ) ;
if ( ! V_36 )
continue;
if ( F_105 ( V_7 ,
V_36 ,
F_113 ( V_36 ) ) ) {
F_143 ( V_82 ) ;
V_409 = F_144 () ;
if ( V_409 != V_82 ) {
if ( V_409 >= 0 )
F_145 ( V_409 ) ;
F_146 ( V_36 ) ;
continue;
}
if ( V_396 ) {
F_147 ( V_396 ) ;
} else {
V_396 = F_148 (
F_81 ( V_413 ) ,
F_149 ( V_414 ) ,
V_415 , V_7 ) ;
if ( F_75 ( V_396 ) ) {
V_396 = NULL ;
F_145 ( V_409 ) ;
F_146 ( V_36 ) ;
continue;
}
}
F_150 ( V_409 , V_396 ) ;
}
F_146 ( V_36 ) ;
}
}
F_21 ( & V_395 -> V_407 ) ;
}
F_24 ( & V_395 -> V_407 ) ;
}
static void F_151 ( struct V_367 * V_368 )
{
struct V_10 * V_370 ;
struct V_416 * V_417 , * V_418 ;
int V_47 , V_82 ;
V_370 = V_368 -> V_7 -> V_16 ;
if ( V_370 -> V_14 == V_370 -> V_13 )
return;
F_136 ( V_368 -> V_7 , V_8 -> V_395 ) ;
V_8 -> V_419 = 0 ;
V_47 = F_35 ( V_370 -> V_13 , V_370 -> V_14 , V_241 ,
V_420 , NULL ) ;
if ( V_47 ) {
F_152 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_421 ; V_82 ++ ) {
V_417 = V_8 -> signal -> V_417 + V_82 ;
V_418 = V_422 . signal -> V_417 + V_82 ;
V_417 -> V_423 = F_153 ( V_417 -> V_424 , V_418 -> V_423 ) ;
}
F_154 ( V_8 ) ;
F_155 ( V_8 , V_416 ( V_425 ) ) ;
}
}
static void F_156 ( struct V_367 * V_368 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_426 V_427 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_241 , V_428 , NULL ) ;
if ( V_47 ) {
memset ( & V_427 , 0 , sizeof V_427 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_157 ( V_82 , & V_427 , NULL ) ;
F_158 ( & V_8 -> V_429 -> V_430 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_431 ) ) {
F_159 ( V_8 ) ;
F_160 ( V_8 , 1 ) ;
F_161 ( & V_8 -> V_432 ) ;
}
F_162 ( & V_8 -> V_429 -> V_430 ) ;
}
F_163 ( & V_433 ) ;
F_164 ( V_8 , V_8 -> V_434 ) ;
F_165 ( & V_433 ) ;
}
static int F_166 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_167 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_168 ( char * V_144 , int V_435 , char * V_436 , int V_437 )
{
if ( V_435 > V_437 )
return 0 ;
return ! memcmp ( V_144 , V_436 , V_435 ) ;
}
static inline int F_169 ( char * V_436 , int V_84 )
{
return ( F_168 ( V_146 , sizeof( V_146 ) - 1 , V_436 , V_84 ) ||
F_168 ( V_147 , sizeof( V_147 ) - 1 , V_436 , V_84 ) ||
F_168 ( V_149 , sizeof( V_149 ) - 1 , V_436 , V_84 ) ||
F_168 ( V_148 , sizeof( V_148 ) - 1 , V_436 , V_84 ) ||
F_168 ( V_150 , sizeof( V_150 ) - 1 , V_436 , V_84 ) ) ;
}
static inline void F_170 ( char * * V_438 , char * V_439 , int * V_440 , int V_84 )
{
if ( ! * V_440 ) {
* * V_438 = ',' ;
* V_438 += 1 ;
} else
* V_440 = 0 ;
memcpy ( * V_438 , V_439 , V_84 ) ;
* V_438 += V_84 ;
}
static inline void F_171 ( char * * V_438 , char * V_439 , int * V_440 ,
int V_84 )
{
int V_441 = 0 ;
if ( ! * V_440 ) {
* * V_438 = '|' ;
* V_438 += 1 ;
} else
* V_440 = 0 ;
while ( V_441 < V_84 ) {
if ( * V_439 != '"' ) {
* * V_438 = * V_439 ;
* V_438 += 1 ;
}
V_439 += 1 ;
V_441 += 1 ;
}
}
static int F_172 ( char * V_442 , char * V_443 )
{
int V_444 , V_38 , V_47 = 0 ;
char * V_445 , * V_446 , * V_447 ;
char * V_448 , * V_449 , * V_450 ;
int V_451 = 0 ;
V_446 = V_442 ;
V_448 = V_443 ;
V_450 = ( char * ) F_173 ( V_12 ) ;
if ( ! V_450 ) {
V_47 = - V_24 ;
goto V_66;
}
V_449 = V_450 ;
V_444 = V_38 = 1 ;
V_445 = V_447 = V_442 ;
do {
if ( * V_447 == '"' )
V_451 = ! V_451 ;
if ( ( * V_447 == ',' && V_451 == 0 ) ||
* V_447 == '\0' ) {
int V_84 = V_447 - V_446 ;
if ( F_169 ( V_446 , V_84 ) )
F_171 ( & V_448 , V_446 , & V_38 , V_84 ) ;
else
F_170 ( & V_450 , V_446 , & V_444 , V_84 ) ;
V_446 = V_447 + 1 ;
}
} while ( * V_447 ++ );
strcpy ( V_445 , V_449 ) ;
F_78 ( ( unsigned long ) V_449 ) ;
V_66:
return V_47 ;
}
static int F_174 ( struct V_41 * V_42 , void * V_141 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_452 , * * V_107 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_141 )
return 0 ;
if ( V_42 -> V_63 -> V_109 & V_110 )
return 0 ;
F_45 ( & V_81 ) ;
V_452 = F_175 () ;
if ( ! V_452 )
return - V_24 ;
V_47 = F_172 ( V_141 , V_452 ) ;
if ( V_47 )
goto V_453;
V_47 = F_58 ( V_452 , & V_81 ) ;
if ( V_47 )
goto V_453;
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
goto V_454;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_455;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_455;
break;
case V_97 : {
struct V_20 * V_102 ;
V_102 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 , V_14 ) )
goto V_455;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_455;
break;
default:
goto V_454;
}
}
V_47 = 0 ;
V_454:
F_49 ( & V_81 ) ;
V_453:
F_176 ( V_452 ) ;
return V_47 ;
V_455:
F_38 ( V_61 L_31
L_32 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_454;
}
static int F_177 ( struct V_41 * V_42 , int V_69 , void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
int V_47 ;
V_47 = F_62 ( V_42 , V_141 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_456 )
return 0 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_42 -> V_54 ;
return F_111 ( V_7 , V_42 , V_457 , & V_252 ) ;
}
static int F_178 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 -> V_458 -> V_54 ;
return F_111 ( V_7 , V_52 -> V_458 , V_459 , & V_252 ) ;
}
static int F_179 ( char * V_460 ,
struct V_215 * V_215 ,
char * type ,
unsigned long V_69 ,
void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_461 )
return F_111 ( V_7 , V_215 -> V_52 -> V_458 ,
V_462 , NULL ) ;
else
return F_104 ( V_7 , V_215 , V_463 ) ;
}
static int F_180 ( struct V_464 * V_378 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_111 ( V_7 , V_378 -> V_465 ,
V_466 , NULL ) ;
}
static int F_181 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_182 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_183 ( struct V_19 * V_19 , struct V_19 * V_269 ,
const struct V_467 * V_467 , char * * V_64 ,
void * * V_468 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_270 ;
struct V_31 * V_32 ;
T_2 V_14 , V_271 , V_469 ;
int V_47 ;
char * V_470 = NULL , * V_83 ;
V_270 = V_269 -> V_30 ;
V_32 = V_269 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_271 = V_11 -> V_272 ;
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_57 == V_76 ) )
V_271 = V_32 -> V_46 ;
else if ( ! V_271 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_87 ( V_14 , V_270 -> V_14 ,
F_68 ( V_19 -> V_226 ) ,
V_467 , & V_271 ) ;
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
V_21 -> V_14 = V_271 ;
V_21 -> V_114 = 1 ;
}
if ( ! V_87 || ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( V_64 ) {
V_470 = F_184 ( V_471 , V_23 ) ;
if ( ! V_470 )
return - V_24 ;
* V_64 = V_470 ;
}
if ( V_468 && V_84 ) {
V_47 = F_185 ( V_271 , & V_83 , & V_469 ) ;
if ( V_47 ) {
F_28 ( V_470 ) ;
return V_47 ;
}
* V_468 = V_83 ;
* V_84 = V_469 ;
}
return 0 ;
}
static int F_186 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_151 )
{
return F_106 ( V_269 , V_52 , V_29 ) ;
}
static int F_187 ( struct V_52 * V_290 , struct V_19 * V_269 , struct V_52 * V_292 )
{
return F_108 ( V_269 , V_290 , V_283 ) ;
}
static int F_188 ( struct V_19 * V_269 , struct V_52 * V_52 )
{
return F_108 ( V_269 , V_52 , V_285 ) ;
}
static int F_189 ( struct V_19 * V_269 , struct V_52 * V_52 , const char * V_64 )
{
return F_106 ( V_269 , V_52 , V_156 ) ;
}
static int F_190 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_301 )
{
return F_106 ( V_269 , V_52 , V_161 ) ;
}
static int F_191 ( struct V_19 * V_269 , struct V_52 * V_52 )
{
return F_108 ( V_269 , V_52 , V_287 ) ;
}
static int F_192 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_151 , T_8 V_221 )
{
return F_106 ( V_269 , V_52 , F_68 ( V_151 ) ) ;
}
static int F_193 ( struct V_19 * V_472 , struct V_52 * V_290 ,
struct V_19 * V_473 , struct V_52 * V_292 )
{
return F_109 ( V_472 , V_290 , V_473 , V_292 ) ;
}
static int F_194 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_305 ) ;
}
static int F_195 ( struct V_52 * V_52 , struct V_474 * V_474 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_305 ) ;
}
static T_9 int F_196 ( struct V_19 * V_19 ,
T_2 V_238 , T_2 V_475 , T_2 V_476 ,
unsigned V_69 )
{
struct V_251 V_252 ;
struct V_20 * V_21 = V_19 -> V_30 ;
int V_47 ;
V_252 . type = V_477 ;
V_252 . V_257 . V_19 = V_19 ;
V_47 = F_197 ( F_14 () , V_21 -> V_14 , V_21 -> V_28 , V_238 ,
V_475 , V_476 , & V_252 , V_69 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_198 ( struct V_19 * V_19 , int V_301 )
{
const struct V_7 * V_7 = F_52 () ;
T_2 V_238 ;
bool V_478 ;
unsigned V_69 = V_301 & V_479 ;
struct V_20 * V_21 ;
T_2 V_14 ;
struct V_253 V_254 ;
int V_47 , V_261 ;
T_2 V_475 , V_476 ;
V_478 = V_301 & V_480 ;
V_301 &= ( V_304 | V_308 | V_302 | V_306 ) ;
if ( ! V_301 )
return 0 ;
F_100 ( V_7 ) ;
if ( F_101 ( F_42 ( V_19 ) ) )
return 0 ;
V_238 = F_112 ( V_19 -> V_226 , V_301 ) ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
V_47 = F_96 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , 0 , & V_254 ) ;
V_475 = F_199 ( V_238 , & V_254 , V_47 ,
V_478 ? V_481 : 0 ,
& V_476 ) ;
if ( F_133 ( ! V_475 ) )
return V_47 ;
V_261 = F_196 ( V_19 , V_238 , V_475 , V_476 , V_69 ) ;
if ( V_261 )
return V_261 ;
return V_47 ;
}
static int F_200 ( struct V_52 * V_52 , struct V_482 * V_482 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_483 = V_482 -> V_483 ;
T_10 V_255 = V_309 ;
if ( V_483 & V_484 ) {
V_483 &= ~ ( V_485 | V_486 | V_487 |
V_484 ) ;
if ( ! V_483 )
return 0 ;
}
if ( V_483 & ( V_487 | V_488 | V_489 |
V_490 | V_491 | V_492 ) )
return F_103 ( V_7 , V_52 , V_493 ) ;
if ( V_318 && ( V_483 & V_494 ) )
V_255 |= V_319 ;
return F_103 ( V_7 , V_52 , V_255 ) ;
}
static int F_201 ( struct V_464 * V_378 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_215 V_215 ;
V_215 . V_52 = V_52 ;
V_215 . V_378 = V_378 ;
return F_104 ( V_7 , & V_215 , V_495 ) ;
}
static int F_202 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_496 ,
sizeof V_496 - 1 ) ) {
if ( ! strcmp ( V_64 , V_497 ) ) {
if ( ! F_203 ( V_498 ) )
return - V_377 ;
} else if ( ! F_203 ( V_365 ) ) {
return - V_377 ;
}
}
return F_103 ( V_7 , V_52 , V_493 ) ;
}
static int F_204 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_468 , T_7 V_499 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_251 V_252 ;
T_2 V_271 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_202 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_205 ( V_19 ) )
return - V_377 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_500 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_468 , V_499 , & V_271 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_203 ( V_501 ) ) {
struct V_502 * V_503 ;
T_7 V_504 ;
const char * V_1 ;
V_1 = V_468 ;
if ( V_1 [ V_499 - 1 ] == '\0' )
V_504 = V_499 - 1 ;
else
V_504 = V_499 ;
V_503 = F_206 ( V_8 -> V_505 , V_91 , V_506 ) ;
F_207 ( V_503 , L_36 ) ;
F_208 ( V_503 , V_468 , V_504 ) ;
F_209 ( V_503 ) ;
return V_47 ;
}
V_47 = F_210 ( V_468 , V_499 , & V_271 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_271 , V_21 -> V_28 ,
V_507 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_211 ( V_21 -> V_14 , V_271 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_271 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_252 ) ;
}
static void F_212 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_468 , T_7 V_499 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_271 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_210 ( V_468 , V_499 , & V_271 ) ;
if ( V_47 ) {
F_38 ( V_73 L_37
L_38 ,
V_19 -> V_33 -> V_62 , V_19 -> V_220 , - V_47 ) ;
return;
}
V_21 -> V_14 = V_271 ;
return;
}
static int F_213 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_495 ) ;
}
static int F_214 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_495 ) ;
}
static int F_215 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_202 ( V_52 , V_64 ) ;
return - V_508 ;
}
static int F_216 ( const struct V_19 * V_19 , const char * V_64 , void * * V_214 , bool V_509 )
{
T_2 V_499 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_471 ) )
return - V_65 ;
error = F_123 ( F_52 () , & V_364 , V_501 ,
V_366 ) ;
if ( ! error )
error = F_185 ( V_21 -> V_14 , & V_83 ,
& V_499 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_499 ) ;
if ( error )
return error ;
error = V_499 ;
if ( V_509 ) {
* V_214 = V_83 ;
goto V_510;
}
F_28 ( V_83 ) ;
V_510:
return error ;
}
static int F_217 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_468 , T_7 V_499 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_271 ;
int V_47 ;
if ( strcmp ( V_64 , V_471 ) )
return - V_65 ;
if ( ! V_468 || ! V_499 )
return - V_508 ;
V_47 = F_54 ( ( void * ) V_468 , V_499 , & V_271 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_14 = V_271 ;
V_21 -> V_114 = 1 ;
return 0 ;
}
static int F_218 ( struct V_19 * V_19 , char * V_214 , T_7 V_511 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_214 && V_84 <= V_511 )
memcpy ( V_214 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_219 ( const struct V_19 * V_19 , T_2 * V_512 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_512 = V_21 -> V_14 ;
}
static int F_220 ( struct V_36 * V_36 , int V_301 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = V_36 -> V_266 . V_52 -> V_56 ;
if ( ( V_36 -> V_315 & V_316 ) && ( V_301 & V_308 ) )
V_301 |= V_306 ;
return F_105 ( V_7 , V_36 ,
F_112 ( V_19 -> V_226 , V_301 ) ) ;
}
static int F_221 ( struct V_36 * V_36 , int V_301 )
{
struct V_19 * V_19 = V_36 -> V_266 . V_52 -> V_56 ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_301 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_513 == V_21 -> V_14 &&
V_38 -> V_514 == F_222 () )
return 0 ;
return F_220 ( V_36 , V_301 ) ;
}
static int F_223 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_224 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_225 ( struct V_36 * V_36 , unsigned int V_515 ,
unsigned long V_516 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_515 ) {
case V_517 :
case V_518 :
case V_519 :
case V_520 :
case V_521 :
error = F_105 ( V_7 , V_36 , V_495 ) ;
break;
case V_522 :
case V_523 :
error = F_105 ( V_7 , V_36 , V_493 ) ;
break;
case V_524 :
case V_525 :
error = F_105 ( V_7 , V_36 , 0 ) ;
break;
case V_526 :
case V_527 :
error = F_93 ( V_7 , V_528 ,
V_260 ) ;
break;
default:
error = F_105 ( V_7 , V_36 , V_317 ) ;
}
return error ;
}
static int F_226 ( struct V_36 * V_36 , unsigned long V_529 , int V_530 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_531 &&
( V_529 & V_532 ) && ( ! V_36 || ( ! V_530 && ( V_529 & V_533 ) ) ) ) {
V_47 = F_90 ( V_7 , V_7 , V_534 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_255 = V_305 ;
if ( V_530 && ( V_529 & V_533 ) )
V_255 |= V_309 ;
if ( V_529 & V_532 )
V_255 |= V_303 ;
return F_105 ( V_7 , V_36 , V_255 ) ;
}
error:
return V_47 ;
}
static int F_227 ( unsigned long V_535 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_535 < V_536 ) {
V_47 = F_35 ( V_14 , V_14 , V_537 ,
V_538 , NULL ) ;
if ( V_47 )
return V_47 ;
}
return F_228 ( V_535 ) ;
}
static int F_229 ( struct V_36 * V_36 , unsigned long V_539 ,
unsigned long V_529 , unsigned long V_69 )
{
if ( V_540 )
V_529 = V_539 ;
return F_226 ( V_36 , V_529 ,
( V_69 & V_541 ) == V_542 ) ;
}
static int F_230 ( struct V_543 * V_544 ,
unsigned long V_539 ,
unsigned long V_529 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_540 )
V_529 = V_539 ;
if ( V_531 &&
( V_529 & V_532 ) && ! ( V_544 -> V_545 & V_546 ) ) {
int V_47 = 0 ;
if ( V_544 -> V_547 >= V_544 -> V_548 -> V_549 &&
V_544 -> V_550 <= V_544 -> V_548 -> V_551 ) {
V_47 = F_90 ( V_7 , V_7 , V_552 ) ;
} else if ( ! V_544 -> V_553 &&
V_544 -> V_547 <= V_544 -> V_548 -> V_554 &&
V_544 -> V_550 >= V_544 -> V_548 -> V_554 ) {
V_47 = F_92 ( V_8 , V_555 ) ;
} else if ( V_544 -> V_553 && V_544 -> V_556 ) {
V_47 = F_105 ( V_7 , V_544 -> V_553 , V_557 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_226 ( V_544 -> V_553 , V_529 , V_544 -> V_545 & V_558 ) ;
}
static int F_231 ( struct V_36 * V_36 , unsigned int V_515 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_36 , V_559 ) ;
}
static int F_232 ( struct V_36 * V_36 , unsigned int V_515 ,
unsigned long V_516 )
{
const struct V_7 * V_7 = F_52 () ;
int V_560 = 0 ;
switch ( V_515 ) {
case V_561 :
if ( ! V_36 -> V_266 . V_52 || ! V_36 -> V_266 . V_52 -> V_56 ) {
V_560 = - V_86 ;
break;
}
if ( ( V_36 -> V_315 & V_316 ) && ! ( V_516 & V_316 ) ) {
V_560 = F_105 ( V_7 , V_36 , V_309 ) ;
break;
}
case V_562 :
case V_563 :
case V_564 :
case V_565 :
case V_566 :
V_560 = F_105 ( V_7 , V_36 , 0 ) ;
break;
case V_567 :
case V_568 :
case V_569 :
#if V_570 == 32
case V_571 :
case V_572 :
case V_573 :
#endif
if ( ! V_36 -> V_266 . V_52 || ! V_36 -> V_266 . V_52 -> V_56 ) {
V_560 = - V_86 ;
break;
}
V_560 = F_105 ( V_7 , V_36 , V_559 ) ;
break;
}
return V_560 ;
}
static int F_233 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_234 ( struct V_17 * V_248 ,
struct V_574 * V_575 , int V_576 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_248 ) ;
T_2 V_228 ;
struct V_37 * V_38 ;
V_36 = F_235 ( V_575 , struct V_36 , V_577 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_576 )
V_228 = F_89 ( V_578 ) ;
else
V_228 = F_89 ( V_576 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_241 , V_228 , NULL ) ;
}
static int F_236 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_36 , F_113 ( V_36 ) ) ;
}
static int F_237 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_20 * V_21 ;
V_38 = V_36 -> V_40 ;
V_21 = V_36 -> V_266 . V_52 -> V_56 -> V_30 ;
V_38 -> V_513 = V_21 -> V_14 ;
V_38 -> V_514 = F_222 () ;
return F_104 ( V_7 , & V_36 -> V_266 , F_114 ( V_36 ) ) ;
}
static int F_238 ( unsigned long V_579 )
{
return F_92 ( V_8 , V_580 ) ;
}
static int F_239 ( struct V_7 * V_7 , T_11 V_581 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_581 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_240 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_216 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_241 ( struct V_7 * V_329 , const struct V_7 * V_330 ,
T_11 V_581 )
{
const struct V_10 * V_369 ;
struct V_10 * V_11 ;
V_369 = V_330 -> V_16 ;
V_11 = F_242 ( V_369 , sizeof( struct V_10 ) , V_581 ) ;
if ( ! V_11 )
return - V_24 ;
V_329 -> V_16 = V_11 ;
return 0 ;
}
static void F_243 ( struct V_7 * V_329 , const struct V_7 * V_330 )
{
const struct V_10 * V_369 = V_330 -> V_16 ;
struct V_10 * V_11 = V_329 -> V_16 ;
* V_11 = * V_369 ;
}
static int F_244 ( struct V_7 * V_329 , T_2 V_512 )
{
struct V_10 * V_11 = V_329 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_582 ;
V_582 = F_35 ( V_14 , V_512 ,
V_583 ,
V_584 ,
NULL ) ;
if ( V_582 == 0 ) {
V_11 -> V_14 = V_512 ;
V_11 -> V_272 = 0 ;
V_11 -> V_372 = 0 ;
V_11 -> V_373 = 0 ;
}
return V_582 ;
}
static int F_245 ( struct V_7 * V_329 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_329 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_582 ;
V_582 = F_35 ( V_14 , V_21 -> V_14 ,
V_583 ,
V_585 ,
NULL ) ;
if ( V_582 == 0 )
V_11 -> V_272 = V_21 -> V_14 ;
return V_582 ;
}
static int F_246 ( char * V_586 )
{
T_2 V_14 ;
struct V_251 V_252 ;
V_14 = F_10 ( V_8 ) ;
V_252 . type = V_587 ;
V_252 . V_257 . V_586 = V_586 ;
return F_35 ( V_14 , V_15 , V_262 ,
V_588 , & V_252 ) ;
}
static int F_247 ( struct V_17 * V_127 , T_12 V_589 )
{
return F_92 ( V_127 , V_590 ) ;
}
static int F_248 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_591 ) ;
}
static int F_249 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_592 ) ;
}
static void F_250 ( struct V_17 * V_127 , T_2 * V_512 )
{
* V_512 = F_10 ( V_127 ) ;
}
static int F_251 ( struct V_17 * V_127 , int V_593 )
{
int V_47 ;
V_47 = F_252 ( V_127 , V_593 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_594 ) ;
}
static int F_253 ( struct V_17 * V_127 , int V_595 )
{
int V_47 ;
V_47 = F_254 ( V_127 , V_595 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_594 ) ;
}
static int F_255 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_596 ) ;
}
static int F_256 ( struct V_17 * V_127 , unsigned int V_597 ,
struct V_416 * V_598 )
{
struct V_416 * V_599 = V_127 -> signal -> V_417 + V_597 ;
if ( V_599 -> V_424 != V_598 -> V_424 )
return F_92 ( V_127 , V_600 ) ;
return 0 ;
}
static int F_257 ( struct V_17 * V_127 )
{
int V_47 ;
V_47 = F_258 ( V_127 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_594 ) ;
}
static int F_259 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_596 ) ;
}
static int F_260 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_594 ) ;
}
static int F_261 ( struct V_17 * V_127 , struct V_601 * V_602 ,
int V_227 , T_2 V_512 )
{
T_2 V_228 ;
int V_47 ;
if ( ! V_227 )
V_228 = V_603 ;
else
V_228 = F_89 ( V_227 ) ;
if ( V_512 )
V_47 = F_35 ( V_512 , F_10 ( V_127 ) ,
V_241 , V_228 , NULL ) ;
else
V_47 = F_92 ( V_127 , V_228 ) ;
return V_47 ;
}
static int F_262 ( struct V_17 * V_127 )
{
return F_91 ( V_127 , V_8 , V_230 ) ;
}
static void F_263 ( struct V_17 * V_127 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_127 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_114 = 1 ;
}
static int F_264 ( struct V_604 * V_605 ,
struct V_251 * V_252 , T_13 * V_606 )
{
int V_607 , V_608 , V_582 = - V_86 ;
struct V_609 V_610 , * V_611 ;
V_607 = F_265 ( V_605 ) ;
V_611 = F_266 ( V_605 , V_607 , sizeof( V_610 ) , & V_610 ) ;
if ( V_611 == NULL )
goto V_66;
V_608 = V_611 -> V_612 * 4 ;
if ( V_608 < sizeof( V_610 ) )
goto V_66;
V_252 -> V_257 . V_613 -> V_614 . V_615 = V_611 -> V_615 ;
V_252 -> V_257 . V_613 -> V_614 . V_616 = V_611 -> V_616 ;
V_582 = 0 ;
if ( V_606 )
* V_606 = V_611 -> V_166 ;
switch ( V_611 -> V_166 ) {
case V_168 : {
struct V_617 V_618 , * V_619 ;
if ( F_267 ( V_611 -> V_620 ) & V_621 )
break;
V_607 += V_608 ;
V_619 = F_266 ( V_605 , V_607 , sizeof( V_618 ) , & V_618 ) ;
if ( V_619 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_619 -> V_623 ;
V_252 -> V_257 . V_613 -> V_624 = V_619 -> V_625 ;
break;
}
case V_169 : {
struct V_626 V_627 , * V_628 ;
if ( F_267 ( V_611 -> V_620 ) & V_621 )
break;
V_607 += V_608 ;
V_628 = F_266 ( V_605 , V_607 , sizeof( V_627 ) , & V_627 ) ;
if ( V_628 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_628 -> V_623 ;
V_252 -> V_257 . V_613 -> V_624 = V_628 -> V_625 ;
break;
}
case V_629 : {
struct V_630 V_631 , * V_632 ;
if ( F_267 ( V_611 -> V_620 ) & V_621 )
break;
V_607 += V_608 ;
V_632 = F_266 ( V_605 , V_607 , sizeof( V_631 ) , & V_631 ) ;
if ( V_632 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_632 -> V_633 ;
V_252 -> V_257 . V_613 -> V_624 = V_632 -> V_634 ;
break;
}
default:
break;
}
V_66:
return V_582 ;
}
static int F_268 ( struct V_604 * V_605 ,
struct V_251 * V_252 , T_13 * V_606 )
{
T_13 V_635 ;
int V_582 = - V_86 , V_607 ;
struct V_636 V_637 , * V_638 ;
T_14 V_620 ;
V_607 = F_265 ( V_605 ) ;
V_638 = F_266 ( V_605 , V_607 , sizeof( V_637 ) , & V_637 ) ;
if ( V_638 == NULL )
goto V_66;
V_252 -> V_257 . V_613 -> V_639 . V_615 = V_638 -> V_615 ;
V_252 -> V_257 . V_613 -> V_639 . V_616 = V_638 -> V_616 ;
V_582 = 0 ;
V_635 = V_638 -> V_635 ;
V_607 += sizeof( V_637 ) ;
V_607 = F_269 ( V_605 , V_607 , & V_635 , & V_620 ) ;
if ( V_607 < 0 )
goto V_66;
if ( V_606 )
* V_606 = V_635 ;
switch ( V_635 ) {
case V_168 : {
struct V_617 V_618 , * V_619 ;
V_619 = F_266 ( V_605 , V_607 , sizeof( V_618 ) , & V_618 ) ;
if ( V_619 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_619 -> V_623 ;
V_252 -> V_257 . V_613 -> V_624 = V_619 -> V_625 ;
break;
}
case V_169 : {
struct V_626 V_627 , * V_628 ;
V_628 = F_266 ( V_605 , V_607 , sizeof( V_627 ) , & V_627 ) ;
if ( V_628 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_628 -> V_623 ;
V_252 -> V_257 . V_613 -> V_624 = V_628 -> V_625 ;
break;
}
case V_629 : {
struct V_630 V_631 , * V_632 ;
V_632 = F_266 ( V_605 , V_607 , sizeof( V_631 ) , & V_631 ) ;
if ( V_632 == NULL )
break;
V_252 -> V_257 . V_613 -> V_622 = V_632 -> V_633 ;
V_252 -> V_257 . V_613 -> V_624 = V_632 -> V_634 ;
break;
}
default:
break;
}
V_66:
return V_582 ;
}
static int F_270 ( struct V_604 * V_605 , struct V_251 * V_252 ,
char * * V_640 , int V_641 , T_13 * V_606 )
{
char * V_642 ;
int V_582 ;
switch ( V_252 -> V_257 . V_613 -> V_170 ) {
case V_177 :
V_582 = F_264 ( V_605 , V_252 , V_606 ) ;
if ( V_582 )
goto V_643;
V_642 = ( char * ) ( V_641 ? & V_252 -> V_257 . V_613 -> V_614 . V_615 :
& V_252 -> V_257 . V_613 -> V_614 . V_616 ) ;
goto V_644;
#if F_271 ( V_645 ) || F_271 ( V_646 )
case V_178 :
V_582 = F_268 ( V_605 , V_252 , V_606 ) ;
if ( V_582 )
goto V_643;
V_642 = ( char * ) ( V_641 ? & V_252 -> V_257 . V_613 -> V_639 . V_615 :
& V_252 -> V_257 . V_613 -> V_639 . V_616 ) ;
goto V_644;
#endif
default:
V_642 = NULL ;
goto V_644;
}
V_643:
F_38 ( V_61
L_39
L_40 ) ;
return V_582 ;
V_644:
if ( V_640 )
* V_640 = V_642 ;
return 0 ;
}
static int F_272 ( struct V_604 * V_605 , T_4 V_170 , T_2 * V_14 )
{
int V_560 ;
T_2 V_647 ;
T_2 V_648 ;
T_2 V_649 ;
F_273 ( V_605 , & V_647 ) ;
F_274 ( V_605 , V_170 , & V_649 , & V_648 ) ;
V_560 = F_275 ( V_648 , V_649 , V_647 , V_14 ) ;
if ( F_101 ( V_560 ) ) {
F_38 ( V_61
L_41
L_42 ) ;
return - V_508 ;
}
return 0 ;
}
static int F_276 ( const struct V_10 * V_11 ,
T_4 V_650 , T_2 * V_651 )
{
if ( V_11 -> V_373 > V_652 ) {
* V_651 = V_11 -> V_373 ;
return 0 ;
}
return F_87 ( V_11 -> V_14 , V_11 -> V_14 , V_650 , NULL ,
V_651 ) ;
}
static int F_277 ( struct V_17 * V_18 , struct V_653 * V_654 , T_2 V_238 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
T_2 V_240 = F_10 ( V_18 ) ;
if ( V_656 -> V_14 == V_15 )
return 0 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_654 = V_654 ;
return F_35 ( V_240 , V_656 -> V_14 , V_656 -> V_28 , V_238 , & V_252 ) ;
}
static int F_278 ( int V_170 , int type ,
int V_166 , int V_660 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_271 ;
T_4 V_650 ;
int V_47 ;
if ( V_660 )
return 0 ;
V_650 = F_71 ( V_170 , type , V_166 ) ;
V_47 = F_276 ( V_11 , V_650 , & V_271 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_271 , V_650 , V_661 , NULL ) ;
}
static int F_279 ( struct V_662 * V_653 , int V_170 ,
int type , int V_166 , int V_660 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_280 ( V_653 ) -> V_30 ;
struct V_655 * V_656 ;
int V_560 = 0 ;
V_21 -> V_28 = F_71 ( V_170 , type , V_166 ) ;
if ( V_660 )
V_21 -> V_14 = V_15 ;
else {
V_560 = F_276 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_560 )
return V_560 ;
}
V_21 -> V_114 = 1 ;
if ( V_653 -> V_654 ) {
V_656 = V_653 -> V_654 -> V_657 ;
V_656 -> V_14 = V_21 -> V_14 ;
V_656 -> V_28 = V_21 -> V_28 ;
V_560 = F_281 ( V_653 -> V_654 , V_170 ) ;
}
return V_560 ;
}
static int F_282 ( struct V_662 * V_653 , struct V_663 * V_664 , int V_665 )
{
struct V_653 * V_654 = V_653 -> V_654 ;
T_4 V_170 ;
int V_560 ;
V_560 = F_277 ( V_8 , V_654 , V_666 ) ;
if ( V_560 )
goto V_66;
V_170 = V_654 -> V_667 ;
if ( V_170 == V_177 || V_170 == V_178 ) {
char * V_642 ;
struct V_655 * V_656 = V_654 -> V_657 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
struct V_668 * V_669 = NULL ;
struct V_670 * V_671 = NULL ;
unsigned short V_672 ;
T_2 V_14 , V_673 ;
if ( V_170 == V_177 ) {
V_669 = (struct V_668 * ) V_664 ;
V_672 = F_267 ( V_669 -> V_674 ) ;
V_642 = ( char * ) & V_669 -> V_675 . V_676 ;
} else {
V_671 = (struct V_670 * ) V_664 ;
V_672 = F_267 ( V_671 -> V_677 ) ;
V_642 = ( char * ) & V_671 -> V_678 . V_679 ;
}
if ( V_672 ) {
int V_680 , V_681 ;
F_283 ( & V_680 , & V_681 ) ;
if ( V_672 < V_682 ( V_683, V_680 ) || V_672 > V_681 ) {
V_560 = F_284 ( V_654 -> V_684 ,
V_672 , & V_14 ) ;
if ( V_560 )
goto V_66;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_622 = F_285 ( V_672 ) ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
V_560 = F_35 ( V_656 -> V_14 , V_14 ,
V_656 -> V_28 ,
V_685 , & V_252 ) ;
if ( V_560 )
goto V_66;
}
}
switch ( V_656 -> V_28 ) {
case V_179 :
V_673 = V_686 ;
break;
case V_181 :
V_673 = V_687 ;
break;
case V_183 :
V_673 = V_688 ;
break;
default:
V_673 = V_689 ;
break;
}
V_560 = F_286 ( V_642 , V_170 , & V_14 ) ;
if ( V_560 )
goto V_66;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_622 = F_285 ( V_672 ) ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
if ( V_170 == V_177 )
V_252 . V_257 . V_613 -> V_614 . V_615 = V_669 -> V_675 . V_676 ;
else
V_252 . V_257 . V_613 -> V_639 . V_615 = V_671 -> V_678 ;
V_560 = F_35 ( V_656 -> V_14 , V_14 ,
V_656 -> V_28 , V_673 , & V_252 ) ;
if ( V_560 )
goto V_66;
}
V_66:
return V_560 ;
}
static int F_287 ( struct V_662 * V_653 , struct V_663 * V_664 , int V_665 )
{
struct V_653 * V_654 = V_653 -> V_654 ;
struct V_655 * V_656 = V_654 -> V_657 ;
int V_560 ;
V_560 = F_277 ( V_8 , V_654 , V_690 ) ;
if ( V_560 )
return V_560 ;
if ( V_656 -> V_28 == V_179 ||
V_656 -> V_28 == V_183 ) {
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
struct V_668 * V_669 = NULL ;
struct V_670 * V_671 = NULL ;
unsigned short V_672 ;
T_2 V_14 , V_228 ;
if ( V_654 -> V_667 == V_177 ) {
V_669 = (struct V_668 * ) V_664 ;
if ( V_665 < sizeof( struct V_668 ) )
return - V_86 ;
V_672 = F_267 ( V_669 -> V_674 ) ;
} else {
V_671 = (struct V_670 * ) V_664 ;
if ( V_665 < V_691 )
return - V_86 ;
V_672 = F_267 ( V_671 -> V_677 ) ;
}
V_560 = F_284 ( V_654 -> V_684 , V_672 , & V_14 ) ;
if ( V_560 )
goto V_66;
V_228 = ( V_656 -> V_28 == V_179 ) ?
V_692 : V_693 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_624 = F_285 ( V_672 ) ;
V_252 . V_257 . V_613 -> V_170 = V_654 -> V_667 ;
V_560 = F_35 ( V_656 -> V_14 , V_14 , V_656 -> V_28 , V_228 , & V_252 ) ;
if ( V_560 )
goto V_66;
}
V_560 = F_288 ( V_654 , V_664 ) ;
V_66:
return V_560 ;
}
static int F_289 ( struct V_662 * V_653 , int V_694 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_695 ) ;
}
static int F_290 ( struct V_662 * V_653 , struct V_662 * V_696 )
{
int V_560 ;
struct V_20 * V_21 ;
struct V_20 * V_123 ;
V_560 = F_277 ( V_8 , V_653 -> V_654 , V_697 ) ;
if ( V_560 )
return V_560 ;
V_123 = F_280 ( V_696 ) -> V_30 ;
V_21 = F_280 ( V_653 ) -> V_30 ;
V_123 -> V_28 = V_21 -> V_28 ;
V_123 -> V_14 = V_21 -> V_14 ;
V_123 -> V_114 = 1 ;
return 0 ;
}
static int F_291 ( struct V_662 * V_653 , struct V_698 * V_699 ,
int V_499 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_700 ) ;
}
static int F_292 ( struct V_662 * V_653 , struct V_698 * V_699 ,
int V_499 , int V_69 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_701 ) ;
}
static int F_293 ( struct V_662 * V_653 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_702 ) ;
}
static int F_294 ( struct V_662 * V_653 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_702 ) ;
}
static int F_295 ( struct V_662 * V_653 , int V_703 , int V_704 )
{
int V_560 ;
V_560 = F_277 ( V_8 , V_653 -> V_654 , V_705 ) ;
if ( V_560 )
return V_560 ;
return F_296 ( V_653 , V_703 , V_704 ) ;
}
static int F_297 ( struct V_662 * V_653 , int V_703 ,
int V_704 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_706 ) ;
}
static int F_298 ( struct V_662 * V_653 , int V_707 )
{
return F_277 ( V_8 , V_653 -> V_654 , V_708 ) ;
}
static int F_299 ( struct V_653 * V_653 ,
struct V_653 * V_709 ,
struct V_653 * V_710 )
{
struct V_655 * V_711 = V_653 -> V_657 ;
struct V_655 * V_712 = V_709 -> V_657 ;
struct V_655 * V_713 = V_710 -> V_657 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
int V_560 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_654 = V_709 ;
V_560 = F_35 ( V_711 -> V_14 , V_712 -> V_14 ,
V_712 -> V_28 ,
V_714 , & V_252 ) ;
if ( V_560 )
return V_560 ;
V_713 -> V_715 = V_711 -> V_14 ;
V_560 = F_300 ( V_712 -> V_14 , V_711 -> V_14 ,
& V_713 -> V_14 ) ;
if ( V_560 )
return V_560 ;
V_711 -> V_715 = V_713 -> V_14 ;
return 0 ;
}
static int F_301 ( struct V_662 * V_653 ,
struct V_662 * V_709 )
{
struct V_655 * V_716 = V_653 -> V_654 -> V_657 ;
struct V_655 * V_717 = V_709 -> V_654 -> V_657 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_654 = V_709 -> V_654 ;
return F_35 ( V_716 -> V_14 , V_717 -> V_14 , V_717 -> V_28 , V_718 ,
& V_252 ) ;
}
static int F_302 ( int V_719 , char * V_642 , T_4 V_170 ,
T_2 V_715 ,
struct V_251 * V_252 )
{
int V_560 ;
T_2 V_720 ;
T_2 V_721 ;
V_560 = F_303 ( V_719 , & V_720 ) ;
if ( V_560 )
return V_560 ;
V_560 = F_35 ( V_715 , V_720 ,
V_722 , V_723 , V_252 ) ;
if ( V_560 )
return V_560 ;
V_560 = F_286 ( V_642 , V_170 , & V_721 ) ;
if ( V_560 )
return V_560 ;
return F_35 ( V_715 , V_721 ,
V_724 , V_725 , V_252 ) ;
}
static int F_304 ( struct V_653 * V_654 , struct V_604 * V_605 ,
T_4 V_170 )
{
int V_560 = 0 ;
struct V_655 * V_656 = V_654 -> V_657 ;
T_2 V_726 = V_656 -> V_14 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
char * V_642 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_727 = V_605 -> V_728 ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
V_560 = F_270 ( V_605 , & V_252 , & V_642 , 1 , NULL ) ;
if ( V_560 )
return V_560 ;
if ( F_4 () ) {
V_560 = F_35 ( V_726 , V_605 -> V_729 , V_730 ,
V_731 , & V_252 ) ;
if ( V_560 )
return V_560 ;
}
V_560 = F_305 ( V_656 , V_605 , V_170 , & V_252 ) ;
if ( V_560 )
return V_560 ;
V_560 = F_306 ( V_656 -> V_14 , V_605 , & V_252 ) ;
return V_560 ;
}
static int F_307 ( struct V_653 * V_654 , struct V_604 * V_605 )
{
int V_560 ;
struct V_655 * V_656 = V_654 -> V_657 ;
T_4 V_170 = V_654 -> V_667 ;
T_2 V_726 = V_656 -> V_14 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
char * V_642 ;
T_13 V_732 ;
T_13 V_733 ;
if ( V_170 != V_177 && V_170 != V_178 )
return 0 ;
if ( V_170 == V_178 && V_605 -> V_166 == F_285 ( V_734 ) )
V_170 = V_177 ;
if ( ! V_735 )
return F_304 ( V_654 , V_605 , V_170 ) ;
V_732 = F_4 () ;
V_733 = F_308 () || F_309 () ;
if ( ! V_732 && ! V_733 )
return 0 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_727 = V_605 -> V_728 ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
V_560 = F_270 ( V_605 , & V_252 , & V_642 , 1 , NULL ) ;
if ( V_560 )
return V_560 ;
if ( V_733 ) {
T_2 V_715 ;
V_560 = F_272 ( V_605 , V_170 , & V_715 ) ;
if ( V_560 )
return V_560 ;
V_560 = F_302 ( V_605 -> V_728 , V_642 , V_170 ,
V_715 , & V_252 ) ;
if ( V_560 ) {
F_310 ( V_605 , V_560 , 0 ) ;
return V_560 ;
}
V_560 = F_35 ( V_726 , V_715 , V_736 ,
V_737 , & V_252 ) ;
if ( V_560 )
F_310 ( V_605 , V_560 , 0 ) ;
}
if ( V_732 ) {
V_560 = F_35 ( V_726 , V_605 -> V_729 , V_730 ,
V_731 , & V_252 ) ;
if ( V_560 )
return V_560 ;
}
return V_560 ;
}
static int F_311 ( struct V_662 * V_653 , char T_15 * V_738 ,
int T_15 * V_739 , unsigned V_84 )
{
int V_560 = 0 ;
char * V_740 ;
T_2 V_741 ;
struct V_655 * V_656 = V_653 -> V_654 -> V_657 ;
T_2 V_715 = V_652 ;
if ( V_656 -> V_28 == V_174 ||
V_656 -> V_28 == V_179 )
V_715 = V_656 -> V_715 ;
if ( V_715 == V_652 )
return - V_742 ;
V_560 = F_47 ( V_715 , & V_740 , & V_741 ) ;
if ( V_560 )
return V_560 ;
if ( V_741 > V_84 ) {
V_560 = - V_219 ;
goto V_743;
}
if ( F_312 ( V_738 , V_740 , V_741 ) )
V_560 = - V_744 ;
V_743:
if ( F_313 ( V_741 , V_739 ) )
V_560 = - V_744 ;
F_28 ( V_740 ) ;
return V_560 ;
}
static int F_314 ( struct V_662 * V_653 , struct V_604 * V_605 , T_2 * V_512 )
{
T_2 V_745 = V_652 ;
T_4 V_170 ;
if ( V_605 && V_605 -> V_166 == F_285 ( V_734 ) )
V_170 = V_177 ;
else if ( V_605 && V_605 -> V_166 == F_285 ( V_746 ) )
V_170 = V_178 ;
else if ( V_653 )
V_170 = V_653 -> V_654 -> V_667 ;
else
goto V_66;
if ( V_653 && V_170 == V_171 )
F_219 ( F_280 ( V_653 ) , & V_745 ) ;
else if ( V_605 )
F_272 ( V_605 , V_170 , & V_745 ) ;
V_66:
* V_512 = V_745 ;
if ( V_745 == V_652 )
return - V_86 ;
return 0 ;
}
static int F_315 ( struct V_653 * V_654 , int V_170 , T_11 V_747 )
{
struct V_655 * V_656 ;
V_656 = F_7 ( sizeof( * V_656 ) , V_747 ) ;
if ( ! V_656 )
return - V_24 ;
V_656 -> V_715 = V_27 ;
V_656 -> V_14 = V_27 ;
F_316 ( V_656 ) ;
V_654 -> V_657 = V_656 ;
return 0 ;
}
static void F_317 ( struct V_653 * V_654 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
V_654 -> V_657 = NULL ;
F_318 ( V_656 ) ;
F_28 ( V_656 ) ;
}
static void F_319 ( const struct V_653 * V_654 , struct V_653 * V_710 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
struct V_655 * V_748 = V_710 -> V_657 ;
V_748 -> V_14 = V_656 -> V_14 ;
V_748 -> V_715 = V_656 -> V_715 ;
V_748 -> V_28 = V_656 -> V_28 ;
F_316 ( V_748 ) ;
}
static void F_320 ( struct V_653 * V_654 , T_2 * V_512 )
{
if ( ! V_654 )
* V_512 = V_749 ;
else {
struct V_655 * V_656 = V_654 -> V_657 ;
* V_512 = V_656 -> V_14 ;
}
}
static void F_321 ( struct V_653 * V_654 , struct V_662 * V_324 )
{
struct V_20 * V_21 = F_280 ( V_324 ) -> V_30 ;
struct V_655 * V_656 = V_654 -> V_657 ;
if ( V_654 -> V_667 == V_177 || V_654 -> V_667 == V_178 ||
V_654 -> V_667 == V_171 )
V_21 -> V_14 = V_656 -> V_14 ;
V_656 -> V_28 = V_21 -> V_28 ;
}
static int F_322 ( struct V_653 * V_654 , struct V_604 * V_605 ,
struct V_750 * V_751 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
int V_560 ;
T_4 V_170 = V_654 -> V_667 ;
T_2 V_271 ;
T_2 V_752 ;
if ( V_170 == V_178 && V_605 -> V_166 == F_285 ( V_734 ) )
V_170 = V_177 ;
V_560 = F_272 ( V_605 , V_170 , & V_752 ) ;
if ( V_560 )
return V_560 ;
if ( V_752 == V_652 ) {
V_751 -> V_512 = V_656 -> V_14 ;
V_751 -> V_745 = V_652 ;
} else {
V_560 = F_300 ( V_656 -> V_14 , V_752 , & V_271 ) ;
if ( V_560 )
return V_560 ;
V_751 -> V_512 = V_271 ;
V_751 -> V_745 = V_752 ;
}
return F_323 ( V_751 , V_170 ) ;
}
static void F_324 ( struct V_653 * V_710 ,
const struct V_750 * V_751 )
{
struct V_655 * V_748 = V_710 -> V_657 ;
V_748 -> V_14 = V_751 -> V_512 ;
V_748 -> V_715 = V_751 -> V_745 ;
F_325 ( V_710 , V_751 -> V_753 -> V_170 ) ;
}
static void F_326 ( struct V_653 * V_654 , struct V_604 * V_605 )
{
T_4 V_170 = V_654 -> V_667 ;
struct V_655 * V_656 = V_654 -> V_657 ;
if ( V_170 == V_178 && V_605 -> V_166 == F_285 ( V_734 ) )
V_170 = V_177 ;
F_272 ( V_605 , V_170 , & V_656 -> V_715 ) ;
}
static int F_327 ( T_2 V_14 )
{
const struct V_10 * V_754 ;
T_2 V_240 ;
V_754 = F_15 () ;
V_240 = V_754 -> V_14 ;
return F_35 ( V_240 , V_14 , V_730 , V_755 , NULL ) ;
}
static void F_328 ( void )
{
F_329 ( & V_6 ) ;
}
static void F_330 ( void )
{
F_331 ( & V_6 ) ;
}
static void F_332 ( const struct V_750 * V_751 ,
struct V_756 * V_757 )
{
V_757 -> V_758 = V_751 -> V_512 ;
}
static int F_333 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_759 , V_760 ,
NULL ) ;
}
static void F_334 ( struct V_653 * V_654 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
V_656 -> V_14 = F_14 () ;
V_656 -> V_28 = V_759 ;
}
static int F_335 ( struct V_653 * V_654 )
{
struct V_655 * V_656 = V_654 -> V_657 ;
T_2 V_14 = F_14 () ;
int V_560 ;
V_560 = F_35 ( V_14 , V_656 -> V_14 , V_759 ,
V_761 , NULL ) ;
if ( V_560 )
return V_560 ;
V_560 = F_35 ( V_14 , V_14 , V_759 ,
V_762 , NULL ) ;
if ( V_560 )
return V_560 ;
V_656 -> V_14 = V_14 ;
return 0 ;
}
static int F_336 ( struct V_653 * V_654 , struct V_604 * V_605 )
{
int V_560 = 0 ;
T_2 V_228 ;
struct V_763 * V_764 ;
struct V_655 * V_656 = V_654 -> V_657 ;
if ( V_605 -> V_84 < F_337 ( 0 ) ) {
V_560 = - V_86 ;
goto V_66;
}
V_764 = F_338 ( V_605 ) ;
V_560 = F_339 ( V_656 -> V_28 , V_764 -> V_765 , & V_228 ) ;
if ( V_560 ) {
if ( V_560 == - V_86 ) {
F_340 ( V_8 -> V_505 , V_12 , V_506 ,
L_43
L_44 ,
V_764 -> V_765 , V_656 -> V_28 ) ;
if ( ! V_3 || F_341 () )
V_560 = 0 ;
}
if ( V_560 == - V_766 )
V_560 = 0 ;
goto V_66;
}
V_560 = F_277 ( V_8 , V_654 , V_228 ) ;
V_66:
return V_560 ;
}
static unsigned int F_342 ( struct V_604 * V_605 , int V_719 ,
T_4 V_170 )
{
int V_560 ;
char * V_642 ;
T_2 V_715 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
T_13 V_732 ;
T_13 V_767 ;
T_13 V_733 ;
if ( ! V_735 )
return V_768 ;
V_732 = F_4 () ;
V_767 = F_308 () ;
V_733 = V_767 || F_309 () ;
if ( ! V_732 && ! V_733 )
return V_768 ;
if ( F_272 ( V_605 , V_170 , & V_715 ) != 0 )
return V_769 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_727 = V_719 ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
if ( F_270 ( V_605 , & V_252 , & V_642 , 1 , NULL ) != 0 )
return V_769 ;
if ( V_733 ) {
V_560 = F_302 ( V_719 , V_642 , V_170 ,
V_715 , & V_252 ) ;
if ( V_560 ) {
F_310 ( V_605 , V_560 , 1 ) ;
return V_769 ;
}
}
if ( V_732 )
if ( F_35 ( V_715 , V_605 -> V_729 ,
V_730 , V_770 , & V_252 ) )
return V_769 ;
if ( V_767 )
if ( F_343 ( V_605 , V_170 , V_715 ) != 0 )
return V_769 ;
return V_768 ;
}
static unsigned int F_344 ( unsigned int V_771 ,
struct V_604 * V_605 ,
const struct V_772 * V_773 ,
const struct V_772 * V_66 ,
int (* F_345)( struct V_604 * ) )
{
return F_342 ( V_605 , V_773 -> V_719 , V_177 ) ;
}
static unsigned int F_346 ( unsigned int V_771 ,
struct V_604 * V_605 ,
const struct V_772 * V_773 ,
const struct V_772 * V_66 ,
int (* F_345)( struct V_604 * ) )
{
return F_342 ( V_605 , V_773 -> V_719 , V_178 ) ;
}
static unsigned int F_347 ( struct V_604 * V_605 ,
T_4 V_170 )
{
T_2 V_14 ;
if ( ! F_308 () )
return V_768 ;
if ( V_605 -> V_654 ) {
struct V_655 * V_656 = V_605 -> V_654 -> V_657 ;
V_14 = V_656 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_343 ( V_605 , V_170 , V_14 ) != 0 )
return V_769 ;
return V_768 ;
}
static unsigned int F_348 ( unsigned int V_771 ,
struct V_604 * V_605 ,
const struct V_772 * V_773 ,
const struct V_772 * V_66 ,
int (* F_345)( struct V_604 * ) )
{
return F_347 ( V_605 , V_177 ) ;
}
static unsigned int F_349 ( struct V_604 * V_605 ,
int V_719 ,
T_4 V_170 )
{
struct V_653 * V_654 = V_605 -> V_654 ;
struct V_655 * V_656 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
char * V_642 ;
T_13 V_606 ;
if ( V_654 == NULL )
return V_768 ;
V_656 = V_654 -> V_657 ;
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_727 = V_719 ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
if ( F_270 ( V_605 , & V_252 , & V_642 , 0 , & V_606 ) )
return V_769 ;
if ( F_4 () )
if ( F_35 ( V_656 -> V_14 , V_605 -> V_729 ,
V_730 , V_774 , & V_252 ) )
return F_350 ( - V_775 ) ;
if ( F_351 ( V_656 -> V_14 , V_605 , & V_252 , V_606 ) )
return F_350 ( - V_775 ) ;
return V_768 ;
}
static unsigned int F_352 ( struct V_604 * V_605 , int V_719 ,
T_4 V_170 )
{
T_2 V_776 ;
T_2 V_715 ;
struct V_653 * V_654 ;
struct V_251 V_252 ;
struct V_658 V_613 = { 0 ,} ;
char * V_642 ;
T_13 V_732 ;
T_13 V_733 ;
if ( ! V_735 )
return F_349 ( V_605 , V_719 , V_170 ) ;
#ifdef F_353
if ( F_354 ( V_605 ) != NULL && F_354 ( V_605 ) -> V_777 != NULL )
return V_768 ;
#endif
V_732 = F_4 () ;
V_733 = F_308 () || F_309 () ;
if ( ! V_732 && ! V_733 )
return V_768 ;
V_654 = V_605 -> V_654 ;
if ( V_654 == NULL ) {
if ( V_605 -> V_728 ) {
V_776 = V_778 ;
if ( F_272 ( V_605 , V_170 , & V_715 ) )
return V_769 ;
} else {
V_776 = V_774 ;
V_715 = V_15 ;
}
} else {
struct V_655 * V_656 = V_654 -> V_657 ;
V_715 = V_656 -> V_14 ;
V_776 = V_774 ;
}
V_252 . type = V_659 ;
V_252 . V_257 . V_613 = & V_613 ;
V_252 . V_257 . V_613 -> V_727 = V_719 ;
V_252 . V_257 . V_613 -> V_170 = V_170 ;
if ( F_270 ( V_605 , & V_252 , & V_642 , 0 , NULL ) )
return V_769 ;
if ( V_732 )
if ( F_35 ( V_715 , V_605 -> V_729 ,
V_730 , V_776 , & V_252 ) )
return F_350 ( - V_775 ) ;
if ( V_733 ) {
T_2 V_720 ;
T_2 V_721 ;
if ( F_303 ( V_719 , & V_720 ) )
return V_769 ;
if ( F_35 ( V_715 , V_720 ,
V_722 , V_779 , & V_252 ) )
return F_350 ( - V_775 ) ;
if ( F_286 ( V_642 , V_170 , & V_721 ) )
return V_769 ;
if ( F_35 ( V_715 , V_721 ,
V_724 , V_780 , & V_252 ) )
return F_350 ( - V_775 ) ;
}
return V_768 ;
}
static unsigned int F_355 ( unsigned int V_771 ,
struct V_604 * V_605 ,
const struct V_772 * V_773 ,
const struct V_772 * V_66 ,
int (* F_345)( struct V_604 * ) )
{
return F_352 ( V_605 , V_66 -> V_719 , V_177 ) ;
}
static unsigned int F_356 ( unsigned int V_771 ,
struct V_604 * V_605 ,
const struct V_772 * V_773 ,
const struct V_772 * V_66 ,
int (* F_345)( struct V_604 * ) )
{
return F_352 ( V_605 , V_66 -> V_719 , V_178 ) ;
}
static int F_357 ( struct V_653 * V_654 , struct V_604 * V_605 )
{
int V_560 ;
V_560 = F_358 ( V_654 , V_605 ) ;
if ( V_560 )
return V_560 ;
return F_336 ( V_654 , V_605 ) ;
}
static int F_359 ( struct V_17 * V_18 ,
struct V_781 * V_228 ,
T_4 V_28 )
{
struct V_782 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_782 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_228 -> V_16 = V_21 ;
return 0 ;
}
static void F_360 ( struct V_781 * V_228 )
{
struct V_782 * V_21 = V_228 -> V_16 ;
V_228 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_361 ( struct V_783 * V_699 )
{
struct V_784 * V_785 ;
V_785 = F_7 ( sizeof( struct V_784 ) , V_12 ) ;
if ( ! V_785 )
return - V_24 ;
V_785 -> V_14 = V_27 ;
V_699 -> V_16 = V_785 ;
return 0 ;
}
static void F_362 ( struct V_783 * V_699 )
{
struct V_784 * V_785 = V_699 -> V_16 ;
V_699 -> V_16 = NULL ;
F_28 ( V_785 ) ;
}
static int F_363 ( struct V_781 * V_786 ,
T_2 V_238 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_786 -> V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_786 -> V_789 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , & V_252 ) ;
}
static int F_364 ( struct V_783 * V_699 )
{
return F_361 ( V_699 ) ;
}
static void F_365 ( struct V_783 * V_699 )
{
F_362 ( V_699 ) ;
}
static int F_366 ( struct V_790 * V_791 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_359 ( V_8 , & V_791 -> V_792 , V_793 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_791 -> V_792 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_791 -> V_792 . V_789 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_793 ,
V_794 , & V_252 ) ;
if ( V_47 ) {
F_360 ( & V_791 -> V_792 ) ;
return V_47 ;
}
return 0 ;
}
static void F_367 ( struct V_790 * V_791 )
{
F_360 ( & V_791 -> V_792 ) ;
}
static int F_368 ( struct V_790 * V_791 , int V_795 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_791 -> V_792 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_791 -> V_792 . V_789 ;
return F_35 ( V_14 , V_21 -> V_14 , V_793 ,
V_796 , & V_252 ) ;
}
static int F_369 ( struct V_790 * V_791 , int V_515 )
{
int V_560 ;
int V_238 ;
switch ( V_515 ) {
case V_797 :
case V_798 :
return F_98 ( V_8 , V_799 ) ;
case V_800 :
case V_801 :
V_238 = V_802 | V_796 ;
break;
case V_803 :
V_238 = V_804 ;
break;
case V_805 :
V_238 = V_806 ;
break;
default:
return 0 ;
}
V_560 = F_363 ( & V_791 -> V_792 , V_238 ) ;
return V_560 ;
}
static int F_370 ( struct V_790 * V_791 , struct V_783 * V_699 , int V_795 )
{
struct V_782 * V_21 ;
struct V_784 * V_785 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_791 -> V_792 . V_16 ;
V_785 = V_699 -> V_16 ;
if ( V_785 -> V_14 == V_27 ) {
V_47 = F_87 ( V_14 , V_21 -> V_14 , V_807 ,
NULL , & V_785 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_791 -> V_792 . V_789 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_793 ,
V_808 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_785 -> V_14 , V_807 ,
V_809 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_785 -> V_14 , V_21 -> V_14 , V_793 ,
V_810 , & V_252 ) ;
return V_47 ;
}
static int F_371 ( struct V_790 * V_791 , struct V_783 * V_699 ,
struct V_17 * V_237 ,
long type , int V_151 )
{
struct V_782 * V_21 ;
struct V_784 * V_785 ;
struct V_251 V_252 ;
T_2 V_14 = F_10 ( V_237 ) ;
int V_47 ;
V_21 = V_791 -> V_792 . V_16 ;
V_785 = V_699 -> V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_791 -> V_792 . V_789 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_793 , V_811 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_785 -> V_14 ,
V_807 , V_812 , & V_252 ) ;
return V_47 ;
}
static int F_372 ( struct V_813 * V_814 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_359 ( V_8 , & V_814 -> V_815 , V_816 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_814 -> V_815 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_814 -> V_815 . V_789 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_816 ,
V_817 , & V_252 ) ;
if ( V_47 ) {
F_360 ( & V_814 -> V_815 ) ;
return V_47 ;
}
return 0 ;
}
static void F_373 ( struct V_813 * V_814 )
{
F_360 ( & V_814 -> V_815 ) ;
}
static int F_374 ( struct V_813 * V_814 , int V_818 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_814 -> V_815 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_814 -> V_815 . V_789 ;
return F_35 ( V_14 , V_21 -> V_14 , V_816 ,
V_819 , & V_252 ) ;
}
static int F_375 ( struct V_813 * V_814 , int V_515 )
{
int V_238 ;
int V_560 ;
switch ( V_515 ) {
case V_797 :
case V_820 :
return F_98 ( V_8 , V_799 ) ;
case V_800 :
case V_821 :
V_238 = V_822 | V_819 ;
break;
case V_803 :
V_238 = V_823 ;
break;
case V_824 :
case V_825 :
V_238 = V_826 ;
break;
case V_805 :
V_238 = V_827 ;
break;
default:
return 0 ;
}
V_560 = F_363 ( & V_814 -> V_815 , V_238 ) ;
return V_560 ;
}
static int F_376 ( struct V_813 * V_814 ,
char T_15 * V_828 , int V_818 )
{
T_2 V_238 ;
if ( V_818 & V_829 )
V_238 = V_830 ;
else
V_238 = V_830 | V_831 ;
return F_363 ( & V_814 -> V_815 , V_238 ) ;
}
static int F_377 ( struct V_832 * V_833 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_359 ( V_8 , & V_833 -> V_834 , V_835 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_833 -> V_834 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_833 -> V_834 . V_789 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_835 ,
V_836 , & V_252 ) ;
if ( V_47 ) {
F_360 ( & V_833 -> V_834 ) ;
return V_47 ;
}
return 0 ;
}
static void F_378 ( struct V_832 * V_833 )
{
F_360 ( & V_833 -> V_834 ) ;
}
static int F_379 ( struct V_832 * V_833 , int V_837 )
{
struct V_782 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_833 -> V_834 . V_16 ;
V_252 . type = V_787 ;
V_252 . V_257 . V_788 = V_833 -> V_834 . V_789 ;
return F_35 ( V_14 , V_21 -> V_14 , V_835 ,
V_838 , & V_252 ) ;
}
static int F_380 ( struct V_832 * V_833 , int V_515 )
{
int V_560 ;
T_2 V_238 ;
switch ( V_515 ) {
case V_797 :
case V_839 :
return F_98 ( V_8 , V_799 ) ;
case V_840 :
case V_841 :
case V_842 :
V_238 = V_843 ;
break;
case V_844 :
case V_845 :
V_238 = V_846 ;
break;
case V_847 :
case V_848 :
V_238 = V_849 ;
break;
case V_805 :
V_238 = V_850 ;
break;
case V_803 :
V_238 = V_851 ;
break;
case V_800 :
case V_852 :
V_238 = V_843 | V_838 ;
break;
default:
return 0 ;
}
V_560 = F_363 ( & V_833 -> V_834 , V_238 ) ;
return V_560 ;
}
static int F_381 ( struct V_832 * V_833 ,
struct V_853 * V_854 , unsigned V_855 , int V_856 )
{
T_2 V_238 ;
if ( V_856 )
V_238 = V_846 | V_849 ;
else
V_238 = V_846 ;
return F_363 ( & V_833 -> V_834 , V_238 ) ;
}
static int F_382 ( struct V_781 * V_857 , short V_98 )
{
T_2 V_255 = 0 ;
V_255 = 0 ;
if ( V_98 & V_858 )
V_255 |= V_859 ;
if ( V_98 & V_860 )
V_255 |= V_861 ;
if ( V_255 == 0 )
return 0 ;
return F_363 ( V_857 , V_255 ) ;
}
static void F_383 ( struct V_781 * V_857 , T_2 * V_512 )
{
struct V_782 * V_21 = V_857 -> V_16 ;
* V_512 = V_21 -> V_14 ;
}
static void F_384 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_385 ( struct V_17 * V_127 ,
char * V_64 , char * * V_468 )
{
const struct V_10 * V_754 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_127 ) {
error = F_92 ( V_127 , V_862 ) ;
if ( error )
return error ;
}
F_11 () ;
V_754 = F_12 ( V_127 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_45 ) )
V_14 = V_754 -> V_14 ;
else if ( ! strcmp ( V_64 , L_46 ) )
V_14 = V_754 -> V_13 ;
else if ( ! strcmp ( V_64 , L_47 ) )
V_14 = V_754 -> V_374 ;
else if ( ! strcmp ( V_64 , L_48 ) )
V_14 = V_754 -> V_272 ;
else if ( ! strcmp ( V_64 , L_49 ) )
V_14 = V_754 -> V_372 ;
else if ( ! strcmp ( V_64 , L_50 ) )
V_14 = V_754 -> V_373 ;
else
goto V_863;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_468 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_863:
F_13 () ;
return - V_86 ;
}
static int F_386 ( struct V_17 * V_127 ,
char * V_64 , void * V_468 , T_7 V_499 )
{
struct V_10 * V_11 ;
struct V_17 * V_387 ;
struct V_7 * V_329 ;
T_2 V_14 = 0 , V_389 ;
int error ;
char * V_1 = V_468 ;
if ( V_8 != V_127 ) {
return - V_508 ;
}
if ( ! strcmp ( V_64 , L_47 ) )
error = F_92 ( V_127 , V_864 ) ;
else if ( ! strcmp ( V_64 , L_48 ) )
error = F_92 ( V_127 , V_865 ) ;
else if ( ! strcmp ( V_64 , L_49 ) )
error = F_92 ( V_127 , V_866 ) ;
else if ( ! strcmp ( V_64 , L_50 ) )
error = F_92 ( V_127 , V_867 ) ;
else if ( ! strcmp ( V_64 , L_45 ) )
error = F_92 ( V_127 , V_868 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_499 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_499 - 1 ] == '\n' ) {
V_1 [ V_499 - 1 ] = 0 ;
V_499 -- ;
}
error = F_54 ( V_468 , V_499 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_48 ) ) {
if ( ! F_203 ( V_501 ) ) {
struct V_502 * V_503 ;
T_7 V_504 ;
if ( V_1 [ V_499 - 1 ] == '\0' )
V_504 = V_499 - 1 ;
else
V_504 = V_499 ;
V_503 = F_206 ( V_8 -> V_505 , V_91 , V_506 ) ;
F_207 ( V_503 , L_51 ) ;
F_208 ( V_503 , V_468 , V_504 ) ;
F_209 ( V_503 ) ;
return error ;
}
error = F_210 ( V_468 , V_499 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_329 = F_387 () ;
if ( ! V_329 )
return - V_24 ;
V_11 = V_329 -> V_16 ;
if ( ! strcmp ( V_64 , L_47 ) ) {
V_11 -> V_374 = V_14 ;
} else if ( ! strcmp ( V_64 , L_48 ) ) {
V_11 -> V_272 = V_14 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
error = F_107 ( V_14 , V_127 ) ;
if ( error )
goto V_869;
V_11 -> V_372 = V_14 ;
} else if ( ! strcmp ( V_64 , L_50 ) ) {
V_11 -> V_373 = V_14 ;
} else if ( ! strcmp ( V_64 , L_45 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_869;
error = - V_377 ;
if ( ! F_388 () ) {
error = F_389 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_869;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_241 ,
V_870 , NULL ) ;
if ( error )
goto V_869;
V_389 = 0 ;
F_152 ( V_127 ) ;
V_387 = F_132 ( V_127 ) ;
if ( V_387 )
V_389 = F_10 ( V_387 ) ;
F_154 ( V_127 ) ;
if ( V_387 ) {
error = F_35 ( V_389 , V_14 , V_241 ,
V_323 , NULL ) ;
if ( error )
goto V_869;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_869;
}
F_390 ( V_329 ) ;
return V_499 ;
V_869:
F_391 ( V_329 ) ;
return error ;
}
static int F_392 ( T_2 V_512 , char * * V_452 , T_2 * V_871 )
{
return F_47 ( V_512 , V_452 , V_871 ) ;
}
static int F_393 ( const char * V_452 , T_2 V_871 , T_2 * V_512 )
{
return F_54 ( V_452 , V_871 , V_512 ) ;
}
static void F_394 ( char * V_452 , T_2 V_871 )
{
F_28 ( V_452 ) ;
}
static int F_395 ( struct V_19 * V_19 , void * V_278 , T_2 V_872 )
{
return F_217 ( V_19 , V_471 , V_278 , V_872 , 0 ) ;
}
static int F_396 ( struct V_52 * V_52 , void * V_278 , T_2 V_872 )
{
return F_397 ( V_52 , V_67 , V_278 , V_872 , 0 ) ;
}
static int F_398 ( struct V_19 * V_19 , void * * V_278 , T_2 * V_872 )
{
int V_84 = 0 ;
V_84 = F_216 ( V_19 , V_471 ,
V_278 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_872 = V_84 ;
return 0 ;
}
static int F_399 ( struct V_789 * V_873 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_874 * V_875 ;
V_875 = F_7 ( sizeof( struct V_874 ) , V_12 ) ;
if ( ! V_875 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_372 )
V_875 -> V_14 = V_11 -> V_372 ;
else
V_875 -> V_14 = V_11 -> V_14 ;
V_873 -> V_16 = V_875 ;
return 0 ;
}
static void F_400 ( struct V_789 * V_873 )
{
struct V_874 * V_875 = V_873 -> V_16 ;
V_873 -> V_16 = NULL ;
F_28 ( V_875 ) ;
}
static int F_401 ( T_16 V_876 ,
const struct V_7 * V_7 ,
T_17 V_228 )
{
struct V_789 * V_789 ;
struct V_874 * V_875 ;
T_2 V_14 ;
if ( V_228 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_789 = F_402 ( V_876 ) ;
V_875 = V_789 -> V_16 ;
return F_35 ( V_14 , V_875 -> V_14 , V_279 , V_228 , NULL ) ;
}
static int F_403 ( struct V_789 * V_789 , char * * V_877 )
{
struct V_874 * V_875 = V_789 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_875 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_877 = V_83 ;
return V_47 ;
}
static T_1 int F_404 ( void )
{
if ( ! F_405 ( & V_878 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_879 L_52 ) ;
return 0 ;
}
F_38 ( V_879 L_53 ) ;
F_6 () ;
V_531 = ! ( V_880 & V_546 ) ;
V_22 = F_406 ( L_54 ,
sizeof( struct V_20 ) ,
0 , V_881 , NULL ) ;
F_407 () ;
if ( F_408 ( & V_878 ) )
F_8 ( L_55 ) ;
if ( V_3 )
F_38 ( V_74 L_56 ) ;
else
F_38 ( V_74 L_57 ) ;
return 0 ;
}
static void F_409 ( struct V_41 * V_42 , void * V_882 )
{
F_62 ( V_42 , NULL ) ;
}
void F_410 ( void )
{
F_38 ( V_74 L_58 ) ;
F_38 ( V_74 L_59 ) ;
F_411 ( F_409 , NULL ) ;
}
static int T_1 F_412 ( void )
{
int V_560 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_60 ) ;
V_560 = F_413 ( V_883 , F_39 ( V_883 ) ) ;
if ( V_560 )
F_8 ( L_61 , V_560 ) ;
#if F_271 ( V_645 ) || F_271 ( V_646 )
V_560 = F_413 ( V_884 , F_39 ( V_884 ) ) ;
if ( V_560 )
F_8 ( L_62 , V_560 ) ;
#endif
V_66:
return V_560 ;
}
static void F_414 ( void )
{
F_38 ( V_74 L_63 ) ;
F_415 ( V_883 , F_39 ( V_883 ) ) ;
#if F_271 ( V_645 ) || F_271 ( V_646 )
F_415 ( V_884 , F_39 ( V_884 ) ) ;
#endif
}
int F_416 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_885 ) {
return - V_86 ;
}
F_38 ( V_879 L_64 ) ;
V_885 = 1 ;
V_5 = 0 ;
F_417 () ;
F_418 () ;
F_414 () ;
F_419 () ;
return 0 ;
}
