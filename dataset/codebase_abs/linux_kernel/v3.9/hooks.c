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
struct V_19 * V_19 = F_106 ( V_36 ) ;
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
static int F_107 ( struct V_19 * V_269 ,
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
static int F_108 ( T_2 V_277 ,
struct V_17 * V_278 )
{
T_2 V_14 = F_10 ( V_278 ) ;
return F_35 ( V_14 , V_277 , V_279 , V_280 , NULL ) ;
}
static int F_109 ( struct V_19 * V_269 ,
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
static inline int F_110 ( struct V_19 * V_289 ,
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
V_297 = F_111 ( V_290 -> V_56 -> V_226 ) ;
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
V_298 = F_111 ( V_292 -> V_56 -> V_226 ) ;
V_47 = F_35 ( V_14 , V_296 -> V_14 ,
V_296 -> V_28 ,
( V_298 ? V_288 : V_286 ) , & V_252 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_112 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_238 ,
struct V_251 * V_252 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_238 , V_252 ) ;
}
static inline T_2 F_113 ( int V_151 , int V_301 )
{
T_2 V_255 = 0 ;
if ( ! F_111 ( V_151 ) ) {
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
static inline T_2 F_114 ( struct V_36 * V_36 )
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
static inline T_2 F_115 ( struct V_36 * V_36 )
{
T_2 V_255 = F_114 ( V_36 ) ;
if ( V_318 )
V_255 |= V_319 ;
return V_255 ;
}
static int F_116 ( struct V_17 * V_320 ,
unsigned int V_151 )
{
int V_47 ;
V_47 = F_117 ( V_320 , V_151 ) ;
if ( V_47 )
return V_47 ;
if ( V_151 & V_321 ) {
T_2 V_14 = F_14 () ;
T_2 V_322 = F_10 ( V_320 ) ;
return F_35 ( V_14 , V_322 , V_29 , V_305 , NULL ) ;
}
return F_92 ( V_320 , V_323 ) ;
}
static int F_118 ( struct V_17 * V_324 )
{
int V_47 ;
V_47 = F_119 ( V_324 ) ;
if ( V_47 )
return V_47 ;
return F_91 ( V_324 , V_8 , V_323 ) ;
}
static int F_120 ( struct V_17 * V_237 , T_6 * V_325 ,
T_6 * V_326 , T_6 * V_327 )
{
int error ;
error = F_92 ( V_237 , V_328 ) ;
if ( error )
return error ;
return F_121 ( V_237 , V_325 , V_326 , V_327 ) ;
}
static int F_122 ( struct V_7 * V_329 , const struct V_7 * V_330 ,
const T_6 * V_325 ,
const T_6 * V_326 ,
const T_6 * V_327 )
{
int error ;
error = F_123 ( V_329 , V_330 ,
V_325 , V_326 , V_327 ) ;
if ( error )
return error ;
return F_90 ( V_330 , V_329 , V_331 ) ;
}
static int F_124 ( const struct V_7 * V_7 , struct V_332 * V_333 ,
int V_249 , int V_250 )
{
int V_47 ;
V_47 = F_125 ( V_7 , V_333 , V_249 , V_250 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_7 , V_249 , V_250 ) ;
}
static int F_126 ( int V_334 , int type , int V_335 , struct V_41 * V_42 )
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
V_47 = F_112 ( V_7 , V_42 , V_341 , NULL ) ;
break;
case V_342 :
case V_343 :
case V_344 :
V_47 = F_112 ( V_7 , V_42 , V_345 , NULL ) ;
break;
default:
V_47 = 0 ;
break;
}
return V_47 ;
}
static int F_127 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_346 ) ;
}
static int F_128 ( int type )
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
static int F_129 ( struct V_360 * V_361 , long V_362 )
{
int V_47 , V_363 = 0 ;
V_47 = F_124 ( F_52 () , & V_364 , V_365 ,
V_366 ) ;
if ( V_47 == 0 )
V_363 = 1 ;
return F_130 ( V_361 , V_362 , V_363 ) ;
}
static int F_131 ( struct V_367 * V_368 )
{
const struct V_10 * V_369 ;
struct V_10 * V_370 ;
struct V_20 * V_21 ;
struct V_251 V_252 ;
struct V_19 * V_19 = F_106 ( V_368 -> V_36 ) ;
int V_47 ;
V_47 = F_132 ( V_368 ) ;
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
V_387 = F_133 ( V_8 ) ;
if ( F_134 ( V_387 != NULL ) ) {
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
static int F_135 ( struct V_367 * V_368 )
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
return ( V_392 || F_136 ( V_368 ) ) ;
}
static int F_137 ( const void * V_127 , struct V_36 * V_36 , unsigned V_394 )
{
return F_105 ( V_127 , V_36 , F_114 ( V_36 ) ) ? V_394 + 1 : 0 ;
}
static inline void F_138 ( const struct V_7 * V_7 ,
struct V_395 * V_396 )
{
struct V_36 * V_36 , * V_397 = NULL ;
struct V_398 * V_399 ;
int V_400 = 0 ;
unsigned V_401 ;
V_399 = F_139 () ;
if ( V_399 ) {
F_21 ( & V_402 ) ;
if ( ! F_22 ( & V_399 -> V_403 ) ) {
struct V_404 * V_405 ;
V_405 = F_140 ( & V_399 -> V_403 ,
struct V_404 , V_26 ) ;
V_36 = V_405 -> V_36 ;
if ( F_104 ( V_7 , & V_36 -> V_266 , V_305 | V_309 ) )
V_400 = 1 ;
}
F_24 ( & V_402 ) ;
F_141 ( V_399 ) ;
}
if ( V_400 )
F_142 () ;
V_401 = F_143 ( V_396 , 0 , F_137 , V_7 ) ;
if ( ! V_401 )
return;
V_397 = F_144 ( & V_406 , V_407 , V_7 ) ;
if ( F_75 ( V_397 ) )
V_397 = NULL ;
do {
F_145 ( V_401 - 1 , V_397 , 0 ) ;
} while ( ( V_401 = F_143 ( V_396 , V_401 , F_137 , V_7 ) ) != 0 );
if ( V_397 )
F_146 ( V_397 ) ;
}
static void F_147 ( struct V_367 * V_368 )
{
struct V_10 * V_370 ;
struct V_408 * V_409 , * V_410 ;
int V_47 , V_82 ;
V_370 = V_368 -> V_7 -> V_16 ;
if ( V_370 -> V_14 == V_370 -> V_13 )
return;
F_138 ( V_368 -> V_7 , V_8 -> V_396 ) ;
V_8 -> V_411 = 0 ;
V_47 = F_35 ( V_370 -> V_13 , V_370 -> V_14 , V_241 ,
V_412 , NULL ) ;
if ( V_47 ) {
F_148 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_413 ; V_82 ++ ) {
V_409 = V_8 -> signal -> V_409 + V_82 ;
V_410 = V_414 . signal -> V_409 + V_82 ;
V_409 -> V_415 = F_149 ( V_409 -> V_416 , V_410 -> V_415 ) ;
}
F_150 ( V_8 ) ;
F_151 ( V_8 , V_408 ( V_417 ) ) ;
}
}
static void F_152 ( struct V_367 * V_368 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_418 V_419 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_241 , V_420 , NULL ) ;
if ( V_47 ) {
memset ( & V_419 , 0 , sizeof V_419 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_153 ( V_82 , & V_419 , NULL ) ;
F_154 ( & V_8 -> V_421 -> V_422 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_423 ) ) {
F_155 ( V_8 ) ;
F_156 ( V_8 , 1 ) ;
F_157 ( & V_8 -> V_424 ) ;
}
F_158 ( & V_8 -> V_421 -> V_422 ) ;
}
F_159 ( & V_425 ) ;
F_160 ( V_8 , V_8 -> V_426 ) ;
F_161 ( & V_425 ) ;
}
static int F_162 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_163 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_164 ( char * V_144 , int V_427 , char * V_428 , int V_429 )
{
if ( V_427 > V_429 )
return 0 ;
return ! memcmp ( V_144 , V_428 , V_427 ) ;
}
static inline int F_165 ( char * V_428 , int V_84 )
{
return ( F_164 ( V_146 , sizeof( V_146 ) - 1 , V_428 , V_84 ) ||
F_164 ( V_147 , sizeof( V_147 ) - 1 , V_428 , V_84 ) ||
F_164 ( V_149 , sizeof( V_149 ) - 1 , V_428 , V_84 ) ||
F_164 ( V_148 , sizeof( V_148 ) - 1 , V_428 , V_84 ) ||
F_164 ( V_150 , sizeof( V_150 ) - 1 , V_428 , V_84 ) ) ;
}
static inline void F_166 ( char * * V_430 , char * V_431 , int * V_432 , int V_84 )
{
if ( ! * V_432 ) {
* * V_430 = ',' ;
* V_430 += 1 ;
} else
* V_432 = 0 ;
memcpy ( * V_430 , V_431 , V_84 ) ;
* V_430 += V_84 ;
}
static inline void F_167 ( char * * V_430 , char * V_431 , int * V_432 ,
int V_84 )
{
int V_433 = 0 ;
if ( ! * V_432 ) {
* * V_430 = '|' ;
* V_430 += 1 ;
} else
* V_432 = 0 ;
while ( V_433 < V_84 ) {
if ( * V_431 != '"' ) {
* * V_430 = * V_431 ;
* V_430 += 1 ;
}
V_431 += 1 ;
V_433 += 1 ;
}
}
static int F_168 ( char * V_434 , char * V_435 )
{
int V_436 , V_38 , V_47 = 0 ;
char * V_437 , * V_438 , * V_439 ;
char * V_440 , * V_441 , * V_442 ;
int V_443 = 0 ;
V_438 = V_434 ;
V_440 = V_435 ;
V_442 = ( char * ) F_169 ( V_12 ) ;
if ( ! V_442 ) {
V_47 = - V_24 ;
goto V_66;
}
V_441 = V_442 ;
V_436 = V_38 = 1 ;
V_437 = V_439 = V_434 ;
do {
if ( * V_439 == '"' )
V_443 = ! V_443 ;
if ( ( * V_439 == ',' && V_443 == 0 ) ||
* V_439 == '\0' ) {
int V_84 = V_439 - V_438 ;
if ( F_165 ( V_438 , V_84 ) )
F_167 ( & V_440 , V_438 , & V_38 , V_84 ) ;
else
F_166 ( & V_442 , V_438 , & V_436 , V_84 ) ;
V_438 = V_439 + 1 ;
}
} while ( * V_439 ++ );
strcpy ( V_437 , V_441 ) ;
F_78 ( ( unsigned long ) V_441 ) ;
V_66:
return V_47 ;
}
static int F_170 ( struct V_41 * V_42 , void * V_141 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_444 , * * V_107 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_141 )
return 0 ;
if ( V_42 -> V_63 -> V_109 & V_110 )
return 0 ;
F_45 ( & V_81 ) ;
V_444 = F_171 () ;
if ( ! V_444 )
return - V_24 ;
V_47 = F_168 ( V_141 , V_444 ) ;
if ( V_47 )
goto V_445;
V_47 = F_58 ( V_444 , & V_81 ) ;
if ( V_47 )
goto V_445;
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
goto V_446;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_447;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_447;
break;
case V_97 : {
struct V_20 * V_102 ;
V_102 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 , V_14 ) )
goto V_447;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_447;
break;
default:
goto V_446;
}
}
V_47 = 0 ;
V_446:
F_49 ( & V_81 ) ;
V_445:
F_172 ( V_444 ) ;
return V_47 ;
V_447:
F_38 ( V_61 L_31
L_32 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_446;
}
static int F_173 ( struct V_41 * V_42 , int V_69 , void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
int V_47 ;
V_47 = F_62 ( V_42 , V_141 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_448 )
return 0 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_42 -> V_54 ;
return F_112 ( V_7 , V_42 , V_449 , & V_252 ) ;
}
static int F_174 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_251 V_252 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 -> V_450 -> V_54 ;
return F_112 ( V_7 , V_52 -> V_450 , V_451 , & V_252 ) ;
}
static int F_175 ( const char * V_452 ,
struct V_215 * V_215 ,
const char * type ,
unsigned long V_69 ,
void * V_141 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_453 )
return F_112 ( V_7 , V_215 -> V_52 -> V_450 ,
V_454 , NULL ) ;
else
return F_104 ( V_7 , V_215 , V_455 ) ;
}
static int F_176 ( struct V_456 * V_378 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_112 ( V_7 , V_378 -> V_457 ,
V_458 , NULL ) ;
}
static int F_177 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_178 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_179 ( struct V_19 * V_19 , struct V_19 * V_269 ,
const struct V_459 * V_459 , char * * V_64 ,
void * * V_460 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_270 ;
struct V_31 * V_32 ;
T_2 V_14 , V_271 , V_461 ;
int V_47 ;
char * V_462 = NULL , * V_83 ;
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
V_459 , & V_271 ) ;
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
V_462 = F_180 ( V_463 , V_23 ) ;
if ( ! V_462 )
return - V_24 ;
* V_64 = V_462 ;
}
if ( V_460 && V_84 ) {
V_47 = F_181 ( V_271 , & V_83 , & V_461 ) ;
if ( V_47 ) {
F_28 ( V_462 ) ;
return V_47 ;
}
* V_460 = V_83 ;
* V_84 = V_461 ;
}
return 0 ;
}
static int F_182 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_151 )
{
return F_107 ( V_269 , V_52 , V_29 ) ;
}
static int F_183 ( struct V_52 * V_290 , struct V_19 * V_269 , struct V_52 * V_292 )
{
return F_109 ( V_269 , V_290 , V_283 ) ;
}
static int F_184 ( struct V_19 * V_269 , struct V_52 * V_52 )
{
return F_109 ( V_269 , V_52 , V_285 ) ;
}
static int F_185 ( struct V_19 * V_269 , struct V_52 * V_52 , const char * V_64 )
{
return F_107 ( V_269 , V_52 , V_156 ) ;
}
static int F_186 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_301 )
{
return F_107 ( V_269 , V_52 , V_161 ) ;
}
static int F_187 ( struct V_19 * V_269 , struct V_52 * V_52 )
{
return F_109 ( V_269 , V_52 , V_287 ) ;
}
static int F_188 ( struct V_19 * V_269 , struct V_52 * V_52 , T_5 V_151 , T_8 V_221 )
{
return F_107 ( V_269 , V_52 , F_68 ( V_151 ) ) ;
}
static int F_189 ( struct V_19 * V_464 , struct V_52 * V_290 ,
struct V_19 * V_465 , struct V_52 * V_292 )
{
return F_110 ( V_464 , V_290 , V_465 , V_292 ) ;
}
static int F_190 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_305 ) ;
}
static int F_191 ( struct V_52 * V_52 , struct V_466 * V_466 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_305 ) ;
}
static T_9 int F_192 ( struct V_19 * V_19 ,
T_2 V_238 , T_2 V_467 , T_2 V_468 ,
unsigned V_69 )
{
struct V_251 V_252 ;
struct V_20 * V_21 = V_19 -> V_30 ;
int V_47 ;
V_252 . type = V_469 ;
V_252 . V_257 . V_19 = V_19 ;
V_47 = F_193 ( F_14 () , V_21 -> V_14 , V_21 -> V_28 , V_238 ,
V_467 , V_468 , & V_252 , V_69 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_194 ( struct V_19 * V_19 , int V_301 )
{
const struct V_7 * V_7 = F_52 () ;
T_2 V_238 ;
bool V_470 ;
unsigned V_69 = V_301 & V_471 ;
struct V_20 * V_21 ;
T_2 V_14 ;
struct V_253 V_254 ;
int V_47 , V_261 ;
T_2 V_467 , V_468 ;
V_470 = V_301 & V_472 ;
V_301 &= ( V_304 | V_308 | V_302 | V_306 ) ;
if ( ! V_301 )
return 0 ;
F_100 ( V_7 ) ;
if ( F_101 ( F_42 ( V_19 ) ) )
return 0 ;
V_238 = F_113 ( V_19 -> V_226 , V_301 ) ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
V_47 = F_96 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , 0 , & V_254 ) ;
V_467 = F_195 ( V_238 , & V_254 , V_47 ,
V_470 ? V_473 : 0 ,
& V_468 ) ;
if ( F_134 ( ! V_467 ) )
return V_47 ;
V_261 = F_192 ( V_19 , V_238 , V_467 , V_468 , V_69 ) ;
if ( V_261 )
return V_261 ;
return V_47 ;
}
static int F_196 ( struct V_52 * V_52 , struct V_474 * V_474 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_475 = V_474 -> V_475 ;
T_10 V_255 = V_309 ;
if ( V_475 & V_476 ) {
V_475 &= ~ ( V_477 | V_478 | V_479 |
V_476 ) ;
if ( ! V_475 )
return 0 ;
}
if ( V_475 & ( V_479 | V_480 | V_481 |
V_482 | V_483 | V_484 ) )
return F_103 ( V_7 , V_52 , V_485 ) ;
if ( V_318 && ( V_475 & V_486 ) )
V_255 |= V_319 ;
return F_103 ( V_7 , V_52 , V_255 ) ;
}
static int F_197 ( struct V_456 * V_378 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_215 V_215 ;
V_215 . V_52 = V_52 ;
V_215 . V_378 = V_378 ;
return F_104 ( V_7 , & V_215 , V_487 ) ;
}
static int F_198 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_488 ,
sizeof V_488 - 1 ) ) {
if ( ! strcmp ( V_64 , V_489 ) ) {
if ( ! F_199 ( V_490 ) )
return - V_377 ;
} else if ( ! F_199 ( V_365 ) ) {
return - V_377 ;
}
}
return F_103 ( V_7 , V_52 , V_485 ) ;
}
static int F_200 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_460 , T_7 V_491 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_251 V_252 ;
T_2 V_271 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_198 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_201 ( V_19 ) )
return - V_377 ;
V_252 . type = V_264 ;
V_252 . V_257 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_492 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_460 , V_491 , & V_271 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_199 ( V_493 ) ) {
struct V_494 * V_495 ;
T_7 V_496 ;
const char * V_1 ;
if ( V_460 ) {
V_1 = V_460 ;
if ( V_1 [ V_491 - 1 ] == '\0' )
V_496 = V_491 - 1 ;
else
V_496 = V_491 ;
} else {
V_1 = L_36 ;
V_496 = 0 ;
}
V_495 = F_202 ( V_8 -> V_497 , V_91 , V_498 ) ;
F_203 ( V_495 , L_37 ) ;
F_204 ( V_495 , V_460 , V_496 ) ;
F_205 ( V_495 ) ;
return V_47 ;
}
V_47 = F_206 ( V_460 , V_491 , & V_271 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_271 , V_21 -> V_28 ,
V_499 , & V_252 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_207 ( V_21 -> V_14 , V_271 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_271 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_252 ) ;
}
static void F_208 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_460 , T_7 V_491 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_271 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_206 ( V_460 , V_491 , & V_271 ) ;
if ( V_47 ) {
F_38 ( V_73 L_38
L_39 ,
V_19 -> V_33 -> V_62 , V_19 -> V_220 , - V_47 ) ;
return;
}
V_21 -> V_14 = V_271 ;
return;
}
static int F_209 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_487 ) ;
}
static int F_210 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_487 ) ;
}
static int F_211 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_198 ( V_52 , V_64 ) ;
return - V_500 ;
}
static int F_212 ( const struct V_19 * V_19 , const char * V_64 , void * * V_214 , bool V_501 )
{
T_2 V_491 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_463 ) )
return - V_65 ;
error = F_124 ( F_52 () , & V_364 , V_493 ,
V_366 ) ;
if ( ! error )
error = F_181 ( V_21 -> V_14 , & V_83 ,
& V_491 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_491 ) ;
if ( error )
return error ;
error = V_491 ;
if ( V_501 ) {
* V_214 = V_83 ;
goto V_502;
}
F_28 ( V_83 ) ;
V_502:
return error ;
}
static int F_213 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_460 , T_7 V_491 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_271 ;
int V_47 ;
if ( strcmp ( V_64 , V_463 ) )
return - V_65 ;
if ( ! V_460 || ! V_491 )
return - V_500 ;
V_47 = F_54 ( ( void * ) V_460 , V_491 , & V_271 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_14 = V_271 ;
V_21 -> V_114 = 1 ;
return 0 ;
}
static int F_214 ( struct V_19 * V_19 , char * V_214 , T_7 V_503 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_214 && V_84 <= V_503 )
memcpy ( V_214 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_215 ( const struct V_19 * V_19 , T_2 * V_504 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_504 = V_21 -> V_14 ;
}
static int F_216 ( struct V_36 * V_36 , int V_301 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = F_106 ( V_36 ) ;
if ( ( V_36 -> V_315 & V_316 ) && ( V_301 & V_308 ) )
V_301 |= V_306 ;
return F_105 ( V_7 , V_36 ,
F_113 ( V_19 -> V_226 , V_301 ) ) ;
}
static int F_217 ( struct V_36 * V_36 , int V_301 )
{
struct V_19 * V_19 = F_106 ( V_36 ) ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_301 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_505 == V_21 -> V_14 &&
V_38 -> V_506 == F_218 () )
return 0 ;
return F_216 ( V_36 , V_301 ) ;
}
static int F_219 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_220 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_221 ( struct V_36 * V_36 , unsigned int V_507 ,
unsigned long V_508 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_507 ) {
case V_509 :
case V_510 :
case V_511 :
case V_512 :
case V_513 :
error = F_105 ( V_7 , V_36 , V_487 ) ;
break;
case V_514 :
case V_515 :
error = F_105 ( V_7 , V_36 , V_485 ) ;
break;
case V_516 :
case V_517 :
error = F_105 ( V_7 , V_36 , 0 ) ;
break;
case V_518 :
case V_519 :
error = F_93 ( V_7 , V_520 ,
V_260 ) ;
break;
default:
error = F_105 ( V_7 , V_36 , V_317 ) ;
}
return error ;
}
static int F_222 ( struct V_36 * V_36 , unsigned long V_521 , int V_522 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_523 &&
( V_521 & V_524 ) && ( ! V_36 || ( ! V_522 && ( V_521 & V_525 ) ) ) ) {
V_47 = F_90 ( V_7 , V_7 , V_526 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_255 = V_305 ;
if ( V_522 && ( V_521 & V_525 ) )
V_255 |= V_309 ;
if ( V_521 & V_524 )
V_255 |= V_303 ;
return F_105 ( V_7 , V_36 , V_255 ) ;
}
error:
return V_47 ;
}
static int F_223 ( unsigned long V_527 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_527 < V_528 ) {
V_47 = F_35 ( V_14 , V_14 , V_529 ,
V_530 , NULL ) ;
if ( V_47 )
return V_47 ;
}
return F_224 ( V_527 ) ;
}
static int F_225 ( struct V_36 * V_36 , unsigned long V_531 ,
unsigned long V_521 , unsigned long V_69 )
{
if ( V_532 )
V_521 = V_531 ;
return F_222 ( V_36 , V_521 ,
( V_69 & V_533 ) == V_534 ) ;
}
static int F_226 ( struct V_535 * V_536 ,
unsigned long V_531 ,
unsigned long V_521 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_532 )
V_521 = V_531 ;
if ( V_523 &&
( V_521 & V_524 ) && ! ( V_536 -> V_537 & V_538 ) ) {
int V_47 = 0 ;
if ( V_536 -> V_539 >= V_536 -> V_540 -> V_541 &&
V_536 -> V_542 <= V_536 -> V_540 -> V_543 ) {
V_47 = F_90 ( V_7 , V_7 , V_544 ) ;
} else if ( ! V_536 -> V_545 &&
V_536 -> V_539 <= V_536 -> V_540 -> V_546 &&
V_536 -> V_542 >= V_536 -> V_540 -> V_546 ) {
V_47 = F_92 ( V_8 , V_547 ) ;
} else if ( V_536 -> V_545 && V_536 -> V_548 ) {
V_47 = F_105 ( V_7 , V_536 -> V_545 , V_549 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_222 ( V_536 -> V_545 , V_521 , V_536 -> V_537 & V_550 ) ;
}
static int F_227 ( struct V_36 * V_36 , unsigned int V_507 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_36 , V_551 ) ;
}
static int F_228 ( struct V_36 * V_36 , unsigned int V_507 ,
unsigned long V_508 )
{
const struct V_7 * V_7 = F_52 () ;
int V_552 = 0 ;
switch ( V_507 ) {
case V_553 :
if ( ( V_36 -> V_315 & V_316 ) && ! ( V_508 & V_316 ) ) {
V_552 = F_105 ( V_7 , V_36 , V_309 ) ;
break;
}
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
V_552 = F_105 ( V_7 , V_36 , 0 ) ;
break;
case V_560 :
case V_561 :
case V_562 :
#if V_563 == 32
case V_564 :
case V_565 :
case V_566 :
#endif
V_552 = F_105 ( V_7 , V_36 , V_551 ) ;
break;
}
return V_552 ;
}
static int F_229 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_230 ( struct V_17 * V_248 ,
struct V_567 * V_568 , int V_569 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_248 ) ;
T_2 V_228 ;
struct V_37 * V_38 ;
V_36 = F_231 ( V_568 , struct V_36 , V_570 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_569 )
V_228 = F_89 ( V_571 ) ;
else
V_228 = F_89 ( V_569 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_241 , V_228 , NULL ) ;
}
static int F_232 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_105 ( V_7 , V_36 , F_114 ( V_36 ) ) ;
}
static int F_233 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_20 * V_21 ;
V_38 = V_36 -> V_40 ;
V_21 = F_106 ( V_36 ) -> V_30 ;
V_38 -> V_505 = V_21 -> V_14 ;
V_38 -> V_506 = F_218 () ;
return F_104 ( V_7 , & V_36 -> V_266 , F_115 ( V_36 ) ) ;
}
static int F_234 ( unsigned long V_572 )
{
return F_92 ( V_8 , V_573 ) ;
}
static int F_235 ( struct V_7 * V_7 , T_11 V_574 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_574 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_236 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_216 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_237 ( struct V_7 * V_329 , const struct V_7 * V_330 ,
T_11 V_574 )
{
const struct V_10 * V_369 ;
struct V_10 * V_11 ;
V_369 = V_330 -> V_16 ;
V_11 = F_238 ( V_369 , sizeof( struct V_10 ) , V_574 ) ;
if ( ! V_11 )
return - V_24 ;
V_329 -> V_16 = V_11 ;
return 0 ;
}
static void F_239 ( struct V_7 * V_329 , const struct V_7 * V_330 )
{
const struct V_10 * V_369 = V_330 -> V_16 ;
struct V_10 * V_11 = V_329 -> V_16 ;
* V_11 = * V_369 ;
}
static int F_240 ( struct V_7 * V_329 , T_2 V_504 )
{
struct V_10 * V_11 = V_329 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_575 ;
V_575 = F_35 ( V_14 , V_504 ,
V_576 ,
V_577 ,
NULL ) ;
if ( V_575 == 0 ) {
V_11 -> V_14 = V_504 ;
V_11 -> V_272 = 0 ;
V_11 -> V_372 = 0 ;
V_11 -> V_373 = 0 ;
}
return V_575 ;
}
static int F_241 ( struct V_7 * V_329 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_329 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_575 ;
V_575 = F_35 ( V_14 , V_21 -> V_14 ,
V_576 ,
V_578 ,
NULL ) ;
if ( V_575 == 0 )
V_11 -> V_272 = V_21 -> V_14 ;
return V_575 ;
}
static int F_242 ( char * V_579 )
{
T_2 V_14 ;
struct V_251 V_252 ;
V_14 = F_10 ( V_8 ) ;
V_252 . type = V_580 ;
V_252 . V_257 . V_579 = V_579 ;
return F_35 ( V_14 , V_15 , V_262 ,
V_581 , & V_252 ) ;
}
static int F_243 ( struct V_17 * V_127 , T_12 V_582 )
{
return F_92 ( V_127 , V_583 ) ;
}
static int F_244 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_584 ) ;
}
static int F_245 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_585 ) ;
}
static void F_246 ( struct V_17 * V_127 , T_2 * V_504 )
{
* V_504 = F_10 ( V_127 ) ;
}
static int F_247 ( struct V_17 * V_127 , int V_586 )
{
int V_47 ;
V_47 = F_248 ( V_127 , V_586 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_587 ) ;
}
static int F_249 ( struct V_17 * V_127 , int V_588 )
{
int V_47 ;
V_47 = F_250 ( V_127 , V_588 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_587 ) ;
}
static int F_251 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_589 ) ;
}
static int F_252 ( struct V_17 * V_127 , unsigned int V_590 ,
struct V_408 * V_591 )
{
struct V_408 * V_592 = V_127 -> signal -> V_409 + V_590 ;
if ( V_592 -> V_416 != V_591 -> V_416 )
return F_92 ( V_127 , V_593 ) ;
return 0 ;
}
static int F_253 ( struct V_17 * V_127 )
{
int V_47 ;
V_47 = F_254 ( V_127 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_127 , V_587 ) ;
}
static int F_255 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_589 ) ;
}
static int F_256 ( struct V_17 * V_127 )
{
return F_92 ( V_127 , V_587 ) ;
}
static int F_257 ( struct V_17 * V_127 , struct V_594 * V_595 ,
int V_227 , T_2 V_504 )
{
T_2 V_228 ;
int V_47 ;
if ( ! V_227 )
V_228 = V_596 ;
else
V_228 = F_89 ( V_227 ) ;
if ( V_504 )
V_47 = F_35 ( V_504 , F_10 ( V_127 ) ,
V_241 , V_228 , NULL ) ;
else
V_47 = F_92 ( V_127 , V_228 ) ;
return V_47 ;
}
static int F_258 ( struct V_17 * V_127 )
{
return F_91 ( V_127 , V_8 , V_230 ) ;
}
static void F_259 ( struct V_17 * V_127 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_127 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_114 = 1 ;
}
static int F_260 ( struct V_597 * V_598 ,
struct V_251 * V_252 , T_13 * V_599 )
{
int V_600 , V_601 , V_575 = - V_86 ;
struct V_602 V_603 , * V_604 ;
V_600 = F_261 ( V_598 ) ;
V_604 = F_262 ( V_598 , V_600 , sizeof( V_603 ) , & V_603 ) ;
if ( V_604 == NULL )
goto V_66;
V_601 = V_604 -> V_605 * 4 ;
if ( V_601 < sizeof( V_603 ) )
goto V_66;
V_252 -> V_257 . V_606 -> V_607 . V_608 = V_604 -> V_608 ;
V_252 -> V_257 . V_606 -> V_607 . V_609 = V_604 -> V_609 ;
V_575 = 0 ;
if ( V_599 )
* V_599 = V_604 -> V_166 ;
switch ( V_604 -> V_166 ) {
case V_168 : {
struct V_610 V_611 , * V_612 ;
if ( F_263 ( V_604 -> V_613 ) & V_614 )
break;
V_600 += V_601 ;
V_612 = F_262 ( V_598 , V_600 , sizeof( V_611 ) , & V_611 ) ;
if ( V_612 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_612 -> V_616 ;
V_252 -> V_257 . V_606 -> V_617 = V_612 -> V_618 ;
break;
}
case V_169 : {
struct V_619 V_620 , * V_621 ;
if ( F_263 ( V_604 -> V_613 ) & V_614 )
break;
V_600 += V_601 ;
V_621 = F_262 ( V_598 , V_600 , sizeof( V_620 ) , & V_620 ) ;
if ( V_621 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_621 -> V_616 ;
V_252 -> V_257 . V_606 -> V_617 = V_621 -> V_618 ;
break;
}
case V_622 : {
struct V_623 V_624 , * V_625 ;
if ( F_263 ( V_604 -> V_613 ) & V_614 )
break;
V_600 += V_601 ;
V_625 = F_262 ( V_598 , V_600 , sizeof( V_624 ) , & V_624 ) ;
if ( V_625 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_625 -> V_626 ;
V_252 -> V_257 . V_606 -> V_617 = V_625 -> V_627 ;
break;
}
default:
break;
}
V_66:
return V_575 ;
}
static int F_264 ( struct V_597 * V_598 ,
struct V_251 * V_252 , T_13 * V_599 )
{
T_13 V_628 ;
int V_575 = - V_86 , V_600 ;
struct V_629 V_630 , * V_631 ;
T_14 V_613 ;
V_600 = F_261 ( V_598 ) ;
V_631 = F_262 ( V_598 , V_600 , sizeof( V_630 ) , & V_630 ) ;
if ( V_631 == NULL )
goto V_66;
V_252 -> V_257 . V_606 -> V_632 . V_608 = V_631 -> V_608 ;
V_252 -> V_257 . V_606 -> V_632 . V_609 = V_631 -> V_609 ;
V_575 = 0 ;
V_628 = V_631 -> V_628 ;
V_600 += sizeof( V_630 ) ;
V_600 = F_265 ( V_598 , V_600 , & V_628 , & V_613 ) ;
if ( V_600 < 0 )
goto V_66;
if ( V_599 )
* V_599 = V_628 ;
switch ( V_628 ) {
case V_168 : {
struct V_610 V_611 , * V_612 ;
V_612 = F_262 ( V_598 , V_600 , sizeof( V_611 ) , & V_611 ) ;
if ( V_612 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_612 -> V_616 ;
V_252 -> V_257 . V_606 -> V_617 = V_612 -> V_618 ;
break;
}
case V_169 : {
struct V_619 V_620 , * V_621 ;
V_621 = F_262 ( V_598 , V_600 , sizeof( V_620 ) , & V_620 ) ;
if ( V_621 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_621 -> V_616 ;
V_252 -> V_257 . V_606 -> V_617 = V_621 -> V_618 ;
break;
}
case V_622 : {
struct V_623 V_624 , * V_625 ;
V_625 = F_262 ( V_598 , V_600 , sizeof( V_624 ) , & V_624 ) ;
if ( V_625 == NULL )
break;
V_252 -> V_257 . V_606 -> V_615 = V_625 -> V_626 ;
V_252 -> V_257 . V_606 -> V_617 = V_625 -> V_627 ;
break;
}
default:
break;
}
V_66:
return V_575 ;
}
static int F_266 ( struct V_597 * V_598 , struct V_251 * V_252 ,
char * * V_633 , int V_634 , T_13 * V_599 )
{
char * V_635 ;
int V_575 ;
switch ( V_252 -> V_257 . V_606 -> V_170 ) {
case V_177 :
V_575 = F_260 ( V_598 , V_252 , V_599 ) ;
if ( V_575 )
goto V_636;
V_635 = ( char * ) ( V_634 ? & V_252 -> V_257 . V_606 -> V_607 . V_608 :
& V_252 -> V_257 . V_606 -> V_607 . V_609 ) ;
goto V_637;
#if F_267 ( V_638 ) || F_267 ( V_639 )
case V_178 :
V_575 = F_264 ( V_598 , V_252 , V_599 ) ;
if ( V_575 )
goto V_636;
V_635 = ( char * ) ( V_634 ? & V_252 -> V_257 . V_606 -> V_632 . V_608 :
& V_252 -> V_257 . V_606 -> V_632 . V_609 ) ;
goto V_637;
#endif
default:
V_635 = NULL ;
goto V_637;
}
V_636:
F_38 ( V_61
L_40
L_41 ) ;
return V_575 ;
V_637:
if ( V_633 )
* V_633 = V_635 ;
return 0 ;
}
static int F_268 ( struct V_597 * V_598 , T_4 V_170 , T_2 * V_14 )
{
int V_552 ;
T_2 V_640 ;
T_2 V_641 ;
T_2 V_642 ;
F_269 ( V_598 , & V_640 ) ;
F_270 ( V_598 , V_170 , & V_642 , & V_641 ) ;
V_552 = F_271 ( V_641 , V_642 , V_640 , V_14 ) ;
if ( F_101 ( V_552 ) ) {
F_38 ( V_61
L_42
L_43 ) ;
return - V_500 ;
}
return 0 ;
}
static int F_272 ( const struct V_10 * V_11 ,
T_4 V_643 , T_2 * V_644 )
{
if ( V_11 -> V_373 > V_645 ) {
* V_644 = V_11 -> V_373 ;
return 0 ;
}
return F_87 ( V_11 -> V_14 , V_11 -> V_14 , V_643 , NULL ,
V_644 ) ;
}
static int F_273 ( struct V_17 * V_18 , struct V_646 * V_647 , T_2 V_238 )
{
struct V_648 * V_649 = V_647 -> V_650 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
T_2 V_240 = F_10 ( V_18 ) ;
if ( V_649 -> V_14 == V_15 )
return 0 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_647 = V_647 ;
return F_35 ( V_240 , V_649 -> V_14 , V_649 -> V_28 , V_238 , & V_252 ) ;
}
static int F_274 ( int V_170 , int type ,
int V_166 , int V_653 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_271 ;
T_4 V_643 ;
int V_47 ;
if ( V_653 )
return 0 ;
V_643 = F_71 ( V_170 , type , V_166 ) ;
V_47 = F_272 ( V_11 , V_643 , & V_271 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_271 , V_643 , V_654 , NULL ) ;
}
static int F_275 ( struct V_655 * V_646 , int V_170 ,
int type , int V_166 , int V_653 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_276 ( V_646 ) -> V_30 ;
struct V_648 * V_649 ;
int V_552 = 0 ;
V_21 -> V_28 = F_71 ( V_170 , type , V_166 ) ;
if ( V_653 )
V_21 -> V_14 = V_15 ;
else {
V_552 = F_272 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_552 )
return V_552 ;
}
V_21 -> V_114 = 1 ;
if ( V_646 -> V_647 ) {
V_649 = V_646 -> V_647 -> V_650 ;
V_649 -> V_14 = V_21 -> V_14 ;
V_649 -> V_28 = V_21 -> V_28 ;
V_552 = F_277 ( V_646 -> V_647 , V_170 ) ;
}
return V_552 ;
}
static int F_278 ( struct V_655 * V_646 , struct V_656 * V_657 , int V_658 )
{
struct V_646 * V_647 = V_646 -> V_647 ;
T_4 V_170 ;
int V_552 ;
V_552 = F_273 ( V_8 , V_647 , V_659 ) ;
if ( V_552 )
goto V_66;
V_170 = V_647 -> V_660 ;
if ( V_170 == V_177 || V_170 == V_178 ) {
char * V_635 ;
struct V_648 * V_649 = V_647 -> V_650 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
struct V_661 * V_662 = NULL ;
struct V_663 * V_664 = NULL ;
unsigned short V_665 ;
T_2 V_14 , V_666 ;
if ( V_170 == V_177 ) {
V_662 = (struct V_661 * ) V_657 ;
V_665 = F_263 ( V_662 -> V_667 ) ;
V_635 = ( char * ) & V_662 -> V_668 . V_669 ;
} else {
V_664 = (struct V_663 * ) V_657 ;
V_665 = F_263 ( V_664 -> V_670 ) ;
V_635 = ( char * ) & V_664 -> V_671 . V_672 ;
}
if ( V_665 ) {
int V_673 , V_674 ;
F_279 ( & V_673 , & V_674 ) ;
if ( V_665 < V_675 ( V_676, V_673 ) || V_665 > V_674 ) {
V_552 = F_280 ( V_647 -> V_677 ,
V_665 , & V_14 ) ;
if ( V_552 )
goto V_66;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_615 = F_281 ( V_665 ) ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
V_552 = F_35 ( V_649 -> V_14 , V_14 ,
V_649 -> V_28 ,
V_678 , & V_252 ) ;
if ( V_552 )
goto V_66;
}
}
switch ( V_649 -> V_28 ) {
case V_179 :
V_666 = V_679 ;
break;
case V_181 :
V_666 = V_680 ;
break;
case V_183 :
V_666 = V_681 ;
break;
default:
V_666 = V_682 ;
break;
}
V_552 = F_282 ( V_635 , V_170 , & V_14 ) ;
if ( V_552 )
goto V_66;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_615 = F_281 ( V_665 ) ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
if ( V_170 == V_177 )
V_252 . V_257 . V_606 -> V_607 . V_608 = V_662 -> V_668 . V_669 ;
else
V_252 . V_257 . V_606 -> V_632 . V_608 = V_664 -> V_671 ;
V_552 = F_35 ( V_649 -> V_14 , V_14 ,
V_649 -> V_28 , V_666 , & V_252 ) ;
if ( V_552 )
goto V_66;
}
V_66:
return V_552 ;
}
static int F_283 ( struct V_655 * V_646 , struct V_656 * V_657 , int V_658 )
{
struct V_646 * V_647 = V_646 -> V_647 ;
struct V_648 * V_649 = V_647 -> V_650 ;
int V_552 ;
V_552 = F_273 ( V_8 , V_647 , V_683 ) ;
if ( V_552 )
return V_552 ;
if ( V_649 -> V_28 == V_179 ||
V_649 -> V_28 == V_183 ) {
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
struct V_661 * V_662 = NULL ;
struct V_663 * V_664 = NULL ;
unsigned short V_665 ;
T_2 V_14 , V_228 ;
if ( V_647 -> V_660 == V_177 ) {
V_662 = (struct V_661 * ) V_657 ;
if ( V_658 < sizeof( struct V_661 ) )
return - V_86 ;
V_665 = F_263 ( V_662 -> V_667 ) ;
} else {
V_664 = (struct V_663 * ) V_657 ;
if ( V_658 < V_684 )
return - V_86 ;
V_665 = F_263 ( V_664 -> V_670 ) ;
}
V_552 = F_280 ( V_647 -> V_677 , V_665 , & V_14 ) ;
if ( V_552 )
goto V_66;
V_228 = ( V_649 -> V_28 == V_179 ) ?
V_685 : V_686 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_617 = F_281 ( V_665 ) ;
V_252 . V_257 . V_606 -> V_170 = V_647 -> V_660 ;
V_552 = F_35 ( V_649 -> V_14 , V_14 , V_649 -> V_28 , V_228 , & V_252 ) ;
if ( V_552 )
goto V_66;
}
V_552 = F_284 ( V_647 , V_657 ) ;
V_66:
return V_552 ;
}
static int F_285 ( struct V_655 * V_646 , int V_687 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_688 ) ;
}
static int F_286 ( struct V_655 * V_646 , struct V_655 * V_689 )
{
int V_552 ;
struct V_20 * V_21 ;
struct V_20 * V_123 ;
V_552 = F_273 ( V_8 , V_646 -> V_647 , V_690 ) ;
if ( V_552 )
return V_552 ;
V_123 = F_276 ( V_689 ) -> V_30 ;
V_21 = F_276 ( V_646 ) -> V_30 ;
V_123 -> V_28 = V_21 -> V_28 ;
V_123 -> V_14 = V_21 -> V_14 ;
V_123 -> V_114 = 1 ;
return 0 ;
}
static int F_287 ( struct V_655 * V_646 , struct V_691 * V_692 ,
int V_491 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_693 ) ;
}
static int F_288 ( struct V_655 * V_646 , struct V_691 * V_692 ,
int V_491 , int V_69 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_694 ) ;
}
static int F_289 ( struct V_655 * V_646 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_695 ) ;
}
static int F_290 ( struct V_655 * V_646 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_695 ) ;
}
static int F_291 ( struct V_655 * V_646 , int V_696 , int V_697 )
{
int V_552 ;
V_552 = F_273 ( V_8 , V_646 -> V_647 , V_698 ) ;
if ( V_552 )
return V_552 ;
return F_292 ( V_646 , V_696 , V_697 ) ;
}
static int F_293 ( struct V_655 * V_646 , int V_696 ,
int V_697 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_699 ) ;
}
static int F_294 ( struct V_655 * V_646 , int V_700 )
{
return F_273 ( V_8 , V_646 -> V_647 , V_701 ) ;
}
static int F_295 ( struct V_646 * V_646 ,
struct V_646 * V_702 ,
struct V_646 * V_703 )
{
struct V_648 * V_704 = V_646 -> V_650 ;
struct V_648 * V_705 = V_702 -> V_650 ;
struct V_648 * V_706 = V_703 -> V_650 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
int V_552 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_647 = V_702 ;
V_552 = F_35 ( V_704 -> V_14 , V_705 -> V_14 ,
V_705 -> V_28 ,
V_707 , & V_252 ) ;
if ( V_552 )
return V_552 ;
V_706 -> V_708 = V_704 -> V_14 ;
V_552 = F_296 ( V_705 -> V_14 , V_704 -> V_14 ,
& V_706 -> V_14 ) ;
if ( V_552 )
return V_552 ;
V_704 -> V_708 = V_706 -> V_14 ;
return 0 ;
}
static int F_297 ( struct V_655 * V_646 ,
struct V_655 * V_702 )
{
struct V_648 * V_709 = V_646 -> V_647 -> V_650 ;
struct V_648 * V_710 = V_702 -> V_647 -> V_650 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_647 = V_702 -> V_647 ;
return F_35 ( V_709 -> V_14 , V_710 -> V_14 , V_710 -> V_28 , V_711 ,
& V_252 ) ;
}
static int F_298 ( int V_712 , char * V_635 , T_4 V_170 ,
T_2 V_708 ,
struct V_251 * V_252 )
{
int V_552 ;
T_2 V_713 ;
T_2 V_714 ;
V_552 = F_299 ( V_712 , & V_713 ) ;
if ( V_552 )
return V_552 ;
V_552 = F_35 ( V_708 , V_713 ,
V_715 , V_716 , V_252 ) ;
if ( V_552 )
return V_552 ;
V_552 = F_282 ( V_635 , V_170 , & V_714 ) ;
if ( V_552 )
return V_552 ;
return F_35 ( V_708 , V_714 ,
V_717 , V_718 , V_252 ) ;
}
static int F_300 ( struct V_646 * V_647 , struct V_597 * V_598 ,
T_4 V_170 )
{
int V_552 = 0 ;
struct V_648 * V_649 = V_647 -> V_650 ;
T_2 V_719 = V_649 -> V_14 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
char * V_635 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_720 = V_598 -> V_721 ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
V_552 = F_266 ( V_598 , & V_252 , & V_635 , 1 , NULL ) ;
if ( V_552 )
return V_552 ;
if ( F_4 () ) {
V_552 = F_35 ( V_719 , V_598 -> V_722 , V_723 ,
V_724 , & V_252 ) ;
if ( V_552 )
return V_552 ;
}
V_552 = F_301 ( V_649 , V_598 , V_170 , & V_252 ) ;
if ( V_552 )
return V_552 ;
V_552 = F_302 ( V_649 -> V_14 , V_598 , & V_252 ) ;
return V_552 ;
}
static int F_303 ( struct V_646 * V_647 , struct V_597 * V_598 )
{
int V_552 ;
struct V_648 * V_649 = V_647 -> V_650 ;
T_4 V_170 = V_647 -> V_660 ;
T_2 V_719 = V_649 -> V_14 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
char * V_635 ;
T_13 V_725 ;
T_13 V_726 ;
if ( V_170 != V_177 && V_170 != V_178 )
return 0 ;
if ( V_170 == V_178 && V_598 -> V_166 == F_281 ( V_727 ) )
V_170 = V_177 ;
if ( ! V_728 )
return F_300 ( V_647 , V_598 , V_170 ) ;
V_725 = F_4 () ;
V_726 = F_304 () || F_305 () ;
if ( ! V_725 && ! V_726 )
return 0 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_720 = V_598 -> V_721 ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
V_552 = F_266 ( V_598 , & V_252 , & V_635 , 1 , NULL ) ;
if ( V_552 )
return V_552 ;
if ( V_726 ) {
T_2 V_708 ;
V_552 = F_268 ( V_598 , V_170 , & V_708 ) ;
if ( V_552 )
return V_552 ;
V_552 = F_298 ( V_598 -> V_721 , V_635 , V_170 ,
V_708 , & V_252 ) ;
if ( V_552 ) {
F_306 ( V_598 , V_552 , 0 ) ;
return V_552 ;
}
V_552 = F_35 ( V_719 , V_708 , V_729 ,
V_730 , & V_252 ) ;
if ( V_552 )
F_306 ( V_598 , V_552 , 0 ) ;
}
if ( V_725 ) {
V_552 = F_35 ( V_719 , V_598 -> V_722 , V_723 ,
V_724 , & V_252 ) ;
if ( V_552 )
return V_552 ;
}
return V_552 ;
}
static int F_307 ( struct V_655 * V_646 , char T_15 * V_731 ,
int T_15 * V_732 , unsigned V_84 )
{
int V_552 = 0 ;
char * V_733 ;
T_2 V_734 ;
struct V_648 * V_649 = V_646 -> V_647 -> V_650 ;
T_2 V_708 = V_645 ;
if ( V_649 -> V_28 == V_174 ||
V_649 -> V_28 == V_179 )
V_708 = V_649 -> V_708 ;
if ( V_708 == V_645 )
return - V_735 ;
V_552 = F_47 ( V_708 , & V_733 , & V_734 ) ;
if ( V_552 )
return V_552 ;
if ( V_734 > V_84 ) {
V_552 = - V_219 ;
goto V_736;
}
if ( F_308 ( V_731 , V_733 , V_734 ) )
V_552 = - V_737 ;
V_736:
if ( F_309 ( V_734 , V_732 ) )
V_552 = - V_737 ;
F_28 ( V_733 ) ;
return V_552 ;
}
static int F_310 ( struct V_655 * V_646 , struct V_597 * V_598 , T_2 * V_504 )
{
T_2 V_738 = V_645 ;
T_4 V_170 ;
if ( V_598 && V_598 -> V_166 == F_281 ( V_727 ) )
V_170 = V_177 ;
else if ( V_598 && V_598 -> V_166 == F_281 ( V_739 ) )
V_170 = V_178 ;
else if ( V_646 )
V_170 = V_646 -> V_647 -> V_660 ;
else
goto V_66;
if ( V_646 && V_170 == V_171 )
F_215 ( F_276 ( V_646 ) , & V_738 ) ;
else if ( V_598 )
F_268 ( V_598 , V_170 , & V_738 ) ;
V_66:
* V_504 = V_738 ;
if ( V_738 == V_645 )
return - V_86 ;
return 0 ;
}
static int F_311 ( struct V_646 * V_647 , int V_170 , T_11 V_740 )
{
struct V_648 * V_649 ;
V_649 = F_7 ( sizeof( * V_649 ) , V_740 ) ;
if ( ! V_649 )
return - V_24 ;
V_649 -> V_708 = V_27 ;
V_649 -> V_14 = V_27 ;
F_312 ( V_649 ) ;
V_647 -> V_650 = V_649 ;
return 0 ;
}
static void F_313 ( struct V_646 * V_647 )
{
struct V_648 * V_649 = V_647 -> V_650 ;
V_647 -> V_650 = NULL ;
F_314 ( V_649 ) ;
F_28 ( V_649 ) ;
}
static void F_315 ( const struct V_646 * V_647 , struct V_646 * V_703 )
{
struct V_648 * V_649 = V_647 -> V_650 ;
struct V_648 * V_741 = V_703 -> V_650 ;
V_741 -> V_14 = V_649 -> V_14 ;
V_741 -> V_708 = V_649 -> V_708 ;
V_741 -> V_28 = V_649 -> V_28 ;
F_312 ( V_741 ) ;
}
static void F_316 ( struct V_646 * V_647 , T_2 * V_504 )
{
if ( ! V_647 )
* V_504 = V_742 ;
else {
struct V_648 * V_649 = V_647 -> V_650 ;
* V_504 = V_649 -> V_14 ;
}
}
static void F_317 ( struct V_646 * V_647 , struct V_655 * V_324 )
{
struct V_20 * V_21 = F_276 ( V_324 ) -> V_30 ;
struct V_648 * V_649 = V_647 -> V_650 ;
if ( V_647 -> V_660 == V_177 || V_647 -> V_660 == V_178 ||
V_647 -> V_660 == V_171 )
V_21 -> V_14 = V_649 -> V_14 ;
V_649 -> V_28 = V_21 -> V_28 ;
}
static int F_318 ( struct V_646 * V_647 , struct V_597 * V_598 ,
struct V_743 * V_744 )
{
struct V_648 * V_649 = V_647 -> V_650 ;
int V_552 ;
T_4 V_170 = V_647 -> V_660 ;
T_2 V_271 ;
T_2 V_745 ;
if ( V_170 == V_178 && V_598 -> V_166 == F_281 ( V_727 ) )
V_170 = V_177 ;
V_552 = F_268 ( V_598 , V_170 , & V_745 ) ;
if ( V_552 )
return V_552 ;
if ( V_745 == V_645 ) {
V_744 -> V_504 = V_649 -> V_14 ;
V_744 -> V_738 = V_645 ;
} else {
V_552 = F_296 ( V_649 -> V_14 , V_745 , & V_271 ) ;
if ( V_552 )
return V_552 ;
V_744 -> V_504 = V_271 ;
V_744 -> V_738 = V_745 ;
}
return F_319 ( V_744 , V_170 ) ;
}
static void F_320 ( struct V_646 * V_703 ,
const struct V_743 * V_744 )
{
struct V_648 * V_741 = V_703 -> V_650 ;
V_741 -> V_14 = V_744 -> V_504 ;
V_741 -> V_708 = V_744 -> V_738 ;
F_321 ( V_703 , V_744 -> V_746 -> V_170 ) ;
}
static void F_322 ( struct V_646 * V_647 , struct V_597 * V_598 )
{
T_4 V_170 = V_647 -> V_660 ;
struct V_648 * V_649 = V_647 -> V_650 ;
if ( V_170 == V_178 && V_598 -> V_166 == F_281 ( V_727 ) )
V_170 = V_177 ;
F_268 ( V_598 , V_170 , & V_649 -> V_708 ) ;
}
static void F_323 ( struct V_597 * V_598 , struct V_646 * V_647 )
{
F_324 ( V_598 , V_647 ) ;
}
static int F_325 ( T_2 V_14 )
{
const struct V_10 * V_747 ;
T_2 V_240 ;
V_747 = F_15 () ;
V_240 = V_747 -> V_14 ;
return F_35 ( V_240 , V_14 , V_723 , V_748 , NULL ) ;
}
static void F_326 ( void )
{
F_327 ( & V_6 ) ;
}
static void F_328 ( void )
{
F_329 ( & V_6 ) ;
}
static void F_330 ( const struct V_743 * V_744 ,
struct V_749 * V_750 )
{
V_750 -> V_751 = V_744 -> V_504 ;
}
static int F_331 ( void * * V_16 )
{
struct V_752 * V_753 ;
V_753 = F_7 ( sizeof( * V_753 ) , V_12 ) ;
if ( ! V_753 )
return - V_24 ;
V_753 -> V_14 = F_14 () ;
* V_16 = V_753 ;
return 0 ;
}
static void F_332 ( void * V_16 )
{
F_28 ( V_16 ) ;
}
static int F_333 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_754 , V_755 ,
NULL ) ;
}
static int F_334 ( void * V_16 )
{
struct V_752 * V_753 = V_16 ;
return F_35 ( F_14 () , V_753 -> V_14 , V_754 ,
V_756 , NULL ) ;
}
static int F_335 ( struct V_646 * V_647 , void * V_16 )
{
struct V_752 * V_753 = V_16 ;
struct V_648 * V_649 = V_647 -> V_650 ;
V_649 -> V_14 = V_753 -> V_14 ;
V_649 -> V_28 = V_754 ;
return 0 ;
}
static int F_336 ( void * V_16 )
{
struct V_752 * V_753 = V_16 ;
T_2 V_14 = F_14 () ;
int V_552 ;
V_552 = F_35 ( V_14 , V_753 -> V_14 , V_754 ,
V_757 , NULL ) ;
if ( V_552 )
return V_552 ;
V_552 = F_35 ( V_14 , V_14 , V_754 ,
V_758 , NULL ) ;
if ( V_552 )
return V_552 ;
V_753 -> V_14 = V_14 ;
return 0 ;
}
static int F_337 ( struct V_646 * V_647 , struct V_597 * V_598 )
{
int V_552 = 0 ;
T_2 V_228 ;
struct V_759 * V_760 ;
struct V_648 * V_649 = V_647 -> V_650 ;
if ( V_598 -> V_84 < F_338 ( 0 ) ) {
V_552 = - V_86 ;
goto V_66;
}
V_760 = F_339 ( V_598 ) ;
V_552 = F_340 ( V_649 -> V_28 , V_760 -> V_761 , & V_228 ) ;
if ( V_552 ) {
if ( V_552 == - V_86 ) {
F_341 ( V_8 -> V_497 , V_12 , V_498 ,
L_44
L_45 ,
V_760 -> V_761 , V_649 -> V_28 ) ;
if ( ! V_3 || F_342 () )
V_552 = 0 ;
}
if ( V_552 == - V_762 )
V_552 = 0 ;
goto V_66;
}
V_552 = F_273 ( V_8 , V_647 , V_228 ) ;
V_66:
return V_552 ;
}
static unsigned int F_343 ( struct V_597 * V_598 , int V_712 ,
T_4 V_170 )
{
int V_552 ;
char * V_635 ;
T_2 V_708 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
T_13 V_725 ;
T_13 V_763 ;
T_13 V_726 ;
if ( ! V_728 )
return V_764 ;
V_725 = F_4 () ;
V_763 = F_304 () ;
V_726 = V_763 || F_305 () ;
if ( ! V_725 && ! V_726 )
return V_764 ;
if ( F_268 ( V_598 , V_170 , & V_708 ) != 0 )
return V_765 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_720 = V_712 ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
if ( F_266 ( V_598 , & V_252 , & V_635 , 1 , NULL ) != 0 )
return V_765 ;
if ( V_726 ) {
V_552 = F_298 ( V_712 , V_635 , V_170 ,
V_708 , & V_252 ) ;
if ( V_552 ) {
F_306 ( V_598 , V_552 , 1 ) ;
return V_765 ;
}
}
if ( V_725 )
if ( F_35 ( V_708 , V_598 -> V_722 ,
V_723 , V_766 , & V_252 ) )
return V_765 ;
if ( V_763 )
if ( F_344 ( V_598 , V_170 , V_708 ) != 0 )
return V_765 ;
return V_764 ;
}
static unsigned int F_345 ( unsigned int V_767 ,
struct V_597 * V_598 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_346)( struct V_597 * ) )
{
return F_343 ( V_598 , V_769 -> V_712 , V_177 ) ;
}
static unsigned int F_347 ( unsigned int V_767 ,
struct V_597 * V_598 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_346)( struct V_597 * ) )
{
return F_343 ( V_598 , V_769 -> V_712 , V_178 ) ;
}
static unsigned int F_348 ( struct V_597 * V_598 ,
T_4 V_170 )
{
T_2 V_14 ;
if ( ! F_304 () )
return V_764 ;
if ( V_598 -> V_647 ) {
struct V_648 * V_649 = V_598 -> V_647 -> V_650 ;
V_14 = V_649 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_344 ( V_598 , V_170 , V_14 ) != 0 )
return V_765 ;
return V_764 ;
}
static unsigned int F_349 ( unsigned int V_767 ,
struct V_597 * V_598 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_346)( struct V_597 * ) )
{
return F_348 ( V_598 , V_177 ) ;
}
static unsigned int F_350 ( struct V_597 * V_598 ,
int V_712 ,
T_4 V_170 )
{
struct V_646 * V_647 = V_598 -> V_647 ;
struct V_648 * V_649 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
char * V_635 ;
T_13 V_599 ;
if ( V_647 == NULL )
return V_764 ;
V_649 = V_647 -> V_650 ;
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_720 = V_712 ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
if ( F_266 ( V_598 , & V_252 , & V_635 , 0 , & V_599 ) )
return V_765 ;
if ( F_4 () )
if ( F_35 ( V_649 -> V_14 , V_598 -> V_722 ,
V_723 , V_770 , & V_252 ) )
return F_351 ( - V_771 ) ;
if ( F_352 ( V_649 -> V_14 , V_598 , & V_252 , V_599 ) )
return F_351 ( - V_771 ) ;
return V_764 ;
}
static unsigned int F_353 ( struct V_597 * V_598 , int V_712 ,
T_4 V_170 )
{
T_2 V_772 ;
T_2 V_708 ;
struct V_646 * V_647 ;
struct V_251 V_252 ;
struct V_651 V_606 = { 0 ,} ;
char * V_635 ;
T_13 V_725 ;
T_13 V_726 ;
if ( ! V_728 )
return F_350 ( V_598 , V_712 , V_170 ) ;
#ifdef F_354
if ( F_355 ( V_598 ) != NULL && F_355 ( V_598 ) -> V_773 != NULL )
return V_764 ;
#endif
V_725 = F_4 () ;
V_726 = F_304 () || F_305 () ;
if ( ! V_725 && ! V_726 )
return V_764 ;
V_647 = V_598 -> V_647 ;
if ( V_647 == NULL ) {
if ( V_598 -> V_721 ) {
V_772 = V_774 ;
if ( F_268 ( V_598 , V_170 , & V_708 ) )
return V_765 ;
} else {
V_772 = V_770 ;
V_708 = V_15 ;
}
} else {
struct V_648 * V_649 = V_647 -> V_650 ;
V_708 = V_649 -> V_14 ;
V_772 = V_770 ;
}
V_252 . type = V_652 ;
V_252 . V_257 . V_606 = & V_606 ;
V_252 . V_257 . V_606 -> V_720 = V_712 ;
V_252 . V_257 . V_606 -> V_170 = V_170 ;
if ( F_266 ( V_598 , & V_252 , & V_635 , 0 , NULL ) )
return V_765 ;
if ( V_725 )
if ( F_35 ( V_708 , V_598 -> V_722 ,
V_723 , V_772 , & V_252 ) )
return F_351 ( - V_771 ) ;
if ( V_726 ) {
T_2 V_713 ;
T_2 V_714 ;
if ( F_299 ( V_712 , & V_713 ) )
return V_765 ;
if ( F_35 ( V_708 , V_713 ,
V_715 , V_775 , & V_252 ) )
return F_351 ( - V_771 ) ;
if ( F_282 ( V_635 , V_170 , & V_714 ) )
return V_765 ;
if ( F_35 ( V_708 , V_714 ,
V_717 , V_776 , & V_252 ) )
return F_351 ( - V_771 ) ;
}
return V_764 ;
}
static unsigned int F_356 ( unsigned int V_767 ,
struct V_597 * V_598 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_346)( struct V_597 * ) )
{
return F_353 ( V_598 , V_66 -> V_712 , V_177 ) ;
}
static unsigned int F_357 ( unsigned int V_767 ,
struct V_597 * V_598 ,
const struct V_768 * V_769 ,
const struct V_768 * V_66 ,
int (* F_346)( struct V_597 * ) )
{
return F_353 ( V_598 , V_66 -> V_712 , V_178 ) ;
}
static int F_358 ( struct V_646 * V_647 , struct V_597 * V_598 )
{
int V_552 ;
V_552 = F_359 ( V_647 , V_598 ) ;
if ( V_552 )
return V_552 ;
return F_337 ( V_647 , V_598 ) ;
}
static int F_360 ( struct V_17 * V_18 ,
struct V_777 * V_228 ,
T_4 V_28 )
{
struct V_778 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_778 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_228 -> V_16 = V_21 ;
return 0 ;
}
static void F_361 ( struct V_777 * V_228 )
{
struct V_778 * V_21 = V_228 -> V_16 ;
V_228 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_362 ( struct V_779 * V_692 )
{
struct V_780 * V_781 ;
V_781 = F_7 ( sizeof( struct V_780 ) , V_12 ) ;
if ( ! V_781 )
return - V_24 ;
V_781 -> V_14 = V_27 ;
V_692 -> V_16 = V_781 ;
return 0 ;
}
static void F_363 ( struct V_779 * V_692 )
{
struct V_780 * V_781 = V_692 -> V_16 ;
V_692 -> V_16 = NULL ;
F_28 ( V_781 ) ;
}
static int F_364 ( struct V_777 * V_782 ,
T_2 V_238 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_782 -> V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_782 -> V_785 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_238 , & V_252 ) ;
}
static int F_365 ( struct V_779 * V_692 )
{
return F_362 ( V_692 ) ;
}
static void F_366 ( struct V_779 * V_692 )
{
F_363 ( V_692 ) ;
}
static int F_367 ( struct V_786 * V_787 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_787 -> V_788 , V_789 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_787 -> V_788 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_787 -> V_788 . V_785 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_789 ,
V_790 , & V_252 ) ;
if ( V_47 ) {
F_361 ( & V_787 -> V_788 ) ;
return V_47 ;
}
return 0 ;
}
static void F_368 ( struct V_786 * V_787 )
{
F_361 ( & V_787 -> V_788 ) ;
}
static int F_369 ( struct V_786 * V_787 , int V_791 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_787 -> V_788 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_787 -> V_788 . V_785 ;
return F_35 ( V_14 , V_21 -> V_14 , V_789 ,
V_792 , & V_252 ) ;
}
static int F_370 ( struct V_786 * V_787 , int V_507 )
{
int V_552 ;
int V_238 ;
switch ( V_507 ) {
case V_793 :
case V_794 :
return F_98 ( V_8 , V_795 ) ;
case V_796 :
case V_797 :
V_238 = V_798 | V_792 ;
break;
case V_799 :
V_238 = V_800 ;
break;
case V_801 :
V_238 = V_802 ;
break;
default:
return 0 ;
}
V_552 = F_364 ( & V_787 -> V_788 , V_238 ) ;
return V_552 ;
}
static int F_371 ( struct V_786 * V_787 , struct V_779 * V_692 , int V_791 )
{
struct V_778 * V_21 ;
struct V_780 * V_781 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_787 -> V_788 . V_16 ;
V_781 = V_692 -> V_16 ;
if ( V_781 -> V_14 == V_27 ) {
V_47 = F_87 ( V_14 , V_21 -> V_14 , V_803 ,
NULL , & V_781 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_787 -> V_788 . V_785 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_789 ,
V_804 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_781 -> V_14 , V_803 ,
V_805 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_781 -> V_14 , V_21 -> V_14 , V_789 ,
V_806 , & V_252 ) ;
return V_47 ;
}
static int F_372 ( struct V_786 * V_787 , struct V_779 * V_692 ,
struct V_17 * V_237 ,
long type , int V_151 )
{
struct V_778 * V_21 ;
struct V_780 * V_781 ;
struct V_251 V_252 ;
T_2 V_14 = F_10 ( V_237 ) ;
int V_47 ;
V_21 = V_787 -> V_788 . V_16 ;
V_781 = V_692 -> V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_787 -> V_788 . V_785 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_789 , V_807 , & V_252 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_781 -> V_14 ,
V_803 , V_808 , & V_252 ) ;
return V_47 ;
}
static int F_373 ( struct V_809 * V_810 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_810 -> V_811 , V_812 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_810 -> V_811 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_810 -> V_811 . V_785 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_812 ,
V_813 , & V_252 ) ;
if ( V_47 ) {
F_361 ( & V_810 -> V_811 ) ;
return V_47 ;
}
return 0 ;
}
static void F_374 ( struct V_809 * V_810 )
{
F_361 ( & V_810 -> V_811 ) ;
}
static int F_375 ( struct V_809 * V_810 , int V_814 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_810 -> V_811 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_810 -> V_811 . V_785 ;
return F_35 ( V_14 , V_21 -> V_14 , V_812 ,
V_815 , & V_252 ) ;
}
static int F_376 ( struct V_809 * V_810 , int V_507 )
{
int V_238 ;
int V_552 ;
switch ( V_507 ) {
case V_793 :
case V_816 :
return F_98 ( V_8 , V_795 ) ;
case V_796 :
case V_817 :
V_238 = V_818 | V_815 ;
break;
case V_799 :
V_238 = V_819 ;
break;
case V_820 :
case V_821 :
V_238 = V_822 ;
break;
case V_801 :
V_238 = V_823 ;
break;
default:
return 0 ;
}
V_552 = F_364 ( & V_810 -> V_811 , V_238 ) ;
return V_552 ;
}
static int F_377 ( struct V_809 * V_810 ,
char T_15 * V_824 , int V_814 )
{
T_2 V_238 ;
if ( V_814 & V_825 )
V_238 = V_826 ;
else
V_238 = V_826 | V_827 ;
return F_364 ( & V_810 -> V_811 , V_238 ) ;
}
static int F_378 ( struct V_828 * V_829 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_829 -> V_830 , V_831 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_829 -> V_830 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_829 -> V_830 . V_785 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_831 ,
V_832 , & V_252 ) ;
if ( V_47 ) {
F_361 ( & V_829 -> V_830 ) ;
return V_47 ;
}
return 0 ;
}
static void F_379 ( struct V_828 * V_829 )
{
F_361 ( & V_829 -> V_830 ) ;
}
static int F_380 ( struct V_828 * V_829 , int V_833 )
{
struct V_778 * V_21 ;
struct V_251 V_252 ;
T_2 V_14 = F_14 () ;
V_21 = V_829 -> V_830 . V_16 ;
V_252 . type = V_783 ;
V_252 . V_257 . V_784 = V_829 -> V_830 . V_785 ;
return F_35 ( V_14 , V_21 -> V_14 , V_831 ,
V_834 , & V_252 ) ;
}
static int F_381 ( struct V_828 * V_829 , int V_507 )
{
int V_552 ;
T_2 V_238 ;
switch ( V_507 ) {
case V_793 :
case V_835 :
return F_98 ( V_8 , V_795 ) ;
case V_836 :
case V_837 :
case V_838 :
V_238 = V_839 ;
break;
case V_840 :
case V_841 :
V_238 = V_842 ;
break;
case V_843 :
case V_844 :
V_238 = V_845 ;
break;
case V_801 :
V_238 = V_846 ;
break;
case V_799 :
V_238 = V_847 ;
break;
case V_796 :
case V_848 :
V_238 = V_839 | V_834 ;
break;
default:
return 0 ;
}
V_552 = F_364 ( & V_829 -> V_830 , V_238 ) ;
return V_552 ;
}
static int F_382 ( struct V_828 * V_829 ,
struct V_849 * V_850 , unsigned V_851 , int V_852 )
{
T_2 V_238 ;
if ( V_852 )
V_238 = V_842 | V_845 ;
else
V_238 = V_842 ;
return F_364 ( & V_829 -> V_830 , V_238 ) ;
}
static int F_383 ( struct V_777 * V_853 , short V_98 )
{
T_2 V_255 = 0 ;
V_255 = 0 ;
if ( V_98 & V_854 )
V_255 |= V_855 ;
if ( V_98 & V_856 )
V_255 |= V_857 ;
if ( V_255 == 0 )
return 0 ;
return F_364 ( V_853 , V_255 ) ;
}
static void F_384 ( struct V_777 * V_853 , T_2 * V_504 )
{
struct V_778 * V_21 = V_853 -> V_16 ;
* V_504 = V_21 -> V_14 ;
}
static void F_385 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_386 ( struct V_17 * V_127 ,
char * V_64 , char * * V_460 )
{
const struct V_10 * V_747 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_127 ) {
error = F_92 ( V_127 , V_858 ) ;
if ( error )
return error ;
}
F_11 () ;
V_747 = F_12 ( V_127 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_46 ) )
V_14 = V_747 -> V_14 ;
else if ( ! strcmp ( V_64 , L_47 ) )
V_14 = V_747 -> V_13 ;
else if ( ! strcmp ( V_64 , L_48 ) )
V_14 = V_747 -> V_374 ;
else if ( ! strcmp ( V_64 , L_49 ) )
V_14 = V_747 -> V_272 ;
else if ( ! strcmp ( V_64 , L_50 ) )
V_14 = V_747 -> V_372 ;
else if ( ! strcmp ( V_64 , L_51 ) )
V_14 = V_747 -> V_373 ;
else
goto V_859;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_460 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_859:
F_13 () ;
return - V_86 ;
}
static int F_387 ( struct V_17 * V_127 ,
char * V_64 , void * V_460 , T_7 V_491 )
{
struct V_10 * V_11 ;
struct V_17 * V_387 ;
struct V_7 * V_329 ;
T_2 V_14 = 0 , V_389 ;
int error ;
char * V_1 = V_460 ;
if ( V_8 != V_127 ) {
return - V_500 ;
}
if ( ! strcmp ( V_64 , L_48 ) )
error = F_92 ( V_127 , V_860 ) ;
else if ( ! strcmp ( V_64 , L_49 ) )
error = F_92 ( V_127 , V_861 ) ;
else if ( ! strcmp ( V_64 , L_50 ) )
error = F_92 ( V_127 , V_862 ) ;
else if ( ! strcmp ( V_64 , L_51 ) )
error = F_92 ( V_127 , V_863 ) ;
else if ( ! strcmp ( V_64 , L_46 ) )
error = F_92 ( V_127 , V_864 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_491 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_491 - 1 ] == '\n' ) {
V_1 [ V_491 - 1 ] = 0 ;
V_491 -- ;
}
error = F_54 ( V_460 , V_491 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_49 ) ) {
if ( ! F_199 ( V_493 ) ) {
struct V_494 * V_495 ;
T_7 V_496 ;
if ( V_1 [ V_491 - 1 ] == '\0' )
V_496 = V_491 - 1 ;
else
V_496 = V_491 ;
V_495 = F_202 ( V_8 -> V_497 , V_91 , V_498 ) ;
F_203 ( V_495 , L_52 ) ;
F_204 ( V_495 , V_460 , V_496 ) ;
F_205 ( V_495 ) ;
return error ;
}
error = F_206 ( V_460 , V_491 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_329 = F_388 () ;
if ( ! V_329 )
return - V_24 ;
V_11 = V_329 -> V_16 ;
if ( ! strcmp ( V_64 , L_48 ) ) {
V_11 -> V_374 = V_14 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
V_11 -> V_272 = V_14 ;
} else if ( ! strcmp ( V_64 , L_50 ) ) {
error = F_108 ( V_14 , V_127 ) ;
if ( error )
goto V_865;
V_11 -> V_372 = V_14 ;
} else if ( ! strcmp ( V_64 , L_51 ) ) {
V_11 -> V_373 = V_14 ;
} else if ( ! strcmp ( V_64 , L_46 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_865;
error = - V_377 ;
if ( ! F_389 () ) {
error = F_390 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_865;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_241 ,
V_866 , NULL ) ;
if ( error )
goto V_865;
V_389 = 0 ;
F_148 ( V_127 ) ;
V_387 = F_133 ( V_127 ) ;
if ( V_387 )
V_389 = F_10 ( V_387 ) ;
F_150 ( V_127 ) ;
if ( V_387 ) {
error = F_35 ( V_389 , V_14 , V_241 ,
V_323 , NULL ) ;
if ( error )
goto V_865;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_865;
}
F_391 ( V_329 ) ;
return V_491 ;
V_865:
F_392 ( V_329 ) ;
return error ;
}
static int F_393 ( T_2 V_504 , char * * V_444 , T_2 * V_867 )
{
return F_47 ( V_504 , V_444 , V_867 ) ;
}
static int F_394 ( const char * V_444 , T_2 V_867 , T_2 * V_504 )
{
return F_54 ( V_444 , V_867 , V_504 ) ;
}
static void F_395 ( char * V_444 , T_2 V_867 )
{
F_28 ( V_444 ) ;
}
static int F_396 ( struct V_19 * V_19 , void * V_278 , T_2 V_868 )
{
return F_213 ( V_19 , V_463 , V_278 , V_868 , 0 ) ;
}
static int F_397 ( struct V_52 * V_52 , void * V_278 , T_2 V_868 )
{
return F_398 ( V_52 , V_67 , V_278 , V_868 , 0 ) ;
}
static int F_399 ( struct V_19 * V_19 , void * * V_278 , T_2 * V_868 )
{
int V_84 = 0 ;
V_84 = F_212 ( V_19 , V_463 ,
V_278 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_868 = V_84 ;
return 0 ;
}
static int F_400 ( struct V_785 * V_869 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_870 * V_871 ;
V_871 = F_7 ( sizeof( struct V_870 ) , V_12 ) ;
if ( ! V_871 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_372 )
V_871 -> V_14 = V_11 -> V_372 ;
else
V_871 -> V_14 = V_11 -> V_14 ;
V_869 -> V_16 = V_871 ;
return 0 ;
}
static void F_401 ( struct V_785 * V_869 )
{
struct V_870 * V_871 = V_869 -> V_16 ;
V_869 -> V_16 = NULL ;
F_28 ( V_871 ) ;
}
static int F_402 ( T_16 V_872 ,
const struct V_7 * V_7 ,
T_17 V_228 )
{
struct V_785 * V_785 ;
struct V_870 * V_871 ;
T_2 V_14 ;
if ( V_228 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_785 = F_403 ( V_872 ) ;
V_871 = V_785 -> V_16 ;
return F_35 ( V_14 , V_871 -> V_14 , V_279 , V_228 , NULL ) ;
}
static int F_404 ( struct V_785 * V_785 , char * * V_873 )
{
struct V_870 * V_871 = V_785 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_871 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_873 = V_83 ;
return V_47 ;
}
static T_1 int F_405 ( void )
{
if ( ! F_406 ( & V_874 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_875 L_53 ) ;
return 0 ;
}
F_38 ( V_875 L_54 ) ;
F_6 () ;
V_523 = ! ( V_876 & V_538 ) ;
V_22 = F_407 ( L_55 ,
sizeof( struct V_20 ) ,
0 , V_877 , NULL ) ;
F_408 () ;
if ( F_409 ( & V_874 ) )
F_8 ( L_56 ) ;
if ( V_3 )
F_38 ( V_74 L_57 ) ;
else
F_38 ( V_74 L_58 ) ;
return 0 ;
}
static void F_410 ( struct V_41 * V_42 , void * V_878 )
{
F_62 ( V_42 , NULL ) ;
}
void F_411 ( void )
{
F_38 ( V_74 L_59 ) ;
F_38 ( V_74 L_60 ) ;
F_412 ( F_410 , NULL ) ;
}
static int T_1 F_413 ( void )
{
int V_552 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_61 ) ;
V_552 = F_414 ( V_879 , F_39 ( V_879 ) ) ;
if ( V_552 )
F_8 ( L_62 , V_552 ) ;
#if F_267 ( V_638 ) || F_267 ( V_639 )
V_552 = F_414 ( V_880 , F_39 ( V_880 ) ) ;
if ( V_552 )
F_8 ( L_63 , V_552 ) ;
#endif
V_66:
return V_552 ;
}
static void F_415 ( void )
{
F_38 ( V_74 L_64 ) ;
F_416 ( V_879 , F_39 ( V_879 ) ) ;
#if F_267 ( V_638 ) || F_267 ( V_639 )
F_416 ( V_880 , F_39 ( V_880 ) ) ;
#endif
}
int F_417 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_881 ) {
return - V_86 ;
}
F_38 ( V_875 L_65 ) ;
V_881 = 1 ;
V_5 = 0 ;
F_418 () ;
F_419 () ;
F_415 () ;
F_420 () ;
return 0 ;
}
