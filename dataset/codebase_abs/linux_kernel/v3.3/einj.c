static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , F_3 ( V_3 ) ,
F_4 ( V_4 ) , V_4 -> V_5 ) ;
}
static int F_5 ( T_1 * type )
{
struct V_1 V_2 ;
int V_6 ;
F_1 ( & V_2 ) ;
V_6 = F_6 ( & V_2 , V_7 ) ;
if ( V_6 )
return V_6 ;
* type = F_7 ( & V_2 ) ;
return 0 ;
}
static int F_8 ( T_1 * type )
{
int V_6 ;
F_9 ( & V_8 ) ;
V_6 = F_5 ( type ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_11 ( T_2 * V_9 )
{
if ( ( V_10 ) * V_9 < V_11 ) {
F_12 (FW_WARN EINJ_PFX
L_1 ) ;
return 1 ;
}
* V_9 -= V_11 ;
F_13 ( V_11 ) ;
F_14 () ;
return 0 ;
}
static void F_15 ( T_2 V_12 ,
struct V_13 * V_14 )
{
int V_15 = V_14 -> V_16 ;
struct V_17 * V_18 ;
T_1 V_19 ;
if ( ! V_15 )
return;
V_18 = F_16 ( V_12 + V_15 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return;
V_19 = V_18 -> V_20 ;
sprintf ( V_21 , L_2 ,
V_19 >> 24 , ( V_19 >> 16 ) & 0xff ,
( V_19 >> 11 ) & 0x1f , ( V_19 >> 8 ) & 0x7 ,
V_18 -> V_22 , V_18 -> V_23 , V_18 -> V_24 ) ;
F_17 ( V_18 , sizeof( * V_18 ) ) ;
}
static void * F_18 ( void )
{
int V_25 ;
T_2 V_26 = 0 , V_27 = 0 ;
struct V_28 * V_29 ;
V_29 = F_4 ( V_4 ) ;
for ( V_25 = 0 ; V_25 < V_4 -> V_5 ; V_25 ++ ) {
if ( V_29 -> V_30 == V_31 &&
V_29 -> V_32 == V_33 &&
V_29 -> V_34 . V_35 ==
V_36 )
memcpy ( & V_26 , & V_29 -> V_34 . V_37 ,
sizeof( V_26 ) ) ;
if ( V_29 -> V_30 == V_38 &&
V_29 -> V_32 == V_33 &&
V_29 -> V_34 . V_35 ==
V_36 )
memcpy ( & V_27 , & V_29 -> V_34 . V_37 ,
sizeof( V_27 ) ) ;
V_29 ++ ;
}
if ( V_27 ) {
struct V_13 * V_14 ;
V_14 = F_16 ( V_27 , sizeof( * V_14 ) ) ;
if ( V_14 ) {
V_39 = 1 ;
F_15 ( V_27 , V_14 ) ;
return V_14 ;
}
}
if ( V_26 ) {
struct V_40 * V_41 ;
V_41 = F_16 ( V_26 , sizeof( * V_41 ) ) ;
if ( ! V_41 )
return NULL ;
if ( V_41 -> V_42 || V_41 -> V_43 ) {
F_17 ( V_41 , sizeof( * V_41 ) ) ;
return NULL ;
}
return V_41 ;
}
return NULL ;
}
static int F_19 ( struct V_44 * V_45 )
{
if ( V_45 -> V_46 != sizeof( struct V_44 ) )
return - V_47 ;
if ( V_45 -> V_48 > V_49 ||
V_45 -> V_48 < V_45 -> V_46 )
return - V_47 ;
if ( V_45 -> V_50 !=
( V_45 -> V_48 - V_45 -> V_46 ) /
sizeof( struct V_51 ) )
return - V_47 ;
return 0 ;
}
static struct V_52 * F_20 (
struct V_44 * V_45 , T_2 V_53 , T_2 V_54 )
{
int V_25 ;
struct V_28 * V_29 ;
V_29 = (struct V_28 * )
( ( char * ) V_45 + sizeof( struct V_44 ) ) ;
for ( V_25 = 0 ; V_25 < V_45 -> V_50 ; V_25 ++ ) {
if ( V_29 -> V_30 == V_55 &&
V_29 -> V_32 == V_56 &&
V_29 -> V_34 . V_35 ==
V_36 &&
( V_29 -> V_34 . V_37 & V_54 ) == ( V_53 & V_54 ) )
return & V_29 -> V_34 ;
V_29 ++ ;
}
return NULL ;
}
static int F_21 ( T_2 V_57 , T_1 type ,
T_2 V_53 , T_2 V_54 )
{
struct V_44 * V_45 = NULL ;
struct V_1 V_58 ;
struct V_59 V_60 ;
struct V_28 * V_61 ;
struct V_62 * V_63 ;
T_1 V_48 ;
int V_6 = - V_64 ;
struct V_52 * V_65 = NULL ;
V_63 = F_22 ( V_57 , sizeof( * V_45 ) ,
L_3 ) ;
if ( ! V_63 ) {
F_23 ( V_66
L_4 ,
( unsigned long long ) V_57 ,
( unsigned long long ) V_57 +
sizeof( * V_45 ) - 1 ) ;
goto V_67;
}
V_45 = F_24 ( V_57 , sizeof( * V_45 ) ) ;
if ( ! V_45 ) {
F_23 ( V_66 L_5 ) ;
goto V_68;
}
V_6 = F_19 ( V_45 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX
L_6 ) ;
goto V_68;
}
if ( ! V_45 -> V_50 )
goto V_68;
V_6 = - V_64 ;
V_48 = V_45 -> V_48 ;
V_63 = F_22 ( V_57 + sizeof( * V_45 ) ,
V_48 - sizeof( * V_45 ) ,
L_3 ) ;
if ( ! V_63 ) {
F_23 ( V_66
L_7 ,
( unsigned long long ) V_57 + sizeof( * V_45 ) ,
( unsigned long long ) V_57 + V_48 - 1 ) ;
goto V_68;
}
F_25 ( V_45 ) ;
V_45 = F_24 ( V_57 , V_48 ) ;
if ( ! V_45 ) {
F_23 ( V_66 L_5 ) ;
goto V_69;
}
V_61 = (struct V_28 * )
( ( char * ) V_45 + sizeof( struct V_44 ) ) ;
F_26 ( & V_60 ) ;
F_2 ( & V_58 , V_3 ,
F_3 ( V_3 ) ,
V_61 , V_45 -> V_50 ) ;
V_6 = F_27 ( & V_58 , & V_60 ) ;
if ( V_6 )
goto V_70;
V_6 = F_28 ( & V_60 , & V_71 ) ;
if ( V_6 )
goto V_70;
if ( V_72 && ( type & 0x0038 ) && V_54 ) {
struct V_59 V_73 ;
F_26 ( & V_73 ) ;
V_65 = F_20 (
V_45 , V_53 , V_54 ) ;
if ( V_65 ) {
V_6 = F_29 ( & V_73 ,
V_65 -> V_37 ,
V_65 -> V_74 / 8 , true ) ;
if ( V_6 )
goto V_70;
V_6 = F_28 ( & V_60 ,
& V_73 ) ;
}
F_30 ( & V_73 ) ;
if ( V_6 )
goto V_70;
}
V_6 = F_31 ( & V_60 , L_8 ) ;
if ( V_6 )
goto V_70;
V_6 = F_32 ( & V_58 ) ;
if ( V_6 )
goto V_75;
V_6 = F_6 ( & V_58 , V_55 ) ;
F_33 ( & V_58 ) ;
V_75:
F_34 ( & V_60 ) ;
V_70:
F_30 ( & V_60 ) ;
V_69:
F_35 ( V_57 + sizeof( * V_45 ) ,
V_48 - sizeof( * V_45 ) ) ;
V_68:
F_35 ( V_57 , sizeof( * V_45 ) ) ;
V_67:
if ( V_45 )
F_25 ( V_45 ) ;
return V_6 ;
}
static int F_36 ( T_1 type , T_2 V_53 , T_2 V_54 )
{
struct V_1 V_2 ;
T_2 V_76 , V_57 , V_77 = V_78 ;
int V_6 ;
F_1 ( & V_2 ) ;
V_6 = F_37 ( & V_2 , V_79 ) ;
if ( V_6 )
return V_6 ;
F_38 ( & V_2 , type ) ;
if ( V_39 ) {
struct V_13 * V_14 = V_80 ;
V_14 -> type = type ;
if ( type & 0x80000000 ) {
switch ( V_81 ) {
case V_82 :
V_14 -> V_83 = V_53 ;
break;
case V_84 :
V_14 -> V_85 = V_53 ;
V_14 -> V_86 = V_54 ;
break;
case V_87 :
V_14 -> V_20 = V_53 ;
break;
}
V_14 -> V_88 = V_81 ;
} else {
switch ( type ) {
case V_89 :
case V_90 :
case V_91 :
V_14 -> V_83 = V_53 ;
V_14 -> V_88 = V_82 ;
break;
case V_92 :
case V_93 :
case V_94 :
V_14 -> V_85 = V_53 ;
V_14 -> V_86 = V_54 ;
V_14 -> V_88 = V_84 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_14 -> V_20 = V_53 ;
V_14 -> V_88 = V_87 ;
break;
}
}
} else {
V_6 = F_6 ( & V_2 , V_31 ) ;
if ( V_6 )
return V_6 ;
if ( V_80 ) {
struct V_40 * V_41 = V_80 ;
V_41 -> V_53 = V_53 ;
V_41 -> V_54 = V_54 ;
}
}
V_6 = F_6 ( & V_2 , V_98 ) ;
if ( V_6 )
return V_6 ;
for (; ; ) {
V_6 = F_6 ( & V_2 , V_99 ) ;
if ( V_6 )
return V_6 ;
V_76 = F_7 ( & V_2 ) ;
if ( ! ( V_76 & V_100 ) )
break;
if ( F_11 ( & V_77 ) )
return - V_64 ;
}
V_6 = F_6 ( & V_2 , V_101 ) ;
if ( V_6 )
return V_6 ;
V_76 = F_7 ( & V_2 ) ;
if ( V_76 != V_102 )
return - V_103 ;
V_6 = F_6 ( & V_2 , V_104 ) ;
if ( V_6 )
return V_6 ;
V_57 = F_7 ( & V_2 ) ;
V_6 = F_21 ( V_57 , type , V_53 , V_54 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_37 ( & V_2 , V_105 ) ;
return V_6 ;
}
static int F_39 ( T_1 type , T_2 V_53 , T_2 V_54 )
{
int V_6 ;
F_9 ( & V_8 ) ;
V_6 = F_36 ( type , V_53 , V_54 ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_40 ( struct V_106 * V_107 , void * V_18 )
{
int V_6 ;
T_1 V_108 = 0 ;
V_6 = F_8 ( & V_108 ) ;
if ( V_6 )
return V_6 ;
if ( V_108 & 0x0001 )
F_41 ( V_107 , L_9 ) ;
if ( V_108 & 0x0002 )
F_41 ( V_107 , L_10 ) ;
if ( V_108 & 0x0004 )
F_41 ( V_107 , L_11 ) ;
if ( V_108 & 0x0008 )
F_41 ( V_107 , L_12 ) ;
if ( V_108 & 0x0010 )
F_41 ( V_107 , L_13 ) ;
if ( V_108 & 0x0020 )
F_41 ( V_107 , L_14 ) ;
if ( V_108 & 0x0040 )
F_41 ( V_107 , L_15 ) ;
if ( V_108 & 0x0080 )
F_41 ( V_107 , L_16 ) ;
if ( V_108 & 0x0100 )
F_41 ( V_107 , L_17 ) ;
if ( V_108 & 0x0200 )
F_41 ( V_107 , L_18 ) ;
if ( V_108 & 0x0400 )
F_41 ( V_107 , L_19 ) ;
if ( V_108 & 0x0800 )
F_41 ( V_107 , L_20 ) ;
return 0 ;
}
static int F_42 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_43 ( V_110 , F_40 , NULL ) ;
}
static int F_44 ( void * V_111 , T_2 * V_76 )
{
* V_76 = V_112 ;
return 0 ;
}
static int F_45 ( void * V_111 , T_2 V_76 )
{
int V_6 ;
T_1 V_108 = 0 ;
T_1 V_113 , V_114 ;
V_114 = V_76 & 0x80000000 ;
V_113 = V_76 & 0x7fffffff ;
if ( V_113 & ( V_113 - 1 ) )
return - V_47 ;
if ( ! V_114 ) {
V_6 = F_8 ( & V_108 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_76 & V_108 ) )
return - V_47 ;
}
V_112 = V_76 ;
return 0 ;
}
static int F_46 ( void * V_111 , T_2 V_76 )
{
if ( ! V_112 )
return - V_47 ;
return F_39 ( V_112 , V_115 , V_116 ) ;
}
static int F_47 ( struct V_117 * V_4 )
{
if ( ( V_4 -> V_118 !=
( sizeof( struct V_117 ) - sizeof( V_4 -> V_119 ) ) )
&& ( V_4 -> V_118 != sizeof( struct V_117 ) ) )
return - V_47 ;
if ( V_4 -> V_119 . V_120 < sizeof( struct V_117 ) )
return - V_47 ;
if ( V_4 -> V_5 !=
( V_4 -> V_119 . V_120 - sizeof( struct V_117 ) ) /
sizeof( struct V_51 ) )
return - V_47 ;
return 0 ;
}
static int T_3 F_48 ( void )
{
int V_6 ;
T_4 V_121 ;
struct V_122 * V_123 ;
struct V_1 V_2 ;
if ( V_124 )
return - V_125 ;
V_121 = F_49 ( V_126 , 0 ,
(struct V_127 * * ) & V_4 ) ;
if ( V_121 == V_128 )
return - V_125 ;
else if ( F_50 ( V_121 ) ) {
const char * V_129 = F_51 ( V_121 ) ;
F_23 ( V_66 L_21 , V_129 ) ;
return - V_47 ;
}
V_6 = F_47 ( V_4 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX L_22 ) ;
return - V_47 ;
}
V_6 = - V_130 ;
V_131 = F_52 ( L_23 , F_53 () ) ;
if ( ! V_131 )
goto V_132;
V_123 = F_54 ( L_24 , V_133 ,
V_131 , NULL ,
& V_134 ) ;
if ( ! V_123 )
goto V_132;
V_123 = F_54 ( L_25 , V_133 | V_135 ,
V_131 , NULL , & V_136 ) ;
if ( ! V_123 )
goto V_132;
V_123 = F_54 ( L_26 , V_135 ,
V_131 , NULL , & V_137 ) ;
if ( ! V_123 )
goto V_132;
F_26 ( & V_71 ) ;
F_1 ( & V_2 ) ;
V_6 = F_27 ( & V_2 , & V_71 ) ;
if ( V_6 )
goto V_138;
V_6 = F_31 ( & V_71 , L_27 ) ;
if ( V_6 )
goto V_138;
V_6 = F_32 ( & V_2 ) ;
if ( V_6 )
goto V_139;
V_80 = F_18 () ;
if ( ( V_72 || V_39 ) && V_80 ) {
V_123 = F_55 ( L_28 , V_133 | V_135 ,
V_131 , & V_115 ) ;
if ( ! V_123 )
goto V_140;
V_123 = F_55 ( L_29 , V_133 | V_135 ,
V_131 , & V_116 ) ;
if ( ! V_123 )
goto V_140;
}
if ( V_21 [ 0 ] ) {
V_141 . V_111 = V_21 ;
V_141 . V_142 = strlen ( V_21 ) ;
V_123 = F_56 ( L_30 , V_133 ,
V_131 , & V_141 ) ;
if ( ! V_123 )
goto V_140;
V_123 = F_57 ( L_31 , V_133 | V_135 ,
V_131 , & V_81 ) ;
if ( ! V_123 )
goto V_140;
}
F_58 ( V_66 L_32 ) ;
return 0 ;
V_140:
if ( V_80 ) {
T_5 V_142 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_40 ) ;
F_17 ( V_80 , V_142 ) ;
}
F_33 ( & V_2 ) ;
V_139:
F_34 ( & V_71 ) ;
V_138:
F_30 ( & V_71 ) ;
V_132:
F_59 ( V_131 ) ;
return V_6 ;
}
static void T_6 F_60 ( void )
{
struct V_1 V_2 ;
if ( V_80 ) {
T_5 V_142 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_40 ) ;
F_17 ( V_80 , V_142 ) ;
}
F_1 ( & V_2 ) ;
F_33 ( & V_2 ) ;
F_34 ( & V_71 ) ;
F_30 ( & V_71 ) ;
F_59 ( V_131 ) ;
}
