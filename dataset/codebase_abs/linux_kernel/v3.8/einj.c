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
if ( V_40 && V_26 ) {
struct V_41 * V_42 ;
V_42 = F_16 ( V_26 , sizeof( * V_42 ) ) ;
if ( ! V_42 )
return NULL ;
if ( V_42 -> V_43 || V_42 -> V_44 ) {
F_17 ( V_42 , sizeof( * V_42 ) ) ;
return NULL ;
}
return V_42 ;
}
return NULL ;
}
static int F_19 ( struct V_45 * V_46 )
{
if ( V_46 -> V_47 != sizeof( struct V_45 ) )
return - V_48 ;
if ( V_46 -> V_49 > V_50 ||
V_46 -> V_49 < V_46 -> V_47 )
return - V_48 ;
if ( V_46 -> V_51 !=
( V_46 -> V_49 - V_46 -> V_47 ) /
sizeof( struct V_52 ) )
return - V_48 ;
return 0 ;
}
static struct V_53 * F_20 (
struct V_45 * V_46 , T_2 V_54 , T_2 V_55 )
{
int V_25 ;
struct V_28 * V_29 ;
V_29 = (struct V_28 * )
( ( char * ) V_46 + sizeof( struct V_45 ) ) ;
for ( V_25 = 0 ; V_25 < V_46 -> V_51 ; V_25 ++ ) {
if ( V_29 -> V_30 == V_56 &&
V_29 -> V_32 == V_57 &&
V_29 -> V_34 . V_35 ==
V_36 &&
( V_29 -> V_34 . V_37 & V_55 ) == ( V_54 & V_55 ) )
return & V_29 -> V_34 ;
V_29 ++ ;
}
return NULL ;
}
static int F_21 ( T_2 V_58 , T_1 type ,
T_2 V_54 , T_2 V_55 )
{
struct V_45 * V_46 = NULL ;
struct V_1 V_59 ;
struct V_60 V_61 ;
struct V_28 * V_62 ;
struct V_63 * V_64 ;
T_1 V_49 ;
int V_6 = - V_65 ;
struct V_53 * V_66 = NULL ;
V_64 = F_22 ( V_58 , sizeof( * V_46 ) ,
L_3 ) ;
if ( ! V_64 ) {
F_23 ( V_67
L_4 ,
( unsigned long long ) V_58 ,
( unsigned long long ) V_58 +
sizeof( * V_46 ) - 1 ) ;
goto V_68;
}
V_46 = F_24 ( V_58 , sizeof( * V_46 ) ) ;
if ( ! V_46 ) {
F_23 ( V_67 L_5 ) ;
goto V_69;
}
V_6 = F_19 ( V_46 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX
L_6 ) ;
goto V_69;
}
if ( ! V_46 -> V_51 )
goto V_69;
V_6 = - V_65 ;
V_49 = V_46 -> V_49 ;
V_64 = F_22 ( V_58 + sizeof( * V_46 ) ,
V_49 - sizeof( * V_46 ) ,
L_3 ) ;
if ( ! V_64 ) {
F_23 ( V_67
L_7 ,
( unsigned long long ) V_58 + sizeof( * V_46 ) ,
( unsigned long long ) V_58 + V_49 - 1 ) ;
goto V_69;
}
F_25 ( V_46 ) ;
V_46 = F_24 ( V_58 , V_49 ) ;
if ( ! V_46 ) {
F_23 ( V_67 L_5 ) ;
goto V_70;
}
V_62 = (struct V_28 * )
( ( char * ) V_46 + sizeof( struct V_45 ) ) ;
F_26 ( & V_61 ) ;
F_2 ( & V_59 , V_3 ,
F_3 ( V_3 ) ,
V_62 , V_46 -> V_51 ) ;
V_6 = F_27 ( & V_59 , & V_61 ) ;
if ( V_6 )
goto V_71;
V_6 = F_28 ( & V_61 , & V_72 ) ;
if ( V_6 )
goto V_71;
if ( ( V_40 || V_39 ) && ( type & 0x0038 ) && V_55 ) {
struct V_60 V_73 ;
F_26 ( & V_73 ) ;
V_66 = F_20 (
V_46 , V_54 , V_55 ) ;
if ( V_66 ) {
V_6 = F_29 ( & V_73 ,
V_66 -> V_37 ,
V_66 -> V_74 / 8 , true ) ;
if ( V_6 )
goto V_71;
V_6 = F_28 ( & V_61 ,
& V_73 ) ;
}
F_30 ( & V_73 ) ;
if ( V_6 )
goto V_71;
}
V_6 = F_31 ( & V_61 , L_8 ) ;
if ( V_6 )
goto V_71;
V_6 = F_32 ( & V_59 ) ;
if ( V_6 )
goto V_75;
V_6 = F_6 ( & V_59 , V_56 ) ;
F_33 ( & V_59 ) ;
V_75:
F_34 ( & V_61 ) ;
V_71:
F_30 ( & V_61 ) ;
V_70:
F_35 ( V_58 + sizeof( * V_46 ) ,
V_49 - sizeof( * V_46 ) ) ;
V_69:
F_35 ( V_58 , sizeof( * V_46 ) ) ;
V_68:
if ( V_46 )
F_25 ( V_46 ) ;
return V_6 ;
}
static int F_36 ( T_1 type , T_2 V_54 , T_2 V_55 )
{
struct V_1 V_2 ;
T_2 V_76 , V_58 , V_77 = V_78 ;
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
V_14 -> V_83 = V_54 ;
break;
case V_84 :
V_14 -> V_85 = V_54 ;
V_14 -> V_86 = V_55 ;
break;
case V_87 :
V_14 -> V_20 = V_54 ;
break;
}
V_14 -> V_88 = V_81 ;
} else {
switch ( type ) {
case V_89 :
case V_90 :
case V_91 :
V_14 -> V_83 = V_54 ;
V_14 -> V_88 = V_82 ;
break;
case V_92 :
case V_93 :
case V_94 :
V_14 -> V_85 = V_54 ;
V_14 -> V_86 = V_55 ;
V_14 -> V_88 = V_84 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_14 -> V_20 = V_54 ;
V_14 -> V_88 = V_87 ;
break;
}
}
} else {
V_6 = F_6 ( & V_2 , V_31 ) ;
if ( V_6 )
return V_6 ;
if ( V_80 ) {
struct V_41 * V_42 = V_80 ;
V_42 -> V_54 = V_54 ;
V_42 -> V_55 = V_55 ;
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
return - V_65 ;
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
V_58 = F_7 ( & V_2 ) ;
if ( V_105 == 0 ) {
V_6 = F_21 ( V_58 , type , V_54 , V_55 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_37 ( & V_2 , V_106 ) ;
return V_6 ;
}
static int F_39 ( T_1 type , T_2 V_54 , T_2 V_55 )
{
int V_6 ;
F_9 ( & V_8 ) ;
V_6 = F_36 ( type , V_54 , V_55 ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_40 ( struct V_107 * V_108 , void * V_18 )
{
int V_6 ;
T_1 V_109 = 0 ;
V_6 = F_8 ( & V_109 ) ;
if ( V_6 )
return V_6 ;
if ( V_109 & 0x0001 )
F_41 ( V_108 , L_9 ) ;
if ( V_109 & 0x0002 )
F_41 ( V_108 , L_10 ) ;
if ( V_109 & 0x0004 )
F_41 ( V_108 , L_11 ) ;
if ( V_109 & 0x0008 )
F_41 ( V_108 , L_12 ) ;
if ( V_109 & 0x0010 )
F_41 ( V_108 , L_13 ) ;
if ( V_109 & 0x0020 )
F_41 ( V_108 , L_14 ) ;
if ( V_109 & 0x0040 )
F_41 ( V_108 , L_15 ) ;
if ( V_109 & 0x0080 )
F_41 ( V_108 , L_16 ) ;
if ( V_109 & 0x0100 )
F_41 ( V_108 , L_17 ) ;
if ( V_109 & 0x0200 )
F_41 ( V_108 , L_18 ) ;
if ( V_109 & 0x0400 )
F_41 ( V_108 , L_19 ) ;
if ( V_109 & 0x0800 )
F_41 ( V_108 , L_20 ) ;
return 0 ;
}
static int F_42 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_43 ( V_111 , F_40 , NULL ) ;
}
static int F_44 ( void * V_112 , T_2 * V_76 )
{
* V_76 = V_113 ;
return 0 ;
}
static int F_45 ( void * V_112 , T_2 V_76 )
{
int V_6 ;
T_1 V_109 = 0 ;
T_1 V_114 , V_115 ;
V_115 = V_76 & 0x80000000 ;
V_114 = V_76 & 0x7fffffff ;
if ( V_114 & ( V_114 - 1 ) )
return - V_48 ;
if ( ! V_115 ) {
V_6 = F_8 ( & V_109 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_76 & V_109 ) )
return - V_48 ;
}
V_113 = V_76 ;
return 0 ;
}
static int F_46 ( void * V_112 , T_2 V_76 )
{
if ( ! V_113 )
return - V_48 ;
return F_39 ( V_113 , V_116 , V_117 ) ;
}
static int F_47 ( struct V_118 * V_4 )
{
if ( ( V_4 -> V_119 !=
( sizeof( struct V_118 ) - sizeof( V_4 -> V_120 ) ) )
&& ( V_4 -> V_119 != sizeof( struct V_118 ) ) )
return - V_48 ;
if ( V_4 -> V_120 . V_121 < sizeof( struct V_118 ) )
return - V_48 ;
if ( V_4 -> V_5 !=
( V_4 -> V_120 . V_121 - sizeof( struct V_118 ) ) /
sizeof( struct V_52 ) )
return - V_48 ;
return 0 ;
}
static int T_3 F_48 ( void )
{
int V_6 ;
T_4 V_122 ;
struct V_123 * V_124 ;
struct V_1 V_2 ;
if ( V_125 )
return - V_126 ;
V_122 = F_49 ( V_127 , 0 ,
(struct V_128 * * ) & V_4 ) ;
if ( V_122 == V_129 )
return - V_126 ;
else if ( F_50 ( V_122 ) ) {
const char * V_130 = F_51 ( V_122 ) ;
F_23 ( V_67 L_21 , V_130 ) ;
return - V_48 ;
}
V_6 = F_47 ( V_4 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX L_22 ) ;
return - V_48 ;
}
V_6 = - V_131 ;
V_132 = F_52 ( L_23 , F_53 () ) ;
if ( ! V_132 )
goto V_133;
V_124 = F_54 ( L_24 , V_134 ,
V_132 , NULL ,
& V_135 ) ;
if ( ! V_124 )
goto V_133;
V_124 = F_54 ( L_25 , V_134 | V_136 ,
V_132 , NULL , & V_137 ) ;
if ( ! V_124 )
goto V_133;
V_124 = F_54 ( L_26 , V_136 ,
V_132 , NULL , & V_138 ) ;
if ( ! V_124 )
goto V_133;
F_26 ( & V_72 ) ;
F_1 ( & V_2 ) ;
V_6 = F_27 ( & V_2 , & V_72 ) ;
if ( V_6 )
goto V_139;
V_6 = F_31 ( & V_72 , L_27 ) ;
if ( V_6 )
goto V_139;
V_6 = F_32 ( & V_2 ) ;
if ( V_6 )
goto V_140;
V_80 = F_18 () ;
if ( ( V_40 || V_39 ) && V_80 ) {
V_124 = F_55 ( L_28 , V_134 | V_136 ,
V_132 , & V_116 ) ;
if ( ! V_124 )
goto V_141;
V_124 = F_55 ( L_29 , V_134 | V_136 ,
V_132 , & V_117 ) ;
if ( ! V_124 )
goto V_141;
V_124 = F_56 ( L_30 , V_134 | V_136 ,
V_132 , & V_105 ) ;
if ( ! V_124 )
goto V_141;
}
if ( V_21 [ 0 ] ) {
V_142 . V_112 = V_21 ;
V_142 . V_143 = strlen ( V_21 ) ;
V_124 = F_57 ( L_31 , V_134 ,
V_132 , & V_142 ) ;
if ( ! V_124 )
goto V_141;
V_124 = F_56 ( L_32 , V_134 | V_136 ,
V_132 , & V_81 ) ;
if ( ! V_124 )
goto V_141;
}
F_58 ( V_67 L_33 ) ;
return 0 ;
V_141:
if ( V_80 ) {
T_5 V_143 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_80 , V_143 ) ;
}
F_33 ( & V_2 ) ;
V_140:
F_34 ( & V_72 ) ;
V_139:
F_30 ( & V_72 ) ;
V_133:
F_59 ( V_132 ) ;
return V_6 ;
}
static void T_6 F_60 ( void )
{
struct V_1 V_2 ;
if ( V_80 ) {
T_5 V_143 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_80 , V_143 ) ;
}
F_1 ( & V_2 ) ;
F_33 ( & V_2 ) ;
F_34 ( & V_72 ) ;
F_30 ( & V_72 ) ;
F_59 ( V_132 ) ;
}
