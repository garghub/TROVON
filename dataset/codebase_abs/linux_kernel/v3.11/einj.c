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
if ( ( V_40 || V_39 ) && ( type & V_73 ) && V_55 ) {
struct V_60 V_74 ;
F_26 ( & V_74 ) ;
V_66 = F_20 (
V_46 , V_54 , V_55 ) ;
if ( V_66 ) {
V_6 = F_29 ( & V_74 ,
V_66 -> V_37 ,
V_66 -> V_75 / 8 , true ) ;
if ( V_6 )
goto V_71;
V_6 = F_28 ( & V_61 ,
& V_74 ) ;
}
F_30 ( & V_74 ) ;
if ( V_6 )
goto V_71;
}
V_6 = F_31 ( & V_61 , L_8 ) ;
if ( V_6 )
goto V_71;
V_6 = F_32 ( & V_59 ) ;
if ( V_6 )
goto V_76;
V_6 = F_6 ( & V_59 , V_56 ) ;
F_33 ( & V_59 ) ;
V_76:
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
T_2 V_77 , V_58 , V_78 = V_79 ;
int V_6 ;
F_1 ( & V_2 ) ;
V_6 = F_37 ( & V_2 , V_80 ) ;
if ( V_6 )
return V_6 ;
F_38 ( & V_2 , type ) ;
if ( V_39 ) {
struct V_13 * V_14 = V_81 ;
V_14 -> type = type ;
if ( type & V_82 ) {
switch ( V_83 ) {
case V_84 :
V_14 -> V_85 = V_54 ;
break;
case V_86 :
V_14 -> V_87 = V_54 ;
V_14 -> V_88 = V_55 ;
break;
case V_89 :
V_14 -> V_20 = V_54 ;
break;
}
V_14 -> V_90 = V_83 ;
} else {
switch ( type ) {
case V_91 :
case V_92 :
case V_93 :
V_14 -> V_85 = V_54 ;
V_14 -> V_90 = V_84 ;
break;
case V_94 :
case V_95 :
case V_96 :
V_14 -> V_87 = V_54 ;
V_14 -> V_88 = V_55 ;
V_14 -> V_90 = V_86 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_14 -> V_20 = V_54 ;
V_14 -> V_90 = V_89 ;
break;
}
}
} else {
V_6 = F_6 ( & V_2 , V_31 ) ;
if ( V_6 )
return V_6 ;
if ( V_81 ) {
struct V_41 * V_42 = V_81 ;
V_42 -> V_54 = V_54 ;
V_42 -> V_55 = V_55 ;
}
}
V_6 = F_6 ( & V_2 , V_100 ) ;
if ( V_6 )
return V_6 ;
for (; ; ) {
V_6 = F_6 ( & V_2 , V_101 ) ;
if ( V_6 )
return V_6 ;
V_77 = F_7 ( & V_2 ) ;
if ( ! ( V_77 & V_102 ) )
break;
if ( F_11 ( & V_78 ) )
return - V_65 ;
}
V_6 = F_6 ( & V_2 , V_103 ) ;
if ( V_6 )
return V_6 ;
V_77 = F_7 ( & V_2 ) ;
if ( V_77 != V_104 )
return - V_105 ;
V_6 = F_6 ( & V_2 , V_106 ) ;
if ( V_6 )
return V_6 ;
V_58 = F_7 ( & V_2 ) ;
if ( V_107 == 0 ) {
V_6 = F_21 ( V_58 , type , V_54 , V_55 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_37 ( & V_2 , V_108 ) ;
return V_6 ;
}
static int F_39 ( T_1 type , T_2 V_54 , T_2 V_55 )
{
int V_6 ;
unsigned long V_109 ;
if ( ! ( V_40 || V_39 ) )
goto V_110;
if ( type & V_82 ) {
if ( V_83 != V_86 )
goto V_110;
} else if ( ! ( type & V_73 ) )
goto V_110;
V_109 = F_40 ( V_54 & V_55 ) ;
if ( ! F_41 ( V_109 ) || ( ( V_55 & V_111 ) != V_111 ) )
return - V_48 ;
V_110:
F_9 ( & V_8 ) ;
V_6 = F_36 ( type , V_54 , V_55 ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_42 ( struct V_112 * V_113 , void * V_18 )
{
int V_6 ;
T_1 V_114 = 0 ;
V_6 = F_8 ( & V_114 ) ;
if ( V_6 )
return V_6 ;
if ( V_114 & 0x0001 )
F_43 ( V_113 , L_9 ) ;
if ( V_114 & 0x0002 )
F_43 ( V_113 , L_10 ) ;
if ( V_114 & 0x0004 )
F_43 ( V_113 , L_11 ) ;
if ( V_114 & 0x0008 )
F_43 ( V_113 , L_12 ) ;
if ( V_114 & 0x0010 )
F_43 ( V_113 , L_13 ) ;
if ( V_114 & 0x0020 )
F_43 ( V_113 , L_14 ) ;
if ( V_114 & 0x0040 )
F_43 ( V_113 , L_15 ) ;
if ( V_114 & 0x0080 )
F_43 ( V_113 , L_16 ) ;
if ( V_114 & 0x0100 )
F_43 ( V_113 , L_17 ) ;
if ( V_114 & 0x0200 )
F_43 ( V_113 , L_18 ) ;
if ( V_114 & 0x0400 )
F_43 ( V_113 , L_19 ) ;
if ( V_114 & 0x0800 )
F_43 ( V_113 , L_20 ) ;
return 0 ;
}
static int F_44 ( struct V_115 * V_115 , struct V_116 * V_116 )
{
return F_45 ( V_116 , F_42 , NULL ) ;
}
static int F_46 ( void * V_117 , T_2 * V_77 )
{
* V_77 = V_118 ;
return 0 ;
}
static int F_47 ( void * V_117 , T_2 V_77 )
{
int V_6 ;
T_1 V_114 = 0 ;
T_1 V_119 , V_120 ;
V_120 = V_77 & V_82 ;
V_119 = V_77 & 0x7fffffff ;
if ( V_119 & ( V_119 - 1 ) )
return - V_48 ;
if ( ! V_120 ) {
V_6 = F_8 ( & V_114 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_77 & V_114 ) )
return - V_48 ;
}
V_118 = V_77 ;
return 0 ;
}
static int F_48 ( void * V_117 , T_2 V_77 )
{
if ( ! V_118 )
return - V_48 ;
return F_39 ( V_118 , V_121 , V_122 ) ;
}
static int F_49 ( struct V_123 * V_4 )
{
if ( ( V_4 -> V_124 !=
( sizeof( struct V_123 ) - sizeof( V_4 -> V_125 ) ) )
&& ( V_4 -> V_124 != sizeof( struct V_123 ) ) )
return - V_48 ;
if ( V_4 -> V_125 . V_126 < sizeof( struct V_123 ) )
return - V_48 ;
if ( V_4 -> V_5 !=
( V_4 -> V_125 . V_126 - sizeof( struct V_123 ) ) /
sizeof( struct V_52 ) )
return - V_48 ;
return 0 ;
}
static int T_3 F_50 ( void )
{
int V_6 ;
T_4 V_127 ;
struct V_128 * V_129 ;
struct V_1 V_2 ;
if ( V_130 )
return - V_131 ;
V_127 = F_51 ( V_132 , 0 ,
(struct V_133 * * ) & V_4 ) ;
if ( V_127 == V_134 )
return - V_131 ;
else if ( F_52 ( V_127 ) ) {
const char * V_135 = F_53 ( V_127 ) ;
F_23 ( V_67 L_21 , V_135 ) ;
return - V_48 ;
}
V_6 = F_49 ( V_4 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX L_22 ) ;
return - V_48 ;
}
V_6 = - V_136 ;
V_137 = F_54 ( L_23 , F_55 () ) ;
if ( ! V_137 )
goto V_138;
V_129 = F_56 ( L_24 , V_139 ,
V_137 , NULL ,
& V_140 ) ;
if ( ! V_129 )
goto V_138;
V_129 = F_56 ( L_25 , V_139 | V_141 ,
V_137 , NULL , & V_142 ) ;
if ( ! V_129 )
goto V_138;
V_129 = F_56 ( L_26 , V_141 ,
V_137 , NULL , & V_143 ) ;
if ( ! V_129 )
goto V_138;
F_26 ( & V_72 ) ;
F_1 ( & V_2 ) ;
V_6 = F_27 ( & V_2 , & V_72 ) ;
if ( V_6 )
goto V_144;
V_6 = F_31 ( & V_72 , L_27 ) ;
if ( V_6 )
goto V_144;
V_6 = F_32 ( & V_2 ) ;
if ( V_6 )
goto V_145;
V_6 = - V_136 ;
V_81 = F_18 () ;
if ( ( V_40 || V_39 ) && V_81 ) {
V_129 = F_57 ( L_28 , V_139 | V_141 ,
V_137 , & V_121 ) ;
if ( ! V_129 )
goto V_146;
V_129 = F_57 ( L_29 , V_139 | V_141 ,
V_137 , & V_122 ) ;
if ( ! V_129 )
goto V_146;
V_129 = F_58 ( L_30 , V_139 | V_141 ,
V_137 , & V_107 ) ;
if ( ! V_129 )
goto V_146;
}
if ( V_21 [ 0 ] ) {
V_147 . V_117 = V_21 ;
V_147 . V_148 = strlen ( V_21 ) ;
V_129 = F_59 ( L_31 , V_139 ,
V_137 , & V_147 ) ;
if ( ! V_129 )
goto V_146;
V_129 = F_58 ( L_32 , V_139 | V_141 ,
V_137 , & V_83 ) ;
if ( ! V_129 )
goto V_146;
}
F_60 ( V_67 L_33 ) ;
return 0 ;
V_146:
if ( V_81 ) {
T_5 V_148 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_81 , V_148 ) ;
}
F_33 ( & V_2 ) ;
V_145:
F_34 ( & V_72 ) ;
V_144:
F_30 ( & V_72 ) ;
V_138:
F_61 ( V_137 ) ;
return V_6 ;
}
static void T_6 F_62 ( void )
{
struct V_1 V_2 ;
if ( V_81 ) {
T_5 V_148 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_81 , V_148 ) ;
}
F_1 ( & V_2 ) ;
F_33 ( & V_2 ) ;
F_34 ( & V_72 ) ;
F_30 ( & V_72 ) ;
F_61 ( V_137 ) ;
}
