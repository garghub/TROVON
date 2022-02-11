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
F_12 ( V_12 L_1 ) ;
return 1 ;
}
* V_9 -= V_11 ;
F_13 ( V_11 ) ;
F_14 () ;
return 0 ;
}
static void F_15 ( T_2 V_13 ,
struct V_14 * V_15 )
{
int V_16 = V_15 -> V_17 ;
struct V_18 * V_19 ;
T_1 V_20 ;
if ( ! V_16 )
return;
V_19 = F_16 ( V_13 + V_16 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return;
V_20 = V_19 -> V_21 ;
sprintf ( V_22 , L_2 ,
V_20 >> 24 , ( V_20 >> 16 ) & 0xff ,
( V_20 >> 11 ) & 0x1f , ( V_20 >> 8 ) & 0x7 ,
V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 ) ;
F_17 ( V_19 , sizeof( * V_19 ) ) ;
}
static void * F_18 ( void )
{
int V_26 ;
T_2 V_27 = 0 , V_28 = 0 ;
struct V_29 * V_30 ;
V_30 = F_4 ( V_4 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 ; V_26 ++ ) {
if ( V_30 -> V_31 == V_32 &&
V_30 -> V_33 == V_34 &&
V_30 -> V_35 . V_36 ==
V_37 )
V_27 = F_19 ( & V_30 -> V_35 . V_38 ) ;
if ( V_30 -> V_31 == V_39 &&
V_30 -> V_33 == V_34 &&
V_30 -> V_35 . V_36 ==
V_37 )
V_28 = F_19 ( & V_30 -> V_35 . V_38 ) ;
V_30 ++ ;
}
if ( V_28 ) {
struct V_14 * V_15 ;
V_15 = F_16 ( V_28 , sizeof( * V_15 ) ) ;
if ( V_15 ) {
V_40 = 1 ;
F_15 ( V_28 , V_15 ) ;
return V_15 ;
}
}
if ( V_41 && V_27 ) {
struct V_42 * V_43 ;
V_43 = F_16 ( V_27 , sizeof( * V_43 ) ) ;
if ( ! V_43 )
return NULL ;
if ( V_43 -> V_44 || V_43 -> V_45 ) {
F_17 ( V_43 , sizeof( * V_43 ) ) ;
return NULL ;
}
return V_43 ;
}
return NULL ;
}
static int F_20 ( struct V_46 * V_47 )
{
if ( V_47 -> V_48 != sizeof( struct V_46 ) )
return - V_49 ;
if ( V_47 -> V_50 > V_51 ||
V_47 -> V_50 < V_47 -> V_48 )
return - V_49 ;
if ( V_47 -> V_52 !=
( V_47 -> V_50 - V_47 -> V_48 ) /
sizeof( struct V_53 ) )
return - V_49 ;
return 0 ;
}
static struct V_54 * F_21 (
struct V_46 * V_47 , T_2 V_55 , T_2 V_56 )
{
int V_26 ;
struct V_29 * V_30 ;
V_30 = (struct V_29 * )
( ( char * ) V_47 + sizeof( struct V_46 ) ) ;
for ( V_26 = 0 ; V_26 < V_47 -> V_52 ; V_26 ++ ) {
if ( V_30 -> V_31 == V_57 &&
V_30 -> V_33 <= V_58 &&
V_30 -> V_35 . V_36 ==
V_37 &&
( V_30 -> V_35 . V_38 & V_56 ) == ( V_55 & V_56 ) )
return & V_30 -> V_35 ;
V_30 ++ ;
}
return NULL ;
}
static int F_22 ( T_2 V_59 , T_1 type ,
T_2 V_55 , T_2 V_56 )
{
struct V_46 * V_47 = NULL ;
struct V_1 V_60 ;
struct V_61 V_62 ;
struct V_29 * V_63 ;
struct V_64 * V_65 ;
T_1 V_50 ;
int V_6 = - V_66 ;
struct V_54 * V_67 = NULL ;
V_65 = F_23 ( V_59 , sizeof( * V_47 ) ,
L_3 ) ;
if ( ! V_65 ) {
F_24 ( L_4 ,
( unsigned long long ) V_59 ,
( unsigned long long ) V_59 +
sizeof( * V_47 ) - 1 ) ;
goto V_68;
}
V_47 = F_25 ( V_59 , sizeof( * V_47 ) ) ;
if ( ! V_47 ) {
F_24 ( L_5 ) ;
goto V_69;
}
V_6 = F_20 ( V_47 ) ;
if ( V_6 ) {
F_12 ( V_70 L_6 ) ;
goto V_69;
}
if ( ! V_47 -> V_52 )
goto V_69;
V_6 = - V_66 ;
V_50 = V_47 -> V_50 ;
V_65 = F_23 ( V_59 + sizeof( * V_47 ) ,
V_50 - sizeof( * V_47 ) ,
L_3 ) ;
if ( ! V_65 ) {
F_24 ( L_7 ,
( unsigned long long ) V_59 + sizeof( * V_47 ) ,
( unsigned long long ) V_59 + V_50 - 1 ) ;
goto V_69;
}
F_26 ( V_47 ) ;
V_47 = F_25 ( V_59 , V_50 ) ;
if ( ! V_47 ) {
F_24 ( L_5 ) ;
goto V_71;
}
V_63 = (struct V_29 * )
( ( char * ) V_47 + sizeof( struct V_46 ) ) ;
F_27 ( & V_62 ) ;
F_2 ( & V_60 , V_3 ,
F_3 ( V_3 ) ,
V_63 , V_47 -> V_52 ) ;
V_6 = F_28 ( & V_60 , & V_62 ) ;
if ( V_6 )
goto V_72;
V_6 = F_29 ( & V_62 , & V_73 ) ;
if ( V_6 )
goto V_72;
if ( ( V_41 || V_40 ) && ( type & V_74 ) && V_56 ) {
struct V_61 V_75 ;
F_27 ( & V_75 ) ;
V_67 = F_21 (
V_47 , V_55 , V_56 ) ;
if ( V_67 ) {
V_6 = F_30 ( & V_75 ,
V_67 -> V_38 ,
V_67 -> V_76 / 8 , true ) ;
if ( V_6 )
goto V_72;
V_6 = F_29 ( & V_62 ,
& V_75 ) ;
}
F_31 ( & V_75 ) ;
if ( V_6 )
goto V_72;
}
V_6 = F_32 ( & V_62 , L_8 ) ;
if ( V_6 )
goto V_72;
V_6 = F_33 ( & V_60 ) ;
if ( V_6 )
goto V_77;
V_6 = F_6 ( & V_60 , V_57 ) ;
F_34 ( & V_60 ) ;
V_77:
F_35 ( & V_62 ) ;
V_72:
F_31 ( & V_62 ) ;
V_71:
F_36 ( V_59 + sizeof( * V_47 ) ,
V_50 - sizeof( * V_47 ) ) ;
V_69:
F_36 ( V_59 , sizeof( * V_47 ) ) ;
V_68:
if ( V_47 )
F_26 ( V_47 ) ;
return V_6 ;
}
static int F_37 ( T_1 type , T_1 V_78 , T_2 V_55 , T_2 V_56 ,
T_2 V_79 , T_2 V_80 )
{
struct V_1 V_2 ;
T_2 V_81 , V_59 , V_82 = V_83 ;
int V_6 ;
F_1 ( & V_2 ) ;
V_6 = F_38 ( & V_2 , V_84 ) ;
if ( V_6 )
return V_6 ;
F_39 ( & V_2 , type ) ;
if ( V_40 ) {
struct V_14 * V_15 = V_85 ;
V_15 -> type = type ;
if ( type & V_86 ) {
switch ( V_87 ) {
case V_88 :
V_15 -> V_89 = V_55 ;
break;
case V_90 :
V_15 -> V_91 = V_55 ;
V_15 -> V_92 = V_56 ;
break;
case V_93 :
V_15 -> V_21 = V_55 ;
break;
}
V_15 -> V_78 = V_87 ;
} else if ( V_78 ) {
V_15 -> V_78 = V_78 ;
V_15 -> V_91 = V_55 ;
V_15 -> V_92 = V_56 ;
V_15 -> V_89 = V_79 ;
V_15 -> V_21 = V_80 ;
} else {
switch ( type ) {
case V_94 :
case V_95 :
case V_96 :
V_15 -> V_89 = V_55 ;
V_15 -> V_78 = V_88 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_15 -> V_91 = V_55 ;
V_15 -> V_92 = V_56 ;
V_15 -> V_78 = V_90 ;
break;
case V_100 :
case V_101 :
case V_102 :
V_15 -> V_21 = V_55 ;
V_15 -> V_78 = V_93 ;
break;
}
}
} else {
V_6 = F_6 ( & V_2 , V_32 ) ;
if ( V_6 )
return V_6 ;
if ( V_85 ) {
struct V_42 * V_43 = V_85 ;
V_43 -> V_55 = V_55 ;
V_43 -> V_56 = V_56 ;
}
}
V_6 = F_6 ( & V_2 , V_103 ) ;
if ( V_6 )
return V_6 ;
for (; ; ) {
V_6 = F_6 ( & V_2 , V_104 ) ;
if ( V_6 )
return V_6 ;
V_81 = F_7 ( & V_2 ) ;
if ( ! ( V_81 & V_105 ) )
break;
if ( F_11 ( & V_82 ) )
return - V_66 ;
}
V_6 = F_6 ( & V_2 , V_106 ) ;
if ( V_6 )
return V_6 ;
V_81 = F_7 ( & V_2 ) ;
if ( V_81 != V_107 )
return - V_108 ;
V_6 = F_6 ( & V_2 , V_109 ) ;
if ( V_6 )
return V_6 ;
V_59 = F_7 ( & V_2 ) ;
if ( V_110 == 0 ) {
V_6 = F_22 ( V_59 , type , V_55 , V_56 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_38 ( & V_2 , V_111 ) ;
return V_6 ;
}
static int F_40 ( T_1 type , T_1 V_78 , T_2 V_55 , T_2 V_56 ,
T_2 V_79 , T_2 V_80 )
{
int V_6 ;
T_2 V_112 , V_113 ;
if ( V_78 && ( V_78 &
~ ( V_88 | V_90 | V_93 ) ) )
return - V_49 ;
if ( ! ( V_41 || V_40 ) )
goto V_114;
if ( type & V_86 ) {
if ( V_87 != V_90 )
goto V_114;
} else if ( ! ( type & V_74 ) && ! ( V_78 & V_90 ) )
goto V_114;
V_112 = V_55 & V_56 ;
V_113 = ~ V_56 + 1 ;
if ( ( ( V_56 & V_115 ) != V_115 ) ||
( ( F_41 ( V_112 , V_113 , V_116 , V_117 )
!= V_118 ) &&
( F_41 ( V_112 , V_113 , V_119 , V_120 )
!= V_118 ) ) )
return - V_49 ;
V_114:
F_9 ( & V_8 ) ;
V_6 = F_37 ( type , V_78 , V_55 , V_56 , V_79 , V_80 ) ;
F_10 ( & V_8 ) ;
return V_6 ;
}
static int F_42 ( struct V_121 * V_122 , void * V_19 )
{
int V_6 ;
T_1 V_123 = 0 ;
V_6 = F_8 ( & V_123 ) ;
if ( V_6 )
return V_6 ;
if ( V_123 & 0x0001 )
F_43 ( V_122 , L_9 ) ;
if ( V_123 & 0x0002 )
F_43 ( V_122 , L_10 ) ;
if ( V_123 & 0x0004 )
F_43 ( V_122 , L_11 ) ;
if ( V_123 & 0x0008 )
F_43 ( V_122 , L_12 ) ;
if ( V_123 & 0x0010 )
F_43 ( V_122 , L_13 ) ;
if ( V_123 & 0x0020 )
F_43 ( V_122 , L_14 ) ;
if ( V_123 & 0x0040 )
F_43 ( V_122 , L_15 ) ;
if ( V_123 & 0x0080 )
F_43 ( V_122 , L_16 ) ;
if ( V_123 & 0x0100 )
F_43 ( V_122 , L_17 ) ;
if ( V_123 & 0x0200 )
F_43 ( V_122 , L_18 ) ;
if ( V_123 & 0x0400 )
F_43 ( V_122 , L_19 ) ;
if ( V_123 & 0x0800 )
F_43 ( V_122 , L_20 ) ;
return 0 ;
}
static int F_44 ( struct V_124 * V_124 , struct V_125 * V_125 )
{
return F_45 ( V_125 , F_42 , NULL ) ;
}
static int F_46 ( void * V_126 , T_2 * V_81 )
{
* V_81 = V_127 ;
return 0 ;
}
static int F_47 ( void * V_126 , T_2 V_81 )
{
int V_6 ;
T_1 V_123 = 0 ;
T_1 V_128 , V_129 ;
V_129 = V_81 & V_86 ;
V_128 = V_81 & 0x7fffffff ;
if ( V_128 & ( V_128 - 1 ) )
return - V_49 ;
if ( ! V_129 ) {
V_6 = F_8 ( & V_123 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_81 & V_123 ) )
return - V_49 ;
}
V_127 = V_81 ;
return 0 ;
}
static int F_48 ( void * V_126 , T_2 V_81 )
{
if ( ! V_127 )
return - V_49 ;
return F_40 ( V_127 , V_130 , V_131 , V_132 ,
V_133 , V_134 ) ;
}
static int F_49 ( struct V_135 * V_4 )
{
if ( ( V_4 -> V_136 !=
( sizeof( struct V_135 ) - sizeof( V_4 -> V_137 ) ) )
&& ( V_4 -> V_136 != sizeof( struct V_135 ) ) )
return - V_49 ;
if ( V_4 -> V_137 . V_138 < sizeof( struct V_135 ) )
return - V_49 ;
if ( V_4 -> V_5 !=
( V_4 -> V_137 . V_138 - sizeof( struct V_135 ) ) /
sizeof( struct V_53 ) )
return - V_49 ;
return 0 ;
}
static int T_3 F_50 ( void )
{
int V_6 ;
T_4 V_139 ;
struct V_140 * V_141 ;
struct V_1 V_2 ;
if ( V_142 ) {
F_51 ( L_21 ) ;
return - V_143 ;
}
V_139 = F_52 ( V_144 , 0 ,
(struct V_145 * * ) & V_4 ) ;
if ( V_139 == V_146 ) {
F_51 ( L_22 ) ;
return - V_143 ;
}
else if ( F_53 ( V_139 ) ) {
F_24 ( L_23 ,
F_54 ( V_139 ) ) ;
return - V_49 ;
}
V_6 = F_49 ( V_4 ) ;
if ( V_6 ) {
F_51 ( V_70 L_24 ) ;
return - V_49 ;
}
V_6 = - V_147 ;
V_148 = F_55 ( L_25 , F_56 () ) ;
if ( ! V_148 ) {
F_24 ( L_26 ) ;
goto V_149;
}
V_141 = F_57 ( L_27 , V_150 ,
V_148 , NULL ,
& V_151 ) ;
if ( ! V_141 )
goto V_149;
V_141 = F_57 ( L_28 , V_150 | V_152 ,
V_148 , NULL , & V_153 ) ;
if ( ! V_141 )
goto V_149;
V_141 = F_57 ( L_29 , V_152 ,
V_148 , NULL , & V_154 ) ;
if ( ! V_141 )
goto V_149;
F_27 ( & V_73 ) ;
F_1 ( & V_2 ) ;
V_6 = F_28 ( & V_2 , & V_73 ) ;
if ( V_6 ) {
F_24 ( L_30 ) ;
goto V_155;
}
V_6 = F_32 ( & V_73 , L_31 ) ;
if ( V_6 ) {
F_24 ( L_32 ) ;
goto V_155;
}
V_6 = F_33 ( & V_2 ) ;
if ( V_6 ) {
F_24 ( L_33 ) ;
goto V_156;
}
V_6 = - V_147 ;
V_85 = F_18 () ;
if ( ( V_41 || V_40 ) && V_85 ) {
V_141 = F_58 ( L_34 , V_150 | V_152 ,
V_148 , & V_130 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_59 ( L_35 , V_150 | V_152 ,
V_148 , & V_131 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_59 ( L_36 , V_150 | V_152 ,
V_148 , & V_132 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_59 ( L_37 , V_150 | V_152 ,
V_148 , & V_133 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_59 ( L_38 , V_150 | V_152 ,
V_148 , & V_134 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_58 ( L_39 , V_150 | V_152 ,
V_148 , & V_110 ) ;
if ( ! V_141 )
goto V_157;
}
if ( V_22 [ 0 ] ) {
V_158 . V_126 = V_22 ;
V_158 . V_113 = strlen ( V_22 ) ;
V_141 = F_60 ( L_40 , V_150 ,
V_148 , & V_158 ) ;
if ( ! V_141 )
goto V_157;
V_141 = F_58 ( L_41 , V_150 | V_152 ,
V_148 , & V_87 ) ;
if ( ! V_141 )
goto V_157;
}
F_61 ( L_42 ) ;
return 0 ;
V_157:
if ( V_85 ) {
T_5 V_113 = ( V_40 ) ?
sizeof( struct V_14 ) :
sizeof( struct V_42 ) ;
F_17 ( V_85 , V_113 ) ;
F_24 ( L_43 ) ;
}
F_34 ( & V_2 ) ;
V_156:
F_35 ( & V_73 ) ;
V_155:
F_31 ( & V_73 ) ;
V_149:
F_24 ( L_44 ) ;
F_62 ( V_148 ) ;
return V_6 ;
}
static void T_6 F_63 ( void )
{
struct V_1 V_2 ;
if ( V_85 ) {
T_5 V_113 = ( V_40 ) ?
sizeof( struct V_14 ) :
sizeof( struct V_42 ) ;
F_17 ( V_85 , V_113 ) ;
}
F_1 ( & V_2 ) ;
F_34 ( & V_2 ) ;
F_35 ( & V_73 ) ;
F_31 ( & V_73 ) ;
F_62 ( V_148 ) ;
}
