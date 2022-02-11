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
V_26 = F_19 ( & V_29 -> V_34 . V_37 ) ;
if ( V_29 -> V_30 == V_38 &&
V_29 -> V_32 == V_33 &&
V_29 -> V_34 . V_35 ==
V_36 )
V_27 = F_19 ( & V_29 -> V_34 . V_37 ) ;
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
static int F_20 ( struct V_45 * V_46 )
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
static struct V_53 * F_21 (
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
static int F_22 ( T_2 V_58 , T_1 type ,
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
V_64 = F_23 ( V_58 , sizeof( * V_46 ) ,
L_3 ) ;
if ( ! V_64 ) {
F_24 ( V_67
L_4 ,
( unsigned long long ) V_58 ,
( unsigned long long ) V_58 +
sizeof( * V_46 ) - 1 ) ;
goto V_68;
}
V_46 = F_25 ( V_58 , sizeof( * V_46 ) ) ;
if ( ! V_46 ) {
F_24 ( V_67 L_5 ) ;
goto V_69;
}
V_6 = F_20 ( V_46 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX
L_6 ) ;
goto V_69;
}
if ( ! V_46 -> V_51 )
goto V_69;
V_6 = - V_65 ;
V_49 = V_46 -> V_49 ;
V_64 = F_23 ( V_58 + sizeof( * V_46 ) ,
V_49 - sizeof( * V_46 ) ,
L_3 ) ;
if ( ! V_64 ) {
F_24 ( V_67
L_7 ,
( unsigned long long ) V_58 + sizeof( * V_46 ) ,
( unsigned long long ) V_58 + V_49 - 1 ) ;
goto V_69;
}
F_26 ( V_46 ) ;
V_46 = F_25 ( V_58 , V_49 ) ;
if ( ! V_46 ) {
F_24 ( V_67 L_5 ) ;
goto V_70;
}
V_62 = (struct V_28 * )
( ( char * ) V_46 + sizeof( struct V_45 ) ) ;
F_27 ( & V_61 ) ;
F_2 ( & V_59 , V_3 ,
F_3 ( V_3 ) ,
V_62 , V_46 -> V_51 ) ;
V_6 = F_28 ( & V_59 , & V_61 ) ;
if ( V_6 )
goto V_71;
V_6 = F_29 ( & V_61 , & V_72 ) ;
if ( V_6 )
goto V_71;
if ( ( V_40 || V_39 ) && ( type & V_73 ) && V_55 ) {
struct V_60 V_74 ;
F_27 ( & V_74 ) ;
V_66 = F_21 (
V_46 , V_54 , V_55 ) ;
if ( V_66 ) {
V_6 = F_30 ( & V_74 ,
V_66 -> V_37 ,
V_66 -> V_75 / 8 , true ) ;
if ( V_6 )
goto V_71;
V_6 = F_29 ( & V_61 ,
& V_74 ) ;
}
F_31 ( & V_74 ) ;
if ( V_6 )
goto V_71;
}
V_6 = F_32 ( & V_61 , L_8 ) ;
if ( V_6 )
goto V_71;
V_6 = F_33 ( & V_59 ) ;
if ( V_6 )
goto V_76;
V_6 = F_6 ( & V_59 , V_56 ) ;
F_34 ( & V_59 ) ;
V_76:
F_35 ( & V_61 ) ;
V_71:
F_31 ( & V_61 ) ;
V_70:
F_36 ( V_58 + sizeof( * V_46 ) ,
V_49 - sizeof( * V_46 ) ) ;
V_69:
F_36 ( V_58 , sizeof( * V_46 ) ) ;
V_68:
if ( V_46 )
F_26 ( V_46 ) ;
return V_6 ;
}
static int F_37 ( T_1 type , T_1 V_77 , T_2 V_54 , T_2 V_55 ,
T_2 V_78 , T_2 V_79 )
{
struct V_1 V_2 ;
T_2 V_80 , V_58 , V_81 = V_82 ;
int V_6 ;
F_1 ( & V_2 ) ;
V_6 = F_38 ( & V_2 , V_83 ) ;
if ( V_6 )
return V_6 ;
F_39 ( & V_2 , type ) ;
if ( V_39 ) {
struct V_13 * V_14 = V_84 ;
V_14 -> type = type ;
if ( type & V_85 ) {
switch ( V_86 ) {
case V_87 :
V_14 -> V_88 = V_54 ;
break;
case V_89 :
V_14 -> V_90 = V_54 ;
V_14 -> V_91 = V_55 ;
break;
case V_92 :
V_14 -> V_20 = V_54 ;
break;
}
V_14 -> V_77 = V_86 ;
} else if ( V_77 ) {
V_14 -> V_77 = V_77 ;
V_14 -> V_90 = V_54 ;
V_14 -> V_91 = V_55 ;
V_14 -> V_88 = V_78 ;
V_14 -> V_20 = V_79 ;
} else {
switch ( type ) {
case V_93 :
case V_94 :
case V_95 :
V_14 -> V_88 = V_54 ;
V_14 -> V_77 = V_87 ;
break;
case V_96 :
case V_97 :
case V_98 :
V_14 -> V_90 = V_54 ;
V_14 -> V_91 = V_55 ;
V_14 -> V_77 = V_89 ;
break;
case V_99 :
case V_100 :
case V_101 :
V_14 -> V_20 = V_54 ;
V_14 -> V_77 = V_92 ;
break;
}
}
} else {
V_6 = F_6 ( & V_2 , V_31 ) ;
if ( V_6 )
return V_6 ;
if ( V_84 ) {
struct V_41 * V_42 = V_84 ;
V_42 -> V_54 = V_54 ;
V_42 -> V_55 = V_55 ;
}
}
V_6 = F_6 ( & V_2 , V_102 ) ;
if ( V_6 )
return V_6 ;
for (; ; ) {
V_6 = F_6 ( & V_2 , V_103 ) ;
if ( V_6 )
return V_6 ;
V_80 = F_7 ( & V_2 ) ;
if ( ! ( V_80 & V_104 ) )
break;
if ( F_11 ( & V_81 ) )
return - V_65 ;
}
V_6 = F_6 ( & V_2 , V_105 ) ;
if ( V_6 )
return V_6 ;
V_80 = F_7 ( & V_2 ) ;
if ( V_80 != V_106 )
return - V_107 ;
V_6 = F_6 ( & V_2 , V_108 ) ;
if ( V_6 )
return V_6 ;
V_58 = F_7 ( & V_2 ) ;
if ( V_109 == 0 ) {
V_6 = F_22 ( V_58 , type , V_54 , V_55 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_38 ( & V_2 , V_110 ) ;
return V_6 ;
}
static int F_40 ( T_1 type , T_1 V_77 , T_2 V_54 , T_2 V_55 ,
T_2 V_78 , T_2 V_79 )
{
int V_6 ;
T_2 V_111 , V_112 ;
if ( V_77 && ( V_77 &
~ ( V_87 | V_89 | V_92 ) ) )
return - V_48 ;
if ( ! ( V_40 || V_39 ) )
goto V_113;
if ( type & V_85 ) {
if ( V_86 != V_89 )
goto V_113;
} else if ( ! ( type & V_73 ) && ! ( V_77 & V_89 ) )
goto V_113;
V_111 = V_54 & V_55 ;
V_112 = ~ V_55 + 1 ;
if ( ( ( V_55 & V_114 ) != V_114 ) ||
( ( F_41 ( V_111 , V_112 , V_115 , V_116 )
!= V_117 ) &&
( F_41 ( V_111 , V_112 , V_118 , V_119 )
!= V_117 ) ) )
return - V_48 ;
V_113:
F_9 ( & V_8 ) ;
V_6 = F_37 ( type , V_77 , V_54 , V_55 , V_78 , V_79 ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_42 ( struct V_120 * V_121 , void * V_18 )
{
int V_6 ;
T_1 V_122 = 0 ;
V_6 = F_8 ( & V_122 ) ;
if ( V_6 )
return V_6 ;
if ( V_122 & 0x0001 )
F_43 ( V_121 , L_9 ) ;
if ( V_122 & 0x0002 )
F_43 ( V_121 , L_10 ) ;
if ( V_122 & 0x0004 )
F_43 ( V_121 , L_11 ) ;
if ( V_122 & 0x0008 )
F_43 ( V_121 , L_12 ) ;
if ( V_122 & 0x0010 )
F_43 ( V_121 , L_13 ) ;
if ( V_122 & 0x0020 )
F_43 ( V_121 , L_14 ) ;
if ( V_122 & 0x0040 )
F_43 ( V_121 , L_15 ) ;
if ( V_122 & 0x0080 )
F_43 ( V_121 , L_16 ) ;
if ( V_122 & 0x0100 )
F_43 ( V_121 , L_17 ) ;
if ( V_122 & 0x0200 )
F_43 ( V_121 , L_18 ) ;
if ( V_122 & 0x0400 )
F_43 ( V_121 , L_19 ) ;
if ( V_122 & 0x0800 )
F_43 ( V_121 , L_20 ) ;
return 0 ;
}
static int F_44 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_45 ( V_124 , F_42 , NULL ) ;
}
static int F_46 ( void * V_125 , T_2 * V_80 )
{
* V_80 = V_126 ;
return 0 ;
}
static int F_47 ( void * V_125 , T_2 V_80 )
{
int V_6 ;
T_1 V_122 = 0 ;
T_1 V_127 , V_128 ;
V_128 = V_80 & V_85 ;
V_127 = V_80 & 0x7fffffff ;
if ( V_127 & ( V_127 - 1 ) )
return - V_48 ;
if ( ! V_128 ) {
V_6 = F_8 ( & V_122 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_80 & V_122 ) )
return - V_48 ;
}
V_126 = V_80 ;
return 0 ;
}
static int F_48 ( void * V_125 , T_2 V_80 )
{
if ( ! V_126 )
return - V_48 ;
return F_40 ( V_126 , V_129 , V_130 , V_131 ,
V_132 , V_133 ) ;
}
static int F_49 ( struct V_134 * V_4 )
{
if ( ( V_4 -> V_135 !=
( sizeof( struct V_134 ) - sizeof( V_4 -> V_136 ) ) )
&& ( V_4 -> V_135 != sizeof( struct V_134 ) ) )
return - V_48 ;
if ( V_4 -> V_136 . V_137 < sizeof( struct V_134 ) )
return - V_48 ;
if ( V_4 -> V_5 !=
( V_4 -> V_136 . V_137 - sizeof( struct V_134 ) ) /
sizeof( struct V_52 ) )
return - V_48 ;
return 0 ;
}
static int T_3 F_50 ( void )
{
int V_6 ;
T_4 V_138 ;
struct V_139 * V_140 ;
struct V_1 V_2 ;
if ( V_141 )
return - V_142 ;
V_138 = F_51 ( V_143 , 0 ,
(struct V_144 * * ) & V_4 ) ;
if ( V_138 == V_145 )
return - V_142 ;
else if ( F_52 ( V_138 ) ) {
const char * V_146 = F_53 ( V_138 ) ;
F_24 ( V_67 L_21 , V_146 ) ;
return - V_48 ;
}
V_6 = F_49 ( V_4 ) ;
if ( V_6 ) {
F_12 (FW_BUG EINJ_PFX L_22 ) ;
return - V_48 ;
}
V_6 = - V_147 ;
V_148 = F_54 ( L_23 , F_55 () ) ;
if ( ! V_148 )
goto V_149;
V_140 = F_56 ( L_24 , V_150 ,
V_148 , NULL ,
& V_151 ) ;
if ( ! V_140 )
goto V_149;
V_140 = F_56 ( L_25 , V_150 | V_152 ,
V_148 , NULL , & V_153 ) ;
if ( ! V_140 )
goto V_149;
V_140 = F_56 ( L_26 , V_152 ,
V_148 , NULL , & V_154 ) ;
if ( ! V_140 )
goto V_149;
F_27 ( & V_72 ) ;
F_1 ( & V_2 ) ;
V_6 = F_28 ( & V_2 , & V_72 ) ;
if ( V_6 )
goto V_155;
V_6 = F_32 ( & V_72 , L_27 ) ;
if ( V_6 )
goto V_155;
V_6 = F_33 ( & V_2 ) ;
if ( V_6 )
goto V_156;
V_6 = - V_147 ;
V_84 = F_18 () ;
if ( ( V_40 || V_39 ) && V_84 ) {
V_140 = F_57 ( L_28 , V_150 | V_152 ,
V_148 , & V_129 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_58 ( L_29 , V_150 | V_152 ,
V_148 , & V_130 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_58 ( L_30 , V_150 | V_152 ,
V_148 , & V_131 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_58 ( L_31 , V_150 | V_152 ,
V_148 , & V_132 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_58 ( L_32 , V_150 | V_152 ,
V_148 , & V_133 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_57 ( L_33 , V_150 | V_152 ,
V_148 , & V_109 ) ;
if ( ! V_140 )
goto V_157;
}
if ( V_21 [ 0 ] ) {
V_158 . V_125 = V_21 ;
V_158 . V_112 = strlen ( V_21 ) ;
V_140 = F_59 ( L_34 , V_150 ,
V_148 , & V_158 ) ;
if ( ! V_140 )
goto V_157;
V_140 = F_57 ( L_35 , V_150 | V_152 ,
V_148 , & V_86 ) ;
if ( ! V_140 )
goto V_157;
}
F_60 ( V_67 L_36 ) ;
return 0 ;
V_157:
if ( V_84 ) {
T_5 V_112 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_84 , V_112 ) ;
}
F_34 ( & V_2 ) ;
V_156:
F_35 ( & V_72 ) ;
V_155:
F_31 ( & V_72 ) ;
V_149:
F_61 ( V_148 ) ;
return V_6 ;
}
static void T_6 F_62 ( void )
{
struct V_1 V_2 ;
if ( V_84 ) {
T_5 V_112 = ( V_39 ) ?
sizeof( struct V_13 ) :
sizeof( struct V_41 ) ;
F_17 ( V_84 , V_112 ) ;
}
F_1 ( & V_2 ) ;
F_34 ( & V_2 ) ;
F_35 ( & V_72 ) ;
F_31 ( & V_72 ) ;
F_61 ( V_148 ) ;
}
